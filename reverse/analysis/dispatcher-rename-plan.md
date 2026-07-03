# Dispatcher Handler Rename Plan

Status: proposed names derived from `FUN_1400f5ef0` jump-table disassembly. These are intended for Ghidra application once a usable headless/GUI Ghidra environment is available.

Evidence:

- Dispatcher: `FUN_1400f5ef0 @ 0x1400f5ef0`
- Jump table: `0x1400f6b78`
- State variable: `DAT_140e45270`
- Fallback export: `reverse/ghidra-or-ida/exports/main-dispatcher-objdump.txt`

Naming convention:

- `state_XX_*_candidate` for handlers whose broad role is known but details remain uncertain.
- Keep `candidate` suffix until the handler body is reviewed and the state label is confirmed by UI/resource/text evidence.
- Shared handlers include the lowest/most representative state in the name unless a clearer domain name exists.

## High-priority main branch renames

Apply these first; they cover title/menu, config, and the core gameplay cluster.

| Address | Proposed name | States | Why |
|---|---|---|---|
| `1400f5ef0` | `main_state_dispatcher_candidate` | all | Central per-frame dispatcher indexed by `DAT_140e45270`. |
| `1400d21e0` | `state_02_title_main_menu_candidate` | `0x02` | Contains title/main menu selection switch into gameplay/config/replay branches. |
| `1400d4610` | `state_03_stage_start_init_candidate` | `0x03` | First gameplay entry after title/stage selection. |
| `1400d5d50` | `state_04_gameplay_update_candidate` | `0x04` | Core active gameplay candidate; large handler. |
| `14010e9b0` | `state_05_gameplay_boss_or_result_candidate` | `0x05` | Gameplay-adjacent large handler; transitions back to gameplay/result states. |
| `1400bca30` | `state_14_replay_demo_gameplay_update_candidate` | `0x14`, `0x15`, `0x2a` | Shared replay/demo gameplay update path. Main loop accelerates `0x14`; demo import reaches `0x2a`. |
| `1400fcd20` | `state_2c_auto_gameplay_branch_candidate` | `0x2c` | Outer loop accelerates this state when stage flag is set. |
| `1400ffc00` | `state_0a_options_menu_candidate` | `0x0a` | Top-level options/config menu; dispatches to `0x0b..0x0d`. |
| `140100e00` | `state_0b_options_submenu_a_candidate` | `0x0b` | Config submenu reached from row 4. |
| `1401019e0` | `state_0c_config_menu_candidate` | `0x0c`, `0x19` | Reads/writes `save\\config.dat` block fields. Existing name: `config_handler_candidate`. |
| `140102ae0` | `state_0d_key_config_menu_candidate` | `0x0d`, `0x1a` | Keybinding/config submenu candidate. |

## Gallery / archive branch

| Address | Proposed name | States | Why |
|---|---|---|---|
| `1400b4c60` | `state_06_gallery_list_candidate` | `0x06` | Gallery/list branch from title menu. |
| `1400b5c70` | `state_07_gallery_detail_candidate` | `0x07` | Gallery/detail or item branch. |
| `1400b8890` | `state_08_gallery_unlock_or_achievement_candidate` | `0x08` | Gallery/achievement-like branch; needs body review. |

## Result / continue / transition cluster

| Address | Proposed name | States | Why |
|---|---|---|---|
| `140104d80` | `state_1b_stage_result_transition_panel_candidate` | `0x1b`, `0x1c`, `0x1d` | Draws/handles three stage/result transition panels. |
| `1401124b0` | `state_10_23_result_continue_candidate` | `0x10`, `0x23` | Shared result/continue handler for paired result states. |
| `140113ef0` | `state_24_result_continue_submenu_candidate` | `0x24` | Result/continue follow-up state. |
| `1400d9110` | `state_28_29_ending_result_candidate` | `0x28`, `0x29` | Ending/result branch, returns to title/result states. |
| `1400b7f10` | `state_30_gameplay_clear_fail_transition_candidate` | `0x30` | Gameplay clear/failure transition candidate. |

## Replay branch placeholders

Replay internals are deferred, but these names prevent ambiguity in dispatcher maps.

| Address | Proposed name | States | Why |
|---|---|---|---|
| `140115190` | `state_0e_replay_list_menu_candidate` | `0x0e` | Replay list/menu state. |
| `140115880` | `state_0f_replay_load_select_candidate` | `0x0f` | Existing replay load/selection handler candidate. |
| `140114580` | `state_25_replay_save_name_entry_candidate` | `0x25` | Existing replay save/name-entry handler candidate. |

## Other dispatcher entries needing review

| Address | Proposed name | States | Why |
|---|---|---|---|
| `1400ceb40` | `state_00_pre_title_init_candidate` | `0x00` | First dispatcher state; body not yet reviewed. |
| `1400f7570` | `state_01_opening_attract_candidate` | `0x01` | Opening/demo attract candidate. |
| `1400ff570` | `state_09_menu_branch_candidate` | `0x09` | Title menu branch; details unknown. |
| `1401108b0` | `state_11_menu_branch_part1_candidate` | `0x11` | State `0x11` calls this then `1401115f0`. |
| `1401115f0` | `state_11_13_menu_branch_shared_candidate` | `0x11`, `0x13` | Shared helper in states `0x11` and `0x13`. |
| `1401110b0` | `state_13_menu_branch_part1_candidate` | `0x13` | State `0x13` helper. |
| `140104200` | `state_16_17_save_select_candidate` | `0x16`, `0x17` | Save/select secondary menu candidate. |
| `140105910` | `state_18_save_select_candidate` | `0x18` | Save/select secondary menu candidate. |
| `1400c5d70` | `state_22_gameplay_result_branch_candidate` | `0x22` | Gameplay/result branch. |
| `1400c7df0` | `state_1f_gameplay_result_branch_candidate` | `0x1f` | Gameplay/result branch. |
| `1400fac60` | `state_20_gameplay_result_branch_candidate` | `0x20` | Gameplay/result branch. |
| `1401172c0` | `state_26_save_replay_adjacent_menu_candidate` | `0x26` | Save/replay-adjacent menu. |
| `140117b00` | `state_27_save_replay_adjacent_menu_candidate` | `0x27` | Save/replay-adjacent menu. |
| `1400feaa0` | `state_2d_2e_system_menu_branch_candidate` | `0x2d`, `0x2e` | System/extra menu branch. |
| `1400ff2d0` | `state_2f_system_menu_branch_candidate` | `0x2f` | System/extra menu branch. |

## Inline/default dispatcher cases

These states do not map to a simple single handler call in the jump table:

| State | Dispatcher behavior |
|---:|---|
| `0x12` | Inline block beginning at `0x1400f648b`, likely Steam/achievement notification UI. |
| `0x21` | Falls to default/no direct handler call. |
| `0x2b` | Falls to default/no direct handler call. |

## Apply order

1. Apply high-priority main branch names.
2. Export fresh decompilations for renamed gameplay cluster states `0x03`, `0x04`, `0x05`, `0x14`, `0x2c`.
3. Review the renamed bodies and remove/refine `candidate` suffix only after state semantics are confirmed.
