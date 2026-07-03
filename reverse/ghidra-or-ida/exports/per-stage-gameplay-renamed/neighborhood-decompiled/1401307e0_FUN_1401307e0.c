// Function: FUN_1401307e0 @ 1401307e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401307e0(undefined4 param_1)

{
  double dVar1;
  bool bVar2;
  double dVar3;
  
  bVar2 = false;
  if (0x8b < DAT_140e418c8) {
    dVar3 = (double)DAT_140e418c8;
    dVar1 = (double)FUN_140332d90(SUB84((dVar3 - _DAT_14053a5b0) * DAT_14053a9d8 * DAT_14053a020 *
                                        DAT_140539d28,0));
    dVar1 = dVar1 * DAT_14053b1c8;
    dVar3 = (double)FUN_140332d90(SUB84((dVar3 - 0.0) * DAT_14053a930 * DAT_14053a020 *
                                        DAT_140539d28,0));
    FUN_1400c8410(DAT_140e41934,0x6f,1,(float)(dVar3 * DAT_14053a018) + 0.0 + _DAT_14053af88,
                  DAT_14053aef4,0,_DAT_14053bac0,_UNK_14053bac8,0xff,0xff,0xff,0x80 - (int)dVar1,1,0
                 );
  }
  if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (0x8b < DAT_140e418c8)) {
    DAT_140e467fc = DAT_140e467c8;
    bVar2 = true;
  }
  if ((DAT_140e467c8 == 0) && (DAT_140e45270 == 0x15)) {
    DAT_140e467fc = 0;
  }
  if (bVar2) {
    DAT_140e418c8 = 99;
    DAT_140e46804 = param_1;
    FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  return;
}


