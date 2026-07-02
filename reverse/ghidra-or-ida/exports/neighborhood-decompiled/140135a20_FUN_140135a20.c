// Function: FUN_140135a20 @ 140135a20
// Decompile completed: true

ulonglong FUN_140135a20(undefined8 param_1,ulonglong param_2,ulonglong param_3,longlong *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = param_4[2];
  if (lVar1 == param_4[1]) {
    param_3 = 0;
    *(undefined4 *)(param_4 + 3) = 1;
  }
  else {
    uVar2 = param_4[1] - lVar1;
    if (uVar2 <= param_2 * param_3 && param_2 * param_3 - uVar2 != 0) {
      param_3 = uVar2 / param_2;
    }
    if (param_3 == 0) {
      if (uVar2 != 0) {
        FUN_1401ae2f0(param_1,*param_4 + lVar1,uVar2);
        param_4[2] = param_4[2] + uVar2;
        param_3 = 1;
      }
    }
    else {
      FUN_1401ae2f0(param_1,*param_4 + lVar1,param_2 * param_3);
      param_4[2] = param_4[2] + param_2 * param_3;
    }
    *(undefined4 *)(param_4 + 3) = 0;
  }
  return param_3;
}


