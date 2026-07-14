# Shared Enemy Type `0x0d` Exact-Port Notes

Status: the constructor surface, entry state, anchored movement, paired
projectile pattern, multipart draw, gauge placement, death reward window, and
strict bounds from `FUN_14007ea30` are ported to `StageRuntime`. Type `0x0d` is
dispatched globally by spawn type, so the recovered helper is used in every
stage rather than only in the Stage 1 schedule.

Primary evidence:

- `reverse/ghidra-or-ida/exports/stage01-helper-decompiled/14007ea30_FUN_14007ea30.c`;
- original instructions `0x14007ea30..0x14007f279` in `LikeDreamer.exe`;
- spawn case 5 at `0x14007bb1f` and the raw jump-table map in
  `stage-spawn-dispatch-map.md`;
- global entity dispatcher call at `0x140078c05..0x140078c0d` and its
  collision/timer tail at `0x14007968e..0x1400796a6`;
- projectile constructor `FUN_14006c2f0` and common movement helper
  `FUN_14006c620`.

## Constructor

Spawn dispatch case 5 passes the scheduled HP and x/y through the common
constructor with these type-specific values:

| Field | Value |
|---|---:|
| update type | `0x0d` |
| reward weight | `5` |
| collision radius | `30` |
| current/saved angles | `0x4000` |
| speed | `1.0` |
| targetability flag | `1` (invulnerable) |
| owner | `0` |

The common Easy-difficulty `HP * 0.8` truncation still applies. The previous
runtime approximation used radius `24`, speed `1.45`, and Stage 1-only routing.

## State 0 Entry

For helper timers `0..20`, the entity remains at its scheduled x/y and queues
`Effect_m` frame 4 with angle zero and scale:

```text
scale = 2.0 - timer * 0.1
markerX = clamp(x, playerX / 6 - 20, playerX / 6 + 620)
markerY = clamp(y, -20, 740)
```

At timer `20`, speed becomes `3.0` when the global stage index is below 4 and
`4.0` otherwise. The angle becomes `0xf2fb` when `x <= 360`, or `0x8d05` when
`x >= 720`; an x between those tests retains constructor angle `0x4000`. The
helper enters state 1, resets its timer to zero, becomes targetable, and falls
through to active movement, firing, body draw, and gauge draw on the same call.

The helper caches angle `+0x40` before the state transition. Consequently, the
transition call moves with the new angle but still uses old angle `0x4000` for
its muzzle side, wing layout, and body mirror flag. `StageRuntime` preserves
this one-frame distinction in `secondaryAngle16`.

## State 1 Movement

The helper keeps an undisplaced anchor in raw fields `+0x30/+0x34`, while
`+0x28/+0x2c` hold the visible and collidable point:

```text
timer = helperTimer
phase = timer % 33
anchorX += cos(angle * pi / 32768) * speed
anchorY += sin(angle * pi / 32768) * speed
x = anchorX
y = anchorY - 10 * sin(phase * pi / 33)
```

Body scale is `1 + 0.1*sin(timer*2*pi/33)`. The wing flap is the signed
truncation of `sin(phase*pi/33)*6666`.

## Projectile Pattern

Firing is evaluated after movement and is based on the global gameplay frame,
not the entity timer. Difficulty tables are:

| Difficulty | Interval, stage `<4` | Speed, stage `<4` | Interval, stage `>=4` | Speed, stage `>=4` |
|---:|---:|---:|---:|---:|
| 0 | `60` | `3.0` | `44` | `4.0` |
| 1 | `44` | `4.0` | `31` | `4.5` |
| 2 | `24` | `4.5` | `17` | `5.0` |
| 3 | `15` | `5.5` | `12` | `6.0` |
| 4 | `7` | `7.5` | `7` | `7.5` |

The cached entry angle selects the muzzle:

```text
angle < 0xc000: fire = (x - 40, y - 12)
otherwise:        fire = (x + 40, y - 12)
```

Emission is allowed only when the fire point is inside inclusive rectangle
`[playerX/6+40, playerX/6+560] x [40,680]` and its distance from the player is
at least `50`. Aim is taken from `(x,y+25)`, not from the muzzle, then snapped
to one of 32 directions:

```text
raw = trunc(atan2(playerY-(y+25), playerX-x) * 10430.378350470464)
angle = (((raw & 0xffff) + 0x400) >> 11) * 0x800
```

Each event creates two visual-selector `0`, movement-ID `0` projectiles with
the same angle, speed, and collision radius `1`. Their initial accumulated
travel values are `0` and `10`. `FUN_14006c620` adds speed before deriving the
first visible point, so the second projectile begins ten pixels farther along
the same ray; it is not a permanent `speed+10` projectile.

## Drawing

After the transition the original queues these `Enemy_s` nodes in order:

1. Frame 10 at `(x+6,y-6)`, angle `0x4000-flap`, when cached angle is below
   `0xc000`; otherwise at `(x-6,y-6)`, angle `0x4000+flap`.
2. Frame 10 at `(x-6,y-12)`, angle `0x4bb8+flap`, for the first orientation;
   otherwise at `(x+6,y-12)`, angle `0x3448-flap`.
3. Frame 9 at `(x,y)`, angle zero, horizontally reversed only when cached
   angle is below `0xc000`.

All three use the body scale above. Gauge mode 2 is queued at x offset `0` and
y offset `-50`; instructions `0x14007f1ca..0x14007f1e3` explicitly load
`DAT_14053b358 == -50.0`, zero `xmm3`, and call `FUN_140079c10(entity,2)`.
The runtime snapshots HP and helper timer when the helper queues the draw, so
later collision processing cannot change the same frame's body or gauge.

## Death, Bounds, and Dispatcher Tail

After movement, firing, body, and gauge are queued, HP below one calls the
reward helper with window `0x1e0` and the constructor's reward weight `5`, then
clears the live flag. The final inclusive lifetime rectangle is:

```text
x in [playerX / 6 - 180, playerX / 6 + 780]
y in [-180, 900]
```

The global dispatcher still performs player-shot collision after the helper,
even when the helper has just cleared the live flag. It then increments the
helper timer unconditionally and increments the payout timer only for a
targetable entity. The reconstruction retains that terminal frame for draw and
collision, then unlinks the inactive entity at the next update.

## Deferred Surface

- `FUN_140079e20(entity,0)` transient death visuals are not represented here.
- The reconstruction draws the recovered components directly rather than
  reproducing the executable's global mode-7 render-node list and layer `0x23`.
