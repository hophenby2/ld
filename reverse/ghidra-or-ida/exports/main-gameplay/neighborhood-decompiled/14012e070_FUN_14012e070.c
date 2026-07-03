// Function: FUN_14012e070 @ 14012e070
// Decompile completed: true

undefined8
FUN_14012e070(int param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
             undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
             undefined4 param_13)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = DAT_140e9fd30;
  if (DAT_140e44e6c < 0x200) {
    puVar1 = (undefined8 *)_malloc_base();
    if (puVar1 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","errer",0);
    }
    *(undefined4 *)(puVar1 + 4) = param_8;
    *(undefined4 *)((longlong)puVar1 + 0x24) = param_9;
    *(undefined4 *)(puVar1 + 5) = param_10;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = param_11;
    *(undefined4 *)(puVar1 + 6) = param_12;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)((longlong)puVar1 + 0x234) = param_13;
    *(undefined4 *)((longlong)puVar1 + 0x14) = param_5;
    *(undefined4 *)(puVar1 + 1) = 0;
    puVar1[0x47] = 0;
    lVar2 = (longlong)(param_1 + -1) * 0x200;
    *(undefined4 *)(puVar1 + 2) = param_4;
    *(undefined4 *)(puVar1 + 3) = param_6;
    *(undefined4 *)((longlong)puVar1 + 0x1c) = param_7;
    *puVar1 = 1;
    FUN_1401aece0((longlong)puVar1 + 0x34,&DAT_140e47910 + lVar2,0x100);
    FUN_1401aece0((longlong)puVar1 + 0x134,&DAT_140e47a10 + lVar2,0x100);
    if (DAT_140e47908 == (undefined8 *)0x0) {
      DAT_140e47908 = puVar1;
    }
    if (DAT_140e9fd30 != (undefined8 *)0x0) {
      DAT_140e9fd30[0x47] = puVar1;
    }
  }
  DAT_140e9fd30 = puVar1;
  return 0;
}


