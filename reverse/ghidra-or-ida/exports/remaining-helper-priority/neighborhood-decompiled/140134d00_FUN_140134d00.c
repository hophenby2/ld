// Function: FUN_140134d00 @ 140134d00
// Decompile completed: true

int FUN_140134d00(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == param_3) {
    return param_2;
  }
  uVar2 = (param_1 >> 0x1e ^ param_1) * 0x6c078965 + 1;
  uVar1 = uVar2 * 0x800 ^ uVar2;
  DAT_140e9fd10 = (uVar2 >> 0x1e ^ uVar2) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar1) >> 8 ^ DAT_140e9fd18 ^ uVar1;
  return param_2 + DAT_140e9fd1c % ((param_3 - param_2) + 1U);
}


