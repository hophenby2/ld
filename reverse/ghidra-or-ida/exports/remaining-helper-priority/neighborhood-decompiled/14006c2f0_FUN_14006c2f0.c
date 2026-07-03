// Function: FUN_14006c2f0 @ 14006c2f0
// Decompile completed: true

undefined8
FUN_14006c2f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined2 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,
             undefined4 param_9)

{
  undefined8 *puVar1;
  bool bVar2;
  
  puVar1 = DAT_140e451a8;
  if ((0x8a < DAT_140e445fc - 0x79U) && (DAT_140e451b4 < 0x800)) {
    puVar1 = (undefined8 *)_malloc_base();
    if (puVar1 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e451b4 = DAT_140e451b4 + 1;
    DAT_140e451a0 = DAT_140e451a0 + 1;
    bVar2 = DAT_140e45260 == (undefined8 *)0x0;
    *(undefined4 *)(puVar1 + 4) = param_6;
    *(undefined2 *)((longlong)puVar1 + 0x24) = param_5;
    *(undefined2 *)((longlong)puVar1 + 0x26) = param_5;
    *(undefined4 *)(puVar1 + 7) = param_8;
    *(undefined4 *)(puVar1 + 5) = (undefined4)param_7;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = param_7._4_4_;
    *(undefined4 *)(puVar1 + 6) = (undefined4)param_7;
    *(undefined4 *)((longlong)puVar1 + 0x34) = param_7._4_4_;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 2) = param_3;
    *(undefined4 *)((longlong)puVar1 + 0x14) = param_4;
    *(undefined4 *)(puVar1 + 3) = param_3;
    *(undefined4 *)((longlong)puVar1 + 0x1c) = param_4;
    *(undefined4 *)(puVar1 + 1) = param_1;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)((longlong)puVar1 + 0x3c) = 0;
    *(undefined4 *)(puVar1 + 8) = 1;
    *(undefined4 *)((longlong)puVar1 + 0x44) = param_9;
    puVar1[9] = 0;
    if (bVar2) {
      DAT_140e45260 = puVar1;
    }
    if (DAT_140e451a8 != (undefined8 *)0x0) {
      DAT_140e451a8[9] = puVar1;
    }
  }
  DAT_140e451a8 = puVar1;
  return 0;
}


