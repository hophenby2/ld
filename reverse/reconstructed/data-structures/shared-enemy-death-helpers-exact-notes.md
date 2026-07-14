# Shared enemy death helpers exact notes

This note records the exact common enemy-death paths centered on
`FUN_14007b010` and `FUN_140079e20`.  It separates reward allocation,
distance/progress feedback, the deferred type-`0x137` entity, and the visual
death burst.  They are separate original helpers even though the compact
runtime currently combines part of their work in
`StageRuntime::spawnEnemyDeathRewardBurst()`.

## Primary evidence

- `reverse/ghidra-or-ida/exports/missing-helper-priority/neighborhood-decompiled/14007b010_FUN_14007b010.c`
- `reverse/ghidra-or-ida/exports/missing-helper-priority/neighborhood-decompiled/140079e20_FUN_140079e20.c`
- `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/1400ca6d0_FUN_1400ca6d0.c`
- `reverse/ghidra-or-ida/exports/missing-helper-priority/neighborhood-decompiled/140070d00_FUN_140070d00.c`
- `FUN_14007c1a0`, `FUN_1400735a0`, and `FUN_140073a60`, exported read-only
  from the existing Ghidra project during this audit.
- `/tmp/enemy-death-helper-scalars.tsv`
- `/tmp/enemy-death-effect-scalars.tsv`
- `/tmp/enemy-death-137-scalars.tsv`
- `/tmp/enemy-death-137-extra-scalars.tsv`

Raw disassembly around `0x14007b010` and `0x140079e20` was also checked to
resolve register/stack arguments that Ghidra omitted from calls with mixed
integer, float, and double parameters.

## `FUN_14007b010`: reward payout

Inputs are the enemy node, a payout window, and a feedback strength.  The
enemy fields used here are:

| original offset | runtime field | use |
|---:|---|---|
| `+0x04` | `entityId` | deterministic child/helper seeds |
| `+0x10` | `targetableTimer` | time spent targetable |
| `+0x24` | `rewardWeight` | base payout |
| `+0x28/+0x2c` | `x/y` | reward and feedback origin |
| `+0x50` | `radius` | proximity, progress, and feedback size |

The integer payout starts at `1`.  It is replaced only when
`payoutWindow-targetableTimer > 0`:

```text
payout = trunc(((payoutWindow - targetableTimer) / payoutWindow) * rewardWeight)
```

Negative special gauge/Fever doubles the payout.  The tier decomposition is
intentionally nonstandard and must retain the original integer order:

```text
if payout > 49:
    type2Count = payout / 20
    payout -= type2Count * 10
if payout > 9:
    type1Count = payout / 10
    payout -= type1Count * 5
type0Count = payout
```

Each item is created at the enemy center.  `frame` below is the global stage
frame (`DAT_140e418c8`), and `i` is local to that tier, beginning at zero.
All speed calls use the existing hundredth-resolution RNG and range
`[0.00,16.00]` inclusive.

| item | count | angle seed | speed seed | radius/scale |
|---:|---|---|---|---:|
| `2` | `type2Count` | `frame + 666 + i` | `frame + 555 + i` | `60` |
| `1` | `type1Count` | `frame + 444 + i` | `frame + 333 + i` | `45` |
| `0` | `type0Count` | `frame + 222 + i` | `frame + 111 + i` | `30` |

The angle is `scriptRandomAngle(seed)`.  The current `RewardItem` structure
can represent all exact values: its angle is fixed-angle 16-bit, speed is a
float, and `radiusOrScale` is an integer.  The current deterministic
`1.8..3.2`, radius-`12` scatter is therefore a temporary substitution rather
than a storage limitation.

## Distance and progress feedback

The helper computes:

```text
proximity = trunc(distance(player, enemy)) - enemy.radius
```

The visible feedback multiplier is:

```text
proximity <= 150  -> 10
151..449          -> max(1, (450 - proximity) / 30)
proximity >= 450  -> 1
Fever             -> 10, overriding distance
```

It allocates effect type `0x1d` with multiplier as its first scale, size
`radius+60`, lifetime `feedbackStrength*3`, white RGB, and alpha `0xc0`.
That effect routes through `FUN_140073e60`; the compact `StageEffect` renderer
does not yet support this graph-less feedback family.

The same proximity value adds exact stock/progress state:

```text
progressScale = proximity <= 500 ? 1.0 + (500.0 - proximity) / 200.0 : 1.0
stockProgress += trunc((radius + 100) * progressScale)
```

When Fever is active, the original also creates player-side object type
`0x1a`.  This is distinct from the reward items and death particles.

## Type `0x137` post-death entity

`FUN_14007b010` always calls the stage-entity allocator with:

```text
type              = 0x137
hp                = 99999999
reward kind       = 0
x/y               = defeated enemy x/y
angle             = 0
speed/lifetime    = enemy.radius * 0.6
radius            = enemy.radius
inverse targetable= 1
helper state      = 0
```

This is a stage entity dispatched to `FUN_14007c1a0`, not a `StageEffect`.
Putting it in the effect vector would lose its counter-mode projectile/reward
behavior.  Its basic lifetime is `trunc(radius*0.6)`, halved on difficulty
zero.  It deactivates at that helper timer or immediately when the relevant
counter-mode global is disabled.  With counter mode enabled and nonzero run
score it periodically samples points inside the defeated enemy radius and can
emit the original counter projectile/reward feedback.  Runtime routing for
`0x137` must be added separately after the active Boss edits settle.

### Exact `FUN_14007c1a0` counter branch

The branch runs only when the counter-mode global equals `1` and run score is
nonzero.  The emission interval by difficulty is:

| difficulty | `0` | `1` | `2` | `3` | `4` |
|---:|---:|---:|---:|---:|---:|
| interval | `5` | `4` | `3` | `2` | `2` |

The helper timer must be nonnegative and divisible by that interval.  The
defeated enemy center must also have `y < 600`.  Let `t` be the helper timer
and `id` the type-`0x137` entity ID.  One candidate point is sampled as:

```text
radialAngle = scriptRandomAngle(t * 666 + id)
radialLength = scriptRandomInt(t * 6666 + id, 0, radius)
point = center + unit(radialAngle) * radialLength
```

The projectile heading is the fixed-angle aim from that point to the player,
plus deterministic jitter in `[-1000,1000]` from seed `t*3333+id`.

The point converts to a reward only when its player distance is below a second
deterministic threshold:

```text
threshold = scriptRandomInt(t * 777 + id, 180, 480)
reward = distance(point, player) < threshold
```

The separate `distance <= 480` check in the function is redundant once this
strict comparison is applied, but should be preserved if porting instruction
order literally.  A reward candidate creates:

- reward item type `0`, at `point`, angle from seed `t*7777+id`, speed
  `[0.00,16.00]` from the same seed, and radius/scale `30`;
- graph-less effect type `0x1a`, group `0x49`, angle equal to another random
  angle from seed `t*77777+id` plus the aimed/jittered heading plus `0x4000`,
  scales `1.0/1.0/0.5`, lifetime `50`, white RGB, alpha `192`;
- effect type `0x0c`, `Effect_m[4]`, group `0x3d`, at `point`, scale
  `0.6`, lifetime `16`, white/opaque.

Otherwise it creates an enemy projectile with:

```text
visual selector = 0x0f
behavior/id      = 0x16
position         = point
angle            = aimed heading plus jitter
initial travel   = 0
radius           = 1
aux              = 0
```

Its speed uses seed `t*7777+id`, with this inclusive hundredth-resolution
range:

```text
minimum = {3.5, 4.0, 4.5, 5.5, 6.5}[difficulty] + selectedStage * 0.1
maximum = minimum + 2.0
```

The current projectile allocator can express this pair.  The graph-less
type-`0x1a` effect remains a separate effect-family gap, while the accompanying
type-`0x0c` node can use the same pending updater required by the normal death
ring.

## `FUN_140079e20`: modes 0 and 1

The number of paired particle nodes is:

```text
count = scriptRandomInt(entityId * 111 + frame, radius / 4, radius / 3)
```

Radii are positive for the supported enemies, so these are ordinary truncating
integer divisions.  Mode `0` plays `EnemyDown1.wav` at
`soundEffectVolume*19`; mode `1` plays `EnemyDown2.wav` at
`soundEffectVolume*22`.

For pair index `i`, define:

```text
burstSeed = entityId * 666 + frame + i
distance  = scriptRandomInt(burstSeed, 0, radius + 60)
offset    = unit(scriptRandomAngle(burstSeed)) * distance
burstScale= scriptRandomHundredth(
                burstSeed, radius / 200.0 + 0.4, radius / 200.0 + 0.7)
```

The first node is:

```text
type       = 0x2a
graph      = Effect_m[5] (DAT_140e41a54)
group      = 0x3e
position   = enemy center + offset
angle      = scriptRandomAngle(burstSeed)
speed      = 1.0
scale x/y  = burstScale
lifetime   = 24
RGBA       = 255,255,255,255
```

The second node stays at the enemy center.  Its exact mode-dependent values
are:

| field | mode `0` | mode `1` |
|---|---|---|
| graph | `Player[14]` (`DAT_140e44ea8`) | same |
| type/group | `0x2c` / `0x3e` | same |
| angle seed | `frame + 11*i` | `frame + 22*i` |
| scale seed | `entityId*666 + frame + 1111*i` | `entityId*666 + frame + 2222*i` |
| scale range | `[0.70,1.00]` | `[0.90,1.50]` |
| speed seed | `frame + 555*i` | `frame + 222*i` |
| speed range | `[6.00,9.00]` | `[10.00,15.00]` |
| lifetime arg | `0` | `0` |
| RGBA | `255,255,255,192` | same |

Both x/y scale calls use the same seed, so they return the same value.  The
existing type-`0x2a` and type-`0x2c` `StageEffect` fields can carry these
values.  Their update implementations already have the required entrance,
fade, randomized lifetime, pulse, deceleration, and rotation fields.  For
`0x2c`, the original stable random key is `initialAngle + creationFrame`; the
runtime's stored `randomSeed = angle16 + frame` matches that relationship.

Outside Fever (`specialGauge >= 0`) both modes append the common ring:

```text
type       = 0x0c
graph      = Effect_m[4] (DAT_140e41a50)
group      = 0x3d
position   = enemy center
angle      = 0
speed      = 0
scale x/y  = radius / 16.0
lifetime   = 24
RGBA       = 255,255,255,96
```

The existing `StageEffect` structure can carry this node, but
`updateStageEffects()` still needs the `FUN_140072560` type-`0x0c` scale/fade
case.

## Immediate runtime patch surface

Once concurrent Boss edits are stable, the low-conflict implementation is:

1. Replace only the exact-payout branch of
   `spawnEnemyDeathRewardBurst()` with the tier RNG/radii above; retain the
   no-window fallback until every caller has an evidence-backed window.
2. Add distance progress and total/close defeat counters there.
3. Add a separate mode-`0/1` death-particle helper and load the two
   `EnemyDown` handles through the existing resource IDs.
4. Add the type-`0x0c` `StageEffect` update case.
5. Add type-`0x137` spawn/update routing separately; do not approximate it as
   a visual effect and do not let it enter generic enemy movement/emission.
6. Keep mode `2` deferred at its original delayed-death call sites; invoking
   it immediately from the reward helper would be a timing regression.
