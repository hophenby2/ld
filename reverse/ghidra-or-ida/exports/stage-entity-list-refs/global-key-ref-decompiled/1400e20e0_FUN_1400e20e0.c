// Function: FUN_1400e20e0 @ 1400e20e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e20e0(undefined4 *param_1)

{
  longlong *plVar1;
  ushort uVar2;
  double dVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort uVar9;
  short sVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  uint uVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  double dVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 in_stack_fffffffffffffe78;
  undefined2 uVar30;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined8 uStack_120;
  
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
  uStack_120._4_4_ = 0;
  uStack_120 = 0;
  if ((0 < DAT_140e44e6c) && (lVar5 = DAT_140e45d80, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar5 + 4) == DAT_140e44308) {
        uStack_120 = *(undefined8 *)(lVar5 + 0x18);
      }
      plVar1 = (longlong *)(lVar5 + 0x60);
      lVar5 = *plVar1;
    } while (*plVar1 != 0);
  }
  fVar25 = (float)param_1[0xb];
  fVar22 = (float)param_1[10];
  dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                 SUB84((double)(DAT_140e445d8 - fVar22),0));
  uVar14 = DAT_140e418c8;
  dVar17 = DAT_14053aba0;
  dVar3 = DAT_14053a020;
  dVar18 = DAT_140539d28;
  sVar13 = 0x8ae;
  sVar10 = (short)(int)(dVar15 * DAT_14053aba0);
  dVar15 = DAT_140539f40;
  if (param_1[5] == 0) {
    iVar4 = param_1[3];
    dVar15 = DAT_140539ec8;
    if ((-1 < iVar4) && (dVar15 = DAT_140539f40, iVar4 < 0x28)) {
      dVar15 = (double)FUN_140332d90(((double)iVar4 - 0.0) * DAT_14053a6d8 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar15 = dVar15 * DAT_140539f28 + DAT_140539ec8;
    }
    dVar21 = *(double *)(param_1 + 0x12) -
             (*(double *)(param_1 + 0x12) / DAT_14053a340) * (double)iVar4;
    dVar16 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar16 * dVar21) + fVar22;
    param_1[10] = fVar22;
    dVar16 = (double)FUN_140332d90();
    fVar25 = (float)(dVar16 * dVar21) + fVar25;
    param_1[0xb] = fVar25;
    if (iVar4 == 0) {
      *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
      goto LAB_1400e2a6b;
    }
    if (iVar4 != 0x28) goto LAB_1400e2a6b;
    if (param_1[6] == 0x7e) {
      param_1[3] = 0;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff3333333333333;
      param_1[5] = 1;
      param_1[0x15] = 0;
      uVar12 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar12 = uVar12 * 0x800 ^ uVar12;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
      *(short *)(param_1 + 0x10) =
           (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x115d) * -0x115d + sVar10 +
           -0x8ae;
    }
    else {
      if (param_1[6] == 0x7f) {
        *(undefined8 *)(param_1 + 0x12) = 0;
        *(undefined2 *)(param_1 + 0x10) = 0x4000;
        *(short *)(param_1 + 0x11) = sVar10;
      }
      param_1[3] = 0;
      param_1[5] = 1;
      param_1[0x15] = 0;
    }
  }
  else if (param_1[5] != 1) goto LAB_1400e2a6b;
  dVar16 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar16 * DAT_14053a238) + fVar22;
  dVar16 = (double)FUN_140332d90();
  fVar26 = (float)(dVar16 * DAT_14053a238) + fVar25;
  if (param_1[6] == 0x7e) {
    dVar16 = *(double *)(param_1 + 0x12);
    dVar21 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar21 * dVar16) + fVar22;
    dVar21 = (double)FUN_140332d90();
    uVar12 = param_1[3];
    param_1[0xb] = (float)(dVar21 * dVar16) + fVar25;
    fVar22 = DAT_140e445dc;
    fVar25 = DAT_140e445d8;
    iVar4 = DAT_140e419b8;
    if ((int)uVar12 < 0xb4) {
      if (0x95 < (int)uVar12) goto LAB_1400e2804;
      dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                     SUB84((double)(DAT_140e445d8 - fVar27),0));
      iVar4 = DAT_140e419b8;
      dVar16 = DAT_140539f40;
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 0x50;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar7 = 0x3c;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 0x32;
      }
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0xf;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0x18;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar6 = 0x1e;
      }
      uVar28 = (undefined4)DAT_14053a158;
      uVar29 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
      if (DAT_140e419b8 == 0) {
        uVar23 = (int)DAT_14053a118;
        uVar24 = (int)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else {
        uVar23 = uVar28;
        uVar24 = uVar29;
        if (DAT_140e419b8 != 1) {
          if (DAT_140e419b8 == 2) {
            uVar23 = (int)DAT_14053a178;
            uVar24 = (int)((ulonglong)DAT_14053a178 >> 0x20);
          }
          else if (DAT_140e419b8 == 3) {
            uVar23 = SUB84(DAT_14053a1b8,0);
            uVar24 = (int)((ulonglong)DAT_14053a1b8 >> 0x20);
          }
          else {
            uVar23 = SUB84(DAT_140539f40,0);
            uVar24 = (int)((ulonglong)DAT_140539f40 >> 0x20);
            if (DAT_140e419b8 == 4) {
              uVar23 = (int)DAT_14053a1e8;
              uVar24 = (int)((ulonglong)DAT_14053a1e8 >> 0x20);
            }
          }
        }
      }
      if ((uVar12 < 0x96) && ((int)uVar12 % iVar7 == 0)) {
        *(short *)(param_1 + 0x11) = (short)(int)(dVar21 * dVar17);
        fVar22 = DAT_140e445dc;
        fVar25 = DAT_140e445d8;
      }
      uVar19 = SUB84(DAT_140539e60,0);
      uVar20 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
      if ((((0x95 < (uint)param_1[3]) || (iVar7 = (int)param_1[3] % iVar7, iVar6 <= iVar7)) ||
          ((iVar7 != (iVar7 / 3 + (iVar7 >> 0x1f) +
                     (int)(((longlong)iVar7 / 3 + ((longlong)iVar7 >> 0x3f) & 0xffffffffU) >> 0x1f))
                     * 3 ||
           (((dVar16 = DAT_140539f40, fVar27 < fVar25 / DAT_14053ab70 + DAT_14053aca8 ||
             (fVar25 / DAT_14053ab70 + DAT_14053aea8 < fVar27)) || (fVar26 < DAT_14053aca8)))))) ||
         (DAT_14053aef4 < fVar26)) goto LAB_1400e2783;
      fVar25 = (float)FUN_140334430(fVar27 - fVar25,DAT_140539fc0);
      fVar22 = (float)FUN_140334430(fVar26 - fVar22);
      if (fVar25 + fVar22 < 0.0) {
        fVar25 = (float)FUN_1403352f8();
      }
      else {
        fVar25 = SQRT(fVar25 + fVar22);
      }
      if (DAT_14053acbc < fVar25) {
        auVar31._12_4_ = in_stack_fffffffffffffe88._12_4_;
        auVar31._0_8_ = in_stack_fffffffffffffe88._0_8_;
        auVar31._8_4_ = 1;
        in_stack_fffffffffffffe88._8_8_ = auVar31._8_8_;
        in_stack_fffffffffffffe88._0_8_ = CONCAT44(uVar24,uVar23);
        uVar19 = CONCAT22(uVar30,*(undefined2 *)(param_1 + 0x11));
        FUN_14006c2f0(7,0,fVar27,fVar26,uVar19,DAT_14053ac2c,CONCAT44(uVar24,uVar23),
                      in_stack_fffffffffffffe88._8_8_,0);
        uVar30 = (undefined2)((uint)uVar19 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar14 = DAT_140e418c8;
        iVar4 = DAT_140e419b8;
      }
      goto LAB_1400e276b;
    }
    uVar19 = SUB84(DAT_140539e60,0);
    uVar20 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
    uVar28 = (undefined4)DAT_14053a158;
    uVar29 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    *(double *)(param_1 + 0x12) = dVar16 + DAT_140539e60;
    dVar16 = DAT_140539f40;
  }
  else {
LAB_1400e2804:
    uVar28 = (undefined4)DAT_14053a158;
    uVar29 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    iVar4 = DAT_140e419b8;
LAB_1400e276b:
    uVar19 = SUB84(DAT_140539e60,0);
    uVar20 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
    dVar16 = DAT_140539f40;
  }
LAB_1400e2783:
  fVar25 = DAT_14053ab70;
  if (param_1[6] == 0x7f) {
    uVar2 = *(ushort *)(param_1 + 0x10);
    uVar9 = sVar10 - uVar2;
    uVar12 = (uint)uVar9;
    if (0x8000 < uVar9) {
      uVar12 = 0x10000 - uVar9;
    }
    iVar8 = (int)uVar12 / 10 + 0x30;
    uVar9 = *(ushort *)(param_1 + 0x11);
    iVar6 = (uint)uVar9 - (uint)uVar2;
    iVar7 = iVar6 + 0x10000;
    if (-0x8001 < iVar6) {
      iVar7 = iVar6;
    }
    iVar6 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar6 = iVar7;
    }
    if (iVar6 < 1) {
      uVar11 = uVar2;
      if ((iVar6 < 0) && (uVar11 = uVar2 - (short)iVar8, -iVar8 < iVar6)) {
        uVar11 = uVar9;
      }
    }
    else {
      uVar11 = uVar9;
      if (iVar8 <= iVar6) {
        uVar11 = uVar2 + (short)iVar8;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
    *(ushort *)((longlong)param_1 + 0x42) = uVar11;
    if (0x1d < (int)param_1[3]) {
      if (iVar4 == 0) {
        dVar17 = (double)CONCAT44(uVar29,uVar28);
      }
      else {
        dVar17 = DAT_14053a1b8;
        if (((iVar4 != 1) && (dVar17 = DAT_14053a208, iVar4 != 2)) &&
           ((iVar4 == 3 || (dVar17 = dVar16, iVar4 == 4)))) {
          dVar17 = DAT_14053a240;
        }
      }
      iVar4 = param_1[3] + -0x1e;
      *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + (double)CONCAT44(uVar20,uVar19);
      if (iVar4 == (iVar4 / 3 + (iVar4 >> 0x1f) +
                   (int)(((longlong)iVar4 / 3 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                   3) {
        if ((((DAT_140e445d8 / fVar25 + 0.0 <= (float)param_1[10]) &&
             ((float)param_1[10] <= DAT_140e445d8 / fVar25 + DAT_14053aec0)) &&
            (0.0 <= (float)param_1[0xb])) && ((float)param_1[0xb] <= DAT_14053af14)) {
          auVar32._12_4_ = in_stack_fffffffffffffe88._12_4_;
          auVar32._0_8_ = in_stack_fffffffffffffe88._0_8_;
          auVar32._8_4_ = 1;
          in_stack_fffffffffffffe88._8_8_ = auVar32._8_8_;
          in_stack_fffffffffffffe88._0_8_ = dVar17;
          FUN_14006c2f0(4,3,fVar27,fVar26,CONCAT22(uVar30,uVar11),0,dVar17,
                        in_stack_fffffffffffffe88._8_8_,0);
          if (0 < DAT_140e419b8) {
            uVar19 = 1;
            if (DAT_140e419b8 == 0) {
              uVar19 = 0;
            }
            else if (DAT_140e419b8 == 1) {
              uVar19 = 0x4b0;
            }
            else if (DAT_140e419b8 == 2) {
              uVar19 = 0x708;
            }
            else if (DAT_140e419b8 == 3) {
              uVar19 = 0x960;
            }
            else if (DAT_140e419b8 == 4) {
              uVar19 = 3000;
            }
            auVar33._12_4_ = in_stack_fffffffffffffe88._12_4_;
            auVar33._0_8_ = in_stack_fffffffffffffe88._0_8_;
            auVar33._8_4_ = 1;
            in_stack_fffffffffffffe88._8_8_ = auVar33._8_8_;
            in_stack_fffffffffffffe88._0_8_ = dVar17 - DAT_140539f00;
            FUN_1400709b0(4,3,fVar27,fVar26,*(undefined2 *)((longlong)param_1 + 0x42),0,
                          dVar17 - DAT_140539f00,in_stack_fffffffffffffe88._8_8_,2,uVar19,0);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          uVar14 = DAT_140e418c8;
        }
      }
    }
    dVar17 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar17 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar17 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar17 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  }
LAB_1400e2a6b:
  uVar20 = (undefined4)((ulonglong)dVar15 >> 0x20);
  uVar19 = SUB84(dVar15,0);
  fVar25 = (float)dVar15 * _DAT_14053b334;
  dVar17 = (double)FUN_1403307c0();
  fVar22 = (float)(dVar17 * (double)fVar25) + (float)param_1[10];
  dVar17 = (double)FUN_140332d90();
  auVar34._12_4_ = in_stack_fffffffffffffe88._12_4_;
  auVar34._0_8_ = in_stack_fffffffffffffe88._0_8_;
  auVar34._8_4_ = 0x66;
  auVar35._4_12_ = auVar34._4_12_;
  auVar35._0_4_ = 0x67;
  uVar12 = 0;
  fVar25 = (float)(dVar17 * (double)fVar25) + (float)param_1[0xb];
  iVar4 = FUN_1400c9580(uVar14,0,3,4,0x65,0x66,auVar35);
  if (param_1[6] == 0x7f) {
    auVar36._12_4_ = auVar35._12_4_;
    auVar36._0_8_ = auVar35._0_8_;
    auVar36._8_4_ = 0x6a;
    auVar35._4_12_ = auVar36._4_12_;
    auVar35._0_4_ = 0x6b;
    uVar12 = 0;
    iVar4 = FUN_1400c9580(uVar14,0,3,4,0x69,0x6a,auVar35);
  }
  uVar30 = (undefined2)(uVar12 >> 0x10);
  if (param_1[6] == 0x7e) {
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar12 = uVar12 & 0xffff0000;
    FUN_1400c8410((&DAT_140e44660)[iVar4],0x23,7,param_1[10],param_1[0xb],uVar12,auVar35,0xff,0xff,
                  0xff,0xff,1,0);
    uVar30 = (undefined2)(uVar12 >> 0x10);
  }
  if (param_1[6] == 0x7f) {
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar28 = CONCAT22(uVar30,*(short *)((longlong)param_1 + 0x42) + -0x4000);
    FUN_1400c8410((&DAT_140e44660)[iVar4],0x23,7,param_1[10],param_1[0xb],uVar28,auVar35,0xff,0xff,
                  0xff,0xff,1,0);
    uVar30 = (undefined2)((uint)uVar28 >> 0x10);
  }
  sVar10 = *(short *)(param_1 + 3) * 0xc80;
  if (param_1[6] == 0x7e) {
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar28 = CONCAT22(uVar30,sVar10);
    FUN_1400c8410(DAT_140e44800,0x23,7,fVar22,fVar25,uVar28,auVar35,0xff,0xff,0xff,0xff,1,0);
    uVar30 = (undefined2)((uint)uVar28 >> 0x10);
  }
  dVar16 = DAT_14053a798;
  dVar17 = DAT_14053a2d8;
  if (param_1[6] == 0x7f) {
    if ((param_1[5] == 1) && (iVar4 = param_1[3], 0x1d < iVar4)) {
      if (iVar4 < 0x3c) {
        dVar21 = (double)FUN_140332d90(((double)iVar4 - DAT_14053a2d8) * DAT_14053a798 * dVar3 *
                                       dVar18);
        sVar13 = 0x4000 - (short)(int)(dVar21 * _DAT_14053abd0);
      }
      dVar21 = (double)FUN_140332d90();
      sVar10 = (short)(int)(dVar21 * _DAT_14053a8f0) + *(short *)((longlong)param_1 + 0x42) + sVar13
               + -0x8000;
    }
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar28 = CONCAT22(uVar30,sVar10);
    FUN_1400c8410(DAT_140e44810,0x23,7,fVar22,fVar25,uVar28,auVar35,0xff,0xff,0xff,0xff,1,0);
    uVar30 = (undefined2)((uint)uVar28 >> 0x10);
  }
  sVar10 = (short)param_1[3] * 0xc80 + -0x8000;
  if (param_1[6] == 0x7e) {
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar28 = CONCAT22(uVar30,sVar10);
    FUN_1400c8410(DAT_140e44800,0x23,7,fVar22,fVar25,uVar28,auVar35,0xff,0xff,0xff,0xff,1,0);
    uVar30 = (undefined2)((uint)uVar28 >> 0x10);
  }
  if (param_1[6] == 0x7f) {
    if ((param_1[5] == 1) && (iVar4 = param_1[3], 0x1d < iVar4)) {
      sVar10 = -0x8ae;
      if (iVar4 < 0x3c) {
        dVar18 = (double)FUN_140332d90(((double)iVar4 - dVar17) * dVar16 * dVar3 * dVar18);
        sVar10 = -0x4000 - (short)(int)(dVar18 * _DAT_14053b308);
      }
      dVar18 = (double)FUN_140332d90();
      sVar10 = (short)(int)(dVar18 * _DAT_14053b2a0) + *(short *)((longlong)param_1 + 0x42) + sVar10
               + -0x8000;
    }
    auVar35._8_4_ = uVar19;
    auVar35._0_8_ = dVar15;
    auVar35._12_4_ = uVar20;
    uVar19 = CONCAT22(uVar30,sVar10);
    FUN_1400c8410(DAT_140e44810,0x23,7,fVar22,fVar25,uVar19,auVar35,0xff,0xff,0xff,0xff,1,0);
    uVar30 = (undefined2)((uint)uVar19 >> 0x10);
  }
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
  fVar25 = DAT_14053b380;
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,1);
    FUN_140079e20(param_1,0);
    if (DAT_140e44654 == 0) {
      auVar37._12_4_ = auVar35._12_4_;
      auVar37._0_8_ = auVar35._0_8_;
      auVar37._8_4_ = 10;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,fVar25,fVar25,CONCAT22(uVar30,0x4000),DAT_140539f40,
                 auVar37._8_8_,1,DAT_140e44308);
    }
    *param_1 = 0;
  }
  if ((uStack_120._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad1c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af04 < (float)param_1[10])) ||
      ((float)param_1[0xb] < fVar25)) || (DAT_14053af54 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


