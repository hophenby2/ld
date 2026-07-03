# Like Dreamer Reverse Reconstruction Workspace

This workspace contains local-only reverse reconstruction notes for the installed Like Dreamer copy.

## Scope

This is **not** a recovered original source project. It is a structured reverse-analysis workspace built from:

- `inputs/LikeDreamer.exe` — compiled Windows x64 PE executable.
- `inputs/media.dxa` — original DxLib DXArchive resource package.
- `../re/` — resources extracted from `media.dxa` with key `VanillaFever11`.
- `save/` and `replay/` in the parent directory — runtime data samples.

The goal is to reconstruct resource maps, data formats, state-machine notes, and readable pseudocode sufficient for local maintenance/reimplementation research.

## Current Findings

- Engine/library evidence: DxLib + DXArchive.
- DXA version: v8.
- Confirmed DXA extraction key: `VanillaFever11`.
- Extracted resource count: 230 files.
- Executable `media\\...` string references: 227.
- Resource references mapped to extracted files: 226; the unmapped one is `media\\demo\\LD_demo%02d.txt`, which is a format template for `LD_demo01.txt` etc.

## Important Outputs

- `symbols/pe-info.txt` — PE/file/hash/import summary.
- `symbols/imports.txt` — `objdump -p` import/PE dump.
- `symbols/strings.txt` — full executable strings with offsets.
- `symbols/resources.txt` — curated high-value strings with offsets.
- `symbols/resource-map.csv` — executable resource paths mapped to extracted files.
- `symbols/assets.csv` — full extracted asset index.
- `analysis/resource-loading.md` — reconstructed loading model.
- `analysis/text-csv-format.md` — CSV text notes.
- `analysis/demo-format.md` — demo TXT notes.
- `analysis/save-replay-format.md` — save/config/replay binary notes.
- `analysis/main-program-flow.md` — main startup loop, scene state, and high-level state transition notes.
- `analysis/reverse-status-2026-07-03.md` — current reverse-engineering status, completed areas, gaps, and next export priorities.
- `analysis/dispatcher-rename-plan.md` — proposed Ghidra names for central dispatcher handlers.
- `tools/ghidra_scripts/RenameGameplayHelpers.java` — applied Ghidra names for confirmed gameplay helper candidates.
- `tools/ghidra_scripts/RenamePerStageGameplayHandlers.java` — applied generic stage-index names for gameplay update handlers dispatched by state `0x14`.
- `tools/ghidra_scripts/RenameGameplaySpawnHelpers.java` — applied conservative names for common stage spawn/event helper functions.
- `reconstructed/pseudocode/save_replay_manager.md` — evidence-backed pseudocode for save/config/replay handlers.
- `reconstructed/pseudocode/main_gameplay_flow.md` — evidence-backed pseudocode for the renamed gameplay-adjacent dispatcher states `0x03`, `0x04`, `0x05`, `0x14`, and `0x2c`.
- `reconstructed/data-structures/stage-spawn-schedule.csv` / `.md` — raw extracted per-stage `stage_spawn_dispatch_candidate` and related helper call schedules.
- `reconstructed/data-structures/stage-spawn-type-matrix.csv` and `stage-spawn-type-summary.md` — spawn type by stage count matrix and examples.
- `reconstructed/data-structures/stage-spawn-dispatch-map.csv` and `stage-spawn-dispatch-map.md` — reconstructed `stage_spawn_dispatch_candidate` jump-table mapping.
- `reconstructed/data-structures/stage-entity-update-dispatch-map.csv` and `stage-spawn-used-update-map.md` — reconstructed `stage_entity_update_dispatch_candidate` type-to-update-helper mapping.
- `reconstructed/data-structures/stage-spawn-semantic-name-candidates.md` — first-pass conservative semantic labels for spawn/update helper groups.
- `reconstructed/data-structures/stage-spawn-family-notes.md` — current stage-to-spawn-type-family interpretation.
- `reconstructed/data-structures/projectile-helper-notes.md` — first-pass projectile/effect helper semantics for `FUN_14006c2f0`, `FUN_1400709b0`, and `FUN_140070d00`.
- `reconstructed/data-structures/projectile-helper-callsite-map.md` — representative projectile/effect helper call-site map by stage/entity helper.
- `reconstructed/data-structures/projectile-pattern-parameter-table.csv` — current projectile ID / update-helper / pattern parameter table.
- `reconstructed/headers/stage_entity_layout.h` — pseudo-C layouts for `StageEntity`, projectile nodes, and effect nodes.

## Next Steps

1. Review high-value update helpers in `stage-spawn-used-update-map.md` order and attach semantic labels to helper groups before renaming numeric spawn types globally.
2. Cross-reference stage resource/text IDs to replace generic `stage_XX` names with real stage/theme names when evidence is strong.
3. Cross-reference `media\\text\\text01.csv` to locate text manager initialization.
4. Gradually remove `candidate` suffixes only after handler semantics are confirmed by body review and resource/UI evidence.
5. Return to replay binary details only after the main gameplay branch is mapped.

## Legal/Use Boundary

Keep outputs local. Do not redistribute commercial assets, rebuilt archives, or reconstructed proprietary code.
