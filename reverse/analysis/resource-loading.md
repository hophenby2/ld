# Resource Loading Reconstruction Notes

## Evidence

- Main executable: `inputs/LikeDreamer.exe`
- Archive: `inputs/media.dxa`
- Extracted resource symlink: `assets/re -> ../re`
- DXA key confirmed by extraction test: `VanillaFever11`
- Interesting strings: `symbols/resources.txt`
- Executable-to-resource mapping: `symbols/resource-map.csv`

## DXA Header

`media.dxa` is DxLib DXArchive v8. Parsed header from prior inspection:

```text
Head: DX
Version: 8
HeadSize: 25728
DataStart: 64
FileNameTableStart: 242952384
FileTableStart: 8128
DirectoryTableStart: 25408
CharCodeFormat: 932
Flags: 0
HuffmanEncodeKB: 10
```

## Resource Path Mapping

The executable contains 227 `media\...` string references. `symbols/resource-map.csv` maps 226 of them to extracted files under `re/`. The one unmapped pattern is expected to be a formatted path or case/path variant.

## Resource Counts

By category:

- `(root)`: 1
- `bgm`: 22
- `demo`: 3
- `effect`: 3
- `gallery`: 19
- `player`: 20
- `se`: 71
- `stage`: 29
- `system`: 58
- `text`: 4

By extension:

- `.csv`: 4
- `.db`: 1
- `.mp3`: 2
- `.ogg`: 22
- `.png`: 129
- `.txt`: 3
- `.wav`: 69

## Reconstructed Loading Model

Hypothesis based on strings and DxLib/DXArchive evidence:

1. Program initializes Steam and DxLib.
2. Program sets DXArchive key string to `VanillaFever11` or equivalent internal value.
3. Program loads assets through DxLib path APIs using logical paths such as `media\system\TitleLogo.png`.
4. DxLib resolves the `media` logical root to `media.dxa`.
5. Fonts `Nyashi.ttf` and `ChillRoundM.ttf` appear to be loaded from real files in the run directory.
6. Save/config/replay files are real filesystem files under `save/` and `replay/`.

## Next Reverse Targets

- Cross-reference `VanillaFever11` in a decompiler to locate DXA key setup.
- Cross-reference `media\text\text01.csv` to locate text manager initialization.
- Cross-reference `SteamAPI_Init` imports/strings to locate startup chain.
- Cross-reference `replay\LD_replay%02d.dat` to locate replay loader/writer.
