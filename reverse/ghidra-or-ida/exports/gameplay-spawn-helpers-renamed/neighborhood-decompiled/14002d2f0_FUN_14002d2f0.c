// Function: FUN_14002d2f0 @ 14002d2f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14002d2f0(undefined4 *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  double dVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  double dVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  float extraout_var;
  short sVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar17;
  ushort uVar18;
  uint uVar19;
  ushort uVar20;
  longlong lVar21;
  short *psVar22;
  uint uVar23;
  int iVar24;
  undefined8 uVar25;
  short sVar26;
  longlong lVar27;
  uint uVar28;
  longlong lVar29;
  bool bVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  float fVar36;
  double dVar37;
  double dVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  int local_res8;
  int local_res10;
  int local_res18;
  undefined2 *local_res20;
  float fVar48;
  uint uVar49;
  ushort uVar50;
  undefined1 in_stack_fffffffffffffe28 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar93 [16];
  undefined1 auVar94 [16];
  undefined1 auVar95 [16];
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined1 auVar99 [16];
  undefined1 auVar100 [16];
  undefined8 in_stack_fffffffffffffe38;
  ulonglong uVar101;
  uint uVar102;
  undefined4 uVar103;
  undefined4 uVar104;
  undefined4 uVar105;
  undefined4 uVar106;
  int local_160;
  undefined4 *local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  
  puVar9 = DAT_140e45d80;
  iVar13 = DAT_140e44e6c;
  iVar16 = DAT_140e44308;
  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  local_150 = 0;
  local_150._0_4_ = 0;
  uStack_138 = 0;
  uStack_138._4_4_ = 0;
  puVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)puVar8[0xc]) {
      if (*(int *)((longlong)puVar8 + 4) == DAT_140e44308) {
        local_150 = *puVar8;
        uStack_148 = puVar8[1];
        local_140 = puVar8[2];
        uStack_138 = puVar8[3];
        local_130 = puVar8[4];
        uStack_128 = puVar8[5];
      }
    }
  }
  dVar31 = (double)FUN_1403300b4((double)((float)param_1[0xf] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xe] - (float)param_1[10]));
  uVar19 = DAT_140e418c8;
  auVar92 = _DAT_14053bb20;
  dVar35 = DAT_14053aba0;
  dVar3 = (double)DAT_14053bb20;
  uVar106 = 0x56;
  uVar105 = 0x57;
  uVar104 = 0x56;
  uVar103 = 0x57;
  uVar102 = 0x55;
  uVar101 = CONCAT44(uVar42,0x54);
  auVar51._12_4_ = in_stack_fffffffffffffe28._12_4_;
  auVar51._0_8_ = in_stack_fffffffffffffe28._0_8_;
  auVar51._8_4_ = 0x53;
  auVar52._4_12_ = auVar51._4_12_;
  auVar52._0_4_ = 0x52;
  uVar49 = 0x51;
  fVar48 = 1.12104e-43;
  uVar23 = (uint)(dVar31 * DAT_14053aba0);
  local_res10 = FUN_1400c9580(DAT_140e418c8,0,5,0x10,0x50,0x51,auVar52,uVar101,0x55,0x57,0x56,0x57,
                              0x56,0x55,0x54,0x53,0x52,0x50,0x51);
  dVar34 = DAT_14053a020;
  dVar31 = DAT_140539d28;
  uVar44 = SUB84(DAT_14053a020,0);
  uVar45 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar42 = SUB84(DAT_140539d28,0);
  uVar43 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  FUN_140332d90();
  dVar32 = (double)FUN_1403307c0();
  dVar38 = DAT_14053a2a8;
  fVar39 = (float)(dVar32 * DAT_14053a2a8) + (float)param_1[10];
  dVar32 = (double)FUN_140332d90();
  iVar15 = param_1[6];
  fVar41 = (float)(dVar32 * dVar38) + ((float)param_1[0xb] - DAT_14053ad40);
  if (iVar15 == 0x84) {
    uVar106 = 0x5c;
    uVar105 = 0x5b;
    uVar104 = 0x5a;
    uVar103 = 0x5b;
    uVar102 = 0x5a;
    uVar101 = CONCAT44((int)(uVar101 >> 0x20),0x5c);
    auVar53._12_4_ = auVar52._12_4_;
    auVar53._0_8_ = auVar52._0_8_;
    auVar53._8_4_ = 0x5d;
    auVar52._4_12_ = auVar53._4_12_;
    auVar52._0_4_ = 0x5e;
    uVar49 = 0x5f;
    fVar48 = 1.34525e-43;
    local_res10 = FUN_1400c9580(uVar19,0,5,0x10,0x60,0x5f,auVar52,uVar101,0x5a,0x5b,0x5a,0x5b,0x5c,
                                0x5d,0x5e,0x5f,0x61,0x60,0x61);
    FUN_140332d90();
    dVar32 = (double)FUN_1403307c0();
    fVar39 = (float)(dVar32 * dVar38) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90();
    iVar15 = param_1[6];
    fVar41 = (float)(dVar32 * dVar38) + ((float)param_1[0xb] - DAT_14053ad40);
  }
  param_1[5] = local_140._4_4_;
  param_1[3] = uStack_148._4_4_;
  if (2 < local_140._4_4_ - 0xb) {
    param_1[8] = DAT_140e41b0c;
  }
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    if (iVar15 == 0x83) {
      uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      uVar12 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 4;
      uVar11 = DAT_1407c7798 * 0xde + DAT_140e418c8;
      uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
      param_1[0xe] = (float)(((uVar12 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ uVar12) % 0x65 + 0xd2);
      DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar11 = uVar11 * 0x800 ^ uVar11;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
LAB_14002d93f:
      param_1[0xf] = (float)(DAT_140e9fd1c % 0x33 + 200);
    }
    else if (iVar15 == 0x84) {
      uVar19 = (DAT_140e418c8 + 0x6f >> 0x1e ^ DAT_140e418c8 + 0x6f) * 0x6c078965 + 1;
      uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      uVar12 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 4;
      uVar11 = DAT_1407c7798 * 0x14d + DAT_140e418c8;
      uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
      param_1[0xe] = (float)(((uVar12 >> 0xb ^ uVar19) >> 8 ^ uVar12 ^ uVar19) % 0x65 + 0x19a);
      DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar11 = uVar11 * 0x800 ^ uVar11;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ uVar11 ^ DAT_140e9fd18;
      goto LAB_14002d93f;
    }
    iVar13 = DAT_140e44e6c;
    if ((0x14 < (int)local_140._4_4_) && ((int)local_140._4_4_ < 0x3b)) {
      if (iVar15 == 0x83) {
        uVar19 = (DAT_140e418c8 + 0x6f >> 0x1e ^ DAT_140e418c8 + 0x6f) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        iVar13 = DAT_140e9fd1c % 0xc9 + 0xd2;
      }
      else {
        if (iVar15 != 0x84) goto LAB_14002dae6;
        uVar19 = (DAT_140e418c8 + 0x6f >> 0x1e ^ DAT_140e418c8 + 0x6f) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        iVar13 = DAT_140e9fd1c % 0xc9 + 0x136;
      }
      param_1[0xe] = (float)iVar13;
      iVar13 = DAT_140e44e6c;
    }
  }
LAB_14002dae6:
  fVar40 = DAT_14053af14;
  local_160 = 0xdc;
  uVar19 = (uint)(uVar101 >> 0x20);
  uVar50 = (ushort)(uVar49 >> 0x10);
  uVar20 = (ushort)uVar23;
  switch(local_140._4_4_) {
  case 0:
  case 1:
    param_1[10] = (float)uStack_128 + (float)param_1[0xc];
    param_1[0xb] = uStack_128._4_4_ + (float)param_1[0xd];
    if ((local_140._4_4_ == 1) && (param_1[0x15] = 0, uStack_148._4_4_ == 1)) {
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
    }
    iVar15 = param_1[7];
    if ((iVar15 < uStack_138._4_4_) && (puVar8 = puVar9, 0 < iVar13)) {
      for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)puVar8[0xc]) {
        if (*(int *)((longlong)puVar8 + 4) == iVar16) {
          *(int *)((longlong)puVar8 + 0x1c) =
               *(int *)((longlong)puVar8 + 0x1c) - (uStack_138._4_4_ - iVar15);
        }
      }
    }
    iVar15 = param_1[7];
    if (uStack_138._4_4_ < (int)param_1[7]) {
      param_1[7] = uStack_138._4_4_;
      iVar15 = uStack_138._4_4_;
    }
    if ((iVar15 < 1) && (0 < iVar13)) {
      for (; puVar9 != (undefined8 *)0x0; puVar9 = (undefined8 *)puVar9[0xc]) {
        if (*(int *)((longlong)puVar9 + 4) == iVar16) {
          *(int *)((longlong)puVar9 + 0x1c) = *(int *)((longlong)puVar9 + 0x1c) - uStack_138._4_4_;
        }
      }
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10 * 4),0x19,0x18,
                  &IMAGE_DOS_HEADER_140000000,param_1[0xb],(uint)uVar50 << 0x10,auVar92,
                  (ulonglong)uVar19 << 0x20,0x40,0x40,0x30,1,0);
    fVar48 = (float)param_1[0xb];
    uVar106 = 0;
    uVar105 = 1;
    uVar104 = 0xff;
    uVar103 = 0xff;
    uVar102 = 0xff;
    uVar101 = 0xff;
    uVar49 = 0;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10 * 4),0x19,7);
    auVar52 = auVar92;
    break;
  case 10:
    if (uStack_148._4_4_ == 1) {
      param_1[0x15] = 1;
    }
    if ((int)uStack_148._4_4_ < 100) {
      uVar106 = 0;
      uVar105 = 1;
      uVar104 = 0x30;
      uVar103 = 0x40;
      uVar102 = 0x40;
      uVar101 = (ulonglong)uVar19 << 0x20;
      param_1[0xb] = uStack_128._4_4_ + (float)param_1[0xd];
      fVar48 = (float)param_1[0xb];
      uVar49 = (uint)uVar50 << 0x10;
      param_1[10] = (float)uStack_128 + (float)param_1[0xc];
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10 * 4),0x19,0x18,
                    &IMAGE_DOS_HEADER_140000000,fVar48,uVar49,auVar92,uVar101,0x40,0x40,0x30,1,0);
      auVar52 = auVar92;
    }
    iVar16 = param_1[3];
    if (99 < iVar16) {
      uVar50 = *(ushort *)(param_1 + 0x10);
      iVar15 = (uVar23 & 0xffff) - (uint)uVar50;
      iVar13 = iVar15 + 0x10000;
      if (-0x8001 < iVar15) {
        iVar13 = iVar15;
      }
      iVar15 = iVar13 + -0x10000;
      if (iVar13 < 0x8001) {
        iVar15 = iVar13;
      }
      if (iVar15 < 1) {
        uVar18 = uVar50;
        if ((iVar15 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar15)) {
          uVar18 = uVar20;
        }
      }
      else {
        uVar18 = uVar20;
        if (0x1ff < iVar15) {
          uVar18 = uVar50 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar18;
      dVar31 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar31 = (double)FUN_140332d90();
      fVar39 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar39;
      if (iVar16 - 0xd2U < 0x1e) {
        param_1[0xb] = fVar39 - (DAT_14053ac34 - ((float)iVar16 - DAT_14053adbc) * _DAT_140539d00);
      }
      if ((iVar16 == 0xd2) || (iVar16 == 0xf0)) {
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472e8);
        FUN_14018a340(DAT_140e472e8,1,1);
      }
    }
    iVar16 = param_1[3];
    if (iVar16 < 0xd2) {
      iVar13 = param_1[6];
joined_r0x000140031415:
      if (iVar13 == 0x83) {
        uVar49 = 0x59;
        fVar48 = 1.23314e-43;
        local_res10 = FUN_1400c9580(iVar16,0,5,2,0x58,0x59);
      }
      if (param_1[6] == 0x84) {
        uVar49 = 99;
        fVar48 = 1.37327e-43;
        local_res10 = FUN_1400c9580(param_1[3],0,5,2,0x62,99);
      }
    }
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    if (((local_140._4_4_ == 0xb) || ((local_140._4_4_ == 0xc && (iVar15 == 0x83)))) ||
       ((local_140._4_4_ == 0xd && (iVar15 == 0x84)))) {
      uVar50 = *(ushort *)(param_1 + 0x10);
      iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
      iVar16 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar16 = iVar13;
      }
      iVar13 = iVar16 + -0x10000;
      if (iVar16 < 0x8001) {
        iVar13 = iVar16;
      }
      if (iVar13 < 1) {
        uVar18 = uVar50;
        if ((iVar13 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar13)) {
          uVar18 = uVar20;
        }
      }
      else {
        uVar18 = uVar20;
        if (0x1ff < iVar13) {
          uVar18 = uVar50 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar18;
      dVar31 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar31 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      uVar42 = DAT_140e41a50;
      if (uStack_148._4_4_ == 1) {
        uVar43 = param_1[1];
        puVar9 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar9 = (undefined8 *)_malloc_base();
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar30 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar9 = 1;
          *(undefined4 *)(puVar9 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar9 + 0xc) = uVar42;
          puVar9[2] = 0x23;
          puVar9[3] = 0;
          *(undefined4 *)(puVar9 + 4) = 0;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          puVar9[5] = 0;
          puVar9[6] = 0x4014000000000000;
          puVar9[7] = 0x4014000000000000;
          *(undefined4 *)(puVar9 + 8) = 0x28;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)(puVar9 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          *(undefined4 *)(puVar9 + 10) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x54) = uVar43;
          puVar9[0xb] = 0;
          if (bVar30) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
        DAT_140e45d28 = puVar9;
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
      }
      dVar33 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),
                                     (double)(DAT_140e445d8 - fVar39));
      iVar16 = DAT_140e419b8;
      uVar19 = DAT_14053ac2c;
      dVar37 = DAT_14053a178;
      dVar6 = DAT_14053a138;
      dVar32 = DAT_14053a118;
      dVar38 = DAT_14053a0f8;
      dVar34 = DAT_14053a0b0;
      dVar31 = DAT_140539f40;
      uVar23 = (uint)(dVar33 * dVar35);
      iVar13 = (int)param_1[3] % 0x4b0;
      uVar42 = 3;
      uVar20 = (ushort)uVar23;
      if (iVar13 < 0x140) {
        iVar15 = iVar13 + -0x28;
        uVar11 = 1;
        if (DAT_140e419b8 == 0) {
          uVar11 = 0x11;
        }
        else if (DAT_140e419b8 == 1) {
          uVar11 = 0x15;
        }
        else if (DAT_140e419b8 == 2) {
          uVar11 = 0x17;
        }
        else if (DAT_140e419b8 == 3) {
          uVar11 = 0x19;
        }
        else if (DAT_140e419b8 == 4) {
          uVar11 = 0x1b;
        }
        iVar7 = 1;
        if (DAT_140e419b8 == 0) {
          iVar7 = 0xf;
        }
        else if (DAT_140e419b8 == 1) {
          iVar7 = 0x19;
        }
        else if (DAT_140e419b8 == 2) {
          iVar7 = 0x23;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar7 = 0x2d;
        }
        sVar10 = 1;
        if (DAT_140e419b8 == 0) {
          sVar10 = 0xb4;
        }
        else if (DAT_140e419b8 == 1) {
          sVar10 = 0xfa;
        }
        else if (DAT_140e419b8 == 2) {
          sVar10 = 300;
        }
        else if (DAT_140e419b8 == 3) {
          sVar10 = 0x168;
        }
        else if (DAT_140e419b8 == 4) {
          sVar10 = 0x1a4;
        }
        sVar10 = sVar10 + -0x28 + (short)iVar13;
        dVar35 = DAT_14053a0b0;
        if ((((DAT_140e419b8 != 0) && (dVar35 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
            (dVar35 = DAT_14053a118, DAT_140e419b8 != 2)) &&
           ((dVar35 = DAT_14053a138, DAT_140e419b8 != 3 &&
            (dVar35 = DAT_140539f40, DAT_140e419b8 == 4)))) {
          dVar35 = DAT_14053a178;
        }
        iVar24 = param_1[6];
        uVar17 = 0;
        dVar35 = ((double)iVar13 - DAT_14053a340) * _DAT_140539db0 + dVar35;
        if (iVar24 == 0x83) {
          if (iVar15 % 0xa0 < 0x50) {
LAB_14002e2d0:
            uVar17 = 9;
          }
        }
        else if ((iVar24 == 0x84) && (0x4f < iVar15 % 0xa0)) goto LAB_14002e2d0;
        if (param_1[5] - 0xc < 2) {
          iVar7 = iVar7 + 10;
        }
        if (0x27 < iVar13) {
          if (iVar15 == (iVar15 / 0x50) * 0x50) {
            *(ushort *)((longlong)param_1 + 0x42) = uVar20;
          }
          else if (iVar13 < 0x28) goto LAB_14002e444;
          iVar15 = iVar15 % 0x50;
          if ((iVar15 < iVar7) && (iVar15 == (iVar15 / 5) * 5)) {
            if (iVar24 == 0x83) {
              uVar103 = 0;
              uVar102 = 0x10000;
              uVar101 = (ulonglong)uVar11;
              auVar54._12_4_ = auVar52._12_4_;
              auVar54._0_8_ = auVar52._0_8_;
              auVar54._8_4_ = 1;
              auVar52._8_8_ = auVar54._8_8_;
              auVar52._0_8_ = dVar35;
              fVar48 = (float)(uint)*(ushort *)((longlong)param_1 + 0x42);
              uVar49 = uVar19;
              FUN_1400709b0(2,uVar17,iVar16,iVar15,fVar48,uVar19,dVar35,auVar52._8_8_,uVar101,
                            0x10000,0);
              *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar10;
            }
            if (param_1[6] == 0x84) {
              uVar103 = 0;
              uVar102 = 0x10000;
              uVar101 = (ulonglong)uVar11;
              auVar55._12_4_ = auVar52._12_4_;
              auVar55._0_8_ = auVar52._0_8_;
              auVar55._8_4_ = 1;
              auVar52._8_8_ = auVar55._8_8_;
              auVar52._0_8_ = dVar35;
              fVar48 = (float)(uint)*(ushort *)((longlong)param_1 + 0x42);
              uVar49 = uVar19;
              FUN_1400709b0(3,uVar17);
              *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar10;
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            dVar31 = DAT_140539f40;
            iVar16 = DAT_140e419b8;
          }
        }
      }
LAB_14002e444:
      dVar35 = DAT_14053a0d0;
      if (iVar13 - 0x168U < 0xb4) {
        iVar15 = 1;
        if (iVar16 == 0) {
          iVar15 = 0xc;
        }
        else if (iVar16 == 1) {
          iVar15 = 9;
        }
        else if (iVar16 == 2) {
          iVar15 = 7;
        }
        else if ((iVar16 == 3) || (iVar16 == 4)) {
          iVar15 = 6;
        }
        local_res18 = 1;
        if (iVar16 == 0) {
          local_res18 = 4;
        }
        else if (iVar16 == 1) {
          local_res18 = 6;
        }
        else if (iVar16 == 2) {
          local_res18 = 7;
        }
        else if (iVar16 == 3) {
          local_res18 = 9;
        }
        else if (iVar16 == 4) {
          local_res18 = 10;
        }
        iVar7 = 1;
        if ((iVar16 == 0) || (iVar16 == 1)) {
          iVar7 = 0x5dc;
        }
        else if (iVar16 == 2) {
          iVar7 = 0x514;
        }
        else if (iVar16 == 3) {
          iVar7 = 1000;
        }
        else if (iVar16 == 4) {
          iVar7 = 900;
        }
        sVar26 = 1;
        sVar10 = 1;
        if (iVar16 == 0) {
          sVar26 = 400;
          sVar10 = 400;
        }
        else if (iVar16 == 1) {
          sVar26 = 0x2a8;
          sVar10 = 0x2a8;
        }
        else if (((iVar16 == 2) || (iVar16 == 3)) || (iVar16 == 4)) {
          sVar26 = 0x2ee;
          sVar10 = 0x2ee;
        }
        dVar37 = DAT_14053a0d0;
        if (((iVar16 != 0) && (dVar37 = dVar32, iVar16 != 1)) &&
           ((dVar37 = dVar6, iVar16 != 2 && ((iVar16 == 3 || (dVar37 = dVar31, iVar16 == 4)))))) {
          dVar37 = DAT_14053a158;
        }
        dVar33 = DAT_140539f38;
        if (iVar16 == 0) {
LAB_14002e62e:
          if (2 < iVar16) {
LAB_14002e636:
            uVar42 = 5;
          }
        }
        else if (iVar16 == 1) {
          uVar42 = 3;
          dVar33 = DAT_140539f28;
        }
        else {
          dVar33 = DAT_140539f18;
          if (iVar16 != 2) {
            dVar33 = DAT_140539f10;
            if (iVar16 != 3) {
              dVar33 = dVar31;
              if (iVar16 == 4) {
                dVar33 = DAT_140539f10;
              }
              goto LAB_14002e62e;
            }
            goto LAB_14002e636;
          }
        }
        if (param_1[6] == 0x83) {
          sVar26 = -sVar26;
          uVar42 = 2;
          sVar10 = sVar26;
          if (2 < iVar16) {
            uVar42 = 4;
          }
        }
        if (param_1[5] - 0xc < 2) {
          iVar15 = 1;
          if (iVar16 == 0) {
            iVar15 = 8;
          }
          else if (iVar16 == 1) {
            iVar15 = 6;
          }
          else if (iVar16 == 2) {
            iVar15 = 5;
          }
          else if ((iVar16 == 3) || (iVar16 == 4)) {
            iVar15 = 4;
          }
        }
        if (iVar13 == 0x168) {
          *(undefined2 *)((longlong)param_1 + 0x42) = 0xc000;
        }
        if ((iVar13 + -0x168) % iVar15 == 0) {
          iVar16 = 0;
          auVar56._12_4_ = auVar52._12_4_;
          auVar56._0_8_ = auVar52._0_8_;
          auVar56._8_4_ = 1;
          auVar52._8_8_ = auVar56._8_8_;
          auVar52._0_8_ = dVar37;
          FUN_14006c2f0(uVar42);
          uVar11 = 0;
          do {
            uVar103 = 0;
            uVar101 = 2;
            auVar57._12_4_ = auVar52._12_4_;
            auVar57._0_8_ = auVar52._0_8_;
            auVar57._8_4_ = 1;
            auVar52._8_8_ = auVar57._8_8_;
            auVar52._0_8_ = dVar37 - (double)iVar16 * dVar33;
            fVar48 = (float)(uint)*(ushort *)((longlong)param_1 + 0x42);
            uVar49 = uVar19;
            uVar102 = uVar11;
            FUN_1400709b0(uVar42,0);
            iVar16 = iVar16 + 1;
            uVar11 = uVar11 + iVar7;
          } while (iVar16 < local_res18);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          dVar31 = DAT_140539f40;
          iVar16 = DAT_140e419b8;
          sVar26 = sVar10;
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar26;
        dVar37 = DAT_14053a178;
      }
      if (iVar13 - 600U < 0x230) {
        if (param_1[6] == 0x83) {
          iVar15 = 1;
          if (iVar16 == 0) {
            iVar15 = 0x28;
          }
          else if (iVar16 == 1) {
            iVar15 = 0x1e;
          }
          else if (iVar16 == 2) {
            iVar15 = 0x18;
          }
          else if (iVar16 == 3) {
            iVar15 = 0x14;
          }
          else if (iVar16 == 4) {
            iVar15 = 0x10;
          }
          uVar11 = 1;
          if (iVar16 == 0) {
            uVar11 = 7;
          }
          else if (iVar16 == 1) {
            uVar11 = 9;
          }
          else if (iVar16 == 2) {
            uVar11 = 0xb;
          }
          else if ((iVar16 == 3) || (iVar16 == 4)) {
            uVar11 = 0xd;
          }
          if ((((iVar16 != 0) && (dVar34 = dVar35, iVar16 != 1)) && (dVar34 = dVar38, iVar16 != 2))
             && ((iVar16 != 3 && (dVar34 = dVar31, iVar16 == 4)))) {
            dVar34 = DAT_14053a140;
          }
          dVar34 = ((double)iVar13 - DAT_14053a7c8) * DAT_140539d90 + dVar34;
          if ((iVar13 + -600) % (iVar15 * 2) == 0) {
            uVar103 = 0;
            uVar102 = 44000;
            uVar101 = (ulonglong)uVar11;
            auVar58._12_4_ = auVar52._12_4_;
            auVar58._0_8_ = auVar52._0_8_;
            auVar58._8_4_ = 1;
            auVar52._8_8_ = auVar58._8_8_;
            auVar52._0_8_ = dVar34;
            fVar48 = (float)(uVar23 & 0xffff);
            uVar49 = uVar19;
            FUN_1400709b0(4,10);
            if (param_1[5] == 0xc) {
              auVar59._12_4_ = auVar52._12_4_;
              auVar59._0_8_ = auVar52._0_8_;
              auVar59._8_4_ = 1;
              auVar60._8_8_ = auVar59._8_8_;
              auVar60._0_8_ = dVar34;
              FUN_1400709b0(4,10);
              uVar103 = 0;
              uVar102 = 44000;
              uVar101 = (ulonglong)uVar11;
              auVar61._12_4_ = auVar60._12_4_;
              auVar61._0_8_ = auVar60._0_8_;
              auVar61._8_4_ = 1;
              auVar52._8_8_ = auVar61._8_8_;
              fVar48 = (float)(uint)(ushort)(uVar20 - 600);
              uVar49 = uVar19;
              FUN_1400709b0(4,10);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            iVar16 = DAT_140e419b8;
          }
          if ((iVar15 + 600 <= iVar13) && ((iVar13 - (iVar15 + 600)) % (iVar15 * 2) == 0)) {
            uVar103 = 0;
            uVar12 = uVar11 - 1;
            uVar11 = (int)(44000 / (ulonglong)uVar12) * (uVar11 - 2) & 0xffff;
            uVar101 = (ulonglong)uVar12;
            auVar62._12_4_ = auVar52._12_4_;
            auVar62._0_8_ = auVar52._0_8_;
            auVar62._8_4_ = 1;
            auVar52._8_8_ = auVar62._8_8_;
            auVar52._0_8_ = dVar34;
            fVar48 = (float)(uVar23 & 0xffff);
            uVar49 = uVar19;
            uVar102 = uVar11;
            FUN_1400709b0(4,10);
            if (param_1[5] == 0xc) {
              auVar63._12_4_ = auVar52._12_4_;
              auVar63._0_8_ = auVar52._0_8_;
              auVar63._8_4_ = 1;
              auVar64._8_8_ = auVar63._8_8_;
              auVar64._0_8_ = dVar34;
              FUN_1400709b0(4,10);
              uVar103 = 0;
              uVar101 = (ulonglong)uVar12;
              auVar65._12_4_ = auVar64._12_4_;
              auVar65._0_8_ = auVar64._0_8_;
              auVar65._8_4_ = 1;
              auVar52._8_8_ = auVar65._8_8_;
              fVar48 = (float)(uint)(ushort)(uVar20 - 600);
              uVar49 = uVar19;
              FUN_1400709b0(4,10);
              uVar102 = uVar11;
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            iVar16 = DAT_140e419b8;
          }
        }
        if (param_1[6] == 0x84) {
          iVar15 = 1;
          if (iVar16 == 0) {
            iVar15 = 0x6e;
          }
          else if (iVar16 == 1) {
            iVar15 = 0x4e;
          }
          else if (iVar16 == 2) {
            iVar15 = 0x3c;
          }
          else if ((iVar16 == 3) || (iVar16 == 4)) {
            iVar15 = 0x32;
          }
          uVar11 = 1;
          if (iVar16 == 0) {
            uVar11 = 3;
          }
          else if (iVar16 == 1) {
            uVar11 = 5;
          }
          else if (iVar16 == 2) {
            uVar11 = 7;
          }
          else if (iVar16 == 3) {
            uVar11 = 9;
          }
          else if (iVar16 == 4) {
            uVar11 = 0xb;
          }
          iVar7 = 1;
          if (iVar16 == 0) {
            iVar7 = 0x1194;
          }
          else if (iVar16 == 1) {
            iVar7 = 0xce4;
          }
          else if (iVar16 == 2) {
            iVar7 = 0xa8c;
          }
          else if (iVar16 == 3) {
            iVar7 = 0x960;
          }
          else if (iVar16 == 4) {
            iVar7 = 2000;
          }
          if ((((iVar16 != 0) && (dVar38 = dVar32, iVar16 != 1)) && (dVar38 = dVar6, iVar16 != 2))
             && ((iVar16 != 3 && (dVar38 = DAT_140539f40, iVar16 == 4)))) {
            dVar38 = dVar37;
          }
          iVar16 = (iVar13 + -0x294) % iVar15;
          dVar38 = (double)iVar16 * DAT_140539e50 + dVar38;
          if ((iVar13 < 0x294) || (iVar16 != 0)) {
            uVar50 = *(ushort *)((longlong)param_1 + 0x42);
            fVar39 = (float)(uint)uVar50;
            uVar12 = (uint)uVar50;
            if (0x293 < iVar13) goto LAB_14002eca6;
LAB_14002ee02:
            uVar42 = SUB84(DAT_140539f00,0);
            uVar43 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
          }
          else {
            *(ushort *)((longlong)param_1 + 0x42) = uVar20;
            fVar39 = (float)(uVar23 & 0xffff);
            uVar12 = uVar23 & 0xffff;
LAB_14002eca6:
            uVar50 = (ushort)uVar12;
            iVar16 = (iVar13 + -0x294) % (iVar15 * 2);
            if ((0x31 < iVar16) || (iVar16 != (iVar16 / 5) * 5)) goto LAB_14002ee02;
            uVar103 = 0;
            uVar28 = (uVar11 - 1) * iVar7;
            uVar101 = (ulonglong)uVar11;
            auVar66._12_4_ = auVar52._12_4_;
            auVar66._0_8_ = auVar52._0_8_;
            auVar66._8_4_ = 1;
            auVar52._8_8_ = auVar66._8_8_;
            auVar52._0_8_ = dVar38;
            uVar49 = uVar19;
            uVar102 = uVar28;
            FUN_1400709b0(9,0,fVar39,uVar12,fVar39,uVar19,dVar38,auVar52._8_8_,uVar101,uVar28,0);
            uVar42 = SUB84(DAT_140539f00,0);
            uVar43 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
            fVar48 = fVar39;
            if (param_1[5] == 0xd) {
              dVar31 = dVar38 - DAT_140539f00;
              auVar67._12_4_ = auVar52._12_4_;
              auVar67._0_8_ = auVar52._0_8_;
              auVar67._8_4_ = 1;
              auVar68._8_8_ = auVar67._8_8_;
              auVar68._0_8_ = dVar31;
              FUN_1400709b0(9,0);
              uVar103 = 0;
              uVar101 = (ulonglong)uVar11;
              auVar69._12_4_ = auVar68._12_4_;
              auVar69._0_8_ = auVar68._0_8_;
              auVar69._8_4_ = 1;
              auVar52._8_8_ = auVar69._8_8_;
              auVar52._0_8_ = dVar31;
              fVar48 = (float)(uint)(ushort)(*(short *)((longlong)param_1 + 0x42) - 400);
              uVar49 = uVar19;
              FUN_1400709b0(9,0);
              uVar102 = uVar28;
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            uVar50 = *(ushort *)((longlong)param_1 + 0x42);
          }
          if (((iVar15 + 0x294 <= iVar13) &&
              (iVar16 = (iVar13 - (iVar15 + 0x294)) % (iVar15 * 2), iVar16 < 0x32)) &&
             (iVar16 == (iVar16 / 5) * 5)) {
            uVar103 = 0;
            uVar12 = (uVar11 - 2) * iVar7;
            uVar101 = (ulonglong)(uVar11 - 1);
            auVar70._12_4_ = auVar52._12_4_;
            auVar70._0_8_ = auVar52._0_8_;
            auVar70._8_4_ = 1;
            auVar52._8_8_ = auVar70._8_8_;
            auVar52._0_8_ = dVar38;
            fVar48 = (float)(uint)uVar50;
            uVar49 = uVar19;
            uVar102 = uVar12;
            FUN_1400709b0(9,0);
            if (param_1[5] == 0xd) {
              dVar38 = dVar38 - (double)CONCAT44(uVar43,uVar42);
              auVar71._12_4_ = auVar52._12_4_;
              auVar71._0_8_ = auVar52._0_8_;
              auVar71._8_4_ = 1;
              auVar72._8_8_ = auVar71._8_8_;
              auVar72._0_8_ = dVar38;
              FUN_1400709b0(9,0);
              uVar103 = 0;
              uVar101 = (ulonglong)(uVar11 - 1);
              auVar73._12_4_ = auVar72._12_4_;
              auVar73._0_8_ = auVar72._0_8_;
              auVar73._8_4_ = 1;
              auVar52._8_8_ = auVar73._8_8_;
              auVar52._0_8_ = dVar38;
              fVar48 = (float)(uint)(ushort)(*(short *)((longlong)param_1 + 0x42) - 400);
              FUN_1400709b0(9,0);
              uVar49 = uVar19;
              uVar102 = uVar12;
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
          uVar50 = *(ushort *)((longlong)param_1 + 0x42);
          iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
          iVar16 = iVar13 + 0x10000;
          if (-0x8001 < iVar13) {
            iVar16 = iVar13;
          }
          iVar13 = iVar16 + -0x10000;
          if (iVar16 < 0x8001) {
            iVar13 = iVar16;
          }
          if (iVar13 < 1) {
            uVar18 = uVar50;
            if ((iVar13 < 0) && (uVar18 = uVar50 - 0x10, -0x10 < iVar13)) {
              uVar18 = uVar20;
            }
          }
          else {
            uVar18 = uVar20;
            if (0xf < iVar13) {
              uVar18 = uVar50 + 0x10;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar18;
        }
      }
      iVar16 = DAT_140e41b0c;
      fVar40 = DAT_14053af14;
      uVar44 = SUB84(DAT_14053a020,0);
      uVar45 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
      uVar42 = SUB84(DAT_140539d28,0);
      uVar43 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      if (param_1[5] == 0xb) {
        if (param_1[3] == 1) {
          *(undefined8 *)(param_1 + 0x14) = 0x50;
          param_1[8] = iVar16 / 2;
          param_1[7] = iVar16 / 2;
        }
        goto LAB_14002fb02;
      }
    }
    else {
      param_1[0xb] = 0x46ea6000;
      param_1[10] = 0;
      param_1[0x15] = 1;
    }
    break;
  case 0x14:
  case 0x1e:
  case 0x28:
  case 0x32:
  case 0x3b:
  case 0x3c:
    iVar16 = 0x83;
    if ((local_140._4_4_ < 0x3d) &&
       ((0x1004010000000000U >> ((longlong)(int)local_140._4_4_ & 0x3fU) & 1) != 0)) {
      iVar16 = 0x84;
    }
    if (iVar15 == iVar16) {
      if (uStack_148._4_4_ == 1) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
        FUN_14018a340(DAT_140e47298,1,1);
        uVar46 = param_1[0xb];
        uVar47 = param_1[10];
        puVar9 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar9 = (undefined8 *)_malloc_base();
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar30 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar9 + 0x14) = uVar47;
          *(undefined4 *)(puVar9 + 3) = uVar46;
          *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar47;
          *(undefined4 *)(puVar9 + 4) = uVar46;
          *puVar9 = 1;
          puVar9[1] = 0x36;
          *(undefined4 *)(puVar9 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          puVar9[5] = 0;
          puVar9[6] = 0x3ff0000000000000;
          puVar9[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar9 + 8) = 0;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)(puVar9 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          puVar9[10] = 0xff;
          puVar9[0xb] = 0;
          if (bVar30) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
        DAT_140e45d28 = puVar9;
        param_1[0x15] = 1;
      }
      if ((int)param_1[3] < 0x5a) {
        FUN_14007ac00(param_1);
      }
      iVar16 = param_1[3];
      dVar31 = (double)FUN_140332d90(((double)iVar16 - _DAT_140539cc0) * DAT_14053a558 * dVar34 *
                                     dVar31);
      iVar13 = param_1[6];
      dVar3 = dVar31 * _DAT_14053b070 + dVar3;
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      goto joined_r0x000140031415;
    }
    if (((local_140._4_4_ == 0x14) && (iVar15 == 0x84)) ||
       ((local_140._4_4_ == 0x28 && (iVar15 == 0x83)))) {
      param_1[0xb] = 0x46ea6000;
      param_1[10] = 0;
    }
    if (local_140._4_4_ - 0x3b < 2) {
      if (iVar15 == 0x83) {
        dVar31 = (double)FUN_140332d90();
        fVar39 = (float)(dVar31 * _DAT_140539cc0) + DAT_14053adc4;
        dVar31 = (double)FUN_140332d90();
        dVar31 = dVar31 * _DAT_14053b270;
        param_1[10] = fVar39;
        param_1[0xb] = (float)dVar31 + DAT_14053af80;
      }
      else if (iVar15 == 0x84) {
        dVar31 = (double)FUN_140332d90();
        fVar39 = (float)(dVar31 * _DAT_140539cc0) + DAT_14053ae88;
        dVar31 = (double)FUN_140332d90();
        dVar31 = dVar31 * _DAT_14053b270;
        param_1[10] = fVar39;
        param_1[0xb] = (float)dVar31 + DAT_14053af80;
      }
    }
    break;
  case 0x15:
    if (uStack_148._4_4_ == 1) {
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
    }
    if (iVar15 == 0x83) {
      iVar15 = (int)uStack_148._4_4_ % 0x35c;
      dVar31 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),
                                     (double)(DAT_140e445d8 - fVar39));
      uVar50 = *(ushort *)(param_1 + 0x10);
      iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
      iVar16 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar16 = iVar13;
      }
      iVar13 = iVar16 + -0x10000;
      if (iVar16 < 0x8001) {
        iVar13 = iVar16;
      }
      if (iVar13 < 1) {
        uVar18 = uVar50;
        if ((iVar13 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar13)) {
          uVar18 = uVar20;
        }
      }
      else {
        uVar18 = uVar20;
        if (0x1ff < iVar13) {
          uVar18 = uVar50 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar18;
      dVar34 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar34 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      if (uStack_148._4_4_ == 1) {
        param_1[0x15] = 0;
      }
      if (iVar15 == 10) {
        uVar20 = 0x8000;
        uVar102 = param_1[1];
        if (900 < uStack_148._4_4_ - 100) {
          uVar20 = 0;
        }
        uVar101 = 1;
        auVar74._12_4_ = auVar52._12_4_;
        auVar74._0_8_ = auVar52._0_8_;
        auVar74._8_4_ = 0x1e;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = auVar74._8_8_;
        auVar52 = auVar4 << 0x40;
        uVar49 = (uint)uVar20;
        fVar48 = DAT_14053adb4;
        stage_entity_spawn_candidate((uStack_148._4_4_ - 100 < 0x385) + 0x8f,99999999,100);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
      uVar19 = 1;
      if (DAT_140e419b8 == 0) {
        uVar19 = 0xf;
      }
      else if (DAT_140e419b8 == 1) {
        uVar19 = 0x13;
      }
      else if (DAT_140e419b8 == 2) {
        uVar19 = 0x17;
      }
      else if (DAT_140e419b8 == 3) {
        uVar19 = 0x19;
      }
      else if (DAT_140e419b8 == 4) {
        uVar19 = 0x1b;
      }
      local_res18 = 1;
      if (DAT_140e419b8 == 0) {
        local_res18 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        local_res18 = 0x19;
      }
      else if (DAT_140e419b8 == 2) {
        local_res18 = 0x1e;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        local_res18 = 0x28;
      }
      sVar10 = 1;
      if (DAT_140e419b8 == 0) {
        sVar10 = 0x140;
      }
      else if (DAT_140e419b8 == 1) {
        sVar10 = 0x1a4;
      }
      else if (DAT_140e419b8 == 2) {
        sVar10 = 0x1cc;
      }
      else if (DAT_140e419b8 == 3) {
        sVar10 = 0x1e0;
      }
      else if (DAT_140e419b8 == 4) {
        sVar10 = 500;
      }
      dVar34 = DAT_14053a0d8;
      if ((((DAT_140e419b8 != 0) && (dVar34 = DAT_14053a110, DAT_140e419b8 != 1)) &&
          (dVar34 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((dVar34 = DAT_14053a160, DAT_140e419b8 != 3 && (dVar34 = dVar3, DAT_140e419b8 == 4)))) {
        dVar34 = DAT_14053a190;
      }
      if ((iVar15 == 0x294) || (iVar15 == 0x2f8)) {
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
      }
      uVar23 = DAT_14053ac2c;
      if (((0x293 < iVar15) && (iVar15 < local_res18 + 0x294)) &&
         (iVar15 + -0x294 == ((iVar15 + -0x294) / 5) * 5)) {
        uVar20 = *(ushort *)((longlong)param_1 + 0x42);
        if (uVar19 == 1) {
          uVar101 = 0;
          auVar76._12_4_ = auVar52._12_4_;
          auVar76._0_8_ = auVar52._0_8_;
          auVar76._8_4_ = 1;
          auVar52._8_8_ = auVar76._8_8_;
          auVar52._0_8_ = dVar34;
          fVar48 = (float)(uint)uVar20;
          uVar49 = DAT_14053ac2c;
          FUN_14006c2f0(3,0x21);
        }
        else {
          iVar16 = 0;
          do {
            uVar101 = 0;
            auVar75._12_4_ = auVar52._12_4_;
            auVar75._0_8_ = auVar52._0_8_;
            auVar75._8_4_ = 1;
            auVar52._8_8_ = auVar75._8_8_;
            auVar52._0_8_ = dVar34;
            fVar48 = (float)(uint)(ushort)((short)iVar16 * (short)(0x10000 / (ulonglong)uVar19) +
                                          uVar20);
            uVar49 = uVar23;
            FUN_14006c2f0(3,0x21);
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar19);
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar10;
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      if (((0x2f7 < iVar15) && (iVar15 < local_res18 + 0x2f8)) &&
         (iVar15 + -0x2f8 == ((iVar15 + -0x2f8) / 5) * 5)) {
        uVar20 = *(ushort *)((longlong)param_1 + 0x42);
        if (uVar19 == 1) {
          uVar101 = 0;
          auVar78._12_4_ = auVar52._12_4_;
          auVar78._0_8_ = auVar52._0_8_;
          auVar78._8_4_ = 1;
          auVar52._8_8_ = auVar78._8_8_;
          auVar52._0_8_ = dVar34;
          fVar48 = (float)(uint)uVar20;
          FUN_14006c2f0(3,0x22);
          uVar49 = uVar23;
        }
        else {
          iVar16 = 0;
          do {
            uVar101 = 0;
            auVar77._12_4_ = auVar52._12_4_;
            auVar77._0_8_ = auVar52._0_8_;
            auVar77._8_4_ = 1;
            auVar52._8_8_ = auVar77._8_8_;
            auVar52._0_8_ = dVar34;
            fVar48 = (float)(uint)(ushort)((short)iVar16 * (short)(0x10000 / (ulonglong)uVar19) +
                                          uVar20);
            uVar49 = uVar23;
            FUN_14006c2f0(3,0x22);
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar19);
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar10;
LAB_14002f508:
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    else {
LAB_14002f537:
      param_1[0xb] = 0x461c4000;
    }
    break;
  case 0x1f:
    if (uStack_148._4_4_ == 1) {
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
    }
    if (iVar15 != 0x83) goto LAB_14002f537;
    uVar50 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
    iVar16 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar16 = iVar13;
    }
    iVar13 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar13 = iVar16;
    }
    if (iVar13 < 1) {
      uVar18 = uVar50;
      if ((iVar13 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar13)) {
        uVar18 = uVar20;
      }
    }
    else {
      uVar18 = uVar20;
      if (0x1ff < iVar13) {
        uVar18 = uVar50 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar31 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar31 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (uStack_148._4_4_ == 1) {
      param_1[0x15] = 0;
    }
    if ((uStack_148._4_4_ - 10 < 0x50) &&
       (iVar16 = uStack_148._4_4_ - 10,
       iVar16 == (iVar16 / 3 + (iVar16 >> 0x1f) +
                 (int)(((longlong)iVar16 / 3 + ((longlong)iVar16 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                 3)) {
      uVar19 = (uStack_148._4_4_ >> 0x1e ^ uStack_148._4_4_) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar102 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar102) >> 8 ^ DAT_140e9fd18 ^ uVar102;
      uVar102 = param_1[1];
      uVar101 = CONCAT44((int)(uVar101 >> 0x20),1);
      auVar79._12_4_ = auVar52._12_4_;
      auVar79._0_8_ = auVar52._0_8_;
      auVar79._8_4_ = 0x14;
      auVar52._8_8_ = auVar79._8_8_;
      auVar52._0_8_ = DAT_14053a0b0;
      uVar49 = (uint)(ushort)((short)((ulonglong)DAT_140e9fd1c / 0xbb81) * 0x447f +
                              (short)DAT_140e9fd1c + 0x6240);
      stage_entity_spawn_candidate
                (0x93,99999999,0,uVar19,fVar41,uVar49,DAT_14053a0b0,auVar52._8_8_,uVar101,uVar102);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      fVar48 = fVar41;
    }
    fVar39 = DAT_14053ac34;
    iVar16 = param_1[3];
    if (99 < iVar16) {
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0xf0;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0xb4;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar13 = 0xa0;
      }
      else if (DAT_140e419b8 == 4) {
        iVar13 = 0x96;
      }
      iVar15 = 1;
      uVar1 = (longlong)(iVar16 + -100) % (longlong)(iVar13 * 4);
      iVar16 = (iVar16 + -100) % iVar13;
      if (DAT_140e419b8 == 0) {
        iVar15 = 9;
      }
      else if (DAT_140e419b8 == 1) {
        iVar15 = 6;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar15 = 5;
      }
      local_res8 = 1;
      if (DAT_140e419b8 == 0) {
        local_res8 = 0xb;
      }
      else if (DAT_140e419b8 == 1) {
        local_res8 = 8;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        local_res8 = 7;
      }
      if (DAT_140e419b8 == 0) {
        iVar7 = 0;
        dVar31 = DAT_14053a018;
      }
      else {
        iVar7 = 0;
        if (((DAT_140e419b8 == 1) || (iVar7 = 0, DAT_140e419b8 == 2)) ||
           ((iVar7 = DAT_140e419b8 + -3, iVar7 == 0 || (dVar31 = dVar3, iVar7 == 1)))) {
          dVar31 = DAT_14053a070;
        }
      }
      sVar10 = (short)iVar16 * 0x78;
      uVar20 = (short)iVar16 * 0x3c - 1000;
      uVar19 = (uint)uVar1;
      if ((uVar19 < 0x3c) &&
         ((int)((longlong)((ulonglong)(uint)((int)uVar19 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
               (longlong)iVar15) == 0)) {
        uVar101 = uVar101 & 0xffffffff00000000;
        auVar80._12_4_ = auVar52._12_4_;
        auVar80._0_8_ = auVar52._0_8_;
        auVar80._8_4_ = 1;
        auVar52._8_8_ = auVar80._8_8_;
        auVar52._0_8_ = dVar31;
        uVar49 = 0;
        fVar48 = (float)(uint)(ushort)(0x4000 - (sVar10 + -0xc80));
        FUN_14006c2f0(0x13,0x23,(float)iVar16 * DAT_14053ac34,iVar7,fVar48,0,dVar31,auVar52._8_8_,
                      uVar101);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
      if (((iVar13 <= (int)uVar19) && ((int)uVar19 < iVar13 + 0x3c)) &&
         ((int)(uVar19 - iVar13) % iVar15 == 0)) {
        uVar101 = 0;
        auVar81._12_4_ = auVar52._12_4_;
        auVar81._0_8_ = auVar52._0_8_;
        auVar81._8_4_ = 1;
        auVar52._8_8_ = auVar81._8_8_;
        auVar52._0_8_ = dVar31;
        uVar49 = 0;
        fVar48 = (float)(uint)(ushort)(sVar10 + 0x3380);
        FUN_14006c2f0(0x13,0x23,
                      (DAT_14053af14 - (float)iVar16 * fVar39) + (float)iVar15 * DAT_14053ab70);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
      if (((iVar13 * 2 <= (int)uVar19) && ((int)uVar19 < iVar13 * 2 + 0x3c)) &&
         ((int)(uVar19 + iVar13 * -2) % local_res8 == 0)) {
        uVar101 = 0;
        auVar82._12_4_ = auVar52._12_4_;
        auVar82._0_8_ = auVar52._0_8_;
        auVar82._8_4_ = 1;
        auVar52._8_8_ = auVar82._8_8_;
        auVar52._0_8_ = dVar31;
        uVar49 = 0;
        fVar48 = (float)(uint)(ushort)(0x8000 - uVar20);
        FUN_14006c2f0(0x13,0x24);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
      fVar40 = DAT_14053af14;
      if (((iVar13 * 3 <= (int)uVar19) && ((int)uVar19 < (iVar13 + 0x14) * 3)) &&
         ((int)(uVar19 + iVar13 * -3) % local_res8 == 0)) {
        uVar101 = 0;
        auVar83._12_4_ = auVar52._12_4_;
        auVar83._0_8_ = auVar52._0_8_;
        auVar83._8_4_ = 1;
        auVar52._8_8_ = auVar83._8_8_;
        auVar52._0_8_ = dVar31;
        uVar49 = 0;
        fVar48 = (float)(uint)uVar20;
        FUN_14006c2f0(0x13,0x24);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
        fVar40 = DAT_14053af14;
      }
    }
    break;
  case 0x29:
    if (uStack_148._4_4_ == 1) {
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
    }
    if (iVar15 != 0x84) goto LAB_14002f537;
    iVar15 = (int)uStack_148._4_4_ % 0x35c;
    dVar31 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),(double)(DAT_140e445d8 - fVar39)
                                  );
    uVar50 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
    iVar16 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar16 = iVar13;
    }
    iVar13 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar13 = iVar16;
    }
    if (iVar13 < 1) {
      uVar18 = uVar50;
      if ((iVar13 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar13)) {
        uVar18 = uVar20;
      }
    }
    else {
      uVar18 = uVar20;
      if (0x1ff < iVar13) {
        uVar18 = uVar50 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar34 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar34 = (double)FUN_140332d90();
    iVar16 = 0;
    param_1[0xb] = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (uStack_148._4_4_ == 1) {
      param_1[0x15] = 0;
    }
    if (iVar15 == 10) {
      uVar20 = 0;
      uVar102 = param_1[1];
      if (900 < uStack_148._4_4_ - 100) {
        uVar20 = 0x8000;
      }
      uVar101 = 1;
      auVar84._12_4_ = auVar52._12_4_;
      auVar84._0_8_ = auVar52._0_8_;
      auVar84._8_4_ = 0x1e;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = auVar84._8_8_;
      auVar52 = auVar5 << 0x40;
      uVar49 = (uint)uVar20;
      fVar48 = DAT_14053adb4;
      stage_entity_spawn_candidate((uStack_148._4_4_ - 100 < 0x385) + 0x91,99999999,0);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 4;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 3;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar13 = 2;
    }
    uVar19 = 1;
    if (DAT_140e419b8 == 0) {
      uVar19 = 5;
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      uVar19 = 6;
    }
    else if (DAT_140e419b8 == 3) {
      uVar19 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      uVar19 = 8;
    }
    sVar10 = 1;
    if (DAT_140e419b8 == 0) {
      sVar10 = 0xdac;
    }
    else if (DAT_140e419b8 == 1) {
      sVar10 = 0x10cc;
    }
    else if (DAT_140e419b8 == 2) {
LAB_14002feb0:
      sVar10 = 0xc80;
    }
    else if (DAT_140e419b8 == 3) {
      sVar10 = 0xf3c;
    }
    else if (DAT_140e419b8 == 4) goto LAB_14002feb0;
    dVar34 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar34 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
       ((dVar34 = DAT_14053a118, DAT_140e419b8 != 2 &&
        ((dVar34 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar34 = dVar3, DAT_140e419b8 == 4)))))) {
      dVar34 = DAT_14053a178;
    }
    if ((iVar15 == 0x294) || (iVar15 == 0x2f8)) {
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
    }
    uVar23 = DAT_14053ac2c;
    if ((iVar15 - 0x294U < 0x28) && ((int)(iVar15 - 0x294U) % iVar13 == 0)) {
      uVar20 = *(ushort *)((longlong)param_1 + 0x42);
      if (uVar19 == 1) {
        uVar101 = 0;
        auVar86._12_4_ = auVar52._12_4_;
        auVar86._0_8_ = auVar52._0_8_;
        auVar86._8_4_ = 1;
        auVar52._8_8_ = auVar86._8_8_;
        auVar52._0_8_ = dVar34;
        fVar48 = (float)(uint)uVar20;
        uVar49 = DAT_14053ac2c;
        FUN_14006c2f0(3,0x22);
      }
      else {
        do {
          uVar101 = 0;
          auVar85._12_4_ = auVar52._12_4_;
          auVar85._0_8_ = auVar52._0_8_;
          auVar85._8_4_ = 1;
          auVar52._8_8_ = auVar85._8_8_;
          auVar52._0_8_ = dVar34;
          fVar48 = (float)(uint)(ushort)((short)iVar16 * (short)(0x10000 / (ulonglong)uVar19) +
                                        uVar20);
          uVar49 = uVar23;
          FUN_14006c2f0(3,0x22);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar19);
      }
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar10;
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    iVar16 = 0;
    if ((iVar15 - 0x2f8U < 0x28) && ((int)(iVar15 - 0x2f8U) % iVar13 == 0)) {
      uVar20 = *(ushort *)((longlong)param_1 + 0x42);
      if (uVar19 == 1) {
        uVar101 = 0;
        auVar88._12_4_ = auVar52._12_4_;
        auVar88._0_8_ = auVar52._0_8_;
        auVar88._8_4_ = 1;
        auVar52._8_8_ = auVar88._8_8_;
        auVar52._0_8_ = dVar34;
        fVar48 = (float)(uint)uVar20;
        FUN_14006c2f0(3,0x21);
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar10;
        uVar49 = uVar23;
      }
      else {
        do {
          uVar101 = 0;
          auVar87._12_4_ = auVar52._12_4_;
          auVar87._0_8_ = auVar52._0_8_;
          auVar87._8_4_ = 1;
          auVar52._8_8_ = auVar87._8_8_;
          auVar52._0_8_ = dVar34;
          fVar48 = (float)(uint)(ushort)((short)iVar16 * (short)(0x10000 / (ulonglong)uVar19) +
                                        uVar20);
          uVar49 = uVar23;
          FUN_14006c2f0(3,0x21);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar19);
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar10;
      }
      goto LAB_14002f508;
    }
    break;
  case 0x33:
    if (uStack_148._4_4_ == 1) {
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
    }
    if (iVar15 != 0x84) goto LAB_14002f537;
    uVar50 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar23 & 0xffff) - (uint)uVar50;
    iVar16 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar16 = iVar13;
    }
    iVar13 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar13 = iVar16;
    }
    if (iVar13 < 1) {
      uVar18 = uVar50;
      if ((iVar13 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar13)) {
        uVar18 = uVar20;
      }
    }
    else {
      uVar18 = uVar20;
      if (0x1ff < iVar13) {
        uVar18 = uVar50 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar31 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar31 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (uStack_148._4_4_ == 1) {
      param_1[0x15] = 0;
    }
    iVar16 = DAT_140e419b8;
    fVar36 = DAT_14053ac80;
    if (9 < (int)uStack_148._4_4_) {
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0x5a;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar13 = 0x46;
      }
      iVar15 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar15 = 800;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar15 = 0x294;
      }
      else if (DAT_140e419b8 == 4) {
        iVar15 = 0x244;
      }
      iVar7 = 1;
      iVar24 = iVar13 * 5 + 0x1e;
      uVar1 = (longlong)(int)(uStack_148._4_4_ - 10) % (longlong)(iVar15 + iVar13 * 5);
      iVar15 = (int)uVar1;
      uVar19 = iVar15 >> 0x1f;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0xb;
        iVar14 = 0;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 7;
        iVar14 = 0;
      }
      else if (DAT_140e419b8 == 2) {
        iVar7 = 6;
        iVar14 = 0;
      }
      else {
        iVar14 = DAT_140e419b8 + -3;
        if (iVar14 == 0) {
          iVar7 = 5;
        }
        else if (iVar14 == 1) {
          iVar7 = 4;
        }
      }
      if (iVar15 == 0) {
        dVar31 = (double)FUN_1403300b4(iVar14,(double)(DAT_14053ac80 - fVar39));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
        dVar31 = (double)FUN_1403300b4();
        *(short *)(param_1 + 0x11) = (short)(int)(dVar31 * dVar35);
      }
      else if (iVar15 == iVar13) {
        dVar31 = (double)FUN_1403300b4((double)(0.0 - fVar41));
        fVar40 = DAT_14053af14 - fVar41;
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
        dVar31 = (double)FUN_1403300b4((double)fVar40);
        *(short *)(param_1 + 0x11) = (short)(int)(dVar31 * dVar35);
      }
      local_158 = param_1 + 0x11;
      local_res20 = (undefined2 *)((longlong)param_1 + 0x42);
      if (iVar15 == iVar13 * 2) {
        dVar31 = (double)FUN_1403300b4();
        *local_res20 = (short)(int)(dVar31 * dVar35);
        dVar31 = (double)FUN_1403300b4(local_res20,(double)(fVar36 - fVar39));
        *(short *)local_158 = (short)(int)(dVar31 * dVar35);
      }
      if (iVar15 == iVar13 * 3) {
        dVar31 = (double)FUN_1403300b4((double)(0.0 - fVar41));
        fVar40 = DAT_14053af14 - fVar41;
        *(undefined2 *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
        dVar31 = (double)FUN_1403300b4((double)fVar40);
        *(short *)(param_1 + 0x11) = (short)(int)(dVar31 * dVar35);
      }
      if (iVar15 == iVar13 * 4) {
        dVar31 = (double)FUN_1403300b4();
        *(undefined2 *)((longlong)param_1 + 0x42) = (short)(int)(dVar31 * dVar35);
        dVar31 = (double)FUN_1403300b4();
        *(short *)(param_1 + 0x11) = (short)(int)(dVar31 * dVar35);
      }
      dVar31 = DAT_14053a0f8;
      if ((((-1 < iVar15) && (iVar15 < iVar13 * 5)) &&
          ((int)((longlong)((ulonglong)uVar19 << 0x20 | uVar1 & 0xffffffff) % (longlong)iVar13) <
           0x28)) &&
         (uVar2 = (longlong)((ulonglong)uVar19 << 0x20 | uVar1 & 0xffffffff) % (longlong)iVar13,
         (int)((longlong)((ulonglong)(uint)((int)uVar2 >> 0x1f) << 0x20 | uVar2 & 0xffffffff) %
              (longlong)iVar7) == 0)) {
        iVar7 = (uint)*(ushort *)(param_1 + 0x11) - (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar16 = iVar7 + 0x10000;
        if (-0x8001 < iVar7) {
          iVar16 = iVar7;
        }
        iVar7 = iVar16 + -0x10000;
        if (iVar16 < 0x8001) {
          iVar7 = iVar16;
        }
        local_res8._0_2_ =
             (short)((longlong)((ulonglong)uVar19 << 0x20 | uVar1 & 0xffffffff) % (longlong)iVar13);
        uVar102 = param_1[1];
        uVar101 = 1;
        auVar89._12_4_ = auVar52._12_4_;
        auVar89._0_8_ = auVar52._0_8_;
        auVar89._8_4_ = 0x14;
        auVar52._8_8_ = auVar89._8_8_;
        auVar52._0_8_ = DAT_14053a0f8;
        uVar49 = (uint)(ushort)((short)(iVar7 / 0x28) * (short)local_res8 +
                               *(ushort *)((longlong)param_1 + 0x42));
        fVar48 = fVar41;
        stage_entity_spawn_candidate
                  (0x94,99999999,0,0x8000,fVar41,uVar49,DAT_14053a0f8,auVar52._8_8_,1,uVar102);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
        iVar16 = DAT_140e419b8;
      }
      iVar13 = 1;
      if ((iVar16 == 0) || (iVar16 == 1)) {
        iVar13 = 0xfa;
      }
      else if ((iVar16 == 2) || (iVar16 == 3)) {
        iVar13 = 200;
      }
      else if (iVar16 == 4) {
        iVar13 = 0xb4;
      }
      iVar7 = 1;
      if (iVar16 == 0) {
        iVar7 = 0x11;
      }
      else if (iVar16 == 1) {
        iVar7 = 9;
      }
      else if (iVar16 == 2) {
        iVar7 = 5;
      }
      else if (iVar16 == 3) {
        iVar7 = 4;
      }
      else if (iVar16 == 4) {
        iVar7 = 3;
      }
      uVar19 = 1;
      if ((iVar16 == 0) || (iVar16 == 1)) {
        uVar19 = 0xa0;
      }
      else if (((iVar16 == 2) || (iVar16 == 3)) || (iVar16 == 4)) {
        uVar19 = 0x78;
      }
      iVar16 = (iVar15 - iVar24) % (iVar13 * 2);
      if (((iVar24 <= iVar15) && (iVar15 < iVar13 * 3 + iVar24)) && (iVar16 == 0)) {
        dVar34 = (double)FUN_1403300b4((double)(0.0 - fVar41),(double)(0.0 - fVar39));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar34 * dVar35);
      }
      fVar40 = DAT_14053af14;
      if (((iVar24 + iVar13 <= iVar15) && (iVar15 < iVar13 * 3 + iVar24)) &&
         ((iVar15 - (iVar24 + iVar13)) % (iVar13 * 2) == 0)) {
        dVar34 = (double)FUN_1403300b4((double)(0.0 - fVar41),(double)(DAT_14053af14 - fVar39));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar34 * dVar35);
      }
      if ((iVar24 <= iVar15) && (iVar15 < iVar24 + iVar13 * 3)) {
        uVar1 = (longlong)(iVar15 - iVar24) % (longlong)iVar13;
        iVar14 = (int)uVar1;
        if ((iVar14 < (int)uVar19) &&
           ((int)((longlong)((ulonglong)(uint)(iVar14 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
                 (longlong)iVar7) == 0)) {
          sVar10 = (short)((iVar15 - iVar24) % iVar13) * (short)(0x10000 / uVar19);
          if (iVar13 <= iVar16) {
            sVar10 = -sVar10;
          }
          uVar102 = param_1[1];
          uVar101 = 1;
          auVar90._12_4_ = auVar52._12_4_;
          auVar90._0_8_ = auVar52._0_8_;
          auVar90._8_4_ = 0x14;
          auVar52._8_8_ = auVar90._8_8_;
          auVar52._0_8_ = dVar31;
          uVar49 = (uint)(ushort)(*(short *)((longlong)param_1 + 0x42) + sVar10);
          stage_entity_spawn_candidate(0x94,99999999,0);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
          FUN_14018a340(DAT_140e472d4,1,1);
          fVar48 = fVar41;
        }
      }
      uVar42 = SUB84(DAT_140539d28,0);
      uVar43 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    }
    break;
  case 0x3d:
    uVar50 = *(ushort *)(param_1 + 0x10);
    iVar15 = (uVar23 & 0xffff) - (uint)uVar50;
    iVar13 = iVar15 + 0x10000;
    if (-0x8001 < iVar15) {
      iVar13 = iVar15;
    }
    iVar15 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar15 = iVar13;
    }
    if (iVar15 < 1) {
      uVar18 = uVar50;
      if ((iVar15 < 0) && (uVar18 = uVar50 - 0x200, -0x200 < iVar15)) {
        uVar18 = uVar20;
      }
    }
    else {
      uVar18 = uVar20;
      if (0x1ff < iVar15) {
        uVar18 = uVar50 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar31 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar31 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar13 = DAT_140e45d1c;
    puVar8 = DAT_140e45d28;
    if (uStack_148._4_4_ == 1) {
      uVar46 = param_1[1];
      param_1[0x15] = 0;
      param_1[8] = (undefined4)local_130;
      param_1[7] = uStack_138._4_4_;
      puVar8 = DAT_140e45d28;
      if (iVar13 < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar30 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar8 = 1;
        puVar8[1] = 0x2d;
        puVar8[2] = 0x3c;
        puVar8[3] = 0;
        *(undefined4 *)(puVar8 + 4) = 0;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0x3ff0000000000000;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0x3c;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        *(undefined4 *)(puVar8 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x54) = uVar46;
        puVar8[0xb] = 0;
        if (bVar30) {
          DAT_140e45d78 = puVar8;
        }
        puVar9 = DAT_140e45d80;
        iVar16 = DAT_140e44308;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
          puVar9 = DAT_140e45d80;
          iVar16 = DAT_140e44308;
        }
      }
    }
    DAT_140e45d28 = puVar8;
    uVar19 = DAT_14053ac2c;
    iVar13 = param_1[3];
    iVar15 = DAT_140e419b8;
    if (iVar13 < 0x1e0) {
      dVar31 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),
                                     (double)(DAT_140e445d8 - fVar39));
      iVar15 = DAT_140e419b8;
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0xb;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 0x11;
      }
      else if (DAT_140e419b8 == 2) {
        iVar7 = 0x13;
      }
      else if (DAT_140e419b8 == 3) {
        iVar7 = 0x15;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 0x17;
      }
      local_res18 = 1;
      iVar7 = iVar7 + ((iVar13 + -0x50) / 100) * 2;
      if (DAT_140e419b8 == 0) {
        local_res18 = 300;
      }
      else if (DAT_140e419b8 == 1) {
        local_res18 = 0x168;
      }
      else if (DAT_140e419b8 == 2) {
        local_res18 = 0x1c2;
      }
      else if (DAT_140e419b8 == 3) {
        local_res18 = -0x226;
      }
      else if (DAT_140e419b8 == 4) {
        local_res18 = -0x280;
      }
      dVar34 = DAT_14053a0f8;
      if ((DAT_140e419b8 != 0) &&
         ((((DAT_140e419b8 == 1 || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
          (dVar34 = dVar3, DAT_140e419b8 == 4)))) {
        dVar34 = DAT_14053a138;
      }
      iVar24 = param_1[6];
      iVar14 = 0xb4;
      if (iVar24 != 0x84) {
        iVar14 = 0x50;
      }
      if ((iVar14 <= iVar13) && (iVar13 - iVar14 == ((iVar13 - iVar14) / 200) * 200)) {
        *(short *)((longlong)param_1 + 0x42) =
             (short)(0x10000 / (longlong)(iVar7 * 2)) + (short)(int)(dVar31 * dVar35);
      }
      iVar13 = param_1[3];
      if (((iVar14 <= iVar13) && (iVar13 < 0x1e0)) &&
         (uVar23 = (iVar13 - iVar14) % 200, (int)uVar23 < 0x50)) {
        uVar23 = uVar23 & 0x80000003;
        if ((int)uVar23 < 0) {
          uVar23 = (uVar23 - 1 | 0xfffffffc) + 1;
        }
        if (uVar23 == 0) {
          iVar16 = (iVar13 - iVar14) % 100;
          if (iVar24 == 0x83) {
            uVar20 = *(ushort *)((longlong)param_1 + 0x42);
            iVar13 = 0;
            if (iVar7 == 1) {
              uVar101 = uVar101 & 0xffffffff00000000;
              auVar92._12_4_ = auVar52._12_4_;
              auVar92._0_8_ = auVar52._0_8_;
              auVar92._8_4_ = 1;
              auVar52._8_8_ = auVar92._8_8_;
              auVar52._0_8_ = dVar34;
              fVar48 = (float)(uint)uVar20;
              uVar49 = uVar19;
              FUN_14006c2f0(0xc,1,0x83,(int)(dVar31 * dVar35),fVar48,uVar19,dVar34,auVar52._8_8_,
                            uVar101);
LAB_140030c7a:
              iVar24 = param_1[6];
            }
            else if (0 < iVar7) {
              do {
                uVar101 = 0;
                auVar91._12_4_ = auVar52._12_4_;
                auVar91._0_8_ = auVar52._0_8_;
                auVar91._8_4_ = 1;
                auVar52._8_8_ = auVar91._8_8_;
                auVar52._0_8_ = dVar34;
                fVar48 = (float)(uint)(ushort)((short)iVar13 * (short)(0x10000 / (longlong)iVar7) +
                                              uVar20);
                uVar49 = uVar19;
                FUN_14006c2f0(0xc,1);
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar7);
              goto LAB_140030c7a;
            }
            psVar22 = (short *)((longlong)param_1 + 0x42);
            if ((int)param_1[3] < iVar14 + 200) {
              if (iVar16 < 0x28) {
LAB_140030d3f:
                lVar21 = (longlong)local_res18;
                *psVar22 = *psVar22 +
                           (short)((ulonglong)(lVar21 * 0x55555556) >> 0x20) +
                           (short)((lVar21 / 3 + (lVar21 >> 0x3f) & 0xffffffffU) >> 0x1f);
                goto LAB_140030ca5;
              }
            }
            else if (0x27 < iVar16) goto LAB_140030d3f;
            *psVar22 = *psVar22 - (short)local_res18;
          }
LAB_140030ca5:
          if (iVar24 == 0x84) {
            uVar20 = *(ushort *)((longlong)param_1 + 0x42);
            if (iVar7 == 1) {
              uVar101 = 0;
              auVar94._12_4_ = auVar52._12_4_;
              auVar94._0_8_ = auVar52._0_8_;
              auVar94._8_4_ = 1;
              auVar52._8_8_ = auVar94._8_8_;
              auVar52._0_8_ = dVar34;
              fVar48 = (float)(uint)uVar20;
              uVar49 = uVar19;
              FUN_14006c2f0(0xd,1);
            }
            else {
              iVar13 = 0;
              if (0 < iVar7) {
                do {
                  uVar101 = 0;
                  auVar93._12_4_ = auVar52._12_4_;
                  auVar93._0_8_ = auVar52._0_8_;
                  auVar93._8_4_ = 1;
                  auVar52._8_8_ = auVar93._8_8_;
                  auVar52._0_8_ = dVar34;
                  fVar48 = (float)(uint)(ushort)((short)iVar13 * (short)(0x10000 / (longlong)iVar7)
                                                + uVar20);
                  uVar49 = uVar19;
                  FUN_14006c2f0(0xd,1);
                  iVar13 = iVar13 + 1;
                } while (iVar13 < iVar7);
              }
            }
            psVar22 = (short *)((longlong)param_1 + 0x42);
            if ((int)param_1[3] < iVar14 + 200) {
              if (iVar16 < 0x28) {
LAB_140030e58:
                local_res18 = (int)((ulonglong)((longlong)local_res18 * 0x55555555) >> 0x20) -
                              local_res18;
                *psVar22 = *psVar22 + ((short)(local_res18 >> 1) - (short)(local_res18 >> 0x1f));
                goto LAB_140030dac;
              }
            }
            else if (0x27 < iVar16) goto LAB_140030e58;
            *psVar22 = *psVar22 + (short)local_res18;
          }
LAB_140030dac:
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          puVar9 = DAT_140e45d80;
          iVar16 = DAT_140e44308;
          iVar15 = DAT_140e419b8;
        }
      }
    }
    if (0x1df < (int)param_1[3]) {
      dVar31 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),
                                     (double)(DAT_140e445d8 - fVar39));
      iVar13 = 1;
      if (iVar15 == 0) {
        iVar13 = 0x46;
      }
      else if (iVar15 == 1) {
        iVar13 = 0x32;
      }
      else if (iVar15 == 2) {
        iVar13 = 0x28;
      }
      else if (iVar15 == 3) {
        iVar13 = 0x1e;
      }
      else if (iVar15 == 4) {
        iVar13 = 0x18;
      }
      uVar46 = 1;
      if (((iVar15 == 0) || (iVar15 == 1)) || (iVar15 == 2)) {
LAB_140030ebb:
        uVar46 = 0xd;
      }
      else if (iVar15 == 3) {
        uVar46 = 0xb;
      }
      else if (iVar15 == 4) goto LAB_140030ebb;
      uVar23 = 1;
      if (iVar15 == 0) {
        uVar23 = 0xd;
      }
      else if (((iVar15 == 1) || (iVar15 == 2)) || (iVar15 == 3)) {
        uVar23 = 0xf;
      }
      else if (iVar15 == 4) {
        uVar23 = 0x11;
      }
      sVar10 = 1;
      if (iVar15 == 0) {
        sVar10 = 0x14;
      }
      else if (iVar15 == 1) {
        sVar10 = 0x1e;
      }
      else if (((iVar15 == 2) || (iVar15 == 3)) || (iVar15 == 4)) {
        sVar10 = 0x28;
      }
      dVar34 = DAT_140539fd8;
      if ((((iVar15 != 0) && (dVar34 = DAT_140539ff8, iVar15 != 1)) &&
          (dVar34 = DAT_14053a018, iVar15 != 2)) && ((iVar15 != 3 && (dVar34 = dVar3, iVar15 == 4)))
         ) {
        dVar34 = DAT_14053a070;
      }
      dVar38 = DAT_140539fd8;
      if (((iVar15 != 0) && (dVar38 = DAT_14053a000, iVar15 != 1)) &&
         ((dVar38 = DAT_14053a030, iVar15 != 2 &&
          ((dVar38 = DAT_14053a048, iVar15 != 3 && (dVar38 = dVar3, iVar15 == 4)))))) {
        dVar38 = DAT_14053a090;
      }
      if ((param_1[6] == 0x83) && (iVar15 = param_1[3], (iVar15 + -0x1e0) % (iVar13 * 2) == 0)) {
        auVar95._12_4_ = auVar52._12_4_;
        auVar95._0_8_ = auVar52._0_8_;
        auVar95._8_4_ = 1;
        auVar96._8_8_ = auVar95._8_8_;
        auVar96._0_8_ = dVar34;
        FUN_1400709b0(0x13,0x26,uVar46,iVar15,(short)iVar15 * sVar10,0,dVar34,auVar96._8_8_,uVar46,
                      0x10000,0);
        uVar103 = 0;
        uVar102 = 0x10000;
        uVar101 = (ulonglong)uVar23;
        auVar97._12_4_ = auVar96._12_4_;
        auVar97._0_8_ = auVar96._0_8_;
        auVar97._8_4_ = 1;
        auVar52._8_8_ = auVar97._8_8_;
        auVar52._0_8_ = dVar38;
        fVar48 = (float)((int)(dVar31 * dVar35) & 0xffff);
        uVar49 = uVar19;
        FUN_1400709b0(2,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        puVar9 = DAT_140e45d80;
        iVar16 = DAT_140e44308;
      }
      if (param_1[6] == 0x84) {
        if ((iVar13 + 0x1e0 <= (int)param_1[3]) &&
           ((param_1[3] - (iVar13 + 0x1e0)) % (iVar13 * 2) == 0)) {
          auVar98._12_4_ = auVar52._12_4_;
          auVar98._0_8_ = auVar52._0_8_;
          auVar98._8_4_ = 1;
          auVar99._8_8_ = auVar98._8_8_;
          auVar99._0_8_ = dVar34;
          FUN_1400709b0(0x14);
          uVar103 = 0;
          uVar102 = 0x10000;
          uVar101 = (ulonglong)uVar23;
          auVar100._12_4_ = auVar99._12_4_;
          auVar100._0_8_ = auVar99._0_8_;
          auVar100._8_4_ = 1;
          auVar52._8_8_ = auVar100._8_8_;
          auVar52._0_8_ = dVar38;
          fVar48 = (float)(uint)(ushort)((short)(0x10000 / (ulonglong)(uVar23 * 2)) +
                                        (short)(int)(dVar31 * dVar35));
          FUN_1400709b0(3,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          puVar9 = DAT_140e45d80;
          iVar16 = DAT_140e44308;
          uVar49 = uVar19;
        }
      }
    }
    iVar15 = DAT_140e44e6c;
    iVar13 = param_1[7];
    if ((iVar13 < uStack_138._4_4_) && (puVar8 = puVar9, 0 < DAT_140e44e6c)) {
      for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)puVar8[0xc]) {
        if (*(int *)((longlong)puVar8 + 4) == iVar16) {
          *(int *)((longlong)puVar8 + 0x1c) =
               *(int *)((longlong)puVar8 + 0x1c) - (uStack_138._4_4_ - iVar13);
        }
      }
    }
    iVar13 = param_1[7];
    if (uStack_138._4_4_ < iVar13) {
      param_1[7] = uStack_138._4_4_;
      iVar13 = uStack_138._4_4_;
    }
    fVar40 = DAT_14053af14;
    if ((iVar13 < 1) && (0 < iVar15)) {
      for (; fVar40 = DAT_14053af14, puVar9 != (undefined8 *)0x0; puVar9 = (undefined8 *)puVar9[0xc]
          ) {
        if (*(int *)((longlong)puVar9 + 4) == iVar16) {
          *(int *)((longlong)puVar9 + 0x1c) = *(int *)((longlong)puVar9 + 0x1c) - uStack_138._4_4_;
        }
      }
    }
    break;
  case 0x46:
    iVar16 = 0xf0;
    if (iVar15 != 0x84) {
      iVar16 = 0xdc;
    }
    if (uStack_148._4_4_ == 1) {
      param_1[0x15] = 1;
    }
    if ((int)uStack_148._4_4_ < iVar16) {
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      if (param_1[6] == 0x83) {
        uVar49 = 0x59;
        fVar48 = 1.23314e-43;
        local_res10 = FUN_1400c9580(param_1[3],0,5,2,0x58,0x59);
      }
      if (param_1[6] == 0x84) {
        uVar49 = 99;
        fVar48 = 1.37327e-43;
        local_res10 = FUN_1400c9580(param_1[3],0,5,2,0x62,99);
      }
    }
    puVar9 = DAT_140e45d28;
    if (param_1[3] == iVar16) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar46 = param_1[0xb];
      uVar47 = param_1[10];
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar30 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar9 + 0x14) = uVar47;
        *(undefined4 *)(puVar9 + 3) = uVar46;
        *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar47;
        *(undefined4 *)(puVar9 + 4) = uVar46;
        *puVar9 = 1;
        puVar9[1] = 0x10;
        *(undefined4 *)(puVar9 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        puVar9[6] = 0x3ff0000000000000;
        puVar9[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar9 + 8) = 0;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        puVar9[10] = 0xff;
        puVar9[0xb] = 0;
        if (bVar30) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
    }
    DAT_140e45d28 = puVar9;
    if ((int)local_150 == 0) {
      *param_1 = 0;
    }
    goto LAB_14002fb02;
  }
LAB_14002fb02:
  fVar39 = DAT_14053ad10;
  uVar47 = (undefined4)((ulonglong)dVar3 >> 0x20);
  uVar46 = SUB84(dVar3,0);
  iVar16 = 0xdc;
  FUN_140332d90();
  lVar21 = 0x71;
  lVar29 = 0x8d;
  lVar27 = 0x71;
  if (param_1[6] == 0x84) {
    FUN_140332d90();
    iVar16 = 0xf0;
    lVar21 = 0x72;
    local_160 = 0xf0;
    lVar29 = 0x8e;
    lVar27 = 0x72;
  }
  dVar31 = DAT_14053a6d8;
  uVar19 = param_1[5];
  if (uVar19 == 10) {
    uVar23 = param_1[3];
    if (uVar23 - 0xaa < 0x28) {
      dVar34 = (double)FUN_140332d90(((double)(int)uVar23 - _DAT_14053a4c8) * DAT_14053a6d8 *
                                     (double)CONCAT44(uVar45,uVar44) *
                                     (double)CONCAT44(uVar43,uVar42));
      fVar40 = (float)(dVar34 * _DAT_14053a7d8) + fVar39;
LAB_14002fc01:
      fVar39 = fVar40;
      if (199 < (int)uVar23) goto LAB_14002fc1a;
    }
    else {
      if ((int)uVar23 < 0xd2) goto LAB_14002fc01;
LAB_14002fc1a:
      fVar40 = fVar39;
      if (uVar23 < 0xf0) {
        FUN_140332d90(((double)(int)uVar23 - DAT_14053a528) * dVar31 *
                      (double)CONCAT44(uVar45,uVar44) * (double)CONCAT44(uVar43,uVar42));
      }
    }
    fVar40 = (float)dVar3 * fVar40;
    iVar16 = local_160;
LAB_140031770:
    if (0x45 < uVar19) goto LAB_140031775;
  }
  else {
    fVar40 = fVar39 * (float)dVar3;
    if (9 < (int)uVar19) goto LAB_140031770;
LAB_140031775:
    if ((uVar19 != 0x46) || (iVar16 <= (int)param_1[3])) goto LAB_140031b67;
  }
  FUN_1403307c0();
  FUN_140332d90();
  FUN_1400c8410((&DAT_140e44ad8)[lVar29],0x19,7);
  FUN_1400c8410((&DAT_140e44ad0)[lVar29],0x19,7);
  if (param_1[6] == 0x83) {
    FUN_1400c8410(DAT_140e447a4,0x19,8);
  }
  if (param_1[6] == 0x84) {
    FUN_1400c8410(DAT_140e447a4,0x19,8);
  }
  uVar106 = 0;
  uVar105 = 1;
  uVar104 = 0xff;
  uVar103 = 0xff;
  uVar102 = 0xff;
  uVar101 = 0xff;
  auVar52._8_4_ = uVar46;
  auVar52._0_8_ = dVar3;
  auVar52._12_4_ = uVar47;
  FUN_1400c8410((&DAT_140e44668)[lVar27],0x1a,7);
  fVar39 = DAT_14053acb4;
  iVar13 = 0;
  fVar41 = (float)dVar3 * DAT_14053acf0;
  fVar36 = (float)dVar3 * DAT_14053ac5c;
  do {
    iVar16 = (DAT_140e418c8 & 0xffff) * 0x14d;
    uVar20 = (short)iVar13 * 0x13b1 + (short)iVar16;
    FUN_140133f30(iVar16,fVar40 + (float)param_1[0xb] + fVar39,0,uVar20,fVar36,fVar41,auVar52,
                  uVar101,uVar102,uVar103,uVar104,uVar105,uVar106);
    uVar106 = 0;
    uVar105 = 1;
    uVar104 = 0xff;
    uVar103 = 0xff;
    uVar102 = 0xff;
    uVar101 = 0xff;
    uVar49 = 0;
    fVar48 = extraout_var;
    FUN_1400c8410((&DAT_140e44660)[lVar21],(uVar20 < 0x8000) + '\x18');
    iVar13 = iVar13 + 1;
    iVar16 = local_160;
  } while (iVar13 < 0xd);
LAB_140031b67:
  if ((param_1[5] != 0x46) || ((int)param_1[3] < iVar16)) {
    fVar48 = (float)param_1[0xb];
    uVar106 = 0;
    uVar105 = 1;
    uVar104 = 0xff;
    uVar103 = 0xff;
    uVar102 = 0xff;
    uVar101 = 0xff;
    auVar52._8_4_ = uVar46;
    auVar52._0_8_ = dVar3;
    auVar52._12_4_ = uVar47;
    uVar49 = 0;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10 * 4),0x19,7);
  }
  if (param_1[0x15] == 0) {
    if (param_1[5] - 0xb < 9) {
      fVar48 = DAT_14053b370;
      FUN_140079c10(param_1,1);
    }
    if (((param_1[0x15] == 0) && (DAT_140e445fc - 0xb4U < 0x50)) && (DAT_140e445fc % 5 == 4)) {
      uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      FUN_1403307c0(uVar19,(ulonglong)DAT_140e9fd1c * 0xecf56bf >> 0x20,DAT_140e9fd14,DAT_140e9fd18,
                    fVar48,uVar49,auVar52,uVar101,uVar102,uVar103,uVar104,uVar105,uVar106);
      FUN_140332d90();
      if ((param_1[6] - 0x13f < 2) || (param_1[6] - 0x146 < 6)) {
        uVar25 = 0x2d;
        uVar17 = 0x35;
        uVar42 = DAT_140e41a98;
      }
      else {
        FUN_140070d00(0x35,DAT_140e41a40,0x2d);
        uVar102 = param_1[3] * 0x22b8 + DAT_140e418c8;
        uVar102 = (uVar102 >> 0x1e ^ uVar102) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar102 >> 0x1e ^ uVar102) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar102 = uVar102 * 0x800 ^ uVar102;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar102) >> 8 ^ DAT_140e9fd18 ^ uVar102;
        uVar17 = 0x17;
        uVar25 = 0x2e;
        uVar42 = DAT_140e41964;
      }
      FUN_140070d00(uVar17,uVar42,uVar25);
    }
  }
  return;
}


