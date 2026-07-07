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
- Types `0..5` use `DAT_140e45d38 + index` graphics and draw frame group `0x41`: same file `:383` through `:400`.
- Types `6..8` use a separate movement/collision path and draw from `DAT_140e45d64`, `DAT_140e45d68`, or `DAT_140e4468c` with frame group `0x4c`: same file `:411` through `:620`.
- Type `6` collection increments a gauge/counter-like global `DAT_140e45d88` and spawns effect type `0x16`: same file `:551` through `:591`.
  - Reconstruction status: `reverse/reconstructed/project/src/stage_runtime.cpp` now has a compact `RewardItem` vector and models Stage 1 type `0x10` reward type `6` drops/collection against `PlayerState::stockProgress`/lives. The original list allocator, draw resources, sound, and effect-node `0x16` chain are still deferred rather than faked.
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

## Next targets

1. Build a `RewardItem` type table for IDs `0..8`, separating ordinary score-item tiers from special rewards.
2. Cross-reference HUD graphics around `DAT_140e46b38`, `DAT_140e46b3c`, `DAT_140e46b40`, `DAT_140e46b44`, and `DAT_140e46b50` to refine the reward/HUD globals named in `reward-hud-globals.md`.
3. Fold these list names into Ghidra rename scripts once confidence is acceptable.
