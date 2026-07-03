// Function: FUN_14006ffc0 @ 14006ffc0
// Decompile completed: true

void FUN_14006ffc0(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    param_1[6] = param_1[8];
    fVar6 = (float)param_1[6];
    if (DAT_140e445dc < (float)param_1[5]) {
      *(undefined2 *)((longlong)param_1 + 0x26) = 0xc000;
    }
    else {
      *(undefined2 *)((longlong)param_1 + 0x26) = 0x4000;
    }
LAB_140070040:
    dVar4 = (double)FUN_140332d90(((double)iVar2 - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                  DAT_140539d28);
    fVar6 = (float)(dVar4 * (double)(fVar6 - 0.0)) + 0.0;
  }
  else {
    fVar6 = (float)param_1[6];
    if (iVar2 < 0) {
      fVar6 = 0.0;
    }
    else if (iVar2 < 10) goto LAB_140070040;
  }
  param_1[8] = fVar6;
  dVar5 = (double)iVar2 * DAT_140539ee8 - DAT_140539fc8;
  *(double *)(param_1 + 10) = dVar5;
  dVar4 = (double)FUN_1403307c0();
  fVar7 = (float)(dVar4 * dVar5) + (float)param_1[4];
  param_1[4] = fVar7;
  dVar4 = (double)FUN_140332d90();
  sVar3 = *(short *)(param_1 + 9);
  fVar8 = (float)(dVar4 * dVar5) + (float)param_1[5];
  param_1[5] = fVar8;
  if (param_1[3] == 0x3a) {
    sVar1 = 0x1bc;
  }
  else {
    if (param_1[3] != 0x3b) goto LAB_14007012f;
    sVar1 = -0x1bc;
  }
  sVar3 = sVar3 + sVar1;
  *(short *)(param_1 + 9) = sVar3;
LAB_14007012f:
  dVar4 = (double)FUN_1403307c0();
  dVar5 = (double)FUN_140332d90();
  FUN_140070250(param_1[2],0x50,iVar2,(float)(dVar4 * (double)fVar6) + fVar7,
                (float)(dVar5 * (double)fVar6) + fVar8,sVar3,0);
  iVar2 = (int)(float)param_1[6];
  if (((((float)param_1[4] < DAT_140e445d8 / DAT_14053ab70 - (float)(iVar2 + 0x32)) ||
       ((float)(iVar2 + 0x28a) + DAT_140e445d8 / DAT_14053ab70 < (float)param_1[4])) ||
      ((float)param_1[5] < (float)-(iVar2 + 0x32))) || ((float)(iVar2 + 0x302) < (float)param_1[5]))
  {
    *param_1 = 0;
  }
  return;
}


