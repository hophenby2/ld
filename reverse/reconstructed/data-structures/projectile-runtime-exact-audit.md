# Projectile Runtime Exact Audit

Status: exactness audit against the current Ghidra exports and PE constants. This
document corrects several first-pass interpretations in
`projectile-helper-notes.md`, `projectile-update-helper-semantics.md`, and the
projectile pair CSV files. Addresses and source line references below refer to
the checked-in decompiler exports.

Evidence source directories:

- constructor/spread: `reverse/ghidra-or-ida/exports/missing-helper-priority/neighborhood-decompiled/`
- motion/draw helpers: `reverse/ghidra-or-ida/exports/projectile-draw-helper/neighborhood-decompiled/`
- dispatcher/collision: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/`

## Implementation priority

### P0: fix the data model and frame lifecycle first

1. `FUN_14006c2f0` takes **visual selector first, behavior/update ID second**.
   Existing notes and generated pair tables label these two arguments in the
   opposite order.
2. Common/scripted/reflecting projectiles do not continuously integrate stored
   `x/y`. They retain an anchor at `+0x10/+0x14`, accumulate travel at `+0x20`,
   and derive the visible/collision point as `anchor + unit(angle) * travel`.
3. The dispatcher calls an update helper with the current age, then increments
   age. A newly constructed projectile therefore runs first with `age == 0`.
4. Projectiles appended while the linked list is being walked are reached later
   in the **same** traversal/frame. A vector implementation must also avoid
   invalidating the parent reference when a helper appends a child.
5. Original update helpers draw before inactive nodes are unlinked. A projectile
   killed on an exact terminal age or boundary still has that frame's draw call.

### P1: replace the remaining approximate helper implementations

1. Port all exact `FUN_14006c620` cases and their inclusive age bounds.
2. Replace the bounce approximation with the one-shot transform in
   `FUN_14006faa0`: the child becomes behavior `0`, not behavior `8`.
3. Port the implemented subset of `FUN_14006ce40` using the exact timing below.
4. Port `FUN_14006fcd0` and `FUN_14006ffc0`; both are materially different from
   the current linear approximations.
5. Use the age-dependent scale/rotation rules in `FUN_140070250` instead of
   fixed selector scales.

## Constructor and node layout

### Correct constructor signature

`FUN_14006c2f0 @ 0x14006c2f0` is:

```cpp
spawnProjectile(
    int visualSelector,       // arg1 -> +0x08
    int behaviorId,           // arg2 -> +0x0c, dispatcher key
    float anchorX,            // arg3 -> +0x10 and +0x18
    float anchorY,            // arg4 -> +0x14 and +0x1c
    uint16_t angle,           // arg5 -> +0x24 and +0x26
    float initialTravel,      // arg6 -> +0x20
    double speed,             // arg7 -> +0x28 and +0x30
    int collisionRadius,      // arg8 -> +0x38
    int aux);                 // arg9 -> +0x44
```

Evidence:

- Constructor stores arg1 at `+0x08` and arg2 at `+0x0c`:
  `14006c2f0_FUN_14006c2f0.c:31-36`.
- The main loop switches on `node[3]`, offset `+0x0c`:
  `1400bca30_state_14_replay_demo_gameplay_update_candidate.c:756-792`.
- Every update helper sends `node[2]`, offset `+0x08`, to the visual bridge;
  common helper example: `14006c620_FUN_14006c620.c:269-270`.
- A decisive child call is `FUN_14006c2f0(4, 0xf, ...)` in the common helper:
  selector `4`, timed behavior `0x0f`, not behavior `4` with selector `0x0f`:
  `14006c620_FUN_14006c620.c:214-220`.

The allocated node is `0x50` bytes, with `next` at `+0x48`. Exact fields:

| Offset | Type | Exact use |
|---:|---|---|
| `+0x00` | `int` | active |
| `+0x04` | `int` | age |
| `+0x08` | `int` | visual selector |
| `+0x0c` | `int` | behavior/update ID |
| `+0x10/+0x14` | `float,float` | anchor or integrated position, helper-dependent |
| `+0x18/+0x1c` | `float,float` | auxiliary/original anchor |
| `+0x20` | `float` | accumulated travel/radius for radial helpers |
| `+0x24/+0x26` | `uint16_t,uint16_t` | current and secondary angle |
| `+0x28` | `double` | current speed |
| `+0x30` | `double` | constructor speed copy/baseline |
| `+0x38` | `int` | collision radius |
| `+0x3c` | `int` | graze/hit processed |
| `+0x40` | `int` | collision enabled |
| `+0x44` | `int` | auxiliary/owner value |
| `+0x48` | pointer | next |

Constructor evidence is `14006c2f0_FUN_14006c2f0.c:13-49`. The single 64-bit
store at line 30 initializes `{active=1, age=0}`. Creation is capped at `0x800`
and suppressed while `DAT_140e445fc` is in inclusive range `0x79..0x103`:
the unsigned gate is `(state - 0x79U) > 0x8a` (`:14`).

### Generated tables that need reinterpretation

The first two columns in these artifacts are reversed semantically:

- `projectile-visual-pair-calls.csv`
- `projectile-visual-pair-coverage.csv`
- `projectile-visual-pair-coverage.md`
- `projectile-pattern-parameter-table.csv`
- the constructor signature/table in `projectile-helper-notes.md:43-78`

For example, raw call `(7, 0, ...)` means visual selector `7`, common behavior
`0`; it does not mean behavior `7`, visual selector `0`.

### Spread wrapper edge cases

`FUN_1400709b0 @ 0x1400709b0` delegates to the constructor only when
`count == 1`; `count == 0` emits nothing. It must not use a `count <= 1`
shortcut. For a full ring (`spread == 0x10000`), each angle is formed with the
16-bit step `(short)(0x10000/count)`. Otherwise the step is zero when
`spread <= 0`, or `(short)(spread/(count-1))` when positive, and the centered
fan angle is evaluated with 16-bit intermediate arithmetic. Evidence:
`1400709b0_FUN_1400709b0.c:12-41`.

## Frame lifecycle and same-frame children

The main projectile loop calls the behavior helper and only then increments
`+0x04`: `1400bca30...c:756-853`. The constructor initializes age zero, so exact
age comparisons below use the value visible inside the helper, without a
pre-increment.

Same-frame child processing follows from the list walk:

- Loop increment follows `current->next` at `1400bca30...c:756-757`.
- Constructor appends by writing the old tail's `+0x48` link at
  `14006c2f0...c:41-46`.
- Therefore, any child appended by a helper is eventually reached by the same
  loop, including when the current node was the old tail.

Do not freeze the container size at frame start. With `std::vector`, a child
`push_back` may reallocate and invalidate the live parent reference before the
helper finishes. Use stable storage, reserve the full `0x800` capacity, or
reacquire by index after every append.

### Dispatcher-only behaviors and unknown IDs

Not every behavior falls through to common motion:

- `0x13` and `0x15`: at age zero set `+0x3c=1` and `+0x40=0` (already
  processed, collision disabled); at age one set inactive.
- `0x14`: set the same flags at age zero and set inactive at age three.
- Any behavior ID absent from the dispatch table is set inactive immediately.

These cases do not call `FUN_14006c620`. Evidence:
`1400bca30_state_14_replay_demo_gameplay_update_candidate.c:794-852`.
An implementation whose switch `default` means common straight motion will
incorrectly animate/collide these short control nodes and preserve unknown IDs.

### Whole-list clear/flush

`FUN_14006c420 @ 0x14006c420` does more than clear storage. For every node it
reconstructs the current radial draw point from anchor/travel/angle, creates a
white effect node there (`effectType=0x0c`, frame/lifetime `0x3d`, scale
`0.6`, alpha `0xff`), then frees the projectile and finally zeros head, tail,
and count. Evidence: `14006c420_FUN_14006c420.c:19-70`. Player death/bomb/reset
paths that call this helper should not be represented as a silent vector clear
when visual parity is desired.

## Common radial helper: `FUN_14006c620`

### Shared step and ordering

At helper entry, before the behavior switch:

```cpp
const double oldSpeed = node.speed;
node.travel = float(oldSpeed) + node.travel;
const Vec2 draw = node.anchor + unit(node.angle) * node.travel;
// Behavior switch now computes speed/anchor/angle for the next frame.
```

Evidence: `14006c620...c:33-49`. The helper normally does not write `draw` back
to the anchor. Collision code independently reconstructs the same point from
`+0x10/+0x14`, `+0x20`, and `+0x24` at `1400cd750...c:63-77` and `:286-300`.

### Exact behavior table

All ranges are inclusive unless written with `<`/`>`.

| Behavior | Age inside helper | Exact post-switch speed/state |
|---:|---|---|
| `0x00`, `0x16` | all | No special mutation; shared radial step only. |
| `0x01` | all | `speed += {0.06,0.07,0.08,0.10,0.10}[difficulty]`. |
| `0x02` | `0` | `speed = 0.1 + base/30`. |
| | `1..30` | `speed += base/30`. |
| | `>30` | Unchanged. |
| `0x03` | `0` | `speed = 0.1`. |
| | `30..90` | `speed += base/60`. |
| | otherwise | Unchanged. Draw layer is always `0x4f`. |
| `0x04` | `0` | `speed = 0.1`. |
| | `12..72` | `speed += base/60`. |
| | otherwise | Unchanged. Draw layer is always `0x4f`. |
| `0x05` | `0` | `speed = base * 0.5`. |
| | `60..120` | `speed += base/120`. |
| | otherwise | Unchanged. Draw layer is always `0x4f`. |
| `0x06` | `0` | First overwrite `base = oldSpeed/5`; then, if `base < oldSpeed`, `speed = oldSpeed - base/6`. |
| | `1..30` | If `base < oldSpeed`, subtract `base/6`. |
| | `>30` | Unchanged. |
| `0x07` | `0..39` | `speed -= base/40`, with no clamp. |
| | `40..99` | `speed += base/60`. |
| | `>=100` | Unchanged. |
| `0x09` | `0..29` | `speed -= base/30`. |
| | `30` | Commit `anchor=draw`, aim at player from `draw`, set `travel=0`, then add retarget acceleration. |
| | `>=31` | `speed += {0.13,0.15,0.175,0.20,0.20}[difficulty]`. |
| `0x0a` | `0..39` | `speed = base*1.8 - (base*1.8/40)*age`. |
| | `40` | Commit `anchor=draw`; aim using auxiliary `+0x18/+0x1c`; set `travel=0`; `speed=base/60`. |
| | `41..99` | `speed += base/60`. |
| | `>=100` | Unchanged. |
| `0x0b` | `0..49` | `speed -= base/50`. |
| | `50` | Commit `anchor=draw`; aim at `(playerX,playerY)` from `(auxX,auxY-200)`; set `travel=0`; `speed=0.07`. |
| | `>=51` | `speed += 0.07`. |
| `0x0d` | `0..23` | Speed unchanged. |
| | `>=24` | `speed += {0.15,0.17,0.18,0.20,0.20}[difficulty]`. |
| `0x0f` | exactly `20` | Set inactive. |
| `0x10` | exactly `40` | Set inactive. |
| `0x11` | exactly `10` | Set inactive. |
| `0x12` | exactly `60` | Spawn the white effect node and set inactive. |

Primary evidence is `14006c620...c:51-268`. Relevant decoded PE constants:

| Symbol | Value |
|---|---:|
| `DAT_140539e30/e40/e50/e60` | `0.06 / 0.07 / 0.08 / 0.10` |
| `DAT_140539e88/e98/eb0/ec8` | `0.13 / 0.15 / 0.175 / 0.20` |
| `DAT_140539ea8/eb8` | `0.17 / 0.18` |
| `DAT_140539f00/fb8` | `0.5 / 1.8` |
| `DAT_14053a0b0/0f8` | `5 / 6` |
| `DAT_14053a2d8/340/380/3a0/4a0` | `30 / 40 / 50 / 60 / 120` |

Behavior `0x0d` emits a child on **every frame** while the derived draw point is
inside the common expanded rectangle, not every tenth frame. Exact child:

```cpp
spawnProjectile(4, 0x0f, draw.x, draw.y, angle, 0.0f, 0.0,
                parent.radius, 0);
```

Evidence: `14006c620...c:204-220`. The child is selector `4`, timed behavior
`0x0f`, and is stationary until its exact age-20 expiry.

### Common cleanup rectangle

After drawing, common/helper-scripted nodes are killed when the derived point is
outside:

```text
x: [playerX / 6 - 30, playerX / 6 + 630]
y: [-30, 750]
```

Evidence: `14006c620...c:269-275`; constants are
`DAT_14053ab70=6`, `DAT_14053ac80=30`, `DAT_14053aed4=630`,
`DAT_14053b33c=-30`, and `DAT_14053af28=750`. This is not equivalent to a
fixed 80-pixel margin around a `0..600 x 0..720` local rectangle.

## One-shot reflection: `FUN_14006faa0`, behavior `0x08`

The helper uses the same radial pre-step as common motion:
`travel += speed`, then `draw = anchor + unit(angle)*travel`
(`14006faa0...c:28-38`). It transforms when `draw` is outside:

```text
x: [playerX / 6 - radius, playerX / 6 + 600 + radius]
y: [-radius, 720 + radius]
```

There is no velocity-direction test. Exact heading selection is ordered as:

```cpp
newAngle = angle;
if (draw.x < playerX / 6 || draw.x > playerX / 6 + 600)
    newAngle = uint16_t(0x8000 - angle);
if (draw.y < 0)
    newAngle = uint16_t(-angle);       // top overrides horizontal reflection
// draw.y > 720 does not alter the angle; it only triggers transformation.
```

Evidence: `14006faa0...c:39-52`. The original node is then killed and the exact
replacement is:

```cpp
spawnProjectile(parent.visualSelector, 0,
                draw.x, draw.y, newAngle,
                0.0f, parent.speed, parent.radius, 0);
```

The replacement is ordinary behavior `0`, so this is a single reflection/
transform, not a perpetually bouncing behavior-`8` node. Ghidra loses the
second argument at `14006faa0...c:53-60`, but disassembly is unambiguous:
`0x14006fbd6` zeroes `EDX`, and nothing changes it before the constructor call
at `0x14006fc30`. The constructor stack arguments are travel `0`, current
speed, same radius, and aux `0` (`0x14006fbe6..0x14006fc35`).

The old node is drawn once on that transform frame and then subjected to the
common outer cleanup rectangle (`14006faa0...c:63-69`).

Behavior `0x31` in `FUN_14006ce40` uses the same boundary/angle transform but
forces visual selector `10`, behavior `0`, travel `0`, current speed, same
radius, aux `0`. Disassembly evidence is
`0x14006e159..0x14006e1c0`; this resolves the truncated decompile call at
`14006ce40...c:658-687`.

## Scripted radial helper: exact currently implemented cases

`FUN_14006ce40` starts with the same radial pre-step as common motion
(`14006ce40...c:71-83`). The current runtime's continuous `x += velocity`
approximation must be replaced with anchor/travel derivation.

### Behavior `0x17`

- At exact age `25`, emit one child.
- Child is visual `3`, behavior `1`, aimed at the player, travel `0`, speed
  `2.0`, and inherits the collision radius.
- Parent is **not** killed by this case.

Evidence: `14006ce40...c:108-114`.

### Behaviors `0x18` and `0x19`

Let `window = {12,16,20,20,20}[difficulty]`.

- Emit on even ages satisfying `16 <= age < 16 + window`.
- `0x18` emits a single child `(visual=0x0c, behavior=1)` at
  `parentAngle - age*200 - 0x36a0`.
- `0x19` emits a single child `(visual=0x0d, behavior=1)` at
  `parentAngle + age*200 + 0x36a0`.
- Child travel is `0`, speed is `1.5`, and radius is inherited.
- At exact age `16 + window`, spawn the white terminal effect and kill parent.
- Draw layer is `0x51` throughout.

Thus emission ages are `16..26`, `16..30`, or `16..34` by difficulty group.
Evidence: `14006ce40...c:115-190`.

### Behaviors `0x1a` and `0x1b`

Let:

```text
interval = {10, 8, 6, 5, 5}[difficulty]
speed    = {5.0, 6.0, 6.5, 6.0, 7.0}[difficulty]
```

At every `age % interval == 0`, including age zero, emit only if the derived
point is inside `[playerX/6, playerX/6+600] x [0,720]`:

- `0x1a`: child visual `8`, behavior `2`, angle
  `parentAngle + (120-age)*250`.
- `0x1b`: child visual `9`, behavior `2`, angle
  `parentAngle + age*250 - 30000`.
- Difficulty `3` or `4` emits a second child at `speed + 1.5`.
- Draw layer is `0x51`; parent is not killed here.

Evidence: `14006ce40...c:191-268`.

### Behavior `0x1c`

Let:

```text
difficulty  period  window  child speed
0           18      6       3.2
1           18      7       4.0
2           15      8       4.5
3           16      10      4.5
4           14      10      5.5
q = truncTowardZero((age + globalFrame) / 2)
```

When `q >= 0`, `q % period < window`, and the derived draw point is inside the
closed playfield, emit two children without killing the parent:

```text
visual=9, behavior=2, travel=0, radius=parent.radius, aux=0
angles=parentAngle-0x4000, parentAngle+0x4000
```

The draw call uses layer `0x51` and final trail/effect flag `1`; this branch
does not take the projectile-emission SFX path. Evidence: table and condition
`0x14006d3f1..0x14006d51f`, constructor arguments
`0x14006d525..0x14006d584`, and flag write `0x14006d586`.

### Behaviors `0x1d` and `0x1e`

Both behaviors first replace the shared radial draw point with a lateral wave:

```text
lateralRadius = float(sin(frame * 2*pi/33) * float(age))
0x1d: lateralAngle = parentAngle - 0x4000
0x1e: lateralAngle = parentAngle + 0x4000
draw += unit(lateralAngle) * lateralRadius
```

The apparently identical Ghidra branches conceal the angle sign. Disassembly
at `0x14006d64b` subtracts `0x4000` for `0x1d`, while `0x14006d6fe` adds it
for `0x1e`. Both branches add the result to the radial point saved at
`0x14006cf2f/0x14006cf54`. The PE constants are
`_DAT_14053a8e8=992.969696969697`, `DAT_14053a020=pi`, and
`DAT_140539d28=1/32768`, which reduce the phase to `2*pi*frame/33`.

Let:

```text
interval = {4, 3, 3, 3, 2}[difficulty]
speed    = {2.5, 3.2, 3.6, 4.0, 5.0}[difficulty]
q        = (age + frame) / 2
```

Inside the playfield, emit visual `0x0d`, behavior `2`, travel `0`, inherited
radius, and aux `0`. Emit at `parentAngle+0x4000` when
`q >= 0 && q % (2*interval) == 0`; emit at `parentAngle-0x4000` when
`q >= interval && (q-interval) % (2*interval) == 0`. Neither behavior kills
the parent. Evidence: `14006ce40...c:320-397` and disassembly
`0x14006d591..0x14006d911`.

### Behaviors `0x21` and `0x22`

At exact age `36`, emit one child and do not kill the parent:

```text
visual=2, behavior=4, travel=0,
angle = parentAngle + 12000  for 0x21
angle = parentAngle - 12000  for 0x22
speed = parent.baseSpeed + 1.2
radius = parent.radius
```

Evidence: `14006ce40...c:419-439`; `DAT_140539f68 = 1.2`.

### Behavior `0x28`

Resolve the stage entity whose `+0x04` id equals projectile aux `+0x44`, then
compute `(parent.field_0c - 60) % 1400`. At phases `870` and `1020` (`0x366`
and `0x3fc`), emit two children without killing the parent:

```text
visual=8, behavior=4, travel=0, radius=parent.radius, aux=0
angles = parentAngle-9000, parentAngle+9000
speed = parent.baseSpeed-1.0
```

Here `field_0c` maps to the reconstructed stage enemy helper timer. Evidence:
`14006ce40...c:440-465`; `DAT_140539f40=1.0`.

### Behaviors `0x29` and `0x2a`

Let:

```text
interval = {8, 6, 5, 5, 5}[difficulty]
speed    = {3.0, 3.5, 3.5, 4.0, 5.0}[difficulty]
```

For `age >= 0`, every `interval` frames, emit one child if the derived point
is inside the closed playfield. Neither branch kills the parent:

```text
0x29: visual=8, behavior=4, angle=parentAngle+age*200-24000
0x2a: visual=9, behavior=4, angle=parentAngle-age*200+24000
both: travel=0, speed=table value, radius=parent.radius, aux=0
```

Angles naturally wrap through the low 16 bits. Both use draw layer `0x50`,
final trail/effect flag `1`, and the `DAT_140e44190*12` emission-SFX path.
Evidence: `0x14006daf0..0x14006dc7a`.

### Behavior `0x2b`

Let:

```text
count = {1, 3, 5, 7, 7}[difficulty]
speed = {8.0, 10.0, 11.0, 12.0, 12.0}[difficulty]
```

At age zero, after the shared radial pre-step, snapshot the player's current
coordinates into the auxiliary anchor. The same age-zero update continues
into emission; the snapshot is not refreshed later. At ages `0,3,...,33`, if
the derived point is inside the closed playfield, emit this fan:

```text
visual=0x0c, behavior=4, travel=0, radius=parent.radius, aux=0
center=trunc(atan2(float(snapshotY-drawY), float(snapshotX-drawX))
             * 10430.378350470464)
spread=20000
```

The coordinate differences are first rounded as floats, then promoted for the
double `atan2`, and the fixed-angle conversion truncates toward zero. The fan
helper uses integer division; for seven shots the offsets are
`{-10000,-6667,-3334,-1,3332,6665,9998}`. This branch does not kill the
parent. It uses draw layer `0x50`, final flag `1`, and the same emission-SFX
path as `0x29/0x2a`. Evidence: `0x14006dc82..0x14006ddf5`.

### Behavior `0x2e`

Leaving the strict playfield boundary transforms the angle in this order:

```text
if x is outside: angle = 0x8000-parentAngle
if y is outside: angle = -parentAngle  // overrides the horizontal result
```

The unclamped derived point remains the fan's spawn point and this frame's
draw point. Separately clamp that point to the closed playfield and write it
back as the raw anchor. Emit a fan with `visual=0x0d`, `behavior=5`,
`spread=32000`, `travel=0`, inherited radius, aux `0`, and these tables:

```text
count = {3, 5, 6, 7, 7}[difficulty]
speed = {4.5, 5.0, 5.0, 5.5, 5.5}[difficulty]
```

The parent is then killed, while deferred unlink preserves its terminal draw.
The draw call uses layer `0x50` and final flag `1`. Evidence:
`0x14006ddf5..0x14006dfa7`.

### Behaviors `0x2f` and `0x30`

On even ages `4..34`, emit one child without a playfield gate:

```text
0x2f: visual=0x0c, behavior=2, angle=parentAngle+age*0x309+12000
0x30: visual=0x0d, behavior=2, angle=parentAngle-age*0x309-12000
both: travel=0, speed=8.5, radius=parent.radius, aux=0
```

At age `36`, create the white terminal effect and kill the parent. The runtime
currently preserves the kill and terminal-frame draw, but the generic effect
list does not yet exist, so it deliberately does not fabricate that effect.
Both branches use draw layer `0x51` and final flag `0`. Evidence:
`0x14006dfac..0x14006e0ae`.

### Behavior `0x31`

The transform triggers after the derived point leaves the radius-expanded
playfield. Reflection uses the same horizontal-then-vertical override as
`0x2e`, but the clamp helper receives the raw anchor fields rather than the
derived point. Emit one replacement from the unclamped derived point and kill
the parent:

```text
visual=10, behavior=0, angle=reflected angle
travel=0, speed=parent current speed, radius=parent.radius, aux=0
```

The draw call uses layer `0x50` and final flag `0`. Evidence:
`0x14006e0af..0x14006e1c8`.

### Behavior `0x32`

At non-negative ages divisible by `9`, only parent visual selectors `2` and
`3` emit. Selector `2` maps to child visual `8`; selector `3` maps to visual
`9`. Emit two children at `parentAngle-0x115c` and
`parentAngle+0x115c`, each with behavior `4`, travel `0`, speed `6.4`,
inherited radius, and aux `0`. The parent is not killed. The draw call uses
layer `0x51` and final flag `1`. Evidence: `0x14006e1c8..0x14006e2f6`.

### Behaviors `0x33` and `0x34`

`0x33` triggers when the entry-time derived point leaves the radius-expanded
playfield. From that unclamped point, emit a child with the parent's visual,
behavior `1`, travel `0`, speed `4.0`, inherited radius, and aux `0`, aimed at
the player's current position using the same float-difference/double-`atan2`/
truncate conversion as `0x2b`; then kill the parent.

At exact age `20`, `0x34` emits one child from the derived point without
killing the parent: visual `5`, behavior `1`, travel `0`, speed `3.0`,
inherited radius, aux `0`, and the same exact player aim conversion. Both use
draw layer `0x50` and final flag `0`. Evidence:
`0x14006e301..0x14006e413`.

The original switch tables use scalar defaults for invalid difficulty values,
whereas the runtime clamps difficulty to `0..4`. This has no effect on valid
gameplay difficulties. Draw-layer/final-flag metadata and the emission SFX
bridge remain unmodeled globally; the values above are retained for that
future bridge rather than approximated locally.

### Behaviors `0x37` and `0x38`

- At ages `0..50`, if current speed is positive, subtract `baseSpeed/50`
  after deriving this frame's radial draw point.
- At exact age `50`, resolve the parent entity through aux `+0x44`, take the
  low 16 bits of its `field_0c` timer, and emit three children spaced by
  `0x5555`.
- `0x37` adds `parentTimer*0x14d` to the projectile angle; `0x38` subtracts it.
- Children are visual `8`, behavior `2`, travel `0`, speed `4.8`, inherited
  radius, and aux `0`.
- After the terminal burst, spawn the white terminal effect and kill the
  scripted parent. The reconstructed runtime currently preserves the kill and
  terminal-frame draw; the generic effect-list bridge remains separate work.

Evidence: `14006ce40...c:739-782`, disassembly
`0x14006e418..0x14006e689`; `DAT_14053a380=50.0` and
`DAT_14053a0a0=4.8`.

### Behavior `0x39`

- Ages `0..29`: `speed -= baseSpeed/30` after this frame's radial pre-step.
- At age `30`, emit exactly two children at `parentAngle-15000` and
  `parentAngle+15000`, then kill the parent.
- Each child is visual `2`, behavior `2`, travel `0`, speed `5.2`, and inherits
  the radius.

Evidence: `14006ce40...c:783-799`; `DAT_14053a0b8 = 5.2`.

### Behavior `0x3c`

This case runs every frame, not every third frame:

- `speed += 0.15` after deriving this frame's draw point.
- Spawn one child `(visual=4, behavior=0x11, travel=0, speed=0, radius=1)` at
  a deterministic polar offset with integer radius `0..10` from the draw point.
  The fixed angle seed is `globalFrame + age*0x5c49`; the radius seed is
  `globalFrame + age*0xeac`, followed by `% 11`.
- Spawn one effect node at a separately seeded polar offset with radius `0..16`.
- Draw layer is `0x51` and trail/effect flag is `1`.

Evidence: `14006ce40...c:800-853`, plus disassembly
`0x14006e722..0x14006e852`; `DAT_140539e98 = 0.15`. The child-projectile
offset is ported; the separately seeded generic effect node remains pending.

## Integrated steering helper: `FUN_14006ecf0`

This family does **not** use radial anchor/travel motion. Its shared ordering is:

1. Compute the player target angle from the pre-move `x/y`.
2. Integrate stored `x/y` using the old current angle and old current speed.
3. Run the behavior switch, changing speed/angle for the next frame.
4. Draw at the integrated point, then apply the expanded cleanup rectangle.

Evidence: `14006ecf0...c:48-73` and `:463-470`. The common cleanup here is
`x:[playerX/6-250,playerX/6+850]`, `y:[-250,970]`. Steering must use a wrapped
signed 16-bit delta; when `abs(delta)` is within the maximum step it snaps to
the target, otherwise it advances exactly one signed step.

### Behavior `0x0c`

- Ages `0..59`: set speed to `8.0` at age zero, then subtract `0.11` whenever
  speed is greater than `1.4`. This gives `7.89` after the age-zero update and
  reaches `1.4` at age 59. Turn toward the pre-move player target by at most
  `0x29a` per frame.
- At age `60`, play the transition sound, set `speed=baseSpeed+0.1`, and begin
  the second turn regime.
- Ages `>60`: `speed += 0.1`.
- Second-regime maximum turn is
  `{120,160,200,250,300}[difficulty]` fixed-angle units.
- On every age, if the moved point is in the common expanded rectangle
  `[playerX/6-30,playerX/6+630] x [-30,750]`, emit stationary child
  `(visual=4, behavior=0x0f, speed=0)` with inherited radius.

Evidence: `14006ecf0...c:76-162`. Disassembly at
`0x14006ee68..0x14006eea7` confirms that age zero also performs the `0.11`
subtraction after loading `8.0`.

### Behavior `0x0e`

Let `baseTurn={200,240,270,300,300}[difficulty]`, `base=baseSpeed`, and
`phase=(age+30)*2*pi/120`.

- Ages `0..239`: `speed=(base+3)/2 + sin(phase)*(base-3)/2`.
- Ages `0..29`: maximum turn is `baseTurn+500`.
- Ages `30..239`: maximum turn is
  `baseTurn+300-int(sin(phase)*300)`.
- Ages `>=240`: `speed += 0.1` and maximum turn is exactly `200`.
- Every frame inside the common expanded rectangle, emit stationary child
  `(visual=5, behavior=0x0f, speed=0)` with inherited radius.
- Leaving the tighter rectangle
  `[playerX/6-20,playerX/6+620] x [-20,740]` creates the two grey/red boundary
  overlay draws; it does not itself kill the projectile.

Evidence: `14006ecf0...c:163-265`; constants are
`DAT_14053a798=546.133333...` (a 120-frame fixed-angle period),
`DAT_14053a650=300`, and `DAT_14053b128=-30`.

### Behaviors `0x23` and `0x24`

```text
interval = {15,11,9,9,8}[difficulty]
speed    = {3.5,4.5,5.5,5.0,6.0}[difficulty]
spread   = 0x7448 for 0x23, 0x85dc for 0x24
```

- At age zero, `0x24` first clamps/stores its position with margin `-30`.
- On every interval boundary, while inside `[playerX/6,playerX/6+600] x
  [0,720]`, emit a two-shot fan `(visual=8, behavior=3)` at the listed speed.
- Difficulty `3/4` emits a second two-shot fan at `speed+1.5`.
- Every frame in the common expanded rectangle, emit stationary child
  `(visual=5, behavior=0x0f, speed=0, radius=1)`.
- `speed += 0.1` every frame. These cases do not home toward the player.

Evidence: `14006ecf0...c:266-332` and shared increment at `:370-372`.

### Behavior `0x25`

- Every frame in the common expanded rectangle, emit stationary child
  `(visual=4, behavior=0x0f, speed=0)` with inherited radius.
- On difficulties `3/4`, turn toward the pre-move target by at most `0xa0`.
- `speed += 0.1` every frame.

Evidence: `14006ecf0...c:333-372`.

### Curving pairs `0x26/0x27` and `0x2c/0x2d`

- `0x26/0x27` turn step is
  `{150,170,180,195,211}[difficulty]`; `0x26` subtracts the step and emits a
  visual-5/behavior-`0x0f` stationary child, while `0x27` adds the step and
  emits visual 4. Both add `0.05` to speed every frame.
- `0x2c/0x2d` turn step is
  `{150,170,180,195,180}[difficulty]`; `0x2c` subtracts, `0x2d` adds, both add
  `0.05` to speed, and neither emits the stationary child.

These are fixed curves, not player-homing interpolation. Evidence:
`14006ecf0...c:373-447`; `_DAT_140539e28=0.05`.

### Behaviors `0x35` and `0x36`

For ages `0..89`, add/subtract exactly `0x5a` from the angle (`0x35` adds,
`0x36` subtracts) and add `0.05` to speed. At age `>=90`, this case makes no
further angle/speed change; it does not explicitly expire the projectile.
Evidence: `14006ecf0...c:448-462`.

## Special motion pairs

### Orbit/arc pair `0x1f/0x20`: `FUN_14006fcd0`

Implementation status: ported to `StageRuntime::updateProjectileOrbitArcPair`.
The generic projectile constructor already initializes `+0x10/+0x14` and
`+0x18/+0x1c` to the same source point, which is the state this helper expects.
The helper itself creates no child projectiles.

- Ages `0..39`: vertical radius is
  `int(sin(age*2pi/160)*150)` and horizontal radius is
  `int(sin(age*2pi/160)*320)`.
- Age `>=40`: vertical radius is `150` and horizontal radius is `320`; a
  defensive negative-age call uses zero radii, matching the signed fallback in
  the original assembly.
- At age `40`, set secondary angle to aim from auxiliary anchor
  `+0x18/+0x1c` to the player. Angle conversion truncates toward zero after
  multiplying by `10430.378350470464`; it does not round.
- For ages `>40`, increase speed by `0.05` while it is below `4.0`, then
  integrate the auxiliary anchor along the secondary angle.
- Rotate current angle each frame by
  `{0x46,0x78,0x8c,0xb4,0xdc}[difficulty]`; add for `0x1f`, subtract for
  `0x20`.
- Final position is the ellipse point around the auxiliary anchor. Cleanup is
  `x:[playerX/6-256,playerX/6+856]`, `y:[-256,976]`.
- `FUN_140133f30` reduces here to
  `x=auxX+cos(angle)*horizontalRadius` and
  `y=auxY+sin(angle)*verticalRadius`. The result is written back to node
  `+0x10/+0x14` before drawing and boundary cleanup.
- Invalid difficulty values retain the helper's default turn step `1`; valid
  difficulties use the table above.
- The helper draws first and only then clears active on an out-of-bounds frame;
  the runtime's deferred unlink therefore preserves the terminal draw.

Evidence: `14006fcd0...c:21-88`. Constants are
`DAT_14053a6d8=409.6`, `DAT_14053a510=150`, `_DAT_14053a668=320`,
`_DAT_140539e28=0.05`, and `DAT_14053a070=4.0`.

### Expanding spiral pair `0x3a/0x3b`: `FUN_14006ffc0`

Implementation status: ported to
`StageRuntime::updateProjectileExpandingSpiralPair`. Construction must preserve
the caller's initial travel at `+0x20`; the generic constructor does so, and
the helper itself creates no child projectiles.

- At age `0`, copy travel `+0x20` into auxiliary X `+0x18` as the permanent
  base radius. Set secondary angle to `0xc000` if starting below the player,
  otherwise `0x4000`.
- Negative age defensively yields current radius `0`. Ages `0..9` use
  `sin(age*2pi/40) * baseRadius`; age `>=10` uses the full base radius.
- Overwrite current speed each frame with `age*0.35 - 2.0`.
- Integrate the central `x/y` along the old current angle using that signed
  speed, then rotate by `+0x1bc` for `0x3a` or `-0x1bc` for `0x3b`.
- Draw at `center + unit(newAngle)*currentRadius`.
- Cleanup uses the integrated center and **integer-truncated** base radius
  `r=int(float(+0x18))`:
  `x:[playerX/6-(r+50),playerX/6+(r+650)]`,
  `y:[-(r+50),r+770]`.
- The visible point is not committed to center `+0x10/+0x14`; collision can be
  reconstructed from center, current radius `+0x20`, and the rotated angle.
  The runtime caches that same point in `x/y` for collision and deferred draw.
- Boundary death occurs after the draw call in the original; deferred unlink
  preserves that terminal frame in the runtime.

Evidence: `14006ffc0...c:16-68`; constants are
`DAT_14053a9d8=1638.4`, `DAT_140539ee8=0.35`, and `DAT_140539fc8=2.0`.

## Projectile visual bridge: `FUN_140070250`

The frame map is selector driven, but scale is not a fixed per-selector value.
For age `a`:

```cpp
scaleA = 1.1 + 0.1 * sin(2*pi*a/11);
scaleB = 1.1 + 0.2 * sin(2*pi*(a-6)/11);
```

- Selectors `0,1`: frame `0,1`, rotation `age*2000`, uniform `scaleA`.
- Selectors `2,3`: frame `2,3`, rotation `age*999`, uniform `scaleA`.
- Selectors `4,5`: frame `4,5`, rotation `age*0x682`, uniform `scaleA`.
- Selectors `6..9`: frames `6..9`, supplied angle, scale `(1.0, scaleB)`.
- Selectors `0x0a..0x0d`: frames `20..23`, supplied angle,
  scale `(scaleA,scaleB)`.
- Selectors `0x0e,0x0f`: frames `24,25`, rotation `age*999`, uniform
  `scaleA`.
- Selector `0x10`: frame `26`, supplied angle, scale `(1.0,scaleB)`.
- Selectors `0x11/0x12` draw the `Effect_s` frame-7 pulse before their base
  frame. Its Y scale is `0.6 + 0.4*sin(2*pi*age/17)`. Selectors `0x13/0x14`
  draw `Enemy_s` frames `117/118` at rotations `-age*0x457` / `age*0x457`
  before their base frame, then append persistent generic effect nodes.

Evidence: `140070250...c:25-184`; `DAT_140539f58=1.1`,
`DAT_140539e60=0.1`, `DAT_140539ec8=0.2`, and
`_DAT_14053ab18=5957.8181818` (an 11-frame fixed-angle cycle).

If the final helper flag is `1`, it also creates the low-alpha type-5 trail
effect (`140070250...c:185-187`).

## Recommended implementation shape

Keep the raw semantics visible in the runtime model:

```cpp
struct Projectile {
    int visualSelector;
    int behaviorId;
    Vec2 anchorOrPosition;
    Vec2 auxiliaryAnchor;
    float travel;
    uint16_t angle;
    uint16_t secondaryAngle;
    double speed;
    double baseSpeed;
    int radius;
    // flags/aux/age...
    Vec2 drawPosition; // cached each update for collision and deferred drawing
};
```

Use helper-specific motion modes instead of a universal velocity integrator:

- common/scripted/reflect: anchor + radial travel;
- homing family: directly integrated `x/y`, with move-before-steer ordering;
- `0x1f/0x20`: ellipse around a separately moving auxiliary anchor;
- `0x3a/0x3b`: integrated center plus a draw-only radial offset.

This prevents `prevX/prevY`, anchor, current draw point, and velocity from being
collapsed into one pair of fields, which is the source of most current
approximation drift.
