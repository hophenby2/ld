# Stage Spawn Schedule Extract

Status: raw extraction from renamed Ghidra decompilation; not original source. Frame conditions are captured as nearby decompiler context and require manual validation.

Source directory: `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/`.

## Summary counts

| Stage | spawn calls | banner/helper calls | total extracted calls |
|---:|---:|---:|---:|
| `01` | 27 | 1 | 28 |
| `02` | 56 | 1 | 57 |
| `03` | 50 | 1 | 51 |
| `04` | 76 | 1 | 77 |
| `05` | 91 | 1 | 92 |
| `06` | 72 | 1 | 73 |
| `07` | 57 | 1 | 58 |
| `08` | 148 | 1 | 149 |
| `09` | 81 | 1 | 82 |
| `10` | 70 | 0 | 70 |
| `00` | 25 | 46 | 71 |

## Raw schedule by stage

### Stage `01`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 27 | `stage_spawn_dispatch_candidate` | `10,0x960,0x1e0,0x96` | `if (DAT_140e451a4 != 0) { \| if (DAT_140e418c8 == 200) {` |
| 30 | `stage_spawn_dispatch_candidate` | `10,0x960,0xf0,200` | `if (DAT_140e451a4 != 0) { \| if (DAT_140e418c8 == 200) { \| if (DAT_140e418c8 == 0x104) {` |
| 33 | `stage_spawn_dispatch_candidate` | `10,2000,0x208,100` | `if (DAT_140e418c8 == 200) { \| if (DAT_140e418c8 == 0x104) { \| if (DAT_140e418c8 == 0x15e) {` |
| 36 | `stage_spawn_dispatch_candidate` | `10,2000,0x168,100` | `if (DAT_140e418c8 == 0x104) { \| if (DAT_140e418c8 == 0x15e) { \| if (DAT_140e418c8 == 0x16d) {` |
| 39 | `stage_spawn_dispatch_candidate` | `10,2000,200,100` | `if (DAT_140e418c8 == 0x15e) { \| if (DAT_140e418c8 == 0x16d) { \| if (DAT_140e418c8 == 0x17c) {` |
| 50 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x12d + 0x3c,0xffffffec` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 54 | `stage_spawn_dispatch_candidate` | `6,5000,0x1cc,0` | `if ((int)uVar7 == 700) {` |
| 58 | `stage_spawn_dispatch_candidate` | `0xe,10000,0x118,0` | `if ((int)uVar7 == 700) { \| if ((int)uVar7 == 900) {` |
| 62 | `stage_spawn_dispatch_candidate` | `0xe,10000,0x1cc,0` | `if ((int)uVar7 == 900) { \| if ((int)uVar7 == 0x44c) {` |
| 73 | `stage_spawn_dispatch_candidate` | `0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 84 | `stage_spawn_dispatch_candidate` | `0xd,700,0x2e4,DAT_140e9fd1c % 0x65 + 0xfa` | `if ((uVar4 < 300) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 95 | `stage_spawn_dispatch_candidate` | `0xb,500,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 106 | `stage_spawn_dispatch_candidate` | `0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 110 | `stage_spawn_dispatch_candidate` | `0xf,8000,0x348,0x96` | `if ((int)uVar7 == 0x898) {` |
| 121 | `stage_spawn_dispatch_candidate` | `0xd,700,0xffffffec,DAT_140e9fd1c % 0x65 + 0xfa` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 132 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 137 | `stage_spawn_dispatch_candidate` | `0x10,40000,0x168,0x50` | `if (uVar4 == 0xabe) {` |
| 155 | `stage_spawn_dispatch_candidate` | `0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((((int)uVar4 < 0xdde) && (iVar3 = (int)(uVar4 - 0xaf0) % 0x96, iVar3 < 100)) &&` |
| 159 | `stage_spawn_dispatch_candidate` | `0xe,7000,0x168,0` | `if ((int)uVar7 == 0xe10) {` |
| 173 | `stage_spawn_dispatch_candidate` | `0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if (((int)uVar4 < 0xf78) && (uVar4 - 0xed8 == ((int)(uVar4 - 0xed8) / 0x14) * 0x14)) {` |
| 185 | `stage_spawn_dispatch_candidate` | `0xd,500,0xffffffec,DAT_140e9fd1c % 0x65 + 300` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 189 | `stage_spawn_dispatch_candidate` | `0xe,7000,0x1cc,0` | `if ((int)uVar7 == 0x1068) {` |
| 193 | `stage_spawn_dispatch_candidate` | `0xf,8000,0xffffff88,100` | `if ((int)uVar7 == 0x1068) { \| if ((int)uVar7 == 0x1108) {` |
| 209 | `stage_spawn_dispatch_candidate` | `0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if (uVar4 == 0) {` |
| 221 | `stage_spawn_dispatch_candidate` | `0xd,500,0xffffffec,DAT_140e9fd1c % 0x65 + 0xfa` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 233 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0xc9 + 0x168,0xffffffec` | `if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 237 | `stage_spawn_dispatch_candidate` | `8,5000,0x104,0` | `if (uVar4 == 0x13ec) {` |
| 25 | `stage_intro_banner_event_candidate` | `iVar3,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `if (DAT_140e451a4 != 0) {` |

### Stage `02`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 54 | `stage_spawn_dispatch_candidate` | `0x19,800,DAT_140e418c8 * 4 + -0x398,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 65 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0xfb + 0x104,0xffffffec` | `if ((uVar3 < 0xbe) && (uVar3 == ((int)uVar3 / 0xe) * 0xe)) {` |
| 69 | `stage_spawn_dispatch_candidate` | `7,5000,0x104,0` | `if ((int)uVar4 == 700) {` |
| 100 | `stage_spawn_dispatch_candidate` | `0x1d,0x6a4,(int)*(float *)(&local_a8 + uVar4), (int)*(float *)((longlong)&local_a8 + uVar4 * 8 + 4)` | `` |
| 107 | `stage_spawn_dispatch_candidate` | `0x1e,0x834,(int)*(float *)(&local_d8 + uVar5), (int)*(float *)((longlong)&local_d8 + uVar5 * 8 + 4)` | `` |
| 112 | `stage_spawn_dispatch_candidate` | `0x1f,11000,0x1e4,0xfffff242` | `` |
| 123 | `stage_spawn_dispatch_candidate` | `0xb,400,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 127 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0x104,0` | `if ((int)uVar4 == 0x6a4) {` |
| 131 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0x1cc,0` | `if ((int)uVar4 == 0x6a4) { \| if ((int)uVar4 == 0x708) {` |
| 142 | `stage_spawn_dispatch_candidate` | `0xd,400,0xffffffec,DAT_140e9fd1c % 0x65 + 0x96` | `if ((uVar3 < 200) && (uVar3 == ((int)uVar3 / 0x19) * 0x19)) {` |
| 153 | `stage_spawn_dispatch_candidate` | `0x19,500,DAT_140e9fd1c % 0xc9 + 0x168,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 164 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec` | `if ((uVar3 < 0x32) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 168 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0xf0,0` | `if ((int)uVar4 == 0x8ca) {` |
| 179 | `stage_spawn_dispatch_candidate` | `0xb,400,0x2e4,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 190 | `stage_spawn_dispatch_candidate` | `0xb,400,0xffffffec,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 194 | `stage_spawn_dispatch_candidate` | `0x1c,6000,0x348,0x32` | `if ((int)uVar4 == 0xa28) {` |
| 205 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec` | `if ((uVar3 < 0xa0) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {` |
| 209 | `stage_spawn_dispatch_candidate` | `0x1c,6000,0xffffff88,100` | `if ((int)uVar4 == 0xb54) {` |
| 220 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {` |
| 231 | `stage_spawn_dispatch_candidate` | `0x19,700,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 235 | `stage_spawn_dispatch_candidate` | `0x1b,4000,0x168,0` | `if ((int)uVar4 == 0xce4) {` |
| 239 | `stage_spawn_dispatch_candidate` | `0x1b,4000,0x1fe,0` | `if ((int)uVar4 == 0xce4) { \| if ((int)uVar4 == 0xd34) {` |
| 250 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {` |
| 254 | `stage_spawn_dispatch_candidate` | `0x1c,5000,0x348,0x50` | `if ((int)uVar4 == 0xe74) {` |
| 265 | `stage_spawn_dispatch_candidate` | `0x19,700,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar3 < 0x8c) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 276 | `stage_spawn_dispatch_candidate` | `0xb,400,0xffffffec,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 0x6e) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {` |
| 280 | `stage_spawn_dispatch_candidate` | `0x1b,0xe10,0x1e0,0` | `if ((int)uVar4 == 0x1248) {` |
| 284 | `stage_spawn_dispatch_candidate` | `0x1b,0xe10,0xf0,0` | `if ((int)uVar4 == 0x1248) { \| if ((int)uVar4 == 0x1298) {` |
| 295 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec` | `if ((uVar3 < 0x28) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 299 | `stage_spawn_dispatch_candidate` | `0x1c,0x1068,0x348,0x50` | `if ((int)uVar4 == 0x1306) {` |
| 303 | `stage_spawn_dispatch_candidate` | `0x1c,0x1068,0xffffff88,0x50` | `if ((int)uVar4 == 0x1306) { \| if ((int)uVar4 == 0x136a) {` |
| 307 | `stage_spawn_dispatch_candidate` | `0x1c,0x1068,0x348,0x50` | `if ((int)uVar4 == 0x136a) { \| if ((int)uVar4 == 0x13ce) {` |
| 323 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x259 + 0x3c,0` | `if (uVar3 == 0) {` |
| 329 | `stage_spawn_dispatch_candidate` | `0x20,0x2b5c,0x168,0xfffffe0c` | `if (uVar3 == 0x14b4) {` |
| 342 | `stage_spawn_dispatch_candidate` | `10,1000,DAT_140e9fd1c % 0x1f5 + 0x6e,0x32` | `if ((uVar9 < 0x154) && (uVar9 == ((int)uVar9 / 0x50) * 0x50)) {` |
| 358 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x259 + 0x3c,0` | `if (uVar3 != 0) goto LAB_14011a9e1;` |
| 365 | `stage_spawn_dispatch_candidate` | `0x19,500,0x6e,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 366 | `stage_spawn_dispatch_candidate` | `0x19,500,0xd2,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 367 | `stage_spawn_dispatch_candidate` | `0x19,500,0x136,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 368 | `stage_spawn_dispatch_candidate` | `0x19,500,0x19a,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 369 | `stage_spawn_dispatch_candidate` | `0x19,500,0x1fe,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 370 | `stage_spawn_dispatch_candidate` | `0x19,500,0x262,0xffffffec` | `if ((((iVar8 == 0x1978) \|\| (iVar8 == 0x19dc)) \|\| (iVar8 == 0x1a40)) \|\|` |
| 381 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0xfb + 0x6e,0xffffffec` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 392 | `stage_spawn_dispatch_candidate` | `0xb,400,0x2e4,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 396 | `stage_spawn_dispatch_candidate` | `0x1b,0xc80,0x230,0` | `if ((int)uVar4 == 0x1bbc) {` |
| 400 | `stage_spawn_dispatch_candidate` | `0x1b,0xc80,0x168,0` | `if ((int)uVar4 == 0x1bbc) { \| if ((int)uVar4 == 0x1bee) {` |
| 404 | `stage_spawn_dispatch_candidate` | `0x1b,0xc80,0xa0,0` | `if ((int)uVar4 == 0x1bee) { \| if ((int)uVar4 == 0x1c20) {` |
| 430 | `stage_spawn_dispatch_candidate` | `0x1d,0x5dc,(int)*(float *)(&local_a8 + uVar4), (int)*(float *)((longlong)&local_a8 + uVar4 * 8 + 4)` | `` |
| 436 | `stage_spawn_dispatch_candidate` | `0x1e,2000,(int)*(float *)(&local_d8 + uVar6), (int)*(float *)((longlong)&local_d8 + uVar6 * 8 + 4)` | `` |
| 441 | `stage_spawn_dispatch_candidate` | `0x1f,8000,0x104,0xfffffcd6` | `` |
| 442 | `stage_spawn_dispatch_candidate` | `0x1f,8000,0x1f9,0xfffffa6f` | `` |
| 443 | `stage_spawn_dispatch_candidate` | `0x1f,8000,0xe6,0xfffff8e4` | `` |
| 460 | `stage_spawn_dispatch_candidate` | `0x19,500,DAT_140e9fd1c % 0x15f + 0xa0,0xffffffec` | `if (uVar3 == 0) {` |
| 465 | `stage_spawn_dispatch_candidate` | `0x1c,6000,0xffffff88,100` | `if ((int)uVar4 == 0x2080) {` |
| 477 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x12d + 0x6e,0xffffffec` | `if ((uVar9 < 0x82) && (uVar9 == ((int)uVar9 / 0xc) * 0xc)) {` |
| 481 | `stage_spawn_dispatch_candidate` | `8,5000,0x1cc,0` | `if (uVar3 == 0x238c) {` |
| 49 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `03`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 44 | `stage_spawn_dispatch_candidate` | `0x25,700,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x23) * 0x23)) {` |
| 48 | `stage_spawn_dispatch_candidate` | `0x26,5000,0x208,0xffffffec` | `if ((int)uVar5 == 500) {` |
| 52 | `stage_spawn_dispatch_candidate` | `0x26,5000,200,0xffffffec` | `if ((int)uVar5 == 500) { \| if ((int)uVar5 == 600) {` |
| 63 | `stage_spawn_dispatch_candidate` | `0x25,600,DAT_140e9fd1c % 0x1a5 + 0xb4,0xffffffec` | `if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x18) * 0x18)) {` |
| 67 | `stage_spawn_dispatch_candidate` | `0x27,7000,0x21c,300` | `if ((int)uVar5 == 0x3ac) {` |
| 71 | `stage_spawn_dispatch_candidate` | `0x29,7000,0xb4,0xfa` | `if ((int)uVar5 == 0x3ac) { \| if ((int)uVar5 == 0x47e) {` |
| 75 | `stage_spawn_dispatch_candidate` | `7,5000,0x1cc,0` | `if ((int)uVar5 == 0x47e) { \| if ((int)uVar5 == 0x546) {` |
| 87 | `stage_spawn_dispatch_candidate` | `0x2c,0x640,(int)*(float *)(&local_68 + uVar5), (int)*(float *)((longlong)&local_68 + uVar5 * 8 + 4)` | `` |
| 92 | `stage_spawn_dispatch_candidate` | `0x2d,6000,0x1ea,0xfffffda8` | `` |
| 103 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0xc9 + 0xa0,0xffffffec` | `if ((uVar4 < 500) && (uVar4 == ((int)uVar4 / 0x30) * 0x30)) {` |
| 119 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96` | `if (uVar4 == 0) {` |
| 124 | `stage_spawn_dispatch_candidate` | `0x29,6000,0x1e0,300` | `if ((int)uVar5 == 0x992) {` |
| 135 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 140 | `stage_spawn_dispatch_candidate` | `0x2e,65000,0x168,0xffffff88` | `if (uVar4 == 0xb40) {` |
| 152 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0x141 + 200,0xffffffec` | `if ((DAT_140e418cc != 0) \|\| (uVar8 = uVar4 - 3000, 0x513 < uVar8)) goto LAB_14011bc5f; \| if (uVar8 == ((int)uVar8 / 0x2d) * 0x2d) {` |
| 163 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((0x513 < uVar4) \|\| (uVar4 != ((int)uVar4 / 0x15) * 0x15)) goto LAB_14011bc5f;` |
| 175 | `stage_spawn_dispatch_candidate` | `0x2c,0x5dc,(int)*(float *)(&local_68 + uVar5), (int)*(float *)((longlong)&local_68 + uVar5 * 8 + 4)` | `if ((int)uVar5 == 0x1130) {` |
| 180 | `stage_spawn_dispatch_candidate` | `0x2d,0x1518,0xd2,0xffffff1f` | `` |
| 181 | `stage_spawn_dispatch_candidate` | `0x2d,0x1518,0x113,0xfffffdbc` | `` |
| 184 | `stage_spawn_dispatch_candidate` | `0x26,5000,0x21c,0xffffffec` | `if (DAT_140e418c8 == 0x1130) {` |
| 196 | `stage_spawn_dispatch_candidate` | `0xb,300,0x2e4,DAT_140e9fd1c % 0x97 + 0x96` | `if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0xc) * 0xc)) {` |
| 207 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 211 | `stage_spawn_dispatch_candidate` | `0x26,4000,0xd2,0xffffffec` | `if ((int)uVar5 == 0x14a0) {` |
| 215 | `stage_spawn_dispatch_candidate` | `0x27,7000,0x21c,300` | `if ((int)uVar5 == 0x14a0) { \| if ((int)uVar5 == 0x1518) {` |
| 219 | `stage_spawn_dispatch_candidate` | `0x2b,12000,0x1b8,0` | `if ((int)uVar5 == 0x1518) { \| if ((int)uVar5 == 0x15e0) {` |
| 230 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x15f + 0x6e,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xc) * 0xc)) {` |
| 234 | `stage_spawn_dispatch_candidate` | `0x26,5000,0x168,0xffffffec` | `if ((int)uVar5 == 0x170c) {` |
| 245 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x19) * 0x19)) {` |
| 249 | `stage_spawn_dispatch_candidate` | `0x26,5000,200,0xffffffec` | `if ((int)uVar5 == 0x17d4) {` |
| 260 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec` | `if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 264 | `stage_spawn_dispatch_candidate` | `0x26,5000,0x208,0xffffffec` | `if ((int)uVar5 == 0x189c) {` |
| 275 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec` | `if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 279 | `stage_spawn_dispatch_candidate` | `0x26,4000,0xf0,0xffffffec` | `if ((int)uVar5 == 0x1946) {` |
| 283 | `stage_spawn_dispatch_candidate` | `0x26,4000,0x1e0,0xffffffec` | `if ((int)uVar5 == 0x1946) { \| if ((int)uVar5 == 0x1964) {` |
| 287 | `stage_spawn_dispatch_candidate` | `0x29,4000,0xf0,300` | `if ((int)uVar5 == 0x1964) { \| if ((int)uVar5 == 0x19f0) {` |
| 291 | `stage_spawn_dispatch_candidate` | `0x29,4000,0x1e0,0xfa` | `if ((int)uVar5 == 0x19f0) { \| if ((int)uVar5 == 0x1a2c) {` |
| 302 | `stage_spawn_dispatch_candidate` | `0x25,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0x5a) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {` |
| 306 | `stage_spawn_dispatch_candidate` | `0x2b,12000,0x118,0` | `if ((int)uVar5 == 7000) {` |
| 317 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0xf0) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {` |
| 333 | `stage_spawn_dispatch_candidate` | `0x2c,0x578,(int)*(float *)(&local_68 + uVar6), (int)*(float *)((longlong)&local_68 + uVar6 * 8 + 4)` | `` |
| 338 | `stage_spawn_dispatch_candidate` | `0x2d,0x1068,0xa5,0xfffffea2` | `` |
| 339 | `stage_spawn_dispatch_candidate` | `0x2d,0x1068,0x235,0xfffffda3` | `` |
| 350 | `stage_spawn_dispatch_candidate` | `0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 0x186) && (uVar4 == ((int)uVar4 / 0x32) * 0x32)) {` |
| 361 | `stage_spawn_dispatch_candidate` | `0x25,400,DAT_140e9fd1c % 0xc9 + 0x104,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 365 | `stage_spawn_dispatch_candidate` | `0x26,6000,0x168,0xffffffec` | `if ((int)uVar5 == 0x2008) {` |
| 369 | `stage_spawn_dispatch_candidate` | `0x27,6000,0x1e0,300` | `if ((int)uVar5 == 0x2008) { \| if ((int)uVar5 == 0x209e) {` |
| 373 | `stage_spawn_dispatch_candidate` | `0x29,5000,0xf0,0xfa` | `if ((int)uVar5 == 0x209e) { \| if ((int)uVar5 == 0x20d0) {` |
| 389 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if (uVar8 == 0) {` |
| 394 | `stage_spawn_dispatch_candidate` | `0x2b,12000,0x1b8,0` | `if (uVar4 == 0x21fc) {` |
| 398 | `stage_spawn_dispatch_candidate` | `8,5000,0x104,0` | `if (uVar4 == 0x21fc) { \| if (uVar4 == 0x22f6) {` |
| 33 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `04`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 33 | `stage_spawn_dispatch_candidate` | `0x37,500,DAT_140e9fd1c % 0x191 + 0xa0, ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400` | `if ((uVar3 < 0x15e) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 45 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x96` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 50 | `stage_spawn_dispatch_candidate` | `0x38,5000,0x1e0,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 800) {` |
| 60 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0x96` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 65 | `stage_spawn_dispatch_candidate` | `0x38,5000,0xf0,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 1000) {` |
| 75 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,400` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 86 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,400` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 104 | `stage_spawn_dispatch_candidate` | `0x37,500,DAT_140e9fd1c % 0x191 + 0xa0, ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400` | `if (uVar3 == 0) {` |
| 111 | `stage_spawn_dispatch_candidate` | `7,5000,0x1cc,0` | `if ((int)uVar7 == 0x578) {` |
| 115 | `stage_spawn_dispatch_candidate` | `0x3d,9000,0xffffff38,0x96` | `if ((int)uVar7 == 0x578) { \| if ((int)uVar7 == 0x60e) {` |
| 126 | `stage_spawn_dispatch_candidate` | `0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0x226) && (uVar3 == ((int)uVar3 / 0x78) * 0x78)) {` |
| 137 | `stage_spawn_dispatch_candidate` | `0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0x1ea) && (uVar3 == ((int)uVar3 / 0x78) * 0x78)) {` |
| 141 | `stage_spawn_dispatch_candidate` | `0x38,4000,500,0` | `if ((int)uVar7 == 0x708) {` |
| 145 | `stage_spawn_dispatch_candidate` | `0x38,4000,0xdc,0` | `if ((int)uVar7 == 0x708) { \| if ((int)uVar7 == 0x76c) {` |
| 149 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0x398,0x96` | `if ((int)uVar7 == 0x76c) { \| if ((int)uVar7 == 0x834) {` |
| 153 | `stage_spawn_dispatch_candidate` | `0x38,0x1194,0xf0,0` | `if ((int)uVar7 == 0x834) { \| if ((int)uVar7 == 0x8fc) {` |
| 157 | `stage_spawn_dispatch_candidate` | `0x38,0x1194,0x1e0,0` | `if ((int)uVar7 == 0x8fc) { \| if ((int)uVar7 == 0x960) {` |
| 167 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0x78` | `if (uVar3 < 0x50) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 172 | `stage_spawn_dispatch_candidate` | `0x3a,10000,0xffffffb0,200` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0xa5a) {` |
| 176 | `stage_spawn_dispatch_candidate` | `0x39,8000,0x262,0xffffffb0` | `if ((int)uVar7 == 0xa5a) { \| if ((int)uVar7 == 0xb22) {` |
| 180 | `stage_spawn_dispatch_candidate` | `0x39,8000,0x6e,0xffffffb0` | `if ((int)uVar7 == 0xb22) { \| if ((int)uVar7 == 0xbea) {` |
| 184 | `stage_spawn_dispatch_candidate` | `0x3a,8000,800,200` | `if ((int)uVar7 == 0xbea) { \| if ((int)uVar7 == 0xcb2) {` |
| 196 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec` | `if (((uVar3 < 600) && (iVar4 = (int)uVar3 % 200, iVar4 < 0x3c)) &&` |
| 208 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0xf1 + 0x78,0xffffffec` | `if (((uVar3 < 500) && (iVar4 = (int)uVar3 % 200, iVar4 < 0x3c)) &&` |
| 219 | `stage_spawn_dispatch_candidate` | `0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0x46) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 230 | `stage_spawn_dispatch_candidate` | `0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 235 | `stage_spawn_dispatch_candidate` | `0x3f,48000,0x167,0` | `if (iVar4 == 0xe10) {` |
| 256 | `stage_spawn_dispatch_candidate` | `0x35,200,0x2e4,0x8c` | `if (0x95 < iVar4 - 0x1194U) goto LAB_14011d9fc; \| if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14011d9fc;` |
| 257 | `stage_spawn_dispatch_candidate` | `0x35,200,0xffffffec,0x8c` | `if (0x95 < iVar4 - 0x1194U) goto LAB_14011d9fc; \| if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14011d9fc;` |
| 262 | `stage_spawn_dispatch_candidate` | `0x3d,9000,0xffffff38,0x96` | `if (uVar3 != 0) goto LAB_14011d9fc; \| if ((int)uVar7 == 0x125c) {` |
| 273 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 285 | `stage_spawn_dispatch_candidate` | `0x37,500,DAT_140e9fd1c % 0x1e1 + 0x78, ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400` | `if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 291 | `stage_spawn_dispatch_candidate` | `0x38,6000,0x1cc,0` | `if ((int)uVar7 == 0x157c) {` |
| 295 | `stage_spawn_dispatch_candidate` | `0x38,6000,0x104,0` | `if ((int)uVar7 == 0x157c) { \| if ((int)uVar7 == 0x15ae) {` |
| 305 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,400` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 310 | `stage_spawn_dispatch_candidate` | `0x38,5000,0x1fe,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x16a8) {` |
| 320 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,400` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 325 | `stage_spawn_dispatch_candidate` | `0x38,5000,0xd2,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x175c) {` |
| 335 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x96` | `if (uVar3 < 0x6e) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 346 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0x96` | `if (uVar3 < 0x6e) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 357 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x15e` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 362 | `stage_spawn_dispatch_candidate` | `0x38,4000,0x1e0,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x1900) {` |
| 363 | `stage_spawn_dispatch_candidate` | `0x38,4000,0xf0,0` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x1900) {` |
| 367 | `stage_spawn_dispatch_candidate` | `0x39,6000,0x6e,0xffffffb0` | `if ((int)uVar7 == 0x1900) { \| if (((int)uVar7 == 0x1964) \|\| ((int)uVar7 == 0x1bbc)) {` |
| 371 | `stage_spawn_dispatch_candidate` | `0x39,6000,0x262,0xffffffb0` | `if (((int)uVar7 == 0x1964) \|\| ((int)uVar7 == 0x1bbc)) { \| if (((int)uVar7 == 0x19fa) \|\| ((int)uVar7 == 0x1c52)) {` |
| 375 | `stage_spawn_dispatch_candidate` | `0x3a,6000,0xffffffb0,200` | `if (((int)uVar7 == 0x19fa) \|\| ((int)uVar7 == 0x1c52)) { \| if (((int)uVar7 == 0x1a90) \|\| ((int)uVar7 == 0x1ce8)) {` |
| 379 | `stage_spawn_dispatch_candidate` | `0x3a,6000,800,200` | `if (((int)uVar7 == 0x1a90) \|\| ((int)uVar7 == 0x1ce8)) { \| if (((int)uVar7 == 0x1b26) \|\| ((int)uVar7 == 0x1d7e)) {` |
| 391 | `stage_spawn_dispatch_candidate` | `0x37,500,DAT_140e9fd1c % 0x1e1 + 0x78, ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400` | `if ((uVar3 < 0x47e) && (uVar3 == ((int)uVar3 / 0x4b) * 0x4b)) {` |
| 409 | `stage_spawn_dispatch_candidate` | `0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300` | `if (uVar3 == 0) {` |
| 421 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 437 | `stage_spawn_dispatch_candidate` | `0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300` | `if (uVar3 == 0) {` |
| 449 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,0x2e4,DAT_140e9fd1c % 0x97 + 0x96` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 453 | `stage_spawn_dispatch_candidate` | `0x38,5000,0xdc,0` | `if ((int)uVar7 == 0x2008) {` |
| 457 | `stage_spawn_dispatch_candidate` | `0x38,5000,500,0` | `if ((int)uVar7 == 0x2008) { \| if ((int)uVar7 == 0x203a) {` |
| 467 | `stage_spawn_dispatch_candidate` | `0x35,200,0x2e4,0x96` | `if (uVar3 < 0x96) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 468 | `stage_spawn_dispatch_candidate` | `0x35,200,0xffffffec,0x96` | `if (uVar3 < 0x96) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 473 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0x398,0x78` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x2198) {` |
| 484 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,0xffffffec,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 488 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0xffffff38,0x96` | `if ((int)uVar7 == 0x2260) {` |
| 499 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,0x2e4,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 503 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0x398,0xb4` | `if ((int)uVar7 == 9000) {` |
| 507 | `stage_spawn_dispatch_candidate` | `0x38,5000,200,0` | `if ((int)uVar7 == 9000) { \| if ((int)uVar7 == 0x238c) {` |
| 517 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0xb4` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 522 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0x398,0x96` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x2454) {` |
| 532 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0x15e` | `if (uVar3 < 100) { \| if ((int)uVar3 < 0) { \| if (uVar3 == 0) {` |
| 537 | `stage_spawn_dispatch_candidate` | `0x3d,7000,0xffffff38,0x78` | `if (uVar3 == 0) { \| if ((int)uVar7 == 0x251c) {` |
| 541 | `stage_spawn_dispatch_candidate` | `0x39,6000,0x262,0xffffffb0` | `if ((int)uVar7 == 0x251c) { \| if ((int)uVar7 == 0x2580) {` |
| 552 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 556 | `stage_spawn_dispatch_candidate` | `0x3f,44000,0x169,0` | `if ((int)uVar7 == 0x2648) {` |
| 568 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec` | `if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 580 | `stage_spawn_dispatch_candidate` | `0x38,5000,DAT_140e9fd1c % 0x169 + 0xb4,0` | `if ((((DAT_140e418cc == 0) && (uVar3 - 0x25e4 < 0x3e9)) && (uVar6 = uVar3 - 0x2648, uVar6 < 0x385)` |
| 584 | `stage_spawn_dispatch_candidate` | `0x38,4000,0x1e0,0` | `if (uVar3 == 0x2a30) {` |
| 585 | `stage_spawn_dispatch_candidate` | `0x38,4000,0xf0,0` | `if (uVar3 == 0x2a30) {` |
| 594 | `stage_spawn_dispatch_candidate` | `0x35,200,0x2e4,0x78` | `if (uVar3 - 0x2a94 < 0x5a) { \| if ((int)uVar6 < 0) { \| if (uVar6 == 0) {` |
| 604 | `stage_spawn_dispatch_candidate` | `0x35,200,0xffffffec,0x96` | `if (uVar3 - 0x2aee < 0x5a) { \| if ((int)uVar6 < 0) { \| if (uVar6 == 0) {` |
| 609 | `stage_spawn_dispatch_candidate` | `8,5000,0x104,0` | `if (uVar6 == 0) { \| if (uVar3 == 0x2b5c) {` |
| 21 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `05`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 32 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x15f + 0x168,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {` |
| 36 | `stage_spawn_dispatch_candidate` | `0x46,3000,0x42e,0x32` | `if ((int)uVar6 == 0x15e) {` |
| 40 | `stage_spawn_dispatch_candidate` | `0x46,3000,0x366,0` | `if ((int)uVar6 == 0x15e) { \| if ((int)uVar6 == 0x17c) {` |
| 51 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x15f + 10,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {` |
| 55 | `stage_spawn_dispatch_candidate` | `0x46,3000,0xfffffea2,0x32` | `if ((int)uVar6 == 0x226) {` |
| 59 | `stage_spawn_dispatch_candidate` | `0x46,3000,0xffffff6a,0` | `if ((int)uVar6 == 0x226) { \| if ((int)uVar6 == 0x244) {` |
| 70 | `stage_spawn_dispatch_candidate` | `0x45,500,0x2e4,DAT_140e9fd1c % 0x97 + 0x78` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {` |
| 74 | `stage_spawn_dispatch_candidate` | `7,5000,0x1cc,0` | `if ((int)uVar6 == 800) {` |
| 78 | `stage_spawn_dispatch_candidate` | `0x47,3000,0x104,0x96` | `if ((int)uVar6 == 800) { \| if ((int)uVar6 == 900) {` |
| 89 | `stage_spawn_dispatch_candidate` | `0x45,400,DAT_140e9fd1c % 0x97 + 0x19a,0xffffffec` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x1f) * 0x1f)) {` |
| 100 | `stage_spawn_dispatch_candidate` | `0x45,400,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x18) * 0x18)) {` |
| 104 | `stage_spawn_dispatch_candidate` | `0x46,3000,0x3fc,0x32` | `if ((int)uVar6 == 0x4f6) {` |
| 108 | `stage_spawn_dispatch_candidate` | `0x46,3000,0xfffffed4,0x32` | `if ((int)uVar6 == 0x4f6) { \| if ((int)uVar6 == 0x51e) {` |
| 119 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec` | `if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0xe) * 0xe)) {` |
| 123 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffe70,0x32` | `if ((int)uVar6 == 0x640) {` |
| 127 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xffffff06,0x4b` | `if ((int)uVar6 == 0x640) { \| if ((int)uVar6 == 0x65e) {` |
| 131 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xffffff9c,100` | `if ((int)uVar6 == 0x65e) { \| if ((int)uVar6 == 0x67c) {` |
| 135 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x398,0x1e` | `if ((int)uVar6 == 0x67c) { \| if ((int)uVar6 == 0x6b8) {` |
| 139 | `stage_spawn_dispatch_candidate` | `0x4a,11000,0x1cc,0` | `if ((int)uVar6 == 0x6b8) { \| if ((int)uVar6 == 0x708) {` |
| 143 | `stage_spawn_dispatch_candidate` | `0x4a,9000,0x104,0` | `if ((int)uVar6 == 0x708) { \| if ((int)uVar6 == 0x7f8) {` |
| 154 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 158 | `stage_spawn_dispatch_candidate` | `0x4a,9000,0x19a,0` | `if ((int)uVar6 == 0x8e8) {` |
| 169 | `stage_spawn_dispatch_candidate` | `0x45,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {` |
| 173 | `stage_spawn_dispatch_candidate` | `0x4a,9000,0x136,0` | `if ((int)uVar6 == 0x9c4) {` |
| 177 | `stage_spawn_dispatch_candidate` | `0x29,7000,0xf0,300` | `if ((int)uVar6 == 0x9c4) { \| if ((int)uVar6 == 0xa8c) {` |
| 188 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x1c3 + 0x104,0xffffffec` | `if ((uVar4 < 0x32) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 199 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x1c3 + 10,0xffffffec` | `if ((uVar4 < 0x32) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 203 | `stage_spawn_dispatch_candidate` | `0x48,0x960,0x1cc,0x96` | `if ((int)uVar6 == 0xb54) {` |
| 214 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {` |
| 218 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x3fc,100` | `if ((int)uVar6 == 0xc6c) {` |
| 222 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffed4,100` | `if ((int)uVar6 == 0xc6c) { \| if ((int)uVar6 == 0xc80) {` |
| 226 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x42e,0x14` | `if ((int)uVar6 == 0xc80) { \| if ((int)uVar6 == 0xcbc) {` |
| 230 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffea2,0x14` | `if ((int)uVar6 == 0xcbc) { \| if ((int)uVar6 == 0xcd0) {` |
| 241 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x2bd + 10,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 245 | `stage_spawn_dispatch_candidate` | `0x4d,6000,0xffffff6a,0` | `if ((int)uVar6 == 0xe10) {` |
| 249 | `stage_spawn_dispatch_candidate` | `0x29,7000,0x1e0,0xfa` | `if ((int)uVar6 == 0xe10) { \| if ((int)uVar6 == 0xf6e) {` |
| 254 | `stage_spawn_dispatch_candidate` | `0x45,300,0xb4,0xffffffec` | `if ((int)uVar6 == 0xf6e) { \| if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x3c) * 0x3c)) {` |
| 255 | `stage_spawn_dispatch_candidate` | `0x45,300,0x168,0xffffffec` | `if ((int)uVar6 == 0xf6e) { \| if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x3c) * 0x3c)) {` |
| 256 | `stage_spawn_dispatch_candidate` | `0x45,300,0x21c,0xffffffec` | `if ((int)uVar6 == 0xf6e) { \| if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x3c) * 0x3c)) {` |
| 260 | `stage_spawn_dispatch_candidate` | `0x4d,6000,0x366,0` | `if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x3c) * 0x3c)) { \| if ((int)uVar6 == 0x1068) {` |
| 271 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x2bd + 10,0xffffffec` | `if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 282 | `stage_spawn_dispatch_candidate` | `0x45,300,0x2e4,DAT_140e9fd1c % 0xc9 + 0x32` | `if ((uVar4 < 0x32a) && (uVar4 == ((int)uVar4 / 0x60) * 0x60)) {` |
| 293 | `stage_spawn_dispatch_candidate` | `0x45,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 0x32` | `if ((uVar4 < 0x2fa) && (uVar4 == ((int)uVar4 / 0x60) * 0x60)) {` |
| 297 | `stage_spawn_dispatch_candidate` | `0x4a,7000,0x104,0` | `if ((int)uVar6 == 0x12c0) {` |
| 301 | `stage_spawn_dispatch_candidate` | `0x4a,7000,0x1cc,0` | `if ((int)uVar6 == 0x12c0) { \| if ((int)uVar6 == 5000) {` |
| 305 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xffffff9c,0x32` | `if ((int)uVar6 == 5000) { \| if ((int)uVar6 == 0x14c8) {` |
| 309 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xffffff06,0x4b` | `if ((int)uVar6 == 0x14c8) { \| if ((int)uVar6 == 0x14e6) {` |
| 313 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffe70,100` | `if ((int)uVar6 == 0x14e6) { \| if ((int)uVar6 == 0x1504) {` |
| 317 | `stage_spawn_dispatch_candidate` | `0x47,0x960,0xf0,0x96` | `if ((int)uVar6 == 0x1504) { \| if ((int)uVar6 == 0x157c) {` |
| 333 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec` | `if (uVar4 == 0) {` |
| 338 | `stage_spawn_dispatch_candidate` | `0x48,0x960,0x1e0,0x96` | `if ((int)uVar6 == 0x16a8) {` |
| 354 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0xf1 + 0x78,0xffffffec` | `if (uVar4 == 0) {` |
| 359 | `stage_spawn_dispatch_candidate` | `0x47,0x960,0xf0,0x96` | `if ((int)uVar6 == 0x17d4) {` |
| 364 | `stage_spawn_dispatch_candidate` | `0x4f,60000,0x168,200` | `if ((int)uVar6 == 0x17d4) { \| if (uVar4 == 0x18ce) {` |
| 377 | `stage_spawn_dispatch_candidate` | `0x46,2000,DAT_140e9fd1c % 0x65 - 0x15e, ((DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4) % 0x65` | `if (((int)uVar4 < 0x1de2) && (uVar7 == ((int)uVar7 / 0x96) * 0x96)) {` |
| 391 | `stage_spawn_dispatch_candidate` | `0x46,2000,DAT_140e9fd1c % 0x65 + 0x3ca, ((DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4) % 0x65` | `if ((uVar4 < 0x497) && (uVar4 == ((int)uVar4 / 0x96) * 0x96)) {` |
| 404 | `stage_spawn_dispatch_candidate` | `0x45,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((0x513 < uVar4) \|\| (uVar4 != ((int)uVar4 / 0x11) * 0x11)) goto LAB_1401207da;` |
| 409 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xffffff9c,100` | `if ((int)uVar6 == 0x1e3c) {` |
| 413 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xffffff06,0x4b` | `if ((int)uVar6 == 0x1e3c) { \| if ((int)uVar6 == 0x1e50) {` |
| 417 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xfffffe70,0x32` | `if ((int)uVar6 == 0x1e50) { \| if ((int)uVar6 == 0x1e64) {` |
| 421 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0x334,0x4b` | `if ((int)uVar6 == 0x1e64) { \| if ((int)uVar6 == 0x1eaa) {` |
| 425 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0x3ca,0x32` | `if ((int)uVar6 == 0x1eaa) { \| if ((int)uVar6 == 0x1ebe) {` |
| 429 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0x460,0x19` | `if ((int)uVar6 == 0x1ebe) { \| if ((int)uVar6 == 0x1ed2) {` |
| 433 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0xfffffe70,100` | `if ((int)uVar6 == 0x1ed2) { \| if ((int)uVar6 == 8000) {` |
| 434 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0x460,0x78` | `if ((int)uVar6 == 0x1ed2) { \| if ((int)uVar6 == 8000) {` |
| 438 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0xffffff06,100` | `if ((int)uVar6 == 8000) { \| if ((int)uVar6 == 0x1f72) {` |
| 439 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0x3ca,0x3c` | `if ((int)uVar6 == 8000) { \| if ((int)uVar6 == 0x1f72) {` |
| 443 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0xffffff9c,100` | `if ((int)uVar6 == 0x1f72) { \| if ((int)uVar6 == 0x1fa4) {` |
| 444 | `stage_spawn_dispatch_candidate` | `0x46,0x640,0x334,0` | `if ((int)uVar6 == 0x1f72) { \| if ((int)uVar6 == 0x1fa4) {` |
| 448 | `stage_spawn_dispatch_candidate` | `0x47,0x960,0xf0,200` | `if ((int)uVar6 == 0x1fa4) { \| if ((int)uVar6 == 0x203a) {` |
| 452 | `stage_spawn_dispatch_candidate` | `0x48,0x960,0x1e0,0x96` | `if ((int)uVar6 == 0x203a) { \| if ((int)uVar6 == 0x20d0) {` |
| 463 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0xfb + 0xa0,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 474 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x15f + 0x136,0xffffffec` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 478 | `stage_spawn_dispatch_candidate` | `0x4a,8000,0x136,0` | `if ((int)uVar6 == 0x2260) {` |
| 494 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (uVar4 == 0) {` |
| 499 | `stage_spawn_dispatch_candidate` | `0x4d,6000,0x366,0` | `if ((int)uVar6 == 0x23f0) {` |
| 503 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xffffff06,100` | `if ((int)uVar6 == 0x23f0) { \| if ((int)uVar6 == 0x24ea) {` |
| 507 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xfffffe70,0x32` | `if ((int)uVar6 == 0x24ea) { \| if ((int)uVar6 == 0x2508) {` |
| 511 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0x3ca,100` | `if ((int)uVar6 == 0x2508) { \| if ((int)uVar6 == 0x254e) {` |
| 515 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0x460,0x32` | `if ((int)uVar6 == 0x254e) { \| if ((int)uVar6 == 0x256c) {` |
| 526 | `stage_spawn_dispatch_candidate` | `0x45,300,0xffffffec,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x11) * 0x11)) {` |
| 537 | `stage_spawn_dispatch_candidate` | `0x45,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec` | `if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {` |
| 541 | `stage_spawn_dispatch_candidate` | `0x4a,10000,0x136,0` | `if ((int)uVar6 == 0x26ac) {` |
| 545 | `stage_spawn_dispatch_candidate` | `0x4d,6000,0xffffff6a,0` | `if ((int)uVar6 == 0x26ac) { \| if ((int)uVar6 == 0x27a6) {` |
| 556 | `stage_spawn_dispatch_candidate` | `0x45,300,0x2e4,DAT_140e9fd1c % 0x97 + 100` | `if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {` |
| 567 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar4 < 0xa0) && (uVar4 == ((int)uVar4 / 10) * 10)) {` |
| 571 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xfffffe70,100` | `if ((int)uVar6 == 0x29fe) {` |
| 575 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xffffff06,0x32` | `if ((int)uVar6 == 0x29fe) { \| if ((int)uVar6 == 0x2a1c) {` |
| 579 | `stage_spawn_dispatch_candidate` | `0x46,0x898,0xffffff9c,0` | `if ((int)uVar6 == 0x2a1c) { \| if ((int)uVar6 == 0x2a3a) {` |
| 591 | `stage_spawn_dispatch_candidate` | `0x45,300,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec` | `if ((uVar7 < 200) && (uVar7 == ((int)uVar7 / 0x11) * 0x11)) {` |
| 595 | `stage_spawn_dispatch_candidate` | `8,5000,0x104,0` | `if (uVar4 == 0x2b5c) {` |
| 21 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `06`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 80 | `stage_spawn_dispatch_candidate` | `0x57,0x960,0x230,0xffffff6a` | `if (DAT_140e418c8 == 0xfa) {` |
| 83 | `stage_spawn_dispatch_candidate` | `0x57,0x960,0x2f8,0xffffff6a` | `if (DAT_140e418c8 == 0xfa) { \| if (DAT_140e418c8 == 0x118) {` |
| 94 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x1c3 + 0x6e,0xffffffec` | `if ((uVar5 < 0x50) && (uVar5 == ((int)uVar5 / 0xe) * 0xe)) {` |
| 105 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 0x46) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {` |
| 109 | `stage_spawn_dispatch_candidate` | `0x58,0x960,0xa0,0xffffff6a` | `if ((int)uVar11 == 0x24e) {` |
| 113 | `stage_spawn_dispatch_candidate` | `0x58,0x960,0xffffffd8,0xffffff6a` | `if ((int)uVar11 == 0x24e) { \| if ((int)uVar11 == 0x262) {` |
| 124 | `stage_spawn_dispatch_candidate` | `0xd,300,0x2e4,DAT_140e9fd1c % 0x65 + 0xfa` | `if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 135 | `stage_spawn_dispatch_candidate` | `0xd,300,0xffffffec,DAT_140e9fd1c % 0x65 + 300` | `if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 139 | `stage_spawn_dispatch_candidate` | `7,5000,0x104,0` | `if ((int)uVar11 == 900) {` |
| 143 | `stage_spawn_dispatch_candidate` | `0x57,0x960,0x294,0xffffff6a` | `if ((int)uVar11 == 900) { \| if ((int)uVar11 == 1000) {` |
| 147 | `stage_spawn_dispatch_candidate` | `0x57,0x960,0x348,0xffffff4c` | `if ((int)uVar11 == 1000) { \| if ((int)uVar11 == 0x3fc) {` |
| 193 | `stage_spawn_dispatch_candidate` | `0x5a,0x44c,(int)*(float *)(&local_158 + lVar6), (int)*(float *)((longlong)&local_158 + lVar6 * 8 + 4)` | `` |
| 200 | `stage_spawn_dispatch_candidate` | `0x5d,0xc80,(int)*(float *)(&local_88 + lVar7), (int)*(float *)((longlong)&local_88 + lVar7 * 8 + 4)` | `` |
| 207 | `stage_spawn_dispatch_candidate` | `0x5e,0x15e0,(int)*(float *)(&local_1a8 + lVar6), (int)*(float *)((longlong)&local_1a8 + lVar6 * 8 + 4)` | `` |
| 212 | `stage_spawn_dispatch_candidate` | `0x5f,0x2b5c,0x168,0xffffee76` | `` |
| 217 | `stage_spawn_dispatch_candidate` | `0x5c,800,0x302,(int)uVar11 + -0x64a` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 222 | `stage_spawn_dispatch_candidate` | `0x5c,800,0x302,(int)uVar11 + -0x6b8` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 227 | `stage_spawn_dispatch_candidate` | `0x5c,800,0xffffffce,(int)uVar11 + -0xa3c` | `if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 232 | `stage_spawn_dispatch_candidate` | `0x5c,800,0xffffffce,(int)uVar11 + -0xaa5` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 237 | `stage_spawn_dispatch_candidate` | `0x5b,800,0x302,(int)uVar11 + -0xeec` | `if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 242 | `stage_spawn_dispatch_candidate` | `0x5b,800,0xffffffce,(int)uVar11 + -0xf5a` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 247 | `stage_spawn_dispatch_candidate` | `0x5b,800,0xffffffce,(int)uVar11 + -0x1252` | `if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 252 | `stage_spawn_dispatch_candidate` | `0x5b,800,0x302,(int)uVar11 + -0x12c0` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 263 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar5 < 0xf0) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 267 | `stage_spawn_dispatch_candidate` | `0x57,0x898,0x1ae,0xffffff88` | `if ((int)uVar11 == 0x6a4) {` |
| 268 | `stage_spawn_dispatch_candidate` | `0x57,0x898,0x244,0xffffff60` | `if ((int)uVar11 == 0x6a4) {` |
| 279 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 0x78) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 290 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x15f + 0x136,0xffffffec` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 294 | `stage_spawn_dispatch_candidate` | `0x59,0x22b8,0xffffff9c,200` | `if ((int)uVar11 == 0xc80) {` |
| 305 | `stage_spawn_dispatch_candidate` | `0xc,300,DAT_140e9fd1c % 0x191 + 0xd2,0xffffffec` | `if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0x2c) * 0x2c)) {` |
| 309 | `stage_spawn_dispatch_candidate` | `0x59,0x22b8,0x334,200` | `if ((int)uVar11 == 0xd70) {` |
| 320 | `stage_spawn_dispatch_candidate` | `0xd,300,0x2e4,DAT_140e9fd1c % 0x65 + 300` | `if ((uVar5 < 200) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 331 | `stage_spawn_dispatch_candidate` | `0xd,300,0xffffffec,DAT_140e9fd1c % 0x65 + 300` | `if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 335 | `stage_spawn_dispatch_candidate` | `0x58,0x960,0x168,0xffffff88` | `if ((int)uVar11 == 0x10cc) {` |
| 339 | `stage_spawn_dispatch_candidate` | `0x58,0x960,0xd2,0xffffff6a` | `if ((int)uVar11 == 0x10cc) { \| if ((int)uVar11 == 0x10fe) {` |
| 343 | `stage_spawn_dispatch_candidate` | `0x58,0x960,0x3c,0xffffff4c` | `if ((int)uVar11 == 0x10fe) { \| if ((int)uVar11 == 0x1130) {` |
| 354 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 365 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 10) * 10)) {` |
| 376 | `stage_spawn_dispatch_candidate` | `0x1a,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar5 < 0xf0) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 400 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((DAT_140e418cc != 0) \|\| (uVar12 = uVar5 - 0x1900, 0x76b < uVar12)) goto LAB_140122b98; \| if (uVar12 == ((int)uVar12 / 0x27) * 0x27) {` |
| 405 | `stage_spawn_dispatch_candidate` | `0x57,2000,0x1a4,0xffffff4c` | `if ((uVar5 < 0x6a4) && (uVar5 == ((int)uVar5 / 400) * 400)) {` |
| 406 | `stage_spawn_dispatch_candidate` | `0x57,2000,0x262,0xffffff6a` | `if ((uVar5 < 0x6a4) && (uVar5 == ((int)uVar5 / 400) * 400)) {` |
| 407 | `stage_spawn_dispatch_candidate` | `0x57,2000,800,0xffffff88` | `if ((uVar5 < 0x6a4) && (uVar5 == ((int)uVar5 / 400) * 400)) {` |
| 412 | `stage_spawn_dispatch_candidate` | `0x58,2000,300,0xffffff88` | `if ((uVar5 < 0x6a4) && (uVar5 == ((int)uVar5 / 400) * 400)) { \| if ((0x5db < uVar5) \|\| (uVar5 != ((int)uVar5 / 400) * 400)) goto LAB_140122b98;` |
| 413 | `stage_spawn_dispatch_candidate` | `0x58,2000,0x6e,0xffffff6a` | `if ((0x5db < uVar5) \|\| (uVar5 != ((int)uVar5 / 400) * 400)) goto LAB_140122b98;` |
| 414 | `stage_spawn_dispatch_candidate` | `0x58,2000,0xffffffb0,0xffffff4c` | `if ((0x5db < uVar5) \|\| (uVar5 != ((int)uVar5 / 400) * 400)) goto LAB_140122b98;` |
| 456 | `stage_spawn_dispatch_candidate` | `0x5a,0x44c,(int)*(float *)(&local_158 + lVar6), (int)*(float *)((longlong)&local_158 + lVar6 * 8 + 4)` | `` |
| 463 | `stage_spawn_dispatch_candidate` | `0x5d,0xc80,(int)*(float *)(&local_180 + lVar7), (int)*(float *)((longlong)&local_180 + lVar7 * 8 + 4)` | `` |
| 469 | `stage_spawn_dispatch_candidate` | `0x5e,0x15e0,(int)*(float *)(&local_1a8 + lVar8), (int)*(float *)((longlong)&local_1a8 + lVar8 * 8 + 4)` | `` |
| 474 | `stage_spawn_dispatch_candidate` | `0x5f,13000,0xf0,0xfffffb1e` | `` |
| 475 | `stage_spawn_dispatch_candidate` | `0x5f,0x30d4,500,0xfffff399` | `` |
| 480 | `stage_spawn_dispatch_candidate` | `0x5b,800,0x302,(int)uVar11 + -0x245e` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 485 | `stage_spawn_dispatch_candidate` | `0x5b,800,0xffffffce,(int)uVar11 + -0x25da` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 489 | `stage_spawn_dispatch_candidate` | `0x59,8000,0x334,200` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) { \| if ((int)uVar11 == 0x2260) {` |
| 493 | `stage_spawn_dispatch_candidate` | `0xf,5000,0xffffff88,0x78` | `if ((int)uVar11 == 0x2260) { \| if ((int)uVar11 == 0x23f0) {` |
| 504 | `stage_spawn_dispatch_candidate` | `0xb,300,0x2e4,DAT_140e9fd1c % 0xc9 + 0x96` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {` |
| 515 | `stage_spawn_dispatch_candidate` | `0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {` |
| 519 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x168,0xffffff9c` | `if ((int)uVar11 == 0x2774) {` |
| 520 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x230,0xffffff9c` | `if ((int)uVar11 == 0x2774) {` |
| 521 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x2f8,0xffffff9c` | `if ((int)uVar11 == 0x2774) {` |
| 522 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x1cc,0xffffff24` | `if ((int)uVar11 == 0x2774) {` |
| 523 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x294,0xffffff24` | `if ((int)uVar11 == 0x2774) {` |
| 528 | `stage_spawn_dispatch_candidate` | `0xc,300,0x3c,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 529 | `stage_spawn_dispatch_candidate` | `0xc,300,0xb4,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 530 | `stage_spawn_dispatch_candidate` | `0xc,300,300,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 531 | `stage_spawn_dispatch_candidate` | `0xc,300,0x1a4,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 532 | `stage_spawn_dispatch_candidate` | `0xc,300,0x21c,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 533 | `stage_spawn_dispatch_candidate` | `0xc,300,0x294,0xffffffec` | `if (((iVar10 == 0x283c) \|\| (iVar10 == 0x288c)) \|\| (iVar10 == 0x28dc)) {` |
| 537 | `stage_spawn_dispatch_candidate` | `0x59,7000,0xffffff9c,200` | `if ((int)uVar11 == 0x2936) {` |
| 541 | `stage_spawn_dispatch_candidate` | `0x59,7000,0x334,200` | `if ((int)uVar11 == 0x2936) { \| if ((int)uVar11 == 0x2968) {` |
| 553 | `stage_spawn_dispatch_candidate` | `0xc,300,DAT_140e9fd1c % 0x191 + 0x50,0xffffffec` | `if ((uVar12 < 0xdc) && (uVar12 == ((int)uVar12 / 0x1e) * 0x1e)) {` |
| 557 | `stage_spawn_dispatch_candidate` | `8,5000,0x1cc,0` | `if (uVar5 == 0x2e18) {` |
| 77 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `07`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 28 | `stage_spawn_dispatch_candidate` | `0x74,0x4b0,(int)(uVar7 * 6) % 0x168 + 0xb4,0x334` | `if ((uVar7 < 0x82) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {` |
| 32 | `stage_spawn_dispatch_candidate` | `0x71,0x1130,0x1e0,200` | `if ((uVar7 < 0x82) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) { \| if ((int)uVar9 == 500) {` |
| 36 | `stage_spawn_dispatch_candidate` | `0x71,0x1130,0xd2,0x10e` | `if ((int)uVar9 == 500) { \| if ((int)uVar9 == 0x244) {` |
| 47 | `stage_spawn_dispatch_candidate` | `0x70,700,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x23) * 0x23)) {` |
| 58 | `stage_spawn_dispatch_candidate` | `0x70,700,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x23) * 0x23)) {` |
| 63 | `stage_spawn_dispatch_candidate` | `0x74,0x4b0,(int)(uVar7 * 6) % 0x168 + 0xb4,0x334` | `if ((uVar7 < 0x82) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {` |
| 74 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,DAT_140e9fd1c % 0x259 + 0x3c,0x30c` | `if ((uVar7 < 0x5a) && (uVar7 == ((int)uVar7 / 0x19) * 0x19)) {` |
| 78 | `stage_spawn_dispatch_candidate` | `7,5000,0x168,0` | `if ((int)uVar9 == 0x514) {` |
| 82 | `stage_spawn_dispatch_candidate` | `0x73,7000,0xf0,0` | `if ((int)uVar9 == 0x514) { \| if ((int)uVar9 == 0x5b4) {` |
| 86 | `stage_spawn_dispatch_candidate` | `0x73,6000,0x1e0,0` | `if ((int)uVar9 == 0x5b4) { \| if ((int)uVar9 == 0x6a4) {` |
| 91 | `stage_spawn_dispatch_candidate` | `0x74,0x4b0,0x21c - (int)(uVar7 * 3) % 0x168,0x334` | `if ((int)uVar9 == 0x6a4) { \| if ((uVar7 < 200) && (uVar7 == ((int)uVar7 / 0x2b) * 0x2b)) {` |
| 95 | `stage_spawn_dispatch_candidate` | `0x72,0xce4,0x1fe,0xfa` | `if ((uVar7 < 200) && (uVar7 == ((int)uVar7 / 0x2b) * 0x2b)) { \| if ((int)uVar9 == 0x758) {` |
| 99 | `stage_spawn_dispatch_candidate` | `0x72,0xce4,0x168,200` | `if ((int)uVar9 == 0x758) { \| if ((int)uVar9 == 0x794) {` |
| 103 | `stage_spawn_dispatch_candidate` | `0x72,0xce4,0xd2,0x96` | `if ((int)uVar9 == 0x794) { \| if ((int)uVar9 == 2000) {` |
| 108 | `stage_spawn_dispatch_candidate` | `0x74,1000,0x21c - (((int)uVar9 + -0x60e) * 6) % 0x168,0x334` | `if ((int)uVar9 == 2000) { \| if ((uVar7 < 0x8c) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {` |
| 112 | `stage_spawn_dispatch_candidate` | `0x26,5000,0x208,0xffffffec` | `if ((uVar7 < 0x8c) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) { \| if ((int)uVar9 == 0x960) {` |
| 116 | `stage_spawn_dispatch_candidate` | `0x26,5000,200,0xffffffec` | `if ((int)uVar9 == 0x960) { \| if ((int)uVar9 == 0x9c4) {` |
| 127 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,DAT_140e9fd1c % 0x259 + 0x3c,0x30c` | `if ((uVar7 < 0x3c) && (uVar7 == ((int)uVar7 / 0xc) * 0xc)) {` |
| 131 | `stage_spawn_dispatch_candidate` | `0x76,18000,0x1ea,0x348` | `if ((int)uVar9 == 0xaf0) {` |
| 142 | `stage_spawn_dispatch_candidate` | `0xb,500,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {` |
| 153 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,DAT_140e9fd1c % 0xfb + 0xa0,0x30c` | `if ((uVar7 < 0xa0) && (uVar7 == ((int)uVar7 / 0x28) * 0x28)) {` |
| 164 | `stage_spawn_dispatch_candidate` | `0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {` |
| 168 | `stage_spawn_dispatch_candidate` | `0x76,15000,0xe6,0x348` | `if ((int)uVar9 == 0xd5c) {` |
| 172 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0x1ae,0x302` | `if ((int)uVar9 == 0xd5c) { \| if ((int)uVar9 == 0xd84) {` |
| 176 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0x212,0x366` | `if ((int)uVar9 == 0xd84) { \| if ((int)uVar9 == 0xdfc) {` |
| 187 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar7 < 0xaa) && (uVar7 == ((int)uVar7 / 10) * 10)) {` |
| 212 | `stage_spawn_dispatch_candidate` | `0x72,0xaf0,0xe6,0xfa` | `if ((DAT_140e418cc != 0) \|\| (iVar5 < 0x1068)) goto LAB_1401244b3; \| if (iVar5 < 0x1900) { \| if ((iVar5 < 0x17d4) && (iVar5 + -0x1068 == ((iVar5 + -0x1068) / 400) * 400)) {` |
| 217 | `stage_spawn_dispatch_candidate` | `0x72,0xaf0,0x1ea,200` | `if (iVar5 < 0x1900) { \| if ((iVar5 < 0x17d4) && (iVar5 + -0x1068 == ((iVar5 + -0x1068) / 400) * 400)) { \| if ((uVar7 < 0x730) && (uVar7 == ((int)uVar7 / 400) * 400)) {` |
| 222 | `stage_spawn_dispatch_candidate` | `0x71,0xaf0,0x1ea,0xfa` | `if ((uVar7 < 0x730) && (uVar7 == ((int)uVar7 / 400) * 400)) { \| if ((uVar7 < 0x6a4) && (uVar7 == ((int)uVar7 / 400) * 400)) {` |
| 227 | `stage_spawn_dispatch_candidate` | `0x71,0xaf0,0xe6,200` | `if ((uVar7 < 0x6a4) && (uVar7 == ((int)uVar7 / 400) * 400)) { \| if ((uVar7 < 0x668) && (uVar7 == ((int)uVar7 / 400) * 400)) {` |
| 238 | `stage_spawn_dispatch_candidate` | `0xb,500,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar7 < 0x76c) && (uVar7 == ((int)uVar7 / 0x32) * 0x32)) {` |
| 242 | `stage_spawn_dispatch_candidate` | `0x73,9000,0x19a,0` | `if ((int)uVar9 == 0x184c) {` |
| 250 | `stage_spawn_dispatch_candidate` | `0x74,1000,((iVar5 + -0x1900) * 5) % 0x168 + 0xb4,0x334` | `if ((iVar5 < 0x1996) && (iVar5 + -0x1900 == ((iVar5 + -0x1900) / 0x13) * 0x13)) {` |
| 262 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,DAT_140e9fd1c % 0x17d + 0xaa,0xffffffc4` | `if ((uVar7 < 0x50) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {` |
| 266 | `stage_spawn_dispatch_candidate` | `0x77,18000,0xf0,0x398` | `if ((int)uVar9 == 0x1a5e) {` |
| 278 | `stage_spawn_dispatch_candidate` | `0x25,700,DAT_140e9fd1c % 0xb5 + 0x1a4,0xffffffec` | `if ((uVar7 < 0xfa) && (uVar7 == ((int)uVar7 / 0x48) * 0x48)) {` |
| 283 | `stage_spawn_dispatch_candidate` | `0x74,1000,(int)(uVar7 * 2) % 200 + 0x186,0x334` | `if ((uVar7 < 0xb4) && (uVar7 == ((int)uVar7 / 0x27) * 0x27)) {` |
| 288 | `stage_spawn_dispatch_candidate` | `0x72,0xaf0,0xf0` | `if ((uVar7 < 0xb4) && (uVar7 == ((int)uVar7 / 0x27) * 0x27)) { \| if (((DAT_140e418cc == 0) && (uVar7 = (int)uVar9 - 0x1c20, uVar7 < 600)) &&` |
| 299 | `stage_spawn_dispatch_candidate` | `0x70,1000,DAT_140e9fd1c % 0x191 + 0xa0,0x30c` | `if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x15) * 0x15)) {` |
| 323 | `stage_spawn_dispatch_candidate` | `0x73,6000,0x168 - (int)(dVar11 * DAT_14053a548),0` | `if ((DAT_140e418cc != 0) \|\| (iVar5 < 0x2008)) goto LAB_140124c32; \| if (iVar5 < 0x28a0) { \| if ((iVar5 < 0x25e4) && (iVar5 + -0x2008 == ((iVar5 + -0x2008) / 0x96) * 0x96)) {` |
| 334 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar7 < 0x60e) && (uVar7 == ((int)uVar7 / 0x2c) * 0x2c)) {` |
| 338 | `stage_spawn_dispatch_candidate` | `0x76,15000,0x168,0x348` | `if ((int)uVar9 == 0x2648) {` |
| 342 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0x1cc,1000` | `if ((int)uVar9 == 0x2648) { \| if ((int)uVar9 == 0x2670) {` |
| 343 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0x104,1000` | `if ((int)uVar9 == 0x2648) { \| if ((int)uVar9 == 0x2670) {` |
| 347 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0x21c,0x366` | `if ((int)uVar9 == 0x2670) { \| if ((int)uVar9 == 10000) {` |
| 348 | `stage_spawn_dispatch_candidate` | `0x75,0x960,0xb4,0x366` | `if ((int)uVar9 == 0x2670) { \| if ((int)uVar9 == 10000) {` |
| 352 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,0x1b8,0x30c` | `if ((int)uVar9 == 10000) { \| if ((int)uVar9 == 0x2814) {` |
| 353 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,0x118,0x30c` | `if ((int)uVar9 == 10000) { \| if ((int)uVar9 == 0x2814) {` |
| 357 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,0x208,0x30c` | `if ((int)uVar9 == 0x2814) { \| if ((int)uVar9 == 0x283c) {` |
| 358 | `stage_spawn_dispatch_candidate` | `0x70,0x4b0,200,0x30c` | `if ((int)uVar9 == 0x2814) { \| if ((int)uVar9 == 0x283c) {` |
| 372 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (((int)uVar7 < 0x2968) && (uVar7 - 0x28a0 == ((int)(uVar7 - 0x28a0) / 10) * 10)) {` |
| 377 | `stage_spawn_dispatch_candidate` | `0x77,18000,0x1e0,0x398` | `if ((int)uVar9 == 0x2968) {` |
| 390 | `stage_spawn_dispatch_candidate` | `0x70,700,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if (((uVar7 < 0x1c2) && (iVar5 = (int)uVar7 % 0x10e, iVar5 < 0x3c)) &&` |
| 394 | `stage_spawn_dispatch_candidate` | `0x76,15000,0xe6,0x348` | `if ((int)uVar9 == 0x2c24) {` |
| 406 | `stage_spawn_dispatch_candidate` | `0x70,700,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar7 < 0x78) && (uVar7 == ((int)uVar7 / 0x1e) * 0x1e)) {` |
| 419 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar8 < 100) && (uVar8 == ((int)uVar8 / 10) * 10)) {` |
| 423 | `stage_spawn_dispatch_candidate` | `8,5000,0x1cc,0` | `if (uVar7 == 0x2e18) {` |
| 23 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `08`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 99 | `stage_spawn_dispatch_candidate` | `0x97,0x5dc,(int)*(float *)(&local_228 + uVar6), (int)*(float *)((longlong)&local_228 + uVar6 * 8 + 4)` | `if (DAT_140e418c8 == 400) {` |
| 104 | `stage_spawn_dispatch_candidate` | `0x9a,15000,0x200,0xfffff37e` | `` |
| 105 | `stage_spawn_dispatch_candidate` | `0x9a,15000,0x138,0xffffee99` | `` |
| 110 | `stage_spawn_dispatch_candidate` | `0x98,1000,0x302,DAT_140e418c8 - 0x352` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 115 | `stage_spawn_dispatch_candidate` | `0x98,1000,0xffffffce,(int)uVar6 + -0x460` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 120 | `stage_spawn_dispatch_candidate` | `0x98,1000,0x302,(int)uVar6 + -0x992` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 125 | `stage_spawn_dispatch_candidate` | `0x98,1000,0xffffffce,(int)uVar6 + -0x1158` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 130 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x10e,0xffffffce` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 131 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x168,0xffffffce` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 132 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x1c2,0xffffffce` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 137 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0x1d6,0xffffffce` | `if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 500) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 138 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0x249,0xffffffce` | `if ((uVar5 < 500) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 143 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0xe6,0xffffffce` | `if ((uVar5 < 500) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 144 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0x1ea,0xffffffce` | `if ((uVar5 < 500) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 157 | `stage_spawn_dispatch_candidate` | `0x99,0x4b0,(int)*(float *)(&local_228 + uVar7), (int)*(float *)((longlong)&local_228 + uVar7 * 8 + 4) + (int)uVar6 + -0x672` | `if ((int)uVar6 == iVar12) {` |
| 167 | `stage_spawn_dispatch_candidate` | `0x99,0x5dc,0xffffffce,0x50` | `if ((int)uVar6 == 0xce4) {` |
| 171 | `stage_spawn_dispatch_candidate` | `0x99,0x5dc,0xffffff4c,0x50` | `if ((int)uVar6 == 0xce4) { \| if ((int)uVar6 == 0xd02) {` |
| 216 | `stage_spawn_dispatch_candidate` | `0x96,700,(int)*pfVar8,(int)(fVar2 - pfVar8[1]) + (int)uVar6 + -0x157c` | `if (0xf < iVar10) { \| if ((int)uVar6 == iVar3) {` |
| 238 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (uVar5 == 0) {` |
| 255 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (uVar5 == 0) {` |
| 260 | `stage_spawn_dispatch_candidate` | `0xe,5000,500,0` | `if ((int)uVar6 == 0x26c) {` |
| 264 | `stage_spawn_dispatch_candidate` | `0xe,5000,0xdc,0` | `if ((int)uVar6 == 0x26c) { \| if ((int)uVar6 == 0x28a) {` |
| 268 | `stage_spawn_dispatch_candidate` | `7,5000,0x1cc,0` | `if ((int)uVar6 == 0x28a) { \| if ((int)uVar6 == 1000) {` |
| 279 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {` |
| 290 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {` |
| 301 | `stage_spawn_dispatch_candidate` | `0x45,400,0xffffffec,DAT_140e9fd1c % 0x79 + 0x96` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 305 | `stage_spawn_dispatch_candidate` | `0x10,14000,0x10e,0x50` | `if ((int)uVar6 == 0xb54) {` |
| 321 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x155 + 0x3c,0xffffffec` | `if (uVar5 == 0) {` |
| 338 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x155 + 0x140,0xffffffec` | `if (uVar5 == 0) {` |
| 343 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffed4,0x32` | `if ((int)uVar6 == 0x1004) {` |
| 347 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x3fc,0x32` | `if ((int)uVar6 == 0x1004) { \| if ((int)uVar6 == 0x1022) {` |
| 351 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffed4,100` | `if ((int)uVar6 == 0x1022) { \| if ((int)uVar6 == 0x109a) {` |
| 355 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x3fc,100` | `if ((int)uVar6 == 0x109a) { \| if ((int)uVar6 == 0x10b8) {` |
| 366 | `stage_spawn_dispatch_candidate` | `0x45,400,0x2e4,DAT_140e9fd1c % 0x83 + 0x78` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 377 | `stage_spawn_dispatch_candidate` | `0x44,200,DAT_140e9fd1c % 0x281 + 0x28,0xffffffec` | `if ((uVar5 < 0xa0) && (uVar5 == ((int)uVar5 / 5) * 5)) {` |
| 382 | `stage_spawn_dispatch_candidate` | `0x45,400,0x50,0xffffffec` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {` |
| 383 | `stage_spawn_dispatch_candidate` | `0x45,400,0xdc,0xffffffec` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {` |
| 384 | `stage_spawn_dispatch_candidate` | `0x45,400,0x168,0xffffffec` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {` |
| 385 | `stage_spawn_dispatch_candidate` | `0x45,400,500,0xffffffec` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {` |
| 386 | `stage_spawn_dispatch_candidate` | `0x45,400,0x26c,0xffffffec` | `if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {` |
| 390 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0xfffffed4,100` | `if ((int)uVar6 == 0x16a8) {` |
| 391 | `stage_spawn_dispatch_candidate` | `0x46,0x960,0x3fc,100` | `if ((int)uVar6 == 0x16a8) {` |
| 396 | `stage_spawn_dispatch_candidate` | `0x9c,9000,0x21c,200` | `if ((int)uVar6 == 0x16a8) { \| if ((int)uVar6 == 0x186a) { \| if (DAT_140e445c0 == 0) {` |
| 400 | `stage_spawn_dispatch_candidate` | `0x9f,7000,0x21c,200` | `if ((int)uVar6 == 0x186a) { \| if (DAT_140e445c0 == 0) { \| if (DAT_140e445c0 == 1) {` |
| 404 | `stage_spawn_dispatch_candidate` | `0xa2,7000,0x21c,200` | `if (DAT_140e445c0 == 1) { \| if (DAT_140e445c0 == 2) {` |
| 410 | `stage_spawn_dispatch_candidate` | `0xb,300,0x50,0xffffffec` | `if (DAT_140e445c0 == 2) { \| if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {` |
| 411 | `stage_spawn_dispatch_candidate` | `0xb,300,0xdc,0xffffffec` | `if (DAT_140e445c0 == 2) { \| if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {` |
| 412 | `stage_spawn_dispatch_candidate` | `0xb,300,0x168,0xffffffec` | `if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {` |
| 413 | `stage_spawn_dispatch_candidate` | `0xb,300,500,0xffffffec` | `if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {` |
| 414 | `stage_spawn_dispatch_candidate` | `0xb,300,0x26c,0xffffffec` | `if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {` |
| 418 | `stage_spawn_dispatch_candidate` | `8,5000,0x136,0` | `if ((int)uVar6 == 0x19fa) {` |
| 429 | `stage_spawn_dispatch_candidate` | `0x70,0x15e,0x2e4,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 0x3c) && (uVar5 == ((int)uVar5 / 10) * 10)) {` |
| 440 | `stage_spawn_dispatch_candidate` | `0x70,0x15e,0xffffffec,DAT_140e9fd1c % 0xc9 + 100` | `if ((uVar5 < 0x3c) && (uVar5 == ((int)uVar5 / 10) * 10)) {` |
| 456 | `stage_spawn_dispatch_candidate` | `0x70,0x15e,((DAT_140e9fd1c / 0xc9) * 0xc9 - DAT_140e9fd1c) + 0x136,0xffffffec` | `if (uVar5 == 0) {` |
| 464 | `stage_spawn_dispatch_candidate` | `0x70,0x15e,DAT_140e9fd1c % 0xc9 + 0x19a,0xffffffec` | `` |
| 477 | `stage_spawn_dispatch_candidate` | `0x37,300,DAT_140e9fd1c % 0x1e1 + 0x78, ((DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5) % 0x97 + 400` | `if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 483 | `stage_spawn_dispatch_candidate` | `0x71,5000,0x1b8,200` | `if ((int)uVar6 == 0x1c20) {` |
| 487 | `stage_spawn_dispatch_candidate` | `0x72,5000,0x118,200` | `if ((int)uVar6 == 0x1c20) { \| if ((int)uVar6 == 0x1cac) {` |
| 491 | `stage_spawn_dispatch_candidate` | `0x71,5000,0x1e0,0xfa` | `if ((int)uVar6 == 0x1cac) { \| if ((int)uVar6 == 0x1d38) {` |
| 507 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (uVar5 == 0) {` |
| 512 | `stage_spawn_dispatch_candidate` | `0x1c,0x1130,0xffffff88,0` | `if ((int)uVar6 == 0x1db0) {` |
| 516 | `stage_spawn_dispatch_candidate` | `0x1c,0x1130,0x348,0x1e` | `if ((int)uVar6 == 0x1db0) { \| if ((int)uVar6 == 0x1e32) {` |
| 520 | `stage_spawn_dispatch_candidate` | `0x1c,0x1130,0xffffff88,0x3c` | `if ((int)uVar6 == 0x1e32) { \| if ((int)uVar6 == 0x1eb4) {` |
| 524 | `stage_spawn_dispatch_candidate` | `0x1c,0x1130,0x348,0x5a` | `if ((int)uVar6 == 0x1eb4) { \| if ((int)uVar6 == 0x1f36) {` |
| 540 | `stage_spawn_dispatch_candidate` | `0xb,300,((DAT_140e9fd1c / 0xc9) * 0xc9 - DAT_140e9fd1c) + 0x136,0xffffffec` | `if (uVar5 == 0) {` |
| 548 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0xc9 + 0x19a,0xffffffec` | `` |
| 554 | `stage_spawn_dispatch_candidate` | `0xa4,75000,0x334,0xb4` | `if (uVar5 == 0x20a8) {` |
| 568 | `stage_spawn_dispatch_candidate` | `0x70,0x15e,((DAT_140e9fd1c / 0x1f5) * 0x1f5 - DAT_140e9fd1c) + 0x262,0xffffffec` | `if ((uVar13 < 0x44c) && (uVar13 == ((int)uVar13 / 0x1e) * 0x1e)) {` |
| 585 | `stage_spawn_dispatch_candidate` | `0xb,300,((DAT_140e9fd1c / 0x1f5) * 0x1f5 - DAT_140e9fd1c) + 0x262,0xffffffec` | `if (uVar5 == 0) {` |
| 598 | `stage_spawn_dispatch_candidate` | `0x1a,300,((DAT_140e9fd1c / 0x1b9) * 0x1b9 - DAT_140e9fd1c) + 0x244,0xffffffec` | `if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0x16) * 0x16)) {` |
| 610 | `stage_spawn_dispatch_candidate` | `0x38,0xe10,((DAT_140e9fd1c / 0x1b9) * 0x1b9 - DAT_140e9fd1c) + 0x244,0xffffffec` | `if ((uVar5 < 0x104) && (uVar5 == ((int)uVar5 / 100) * 100)) {` |
| 616 | `stage_spawn_dispatch_candidate` | `0x26,3000,0x168,0xffffffec` | `if ((int)uVar6 == 0x28a0) {` |
| 620 | `stage_spawn_dispatch_candidate` | `0x26,3000,0x21c,0xffffffec` | `if ((int)uVar6 == 0x28a0) { \| if ((int)uVar6 == 0x28d2) {` |
| 621 | `stage_spawn_dispatch_candidate` | `0x26,3000,0xb4,0xffffffec` | `if ((int)uVar6 == 0x28a0) { \| if ((int)uVar6 == 0x28d2) {` |
| 660 | `stage_spawn_dispatch_candidate` | `0x1d,0x640,(int)*(float *)((longlong)&local_188 + uVar6), (int)*(float *)((longlong)&local_188 + uVar6 + 4)` | `` |
| 663 | `stage_spawn_dispatch_candidate` | `0x2c,0x640,(int)*(float *)((longlong)&local_158 + uVar6), (int)*(float *)((longlong)&local_158 + uVar6 + 4)` | `` |
| 666 | `stage_spawn_dispatch_candidate` | `0x5a,0x640,(int)*(float *)((longlong)&local_128 + uVar6), (int)*(float *)((longlong)&local_128 + uVar6 + 4)` | `` |
| 673 | `stage_spawn_dispatch_candidate` | `0x1e,0x708,(int)*(float *)((longlong)&local_1f8 + uVar7), (int)*(float *)((longlong)&local_1f8 + uVar7 + 4)` | `` |
| 676 | `stage_spawn_dispatch_candidate` | `0x2d,0x1194,(int)*(float *)((longlong)&local_1e8 + uVar7), (int)*(float *)((longlong)&local_1e8 + uVar7 + 4)` | `` |
| 683 | `stage_spawn_dispatch_candidate` | `0x5d,0xc80,(int)*(float *)(&local_1d8 + uVar6), (int)*(float *)((longlong)&local_1d8 + uVar6 * 8 + 4)` | `` |
| 690 | `stage_spawn_dispatch_candidate` | `0x97,0x708,(int)*(float *)(&local_228 + uVar7), (int)*(float *)((longlong)&local_228 + uVar7 * 8 + 4)` | `` |
| 695 | `stage_spawn_dispatch_candidate` | `0x20,14000,200,0xfffff4de` | `` |
| 696 | `stage_spawn_dispatch_candidate` | `0x5e,0x157c,0x208,0xfffff4ac` | `` |
| 697 | `stage_spawn_dispatch_candidate` | `0x1f,8000,0x1c2,0xffffec64` | `` |
| 698 | `stage_spawn_dispatch_candidate` | `0x1f,8000,0x127,0xffffebc4` | `` |
| 699 | `stage_spawn_dispatch_candidate` | `0x5f,0x34bc,0x168,0xffffea84` | `` |
| 704 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x10e,0xffffffce` | `if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 705 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x168,0xffffffce` | `if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 706 | `stage_spawn_dispatch_candidate` | `0x95,1000,0x1c2,0xffffffce` | `if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 711 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0xe6,0xffffffce` | `if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 712 | `stage_spawn_dispatch_candidate` | `0x95,0x4b0,0x1ea,0xffffffce` | `if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 717 | `stage_spawn_dispatch_candidate` | `0x5b,800,0x302,(int)uVar6 + -0x2d14` | `if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 718 | `stage_spawn_dispatch_candidate` | `0x5b,800,0xffffffce,DAT_140e418c8 - 0x2d82` | `if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 723 | `stage_spawn_dispatch_candidate` | `0x5b,1000,0xffffffce,(int)uVar6 + -0x3264` | `if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 900) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 728 | `stage_spawn_dispatch_candidate` | `0x98,1000,0x302,(int)uVar6 + -0x3714` | `if ((uVar5 < 900) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) { \| if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {` |
| 749 | `stage_spawn_dispatch_candidate` | `0x96,700,(int)*pfVar8,(int)(fVar2 - pfVar8[1]) + (int)uVar6 + -0x3cf0` | `if ((int)uVar11 < 3) { \| if ((int)uVar6 == iVar10) {` |
| 765 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0x96` | `if (uVar5 < 100) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 770 | `stage_spawn_dispatch_candidate` | `0x1b,3000,0xf0,0` | `if (uVar5 == 0) { \| if ((int)uVar6 == 0x2ac6) {` |
| 780 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x96` | `if (uVar5 < 100) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 785 | `stage_spawn_dispatch_candidate` | `0x1b,3000,0x1e0,0` | `if (uVar5 == 0) { \| if ((int)uVar6 == 0x2b5c) {` |
| 789 | `stage_spawn_dispatch_candidate` | `0x4a,9000,0x168,0` | `if ((int)uVar6 == 0x2b5c) { \| if ((int)uVar6 == 0x2c56) {` |
| 799 | `stage_spawn_dispatch_candidate` | `0x35,200,0x2e4,0x96` | `if (uVar5 < 0x3c) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 810 | `stage_spawn_dispatch_candidate` | `0x35,200,0xffffffec,0xb4` | `if (uVar5 < 0x32) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 821 | `stage_spawn_dispatch_candidate` | `0x35,200,0x2e4,0x15e` | `if (uVar5 < 0x32) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 832 | `stage_spawn_dispatch_candidate` | `0x35,200,0xffffffec,0x15e` | `if (uVar5 < 0x32) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 843 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x78` | `if (uVar5 < 100) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 848 | `stage_spawn_dispatch_candidate` | `0x9b,6000,0x230,0xb4` | `if (uVar5 == 0) { \| if ((int)uVar6 == 0x3390) {` |
| 852 | `stage_spawn_dispatch_candidate` | `0x9e,5000,0xdc,0x96` | `if ((int)uVar6 == 0x3390) { \| if ((int)uVar6 == 0x367e) {` |
| 856 | `stage_spawn_dispatch_candidate` | `0x3a,10000,800,200` | `if ((int)uVar6 == 0x367e) { \| if ((int)uVar6 == 0x3840) {` |
| 860 | `stage_spawn_dispatch_candidate` | `0xa1,9000,0x21c,0x96` | `if ((int)uVar6 == 0x3840) { \| if ((int)uVar6 == 0x3afc) {` |
| 871 | `stage_spawn_dispatch_candidate` | `0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {` |
| 883 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {` |
| 894 | `stage_spawn_dispatch_candidate` | `10,1000,(int)(uVar5 * 7) % 0x1e0 + 0x78,0x4236 - (int)uVar6` | `if (uVar5 < 200) { \| if ((int)uVar13 < 0) { \| if (uVar13 == 0) {` |
| 906 | `stage_spawn_dispatch_candidate` | `0xc,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 0x6e) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 911 | `stage_spawn_dispatch_candidate` | `0x70,500,0x136 - (int)(uVar5 * 6) % 0xf0,0x30c` | `if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 912 | `stage_spawn_dispatch_candidate` | `0x70,500,(int)((DAT_140e418c8 - 0x43a8) * 6) % 0xf0 + 0x19a,0x30c` | `if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 918 | `stage_spawn_dispatch_candidate` | `0x70,500,0x136 - (int)(uVar5 * 6) % 0xf0,0x30c` | `if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) { \| if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 919 | `stage_spawn_dispatch_candidate` | `0x70,500,(int)((DAT_140e418c8 - 0x440c) * 6) % 0xf0 + 0x19a,0x30c` | `if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {` |
| 924 | `stage_spawn_dispatch_candidate` | `0xf,0x1194,0xffffff88,0xfa` | `if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) { \| if ((int)uVar6 == 0x44c0) {` |
| 928 | `stage_spawn_dispatch_candidate` | `0xf,0x1194,0x348,200` | `if ((int)uVar6 == 0x44c0) { \| if ((int)uVar6 == 0x44f2) {` |
| 932 | `stage_spawn_dispatch_candidate` | `0xf,0x1194,0xffffff88,0x96` | `if ((int)uVar6 == 0x44f2) { \| if ((int)uVar6 == 0x4524) {` |
| 936 | `stage_spawn_dispatch_candidate` | `0xf,0x1194,0x348,100` | `if ((int)uVar6 == 0x4524) { \| if ((int)uVar6 == 0x4556) {` |
| 940 | `stage_spawn_dispatch_candidate` | `0x3d,10000,0x398,0x96` | `if ((int)uVar6 == 0x4556) { \| if ((int)uVar6 == 18000) {` |
| 950 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0x2e4,0x78` | `if (uVar5 < 0x50) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 955 | `stage_spawn_dispatch_candidate` | `0x73,7000,0x1cc,0` | `if (uVar5 == 0) { \| if ((int)uVar6 == 0x474a) {` |
| 965 | `stage_spawn_dispatch_candidate` | `0x35,0xfa,0xffffffec,0xa0` | `if (uVar5 < 0x50) { \| if ((int)uVar5 < 0) { \| if (uVar5 == 0) {` |
| 970 | `stage_spawn_dispatch_candidate` | `0x73,7000,0x104,0` | `if (uVar5 == 0) { \| if ((int)uVar6 == 0x4812) {` |
| 974 | `stage_spawn_dispatch_candidate` | `0x25,700,0xd2,0xffffffec` | `if ((int)uVar6 == 0x4812) { \| if ((int)uVar6 == 0x4876) {` |
| 975 | `stage_spawn_dispatch_candidate` | `0x25,700,300,0xffffffec` | `if ((int)uVar6 == 0x4812) { \| if ((int)uVar6 == 0x4876) {` |
| 976 | `stage_spawn_dispatch_candidate` | `0x25,700,0x186,0xffffffec` | `if ((int)uVar6 == 0x4812) { \| if ((int)uVar6 == 0x4876) {` |
| 977 | `stage_spawn_dispatch_candidate` | `0x25,700,0x1e0,0xffffffec` | `if ((int)uVar6 == 0x4812) { \| if ((int)uVar6 == 0x4876) {` |
| 981 | `stage_spawn_dispatch_candidate` | `0x25,700,0xf0,0xffffffec` | `if ((int)uVar6 == 0x4876) { \| if ((int)uVar6 == 0x48a8) {` |
| 982 | `stage_spawn_dispatch_candidate` | `0x25,700,0x14a,0xffffffec` | `if ((int)uVar6 == 0x48a8) {` |
| 983 | `stage_spawn_dispatch_candidate` | `0x25,700,0x1a4,0xffffffec` | `if ((int)uVar6 == 0x48a8) {` |
| 984 | `stage_spawn_dispatch_candidate` | `0x25,700,0x1fe,0xffffffec` | `if ((int)uVar6 == 0x48a8) {` |
| 989 | `stage_spawn_dispatch_candidate` | `0x2e,60000,0x168,0xffffff88` | `if (uVar5 == 0x490c) {` |
| 1002 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar13 < 0x47e) && (uVar13 == ((int)uVar13 / 5) * 5)) {` |
| 1006 | `stage_spawn_dispatch_candidate` | `0x27,4000,0x1e0,300` | `if ((int)uVar6 == 20000) {` |
| 1010 | `stage_spawn_dispatch_candidate` | `0x27,4000,0xf0,200` | `if ((int)uVar6 == 20000) { \| if ((int)uVar6 != 0x4e48) goto LAB_1401282c6;` |
| 1015 | `stage_spawn_dispatch_candidate` | `0x27,4000,0x1b8,100` | `if ((int)uVar6 != 0x4e48) goto LAB_1401282c6; \| if ((int)uVar6 == 0x4e70) {` |
| 1019 | `stage_spawn_dispatch_candidate` | `0x29,4000,0xf0,300` | `if ((int)uVar6 == 0x4e70) { \| if ((int)uVar6 == 0x4f4c) {` |
| 1023 | `stage_spawn_dispatch_candidate` | `0x29,4000,0x1e0,0xfa` | `if ((int)uVar6 == 0x4f4c) { \| if ((int)uVar6 == 0x4fb0) {` |
| 1027 | `stage_spawn_dispatch_candidate` | `0x29,4000,0xf0,200` | `if ((int)uVar6 == 0x4fb0) { \| if ((int)uVar6 == 0x5014) {` |
| 1039 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x18) * 0x18)) {` |
| 1044 | `stage_spawn_dispatch_candidate` | `0x59,5000,0xffffff9c,200` | `if ((int)uVar6 == 0x50aa) {` |
| 1048 | `stage_spawn_dispatch_candidate` | `0x59,5000,0x334,200` | `if ((int)uVar6 == 0x50aa) { \| if ((int)uVar6 == 0x50dc) {` |
| 1060 | `stage_spawn_dispatch_candidate` | `0x45,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if (((DAT_140e418cc == 0) && (uVar13 = uVar5 - 0x50dc, uVar13 < 100)) &&` |
| 1064 | `stage_spawn_dispatch_candidate` | `8,5000,0x104,0` | `if (uVar5 == 0x51a4) {` |
| 89 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `09`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 32 | `stage_spawn_dispatch_candidate` | `0x74,700,iVar4 + 0x82,0x334` | `if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {` |
| 33 | `stage_spawn_dispatch_candidate` | `0x74,700,iVar4 + 0x104,0x334` | `if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {` |
| 34 | `stage_spawn_dispatch_candidate` | `0x74,700,iVar4 + 0x186,0x334` | `if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {` |
| 35 | `stage_spawn_dispatch_candidate` | `0x74,700,iVar4 + 0x208,0x334` | `if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {` |
| 36 | `stage_spawn_dispatch_candidate` | `0x74,700,iVar4 + 0x28a,0x334` | `if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {` |
| 40 | `stage_spawn_dispatch_candidate` | `0x26,3000,0x230,0xffffffec` | `if ((int)uVar7 == 700) {` |
| 41 | `stage_spawn_dispatch_candidate` | `0x26,3000,0xa0,0xffffffec` | `if ((int)uVar7 == 700) {` |
| 45 | `stage_spawn_dispatch_candidate` | `0x26,3000,0x168,0xffffffec` | `if ((int)uVar7 == 700) { \| if ((int)uVar7 == 800) {` |
| 50 | `stage_spawn_dispatch_candidate` | `0x19,700,(int)uVar7 * 4 + -0xdc0,0xffffffec` | `if ((int)uVar7 == 800) { \| if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 61 | `stage_spawn_dispatch_candidate` | `0xd,400,0xffffffec,DAT_140e9fd1c % 0x12d + 0x96` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 72 | `stage_spawn_dispatch_candidate` | `0xd,400,0x2e4,DAT_140e9fd1c % 0x12d + 0x96` | `if ((uVar3 < 0x73) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 76 | `stage_spawn_dispatch_candidate` | `7,5000,0x104,0` | `if ((int)uVar7 == 0x4b0) {` |
| 104 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((iVar4 < 0x60) && (iVar4 == (iVar4 / 0x18) * 0x18)) {` |
| 115 | `stage_spawn_dispatch_candidate` | `0xe,3000,DAT_140e9fd1c % 0x1b9 + 0x8c,0` | `if ((uVar3 < 0x6e0) && (uVar3 == ((int)uVar3 / 100) * 100)) {` |
| 119 | `stage_spawn_dispatch_candidate` | `0x38,3000,0x208,0` | `if ((int)uVar7 == 0xdac) {` |
| 120 | `stage_spawn_dispatch_candidate` | `0x38,3000,0xb4,0` | `if ((int)uVar7 == 0xdac) {` |
| 125 | `stage_spawn_dispatch_candidate` | `0x46,2000,0x460,100,uVar10,uVar12` | `if ((int)uVar7 == 0xdac) { \| if ((int)uVar7 == 0xe4c) {` |
| 129 | `stage_spawn_dispatch_candidate` | `0x46,2000,0x3ca,0x4b,uVar10` | `if ((int)uVar7 == 0xe4c) { \| if ((int)uVar7 == 0xe74) {` |
| 133 | `stage_spawn_dispatch_candidate` | `0x46,2000,0x334,0x32` | `if ((int)uVar7 == 0xe74) { \| if ((int)uVar7 == 0xe92) {` |
| 137 | `stage_spawn_dispatch_candidate` | `0x46,2000,0xfffffe70,0x50` | `if ((int)uVar7 == 0xe92) { \| if ((int)uVar7 == 0xec4) {` |
| 141 | `stage_spawn_dispatch_candidate` | `0x46,2000,0xffffff06,0x37` | `if ((int)uVar7 == 0xec4) { \| if ((int)uVar7 == 0xee2) {` |
| 145 | `stage_spawn_dispatch_candidate` | `0x46,2000,0xffffff9c,0x1e` | `if ((int)uVar7 == 0xee2) { \| if ((int)uVar7 == 0xf00) {` |
| 150 | `stage_spawn_dispatch_candidate` | `0x19,500,0x6e,0xffffffec` | `if ((int)uVar7 == 0xf00) { \| if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 151 | `stage_spawn_dispatch_candidate` | `0x19,500,0xd2,0xffffffec` | `if ((int)uVar7 == 0xf00) { \| if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 152 | `stage_spawn_dispatch_candidate` | `0x19,500,0x136,0xffffffec` | `if ((int)uVar7 == 0xf00) { \| if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 153 | `stage_spawn_dispatch_candidate` | `0x19,500,0x19a,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 154 | `stage_spawn_dispatch_candidate` | `0x19,500,0x1fe,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 155 | `stage_spawn_dispatch_candidate` | `0x19,500,0x262,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 181 | `stage_spawn_dispatch_candidate` | `0x57,0x708,DAT_140e9fd1c % 0x97 + 0x262, ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x65 - 200` | `if (((int)uVar3 < 0x15e0) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {` |
| 195 | `stage_spawn_dispatch_candidate` | `0x58,0x708,DAT_140e9fd1c % 0x97 - 0x28, ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3) % 0x65 - 200` | `if ((uVar3 < 0x4f6) && (uVar3 == ((int)uVar3 / 0x50) * 0x50)) {` |
| 201 | `stage_spawn_dispatch_candidate` | `0x2b,12000,0x168,0` | `if ((int)uVar7 == 0x1644) {` |
| 206 | `stage_spawn_dispatch_candidate` | `0xb,400,0x6e,0xffffffec` | `if ((int)uVar7 == 0x1644) { \| if ((uVar3 < 0x96) && (uVar3 == ((int)uVar3 / 0x32) * 0x32)) {` |
| 207 | `stage_spawn_dispatch_candidate` | `0xb,400,0x262,0xffffffec` | `if ((int)uVar7 == 0x1644) { \| if ((uVar3 < 0x96) && (uVar3 == ((int)uVar3 / 0x32) * 0x32)) {` |
| 220 | `stage_spawn_dispatch_candidate` | `0xb,0x168,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec,uVar10,uVar12` | `if (((uVar3 < 0xa0) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&` |
| 232 | `stage_spawn_dispatch_candidate` | `0xb,0x168,0x2e4,DAT_140e9fd1c % 0xfb + 100,uVar10` | `if (((uVar3 < 0x9b) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&` |
| 244 | `stage_spawn_dispatch_candidate` | `0xb,0x168,0xffffffec,DAT_140e9fd1c % 0xfb + 100` | `if (((uVar3 < 0x96) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&` |
| 269 | `stage_spawn_dispatch_candidate` | `0x35,0x96,0x2e4,100` | `if (iVar4 < 0x1bee) { \| if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14012991b;` |
| 270 | `stage_spawn_dispatch_candidate` | `0x35,0x96,0xffffffec,0xa0` | `if (iVar4 < 0x1bee) { \| if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14012991b;` |
| 271 | `stage_spawn_dispatch_candidate` | `0x35,0x96,0x2e4,0xdc` | `if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14012991b;` |
| 272 | `stage_spawn_dispatch_candidate` | `0x35,0x96,0xffffffec,0x118` | `if ((int)uVar3 < 0) { \| if (uVar3 != 0) goto LAB_14012991b;` |
| 293 | `stage_spawn_dispatch_candidate` | `0x47,2000,0x1fe,0xfa` | `if ((int)uVar3 < 0) { \| if (uVar3 == 0) goto LAB_14012995f; \| if ((int)uVar7 == 0x1e78) {` |
| 297 | `stage_spawn_dispatch_candidate` | `0x48,2000,0xd2,0x96` | `if (uVar3 == 0) goto LAB_14012995f; \| if ((int)uVar7 == 0x1e78) { \| if ((int)uVar7 == 0x1ec8) {` |
| 301 | `stage_spawn_dispatch_candidate` | `0x58,0x640,0x104,0xffffff9c` | `if ((int)uVar7 == 0x1ec8) { \| if ((int)uVar7 == 0x1fd6) {` |
| 302 | `stage_spawn_dispatch_candidate` | `0x58,0x640,0x6e,0xffffff6a` | `if ((int)uVar7 == 0x1ec8) { \| if ((int)uVar7 == 0x1fd6) {` |
| 303 | `stage_spawn_dispatch_candidate` | `0x58,0x640,0xffffffd8,0xffffff38` | `if ((int)uVar7 == 0x1ec8) { \| if ((int)uVar7 == 0x1fd6) {` |
| 307 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x1cc,0xffffff38` | `if ((int)uVar7 == 0x1fd6) { \| if ((int)uVar7 == 0x203a) {` |
| 308 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x262,0xffffff6a` | `if ((int)uVar7 == 0x1fd6) { \| if ((int)uVar7 == 0x203a) {` |
| 309 | `stage_spawn_dispatch_candidate` | `0x57,0x640,0x2f8,0xffffff9c` | `if ((int)uVar7 == 0x203a) {` |
| 314 | `stage_spawn_dispatch_candidate` | `8,5000,0x1cc,0,uVar10,uVar12` | `if ((int)uVar7 == 0x203a) { \| if ((int)uVar7 == 0x20d0) {` |
| 318 | `stage_spawn_dispatch_candidate` | `0x4d,6000,0xffffff6a,0,uVar10` | `if ((int)uVar7 == 0x20d0) { \| if ((int)uVar7 == 0x2166) {` |
| 329 | `stage_spawn_dispatch_candidate` | `0x36,0x15e,0x2e4,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0xe6) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 340 | `stage_spawn_dispatch_candidate` | `0x36,0x15e,0xffffffec,DAT_140e9fd1c % 0xc9 + 300` | `if ((uVar3 < 0xdc) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 365 | `stage_spawn_dispatch_candidate` | `0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `else if ((DAT_140e418cc == 0) && (uVar5 = uVar3 - 0x23f0, uVar5 < 2000)) { \| if (((int)uVar3 < 0x27c4) && (uVar5 == ((int)uVar5 / 0x18) * 0x18)) {` |
| 376 | `stage_spawn_dispatch_candidate` | `0xd,400,0xffffffec,DAT_140e9fd1c % 0x12d + 0x96` | `if ((uVar3 < 0xf0) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 387 | `stage_spawn_dispatch_candidate` | `0xd,400,0x2e4,DAT_140e9fd1c % 0x12d + 0x96` | `if ((uVar3 < 0xeb) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 391 | `stage_spawn_dispatch_candidate` | `0x39,7000,0x262,0xffffffb0` | `if ((int)uVar7 == 0x2968) {` |
| 407 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0xf1 + 0x50,0xffffffec` | `if (uVar3 == 0) {` |
| 412 | `stage_spawn_dispatch_candidate` | `0x3a,7000,0xffffffb0,200` | `if ((int)uVar7 == 0x29cc) {` |
| 416 | `stage_spawn_dispatch_candidate` | `0x39,7000,0x6e,0xffffffb0` | `if ((int)uVar7 == 0x29cc) { \| if ((int)uVar7 == 0x2a30) {` |
| 432 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0xf1 + 400,0xffffffec` | `if (uVar3 == 0) {` |
| 437 | `stage_spawn_dispatch_candidate` | `0x3a,7000,800,200` | `if ((int)uVar7 == 0x2a94) {` |
| 442 | `stage_spawn_dispatch_candidate` | `0x76,12000,0xe6,0x348,uVar10,uVar12` | `if ((int)uVar7 == 0x2a94) { \| if ((int)uVar7 == 0x2bf2) {` |
| 446 | `stage_spawn_dispatch_candidate` | `0x76,12000,0x1ea,0x348,uVar10` | `if ((int)uVar7 == 0x2bf2) { \| if ((int)uVar7 == 0x2c1a) {` |
| 457 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec` | `if ((uVar3 < 0xb4) && (uVar3 == ((int)uVar3 / 5) * 5)) {` |
| 483 | `stage_spawn_dispatch_candidate` | `0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((DAT_140e418cc == 0) && (uVar5 = uVar3 - 12000, uVar5 < 0x6a4)) { \| if (((int)uVar3 < 0x3340) && (uVar5 == ((int)uVar5 / 0x12) * 0x12)) {` |
| 495 | `stage_spawn_dispatch_candidate` | `0x19,500,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar3 < 0x460) && (uVar3 == ((int)uVar3 / 0x18) * 0x18)) {` |
| 507 | `stage_spawn_dispatch_candidate` | `0x9b,5000,DAT_140e9fd1c % 0x65 + 0x1cc, ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x65 + 0x96` | `if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 100) * 100)) {` |
| 521 | `stage_spawn_dispatch_candidate` | `0x45,400,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec` | `if (((uVar3 < 0x168) && (iVar4 = (int)uVar3 % 0x96, iVar4 < 0x3c)) &&` |
| 527 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0x168,0,uVar11,uVar12` | `if ((int)uVar7 == 0x3584) {` |
| 531 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0x1fe,0,uVar11` | `if ((int)uVar7 == 0x3584) { \| if ((int)uVar7 == 0x35b6) {` |
| 535 | `stage_spawn_dispatch_candidate` | `0x1b,0x1130,0xd2,0` | `if ((int)uVar7 == 0x35b6) { \| if ((int)uVar7 == 0x35e8) {` |
| 559 | `stage_spawn_dispatch_candidate` | `0x1a,400,DAT_140e9fd1c % 0x231 + 0x50,0xffffffec` | `if ((DAT_140e418cc != 0) \|\| (uVar5 = uVar3 - 0x3714, 1999 < uVar5)) goto LAB_14012ad20; \| if (((int)uVar3 < 0x3bc4) && (uVar5 == ((int)uVar5 / 0x13) * 0x13)) {` |
| 570 | `stage_spawn_dispatch_candidate` | `0x25,600,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar3 < 0x4b0) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 582 | `stage_spawn_dispatch_candidate` | `0xa1,5000,DAT_140e9fd1c % 0x65 + 0xa0, ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3) % 0x65 + 0x96` | `if ((uVar3 < 400) && (uVar3 == ((int)uVar3 / 100) * 100)) {` |
| 590 | `stage_spawn_dispatch_candidate` | `0x44,0xfa,iVar4,0xffffffec` | `if ((int)uVar7 == 0x3e1c) {` |
| 596 | `stage_spawn_dispatch_candidate` | `0xf,5000,0xffffff88,0x96` | `if ((int)uVar7 != 0x3e44) goto LAB_14012ad20;` |
| 597 | `stage_spawn_dispatch_candidate` | `0xf,5000,0x348,0x96` | `if ((int)uVar7 != 0x3e44) goto LAB_14012ad20;` |
| 603 | `stage_spawn_dispatch_candidate` | `0xa4,50000,0xffffff9c,0xb4,uVar11,uVar12` | `if ((int)uVar7 != 0x3e44) goto LAB_14012ad20; \| if (uVar3 == 0x3ee4) {` |
| 622 | `stage_spawn_dispatch_candidate` | `0x9e,5000,0x1cc,0xfa,uVar11` | `if (uVar3 == 0x42cc) {` |
| 626 | `stage_spawn_dispatch_candidate` | `0x9e,5000,0x104,0xb4` | `if (uVar3 == 0x42cc) { \| if (uVar3 == 0x42fe) {` |
| 631 | `stage_spawn_dispatch_candidate` | `8,5000,0x1cc,0,uVar11` | `if (uVar3 == 0x42fe) { \| if (uVar3 == 0x4394) {` |
| 24 | `stage_intro_banner_event_candidate` | `DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0` | `` |

### Stage `10`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 82 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x1e0,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 87 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xf0,0xffffffec` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x72) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 99 | `stage_spawn_dispatch_candidate` | `0xfc,800,iVar5 * 10,0xffffffec` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xd) * 0xd)) { \| if (iVar5 < 0x32) {` |
| 104 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,0x96` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 109 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xffffffec,0xf0` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 114 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,0x140` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 125 | `stage_spawn_dispatch_candidate` | `0xfb,400,DAT_140e9fd1c % 0x231 + 0x50,0` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 129 | `stage_spawn_dispatch_candidate` | `6,5000,0x1cc,0` | `if ((int)uVar4 == 0x44c) {` |
| 140 | `stage_spawn_dispatch_candidate` | `0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec` | `if ((uVar3 < 0x1c2) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 145 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xb4,0xffffffec` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 150 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,200` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 155 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xffffffec,0x168` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 160 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x21c,0xffffffec` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 171 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0` | `if ((uVar3 < 1000) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 175 | `stage_spawn_dispatch_candidate` | `0x103,4000,0x2c6,0xffffff38` | `if ((int)uVar4 == 0xbea) {` |
| 179 | `stage_spawn_dispatch_candidate` | `0x103,4000,0x35c,0xffffff6a` | `if ((int)uVar4 == 0xbea) { \| if ((int)uVar4 == 0xc30) {` |
| 184 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,0x96` | `if ((int)uVar4 == 0xc30) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 189 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xffffffec,0xf0` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 193 | `stage_spawn_dispatch_candidate` | `0x104,4000,0xffffffd8,0xffffff38` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((int)uVar4 == 0xd7a) {` |
| 197 | `stage_spawn_dispatch_candidate` | `0xfe,7000,0x21c,200` | `if ((int)uVar4 == 0xd7a) { \| if ((int)uVar4 == 0xdd4) {` |
| 208 | `stage_spawn_dispatch_candidate` | `0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 224 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0` | `if (uVar3 == 0) {` |
| 229 | `stage_spawn_dispatch_candidate` | `0x102,7000,0x1e0,0` | `if ((int)uVar4 == 0x12c0) {` |
| 234 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x1cc,0xffffffec` | `if ((int)uVar4 == 0x12c0) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 245 | `stage_spawn_dispatch_candidate` | `0xfd,1000,DAT_140e9fd1c % 0x191 + 0xd2,0` | `if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {` |
| 256 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0xc9 + 0x6e,0` | `if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {` |
| 260 | `stage_spawn_dispatch_candidate` | `0x100,6000,0xb4,300` | `if ((int)uVar4 == 0x146e) {` |
| 264 | `stage_spawn_dispatch_candidate` | `0x100,6000,0x21c,200` | `if ((int)uVar4 == 0x146e) { \| if ((int)uVar4 == 0x14c8) {` |
| 268 | `stage_spawn_dispatch_candidate` | `0xfd,1000,0x78,0` | `if ((int)uVar4 == 0x14c8) { \| if ((int)uVar4 == 0x159a) {` |
| 269 | `stage_spawn_dispatch_candidate` | `0xfd,1000,0x10e,0` | `if ((int)uVar4 == 0x14c8) { \| if ((int)uVar4 == 0x159a) {` |
| 270 | `stage_spawn_dispatch_candidate` | `0xfd,1000,0x1c2,0` | `if ((int)uVar4 == 0x14c8) { \| if ((int)uVar4 == 0x159a) {` |
| 271 | `stage_spawn_dispatch_candidate` | `0xfd,1000,600,0` | `if ((int)uVar4 == 0x14c8) { \| if ((int)uVar4 == 0x159a) {` |
| 283 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x17d + 0x50,0` | `if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 294 | `stage_spawn_dispatch_candidate` | `0xfc,800,DAT_140e9fd1c % 0x191 + 0xd2,0` | `if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 300 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x1a4,0xffffffec` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 304 | `stage_spawn_dispatch_candidate` | `0x102,7000,0x168,0` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((int)uVar4 == 0x1a18) {` |
| 309 | `stage_spawn_dispatch_candidate` | `0xfa,300,300,0xffffffec` | `if ((int)uVar4 == 0x1a18) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 320 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0xffffffec` | `if ((uVar3 < 800) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {` |
| 324 | `stage_spawn_dispatch_candidate` | `0xfe,0x157c,0xb4,0xfa` | `if ((int)uVar4 == 7000) {` |
| 328 | `stage_spawn_dispatch_candidate` | `0xfe,0x157c,0xb4,200` | `if ((int)uVar4 == 7000) { \| if ((int)uVar4 == 0x1bbc) {` |
| 332 | `stage_spawn_dispatch_candidate` | `0xfe,0x157c,0xb4,0x96` | `if ((int)uVar4 == 0x1bbc) { \| if ((int)uVar4 == 0x1c20) {` |
| 336 | `stage_spawn_dispatch_candidate` | `0x102,5000,0x208,0` | `if ((int)uVar4 == 0x1c20) { \| if ((int)uVar4 == 0x1d1a) {` |
| 340 | `stage_spawn_dispatch_candidate` | `0x102,5000,200,0` | `if ((int)uVar4 == 0x1d1a) { \| if ((int)uVar4 == 0x1d7e) {` |
| 344 | `stage_spawn_dispatch_candidate` | `0x102,5000,0x168,0` | `if ((int)uVar4 == 0x1d7e) { \| if ((int)uVar4 == 0x1de2) {` |
| 356 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0` | `if ((699 < uVar3) \|\| (uVar3 != ((int)uVar3 / 0x1e) * 0x1e)) goto LAB_14012c7c3;` |
| 368 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0` | `if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {` |
| 379 | `stage_spawn_dispatch_candidate` | `0xfd,1000,DAT_140e9fd1c % 0x191 + 0x6e,0` | `if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {` |
| 392 | `stage_spawn_dispatch_candidate` | `0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0` | `if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {` |
| 396 | `stage_spawn_dispatch_candidate` | `0x104,4000,0x3c,0xffffff9c` | `if ((int)uVar4 == 9000) {` |
| 400 | `stage_spawn_dispatch_candidate` | `0x104,4000,0xffffffa6,0xffffff6a` | `if ((int)uVar4 == 9000) { \| if ((int)uVar4 == 0x235a) {` |
| 404 | `stage_spawn_dispatch_candidate` | `0x104,4000,0xffffff10,0xffffff38` | `if ((int)uVar4 == 0x235a) { \| if ((int)uVar4 == 0x238c) {` |
| 409 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,0x168` | `if ((int)uVar4 == 0x238c) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 414 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xffffffec,0xf0` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 419 | `stage_spawn_dispatch_candidate` | `0xfa,300,0x2e4,0xa0` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 424 | `stage_spawn_dispatch_candidate` | `0xfa,300,0xffffffec,300` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {` |
| 428 | `stage_spawn_dispatch_candidate` | `0x100,6000,0xb4,0xfa` | `if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) { \| if ((int)uVar4 == 0x2544) {` |
| 432 | `stage_spawn_dispatch_candidate` | `0x100,6000,0x21c,0x96` | `if ((int)uVar4 == 0x2544) { \| if ((int)uVar4 == 0x26ac) {` |
| 443 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0` | `if ((uVar3 < 0x348) && (uVar3 == ((int)uVar3 / 0x1c) * 0x1c)) {` |
| 447 | `stage_spawn_dispatch_candidate` | `0x103,4000,0x35c,0xffffff88` | `if ((int)uVar4 == 0x28a0) {` |
| 460 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0` | `if ((uVar6 < 200) && (uVar6 == ((int)uVar6 / 7) * 7)) {` |
| 472 | `stage_spawn_dispatch_candidate` | `0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0` | `if ((uVar6 < 400) && (uVar6 == ((int)uVar6 / 0xf) * 0xf)) {` |
| 476 | `stage_spawn_dispatch_candidate` | `0x102,5000,0xf0,0` | `if (uVar3 == 0x2b5c) {` |
| 480 | `stage_spawn_dispatch_candidate` | `0x102,5000,0x1e0,0` | `if (uVar3 == 0x2b5c) { \| if (uVar3 == 0x2c24) {` |
| 485 | `stage_spawn_dispatch_candidate` | `0xfc,800,0x3c,0` | `if (uVar3 == 0x2c24) { \| if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 486 | `stage_spawn_dispatch_candidate` | `0xfc,800,0xb4,0` | `if (uVar3 == 0x2c24) { \| if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 487 | `stage_spawn_dispatch_candidate` | `0xfc,800,300,0` | `if (uVar3 == 0x2c24) { \| if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 488 | `stage_spawn_dispatch_candidate` | `0xfc,800,0x1a4,0` | `if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 489 | `stage_spawn_dispatch_candidate` | `0xfc,800,0x21c,0` | `if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 490 | `stage_spawn_dispatch_candidate` | `0xfc,800,0x294,0` | `if (((uVar3 == 0x2cd8) \|\| (uVar3 == 0x2d14)) \|\| (uVar3 == 0x2d50)) {` |
| 494 | `stage_spawn_dispatch_candidate` | `7,5000,0x104,0` | `if (uVar3 == 0x2db4) {` |

### Stage `00`

| Line | Helper | Args | Nearby condition/context |
|---:|---|---|---|
| 188 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0xf0,0` | `case 8: \| case 9: \| if (DAT_140e418c8 == 100) {` |
| 189 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0x1e0,0` | `case 9: \| if (DAT_140e418c8 == 100) {` |
| 192 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0xdc,0` | `case 9: \| if (DAT_140e418c8 == 100) { \| if (DAT_140e9fd0c == 2) {` |
| 193 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0x168,0` | `if (DAT_140e418c8 == 100) { \| if (DAT_140e9fd0c == 2) {` |
| 194 | `stage_spawn_dispatch_candidate` | `0,0x5dc,500,0` | `if (DAT_140e418c8 == 100) { \| if (DAT_140e9fd0c == 2) {` |
| 198 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0x78,0` | `if (DAT_140e9fd0c == 2) { \| if (DAT_140e9fd0c == 6) {` |
| 199 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0x118,0` | `if (DAT_140e9fd0c == 2) { \| if (DAT_140e9fd0c == 6) {` |
| 200 | `stage_spawn_dispatch_candidate` | `0,0x5dc,0x1b8,0` | `if (DAT_140e9fd0c == 6) {` |
| 201 | `stage_spawn_dispatch_candidate` | `0,0x5dc,600,0` | `if (DAT_140e9fd0c == 6) {` |
| 230 | `stage_spawn_dispatch_candidate` | `2,8000,0x168,0` | `case 0xd: \| case 0xe: \| if (DAT_140e418c8 == 100) {` |
| 233 | `stage_spawn_dispatch_candidate` | `2,8000,0xb4,0` | `case 0xe: \| if (DAT_140e418c8 == 100) { \| if (DAT_140e9fd0c == 1) {` |
| 237 | `stage_spawn_dispatch_candidate` | `2,8000,0x21c,0` | `if (DAT_140e418c8 == 100) { \| if (DAT_140e9fd0c == 1) { \| if (DAT_140e9fd0c == 3) {` |
| 241 | `stage_spawn_dispatch_candidate` | `2,8000,0xdc,0` | `if (DAT_140e9fd0c == 3) { \| if (DAT_140e9fd0c == 5) {` |
| 242 | `stage_spawn_dispatch_candidate` | `2,8000,500,0` | `if (DAT_140e9fd0c == 3) { \| if (DAT_140e9fd0c == 5) {` |
| 316 | `stage_spawn_dispatch_candidate` | `1,3000,0x168,0` | `case 0x12: \| case 0x13: \| if (DAT_140e418c8 == 0xa0) {` |
| 319 | `stage_spawn_dispatch_candidate` | `1,3000,0xb4,0` | `case 0x13: \| if (DAT_140e418c8 == 0xa0) { \| if (DAT_140e9fd0c == 1) {` |
| 320 | `stage_spawn_dispatch_candidate` | `1,3000,0x21c,0` | `case 0x13: \| if (DAT_140e418c8 == 0xa0) { \| if (DAT_140e9fd0c == 1) {` |
| 324 | `stage_spawn_dispatch_candidate` | `1,3000,0xa0,0` | `if (DAT_140e9fd0c == 1) { \| if (DAT_140e9fd0c == 4) {` |
| 325 | `stage_spawn_dispatch_candidate` | `1,3000,0x168,0` | `if (DAT_140e9fd0c == 1) { \| if (DAT_140e9fd0c == 4) {` |
| 326 | `stage_spawn_dispatch_candidate` | `1,3000,0x230,0` | `if (DAT_140e9fd0c == 1) { \| if (DAT_140e9fd0c == 4) {` |
| 330 | `stage_spawn_dispatch_candidate` | `3,40000,0x168,0` | `if (DAT_140e9fd0c == 4) { \| if (DAT_140e9fd0c == 8) {` |
| 476 | `stage_spawn_dispatch_candidate` | `4,10000,0x1c5,0` | `case 0x1b: \| if (DAT_140e418c8 == 100) {` |
| 490 | `stage_spawn_dispatch_candidate` | `4,10000,DAT_140e9fd1c % 0x169 + 0x78,0` | `if (uVar9 == 1) {` |
| 548 | `stage_spawn_dispatch_candidate` | `5,99999999,0x168,0` | `case 0x1c: \| case 0x1d: \| if (DAT_140e418c8 == 0x82) {` |
| 587 | `stage_spawn_dispatch_candidate` | `5,99999999,0x168,0` | `if ((DAT_140e45d34 == 0) && (DAT_140e418c8 == 0xa1)) { \| else if (DAT_140e418c8 == 0xdc) {` |
| 57 | `stage_intro_skip_prompt_candidate` | `2` | `else if (DAT_140e418c8 == 0x78) { \| case 1:` |
| 61 | `stage_intro_skip_prompt_candidate` | `3` | `case 1: \| case 2:` |
| 65 | `stage_intro_skip_prompt_candidate` | `4` | `case 2: \| case 3:` |
| 69 | `stage_intro_skip_prompt_candidate` | `5` | `case 3: \| case 4:` |
| 174 | `stage_intro_skip_prompt_candidate` | `7` | `case 6:` |
| 178 | `stage_intro_skip_prompt_candidate` | `8` | `case 6: \| case 7:` |
| 182 | `stage_intro_skip_prompt_candidate` | `9` | `case 7: \| case 8:` |
| 212 | `stage_intro_skip_prompt_candidate` | `0xb` | `if (10 < (int)DAT_140e9fd0c) { \| case 10:` |
| 216 | `stage_intro_skip_prompt_candidate` | `0xc` | `case 10: \| case 0xb:` |
| 220 | `stage_intro_skip_prompt_candidate` | `0xd` | `case 0xb: \| case 0xc:` |
| 224 | `stage_intro_skip_prompt_candidate` | `0xe` | `case 0xc: \| case 0xd:` |
| 298 | `stage_intro_skip_prompt_candidate` | `0x10` | `case 0xf:` |
| 302 | `stage_intro_skip_prompt_candidate` | `0x11` | `case 0xf: \| case 0x10:` |
| 306 | `stage_intro_skip_prompt_candidate` | `0x12` | `case 0x10: \| case 0x11:` |
| 310 | `stage_intro_skip_prompt_candidate` | `0x13` | `case 0x11: \| case 0x12:` |
| 404 | `stage_intro_skip_prompt_candidate` | `0x13` | `case 0x14:` |
| 408 | `stage_intro_skip_prompt_candidate` | `0x16` | `case 0x14: \| case 0x15:` |
| 412 | `stage_intro_skip_prompt_candidate` | `0x17` | `case 0x15: \| case 0x16:` |
| 458 | `stage_intro_skip_prompt_candidate` | `0x19` | `if (bVar12) { \| if (DAT_140e46c88 != (undefined4 *)0x0) {` |
| 462 | `stage_intro_skip_prompt_candidate` | `0x1a` | `case 0x19:` |
| 466 | `stage_intro_skip_prompt_candidate` | `0x1b` | `case 0x19: \| case 0x1a:` |
| 542 | `stage_intro_skip_prompt_candidate` | `0x1d` | `case 0x1c:` |
| 562 | `stage_intro_skip_prompt_candidate` | `0x1f` | `case 0x1e:` |
| 566 | `stage_intro_skip_prompt_candidate` | `0x20` | `case 0x1e: \| case 0x1f:` |
| 570 | `stage_intro_skip_prompt_candidate` | `0x21` | `case 0x1f: \| case 0x20:` |
| 648 | `stage_intro_skip_prompt_candidate` | `0x21` | `case 0x22:` |
| 657 | `stage_intro_skip_prompt_candidate` | `0x24` | `if (DAT_140e418c8 == 0xa0) { \| case 0x23:` |
| 661 | `stage_intro_skip_prompt_candidate` | `0x25` | `case 0x23: \| case 0x24:` |
| 707 | `stage_intro_skip_prompt_candidate` | `0x27` | `if (bVar12) { \| if (DAT_140e46c88 != (undefined4 *)0x0) {` |
| 711 | `stage_intro_skip_prompt_candidate` | `0x28` | `case 0x27:` |
| 715 | `stage_intro_skip_prompt_candidate` | `0x29` | `case 0x27: \| case 0x28:` |
| 719 | `stage_intro_skip_prompt_candidate` | `0x2a` | `case 0x28: \| case 0x29:` |
| 723 | `stage_intro_skip_prompt_candidate` | `0x2b` | `case 0x29: \| case 0x2a:` |
| 727 | `stage_intro_skip_prompt_candidate` | `0x2c` | `case 0x2a: \| case 0x2b:` |
| 731 | `stage_intro_skip_prompt_candidate` | `0x2d` | `case 0x2b: \| case 0x2c:` |
| 777 | `stage_intro_skip_prompt_candidate` | `0x2f` | `if (bVar12) { \| if (DAT_140e46c88 != (undefined4 *)0x0) {` |
| 415 | `stage_continue_prompt_candidate` | `0x18,0` | `case 0x16: \| case 0x17:` |
| 664 | `stage_continue_prompt_candidate` | `0x26,1` | `case 0x24: \| case 0x25:` |
| 734 | `stage_continue_prompt_candidate` | `0x2e,2` | `case 0x2c: \| case 0x2d:` |
| 76 | `stage_hud_or_option_panel_candidate` | `0` | `case 5: \| if (DAT_140e445f0 != 0.0) {` |
| 186 | `stage_hud_or_option_panel_candidate` | `1` | `case 8: \| case 9:` |
| 228 | `stage_hud_or_option_panel_candidate` | `2` | `case 0xd: \| case 0xe:` |
| 314 | `stage_hud_or_option_panel_candidate` | `4` | `case 0x12: \| case 0x13:` |
| 470 | `stage_hud_or_option_panel_candidate` | `4` | `case 0x1a: \| case 0x1b:` |
| 546 | `stage_hud_or_option_panel_candidate` | `5` | `case 0x1c: \| case 0x1d:` |
| 574 | `stage_hud_or_option_panel_candidate` | `3` | `case 0x20: \| case 0x21:` |

