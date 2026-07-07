# Stage 01 Child / Reward Reconstruction Notes

Status: runtime implementation pass after exporting `FUN_140082090 @ 0x140082090`.

## Child entity type `0x11`

`FUN_140082090` is now treated as the Stage 1 child helper for spawn type `0x11`.

Evidence from the decompile:

- It searches the stage entity list for a parent whose id matches the child parent field, copies parent position/aux fields, and expires if the parent is gone.
- It has a state-0 attach/offset phase up to `0x78` frames, then switches to state 1.
- State 1 emits projectile id `7` during the early aimed window and projectile id `9` in a later arced/volley window.
- It also allocates several effect/overlay nodes through the malloc effect chain; those visuals remain deferred.

Runtime mapping in `reverse/reconstructed/project/src/stage_runtime.cpp`:

- `StageEnemy` now carries `entityId`, `parentEntityId`, `parentSpawnType`, and `childIndex` fields for child lookup.
- `spawnStage01Child()` creates Stage 1 spawn type `0x11` children from parent anchors.
- Type `0x10` creates left/right `0x11` anchors when its active state begins.
- Marker types `0x06`/`0x08` now create type `0x09` marker satellites from `FUN_140083db0` evidence, plus visible `0x11` anchor scaffolds after their `0x14`-frame entry delay.
- `updateStage01Child()` preserves the parent-following state split and expires children when the parent disappears.
- `emitStage01Projectiles()` gives type `0x11` its own Stage 1 projectile route for id `7` and id `9` instead of falling back to generic emission.

Deferred / not claimed complete:

- Exact original child allocation counts and parent-id fields for all routes/difficulties.
- Exact original relationship between marker satellites `0x09` and visible/projectile child anchors `0x11` for every route branch.
- The malloc effect-node overlay chain in `FUN_140082090`.
- Exact `DAT_14053a*` projectile speed/scale constants.

## Reward item type `6`

The runtime now has a minimal `RewardItem` subsystem sufficient for Stage 1 type `0x10` reward drops:

- `RewardItem` mirrors the known list identity from `reward-item-list.md`: type, position, angle, speed, radius/scale, age, and homing flag.
- `spawnRewardItem()` allocates into a compact vector capped by `kRewardItemCap`.
- `updateRewardItems()` moves items, enables homing after a short delay / top-of-screen collection condition, and applies collection rewards.
- Stage 1 type `0x10` emits reward type `6` both on early death and at the long-controller exit point.
- Type `6` collection maps the original `DAT_140e45d88` stock-progress effect to `PlayerState::stockProgress` and a lives/top-up probe value.

Deferred / not claimed complete:

- Original reward list allocator/list-link shape (`DAT_140e46e90` / `DAT_140e46e98`).
- Original type `6` draw resource handles, sound, and effect type `0x16` node.
- Final naming of the stock/life/guard HUD semantics.
