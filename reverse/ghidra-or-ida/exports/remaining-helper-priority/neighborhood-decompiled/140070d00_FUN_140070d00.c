// Function: FUN_140070d00 @ 140070d00
// Decompile completed: true

undefined8
FUN_140070d00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined2 param_6,undefined8 param_7,undefined8 param_8,
             undefined8 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
             undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  undefined8 *puVar1;
  bool bVar2;
  
  puVar1 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar1 = (undefined8 *)_malloc_base();
    if (puVar1 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar2 = DAT_140e45d78 == (undefined8 *)0x0;
    *(undefined2 *)((longlong)puVar1 + 0x24) = param_6;
    *(undefined4 *)(puVar1 + 8) = param_10;
    *(undefined4 *)((longlong)puVar1 + 0x44) = param_11;
    *(undefined4 *)(puVar1 + 9) = param_12;
    *(undefined4 *)(puVar1 + 3) = param_5;
    *(undefined4 *)(puVar1 + 4) = param_5;
    *(undefined4 *)((longlong)puVar1 + 0x4c) = param_13;
    puVar1[5] = param_7;
    *(undefined4 *)(puVar1 + 10) = param_14;
    *(undefined4 *)((longlong)puVar1 + 0x54) = param_15;
    *(undefined4 *)((longlong)puVar1 + 0x14) = param_4;
    *(undefined4 *)((longlong)puVar1 + 0x1c) = param_4;
    puVar1[6] = param_8;
    puVar1[7] = param_9;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 1) = param_1;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)(puVar1 + 2) = param_3;
    puVar1[0xb] = 0;
    if (bVar2) {
      DAT_140e45d78 = puVar1;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar1;
    }
  }
  DAT_140e45d28 = puVar1;
  return 0;
}


