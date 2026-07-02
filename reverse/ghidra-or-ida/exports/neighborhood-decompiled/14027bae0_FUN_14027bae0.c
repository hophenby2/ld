// Function: FUN_14027bae0 @ 14027bae0
// Decompile completed: true

undefined8 FUN_14027bae0(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  if (DAT_140c2b470 == 0) {
    FUN_1401e6080();
    if (DAT_140c2c018 != (code *)0x0) {
      (*DAT_140c2c018)(1);
    }
  }
  uVar4 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar4;
  uVar4 = param_2[3];
  param_1[2] = param_2[2];
  param_1[3] = uVar4;
  uVar4 = param_2[5];
  param_1[4] = param_2[4];
  param_1[5] = uVar4;
  uVar4 = param_2[7];
  param_1[6] = param_2[6];
  param_1[7] = uVar4;
  uVar1 = *(undefined4 *)((longlong)param_2 + 0x44);
  uVar2 = *(undefined4 *)(param_2 + 9);
  uVar3 = *(undefined4 *)((longlong)param_2 + 0x4c);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)((longlong)param_1 + 0x44) = uVar1;
  *(undefined4 *)(param_1 + 9) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x4c) = uVar3;
  param_1[10] = param_2[10];
  if (*(int *)(param_2 + 9) != 0) {
    lVar5 = (*DAT_140c2b908)(*(int *)(param_2 + 9));
    param_1[10] = lVar5;
    if (lVar5 == 0) {
      *(undefined4 *)(param_1 + 9) = 0;
      return 0x8007000e;
    }
    FUN_1401ae2f0(lVar5,param_2[10],*(undefined4 *)(param_1 + 9));
  }
  if ((longlong *)param_1[8] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[8] + 8))();
  }
  return 0;
}


