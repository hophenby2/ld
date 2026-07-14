# Stage 04 Type `0x3d` / `0x3e` Exact-Port Notes

Status: audited against the original `LikeDreamer.exe` instructions and the
checked-in Ghidra decompilations. The parent helper is `FUN_1400941d0`
(`0x1400941d0..0x140094bbc`); the child helper is `FUN_140094bc0`
(`0x140094bc0..0x140095128`). This document is implementation-ready and
supersedes the current three-anchor approximation.

## Constructor fields

The Stage 04 spawn dispatcher gives a scheduled type `0x3d` these values:

| Entity field | Type `0x3d` parent |
|---|---:|
| `+0x08` owner id | `0` |
| `+0x0c` helper timer | `0` |
| `+0x10` targetable timer | `0` |
| `+0x14` state | `0` |
| `+0x18` type | `0x3d` |
| `+0x1c/+0x20` current/max HP | schedule HP; Easy (`difficulty==0`) truncates `HP*0.8` |
| `+0x24` reward weight | `48` |
| `+0x28..+0x3c` current/origin/saved x,y | schedule x,y in all three pairs |
| `+0x40/+0x42/+0x44` angles | `0x4000` |
| `+0x48` speed | `1.0` |
| `+0x50` collision radius | `160` |
| `+0x54` targetability flag | `1` (invulnerable marker) |

Evidence: type `0x3d` dispatch target `0x14007bacf` and common tail
`0x14007bf99..0x14007bfbf`; constructor `FUN_140078a00`.

On the parent's first helper call (`state==0 && timer==0`), it directly appends
three type `0x3e` nodes in this exact order:

| Child | Local x | Local y |
|---:|---:|---:|
| 0 | `-148.0f` | `-80.0f` |
| 1 | `-95.0f` | `-105.0f` |
| 2 | `113.0f` | `-110.0f` |

Each direct constructor call is:

```text
spawnEntity(type=0x3e, hp=99999999, rewardWeight=1,
            x=localX, y=localY, angle=0xc000, speed=0.0,
            radius=40, targetability=1, ownerId=parent.entityId)
```

Thus all child current/origin/saved coordinate pairs initially contain the local
offset. Easy difficulty also scales child HP, yielding `79,999,999` after integer
truncation. This HP is not gameplay-relevant because `+0x54` remains `1` and the
child helper never performs its own HP death check.

The entity loop follows the live `next` link after each helper call. The three
new children are therefore updated later in the same entity traversal. Do not
freeze the entity count at traversal start.

## Parent state and motion

Define:

```text
viewportLeft = playerX / 6.0f
entryFromLeft = parent.originX < 360.0f
```

The clamp helper used below clamps a point to:

```text
x in [viewportLeft + margin, viewportLeft + 600 - margin]
y in [margin, 720 - margin]
```

State 0 is a 20-frame marker phase:

1. Every call draws the marker at `clamp(parent.position, -50)` with scale
   `4.0 - timer*0.2`.
2. At timer `0`, append the three children listed above, after queueing the
   marker draw.
3. At timer `20`, set speed to `2.5`, set the current angle `+0x40` to `2000`
   when `currentX <= 360`, otherwise to `0x7830` (`32768-2000`), clamp current
   position with margin `-200`, set state to `1`, targetability to `0`, and reset
   the helper timer to `0`.
4. The timer-20 call then falls through into state 1. It moves and draws the
   active body in the same call. Therefore that transition frame contains both
   a zero-scale marker draw and a body draw at active timer zero.

State 1 first integrates the fixed-angle motion every call:

```text
x += cos(angle16 * 2*pi/65536) * 2.5
y += sin(angle16 * 2*pi/65536) * 2.5
```

The angle is not subsequently steered. Numerically the left-entry velocity is
approximately `(2.45418, 0.47644)` and the right-entry x velocity is its
negative. The original `+0x30/+0x34` origin remains unchanged.

## Parent projectile pattern

After movement, define:

```text
fireX = x + 180  if entryFromLeft, else x - 180
fireY = y + 33
aim = uint16(trunc(atan2(playerY-fireY, playerX-fireX) * 65536/(2*pi)))
```

No parent bullet is emitted unless `fireX` is in
`[viewportLeft, viewportLeft+600]` and `fireY` is in `[0,720]`, inclusive.

Difficulty tables (index `0..4`):

| Difficulty | Half-cycle `H` | Base speed | Fan count | Fan spread |
|---:|---:|---:|---:|---:|
| 0 | 100 | 3.2 | 5 | 1440 |
| 1 | 80 | 3.6 | 7 | 2160 |
| 2 | 50 | 4.0 | 9 | 2880 |
| 3 | 60 | 5.0 | 9 | 2880 |
| 4 | 50 | 6.5 | 9 | 2880 |

`spread == (count-1)*360`, so the spread wrapper creates adjacent bullets with
an exact signed-16-bit angle step of `360`.

Volley A occurs when `timer>=32` and `(timer-32)%(2*H)==0`:

| Center angle | Speed | Difficulties |
|---:|---:|---:|
| `aim` | base | all |
| `aim + 7000` | base | all |
| `aim - 7000` | base | all |
| `aim + 3500` | base - 1.2 | 3, 4 only |
| `aim - 3500` | base - 1.2 | 3, 4 only |

Volley B occurs when `timer>=H+32` and `(timer-(H+32))%(2*H)==0`:

| Center angle | Speed | Difficulties |
|---:|---:|---:|
| `aim + 3500` | base | all |
| `aim - 3500` | base | all |
| `aim` | base - 1.2 | 3, 4 only |
| `aim + 7000` | base - 1.2 | 3, 4 only |
| `aim - 7000` | base - 1.2 | 3, 4 only |

Every table row is one exact spread call:

```text
FUN_1400709b0(visual=5, behavior=0, fireX, fireY, centerAngle,
              initialTravel=0.0f, speed, collisionRadius=1,
              count, spread, aux=0)
```

Thus A and B alternate every `H` active frames; they are not three independent
anchor emitters.

## Child owner relation and state

Every child call scans the entity list for `entityId == child.parentEntityId` and
copies an owner snapshot. The lookup is not an early-return gate and does not
require `owner.active != 0`.

Before state logic, the child does this ordering exactly:

1. Compute the desired player aim from the child's current x,y, which are still
   the coordinates left by the previous call.
2. Refresh position as `child.x=owner.x+child.originX` and
   `child.y=owner.y+child.originY`.
3. Run state logic and possible firing.

The desired aim therefore has a deliberate one-update positional lag.

In state 0:

- At timer `0`, negate `child.originX` when `owner.originX < 360`. This happens
  after the position refresh, so the first draw uses the unmirrored offset and
  the mirrored offset takes effect on the next call.
- At timer `20`, reset timer to `0`, set state to `1`, and fall through into the
  state-1 turn/fire code in the same call.
- Targetability is never changed; children remain invulnerable.

In state 1, approach the lagged desired angle using shortest 16-bit turn
distance. The maximum turn this frame is:

```text
turnStep = circularDistance(currentAngle, desiredAngle) / 10 + 48
```

Snap when the remaining signed difference is smaller than the step; otherwise
add or subtract the step. Store the result in current angle `+0x40`.

## Child projectile pattern

The three children are normally assigned consecutive IDs. The helper nevertheless
uses the exact formula, not an explicit child index:

```text
phase = 30 + 12 * (owner.entityId - child.entityId)
```

For the normal three children this is `18`, `6`, and `-6`, respectively.
Firing requires all of:

```text
timer >= phase
(timer - phase) % interval[difficulty] == 0
child.x in [viewportLeft-30, viewportLeft+630]
child.y in [-30, 750]
```

Difficulty tables:

| Difficulty | Interval | Base speed |
|---:|---:|---:|
| 0 | 95 | 4.6 |
| 1 | 60 | 5.5 |
| 2 | 45 | 6.0 |
| 3 | 38 | 5.5 |
| 4 | 27 | 7.0 |

The emission anchor is 55 units ahead of the refreshed child position along its
new current angle:

```text
emitX = child.x + cos(angle) * 55
emitY = child.y + sin(angle) * 55
```

Each firing event creates individual straight projectiles at the same angle:

```text
FUN_14006c2f0(visual=6, behavior=0, emitX, emitY, angle,
              initialTravel=10.0f, speed=base+0.0,
              collisionRadius=1, aux=0)
FUN_14006c2f0(... speed=base+0.4 ...)

// Difficulty 3 or 4 only:
FUN_14006c2f0(... speed=base+2.0 ...)
FUN_14006c2f0(... speed=base+2.4 ...)
```

## Exact drawing

The fixed 16-bit angle is the rotation passed to the draw queue. The two doubles
after it are x/y scale; this distinction is visible in the draw-list consumer
`FUN_1400c8530`.

Parent state-0 marker:

- `Effect_m.png` frame 4, handle `DAT_140e41a50`;
- layer `50`, draw mode `8`, fixed angle `0`;
- clamped position described above, scale x/y `4.0-timer*0.2`;
- white RGBA, enable flag `1`, mirror flag `0`.

Parent state-1 draw order:

1. Let `sideX = x-205` for a left entry, otherwise `x+205`; `sideY=y+12`;
   let `s=sin(timer*2*pi/19)`.
2. Draw `Enemy_m.png` frame 73 (`DAT_140e44bf4`) at `(sideX,sideY)`, fixed
   angle `0xc000`, scale `(s,1)`, mirror flag `1`.
3. Draw the same frame at the same position and angle, scale `(-s,1)`, mirror
   flag `1`.
4. Draw `Enemy_l.png` frame 17 (`DAT_140e44954`) at `(x,y)`, fixed angle `0`,
   scale `(1,1)`, mirror flag `entryFromLeft`.
5. Call the common HP gauge helper with gauge type `0`, x offset `0`, y offset
   `-150`.

All three body calls use layer `30`, mode `7`, white RGBA, and enable flag `1`.
The side animation is x scale, not a floating-point rotation.

Each child always queues one body draw before owner-loss cleanup:

- `Enemy_m.png` frame 72 (`DAT_140e44bf0`), layer `30`, mode `7`;
- position `(child.x,child.y)`, fixed angle `child.currentAngle`;
- scale `(1,1)`, white RGBA, enable flag `1`, mirror flag `0`.

## HP, death, bounds, and ordering

Parent HP is independent of child HP. There is no shared-HP propagation.

At the end of every parent helper call, after movement, firing, body drawing, and
gauge drawing:

```text
if (parent.hp < 1) {
    FUN_14007b010(parent, 500, 8);
    FUN_140079e20(parent, 1);
    parent.active = 0;
}
```

The parent is also cleared, without the above reward/death calls, when:

```text
x < viewportLeft-360 || x > viewportLeft+960 ||
y < -360 || y > 1080
```

These checks occur after drawing, so a terminal parent frame still draws and can
fire. There is no timer/lifetime deletion rule.

At the end of every child call, after its body draw:

```text
if (owner.hp < 1) {
    FUN_140079e20(child, 0);
    child.active = 0;
}
if (owner.active == 0) {
    child.active = 0;
}
```

A missing owner leaves the zero-initialized snapshot (`hp==0`, `active==0`), so
it takes the first path as well. There is no child bounds test and no child
reward call.

The dispatcher calls the type helper before collision, then increments helper
timer and, only when targetable, targetable timer. Consequently a lethal player
hit to the parent is normally rewarded by the parent on its next update. Because
the children occur later in the same list, they can observe the newly reduced
owner HP and execute their mode-0 death effect during the lethal-hit traversal.

## Mapping to current `StageEnemy`

The current structure can represent the behavior as follows:

| Original meaning | Current field |
|---|---|
| type, id, owner id | `spawnType`, `entityId`, `parentEntityId` |
| current/origin position | `x/y`, `originX/originY` |
| current fixed angle `+0x40` | `sourceAngle16` |
| saved angle `+0x42` | `secondaryAngle16` (unused by these helpers after construction) |
| speed `+0x48` | `sourceSpeed` and synchronized `speed` |
| state/timer | `helperState`, `helperTimer` |
| current/max HP | `hp`, `maxHp` |
| radius/reward | `radius`, `rewardWeight` |
| targetability/active | `targetable`, `active` |

No extra per-child index is required for firing; use the exact entity-ID phase
formula. Deferred drawing needs care on the parent's transition call: one timer
value cannot describe both the pre-reset marker (`20`) and post-reset body (`0`).
Queue the marker immediately or preserve both draw events/timers. Likewise,
preserve the child update's aim-before-position-refresh ordering rather than
calling a generic owner-follow helper first.

## Decoded constants and evidence

Important PE scalars used above:

| Address | Value |
|---:|---:|
| `0x140539ec8` | `0.2` |
| `0x140539f68` | `1.2` |
| `0x14053a390` | `55.0` |
| `0x14053ab70` | `6.0f` |
| `0x14053aba0` | `10430.37835047046` (`65536/(2*pi)`) |
| `0x14053ac2c` | `10.0f` |
| `0x14053ac34` | `12.0f` |
| `0x14053ac98` | `33.0f` |
| `0x14053ad9c` | `180.0f` |
| `0x14053adb8` | `205.0f` |
| `0x14053ae30` | `360.0f` |
| `0x14053aec0` | `600.0f` |
| `0x14053aed4` | `630.0f` |
| `0x14053af14` | `720.0f` |
| `0x14053af28` | `750.0f` |
| `0x14053afa0` | `960.0f` |
| `0x14053afcc` | `1080.0f` |
| `0x14053b044` | `-1.0f` |
| `0x14053b33c` | `-30.0f` |
| `0x14053b3ac` | `-150.0f` |
| `0x14053b400` | `-360.0f` |

Primary decompilation sources:

- `gameplay-spawn-helpers-renamed/neighborhood-decompiled/1400941d0_FUN_1400941d0.c`
- `stage-entity-list-refs/global-key-ref-decompiled/140094bc0_FUN_140094bc0.c`
- `gameplay-spawn-helpers-renamed/neighborhood-decompiled/140078a00_stage_entity_spawn_candidate.c`
- `stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c`
- `remaining-helper-priority/neighborhood-decompiled/140079c10_FUN_140079c10.c`

Original instruction ranges used to resolve decompiler packing artifacts:
`0x1400941d0..0x140094bbc`, `0x140094bc0..0x140095128`, and
`0x14007bacf..0x14007bfc4`.
