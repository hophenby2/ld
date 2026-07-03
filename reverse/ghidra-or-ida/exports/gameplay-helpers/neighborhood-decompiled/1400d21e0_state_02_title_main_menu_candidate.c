// Function: state_02_title_main_menu_candidate @ 1400d21e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_02_title_main_menu_candidate(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  double dVar4;
  float fVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 uVar34;
  undefined1 auStack_198 [32];
  float local_178;
  undefined4 uStack_174;
  undefined8 local_170;
  undefined1 auStack_168 [12];
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  int local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined4 *local_128;
  undefined4 *local_120;
  undefined4 *local_118;
  undefined2 uStack_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  ulonglong local_d0;
  
  iVar7 = DAT_140e418c8;
  uVar6 = _UNK_14053bb28;
  puVar11 = _DAT_14053bb20;
  dVar4 = DAT_14053a628;
  dVar24 = DAT_14053a020;
  dVar25 = DAT_140539d28;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_198;
  dVar22 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar31 = DAT_14053af94;
  dVar22 = dVar22 * _DAT_14053b0b8;
  dVar23 = (double)FUN_140332d90();
  puVar19 = &DAT_140e45100;
  uVar13 = (DAT_140e9fda8 - iVar7) + DAT_140e451bc;
  uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
  fVar26 = (float)(dVar23 * DAT_14053b0d8) + DAT_14053ae30;
  DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  uVar13 = uVar13 * 0x800 ^ uVar13;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
  uVar13 = DAT_140e9fd1c / 3;
  iVar8 = DAT_140e9fd1c * 10;
  if (iVar7 == 1) {
    if (DAT_140e474e4 == 1) {
      puVar17 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar17,0);
        puVar17 = puVar17 + 1;
      } while ((longlong)puVar17 < 0x140e45178);
      _DAT_1407c777c = 1.0;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e45108);
      FUN_14018a340(DAT_140e45108,3,1);
      iVar7 = DAT_140e418c8;
      goto LAB_1400d241d;
    }
LAB_1400d242b:
    dVar23 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a6d8 * dVar24 * dVar25);
    puVar17 = (undefined4 *)(dVar23 * _DAT_140539f70 + 0.0);
LAB_1400d2498:
    dVar24 = (double)FUN_140332d90(((double)iVar7 - 0.0) * dVar4 * dVar24 * dVar25);
    fVar31 = (float)(dVar24 * _DAT_14053b268) + _DAT_14053b01c;
    FUN_1400d4310(iVar7);
    iVar7 = DAT_140e418c8;
  }
  else {
LAB_1400d241d:
    puVar17 = puVar11;
    if (iVar7 < 0x3c) {
      if (iVar7 < 0x28) goto LAB_1400d242b;
      dVar23 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a278) * DAT_14053a890 * dVar24 *
                                     dVar25);
      puVar17 = (undefined4 *)(dVar23 * DAT_140539ed8 + (double)puVar11);
      goto LAB_1400d2498;
    }
  }
  iVar15 = DAT_140e46014;
  dVar24 = DAT_14053a020;
  iVar20 = 0;
  if (iVar7 == 0x40) {
    DAT_140e474e4 = 0;
  }
  uVar30 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  puVar3 = puVar11;
  if (0 < DAT_140e46014) {
    dVar25 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * DAT_14053a020 *
                                   dVar25);
    DAT_140e46014 = iVar15 + -1;
    puVar3 = (undefined4 *)(dVar25 * DAT_140539e60 + (double)puVar11);
  }
  uVar14 = DAT_140e467f0;
  uVar29 = SUB84(dVar24,0);
  uVar34 = (undefined4)((ulonglong)puVar3 >> 0x20);
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar9 = uVar14;
  *(undefined8 *)(puVar9 + 1) = 10;
  *(undefined8 *)(puVar9 + 3) = 0;
  *(undefined2 *)(puVar9 + 5) = 0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar9;
  }
  fVar5 = DAT_14053ae48;
  local_178 = (float)dVar22 + 0.0 + DAT_14053adb4;
  local_130._0_4_ = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158 = 0xff;
  auStack_168._8_4_ = (int)puVar17;
  auStack_168._0_8_ = puVar17;
  uStack_15c = (int)((ulonglong)puVar17 >> 0x20);
  local_170 = (undefined4 *)((ulonglong)local_170 & 0xffffffffffff0000);
  DAT_140e46c88 = puVar9;
  FUN_1400c8410(DAT_140e46ec8,100,1,DAT_14053ae48);
  local_130 = (undefined4 *)((ulonglong)local_130._4_4_ << 0x20);
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158 = 0xff;
  stack0xfffffffffffffea0 = uVar6;
  auStack_168._0_8_ = puVar11;
  local_170 = (undefined4 *)((ulonglong)local_170 & 0xffffffffffff0000);
  local_178 = fVar26;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44240 + (longlong)(int)(iVar8 + uVar13 * -0x1e + 9) * 4),
                0x4f,1,fVar31);
  fVar26 = DAT_14053ae90;
  fVar31 = DAT_14053ac94;
  iVar8 = 0xff;
  if (DAT_140e45274 == 1) {
    if (DAT_140e41b1c == 0) goto LAB_1400d26f7;
  }
  else if (DAT_140e45274 == 2) {
    if (DAT_140e41b68 < 2) {
LAB_1400d26f7:
      iVar8 = 0x80;
    }
  }
  else if ((DAT_140e45274 == 4) && (DAT_140e467e8 != 0)) goto LAB_1400d26f7;
  iVar7 = iVar20;
  if (DAT_140e45fac != 0) {
    uVar13 = DAT_140e45fac + 10000U & 0x80000003;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
    }
    if ((int)uVar13 < 2) {
      iVar8 = 0x60;
    }
  }
  while( true ) {
    while( true ) {
      iVar18 = DAT_140e45274;
      iVar15 = DAT_140e418c8;
      fVar32 = 0.0;
      dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - (double)(iVar7 * 0x21)) *
                                     DAT_14053a798 * (double)CONCAT44(uVar30,uVar29) * DAT_140539d28
                                    );
      fVar33 = (float)(dVar25 * DAT_14053a018) + 0.0;
      if ((iVar15 < 0x3c) && (iVar2 = iVar7 * 5, iVar15 < iVar2 + 0x32)) {
        dVar25 = (double)FUN_140332d90(iVar2,(double)iVar2);
        fVar32 = (float)(dVar25 * DAT_14053a848) - DAT_14053af14;
      }
      local_130 = (undefined4 *)((ulonglong)local_130 & 0xffffffff00000000);
      local_138 = 1;
      if (iVar7 != 0) break;
      local_148 = 0xff;
      local_150 = 0xff;
      local_158 = 0xff;
      auStack_168._8_4_ = (int)puVar3;
      auStack_168._0_8_ = puVar3;
      uStack_15c = uVar34;
      local_170 = (undefined4 *)((ulonglong)local_170._2_6_ << 0x10);
      local_f8 = _DAT_14053bcc0;
      uStack_f0 = _UNK_14053bcc8;
      local_d8 = 0x42b40000;
      local_e8 = _DAT_14053bcb0;
      uStack_e0 = _UNK_14053bcb8;
      local_140 = iVar8;
      local_178 = fVar33 + fVar26;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e473b0 + (longlong)iVar18 * 4),0x6e,1,fVar32 + fVar5);
      if (((DAT_140e441b4 & 0xfffffffc) == 0) && (DAT_140e441b4 != 1)) {
        local_178 = fVar33 + fVar26 + fVar31;
        local_130 = (undefined4 *)((ulonglong)local_130 & 0xffffffff00000000);
        local_138 = 1;
        local_148 = 0xff;
        local_150 = 0xff;
        local_158 = 0xff;
        local_170 = (undefined4 *)((ulonglong)local_170 & 0xffffffffffff0000);
        local_140 = iVar8;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e47438 + (longlong)DAT_140e45274 * 4),0x6f,1,
                      fVar32 + fVar5 + *(float *)((longlong)&local_f8 + (longlong)DAT_140e45274 * 4)
                     );
      }
      iVar7 = 1;
    }
    iVar15 = iVar18 + iVar7;
    iVar18 = iVar18 - iVar7;
    iVar16 = (3 - iVar7) * 0x40;
    local_148 = 0xff;
    iVar2 = iVar15 + -9;
    if (iVar15 < 9) {
      iVar2 = iVar15;
    }
    local_150 = 0xff;
    local_158 = 0xff;
    dVar25 = DAT_140539f28 - (double)iVar7 * DAT_140539e60;
    fVar28 = (float)iVar7 * DAT_14053acfc;
    fVar27 = (float)iVar7 * DAT_14053aca8 + DAT_14053aca8;
    uVar30 = (undefined4)((ulonglong)dVar25 >> 0x20);
    auStack_168._8_4_ = SUB84(dVar25,0);
    auStack_168._0_8_ = dVar25;
    uStack_15c = uVar30;
    local_170 = (undefined4 *)((ulonglong)local_170._2_6_ << 0x10);
    local_178 = fVar27 + fVar26 + fVar33;
    local_140 = iVar16;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e473b0 + (longlong)iVar2 * 4),0x6e,1,
                  fVar28 + fVar5 + fVar32);
    local_130 = (undefined4 *)((ulonglong)local_130 & 0xffffffff00000000);
    local_138 = 1;
    local_148 = 0xff;
    local_150 = 0xff;
    local_158 = 0xff;
    iVar15 = iVar18 + 9;
    if (-1 < iVar18) {
      iVar15 = iVar18;
    }
    local_170 = (undefined4 *)((ulonglong)local_170 & 0xffffffffffff0000);
    local_178 = (fVar26 - fVar27) + fVar33;
    local_140 = iVar16;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e473b0 + (longlong)iVar15 * 4),0x6e,1,
                  (fVar5 - fVar28) + fVar32);
    if (2 < iVar7 + 1) break;
    uVar29 = SUB84(DAT_14053a020,0);
    uVar30 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    iVar7 = iVar7 + 1;
  }
  FUN_1400d9b60(0,0x70,0xff);
  uVar30 = DAT_14053ac80;
  puVar10 = DAT_140e47908;
  if (DAT_140e418c8 == 1) {
    while (puVar10 != (undefined8 *)0x0) {
      puVar10 = (undefined8 *)puVar10[0x47];
      FUN_140323ce8();
    }
    DAT_140e47908 = (undefined8 *)0x0;
    DAT_140e9fd30 = (undefined8 *)0x0;
    puVar10 = DAT_140e9fd30;
    if (DAT_140e44e6c < 0x200) {
      puVar10 = (undefined8 *)_malloc_base(0x240);
      if (puVar10 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar10 = 1;
      *(undefined4 *)((longlong)puVar10 + 0xc) = 1;
      *(undefined4 *)(puVar10 + 1) = 0;
      *(undefined4 *)(puVar10 + 2) = 0x40a00000;
      *(undefined8 *)((longlong)puVar10 + 0x14) = 0x40a00000;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = 0x41f00000;
      *(undefined4 *)(puVar10 + 4) = 0xff;
      *(undefined4 *)((longlong)puVar10 + 0x24) = 0xff;
      puVar10[5] = 0xff;
      *(undefined4 *)(puVar10 + 6) = 0;
      *(undefined4 *)((longlong)puVar10 + 0x234) = 5;
      puVar10[0x47] = 0;
      strcpy_s((char *)((longlong)puVar10 + 0x34),0x100,"Ver 2.11");
      strcpy_s((char *)((longlong)puVar10 + 0x134),0x100,"NULL");
      if (DAT_140e47908 == (undefined8 *)0x0) {
        DAT_140e47908 = puVar10;
      }
      if (DAT_140e9fd30 != (undefined8 *)0x0) {
        DAT_140e9fd30[0x47] = puVar10;
      }
    }
    DAT_140e9fd30 = puVar10;
    local_138 = 5;
    local_140 = 2;
    local_148 = 0;
    local_150 = 0xff;
    local_158 = 0xff;
    auStack_168._8_4_ = 0xff;
    auStack_168._0_4_ = uVar30;
    local_170 = (undefined4 *)((ulonglong)local_170 & 0xffffffff00000000);
    local_178 = DAT_14053af00;
    FUN_14012e070(1,0);
  }
  uVar14 = DAT_140e47540;
  if (DAT_140e4747c != 0) {
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar11 = uVar14;
    puVar11[1] = 0x6e;
    puVar11[2] = 1;
    puVar11[3] = 0x44200000;
    puVar11[4] = 0x43c08000;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xd] = 0xff;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    local_150 = 0;
    local_158 = 1;
    auStack_168._8_4_ = 0xff;
    local_170 = _DAT_14053bb20;
    auStack_168._0_8_ = _UNK_14053bb28;
    local_178 = DAT_14053ae18;
    DAT_140e46c88 = puVar11;
    FUN_1400c95e0(0,0x6f,(longlong)DAT_140e4747c,DAT_14053aedc);
  }
  FUN_1400d3a60();
  if (((0x3f < DAT_140e418c8) && (DAT_140e45fac == 0)) && (DAT_140e418c8 < 0xe10)) {
    iVar8 = 0;
    if (DAT_140e8cf14 == 1) {
LAB_1400d2d55:
      iVar20 = 1;
    }
    else if (0x13 < DAT_140e8cf14) {
      uVar13 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar13 < 0) {
        uVar13 = (uVar13 - 1 | 0xfffffff8) + 1;
      }
      iVar20 = iVar8;
      if (uVar13 == 0) goto LAB_1400d2d55;
    }
    if ((DAT_140e8cf10 < 1) && (iVar20 == 1)) {
      if (DAT_140e4745c == 0) {
        DAT_140e45274 = DAT_140e45274 + 1;
        if (8 < DAT_140e45274) {
          DAT_140e45274 = 0;
        }
        DAT_140e46014 = 4;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar14 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar14 = DAT_140e4720c;
      }
      FUN_14018a340(uVar14,1,1);
      DAT_140e467fc = 1;
    }
    if (DAT_140e8cf10 == 1) {
LAB_1400d2e1e:
      bVar21 = true;
    }
    else {
      bVar21 = false;
      if (0x13 < DAT_140e8cf10) {
        uVar13 = DAT_140e8cf10 - 0x14U & 0x80000007;
        if ((int)uVar13 < 0) {
          uVar13 = (uVar13 - 1 | 0xfffffff8) + 1;
        }
        bVar21 = false;
        if (uVar13 == 0) goto LAB_1400d2e1e;
      }
    }
    if ((DAT_140e8cf14 < 1) && (bVar21)) {
      if (DAT_140e4745c == 0) {
        DAT_140e45274 = DAT_140e45274 + -1;
        if (DAT_140e45274 < 0) {
          DAT_140e45274 = 8;
        }
        DAT_140e46014 = 4;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar14 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar14 = DAT_140e4720c;
      }
      FUN_14018a340(uVar14,1,1);
      DAT_140e467fc = 1;
    }
    if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
      if (DAT_140e45274 == 1) {
        if (DAT_140e41b1c == 0) goto LAB_1400d3112;
      }
      else if (DAT_140e45274 == 2) {
        if (DAT_140e41b68 < 2) {
LAB_1400d3112:
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          FUN_14018a340(DAT_140e4720c,1,1);
          DAT_140e467fc = 1;
          goto LAB_1400d2ef7;
        }
      }
      else if ((DAT_140e45274 == 4) && (DAT_140e467e8 != 0)) goto LAB_1400d3112;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e45fac = 1;
    }
LAB_1400d2ef7:
    if (DAT_140e47478 == 1) {
      iVar7 = FUN_14019d900(1);
      if (((iVar7 == 1) && (DAT_140e467fc == 0)) && (DAT_140e41b1c == 0)) {
        FUN_140135430(1);
        DAT_140e467fc = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        FUN_14018a340(DAT_140e47204,1,1);
      }
      iVar7 = FUN_14019d900(1);
      if (((iVar7 == 1) && (DAT_140e467fc == 0)) && (DAT_140e41b1c == 1)) {
        FUN_140135430(0);
        DAT_140e467fc = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        FUN_14018a340(DAT_140e47204,1,1);
      }
    }
    uVar29 = DAT_14053ae58;
    uVar14 = DAT_14053ac28;
    if (DAT_140e4747c != 0) {
      if ((DAT_140e8cf18 == 1) ||
         ((iVar7 = iVar8, 0x13 < DAT_140e8cf18 &&
          (iVar15 = DAT_140e8cf18 + -0x14,
          iVar15 == (iVar15 / 3 + (iVar15 >> 0x1f) +
                    (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3)))) {
        iVar7 = 1;
      }
      fVar31 = DAT_14053ae30;
      if (((DAT_140e8cf1c < 1) && (iVar7 == 1)) && (DAT_140e4747c < 0x22b)) {
        DAT_140e4747c = DAT_140e4747c + 1;
        puVar10 = DAT_140e47908;
        while (DAT_14053ae30 = fVar31, puVar10 != (undefined8 *)0x0) {
          puVar10 = (undefined8 *)puVar10[0x47];
          FUN_140323ce8();
          fVar31 = DAT_14053ae30;
        }
        local_138 = 5;
        local_140 = 0;
        local_148 = 0;
        local_150 = 0x80;
        local_158 = 0x40;
        auStack_168._8_4_ = 0x40;
        auStack_168._0_4_ = uVar30;
        local_170._4_4_ = (undefined4)((ulonglong)local_170 >> 0x20);
        local_170 = (undefined4 *)CONCAT44(local_170._4_4_,uVar14);
        DAT_140e47908 = (undefined8 *)0x0;
        DAT_140e9fd30 = (undefined8 *)0x0;
        local_178 = fVar31;
        FUN_14012e070(DAT_140e4747c,4,DAT_140e4747c,uVar29);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
      if ((DAT_140e8cf1c == 1) ||
         ((0x13 < DAT_140e8cf1c &&
          (iVar7 = DAT_140e8cf1c + -0x14,
          iVar7 == (iVar7 / 3 + (iVar7 >> 0x1f) +
                   (int)(((longlong)iVar7 / 3 + ((longlong)iVar7 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                   3)))) {
        iVar8 = 1;
      }
      if (((DAT_140e8cf18 < 1) && (iVar8 == 1)) && (1 < DAT_140e4747c)) {
        DAT_140e4747c = DAT_140e4747c + -1;
        puVar10 = DAT_140e47908;
        while (puVar10 != (undefined8 *)0x0) {
          puVar10 = (undefined8 *)puVar10[0x47];
          FUN_140323ce8();
        }
        local_138 = 5;
        local_140 = 0;
        local_148 = 0;
        local_150 = 0x80;
        local_158 = 0x40;
        auStack_168._8_4_ = 0x40;
        auStack_168._0_4_ = uVar30;
        local_170._4_4_ = (undefined4)((ulonglong)local_170 >> 0x20);
        local_170 = (undefined4 *)CONCAT44(local_170._4_4_,uVar14);
        DAT_140e47908 = (undefined8 *)0x0;
        DAT_140e9fd30 = (undefined8 *)0x0;
        local_178 = fVar31;
        FUN_14012e070(DAT_140e4747c,4,DAT_140e4747c,uVar29);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
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
  if (DAT_140e45274 == 8) goto LAB_1400d3417;
  if (0x13 < DAT_140e45fac) {
    FUN_1400d3fd0(DAT_140e45fac + -0x14);
  }
  if ((DAT_140e45274 == 8) || (DAT_140e45fac != 0x3c)) goto LAB_1400d3417;
  switch(DAT_140e45274) {
  case 0:
  case 1:
  case 2:
    if (DAT_140e441bc == 1) {
      DAT_140e41928 = DAT_140e45274;
      DAT_140e46064 = 0;
      DAT_140e445c0 = DAT_140e41b24;
      DAT_140e45270 = 3;
      _DAT_140e445c4 = *(undefined8 *)(&DAT_140e41b28 + (longlong)DAT_140e41b24 * 0x10);
      _DAT_140e445cc = *(undefined8 *)(&DAT_140e41b30 + (longlong)DAT_140e41b24 * 0x10);
      break;
    }
    DAT_140e41928 = -1;
    FUN_1400f7150();
    goto switchD_1400d3337_default;
  case 3:
    DAT_140e45270 = 0xe;
    DAT_140e47434 = 0;
    replay_handler_candidate_B();
    break;
  case 4:
    DAT_140e45270 = 0x11;
    DAT_140e46064 = 0;
    DAT_140e473dc = 0;
    break;
  case 5:
    DAT_140e45270 = 6;
    DAT_140e46064 = 0;
    break;
  case 6:
    DAT_140e45270 = 9;
    break;
  case 7:
    DAT_140e45270 = 10;
    break;
  default:
    goto switchD_1400d3337_default;
  }
  DAT_140e45274 = 0;
switchD_1400d3337_default:
  DAT_140e418c8 = 0;
  DAT_140e46014 = 0;
  DAT_140e46bb4 = 0;
  DAT_140e46bb0 = 0;
  DAT_140e45fac = 0;
LAB_1400d3417:
  if (((DAT_140e441bc == 0) && (DAT_140e45274 == 0)) && (DAT_140e45fac == 1)) {
    do {
      FUN_14018f230(*puVar19,0);
      puVar19 = puVar19 + 1;
    } while ((longlong)puVar19 < 0x140e45178);
  }
  if ((0xe0f < DAT_140e418c8) && (DAT_140e45fac == 0)) {
    uVar13 = DAT_140e4526c & 0x80000003;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
    }
    if (uVar13 == 3) {
      dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053aaa8) * DAT_14053a4d8 *
                                     DAT_14053a020 * DAT_140539d28);
      _DAT_1407c777c = (float)(dVar25 * DAT_14053b0a0) + DAT_140539da8;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45108);
      dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053aaa8) * DAT_14053a4d8 *
                                     DAT_14053a020 * DAT_140539d28);
      uVar30 = DAT_140e41ab8;
      dVar25 = dVar25 * DAT_14053a5f8;
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e8c = _DAT_140e46e8c + 1;
      bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar11 = uVar30;
      *(undefined8 *)(puVar11 + 1) = 0x7f;
      *(undefined8 *)(puVar11 + 3) = 0;
      *(undefined2 *)(puVar11 + 5) = 0;
      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar11 + 10) = 0;
      puVar11[0xc] = 0;
      puVar11[0xd] = (int)dVar25;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      if (bVar21) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
      DAT_140e46c88 = puVar11;
      if (DAT_140e418c8 == 0xe88) {
        DAT_140e4526c = DAT_140e4526c + 1;
        DAT_140e418c8 = 0xe88;
        lVar1 = DAT_140e45d78;
        while (lVar1 != 0) {
          lVar1 = *(longlong *)(lVar1 + 0x58);
          FUN_140323ce8();
        }
        DAT_140e45d78 = 0;
        DAT_140e45d28 = 0;
        DAT_140e45d1c = 0;
        puVar10 = DAT_140e47908;
        while (puVar10 != (undefined8 *)0x0) {
          puVar10 = (undefined8 *)puVar10[0x47];
          FUN_140323ce8();
        }
        DAT_140e47908 = (undefined8 *)0x0;
        DAT_140e9fd30 = (undefined8 *)0x0;
        DAT_140e418c8 = 0;
        DAT_140e45270 = 1;
      }
    }
    else {
      FUN_1400d3fd0(DAT_140e418c8 + -0xe10);
      if (DAT_140e418c8 == 0xe4c) {
        DAT_140e4526c = DAT_140e4526c + 1;
        lVar1 = DAT_140e45d78;
        while (lVar1 != 0) {
          lVar1 = *(longlong *)(lVar1 + 0x58);
          FUN_140323ce8();
        }
        DAT_140e45d78 = 0;
        DAT_140e45d28 = 0;
        DAT_140e45d1c = 0;
        puVar10 = DAT_140e47908;
        while (puVar10 != (undefined8 *)0x0) {
          puVar10 = (undefined8 *)puVar10[0x47];
          FUN_140323ce8();
        }
        DAT_140e47908 = (undefined8 *)0x0;
        DAT_140e9fd30 = (undefined8 *)0x0;
        uVar13 = DAT_140e4526c & 0x80000003;
        if ((int)uVar13 < 0) {
          uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
        }
        DAT_140e45270 = 0x2a;
        FUN_1401121f0();
        DAT_140e41b00 = 1;
        FUN_140070ca0(&local_f8,0x20,"media\\demo\\LD_demo%02d.txt",uVar13);
        iVar8 = FUN_140137460(&local_f8,0);
        if (iVar8 == 0) {
          FUN_140137440(0);
          FUN_1400f6fb0();
          DAT_140e45274 = 0;
          DAT_140e45270 = 2;
          goto LAB_1400d39bd;
        }
        local_118 = &DAT_140e452f0;
        local_120 = &DAT_140e452e8;
        local_128 = &DAT_140e452a8;
        local_130 = &DAT_140e452a4;
        local_138 = 0x40e452ec;
        uStack_134 = 1;
        local_140 = 0x40e452bc;
        uStack_13c = 1;
        local_148 = 0x40e452b8;
        uStack_144 = 1;
        local_150 = 0x40e452b4;
        uStack_14c = 1;
        local_158 = 0x40e452b0;
        uStack_154 = 1;
        stack0xfffffffffffffea0 = &DAT_140e452ac;
        auStack_168._0_8_ = &DAT_140e452c0;
        local_170 = &DAT_140e452a0;
        local_178 = 7.135084;
        uStack_174 = 1;
        FUN_140137aa0(iVar8,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&DAT_140e45284,
                      &DAT_140e45298);
        do {
          iVar15 = FUN_140137aa0(iVar8,"%d,%d",&local_100,(int *)((longlong)&local_100 + 4));
          iVar7 = (int)local_100;
          uStack_104 = (undefined2)local_100._4_4_;
          piVar12 = (int *)_malloc_base(0x10);
          if (piVar12 == (int *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          bVar21 = DAT_140e45278 == (int *)0x0;
          *(undefined2 *)(piVar12 + 1) = uStack_104;
          *piVar12 = iVar7;
          piVar12[2] = 0;
          piVar12[3] = 0;
          if (bVar21) {
            DAT_140e45278 = piVar12;
          }
          if (DAT_140e9fd00 != (int *)0x0) {
            *(int **)(DAT_140e9fd00 + 2) = piVar12;
          }
          DAT_140e9fd00 = piVar12;
        } while ((iVar15 != -1) && ((int)local_100 < DAT_140e45284));
        FUN_140137440(iVar8);
        DAT_140e41928 = DAT_140e45298;
        DAT_140e41abc = DAT_140e4529c;
        DAT_140e451a4 = DAT_140e452a8;
        DAT_140e419b8 = DAT_140e452a0;
        DAT_140e45268 = DAT_140e452a4;
        DAT_140e445c0 = DAT_140e452ac;
        DAT_1407c7798 = DAT_140e452c0;
        _DAT_140e445c4 = _DAT_140e452b0;
        _DAT_140e445cc = _DAT_140e452b8;
        FUN_1400f7150();
        DAT_140e418c8 = DAT_140e418c8 + -1;
      }
    }
  }
  if (DAT_140e45274 == 8) {
    if (DAT_140e45fac == 1) {
      fopen_s((FILE **)&local_100,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(local_100._4_4_,(int)local_100));
      FUN_140323e90(CONCAT44(local_100._4_4_,(int)local_100));
      DAT_140e471fc = 0xb4;
    }
    if (0x1d < DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac + -0x1e);
    }
    if (DAT_140e45fac == 0x5a) {
      FUN_14019d3b0();
    }
  }
LAB_1400d39bd:
  if (0 < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


