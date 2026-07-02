// Function: FUN_1401af4b0 @ 1401af4b0
// Decompile completed: true

void FUN_1401af4b0(longlong param_1,int *param_2,short *param_3)

{
  short sVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (param_3 != (short *)0x0) {
    sVar1 = *param_3;
    while (sVar1 != 0) {
      uVar2 = uVar2 + 1;
      sVar1 = param_3[uVar2];
    }
    uVar2 = (ulonglong)((int)uVar2 * 2 + 2);
  }
  if ((param_1 != 0) && (*(short *)(*param_2 + param_1) = (short)uVar2 + 2, (int)uVar2 != 0)) {
    FUN_1401ae2f0(param_1 + 2 + (longlong)*param_2,param_3,uVar2);
  }
  *param_2 = *param_2 + (int)uVar2 + 2;
  return;
}


