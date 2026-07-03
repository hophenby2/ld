# Reverse Engineering Status — 2026-07-03

Status: working snapshot for the local Like Dreamer reverse-reconstruction workspace. This is not a recovered source tree and does not currently compile into the target executable.

## Scope and current artifact type

The repository is currently a structured reverse-analysis workspace built from the installed Windows x64 executable and extracted DxLib resources. It contains Ghidra exports, reconstructed maps, pseudocode, and semantic notes. It does **not** yet contain a buildable C/C++ project (`.sln`, `.vcxproj`, `CMakeLists.txt`, or `Makefile`).

## Completed or relatively mature areas

### Main/gameplay flow

- High-level startup and gameplay state flow have been documented.
- The gameplay branch and stage update dispatch are understood well enough to follow per-stage spawn schedules and entity updates.

Primary files:

- `analysis/main-program-flow.md`
- `reconstructed/pseudocode/main_gameplay_flow.md`

### Resource archive and loading model

- Engine/library evidence: DxLib + DXArchive.
- DXA version: v8.
- Confirmed extraction key: `VanillaFever11`.
- Extracted resource count: 230 files.
- Executable `media\\...` references: 227.
- Resource references mapped to extracted files: 226; the known unmapped reference is the demo template `media\\demo\\LD_demo%02d.txt`.

Primary files:

- `analysis/resource-loading.md`
- `symbols/resource-map.csv`
- `symbols/assets.csv`
- `symbols/image-index.csv`
- `reconstructed/data-structures/resource-handle-map-full.csv`

### Stage spawn schedule extraction

The per-stage calls to `stage_spawn_dispatch_candidate(type, duration_or_lifetime, x, y, ...)` have been extracted and summarized.

Primary files:

- `reconstructed/data-structures/stage-spawn-schedule.csv`
- `reconstructed/data-structures/stage-spawn-schedule.md`
- `reconstructed/data-structures/stage-spawn-type-matrix.csv`
- `reconstructed/data-structures/stage-spawn-type-summary.md`

Current understanding:

- Spawn type IDs cluster strongly by stage/theme family.
- Stage-local ranges include:
  - `0x35..0x3f` — stage 04 family
  - `0x44..0x4f` — stage 05 family
  - `0x57..0x77` — stage 06/07 family
  - `0x95..0xa4` — composite/late-stage family
  - `0xfa..0x104` — final/special stage family

### Spawn and entity update dispatch maps

The spawn and update dispatch tables have been reconstructed to a useful level.

Primary files:

- `reconstructed/data-structures/stage-spawn-dispatch-map.csv`
- `reconstructed/data-structures/stage-spawn-dispatch-map.md`
- `reconstructed/data-structures/stage-entity-update-dispatch-map.csv`
- `reconstructed/data-structures/stage-spawn-used-update-map.csv`
- `reconstructed/data-structures/stage-spawn-used-update-map.md`
- `reconstructed/data-structures/stage-spawn-family-notes.md`

Important confirmed points:

- `stage_spawn_dispatch_candidate @ 0x14007b710` dispatches scheduled spawn types through a jump table.
- `stage_entity_spawn_candidate @ 0x140078a00` allocates and initializes stage entity nodes.
- Entity node `+0x18` / downstream `param_1[6]` is the primary behavior/type ID.
- The dispatch `r8d` / entity kind field is not the primary behavior switch.
- `stage_entity_update_dispatch_candidate @ 0x140078b70` walks the entity list and dispatches by entity type.

### Stage entity node layout

A first-pass field map has been documented. It is not yet a formal C struct, but it is sufficient for helper analysis.

Important fields:

| Node field | Downstream form | Current interpretation |
|---|---|---|
| `+0x18` | `param_1[6]` | entity behavior/type ID |
| `+0x1c`, `+0x20` | `param_1[7]`, `param_1[8]` | lifetime/countdown and max/original lifetime |
| `+0x28`, `+0x2c` | `param_1[10]`, `param_1[0xb]` | x/y position |
| `+0x30`, `+0x34` | `param_1[0xc]`, `param_1[0xd]` | origin/anchor/previous x/y, helper-dependent |
| `+0x40`, `+0x42`, `+0x44` | angle fields | current/previous/target heading |
| `+0x48` | double | speed/magnitude/scale, helper-dependent |
| `+0x50` | radius-like field | collision/effect radius candidate |
| `+0x54` | active flag | active/targetable/update flag |
| `+0x60` | next pointer | linked-list next |

Primary file:

- `reconstructed/data-structures/stage-spawn-family-notes.md`

### Resource frame anchors for stage enemies

The main enemy sprite sheets and frame bases are known:

| Sheet | Base global | Layout |
|---|---|---|
| `media\\stage\\Enemy_s.png` | `DAT_140e44660` | `0xaa` frames, 10 x 17, 100x100 |
| `media\\stage\\Enemy_m.png` | `DAT_140e44ad0` | `0xe6` frames, 10 x 23, 200x200 |
| `media\\stage\\Enemy_l.png` | `DAT_140e44910` | `0x6e` frames, 10 x 11, 600x600 |
| `media\\stage\\Bullet.png` | `DAT_140e451c0` | `0x28` frames, 10 x 4, 60x60 |

Reviewed frame clusters:

| Globals | Backing sheet | Frame indexes | Primary use |
|---|---|---:|---|
| `DAT_140e44720..72c` | `Enemy_s.png` | 48-51 | `0x45`, small multipart body |
| `DAT_140e44c08..c10` | `Enemy_m.png` | 78-80 | `0x46`, medium multipart body |
| `DAT_140e44798..7a4` | `Enemy_s.png` | 78-81 | `0x70`, dual-anchor body/effect cluster |
| `DAT_140e448c0/c4` | `Enemy_s.png` | 152-153 | `0xfa`, compact final/special body |
| `DAT_140e448d0..8dc` | `Enemy_s.png` | 156-159 | `0xfc`, final/special sweeper body |
| `DAT_140e44e00/e04` | `Enemy_m.png` | 204-205 | `0xfe`, final child carrier body |
| `DAT_140e44e08/e0c` | `Enemy_m.png` | 206-207 | `0x100`, final dual-child emitter body |
| `DAT_140e44e1c/e20/e24` | `Enemy_m.png` | 211-213 | `0x103/0x104`, large rotating/orbit body |
| `DAT_140e448f4` | `Enemy_s.png` | 165 | `0x103/0x104`, orbit/effect visual |

### Spawn/update semantic candidates

The current semantic naming work is centralized in:

- `reconstructed/data-structures/stage-spawn-semantic-name-candidates.md`

Reviewed higher-value candidates include:

| Type(s) | Candidate semantic label | Confidence |
|---|---|---|
| `0x0b` | `common_homing_burst_emitter` | Medium |
| `0x2..0x5` | `stage00_orbiting_core_variants` | Medium |
| `0x6..0x8` | `common_spawn_marker_to_emitter` | Medium |
| `0x35` | `stage04_triple_afterimage_aimed_emitter` | Medium |
| `0x45` | `stage05_small_swooping_aimed_spread_emitter` | Medium |
| `0x46` | `stage05_medium_multi_part_aimed_burst_emitter` | Medium |
| `0x57/0x58` | `stage06_diving_aimed_emitter_pair` | Medium |
| `0x70` | `stage07_dual_anchor_aimed_spread_emitter` | Medium |
| `0x77` | `stage07_boss_like_pattern_controller` | High |
| `0x9b/0x9c/0x9e/0x9f/0xa1/0xa2` | `composite_child_spawner_triplets` | Medium |
| `0xfa` | `final_stage_curving_single_shot_emitter` | Medium |
| `0xfc` | `final_stage_swaying_triple_shot_sweeper` | Medium |
| `0xfe` | `final_stage_four_satellite_child_carrier` | Medium |
| `0x100` | `final_stage_dual_child_paired_aimed_emitter` | Medium |
| `0x103/0x104` | `final_stage_large_rotating_orbit_burst_emitter_pair` | Medium |

Important policy: these are conservative candidate names. Do not apply them as final Ghidra renames until resource, schedule, and helper-body evidence are strong enough.

## Known gaps

### No buildable source tree yet

The current workspace cannot compile into the target EXE. It lacks a build system and cleaned source. To make a reimplementation buildable, the project still needs:

- C/C++ project skeleton.
- Runtime entry point and gameplay loop.
- DxLib-compatible rendering/audio/input layer or replacement abstraction.
- Global variable definitions.
- Formal structs for entity, player, projectile, resources, and stage state.
- Cleaned helper implementations instead of raw Ghidra decompilation artifacts.
- Stubs or reconstructed implementations for unresolved helpers.

### Recently exported and reviewed helpers

The Homebrew Ghidra export pass on 2026-07-03 produced decompilations under `ghidra-or-ida/exports/missing-helper-priority/`. The following previously missing priority helpers have now been reviewed and folded into `stage-spawn-semantic-name-candidates.md`:

| Type | Helper | Current candidate |
|---|---|---|
| `0x36` | `FUN_140091540` | `stage04_side_entry_curving_multipart_spread_emitter` |
| `0x37` | `FUN_140092230` | `stage04_random_drifting_aimed_microburst_emitter` |
| `0x38` | `FUN_140092b20` | `stage04_large_multipart_sinusoidal_pattern_emitter` |
| `0x3f` | `FUN_140095130` | `stage04_boss_like_multipart_pattern_controller` |
| `0x73` | `FUN_1400a3990` | `stage07_08_drifting_multi_part_emitter` |
| `0x74` | `FUN_1400a4440` | `stage07_lane_sweeper_aimed_burst_emitter` |
| `0x75` | `FUN_1400a4fe0` | `stage07_lower_anchor_bullet_emitter` |
| `0x76` | `FUN_1400a5dd0` | `stage07_heavy_multipart_pattern_emitter` |
| `0xfb` | `FUN_1400af900` | `final_stage_homing_swarmer_with_forward_shots` |
| `0xfd` | `FUN_1400b0b70` | `final_stage_spinning_fan_burster` |
| `0x102` | `FUN_1400b2760` | `final_stage_large_multi_part_carrier_emitter` |

Remaining export status: all scheduled helper bodies from the current high-value adjacent list have now been exported and reviewed. Remaining work shifts to projectile-helper semantics, resource-frame naming, typed struct cleanup, and optional formal Ghidra renames.

### Projectile/bullet system is now first-pass mapped

Common projectile/effect helpers have first-pass names and field layouts in `reverse/reconstructed/data-structures/projectile-helper-notes.md`:

- `FUN_14006c2f0(...)` → `spawn_projectile_node_candidate`.
- `FUN_1400709b0(...)` → `spawn_projectile_spread_candidate`.
- `FUN_140070d00(...)` → `spawn_effect_node_candidate`.
- `FUN_140070250(...)` → `draw_projectile_visual_candidate`.

The projectile ID / update-helper / pattern table lives at `reverse/reconstructed/data-structures/projectile-pattern-parameter-table.csv`, the Bullet.png frame/visual-selector map lives at `reverse/reconstructed/data-structures/bullet-frame-visual-map.md`, the update-helper semantic pass lives at `reverse/reconstructed/data-structures/projectile-update-helper-semantics.md`, the constructor-pair visual coverage lives at `reverse/reconstructed/data-structures/projectile-visual-pair-coverage.md`, and pseudo-C node layouts live in `reverse/reconstructed/headers/stage_entity_layout.h`.

Current understanding covers single-shot allocation, ring/fan expansion, effect node allocation, linked-list globals, 16-bit fixed-angle convention, main dispatcher groupings, the projectile visual draw selector, `Bullet.png` visual frame clusters, a first deeper pass over `FUN_14006c620`, `FUN_14006ce40`, `FUN_14006ecf0`, `FUN_14006faa0`, `FUN_14006fcd0`, and `FUN_14006ffc0`, and raw constructor-call coverage for `1195` literal projectile spawns / `109` distinct `(projectile_id, visual_selector_or_variant)` pairs. Still missing:

- Collision/lifetime behavior for bullets.
- Manual stage/type semantic annotation for the highest-value `(projectile_id, visual_selector)` pairs in boss/final helpers.
- Full naming of higher projectile IDs beyond first-pass dispatcher groups.

### Collision, damage, score, and effects are only partially reconstructed

Known pieces include lifetime, cleanup, active flag, and some radius/effect fields, but the full systems remain incomplete:

- Player/enemy collision.
- Bullet collision.
- Boss HP and gauge behavior.
- Damage scaling.
- Score/reward/effect payout.
- Difficulty/rank scaling.

### Boss and scripted setpieces need deeper passes

Some boss-like or controller-like types are identified (`0x4f`, `0x77`, `0x103/0x104`, final-stage helpers), but the complete boss/setpiece model is still incomplete:

- Boss phase state machines.
- Boss HP/gauge/name linkage.
- Child parts and orbiting controllers.
- Stage clear and transition conditions.

### Non-gameplay UI systems are not yet deeply covered

Some functions have candidate names for menu/gallery/result/replay-related states, but most recent work focused on gameplay entities. Still needs systematic review:

- Title/menu/option flow.
- Stage select.
- Gallery/list/detail screens.
- Replay/demo playback internals.
- Result screen.
- Save/config/unlock/achievement details.

### Ghidra decompiler artifacts remain throughout

Raw exports still contain many artifacts:

- `undefined4` / `undefined8`.
- `param_1[index]` instead of typed structs.
- `CONCAT*`, `SUB*`, stack temporaries, and synthetic locals.
- Generic `FUN_140...` and `DAT_140...` names.

The next readability jump will come from a formal `StageEntity` pseudo-struct and systematic helper/field renaming.

## Recommended next steps

1. Manually annotate the high-value boss/final representative functions from `projectile-visual-pair-coverage.csv`, tying `(projectile_id, visual_selector)` pairs back to stage spawn semantic names.
2. Expand remaining resource frame mapping for `Enemy_s/m/l` and `Boss` sheets, now that Bullet.png has a first-pass visual-selector map.
3. Locate and type the projectile collision/lifetime walker that consumes `radius_or_flags` and active/draw flags.
4. Rewrite reviewed helper notes opportunistically in terms of the new `StageEntity`, `ProjectileNode`, and `EffectNode` pseudo-fields.
5. Keep Ghidra renames conservative and per-type until helper behavior, schedule usage, and resource identity agree.

## Legal/use boundary

Keep outputs local. Do not redistribute commercial assets, rebuilt archives, or reconstructed proprietary code.
