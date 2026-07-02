// Function: FUN_140212220 @ 140212220
// Decompile completed: true

undefined8 FUN_140212220(longlong *param_1,longlong param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((int)param_1[2] < param_3) {
    return 0xffffffff;
  }
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  if ((int)param_1[1] == iVar1) {
    *(undefined4 *)(param_1 + 1) = 0;
  }
  if (*(int *)((longlong)param_1 + 0xc) == iVar1) {
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  }
  iVar2 = (int)param_1[1];
  if (iVar1 < iVar2 + param_3) {
    FUN_1401ae2f0(param_2,(longlong)iVar2 + *param_1,(longlong)(iVar1 - iVar2));
    FUN_1401ae2f0((*(int *)((longlong)param_1 + 0x14) - (int)param_1[1]) + param_2,*param_1,
                  (longlong)(((int)param_1[1] - *(int *)((longlong)param_1 + 0x14)) + param_3));
    if (param_4 != 0) {
      return 0;
    }
    *(int *)(param_1 + 1) = (int)param_1[1] + (param_3 - *(int *)((longlong)param_1 + 0x14));
  }
  else {
    FUN_1401ae2f0(param_2,(longlong)iVar2 + *param_1,(longlong)param_3);
    if (param_4 != 0) {
      return 0;
    }
    *(int *)(param_1 + 1) = (int)param_1[1] + param_3;
  }
  *(int *)(param_1 + 2) = (int)param_1[2] - param_3;
  return 0;
}


