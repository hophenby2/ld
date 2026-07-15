# Stage 4 boss `0x13b` reverse-engineering notes

Status: the root state machine, four live bars, phase breaks, direct projectile
patterns, child types `0x40..0x43`, multipart drawing, HUD, and final clear are
connected to the reconstruction. The effect drivers used by the appendage dash
and state-9 move are also represented explicitly. No build or game run was
performed while making this port.

## Evidence set

- Stage handoff:
  `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/14011cdd0_stage_04_gameplay_update_candidate.c`.
- Root helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140014bf0_FUN_140014bf0.c`.
- Type `0x40` helper:
  `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140018480_FUN_140018480.c`.
- Type `0x41` helper:
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/14001ac40_FUN_14001ac40.c`.
- Types `0x42/0x43` helper:
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/14001b540_FUN_14001b540.c`.
- Effect helpers `FUN_140071cb0`, `FUN_140072560`, `FUN_140073e60`,
  `FUN_1400757a0`, and `FUN_140077cf0` were checked in the read-only Homebrew
  Ghidra project. The latter three establish the owner-linked `0x2d -> 0x31`
  pulse and `0x41` trail contracts.
- Shared phase-break, final-clear, ambient-effect, and HUD helpers:
  `FUN_1400031d0`, `FUN_140003ad0`, `FUN_140004140`, and `FUN_140002260`.
- Dispatcher ordering:
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c`.

## Handoff and constructor

The Stage 4 length-table value is frame `11700`. At that frame the original
converts every stage entity and enemy projectile into a white type-`0x0c`
16-frame disappearance effect, frees both lists, stops the stage music, and
starts `Boss2.ogg`. At `endFrame + 0x3c`, frame `11760`, it creates:

```text
type=0x13b, hp=100000, kind=0
x=360, y=120, angle=0, speed=0.3
radius=200, initially blocked, owner=0
```

The constructor initializes four remaining breaks, the shared HP/countdown
fields, and the global Boss entity id. The reconstruction keeps separate Stage
4 fields for these values; it must not reuse the Stage 1 Boss globals.

## Owner mapping

All original `0x40..0x43` constructor calls pass owner argument `0`. Their
helpers do not resolve that field. They scan the entity list for the global
Boss id in `DAT_140e44308` instead. The reconstruction deliberately stores the
root id in `parentEntityId` and `0x13b` in `parentSpawnType`; this is an explicit
replacement for the original global lookup, not evidence that the original
owner argument was nonzero.

The same rule applies to the delayed-damage `0x153` node created by a destroyed
`0x40`. Its reconstructed `parentEntityId` identifies the root whose HP must be
adjusted when the node expires.

## Phase-break preamble

The live-bar break check runs before the root state switch. HP below one or a
countdown below one calls the shared break helper, clears targetability and the
state timer, creates the break-side objects, and selects:

| Breaks before decrement | New state | New mode | Radius |
| ---: | ---: | ---: | ---: |
| `4` | `2` | `2` | `240` |
| `3` | `6` | `2` | unchanged |
| `2` | `8` | `2` | unchanged |
| `1` | `11` | `-1` | unchanged |

The new state executes at timer zero in that same helper call. The dispatcher
then increments the timer after the helper returns. Generic enemy death must
therefore never run before the `0x13b` helper.

## Root state machine

| State | Exit | Behavior |
| ---: | --- | --- |
| `0` | `t=240` | Intro trajectory at x `360`; create six `0x40` appendages at `t=180`; open the first bar at `t=240`. |
| `1` | HP/time break | Speed `0.3` steering, root fan pattern, and appendage orchestration. Reset the local attack timer at `t=3420`. |
| `2` | `t=380` | First break transition; early ambient destruction, then steering from `t>=130`; open state `3`. |
| `3` | `t=150` | Steer and create the difficulty-sized `0x41` ring at `t=10`; enter move state `4`. |
| `4` | `t=60` | Save the current point, choose a bounded random destination, and sine-ease to it; enter state `5`. |
| `5` | `t=90` | Steer for 90 frames, then repeat state `4`. |
| `6` | `t=180` | Second break transition; descend by `0.1`; open state `7`. |
| `7` | HP/time break | Create three `0x42` at `t=10`, steer, and run the root phase pattern. |
| `8` | `t=180` | Third break transition; descend by `0.1`; open state `9`. |
| `9` | `t=40` | Create owner-linked effect `0x2d` at `t=1`, ease to `(440,150)`, and enter state `10`. |
| `10` | HP/time break | Run the fixed sinusoidal path and final root patterns; create three `0x43` at `t=300`. |
| `11` | `t=480` | Final destruction/result chain; result transition at `t=420`, clear and unlink at `t=480`. |

The four bars are:

| Phase | HP | Countdown |
| ---: | ---: | ---: |
| `0` | `195000` | `4500` |
| `1` | `45000` | `1800` |
| `2` | `58000` | `1800` |
| `3` | `70000` | `2100` |

States `3/4/5` share the second bar and states `9/10` share the fourth bar.
States `3` and `9` are targetable portions of those bars, not invulnerable
pre-phase states.

## Child contracts

### Type `0x40`

Six destructible appendages use states `0..8` plus death state `-1`. Their
mount points, movement states, five projectile groups, 20-segment chain draw,
body draw, and gauge are helper-owned. A destruction awards the original
`reward(2000,8)`, creates death effects and an `0x153` node carrying the full
maximum HP, and decrements the root child counter.

The constructor kind remains `15`; the `8` passed to the reward helper is the
death-feedback lifetime source, not the reward weight. Destruction defers the
generic mode-zero feedback and emits one mode-one burst with `EnemyDown2`.
States `1/2` track their mount with the fixed `0x457` angular step. State `2`
updates its wave-offset shot heading on every frame below root timer `580`, not
only on firing frames.

While the root is still in state `1`, a destroyed appendage restores its full
HP and restarts state `0` after 200 frames. Once the root leaves state `1`, the
death chain unlinks the appendage after 80 frames instead.

### Type `0x41`

The root creates `7/9/11/11/13` nodes by difficulty. State `0` expands the
ellipse for 50 frames and enters state `1` in the same helper call. State `1`
runs the 25-wave increasing-salvo table. These nodes remain blocked and are
removed with death mode zero when the root bar ends.

### Types `0x42/0x43`

Both create three nodes, expand for 50 frames, then become targetable and copy
the root HP. Their constructor HP is the root's unchanged original `+0x20`
value (`80000` on Easy, otherwise `100000`), not the current phase maximum.
The Easy constructor initially applies its normal `0.8` scale again, then timer
50 copies the root max HP back. Damage is synchronized to the root after the
child has queued its body and gauge. This ordering preserves the dispatcher's
terminal-frame collision call.

`0x42` uses the three-part 1200-frame pattern; `0x43` uses three child-indexed
salvo offsets. Both fire from the pre-movement position and old heading.

## Effect contracts

- Type `0x05` moves by its stored heading/speed, while both scale axes and alpha
  decrease linearly to zero over the declared lifetime.
- Type `0x22` uses `FUN_140072560`: it scales linearly from zero to `3.0` over
  24 frames and fades only during the last eight frames.
- Type `0x41` resolves its owner id every frame and draws eleven staggered
  nodes on a deterministic polar spiral. For node `j`,
  `r = scaleX * (200 + 170*j)` is used as both radius and radian angle; the
  copied owner heading is not used for node placement. The owner id is stored
  in effect offset `+0x54` in the original. Ages `0,10,...,90` use the second
  `BossSE4.wav` handle, and the draw layer is `0x4e`.
- Root state `9` creates graphless driver `0x2d` with lifetime 60 and the root
  id at `+0x54`. `FUN_140073e60` creates an owner-linked `0x31` pulse every 20
  frames. `FUN_1400757a0` fades each pulse in for eight frames and shrinks its
  scale from `5.0` to zero over 40 frames.
- The same `0x2d` driver creates one additive `0x33` particle per frame,
  including age 60. Each starts 400..700 units from the owner, contracts over
  60 frames, independently selects a hundredth-step scale in `0.4..0.7`, spins
  at a creation-frame-seeded constant rate, and uses the original 16-frame
  entrance/four-frame exit alpha envelope.

## Queue and draw ordering

- Root and child helpers queue their draw state before their state-transition
  tails. `drawHelperState` and `drawHelperTimer` retain that snapshot.
- The effect list is growable. Effects appended by another effect helper are
  eligible for update later in the same frame.
- The central dispatcher increments helper timers after each helper and checks
  collision after the helper, even when an exact child cleared its active link
  flag during that call.
- `0x42/0x43` therefore retain targetability for their terminal collision call;
  they are physically unlinked on the next update.

## Handoff, presentation, and audio

The reconstruction now represents the 300-frame Boss Approach layers, their
20-frame `Alert.wav` cadence, the Stage 4 BGM fade beginning at frame 11340,
the frame-11700 handoff disappearance effects, and language-aware approach
frames (`base` for Japanese/English, `_ch1` for Simplified Chinese, `_ch2` for
Traditional Chinese). The first phase-title presentation includes the black
backdrop, 7-by-32 moving grid, `Stand[33]`, and localized
`BossApproach1[1]/[5]` nodes with their independent envelopes.

All three Stage 4 calls to `stage_intro_banner_event_candidate` are connected:

- stage opening: CSV id `130 + setupGroup`, icon `setupGroup`, frame `[50,230)`, mode 0;
- approach speaker A: CSV id `133 + setupGroup`, icon 7, frame `[11400,11560)`, mode 1;
- approach speaker B: CSV id `136 + setupGroup`, icon `setupGroup`, frame `[11540,11700)`, mode 0.

The TextBox/icon nodes use layer `0x6e`; the approach portrait uses `0x6f`;
and the two-line UTF-8 text uses `0x78`. Text appears at `start + 16`, is
removed at `end - 16`, advances one code point per frame in English and every
two frames in Japanese/Chinese, and retains the original per-glyph sine bob.
Mode 0 selects `Text.wav` with color `(64,64,128)`; mode 1 selects `Text2.wav`
with white text. The slot-4 fonts use the internal Nyashi/ChillRound face names,
size 18, thickness 9, and font type `0x12`.

The original selects `Boss2.ogg` for this boss; `Boss4.ogg` is present in the
resource table but is not the handle used by `FUN_14011cdd0`. The final death
state fades Boss2 over timers `360..480` before the result layer stops all BGM
handles. Root, child, countdown, weaken, phase-title, dash, and death sound
calls are connected at their helper-owned timers.

The frame-11400 allocation is effect-list type `0x16`, not a stage enemy. It
uses `PlayerFrame[5 + setupGroup*10]`, layer `0x6f`, lifetime 300, and the
`FUN_140070e40` eight-frame sine alpha edges. Age 300 still queues the mode-0
top-left `DrawGraph(0,0)` node at alpha zero before unlinking on the next update.

Stage 4 random spawn coordinates now use the exact frame-seeded
`DAT_140e9fd1c` temper expression. In particular, type `0x37` deliberately
derives both x and y from the same raw value; the former reconstruction-only
per-axis salt is gone. The two type-`0x3f` controllers now also own the original
`DAT_140e418cc` schedule gate, including the gated `0x35`/`0x38` windows and the
death/exit clear points. The persistent HUD likewise follows `FUN_1400c2860`:
`PlayerFrame[0]` at `(940,0)` followed by `PlayerFrame[1 + setupGroup*10]` at
`(0,0)`.
