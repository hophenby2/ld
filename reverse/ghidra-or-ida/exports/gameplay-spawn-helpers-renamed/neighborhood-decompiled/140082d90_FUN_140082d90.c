// Function: FUN_140082d90 @ 140082d90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140082d90(undefined4 *param_1)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  ushort uVar4;
  short sVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  double dVar9;
  double dVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  ushort uVar20;
  ushort uVar21;
  int iVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  float fVar30;
  double dVar31;
  float fVar32;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined8 in_stack_fffffffffffffee8;
  ulonglong uVar33;
  uint in_stack_fffffffffffffef0;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  
  uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  iVar22 = 0;
  iVar16 = DAT_140e419b8;
  if (param_1[5] != 0) goto LAB_14008312f;
  uVar13 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
  local_res8 = (undefined4)uVar13;
  dVar31 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
  uStackX_c = (undefined4)((ulonglong)uVar13 >> 0x20);
  in_stack_fffffffffffffef8._8_4_ = SUB84(dVar31,0);
  in_stack_fffffffffffffef8._0_8_ = dVar31;
  in_stack_fffffffffffffef8._12_4_ = (int)((ulonglong)dVar31 >> 0x20);
  uVar33 = CONCAT44(uVar18,uStackX_c);
  FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uVar33,in_stack_fffffffffffffef0 & 0xffff0000,
                in_stack_fffffffffffffef8,0xff,0xff,0xff,0xff,1,0);
  iVar16 = DAT_140e419b8;
  if (param_1[3] != 0x14) goto LAB_14008312f;
  *(undefined8 *)(param_1 + 0x12) = 0x4018000000000000;
  iVar16 = DAT_140e419b8;
  if (param_1[6] == 6) {
    uVar18 = DAT_140e445c0;
    if (DAT_140e41928 == 0) goto LAB_140082ec8;
LAB_140082ff7:
    puVar14 = param_1 + 3;
    if ((DAT_140e41928 == 1) &&
       (iVar17 = FUN_140135290(DAT_140e41abc + 0xb,uVar18,iVar16), iVar19 = iVar22, 0 < iVar17)) {
      do {
        uVar12 = (DAT_140e418c8 + iVar19 >> 0x1e ^ DAT_140e418c8 + iVar19) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar12 = uVar12 * 0x800 ^ uVar12;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
        auVar35._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar35._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar35._8_4_ = 0x28;
        auVar8._8_8_ = 0;
        auVar8._0_8_ = auVar35._8_8_;
        in_stack_fffffffffffffef8 = auVar8 << 0x40;
        uVar33 = uVar33 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (9,3000,0,0,uVar33,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001),0,
                   auVar35._8_8_,1,param_1[1]);
        iVar16 = DAT_140e419b8;
        iVar19 = iVar19 + 1;
        iVar17 = FUN_140135290(DAT_140e41abc + 0xb,DAT_140e445c0,DAT_140e419b8);
      } while (iVar19 < iVar17);
      puVar14 = param_1 + 3;
    }
  }
  else {
    if ((DAT_140e41928 != 0) || (param_1[6] != 7)) {
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
      goto LAB_14008312f;
    }
LAB_140082ec8:
    puVar14 = param_1 + 3;
    iVar17 = FUN_140135290(DAT_1407c7798,DAT_140e445c0,DAT_140e419b8);
    iVar19 = iVar22;
    if (0 < iVar17) {
      do {
        uVar12 = (DAT_140e418c8 + iVar19 >> 0x1e ^ DAT_140e418c8 + iVar19) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar12 = uVar12 * 0x800 ^ uVar12;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
        auVar34._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar34._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar34._8_4_ = 0x28;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = auVar34._8_8_;
        in_stack_fffffffffffffef8 = auVar7 << 0x40;
        uVar33 = uVar33 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (9,3000,0,0,uVar33,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001),0,
                   auVar34._8_8_,1,param_1[1]);
        uVar18 = DAT_140e445c0;
        iVar16 = DAT_140e419b8;
        iVar19 = iVar19 + 1;
        iVar17 = FUN_140135290(DAT_1407c7798,DAT_140e445c0,DAT_140e419b8);
      } while (iVar19 < iVar17);
      goto LAB_140082ff7;
    }
  }
  param_1[5] = param_1[5] + 1;
  param_1[0x15] = 0;
  *puVar14 = 0;
LAB_14008312f:
  fVar2 = DAT_14053acf0;
  if (param_1[5] == 1) {
    fVar30 = (float)param_1[0xb];
    fVar32 = (float)param_1[10];
    dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar30 + DAT_14053acf0)),
                                   SUB84((double)(DAT_140e445d8 - fVar32),0));
    dVar10 = DAT_14053a020;
    dVar24 = dVar24 * DAT_14053aba0;
    uVar12 = param_1[3];
    dVar25 = (double)FUN_140332d90(((double)(int)uVar12 - 0.0) * _DAT_14053a850 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar9 = DAT_140539f40;
    dVar31 = *(double *)(param_1 + 0x12);
    dVar25 = dVar25 * DAT_140539e60 + DAT_140539f40;
    if ((uVar12 < 0x79) && (DAT_140539f40 < dVar31)) {
      dVar31 = dVar31 - DAT_140539e60;
    }
    *(double *)(param_1 + 0x12) = dVar31;
    dVar26 = (double)FUN_1403307c0();
    fVar32 = (float)(dVar26 * dVar31) + fVar32;
    param_1[10] = fVar32;
    dVar26 = (double)FUN_140332d90();
    iVar19 = 1;
    fVar30 = (float)(dVar26 * dVar31) + fVar30;
    param_1[0xb] = fVar30;
    if (iVar16 == 0) {
      iVar19 = 0x28;
    }
    else if ((((iVar16 == 1) || (iVar16 == 2)) || (iVar16 == 3)) || (iVar16 == 4)) {
      iVar19 = 0x1e;
    }
    iVar17 = 1;
    if (iVar16 == 0) {
      iVar17 = 100;
    }
    else if (iVar16 == 1) {
      iVar17 = 0x50;
    }
    else if ((iVar16 == 2) || (iVar16 == 3)) {
      iVar17 = 0x3c;
    }
    else if (iVar16 == 4) {
      iVar17 = 0x32;
    }
    uVar18 = 1;
    if (iVar16 != 0) {
      if (iVar16 == 1) {
        uVar18 = 3;
      }
      else if ((iVar16 == 2) || (iVar16 == 3)) {
        uVar18 = 5;
      }
      else if (iVar16 == 4) {
        uVar18 = 7;
      }
    }
    dVar31 = DAT_14053a070;
    if ((((iVar16 != 0) && (dVar31 = DAT_14053a0f8, iVar16 != 1)) &&
        (dVar31 = DAT_14053a178, iVar16 != 2)) &&
       ((dVar31 = DAT_14053a1c8, iVar16 != 3 && (dVar31 = dVar9, iVar16 == 4)))) {
      dVar31 = DAT_14053a208;
    }
    iVar16 = (int)(uVar12 - iVar19) % iVar17;
    uVar21 = (ushort)(int)dVar24;
    if (iVar16 == 0) {
      *(ushort *)(param_1 + 0x11) = uVar21;
    }
    uVar4 = *(ushort *)(param_1 + 0x11);
    iVar15 = ((int)dVar24 & 0xffffU) - (uint)uVar4;
    iVar11 = iVar15 + 0x10000;
    if (-0x8001 < iVar15) {
      iVar11 = iVar15;
    }
    iVar15 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar15 = iVar11;
    }
    if (iVar15 < 1) {
      uVar20 = uVar4;
      if ((iVar15 < 0) && (uVar20 = uVar4 - 0x14, -0x14 < iVar15)) {
        uVar20 = uVar21;
      }
    }
    else {
      uVar20 = uVar21;
      if (0x13 < iVar15) {
        uVar20 = uVar4 + 0x14;
      }
    }
    iVar11 = param_1[3];
    *(ushort *)(param_1 + 0x11) = uVar20;
    if ((((iVar19 <= iVar11) && (iVar11 < 0xf0)) && ((iVar11 - iVar19) % iVar17 < 0x1e)) &&
       (iVar17 = (iVar11 - iVar19) % iVar17, iVar17 == (iVar17 / 5) * 5)) {
      auVar36._12_4_ = in_stack_fffffffffffffef8._12_4_;
      auVar36._0_8_ = in_stack_fffffffffffffef8._0_8_;
      auVar36._8_4_ = 1;
      dVar26 = (double)iVar16 * _DAT_140539e28;
      dVar24 = dVar26 + dVar31;
      auVar37._8_8_ = auVar36._8_8_;
      auVar37._0_8_ = dVar24;
      FUN_1400709b0(0,0,fVar32,fVar30 + fVar2,uVar20,0,dVar24,auVar37._8_8_,uVar18,20000,0);
      if (2 < DAT_140e419b8) {
        auVar38._12_4_ = auVar37._12_4_;
        auVar38._0_8_ = auVar37._0_8_;
        auVar38._8_4_ = 1;
        FUN_1400709b0(0,0,param_1[10],(float)param_1[0xb] + fVar2,*(undefined2 *)(param_1 + 0x11),0,
                      (dVar31 - DAT_140539fc8) + dVar26,auVar38._8_8_,uVar18,20000,0);
      }
    }
    uVar1 = DAT_140e44af8;
    fVar2 = DAT_14053acfc;
    sVar5 = *(short *)(param_1 + 3);
    uVar18 = param_1[10];
    fVar30 = (float)param_1[0xb] + DAT_14053acfc;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar14[3] = uVar18;
    *(undefined8 *)(puVar14 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    puVar14[4] = fVar30;
    *puVar14 = uVar1;
    puVar14[1] = 0x26;
    puVar14[2] = 7;
    *(short *)(puVar14 + 5) = sVar5 * 0x6f1;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = 0xff;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    _DAT_140e46d28 = _DAT_140e46d28 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar14;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
    }
    uVar1 = DAT_140e44af8;
    sVar5 = *(short *)(param_1 + 3);
    fVar30 = (float)param_1[0xb];
    uVar18 = param_1[10];
    DAT_140e46c88 = puVar14;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar14 = uVar1;
    puVar14[1] = 0x26;
    puVar14[2] = 7;
    puVar14[3] = uVar18;
    puVar14[4] = fVar30 + fVar2;
    *(short *)(puVar14 + 5) = sVar5 * 0x6f1 + 0x5555;
    *(undefined8 *)(puVar14 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = 0xff;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    _DAT_140e46d28 = _DAT_140e46d28 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar14;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
    }
    uVar1 = DAT_140e44af8;
    sVar5 = *(short *)(param_1 + 3);
    fVar30 = (float)param_1[0xb];
    uVar18 = param_1[10];
    DAT_140e46c88 = puVar14;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar14 = uVar1;
    puVar14[1] = 0x26;
    puVar14[2] = 7;
    puVar14[3] = uVar18;
    puVar14[4] = fVar30 + fVar2;
    *(short *)(puVar14 + 5) = sVar5 * 0x6f1 + -0x5556;
    *(undefined8 *)(puVar14 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = 0xff;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    _DAT_140e46d28 = _DAT_140e46d28 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar14;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
    }
    uVar3 = DAT_140e44af4;
    uVar18 = param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar14;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46d28 = _DAT_140e46d28 + 1;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar14[3] = uVar1;
    puVar14[4] = uVar18;
    *(double *)(puVar14 + 6) = dVar25;
    *puVar14 = uVar3;
    puVar14[1] = 0x26;
    puVar14[2] = 7;
    *(undefined2 *)(puVar14 + 5) = 0;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = 0xff;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar14;
    }
    dVar31 = DAT_14053aa88;
    dVar24 = DAT_140539d28;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
      dVar31 = DAT_14053aa88;
      dVar24 = DAT_140539d28;
    }
    do {
      DAT_140e46c88 = puVar14;
      iVar16 = param_1[1];
      uVar12 = iVar16 + 0x4d + iVar22;
      uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar12 = uVar12 * 0x800 ^ uVar12;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
      dVar27 = (double)FUN_140134db0(iVar16 + 0x309 + iVar22,(int)DAT_14053a240,DAT_14053a2f0);
      dVar28 = (double)FUN_1403307c0();
      fVar2 = (float)param_1[10];
      dVar29 = (double)FUN_140332d90();
      fVar30 = (float)param_1[0xb] - DAT_14053ac60;
      dVar26 = dVar9;
      if ((int)param_1[3] % 0x3c < 0xb) {
        dVar26 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * dVar31 * dVar10 * dVar24);
        dVar26 = dVar26 * DAT_140539e60 + dVar9;
      }
      uVar18 = DAT_140e45d64;
      uVar12 = iVar16 + 0x1e61 + iVar22;
      uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar12 = uVar12 * 0x800 ^ uVar12;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
      uVar33 = (ulonglong)DAT_140e9fd1c;
      sVar5 = (short)DAT_140e9fd1c;
      puVar14 = (undefined4 *)_malloc_base(0x48);
      if (puVar14 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar14[3] = (float)(dVar28 * (double)(float)(dVar27 * dVar25)) + fVar2;
      puVar14[4] = (float)(dVar29 * (double)(float)(dVar27 * dVar25)) + fVar30;
      *puVar14 = uVar18;
      puVar14[1] = 0x26;
      puVar14[2] = 7;
      *(short *)(puVar14 + 5) = sVar5 - (short)(uVar33 / 0x10001);
      auVar6._8_4_ = SUB84(dVar26,0);
      auVar6._0_8_ = dVar26;
      auVar6._12_4_ = (int)((ulonglong)dVar26 >> 0x20);
      *(undefined1 (*) [16])(puVar14 + 6) = auVar6;
      puVar14[10] = 0xff;
      puVar14[0xb] = 0xff;
      puVar14[0xc] = 0xff;
      puVar14[0xd] = 0xff;
      *(undefined8 *)(puVar14 + 0xe) = 1;
      *(undefined8 *)(puVar14 + 0x10) = 0;
      _DAT_140e46d28 = _DAT_140e46d28 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar14;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
      }
      uVar18 = DAT_140e44af0;
      iVar22 = iVar22 + 1;
    } while (iVar22 < 0x10);
    uVar1 = param_1[0xb];
    uVar3 = param_1[10];
    DAT_140e46c88 = puVar14;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46d28 = _DAT_140e46d28 + 1;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar14[3] = uVar3;
    puVar14[4] = uVar1;
    *(double *)(puVar14 + 6) = dVar25;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    *puVar14 = uVar18;
    puVar14[1] = 0x26;
    puVar14[2] = 7;
    *(undefined2 *)(puVar14 + 5) = 0;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = 0xff;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar14;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
    }
    DAT_140e46c88 = puVar14;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_140079e20(param_1,1);
    FUN_14007b010(param_1,500,0xc);
    uVar12 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    FUN_1400ca6d0(6,param_1[10],param_1[0xb],
                  CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                           (short)DAT_140e9fd1c +
                           (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                  DAT_14053a070,DAT_14053ac80);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
      (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b398 || (_DAT_14053af5c < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


