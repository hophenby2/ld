# Stage 04 Type `0x38` Exact-Port Notes

Status: exact audit of `FUN_140092b20 @ 0x140092b20` against the original
`LikeDreamer.exe`. Constants were read from the original PE with the read-only
Ghidra `ExportScalarValues.java` script. This document is intended to replace the
current sinusoidal placeholder without requiring another interpretation pass.

Implementation status: ported into `stage_runtime.cpp`, including constructor
overrides, helper/targetable timer ordering, both projectile families, multipart
frames `63..66`, type-1 HP gauge, reward window, strict bounds, and the shared
death-effect nodes. The reward helper keeps the entity x/y in `xmm1/xmm2`; its
frame-offset RNG controls item angle and speed rather than spawn position, and
that call contract is now represented directly.

Primary evidence:

- update/death/draw helper:
  `missing-helper-priority/neighborhood-decompiled/140092b20_FUN_140092b20.c`;
- original instructions: `0x140092b20..0x140093539` in `LikeDreamer.exe`;
- type constructor branch: `0x14007ba77..0x14007bfc3`;
- common constructor:
  `stage-update-helper-sample/neighborhood-decompiled/140078a00_stage_entity_spawn_candidate.c`;
- spread wrapper:
  `stage-update-helper-priority/neighborhood-decompiled/1400709b0_FUN_1400709b0.c`;
- dispatcher timer/collision ordering:
  `stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c:650-655`.

## Constructor

The raw stage call is `stage_spawn_dispatch_candidate(type, hp, x, y)`. For type
`0x38`, the dispatch branch discards the supplied `y` and calls the common entity
constructor with these values:

| Entity field / constructor argument | Exact value |
|---|---:|
| type `+0x18` | `0x38` |
| current/max HP `+0x1c/+0x20` | schedule `hp`; difficulty 0 applies the common `0.8` scale |
| reward/death weight `+0x24` | `24` (`0x18`) |
| x `+0x28` and saved x fields | `(float)x` from the schedule |
| y `+0x2c` and saved y fields | `-100.0f` (`DAT_14053b380`) |
| angles `+0x40/+0x42/+0x44` | `0x4000` |
| speed `+0x48` | `1.0` (`DAT_140539f40`) |
| collision radius `+0x50` | `90` (`0x5a`) |
| targetability state `+0x54` | `1`, meaning invulnerable/not targetable |
| owner `+0x08` | `0` |
| helper state/timers | state `0`, helper timer `0`, targetable timer `0` |

Evidence: original instructions `0x14007ba77..0x14007baa6` and common tail
`0x14007bfa1..0x14007bfc3`. Do not initialize this type with the reconstruction's
old `hp=80`, `radius=56`, `vy=0.2`, or `activationDelay=48` defaults.

## Frame ordering and state 0

The main entity dispatcher calls the helper first, performs player-shot collision
only when `+0x54 == 0`, increments helper timer `+0x0c`, then conditionally
increments targetable timer `+0x10`. All timer comparisons below therefore use the
pre-increment helper timer visible inside `FUN_140092b20`.

State 0 runs for helper timers `0..20`, inclusive:

1. Call `FUN_1401346a0({x,y}, -50)` and draw `Effect_m` frame 4
   (`DAT_140e41a50`) at the returned position.
2. Draw call parameters are `(0x32, layer 8, angle 0, scaleX=scaleY)` with
   `scale = 3.0 - timer * 0.15`, white RGBA, final flags `1,0`.
3. The clamp helper is exactly
   `x=clamp(x, playerX/6-50, playerX/6+650)` and
   `y=clamp(y,-50,770)`. Since the constructor y is `-100`, the marker is drawn at
   y `-50`; the actual entity remains at y `-100`.
4. At timer `20`, set state to `1`, speed to `7.0`, `+0x54=0` (targetable), and
   helper timer to `0`.

The state checks are two independent `if` blocks, not `if/else`. Consequently the
timer-20 transition call immediately continues through the state-1 update with
active timer `t=0`. It draws both the zero-scale marker and the active body, reduces
speed from `7.0` to `6.9`, moves once, and is targetable to the collision pass later
in that same entity update.

Evidence: decompile lines 46-69 and original instructions
`0x140092b6a..0x140092c34`.

## Active-state oscillators

For state 1, let `t = helperTimer` and compute these values before changing the
entity position:

```text
rearWave = float(2 * sin(t       * 2*pi/63)) - 8
bodyWave = float(2 * sin((t - 23) * 2*pi/63))
rot65    = trunc_to_int(sin(t        * 2*pi/50) * 1500)
rot66    = trunc_to_int(sin((t - 25) * 2*pi/50) * 1500)
```

The PE constants are `65536/63 == 1040.2539682539682`,
`65536/50 == 1310.72`, fixed-angle scale `pi/32768`, and amplitude `1500.0`.
The rotations use `cvttsd2si`, so conversion truncates toward zero before the
low 16 bits are passed to the draw helper.

Evidence: original instructions `0x140092c42..0x140092d8b`.

## Motion

At function entry, before any state work or movement, compute the 16-bit player
aim from the old position:

```text
motionTarget = angle16(atan2(playerY - oldY, playerX - oldX))
```

State 1 then performs the following operations in this exact order:

```text
if (t <= 120 && speed > 1.2)
    speed -= 0.1

motionAngle = approach_angle16(motionAngle, motionTarget, 0x80)

if (t >= 290)
    speed -= 0.1                 // no lower bound; it may become negative

x += cos16(motionAngle) * speed
y += sin16(motionAngle) * speed
```

`approach_angle16` uses the wrapped shortest signed difference. A target within
the step snaps exactly; otherwise it adds/subtracts the maximum step. The first
guard is inclusive at `120`, the exit deceleration is inclusive at `290`, and
there is no explicit active-state lifetime.

Evidence: decompile lines 84-125 and original instructions
`0x140092d86..0x140092e77`.

## Firing origin and active window

Firing is evaluated after movement. It only runs for active timers `24..289`
inclusive. Define:

```text
fireX   = postMoveX
fireY   = postMoveY + rearWave - 5
fireAim = angle16(atan2(playerY - fireY, playerX - fireX))
local   = (t - 24) % 120
```

Thus movement tracking and projectile tracking deliberately use two separately
sampled aims: the motion target is from the pre-movement entity position, while
`fireAim` is from the post-movement, vertically offset muzzle.

Difficulty tables for indices `0..4` are:

| Difficulty | first-family window | fixed count for family 2 | spread unit | base speed |
|---:|---:|---:|---:|---:|
| 0 | 16 | 3 | 320 | 6.0 |
| 1 | 24 | 5 | 320 | 7.0 |
| 2 | 28 | 7 | 350 | 7.5 |
| 3 | 32 | 7 | 450 | 10.0 |
| 4 | 36 | 9 | 600 | 11.0 |

At `local == 0` or `local == 40`, copy `fireAim` directly into stored projectile
angle `+0x42` before either family is evaluated.

### Family 1: expanding selector-9 fan

When `local < firstFamilyWindow` and `local % 4 == 0`, let `k=local/4` and call:

```text
FUN_1400709b0(
    visualSelector = 9,
    behavior       = 0,
    x = fireX, y = fireY,
    centerAngle    = storedAngle,
    initialTravel  = 10.0f,
    speed          = baseSpeed,
    radius         = 1,
    count          = k + 1,
    spreadAngle16  = k * spreadUnit,
    auxiliary      = 0)
```

The `count==1` case is a single constructor call. For larger counts, preserve the
spread wrapper's signed-16-bit step and centered-angle arithmetic.

### Family 2: selector-8 wide fans

When `40 <= local <= 69` and `(local-40) % 4 == 0`, define
`ramp=(local-40)*0.1` and call:

```text
FUN_1400709b0(8, 0, fireX, fireY, storedAngle,
              0.0f, baseSpeed + ramp + 1.0,
              1, fixedCount, 20000, 0)
```

On difficulties 3 and 4, immediately make a second otherwise-identical call at
speed `baseSpeed + ramp - 2.0`. This second speed is not the first call's speed
minus two; the difference between the two emitted fans is exactly `3.0`.

After both family checks, on every timer in `24..289`, approach stored angle
`+0x42` toward `fireAim` by at most `0x20`. This happens even on frames which emit
no projectile. On `local==0/40`, the preceding snap makes this final adjustment a
no-op.

Evidence: decompile lines 126-268 and original instructions
`0x140092e7d..0x1400931a4`.

## Multipart drawing and HP gauge

`Enemy_m.png` begins at `DAT_140e44ad0`, so the four handles used here are exact
frames 63 through 66. Draw after movement and projectile creation, in this order:

| Order | Frame / handle | Position | Angle | Mirror flag |
|---:|---|---|---:|---:|
| 1 | `Enemy_m` 66 / `DAT_140e44bd8` | `(x+30, y+bodyWave)` | `rot66` | 0 |
| 2 | `Enemy_m` 66 / `DAT_140e44bd8` | `(x-30, y+bodyWave)` | `-rot66` | 1 |
| 3 | `Enemy_m` 65 / `DAT_140e44bd4` | `(x+25, y+bodyWave+80)` | `rot65` | 0 |
| 4 | `Enemy_m` 65 / `DAT_140e44bd4` | `(x-25, y+bodyWave+80)` | `-rot65` | 1 |
| 5 | `Enemy_m` 64 / `DAT_140e44bd0` | `(x, y+bodyWave)` | 0 | 0 |
| 6 | `Enemy_m` 63 / `DAT_140e44bcc` | `(x, y+rearWave)` | 0 | 0 |

Every body call uses the remaining tuple `(0x20, layer 7, scaleX=scaleY=1.0,
RGBA=255, final enable flag=1)`. The left copies are mirrored through the final
draw argument; they are not separately authored frames.

After the six body calls, call the common enemy gauge helper as type 1 with x
offset `0` and y offset `-120`. In concrete terms its background is centered at
`(x,y-120)`, and its fill starts at `(x-60,y-125)`; the type-1 fill x scale is
`ratio*0.5`, where `ratio=currentHP/maxHP`. The background uses gauge frame 1,
scale `1,1`, white RGB, and alpha `192`. The fill uses alpha `192` and these
integer RGB values:

```text
ratio > 0.5:  (0, 255, trunc((ratio - 0.5) * 511))
otherwise:    (trunc(255 - ratio * 511), trunc(ratio * 511), 0)
```

The common gauge helper renders only while signed current HP is nonnegative; HP
zero therefore draws an empty gauge, while negative HP suppresses both gauge
draws. This does not suppress the six body-part draws which precede it.

Evidence: decompile lines 269-290; original instructions
`0x1400931a8..0x14009345b`; `Enemy_m` base handle comes from
`load_primary_resources_candidate @ 0x1400ced90`.

## Death and removal

Death is checked only after the complete active update, firing, multipart draw,
and gauge call. If signed current HP `+0x1c <= 0`, execute in order:

```text
FUN_14007b010(entity, 500, 8)
FUN_140079e20(entity, 1)
entity.active = 0
```

Because collision occurs after the helper in the outer dispatcher, a shot which
makes HP non-positive is processed by this death branch on the next entity update.
That final helper call can still move, emit, and draw before clearing the entity.

Independently of HP and state, clear the entity when any exact bound is violated:

```text
x < playerX/6 - 128
x > playerX/6 + 728
y < -128
y > 848
```

The comparisons are strict; equality remains active. Unlike some neighboring
Stage 04 helpers, type `0x38` does not gate culling on state or timer.

Evidence: decompile lines 292-301 and original instructions
`0x1400934b6..0x14009352f`.

## Decoded scalar constants

| PE address | Type | Value | Use |
|---|---|---:|---|
| `0x140539d28` | double | `1/32768` | fixed-angle radians factor with pi |
| `0x140539e60` | double | `0.1` | active speed decrement and family-2 ramp |
| `0x140539e98` | double | `0.15` | marker shrink per frame |
| `0x140539f00` | double | `0.5` | type-1 HP fill scale/color split |
| `0x140539f28` | double | `0.8` | common difficulty-0 HP scale |
| `0x140539f40` | double | `1.0` | constructor speed and draw scale |
| `0x140539f68` | double | `1.2` | guarded deceleration floor comparison |
| `0x140539fc8` | double | `2.0` | high-difficulty family-2 subtraction |
| `0x14053a018` | double | `3.0` | marker starting scale |
| `0x14053a020` | double | pi | trigonometric conversion |
| `0x14053a0f8` | double | `6.0` | difficulty-0 projectile base speed |
| `0x14053a138` | double | `7.0` | difficulty-1 projectile base speed |
| `0x14053a158` | double | `7.5` | difficulty-2 projectile base speed |
| `0x14053a1e8` | double | `10.0` | difficulty-3 projectile base speed |
| `0x14053a208` | double | `11.0` | difficulty-4 projectile base speed |
| `0x14053a298` | double | `23.0` | body-wave phase offset |
| `0x14053a2b0` | double | `25.0` | frame-66 rotation phase offset |
| `0x14053a340` | double | `40.0` | family-2 local start |
| `0x14053a5f8` | double | `255.0` | HP gauge red component basis |
| `0x14053a768` | double | `511.0` | HP gauge color ramp |
| `0x14053a908` | double | `1040.2539682539682` | `65536/63` oscillator factor |
| `0x14053a988` | double | `1310.72` | `65536/50` oscillator factor |
| `0x14053a9c0` | double | `1500.0` | part rotation amplitude |
| `0x14053aa20` | float | `5.0f` | firing-y offset |
| `0x14053ab70` | float | `6.0f` | horizontal culling divisor |
| `0x14053aba0` | double | `10430.378350470464` | radians-to-16-bit-angle factor |
| `0x14053ac18` | float | `8.0f` | rear-wave baseline |
| `0x14053ac2c` | float | `10.0f` | family-1 initial radial travel |
| `0x14053ac60` | float | `25.0f` | inner-part x offset |
| `0x14053ac80` | float | `30.0f` | outer-part x offset |
| `0x14053acfc` | float | `80.0f` | inner-part y offset |
| `0x14053ad4c` | float | `128.0f` | left culling margin |
| `0x14053af18` | float | `728.0f` | right culling extent |
| `0x14053af5c` | float | `848.0f` | bottom culling bound |
| `0x14053b360` | float | `-60.0f` | type-1 HP fill x offset |
| `0x14053b380` | float | `-100.0f` | constructor y |
| `0x14053b390` | float | `-120.0f` | HP gauge y offset |
| `0x14053b398` | float | `-128.0f` | top culling bound |
| `0x14053bb20/+8` | double pair | `1.0, 1.0` | body draw x/y scales |
