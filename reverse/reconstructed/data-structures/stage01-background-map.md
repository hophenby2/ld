# Stage 01 background resource/draw map

This file records only logic that is directly anchored in the original executable decompile or in the reconstructed runtime implementation.

## Primary resource load block

Evidence: `reverse/ghidra-or-ida/exports/decompiled-anchors/1400ced90_FUN_1400ced90.c:108-117` and renamed copy `reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c:147-160`.

| global base | logical path | LoadDivGraph args | role in reconstructed runtime |
|---|---|---:|---|
| `DAT_140e469b0` | `media\\stage\\StageBack1.png` | `10, 10, 1, 0x2d0, 0xa00` | base tall Stage 1 rear layer |
| `DAT_140e46ab8` | `media\\stage\\StageBack1b.png` | `10, 10, 1, 0x2d0, 0xa00` | additional tall Stage 1 dynamic layer |
| `DAT_140e469d8` | `media\\stage\\StageBack1c.png` | `0x0c, 0x0c, 1, 0x2d0, 0xa00` | 12-frame tall Stage 1 dynamic layer |
| `DAT_140e45178` | `media\\stage\\StageBack1d.png` | `10, 10, 1, 0x2d0, 0xa00` | later tall Stage 1 dynamic layer |
| `DAT_140e450d8` | `media\\stage\\StageBack2.png` | `10, 10, 1, 0x2d0, 0x2d0` | 720-high scrolling rear layer |

The previous reconstructed runtime loaded only `StageBack1.png` and `StageBack2.png`; this could never reproduce the original dynamic rear background.

## Original draw references

Evidence: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400be7a0_FUN_1400be7a0.c`.

| case / segment | draw evidence | confirmed resource use |
|---|---|---|
| default early background | `:90-97` | draws `DAT_140e469b0` plus adjacent `DAT_140e469b4` frame |
| case 4 | `:643-645` | draws `DAT_140e46ab8` plus adjacent `DAT_140e46abc` frame |
| case 7 | `:915-946` | draws `DAT_140e469d8`, adjacent StageBack1/1c handles, and transition alpha |
| later case using 1d | grep hits at `:1565` and `:1646` | draws `DAT_140e45178` |

`FUN_1400c2670` appears to enqueue/draw background/effect nodes with layer index, handle, blend/effect selector, alpha/color, and scale. Exact numeric constants still need naming before claiming a bit-for-bit background timeline.

## Runtime status

`reverse/reconstructed/project/src/stage_runtime.cpp` now loads all five original Stage 1 background resources. Its current draw implementation is still an approximate reconstruction: scroll, timing, alpha ramps, and layer composition are not yet claimed exact because `FUN_1400c2670` and the case timeline in `FUN_1400be7a0` have not been fully reduced to a verified table.
