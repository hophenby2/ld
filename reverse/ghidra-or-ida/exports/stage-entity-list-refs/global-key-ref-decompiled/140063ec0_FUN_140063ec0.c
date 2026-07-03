// Function: FUN_140063ec0 @ 140063ec0
// Decompile completed: true

void FUN_140063ec0(undefined4 *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  longlong lVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  undefined4 uVar20;
  float fVar21;
  undefined4 in_stack_fffffffffffffeb0;
  undefined2 uVar23;
  undefined4 uVar22;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined8 uStack_100;
  undefined8 local_f8;
  
  dVar4 = DAT_14053a020;
  dVar18 = DAT_140539d28;
  uVar23 = (undefined2)((uint)in_stack_fffffffffffffeb0 >> 0x10);
  lVar3 = DAT_140e45d80;
  iVar8 = uStack_100._4_4_;
  iVar7 = local_f8._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar8 = (int)((ulonglong)uStack_100 >> 0x20);
      iVar7 = (int)((ulonglong)local_f8 >> 0x20);
      if (lVar3 == 0) break;
      if (*(int *)(lVar3 + 4) == param_1[2]) {
        uStack_100 = *(undefined8 *)(lVar3 + 8);
        local_f8 = *(undefined8 *)(lVar3 + 0x10);
      }
      lVar3 = *(longlong *)(lVar3 + 0x60);
    }
  }
  local_f8._4_4_ = iVar7;
  uStack_100._4_4_ = iVar8;
  iVar8 = param_1[3];
  if (iVar8 < 0) {
    dVar15 = 0.0;
  }
  else {
    dVar15 = DAT_140539f40;
    if (iVar8 < 10) {
      dVar15 = (double)FUN_140332d90(((double)iVar8 - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar15 = dVar15 + 0.0;
    }
  }
  uVar20 = (undefined4)((ulonglong)dVar15 >> 0x20);
  dVar16 = (double)FUN_1403307c0();
  fVar21 = (float)(dVar16 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar21;
  dVar17 = (double)FUN_140332d90();
  fVar6 = DAT_14053ac94;
  fVar5 = DAT_14053a378;
  dVar16 = DAT_140539fc8;
  fVar19 = (float)(dVar17 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar19;
  if (param_1[6] == 0x123) {
    if (iVar8 < 10) {
      dVar17 = 0.0;
    }
    else {
      dVar17 = dVar16;
      if (iVar8 < 0x32) {
        dVar17 = (double)FUN_140332d90(((double)iVar8 - DAT_14053a1e8) * DAT_14053a6d8 * dVar4 *
                                       dVar18);
        dVar17 = dVar17 + dVar17 + 0.0;
      }
    }
    *(double *)(param_1 + 0x12) = dVar17;
    dVar17 = (double)FUN_140332d90(((double)iVar8 - 0.0) * DAT_14053a900 * dVar4 * dVar18);
    auVar25._8_4_ = SUB84(dVar15,0);
    auVar25._0_8_ = dVar15;
    auVar25._12_4_ = uVar20;
    uVar22 = CONCAT22(uVar23,(short)(int)(dVar17 * DAT_14053aa78));
    FUN_1400c8410(DAT_140e44e3c,0x23,7,fVar21,fVar19,uVar22,auVar25,0xff,0xff,0xff,0xff,1,0);
    uVar23 = (undefined2)((uint)uVar22 >> 0x10);
    if (param_1[3] == 0x46) {
      uVar13 = 5;
      uVar12 = uStack_100._4_4_ + 0x14a;
      do {
        fVar21 = (float)(int)uVar13 * fVar6;
        uVar14 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
        iVar8 = (int)(fVar21 * fVar5);
        if (uVar13 < 4) {
          DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar9 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
          uVar11 = 3;
        }
        else {
          DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar9 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
          uVar11 = 2;
        }
        DAT_140e9fd18 = uVar9 * 0x6c078965 + 4;
        auVar24._12_4_ = auVar25._12_4_;
        auVar24._0_8_ = auVar25._0_8_;
        auVar24._8_4_ = 1;
        uVar14 = uVar14 * 0x800 ^ uVar14;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = auVar24._8_8_;
        auVar25 = auVar1 << 0x40;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
        fVar19 = (float)CONCAT22((short)((uint)fVar19 >> 0x10),
                                 (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
        FUN_1400709b0(uVar11,0x3a,param_1[10],param_1[0xb],fVar19,fVar21,0,auVar24._8_8_,
                      (int)((iVar8 >> 0x1f & 0xfU) + iVar8) >> 4,0x10000,0);
        uVar13 = uVar13 - 1;
        uVar12 = uVar12 - 0x42;
      } while (0 < (int)uVar13);
      auVar26._12_4_ = auVar25._12_4_;
      auVar26._0_8_ = auVar25._0_8_;
      auVar26._8_4_ = 1;
      uVar23 = 0;
      FUN_14006c2f0(3,0x3a,param_1[10],param_1[0xb],(uint)fVar19 & 0xffff0000,0,0,auVar26._8_8_,0);
      FUN_140079e20(param_1,1);
      *param_1 = 0;
    }
  }
  if (param_1[6] == 0x124) {
    iVar8 = param_1[3];
    if (iVar8 < 10) {
      dVar16 = 0.0;
    }
    else if (iVar8 < 0x1e) {
      dVar16 = (double)FUN_140332d90(((double)iVar8 - DAT_14053a1e8) * DAT_14053a890 * dVar4 *
                                     dVar18);
      dVar16 = dVar16 + dVar16 + 0.0;
    }
    *(double *)(param_1 + 0x12) = dVar16;
    dVar18 = (double)FUN_140332d90(((double)iVar8 - 0.0) * DAT_14053a998 * dVar4 * dVar18);
    uVar12 = param_1[0xb];
    auVar28._8_4_ = SUB84(dVar15,0);
    auVar28._0_8_ = dVar15;
    auVar28._12_4_ = uVar20;
    FUN_1400c8410(DAT_140e44e40,0x23,7,param_1[10],uVar12,
                  CONCAT22(uVar23,(short)(int)(dVar18 * DAT_14053aa78)),auVar28,0xff,0xff,0xff,0xff,
                  1,0);
    if (param_1[3] == 0x32) {
      uVar14 = 3;
      uVar13 = uStack_100._4_4_ + 0xc6;
      do {
        fVar19 = (float)(int)uVar14 * fVar6;
        uVar9 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
        iVar8 = (int)(fVar19 * fVar5);
        if (uVar14 < 3) {
          DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar10 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
          uVar11 = 3;
        }
        else {
          DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar10 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
          uVar11 = 2;
        }
        DAT_140e9fd18 = uVar10 * 0x6c078965 + 4;
        auVar27._12_4_ = auVar28._12_4_;
        auVar27._0_8_ = auVar28._0_8_;
        auVar27._8_4_ = 1;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        auVar2._8_8_ = 0;
        auVar2._0_8_ = auVar27._8_8_;
        auVar28 = auVar2 << 0x40;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
        uVar12 = CONCAT22((short)(uVar12 >> 0x10),
                          (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
        FUN_1400709b0(uVar11,0x3b,param_1[10],param_1[0xb],uVar12,fVar19,0,auVar27._8_8_,
                      (int)((iVar8 >> 0x1f & 0xfU) + iVar8) >> 4,0x10000,0);
        uVar14 = uVar14 - 1;
        uVar13 = uVar13 - 0x42;
      } while (0 < (int)uVar14);
      auVar29._12_4_ = auVar28._12_4_;
      auVar29._0_8_ = auVar28._0_8_;
      auVar29._8_4_ = 1;
      FUN_14006c2f0(3,0x3b,param_1[10],param_1[0xb],uVar12 & 0xffff0000,0,0,auVar29._8_8_,0);
      FUN_140079e20(param_1,0);
      *param_1 = 0;
    }
  }
  if (local_f8._4_4_ == 99) {
    if (param_1[6] == 0x123) {
      FUN_140079e20(param_1,1);
    }
    if (param_1[6] == 0x124) {
      FUN_140079e20(param_1,0);
    }
    *param_1 = 0;
  }
  return;
}


