// Function: state_04_gameplay_update_candidate @ 1400d5d50
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_04_gameplay_update_candidate(void)

{
  float fVar1;
  FILE *pFVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  longlong lVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  int iVar18;
  ulonglong uVar19;
  longlong lVar20;
  undefined2 uVar21;
  ulonglong uVar22;
  int iVar23;
  undefined4 uVar24;
  int iVar25;
  bool bVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  double dVar37;
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  float fVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined1 auStack_308 [32];
  float local_2e8;
  double local_2e0;
  undefined1 local_2d8 [16];
  undefined4 local_2c8;
  undefined4 local_2c0;
  undefined4 local_2b8;
  int local_2b0;
  undefined4 local_2a8;
  undefined4 local_2a0;
  uint local_298;
  int local_294;
  float local_290;
  float local_28c;
  int local_288;
  int local_284;
  uint local_280;
  ulonglong local_278;
  longlong local_270;
  int local_268;
  double local_260;
  int local_258;
  double local_250;
  double local_248;
  int local_240;
  double local_238;
  FILE *local_230;
  ulonglong local_228;
  float local_218 [4];
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
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
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  FILE *local_d8;
  ulonglong local_d0;
  
  uVar10 = DAT_140e418c8;
  uVar6 = _UNK_14053bb28;
  dVar37 = _DAT_14053bb20;
  dVar33 = DAT_14053a020;
  dVar29 = DAT_140539d28;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_308;
  dVar28 = 0.0;
  iVar23 = 1;
  uVar46 = SUB84(DAT_14053a020,0);
  uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  local_198 = _DAT_14053b880;
  uStack_190 = _UNK_14053b888;
  local_178 = _DAT_14053b8c0;
  uStack_170 = _UNK_14053b8c8;
  local_158 = _DAT_14053b860;
  uStack_150 = _UNK_14053b868;
  local_138 = _DAT_14053b820;
  uStack_130 = _UNK_14053b828;
  local_108 = _DAT_14053b8f0;
  uStack_100 = _UNK_14053b8f8;
  local_218[0] = 0.0;
  local_218[1] = 0.0;
  local_218[2] = 0.0;
  local_218[3] = 0.0;
  local_1f8 = _DAT_14053c1e0;
  uStack_1f0 = _UNK_14053c1e8;
  local_188 = _DAT_14053b920;
  uStack_180 = _UNK_14053b928;
  local_1d8 = _DAT_14053bd50;
  uStack_1d0 = _UNK_14053bd58;
  local_168 = _DAT_14053b870;
  uStack_160 = _UNK_14053b878;
  local_1b8 = _DAT_14053c1f0;
  uStack_1b0 = _UNK_14053c1f8;
  local_128 = _DAT_14053b850;
  uStack_120 = _UNK_14053b858;
  local_f8 = _DAT_14053b910;
  uStack_f0 = _UNK_14053b918;
  local_208 = _DAT_14053c0b0;
  uStack_200 = _UNK_14053c0b8;
  local_1e8 = _DAT_14053c290;
  uStack_1e0 = _UNK_14053c298;
  local_e8 = 0x80;
  local_1a8 = 0x46185800;
  local_1a4 = 0xc4200000;
  local_294 = 0xff;
  local_280 = 1;
  local_238 = _DAT_14053bb20;
  local_250 = 0.0;
  local_260 = 0.0;
  local_248 = 0.0;
  local_230 = (FILE *)0x0;
  local_d8 = (FILE *)0x0;
  local_148 = _DAT_14053b900;
  uStack_140 = _UNK_14053b908;
  local_284 = DAT_140e41b68;
  local_118 = _DAT_14053b900;
  uStack_110 = _UNK_14053b908;
  local_1c8 = _DAT_14053b5d0;
  uStack_1c0 = _UNK_14053b5d8;
  dVar27 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a930 * DAT_14053a020
                                 * DAT_140539d28);
  iVar15 = DAT_1407c7798;
  dVar32 = DAT_14053a798;
  uVar16 = (ulonglong)DAT_1407c7798;
  local_240 = DAT_1407c7798;
  local_268 = DAT_140e419b8;
  local_288 = DAT_140e43eac;
  local_258 = 0;
  local_28c = (float)(dVar27 * DAT_14053a018) + 0.0;
  if (DAT_140e41928 == 1) {
    iVar23 = 0xb;
    local_280 = 0xb;
    local_284 = DAT_140e41b6c;
    if (0 < DAT_140e41b78) {
      iVar23 = 10;
      local_280 = 10;
      if (DAT_1407c7798 == 10) {
        local_258 = 1;
        local_268 = 2;
      }
    }
  }
  iVar9 = local_268;
  if (uVar10 == 1) {
    DAT_140e46950 = local_218[uVar16 * 2];
    DAT_140e46954 = local_218[uVar16 * 2 + 1];
    _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
LAB_1400d6026:
    local_238 = (double)FUN_140332d90();
    local_238 = local_238 + 0.0;
  }
  else if ((int)uVar10 < 0x1e) goto LAB_1400d6026;
  iVar14 = iVar15;
  if ((int)uVar10 < 0x3c) {
    FUN_1400d4310();
    uVar10 = DAT_140e418c8;
    iVar14 = DAT_1407c7798;
  }
  dVar27 = DAT_14053a558;
  if (DAT_140e46958 == 1) {
    if (uVar10 != 0x1e) {
      puVar11 = DAT_140e46c88;
      if (0x77 < (int)uVar10) {
        iVar14 = 0xc0;
        if (uVar10 - 0x78 < 0x5a) {
          dVar30 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a2d8) * DAT_14053a558 *
                                         dVar33 * dVar29);
          iVar14 = (int)(dVar30 * DAT_14053a578);
        }
        uVar43 = DAT_140e41ab8;
        iVar25 = 0;
        if ((int)uVar10 < 0xd2) {
          iVar25 = iVar14;
        }
        puVar11 = (undefined4 *)_malloc_base();
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46e8c = _DAT_140e46e8c + 1;
        bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar11 = uVar43;
        puVar11[1] = 0x7f;
        *(undefined8 *)(puVar11 + 2) = 5;
        puVar11[4] = 0;
        *(undefined2 *)(puVar11 + 5) = 0;
        *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
        puVar11[10] = 0xff;
        puVar11[0xb] = 0xff;
        puVar11[0xc] = 0xff;
        puVar11[0xd] = iVar25;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        if (bVar26) {
          DAT_140e46bf0 = puVar11;
        }
        uVar10 = DAT_140e418c8;
        iVar14 = DAT_1407c7798;
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
          uVar10 = DAT_140e418c8;
          iVar14 = DAT_1407c7798;
        }
      }
      DAT_140e46c88 = puVar11;
      if (uVar10 == 0xd2) {
        DAT_140e46958 = 0;
        DAT_140e46014 = 0;
      }
      goto LAB_1400d61d6;
    }
    iVar14 = iVar14 + 1;
    _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
    DAT_140e46014 = 1;
    fVar34 = DAT_140e46954;
    fVar36 = DAT_140e46950;
    DAT_1407c7798 = iVar14;
  }
  else {
LAB_1400d61d6:
    fVar34 = DAT_140e46a14;
    fVar36 = DAT_140e46a10;
  }
  uVar8 = DAT_140e46bb4;
  uVar10 = DAT_140e46014;
  dVar31 = DAT_14053ab78;
  dVar30 = DAT_140539ef8;
  if (DAT_140e45274 == 0) {
    if (DAT_140e46014 - 1 < 4) {
      dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar33 *
                                     dVar29);
      uVar43 = SUB84(DAT_140539f00,0);
      uVar45 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
      local_260 = dVar28 * DAT_140539f00 + 0.0;
    }
    else {
      uVar43 = SUB84(DAT_140539f00,0);
      uVar45 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
    }
    iVar25 = 0xff;
    if (uVar10 + 4 < 4) {
      dVar28 = (double)FUN_140332d90(((double)(int)-uVar10 - 0.0) * dVar31 * dVar33 * dVar29);
      local_248 = dVar28 * (double)CONCAT44(uVar45,uVar43) + 0.0;
      iVar25 = 0xff;
    }
  }
  else {
    iVar25 = 0xff;
    if (DAT_140e45274 == 1) {
      if (0 < (int)DAT_140e46bb4) {
        dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e46bb4 - 0.0) * DAT_14053ab78 * dVar33 *
                                       DAT_140539d28);
        dVar28 = dVar28 * dVar30 + 0.0;
        local_250 = dVar28;
      }
      local_260 = dVar28;
      if (0x7fffffff < uVar8) {
        dVar28 = (double)FUN_140332d90(((double)(int)-uVar8 - 0.0) * dVar31 * dVar33 * DAT_140539d28
                                      );
        local_250 = dVar28 * dVar30 + 0.0;
        local_248 = local_250;
      }
      uVar7 = DAT_140e46bb0;
      dVar29 = DAT_140539ed8;
      dVar28 = DAT_140539d28;
      if (0 < (int)uVar8) {
        dVar30 = (double)FUN_140332d90(((double)(int)DAT_140e46bb0 - 0.0) * dVar31 * dVar33 *
                                       DAT_140539d28);
        local_230 = (FILE *)(dVar30 * dVar29 + 0.0);
      }
      iVar25 = local_294;
      if (0x7fffffff < uVar8) {
        dVar28 = (double)FUN_140332d90(((double)(int)-uVar7 - 0.0) * dVar31 * dVar33 * dVar28);
        local_d8 = (FILE *)(dVar28 * dVar29 + 0.0);
        iVar25 = local_294;
      }
    }
  }
  dVar28 = DAT_140539d28;
  uVar43 = SUB84(DAT_140539d28,0);
  uVar45 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  if (0 < (int)uVar10) {
    dVar29 = (double)FUN_140332d90();
    fVar1 = local_218[(longlong)iVar14 * 2];
    dVar30 = (double)FUN_140332d90();
    DAT_140e46954 =
         (float)(dVar30 * (double)(local_218[(longlong)iVar14 * 2 + 1] - fVar34)) + fVar34;
    DAT_140e46950 = (float)(dVar29 * (double)(fVar1 - fVar36)) + fVar36;
  }
  if (0x7fffffff < uVar10) {
    dVar29 = (double)FUN_140332d90();
    fVar1 = local_218[(longlong)iVar14 * 2];
    dVar30 = (double)FUN_140332d90();
    DAT_140e46954 =
         (float)(dVar30 * (double)(local_218[(longlong)iVar14 * 2 + 1] - fVar34)) + fVar34;
    DAT_140e46950 = (float)(dVar29 * (double)(fVar1 - fVar36)) + fVar36;
  }
  uVar24 = DAT_140e467f0;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar24;
  *(undefined8 *)(puVar11 + 1) = 10;
  *(undefined8 *)(puVar11 + 3) = 0;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar24 = DAT_140e4601c;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar24;
  *(undefined8 *)(puVar11 + 1) = 0x65;
  *(undefined8 *)(puVar11 + 3) = 0;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  dVar29 = DAT_14053a698;
  DAT_140e46c88 = puVar11;
  dVar30 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a698 * dVar33 *
                                 dVar28);
  uVar24 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  fVar34 = (float)(dVar30 * DAT_14053a0f8) + DAT_14053ae7c;
  puVar11 = (undefined4 *)_malloc_base();
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46da8 = _DAT_140e46da8 + 1;
  uVar42 = 0;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[4] = fVar34;
  *puVar11 = uVar24;
  puVar11[1] = 0x46;
  puVar11[2] = 1;
  puVar11[3] = 0x43480000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  iVar14 = 0x80;
  puVar11[0xd] = 0x80;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar10 = DAT_140e46014;
  dVar30 = DAT_14053a4b8;
  uVar24 = DAT_14053afcc;
  if (iVar15 == 7) {
    uVar24 = DAT_14053afbc;
  }
  lVar20 = (longlong)DAT_140e445c0;
  lVar12 = lVar20 + uVar16 * 3;
  if ((0 < (int)(&DAT_140e41b94)[lVar12 * 0x32]) || (0 < (int)(&DAT_140e41ba8)[lVar12 * 0x32])) {
    uVar42 = 0xff;
  }
  if ((0 < (int)(&DAT_140e41b98)[lVar12 * 0x32]) || (0 < (int)(&DAT_140e41bac)[lVar12 * 0x32])) {
    uVar42 = 0xff;
  }
  if ((0 < *(int *)(&DAT_140e41b9c + lVar12 * 200)) ||
     (0 < *(int *)(&DAT_140e41bb0 + (lVar20 + uVar16 * 3) * 200))) {
    uVar42 = 0xff;
  }
  lVar12 = (lVar20 + uVar16 * 3) * 200;
  if ((0 < *(int *)(&DAT_140e41ba0 + lVar12)) || (0 < *(int *)(&DAT_140e41bb4 + lVar12))) {
    uVar42 = 0xff;
  }
  if ((0 < *(int *)(&DAT_140e41ba4 + lVar12)) || (0 < *(int *)(&DAT_140e41bb8 + lVar12))) {
    uVar42 = 0xff;
  }
  DAT_140e46c88 = puVar11;
  if ((int)DAT_140e46014 < 1) {
LAB_1400d6839:
    if ((int)uVar10 < 0) goto LAB_1400d683b;
  }
  else {
    iVar14 = ((int)DAT_140e46014 >> 0x1f & 0xffffff80U) + 0x80;
    if (-1 < (int)DAT_140e46014) {
      if ((int)DAT_140e46014 < 0x1e) {
        dVar31 = (double)FUN_140332d90(((double)(int)DAT_140e46014 - 0.0) * dVar32 * dVar33 * dVar28
                                      );
        iVar14 = (int)(dVar31 * dVar30);
      }
      goto LAB_1400d6839;
    }
LAB_1400d683b:
    iVar18 = -uVar10;
    iVar14 = (iVar18 >> 0x1f & 0xffffff80U) + 0x80;
    if ((-1 < iVar18) && (iVar18 < 0x1e)) {
      dVar32 = (double)FUN_140332d90(((double)iVar18 - 0.0) * dVar32 * dVar33 * dVar28);
      iVar14 = (int)(dVar32 * dVar30);
    }
  }
  iVar18 = DAT_140e46958;
  if (((DAT_140e46958 == 1) && (iVar14 = 0, 0x77 < (int)DAT_140e418c8)) &&
     (iVar14 = 0x80, (int)DAT_140e418c8 < 0xd2)) {
    dVar32 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a4a0) * dVar27 * dVar33 *
                                   dVar28);
    iVar14 = (int)(dVar32 * dVar30);
  }
  fVar34 = DAT_14053ae70;
  if (iVar15 < 10) {
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar29 * dVar33 * dVar28);
    uVar5 = *(undefined4 *)(uVar16 * 4 + 0x140e442b4);
LAB_1400d699a:
    local_2a0 = 0;
    local_2a8 = 1;
    local_2d8._8_8_ = uVar6;
    local_2d8._0_8_ = dVar37;
    local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
    local_2e8 = (float)(dVar28 * DAT_14053b0c0) + fVar34;
    local_2c8 = uVar42;
    local_2c0 = uVar42;
    local_2b8 = uVar42;
    local_2b0 = iVar14;
    FUN_1400c8410(uVar5,0x46,1,uVar24);
    iVar18 = DAT_140e46958;
  }
  else if (iVar15 == 10) {
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar29 * dVar33 * dVar28);
    uVar5 = DAT_140e442e4;
    goto LAB_1400d699a;
  }
  fVar1 = DAT_14053b2c8;
  dVar28 = DAT_14053ae68;
  fVar36 = DAT_14053ac48;
  uVar17 = (ulonglong)local_280;
  local_278 = uVar17;
  if ((longlong)uVar17 <= (longlong)local_284) {
    lVar12 = (longlong)iVar9;
    fVar34 = DAT_14053b32c;
    local_270 = lVar12;
    local_228 = uVar16;
    do {
      uVar10 = DAT_140e418c8;
      fVar38 = (local_218[uVar17 * 2] + DAT_14053aedc) - DAT_140e46950;
      local_290 = fVar38;
      local_278 = uVar17;
      dVar29 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)(iVar23 * 0x28)) *
                                     DAT_14053a698 * DAT_14053a020 * (double)CONCAT44(uVar45,uVar43)
                                    );
      uVar46 = DAT_140e46910;
      fVar44 = (float)(dVar29 * DAT_14053a0b0) + 0.0 +
               ((local_218[uVar17 * 2 + 1] + DAT_14053ae1c) - DAT_140e46954);
      if ((_DAT_14053b418 <= fVar38) && (fVar38 <= DAT_14053b028)) {
        if ((iVar18 == 1) && ((int)uVar10 < 0x78)) {
          if ((int)uVar10 < 0x1e) {
            if (iVar23 == DAT_1407c7798 + 1) {
              local_294 = 0;
              iVar25 = 0;
            }
          }
          else if (iVar23 == DAT_1407c7798) {
            local_294 = 0;
            iVar15 = 0;
            if ((int)DAT_140e418c8 < 0x3c) {
LAB_1400d6b37:
              iVar25 = local_294;
              if ((int)DAT_140e418c8 < 0x5a) goto LAB_1400d6b69;
            }
            else if ((int)DAT_140e418c8 < 0x5a) {
              uVar10 = DAT_140e418c8 & 0x80000003;
              if ((int)uVar10 < 0) {
                uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
              }
              local_294 = 0;
              if (uVar10 == 0) {
                iVar15 = 0xff;
                local_294 = 0xff;
              }
              goto LAB_1400d6b37;
            }
            iVar25 = iVar15;
            local_294 = iVar25;
            if (DAT_140e418c8 ==
                ((int)DAT_140e418c8 / 3 + ((int)DAT_140e418c8 >> 0x1f) +
                (int)((ulonglong)
                      ((longlong)(int)DAT_140e418c8 / 3 + ((longlong)(int)DAT_140e418c8 >> 0x3f)) >>
                     0x1f)) * 3) {
              iVar25 = 0xff;
              local_294 = iVar25;
            }
          }
        }
LAB_1400d6b69:
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(double *)(puVar11 + 6) = local_238;
        *(double *)(puVar11 + 8) = local_238;
        *puVar11 = uVar46;
        puVar11[3] = fVar38;
        puVar11[4] = fVar44;
        puVar11[1] = 0x4b;
        puVar11[2] = 1;
        *(undefined2 *)(puVar11 + 5) = 0;
        puVar11[10] = 0x80;
        puVar11[0xb] = 0x80;
        puVar11[0xc] = 0x80;
        puVar11[0xd] = iVar25;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        _DAT_140e46dbc = _DAT_140e46dbc + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar11;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
        }
        local_2a0 = 0;
        local_2a8 = 1;
        local_2b0 = (int)((double)iVar25 * DAT_140539f20);
        local_2b8 = *(undefined4 *)((longlong)&uStack_190 + uVar17 * 0xc);
        local_2c0 = *(undefined4 *)((longlong)&local_198 + uVar17 * 0xc + 4);
        local_2c8 = *(undefined4 *)((longlong)&local_198 + uVar17 * 0xc);
        local_2d8._8_8_ = local_238;
        local_2d8._0_8_ = local_238;
        local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
        DAT_140e46c88 = puVar11;
        local_2e8 = fVar44;
        FUN_1400c8410(DAT_140e46914,0x4b,6,fVar38);
        iVar18 = DAT_140e46958;
        if (DAT_140e46958 == 1) {
          if ((0x77 < (int)DAT_140e418c8) || (uVar17 != uVar16)) {
LAB_1400d6ca4:
            uVar22 = 0;
            local_298 = 0;
            uVar19 = uVar22;
LAB_1400d6cb4:
            do {
              uVar10 = (uint)uVar19;
              iVar15 = (uVar10 + 6) * 5;
              dVar29 = dVar37;
              if (iVar15 != iVar15 + 0xc) {
                if ((int)DAT_140e418c8 < iVar15) {
                  dVar29 = 0.0;
                }
                else if ((int)DAT_140e418c8 < iVar15 + 0xc) {
                  dVar29 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)iVar15) *
                                                 DAT_14053a998 * DAT_14053a020 * DAT_140539d28);
                  uVar22 = 0;
                  dVar29 = dVar29 + 0.0;
                }
              }
              fVar35 = local_290;
              uVar21 = (undefined2)uVar22;
              uVar46 = (undefined4)uVar22;
              switch(uVar10) {
              case 0:
                local_2e8 = fVar44 - DAT_14053ade0;
                local_2a8 = 1;
                local_2b0 = 0xff;
                local_2b8 = 0xff;
                local_2c0 = 0xff;
                local_2c8 = 0xff;
                local_2d8._8_8_ = dVar29;
                local_2d8._0_8_ = dVar37;
                local_2e0 = (double)CONCAT62(local_2e0._2_6_,uVar21);
                local_2a0 = uVar46;
                FUN_1400c8410((&DAT_140e46914)[uVar17],0x4b,1,fVar38);
                local_298 = uVar10 + 1;
                uVar19 = (ulonglong)local_298;
                uVar22 = 0;
                goto LAB_1400d6cb4;
              case 1:
                local_2e8 = fVar44 - DAT_14053acbc;
                local_2a8 = 1;
                local_2b0 = 0xff;
                local_2b8 = 0xff;
                local_2c0 = 0xff;
                local_2c8 = 0xff;
                local_2d8._8_8_ = dVar29;
                local_2d8._0_8_ = dVar37;
                local_2e0 = (double)CONCAT62(local_2e0._2_6_,uVar21);
                local_2a0 = uVar46;
                FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e46878 + uVar17 * 4 + 4),0x4b,1,
                              fVar38);
                local_298 = uVar10 + 1;
                uVar19 = (ulonglong)local_298;
                uVar22 = 0;
                goto LAB_1400d6cb4;
              case 2:
                if (iVar23 != 10) {
                  uVar22 = uVar22 & 0xffffffff;
                  iVar15 = local_288 + 1;
                  uVar17 = local_278;
                  lVar12 = local_270;
                  if (0 < iVar15) {
                    puVar11 = &DAT_140e47688;
                    fVar39 = fVar38 - DAT_14053ad5c;
                    fVar35 = fVar44 - DAT_14053ad80;
                    do {
                      iVar9 = (int)uVar22;
                      fVar34 = (float)iVar9 * DAT_14053aca8 + fVar39;
                      if ((iVar9 != 4) || (iVar14 = FUN_1401351a0(iVar23,uVar22), iVar14 != 0)) {
                        uVar46 = *puVar11;
                        puVar13 = (undefined4 *)_malloc_base(0x48);
                        if (puVar13 == (undefined4 *)0x0) {
                          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                        }
                        *puVar13 = uVar46;
                        puVar13[3] = fVar34;
                        puVar13[2] = 1;
                        *(undefined8 *)(puVar13 + 0xe) = 1;
                        puVar13[4] = fVar35;
                        *(double *)(puVar13 + 8) = dVar29;
                        puVar13[1] = 0x4f;
                        *(undefined2 *)(puVar13 + 5) = 0;
                        *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
                        *(undefined8 *)(puVar13 + 10) = 0;
                        puVar13[0xc] = 0;
                        puVar13[0xd] = 0x80;
                        *(undefined8 *)(puVar13 + 0x10) = 0;
                        _DAT_140e46dcc = _DAT_140e46dcc + 1;
                        if (DAT_140e46bf0 == (undefined4 *)0x0) {
                          DAT_140e46bf0 = puVar13;
                        }
                        if (DAT_140e46c88 != (undefined4 *)0x0) {
                          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
                        }
                        DAT_140e46c88 = puVar13;
                        iVar14 = FUN_1401351a0(iVar23,uVar22);
                        if (iVar14 == 2) {
                          local_2a0 = 0;
                          local_2a8 = 1;
                          local_2b0 = 0xff;
                          local_2b8 = 0xff;
                          local_2c0 = 0xff;
                          local_2c8 = 0xff;
                          local_2d8._8_8_ = dVar29;
                          local_2d8._0_8_ = dVar37;
                          local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                          local_2e8 = fVar35;
                          FUN_1400c8410(*puVar11,0x50,1,fVar34);
                        }
                        else if (iVar14 == 1) {
                          local_2a0 = 0;
                          local_2a8 = 1;
                          local_2b0 = 0xff;
                          local_2b8 = 0xff;
                          local_2c0 = 0xff;
                          local_2c8 = 0xff;
                          local_2d8._8_8_ = dVar29;
                          local_2d8._0_8_ = dVar37;
                          local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                          local_2e8 = fVar35;
                          FUN_1400c8410(DAT_140e4769c,0x50,1,fVar34);
                        }
                      }
                      uVar22 = (ulonglong)(iVar9 + 1U);
                      puVar11 = puVar11 + 1;
                      uVar17 = local_278;
                      lVar12 = local_270;
                      fVar38 = local_290;
                      fVar34 = DAT_14053b32c;
                      uVar10 = local_298;
                    } while ((int)(iVar9 + 1U) < iVar15);
                  }
                }
                local_298 = uVar10 + 1;
                uVar19 = (ulonglong)local_298;
                uVar22 = 0;
                goto LAB_1400d6cb4;
              case 3:
                fVar38 = fVar44 - DAT_14053ad1c;
                local_2a8 = 1;
                local_2b0 = 0xff;
                local_2b8 = 0xff;
                local_2c0 = 0xff;
                local_2c8 = 0xff;
                local_2d8._8_8_ = dVar29;
                local_2d8._0_8_ = dVar37;
                local_2e0 = (double)CONCAT62(local_2e0._2_6_,uVar21);
                local_2e8 = fVar38;
                local_2a0 = uVar46;
                FUN_1400c8410(DAT_140e47650,0x50,1,local_290 - DAT_14053acbc);
                lVar20 = uVar17 * 3 + (longlong)DAT_140e445c0;
                if (iVar23 == 0xe) {
                  local_2d8._0_8_ = dVar29;
                  local_2e0 = dVar37;
                  local_2e8 = fVar38;
                  FUN_1400c9c90(0,0x50,(&DAT_140e41c20)
                                       [(longlong)DAT_140e45268 + (lVar20 * 0x19 + lVar12) * 2],
                                fVar35 + DAT_14053ac58);
                  uVar22 = 0;
                  local_298 = uVar10 + 1;
                  uVar19 = (ulonglong)local_298;
                  fVar38 = local_290;
                }
                else {
                  fVar35 = fVar35 + DAT_14053ad70;
                  lVar12 = lVar20 * 0x19 + lVar12 * 2 + (longlong)DAT_140e45268;
                  uVar17 = (&DAT_140e41bd0)[lVar12];
                  uVar16 = 0;
                  iVar15 = 0;
                  do {
                    dVar33 = (double)FUN_1403316f0(lVar12,(double)iVar15);
                    uVar10 = local_298;
                    lVar12 = 0;
                    if ((dVar28 <= dVar33) && (dVar33 = dVar33 - dVar28, dVar33 < dVar28)) {
                      lVar12 = -0x8000000000000000;
                    }
                    iVar15 = iVar15 + 1;
                    lVar12 = (longlong)dVar33 + lVar12;
                    uVar16 = uVar16 + lVar12 * 9;
                  } while (iVar15 < 0xc);
                  uVar19 = uVar17;
                  if (uVar16 < uVar17) {
                    uVar19 = uVar16;
                  }
                  if (uVar17 < 10) {
                    local_2a0 = 0;
                    local_2a8 = 1;
                    local_2b0 = 0xff;
                    local_2b8 = 0xff;
                    local_2c0 = 0xff;
                    local_2c8 = 0xff;
                    local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                    local_2e8 = fVar38;
                    FUN_1400c8410((&DAT_140e41980)[uVar17],0x50,1,fVar35);
                  }
                  else {
                    iVar15 = 0;
                    if (uVar16 < uVar17) {
                      local_2a0 = 0;
                      local_2a8 = 1;
                      local_2b0 = 0xff;
                      local_2b8 = 0xff;
                      local_2c0 = 0xff;
                      local_2c8 = 0xff;
                      local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                      local_2e8 = fVar38;
                      FUN_1400c8410(DAT_140e419ac,0x50,1,fVar35 + fVar36);
                      iVar15 = 0;
                    }
                    while( true ) {
                      while( true ) {
                        uVar16 = uVar19 / 10;
                        uVar46 = (&DAT_140e41980)[(int)uVar19 + (int)uVar16 * -10];
                        puVar11 = (undefined4 *)_malloc_base(0x48);
                        if (puVar11 == (undefined4 *)0x0) {
                          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                        }
                        puVar11[3] = fVar35;
                        puVar11[10] = 0xff;
                        *(undefined2 *)(puVar11 + 5) = 0;
                        puVar11[2] = 1;
                        *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
                        puVar11[0xb] = 0xff;
                        puVar11[0xc] = 0xff;
                        puVar11[0xd] = 0xff;
                        *(undefined8 *)(puVar11 + 0xe) = 1;
                        *(undefined8 *)(puVar11 + 0x10) = 0;
                        puVar11[4] = fVar38;
                        *(double *)(puVar11 + 8) = dVar29;
                        *puVar11 = uVar46;
                        puVar11[1] = 0x50;
                        _DAT_140e46dd0 = _DAT_140e46dd0 + 1;
                        if (DAT_140e46bf0 == (undefined4 *)0x0) {
                          DAT_140e46bf0 = puVar11;
                        }
                        if (DAT_140e46c88 != (undefined4 *)0x0) {
                          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
                        }
                        fVar35 = fVar35 + fVar34;
                        DAT_140e46c88 = puVar11;
                        if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                                     (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) &
                                           0xffffffffU) >> 0x1f)) * -3 != 2) break;
                        if (uVar19 < 10) goto LAB_1400d73dd;
                        fVar35 = fVar35 + fVar1;
                        local_2a0 = 0;
                        local_2a8 = 1;
                        local_2b0 = 0xff;
                        local_2b8 = 0xff;
                        local_2c0 = 0xff;
                        local_2c8 = 0xff;
                        local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
                        local_2e8 = fVar38;
                        FUN_1400c8410(DAT_140e419a8,0x50,1,fVar35 + fVar36);
                        iVar15 = iVar15 + 1;
                        uVar19 = uVar16;
                      }
                      if (uVar19 < 10) break;
                      iVar15 = iVar15 + 1;
                      uVar19 = uVar16;
                    }
                  }
LAB_1400d73dd:
                  uVar22 = 0;
                  local_298 = uVar10 + 1;
                  uVar19 = (ulonglong)local_298;
                  uVar17 = local_278;
                  lVar12 = local_270;
                  fVar38 = local_290;
                }
                goto LAB_1400d6cb4;
              case 4:
                fVar38 = fVar44 - DAT_14053acbc;
                local_2a8 = 1;
                local_2b0 = 0xff;
                local_2b8 = 0xff;
                local_2c0 = 0xff;
                local_2c8 = 0xff;
                local_2d8._8_8_ = dVar29;
                local_2d8._0_8_ = dVar37;
                local_2e0 = (double)CONCAT62(local_2e0._2_6_,uVar21);
                local_2e8 = fVar38;
                local_2a0 = uVar46;
                FUN_1400c8410(DAT_140e47654,0x50,1,local_290 - DAT_14053acbc);
                fVar35 = fVar35 + DAT_14053ad70;
                puVar11 = &DAT_140e41b10;
                uVar17 = (ulonglong)
                         (int)(&DAT_140e41b80)
                              [(uVar17 * 3 + (longlong)DAT_140e445c0) * 0x32 + lVar12];
                uVar16 = 0;
                iVar15 = 0;
                do {
                  dVar33 = (double)FUN_1403316f0(puVar11,(double)iVar15);
                  lVar12 = 0;
                  if ((dVar28 <= dVar33) && (dVar33 = dVar33 - dVar28, dVar33 < dVar28)) {
                    lVar12 = -0x8000000000000000;
                  }
                  iVar15 = iVar15 + 1;
                  puVar11 = (undefined4 *)((longlong)dVar33 + lVar12);
                  uVar16 = uVar16 + (longlong)puVar11 * 9;
                } while (iVar15 < 4);
                uVar19 = uVar17;
                if (uVar16 < uVar17) {
                  uVar19 = uVar16;
                }
                if (uVar17 < 10) {
                  local_2a0 = 0;
                  local_2a8 = 1;
                  local_2b0 = 0xff;
                  local_2b8 = 0xff;
                  local_2c0 = 0xff;
                  local_2c8 = 0xff;
                  local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                  local_2e8 = fVar38;
                  FUN_1400c8410((&DAT_140e41980)[uVar17],0x50,1,fVar35);
                }
                else {
                  iVar15 = 0;
                  if (uVar16 < uVar17) {
                    local_2a0 = 0;
                    local_2a8 = 1;
                    local_2b0 = 0xff;
                    local_2b8 = 0xff;
                    local_2c0 = 0xff;
                    local_2c8 = 0xff;
                    local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                    local_2e8 = fVar38;
                    FUN_1400c8410(DAT_140e419ac,0x50,1,fVar35 + fVar36);
                    iVar15 = 0;
                  }
                  while( true ) {
                    while( true ) {
                      uVar16 = uVar19 / 10;
                      uVar46 = (&DAT_140e41980)[(int)uVar19 + (int)uVar16 * -10];
                      puVar11 = (undefined4 *)_malloc_base(0x48);
                      if (puVar11 == (undefined4 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      *puVar11 = uVar46;
                      puVar11[3] = fVar35;
                      puVar11[4] = fVar38;
                      puVar11[2] = 1;
                      *(undefined8 *)(puVar11 + 0xe) = 1;
                      *(double *)(puVar11 + 8) = dVar29;
                      puVar11[1] = 0x50;
                      *(undefined2 *)(puVar11 + 5) = 0;
                      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
                      puVar11[10] = 0xff;
                      puVar11[0xb] = 0xff;
                      puVar11[0xc] = 0xff;
                      puVar11[0xd] = 0xff;
                      *(undefined8 *)(puVar11 + 0x10) = 0;
                      _DAT_140e46dd0 = _DAT_140e46dd0 + 1;
                      if (DAT_140e46bf0 == (undefined4 *)0x0) {
                        DAT_140e46bf0 = puVar11;
                      }
                      if (DAT_140e46c88 != (undefined4 *)0x0) {
                        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
                      }
                      fVar35 = fVar35 + fVar34;
                      DAT_140e46c88 = puVar11;
                      if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                                   (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) &
                                         0xffffffffU) >> 0x1f)) * -3 != 2) break;
                      if (uVar19 < 10) goto LAB_1400d7743;
                      fVar35 = fVar35 + fVar1;
                      local_2a0 = 0;
                      local_2a8 = 1;
                      local_2b0 = 0xff;
                      local_2b8 = 0xff;
                      local_2c0 = 0xff;
                      local_2c8 = 0xff;
                      local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
                      local_2e8 = fVar38;
                      FUN_1400c8410(DAT_140e419a8,0x50,1,fVar35 + fVar36);
                      iVar15 = iVar15 + 1;
                      uVar19 = uVar16;
                    }
                    if (uVar19 < 10) break;
                    iVar15 = iVar15 + 1;
                    uVar19 = uVar16;
                  }
                }
LAB_1400d7743:
                uVar22 = 0;
                local_298 = local_298 + 1;
                uVar19 = (ulonglong)local_298;
                uVar17 = local_278;
                lVar12 = local_270;
                fVar38 = local_290;
                goto LAB_1400d6cb4;
              case 5:
                local_2a8 = 1;
                local_2b0 = 0xff;
                local_2b8 = 0xff;
                local_2c0 = 0xff;
                local_2c8 = 0xff;
                local_2d8._8_8_ = dVar29;
                local_2d8._0_8_ = dVar37;
                local_2e0 = (double)CONCAT62(local_2e0._2_6_,uVar21);
                local_2e8 = fVar44;
                local_2a0 = uVar46;
                FUN_1400c8410(DAT_140e47658,0x50,1,fVar38 - DAT_14053acbc);
                fVar35 = fVar38 + DAT_14053ad70;
                puVar11 = &DAT_140e41b10;
                uVar17 = (ulonglong)
                         (int)(&DAT_140e41b94)
                              [(uVar17 * 3 + (longlong)DAT_140e445c0) * 0x32 + lVar12];
                uVar16 = 0;
                iVar15 = 0;
                do {
                  dVar33 = (double)FUN_1403316f0(puVar11,(double)iVar15);
                  lVar12 = 0;
                  if ((dVar28 <= dVar33) && (dVar33 = dVar33 - dVar28, dVar33 < dVar28)) {
                    lVar12 = -0x8000000000000000;
                  }
                  iVar15 = iVar15 + 1;
                  puVar11 = (undefined4 *)((longlong)dVar33 + lVar12);
                  uVar16 = uVar16 + (longlong)puVar11 * 9;
                } while (iVar15 < 4);
                uVar19 = uVar17;
                if (uVar16 < uVar17) {
                  uVar19 = uVar16;
                }
                if (uVar17 < 10) {
                  local_2a0 = 0;
                  local_2a8 = 1;
                  local_2b0 = 0xff;
                  local_2b8 = 0xff;
                  local_2c0 = 0xff;
                  local_2c8 = 0xff;
                  local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                  local_2e8 = fVar44;
                  FUN_1400c8410((&DAT_140e41980)[uVar17],0x50,1,fVar35);
                }
                else {
                  iVar15 = 0;
                  if (uVar16 < uVar17) {
                    local_2a0 = 0;
                    local_2a8 = 1;
                    local_2b0 = 0xff;
                    local_2b8 = 0xff;
                    local_2c0 = 0xff;
                    local_2c8 = 0xff;
                    local_2e0 = (double)((ulonglong)local_2e0._2_6_ << 0x10);
                    local_2e8 = fVar44;
                    FUN_1400c8410(DAT_140e419ac,0x50,1,fVar35 + fVar36);
                    iVar15 = 0;
                  }
                  while( true ) {
                    while( true ) {
                      uVar16 = uVar19 / 10;
                      uVar46 = (&DAT_140e41980)[(int)uVar19 + (int)uVar16 * -10];
                      puVar11 = (undefined4 *)_malloc_base(0x48);
                      if (puVar11 == (undefined4 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      *puVar11 = uVar46;
                      puVar11[3] = fVar35;
                      puVar11[4] = fVar44;
                      puVar11[2] = 1;
                      *(undefined8 *)(puVar11 + 0xe) = 1;
                      *(double *)(puVar11 + 8) = dVar29;
                      puVar11[1] = 0x50;
                      *(undefined2 *)(puVar11 + 5) = 0;
                      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
                      puVar11[10] = 0xff;
                      puVar11[0xb] = 0xff;
                      puVar11[0xc] = 0xff;
                      puVar11[0xd] = 0xff;
                      *(undefined8 *)(puVar11 + 0x10) = 0;
                      _DAT_140e46dd0 = _DAT_140e46dd0 + 1;
                      if (DAT_140e46bf0 == (undefined4 *)0x0) {
                        DAT_140e46bf0 = puVar11;
                      }
                      if (DAT_140e46c88 != (undefined4 *)0x0) {
                        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
                      }
                      fVar35 = fVar35 + fVar34;
                      DAT_140e46c88 = puVar11;
                      if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                                   (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) &
                                         0xffffffffU) >> 0x1f)) * -3 != 2) break;
                      if (uVar19 < 10) goto LAB_1400d7aa6;
                      fVar35 = fVar35 + fVar1;
                      local_2a0 = 0;
                      local_2a8 = 1;
                      local_2b0 = 0xff;
                      local_2b8 = 0xff;
                      local_2c0 = 0xff;
                      local_2c8 = 0xff;
                      local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
                      local_2e8 = fVar44;
                      FUN_1400c8410(DAT_140e419a8,0x50,1,fVar35 + fVar36);
                      iVar15 = iVar15 + 1;
                      uVar19 = uVar16;
                    }
                    if (uVar19 < 10) break;
                    iVar15 = iVar15 + 1;
                    uVar19 = uVar16;
                  }
                }
LAB_1400d7aa6:
                uVar22 = 0;
                local_298 = local_298 + 1;
                uVar19 = (ulonglong)local_298;
                uVar17 = local_278;
                lVar12 = local_270;
                goto LAB_1400d6cb4;
              case 6:
                uVar8 = FUN_140135290(iVar23,DAT_140e445c0,local_268);
                if (0 < (int)uVar8) {
                  local_2a0 = (undefined4)uVar22;
                  fVar35 = fVar44 + DAT_14053acbc;
                  local_2a8 = 1;
                  local_2b0 = 0xff;
                  local_2b8 = 0xff;
                  local_2c0 = 0xff;
                  local_2c8 = 0xff;
                  local_2d8._8_8_ = dVar29;
                  local_2d8._0_8_ = dVar37;
                  local_2e0 = (double)CONCAT62(local_2e0._2_6_,(short)uVar22);
                  local_2e8 = fVar35;
                  FUN_1400c8410(DAT_140e4765c,0x50,1,fVar38 - DAT_14053ac2c);
                  iVar15 = 0x18;
                  uVar16 = (ulonglong)uVar8;
                  do {
                    uVar46 = DAT_140e46b50;
                    puVar11 = (undefined4 *)_malloc_base(0x48);
                    if (puVar11 == (undefined4 *)0x0) {
                      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                    }
                    uVar22 = 0;
                    *puVar11 = uVar46;
                    puVar11[1] = 0x50;
                    puVar11[2] = 1;
                    *(undefined2 *)(puVar11 + 5) = 0;
                    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
                    puVar11[4] = fVar35;
                    *(double *)(puVar11 + 8) = dVar29;
                    puVar11[10] = 0xff;
                    puVar11[0xb] = 0xff;
                    puVar11[0xc] = 0xff;
                    puVar11[0xd] = 0xff;
                    puVar11[3] = (float)iVar15 + fVar38;
                    *(undefined8 *)(puVar11 + 0xe) = 1;
                    *(undefined8 *)(puVar11 + 0x10) = 0;
                    _DAT_140e46dd0 = _DAT_140e46dd0 + 1;
                    if (DAT_140e46bf0 == (undefined4 *)0x0) {
                      DAT_140e46bf0 = puVar11;
                    }
                    if (DAT_140e46c88 != (undefined4 *)0x0) {
                      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
                    }
                    iVar15 = iVar15 + 0x18;
                    uVar16 = uVar16 - 1;
                    DAT_140e46c88 = puVar11;
                  } while (uVar16 != 0);
                  local_298 = local_298 + 1;
                  uVar19 = (ulonglong)local_298;
                  uVar17 = local_278;
                  lVar12 = local_270;
                  goto LAB_1400d6cb4;
                }
              }
              local_298 = uVar10 + 1;
              uVar19 = (ulonglong)local_298;
              uVar16 = local_228;
              iVar25 = local_294;
              iVar18 = DAT_140e46958;
            } while ((int)local_298 < 8);
          }
        }
        else if (DAT_140e46958 == 0) goto LAB_1400d6ca4;
      }
      uVar17 = uVar17 + 1;
      uVar43 = SUB84(DAT_140539d28,0);
      uVar45 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      iVar23 = iVar23 + 1;
    } while ((longlong)uVar17 <= (longlong)local_284);
    uVar46 = SUB84(DAT_14053a020,0);
    uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    fVar34 = DAT_14053ae70;
    iVar15 = local_240;
    local_278 = uVar17;
  }
  uVar24 = DAT_140e47660;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  iVar23 = local_258;
  _DAT_140e46dd0 = _DAT_140e46dd0 + 1;
  *puVar11 = uVar24;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[1] = 0x50;
  puVar11[2] = 1;
  puVar11[3] = 0x44138000;
  puVar11[4] = 0x43e60000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  uVar24 = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar5 = DAT_140e47680;
  uVar42 = DAT_140e4767c;
  DAT_140e46c88 = puVar11;
  if (local_258 == 0) {
    if ((int)(&DAT_140e43ea8)[iVar15] < DAT_140e419b8) {
      uVar24 = 0x80;
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      uVar40 = SUB84(local_250,0);
      uVar41 = (undefined4)((ulonglong)local_250 >> 0x20);
      _DAT_140e46de4 = _DAT_140e46de4 + 1;
      bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar11 = uVar5;
      puVar11[1] = 0x55;
      puVar11[2] = 1;
      puVar11[3] = 0x44200000;
      *(double *)(puVar11 + 6) = local_250 + dVar37;
      *(double *)(puVar11 + 8) = local_250 + dVar37;
      puVar11[4] = 0x44048000;
      *(undefined2 *)(puVar11 + 5) = 0xf000;
      puVar11[10] = 0xff;
      puVar11[0xb] = 0xff;
      puVar11[0xc] = 0xff;
      puVar11[0xd] = 0xff;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      if (bVar26) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
    }
    else {
      uVar40 = SUB84(local_250,0);
      uVar41 = (undefined4)((ulonglong)local_250 >> 0x20);
    }
    DAT_140e46c88 = puVar11;
    uVar42 = (&DAT_140e47650)[DAT_140e419b8 + 6];
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar11 = uVar42;
    puVar11[10] = uVar24;
    puVar11[0xb] = uVar24;
    puVar11[0xc] = uVar24;
  }
  else {
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    uVar40 = SUB84(local_250,0);
    uVar41 = (undefined4)((ulonglong)local_250 >> 0x20);
    *puVar11 = uVar42;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
  }
  _DAT_140e46de0 = _DAT_140e46de0 + 1;
  dVar28 = (double)CONCAT44(uVar41,uVar40) + dVar37;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  puVar11[0xd] = 0xff;
  uVar24 = SUB84(dVar28,0);
  uVar42 = (undefined4)((ulonglong)dVar28 >> 0x20);
  auVar3._8_4_ = uVar24;
  auVar3._0_8_ = dVar28;
  auVar3._12_4_ = uVar42;
  *(undefined1 (*) [16])(puVar11 + 6) = auVar3;
  *(undefined2 *)(puVar11 + 5) = 0;
  puVar11[4] = 0x44048000;
  puVar11[3] = 0x44200000;
  puVar11[2] = 1;
  puVar11[1] = 0x54;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  iVar9 = FUN_1401351a0(iVar15,local_268);
  uVar5 = DAT_140e47684;
  dVar29 = DAT_140539f28;
  if (iVar9 < 2) {
    puVar11 = DAT_140e46c88;
    if (DAT_140e45274 != 1) goto LAB_1400d8118;
    lVar12 = (longlong)DAT_140e419b8;
    fVar36 = local_28c;
    if (DAT_140e419b8 <= (int)(&DAT_140e43ea8)[iVar15]) {
      dVar33 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a698 *
                                     (double)CONCAT44(uVar47,uVar46) *
                                     (double)CONCAT44(uVar45,uVar43));
      local_2a0 = 0;
      local_2a8 = 1;
      local_2b0 = 0xff;
      local_2b8 = 0xff;
      local_2c0 = 0xff;
      local_2c8 = 0xff;
      local_2d8._8_4_ = uVar24;
      local_2d8._0_8_ = dVar28;
      local_2d8._12_4_ = uVar42;
      local_2e0 = (double)((ulonglong)local_2e0 & 0xffffffffffff0000);
      local_2e8 = (float)(dVar33 * DAT_14053a018) + 0.0 + fVar34;
      uVar24 = DAT_140e47474;
      if (iVar23 == 0) {
        uVar24 = *(undefined4 *)(&DAT_140e47460 + lVar12 * 4);
      }
      FUN_1400c8410(uVar24,0x55,1,DAT_14053af60);
      puVar11 = DAT_140e46c88;
      goto LAB_1400d8118;
    }
LAB_1400d82e7:
    iVar9 = local_288;
    uVar24 = DAT_140e41934;
    puVar11 = DAT_140e46c88;
    if (iVar23 == 0) {
      if (DAT_140e419b8 < local_288) {
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46de4 = _DAT_140e46de4 + 1;
        fVar34 = DAT_14053af38 - fVar36;
        bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar11 = uVar24;
        puVar11[1] = 0x55;
        puVar11[2] = 1;
        puVar11[3] = fVar34;
        puVar11[4] = 0x44048000;
        *(undefined2 *)(puVar11 + 5) = 0;
        puVar11[10] = 0xff;
        puVar11[0xb] = 0xff;
        puVar11[0xc] = 0xff;
        *(double *)(puVar11 + 6) = local_260 + dVar29;
        *(double *)(puVar11 + 8) = local_260 + dVar29;
        puVar11[0xd] = 0xff;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        if (bVar26) {
          DAT_140e46bf0 = puVar11;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
        }
      }
      DAT_140e46c88 = puVar11;
      uVar24 = DAT_140e41934;
      puVar11 = DAT_140e46c88;
      if (0 < DAT_140e419b8) {
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46de4 = _DAT_140e46de4 + 1;
        fVar34 = fVar36 + DAT_14053ae88;
        *(undefined2 *)(puVar11 + 5) = 0x8000;
        bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar11 = uVar24;
        puVar11[1] = 0x55;
        puVar11[3] = fVar34;
        puVar11[2] = 1;
        puVar11[4] = 0x44048000;
        puVar11[10] = 0xff;
        puVar11[0xb] = 0xff;
        puVar11[0xc] = 0xff;
        *(double *)(puVar11 + 6) = local_248 + dVar29;
        *(double *)(puVar11 + 8) = local_248 + dVar29;
        puVar11[0xd] = 0xff;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        if (bVar26) {
          DAT_140e46bf0 = puVar11;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
        }
      }
    }
  }
  else {
    if (DAT_140e419b8 == 3) {
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar11[3] = 0x44390000;
    }
    else {
      puVar11 = (undefined4 *)_malloc_base();
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar11[3] = 0x44318000;
    }
    _DAT_140e46de4 = _DAT_140e46de4 + 1;
    bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    puVar11[0xd] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[10] = 0xff;
    auVar4._8_4_ = uVar24;
    auVar4._0_8_ = dVar28;
    auVar4._12_4_ = uVar42;
    *(undefined1 (*) [16])(puVar11 + 6) = auVar4;
    *(undefined2 *)(puVar11 + 5) = 3000;
    puVar11[4] = 0x43fa0000;
    puVar11[2] = 1;
    puVar11[1] = 0x55;
    *puVar11 = uVar5;
    if (bVar26) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
LAB_1400d8118:
    DAT_140e46c88 = puVar11;
    uVar24 = DAT_140e41934;
    fVar36 = local_28c;
    puVar11 = DAT_140e46c88;
    if (DAT_140e45274 == 0) {
      iVar9 = local_288;
      if (DAT_140e46958 == 0) {
        if (iVar15 < local_284) {
          puVar11 = (undefined4 *)_malloc_base(0x48);
          if (puVar11 == (undefined4 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          _DAT_140e46de4 = _DAT_140e46de4 + 1;
          bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
          fVar34 = local_28c + _DAT_14053af74;
          *puVar11 = uVar24;
          puVar11[1] = 0x55;
          puVar11[2] = 1;
          puVar11[4] = 0x43a00000;
          puVar11[3] = fVar34;
          *(undefined2 *)(puVar11 + 5) = 0;
          puVar11[10] = 0xff;
          puVar11[0xb] = 0xff;
          puVar11[0xc] = 0xff;
          puVar11[0xd] = 0xff;
          *(double *)(puVar11 + 6) = local_260 + dVar37;
          *(double *)(puVar11 + 8) = local_260 + dVar37;
          *(undefined8 *)(puVar11 + 0xe) = 1;
          *(undefined8 *)(puVar11 + 0x10) = 0;
          if (bVar26) {
            DAT_140e46bf0 = puVar11;
          }
          if (DAT_140e46c88 != (undefined4 *)0x0) {
            *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
          }
        }
        DAT_140e46c88 = puVar11;
        fVar36 = local_28c;
        uVar24 = DAT_140e41934;
        puVar11 = DAT_140e46c88;
        if ((int)local_280 < iVar15) {
          puVar11 = (undefined4 *)_malloc_base(0x48);
          if (puVar11 == (undefined4 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          _DAT_140e46de4 = _DAT_140e46de4 + 1;
          fVar34 = DAT_14053ae48 - fVar36;
          bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
          *puVar11 = uVar24;
          puVar11[1] = 0x55;
          puVar11[2] = 1;
          puVar11[3] = fVar34;
          puVar11[4] = 0x43a00000;
          *(undefined2 *)(puVar11 + 5) = 0x8000;
          puVar11[10] = 0xff;
          puVar11[0xb] = 0xff;
          puVar11[0xc] = 0xff;
          *(double *)(puVar11 + 6) = local_248 + dVar37;
          *(double *)(puVar11 + 8) = local_248 + dVar37;
          puVar11[0xd] = 0xff;
          *(undefined8 *)(puVar11 + 0xe) = 1;
          *(undefined8 *)(puVar11 + 0x10) = 0;
          if (bVar26) {
            DAT_140e46bf0 = puVar11;
          }
          if (DAT_140e46c88 != (undefined4 *)0x0) {
            *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
          }
        }
        goto LAB_1400d82cc;
      }
    }
    else {
LAB_1400d82cc:
      DAT_140e46c88 = puVar11;
      iVar9 = local_288;
      puVar11 = DAT_140e46c88;
      if (DAT_140e45274 == 1) goto LAB_1400d82e7;
    }
  }
  DAT_140e46c88 = puVar11;
  uVar24 = DAT_140e47664;
  puVar11 = DAT_140e46c88;
  if (DAT_140e41b74 == 1) {
    if (DAT_140e45268 == 0) {
      puVar11 = (undefined4 *)_malloc_base();
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46de4 = _DAT_140e46de4 + 1;
      bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar11 = uVar24;
      puVar11[1] = 0x55;
      puVar11[2] = 1;
      puVar11[3] = 0x44200000;
      puVar11[4] = 0x44110000;
      *(undefined2 *)(puVar11 + 5) = 0;
      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
      puVar11[10] = 0xff;
      puVar11[0xb] = 0xff;
      puVar11[0xc] = 0xff;
      puVar11[0xd] = 0x80;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      if (bVar26) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
      uVar24 = DAT_140e41934;
      if (DAT_140e45274 == 1) {
        DAT_140e46c88 = puVar11;
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        fVar36 = fVar36 + DAT_14053aeb8;
        *(undefined2 *)(puVar11 + 5) = 0xc000;
        puVar11[4] = fVar36;
        pFVar2 = local_230;
LAB_1400d86b2:
        dVar28 = (double)pFVar2 + DAT_140539f00;
        _DAT_140e46dd8 = _DAT_140e46dd8 + 1;
        bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(double *)(puVar11 + 6) = dVar28;
        *(double *)(puVar11 + 8) = dVar28;
        puVar11[0xd] = 0xff;
        puVar11[0xc] = 0xff;
        puVar11[0xb] = 0xff;
        puVar11[10] = 0xff;
        puVar11[3] = 0x44368000;
        puVar11[2] = 1;
        puVar11[1] = 0x52;
        *puVar11 = uVar24;
        if (bVar26) {
          DAT_140e46bf0 = puVar11;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
        }
      }
    }
    else {
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46de4 = _DAT_140e46de4 + 1;
      bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar11 = uVar24;
      puVar11[1] = 0x55;
      puVar11[2] = 1;
      puVar11[3] = 0x44200000;
      puVar11[4] = 0x44110000;
      *(undefined2 *)(puVar11 + 5) = 0;
      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
      puVar11[10] = 0xff;
      puVar11[0xb] = 0xff;
      puVar11[0xc] = 0xff;
      puVar11[0xd] = 0xff;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      if (bVar26) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
      uVar24 = DAT_140e41934;
      if (DAT_140e45274 == 1) {
        DAT_140e46c88 = puVar11;
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        fVar36 = DAT_14053aeb8 - fVar36;
        *(undefined2 *)(puVar11 + 5) = 0x4000;
        puVar11[4] = fVar36;
        pFVar2 = local_d8;
        goto LAB_1400d86b2;
      }
    }
  }
  DAT_140e46c88 = puVar11;
  FUN_1400c48f0(0x50);
  FUN_1400d9b60(1,0x70,0xff);
  if (DAT_140e45274 == 0) {
    if (0x7fffffff < DAT_140e45fac) {
      dVar28 = (double)FUN_140332d90(((double)(int)-DAT_140e45fac - 0.0) * DAT_14053a9d8 *
                                     (double)CONCAT44(uVar47,uVar46) *
                                     (double)CONCAT44(uVar45,uVar43));
      dVar29 = dVar28 * _DAT_14053b068 + dVar37;
    }
LAB_1400d87a5:
    dVar37 = dVar29;
    uVar24 = 0xc0;
  }
  else if (DAT_140e45274 == 1) {
    uVar10 = DAT_140e418c8 & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    uVar24 = 0xc0;
    if (1 < (int)uVar10) {
      uVar24 = 0xff;
    }
    if ((int)(&DAT_140e43ea8)[iVar15] < DAT_140e419b8) {
      uVar24 = 0xc0;
    }
    if (0 < (int)DAT_140e45fac) {
      dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * DAT_14053a9d8 *
                                     (double)CONCAT44(uVar47,uVar46) *
                                     (double)CONCAT44(uVar45,uVar43));
      dVar37 = dVar28 * DAT_140539ec8 + dVar29;
    }
  }
  else {
    if ((DAT_140e45274 != 2) || ((int)(&DAT_140e43ea8)[iVar15] < DAT_140e419b8)) goto LAB_1400d87a5;
    uVar24 = 0xff;
    if ((int)DAT_140e45fac < 0x11) {
      dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * DAT_14053aa28 *
                                     (double)CONCAT44(uVar47,uVar46) *
                                     (double)CONCAT44(uVar45,uVar43));
      dVar37 = dVar28 * DAT_140539ec8 + dVar37;
      uVar24 = 0xff;
    }
  }
  uVar46 = DAT_140e46a98;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  *puVar11 = uVar46;
  bVar26 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[10] = uVar24;
  puVar11[0xb] = uVar24;
  puVar11[0xc] = uVar24;
  puVar11[1] = 0x6e;
  puVar11[2] = 1;
  puVar11[3] = 0x44200000;
  puVar11[4] = 0x44250000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(double *)(puVar11 + 6) = dVar37;
  *(double *)(puVar11 + 8) = dVar37;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar26) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  FUN_1400d3a60();
  if (((0x3b < (int)DAT_140e418c8) && (DAT_140e45fac == 0)) && (DAT_140e46958 == 0)) {
    bVar26 = false;
    if (DAT_140e8cf18 == 1) {
LAB_1400d889f:
      bVar26 = true;
    }
    else if (0x13 < DAT_140e8cf18) {
      uVar10 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
      }
      if (uVar10 == 0) goto LAB_1400d889f;
    }
    if ((DAT_140e8cf1c < 1) && (bVar26)) {
      if (DAT_140e45274 == 0) {
        if (local_284 <= DAT_1407c7798) goto LAB_1400d898a;
        DAT_1407c7798 = DAT_1407c7798 + 1;
        _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
        DAT_140e46014 = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
        DAT_140e467fc = 1;
      }
      if (((DAT_140e45274 == 1) && (DAT_140e419b8 < iVar9)) && (iVar23 == 0)) {
        DAT_140e419b8 = DAT_140e419b8 + 1;
        DAT_140e46bb4 = 4;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
        DAT_140e467fc = 1;
      }
    }
LAB_1400d898a:
    bVar26 = false;
    if (DAT_140e8cf1c == 1) {
LAB_1400d89ab:
      bVar26 = true;
    }
    else if (0x13 < DAT_140e8cf1c) {
      uVar10 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
      }
      if (uVar10 == 0) goto LAB_1400d89ab;
    }
    if ((DAT_140e8cf18 < 1) && (bVar26)) {
      if (DAT_140e45274 == 0) {
        if ((int)local_280 < DAT_1407c7798) {
          DAT_1407c7798 = DAT_1407c7798 + -1;
          _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
          DAT_140e46014 = 0xffffffff;
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          FUN_14018a340(DAT_140e47200,1,1);
          DAT_140e467fc = 1;
          goto LAB_1400d8a2e;
        }
      }
      else {
LAB_1400d8a2e:
        if (DAT_140e45274 == 1) {
          if ((0 < DAT_140e419b8) && (iVar23 == 0)) {
            DAT_140e419b8 = DAT_140e419b8 + -1;
            DAT_140e46bb4 = 0xfffffffc;
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
            FUN_14018a340(DAT_140e47200,1,1);
            DAT_140e467fc = 1;
            goto LAB_1400d8a81;
          }
          goto LAB_1400d8a8d;
        }
      }
    }
    else {
LAB_1400d8a81:
      if (DAT_140e45274 == 1) {
LAB_1400d8a8d:
        if (DAT_140e41b74 == 1) {
          if (((DAT_140e467b8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45268 == 0)) {
            DAT_140e45268 = 1;
            DAT_140e46bb0 = 4;
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
            FUN_14018a340(DAT_140e47200,1,1);
            DAT_140e467fc = 1;
          }
          if (((DAT_140e467bc == 1) && (DAT_140e467fc == 0)) && (DAT_140e45268 == 1)) {
            DAT_140e45268 = 0;
            DAT_140e46bb0 = 4;
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
            FUN_14018a340(DAT_140e47200,1,1);
            DAT_140e467fc = 1;
          }
        }
      }
    }
    if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e46014 == 0)) {
      if (((DAT_140e45274 == 0) || (DAT_140e419b8 <= (int)(&DAT_140e43ea8)[iVar15])) ||
         (iVar23 == 1)) {
        DAT_140e45274 = DAT_140e45274 + 1;
        DAT_140e45fac = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        uVar46 = DAT_140e47204;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar46 = DAT_140e4720c;
      }
      FUN_14018a340(uVar46,1,1);
      DAT_140e467fc = 1;
    }
    if (((int)DAT_140e467cc == 1) && (DAT_140e46014 == 0)) {
      DAT_140e45274 = DAT_140e45274 + -1;
      DAT_140e45fac = 0xffffffff;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
      FUN_14018a340(DAT_140e47208,1,1);
    }
    if ((DAT_140e467e4 != 1) &&
       (DAT_140e467e0 != 1 &&
        (DAT_140e467dc != 1 &&
        (DAT_140e467d8 != 1 &&
        (DAT_140e467d4 != 1 &&
        (DAT_140e467cc._4_4_ != 1 &&
        ((int)DAT_140e467cc != 1 &&
        (DAT_140e467c8 != 1 &&
        (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))
        )))))) {
      DAT_140e467fc = 0;
    }
  }
  if (((0 < (int)DAT_140e46014) && (DAT_140e46014 = DAT_140e46014 + 1, DAT_140e46014 == 0x1e)) ||
     ((0x7fffffff < DAT_140e46014 &&
      (DAT_140e46014 = DAT_140e46014 - 1, DAT_140e46014 == 0xffffffe2)))) {
    DAT_140e46014 = 0;
  }
  if (0 < (int)DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 - 1;
  }
  if (0x7fffffff < DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 + 1;
  }
  if (0 < (int)DAT_140e46bb0) {
    DAT_140e46bb0 = DAT_140e46bb0 - 1;
  }
  if (0x7fffffff < DAT_140e46bb0) {
    DAT_140e46bb0 = DAT_140e46bb0 + 1;
  }
  if (DAT_140e45274 == 2) {
    if (DAT_140e45fac == 1) {
      if (DAT_140e41928 == 0) {
        DAT_140e41b58 = DAT_1407c7798;
      }
      else if (DAT_140e41928 == 1) {
        DAT_140e41b5c = DAT_1407c7798;
        DAT_140e41abc = DAT_1407c7798 + -0xb;
      }
      if (iVar23 == 0) {
        DAT_140e41b60 = DAT_140e419b8;
      }
      puVar11 = &DAT_140e45100;
      DAT_140e41b64 = DAT_140e45268;
      do {
        FUN_14018f230(*puVar11,0);
        puVar11 = puVar11 + 1;
      } while ((longlong)puVar11 < 0x140e45178);
      fopen_s(&local_d8,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
      FUN_140323e90(local_d8);
      DAT_140e471fc = 0xb4;
    }
    if (0x3b < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x3c);
    }
    if (DAT_140e45fac == 100) {
      FUN_1400f7150();
      DAT_140e418c8 = DAT_140e418c8 - 1;
    }
  }
  else if (DAT_140e45fac == 10) {
    DAT_140e45fac = 0;
  }
  if (DAT_140e45274 == -1) {
    if ((int)DAT_140e45fac < -9) {
      FUN_1400d3fd0(-10 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffce) {
      if (DAT_140e41928 == 0) {
        DAT_140e41b58 = DAT_1407c7798;
      }
      else if (DAT_140e41928 == 1) {
        DAT_140e41b5c = DAT_1407c7798;
        DAT_140e41abc = 0;
      }
      if (iVar23 == 0) {
        DAT_140e41b60 = DAT_140e419b8;
      }
      DAT_140e41b64 = DAT_140e45268;
      DAT_140e45274 = 0;
      DAT_140e46064 = 0;
      DAT_140e418c8 = 0;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      fopen_s(&local_d8,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
      FUN_140323e90(local_d8);
      DAT_140e471fc = 0xb4;
      DAT_140e45270 = 3;
    }
  }
  else if (DAT_140e45fac == 0xfffffff6) {
    DAT_140e45fac = 0;
    goto LAB_1400d905f;
  }
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
LAB_1400d905f:
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


