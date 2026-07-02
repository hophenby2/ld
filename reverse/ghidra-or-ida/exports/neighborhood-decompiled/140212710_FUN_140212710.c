// Function: FUN_140212710 @ 140212710
// Decompile completed: true

longlong FUN_140212710(int *param_1,longlong param_2,ulonglong param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  if ((*param_1 == 0) || (param_1[1] == 1)) {
    return 0;
  }
  lVar5 = 0;
  lVar3 = lVar5;
  do {
    if (param_3 == 0) {
      return lVar3;
    }
    if (*(longlong *)(param_1 + 0x124) == 0) {
      iVar1 = param_1[2];
      param_1[0x126] = 0;
      param_1[0x127] = 0;
      if (iVar1 == 0) {
        iVar1 = FUN_140212460(param_1);
      }
      else if (iVar1 == 1) {
        iVar1 = FUN_140267480(param_1);
      }
      else if (iVar1 == 2) {
        iVar1 = FUN_140267540(param_1);
      }
      else {
        iVar1 = FUN_140246be0();
      }
      if (iVar1 == -1) {
        if (param_3 == 0) {
          return lVar3;
        }
        param_1[1] = 1;
        return lVar3;
      }
    }
    uVar4 = param_3;
    if (*(ulonglong *)(param_1 + 0x124) < param_3) {
      uVar4 = *(ulonglong *)(param_1 + 0x124);
    }
    FUN_1401ae2f0(lVar5 + param_2,*(longlong *)(param_1 + 0x120) + *(longlong *)(param_1 + 0x126),
                  uVar4);
    lVar2 = (longlong)(int)uVar4;
    lVar5 = lVar5 + uVar4;
    *(longlong *)(param_1 + 0x124) = *(longlong *)(param_1 + 0x124) - lVar2;
    lVar3 = lVar3 + uVar4;
    *(longlong *)(param_1 + 0x126) = *(longlong *)(param_1 + 0x126) + lVar2;
    *(longlong *)(param_1 + 0x128) = *(longlong *)(param_1 + 0x128) + lVar2;
    param_3 = param_3 - uVar4;
  } while( true );
}


