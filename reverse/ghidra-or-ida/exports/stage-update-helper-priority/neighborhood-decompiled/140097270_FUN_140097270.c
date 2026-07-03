// Function: FUN_140097270 @ 140097270
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140097270(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  ushort uVar3;
  ulonglong uVar4;
  double dVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  int iVar11;
  ushort uVar12;
  ushort uVar13;
  short sVar14;
  int iVar15;
  int *piVar16;
  float fVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar27;
  uint in_stack_ffffffffffffff00;
  undefined4 uVar28;
  undefined2 uVar31;
  undefined4 uVar29;
  uint uVar30;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  dVar18 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar5 = DAT_140539fc8;
  dVar22 = DAT_140539e60;
  uVar31 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  dVar18 = dVar18 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar10;
    dVar20 = dVar5 - (double)(int)param_1[3] * dVar22;
    uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar20,0);
    in_stack_ffffffffffffff08._0_8_ = dVar20;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar20 >> 0x20);
    in_stack_ffffffffffffff00 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff00,
                  in_stack_ffffffffffffff08,0xff,0xff,0xff,0xff,1,0);
    uVar31 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
    uVar27 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      uVar10 = FUN_140134db0(DAT_140e418c8,(int)DAT_14053a0f8,DAT_14053a178);
      *(undefined8 *)(param_1 + 0x12) = uVar10;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      piVar16 = param_1 + 5;
      uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      *piVar16 = *piVar16 + 1;
      local_res8 = (undefined4)uVar10;
      uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
      goto LAB_14009744d;
    }
  }
  piVar16 = param_1 + 5;
LAB_14009744d:
  dVar21 = DAT_14053a020;
  dVar20 = DAT_140539d28;
  if (*piVar16 == 1) {
    iVar15 = param_1[3];
    dVar19 = (double)FUN_140332d90(((double)iVar15 - 0.0) * DAT_14053a998 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar20 = (double)FUN_140332d90(((double)iVar15 - DAT_14053a240) * DAT_14053a998 * dVar21 *
                                   dVar20);
    fVar17 = (float)dVar20 + 0.0;
    dVar20 = (double)FUN_140332d90();
    dVar20 = dVar20 * _DAT_14053aaf8;
    dVar21 = (double)FUN_140332d90();
    dVar21 = dVar21 * _DAT_14053aaf8;
    fVar1 = (float)param_1[10];
    fVar25 = fVar17 + (float)param_1[0xb] + DAT_14053ac58;
    if (iVar15 < 0x96) {
      dVar2 = *(double *)(param_1 + 0x12);
      if ((-1 < iVar15) && (dVar5 < dVar2)) {
        dVar2 = dVar2 - dVar22;
      }
      uVar3 = *(ushort *)(param_1 + 0x10);
      iVar11 = ((int)dVar18 & 0xffffU) - (uint)uVar3;
      *(double *)(param_1 + 0x12) = dVar2;
      iVar15 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar15 = iVar11;
      }
      iVar11 = iVar15 + -0x10000;
      if (iVar15 < 0x8001) {
        iVar11 = iVar15;
      }
      uVar12 = (ushort)(int)dVar18;
      if (iVar11 < 1) {
        uVar13 = uVar3;
        if ((iVar11 < 0) && (uVar13 = uVar3 - 0x80, -0x80 < iVar11)) {
          uVar13 = uVar12;
        }
      }
      else {
        uVar13 = uVar12;
        if (0x7f < iVar11) {
          uVar13 = uVar3 + 0x80;
        }
      }
    }
    else {
      uVar13 = *(ushort *)(param_1 + 0x10);
      iVar11 = -(uint)uVar13 + 0xc000;
      iVar15 = -(uint)uVar13 + 0x1c000;
      if (-0x8001 < iVar11) {
        iVar15 = iVar11;
      }
      iVar11 = iVar15 + -0x10000;
      if (iVar15 < 0x8001) {
        iVar11 = iVar15;
      }
      if (iVar11 < 1) {
        if ((iVar11 < 0) && (uVar13 = uVar13 - 0x100, -0x100 < iVar11)) {
          uVar13 = 0xc000;
        }
      }
      else if (iVar11 < 0x100) {
        uVar13 = 0xc000;
      }
      else {
        uVar13 = uVar13 + 0x100;
      }
      dVar2 = *(double *)(param_1 + 0x12) + dVar22;
      *(double *)(param_1 + 0x12) = dVar2;
    }
    *(ushort *)(param_1 + 0x10) = uVar13;
    dVar22 = (double)FUN_1403307c0();
    fVar26 = (float)(dVar22 * dVar2) + (float)param_1[10];
    param_1[10] = fVar26;
    dVar22 = (double)FUN_140332d90();
    uVar9 = _UNK_14053bb2c;
    uVar8 = _UNK_14053bb28;
    uVar7 = _UNK_14053bb24;
    uVar6 = _DAT_14053bb20;
    param_1[0xb] = (float)(dVar22 * dVar2) + (float)param_1[0xb];
    if (((((int)param_1[3] < 0x96) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= fVar1)) &&
        (fVar1 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
       ((DAT_14053aca8 <= fVar25 && (fVar25 <= DAT_14053aef4)))) {
      dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                     SUB84((double)(DAT_140e445d8 - fVar1),0));
      uVar29 = DAT_14053ac2c;
      iVar15 = 1;
      if (DAT_140e419b8 == 0) {
        iVar15 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar15 = 0xe;
      }
      else if (DAT_140e419b8 == 2) {
        iVar15 = 10;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar15 = 5;
      }
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x37;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x1e;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 0x18;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0x15;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x10;
      }
      if (DAT_140e419b8 == 0) {
        uVar23 = (undefined4)DAT_14053a0b0;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar23 = (undefined4)DAT_14053a0f8;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar23 = (undefined4)DAT_14053a118;
        uVar24 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar23 = (undefined4)DAT_14053a158;
        uVar24 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
      }
      else {
        uVar23 = uVar6;
        uVar24 = uVar7;
        if (DAT_140e419b8 == 4) {
          uVar23 = (undefined4)DAT_14053a1b8;
          uVar24 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
        }
      }
      if (((iVar15 <= (int)param_1[3]) &&
          (uVar4 = (longlong)(param_1[3] - iVar15) % (longlong)iVar11, (int)uVar4 == 0)) &&
         (fVar26 < DAT_14053ae90)) {
        auVar32._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar32._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar32._8_4_ = 1;
        auVar33._8_8_ = auVar32._8_8_;
        auVar33._0_8_ = CONCAT44(uVar24,uVar23);
        sVar14 = (short)(((int)(dVar22 * DAT_14053aba0) & 0xffffU) + 0x400 >> 0xb) * 0x800;
        uVar28 = DAT_14053ac2c;
        FUN_14006c2f0(8,uVar4 & 0xffffffff,fVar1,fVar25,CONCAT22(uVar27,sVar14),DAT_14053ac2c,
                      CONCAT44(uVar24,uVar23),auVar33._8_8_,0);
        uVar31 = (undefined2)((uint)uVar28 >> 0x10);
        if (DAT_140e419b8 == 2) {
          dVar22 = (double)CONCAT44(uVar24,uVar23) + DAT_140539f00;
          auVar34._12_4_ = auVar33._12_4_;
          auVar34._0_8_ = auVar33._0_8_;
          auVar34._8_4_ = 1;
          auVar33._8_8_ = auVar34._8_8_;
          auVar33._0_8_ = dVar22;
          uVar28 = uVar29;
          FUN_14006c2f0(8,0,fVar1,fVar25,sVar14,uVar29,dVar22,auVar33._8_8_,0);
          uVar31 = (undefined2)((uint)uVar28 >> 0x10);
        }
        if (2 < DAT_140e419b8) {
          dVar22 = (double)CONCAT44(uVar24,uVar23) - DAT_140539f90;
          iVar15 = 0;
          do {
            auVar35._12_4_ = auVar33._12_4_;
            auVar35._0_8_ = auVar33._0_8_;
            auVar35._8_4_ = 1;
            auVar33._8_8_ = auVar35._8_8_;
            auVar33._0_8_ = dVar22;
            uVar23 = uVar29;
            FUN_14006c2f0(8,0,fVar1,fVar25,(short)iVar15 * 4000 + sVar14 + -2000,uVar29,dVar22,
                          auVar33._8_8_,0);
            uVar31 = (undefined2)((uint)uVar23 >> 0x10);
            iVar15 = iVar15 + 1;
          } while (iVar15 < 2);
        }
      }
    }
    fVar1 = DAT_14053aa20;
    auVar36._4_4_ = uVar7;
    auVar36._0_4_ = uVar6;
    auVar36._8_4_ = uVar8;
    auVar36._12_4_ = uVar9;
    sVar14 = (short)(int)dVar21;
    uVar29 = CONCAT22(uVar31,sVar14);
    FUN_1400c8410(DAT_140e4472c,0x23,7,(float)param_1[10] + DAT_14053aa20,
                  fVar17 + (float)param_1[0xb],uVar29,auVar36,0xff,0xff,0xff,0xff,1,0);
    auVar37._4_4_ = uVar7;
    auVar37._0_4_ = uVar6;
    auVar37._8_4_ = uVar8;
    auVar37._12_4_ = uVar9;
    uVar29 = CONCAT22((short)((uint)uVar29 >> 0x10),-sVar14);
    FUN_1400c8410(DAT_140e4472c,0x23,7,(float)param_1[10] - fVar1,fVar17 + (float)param_1[0xb],
                  uVar29,auVar37,0xff,0xff,0xff,0xff,1,1);
    auVar38._4_4_ = uVar7;
    auVar38._0_4_ = uVar6;
    auVar38._8_4_ = uVar8;
    auVar38._12_4_ = uVar9;
    sVar14 = (short)(int)dVar20;
    uVar29 = CONCAT22((short)((uint)uVar29 >> 0x10),sVar14);
    FUN_1400c8410(DAT_140e44728,0x23,7,(float)param_1[10] + fVar1,fVar17 + (float)param_1[0xb],
                  uVar29,auVar38,0xff,0xff,0xff,0xff,1,0);
    auVar39._4_4_ = uVar7;
    auVar39._0_4_ = uVar6;
    auVar39._8_4_ = uVar8;
    auVar39._12_4_ = uVar9;
    uVar30 = CONCAT22((short)((uint)uVar29 >> 0x10),-sVar14);
    FUN_1400c8410(DAT_140e44728,0x23,7,(float)param_1[10] - fVar1,fVar17 + (float)param_1[0xb],
                  uVar30,auVar39,0xff,0xff,0xff,0xff,1,1);
    auVar40._4_4_ = uVar7;
    auVar40._0_4_ = uVar6;
    auVar40._8_4_ = uVar8;
    auVar40._12_4_ = uVar9;
    uVar30 = uVar30 & 0xffff0000;
    FUN_1400c8410(DAT_140e44724,0x23,7,param_1[10],fVar17 + (float)param_1[0xb],uVar30,auVar40,0xff,
                  0xff,0xff,0xff,1,0);
    auVar41._4_4_ = uVar7;
    auVar41._0_4_ = uVar6;
    auVar41._8_4_ = uVar8;
    auVar41._12_4_ = uVar9;
    FUN_1400c8410(DAT_140e44720,0x23,7,param_1[10],
                  (float)dVar19 + 0.0 + (float)param_1[0xb] + DAT_140539fc0,uVar30 & 0xffff0000,
                  auVar41,0xff,0xff,0xff,0xff,1,0);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0xf0,3);
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


