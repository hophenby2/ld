// Function: FUN_140097d30 @ 140097d30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140097d30(undefined4 *param_1)

{
  ushort *puVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  undefined4 uVar11;
  short sVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff28;
  undefined2 uVar22;
  undefined4 uVar21;
  uint in_stack_ffffffffffffff30;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined2 uVar25;
  undefined1 in_stack_ffffffffffffff38 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  
  uVar22 = (undefined2)((uint)in_stack_ffffffffffffff28 >> 0x10);
  dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar14 = DAT_14053a018;
  uVar25 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
  uVar9 = (uint)(dVar13 * DAT_14053aba0);
  if (param_1[5] == 0) {
    uVar3 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar3;
    dVar14 = dVar14 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar3 >> 0x20);
    in_stack_ffffffffffffff38._8_4_ = SUB84(dVar14,0);
    in_stack_ffffffffffffff38._0_8_ = dVar14;
    in_stack_ffffffffffffff38._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
    in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff30,
                  in_stack_ffffffffffffff38,0xff,0xff,0xff,0xff,1,0);
    uVar25 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
    uVar22 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4028000000000000;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 2000;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x7830;
      }
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140098648;
  uVar2 = param_1[3];
  dVar14 = (double)FUN_140332d90(((double)(int)uVar2 - 0.0) * _DAT_14053aa08 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar14 = dVar14 * _DAT_14053aa40;
  dVar13 = (double)FUN_140332d90();
  dVar13 = dVar13 * _DAT_14053aa40;
  uVar10 = (ushort)uVar9;
  if ((int)uVar2 < 100) {
    dVar15 = *(double *)(param_1 + 0x12);
    if ((uVar2 < 0x65) && (0.0 < dVar15)) {
      dVar15 = dVar15 - DAT_140539e70;
    }
    uVar5 = *(ushort *)(param_1 + 0x10);
    iVar4 = (uVar9 & 0xffff) - (uint)uVar5;
    *(double *)(param_1 + 0x12) = dVar15;
    iVar8 = iVar4 + 0x10000;
    if (-0x8001 < iVar4) {
      iVar8 = iVar4;
    }
    iVar4 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar4 = iVar8;
    }
    if (iVar4 < 1) {
      if ((iVar4 < 0) && (uVar5 = uVar5 - 0x20, -0x20 < iVar4)) {
        uVar5 = uVar10;
      }
      *(ushort *)(param_1 + 0x10) = uVar5;
    }
    else if (iVar4 < 0x20) {
      *(ushort *)(param_1 + 0x10) = uVar10;
    }
    else {
      *(ushort *)(param_1 + 0x10) = uVar5 + 0x20;
    }
  }
  else {
    if ((int)uVar2 < 0xf0) {
      puVar1 = (ushort *)(param_1 + 0x10);
      if (uVar2 == 100) {
        *puVar1 = uVar10;
LAB_140097fec:
        *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + _DAT_140539e28;
      }
      else if ((int)uVar2 < 0x82) goto LAB_140097fec;
      uVar5 = *puVar1;
      iVar4 = (uVar9 & 0xffff) - (uint)uVar5;
      iVar8 = iVar4 + 0x10000;
      if (-0x8001 < iVar4) {
        iVar8 = iVar4;
      }
      iVar4 = iVar8 + -0x10000;
      if (iVar8 < 0x8001) {
        iVar4 = iVar8;
      }
      if (iVar4 < 1) {
        uVar6 = uVar5;
        if ((iVar4 < 0) && (uVar6 = uVar5 - 0x80, -0x80 < iVar4)) {
          uVar6 = uVar10;
        }
      }
      else {
        uVar6 = uVar10;
        if (0x7f < iVar4) {
          uVar6 = uVar5 + 0x80;
        }
      }
      *puVar1 = uVar6;
      if ((int)uVar2 < 0xf0) goto LAB_14009806e;
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) - DAT_140539e60;
  }
LAB_14009806e:
  dVar15 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar15 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar20;
  dVar16 = (double)FUN_140332d90();
  uVar3 = _UNK_14053bb28;
  dVar15 = _DAT_14053bb20;
  fVar17 = (float)(dVar16 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar17;
  fVar19 = DAT_140e445d8;
  if ((int)uVar2 < 0xf0) {
    fVar17 = fVar17 + DAT_14053aa20;
    dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar17),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    iVar8 = 1;
    dVar16 = dVar16 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x60;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x40;
    }
    else if (DAT_140e419b8 == 2) {
      iVar8 = 0x32;
    }
    else if (DAT_140e419b8 == 3) {
      iVar8 = 0x28;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x24;
    }
    uVar11 = 1;
    if (DAT_140e419b8 == 0) {
      uVar11 = 0;
    }
    else if (DAT_140e419b8 == 1) {
      uVar11 = 0x8ae;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      uVar11 = 0xd05;
    }
    dVar18 = DAT_14053a0f8;
    if (((DAT_140e419b8 != 0) && (dVar18 = DAT_14053a138, DAT_140e419b8 != 1)) &&
       ((dVar18 = DAT_14053a158, DAT_140e419b8 != 2 &&
        ((dVar18 = DAT_14053a178, DAT_140e419b8 != 3 && (dVar18 = dVar15, DAT_140e419b8 == 4)))))) {
      dVar18 = DAT_14053a1b8;
    }
    iVar4 = param_1[3];
    iVar7 = (iVar4 + -0x40) % iVar8;
    dVar18 = (double)iVar7 * DAT_140539e30 + dVar18;
    uVar10 = (ushort)(int)dVar16;
    if ((iVar4 - 0x40U < 0xb0) && (iVar7 == 0)) {
      *(ushort *)((longlong)param_1 + 0x42) = uVar10;
      fVar19 = DAT_140e445d8;
LAB_140098230:
      uVar24 = DAT_14053ac2c;
      iVar8 = (iVar4 + -0x40) % iVar8;
      if ((((iVar8 == (iVar8 / 5) * 5) && (fVar19 / DAT_14053ab70 + 0.0 <= fVar20)) &&
          (fVar20 <= fVar19 / DAT_14053ab70 + DAT_14053aec0)) &&
         ((0.0 <= fVar17 && (fVar17 <= DAT_14053af14)))) {
        auVar26._12_4_ = in_stack_ffffffffffffff38._12_4_;
        auVar26._0_8_ = in_stack_ffffffffffffff38._0_8_;
        auVar26._8_4_ = 1;
        auVar27._8_8_ = auVar26._8_8_;
        auVar27._0_8_ = dVar18;
        uVar21 = CONCAT22(uVar22,*(undefined2 *)((longlong)param_1 + 0x42));
        uVar23 = DAT_14053ac2c;
        FUN_14006c2f0(7,0,fVar20,fVar17,uVar21,DAT_14053ac2c,dVar18,auVar27._8_8_,0);
        uVar25 = (undefined2)((uint)uVar23 >> 0x10);
        uVar22 = (undefined2)((uint)uVar21 >> 0x10);
        if (0 < DAT_140e419b8) {
          auVar28._12_4_ = auVar27._12_4_;
          auVar28._0_8_ = auVar27._0_8_;
          auVar28._8_4_ = 1;
          auVar27._8_8_ = auVar28._8_8_;
          auVar27._0_8_ = dVar18 - dVar15;
          uVar21 = CONCAT22(uVar22,*(undefined2 *)((longlong)param_1 + 0x42));
          uVar23 = uVar24;
          FUN_1400709b0(7,0,fVar20,fVar17,uVar21,uVar24,dVar18 - dVar15,auVar27._8_8_,2,uVar11,0);
          uVar25 = (undefined2)((uint)uVar23 >> 0x10);
          uVar22 = (undefined2)((uint)uVar21 >> 0x10);
        }
        if (2 < DAT_140e419b8) {
          auVar29._12_4_ = auVar27._12_4_;
          auVar29._0_8_ = auVar27._0_8_;
          auVar29._8_4_ = 1;
          auVar30._8_8_ = auVar29._8_8_;
          auVar30._0_8_ = dVar18 + DAT_140539fb8;
          FUN_14006c2f0(7,0,fVar20,fVar17,CONCAT22(uVar22,*(undefined2 *)((longlong)param_1 + 0x42))
                        ,uVar24,dVar18 + DAT_140539fb8,auVar30._8_8_,0);
          auVar31._12_4_ = auVar30._12_4_;
          auVar31._0_8_ = auVar30._0_8_;
          auVar31._8_4_ = 1;
          FUN_1400709b0(7,0,fVar20,fVar17,*(undefined2 *)((longlong)param_1 + 0x42),uVar24,
                        dVar18 + DAT_140539f28,auVar31._8_8_,2,uVar11,0);
          uVar25 = (undefined2)((uint)uVar24 >> 0x10);
        }
      }
    }
    else if ((iVar4 - 0x40U < 0xb0) && (iVar7 < 0x1e)) goto LAB_140098230;
    uVar5 = *(ushort *)((longlong)param_1 + 0x42);
    iVar4 = ((int)dVar16 & 0xffffU) - (uint)uVar5;
    iVar8 = iVar4 + 0x10000;
    if (-0x8001 < iVar4) {
      iVar8 = iVar4;
    }
    iVar4 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar4 = iVar8;
    }
    if (iVar4 < 1) {
      uVar6 = uVar5;
      if ((iVar4 < 0) && (uVar6 = uVar5 - 0x20, -0x20 < iVar4)) {
        uVar6 = uVar10;
      }
    }
    else {
      uVar6 = uVar10;
      if (0x1f < iVar4) {
        uVar6 = uVar5 + 0x20;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar6;
  }
  sVar12 = (short)(int)dVar13;
  uVar11 = CONCAT22(uVar25,sVar12);
  FUN_1400c8410(DAT_140e44c10,0x20,7,param_1[10],param_1[0xb],uVar11,dVar15,uVar3,0xff,0xff,0xff,
                0xff,1,0);
  uVar11 = CONCAT22((short)((uint)uVar11 >> 0x10),-sVar12);
  FUN_1400c8410(DAT_140e44c10,0x20,7,param_1[10],param_1[0xb],uVar11,dVar15,uVar3,0xff,0xff,0xff,
                0xff,1,1);
  sVar12 = (short)(int)dVar14;
  uVar11 = CONCAT22((short)((uint)uVar11 >> 0x10),sVar12);
  FUN_1400c8410(DAT_140e44c0c,0x20,7,param_1[10],param_1[0xb],uVar11,dVar15,uVar3,0xff,0xff,0xff,
                0xff,1,0);
  uVar9 = CONCAT22((short)((uint)uVar11 >> 0x10),-sVar12);
  FUN_1400c8410(DAT_140e44c0c,0x20,7,param_1[10],param_1[0xb],uVar9,dVar15,uVar3,0xff,0xff,0xff,0xff
                ,1,1);
  FUN_1400c8410(DAT_140e44c08,0x20,7,param_1[10],param_1[0xb],uVar9 & 0xffff0000,dVar15,uVar3,0xff,
                0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_140098648:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,6);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
        (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) &&
     (0x77 < (int)param_1[3])) {
    *param_1 = 0;
  }
  return;
}


