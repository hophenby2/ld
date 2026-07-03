// Function: FUN_14009f5d0 @ 14009f5d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009f5d0(undefined4 *param_1)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  uint uVar11;
  uint uVar12;
  short sVar13;
  short sVar14;
  float fVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  uint in_stack_fffffffffffffef0;
  undefined2 uVar28;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined8 in_stack_ffffffffffffff08;
  ulonglong uVar39;
  
  fVar24 = DAT_14053ae30;
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  uVar10 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
  fVar22 = (float)DAT_1407c77a4;
  fVar26 = (float)param_1[0xb];
  param_1[0xb] = fVar22 + fVar26;
  if (param_1[5] == 0) {
    uVar20 = CONCAT44(uVar16,0xff);
    dVar19 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    in_stack_fffffffffffffef8._8_4_ = SUB84(dVar19,0);
    in_stack_fffffffffffffef8._0_8_ = dVar19;
    in_stack_fffffffffffffef8._12_4_ = (int)((ulonglong)dVar19 >> 0x20);
    uVar12 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,param_1[10],fVar22 + fVar26,uVar12,in_stack_fffffffffffffef8,
                  uVar20,0xff,0xff,0xff,1,0);
    uVar16 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar10 = (undefined2)(uVar12 >> 0x10);
    if (param_1[3] == 0x14) {
      if (param_1[6] == 0x5b) {
        if ((float)param_1[0xc] <= fVar24) {
          *(undefined2 *)(param_1 + 0x10) = 0;
        }
        else {
          *(undefined2 *)(param_1 + 0x10) = 0x8000;
        }
      }
      else if (param_1[6] == 0x5c) {
        if ((float)param_1[0xc] <= fVar24) {
          *(undefined2 *)(param_1 + 0x10) = 0xe0c0;
        }
        else {
          *(undefined2 *)(param_1 + 0x10) = 0x9f40;
        }
      }
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff8000000000000;
      param_1[3] = 0;
    }
  }
  uVar5 = _UNK_14053bb2c;
  uVar21 = _UNK_14053bb28;
  uVar4 = _UNK_14053bb24;
  uVar3 = _DAT_14053bb20;
  dVar18 = DAT_14053b0d8;
  dVar2 = DAT_14053a7f8;
  dVar1 = DAT_14053a020;
  dVar19 = DAT_140539d28;
  fVar26 = DAT_14053ab70;
  if (param_1[5] == 1) {
    iVar7 = param_1[3];
    fVar22 = 0.0;
    if (iVar7 % 0x32 < 0x33) {
      dVar17 = (double)FUN_140332d90(((double)(iVar7 % 0x32) - 0.0) * DAT_14053a7f8 * DAT_14053a020
                                     * DAT_140539d28);
      fVar22 = (float)(dVar17 * dVar18) + 0.0;
    }
    fVar27 = 0.0;
    iVar8 = (iVar7 + 3) % 0x32;
    if (iVar8 < 0x33) {
      dVar17 = (double)FUN_140332d90(((double)iVar8 - 0.0) * dVar2 * dVar1 * dVar19);
      fVar27 = (float)(dVar17 * dVar18) + 0.0;
    }
    sVar14 = 0;
    iVar8 = (iVar7 + 5) % 0x32;
    if (iVar8 < 0x33) {
      dVar18 = (double)FUN_140332d90(((double)iVar8 - 0.0) * dVar2 * dVar1 * dVar19);
      sVar14 = (short)(int)(dVar18 * _DAT_14053aac8);
    }
    dVar18 = DAT_14053abb8;
    sVar13 = 0;
    iVar8 = (iVar7 + 5) % 100;
    if (iVar8 < 0x33) {
      dVar17 = (double)FUN_140332d90(((double)iVar8 - 0.0) * dVar2 * dVar1 * dVar19);
      sVar13 = (short)(int)(dVar17 * dVar18);
    }
    uVar10 = 0;
    iVar8 = (iVar7 + 0x37) % 100;
    if (iVar8 < 0x33) {
      dVar19 = (double)FUN_140332d90(((double)iVar8 - 0.0) * dVar2 * dVar1 * dVar19);
      uVar10 = (undefined2)(int)(dVar19 * dVar18);
    }
    auVar29._12_4_ = in_stack_fffffffffffffef8._12_4_;
    auVar29._0_8_ = in_stack_fffffffffffffef8._0_8_;
    auVar29._8_4_ = 0x41;
    auVar30._4_12_ = auVar29._4_12_;
    auVar30._0_4_ = 0x40;
    uVar28 = 0;
    iVar7 = FUN_1400c9580(iVar7,0,7,4,0x3e,0x3f,auVar30);
    fVar26 = DAT_14053ab70;
    if (param_1[0x15] == 1) {
      if ((((DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac58 <= (float)param_1[10]) &&
           ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aecc)) &&
          (DAT_14053b330 <= (float)param_1[0xb])) && ((float)param_1[0xb] <= _DAT_14053af24)) {
        param_1[0x15] = 0;
      }
    }
    if (param_1[6] == 0x5c) {
      if ((float)param_1[0xc] <= fVar24) {
        sVar6 = *(short *)(param_1 + 0x10) + 0x13;
      }
      else {
        sVar6 = *(short *)(param_1 + 0x10) + -0x12;
      }
      *(short *)(param_1 + 0x10) = sVar6;
    }
    dVar19 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar25;
    dVar19 = (double)FUN_140332d90();
    fVar23 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar23;
    fVar15 = DAT_140e445d8;
    if (fVar23 < fVar24) {
      fVar24 = (fVar23 + fVar22) - DAT_14053aa20;
      FUN_1403300b4((double)(DAT_140e445dc - fVar24),SUB84((double)(DAT_140e445d8 - fVar25),0));
      iVar8 = 1;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0x2c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x15;
      }
      else if (DAT_140e419b8 == 2) {
        iVar8 = 0xf;
      }
      else if (DAT_140e419b8 == 3) {
        iVar8 = 9;
      }
      else if (DAT_140e419b8 == 4) {
        iVar8 = 7;
      }
      if (-1 < (int)param_1[3]) {
        uVar39 = (longlong)(int)param_1[3] % (longlong)(iVar8 * 5);
        iVar9 = (int)uVar39;
        if ((((iVar9 < iVar8 * 3) &&
             ((int)((longlong)((ulonglong)(uint)(iVar9 >> 0x1f) << 0x20 | uVar39 & 0xffffffff) %
                   (longlong)iVar8) == 0)) &&
            ((fVar23 = fVar15 / fVar26, fVar23 + 0.0 <= fVar25 &&
             ((fVar25 <= fVar23 + DAT_14053aec0 && (0.0 <= fVar24)))))) && (fVar24 <= DAT_14053af14)
           ) {
          fVar15 = (float)FUN_140334430(fVar25 - fVar15,DAT_140539fc0);
          fVar24 = (float)FUN_140334430(fVar24 - DAT_140e445dc);
          if (fVar15 + fVar24 < 0.0) {
            fVar24 = (float)FUN_1403352f8();
          }
          else {
            fVar24 = SQRT(fVar15 + fVar24);
          }
          if (DAT_14053acbc < fVar24) {
            uVar28 = 0;
            FUN_14006c2f0(1,0);
            if (2 < DAT_140e419b8) {
              uVar28 = 0;
              FUN_14006c2f0(1,0);
            }
          }
        }
      }
    }
    uVar20 = CONCAT44(uVar16,0xff);
    auVar31._4_4_ = uVar4;
    auVar31._0_4_ = uVar3;
    auVar31._8_4_ = uVar21;
    auVar31._12_4_ = uVar5;
    uVar16 = CONCAT22(uVar28,-sVar13);
    FUN_1400c8410(DAT_140e44768,0x1a,7,(float)param_1[10] + DAT_14053ac18,
                  fVar27 + (float)param_1[0xb] + DAT_14053ac48,uVar16,auVar31,uVar20,0xff,0xff,0xff,
                  1,0);
    uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar32._4_4_ = uVar4;
    auVar32._0_4_ = uVar3;
    auVar32._8_4_ = uVar21;
    auVar32._12_4_ = uVar5;
    uVar16 = CONCAT22((short)((uint)uVar16 >> 0x10),uVar10);
    FUN_1400c8410(DAT_140e44768,0x1a,7,(float)param_1[10] - DAT_14053ac18,
                  fVar27 + (float)param_1[0xb] + DAT_14053ac48,uVar16,auVar32,uVar20,0xff,0xff,0xff,
                  1,1);
    uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar33._4_4_ = uVar4;
    auVar33._0_4_ = uVar3;
    auVar33._8_4_ = uVar21;
    auVar33._12_4_ = uVar5;
    uVar16 = CONCAT22((short)((uint)uVar16 >> 0x10),-sVar14);
    FUN_1400c8410(DAT_140e4476c,0x1a,7,(float)param_1[10] + DAT_14053ac2c,
                  fVar27 + (float)param_1[0xb],uVar16,auVar33,uVar20,0xff,0xff,0xff,1,0);
    uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar34._4_4_ = uVar4;
    auVar34._0_4_ = uVar3;
    auVar34._8_4_ = uVar21;
    auVar34._12_4_ = uVar5;
    uVar12 = CONCAT22((short)((uint)uVar16 >> 0x10),sVar14);
    FUN_1400c8410(DAT_140e4476c,0x1a,7,(float)param_1[10] - DAT_14053ac2c,
                  fVar27 + (float)param_1[0xb],uVar12,auVar34,uVar20,0xff,0xff,0xff,1,1);
    uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar35._4_4_ = uVar4;
    auVar35._0_4_ = uVar3;
    auVar35._8_4_ = uVar21;
    auVar35._12_4_ = uVar5;
    uVar12 = uVar12 & 0xffff0000;
    FUN_1400c8410(DAT_140e44770,0x1a,7,param_1[10],fVar27 + (float)param_1[0xb],uVar12,auVar35,
                  uVar20,0xff,0xff,0xff,1,0);
    uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar36._4_4_ = uVar4;
    auVar36._0_4_ = uVar3;
    auVar36._8_4_ = uVar21;
    auVar36._12_4_ = uVar5;
    uVar12 = uVar12 & 0xffff0000;
    FUN_1400c8410(DAT_140e44774,0x1a,7,param_1[10],(fVar22 + (float)param_1[0xb]) - _DAT_14053ac40,
                  uVar12,auVar36,uVar20,0xff,0xff,0xff,1,0);
    uVar39 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0xff);
    auVar37._4_4_ = uVar4;
    auVar37._0_4_ = uVar3;
    auVar37._8_4_ = uVar21;
    auVar37._12_4_ = uVar5;
    uVar12 = uVar12 & 0xffff0000;
    FUN_1400c8410((&DAT_140e44660)[iVar7],0x19,7,param_1[10],(float)param_1[0xb] + DAT_14053accc,
                  uVar12,auVar37,uVar39,0xff,0xff,0xff,1,0);
    auVar38._4_4_ = uVar4;
    auVar38._0_4_ = uVar3;
    auVar38._8_4_ = uVar21;
    auVar38._12_4_ = uVar5;
    uVar12 = uVar12 & 0xffff0000;
    FUN_1400c8410((&DAT_140e44660)[iVar7],0x18,0x17,param_1[10],(float)param_1[0xb] + DAT_14053accc,
                  uVar12,auVar38,uVar39 & 0xffffffff00000000,0,0,0x40,1,0);
    uVar10 = (undefined2)(uVar12 >> 0x10);
    if (param_1[0x15] == 0) {
      FUN_140079c10(param_1,2);
    }
  }
  if ((int)param_1[7] < 1) {
    uVar11 = param_1[1] + DAT_140e418c8;
    uVar12 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar12 = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
    DAT_140e9fd1c = uVar12;
    uVar20 = FUN_140134db0(uVar11,(int)DAT_140539f38);
    uVar16 = (undefined4)uVar20;
    uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar20 = FUN_140134db0(uVar11);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],(float)param_1[0xb] + DAT_14053acfc,
                  CONCAT22(uVar10,(short)uVar12 - (short)(uVar12 / 0x10001)),CONCAT44(uVar4,uVar3),
                  uVar20,CONCAT44(uVar21,uVar16),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,1000,4);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (param_1[0x15] == 0) {
    if (((((float)param_1[10] < DAT_140e445d8 / fVar26 - DAT_14053ad1c) ||
         (DAT_140e445d8 / fVar26 + DAT_14053af04 < (float)param_1[10])) ||
        ((float)param_1[0xb] < DAT_14053b380)) || (DAT_14053af54 < (float)param_1[0xb])) {
      *param_1 = 0;
    }
  }
  return;
}


