// Function: FUN_1400f6fb0 @ 1400f6fb0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400f6fb0(void)

{
  longlong lVar1;
  undefined1 auStack_38 [32];
  FILE *local_18;
  ulonglong local_10;
  
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_38;
  DAT_140e418c8 = 0;
  DAT_140e45fac = 0;
  DAT_140e45274 = 0;
  DAT_140e46064 = 0;
  DAT_140e46014 = 0;
  DAT_140e46bb4 = 0;
  DAT_140e46bb0 = 0;
  DAT_140e46a20 = 0;
  DAT_140e467fc = 0;
  DAT_140e41b00 = 0;
  _DAT_1407c777c = 0x3f800000;
  lVar1 = DAT_140e46ea0;
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x38);
    FUN_140323ce8();
  }
  DAT_140e46ea0 = 0;
  DAT_140e9fd38 = 0;
  DAT_140e4764c = 0;
  lVar1 = DAT_140e46e90;
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x28);
    FUN_140323ce8();
  }
  DAT_140e46e90 = 0;
  DAT_140e46e98 = 0;
  DAT_140e46c5c = 0;
  FUN_140079b00();
  FUN_14006c420();
  lVar1 = DAT_140e45d78;
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x58);
    FUN_140323ce8();
  }
  DAT_140e45d78 = 0;
  DAT_140e45d28 = 0;
  DAT_140e45d1c = 0;
  lVar1 = DAT_140e47908;
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x238);
    FUN_140323ce8();
  }
  DAT_140e47908 = 0;
  DAT_140e9fd30 = 0;
  fopen_s(&local_18,"save\\save.dat","wb");
  FUN_140327c78(&DAT_140e41b10,0x2730,1,local_18);
  FUN_140323e90(local_18);
  DAT_140e471fc = 0xb4;
  return;
}


