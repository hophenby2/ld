// Function: FUN_140079c10 @ 140079c10
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140079c10(longlong param_1,int param_2,undefined8 param_3,float param_4,float param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  float fVar6;
  
  uVar1 = _DAT_14053bb20;
  param_4 = param_4 + *(float *)(param_1 + 0x28);
  iVar4 = 0;
  iVar3 = 0xff;
  dVar5 = (double)*(int *)(param_1 + 0x1c) / (double)*(int *)(param_1 + 0x20);
  iVar2 = (int)((dVar5 - DAT_140539f00) * DAT_14053a768);
  if (dVar5 <= DAT_140539f00) {
    iVar2 = 0;
    iVar3 = (int)(dVar5 * DAT_14053a768);
    iVar4 = (int)(DAT_14053a5f8 - dVar5 * DAT_14053a768);
  }
  if (param_2 == 0) {
    fVar6 = param_4 + DAT_14053b390;
  }
  else if (param_2 == 1) {
    dVar5 = dVar5 * DAT_140539f00;
    fVar6 = param_4 + DAT_14053b360;
  }
  else {
    fVar6 = param_4;
    if (param_2 == 2) {
      fVar6 = param_4 + DAT_14053b34c;
      dVar5 = dVar5 / DAT_14053a018;
    }
  }
  if (-1 < *(int *)(param_1 + 0x1c)) {
    FUN_1400c8410((&DAT_140e45d98)[param_2],100,7,param_4,param_5 + *(float *)(param_1 + 0x2c),0,
                  _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xc0,1,0);
    FUN_1400c8410(DAT_140e45d8c,100,9,fVar6,(param_5 + *(float *)(param_1 + 0x2c)) - DAT_14053aa20,0
                  ,dVar5,uVar1,iVar4,iVar3,iVar2,0xc0,1,0);
  }
  return;
}


