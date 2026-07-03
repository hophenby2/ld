// Function: FUN_1400af090 @ 1400af090
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400af090(undefined4 *param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  undefined8 uVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar24;
  uint in_stack_ffffffffffffff00;
  undefined2 uVar25;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar26 [16];
  
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  fVar23 = DAT_14053af14;
  fVar22 = DAT_14053ae30;
  uVar25 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar13 = (uint)(dVar16 * DAT_14053aba0);
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar7;
    dVar16 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar16,0);
    in_stack_ffffffffffffff08._0_8_ = dVar16;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar16 >> 0x20);
    in_stack_ffffffffffffff00 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff00,
                  in_stack_ffffffffffffff08,0xff,0xff,0xff,0xff,1,0);
    uVar25 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
    uVar24 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      fVar21 = (float)param_1[10];
      if (0.0 < (float)param_1[0xb]) {
        if (fVar21 <= 0.0) {
          *(undefined2 *)(param_1 + 0x10) = 0;
        }
        if (fVar23 <= fVar21) {
          *(undefined2 *)(param_1 + 0x10) = 0x8000;
        }
      }
      else {
        uVar3 = 0x18f1;
        if (fVar22 <= fVar21) {
          uVar3 = 0x670f;
        }
        *(undefined2 *)(param_1 + 0x10) = uVar3;
      }
      param_1[5] = param_1[5] + 1;
      *(short *)((longlong)param_1 + 0x42) = (short)uVar13;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] == 1) {
    fVar21 = (float)param_1[0xd];
    if (0.0 < fVar21) {
      sVar4 = 400;
      if (0x31 < param_1[3] - 0x3c) {
        sVar4 = 0x3c;
      }
      if ((((float)param_1[0xc] <= 0.0) && (DAT_14053ade8 <= fVar21)) ||
         ((fVar23 <= (float)param_1[0xc] && (fVar21 < DAT_14053ade8)))) {
        sVar4 = -sVar4;
      }
    }
    else {
      sVar8 = 400;
      if (0x31 < param_1[3] - 0x28) {
        sVar8 = 0x3c;
      }
      sVar4 = -sVar8;
      if ((float)param_1[0xc] < fVar22) {
        sVar4 = sVar8;
      }
    }
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar4;
    dVar18 = DAT_14053a020;
    dVar16 = DAT_140539d28;
    dVar17 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar17 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar22;
    dVar17 = (double)FUN_140332d90();
    uVar1 = *(ushort *)((longlong)param_1 + 0x42);
    uVar11 = (uint)uVar1;
    uVar5 = (short)uVar13 - uVar1;
    uVar9 = (uint)uVar5;
    if (0x8000 < uVar5) {
      uVar9 = 0x10000 - uVar5;
    }
    iVar10 = (uVar13 & 0xffff) - (uint)uVar1;
    fVar23 = (float)(dVar17 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar12 = (int)uVar9 / 10 + 0x30;
    param_1[0xb] = fVar23;
    iVar6 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar6 = iVar10;
    }
    iVar10 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar10 = iVar6;
    }
    if (iVar10 < 1) {
      if ((iVar10 < 0) && (uVar11 = (uint)(ushort)(uVar1 - (short)iVar12), -iVar12 < iVar10)) {
        uVar11 = uVar13 & 0xffff;
      }
    }
    else if (iVar10 < iVar12) {
      uVar11 = uVar13 & 0xffff;
    }
    else {
      uVar11 = (uint)(ushort)(uVar1 + (short)iVar12);
    }
    *(short *)((longlong)param_1 + 0x42) = (short)uVar11;
    dVar17 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar17 * _DAT_14053a358) + fVar22;
    dVar17 = (double)FUN_140332d90();
    fVar21 = (float)(dVar17 * _DAT_14053a358) + fVar23;
    if (((((int)param_1[3] < 200) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053ac58 <= fVar22)) &&
        (fVar22 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aeb8)) &&
       ((DAT_14053ac58 <= fVar21 && (fVar21 <= DAT_14053af04)))) {
      fVar14 = (float)FUN_140334430(fVar22 - DAT_140e445d8,DAT_140539fc0);
      fVar15 = (float)FUN_140334430(fVar21 - DAT_140e445dc);
      if (fVar14 + fVar15 < 0.0) {
        fVar14 = (float)FUN_1403352f8();
      }
      else {
        fVar14 = SQRT(fVar14 + fVar15);
      }
      if (((DAT_14053ad10 <= fVar14) && (fVar23 < DAT_14053ae90)) &&
         ((-1 < DAT_140e418c8 && (DAT_140e418c8 == (DAT_140e418c8 / 10) * 10)))) {
        auVar26._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar26._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar26._8_4_ = 1;
        uVar25 = 0;
        FUN_14006c2f0(9,0,fVar22,fVar21,CONCAT22(uVar24,(short)(uVar11 + 0x400 >> 0xb) * 0x800),0,
                      DAT_14053a160,auVar26._8_8_,0);
      }
    }
    dVar16 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053aa60 * dVar18 *
                                   dVar16);
    dVar16 = dVar16 * _DAT_14053aa98;
    sVar4 = *(short *)((longlong)param_1 + 0x42);
    dVar18 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar18 * DAT_14053a0b0) + (float)param_1[10];
    dVar18 = (double)FUN_140332d90();
    sVar8 = (short)(int)dVar16;
    fVar23 = (float)(dVar18 * DAT_14053a0b0) + (float)param_1[0xb];
    dVar18 = (double)FUN_1403307c0();
    dVar16 = DAT_14053a318;
    dVar18 = dVar18 * DAT_14053a318;
    dVar17 = (double)FUN_140332d90();
    dVar19 = (double)FUN_1403307c0();
    dVar20 = (double)FUN_140332d90();
    uVar2 = _UNK_14053bb28;
    uVar7 = _DAT_14053bb20;
    FUN_1400c8410(DAT_140e448c4,0x23,7,(float)dVar18 + fVar22,(float)(dVar17 * dVar16) + fVar23,
                  CONCAT22(uVar25,sVar8 + sVar4 + -0x4000),_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                  0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e448c4,0x23,7,(float)(dVar19 * dVar16) + fVar22,
                  (float)(dVar20 * dVar16) + fVar23,
                  (*(short *)((longlong)param_1 + 0x42) - sVar8) + -0x4000,uVar7,uVar2,0xff,0xff,
                  0xff,0xff,1,1);
    FUN_1400c8410(DAT_140e448c0,0x23,7,param_1[10],param_1[0xb],
                  *(undefined2 *)((longlong)param_1 + 0x42),uVar7,uVar2,0xff,0xff,0xff,0xff,1,0);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,200,2);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


