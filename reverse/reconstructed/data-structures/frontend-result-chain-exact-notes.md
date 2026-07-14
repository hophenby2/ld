# Frontend result-state chain exact notes

Status: control flow, input gates, transition timing, and directly referenced
resource frames are recovered. The reconstructed runtime ports states 0x10,
0x20, 0x22, 0x23, and 0x24. Steam transport and replay payload recording
remain explicit boundaries.

## Primary evidence

- Main dispatcher:
  reverse/ghidra-or-ida/exports/gameplay-helpers/neighborhood-decompiled/1400f5ef0_main_state_dispatcher_candidate.c
- Clear router:
  reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c6e10_FUN_1400c6e10.c
- Shared states 0x10/0x23:
  reverse/ghidra-or-ida/exports/gameplay-helpers/neighborhood-decompiled/1401124b0_state_10_23_result_continue_candidate.c
- Result summary 0x20:
  reverse/ghidra-or-ida/exports/gameplay-helpers/neighborhood-decompiled/1400fac60_state_20_gameplay_result_branch_candidate.c
- Trial continuation 0x22:
  reverse/ghidra-or-ida/exports/gameplay-helpers/neighborhood-decompiled/1400c5d70_state_22_gameplay_result_branch_candidate.c
- Replay slot selection 0x24:
  reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140113ef0_state_24_result_continue_submenu_candidate.c
- Ranking predicate:
  reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140135330_result_route_predicate_candidate.c
- Trial/map-id conversion:
  reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400d5d50_state_04_gameplay_update_candidate.c
  and
  reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f7150_gameplay_context_init_candidate.c

The extracted sheets used to validate frame identities are:

- re/player/StageClear.png: five 1280x720 frames.
- re/player/Result.png: twenty 240x60 frames.
- re/player/PauseMenu*.png: thirty localized 480x80 frames.
- re/system/Num_l.png: fourteen 48x72 frames.

## Clear routing

FUN_1400c6e10 distinguishes the three top-level play modes:

| Mode | Original route |
| --- | --- |
| normal (0) | update clear/unlock records, then enter result summary 0x20 |
| Trial (1) | early nonterminal stages may enter 0x22; terminal results enter 0x20 |
| Practice (2) | enter replay prompt 0x23; choosing no-save eventually restores state 0x05 |

Practice therefore does not jump straight to setup in the original. Its final
destination is still Alternate Setup with cursor 8; the 0x23 prompt occurs
between gameplay and that destination.

## Frontend map ids versus gameplay stages

`DAT_1407c7798` has two meanings across the state `0x04` launch boundary. In
state `0x04` it is the selected world-map node. At launch, Trial stores
`DAT_140e41abc = DAT_1407c7798 - 11`; `FUN_1400f7150` then replaces the active
gameplay stage:

| Route | Frontend selection | Stored submode | Initial gameplay stage |
| --- | ---: | ---: | ---: |
| normal | `1..9` | n/a | unchanged (`1..9`) |
| Trial special | `10` | `-1` | `10`, difficulty forced to `2` |
| Trial | `11` | `0` | `1` |
| Trial | `12` | `1` | `1`, initialized near the stage end |
| Trial | `13` | `2` | `1` |
| Trial | `14` | `3` | `1` |
| Practice | descriptor stage `1..10` | n/a | copied directly by `FUN_1401105c0` |

The ordinary Trial score/Help record index is `submode + 11`, so it is exactly
the original frontend node id `11..14`, not the active gameplay stage. State
`0x23` later restores the saved frontend node (`DAT_140e41b5c`) rather than the
terminal gameplay stage. Evidence:
`1400d5d50_state_04_gameplay_update_candidate.c:1876-1884`,
`1400f7150_gameplay_context_init_candidate.c:76-93`, and
`1401124b0_state_10_23_result_continue_candidate.c:533-542`.

## State 0x20: result summary

- On state frame 1, the original clears stale draw state and starts the
  Stage Clear BGM.
- The full-screen StageClear[0] background fades in for the first 60 frames.
- StageClear[2] (YOU WIN!) starts entering at frame 140.
- Result rows begin entering at frame 170.
- The visible score counts as
  (final_score / 150) * (state_frame - 170) until frame 320.
- Confirm is accepted only after frame 359.
- Confirm starts a positive transition. The tile wipe starts after transition
  frame 40; the state commits at transition frame 80.
- The normal route proceeds to 0x23. The recovered predicate may insert
  ranking-submit state 0x10 for qualifying Trial terminal results.

### Exact ranking-submit predicate

`FUN_140135330` is not a stage-8/stage-9 test. It first clears the submission
error flag, then returns true only when all of these conditions hold:

1. route mode is Trial (`DAT_140e41928 == 1`);
2. the clear router set `DAT_140e4680c` to a nonzero terminal value;
3. the effective Help level for the result record is zero.

For ordinary Trial, the record is `submode + 11` and uses the common
`FUN_140135290` folding. Auto progress maps `<3` to Help level zero, `3..5` to
one, `6..7` to two, `8..9` to three, `10..11` to four, and `>=12` to five.
Explicit Help `1..5` blocks submission; Off (`6`) permits it. Record index `14`
is the common helper's unconditional level-zero override.

Gameplay stage `10` instead reads
`save.dat + 0x181c + (setupGroup * 50 + 2) * 4`: its gameplay initializer
forces difficulty `2`. It applies the same Auto/explicit folding without the
record-14 override. The clear router writes the terminal flag as follows:

| Active gameplay stage | `DAT_140e4680c` |
| ---: | ---: |
| `8` with `DAT_140e44e68 == 0` | `1` |
| `9` | `2` |
| `10` | `1` |

Therefore normal and Practice results never enter state `0x10`, and a Trial
terminal played with an effective Help level above zero also proceeds directly
to `0x23`. Evidence: `140135330_result_route_predicate_candidate.c:11-60` and
`1400c6e10_FUN_1400c6e10.c:499-508` (plus `:70-95` for stage `10`).

`FrontendRuntime::shouldPromptResultSubmit()` now preserves these live-run
gates, including the separate stage-10 offset and record-14 override. The
previous `routeMode_ == 1 && (selectedStage_ == 8 || selectedStage_ == 9)`
approximation is removed.

Direct Result.png identities used by this state:

| Frame | Text |
| ---: | --- |
| 0 | Score |
| 1 | Stage |
| 2 | Trial |
| 3 | Trial+ |
| 4..8 | Casual, Maniac, Expert, Nightmare, Chaos |
| 9 | Extra |
| 11 | CounterMode |
| 12 | New Record! |
| 13 | Select(Z) & Next |
| 19 | Time |

## States 0x10 and 0x23

Both states use the same function and two-row cursor logic:

- Input begins after state frame 31.
- Up/down wrap over two rows.
- Confirm starts a positive transition.
- Cancel selects row 1 and starts the same positive transition.
- The tile wipe begins after transition frame 20; commit is at frame 60.

State 0x10 uses PauseMenu[25] for the online-ranking question and
PauseMenu[23]/[24] for Yes/No. Both choices proceed to 0x23; row 0
additionally calls the Steam ranking path in the original.

State 0x23 uses PauseMenu[7] for the replay-save question and
PauseMenu[8]/[9] for Save replay/Don't save. Row 0 scans the 24 replay
slots and enters 0x24. Row 1 restores Stage Select, or Alternate Setup
cursor 8 for Practice.

## State 0x22: Trial continuation

This is not a generic result menu. Its decoded selector can map all of the
following stage pairs, but the live clear router enters `0x22` only for Trial
submode `0` after active stages `1..5`:

| Cleared stage | Selectable next stages |
| ---: | --- |
| 1 | 2..3 |
| 2..3 | 4..5 |
| 4..5 | 6..7 |
| 6..7 | 8 |
| 8 | 9 |

Input begins after frame 59. The first confirm advances to the confirmation
phase; cancel returns to selection. The second confirm starts the tile wipe at
frame 60 and launches gameplay at transition frame 100.

## State 0x24: replay slot selection

- The cursor wraps across slots 0..23.
- Input begins after frame 31.
- Confirm begins the 0x25 name-entry/save path at positive transition frame
  16.
- Cancel uses the reverse tile wipe and restores Stage Select or Practice
  setup at transition frame -40.

The reconstruction scans and displays the existing 24 replay headers and
ports the exact cursor/cancel behavior. Confirm is intentionally rejected
until StageRuntime records the original input stream and can supply the
payload expected by 0x25; emitting a header-only replay would create an
invalid file.

## Remaining result-chain work

- Port state 0x25 name entry and states 0x26/0x27 only after a complete replay
  input stream is available.
- Connect the local Steam stub to the row-0 action in state 0x10 if a
  leaderboard transport is implemented.
- Port the achievement/unlock detours 0x2c/0x2d/0x2f that state 0x20 may
  select before 0x10/0x23.
- Feed all original result counters and record comparisons into 0x20;
  current runtime data exposes score and elapsed frames but not every original
  per-run statistic.
- Split the Trial frontend node (`10..14`) from the active gameplay stage and
  preserve the original cross-stage Trial context. StageRuntime currently
  accepts only reconstructed stages `1..4`, so the full node-to-submode launch,
  automatic continuation, and stage-8/stage-9 terminal choice are not yet
  representable. `resultRouteCompletion_` consequently covers the original
  default terminal values but not custom end-stage overrides or a future
  `DAT_140e44e68` continuation signal.
