# Secondary Collectible / Reward Object List Notes

Status: first focused pass over the `DAT_140e46e90` 0x30-byte list. Names remain candidate-level, but this list is now better understood as a collectible/reward-item list rather than a visual-only transient list.

## List identity

The list rooted at `DAT_140e46e90` and tailed by `DAT_140e46e98` is allocated by `FUN_1400ca6d0 @ 0x1400ca6d0` and updated/rendered by `FUN_1400ca7b0 @ 0x1400ca7b0`.

Working name: `RewardItemNode` / `reward_item_list`.

Why this is likely a collectible/reward list:

- Nodes move onscreen, then either home toward the player or bounce/float depending type and state.
- On player proximity they set `active = 0`, play reward/collection sounds, spawn visual effects, and mutate scoring/gauge-like globals.
- `player_update_input_movement_candidate` can force eligible nodes into homing mode when the player is near the top of the playfield.
- `FUN_1400cd750` spawns types `3`/`4` at enemy projectile cancel positions, which then feed the same reward collection path.

## Allocator: `FUN_1400ca6d0`

Candidate name: `spawn_reward_item_candidate`.

Observed prototype:

```c
void spawn_reward_item_candidate(
    int item_type,
    float x,
    float y,
    FixedAngle16 angle,
    double speed,
    float radius_or_scale);
```

Field map from allocator evidence:

| Offset | Decompiled access | Field | Notes |
|---:|---|---|---|
| `+0x00` | `*node` | `active` | Main loop removes inactive nodes. |
| `+0x04` | `node[1]` | `age` | Incremented by `FUN_1400ca7b0`. |
| `+0x08` | `node[2]` | `item_type` | Update/render switch key. Observed types `0..8`. |
| `+0x0c` | `node[3]` | `x` | Current x. |
| `+0x10` | `node[4]` | `y` | Current y. |
| `+0x14` | `*(short *)(node + 5)` | `angle` | 16-bit fixed angle. |
| `+0x18` | `*(double *)(node + 6)` | `speed` | Movement speed; changed when homing. |
| `+0x20` | `node[8]` | `radius_or_scale` | Collection radius / draw scale margin. |
| `+0x24` | `node[9]` | `homing_or_collect_flag` | Initialized `0`; set to `1` by player auto-collect logic or by near-player checks. |
| `+0x28` | `*(... + 10)` | `next` | Singly-linked list next. |

Primary evidence: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca6d0_FUN_1400ca6d0.c:11` through `:36`.

## Updater / renderer: `FUN_1400ca7b0`

Candidate name: `update_reward_items_candidate`.

Call site: the main gameplay loop calls this after stage entity update and before effect/projectile updates. Evidence: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:751` through `:754`.

Behavior summary:

- Iterates `DAT_140e46e90`.
- Switches on `item_type`.
- Types `0..5` are small score/reward items that drift, can enter homing mode, and grant score/gauge on collection.
- Types `6..8` are larger/special reward items that use different graphics and grant stronger state changes.
- Draws via `FUN_1400c8410` using resource globals around `DAT_140e45d38`, `DAT_140e45d64`, `DAT_140e45d68`, and `DAT_140e4468c`.
- Deactivates nodes when collected or when they leave the extended playfield bounds.

Evidence:

- List traversal and switch: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c:62` through `:73`.
- Types `0..5` initial drift, optional homing trigger, movement, collection test, and score/gauge mutation: same file `:74` through `:382`.
- Types `0`/`3`, `1`/`4`, and `2`/`5` share reward tiers; the collected reward increments `DAT_140e44590` by `1x`, `5x`, or `10x` `DAT_1407c77a8` respectively: same file `:230` through `:247`, `:304` through `:313`, and `:361` through `:371`.
- Types `0`/`3`, `1`/`4`, and `2` use `DAT_140e45d38 + index` graphics and draw frame group `0x41`; the original switch has no type-`5` draw call: same file `:383` through `:400`.
- Types `6..8` use a separate movement/collision path and draw from `DAT_140e45d64`, `DAT_140e45d68`, or `DAT_140e4468c` with frame group `0x4c`: same file `:411` through `:620`.
- Type `6` collection increments a gauge/counter-like global `DAT_140e45d88` and spawns effect type `0x16`: same file `:551` through `:591`.
  - Reconstruction status: `reverse/reconstructed/project/src/stage_runtime.cpp` now has a compact `RewardItem` vector, models Stage 1 type `0x10` reward type `6` drops/collection against `PlayerState::stockProgress`/lives, draws `Item.png` frame `11`, and plays `Item3.wav`. The original list allocator and effect-node `0x16` chain remain deferred.
- Type `7` collection increments `DAT_140e445f8` up to `9`, spawns effect type `0x17`, and plays `DAT_140e47228`: same file `:500` through `:549`.
- Type `8` collection grants a large bonus (`DAT_140e45d88 += 99999`) and sets `DAT_140e445f8 = 9`: same file `:593` through `:596`.
- Bounds cleanup for both groups sets `active = 0`: same file `:402` through `:409` and `:621` through `:628`.

## Auto-collect / homing trigger from player update

`player_update_input_movement_candidate` scans this list when the player is near the top/threshold region and the gameplay timer is early enough. For eligible nodes with `age > 0x1f` and `item_type` outside most `6..8` special cases, it sets `node->homing_or_collect_flag = 1`.

Evidence: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:595` through `:600`.

Interpretation: this is consistent with “point of collection” / auto-collect behavior common in shooting games. Once the flag is set, the updater computes angle toward the player and raises speed.

## Spawn sources

High-signal spawn sources:

| Source | Spawned types | Interpretation |
|---|---|---|
| `FUN_14007b010` | `0`, `1`, `2` | Entity death/reward burst; amount scales with a value derived from entity fields. |
| `FUN_1400cd750` | `3`, `4` | Projectile cancel/impact reward items emitted at cancelled enemy bullet positions. |
| `player_update_input_movement_candidate` | `6` | Player death/route/clear-adjacent special item/effect near player. |
| Stage/entity helpers | `6`, `7`, sometimes `8` | Special rewards or clear tokens from specific enemy/stage events. |

Evidence examples:

- `FUN_14007b010` emits type `2`, then `1`, then `0` in decreasing reward tiers: `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/14007b010_FUN_14007b010.c:52` through `:108`.
- `FUN_1400cd750` emits type `3` or `4` at enemy projectile cancel positions: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400cd750_FUN_1400cd750.c:93` through `:96`, `:181` through `:184`, `:377` through `:378`, and `:459` through `:460`.
- `player_update_input_movement_candidate` emits type `6` around route/death/clear conditions: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c:742` through `:758`.

## Relationship to other gameplay lists

| List | Head | Tail | Count | Allocator | Updater | Current meaning |
|---|---|---|---|---|---|---|
| Enemy projectile | `DAT_140e45260` | `DAT_140e451a8` | `DAT_140e451b4` | `FUN_14006c2f0` | projectile update switch | Enemy bullets/projectiles. |
| Player-side object | `DAT_140e46ea0` | `DAT_140e9fd38` | `DAT_140e4764c` | `FUN_140109660` | `FUN_140109780` | Player shots, specials, cancel fields, and clear visuals. |
| Reward item | `DAT_140e46e90` | `DAT_140e46e98` | `DAT_140e46c5c` | `FUN_1400ca6d0` | `FUN_1400ca7b0` | Collectible score/gauge/reward items; includes bullet-cancel drops. |
| Effect node | `DAT_140e45d78` | `DAT_140e45d28` | `DAT_140e45d1c` | `FUN_140070d00` | `FUN_140070e40` | Visual/effect nodes. |

## Rename candidates

| Address | Current | Candidate | Confidence |
|---|---|---|---|
| `0x1400ca6d0` | `FUN_1400ca6d0` | `spawn_reward_item_candidate` | High |
| `0x1400ca7b0` | `FUN_1400ca7b0` | `update_reward_items_candidate` | High |

## Current reconstruction status

`reverse/reconstructed/project/src/stage_runtime.cpp` now models the reward list with a compact vector-backed `RewardItem` runtime. This remains structurally simpler than the original linked list, but the collection effects now follow the evidence table from `FUN_1400ca7b0`:

| Item type | Runtime collection effect | Evidence status |
|---:|---|---|
| `0`, `3` | `score += 1 * scoreItemBaseValue`, small special-gauge gain | Matches the `1x` score tier from `FUN_1400ca7b0`; exact gauge delta is still first-pass. |
| `1`, `4` | `score += 5 * scoreItemBaseValue`, medium special-gauge gain | Matches the `5x` score tier; exact gauge delta is still first-pass. |
| `2`, `5` | `score += 10 * scoreItemBaseValue`, larger special-gauge gain | Matches the `10x` score tier; exact gauge delta is still first-pass. |
| `6` | Adds one stock-progress threshold chunk and `10x` score proxy | Models `DAT_140e45d88` progress and exact `Item3.wav` collection audio; type `0x16` effect deferred. |
| `7` | Increments token stock up to `9` | Models `DAT_140e445f8` and exact below-cap `Extend.wav` audio; type `0x17` effect deferred. |
| `8` | Adds `99999` stock progress and sets token stock to `9` | Matches large-stock/token evidence; now draws the original magenta-tinted `Enemy_s.png` frame `11`. |

Spawn/update status:

- Enemy defeat routes through `spawnEnemyDeathRewardBurst()`. Stage 1 types
  `0x06..0x08` and `0x0a..0x11` now use each original helper's exact
  `FUN_14007b010` payout window together with the constructor's `+0x24`
  `entity_kind` value, so the type `2`, then `1`, then `0` tier counts follow
  the original integer decomposition. The compact runtime still substitutes
  deterministic item scatter for the original RNG/packed-coordinate helper.
- Stage 1 type `0x09` satellites are non-targetable and retain their separate
  parent-loss type `7` reward path; they no longer fall through the generic
  enemy-death burst.
- Stage 1 type `0x10` still emits the known type `6` stock/special reward.
- Player-side object vs enemy projectile cancellation now emits type `3/4` drops as a first-pass model of `FUN_1400cd750`.
- Original linked-list allocation, exact reward-burst RNG/scatter, remaining
  pre-homing drift/RNG and boundary geometry, score popups, and reward effect
  nodes remain deferred. Item frame selection, pulse scales, alpha/tint,
  collection sounds, auto-collect gating, and terminal-frame lifetime are
  reconstructed.

## Exact movement / frame / sound pass — 2026-07-07

The focused pass over `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400ca7b0_FUN_1400ca7b0.c` resolves several previously deferred constants.

### Type table

| Item type | Current meaning | Draw handle / source | Draw group | Collection sound | Collection effect | Effect node |
|---:|---|---|---:|---|---|---|
| `0` | score tier 1 | `DAT_140e45d38 + animated index` from `media\\player\\Item.png` | `0x41` | `DAT_140e4726c` = `media\\se\\Item1.wav` | `DAT_140e44590 += 1 * DAT_1407c77a8`; gauge delta uses stage-dependent scalar | score popup effect type `0x1b`, selector `0x42` |
| `1` | score tier 5 | same Item.png handle family | `0x41` | `DAT_140e4726c` | `DAT_140e44590 += 5 * DAT_1407c77a8`; larger gauge scalar | score popup effect type `0x1b`, selector `0x42` |
| `2` | score tier 10 | same Item.png handle family | `0x41` | `DAT_140e4726c` | `DAT_140e44590 += 10 * DAT_1407c77a8`; largest gauge scalar | score popup effect type `0x1b`, selector `0x42` |
| `3` | cancel score tier 1 | same Item.png handle family | `0x41` | `DAT_140e4726c` | same as type `0` | score popup path shared with type `0` |
| `4` | cancel score tier 5 | same Item.png handle family | `0x41` | `DAT_140e4726c` | same as type `1` | score popup path shared with type `1` |
| `5` | cancel score tier 10 | no draw branch in `FUN_1400ca7b0` | — | `DAT_140e4726c` | same as type `2` | score popup path shared with type `2` |
| `6` | stock/progress reward | `DAT_140e45d64` from `Item.png` div graph | `0x4c` | `DAT_140e47274` = `media\\se\\Item3.wav` | if `DAT_140e45d34 < 3`, `DAT_140e45d88 += DAT_140538bd8[DAT_140e419b8]` | effect node type `0x16`, handle `DAT_140e419c8[DAT_140e445c0 * 10]`, selector `0x6f`, lifetime `0x78` |
| `7` | token stock reward | `DAT_140e45d68` from `Item.png` div graph | `0x4c` | `DAT_140e47228` = `media\\se\\Extend.wav` | `DAT_140e445f8++`, capped at `9` | effect node type `0x17`, handle `DAT_140e46b7c`, selector `0x4b`, lifetime `0x78` |
| `8` | large stock/token reward | `DAT_140e4468c` from resource table, drawn tinted magenta | `0x4c` | no dedicated sound seen in this focused block | `DAT_140e45d88 += 99999`; `DAT_140e445f8 = 9` | no dedicated effect allocation seen in this focused block |

### Movement constants

- Types `0..5` use the ordinary score-item path at `1400ca7b0.c:74-410`.
  - Initial drift lasts through the age gate around `0x20`/`0x21`.
  - Homing is enabled by proximity/age checks or the player-update auto-collect flag.
  - Homing turn step is capped at `0x1000` fixed-angle units per frame (`1400ca7b0.c:141-168`).
  - Homing speed is snapped to double `12.0` (`0x4028000000000000`) rather than ramped.
- Types `6..8` use the separate special-item path at `1400ca7b0.c:411-628`.
  - They bounce/reflect inside the playfield while `age < 0x4b0` (`1400ca7b0.c:473-492`).
  - Homing uses the same `0x1000` turn cap and speed `12.0` (`1400ca7b0.c:433-460`).
  - If the stage timer/state passes the late threshold (`DAT_140e445fc > 0xb4`), homing is cleared and speed is set to `4.0` (`0x4010000000000000`).

### Runtime visual and lifetime pass — 2026-07-13

The runtime now loads `media\\player\\Item.png` with the original
`(15, 15, 1, 100, 100)` division and follows the draw branches at
`1400ca7b0.c:81-94`, `:383-410`, and `:600-619`:

- Types `0`/`3`, `1`/`4`, and `2` use base scales `0.75`, `1.0`, and `1.5`.
  The shared pulse is `1 + 0.2 * sin(2*pi*age/33)`.
- Normal Heart style uses `Item.png` frame `0`; Like Style uses frame `13`.
  Normal alpha is `160`, Visibility mode changes it to `128`, and Like Style
  overrides it with `200`.
- The original function has no type-`5` draw branch. Type `5` remains
  collectible through the type-`2` payout path but is intentionally not drawn.
- Types `6` and `7` use `Item.png` frames `11` and `12`; type `8` uses
  `Enemy_s.png` frame `11` tinted `(255, 32, 255)`. Their shared pulse is
  `1 + 0.1 * sin(pi*age/32)` and their draw alpha remains `255`.
- Types `0..5` play `Item1.wav` at the original `12 * SE-volume` multiplier;
  type `6` plays `Item3.wav` and type `7` plays `Extend.wav` (only while token
  stock is below `9`) at the original `25 * SE-volume` multiplier. Type `8` has
  no sound in this function.

The vector runtime now also preserves the linked-list frame semantics:

- Inactive nodes are unlinked at the beginning of the next gameplay update,
  not immediately after the reward update. Collection and bounds exit therefore
  retain their terminal draw frame.
- `age` is incremented at the end of each node update. A cached `drawAge` keeps
  the separated renderer on the pre-increment age used by the original function,
  including age-zero nodes spawned after the reward update.
- Collection and special-item proximity homing require
  `playerStateTimer < 0xb5`. Homing is released at `playerStateTimer > 0xb4`,
  rather than by item age.
- The player-update auto-collect scan runs at `player.y <= 300` and
  `playerStateTimer < 0xb4`; after age `0x1f` it flags only types `0..5` and `8`,
  matching the unsigned type test in `player_update_input_movement_candidate`.

Runtime status: `reverse/reconstructed/project/src/stage_runtime.cpp` now models
the recovered movement thresholds, visual table, collection audio, and
terminal-frame lifetime for `RewardItem`; exact score-popup/effect-node visual
allocation is still documented rather than fully rendered.

## Next targets

1. Decode exact reward-item gauge deltas from the floating constants around `DAT_140539f40`, `DAT_140539e60`, `DAT_14053a1e8`, `DAT_14053a380`, and `DAT_14053a460`.
2. Cross-reference HUD graphics around `DAT_140e46b38`, `DAT_140e46b3c`, `DAT_140e46b40`, `DAT_140e46b44`, and `DAT_140e46b50` to refine the reward/HUD globals named in `reward-hud-globals.md`.
3. Fold these list names into Ghidra rename scripts once confidence is acceptable.
