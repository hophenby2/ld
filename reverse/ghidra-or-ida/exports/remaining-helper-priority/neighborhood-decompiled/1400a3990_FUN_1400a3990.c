// Function: FUN_1400a3990 @ 1400a3990
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a3990(undefined4 *param_1)

{
  double dVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  ushort uVar4;
  int iVar6;
  undefined8 uVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  float *pfVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined1 auStack_158 [32];
  float local_138;
  undefined4 local_130;
  undefined1 local_128 [16];
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  float local_e0;
  float local_d8 [5];
  float local_c4;
  float local_c0;
  float local_bc;
  ulonglong local_b8;
  ushort uVar5;
  
  local_b8 = DAT_1407c6b00 ^ (ulonglong)auStack_158;
  dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar17 = dVar17 * DAT_14053aba0;
  uVar14 = (ushort)(int)dVar17;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_f0 = 0;
    local_f8 = 1;
    local_100 = 0xff;
    local_108 = 0xff;
    local_110 = 0xff;
    local_118 = 0xff;
    local_e8._0_4_ = (undefined4)uVar7;
    dVar18 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    local_e8._4_4_ = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_128._8_4_ = SUB84(dVar18,0);
    local_128._0_8_ = dVar18;
    local_128._12_4_ = (int)((ulonglong)dVar18 >> 0x20);
    local_130 = local_130 & 0xffff0000;
    local_138 = (float)local_e8._4_4_;
    uVar12 = (undefined4)local_e8;
    local_e8 = uVar7;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar12);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar18 = DAT_140539e60;
  if (param_1[5] == 1) {
    uVar15 = param_1[3];
    dVar1 = *(double *)(param_1 + 0x12);
    fVar20 = (float)param_1[10];
    fVar19 = (float)param_1[0xb];
    local_e0 = fVar20 - DAT_14053ad00;
    fVar21 = fVar19 + DAT_14053acbc;
    fVar22 = fVar19 - DAT_14053ac9c;
    fVar23 = fVar20 + DAT_14053ad04;
    fVar24 = fVar20 - DAT_14053ad04;
    local_c0 = fVar20 + DAT_14053ad00;
    local_e8 = CONCAT44(local_e8._4_4_,local_c0);
    if ((uVar15 < 0x79) && (DAT_140539f10 < dVar1)) {
      dVar1 = dVar1 - DAT_140539e60;
    }
    uVar4 = *(ushort *)(param_1 + 0x10);
    iVar9 = ((int)dVar17 & 0xffffU) - (uint)uVar4;
    *(double *)(param_1 + 0x12) = dVar1;
    iVar6 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar6 = iVar9;
    }
    iVar9 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar9 = iVar6;
    }
    if (iVar9 < 1) {
      uVar5 = uVar4;
      if ((iVar9 < 0) && (uVar5 = uVar4 - 0x40, -0x40 < iVar9)) {
        uVar5 = uVar14;
      }
    }
    else {
      uVar5 = uVar14;
      if (0x3f < iVar9) {
        uVar5 = uVar4 + 0x40;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar5;
    if (0x167 < (int)uVar15) {
      dVar1 = dVar1 - dVar18;
      *(double *)(param_1 + 0x12) = dVar1;
    }
    local_d8[0] = fVar23;
    local_d8[1] = fVar21;
    local_d8[2] = fVar24;
    local_d8[3] = fVar21;
    local_d8[4] = local_e0;
    local_c4 = fVar22;
    local_bc = fVar22;
    dVar17 = (double)FUN_1403307c0();
    fVar20 = (float)(dVar17 * dVar1) + fVar20;
    param_1[10] = fVar20;
    dVar17 = (double)FUN_140332d90();
    fVar19 = (float)(dVar17 * dVar1) + fVar19;
    param_1[0xb] = fVar19;
    dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar19 + DAT_14053ac60)),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    iVar6 = DAT_140e419b8;
    uVar14 = *(ushort *)((longlong)param_1 + 0x42);
    uVar5 = (ushort)(int)(dVar17 * DAT_14053aba0);
    uVar4 = uVar5 - uVar14;
    uVar10 = (uint)uVar4;
    if (0x8000 < uVar4) {
      uVar10 = 0x10000 - uVar4;
    }
    iVar11 = ((int)(dVar17 * DAT_14053aba0) & 0xffffU) - (uint)uVar14;
    iVar16 = (int)uVar10 / 10 + 0x30;
    iVar9 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar9 = iVar11;
    }
    iVar11 = iVar9 + -0x10000;
    if (iVar9 < 0x8001) {
      iVar11 = iVar9;
    }
    if (iVar11 < 1) {
      uVar4 = uVar14;
      if ((iVar11 < 0) && (uVar4 = uVar14 - (short)iVar16, -iVar16 < iVar11)) {
        uVar4 = uVar5;
      }
    }
    else {
      uVar4 = uVar5;
      if (iVar16 <= iVar11) {
        uVar4 = uVar14 + (short)iVar16;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar4;
    uVar7 = _UNK_14053bb28;
    dVar17 = _DAT_14053bb20;
    uVar10 = DAT_14053ac2c;
    iVar9 = 1;
    if (iVar6 == 0) {
      iVar9 = 0x12;
    }
    else if (iVar6 == 1) {
      iVar9 = 10;
    }
    else if (iVar6 == 2) {
      iVar9 = 8;
    }
    else if (iVar6 == 3) {
      iVar9 = 6;
    }
    else if (iVar6 == 4) {
      iVar9 = 5;
    }
    uVar12 = 1;
    if ((iVar6 != 0) && ((((iVar6 == 1 || (iVar6 == 2)) || (iVar6 == 3)) || (iVar6 == 4)))) {
      uVar12 = 2;
    }
    sVar8 = 1;
    if (iVar6 == 0) {
      sVar8 = 0x96;
    }
    else if (iVar6 == 1) {
      sVar8 = 200;
    }
    else if (iVar6 == 2) {
      sVar8 = 0xf0;
    }
    else if (iVar6 == 3) {
      sVar8 = 0x10e;
    }
    else if (iVar6 == 4) {
      sVar8 = 0x140;
    }
    dVar18 = DAT_14053a0a0;
    if (((iVar6 != 0) && (dVar18 = DAT_14053a0b0, iVar6 != 1)) &&
       ((dVar18 = DAT_14053a0e8, iVar6 != 2 &&
        ((dVar18 = DAT_14053a118, iVar6 != 3 && (dVar18 = _DAT_14053bb20, iVar6 == 4)))))) {
      dVar18 = DAT_14053a158;
    }
    if ((uVar15 - 0x1e < 0x14a) &&
       (uVar3 = (longlong)(int)(uVar15 - 0x1e) % (longlong)iVar9, (int)uVar3 == 0)) {
      local_108 = 0;
      local_110 = 0x10000;
      local_128._8_4_ = 1;
      local_128._0_8_ = dVar18;
      local_130 = DAT_14053ac2c;
      local_118 = uVar12;
      local_138._0_2_ = -0x6000 - *(short *)(param_1 + 3) * sVar8;
      FUN_1400709b0(7,uVar3 & 0xffffffff,fVar23,fVar21);
      local_108 = 0;
      local_110 = 0x10000;
      local_128._8_4_ = 1;
      local_128._0_8_ = dVar18;
      local_130 = uVar10;
      local_138._0_2_ = *(short *)(param_1 + 3) * sVar8 + -0x2000;
      local_118 = uVar12;
      FUN_1400709b0(7,0,fVar24,fVar21);
      local_108 = 0;
      local_110 = 0x10000;
      local_128._8_4_ = 1;
      local_128._0_8_ = dVar18;
      local_130 = uVar10;
      local_138._0_2_ = -0x4000 - *(short *)(param_1 + 3) * sVar8;
      local_118 = uVar12;
      FUN_1400709b0(7,0,local_e0,fVar22);
      local_108 = 0;
      local_110 = 0x10000;
      local_128._8_4_ = 1;
      local_128._0_8_ = dVar18;
      local_130 = uVar10;
      local_138 = (float)CONCAT22(local_138._2_2_,*(short *)(param_1 + 3) * sVar8 + -0x4000);
      local_118 = uVar12;
      FUN_1400709b0(7,0,(undefined4)local_e8,fVar22);
      iVar6 = DAT_140e419b8;
    }
    uVar2 = *(undefined2 *)((longlong)param_1 + 0x42);
    dVar18 = (double)FUN_1403307c0();
    fVar19 = (float)(dVar18 * _DAT_14053a358) + (float)param_1[10];
    dVar18 = (double)FUN_140332d90();
    iVar9 = 1;
    fVar20 = (float)(dVar18 * _DAT_14053a358) + (float)param_1[0xb] + DAT_14053ac60;
    if (iVar6 == 0) {
      iVar9 = 0xa0;
    }
    else if (iVar6 == 1) {
      iVar9 = 0x78;
    }
    else if ((iVar6 == 2) || (iVar6 == 3)) {
      iVar9 = 0x5a;
    }
    else if (iVar6 == 4) {
      iVar9 = 0x46;
    }
    uVar12 = 1;
    if ((iVar6 != 0) && ((((iVar6 == 1 || (iVar6 == 2)) || (iVar6 == 3)) || (iVar6 == 4)))) {
      uVar12 = 3;
    }
    dVar18 = DAT_14053a0f8;
    if (((iVar6 != 0) && (dVar18 = DAT_14053a120, iVar6 != 1)) &&
       ((dVar18 = DAT_14053a138, iVar6 != 2 && ((iVar6 != 3 && (dVar18 = dVar17, iVar6 == 4)))))) {
      dVar18 = DAT_14053a190;
    }
    if (((param_1[3] - 0x32 < 0x136) && (iVar9 = (param_1[3] + -0x32) % iVar9, iVar9 < 0x32)) &&
       (iVar9 == (iVar9 / 0x12) * 0x12)) {
      local_108 = 0;
      local_110 = 5000;
      local_128._8_4_ = 1;
      local_128._0_8_ = dVar18;
      local_130 = uVar10;
      local_118 = uVar12;
      local_138._0_2_ = uVar2;
      FUN_1400709b0(0xc,0,fVar19,fVar20);
      if (2 < DAT_140e419b8) {
        local_108 = 0;
        local_110 = 5000;
        local_128._8_4_ = 1;
        local_128._0_8_ = dVar18 + dVar17;
        local_130 = uVar10;
        local_138 = (float)CONCAT22(local_138._2_2_,*(undefined2 *)((longlong)param_1 + 0x42));
        local_118 = uVar12;
        FUN_1400709b0(0xc,0,fVar19,fVar20);
      }
    }
    local_138 = (float)param_1[0xb] + DAT_14053ac60;
    local_f0 = 0;
    local_f8 = 1;
    local_100 = 0xff;
    local_108 = 0xff;
    local_110 = 0xff;
    local_118 = 0xff;
    local_128._0_8_ = dVar17;
    local_128._8_8_ = uVar7;
    local_130._0_2_ = *(undefined2 *)((longlong)param_1 + 0x42);
    FUN_1400c8410(DAT_140e44ca0,0x20,7,param_1[10]);
    local_138 = (float)param_1[0xb];
    local_f0 = 0;
    local_f8 = 1;
    local_100 = 0xff;
    local_108 = 0xff;
    local_110 = 0xff;
    local_118 = 0xff;
    local_128._8_8_ = uVar7;
    local_128._0_8_ = dVar17;
    local_130 = (uint)local_130._2_2_ << 0x10;
    FUN_1400c8410(DAT_140e44c9c,0x20,7,param_1[10]);
    pfVar13 = local_d8;
    uVar15 = 0;
    do {
      local_138 = pfVar13[1];
      local_f0 = 0;
      local_f8 = 1;
      local_100 = 0xff;
      local_108 = 0xff;
      local_110 = 0xff;
      local_118 = 0xff;
      if ((uVar15 & 1) == 0) {
        sVar8 = *(short *)(param_1 + 3) * 0xe10;
      }
      else {
        sVar8 = *(short *)(param_1 + 3) * -0xe10;
      }
      local_130 = CONCAT22(local_130._2_2_,sVar8);
      FUN_1400c8410(DAT_140e44ca4,0x20,7,*pfVar13);
      uVar15 = uVar15 + 1;
      pfVar13 = pfVar13 + 2;
    } while ((int)uVar15 < 4);
    local_138 = (float)DAT_14053b390;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,0xc);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
      (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b398 || (_DAT_14053af5c < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


