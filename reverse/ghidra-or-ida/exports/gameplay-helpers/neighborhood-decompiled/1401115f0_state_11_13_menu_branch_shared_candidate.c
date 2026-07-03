// Function: state_11_13_menu_branch_shared_candidate @ 1401115f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_11_13_menu_branch_shared_candidate(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined4 uVar7;
  
  uVar5 = DAT_140e46044;
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar6 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar4 = uVar5;
  *(undefined8 *)(puVar4 + 1) = 0x65;
  *(undefined8 *)(puVar4 + 3) = 0;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
  puVar4[10] = 0xff;
  puVar4[0xb] = 0xff;
  puVar4[0xc] = 0xff;
  puVar4[0xd] = 0xff;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar6) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar4;
  }
  uVar5 = DAT_140e467f0;
  DAT_140e46c88 = puVar4;
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar6 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar4 = uVar5;
  *(undefined8 *)(puVar4 + 1) = 10;
  *(undefined8 *)(puVar4 + 3) = 0;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
  puVar4[10] = 0xff;
  puVar4[0xb] = 0xff;
  puVar4[0xc] = 0xff;
  puVar4[0xd] = 0xff;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar6) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
  }
  uVar5 = DAT_140e41ab8;
  DAT_140e46c88 = puVar4;
  if (DAT_140e45270 == 0x11) {
    puVar4 = (undefined4 *)_malloc_base();
    if (puVar4 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    *(undefined8 *)(puVar4 + 6) = 0x3fdccccccccccccd;
    *(undefined8 *)(puVar4 + 8) = 0x3fc3333333333333;
    puVar4[1] = 0x14;
    puVar4[3] = 0x44200000;
    puVar4[4] = 0x43b40000;
    puVar4[10] = 0x40;
    puVar4[0xb] = 0x40;
    puVar4[0xc] = 0x80;
    puVar4[0xd] = 0xc0;
  }
  else {
    puVar4 = (undefined4 *)_malloc_base(0x48);
    if (puVar4 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar6 = DAT_140e46bf0 == (undefined4 *)0x0;
    *(undefined8 *)(puVar4 + 6) = 0x3feccccccccccccd;
    *(undefined8 *)(puVar4 + 8) = 0x3fe999999999999a;
    *puVar4 = uVar5;
    puVar4[1] = 0x14;
    puVar4[2] = 1;
    puVar4[3] = 0x44200000;
    puVar4[4] = 0x43b40000;
    *(undefined2 *)(puVar4 + 5) = 0;
    puVar4[10] = 0x40;
    puVar4[0xb] = 0x40;
    puVar4[0xc] = 0x80;
    puVar4[0xd] = 0xc0;
    *(undefined8 *)(puVar4 + 0xe) = 1;
    *(undefined8 *)(puVar4 + 0x10) = 0;
    if (bVar6) {
      DAT_140e46bf0 = puVar4;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
    }
    if (DAT_140e473dc == 0) {
      iVar3 = DAT_140e441b4 + 6;
    }
    else {
      iVar3 = DAT_140e441b4 + 10;
    }
    uVar5 = (&DAT_140e47088)[iVar3];
    DAT_140e46c88 = puVar4;
    puVar4 = (undefined4 *)_malloc_base(0x48);
    if (puVar4 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e24 = _DAT_140e46e24 + 1;
    puVar4[0xd] = 0xff;
    puVar4[0xc] = 0xff;
    puVar4[0xb] = 0xff;
    puVar4[10] = 0xff;
    *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar4 + 6) = 0x3ff0000000000000;
    puVar4[4] = 0x42200000;
    puVar4[3] = 0x44610000;
    puVar4[1] = 0x65;
  }
  bVar6 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar4 = uVar5;
  puVar4[2] = 1;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar6) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
  }
  DAT_140e46c88 = puVar4;
  FUN_1400d3a60();
  uVar2 = _UNK_14053bb28;
  uVar1 = _DAT_14053bb20;
  uVar5 = DAT_14053ae48;
  uVar7 = DAT_14053ad2c;
  if (DAT_140e45270 == 0x11) {
    uVar7 = DAT_14053ae30;
  }
  if (DAT_140e45274 == 0) {
    FUN_1400c8410(DAT_140e46968,0x55,4,DAT_14053ae48,uVar7,0,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff
                  ,0xff,0xff,1,0);
  }
  if (DAT_140e45274 == 1) {
    FUN_1400c8410(DAT_140e46998,0x55,4,uVar5,uVar7,0,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  }
  if (DAT_140e45274 == 2) {
    FUN_1400c8410(DAT_140e469a0,0x55,4,uVar5,uVar7,0,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  }
  if (DAT_140e45274 == 3) {
    FUN_1400c8410(DAT_140e469a8,0x55,4,uVar5,uVar7,0,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  }
  if (DAT_140e45274 == 4) {
    FUN_1400c8410(DAT_140e46984,0x55,4,uVar5,uVar7,0,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
    if (DAT_140e45274 == 4) goto LAB_140111c13;
  }
  FUN_1400c8410((&DAT_140e46960)[DAT_140e46064 % 5 + 4],0x55,4,DAT_14053aea4,uVar7,0,uVar1,uVar2,
                0xff,0xff,0xff,0xff,1,0);
LAB_140111c13:
  if (4 < DAT_140e46064) {
    FUN_1400c8410(DAT_140e4698c,0x55,4,DAT_14053af0c,uVar7,0,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  }
  return;
}


