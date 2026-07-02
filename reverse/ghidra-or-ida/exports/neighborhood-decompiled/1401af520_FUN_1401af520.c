// Function: FUN_1401af520 @ 1401af520
// Decompile completed: true

void FUN_1401af520(longlong param_1,int *param_2,undefined8 param_3,int param_4)

{
  if (param_1 != 0) {
    *(short *)(*param_2 + param_1) = (short)param_4 + 2;
    FUN_1401ae2f0(param_1 + 2 + (longlong)*param_2,param_3,(longlong)param_4);
    *param_2 = *param_2 + param_4 + 2;
    return;
  }
  *param_2 = *param_2 + param_4 + 2;
  return;
}


