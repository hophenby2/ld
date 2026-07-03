// Function: FUN_14012e8e0 @ 14012e8e0
// Decompile completed: true

void FUN_14012e8e0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  
  uVar2 = DAT_140539f40;
  if ((param_4 <= param_3) && (param_3 < param_5)) {
    uVar6 = 0;
    uVar4 = FUN_1401349e0(param_3,param_4,param_4 + 0x10,param_5 + -0x10,param_5,0,DAT_140539f40);
    uVar5 = DAT_14053accc;
    if ((param_6 != 1) && (uVar5 = DAT_14053aee8, param_6 == 2)) {
      uVar5 = DAT_14053ad80;
    }
    iVar3 = 1;
    if (param_6 != 2) {
      iVar3 = param_6;
    }
    uVar6 = uVar6 & 0xffffffffffff0000;
    FUN_1400c8410((&DAT_140e47540)[iVar3],0x6e,1,DAT_14053aedc,uVar5,uVar6,uVar2,uVar4,0xff,0xff,
                  0xff,0xff,1,0);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)param_2 * 4),0x6e,1,DAT_14053ae44,uVar5
                  ,uVar6 & 0xffffffffffff0000,uVar4,uVar4,0xff,0xff,0xff,0xff,1,0);
    if ((param_3 == param_4 + 0x10) && (((param_6 == 0 || (param_6 == 1)) || (param_6 == 2)))) {
      FUN_14012e070(param_1,4);
    }
    lVar1 = DAT_140e47908;
    if (param_3 == param_5 + -0x10) {
      while (lVar1 != 0) {
        lVar1 = *(longlong *)(lVar1 + 0x238);
        FUN_140323ce8();
      }
      DAT_140e47908 = 0;
      DAT_140e9fd30 = 0;
    }
  }
  return;
}


