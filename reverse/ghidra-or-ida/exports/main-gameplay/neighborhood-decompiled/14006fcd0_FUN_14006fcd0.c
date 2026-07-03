// Function: FUN_14006fcd0 @ 14006fcd0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14006fcd0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  short sVar5;
  short sVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  dVar8 = DAT_14053a6d8;
  uVar1 = param_1[1];
  if (uVar1 < 0x28) {
    dVar7 = (double)FUN_140332d90(((double)(int)uVar1 - 0.0) * DAT_14053a6d8 * DAT_14053a020 *
                                  DAT_140539d28);
    fVar9 = (float)(int)(dVar7 * DAT_14053a510);
  }
  else {
    iVar3 = ((int)uVar1 >> 0x1f & 0xfffffec0U) + 0x140;
    fVar9 = (float)(int)(((int)uVar1 >> 0x1f & 0xffffff6aU) + 0x96);
    if (((int)uVar1 < 0) || (0x27 < (int)uVar1)) goto LAB_14006fdae;
  }
  dVar8 = (double)FUN_140332d90(((double)(int)uVar1 - 0.0) * dVar8 * DAT_14053a020 * DAT_140539d28);
  iVar3 = (int)(dVar8 * _DAT_14053a668);
LAB_14006fdae:
  sVar5 = 1;
  if (DAT_140e419b8 == 0) {
    sVar5 = 0x46;
  }
  else if (DAT_140e419b8 == 1) {
    sVar5 = 0x78;
  }
  else if (DAT_140e419b8 == 2) {
    sVar5 = 0x8c;
  }
  else if (DAT_140e419b8 == 3) {
    sVar5 = 0xb4;
  }
  else if (DAT_140e419b8 == 4) {
    sVar5 = 0xdc;
  }
  if (uVar1 == 0x28) {
    dVar8 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[7]),
                                  (double)(DAT_140e445d8 - (float)param_1[6]));
    *(short *)((longlong)param_1 + 0x26) = (short)(int)(dVar8 * DAT_14053aba0);
  }
  else if (0x28 < (int)uVar1) {
    dVar8 = *(double *)(param_1 + 10);
    if (dVar8 < DAT_14053a070) {
      dVar8 = dVar8 + _DAT_140539e28;
      *(double *)(param_1 + 10) = dVar8;
    }
    dVar7 = (double)FUN_1403307c0();
    param_1[6] = (float)(dVar7 * dVar8) + (float)param_1[6];
    dVar7 = (double)FUN_140332d90();
    param_1[7] = (float)(dVar7 * dVar8) + (float)param_1[7];
  }
  iVar2 = param_1[3];
  sVar6 = *(short *)(param_1 + 9);
  if (iVar2 == 0x1f) {
    sVar6 = sVar5 + sVar6;
    *(short *)(param_1 + 9) = sVar6;
  }
  else if (iVar2 == 0x20) {
    sVar6 = sVar6 - sVar5;
    *(short *)(param_1 + 9) = sVar6;
  }
  uVar4 = FUN_140133f30(iVar2,param_1[7],0,sVar6,fVar9,(float)iVar3);
  uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
  local_res8 = (undefined4)uVar4;
  param_1[4] = local_res8;
  param_1[5] = uStackX_c;
  FUN_140070250(param_1[2],0x50,uVar1,local_res8,uStackX_c,sVar6,0);
  if (((((float)param_1[4] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053adf0) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af68 < (float)param_1[4])) ||
      ((float)param_1[5] < DAT_14053b3ec)) || (_DAT_14053afac < (float)param_1[5])) {
    *param_1 = 0;
  }
  return;
}


