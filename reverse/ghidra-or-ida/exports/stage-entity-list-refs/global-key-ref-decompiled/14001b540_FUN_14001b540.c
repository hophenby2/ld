// Function: FUN_14001b540 @ 14001b540
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14001b540(undefined4 *param_1)

{
  float fVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  ushort uVar6;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  uint in_stack_fffffffffffffe48;
  undefined2 uVar29;
  undefined8 in_stack_fffffffffffffe60;
  undefined4 uVar30;
  ulonglong in_stack_fffffffffffffe68;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  int iStack_12c;
  undefined8 local_128;
  undefined8 uStack_120;
  ushort uVar7;
  
  iStack_12c = 0;
  puVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == DAT_140e44308) {
        local_148 = *puVar4;
        uStack_140 = puVar4[1];
        local_138 = *(undefined4 *)(puVar4 + 2);
        uStack_134 = *(undefined4 *)((longlong)puVar4 + 0x14);
        uStack_130 = *(undefined4 *)(puVar4 + 3);
        iStack_12c = *(int *)((longlong)puVar4 + 0x1c);
        local_128 = puVar4[4];
        uStack_120 = puVar4[5];
      }
    }
  }
  iVar12 = iStack_12c;
  fVar24 = uStack_120._4_4_ - DAT_14053accc;
  fVar1 = (float)uStack_120;
  fVar23 = (float)param_1[0xe];
  uVar27 = SUB84(DAT_14053a020,0);
  uVar28 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  param_1[0xd] = fVar24;
  param_1[0xc] = (float)uStack_120;
  if (param_1[5] == 0) {
    iVar13 = param_1[3];
    if (iVar13 == 0) {
      fVar23 = (float)param_1[10];
      param_1[0xe] = fVar23;
      *(undefined2 *)(param_1 + 0x10) = 0x4000;
    }
    dVar18 = (double)FUN_140332d90();
    fVar25 = (float)(dVar18 * (double)fVar23) + 0.0;
    if ((-1 < iVar13) && (iVar13 < 0x32)) {
      FUN_140332d90();
    }
    dVar22 = (double)fVar25;
    dVar18 = (double)FUN_1403307c0();
    dVar19 = (double)FUN_140332d90();
    param_1[10] = (float)(dVar18 * dVar22) + fVar1;
    param_1[0xb] = (float)(dVar19 * dVar22) + fVar24;
    if (iVar13 != 0x32) goto LAB_14001c564;
    param_1[8] = (undefined4)local_128;
    param_1[7] = iStack_12c;
    param_1[3] = 0;
    param_1[5] = 1;
    param_1[0x15] = 0;
  }
  else {
    fVar25 = fVar23;
    if (param_1[5] != 1) goto LAB_14001c564;
  }
  uVar5 = DAT_14053ac2c;
  dVar22 = DAT_14053aba0;
  dVar19 = DAT_14053a380;
  dVar18 = DAT_14053a2c0;
  uVar29 = (undefined2)(in_stack_fffffffffffffe48 >> 0x10);
  uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  iVar12 = DAT_140e419b8;
  if (param_1[6] == 0x42) {
    dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                   SUB84((double)(DAT_140e445d8 - fVar1),0));
    uVar2 = *(ushort *)(param_1 + 0x10);
    dVar21 = (double)FUN_1403307c0();
    fVar26 = (float)(dVar21 * dVar19) + (float)param_1[10];
    FUN_140332d90();
    dVar19 = DAT_14053a020;
    iVar13 = param_1[3];
    uVar15 = iVar13 % 0x4b0;
    dVar21 = (double)FUN_140332d90(((double)iVar13 - 0.0) * dVar18 * DAT_14053a020 * DAT_140539d28);
    iVar12 = DAT_140e419b8;
    iVar9 = 1;
    *(short *)((longlong)param_1 + 0x42) =
         *(short *)((longlong)param_1 + 0x42) - (short)(int)(dVar21 * _DAT_14053b250);
    if (iVar12 == 0) {
      iVar9 = -0x78;
    }
    else if (iVar12 == 1) {
      iVar9 = -0x50;
    }
    else if ((iVar12 == 2) || (iVar12 == 3)) {
      iVar9 = -0x3c;
    }
    else if (iVar12 == 4) {
      iVar9 = -0x28;
    }
    fVar25 = fVar23;
    if (iVar13 % 0x4b0 < 0x4b1) {
      dVar18 = (double)FUN_140332d90(((double)(iVar13 % 0x4b0) - 0.0) * dVar18 * dVar19 *
                                     DAT_140539d28);
      fVar25 = (float)(dVar18 * (double)iVar9) + fVar23;
    }
    dVar18 = (double)FUN_1403307c0();
    dVar19 = (double)FUN_140332d90();
    uVar7 = (ushort)(int)(dVar20 * dVar22);
    uVar6 = uVar7 - uVar2;
    param_1[10] = (float)(dVar18 * (double)fVar25) + fVar1;
    uVar10 = (uint)uVar6;
    if (0x8000 < uVar6) {
      uVar10 = 0x10000 - uVar6;
    }
    iVar9 = ((int)(dVar20 * dVar22) & 0xffffU) - (uint)uVar2;
    param_1[0xb] = (float)(dVar19 * (double)fVar25) + fVar24;
    iVar11 = (int)uVar10 / 10 + 0x30;
    iVar13 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar13 = iVar9;
    }
    iVar9 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar9 = iVar13;
    }
    if (iVar9 < 1) {
      uVar6 = uVar2;
      if ((iVar9 < 0) && (uVar6 = uVar2 - (short)iVar11, -iVar11 < iVar9)) {
        uVar6 = uVar7;
      }
    }
    else {
      uVar6 = uVar7;
      if (iVar11 <= iVar9) {
        uVar6 = uVar2 + (short)iVar11;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar6;
    iVar13 = 1;
    if (iVar12 == 0) {
      iVar13 = 0x5a;
    }
    else if (iVar12 == 1) {
LAB_14001ba80:
      iVar13 = 0x2c;
    }
    else if (iVar12 == 2) {
      iVar13 = 0x21;
    }
    else if (iVar12 == 3) {
      iVar13 = 0x32;
    }
    else if (iVar12 == 4) goto LAB_14001ba80;
    iVar9 = 1;
    if (iVar12 == 0) {
      iVar9 = 0x12;
    }
    else if (iVar12 == 1) {
      iVar9 = 0x15;
    }
    else if (((iVar12 == 2) || (iVar12 == 3)) || (iVar12 == 4)) {
      iVar9 = 0x18;
    }
    dVar18 = DAT_14053a070;
    if (((iVar12 != 0) && (dVar18 = DAT_14053a0b0, iVar12 != 1)) &&
       ((dVar18 = DAT_14053a0f8, iVar12 != 2 &&
        ((dVar18 = DAT_14053a118, iVar12 != 3 && (dVar18 = DAT_140539f40, iVar12 == 4)))))) {
      dVar18 = DAT_14053a158;
    }
    iVar11 = (int)uVar15 % iVar13;
    dVar19 = (double)iVar11 * DAT_140539e60;
    if (uVar15 < 0x118) {
      if (iVar11 == 0) {
        *(ushort *)(param_1 + 0x11) = uVar6;
      }
      else if (0x117 < uVar15) goto LAB_14001bc83;
      iVar17 = 0;
      if ((iVar11 < iVar9) &&
         (iVar11 == (iVar11 / 3 + (iVar11 >> 0x1f) +
                    (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3)) {
        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
        in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
        in_stack_fffffffffffffe48 =
             CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),*(undefined2 *)(param_1 + 0x11));
        FUN_14006c2f0(0xd,0,fVar26,iVar13,in_stack_fffffffffffffe48,uVar5,dVar19 + dVar18,
                      in_stack_fffffffffffffe60,in_stack_fffffffffffffe68);
        if (2 < DAT_140e419b8) {
          do {
            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
            in_stack_fffffffffffffe60 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            in_stack_fffffffffffffe48 = in_stack_fffffffffffffe48 & 0xffff0000;
            FUN_14006c2f0(0xd,0,fVar26);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar12 = DAT_140e419b8;
      }
    }
LAB_14001bc83:
    iVar13 = 0;
    puVar16 = (uint *)&local_158;
    lVar14 = 4;
    local_158 = _DAT_14053b930;
    uStack_150 = _UNK_14053b938;
    do {
      uVar10 = *puVar16;
      if (uVar15 == uVar10) {
        *(undefined2 *)(param_1 + 0x11) = *(undefined2 *)(param_1 + 0x10);
LAB_14001bd77:
        if (((int)uVar15 < (int)(uVar10 + 0x3c)) || (uVar10 == 0xffffffc4)) {
          uVar10 = uVar15 - uVar10 & 0x80000003;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
          }
          if (uVar10 == 0) {
            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
            in_stack_fffffffffffffe60 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            in_stack_fffffffffffffe48 = in_stack_fffffffffffffe48 & 0xffff0000;
            FUN_14006c2f0(2,0,fVar26);
            iVar12 = iVar13;
            if (2 < DAT_140e419b8) {
              do {
                in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
                in_stack_fffffffffffffe60 =
                     CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
                in_stack_fffffffffffffe48 = in_stack_fffffffffffffe48 & 0xffff0000;
                FUN_14006c2f0(2,0,fVar26);
                iVar12 = iVar12 + 1;
              } while (iVar12 < 2);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar12 = DAT_140e419b8;
          }
        }
      }
      else if ((int)uVar10 <= (int)uVar15) goto LAB_14001bd77;
      uVar29 = (undefined2)(in_stack_fffffffffffffe48 >> 0x10);
      uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
      puVar16 = puVar16 + 1;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    iVar9 = 1;
    if (iVar12 == 0) {
      iVar9 = 0x30;
    }
    else if (iVar12 == 1) {
      iVar9 = 0x1e;
    }
    else if (iVar12 == 2) {
      iVar9 = 0x12;
    }
    else if (iVar12 == 3) {
      iVar9 = 0xe;
    }
    else if (iVar12 == 4) {
      iVar9 = 0xc;
    }
    if ((uVar15 - 0x370 < 0x10e) &&
       (uVar3 = (longlong)(int)(uVar15 - 0x370) % (longlong)iVar9, (int)uVar3 == 0)) {
      in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
      uVar15 = in_stack_fffffffffffffe48 & 0xffff0000;
      FUN_14006c2f0(0xd,uVar3 & 0xffffffff,fVar26);
      uVar29 = (undefined2)(uVar15 >> 0x10);
      if (0 < DAT_140e419b8) {
        do {
          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
          uVar15 = uVar15 & 0xffff0000;
          FUN_14006c2f0(0xd,0,fVar26);
          uVar29 = (undefined2)(uVar15 >> 0x10);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar27 = SUB84(DAT_14053a020,0);
      uVar28 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
      iVar12 = DAT_140e419b8;
    }
    else {
      uVar27 = SUB84(DAT_14053a020,0);
      uVar28 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    }
  }
  dVar18 = DAT_14053aba0;
  if (param_1[6] == 0x43) {
    iVar13 = param_1[1] - DAT_1407c77a0;
    dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                   SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
    dVar19 = DAT_140539d28;
    uVar2 = *(ushort *)(param_1 + 0x10);
    uVar10 = (uint)(dVar22 * dVar18);
    dVar18 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar18 * DAT_14053a380) + (float)param_1[10];
    FUN_140332d90();
    uVar15 = param_1[3];
    sVar8 = ((ushort)((int)uVar15 >> 0x1f) & 0xff10) + 0xf0;
    if (uVar15 < 600) {
      dVar18 = (double)FUN_140332d90(((double)(int)uVar15 - _DAT_140539cc0) * DAT_14053a2c0 *
                                     (double)CONCAT44(uVar28,uVar27) * dVar19);
      sVar8 = (short)(int)(dVar18 * DAT_14053a5e8);
    }
    else if (((int)uVar15 < 0x4b0) || (0x707 < (int)uVar15)) {
      if (0x707 < (int)uVar15) {
        sVar8 = 0;
      }
    }
    else {
      dVar18 = (double)FUN_140332d90(((double)(int)uVar15 - DAT_14053a7c8) * DAT_14053a2c0 *
                                     (double)CONCAT44(uVar28,uVar27) * dVar19);
      sVar8 = (short)(int)(dVar18 * DAT_14053a5e8);
    }
    *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar8;
    dVar18 = (double)FUN_1403307c0();
    fVar1 = (float)param_1[0xc];
    dVar19 = (double)FUN_140332d90();
    uVar7 = (ushort)uVar10;
    uVar6 = uVar7 - uVar2;
    param_1[10] = (float)(dVar18 * (double)fVar25) + fVar1;
    uVar15 = (uint)uVar6;
    if (0x8000 < uVar6) {
      uVar15 = 0x10000 - uVar6;
    }
    iVar11 = (uVar10 & 0xffff) - (uint)uVar2;
    param_1[0xb] = (float)(dVar19 * (double)fVar25) + (float)param_1[0xd];
    iVar17 = (int)uVar15 / 10 + 0x30;
    iVar9 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar9 = iVar11;
    }
    iVar11 = iVar9 + -0x10000;
    if (iVar9 < 0x8001) {
      iVar11 = iVar9;
    }
    if (iVar11 < 1) {
      uVar6 = uVar2;
      if ((iVar11 < 0) && (uVar6 = uVar2 - (short)iVar17, -iVar17 < iVar11)) {
        uVar6 = uVar7;
      }
    }
    else {
      uVar6 = uVar7;
      if (iVar17 <= iVar11) {
        uVar6 = uVar2 + (short)iVar17;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar6;
    iVar9 = 1;
    if (iVar12 == 0) {
      iVar9 = 0x4b;
    }
    else if (iVar12 == 1) {
      iVar9 = 0x28;
    }
    else if (iVar12 == 2) {
      iVar9 = 0x24;
    }
    else if (iVar12 == 3) {
      iVar9 = 0x20;
    }
    else if (iVar12 == 4) {
      iVar9 = 0x1a;
    }
    iVar13 = iVar9 * iVar13 + 0x14;
    dVar18 = DAT_14053a0d0;
    if ((((iVar12 != 0) && (dVar18 = DAT_14053a118, iVar12 != 1)) &&
        (dVar18 = DAT_14053a138, iVar12 != 2)) &&
       ((dVar18 = DAT_14053a158, iVar12 != 3 && (dVar18 = DAT_140539f40, iVar12 == 4)))) {
      dVar18 = DAT_14053a1c8;
    }
    iVar12 = param_1[3];
    iVar11 = iVar12 - iVar13;
    dVar19 = (double)(iVar11 % iVar9) * DAT_140539e40;
    if ((iVar12 < iVar13) || (iVar11 % (iVar9 * 3) != 0)) {
      uVar6 = *(ushort *)(param_1 + 0x11);
      if ((iVar13 <= iVar12) && (iVar11 = iVar11 % (iVar9 * 3), iVar11 < 0x18)) goto LAB_14001c38a;
    }
    else {
      *(ushort *)(param_1 + 0x11) = uVar6;
      iVar11 = iVar11 % (iVar9 * 3);
LAB_14001c38a:
      if (iVar11 == (iVar11 / 3 + (iVar11 >> 0x1f) +
                    (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3) {
        iVar12 = 0;
        FUN_14006c2f0(0xd,0,fVar23,iVar13,CONCAT22(uVar29,uVar6),uVar5,dVar19 + dVar18,
                      CONCAT44(uVar30,1),in_stack_fffffffffffffe68 & 0xffffffff00000000);
        if (2 < DAT_140e419b8) {
          do {
            FUN_14006c2f0(0xd,0,fVar23);
            iVar12 = iVar12 + 1;
          } while (iVar12 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    uVar2 = *(ushort *)(param_1 + 0x11);
    iVar13 = (uVar10 & 0xffff) - (uint)uVar2;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar6 = uVar2;
      if ((iVar13 < 0) && (uVar6 = uVar2 - 0x30, -0x30 < iVar13)) {
        uVar6 = uVar7;
      }
    }
    else {
      uVar6 = uVar7;
      if (0x2f < iVar13) {
        uVar6 = uVar2 + 0x30;
      }
    }
    *(ushort *)(param_1 + 0x11) = uVar6;
  }
  iVar13 = DAT_140e44308;
  iVar12 = param_1[7];
  if ((iVar12 < iStack_12c) && (puVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == iVar13) {
        *(int *)((longlong)puVar4 + 0x1c) =
             *(int *)((longlong)puVar4 + 0x1c) - (iStack_12c - iVar12);
      }
    }
  }
  iVar13 = param_1[7];
  if (iStack_12c < iVar13) {
    param_1[7] = iStack_12c;
    iVar13 = iStack_12c;
  }
  iVar9 = DAT_140e44308;
  iVar12 = iStack_12c;
  if ((iVar13 < 1) && (puVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == iVar9) {
        *(int *)((longlong)puVar4 + 0x1c) = *(int *)((longlong)puVar4 + 0x1c) - iStack_12c;
      }
    }
  }
LAB_14001c564:
  FUN_140332d90(((double)uStack_140._4_4_ - 0.0) * _DAT_14053a8e8 * (double)CONCAT44(uVar28,uVar27)
                * DAT_140539d28);
  FUN_140332d90();
  FUN_1403307c0();
  FUN_140332d90();
  FUN_1400c8410(DAT_140e44c04,0x23,7);
  FUN_1400c8410(DAT_140e44c00,0x23,7);
  if ((param_1[5] == 0) && ((*(byte *)(param_1 + 3) & 1) == 0)) {
    FUN_140070d00(5,DAT_140e44c04,0x24);
    FUN_140070d00(5,DAT_140e44c00,0x24);
  }
  if ((iVar12 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


