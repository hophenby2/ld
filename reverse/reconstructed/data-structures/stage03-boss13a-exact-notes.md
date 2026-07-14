# Stage 3 boss `0x13a` exact reverse-engineering notes

Status: audited against the original `LikeDreamer.exe` and connected to the
reconstruction as a single lifecycle unit. The port includes the nine-state
root, four live bars, phase breaks, root projectile/entity patterns,
`0x30..0x34`, multipart drawing, Boss HUD, and final clear. No build or game
run was performed for this port.

## Evidence set

- Stage handoff:
  `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/14011b3d0_stage_03_gameplay_update_candidate.c:461-470`.
- Root helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/14000ed10_FUN_14000ed10.c`.
- Type `0x30` helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140011a80_FUN_140011a80.c`.
- Type `0x31` helper:
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/1400120b0_FUN_1400120b0.c`.
- Types `0x32/0x33` helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140012dc0_FUN_140012dc0.c`.
- Type `0x34` helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140013c00_FUN_140013c00.c`.
- Dispatch proof:
  `reverse/reconstructed/data-structures/stage-entity-update-dispatch-map.csv`.
- Shared phase-break, final-clear, ambient-effect, and boss-HUD helpers:
  `FUN_1400031d0`, `FUN_140003ad0`, `FUN_140004140`, and
  `FUN_140002260`.
- Existing scalar cross-checks:
  `reverse/ghidra-or-ida/exports/stage03-enemy-exact/scalars.tsv`.

The dispatch mapping is exact and must not be confused with projectile
selectors that happen to use the same numeric values:

| Spawn type | Update case | Helper |
| ---: | ---: | --- |
| `0x30` | `0x23` | `FUN_140011a80` |
| `0x31` | `0x24` | `FUN_1400120b0` |
| `0x32` | `0x25` | `FUN_140012dc0` |
| `0x33` | `0x25` | `FUN_140012dc0` |
| `0x34` | `0x26` | `FUN_140013c00` |
| `0x13a` | `0xa1` | `FUN_14000ed10` |

## Handoff and constructor

The Stage 3 length-table value is frame `9500`. At `endFrame + 0x3c`, or
frame `9560`, the original performs:

```text
stage_entity_spawn_candidate(
    type=0x13a, hp=100000, kind=0,
    x=360.0f, y=200.0f, angle=0,
    speed=0.5, radius=150, untargetable=1, owner=0)

DAT_140e44308 = next entity id
DAT_140e418cc = 1
DAT_140e419bc = 0
DAT_140e41b0c = 100000
DAT_140e4192c = 0
DAT_140e41af8 = 4
```

As in the other boss helpers, `+0x54 == 1` is the inverse targetability
gate. The root is initially invulnerable; it does not have a separate fake
activation-delay timer.

The relevant root fields are:

| Offset | Meaning for this helper |
| ---: | --- |
| `+0x00` | active flag |
| `+0x04` | entity id |
| `+0x08` | owner id |
| `+0x0c` | state-local timer, incremented by the dispatcher after the helper |
| `+0x10` | targetable-age timer |
| `+0x14` | root state `0..8` |
| `+0x18` | spawn type `0x13a` |
| `+0x1c/+0x20` | current/original HP |
| `+0x28/+0x2c` | current x/y |
| `+0x30/+0x34` | constructor origin x/y |
| `+0x40/+0x42/+0x44` | current, saved, and working fixed angles |
| `+0x48` | movement speed |
| `+0x50` | collision radius |
| `+0x54` | inverse targetability gate |
| `+0x5c` | live phase-child count |

## Phase-break preamble

The break check runs before the state switch. While
`DAT_140e419bc == 1`, either root HP below one or the shared countdown below
one calls `FUN_1400031d0`, spawns type `0x137` at the root, makes the root
invulnerable, resets the state timer, and selects the next transition:

| Breaks before decrement | New state | New mode | Radius change |
| ---: | ---: | ---: | ---: |
| `4` | `2` | `2` | `200` |
| `3` | `4` | `2` | `200` |
| `2` | `6` | `2` | unchanged (`80`) |
| `1` | `8` | `-1` | unchanged (`80`) |

The helper then decrements `DAT_140e41af8`, clears `+0x5c`, and executes the
new state in that same call. Generic enemy death must therefore never run
first for this root.

Every live bar starts with countdown `1800`. The root helper installs the new
bar, then its common HUD tail runs on the same frame, so the newly written
countdown is already `1799` when the frame completes. This ordering matters
for exact phase length.

## Root state machine

| State | Duration/exit | Exact behavior |
| ---: | --- | --- |
| `0` | through `t=180` | Intro. At `t=0`, create two `0x30` and two `0x31` children. Run the two-part integer-truncated y trajectory below. At `t=180`, clear the hit gate and enter state `1` with HP/max HP `70000`, radius `150`, countdown `1800`, and mode `1`. |
| `1` | until HP/time break | Move at speed `0.5`, turning toward the shared random target by at most `0x200`. Run the expanding fan described below. Break enters state `2`. |
| `2` | through `t=200` | First transition. For `t<90`, add `t*0.04` to y and run the ambient transition effect. At `t=90`, set speed `3.0`. From `t>=90`, turn toward the random target by `0x309` and move. At `t=200`, radius returns to `150`, the root becomes targetable, and state `3` starts at HP/max HP `66000`. |
| `3` | until HP/time break | Move at speed `3.0`, turn by `0x309`, and run both 1200-frame root patterns below. This state refreshes its random target every 25 global frames. Break enters state `4`. |
| `4` | through `t=380` | Second transition. For `t<120`, add `t*0.02` to y and run the ambient effect. At `t=120`, set speed `0.5`. From `t>=130`, turn by `0x200` and move. The phase-title helper begins after `t=220`. At `t=380`, set radius `80`, become targetable, and start state `5` at HP/max HP `40000`. |
| `5` | until HP/time break | Move at speed `0.5`, turn by `0x200`, and create the alternating `0x32/0x33` sweeps described below. The root has no substitute generic volley in this phase. Break enters state `6`. |
| `6` | through `t=180` | Add `0.1` to y each frame and run the transition effects, including the ambient helper for the early window. At `t=180`, become targetable and start state `7` at HP/max HP `50000`. Radius stays `80`. |
| `7` | until HP/time break | Continue the `0x200` steering and `0.5` movement. At `t=10`, create four `0x34` children and set live-child count to four. Once `t>99` and all four are gone, reset the root timer to zero and repeat the child cycle. Break enters state `8`. |
| `8` | through `t=480` | Call `FUN_140003ad0` every frame. For `t<240`, add `0.2` to y, run final effects, and draw Boss frames `23/24`; result panels occupy `t=60..239`. Create the final disappearance effect at `t=240`. The clear helper starts the result transition at `t=420`; at `t=480` it requests clear and the root deactivates. |

State 0 keeps x at `360` and computes y exactly as follows:

```text
t = 0..59:   y = -200 + trunc(sin(t * pi / 120) * 600)
t = 60:      y = 400
t = 61..179: y =  200 + trunc(sin((t + 60) * pi / 240) * 200)
t = 180:     y = 200, then enter state 1
```

The common random target refresh at every 50th global frame is
`x = random % 301 + 210`, `y = random % 101 + 150`. State 3 replaces that
y range with `120..220` and refreshes every 25 global frames.

## Root projectile patterns

`FUN_14006c2f0` is the single-projectile creator and `FUN_1400709b0` is the
spread creator. Angles and spread widths below use the original 16-bit turn
domain.

### State 1: expanding aimed fans

Let `p=t%1000`. Only `p=80..399` is active. Split that range into four
80-frame blocks and let `q=(p-80)%80`, `block=(p-80)/80`.

At `q=0`, cache player aim from `(x,y+140)`. While `q` is below the
difficulty-specific burst length, every fourth frame emits visual `12`,
behavior `0`, travel `10`, and radius `1`:

| Difficulty | Burst length | Per-node angle step | Base speed |
| ---: | ---: | ---: | ---: |
| `0` | `20` | `300` | `4.0` |
| `1` | `36` | `400` | `6.0` |
| `2` | `50` | `500` | `7.5` |
| `3` | `60` | `500` | `8.0` |
| `4` | `60` | `600` | `9.0` |

```text
count  = q / 4 + 1
speed  = baseSpeed + block * 0.5
spread = (count - 1) * angleStep
```

This produces a fan that grows by one projectile on each firing frame. The
cached aim is refreshed at the beginning of every 80-frame block.

### State 3: aimed fan section

Let `p=t%1200`. For `p=30..279`, every `cadence` frames fire visual `5`,
behavior `0`, centered on a cached player aim, with spread `24000`:

| Difficulty | Cadence | Count | Speed |
| ---: | ---: | ---: | ---: |
| `0` | `40` | `5` | `4.0` |
| `1` | `36` | `7` | `5.5` |
| `2` | `30` | `9` | `6.5` |
| `3` | `20` | `9` | `6.0` |
| `4` | `16` | `9` | `7.0` |

The aim is recaptured every `cadence*3` frames. Difficulty `1+` adds visual
`1`, behavior `0`, at `speed-1.2` and `count-1`, using the same center and
spread.

### State 3: accelerating eight-window section

The second section consists of eight windows. With `i=0..7`:

```text
start[0]   = 320
start[i+1] = start[i] + gap + 15*i
end[i]     = start[i] + 30 + 15*i       // exclusive
```

The difficulty table is:

| Difficulty | Gap | Count | Speed slope per window frame |
| ---: | ---: | ---: | ---: |
| `0` | `70` | `3` | `0.10` |
| `1` | `50` | `5` | `0.18` |
| `2` | `40` | `7` | `0.20` |
| `3` | `40` | `7` | `0.20` |
| `4` | `40` | `9` | `0.24` |

At the start of each window, cache player aim. Every five frames in that
window, fire visual `3`, behavior `0`, count from the table, spread `27000`,
and speed:

```text
speed = 3.5 + (p - start[i]) * slope
```

After each shot the cached aim approaches current player aim by at most
`0x78`. Difficulties `3/4` add a second identical fan at `speed+1.5`.

### State 5: alternating entity sweeps

State 5 creates entities, not direct root projectiles. Let
`phase=(t-10)%(period*2)`:

| Difficulty | Period | Spawn cadence |
| ---: | ---: | ---: |
| `0` | `150` | `10` |
| `1` | `120` | `9` |
| `2` | `100` | `8` |
| `3` | `100` | `8` |
| `4` | `100` | `8` |

- For `phase=0..59`, every cadence frames create `0x32` with target
  `(phase*12,0)` and speed `1.0`.
- For `phase=period..period+59`, every cadence frames create `0x33` with
  local phase `r=phase-period`, target `(720-r*12,0)`, and speed `1.5`.

Both use HP `500`, kind `4`, radius `30`, the fixed-angle aim from
`(root.x,-3200)` to the player, the inverse hit gate set, and the root id as
owner.

## Child entity contracts

### Type `0x30`: destructible lower arms

State 0 creates two nodes:

| HP | Kind | Relative x/y | Angle | Speed | Radius | Initially blocked |
| ---: | ---: | --- | ---: | ---: | ---: | ---: |
| `10000` | `48` | `(+150,+120)` | `0x4000` | `1.0` | `50` | yes |
| `10000` | `48` | `(-150,+120)` | `0x4000` | `1.0` | `50` | yes |

Each node follows `root + relativeOffset`, closing one fifth of the remaining
distance per frame. It becomes targetable when the root reaches state `1`.
Its live attack starts after child timer `10`:

| Difficulty | Cycle | Spread count | Speed |
| ---: | ---: | ---: | ---: |
| `0` | `100` | `1` | `5.0` |
| `1` | `60` | `1` | `6.0` |
| `2` | `40` | `1` | `7.0` |
| `3` | `36` | `2` | `8.0` |
| `4` | `30` | `2` | `9.0` |

For the first 20 frames of each cycle, every fourth frame emit visual `3`,
behavior `0`, downward at angle `0x4000`, from `y+65`, with spread `3000`.
The helper draws `Enemy_l[14]` in its attached/live states and `Enemy_l[16]`
in its destroyed/withdrawal state, plus the paired `Effect_s[0]` accents. It
uses enemy gauge mode `1`.

On death it calls `FUN_14007b010(child,1800,8)`, performs cleanup mode `2`,
spawns type `0x153`, decrements the root live-child count, and enters the
withdrawal state. It is removed when the root has moved beyond the matching
transition.

### Type `0x31`: invulnerable upper satellites

State 0 also creates two nodes:

| HP | Kind | Relative x/y | Angle | Speed | Radius | Initially blocked |
| ---: | ---: | --- | ---: | ---: | ---: | ---: |
| `99999999` | `0` | `(+100,-100)` | `0x4000` | `1.0` | `50` | yes |
| `99999999` | `0` | `(-100,-100)` | `0x4000` | `1.0` | `50` | yes |

They remain attached to the root and are not ordinary destructible enemies.
Their local state follows root states `1`, `2`, and `3`; state `2` is a quiet
bridge and state `3` has its own attack. The helper computes projectile sources
before snapping to the parent: `oldPosition + unit(oldHeading)*70`. The
root-state-1 script uses
`local=t%1000` and has three sections:

- `local=30..399`: visual `7`, behavior `0`, aimed spreads. Cadence is
  `{100,50,40,40,30}` by difficulty. The helper emits a base speed layer and
  a second layer at `speed+0.3`; the per-difficulty base speeds are
  `{4.5,5.5,6.0,6.5,7.5}`, counts are `{1,1,1,3,3}`, and spread is `2400`.
- `local=430..699`: visual `13`, behavior `1`, rotating spreads. The emission
  divisors are `{4,3,2,2,2}`, counts are `{1,2,3,3,4}`, and full spread is
  `(count-1)*8888`. Base speeds are `{2.0,3.0,4.0,3.0,3.5}`;
  difficulties `3/4` add another spread at `speed+1.5`.
- `local=730..999`: visual `6`, behavior `0`, aimed/rotating spreads in
  40-frame bursts. Cadence is `{80,45,40,40,40}`, count is
  `{3,5,7,7,9}`, and spread is `22000`. Base speeds are
  `{4.0,6.0,7.0,7.0,8.0}`; speed then grows by `0.5` per burst and `0.1` per
  frame within the burst. Difficulties `3/4` add a layer at `speed+1.6`.

After the root enters state `3`, let `p=localTimer%1200`. In `p=690..1119`,
the two satellites alternate side-dependent aimed spreads:

| Difficulty | Per-side interval | Count | Speed |
| ---: | ---: | ---: | ---: |
| `0` | `140` | `3` | `7.7` |
| `1` | `100` | `5` | `8.5` |
| `2` | `90` | `7` | `9.0` |
| `3` | `90` | `7` | `9.0` |
| `4` | `70` | `7` | `9.0` |

The positive-x satellite begins at `p=690`; the negative-x satellite begins
one interval later. Each individual satellite fires every twice-interval.
The positive side uses visual `3`, behavior `26`; the negative side uses
visual `2`, behavior `27`. Spread is `20000`.

This helper draws `Enemy_m[62]` on layer `0x21`, mode `7`, rotated by its
current heading. State `1/2` bypass the HP/countdown tail, so the pair survives
the first break; state `3` reaches that tail and removes the pair on the second
break. A root state beyond `4` also removes it.

### Types `0x32/0x33`: opposing sweep nodes

Both types use `FUN_140012dc0`. Their 40-frame entry interpolates from the
root position to the requested target, after which they become targetable.
In the live state their anchor advances by angle/speed, speed increases by
`0.04` per frame, and displayed x adds a signed
`30*sin(timer*pi/75)` wobble (`0x32` and `0x33` use opposite signs).

The common firing cycle is keyed to the root timer, beginning at root timer
`60`:

| Difficulty | Cycle | Burst length | Base speed |
| ---: | ---: | ---: | ---: |
| `0` | `80` | `24` | `5.5` |
| `1` | `60` | `32` | `6.5` |
| `2` | `50` | `36` | `7.0` |
| `3` | `50` | `36` | `6.0` |
| `4` | `50` | `40` | `7.5` |

The constructor heading uses the player aim from `(root.x,-3200)`. At a live
cycle boundary the helper instead caches aim from `(root.x,-200)`. During the
burst, every fourth frame it emits two opposite
visual `7`, behavior `0` singles while `y<700`
and player distance is greater than `30`. Difficulties `3/4` add an opposite
pair at `baseSpeed+2.0`.

On HP exhaustion, while `y<520` and player distance is greater than `80`, the
node emits an aimed visual `2`, behavior `3` death shot. Its base speeds are
`{5.0,6.0,6.5,6.5,7.5}`; difficulties `3/4` add a second shot at
`8.0/9.0`. Death then increments the phase kill counter, calls
`FUN_14007b010(child,500,1)`, performs cleanup mode `0`, optionally creates
`0x153`, and deactivates. Parent HP/countdown exhaustion removes it without
the kill payout.

Both types draw the same five-leaf body on layer `0x23`, mode `7`:

- `Enemy_s[30]` and `Enemy_s[29]` form the center body.
- Five `Enemy_s[31]` leaves share the center at `y-30` and use angle offsets
  `0`, `0x3333`, `0x6666`, `-0x6667`, and `-0x3334`.
- The leaf base angle advances by `2000` per frame.
- Entry frames append the original `Enemy_s[29]` trail effect.
- Gauge mode is `2`.

### Type `0x34`: four final-bar satellites

Root state `7`, timer `10`, stores the first allocated id in
`DAT_1407c77a0`, creates these four children, and sets root live-child count
to four:

| Child index | HP | Kind | Relative x/y | Angle | Speed | Radius |
| ---: | ---: | ---: | --- | ---: | ---: | ---: |
| `0` | `9000` | `24` | `(+250,-20)` | `0x4000` | `1.0` | `50` |
| `1` | `9000` | `24` | `(-250,-20)` | `0x4000` | `1.0` | `50` |
| `2` | `9000` | `24` | `(+120,-70)` | `0x4000` | `1.0` | `50` |
| `3` | `9000` | `24` | `(-120,-70)` | `0x4000` | `1.0` | `50` |

The first 40 frames expand the target offset sinusoidally while current
position closes one tenth of the remaining distance to `root+offset` each
frame. That one-tenth follow continues live; the hit gate clears at timer
`40`. Live attacks use
`p=(rootTimer-80)%380` and `index=entityId-DAT_1407c77a0`.

For `p<200`, each child has a staggered full-ring visual `4`, behavior `0`
window. It caches player aim at `p=index*50`, then fires every three frames:

| Difficulty | Ring count | Angle step | Base speed |
| ---: | ---: | ---: | ---: |
| `0` | `15` | `50` | `4.5` |
| `1` | `23` | `70` | `6.4` |
| `2` | `27` | `80` | `7.5` |
| `3` | `27` | `80` | `8.0` |
| `4` | `25` | `120` | `9.0` |

```text
window start = index * 50
window end   = index * 56 + burstLength     // exclusive
speed        = baseSpeed + index * 0.6
angle step   = baseStep + index * 10
spread       = 0x10000
```

`burstLength` is `{6,9,12,12,12}` by difficulty; it is distinct from the
ring-count table. At `p=200` the first segment still applies one angle step,
then the random-ring segment runs in the same call. Both segments fire only
inside the original playfield gate (`player.x/6 .. +600`, `y=0..720`).

Odd child indices negate the angle step. Difficulties `3/4` add a second
ring at `speed+1.2`.

For `p>=200`, the children emit random-angle full rings using visual `3`,
behavior `0`; all children derive the first shared angle from
`scriptRandomAngle(p)`. Difficulties `3/4` derive the second layer's angle by
applying the helper's additional xorshift/temper step to the same seed. The
exact table is:

| Difficulty | Index spacing | Base count | Base speed |
| ---: | ---: | ---: | ---: |
| `0` | `32` | `23` | `3.6` |
| `1` | `18` | `31` | `5.0` |
| `2` | `16` | `35` | `5.5` |
| `3` | `16` | `35` | `5.5` |
| `4` | `10` | `35` | `6.5` |

```text
start = 200 + index * indexSpacing
fire while start <= p < 330 and
           (p - start) % (indexSpacing * 5) == 0
count  = baseCount + index * 2
speed  = baseSpeed + index * 0.3
spread = 0x10000
```

Difficulties `3/4` add a second random-angle ring at `speed+1.0`.

Type `0x34` uses the same `Enemy_s[29..31]` five-leaf multipart drawing as
`0x32/0x33`, including the `2000`-unit leaf rotation and entry trail. Gauge
mode is `2`.

On death it increments the phase kill counter, calls
`FUN_14007b010(child,1800,5)`, performs cleanup mode `0`, creates a `0x153`
node at half the child reward value, decrements root live-child count, and
deactivates. Parent HP/countdown exhaustion removes it without that payout.

### Type `0x153`: delayed owner damage

The child-death node is not a visible, shootable reward target. It is created
at `(-100,-100)`, remains untargetable, and uses update case `0xb5`. Each
helper call subtracts `min(currentHp,maxHp/30)` from both itself and its owner
root; it deactivates when exhausted. Type `0x30` supplies its full original HP,
`0x34` supplies half, and `0x32/0x33` create it only when the shared
screen-clear/invulnerability countdown is zero.

## Root drawing

The resource handles resolve against the original divided image tables:

| Handle | Resource |
| --- | --- |
| `DAT_140e44944` | `Enemy_l[13]` |
| `DAT_140e44948` | `Enemy_l[14]` |
| `DAT_140e4494c` | `Enemy_l[15]` |
| `DAT_140e44950` | `Enemy_l[16]` |
| `DAT_140e44bc8` | `Enemy_m[62]` |
| `DAT_140e446d4..dc` | `Enemy_s[29..31]` |
| `DAT_140e44310 + frame*4` | `Boss[frame]` |

Root frame selection is:

| Root state/window | Draw |
| --- | --- |
| states `0..3` | `Enemy_l[13]` plus four `Enemy_l[15]` blades |
| state `4`, `t<130` | same Enemy_l multipart body |
| state `4`, `t>=130` | `Boss[20,21,22]`, 7-frame steps |
| state `5` | `Boss[20,21,22]`, 7-frame steps |
| state `6` | `Boss[23,24]`, 5-frame steps |
| state `7` | `Boss[20,21,22]`, 7-frame steps |
| state `8`, `t<240` | `Boss[23,24]`, 5-frame steps |

The early multipart root draws `Enemy_l[13]` at `(x,y)` on layer `0x20`,
mode `7`. Four `Enemy_l[15]` blades are centered at `(x,y-255)` on layer
`0x22`, mode `7`, with angles:

```text
globalFrame * 0x500 + { 0, 0x4000, 0x8000, 0xc000 }
```

Boss-frame draws use layer `0x1e`, mode `7`, angle zero, and scale `1.0`.
`FUN_140004140(root)` and `FUN_140002260()` run after the state drawing on
every root update, supplying the common boss ambient effects and HUD.

## Reconstruction status and remaining boundary

`stage_runtime.cpp` now routes `0x13a` before generic death and connects its
nine states, same-frame phase breaks, bars, children, projectiles, drawing,
HUD, and clear latch. It also routes `0x153` as delayed owner damage rather
than generic enemy behavior.

There are existing projectile update cases numbered `0x30..0x34`; those are
projectile behavior ids and are unrelated to these stage-entity spawn types.
They cannot substitute for `FUN_140011a80`, `FUN_1400120b0`,
`FUN_140012dc0`, or `FUN_140013c00`.

Remaining representation gaps are narrower: the state-4 phase-title helper,
parts of shared `FUN_140004140` ambient queues, and true layer ordering for
layers `0x20..0x23` are not represented by the compact two-band effect
renderer. The optional `0x32/0x33 -> 0x153` gate currently uses the represented
player invulnerability timer as a proxy for the original shared screen-clear
countdown.
