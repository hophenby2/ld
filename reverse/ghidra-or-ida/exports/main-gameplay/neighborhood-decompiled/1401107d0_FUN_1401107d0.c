// Function: FUN_1401107d0 @ 1401107d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401107d0(int param_1,undefined8 param_2,int param_3)

{
  longlong lVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  lVar1 = (longlong)DAT_1407c7798;
  local_48 = _DAT_14053ba60;
  uStack_40 = _UNK_14053ba68;
  local_38 = _DAT_14053ba60;
  uStack_30 = _UNK_14053ba68;
  local_18 = 0xac44;
  local_28 = _DAT_14053ba60;
  uStack_20 = _UNK_14053ba68;
  local_14 = 0xac44;
  local_10 = 0xac44;
  FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),
                (&DAT_140e45100)[param_1]);
  FUN_14018bca0((longlong)*(int *)((longlong)&local_48 + lVar1 * 4) *
                (longlong)((DAT_140e45d74 - param_3) / 0x3c),(&DAT_140e45100)[param_1]);
  FUN_14018a340((&DAT_140e45100)[param_1],3,0);
  return;
}


