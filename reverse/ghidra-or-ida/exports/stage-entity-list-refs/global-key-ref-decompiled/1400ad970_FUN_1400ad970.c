// Function: FUN_1400ad970 @ 1400ad970
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ad970(undefined4 *param_1)

{
  float fVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  short sVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  undefined2 uVar15;
  short sVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  double dVar28;
  double dVar29;
  float fVar30;
  double dVar31;
  float fVar32;
  float fVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  uint local_res8;
  short local_res10;
  undefined4 in_stack_fffffffffffffe48;
  undefined2 uVar38;
  undefined4 in_stack_fffffffffffffe50;
  undefined8 in_stack_fffffffffffffe60;
  undefined8 uVar39;
  uint local_160;
  undefined8 local_150;
  undefined8 uStack_148;
  int local_140;
  int iStack_13c;
  int iStack_134;
  undefined8 local_130;
  undefined8 uStack_128;
  
  dVar29 = DAT_14053a710;
  dVar31 = DAT_14053a020;
  dVar21 = DAT_140539d28;
  local_150 = 0;
  local_150._0_4_ = 0;
  iStack_134 = 0;
  puVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
      if (*(int *)((longlong)puVar3 + 4) == param_1[2]) {
        local_150 = *puVar3;
        uStack_148 = puVar3[1];
        local_140 = *(int *)(puVar3 + 2);
        iStack_13c = *(int *)((longlong)puVar3 + 0x14);
        iStack_134 = *(int *)((longlong)puVar3 + 0x1c);
        local_130 = puVar3[4];
        uStack_128 = puVar3[5];
      }
    }
  }
  iVar13 = param_1[3];
  uVar34 = SUB84(DAT_14053a020,0);
  uVar35 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  fVar1 = (float)param_1[0xe];
  uStack_128._0_4_ = (float)uStack_128 + fVar1;
  uStack_128._4_4_ = uStack_128._4_4_ + (float)param_1[0xf];
  uVar36 = SUB84(DAT_140539d28,0);
  uVar37 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar20 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a710 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar22 = DAT_14053a950;
  uVar8 = *(ushort *)(param_1 + 0x11);
  dVar20 = dVar20 * DAT_14053a950;
  local_res8 = (uint)uVar8 + (int)dVar20;
  dVar21 = (double)FUN_140332d90(((double)iVar13 - _DAT_14053a350) * dVar29 * dVar31 * dVar21);
  iVar13 = (int)(dVar21 * dVar22);
  local_res10 = (short)(iVar13 + local_res8) + 7000;
  fVar27 = DAT_14053ad70;
  if (param_1[6] == 0xa6) {
    dVar21 = (double)FUN_140332d90();
    local_res8 = (uint)(ushort)((short)(int)(dVar21 * dVar22) + uVar8);
    fVar27 = DAT_14053ad10;
  }
  sVar12 = (short)iVar13;
  if (fVar1 < 0.0) {
    uVar8 = uVar8 - (short)(int)dVar20;
    local_res10 = (uVar8 - sVar12) + -7000;
    local_res8 = (uint)uVar8;
  }
  local_160 = (uint)(fVar1 < 0.0);
  if (iStack_13c == 3) {
    sVar6 = (short)uStack_148._4_4_;
    if (fVar1 < 0.0) {
      uVar8 = (short)local_res8 + sVar6 * -100;
      local_res10 = ((uVar8 + sVar6 * -0x3c) - sVar12) + -7000;
    }
    else {
      uVar8 = (short)local_res8 + sVar6 * 100;
      local_res10 = (short)((uStack_148._4_4_ & 0xffff) * 0x3c) + sVar12 + uVar8 + 7000;
    }
    local_res8 = (uint)uVar8;
    if ((int)local_150 == 0) {
      FUN_140079e20(param_1,1);
    }
  }
  dVar21 = (double)FUN_1403307c0();
  fVar32 = (float)(dVar21 * (double)fVar27) + (float)uStack_128;
  dVar21 = (double)FUN_140332d90();
  param_1[10] = fVar32;
  fVar27 = (float)(dVar21 * (double)fVar27) + uStack_128._4_4_;
  param_1[0xb] = fVar27;
  if (param_1[0x15] != 0) goto LAB_1400ae8cb;
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar27),
                                 SUB84((double)(DAT_140e445d8 - fVar32),0));
  iVar13 = DAT_140e419b8;
  uVar34 = DAT_14053ac2c;
  dVar29 = DAT_14053a178;
  dVar31 = DAT_14053a138;
  dVar21 = DAT_140539f40;
  uVar38 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
  uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  iVar17 = 2000;
  if (DAT_1407c7798 == 9) {
    iVar17 = 0x4b0;
  }
  uVar15 = (undefined2)(int)(dVar22 * DAT_14053aba0);
  if ((iStack_13c == 1) && (local_140 < iVar17)) {
    if (param_1[6] == 0xa5) {
      iVar18 = 1;
      if (DAT_140e419b8 == 0) {
        iVar18 = 0x5a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar18 = 0x50;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar18 = 0x46;
      }
      iVar14 = 1;
      uVar9 = (param_1[3] - iVar18) % 0xf0;
      if (DAT_140e419b8 == 0) {
        iVar14 = 0x3c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar14 = 0x28;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar14 = 0x1e;
      }
      iVar10 = 1;
      if (((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) ||
         ((DAT_140e419b8 == 2 || ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))))) {
        iVar10 = 5;
      }
      dVar22 = DAT_14053a0c8;
      if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a110, DAT_140e419b8 != 1)) &&
          (dVar22 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar22 = DAT_140539f40, DAT_140e419b8 == 4)))) {
        dVar22 = DAT_14053a178;
      }
      dVar22 = (double)((int)uVar9 % iVar14) * DAT_140539e60 + dVar22;
      if (uVar9 == 0) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar15;
      }
      dVar20 = DAT_140539f90;
      if (iVar18 <= (int)param_1[3]) {
        if ((uVar9 < 0x78) && (uVar7 = (int)uVar9 % (iVar14 * 2), (int)uVar7 < 0x1e)) {
          uVar7 = uVar7 & 0x80000003;
          if ((int)uVar7 < 0) {
            uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
          }
          if (uVar7 == 0) {
            in_stack_fffffffffffffe60 = CONCAT44(uVar35,1);
            in_stack_fffffffffffffe48 = CONCAT22(uVar38,*(undefined2 *)((longlong)param_1 + 0x42));
            in_stack_fffffffffffffe50 = uVar34;
            FUN_1400709b0(7,0,fVar32,param_1[0xb],in_stack_fffffffffffffe48,uVar34,dVar22,
                          in_stack_fffffffffffffe60,iVar10,20000,0);
            iVar13 = DAT_140e419b8;
            if (2 < DAT_140e419b8) {
              in_stack_fffffffffffffe60 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
              in_stack_fffffffffffffe48 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                            *(undefined2 *)((longlong)param_1 + 0x42));
              in_stack_fffffffffffffe50 = uVar34;
              FUN_1400709b0(7,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar34,
                            dVar22 + dVar20,in_stack_fffffffffffffe60,iVar10,20000,0);
              iVar13 = DAT_140e419b8;
            }
          }
        }
        if (((iVar14 <= (int)uVar9) && ((int)uVar9 < 0x78)) &&
           (uVar9 = (int)(uVar9 - iVar14) % (iVar14 * 2), (int)uVar9 < 0x1e)) {
          uVar9 = uVar9 & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          if (uVar9 == 0) {
            uVar9 = iVar10 - 1;
            uVar7 = (int)(20000 / (ulonglong)uVar9) * (iVar10 + -2) & 0xffff;
            in_stack_fffffffffffffe60 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                          *(undefined2 *)((longlong)param_1 + 0x42));
            in_stack_fffffffffffffe50 = uVar34;
            FUN_1400709b0(7,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar34,dVar22,
                          in_stack_fffffffffffffe60,uVar9,uVar7,0);
            iVar13 = DAT_140e419b8;
            if (2 < DAT_140e419b8) {
              in_stack_fffffffffffffe60 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
              in_stack_fffffffffffffe48 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                            *(undefined2 *)((longlong)param_1 + 0x42));
              in_stack_fffffffffffffe50 = uVar34;
              FUN_1400709b0(7,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar34,
                            dVar22 + dVar20,in_stack_fffffffffffffe60,uVar9,uVar7,0);
              iVar13 = DAT_140e419b8;
            }
          }
        }
      }
    }
    uVar38 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
    uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
    if (param_1[6] == 0xa6) {
      iVar18 = 1;
      if (iVar13 == 0) {
        iVar18 = 0x12;
      }
      else if (iVar13 == 1) {
        iVar18 = 0xd;
      }
      else if (((iVar13 == 2) || (iVar13 == 3)) || (iVar13 == 4)) {
        iVar18 = 0xb;
      }
      iVar14 = 1;
      if (iVar13 == 0) {
        iVar14 = 2;
      }
      else if (iVar13 == 1) {
LAB_1400ae082:
        iVar14 = 4;
      }
      else if (iVar13 == 2) {
        iVar14 = 5;
      }
      else if (iVar13 == 3) {
        iVar14 = 3;
      }
      else if (iVar13 == 4) goto LAB_1400ae082;
      uVar36 = 1;
      if (((iVar13 != 0) && (iVar13 != 1)) && ((iVar13 != 2 && ((iVar13 == 3 || (iVar13 == 4)))))) {
        uVar36 = 2;
      }
      dVar22 = DAT_14053a070;
      if ((((iVar13 != 0) && (iVar13 != 1)) && (iVar13 != 2)) &&
         ((dVar22 = DAT_14053a0b0, iVar13 != 3 && (dVar22 = dVar21, iVar13 == 4)))) {
        dVar22 = DAT_14053a0f8;
      }
      iVar10 = 0;
      if (0.0 <= fVar1) {
        do {
          sVar12 = *(short *)(param_1 + 3);
          iVar13 = param_1[3];
          if (((0x77 < iVar13) && (iVar13 < iVar17)) &&
             (uVar2 = (longlong)(iVar13 + -0x78) % (longlong)iVar18, (int)uVar2 == 0)) {
            uVar39 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            uVar35 = CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                              sVar12 * 0x89 + (short)iVar10 * 800 + -0x4038);
            FUN_1400709b0(0xc,uVar2 & 0xffffffff,param_1[10],param_1[0xb],uVar35,uVar34,
                          (double)iVar10 + dVar22,uVar39,uVar36,9000,0);
            in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),1);
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)((uint)uVar35 >> 0x10),
                          sVar12 * -0x89 + 0x4038 + (short)iVar10 * -800);
            in_stack_fffffffffffffe50 = uVar34;
            FUN_1400709b0(0xc,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar34,
                          (double)iVar10 + dVar22,in_stack_fffffffffffffe60,uVar36,9000,0);
          }
          uVar38 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
          uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
          iVar10 = iVar10 + 1;
          iVar13 = DAT_140e419b8;
        } while (iVar10 < iVar14);
      }
      else {
        do {
          sVar12 = *(short *)(param_1 + 3);
          iVar13 = param_1[3];
          if (((0x77 < iVar13) && (iVar13 < iVar17)) &&
             (uVar2 = (longlong)(iVar13 + -0x78) % (longlong)iVar18, (int)uVar2 == 0)) {
            uVar39 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            uVar35 = CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                              sVar12 * -0x89 + -0x3fc8 + (short)iVar10 * -800);
            FUN_1400709b0(0xc,uVar2 & 0xffffffff,param_1[10],param_1[0xb],uVar35,uVar34,
                          (double)iVar10 + dVar22,uVar39,uVar36,9000,0);
            in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),1);
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)((uint)uVar35 >> 0x10),sVar12 * 0x89 + (short)iVar10 * 800 + 0x3fc8
                         );
            in_stack_fffffffffffffe50 = uVar34;
            FUN_1400709b0(0xc,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar34,
                          (double)iVar10 + dVar22,in_stack_fffffffffffffe60,uVar36,9000,0);
          }
          uVar38 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
          uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
          iVar10 = iVar10 + 1;
          iVar13 = DAT_140e419b8;
        } while (iVar10 < iVar14);
      }
    }
  }
  if (iStack_13c == 2) {
    iVar17 = 1;
    if (iVar13 == 0) {
      iVar17 = 0xb4;
    }
    else if (iVar13 == 1) {
      iVar17 = 0x8c;
    }
    else if (iVar13 == 2) {
      iVar17 = 0x82;
    }
    else if ((iVar13 == 3) || (iVar13 == 4)) {
      iVar17 = 0x78;
    }
    iVar14 = 1;
    iVar18 = (int)(uStack_148._4_4_ - 0x3c) % iVar17;
    if (iVar13 == 0) {
      iVar14 = 0x10;
    }
    else if (iVar13 == 1) {
      iVar14 = 0xc;
    }
    else if (iVar13 == 2) {
      iVar14 = 10;
    }
    else if (iVar13 == 3) {
      iVar14 = 9;
    }
    else if (iVar13 == 4) {
      iVar14 = 8;
    }
    lVar11 = 1;
    if (iVar13 == 0) {
      lVar11 = 0x640;
    }
    else if (iVar13 == 1) {
      lVar11 = 0x960;
    }
    else if (iVar13 == 2) {
      lVar11 = 0xa8c;
    }
    else if ((iVar13 == 3) || (iVar13 == 4)) {
      lVar11 = 3000;
    }
    if ((((iVar13 != 0) && (dVar31 = dVar29, iVar13 != 1)) && (dVar31 = DAT_14053a1b8, iVar13 != 2))
       && ((dVar31 = DAT_14053a1e8, iVar13 != 3 && (dVar31 = dVar21, iVar13 == 4)))) {
      dVar31 = DAT_14053a208;
    }
    dVar31 = dVar31 - (double)iVar18 * DAT_140539de8;
    if ((0x3b < (int)uStack_148._4_4_) && (iVar18 == 0)) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar15;
    }
    if (0x3b < (int)uStack_148._4_4_) {
      if (((int)(uStack_148._4_4_ - 0x3c) % iVar17 < 0x40) &&
         (iVar13 = (int)(uStack_148._4_4_ - 0x3c) % iVar17,
         iVar13 == (iVar13 / 3 + (iVar13 >> 0x1f) +
                   (int)(((longlong)iVar13 / 3 + ((longlong)iVar13 >> 0x3f) & 0xffffffffU) >> 0x1f))
                   * 3)) {
        iVar13 = (int)((ulonglong)(lVar11 * 0xd41d41d5) >> 0x20);
        iVar13 = (((uint)((int)lVar11 - iVar13) >> 1) + iVar13 >> 6) * iVar18;
        uVar39 = CONCAT44(uVar35,1);
        uVar35 = CONCAT22(uVar38,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(9,0,param_1[10],param_1[0xb],uVar35,uVar34,dVar31,uVar39,2,iVar13,0);
        uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),1);
        uVar35 = CONCAT22((short)((uint)uVar35 >> 0x10),*(short *)((longlong)param_1 + 0x42) + 10000
                         );
        FUN_1400709b0(9,0,param_1[10],param_1[0xb],uVar35,uVar34,dVar31,uVar39,2,iVar13,0);
        uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),1);
        uVar35 = CONCAT22((short)((uint)uVar35 >> 0x10),
                          *(short *)((longlong)param_1 + 0x42) + -10000);
        in_stack_fffffffffffffe50 = uVar34;
        FUN_1400709b0(9,0,param_1[10],param_1[0xb],uVar35,uVar34,dVar31,uVar39,2,iVar13,0);
        uVar38 = (undefined2)((uint)uVar35 >> 0x10);
        uVar35 = (undefined4)((ulonglong)uVar39 >> 0x20);
      }
      if (((0x3b < (int)uStack_148._4_4_) && ((int)(uStack_148._4_4_ - 0x3c) % iVar17 < 0x46)) &&
         (uVar2 = (longlong)(int)(uStack_148._4_4_ - 0x3c) % (longlong)iVar17,
         uVar2 = (longlong)((ulonglong)(uint)((int)uVar2 >> 0x1f) << 0x20 | uVar2 & 0xffffffff) %
                 (longlong)iVar14, (int)uVar2 == 0)) {
        dVar29 = dVar31 - DAT_140539fc8;
        iVar13 = iVar18 * 0x8e;
        FUN_1400709b0(8,uVar2 & 0xffffffff,param_1[10],param_1[0xb],
                      CONCAT22(uVar38,*(undefined2 *)((longlong)param_1 + 0x42)),uVar34,dVar29,
                      CONCAT44(uVar35,1),2,iVar13,0);
        FUN_1400709b0(8,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + 10000,
                      uVar34,dVar29,1,2,iVar13,0);
        in_stack_fffffffffffffe50 = uVar34;
        FUN_1400709b0(8,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + -10000,
                      uVar34,dVar29,1,2,iVar13,0);
        if ((0 < DAT_140e419b8) && (iVar18 < 0x32)) {
          dVar31 = dVar31 - dVar21;
          iVar18 = iVar18 * 200;
          FUN_1400709b0(8,0,param_1[10],param_1[0xb],*(undefined2 *)((longlong)param_1 + 0x42),
                        uVar34,dVar31,1,2,iVar18,0);
          FUN_1400709b0(8,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + 10000,
                        uVar34,dVar31,1,2,iVar18,0);
          FUN_1400709b0(8,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + -10000,
                        uVar34,dVar31,1,2,iVar18,0);
          in_stack_fffffffffffffe50 = uVar34;
        }
      }
    }
  }
  iVar13 = param_1[7];
  if (iVar13 < iStack_134) {
    iVar17 = param_1[2];
    puVar3 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
        if (*(int *)((longlong)puVar3 + 4) == iVar17) {
          *(int *)((longlong)puVar3 + 0x1c) =
               *(int *)((longlong)puVar3 + 0x1c) - (iStack_134 - iVar13);
        }
      }
    }
  }
  iVar13 = param_1[7];
  if (iStack_134 < iVar13) {
    param_1[7] = iStack_134;
    iVar13 = iStack_134;
  }
  if ((iVar13 < 1) && (iVar13 = param_1[2], puVar3 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
      if (*(int *)((longlong)puVar3 + 4) == iVar13) {
        *(int *)((longlong)puVar3 + 0x1c) = *(int *)((longlong)puVar3 + 0x1c) - iStack_134;
      }
    }
  }
  if ((param_1[6] == 0xa6) && (iStack_134 <= (int)((double)(int)local_130 * DAT_140539ef8))) {
    FUN_14007b010(param_1,0x960,7);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  uVar34 = SUB84(DAT_14053a020,0);
  uVar35 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar36 = SUB84(DAT_140539d28,0);
  uVar37 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  if (iStack_134 < 1) {
    param_1[0x15] = 1;
  }
LAB_1400ae8cb:
  iVar13 = 0xd;
  sVar16 = (short)local_res8;
  dVar31 = (double)FUN_1403307c0((double)(local_res8 & 0xffff) * (double)CONCAT44(uVar35,uVar34) *
                                 (double)CONCAT44(uVar37,uVar36));
  dVar31 = dVar31 * _DAT_14053a3b8;
  dVar29 = (double)FUN_140332d90((double)(local_res8 & 0xffff) * (double)CONCAT44(uVar35,uVar34) *
                                 (double)CONCAT44(uVar37,uVar36));
  dVar29 = dVar29 * _DAT_14053a3b8;
  dVar22 = (double)FUN_1403307c0();
  dVar22 = dVar22 * DAT_14053a2d8;
  fVar1 = (float)param_1[10];
  dVar20 = (double)FUN_140332d90();
  dVar20 = dVar20 * DAT_14053a2d8;
  uVar9 = 0;
  sVar6 = 0;
  sVar12 = 0;
  fVar27 = (float)param_1[0xb];
  dVar23 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a628 *
                                 (double)CONCAT44(uVar35,uVar34) * (double)CONCAT44(uVar37,uVar36));
  fVar32 = DAT_14053ac80;
  dVar21 = DAT_14053aa78;
  iVar17 = 0xc0 - (int)(dVar23 * DAT_14053a3b0);
  if (local_160 == 1) {
    sVar6 = -0x8000;
    sVar12 = -0x8000;
  }
  uVar34 = SUB84(DAT_14053b2e0,0);
  uVar35 = (undefined4)((ulonglong)DAT_14053b2e0 >> 0x20);
  if (param_1[6] == 0xa5) {
    dVar23 = (double)FUN_1403307c0();
    dVar24 = (double)FUN_140332d90();
    dVar25 = (double)FUN_1403307c0();
    dVar26 = (double)FUN_140332d90();
    uVar4 = _UNK_14053bb28;
    uVar39 = _DAT_14053bb20;
    do {
      uVar38 = (undefined2)((uint)in_stack_fffffffffffffe50 >> 0x10);
      dVar28 = (double)((float)(int)uVar9 * fVar32 + fVar32);
      fVar33 = (float)(dVar28 * dVar24) + uStack_128._4_4_;
      fVar30 = (float)(dVar28 * dVar23) + (float)uStack_128;
      dVar28 = (double)FUN_140332d90();
      sVar6 = ((short)((uVar9 & 0xffff) * 0xfce0) - (short)(int)(dVar28 * DAT_14053b2e0)) + sVar16 +
              16000;
      if (local_160 == 1) {
        dVar28 = (double)FUN_140332d90();
        sVar6 = (((short)uVar9 + 0x14) * 800 - (short)(int)(dVar28 * dVar21)) + sVar16;
      }
      if (3 < (int)uVar9) {
        dVar28 = (double)((float)(int)(uVar9 - 4) * fVar32);
        fVar33 = (float)(dVar28 * dVar26) + (float)param_1[0xb];
        fVar30 = (float)(dVar28 * dVar25) + (float)param_1[10];
      }
      in_stack_fffffffffffffe50 = CONCAT22(uVar38,sVar6);
      FUN_1400c8410(DAT_140e44d4c,0x1e,8,fVar30,fVar33,in_stack_fffffffffffffe50,uVar39,uVar4,0x80,
                    0xff,iVar17,0x80,1,local_160);
      uVar9 = uVar9 + 1;
      iVar13 = iVar13 + 0xd;
    } while (iVar13 < 0x68);
    in_stack_fffffffffffffe50 =
         CONCAT22((short)((uint)in_stack_fffffffffffffe50 >> 0x10),sVar16 + sVar12);
    FUN_1400c8410(DAT_140e44d50,0x1e,7,(float)dVar31 + (float)uStack_128,
                  (float)dVar29 + uStack_128._4_4_,in_stack_fffffffffffffe50,uVar39,uVar4,0xff,0xff,
                  0xff,0xff,1,local_160);
    uVar34 = SUB84(DAT_14053b2e0,0);
    uVar35 = (undefined4)((ulonglong)DAT_14053b2e0 >> 0x20);
    sVar6 = sVar12;
  }
  uVar9 = 0;
  puVar5 = DAT_140e46c88;
  if (param_1[6] == 0xa6) {
    dVar31 = (double)FUN_1403307c0();
    dVar29 = (double)FUN_140332d90();
    dVar23 = (double)FUN_1403307c0();
    dVar24 = (double)FUN_140332d90();
    iVar13 = 0x21;
    do {
      uVar38 = (undefined2)((uint)in_stack_fffffffffffffe50 >> 0x10);
      dVar25 = (double)((float)(int)uVar9 * fVar32 + fVar32);
      fVar33 = (float)(dVar25 * dVar29) + uStack_128._4_4_;
      fVar30 = (float)(dVar25 * dVar31) + (float)uStack_128;
      dVar25 = (double)FUN_140332d90();
      sVar6 = ((short)((uVar9 & 0xffff) * 0xfce0) -
              (short)(int)(dVar25 * (double)CONCAT44(uVar35,uVar34))) + sVar16 + 16000;
      if (local_160 == 1) {
        dVar25 = (double)FUN_140332d90();
        sVar6 = (((short)uVar9 + 0x14) * 800 - (short)(int)(dVar25 * dVar21)) + sVar16;
      }
      if (1 < (int)uVar9) {
        dVar25 = (double)((float)(int)(uVar9 - 2) * fVar32);
        fVar33 = (float)(dVar25 * dVar24) + (float)param_1[0xb];
        fVar30 = (float)(dVar25 * dVar23) + (float)param_1[10];
      }
      in_stack_fffffffffffffe50 = CONCAT22(uVar38,sVar6);
      FUN_1400c8410(DAT_140e44d4c,0x1e,8,fVar30,fVar33,in_stack_fffffffffffffe50,_DAT_14053bb20,
                    _UNK_14053bb28,0x80,0xff,iVar17,0x80,1,local_160);
      uVar36 = DAT_140e44d58;
      uVar9 = uVar9 + 1;
      iVar13 = iVar13 + 0xd;
    } while (iVar13 < 0x62);
    puVar5 = (undefined4 *)_malloc_base(0x48);
    if (puVar5 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d08 = DAT_140e46d08 + 1;
    puVar5[3] = (float)uStack_128;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar5[4] = uStack_128._4_4_;
    *puVar5 = uVar36;
    puVar5[1] = 0x1e;
    puVar5[2] = 7;
    *(short *)(puVar5 + 5) = sVar16 + sVar12;
    *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
    puVar5[10] = 0xff;
    puVar5[0xb] = 0xff;
    puVar5[0xc] = 0xff;
    puVar5[0xd] = 0xff;
    puVar5[0xe] = 1;
    puVar5[0xf] = local_160;
    *(undefined8 *)(puVar5 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar5;
    }
    sVar6 = sVar12;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
    }
  }
  DAT_140e46c88 = puVar5;
  uVar34 = DAT_140e44d54;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d08 = DAT_140e46d08 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar5[3] = (float)dVar22 + fVar1;
  puVar5[4] = (float)dVar20 + fVar27;
  *puVar5 = uVar34;
  puVar5[1] = 0x1e;
  puVar5[2] = 7;
  *(short *)(puVar5 + 5) = sVar6 + local_res10;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0xff;
  puVar5[0xe] = 1;
  puVar5[0xf] = local_160;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
  }
  DAT_140e46c88 = puVar5;
  if ((int)local_150 == 0) {
    *param_1 = 0;
  }
  return;
}


