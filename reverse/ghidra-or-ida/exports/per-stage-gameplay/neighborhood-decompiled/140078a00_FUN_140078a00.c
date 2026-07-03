// Function: FUN_140078a00 @ 140078a00
// Decompile completed: true

undefined8
FUN_140078a00(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
             undefined2 param_6,undefined8 param_7,undefined4 param_8,undefined4 param_9,
             undefined4 param_10)

{
  undefined4 *puVar1;
  bool bVar2;
  double dVar3;
  
  puVar1 = DAT_140e45d90;
  if (DAT_140e44e6c < 0x200) {
    puVar1 = (undefined4 *)_malloc_base(0x68);
    if (puVar1 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    bVar2 = DAT_140e419b8 == 0;
    *puVar1 = 1;
    puVar1[1] = DAT_1407c779c;
    puVar1[2] = param_10;
    *(undefined8 *)(puVar1 + 3) = 0;
    puVar1[5] = 0;
    puVar1[6] = param_1;
    puVar1[7] = param_2;
    puVar1[8] = param_2;
    if ((bVar2) && (param_1 != 0x153)) {
      dVar3 = (double)param_2 * DAT_140539f28;
      puVar1[7] = (int)dVar3;
      puVar1[8] = (int)dVar3;
    }
    DAT_1407c779c = DAT_1407c779c + 1;
    DAT_140e44e6c = DAT_140e44e6c + 1;
    bVar2 = DAT_140e45d80 == (undefined4 *)0x0;
    *(undefined2 *)(puVar1 + 0x10) = param_6;
    *(undefined2 *)((longlong)puVar1 + 0x42) = param_6;
    *(undefined2 *)(puVar1 + 0x11) = param_6;
    puVar1[0xb] = param_5;
    puVar1[0xd] = param_5;
    puVar1[0xf] = param_5;
    puVar1[0x14] = param_8;
    puVar1[0x15] = param_9;
    puVar1[10] = param_4;
    puVar1[0xc] = param_4;
    puVar1[0xe] = param_4;
    *(undefined8 *)(puVar1 + 0x12) = param_7;
    puVar1[9] = param_3;
    *(undefined8 *)(puVar1 + 0x16) = 1;
    *(undefined8 *)(puVar1 + 0x18) = 0;
    if (bVar2) {
      DAT_140e45d80 = puVar1;
    }
    if (DAT_140e45d90 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e45d90 + 0x18) = puVar1;
    }
  }
  DAT_140e45d90 = puVar1;
  return 0;
}


