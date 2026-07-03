// Function: FUN_1400e3070 @ 1400e3070
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e3070(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ushort uVar6;
  double dVar7;
  undefined8 uVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ushort uVar17;
  undefined8 uVar18;
  uint uVar19;
  undefined4 uVar20;
  short sVar21;
  int iVar22;
  int iVar23;
  bool bVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  float fVar28;
  undefined4 uVar29;
  double dVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  undefined8 in_stack_fffffffffffffee8;
  undefined8 uVar35;
  double dVar36;
  uint in_stack_fffffffffffffef0;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined4 uVar55;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined1 local_b8 [128];
  
  uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  dVar25 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar30 = DAT_14053aba0;
  dVar27 = DAT_14053a4f0;
  dVar26 = DAT_14053a070;
  uVar55 = SUB84(DAT_14053a070,0);
  uVar29 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
  dVar25 = dVar25 * DAT_14053aba0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar37._12_4_ = in_stack_fffffffffffffef8._12_4_;
    auVar37._0_8_ = in_stack_fffffffffffffef8._0_8_;
    auVar37._8_4_ = param_1[0x14];
    in_stack_fffffffffffffef8._8_8_ = auVar37._8_8_;
    in_stack_fffffffffffffef8._0_8_ = dVar27;
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    uVar35 = CONCAT44(uVar32,param_1[0xb]);
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],uVar35,in_stack_fffffffffffffef0,dVar27,
               in_stack_fffffffffffffef8._8_8_,1,0);
    uVar32 = (undefined4)((ulonglong)uVar35 >> 0x20);
    if (DAT_140e41928 == 0) {
      uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      dVar36 = dVar26;
      in_stack_fffffffffffffef0 = DAT_14053ac80;
      FUN_1400ca6d0(6,(ulonglong)DAT_140e9fd1c / 0x4001,param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),dVar26,
                    DAT_14053ac80);
      uVar32 = (undefined4)((ulonglong)dVar36 >> 0x20);
    }
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 0xf0;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar7 = DAT_14053a020;
  dVar36 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar14 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
    uVar19 = uVar19 * 0x800 ^ uVar19;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
    uVar15 = DAT_1407c7798 * 0x6f + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar14 >> 0xb ^ uVar19) >> 8 ^ uVar14 ^ uVar19) % 0x12d + 0xd2);
    uVar19 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar19 = uVar19 * 0x800 ^ uVar19;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  iVar23 = param_1[5];
  iVar16 = 0;
  if (iVar23 != 0) {
    if (iVar23 == 1) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar16 = ((int)dVar25 & 0xffffU) - (uint)uVar1;
      iVar23 = iVar16 + 0x10000;
      if (-0x8001 < iVar16) {
        iVar23 = iVar16;
      }
      iVar16 = iVar23 + -0x10000;
      if (iVar23 < 0x8001) {
        iVar16 = iVar23;
      }
      uVar6 = (ushort)(int)dVar25;
      if (iVar16 < 1) {
        uVar17 = uVar1;
        if ((iVar16 < 0) && (uVar17 = uVar1 - 0x200, -0x200 < iVar16)) {
          uVar17 = uVar6;
        }
      }
      else {
        uVar17 = uVar6;
        if (0x1ff < iVar16) {
          uVar17 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar17;
      dVar27 = (double)FUN_1403307c0();
      fVar31 = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar31;
      dVar25 = (double)FUN_140332d90();
      dVar27 = _DAT_14053bb20;
      iVar23 = param_1[3];
      auVar3._8_8_ = _UNK_14053bb28;
      auVar3._0_8_ = _DAT_14053bb20;
      uVar32 = SUB84(_DAT_14053bb20,0);
      uVar33 = (undefined4)((ulonglong)_DAT_14053bb20 >> 0x20);
      fVar28 = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar28;
      fVar34 = DAT_14053ace8;
      if (0x1d < iVar23) {
        dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar28 + DAT_14053ace8)),
                                       (double)(DAT_140e445d8 - fVar31));
        fVar31 = DAT_14053ad14;
        fVar28 = DAT_14053aa20;
        uVar19 = (iVar23 + -0x1e) % 0x44c;
        sVar21 = (short)(int)(dVar25 * dVar30);
        if ((int)uVar19 < 500) {
          iVar23 = 1;
          if (DAT_140e419b8 == 0) {
            iVar23 = 0x8c;
          }
          else if (DAT_140e419b8 == 1) {
            iVar23 = 0x78;
          }
          else if (DAT_140e419b8 == 2) {
            iVar23 = 0x6e;
          }
          else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
            iVar23 = 0x66;
          }
          uVar14 = 1;
          if (DAT_140e419b8 == 0) {
            uVar14 = 7;
          }
          else if (DAT_140e419b8 == 1) {
            uVar14 = 9;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            uVar14 = 0xb;
          }
          else if (DAT_140e419b8 == 4) {
            uVar14 = 0xd;
          }
          uVar20 = 1;
          if (DAT_140e419b8 == 0) {
            uVar20 = 0xf;
          }
          else if (DAT_140e419b8 == 1) {
            uVar20 = 0x13;
          }
          else if (DAT_140e419b8 == 2) {
            uVar20 = 0x17;
          }
          else if (DAT_140e419b8 == 3) {
            uVar20 = 0x19;
          }
          else if (DAT_140e419b8 == 4) {
            uVar20 = 0x1e;
          }
          if (DAT_140e419b8 == 0) {
            uVar55 = (undefined4)DAT_140539ff0;
            uVar29 = (undefined4)((ulonglong)DAT_140539ff0 >> 0x20);
          }
          else if (DAT_140e419b8 == 1) {
            uVar55 = (undefined4)DAT_14053a018;
            uVar29 = (undefined4)((ulonglong)DAT_14053a018 >> 0x20);
          }
          else if (DAT_140e419b8 == 2) {
            uVar55 = (undefined4)DAT_14053a040;
            uVar29 = (undefined4)((ulonglong)DAT_14053a040 >> 0x20);
          }
          else if ((DAT_140e419b8 != 3) && (uVar55 = uVar32, uVar29 = uVar33, DAT_140e419b8 == 4)) {
            uVar55 = SUB84(DAT_14053a0b0,0);
            uVar29 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
          }
          if ((uVar19 < 500) && ((int)uVar19 % (iVar23 * 2) == 0)) {
            iVar16 = 0;
            do {
              auVar38._12_4_ = in_stack_fffffffffffffef8._12_4_;
              auVar38._0_8_ = in_stack_fffffffffffffef8._0_8_;
              auVar38._8_4_ = 0x1e;
              auVar4._8_8_ = 0;
              auVar4._0_8_ = auVar38._8_8_;
              in_stack_fffffffffffffef8 = auVar4 << 0x40;
              stage_entity_spawn_candidate
                        (0xc4,600,5,param_1[10],(float)param_1[0xb] + fVar34,
                         (short)iVar16 * (short)(0x10000 / uVar14) + *(short *)(param_1 + 3) * 0x457
                         ,0,auVar38._8_8_,1,0);
              iVar16 = iVar16 + 1;
            } while (iVar16 < (int)uVar14);
            auVar39._12_4_ = in_stack_fffffffffffffef8._12_4_;
            auVar39._0_8_ = in_stack_fffffffffffffef8._0_8_;
            auVar39._8_4_ = 1;
            in_stack_fffffffffffffef8._8_8_ = auVar39._8_8_;
            in_stack_fffffffffffffef8._0_8_ = CONCAT44(uVar29,uVar55);
            in_stack_fffffffffffffef0 = 0;
            FUN_1400709b0(2,0,param_1[10],(float)param_1[0xb] + fVar34,sVar21,0,
                          CONCAT44(uVar29,uVar55),in_stack_fffffffffffffef8._8_8_,uVar20,0x10000,0);
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
            FUN_14018a340(DAT_140e472bc,1,1);
          }
          if ((iVar23 <= (int)uVar19) && ((int)(uVar19 - iVar23) % (iVar23 * 2) == 0)) {
            iVar23 = 0;
            do {
              auVar40._12_4_ = in_stack_fffffffffffffef8._12_4_;
              auVar40._0_8_ = in_stack_fffffffffffffef8._0_8_;
              auVar40._8_4_ = 0x1e;
              auVar5._8_8_ = 0;
              auVar5._0_8_ = auVar40._8_8_;
              in_stack_fffffffffffffef8 = auVar5 << 0x40;
              stage_entity_spawn_candidate
                        (0xc5,600,5,param_1[10],(float)param_1[0xb] + fVar34,
                         (short)iVar23 * (short)(0x10000 / uVar14) +
                         *(short *)(param_1 + 3) * -0x457,0,auVar40._8_8_,1,0);
              iVar23 = iVar23 + 1;
            } while (iVar23 < (int)uVar14);
            auVar41._12_4_ = in_stack_fffffffffffffef8._12_4_;
            auVar41._0_8_ = in_stack_fffffffffffffef8._0_8_;
            auVar41._8_4_ = 1;
            in_stack_fffffffffffffef0 = 0;
            FUN_1400709b0(2,0,param_1[10],(float)param_1[0xb] + fVar34,sVar21,0,
                          CONCAT44(uVar29,uVar55),auVar41._8_8_,uVar20,0x10000,0);
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
            FUN_14018a340(DAT_140e472bc,1,1);
          }
        }
        else if (0x243 < (int)uVar19) {
          sVar11 = 1;
          if ((((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) || (DAT_140e419b8 == 2)) ||
             ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
            sVar11 = 0x78;
          }
          iVar23 = 1;
          if (DAT_140e419b8 == 0) {
            iVar23 = 0x2d;
          }
          else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) ||
                  ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
            iVar23 = 0x23;
          }
          iVar16 = 1;
          if (DAT_140e419b8 == 0) {
            iVar16 = 6;
          }
          else if (DAT_140e419b8 == 1) {
            iVar16 = 8;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            iVar16 = 10;
          }
          dVar30 = DAT_14053a030;
          if (((DAT_140e419b8 != 0) && (dVar30 = dVar26, DAT_140e419b8 != 1)) &&
             ((dVar30 = DAT_14053a0b0, DAT_140e419b8 != 2 &&
              ((DAT_140e419b8 != 3 && (dVar30 = dVar27, DAT_140e419b8 == 4)))))) {
            dVar30 = DAT_14053a110;
          }
          iVar22 = 1;
          if (DAT_140e419b8 == 0) {
            iVar22 = 0xe;
          }
          else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
            iVar22 = 9;
          }
          else if (DAT_140e419b8 == 3) {
            iVar22 = 8;
          }
          else if (DAT_140e419b8 == 4) {
            iVar22 = 7;
          }
          uVar55 = 1;
          if (DAT_140e419b8 == 0) {
            uVar55 = 3;
          }
          else if (DAT_140e419b8 == 1) {
            uVar55 = 5;
          }
          else if (DAT_140e419b8 == 2) {
            uVar55 = 6;
          }
          else if (DAT_140e419b8 == 3) {
            uVar55 = 7;
          }
          else if (DAT_140e419b8 == 4) {
            uVar55 = 8;
          }
          if (DAT_140e419b8 == 0) {
            uVar32 = (undefined4)DAT_14053a088;
            uVar33 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
          }
          else if (DAT_140e419b8 == 1) {
            uVar32 = (undefined4)DAT_14053a0d0;
            uVar33 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
          }
          else if (DAT_140e419b8 == 2) {
            uVar32 = SUB84(DAT_14053a0f8,0);
            uVar33 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
          }
          else if (DAT_140e419b8 == 3) {
            uVar32 = SUB84(DAT_14053a138,0);
            uVar33 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
          }
          else if (DAT_140e419b8 == 4) {
            uVar32 = (undefined4)DAT_14053a1a8;
            uVar33 = (undefined4)((ulonglong)DAT_14053a1a8 >> 0x20);
          }
          if ((int)uVar19 < 0x424) {
            uVar2 = (longlong)(int)(uVar19 - 0x244) % (longlong)iVar23;
            if ((int)uVar2 == 0) {
              sVar10 = (short)uVar19 * sVar11;
              iVar23 = iVar16 * 600 + -600;
              sVar9 = sVar10 + 0x2000;
              auVar42._12_4_ = in_stack_fffffffffffffef8._12_4_;
              auVar42._0_8_ = in_stack_fffffffffffffef8._0_8_;
              auVar42._8_4_ = 1;
              auVar43._8_8_ = auVar42._8_8_;
              auVar43._0_8_ = dVar30;
              FUN_1400709b0(3,uVar2 & 0xffffffff,(float)param_1[10] + DAT_14053ad14,
                            (float)param_1[0xb] - DAT_14053aa20,sVar9,0,dVar30,auVar43._8_8_,iVar16,
                            iVar23,0);
              sVar10 = -0x2000 - sVar10;
              auVar44._12_4_ = auVar43._12_4_;
              auVar44._0_8_ = auVar43._0_8_;
              auVar44._8_4_ = 1;
              in_stack_fffffffffffffef8._8_8_ = auVar44._8_8_;
              in_stack_fffffffffffffef8._0_8_ = dVar30;
              in_stack_fffffffffffffef0 = 0;
              FUN_1400709b0(3,0,(float)param_1[10] - fVar31,(float)param_1[0xb] - fVar28,sVar10,0,
                            dVar30,in_stack_fffffffffffffef8._8_8_,iVar16,iVar23,0);
              if (2 < DAT_140e419b8) {
                dVar30 = dVar30 + DAT_140539f00;
                auVar45._12_4_ = in_stack_fffffffffffffef8._12_4_;
                auVar45._0_8_ = in_stack_fffffffffffffef8._0_8_;
                auVar45._8_4_ = 1;
                auVar46._8_8_ = auVar45._8_8_;
                auVar46._0_8_ = dVar30;
                FUN_1400709b0(3,0,(float)param_1[10] + fVar31,(float)param_1[0xb] - fVar28,sVar9,0,
                              dVar30,auVar46._8_8_,iVar16,iVar23,0);
                auVar47._12_4_ = auVar46._12_4_;
                auVar47._0_8_ = auVar46._0_8_;
                auVar47._8_4_ = 1;
                in_stack_fffffffffffffef8._8_8_ = auVar47._8_8_;
                in_stack_fffffffffffffef8._0_8_ = dVar30;
                in_stack_fffffffffffffef0 = 0;
                FUN_1400709b0(3,0,(float)param_1[10] - fVar31,(float)param_1[0xb] - fVar28,sVar10,0,
                              dVar30,in_stack_fffffffffffffef8._8_8_,iVar16,iVar23,0);
              }
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
            }
            else if (0x423 < (int)uVar19) goto LAB_1400e4143;
            uVar2 = (longlong)(int)(uVar19 - 0x244) % (longlong)iVar22;
            if ((int)uVar2 == 0) {
              auVar48._12_4_ = in_stack_fffffffffffffef8._12_4_;
              auVar48._0_8_ = in_stack_fffffffffffffef8._0_8_;
              auVar48._8_4_ = 1;
              auVar49._8_8_ = auVar48._8_8_;
              auVar49._0_8_ = CONCAT44(uVar33,uVar32);
              sVar11 = (short)uVar19 * sVar11;
              FUN_1400709b0(5,uVar2 & 0xffffffff,(float)param_1[10] + fVar31,
                            (float)param_1[0xb] - fVar28,sVar11 + -0x6000,0,CONCAT44(uVar33,uVar32),
                            auVar49._8_8_,uVar55,25000,0);
              auVar50._12_4_ = auVar49._12_4_;
              auVar50._0_8_ = auVar49._0_8_;
              auVar50._8_4_ = 1;
              in_stack_fffffffffffffef8._8_8_ = auVar50._8_8_;
              in_stack_fffffffffffffef8._0_8_ = CONCAT44(uVar33,uVar32);
              in_stack_fffffffffffffef0 = 0;
              FUN_1400709b0(5,0,(float)param_1[10] - fVar31,(float)param_1[0xb] - fVar28,
                            0x6000 - sVar11,0,CONCAT44(uVar33,uVar32),
                            in_stack_fffffffffffffef8._8_8_,uVar55,25000,0);
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
            }
          }
LAB_1400e4143:
          iVar23 = 1;
          if (DAT_140e419b8 == 0) {
            iVar23 = 0x50;
          }
          else if (DAT_140e419b8 == 1) {
            iVar23 = 0x3c;
          }
          else if (DAT_140e419b8 == 2) {
            iVar23 = 0x32;
          }
          else if (DAT_140e419b8 == 3) {
            iVar23 = 0x28;
          }
          else if (DAT_140e419b8 == 4) {
            iVar23 = 0x20;
          }
          dVar26 = DAT_14053a0f8;
          if ((((DAT_140e419b8 != 0) && (dVar26 = DAT_14053a138, DAT_140e419b8 != 1)) &&
              (dVar26 = DAT_14053a158, DAT_140e419b8 != 2)) &&
             ((dVar26 = DAT_14053a1b8, DAT_140e419b8 != 3 && (dVar26 = dVar27, DAT_140e419b8 == 4)))
             ) {
            dVar26 = DAT_14053a1e8;
          }
          if ((uVar19 - 700 < 0x168) && ((int)(uVar19 - 700) % iVar23 == 0)) {
            iVar23 = 0;
            if (1 < DAT_140e419b8) {
              fVar28 = (float)param_1[0xb];
              dVar30 = dVar26 - DAT_140539fc8;
              uVar55 = param_1[10];
              iVar16 = iVar23;
              do {
                auVar51._12_4_ = in_stack_fffffffffffffef8._12_4_;
                auVar51._0_8_ = in_stack_fffffffffffffef8._0_8_;
                auVar51._8_4_ = 1;
                in_stack_fffffffffffffef8._8_8_ = auVar51._8_8_;
                in_stack_fffffffffffffef8._0_8_ = dVar30;
                FUN_14006c2f0(0xc,0,uVar55,fVar28 + fVar34,(short)iVar16 * 0x640 + sVar21 + -0x640,0
                              ,dVar30,in_stack_fffffffffffffef8._8_8_,0);
                iVar16 = iVar16 + 1;
              } while (iVar16 < 3);
            }
            fVar28 = (float)param_1[0xb];
            uVar55 = param_1[10];
            do {
              auVar52._12_4_ = in_stack_fffffffffffffef8._12_4_;
              auVar52._0_8_ = in_stack_fffffffffffffef8._0_8_;
              auVar52._8_4_ = 1;
              in_stack_fffffffffffffef8._8_8_ = auVar52._8_8_;
              in_stack_fffffffffffffef8._0_8_ = dVar26 - dVar27;
              FUN_14006c2f0(0xc,0,uVar55,fVar28 + fVar34,(short)iVar23 * 0x640 + sVar21 + -800,0,
                            dVar26 - dVar27,in_stack_fffffffffffffef8._8_8_,0);
              iVar23 = iVar23 + 1;
            } while (iVar23 < 2);
            auVar53._12_4_ = in_stack_fffffffffffffef8._12_4_;
            auVar53._0_8_ = in_stack_fffffffffffffef8._0_8_;
            auVar53._8_4_ = 1;
            in_stack_fffffffffffffef0 = 0;
            FUN_14006c2f0(0xc,0,param_1[10],(float)param_1[0xb] + fVar34,sVar21,0,dVar26,
                          auVar53._8_8_,0);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
          }
        }
      }
      FUN_1400c8410(DAT_140e44910,0x1e,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffef0 & 0xffff0000,auVar3,0xff,0xff,0xff,0xff,1,0);
      goto LAB_1400e4758;
    }
    if (iVar23 != 2) goto LAB_1400e4758;
    iVar23 = param_1[3];
    iVar22 = iVar16;
    if (iVar23 < 0x5a) {
LAB_1400e34cc:
      if (iVar23 < 0x96) {
        iVar16 = iVar22;
      }
      puVar12 = DAT_140e45d28;
      if (iVar23 == 1) {
        uVar55 = param_1[0xb];
        uVar29 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar12 = (undefined8 *)_malloc_base(0x60);
          if (puVar12 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar24 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar12 + 0x14) = uVar29;
          *(undefined4 *)(puVar12 + 3) = uVar55;
          *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar29;
          *(undefined4 *)(puVar12 + 4) = uVar55;
          *puVar12 = 1;
          puVar12[1] = 0x36;
          *(undefined4 *)(puVar12 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
          puVar12[5] = 0;
          puVar12[6] = 0x3ff0000000000000;
          puVar12[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar12 + 8) = 0;
          *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
          *(undefined4 *)(puVar12 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
          puVar12[10] = 0xff;
          puVar12[0xb] = 0;
          if (bVar24) {
            DAT_140e45d78 = puVar12;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar12;
          }
        }
      }
    }
    else {
      iVar22 = 0xff;
      if (iVar23 < 100) {
        dVar26 = (double)FUN_140332d90(((double)iVar23 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar16 = (int)(dVar26 * DAT_14053a5f8);
        puVar12 = DAT_140e45d28;
      }
      else {
        if (0x95 < iVar23) goto LAB_1400e34cc;
        dVar26 = (double)FUN_140332d90(((double)iVar23 - DAT_14053a380) * DAT_14053a670 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar12 = DAT_140e45d28;
        if (iVar23 < 0x96) {
          iVar16 = (int)(dVar26 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar12;
    iVar23 = param_1[3];
    if (iVar23 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar23 = param_1[3];
      param_1[0xb] = (float)iVar23 * _DAT_140539ccc + (float)param_1[0xb];
    }
    if (iVar23 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar55 = param_1[0xb];
      uVar29 = param_1[10];
      puVar12 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar12 = (undefined8 *)_malloc_base(0x60);
        if (puVar12 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar24 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar12 + 0x14) = uVar29;
        *(undefined4 *)(puVar12 + 3) = uVar55;
        *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar29;
        *(undefined4 *)(puVar12 + 4) = uVar55;
        *puVar12 = 1;
        puVar12[1] = 0x11;
        *(undefined4 *)(puVar12 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
        puVar12[5] = 0;
        puVar12[6] = 0x3ff0000000000000;
        puVar12[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar12 + 8) = 0;
        *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
        *(undefined4 *)(puVar12 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
        puVar12[10] = 0xff;
        puVar12[0xb] = 0;
        if (bVar24) {
          DAT_140e45d78 = puVar12;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar12;
        }
      }
      DAT_140e45d28 = puVar12;
      DAT_140e46a08 = DAT_140e418c8;
    }
    uVar55 = DAT_140e41ab8;
    puVar13 = (undefined4 *)_malloc_base(0x48);
    if (puVar13 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar24 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar13 = uVar55;
    puVar13[1] = 0x4e;
    *(undefined8 *)(puVar13 + 2) = 5;
    puVar13[4] = 0;
    *(undefined2 *)(puVar13 + 5) = 0;
    *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
    puVar13[10] = 0xff;
    puVar13[0xb] = 0xff;
    puVar13[0xc] = 0xff;
    puVar13[0xd] = iVar16;
    *(undefined8 *)(puVar13 + 0xe) = 1;
    *(undefined8 *)(puVar13 + 0x10) = 0;
    if (bVar24) {
      DAT_140e46bf0 = puVar13;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
    }
    DAT_140e46c88 = puVar13;
    if ((int)param_1[3] < 100) {
      FUN_1400c8410(DAT_140e44910,0x1e,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffef0 & 0xffff0000,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                    0xff,0xff,1,0);
    }
    if (param_1[3] == 0x96) {
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
    goto LAB_1400e4758;
  }
  iVar23 = param_1[3];
  uVar19 = iVar23 >> 0x1f & 0xfffffda8;
  if ((-1 < iVar23) && (iVar23 < 0xb4)) {
    dVar26 = (double)FUN_140332d90(((double)iVar23 - 0.0) * DAT_14053a438 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar19 = -(int)(dVar26 * _DAT_14053b260) - 600;
  }
  puVar12 = (undefined8 *)FUN_140135060(local_b8,iVar23,0x14);
  uVar8 = _UNK_14053bb28;
  dVar26 = _DAT_14053bb20;
  uVar35 = *puVar12;
  uVar55 = *(undefined4 *)(puVar12 + 1);
  iVar22 = iVar16;
  if (iVar23 < 0xb4) {
LAB_1400e448b:
    if (iVar23 < 0xf0) {
      iVar16 = iVar22;
    }
    if (iVar23 == 0) {
      auVar54._12_4_ = in_stack_fffffffffffffef8._12_4_;
      auVar54._0_8_ = in_stack_fffffffffffffef8._0_8_;
      auVar54._8_4_ = 100;
      in_stack_fffffffffffffef0 = CONCAT22((short)(in_stack_fffffffffffffef0 >> 0x10),0x4000);
      uVar18 = CONCAT44(uVar32,DAT_14053adbc);
      stage_entity_spawn_candidate
                (0x12,99999999,0,0,uVar18,in_stack_fffffffffffffef0,_DAT_14053bb20,auVar54._8_8_,1,
                 param_1[1]);
      uVar32 = (undefined4)((ulonglong)uVar18 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
    }
  }
  else if (iVar23 < 0xbe) {
    dVar27 = (double)FUN_140332d90(((double)iVar23 - DAT_14053a548) * DAT_14053a9d8 * dVar7 * dVar36
                                  );
    iVar16 = (int)(dVar27 * DAT_14053a5f8);
  }
  else {
    iVar22 = 0xff;
    if (0xef < iVar23) goto LAB_1400e448b;
    dVar27 = (double)FUN_140332d90(((double)iVar23 - dVar27) * DAT_14053a670 * dVar7 * dVar36);
    if (iVar23 < 0xf0) {
      iVar16 = (int)(dVar27 * DAT_14053a5f8);
    }
  }
  if (param_1[3] == 0xb4) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
    FUN_14018a340(DAT_140e472bc,1,1);
  }
  iVar23 = param_1[3];
  if (iVar23 < 0xbf) {
    dVar27 = (double)FUN_140332d90(((double)iVar23 - _DAT_14053b158) * DAT_14053a628 * dVar7 *
                                   dVar36);
    iVar22 = (int)(float)param_1[0xd];
    fVar34 = (float)(dVar27 * (double)(int)uVar19) + (float)param_1[0xc];
    param_1[10] = fVar34;
    if (iVar23 < 0) {
      iVar22 = 600;
    }
    else if (iVar23 < 0xb4) {
      dVar27 = (double)FUN_140332d90();
      iVar22 = (int)(dVar27 * (double)(iVar22 + -600)) + 600;
    }
    uStack_c4 = (undefined4)((ulonglong)uVar35 >> 0x20);
    uVar18 = 8;
    local_c8 = (undefined4)uVar35;
    fVar28 = (float)iVar22;
  }
  else {
    uVar18 = 7;
    fVar28 = (float)param_1[0xb] + DAT_140539ce4;
    fVar34 = (float)param_1[10];
    uVar55 = 0xff;
    uStack_c4 = 0xff;
    local_c8 = 0xff;
  }
  param_1[0xb] = fVar28;
  FUN_1400c8410(DAT_140e44910,0x1e,uVar18,fVar34,CONCAT44(uVar32,fVar28),
                in_stack_fffffffffffffef0 & 0xffff0000,dVar26,uVar8,local_c8,uStack_c4,uVar55,0xff,1
                ,0);
  uVar55 = DAT_140e41ab8;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46df0 = _DAT_140e46df0 + 1;
  bVar24 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar13 = uVar55;
  *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
  puVar13[1] = 0x58;
  *(undefined8 *)(puVar13 + 2) = 5;
  puVar13[4] = 0;
  *(undefined2 *)(puVar13 + 5) = 0;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = iVar16;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  if (bVar24) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  DAT_140e46c88 = puVar13;
  if (param_1[3] == 0xf0) {
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 0;
    param_1[3] = 0;
    DAT_140e41b0c = 85000;
    DAT_140e4430c = 0x708;
    DAT_140e4192c = 0;
    param_1[7] = 85000;
    DAT_140e419bc = 1;
  }
LAB_1400e4758:
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


