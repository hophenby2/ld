// Function: FUN_14021ae70 @ 14021ae70
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14021ae70(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_58 [32];
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_1407c6b00 ^ (ulonglong)auStack_58;
  FUN_1401b6dc0(param_1 + 0xd0,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x53d);
  lVar1 = *(longlong *)(param_1 + 0x88);
  while (lVar2 = lVar1, lVar2 != 0) {
    lVar1 = *(longlong *)(lVar2 + 0x48);
    if ((*(byte *)(lVar2 + 0x50) & 1) != 0) {
      FUN_1401ae2f0(local_38,lVar2 + 0x54,0x20);
      (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x10),local_38);
    }
  }
  FUN_1401b6e70(param_1 + 0xd0);
  FUN_1401ae370(param_1,0,0x8418);
  return 0;
}


