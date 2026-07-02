// Function: FUN_1401ba9b0 @ 1401ba9b0
// Decompile completed: true

longlong FUN_1401ba9b0(undefined8 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = FUN_1401c4e80();
  if (iVar2 == 1) {
    lVar3 = 0;
    cVar1 = (char)*param_2;
    while (cVar1 != '\0') {
      lVar3 = lVar3 + 1;
      cVar1 = *(char *)(lVar3 + (longlong)param_2);
    }
  }
  else if (iVar2 == 2) {
    lVar3 = 0;
    if ((short)*param_2 != 0) {
      do {
        lVar3 = lVar3 + 1;
      } while (*(short *)((longlong)param_2 + lVar3 * 2) != 0);
      return lVar3;
    }
  }
  else {
    if (iVar2 != 4) {
      return 0;
    }
    lVar3 = 0;
    if (*param_2 != 0) {
      do {
        lVar3 = lVar3 + 1;
      } while (param_2[lVar3] != 0);
      return lVar3;
    }
  }
  return lVar3;
}


