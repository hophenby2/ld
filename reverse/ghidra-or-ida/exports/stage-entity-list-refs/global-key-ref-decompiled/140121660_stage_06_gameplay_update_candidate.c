// Function: stage_06_gameplay_update_candidate @ 140121660
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_06_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  float fVar3;
  undefined8 *puVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 *puVar9;
  int iVar10;
  ulonglong uVar11;
  uint uVar12;
  bool bVar13;
  double dVar14;
  uint uVar15;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
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
  
  lVar8 = 0;
  uVar15 = 0;
  stage_intro_banner_event_candidate
            (DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  if (DAT_140e418c8 == 0xfa) {
    stage_spawn_dispatch_candidate(0x57,0x960,0x230,0xffffff6a);
  }
  if (DAT_140e418c8 == 0x118) {
    stage_spawn_dispatch_candidate(0x57,0x960,0x2f8,0xffffff6a);
  }
  uVar11 = (ulonglong)DAT_140e418c8;
  uVar5 = DAT_140e418c8 - 0x15e;
  if ((uVar5 < 0x50) && (uVar5 == ((int)uVar5 / 0xe) * 0xe)) {
    uVar5 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0x1a,300,DAT_140e9fd1c % 0x1c3 + 0x6e,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x1e0;
  if ((uVar5 < 0x46) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x24e) {
    stage_spawn_dispatch_candidate(0x58,0x960,0xa0,0xffffff6a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x262) {
    stage_spawn_dispatch_candidate(0x58,0x960,0xffffffd8,0xffffff6a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x294;
  if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xd,300,0x2e4,DAT_140e9fd1c % 0x65 + 0xfa);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 800;
  if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xd,300,0xffffffec,DAT_140e9fd1c % 0x65 + 300);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 900) {
    stage_spawn_dispatch_candidate(7,5000,0x104,0);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 1000) {
    stage_spawn_dispatch_candidate(0x57,0x960,0x294,0xffffff6a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x3fc) {
    stage_spawn_dispatch_candidate(0x57,0x960,0x348,0xffffff4c);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar1 = DAT_14053ade0;
  if ((int)uVar11 == 0x44c) {
    local_158 = _DAT_14053c030;
    uStack_150 = _UNK_14053c038;
    local_148 = _DAT_14053c080;
    uStack_140 = _UNK_14053c088;
    local_138 = _DAT_14053c0a0;
    uStack_130 = _UNK_14053c0a8;
    local_128 = _DAT_14053c280;
    uStack_120 = _UNK_14053c288;
    local_118 = _DAT_14053c270;
    uStack_110 = _UNK_14053c278;
    local_108 = _DAT_14053c2a0;
    uStack_100 = _UNK_14053c2a8;
    local_f8 = _DAT_14053c2b0;
    uStack_f0 = _UNK_14053c2b8;
    local_e8 = _DAT_14053c4c0;
    uStack_e0 = _UNK_14053c4c8;
    local_d8 = _DAT_14053c550;
    uStack_d0 = _UNK_14053c558;
    local_c8 = _DAT_14053c540;
    uStack_c0 = _UNK_14053c548;
    local_88 = _DAT_14053c130;
    uStack_80 = _UNK_14053c138;
    local_78 = _DAT_14053c2f0;
    uStack_70 = _UNK_14053c2f8;
    local_68 = _DAT_14053c400;
    uStack_60 = _UNK_14053c408;
    local_58 = _DAT_14053c450;
    uStack_50 = _UNK_14053c458;
    local_48 = _DAT_14053c4a0;
    uStack_40 = _UNK_14053c4a8;
    local_38 = _DAT_14053c4b0;
    uStack_30 = _UNK_14053c4b8;
    local_1a8 = _DAT_14053c310;
    uStack_1a0 = _UNK_14053c318;
    local_198 = _DAT_14053c470;
    uStack_190 = _UNK_14053c478;
    local_b8 = 0xc592180044200000;
    local_188 = 0x43700000;
    local_184 = 0xc593f800;
    lVar6 = lVar8;
    do {
      stage_spawn_dispatch_candidate
                (0x5a,0x44c,(int)*(float *)(&local_158 + lVar6),
                 (int)*(float *)((longlong)&local_158 + lVar6 * 8 + 4));
      lVar6 = lVar6 + 1;
      lVar7 = lVar8;
    } while (lVar6 < 0x15);
    do {
      stage_spawn_dispatch_candidate
                (0x5d,0xc80,(int)*(float *)(&local_88 + lVar7),
                 (int)*(float *)((longlong)&local_88 + lVar7 * 8 + 4));
      lVar7 = lVar7 + 1;
      lVar6 = lVar8;
    } while (lVar7 < 0xc);
    do {
      stage_spawn_dispatch_candidate
                (0x5e,0x15e0,(int)*(float *)(&local_1a8 + lVar6),
                 (int)*(float *)((longlong)&local_1a8 + lVar6 * 8 + 4));
      lVar6 = lVar6 + 1;
    } while (lVar6 < 5);
    stage_spawn_dispatch_candidate(0x5f,0x2b5c,0x168,0xffffee76);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x4b0;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5c,800,0x302,(int)uVar11 + -0x64a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x4d8;
  if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5c,800,0x302,(int)uVar11 + -0x6b8);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x898;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5c,800,0xffffffce,(int)uVar11 + -0xa3c);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x8c0;
  if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5c,800,0xffffffce,(int)uVar11 + -0xaa5);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0xd48;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0x302,(int)uVar11 + -0xeec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0xd70;
  if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0xffffffce,(int)uVar11 + -0xf5a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x10cc;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0xffffffce,(int)uVar11 + -0x1252);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x10f4;
  if ((uVar5 < 0x2f8) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0x302,(int)uVar11 + -0x12c0);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x488;
  if ((uVar5 < 0xf0) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x6a4) {
    stage_spawn_dispatch_candidate(0x57,0x898,0x1ae,0xffffff88);
    stage_spawn_dispatch_candidate(0x57,0x898,0x244,0xffffff60);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0xa28;
  if ((uVar5 < 0x78) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0xabe;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0x1a,300,DAT_140e9fd1c % 0x15f + 0x136,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0xc80) {
    stage_spawn_dispatch_candidate(0x59,0x22b8,0xffffff9c,200);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0xc80;
  if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0x2c) * 0x2c)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xc,300,DAT_140e9fd1c % 0x191 + 0xd2,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0xd70) {
    stage_spawn_dispatch_candidate(0x59,0x22b8,0x334,200);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0xdac;
  if ((uVar5 < 200) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xd,300,0x2e4,DAT_140e9fd1c % 0x65 + 300);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0xe42;
  if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xd,300,0xffffffec,DAT_140e9fd1c % 0x65 + 300);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x10cc) {
    stage_spawn_dispatch_candidate(0x58,0x960,0x168,0xffffff88);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x10fe) {
    stage_spawn_dispatch_candidate(0x58,0x960,0xd2,0xffffff6a);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x1130) {
    stage_spawn_dispatch_candidate(0x58,0x960,0x3c,0xffffff4c);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x11f8;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x1482;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 10) * 10)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x17ac;
  if ((uVar5 < 0xf0) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0x1a,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar2 = DAT_140539ee0;
  uVar5 = (uint)uVar11;
  if (uVar5 == 0x189c) {
    uVar15 = uVar15 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate(0x143,100000,0,DAT_14053ae48,uVar1,uVar15,DAT_140539ee0,0x50,1,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (uVar12 = uVar5 - 0x1900, 0x76b < uVar12)) goto LAB_140122b98;
    if (uVar12 == ((int)uVar12 / 0x27) * 0x27) {
      uVar5 = ((uint)(uVar11 >> 0x1e) ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      stage_spawn_dispatch_candidate(0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar11 = (ulonglong)DAT_140e418c8;
    }
    uVar5 = (int)uVar11 - 0x1964;
    if ((uVar5 < 0x6a4) && (uVar5 == ((int)uVar5 / 400) * 400)) {
      stage_spawn_dispatch_candidate(0x57,2000,0x1a4,0xffffff4c);
      stage_spawn_dispatch_candidate(0x57,2000,0x262,0xffffff6a);
      stage_spawn_dispatch_candidate(0x57,2000,800,0xffffff88);
      uVar11 = (ulonglong)DAT_140e418c8;
    }
    uVar5 = (int)uVar11 - 0x1a2c;
    if ((0x5db < uVar5) || (uVar5 != ((int)uVar5 / 400) * 400)) goto LAB_140122b98;
    stage_spawn_dispatch_candidate(0x58,2000,300,0xffffff88);
    stage_spawn_dispatch_candidate(0x58,2000,0x6e,0xffffff6a);
    stage_spawn_dispatch_candidate(0x58,2000,0xffffffb0,0xffffff4c);
  }
  uVar11 = (ulonglong)DAT_140e418c8;
LAB_140122b98:
  if ((int)uVar11 == 0x2008) {
    local_158 = _DAT_14053c050;
    uStack_150 = _UNK_14053c058;
    local_138 = _DAT_14053c0f0;
    uStack_130 = _UNK_14053c0f8;
    local_148 = _DAT_14053c0e0;
    uStack_140 = _UNK_14053c0e8;
    local_118 = _DAT_14053c170;
    uStack_110 = _UNK_14053c178;
    local_128 = _DAT_14053c0d0;
    uStack_120 = _UNK_14053c0d8;
    local_f8 = _DAT_14053c260;
    uStack_f0 = _UNK_14053c268;
    local_108 = _DAT_14053c240;
    uStack_100 = _UNK_14053c248;
    local_d8 = _DAT_14053c3f0;
    uStack_d0 = _UNK_14053c3f8;
    local_e8 = _DAT_14053c2c0;
    uStack_e0 = _UNK_14053c2c8;
    local_b8 = _DAT_14053c420;
    uStack_b0 = _UNK_14053c428;
    local_c8 = _DAT_14053c410;
    uStack_c0 = _UNK_14053c418;
    local_180 = _DAT_14053c060;
    uStack_178 = _UNK_14053c068;
    local_98 = 0x44214000;
    local_a8 = _DAT_14053c430;
    uStack_a0 = _UNK_14053c438;
    local_1a8 = _DAT_14053c390;
    uStack_1a0 = _UNK_14053c398;
    local_94 = 0xc552a000;
    local_170 = _DAT_14053c3d0;
    uStack_168 = _UNK_14053c3d8;
    local_160 = 0x43bb8000;
    local_15c = 0xc53b8000;
    local_198 = 0xc551600043660000;
    lVar6 = lVar8;
    do {
      stage_spawn_dispatch_candidate
                (0x5a,0x44c,(int)*(float *)(&local_158 + lVar6),
                 (int)*(float *)((longlong)&local_158 + lVar6 * 8 + 4));
      lVar6 = lVar6 + 1;
      lVar7 = lVar8;
    } while (lVar6 < 0x19);
    do {
      stage_spawn_dispatch_candidate
                (0x5d,0xc80,(int)*(float *)(&local_180 + lVar7),
                 (int)*(float *)((longlong)&local_180 + lVar7 * 8 + 4));
      lVar7 = lVar7 + 1;
    } while (lVar7 < 5);
    do {
      stage_spawn_dispatch_candidate
                (0x5e,0x15e0,(int)*(float *)(&local_1a8 + lVar8),
                 (int)*(float *)((longlong)&local_1a8 + lVar8 * 8 + 4));
      lVar8 = lVar8 + 1;
    } while (lVar8 < 3);
    stage_spawn_dispatch_candidate(0x5f,13000,0xf0,0xfffffb1e);
    stage_spawn_dispatch_candidate(0x5f,0x30d4,500,0xfffff399);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x22c4;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0x302,(int)uVar11 + -0x245e);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar11 - 0x23f0;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
    stage_spawn_dispatch_candidate(0x5b,800,0xffffffce,(int)uVar11 + -0x25da);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x2260) {
    stage_spawn_dispatch_candidate(0x59,8000,0x334,200);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x23f0) {
    stage_spawn_dispatch_candidate(0xf,5000,0xffffff88,0x78);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 0x26ca;
  if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {
    uVar5 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,0x2e4,DAT_140e9fd1c % 0xc9 + 0x96);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11 - 10000;
  if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {
    uVar12 = ((uint)(uVar11 >> 0x1e) ^ (uint)uVar11) * 0x6c078965 + 1;
    uVar5 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x2774) {
    stage_spawn_dispatch_candidate(0x57,0x640,0x168,0xffffff9c);
    stage_spawn_dispatch_candidate(0x57,0x640,0x230,0xffffff9c);
    stage_spawn_dispatch_candidate(0x57,0x640,0x2f8,0xffffff9c);
    stage_spawn_dispatch_candidate(0x57,0x640,0x1cc,0xffffff24);
    stage_spawn_dispatch_candidate(0x57,0x640,0x294,0xffffff24);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  iVar10 = (int)uVar11;
  if (((iVar10 == 0x283c) || (iVar10 == 0x288c)) || (iVar10 == 0x28dc)) {
    stage_spawn_dispatch_candidate(0xc,300,0x3c,0xffffffec);
    stage_spawn_dispatch_candidate(0xc,300,0xb4,0xffffffec);
    stage_spawn_dispatch_candidate(0xc,300,300,0xffffffec);
    stage_spawn_dispatch_candidate(0xc,300,0x1a4,0xffffffec);
    stage_spawn_dispatch_candidate(0xc,300,0x21c,0xffffffec);
    stage_spawn_dispatch_candidate(0xc,300,0x294,0xffffffec);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x2936) {
    stage_spawn_dispatch_candidate(0x59,7000,0xffffff9c,200);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar11 == 0x2968) {
    stage_spawn_dispatch_candidate(0x59,7000,0x334,200);
    uVar11 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar11;
  uVar12 = uVar5 - 0x2a94;
  if ((uVar12 < 0xdc) && (uVar12 == ((int)uVar12 / 0x1e) * 0x1e)) {
    uVar12 = ((uint)(uVar11 >> 0x1e) ^ uVar5) * 0x6c078965 + 1;
    uVar5 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xc,300,DAT_140e9fd1c % 0x191 + 0x50,0xffffffec);
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == 0x2e18) {
    stage_spawn_dispatch_candidate(8,5000,0x1cc,0);
    uVar5 = DAT_140e418c8;
  }
  puVar4 = DAT_140e45d28;
  if ((uVar5 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar1 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar4 = (undefined8 *)_malloc_base(0x60);
    if (puVar4 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar4 = 1;
    *(undefined4 *)(puVar4 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
    puVar4[2] = 0x6f;
    puVar4[3] = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
    puVar4[5] = 0;
    puVar4[6] = 0x3ff0000000000000;
    puVar4[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar4 + 8) = 300;
    *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
    *(undefined4 *)(puVar4 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
    puVar4[10] = 0xff;
    puVar4[0xb] = 0;
    if (bVar13) {
      DAT_140e45d78 = puVar4;
    }
    uVar5 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar4;
      uVar5 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar4;
  fVar3 = DAT_14053ac64;
  iVar10 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar10 <= (int)uVar5) &&
     ((int)uVar5 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar14 = (double)FUN_140332d90(((double)(int)uVar5 - (double)iVar10) * DAT_14053a4d8 *
                                   DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar14 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * fVar3 * _DAT_1407c777c),DAT_140e45100);
    uVar5 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar5) &&
     ((int)uVar5 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    stage_entity_flush_effects_candidate();
    stage_pending_effect_flush_candidate();
    puVar9 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar9,0);
      puVar9 = puVar9 + 1;
    } while ((longlong)puVar9 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * fVar3),DAT_140e45140);
    FUN_14018a340(DAT_140e45140,3,1);
    DAT_140e45100 = DAT_140e45140;
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate
              (0x13d,100000,0,DAT_14053ae7c,DAT_14053ad70,uVar15 & 0xffff0000,uVar2,0xaf,1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 5;
  }
  return;
}


