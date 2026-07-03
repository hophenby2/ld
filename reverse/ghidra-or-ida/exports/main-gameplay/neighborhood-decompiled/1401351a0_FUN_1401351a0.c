// Function: FUN_1401351a0 @ 1401351a0
// Decompile completed: true

void FUN_1401351a0(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  
  iVar1 = 0;
  if (0 < param_1) {
    lVar4 = 3;
    lVar3 = (longlong)param_1 * 0x96;
    piVar2 = &DAT_140e41b94 + (longlong)param_1 * 0x96;
    do {
      if (param_2 < 5) {
        if ((0 < (int)(&DAT_140e41ba8)[(int)param_2 + lVar3]) && (iVar1 == 0)) {
          iVar1 = 1;
        }
        if (0 < (int)(&DAT_140e41b94)[(int)param_2 + lVar3]) {
          iVar1 = 2;
        }
      }
      else {
        if ((0 < piVar2[5]) && (iVar1 == 0)) {
          iVar1 = 1;
        }
        if (0 < *piVar2) {
          iVar1 = 2;
        }
        if ((0 < piVar2[6]) && (iVar1 == 0)) {
          iVar1 = 1;
        }
        if (0 < piVar2[1]) {
          iVar1 = 2;
        }
        if ((0 < piVar2[7]) && (iVar1 == 0)) {
          iVar1 = 1;
        }
        if (0 < piVar2[2]) {
          iVar1 = 2;
        }
        if ((0 < piVar2[8]) && (iVar1 == 0)) {
          iVar1 = 1;
        }
        if (0 < piVar2[3]) {
          iVar1 = 2;
        }
      }
      lVar3 = lVar3 + 0x32;
      piVar2 = piVar2 + 0x32;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return;
}


