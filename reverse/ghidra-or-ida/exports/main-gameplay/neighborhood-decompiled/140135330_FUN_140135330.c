// Function: FUN_140135330 @ 140135330
// Decompile completed: true

undefined8 FUN_140135330(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_140e4759c = 0;
  if ((DAT_140e41928 == 1) && (DAT_140e4680c != 0)) {
    if (DAT_1407c7798 != 10) {
      iVar1 = FUN_140135290(DAT_140e41abc + 0xb,DAT_140e445c0,DAT_140e419b8);
      if (iVar1 != 0) {
        return 0;
      }
      return 1;
    }
    iVar1 = *(int *)(&DAT_140e4332c + ((longlong)DAT_140e445c0 * 0x32 + (longlong)DAT_140e419b8) * 4
                    );
    iVar3 = DAT_140e452f0;
    iVar2 = DAT_140e452f0;
    if (DAT_140e41b00 != 1) {
      iVar3 = DAT_140e44198;
      if (DAT_140e44198 == 0) {
        if (iVar1 < 3) {
          DAT_140e4759c = 0;
          return 1;
        }
        if (iVar1 < 6) {
          iVar2 = 1;
        }
        else if (iVar1 < 8) {
          iVar2 = 2;
        }
        else if (iVar1 < 10) {
          iVar2 = 3;
        }
        else {
          iVar2 = (0xb < iVar1) + 4;
        }
      }
      else {
        iVar2 = DAT_140e44198;
        if (4 < DAT_140e44198 - 1U) {
          DAT_140e4759c = 0;
          return 1;
        }
      }
    }
    iVar1 = 0;
    if (iVar3 < 6) {
      iVar1 = iVar2;
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}


