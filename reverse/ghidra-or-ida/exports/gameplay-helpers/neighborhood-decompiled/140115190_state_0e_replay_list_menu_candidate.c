// Function: state_0e_replay_list_menu_candidate @ 140115190
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_0e_replay_list_menu_candidate(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  
  if (DAT_140e418c8 < 0x3c) {
    FUN_1400d4310();
  }
  uVar4 = DAT_140e46028;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  *puVar2 = uVar4;
  *(undefined8 *)(puVar2 + 1) = 0x65;
  bVar5 = DAT_140e46bf0 == (undefined4 *)0x0;
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
  if (bVar5) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar2;
  }
  uVar4 = DAT_140e467f0;
  DAT_140e46c88 = puVar2;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar5 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar2 = uVar4;
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
  if (bVar5) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
  }
  DAT_140e46c88 = puVar2;
  FUN_1400d9b60(0,0x70,0xff);
  FUN_1400d3a60();
  if ((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) goto LAB_140115567;
  bVar5 = false;
  if (DAT_140e8cf10 == 1) {
LAB_14011535c:
    bVar5 = true;
  }
  else if (0x13 < DAT_140e8cf10) {
    uVar3 = DAT_140e8cf10 - 0x14U & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) goto LAB_14011535c;
  }
  if ((DAT_140e8cf14 < 1) && (bVar5)) {
    DAT_140e47434 = DAT_140e47434 + -1;
    if (DAT_140e47434 < 0) {
      DAT_140e47434 = 0x17;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  bVar5 = false;
  if (DAT_140e8cf14 == 1) {
LAB_1401153dc:
    bVar5 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar3 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) goto LAB_1401153dc;
  }
  if ((DAT_140e8cf10 < 1) && (bVar5)) {
    DAT_140e47434 = DAT_140e47434 + 1;
    if (0x17 < DAT_140e47434) {
      DAT_140e47434 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    if ((&DAT_140e9fd40)[DAT_140e47434] == 1) {
      DAT_140e45fac = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      uVar4 = DAT_140e47204;
    }
    else {
      FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
      uVar4 = DAT_140e4720c;
    }
    FUN_14018a340(uVar4,1,1);
    DAT_140e467fc = 1;
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
LAB_140115567:
  if (DAT_140e45fac == 0x20) {
    if (((&DAT_140e8cf58)[(longlong)DAT_140e47434 * 0x2a6] & 0xfffffffd) == 0) {
      DAT_1407c7798 = (&DAT_140e8cf80)[(longlong)DAT_140e47434 * 0x2a6];
    }
    if ((&DAT_140e8cf58)[(longlong)DAT_140e47434 * 0x2a6] == 1) {
      DAT_1407c7798 = 1;
    }
    DAT_140e45fac = 0;
    DAT_140e46014 = 0;
    DAT_140e418c8 = 1;
    DAT_140e45270 = 0xf;
  }
  else {
    if ((int)DAT_140e45fac < -9) {
      FUN_1400d3fd0(-10 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffce) {
      DAT_140e45270 = 2;
      DAT_140e45274 = 3;
      DAT_140e418c8 = 0;
      DAT_140e45d74 = 0;
      DAT_140e45fac = 0;
      DAT_140e46014 = 0;
      lVar1 = DAT_140e47908;
      while (lVar1 != 0) {
        lVar1 = *(longlong *)(lVar1 + 0x238);
        FUN_140323ce8();
      }
      DAT_140e47908 = 0;
      DAT_140e9fd30 = 0;
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


