// Function: FUN_140134b10 @ 140134b10
// Decompile completed: true

ulonglong FUN_140134b10(int param_1,int param_2,int param_3,int param_4,int param_5,float param_6,
                       float param_7)

{
  double dVar1;
  ulonglong uVar2;
  double dVar3;
  
  dVar3 = DAT_14053ac08;
  uVar2 = (ulonglong)(uint)param_7;
  if (param_2 != param_3) {
    if (param_1 < param_2) {
      uVar2 = (ulonglong)(uint)param_6;
    }
    else if (param_1 < param_3) {
      dVar1 = (double)FUN_140332d90((DAT_14053ac08 / (double)((param_3 - param_2) * 4)) *
                                    ((double)param_1 - (double)param_2) * DAT_14053a020 *
                                    DAT_140539d28);
      dVar1 = dVar1 * (double)(param_7 - param_6);
      uVar2 = CONCAT44((int)((ulonglong)dVar1 >> 0x20),(float)dVar1 + param_6);
    }
  }
  if (param_4 != param_5) {
    if (param_1 < param_4) {
      if (param_1 < param_5) {
        return uVar2;
      }
    }
    else if (param_1 < param_5) {
      dVar3 = (double)FUN_140332d90(((double)param_1 - (double)(param_4 * 2 - param_5)) *
                                    (dVar3 / (double)((param_5 - param_4) * 4)) * DAT_14053a020 *
                                    DAT_140539d28);
      dVar3 = dVar3 * (double)(param_7 - param_6);
      return CONCAT44((int)((ulonglong)dVar3 >> 0x20),(float)dVar3 + param_6);
    }
    uVar2 = (ulonglong)(uint)param_6;
  }
  return uVar2;
}


