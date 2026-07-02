// Function: FUN_1402456a0 @ 1402456a0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1402456a0(longlong param_1,int param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_1407c6b00 ^ (ulonglong)auStack_58;
  if (**(longlong **)(param_1 + 0x98) != 0) {
    local_38 = 0;
    iVar1 = FUN_140222d50(**(longlong **)(param_1 + 0x98),*(int *)(param_1 + 0x84) * param_2,
                          *(int *)(param_1 + 0x84) * param_4,&local_28);
    if (iVar1 != 0) {
      FUN_1401594b0(&DAT_1404e8198);
      return 0xffffffff;
    }
    FUN_1401ae2f0(local_28,param_3,(longlong)(*(int *)(param_1 + 0x84) * param_4));
    FUN_14021ee40(**(undefined8 **)(param_1 + 0x98));
  }
  return 0;
}


