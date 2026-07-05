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
cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DDXLIB_ROOT="\\wsl.localhost\Ubuntu\home\a\ld\DxLib_VC3_24f\DxLib_VC\僾儘僕僃僋僩偵捛壛偡傋偒僼傽僀儖_VC梡"
cmake --build build --config Release
```

If your Windows CMake cannot read the WSL-style default path, always pass `DXLIB_ROOT` as the UNC path shown above.

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
- Only smoke-test graphics are loaded.
- Press `ESC` or close the window to exit.

## Legal boundary

Keep reconstructed code and commercial assets local. Do not redistribute the original executable, assets, rebuilt archives, or proprietary reconstructed logic.
