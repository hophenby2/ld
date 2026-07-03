// Function: FUN_140051030 @ 140051030
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140051030(undefined4 *param_1)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  undefined8 in_stack_fffffffffffffec8;
  undefined4 uVar11;
  int iStack_a4;
  
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539f40;
  dVar7 = DAT_140539d28;
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  lVar1 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        iStack_a4 = *(int *)(lVar1 + 0x54);
      }
    }
  }
  iVar4 = param_1[3];
  if (iVar4 < 0) {
LAB_14005112a:
    dVar5 = 0.0;
  }
  else {
    if (iVar4 < 0x10) {
      dVar5 = (double)iVar4 - 0.0;
    }
    else {
      dVar5 = DAT_140539f40;
      if (iVar4 < 0xa4) goto LAB_14005112e;
      if (0xb3 < iVar4) goto LAB_14005112a;
      dVar5 = (double)iVar4 - DAT_14053a500;
    }
    dVar5 = (double)FUN_140332d90(dVar5 * DAT_14053a900 * DAT_14053a020 * DAT_140539d28);
    dVar5 = dVar5 + 0.0;
  }
LAB_14005112e:
  uVar10 = 0;
  iVar4 = FUN_1400c9580(iVar4,0,5,3,0xab,0xac,CONCAT44(uVar11,0xad));
  dVar6 = (double)FUN_1403307c0();
  fVar9 = (float)(dVar6 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar9;
  dVar6 = (double)FUN_140332d90();
  fVar8 = (float)(dVar6 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar8;
  if ((iStack_a4 == 1) && ((int)param_1[3] < 0xa4)) {
    param_1[3] = 0xa4;
  }
  dVar7 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053abd8 * dVar3 * dVar7);
  FUN_1400c8410((&DAT_140e44ad0)[iVar4],0x1d,7,fVar9,fVar8,uVar10 & 0xffff0000,dVar2,dVar5,0xff,0xff
                ,0xff,0xc0 - (int)(dVar7 * _DAT_14053b130),1,0);
  if (param_1[3] == 0xb4) {
    *param_1 = 0;
  }
  return;
}


