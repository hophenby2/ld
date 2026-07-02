// Function: FUN_1401ae2f0 @ 1401ae2f0
// Decompile completed: true

void FUN_1401ae2f0(longlong param_1,undefined1 *param_2,longlong param_3)

{
  if (param_3 != 0) {
    param_1 = param_1 - (longlong)param_2;
    do {
      param_2[param_1] = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


