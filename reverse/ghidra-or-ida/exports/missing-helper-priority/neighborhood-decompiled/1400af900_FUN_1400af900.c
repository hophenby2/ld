// Function: FUN_1400af900 @ 1400af900
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400af900(undefined4 *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  ushort uVar10;
  ushort uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar22;
  uint in_stack_ffffffffffffff00;
  uint uVar23;
  undefined2 uVar24;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar25 [16];
  
  uVar24 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  if (param_1[5] == 0) {
    uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar8;
    dVar15 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar15,0);
    in_stack_ffffffffffffff08._0_8_ = dVar15;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar15 >> 0x20);
    uVar23 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar23,in_stack_ffffffffffffff08,0xff,
                  0xff,0xff,0xff,1,0);
    uVar12 = DAT_140e418c8;
    uVar24 = (undefined2)(uVar23 >> 0x10);
    uVar22 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4014000000000000;
      uVar12 = (uVar12 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar12 = uVar12 * 0x800 ^ uVar12;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
      *(short *)(param_1 + 0x10) =
           (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 + 0x3a24;
      uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] == 1) {
    fVar20 = (float)param_1[10];
    fVar21 = (float)param_1[0xb];
    dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar21),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    iVar4 = param_1[3];
    if (iVar4 < 200) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      uVar11 = (ushort)(int)(dVar15 * DAT_14053aba0);
      iVar9 = ((int)(dVar15 * DAT_14053aba0) & 0xffffU) - (uint)uVar1;
      iVar7 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar7 = iVar9;
      }
      iVar9 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar9 = iVar7;
      }
      if (iVar9 < 1) {
        uVar10 = uVar1;
        if ((iVar9 < 0) && (uVar10 = uVar1 - 0xff, -0xff < iVar9)) {
          uVar10 = uVar11;
        }
      }
      else {
        uVar10 = uVar11;
        if (0xfe < iVar9) {
          uVar10 = uVar1 + 0xff;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar10;
    }
    dVar17 = DAT_14053a020;
    dVar15 = DAT_140539d28;
    dVar19 = *(double *)(param_1 + 0x12) + _DAT_140539e28;
    uVar2 = *(undefined2 *)(param_1 + 0x10);
    *(double *)(param_1 + 0x12) = dVar19;
    dVar16 = (double)FUN_1403307c0();
    fVar20 = (float)(dVar16 * dVar19) + fVar20;
    param_1[10] = fVar20;
    dVar16 = (double)FUN_140332d90();
    fVar21 = (float)(dVar16 * dVar19) + fVar21;
    param_1[0xb] = fVar21;
    fVar13 = DAT_140e445d8;
    if ((((iVar4 < 200) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053ac58 <= fVar20)) &&
        (fVar20 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aeb8)) &&
       (((DAT_14053ac58 <= fVar21 && (fVar21 <= DAT_14053af04)) && (fVar21 < DAT_14053ae50)))) {
      dVar16 = (double)FUN_1403307c0();
      fVar20 = (float)(dVar16 * _DAT_14053a358) + fVar20;
      dVar16 = (double)FUN_140332d90();
      fVar21 = (float)(dVar16 * _DAT_14053a358) + fVar21;
      if ((-1 < iVar4) && (iVar4 == (iVar4 / 0x12) * 0x12)) {
        fVar13 = (float)FUN_140334430(fVar20 - fVar13,DAT_140539fc0);
        fVar14 = (float)FUN_140334430(fVar21 - DAT_140e445dc);
        if (fVar13 + fVar14 < 0.0) {
          fVar13 = (float)FUN_1403352f8();
        }
        else {
          fVar13 = SQRT(fVar13 + fVar14);
        }
        if (DAT_14053ad10 <= fVar13) {
          auVar25._12_4_ = in_stack_ffffffffffffff08._12_4_;
          auVar25._0_8_ = in_stack_ffffffffffffff08._0_8_;
          auVar25._8_4_ = 1;
          uVar24 = 0;
          FUN_14006c2f0(8,0,fVar20,fVar21,CONCAT22(uVar22,uVar2),0,DAT_14053a160,auVar25._8_8_,0);
        }
      }
    }
    dVar15 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053aa60 * dVar17 *
                                   dVar15);
    dVar15 = dVar15 * _DAT_14053aa98;
    sVar3 = *(short *)(param_1 + 0x10);
    dVar17 = (double)FUN_1403307c0();
    fVar20 = (float)(dVar17 * DAT_14053a0b0) + (float)param_1[10];
    dVar17 = (double)FUN_140332d90();
    sVar5 = (short)(int)dVar15;
    fVar21 = (float)(dVar17 * DAT_14053a0b0) + (float)param_1[0xb];
    dVar17 = (double)FUN_1403307c0();
    dVar15 = DAT_14053a318;
    dVar17 = dVar17 * DAT_14053a318;
    dVar16 = (double)FUN_140332d90();
    dVar19 = (double)FUN_1403307c0();
    dVar18 = (double)FUN_140332d90();
    uVar6 = _UNK_14053bb28;
    uVar8 = _DAT_14053bb20;
    FUN_1400c8410(DAT_140e448cc,0x23,7,(float)dVar17 + fVar20,(float)(dVar16 * dVar15) + fVar21,
                  CONCAT22(uVar24,sVar5 + sVar3 + -0x4000),_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                  0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e448cc,0x23,7,(float)(dVar19 * dVar15) + fVar20,
                  (float)(dVar18 * dVar15) + fVar21,(*(short *)(param_1 + 0x10) - sVar5) + -0x4000,
                  uVar8,uVar6,0xff,0xff,0xff,0xff,1,1);
    FUN_1400c8410(DAT_140e448c8,0x23,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x10),
                  uVar8,uVar6,0xff,0xff,0xff,0xff,1,0);
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


