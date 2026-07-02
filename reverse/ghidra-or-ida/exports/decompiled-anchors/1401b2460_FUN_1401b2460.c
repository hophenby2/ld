// Function: FUN_1401b2460 @ 1401b2460
// Decompile completed: true

undefined8 FUN_1401b2460(void)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  
  if (DAT_14092dd40 != 0) {
    FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xe7e);
    iVar2 = DAT_14097604c;
    iVar4 = 0;
    if (0 < DAT_14097604c) {
      plVar3 = &DAT_14092df80;
      do {
        lVar1 = *plVar3;
        if (lVar1 != 0) {
          iVar4 = iVar4 + 1;
          FUN_1401b0960(lVar1 + 8);
          FUN_1401b0960(lVar1 + 8);
          FUN_1401ae370(lVar1 + 8,0,0x900);
          FUN_1401b6700(lVar1);
          *plVar3 = 0;
          DAT_14097604c = DAT_14097604c + -1;
        }
        plVar3 = plVar3 + 1;
      } while (iVar4 < iVar2);
    }
    FUN_1401b6e70(&DAT_14092dd48);
    FUN_1401b6d00(&DAT_14092dd48);
    DAT_14092dd40 = 0;
    return 0;
  }
  return 0xffffffff;
}


