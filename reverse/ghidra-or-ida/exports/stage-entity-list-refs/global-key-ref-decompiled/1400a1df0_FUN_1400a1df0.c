// Function: FUN_1400a1df0 @ 1400a1df0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a1df0(undefined4 *param_1)

{
  float fVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  short sVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined8 in_stack_fffffffffffffed0;
  undefined4 uVar18;
  int iStack_dc;
  undefined8 uStack_d0;
  
  uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  iStack_dc = 0;
  iVar6 = 0;
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_dc = iVar6, lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == param_1[2]) {
        iStack_dc = *(int *)(lVar2 + 0x1c);
        uStack_d0 = *(undefined8 *)(lVar2 + 0x28);
      }
      iVar6 = iStack_dc;
    }
  }
  fVar15 = (float)DAT_1407c77a4;
  fVar1 = (float)param_1[0xf];
  param_1[0xf] = fVar15 + fVar1;
  dVar12 = DAT_14053a4d8;
  dVar14 = DAT_14053a020;
  dVar13 = DAT_140539d28;
  if (param_1[5] != 0) goto LAB_1400a22c5;
  uVar7 = param_1[3];
  uVar5 = (int)uVar7 >> 0x1f;
  if (uVar7 < 0x78) {
    dVar11 = (double)FUN_140332d90(((double)(int)uVar7 - 0.0) * DAT_14053a4d8 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar16 = (undefined2)((uint)(float)(int)(dVar11 * DAT_14053a380) >> 0x10);
LAB_1400a1f48:
    dVar12 = (double)FUN_140332d90(((double)(int)uVar7 - 0.0) * dVar12 * dVar14 * dVar13);
    uVar17 = (undefined2)((uint)(float)(int)(dVar12 * DAT_14053a430) >> 0x10);
LAB_1400a1f9d:
    dVar12 = (double)FUN_140332d90(((double)(int)uVar7 - 0.0) * DAT_14053a438 * dVar14 * dVar13);
    iVar6 = (int)(dVar12 * DAT_14053b1b8);
  }
  else {
    uVar16 = (undefined2)((uint)(float)(int)((uVar5 & 0xffffffce) + 0x32) >> 0x10);
    if ((-1 < (int)uVar7) && ((int)uVar7 < 0x78)) goto LAB_1400a1f48;
    iVar6 = (uVar5 & 0x78) - 0x78;
    uVar17 = (undefined2)((uint)(float)(int)((uVar5 & 0xffffffa6) + 0x5a) >> 0x10);
    if ((-1 < (int)uVar7) && ((int)uVar7 < 0xb4)) goto LAB_1400a1f9d;
  }
  dVar12 = ((double)DAT_140e418c8 - 0.0) * _DAT_14053a4e8;
  param_1[0xd] = (float)iVar6 + fVar15 + fVar1;
  dVar13 = (double)FUN_140332d90(dVar12 * dVar14 * dVar13);
  sVar10 = *(short *)((longlong)param_1 + 0x42) - (short)(int)(dVar13 * _DAT_14053b1d0);
  *(short *)((longlong)param_1 + 0x42) = sVar10;
  uVar4 = FUN_140133f30();
  uVar3 = _UNK_14053bb28;
  dVar13 = _DAT_14053bb20;
  fVar1 = DAT_14053ae70;
  local_res8 = (undefined4)uVar4;
  uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
  param_1[10] = local_res8;
  param_1[0xb] = uStackX_c;
  if (uStack_d0._4_4_ < fVar1) {
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x24;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      iVar6 = 0x20;
    }
    iVar9 = 1;
    if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
      iVar9 = 0x10;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar9 = 0x14;
    }
    uVar8 = 1;
    if ((DAT_140e419b8 != 0) &&
       ((((DAT_140e419b8 == 1 || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
        (DAT_140e419b8 == 4)))) {
      uVar8 = 2;
    }
    dVar14 = DAT_14053a0a0;
    if (((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
       ((dVar14 = DAT_14053a0f8, DAT_140e419b8 != 2 &&
        ((DAT_140e419b8 != 3 && (dVar14 = dVar13, DAT_140e419b8 == 4)))))) {
      dVar14 = DAT_14053a158;
    }
    if ((0x27 < (int)uVar7) && (uVar7 = (int)(uVar7 - 0x28) % iVar6, (int)uVar7 < iVar9)) {
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        uVar17 = 0;
        FUN_1400709b0(5,fVar1,local_res8,uStackX_c,CONCAT22(uVar16,sVar10),0,dVar14,
                      CONCAT44(uVar18,1),uVar8,4000,0);
        if (2 < DAT_140e419b8) {
          uVar17 = 0;
          FUN_1400709b0(5,0,param_1[10],param_1[0xb],*(undefined2 *)((longlong)param_1 + 0x42),0,
                        dVar14 + DAT_140539f00,1,uVar8,4000,0);
        }
      }
    }
  }
  FUN_1400c8410(DAT_140e44778,0x1c,7,param_1[10],param_1[0xb],
                CONCAT22(uVar17,*(short *)(param_1 + 3) * 0x22b),dVar13,uVar3,0xff,0xff,0xff,0xff,1,
                0);
LAB_1400a22c5:
  if (iStack_dc < 1) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (DAT_14053af2c <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


