// Function: FUN_14018f230 @ 14018f230
// Decompile completed: true

undefined8 FUN_14018f230(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  longlong lVar6;
  
  iVar2 = FUN_14019e300();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_140988598 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_1409885e8))
     && ((int)(param_1 & 0x3ffff) < DAT_1409885f0)) {
    lVar6 = (ulonglong)(param_1 & 0x3ffff) * 8;
    piVar1 = *(int **)(lVar6 + DAT_1409885a0);
    if ((piVar1 != (int *)0x0) && (*piVar1 << 0x12 == (param_1 & 0x3fc0000))) {
      if (piVar1[6] != 0) {
        if ((piVar1[6] < 2) && (-1 < piVar1[8])) {
          iVar2 = FUN_1401afbe0();
        }
        else {
          iVar2 = FUN_1401b82b0(param_1);
        }
        if (iVar2 < 0) {
          return 0xffffffff;
        }
        if (*(longlong *)(lVar6 + DAT_1409885a0) == 0) {
          return 0xffffffff;
        }
      }
      if (piVar1[0x5ed] == 1) {
        uVar4 = FUN_14018f510(param_1,param_2);
        return uVar4;
      }
      if (param_2 == 0) {
        iVar2 = 0;
        if (0 < piVar1[0x47]) {
          piVar5 = piVar1 + 0x5c;
          do {
            lVar6 = (longlong)iVar2;
            piVar1[lVar6 + 0x48] = 0;
            piVar1[lVar6 + 0x52] = 0;
            if (*piVar5 == 0) {
              return 0xffffffff;
            }
            if ((DAT_140845100 == 0) && (DAT_1408450f8 == 0)) {
              iVar3 = FUN_1401a20a0(piVar5);
            }
            else {
              iVar3 = piVar5[0x16];
            }
            if (iVar3 == -1) {
              return 0xffffffff;
            }
            if (iVar3 != 0) {
              FUN_14018eac0(piVar1 + lVar6 * 0x8e + 0x5c,1);
            }
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 0x8e;
          } while (iVar2 < piVar1[0x47]);
        }
      }
      else if (((DAT_140845100 == 0) && (DAT_1408450f8 == 0)) && (DAT_1408450fc == 0)) {
        iVar2 = 0;
        if (0 < piVar1[0x47]) {
          piVar5 = piVar1 + 0x5c;
          do {
            if (*piVar5 == 0) {
              return 0xffffffff;
            }
            if ((DAT_140845100 == 0) && (DAT_1408450f8 == 0)) {
              iVar3 = FUN_1401a20a0(piVar5);
            }
            else {
              iVar3 = piVar5[0x16];
            }
            if (iVar3 == -1) {
              return 0xffffffff;
            }
            if (iVar3 != 0) {
              FUN_14018eac0(piVar1 + (longlong)iVar2 * 0x8e + 0x5c,0);
              FUN_14018e080(piVar1 + (longlong)iVar2 * 0x8e + 0x5c);
            }
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 0x8e;
          } while (iVar2 < piVar1[0x47]);
        }
      }
      else {
        iVar2 = 0;
        if (0 < piVar1[0x47]) {
          piVar5 = piVar1 + 0x5c;
          do {
            if (*piVar5 == 0) {
              return 0xffffffff;
            }
            if ((DAT_140845100 == 0) && (DAT_1408450f8 == 0)) {
              iVar3 = FUN_1401a20a0(piVar5);
            }
            else {
              iVar3 = piVar5[0x16];
            }
            if (iVar3 == -1) {
              return 0xffffffff;
            }
            if (iVar3 != 0) {
              piVar1[(longlong)iVar2 * 0x8e + 0x79] = 0;
            }
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 0x8e;
          } while (iVar2 < piVar1[0x47]);
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}


