// Function: state_10_23_result_continue_candidate @ 1401124b0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_10_23_result_continue_candidate(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  double dVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  uint local_90;
  undefined1 local_88 [16];
  uint local_78;
  uint local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_50;
  int local_48;
  undefined4 uStack_44;
  ulonglong local_40;
  
  iVar8 = DAT_140e418c8;
  dVar4 = DAT_140539f40;
  local_40 = DAT_1407c6b00 ^ (ulonglong)auStack_b8;
  iVar10 = 0;
  puVar6 = DAT_140e46c88;
  if (((DAT_140e45270 == 0x23) && (DAT_140e4759c == 1)) && (DAT_140e418c8 < 0x100)) {
    iVar7 = 0xff;
    if (DAT_140e418c8 - 0xdcU < 0x1e) {
      dVar12 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a568) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar7 = (int)(dVar12 * DAT_14053a5f8);
    }
    iVar9 = iVar10;
    if (iVar8 < 0xfa) {
      iVar9 = iVar7;
    }
    uVar1 = (&DAT_140e47088)[DAT_140e441b4 + 2];
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar1;
    puVar6[1] = 100;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x442c8000;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = iVar9;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar11) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  if (DAT_140e418c8 < 0x3c) {
    FUN_1400d4310(DAT_140e418c8);
  }
  uVar1 = DAT_140e46024;
  puVar6 = (undefined4 *)_malloc_base(0x48);
  if (puVar6 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar6 = uVar1;
  *(undefined8 *)(puVar6 + 1) = 100;
  *(undefined8 *)(puVar6 + 3) = 0;
  *(undefined2 *)(puVar6 + 5) = 0;
  *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
  puVar6[10] = 0xff;
  puVar6[0xb] = 0xff;
  puVar6[0xc] = 0xff;
  puVar6[0xd] = 0xff;
  *(undefined8 *)(puVar6 + 0xe) = 1;
  *(undefined8 *)(puVar6 + 0x10) = 0;
  if (bVar11) {
    DAT_140e46bf0 = puVar6;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
  }
  uVar1 = DAT_140e467f0;
  DAT_140e46c88 = puVar6;
  puVar6 = (undefined4 *)_malloc_base(0x48);
  if (puVar6 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar6 = uVar1;
  *(undefined8 *)(puVar6 + 1) = 10;
  *(undefined8 *)(puVar6 + 3) = 0;
  *(undefined2 *)(puVar6 + 5) = 0;
  *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
  puVar6[10] = 0xff;
  puVar6[0xb] = 0xff;
  puVar6[0xc] = 0xff;
  puVar6[0xd] = 0xff;
  *(undefined8 *)(puVar6 + 0xe) = 1;
  *(undefined8 *)(puVar6 + 0x10) = 0;
  if (bVar11) {
    DAT_140e46bf0 = puVar6;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
  }
  uVar1 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  DAT_140e46c88 = puVar6;
  puVar6 = (undefined4 *)_malloc_base(0x48);
  if (puVar6 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar6 = uVar1;
  puVar6[1] = 10;
  puVar6[2] = 1;
  puVar6[3] = 0x44200000;
  puVar6[4] = 0x43c30000;
  *(undefined2 *)(puVar6 + 5) = 0;
  *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
  puVar6[10] = 0xff;
  puVar6[0xb] = 0xff;
  puVar6[0xc] = 0xff;
  puVar6[0xd] = 0x80;
  *(undefined8 *)(puVar6 + 0xe) = 1;
  *(undefined8 *)(puVar6 + 0x10) = 0;
  if (bVar11) {
    DAT_140e46bf0 = puVar6;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
  }
  uVar1 = DAT_140e41ab8;
  DAT_140e46c88 = puVar6;
  puVar6 = (undefined4 *)_malloc_base(0x48);
  if (puVar6 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cbc = _DAT_140e46cbc + 1;
  bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar6 = uVar1;
  *(undefined8 *)(puVar6 + 1) = 0xb;
  *(undefined8 *)(puVar6 + 3) = 0;
  *(undefined2 *)(puVar6 + 5) = 0;
  *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 10) = 0;
  puVar6[0xc] = 0;
  puVar6[0xd] = 0x80;
  *(undefined8 *)(puVar6 + 0xe) = 1;
  *(undefined8 *)(puVar6 + 0x10) = 0;
  if (bVar11) {
    DAT_140e46bf0 = puVar6;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
  }
  DAT_140e46c88 = puVar6;
  FUN_1400d9b60(0,0x70,0xff);
  if ((0x1f < DAT_140e418c8) && (DAT_140e45fac == 0)) {
    if (DAT_140e8cf10 == 1) {
LAB_140112923:
      iVar8 = 1;
    }
    else {
      iVar8 = iVar10;
      if (0x13 < DAT_140e8cf10) {
        uVar5 = DAT_140e8cf10 - 0x14U & 0x80000007;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
        }
        if (uVar5 == 0) goto LAB_140112923;
      }
    }
    if ((DAT_140e8cf14 < 1) && (iVar8 == 1)) {
      DAT_140e45274 = DAT_140e45274 + -1;
      if (DAT_140e45274 < 0) {
        DAT_140e45274 = 1;
      }
      DAT_140e46014 = 4;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (DAT_140e8cf14 == 1) {
LAB_1401129b0:
      iVar10 = 1;
    }
    else if (0x13 < DAT_140e8cf14) {
      uVar5 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
      }
      iVar10 = 0;
      if (uVar5 == 0) goto LAB_1401129b0;
    }
    if ((DAT_140e8cf10 < 1) && (iVar10 == 1)) {
      DAT_140e45274 = DAT_140e45274 + 1;
      if (1 < DAT_140e45274) {
        DAT_140e45274 = 0;
      }
      DAT_140e46014 = 4;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
      DAT_140e45fac = 1;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
    }
    if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
      DAT_140e45274 = 1;
      DAT_140e45fac = 1;
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
  iVar8 = DAT_140e46014;
  if (0 < DAT_140e46014) {
    dVar12 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * DAT_14053a020 *
                                   DAT_140539d28);
    DAT_140e46014 = iVar8 + -1;
    dVar4 = dVar4 + dVar12 * DAT_140539e60;
  }
  uVar1 = DAT_140e4785c;
  uVar14 = (undefined4)((ulonglong)dVar4 >> 0x20);
  uVar13 = SUB84(dVar4,0);
  puVar6 = DAT_140e46c88;
  if (DAT_140e45270 == 0x23) {
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x43c80000;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar11) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  uVar1 = DAT_140e478a4;
  puVar6 = DAT_140e46c88;
  if (DAT_140e45270 == 0x10) {
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x43c80000;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar11) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  if (DAT_140e45270 == 0x23) {
    iVar8 = 8;
  }
  else {
    iVar8 = local_48;
    if (DAT_140e45270 == 0x10) {
      iVar8 = 0x17;
    }
  }
  uVar1 = *(undefined4 *)(&DAT_140e47840 + (longlong)iVar8 * 4);
  if (DAT_140e45274 == 0) {
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x44020000;
    *(undefined2 *)(puVar6 + 5) = 0;
    auVar3._8_4_ = uVar13;
    auVar3._0_8_ = dVar4;
    auVar3._12_4_ = uVar14;
    *(undefined1 (*) [16])(puVar6 + 6) = auVar3;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    if (DAT_140e45fac != 0) {
      uVar5 = DAT_140e45fac & 0x80000003;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
      }
      if ((int)uVar5 < 2) {
        local_50 = 0;
        local_58 = 1;
        local_60 = 0xff;
        local_68 = 0xff;
        local_70 = 0xff;
        local_78 = 0xff;
        local_88._8_4_ = uVar13;
        local_88._0_8_ = dVar4;
        local_88._12_4_ = uVar14;
        local_90 = local_90 & 0xffff0000;
        local_98 = DAT_14053ae90;
        DAT_140e46c88 = puVar6;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + (longlong)iVar8 * 4),0x6e,6,DAT_14053aedc);
        puVar6 = DAT_140e46c88;
      }
    }
  }
  else {
    puVar6 = (undefined4 *)_malloc_base();
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x44020000;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0x80;
    puVar6[0xb] = 0x80;
    puVar6[0xc] = 0x80;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  if (DAT_140e45270 == 0x23) {
    iVar8 = 9;
  }
  else if (DAT_140e45270 == 0x10) {
    iVar8 = 0x18;
  }
  uVar1 = *(undefined4 *)(&DAT_140e47840 + (longlong)iVar8 * 4);
  if (DAT_140e45274 == 1) {
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x44160000;
    *(undefined2 *)(puVar6 + 5) = 0;
    auVar2._8_4_ = uVar13;
    auVar2._0_8_ = dVar4;
    auVar2._12_4_ = uVar14;
    *(undefined1 (*) [16])(puVar6 + 6) = auVar2;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    if (DAT_140e45fac != 0) {
      uVar5 = DAT_140e45fac & 0x80000003;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
      }
      if ((int)uVar5 < 2) {
        local_50 = 0;
        local_58 = 1;
        local_60 = 0xff;
        local_68 = 0xff;
        local_70 = 0xff;
        local_78 = 0xff;
        local_88._8_4_ = uVar13;
        local_88._0_8_ = dVar4;
        local_88._12_4_ = uVar14;
        local_90 = local_90 & 0xffff0000;
        local_98 = DAT_14053aec0;
        DAT_140e46c88 = puVar6;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + (longlong)iVar8 * 4),0x6e,6,DAT_14053aedc);
        puVar6 = DAT_140e46c88;
      }
    }
  }
  else {
    puVar6 = (undefined4 *)_malloc_base();
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar1;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x44160000;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0x80;
    puVar6[0xb] = 0x80;
    puVar6[0xc] = 0x80;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  if ((int)DAT_140e45fac < 0x10) goto LAB_140113406;
  if (DAT_140e45270 == 0x23) {
    if (DAT_140e45274 == 0) {
      DAT_140e418c8 = 0;
      DAT_140e45fac = 0;
      DAT_140e47434 = 0;
      replay_handler_candidate_B();
      DAT_140e45270 = 0x24;
    }
    if (DAT_140e45274 == 1) {
      if (0x14 < (int)DAT_140e45fac) {
        FUN_1400d3fd0(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        FUN_1400f6fb0();
        DAT_140e45270 = 4;
        DAT_140e45274 = 0;
        DAT_140e418c8 = 0;
        DAT_140e46014 = 0;
        DAT_140e46bb4 = 0;
        DAT_140e46bb0 = 0;
        DAT_140e45fac = 0;
        if (DAT_140e41928 == 0) {
          DAT_1407c7798 = DAT_140e41b58;
        }
        else if (DAT_140e41928 == 1) {
          DAT_1407c7798 = DAT_140e41b5c;
        }
        else if (DAT_140e41928 == 2) {
          DAT_140e45270 = 5;
        }
        DAT_140e419b8 = DAT_140e41b60;
        FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45108);
        FUN_14018a340(DAT_140e45108,3,1);
        fopen_s((FILE **)&local_48,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_44,local_48));
        FUN_140323e90(CONCAT44(uStack_44,local_48));
        DAT_140e471fc = 0xb4;
      }
    }
  }
  if (DAT_140e45270 != 0x10) goto LAB_140113406;
  if (0x14 < (int)DAT_140e45fac) {
    FUN_1400d3fd0(DAT_140e45fac - 0x14);
  }
  if (DAT_140e45fac != 0x3c) goto LAB_140113406;
  DAT_140e45fac = 0;
  DAT_140e418c8 = 0;
  DAT_140e4759c = 0;
  if (DAT_140e45274 == 0) {
    if ((DAT_140e47478 == 0) && (DAT_140e46be8 == 0)) {
      if (DAT_1407c7798 != 10) {
        local_78 = (uint)(DAT_1407c7798 == 9);
        iVar8 = DAT_140e41abc;
        local_88._8_8_ = DAT_140e44590;
        if (DAT_140e41abc == 3) {
          local_78 = 0;
          iVar8 = 3;
          local_88._8_8_ = (longlong)DAT_140e451b0;
        }
        local_70 = (uint)(DAT_140e41abc == 3);
        local_88._0_4_ = DAT_140e445d0;
        local_90 = DAT_140e445cc;
        local_98 = DAT_140e445c8;
        FUN_14012d7c0(iVar8,DAT_140e419b8 + DAT_140e45268 * 5,DAT_140e445c0,DAT_140e445c4);
        if (DAT_1407c7798 != 10) goto LAB_1401133f5;
      }
      local_70 = 0;
      local_78 = 0;
      local_88._8_8_ = DAT_140e44590;
      local_88._0_4_ = DAT_140e445d0;
      local_90 = DAT_140e445cc;
      local_98 = DAT_140e445c8;
      FUN_14012d7c0(4,DAT_140e45268 * 5,DAT_140e445c0,DAT_140e445c4);
    }
    else {
      MessageBoxA((HWND)0x0,&DAT_140539540,"errer",0);
      DAT_140e4759c = 1;
    }
  }
LAB_1401133f5:
  DAT_140e45274 = 0;
  DAT_140e45270 = 0x23;
LAB_140113406:
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


