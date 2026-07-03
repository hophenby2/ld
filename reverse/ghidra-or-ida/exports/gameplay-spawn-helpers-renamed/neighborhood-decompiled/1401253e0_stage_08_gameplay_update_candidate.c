// Function: stage_08_gameplay_update_candidate @ 1401253e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_08_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  double dVar15;
  uint uVar16;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined1 local_218 [16];
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined1 local_1a8 [16];
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
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
  undefined1 local_48 [16];
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar11 = 0;
  uVar16 = 0;
  stage_intro_banner_event_candidate
            (DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  if (DAT_140e418c8 == 400) {
    local_228 = _DAT_14053c350;
    uStack_220 = _UNK_14053c358;
    local_208 = _DAT_14053c500;
    uStack_200 = _UNK_14053c508;
    local_218 = _DAT_14053c4f0;
    uVar6 = uVar11;
    do {
      stage_spawn_dispatch_candidate
                (0x97,0x5dc,(int)*(float *)(&local_228 + uVar6),
                 (int)*(float *)((longlong)&local_228 + uVar6 * 8 + 4));
      uVar6 = uVar6 + 1;
    } while ((longlong)uVar6 < 6);
    stage_spawn_dispatch_candidate(0x9a,15000,0x200,0xfffff37e);
    stage_spawn_dispatch_candidate(0x9a,15000,0x138,0xffffee99);
  }
  uVar6 = (ulonglong)DAT_140e418c8;
  uVar5 = DAT_140e418c8 - 400;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x98,1000,0x302,DAT_140e418c8 - 0x352);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 700;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x98,1000,0xffffffce,(int)uVar6 + -0x460);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 2000;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x98,1000,0x302,(int)uVar6 + -0x992);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 4000;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x98,1000,0xffffffce,(int)uVar6 + -0x1158);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x546;
  if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x95,1000,0x10e,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,1000,0x168,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,1000,0x1c2,0xffffffce);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0xa8c;
  if ((uVar5 < 500) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x95,0x4b0,0x1d6,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,0x4b0,0x249,0xffffffce);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0xf3c;
  if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x95,0x4b0,0xe6,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,0x4b0,0x1ea,0xffffffce);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  iVar12 = 0x672;
  if ((0x671 < (int)uVar6) && ((int)uVar6 < 0x6d6)) {
    local_228 = _DAT_14053bc80;
    uStack_220 = _UNK_14053bc88;
    local_208 = _DAT_14053b570;
    uStack_200 = _UNK_14053b578;
    local_218 = _DAT_14053bd30;
    uVar7 = uVar11;
    do {
      if ((int)uVar6 == iVar12) {
        stage_spawn_dispatch_candidate
                  (0x99,0x4b0,(int)*(float *)(&local_228 + uVar7),
                   (int)*(float *)((longlong)&local_228 + uVar7 * 8 + 4) + (int)uVar6 + -0x672);
        uVar6 = (ulonglong)DAT_140e418c8;
      }
      iVar12 = iVar12 + 0xf;
      uVar7 = uVar7 + 1;
    } while ((longlong)uVar7 < 6);
  }
  if ((int)uVar6 == 0xce4) {
    stage_spawn_dispatch_candidate(0x99,0x5dc,0xffffffce,0x50);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xd02) {
    stage_spawn_dispatch_candidate(0x99,0x5dc,0xffffff4c,0x50);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  fVar2 = DAT_14053ad1c;
  if ((0x157b < (int)uVar6) && ((int)uVar6 < 0x1964)) {
    pfVar8 = (float *)&local_f8;
    local_f8 = _DAT_14053bc90;
    uStack_f0 = _UNK_14053bc98;
    iVar12 = 0x15b8;
    local_d8 = _DAT_14053bca0;
    uStack_d0 = _UNK_14053bca8;
    local_e8 = _DAT_14053bc70;
    uStack_e0 = _UNK_14053bc78;
    local_b8 = _DAT_14053bbd0;
    uStack_b0 = _UNK_14053bbd8;
    local_c8 = _DAT_14053bc10;
    uStack_c0 = _UNK_14053bc18;
    local_98 = _DAT_14053bcf0;
    uStack_90 = _UNK_14053bcf8;
    local_a8 = _DAT_14053b560;
    uStack_a0 = _UNK_14053b568;
    local_78 = _DAT_14053bda0;
    uStack_70 = _UNK_14053bda8;
    local_88 = _DAT_14053bd10;
    uStack_80 = _UNK_14053bd18;
    local_58 = _DAT_14053be00;
    uStack_50 = _UNK_14053be08;
    local_68 = _DAT_14053bdd0;
    uStack_60 = _UNK_14053bdd8;
    local_38 = _DAT_14053be40;
    uStack_30 = _UNK_14053be48;
    local_48 = _DAT_14053be30;
    uVar7 = uVar11;
    do {
      iVar10 = (int)uVar7;
      if (iVar10 < 7) {
        iVar3 = iVar12 + -0x3c;
      }
      else {
        iVar3 = iVar12;
        if (0xf < iVar10) {
          iVar3 = iVar12 + 0xbe;
        }
      }
      if ((int)uVar6 == iVar3) {
        stage_spawn_dispatch_candidate
                  (0x96,700,(int)*pfVar8,(int)(fVar2 - pfVar8[1]) + (int)uVar6 + -0x157c);
        uVar6 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (ulonglong)(iVar10 + 1);
      iVar12 = iVar12 + 0xc;
      pfVar8 = pfVar8 + 2;
    } while (iVar12 < 0x16f0);
  }
  uVar5 = (uint)uVar6 - 0x186;
  if (uVar5 < 0xb4) {
    uVar5 = uVar5 & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      stage_spawn_dispatch_candidate(0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (uint)uVar6 - 0x18e;
  if (uVar5 < 0xac) {
    uVar5 = uVar5 & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x26c) {
    stage_spawn_dispatch_candidate(0xe,5000,500,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x28a) {
    stage_spawn_dispatch_candidate(0xe,5000,0xdc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 1000) {
    stage_spawn_dispatch_candidate(7,5000,0x1cc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x802;
  if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x92e;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xc) * 0xc)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0xa64;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x45,400,0xffffffec,DAT_140e9fd1c % 0x79 + 0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xb54) {
    stage_spawn_dispatch_candidate(0x10,14000,0x10e,0x50);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0xe56;
  if (uVar5 < 0x50) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x155 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (uint)uVar6 - 0xece;
  if (uVar5 < 0x50) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x155 + 0x140,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x1004) {
    stage_spawn_dispatch_candidate(0x46,0x960,0xfffffed4,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1022) {
    stage_spawn_dispatch_candidate(0x46,0x960,0x3fc,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x109a) {
    stage_spawn_dispatch_candidate(0x46,0x960,0xfffffed4,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x10b8) {
    stage_spawn_dispatch_candidate(0x46,0x960,0x3fc,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x11f8;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x45,400,0x2e4,DAT_140e9fd1c % 0x83 + 0x78);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x1432;
  if ((uVar5 < 0xa0) && (uVar5 == ((int)uVar5 / 5) * 5)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x44,200,DAT_140e9fd1c % 0x281 + 0x28,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x1518;
  if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0x1e) * 0x1e)) {
    stage_spawn_dispatch_candidate(0x45,400,0x50,0xffffffec);
    stage_spawn_dispatch_candidate(0x45,400,0xdc,0xffffffec);
    stage_spawn_dispatch_candidate(0x45,400,0x168,0xffffffec);
    stage_spawn_dispatch_candidate(0x45,400,500,0xffffffec);
    stage_spawn_dispatch_candidate(0x45,400,0x26c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x16a8) {
    stage_spawn_dispatch_candidate(0x46,0x960,0xfffffed4,100);
    stage_spawn_dispatch_candidate(0x46,0x960,0x3fc,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x186a) {
    if (DAT_140e445c0 == 0) {
      stage_spawn_dispatch_candidate(0x9c,9000,0x21c,200);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    if (DAT_140e445c0 == 1) {
      stage_spawn_dispatch_candidate(0x9f,7000,0x21c,200);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    if (DAT_140e445c0 == 2) {
      stage_spawn_dispatch_candidate(0xa2,7000,0x21c,200);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 0x18d8;
  if ((uVar5 < 0x8c) && (uVar5 == ((int)uVar5 / 0x3c) * 0x3c)) {
    stage_spawn_dispatch_candidate(0xb,300,0x50,0xffffffec);
    stage_spawn_dispatch_candidate(0xb,300,0xdc,0xffffffec);
    stage_spawn_dispatch_candidate(0xb,300,0x168,0xffffffec);
    stage_spawn_dispatch_candidate(0xb,300,500,0xffffffec);
    stage_spawn_dispatch_candidate(0xb,300,0x26c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x19fa) {
    stage_spawn_dispatch_candidate(8,5000,0x136,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x1af4;
  if ((uVar5 < 0x3c) && (uVar5 == ((int)uVar5 / 10) * 10)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x70,0x15e,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 7000;
  if ((uVar5 < 0x3c) && (uVar5 == ((int)uVar5 / 10) * 10)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0x70,0x15e,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x1bbc;
  if (uVar5 < 0x3c) {
    uVar5 = uVar5 & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0x70,0x15e,((DAT_140e9fd1c / 0xc9) * 0xc9 - DAT_140e9fd1c) + 0x136,0xffffffec);
      uVar5 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0x70,0x15e,DAT_140e9fd1c % 0xc9 + 0x19a,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (uint)uVar6 - 0x1c52;
  if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar13 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar13 * 0x800 ^ uVar13;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate
              (0x37,300,DAT_140e9fd1c % 0x1e1 + 0x78,
               ((DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5) % 0x97 + 400);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1c20) {
    stage_spawn_dispatch_candidate(0x71,5000,0x1b8,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1cac) {
    stage_spawn_dispatch_candidate(0x72,5000,0x118,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1d38) {
    stage_spawn_dispatch_candidate(0x71,5000,0x1e0,0xfa);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x1dec;
  if ((uVar5 < 0x1cc) && (uVar5 = (int)uVar5 % 0x82, (int)uVar5 < 0x3c)) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x1db0) {
    stage_spawn_dispatch_candidate(0x1c,0x1130,0xffffff88,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1e32) {
    stage_spawn_dispatch_candidate(0x1c,0x1130,0x348,0x1e);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1eb4) {
    stage_spawn_dispatch_candidate(0x1c,0x1130,0xffffff88,0x3c);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1f36) {
    stage_spawn_dispatch_candidate(0x1c,0x1130,0x348,0x5a);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x2008;
  if (uVar5 < 100) {
    uVar5 = uVar5 & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    if (uVar5 == 0) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0xb,300,((DAT_140e9fd1c / 0xc9) * 0xc9 - DAT_140e9fd1c) + 0x136,0xffffffec);
      uVar5 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0xc9 + 0x19a,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (uint)uVar6;
  if (uVar5 == 0x20a8) {
    stage_spawn_dispatch_candidate(0xa4,75000,0x334,0xb4);
    DAT_140e418cc = 1;
LAB_140127143:
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (uVar5 - 0x20d0 < 0x898)) {
    uVar13 = uVar5 - 0x2260;
    if ((uVar13 < 0x44c) && (uVar13 == ((int)uVar13 / 0x1e) * 0x1e)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0x70,0x15e,((DAT_140e9fd1c / 0x1f5) * 0x1f5 - DAT_140e9fd1c) + 0x262,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    uVar5 = (uint)uVar6 - 0x2260;
    if (uVar5 < 0x44c) {
      uVar5 = uVar5 & 0x8000000f;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
      }
      if (uVar5 == 0) {
        uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
        stage_spawn_dispatch_candidate
                  (0xb,300,((DAT_140e9fd1c / 0x1f5) * 0x1f5 - DAT_140e9fd1c) + 0x262,0xffffffec);
        uVar6 = (ulonglong)DAT_140e418c8;
      }
    }
    uVar5 = (uint)uVar6 - 10000;
    if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0x16) * 0x16)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0x1a,300,((DAT_140e9fd1c / 0x1b9) * 0x1b9 - DAT_140e9fd1c) + 0x244,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    uVar5 = (uint)uVar6 - 0x2738;
    if ((uVar5 < 0x104) && (uVar5 == ((int)uVar5 / 100) * 100)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0x38,0xe10,((DAT_140e9fd1c / 0x1b9) * 0x1b9 - DAT_140e9fd1c) + 0x244,0xffffffec);
      goto LAB_140127143;
    }
  }
  if ((int)uVar6 == 0x28a0) {
    stage_spawn_dispatch_candidate(0x26,3000,0x168,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x28d2) {
    stage_spawn_dispatch_candidate(0x26,3000,0x21c,0xffffffec);
    stage_spawn_dispatch_candidate(0x26,3000,0xb4,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2a30) {
    local_188 = _DAT_14053c150;
    uStack_180 = _UNK_14053c158;
    local_168 = _DAT_14053c520;
    uStack_160 = _UNK_14053c528;
    local_178 = _DAT_14053c4d0;
    uStack_170 = _UNK_14053c4d8;
    local_158 = _DAT_14053c330;
    uStack_150 = _UNK_14053c338;
    local_1f8 = _DAT_14053c3a0;
    uStack_1f0 = _UNK_14053c3a8;
    local_138 = _DAT_14053c480;
    uStack_130 = _UNK_14053c488;
    local_148 = _DAT_14053c340;
    uStack_140 = _UNK_14053c348;
    local_128 = _DAT_14053c160;
    uStack_120 = _UNK_14053c168;
    local_1e8 = _DAT_14053c490;
    uStack_1e0 = _UNK_14053c498;
    local_108 = _DAT_14053c530;
    uStack_100 = _UNK_14053c538;
    local_118 = _DAT_14053c4e0;
    uStack_110 = _UNK_14053c4e8;
    local_1d8 = _DAT_14053c360;
    uStack_1d0 = _UNK_14053c368;
    local_1c8 = _DAT_14053c370;
    uStack_1c0 = _UNK_14053c378;
    local_1b8 = _DAT_14053c380;
    uStack_1b0 = _UNK_14053c388;
    local_1a8._8_8_ = _UNK_14053c518;
    local_1a8._0_8_ = _DAT_14053c510;
    local_228 = _DAT_14053c560;
    uStack_220 = _UNK_14053c568;
    local_218 = _DAT_14053c570;
    uVar6 = uVar11;
    do {
      stage_spawn_dispatch_candidate
                (0x1d,0x640,(int)*(float *)((longlong)&local_188 + uVar6),
                 (int)*(float *)((longlong)&local_188 + uVar6 + 4));
      stage_spawn_dispatch_candidate
                (0x2c,0x640,(int)*(float *)((longlong)&local_158 + uVar6),
                 (int)*(float *)((longlong)&local_158 + uVar6 + 4));
      stage_spawn_dispatch_candidate
                (0x5a,0x640,(int)*(float *)((longlong)&local_128 + uVar6),
                 (int)*(float *)((longlong)&local_128 + uVar6 + 4));
      uVar6 = uVar6 + 8;
      uVar7 = uVar11;
    } while ((longlong)uVar6 < 0x30);
    do {
      stage_spawn_dispatch_candidate
                (0x1e,0x708,(int)*(float *)((longlong)&local_1f8 + uVar7),
                 (int)*(float *)((longlong)&local_1f8 + uVar7 + 4));
      stage_spawn_dispatch_candidate
                (0x2d,0x1194,(int)*(float *)((longlong)&local_1e8 + uVar7),
                 (int)*(float *)((longlong)&local_1e8 + uVar7 + 4));
      uVar7 = uVar7 + 8;
      uVar6 = uVar11;
    } while ((longlong)uVar7 < 0x10);
    do {
      stage_spawn_dispatch_candidate
                (0x5d,0xc80,(int)*(float *)(&local_1d8 + uVar6),
                 (int)*(float *)((longlong)&local_1d8 + uVar6 * 8 + 4));
      uVar6 = uVar6 + 1;
      uVar7 = uVar11;
    } while ((longlong)uVar6 < 8);
    do {
      stage_spawn_dispatch_candidate
                (0x97,0x708,(int)*(float *)(&local_228 + uVar7),
                 (int)*(float *)((longlong)&local_228 + uVar7 * 8 + 4));
      uVar7 = uVar7 + 1;
    } while ((longlong)uVar7 < 4);
    stage_spawn_dispatch_candidate(0x20,14000,200,0xfffff4de);
    stage_spawn_dispatch_candidate(0x5e,0x157c,0x208,0xfffff4ac);
    stage_spawn_dispatch_candidate(0x1f,8000,0x1c2,0xffffec64);
    stage_spawn_dispatch_candidate(0x1f,8000,0x127,0xffffebc4);
    stage_spawn_dispatch_candidate(0x5f,0x34bc,0x168,0xffffea84);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x2de6;
  if ((uVar5 < 0x226) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x95,1000,0x10e,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,1000,0x168,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,1000,0x1c2,0xffffffce);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x37dc;
  if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x95,0x4b0,0xe6,0xffffffce);
    stage_spawn_dispatch_candidate(0x95,0x4b0,0x1ea,0xffffffce);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x2b5c;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x5b,800,0x302,(int)uVar6 + -0x2d14);
    stage_spawn_dispatch_candidate(0x5b,800,0xffffffce,DAT_140e418c8 - 0x2d82);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x30d4;
  if ((uVar5 < 900) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x5b,1000,0xffffffce,(int)uVar6 + -0x3264);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x3520;
  if ((uVar5 < 800) && (uVar5 == ((int)uVar5 / 0x5a) * 0x5a)) {
    stage_spawn_dispatch_candidate(0x98,1000,0x302,(int)uVar6 + -0x3714);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((0x3cef < (int)uVar6) && ((int)uVar6 < 0x40d8)) {
    pfVar8 = (float *)&local_1d8;
    local_1d8 = _DAT_14053bc60;
    uStack_1d0 = _UNK_14053bc68;
    iVar12 = 0x3e08;
    local_1b8 = _DAT_14053bd40;
    uStack_1b0 = _UNK_14053bd48;
    local_1c8 = _DAT_14053bd60;
    uStack_1c0 = _UNK_14053bd68;
    local_198 = _DAT_14053bdb0;
    uStack_190 = _UNK_14053bdb8;
    local_1a8 = _DAT_14053bdc0;
    do {
      iVar10 = iVar12;
      if ((int)uVar11 < 3) {
        iVar10 = iVar12 + -0x118;
      }
      if ((int)uVar6 == iVar10) {
        stage_spawn_dispatch_candidate
                  (0x96,700,(int)*pfVar8,(int)(fVar2 - pfVar8[1]) + (int)uVar6 + -0x3cf0);
        uVar6 = (ulonglong)DAT_140e418c8;
      }
      uVar11 = (ulonglong)((int)uVar11 + 1);
      iVar12 = iVar12 + 0xf;
      pfVar8 = pfVar8 + 2;
    } while (iVar12 < 0x3e9e);
  }
  uVar5 = (int)uVar6 - 0x2a62;
  if (uVar5 < 100) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,0xfa,0xffffffec,0x96);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x2ac6) {
    stage_spawn_dispatch_candidate(0x1b,3000,0xf0,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 11000;
  if (uVar5 < 100) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,0xfa,0x2e4,0x96);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x2b5c) {
    stage_spawn_dispatch_candidate(0x1b,3000,0x1e0,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2c56) {
    stage_spawn_dispatch_candidate(0x4a,9000,0x168,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 12000;
  if (uVar5 < 0x3c) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,200,0x2e4,0x96);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 0x2f58;
  if (uVar5 < 0x32) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,200,0xffffffec,0xb4);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 0x3002;
  if (uVar5 < 0x32) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,200,0x2e4,0x15e);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 0x30ac;
  if (uVar5 < 0x32) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,200,0xffffffec,0x15e);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 13000;
  if (uVar5 < 100) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,0xfa,0x2e4,0x78);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x3390) {
    stage_spawn_dispatch_candidate(0x9b,6000,0x230,0xb4);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x367e) {
    stage_spawn_dispatch_candidate(0x9e,5000,0xdc,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x3840) {
    stage_spawn_dispatch_candidate(0x3a,10000,800,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x3afc) {
    stage_spawn_dispatch_candidate(0xa1,9000,0x21c,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6 - 0x3b60;
  if ((uVar5 < 100) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 0) {
    uVar5 = (uint)uVar6 - 0x4010;
    if ((uVar5 < 300) && (uVar5 == ((int)uVar5 / 0xd) * 0xd)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (int)uVar6 - 0x413c;
  if (uVar5 < 200) {
    uVar13 = uVar5 & 0x8000000f;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffff0) + 1;
    }
    if (uVar13 == 0) {
      stage_spawn_dispatch_candidate(10,1000,(int)(uVar5 * 7) % 0x1e0 + 0x78,0x4236 - (int)uVar6);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar5 = (uint)uVar6 - 0x4290;
  if ((uVar5 < 0x6e) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0xc,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x43a8;
  if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    stage_spawn_dispatch_candidate(0x70,500,0x136 - (int)(uVar5 * 6) % 0xf0,0x30c);
    stage_spawn_dispatch_candidate
              (0x70,500,(int)((DAT_140e418c8 - 0x43a8) * 6) % 0xf0 + 0x19a,0x30c);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x440c;
  if ((uVar5 < 0x28) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
    stage_spawn_dispatch_candidate(0x70,500,0x136 - (int)(uVar5 * 6) % 0xf0,0x30c);
    stage_spawn_dispatch_candidate
              (0x70,500,(int)((DAT_140e418c8 - 0x440c) * 6) % 0xf0 + 0x19a,0x30c);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x44c0) {
    stage_spawn_dispatch_candidate(0xf,0x1194,0xffffff88,0xfa);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x44f2) {
    stage_spawn_dispatch_candidate(0xf,0x1194,0x348,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4524) {
    stage_spawn_dispatch_candidate(0xf,0x1194,0xffffff88,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4556) {
    stage_spawn_dispatch_candidate(0xf,0x1194,0x348,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 18000) {
    stage_spawn_dispatch_candidate(0x3d,10000,0x398,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x4696;
  if (uVar5 < 0x50) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,0xfa,0x2e4,0x78);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x474a) {
    stage_spawn_dispatch_candidate(0x73,7000,0x1cc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (int)uVar6 - 0x475e;
  if (uVar5 < 0x50) {
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    if (uVar5 == 0) {
      stage_spawn_dispatch_candidate(0x35,0xfa,0xffffffec,0xa0);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x4812) {
    stage_spawn_dispatch_candidate(0x73,7000,0x104,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4876) {
    stage_spawn_dispatch_candidate(0x25,700,0xd2,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,300,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,0x186,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,0x1e0,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x48a8) {
    stage_spawn_dispatch_candidate(0x25,700,0xf0,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,0x14a,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,0x1a4,0xffffffec);
    stage_spawn_dispatch_candidate(0x25,700,0x1fe,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6;
  if (uVar5 == 0x490c) {
    stage_spawn_dispatch_candidate(0x2e,60000,0x168,0xffffff88);
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (0x577 < uVar5 - 0x490c)) goto LAB_1401282c6;
    uVar13 = uVar5 - 0x4970;
    if ((uVar13 < 0x47e) && (uVar13 == ((int)uVar13 / 5) * 5)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar6 == 20000) {
      stage_spawn_dispatch_candidate(0x27,4000,0x1e0,300);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar6 != 0x4e48) goto LAB_1401282c6;
    stage_spawn_dispatch_candidate(0x27,4000,0xf0,200);
  }
  uVar6 = (ulonglong)DAT_140e418c8;
LAB_1401282c6:
  if ((int)uVar6 == 0x4e70) {
    stage_spawn_dispatch_candidate(0x27,4000,0x1b8,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4f4c) {
    stage_spawn_dispatch_candidate(0x29,4000,0xf0,300);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4fb0) {
    stage_spawn_dispatch_candidate(0x29,4000,0x1e0,0xfa);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x5014) {
    stage_spawn_dispatch_candidate(0x29,4000,0xf0,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 0) {
    uVar5 = (uint)uVar6 - 0x4fb0;
    if ((uVar5 < 400) && (uVar5 == ((int)uVar5 / 0x18) * 0x18)) {
      uVar5 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x50aa) {
    stage_spawn_dispatch_candidate(0x59,5000,0xffffff9c,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x50dc) {
    stage_spawn_dispatch_candidate(0x59,5000,0x334,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar5 = (uint)uVar6;
  if (((DAT_140e418cc == 0) && (uVar13 = uVar5 - 0x50dc, uVar13 < 100)) &&
     (uVar13 == ((int)uVar13 / 0x18) * 0x18)) {
    uVar13 = ((uint)(uVar6 >> 0x1e) ^ uVar5) * 0x6c078965 + 1;
    uVar5 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    stage_spawn_dispatch_candidate(0x45,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == 0x51a4) {
    stage_spawn_dispatch_candidate(8,5000,0x104,0);
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
    bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
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
    if (bVar14) {
      DAT_140e45d78 = puVar4;
    }
    uVar5 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar4;
      uVar5 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar4;
  fVar2 = DAT_14053ac64;
  iVar12 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar12 <= (int)uVar5) &&
     ((int)uVar5 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar15 = (double)FUN_140332d90(((double)(int)uVar5 - (double)iVar12) * DAT_14053a4d8 *
                                   DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar15 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * fVar2 * _DAT_1407c777c),DAT_140e45100);
    uVar5 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar5) &&
     ((int)uVar5 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    DAT_140e418cc = 0;
    stage_entity_flush_effects_candidate();
    stage_pending_effect_flush_candidate();
    puVar9 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar9,0);
      puVar9 = puVar9 + 1;
    } while ((longlong)puVar9 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * fVar2),DAT_140e45140);
    FUN_14018a340(DAT_140e45140,3,1);
    DAT_140e45100 = DAT_140e45140;
    uVar5 = DAT_140e418c8;
  }
  if (uVar5 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate
              (0x13f,100000,0,DAT_14053ae30,DAT_14053ad9c,uVar16 & 0xffff0000,DAT_140539ee0,0x82,1,0
              );
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 6;
  }
  return;
}


