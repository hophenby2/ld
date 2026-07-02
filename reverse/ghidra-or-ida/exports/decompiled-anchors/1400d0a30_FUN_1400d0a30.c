// Function: FUN_1400d0a30 @ 1400d0a30
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400d0a30(void)

{
  undefined1 auStack_38 [32];
  FILE *local_18;
  ulonglong local_10;
  
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_38;
  fopen_s(&local_18,"save\\save.dat","wb");
  FUN_140327c78(&DAT_140e41b10,0x2730,1,local_18);
  FUN_140323e90(local_18);
  DAT_140e471fc = 0xb4;
  return;
}


