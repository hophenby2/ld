// Function: FUN_14016a870 @ 14016a870
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_14016a870(undefined1 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_688 [32];
  longlong local_668;
  int local_660;
  int local_658;
  int local_654;
  undefined4 local_650;
  undefined1 local_648 [512];
  undefined1 local_448 [1024];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_688;
  puVar6 = (undefined1 *)0x0;
  local_654 = param_2;
  local_650 = param_4;
  if ((param_3 == -2) && (param_3 = DAT_14081857c, DAT_14081857c < 1)) {
    FUN_14016c720();
    param_3 = DAT_140818578;
  }
  puVar4 = puVar6;
  if (-1 < param_2) {
    iVar2 = FUN_14016af50(param_3);
    if (iVar2 < 0) {
      return 0xffffffff;
    }
    iVar1 = thunk_FUN_1401c4e80(iVar2);
    iVar2 = FUN_1401ba9b0(iVar2,param_1);
    local_654 = param_2;
    if (iVar2 < param_2) {
      local_654 = iVar2;
    }
    iVar2 = local_654 * iVar1;
    if (iVar2 + 0x10U < 0x200) {
      puVar7 = local_648;
    }
    else {
      puVar4 = (undefined1 *)
               FUN_1401b6390((longlong)(int)(iVar2 + 0x10U),
                             "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x3540);
      puVar7 = puVar4;
      if (puVar4 == (undefined1 *)0x0) {
        return 0xffffffff;
      }
    }
    FUN_1401ae2f0(puVar7,param_1,(longlong)iVar2);
    FUN_1401ae370(puVar7 + iVar2,0,(longlong)(iVar1 * 8));
    param_1 = puVar7;
  }
  if ((param_3 == -2) && (param_3 = DAT_14081857c, DAT_14081857c < 1)) {
    FUN_14016c720();
    param_3 = DAT_140818578;
  }
  iVar2 = FUN_14016af50(param_3);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  uVar5 = FUN_1401ba9b0(iVar2,param_1);
  if (uVar5 < 0x1f9) {
    puVar7 = local_448;
  }
  else {
    puVar6 = (undefined1 *)
             FUN_1401b6390(uVar5 * 2 + 0x20,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                           0x3540);
    puVar7 = puVar6;
    if (puVar6 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
  }
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  local_658 = DAT_1408ab148;
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  iVar1 = DAT_1408ab148;
  local_668 = uVar5 * 2 + 0x20;
  local_660 = local_658;
  FUN_1401c0470(param_1,0xffffffff,iVar2,puVar7);
  thunk_FUN_1401c4e80(iVar1);
  local_668 = CONCAT44(local_668._4_4_,local_650);
  uVar3 = FUN_14016aad0(puVar7,0,local_654,param_3);
  if (puVar6 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar6);
  }
  if (puVar4 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar4);
    return uVar3;
  }
  return uVar3;
}


