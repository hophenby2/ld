// Function: FUN_140034670 @ 140034670
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140034670(undefined4 *param_1)

{
  ushort *puVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ushort uVar11;
  longlong lVar12;
  ushort uVar13;
  int iVar14;
  longlong lVar15;
  int iVar16;
  short sVar17;
  uint uVar18;
  ushort uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  short sVar23;
  int iVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  float fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  undefined4 in_stack_fffffffffffffe98;
  undefined2 uVar33;
  undefined4 in_stack_fffffffffffffea0;
  undefined4 uVar34;
  undefined2 uVar35;
  undefined8 in_stack_fffffffffffffeb0;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 uStack_f0;
  
  lVar15 = DAT_140e45d80;
  iVar16 = DAT_140e44308;
  uVar35 = (undefined2)((uint)in_stack_fffffffffffffea0 >> 0x10);
  uVar33 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  uStack_100 = 0;
  uStack_100._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar12 = DAT_140e45d80, uStack_100._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar12 + 4) == DAT_140e44308) {
        uStack_110 = *(undefined8 *)(lVar12 + 8);
        local_108 = *(undefined8 *)(lVar12 + 0x10);
        uStack_100 = *(undefined8 *)(lVar12 + 0x18);
        uStack_f0 = *(undefined8 *)(lVar12 + 0x28);
      }
      lVar12 = *(longlong *)(lVar12 + 0x60);
    } while (lVar12 != 0);
  }
  fVar31 = (float)uStack_f0 + (float)param_1[0xc];
  fVar32 = uStack_f0._4_4_ + (float)param_1[0xd];
  dVar2 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar32),0),
                                SUB84((double)(DAT_140e445d8 - fVar31),0));
  dVar2 = dVar2 * DAT_14053aba0;
  uVar13 = *(ushort *)(param_1 + 0x10);
  uVar18 = (uint)uVar13;
  uVar29 = SUB84((double)uVar13 * DAT_14053a020 * DAT_140539d28,0);
  dVar3 = (double)FUN_1403307c0(uVar29);
  dVar3 = dVar3 * DAT_14053a278;
  dVar4 = (double)FUN_140332d90(uVar29);
  dVar4 = dVar4 * DAT_14053a278;
  param_1[10] = (float)dVar3 + fVar31;
  param_1[0xb] = (float)dVar4 + fVar32;
  dVar3 = (double)FUN_1403307c0(uVar29);
  dVar3 = dVar3 * DAT_14053a380;
  dVar4 = (double)FUN_140332d90(uVar29);
  uVar10 = _UNK_14053bb2c;
  uVar9 = _UNK_14053bb28;
  uVar8 = _UNK_14053bb24;
  uVar29 = _DAT_14053bb20;
  dVar4 = dVar4 * DAT_14053a380;
  if (local_108._4_4_ != 1) goto LAB_140034c9a;
  iVar24 = uStack_110._4_4_ % 0xa28;
  if ((iVar24 < 0x3c0) || (0x63f < iVar24)) {
    puVar1 = (ushort *)((longlong)param_1 + 0x42);
    if (param_1[6] == 0x89) {
      dVar5 = (double)FUN_1403300b4(SUB84((double)((uStack_f0._4_4_ + DAT_14053accc) - fVar32),0),
                                    SUB84((double)(((float)uStack_f0 - DAT_14053acfc) - fVar31),0));
      uVar20 = (uint)(dVar5 * DAT_14053aba0);
      *puVar1 = (ushort)uVar20;
    }
    else {
      uVar20 = (uint)*puVar1;
      if (param_1[6] == 0x8a) {
        dVar5 = (double)FUN_1403300b4(SUB84((double)((uStack_f0._4_4_ + DAT_14053accc) - fVar32),0),
                                      SUB84((double)(((float)uStack_f0 + DAT_14053acfc) - fVar31),0)
                                     );
        dVar5 = dVar5 * DAT_14053aba0;
        *puVar1 = (ushort)(int)dVar5;
        uVar20 = (int)dVar5 & 0xffff;
      }
    }
    uVar11 = (short)uVar20 - uVar13;
    uVar18 = (uint)uVar11;
    if (0x8000 < uVar11) {
      uVar18 = 0x10000 - uVar11;
    }
    iVar21 = (uVar20 & 0xffff) - (uint)uVar13;
    iVar22 = (int)uVar18 / 10 + 0x30;
    iVar14 = iVar21 + 0x10000;
    if (-0x8001 < iVar21) {
      iVar14 = iVar21;
    }
    iVar21 = iVar14 + -0x10000;
    if (iVar14 < 0x8001) {
      iVar21 = iVar14;
    }
    if (iVar21 < 1) {
      uVar18 = (uint)uVar13;
      if ((iVar21 < 0) && (uVar18 = (uint)(ushort)(uVar13 - (short)iVar22), -iVar22 < iVar21)) {
        uVar18 = uVar20 & 0xffff;
      }
    }
    else if (iVar21 < iVar22) {
      uVar18 = uVar20 & 0xffff;
    }
    else {
      uVar18 = (uint)(ushort)(uVar13 + (short)iVar22);
    }
    *(short *)(param_1 + 0x10) = (short)uVar18;
    if (iVar24 - 0x3c0U < 0x280) goto LAB_1400349b9;
  }
  else {
LAB_1400349b9:
    sVar17 = (short)uVar18;
    sVar23 = (short)(int)dVar2;
    *(short *)((longlong)param_1 + 0x42) = sVar23;
    if (iVar24 < 0x3d4) {
      uVar13 = sVar23 - sVar17;
      uVar20 = (uint)uVar13;
      if (0x8000 < uVar13) {
        uVar20 = 0x10000 - uVar13;
      }
      iVar14 = ((int)dVar2 & 0xffffU) - uVar18;
      iVar21 = (int)uVar20 / 10 + 0x30;
      iVar24 = iVar14 + 0x10000;
      if (-0x8001 < iVar14) {
        iVar24 = iVar14;
      }
      iVar14 = iVar24 + -0x10000;
      if (iVar24 < 0x8001) {
        iVar14 = iVar24;
      }
      if (iVar14 < 1) {
        if ((iVar14 < 0) && (sVar17 = sVar17 - (short)iVar21, -iVar21 < iVar14)) {
          sVar17 = sVar23;
        }
        *(short *)(param_1 + 0x10) = sVar17;
      }
      else if (iVar14 < iVar21) {
        *(short *)(param_1 + 0x10) = sVar23;
      }
      else {
        *(short *)(param_1 + 0x10) = sVar17 + (short)iVar21;
      }
    }
    else {
      iVar14 = 1;
      uVar18 = (uint)*(ushort *)(param_1 + 0x10);
      if (DAT_140e419b8 == 0) {
        iVar14 = 0x2d;
      }
      else if (DAT_140e419b8 == 1) {
        iVar14 = 0x24;
      }
      else if (DAT_140e419b8 == 2) {
        iVar14 = 0x1e;
      }
      else if (DAT_140e419b8 == 3) {
        iVar14 = 0x18;
      }
      else if (DAT_140e419b8 == 4) {
        iVar14 = 0x14;
      }
      if (DAT_140e419b8 == 0) {
        uVar25 = (undefined4)DAT_14053a0d0;
        uVar26 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar25 = (undefined4)DAT_14053a118;
        uVar26 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar25 = (undefined4)DAT_14053a138;
        uVar26 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar25 = (undefined4)DAT_14053a178;
        uVar26 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
      }
      else {
        uVar25 = uVar29;
        uVar26 = uVar8;
        if (DAT_140e419b8 == 4) {
          uVar25 = (undefined4)DAT_14053a1b8;
          uVar26 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
        }
      }
      iVar14 = (iVar24 + -0x3d4) % iVar14;
      if ((iVar14 < 9) &&
         (iVar14 == (iVar14 / 3 + (iVar14 >> 0x1f) +
                    (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3)) {
        uVar34 = DAT_14053ac2c;
        FUN_14006c2f0(6,0,(float)dVar3 + fVar31,(float)dVar4 + fVar32,
                      CONCAT22(uVar33,*(ushort *)(param_1 + 0x10)),DAT_14053ac2c,
                      CONCAT44(uVar26,uVar25),CONCAT44(uVar28,1),0);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar18 = (uint)*(ushort *)(param_1 + 0x10);
        lVar15 = DAT_140e45d80;
        iVar16 = DAT_140e44308;
      }
      uVar13 = (ushort)uVar18;
      if (7 < iVar14) {
        uVar11 = *(ushort *)((longlong)param_1 + 0x42);
        iVar14 = uVar11 - uVar18;
        iVar24 = iVar14 + 0x10000;
        if (-0x8001 < iVar14) {
          iVar24 = iVar14;
        }
        iVar14 = iVar24 + -0x10000;
        if (iVar24 < 0x8001) {
          iVar14 = iVar24;
        }
        if (iVar14 < 1) {
          uVar19 = uVar13;
          if ((iVar14 < 0) && (uVar19 = uVar13 - 0x8ae, -0x8ae < iVar14)) {
            uVar19 = uVar11;
          }
        }
        else {
          uVar19 = uVar11;
          if (0x8ad < iVar14) {
            uVar19 = uVar13 + 0x8ae;
          }
        }
        *(ushort *)(param_1 + 0x10) = uVar19;
      }
    }
  }
  if (uStack_110._4_4_ == 1) {
    param_1[8] = DAT_140e41b0c;
    param_1[7] = uStack_100._4_4_;
    param_1[0x15] = 0;
  }
  iVar14 = DAT_140e44e6c;
  iVar24 = param_1[7];
  if ((iVar24 < uStack_100._4_4_) && (lVar12 = lVar15, 0 < DAT_140e44e6c)) {
    for (; lVar12 != 0; lVar12 = *(longlong *)(lVar12 + 0x60)) {
      if (*(int *)(lVar12 + 4) == iVar16) {
        *(int *)(lVar12 + 0x1c) = *(int *)(lVar12 + 0x1c) - (uStack_100._4_4_ - iVar24);
      }
    }
  }
  iVar24 = param_1[7];
  if (uStack_100._4_4_ < iVar24) {
    param_1[7] = uStack_100._4_4_;
    iVar24 = uStack_100._4_4_;
  }
  if ((iVar24 < 1) && (0 < iVar14)) {
    for (; lVar15 != 0; lVar15 = *(longlong *)(lVar15 + 0x60)) {
      if (*(int *)(lVar15 + 4) == iVar16) {
        *(int *)(lVar15 + 0x1c) = *(int *)(lVar15 + 0x1c) - uStack_100._4_4_;
      }
    }
  }
LAB_140034c9a:
  uVar13 = *(ushort *)(param_1 + 0x10);
  uVar28 = SUB84((double)uVar13 * DAT_14053a020 * DAT_140539d28,0);
  dVar2 = (double)FUN_1403307c0(uVar28);
  fVar30 = (float)(dVar2 * DAT_14053a4a0) + fVar31;
  dVar2 = (double)FUN_140332d90(uVar28);
  uVar7 = DAT_140539fc8;
  uVar6 = DAT_140539f38;
  fVar27 = (float)(dVar2 * DAT_14053a4a0) + fVar32;
  if (param_1[6] == 0x89) {
    uVar28 = CONCAT22(uVar35,uVar13);
    FUN_1400c8410(DAT_140e447a4,0x1c,8,fVar30,fVar27,uVar28,DAT_140539fc8,DAT_140539f38,0xff,0,0xff,
                  0x40,1,0);
    uVar35 = (undefined2)((uint)uVar28 >> 0x10);
    uVar13 = *(ushort *)(param_1 + 0x10);
  }
  if (param_1[6] == 0x8a) {
    uVar28 = CONCAT22(uVar35,uVar13);
    FUN_1400c8410(DAT_140e447a4,0x1c,8,fVar30,fVar27,uVar28,uVar7,uVar6,0,0xff,0xff,0x40,1,0);
    uVar35 = (undefined2)((uint)uVar28 >> 0x10);
  }
  FUN_1400c8410(DAT_140e447f0,0x1c,7,fVar31,fVar32,CONCAT22(uVar35,*(undefined2 *)(param_1 + 0x10)),
                CONCAT44(uVar8,uVar29),CONCAT44(uVar10,uVar9),0xff,0xff,0xff,0xff,1,0);
  if (9 < local_108._4_4_) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


