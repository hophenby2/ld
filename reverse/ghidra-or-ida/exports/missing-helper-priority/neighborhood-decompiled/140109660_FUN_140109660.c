// Function: FUN_140109660 @ 140109660
// Decompile completed: true

undefined8
FUN_140109660(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
             undefined2 param_5,int param_6,undefined4 param_7)

{
  undefined8 *puVar1;
  bool bVar2;
  
  puVar1 = DAT_140e9fd38;
  if (DAT_140e4764c < 0x100) {
    puVar1 = (undefined8 *)_malloc_base();
    if (puVar1 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e4764c = DAT_140e4764c + 1;
    bVar2 = DAT_140e9fd20 == 1;
    *(undefined2 *)((longlong)puVar1 + 0x1c) = param_5;
    *(int *)(puVar1 + 5) = param_6;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)(puVar1 + 2) = param_3;
    *(undefined4 *)((longlong)puVar1 + 0x14) = param_2;
    *(undefined4 *)(puVar1 + 3) = param_3;
    puVar1[4] = param_4;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = param_7;
    *(undefined4 *)(puVar1 + 6) = param_7;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 1) = param_1;
    *(undefined4 *)((longlong)puVar1 + 0x34) = 0;
    puVar1[7] = 0;
    if (bVar2) {
      *(int *)(puVar1 + 5) = param_6 * 100;
    }
    if (DAT_140e46ea0 == (undefined8 *)0x0) {
      DAT_140e46ea0 = puVar1;
    }
    if (DAT_140e9fd38 != (undefined8 *)0x0) {
      DAT_140e9fd38[7] = puVar1;
    }
  }
  DAT_140e9fd38 = puVar1;
  return 0;
}


