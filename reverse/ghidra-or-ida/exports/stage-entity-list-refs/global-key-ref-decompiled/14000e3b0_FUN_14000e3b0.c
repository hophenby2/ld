// Function: FUN_14000e3b0 @ 14000e3b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000e3b0(undefined4 *param_1)

{
  short sVar1;
  longlong lVar2;
  ulonglong uVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  int iVar8;
  short sVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 in_stack_fffffffffffffe68;
  undefined4 uVar28;
  undefined2 uVar29;
  undefined4 in_stack_fffffffffffffe70;
  undefined2 uVar30;
  undefined8 uStack_130;
  int iStack_11c;
  undefined8 uStack_110;
  
  dVar19 = DAT_14053a020;
  dVar18 = DAT_140539d28;
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffe70 >> 0x10);
  uVar29 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  iStack_11c = 0;
  iVar8 = 0;
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_11c = iVar8, lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        uStack_130 = *(undefined8 *)(lVar2 + 8);
        iStack_11c = *(int *)(lVar2 + 0x1c);
        uStack_110 = *(undefined8 *)(lVar2 + 0x28);
      }
      iVar8 = iStack_11c;
    }
  }
  dVar17 = *(double *)(param_1 + 0x12);
  fVar24 = (float)param_1[0xe];
  sVar9 = (short)(int)dVar17;
  dVar15 = (double)FUN_140332d90(((double)uStack_130._4_4_ - 0.0) * _DAT_14053a9b8 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar4 = DAT_140539f40;
  uVar23 = SUB84(DAT_140539f40,0);
  uVar3 = (ulonglong)DAT_140539f40 >> 0x20;
  dVar15 = dVar15 * DAT_140539e60;
  param_1[0xc] = (float)uStack_110;
  param_1[0xd] = uStack_110._4_4_;
  dVar15 = dVar15 + dVar4;
  uVar27 = SUB84(dVar15,0);
  sVar12 = (short)uStack_130._4_4_;
  if (param_1[5] == 0) {
    if (param_1[3] == 0) {
      fVar24 = (float)param_1[10];
      param_1[0xe] = fVar24;
    }
    dVar16 = (double)FUN_140332d90();
    if (dVar17 <= 0.0) {
      sVar9 = (short)(int)(dVar16 * DAT_14053aa78) + sVar9 + -3000;
    }
    else {
      sVar9 = (short)(int)(dVar16 * DAT_14053b2e0) + sVar9 + 3000;
    }
    dVar17 = (double)FUN_140332d90();
    sVar1 = *(short *)(param_1 + 0x10);
    *(short *)(param_1 + 0x10) = sVar9 + sVar1;
    fVar24 = (float)(dVar17 * (double)fVar24) + 0.0;
    dVar17 = (double)FUN_1403307c0();
    uStack_110._0_4_ = (float)(dVar17 * (double)fVar24) + (float)uStack_110;
    dVar17 = (double)FUN_140332d90();
    param_1[10] = (float)uStack_110;
    uVar21 = CONCAT22(uVar30,sVar9 + sVar1 + sVar12 * 0x14d);
    fVar20 = (float)(dVar17 * (double)fVar24) + (float)param_1[0xd];
    param_1[0xb] = fVar20;
    FUN_1400c8410(DAT_140e446bc,0x1d,7,(float)uStack_110,fVar20,uVar21,dVar15,uVar27,0xff,0xff,0xff,
                  0xff,1,0);
    uVar28 = param_1[0xb];
    uVar21 = CONCAT22((short)((uint)uVar21 >> 0x10),sVar12 * 0x14d + *(short *)(param_1 + 0x10));
    FUN_140070d00(5,DAT_140e446bc,0x1c,param_1[10],uVar28,uVar21,0,uVar27,uVar27,0x10,0xff,0xff,0xff
                  ,0x60,0);
    uVar30 = (undefined2)((uint)uVar21 >> 0x10);
    uVar29 = (undefined2)((uint)uVar28 >> 0x10);
    if (param_1[3] == 0x32) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_14000ec63;
  iVar8 = param_1[6];
  if (iVar8 == 0x23) {
    dVar18 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a4d8 * dVar19 * dVar18
                                  );
    dVar18 = dVar18 * _DAT_14053a870;
LAB_14000e77a:
    sVar9 = (short)(int)dVar18;
  }
  else if (iVar8 == 0x24) {
    dVar18 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a628 * dVar19 * dVar18
                                  );
    dVar18 = dVar18 * DAT_14053a6d0;
    goto LAB_14000e77a;
  }
  sVar1 = *(short *)(param_1 + 0x10);
  *(short *)(param_1 + 0x10) = sVar9 + sVar1;
  dVar18 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar18 * (double)fVar24) + (float)param_1[0xc];
  dVar16 = (double)FUN_140332d90();
  iVar6 = DAT_140e419b8;
  uVar28 = DAT_14053ac2c;
  dVar17 = DAT_14053a0f8;
  dVar19 = DAT_14053a0b0;
  dVar18 = DAT_14053a070;
  uVar25 = SUB84(DAT_14053a0f8,0);
  uVar26 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
  uVar21 = SUB84(DAT_14053a0b0,0);
  uVar22 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
  param_1[10] = fVar20;
  fVar24 = (float)(dVar16 * (double)fVar24) + (float)param_1[0xd];
  param_1[0xb] = fVar24;
  if (iVar8 == 0x23) {
    iVar8 = 1;
    if (iVar6 == 0) {
      iVar8 = 9;
    }
    else if (((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) {
      iVar8 = 5;
    }
    else if (iVar6 == 4) {
      iVar8 = 4;
    }
    dVar16 = dVar18;
    if (((iVar6 != 0) && (dVar16 = dVar19, iVar6 != 1)) &&
       ((dVar16 = dVar17, iVar6 != 2 &&
        ((dVar16 = DAT_14053a118, iVar6 != 3 && (dVar16 = dVar4, iVar6 == 4)))))) {
      dVar16 = DAT_14053a158;
    }
    if (((uint)((int)param_1[3] % 0x1e0) < 0x1a4) && (((int)param_1[3] % 0x1e0) % iVar8 == 0)) {
      fVar13 = (float)FUN_140334430(fVar20 - DAT_140e445d8,DAT_140539fc0);
      fVar14 = (float)FUN_140334430(fVar24 - DAT_140e445dc);
      if (fVar13 + fVar14 < 0.0) {
        fVar13 = (float)FUN_1403352f8();
      }
      else {
        fVar13 = SQRT(fVar13 + fVar14);
      }
      if (DAT_14053acfc <= fVar13) {
        uVar22 = CONCAT22(uVar29,sVar9 + sVar1 + sVar12 * -0xb4);
        uVar21 = uVar28;
        FUN_14006c2f0(1,0,fVar20,fVar24,uVar22,uVar28,dVar16,1,0);
        uVar30 = (undefined2)((uint)uVar21 >> 0x10);
        uVar29 = (undefined2)((uint)uVar22 >> 0x10);
        if (2 < DAT_140e419b8) {
          uVar22 = CONCAT22(uVar29,*(short *)(param_1 + 0x10) + sVar12 * -0xb4);
          uVar21 = uVar28;
          FUN_14006c2f0(1,0,param_1[10],param_1[0xb],uVar22,uVar28,dVar16 + DAT_140539f10,1,0);
          uVar30 = (undefined2)((uint)uVar21 >> 0x10);
          uVar29 = (undefined2)((uint)uVar22 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 9,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        fVar20 = (float)param_1[10];
        iVar6 = DAT_140e419b8;
      }
      uVar21 = SUB84(DAT_14053a0b0,0);
      uVar22 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      dVar18 = DAT_14053a070;
    }
  }
  if (param_1[6] == 0x24) {
    dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    dVar19 = dVar19 * DAT_14053aba0;
    iVar8 = 1;
    if (iVar6 == 0) {
      iVar8 = 0xf0;
    }
    else if (iVar6 == 1) {
      iVar8 = 0xd2;
    }
    else if ((iVar6 == 2) || (iVar6 == 3)) {
      iVar8 = 0xb4;
    }
    else if (iVar6 == 4) {
      iVar8 = 0xa0;
    }
    iVar5 = 1;
    if (iVar6 == 0) {
      iVar5 = 0x10;
    }
    else if (iVar6 == 1) {
      iVar5 = 0x19;
    }
    else if (((iVar6 == 2) || (iVar6 == 3)) || (iVar6 == 4)) {
      iVar5 = 0x20;
    }
    if (iVar6 == 0) {
      uVar21 = SUB84(dVar18,0);
      uVar22 = (int)((ulonglong)dVar18 >> 0x20);
    }
    else if (((iVar6 != 1) && (uVar21 = uVar25, uVar22 = uVar26, iVar6 != 2)) &&
            ((iVar6 != 3 && (uVar21 = uVar23, uVar22 = (int)uVar3, iVar6 == 4)))) {
      uVar21 = (int)DAT_14053a160;
      uVar22 = (int)((ulonglong)DAT_14053a160 >> 0x20);
    }
    iVar6 = param_1[3];
    iVar8 = (iVar6 + -0x1e) % iVar8;
    dVar18 = (double)iVar8 * DAT_140539ec8;
    uVar10 = (ushort)(int)dVar19;
    if ((iVar6 < 0x1e) || (iVar8 != 0)) {
      uVar11 = *(ushort *)((longlong)param_1 + 0x42);
      if (0x1d < iVar6) goto LAB_14000eb30;
    }
    else {
      *(ushort *)((longlong)param_1 + 0x42) = uVar10;
      uVar11 = uVar10;
LAB_14000eb30:
      if ((iVar8 < iVar5) &&
         (iVar8 == (iVar8 / 3 + (iVar8 >> 0x1f) +
                   (int)(((longlong)iVar8 / 3 + ((longlong)iVar8 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                   3)) {
        FUN_14006c2f0(0xb,0,param_1[10],param_1[0xb],CONCAT22(uVar29,uVar11),uVar28,
                      dVar18 + (double)CONCAT44(uVar22,uVar21),1,0);
        uVar30 = (undefined2)((uint)uVar28 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    uVar11 = *(ushort *)((longlong)param_1 + 0x42);
    iVar6 = ((int)dVar19 & 0xffffU) - (uint)uVar11;
    iVar8 = iVar6 + 0x10000;
    if (-0x8001 < iVar6) {
      iVar8 = iVar6;
    }
    iVar6 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar6 = iVar8;
    }
    if (iVar6 < 1) {
      uVar7 = uVar11;
      if ((iVar6 < 0) && (uVar7 = uVar11 - 0x30, -0x30 < iVar6)) {
        uVar7 = uVar10;
      }
    }
    else {
      uVar7 = uVar10;
      if (0x2f < iVar6) {
        uVar7 = uVar11 + 0x30;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar7;
  }
  FUN_1400c8410(DAT_140e446bc,0x1d,7,param_1[10],param_1[0xb],
                CONCAT22(uVar30,sVar12 * 0x14d + *(short *)(param_1 + 0x10)),dVar15,uVar27,0xff,0xff
                ,0xff,0xff,1,0);
LAB_14000ec63:
  if ((iStack_11c < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


