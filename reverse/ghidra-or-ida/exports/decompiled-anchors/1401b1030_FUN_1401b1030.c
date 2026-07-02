// Function: FUN_1401b1030 @ 1401b1030
// Decompile completed: true

undefined8 FUN_1401b1030(int param_1)

{
  int *piVar1;
  
  FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xe61);
  piVar1 = (int *)(&DAT_14092df80)[param_1];
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    *piVar1 = *piVar1 + -1;
    FUN_1401b6e70(&DAT_14092dd48);
    return 0;
  }
  FUN_1401b6e70(&DAT_14092dd48);
  return 0xffffffff;
}


