// Function: FUN_14007dfb0 @ 14007dfb0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14007dfb0(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  undefined1 auVar5 [16];
  int iVar6;
  undefined8 uVar7;
  int iVar8;
  ushort uVar9;
  ushort uVar10;
  int *piVar11;
  short sVar12;
  undefined4 uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined2 uVar26;
  uint in_stack_ffffffffffffff10;
  undefined4 uVar27;
  undefined4 uVar28;
  uint uVar29;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined2 uVar30;
  
  uVar26 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar17 = DAT_140539e60;
  uVar30 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
  dVar14 = dVar14 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar7;
    dVar15 = DAT_140539fc8 - (double)(int)param_1[3] * dVar17;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    in_stack_ffffffffffffff18._8_4_ = SUB84(dVar15,0);
    in_stack_ffffffffffffff18._0_8_ = dVar15;
    in_stack_ffffffffffffff18._12_4_ = (int)((ulonglong)dVar15 >> 0x20);
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff10,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,0xff,1,0);
    uVar30 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
    uVar26 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] != 0x14) goto LAB_14007e180;
    uVar7 = FUN_140134db0(DAT_140e418c8,(int)DAT_14053a0b0,DAT_14053a138);
    *(undefined8 *)(param_1 + 0x12) = uVar7;
    if ((float)param_1[10] <= 0.0) {
      *(undefined2 *)(param_1 + 0x10) = 0;
    }
    if (DAT_14053af14 <= (float)param_1[10]) {
      *(undefined2 *)(param_1 + 0x10) = 0x8000;
    }
    piVar11 = param_1 + 5;
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    *piVar11 = *piVar11 + 1;
    local_res8 = (undefined4)uVar7;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    param_1[10] = local_res8;
    param_1[0xb] = uStackX_c;
    param_1[3] = 0;
    param_1[0x15] = 0;
  }
  else {
LAB_14007e180:
    piVar11 = param_1 + 5;
  }
  if (*piVar11 != 1) goto LAB_14007e969;
  iVar6 = param_1[3];
  dVar15 = (double)FUN_140332d90(((double)iVar6 - 0.0) * _DAT_14053aa00 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar16 = (double)FUN_140332d90();
  fVar25 = (float)dVar16 + 0.0;
  dVar16 = (double)FUN_140332d90();
  auVar5 = _DAT_14053bb20;
  dVar16 = dVar16 * _DAT_14053aa40;
  uVar28 = (undefined4)DAT_14053bb20;
  uVar27 = DAT_14053bb20._4_4_;
  if (iVar6 < 200) {
    dVar22 = *(double *)(param_1 + 0x12);
    if ((-1 < iVar6) && ((double)DAT_14053bb20 < dVar22)) {
      dVar22 = dVar22 - dVar17;
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar8 = ((int)dVar14 & 0xffffU) - (uint)uVar1;
    *(double *)(param_1 + 0x12) = dVar22;
    iVar6 = iVar8 + 0x10000;
    if (-0x8001 < iVar8) {
      iVar6 = iVar8;
    }
    iVar8 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar8 = iVar6;
    }
    uVar9 = (ushort)(int)dVar14;
    if (iVar8 < 1) {
      uVar10 = uVar1;
      if ((iVar8 < 0) && (uVar10 = uVar1 - 0x80, -0x80 < iVar8)) {
        uVar10 = uVar9;
      }
    }
    else {
      uVar10 = uVar9;
      if (0x7f < iVar8) {
        uVar10 = uVar1 + 0x80;
      }
    }
  }
  else {
    uVar10 = *(ushort *)(param_1 + 0x10);
    iVar8 = -(uint)uVar10 + 0xc000;
    iVar6 = -(uint)uVar10 + 0x1c000;
    if (-0x8001 < iVar8) {
      iVar6 = iVar8;
    }
    iVar8 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar8 = iVar6;
    }
    if (iVar8 < 1) {
      if ((iVar8 < 0) && (uVar10 = uVar10 - 0x100, -0x100 < iVar8)) {
        uVar10 = 0xc000;
      }
    }
    else if (iVar8 < 0x100) {
      uVar10 = 0xc000;
    }
    else {
      uVar10 = uVar10 + 0x100;
    }
    dVar22 = *(double *)(param_1 + 0x12) + dVar17;
    *(double *)(param_1 + 0x12) = dVar22;
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  dVar17 = (double)FUN_1403307c0();
  fVar23 = (float)(dVar17 * dVar22) + (float)param_1[10];
  param_1[10] = fVar23;
  dVar17 = (double)FUN_140332d90();
  fVar24 = (float)(dVar17 * dVar22) + (float)param_1[0xb];
  param_1[0xb] = fVar24;
  fVar4 = DAT_14053ac60;
  if ((int)param_1[3] < 200) {
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x1e;
    }
    else if (DAT_140e419b8 == 1) {
      iVar6 = 0x14;
    }
    else if (DAT_140e419b8 == 2) {
      iVar6 = 0xc;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar6 = 10;
    }
    iVar8 = 1;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x8c;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 100;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar8 = 0x50;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x3c;
    }
    uVar19 = (undefined4)((ulonglong)DAT_14053a1c8 >> 0x20);
    uVar13 = (undefined4)DAT_14053a178;
    uVar18 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    uVar20 = uVar13;
    uVar21 = uVar18;
    if (DAT_140e419b8 == 0) {
      uVar20 = (int)DAT_14053a0a0;
      uVar21 = (int)((ulonglong)DAT_14053a0a0 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar20 = (int)DAT_14053a118;
      uVar21 = (int)((ulonglong)DAT_14053a118 >> 0x20);
    }
    else if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
            (uVar20 = uVar28, uVar21 = uVar27, DAT_140e419b8 == 4)) {
      uVar20 = (int)DAT_14053a1c8;
      uVar21 = uVar19;
    }
    iVar3 = (param_1[3] - iVar6) % iVar8;
    if (3 < DAT_1407c7798) {
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0xc;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar6 = 10;
      }
      iVar8 = 1;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x50;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar8 = 0x3c;
      }
      else if (DAT_140e419b8 == 4) {
        iVar8 = 0x32;
      }
      if (DAT_140e419b8 == 0) {
        uVar20 = (int)DAT_14053a0f8;
        uVar21 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar20 = (int)DAT_14053a138;
        uVar21 = (int)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else {
        uVar20 = uVar13;
        uVar21 = uVar18;
        if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
           (uVar20 = uVar28, uVar21 = uVar27, DAT_140e419b8 == 4)) {
          uVar20 = (int)DAT_14053a1c8;
          uVar21 = uVar19;
        }
      }
    }
    iVar2 = param_1[3];
    if (iVar6 <= iVar2) {
      if ((iVar2 - iVar6) % iVar8 == 0) {
        dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                       SUB84((double)(DAT_140e445d8 - (fVar23 + DAT_14053ac60)),0));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar17 * DAT_14053aba0);
        dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                       SUB84((double)(DAT_140e445d8 - (fVar23 - fVar4)),0));
        iVar8 = (iVar2 - iVar6) % iVar8;
        *(short *)(param_1 + 0x11) = (short)(int)(dVar17 * DAT_14053aba0);
      }
      else if (((iVar2 < iVar6) || (0xef < iVar2)) ||
              (iVar8 = (iVar2 - iVar6) % iVar8, 0x27 < iVar8)) goto LAB_14007e778;
      uVar28 = DAT_14053ac2c;
      if (iVar8 == (iVar8 / 5) * 5) {
        auVar31._12_4_ = in_stack_ffffffffffffff18._12_4_;
        auVar31._0_8_ = in_stack_ffffffffffffff18._0_8_;
        auVar31._8_4_ = 1;
        dVar17 = (double)iVar3 * DAT_140539de8 + (double)CONCAT44(uVar21,uVar20);
        auVar32._8_8_ = auVar31._8_8_;
        auVar32._0_8_ = dVar17;
        FUN_14006c2f0(7,0,fVar23 + fVar4,fVar24,
                      CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42)),DAT_14053ac2c,
                      dVar17,auVar32._8_8_,0);
        auVar33._12_4_ = auVar32._12_4_;
        auVar33._0_8_ = auVar32._0_8_;
        auVar33._8_4_ = 1;
        auVar34._8_8_ = auVar33._8_8_;
        auVar34._0_8_ = dVar17;
        uVar27 = uVar28;
        FUN_14006c2f0(7,0,(float)param_1[10] - fVar4,param_1[0xb],*(undefined2 *)(param_1 + 0x11),
                      uVar28,dVar17,auVar34._8_8_,0);
        uVar30 = (undefined2)((uint)uVar27 >> 0x10);
        if (2 < DAT_140e419b8) {
          dVar17 = dVar17 - DAT_140539f28;
          auVar35._12_4_ = auVar34._12_4_;
          auVar35._0_8_ = auVar34._0_8_;
          auVar35._8_4_ = 1;
          auVar36._8_8_ = auVar35._8_8_;
          auVar36._0_8_ = dVar17;
          FUN_14006c2f0(7,0,(float)param_1[10] + fVar4,param_1[0xb],
                        *(short *)((longlong)param_1 + 0x42) + -700,uVar28,dVar17,auVar36._8_8_,0);
          auVar37._12_4_ = auVar36._12_4_;
          auVar37._0_8_ = auVar36._0_8_;
          auVar37._8_4_ = 1;
          FUN_14006c2f0(7,0,(float)param_1[10] - fVar4,param_1[0xb],*(short *)(param_1 + 0x11) + 700
                        ,uVar28,dVar17,auVar37._8_8_,0);
          uVar30 = (undefined2)((uint)uVar28 >> 0x10);
        }
      }
    }
  }
LAB_14007e778:
  sVar12 = (short)(int)dVar16;
  uVar28 = CONCAT22(uVar30,sVar12);
  FUN_1400c8410(DAT_140e44680,0x26,7,param_1[10],fVar25 + (float)param_1[0xb],uVar28,auVar5,0xff,
                0xff,0xff,0xff,1,0);
  uVar29 = CONCAT22((short)((uint)uVar28 >> 0x10),-sVar12);
  FUN_1400c8410(DAT_140e44680,0x26,7,param_1[10],fVar25 + (float)param_1[0xb],uVar29,auVar5,0xff,
                0xff,0xff,0xff,1,1);
  uVar29 = uVar29 & 0xffff0000;
  FUN_1400c8410(DAT_140e4467c,0x26,7,param_1[10],(fVar25 + (float)param_1[0xb]) - DAT_14053abf8,
                uVar29,auVar5,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44678,0x26,7,param_1[10],
                ((float)dVar15 + 0.0 + (float)param_1[0xb]) - _DAT_14053ac40,uVar29 & 0xffff0000,
                auVar5,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,2);
LAB_14007e969:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x168,3);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


