// Function: stage_03_gameplay_update_candidate @ 14011b3d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_03_gameplay_update_candidate(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  uint uVar8;
  bool bVar9;
  double dVar10;
  uint uVar11;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined1 local_38 [16];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar6 = 0;
  uVar11 = 0;
  FUN_14012e8e0(DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar5 = (ulonglong)DAT_140e418c8;
  uVar4 = DAT_140e418c8 - 0x10e;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x23) * 0x23)) {
    uVar4 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,700,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 500) {
    FUN_14007b710(0x26,5000,0x208,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 600) {
    FUN_14007b710(0x26,5000,200,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 700;
  if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x18) * 0x18)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,600,DAT_140e9fd1c % 0x1a5 + 0xb4,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x3ac) {
    FUN_14007b710(0x27,7000,0x21c,300);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x47e) {
    FUN_14007b710(0x29,7000,0xb4,0xfa);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x546) {
    FUN_14007b710(7,5000,0x1cc,0);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x5dc) {
    local_68 = _DAT_14053c020;
    uStack_60 = _UNK_14053c028;
    local_48 = _DAT_14053c1c0;
    uStack_40 = _UNK_14053c1c8;
    local_38._0_8_ = 0xc41d8000441d8000;
    local_58 = _DAT_14053c100;
    uVar5 = uVar6;
    do {
      FUN_14007b710(0x2c,0x640,(int)*(float *)(&local_68 + uVar5),
                    (int)*(float *)((longlong)&local_68 + uVar5 * 8 + 4));
      uVar5 = uVar5 + 1;
    } while (uVar5 < 7);
    FUN_14007b710(0x2d,6000,0x1ea,0xfffffda8);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x5dc;
  if ((uVar4 < 500) && (uVar4 == ((int)uVar4 / 0x30) * 0x30)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,500,DAT_140e9fd1c % 0xc9 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x8fc;
  if (uVar4 < 0x96) {
    uVar4 = uVar4 & 0x8000000f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
    }
    if (uVar4 == 0) {
      uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar4 * 0x800 ^ uVar4;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0xb,300,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96);
      uVar5 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar5 == 0x992) {
    FUN_14007b710(0x29,6000,0x1e0,300);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0xa8c;
  if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5;
  if (uVar4 == 0xb40) {
    FUN_14007b710(0x2e,65000,0x168,0xffffff88);
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (uVar8 = uVar4 - 3000, 0x513 < uVar8)) goto LAB_14011bc5f;
    if (uVar8 == ((int)uVar8 / 0x2d) * 0x2d) {
      uVar4 = ((uint)(uVar5 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar4 * 0x800 ^ uVar4;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0x25,500,DAT_140e9fd1c % 0x141 + 200,0xffffffec);
      uVar5 = (ulonglong)DAT_140e418c8;
    }
    uVar4 = (uint)uVar5 - 3000;
    if ((0x513 < uVar4) || (uVar4 != ((int)uVar4 / 0x15) * 0x15)) goto LAB_14011bc5f;
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
  }
  uVar5 = (ulonglong)DAT_140e418c8;
LAB_14011bc5f:
  if ((int)uVar5 == 0x1130) {
    local_68 = _DAT_14053bff0;
    uStack_60 = _UNK_14053bff8;
    local_48 = _DAT_14053c200;
    uStack_40 = _UNK_14053c208;
    local_58 = _DAT_14053c0c0;
    uVar5 = uVar6;
    do {
      FUN_14007b710(0x2c,0x5dc,(int)*(float *)(&local_68 + uVar5),
                    (int)*(float *)((longlong)&local_68 + uVar5 * 8 + 4));
      uVar5 = uVar5 + 1;
    } while (uVar5 < 6);
    FUN_14007b710(0x2d,0x1518,0xd2,0xffffff1f);
    FUN_14007b710(0x2d,0x1518,0x113,0xfffffdbc);
    uVar5 = (ulonglong)DAT_140e418c8;
    if (DAT_140e418c8 == 0x1130) {
      FUN_14007b710(0x26,5000,0x21c,0xffffffec);
      uVar5 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar4 = (uint)uVar5 - 0x12c0;
  if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0xc) * 0xc)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,0x2e4,DAT_140e9fd1c % 0x97 + 0x96);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x141e;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,500,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x14a0) {
    FUN_14007b710(0x26,4000,0xd2,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x1518) {
    FUN_14007b710(0x27,7000,0x21c,300);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x15e0) {
    FUN_14007b710(0x2b,12000,0x1b8,0);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1676;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xc) * 0xc)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x15f + 0x6e,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x170c) {
    FUN_14007b710(0x26,5000,0x168,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x173e;
  if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x19) * 0x19)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x17d4) {
    FUN_14007b710(0x26,5000,200,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1806;
  if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x189c) {
    FUN_14007b710(0x26,5000,0x208,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x18ce;
  if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar8 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    uVar4 = uVar8 * 0x800 ^ uVar8;
    DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x1946) {
    FUN_14007b710(0x26,4000,0xf0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x1964) {
    FUN_14007b710(0x26,4000,0x1e0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x19f0) {
    FUN_14007b710(0x29,4000,0xf0,300);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x1a2c) {
    FUN_14007b710(0x29,4000,0x1e0,0xfa);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1acc;
  if ((uVar4 < 0x5a) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 7000) {
    FUN_14007b710(0x2b,12000,0x118,0);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1bf8;
  if ((uVar4 < 0xf0) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x1c84) {
    local_68 = _DAT_14053bfe0;
    uStack_60 = _UNK_14053bfe8;
    local_48 = _DAT_14053c110;
    uStack_40 = _UNK_14053c118;
    local_58._8_8_ = _UNK_14053c008;
    local_58._0_8_ = _DAT_14053c000;
    local_28 = _DAT_14053c1d0;
    uStack_20 = _UNK_14053c1d8;
    local_38 = _DAT_14053c140;
    local_18 = 0x43700000;
    local_14 = 0xc41ec000;
    do {
      FUN_14007b710(0x2c,0x578,(int)*(float *)(&local_68 + uVar6),
                    (int)*(float *)((longlong)&local_68 + uVar6 * 8 + 4));
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xb);
    FUN_14007b710(0x2d,0x1068,0xa5,0xfffffea2);
    FUN_14007b710(0x2d,0x1068,0x235,0xfffffda3);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1dec;
  if ((uVar4 < 0x186) && (uVar4 == ((int)uVar4 / 0x32) * 0x32)) {
    uVar4 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,500,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5 - 0x1fa4;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar8 = ((uint)(uVar5 >> 0x1e) ^ (uint)uVar5) * 0x6c078965 + 1;
    uVar4 = uVar8 * 0x800 ^ uVar8;
    DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x25,400,DAT_140e9fd1c % 0xc9 + 0x104,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x2008) {
    FUN_14007b710(0x26,6000,0x168,0xffffffec);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x209e) {
    FUN_14007b710(0x27,6000,0x1e0,300);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar5 == 0x20d0) {
    FUN_14007b710(0x29,5000,0xf0,0xfa);
    uVar5 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar5;
  if (uVar4 - 0x2198 < 100) {
    uVar8 = uVar4 - 0x2198 & 0x8000000f;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
    }
    if (uVar8 == 0) {
      uVar8 = ((uint)(uVar5 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
      uVar4 = uVar8 * 0x800 ^ uVar8;
      DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
      uVar4 = DAT_140e418c8;
    }
  }
  if (uVar4 == 0x21fc) {
    FUN_14007b710(0x2b,12000,0x1b8,0);
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == 0x22f6) {
    FUN_14007b710(8,5000,0x104,0);
    uVar4 = DAT_140e418c8;
  }
  puVar3 = DAT_140e45d28;
  if ((uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar2 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar3 = (undefined8 *)_malloc_base(0x60);
    if (puVar3 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar9 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar3 = 1;
    *(undefined4 *)(puVar3 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar3 + 0xc) = uVar2;
    puVar3[2] = 0x6f;
    puVar3[3] = 0;
    *(undefined4 *)(puVar3 + 4) = 0;
    *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
    puVar3[5] = 0;
    puVar3[6] = 0x3ff0000000000000;
    puVar3[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar3 + 8) = 300;
    *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
    *(undefined4 *)(puVar3 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
    puVar3[10] = 0xff;
    puVar3[0xb] = 0;
    if (bVar9) {
      DAT_140e45d78 = puVar3;
    }
    uVar4 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar3;
      uVar4 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar3;
  iVar1 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar1 <= (int)uVar4) &&
     ((int)uVar4 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar10 = (double)FUN_140332d90(((double)(int)uVar4 - (double)iVar1) * DAT_14053a4d8 *
                                   DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar10 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    uVar4 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar4) &&
     ((int)uVar4 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    FUN_140079b00();
    FUN_14006c420();
    puVar7 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar7,0);
      puVar7 = puVar7 + 1;
    } while ((longlong)puVar7 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e4513c);
    FUN_14018a340(DAT_140e4513c,3,1);
    DAT_140e45100 = DAT_140e4513c;
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x13a,100000,0,DAT_14053ae30,DAT_14053adb4,uVar11 & 0xffff0000,DAT_140539f00,0x96,
                  1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 4;
  }
  return;
}


