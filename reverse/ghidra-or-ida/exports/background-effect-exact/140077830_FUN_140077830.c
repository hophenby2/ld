// Function: FUN_140077830 @ 140077830
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140077830(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined1 auVar3 [16];
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  undefined1 in_stack_ffffffffffffff58 [16];
  undefined1 auVar12 [16];
  
  dVar8 = DAT_14053a020;
  dVar1 = *(double *)(param_1 + 10);
  dVar6 = (double)*(ushort *)(param_1 + 9) * DAT_14053a020 * DAT_140539d28;
  dVar5 = (double)FUN_1403307c0(dVar6);
  fVar9 = (float)(dVar5 * dVar1) + (float)param_1[5];
  param_1[5] = fVar9;
  dVar6 = (double)FUN_140332d90(dVar6);
  iVar2 = param_1[1];
  *(double *)(param_1 + 10) = dVar1 + DAT_140539e20;
  fVar10 = (float)(dVar6 * dVar1) + (float)param_1[6];
  param_1[6] = fVar10;
  dVar1 = ((double)iVar2 * _DAT_140539cf8 + _DAT_140539d40) * (double)iVar2 +
          *(double *)(param_1 + 0xc);
  *(double *)(param_1 + 0xc) = dVar1;
  if (param_1[2] == 0x3c) {
    fVar7 = (float)dVar1 * DAT_14053accc;
    dVar8 = (double)(((DAT_140e44acc + iVar2) / 2 & 0xffffU) * 0x22b & 0xffff) * dVar8 *
            DAT_140539d28;
    dVar6 = (double)FUN_1403307c0(dVar8);
    dVar8 = (double)FUN_140332d90(dVar8);
    auVar12._4_12_ = in_stack_ffffffffffffff58._4_12_;
    auVar12._0_4_ = param_1[0x14];
    uVar11 = 0;
    uVar4 = FUN_1401348b0(iVar2,0,0x20,param_1[0x10] + -0x10,param_1[0x10],0,auVar12);
    auVar3._8_4_ = SUB84(dVar1,0);
    auVar3._0_8_ = dVar1;
    auVar3._12_4_ = (int)((ulonglong)dVar1 >> 0x20);
    FUN_1400c8410(param_1[3],param_1[4],8,(float)(dVar6 * (double)fVar7) + fVar9,
                  (float)(dVar8 * (double)fVar7) + fVar10,uVar11 & 0xffff0000,auVar3,param_1[0x11],
                  param_1[0x12],param_1[0x13],uVar4,1,0);
  }
  if ((param_1[1] == param_1[0x10]) || (DAT_140e418c8 == DAT_140e45d74 + 1)) {
    *param_1 = 0;
  }
  return;
}


