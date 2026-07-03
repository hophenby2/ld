// Function: FUN_140034e90 @ 140034e90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140034e90(undefined4 *param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  int iVar4;
  short sVar5;
  int iVar6;
  ulonglong uVar7;
  short sVar8;
  ulonglong uVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  ushort uVar17;
  short sVar18;
  undefined4 uVar19;
  undefined4 *puVar20;
  float fVar21;
  float fVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  double dVar30;
  float fVar31;
  int local_res18;
  undefined4 in_stack_fffffffffffffe58;
  undefined2 uVar33;
  undefined4 uVar32;
  undefined1 in_stack_fffffffffffffe68 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined8 uStack_148;
  undefined8 uStack_138;
  
  iVar10 = 0;
  uStack_138 = 0;
  uStack_138._4_4_ = 0;
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        uStack_148 = *(undefined8 *)(lVar2 + 8);
        uStack_138 = *(undefined8 *)(lVar2 + 0x18);
      }
    }
  }
  fVar28 = (float)param_1[0xb];
  fVar27 = (float)param_1[10];
  dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar28),
                                 SUB84((double)(DAT_140e445d8 - fVar27),0));
  dVar26 = DAT_14053aba0;
  iVar4 = param_1[6];
  iVar11 = param_1[5];
  uVar16 = 0x65;
  if ((iVar4 - 0x8cU & 0xfffffffd) == 0) {
    uVar16 = 0x69;
  }
  sVar5 = (short)(int)(dVar23 * DAT_14053aba0);
  dVar23 = DAT_140539f40;
  if (iVar11 == 0) {
    iVar6 = param_1[3];
    dVar23 = DAT_140539ec8;
    if ((-1 < iVar6) && (dVar23 = DAT_140539f40, iVar6 < 0x28)) {
      dVar23 = (double)FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a6d8 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar23 = dVar23 * DAT_140539f28 + DAT_140539ec8;
    }
    dVar30 = *(double *)(param_1 + 0x12) -
             (*(double *)(param_1 + 0x12) / DAT_14053a340) * (double)iVar6;
    dVar24 = (double)FUN_1403307c0();
    fVar27 = (float)(dVar24 * dVar30) + fVar27;
    param_1[10] = fVar27;
    dVar24 = (double)FUN_140332d90();
    fVar28 = (float)(dVar24 * dVar30) + fVar28;
    param_1[0xb] = fVar28;
    uVar13 = DAT_140e418c8;
    if (iVar6 == 0) {
      *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
      goto LAB_140035ed0;
    }
    if (iVar6 != 0x28) goto LAB_14003524b;
    if (iVar4 == 0x8b) {
      *(undefined8 *)(param_1 + 0x12) = 0x3ff3333333333333;
      uVar13 = (uVar13 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar13 = uVar13 * 0x800 ^ uVar13;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
      *(short *)(param_1 + 0x10) =
           (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x115d) * -0x115d + sVar5 +
           -0x8ae;
LAB_1400351d2:
      if (iVar4 - 0x8dU < 2) {
        *(short *)(param_1 + 0x10) = sVar5;
        *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
      }
    }
    else {
      if (iVar4 != 0x8c) goto LAB_1400351d2;
      *(undefined8 *)(param_1 + 0x12) = 0;
      *(undefined2 *)(param_1 + 0x10) = 0x4000;
      dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xd]),
                                     SUB84((double)(DAT_140e445d8 - (float)param_1[0xc]),0));
      *(short *)(param_1 + 0x11) = (short)(int)(dVar24 * dVar26);
    }
    param_1[3] = 0;
    param_1[5] = 1;
    param_1[0x15] = 0;
  }
  else {
LAB_14003524b:
    if (iVar11 != 1) goto LAB_140035ed0;
  }
  dVar26 = (double)FUN_1403307c0();
  fVar31 = (float)(dVar26 * DAT_14053a238) + fVar27;
  dVar26 = (double)FUN_140332d90();
  uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
  iVar4 = param_1[6];
  fVar29 = (float)(dVar26 * DAT_14053a238) + fVar28;
  iVar11 = DAT_140e419b8;
  if (((iVar4 - 0x8bU & 0xfffffffc) == 0) && (iVar4 != 0x8c)) {
    dVar26 = *(double *)(param_1 + 0x12);
    dVar24 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar24 * dVar26) + fVar27;
    dVar24 = (double)FUN_140332d90();
    uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
    uVar13 = param_1[3];
    param_1[0xb] = (float)(dVar24 * dVar26) + fVar28;
    if (0xb3 < (int)uVar13) {
      *(double *)(param_1 + 0x12) = dVar26 + DAT_140539e60;
    }
    fVar28 = DAT_140e445d8;
    dVar24 = DAT_14053a0b0;
    dVar26 = DAT_14053a088;
    fVar27 = DAT_140e445dc;
    iVar11 = DAT_140e419b8;
    if ((iVar4 == 0x8b) && ((int)uVar13 < 0x96)) {
      dVar30 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar29),
                                     SUB84((double)(DAT_140e445d8 - fVar31),0));
      iVar11 = DAT_140e419b8;
      uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
      iVar4 = 1;
      dVar30 = dVar30 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar4 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar4 = 0x3c;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar4 = 0x2d;
      }
      else if (DAT_140e419b8 == 4) {
        iVar4 = 0x28;
      }
      dVar25 = DAT_14053a060;
      if ((((DAT_140e419b8 != 0) && (dVar25 = dVar26, DAT_140e419b8 != 1)) &&
          (dVar25 = dVar24, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar25 = DAT_140539f40, DAT_140e419b8 == 4)))) {
        dVar25 = DAT_14053a0f8;
      }
      fVar27 = DAT_140e445dc;
      if (((uVar13 < 0x96) && ((int)uVar13 % iVar4 == 0)) &&
         ((fVar28 / DAT_14053ab70 + DAT_14053aca8 <= fVar31 &&
          (((fVar31 <= fVar28 / DAT_14053ab70 + DAT_14053aea8 && (DAT_14053aca8 <= fVar29)) &&
           (fVar29 <= DAT_14053aef4)))))) {
        fVar21 = (float)FUN_140334430(fVar31 - fVar28,DAT_140539fc0);
        fVar27 = DAT_140e445dc;
        fVar22 = (float)FUN_140334430(fVar29 - DAT_140e445dc);
        if (fVar21 + fVar22 < 0.0) {
          fVar21 = (float)FUN_1403352f8();
        }
        else {
          fVar21 = SQRT(fVar21 + fVar22);
        }
        uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
        dVar24 = DAT_14053a0b0;
        if (DAT_14053acbc < fVar21) {
          uVar13 = ((uint)(uStack_148._4_4_ + param_1[3]) >> 0x1e ^ uStack_148._4_4_ + param_1[3]) *
                   0x6c078965 + 1;
          DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar13 = uVar13 * 0x800 ^ uVar13;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
          uVar9 = (ulonglong)DAT_140e9fd1c;
          sVar8 = (short)DAT_140e9fd1c;
          sVar18 = (short)(int)dVar30;
          iVar4 = iVar10;
          do {
            auVar34._12_4_ = in_stack_fffffffffffffe68._12_4_;
            auVar34._0_8_ = in_stack_fffffffffffffe68._0_8_;
            auVar34._8_4_ = 1;
            in_stack_fffffffffffffe68._8_8_ = auVar34._8_8_;
            in_stack_fffffffffffffe68._0_8_ = dVar25;
            in_stack_fffffffffffffe58 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe58 >> 0x10),
                          (short)iVar4 * 700 + sVar8 + (short)(uVar9 / 0x5dc1) * -0x5dc1 + sVar18 +
                          -0x319c);
            FUN_14006c2f0(4,0,fVar31,fVar29,in_stack_fffffffffffffe58,0,dVar25,
                          in_stack_fffffffffffffe68._8_8_,0);
            uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 3);
          if (2 < DAT_140e419b8) {
            uVar14 = ((uint)(uStack_148._4_4_ + param_1[3]) >> 0x1e ^ uStack_148._4_4_ + param_1[3])
                     * 0x6c078965 + 1;
            uVar13 = uVar14 * 0x800 ^ uVar14;
            DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
            uVar9 = (ulonglong)DAT_140e9fd1c;
            sVar8 = (short)DAT_140e9fd1c;
            do {
              auVar35._12_4_ = in_stack_fffffffffffffe68._12_4_;
              auVar35._0_8_ = in_stack_fffffffffffffe68._0_8_;
              auVar35._8_4_ = 1;
              in_stack_fffffffffffffe68._8_8_ = auVar35._8_8_;
              in_stack_fffffffffffffe58 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffe58 >> 0x10),
                            (short)iVar10 * 0xaf0 +
                            sVar8 + (short)(uVar9 / 0x5dc1) * -0x5dc1 + sVar18 + -0x3458);
              FUN_14006c2f0(4,0,fVar31,fVar29,in_stack_fffffffffffffe58,0,dVar25,
                            in_stack_fffffffffffffe68._8_8_,0);
              uVar33 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
              iVar10 = iVar10 + 1;
            } while (iVar10 < 2);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          fVar28 = DAT_140e445d8;
          fVar27 = DAT_140e445dc;
          iVar11 = DAT_140e419b8;
          dVar24 = DAT_14053a0b0;
        }
      }
    }
    if ((param_1[6] - 0x8d < 2) && ((int)param_1[3] < 0x96)) {
      dVar30 = (double)FUN_1403300b4((double)(fVar27 - fVar29),SUB84((double)(fVar28 - fVar31),0));
      dVar30 = dVar30 * DAT_14053aba0;
      sVar18 = 0;
      uVar9 = 1;
      if ((iVar11 == 0) || (iVar11 == 1)) {
        uVar9 = 100;
      }
      else if ((iVar11 == 2) || (iVar11 == 3)) {
        uVar9 = 0x4b;
      }
      else if (iVar11 == 4) {
        uVar9 = 0x41;
      }
      local_res18 = 1;
      if (iVar11 == 0) {
        local_res18 = 0x50;
      }
      else if (iVar11 == 1) {
        local_res18 = 0x3c;
      }
      else if (iVar11 == 2) {
        local_res18 = 0x32;
      }
      else if (iVar11 == 3) {
        local_res18 = 0x28;
      }
      else if (iVar11 == 4) {
        local_res18 = 0x20;
      }
      uVar15 = 1;
      if (iVar11 == 0) {
        uVar15 = 6;
      }
      else if (iVar11 == 1) {
        uVar15 = 8;
      }
      else if (iVar11 == 2) {
        uVar15 = 9;
      }
      else if (iVar11 == 3) {
        uVar15 = 0xb;
      }
      else if (iVar11 == 4) {
        uVar15 = 0xd;
      }
      uVar19 = 1;
      if (iVar11 == 0) {
        uVar19 = 0xd;
      }
      else if (iVar11 == 1) {
        uVar19 = 0x11;
      }
      else if (iVar11 == 2) {
        uVar19 = 0x17;
      }
      else if (iVar11 == 3) {
        uVar19 = 0x1b;
      }
      else if (iVar11 == 4) {
        uVar19 = 0x1f;
      }
      uVar7 = 1;
      if (iVar11 == 0) {
        uVar7 = 4000;
      }
      else if ((iVar11 == 1) || (iVar11 == 2)) {
        uVar7 = 0x1194;
      }
      else if ((iVar11 == 3) || (iVar11 == 4)) {
        uVar7 = 5000;
      }
      if ((((iVar11 != 0) && (dVar26 = dVar24, iVar11 != 1)) &&
          (dVar26 = DAT_14053a0d0, iVar11 != 2)) &&
         ((dVar26 = DAT_14053a0f8, iVar11 != 3 && (dVar26 = DAT_140539f40, iVar11 == 4)))) {
        dVar26 = DAT_14053a138;
      }
      iVar10 = param_1[3];
      dVar26 = (double)iVar10 * DAT_140539e20 + dVar26;
      dVar24 = DAT_14053a018;
      if (((iVar11 != 0) && (dVar24 = DAT_14053a040, iVar11 != 1)) &&
         ((dVar24 = DAT_14053a070, iVar11 != 2 &&
          ((iVar11 != 3 && (dVar24 = DAT_140539f40, iVar11 == 4)))))) {
        dVar24 = DAT_14053a0b0;
      }
      if (iVar10 == 0) {
        dVar25 = (double)FUN_1403300b4((double)(fVar27 - fVar29),SUB84((double)(fVar28 - fVar31),0))
        ;
        *(short *)(param_1 + 0x11) = (short)(int)(dVar25 * DAT_14053aba0);
        fVar28 = DAT_140e445d8;
        fVar27 = DAT_140e445dc;
      }
      if (param_1[6] == 0x8d) {
        lVar2 = (longlong)iVar10 % (longlong)(int)uVar9;
        sVar18 = (short)lVar2;
        sVar8 = (short)(uVar7 / (uVar9 >> 1));
        if ((int)lVar2 < (int)(uVar9 >> 1)) {
          sVar18 = sVar8 * sVar18 + *(short *)(param_1 + 0x11);
        }
        else {
          sVar18 = ((short)uVar9 - sVar18) * sVar8 + *(short *)(param_1 + 0x11);
        }
      }
      else if (param_1[6] == 0x8e) {
        lVar2 = (longlong)iVar10 % (longlong)(int)uVar9;
        iVar10 = (int)(uVar9 >> 1);
        sVar18 = (short)lVar2;
        if (iVar10 <= (int)lVar2) {
          sVar18 = (short)uVar9 - sVar18;
        }
        sVar18 = -(short)(uVar7 / (ulonglong)(longlong)iVar10) * sVar18 + *(short *)(param_1 + 0x11)
        ;
      }
      if ((((fVar28 / DAT_14053ab70 + DAT_14053aca8 <= fVar31) &&
           (fVar31 <= fVar28 / DAT_14053ab70 + DAT_14053aea8)) && (DAT_14053aca8 <= fVar29)) &&
         (fVar29 <= DAT_14053aef4)) {
        fVar28 = (float)FUN_140334430(fVar31 - fVar28,DAT_140539fc0);
        fVar27 = (float)FUN_140334430(fVar29 - fVar27);
        if (fVar28 + fVar27 < 0.0) {
          fVar28 = (float)FUN_1403352f8();
        }
        else {
          fVar28 = SQRT(fVar28 + fVar27);
        }
        if (DAT_14053acbc < fVar28) {
          uVar13 = param_1[3];
          if ((uVar13 < 0x96) &&
             (uVar13 == ((int)uVar13 / 3 + ((int)uVar13 >> 0x1f) +
                        (int)(((longlong)(int)uVar13 / 3 + ((longlong)(int)uVar13 >> 0x3f) &
                              0xffffffffU) >> 0x1f)) * 3)) {
            auVar36._12_4_ = in_stack_fffffffffffffe68._12_4_;
            auVar36._0_8_ = in_stack_fffffffffffffe68._0_8_;
            auVar36._8_4_ = 1;
            in_stack_fffffffffffffe68._8_8_ = auVar36._8_8_;
            in_stack_fffffffffffffe68._0_8_ = dVar26;
            uVar32 = CONCAT22(uVar33,sVar18);
            FUN_1400709b0(9,0,fVar31,fVar29,uVar32,DAT_14053ac2c,dVar26,
                          in_stack_fffffffffffffe68._8_8_,uVar15,0x10000,0);
            uVar33 = (undefined2)((uint)uVar32 >> 0x10);
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar11 = DAT_140e419b8;
          }
          if (((uint)param_1[3] < 0x96) &&
             (uVar9 = (longlong)(int)param_1[3] % (longlong)local_res18, (int)uVar9 == 0)) {
            auVar37._12_4_ = in_stack_fffffffffffffe68._12_4_;
            auVar37._0_8_ = in_stack_fffffffffffffe68._0_8_;
            auVar37._8_4_ = 1;
            in_stack_fffffffffffffe68._8_8_ = auVar37._8_8_;
            in_stack_fffffffffffffe68._0_8_ = dVar24;
            uVar15 = CONCAT22(uVar33,(short)(int)dVar30);
            FUN_1400709b0(4,uVar9 & 0xffffffff,fVar31,fVar29,uVar15,0,dVar24,
                          in_stack_fffffffffffffe68._8_8_,uVar19,0x10000,0);
            uVar33 = (undefined2)((uint)uVar15 >> 0x10);
            iVar11 = DAT_140e419b8;
          }
        }
      }
    }
  }
  if (param_1[6] == 0x8c) {
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar17 = sVar5 - uVar1;
    uVar13 = (uint)uVar17;
    if (0x8000 < uVar17) {
      uVar13 = 0x10000 - uVar17;
    }
    iVar6 = (int)uVar13 / 10 + 0x30;
    uVar17 = *(ushort *)(param_1 + 0x11);
    iVar4 = (uint)uVar17 - (uint)uVar1;
    iVar10 = iVar4 + 0x10000;
    if (-0x8001 < iVar4) {
      iVar10 = iVar4;
    }
    iVar4 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar4 = iVar10;
    }
    if (iVar4 < 1) {
      uVar12 = uVar1;
      if ((iVar4 < 0) && (uVar12 = uVar1 - (short)iVar6, -iVar6 < iVar4)) {
        uVar12 = uVar17;
      }
    }
    else {
      uVar12 = uVar17;
      if (iVar6 <= iVar4) {
        uVar12 = uVar1 + (short)iVar6;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    *(ushort *)((longlong)param_1 + 0x42) = uVar12;
    if (0x1d < (int)param_1[3]) {
      dVar26 = DAT_140539e30;
      if ((((iVar11 != 0) && (dVar26 = DAT_140539e50, iVar11 != 1)) &&
          (dVar26 = DAT_140539e60, iVar11 != 2)) &&
         ((dVar26 = DAT_140539e70, iVar11 != 3 && (dVar26 = DAT_140539f40, iVar11 == 4)))) {
        dVar26 = DAT_140539e98;
      }
      *(double *)(param_1 + 0x12) = dVar26 + *(double *)(param_1 + 0x12);
      if ((param_1[3] & 1) == 0) {
        if (((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= (float)param_1[10]) &&
            ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
           ((0.0 <= (float)param_1[0xb] && ((float)param_1[0xb] <= DAT_14053af14)))) {
          auVar38._12_4_ = in_stack_fffffffffffffe68._12_4_;
          auVar38._0_8_ = in_stack_fffffffffffffe68._0_8_;
          auVar38._8_4_ = 1;
          in_stack_fffffffffffffe68._8_8_ = auVar38._8_8_;
          in_stack_fffffffffffffe68._0_8_ = DAT_14053a218;
          FUN_14006c2f0(4,3,fVar31,fVar29,CONCAT22(uVar33,uVar12),0,DAT_14053a218,
                        in_stack_fffffffffffffe68._8_8_,0);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
    }
    dVar26 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar26 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  }
LAB_140035ed0:
  sVar18 = 0x8ae;
  fVar29 = (float)dVar23 * _DAT_14053b334;
  dVar26 = (double)FUN_1403307c0();
  fVar28 = (float)param_1[10];
  fVar31 = (float)(dVar26 * (double)fVar29);
  dVar26 = (double)FUN_140332d90();
  fVar27 = (float)param_1[0xb];
  iVar10 = uVar16 + 1;
  auVar39._12_4_ = in_stack_fffffffffffffe68._12_4_;
  auVar39._0_8_ = in_stack_fffffffffffffe68._0_8_;
  auVar39._8_4_ = iVar10;
  auVar40._4_12_ = auVar39._4_12_;
  auVar40._0_4_ = uVar16 + 2;
  fVar29 = (float)(dVar26 * (double)fVar29);
  iVar4 = FUN_1400c9580(DAT_140e418c8,0,3,4,uVar16,iVar10,auVar40);
  auVar3._8_4_ = SUB84(dVar23,0);
  auVar3._0_8_ = dVar23;
  auVar3._12_4_ = (int)((ulonglong)dVar23 >> 0x20);
  uVar15 = CONCAT22((short)((uint)iVar10 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -0x4000);
  FUN_1400c8410((&DAT_140e44660)[iVar4],0x23,7,param_1[10],param_1[0xb],uVar15,auVar3,0xff,0xff,0xff
                ,0xff,1,0);
  dVar24 = DAT_14053a798;
  dVar26 = DAT_14053a2d8;
  uVar33 = (undefined2)((uint)uVar15 >> 0x10);
  sVar5 = (short)param_1[3] * 0xc80;
  if (((((param_1[6] - 0x8b & 0xfffffffc) != 0) || (param_1[6] == 0x8c)) && (param_1[5] == 1)) &&
     (iVar10 = param_1[3], 0x1d < iVar10)) {
    if (iVar10 < 0x3c) {
      dVar30 = (double)FUN_140332d90(((double)iVar10 - DAT_14053a2d8) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      sVar18 = 0x4000 - (short)(int)(dVar30 * _DAT_14053abd0);
    }
    dVar30 = (double)FUN_140332d90();
    sVar5 = (short)(int)(dVar30 * _DAT_14053a8f0) + *(short *)((longlong)param_1 + 0x42) + sVar18 +
            -0x8000;
  }
  puVar20 = &DAT_140e44660 + (uVar16 + 3);
  uVar15 = CONCAT22(uVar33,sVar5);
  FUN_1400c8410((&DAT_140e44660)[uVar16 + 3],0x23,7,fVar28 + fVar31,fVar27 + fVar29,uVar15,dVar23,
                dVar23,0xff,0xff,0xff,0xff,1,0);
  uVar33 = (undefined2)((uint)uVar15 >> 0x10);
  sVar5 = (short)param_1[3] * 0xc80 + -0x8000;
  if (((param_1[6] - 0x8b & 0xfffffffc) != 0) || (param_1[6] == 0x8c)) {
    if ((param_1[5] == 1) && (iVar10 = param_1[3], 0x1d < iVar10)) {
      sVar5 = -0x8ae;
      if (iVar10 < 0x3c) {
        dVar26 = (double)FUN_140332d90(((double)iVar10 - dVar26) * dVar24 * DAT_14053a020 *
                                       DAT_140539d28);
        sVar5 = -0x4000 - (short)(int)(dVar26 * _DAT_14053b308);
      }
      dVar26 = (double)FUN_140332d90();
      sVar5 = (short)(int)(dVar26 * _DAT_14053b2a0) + *(short *)((longlong)param_1 + 0x42) + sVar5 +
              -0x8000;
    }
    puVar20 = &DAT_140e4466c + uVar16;
  }
  auVar41._8_8_ = dVar23;
  auVar41._0_8_ = dVar23;
  uVar15 = CONCAT22(uVar33,sVar5);
  FUN_1400c8410(*puVar20,0x23,7,fVar31 + fVar28,fVar29 + fVar27,uVar15,dVar23,dVar23,0xff,0xff,0xff,
                0xff,1,0);
  uVar33 = (undefined2)((uint)uVar15 >> 0x10);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
  fVar28 = DAT_14053b380;
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,1);
    FUN_140079e20(param_1,0);
    if (DAT_140e44654 == 0) {
      auVar42._12_4_ = auVar41._12_4_;
      auVar42._0_8_ = auVar41._0_8_;
      auVar42._8_4_ = 10;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,fVar28,fVar28,CONCAT22(uVar33,0x4000),DAT_140539f40,
                 auVar42._8_8_,1,DAT_140e44308);
    }
    *param_1 = 0;
  }
  if ((uStack_138._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad1c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af04 < (float)param_1[10])) ||
      ((float)param_1[0xb] < fVar28)) || (DAT_14053af54 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


