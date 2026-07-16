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

`FUN_1400c2670` is now exported at
`reverse/ghidra-or-ida/exports/background-helper-exact/1400c2670_FUN_1400c2670.c`.
Its first argument selects one of four persistent `float` scroll slots at
`DAT_140e46a28`; each call adds `DAT_1407c77a4 * speed`, stores the unrounded
value, truncates it to an integer modulo `0xa00`, and enqueues three copies at
`y`, `y + 0xa00`, and `y - 0xa00`. The draw nodes use horizontal scale `1.005`,
vertical scale `1.0`, and logical x `360`; renderer `FUN_1400c8530` adds the
playfield origin (`280`) before drawing.

Stage 1 case `1` uses these exact layers:

| slot | resource frame | draw layer/type | color / alpha | speed multiplier |
|---:|---:|---|---|---:|
| `0` | `StageBack1[2]` | `4 / 0x0e` | white; alpha `255` before frame `300`, `sin(frame*pi/600)*255` at `300..599`, zero at `600`; absent afterward | `2.0` |
| `1` | `StageBack1[4]` | `1 / 0x0e` | white / `255` | `0.5` |
| `2` | `StageBack1[5]` | `3 / 0x0e` | white / `255` | `1.0` |
| `3` | `StageBack1[3]` | `5 / 0x0e` additive | white / `128` | `3.0` |

The common speed is `10.0` before frame `600`, follows a quarter-sine to
`2.5` over frames `600..839`, remains `2.5` through frame `5399`, returns to
`10.0` over frames `5400..5699`, and is `10.0` afterward. This is the exact
`FUN_140134b10(frame, 600, 840, 5400, 5700, 10.0, 2.5)` result.

## Runtime status

`reverse/reconstructed/project/src/stage_runtime.cpp` loads all five original
background sheets and now implements the Stage 1 case table above. The former
720-pixel tiling, frame-`840` animation strip, and frame-`1560` fade were
temporary behavior with no EXE callsite and have been removed.
