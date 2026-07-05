# Player-Side Object List Notes

Status: first focused pass over the `DAT_140e46ea0` list that participates in projectile cancellation and player-side visuals. Names are still candidate-level because the list is mixed: it contains normal player shots, shot/bomb/cancel visuals, and some stage/enemy-triggered clear effects.

## List identity

The list rooted at `DAT_140e46ea0` and tailed by `DAT_140e9fd38` is allocated by `FUN_140109660 @ 0x140109660` and updated/rendered by `FUN_140109780 @ 0x140109780`.

Working name: `PlayerSideObject` / `player_side_object_list`.

It is not just “player bullets”:

- Player input/movement logic spawns types `0x0b`, `0x0e`, `0x0f`, `0x11`, `0x12`, `0x15`, `0x16`, and `0x18` from `player_update_input_movement_candidate`.
- The player-side object update function itself chains sub-objects: e.g. type `0x0b` spawns type `0x1a` and repeated type `0x0c`; type `0x13` spawns type `0x14` children.
- Stage/entity helpers also spawn types `0x18` and `0x19` at enemy/entity positions, likely explosion/clear/cancel visuals.
- `FUN_1400cd750` uses only selected object types from this same list as collision/cancel fields against enemy projectiles.

## Allocator: `FUN_140109660`

Candidate name: `spawn_player_side_object_candidate`.

Observed prototype:

```c
void spawn_player_side_object_candidate(
    int object_type,
    float x,
    float y,
    double speed_or_scale,
    FixedAngle16 angle,
    int radius_or_lifetime,
    float aux_radius_or_scale);
```

Field map from the allocator:

| Offset | Decompiled access | Field | Notes |
|---:|---|---|---|
| `+0x00` | `*node` | `active` | Main loop removes inactive nodes. |
| `+0x04` | `node[1]` | `age` | Incremented by `FUN_140109780`. |
| `+0x08` | `node[2]` | `object_type` | Update/render switch key. |
| `+0x0c` | `node[3]` | `x` | Current x; also collision-test center in `FUN_1400cd750`. |
| `+0x10` | `node[4]` | `y` | Current y; also collision-test center in `FUN_1400cd750`. |
| `+0x14` | `node[5]` | `prev_or_origin_x` | Mirrored initial x. |
| `+0x18` | `node[6]` | `prev_or_origin_y` | Mirrored initial y. |
| `+0x1c` | `*(short *)(node + 7)` | `angle` | 16-bit fixed angle; many render paths use it. |
| `+0x20` | `*(double *)(node + 8)` | `speed_or_scale` | Movement speed/scale; used for types `0..0xa`, `0xc`, etc. |
| `+0x28` | `node[10]` | `alpha_or_lifetime` | Often alpha/lifetime-like; allocator multiplies it by 100 when `DAT_140e9fd20 == 1`. |
| `+0x2c` | `node[11]` | `collision_radius_or_scale` | Radius/scale used by collision and several expanding render paths. |
| `+0x30` | `node[12]` | `aux_radius_or_scale` | Mirrored final argument; type `0x14/0x15/0x16` use it as a target radius/scale. |
| `+0x34` | `node[13]` | `field_34` | Initialized zero. |
| `+0x38` | `*(... + 0xe)` | `next` | Singly-linked list next. |

Primary evidence: `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140109660_FUN_140109660.c:11` through `:42`.

## Update/render dispatcher: `FUN_140109780`

Candidate name: `update_player_side_objects_candidate`.

Call site: `state_14_replay_demo_gameplay_update_candidate` calls this before stage entity update and before enemy projectile update/collision. Evidence: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:748` through `:754`.

Behavior summary:

- Iterates `DAT_140e46ea0`.
- Switches on `object_type`.
- Updates position, radius/scale/alpha, draws through `FUN_1400c8410`, sometimes spawns visual effects through `FUN_140070d00`, sometimes spawns more `PlayerSideObject` nodes through `FUN_140109660`.
- Increments `age` each frame and sets `active = 0` on expiry.

Evidence:

- List traversal and switch on `node[2]`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/140109780_FUN_140109780.c:107` through `:124`.
- Types `0..0x0a` move by angle/speed and draw player-shot sprites from `DAT_140e44e70` frame groups: same file `:125` through `:275`.
- Bounds cleanup for moving player-shot-like objects uses `node[0xb]` as a radius/margin: same file `:367` through `:373`.
- Type `0x0b` is a larger player special/bomb-like parent that spawns one type `0x1a` and four type `0x0c` children at timed frames: same file `:375` through `:447`.
- Type `0x0c` is a bouncing/reflecting child that moves, reflects against bounds for ~20 frames, then expires with type `0x0d` effect and sound: same file `:448` through `:563`.
- Types `0x0e`/`0x0f` are larger special variants; `0x0f` repeatedly spawns type `0x10` children: same file `:596` through `:840`.
- Type `0x13` is a timed generator that spawns multiple type `0x14` children every five frames: same file `:1046` through `:1072`.
- Types `0x17`/`0x18`, `0x19`, and `0x1a` are expanding visual/cancel rings that draw with `DAT_140e45060` / `DAT_140e41a54`: same file `:1329` through `:1408`.

## Collision/cancel consumer: `FUN_1400cd750`

The previous projectile collision pass identified `FUN_1400cd750` as the function that checks selected `PlayerSideObject` nodes against enemy projectile nodes.

Refined interpretation:

Candidate name remains `check_player_side_object_vs_projectiles_candidate`.

Why not only “player shot collision”:

- It filters object types with bitmask `0x63737000` and explicit type `0x1a`, selecting a subset of the mixed `PlayerSideObject` list.
- Types seen in the selected range include normal shot-like objects and larger cancel/special objects.
- On overlap it spawns impact/cancel visual effects, plays/queues effect helpers, and sets enemy projectile `active = 0`.

Evidence anchors:

- Object list traversal and type filter: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400cd750_FUN_1400cd750.c:40` through `:50`.
- Enemy projectile traversal and predicted projectile test point: same file `:56` through `:75`.
- Requires projectile `active == 1` and `collision_enabled == 1` before selected cancel paths: same file `:75` through `:76` and `:298` through `:299`.
- Deactivates enemy projectile on overlap: same file `:278` and `:335`.

## Relation to other projectile/visual lists

Do not confuse the three nearby linked lists:

| List | Head | Tail | Count | Allocator | Update/render | Meaning |
|---|---|---|---|---|---|---|
| Enemy projectile | `DAT_140e45260` | `DAT_140e451a8` | `DAT_140e451b4` | `FUN_14006c2f0` | projectile update switch in state `0x14` | Enemy bullets/projectiles. |
| Player-side object | `DAT_140e46ea0` | `DAT_140e9fd38` | `DAT_140e4764c` | `FUN_140109660` | `FUN_140109780` | Player shots, specials, cancel fields, and some clear visuals. |
| Reward item | `DAT_140e46e90` | `DAT_140e46e98` | `DAT_140e46c5c` | `FUN_1400ca6d0` | `FUN_1400ca7b0` | Collectible score/gauge/reward items; includes bullet-cancel drops. |

## Rename candidates

| Address | Current | Candidate | Confidence |
|---|---|---|---|
| `0x140109660` | `FUN_140109660` | `spawn_player_side_object_candidate` | High |
| `0x140109780` | `FUN_140109780` | `update_player_side_objects_candidate` | High |
| `0x1400cd750` | `FUN_1400cd750` | `check_player_side_object_vs_projectiles_candidate` | Medium-high |

## Next targets

1. Build a `RewardItem` type table for the `DAT_140e46e90` list now identified in `reward-item-list.md`.
2. Build a table of `PlayerSideObject` type IDs (`0..0x1a`) with spawn sites and visual resources.
3. Cross-reference `DAT_140e445c0` / `DAT_140e445cc` player variant settings to name the player shot families more concretely.
