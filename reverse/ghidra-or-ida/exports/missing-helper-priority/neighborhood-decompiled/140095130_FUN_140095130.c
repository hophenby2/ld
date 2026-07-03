// Function: FUN_140095130 @ 140095130
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140095130(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  short sVar15;
  undefined2 uVar16;
  int iVar17;
  ushort uVar18;
  short sVar19;
  float *pfVar20;
  int iVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  float fVar30;
  float fVar31;
  double dVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  float fVar36;
  uint local_res18;
  uint in_stack_fffffffffffffea8;
  double in_stack_fffffffffffffeb8;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  
  dVar4 = DAT_14053a020;
  dVar3 = DAT_140539d28;
  dVar23 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a798 * DAT_14053a020
                                 * DAT_140539d28);
  iVar17 = param_1[5];
  uVar33 = SUB84(DAT_140539f40,0);
  uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  dVar23 = dVar23 * _DAT_140539e28 + DAT_140539f40;
  if (iVar17 == 0) {
    iVar6 = param_1[3];
    if (iVar6 == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar6 = param_1[3];
      iVar17 = param_1[5];
    }
    dVar25 = DAT_14053a558;
    fVar30 = (float)param_1[0xc];
    uVar9 = iVar6 >> 0x1f;
    if (fVar30 < DAT_14053ae30) {
      uVar10 = uVar9 & 0xfffffd44;
      if ((-1 < iVar6) && (iVar6 < 0x5a)) {
        dVar24 = (double)FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a558 * dVar4 * dVar3);
        dVar24 = dVar24 * _DAT_14053b278;
        iVar12 = -700;
        goto LAB_1400952c4;
      }
    }
    else {
      uVar10 = uVar9 & 700;
      if ((-1 < iVar6) && (iVar6 < 0x5a)) {
        dVar24 = (double)FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a558 * dVar4 * dVar3);
        dVar24 = dVar24 * DAT_14053a840;
        iVar12 = 700;
LAB_1400952c4:
        uVar10 = iVar12 - (int)dVar24;
      }
    }
    param_1[10] = fVar30 - (float)(int)uVar10;
    if ((iVar6 < 0) || (0x59 < iVar6)) {
      fVar30 = (float)param_1[0xd] + DAT_140539da8;
      param_1[0xb] = (float)(uVar9 & 400) + (float)param_1[0xd];
      param_1[0xd] = fVar30;
      if (iVar6 == 0x78) {
        iVar17 = iVar17 + 1;
        *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
        param_1[5] = iVar17;
        param_1[0x15] = 0;
        param_1[3] = 0;
      }
    }
    else {
      dVar25 = (double)FUN_140332d90(((double)iVar6 - 0.0) * dVar25 * dVar4 * dVar3);
      fVar30 = (float)param_1[0xd] + DAT_140539da8;
      param_1[0xb] = (float)(400 - (int)(dVar25 * DAT_14053a6d0)) + (float)param_1[0xd];
      param_1[0xd] = fVar30;
    }
  }
  dVar25 = DAT_14053aba0;
  if (iVar17 != 1) goto LAB_14009630b;
  iVar17 = param_1[3];
  if (iVar17 < 900) {
    if (iVar17 == (iVar17 / 0x14) * 0x14) {
      uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      uVar11 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
      uVar10 = (DAT_140e418c8 + 0x115c >> 0x1e ^ DAT_140e418c8 + 0x115c) * 0x6c078965 + 1;
      param_1[0xc] = (float)(((uVar11 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ uVar11) % 0xf1 + 0xf0);
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar10 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
      param_1[0xd] = (float)(DAT_140e9fd1c % 0x3d + 0x28);
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    dVar24 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                   (double)((float)param_1[0xc] - (float)param_1[10]));
    uVar18 = (ushort)(int)(dVar24 * dVar25);
    iVar12 = ((int)(dVar24 * dVar25) & 0xffffU) - (uint)uVar1;
    iVar6 = iVar12 + 0x10000;
    if (-0x8001 < iVar12) {
      iVar6 = iVar12;
    }
    iVar12 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar12 = iVar6;
    }
    if (iVar12 < 1) {
      uVar14 = uVar1;
      if ((iVar12 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar12)) {
        uVar14 = uVar18;
      }
    }
    else {
      uVar14 = uVar18;
      if (0x1ff < iVar12) {
        uVar14 = uVar1 + 0x200;
      }
    }
  }
  else {
    *(double *)(param_1 + 0x12) = ((double)iVar17 - _DAT_14053a8b8) * DAT_140539e60;
    uVar14 = 0x4000;
  }
  *(ushort *)(param_1 + 0x10) = uVar14;
  dVar24 = (double)FUN_1403307c0();
  fVar36 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar36;
  dVar24 = (double)FUN_140332d90();
  fVar35 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar35;
  fVar30 = DAT_140e445dc;
  if (iVar17 < 900) {
    local_108 = fVar36 + DAT_14053ad10;
    local_104 = fVar35 + DAT_14053ad90;
    local_f4 = fVar35 + _DAT_14053ad3c;
    local_100 = fVar36 - DAT_14053ad10;
    local_f8 = fVar36 + DAT_14053ad80;
    local_f0 = fVar36 - DAT_14053ad80;
    fVar31 = DAT_140e445d8 - fVar36;
    local_fc = local_104;
    local_ec = local_f4;
    dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar35 + DAT_14053ad70)),(double)fVar31
                                  );
    fVar35 = fVar35 + DAT_14053adc4;
    dVar26 = (double)FUN_1403300b4((double)(fVar30 - fVar35),(double)fVar31);
    iVar6 = DAT_140e419b8;
    iVar12 = 1;
    if (DAT_140e419b8 == 0) {
      iVar12 = 0x46;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0x37;
    }
    else if (DAT_140e419b8 == 2) {
      iVar12 = 0x2d;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar12 = 0x28;
    }
    iVar21 = 1;
    if (DAT_140e419b8 == 0) {
      iVar21 = 0xc;
    }
    else if (DAT_140e419b8 == 1) {
      iVar21 = 0x10;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar21 = 0x14;
    }
    uVar33 = SUB84(DAT_140539f40,0);
    uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    if (DAT_140e419b8 == 0) {
      uVar33 = SUB84(DAT_14053a088,0);
      uVar34 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar33 = (undefined4)DAT_14053a0d0;
      uVar34 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar33 = SUB84(DAT_14053a0f8,0);
      uVar34 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar33 = (undefined4)DAT_14053a158;
      uVar34 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar33 = (undefined4)DAT_14053a1c8;
      uVar34 = (undefined4)((ulonglong)DAT_14053a1c8 >> 0x20);
    }
    if (iVar17 == 0) {
      *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
    }
    uVar5 = DAT_14053ac2c;
    dVar27 = DAT_140539f00;
    pfVar20 = &local_108;
    local_res18 = 0;
    do {
      iVar17 = 0;
      fVar30 = pfVar20[1];
      sVar15 = *(short *)((longlong)param_1 + 0x42);
      if (DAT_140e445dc < fVar30) {
        sVar15 = sVar15 + -0x8000;
      }
      uVar9 = param_1[3];
      if (local_res18 < 2) {
        if (((uVar9 < 900) && (iVar13 = (int)uVar9 % (iVar12 * 2), iVar13 < iVar21)) &&
           (iVar13 == (iVar13 / 3 + (iVar13 >> 0x1f) +
                      (int)(((longlong)iVar13 / 3 + ((longlong)iVar13 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3)) {
          fVar31 = *pfVar20;
          do {
            in_stack_fffffffffffffeb8 = (double)CONCAT44(uVar34,uVar33);
            in_stack_fffffffffffffea8 =
                 CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                          (short)iVar17 * 9000 + sVar15 + -9000);
            FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,
                          in_stack_fffffffffffffeb8,1,0);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 3);
          iVar6 = DAT_140e419b8;
          if (2 < DAT_140e419b8) {
            iVar17 = 0;
            do {
              in_stack_fffffffffffffea8 =
                   CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                            (short)iVar17 * 9000 + sVar15 + -0x2134);
              FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,
                            (double)CONCAT44(uVar34,uVar33) - dVar27,1,0);
              iVar17 = iVar17 + 1;
            } while (iVar17 < 3);
            iVar17 = 0;
            dVar28 = (double)CONCAT44(uVar34,uVar33) - dVar27;
            do {
              in_stack_fffffffffffffea8 =
                   CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                            (short)iVar17 * 9000 + sVar15 + -0x251c);
              in_stack_fffffffffffffeb8 = dVar28;
              FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,dVar28,1,0);
              iVar17 = iVar17 + 1;
              iVar6 = DAT_140e419b8;
            } while (iVar17 < 3);
          }
        }
      }
      else if (((iVar12 <= (int)uVar9) && ((int)uVar9 < 900)) &&
              ((iVar13 = (int)(uVar9 - iVar12) % (iVar12 * 2), iVar13 < iVar21 &&
               (iVar13 == (iVar13 / 3 + (iVar13 >> 0x1f) +
                          (int)(((longlong)iVar13 / 3 + ((longlong)iVar13 >> 0x3f) & 0xffffffffU) >>
                               0x1f)) * 3)))) {
        fVar31 = *pfVar20;
        do {
          in_stack_fffffffffffffeb8 = (double)CONCAT44(uVar34,uVar33);
          in_stack_fffffffffffffea8 =
               CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                        (short)iVar17 * 9000 + sVar15 + -9000);
          FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,in_stack_fffffffffffffeb8,
                        1,0);
          iVar17 = iVar17 + 1;
        } while (iVar17 < 3);
        iVar6 = DAT_140e419b8;
        if (2 < DAT_140e419b8) {
          iVar17 = 0;
          do {
            in_stack_fffffffffffffea8 =
                 CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                          (short)iVar17 * 9000 + sVar15 + -0x2134);
            FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,
                          (double)CONCAT44(uVar34,uVar33) - dVar27,1,0);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 3);
          iVar17 = 0;
          dVar28 = (double)CONCAT44(uVar34,uVar33) - dVar27;
          do {
            in_stack_fffffffffffffea8 =
                 CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                          (short)iVar17 * 9000 + sVar15 + -0x251c);
            in_stack_fffffffffffffeb8 = dVar28;
            FUN_14006c2f0(7,0,fVar31,fVar30,in_stack_fffffffffffffea8,uVar5,dVar28,1,0);
            iVar17 = iVar17 + 1;
            iVar6 = DAT_140e419b8;
          } while (iVar17 < 3);
        }
      }
      local_res18 = local_res18 + 1;
      pfVar20 = pfVar20 + 2;
    } while ((int)local_res18 < 4);
    uVar14 = *(ushort *)((longlong)param_1 + 0x42);
    iVar12 = ((int)(dVar24 * dVar25) & 0xffffU) - (uint)uVar14;
    iVar17 = iVar12 + 0x10000;
    if (-0x8001 < iVar12) {
      iVar17 = iVar12;
    }
    iVar12 = iVar17 + -0x10000;
    if (iVar17 < 0x8001) {
      iVar12 = iVar17;
    }
    uVar1 = (ushort)(int)(dVar24 * dVar25);
    if (iVar12 < 1) {
      uVar18 = uVar14;
      if ((iVar12 < 0) && (uVar18 = uVar14 - 0x10, -0x10 < iVar12)) {
        uVar18 = uVar1;
      }
    }
    else {
      uVar18 = uVar1;
      if (0xf < iVar12) {
        uVar18 = uVar14 + 0x10;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar18;
    dVar29 = DAT_14053a0f8;
    dVar28 = DAT_14053a088;
    dVar27 = DAT_140539f68;
    dVar24 = DAT_140539f40;
    iVar17 = 1;
    if (iVar6 == 0) {
      iVar17 = 0x10;
    }
    else if (iVar6 == 1) {
      iVar17 = 10;
    }
    else if (iVar6 == 2) {
      iVar17 = 8;
    }
    else if (iVar6 == 3) {
      iVar17 = 7;
    }
    else if (iVar6 == 4) {
      iVar17 = 5;
    }
    dVar32 = DAT_14053a018;
    if ((((iVar6 != 0) && (dVar32 = DAT_14053a070, iVar6 != 1)) &&
        (dVar32 = DAT_14053a088, iVar6 != 2)) &&
       ((iVar6 != 3 && (dVar32 = DAT_140539f40, iVar6 == 4)))) {
      dVar32 = DAT_14053a0f8;
    }
    uVar9 = param_1[3] - 0x3c;
    dVar32 = (double)(int)param_1[3] * DAT_140539d90 + dVar32;
    uVar16 = (undefined2)(int)(dVar26 * dVar25);
    if (uVar9 < 0x168) {
      if (uVar9 == ((int)uVar9 / 0x5a) * 0x5a) {
        *(undefined2 *)(param_1 + 0x11) = uVar16;
      }
      else if ((0x167 < uVar9) || (0x31 < (int)uVar9 % 0x5a)) goto LAB_140096027;
      if (((int)uVar9 % 0x5a) % iVar17 == 0) {
        uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
        in_stack_fffffffffffffea8 =
             CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                      (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x1771) * -0x1771 +
                      *(short *)(param_1 + 0x11) + -3000);
        in_stack_fffffffffffffeb8 = dVar32;
        FUN_14006c2f0(4,0,fVar36,fVar35,in_stack_fffffffffffffea8,uVar5,dVar32,1,0);
        if (DAT_140e419b8 == 3) {
          in_stack_fffffffffffffeb8 = dVar32 + dVar27;
          uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar9 = uVar9 * 0x800 ^ uVar9;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
          in_stack_fffffffffffffea8 =
               CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                        *(short *)(param_1 + 0x11) +
                        (short)((ulonglong)DAT_140e9fd1c / 0x1771) * -0x1771 + (short)DAT_140e9fd1c
                        + -3000);
          FUN_14006c2f0(4,0,fVar36,fVar35,in_stack_fffffffffffffea8,uVar5,in_stack_fffffffffffffeb8,
                        1,0);
        }
        dVar24 = DAT_140539f40;
        iVar6 = DAT_140e419b8;
        if (DAT_140e419b8 == 4) {
          sVar15 = *(short *)(param_1 + 0x11);
          uVar10 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
          uVar9 = uVar10 * 0x800 ^ uVar10;
          DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
          uVar2 = (ulonglong)DAT_140e9fd1c;
          iVar17 = 0;
          sVar19 = (short)DAT_140e9fd1c;
          do {
            in_stack_fffffffffffffea8 =
                 CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),
                          (short)iVar17 * 0x15b3 +
                          sVar15 + (short)(uVar2 / 0x1771) * -0x1771 + sVar19 + -0x1691);
            in_stack_fffffffffffffeb8 = dVar32;
            FUN_14006c2f0(4,0,fVar36,fVar35,in_stack_fffffffffffffea8,uVar5,dVar32,1,0);
            iVar17 = iVar17 + 1;
            dVar24 = DAT_140539f40;
            iVar6 = DAT_140e419b8;
          } while (iVar17 < 2);
        }
      }
    }
LAB_140096027:
    iVar17 = 1;
    if (iVar6 == 0) {
      iVar17 = 100;
    }
    else if (iVar6 == 1) {
      iVar17 = 0x46;
    }
    else if (iVar6 == 2) {
      iVar17 = 0x3c;
    }
    else if (iVar6 == 3) {
      iVar17 = 0x32;
    }
    else if (iVar6 == 4) {
      iVar17 = 0x19;
    }
    uVar33 = 1;
    if (iVar6 == 0) {
      uVar33 = 7;
    }
    else if (iVar6 == 1) {
      uVar33 = 9;
    }
    else if (iVar6 == 2) {
      uVar33 = 0xb;
    }
    else if (iVar6 == 3) {
      uVar33 = 0xd;
    }
    else if (iVar6 == 4) {
      uVar33 = 0xf;
    }
    dVar25 = DAT_14053a040;
    if ((((iVar6 != 0) && (dVar25 = dVar28, iVar6 != 1)) && (dVar25 = DAT_14053a0b0, iVar6 != 2)) &&
       ((iVar6 != 3 && (dVar25 = dVar24, iVar6 == 4)))) {
      dVar25 = dVar29;
    }
    iVar6 = param_1[3];
    dVar25 = ((double)iVar6 - _DAT_14053a708) * DAT_140539dc8 + dVar25;
    if ((iVar6 - 0x1c2U < 0x1c2) &&
       (uVar2 = (longlong)(iVar6 + -0x1c2) % (longlong)iVar17, (int)uVar2 == 0)) {
      in_stack_fffffffffffffea8 = CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),uVar16);
      in_stack_fffffffffffffeb8 = dVar25;
      FUN_1400709b0(2,uVar2 & 0xffffffff,fVar36,fVar35,in_stack_fffffffffffffea8,uVar5,dVar25,1,
                    uVar33,0x8000,0);
      if (2 < DAT_140e419b8) {
        in_stack_fffffffffffffeb8 = dVar25 + dVar27;
        in_stack_fffffffffffffea8 = CONCAT22((short)(in_stack_fffffffffffffea8 >> 0x10),uVar16);
        FUN_1400709b0(2,0,fVar36,fVar35,in_stack_fffffffffffffea8,uVar5,in_stack_fffffffffffffeb8,1,
                      uVar33,0x8000,0);
      }
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0x1e);
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffea8 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffeb8 & 0xffffffff00000000);
    uVar33 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar7 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar7 = 1;
      *(undefined4 *)(puVar7 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar33;
      puVar7[2] = 0x6f;
      puVar7[3] = 0;
      *(undefined4 *)(puVar7 + 4) = 0;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0;
      puVar7[6] = 0x3ff0000000000000;
      puVar7[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar7 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0;
      if (bVar22) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
    }
    DAT_140e45d28 = puVar7;
    param_1[5] = param_1[5] + 1;
    uVar33 = SUB84(DAT_140539f40,0);
    uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    param_1[0x15] = 1;
    param_1[3] = 0;
  }
  else {
    uVar33 = SUB84(DAT_140539f40,0);
    uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  }
LAB_14009630b:
  iVar17 = 0;
  if (((int)param_1[7] < 1) && (param_1[0x15] == 1)) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)(int)param_1[3] * _DAT_140539cdc + (float)param_1[0xb];
    if (param_1[3] == 0x3c) {
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a8e8 * dVar4 * dVar3
                                );
  fVar35 = DAT_14053ad1c;
  fVar30 = DAT_14053ac60;
  dVar24 = DAT_14053a740;
  dVar25 = DAT_14053a700;
  dVar26 = dVar26 * _DAT_14053a870;
  do {
    dVar27 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar24 * dVar4 * dVar3);
    dVar28 = (double)FUN_1403307c0();
    fVar36 = (float)param_1[10];
    dVar29 = (double)FUN_140332d90();
    uVar5 = DAT_140e44708;
    fVar31 = (float)param_1[0xb];
    dVar32 = (double)iVar17 * _DAT_140539e28;
    puVar8 = (undefined4 *)_malloc_base(0x48);
    if (puVar8 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar8[3] = (float)(dVar28 * (double)((float)iVar17 * fVar30)) + fVar36;
    puVar8[4] = (float)(dVar29 * (double)((float)iVar17 * fVar30)) + (fVar31 - fVar35);
    *(double *)(puVar8 + 8) = (double)CONCAT44(uVar34,uVar33) - dVar32;
    *puVar8 = uVar5;
    puVar8[1] = 0x20;
    puVar8[2] = 7;
    *(short *)(puVar8 + 5) = (short)(int)(dVar27 * dVar25) * ((short)iVar17 + 1) + -0x4000;
    *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
    puVar8[10] = 0xff;
    puVar8[0xb] = 0xff;
    puVar8[0xc] = 0xff;
    puVar8[0xd] = 0xff;
    *(undefined8 *)(puVar8 + 0xe) = 1;
    *(undefined8 *)(puVar8 + 0x10) = 0;
    DAT_140e46d10 = DAT_140e46d10 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar8;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
    }
    uVar5 = DAT_140e44bf8;
    fVar36 = DAT_14053add4;
    iVar17 = iVar17 + 1;
    DAT_140e46c88 = puVar8;
  } while (iVar17 < 0xb);
  fVar35 = (float)param_1[0xb] + DAT_14053add4;
  fVar31 = (float)(dVar23 * DAT_14053a3a0);
  fVar30 = (float)param_1[10];
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar8[3] = fVar31 + fVar30;
  puVar8[4] = fVar35;
  *puVar8 = uVar5;
  puVar8[1] = 0x20;
  puVar8[2] = 7;
  sVar15 = (short)(int)dVar26;
  *(short *)(puVar8 + 5) = sVar15;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  uVar33 = DAT_140e44bf8;
  fVar30 = (float)param_1[0xb];
  fVar35 = (float)param_1[10];
  DAT_140e46c88 = puVar8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar8[3] = fVar35 - fVar31;
  puVar8[4] = fVar30 + fVar36;
  *puVar8 = uVar33;
  puVar8[1] = 0x20;
  puVar8[2] = 7;
  *(short *)(puVar8 + 5) = -sVar15;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  puVar8[0xe] = 1;
  puVar8[0xf] = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  uVar34 = DAT_140e44958;
  fVar30 = (float)param_1[0xb] + DAT_14053ace8;
  uVar33 = param_1[10];
  DAT_140e46c88 = puVar8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar8[3] = uVar33;
  puVar8[4] = fVar30;
  *(double *)(puVar8 + 6) = dVar23;
  *puVar8 = uVar34;
  puVar8[1] = 0x20;
  puVar8[2] = 7;
  *(undefined2 *)(puVar8 + 5) = 0;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  DAT_140e46c88 = puVar8;
  FUN_140079c10(param_1,0);
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ae48) ||
        (DAT_140e445d8 / DAT_14053ab70 + DAT_14053afb0 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b404)) || (DAT_14053afd4 < (float)param_1[0xb])) &&
     (param_1[0x15] == 0)) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
  return;
}


