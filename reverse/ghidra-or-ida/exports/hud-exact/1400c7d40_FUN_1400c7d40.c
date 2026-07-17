// Function: FUN_1400c7d40 @ 1400c7d40
// Decompile completed: true

bool FUN_1400c7d40(void)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;

  if ((DAT_140e41928 != 1) || (DAT_140e451a4 != 0)) goto LAB_1400c7d99;
  if (DAT_140e419b8 < 3) {
    if (DAT_140e445d0 == 0) {
      bVar3 = SBORROW4(DAT_140e46b24,6);
      iVar1 = -6;
      bVar2 = DAT_140e46b24 == 6;
    }
    else {
      if ((DAT_140e445d0 - 1U < 2) && (DAT_140e46b24 < 6)) {
        return true;
      }
      if (DAT_140e445d0 != 3) goto LAB_1400c7d8a;
      bVar3 = SBORROW4(DAT_140e46b24,3);
      iVar1 = -3;
      bVar2 = DAT_140e46b24 == 3;
    }
    if (bVar2 || bVar3 != DAT_140e46b24 + iVar1 < 0) {
      return true;
    }
  }
LAB_1400c7d8a:
  if (DAT_140e419b8 == 3) {
    if (DAT_140e445d0 == 0) {
      bVar4 = SBORROW4(DAT_140e46b24,8);
      bVar3 = DAT_140e46b24 + -8 < 0;
      bVar2 = DAT_140e46b24 == 8;
    }
    else {
      if ((DAT_140e445d0 - 1U < 2) && (DAT_140e46b24 < 8)) {
        return true;
      }
      if (DAT_140e445d0 != 3) goto LAB_1400c7d99;
      bVar4 = SBORROW4(DAT_140e46b24,4);
      bVar3 = DAT_140e46b24 + -4 < 0;
      bVar2 = DAT_140e46b24 == 4;
    }
  }
  else {
    if (DAT_140e419b8 != 4) goto LAB_1400c7d99;
    if (DAT_140e445d0 != 0) {
      if ((DAT_140e445d0 - 1U < 2) && (DAT_140e46b24 < 9)) {
        return true;
      }
      if ((DAT_140e445d0 == 3) && (DAT_140e46b24 < 6)) {
        return true;
      }
      goto LAB_1400c7d99;
    }
    bVar4 = SBORROW4(DAT_140e46b24,10);
    bVar3 = DAT_140e46b24 + -10 < 0;
    bVar2 = DAT_140e46b24 == 10;
  }
  if (bVar2 || bVar4 != bVar3) {
    return true;
  }
LAB_1400c7d99:
  return DAT_140e4695c == 1;
}
