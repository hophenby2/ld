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
    int damage_or_lifetime,
    float collision_radius_or_scale);
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
| `+0x28` | `node[10]` | `damage_or_lifetime` | Damage for moving shot types `0..0x0a`; helper-specific lifetime/value for special objects. The allocator multiplies it by 100 when `DAT_140e9fd20 == 1`. |
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
- Enemy projectile traversal and current visible projectile `x/y` test point: same file `:56` through `:75`.
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

## Current reconstruction status

`reverse/reconstructed/project/src/stage_runtime.cpp` now uses the vector-backed `PlayerSideObject` runtime for two evidence-backed roles:

- offensive collision with stage enemies through `handlePlayerSideObjectEnemyCollisions()`;
- first-pass enemy projectile cancellation through `handlePlayerSideObjectProjectileCancels()`, emitting reward item type `3` for smaller/default cancel hits and type `4` for larger/special cancel hits.

The special-gauge action scaffold in `StageRuntime::updateSpecialGaugeAction()` also spawns an existing player-side object family when `specialGauge >= 50000`, then enters a `-600..0` cooldown. This is a conservative reconstruction of the `player_update_input_movement_candidate` evidence; the exact original special/hyper label, type `0x18` chain, and bitmask `0x63737000` filtering remain deferred.

## Type table and cancel mask pass — 2026-07-07

Focused reads of `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/140109780_FUN_140109780.c` and `1400cd750_FUN_1400cd750.c` resolve the top-level type families and the original projectile-cancel filter.

### Update/render type families

| Type | Role / behavior evidence | Runtime status |
|---:|---|---|
| `0..0x0a` | Moving player-shot-like objects. They move by `angle/speed`, draw from `DAT_140e44e70` player frames with frame groups selected by `DAT_140e445c0`, and expire on extended bounds (`140109780.c:125-373`). | Implemented as normal player-side shots; frame semantics still approximate. |
| `0x0b` | Parent special/bomb-like object. On age `0`, spawns type `0x1a`; at ages `0`, `8`, `0x10`, `0x18`, spawns type `0x0c` children and plays `DAT_140e47250` (`140109780.c:376-447`). | Documented; runtime pending. |
| `0x0c` | Bouncing/reflecting child. Reflects inside bounds for about `0x14` frames, then expires with type `0x0d` effect and `DAT_140e47254` (`140109780.c:448-563`). | Partially modeled only as cancel-capable. |
| `0x0d` | Expiry/impact visual for type `0x0c`; draws `DAT_140e45064`, group `0x3c`, lifetime to `0x82` (`140109780.c:564-595`). | Runtime pending. |
| `0x0e` | Special variant that spawns type `0x19` and bouncing/effect visuals, including `DAT_140e4725c` at age `0x1e` (`140109780.c:596-773`). | Runtime pending. |
| `0x0f` | Centered special variant; repeatedly spawns type `0x10` children and type `0x13` effect generators (`140109780.c:774-840`). | Runtime pending. |
| `0x10` | Child object spawned by `0x0f`; moves/draws `DAT_140e41a5c` and emits effect node selector `0x3b` (`140109780.c:841-897`). | Runtime pending. |
| `0x11` | Long special variant; age `0` spawns type `0x18` and sets `DAT_140e44658 = 600`; lifetime around `600` frames (`140109780.c:898-949`). | Runtime pending. |
| `0x12` | Long special/generator variant; periodically creates type `0x13` generators (`140109780.c:950-1045`). | Runtime pending. |
| `0x13` | Timed generator; every five frames spawns multiple type `0x14` children and plays `DAT_140e47264` (`140109780.c:1046-1072`). | Runtime pending. |
| `0x14` | Generated child visual/cancel object drawing `DAT_140e41a70`, group `0x3c`; lifetime `0x1e` (`140109780.c:1073-1097`). | Runtime pending. |
| `0x15` | Screen-field style object that draws repeated `DAT_140e45074`, `DAT_140e45070`, and `DAT_140e41938` visuals and plays `DAT_140e47268` every `0x14` frames (`140109780.c:1098-1256`). | Runtime pending. |
| `0x16` | Ring object; on age `0` emits repeated `FUN_140070d00` effect nodes, then draws `DAT_140e45078` (`140109780.c:1257-1328`). | Runtime pending. |
| `0x17` / `0x18` | Expanding ring/cancel visuals drawing `DAT_140e45060`, group `0x46`; age `0` raises `DAT_140e44654` if below `100`; lifetime `0x30` (`140109780.c:1329-1357`). | Runtime pending; `0x18` participates in special-gauge chain. |
| `0x19` | Shorter expanding ring/cancel visual drawing `DAT_140e45060`, group `0x46`; lifetime `0x18` (`140109780.c:1358-1385`). | Runtime pending. |
| `0x1a` | Expanding ring/cancel visual drawing `DAT_140e41a54`, group `0x46`; lifetime `0x18` (`140109780.c:1386-1408`). | Explicit cancel path retained in runtime. |

### Original projectile-cancel type filter

`FUN_1400cd750` first filters the mixed player-side object list with:

```c
(type < 0x1f) && ((0x63737000U >> (type & 0x1f)) & 1)
```

Decoded selected type IDs:

```text
0x0c, 0x0d, 0x0e, 0x10, 0x11, 0x14, 0x15, 0x16, 0x18, 0x19, 0x1d, 0x1e
```

The same function has a separate explicit `type == 0x1a` path (`1400cd750.c:562-566`) that jumps into the same switch body. Runtime now uses this bitmask plus explicit `0x1a` instead of the earlier broad radius heuristic.

Cancel reward evidence:

- `FUN_1400cd750` tests predicted enemy projectile position and requires projectile `active == 1` plus `collision_enabled == 1` in the main paths (`1400cd750.c:56-77`, `:298-300`).
- Projectile radius `< 2` emits reward item type `3`; larger/special paths emit type `4` (`1400cd750.c:90-97`, `:178-185`, `:377-380`, `:459-461`).
- On overlap it deactivates the projectile and allocates impact/cancel effect nodes.

## Next targets

1. Build a `RewardItem` type table for the `DAT_140e46e90` list now identified in `reward-item-list.md`.
2. Port the highest-impact `PlayerSideObject` type chains (`0x0b -> 0x0c/0x1a`, `0x0f -> 0x10`, `0x13 -> 0x14`) into the runtime probe incrementally.
3. Cross-reference `DAT_140e445c0` / `DAT_140e445cc` player variant settings to name the player shot families more concretely.

## Exact Bomb/Fever port - 2026-07-13

The earlier pending/scaffold status above is superseded by
`player-special-mode-exact-notes.md`.  The runtime now implements the six
equipment-selected root objects and their `0x0b..0x1a` chains, including
per-frame radius writes used by the original cancel mask.  Auto/Manual Fever,
the `9999999` Manual-ready sentinel, and the `-600..0` active-Fever interval are
also connected from the equipment menu to `StageRuntimeConfig`.

Direct core sprites use the recovered `Effect_m[5/6/7/12]` and
`Effect_l[0/1/4/5/6]` handles.  Generic secondary effect-list emissions remain
separately deferred; they do not replace or broaden the recovered object
collision fields.

The enemy consumer `FUN_1400cc2f0` is now represented as an enemy-outer,
player-object-inner walk without an `active` test. This restores normal-shot
terminal hits, `0x0c -> 0x0d` impact conversion, and persistent Bomb damage for
`0x0d/0x0e/0x14/0x15`. The projectile consumer now also keeps the original
three cancel groups instead of collapsing them into one reward heuristic.
