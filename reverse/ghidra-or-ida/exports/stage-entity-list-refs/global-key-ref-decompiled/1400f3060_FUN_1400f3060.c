// Function: FUN_1400f3060 @ 1400f3060
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400f3060(undefined4 *param_1)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  double dVar4;
  double dVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  short sVar14;
  int iVar15;
  ushort uVar16;
  short sVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  int local_res10;
  undefined2 local_res18;
  ulonglong in_stack_fffffffffffffdd8;
  undefined8 uVar27;
  undefined4 uVar28;
  undefined4 in_stack_fffffffffffffde0;
  undefined2 uVar30;
  undefined4 uVar29;
  double in_stack_fffffffffffffde8;
  longlong local_1d0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_150;
  undefined8 local_148;
  
  iVar11 = DAT_140e418c8;
  dVar5 = DAT_14053a020;
  dVar20 = DAT_140539d28;
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == DAT_140e44308) {
        uStack_150 = *(undefined8 *)(lVar3 + 8);
        local_148 = *(undefined8 *)(lVar3 + 0x10);
      }
    }
  }
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == param_1[2]) {
        uStack_198 = *(undefined8 *)(lVar3 + 0x28);
        local_190 = *(undefined8 *)(lVar3 + 0x30);
      }
    }
  }
  iVar15 = param_1[6];
  fVar25 = (float)uStack_198 + (float)param_1[0xe];
  fVar23 = uStack_198._4_4_ + (float)param_1[0xf];
  local_res10 = 3000;
  iVar13 = 0x514;
  local_res18 = 0;
  uVar30 = local_res18;
  local_res18 = 0;
  local_1d0 = 0xae;
  iVar10 = 0x514;
  switch(iVar15) {
  case 0xe4:
    dVar18 = (double)FUN_1403307c0(0x5770,2000,1000);
    fVar25 = (float)(dVar18 * DAT_14053a3d0) + (float)local_190;
    dVar18 = (double)FUN_140332d90();
    fVar23 = (float)(dVar18 * DAT_14053a3d0) + local_190._4_4_;
    dVar20 = (double)FUN_140332d90(((double)iVar11 - _DAT_14053b180) * DAT_14053a7f8 * dVar5 *
                                   dVar20);
    local_1d0 = 0xae;
    local_res18 = (short)(int)(dVar20 * DAT_14053a888);
    break;
  case 0xe5:
    dVar18 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar18 * DAT_14053a620) + (float)uStack_198;
    dVar18 = (double)FUN_140332d90();
    fVar23 = (float)(dVar18 * DAT_14053a620) + uStack_198._4_4_;
    dVar20 = (double)FUN_140332d90(((double)iVar11 - _DAT_14053b178) * DAT_14053a7f8 * dVar5 *
                                   dVar20);
    local_1d0 = 0xaf;
    local_res18 = (undefined2)(int)(dVar20 * DAT_14053a6d0);
    iVar10 = iVar13;
    break;
  case 0xe6:
    dVar18 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar18 * DAT_14053a3a0) + (float)local_190;
    dVar18 = (double)FUN_140332d90();
    fVar23 = (float)(dVar18 * DAT_14053a3a0) + local_190._4_4_;
    dVar20 = (double)FUN_140332d90(((double)iVar11 - _DAT_14053b180) * DAT_14053a7f8 * dVar5 *
                                   dVar20);
    local_1d0 = 0xb0;
    local_res18 = (undefined2)(int)(dVar20 * _DAT_14053b290);
    iVar10 = iVar13;
    break;
  case 0xe7:
    dVar18 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar18 * _DAT_14053a610) + (float)uStack_198;
    dVar18 = (double)FUN_140332d90();
    fVar23 = (float)(dVar18 * _DAT_14053a610) + uStack_198._4_4_;
    dVar20 = (double)FUN_140332d90(((double)iVar11 - _DAT_14053b178) * DAT_14053a7f8 * dVar5 *
                                   dVar20);
    local_1d0 = 0xb1;
    iVar10 = iVar13;
    local_res18 = (short)(int)(dVar20 * _DAT_14053b230);
    break;
  case 0xe8:
    iVar10 = 2000;
    local_res10 = 0x157c;
    local_1d0 = 0xb2;
    local_res18 = uVar30;
    break;
  case 0xe9:
    iVar10 = 2000;
    local_res10 = 0x157c;
    local_1d0 = 0xb3;
    local_res18 = uVar30;
    break;
  case 0xea:
    iVar10 = 2000;
    local_res10 = 0x157c;
    local_1d0 = 0xb4;
    local_res18 = uVar30;
    break;
  case 0xeb:
    iVar10 = 2000;
    local_res10 = 0x157c;
    local_1d0 = 0xb5;
    local_res18 = uVar30;
    break;
  case 0xec:
    iVar10 = 2000;
    local_res10 = 0x157c;
    local_1d0 = 0xb6;
    local_res18 = uVar30;
    break;
  case 0xed:
    local_res10 = 0x19c8;
    dVar20 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053b128) * DAT_14053a7f8 *
                                   DAT_14053a020 * DAT_140539d28);
    dVar20 = dVar20 * DAT_14053a840;
    dVar18 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar18 * DAT_14053a650) + (float)uStack_198;
    dVar18 = (double)FUN_140332d90();
    local_1d0 = 0xb7;
    fVar23 = (float)(dVar18 * DAT_14053a650) + uStack_198._4_4_;
    iVar10 = 0x1644;
    local_res18 = (short)(int)dVar20;
    break;
  case 0xee:
    local_res10 = 0x2260;
    FUN_140332d90();
    dVar20 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar20 * DAT_14053a650) + (float)uStack_198;
    dVar20 = (double)FUN_140332d90();
    fVar23 = (float)(dVar20 * DAT_14053a650) + uStack_198._4_4_;
    dVar20 = (double)FUN_140332d90();
    local_1d0 = 0xb8;
    iVar10 = 0x1edc;
    local_res18 = (short)(int)(dVar20 * _DAT_14053b278);
    break;
  case 0xef:
    iVar10 = 0x2454;
    local_res10 = 0x2968;
    local_1d0 = 0xb9;
    local_res18 = uVar30;
    break;
  case 0xf0:
    iVar10 = 0x2454;
    local_res10 = 0x2968;
    local_1d0 = 0xba;
    local_res18 = uVar30;
    break;
  case 0xf1:
    iVar10 = 0x2968;
    fVar25 = (float)local_190 + (float)param_1[0xe];
    fVar23 = local_190._4_4_ + (float)param_1[0xf];
    local_res10 = 0x2cec;
    local_1d0 = 0xbb;
    local_res18 = uVar30;
  }
  iVar13 = 0;
  fVar26 = (float)param_1[0xb];
  fVar24 = (float)param_1[10];
  FUN_1403300b4((double)(fVar23 - fVar26),SUB84((double)(fVar25 - fVar24),0));
  dVar20 = DAT_14053aba0;
  fVar25 = (float)FUN_140334430(fVar24 - fVar25,DAT_140539fc0);
  fVar23 = (float)FUN_140334430(fVar26 - fVar23);
  if (fVar25 + fVar23 < 0.0) {
    fVar23 = (float)FUN_1403352f8();
  }
  else {
    fVar23 = SQRT(fVar25 + fVar23);
  }
  dVar21 = (double)fVar23 / DAT_14053a018;
  dVar18 = (double)FUN_1403307c0();
  fVar24 = (float)(dVar18 * dVar21) + fVar24;
  param_1[10] = fVar24;
  dVar19 = (double)FUN_140332d90();
  uVar6 = _UNK_14053bb28;
  dVar18 = _DAT_14053bb20;
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffde0 >> 0x10);
  iVar8 = param_1[5];
  fVar26 = (float)(dVar19 * dVar21) + fVar26;
  param_1[0xb] = fVar26;
  fVar23 = DAT_14053ab70;
  if (iVar8 == 0) {
    if ((param_1[3] == 0) && (iVar10 <= iVar11)) {
      param_1[0x15] = 1;
      param_1[5] = 2;
      goto LAB_1400f41d8;
    }
    iVar7 = 0;
    iVar8 = 0;
    if ((((iVar10 <= iVar11) && (iVar8 = iVar7, DAT_14053ad10 <= fVar24)) &&
        (fVar24 <= DAT_14053aed4)) && ((DAT_14053ad10 <= fVar26 && (fVar26 <= DAT_14053aed4)))) {
      if (((iVar15 - 0xedU & 0xfffffffa) == 0) && (iVar15 != 0xf2)) {
        DAT_140e418cc = 1;
      }
      param_1[5] = param_1[5] + 1;
      iVar8 = param_1[5];
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
    if (0 < local_148._4_4_) {
      param_1[0x15] = 1;
      param_1[5] = 3;
      fVar23 = DAT_14053ab70;
      goto LAB_1400f41d8;
    }
  }
  fVar23 = DAT_14053ab70;
  if (iVar8 != 1) goto LAB_1400f41d8;
  if ((iVar11 < local_res10) && (param_1[0x15] == 0)) {
    if (((iVar15 - 0xedU & 0xfffffffa) != 0) || (iVar15 == 0xf2)) {
      dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                     SUB84((double)(DAT_140e445d8 - fVar24),0));
      iVar15 = param_1[3];
      uVar9 = (iVar15 + -0x14) % 0x4b;
      dVar21 = (double)(int)uVar9 * DAT_140539e40 + DAT_14053a178;
      if (0x13 < iVar15) {
        uVar16 = (ushort)(int)(dVar19 * dVar20);
        if (uVar9 == 0) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar16;
LAB_1400f3923:
          in_stack_fffffffffffffdd8 =
               CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                        *(undefined2 *)((longlong)param_1 + 0x42));
          FUN_14006c2f0(0xb,0,fVar24,fVar26,in_stack_fffffffffffffdd8,0,dVar21,1,0);
          sVar14 = *(short *)((longlong)param_1 + 0x42);
          dVar21 = dVar21 - dVar18;
          uVar29 = param_1[0xb];
          uVar28 = param_1[10];
          do {
            in_stack_fffffffffffffde0 = 0;
            in_stack_fffffffffffffdd8 =
                 CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                          (short)iVar13 * 2000 + sVar14 + -1000);
            in_stack_fffffffffffffde8 = dVar21;
            FUN_14006c2f0(0xb,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,dVar21,1,0);
            iVar11 = DAT_140e418c8;
            iVar13 = iVar13 + 1;
          } while (iVar13 < 2);
          uVar1 = *(ushort *)((longlong)param_1 + 0x42);
          iVar10 = ((int)(dVar19 * dVar20) & 0xffffU) - (uint)uVar1;
          iVar15 = iVar10 + 0x10000;
          if (-0x8001 < iVar10) {
            iVar15 = iVar10;
          }
          iVar10 = iVar15 + -0x10000;
          if (iVar15 < 0x8001) {
            iVar10 = iVar15;
          }
          if (iVar10 < 1) {
            uVar12 = uVar1;
            if ((iVar10 < 0) && (uVar12 = uVar1 - 0x80, -0x80 < iVar10)) {
              uVar12 = uVar16;
            }
          }
          else {
            uVar12 = uVar16;
            if (0x7f < iVar10) {
              uVar12 = uVar1 + 0x80;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar12;
        }
        else if ((0x13 < iVar15) && ((int)uVar9 < 0x20)) {
          uVar9 = uVar9 & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          if (uVar9 == 0) goto LAB_1400f3923;
        }
      }
    }
    dVar19 = DAT_14053a110;
    dVar20 = DAT_140539f38;
    uVar30 = (undefined2)((uint)in_stack_fffffffffffffde0 >> 0x10);
    iVar15 = param_1[6];
    if ((iVar15 == 0xed) || (iVar15 == 0xee)) {
      sVar14 = *(short *)(param_1 + 3);
      if ((0x13 < (int)param_1[3]) && (iVar10 = param_1[3] + -0x14, iVar10 == (iVar10 / 7) * 7)) {
        uVar9 = 0;
        do {
          if (param_1[6] == 0xed) {
            if ((int)param_1[3] < 0x1a4) {
LAB_1400f3af0:
              uVar29 = param_1[0xb];
              uVar28 = param_1[10];
              dVar21 = (double)(int)uVar9 * dVar20 + dVar19;
              iVar11 = 0;
              do {
                in_stack_fffffffffffffde0 = 0;
                in_stack_fffffffffffffdd8 =
                     CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                              (short)iVar11 * -0x8000 +
                              (short)((uVar9 & 0xffff) * 900) + sVar14 * 500 + -10000);
                in_stack_fffffffffffffde8 = dVar21;
                FUN_14006c2f0(3,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,dVar21,1,0);
                iVar11 = iVar11 + 1;
              } while (iVar11 < 2);
            }
          }
          else if ((param_1[6] == 0xee) && (0x1a3 < (int)param_1[3])) goto LAB_1400f3af0;
          if (param_1[6] == 0xee) {
            if ((int)param_1[3] < 0x1a4) {
LAB_1400f3ba5:
              sVar17 = *(short *)((longlong)param_1 + 0x42);
              uVar29 = param_1[0xb];
              uVar28 = param_1[10];
              dVar21 = (double)(int)uVar9 * dVar20 + dVar19;
              iVar11 = 0;
              do {
                in_stack_fffffffffffffde0 = 0;
                in_stack_fffffffffffffdd8 =
                     CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                              (short)iVar11 * -0x8000 +
                              sVar17 + (short)uVar9 * -900 + sVar14 * -500 + 10000);
                in_stack_fffffffffffffde8 = dVar21;
                FUN_14006c2f0(2,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,dVar21,1,0);
                iVar11 = iVar11 + 1;
              } while (iVar11 < 2);
            }
          }
          else if ((param_1[6] == 0xed) && (0x1a3 < (int)param_1[3])) goto LAB_1400f3ba5;
          uVar30 = (undefined2)((uint)in_stack_fffffffffffffde0 >> 0x10);
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 4);
        iVar15 = param_1[6];
        iVar11 = DAT_140e418c8;
      }
      if (iVar11 == local_res10) {
        DAT_140e418cc = 0;
      }
    }
    dVar4 = DAT_140539f68;
    dVar21 = DAT_140539f28;
    dVar20 = DAT_140539f18;
    if (iVar15 == 0xf1) {
      uVar9 = param_1[3] - 0x14;
      sVar17 = *(short *)(param_1 + 3) * 0x1e0;
      sVar14 = *(short *)(param_1 + 3) * -0x1e0;
      if ((uVar9 < 400) && (uVar9 == ((int)uVar9 / 5) * 5)) {
        iVar15 = 0;
        do {
          uVar29 = param_1[0xb];
          uVar28 = param_1[10];
          iVar10 = 0;
          iVar11 = iVar10;
          do {
            in_stack_fffffffffffffdd8 =
                 CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                          (short)iVar11 * -0x8000 + (short)iVar15 * 600 + sVar17 + -0x2580);
            FUN_14006c2f0(3,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,
                          (double)iVar15 * dVar20 + dVar19,1,0);
            iVar11 = iVar11 + 1;
          } while (iVar11 < 2);
          sVar2 = *(short *)((longlong)param_1 + 0x42);
          uVar29 = param_1[0xb];
          uVar28 = param_1[10];
          dVar22 = ((double)iVar15 * dVar21 + dVar19) - dVar4;
          do {
            uVar30 = 0;
            in_stack_fffffffffffffdd8 =
                 CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                          (short)iVar10 * -0x8000 + sVar2 + (short)iVar15 * -0xaf0 + sVar14 + 0x12c0
                         );
            in_stack_fffffffffffffde8 = dVar22;
            FUN_14006c2f0(10,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,dVar22,1,0);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 2);
          iVar15 = iVar15 + 1;
          iVar11 = DAT_140e418c8;
        } while (iVar15 < 4);
      }
      if ((0x1b7 < (int)param_1[3]) && (iVar15 = param_1[3] + -0x1b8, iVar15 == (iVar15 / 5) * 5)) {
        iVar15 = 0;
        do {
          uVar29 = param_1[0xb];
          uVar28 = param_1[10];
          iVar10 = 0;
          iVar11 = iVar10;
          do {
            in_stack_fffffffffffffdd8 =
                 CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                          (short)iVar11 * -0x8000 + (short)iVar15 * 0xaf0 + sVar17 + -0x2580);
            FUN_14006c2f0(0xb,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,
                          ((double)iVar15 * dVar21 + dVar19) - dVar4,1,0);
            iVar11 = iVar11 + 1;
          } while (iVar11 < 2);
          sVar2 = *(short *)((longlong)param_1 + 0x42);
          uVar29 = param_1[0xb];
          uVar28 = param_1[10];
          dVar22 = (double)iVar15 * dVar20 + dVar19;
          do {
            uVar30 = 0;
            in_stack_fffffffffffffdd8 =
                 CONCAT62((int6)(in_stack_fffffffffffffdd8 >> 0x10),
                          (short)iVar10 * -0x8000 + sVar2 + (short)iVar15 * -600 + sVar14 + 0x12c0);
            in_stack_fffffffffffffde8 = dVar22;
            FUN_14006c2f0(2,0,uVar28,uVar29,in_stack_fffffffffffffdd8,0,dVar22,1,0);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 2);
          iVar15 = iVar15 + 1;
          iVar11 = DAT_140e418c8;
        } while (iVar15 < 4);
      }
      if (iVar11 == local_res10) {
        DAT_140e418cc = 0;
      }
    }
  }
  fVar23 = DAT_14053ab70;
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 + 0.0) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0 < (float)param_1[10])) ||
      ((float)param_1[0xb] < 0.0)) || (DAT_14053af14 < (float)param_1[0xb])) {
    param_1[0x15] = 1;
    if (((param_1[6] - 0xed & 0xfffffffa) == 0) && (param_1[6] != 0xf2)) {
      DAT_140e418cc = 0;
      param_1[5] = 3;
    }
  }
  else {
    param_1[0x15] = 0;
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,1000,8);
    if (((param_1[6] - 0xed & 0xfffffffa) == 0) && (param_1[6] != 0xf2)) {
      FUN_140079e20(param_1,2);
      uVar30 = 0;
      in_stack_fffffffffffffdd8 = in_stack_fffffffffffffdd8 & 0xffffffffffff0000;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,in_stack_fffffffffffffdd8,0,
                    (ulonglong)in_stack_fffffffffffffde8 & 0xffffffff00000000);
      if ((param_1[6] == 0xf1) && (DAT_140e44600 == 0)) {
        uVar9 = ((uint)param_1[1] >> 0x1e ^ param_1[1]) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
        in_stack_fffffffffffffdd8 = DAT_14053a070;
        uVar29 = DAT_14053ac80;
        FUN_1400ca6d0(6,param_1[10],param_1[0xb],
                      CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                               (short)DAT_140e9fd1c +
                               (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                      DAT_14053a070,DAT_14053ac80);
        uVar30 = (undefined2)((uint)uVar29 >> 0x10);
      }
      DAT_140e418cc = 0;
    }
    else {
      FUN_140079e20(param_1,1);
    }
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 1;
  }
LAB_1400f41d8:
  fVar25 = (float)param_1[10];
  fVar26 = (float)param_1[0xb];
  if ((((DAT_140e445d8 / fVar23 - DAT_14053acfc <= fVar25) &&
       (fVar25 <= DAT_140e445d8 / fVar23 + DAT_14053aef4)) && (DAT_14053b370 <= fVar26)) &&
     (fVar26 <= DAT_14053af48)) {
    uVar29 = CONCAT22(uVar30,local_res18);
    uVar27 = CONCAT44((int)(in_stack_fffffffffffffdd8 >> 0x20),fVar26);
    if (param_1[5] == 2) {
      FUN_1400c8410(*(undefined4 *)(local_1d0 * 4 + 0x140e44b08),0x14,7,fVar25,uVar27,uVar29,dVar18,
                    uVar6,0xff,0xff,0xff,0xff,1,0);
    }
    else {
      FUN_1400c8410((&DAT_140e44ad0)[local_1d0],0x17,7,fVar25,uVar27,uVar29,dVar18,uVar6,0xff,0xff,
                    0xff,0xff,1,0);
      uVar28 = (undefined4)((ulonglong)uVar27 >> 0x20);
      uVar30 = (undefined2)((uint)uVar29 >> 0x10);
      if ((param_1[5] == 1) && (uVar9 = param_1[3], (int)uVar9 < 0x28)) {
        iVar11 = 0xff;
        if (uVar9 < 0x28) {
          dVar20 = (double)FUN_140332d90(((double)(int)uVar9 - DAT_14053b138) * DAT_14053a6d8 *
                                         dVar5 * DAT_140539d28);
          iVar11 = (int)(dVar20 * DAT_14053a5f8);
        }
        FUN_1400c8410((&DAT_140e44ad0)[local_1d0],0x17,8,param_1[10],CONCAT44(uVar28,param_1[0xb]),
                      CONCAT22(uVar30,local_res18),dVar18,uVar6,0xff,0xff,0xff,iVar11,1,0);
      }
      if (param_1[0x15] == 0) {
        FUN_140079c10(param_1,1);
      }
    }
  }
  if ((local_148._4_4_ == 7) && (uStack_150._4_4_ == 0xa0)) {
    *param_1 = 0;
  }
  return;
}


