// Function: FUN_140135290 @ 140135290
// Decompile completed: true

int FUN_140135290(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (&DAT_140e41bbc)[((longlong)param_1 * 3 + (longlong)param_2) * 0x32 + (longlong)param_3];
  iVar3 = DAT_140e452f0;
  iVar2 = DAT_140e452f0;
  if (DAT_140e41b00 != 1) {
    if (DAT_140e44198 == 0) {
      if (iVar1 < 3) {
        iVar2 = 0;
      }
      else if (iVar1 < 6) {
        iVar2 = 1;
      }
      else if (iVar1 < 8) {
        iVar2 = 2;
      }
      else if (iVar1 < 10) {
        iVar2 = 3;
      }
      else if (iVar1 < 0xc) {
        iVar2 = 4;
      }
      else {
        iVar2 = 5;
      }
      goto LAB_14013531e;
    }
    iVar3 = DAT_140e44198;
    iVar2 = 0;
    if (DAT_140e44198 - 1U < 5) {
      iVar2 = DAT_140e44198;
    }
  }
  if (5 < iVar3) {
    return 0;
  }
LAB_14013531e:
  if (param_1 == 0xe) {
    return 0;
  }
  return iVar2;
}


