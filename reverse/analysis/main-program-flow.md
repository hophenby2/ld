# Main Program Flow Notes

Status: partial reconstruction from Ghidra exports. Focus is the main game branch; replay internals are intentionally deferred except where they explain scene transitions.

## Startup and outer loop

Primary evidence: `game_startup_init_candidate @ 0x1400f4f70`.

High-level flow:

1. Initialize Steam callbacks and Steam API.
2. Load or initialize `save\\save.dat` (`0x2730` bytes at `DAT_140e41b10`).
3. Load or initialize `save\\config.dat` (`0x1c` bytes at `DAT_140e468f0`).
4. Configure DxLib/window/audio from config.
5. Set DXArchive key string `VanillaFever11` via `dxarchive_set_key_candidate`.
6. Load base resources through `load_primary_resources_candidate` and secondary localized resources when needed.
7. Enter the per-frame loop.

Per-frame loop evidence in `game_startup_init_candidate`:

```text
FUN_140156d60(back_buffer_or_screen)
FUN_1400f5ef0()              // central per-frame game update/render dispatcher
FUN_140156d60(0xfffffffe)
...
thunk_FUN_140153110()        // likely screen flip / present
SteamAPI_RunCallbacks()
```

`FUN_1400f5ef0` could not be exported through headless Ghidra in this environment because the available Ghidra checkout reports `Cannot launch from repo because Ghidra has not been compiled with Eclipse or Gradle.` As a fallback, the function was disassembled with `objdump` into `reverse/ghidra-or-ida/exports/main-dispatcher-objdump.txt`. The disassembly still exposes a clear jump table at `0x1400f6b78`, indexed by `DAT_140e45270`, with valid state ids `0x00..0x30`.

The loop also has a fast-forward style repeat for two states:

- `DAT_140e41b00 == 1 && DAT_140e45270 == 0x14`
- `DAT_140e45270 == 0x2c && (&DAT_140e441c0)[DAT_140e445c0] == 1`

In those cases it may run the update up to 6 times in one display frame unless configured input keys are pressed.

## Core globals

| Global | Current interpretation | Evidence |
|---|---|---|
| `DAT_140e45270` | Main scene/state id | Compared/assigned across most anchor handlers; drives major transitions. |
| `DAT_140e45274` | Scene-local cursor/substate/menu selection | Used as menu row/index in title/config/stage-select handlers. |
| `DAT_140e418c8` | Scene frame counter / transition timer | Reset to `0` on state changes; incremented each frame by handlers. |
| `DAT_140e45fac` | Transition phase/timer | Positive/negative values drive fade/confirm/cancel transitions. |
| `DAT_140e46014` | Redraw/selection-dirty flag | Set when menu selection changes; cleared by handlers after update. |
| `DAT_140e467b8..e4` | Input edge/held state globals | Used for up/down/left/right/confirm/cancel style navigation. |
| `DAT_140e467fc` | Input consumed flag | Prevents multiple menu actions in one frame. |
| `DAT_140e41b00` | Replay/demo mode flag | Set before replay/demo playback paths; affects per-frame fast-forward and gameplay update. |

## Central dispatcher jump table

Evidence: `reverse/ghidra-or-ida/exports/main-dispatcher-objdump.txt`, function `FUN_1400f5ef0 @ 0x1400f5ef0`.

Important dispatcher skeleton:

```text
movslq DAT_140e45270, %rax
cmp    $0x30, %eax
ja     default
mov    jump_table[rax], %ecx   ; table base 0x1400f6b78
add    image_base, %rcx
jmp    *%rcx
```

Confirmed state-to-handler table:

| State | Handler address | Current handler name / interpretation |
|---:|---|---|
| `0x00` | `0x1400ceb40` | unknown pre-title/init handler candidate |
| `0x01` | `0x1400f7570` | opening/demo attract loop candidate |
| `0x02` | `0x1400d21e0` | title/main menu handler candidate |
| `0x03` | `0x1400d4610` | stage/gameplay initialization candidate |
| `0x04` | `0x1400d5d50` | active gameplay candidate A |
| `0x05` | `0x14010e9b0` | active gameplay / boss / result-adjacent candidate B |
| `0x06` | `0x1400b4c60` | gallery/list handler candidate A |
| `0x07` | `0x1400b5c70` | gallery/detail handler candidate B |
| `0x08` | `0x1400b8890` | gallery/detail or achievement handler candidate C |
| `0x09` | `0x1400ff570` | menu branch candidate |
| `0x0a` | `0x1400ffc00` | top-level options/config handler candidate |
| `0x0b` | `0x140100e00` | config submenu handler candidate A |
| `0x0c` | `0x1401019e0` | config handler candidate, already renamed |
| `0x0d` | `0x140102ae0` | config/keybinding submenu candidate |
| `0x0e` | `0x140115190` | replay list/menu handler candidate |
| `0x0f` | `0x140115880` | replay load/selection handler candidate |
| `0x10` | `0x1401124b0` | result/continue handler candidate A |
| `0x11` | `0x1401108b0` then `0x1401115f0` | two-step menu branch handler candidate |
| `0x12` | inline block at `0x1400f648b` | Steam/achievement notification UI block candidate |
| `0x13` | `0x1401110b0`, `0x1401115f0`, then extra helpers | post-achievement/menu utility branch candidate |
| `0x14` | `0x1400bca30` | replay/demo gameplay update candidate |
| `0x15` | `0x1400bca30` | same as `0x14` |
| `0x16` | `0x140104200` | save/select menu candidate A |
| `0x17` | `0x140104200` | same as `0x16` |
| `0x18` | `0x140105910` | save/select menu candidate B |
| `0x19` | `0x1401019e0` | config transition handled by config handler |
| `0x1a` | `0x140102ae0` | keybinding/config transition handled by config-key handler |
| `0x1b` | `0x140104d80` | stage/result transition panel handler |
| `0x1c` | `0x140104d80` | same as `0x1b` |
| `0x1d` | `0x140104d80` | same as `0x1b` |
| `0x1e` | `0x1400bca30` with extra transition draw | gameplay-like state with transition overlay |
| `0x1f` | `0x1400c7df0` | gameplay/result branch candidate |
| `0x20` | `0x1400fac60` | gameplay/result branch candidate |
| `0x21` | default/no handler | no dispatch call observed |
| `0x22` | `0x1400c5d70` | gameplay/result branch candidate |
| `0x23` | `0x1401124b0` | result/continue handler candidate A |
| `0x24` | `0x140113ef0` | result/continue handler candidate B |
| `0x25` | `0x140114580` | replay save/name-entry handler candidate |
| `0x26` | `0x1401172c0` | save/select or replay-adjacent menu candidate |
| `0x27` | `0x140117b00` | save/select or replay-adjacent menu candidate |
| `0x28` | `0x1400d9110` | ending/result branch candidate |
| `0x29` | `0x1400d9110` | same as `0x28` |
| `0x2a` | `0x1400bca30` | demo text playback update candidate |
| `0x2b` | default/no handler | no dispatch call observed |
| `0x2c` | `0x1400fcd20` | accelerated gameplay-like branch candidate |
| `0x2d` | `0x1400feaa0` | extra/system menu branch candidate |
| `0x2e` | `0x1400feaa0` | same as `0x2d` |
| `0x2f` | `0x1400ff2d0` | extra/system menu branch candidate |
| `0x30` | `0x1400b7f10` | gameplay clear/failure transition candidate |

This table supersedes the earlier broad state guesses where it gives a concrete handler address.

## Major state values seen so far

These names are provisional and should be refined as each handler is renamed.

| State | Provisional meaning | Evidence |
|---:|---|---|
| `0x01` | Opening/demo attract loop candidate | `FUN_1400d21e0` returns here after long attract/demo timing. |
| `0x02` | Title/main menu | Many menu exits return to `2`; `FUN_1400d21e0` main menu switch transitions out from this area. |
| `0x03` | Start gameplay / stage initialization | `FUN_1400d21e0` sets this from story/stage start selection; several result paths return to `3`. |
| `0x04` | Gameplay active candidate | Stage selection and replay-return paths transition to `4`; needs deeper gameplay handler mapping. |
| `0x05` | Alternate gameplay entry / boss or stage transition candidate | Often paired with state `4` in stage-select/result branches. |
| `0x06` | Gallery/achievement/list branch candidate | Main menu option and gallery handler transition through `6`. |
| `0x07` | Gallery detail/list substate candidate | `FUN_1400b4c60` enters `7` from grouped selection. |
| `0x08` | Gallery/list back or alternate detail candidate | `FUN_1400b4c60` enters `8` when navigating backward from group start. |
| `0x09` | Main menu option branch | Selected from main menu case 6. |
| `0x0a` | Option/config top-level | Multiple cancel paths from config return to `0x0a`. |
| `0x0b` | Config submenu 1 | `FUN_1400ffc00` transitions from config row 4. |
| `0x0c` | Config submenu handled by `config_handler_candidate` | Direct comparisons in `config_handler_candidate`. |
| `0x0d` | Config/keybinding submenu candidate | `FUN_1400ffc00` transitions from config row 6; `FUN_140102ae0` handles `0x0d`. |
| `0x0e` | Replay list/menu | Main menu case 3 sets state `0x0e` and calls replay slot scan. |
| `0x10` | Stage result / retry branch candidate | Result handler `FUN_1401124b0` compares with `0x10`. |
| `0x11` | Menu option branch from main menu case 4 | `FUN_1400d21e0` sets `0x11`; exact UI still unknown. |
| `0x14` | Replay/demo playback update | Main loop special-cases replay mode with `DAT_140e41b00 == 1`. |
| `0x16`, `0x17`, `0x18`, `0x19`, `0x1a` | Save/select/config-related secondary menu states | Seen in `FUN_140105910`, `config_handler_candidate`, and `FUN_140102ae0`. |
| `0x1b`, `0x1c`, `0x1d` | Stage/result transition panels | `FUN_140104d80` draws/handles all three and moves to stage/gameplay states. |
| `0x20`, `0x22`, `0x23`, `0x24`, `0x27` | In-game/result/continue transition cluster | Appears in stage/gameplay result handlers; `0x23` and `0x10` are paired in `FUN_1401124b0`. |
| `0x28`, `0x29` | Ending/result branch candidate | `FUN_1400d9110` handles both and returns to `1` or `0x23`. |
| `0x2a` | Demo text playback import state | `FUN_1400d21e0` sets it while loading `media\\demo\\LD_demo%02d.txt`. |
| `0x2c` | Auto/fast gameplay branch candidate | Main loop can update this state up to 6 times/frame for enabled stages. |
| `0x30` | Gameplay clear/failure transition candidate | `FUN_1400b5c70` sets this before returning to gallery/title-ish paths. |

## Main menu transition evidence

`FUN_1400d21e0` contains a clear selection switch around lines 573-618 in the exported decompilation:

| Menu selection (`DAT_140e45274`) | Transition |
|---:|---|
| `0`, `1`, `2` | Start gameplay path: set `DAT_140e41928`, `DAT_140e445c0`, then `DAT_140e45270 = 3`. |
| `3` | Replay menu: `DAT_140e45270 = 0x0e`, reset replay slot index, call `replay_handler_candidate_B`. |
| `4` | Branch to `0x11`. |
| `5` | Branch to `0x06`. |
| `6` | Branch to `0x09`. |
| `7` | Branch to `0x0a`. |
| `8` | Back/exit behavior; returns selection to 7 or title depending transition. |

This is the best current anchor for naming the title/main menu handler.

## Config branch evidence

`FUN_1400ffc00` appears to be the top-level options/config menu:

- Selection `4` -> `DAT_140e45270 = 0x0b`.
- Selection `5` -> `DAT_140e45270 = 0x0c`.
- Selection `6` -> `DAT_140e45270 = 0x0d`.
- Selection `7` calls `FUN_1400f7150()` and returns to title/menu (`state 2`).
- Selection `8` also returns to title/menu with `DAT_140e45274 = 7`.
- It writes `save\\save.dat` after transition, so menu actions persist progress/settings.

`config_handler_candidate @ 0x1401019e0` handles state `0x0c` and related transition state `0x19`, updating the 28-byte config block.

## Gameplay/stage branch evidence

The dispatcher handlers have now been renamed and exported with Homebrew Ghidra. Detailed pseudocode is in `reconstructed/pseudocode/main_gameplay_flow.md`. Current interpretation:

- State `3` is a pre-run/stage-start setup menu. It commits into state `4` for normal route modes or state `5` for alternate/boss-like mode, and cancels back to title state `2`.
- State `4` is a normal route stage-selection / pre-gameplay start overlay. It persists selected stage/player options, then calls `FUN_1400f7150()` on confirm; that helper enters state `0x14` or `0x15` after initializing gameplay context. Cancel returns to state `3`.
- State `5` is a 10-row alternate/boss/options setup state. Row `8` confirms through `FUN_1400f7150()`; row `9` or negative transition returns to state `3`.
- State `0x14`/`0x15`/`0x2a` is the clearest gameplay-loop handler in this set: it records or replays packed input, runs per-stage gameplay updates, handles demo completion, and transitions to replay/save follow-up states.
- State `0x2c` is an accelerated auto/ending/unlock branch gated by `(&DAT_140e441c0)[DAT_140e445c0]`; it routes to `0x2d`, `0x23`, or `0x10` after its fade-out.

## Near-term main-branch targets

1. Review high-value update helpers in `reconstructed/data-structures/stage-spawn-used-update-map.md` order and attach semantic labels to helper groups before renaming numeric spawn types globally.
2. Cross-reference stage resource/text IDs to replace generic `stage_XX` names with real stage/theme names when evidence is strong.
3. Export/decompile the currently missing dispatcher-adjacent handlers named only by address in the jump table.
4. Treat replay format work as deferred unless it blocks understanding main flow.
