// Function: FUN_140157840 @ 140157840
// Decompile completed: true

int FUN_140157840(int param_1,undefined8 param_2,int param_3,uint param_4)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  
  if ((((DAT_14098b380 != 0) && (-1 < (int)param_4)) && ((param_4 & 0x7c000000) == DAT_14098b3d0))
     && ((int)(param_4 & 0x3ffff) < DAT_14098b3d8)) {
    lVar1 = (ulonglong)(param_4 & 0x3ffff) * 8;
    piVar2 = *(int **)(lVar1 + DAT_14098b388);
    if ((piVar2 != (int *)0x0) && (*piVar2 << 0x12 == (param_4 & 0x3fc0000))) {
      if (piVar2[6] != 0) {
        if ((piVar2[6] < 2) && (-1 < piVar2[8])) {
          iVar3 = FUN_1401afbe0();
        }
        else {
          iVar3 = FUN_1401b82b0(param_4);
        }
        if (iVar3 < 0) {
          return -1;
        }
        if (*(longlong *)(lVar1 + DAT_14098b388) == 0) {
          return -1;
        }
      }
      if ((param_1 + param_3 <= piVar2[0x22]) && (-1 < param_1)) {
        FUN_1401ae2f0((longlong)(piVar2[0x21] * param_1) + *(longlong *)(piVar2 + 0x24),param_2,
                      (longlong)(piVar2[0x21] * param_3));
        iVar3 = FUN_1401ef020(piVar2,param_1,param_2,param_3);
        return (-1 < iVar3) - 1;
      }
    }
  }
  return -1;
}


