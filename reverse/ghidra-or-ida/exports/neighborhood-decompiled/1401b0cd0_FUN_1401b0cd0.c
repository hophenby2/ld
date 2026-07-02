// Function: FUN_1401b0cd0 @ 1401b0cd0
// Decompile completed: true

longlong FUN_1401b0cd0(longlong param_1,longlong *param_2,longlong *param_3,undefined1 *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_1 + 0x8c8) == 0) {
    *param_4 = 0;
    lVar3 = 0;
  }
  else {
    FUN_1401ae2f0(param_4,param_1 + 0x888);
    param_4[*(longlong *)(param_1 + 0x8c8)] = 0;
    lVar3 = *(longlong *)(param_1 + 0x8c8);
  }
  FUN_1401ae370(param_4 + 0x7f8,0,8);
  param_4 = param_4 + lVar3;
  FUN_1401b9f20(*(undefined4 *)(param_1 + 0x40),param_4,0x7f8 - lVar3,
                *param_3 + 4 + *(longlong *)(param_1 + 0x70));
  lVar2 = param_2[1];
  while (lVar2 != -1) {
    FUN_1401b9f20(*(undefined4 *)(param_1 + 0x40),param_4,0x7f8 - lVar3,
                  *(longlong *)(param_1 + 0x70) + 4 +
                  *(longlong *)(*(longlong *)(param_1 + 0x60) + *param_2));
    param_2 = (longlong *)(param_2[1] + *(longlong *)(param_1 + 0x68));
    lVar2 = param_2[1];
  }
  lVar2 = FUN_1401ba9b0(*(undefined4 *)(param_1 + 0x40),param_4);
  iVar1 = thunk_FUN_1401c4e80(*(undefined4 *)(param_1 + 0x40));
  return iVar1 * lVar2 + lVar3;
}


