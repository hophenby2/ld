# Stage Spawn Type Family Notes

Status: aggregate notes from `stage-spawn-schedule.csv` and `stage-spawn-type-matrix.csv`. These are numeric spawn/entity type families, not confirmed enemy or object names.

## Core observations

`stage_spawn_dispatch_candidate(type, duration_or_lifetime, x, y, ...)` is called by the per-stage update handlers. The first argument clusters strongly by stage, suggesting the type id space is grouped by stage/theme or entity family.

Supporting files:

- `stage-spawn-schedule.csv` — raw extracted call rows, including nearby decompiler frame conditions.
- `stage-spawn-schedule.md` — readable raw schedule by stage.
- `stage-spawn-type-matrix.csv` — count matrix of spawn type by stage.
- `stage-spawn-type-summary.md` — matrix plus first/last examples for each type.
- `stage-spawn-dispatch-map.csv` — full `type -> case index -> case block -> default fields` reconstruction from the `stage_spawn_dispatch_candidate` jump table.
- `stage-spawn-dispatch-used-types.csv` / `.md` — dispatch map restricted to spawn types seen in stage schedules.

## Stage-to-type family map

| Stage | Dominant spawn type families | Notes |
|---:|---|---|
| `00` | `0x00..0x05` plus many non-spawn helper calls | Special tutorial/intro-like handler; also uses many prompt/HUD helpers and direct object allocation. |
| `01` | `0x0a..0x10`, with common `0x0b` projectile-like repeats | First regular dense schedule; type `0x0b` appears repeatedly with random x/y edges. |
| `02` | `0x19..0x20`, plus common `0x0b`, `0x0d` | Strong type block `0x19..0x20`; later reused by stage `09` and stage `08`. |
| `03` | `0x25..0x2e`, plus common `0x07`, `0x08`, `0x0b` | Strong type block `0x25..0x2e`; reused by stage `08` and lightly by stage `09`. |
| `04` | `0x35..0x3f` | Strong self-contained type block; heavily uses `0x35`/`0x38`. |
| `05` | `0x44..0x4f` | Strong self-contained type block; type `0x46` dominates this stage. |
| `06` | `0x57..0x5f`, plus common `0x0b..0x0f`, `0x1a` | Strong type block `0x57..0x5f`; type `0x57` and `0x58` dominate. |
| `07` | `0x70..0x77`, plus common `0x07`, `0x08`, `0x25`, `0x26` | Strong type block `0x70..0x77`; type `0x70` dominates. |
| `08` | Broad composite: `0x0a..0x10`, `0x19..0x20`, `0x25..0x2e`, `0x35..0x3f`, `0x44..0x4a`, `0x57..0x5f`, `0x70..0x73`, `0x95..0xa4` | Longest handler; appears to remix many earlier stage families plus its own `0x95..0xa4` block. Candidate for boss/rush/final composite stage, pending resource/text evidence. |
| `09` | Reuses many previous families: `0x0b..0x0f`, `0x19..0x1b`, `0x25..0x2b`, `0x35..0x3a`, `0x44..0x48`, `0x57..0x58`, `0x74`, `0x9b..0xa4` | Composite/reuse-heavy schedule; likely late-stage or challenge remix. |
| `10` | `0xfa..0x104`, plus common `0x06..0x08` | Distinct high-numbered type block; special/final-stage-like handler with no intro banner extraction in the raw schedule. |

## Dispatch map findings

`stage_spawn_dispatch_candidate @ 0x14007b710` uses a two-level table:

1. A byte index table at `0x14007c098`, indexed directly by spawn type `0..0x104`.
2. A case offset table at `0x14007bfcc`, indexed by that byte case id.

This means many numeric spawn types intentionally share the same case block/default behavior. For example:

- Types `0` and `1` both map to case `0` / target `0x14007b741`.
- Types `2`, `3`, and `4` all map to case `1` / target `0x14007b771`.
- Common type `0x0b` and type `0x0d` both map to case `5` / target `0x14007bb1f`.
- Several late composite/final types (`0xfe`, `0x100`, etc.) reuse earlier case `18` / target `0x14007bf24`.

The reconstructed fields extracted from objdump now line up with the `0x68`-byte node allocated by `stage_entity_spawn_candidate @ 0x140078a00`:

| Extracted field | Node offset | Meaning | Evidence |
|---|---:|---|---|
| `spawn_type` / first dispatch arg | `+0x18` (`puVar1[6]`) | Entity behavior/type id. This is the value most downstream helpers test as `param_1[6]` (`0x83`, `0x84`, `0x116`, etc.), so it is the node's primary behavior discriminator. | `stage_entity_spawn_candidate` stores `param_1` at `puVar1[6]`; downstream helpers branch on `param_1[6]`. |
| `entity_kind/r8d` | `+0x24` (`puVar1[9]`) | Render/collision category, not the main type. It is copied from dispatch `r8d` into `param_3`, then used by generic update/render helpers (`FUN_14007b010` uses `*(int *)(param_1 + 0x24)` for effect payout/scoring scale). | `stage_entity_spawn_candidate` stores `param_3` at `puVar1[9]`; `FUN_14007b010` reads offset `+0x24`. |
| dispatch arg 2 / schedule duration | `+0x1c` and `+0x20` (`puVar1[7]`, `puVar1[8]`) | Lifetime/countdown or max lifetime. In mode `DAT_140e419b8 == 0`, this is scaled by `DAT_140539f28` except for special type `0x153`. Several child/follower helpers copy parent `+0x1c/+0x20` to synchronize lifetimes. | Stored twice by `stage_entity_spawn_candidate`; follower code clamps child `param_1[7]` against parent lifetime. |
| dispatch x | `+0x28`, mirrored to `+0x30`/`+0x38` | X position / previous/origin x. | Stored from `param_4` into `puVar1[10]`, `puVar1[0xc]`, `puVar1[0xe]`; flush renders from `+0x28`. |
| dispatch y | `+0x2c`, mirrored to `+0x34`/`+0x3c` | Y position / previous/origin y. | Stored from `param_5` into `puVar1[0xb]`, `puVar1[0xd]`, `puVar1[0xf]`; flush renders from `+0x2c`. |
| angle argument | `+0x40`, `+0x42`, `+0x44` | Current/previous/target angle or heading. | Stored from `param_6`; many helpers update `+0x40`/`+0x42` and pass it to projectile/effect constructors. |
| `const` | `+0x48` (`double`) | Speed/scale/timing constant. | Stored from `param_7`; movement helpers use `*(double *)(param_1 + 0x48)` as velocity/magnitude. |
| `field_38` | `+0x50` (`puVar1[0x14]`) | Collision radius / clear-effect size. It is rendered as explosion size during `stage_entity_flush_effects_candidate` and used in distance tests. | `stage_entity_spawn_candidate` stores `param_8`; `stage_entity_flush_effects_candidate` multiplies offset `+0x50` by `DAT_140539e38`; targeting code subtracts it from distance. |
| `field_40` | `+0x54` (`puVar1[0x15]`) | Active/targetable flag. Most spawns set it to `1`; helpers set it to `0` while transitioning or before removal. | Targeting code requires `+0x54 == 0` or `param_1[0x15] == 0` in specific contexts; spawn map usually sets stack `+0x40` to `1`. |
| `field_48` | `+0x08` (`puVar1[2]`) | Parent/link id or auxiliary owner id, not spatial data. | Stored from `param_10`; direct spawns pass `DAT_140e44308` when creating child nodes. |
| list link | `+0x60` | Next pointer in `DAT_140e45d80` list. | New nodes are appended through previous tail `+0x60`; all list walks follow `+0x60`. |

Important correction: the earlier column name `entity_kind/r8d` should not be treated as the primary behavior switch. The actual behavior discriminator is the node's `+0x18` type (`param_1[6]` downstream), which is the original spawn type or a child type created by another entity.

## Downstream update dispatcher

`stage_entity_update_dispatch_candidate @ 0x140078b70` is the per-node dispatcher. It walks `DAT_140e45d80`, reads node `+0x18`, indexes byte table `DAT_1400799a8[type]`, and dispatches the resulting update case to a helper. After the helper runs, if node `+0x54 == 0`, it calls `FUN_1400cc2f0`, then increments node timers at `+0x0c` and, when active, `+0x10`.

Generated maps:

- `stage-entity-update-dispatch-map.csv` — full entity type `0..0x153` to update case/helper mapping.
- `stage-spawn-used-update-map.csv` / `.md` — the same mapping restricted to spawn types observed in per-stage schedules.

Important correction: this confirms that `entity_kind/r8d` is not the switch input. The update switch input is node `+0x18`, i.e. the original `spawn_type` or a child type spawned by another entity.

### Used scheduled spawn type groups by update helper

| Spawn type family | Update helper pattern | Notes |
|---|---|---|
| `0x00..0x10` | `FUN_1401327d0` through `FUN_140080fb0` | Early/common family; types `0/1`, `2..5`, and `6..8` share update helpers. |
| `0x19..0x2e` | `FUN_1400841d0` through `FUN_14008efc0` | Stage-family block with mostly one update helper per spawn type; `0x39/0x3a`-style sharing appears in later blocks. |
| `0x35..0x4f` | `FUN_140090c30` through `FUN_14009b5f0` | Stage-local blocks; several paired types share helpers (`0x39/0x3a`, `0x47/0x48`). |
| `0x57..0x77` | `FUN_14009d610` through `FUN_1400a7760` | Another contiguous stage-family range with paired helper sharing (`0x57/0x58`, `0x5b/0x5c`, `0x71/0x72`). |
| `0x95..0xa4` | `FUN_1400a9080` through `FUN_1400acd20` | Composite/late-stage family; `0x97/0x98/0x99` and `0x9b/0x9c/0x9e/0x9f/0xa1/0xa2` share helpers. |
| `0xfa..0x104` | `FUN_1400af090` through `FUN_1400b3540` | Special/final high-numbered family; mostly one helper per type except `0x103/0x104`. |

### Child/internal type anchors

Some update helpers spawn child entity types not present directly in stage schedules:

| Helper | Child/internal type evidence | Notes |
|---|---|---|
| `FUN_14004a970` | creates `0xce..0xd9` | Broad scripted/boss-like state machine; reached by update case `0xa7`, not by the initially scheduled types above. |
| `FUN_14002d2f0` | checks `0x83/0x84` and later `0x13f..0x151` | Paired/follower behavior; synchronizes child lifetime with parent node. |
| `FUN_14005e890` | handles `0x116..0x119` | High-numbered family-specific behavior. |
| `FUN_1400e20e0` | handles `0x7e/0x7f` | Bullet/emitter-like behavior: moves by angle/speed, emits effects/projectiles, clears on lifetime/bounds. |
| `FUN_1400e0680` | handles `0x79..0x7d` | Parent-relative/follower behavior; reads parent node fields by matching ids in `DAT_140e45d80`. |

Next step: review the high-value update helpers in `stage-spawn-used-update-map.md` order and attach semantic labels to helper groups before renaming numeric spawn types globally.

## Cross-stage common types

| Type family | Evidence |
|---|---|
| `0x07`, `0x08` | Appears once or twice in many stages, likely common large/background or stage-control entities. |
| `0x0b` | Most common spawn type overall: 74 calls across stages `01..09`, often with random edge/position arguments. Candidate common small enemy/projectile family. |
| `0x0c..0x0f` | Common early type family reused across several stages. |
| Stage-local blocks | Most stage families are contiguous blocks: `0x19..0x20`, `0x25..0x2e`, `0x35..0x3f`, `0x44..0x4f`, `0x57..0x5f`, `0x70..0x77`, `0x95..0xa4`, `0xfa..0x104`. This suggests `stage_spawn_dispatch_candidate` maps type ids to specialized enemy/object constructors or behavior initializers. |

## Next evidence needed

1. Review `stage_spawn_dispatch_candidate` switch and downstream case functions to map each type id to actual constructor/update logic.
2. Cross-reference graphics/resource ids touched by those constructors against `graphics-table.csv` / resource filenames.
3. Only after resources confirm the stage themes, rename `stage_XX_gameplay_update_candidate` and type families away from numeric names.
