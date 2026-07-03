// Function: stage_02_gameplay_update_candidate @ 140119640
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_02_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  double dVar11;
  uint uVar12;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar6 = 0;
  uVar12 = 0;
  FUN_14012e8e0(DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar4 = (ulonglong)DAT_140e418c8;
  uVar3 = DAT_140e418c8 - 0x10e;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
    FUN_14007b710(0x19,800,DAT_140e418c8 * 4 + -0x398,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x1cc;
  if ((uVar3 < 0xbe) && (uVar3 == ((int)uVar3 / 0xe) * 0xe)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0xfb + 0x104,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 700) {
    FUN_14007b710(7,5000,0x104,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 800) {
    local_a8 = _DAT_14053c040;
    uStack_a0 = _UNK_14053c048;
    local_88 = _DAT_14053c180;
    uStack_80 = _UNK_14053c188;
    local_68 = _DAT_14053c3b0;
    uStack_60 = _UNK_14053c3b8;
    local_98 = _DAT_14053c120;
    uStack_90 = _UNK_14053c128;
    local_48 = _DAT_14053c3e0;
    uStack_40 = _UNK_14053c3e8;
    local_78 = _DAT_14053c210;
    uStack_70 = _UNK_14053c218;
    local_28 = _DAT_14053c460;
    uStack_20 = _UNK_14053c468;
    local_58 = _DAT_14053c3c0;
    uStack_50 = _UNK_14053c3c8;
    local_d8 = _DAT_14053c090;
    uStack_d0 = _UNK_14053c098;
    local_18 = 0x4419c000;
    local_38 = _DAT_14053c440;
    uStack_30 = _UNK_14053c448;
    local_b8 = _DAT_14053c230;
    uStack_b0 = _UNK_14053c238;
    local_14 = 0xc564c000;
    local_c8 = _DAT_14053c1b0;
    uVar4 = uVar6;
    do {
      FUN_14007b710(0x1d,0x6a4,(int)*(float *)(&local_a8 + uVar4),
                    (int)*(float *)((longlong)&local_a8 + uVar4 * 8 + 4));
      uVar4 = uVar4 + 1;
      uVar5 = uVar6;
    } while (uVar4 < 0x13);
    do {
      FUN_14007b710(0x1e,0x834,(int)*(float *)(&local_d8 + uVar5),
                    (int)*(float *)((longlong)&local_d8 + uVar5 * 8 + 4));
      uVar5 = uVar5 + 1;
    } while (uVar5 < 6);
    FUN_14007b710(0x1f,11000,0x1e4,0xfffff242);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x546;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x6a4) {
    FUN_14007b710(0x1b,0x1130,0x104,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x708) {
    FUN_14007b710(0x1b,0x1130,0x1cc,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x708;
  if ((uVar3 < 200) && (uVar3 == ((int)uVar3 / 0x19) * 0x19)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xd,400,0xffffffec,DAT_140e9fd1c % 0x65 + 0x96);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x7ee;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x19,500,DAT_140e9fd1c % 0xc9 + 0x168,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x898;
  if ((uVar3 < 0x32) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x8ca) {
    FUN_14007b710(0x1b,0x1130,0xf0,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x92e;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,0x2e4,DAT_140e9fd1c % 0x97 + 100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x992;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,0xffffffec,DAT_140e9fd1c % 0x97 + 100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xa28) {
    FUN_14007b710(0x1c,6000,0x348,0x32);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0xaa0;
  if ((uVar3 < 0xa0) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xb54) {
    FUN_14007b710(0x1c,6000,0xffffff88,100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 3000;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0xc4e;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x19,700,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xce4) {
    FUN_14007b710(0x1b,4000,0x168,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xd34) {
    FUN_14007b710(0x1b,4000,0x1fe,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0xd7a;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xe74) {
    FUN_14007b710(0x1c,5000,0x348,0x50);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0xf64;
  if ((uVar3 < 0x8c) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x19,700,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x11bc;
  if ((uVar3 < 0x6e) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,0xffffffec,DAT_140e9fd1c % 0x97 + 100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1248) {
    FUN_14007b710(0x1b,0xe10,0x1e0,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1298) {
    FUN_14007b710(0x1b,0xe10,0xf0,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x12d4;
  if ((uVar3 < 0x28) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x12d + 0xd2,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1306) {
    FUN_14007b710(0x1c,0x1068,0x348,0x50);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x136a) {
    FUN_14007b710(0x1c,0x1068,0xffffff88,0x50);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x13ce) {
    FUN_14007b710(0x1c,0x1068,0x348,0x50);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x1482;
  if (uVar3 < 0x96) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x259 + 0x3c,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (uint)uVar4;
  if (uVar3 == 0x14b4) {
    FUN_14007b710(0x20,0x2b5c,0x168,0xfffffe0c);
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (899 < uVar3 - 0x157c)) goto LAB_14011a9e1;
    uVar9 = uVar3 - 0x1748;
    if ((uVar9 < 0x154) && (uVar9 == ((int)uVar9 / 0x50) * 0x50)) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      FUN_14007b710(10,1000,DAT_140e9fd1c % 0x1f5 + 0x6e,0x32);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar4 - 0x157c;
    if (899 < uVar3) goto LAB_14011a9e1;
    uVar3 = uVar3 & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    if (uVar3 != 0) goto LAB_14011a9e1;
    uVar9 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    uVar3 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x1a,300,DAT_140e9fd1c % 0x259 + 0x3c,0);
  }
  uVar4 = (ulonglong)DAT_140e418c8;
LAB_14011a9e1:
  iVar8 = (int)uVar4;
  if ((((iVar8 == 0x1978) || (iVar8 == 0x19dc)) || (iVar8 == 0x1a40)) ||
     ((iVar8 == 0x1a68 || (iVar8 == 0x1a90)))) {
    FUN_14007b710(0x19,500,0x6e,0xffffffec);
    FUN_14007b710(0x19,500,0xd2,0xffffffec);
    FUN_14007b710(0x19,500,0x136,0xffffffec);
    FUN_14007b710(0x19,500,0x19a,0xffffffec);
    FUN_14007b710(0x19,500,0x1fe,0xffffffec);
    FUN_14007b710(0x19,500,0x262,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x1b1c;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    uVar9 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    uVar3 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0xfb + 0x6e,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 7000;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    uVar9 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    uVar3 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,0x2e4,DAT_140e9fd1c % 0x97 + 100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1bbc) {
    FUN_14007b710(0x1b,0xc80,0x230,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1bee) {
    FUN_14007b710(0x1b,0xc80,0x168,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1c20) {
    FUN_14007b710(0x1b,0xc80,0xa0,0);
    uVar4 = (ulonglong)DAT_140e418c8;
    if (DAT_140e418c8 == 0x1c20) {
      local_a8 = _DAT_14053c010;
      uStack_a0 = _UNK_14053c018;
      local_98 = _DAT_14053c070;
      uStack_90 = _UNK_14053c078;
      local_88 = _DAT_14053c190;
      uStack_80 = _UNK_14053c198;
      local_78 = _DAT_14053c220;
      uStack_70 = _UNK_14053c228;
      local_68 = _DAT_14053c2d0;
      uStack_60 = _UNK_14053c2d8;
      local_58 = _DAT_14053c2e0;
      uStack_50 = _UNK_14053c2e8;
      local_48 = _DAT_14053c300;
      uStack_40 = _UNK_14053c308;
      local_38 = _DAT_14053c320;
      uStack_30 = _UNK_14053c328;
      local_d8 = _DAT_14053c1a0;
      uStack_d0 = _UNK_14053c1a8;
      local_c8 = _DAT_14053c250;
      local_28 = 0xc4d9800043be0000;
      local_b8 = 0xc45fc00043d20000;
      uVar4 = uVar6;
      do {
        FUN_14007b710(0x1d,0x5dc,(int)*(float *)(&local_a8 + uVar4),
                      (int)*(float *)((longlong)&local_a8 + uVar4 * 8 + 4));
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0x11);
      do {
        FUN_14007b710(0x1e,2000,(int)*(float *)(&local_d8 + uVar6),
                      (int)*(float *)((longlong)&local_d8 + uVar6 * 8 + 4));
        uVar6 = uVar6 + 1;
      } while (uVar6 < 5);
      FUN_14007b710(0x1f,8000,0x104,0xfffffcd6);
      FUN_14007b710(0x1f,8000,0x1f9,0xfffffa6f);
      FUN_14007b710(0x1f,8000,0xe6,0xfffff8e4);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (uint)uVar4 - 0x1d88;
  if (uVar3 < 0x8c) {
    uVar3 = uVar3 & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    if (uVar3 == 0) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      FUN_14007b710(0x19,500,DAT_140e9fd1c % 0x15f + 0xa0,0xffffffec);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar4 == 0x2080) {
    FUN_14007b710(0x1c,6000,0xffffff88,100);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4;
  uVar9 = uVar3 - 0x21de;
  if ((uVar9 < 0x82) && (uVar9 == ((int)uVar9 / 0xc) * 0xc)) {
    uVar9 = ((uint)(uVar4 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
    uVar3 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x12d + 0x6e,0xffffffec);
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == 0x238c) {
    FUN_14007b710(8,5000,0x1cc,0);
    uVar3 = DAT_140e418c8;
  }
  puVar2 = DAT_140e45d28;
  if ((uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar1 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar2 = (undefined8 *)_malloc_base(0x60);
    if (puVar2 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar10 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar2 = 1;
    *(undefined4 *)(puVar2 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar2 + 0xc) = uVar1;
    puVar2[2] = 0x6f;
    puVar2[3] = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    *(undefined2 *)((longlong)puVar2 + 0x24) = 0;
    puVar2[5] = 0;
    puVar2[6] = 0x3ff0000000000000;
    puVar2[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar2 + 8) = 300;
    *(undefined4 *)((longlong)puVar2 + 0x44) = 0xff;
    *(undefined4 *)(puVar2 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar2 + 0x4c) = 0xff;
    puVar2[10] = 0xff;
    puVar2[0xb] = 0;
    if (bVar10) {
      DAT_140e45d78 = puVar2;
    }
    uVar3 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar2;
      uVar3 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar2;
  iVar8 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar8 <= (int)uVar3) &&
     ((int)uVar3 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar11 = (double)FUN_140332d90(((double)(int)uVar3 - (double)iVar8) * DAT_14053a4d8 *
                                   DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar11 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    uVar3 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar3) &&
     ((int)uVar3 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
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
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x139,100000,0,DAT_14053ae30,DAT_14053ad9c,uVar12 & 0xffff0000,DAT_140539ee0,0xb4,
                  1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 4;
  }
  return;
}


