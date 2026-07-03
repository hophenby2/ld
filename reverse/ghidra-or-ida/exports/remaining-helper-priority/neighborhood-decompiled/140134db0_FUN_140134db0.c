// Function: FUN_140134db0 @ 140134db0
// Decompile completed: true

ulonglong FUN_140134db0(uint param_1,double param_2,double param_3)

{
  ulonglong in_RAX;
  uint uVar1;
  uint uVar2;
  
  if (param_2 != param_3) {
    uVar2 = (param_1 >> 0x1e ^ param_1) * 0x6c078965 + 1;
    uVar1 = uVar2 * 0x800 ^ uVar2;
    DAT_140e9fd10 = (uVar2 >> 0x1e ^ uVar2) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar1) >> 8 ^ DAT_140e9fd18 ^ uVar1;
    return (ulonglong)DAT_140e9fd1c /
           (ulonglong)(((int)(param_3 * DAT_14053a460) - (int)(param_2 * DAT_14053a460)) + 1);
  }
  return in_RAX;
}


