// Function: FUN_140184700 @ 140184700
// Decompile completed: true

undefined8 FUN_140184700(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  int *piVar5;
  int iVar6;
  double dVar7;
  
  iVar1 = FUN_14019e300();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_140988598 != 0) && (-1 < (int)param_2)) && ((param_2 & 0x7c000000) == DAT_1409885e8))
     && ((int)(param_2 & 0x3ffff) < DAT_1409885f0)) {
    piVar3 = *(int **)(DAT_1409885a0 + (ulonglong)(param_2 & 0x3ffff) * 8);
    if ((piVar3 != (int *)0x0) && (*piVar3 << 0x12 == (param_2 & 0x3fc0000))) {
      if (piVar3[6] != 0) {
        if ((piVar3[6] < 2) && (-1 < piVar3[8])) {
          iVar1 = FUN_1401afbe0();
        }
        else {
          iVar1 = FUN_1401b82b0(param_2);
        }
        if (iVar1 < 0) {
          return 0xffffffff;
        }
        if (*(longlong *)(DAT_1409885a0 + (ulonglong)(param_2 & 0x3ffff) * 8) == 0) {
          return 0xffffffff;
        }
      }
      iVar6 = 0;
      iVar1 = 0;
      if (-1 < param_1) {
        iVar1 = param_1;
      }
      if (iVar1 == 0) {
        iVar2 = -10000;
      }
      else {
        if (DAT_140845098 == 0) {
          dVar7 = (double)thunk_FUN_140331140((double)iVar1 / DAT_14053a5f8);
          dVar7 = dVar7 * DAT_14053a380;
        }
        else {
          dVar7 = (double)thunk_FUN_140331140((double)iVar1 / DAT_14053a5f8);
          dVar7 = dVar7 * DAT_14053a1e8;
        }
        iVar2 = (int)(dVar7 * DAT_14053a460);
        if (iVar2 < -10000) {
          iVar2 = -10000;
        }
      }
      if (0 < piVar3[0x47]) {
        piVar5 = piVar3 + 0x5c;
        do {
          if (*piVar5 != 0) {
            piVar5[2] = iVar2;
            piVar5[3] = iVar2;
            piVar5[4] = iVar2;
            piVar5[5] = iVar2;
            piVar5[6] = iVar2;
            piVar5[7] = iVar2;
            piVar5[8] = iVar2;
            piVar5[9] = iVar2;
            FUN_14018e190(piVar5);
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 0x8e;
        } while (iVar6 < piVar3[0x47]);
      }
      piVar3 = piVar3 + 0xb56;
      lVar4 = 8;
      do {
        piVar3[-8] = iVar2;
        *piVar3 = iVar1;
        piVar3 = piVar3 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      return 0;
    }
  }
  return 0xffffffff;
}


