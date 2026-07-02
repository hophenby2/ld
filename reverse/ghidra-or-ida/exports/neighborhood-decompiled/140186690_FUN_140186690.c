// Function: FUN_140186690 @ 140186690
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140186690(void)

{
  undefined1 auStack_68 [32];
  undefined1 local_48 [4];
  int local_44;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined2 local_24;
  undefined1 local_22 [4];
  int local_1e;
  ulonglong local_10;
  
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_68;
  if (DAT_140845104 == 0) {
    return 0xffffffff;
  }
  local_34 = 0x20001;
  local_30 = 0xac44;
  local_24 = 0;
  local_28 = 0x100004;
  local_2c = 0x2b110;
  FUN_1401ae2f0(local_48,&DAT_1404a91c8,4);
  local_44 = (local_28 & 0xffff) * DAT_140845108 + 0x26;
  FUN_1401ae2f0(local_40,&DAT_1404a91d0,4);
  FUN_1401ae2f0(local_3c,&DAT_1404a91d8,4);
  local_38 = 0x12;
  FUN_1401ae2f0(local_22,&DAT_1404a91e0,4);
  local_1e = (local_28 & 0xffff) * DAT_140845108;
  thunk_FUN_1401b9630(DAT_140845110,0,0);
  thunk_FUN_1401b96b0(DAT_140845110,local_48,0x2e,0);
  thunk_FUN_1401b9530(DAT_140845110);
  DAT_140845110 = 0;
  DAT_140845104 = 0;
  return 0;
}


