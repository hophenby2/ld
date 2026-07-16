// Function: FUN_14009c530 @ 14009c530
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009c530(undefined4 *param_1)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  double dVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined8 *puVar8;
  double dVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined8 local_138;
  undefined8 uStack_130;
  int iStack_124;
  undefined8 uStack_110;
  
  dVar9 = DAT_14053a020;
  dVar17 = DAT_140539f40;
  dVar19 = DAT_140539d28;
  local_138 = 0;
  local_138._0_4_ = 0;
  puVar8 = DAT_140e45d80;
  iVar11 = uStack_130._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar11 = (int)((ulonglong)uStack_130 >> 0x20);
      if (puVar8 == (undefined8 *)0x0) break;
      if (*(int *)((longlong)puVar8 + 4) == param_1[2]) {
        local_138 = *puVar8;
        uStack_130 = puVar8[1];
        iStack_124 = *(int *)((longlong)puVar8 + 0x14);
        uStack_110 = puVar8[5];
      }
      puVar8 = (undefined8 *)puVar8[0xc];
    }
  }
  uStack_130._4_4_ = iVar11;
  iVar11 = param_1[5];
  iVar12 = 0xff;
  iVar14 = 0xff;
  uVar24 = DAT_140539fc0;
  if (iVar11 == 0) {
    if (param_1[3] == 0) {
      param_1[10] = (float)uStack_110;
      param_1[0xb] = uStack_110._4_4_;
      uVar24 = DAT_14053ad40;
      if (param_1[6] == 0x50) {
        auVar25._12_4_ = in_stack_fffffffffffffe88._12_4_;
        auVar25._0_8_ = in_stack_fffffffffffffe88._0_8_;
        auVar25._8_4_ = 100;
        auVar26._8_8_ = auVar25._8_8_;
        auVar26._0_8_ = dVar17;
        stage_entity_spawn_candidate
                  (0x51,99999999,0,DAT_14053accc,DAT_14053ad40,0x4000,dVar17,auVar26._8_8_,1,
                   param_1[1]);
        auVar27._12_4_ = auVar26._12_4_;
        auVar27._0_8_ = auVar26._0_8_;
        auVar27._8_4_ = 100;
        auVar28._8_8_ = auVar27._8_8_;
        auVar28._0_8_ = dVar17;
        stage_entity_spawn_candidate
                  (0x51,99999999,0,DAT_14053b360,uVar24,0x4000,dVar17,auVar28._8_8_,1,param_1[1]);
        uVar24 = DAT_14053b358;
        auVar29._12_4_ = auVar28._12_4_;
        auVar29._0_8_ = auVar28._0_8_;
        auVar29._8_4_ = 100;
        auVar30._8_8_ = auVar29._8_8_;
        auVar30._0_8_ = dVar17;
        stage_entity_spawn_candidate
                  (0x52,99999999,0,DAT_14053ace8,DAT_14053b358,0x4000,dVar17,auVar30._8_8_,1,
                   param_1[1]);
        auVar31._12_4_ = auVar30._12_4_;
        auVar31._0_8_ = auVar30._0_8_;
        auVar31._8_4_ = 100;
        stage_entity_spawn_candidate
                  (0x52,99999999,0,DAT_14053b36c,uVar24,0x4000,dVar17,auVar31._8_8_,1,param_1[1]);
        iVar11 = param_1[5];
      }
    }
    dVar4 = DAT_14053a5f8;
    uVar3 = param_1[3];
    uVar13 = (int)uVar3 >> 0x1f;
    if ((int)uVar3 < 0) {
      iVar14 = (uVar13 & 0xffffff01) + 0xff;
      dVar17 = 0.0;
      iVar12 = iVar14;
    }
    else {
      if ((int)uVar3 < 100) {
        dVar17 = (double)FUN_140332d90(((double)(int)uVar3 - 0.0) * DAT_14053a530 * dVar9 * dVar19);
        dVar17 = dVar17 + 0.0;
        iVar14 = (uVar13 & 0xffffff01) + 0xff;
        dVar18 = (double)FUN_140332d90(((double)(int)uVar3 - 0.0) * DAT_14053a530 * dVar9 * dVar19);
        iVar12 = (int)(dVar18 * dVar4);
      }
      else {
        iVar14 = (uVar13 & 0xffffff01) + 0xff;
        iVar12 = iVar14;
      }
      if (uVar3 < 10) {
        dVar18 = (double)FUN_140332d90(((double)(int)uVar3 - 0.0) * DAT_14053a9d8 * dVar9 * dVar19);
        iVar14 = (int)(dVar18 * dVar4);
      }
    }
    fVar16 = (float)param_1[0xb];
    fVar15 = (float)param_1[10];
    fVar20 = (float)dVar17 * (float)param_1[0xc] + (float)uStack_110;
    fVar21 = (float)dVar17 * (float)param_1[0xd] + uStack_110._4_4_;
    FUN_1403300b4((double)(fVar21 - fVar16),SUB84((double)(fVar20 - fVar15),0));
    fVar20 = (float)FUN_140334430(fVar15 - fVar20,DAT_140539fc0);
    fVar21 = (float)FUN_140334430(fVar16 - fVar21);
    if (fVar20 + fVar21 < 0.0) {
      fVar20 = (float)FUN_1403352f8();
    }
    else {
      fVar20 = SQRT(fVar20 + fVar21);
    }
    dVar4 = (double)fVar20 / DAT_14053a0b0;
    dVar18 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar18 * dVar4) + fVar15;
    dVar18 = (double)FUN_140332d90();
    uVar24 = DAT_140539fc0;
    param_1[0xb] = (float)(dVar18 * dVar4) + fVar16;
    if (uVar3 == 100) {
      iVar11 = iVar11 + 1;
      param_1[3] = 0;
      param_1[5] = iVar11;
    }
  }
  uVar23 = (undefined4)((ulonglong)dVar17 >> 0x20);
  uVar22 = SUB84(dVar17,0);
  pfVar1 = (float *)(param_1 + 0xb);
  pfVar2 = (float *)(param_1 + 10);
  if (iVar11 == 1) {
    fVar16 = (float)param_1[0xd];
    fVar15 = (float)param_1[0xc];
    fVar20 = *pfVar1;
    fVar21 = *pfVar2;
    FUN_1403300b4((double)((uStack_110._4_4_ + fVar16) - fVar20),
                  SUB84((double)(((float)uStack_110 + fVar15) - fVar21),0));
    fVar15 = (float)FUN_140334430(fVar21 - ((float)uStack_110 + fVar15),uVar24);
    fVar16 = (float)FUN_140334430(fVar20 - (uStack_110._4_4_ + fVar16));
    if (fVar15 + fVar16 < 0.0) {
      fVar16 = (float)FUN_1403352f8();
    }
    else {
      fVar16 = SQRT(fVar15 + fVar16);
    }
    dVar4 = (double)fVar16 / DAT_14053a0b0;
    dVar18 = (double)FUN_1403307c0();
    *pfVar2 = (float)(dVar18 * dVar4) + fVar21;
    dVar18 = (double)FUN_140332d90();
    *pfVar1 = (float)(dVar18 * dVar4) + fVar20;
  }
  if ((((param_1[6] == 0x50) &&
       (auVar5._8_4_ = uVar22, auVar5._0_8_ = dVar17, auVar5._12_4_ = uVar23,
       FUN_1400c8410(DAT_140e44970,0x1f,7,*pfVar2,*pfVar1,0,auVar5,iVar12,iVar12,iVar12,iVar14,1,0),
       param_1[5] == 1)) && (iStack_124 == 2)) && (uStack_130._4_4_ == 0x3c)) {
    *param_1 = 0;
  }
  dVar4 = DAT_14053a808;
  if (param_1[6] == 0x51) {
    dVar18 = ((double)DAT_140e418c8 - _DAT_14053a3c0) * DAT_14053a808 * dVar9 * dVar19;
    if ((float)param_1[0xc] < 0.0) {
      dVar18 = (double)FUN_140332d90(dVar18);
      dVar18 = dVar18 * _DAT_14053b278;
      uVar24 = DAT_140e44978;
    }
    else {
      dVar18 = (double)FUN_140332d90(dVar18);
      dVar18 = dVar18 * DAT_14053a840;
      uVar24 = DAT_140e44974;
    }
    auVar6._8_4_ = uVar22;
    auVar6._0_8_ = dVar17;
    auVar6._12_4_ = uVar23;
    FUN_1400c8410(uVar24,0x1e,7,param_1[10],param_1[0xb],(short)(int)dVar18,auVar6,iVar12,iVar12,
                  iVar12,iVar14,1,0);
  }
  if (param_1[6] == 0x52) {
    dVar19 = ((double)DAT_140e418c8 - _DAT_14053a300) * dVar4 * dVar9 * dVar19;
    if ((float)param_1[0xc] < 0.0) {
      dVar19 = (double)FUN_140332d90(dVar19);
      sVar10 = (short)(int)(dVar19 * _DAT_14053b298) + -10000;
      uVar24 = DAT_140e44980;
    }
    else {
      dVar19 = (double)FUN_140332d90(dVar19);
      sVar10 = (short)(int)(dVar19 * _DAT_14053a8b8) + 10000;
      uVar24 = DAT_140e4497c;
    }
    auVar7._8_4_ = uVar22;
    auVar7._0_8_ = dVar17;
    auVar7._12_4_ = uVar23;
    FUN_1400c8410(uVar24,0x1e,7,param_1[10],param_1[0xb],sVar10,auVar7,iVar12,iVar12,iVar12,iVar14,1
                  ,0);
  }
  if ((int)local_138 == 0) {
    *param_1 = 0;
  }
  return;
}


