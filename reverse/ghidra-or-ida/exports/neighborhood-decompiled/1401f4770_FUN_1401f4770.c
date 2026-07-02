// Function: FUN_1401f4770 @ 1401f4770
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401f4770(int param_1,int param_2,undefined8 param_3,int param_4,int param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 local_68 [2];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_98;
  lVar3 = (longlong)param_1;
  iVar2 = *(int *)(&DAT_1404b00c8 + lVar3 * 4);
  FUN_1401f4a80(iVar2 * param_4);
  local_78 = local_68;
  local_70 = 0;
  FUN_14021d030(DAT_140c592a8,0,4);
  FUN_1401ae2f0(local_68[0],param_3,(longlong)(iVar2 * param_4));
  FUN_14021d280(DAT_140c592a8,0,0);
  if ((DAT_140ca59d8 != 0) && ((DAT_140c71250 != param_2 || (DAT_140c49268 != 0)))) {
    DAT_140c71250 = param_2;
    FUN_14021cf90(param_2);
  }
  lVar1 = (&DAT_140c49150)[lVar3];
  if ((DAT_140ca59d8 != 0) && ((DAT_140c713e0 != lVar1 || (DAT_140c49268 != 0)))) {
    if (lVar1 != 0) {
      FUN_14021cf70(lVar1);
    }
    DAT_140c491d4 = 1;
    DAT_140c713e0 = lVar1;
  }
  if (param_5 != 0) {
    if (param_1 == 5) {
      iVar2 = FUN_14020bd10();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
    }
    else {
      lVar1 = (&DAT_140c3e370)[lVar3];
      if (((DAT_140c713b0 != lVar1) || (DAT_140c49268 != 0)) && (DAT_140ca59d8 != 0)) {
        FUN_14021d4b0(lVar1,0,0);
        DAT_140c713a8 = 1;
        DAT_140c713b0 = lVar1;
      }
    }
  }
  FUN_1401f8d60(DAT_140c592a8,*(undefined4 *)(&DAT_1404b00c8 + lVar3 * 4));
  FUN_1401fa0f0();
  FUN_14021ceb0(param_4,0);
  DAT_1407cd8f4 = DAT_1407cd8f4 + 1;
  return 0;
}


