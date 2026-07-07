// Function: FUN_14007ea30 @ 14007ea30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14007ea30(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  float fVar5;
  float fVar6;
  ulonglong uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  float fVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  float fVar27;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar28;
  uint in_stack_fffffffffffffef0;
  uint uVar29;
  undefined2 uVar30;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  
  dVar4 = DAT_140539e60;
  uVar30 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
  uVar28 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar9 = DAT_1407c7798;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    dVar13 = DAT_140539fc8 - (double)(int)param_1[3] * dVar4;
    uStackX_c = (undefined4)(uVar7 >> 0x20);
    in_stack_fffffffffffffef8._8_4_ = SUB84(dVar13,0);
    in_stack_fffffffffffffef8._0_8_ = dVar13;
    in_stack_fffffffffffffef8._12_4_ = (int)((ulonglong)dVar13 >> 0x20);
    uVar29 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar7 & 0xffffffff,uStackX_c,uVar29,in_stack_fffffffffffffef8
                  ,0xff,0xff,0xff,0xff,1,0);
    iVar9 = DAT_1407c7798;
    uVar30 = (undefined2)(uVar29 >> 0x10);
    uVar28 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4008000000000000;
      if (3 < iVar9) {
        *(undefined8 *)(param_1 + 0x12) = 0x4010000000000000;
      }
      if ((float)param_1[10] <= DAT_14053ae30) {
        *(undefined2 *)(param_1 + 0x10) = 0xf2fb;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8d05;
      }
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  fVar5 = DAT_14053ab70;
  if (param_1[5] == 1) {
    dVar13 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053aa10 * DAT_14053a020
                                   * DAT_140539d28);
    dVar4 = dVar13 * dVar4 + DAT_140539f40;
    uVar25 = SUB84(dVar4,0);
    uVar26 = (undefined4)((ulonglong)dVar4 >> 0x20);
    dVar13 = (double)FUN_140332d90();
    dVar13 = dVar13 * _DAT_14053ab40;
    dVar14 = (double)FUN_1403307c0();
    fVar27 = (float)(dVar14 * *(double *)(param_1 + 0x12)) + (float)param_1[0xc];
    param_1[0xc] = fVar27;
    dVar14 = (double)FUN_140332d90();
    param_1[10] = fVar27;
    fVar20 = (float)(dVar14 * *(double *)(param_1 + 0x12)) + (float)param_1[0xd];
    param_1[0xd] = fVar20;
    dVar14 = (double)FUN_140332d90();
    fVar18 = DAT_14053aca8;
    fVar11 = DAT_14053ac34;
    fVar20 = (float)(dVar14 * DAT_14053b0d8) + fVar20;
    param_1[0xb] = fVar20;
    fVar6 = DAT_140e445d8;
    fVar24 = fVar20 - fVar11;
    if (uVar1 < 0xc000) {
      fVar23 = fVar27 - fVar18;
    }
    else {
      fVar23 = fVar27 + fVar18;
    }
    if ((((DAT_140e445d8 / fVar5 + fVar18 <= fVar23) &&
         (fVar23 <= DAT_140e445d8 / fVar5 + DAT_14053aea8)) && (fVar18 <= fVar24)) &&
       (fVar24 <= DAT_14053aef4)) {
      fVar11 = (float)FUN_140334430(fVar23 - DAT_140e445d8,DAT_140539fc0);
      fVar18 = DAT_140e445dc;
      fVar12 = (float)FUN_140334430(fVar24 - DAT_140e445dc);
      if (fVar11 + fVar12 < 0.0) {
        fVar12 = (float)FUN_1403352f8();
      }
      else {
        fVar12 = SQRT(fVar11 + fVar12);
      }
      fVar11 = DAT_14053ac34;
      if (DAT_14053acbc <= fVar12) {
        dVar14 = (double)FUN_1403300b4((double)(fVar18 - (fVar20 + DAT_14053ac60)),
                                       SUB84((double)(fVar6 - fVar27),0));
        iVar10 = 1;
        if (DAT_140e419b8 == 0) {
          iVar10 = 0x3c;
        }
        else if (DAT_140e419b8 == 1) {
          iVar10 = 0x2c;
        }
        else if (DAT_140e419b8 == 2) {
          iVar10 = 0x18;
        }
        else if (DAT_140e419b8 == 3) {
          iVar10 = 0xf;
        }
        else if (DAT_140e419b8 == 4) {
          iVar10 = 7;
        }
        uVar19 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
        uVar16 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
        uVar17 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
        uVar15 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
        if (DAT_140e419b8 == 0) {
          uVar21 = (int)DAT_14053a018;
          uVar22 = (int)((ulonglong)DAT_14053a018 >> 0x20);
        }
        else {
          uVar21 = (int)DAT_14053a070;
          uVar22 = uVar15;
          if ((DAT_140e419b8 != 1) &&
             (uVar21 = (int)DAT_14053a088, uVar22 = uVar16, DAT_140e419b8 != 2)) {
            if (DAT_140e419b8 == 3) {
              uVar21 = (int)DAT_14053a0d0;
              uVar22 = (int)((ulonglong)DAT_14053a0d0 >> 0x20);
            }
            else {
              uVar21 = SUB84(DAT_140539f40,0);
              uVar22 = uVar19;
              if (DAT_140e419b8 == 4) {
                uVar21 = (int)DAT_14053a158;
                uVar22 = uVar17;
              }
            }
          }
        }
        if (3 < iVar9) {
          iVar10 = 1;
          if (DAT_140e419b8 == 0) {
            iVar10 = 0x2c;
          }
          else if (DAT_140e419b8 == 1) {
            iVar10 = 0x1f;
          }
          else if (DAT_140e419b8 == 2) {
            iVar10 = 0x11;
          }
          else if (DAT_140e419b8 == 3) {
            iVar10 = 0xc;
          }
          else if (DAT_140e419b8 == 4) {
            iVar10 = 7;
          }
          uVar21 = (int)DAT_14053a070;
          uVar22 = uVar15;
          if ((DAT_140e419b8 != 0) &&
             (uVar21 = (int)DAT_14053a088, uVar22 = uVar16, DAT_140e419b8 != 1)) {
            if (DAT_140e419b8 == 2) {
              uVar21 = (int)DAT_14053a0b0;
              uVar22 = (int)((ulonglong)DAT_14053a0b0 >> 0x20);
            }
            else if (DAT_140e419b8 == 3) {
              uVar21 = (int)DAT_14053a0f8;
              uVar22 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
            }
            else {
              uVar21 = SUB84(DAT_140539f40,0);
              uVar22 = uVar19;
              if (DAT_140e419b8 == 4) {
                uVar21 = (int)DAT_14053a158;
                uVar22 = uVar17;
              }
            }
          }
        }
        fVar11 = DAT_14053ac34;
        if ((-1 < DAT_140e418c8) && ((int)((longlong)DAT_140e418c8 % (longlong)iVar10) == 0)) {
          auVar31._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar31._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar31._8_4_ = 1;
          auVar32._8_8_ = auVar31._8_8_;
          auVar32._0_8_ = CONCAT44(uVar22,uVar21);
          sVar8 = (short)(((int)(dVar14 * DAT_14053aba0) & 0xffffU) + 0x400 >> 0xb) * 0x800;
          FUN_14006c2f0(0,(longlong)DAT_140e418c8 % (longlong)iVar10 & 0xffffffff,fVar23,fVar24,
                        CONCAT22(uVar28,sVar8),0,CONCAT44(uVar22,uVar21),auVar32._8_8_,0);
          auVar33._12_4_ = auVar32._12_4_;
          auVar33._0_8_ = auVar32._0_8_;
          auVar33._8_4_ = 1;
          uVar15 = DAT_14053ac2c;
          FUN_14006c2f0(0,0,fVar23,fVar24,sVar8,DAT_14053ac2c,CONCAT44(uVar22,uVar21),auVar33._8_8_,
                        0);
          uVar30 = (undefined2)((uint)uVar15 >> 0x10);
          fVar11 = DAT_14053ac34;
        }
      }
    }
    auVar2._8_4_ = uVar25;
    auVar2._0_8_ = dVar4;
    auVar2._12_4_ = uVar26;
    sVar8 = (short)(int)dVar13;
    if (uVar1 < 0xc000) {
      uVar15 = CONCAT22(uVar30,0x4000 - sVar8);
      FUN_1400c8410(DAT_140e44688,0x23,7,(float)param_1[10] + fVar5,(float)param_1[0xb] - fVar5,
                    uVar15,auVar2,0xff,0xff,0xff,0xff,1,0);
      fVar18 = (float)param_1[10] - fVar5;
      uVar29 = CONCAT22((short)((uint)uVar15 >> 0x10),sVar8 + 0x4bb8);
    }
    else {
      uVar15 = CONCAT22(uVar30,sVar8 + 0x4000);
      FUN_1400c8410(DAT_140e44688,0x23,7,(float)param_1[10] - fVar5,(float)param_1[0xb] - fVar5,
                    uVar15,auVar2,0xff,0xff,0xff,0xff,1,0);
      fVar18 = (float)param_1[10] + fVar5;
      uVar29 = CONCAT22((short)((uint)uVar15 >> 0x10),0x3448 - sVar8);
    }
    auVar34._8_4_ = uVar25;
    auVar34._0_8_ = dVar4;
    auVar34._12_4_ = uVar26;
    FUN_1400c8410(DAT_140e44688,0x23,7,fVar18,(float)param_1[0xb] - fVar11,uVar29,auVar34,0xff,0xff,
                  0xff,0xff,1,0);
    auVar3._8_4_ = uVar25;
    auVar3._0_8_ = dVar4;
    auVar3._12_4_ = uVar26;
    FUN_1400c8410(DAT_140e44684,0x23,7,param_1[10],param_1[0xb],uVar29 & 0xffff0000,auVar3,0xff,0xff
                  ,0xff,0xff,1,uVar1 < 0xc000);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x1e0,3);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / fVar5 - DAT_14053ad9c) ||
       (DAT_140e445d8 / fVar5 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


