# Stage 01 Frame / Constant / Boss Handoff Map

Status: evidence-backed mapping pass for remaining Stage 1 runtime alignment. This file records original resource/frame/constant evidence and how the reconstruction maps it. It is intentionally conservative: `FUN_1400c8410` overlay nodes and exact original effect list lifetimes remain deferred.

## Resource atlas bases

Evidence: `reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c:161-169`.

| Atlas | Load call | Base global | Frame formula |
|---|---|---|---|
| `media\\stage\\Enemy_s.png` | `dxlib_load_div_graph_candidate(..., 0xaa, 10, 0x11, 100, 100, &DAT_140e44660, ...)` | `DAT_140e44660` | `DAT_140e44660 + 4 * frame` |
| `media\\stage\\Enemy_m.png` | `dxlib_load_div_graph_candidate(..., 0xe6, 10, 0x17, 200, 200, &DAT_140e44ad0, ...)` | `DAT_140e44ad0` | `DAT_140e44ad0 + 4 * frame` |
| `media\\stage\\Boss.png` | `dxlib_load_div_graph_candidate(..., 0xa0, 10, 0x10, 200, 200, &DAT_140e44310, ...)` | `DAT_140e44310` | `DAT_140e44310 + 4 * frame` |

## Stage 1 enemy body frame mapping

| Spawn type | Helper | Runtime atlas/frame | Original globals / evidence |
|---:|---|---|---|
| `0x06`, `0x08` | `FUN_140082d90` | `Enemy_m` frames `8..10` for marker core | `DAT_140e44af0`, `DAT_140e44af4`, `DAT_140e44af8` in `140082d90_FUN_140082d90.c:252-465` |
| `0x09` | `FUN_140083db0` | `Enemy_m` frame `11` scaffold | `DAT_140e44afc` in `stage-entity-list-refs/global-key-ref-decompiled/140083db0_FUN_140083db0.c:86-88` |
| `0x0a` | `FUN_14007c9c0` | `Enemy_m` frame `15` plus dynamic indexed frame | `DAT_140e44b0c` and `(&DAT_140e44ad0)[iVar5]` in `14007c9c0_FUN_14007c9c0.c:320-331` |
| `0x0b` | `FUN_14007d4e0` | `Enemy_s` frames `4..5` | `DAT_140e44670`, `DAT_140e44674` in `14007d4e0_FUN_14007d4e0.c:244-262` |
| `0x0c` | `FUN_14007dfb0` | `Enemy_s` frames `6..8` | `DAT_140e44678`, `DAT_140e4467c`, `DAT_140e44680` in `14007dfb0_FUN_14007dfb0.c:311-320` |
| `0x0d` | `FUN_14007ea30` | `Enemy_s` frames `9..10` | `DAT_140e44684`, `DAT_140e44688` in `14007ea30_FUN_14007ea30.c:236-257` |
| `0x0e` | `FUN_14007f2c0` | `Enemy_m` frames `16..21` | `DAT_140e44b10..DAT_140e44b24` in `14007f2c0_FUN_14007f2c0.c:340-368` |
| `0x0f` | `FUN_140080170` | `Enemy_m` frames `22..25` | `DAT_140e44b28..DAT_140e44b34` in `140080170_FUN_140080170.c:416-430` |
| `0x10` | `FUN_140080fb0` | `Enemy_m` frames `26..31` | `DAT_140e44b38..DAT_140e44b4c` in `140080fb0_FUN_140080fb0.c:443-468` |
| `0x11` | `FUN_140082090` | `Enemy_m` frames `32..33` | `DAT_140e44b50`, `DAT_140e44b54` in `140082090_FUN_140082090.c:318-431` |
| `0x138` | `FUN_140004660` | `Boss.png` scaffold frame `0` | Spawned by Stage 1 handoff; full boss helper not ported. |

Runtime status:

- `stage_runtime.cpp` now loads `Boss.png` and uses `enemyVisualFrameForSpawnType()` / `enemyUsesMediumFrame()` for Stage 1 frame selection.
- `0x09`, `0x11`, and `0x138` are recognized by Stage 1-specific routing instead of generic fallback.

## Decoded Stage 1 projectile/scalar constants

These values were recovered from `LikeDreamer.exe` `.rdata` and are used by Stage 1 helper calls to `FUN_14006c2f0` / `FUN_1400709b0`.

| Global | Value |
|---|---:|
| `DAT_14053a018` | `3.0` |
| `DAT_14053a040` | `3.5` |
| `DAT_14053a070` | `4.0` |
| `DAT_14053a088` | `4.5` |
| `DAT_14053a0a0` | `4.8` |
| `DAT_14053a0b0` | `5.0` |
| `DAT_14053a0d0` | `5.5` |
| `DAT_14053a0f8` | `6.0` |
| `DAT_14053a118` | `6.5` |
| `DAT_14053a138` | `7.0` |
| `DAT_14053a158` | `7.5` |
| `DAT_14053a178` | `8.0` |
| `DAT_14053a190` | `8.5` |
| `DAT_14053a1b8` | `9.0` |
| `DAT_14053a1c8` | `9.5` |
| `DAT_14053a208` | `11.0` |

Runtime status:

- `stage_runtime.cpp` now has `stage01SpeedConstantValue()` and maps Stage 1 projectile speed tables through decoded `DAT_14053a*` values for key helpers (`0x0a..0x0d`, marker, and long setpieces) instead of the older purely invented low-speed fallbacks.
- Some movement/effect scale constants outside this monotonic ladder remain unresolved.

## Stage 1 marker child/satellite mapping

`FUN_140082d90` has two distinct child-like behaviors:

1. It spawns type `0x09` satellite/helper nodes with `stage_entity_spawn_candidate(9, 3000, ...)` at `140082d90_FUN_140082d90.c:92-94` and `:128-130`.
2. Type `0x09` dispatches through case `0x3` to `FUN_140083db0`; that helper resolves its parent id, renders `DAT_140e44afc`, and spawns reward type `7` when its parent is gone (`140083db0_FUN_140083db0.c:31-43`, `:86-102`).

Runtime status:

- `spawnStage01MarkerSatellite()` and `updateStage01MarkerSatellite()` now scaffold this route as Stage 1 type `0x09`.
- The previously added `0x11` marker children remain as an explicit approximation for visible anchor/projectile behavior; exact original marker child counts/route branches remain deferred.

## Stage 1 boss handoff

Evidence: `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/140118420_stage_01_gameplay_update_candidate.c:240-317`.

- Stage length table `UNK_140538ad8` / `DAT_140538ad8` has Stage 1 index `1` value `5700`.
- `endFrame - 300` = `5400`: allocate effect type `0x16`.
- `endFrame - 0x168 .. endFrame - 0xf0` = `5336..5459`: background/transition ramp.
- `endFrame - 300 .. endFrame` = `5400..5700`: cleanup tick via `FUN_140001060()`.
- `endFrame` = `5700`: flush stage entities/effects and reset background handles.
- `endFrame + 0x3c` = `5760`: direct spawn `stage_entity_spawn_candidate(0x138, 100000, ..., x=DAT_14053ae30, y=DAT_14053adb4, ..., field_50=0xa0, ..., parent/link=0)`, then boss globals are initialized.

Runtime status:

- `stage_runtime.cpp` now uses `stage01EndFrame_ = 5700` and scaffolds end visual/cleanup flags plus boss handoff spawn `0x138` at frame `5760`.
- `0x138` is treated as a boss scaffold and uses `Boss.png`; full `FUN_140004660` boss behavior remains deferred.

## Deferred original systems

- Exact `FUN_1400c8410` `0x48` overlay-node lifecycle and draw ordering.
- Exact `0x60` effect-node dispatcher for type `0x16` / type `0x17` visuals.
- Full `FUN_140004660` boss pattern port for entity `0x138`.
- Exact marker child/satellite counts for every route/difficulty combination.
- Exact named semantics of reward stock/life/guard HUD values.
