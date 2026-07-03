// Function: FUN_140072560 @ 140072560
// Decompile completed: true

void FUN_140072560(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  longlong lVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  float fVar14;
  undefined8 uStack_d0;
  
  iVar1 = param_1[0x10];
  iVar2 = param_1[1];
  iVar8 = param_1[0x14];
  dVar10 = *(double *)(param_1 + 0xc);
  dVar9 = (double)FUN_140332d90((DAT_14053ac08 / (double)(iVar1 * 4)) * ((double)iVar2 - 0.0) *
                                DAT_14053a020 * DAT_140539d28);
  dVar9 = dVar9 * dVar10 + 0.0;
  if (param_1[2] - 0x22 < 4) {
    dVar9 = (dVar10 / (double)iVar1) * (double)iVar2;
  }
  uVar13 = (undefined4)((ulonglong)dVar9 >> 0x20);
  uVar12 = SUB84(dVar9,0);
  if (iVar1 + -8 <= iVar2) {
    iVar8 = iVar8 - (int)((double)((iVar2 - iVar1) + 8) * (double)iVar8 * DAT_140539e80);
  }
  dVar10 = (double)FUN_1403307c0();
  fVar14 = (float)(dVar10 * *(double *)(param_1 + 10)) + (float)param_1[5];
  param_1[5] = fVar14;
  dVar10 = (double)FUN_140332d90();
  fVar11 = (float)(dVar10 * *(double *)(param_1 + 10)) + (float)param_1[6];
  param_1[6] = fVar11;
  if ((param_1[2] == 0x20) || (param_1[2] == 0x22)) {
    auVar3._8_4_ = uVar12;
    auVar3._0_8_ = dVar9;
    auVar3._12_4_ = uVar13;
    FUN_1400c8410(param_1[3],param_1[4],7,fVar14,fVar11,*(undefined2 *)(param_1 + 9),auVar3,
                  param_1[0x11],param_1[0x13],param_1[0x12],iVar8,1,0);
  }
  iVar1 = param_1[2];
  if (((iVar1 == 0x21) || (iVar1 == 0x23)) || (iVar1 == 0xc)) {
    auVar6._8_4_ = uVar12;
    auVar6._0_8_ = dVar9;
    auVar6._12_4_ = uVar13;
    FUN_1400c8410(param_1[3],param_1[4],8,param_1[5],param_1[6],*(undefined2 *)(param_1 + 9),auVar6,
                  param_1[0x11],param_1[0x13],param_1[0x12],iVar8,1,0);
  }
  if (param_1[2] - 0x24 < 2) {
    lVar7 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar7 != 0; lVar7 = *(longlong *)(lVar7 + 0x60)) {
        if (*(int *)(lVar7 + 4) == param_1[0x15]) {
          uStack_d0 = *(undefined8 *)(lVar7 + 0x28);
        }
      }
    }
    if (param_1[2] == 0x24) {
      auVar4._8_4_ = uVar12;
      auVar4._0_8_ = dVar9;
      auVar4._12_4_ = uVar13;
      FUN_1400c8410(param_1[3],param_1[4],7,(float)uStack_d0 + (float)param_1[5],
                    uStack_d0._4_4_ + (float)param_1[6],*(undefined2 *)(param_1 + 9),auVar4,
                    param_1[0x11],param_1[0x13],param_1[0x12],iVar8,1,0);
    }
    if (param_1[2] == 0x25) {
      auVar5._8_4_ = uVar12;
      auVar5._0_8_ = dVar9;
      auVar5._12_4_ = uVar13;
      FUN_1400c8410(param_1[3],param_1[4],8,(float)uStack_d0 + (float)param_1[5],
                    uStack_d0._4_4_ + (float)param_1[6],*(undefined2 *)(param_1 + 9),auVar5,
                    param_1[0x11],param_1[0x13],param_1[0x12],iVar8,1,0);
    }
  }
  if (param_1[1] == param_1[0x10]) {
    *param_1 = 0;
  }
  return;
}


