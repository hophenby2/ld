# Stage 02 Schedule and Enemy Exact-Port Notes

Primary evidence:

- Stage schedule: `stage_02_gameplay_update_candidate @ 0x140119640`, exported
  under `per-stage-gameplay-renamed/neighborhood-decompiled` as
  `140119640_stage_02_gameplay_update_candidate.c`.
- Spawn constructors: `stage_spawn_dispatch_candidate @ 0x14007b710` and
  `stage_entity_spawn_candidate @ 0x140078a00`.
- Type `0x19`: `FUN_1400841d0 @ 0x1400841d0`.
- Type `0x1a`: `FUN_140084be0 @ 0x140084be0`.
- Type `0x1b`: `FUN_1400853f0 @ 0x1400853f0`.
- Type `0x1c`: `FUN_140085f70 @ 0x140085f70`.
- Type `0x1d`: `FUN_140086aa0 @ 0x140086aa0`.
- Type `0x1e`: `FUN_1400870a0 @ 0x1400870a0`.
- Type `0x1f`: `FUN_140087750 @ 0x140087750`.
- Type `0x20`: `FUN_140088110 @ 0x140088110`.
- Type `0x21`: `FUN_140088c20 @ 0x140088c20`.
- Enemy gauge: `FUN_140079c10 @ 0x140079c10`.
- Ghidra scalar dump: `exports/stage02-enemy-scalars.tsv`.

## Schedule status

`StageRuntime::spawnStage02OriginalSchedule` retains all 56 recovered spawn
dispatcher call sites, including both literal path arrays created at frames
`800` and `0x1c20`. The repeated stage RNG expression is represented by
`stageScriptRandFromFrame`; it is the same frame-seeded MT initialization and
temper sequence used at each schedule call site, not a generic random stand-in.

At frame `0x14b4`, the schedule spawns type `0x20` and sets the Stage 2 gate.
Only `FUN_140088110` owns its release: after the controller enters death state
`2`, helper timer `60` clears the gate. The old schedule-side HP watcher and
parallel 60-frame countdown were removed because they duplicated that state
machine and could release on a different frame.

## Type `0x19`

The dispatcher block at `0x14007bc4f` constructs this node with update case
`0x0e`, reward weight `6`, collision radius `40`, angle `0x4000`, speed `1.0`,
and the entry invulnerability flag set. Schedule x/y are retained. State zero
draws Effect_m frame `4` at the `FUN_1401346a0(position,-20)` clamped point with
scale `2-timer*0.1`. At timer `20`, the helper sets speed `1.4`, chooses angle
`0` for the left edge or `0x8000` for the right edge (otherwise retaining
`0x4000`), clamps the live position, clears invulnerability, and resets its
timer.

For state timer `<150`, it turns toward the player by at most `0x80`, adds
`0.02` speed, and moves. Thereafter it turns toward `0xc000` by `0x100` and
adds `0.1` speed. Firing uses pre-movement `(x,y+10)` and snaps aim to an
`0x800` angle sector:

```text
difficulty       0     1     2     3     4
start           36    30    24    20    16
interval       150    48    32    32    20
spread          900  2800  4000  2500  2500
speed           4.0   5.0   6.0   7.0   8.5
```

Each firing frame emits visual `5`, behavior `0`: a two-node spread at the
listed speed and one center node at `speed*1.1`. Difficulties `3/4` prepend a
second spread at `speed*0.9` and twice the listed spread. On stages `8+`, the
helper substitutes starts `{32,24,20,20,16}`, intervals `{80,40,32,32,20}`,
and speeds `{5,6,6.5,7,8.5}`.

The multipart body uses Enemy_s frame `15` at scale
`1+0.1*sin(timer*2*pi/51)`. Two mirrored Enemy_s frame `16` parts orbit from
angle `trunc(6500*sin(timer*2*pi/11))-8000`, with a 40-pixel arm and `15/-5`
positional offsets. Death uses the original `300` payout window; bounds are x
`playerX/6-180 .. playerX/6+780` and y `-180 .. 900`.

## Type `0x1a`

The dispatcher block at `0x14007b869` constructs this node with update case
`0x0f`, reward weight `5`, collision radius `30`, angle `0x4000`, speed `1.0`,
and the entry invulnerability flag set. It preserves schedule x but forces y
to `-20`. Its 20-frame marker phase is the same as type `0x19`. At activation,
the helper seeds its inline MT expression from the global stage frame, sets
speed `8.6`, chooses heading `0x3b50+random%0x961`, initializes visual rotation
from `random-random/0x10001`, clamps position, and becomes hittable.

For timers `0..39`, heading approaches the pre-movement player aim by `0x80`
and speed decreases by `0.2` while above `0.6`. From timer `40` onward the
heading is retained and speed increases by `0.16`. Visual rotation adds
`0x378` every frame. While inside the play rectangle, farther than 100 pixels
from the player, and before timer `90`, it emits visual `0x0e`, behavior `0`,
travel `0`, radius `1`, aux `0`:

```text
difficulty       0    1    2    3    4
start           18   14   12   12    8
interval        32   24   16   16    8
speed          5.5  6.5  7.5  8.0  9.6
```

Difficulties `3/4` add a second shot at `speed-2`. On stages `4+`, starts are
`{16,12,8,8,8}` and intervals `{27,20,13,13,8}`. Drawing places pulsing,
rotating Enemy_s frame `17` over frame `18`; pulse scale is
`1+0.1*sin(timer*2*pi/23)`. Death and bounds match type `0x19`.

## Type `0x1b`

The dispatcher branch at `0x14007b899` constructs this node with update case
`0x10`, reward weight `20`, collision radius `80`, forced y `-100`, angle
`0x4000`, speed `1.0`, and the initial invulnerability flag set.

State `0` clamps the entry marker to the playfield extended by `50` pixels and
draws Effect_m frame `4` at scale `3.0-timer*0.15`. At timer `20`, it changes
to state `1`, resets the timer, sets speed `7.0`, and becomes targetable. The
new state executes immediately on that transition frame.

In state `1`, the current angle turns toward the player by at most `0x80` per
frame. Through timer `120`, speed drops by `0.1` while it remains above `1.5`;
from timer `240` onward it drops by `0.1` without a floor. Movement uses that
angle and speed directly. Firing is limited to timers `24..239`:

```text
difficulty       0     1     2     3     4
cycle          120    80    70    70    60
front count      3     5     7     7     9
front speed    4.0   5.0   5.5   6.0   7.2
rear base      5.5   6.5   7.0   7.5   9.5
rear spread      0  1800  4800  4800  4400
```

Cycle phase `0` emits visual `5` from `y+65*bodyScale`, centered on the player,
with spread `(count-1)*300`. Difficulties `3/4` add a second fan at speed
`-0.5` and spread `(count-1)*450`. At phase `30`, the helper snapshots aim from
`y-50*bodyScale`; phases `30,34,...,58` emit visual `0` with speed increasing by
`0.2` each shot. Higher difficulties add the recovered two-shot spreads and
fast direct layers. After each rear volley, saved aim approaches live aim by at
most `0x40`.

The multipart body uses Enemy_m frame `35` at mirrored offsets
`x +/- (30+20*cos(flap))`, `y+10+20*sin(flap)`, where
`flap=sin(timer*2*pi/27)*3300`. Enemy_m frame `34` is centered at `(x,y)` with
vertical scale `1+0.05*sin(timer*2*pi/72)`. Death uses payout window `500`; the
four removal bounds are `origin-128`, `origin+728`, `-128`, and `848`.

## Type `0x1c`

The dispatcher constructs update case `0x11`, reward weight `30`, collision
radius `60`, Enemy_m base frame `36`, angle `0x4000`, speed `1.0`, and an
initially invulnerable node. State `0` draws Effect_m frame `4` at the
playfield-expanded-by-50 clamp with scale `3-timer*0.15`. At timer `20`, the
position is reclamped with a 100-pixel expansion, speed becomes `2.5`, the
heading becomes decimal `6000` for x `<=360` or `0x6890` otherwise, and state
`1` executes immediately.

State `1` turns toward `0xc000` by `0x14` per frame and moves directly. Both
patterns fire from `(x,y+30)` only while the entity point is in the playfield:

| Difficulty | Cycle | Burst window | Burst speed | Fan count | Fan speed |
|---:|---:|---:|---:|---:|---:|
| 0 | 100 | 21 | 5.5 | 4 | 3.5 |
| 1 | 80 | 30 | 6.5 | 8 | 4.5 |
| 2 | 60 | 36 | 8.0 | 10 | 5.0 |
| 3 | 60 | 36 | 9.0 | 10 | 5.0 |
| 4 | 54 | 36 | 10.5 | 12 | 6.5 |

Timers `45..299` snapshot aim at cycle phase zero before applying the playfield
fire gate, then emit selector `9`, behavior `0` at every third phase inside the
burst window. Difficulties `3/4`
add angles `savedAim-3500` and `savedAim+3500`. Timers `85..299` emit selector
`4`, behavior `0` fans every cycle using live aim, spread `27000`, and the
listed count/speed; difficulties `3/4` add a `speed+1.2` fan.

Drawing uses Enemy_m frame `37` at `y+35`, frame `36` with x scale
`1-0.05*sin(timer*2*pi/61)`, and three frame-`38` rotors at `y-50` with angles
`timer*0x708`, `+0x5555`, and `-0x5556`. Death uses payout window `500`.
Removal bounds are x `playerX/6-360 .. playerX/6+960` and y `-360 .. 1080`.

## Type `0x1d`

The dispatcher branch at `0x14007bde7` constructs this node with update case
`0x12`, reward weight `5`, collision radius `40`, angle `0x4000`, speed `1.0`,
and the initial invulnerability flag set.

Every helper call first adds the integer stage-scroll scalar `1` to y. At
`y >= 0` the node becomes targetable. While `y < 400`, firing uses global
stage frame rather than the entity timer:

```text
interval = {90, 50, 40, 30, 20}[difficulty]
speed    = {4.5, 5.5, 6.5, 7.0, 8.0}[difficulty]
phase    = globalFrame % interval
```

At phase zero, aim from `(x,y+30)` at the player, add `0x400`, then retain that
angle. At phases `0,3,6`, mask it with `0xf800` and emit visual `1`, behavior
`0`, travel `0`, collision radius `1`, and aux `0`. Difficulties `3/4` emit a
second node at `speed+1.8`.

The body is Enemy_s frame `19`, drawn in the original layer pair with x scale
`1-0.05*sin(timer*2*pi/60)`. During timer remainders `0..10` modulo `120`, the
scale is replaced with `1+0.05*sin(timer*2*pi/10)`.

## Type `0x1e`

The dispatcher branch at `0x14007bb47` constructs this node with update case
`0x13`, reward weight `7`, collision radius `40`, angle `0x4000`, speed `1.0`,
and the initial invulnerability flag set. It has the same `y += 1`, `y >= 0`
activation, and `y < 400` firing bounds as type `0x1d`.

```text
interval = {140, 100, 80, 80, 50}[difficulty]
speed    = {5.0, 6.0, 7.0, 8.5, 9.5}[difficulty]
```

Starting at entity timer `80`, each cycle snapshots player aim from
`(x,y-60)` at phase zero and emits visual `0x0c`, behavior `0`, travel `0`,
radius `1`, aux `0` at phases `0,12,24,36`. On difficulties `3/4`, a second
cycle beginning at timer `86` emits angles `savedAim-600` and `savedAim+600`
at phases `0,12,24`.

The multipart draw uses Enemy_m frame `39 + entityId%4` at `(x,y-50)` with x
scale `1-0.05*sin(timer*2*pi/25)`, plus Enemy_s frames `20,21,22` at
`(x,y-60)`, each held for three frames.

Both helpers award through the original `1000`-frame payout window on death
and unlink at `y >= 760`. Their terminal type-`0x37` node uses Effect_s frame
`6` on layer `0x15` at alpha `128`: type `0x1d` places it at `y+10` with a
`1.0..1.2` scale, while type `0x1e` uses `y+5` and `0.8..1.0`.

## Type `0x1f`

The dispatcher constructs update case `0x14`, reward weight `50`, collision
radius `100`, Enemy_m frame `43`, angle `0x4000`, speed `1.0`, and an initially
invulnerable node. Every update first adds the stage scroll value `1` to y.
State `0` changes to state `1` at `y >= -100`; timer `50` makes the node
targetable. Firing requires x in `playerX/6-50 .. playerX/6+650`, y in
`-50 .. 770`, and y `<350`.

The aimed selector-`3`, behavior-`1` fan fires from `y+70` starting at timer
`50`. Its intervals are `{50,30,30,30,20}`, counts `{1,3,5,5,5}`, speeds
`{3,3,4,4,5}`, and spread `18000`. Difficulties `3/4` add identical fans at
aim offsets `+800` and `-800`.

Starting at timer `60`, a second pattern uses cycles `{90,72,60,50,50}`. Cycle
phases below `32` divisible by `8` emit two selector-`4`, behavior-`0` full
rings from `y-55`, with counts `{6,12,14,16,16}` and speeds
`{4,4,4.5,5,7}`. The base angle is `signedStep*timer`, where the steps are
`{18,25,25,36,42}` and x positions left of `360` use the negative sign; the
second ring adds `800`.

Death pays through window `0x708`, disables collision, and retains a 60-frame
state `2`. Active x scale is `1-0.05*sin(timer*2*pi/50)`; death x scale is
`1+0.15*sin(timer*2*pi/9)`. Both are drawn once at alpha `64` and once opaque.
Timers `0..60` run the shared death-explosion chain. At timer `60`, the enemy
creates a terminal type-`0x37` Effect_m frame `18` at `y+30`, alpha `128`, and
scale `1.0..1.1`, then unlinks. The y bound remains `820`.

## Types `0x20` and `0x21`

Type `0x20` is the gated Stage 2 controller: update case `0x15`, reward weight
`120`, radius `150`, and five type-`0x21` children. It scrolls downward, enters
its active state at y `-150`, and fires selector `3`, behavior `7` half-cycle
fans beginning at timer `50`. Each actual firing frame recomputes truncated
player aim from `(x,y+85+bob)` before applying the frame-seeded random offset;
this matters on Easy because the 120-frame half-cycle is not divisible by the
45-frame interval. Death enters a 60-frame state, and only timer `60` clears
the stage gate. Its timers `0..60` use the same explosion chain as type `0x1f`;
the terminal node is type `0x37`, Effect_l frame `12`, `y+60`, alpha `128`, and
scale `0.9..1.0`.

Each type `0x21` child resolves its parent before updating, scrolls down, enters
state `1` at y `-55`, and becomes targetable at timer `30`. Its growing
selector-`0x0c` fan and higher-difficulty selector-`0x0d` layer retain the
cycle-start aim. Parent removal or HP exhaustion unlinks the child without a
second parent payout.

## Shared death effects

`FUN_14007ac00` is represented by the separate `0x60`-byte-style stage-effect
queue with the original `0x1000`-node cap. On every death timer divisible by
`3`, it chooses a point up to `radius+50` pixels from the enemy using the
timer-seeded angle and distance, then creates both of these nodes there:

- Type `0x2a`, or `0x2b` while the Stage 2 gate is set: Effect_m frame `5`,
  layer `0x3e`, lifetime `24`, speed `1`, and scale
  `radius/200+0.1 .. radius/200+0.4`. Ages `0..7` use
  `sin(age*pi/16)` scale-in, ages `16..24` fade linearly, and drawing rotates
  by `age*0x640` while the node moves along its base angle.
- Type `0x2c`: Player frame `14`, layer `0x48`, alpha `192`, scale
  `0.8..1.6`, and speed `14..22`. The invariant seed `angle+spawnFrame`
  selects lifetime `30..50`, pulse start `5..30`, rotation step `30..600`,
  and the exact sine pulse/fade. Speed follows
  `base*(1-sin(age*pi/(2*lifetime)))`; stored scale grows by `0.005` per frame.

Every timer divisible by `6` plays `Blast1.wav` at SE-volume multiplier
`0x14`. Effects at layers below `0x18` draw behind enemies; the two chain
layers draw in the foreground.

Terminal type-`0x37` nodes retain their angle, scale, color, and alpha while
moving down by the stage-scroll scalar `1`. They persist until their center is
outside the vertical play rectangle, or outside the horizontal interval rooted
at `playerX/6`, by one full source-graph width (`100`, `200`, or `600` for the
small, medium, and large terminal frames). This matches the dynamic origin in
`FUN_140076b00`, rather than treating the left edge as a fixed constant.

## Gauge modes

The shared `FUN_140079c10` renderer is represented directly instead of by
per-enemy approximations. All modes use alpha `192`, a fill y offset of `-5`,
and the original red/green/blue HP-ratio ramp:

| Mode | Background | Fill x offset | Fill x scale | Stage 2 users |
|---:|---:|---:|---:|---|
| 0 | `EnemyGauge1[0]` | `-120` | `ratio` | targetable type `0x20` |
| 1 | `EnemyGauge1[1]` | `-60` | `ratio*0.5` | types `0x1b`, `0x1c`, targetable `0x1f`, active `0x21` |
| 2 | `EnemyGauge1[2]` | `-40` | `ratio/3` | active types `0x19`, `0x1a`, and every-frame `0x1d/0x1e` |

## Remaining Stage 02 gaps

Scheduled types `0x19..0x21` now bypass generic movement and emission and own
their helper timers, state changes, firing, drawing, death, and removal bounds.
The type-`0x2b` age-zero reward/item derivative still depends on the separate
original reward queue and `DAT_140e44590`; it is intentionally not folded into
the minimal visual-effect queue. Stage-end fade/effect/audio work also remains
shared runtime infrastructure rather than schedule logic.
