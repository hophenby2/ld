// Function: FUN_1400c2670 @ 1400c2670
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c2670(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,float param_10)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  
  uVar2 = DAT_140539f50;
  uVar1 = DAT_140539f40;
  fVar3 = (float)DAT_1407c77a4 * param_10 + *(float *)(&DAT_140e46a28 + (longlong)param_1 * 4);
  *(float *)(&DAT_140e46a28 + (longlong)param_1 * 4) = fVar3;
  fVar3 = (float)((int)fVar3 % 0xa00);
  FUN_1400c8410(param_2,param_3,param_4,param_5,fVar3,0,uVar2,uVar1,param_6,param_7,param_8,param_9,
                1,0);
  FUN_1400c8410(param_2,param_3,param_4,param_5,fVar3 + _DAT_14053b034,0,uVar2,uVar1,param_6,param_7
                ,param_8,param_9,1,0);
  FUN_1400c8410(param_2,param_3,param_4,param_5,fVar3 - _DAT_14053b034,0,uVar2,uVar1,param_6,param_7
                ,param_8,param_9,1,0);
  return;
}


