// Function: FUN_140135060 @ 140135060
// Decompile completed: true

int * FUN_140135060(int *param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  int local_38;
  int iStack_34;
  undefined1 local_28 [16];
  undefined1 local_18 [16];

  param_2 = param_2 / param_3;
  puVar3 = (undefined8 *)FUN_140134fa0(local_28,(param_2 + 1) % 7 + 1);
  uVar1 = *puVar3;
  iVar6 = *(int *)(puVar3 + 1);
  puVar3 = (undefined8 *)FUN_140134fa0(local_18,param_2 % 7 + 1);
  dVar8 = (double)param_3;
  iVar2 = *(int *)(puVar3 + 1);
  iVar4 = (int)*puVar3;
  local_38 = (int)uVar1;
  iVar5 = (int)((ulonglong)*puVar3 >> 0x20);
  dVar7 = (double)(DAT_140e44acc % param_3);
  *param_1 = (int)((double)iVar4 - ((double)(iVar4 - local_38) / dVar8) * dVar7);
  iStack_34 = (int)((ulonglong)uVar1 >> 0x20);
  param_1[1] = (int)((double)iVar5 - ((double)(iVar5 - iStack_34) / dVar8) * dVar7);
  param_1[2] = (int)((double)iVar2 - ((double)(iVar2 - iVar6) / dVar8) * dVar7);
  return param_1;
}
