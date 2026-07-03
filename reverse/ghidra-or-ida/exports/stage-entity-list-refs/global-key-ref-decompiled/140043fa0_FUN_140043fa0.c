// Function: FUN_140043fa0 @ 140043fa0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140043fa0(undefined4 *param_1)

{
  float *pfVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  longlong lVar4;
  double dVar5;
  double dVar6;
  undefined8 uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  double dVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 uVar21;
  undefined2 uVar22;
  undefined4 in_stack_fffffffffffffe90;
  float fVar23;
  undefined2 uVar25;
  uint uVar24;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined8 local_118;
  undefined8 uStack_100;
  
  dVar17 = DAT_14053a020;
  dVar15 = DAT_140539d28;
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffe90 >> 0x10);
  lVar4 = DAT_140e45d80;
  iVar9 = local_118._4_4_;
  if (0 < DAT_140e44e6c) {
    for (; iVar9 = (int)((ulonglong)local_118 >> 0x20), lVar4 != 0;
        lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        local_118 = *(undefined8 *)(lVar4 + 0x10);
        uStack_100 = *(undefined8 *)(lVar4 + 0x28);
      }
    }
  }
  local_118._4_4_ = iVar9;
  sVar8 = (short)(int)*(double *)(param_1 + 0x12);
  dVar12 = (double)FUN_140332d90();
  dVar6 = DAT_14053a890;
  dVar5 = DAT_140539f40;
  dVar12 = dVar12 * _DAT_14053aa58;
  iVar9 = param_1[3];
  if (iVar9 < 0) {
    dVar13 = DAT_140539e60;
    dVar14 = 0.0;
  }
  else {
    dVar13 = DAT_140539f40;
    if (iVar9 < 0x14) {
      dVar13 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053a890 * dVar17 * dVar15);
      dVar13 = dVar13 * DAT_140539f38 + DAT_140539e60;
    }
    if (iVar9 < 10) {
      dVar14 = 0.0;
    }
    else {
      dVar14 = dVar5;
      if (iVar9 < 0x1e) {
        dVar14 = (double)FUN_140332d90(((double)iVar9 - DAT_14053a1e8) * dVar6 * dVar17 * dVar15);
        dVar14 = dVar14 + 0.0;
      }
    }
  }
  uVar18 = (undefined4)((ulonglong)dVar13 >> 0x20);
  iVar11 = param_1[6];
  if ((iVar11 - 0xb1U & 0xfffffffd) == 0) {
    sVar8 = -sVar8;
    dVar12 = (double)FUN_140332d90();
    dVar12 = dVar12 * _DAT_14053b2d8;
  }
  if (param_1[5] != 0) goto LAB_1400447af;
  pfVar1 = (float *)(param_1 + 0xc);
  if (iVar9 == 0) {
    *pfVar1 = 0.0;
LAB_1400441a8:
    dVar15 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053a798 * dVar17 * dVar15);
    *pfVar1 = (float)(dVar15 * DAT_14053a598) + 0.0;
  }
  else if (iVar9 < 0x1e) {
    if (-1 < iVar9) goto LAB_1400441a8;
    *pfVar1 = 0.0;
  }
  else if (param_1[0x15] == 1) {
    param_1[0x15] = 0;
  }
  fVar23 = *pfVar1;
  fVar16 = fVar23 * DAT_140539d20;
  sVar8 = sVar8 + *(short *)(param_1 + 0x10);
  *(short *)(param_1 + 0x10) = sVar8;
  uVar7 = FUN_140133f30((float)uStack_100 + (float)param_1[0xe],
                        uStack_100._4_4_ + (float)param_1[0xf],(int)dVar12 & 0xffff,sVar8,fVar16,
                        fVar23);
  iVar10 = DAT_140e419b8;
  dVar12 = DAT_14053a0f8;
  dVar6 = DAT_14053a0b0;
  dVar17 = DAT_14053a088;
  dVar15 = DAT_14053a018;
  uVar25 = (undefined2)((uint)fVar23 >> 0x10);
  uVar22 = (undefined2)((uint)fVar16 >> 0x10);
  uVar19 = SUB84(DAT_14053a088,0);
  uVar20 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
  local_res8 = (undefined4)uVar7;
  uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
  param_1[10] = local_res8;
  param_1[0xb] = uStackX_c;
  if (iVar11 - 0xb0U < 2) {
    iVar11 = 1;
    if (iVar10 == 0) {
      iVar11 = 0x14;
    }
    else if (iVar10 == 1) {
      iVar11 = 0xb;
    }
    else if (iVar10 == 2) {
      iVar11 = 9;
    }
    else if (iVar10 == 3) {
      iVar11 = 7;
    }
    else if (iVar10 == 4) {
      iVar11 = 6;
    }
    if ((((iVar10 != 0) && (dVar15 = DAT_14053a070, iVar10 != 1)) && (dVar15 = dVar17, iVar10 != 2))
       && ((dVar15 = dVar6, iVar10 != 3 && (dVar15 = dVar5, iVar10 == 4)))) {
      dVar15 = dVar12;
    }
    dVar17 = (double)iVar9 * _DAT_140539d98 + dVar15;
    dVar15 = DAT_14053a018;
    if ((0x31 < iVar9) && ((iVar9 + -0x32) % iVar11 == 0)) {
      uVar19 = param_1[0xb];
      iVar9 = 0;
      do {
        auVar26._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar26._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar26._8_4_ = 1;
        in_stack_fffffffffffffe98._8_8_ = auVar26._8_8_;
        in_stack_fffffffffffffe98._0_8_ = dVar17;
        uVar25 = 0;
        fVar16 = (float)CONCAT22((short)((uint)fVar16 >> 0x10),
                                 (short)iVar9 * 0x15b3 + sVar8 + -0xad9);
        FUN_14006c2f0(1,0,local_res8,uVar19,fVar16,0,dVar17,in_stack_fffffffffffffe98._8_8_,0);
        uVar22 = (undefined2)((uint)fVar16 >> 0x10);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 2);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar19 = SUB84(DAT_14053a088,0);
      uVar20 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
      dVar15 = DAT_14053a018;
      dVar12 = DAT_14053a0f8;
      iVar10 = DAT_140e419b8;
    }
  }
  if (param_1[6] - 0xb2 < 2) {
    iVar9 = 1;
    if (iVar10 == 0) {
      iVar9 = 0x12;
    }
    else if (iVar10 == 1) {
LAB_140044455:
      iVar9 = 0xb;
    }
    else {
      if (iVar10 != 2) {
        if (iVar10 == 3) goto LAB_140044455;
        if (iVar10 != 4) goto LAB_140044463;
      }
      iVar9 = 10;
    }
LAB_140044463:
    iVar11 = 1;
    if (iVar10 == 0) {
      iVar11 = 3;
    }
    else if ((iVar10 == 1) || (iVar10 == 2)) {
      iVar11 = 5;
    }
    else if ((iVar10 == 3) || (iVar10 == 4)) {
      iVar11 = 7;
    }
    dVar17 = DAT_14053a078;
    if ((((iVar10 != 0) && (dVar17 = dVar6, iVar10 != 1)) && (dVar17 = DAT_14053a0d0, iVar10 != 2))
       && ((dVar17 = dVar12, iVar10 != 3 && (dVar17 = dVar5, iVar10 == 4)))) {
      dVar17 = DAT_14053a138;
    }
    iVar9 = (param_1[3] + -0x32) % iVar9;
    dVar17 = (double)iVar9 * DAT_140539ed8 + dVar17;
    if ((0x31 < (int)param_1[3]) && (iVar9 < iVar11)) {
      auVar27._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar27._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar27._8_4_ = 1;
      in_stack_fffffffffffffe98._8_8_ = auVar27._8_8_;
      in_stack_fffffffffffffe98._0_8_ = dVar17;
      uVar25 = 0;
      uVar21 = CONCAT22(uVar22,*(undefined2 *)(param_1 + 0x10));
      FUN_14006c2f0(1,0,param_1[10],param_1[0xb],uVar21,0,dVar17,in_stack_fffffffffffffe98._8_8_,0);
      uVar22 = (undefined2)((uint)uVar21 >> 0x10);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar10 = DAT_140e419b8;
    }
  }
  if ((0x1d < (int)param_1[3]) && (iVar9 = param_1[3] + -0x1e, iVar9 == (iVar9 / 0x48) * 0x48)) {
    if (((iVar10 != 0) &&
        (((dVar15 = DAT_14053a040, iVar10 != 1 && (dVar15 = DAT_14053a070, iVar10 != 2)) &&
         (iVar10 != 3)))) && (dVar15 = dVar5, iVar10 == 4)) {
      dVar15 = (double)CONCAT44(uVar20,uVar19);
    }
    auVar28._12_4_ = in_stack_fffffffffffffe98._12_4_;
    auVar28._0_8_ = in_stack_fffffffffffffe98._0_8_;
    auVar28._8_4_ = 1;
    uVar25 = 0;
    FUN_14006c2f0(5,2,param_1[10],param_1[0xb],CONCAT22(uVar22,*(short *)(param_1 + 0x10) + -0x8000)
                  ,0,dVar15,auVar28._8_8_,0);
  }
  auVar3._8_4_ = SUB84(dVar14,0);
  auVar3._0_8_ = dVar14;
  auVar3._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
  uVar24 = CONCAT22(uVar25,*(short *)(param_1 + 3) * 0x309);
  FUN_1400c8410(DAT_140e44884,0x24,7,param_1[10],param_1[0xb],uVar24,auVar3,0xff,0xff,0xff,0xff,1,0)
  ;
  auVar2._8_4_ = SUB84(dVar13,0);
  auVar2._0_8_ = dVar13;
  auVar2._12_4_ = uVar18;
  uVar24 = uVar24 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar24,auVar2,0xff,0xff,0xff,0xff,1,0)
  ;
  dVar15 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                 DAT_140539d28);
  in_stack_fffffffffffffe98._8_4_ = SUB84(dVar13,0);
  in_stack_fffffffffffffe98._0_8_ = dVar13;
  in_stack_fffffffffffffe98._12_4_ = uVar18;
  uVar24 = uVar24 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar24,in_stack_fffffffffffffe98,0xff,
                0xff,0xff,0x80 - (int)(dVar15 * DAT_14053b1c8),1,0);
  uVar22 = (undefined2)(uVar24 >> 0x10);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
LAB_1400447af:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,2);
    if (DAT_140e44600 == 0) {
      auVar29._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar29._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar29._8_4_ = 10;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar22,0x4000),dVar5,
                 auVar29._8_8_,1,DAT_140e44308);
    }
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((param_1[3] == 0xfa) || (0x1d < local_118._4_4_)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053adb4) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af48 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3d0 || (_DAT_14053af88 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


