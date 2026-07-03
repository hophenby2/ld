// Function: FUN_1400e8570 @ 1400e8570
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e8570(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  longlong lVar4;
  undefined1 auVar5 [16];
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  float fVar21;
  undefined4 in_stack_fffffffffffffee0;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined2 uVar24;
  undefined1 in_stack_fffffffffffffee8 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  int iStack_c4;
  undefined8 uStack_b0;
  
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffee0 >> 0x10);
  lVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        iStack_c4 = *(int *)(lVar4 + 0x14);
        uStack_b0 = *(undefined8 *)(lVar4 + 0x28);
      }
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  uVar18 = SUB84((double)uVar1 * DAT_14053a020 * DAT_140539d28,0);
  dVar3 = (double)FUN_1403307c0(uVar18);
  fVar21 = (float)(dVar3 * DAT_14053a3d0) + (float)param_1[10];
  dVar3 = (double)FUN_140332d90(uVar18);
  fVar20 = (float)(dVar3 * DAT_14053a3d0) + (float)param_1[0xb];
  dVar3 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - (float)param_1[0xb]),0),
                                SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  auVar5 = _DAT_14053bb20;
  uVar18 = (undefined4)DAT_14053bb20;
  uVar19 = DAT_14053bb20._4_4_;
  uVar14 = (uint)(dVar3 * DAT_14053aba0);
  param_1[0xb] = uStack_b0._4_4_ + (float)param_1[0xd];
  param_1[10] = (float)uStack_b0 + (float)param_1[0xc];
  if (param_1[5] == 0) {
    if (iStack_c4 != 1) goto LAB_1400e8c5e;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_1400e8c5e;
  iVar17 = param_1[1] - DAT_1407c77a0;
  iVar16 = (int)param_1[3] % 0x4b0;
  uVar6 = (ushort)uVar14;
  if (iVar16 < 0x168) {
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 0x46;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0x30;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar13 = 0x24;
    }
    uVar12 = 1;
    iVar17 = iVar13 * iVar17 + 0x5a;
    if (DAT_140e419b8 == 0) {
      uVar12 = 9;
    }
    else if (DAT_140e419b8 == 1) {
      uVar12 = 0xd;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      uVar12 = 0xf;
    }
    else if (DAT_140e419b8 == 4) {
      uVar12 = 0x11;
    }
    if (DAT_140e419b8 == 0) {
      uVar18 = (undefined4)DAT_14053a088;
      uVar19 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar18 = (undefined4)DAT_14053a0d0;
      uVar19 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar18 = (undefined4)DAT_14053a0f8;
      uVar19 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar18 = (undefined4)DAT_14053a118;
      uVar19 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar18 = (undefined4)DAT_14053a158;
      uVar19 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    }
    uVar7 = uVar6 - uVar1;
    uVar9 = (uint)uVar7;
    if (0x8000 < uVar7) {
      uVar9 = 0x10000 - uVar7;
    }
    iVar8 = (uVar14 & 0xffff) - (uint)uVar1;
    iVar11 = (int)uVar9 / 10 + 0x30;
    iVar10 = iVar8 + 0x10000;
    if (-0x8001 < iVar8) {
      iVar10 = iVar8;
    }
    iVar8 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar8 = iVar10;
    }
    if (iVar8 < 1) {
      uVar7 = uVar1;
      if ((iVar8 < 0) && (uVar7 = uVar6, iVar8 <= -iVar11)) {
        uVar7 = uVar1 - (short)iVar11;
      }
    }
    else {
      uVar7 = uVar6;
      if (iVar11 <= iVar8) {
        uVar7 = uVar1 + (short)iVar11;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar7;
    uVar23 = DAT_14053ac2c;
    if ((iVar16 < iVar17) ||
       (uVar2 = (longlong)(iVar16 - iVar17) % (longlong)(iVar13 * 2), (int)uVar2 != 0))
    goto LAB_1400e8c5e;
    auVar25._12_4_ = in_stack_fffffffffffffee8._12_4_;
    auVar25._0_8_ = in_stack_fffffffffffffee8._0_8_;
    auVar25._8_4_ = 1;
    auVar26._8_8_ = auVar25._8_8_;
    auVar26._0_8_ = CONCAT44(uVar19,uVar18);
    uVar22 = DAT_14053ac2c;
    FUN_1400709b0(0xc,uVar2 & 0xffffffff,fVar21,fVar20,uVar7,DAT_14053ac2c,CONCAT44(uVar19,uVar18),
                  auVar26._8_8_,uVar12,27000,0);
    uVar24 = (undefined2)((uint)uVar22 >> 0x10);
    if (2 < DAT_140e419b8) {
      auVar27._12_4_ = auVar26._12_4_;
      auVar27._0_8_ = auVar26._0_8_;
      auVar27._8_4_ = 1;
      FUN_1400709b0(0xc,0,fVar21,fVar20,*(undefined2 *)(param_1 + 0x10),uVar23,
                    (double)CONCAT44(uVar19,uVar18) + auVar5._0_8_,auVar27._8_8_,uVar12,27000,0);
      uVar24 = (undefined2)((uint)uVar23 >> 0x10);
    }
  }
  else {
    if (iVar16 < 0x302) goto LAB_1400e8c5e;
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 0xc;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 9;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 8;
    }
    else if (DAT_140e419b8 == 3) {
      iVar13 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      iVar13 = 5;
    }
    if (DAT_140e419b8 == 0) {
      uVar18 = (undefined4)DAT_14053a138;
      uVar19 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar18 = (undefined4)DAT_14053a178;
      uVar19 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar18 = (undefined4)DAT_14053a1b8;
      uVar19 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar18 = (undefined4)DAT_14053a1e8;
      uVar19 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar18 = (undefined4)DAT_14053a218;
      uVar19 = (undefined4)((ulonglong)DAT_14053a218 >> 0x20);
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar7 = uVar6 - uVar1;
    uVar9 = (uint)uVar7;
    if (0x8000 < uVar7) {
      uVar9 = 0x10000 - uVar7;
    }
    iVar8 = (uVar14 & 0xffff) - (uint)uVar1;
    iVar11 = (int)uVar9 / 10 + 0x30;
    iVar10 = iVar8 + 0x10000;
    if (-0x8001 < iVar8) {
      iVar10 = iVar8;
    }
    iVar8 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar8 = iVar10;
    }
    if (iVar8 < 1) {
      uVar7 = uVar1;
      if ((iVar8 < 0) && (uVar7 = uVar1 - (short)iVar11, -iVar11 < iVar8)) {
        uVar7 = uVar6;
      }
    }
    else {
      uVar7 = uVar6;
      if (iVar11 <= iVar8) {
        uVar7 = uVar1 + (short)iVar11;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar7;
    uVar12 = DAT_14053ac2c;
    if ((0x45f < iVar16) || ((iVar16 + -0x302) % iVar13 != 0)) goto LAB_1400e8c5e;
    uVar14 = iVar17 * 9999 + param_1[3];
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar14 = uVar14 * 0x800 ^ uVar14;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    if (iVar17 == 0) {
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
      uVar14 = DAT_140e9fd1c / 0x3e81;
      sVar15 = (short)DAT_140e9fd1c;
      iVar16 = 0;
      do {
        auVar28._12_4_ = in_stack_fffffffffffffee8._12_4_;
        auVar28._0_8_ = in_stack_fffffffffffffee8._0_8_;
        auVar28._8_4_ = 1;
        in_stack_fffffffffffffee8._8_8_ = auVar28._8_8_;
        in_stack_fffffffffffffee8._0_8_ = CONCAT44(uVar19,uVar18);
        uVar23 = uVar12;
        FUN_14006c2f0(0xd,7,fVar21,fVar20,
                      (short)iVar16 * 0x2ee + sVar15 + (short)uVar14 * -0x3e81 + uVar7 + -0x222e,
                      uVar12,CONCAT44(uVar19,uVar18),in_stack_fffffffffffffee8._8_8_,0);
        uVar24 = (undefined2)((uint)uVar23 >> 0x10);
        iVar16 = iVar16 + 1;
      } while (iVar16 < 3);
    }
    else {
      iVar16 = 0;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
      uVar14 = DAT_140e9fd1c / 0x3e81;
      sVar15 = (short)DAT_140e9fd1c;
      do {
        auVar29._12_4_ = in_stack_fffffffffffffee8._12_4_;
        auVar29._0_8_ = in_stack_fffffffffffffee8._0_8_;
        auVar29._8_4_ = 1;
        in_stack_fffffffffffffee8._8_8_ = auVar29._8_8_;
        in_stack_fffffffffffffee8._0_8_ = CONCAT44(uVar19,uVar18);
        uVar23 = uVar12;
        FUN_14006c2f0(0xc,7,fVar21,fVar20,
                      (short)iVar16 * 0x2ee + uVar7 + (short)uVar14 * -0x3e81 + sVar15 + -0x222e,
                      uVar12,CONCAT44(uVar19,uVar18),in_stack_fffffffffffffee8._8_8_,0);
        uVar24 = (undefined2)((uint)uVar23 >> 0x10);
        iVar16 = iVar16 + 1;
      } while (iVar16 < 3);
    }
  }
  FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
  FUN_14018a340(DAT_140e472a4,1,1);
LAB_1400e8c5e:
  FUN_1400c8410(DAT_140e44bc8,0x21,7,param_1[10],param_1[0xb],
                CONCAT22(uVar24,*(undefined2 *)(param_1 + 0x10)),auVar5,0xff,0xff,0xff,0xff,1,0);
  if (1 < iStack_c4) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


