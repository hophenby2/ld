// Function: FUN_1401b0f70 @ 1401b0f70
// Decompile completed: true

undefined8 FUN_1401b0f70(uint param_1)

{
  int *piVar1;
  
  FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xfc2);
  piVar1 = (int *)(&DAT_140935f80)[param_1 & 0xfffffff];
  if (piVar1 == (int *)0x0) {
    FUN_1401b6e70(&DAT_14092dd48);
    return 0xffffffff;
  }
  if (*piVar1 == 0) {
    FUN_1401396c0(*(undefined8 *)(piVar1 + 2));
    piVar1[2] = 0;
    piVar1[3] = 0;
  }
  else {
    FUN_1401b1030(piVar1[4]);
    FUN_1401b5650(piVar1 + 6);
  }
  FUN_1401b6700(piVar1);
  (&DAT_140935f80)[param_1 & 0xfffffff] = 0;
  DAT_140976050 = DAT_140976050 + -1;
  FUN_1401b6e70(&DAT_14092dd48);
  return 0;
}


