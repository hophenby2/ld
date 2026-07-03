// Function: FUN_140009480 @ 140009480
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140009480(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  short sVar16;
  int iVar17;
  longlong lVar18;
  int iVar19;
  ushort *puVar20;
  int *piVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  undefined8 uVar27;
  float fVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  float fVar32;
  double dVar33;
  float fVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  float fVar39;
  undefined4 local_res8;
  undefined4 uStackX_c;
  uint local_res10;
  longlong local_res20;
  undefined4 in_stack_fffffffffffffe98;
  undefined4 uVar40;
  undefined2 uVar41;
  ulonglong in_stack_fffffffffffffea0;
  ulonglong uVar42;
  undefined8 in_stack_fffffffffffffea8;
  undefined8 in_stack_fffffffffffffeb0;
  undefined4 uVar43;
  undefined8 local_118;
  undefined8 uStack_110;
  float local_108 [4];
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  
  uVar41 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  dVar23 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar24 = DAT_14053aba0;
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  iVar5 = 0;
  uVar15 = (uint)(dVar23 * DAT_14053aba0);
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffeb0 = CONCAT44(uVar43,param_1[0x14]);
    uVar40 = param_1[0xb];
    in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffffffff0000;
    uVar8 = DAT_14053a4f0;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],uVar40,in_stack_fffffffffffffea0,DAT_14053a4f0,
               in_stack_fffffffffffffeb0,1,0);
    uVar41 = (undefined2)((uint)uVar40 >> 0x10);
    uVar40 = (undefined4)((ulonglong)uVar8 >> 0x20);
    if (DAT_140e41af8 == 1) {
      param_1[5] = 8;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      param_1[5] = 6;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 3) {
      param_1[5] = 4;
      DAT_140e419bc = 2;
      param_1[0x14] = 300;
    }
    else if (DAT_140e41af8 == 4) {
      param_1[5] = 2;
      DAT_140e419bc = 2;
      param_1[0x14] = 0xf0;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar8 = _UNK_14053bb28;
  dVar29 = _DAT_14053bb20;
  fVar34 = DAT_14053ad80;
  fVar39 = DAT_14053acfc;
  dVar31 = DAT_14053a020;
  dVar23 = DAT_140539d28;
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar13 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar9 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
    DAT_140e44908 = (float)(((uVar9 >> 0xb ^ uVar13) >> 8 ^ uVar9 ^ uVar13) % 0x12d + 0xd2);
    uVar13 = DAT_140e418c8 + DAT_1407c7798 * 0xde;
    uVar9 = DAT_140e418c8 + DAT_1407c7798 * 0xde;
    uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
    if (param_1[5] == 3) {
      uVar13 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
      uVar9 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
      DAT_140e9fd14 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
      uVar13 = uVar13 * 0x800 ^ uVar13;
      uVar9 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (uVar9 >> 0xb ^ uVar13) >> 8 ^ uVar9 ^ uVar13;
      DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0xdc);
    }
  }
  iVar19 = param_1[5];
  uVar35 = SUB84(DAT_14053a020,0);
  uVar36 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar37 = SUB84(DAT_140539d28,0);
  uVar38 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  iVar4 = 0;
  uVar14 = (ushort)uVar15;
  switch(iVar19) {
  case 0:
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar19 = param_1[5];
    }
    iVar5 = param_1[3];
    if (iVar5 < 0xbf) {
      iVar19 = (int)(float)param_1[0xd];
      if (iVar5 < 0) {
        iVar19 = 900;
      }
      else if (iVar5 < 0xb4) {
        dVar24 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a438 * dVar31 * dVar23);
        iVar19 = (int)(dVar24 * (double)(iVar19 + -900)) + 900;
      }
      param_1[0xb] = (float)iVar19;
    }
    else {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      if (iVar5 == 0xd2) {
        param_1[0x15] = 0;
        param_1[5] = iVar19 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 60000;
        DAT_140e4430c = 0x708;
        DAT_140e4192c = 0;
        param_1[7] = 60000;
        DAT_140e419bc = 1;
      }
    }
    break;
  case 1:
    uVar11 = *(ushort *)(param_1 + 0x10);
    iVar19 = (uVar15 & 0xffff) - (uint)uVar11;
    iVar5 = iVar19 + 0x10000;
    if (-0x8001 < iVar19) {
      iVar5 = iVar19;
    }
    iVar19 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar19 = iVar5;
    }
    if (iVar19 < 1) {
      uVar12 = uVar11;
      if ((iVar19 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar19)) {
        uVar12 = uVar14;
      }
    }
    else {
      uVar12 = uVar14;
      if (0x1ff < iVar19) {
        uVar12 = uVar11 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar23 = (double)FUN_1403307c0();
    fVar28 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar28;
    dVar23 = (double)FUN_140332d90();
    fVar34 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar34;
    uVar40 = DAT_14053ac2c;
    dVar31 = DAT_14053a0d0;
    dVar23 = DAT_14053a070;
    if (0x1d < (int)param_1[3]) {
      local_108[0] = fVar28 + DAT_14053ace8;
      local_108[1] = fVar34;
      local_108[3] = fVar34;
      local_f8 = fVar28 + DAT_14053ad5c;
      local_f4 = fVar34 - fVar39;
      local_ec = fVar34 - fVar39;
      local_108[2] = fVar28 - DAT_14053ace8;
      local_f0 = fVar28 - DAT_14053ad5c;
      local_res10 = 0;
      local_res20 = 0;
      uVar15 = (param_1[3] + -0x1e) % 0x3c0;
      iVar5 = DAT_140e419b8;
      dVar25 = DAT_14053a178;
      do {
        fVar39 = local_108[local_res20 * 2 + 1];
        fVar34 = local_108[local_res20 * 2];
        dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar39),
                                       (double)(DAT_140e445d8 - fVar34));
        if (300 < (int)uVar15) goto LAB_14000a9ed;
        iVar19 = 1;
        if (iVar5 == 0) {
          iVar19 = 0x78;
        }
        else if (iVar5 == 1) {
          iVar19 = 0x5a;
        }
        else if (iVar5 == 2) {
          iVar19 = 0x50;
        }
        else if (iVar5 == 3) {
          iVar19 = 0x46;
        }
        else if (iVar5 == 4) {
          iVar19 = 0x3c;
        }
        iVar4 = 1;
        if (iVar5 == 0) {
          iVar4 = 0xf;
        }
        else if (iVar5 == 1) {
          iVar4 = 0x18;
        }
        else if (((iVar5 == 2) || (iVar5 == 3)) || (iVar5 == 4)) {
          iVar4 = 0x1e;
        }
        dVar30 = dVar31;
        if (((iVar5 != 0) && (dVar30 = DAT_14053a138, iVar5 != 1)) &&
           ((dVar30 = dVar25, iVar5 != 2 &&
            ((dVar30 = DAT_14053a1b8, iVar5 != 3 && (dVar30 = dVar29, iVar5 == 4)))))) {
          dVar30 = DAT_14053a208;
        }
        iVar10 = 1;
        if (iVar5 == 0) {
          iVar10 = 0x12;
        }
        else if (iVar5 == 1) {
          iVar10 = 0xb;
        }
        else if (iVar5 == 2) {
LAB_14000a2d0:
          iVar10 = 9;
        }
        else if (iVar5 == 3) {
          iVar10 = 10;
        }
        else if (iVar5 == 4) goto LAB_14000a2d0;
        iVar17 = 1;
        if (iVar5 == 0) {
          iVar17 = 3;
        }
        else if (iVar5 == 1) {
          iVar17 = 4;
        }
        else if ((iVar5 == 2) || (iVar5 == 3)) {
          iVar17 = 5;
        }
        else if (iVar5 == 4) {
          iVar17 = 6;
        }
        dVar33 = dVar23;
        if ((((iVar5 != 0) && (dVar33 = DAT_14053a088, iVar5 != 1)) && (dVar33 = dVar31, iVar5 != 2)
            ) && ((dVar33 = DAT_14053a0f8, iVar5 != 3 && (dVar33 = dVar29, iVar5 == 4)))) {
          dVar33 = DAT_14053a158;
        }
        uVar14 = (ushort)(int)(dVar26 * dVar24);
        uVar13 = (uint)(in_stack_fffffffffffffea0 >> 0x20);
        if (local_res10 == 0) {
          iVar10 = iVar19 + 0x14;
          if ((((int)uVar15 < iVar10) || (299 < (int)uVar15)) ||
             ((int)(uVar15 - iVar10) % iVar19 != 0)) {
            uVar11 = *(ushort *)((longlong)param_1 + 0x42);
            puVar20 = (ushort *)((longlong)param_1 + 0x42);
            if (((int)uVar15 < iVar10) || (299 < (int)uVar15)) goto LAB_14000a4d4;
          }
          else {
            *(ushort *)((longlong)param_1 + 0x42) = uVar14;
            uVar11 = uVar14;
          }
          puVar20 = (ushort *)((longlong)param_1 + 0x42);
          iVar19 = (int)(uVar15 - iVar10) % iVar19;
          if ((iVar19 < iVar4) &&
             (iVar19 == (iVar19 / 3 + (iVar19 >> 0x1f) +
                        (int)(((longlong)iVar19 / 3 + ((longlong)iVar19 >> 0x3f) & 0xffffffffU) >>
                             0x1f)) * 3)) {
            in_stack_fffffffffffffea0 = CONCAT44(uVar13,uVar40);
            FUN_14006c2f0(3,7,fVar34,fVar39,uVar11,in_stack_fffffffffffffea0,dVar30,1,0);
            if (2 < DAT_140e419b8) {
              dVar30 = dVar30 - DAT_140539f90;
              uVar11 = *puVar20;
              iVar5 = 0;
              do {
                in_stack_fffffffffffffea0 =
                     CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
                FUN_14006c2f0(3,7,fVar34,fVar39,(short)iVar5 * 0xaf0 + uVar11 + -0x578,
                              in_stack_fffffffffffffea0,dVar30,1,0);
                iVar5 = iVar5 + 1;
              } while (iVar5 < 2);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar5 = DAT_140e419b8;
          }
LAB_14000a4d4:
          uVar11 = *puVar20;
          iVar4 = ((int)(dVar26 * dVar24) & 0xffffU) - (uint)uVar11;
          iVar19 = iVar4 + 0x10000;
          if (-0x8001 < iVar4) {
            iVar19 = iVar4;
          }
          iVar4 = iVar19 + -0x10000;
          if (iVar19 < 0x8001) {
            iVar4 = iVar19;
          }
          if (iVar4 < 1) {
            if ((iVar4 < 0) && (uVar11 = uVar11 - 0x20, -0x20 < iVar4)) {
              uVar11 = uVar14;
            }
            *puVar20 = uVar11;
            dVar25 = DAT_14053a178;
          }
          else if (iVar4 < 0x20) {
            *puVar20 = uVar14;
            dVar25 = DAT_14053a178;
          }
          else {
            *puVar20 = uVar11 + 0x20;
            dVar25 = DAT_14053a178;
          }
        }
        else {
          if (local_res10 == 1) {
            iVar10 = iVar19 + 0x14;
            if ((((int)uVar15 < iVar10) || (299 < (int)uVar15)) ||
               ((int)(uVar15 - iVar10) % iVar19 != 0)) {
              uVar11 = *(ushort *)(param_1 + 0x11);
              puVar20 = (ushort *)(param_1 + 0x11);
              if (((int)uVar15 < iVar10) || (299 < (int)uVar15)) goto LAB_14000a4d4;
            }
            else {
              *(ushort *)(param_1 + 0x11) = uVar14;
              uVar11 = uVar14;
            }
            puVar20 = (ushort *)(param_1 + 0x11);
            iVar19 = (int)(uVar15 - iVar10) % iVar19;
            if ((iVar19 < iVar4) &&
               (iVar19 == (iVar19 / 3 + (iVar19 >> 0x1f) +
                          (int)(((longlong)iVar19 / 3 + ((longlong)iVar19 >> 0x3f) & 0xffffffffU) >>
                               0x1f)) * 3)) {
              in_stack_fffffffffffffea0 = CONCAT44(uVar13,uVar40);
              FUN_14006c2f0(3,7,fVar34,fVar39,uVar11,in_stack_fffffffffffffea0,dVar30,1,0);
              iVar5 = DAT_140e419b8;
              if (2 < DAT_140e419b8) {
                dVar30 = dVar30 - DAT_140539f90;
                uVar11 = *puVar20;
                iVar19 = 0;
                do {
                  in_stack_fffffffffffffea0 =
                       CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
                  FUN_14006c2f0(3,7,fVar34,fVar39,(short)iVar19 * 0xaf0 + uVar11 + -0x578,
                                in_stack_fffffffffffffea0,dVar30,1,0);
                  iVar19 = iVar19 + 1;
                  iVar5 = DAT_140e419b8;
                } while (iVar19 < 2);
              }
            }
            goto LAB_14000a4d4;
          }
          dVar25 = DAT_14053a178;
          if (local_res10 == 2) {
            uVar9 = uVar15;
            if (uVar15 < 300) {
LAB_14000a6cc:
              if ((int)uVar9 % (iVar10 * 2) == 0) {
                uVar9 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
                DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
                DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                in_stack_fffffffffffffea0 = (ulonglong)uVar13 << 0x20;
                uVar9 = uVar9 * 0x800 ^ uVar9;
                DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
                FUN_1400709b0(4,0,fVar34,fVar39,
                              (short)DAT_140e9fd1c +
                              (short)((ulonglong)DAT_140e9fd1c / 0x36b1) * -0x36b1 + uVar14 + -7000,
                              in_stack_fffffffffffffea0,dVar33,1,iVar17,iVar17 * 0x1b8 + -0x1b8,0);
                if (2 < DAT_140e419b8) {
                  iVar5 = iVar17 * 0x1b8 + -0x528;
                  uVar13 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
                  in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
                  DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
                  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                  uVar13 = uVar13 * 0x800 ^ uVar13;
                  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
                  FUN_1400709b0(4,0,fVar34,fVar39,
                                (short)DAT_140e9fd1c +
                                (short)((ulonglong)DAT_140e9fd1c / 0x36b1) * -0x36b1 + uVar14 +
                                -2000,in_stack_fffffffffffffea0,dVar33,1,iVar17 + -2,iVar5,0);
                  uVar13 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
                  DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
                  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                  uVar13 = uVar13 * 0x800 ^ uVar13;
                  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
                  in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
                  FUN_1400709b0(4,0,fVar34,fVar39,
                                (short)DAT_140e9fd1c +
                                (short)((ulonglong)DAT_140e9fd1c / 0x36b1) * -0x36b1 + uVar14 +
                                -12000,in_stack_fffffffffffffea0,dVar33,1,iVar17 + -2,iVar5,0);
                }
                FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
                FUN_14018a340(DAT_140e472a4,1,1);
                iVar5 = DAT_140e419b8;
                dVar25 = DAT_14053a178;
              }
            }
          }
          else if (((local_res10 == 3) && (iVar10 <= (int)uVar15)) && ((int)uVar15 < 300)) {
            uVar9 = uVar15 - iVar10;
            goto LAB_14000a6cc;
          }
        }
LAB_14000a9ed:
        uVar13 = uVar15 - 0x14a;
        if (uVar13 < 0x14b) {
          iVar19 = 1;
          if (iVar5 == 0) {
            iVar19 = 0x12;
          }
          else if (iVar5 == 1) {
            iVar19 = 9;
          }
          else if (iVar5 == 2) {
            iVar19 = 6;
          }
          else if (iVar5 == 3) {
            iVar19 = 5;
          }
          else if (iVar5 == 4) {
            iVar19 = 4;
          }
          dVar26 = DAT_140539ff0;
          if ((((iVar5 != 0) && (dVar26 = DAT_14053a040, iVar5 != 1)) &&
              (dVar26 = dVar23, iVar5 != 2)) && ((iVar5 != 3 && (dVar26 = dVar29, iVar5 == 4)))) {
            dVar26 = dVar31;
          }
          sVar16 = 1;
          dVar26 = (double)(int)uVar13 * DAT_140539dc8 + dVar26;
          local_118 = _DAT_14053ba10;
          uStack_110 = _UNK_14053ba18;
          if (iVar5 == 0) {
            sVar16 = 0xa0;
          }
          else if (iVar5 == 1) {
            sVar16 = 0xfa;
          }
          else if ((iVar5 == 2) || (iVar5 == 3)) {
            sVar16 = 300;
          }
          else if (iVar5 == 4) {
            sVar16 = 0x1b8;
          }
          sVar16 = sVar16 * (short)uVar13 +
                   (short)*(undefined4 *)((longlong)&local_118 + local_res20 * 4);
          if (0x293 < (int)uVar15) goto LAB_14000abf3;
          if ((int)((longlong)(int)uVar13 % (longlong)iVar19) != 0) goto LAB_14000af02;
          uVar8 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
          FUN_14006c2f0(9,(longlong)(int)uVar13 % (longlong)iVar19 & 0xffffffff,fVar34,fVar39,sVar16
                        ,uVar8,dVar26,1,0);
          in_stack_fffffffffffffea0 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),uVar40);
          FUN_14006c2f0(8,0,fVar34,fVar39,-sVar16,in_stack_fffffffffffffea0,dVar26,1,0);
          if (2 < DAT_140e419b8) {
            dVar26 = dVar26 + DAT_140539f68;
            uVar8 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
            FUN_14006c2f0(9,0,fVar34,fVar39,sVar16,uVar8,dVar26,1,0);
            in_stack_fffffffffffffea0 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),uVar40);
            FUN_14006c2f0(8,0,fVar34,fVar39,-sVar16,in_stack_fffffffffffffea0,dVar26,1,0);
          }
LAB_14000aed2:
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar5 = DAT_140e419b8;
        }
        else {
LAB_14000abf3:
          if (0x2b1 < (int)uVar15) {
            iVar19 = 1;
            if (iVar5 == 0) {
              iVar19 = 0x5a;
            }
            else if (iVar5 == 1) {
              iVar19 = 0x3c;
            }
            else if (iVar5 == 2) {
              iVar19 = 0x32;
            }
            else if ((iVar5 == 3) || (iVar5 == 4)) {
              iVar19 = 0x28;
            }
            iVar4 = 1;
            if ((iVar5 == 0) || (iVar5 == 1)) {
LAB_14000ac55:
              iVar4 = 0x14;
            }
            else if (iVar5 == 2) {
LAB_14000ac4e:
              iVar4 = 0x1e;
            }
            else {
              if (iVar5 == 3) goto LAB_14000ac55;
              if (iVar5 == 4) goto LAB_14000ac4e;
            }
            dVar26 = DAT_14053a0b0;
            if ((((iVar5 != 0) && (dVar26 = DAT_14053a0f8, iVar5 != 1)) &&
                (dVar26 = DAT_14053a118, iVar5 != 2)) &&
               ((dVar26 = DAT_14053a138, iVar5 != 3 && (dVar26 = dVar29, iVar5 == 4)))) {
              dVar26 = dVar25;
            }
            local_118 = _DAT_14053b970;
            uStack_110 = _UNK_14053b978;
            if (((int)uVar15 < 900) && ((int)(uVar15 - 0x2b2) % iVar19 == 0)) {
              dVar30 = (double)FUN_1403300b4((double)(DAT_140e445dc - 0.0),
                                             (double)(DAT_140e445d8 - (float)param_1[10]));
              *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar30 * dVar24);
            }
            else if (0x3a1 < (int)uVar15) goto LAB_14000af02;
            uVar13 = (int)(uVar15 - 0x2b2) % iVar19;
            if ((int)uVar13 < iVar4) {
              uVar13 = uVar13 & 0x80000003;
              if ((int)uVar13 < 0) {
                uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
              }
              if ((uVar13 == 0) && ((iVar5 != 0 || (1 < local_res10)))) {
                sVar16 = *(short *)((longlong)&local_118 + local_res20 * 4);
                sVar3 = *(short *)((longlong)param_1 + 0x42);
                iVar5 = 0;
                do {
                  in_stack_fffffffffffffea0 =
                       CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
                  FUN_14006c2f0(2,0x17,fVar34,fVar39,(short)iVar5 * -0x8000 + sVar16 + sVar3,
                                in_stack_fffffffffffffea0,dVar26,1,0);
                  iVar5 = iVar5 + 1;
                } while (iVar5 < 2);
                if (2 < DAT_140e419b8) {
                  sVar3 = *(short *)((longlong)param_1 + 0x42);
                  iVar5 = 0;
                  do {
                    in_stack_fffffffffffffea0 =
                         CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
                    FUN_14006c2f0(2,0x17,fVar34,fVar39,
                                  (short)iVar5 * -0x8000 + sVar16 + sVar3 + 2000,
                                  in_stack_fffffffffffffea0,dVar26,1,0);
                    iVar5 = iVar5 + 1;
                  } while (iVar5 < 2);
                  sVar3 = *(short *)((longlong)param_1 + 0x42);
                  iVar5 = 0;
                  do {
                    in_stack_fffffffffffffea0 =
                         CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
                    FUN_14006c2f0(2,0x17,fVar34,fVar39,
                                  (short)iVar5 * -0x8000 + sVar16 + sVar3 + -2000,
                                  in_stack_fffffffffffffea0,dVar26,1,0);
                    iVar5 = iVar5 + 1;
                  } while (iVar5 < 2);
                }
                goto LAB_14000aed2;
              }
            }
          }
        }
LAB_14000af02:
        local_res10 = local_res10 + 1;
        local_res20 = local_res20 + 1;
      } while ((int)local_res10 < 4);
      uVar35 = SUB84(DAT_14053a020,0);
      uVar36 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
      uVar37 = SUB84(DAT_140539d28,0);
      uVar38 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      fVar39 = DAT_14053acfc;
    }
    break;
  case 2:
    iVar5 = param_1[3];
    iVar19 = 0;
    if (iVar5 < 0x5a) {
LAB_14000aff8:
      if (iVar5 < 0xb4) {
        iVar4 = iVar19;
      }
      puVar7 = DAT_140e45d28;
      if (iVar5 == 1) {
        uVar40 = param_1[0xb];
        uVar2 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar7 + 0x14) = uVar2;
          *(undefined4 *)(puVar7 + 3) = uVar40;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar2;
          *(undefined4 *)(puVar7 + 4) = uVar40;
          *puVar7 = 1;
          puVar7[1] = 0x36;
          *(undefined4 *)(puVar7 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
          puVar7[5] = 0;
          puVar7[6] = 0x3ff0000000000000;
          puVar7[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar7 + 8) = 0;
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
      }
    }
    else {
      iVar19 = 0xff;
      if (iVar5 < 100) {
        dVar24 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar4 = (int)(dVar24 * DAT_14053a5f8);
        puVar7 = DAT_140e45d28;
      }
      else {
        if (0xb3 < iVar5) goto LAB_14000aff8;
        dVar24 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a278) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar4 = 0;
        puVar7 = DAT_140e45d28;
        if (iVar5 < 0xb4) {
          iVar4 = (int)(dVar24 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar7;
    iVar5 = param_1[3];
    if (iVar5 < 0x5a) {
      param_1[0xb] = (float)iVar5 * DAT_140539cc8 + (float)param_1[0xb];
      FUN_14007ac00(param_1);
    }
    puVar7 = DAT_140e45d28;
    if (param_1[3] == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar40 = param_1[0xb];
      uVar2 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar2;
        *(undefined4 *)(puVar7 + 3) = uVar40;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar2;
        *(undefined4 *)(puVar7 + 4) = uVar40;
        *puVar7 = 1;
        puVar7[1] = 0x11;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
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
    }
    DAT_140e45d28 = puVar7;
    iVar5 = param_1[3];
    if (99 < iVar5) {
      uVar11 = *(ushort *)(param_1 + 0x10);
      iVar10 = (uVar15 & 0xffff) - (uint)uVar11;
      iVar19 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar19 = iVar10;
      }
      iVar10 = iVar19 + -0x10000;
      if (iVar19 < 0x8001) {
        iVar10 = iVar19;
      }
      if (iVar10 < 1) {
        uVar12 = uVar11;
        if ((iVar10 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar10)) {
          uVar12 = uVar14;
        }
      }
      else {
        uVar12 = uVar14;
        if (0x1ff < iVar10) {
          uVar12 = uVar11 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar12;
      dVar24 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar25 = (double)FUN_140332d90();
      dVar24 = *(double *)(param_1 + 0x12);
      dVar26 = 0.0;
      fVar28 = (float)param_1[0xb];
      if (iVar5 < 0xf0) {
        dVar23 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a460) * _DAT_14053a490 * dVar31 *
                                       dVar23);
        dVar26 = dVar23 * DAT_14053b0a0 + dVar29;
      }
      fVar28 = ((float)(dVar25 * dVar24) + fVar28) - (float)dVar26;
      param_1[0xb] = fVar28;
      uVar40 = DAT_14053b358;
      if (iVar5 == 100) {
        param_1[0xb] = fVar28 + fVar34;
      }
      else if (iVar5 == 0xb4) {
        DAT_1407c77a0 = DAT_1407c779c;
        stage_entity_spawn_candidate
                  (0x22,99999999,10,DAT_14053ace8,DAT_14053b358,0x4000,dVar29,CONCAT44(uVar43,0x32),
                   1,0);
        stage_entity_spawn_candidate(0x22,99999999,10,DAT_14053b36c,uVar40,0x4000,dVar29,0x32,1,0);
        uVar40 = DAT_14053b388;
        stage_entity_spawn_candidate
                  (0x22,99999999,10,DAT_14053ad5c,DAT_14053b388,0x4000,dVar29,0x32,1,0);
        stage_entity_spawn_candidate(0x22,99999999,10,DAT_14053b3a0,uVar40,0x4000,dVar29,0x32,1,0);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
    }
    uVar40 = DAT_140e41ab8;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar40;
    puVar6[1] = 0x4e;
    *(undefined8 *)(puVar6 + 2) = 5;
    puVar6[4] = 0;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = iVar4;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    DAT_140e46c88 = puVar6;
    if (param_1[3] != 0xf0) break;
    iVar5 = param_1[5];
    *(undefined8 *)(param_1 + 0x14) = 0xdc;
    param_1[3] = 0;
    if (iVar5 == 2) {
      DAT_140e41b0c = 75000;
LAB_14000b547:
      DAT_140e4430c = 0x708;
      DAT_140e4192c = 0;
    }
    goto LAB_14000b566;
  case 3:
    uVar11 = *(ushort *)(param_1 + 0x10);
    iVar19 = (uVar15 & 0xffff) - (uint)uVar11;
    iVar5 = iVar19 + 0x10000;
    if (-0x8001 < iVar19) {
      iVar5 = iVar19;
    }
    iVar19 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar19 = iVar5;
    }
    if (iVar19 < 1) {
      uVar12 = uVar11;
      if ((iVar19 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar19)) {
        uVar12 = uVar14;
      }
    }
    else {
      uVar12 = uVar14;
      if (0x1ff < iVar19) {
        uVar12 = uVar11 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar24 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar24 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    break;
  case 4:
    iVar5 = param_1[3];
    iVar19 = iVar4;
    if (iVar5 < 0x78) {
LAB_14000b6ca:
      if (iVar5 < 0xdc) {
        iVar4 = iVar19;
      }
      puVar7 = DAT_140e45d28;
      if (iVar5 == 1) {
        uVar43 = param_1[0xb];
        uVar2 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar7 + 0x14) = uVar2;
          *(undefined4 *)(puVar7 + 3) = uVar43;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar2;
          *(undefined4 *)(puVar7 + 4) = uVar43;
          *puVar7 = 1;
          puVar7[1] = 0x36;
          *(undefined4 *)(puVar7 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
          puVar7[5] = 0;
          puVar7[6] = 0x3ff0000000000000;
          puVar7[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar7 + 8) = 0;
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
      }
    }
    else {
      iVar19 = 0xff;
      if (iVar5 < 0x82) {
        dVar24 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar4 = (int)(dVar24 * DAT_14053a5f8);
        puVar7 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar5) goto LAB_14000b6ca;
        dVar24 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar7 = DAT_140e45d28;
        if (iVar5 < 0xdc) {
          iVar4 = (int)(dVar24 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar7;
    uVar43 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    iVar5 = param_1[3];
    if (iVar5 < 0x78) {
      FUN_14007ac00(param_1);
      iVar5 = param_1[3];
      param_1[0xb] = (float)iVar5 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar7 = DAT_140e45d28;
    if (iVar5 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar2 = param_1[0xb];
      uVar1 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar1;
        *(undefined4 *)(puVar7 + 3) = uVar2;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar1;
        *(undefined4 *)(puVar7 + 4) = uVar2;
        *puVar7 = 1;
        puVar7[1] = 0x11;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
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
    }
    DAT_140e45d28 = puVar7;
    iVar5 = param_1[3];
    if (0xdb < iVar5) {
      FUN_140001900(iVar5,0xdc,1);
    }
    iVar5 = param_1[3];
    if (iVar5 == 0x82) {
      param_1[0xb] = (float)param_1[0xb] - fVar34;
LAB_14000b91d:
      uVar11 = *(ushort *)(param_1 + 0x10);
      iVar10 = (uVar15 & 0xffff) - (uint)uVar11;
      iVar19 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar19 = iVar10;
      }
      iVar10 = iVar19 + -0x10000;
      if (iVar19 < 0x8001) {
        iVar10 = iVar19;
      }
      if (iVar10 < 1) {
        uVar12 = uVar11;
        if ((iVar10 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar10)) {
          uVar12 = uVar14;
        }
      }
      else {
        uVar12 = uVar14;
        if (0x1ff < iVar10) {
          uVar12 = uVar11 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar12;
      dVar24 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar24 = (double)FUN_140332d90();
      uVar42 = CONCAT44(uVar43,0xb);
      param_1[0xb] = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar5 = FUN_1400c9580(iVar5,0,5,3,10,uVar42,CONCAT44(uVar40,0xc));
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar42 & 0xffffffffffff0000,dVar29,uVar8,0xff,0xff,0xff,0xff,1,0);
    }
    else if (0x81 < iVar5) goto LAB_14000b91d;
    uVar40 = DAT_140e41ab8;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar40;
    puVar6[1] = 0x4e;
    *(undefined8 *)(puVar6 + 2) = 5;
    puVar6[4] = 0;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = iVar4;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    DAT_140e46c88 = puVar6;
    if (param_1[3] != 0x17c) break;
    iVar5 = param_1[5];
    *(undefined8 *)(param_1 + 0x14) = 0x50;
    param_1[3] = 0;
    if (iVar5 == 4) {
      DAT_140e41b0c = 40000;
      goto LAB_14000b547;
    }
LAB_14000b566:
    param_1[7] = DAT_140e41b0c;
    param_1[5] = iVar5 + 1;
    DAT_140e419bc = 1;
    break;
  case 5:
    uVar11 = *(ushort *)(param_1 + 0x10);
    iVar4 = (uVar15 & 0xffff) - (uint)uVar11;
    iVar19 = iVar4 + 0x10000;
    if (-0x8001 < iVar4) {
      iVar19 = iVar4;
    }
    iVar4 = iVar19 + -0x10000;
    if (iVar19 < 0x8001) {
      iVar4 = iVar19;
    }
    if (iVar4 < 1) {
      uVar12 = uVar11;
      if ((iVar4 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar4)) {
        uVar12 = uVar14;
      }
    }
    else {
      uVar12 = uVar14;
      if (0x1ff < iVar4) {
        uVar12 = uVar11 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar23 = (double)FUN_1403307c0();
    fVar34 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar34;
    dVar23 = (double)FUN_140332d90();
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
    fVar28 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar28;
    fVar32 = DAT_14053ad5c;
    if (param_1[3] == 10) {
      uVar15 = 1;
      if (DAT_140e419b8 == 0) {
        uVar15 = 3;
      }
      else if (DAT_140e419b8 == 1) {
        uVar15 = 5;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar15 = 7;
      }
      else if (DAT_140e419b8 == 4) {
        uVar15 = 9;
      }
      DAT_1407c77a0 = DAT_1407c779c;
      do {
        in_stack_fffffffffffffeb0 =
             CONCAT44((int)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20),0x32);
        uVar40 = 0;
        in_stack_fffffffffffffea0 =
             CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),
                      (short)(0x10000 / uVar15) * (short)iVar5 + -0x4000);
        uVar41 = 0;
        stage_entity_spawn_candidate
                  (0x23,99999999,10,fVar32,0,in_stack_fffffffffffffea0,0,in_stack_fffffffffffffeb0,1
                   ,0);
        uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar15);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      fVar34 = (float)param_1[10];
      fVar28 = (float)param_1[0xb];
    }
    iVar5 = 10;
    if ((0x3b < (int)param_1[3]) && (iVar19 = (param_1[3] + -0x3c) % 0x1e0, 0x59 < iVar19)) {
      fVar34 = fVar34 - DAT_14053ac60;
      fVar28 = fVar28 - DAT_14053ad04;
      dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar28),
                                     (double)(DAT_140e445d8 - fVar34));
      iVar4 = 1;
      if (DAT_140e419b8 == 0) {
        iVar4 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar4 = 0x50;
      }
      else if (DAT_140e419b8 == 2) {
        iVar4 = 0x46;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar4 = 0x3c;
      }
      iVar10 = 1;
      if (DAT_140e419b8 == 0) {
        iVar10 = 5;
      }
      else if (DAT_140e419b8 == 1) {
LAB_14000bdb2:
        iVar10 = 7;
      }
      else {
        if (DAT_140e419b8 != 2) {
          if (DAT_140e419b8 == 3) goto LAB_14000bdb2;
          if (DAT_140e419b8 != 4) goto LAB_14000bdbe;
        }
        iVar10 = 9;
      }
LAB_14000bdbe:
      dVar31 = DAT_14053a088;
      if ((((DAT_140e419b8 != 0) && (dVar31 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
          (dVar31 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((dVar31 = DAT_14053a178, DAT_140e419b8 != 3 && (dVar31 = dVar29, DAT_140e419b8 == 4)))) {
        dVar31 = DAT_14053a1b8;
      }
      uVar14 = (ushort)(int)(dVar23 * dVar24);
      if ((iVar19 < 0x1c2) && ((iVar19 + -0x5a) % iVar4 == 0)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar14;
        iVar17 = (iVar19 + -0x5a) % iVar4;
        uVar11 = uVar14;
LAB_14000be53:
        uVar2 = DAT_14053ac2c;
        if (iVar17 == (iVar17 / 3 + (iVar17 >> 0x1f) +
                      (int)(((longlong)iVar17 / 3 + ((longlong)iVar17 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3) {
          dVar31 = (double)((iVar19 + -0x3c) % iVar4) * DAT_140539e40 + dVar31;
          in_stack_fffffffffffffea0 =
               CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),DAT_14053ac2c);
          dVar25 = dVar31;
          FUN_1400709b0(0x10,0,fVar34,fVar28,CONCAT22(uVar41,uVar11),in_stack_fffffffffffffea0,
                        dVar31,CONCAT44(uVar43,1),iVar10,0x8000,0);
          uVar40 = (undefined4)((ulonglong)dVar25 >> 0x20);
          if (2 < DAT_140e419b8) {
            dVar31 = dVar31 - _DAT_140539f88;
            in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar2);
            FUN_1400709b0(0x10,0,fVar34,fVar28,*(undefined2 *)((longlong)param_1 + 0x42),
                          in_stack_fffffffffffffea0,dVar31,1,iVar10 - 1U,
                          (int)(0x8000 / (ulonglong)(iVar10 - 1U)) * (iVar10 + -2) & 0xffff,0);
            uVar40 = (undefined4)((ulonglong)dVar31 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      else {
        uVar11 = *(ushort *)((longlong)param_1 + 0x42);
        if ((iVar19 < 0x1c2) && (iVar17 = (iVar19 + -0x5a) % iVar4, iVar17 < 0x18))
        goto LAB_14000be53;
      }
      uVar11 = *(ushort *)((longlong)param_1 + 0x42);
      iVar4 = ((int)(dVar23 * dVar24) & 0xffffU) - (uint)uVar11;
      iVar19 = iVar4 + 0x10000;
      if (-0x8001 < iVar4) {
        iVar19 = iVar4;
      }
      iVar4 = iVar19 + -0x10000;
      if (iVar19 < 0x8001) {
        iVar4 = iVar19;
      }
      if (iVar4 < 1) {
        uVar12 = uVar11;
        if ((iVar4 < 0) && (uVar12 = uVar11 - 0x30, -0x30 < iVar4)) {
          uVar12 = uVar14;
        }
      }
      else {
        uVar12 = uVar14;
        if (0x2f < iVar4) {
          uVar12 = uVar11 + 0x30;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar12;
    }
    iVar19 = param_1[3];
    if (iVar19 < 10) {
      in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0xe);
      iVar5 = FUN_1400c9580(iVar19,0,5,2,0xd,in_stack_fffffffffffffea0);
    }
    iVar19 = param_1[3];
    if (9 < iVar19) {
      in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x10);
      iVar5 = FUN_1400c9580(iVar19,10,5,3,0xf,in_stack_fffffffffffffea0,CONCAT44(uVar40,0x11));
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],in_stack_fffffffffffffea0 & 0xffffffffffff0000,dVar29,uVar8,0xff,0xff
                  ,0xff,0xff,1,0);
    break;
  case 6:
    iVar5 = param_1[3];
    dVar24 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar40 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    dVar24 = dVar24 * _DAT_14053b070 + dVar29;
    puVar7 = DAT_140e45d28;
    if (iVar5 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar43 = param_1[0xb];
      uVar2 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar2;
        *(undefined4 *)(puVar7 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar2;
        *(undefined4 *)(puVar7 + 4) = uVar43;
        *puVar7 = 1;
        puVar7[1] = 0x36;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
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
    }
    DAT_140e45d28 = puVar7;
    piVar21 = param_1 + 3;
    if (*piVar21 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar42 = CONCAT44(uVar40,0x13);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar5 = FUN_1400c9580(*piVar21,0,5,2,0x12,uVar42);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar42 & 0xffffffffffff0000,dVar24,dVar24,0xff,0xff,0xff,0xff,1,0);
    if (*piVar21 == 0xb4) {
      iVar5 = param_1[5];
      param_1[0x15] = 0;
      *piVar21 = 0;
      if (iVar5 == 6) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 50000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar5 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 7:
    uVar11 = *(ushort *)(param_1 + 0x10);
    iVar4 = (uVar15 & 0xffff) - (uint)uVar11;
    iVar19 = iVar4 + 0x10000;
    if (-0x8001 < iVar4) {
      iVar19 = iVar4;
    }
    iVar4 = iVar19 + -0x10000;
    if (iVar19 < 0x8001) {
      iVar4 = iVar19;
    }
    if (iVar4 < 1) {
      uVar12 = uVar11;
      if ((iVar4 < 0) && (uVar12 = uVar11 - 0x200, -0x200 < iVar4)) {
        uVar12 = uVar14;
      }
    }
    else {
      uVar12 = uVar14;
      if (0x1ff < iVar4) {
        uVar12 = uVar11 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar24 = (double)FUN_1403307c0();
    fVar34 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar34;
    dVar24 = (double)FUN_140332d90();
    fVar28 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar28;
    if ((param_1[3] == 1) && (uVar40 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar7 = 1;
      puVar7[1] = 0x2d;
      puVar7[2] = 0x3c;
      puVar7[3] = 0;
      *(undefined4 *)(puVar7 + 4) = 0;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0x3ff0000000000000;
      puVar7[6] = 0x3ff0000000000000;
      puVar7[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar7 + 8) = 0x3c;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      *(undefined4 *)(puVar7 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x54) = uVar40;
      puVar7[0xb] = 0;
      if (bVar22) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
      fVar34 = (float)param_1[10];
      fVar28 = (float)param_1[0xb];
      DAT_140e45d28 = puVar7;
    }
    if (0x3b < (int)param_1[3]) {
      if (DAT_140e419b8 == 0) {
        iVar19 = 0xc;
      }
      else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
        iVar19 = 9;
      }
      else if ((DAT_140e419b8 == 3) || (iVar19 = 1, DAT_140e419b8 == 4)) {
        iVar19 = 10;
      }
      iVar4 = 1;
      if (DAT_140e419b8 == 0) {
        iVar4 = 4;
      }
      else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
        iVar4 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar4 = 6;
      }
      iVar10 = 1;
      if ((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) {
        if (DAT_140e419b8 == 2) {
          iVar10 = 2;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar10 = 3;
        }
      }
      dVar24 = DAT_14053a018;
      if ((((DAT_140e419b8 != 0) && (dVar24 = DAT_14053a048, DAT_140e419b8 != 1)) &&
          (dVar24 = DAT_14053a070, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar24 = dVar29, DAT_140e419b8 == 4)))) {
        dVar24 = DAT_14053a0b0;
      }
      iVar17 = param_1[3] + -0x3c;
      sVar16 = *(short *)(param_1 + 3) * 300 + -18000;
      if (299 < iVar17 % 600) {
        sVar16 = -0x4000 - sVar16;
      }
      if (iVar17 % iVar19 < iVar4) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),DAT_14053ac2c)
        ;
        FUN_1400709b0(0x10,8,fVar34 - DAT_14053ac60,fVar28 - DAT_14053ad04,sVar16,
                      in_stack_fffffffffffffea0,dVar24,1,iVar10,iVar10 * 9000,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    uVar40 = DAT_14053ad40;
    if (param_1[3] == 0xd2) {
      DAT_1407c77a0 = DAT_1407c779c;
      do {
        in_stack_fffffffffffffea0 =
             CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),(short)iVar5 * 0x1c71 + -0x4000);
        stage_entity_spawn_candidate(0x24,99999999,10,uVar40,0,in_stack_fffffffffffffea0,0,0x32,1,0)
        ;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar5 = 10;
    if ((int)param_1[3] < 10) {
      in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0xe);
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,0xd,in_stack_fffffffffffffea0);
    }
    if (9 < (int)param_1[3]) {
      in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x10);
      iVar5 = FUN_1400c9580(param_1[3],10,5,3,0xf,in_stack_fffffffffffffea0,0x11);
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],in_stack_fffffffffffffea0 & 0xffffffffffff0000,dVar29,uVar8,0xff,0xff
                  ,0xff,0xff,1,0);
    break;
  case 8:
    FUN_140003ad0(param_1);
    uVar40 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    iVar5 = param_1[3];
    if (iVar5 < 0xf0) {
      iVar19 = DAT_1407c7798 + 3;
      iVar4 = DAT_1407c7798 * 10;
      if (iVar5 - 0x3cU < 0xb4) {
        uVar42 = 0;
        uVar27 = FUN_1401349e0(iVar5,0x3c,0x4c,0xe0,0xf0,0,dVar29);
        uVar40 = DAT_14053accc;
        uVar42 = uVar42 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,DAT_14053accc,uVar42,dVar29,uVar27,0xff,
                      0xff,0xff,0xff,1,0);
        uVar42 = uVar42 & 0xffffffffffff0000;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar19 * 4),0x6e,1,DAT_14053ae44,
                      uVar40,uVar42,uVar27,uVar27,0xff,0xff,0xff,0xff,1,0);
        uVar40 = (undefined4)(uVar42 >> 0x20);
        if (iVar5 == 0x4c) {
          FUN_14012e070(iVar4 + 99,4);
        }
        else {
          lVar18 = DAT_140e47908;
          if (iVar5 == 0xe0) {
            while (lVar18 != 0) {
              lVar18 = *(longlong *)(lVar18 + 0x238);
              FUN_140323ce8();
              uVar40 = (undefined4)(uVar42 >> 0x20);
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar42 = CONCAT44(uVar40,0x13);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,0x12,uVar42);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar42 & 0xffffffffffff0000,dVar29,uVar8,0xff,0xff,0xff,0xff,1,0);
    }
    puVar7 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar40 = param_1[0xb];
      uVar43 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar43;
        *(undefined4 *)(puVar7 + 3) = uVar40;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar43;
        *(undefined4 *)(puVar7 + 4) = uVar40;
        *puVar7 = 1;
        puVar7[1] = 0x10;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
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
    }
    DAT_140e45d28 = puVar7;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
  }
  iVar19 = 0;
  iVar5 = param_1[5];
  if ((iVar5 < 4) || ((iVar5 == 4 && ((int)param_1[3] < 0x82)))) {
    iVar4 = param_1[3];
    dVar24 = (double)FUN_140332d90(((double)iVar4 - 0.0) * DAT_14053a930 *
                                   (double)CONCAT44(uVar36,uVar35) * (double)CONCAT44(uVar38,uVar37)
                                  );
    uVar40 = DAT_140e44930;
    fVar34 = DAT_14053ade8;
    lVar18 = 0xf;
    if (iVar5 != 0) {
      lVar18 = 0x1e;
    }
    dVar29 = dVar24 * DAT_140539e60 + dVar29;
    if ((2 < iVar5) || ((fVar28 = 0.0, iVar5 == 2 && (100 < iVar4)))) {
      fVar28 = DAT_14053b3b0;
    }
    sVar16 = (short)DAT_140e418c8;
    uVar43 = param_1[10];
    fVar32 = fVar28 + (float)param_1[0xb] + DAT_14053ade8;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar6[3] = uVar43;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[4] = fVar32;
    *puVar6 = uVar40;
    iVar5 = (int)lVar18;
    puVar6[1] = iVar5;
    puVar6[2] = 7;
    *(short *)(puVar6 + 5) = sVar16 * 600;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    (&DAT_140e46c90)[lVar18] = (&DAT_140e46c90)[lVar18] + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar43 = DAT_140e44930;
    sVar16 = (short)DAT_140e418c8;
    fVar32 = (float)param_1[0xb];
    uVar40 = param_1[10];
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar43;
    puVar6[1] = iVar5;
    puVar6[2] = 7;
    puVar6[3] = uVar40;
    puVar6[4] = fVar28 + fVar32 + fVar34;
    *(short *)(puVar6 + 5) = sVar16 * 600 + 0x4000;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    (&DAT_140e46c90)[lVar18] = (&DAT_140e46c90)[lVar18] + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar43 = DAT_140e44930;
    sVar16 = (short)DAT_140e418c8;
    fVar32 = (float)param_1[0xb];
    uVar40 = param_1[10];
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar43;
    puVar6[1] = iVar5;
    puVar6[2] = 7;
    puVar6[3] = uVar40;
    puVar6[4] = fVar28 + fVar32 + fVar34;
    *(short *)(puVar6 + 5) = sVar16 * 600 + -0x8000;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    (&DAT_140e46c90)[lVar18] = (&DAT_140e46c90)[lVar18] + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar43 = DAT_140e44930;
    sVar16 = (short)DAT_140e418c8;
    fVar32 = (float)param_1[0xb];
    uVar40 = param_1[10];
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar43;
    puVar6[1] = iVar5;
    puVar6[2] = 7;
    puVar6[3] = uVar40;
    puVar6[4] = fVar28 + fVar32 + fVar34;
    *(short *)(puVar6 + 5) = sVar16 * 600 + -0x4000;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    (&DAT_140e46c90)[lVar18] = (&DAT_140e46c90)[lVar18] + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar43 = DAT_140e4492c;
    fVar34 = DAT_14053ad80;
    uVar40 = param_1[10];
    fVar32 = fVar28 + (float)param_1[0xb] + DAT_14053ad80;
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    (&DAT_140e46c90)[lVar18] = (&DAT_140e46c90)[lVar18] + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar6[3] = uVar40;
    puVar6[4] = fVar32;
    *puVar6 = uVar43;
    puVar6[1] = iVar5;
    puVar6[2] = 7;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar40 = DAT_140e44928;
    DAT_140e46c88 = puVar6;
    if (((int)param_1[5] < 2) || ((param_1[5] == 2 && ((int)param_1[3] < 0x65)))) {
      uVar43 = param_1[0xb];
      uVar35 = param_1[10];
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar6[3] = uVar35;
      (&DAT_140e46c98)[lVar18] = (&DAT_140e46c98)[lVar18] + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar6[4] = uVar43;
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 2;
      puVar6[2] = 7;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      uVar43 = DAT_140e44b8c;
      fVar34 = DAT_14053ad10;
      uVar40 = param_1[10];
      fVar32 = (float)param_1[0xb] - DAT_14053ad10;
      DAT_140e46c88 = puVar6;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar6[3] = uVar40;
      *(int *)(&DAT_140e46c9c + lVar18 * 4) = *(int *)(&DAT_140e46c9c + lVar18 * 4) + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar6[4] = fVar32;
      *puVar6 = uVar43;
      puVar6[1] = iVar5 + 3;
      puVar6[2] = 7;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30(&IMAGE_DOS_HEADER_140000000,(float)param_1[0xb] - fVar39,0,0,fVar34,
                            DAT_14053ad5c);
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(double *)(puVar6 + 6) = dVar29;
      puVar6[1] = iVar5 + 3;
      puVar6[2] = 7;
      *(undefined2 *)(puVar6 + 5) = 0;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      *(int *)(&DAT_140e46c9c + lVar18 * 4) = *(int *)(&DAT_140e46c9c + lVar18 * 4) + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30();
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 3;
      puVar6[2] = 7;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar29;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      *(int *)(&DAT_140e46c9c + lVar18 * 4) = *(int *)(&DAT_140e46c9c + lVar18 * 4) + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30();
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 3;
      puVar6[2] = 7;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar29;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      *(int *)(&DAT_140e46c9c + lVar18 * 4) = *(int *)(&DAT_140e46c9c + lVar18 * 4) + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30();
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 3;
      puVar6[2] = 7;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar29;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      *(int *)(&DAT_140e46c9c + lVar18 * 4) = *(int *)(&DAT_140e46c9c + lVar18 * 4) + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30();
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 2;
      puVar6[2] = 7;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar29;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      (&DAT_140e46c98)[lVar18] = (&DAT_140e46c98)[lVar18] + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      DAT_140e46c88 = puVar6;
      uVar8 = FUN_140133f30();
      uVar40 = DAT_140e44b88;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *puVar6 = uVar40;
      puVar6[1] = iVar5 + 2;
      puVar6[2] = 7;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar29;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      (&DAT_140e46c98)[lVar18] = (&DAT_140e46c98)[lVar18] + 1;
    }
    else {
      iVar4 = FUN_1400c9580(param_1[3],0,5,3,10,0xb,0xc);
      fVar32 = (float)param_1[0xb];
      uVar40 = param_1[10];
      uVar43 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4);
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar6 = uVar43;
      (&DAT_140e46c94)[lVar18] = (&DAT_140e46c94)[lVar18] + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar6[3] = uVar40;
      puVar6[4] = fVar32 - fVar34;
      puVar6[1] = iVar5 + 1;
      puVar6[2] = 0x17;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 10) = 0;
      puVar6[0xc] = 0;
      puVar6[0xd] = 0x40;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      fVar32 = (float)param_1[0xb];
      uVar43 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4);
      uVar40 = param_1[10];
      DAT_140e46c88 = puVar6;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar6[3] = uVar40;
      (&DAT_140e46c98)[lVar18] = (&DAT_140e46c98)[lVar18] + 1;
      puVar6[4] = fVar32 - fVar34;
      *puVar6 = uVar43;
      puVar6[1] = iVar5 + 2;
      puVar6[2] = 7;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
    }
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    uVar40 = DAT_14053adc0;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      uVar40 = DAT_14053adc0;
    }
    do {
      DAT_140e46c88 = puVar6;
      iVar4 = (DAT_140e418c8 & 0xffff) * 0xde;
      uVar14 = (short)iVar19 * 0x13b1 + (short)iVar4;
      uVar8 = FUN_140133f30(iVar4,fVar28 + (float)param_1[0xb] + fVar39,0,uVar14,DAT_14053ad40,
                            uVar40);
      uVar43 = DAT_140e44b90;
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      *(undefined2 *)(puVar6 + 5) = 0;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      puVar6[3] = local_res8;
      puVar6[4] = uStackX_c;
      *puVar6 = uVar43;
      puVar6[1] = (2 - (uint)(0x8000 < uVar14)) + iVar5;
      puVar6[2] = 7;
      *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      (&DAT_140e46c90)[(2 - (ulonglong)(0x8000 < uVar14)) + lVar18] =
           (&DAT_140e46c90)[(2 - (ulonglong)(0x8000 < uVar14)) + lVar18] + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      iVar19 = iVar19 + 1;
      DAT_140e46c88 = puVar6;
    } while (iVar19 < 0xd);
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


