// Function: FUN_140478f80 @ 140478f80
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140478f80(undefined8 param_1,longlong param_2,int *param_3,undefined4 param_4,
                  undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  int local_98 [9];
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_d8;
  local_a0 = param_5;
  local_a8 = param_4;
  FUN_1401ae2f0(local_98,param_3);
  uVar2 = local_a0;
  iVar6 = 0;
  iVar7 = 0;
  iVar5 = 0;
  iVar9 = 0;
  lVar8 = 0;
  lVar10 = 0;
  lVar11 = 0;
  lVar3 = 8;
  iVar4 = 1;
  lVar12 = 0;
  do {
    iVar1 = *(int *)((longlong)local_98 + lVar3 + 4);
    if (*(int *)((longlong)local_98 + lVar12 + 4) < iVar1) {
      lVar12 = lVar3;
      iVar7 = iVar4;
    }
    if (iVar1 < *(int *)((longlong)local_98 + lVar11 + 4)) {
      lVar11 = lVar3;
      iVar6 = iVar4;
    }
    if (*(int *)((longlong)local_98 + lVar10) < *(int *)((longlong)local_98 + lVar3)) {
      lVar10 = lVar3;
      iVar5 = iVar4;
    }
    if (*(int *)((longlong)local_98 + lVar3) < *(int *)((longlong)local_98 + lVar8)) {
      lVar8 = lVar3;
      iVar9 = iVar4;
    }
    iVar4 = iVar4 + 1;
    lVar3 = lVar3 + 8;
  } while (iVar4 < 4);
  iVar4 = local_98[(longlong)iVar9 * 2] + -2;
  iVar9 = local_98[(longlong)iVar6 * 2 + 1] + -2;
  iVar6 = local_98[(longlong)iVar5 * 2] + 4;
  if (local_98[(longlong)iVar5 * 2] + 4 < iVar4) {
    iVar6 = iVar4;
  }
  iVar5 = local_98[(longlong)iVar7 * 2 + 1] + 4;
  if (local_98[(longlong)iVar7 * 2 + 1] + 4 < iVar9) {
    iVar5 = iVar9;
  }
  iVar7 = DAT_140c28a80;
  if ((iVar5 <= DAT_140c28a80) && (iVar7 = iVar5, iVar5 < DAT_140c28a78)) {
    iVar7 = DAT_140c28a78;
  }
  iVar5 = DAT_140c28a80;
  if ((iVar9 <= DAT_140c28a80) && (iVar5 = iVar9, iVar9 < DAT_140c28a78)) {
    iVar5 = DAT_140c28a78;
  }
  iVar9 = DAT_140c28a7c;
  if ((iVar6 <= DAT_140c28a7c) && (iVar9 = iVar6, iVar6 < DAT_140c28a74)) {
    iVar9 = DAT_140c28a74;
  }
  iVar6 = DAT_140c28a7c;
  if ((iVar4 <= DAT_140c28a7c) && (iVar6 = iVar4, iVar4 < DAT_140c28a74)) {
    iVar6 = DAT_140c28a74;
  }
  if ((iVar6 != iVar9) && (iVar5 != iVar7)) {
    local_6c = *(undefined4 *)(param_2 + 8);
    local_98[0] = *param_3;
    local_98[6] = *(undefined4 *)(param_2 + 4);
    local_98[1] = param_3[1];
    local_98[4] = param_3[2];
    local_98[5] = param_3[3];
    local_98[8] = param_3[4];
    local_74 = param_3[5];
    local_68 = param_3[6];
    local_64 = param_3[7];
    local_b0 = 0;
    local_98[2] = 0;
    local_98[3] = 0;
    local_98[7] = 0;
    local_70 = 0;
    local_b8 = local_a0;
    local_60 = local_98[6];
    local_5c = local_6c;
    FUN_1403bd9d0(param_1,param_2,local_98,local_a8);
    local_b0 = 0;
    local_b8 = uVar2;
    FUN_1403bd9d0(param_1,param_2,local_98 + 4,local_a8);
  }
  return;
}


