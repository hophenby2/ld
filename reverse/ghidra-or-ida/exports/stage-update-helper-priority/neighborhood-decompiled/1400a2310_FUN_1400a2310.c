// Function: FUN_1400a2310 @ 1400a2310
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a2310(undefined4 *param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float fVar16;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff18;
  undefined2 uVar17;
  uint in_stack_ffffffffffffff20;
  undefined1 in_stack_ffffffffffffff28 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  
  dVar13 = DAT_140539e60;
  uVar17 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  if (param_1[5] == 0) {
    uVar2 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar2;
    dVar14 = DAT_140539fc8 - (double)(int)param_1[3] * dVar13;
    uStackX_c = (undefined4)((ulonglong)uVar2 >> 0x20);
    in_stack_ffffffffffffff28._8_4_ = SUB84(dVar14,0);
    in_stack_ffffffffffffff28._0_8_ = dVar14;
    in_stack_ffffffffffffff28._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
    in_stack_ffffffffffffff20 = in_stack_ffffffffffffff20 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff20,
                  in_stack_ffffffffffffff28,0xff,0xff,0xff,0xff,1,0);
    uVar17 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      uVar2 = FUN_140134db0(DAT_140e418c8,SUB84(DAT_14053a0f8,0),DAT_14053a1b8);
      *(undefined8 *)(param_1 + 0x12) = uVar2;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      if (DAT_14053af14 <= (float)param_1[0xb]) {
        uVar2 = FUN_140134db0(DAT_140e418c8,(int)DAT_14053a1e8,DAT_14053a218);
        *(undefined8 *)(param_1 + 0x12) = uVar2;
        *(undefined2 *)(param_1 + 0x10) = 0xc000;
      }
      *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
      uVar2 = FUN_1401346a0(*(undefined8 *)(param_1 + 0xc),0xffffffc4);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar2;
      uStackX_c = (undefined4)((ulonglong)uVar2 >> 0x20);
      param_1[0xc] = local_res8;
      param_1[0xd] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_1400a2bef;
  dVar12 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((float)param_1[0xb] + DAT_14053ac5c)),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar14 = DAT_140539f68;
  uVar7 = (uint)(dVar12 * DAT_14053aba0);
  if ((ushort)((ushort)uVar7 - 4000) < 0xb060) {
    if (0x705f < (ushort)uVar7) {
      uVar7 = 0x7060;
    }
  }
  else {
    uVar7 = 4000;
  }
  uVar6 = (ushort)uVar7;
  if ((int)param_1[3] < 200) {
    dVar12 = *(double *)(param_1 + 0x12);
    if ((-1 < (int)param_1[3]) && (DAT_140539f00 < dVar12)) {
      dVar12 = dVar12 - dVar13;
    }
    *(double *)(param_1 + 0x12) = dVar12;
    if (dVar12 < dVar14) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar3 = (uVar7 & 0xffff) - (uint)uVar1;
      iVar8 = iVar3 + 0x10000;
      if (-0x8001 < iVar3) {
        iVar8 = iVar3;
      }
      iVar3 = iVar8 + -0x10000;
      if (iVar8 < 0x8001) {
        iVar3 = iVar8;
      }
      if (iVar3 < 1) {
        uVar5 = uVar1;
        if ((iVar3 < 0) && (uVar5 = uVar1 - 0x40, -0x40 < iVar3)) {
          uVar5 = uVar6;
        }
      }
      else {
        uVar5 = uVar6;
        if (0x3f < iVar3) {
          uVar5 = uVar1 + 0x40;
        }
      }
      goto LAB_1400a2654;
    }
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x10);
    iVar3 = -(uint)uVar5 + 0xc000;
    iVar8 = -(uint)uVar5 + 0x1c000;
    if (-0x8001 < iVar3) {
      iVar8 = iVar3;
    }
    iVar3 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar3 = iVar8;
    }
    if (iVar3 < 1) {
      if ((iVar3 < 0) && (uVar5 = uVar5 - 0x200, -0x200 < iVar3)) {
        uVar5 = 0xc000;
      }
    }
    else if (iVar3 < 0x200) {
      uVar5 = 0xc000;
    }
    else {
      uVar5 = uVar5 + 0x200;
    }
    dVar12 = *(double *)(param_1 + 0x12) + _DAT_140539e28;
    *(double *)(param_1 + 0x12) = dVar12;
LAB_1400a2654:
    *(ushort *)(param_1 + 0x10) = uVar5;
  }
  dVar13 = (double)FUN_1403307c0();
  fVar16 = (float)(dVar13 * dVar12) + (float)param_1[0xc];
  param_1[0xc] = fVar16;
  dVar13 = (double)FUN_140332d90();
  uVar5 = *(ushort *)((longlong)param_1 + 0x42);
  uVar1 = uVar6 - uVar5;
  uVar4 = (uint)uVar1;
  if (0x8000 < uVar1) {
    uVar4 = 0x10000 - uVar1;
  }
  iVar3 = (uVar7 & 0xffff) - (uint)uVar5;
  fVar15 = (float)(dVar13 * dVar12) + (float)param_1[0xd];
  iVar9 = (int)uVar4 / 10 + 0x30;
  param_1[0xd] = fVar15;
  iVar8 = iVar3 + 0x10000;
  if (-0x8001 < iVar3) {
    iVar8 = iVar3;
  }
  iVar3 = iVar8 + -0x10000;
  if (iVar8 < 0x8001) {
    iVar3 = iVar8;
  }
  if (iVar3 < 1) {
    uVar1 = uVar5;
    if ((iVar3 < 0) && (uVar1 = uVar5 - (short)iVar9, -iVar9 < iVar3)) {
      uVar1 = uVar6;
    }
  }
  else {
    uVar1 = uVar6;
    if (iVar9 <= iVar3) {
      uVar1 = uVar5 + (short)iVar9;
    }
  }
  *(ushort *)((longlong)param_1 + 0x42) = uVar1;
  dVar14 = (double)FUN_1403307c0();
  dVar14 = dVar14 * DAT_14053a278;
  fVar16 = (float)dVar14 + fVar16;
  dVar12 = (double)FUN_140332d90();
  fVar15 = fVar15 + DAT_14053ac5c;
  dVar12 = dVar12 * DAT_14053a278;
  param_1[10] = fVar16;
  param_1[0xb] = fVar15 + (float)dVar12;
  uVar2 = _UNK_14053bb28;
  dVar13 = _DAT_14053bb20;
  if ((int)param_1[3] < 200) {
    fVar16 = (float)dVar14 + fVar16;
    iVar8 = 1;
    fVar15 = (float)dVar12 + (float)param_1[0xb];
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x2d;
    }
    else if (DAT_140e419b8 == 2) {
      iVar8 = 0x21;
    }
    else if (DAT_140e419b8 == 3) {
      iVar8 = 0x1e;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x14;
    }
    iVar3 = 1;
    if (DAT_140e419b8 == 0) {
      iVar3 = 3;
    }
    else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
      iVar3 = 5;
    }
    else if (DAT_140e419b8 == 4) {
      iVar3 = 7;
    }
    dVar14 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
       ((dVar14 = DAT_14053a138, DAT_140e419b8 != 2 &&
        ((DAT_140e419b8 == 3 || (dVar14 = _DAT_14053bb20, DAT_140e419b8 == 4)))))) {
      dVar14 = DAT_14053a1b8;
    }
    iVar9 = 0x14;
    if (DAT_14053af14 <= (float)param_1[0xf]) {
      iVar9 = 0x46;
    }
    if ((iVar9 <= (int)param_1[3]) && ((param_1[3] - iVar9) % iVar8 == 0)) {
      fVar10 = (float)FUN_140334430(fVar16 - DAT_140e445d8,DAT_140539fc0);
      fVar11 = (float)FUN_140334430(fVar15 - DAT_140e445dc);
      if (fVar10 + fVar11 < 0.0) {
        fVar10 = (float)FUN_1403352f8();
      }
      else {
        fVar10 = SQRT(fVar10 + fVar11);
      }
      if (DAT_14053acfc < fVar10) {
        auVar18._12_4_ = in_stack_ffffffffffffff28._12_4_;
        auVar18._0_8_ = in_stack_ffffffffffffff28._0_8_;
        auVar18._8_4_ = 1;
        auVar19._8_8_ = auVar18._8_8_;
        auVar19._0_8_ = dVar14;
        in_stack_ffffffffffffff20 = 0;
        FUN_1400709b0(0xc,0,fVar16,fVar15,CONCAT22(uVar17,uVar1),0,dVar14,auVar19._8_8_,iVar3,
                      iVar3 * 0x1c2 + -0x1c2,0);
        if (2 < DAT_140e419b8) {
          auVar20._12_4_ = auVar19._12_4_;
          auVar20._0_8_ = auVar19._0_8_;
          auVar20._8_4_ = 1;
          in_stack_ffffffffffffff20 = 0;
          FUN_1400709b0(0xc,0,fVar16,fVar15,*(undefined2 *)((longlong)param_1 + 0x42),0,
                        dVar14 - DAT_140539f90,auVar20._8_8_,iVar3,3000,0);
        }
      }
    }
  }
  dVar14 = (double)FUN_1403307c0();
  dVar14 = dVar14 * DAT_14053a390;
  fVar16 = (float)param_1[10];
  dVar12 = (double)FUN_140332d90();
  dVar12 = dVar12 * DAT_14053a390;
  fVar15 = (float)param_1[0xb];
  FUN_1400c8410(DAT_140e4479c,0x23,7,param_1[0xc],param_1[0xd],
                in_stack_ffffffffffffff20 & 0xffff0000,dVar13,uVar2,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e447a0,0x23,7,param_1[10],param_1[0xb],
                *(undefined2 *)((longlong)param_1 + 0x42),dVar13,uVar2,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e447a4,0x23,8,(float)dVar14 + fVar16,(float)dVar12 + fVar15,
                *(undefined2 *)((longlong)param_1 + 0x42),dVar13,uVar2,0xff,0xff,0xff,0x40,1,0);
  iVar8 = 0;
  do {
    FUN_1400c8410(DAT_140e44798,0x23,7,param_1[0xc],param_1[0xd],
                  (short)iVar8 * -0x8000 + *(short *)(param_1 + 3) * 0xf3c,dVar13,uVar2,0xff,0xff,
                  0xff,0xff,1,0);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  FUN_140079c10(param_1,2);
LAB_1400a2bef:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x168,4);
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


