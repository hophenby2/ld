// Function: FUN_1400dc1c0 @ 1400dc1c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400dc1c0(undefined4 *param_1)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  longlong lVar4;
  short sVar5;
  int iVar6;
  ushort uVar7;
  int iVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 uVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  undefined4 in_stack_fffffffffffffe68;
  undefined4 uVar25;
  undefined2 uVar26;
  undefined4 in_stack_fffffffffffffe70;
  undefined2 uVar27;
  undefined8 uStack_120;
  undefined8 uStack_110;
  
  dVar18 = DAT_140539f40;
  uVar26 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffe70 >> 0x10);
  uStack_120._4_4_ = 0;
  uStack_120 = 0;
  if ((0 < DAT_140e44e6c) && (lVar4 = DAT_140e45d80, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        uStack_120 = *(undefined8 *)(lVar4 + 0x18);
        uStack_110 = *(undefined8 *)(lVar4 + 0x28);
      }
      lVar4 = *(longlong *)(lVar4 + 0x60);
    } while (lVar4 != 0);
  }
  dVar15 = *(double *)(param_1 + 0x12);
  fVar24 = (float)param_1[0xe];
  uVar19 = SUB84(DAT_140539d28,0);
  uVar21 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  uVar11 = (uint)dVar15;
  dVar14 = DAT_140539f40;
  dVar16 = DAT_14053a020;
  if (param_1[5] == 0) {
    iVar10 = param_1[3];
    param_1[0xc] = (float)uStack_110;
    param_1[0xd] = uStack_110._4_4_;
    if (iVar10 == 0) {
      fVar24 = (float)param_1[10];
      param_1[0xe] = fVar24;
    }
    dVar14 = (double)FUN_140332d90();
    if (dVar15 <= 0.0) {
      uVar9 = (short)(int)(dVar14 * DAT_14053aa78) - 3000;
    }
    else {
      uVar9 = (short)(int)(dVar14 * DAT_14053b2e0) + 3000;
    }
    uVar11 = (uint)uVar9;
    dVar15 = (double)FUN_140332d90();
    fVar24 = (float)(dVar15 * (double)fVar24) + _DAT_140539cbc;
    if (iVar10 < 0) {
      dVar14 = 0.0;
    }
    else {
      dVar14 = dVar18;
      if (iVar10 < 0x28) {
        dVar14 = (double)FUN_140332d90();
        dVar14 = dVar14 + 0.0;
      }
    }
    sVar2 = *(short *)(param_1 + 0x10);
    *(ushort *)(param_1 + 0x10) = uVar9 + sVar2;
    dVar15 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar15 * (double)fVar24) + (float)uStack_110;
    dVar15 = (double)FUN_140332d90();
    sVar5 = (short)DAT_140e418c8 * 0x29a;
    param_1[10] = fVar23;
    fVar20 = (float)(dVar15 * (double)fVar24) + uStack_110._4_4_;
    param_1[0xb] = fVar20;
    FUN_140070d00(5,DAT_140e4477c,0x1c,fVar23,fVar20,CONCAT22(uVar27,sVar5 + uVar9 + sVar2),0,
                  SUB84(dVar14,0),SUB84(dVar14,0),0x10,0xff,0xff,0xff,0x60,0);
    dVar16 = DAT_14053a020;
    uVar26 = (undefined2)((uint)fVar20 >> 0x10);
    uVar19 = SUB84(DAT_140539d28,0);
    uVar21 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    if (param_1[3] == 0x28) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  dVar15 = DAT_140539e60;
  iVar10 = DAT_140e419b8;
  if (param_1[5] == 1) {
    iVar3 = param_1[3];
    param_1[0xc] = (float)uStack_110;
    dVar16 = (double)FUN_140332d90(((double)iVar3 - 0.0) * _DAT_14053a478 * dVar16 *
                                   (double)CONCAT44(uVar21,uVar19));
    *(short *)(param_1 + 0x10) =
         (short)(int)(dVar16 * (double)(int)uVar11) + *(short *)(param_1 + 0x10);
    dVar16 = (double)FUN_1403307c0();
    uStack_110._0_4_ = (float)(dVar16 * (double)fVar24) + (float)uStack_110;
    dVar17 = (double)FUN_140332d90();
    dVar16 = DAT_14053aba0;
    uVar19 = SUB84(DAT_14053aba0,0);
    uVar21 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
    param_1[0xd] = uStack_110._4_4_;
    param_1[10] = (float)uStack_110;
    uStack_110._4_4_ = (float)(dVar17 * (double)fVar24) + uStack_110._4_4_;
    param_1[0xb] = uStack_110._4_4_;
    iVar10 = DAT_140e419b8;
    if (param_1[6] == 0x61) {
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_110._4_4_),
                                     SUB84((double)(DAT_140e445d8 - (float)uStack_110),0));
      iVar10 = DAT_140e419b8;
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0xb4;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0x78;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar6 = 0x5a;
      }
      else if (DAT_140e419b8 == 4) {
        iVar6 = 0x3c;
      }
      dVar22 = DAT_14053a0b0;
      if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar22 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((dVar22 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar22 = dVar18, DAT_140e419b8 == 4)))) {
        dVar22 = DAT_14053a138;
      }
      iVar8 = (iVar3 + -0x32) % iVar6;
      dVar22 = (double)iVar8 * dVar15 + dVar22;
      uVar9 = (ushort)(int)(dVar17 * dVar16);
      if ((iVar3 - 0x32U < 0x1fe) && (iVar8 == 0)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar9;
        uVar7 = uVar9;
      }
      else {
        uVar7 = *(ushort *)((longlong)param_1 + 0x42);
      }
      uVar1 = DAT_14053ac2c;
      if ((param_1[3] - 0x32 < 0x1fe) && (iVar8 < 0x14)) {
        uVar11 = (param_1[3] + -0x32) % iVar6 & 0x80000003;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
        }
        if (uVar11 == 0) {
          uVar25 = CONCAT22(uVar26,uVar7);
          FUN_14006c2f0(0xb,0,(float)uStack_110,param_1[0xb],uVar25,DAT_14053ac2c,dVar22,1,0);
          uVar26 = (undefined2)((uint)uVar25 >> 0x10);
          if (2 < DAT_140e419b8) {
            uVar25 = CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42));
            FUN_14006c2f0(0xb,0,param_1[10],param_1[0xb],uVar25,uVar1,dVar22 + DAT_140539fc8,1,0);
            uVar26 = (undefined2)((uint)uVar25 >> 0x10);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          iVar10 = DAT_140e419b8;
        }
      }
      uVar7 = *(ushort *)((longlong)param_1 + 0x42);
      iVar6 = ((int)(dVar17 * dVar16) & 0xffffU) - (uint)uVar7;
      iVar3 = iVar6 + 0x10000;
      if (-0x8001 < iVar6) {
        iVar3 = iVar6;
      }
      iVar6 = iVar3 + -0x10000;
      if (iVar3 < 0x8001) {
        iVar6 = iVar3;
      }
      if (iVar6 < 1) {
        if ((iVar6 < 0) && (uVar7 = uVar7 - 0x30, -0x30 < iVar6)) {
          uVar7 = uVar9;
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar7;
      }
      else if (iVar6 < 0x30) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar9;
      }
      else {
        *(ushort *)((longlong)param_1 + 0x42) = uVar7 + 0x30;
      }
    }
    iVar3 = param_1[6];
    if (iVar3 - 0x62U < 2) {
      iVar6 = 1;
      if (iVar10 == 0) {
        iVar6 = 9;
      }
      else if (iVar10 == 1) {
LAB_1400dc7c1:
        iVar6 = 6;
      }
      else if ((iVar10 == 2) || (iVar10 == 3)) {
        iVar6 = 7;
      }
      else if (iVar10 == 4) goto LAB_1400dc7c1;
      dVar16 = DAT_14053a030;
      if ((((iVar10 != 0) && (dVar16 = DAT_14053a060, iVar10 != 1)) &&
          (dVar16 = DAT_14053a078, iVar10 != 2)) &&
         ((dVar16 = DAT_14053a088, iVar10 != 3 && (dVar16 = dVar18, iVar10 == 4)))) {
        dVar16 = DAT_14053a0d0;
      }
      uVar11 = param_1[3];
      sVar2 = *(short *)(param_1 + 0x10);
      sVar5 = (short)uVar11 * 0x14;
      dVar17 = (double)(int)uVar11 * _DAT_140539d88;
      if (iVar3 == 99) {
        sVar5 = (short)uVar11 * -0x14;
      }
      if (((uVar11 < 0x230) && ((int)uVar11 % iVar6 == 0)) &&
         (((int)uVar11 < iVar6 * 3 ||
          ((iVar6 * 0x23 <= (int)uVar11 || (iVar6 * 2 <= (int)(uVar11 + iVar6 * -3) % (iVar6 * 5))))
          ))) {
        fVar20 = (float)param_1[0xb];
        fVar23 = (float)param_1[10];
        fVar12 = (float)FUN_140334430(fVar20 - DAT_140e445dc,DAT_140539fc0);
        fVar13 = (float)FUN_140334430(fVar23 - DAT_140e445d8);
        if (fVar12 + fVar13 < 0.0) {
          fVar12 = (float)FUN_1403352f8();
        }
        else {
          fVar12 = SQRT(fVar12 + fVar13);
        }
        if (DAT_14053acfc <= fVar12) {
          uVar19 = CONCAT22(uVar26,sVar5 + sVar2 + -0x8000);
          FUN_14006c2f0((iVar3 == 99) + '\x04',0,fVar23,fVar20,uVar19,0,dVar17 + dVar16,1,0);
          uVar26 = (undefined2)((uint)uVar19 >> 0x10);
          FUN_140184700(DAT_140e44190 * 9,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar10 = DAT_140e419b8;
        }
        uVar19 = SUB84(DAT_14053aba0,0);
        uVar21 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
      }
    }
    if (param_1[3] == 600) {
      param_1[3] = 0;
      if (param_1[6] == 0x61) {
        param_1[5] = 2;
      }
      else {
        dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xd]),
                                       SUB84((double)(DAT_140e445d8 - (float)param_1[0xc]),0));
        *(undefined8 *)(param_1 + 0x12) = 0;
        param_1[5] = 3;
        *(short *)((longlong)param_1 + 0x42) =
             (short)(int)(dVar16 * (double)CONCAT44(uVar21,uVar19));
      }
    }
  }
  if (param_1[5] == 2) {
    iVar10 = param_1[3];
    dVar14 = dVar18;
    if (iVar10 < 0) goto LAB_1400dcc09;
    if (iVar10 < 0x1e) {
      dVar14 = (double)FUN_140332d90(((double)iVar10 - DAT_14053b128) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar14 = dVar14 + 0.0;
      goto LAB_1400dcc09;
    }
    dVar14 = 0.0;
    dVar18 = 0.0;
    if (iVar10 != 0x1e) goto LAB_1400dcc09;
  }
  else {
    if (param_1[5] != 3) goto LAB_1400dcc09;
    param_1[0xe] = (float)param_1[0xe] + DAT_140539da8;
    if ((((iVar10 == 0) || (iVar10 == 1)) || (iVar10 == 2)) || ((iVar10 == 3 || (iVar10 == 4)))) {
      dVar18 = dVar15;
    }
    dVar18 = dVar18 + *(double *)(param_1 + 0x12);
    *(double *)(param_1 + 0x12) = dVar18;
    sVar2 = *(short *)(param_1 + 3) * -2;
    if (param_1[6] != 99) {
      sVar2 = *(short *)(param_1 + 3) * 2;
    }
    sVar5 = *(short *)(param_1 + 0x10);
    *(short *)(param_1 + 0x10) = sVar2 + sVar5;
    dVar15 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar15 * dVar18) + (float)param_1[0xc];
    param_1[0xc] = fVar23;
    dVar15 = (double)FUN_140332d90();
    fVar20 = (float)(dVar15 * dVar18) + (float)param_1[0xd];
    param_1[0xd] = fVar20;
    dVar18 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar18 * (double)fVar24) + fVar23;
    dVar18 = (double)FUN_140332d90();
    param_1[10] = fVar23;
    fVar20 = (float)(dVar18 * (double)fVar24) + fVar20;
    param_1[0xb] = fVar20;
    FUN_14006c2f0(5,0xf,fVar23,fVar20,CONCAT22(uVar26,sVar2 + sVar5),0,0,1,0);
    dVar18 = dVar14;
    if (((DAT_140e445d8 / DAT_14053ab70 - DAT_14053acbc <= (float)param_1[10]) &&
        ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aee0)) &&
       ((DAT_14053b358 <= (float)param_1[0xb] && ((float)param_1[0xb] <= _DAT_14053af34))))
    goto LAB_1400dcc09;
  }
  dVar14 = dVar18;
  *param_1 = 0;
LAB_1400dcc09:
  FUN_1400c8410(DAT_140e4477c,0x1d,7,param_1[10],param_1[0xb],
                (short)DAT_140e418c8 * 0x29a + *(short *)(param_1 + 0x10),dVar14,SUB84(dVar14,0),
                0xff,0xff,0xff,0xff,1,0);
  if ((uStack_120._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


