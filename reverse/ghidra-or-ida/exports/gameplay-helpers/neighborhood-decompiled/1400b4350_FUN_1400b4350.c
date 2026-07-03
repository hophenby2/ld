// Function: FUN_1400b4350 @ 1400b4350
// Decompile completed: true

undefined8 FUN_1400b4350(undefined4 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  puVar2 = (undefined4 *)_malloc_base(0x18);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e467ec = DAT_140e467ec + 1;
  *puVar2 = 1;
  bVar3 = DAT_140e46068 == (undefined4 *)0x0;
  puVar2[1] = DAT_140e467ec;
  puVar2[2] = param_1;
  puVar2[3] = param_2;
  *(undefined8 *)(puVar2 + 4) = 0;
  if (bVar3) {
    DAT_140e46068 = puVar2;
  }
  if (DAT_140e46878 != (undefined4 *)0x0) {
    puVar1 = (undefined8 *)((longlong)DAT_140e46878 + 0x10);
    DAT_140e46878 = puVar2;
    *puVar1 = puVar2;
    puVar2 = DAT_140e46878;
  }
  DAT_140e46878 = puVar2;
  return 0;
}


