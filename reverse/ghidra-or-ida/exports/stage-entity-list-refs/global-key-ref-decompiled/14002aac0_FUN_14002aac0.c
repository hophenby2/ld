// Function: FUN_14002aac0 @ 14002aac0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14002aac0(undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  longlong lVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  float fVar26;
  float fVar27;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined2 uVar30;
  undefined2 uVar31;
  undefined8 uStack_148;
  int iStack_134;
  undefined8 uStack_128;
  
  fVar17 = DAT_14053af48;
  fVar27 = DAT_14053ae2c;
  dVar4 = DAT_140539f40;
  iStack_134 = 0;
  iVar9 = 0;
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_134 = iVar9, lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == DAT_140e44308) {
        uStack_148 = *(undefined8 *)(lVar3 + 8);
        iStack_134 = *(int *)(lVar3 + 0x1c);
        uStack_128 = *(undefined8 *)(lVar3 + 0x28);
      }
      iVar9 = iStack_134;
    }
  }
  uVar31 = 0;
  iVar9 = FUN_1400c9580(DAT_140e418c8,0,4,6,0x48,0x49,0x4a,0x4b,0x4c,0x4d);
  dVar23 = DAT_14053a6d8;
  dVar2 = DAT_14053a020;
  dVar21 = DAT_140539d28;
  uVar24 = SUB84(DAT_140539d28,0);
  uVar25 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar22 = dVar4;
  if (param_1[5] != 0) goto LAB_14002aed9;
  iVar1 = param_1[3];
  if (iVar1 == 0) {
    *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
LAB_14002ac56:
    dVar20 = (double)FUN_140332d90(((double)iVar1 - 0.0) * dVar23 * dVar2 * dVar21);
    fVar27 = (float)(int)(dVar20 * _DAT_14053a688);
LAB_14002acb6:
    dVar21 = (double)FUN_140332d90(((double)iVar1 - 0.0) * dVar23 * dVar2 * dVar21);
    fVar17 = (float)(int)(dVar21 * DAT_14053a888);
LAB_14002ad12:
    uStack_128._4_4_ = uStack_128._4_4_ - DAT_14053ad00;
    uStack_128._0_4_ = (float)uStack_128 - DAT_14053ac98;
    dVar21 = (double)FUN_140332d90();
    fVar19 = DAT_14053ae30;
    fVar18 = DAT_14053ae30 - (float)uStack_128;
    dVar20 = (double)FUN_140332d90();
    param_1[0xc] = (float)(dVar21 * (double)fVar18) + (float)uStack_128;
    uVar24 = SUB84(DAT_140539d28,0);
    uVar25 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    param_1[0xd] = (float)(dVar20 * (double)(fVar19 - uStack_128._4_4_)) + uStack_128._4_4_;
  }
  else {
    if ((-1 < iVar1) && (iVar1 < 0x28)) goto LAB_14002ac56;
    fVar27 = (float)(int)((iVar1 >> 0x1f & 0xfffffea2U) + 0x15e);
    if ((-1 < iVar1) && (iVar1 < 0x28)) goto LAB_14002acb6;
    fVar17 = (float)(int)((iVar1 >> 0x1f & 0xfffffce0U) + 800);
    if (iVar1 < 0x28) goto LAB_14002ad12;
  }
  uVar31 = (undefined2)((uint)fVar17 >> 0x10);
  uVar10 = FUN_140133f30();
  local_res10 = (undefined4)uVar10;
  uStackX_14 = (undefined4)((ulonglong)uVar10 >> 0x20);
  param_1[10] = local_res10;
  param_1[0xb] = uStackX_14;
  if (iVar1 < 0) {
    dVar22 = 0.0;
  }
  else if (iVar1 < 0x28) {
    dVar22 = (double)FUN_140332d90(((double)iVar1 - 0.0) * dVar23 * dVar2 *
                                   (double)CONCAT44(uVar25,uVar24));
    dVar22 = dVar22 + 0.0;
  }
  if (iVar1 < 4) {
    uVar24 = CONCAT22(uVar31,*(undefined2 *)((longlong)param_1 + 0x42));
    FUN_140070d00(5,(&DAT_140e44660)[iVar9],0x22,local_res10,param_1[0xb],uVar24,0,SUB84(dVar22,0),
                  SUB84(dVar22,0),0x10,0xff,0xff,0xff,0x60,0);
    uVar31 = (undefined2)((uint)uVar24 >> 0x10);
  }
  if (uStack_148._4_4_ == 0xa0) {
    param_1[5] = param_1[5] + 1;
    param_1[3] = 0;
  }
LAB_14002aed9:
  uVar30 = (undefined2)((uint)fVar27 >> 0x10);
  if (param_1[5] == 1) {
    iVar1 = param_1[3];
    uVar14 = iVar1 % 0x4b0;
    dVar23 = (double)FUN_1403307c0();
    dVar21 = DAT_14053a330;
    fVar27 = (float)(dVar23 * DAT_14053a330) + (float)param_1[10];
    dVar23 = (double)FUN_140332d90();
    fVar19 = (float)(dVar23 * dVar21) + (float)param_1[0xb];
    dVar23 = (double)FUN_1403307c0();
    fVar18 = (float)(dVar23 * dVar21) + (float)param_1[10];
    dVar23 = (double)FUN_140332d90();
    fVar26 = (float)(dVar23 * dVar21) + (float)param_1[0xb];
    dVar21 = (double)FUN_140332d90(((double)iVar1 - 0.0) * DAT_14053a388 * dVar2 * DAT_140539d28);
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + (short)(int)(dVar21 * DAT_14053a3f8);
    uVar31 = (short)((uint)fVar17 >> 0x10);
    uVar10 = FUN_140133f30();
    iVar1 = DAT_140e419b8;
    iVar13 = 1;
    local_res8 = (undefined4)uVar10;
    uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    param_1[10] = local_res8;
    param_1[0xb] = uStackX_c;
    uVar24 = DAT_14053ac2c;
    dVar21 = DAT_140539fa8;
    if (iVar1 == 0) {
      iVar13 = 0x5a;
    }
    else if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) || (iVar1 == 4)) {
      iVar13 = 0x3c;
    }
    iVar15 = 1;
    if (iVar1 == 0) {
      iVar15 = 0x10;
    }
    else if (iVar1 == 1) {
      iVar15 = 0x14;
    }
    else if ((iVar1 == 2) || (iVar1 == 3)) {
      iVar15 = 0x18;
    }
    else if (iVar1 == 4) {
      iVar15 = 0x20;
    }
    uVar25 = 1;
    if (((iVar1 != 0) && (iVar1 != 1)) && ((iVar1 != 2 && ((iVar1 == 3 || (iVar1 == 4)))))) {
      uVar25 = 2;
    }
    iVar16 = 1;
    if (iVar1 == 0) {
      iVar16 = 0x28;
    }
    else if (iVar1 == 1) {
      iVar16 = 0x1e;
    }
    else if ((iVar1 == 2) || (iVar1 == 3)) {
      iVar16 = 0x14;
    }
    else if (iVar1 == 4) {
      iVar16 = 0xf;
    }
    dVar2 = DAT_14053a048;
    if ((((iVar1 != 0) && (dVar2 = DAT_14053a078, iVar1 != 1)) &&
        (dVar2 = DAT_14053a090, iVar1 != 2)) &&
       ((dVar2 = DAT_14053a0b0, iVar1 != 3 && (dVar2 = dVar4, iVar1 == 4)))) {
      dVar2 = DAT_14053a118;
    }
    if (uVar14 < 0x244) {
      if ((int)uVar14 % iVar13 < iVar15) {
        uVar11 = (int)uVar14 % iVar13 & 0x80000003;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
        }
        if (uVar11 == 0) {
          uVar28 = CONCAT22(uVar30,*(undefined2 *)((longlong)param_1 + 0x42));
          uVar29 = DAT_14053ac2c;
          FUN_1400709b0(5,uStackX_c,fVar27,fVar19,uVar28,DAT_14053ac2c,SUB84(dVar2,0),1,uVar25,4000,
                        0);
          uVar31 = (undefined2)((uint)uVar29 >> 0x10);
          uVar30 = (undefined2)((uint)uVar28 >> 0x10);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      if ((int)((longlong)(int)uVar14 % (longlong)iVar16) == 0) {
        uVar28 = CONCAT22(uVar30,*(short *)((longlong)param_1 + 0x42) + -0x8000);
        uVar29 = uVar24;
        FUN_14006c2f0(8,(longlong)(int)uVar14 % (longlong)iVar16 & 0xffffffff,fVar18,fVar26,uVar28,
                      uVar24,SUB84(dVar2 - dVar21,0),1,0);
        uVar31 = (undefined2)((uint)uVar29 >> 0x10);
        uVar30 = (undefined2)((uint)uVar28 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    uVar11 = uVar14 - 0x280;
    if (uVar11 < 500) {
      if ((int)uVar11 % iVar13 < iVar15) {
        uVar12 = (int)uVar11 % iVar13 & 0x80000003;
        if ((int)uVar12 < 0) {
          uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
        }
        if (uVar12 == 0) {
          uVar28 = CONCAT22(uVar30,*(short *)((longlong)param_1 + 0x42) + -0x8000);
          uVar29 = uVar24;
          FUN_14006c2f0(5,0,fVar18,fVar26,uVar28,uVar24,SUB84(dVar2 - dVar21,0),1,0);
          uVar31 = (undefined2)((uint)uVar29 >> 0x10);
          uVar30 = (undefined2)((uint)uVar28 >> 0x10);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      if ((int)((longlong)(int)uVar11 % (longlong)iVar16) == 0) {
        uVar29 = CONCAT22(uVar30,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(8,(longlong)(int)uVar11 % (longlong)iVar16 & 0xffffffff,fVar27,fVar19,uVar29,
                      uVar24,SUB84(dVar2,0),1,uVar25,4000,0);
        uVar31 = (undefined2)((uint)uVar24 >> 0x10);
        uVar30 = (undefined2)((uint)uVar29 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    fVar8 = DAT_14053b33c;
    fVar7 = DAT_14053af28;
    fVar6 = DAT_14053aed4;
    fVar5 = DAT_14053ac80;
    fVar17 = DAT_14053ab70;
    if (-1 < (int)uVar14) {
      uVar14 = uVar14 & 0x80000003;
      if ((int)uVar14 < 0) {
        uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
      }
      if (uVar14 == 0) {
        uVar24 = (undefined4)DAT_140539fc8;
        if (((0x7fff < *(ushort *)(param_1 + 0x10)) &&
            (DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac80 <= fVar27)) &&
           ((fVar27 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aed4 &&
            ((DAT_14053b33c <= fVar19 && (fVar19 <= DAT_14053af28)))))) {
          uVar31 = 0;
          uVar25 = CONCAT22(uVar30,*(ushort *)(param_1 + 0x10));
          FUN_14006c2f0(0xe,0,fVar27,fVar19,uVar25,0,uVar24,1,0);
          uVar30 = (undefined2)((uint)uVar25 >> 0x10);
        }
        if ((((*(ushort *)(param_1 + 0x10) < 0x8000) && (DAT_140e445d8 / fVar17 - fVar5 <= fVar18))
            && (fVar18 <= DAT_140e445d8 / fVar17 + fVar6)) &&
           ((fVar8 <= fVar26 && (fVar26 <= fVar7)))) {
          uVar31 = 0;
          FUN_14006c2f0(0xe,0,fVar18,fVar26,CONCAT22(uVar30,*(ushort *)(param_1 + 0x10)),0,uVar24,1,
                        0);
        }
      }
    }
  }
  FUN_1400c8410((&DAT_140e44660)[iVar9],0x23,7,param_1[10],param_1[0xb],
                CONCAT22(uVar31,*(undefined2 *)((longlong)param_1 + 0x42)),SUB84(dVar22,0),
                SUB84(dVar22,0),0xff,0xff,0xff,0xff,1,0);
  if ((iStack_134 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


