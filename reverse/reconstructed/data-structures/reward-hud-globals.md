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
| `DAT_140e46b24` | `key_state_count_candidate` | Medium | Left HUD key-state/count value; drawn by `FUN_1400c4bb0` and incremented in the state14 gameplay loop. |
| `DAT_140e441b8` | `left_key_state_hud_enabled_candidate` | Medium | Gate that allows `FUN_1400c2860` to call the left HUD/key-state helper `FUN_1400c4bb0` when the current route/mode is valid. |

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
  - Reconstruction status: Stage 1 runtime now maps this through `PlayerState::stockProgress` for the new minimal `RewardItem` type `6` path. This is a gameplay probe mapping, not a final rename of the original HUD variable.
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

## `DAT_140e46b24` and `DAT_140e441b8` — left key-state HUD candidates

Candidate names:

- `DAT_140e46b24` → `key_state_count_candidate`.
- `DAT_140e441b8` → `left_key_state_hud_enabled_candidate`.

Evidence for `DAT_140e46b24`:

- `FUN_1400c4bb0` draws it through the HUD number helper on layer `0x73`: `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/1400c4bb0_FUN_1400c4bb0.c:227` through `:272`.
- The same draw block uses left-HUD coordinates and resources, including a status/icon area around `(280,535)` and number drawing via `FUN_1400c95e0`.
- The state14 gameplay loop increments it in a gameplay event path: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:1007`.

Evidence for `DAT_140e441b8`:

- `FUN_1400c2860` conditionally calls the left HUD helper when `DAT_140e441b8 == 1` and `DAT_140e41928 != -1`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c:1064` through `:1066`.
- The callee `FUN_1400c4bb0` is the left-side DataWindow/key-state HUD helper; it draws `DataWindow.png` at `(0,330)` and several x<340 HUD rows/icons.

Interpretation:

`DAT_140e46b24` is a count/value displayed in the left key-state HUD, and `DAT_140e441b8` gates whether that left HUD is shown. Avoid mapping this to any temporary reconstruction counters until the exact gameplay event semantics of the increment path are named.

| Address/global | Candidate | Confidence |
|---|---|---|
| `DAT_140e44590` | `g_run_score_candidate` | High |
| `DAT_1407c77a8` | `g_score_item_base_value_candidate` | Medium-high |
| `DAT_140e45d18` | `g_special_gauge_or_charge_candidate` | Medium |
| `DAT_140e45d20` | `g_special_gauge_flash_timer_candidate` | Medium |
| `DAT_140e45d88` | `g_stock_progress_candidate` | Medium |
| `DAT_140e45d34` | `g_stock_level_candidate` | Medium |
| `DAT_140e445f8` | `g_special_token_stock_candidate` | Medium |
| `DAT_140e46b24` | `g_key_state_count_candidate` | Medium |
| `DAT_140e441b8` | `g_left_key_state_hud_enabled_candidate` | Medium |

## Current reconstruction status

`reverse/reconstructed/project/src/stage_runtime.cpp` now maps the known globals into `StageRuntime::PlayerState` more directly:

| Runtime field | Original global candidate | Status |
|---|---|---|
| `player_.score` | `DAT_140e44590` | Updated through reward item collection tiers instead of direct enemy-kill scoring. |
| `player_.scoreItemBaseValue` | `DAT_1407c77a8` | Still a runtime-probe value, incremented on offensive hits; exact original update rules need more xrefs. |
| `player_.specialGauge` | `DAT_140e45d18` | Supports positive charging, `50000` ready threshold, and negative `-600..0` cooldown scaffold. |
| `player_.tokenStock` | `DAT_140e445f8` | Type `7`/`8` reward collection now updates it with cap `9`. |
| `player_.stockProgress` | `DAT_140e45d88` | Type `6`/`8` collection now feeds this progress value via a fallback threshold. |
| `player_.lives` | `DAT_140e45d34` proxy | Still a playable runtime proxy for the capped stock-level candidate, not a final life-label rename. |
| `player_.graze` | graze/near-miss counters in `FUN_1400cbd30` | Now increments from enemy-projectile near-miss, not offensive hits. |

Deferred: exact `DAT_140e45d20` flash timer, exact stock threshold table, `9999999` gauge state, right-HUD `State`/`DataWindow2` frame semantics, and final in-game names for stock/buzz/hyper-like concepts.

## HUD labels, gauge states, and stock table pass — 2026-07-07

### Right HUD label handles from `FUN_1400c2860`

A focused read of `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c` ties the previously deferred label/icon handles to concrete HUD rows. Final user-facing text still needs visual confirmation from the `State.png` / `DataWindow2.png` frames, so these remain semantic candidates rather than final “buzz” / “hyper” renames.

| Global / handle | Draw evidence | Current semantic use | Naming status |
|---|---|---|---|
| `DAT_140e46b38` | drawn after the run-score rows at `1400c2860.c:449-475`, then `DAT_1407c77a8` is rendered at y `DAT_14053ae88` | score item base value row label | candidate: `score_item_base_value_label_handle` |
| `DAT_140e46b3c` | drawn at `1400c2860.c:575-601` immediately before `DAT_140e45d18` gauge drawing | special gauge row label | candidate: `special_gauge_or_hyper_label_handle` |
| `DAT_140e46b40` | drawn at `1400c2860.c:660-687` before token/pip row | token/pip row label | candidate: `special_token_stock_label_handle` |
| `DAT_140e46b50` | repeatedly drawn inactive/active in the token loop at `1400c2860.c:691-746` | token/pip icon | candidate: `special_token_pip_icon_handle` |
| `DAT_140e46b44` | drawn after the token loop at `1400c2860.c:747-777` | lower stock/status label | candidate pending visual confirmation |

### `DAT_140e45d18` gauge state model

`DAT_140e45d18` has at least four distinct states:

| State | Evidence | Interpretation |
|---|---|---|
| normal charge `0..49999` | reward collection adds scaled amounts; HUD computes a proportional meter at `1400c2860.c:559-564` | filling special gauge |
| ready `>=50000` | player update gates action at `50000`; HUD switches to special full/ready color path at `1400c2860.c:565-573` | full/ready special gauge |
| negative cooldown `-600..0` | `140106be0_player_update_input_movement_candidate.c:979-1038` counts toward zero after spending | cooldown / recovery interval |
| forced full `9999999` | `140106be0_player_update_input_movement_candidate.c:1254` assigns this sentinel; HUD treats any `>49999` as ready/full | forced full / terminal full state candidate |

Runtime status: `stage_runtime.cpp` now preserves the `9999999` sentinel separately from the normal `50000` ready cap and renders all values above `49999` as full/ready rather than proportional overflow.

### Original stock threshold table

The raw `DAT_140538bd8` table was recovered directly from `reverse/inputs/LikeDreamer.exe` at VA `0x140538bd8` (`.rdata` file offset `0x537bd8`):

| Index (`DAT_140e419b8`) | Threshold chunk |
|---:|---:|
| `0` | `56000` |
| `1` | `70000` |
| `2` | `70000` |
| `3` | `70000` |
| `4` | `70000` |

Usage evidence:

- Reset/init: `DAT_140e45d88 = DAT_140538bd8[DAT_140e419b8] * DAT_140e474ec` in `1400f6c40_FUN_1400f6c40.c:17`.
- Replay/setup restore: `DAT_140e45d88 = threshold * param_1[5] + (threshold / 0x14) * param_1[6]`, with a `param_1[6] == 0x14` minus-one edge case in `1401105c0_FUN_1401105c0.c:129-134`.
- Progress clamp and stock-level increment: `FUN_14010e250` clamps to `3 * threshold`, computes the current band, plays `DAT_140e47278` (`DreamPower.wav`) when crossing into the next stock level, increments `DAT_140e45d34`, and spawns effect nodes type `0x17` / `0x16` (`14010e250_FUN_14010e250.c:23-154`).
- Reward item type `6` adds one threshold chunk if `DAT_140e45d34 < 3` (`1400ca7b0_FUN_1400ca7b0.c:551-558`).

## Next targets

1. Visually inspect `State.png` / `DataWindow2.png` label frames for final English/Japanese/Chinese wording before replacing candidate “special gauge/token/stock” names with final “buzz” or “hyper” terms.
2. Decode exact reward-item gauge deltas from `FUN_1400ca7b0`.
3. Inspect result-screen text and save fields to decide whether `stock_level` is best named life, shield, guard, or another game-specific term.
