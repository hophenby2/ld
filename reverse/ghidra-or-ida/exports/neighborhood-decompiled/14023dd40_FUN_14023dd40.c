// Function: FUN_14023dd40 @ 14023dd40
// Decompile completed: true

undefined8
FUN_14023dd40(longlong param_1,int param_2,int param_3,int param_4,undefined8 param_5,int param_6,
             int param_7)

{
  longlong lVar1;
  bool bVar2;
  byte *pbVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar4 = (longlong)param_3;
  lVar7 = (longlong)param_4;
  lVar1 = lVar4 + (longlong)param_2 * 4;
  lVar5 = lVar1 * 0x140c;
  if (param_7 != 0) {
    FUN_14023e510(param_1 + 0x14 + lVar5,1,param_4,param_6);
  }
  FUN_1401ae2f0(param_1 + 0x420 + lVar5 + (longlong)(*(int *)(lVar5 + 0x41c + param_1) * param_4),
                param_5);
  lVar5 = param_1 + 0x2717c + (longlong)param_2 * 0x100;
  bVar2 = false;
  if (lVar7 < param_4 + param_6) {
    pbVar3 = (byte *)(lVar7 + lVar5);
    lVar7 = (param_4 + param_6) - lVar7;
    bVar2 = false;
    do {
      pbVar3[((lVar1 * 0x100 + param_1) - lVar5) + 0x1e134] = 1;
      if (*(int *)(param_1 + lVar4 * 4) != 0) {
        if ((*pbVar3 == 0xff) || ((int)(uint)*pbVar3 <= param_3)) {
          *pbVar3 = (byte)param_3;
        }
        else {
          bVar2 = true;
        }
      }
      pbVar3 = pbVar3 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  if (*(int *)(param_1 + lVar4 * 4) != 0) {
    uVar6 = 0;
    if (!bVar2) {
      uVar6 = param_5;
    }
    FUN_14023cc30(param_1,param_2,param_4,uVar6,param_6);
  }
  return 0;
}


