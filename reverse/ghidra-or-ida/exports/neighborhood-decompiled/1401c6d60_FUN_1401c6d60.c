// Function: FUN_1401c6d60 @ 1401c6d60
// Decompile completed: true

void FUN_1401c6d60(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_1401ae170();
  if (iVar1 != 0) {
    return;
  }
  if (DAT_140c2b470 == 0) {
    FUN_1401e6080();
    if (DAT_140c2c018 != (code *)0x0) {
      (*DAT_140c2c018)(1);
    }
  }
  FUN_1401ae580(0x4b0);
  uVar2 = (*DAT_140c2b8a0)();
  if (uVar2 < 0x3b7) {
    if (uVar2 == 0x3b6) {
      FUN_1401ae4c0(3);
      FUN_1401ae4d0(0x3b6);
      return;
    }
    if (uVar2 != 0x3a4) {
      if (uVar2 == 0x3a8) {
        FUN_1401ae4c0(4);
        FUN_1401ae4d0(0x3a8);
        return;
      }
      if (uVar2 == 0x3b5) {
        FUN_1401ae4c0(2);
        FUN_1401ae4d0(0x3b5);
        return;
      }
    }
  }
  else {
    if (uVar2 == 0x4e4) {
      FUN_1401ae4c0(5);
      FUN_1401ae4d0(0x4e4);
      return;
    }
    if (uVar2 == 0x7ffc) {
      FUN_1401ae4c0(6);
      FUN_1401ae4d0(0x7ffc);
      return;
    }
  }
  FUN_1401ae4c0(1);
  FUN_1401ae4d0(0x3a4);
  return;
}


