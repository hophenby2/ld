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

## Next Steps

1. Import `inputs/LikeDreamer.exe` into Ghidra/IDA if available.
2. Cross-reference `VanillaFever11` to locate DXArchive key setup.
3. Cross-reference `media\\text\\text01.csv` to locate text manager initialization.
4. Cross-reference `replay\\LD_replay%02d.dat` to locate replay handling.
5. Gradually write pseudocode in `reconstructed/pseudocode/` with evidence labels.

## Legal/Use Boundary

Keep outputs local. Do not redistribute commercial assets, rebuilt archives, or reconstructed proprietary code.
