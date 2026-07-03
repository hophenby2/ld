// Function: FUN_1400709b0 @ 1400709b0
// Decompile completed: true

void FUN_1400709b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  short param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,
                  uint param_9,int param_10,undefined4 param_11)

{
  int iVar1;
  short sVar2;
  
  if (param_9 == 1) {
    FUN_14006c2f0();
  }
  else {
    iVar1 = 0;
    if (param_10 == 0x10000) {
      if (0 < (int)param_9) {
        do {
          FUN_14006c2f0(param_1,param_2,param_3,param_4,
                        (short)(0x10000 / param_9) * (short)iVar1 + param_5,param_6,param_7,param_8,
                        param_11);
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)param_9);
      }
    }
    else {
      sVar2 = 0;
      if (0 < param_10) {
        sVar2 = (short)(param_10 / (int)(param_9 - 1));
      }
      if (0 < (int)param_9) {
        do {
          FUN_14006c2f0(param_1,param_2,param_3,param_4,
                        (sVar2 * (short)iVar1 - (short)(param_10 / 2)) + param_5,param_6,param_7,
                        param_8,param_11);
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)param_9);
      }
    }
  }
  return;
}


