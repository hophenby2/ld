# Reward / HUD Global Notes

Status: first semantic pass over the gameplay reward and HUD globals touched by `reward-item-list.md`. Names are candidate-level and intentionally conservative until result-screen text/resources and in-game labels are cross-referenced.

## Summary table

| Global | Candidate name | Confidence | Current interpretation |
|---|---|---|---|
| `DAT_140e44590` | `run_score_candidate` | High | Main run score/value. Displayed as decimal digits, saved to high-score tables, incremented by reward items. |
| `DAT_1407c77a8` | `score_item_base_value_candidate` | Medium-high | Dynamic base value used by reward item collection; starts at `100` and is also tracked for max/value records. |
| `DAT_140e45d18` | `special_gauge_or_charge_candidate` | Medium | Charge/gauge that grows from reward collection, can enter negative cooldown, gates special/bomb-like player actions, and is drawn as a HUD meter. |
| `DAT_140e45d20` | `special_gauge_flash_timer_candidate` | Medium | Short timer set when the special gauge changes/levels, used for HUD flash/lockout behavior. |
| `DAT_140e45d88` | `extend_or_life_stock_progress_candidate` | Medium | Progress toward increasing `DAT_140e45d34`; clamped against difficulty/stage thresholds and incremented by special reward items. |
| `DAT_140e45d34` | `stock_level_or_life_count_candidate` | Medium | Small capped value `0..3` initialized from route/setup, incremented when `DAT_140e45d88` reaches thresholds, decremented/spent on hit/route events. |
| `DAT_140e445f8` | `special_token_stock_candidate` | Medium | Small stock/token count, capped at `9`, drawn as HUD pips and consumed by a special clear/action path. |

## `DAT_140e44590` — run score candidate

Candidate name: `run_score_candidate`.

Evidence:

- Reset to zero during gameplay context reset: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f6c40_FUN_1400f6c40.c:63`.
- Reward item types `0..5` increment it by `1x`, `5x`, or `10x` `DAT_1407c77a8`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c:232` through `:247`, `:304` through `:313`, and `:361` through `:371`.
- Main gameplay loop compares it against `DAT_140e46ae0`, writes it to per-stage/per-route records, and updates global maxima: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:515` through `:567`.
- HUD drawing renders it as digits using `DAT_140e41980` number glyphs: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c:367` through `:447`.
- Result branches read it for score/count-up display: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400fac60_state_20_gameplay_result_branch_candidate.c:571` through `:573` and `:920`.

Interpretation: this is the primary run score or score-like result value.

## `DAT_1407c77a8` — score item base value candidate

Candidate name: `score_item_base_value_candidate`.

Evidence:

- Reset to `100` during gameplay context reset: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f6c40_FUN_1400f6c40.c:64`.
- Reward items add `1x`, `5x`, or `10x` this value into `DAT_140e44590`.
- Main loop stores/compares it as a max-like companion to score: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:565` through `:567`.
- HUD renders it as a separate number row after score: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c:476` through `:557`.

Interpretation: a dynamic point/item-value multiplier or base score value. It is not itself the run score because `DAT_140e44590` accumulates multiples of it.

## `DAT_140e45d18` — special gauge / charge candidate

Candidate name: `special_gauge_or_charge_candidate`.

Evidence:

- Reset to `0` during gameplay context reset: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f6c40_FUN_1400f6c40.c:47`.
- Reward item types `0..5` add scaled amounts to it, but only if it is non-negative; the code clamps negative-to-zero after additions: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c:233` through `:251`, `:306` through `:317`, and `:364` through `:374`.
- Player update checks the `50000` threshold for special/action gating: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:317` through `:320`.
- When a special action triggers, it is set to `-600` as a cooldown/negative fill interval: same file `:1031` through `:1038`.
- While negative, it counts back up toward zero and spawns visual effects; when it reaches zero, a sound and player-side object type `0x18` fire: same file `:979` through `:1027`.
- It can also be forced to `9999999`, suggesting a full/terminal/special state rather than a simple counter: same file `:1169` through `:1254`.
- HUD drawing treats normal positive values as a meter (`value / constant`), but values above `49999` use a special color/visual path and negative values use a separate cooldown display: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c:559` through `:573`, and `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:1342` through `:1372`.

Interpretation: a special gauge/charge meter that can be spent or enter cooldown. The exact in-game label still needs UI text/resource correlation.

## `DAT_140e45d88` and `DAT_140e45d34` — stock progress and stock level candidates

Candidate names:

- `DAT_140e45d88` → `extend_or_life_stock_progress_candidate`.
- `DAT_140e45d34` → `stock_level_or_life_count_candidate`.

Evidence for `DAT_140e45d88`:

- Initialized from a difficulty/route threshold table `DAT_140538bd8` times `DAT_140e474ec`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f6c40_FUN_1400f6c40.c:16`.
- Stage 00 clamps it to `30000` in an early-stage condition: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/14012eba0_FUN_14012eba0.c:870` through `:871`.
- Reward item type `6` increments it by one difficulty threshold chunk if `DAT_140e45d34 < 3`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c:551` through `:558`.
- Reward item type `8` grants a large `+99999`: same file `:593` through `:595`.
- `FUN_14010e250` clamps it to `3 * threshold`, computes progress within the current stock band, and increments `DAT_140e45d34` when a threshold is crossed: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/14010e250_FUN_14010e250.c:21` through `:38` and `:86` through `:88`.
- Player hit/route logic subtracts one threshold chunk from it and decrements `DAT_140e45d34`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:880` through `:897`.

Interpretation:

This pair is likely a stock/life/guard progression system. `DAT_140e45d88` is the progress value; `DAT_140e45d34` is the small current level/count capped at `3`. Avoid final “life” naming until UI labels confirm whether this is life stock, shield stock, or another survivability tier.

## `DAT_140e445f8` — special token stock candidate

Candidate name: `special_token_stock_candidate`.

Evidence:

- Reset/initialized to `2` during normal gameplay context reset and state `0x15`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1400f6c40_FUN_1400f6c40.c:45`, and `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:974` through `:976`.
- Stage/replay setup can initialize it to `9`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/1401105c0_FUN_1401105c0.c:134`.
- Reward item type `7` increments it up to `9`; reward item type `8` sets it to `9`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c:500` through `:502`, and `:593` through `:596`.
- Main gameplay loop also increments it up to `9` in a pickup/bonus path: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:1094` through `:1097`.
- Player update consumes it (`--`) when a special clear/action path runs, after flushing enemy projectiles through `FUN_14006c420`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:793` through `:797`.
- HUD drawing creates a row of pips/icons and draws active versions for indices `<= DAT_140e445f8`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c:700` through `:750`.
- Stage helpers `FUN_140003ad0` / `FUN_140003e60` gate ending/special effects on `DAT_140e445f8 > 0` and `DAT_140e44590 != 0`: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140003ad0_FUN_140003ad0.c:50` through `:52`, and `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140003e60_FUN_140003e60.c:29` through `:30`.

Interpretation: a small token/stock count represented by HUD pips and consumed by a projectile clear/special action. It may be a bomb/guard/token stock, but the exact label is not confirmed.

## Rename candidates

| Address/global | Candidate | Confidence |
|---|---|---|
| `DAT_140e44590` | `g_run_score_candidate` | High |
| `DAT_1407c77a8` | `g_score_item_base_value_candidate` | Medium-high |
| `DAT_140e45d18` | `g_special_gauge_or_charge_candidate` | Medium |
| `DAT_140e45d20` | `g_special_gauge_flash_timer_candidate` | Medium |
| `DAT_140e45d88` | `g_stock_progress_candidate` | Medium |
| `DAT_140e45d34` | `g_stock_level_candidate` | Medium |
| `DAT_140e445f8` | `g_special_token_stock_candidate` | Medium |

## Next targets

1. Cross-reference HUD graphics around `DAT_140e46b38`, `DAT_140e46b3c`, `DAT_140e46b40`, `DAT_140e46b44`, and `DAT_140e46b50` to name the HUD labels/icons for score, gauge, stock, and token count.
2. Build a compact `RewardItem` type table (`0..8`) with reward deltas and source helpers now that the target globals are named.
3. Inspect result-screen text and save fields to decide whether `stock_level` is best named life, shield, guard, or another game-specific term.
