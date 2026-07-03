// Function: FUN_140057f90 @ 140057f90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140057f90(undefined4 *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  longlong lVar8;
  undefined8 uVar9;
  short sVar10;
  undefined8 uVar11;
  short sVar12;
  int iVar13;
  short *psVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined8 local_res8;
  undefined4 in_stack_fffffffffffffe78;
  undefined2 uVar28;
  undefined4 uVar27;
  uint in_stack_fffffffffffffe80;
  ushort uVar29;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  int iStack_11c;
  undefined8 uStack_110;
  
  dVar20 = DAT_14053a020;
  dVar19 = DAT_140539f40;
  uVar29 = (ushort)(in_stack_fffffffffffffe80 >> 0x10);
  iStack_11c = 0;
  iVar13 = 0;
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_11c = iVar13, lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == DAT_140e44308) {
        iStack_11c = *(int *)(lVar8 + 0x1c);
        uStack_110 = *(undefined8 *)(lVar8 + 0x28);
      }
      iVar13 = iStack_11c;
    }
  }
  uVar25 = SUB84(DAT_140539d28,0);
  uVar26 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  if (param_1[5] == 0) {
    iVar13 = param_1[3];
    if (iVar13 == 0) {
      param_1[0xc] = (undefined4)uStack_110;
      param_1[0xd] = uStack_110._4_4_;
    }
    dVar15 = (double)FUN_140332d90();
    fVar23 = (float)param_1[0xe];
    fVar24 = (float)param_1[0xc];
    fVar21 = (float)param_1[0xc];
    dVar16 = (double)FUN_140332d90();
    fVar22 = (float)param_1[0xf];
    fVar2 = (float)param_1[0xd];
    fVar3 = (float)param_1[0xd];
    dVar17 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a798 * dVar20 * DAT_140539d28);
    dVar17 = (double)((float)(dVar17 * DAT_14053a460) + 0.0);
    dVar18 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar18 * dVar17) + (float)(dVar15 * (double)(fVar23 - fVar24)) + fVar21;
    dVar15 = (double)FUN_140332d90();
    param_1[10] = fVar23;
    param_1[0xb] = (float)(dVar15 * dVar17) + (float)(dVar16 * (double)(fVar22 - fVar2)) + fVar3;
    uVar25 = SUB84(DAT_140539d28,0);
    uVar26 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    if (iVar13 < 0) {
      dVar19 = 0.0;
    }
    else if (iVar13 < 0x3c) {
      dVar19 = (double)FUN_140332d90();
      dVar19 = dVar19 + 0.0;
    }
    in_stack_fffffffffffffe78 = param_1[0xb];
    in_stack_fffffffffffffe88._8_4_ = SUB84(dVar19,0);
    in_stack_fffffffffffffe88._0_8_ = dVar19;
    in_stack_fffffffffffffe88._12_4_ = (int)((ulonglong)dVar19 >> 0x20);
    in_stack_fffffffffffffe80 = (uint)uVar29 << 0x10;
    FUN_1400c8410(DAT_140e44904,0x24,7,fVar23,in_stack_fffffffffffffe78,in_stack_fffffffffffffe80,
                  in_stack_fffffffffffffe88,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x3c) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  uVar28 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
  if (0 < (int)param_1[5]) {
    piVar1 = param_1 + 3;
    if (param_1[6] == 0x105) {
      if (*piVar1 == 0) {
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
      dVar15 = *(double *)(param_1 + 0x12) + DAT_140539e98;
      *(double *)(param_1 + 0x12) = dVar15;
      dVar17 = (double)FUN_1403307c0();
      fVar24 = (float)(dVar17 * dVar15) + (float)param_1[10];
      param_1[10] = fVar24;
      dVar17 = (double)FUN_140332d90();
      fVar23 = (float)(dVar17 * dVar15) + (float)param_1[0xb];
      param_1[0xb] = fVar23;
      if (*piVar1 == 0x10) {
        dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),
                                       SUB84((double)(DAT_140e445d8 - fVar24),0));
        auVar30._12_4_ = in_stack_fffffffffffffe88._12_4_;
        auVar30._0_8_ = in_stack_fffffffffffffe88._0_8_;
        auVar30._8_4_ = 1;
        in_stack_fffffffffffffe88._8_8_ = auVar30._8_8_;
        in_stack_fffffffffffffe88._0_8_ = DAT_14053a138;
        uVar27 = CONCAT22(uVar28,(short)(int)(dVar17 * DAT_14053aba0));
        FUN_14006c2f0(3,2,fVar24,fVar23,uVar27,0,DAT_14053a138,in_stack_fffffffffffffe88._8_8_,0);
        uVar28 = (undefined2)((uint)uVar27 >> 0x10);
      }
      auVar31._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar31._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar31._8_4_ = 1;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = auVar31._8_8_;
      in_stack_fffffffffffffe88 = auVar5 << 0x40;
      in_stack_fffffffffffffe80 = 0;
      in_stack_fffffffffffffe78 = CONCAT22(uVar28,*(undefined2 *)(param_1 + 0x10));
      FUN_14006c2f0(4,0xf,param_1[10],param_1[0xb],in_stack_fffffffffffffe78,0,0,auVar31._8_8_,0);
    }
    uVar28 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
    if (param_1[6] == 0x106) {
      if (*piVar1 == 0) {
        uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xfffffff6);
        uVar27 = DAT_140e472d4;
        local_res8._0_4_ = (float)uVar11;
        local_res8._4_4_ = (undefined4)((ulonglong)uVar11 >> 0x20);
        param_1[10] = (float)local_res8;
        param_1[0xb] = local_res8._4_4_;
        FUN_140184700(DAT_140e44190 * 0x13,uVar27);
        FUN_14018a340(DAT_140e472d4,1,1);
        local_res8 = uVar11;
      }
      sVar12 = *(short *)(param_1 + 0x10);
      dVar17 = (double)FUN_140332d90(((double)*piVar1 - 0.0) * DAT_14053a798 * dVar20 *
                                     (double)CONCAT44(uVar26,uVar25));
      dVar20 = _DAT_14053a690;
      if ((float)param_1[0xe] <= DAT_14053ae30 && DAT_14053ae30 != (float)param_1[0xe]) {
        dVar20 = _DAT_14053b228;
      }
      sVar12 = (short)(int)(dVar17 * dVar20) + sVar12;
      *(short *)(param_1 + 0x10) = sVar12;
      dVar20 = (double)FUN_1403307c0();
      fVar24 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar24;
      dVar20 = (double)FUN_140332d90();
      auVar32._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar32._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar32._8_4_ = 1;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = auVar32._8_8_;
      in_stack_fffffffffffffe88 = auVar6 << 0x40;
      in_stack_fffffffffffffe80 = 0;
      in_stack_fffffffffffffe78 = CONCAT22(uVar28,sVar12);
      fVar23 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar23;
      FUN_14006c2f0(4,0x10,fVar24,fVar23,in_stack_fffffffffffffe78,0,0,auVar32._8_8_,0);
    }
    fVar23 = DAT_14053ab70;
    uVar28 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
    if (param_1[6] == 0x107) {
      if (param_1[3] == 0) {
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
      dVar17 = *(double *)(param_1 + 0x12) + DAT_140539e40;
      sVar12 = *(short *)(param_1 + 0x10);
      *(double *)(param_1 + 0x12) = dVar17;
      dVar20 = (double)FUN_1403307c0();
      fVar24 = (float)(dVar20 * dVar17) + (float)param_1[10];
      param_1[10] = fVar24;
      dVar20 = (double)FUN_140332d90();
      fVar21 = (float)(dVar20 * dVar17) + (float)param_1[0xb];
      param_1[0xb] = fVar21;
      if ((param_1[5] == 1) && (DAT_140539da8 <= fVar21)) {
        fVar22 = DAT_140e445d8 / fVar23;
        if ((fVar24 < fVar22 + 0.0) ||
           (((fVar22 + DAT_14053aec0 < fVar24 || (fVar21 < 0.0)) || (DAT_14053af14 < fVar21)))) {
          sVar10 = -0x8000 - sVar12;
          if (fVar24 < fVar22 + 0.0) {
            sVar12 = sVar10;
          }
          if (fVar22 + DAT_14053aec0 < fVar24) {
            sVar12 = sVar10;
          }
          *(short *)(param_1 + 0x10) = sVar12;
          uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0);
          param_1[5] = param_1[5] + 1;
          local_res8._0_4_ = (float)uVar11;
          local_res8._4_4_ = (undefined4)((ulonglong)uVar11 >> 0x20);
          param_1[10] = (float)local_res8;
          param_1[0xb] = local_res8._4_4_;
          fVar24 = (float)local_res8;
          local_res8 = uVar11;
        }
      }
      auVar33._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar33._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar33._8_4_ = 1;
      auVar7._8_8_ = 0;
      auVar7._0_8_ = auVar33._8_8_;
      in_stack_fffffffffffffe88 = auVar7 << 0x40;
      in_stack_fffffffffffffe80 = 0;
      in_stack_fffffffffffffe78 = CONCAT22(uVar28,sVar12);
      FUN_14006c2f0(4,0x10,fVar24,param_1[0xb],in_stack_fffffffffffffe78,0,0,auVar33._8_8_,0);
    }
    psVar14 = (short *)(param_1 + 0x10);
    iVar13 = param_1[6];
    if (iVar13 - 0x108U < 2) {
      sVar12 = *psVar14;
      dVar20 = (double)FUN_1403307c0();
      fVar21 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar21;
      dVar20 = (double)FUN_140332d90();
      uVar28 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
      fVar24 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar24;
      if (iVar13 == 0x108) {
        *psVar14 = sVar12 + 0x400;
        local_res8._0_2_ = sVar12 + 0x4400;
      }
      else if (iVar13 == 0x109) {
        *psVar14 = sVar12 + -0x400;
        local_res8._0_2_ = sVar12 + -0x4400;
      }
      uVar25 = DAT_14053ac2c;
      uVar11 = DAT_14053a0b0;
      if ((-1 < (int)param_1[3]) && ((param_1[3] & 1) == 0)) {
        iVar13 = 0;
        do {
          auVar34._12_4_ = in_stack_fffffffffffffe88._12_4_;
          auVar34._0_8_ = in_stack_fffffffffffffe88._0_8_;
          auVar34._8_4_ = 1;
          in_stack_fffffffffffffe88._8_8_ = auVar34._8_8_;
          in_stack_fffffffffffffe88._0_8_ = uVar11;
          in_stack_fffffffffffffe78 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe78 >> 0x10),
                        (short)iVar13 * -0x8000 + (short)local_res8 + 0x4000);
          FUN_14006c2f0(0xd,3,fVar21,fVar24,in_stack_fffffffffffffe78,uVar25,uVar11,
                        in_stack_fffffffffffffe88._8_8_,0);
          uVar9 = DAT_14053a110;
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
        uVar26 = param_1[0xb];
        uVar27 = param_1[10];
        iVar13 = 0;
        do {
          auVar35._12_4_ = in_stack_fffffffffffffe88._12_4_;
          auVar35._0_8_ = in_stack_fffffffffffffe88._0_8_;
          auVar35._8_4_ = 1;
          in_stack_fffffffffffffe88._8_8_ = auVar35._8_8_;
          in_stack_fffffffffffffe88._0_8_ = uVar9;
          in_stack_fffffffffffffe78 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe78 >> 0x10),
                        (short)iVar13 * 0x4000 + (short)local_res8 + 0x6000);
          FUN_14006c2f0(0xd,3,uVar27,uVar26,in_stack_fffffffffffffe78,uVar25,uVar9,
                        in_stack_fffffffffffffe88._8_8_,0);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
        auVar36._12_4_ = in_stack_fffffffffffffe88._12_4_;
        auVar36._0_8_ = in_stack_fffffffffffffe88._0_8_;
        auVar36._8_4_ = 1;
        in_stack_fffffffffffffe88._8_8_ = auVar36._8_8_;
        in_stack_fffffffffffffe88._0_8_ = uVar11;
        uVar25 = CONCAT22((short)((uint)in_stack_fffffffffffffe78 >> 0x10),(short)local_res8);
        FUN_14006c2f0(0xd,3,param_1[10],param_1[0xb],uVar25,0,uVar11,in_stack_fffffffffffffe88._8_8_
                      ,0);
        uVar28 = (undefined2)((uint)uVar25 >> 0x10);
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      auVar37._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar37._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar37._8_4_ = 1;
      in_stack_fffffffffffffe80 = 0;
      FUN_14006c2f0(4,0x10,param_1[10],param_1[0xb],CONCAT22(uVar28,*(undefined2 *)(param_1 + 0x10))
                    ,0,0,auVar37._8_8_,0);
      if (param_1[3] == 0x40) {
        *param_1 = 0;
      }
    }
    auVar4._8_4_ = SUB84(dVar19,0);
    auVar4._0_8_ = dVar19;
    auVar4._12_4_ = (int)((ulonglong)dVar19 >> 0x20);
    FUN_1400c8410(DAT_140e44904,0x24,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffe80 & 0xffff0000,auVar4,0xff,0xff,0xff,0xff,1,0);
    fVar23 = DAT_140e445d8 / fVar23;
    if ((((float)param_1[10] < fVar23 - DAT_14053ad9c) ||
        (fVar23 + DAT_14053af38 < (float)param_1[10])) ||
       (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
      *param_1 = 0;
    }
  }
  if ((iStack_11c < 1) || (DAT_140e4430c < 1)) {
    *param_1 = 0;
  }
  return;
}


