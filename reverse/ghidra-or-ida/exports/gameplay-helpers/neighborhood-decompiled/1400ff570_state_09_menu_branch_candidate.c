// Function: state_09_menu_branch_candidate @ 1400ff570
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_09_menu_branch_candidate(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  bool bVar11;
  undefined4 uVar12;
  
  if (DAT_140e418c8 < 0x3c) {
    FUN_1400d4310();
  }
  uVar2 = DAT_140e467f0;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  *puVar5 = uVar2;
  bVar11 = false;
  iVar7 = 0;
  *(undefined8 *)(puVar5 + 1) = 10;
  bVar10 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar5 + 3) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0xff;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar10) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar5;
  }
  uVar2 = DAT_140e46030;
  DAT_140e46c88 = puVar5;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar10 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar5 = uVar2;
  *(undefined8 *)(puVar5 + 1) = 0x65;
  *(undefined8 *)(puVar5 + 3) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0xff;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar10) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
  }
  DAT_140e46c88 = puVar5;
  FUN_1400d3a60();
  if ((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) goto LAB_1400ff954;
  if (DAT_140e8cf10 == 1) {
LAB_1400ff73d:
    bVar10 = true;
  }
  else {
    bVar10 = bVar11;
    if (0x13 < DAT_140e8cf10) {
      uVar4 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
      }
      if (uVar4 == 0) goto LAB_1400ff73d;
    }
  }
  if ((DAT_140e8cf14 < 1) && (bVar10)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 10;
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 == 1) {
LAB_1400ff7c1:
    bVar11 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar4 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    if (uVar4 == 0) goto LAB_1400ff7c1;
  }
  if ((DAT_140e8cf10 < 1) && (bVar11)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (10 < DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (((DAT_140e467c8 == 1) && (DAT_140e45274 == 10)) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 10) {
      DAT_140e45fac = 1;
    }
    else {
      DAT_140e45274 = 10;
      DAT_140e46014 = 1;
    }
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
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_1400ff954:
  uVar3 = DAT_14053ad58;
  uVar2 = DAT_14053ad40;
  puVar5 = &DAT_140e476a0;
  iVar8 = 100;
  do {
    uVar12 = uVar2;
    uVar9 = 0x60;
    if (DAT_140e45274 == iVar7) {
      uVar12 = uVar3;
      if (DAT_140e45fac != 0) {
        uVar4 = DAT_140e45fac + 10000U & 0x80000003;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
        }
        uVar9 = 0x60;
        if (1 < (int)uVar4) goto LAB_1400ff9c6;
      }
      uVar9 = 0xff;
    }
LAB_1400ff9c6:
    uVar1 = *puVar5;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar1;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[3] = uVar12;
    puVar6[4] = (float)iVar8;
    *(undefined8 *)(puVar6 + 1) = 100;
    *(undefined2 *)(puVar6 + 5) = 0;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = uVar9;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x32;
    puVar5 = puVar5 + 1;
    DAT_140e46c88 = puVar6;
    if (0x140e476cb < (longlong)puVar5) {
      uVar2 = (&DAT_140e47570)[DAT_140e45274];
      puVar5 = (undefined4 *)_malloc_base(0x48);
      if (puVar5 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e20 = _DAT_140e46e20 + 1;
      bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar5 = uVar2;
      *(undefined8 *)(puVar5 + 1) = 100;
      puVar5[3] = 0x43be0000;
      puVar5[4] = 0x42c80000;
      *(undefined2 *)(puVar5 + 5) = 0;
      *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
      puVar5[10] = 0xff;
      puVar5[0xb] = 0xff;
      puVar5[0xc] = 0xff;
      puVar5[0xd] = 0xff;
      *(undefined8 *)(puVar5 + 0xe) = 1;
      *(undefined8 *)(puVar5 + 0x10) = 0;
      if (bVar11) {
        DAT_140e46bf0 = puVar5;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
      }
      DAT_140e46c88 = puVar5;
      FUN_1400d9b60(1,0x70,0xff);
      if (0 < DAT_140e45fac) {
        if (0x13 < DAT_140e45fac) {
          FUN_1400d3fd0(DAT_140e45fac + -0x14);
        }
        if (DAT_140e45fac == 0x32) {
          DAT_140e418c8 = 1;
          DAT_140e45270 = 2;
          DAT_140e45274 = 6;
          DAT_140e45fac = 0;
          DAT_140e46014 = 0;
          DAT_140e46bb0 = 0;
          DAT_140e46bb4 = 0;
          return;
        }
      }
      if (0 < DAT_140e46014) {
        DAT_140e46014 = 0;
      }
      if (0 < DAT_140e45fac) {
        DAT_140e45fac = DAT_140e45fac + 1;
      }
      DAT_140e418c8 = DAT_140e418c8 + 1;
      return;
    }
  } while( true );
}


