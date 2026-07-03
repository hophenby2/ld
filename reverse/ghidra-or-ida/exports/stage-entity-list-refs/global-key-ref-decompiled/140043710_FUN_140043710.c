// Function: FUN_140043710 @ 140043710
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140043710(undefined4 *param_1)

{
  undefined1 auVar1 [16];
  short sVar2;
  longlong lVar3;
  double dVar4;
  double dVar5;
  undefined4 uVar6;
  float fVar7;
  undefined8 uVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float local_res8;
  float fStackX_c;
  double local_res10;
  undefined4 in_stack_fffffffffffffe80;
  undefined4 uVar21;
  undefined2 uVar23;
  uint uVar22;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  int iStack_124;
  
  dVar4 = DAT_14053a020;
  dVar15 = DAT_140539d28;
  uVar23 = (undefined2)((uint)in_stack_fffffffffffffe80 >> 0x10);
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == DAT_140e44308) {
        iStack_124 = *(int *)(lVar3 + 0x14);
      }
    }
  }
  uVar22 = param_1[3];
  sVar10 = ((ushort)((int)uVar22 >> 0x1f) & 0x154) + 0x3c;
  if (uVar22 < 0x3c) {
    dVar14 = (double)FUN_140332d90(((double)(int)uVar22 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar19 = (undefined4)DAT_140539f40;
    uVar20 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    sVar10 = 400 - (short)(int)(dVar14 * _DAT_14053a680);
LAB_1400437fb:
    dVar5 = DAT_14053a890;
    dVar14 = (double)CONCAT44(uVar20,uVar19);
    if (uVar22 < 0x14) {
      dVar14 = (double)FUN_140332d90(((double)(int)uVar22 - 0.0) * DAT_14053a890 * dVar4 * dVar15);
      dVar14 = dVar14 * DAT_140539f38 + DAT_140539e60;
    }
    local_res10 = (double)CONCAT44(uVar20,uVar19);
    if ((int)uVar22 < 10) {
      local_res10 = 0.0;
    }
    else if ((int)uVar22 < 0x1e) {
      local_res10 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a1e8) * dVar5 * dVar4 *
                                          dVar15);
      local_res10 = local_res10 + 0.0;
    }
  }
  else {
    uVar19 = (undefined4)DAT_140539f40;
    uVar20 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    if (-1 < (int)uVar22) goto LAB_1400437fb;
    local_res10 = 0.0;
    dVar14 = DAT_140539e60;
  }
  fVar7 = DAT_14053accc;
  fVar13 = DAT_14053ab70;
  if (param_1[5] != 0) goto LAB_140043e69;
  if (uVar22 == 0) {
LAB_140043904:
    dVar15 = (double)FUN_140332d90(((double)(int)uVar22 - 0.0) * DAT_14053a798 * dVar4 * dVar15);
    fVar16 = (float)(dVar15 * DAT_14053a598) + 0.0;
    param_1[0xc] = fVar16;
  }
  else {
    fVar16 = (float)param_1[0xc];
    if ((int)uVar22 < 0x1e) {
      if (-1 < (int)uVar22) goto LAB_140043904;
      fVar16 = 0.0;
      param_1[0xc] = 0;
    }
    else {
      if (param_1[0x15] == 1) {
        param_1[0x15] = 0;
      }
      if (0x3b < (int)uVar22) {
        fVar16 = ((float)(int)uVar22 - fVar7) * _DAT_140539ce8 + fVar16;
        param_1[0xc] = fVar16;
      }
    }
  }
  uVar23 = (undefined2)((uint)fVar16 >> 0x10);
  param_1[0xd] = (float)param_1[0xd] + DAT_140539cd8;
  if (param_1[6] != 0xae) {
    sVar10 = -sVar10;
  }
  *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar10;
  uVar8 = FUN_140133f30();
  iVar11 = DAT_140e419b8;
  iVar12 = 1;
  local_res8 = (float)uVar8;
  fStackX_c = (float)((ulonglong)uVar8 >> 0x20);
  param_1[10] = local_res8;
  param_1[0xb] = fStackX_c;
  if (iVar11 == 0) {
    iVar12 = 0x11;
  }
  else if (iVar11 == 1) {
    iVar12 = 0xb;
  }
  else if (iVar11 == 2) {
LAB_140043a16:
    iVar12 = 9;
  }
  else if (iVar11 == 3) {
    iVar12 = 10;
  }
  else if (iVar11 == 4) goto LAB_140043a16;
  if (iVar11 == 0) {
    uVar17 = (undefined4)DAT_14053a070;
    uVar18 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
  }
  else if (iVar11 == 1) {
    uVar17 = (undefined4)DAT_14053a0b0;
    uVar18 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
  }
  else if (iVar11 == 2) {
    uVar17 = (undefined4)DAT_14053a0f8;
    uVar18 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
  }
  else if (iVar11 == 3) {
    uVar17 = (undefined4)DAT_14053a0d0;
    uVar18 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  }
  else {
    uVar17 = uVar19;
    uVar18 = uVar20;
    if (iVar11 == 4) {
      uVar17 = (undefined4)DAT_14053a118;
      uVar18 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    }
  }
  if ((0x3b < (int)uVar22) && ((int)(uVar22 - 0x3c) % iVar12 == 0)) {
    fVar13 = (float)FUN_140334430(fStackX_c - DAT_140e445dc,DAT_140539fc0);
    fVar7 = DAT_140e445d8;
    fVar16 = (float)FUN_140334430(local_res8 - DAT_140e445d8);
    if (fVar13 + fVar16 < 0.0) {
      fVar16 = (float)FUN_1403352f8();
    }
    else {
      fVar16 = SQRT(fVar13 + fVar16);
    }
    uVar6 = DAT_14053ac2c;
    fVar13 = DAT_14053ab70;
    if ((((DAT_14053accc <= fVar16) && (fVar7 / DAT_14053ab70 + 0.0 <= local_res8)) &&
        (local_res8 <= fVar7 / DAT_14053ab70 + DAT_14053aec0)) &&
       ((0.0 <= fStackX_c && (fStackX_c <= DAT_14053af14)))) {
      iVar11 = 0;
      sVar10 = *(short *)(param_1 + 0x10);
      sVar9 = *(short *)(param_1 + 3) * 0x50 + -0x12c0;
      sVar2 = -sVar9;
      if (param_1[6] != 0xaf) {
        sVar2 = sVar9;
      }
      do {
        auVar24._12_4_ = in_stack_fffffffffffffe88._12_4_;
        auVar24._0_8_ = in_stack_fffffffffffffe88._0_8_;
        auVar24._8_4_ = 1;
        in_stack_fffffffffffffe88._8_8_ = auVar24._8_8_;
        in_stack_fffffffffffffe88._0_8_ = CONCAT44(uVar18,uVar17);
        uVar21 = uVar6;
        FUN_14006c2f0(7,2,local_res8,fStackX_c,(short)iVar11 * -0x8000 + sVar10 + sVar2,uVar6,
                      CONCAT44(uVar18,uVar17),in_stack_fffffffffffffe88._8_8_,0);
        uVar23 = (undefined2)((uint)uVar21 >> 0x10);
        iVar11 = iVar11 + 1;
      } while (iVar11 < 2);
      if (2 < DAT_140e419b8) {
        dVar15 = (double)CONCAT44(uVar18,uVar17) + DAT_140539f68;
        uVar17 = param_1[0xb];
        iVar11 = 0;
        uVar18 = param_1[10];
        do {
          auVar25._12_4_ = in_stack_fffffffffffffe88._12_4_;
          auVar25._0_8_ = in_stack_fffffffffffffe88._0_8_;
          auVar25._8_4_ = 1;
          in_stack_fffffffffffffe88._8_8_ = auVar25._8_8_;
          in_stack_fffffffffffffe88._0_8_ = dVar15;
          uVar21 = uVar6;
          FUN_14006c2f0(7,2,uVar18,uVar17,(short)iVar11 * -0x8000 + sVar10 + sVar2,uVar6,dVar15,
                        in_stack_fffffffffffffe88._8_8_,0);
          uVar23 = (undefined2)((uint)uVar21 >> 0x10);
          iVar11 = iVar11 + 1;
        } while (iVar11 < 2);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      fVar13 = DAT_14053ab70;
    }
  }
  uVar17 = (undefined4)((ulonglong)dVar14 >> 0x20);
  uVar22 = CONCAT22(uVar23,*(short *)(param_1 + 3) * 0x309);
  FUN_1400c8410(DAT_140e44884,0x24,7,param_1[10],param_1[0xb],uVar22,local_res10,local_res10,0xff,
                0xff,0xff,0xff,1,0);
  auVar1._8_4_ = SUB84(dVar14,0);
  auVar1._0_8_ = dVar14;
  auVar1._12_4_ = uVar17;
  uVar22 = uVar22 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar22,auVar1,0xff,0xff,0xff,0xff,1,0)
  ;
  dVar15 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                 DAT_140539d28);
  in_stack_fffffffffffffe88._8_4_ = SUB84(dVar14,0);
  in_stack_fffffffffffffe88._0_8_ = dVar14;
  in_stack_fffffffffffffe88._12_4_ = uVar17;
  uVar22 = uVar22 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar22,in_stack_fffffffffffffe88,0xff,
                0xff,0xff,0x80 - (int)(dVar15 * DAT_14053b1c8),1,0);
  uVar23 = (undefined2)(uVar22 >> 0x10);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
LAB_140043e69:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,2);
    if (DAT_140e44600 == 0) {
      auVar26._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar26._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar26._8_4_ = 10;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar23,0x4000),
                 CONCAT44(uVar20,uVar19),auVar26._8_8_,1,DAT_140e44308);
    }
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (9 < iStack_124) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / fVar13 - DAT_14053adb4) ||
      (DAT_140e445d8 / fVar13 + DAT_14053af48 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3d0 || (_DAT_14053af88 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


