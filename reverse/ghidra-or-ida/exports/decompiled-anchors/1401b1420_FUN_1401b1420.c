// Function: FUN_1401b1420 @ 1401b1420
// Decompile completed: true

undefined8 FUN_1401b1420(void)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  
  if (DAT_14092dd40 == 0) {
    FUN_1401b6d40(&DAT_14092dd48);
    FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xe7e);
    iVar2 = DAT_14097604c;
    iVar4 = 0;
    if (0 < DAT_14097604c) {
      puVar3 = &DAT_14092df80;
      do {
        piVar1 = (int *)*puVar3;
        if ((piVar1 != (int *)0x0) && (iVar4 = iVar4 + 1, *piVar1 < 1)) {
          FUN_1401b0960(piVar1 + 2);
          FUN_1401b0960(piVar1 + 2);
          FUN_1401ae370(piVar1 + 2,0,0x900);
          FUN_1401b6700(piVar1);
          *puVar3 = 0;
          DAT_14097604c = DAT_14097604c + -1;
        }
        puVar3 = puVar3 + 1;
      } while (iVar4 < iVar2);
    }
    FUN_1401b6e70(&DAT_14092dd48);
    DAT_14092dd40 = 1;
    return 0;
  }
  return 0xffffffff;
}


