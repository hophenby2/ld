// Function: state_24_result_continue_submenu_candidate @ 140113ef0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_24_result_continue_submenu_candidate(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_38 [32];
  FILE *local_18;
  ulonglong local_10;
  
  uVar1 = DAT_140e46024;
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_38;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  *puVar2 = uVar1;
  *(undefined8 *)(puVar2 + 1) = 100;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar2 + 3) = 0;
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
  puVar2[10] = 0xff;
  puVar2[0xb] = 0xff;
  puVar2[0xc] = 0xff;
  puVar2[0xd] = 0xff;
  *(undefined8 *)(puVar2 + 0xe) = 1;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar2;
  }
  uVar1 = DAT_140e467f0;
  DAT_140e46c88 = puVar2;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar2 = uVar1;
  *(undefined8 *)(puVar2 + 1) = 10;
  *(undefined8 *)(puVar2 + 3) = 0;
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
  puVar2[10] = 0xff;
  puVar2[0xb] = 0xff;
  puVar2[0xc] = 0xff;
  puVar2[0xd] = 0xff;
  *(undefined8 *)(puVar2 + 0xe) = 1;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
  }
  uVar1 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  DAT_140e46c88 = puVar2;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar2 = uVar1;
  puVar2[1] = 10;
  puVar2[2] = 1;
  puVar2[3] = 0x44200000;
  puVar2[4] = 0x43c30000;
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
  puVar2[10] = 0xff;
  puVar2[0xb] = 0xff;
  puVar2[0xc] = 0xff;
  puVar2[0xd] = 0x80;
  *(undefined8 *)(puVar2 + 0xe) = 1;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
  }
  uVar1 = DAT_140e41ab8;
  DAT_140e46c88 = puVar2;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cbc = _DAT_140e46cbc + 1;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar2 = uVar1;
  *(undefined8 *)(puVar2 + 1) = 0xb;
  *(undefined8 *)(puVar2 + 3) = 0;
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 10) = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0x80;
  *(undefined8 *)(puVar2 + 0xe) = 1;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
  }
  DAT_140e46c88 = puVar2;
  FUN_1400d9b60(0,0x70,0xff);
  if ((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) goto LAB_1401143e3;
  bVar4 = false;
  if (DAT_140e8cf10 == 1) {
LAB_1401141ff:
    bVar4 = true;
  }
  else if (0x13 < DAT_140e8cf10) {
    uVar3 = DAT_140e8cf10 - 0x14U & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) goto LAB_1401141ff;
  }
  if ((DAT_140e8cf14 < 1) && (bVar4)) {
    DAT_140e47434 = DAT_140e47434 + -1;
    if (DAT_140e47434 < 0) {
      DAT_140e47434 = 0x17;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  bVar4 = false;
  if (DAT_140e8cf14 == 1) {
LAB_140114287:
    bVar4 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar3 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) goto LAB_140114287;
  }
  if ((DAT_140e8cf10 < 1) && (bVar4)) {
    DAT_140e47434 = DAT_140e47434 + 1;
    if (0x17 < DAT_140e47434) {
      DAT_140e47434 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
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
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_1401143e3:
  if (DAT_140e45fac == 0x10) {
    DAT_140e9fd28 = 0;
    DAT_140e45fac = 0;
    DAT_140e418c8 = 1;
    DAT_140e45270 = 0x25;
  }
  else {
    if ((int)DAT_140e45fac < -9) {
      transition_tile_wipe_out_candidate(-10 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffd8) {
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
      fopen_s(&local_18,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_18);
      FUN_140323e90(local_18);
      DAT_140e471fc = 0xb4;
    }
    if (0 < (int)DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    if (0x7fffffff < DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac - 1;
    }
    DAT_140e418c8 = DAT_140e418c8 + 1;
  }
  return;
}


