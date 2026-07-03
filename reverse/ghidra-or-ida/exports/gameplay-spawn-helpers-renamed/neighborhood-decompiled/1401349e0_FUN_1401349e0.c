// Function: FUN_1401349e0 @ 1401349e0
// Decompile completed: true

double FUN_1401349e0(int param_1,int param_2,int param_3,int param_4,int param_5,double param_6,
                    double param_7)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar2 = DAT_14053ac08;
  dVar1 = param_7;
  if (((param_2 != param_3) && (dVar1 = param_6, param_2 <= param_1)) &&
     (dVar1 = param_7, param_1 < param_3)) {
    dVar1 = (double)FUN_140332d90((DAT_14053ac08 / (double)((param_3 - param_2) * 4)) *
                                  ((double)param_1 - (double)param_2) * DAT_14053a020 *
                                  DAT_140539d28);
    dVar1 = dVar1 * (param_7 - param_6) + param_6;
  }
  dVar3 = dVar1;
  if (param_4 != param_5) {
    dVar3 = param_6;
    if (param_1 < param_4) {
      if (param_1 < param_5) {
        return dVar1;
      }
    }
    else if (param_1 < param_5) {
      dVar2 = (double)FUN_140332d90(((double)param_1 - (double)(param_4 * 2 - param_5)) *
                                    (dVar2 / (double)((param_5 - param_4) * 4)) * DAT_14053a020 *
                                    DAT_140539d28);
      return dVar2 * (param_7 - param_6) + param_6;
    }
  }
  return dVar3;
}


