// Function: FUN_1400a7760 @ 1400a7760
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a7760(undefined4 *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  double dVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  float *pfVar15;
  bool bVar16;
  undefined4 uVar17;
  double dVar18;
  double dVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  float fVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  undefined1 auStack_198 [32];
  float local_178;
  undefined4 local_170;
  double local_168;
  double dStack_160;
  undefined8 local_158;
  int local_150;
  int local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined8 local_118;
  uint local_110;
  int local_10c;
  uint local_108;
  float local_104;
  uint local_fc;
  uint local_f8;
  float local_e8 [5];
  float local_d4;
  float local_d0;
  float local_cc;
  ulonglong local_c8;
  
  dVar3 = DAT_14053a020;
  dVar19 = DAT_140539d28;
  local_c8 = DAT_1407c6b00 ^ (ulonglong)auStack_198;
  iVar6 = param_1[3];
  uVar27 = SUB84(DAT_14053a020,0);
  uVar28 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar29 = SUB84(DAT_140539d28,0);
  uVar30 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar23 = (double)iVar6;
  dVar18 = (double)FUN_140332d90((dVar23 - 0.0) * DAT_14053ab78 * DAT_14053a020 * DAT_140539d28);
  fVar31 = (float)(dVar18 + dVar18) + 0.0;
  local_104 = fVar31;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_130 = 0;
    local_138 = 1;
    local_140 = 0xff;
    local_148 = 0xff;
    local_168 = DAT_14053a070 - dVar23 * DAT_140539ec8;
    local_150 = 0xff;
    local_118._0_4_ = (uint)uVar7;
    local_158 = CONCAT44(local_158._4_4_,0xff);
    local_170 = (float)((uint)local_170 & 0xffff0000);
    local_118._4_4_ = (uint)((ulonglong)uVar7 >> 0x20);
    local_178 = (float)local_118._4_4_;
    dStack_160 = local_168;
    uVar17 = (uint)local_118;
    local_118 = uVar7;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar17);
    iVar6 = param_1[3];
    if (param_1[3] == 0x14) {
      local_150 = param_1[1];
      local_158 = local_158 & 0xffffffff00000000;
      dStack_160._0_4_ = 0x28;
      local_168 = 0.0;
      local_170._0_2_ = 0x4000;
      local_178 = (float)DAT_14053ad5c;
      stage_entity_spawn_candidate(0x78,6000,0xc,DAT_14053b34c);
      local_150 = param_1[1];
      local_158 = local_158 & 0xffffffff00000000;
      dStack_160 = (double)CONCAT44(dStack_160._4_4_,0x28);
      local_168 = 0.0;
      local_170 = (float)CONCAT22(local_170._2_2_,0x4000);
      local_178 = (float)DAT_14053ace8;
      stage_entity_spawn_candidate(0x78,6000,0xc,DAT_14053aca8);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_118._0_4_ = (uint)uVar7;
      local_118._4_4_ = (uint)((ulonglong)uVar7 >> 0x20);
      param_1[10] = (uint)local_118;
      param_1[0xb] = local_118._4_4_;
      param_1[3] = 0;
      param_1[0x15] = 0;
      iVar6 = 0;
      local_118 = uVar7;
    }
  }
  uVar7 = _UNK_14053bb28;
  dVar18 = _DAT_14053bb20;
  if (param_1[5] != 1) goto LAB_1400a831b;
  fVar31 = (float)param_1[0xd];
  fVar22 = (float)param_1[0xc];
  iVar11 = (int)fVar31;
  fVar26 = fVar22 + DAT_140e45d24;
  iVar12 = iVar11;
  if (iVar6 >= 0) {
    iVar12 = iVar11 + -900;
  }
  param_1[10] = fVar26;
  if ((iVar6 < 0) || (0x95 < iVar6)) {
    if (iVar6 < 0x3fc) goto LAB_1400a7b1d;
    if (iVar6 < 0x4b0) {
      dVar19 = (double)FUN_140332d90(((double)iVar6 - _DAT_14053a898) * DAT_14053a438 * dVar3 *
                                     dVar19);
      dVar19 = dVar19 * _DAT_14053a8b8;
      param_1[0xd] = fVar31 + DAT_140539cf0;
      fVar25 = (float)(iVar11 - (int)dVar19);
      param_1[0xb] = fVar25;
      goto LAB_1400a7b48;
    }
    fVar31 = fVar31 + DAT_140539cf0;
    param_1[0xb] = (float)iVar11;
    param_1[0xd] = (float)(iVar6 + -0x4b0) * DAT_140539cd8 + fVar31;
  }
  else {
    dVar19 = (double)FUN_140332d90(((double)iVar6 - 0.0) * _DAT_14053a478 * dVar3 * dVar19);
    iVar12 = iVar11 - (int)(dVar19 * _DAT_14053a8b8);
LAB_1400a7b1d:
    fVar25 = (float)iVar12;
    param_1[0xb] = fVar25;
    param_1[0xd] = fVar31 + DAT_140539cf0;
    if ((0x77 < iVar6) && (iVar6 < 0x4b0)) {
LAB_1400a7b48:
      fVar4 = DAT_14053ae30;
      fVar31 = DAT_14053ac2c;
      dVar3 = DAT_14053a138;
      dVar19 = DAT_14053a0f8;
      if (fVar25 < DAT_14053ae30) {
        fVar25 = fVar25 + DAT_14053ac2c;
        iVar12 = 1;
        local_110 = (iVar6 + -0x78) % 0x148;
        if (DAT_140e419b8 == 0) {
          iVar12 = 0x13;
        }
        else if (DAT_140e419b8 == 1) {
          iVar12 = 0xd;
        }
        else if (DAT_140e419b8 == 2) {
          iVar12 = 0xb;
        }
        else if (DAT_140e419b8 == 3) {
          iVar12 = 10;
        }
        else if (DAT_140e419b8 == 4) {
          iVar12 = 8;
        }
        iVar6 = 1;
        if (DAT_140e419b8 == 0) {
          iVar6 = 6;
        }
        else if (DAT_140e419b8 == 1) {
          iVar6 = 8;
        }
        else if (DAT_140e419b8 == 2) {
          iVar6 = 9;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar6 = 10;
        }
        sVar10 = 1;
        if (DAT_140e419b8 == 0) {
          sVar10 = 0x50;
        }
        else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
          sVar10 = 100;
        }
        else if (DAT_140e419b8 == 3) {
          sVar10 = 0x78;
        }
        else if (DAT_140e419b8 == 4) {
          sVar10 = 0x96;
        }
        dVar23 = DAT_14053a0c8;
        if ((((DAT_140e419b8 != 0) && (dVar23 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
            (dVar23 = DAT_14053a118, DAT_140e419b8 != 2)) &&
           ((dVar23 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar23 = dVar18, DAT_140e419b8 == 4))))
        {
          dVar23 = DAT_14053a178;
        }
        if (DAT_14053ae30 <= fVar22) {
          sVar10 = -sVar10;
        }
        if ((local_110 < 0x78) && ((int)((longlong)(int)local_110 % (longlong)iVar12) == 0)) {
          local_148 = 0;
          local_150 = 0x10000;
          dStack_160._0_4_ = 1;
          local_170 = 0.0;
          local_168 = dVar23;
          local_158._0_4_ = iVar6;
          local_178._0_2_ = sVar10 * *(short *)(param_1 + 3);
          FUN_1400709b0(4,(longlong)(int)local_110 % (longlong)iVar12 & 0xffffffff,fVar26,fVar25);
          local_168 = dVar23 - DAT_140539f00;
          local_148 = 0;
          local_150 = 0x10000;
          sVar13 = (short)(0x10000 / (ulonglong)(uint)(iVar6 * 3));
          local_158 = CONCAT44(local_158._4_4_,iVar6);
          dStack_160 = (double)CONCAT44(dStack_160._4_4_,1);
          local_170 = 0.0;
          if (fVar4 <= (float)param_1[0xc]) {
            sVar13 = -sVar13;
          }
          local_178 = (float)CONCAT22(local_178._2_2_,sVar10 * *(short *)(param_1 + 3) + sVar13);
          FUN_1400709b0(4,0,fVar26,fVar25);
        }
        dVar23 = DAT_14053aba0;
        iVar6 = 1;
        local_d4 = (float)param_1[0xb];
        local_e8[0] = (float)param_1[10] - DAT_14053ad48;
        local_e8[1] = local_d4 + DAT_14053ad48;
        local_e8[2] = (float)param_1[10] + DAT_14053ad48;
        local_d4 = local_d4 + DAT_14053aca8;
        if (DAT_140e419b8 == 0) {
          iVar6 = 0x20;
        }
        else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
          iVar6 = 0xf;
        }
        else if (DAT_140e419b8 == 4) {
          iVar6 = 0xc;
        }
        iVar12 = 1;
        if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
          iVar12 = 3;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar12 = 5;
        }
        else if (DAT_140e419b8 == 4) {
          iVar12 = 7;
        }
        dVar24 = DAT_14053a080;
        if ((((DAT_140e419b8 != 0) && (dVar24 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
            (dVar24 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
           ((dVar24 = dVar19, DAT_140e419b8 != 3 && (dVar24 = dVar18, DAT_140e419b8 == 4)))) {
          dVar24 = dVar3;
        }
        pfVar15 = local_e8;
        local_108 = 0;
        iVar11 = local_110 - 0xa0;
        local_10c = 0xa0;
        local_e8[3] = local_e8[1];
        local_e8[4] = local_e8[0];
        local_d0 = local_e8[2];
        local_cc = local_d4;
        do {
          local_f8 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (local_f8 >> 0x1e ^ local_f8) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          local_118 = CONCAT44(local_118._4_4_,DAT_140e9fd14);
          uVar5 = local_f8 * 0x800 ^ local_f8;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
          DAT_140e9fd1c = uVar5;
          local_fc = DAT_140e9fd18;
          dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((float)param_1[0xb] + fVar31)),
                                         (double)(DAT_140e445d8 - (float)param_1[10]));
          uVar14 = local_108;
          sVar13 = (short)(int)(dVar19 * dVar23);
          sVar10 = sVar13 + (short)((ulonglong)uVar5 / 0x2711) * -0x2711 + (short)uVar5 + -8000;
          if ((local_108 & 1) != 0) {
            uVar5 = local_f8 << 0xb ^ local_f8;
            DAT_140e9fd14 = (uint)local_118;
            DAT_140e9fd1c = (local_fc >> 0xb ^ uVar5) >> 8 ^ local_fc ^ uVar5;
            sVar10 = sVar13 + (short)((ulonglong)DAT_140e9fd1c / 0x2711) * -0x2711 +
                     (short)DAT_140e9fd1c + -2000;
          }
          if ((local_10c <= (int)local_110) && ((int)local_110 < 300)) {
            uVar1 = (longlong)iVar11 % (longlong)(iVar6 * 5);
            iVar9 = (int)uVar1;
            if (iVar9 == 0) {
              fVar22 = pfVar15[1];
              fVar26 = *pfVar15;
              local_150 = iVar12 * 0x960 + -0x960;
              local_158 = CONCAT44(local_158._4_4_,iVar12);
              dStack_160 = (double)CONCAT44(dStack_160._4_4_,1);
              local_170 = fVar31;
              local_178 = (float)CONCAT22(local_178._2_2_,sVar10);
              local_118 = CONCAT44(local_118._4_4_,local_150);
              local_168 = dVar24;
              local_148 = iVar9;
              FUN_1400709b0(0xc,uVar1 & 0xffffffff,fVar26,fVar22);
              if (2 < DAT_140e419b8) {
                local_148 = 0;
                local_168 = dVar24 + dVar18;
                local_150 = (uint)local_118;
                local_158 = CONCAT44(local_158._4_4_,iVar12);
                dStack_160 = (double)CONCAT44(dStack_160._4_4_,1);
                local_170 = fVar31;
                local_178 = (float)CONCAT22(local_178._2_2_,sVar10);
                FUN_1400709b0(0xc,0,fVar26,fVar22);
              }
            }
          }
          local_10c = local_10c + iVar6;
          local_108 = uVar14 + 1;
          iVar11 = iVar11 - iVar6;
          pfVar15 = pfVar15 + 2;
        } while ((int)local_108 < 4);
        uVar27 = SUB84(DAT_14053a020,0);
        uVar28 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
        uVar29 = SUB84(DAT_140539d28,0);
        uVar30 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      }
    }
  }
  if ((int)param_1[3] % 0x12 == 1) {
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472f4);
    FUN_14018a340(DAT_140e472f4,1,1);
  }
  fVar31 = local_104;
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0x1e);
    local_168 = (double)((ulonglong)local_168 & 0xffffffff00000000);
    local_170 = 0.0;
    local_178 = (float)((uint)local_178 & 0xffff0000);
    FUN_140109660(0x18,param_1[10],param_1[0xb],0);
    uVar17 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar8 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar8 = (undefined8 *)_malloc_base(0x60);
      if (puVar8 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar8 = 1;
      *(undefined4 *)(puVar8 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar8 + 0xc) = uVar17;
      puVar8[2] = 0x6f;
      puVar8[3] = 0;
      *(undefined4 *)(puVar8 + 4) = 0;
      *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
      puVar8[5] = 0;
      puVar8[6] = 0x3ff0000000000000;
      puVar8[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar8 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
      *(undefined4 *)(puVar8 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0;
      if (bVar16) {
        DAT_140e45d78 = puVar8;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar8;
      }
    }
    DAT_140e45d28 = puVar8;
    param_1[5] = param_1[5] + 1;
    param_1[0x14] = 200;
    param_1[0x15] = 1;
    param_1[3] = 0;
    fVar31 = local_104;
  }
LAB_1400a831b:
  uVar2 = DAT_140539f28;
  if (param_1[5] == 2) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)(int)param_1[3] * DAT_140539ce4 + (float)param_1[0xb];
    if (param_1[3] == 0x3c) {
      uVar5 = param_1[1] + DAT_140e418c8;
      uVar14 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar14 = uVar14 * 0x800 ^ uVar14;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar14;
      uVar20 = FUN_140134db0(uVar5,uVar2,DAT_140539f38);
      uVar17 = (undefined4)uVar20;
      uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
      dStack_160 = (double)FUN_140134db0(param_1[1] + DAT_140e418c8);
      local_128 = 0;
      local_130 = 0xc0;
      local_138 = 0xff;
      local_140 = 0xff;
      local_148 = 0xff;
      local_150 = 0x78;
      local_158 = CONCAT44(uVar21,uVar17);
      local_178 = (float)param_1[0xb];
      local_168 = dVar18;
      local_170 = (float)CONCAT22(local_170._2_2_,(short)uVar14 - (short)(uVar14 / 0x10001));
      FUN_140070d00(0x38,DAT_140e45090,0x15,(float)param_1[10] - DAT_140e45d24);
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  local_170 = 1.35926e-43;
  local_178 = 1.34525e-43;
  iVar6 = FUN_1400c9580(param_1[3],0,5,2);
  fVar26 = DAT_14053ae04;
  fVar22 = DAT_14053acd8;
  local_178 = (float)param_1[0xb] + DAT_14053ae04;
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  local_168 = dVar18;
  dStack_160 = (double)uVar7;
  local_170 = (float)((uint)local_170 & 0xffff0000);
  FUN_1400c8410((&DAT_140e44660)[iVar6],0x1c,7,(float)param_1[10] + DAT_14053acd8);
  local_178 = (float)param_1[0xb] + fVar26;
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  local_168 = dVar18;
  dStack_160 = (double)uVar7;
  local_170 = (float)((uint)local_170 & 0xffff0000);
  FUN_1400c8410((&DAT_140e44660)[iVar6],0x1c,7,(float)param_1[10] - fVar22);
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_178 = (float)param_1[0xb] + DAT_14053ad10 + fVar31;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  local_168 = dVar18;
  dStack_160 = (double)uVar7;
  local_170 = (float)((uint)local_170 & 0xffff0000);
  FUN_1400c8410(DAT_140e449b4,0x1c,7,param_1[10]);
  local_178 = fVar31 + (float)param_1[0xb];
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  local_168 = dVar18;
  dStack_160 = (double)uVar7;
  local_170 = (float)((uint)local_170 & 0xffff0000);
  FUN_1400c8410(DAT_140e44cc0,0x1c,7,param_1[10]);
  dVar19 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a6c8 *
                                 (double)CONCAT44(uVar28,uVar27) * (double)CONCAT44(uVar30,uVar29));
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_178 = ((float)param_1[0xb] - DAT_14053ad1c) + fVar31;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  local_168 = dVar18;
  dStack_160 = (double)uVar7;
  local_170._0_2_ = (short)(int)(dVar19 * _DAT_14053aa18);
  FUN_1400c8410(DAT_140e44cc4,0x1d,7,(float)param_1[10] - fVar22);
  local_130 = 0;
  local_138 = 1;
  local_140 = 0x40;
  local_178 = (float)param_1[0xb] + DAT_14053ad70 + fVar31;
  local_148 = 0x20;
  local_150 = 0;
  local_158 = (ulonglong)local_158._4_4_ << 0x20;
  dStack_160 = (double)uVar2;
  local_168 = dVar18;
  local_170 = (float)((uint)local_170._2_2_ << 0x10);
  FUN_1400c8410(DAT_140e449b4,0x17,7,param_1[10]);
  uVar27 = DAT_140e41960;
  fVar31 = (float)param_1[0xb];
  fVar25 = ((float)param_1[10] + fVar22) - DAT_140e45d24;
  iVar6 = DAT_140e45d1c;
  puVar8 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar8 = (undefined8 *)_malloc_base(0x60);
    if (puVar8 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar6 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar8 + 0x14) = fVar25;
    bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar8 + 3) = fVar31 + fVar26;
    *(float *)((longlong)puVar8 + 0x1c) = fVar25;
    *(float *)(puVar8 + 4) = fVar31 + fVar26;
    *puVar8 = 1;
    *(undefined4 *)(puVar8 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar8 + 0xc) = uVar27;
    *(undefined4 *)(puVar8 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
    puVar8[5] = 0;
    puVar8[6] = 0x3ff0000000000000;
    puVar8[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar8 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
    *(undefined4 *)(puVar8 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
    puVar8[10] = 0x80;
    puVar8[0xb] = 0;
    if (bVar16) {
      DAT_140e45d78 = puVar8;
    }
    DAT_140e45d1c = iVar6;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar8;
    }
  }
  DAT_140e45d28 = puVar8;
  uVar27 = DAT_140e41960;
  fVar31 = (float)param_1[0xb];
  fVar22 = ((float)param_1[10] - fVar22) - DAT_140e45d24;
  puVar8 = DAT_140e45d28;
  if (iVar6 < 0x1000) {
    puVar8 = (undefined8 *)_malloc_base(0x60);
    if (puVar8 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar8 + 0x14) = fVar22;
    *(float *)(puVar8 + 3) = fVar31 + fVar26;
    *(float *)((longlong)puVar8 + 0x1c) = fVar22;
    *(float *)(puVar8 + 4) = fVar31 + fVar26;
    *puVar8 = 1;
    *(undefined4 *)(puVar8 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar8 + 0xc) = uVar27;
    *(undefined4 *)(puVar8 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
    puVar8[5] = 0;
    puVar8[6] = 0x3ff0000000000000;
    puVar8[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar8 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
    *(undefined4 *)(puVar8 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
    puVar8[10] = 0x80;
    puVar8[0xb] = 0;
    if (bVar16) {
      DAT_140e45d78 = puVar8;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar8;
    }
  }
  DAT_140e45d28 = puVar8;
  if (param_1[0x15] == 0) {
    local_178 = (float)DAT_14053b36c;
    FUN_140079c10(param_1,0);
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ade0) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af58 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3e4)) || (_DAT_14053afa0 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


