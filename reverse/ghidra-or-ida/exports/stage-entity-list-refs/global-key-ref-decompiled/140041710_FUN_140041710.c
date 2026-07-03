// Function: FUN_140041710 @ 140041710
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140041710(undefined4 *param_1)

{
  longlong lVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float fVar21;
  undefined4 in_stack_fffffffffffffea8;
  undefined2 uVar22;
  undefined4 in_stack_fffffffffffffeb0;
  ushort uVar24;
  undefined4 uVar23;
  undefined8 in_stack_fffffffffffffec0;
  undefined8 local_f8;
  undefined8 local_d8;
  undefined8 uStack_d0;
  
  dVar2 = DAT_140539f28;
  uVar24 = (ushort)((uint)in_stack_fffffffffffffeb0 >> 0x10);
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffea8 >> 0x10);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  lVar1 = DAT_140e45d80;
  fVar21 = uStack_d0._4_4_;
  iVar12 = local_f8._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      fVar21 = (float)((ulonglong)uStack_d0 >> 0x20);
      iVar12 = (int)((ulonglong)local_f8 >> 0x20);
      if (lVar1 == 0) break;
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        local_f8 = *(undefined8 *)(lVar1 + 0x10);
        local_d8 = *(undefined8 *)(lVar1 + 0x30);
        uStack_d0 = *(undefined8 *)(lVar1 + 0x38);
      }
      lVar1 = *(longlong *)(lVar1 + 0x60);
    }
  }
  local_f8._4_4_ = iVar12;
  uStack_d0._4_4_ = fVar21;
  local_d8._0_4_ = (float)local_d8 + (float)param_1[0xe];
  fVar21 = local_d8._4_4_ + uStack_d0._4_4_ + (float)param_1[0xf];
  param_1[10] = (float)local_d8;
  param_1[0xb] = fVar21;
  if (param_1[5] == 0) {
    if (fVar21 < DAT_14053b358) goto LAB_140041dd6;
    param_1[5] = 1;
    param_1[3] = 0;
    param_1[0x15] = 0;
  }
  else if (param_1[5] != 1) goto LAB_140041dd6;
  dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar21),
                                 SUB84((double)(DAT_140e445d8 - (float)local_d8),0));
  uVar7 = _UNK_14053bb2c;
  uVar6 = _UNK_14053bb28;
  uVar5 = _UNK_14053bb24;
  uVar4 = _DAT_14053bb20;
  iVar12 = param_1[3];
  uVar16 = (uint)(dVar17 * DAT_14053aba0);
  uVar15 = (ushort)uVar16;
  if ((iVar12 < 0x1e) || (DAT_14053ae2c <= fVar21)) {
    uVar13 = *(ushort *)(param_1 + 0x10);
    uVar8 = uVar15 - uVar13;
    uVar10 = (uint)uVar8;
    if (0x8000 < uVar8) {
      uVar10 = 0x10000 - uVar8;
    }
    iVar9 = (uVar16 & 0xffff) - (uint)uVar13;
    iVar14 = (int)uVar10 / 10 + 0x30;
    iVar12 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar12 = iVar9;
    }
    iVar9 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar9 = iVar12;
    }
    if (iVar9 < 1) {
      uVar8 = uVar13;
      if ((iVar9 < 0) && (uVar8 = uVar13 - (short)iVar14, -iVar14 < iVar9)) {
        uVar8 = uVar15;
      }
    }
    else {
      uVar8 = uVar15;
      if (iVar14 <= iVar9) {
        uVar8 = uVar13 + (short)iVar14;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar8;
  }
  else {
    uVar13 = *(ushort *)(param_1 + 0x10);
    dVar17 = (double)uVar13 * DAT_14053a020 * DAT_140539d28;
    dVar18 = (double)FUN_1403307c0(dVar17);
    local_d8._0_4_ = (float)(dVar18 * DAT_14053a2b0) + (float)local_d8;
    dVar17 = (double)FUN_140332d90(dVar17);
    uVar3 = DAT_14053aca8;
    iVar9 = 1;
    fVar21 = (float)(dVar17 * DAT_14053a2b0) + fVar21;
    if (DAT_140e419b8 == 0) {
      iVar9 = 0x5a;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0x46;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar9 = 0x37;
    }
    if (DAT_140e419b8 == 0) {
      uVar19 = (int)DAT_14053a178;
      uVar20 = (int)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar19 = (int)DAT_14053a1b8;
      uVar20 = (int)((ulonglong)DAT_14053a1b8 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar19 = (int)DAT_14053a1c8;
      uVar20 = (int)((ulonglong)DAT_14053a1c8 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar19 = (int)DAT_14053a1e8;
      uVar20 = (int)((ulonglong)DAT_14053a1e8 >> 0x20);
    }
    else {
      uVar19 = uVar4;
      uVar20 = uVar5;
      if (DAT_140e419b8 == 4) {
        uVar19 = (int)DAT_14053a210;
        uVar20 = (int)((ulonglong)DAT_14053a210 >> 0x20);
      }
    }
    uVar10 = (iVar12 + -0x1e) % iVar9;
    if ((int)uVar10 < 0x18) {
      uVar10 = uVar10 & 0x80000003;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
      }
      if (uVar10 == 0) {
        FUN_14006c2f0(7,0,(float)local_d8,fVar21,CONCAT22(uVar22,uVar13),DAT_14053aca8,
                      CONCAT44(uVar20,uVar19),CONCAT44(uVar23,1),0);
        sVar11 = *(short *)(param_1 + 0x10);
        dVar17 = (double)CONCAT44(uVar20,uVar19) - dVar2;
        iVar12 = 0;
        do {
          uVar23 = uVar3;
          FUN_14006c2f0(7,0,(float)local_d8,fVar21,(short)iVar12 * 0x4b0 + sVar11 + -600,uVar3,
                        dVar17,1,0);
          uVar24 = (ushort)((uint)uVar23 >> 0x10);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 2);
        sVar11 = *(short *)(param_1 + 0x10);
        if (0 < DAT_140e419b8) {
          dVar18 = (double)CONCAT44(uVar20,uVar19) - DAT_140539fa8;
          iVar12 = 0;
          do {
            uVar23 = uVar3;
            FUN_14006c2f0(7,0,(float)local_d8,fVar21,(short)iVar12 * 0x960 + sVar11 + -0x4b0,uVar3,
                          dVar18,1,0);
            uVar24 = (ushort)((uint)uVar23 >> 0x10);
            iVar12 = iVar12 + 1;
          } while (iVar12 < 2);
          sVar11 = *(short *)(param_1 + 0x10);
        }
        if (2 < DAT_140e419b8) {
          iVar12 = 0;
          do {
            uVar23 = uVar3;
            FUN_14006c2f0(7,0,(float)local_d8,fVar21,(short)iVar12 * 0xe10 + sVar11 + -0x708,uVar3,
                          dVar17,1,0);
            uVar24 = (ushort)((uint)uVar23 >> 0x10);
            iVar12 = iVar12 + 1;
          } while (iVar12 < 2);
        }
      }
    }
    if (0x18 < (param_1[3] + -0x1e) % iVar9) {
      uVar13 = *(ushort *)(param_1 + 0x10);
      uVar8 = uVar15 - uVar13;
      uVar10 = (uint)uVar8;
      if (0x8000 < uVar8) {
        uVar10 = 0x10000 - uVar8;
      }
      iVar9 = (uVar16 & 0xffff) - (uint)uVar13;
      iVar14 = (int)uVar10 / 10 + 0x30;
      iVar12 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar12 = iVar9;
      }
      iVar9 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar9 = iVar12;
      }
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar13 = uVar13 - (short)iVar14, -iVar14 < iVar9)) {
          uVar13 = uVar15;
        }
        *(ushort *)(param_1 + 0x10) = uVar13;
      }
      else if (iVar9 < iVar14) {
        *(ushort *)(param_1 + 0x10) = uVar15;
      }
      else {
        *(ushort *)(param_1 + 0x10) = uVar13 + (short)iVar14;
      }
    }
  }
  uVar23 = CONCAT22(uVar24,*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e44d68,0x18,7,(float)param_1[10] + DAT_14053ac48,
                (float)param_1[0xb] + DAT_14053ac28,uVar23,CONCAT44(uVar5,uVar4),
                CONCAT44(uVar7,uVar6),0,0,0,0x40,1,0);
  uVar23 = CONCAT22((short)((uint)uVar23 >> 0x10),*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e44d68,0x20,7,param_1[10],param_1[0xb],uVar23,CONCAT44(uVar5,uVar4),
                CONCAT44(uVar7,uVar6),0xff,0xff,0xff,0xff,1,0);
  uVar24 = (ushort)((uint)uVar23 >> 0x10);
  FUN_140079c10(param_1,1);
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,10);
  }
  else if (local_f8._4_4_ < 10) goto LAB_140041dd6;
  FUN_140079e20(param_1,1);
  param_1[5] = param_1[5] + 1;
  param_1[3] = 0;
  param_1[0x15] = 1;
LAB_140041dd6:
  if (param_1[5] == 2) {
    FUN_1400c8410(DAT_140e41a88,0x15,7,param_1[10],param_1[0xb],(uint)uVar24 << 0x10,dVar2,
                  DAT_140539f00,0xff,0xff,0xff,0xc0,1,0);
  }
  if ((DAT_14053af80 <= (float)param_1[0xb]) || (0x13 < local_f8._4_4_)) {
    *param_1 = 0;
  }
  return;
}


