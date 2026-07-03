// Function: FUN_1400210c0 @ 1400210c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400210c0(undefined4 *param_1)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  undefined1 auVar4 [16];
  double dVar5;
  double dVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  short sVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  float fVar21;
  double dVar22;
  undefined4 uVar23;
  int local_res8;
  undefined2 uVar25;
  undefined4 uVar24;
  float fVar26;
  undefined1 in_stack_fffffffffffffe78 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar33 [12];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  int iStack_12c;
  undefined4 local_128;
  float fStack_120;
  float fStack_11c;
  
  dVar3 = DAT_140539f40;
  iVar12 = 0;
  iStack_12c = 0;
  iVar11 = 0;
  lVar1 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_12c = iVar11, lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        iStack_12c = *(int *)(lVar1 + 0x1c);
        local_128 = *(undefined4 *)(lVar1 + 0x20);
        fStack_120 = *(float *)(lVar1 + 0x28);
        fStack_11c = *(float *)(lVar1 + 0x2c);
      }
      iVar11 = iStack_12c;
    }
  }
  auVar27._4_12_ = in_stack_fffffffffffffe78._4_12_;
  auVar27._0_4_ = 0x34;
  fVar26 = 0.0;
  uVar24 = 0;
  local_res8 = FUN_1400c9580(param_1[3],0,7,3,0x32,0x33,auVar27);
  dVar6 = DAT_14053a020;
  dVar5 = DAT_140539d28;
  iVar11 = param_1[3];
  dVar22 = (double)iVar11 - 0.0;
  dVar2 = (double)FUN_140332d90(SUB84(dVar22 * _DAT_14053a5e0 * DAT_14053a020 * DAT_140539d28,0));
  iVar10 = (iVar11 >> 0x1f & 0x3cU) - 0x3c;
  fVar19 = (float)(dVar2 * DAT_14053a598) + _DAT_140539cbc;
  param_1[0xc] = fVar19;
  if ((-1 < iVar11) && (iVar11 < 0xac)) {
    dVar2 = (double)FUN_140332d90(SUB84(dVar22 * _DAT_14053a448 * dVar6 * dVar5,0));
    iVar10 = (int)(dVar2 * _DAT_14053b158);
  }
  dVar2 = (double)FUN_140332d90(SUB84(dVar22 * _DAT_14053a520 * dVar6 * dVar5,0));
  fVar18 = (float)param_1[10];
  fVar19 = fVar19 + fStack_120;
  fVar21 = (float)(dVar2 * DAT_14053b188) + (float)iVar10;
  param_1[0xd] = fVar21;
  fVar21 = fVar21 + fStack_11c;
  dVar2 = (double)FUN_1403300b4(SUB84((double)(fVar21 - (float)param_1[0xb]),0),
                                SUB84((double)(fVar19 - fVar18),0));
  uVar23 = SUB84((double)((int)(dVar2 * DAT_14053aba0) & 0xffff) * dVar6 * dVar5,0);
  fVar18 = (float)FUN_140334430(fVar18 - fVar19,DAT_140539fc0);
  fVar19 = (float)FUN_140334430((float)param_1[0xb] - fVar21);
  fVar18 = fVar18 + fVar19;
  if (fVar18 < 0.0) {
    fVar18 = (float)FUN_1403352f8(fVar18);
  }
  else {
    fVar18 = SQRT(fVar18);
  }
  dVar20 = (double)fVar18 / DAT_14053a2d8;
  dVar2 = (double)FUN_1403307c0(uVar23);
  fVar19 = (float)(dVar2 * dVar20) + (float)param_1[10];
  param_1[10] = fVar19;
  dVar2 = (double)FUN_140332d90(uVar23);
  fVar18 = (float)(dVar2 * dVar20) + (float)param_1[0xb];
  param_1[0xb] = fVar18;
  if (param_1[5] == 0) {
    if (iVar11 == 0) {
      fVar19 = fStack_11c + DAT_14053ac80;
      param_1[10] = fStack_120 + DAT_14053aa20;
      param_1[0xb] = fVar19;
    }
    else {
      dVar2 = DAT_140539ef8;
      if (iVar11 < 0) goto LAB_140021bc1;
      if (0x3b < iVar11) {
        dVar2 = dVar3;
        if (iVar11 != 0xac) goto LAB_140021bc1;
        param_1[8] = local_128;
        param_1[7] = iStack_12c;
        param_1[0x15] = 0;
        param_1[5] = 1;
        goto LAB_140021433;
      }
    }
    dVar3 = (double)FUN_140332d90(SUB84(dVar22 * DAT_14053a628 * dVar6 * dVar5,0));
    dVar2 = dVar3 * DAT_140539f10 + DAT_140539ef8;
    goto LAB_140021bc1;
  }
  dVar2 = dVar3;
  if (param_1[5] != 1) goto LAB_140021bc1;
LAB_140021433:
  fVar21 = DAT_14053ac2c;
  fVar18 = fVar18 + DAT_14053ac2c;
  iVar10 = (iVar11 + -0xac) % 700;
  dVar2 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar18),0),
                                SUB84((double)(DAT_140e445d8 - fVar19),0));
  iVar11 = DAT_140e419b8;
  dVar6 = DAT_14053a0f8;
  dVar5 = DAT_14053a0b0;
  uVar25 = (undefined2)((uint)uVar24 >> 0x10);
  iVar15 = 1;
  if (DAT_140e419b8 == 0) {
    iVar15 = 10;
  }
  else if (DAT_140e419b8 == 1) {
    iVar15 = 6;
  }
  else if (DAT_140e419b8 == 2) {
LAB_1400214db:
    iVar15 = 3;
  }
  else if (DAT_140e419b8 == 3) {
    iVar15 = 4;
  }
  else if (DAT_140e419b8 == 4) goto LAB_1400214db;
  iVar13 = 1;
  if (DAT_140e419b8 == 0) {
    iVar13 = 0x53;
  }
  else if (DAT_140e419b8 == 1) {
    iVar13 = 0x33;
  }
  else if (DAT_140e419b8 == 2) {
LAB_14002151b:
    iVar13 = 0x21;
  }
  else if (DAT_140e419b8 == 3) {
    iVar13 = 0x2d;
  }
  else if (DAT_140e419b8 == 4) goto LAB_14002151b;
  dVar22 = DAT_14053a048;
  if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a088, DAT_140e419b8 != 1)) &&
      (dVar22 = DAT_14053a0b0, DAT_140e419b8 != 2)) &&
     ((dVar22 = DAT_14053a070, DAT_140e419b8 != 3 && (dVar22 = dVar3, DAT_140e419b8 == 4)))) {
    dVar22 = DAT_14053a0f8;
  }
  dVar22 = ((double)iVar10 - DAT_14053a4a0) * _DAT_140539d98 + dVar22;
  sVar16 = (short)(int)(dVar2 * DAT_14053aba0);
  if ((iVar10 - 0x78U < 0x168) && ((iVar10 + -0x78) % iVar13 == 0)) {
    *(short *)((longlong)param_1 + 0x42) = sVar16;
LAB_1400215e2:
    if ((iVar10 + -0x78) % iVar15 == 0) {
      iVar13 = iVar13 * 2;
      lVar1 = (longlong)(iVar10 + -0x78) % (longlong)iVar13;
      sVar9 = (short)lVar1;
      if (iVar13 >> 1 <= (int)lVar1) {
        sVar9 = (short)iVar13 - sVar9;
      }
      sVar9 = (short)(0x8000 / (ulonglong)(longlong)(iVar13 >> 1)) * sVar9 +
              *(short *)((longlong)param_1 + 0x42);
      iVar11 = iVar12;
      do {
        auVar28._12_4_ = auVar27._12_4_;
        auVar28._0_8_ = auVar27._0_8_;
        auVar28._8_4_ = 1;
        auVar27._8_8_ = auVar28._8_8_;
        auVar27._0_8_ = dVar22;
        uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),(short)iVar11 * 400 + sVar9 + -0x4190);
        fVar26 = fVar21;
        FUN_14006c2f0(0xd,0,fVar19,fVar18,uVar24,fVar21,dVar22,auVar27._8_8_,0);
        uVar25 = (undefined2)((uint)uVar24 >> 0x10);
        iVar11 = iVar11 + 1;
      } while (iVar11 < 3);
      if (2 < DAT_140e419b8) {
        do {
          auVar29._12_4_ = auVar27._12_4_;
          auVar29._0_8_ = auVar27._0_8_;
          auVar29._8_4_ = 1;
          auVar27._8_8_ = auVar29._8_8_;
          auVar27._0_8_ = dVar22 + dVar3;
          uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),(short)iVar12 * 400 + sVar9 + -0x3d39);
          fVar26 = fVar21;
          FUN_14006c2f0(0xd,0,fVar19,fVar18,uVar24,fVar21,dVar22 + dVar3,auVar27._8_8_,0);
          uVar25 = (undefined2)((uint)uVar24 >> 0x10);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 3);
      }
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar11 = DAT_140e419b8;
    }
  }
  else if (iVar10 - 0x78U < 0x168) goto LAB_1400215e2;
  uVar24 = DAT_140e41a50;
  iVar12 = 1;
  if (iVar11 == 0) {
    iVar12 = 0x12;
  }
  else if (iVar11 == 1) {
    iVar12 = 9;
  }
  else if (iVar11 == 2) {
    iVar12 = 6;
  }
  else if (iVar11 == 3) {
    iVar12 = 4;
  }
  else if (iVar11 == 4) {
    iVar12 = 3;
  }
  iVar15 = 1;
  if (iVar11 == 0) {
    iVar15 = 0x28;
  }
  else if (iVar11 == 1) {
    iVar15 = 0x32;
  }
  else if (iVar11 == 2) {
    iVar15 = 0x37;
  }
  else if (iVar11 == 3) {
    iVar15 = 0x3c;
  }
  else if (iVar11 == 4) {
    iVar15 = 0x42;
  }
  if ((((iVar11 != 0) && (dVar5 = dVar6, iVar11 != 1)) && (dVar5 = DAT_14053a138, iVar11 != 2)) &&
     ((dVar5 = DAT_14053a178, iVar11 != 3 && (dVar5 = dVar3, iVar11 == 4)))) {
    dVar5 = DAT_14053a1b8;
  }
  if ((iVar10 == 0x1cc) || (iVar10 == 0x230)) {
    uVar23 = param_1[1];
    puVar7 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar24;
      bVar17 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar7 = 1;
      *(undefined4 *)(puVar7 + 1) = 0x31;
      puVar7[2] = 0x23;
      puVar7[3] = 0;
      *(undefined4 *)(puVar7 + 4) = 0;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0;
      puVar7[6] = 0x4014000000000000;
      puVar7[7] = 0x4014000000000000;
      *(undefined4 *)(puVar7 + 8) = 0x28;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      *(undefined4 *)(puVar7 + 10) = 0xc0;
      *(undefined4 *)((longlong)puVar7 + 0x54) = uVar23;
      puVar7[0xb] = 0;
      if (bVar17) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
    }
    DAT_140e45d28 = puVar7;
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
    FUN_14018a340(DAT_140e472c0,1,1);
  }
  auVar33 = auVar27._4_12_;
  if ((((499 < iVar10) && (iVar10 < iVar15 + 500)) && ((iVar10 + -500) % iVar12 == 0)) ||
     (((599 < iVar10 && (iVar10 < iVar15 + 600)) && ((iVar10 + -600) % iVar12 == 0)))) {
    auVar30._12_4_ = auVar27._12_4_;
    auVar30._0_8_ = auVar27._0_8_;
    auVar30._8_4_ = 1;
    auVar31._8_8_ = auVar30._8_8_;
    auVar31._0_8_ = dVar5;
    fVar26 = 0.0;
    uVar14 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar14 = uVar14 * 0x800 ^ uVar14;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
    FUN_14006c2f0(0x11,0xc,fVar19,fVar18,
                  CONCAT22(uVar25,(short)(DAT_140e9fd1c / 0x9c41) * 0x63bf + (short)DAT_140e9fd1c +
                                  sVar16 + -20000),0,dVar5,auVar31._8_8_,0);
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
    FUN_14018a340(DAT_140e472a8,1,1);
    auVar33 = auVar31._4_12_;
  }
  if (iVar10 - 0x78U < 10) {
    fVar26 = 7.56701e-44;
    uVar8 = 0x78;
    uVar24 = 0x35;
LAB_140021b06:
    local_res8 = FUN_1400c9580(iVar10,uVar8,5,2,uVar24,fVar26);
  }
  else if (iVar10 - 0x82U < 0x231) {
    auVar32._4_12_ = auVar33;
    auVar32._0_4_ = 0x39;
    fVar26 = 0.0;
    local_res8 = FUN_1400c9580(iVar10,0x82,5,3,0x37,0x38,auVar32);
  }
  else if (iVar10 - 0x2b3U < 10) {
    fVar26 = 7.42688e-44;
    uVar8 = 0x2b3;
    uVar24 = 0x36;
    goto LAB_140021b06;
  }
  iVar11 = param_1[7];
  if (iVar11 < iStack_12c) {
    iVar12 = param_1[2];
    lVar1 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
        if (*(int *)(lVar1 + 4) == iVar12) {
          *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) - (iStack_12c - iVar11);
        }
      }
    }
  }
  iVar11 = param_1[7];
  if (iStack_12c < iVar11) {
    param_1[7] = iStack_12c;
    iVar11 = iStack_12c;
  }
  if ((iVar11 < 1) && (iVar11 = param_1[2], lVar1 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == iVar11) {
        *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) - iStack_12c;
      }
    }
  }
  if ((iStack_12c < 1) || (dVar2 = dVar3, DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
    dVar2 = dVar3;
  }
LAB_140021bc1:
  auVar4._8_4_ = SUB84(dVar2,0);
  auVar4._0_8_ = dVar2;
  auVar4._12_4_ = (int)((ulonglong)dVar2 >> 0x20);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res8 * 4),0x23,7,param_1[10],
                param_1[0xb],(uint)fVar26 & 0xffff0000,auVar4,0xff,0xff,0xff,0xff,1,0);
  return;
}


