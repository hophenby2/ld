// Function: FUN_1400ca6d0 @ 1400ca6d0
// Decompile completed: true

undefined8
FUN_1400ca6d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
             undefined8 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  bool bVar2;
  
  puVar1 = DAT_140e46e98;
  if (DAT_140e46c5c < 0x2000) {
    puVar1 = (undefined8 *)_malloc_base(0x30);
    if (puVar1 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c5c = DAT_140e46c5c + 1;
    bVar2 = DAT_140e46e90 == (undefined8 *)0x0;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)(puVar1 + 2) = param_3;
    puVar1[3] = param_5;
    *(undefined4 *)(puVar1 + 4) = param_6;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 1) = param_1;
    *(undefined2 *)((longlong)puVar1 + 0x14) = param_4;
    *(undefined4 *)((longlong)puVar1 + 0x24) = 0;
    puVar1[5] = 0;
    if (bVar2) {
      DAT_140e46e90 = puVar1;
    }
    if (DAT_140e46e98 != (undefined8 *)0x0) {
      DAT_140e46e98[5] = puVar1;
    }
  }
  DAT_140e46e98 = puVar1;
  return 0;
}


