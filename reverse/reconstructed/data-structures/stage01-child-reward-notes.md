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
- `updateRewardItems()` now incorporates the recovered `FUN_1400ca7b0` movement constants for type `6`: special-item bounce/float path, homing turn cap `0x1000`, homing speed snap `12.0`, and late non-homing speed `4.0`.
- Stage 1 type `0x10` emits reward type `6` both on early death and at the long-controller exit point.
- Type `6` collection maps the original `DAT_140e45d88` stock-progress effect to `PlayerState::stockProgress` using the recovered `DAT_140538bd8` threshold table (`{56000, 70000, 70000, 70000, 70000}`).

Recovered exact type `6` collection evidence from `1400ca7b0_FUN_1400ca7b0.c:551-591`:

- If `DAT_140e45d34 < 3`, add one threshold chunk: `DAT_140e45d88 += DAT_140538bd8[DAT_140e419b8]`.
- Play `DAT_140e47274`, mapped in the audio table to `media\\se\\Item3.wav`.
- Spawn effect node type `0x16` with handle `DAT_140e419c8[DAT_140e445c0 * 10]`, selector `0x6f`, scale `1.0`, lifetime `0x78`, and full RGB/alpha values.

Deferred / not claimed complete:

- Original linked-list allocation shape (`DAT_140e46e90` / `DAT_140e46e98`) remains represented by the runtime vector.
- The type `0x16` effect is documented and can be exposed as a debug event, but the runtime does not yet recreate the full original effect-node renderer.
- Final naming of the stock/life/guard HUD semantics awaits visual label confirmation.
