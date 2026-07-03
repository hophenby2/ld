// Function: FUN_1400714d0 @ 1400714d0
// Decompile completed: true

undefined8 FUN_1400714d0(void)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = DAT_140e45d28;
  if (DAT_140e45d78 != (int *)0x0) {
    iVar1 = *DAT_140e45d78;
    piVar3 = DAT_140e45d78;
    while (iVar1 == 0) {
      DAT_140e45d78 = *(int **)(piVar3 + 0x16);
      FUN_140323ce8(piVar3);
      DAT_140e45d1c = DAT_140e45d1c + -1;
      if (DAT_140e45d78 == (int *)0x0) {
        DAT_140e45d28 = (int *)0x0;
        return 0;
      }
      piVar3 = DAT_140e45d78;
      iVar1 = *DAT_140e45d78;
    }
    lVar2 = *(longlong *)(piVar3 + 0x16);
    DAT_140e45d78 = piVar3;
    while (lVar2 != 0) {
      piVar4 = *(int **)(piVar3 + 0x16);
      if (*piVar4 == 0) {
        *(undefined8 *)(piVar3 + 0x16) = *(undefined8 *)(piVar4 + 0x16);
        FUN_140323ce8();
        DAT_140e45d1c = DAT_140e45d1c + -1;
        piVar4 = piVar3;
      }
      piVar3 = piVar4;
      lVar2 = *(longlong *)(piVar4 + 0x16);
    }
  }
  DAT_140e45d28 = piVar3;
  return 0;
}


