// Function: FUN_140096890 @ 140096890
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140096890(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  double dVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  double dVar7;
  ushort uVar8;
  int iVar9;
  undefined8 uVar10;
  uint uVar11;
  int iVar12;
  ushort uVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff18;
  undefined2 uVar28;
  uint in_stack_ffffffffffffff20;
  undefined2 uVar29;
  undefined1 in_stack_ffffffffffffff28 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  
  uVar28 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar22 = DAT_140539e60;
  uVar29 = (undefined2)(in_stack_ffffffffffffff20 >> 0x10);
  dVar20 = dVar20 * DAT_14053aba0;
  uVar25 = 0xff;
  if (param_1[5] == 0) {
    uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar10;
    dVar4 = DAT_140539fc8 - (double)(int)param_1[3] * dVar22;
    uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    in_stack_ffffffffffffff28._8_4_ = SUB84(dVar4,0);
    in_stack_ffffffffffffff28._0_8_ = dVar4;
    in_stack_ffffffffffffff28._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    in_stack_ffffffffffffff20 = in_stack_ffffffffffffff20 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff20,
                  in_stack_ffffffffffffff28,uVar25,uVar25,uVar25,uVar25,1,0);
    iVar15 = DAT_1407c7798;
    uVar28 = (undefined2)((uint)uStackX_c >> 0x10);
    uVar29 = (undefined2)(in_stack_ffffffffffffff20 >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4008000000000000;
      if (7 < iVar15) {
        *(undefined8 *)(param_1 + 0x12) = 0x4018000000000000;
      }
      uVar11 = DAT_140e418c8;
      if ((float)param_1[0xb] <= 0.0) {
        uVar17 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar17 = uVar17 * 0x800 ^ uVar17;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ DAT_140e9fd18 ^ uVar17;
        *(short *)(param_1 + 0x10) =
             (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 + 0x3a24;
      }
      if ((float)param_1[10] <= 0.0) {
        uVar17 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar17 = uVar17 * 0x800 ^ uVar17;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ DAT_140e9fd18 ^ uVar17;
        *(short *)(param_1 + 0x10) =
             (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 + -0x5dc;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        uVar17 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
        uVar11 = uVar17 * 0x800 ^ uVar17;
        DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ uVar11 ^ DAT_140e9fd18;
        *(short *)(param_1 + 0x10) =
             (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 + 0x7a24;
      }
      uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar10;
      uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
      param_1[3] = 0;
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[0x15] = 0;
    }
  }
  dVar4 = DAT_140539f40;
  uVar25 = SUB84(DAT_140539f40,0);
  uVar26 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  if (param_1[5] == 1) {
    iVar15 = param_1[3];
    dVar21 = (double)FUN_140332d90(((double)iVar15 - 0.0) * _DAT_14053a9b8 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar7 = dVar21 * dVar22 + dVar4;
    dVar21 = (double)FUN_140332d90();
    dVar21 = dVar21 * dVar22 + DAT_140539f58;
    uVar27 = (undefined4)((ulonglong)dVar21 >> 0x20);
    if (iVar15 < 200) {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar12 = ((int)dVar20 & 0xffffU) - (uint)uVar2;
      iVar9 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar9 = iVar12;
      }
      iVar12 = iVar9 + -0x10000;
      if (iVar9 < 0x8001) {
        iVar12 = iVar9;
      }
      uVar8 = (ushort)(int)dVar20;
      if (iVar12 < 1) {
        uVar13 = uVar2;
        if ((iVar12 < 0) && (uVar13 = uVar2 - 0xff, -0xff < iVar12)) {
          uVar13 = uVar8;
        }
      }
      else {
        uVar13 = uVar8;
        if (0xfe < iVar12) {
          uVar13 = uVar2 + 0xff;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar13;
    }
    pfVar16 = (float *)(param_1 + 10);
    pfVar14 = (float *)(param_1 + 0xb);
    dVar22 = *(double *)(param_1 + 0x12) + dVar22;
    *(double *)(param_1 + 0x12) = dVar22;
    dVar20 = (double)FUN_1403307c0();
    fVar24 = (float)(dVar20 * dVar22) + *pfVar16;
    *pfVar16 = fVar24;
    dVar20 = (double)FUN_140332d90();
    auVar5._8_4_ = SUB84(dVar21,0);
    auVar5._0_8_ = dVar21;
    auVar5._12_4_ = uVar27;
    fVar23 = (float)(dVar20 * dVar22) + *pfVar14;
    *pfVar14 = fVar23;
    FUN_1400c8410(DAT_140e4471c,0x4e,8,fVar24,fVar23,CONCAT22(uVar29,(short)iVar15 * 0x29a),auVar5,
                  0xff,0xff,0xff,0x80,1,0);
    auVar6._8_4_ = SUB84(dVar21,0);
    auVar6._0_8_ = dVar21;
    auVar6._12_4_ = uVar27;
    FUN_1400c8410(DAT_140e4471c,0x4e,8,*pfVar16,*pfVar14,*(short *)(param_1 + 3) * -0x29a,auVar6,
                  0xff,0xff,0xff,0x80,1,0);
    in_stack_ffffffffffffff28._8_8_ = dVar7;
    in_stack_ffffffffffffff28._0_8_ = dVar4;
    FUN_1400c8410(DAT_140e44718,0x4e,7,*pfVar16,*pfVar14,*(undefined2 *)(param_1 + 0x10),dVar4,dVar7
                  ,0xff,0xff,0xff,0xff,1,0);
    uVar27 = DAT_14053b358;
    FUN_140079c10(param_1,2);
    uVar28 = (undefined2)((uint)uVar27 >> 0x10);
  }
  iVar15 = DAT_140e419b8;
  if (0 < (int)param_1[7]) goto LAB_1400971ae;
  if (DAT_140e419b8 == 0) {
    uVar25 = (undefined4)DAT_14053a0d0;
    uVar26 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  }
  else if (DAT_140e419b8 == 1) {
LAB_140096f6f:
    uVar25 = (undefined4)DAT_14053a118;
    uVar26 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
  }
  else if (DAT_140e419b8 == 2) {
    uVar25 = (undefined4)DAT_14053a138;
    uVar26 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
  }
  else {
    if (DAT_140e419b8 == 3) goto LAB_140096f6f;
    if (DAT_140e419b8 == 4) {
      uVar25 = (undefined4)DAT_14053a158;
      uVar26 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    }
  }
  fVar23 = (float)param_1[10];
  fVar24 = (float)param_1[0xb];
  fVar18 = (float)FUN_140334430(fVar23 - DAT_140e445d8,DAT_140539fc0);
  fVar19 = (float)FUN_140334430(fVar24 - DAT_140e445dc);
  if (fVar18 + fVar19 < 0.0) {
    fVar18 = (float)FUN_1403352f8();
  }
  else {
    fVar18 = SQRT(fVar18 + fVar19);
  }
  if (DAT_14053acbc <= fVar18) {
    if (iVar15 == 0) {
      uVar11 = param_1[1] & 0x80000001;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
      }
      if (uVar11 == 1) goto LAB_14009718a;
    }
    auVar30._12_4_ = in_stack_ffffffffffffff28._12_4_;
    auVar30._0_8_ = in_stack_ffffffffffffff28._0_8_;
    auVar30._8_4_ = 1;
    auVar31._8_8_ = auVar30._8_8_;
    auVar31._0_8_ = CONCAT44(uVar26,uVar25);
    FUN_14006c2f0(9,2,fVar23,fVar24,CONCAT22(uVar28,*(undefined2 *)(param_1 + 0x10)),0,
                  CONCAT44(uVar26,uVar25),auVar31._8_8_,0);
    if (2 < DAT_140e419b8) {
      dVar22 = (double)CONCAT44(uVar26,uVar25) + DAT_140539fc8;
      auVar32._12_4_ = auVar31._12_4_;
      auVar32._0_8_ = auVar31._0_8_;
      auVar32._8_4_ = 1;
      auVar31._8_8_ = auVar32._8_8_;
      auVar31._0_8_ = dVar22;
      FUN_14006c2f0(9,2,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x10),0,dVar22,
                    auVar31._8_8_,0);
    }
    if (3 < DAT_140e419b8) {
      uVar27 = param_1[10];
      sVar3 = *(short *)(param_1 + 0x10);
      iVar15 = 0;
      uVar1 = param_1[0xb];
      do {
        auVar33._12_4_ = auVar31._12_4_;
        auVar33._0_8_ = auVar31._0_8_;
        auVar33._8_4_ = 1;
        auVar31._8_8_ = auVar33._8_8_;
        auVar31._0_8_ = CONCAT44(uVar26,uVar25);
        FUN_14006c2f0(9,2,uVar27,uVar1,(short)iVar15 * 0x1a0a + sVar3 + -0xd05,0,
                      CONCAT44(uVar26,uVar25),auVar31._8_8_,0);
        iVar15 = iVar15 + 1;
      } while (iVar15 < 2);
      dVar22 = (double)CONCAT44(uVar26,uVar25) + DAT_140539fc8;
      sVar3 = *(short *)(param_1 + 0x10);
      iVar15 = 0;
      uVar25 = param_1[0xb];
      uVar26 = param_1[10];
      do {
        auVar34._12_4_ = auVar31._12_4_;
        auVar34._0_8_ = auVar31._0_8_;
        auVar34._8_4_ = 1;
        auVar31._8_8_ = auVar34._8_8_;
        auVar31._0_8_ = dVar22;
        FUN_14006c2f0(9,2,uVar26,uVar25,(short)iVar15 * 0x1a0a + sVar3 + -0xd05,0,dVar22,
                      auVar31._8_8_,0);
        iVar15 = iVar15 + 1;
      } while (iVar15 < 2);
    }
  }
LAB_14009718a:
  FUN_14007b010(param_1,200,2);
  FUN_140079e20(param_1,0);
  *param_1 = 0;
LAB_1400971ae:
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


