// Function: FUN_1401b6dc0 @ 1401b6dc0
// Decompile completed: true

undefined8 FUN_1401b6dc0(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_140c2b470 == 0) {
    FUN_1401e6080();
    if (DAT_140c2c018 != (code *)0x0) {
      (*DAT_140c2c018)(1);
    }
  }
  uVar1 = (*DAT_140c2b698)();
  (*DAT_140c2b860)(param_1);
  iVar2 = FUN_1401ae820(param_2);
  if (0x1ff < iVar2) {
    iVar2 = 0x1ff;
  }
  FUN_1401ae2f0(param_1 + 0x28,param_2,(longlong)iVar2);
  *(undefined1 *)((longlong)iVar2 + 0x28 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x22c) = uVar1;
  *(undefined4 *)(param_1 + 0x228) = param_3;
  return 0;
}


