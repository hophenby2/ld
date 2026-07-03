// Function: FUN_140094bc0 @ 140094bc0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140094bc0(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  int iVar8;
  ulonglong *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 in_stack_fffffffffffffec8;
  undefined2 uVar21;
  undefined4 in_stack_fffffffffffffed0;
  undefined4 uVar22;
  undefined2 uVar23;
  ulonglong local_e8;
  undefined8 uStack_d0;
  undefined8 uStack_c0;
  ulonglong local_b8;
  
  uVar23 = (undefined2)((uint)in_stack_fffffffffffffed0 >> 0x10);
  uVar21 = (undefined2)((uint)in_stack_fffffffffffffec8 >> 0x10);
  uStack_d0._4_4_ = 0;
  local_e8 = local_e8 & 0xffffffff00000000;
  uStack_d0 = 0;
  iVar12 = 0;
  if ((0 < DAT_140e44e6c) && (puVar9 = DAT_140e45d80, iVar12 = 0, DAT_140e45d80 != (ulonglong *)0x0)
     ) {
    do {
      if (*(int *)((longlong)puVar9 + 4) == param_1[2]) {
        local_e8 = *puVar9;
        uStack_d0 = puVar9[3];
        uStack_c0 = puVar9[5];
        local_b8 = puVar9[6];
      }
      puVar9 = (ulonglong *)puVar9[0xc];
    } while (puVar9 != (ulonglong *)0x0);
    iVar12 = (int)local_e8;
  }
  dVar3 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - (float)param_1[0xb]),0),
                                SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar6 = _UNK_14053bb28;
  uVar5 = _UNK_14053bb24;
  uVar4 = _DAT_14053bb20;
  fVar20 = uStack_c0._4_4_ + (float)param_1[0xd];
  uVar15 = (uint)(dVar3 * DAT_14053aba0);
  param_1[0xb] = fVar20;
  uStack_c0._0_4_ = (float)param_1[0xc] + (float)uStack_c0;
  param_1[10] = (float)uStack_c0;
  if (param_1[5] == 0) {
    if (param_1[3] == 0) {
      if ((float)local_b8 < DAT_14053ae30) {
        param_1[0xc] = (float)param_1[0xc] * DAT_14053b044;
      }
      goto LAB_140095081;
    }
    if (param_1[3] != 0x14) goto LAB_140095081;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_140095081;
  uVar1 = *(ushort *)(param_1 + 0x10);
  uVar13 = (uint)uVar1;
  iVar16 = ((int)(local_e8 >> 0x20) - param_1[1]) * 0xc + 0x1e;
  uVar7 = (short)uVar15 - uVar1;
  uVar10 = (uint)uVar7;
  if (0x8000 < uVar7) {
    uVar10 = 0x10000 - uVar7;
  }
  iVar11 = (uVar15 & 0xffff) - (uint)uVar1;
  iVar14 = (int)uVar10 / 10 + 0x30;
  iVar8 = iVar11 + 0x10000;
  if (-0x8001 < iVar11) {
    iVar8 = iVar11;
  }
  iVar11 = iVar8 + -0x10000;
  if (iVar8 < 0x8001) {
    iVar11 = iVar8;
  }
  if (iVar11 < 1) {
    if ((iVar11 < 0) && (uVar13 = (uint)(ushort)(uVar1 - (short)iVar14), -iVar14 < iVar11)) {
      uVar13 = uVar15 & 0xffff;
    }
  }
  else if (iVar11 < iVar14) {
    uVar13 = uVar15 & 0xffff;
  }
  else {
    uVar13 = (uint)(ushort)(uVar1 + (short)iVar14);
  }
  iVar8 = param_1[3];
  *(short *)(param_1 + 0x10) = (short)uVar13;
  if ((((iVar8 < iVar16) || ((float)uStack_c0 < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac80)) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aed4 < (float)uStack_c0)) ||
     ((fVar20 < DAT_14053b33c || (DAT_14053af28 < fVar20)))) goto LAB_140095081;
  uVar19 = SUB84((double)uVar13 * DAT_14053a020 * DAT_140539d28,0);
  dVar3 = (double)FUN_1403307c0(uVar19);
  uStack_c0._0_4_ = (float)(dVar3 * DAT_14053a390) + (float)uStack_c0;
  dVar3 = (double)FUN_140332d90(uVar19);
  uVar19 = DAT_14053ac2c;
  iVar11 = 1;
  fVar20 = (float)(dVar3 * DAT_14053a390) + fVar20;
  if (DAT_140e419b8 == 0) {
    iVar11 = 0x5f;
  }
  else if (DAT_140e419b8 == 1) {
    iVar11 = 0x3c;
  }
  else if (DAT_140e419b8 == 2) {
    iVar11 = 0x2d;
  }
  else if (DAT_140e419b8 == 3) {
    iVar11 = 0x26;
  }
  else if (DAT_140e419b8 == 4) {
    iVar11 = 0x1b;
  }
  if (DAT_140e419b8 == 0) {
    uVar17 = (undefined4)DAT_14053a090;
    uVar18 = (undefined4)((ulonglong)DAT_14053a090 >> 0x20);
  }
  else if (DAT_140e419b8 == 1) {
LAB_140094f23:
    uVar17 = (undefined4)DAT_14053a0d0;
    uVar18 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  }
  else if (DAT_140e419b8 == 2) {
    uVar17 = (undefined4)DAT_14053a0f8;
    uVar18 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
  }
  else {
    if (DAT_140e419b8 == 3) goto LAB_140094f23;
    uVar17 = uVar4;
    uVar18 = uVar5;
    if (DAT_140e419b8 == 4) {
      uVar17 = (undefined4)DAT_14053a138;
      uVar18 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    }
  }
  uVar2 = (longlong)(iVar8 - iVar16) % (longlong)iVar11;
  if ((int)uVar2 == 0) {
    FUN_14006c2f0(6,uVar2 & 0xffffffff,(float)uStack_c0,fVar20,CONCAT22(uVar21,(short)uVar13),
                  DAT_14053ac2c,CONCAT44(uVar18,uVar17),1,0);
    uVar22 = uVar19;
    FUN_14006c2f0(6,0,(float)uStack_c0,fVar20,*(undefined2 *)(param_1 + 0x10),uVar19,
                  (double)CONCAT44(uVar18,uVar17) + DAT_140539ef8,1,0);
    uVar23 = (undefined2)((uint)uVar22 >> 0x10);
    if (2 < DAT_140e419b8) {
      FUN_14006c2f0(6,0,(float)uStack_c0,fVar20,*(undefined2 *)(param_1 + 0x10),uVar19,
                    (double)CONCAT44(uVar18,uVar17) + DAT_140539fc8,1,0);
      FUN_14006c2f0(6,0,(float)uStack_c0,fVar20,*(undefined2 *)(param_1 + 0x10),uVar19,
                    (double)CONCAT44(uVar18,uVar17) + DAT_140539fe8,1,0);
      uVar23 = (undefined2)((uint)uVar19 >> 0x10);
    }
  }
LAB_140095081:
  FUN_1400c8410(DAT_140e44bf0,0x1e,7,param_1[10],param_1[0xb],
                CONCAT22(uVar23,*(undefined2 *)(param_1 + 0x10)),CONCAT44(uVar5,uVar4),uVar6,0xff,
                0xff,0xff,0xff,1,0);
  if (uStack_d0._4_4_ < 1) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (iVar12 == 0) {
    *param_1 = 0;
  }
  return;
}


