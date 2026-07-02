// Function: FUN_1400d4610 @ 1400d4610
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d4610(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  float *pfVar10;
  uint uVar11;
  undefined4 *puVar12;
  longlong lVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined4 uVar23;
  double dVar24;
  float fVar25;
  undefined4 uVar26;
  undefined1 auStack_268 [32];
  float local_248;
  uint local_240;
  undefined1 local_238 [12];
  undefined4 uStack_22c;
  undefined4 local_228;
  undefined4 local_220;
  undefined4 local_218;
  undefined4 local_210;
  undefined4 local_208;
  undefined4 local_200;
  int local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float *local_1e8;
  double local_1e0;
  double local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
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
  undefined8 local_e8;
  undefined8 uStack_e0;
  FILE *local_d8;
  ulonglong local_d0;
  
  uVar14 = DAT_140e418c8;
  dVar6 = DAT_14053a020;
  dVar24 = DAT_140539d28;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_268;
  local_1e0 = 0.0;
  local_1d8 = 0.0;
  dVar20 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a930 * DAT_14053a020
                                 * DAT_140539d28);
  dVar21 = DAT_14053a0f8;
  local_1f4 = (float)(dVar20 * DAT_14053a0f8) + 0.0;
  dVar20 = (double)FUN_140332d90();
  local_1ec = (float)(dVar20 * dVar21) + DAT_14053ae7c;
  dVar20 = (double)FUN_140332d90();
  local_1f8 = 1;
  if (DAT_140e45274 == 4) {
    local_1f8 = 3;
  }
  local_1c0 = _DAT_14053bd90;
  uStack_1b8 = _UNK_14053bd98;
  local_1f0 = (float)(dVar20 * dVar21) + DAT_14053aec0;
  local_1d0 = _DAT_14053bcd0;
  uStack_1c8 = _UNK_14053bcd8;
  local_1b0 = _DAT_14053be70;
  uStack_1a8 = _UNK_14053be78;
  if ((int)uVar14 < 0x3c) {
    FUN_1400d4310(uVar14);
    uVar14 = DAT_140e418c8;
  }
  uVar11 = DAT_140e46014;
  dVar21 = 0.0;
  if ((int)uVar14 < 0x40) {
LAB_1400d48b2:
    dVar20 = 0.0;
  }
  else {
    if ((int)DAT_140e46014 < 1) {
      dVar21 = 0.0;
      if (0x7fffffff < DAT_140e46014) {
        dVar21 = (double)FUN_140332d90();
        dVar21 = dVar21 * DAT_140539e60 + 0.0;
        dVar20 = (double)FUN_140332d90();
        DAT_140e46014 = uVar11 + 1;
        local_1d8 = dVar20 * DAT_140539f00 + 0.0;
      }
      goto LAB_1400d48b2;
    }
    dVar21 = (double)FUN_140332d90();
    dVar21 = dVar21 * DAT_140539e60 + 0.0;
    dVar20 = (double)FUN_140332d90();
    DAT_140e46014 = uVar11 - 1;
    dVar20 = dVar20 * DAT_140539f00 + 0.0;
    local_1e0 = dVar20;
  }
  uVar23 = DAT_140e467f0;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  iVar16 = 0;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar23;
  *(undefined8 *)(puVar12 + 1) = 10;
  *(undefined8 *)(puVar12 + 3) = 0;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar12;
  }
  uVar23 = DAT_140e46018;
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar23;
  *(undefined8 *)(puVar12 + 1) = 0x65;
  *(undefined8 *)(puVar12 + 3) = 0;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  dVar7 = DAT_14053aa28;
  dVar5 = DAT_140539f40;
  dVar4 = DAT_140539ec8;
  local_1e8 = (float *)&local_1d0;
  uVar23 = (undefined4)DAT_140539f68;
  uVar26 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
  local_d8 = (FILE *)&DAT_140e445c4;
  DAT_140e46c88 = puVar12;
  do {
    uVar11 = DAT_140e46bb4;
    uVar14 = DAT_140e45fac;
    iVar15 = DAT_140e45274;
    iVar18 = *(int *)&local_d8->_ptr + (iVar16 + DAT_140e445c0 * 3) * 2;
    if (iVar16 == 3) {
      iVar18 = *(int *)&local_d8->_ptr + 0x12;
    }
    else if (iVar16 == 4) {
      iVar18 = 0x1d;
      if (DAT_140e41b70 == 0) {
        iVar18 = 0x17;
      }
    }
    else if (iVar16 == 5) {
      iVar18 = 0x16;
    }
    uVar17 = 0xff;
    if (DAT_140e45274 <= iVar16) {
      uVar17 = 0x80;
    }
    iVar1 = DAT_140e45274 + -1;
    dVar22 = dVar5;
    if (((int)DAT_140e45fac < 1) && (DAT_140e46bb4 != 0)) {
      if ((int)DAT_140e46bb4 < 1) {
        if (iVar16 == iVar1) {
          dVar22 = (double)FUN_140332d90(((double)(int)-DAT_140e46bb4 - 0.0) * dVar7 * dVar6 *
                                         dVar24);
          dVar22 = dVar22 * dVar4 + dVar5;
        }
        if (iVar16 == DAT_140e46064 + -1) {
          uVar3 = -uVar11;
          goto LAB_1400d4b84;
        }
      }
      else {
        if (iVar16 == iVar1) {
          dVar22 = (double)FUN_140332d90(((double)(int)DAT_140e46bb4 - 0.0) * dVar7 * dVar6 * dVar24
                                        );
          dVar22 = dVar22 * dVar4 + dVar5;
        }
        uVar3 = uVar11;
        if (iVar16 == DAT_140e46064 + -1) {
LAB_1400d4b84:
          dVar22 = (double)FUN_140332d90(((double)(int)uVar3 - DAT_14053b0c8) * dVar7 * dVar6 *
                                         dVar24);
          dVar22 = dVar22 * dVar4 + dVar5;
        }
      }
    }
    if (iVar16 == iVar1) {
      if (uVar11 == 0) {
        dVar22 = (double)CONCAT44(uVar26,uVar23);
      }
      dVar22 = dVar22 + dVar21;
      puVar12 = DAT_140e46c88;
      if (iVar15 != 6) {
        if (0 < iVar15) {
          if (5 < iVar15) goto LAB_1400d4e38;
          local_238._0_8_ = dVar20 + dVar5;
          local_200 = 0;
          fVar25 = *local_1e8;
          fVar2 = local_1e8[1];
          local_208 = 1;
          local_210 = 0xff;
          local_218 = 0xff;
          local_220 = 0xff;
          local_228 = 0xff;
          local_240 = local_240 & 0xffff0000;
          local_248 = fVar2;
          unique0x10001e77 = (double)local_238._0_8_;
          FUN_1400c8410(DAT_140e41934,0x70,1,fVar25 + DAT_14053ad9c + local_1f4);
          local_200 = 0;
          local_208 = 1;
          local_210 = 0xff;
          local_218 = 0xff;
          local_220 = 0xff;
          local_228 = 0xff;
          stack0xfffffffffffffdd0 = local_1d8 + dVar5;
          local_238._0_8_ = local_1d8 + dVar5;
          local_240 = CONCAT22(local_240._2_2_,0x8000);
          local_248 = fVar2;
          FUN_1400c8410(DAT_140e41934,0x70,1,(fVar25 - DAT_14053ad9c) - local_1f4);
          uVar23 = (undefined4)DAT_140539f68;
          uVar26 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
          iVar15 = DAT_140e45274;
        }
        goto LAB_1400d4d56;
      }
      uVar11 = DAT_140e418c8 & 0x80000003;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
      }
      if ((int)uVar11 < 2) {
        if (uVar14 == 0) {
          uVar17 = 0xc0;
        }
        else {
LAB_1400d4bfa:
          if ((int)uVar14 < 0x11) {
            dVar20 = (double)FUN_140332d90(((double)(int)uVar14 - 0.0) * dVar7 * dVar6 * dVar24);
            dVar22 = dVar20 * dVar4 + (double)CONCAT44(uVar26,uVar23);
            puVar12 = DAT_140e46c88;
          }
        }
      }
      else if (uVar14 != 0) goto LAB_1400d4bfa;
    }
    else {
LAB_1400d4d56:
      uVar8 = DAT_140e41934;
      puVar12 = DAT_140e46c88;
      if (iVar15 < 6) {
        fVar25 = (local_1f4 * _DAT_140539d30 + DAT_14053aee0) - DAT_14053acb0;
        puVar12 = (undefined4 *)_malloc_base(0x48);
        if (puVar12 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar12 = uVar8;
        *(undefined8 *)(puVar12 + 6) = 0x3fe3333333333333;
        *(undefined8 *)(puVar12 + 8) = 0x3fe3333333333333;
        puVar12[4] = fVar25;
        puVar12[1] = 0x70;
        puVar12[2] = 1;
        puVar12[3] = 0x44898000;
        *(undefined2 *)(puVar12 + 5) = 0x4000;
        puVar12[10] = 0xff;
        puVar12[0xb] = 0xff;
        puVar12[0xc] = 0xff;
        puVar12[0xd] = 0xff;
        *(undefined8 *)(puVar12 + 0xe) = 1;
        *(undefined8 *)(puVar12 + 0x10) = 0;
        _DAT_140e46e50 = _DAT_140e46e50 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar12;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
        }
      }
    }
LAB_1400d4e38:
    DAT_140e46c88 = puVar12;
    pfVar10 = local_1e8;
    local_200 = 0;
    local_208 = 1;
    local_248 = local_1e8[1];
    local_210 = 0xff;
    local_238._8_4_ = SUB84(dVar22,0);
    local_238._0_8_ = dVar22;
    uStack_22c = (int)((ulonglong)dVar22 >> 0x20);
    local_240 = local_240 & 0xffff0000;
    local_228 = uVar17;
    local_220 = uVar17;
    local_218 = uVar17;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e46a40 + (longlong)iVar18 * 4),(iVar16 == iVar1) + 'n',1,
                  *local_1e8);
    local_1e8 = pfVar10 + 2;
    iVar16 = iVar16 + 1;
    local_d8 = (FILE *)((longlong)&local_d8->_ptr + 4);
    dVar20 = local_1e0;
  } while (iVar16 < 6);
  local_198 = _DAT_14053b480;
  uStack_190 = _UNK_14053b488;
  local_188 = _DAT_14053b4a0;
  uStack_180 = _UNK_14053b4a8;
  iVar15 = DAT_140e445c0 * 10;
  local_178 = _DAT_14053b490;
  uStack_170 = _UNK_14053b498;
  local_168 = _DAT_14053b6c0;
  uStack_160 = _UNK_14053b6c8;
  local_158 = _DAT_14053b710;
  uStack_150 = _UNK_14053b718;
  local_148 = _DAT_14053b720;
  uStack_140 = _UNK_14053b728;
  local_138 = _DAT_14053b730;
  uStack_130 = _UNK_14053b738;
  local_128 = _DAT_14053b760;
  uStack_120 = _UNK_14053b768;
  local_118 = _DAT_14053b7a0;
  uStack_110 = _UNK_14053b7a8;
  local_108 = _DAT_14053b7b0;
  uStack_100 = _UNK_14053b7b8;
  local_f8 = _DAT_14053b790;
  uStack_f0 = _UNK_14053b798;
  local_e8 = _DAT_14053b7d0;
  uStack_e0 = _UNK_14053b7d8;
  iVar16 = iVar15;
  if (DAT_140e45274 == 0) {
    dVar24 = dVar21 + dVar5;
  }
  else {
    uVar14 = DAT_140e45274 - 1;
    if (uVar14 < 4) {
      iVar16 = *(int *)((longlong)&local_198 +
                       ((longlong)(int)(&DAT_140e445c4)[(int)uVar14] +
                       ((longlong)(int)uVar14 + (longlong)DAT_140e445c0 * 4) * 4) * 4);
    }
    dVar24 = dVar5;
    if (DAT_140e45274 == 5) {
      iVar16 = iVar15;
    }
  }
  uVar23 = *(undefined4 *)(&DAT_140e44240 + (longlong)iVar16 * 4);
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  fVar25 = local_1ec;
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar12[4] = local_1ec;
  *puVar12 = uVar23;
  puVar12[1] = 100;
  puVar12[2] = 1;
  puVar12[3] = 0x43960000;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(double *)(puVar12 + 6) = dVar24;
  *(double *)(puVar12 + 8) = dVar24;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar23 = *(undefined4 *)(&DAT_140e44240 + (longlong)iVar16 * 4);
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  fVar25 = fVar25 + DAT_14053ac44;
  _DAT_140e46e1c = _DAT_140e46e1c + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar23;
  puVar12[1] = 99;
  puVar12[4] = fVar25;
  puVar12[2] = 1;
  puVar12[3] = 0x43a00000;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(double *)(puVar12 + 6) = dVar24;
  *(double *)(puVar12 + 8) = dVar24;
  *(undefined8 *)(puVar12 + 10) = 0;
  puVar12[0xc] = 0;
  puVar12[0xd] = 0x20;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar23 = *(undefined4 *)(&DAT_140e46a40 + (longlong)(DAT_140e445c0 + 0x18) * 4);
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  fVar25 = local_1f4;
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar12[4] = local_1f0;
  *puVar12 = uVar23;
  puVar12[1] = 100;
  puVar12[2] = 1;
  puVar12[3] = 0x43200000;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(double *)(puVar12 + 6) = dVar24;
  *(double *)(puVar12 + 8) = dVar24;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  fVar2 = DAT_14053ae30;
  DAT_140e46c88 = puVar12;
  if (DAT_140e45274 == 0) {
    local_238._0_8_ = local_1e0 + dVar5;
    local_200 = 0;
    local_208 = 1;
    local_210 = 0xff;
    local_218 = 0xff;
    local_220 = 0xff;
    local_228 = 0xff;
    local_240 = local_240 & 0xffff0000;
    local_248 = DAT_14053ae30;
    unique0x10001e87 = (double)local_238._0_8_;
    FUN_1400c8410(DAT_140e41934,0x65,1,local_1f4 + DAT_14053ae88);
    local_200 = 0;
    local_208 = 1;
    local_210 = 0xff;
    local_218 = 0xff;
    local_220 = 0xff;
    local_228 = 0xff;
    stack0xfffffffffffffdd0 = local_1d8 + dVar5;
    local_238._0_8_ = local_1d8 + dVar5;
    local_240 = CONCAT22(local_240._2_2_,0x8000);
    local_248 = fVar2;
    FUN_1400c8410(DAT_140e41934,0x65,1,DAT_14053ad1c - fVar25);
  }
  FUN_1400d9b60(1,0x70,0xff);
  uVar23 = DAT_140e47540;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar23;
  puVar12[1] = 0x6e;
  puVar12[2] = 1;
  puVar12[3] = 0x44200000;
  puVar12[4] = 0x44228000;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  if ((DAT_140e45274 == 0) || (DAT_140e45274 == 6)) {
    uVar23 = *(undefined4 *)(&DAT_140e474f0 + (longlong)DAT_140e445c0 * 4);
    DAT_140e46c88 = puVar12;
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e58 = _DAT_140e46e58 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar12 = uVar23;
    puVar12[1] = 0x72;
    puVar12[2] = 1;
    puVar12[3] = 0x43c30000;
    puVar12[4] = 0x44228000;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = 0xff;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
  }
  DAT_140e46c88 = puVar12;
  lVar13 = DAT_140e47908;
  if ((((DAT_140e418c8 == 0x1e) || (DAT_140e46014 == 3)) || (DAT_140e46014 == 0xfffffffd)) ||
     ((DAT_140e46bb4 + 2 & 0xfffffffb) == 0)) {
    while (lVar13 != 0) {
      lVar13 = *(longlong *)(lVar13 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    if (DAT_140e45274 == 0) {
      iVar16 = DAT_140e445c0 + 3;
      uVar23 = DAT_14053ae58;
LAB_1400d5600:
      local_238._8_4_ = 0x40;
      local_238._0_4_ = DAT_14053ac80;
    }
    else {
      uVar23 = DAT_14053ae34;
      if (DAT_140e45274 < 4) {
        iVar16 = (&DAT_140e445c4)[DAT_140e45274 + -1] + 4 + (DAT_140e45274 + DAT_140e445c0 * 3) * 2;
        goto LAB_1400d5600;
      }
      if (DAT_140e45274 < 5) {
        DAT_140e445d0 = (int)((ulonglong)_DAT_140e445cc >> 0x20);
        iVar16 = DAT_140e445d0 + 0x18;
        goto LAB_1400d5600;
      }
      if (5 < DAT_140e45274) {
        if (6 < DAT_140e45274) goto LAB_1400d565d;
        iVar16 = DAT_140e445c0 + 0x1c;
        uVar23 = DAT_14053ae58;
        goto LAB_1400d5600;
      }
      local_238._8_4_ = 0x40;
      local_238._0_4_ = DAT_14053ac80;
      if (DAT_140e41b70 == 0) {
        iVar16 = 0x60;
      }
      else {
        iVar16 = 0x61;
      }
    }
    local_208 = 5;
    local_210 = 0;
    local_218 = 1;
    local_220 = 0x80;
    local_228 = 0x40;
    local_248 = DAT_14053aed0;
    local_240 = DAT_14053ac28;
    FUN_14012e070(iVar16,4,DAT_140e45274,uVar23);
  }
LAB_1400d565d:
  FUN_1400d3a60();
  iVar16 = local_1f8;
  if ((((int)DAT_140e418c8 < 0x32) || (DAT_140e45fac != 0)) || (DAT_140e46bb4 != 0))
  goto LAB_1400d5adf;
  if (DAT_140e45274 < 6) {
    bVar19 = false;
    if (DAT_140e8cf18 == 1) {
LAB_1400d56cb:
      bVar19 = true;
    }
    else if (0x13 < DAT_140e8cf18) {
      uVar14 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar14 < 0) {
        uVar14 = (uVar14 - 1 | 0xfffffff8) + 1;
      }
      if (uVar14 == 0) goto LAB_1400d56cb;
    }
    if ((DAT_140e8cf1c < 1) && (bVar19)) {
      if (DAT_140e45274 == 0) {
        DAT_140e445c0 = DAT_140e445c0 + 1;
        if (2 < DAT_140e445c0) {
          DAT_140e445c0 = 0;
        }
        _DAT_140e445c4 = *(undefined8 *)(&DAT_140e41b28 + (longlong)DAT_140e445c0 * 0x10);
        _DAT_140e445cc = *(undefined8 *)(&DAT_140e41b30 + (longlong)DAT_140e445c0 * 0x10);
        DAT_140e41b24 = DAT_140e445c0;
      }
      else if (DAT_140e45274 < 5) {
        lVar13 = (longlong)(DAT_140e45274 + -1);
        iVar15 = (&DAT_140e445c4)[lVar13] + 1;
        (&DAT_140e445c4)[lVar13] = iVar15;
        if (local_1f8 < iVar15) {
          (&DAT_140e445c4)[lVar13] = 0;
          iVar15 = 0;
        }
        *(int *)(&DAT_140e41b28 + (lVar13 + (longlong)DAT_140e445c0 * 4) * 4) = iVar15;
      }
      else if (DAT_140e45274 == 5) {
        DAT_140e41b70 = (uint)(DAT_140e41b70 == 0);
      }
      DAT_140e46014 = 4;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e467fc = 1;
    }
    bVar19 = false;
    if (DAT_140e8cf1c == 1) {
LAB_1400d57ef:
      bVar19 = true;
    }
    else if (0x13 < DAT_140e8cf1c) {
      uVar14 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar14 < 0) {
        uVar14 = (uVar14 - 1 | 0xfffffff8) + 1;
      }
      if (uVar14 == 0) goto LAB_1400d57ef;
    }
    if ((DAT_140e8cf18 < 1) && (bVar19)) {
      if (DAT_140e45274 == 0) {
        DAT_140e445c0 = DAT_140e445c0 + -1;
        if (DAT_140e445c0 < 0) {
          DAT_140e445c0 = 2;
        }
        _DAT_140e445c4 = *(undefined8 *)(&DAT_140e41b28 + (longlong)DAT_140e445c0 * 0x10);
        _DAT_140e445cc = *(undefined8 *)(&DAT_140e41b30 + (longlong)DAT_140e445c0 * 0x10);
        DAT_140e41b24 = DAT_140e445c0;
      }
      else if (DAT_140e45274 < 5) {
        lVar13 = (longlong)(DAT_140e45274 + -1);
        iVar15 = (&DAT_140e445c4)[lVar13] + -1;
        (&DAT_140e445c4)[lVar13] = iVar15;
        if (iVar15 < 0) {
          (&DAT_140e445c4)[lVar13] = iVar16;
          iVar15 = iVar16;
        }
        *(int *)(&DAT_140e41b28 + (lVar13 + (longlong)DAT_140e445c0 * 4) * 4) = iVar15;
      }
      else if (DAT_140e45274 == 5) {
        DAT_140e41b70 = (uint)(DAT_140e41b70 == 0);
      }
      DAT_140e46014 = 0xfffffffc;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e467fc = 1;
    }
    uVar23 = DAT_140e47204;
    iVar16 = DAT_140e45274;
    uVar9 = _DAT_140e445cc;
    if ((DAT_140e467bc == 1) && (DAT_140e467fc == 0)) {
      lVar13 = (longlong)DAT_140e445c0;
      DAT_140e41b24 = DAT_140e445c0;
      DAT_140e45274 = 6;
      DAT_140e46bb4 = 1;
      DAT_140e46064 = iVar16;
      *(undefined8 *)(&DAT_140e41b28 + lVar13 * 0x10) = _DAT_140e445c4;
      *(undefined8 *)(&DAT_140e41b30 + lVar13 * 0x10) = uVar9;
      FUN_140184700(DAT_140e44190 * 0x19,uVar23);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e467fc = 1;
    }
  }
  if (((DAT_140e45274 == 6) && (DAT_140e467b8 == 1)) && (DAT_140e467fc == 0)) {
    DAT_140e45274 = DAT_140e46064;
    DAT_140e46064 = 6;
    DAT_140e46bb4 = 0xffffffff;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
    DAT_140e467fc = 1;
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 < 6) {
      DAT_140e46bb4 = 1;
      iVar16 = DAT_140e45274 + 1;
      DAT_140e46064 = DAT_140e45274;
    }
    else {
      DAT_140e45fac = 1;
      iVar16 = DAT_140e45274;
    }
    DAT_140e45274 = iVar16;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e467fc = 1;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 0) {
      DAT_140e45fac = 0xffffffff;
      iVar16 = DAT_140e45274;
    }
    else {
      DAT_140e46bb4 = 0xffffffff;
      iVar16 = DAT_140e45274 + -1;
      DAT_140e46064 = DAT_140e45274;
    }
    DAT_140e45274 = iVar16;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
    DAT_140e467fc = 1;
  }
  if ((DAT_140e467e4 != 1) &&
     (DAT_140e467e0 != 1 &&
      (DAT_140e467dc != 1 &&
      (DAT_140e467d8 != 1 &&
      (DAT_140e467d4 != 1 &&
      (DAT_140e467cc._4_4_ != 1 &&
      ((int)DAT_140e467cc != 1 &&
      (DAT_140e467c8 != 1 &&
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_1400d5adf:
  if (((DAT_140e45274 < 7) && (DAT_140e46bb4 == 8)) ||
     ((-1 < DAT_140e45274 && (DAT_140e46bb4 == 0xfffffff8)))) {
    DAT_140e46bb4 = 0;
  }
  if (0x1e < (int)DAT_140e45fac) {
    FUN_1400d3fd0(DAT_140e45fac - 0x1e);
  }
  if (DAT_140e45fac == 0x50) {
    DAT_140e45274 = 0;
    DAT_140e418c8 = 0;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    if (DAT_140e41928 == 2) {
      DAT_140e45270 = 5;
    }
    else {
      DAT_140e45270 = 4;
      DAT_140e46958 = 0;
      uVar23 = DAT_140e41b58;
      if ((DAT_140e41928 == 0) || (uVar23 = DAT_140e41b5c, DAT_140e41928 == 1)) {
        DAT_1407c7798 = uVar23;
      }
      DAT_140e419b8 = DAT_140e41b60;
      DAT_140e45268 = DAT_140e41b64;
    }
    fopen_s(&local_d8,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
    FUN_140323e90(local_d8);
    DAT_140e471fc = 0xb4;
  }
  if ((int)DAT_140e45fac < -9) {
    FUN_1400d3fd0(-10 - DAT_140e45fac);
  }
  if (DAT_140e45fac == 0xffffffce) {
    DAT_140e45274 = DAT_140e41928;
    DAT_140e418c8 = 0;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    fopen_s(&local_d8,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
    FUN_140323e90(local_d8);
    DAT_140e471fc = 0xb4;
    DAT_140e45270 = 2;
  }
  if (0 < (int)DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 + 1;
  }
  if (0x7fffffff < DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 - 1;
  }
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


