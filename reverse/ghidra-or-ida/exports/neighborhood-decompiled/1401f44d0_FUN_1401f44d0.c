// Function: FUN_1401f44d0 @ 1401f44d0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1401f44d0(int param_1,int param_2,undefined8 param_3,int param_4,undefined8 param_5,int param_6,
             int param_7,int param_8)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [2];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_a8;
  iVar2 = 0;
  local_70 = param_5;
  lVar4 = (longlong)param_1;
  if (param_7 == 0x2a) {
    iVar2 = 4;
    iVar3 = 1;
  }
  else if (param_7 == 0x39) {
    iVar2 = 2;
    iVar3 = 0;
  }
  else {
    local_78._0_4_ = (int)param_3;
    iVar3 = (int)local_78;
  }
  param_4 = param_4 * *(int *)(&DAT_1404b00c8 + lVar4 * 4);
  local_78 = param_3;
  FUN_1401f4a80(param_4);
  FUN_1401f4920(iVar2 * param_6,param_7);
  local_88 = local_68;
  local_80 = 0;
  FUN_14021d030(DAT_140c592a8,0,4);
  FUN_1401ae2f0(local_68[0],local_78,(longlong)param_4);
  FUN_14021d280(DAT_140c592a8,0,0);
  local_80 = 0;
  local_88 = local_68;
  FUN_14021d030((&DAT_140c592b8)[iVar3],0,4);
  FUN_1401ae2f0(local_68[0],local_70,(longlong)(iVar2 * param_6));
  FUN_14021d280((&DAT_140c592b8)[iVar3],0,0);
  if ((DAT_140ca59d8 != 0) && ((DAT_140c71250 != param_2 || (DAT_140c49268 != 0)))) {
    DAT_140c71250 = param_2;
    FUN_14021cf90(param_2);
  }
  lVar1 = (&DAT_140c49150)[lVar4];
  if ((DAT_140ca59d8 != 0) && ((DAT_140c713e0 != lVar1 || (DAT_140c49268 != 0)))) {
    if (lVar1 != 0) {
      FUN_14021cf70(lVar1);
    }
    DAT_140c491d4 = 1;
    DAT_140c713e0 = lVar1;
  }
  if (param_8 != 0) {
    if (param_1 == 5) {
      iVar2 = FUN_14020bd10();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
    }
    else {
      lVar1 = (&DAT_140c3e370)[lVar4];
      if (((DAT_140c713b0 != lVar1) || (DAT_140c49268 != 0)) && (DAT_140ca59d8 != 0)) {
        FUN_14021d4b0(lVar1,0,0);
        DAT_140c713a8 = 1;
        DAT_140c713b0 = lVar1;
      }
      if (DAT_140c713b8 != 0) {
        FUN_1401f66f0();
      }
    }
  }
  FUN_1401f8d60(DAT_140c592a8,*(int *)(&DAT_1404b00c8 + lVar4 * 4));
  lVar4 = (&DAT_140c592b8)[iVar3];
  if (((DAT_140c713d0 != lVar4) || (DAT_140c49268 != 0)) && (DAT_140ca59d8 != 0)) {
    if (lVar4 != 0) {
      FUN_14021cf50(lVar4,param_7,0);
    }
    DAT_140c713d8 = param_7;
    DAT_140c713d0 = lVar4;
  }
  FUN_1401fa0f0();
  FUN_14021ced0(param_6,0,0);
  DAT_1407cd8f4 = DAT_1407cd8f4 + 1;
  return 0;
}


