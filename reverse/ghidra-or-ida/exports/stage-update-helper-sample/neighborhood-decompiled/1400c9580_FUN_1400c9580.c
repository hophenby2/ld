// Function: FUN_1400c9580 @ 1400c9580
// Decompile completed: true

undefined4 FUN_1400c9580(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined4 local_res20 [2];
  
  uVar5 = 0;
  if (0 < (int)param_4) {
    iVar1 = 0;
    iVar2 = (param_1 - param_2) % (int)(param_3 * param_4);
    puVar3 = local_res20;
    uVar4 = (ulonglong)param_4;
    do {
      puVar3 = puVar3 + 2;
      if ((iVar1 <= iVar2) && (iVar2 < iVar1 + param_3)) {
        uVar5 = *puVar3;
      }
      iVar1 = iVar1 + param_3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return uVar5;
}


