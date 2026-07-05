# LikeDreamerRe reconstruction scaffold

This directory contains a **local reconstruction scaffold**, not original Like Dreamer source code and not a complete game reimplementation.

The first milestone is intentionally small: build a Windows x64 exe that initializes DxLib, sets the known DXArchive key, loads a few startup/title resources identified during reverse analysis, and displays a smoke-test title window.

## Evidence used

- `../..//README.md` identifies DxLib + DXArchive and key `VanillaFever11`.
- `../../ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c` shows Steam init, save/config loading, `dxarchive_set_key_candidate("VanillaFever11")`, and initial `media\system\...` loads.
- `../data-structures/resource-handle-map.md` lists startup and primary graphics paths.
- `../headers/*.h` contains reconstructed identifier sketches.

## Build

Build from a Windows Developer PowerShell or Visual Studio command prompt. The target links the official Windows DxLib VC package, so native WSL Linux compilers are not expected to work.

```powershell
cd \\wsl.localhost\Ubuntu\mnt\e\fork\ld\reverse\reconstructed\project
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

The default `DXLIB_ROOT` points at the verified local VC package: `E:\fork\DxLibVCTest\DxLibVCTest`. Override it with `-DDXLIB_ROOT=...` only if that directory moves.

## Run smoke test

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "\\wsl.localhost\Ubuntu\mnt\e\fork\ld" --smoke-test
```

Default mode loads extracted files by mapping logical paths such as `media\system\TitleLogo.png` to `<asset-root>\re\system\TitleLogo.png`.

Experimental DXA mode keeps the original logical `media\...` paths and relies on `media.dxa` plus `SetDXArchiveKeyString("VanillaFever11")`:

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "\\wsl.localhost\Ubuntu\mnt\e\fork\ld" --use-dxa --smoke-test
```

For DXA mode, run from a directory where `media.dxa` is visible using the same layout as the original game.

## Current behavior

- Steam is stubbed out.
- `save\save.dat` and `save\config.dat` are byte-buffer stubs with sizes from the decompiled startup (`0x2730` and `0x1c`).
- Startup only loads smoke-test graphics; `F6` loads the playable-stage graphics it needs on demand.
- Use `F1` for the title smoke screen, `F2` for resource diagnostics, `F3` for text CSV diagnostics, `F4` for save/config diagnostics, `F5` for stage reconstruction probes, `F6` for the playable Stage 01 reconstruction slice, and `ESC` or close the window to exit.
- The `F5` stage probe now includes a small curated set of projectile visual annotations from the boss/final helper review, joining spawn type, projectile ID/selector pair, Bullet.png frame interpretation, and confidence.
- The `F6` playable stage uses arrow keys to move, `Shift` to focus/slow, `Z` to shoot, and `R` to reset the runtime slice.

## Legal boundary

Keep reconstructed code and commercial assets local. Do not redistribute the original executable, assets, rebuilt archives, or proprietary reconstructed logic.

## Expanded diagnostics

Load the larger reconstructed graphics table and optional audio smoke-test handles:

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "E:\fork\ld" --smoke-test --load-all-graphics --load-audio
```

The expanded tables are hand-transcribed from `../data-structures/*.md` and the decompiled startup/resource-loader anchors. They are diagnostic coverage, not final gameplay behavior.

## Stage probe

`F5` shows the current stage-reconstruction evidence layer: stage/background/BGM hints, curated projectile visual annotations for representative boss/final helpers, parsed `LD_demo01..03.txt` header/input counts, replay stage-field offsets, entity model hypotheses, and the next reverse targets to locate (`stage_init`, `stage_update`, `spawn_enemy`, `spawn_bullet`, etc.). This page is intentionally diagnostic only.

## Playable Stage 01 reconstruction slice

`F6` enters a first playable in-stage runtime. It uses a hand-transcribed subset of Stage 01 rows from `../data-structures/stage-spawn-schedule.csv`, simplified common-family enemy behaviors from `../data-structures/stage-spawn-semantic-name-candidates.md`, and projectile constructor/spread conventions from `../data-structures/projectile-helper-notes.md` plus `../data-structures/bullet-frame-visual-map.md`.

Controls: arrow keys move, `Shift` focuses/slows movement, `Z` shoots, and `R` resets the runtime slice. This is a reconstruction probe designed to make stage logic runnable and inspectable; it is not recovered original source and does not yet implement exact helper-by-helper gameplay.
