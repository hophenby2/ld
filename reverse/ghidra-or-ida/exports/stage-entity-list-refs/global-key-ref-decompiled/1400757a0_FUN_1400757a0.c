// Function: FUN_1400757a0 @ 1400757a0
// Decompile completed: true

void FUN_1400757a0(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 uStack_80;
  
  dVar10 = DAT_14053a020;
  iVar2 = param_1[1];
  dVar1 = *(double *)(param_1 + 0xc);
  uVar11 = SUB84(dVar1,0);
  uVar12 = (undefined4)((ulonglong)dVar1 >> 0x20);
  iVar8 = param_1[0x10];
  if (iVar8 == 0) {
LAB_140075858:
    dVar1 = (double)CONCAT44(uVar12,uVar11);
    iVar8 = param_1[0x14];
    iVar7 = 0;
    iVar5 = iVar8;
    if (iVar2 < 0) goto LAB_1400758a3;
  }
  else {
    if (iVar2 < 0) {
      if (iVar8 <= iVar2) goto LAB_140075854;
      goto LAB_140075858;
    }
    if (iVar8 <= iVar2) {
LAB_140075854:
      uVar11 = 0;
      uVar12 = 0;
      goto LAB_140075858;
    }
    dVar9 = (double)FUN_140332d90((DAT_14053ac08 / (double)(iVar8 * 4)) *
                                  ((double)iVar2 - (double)-iVar8) * DAT_14053a020 * DAT_140539d28);
    iVar8 = param_1[0x14];
    iVar5 = 0;
    if (-1 < iVar2) {
      iVar5 = iVar8;
    }
    dVar1 = (dVar1 - 0.0) * dVar9 + 0.0;
  }
  iVar7 = iVar5;
  if (iVar2 < 8) {
    dVar10 = (double)FUN_140332d90(((double)iVar2 - 0.0) * DAT_14053aa28 * dVar10 * DAT_140539d28);
    iVar7 = (int)(dVar10 * (double)iVar8);
  }
LAB_1400758a3:
  uVar11 = (undefined4)((ulonglong)dVar1 >> 0x20);
  if ((int)param_1[0x15] < 1) {
    uStack_80._0_4_ = (float)param_1[5];
    uStack_80._4_4_ = (float)param_1[6];
  }
  else {
    lVar6 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x60)) {
        if (*(int *)(lVar6 + 4) == param_1[0x15]) {
          uStack_80 = *(undefined8 *)(lVar6 + 0x28);
        }
      }
    }
    uStack_80._0_4_ = (float)uStack_80 + (float)param_1[5];
    uStack_80._4_4_ = uStack_80._4_4_ + (float)param_1[6];
  }
  if (param_1[2] == 0x31) {
    auVar3._8_4_ = SUB84(dVar1,0);
    auVar3._0_8_ = dVar1;
    auVar3._12_4_ = uVar11;
    FUN_1400c8410(param_1[3],param_1[4],8,(float)uStack_80,uStack_80._4_4_,0,auVar3,0xff,0xff,0xff,
                  iVar7,1,0);
  }
  if (param_1[2] == 0x32) {
    auVar4._8_4_ = SUB84(dVar1,0);
    auVar4._0_8_ = dVar1;
    auVar4._12_4_ = uVar11;
    FUN_1400c8410(param_1[3],param_1[4],7,(float)uStack_80,uStack_80._4_4_,0,auVar4,param_1[0x11],
                  param_1[0x12],param_1[0x13],iVar7,1,0);
  }
  if (param_1[1] == param_1[0x10]) {
    *param_1 = 0;
  }
  return;
}


