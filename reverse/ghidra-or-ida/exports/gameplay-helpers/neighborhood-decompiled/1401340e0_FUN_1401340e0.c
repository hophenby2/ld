// Function: FUN_1401340e0 @ 1401340e0
// Decompile completed: true

int FUN_1401340e0(void)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0;
  lVar2 = DAT_140e45d80;
  if (DAT_140e44e6c != 0) {
    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if ((*(int *)(lVar2 + 0x54) == 0) && (*(int *)(lVar2 + 0x58) == 1)) {
        iVar1 = *(int *)(lVar2 + 0x50);
        if ((DAT_140e445d8 / DAT_14053ab70 - (float)(iVar1 + 100) <= *(float *)(lVar2 + 0x28)) &&
           (((*(float *)(lVar2 + 0x28) <= (float)(iVar1 + 700) + DAT_140e445d8 / DAT_14053ab70 &&
             ((float)-(iVar1 + 100) <= *(float *)(lVar2 + 0x2c))) &&
            (*(float *)(lVar2 + 0x2c) <= (float)(iVar1 + 0x334))))) {
          iVar3 = iVar3 + 1;
        }
      }
    }
  }
  return iVar3;
}


