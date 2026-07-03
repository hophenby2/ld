// Function: FUN_1400c8410 @ 1400c8410
// Decompile completed: true

undefined8
FUN_1400c8410(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined2 param_6,undefined8 param_7,undefined8 param_8,
             undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
             undefined4 param_13,undefined4 param_14)

{
  longlong *plVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
  bVar3 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined2 *)(puVar2 + 5) = param_6;
  puVar2[10] = param_9;
  puVar2[0xb] = param_10;
  puVar2[0xc] = param_11;
  puVar2[0xd] = param_12;
  puVar2[4] = param_5;
  puVar2[0xe] = param_13;
  puVar2[0xf] = param_14;
  puVar2[3] = param_4;
  *(undefined8 *)(puVar2 + 6) = param_7;
  *(undefined8 *)(puVar2 + 8) = param_8;
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar3) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    plVar1 = (longlong *)((longlong)DAT_140e46c88 + 0x40);
    DAT_140e46c88 = puVar2;
    *plVar1 = (longlong)puVar2;
    puVar2 = DAT_140e46c88;
  }
  DAT_140e46c88 = puVar2;
  return 0;
}


