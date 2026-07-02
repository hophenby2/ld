// Function: dxarchive_set_key_candidate @ 1401b23b0
// Decompile completed: true

undefined8 dxarchive_set_key_candidate(longlong param_1)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    DAT_140976008 = 0;
    return 0;
  }
  DAT_140976008 = 1;
  uVar1 = FUN_1401ae820();
  if (0x3f < uVar1) {
    FUN_1401ae2f0(&DAT_14097600c,param_1,0x3f);
    DAT_14097604b = 0;
    return 0;
  }
  FUN_1401ae790(&DAT_14097600c,param_1);
  return 0;
}


