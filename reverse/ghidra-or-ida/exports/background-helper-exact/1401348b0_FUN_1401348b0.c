// Function: FUN_1401348b0 @ 1401348b0
// Decompile completed: true

int FUN_1401348b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  dVar4 = DAT_14053ac08;
  iVar1 = param_7;
  if (((param_2 != param_3) && (iVar1 = param_6, param_2 <= param_1)) &&
     (iVar1 = param_7, param_1 < param_3)) {
    dVar3 = (double)FUN_140332d90((DAT_14053ac08 / (double)((param_3 - param_2) * 4)) *
                                  ((double)param_1 - (double)param_2) * DAT_14053a020 *
                                  DAT_140539d28);
    iVar1 = (int)(dVar3 * (double)(param_7 - param_6)) + param_6;
  }
  iVar2 = iVar1;
  if (param_4 != param_5) {
    iVar2 = param_6;
    if (param_1 < param_4) {
      if (param_1 < param_5) {
        return iVar1;
      }
    }
    else if (param_1 < param_5) {
      dVar4 = (double)FUN_140332d90(((double)param_1 - (double)(param_4 * 2 - param_5)) *
                                    (dVar4 / (double)((param_5 - param_4) * 4)) * DAT_14053a020 *
                                    DAT_140539d28);
      return (int)(dVar4 * (double)(param_7 - param_6)) + param_6;
    }
  }
  return iVar2;
}


