// Function: FUN_1400aa590 @ 1400aa590
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400aa590(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 auVar3 [16];
  double dVar4;
  float fVar5;
  undefined4 uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  ushort uVar16;
  undefined2 uVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  double dVar21;
  double dVar22;
  undefined8 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  float fVar30;
  uint in_stack_fffffffffffffef0;
  undefined2 uVar31;
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  ulonglong in_stack_ffffffffffffff08;
  ulonglong uVar39;
  
  fVar25 = (float)param_1[0xb];
  fVar18 = (float)param_1[10];
  dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar25 - DAT_14053ac80)),
                                 SUB84((double)(DAT_140e445d8 - fVar18),0));
  fVar19 = DAT_14053ae30;
  uVar31 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
  dVar21 = dVar21 * DAT_14053aba0;
  iVar12 = 0;
  fVar25 = (float)DAT_1407c77a4 + fVar25;
  param_1[0xb] = fVar25;
  uVar17 = 0;
  uVar16 = (ushort)(int)dVar21;
  if (param_1[5] == 0) {
    in_stack_ffffffffffffff08 = CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),0xff);
    dVar4 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    auVar3._8_4_ = SUB84(dVar4,0);
    auVar3._0_8_ = dVar4;
    auVar3._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,fVar18,fVar25,in_stack_fffffffffffffef0,auVar3,
                  in_stack_ffffffffffffff08,0xff,0xff,0xff,1,0);
    uVar31 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
    if (param_1[3] == 0x14) {
      iVar2 = param_1[6];
      if (iVar2 == 0x97) {
        *(undefined8 *)(param_1 + 0x12) = 0;
      }
      else if ((iVar2 == 0x98) || (iVar2 == 0x99)) {
        if (fVar19 < (float)param_1[0xc]) {
          uVar17 = 0x8000;
        }
        *(undefined2 *)(param_1 + 0x10) = uVar17;
        if (iVar2 == 0x98) {
          uVar23 = 0x3ff8000000000000;
        }
        else {
          if (iVar2 != 0x99) goto LAB_1400aa72f;
          uVar23 = 0x4018000000000000;
        }
        *(undefined8 *)(param_1 + 0x12) = uVar23;
      }
LAB_1400aa72f:
      param_1[5] = param_1[5] + 1;
      *(ushort *)((longlong)param_1 + 0x42) = uVar16;
      param_1[3] = 0;
    }
  }
  fVar5 = DAT_14053af14;
  fVar18 = DAT_14053aec0;
  fVar25 = DAT_14053ac2c;
  uVar28 = (undefined4)DAT_140539f40;
  uVar29 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  if (param_1[5] != 1) goto LAB_1400aaf57;
  if (param_1[0x15] == 1) {
    if ((((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= (float)param_1[10]) &&
         ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
        (0.0 <= (float)param_1[0xb])) && ((float)param_1[0xb] <= DAT_14053af14)) {
      param_1[0x15] = 0;
    }
  }
  dVar4 = *(double *)(param_1 + 0x12);
  dVar22 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar22 * dVar4) + (float)param_1[10];
  dVar22 = (double)FUN_140332d90();
  param_1[0xb] = (float)(dVar22 * dVar4) + (float)param_1[0xb];
  dVar22 = _DAT_14053b248;
  if (fVar19 < (float)param_1[0xc]) {
    dVar22 = _DAT_14053a790;
  }
  *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) - (short)(int)(dVar4 * dVar22);
  if (param_1[6] == 0x99) {
    if (((uint)param_1[3] < 0x65) && (0.0 < dVar4)) {
      dVar4 = dVar4 - DAT_140539e30;
    }
    *(double *)(param_1 + 0x12) = dVar4;
    if (99 < (int)param_1[3]) {
      *(double *)(param_1 + 0x12) = 0.0;
    }
  }
  iVar2 = DAT_140e419b8;
  iVar10 = 1;
  if (DAT_140e419b8 == 0) {
    iVar10 = 0x5a;
  }
  else if (DAT_140e419b8 == 1) {
LAB_1400aa8ee:
    iVar10 = 0x3c;
  }
  else {
    if (DAT_140e419b8 != 2) {
      if (DAT_140e419b8 == 3) goto LAB_1400aa8ee;
      if (DAT_140e419b8 != 4) goto LAB_1400aa8fa;
    }
    iVar10 = 0x2c;
  }
LAB_1400aa8fa:
  iVar11 = 1;
  if (DAT_140e419b8 == 0) {
    iVar11 = 0x1e;
  }
  else if (DAT_140e419b8 == 1) {
    iVar11 = 0x12;
  }
  else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
    iVar11 = 0xc;
  }
  else if (DAT_140e419b8 == 4) {
    iVar11 = 10;
  }
  if (((int)param_1[3] < 0x1e) || (iVar11 * 2 + 1 <= (param_1[3] + -0x1e) % iVar10)) {
    fVar30 = (float)param_1[0xb];
LAB_1400aa9a3:
    uVar1 = *(ushort *)((longlong)param_1 + 0x42);
    uVar7 = uVar16 - uVar1;
    uVar15 = (uint)uVar7;
    if (0x8000 < uVar7) {
      uVar15 = 0x10000 - uVar7;
    }
    iVar9 = ((int)dVar21 & 0xffffU) - (uint)uVar1;
    iVar14 = (int)uVar15 / 10 + 0x30;
    iVar8 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar8 = iVar9;
    }
    iVar9 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar9 = iVar8;
    }
    if (iVar9 < 1) {
      uVar7 = uVar1;
      if ((iVar9 < 0) && (uVar7 = uVar1 - (short)iVar14, -iVar14 < iVar9)) {
        uVar7 = uVar16;
      }
    }
    else {
      uVar7 = uVar16;
      if (iVar14 <= iVar9) {
        uVar7 = uVar1 + (short)iVar14;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar7;
  }
  else {
    fVar30 = (float)param_1[0xb];
    if (fVar19 <= fVar30) goto LAB_1400aa9a3;
  }
  dVar21 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar21 * DAT_14053a330) + (float)param_1[10];
  dVar21 = (double)FUN_140332d90();
  uVar20 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
  fVar26 = (float)(dVar21 * DAT_14053a330) + (fVar30 - DAT_14053ac80);
  if (0x1d < (int)param_1[3]) {
    uVar39 = (longlong)(param_1[3] + -0x1e) % (longlong)iVar10;
    iVar10 = (int)uVar39;
    if ((((iVar10 < iVar11 * 3) &&
         ((int)((longlong)((ulonglong)(uint)(iVar10 >> 0x1f) << 0x20 | uVar39 & 0xffffffff) %
               (longlong)iVar11) == 0)) && (fVar30 < fVar19)) &&
       (((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar27 &&
         (fVar27 <= DAT_140e445d8 / DAT_14053ab70 + fVar18)) &&
        ((0.0 <= fVar26 && (fVar26 <= fVar5)))))) {
      fVar18 = (float)FUN_140334430(fVar27 - DAT_140e445d8,DAT_140539fc0);
      fVar19 = (float)FUN_140334430(fVar26 - DAT_140e445dc);
      if (fVar18 + fVar19 < 0.0) {
        fVar18 = (float)FUN_1403352f8();
      }
      else {
        fVar18 = SQRT(fVar18 + fVar19);
      }
      uVar20 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
      if (DAT_14053acbc < fVar18) {
        if (2 < iVar2) {
          do {
            in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
            FUN_14006c2f0(7,0);
            uVar20 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
            iVar12 = iVar12 + 1;
          } while (iVar12 < 2);
        }
        fVar18 = fVar25;
        FUN_14006c2f0(7,0);
        uVar31 = (undefined2)((uint)fVar18 >> 0x10);
      }
    }
  }
  uVar6 = _UNK_14053bb2c;
  uVar24 = _UNK_14053bb28;
  uVar29 = _UNK_14053bb24;
  uVar28 = _DAT_14053bb20;
  fVar18 = DAT_14053ac80;
  uVar23 = CONCAT44(uVar20,0xff);
  auVar32._4_4_ = _UNK_14053bb24;
  auVar32._0_4_ = _DAT_14053bb20;
  auVar32._8_4_ = _UNK_14053bb28;
  auVar32._12_4_ = _UNK_14053bb2c;
  uVar20 = CONCAT22(uVar31,*(undefined2 *)(param_1 + 0x11));
  FUN_1400c8410(DAT_140e44868,0x19,7,(float)param_1[10] + DAT_14053ac80,
                (float)param_1[0xb] - DAT_14053ac44,uVar20,auVar32,uVar23,0xff,0xff,0xff,1,0);
  uVar23 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),0xff);
  auVar33._4_4_ = uVar29;
  auVar33._0_4_ = uVar28;
  auVar33._8_4_ = uVar24;
  auVar33._12_4_ = uVar6;
  uVar15 = CONCAT22((short)((uint)uVar20 >> 0x10),*(undefined2 *)(param_1 + 0x11));
  FUN_1400c8410(DAT_140e44868,0x19,7,(float)param_1[10] - fVar18,(float)param_1[0xb] - DAT_14053ac44
                ,uVar15,auVar33,uVar23,0xff,0xff,0xff,1,0);
  uVar23 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),0xff);
  auVar34._4_4_ = uVar29;
  auVar34._0_4_ = uVar28;
  auVar34._8_4_ = uVar24;
  auVar34._12_4_ = uVar6;
  uVar15 = uVar15 & 0xffff0000;
  FUN_1400c8410(DAT_140e44864,0x19,7,param_1[10],(float)param_1[0xb] + fVar25,uVar15,auVar34,uVar23,
                0xff,0xff,0xff,1,0);
  uVar23 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),0xff);
  auVar35._4_4_ = uVar29;
  auVar35._0_4_ = uVar28;
  auVar35._8_4_ = uVar24;
  auVar35._12_4_ = uVar6;
  uVar20 = CONCAT22((short)(uVar15 >> 0x10),*(undefined2 *)(param_1 + 0x11));
  FUN_1400c8410(DAT_140e44868,0x19,7,(float)param_1[10] + fVar18,(float)param_1[0xb] + DAT_14053ac9c
                ,uVar20,auVar35,uVar23,0xff,0xff,0xff,1,0);
  uVar23 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),0xff);
  auVar36._4_4_ = uVar29;
  auVar36._0_4_ = uVar28;
  auVar36._8_4_ = uVar24;
  auVar36._12_4_ = uVar6;
  uVar20 = CONCAT22((short)((uint)uVar20 >> 0x10),*(undefined2 *)(param_1 + 0x11));
  FUN_1400c8410(DAT_140e44868,0x19,7,(float)param_1[10] - fVar18,(float)param_1[0xb] + DAT_14053ac9c
                ,uVar20,auVar36,uVar23,0xff,0xff,0xff,1,0);
  uVar39 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),0xff);
  auVar37._4_4_ = uVar29;
  auVar37._0_4_ = uVar28;
  auVar37._8_4_ = uVar24;
  auVar37._12_4_ = uVar6;
  uVar15 = CONCAT22((short)((uint)uVar20 >> 0x10),*(undefined2 *)((longlong)param_1 + 0x42));
  FUN_1400c8410(DAT_140e4486c,0x1a,7,param_1[10],(float)param_1[0xb] - fVar18,uVar15,auVar37,uVar39,
                0xff,0xff,0xff,1,0);
  auVar38._4_4_ = uVar29;
  auVar38._0_4_ = uVar28;
  auVar38._8_4_ = uVar24;
  auVar38._12_4_ = uVar6;
  uVar15 = uVar15 & 0xffff0000;
  FUN_1400c8410(DAT_140e44864,0x18,7,param_1[10],(float)param_1[0xb] + DAT_14053ac4c,uVar15,auVar38,
                uVar39 & 0xffffffff00000000,0,0,0x40,1,0);
  uVar31 = (undefined2)(uVar15 >> 0x10);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
LAB_1400aaf57:
  if ((int)param_1[7] < 1) {
    uVar13 = param_1[1] + DAT_140e418c8;
    uVar15 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar15 = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
    DAT_140e9fd1c = uVar15;
    uVar23 = FUN_140134db0(uVar13,(int)DAT_140539f58,DAT_140539f68);
    uVar20 = (undefined4)uVar23;
    uVar24 = (undefined4)((ulonglong)uVar23 >> 0x20);
    uVar23 = FUN_140134db0(uVar13);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],(float)param_1[0xb] + fVar25,
                  CONCAT22(uVar31,(short)uVar15 - (short)(uVar15 / 0x10001)),CONCAT44(uVar29,uVar28)
                  ,uVar23,CONCAT44(uVar24,uVar20),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,1000,4);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((param_1[0x15] == 0) && (DAT_14053af54 <= (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


