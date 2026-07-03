// Function: FUN_1400e9e20 @ 1400e9e20
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e9e20(undefined4 *param_1)

{
  short sVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  double dVar5;
  undefined2 uVar6;
  ushort uVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  longlong lVar15;
  int iVar16;
  ushort uVar17;
  ushort uVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  undefined8 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  int iVar39;
  undefined1 auStack_298 [32];
  float local_278;
  undefined4 local_270;
  double local_268;
  undefined8 local_260;
  ulonglong uStack_258;
  int local_250;
  undefined4 local_248;
  undefined4 local_240;
  undefined4 local_238;
  undefined4 local_230;
  undefined4 local_228;
  float local_218;
  float local_214;
  int local_210;
  uint local_20c;
  int local_208;
  float local_204;
  undefined4 local_200;
  int iStack_1fc;
  undefined4 uStack_1f8;
  int iStack_1f4;
  longlong local_1f0;
  undefined8 local_1e8;
  double local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  int iStack_1cc;
  undefined4 local_1c8;
  int iStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  float fStack_1b0;
  float fStack_1ac;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  float local_108 [4];
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  ulonglong local_d8;
  
  puVar10 = DAT_140e45d80;
  iVar14 = DAT_140e44e6c;
  iVar23 = DAT_140e44308;
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_298;
  uStack_1bc = 0;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined4 *)0x0)) {
    iStack_1f4 = 0;
    local_1d8 = 0;
    fVar36 = fStack_1b0;
    fVar37 = fStack_1ac;
    iVar39 = iStack_1c4;
  }
  else {
    iStack_1f4 = 0;
    local_1d8 = 0;
    puVar8 = DAT_140e45d80;
    do {
      if (puVar8[1] == DAT_140e44308) {
        local_1d8 = *puVar8;
        uStack_1d4 = puVar8[1];
        uStack_1d0 = puVar8[2];
        iStack_1cc = puVar8[3];
        local_1c8 = puVar8[4];
        iStack_1c4 = puVar8[5];
        uStack_1c0 = puVar8[6];
        iStack_1f4 = puVar8[7];
        fStack_1b0 = (float)puVar8[10];
        fStack_1ac = (float)puVar8[0xb];
      }
      puVar8 = *(undefined4 **)(puVar8 + 0x18);
      fVar36 = fStack_1b0;
      fVar37 = fStack_1ac;
      iVar39 = iStack_1c4;
    } while (puVar8 != (undefined4 *)0x0);
  }
  iVar16 = param_1[1] - DAT_1407c77a0;
  fVar35 = (float)param_1[0xd];
  fVar38 = (float)param_1[0xc];
  local_200 = local_1c8;
  iStack_1fc = iVar39;
  uStack_1f8 = uStack_1c0;
  dVar29 = (double)FUN_1403300b4((double)((fVar37 + fVar35) - (float)param_1[0xb]),
                                 (double)((fVar36 + fVar38) - (float)param_1[10]));
  uVar22 = (uint)(dVar29 * DAT_14053aba0);
  local_20c = uVar22;
  fVar25 = (float)FUN_140334430();
  fVar26 = (float)FUN_140334430();
  if (fVar25 + fVar26 < 0.0) {
    local_218 = (float)FUN_1403352f8();
  }
  else {
    local_218 = SQRT(fVar25 + fVar26);
  }
  local_108[0] = fVar36 + DAT_14053acbc;
  local_108[1] = fVar37 + DAT_14053ad70;
  local_f8 = fVar36 + DAT_14053ad1c;
  local_108[3] = fVar37 + DAT_14053ad70;
  local_108[2] = fVar36 - DAT_14053acbc;
  local_f0 = fVar36 - DAT_14053ad1c;
  local_f4 = fVar37 + DAT_14053ad5c;
  local_ec = fVar37 + DAT_14053ad5c;
  local_e4 = fVar37 + DAT_14053ad40;
  local_dc = fVar37 + DAT_14053ad40;
  local_e8 = fVar36 + DAT_14053ad5c;
  local_e0 = fVar36 - DAT_14053ad5c;
  if (param_1[5] == 0) {
    iVar11 = 0;
    if (param_1[3] == 0) {
      param_1[10] = fVar36 + fVar38;
      param_1[0xb] = fVar37 + fVar35;
    }
    else if (param_1[3] == 0x28) {
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      iVar11 = param_1[5];
      puVar10 = DAT_140e45d80;
      iVar14 = DAT_140e44e6c;
      iVar23 = DAT_140e44308;
    }
    if (param_1[3] == 0x3c) {
      if ((iVar16 == 0) || (uVar6 = 0x7c18, iVar16 - 3U < 2)) {
        uVar6 = 1000;
      }
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar6;
      param_1[5] = iVar11 + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
      if (0 < iVar14) {
        for (; puVar10 != (undefined4 *)0x0; puVar10 = *(undefined4 **)(puVar10 + 0x18)) {
          if (puVar10[1] == iVar23) {
            puVar10[0x17] = puVar10[0x17] + 1;
          }
        }
      }
    }
  }
  iVar14 = iStack_1cc;
  dVar5 = DAT_14053a020;
  dVar4 = DAT_140539f40;
  dVar29 = DAT_140539d28;
  iVar23 = param_1[5];
  if (iVar23 == 1) {
    uVar17 = *(ushort *)((longlong)param_1 + 0x42);
    iVar11 = (uVar22 & 0xffff) - (uint)uVar17;
    iVar23 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar23 = iVar11;
    }
    iVar11 = iVar23 + -0x10000;
    if (iVar23 < 0x8001) {
      iVar11 = iVar23;
    }
    if (iVar11 < 1) {
      uVar7 = uVar17;
      if ((iVar11 < 0) && (uVar7 = uVar17 - 0x457, -0x457 < iVar11)) {
        uVar7 = (ushort)uVar22;
      }
    }
    else {
      uVar7 = (ushort)uVar22;
      if (0x456 < iVar11) {
        uVar7 = uVar17 + 0x457;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar7;
    dVar30 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar30 = (double)FUN_140332d90();
    uVar17 = *(ushort *)(param_1 + 0x10);
    uVar7 = 0x4000 - uVar17;
    uVar22 = (uint)uVar7;
    if (0x8000 < uVar7) {
      uVar22 = 0x10000 - uVar7;
    }
    iVar11 = -(uint)uVar17 + 0x4000;
    param_1[0xb] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar19 = (int)uVar22 / 10 + 0x30;
    iVar23 = -(uint)uVar17 + 0x14000;
    if (-0x8001 < iVar11) {
      iVar23 = iVar11;
    }
    iVar11 = iVar23 + -0x10000;
    if (iVar23 < 0x8001) {
      iVar11 = iVar23;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar17 = uVar17 - (short)iVar19, -iVar19 < iVar11)) {
        uVar17 = 0x4000;
      }
    }
    else if (iVar11 < iVar19) {
      uVar17 = 0x4000;
    }
    else {
      uVar17 = uVar17 + (short)iVar19;
    }
    *(ushort *)(param_1 + 0x10) = uVar17;
    if (iVar14 == iVar16 * 0xf + 10) {
      param_1[3] = 0;
      iVar23 = 2;
      param_1[5] = 2;
    }
    else {
      iVar23 = param_1[5];
    }
    if (iVar14 == iVar16 * 0x14 + 0x14a) {
      param_1[3] = 0;
      iVar23 = 4;
      param_1[5] = 4;
    }
    if (iVar14 == 0x2a8) {
      param_1[3] = 0;
      iVar23 = 6;
      param_1[5] = 6;
    }
    if (iVar14 != 0x3b6) goto LAB_1400ea371;
    param_1[3] = 0;
    iVar23 = 8;
    param_1[5] = 8;
LAB_1400ea389:
    fVar35 = (float)param_1[0xb];
    fVar38 = (float)param_1[10];
    dVar30 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar35),(double)(DAT_140e445d8 - fVar38)
                                  );
    local_168 = _DAT_14053bea0;
    uStack_160 = _UNK_14053bea8;
    local_148 = _DAT_14053bd20;
    uStack_140 = _UNK_14053bd28;
    local_158 = _DAT_14053bde0;
    uStack_150 = _UNK_14053bde8;
    local_118 = _DAT_14053be20;
    uStack_110 = _UNK_14053be28;
    local_138 = _DAT_14053bec0;
    uStack_130 = _UNK_14053bec8;
    local_128 = _DAT_14053beb0;
    uStack_120 = _UNK_14053beb8;
    if (param_1[3] == 1) {
      local_228 = param_1[1];
      local_230 = 0x80;
      local_238 = 0xff;
      local_240 = 0xff;
      local_248 = 0xff;
      local_250 = 0x5a;
      local_260 = _DAT_14053baf0;
      uStack_258 = _UNK_14053baf8;
      local_268 = 0.0;
      local_270 = CONCAT22(local_270._2_2_,*(undefined2 *)(param_1 + 0x10));
      local_278 = fVar35;
      FUN_140070d00(0x41,DAT_140e41a90,0x50,fVar38);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
      fVar35 = (float)param_1[0xb];
      fVar38 = (float)param_1[10];
      iVar23 = param_1[5];
    }
    dVar31 = DAT_14053aba0;
    if ((int)param_1[3] < 0x32) {
      if (iVar23 == 6) {
        dVar30 = (double)FUN_1403300b4((double)(*(float *)((longlong)&local_168 +
                                                          (longlong)iVar16 * 8 + 4) - fVar35),
                                       (double)(*(float *)(&local_168 + iVar16) - fVar38));
        dVar30 = dVar30 * DAT_14053aba0;
      }
      else {
        dVar30 = dVar30 * DAT_14053aba0;
        if (iVar23 == 8) {
          dVar30 = (double)FUN_1403300b4((double)(*(float *)((longlong)&local_138 +
                                                            (longlong)iVar16 * 8 + 4) - fVar35),
                                         (double)(*(float *)(&local_138 + iVar16) - fVar38));
          dVar30 = dVar30 * dVar31;
        }
      }
      uVar17 = *(ushort *)(param_1 + 0x10);
      uVar18 = (ushort)(int)dVar30;
      uVar7 = uVar18 - uVar17;
      uVar22 = (uint)uVar7;
      if (0x8000 < uVar7) {
        uVar22 = 0x10000 - uVar7;
      }
      iVar11 = ((int)dVar30 & 0xffffU) - (uint)uVar17;
      iVar19 = (int)uVar22 / 10 + 0x30;
      iVar23 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar23 = iVar11;
      }
      iVar11 = iVar23 + -0x10000;
      if (iVar23 < 0x8001) {
        iVar11 = iVar23;
      }
      if (iVar11 < 1) {
        uVar7 = uVar17;
        if ((iVar11 < 0) && (uVar7 = uVar17 - (short)iVar19, -iVar19 < iVar11)) {
          uVar7 = uVar18;
        }
      }
      else {
        uVar7 = uVar18;
        if (iVar19 <= iVar11) {
          uVar7 = uVar17 + (short)iVar19;
        }
      }
      fVar38 = (float)param_1[10];
      fVar35 = (float)param_1[0xb];
      *(ushort *)(param_1 + 0x10) = uVar7;
    }
    uVar27 = DAT_140e472cc;
    iVar23 = param_1[3];
    if (iVar23 == 0x5a) {
      *(undefined8 *)(param_1 + 0x12) = 0x4024000000000000;
      FUN_140184700(DAT_140e44190 * 0x19,uVar27);
      FUN_14018a340(DAT_140e472cc,1,1);
      iVar23 = param_1[3];
      fVar38 = (float)param_1[10];
      fVar35 = (float)param_1[0xb];
    }
    if (0x59 < iVar23) {
      sVar1 = *(short *)(param_1 + 0x10);
      dVar30 = *(double *)(param_1 + 0x12);
      dVar31 = (double)FUN_1403307c0();
      fVar38 = (float)(dVar31 * dVar30) + fVar38;
      param_1[10] = fVar38;
      dVar31 = (double)FUN_140332d90();
      *(double *)(param_1 + 0x12) = dVar30 + DAT_140539ec8;
      local_214 = (float)(dVar31 * dVar30) + fVar35;
      param_1[0xb] = local_214;
      if (((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar38) &&
          (fVar38 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
         ((0.0 <= local_214 && (local_214 <= DAT_14053af14)))) {
        FUN_1403307c0();
        dVar30 = (double)FUN_140332d90();
        uStack_258 = uStack_258 & 0xffffffff00000000;
        local_260._0_4_ = 1;
        uVar22 = (DAT_140e418c8 + 0x1bc >> 0x1e ^ DAT_140e418c8 + 0x1bc) * 0x6c078965 + 1;
        fVar35 = (float)(dVar30 * DAT_14053a3a0) + local_214;
        local_268 = (double)DAT_14053a1e8;
        local_270 = DAT_14053ac2c;
        DAT_140e9fd10 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar22 = uVar22 * 0x800 ^ uVar22;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar22) >> 8 ^ uVar22 ^ DAT_140e9fd18;
        local_278._0_2_ =
             sVar1 + (short)((ulonglong)DAT_140e9fd1c / 0x961) * -0x961 + (short)DAT_140e9fd1c +
             0x7b50;
        FUN_14006c2f0(3,1,(ulonglong)DAT_140e9fd1c,fVar35);
        uVar22 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 2;
        uStack_258 = uStack_258 & 0xffffffff00000000;
        local_260 = CONCAT44(local_260._4_4_,1);
        local_268 = DAT_14053a1b8;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        local_270 = 0;
        uVar22 = uVar22 * 0x800 ^ uVar22;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar22) >> 8 ^ uVar22 ^ DAT_140e9fd18;
        local_278 = (float)CONCAT22(local_278._2_2_,
                                    *(short *)(param_1 + 0x10) +
                                    (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 +
                                    (short)DAT_140e9fd1c + 0x7a24);
        FUN_14006c2f0(5,1,(ulonglong)DAT_140e9fd1c,fVar35);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      iVar39 = iStack_1fc;
      if (99 < (int)param_1[3]) {
        if (((((float)param_1[10] < DAT_14053aca8) || (DAT_14053aef4 < (float)param_1[10])) ||
            ((float)param_1[0xb] < DAT_14053aca8)) || (DAT_14053aef4 < (float)param_1[0xb])) {
          iVar23 = 1;
          if (DAT_140e419b8 == 0) {
            iVar23 = 0xc;
          }
          else if (DAT_140e419b8 == 1) {
LAB_1400ea97b:
            iVar23 = 0x18;
          }
          else if (DAT_140e419b8 == 2) {
            iVar23 = 0x20;
          }
          else if (DAT_140e419b8 == 3) {
            iVar23 = 0x14;
          }
          else if (DAT_140e419b8 == 4) goto LAB_1400ea97b;
          dVar30 = DAT_14053a040;
          if (((DAT_140e419b8 != 0) && (dVar30 = DAT_14053a088, DAT_140e419b8 != 1)) &&
             ((dVar30 = DAT_14053a0b0, DAT_140e419b8 != 2 &&
              ((dVar30 = DAT_14053a0d0, DAT_140e419b8 != 3 && (dVar30 = dVar4, DAT_140e419b8 == 4)))
              ))) {
            dVar30 = DAT_14053a120;
          }
          local_248 = 0;
          local_250 = 0x10000;
          uStack_258 = CONCAT44(uStack_258._4_4_,iVar23);
          local_260 = CONCAT44(local_260._4_4_,1);
          local_270 = 0;
          local_278 = (float)CONCAT22(local_278._2_2_,*(undefined2 *)(param_1 + 0x10));
          local_268 = dVar30;
          FUN_1400709b0(2);
          if (2 < DAT_140e419b8) {
            local_268 = dVar30 - dVar4;
            local_248 = 0;
            local_250 = 0x10000;
            uStack_258 = CONCAT44(uStack_258._4_4_,iVar23);
            local_260 = CONCAT44(local_260._4_4_,1);
            local_270 = 0;
            local_278 = (float)CONCAT22(local_278._2_2_,
                                        (short)(0x10000 / (ulonglong)(uint)(iVar23 * 2)) +
                                        *(short *)(param_1 + 0x10));
            FUN_1400709b0(4,7,(ulonglong)(uint)(iVar23 * 2),param_1[0xb]);
          }
          uVar33 = DAT_140e44bfc;
          uVar6 = *(undefined2 *)(param_1 + 0x10);
          uVar27 = param_1[0xb];
          uVar28 = param_1[10];
          puVar9 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar9 = (undefined8 *)_malloc_base(0x60);
            if (puVar9 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            *(undefined4 *)((longlong)puVar9 + 0xc) = uVar33;
            bVar24 = DAT_140e45d78 == (undefined8 *)0x0;
            *(undefined4 *)((longlong)puVar9 + 0x14) = uVar28;
            *(undefined4 *)(puVar9 + 3) = uVar27;
            *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar28;
            *(undefined4 *)(puVar9 + 4) = uVar27;
            *puVar9 = 1;
            *(undefined4 *)(puVar9 + 1) = 0x22;
            *(undefined4 *)(puVar9 + 2) = 0x24;
            *(undefined2 *)((longlong)puVar9 + 0x24) = uVar6;
            puVar9[5] = 0;
            puVar9[6] = 0x4008000000000000;
            puVar9[7] = 0x4008000000000000;
            *(undefined4 *)(puVar9 + 8) = 0x18;
            *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
            *(undefined4 *)(puVar9 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
            puVar9[10] = 0x80;
            puVar9[0xb] = 0;
            if (bVar24) {
              DAT_140e45d78 = puVar9;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar9;
            }
          }
          DAT_140e45d28 = puVar9;
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e472d0);
          FUN_14018a340(DAT_140e472d0,1,1);
          param_1[5] = param_1[5] + 1;
          param_1[3] = 0;
          iVar39 = iStack_1fc;
        }
      }
    }
  }
  else {
LAB_1400ea371:
    if ((((iVar23 == 2) || (iVar23 == 4)) || (iVar23 == 6)) || (iVar23 == 8)) goto LAB_1400ea389;
  }
  iVar11 = 0;
  iVar23 = param_1[5];
  if ((((iVar23 - 3U & 0xfffffff9) == 0) && (iVar23 != 9)) || (iVar23 == 9)) {
    iVar19 = param_1[3];
    if (iVar19 < 0x3c) {
LAB_1400eacd4:
      if ((iVar14 != 0xb34) && (iVar14 != 0xc42)) goto LAB_1400eacfe;
    }
    else {
      dVar31 = (double)local_218 / DAT_14053a278;
      dVar30 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar30 * dVar31) + (float)param_1[10];
      dVar30 = (double)FUN_140332d90();
      uVar17 = *(ushort *)(param_1 + 0x10);
      uVar7 = 0x4000 - uVar17;
      uVar22 = (uint)uVar7;
      if (0x8000 < uVar7) {
        uVar22 = 0x10000 - uVar7;
      }
      iVar12 = -(uint)uVar17 + 0x4000;
      param_1[0xb] = (float)(dVar30 * dVar31) + (float)param_1[0xb];
      iVar20 = (int)uVar22 / 10 + 0x30;
      iVar23 = -(uint)uVar17 + 0x14000;
      if (-0x8001 < iVar12) {
        iVar23 = iVar12;
      }
      iVar12 = iVar23 + -0x10000;
      if (iVar23 < 0x8001) {
        iVar12 = iVar23;
      }
      if (iVar12 < 1) {
        if ((iVar12 < 0) && (uVar17 = uVar17 - (short)iVar20, -iVar20 < iVar12)) {
          uVar17 = 0x4000;
        }
      }
      else if (iVar12 < iVar20) {
        uVar17 = 0x4000;
      }
      else {
        uVar17 = uVar17 + (short)iVar20;
      }
      iVar23 = param_1[5];
      *(ushort *)(param_1 + 0x10) = uVar17;
      if (iVar19 != 0x5a) goto LAB_1400eacd4;
    }
    param_1[5] = 1;
    *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
LAB_1400ead5c:
    param_1[3] = 0;
  }
  else {
LAB_1400eacfe:
    if (iVar23 == -1) {
      if ((iVar39 != 1) && (0x4f < (int)param_1[3])) {
        *param_1 = 0;
      }
      if (param_1[3] == 200) {
        param_1[7] = param_1[8];
        param_1[5] = 0;
        param_1[10] = fVar36 + (float)param_1[0xc];
        param_1[0xb] = fVar37 + (float)param_1[0xd];
        goto LAB_1400ead5c;
      }
    }
  }
  fVar36 = (float)param_1[10];
  fVar37 = (float)param_1[0xb];
  lVar15 = (longlong)iVar16;
  local_204 = local_108[lVar15 * 2];
  fVar35 = local_108[lVar15 * 2 + 1];
  local_1f0 = lVar15;
  fVar38 = (float)FUN_140334430(local_204 - fVar36);
  fVar25 = (float)FUN_140334430(fVar35 - fVar37);
  if (fVar38 + fVar25 < 0.0) {
    fVar38 = (float)FUN_1403352f8();
  }
  else {
    fVar38 = SQRT(fVar38 + fVar25);
  }
  local_20c = 0;
  fVar25 = local_108[lVar15 * 2];
  FUN_1403300b4((double)(fVar37 - fVar35),(double)(fVar36 - fVar25));
  local_1e8 = FUN_1403307c0();
  fVar38 = fVar38 / DAT_14053ac58;
  uVar27 = (undefined4)local_1e8;
  uVar28 = (undefined4)((ulonglong)local_1e8 >> 0x20);
  local_1e0 = (double)FUN_140332d90();
  local_214 = 0.0;
  local_218 = 0.0;
  local_210 = 0;
  local_208 = 0;
  iVar23 = 0x3c;
  uVar22 = iVar11;
  do {
    iVar14 = local_210;
    fVar37 = local_214;
    fVar36 = local_218;
    dVar31 = (double)((float)(int)uVar22 * fVar38);
    fVar26 = (float)(local_1e0 * dVar31) + local_108[local_1f0 * 2 + 1];
    dVar30 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)(int)local_214) *
                                   DAT_14053a890 * dVar5 * dVar29);
    fVar35 = (float)(dVar30 * DAT_14053a070) + 0.0 +
             (float)(dVar31 * (double)CONCAT44(uVar28,uVar27)) + fVar25;
    dVar30 = dVar4;
    if (param_1[5] == 0) {
      iVar39 = param_1[3];
      if (iVar11 != iVar11 + 8) {
        if (iVar39 < iVar11) {
          dVar30 = 0.0;
        }
        else if (iVar39 < iVar11 + 8) {
          dVar30 = (double)FUN_140332d90(((double)iVar39 - (double)iVar11) * DAT_14053aa28 * dVar5 *
                                         dVar29);
          dVar30 = dVar30 + 0.0;
        }
      }
    }
    else if ((param_1[5] == -1) && (param_1[3] == iVar23)) {
      uVar21 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar13 = uVar21 * 0x800 ^ uVar21;
      DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
      uVar21 = DAT_140e9fd1c & 0xffff;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47290);
      FUN_14018a340(DAT_140e47290,1,1);
      uVar22 = uVar22 + uVar21;
      uVar13 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar13 = uVar13 * 0x800 ^ uVar13;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar13 = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar13;
      uVar32 = FUN_140134db0(uVar22,DAT_140539ee0,DAT_140539f10);
      uVar27 = (undefined4)uVar32;
      uVar28 = (undefined4)((ulonglong)uVar32 >> 0x20);
      local_260 = FUN_140134db0(uVar22);
      local_228 = 0;
      local_230 = 0xff;
      local_238 = 0xff;
      local_240 = 0xff;
      local_248 = 0xff;
      local_250 = 0x18;
      uStack_258 = CONCAT44(uVar28,uVar27);
      local_268 = dVar4;
      local_278 = fVar26;
      local_270._0_2_ = (short)uVar13 - (short)(uVar13 / 0x10001);
      FUN_140070d00(0x2a,DAT_140e41a54,0x1d,fVar35);
      uVar22 = DAT_140e418c8;
      iVar14 = local_210 + uVar21;
      uVar13 = (local_208 + DAT_140e418c8 >> 0x1e ^ local_208 + DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar13 = uVar13 * 0x800 ^ uVar13;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar13 = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar13;
      uVar32 = FUN_140134db0(iVar14,DAT_140539f18);
      uVar27 = (undefined4)uVar32;
      uVar33 = (undefined4)((ulonglong)uVar32 >> 0x20);
      uVar32 = FUN_140134db0(iVar14);
      fVar36 = local_218;
      uVar28 = (undefined4)uVar32;
      uVar34 = (undefined4)((ulonglong)uVar32 >> 0x20);
      local_268 = (double)FUN_140134db0((int)local_218 + uVar22,DAT_14053a0f8,DAT_14053a1b8);
      local_228 = 0;
      local_230 = 0xc0;
      local_238 = 0xff;
      local_240 = 0xff;
      local_248 = 0xff;
      local_250 = 0;
      uStack_258 = CONCAT44(uVar33,uVar27);
      local_260 = CONCAT44(uVar34,uVar28);
      local_270 = CONCAT22(local_270._2_2_,(short)uVar13 - (short)(uVar13 / 0x10001));
      local_278 = fVar26;
      FUN_140070d00(0x2c,DAT_140e44ea8,0x3e,fVar35);
      fVar37 = local_214;
      uVar22 = local_20c;
      iVar14 = local_210;
    }
    if ((-1 < (int)param_1[5]) ||
       ((puVar10 = DAT_140e46c88, param_1[5] == -1 && ((int)param_1[3] <= iVar23)))) {
      uVar6 = *(undefined2 *)(param_1 + 0x10);
      local_214 = (float)DAT_140e4470c;
      puVar10 = (undefined4 *)_malloc_base(0x48);
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar10 = local_214;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      puVar10[3] = fVar35;
      puVar10[4] = fVar26;
      puVar10[1] = 0x1c;
      puVar10[2] = 7;
      *(undefined2 *)(puVar10 + 5) = uVar6;
      *(double *)(puVar10 + 6) = dVar30;
      *(double *)(puVar10 + 8) = dVar30;
      puVar10[10] = 0xff;
      puVar10[0xb] = 0xff;
      puVar10[0xc] = 0xff;
      puVar10[0xd] = 0xff;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      _DAT_140e46d00 = _DAT_140e46d00 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar10;
      }
      iVar14 = local_210;
      fVar36 = local_218;
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
    }
    DAT_140e46c88 = puVar10;
    local_208 = local_208 + 0xb;
    uVar22 = uVar22 + 1;
    local_214 = (float)((int)fVar37 + 7);
    uVar27 = (undefined4)local_1e8;
    uVar28 = (undefined4)((ulonglong)local_1e8 >> 0x20);
    local_210 = iVar14 + 0x457;
    local_218 = (float)((int)fVar36 + 0x22b);
    iVar11 = iVar11 + 2;
    iVar23 = iVar23 + -3;
    fVar25 = local_204;
    local_20c = uVar22;
  } while (0 < iVar23);
  iVar23 = param_1[5];
  dVar30 = dVar4;
  if (iVar23 == 0) {
    iVar23 = param_1[3];
    if (iVar23 < 0x28) {
      dVar30 = 0.0;
    }
    else if (iVar23 < 0x30) {
      dVar30 = (double)FUN_140332d90(((double)iVar23 - DAT_14053a340) * DAT_14053aa28 * dVar5 *
                                     dVar29);
      dVar30 = dVar30 + 0.0;
    }
  }
  else {
    if (((iVar23 == 5) || (iVar23 == 8)) && ((int)param_1[3] < 9)) {
      dVar29 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053aad0 * dVar5 *
                                     dVar29);
      dVar30 = dVar29 * DAT_140539ef8 + dVar4;
    }
    puVar10 = DAT_140e46c88;
    if (iVar23 < 0) goto LAB_1400eb504;
  }
  uVar33 = DAT_140e44bfc;
  uVar6 = *(undefined2 *)(param_1 + 0x10);
  uVar27 = param_1[0xb];
  uVar28 = param_1[10];
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  bVar24 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar10[3] = uVar28;
  puVar10[4] = uVar27;
  *puVar10 = uVar33;
  puVar10[1] = 0x23;
  puVar10[2] = 7;
  *(undefined2 *)(puVar10 + 5) = uVar6;
  auVar2._8_4_ = SUB84(dVar30,0);
  auVar2._0_8_ = dVar30;
  auVar2._12_4_ = (int)((ulonglong)dVar30 >> 0x20);
  *(undefined1 (*) [16])(puVar10 + 6) = auVar2;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar24) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
LAB_1400eb504:
  DAT_140e46c88 = puVar10;
  uVar27 = DAT_140e44bfc;
  iVar23 = param_1[5];
  if ((iVar23 == 2) || (iVar23 == 4)) {
    uVar22 = param_1[3] & 0x80000003;
    if ((int)uVar22 < 0) {
      uVar22 = (uVar22 - 1 | 0xfffffffc) + 1;
    }
    if ((int)uVar22 < 2) {
      uVar6 = *(undefined2 *)(param_1 + 0x10);
      uVar28 = param_1[0xb];
      uVar33 = param_1[10];
      puVar10 = (undefined4 *)_malloc_base(0x48);
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar24 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar10[3] = uVar33;
      puVar10[4] = uVar28;
      *puVar10 = uVar27;
      puVar10[1] = 0x23;
      puVar10[2] = 8;
      *(undefined2 *)(puVar10 + 5) = uVar6;
      auVar3._8_4_ = SUB84(dVar30,0);
      auVar3._0_8_ = dVar30;
      auVar3._12_4_ = (int)((ulonglong)dVar30 >> 0x20);
      *(undefined1 (*) [16])(puVar10 + 6) = auVar3;
      puVar10[10] = 0xff;
      puVar10[0xb] = 0xff;
      puVar10[0xc] = 0xff;
      puVar10[0xd] = 0xff;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      if (bVar24) {
        DAT_140e46bf0 = puVar10;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
      iVar23 = param_1[5];
      DAT_140e46c88 = puVar10;
    }
  }
  if (param_1[0x15] == 0) {
    local_278 = DAT_14053b370;
    FUN_140079c10(param_1,1);
    iVar23 = param_1[5];
  }
  if ((int)param_1[7] < 1) {
    if (iVar23 < 1) {
      return;
    }
    FUN_14007b010(param_1,2000,8);
    FUN_140079e20(param_1,1);
    local_250 = DAT_140e44308;
    uStack_258 = CONCAT44(uStack_258._4_4_,1);
    local_260 = CONCAT44(local_260._4_4_,10);
    local_268 = dVar4;
    local_270 = CONCAT22(local_270._2_2_,0x4000);
    local_278 = (float)DAT_14053b380;
    stage_entity_spawn_candidate(0x153,param_1[8],1);
    iVar23 = DAT_140e44308;
    puVar10 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar10 != (undefined4 *)0x0; puVar10 = *(undefined4 **)(puVar10 + 0x18)) {
        if (puVar10[1] == iVar23) {
          puVar10[0x17] = puVar10[0x17] + -1;
        }
      }
    }
  }
  else {
    if (iVar23 < 1) {
      return;
    }
    if ((0 < iStack_1f4) && (0 < DAT_140e4430c)) {
      return;
    }
    FUN_140079e20(param_1,1);
  }
  param_1[0x15] = 1;
  param_1[3] = 0;
  param_1[5] = 0xffffffff;
  return;
}


