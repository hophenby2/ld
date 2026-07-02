# Ghidra First Pass Findings

## Import status

Ghidra 12.1.2 headless import and auto-analysis succeeded.

Project:

```text
reverse/ghidra-or-ida/project/LikeDreamerGhidra.gpr
```

Main exports:

```text
reverse/ghidra-or-ida/exports/summary.md
reverse/ghidra-or-ida/exports/functions.tsv
reverse/ghidra-or-ida/exports/defined-strings.tsv
reverse/ghidra-or-ida/exports/anchor-xrefs.tsv
reverse/ghidra-or-ida/exports/decompiled-anchors/
```

## Analysis summary

- Image base: `0x140000000`
- Functions found: `5596`
- Defined strings: `2859`
- Decompiled anchor functions exported: `44`
- PDB reference found but unavailable: `Outside_Game.pdb`

## High-value anchor functions

| Anchor | Function(s) | Current interpretation |
|---|---|---|
| `VanillaFever11` | `FUN_1400f4f70` | Main startup/init function; calls Steam init, reads save/config, sets DXA key. |
| `SteamAPI_Init` | `FUN_1400f4f70` | Same startup function. |
| `Failed to initialize SteamAPI.` | `FUN_1400f4f70` | Steam init failure path. |
| `media\\system\\TitleLogo.png` | `FUN_1400ced90` | Main resource loading function for base images/audio/textures. |
| `media\\bgm\\Stage1.ogg` | `FUN_1400ced90` | Same resource loading function includes BGM table. |
| `media\\text\\text01.csv` | `FUN_1400d0e50` | Additional language/UI/tutorial/gallery resource loader; cross-ref to text CSV anchor. |
| `save\\save.dat` | many functions, including `FUN_1400f4f70` | Save read/write and many gameplay update paths reference save data. |
| `save\\config.dat` | `FUN_1401019e0`, `FUN_1400f4f70` | Config read/write. |
| `replay\\LD_replay%02d.dat` | `FUN_140115880`, `FUN_1401171d0`, `FUN_140114580` | Replay load/save/list handling candidates. |
| `DXBDXARC` / `DxArchive_.cpp` | `FUN_1401b...` cluster | Bundled DxLib DXArchive implementation; likely library code, not game-specific logic. |

## Key decompiler evidence

`FUN_1400f4f70` appears to be startup/main init. Evidence:

- Calls `SteamAPI_RestartAppIfNecessary(0x1c7fdc)`.
- Calls `SteamAPI_Init()`.
- Shows `Failed to initialize SteamAPI.` on failure.
- Reads `save\\save.dat`, size `0x2730` into `DAT_140e41b10`.
- Reads `save\\config.dat`, size `0x1c` into `DAT_140e468f0`.
- Calls `thunk_FUN_1401b23b0("VanillaFever11")`; likely `SetDXArchiveKeyString` or equivalent DXArchive key setter.
- Begins loading resources such as `media\\system\\WhiteBack.png` and then calls `FUN_1400ced90()`.

`FUN_1400ced90` appears to be the primary resource-loading table/function. Evidence:

- Loads many individual images through `FUN_140155c60(path, 0)` and `FUN_140155bf0(path, columns, rows, ..., width, height, destination, ...)`.
- Contains title/menu/player/stage/gallery/effect resources.
- Likely maps resource IDs/global handles into `DAT_140e...` globals.

`FUN_1400d0e50` appears to load secondary localized/UI/manual resources. Evidence:

- Loads `Manual.png`, `ManualMenu.png`, `DifficultyTips.png`, `KerPromot.png`, `PauseMenu.png`, `TutorialPanel.png`, gallery notices, map/equip menu resources.
- Has variants and language-related resource group behavior.

## Next reverse targets

1. Rename `FUN_1400f4f70` in Ghidra to `game_startup_init_candidate`.
2. Rename `FUN_1400ced90` to `load_primary_resources_candidate`.
3. Rename `FUN_1400d0e50` to `load_secondary_localized_resources_candidate`.
4. Identify `thunk_FUN_1401b23b0`; likely maps to `SetDXArchiveKeyString`.
5. Identify `FUN_140155c60` and `FUN_140155bf0`; likely image/texture load helpers.
6. Trace callers/callees for replay candidates `FUN_140115880`, `FUN_1401171d0`, `FUN_140114580`.

## Candidate renames applied

The following user-defined names were applied to the Ghidra project and re-exported under `exports/renamed-decompiled/`:

| Address | New name | Status |
|---|---|---|
| `1400f4f70` | `game_startup_init_candidate` | OK |
| `1400ced90` | `load_primary_resources_candidate` | OK |
| `1400d0e50` | `load_secondary_localized_resources_candidate` | OK |
| `1401b23b0` | `dxarchive_set_key_candidate` | OK |
| `140155c60` | `dxlib_load_graph_candidate` | OK |
| `140155bf0` | `dxlib_load_div_graph_candidate` | OK |
| `140115880` | `replay_or_save_handler_candidate_A` | OK |
| `1401171d0` | `replay_handler_candidate_B` | OK |
| `140114580` | `replay_or_save_handler_candidate_C` | OK |
| `1401019e0` | `config_handler_candidate` | OK |
| `1400d0a30` | `save_init_or_reset_candidate` | OK |

Renamed decompilation outputs:

```text
reverse/ghidra-or-ida/exports/renamed-decompiled/
```

Important files:

```text
1400f4f70_game_startup_init_candidate.c
1400ced90_load_primary_resources_candidate.c
1400d0e50_load_secondary_localized_resources_candidate.c
1401b23b0_dxarchive_set_key_candidate.c
140155c60_dxlib_load_graph_candidate.c
140155bf0_dxlib_load_div_graph_candidate.c
140115880_replay_or_save_handler_candidate_A.c
1401171d0_replay_handler_candidate_B.c
140114580_replay_or_save_handler_candidate_C.c
1401019e0_config_handler_candidate.c
1400d0a30_save_init_or_reset_candidate.c
```
