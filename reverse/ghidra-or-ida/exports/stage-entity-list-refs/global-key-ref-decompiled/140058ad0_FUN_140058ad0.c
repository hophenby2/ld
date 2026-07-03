// Function: FUN_140058ad0 @ 140058ad0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140058ad0(undefined4 *param_1)

{
  float fVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  undefined8 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffec8;
  undefined2 uVar14;
  undefined4 uVar13;
  uint in_stack_fffffffffffffed0;
  undefined8 in_stack_fffffffffffffee0;
  int iStack_cc;
  
  dVar4 = DAT_14053a020;
  dVar3 = DAT_140539d28;
  uVar14 = (undefined2)((uint)in_stack_fffffffffffffec8 >> 0x10);
  uVar13 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  iStack_cc = 0;
  iVar8 = 0;
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_cc = iVar8, lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        iStack_cc = *(int *)(lVar2 + 0x1c);
      }
      iVar8 = iStack_cc;
    }
  }
  sVar7 = *(short *)(param_1 + 0x10);
  dVar9 = (double)FUN_1403307c0();
  local_res8 = (float)(dVar9 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = local_res8;
  dVar9 = (double)FUN_140332d90();
  fVar12 = (float)(dVar9 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar12;
  if (param_1[6] - 0x10c < 2) {
    iVar8 = param_1[3];
    if (iVar8 == 0) {
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472d4);
      FUN_14018a340(DAT_140e472d4,1,1);
      iVar8 = param_1[3];
      sVar7 = *(short *)(param_1 + 0x10);
      fVar12 = (float)param_1[0xb];
      local_res8 = (float)param_1[10];
    }
    dVar10 = (double)FUN_140332d90(((double)iVar8 - 0.0) * _DAT_14053a8a8 * dVar4 * dVar3);
    dVar9 = _DAT_14053a7a0;
    if (param_1[6] == 0x10c) {
      dVar9 = _DAT_14053b250;
    }
    *(short *)(param_1 + 0x10) = (short)(int)(dVar10 * dVar9) + sVar7;
    if (iVar8 == 0x19) {
      dVar9 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar12),
                                    SUB84((double)(DAT_140e445d8 - local_res8),0));
      uVar5 = CONCAT44(uVar13,1);
      uVar13 = CONCAT22(uVar14,(short)(int)(dVar9 * DAT_14053aba0));
      FUN_14006c2f0(3,2,local_res8,fVar12,uVar13,0,DAT_14053a0f8,uVar5,0);
      uVar14 = (undefined2)((uint)uVar13 >> 0x10);
      uVar13 = (undefined4)((ulonglong)uVar5 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar5 = CONCAT44(uVar13,1);
    in_stack_fffffffffffffed0 = 0;
    uVar13 = CONCAT22(uVar14,*(undefined2 *)(param_1 + 0x10));
    FUN_14006c2f0(4,0x10,param_1[10],param_1[0xb],uVar13,0,0,uVar5,0);
    uVar14 = (undefined2)((uint)uVar13 >> 0x10);
    uVar13 = (undefined4)((ulonglong)uVar5 >> 0x20);
    local_res8 = (float)param_1[10];
  }
  fVar12 = DAT_14053ab70;
  if (param_1[6] == 0x10e) {
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472d4);
      FUN_14018a340(DAT_140e472d4,1,1);
      local_res8 = (float)param_1[10];
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + DAT_140539e40;
    if (param_1[5] == 0) {
      local_res8 = (float)param_1[10];
      fVar1 = (float)param_1[0xb];
      fVar11 = DAT_140e445d8 / fVar12;
      if ((((local_res8 < fVar11 + 0.0) || (fVar11 + DAT_14053aec0 < local_res8)) || (fVar1 < 0.0))
         || (DAT_14053af14 < fVar1)) {
        sVar7 = *(short *)(param_1 + 0x10);
        sVar6 = -0x8000 - sVar7;
        if (fVar11 + 0.0 <= local_res8) {
          sVar6 = sVar7;
        }
        if (fVar11 + DAT_14053aec0 < local_res8) {
          sVar6 = -0x8000 - sVar7;
        }
        if (fVar1 < 0.0) {
          sVar6 = -sVar7;
        }
        if (DAT_14053af14 < fVar1) {
          sVar6 = -sVar7;
        }
        *(short *)(param_1 + 0x10) = sVar6;
        uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0);
        param_1[5] = param_1[5] + 1;
        local_res8 = (float)uVar5;
        uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
        param_1[10] = local_res8;
        param_1[0xb] = uStackX_c;
      }
    }
    in_stack_fffffffffffffed0 = 0;
    FUN_14006c2f0(4,0xf,local_res8,param_1[0xb],CONCAT22(uVar14,*(undefined2 *)(param_1 + 0x10)),0,0
                  ,CONCAT44(uVar13,1),0);
  }
  iVar8 = param_1[3];
  if (iVar8 < 0) {
    dVar9 = 0.0;
  }
  else {
    dVar9 = DAT_140539f40;
    if (iVar8 < 0x3c) {
      dVar9 = (double)FUN_140332d90(((double)iVar8 - 0.0) * DAT_14053a628 * dVar4 * dVar3);
      dVar9 = dVar9 + 0.0;
    }
  }
  FUN_1400c8410(DAT_140e44904,0x24,7,param_1[10],param_1[0xb],in_stack_fffffffffffffed0 & 0xffff0000
                ,dVar9,dVar9,0xff,0xff,0xff,0xff,1,0);
  fVar12 = DAT_140e445d8 / fVar12;
  if ((((float)param_1[10] < fVar12 - DAT_14053ad9c) ||
      (fVar12 + DAT_14053af38 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  if ((iStack_cc < 1) || (DAT_140e4430c < 1)) {
    *param_1 = 0;
  }
  return;
}


