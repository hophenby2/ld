// Function: FUN_1400b0120 @ 1400b0120
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b0120(undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  double dVar26;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar27;
  uint in_stack_fffffffffffffef0;
  undefined2 uVar29;
  undefined4 uVar28;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xd]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[0xc]),0));
  dVar19 = DAT_14053aba0;
  dVar26 = DAT_140539e60;
  uVar29 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
  dVar15 = dVar15 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar5;
    dVar2 = DAT_140539fc8 - (double)(int)param_1[3] * dVar26;
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_fffffffffffffef8._8_4_ = SUB84(dVar2,0);
    in_stack_fffffffffffffef8._0_8_ = dVar2;
    in_stack_fffffffffffffef8._12_4_ = (int)((ulonglong)dVar2 >> 0x20);
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_fffffffffffffef0,
                  in_stack_fffffffffffffef8,0xff,0xff,0xff,0xff,1,0);
    uVar29 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
    uVar27 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4000000000000000;
      *(undefined2 *)(param_1 + 0x10) = 0x4000;
      uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffc4);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar5;
      uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  fVar22 = DAT_14053ab70;
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_1400b0ac1;
  iVar1 = param_1[3];
  dVar16 = (double)FUN_140332d90(((double)iVar1 - 0.0) * DAT_14053a988 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar14 = (float)dVar16 - DAT_14053acb0;
  dVar17 = (double)FUN_140332d90();
  uVar9 = *(ushort *)(param_1 + 0x10);
  dVar16 = *(double *)(param_1 + 0x12);
  fVar20 = (float)dVar17 - DAT_14053aa20;
  dVar17 = (double)FUN_1403307c0();
  dVar18 = (double)FUN_140332d90();
  if (iVar1 < 0xb4) {
    uVar12 = ((uint)(DAT_140e418c8 - iVar1) >> 0x1e ^ DAT_140e418c8 - iVar1) * 0x6c078965 + 1;
    fVar23 = (float)(dVar16 * dVar17) + (float)param_1[0xc];
    uVar11 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd10 = uVar11;
    param_1[0xc] = fVar23;
    fVar25 = (float)(dVar16 * dVar18) + (float)param_1[0xd];
    param_1[0xd] = fVar25;
    DAT_140e9fd14 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar12 = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    DAT_140e9fd1c = uVar12;
    dVar17 = (double)FUN_140332d90();
    dVar16 = _DAT_14053b158;
    if ((uVar12 & 1) == 0) {
      dVar16 = DAT_14053a3a0;
    }
    iVar6 = ((int)dVar15 & 0xffffU) - (uint)uVar9;
    iVar7 = iVar6 + 0x10000;
    if (-0x8001 < iVar6) {
      iVar7 = iVar6;
    }
    iVar6 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar6 = iVar7;
    }
    param_1[10] = (float)(dVar17 * dVar16) + 0.0 + fVar23;
    param_1[0xb] = fVar25;
    uVar13 = (ushort)(int)dVar15;
    if (iVar6 < 1) {
      uVar10 = uVar9;
      if ((iVar6 < 0) && (uVar10 = uVar9 - 0x40, -0x40 < iVar6)) {
        uVar10 = uVar13;
      }
    }
    else {
      uVar10 = uVar13;
      if (0x3f < iVar6) {
        uVar10 = uVar9 + 0x40;
      }
    }
  }
  else {
    iVar6 = -(uint)uVar9 + 0xc000;
    iVar7 = -(uint)uVar9 + 0x1c000;
    if (-0x8001 < iVar6) {
      iVar7 = iVar6;
    }
    iVar6 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar6 = iVar7;
    }
    param_1[10] = (float)(dVar16 * dVar17) + (float)param_1[10];
    param_1[0xb] = (float)(dVar16 * dVar18) + (float)param_1[0xb];
    if (iVar6 < 1) {
      if ((iVar6 < 0) && (uVar9 = uVar9 - 0xa0, -0xa0 < iVar6)) {
        uVar9 = 0xc000;
      }
    }
    else if (iVar6 < 0xa0) {
      uVar9 = 0xc000;
    }
    else {
      uVar9 = uVar9 + 0xa0;
    }
    *(double *)(param_1 + 0x12) = dVar16 + dVar26;
    uVar10 = uVar9;
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  fVar25 = DAT_14053ac60;
  fVar23 = (float)param_1[10];
  fVar24 = fVar14 + (float)param_1[0xb] + DAT_14053ac60;
  iVar7 = (iVar1 + -0x28) % 0x32;
  dVar26 = (double)iVar7 * dVar26 + DAT_14053a1a8;
  if ((iVar1 - 0x28U < 0x8c) && (iVar7 == 0)) {
    dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                   SUB84((double)(DAT_140e445d8 - fVar23),0));
    *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar15 * dVar19);
LAB_1400b0653:
    fVar21 = DAT_140e445d8 / fVar22;
    if ((((fVar21 + 0.0 <= fVar23) && (fVar23 <= fVar21 + DAT_14053aec0)) && (0.0 <= fVar24)) &&
       (fVar24 <= DAT_14053af14)) {
      auVar30._12_4_ = in_stack_fffffffffffffef8._12_4_;
      auVar30._0_8_ = in_stack_fffffffffffffef8._0_8_;
      auVar30._8_4_ = 1;
      auVar31._8_8_ = auVar30._8_8_;
      auVar31._0_8_ = dVar26;
      FUN_14006c2f0(0xc,0,fVar23,fVar24,CONCAT22(uVar27,*(undefined2 *)((longlong)param_1 + 0x42)),0
                    ,dVar26,auVar31._8_8_,0);
      fVar24 = fVar24 - DAT_14053ac80;
      auVar32._12_4_ = auVar31._12_4_;
      auVar32._0_8_ = auVar31._0_8_;
      auVar32._8_4_ = 1;
      auVar33._8_8_ = auVar32._8_8_;
      auVar33._0_8_ = dVar26;
      FUN_14006c2f0(4,0,fVar23 + fVar25,fVar24,*(undefined2 *)((longlong)param_1 + 0x42),0,dVar26,
                    auVar33._8_8_,0);
      auVar34._12_4_ = auVar33._12_4_;
      auVar34._0_8_ = auVar33._0_8_;
      auVar34._8_4_ = 1;
      uVar29 = 0;
      FUN_14006c2f0(4,0,fVar23 - fVar25,fVar24,*(undefined2 *)((longlong)param_1 + 0x42),0,dVar26,
                    auVar34._8_8_,0);
    }
  }
  else if ((iVar1 - 0x28U < 0x8c) && ((iVar7 < 0x14 && (iVar7 == (iVar7 / 5) * 5))))
  goto LAB_1400b0653;
  dVar26 = (double)FUN_140332d90(((double)(int)param_1[3] - DAT_14053a218) * DAT_14053a988 * dVar3 *
                                 dVar2);
  dVar26 = dVar26 * _DAT_14053a8b8;
  dVar19 = (double)FUN_140332d90();
  uVar4 = _UNK_14053bb28;
  uVar5 = _DAT_14053bb20;
  sVar8 = (short)(int)(dVar19 * _DAT_14053b298);
  uVar28 = CONCAT22(uVar29,sVar8);
  FUN_1400c8410(DAT_140e448dc,0x22,7,(float)param_1[10] + DAT_14053ac34,
                fVar20 + (float)param_1[0xb] + DAT_14053aca0,uVar28,_DAT_14053bb20,_UNK_14053bb28,
                0xff,0xff,0xff,0xff,1,0);
  uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),-sVar8);
  FUN_1400c8410(DAT_140e448dc,0x22,7,(float)param_1[10] - DAT_14053ac34,
                fVar20 + (float)param_1[0xb] + DAT_14053aca0,uVar28,uVar5,uVar4,0xff,0xff,0xff,0xff,
                1,1);
  sVar8 = (short)(int)dVar26;
  uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),sVar8);
  FUN_1400c8410(DAT_140e448d8,0x22,7,(float)param_1[10] + _DAT_14053ac40,
                fVar20 + (float)param_1[0xb],uVar28,uVar5,uVar4,0xff,0xff,0xff,0xff,1,0);
  uVar12 = CONCAT22((short)((uint)uVar28 >> 0x10),-sVar8);
  FUN_1400c8410(DAT_140e448d8,0x22,7,(float)param_1[10] - _DAT_14053ac40,
                fVar20 + (float)param_1[0xb],uVar12,uVar5,uVar4,0xff,0xff,0xff,0xff,1,1);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410(DAT_140e448d4,0x22,7,param_1[10],fVar20 + (float)param_1[0xb],uVar12,uVar5,uVar4,
                0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e448d0,0x22,7,param_1[10],fVar14 + (float)param_1[0xb],uVar12 & 0xffff0000,
                uVar5,uVar4,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,2);
LAB_1400b0ac1:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,4);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  fVar22 = DAT_140e445d8 / fVar22;
  if ((((float)param_1[10] < fVar22 - DAT_14053ad9c) ||
      (fVar22 + DAT_14053af38 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


