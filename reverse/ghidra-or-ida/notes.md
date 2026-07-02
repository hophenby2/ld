# Decompiler Notes

No decompiler project has been created yet in this workspace.

Recommended first-pass labels once imported:

| Evidence | Analysis action |
|---|---|
| `VanillaFever11` | Find cross-references; likely DXA key setup or resource initialization. |
| `media\\text\\text01.csv` | Find text manager/CSV loader initialization. |
| `media\\system\\TitleLogo.png` | Find title/UI resource table initialization. |
| `replay\\LD_replay%02d.dat` | Find replay load/save code. |
| `save\\save.dat` / `save\\config.dat` | Find save/config serialization code. |
| `SteamAPI_Init` / `Failed to initialize SteamAPI.` | Find startup chain and Steam wrapper. |
| `DxArchive_.cpp`, `DXBDXARC`, `DxLib` | Identify bundled library code boundaries to avoid mistaking library functions for game code. |

Suggested naming convention:

- `game_init_*` for game-specific startup functions.
- `res_*` for resource manager functions.
- `text_*` for CSV/text functions.
- `save_*` / `replay_*` for serialization.
- `steam_*` for Steam API wrapper functions.
- `dxlib_*` only when confident a function belongs to the bundled library.
