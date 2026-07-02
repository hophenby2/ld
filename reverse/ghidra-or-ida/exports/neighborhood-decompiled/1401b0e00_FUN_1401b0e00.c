// Function: FUN_1401b0e00 @ 1401b0e00
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1401b0e00(longlong param_1,longlong param_2,longlong param_3,ulonglong param_4,longlong param_5,
             ulonglong param_6)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  longlong local_68;
  int local_60 [2];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_98;
  local_68 = param_5;
  iVar2 = 0;
  iVar4 = 0;
  iVar7 = -1;
  uVar3 = FUN_1401c4e50(param_2,*(undefined4 *)(param_1 + 0x40),local_60);
  iVar1 = (int)uVar3;
  while (iVar1 != 0) {
    if (((uint)uVar3 == 0x5c) ||
       (((uint)uVar3 < 0x3b && ((0x400800000000001U >> (uVar3 & 0x3f) & 1) != 0)))) {
      iVar2 = local_60[0];
      iVar7 = iVar4;
    }
    iVar4 = iVar4 + local_60[0];
    uVar3 = FUN_1401c4e50(iVar4 + param_2,*(undefined4 *)(param_1 + 0x40),local_60);
    param_5 = local_68;
    iVar1 = (int)uVar3;
  }
  if (param_3 != 0) {
    if (iVar7 == -1) {
      iVar2 = thunk_FUN_1401c4e80(*(undefined4 *)(param_1 + 0x40));
      uVar3 = param_4;
      lVar6 = param_2;
    }
    else {
      uVar5 = (ulonglong)(iVar7 + iVar2);
      if (param_4 <= uVar5) goto LAB_1401b0eea;
      iVar2 = thunk_FUN_1401c4e80(*(undefined4 *)(param_1 + 0x40));
      uVar3 = param_4 - uVar5;
      lVar6 = uVar5 + param_2;
    }
    local_78 = (undefined4)(uVar3 / (ulonglong)(longlong)iVar2);
    FUN_1401bae90(*(undefined4 *)(param_1 + 0x40),param_3,param_4,lVar6);
  }
LAB_1401b0eea:
  if (param_5 != 0) {
    if (iVar7 != -1) {
      lVar6 = (longlong)iVar7;
      if (param_6 <= lVar6 + 1U) {
        return 0;
      }
      FUN_1401ae2f0(param_5,param_2,lVar6);
      param_5 = lVar6 + param_5;
      param_6 = 0x7fffffff;
    }
    thunk_FUN_1401c5940(0,*(undefined4 *)(param_1 + 0x40),param_5,param_6);
  }
  return 0;
}


