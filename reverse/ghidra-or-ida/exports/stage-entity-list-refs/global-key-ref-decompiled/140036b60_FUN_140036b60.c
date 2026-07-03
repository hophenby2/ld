// Function: FUN_140036b60 @ 140036b60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140036b60(undefined4 *param_1)

{
  float fVar1;
  short sVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  ushort uVar9;
  undefined8 uVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  ushort uVar18;
  int iVar19;
  uint uVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  double local_res8;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined8 in_stack_fffffffffffffe98;
  undefined4 uVar29;
  ulonglong uVar28;
  undefined8 uStack_110;
  undefined8 uStack_100;
  
  iVar15 = DAT_140e418c8;
  dVar23 = DAT_14053a2a8;
  dVar8 = DAT_14053a020;
  dVar7 = DAT_140539f40;
  dVar6 = DAT_140539d28;
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  uStack_110 = (ulonglong)(uint)uStack_110;
  lVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == param_1[2]) {
        uStack_110 = *(ulonglong *)(lVar4 + 0x18);
        uStack_100 = *(undefined8 *)(lVar4 + 0x28);
      }
    }
  }
  uVar27 = SUB84(DAT_140539f40,0);
  uVar5 = (ulonglong)DAT_140539f40 >> 0x20;
  local_res8 = DAT_140539f40;
  if ((uint)uStack_110 == 0x83) {
    FUN_140332d90(((double)DAT_140e418c8 - _DAT_140539cc0) * _DAT_14053a6c8 * DAT_14053a020 *
                  DAT_140539d28);
    dVar21 = (double)FUN_1403307c0();
    dVar22 = (double)FUN_140332d90();
    param_1[0xc] = (float)(dVar21 * dVar23) + (float)uStack_100;
    param_1[0xd] = (float)(dVar22 * dVar23) + (uStack_100._4_4_ - DAT_14053ad40);
  }
  if ((uint)uStack_110 == 0x84) {
    FUN_140332d90(((double)iVar15 - _DAT_140539cc0) * _DAT_14053a6c8 * dVar8 * dVar6);
    dVar21 = (double)FUN_1403307c0();
    dVar22 = (double)FUN_140332d90();
    uStack_100._4_4_ = uStack_100._4_4_ - DAT_14053ad40;
    param_1[0xc] = (float)(dVar21 * dVar23) + (float)uStack_100;
    param_1[0xd] = (float)(dVar22 * dVar23) + uStack_100._4_4_;
  }
  if (param_1[5] != 0) goto LAB_1400378c4;
  fVar1 = (float)param_1[10];
  dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - fVar1),0));
  uVar20 = param_1[3];
  dVar23 = dVar23 * DAT_14053aba0;
  if (uVar20 == 0) {
    param_1[0xe] = fVar1;
LAB_140036e5c:
    FUN_140332d90(((double)(int)uVar20 - 0.0) * _DAT_14053a2e0 * dVar8 * dVar6);
    FUN_140332d90(((double)(int)uVar20 - 0.0) * _DAT_14053a2e0 * dVar8 * dVar6);
LAB_140036ef8:
    local_res8 = dVar7;
    if (uVar20 < 10) {
      local_res8 = (double)FUN_140332d90(((double)(int)uVar20 - 0.0) * DAT_14053a9d8 * dVar8 * dVar6
                                        );
      local_res8 = local_res8 + 0.0;
    }
  }
  else {
    if (-1 < (int)uVar20) {
      if ((int)uVar20 < 0x21c) goto LAB_140036e5c;
      goto LAB_140036ef8;
    }
    local_res8 = 0.0;
  }
  dVar22 = DAT_14053a620;
  dVar21 = DAT_14053a3a8;
  iVar15 = param_1[6];
  if ((iVar15 == 0x8f) || (iVar15 == 0x92)) {
    sVar2 = *(short *)(param_1 + 0x10);
    FUN_140332d90(((double)(int)uVar20 - DAT_14053a620) * DAT_14053a3a8 * dVar8 * dVar6);
    uVar10 = FUN_140133f30();
    local_res10 = (undefined4)uVar10;
    uStackX_14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    param_1[10] = local_res10;
    param_1[0xb] = uStackX_14;
    *(short *)(param_1 + 0x10) = sVar2 + -0x1e5;
  }
  if (iVar15 - 0x90U < 2) {
    sVar2 = *(short *)(param_1 + 0x10);
    FUN_140332d90(((double)(int)uVar20 - dVar22) * dVar21 * dVar8 * dVar6);
    uVar10 = FUN_140133f30();
    local_res10 = (undefined4)uVar10;
    uStackX_14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    param_1[10] = local_res10;
    param_1[0xb] = uStackX_14;
    *(short *)(param_1 + 0x10) = sVar2 + 0x1e5;
  }
  dVar8 = DAT_14053a0f8;
  dVar6 = DAT_14053a088;
  uVar25 = SUB84(DAT_14053a088,0);
  uVar26 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
  if (iVar15 - 0x8fU < 2) {
    iVar15 = 1;
    if (DAT_140e419b8 == 0) {
      iVar15 = 0xb;
    }
    else if (DAT_140e419b8 == 1) {
LAB_1400370c0:
      iVar15 = 8;
    }
    else {
      if (DAT_140e419b8 != 2) {
        if (DAT_140e419b8 == 3) goto LAB_1400370c0;
        if (DAT_140e419b8 != 4) goto LAB_1400370ce;
      }
      iVar15 = 7;
    }
LAB_1400370ce:
    iVar14 = 1;
    if (DAT_140e419b8 == 0) {
      iVar14 = 3;
    }
    else if (DAT_140e419b8 == 1) {
      iVar14 = 5;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar14 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      iVar14 = 8;
    }
    dVar21 = DAT_14053a040;
    if ((((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a088, DAT_140e419b8 != 1)) &&
        (dVar21 = DAT_14053a0b0, DAT_140e419b8 != 2)) &&
       ((dVar21 = DAT_14053a088, DAT_140e419b8 != 3 && (dVar21 = dVar7, DAT_140e419b8 == 4)))) {
      dVar21 = DAT_14053a0f8;
    }
    iVar11 = param_1[3];
    dVar21 = (double)iVar11 * _DAT_140539d78 + dVar21;
    if ((9 < iVar11) && (uVar28 = (longlong)(iVar11 + -10) % (longlong)iVar15, (int)uVar28 == 0)) {
      iVar15 = iVar14 * 3000 + -3000;
      uVar10 = CONCAT44(uVar29,iVar14);
      FUN_1400709b0(4,uVar28 & 0xffffffff,param_1[10],param_1[0xb],(short)iVar11 * -0x118,0,dVar21,1
                    ,uVar10,iVar15,0);
      uVar28 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),iVar14);
      FUN_1400709b0(4,0,param_1[10],param_1[0xb],*(short *)(param_1 + 3) * -0x118 + -0x8000,0,dVar21
                    ,1,uVar28,iVar15,0);
      if (2 < DAT_140e419b8) {
        sVar2 = *(short *)(param_1 + 3);
        uVar29 = param_1[0xb];
        uVar24 = param_1[10];
        iVar15 = 0;
        do {
          uVar28 = uVar28 & 0xffffffff00000000;
          FUN_14006c2f0(5,0,uVar24,uVar29,(short)iVar15 * 3000 + sVar2 * 300 + -0x1194,0,
                        dVar21 + dVar7,1,uVar28);
          iVar15 = iVar15 + 1;
        } while (iVar15 < 4);
        sVar2 = *(short *)(param_1 + 3);
        uVar29 = param_1[0xb];
        uVar24 = param_1[10];
        iVar15 = 0;
        do {
          uVar28 = uVar28 & 0xffffffff00000000;
          FUN_14006c2f0(5,0,uVar24,uVar29,(short)iVar15 * 3000 + sVar2 * 300 + 0x6e6c,0,
                        dVar21 + dVar7,1,uVar28);
          iVar15 = iVar15 + 1;
        } while (iVar15 < 4);
      }
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
  }
  iVar15 = DAT_140e419b8;
  uVar29 = DAT_14053ac2c;
  uVar24 = SUB84(DAT_14053a070,0);
  uVar28 = (ulonglong)DAT_14053a070 >> 0x20;
  uVar9 = (ushort)(int)dVar23;
  if (param_1[6] - 0x91 < 2) {
    iVar14 = 1;
    if (DAT_140e419b8 == 0) {
LAB_140037376:
      iVar14 = 0x32;
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      iVar14 = 0x27;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) goto LAB_140037376;
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0xc;
    }
    else if (DAT_140e419b8 == 1) {
      iVar11 = 0x15;
    }
    else if (DAT_140e419b8 == 2) {
      iVar11 = 0x1b;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar11 = 0x24;
    }
    iVar19 = 1;
    if (DAT_140e419b8 == 0) {
      iVar19 = 10;
    }
    else if (DAT_140e419b8 == 1) {
      iVar19 = 0xe;
    }
    else if (DAT_140e419b8 == 2) {
      iVar19 = 0x10;
    }
    else if (DAT_140e419b8 == 3) {
      iVar19 = 0x12;
    }
    else if (DAT_140e419b8 == 4) {
      iVar19 = 0x14;
    }
    iVar13 = param_1[3];
    iVar19 = iVar19 + (iVar13 + -10) / (iVar14 * 2);
    dVar21 = DAT_14053a070;
    if ((((DAT_140e419b8 != 0) && (dVar21 = dVar6, DAT_140e419b8 != 1)) &&
        (dVar21 = DAT_14053a0b8, DAT_140e419b8 != 2)) &&
       ((dVar21 = dVar8, DAT_140e419b8 != 3 && (dVar21 = dVar7, DAT_140e419b8 == 4)))) {
      dVar21 = DAT_14053a138;
    }
    iVar17 = 1;
    dVar21 = (double)iVar13 * _DAT_140539d80 + dVar21;
    if (DAT_140e419b8 == 0) {
      iVar17 = 0x5a;
    }
    else if (DAT_140e419b8 == 1) {
      iVar17 = 0x3c;
    }
    else if (DAT_140e419b8 == 2) {
      iVar17 = 0x30;
    }
    else if (DAT_140e419b8 == 3) {
      iVar17 = 0x24;
    }
    else if (DAT_140e419b8 == 4) {
      iVar17 = 0x1a;
    }
    uVar16 = 1;
    if (DAT_140e419b8 == 0) {
      uVar16 = 0x14;
    }
    else if (DAT_140e419b8 == 1) {
      uVar16 = 0x20;
    }
    else if (DAT_140e419b8 == 2) {
      uVar16 = 0x24;
    }
    else if (DAT_140e419b8 == 3) {
      uVar16 = 0x28;
    }
    else if (DAT_140e419b8 == 4) {
      uVar16 = 0x2c;
    }
    if ((iVar13 < 10) || ((iVar13 + -10) % iVar14 != 0)) {
      uVar18 = *(ushort *)((longlong)param_1 + 0x42);
    }
    else {
      *(ushort *)((longlong)param_1 + 0x42) = uVar9;
      uVar18 = uVar9;
    }
    if (((9 < (int)param_1[3]) && (iVar13 = (param_1[3] + -10) % (iVar14 * 2), iVar13 < iVar11)) &&
       (iVar13 == (iVar13 / 3 + (iVar13 >> 0x1f) +
                  (int)(((longlong)iVar13 / 3 + ((longlong)iVar13 >> 0x3f) & 0xffffffffU) >> 0x1f))
                  * 3)) {
      FUN_1400709b0(0xb,0,param_1[10],param_1[0xb],uVar18,uVar29,dVar21,1,iVar19,0x10000,0);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar18 = *(ushort *)((longlong)param_1 + 0x42);
      iVar15 = DAT_140e419b8;
    }
    if (((iVar14 + 10 <= (int)param_1[3]) &&
        (iVar14 = (param_1[3] - (iVar14 + 10)) % (iVar14 * 2), iVar14 < iVar11)) &&
       (iVar14 == (iVar14 / 3 + (iVar14 >> 0x1f) +
                  (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU) >> 0x1f))
                  * 3)) {
      FUN_1400709b0(0xb,0,param_1[10],param_1[0xb],
                    (short)(0x10000 / (longlong)(iVar19 * 2)) + uVar18,uVar29,dVar21,1,iVar19,
                    0x10000,0);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar18 = *(ushort *)((longlong)param_1 + 0x42);
      iVar15 = DAT_140e419b8;
    }
    if ((param_1[3] - 0x1a < 0x1a8) &&
       (uVar3 = (longlong)(param_1[3] + -0x1a) % (longlong)iVar17, (int)uVar3 == 0)) {
      FUN_1400709b0(4,uVar3 & 0xffffffff,param_1[10],param_1[0xb],uVar18,0,dVar21 * DAT_140539f10,1,
                    uVar16,0x10000,0);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar15 = DAT_140e419b8;
    }
    uVar18 = *(ushort *)((longlong)param_1 + 0x42);
    iVar11 = ((int)dVar23 & 0xffffU) - (uint)uVar18;
    iVar14 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar14 = iVar11;
    }
    iVar11 = iVar14 + -0x10000;
    if (iVar14 < 0x8001) {
      iVar11 = iVar14;
    }
    if (iVar11 < 1) {
      uVar12 = uVar18;
      if ((iVar11 < 0) && (uVar12 = uVar18 - 0x30, -0x30 < iVar11)) {
        uVar12 = uVar9;
      }
    }
    else {
      uVar12 = uVar9;
      if (0x2f < iVar11) {
        uVar12 = uVar18 + 0x30;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar12;
  }
  dVar6 = DAT_140539f38;
  if (param_1[3] == 0x21c) {
    iVar14 = 1;
    if (iVar15 == 0) {
      iVar14 = 0x14;
    }
    else if (iVar15 == 1) {
      iVar14 = 0x24;
    }
    else if (iVar15 == 2) {
      iVar14 = 0x2c;
    }
    else if (iVar15 == 3) {
      iVar14 = 0x32;
    }
    else if (iVar15 == 4) {
      iVar14 = 0x37;
    }
    iVar11 = 1;
    if (iVar15 != 0) {
      if (iVar15 == 1) {
        iVar11 = 2;
      }
      else if (iVar15 == 2) {
        iVar11 = 3;
      }
      else if (iVar15 == 3) {
        iVar11 = 5;
      }
      else if (iVar15 == 4) {
        iVar11 = 6;
      }
      if (((iVar15 != 0) && (iVar15 != 1)) &&
         ((iVar15 == 2 || ((iVar15 == 3 || (uVar25 = uVar27, uVar26 = (int)uVar5, iVar15 == 4))))))
      {
        uVar25 = uVar24;
        uVar26 = (int)uVar28;
      }
    }
    uVar20 = 0;
    do {
      uVar10 = 3;
      if ((uint)uStack_110 != 0x83) {
        uVar10 = 2;
      }
      FUN_1400709b0(uVar10,0,param_1[10],param_1[0xb],
                    (short)((uVar20 & 0xffff) *
                           ((uint)(0x10000 / (ulonglong)(uint)(iVar14 * 5)) & 0xffff)) * 2 + uVar9,
                    uVar29,(double)(int)uVar20 * dVar6 + (double)CONCAT44(uVar26,uVar25),1,iVar14,
                    0x10000,0);
      uVar20 = uVar20 + 1;
    } while ((int)uVar20 < iVar11);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
LAB_1400378c4:
  if ((uint)uStack_110 == 0x83) {
    FUN_1400c8410(DAT_140e44834,0x23,7,param_1[10],param_1[0xb],*(short *)(param_1 + 3) * -0x457,
                  local_res8,local_res8,0xff,0xff,0xff,0xff,1,0);
    FUN_140070d00(5,DAT_140e44834,0x22,param_1[10],param_1[0xb],*(short *)(param_1 + 3) * -0x457,0,
                  local_res8,local_res8,0x10,0xff,0xff,0xff,0x60,0);
  }
  if ((uint)uStack_110 == 0x84) {
    FUN_1400c8410(DAT_140e44838,0x23,7,param_1[10],param_1[0xb],*(short *)(param_1 + 3) * -0x457,
                  local_res8,local_res8,0xff,0xff,0xff,0xff,1,0);
    FUN_140070d00(5,DAT_140e44838,0x22,param_1[10],param_1[0xb],*(short *)(param_1 + 3) * -0x457,0,
                  local_res8,local_res8,0x10,0xff,0xff,0xff,0x60,0);
  }
  if ((uStack_110._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  return;
}


