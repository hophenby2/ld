// Function: FUN_14001ac40 @ 14001ac40
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14001ac40(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ushort uVar5;
  int iVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  double dVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_res8;
  undefined4 uStackX_c;
  float in_stack_fffffffffffffe70;
  uint uVar21;
  ulonglong in_stack_fffffffffffffe88;
  undefined4 uVar22;
  undefined8 uStack_130;
  undefined8 uStack_120;
  undefined8 uStack_110;
  
  dVar17 = DAT_14053a020;
  dVar14 = DAT_140539f40;
  dVar15 = DAT_140539d28;
  uStack_120 = 0;
  uStack_120._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar10 = DAT_140e45d80, uStack_120._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar10 + 4) == DAT_140e44308) {
        uStack_130 = *(undefined8 *)(lVar10 + 8);
        uStack_120 = *(undefined8 *)(lVar10 + 0x18);
        uStack_110 = *(undefined8 *)(lVar10 + 0x28);
      }
      lVar10 = *(longlong *)(lVar10 + 0x60);
    } while (lVar10 != 0);
  }
  iVar9 = param_1[5];
  fVar16 = (float)param_1[0xf];
  uVar19 = SUB84(DAT_140539d28,0);
  uVar20 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  param_1[0xc] = (undefined4)uStack_110;
  param_1[0xd] = uStack_110._4_4_;
  dVar13 = DAT_14053a670;
  dVar11 = dVar14;
  if (iVar9 == 0) {
    iVar6 = param_1[3];
    if (iVar6 == 0) {
      param_1[0xe] = param_1[10];
LAB_14001ad9b:
      FUN_140332d90(((double)iVar6 - 0.0) * dVar13 * dVar17 * dVar15);
LAB_14001ae04:
      dVar11 = (double)FUN_140332d90(((double)iVar6 - 0.0) * dVar13 * dVar17 * dVar15);
      fVar16 = (float)(int)(dVar11 * (double)(int)fVar16);
LAB_14001ae60:
      dVar11 = (double)FUN_140332d90(((double)iVar6 - 0.0) * dVar13 * dVar17 * dVar15);
      dVar11 = dVar11 + 0.0;
    }
    else {
      if ((-1 < iVar6) && (iVar6 < 0x32)) goto LAB_14001ad9b;
      iVar8 = 0;
      if ((-1 < iVar6) && (iVar8 = (int)fVar16, iVar6 < 0x32)) goto LAB_14001ae04;
      fVar16 = (float)iVar8;
      if (-1 < iVar6) {
        if (0x31 < iVar6) goto LAB_14001ae89;
        goto LAB_14001ae60;
      }
      dVar11 = 0.0;
    }
LAB_14001ae89:
    in_stack_fffffffffffffe70 = fVar16;
    uVar4 = FUN_140133f30();
    local_res8 = (undefined4)uVar4;
    uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
    param_1[10] = local_res8;
    param_1[0xb] = uStackX_c;
    if (iVar6 != 0x32) goto LAB_14001aee2;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else {
LAB_14001aee2:
    uVar22 = (undefined4)(in_stack_fffffffffffffe88 >> 0x20);
    if (iVar9 != 1) goto LAB_14001b223;
  }
  iVar9 = DAT_140e419b8;
  dVar13 = DAT_14053a2c0;
  uVar7 = 1;
  uVar19 = param_1[10];
  fVar18 = (float)param_1[0xb] + DAT_14053ac44;
  if (DAT_140e419b8 == 0) {
    uVar7 = 0x14d;
  }
  else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
          (DAT_140e419b8 == 4)) {
    uVar7 = 0x22b;
  }
  iVar6 = param_1[3];
  uVar5 = 0;
  if ((-1 < iVar6) && (uVar5 = uVar7, iVar6 < 600)) {
    dVar12 = (double)FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a2c0 * dVar17 * dVar15);
    uVar5 = (ushort)(int)(dVar12 * (double)uVar7);
  }
  if (iVar6 - 0x4b0U < 600) {
    dVar13 = (double)FUN_140332d90(((double)iVar6 - DAT_14053a7c8) * dVar13 * dVar17 * dVar15);
    uVar5 = (ushort)(int)(dVar13 * (double)uVar7);
  }
  uVar7 = 0;
  if (iVar6 < 0x708) {
    uVar7 = uVar5;
  }
  *(ushort *)((longlong)param_1 + 0x42) = uVar7 + *(short *)((longlong)param_1 + 0x42);
  FUN_140332d90(((double)iVar6 - _DAT_14053b178) * DAT_14053a5a0 * dVar17 * dVar15);
  FUN_140332d90();
  uVar4 = FUN_140133f30();
  uVar22 = (undefined4)(in_stack_fffffffffffffe88 >> 0x20);
  local_res8 = (undefined4)uVar4;
  uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
  param_1[10] = local_res8;
  param_1[0xb] = uStackX_c;
  dVar15 = DAT_140539fe8;
  if (param_1[6] == 0x41) {
    iVar6 = 10;
    iVar8 = 1;
    if (iVar9 == 0) {
      iVar8 = 8;
    }
    else if (iVar9 == 1) {
      iVar8 = 5;
    }
    else if (iVar9 == 2) {
LAB_14001b0c2:
      iVar8 = 3;
    }
    else if (iVar9 == 3) {
      iVar8 = 4;
    }
    else if (iVar9 == 4) goto LAB_14001b0c2;
    dVar13 = DAT_14053a0a0;
    if (((iVar9 != 0) && (dVar13 = DAT_14053a0f8, iVar9 != 1)) &&
       ((dVar13 = DAT_14053a138, iVar9 != 2 && ((iVar9 != 3 && (dVar13 = dVar14, iVar9 == 4)))))) {
      dVar13 = DAT_14053a1b8;
    }
    iVar9 = 0;
    lVar10 = 0x19;
    do {
      iVar2 = param_1[3];
      iVar1 = iVar9 + iVar6;
      if ((iVar6 <= iVar2) &&
         (((iVar2 < iVar1 + 1 || (iVar1 == -1)) &&
          (uVar3 = (longlong)(iVar2 - iVar6) % (longlong)iVar8, (int)uVar3 == 0)))) {
        in_stack_fffffffffffffe88 = in_stack_fffffffffffffe88 & 0xffffffff00000000;
        fVar16 = 0.0;
        FUN_14006c2f0(3,uVar3 & 0xffffffff,uVar19,fVar18,*(undefined2 *)((longlong)param_1 + 0x42),0
                      ,dVar13,1,in_stack_fffffffffffffe88);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffe88 = in_stack_fffffffffffffe88 & 0xffffffff00000000;
          fVar16 = 0.0;
          FUN_14006c2f0(9,0,uVar19,fVar18,*(undefined2 *)((longlong)param_1 + 0x42),0,
                        dVar13 - dVar15,1,in_stack_fffffffffffffe88);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      uVar22 = (undefined4)(in_stack_fffffffffffffe88 >> 0x20);
      iVar9 = iVar9 + iVar8;
      iVar6 = iVar1 + 0x18;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
  uVar19 = SUB84(DAT_140539d28,0);
  uVar20 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  in_stack_fffffffffffffe70 = fVar16;
LAB_14001b223:
  uVar7 = *(ushort *)((longlong)param_1 + 0x42);
  dVar14 = (double)FUN_140332d90(((double)uVar7 - 0.0) * dVar17 * (double)CONCAT44(uVar20,uVar19));
  dVar15 = DAT_140539e60;
  dVar11 = dVar11 * (dVar14 * DAT_140539e60 + DAT_140539f38);
  dVar14 = (double)FUN_140332d90(((double)uStack_130._4_4_ - 0.0) * _DAT_14053a9b8 * dVar17 *
                                 (double)CONCAT44(uVar20,uVar19));
  dVar17 = (dVar14 * dVar15 + 0.0) * dVar11 + dVar11;
  dVar14 = (double)FUN_140332d90();
  iVar9 = 0x1c;
  if (uVar7 < 0x8001) {
    iVar9 = 0x1f;
  }
  dVar15 = (dVar14 * dVar15 + 0.0) * dVar11 + dVar11;
  uVar21 = (uint)in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e44710,iVar9,7,param_1[10],param_1[0xb],uVar21,dVar15,dVar11,
                CONCAT44(uVar22,0xff),0xff,0xff,0xff,1,0);
  uVar21 = uVar21 & 0xffff0000;
  FUN_1400c8410(DAT_140e44714,iVar9,7,param_1[10],param_1[0xb],uVar21,dVar17,dVar11,0xff,0xff,0xff,
                0xff,1,0);
  if ((param_1[5] == 0) && ((*(byte *)(param_1 + 3) & 1) == 0)) {
    uVar21 = uVar21 & 0xffff0000;
    FUN_140070d00(5,DAT_140e44710,iVar9 + 1,param_1[10],param_1[0xb],uVar21,0,dVar15,dVar11,0x10,
                  0xff,0xff,0xff,0x60,0);
    FUN_140070d00(5,DAT_140e44714,iVar9 + 1,param_1[10],param_1[0xb],uVar21 & 0xffff0000,0,dVar17,
                  dVar11,0x10,0xff,0xff,0xff,0x60,0);
  }
  if ((uStack_120._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  return;
}


