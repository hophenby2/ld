// Function: FUN_14006faa0 @ 14006faa0
// Decompile completed: true

void FUN_14006faa0(undefined4 *param_1)

{
  short sVar1;
  double dVar2;
  short sVar3;
  undefined8 uVar4;
  short sVar5;
  int iVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff88;
  undefined2 uVar11;
  undefined4 in_stack_ffffffffffffff90;
  undefined2 uVar12;
  double in_stack_ffffffffffffff98;
  double dVar13;
  
  uVar12 = (undefined2)((uint)in_stack_ffffffffffffff90 >> 0x10);
  uVar11 = (undefined2)((uint)in_stack_ffffffffffffff88 >> 0x10);
  sVar1 = *(short *)(param_1 + 9);
  dVar13 = *(double *)(param_1 + 10);
  fVar8 = (float)param_1[8];
  param_1[8] = (float)dVar13 + fVar8;
  dVar2 = (double)((float)dVar13 + fVar8);
  dVar7 = (double)FUN_1403307c0();
  fVar10 = (float)(dVar7 * dVar2) + (float)param_1[4];
  dVar7 = (double)FUN_140332d90();
  fVar8 = DAT_140e445d8 / DAT_14053ab70;
  iVar6 = param_1[0xe];
  fVar9 = (float)(dVar7 * dVar2) + (float)param_1[5];
  if ((((fVar10 < fVar8 - (float)iVar6) || ((float)(iVar6 + 600) + fVar8 < fVar10)) ||
      (fVar9 < (float)-iVar6)) || ((float)(iVar6 + 0x2d0) < fVar9)) {
    sVar3 = sVar1;
    if (fVar10 < fVar8 + 0.0) {
      sVar3 = -0x8000 - sVar1;
    }
    sVar5 = -0x8000 - sVar1;
    if (fVar10 <= fVar8 + DAT_14053aec0) {
      sVar5 = sVar3;
    }
    if (fVar9 < 0.0) {
      sVar5 = -sVar1;
    }
    *(short *)(param_1 + 9) = sVar5;
    uVar4 = FUN_1401346a0(*(undefined8 *)(param_1 + 4),0);
    local_res8 = (undefined4)uVar4;
    uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar12 = 0;
    param_1[4] = local_res8;
    param_1[5] = uStackX_c;
    FUN_14006c2f0(param_1[2],uStackX_c,fVar10,fVar9,CONCAT22(uVar11,sVar5),0,dVar13,iVar6,0);
    *param_1 = 0;
    in_stack_ffffffffffffff98 = dVar13;
  }
  FUN_140070250(param_1[2],0x50,param_1[1],fVar10,fVar9,
                CONCAT22(uVar12,*(undefined2 *)(param_1 + 9)),
                (ulonglong)in_stack_ffffffffffffff98 & 0xffffffff00000000);
  if (((fVar10 < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac80) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aed4 < fVar10)) ||
     ((fVar9 < DAT_14053b33c || (DAT_14053af28 < fVar9)))) {
    *param_1 = 0;
  }
  return;
}


