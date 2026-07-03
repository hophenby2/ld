// Function: FUN_140018480 @ 140018480
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140018480(undefined4 *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined2 uVar4;
  ushort uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  short sVar13;
  undefined4 uVar14;
  int iVar15;
  short sVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  longlong lVar21;
  ushort uVar22;
  ushort uVar23;
  uint uVar24;
  uint uVar25;
  bool bVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  undefined8 uVar35;
  undefined4 uVar36;
  undefined8 extraout_XMM0_Qb;
  undefined8 extraout_XMM0_Qb_00;
  undefined8 extraout_XMM0_Qb_01;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  double dVar39;
  double dVar40;
  float fVar41;
  undefined1 auVar42 [16];
  float fVar43;
  float fVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  undefined1 auStack_2a8 [32];
  float local_288;
  undefined4 local_280;
  double local_278;
  undefined8 local_270;
  ulonglong uStack_268;
  int local_260;
  uint local_258;
  undefined4 local_250;
  undefined4 local_248;
  undefined4 local_240;
  undefined4 local_238;
  uint local_228;
  float local_224;
  uint local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined8 local_1e8;
  undefined4 uStack_1e0;
  int iStack_1dc;
  ulonglong local_1d8;
  double local_1d0;
  longlong local_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  float local_1a8 [4];
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  undefined8 local_168;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  float fStack_150;
  float fStack_14c;
  ulonglong local_d8;
  
  puVar8 = DAT_140e45d80;
  iVar15 = DAT_140e44e6c;
  iVar20 = DAT_140e44308;
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_2a8;
  uStack_15c = 0;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined4 *)0x0)) {
    local_1e8 = local_168;
    uStack_1e0 = uStack_160;
    iStack_1dc = 0;
    local_178 = 0;
    fVar29 = fStack_150;
    fVar30 = fStack_14c;
  }
  else {
    local_1e8 = local_168;
    uStack_1e0 = uStack_160;
    iStack_1dc = 0;
    local_178 = 0;
    puVar6 = DAT_140e45d80;
    do {
      if (puVar6[1] == DAT_140e44308) {
        local_1e8 = *(undefined8 *)(puVar6 + 4);
        local_178 = *puVar6;
        uStack_174 = puVar6[1];
        uStack_170 = puVar6[2];
        iStack_16c = puVar6[3];
        fStack_150 = (float)puVar6[10];
        fStack_14c = (float)puVar6[0xb];
        uStack_1e0 = (undefined4)*(undefined8 *)(puVar6 + 6);
        iStack_1dc = (int)((ulonglong)*(undefined8 *)(puVar6 + 6) >> 0x20);
      }
      puVar6 = *(undefined4 **)(puVar6 + 0x18);
      fVar29 = fStack_150;
      fVar30 = fStack_14c;
    } while (puVar6 != (undefined4 *)0x0);
  }
  uVar24 = param_1[1] - DAT_1407c77a0;
  fVar41 = (float)param_1[0xd];
  fVar43 = (float)param_1[0xc];
  local_228 = uVar24;
  dVar32 = (double)FUN_1403300b4((double)((fVar30 + fVar41) - (float)param_1[0xb]),
                                 (double)((fVar29 + fVar43) - (float)param_1[10]));
  dVar40 = DAT_14053aba0;
  uVar19 = (uint)(dVar32 * DAT_14053aba0);
  local_220 = uVar19;
  fVar27 = (float)FUN_140334430();
  fVar28 = (float)FUN_140334430();
  if (fVar27 + fVar28 < 0.0) {
    local_224 = (float)FUN_1403352f8();
  }
  else {
    local_224 = SQRT(fVar27 + fVar28);
  }
  local_1a8[0] = fVar29 + DAT_14053acbc;
  local_1a8[1] = fVar30 + DAT_14053ad70;
  local_198 = fVar29 + DAT_14053ad1c;
  local_1a8[3] = fVar30 + DAT_14053ad70;
  local_1a8[2] = fVar29 - DAT_14053acbc;
  local_190 = fVar29 - DAT_14053ad1c;
  local_194 = fVar30 + DAT_14053ad5c;
  local_18c = fVar30 + DAT_14053ad5c;
  local_184 = fVar30 + DAT_14053ad40;
  local_17c = fVar30 + DAT_14053ad40;
  local_188 = fVar29 + DAT_14053ad5c;
  local_180 = fVar29 - DAT_14053ad5c;
  if (param_1[5] == 0) {
    iVar9 = 0;
    if (param_1[3] == 0) {
      param_1[10] = fVar29 + fVar43;
      param_1[0xb] = fVar30 + fVar41;
    }
    else if (param_1[3] == 0x28) {
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      iVar9 = param_1[5];
      puVar8 = DAT_140e45d80;
      iVar15 = DAT_140e44e6c;
      iVar20 = DAT_140e44308;
    }
    if (param_1[3] == 0x3c) {
      if ((uVar24 == 0) || (uVar4 = 0x7c18, uVar24 - 3 < 2)) {
        uVar4 = 1000;
      }
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar4;
      param_1[5] = iVar9 + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
      if (0 < iVar15) {
        for (; puVar8 != (undefined4 *)0x0; puVar8 = *(undefined4 **)(puVar8 + 0x18)) {
          if (puVar8[1] == iVar20) {
            puVar8[0x17] = puVar8[0x17] + 1;
          }
        }
      }
    }
  }
  iVar20 = iStack_16c;
  dVar32 = DAT_14053a020;
  uVar23 = (ushort)uVar19;
  if (param_1[5] == 1) {
    uVar5 = *(ushort *)((longlong)param_1 + 0x42);
    iVar9 = (uVar19 & 0xffff) - (uint)uVar5;
    iVar15 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar15 = iVar9;
    }
    iVar9 = iVar15 + -0x10000;
    if (iVar15 < 0x8001) {
      iVar9 = iVar15;
    }
    if (iVar9 < 1) {
      uVar22 = uVar5;
      if ((iVar9 < 0) && (uVar22 = uVar5 - 0x457, -0x457 < iVar9)) {
        uVar22 = uVar23;
      }
    }
    else {
      uVar22 = uVar23;
      if (0x456 < iVar9) {
        uVar22 = uVar5 + 0x457;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar22;
    dVar33 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar33 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar33 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar33 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (iVar20 < 600) {
      if (0x1d < (int)param_1[3]) {
        param_1[5] = 2;
LAB_1400188ca:
        param_1[3] = 0;
      }
    }
    else if ((iVar20 < 0x3ac) && (0x1d < (int)param_1[3])) {
      param_1[5] = 3;
      goto LAB_1400188ca;
    }
    if (iVar20 == uVar24 * 0x96 + 0x3c0) {
      param_1[3] = 0;
      param_1[5] = 4;
    }
    if ((iVar20 - 0x79eU < 600) && (0x1d < (int)param_1[3])) {
      param_1[3] = 0;
      param_1[5] = 6;
    }
    if (((iVar20 == 0xa28) || (iVar20 == 0xb36)) || (iVar20 == 0xc44)) {
      param_1[3] = 0;
      param_1[5] = 7;
    }
  }
  dVar33 = DAT_14053a060;
  uVar31 = SUB84(DAT_14053a060,0);
  uVar36 = (undefined4)((ulonglong)DAT_14053a060 >> 0x20);
  if (param_1[5] == 2) {
    uVar5 = *(ushort *)((longlong)param_1 + 0x42);
    iVar9 = (uVar19 & 0xffff) - (uint)uVar5;
    iVar15 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar15 = iVar9;
    }
    iVar9 = iVar15 + -0x10000;
    if (iVar15 < 0x8001) {
      iVar9 = iVar15;
    }
    if (iVar9 < 1) {
      uVar22 = uVar5;
      if ((iVar9 < 0) && (uVar22 = uVar5 - 0x457, -0x457 < iVar9)) {
        uVar22 = uVar23;
      }
    }
    else {
      uVar22 = uVar23;
      if (0x456 < iVar9) {
        uVar22 = uVar5 + 0x457;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar22;
    dVar34 = (double)FUN_1403307c0();
    fVar43 = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar43;
    dVar34 = (double)FUN_140332d90();
    fVar41 = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar41;
    if (iVar20 < 0x244) {
      dVar34 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41),
                                     (double)(DAT_140e445d8 - fVar29));
      iVar15 = DAT_140e419b8;
      iVar9 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar9 = 0x4f;
      }
      else if (DAT_140e419b8 == 2) {
        iVar9 = 0x3d;
      }
      else if (DAT_140e419b8 == 3) {
        iVar9 = 0x30;
      }
      else if (DAT_140e419b8 == 4) {
        iVar9 = 0x27;
      }
      uVar45 = SUB84(DAT_140539f40,0);
      uVar46 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      dVar39 = DAT_140539ff0;
      if ((((DAT_140e419b8 != 0) && (dVar39 = DAT_14053a040, DAT_140e419b8 != 1)) &&
          (dVar39 = dVar33, DAT_140e419b8 != 2)) &&
         ((dVar39 = DAT_14053a088, DAT_140e419b8 != 3 &&
          (dVar39 = DAT_140539f40, DAT_140e419b8 == 4)))) {
        dVar39 = DAT_14053a0d0;
      }
      if ((local_228 == 0) || (local_228 - 3 < 2)) {
        dVar32 = (double)FUN_140332d90(((double)iVar20 - DAT_14053a2f0) * DAT_14053a710 * dVar32 *
                                       DAT_140539d28);
        dVar32 = dVar32 * _DAT_14053aa38;
      }
      else {
        dVar32 = (double)FUN_140332d90(((double)iVar20 - DAT_14053a2f0) * DAT_14053a710 * dVar32 *
                                       DAT_140539d28);
        dVar32 = dVar32 * _DAT_14053b2d0;
      }
      uVar23 = *(ushort *)(param_1 + 0x10);
      uVar22 = (short)(int)(dVar34 * dVar40) + (short)(int)dVar32;
      uVar5 = uVar22 - uVar23;
      uVar19 = (uint)uVar5;
      if (0x8000 < uVar5) {
        uVar19 = 0x10000 - uVar5;
      }
      iVar10 = (uint)uVar22 - (uint)uVar23;
      iVar17 = (int)uVar19 / 10 + 0x30;
      iVar11 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar11 = iVar10;
      }
      iVar10 = iVar11 + -0x10000;
      if (iVar11 < 0x8001) {
        iVar10 = iVar11;
      }
      if (iVar10 < 1) {
        uVar5 = uVar23;
        if ((iVar10 < 0) && (uVar5 = uVar23 - (short)iVar17, -iVar17 < iVar10)) {
          uVar5 = uVar22;
        }
      }
      else {
        uVar5 = uVar22;
        if (iVar17 <= iVar10) {
          uVar5 = uVar23 + (short)iVar17;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar5;
      iVar11 = 1;
      if ((iVar15 == 0) || (iVar15 == 1)) {
        iVar11 = 0xc;
      }
      else if (iVar15 == 2) {
        iVar11 = 10;
      }
      else if (iVar15 == 3) {
        iVar11 = 8;
      }
      else if (iVar15 == 4) {
        iVar11 = 7;
      }
      iVar10 = ((int)local_228 / 2) * iVar11 + 0x20;
      if ((((iVar10 <= iVar20) &&
           (uVar12 = (longlong)(iVar20 - iVar10) % (longlong)iVar9, (int)uVar12 == 0)) &&
          (DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar43)) &&
         (((fVar43 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0 && (0.0 <= fVar41)) &&
          (fVar41 <= DAT_14053af14)))) {
        iVar15 = 0;
        uStack_268 = uStack_268 & 0xffffffff00000000;
        local_270 = CONCAT44(local_270._4_4_,1);
        local_280 = 0;
        local_288 = (float)CONCAT22(local_288._2_2_,uVar22);
        local_278 = dVar39;
        FUN_14006c2f0(0xd,uVar12 & 0xffffffff,iVar11,fVar41);
        if (0 < DAT_140e419b8) {
          dVar39 = dVar39 - DAT_140539ee0;
          do {
            uStack_268 = uStack_268 & 0xffffffff00000000;
            local_270 = CONCAT44(local_270._4_4_,1);
            local_280 = 0;
            local_288 = (float)CONCAT22(local_288._2_2_,(short)iVar15 * 0x22b8 + uVar22 + -0x115c);
            local_278 = dVar39;
            FUN_14006c2f0(0xd,0);
            iVar15 = iVar15 + 1;
            iVar20 = iStack_16c;
          } while (iVar15 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar15 = DAT_140e419b8;
      }
    }
    else {
      uVar45 = SUB84(DAT_140539f40,0);
      uVar46 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      iVar15 = DAT_140e419b8;
    }
    if (iVar20 == 600) {
      param_1[3] = 0;
      param_1[5] = 3;
    }
  }
  else {
    uVar45 = SUB84(DAT_140539f40,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    iVar15 = DAT_140e419b8;
  }
  uVar48 = DAT_14053ac2c;
  dVar40 = DAT_14053a278;
  if (param_1[5] == 3) {
    dVar33 = (double)local_224 / DAT_14053a278;
    dVar32 = (double)FUN_1403307c0();
    fVar41 = (float)(dVar32 * dVar33) + (float)param_1[10];
    param_1[10] = fVar41;
    dVar32 = (double)FUN_140332d90();
    uVar23 = *(ushort *)(param_1 + 0x10);
    uVar5 = 0x4000 - uVar23;
    uVar19 = (uint)uVar5;
    if (0x8000 < uVar5) {
      uVar19 = 0x10000 - uVar5;
    }
    iVar11 = -(uint)uVar23 + 0x4000;
    fVar43 = (float)(dVar32 * dVar33) + (float)param_1[0xb];
    iVar10 = (int)uVar19 / 10 + 0x30;
    param_1[0xb] = fVar43;
    iVar9 = -(uint)uVar23 + 0x14000;
    if (-0x8001 < iVar11) {
      iVar9 = iVar11;
    }
    iVar11 = iVar9 + -0x10000;
    if (iVar9 < 0x8001) {
      iVar11 = iVar9;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar23 = uVar23 - (short)iVar10, -iVar10 < iVar11)) {
        uVar23 = 0x4000;
      }
    }
    else if (iVar11 < iVar10) {
      uVar23 = 0x4000;
    }
    else {
      uVar23 = uVar23 + (short)iVar10;
    }
    *(ushort *)(param_1 + 0x10) = uVar23;
    if ((0x293 < iVar20) && (iVar20 < 0x398)) {
      local_200 = _DAT_14053b940;
      uStack_1f8 = _UNK_14053b948;
      local_1f0 = 0xfffff830;
      local_1ec = 2000;
      dVar32 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar43),
                                     (double)(DAT_140e445d8 - fVar29));
      dVar32 = dVar32 * DAT_14053aba0;
      uVar12 = 1;
      sVar16 = *(short *)((longlong)&local_200 + (longlong)(int)local_228 * 4);
      if (iVar15 == 0) {
        uVar12 = 0x41;
      }
      else if (iVar15 == 1) {
LAB_140018f44:
        uVar12 = 0x2c;
      }
      else {
        if (iVar15 != 2) {
          if (iVar15 == 3) goto LAB_140018f44;
          if (iVar15 != 4) goto LAB_140018f50;
        }
        uVar12 = 0x26;
      }
LAB_140018f50:
      dVar33 = DAT_14053a078;
      if ((((iVar15 != 0) && (dVar33 = DAT_14053a0d0, iVar15 != 1)) &&
          (dVar33 = DAT_14053a0f8, iVar15 != 2)) &&
         ((iVar15 != 3 && (dVar33 = (double)CONCAT44(uVar46,uVar45), iVar15 == 4)))) {
        dVar33 = DAT_14053a178;
      }
      uVar19 = (iVar20 + -0x294) % (int)uVar12;
      dVar33 = (double)(int)uVar19 * DAT_140539e60 + dVar33;
      if (uVar19 == 0) {
        dVar34 = (double)FUN_140332d90(((double)iVar20 - (double)(0x294 - (int)(uVar12 >> 1))) *
                                       (DAT_14053ac08 / (double)((int)uVar12 * 2)) * DAT_14053a020 *
                                       DAT_140539d28);
        *(short *)(param_1 + 0x11) =
             (short)(int)(dVar34 * (double)((iVar20 + -0x294) * 0x10)) + (short)(int)dVar32 + sVar16
        ;
LAB_140019041:
        if (((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar41) &&
            (fVar41 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
           ((0.0 <= fVar43 && (fVar43 <= DAT_14053af14)))) {
          uStack_268 = uStack_268 & 0xffffffff00000000;
          local_270 = CONCAT44(local_270._4_4_,1);
          local_280 = uVar48;
          local_288 = (float)CONCAT22(local_288._2_2_,*(undefined2 *)(param_1 + 0x11));
          local_278 = dVar33;
          FUN_14006c2f0(9,0);
          if (2 < DAT_140e419b8) {
            dVar33 = dVar33 - DAT_140539f10;
            sVar16 = *(short *)(param_1 + 0x11);
            iVar15 = 0;
            do {
              uStack_268 = uStack_268 & 0xffffffff00000000;
              local_270 = CONCAT44(local_270._4_4_,1);
              local_280 = uVar48;
              local_288 = (float)CONCAT22(local_288._2_2_,(short)iVar15 * 0x1e61 + sVar16 + -0xf30);
              local_278 = dVar33;
              FUN_14006c2f0(9,0);
              iVar15 = iVar15 + 1;
            } while (iVar15 < 2);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar15 = DAT_140e419b8;
        }
      }
      else if ((int)uVar19 < 0x18) {
        uVar19 = uVar19 & 0x80000003;
        if ((int)uVar19 < 0) {
          uVar19 = (uVar19 - 1 | 0xfffffffc) + 1;
        }
        if (uVar19 == 0) goto LAB_140019041;
      }
    }
    if (iVar20 == 0x3ac) {
      param_1[3] = 0;
      param_1[5] = 1;
    }
  }
  if ((param_1[5] == 4) || (param_1[5] == 7)) {
    fVar41 = (float)param_1[0xb];
    uVar45 = param_1[10];
    dVar32 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar41));
    uVar46 = SUB84(DAT_14053aba0,0);
    uVar47 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
    dVar32 = dVar32 * DAT_14053aba0;
    if (param_1[3] == 1) {
      local_238 = param_1[1];
      local_240 = 0x80;
      local_248 = 0xff;
      local_250 = 0xff;
      local_258 = 0xff;
      local_260 = 0x5a;
      local_270 = _DAT_14053baf0;
      uStack_268 = _UNK_14053baf8;
      local_278 = 0.0;
      local_280 = CONCAT22(local_280._2_2_,*(undefined2 *)(param_1 + 0x10));
      local_288 = fVar41;
      FUN_140070d00(0x41,DAT_140e41a90,0x50,uVar45);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
      iVar15 = DAT_140e419b8;
    }
    uVar45 = DAT_140e472cc;
    if ((int)param_1[3] < 0x32) {
      uVar23 = *(ushort *)(param_1 + 0x10);
      uVar22 = (ushort)(int)dVar32;
      uVar5 = uVar22 - uVar23;
      uVar19 = (uint)uVar5;
      if (0x8000 < uVar5) {
        uVar19 = 0x10000 - uVar5;
      }
      iVar11 = ((int)dVar32 & 0xffffU) - (uint)uVar23;
      iVar10 = (int)uVar19 / 10 + 0x30;
      iVar9 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar9 = iVar11;
      }
      iVar11 = iVar9 + -0x10000;
      if (iVar9 < 0x8001) {
        iVar11 = iVar9;
      }
      if (iVar11 < 1) {
        if ((iVar11 < 0) && (uVar23 = uVar23 - (short)iVar10, -iVar10 < iVar11)) {
          uVar23 = uVar22;
        }
        *(ushort *)(param_1 + 0x10) = uVar23;
      }
      else if (iVar11 < iVar10) {
        *(ushort *)(param_1 + 0x10) = uVar22;
      }
      else {
        *(ushort *)(param_1 + 0x10) = uVar23 + (short)iVar10;
      }
    }
    else if (param_1[3] == 0x5a) {
      *(undefined8 *)(param_1 + 0x12) = 0x4024000000000000;
      FUN_140184700(DAT_140e44190 * 0x19,uVar45);
      FUN_14018a340(DAT_140e472cc,1,1);
      iVar15 = DAT_140e419b8;
    }
    if (0x59 < (int)param_1[3]) {
      sVar16 = *(short *)(param_1 + 0x10);
      dVar32 = *(double *)(param_1 + 0x12);
      dVar33 = (double)FUN_1403307c0();
      fVar44 = (float)(dVar33 * dVar32) + (float)param_1[10];
      param_1[10] = fVar44;
      dVar33 = (double)FUN_140332d90();
      fVar27 = DAT_14053af14;
      fVar43 = DAT_14053aec0;
      fVar41 = DAT_14053ab70;
      *(double *)(param_1 + 0x12) = dVar32 + DAT_140539ec8;
      fVar28 = (float)(dVar33 * dVar32) + (float)param_1[0xb];
      param_1[0xb] = fVar28;
      if ((((DAT_140e445d8 / fVar41 + 0.0 <= fVar44) && (fVar44 <= DAT_140e445d8 / fVar41 + fVar43))
          && (0.0 <= fVar28)) && (fVar28 <= fVar27)) {
        FUN_1403307c0();
        dVar32 = (double)FUN_140332d90();
        uVar19 = (DAT_140e418c8 + 0x1bc >> 0x1e ^ DAT_140e418c8 + 0x1bc) * 0x6c078965 + 1;
        fVar28 = (float)(dVar32 * DAT_14053a3a0) + fVar28;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        uStack_268 = uStack_268 & 0xffffffff00000000;
        sVar16 = (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x961) * -0x961 + sVar16
                 + 0x7b50;
        local_270._0_4_ = 1;
        local_278 = (double)DAT_14053a1e8;
        local_280 = uVar48;
        local_288._0_2_ = sVar16;
        FUN_14006c2f0(3,1,CONCAT22((short)(DAT_140e9fd1c >> 0x10),sVar16),fVar28);
        uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        uStack_268 = uStack_268 & 0xffffffff00000000;
        local_270 = CONCAT44(local_270._4_4_,1);
        local_278 = DAT_14053a1b8;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        local_280 = 0;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
        sVar16 = (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 +
                 *(short *)(param_1 + 0x10) + 0x7a24;
        local_288 = (float)CONCAT22(local_288._2_2_,sVar16);
        FUN_14006c2f0(5,1,CONCAT22((short)(DAT_140e9fd1c >> 0x10),sVar16),fVar28);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        fVar43 = DAT_14053aec0;
        iVar15 = DAT_140e419b8;
        fVar41 = DAT_14053ab70;
        fVar27 = DAT_14053af14;
      }
      if (param_1[5] == 4) {
        iVar9 = 1;
        if (iVar15 == 0) {
          iVar9 = 4;
        }
        uVar31 = 1;
        if ((iVar15 != 0) && (iVar15 != 1)) {
          if ((iVar15 == 2) || (iVar15 == 3)) {
            uVar31 = 2;
          }
          else if (iVar15 == 4) {
            uVar31 = 3;
          }
        }
        dVar32 = DAT_140539fc8;
        if (((iVar15 != 0) && (dVar32 = DAT_14053a010, iVar15 != 1)) &&
           ((dVar32 = DAT_14053a030, iVar15 != 2 &&
            ((dVar32 = DAT_14053a048, iVar15 != 3 && (dVar32 = DAT_140539f40, iVar15 == 4)))))) {
          dVar32 = DAT_14053a0b0;
        }
        sVar13 = 1;
        sVar16 = -1;
        if (iVar15 == 0) {
          sVar13 = 2000;
          sVar16 = -2000;
        }
        else if (iVar15 == 1) {
          sVar13 = 0xed8;
          sVar16 = -0xed8;
        }
        else if ((iVar15 == 2) || (iVar15 == 3)) {
          sVar13 = 0xe10;
          sVar16 = -0xe10;
        }
        else if (iVar15 == 4) {
          sVar13 = 0xc80;
          sVar16 = -0xc80;
        }
        iVar11 = param_1[3];
        if ((local_228 & 1) != 0) {
          sVar16 = sVar13;
        }
        if ((0x59 < iVar11) && (uVar19 = (iVar11 + -0x5a) % iVar9, uVar19 == 0)) {
          if ((DAT_140e445d8 / fVar41 + 0.0 <= (float)param_1[10]) &&
             ((((float)param_1[10] <= DAT_140e445d8 / fVar41 + fVar43 &&
               (0.0 <= (float)param_1[0xb])) && ((float)param_1[0xb] <= fVar27)))) {
            local_260 = 0x10000;
            uStack_268 = CONCAT44(uStack_268._4_4_,uVar31);
            local_270 = CONCAT44(local_270._4_4_,1);
            local_280 = 0;
            local_288 = (float)CONCAT22(local_288._2_2_,
                                        sVar16 * (short)iVar11 + *(short *)(param_1 + 0x10));
            local_278 = dVar32;
            local_258 = uVar19;
            FUN_1400709b0(0xc,3);
            iVar15 = DAT_140e419b8;
            if (2 < DAT_140e419b8) {
              local_278 = dVar32 - DAT_140539f10;
              local_258 = 0;
              local_260 = 0x10000;
              uStack_268 = CONCAT44(uStack_268._4_4_,uVar31);
              local_270 = CONCAT44(local_270._4_4_,1);
              local_280 = 0;
              local_288 = (float)CONCAT22(local_288._2_2_,
                                          *(short *)(param_1 + 3) * sVar16 +
                                          *(short *)(param_1 + 0x10));
              FUN_1400709b0(0xc,3);
              iVar15 = DAT_140e419b8;
            }
          }
        }
      }
      uVar31 = DAT_140e44bfc;
      if (99 < (int)param_1[3]) {
        fVar41 = (float)param_1[10];
        if (((fVar41 < DAT_14053aca8) || (DAT_14053aef4 < fVar41)) ||
           (((float)param_1[0xb] < DAT_14053aca8 || (DAT_14053aef4 < (float)param_1[0xb])))) {
          uVar4 = *(undefined2 *)(param_1 + 0x10);
          uVar36 = param_1[0xb];
          puVar7 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar7 = (undefined8 *)_malloc_base();
            if (puVar7 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
            *(float *)((longlong)puVar7 + 0x14) = fVar41;
            *(undefined4 *)(puVar7 + 3) = uVar36;
            *(float *)((longlong)puVar7 + 0x1c) = fVar41;
            *(undefined4 *)(puVar7 + 4) = uVar36;
            *puVar7 = 1;
            *(undefined4 *)(puVar7 + 1) = 0x22;
            *(undefined4 *)((longlong)puVar7 + 0xc) = uVar31;
            *(undefined4 *)(puVar7 + 2) = 0x24;
            *(undefined2 *)((longlong)puVar7 + 0x24) = uVar4;
            puVar7[5] = 0;
            puVar7[6] = 0x4008000000000000;
            puVar7[7] = 0x4008000000000000;
            *(undefined4 *)(puVar7 + 8) = 0x18;
            *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
            *(undefined4 *)(puVar7 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
            puVar7[10] = 0x80;
            puVar7[0xb] = 0;
            if (bVar26) {
              DAT_140e45d78 = puVar7;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar7;
            }
          }
          DAT_140e45d28 = puVar7;
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e472d0);
          FUN_14018a340(DAT_140e472d0,1,1);
          param_1[5] = param_1[5] + 1;
          iVar15 = DAT_140e419b8;
          param_1[3] = 0;
        }
      }
      uVar31 = SUB84(DAT_14053a060,0);
      uVar36 = (undefined4)((ulonglong)DAT_14053a060 >> 0x20);
      goto LAB_140019a2e;
    }
  }
  else {
LAB_140019a2e:
    uVar46 = SUB84(DAT_14053aba0,0);
    uVar47 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
  }
  iVar9 = param_1[5];
  if ((iVar9 == 5) || (iVar9 == 8)) {
    iVar11 = param_1[3];
    if (iVar11 < 0x5a) {
LAB_140019b54:
      if ((iVar20 != 0xb34) && (iVar20 != 0xc42)) goto LAB_140019b6c;
    }
    else {
      dVar33 = (double)local_224 / dVar40;
      dVar32 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar32 * dVar33) + (float)param_1[10];
      dVar32 = (double)FUN_140332d90();
      uVar23 = *(ushort *)(param_1 + 0x10);
      uVar5 = 0x4000 - uVar23;
      uVar19 = (uint)uVar5;
      if (0x8000 < uVar5) {
        uVar19 = 0x10000 - uVar5;
      }
      iVar17 = -(uint)uVar23 + 0x4000;
      param_1[0xb] = (float)(dVar32 * dVar33) + (float)param_1[0xb];
      iVar18 = (int)uVar19 / 10 + 0x30;
      iVar10 = -(uint)uVar23 + 0x14000;
      if (-0x8001 < iVar17) {
        iVar10 = iVar17;
      }
      iVar17 = iVar10 + -0x10000;
      if (iVar10 < 0x8001) {
        iVar17 = iVar10;
      }
      if (iVar17 < 1) {
        if ((iVar17 < 0) && (uVar23 = uVar23 - (short)iVar18, -iVar18 < iVar17)) {
          uVar23 = 0x4000;
        }
      }
      else if (iVar17 < iVar18) {
        uVar23 = 0x4000;
      }
      else {
        uVar23 = uVar23 + (short)iVar18;
      }
      *(ushort *)(param_1 + 0x10) = uVar23;
      if (iVar11 != 0x78) goto LAB_140019b54;
    }
    param_1[5] = 1;
    *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
    param_1[3] = 0;
LAB_140019f92:
    uVar49 = SUB84(DAT_14053a020,0);
    uVar50 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar45 = SUB84(DAT_140539f40,0);
    uVar48 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    uVar19 = local_228;
  }
  else {
LAB_140019b6c:
    if (iVar9 != 6) goto LAB_140019f92;
    dVar40 = (double)local_224 / dVar40;
    dVar32 = (double)FUN_1403307c0();
    fVar43 = (float)(dVar32 * dVar40) + (float)param_1[10];
    param_1[10] = fVar43;
    dVar33 = (double)FUN_140332d90();
    uVar19 = local_228;
    dVar32 = DAT_14053a020;
    lVar21 = (longlong)(int)local_228;
    uVar49 = SUB84(DAT_14053a020,0);
    uVar50 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    local_1f0 = 0;
    local_1ec = 0x23;
    local_1b0 = 0xfffff060;
    local_1ac = 4000;
    fVar41 = (float)(dVar33 * dVar40) + (float)param_1[0xb];
    local_1c0 = _DAT_14053b960;
    uStack_1b8 = _UNK_14053b968;
    local_200 = _DAT_14053b7e0;
    uStack_1f8 = _UNK_14053b7e8;
    iVar9 = *(int *)((longlong)&local_200 + lVar21 * 4);
    param_1[0xb] = fVar41;
    dVar40 = (double)FUN_140332d90(((double)iVar20 - (double)iVar9) * DAT_14053a6e8 * dVar32 *
                                   DAT_140539d28);
    iVar9 = 1;
    sVar16 = (short)(int)(dVar40 * _DAT_14053aa40) + *(short *)((longlong)&local_1c0 + lVar21 * 4);
    uVar23 = sVar16 + 0x4000;
    if (iVar15 == 0) {
      iVar9 = 0x48;
    }
    else if (iVar15 == 1) {
      iVar9 = 0x2c;
    }
    else if ((iVar15 == 2) || (iVar15 == 3)) {
      iVar9 = 0x20;
    }
    else if (iVar15 == 4) {
      iVar9 = 0x1c;
    }
    iVar11 = 1;
    if (iVar15 == 0) {
      iVar11 = 0xc;
    }
    else if (((iVar15 == 1) || (iVar15 == 2)) || (iVar15 == 3)) {
      iVar11 = 0x10;
    }
    else if (iVar15 == 4) {
      iVar11 = 0x14;
    }
    uVar14 = 1;
    if (((iVar15 != 0) && (iVar15 != 1)) && ((iVar15 != 2 && ((iVar15 == 3 || (iVar15 == 4)))))) {
      uVar14 = 2;
    }
    uVar45 = SUB84(DAT_140539f40,0);
    uVar48 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    dVar40 = DAT_14053a018;
    if (iVar15 != 0) {
      if (iVar15 == 1) {
        dVar40 = (double)CONCAT44(uVar36,uVar31);
      }
      else {
        dVar40 = DAT_14053a088;
        if (((iVar15 != 2) && (iVar15 != 3)) && (dVar40 = DAT_140539f40, iVar15 == 4)) {
          dVar40 = DAT_14053a0d0;
        }
      }
    }
    uVar5 = *(ushort *)(param_1 + 0x10);
    uVar22 = 0x4000 - uVar5;
    uVar24 = (uint)uVar22;
    if (0x8000 < uVar22) {
      uVar24 = 0x10000 - uVar22;
    }
    iVar17 = (uint)uVar23 - (uint)uVar5;
    dVar40 = ((double)iVar20 - _DAT_14053aa18) * DAT_140539d90 + dVar40;
    iVar18 = (int)uVar24 / 10 + 0x30;
    iVar10 = iVar17 + 0x10000;
    if (-0x8001 < iVar17) {
      iVar10 = iVar17;
    }
    iVar17 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar17 = iVar10;
    }
    if (iVar17 < 1) {
      uVar22 = uVar5;
      if ((iVar17 < 0) && (uVar22 = uVar5 - (short)iVar18, -iVar18 < iVar17)) {
        uVar22 = uVar23;
      }
    }
    else {
      uVar22 = uVar23;
      if (iVar18 <= iVar17) {
        uVar22 = uVar5 + (short)iVar18;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar22;
    if (DAT_140e445dc <= fVar41) {
      uVar23 = sVar16 + 0xc000;
    }
    iVar10 = ((int)uVar19 / 2) * 8 + 2000;
    if ((iVar10 <= iVar20) && (uVar24 = (iVar20 - iVar10) % iVar9, (int)uVar24 < iVar11)) {
      uVar24 = uVar24 & 0x80000003;
      if ((int)uVar24 < 0) {
        uVar24 = (uVar24 - 1 | 0xfffffffc) + 1;
      }
      if ((((uVar24 == 0) && (DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar43)) &&
          (fVar27 = DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0, fVar43 <= fVar27)) &&
         ((0.0 <= fVar41 && (fVar41 <= DAT_14053af14)))) {
        local_260 = 0xd05;
        uStack_268 = CONCAT44(uStack_268._4_4_,uVar14);
        local_270 = CONCAT44(local_270._4_4_,1);
        local_280 = 0;
        local_288 = (float)CONCAT22(local_288._2_2_,uVar23);
        local_278 = dVar40;
        local_258 = uVar24;
        FUN_1400709b0(0xd,fVar27,uVar22,fVar41);
        iVar15 = 0;
        do {
          uStack_268 = uStack_268 & 0xffffffff00000000;
          local_270 = CONCAT44(local_270._4_4_,1);
          local_280 = 0;
          local_288 = (float)CONCAT22(local_288._2_2_,(short)iVar15 * 0x5555 + uVar23 + 0x5556);
          local_278 = dVar40;
          FUN_14006c2f0(0xd,0);
          iVar15 = iVar15 + 1;
        } while (iVar15 < 2);
        FUN_140184700(DAT_140e44190 * 9,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar15 = DAT_140e419b8;
      }
    }
    if (iVar20 == 0x9f6) {
      param_1[3] = 0;
      param_1[5] = 1;
    }
  }
  dVar40 = (double)CONCAT44(uVar48,uVar45);
  local_204 = (int)((ulonglong)local_1e8 >> 0x20);
  if (param_1[5] == -1) {
    if ((local_204 != 1) && (0x4f < (int)param_1[3])) {
      *param_1 = 0;
    }
    if (param_1[3] == 200) {
      param_1[7] = param_1[8];
      param_1[10] = fVar29 + (float)param_1[0xc];
      param_1[5] = 0;
      param_1[3] = 0;
      param_1[0xb] = fVar30 + (float)param_1[0xd];
    }
  }
  fVar29 = (float)param_1[10];
  lVar21 = (longlong)(int)uVar19;
  local_1c8 = lVar21;
  fVar30 = local_1a8[lVar21 * 2];
  dVar32 = (double)FUN_1403300b4((double)((float)param_1[0xb] - local_1a8[lVar21 * 2 + 1]),
                                 (double)(fVar29 - fVar30));
  local_208 = (int)(dVar32 * (double)CONCAT44(uVar47,uVar46));
  fVar29 = (float)FUN_140334430(fVar30 - fVar29);
  fVar30 = (float)FUN_140334430();
  if (fVar29 + fVar30 < 0.0) {
    fVar29 = (float)FUN_1403352f8();
  }
  else {
    fVar29 = SQRT(fVar29 + fVar30);
  }
  dVar32 = DAT_140539d28;
  fVar30 = 0.0;
  local_224 = 0.0;
  local_1d8 = FUN_1403307c0();
  fVar29 = fVar29 / DAT_14053ac58;
  auVar42._8_4_ = (int)extraout_XMM0_Qb;
  auVar42._0_8_ = local_1d8;
  auVar42._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
  local_1d0 = (double)FUN_140332d90();
  local_210 = 0;
  local_214 = 0;
  local_218 = 0;
  iVar20 = 0;
  local_20c = 0;
  local_220 = 0x3c;
  local_21c = 0x4000;
  do {
    uVar19 = local_220;
    dVar34 = (double)((float)(int)fVar30 * fVar29);
    fVar41 = local_1a8[lVar21 * 2];
    fVar43 = (float)(local_1d0 * dVar34) + local_1a8[lVar21 * 2 + 1];
    dVar33 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)local_20c) * DAT_14053a890
                                   * (double)CONCAT44(uVar50,uVar49) * dVar32);
    fVar41 = (float)(dVar33 * DAT_14053a070) + 0.0 + (float)(auVar42._0_8_ * dVar34) + fVar41;
    if (param_1[5] == 0) {
      iVar9 = param_1[3];
      dVar33 = dVar40;
      if (iVar20 != iVar20 + 8) {
        if (iVar9 < iVar20) {
          dVar33 = 0.0;
        }
        else {
          dVar33 = (double)CONCAT44(uVar48,uVar45);
          if (iVar9 < iVar20 + 8) {
            dVar33 = (double)FUN_140332d90(((double)iVar9 - (double)iVar20) * DAT_14053aa28 *
                                           (double)CONCAT44(uVar50,uVar49) * dVar32);
            dVar33 = dVar33 + 0.0;
          }
        }
      }
    }
    else {
      dVar33 = (double)CONCAT44(uVar48,uVar45);
      if (param_1[5] == 8) {
        iVar9 = 1;
        iVar11 = local_228 * 0xc + 8;
        if (iVar15 == 0) {
          iVar9 = 7;
        }
        else if (iVar15 == 1) {
          iVar9 = 4;
        }
        else if (iVar15 == 2) {
          iVar9 = 3;
        }
        else if ((iVar15 == 3) || (iVar15 == 4)) {
          iVar9 = 2;
        }
        iVar10 = 1;
        if (iVar15 == 0) {
          iVar10 = 0xe;
        }
        else if (iVar15 == 1) {
          iVar10 = 0x12;
        }
        else if ((iVar15 == 2) || (iVar15 == 3)) {
          iVar10 = 0x14;
        }
        else if (iVar15 == 4) {
          iVar10 = 0x17;
        }
        dVar34 = DAT_14053a040;
        if ((((iVar15 != 0) && (dVar34 = DAT_14053a088, iVar15 != 1)) &&
            (dVar34 = DAT_14053a0b0, iVar15 != 2)) &&
           ((dVar34 = DAT_14053a0d0, iVar15 != 3 &&
            (dVar34 = (double)CONCAT44(uVar48,uVar45), iVar15 == 4)))) {
          dVar34 = DAT_14053a158;
        }
        iVar17 = param_1[3];
        dVar33 = (double)CONCAT44(uVar48,uVar45);
        if (((iVar11 <= iVar17) &&
            ((iVar17 < iVar10 + iVar11 ||
             (dVar33 = (double)CONCAT44(uVar48,uVar45), iVar10 + iVar11 == 0)))) &&
           (iVar10 = iVar17 - iVar11, dVar33 = (double)CONCAT44(uVar48,uVar45),
           iVar10 == (iVar10 / 3 + (iVar10 >> 0x1f) +
                     (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * 3)) {
          uVar24 = (uint)((longlong)(int)fVar30 % (longlong)iVar9);
          dVar33 = (double)CONCAT44(uVar48,uVar45);
          if ((((uVar24 == 0) &&
               (dVar33 = (double)CONCAT44(uVar48,uVar45),
               DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar41)) &&
              (dVar33 = (double)CONCAT44(uVar48,uVar45),
              fVar41 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
             ((dVar33 = (double)CONCAT44(uVar48,uVar45), 0.0 <= fVar43 &&
              (dVar33 = (double)CONCAT44(uVar48,uVar45), fVar43 <= DAT_14053af14)))) {
            local_260 = local_21c;
            uStack_268 = CONCAT44(uStack_268._4_4_,2);
            local_270 = CONCAT44(local_270._4_4_,1);
            local_280 = 0;
            local_288 = (float)CONCAT22(local_288._2_2_,(short)local_208 + -0x8000);
            local_278 = ((double)iVar17 - (double)iVar11) * DAT_140539e60 + dVar34;
            local_258 = uVar24;
            FUN_1400709b0(4,(longlong)(int)fVar30 % (longlong)iVar9 & 0xffffffff,iVar9,fVar43);
            FUN_140184700(DAT_140e44190 * 9,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar15 = DAT_140e419b8;
            dVar33 = (double)CONCAT44(uVar48,uVar45);
          }
        }
      }
    }
    if ((param_1[5] == -1) && (param_1[3] == uVar19)) {
      uVar24 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar19 = uVar24 * 0x800 ^ uVar24;
      DAT_140e9fd10 = (uVar24 >> 0x1e ^ uVar24) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      uVar25 = DAT_140e9fd1c & 0xffff;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47290);
      FUN_14018a340(DAT_140e47290,1,1);
      uVar24 = uVar25 + (int)fVar30;
      uVar19 = (uVar24 >> 0x1e ^ uVar24) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar19;
      uVar35 = FUN_140134db0(uVar24,DAT_140539ee0,DAT_140539f10);
      auVar37._8_4_ = (int)extraout_XMM0_Qb_00;
      auVar37._0_8_ = uVar35;
      auVar37._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_00 >> 0x20);
      local_270 = FUN_140134db0(uVar24);
      local_238 = 0;
      local_240 = 0xff;
      local_248 = 0xff;
      local_250 = 0xff;
      local_258 = 0xff;
      local_260 = 0x18;
      uStack_268 = auVar37._0_8_;
      local_278 = (double)CONCAT44(uVar48,uVar45);
      local_288 = fVar43;
      local_280._0_2_ = (short)uVar19 - (short)(uVar19 / 0x10001);
      FUN_140070d00(0x2a,DAT_140e41a54,0x1d,fVar41);
      iVar15 = local_214 + uVar25;
      uVar19 = (local_218 + DAT_140e418c8 >> 0x1e ^ local_218 + DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar19;
      uVar35 = FUN_140134db0(iVar15,DAT_140539f18);
      uVar31 = (undefined4)uVar35;
      uVar36 = (undefined4)((ulonglong)uVar35 >> 0x20);
      uVar35 = FUN_140134db0(iVar15);
      auVar38._8_4_ = (int)extraout_XMM0_Qb_01;
      auVar38._0_8_ = uVar35;
      auVar38._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_01 >> 0x20);
      local_278 = (double)FUN_140134db0(local_210 + DAT_140e418c8,DAT_14053a0f8,DAT_14053a1b8);
      local_238 = 0;
      local_240 = 0xc0;
      local_248 = 0xff;
      local_250 = 0xff;
      local_258 = 0xff;
      local_260 = 0;
      uStack_268 = CONCAT44(uVar36,uVar31);
      local_270 = auVar38._0_8_;
      local_280 = CONCAT22(local_280._2_2_,(short)uVar19 - (short)(uVar19 / 0x10001));
      local_288 = fVar43;
      FUN_140070d00(0x2c,DAT_140e44ea8,0x3e,fVar41);
      iVar15 = DAT_140e419b8;
      uVar19 = local_220;
      fVar30 = local_224;
    }
    uVar31 = DAT_140e4470c;
    if ((-1 < (int)param_1[5]) ||
       ((puVar8 = DAT_140e46c88, param_1[5] == -1 && ((int)param_1[3] <= (int)uVar19)))) {
      uVar4 = *(undefined2 *)(param_1 + 0x10);
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar8[3] = fVar41;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      puVar8[4] = fVar43;
      *puVar8 = uVar31;
      puVar8[1] = 0x1c;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = uVar4;
      auVar1._8_4_ = SUB84(dVar33,0);
      auVar1._0_8_ = dVar33;
      auVar1._12_4_ = (int)((ulonglong)dVar33 >> 0x20);
      *(undefined1 (*) [16])(puVar8 + 6) = auVar1;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      _DAT_140e46d00 = _DAT_140e46d00 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar8;
      }
      iVar15 = DAT_140e419b8;
      fVar30 = local_224;
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
        iVar15 = DAT_140e419b8;
      }
    }
    DAT_140e46c88 = puVar8;
    fVar30 = (float)((int)fVar30 + 1);
    local_20c = local_20c + 7;
    local_218 = local_218 + 0xb;
    local_21c = local_21c + 0x666;
    local_214 = local_214 + 0x457;
    local_220 = uVar19 + -3;
    local_210 = local_210 + 0x22b;
    iVar20 = iVar20 + 2;
    auVar42._8_8_ = 0;
    auVar42._0_8_ = local_1d8;
    lVar21 = local_1c8;
    local_224 = fVar30;
  } while (local_21c < 0xbff8);
  iVar20 = param_1[5];
  if (iVar20 == 0) {
    iVar20 = param_1[3];
    if (iVar20 < 0x28) {
      dVar40 = 0.0;
    }
    else if (iVar20 < 0x30) {
      dVar40 = (double)FUN_140332d90(((double)iVar20 - DAT_14053a340) * DAT_14053aa28 *
                                     (double)CONCAT44(uVar50,uVar49) * dVar32);
      dVar40 = dVar40 + _DAT_140539cc0;
    }
  }
  else {
    if (((iVar20 == 5) || (iVar20 == 8)) &&
       (dVar40 = (double)CONCAT44(uVar48,uVar45), (int)param_1[3] < 9)) {
      dVar40 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053aad0 *
                                     (double)CONCAT44(uVar50,uVar49) * dVar32);
      dVar40 = dVar40 * DAT_140539ef8 + (double)CONCAT44(uVar48,uVar45);
    }
    puVar8 = DAT_140e46c88;
    if (iVar20 < 0) goto LAB_14001a9c0;
  }
  uVar46 = DAT_140e44bfc;
  uVar4 = *(undefined2 *)(param_1 + 0x10);
  uVar31 = param_1[0xb];
  uVar36 = param_1[10];
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar8[3] = uVar36;
  puVar8[4] = uVar31;
  *puVar8 = uVar46;
  puVar8[1] = 0x23;
  puVar8[2] = 7;
  *(undefined2 *)(puVar8 + 5) = uVar4;
  auVar2._8_4_ = SUB84(dVar40,0);
  auVar2._0_8_ = dVar40;
  auVar2._12_4_ = (int)((ulonglong)dVar40 >> 0x20);
  *(undefined1 (*) [16])(puVar8 + 6) = auVar2;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
LAB_14001a9c0:
  DAT_140e46c88 = puVar8;
  uVar31 = DAT_140e44bfc;
  iVar20 = param_1[5];
  if ((iVar20 == 4) || (iVar20 == 7)) {
    uVar19 = param_1[3] & 0x80000003;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffffc) + 1;
    }
    if ((int)uVar19 < 2) {
      uVar4 = *(undefined2 *)(param_1 + 0x10);
      uVar36 = param_1[0xb];
      uVar46 = param_1[10];
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar8[3] = uVar46;
      puVar8[4] = uVar36;
      *puVar8 = uVar31;
      puVar8[1] = 0x23;
      puVar8[2] = 8;
      *(undefined2 *)(puVar8 + 5) = uVar4;
      auVar3._8_4_ = SUB84(dVar40,0);
      auVar3._0_8_ = dVar40;
      auVar3._12_4_ = (int)((ulonglong)dVar40 >> 0x20);
      *(undefined1 (*) [16])(puVar8 + 6) = auVar3;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar26) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
      iVar20 = param_1[5];
      DAT_140e46c88 = puVar8;
    }
  }
  if (param_1[0x15] == 0) {
    local_288 = DAT_14053b370;
    FUN_140079c10(param_1,1,iVar20,0);
    iVar20 = param_1[5];
  }
  if ((int)param_1[7] < 1) {
    if (iVar20 < 1) {
      return;
    }
    FUN_14007b010(param_1,2000,8);
    FUN_140079e20(param_1,1);
    local_260 = DAT_140e44308;
    uStack_268 = CONCAT44(uStack_268._4_4_,1);
    local_270 = CONCAT44(local_270._4_4_,10);
    local_278 = (double)CONCAT44(uVar48,uVar45);
    local_280 = CONCAT22(local_280._2_2_,0x4000);
    local_288 = (float)DAT_14053b380;
    stage_entity_spawn_candidate(0x153,param_1[8],1);
    iVar20 = DAT_140e44308;
    puVar8 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar8 != (undefined4 *)0x0; puVar8 = *(undefined4 **)(puVar8 + 0x18)) {
        if (puVar8[1] == iVar20) {
          puVar8[0x17] = puVar8[0x17] + -1;
        }
      }
    }
  }
  else {
    if (iVar20 < 1) {
      return;
    }
    if (((0 < iStack_1dc) && (0 < DAT_140e4430c)) && (local_204 < 2)) {
      return;
    }
    FUN_140079e20(param_1,1);
  }
  param_1[0x15] = 1;
  param_1[3] = 0;
  param_1[5] = 0xffffffff;
  return;
}


