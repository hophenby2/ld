// Function: FUN_140033070 @ 140033070
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140033070(undefined4 *param_1)

{
  short *psVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined1 auVar7 [16];
  double dVar8;
  float fVar9;
  undefined1 auVar10 [16];
  short sVar11;
  undefined8 *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  undefined4 uVar16;
  int iVar17;
  longlong lVar18;
  int iVar19;
  undefined8 uVar20;
  longlong lVar21;
  int iVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  float fVar36;
  float fVar37;
  int local_res10;
  undefined2 local_res20;
  undefined4 in_stack_fffffffffffffe58;
  uint uVar38;
  undefined2 uVar39;
  float in_stack_fffffffffffffe60;
  ushort uVar40;
  undefined2 uVar41;
  undefined1 in_stack_fffffffffffffe68 [16];
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
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined8 uStack_150;
  int iStack_144;
  undefined8 uStack_130;
  
  uVar39 = (undefined2)((uint)in_stack_fffffffffffffe58 >> 0x10);
  uVar40 = (ushort)((uint)in_stack_fffffffffffffe60 >> 0x10);
  lVar18 = DAT_140e45d80;
  iVar14 = uStack_150._4_4_;
  if (0 < DAT_140e44e6c) {
    for (; iVar14 = (int)((ulonglong)uStack_150 >> 0x20), lVar18 != 0;
        lVar18 = *(longlong *)(lVar18 + 0x60)) {
      if (*(int *)(lVar18 + 4) == DAT_140e44308) {
        uStack_150 = *(undefined8 *)(lVar18 + 8);
        iStack_144 = *(int *)(lVar18 + 0x14);
        uStack_130 = *(undefined8 *)(lVar18 + 0x28);
      }
    }
  }
  uStack_150._4_4_ = iVar14;
  iVar14 = 0;
  if ((iStack_144 == 1) && (uStack_150._4_4_ == 1)) {
    param_1[0x15] = 0;
  }
  auVar10 = _DAT_14053bb20;
  dVar25 = DAT_140539e60;
  uVar4 = (undefined4)DAT_14053bb20;
  uVar5 = DAT_14053bb20._4_4_;
  dVar6 = (double)DAT_14053bb20;
  uVar34 = SUB84(DAT_140539e60,0);
  uVar35 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
  uVar31 = (undefined4)DAT_14053a0d0;
  uVar33 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  iVar13 = DAT_140e419b8;
  if (param_1[6] == 0x87) {
    dVar24 = dVar6;
    if (DAT_140e418c8 % 0x29 < 9) {
      dVar24 = (double)FUN_140332d90(((double)(DAT_140e418c8 % 0x29) - 0.0) * DAT_14053aad0 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar24 = dVar24 * dVar25 + dVar6;
    }
    fVar9 = DAT_14053ac2c;
    fVar37 = (float)param_1[0xb] + DAT_14053ac58;
    fVar27 = (float)param_1[10];
    fVar36 = fVar27 + DAT_14053ac2c;
    dVar25 = (double)FUN_1403300b4();
    fVar30 = (float)param_1[0xc];
    bVar2 = 0.0 <= fVar30;
    local_res20 = (undefined2)(int)(dVar25 * DAT_14053aba0);
    if (bVar2) {
      fVar36 = fVar27 - fVar9;
      dVar25 = (double)FUN_1403300b4();
      local_res20 = (undefined2)(int)(dVar25 * DAT_14053aba0);
    }
    fVar30 = (float)uStack_130 + fVar30;
    fVar27 = uStack_130._4_4_ + (float)param_1[0xd] + DAT_14053acb0;
    in_stack_fffffffffffffe60 = (float)((uint)uVar40 << 0x10);
    param_1[10] = fVar30;
    param_1[0xb] = uStack_130._4_4_ + (float)param_1[0xd];
    in_stack_fffffffffffffe68 = auVar10;
    FUN_1400c8410(DAT_140e44cf8,0x1b,7,fVar30,fVar27,in_stack_fffffffffffffe60,auVar10,0xff,0xff,
                  0xff,0xff,1,0);
    uVar39 = (undefined2)((uint)fVar27 >> 0x10);
    iVar13 = DAT_140e419b8;
    if (iStack_144 == 1) {
      uVar34 = (undefined4)DAT_14053a138;
      uVar35 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      uVar31 = (undefined4)DAT_14053a0b0;
      uVar33 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      if (param_1[5] == 0) {
        local_res10 = 0x6fe;
        if (!bVar2) {
          local_res10 = 0x672;
        }
        iVar19 = 0x2ee;
        if (!bVar2) {
          iVar19 = 0x14a;
        }
        if (((0x13 < uStack_150._4_4_) &&
            (iVar13 = (uStack_150._4_4_ + -0x14) % 0x52, iVar13 < 0x1e)) &&
           (iVar13 == (iVar13 / 5) * 5)) {
          uVar16 = uVar31;
          uVar32 = uVar33;
          if (DAT_140e419b8 != 0) {
            if (DAT_140e419b8 == 1) {
              uVar16 = (int)DAT_14053a0f8;
              uVar32 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
            }
            else {
              uVar16 = uVar34;
              uVar32 = uVar35;
              if (DAT_140e419b8 != 2) {
                if (DAT_140e419b8 == 3) {
                  uVar16 = (int)DAT_14053a178;
                  uVar32 = (int)((ulonglong)DAT_14053a178 >> 0x20);
                }
                else {
                  uVar16 = uVar4;
                  uVar32 = uVar5;
                  if (DAT_140e419b8 == 4) {
                    uVar16 = (int)DAT_14053a1c8;
                    uVar32 = (int)((ulonglong)DAT_14053a1c8 >> 0x20);
                  }
                }
              }
            }
          }
          if (bVar2) {
            do {
              auVar43._12_4_ = in_stack_fffffffffffffe68._12_4_;
              auVar43._0_8_ = in_stack_fffffffffffffe68._0_8_;
              auVar43._8_4_ = 1;
              in_stack_fffffffffffffe68._8_8_ = auVar43._8_8_;
              in_stack_fffffffffffffe68._0_8_ = CONCAT44(uVar32,uVar16);
              fVar27 = (float)CONCAT22((short)((uint)fVar27 >> 0x10),(short)iVar14 * 14000 + -14000)
              ;
              in_stack_fffffffffffffe60 = fVar9;
              FUN_14006c2f0(2,0,fVar36,fVar37,fVar27,fVar9,CONCAT44(uVar32,uVar16),
                            in_stack_fffffffffffffe68._8_8_,0);
              iVar14 = iVar14 + 1;
            } while (iVar14 < 3);
          }
          else {
            do {
              auVar42._12_4_ = in_stack_fffffffffffffe68._12_4_;
              auVar42._0_8_ = in_stack_fffffffffffffe68._0_8_;
              auVar42._8_4_ = 1;
              in_stack_fffffffffffffe68._8_8_ = auVar42._8_8_;
              in_stack_fffffffffffffe68._0_8_ = CONCAT44(uVar32,uVar16);
              fVar27 = (float)CONCAT22((short)((uint)fVar27 >> 0x10),(short)iVar14 * 14000 + 0x4950)
              ;
              in_stack_fffffffffffffe60 = fVar9;
              FUN_14006c2f0(2,0,fVar36,fVar37,fVar27,fVar9,CONCAT44(uVar32,uVar16),
                            in_stack_fffffffffffffe68._8_8_,0);
              iVar14 = iVar14 + 1;
            } while (iVar14 < 3);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      else {
        if (param_1[5] != 1) goto LAB_140033e1b;
        local_res10 = 0x6fe;
        if (!bVar2) {
          local_res10 = 0x672;
        }
        iVar19 = 0x2ee;
        if (!bVar2) {
          iVar19 = 0x14a;
        }
      }
      iVar13 = DAT_140e419b8;
      uVar39 = (undefined2)((uint)fVar27 >> 0x10);
      iVar14 = uStack_150._4_4_ % 0xa28;
      uVar16 = (undefined4)DAT_14053a070;
      uVar32 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
      if (iVar14 < 0x3a2) {
        iVar17 = 1;
        if (DAT_140e419b8 == 0) {
          iVar17 = 6;
        }
        else if (DAT_140e419b8 == 1) {
          iVar17 = 5;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar17 = 4;
        }
        iVar22 = 1;
        if (DAT_140e419b8 == 0) {
          iVar22 = 5;
        }
        else if (DAT_140e419b8 == 1) {
          iVar22 = 7;
        }
        else if (DAT_140e419b8 == 2) {
          iVar22 = 9;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar22 = 0xb;
        }
        sVar11 = 1;
        if (DAT_140e419b8 == 0) {
          sVar11 = 0x15f4;
        }
        else if (DAT_140e419b8 == 1) {
          sVar11 = 0x1270;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          sVar11 = 0xeec;
        }
        if (DAT_140e419b8 == 0) {
          uVar28 = (int)DAT_14053a030;
          uVar29 = (int)((ulonglong)DAT_14053a030 >> 0x20);
        }
        else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
          uVar28 = (int)DAT_14053a048;
          uVar29 = (int)((ulonglong)DAT_14053a048 >> 0x20);
        }
        else {
          uVar28 = uVar16;
          uVar29 = uVar32;
          if ((DAT_140e419b8 != 3) && (uVar28 = uVar4, uVar29 = uVar5, DAT_140e419b8 == 4)) {
            uVar28 = uVar31;
            uVar29 = uVar33;
          }
        }
        uVar20 = 3;
        dVar25 = ((double)iVar14 - (double)iVar19) * _DAT_140539dd8 +
                 (double)CONCAT44(uVar29,uVar28);
        if (param_1[5] == 1) {
          iVar22 = iVar22 + -3;
          sVar11 = 1;
          if (DAT_140e419b8 == 0) {
            sVar11 = 0x15b8;
          }
          else if (DAT_140e419b8 == 1) {
            sVar11 = 0x1234;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            sVar11 = 0xe88;
          }
          uVar20 = 5;
        }
        if (iVar14 == iVar19) {
          if (bVar2) {
            *(undefined2 *)((longlong)param_1 + 0x42) = 0xa000;
          }
          else {
            *(undefined2 *)((longlong)param_1 + 0x42) = 0xe000;
          }
LAB_1400337ae:
          dVar8 = DAT_140539f10;
          if ((iVar14 < iVar19 + 0x96) && ((iVar14 - iVar19) % iVar17 == 0)) {
            iVar13 = 0;
            if (0 < iVar22) {
              if (bVar2) {
                do {
                  auVar45._12_4_ = in_stack_fffffffffffffe68._12_4_;
                  auVar45._0_8_ = in_stack_fffffffffffffe68._0_8_;
                  auVar45._8_4_ = 1;
                  dVar26 = (double)iVar13 * dVar8 + dVar25;
                  in_stack_fffffffffffffe68._8_8_ = auVar45._8_8_;
                  in_stack_fffffffffffffe68._0_8_ = dVar26;
                  fVar27 = (float)CONCAT22((short)((uint)fVar27 >> 0x10),
                                           (short)iVar13 * sVar11 +
                                           *(short *)((longlong)param_1 + 0x42));
                  in_stack_fffffffffffffe60 = fVar9;
                  FUN_14006c2f0(uVar20,0,fVar36,fVar37,fVar27,fVar9,dVar26,
                                in_stack_fffffffffffffe68._8_8_,0);
                  uVar39 = (undefined2)((uint)fVar27 >> 0x10);
                  iVar13 = iVar13 + 1;
                } while (iVar13 < iVar22);
              }
              else {
                do {
                  auVar44._12_4_ = in_stack_fffffffffffffe68._12_4_;
                  auVar44._0_8_ = in_stack_fffffffffffffe68._0_8_;
                  auVar44._8_4_ = 1;
                  dVar26 = (double)iVar13 * dVar8 + dVar25;
                  in_stack_fffffffffffffe68._8_8_ = auVar44._8_8_;
                  in_stack_fffffffffffffe68._0_8_ = dVar26;
                  fVar27 = (float)CONCAT22((short)((uint)fVar27 >> 0x10),
                                           *(short *)((longlong)param_1 + 0x42) -
                                           (short)iVar13 * sVar11);
                  in_stack_fffffffffffffe60 = fVar9;
                  FUN_14006c2f0(uVar20,0,fVar36,fVar37,fVar27,fVar9,dVar26,
                                in_stack_fffffffffffffe68._8_8_,0);
                  uVar39 = (undefined2)((uint)fVar27 >> 0x10);
                  iVar13 = iVar13 + 1;
                } while (iVar13 < iVar22);
              }
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar13 = DAT_140e419b8;
          }
        }
        else if (iVar19 <= iVar14) goto LAB_1400337ae;
        if (bVar2) {
          sVar11 = -900;
        }
        else {
          sVar11 = 900;
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar11;
      }
      uVar31 = (undefined4)DAT_14053a0d0;
      uVar33 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      if (iVar14 - 0x3deU < 0x23a) {
        iVar19 = 1;
        if (iVar13 == 0) {
          iVar19 = 0x13;
        }
        else if (iVar13 == 1) {
          iVar19 = 0xd;
        }
        else if ((iVar13 == 2) || (iVar13 == 3)) {
          iVar19 = 0xb;
        }
        else if (iVar13 == 4) {
          iVar19 = 10;
        }
        uVar28 = 1;
        if (iVar13 == 0) {
          uVar28 = 3;
        }
        else if (iVar13 == 1) {
          uVar28 = 4;
        }
        else if ((iVar13 == 2) || (iVar13 == 3)) {
          uVar28 = 5;
        }
        else if (iVar13 == 4) {
          uVar28 = 6;
        }
        if (iVar13 == 0) {
          uVar16 = (undefined4)DAT_14053a040;
          uVar32 = (undefined4)((ulonglong)DAT_14053a040 >> 0x20);
        }
        else if (iVar13 != 1) {
          if ((iVar13 == 2) || (iVar13 == 3)) {
            uVar16 = (undefined4)DAT_14053a088;
            uVar32 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
          }
          else {
            uVar16 = uVar4;
            uVar32 = uVar5;
            if (iVar13 == 4) {
              uVar16 = uVar31;
              uVar32 = uVar33;
            }
          }
        }
        dVar25 = (double)CONCAT44(uVar32,uVar16);
        if (param_1[5] == 1) {
          iVar19 = iVar19 * 2;
          dVar25 = (double)CONCAT44(uVar32,uVar16) - dVar6;
        }
        psVar1 = (short *)((longlong)param_1 + 0x42);
        uVar16 = 1;
        if (param_1[5] != 1) {
          uVar16 = 5;
        }
        if (iVar14 == 0x41a) {
          *psVar1 = -0x4000;
LAB_140033a70:
          uVar3 = (longlong)(iVar14 + -0x41a) % (longlong)iVar19;
          if ((int)uVar3 == 0) {
            auVar46._12_4_ = in_stack_fffffffffffffe68._12_4_;
            auVar46._0_8_ = in_stack_fffffffffffffe68._0_8_;
            auVar46._8_4_ = 1;
            in_stack_fffffffffffffe68._8_8_ = auVar46._8_8_;
            in_stack_fffffffffffffe68._0_8_ = dVar25;
            in_stack_fffffffffffffe60 = 0.0;
            uVar32 = CONCAT22(uVar39,*psVar1);
            FUN_1400709b0(uVar16,uVar3 & 0xffffffff,fVar36,fVar37,uVar32,0,dVar25,
                          in_stack_fffffffffffffe68._8_8_,uVar28,0x10000,0);
            uVar39 = (undefined2)((uint)uVar32 >> 0x10);
            iVar13 = DAT_140e419b8;
            if (2 < DAT_140e419b8) {
              auVar47._12_4_ = in_stack_fffffffffffffe68._12_4_;
              auVar47._0_8_ = in_stack_fffffffffffffe68._0_8_;
              auVar47._8_4_ = 1;
              in_stack_fffffffffffffe68._8_8_ = auVar47._8_8_;
              in_stack_fffffffffffffe68._0_8_ = dVar25 + DAT_140539f28;
              in_stack_fffffffffffffe60 = 0.0;
              uVar32 = CONCAT22(uVar39,*psVar1);
              FUN_1400709b0(uVar16,0,fVar36,fVar37,uVar32,0,dVar25 + DAT_140539f28,
                            in_stack_fffffffffffffe68._8_8_,uVar28,0x10000,0);
              uVar39 = (undefined2)((uint)uVar32 >> 0x10);
              iVar13 = DAT_140e419b8;
            }
          }
        }
        else if (0x419 < iVar14) goto LAB_140033a70;
        if (bVar2) {
          *psVar1 = *psVar1 + -0xa0;
        }
        else {
          *psVar1 = *psVar1 + 0xa0;
        }
      }
      if (iVar14 - 0x672U < 0x10e) {
        iVar19 = 1;
        if (iVar13 == 0) {
          iVar19 = 0x28;
        }
        else if (iVar13 == 1) {
          iVar19 = 0x1e;
        }
        else if (iVar13 == 2) {
LAB_140033bab:
          iVar19 = 0x18;
        }
        else if (iVar13 == 3) {
          iVar19 = 0x14;
        }
        else if (iVar13 == 4) goto LAB_140033bab;
        iVar17 = 1;
        if (iVar13 == 0) {
          iVar17 = 7;
        }
        else if (((iVar13 == 1) || (iVar13 == 2)) || (iVar13 == 3)) {
          iVar17 = 9;
        }
        else if (iVar13 == 4) {
          iVar17 = 0xb;
        }
        if (iVar13 != 0) {
          if (iVar13 == 1) {
            uVar31 = (int)DAT_14053a108;
            uVar33 = (int)((ulonglong)DAT_14053a108 >> 0x20);
          }
          else {
            uVar31 = uVar34;
            uVar33 = uVar35;
            if (iVar13 != 2) {
              if (iVar13 == 3) {
                uVar31 = (int)DAT_14053a158;
                uVar33 = (int)((ulonglong)DAT_14053a158 >> 0x20);
              }
              else {
                uVar31 = uVar4;
                uVar33 = uVar5;
                if (iVar13 == 4) {
                  uVar31 = (int)DAT_14053a190;
                  uVar33 = (int)((ulonglong)DAT_14053a190 >> 0x20);
                }
              }
            }
          }
        }
        dVar25 = (double)CONCAT44(uVar33,uVar31);
        if (param_1[5] == 1) {
          iVar17 = iVar17 + -4;
          dVar25 = (double)CONCAT44(uVar33,uVar31) - dVar6;
        }
        uVar20 = 5;
        if (param_1[5] != 1) {
          uVar20 = 3;
        }
        if (iVar14 == local_res10) {
          *(undefined2 *)((longlong)param_1 + 0x42) = local_res20;
LAB_140033c72:
          if ((iVar14 < local_res10 + 0x78) &&
             (uVar3 = (longlong)(iVar14 - local_res10) % (longlong)(iVar19 * 2), (int)uVar3 == 0)) {
            auVar48._12_4_ = in_stack_fffffffffffffe68._12_4_;
            auVar48._0_8_ = in_stack_fffffffffffffe68._0_8_;
            auVar48._8_4_ = 1;
            in_stack_fffffffffffffe68._8_8_ = auVar48._8_8_;
            in_stack_fffffffffffffe68._0_8_ = dVar25;
            in_stack_fffffffffffffe60 = 0.0;
            uVar31 = CONCAT22(uVar39,*(undefined2 *)((longlong)param_1 + 0x42));
            FUN_1400709b0(uVar20,uVar3 & 0xffffffff,fVar36,fVar37,uVar31,0,dVar25,
                          in_stack_fffffffffffffe68._8_8_,iVar17,iVar17 * 0x294 + -0x294,0);
            uVar39 = (undefined2)((uint)uVar31 >> 0x10);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar13 = DAT_140e419b8;
          }
        }
        else if (local_res10 <= iVar14) goto LAB_140033c72;
        if (((iVar19 + local_res10 <= iVar14) && (iVar14 < local_res10 + 0x78)) &&
           (uVar3 = (longlong)(iVar14 - (iVar19 + local_res10)) % (longlong)(iVar19 * 2),
           (int)uVar3 == 0)) {
          iVar14 = iVar17 * 0x294 + -0x294;
          auVar49._12_4_ = in_stack_fffffffffffffe68._12_4_;
          auVar49._0_8_ = in_stack_fffffffffffffe68._0_8_;
          auVar49._8_4_ = 1;
          auVar50._8_8_ = auVar49._8_8_;
          auVar50._0_8_ = dVar25;
          uVar31 = CONCAT22(uVar39,*(short *)((longlong)param_1 + 0x42) + 0x157c);
          FUN_1400709b0(uVar20,uVar3 & 0xffffffff,fVar36,fVar37,uVar31,0,dVar25,auVar50._8_8_,iVar17
                        ,iVar14,0);
          auVar51._12_4_ = auVar50._12_4_;
          auVar51._0_8_ = auVar50._0_8_;
          auVar51._8_4_ = 1;
          in_stack_fffffffffffffe68._8_8_ = auVar51._8_8_;
          in_stack_fffffffffffffe68._0_8_ = dVar25;
          in_stack_fffffffffffffe60 = 0.0;
          uVar31 = CONCAT22((short)((uint)uVar31 >> 0x10),
                            *(short *)((longlong)param_1 + 0x42) + -0x157c);
          FUN_1400709b0(uVar20,0,fVar36,fVar37,uVar31,0,dVar25,in_stack_fffffffffffffe68._8_8_,
                        iVar17,iVar14,0);
          uVar39 = (undefined2)((uint)uVar31 >> 0x10);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar13 = DAT_140e419b8;
        }
      }
    }
LAB_140033e1b:
    iVar14 = param_1[5];
    if (iVar14 == 0) {
      uVar31 = param_1[0xb];
      in_stack_fffffffffffffe68._8_4_ = SUB84(dVar24,0);
      in_stack_fffffffffffffe68._0_8_ = dVar24;
      in_stack_fffffffffffffe68._12_4_ = (int)((ulonglong)dVar24 >> 0x20);
      in_stack_fffffffffffffe60 = (float)((uint)in_stack_fffffffffffffe60 & 0xffff0000);
      FUN_1400c8410(DAT_140e44cfc,0x1b,7,param_1[10],uVar31,in_stack_fffffffffffffe60,
                    in_stack_fffffffffffffe68,0xff,0xff,0xff,0xff,1,bVar2);
      uVar33 = DAT_140e41a50;
      uVar39 = (undefined2)((uint)uVar31 >> 0x10);
      puVar12 = DAT_140e45d28;
      if (DAT_140e418c8 == (DAT_140e418c8 / 0x29) * 0x29) {
        uVar31 = param_1[1];
        fVar27 = (float)param_1[0xb];
        fVar30 = (float)param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar12 = (undefined8 *)_malloc_base(0x60);
          if (puVar12 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)((longlong)puVar12 + 0x14) = fVar36 - fVar30;
          *(float *)(puVar12 + 3) = fVar37 - fVar27;
          *(float *)((longlong)puVar12 + 0x1c) = fVar36 - fVar30;
          *(float *)(puVar12 + 4) = fVar37 - fVar27;
          *puVar12 = 1;
          *(undefined4 *)(puVar12 + 1) = 0x25;
          *(undefined4 *)((longlong)puVar12 + 0xc) = uVar33;
          *(undefined4 *)(puVar12 + 2) = 0x1e;
          *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
          puVar12[5] = 0;
          puVar12[6] = 0x3ff0000000000000;
          puVar12[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar12 + 8) = 0x10;
          *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
          *(undefined4 *)(puVar12 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
          *(undefined4 *)(puVar12 + 10) = 0x80;
          *(undefined4 *)((longlong)puVar12 + 0x54) = uVar31;
          puVar12[0xb] = 0;
          if (bVar23) {
            DAT_140e45d78 = puVar12;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar12;
          }
        }
      }
      DAT_140e45d28 = puVar12;
      if (param_1[0x15] == 0) {
        uVar31 = DAT_14053b360;
        FUN_140079c10(param_1,1);
        uVar39 = (undefined2)((uint)uVar31 >> 0x10);
      }
      uVar41 = (undefined2)((uint)in_stack_fffffffffffffe60 >> 0x10);
      if ((int)param_1[7] < 1) {
        FUN_14007b010(param_1,0xf3c,10);
        FUN_140079e20(param_1,2);
        auVar52._12_4_ = in_stack_fffffffffffffe68._12_4_;
        auVar52._0_8_ = in_stack_fffffffffffffe68._0_8_;
        auVar52._8_4_ = 10;
        auVar53._8_8_ = auVar52._8_8_;
        auVar53._0_8_ = dVar6;
        fVar27 = DAT_14053b380;
        stage_entity_spawn_candidate
                  (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar41,0x4000),dVar6,
                   auVar53._8_8_,1,DAT_140e44308);
        iVar14 = DAT_140e44308;
        lVar18 = DAT_140e45d80;
        if (0 < DAT_140e44e6c) {
          for (; lVar18 != 0; lVar18 = *(longlong *)(lVar18 + 0x60)) {
            if (*(int *)(lVar18 + 4) == iVar14) {
              *(int *)(lVar18 + 0x5c) = *(int *)(lVar18 + 0x5c) + -1;
            }
          }
        }
        auVar7._12_4_ = 0;
        auVar7._0_12_ = auVar53._4_12_;
        in_stack_fffffffffffffe68 = auVar7 << 0x20;
        in_stack_fffffffffffffe60 = 0.0;
        uVar38 = (uint)fVar27 & 0xffff0000;
        FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar38,0,in_stack_fffffffffffffe68);
        uVar39 = (undefined2)(uVar38 >> 0x10);
        iVar14 = param_1[5] + 1;
        param_1[0x15] = 1;
        param_1[5] = iVar14;
      }
      else {
        iVar14 = param_1[5];
      }
      piVar15 = param_1 + 5;
      iVar13 = DAT_140e419b8;
      if (9 < iStack_144) {
        FUN_140079e20(param_1,2);
        *piVar15 = *piVar15 + 1;
        iVar14 = *piVar15;
        param_1[0x15] = 1;
        iVar13 = DAT_140e419b8;
      }
    }
    if (iVar14 == 1) {
      uVar31 = param_1[0xb];
      in_stack_fffffffffffffe60 = (float)((uint)in_stack_fffffffffffffe60 & 0xffff0000);
      in_stack_fffffffffffffe68 = auVar10;
      FUN_1400c8410(DAT_140e44d00,0x1b,7,param_1[10],uVar31,in_stack_fffffffffffffe60,auVar10,0xff,
                    0xff,0xff,0xff,1,bVar2);
      uVar39 = (undefined2)((uint)uVar31 >> 0x10);
      iVar13 = DAT_140e419b8;
    }
    uVar31 = (undefined4)DAT_14053a0d0;
    uVar33 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    uVar34 = SUB84(DAT_140539e60,0);
    uVar35 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
  }
  if (param_1[6] != 0x88) goto LAB_1400345d3;
  dVar25 = dVar6;
  if (DAT_140e418c8 % 0x29 < 9) {
    dVar25 = (double)FUN_140332d90(((double)(DAT_140e418c8 % 0x29) - 0.0) * DAT_14053aad0 *
                                   DAT_14053a020 * DAT_140539d28);
    dVar25 = dVar25 * (double)CONCAT44(uVar35,uVar34) + dVar6;
  }
  fVar30 = DAT_14053b380;
  fVar27 = (float)param_1[0xc];
  uVar34 = 0;
  if (fVar27 < DAT_14053ad1c) {
    lVar18 = 0x6d;
    lVar21 = 0x6d;
    uVar35 = 0;
    if (fVar27 < DAT_14053b380) goto LAB_140034233;
  }
  else {
    uVar35 = 1;
LAB_140034233:
    uVar34 = uVar35;
    lVar18 = 0x6f;
    lVar21 = 0x6f;
  }
  iVar14 = param_1[5];
  uStack_130._0_4_ = (float)uStack_130 + fVar27;
  param_1[0xb] = uStack_130._4_4_ + (float)param_1[0xd];
  param_1[10] = (float)uStack_130;
  if (iVar14 == 0) {
    if (iStack_144 == 1) {
      dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc -
                                             (uStack_130._4_4_ + (float)param_1[0xd])),
                                     SUB84((double)(DAT_140e445d8 - (float)uStack_130),0));
      if (iVar13 == 0) {
        iVar14 = 0xa4;
      }
      else if (iVar13 == 1) {
        iVar14 = 0x7b;
      }
      else if (((iVar13 == 2) || (iVar13 == 3)) || (iVar14 = 1, iVar13 == 4)) {
        iVar14 = 0x51;
      }
      if (iVar13 == 0) {
        uVar31 = (undefined4)DAT_14053a088;
        uVar33 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
      }
      else if (iVar13 == 1) {
        uVar31 = (undefined4)DAT_14053a0b0;
        uVar33 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      }
      else if (((iVar13 != 2) && (iVar13 != 3)) && (uVar31 = uVar4, uVar33 = uVar5, iVar13 == 4)) {
        uVar31 = (undefined4)DAT_14053a138;
        uVar33 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      if (0x28 < uStack_150._4_4_) {
        if ((uStack_150._4_4_ + -0x29) % iVar14 == 0) {
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar24 * DAT_14053aba0) + 0x400;
        }
        if (((0x28 < uStack_150._4_4_) && (iVar14 = (uStack_150._4_4_ + -0x29) % iVar14, iVar14 < 9)
            ) && (iVar14 == (iVar14 / 3 + (iVar14 >> 0x1f) +
                            (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU)
                                 >> 0x1f)) * 3)) {
          uVar41 = *(undefined2 *)((longlong)param_1 + 0x42);
          auVar54._12_4_ = in_stack_fffffffffffffe68._12_4_;
          auVar54._0_8_ = in_stack_fffffffffffffe68._0_8_;
          auVar54._8_4_ = 1;
          auVar55._8_8_ = auVar54._8_8_;
          auVar55._0_8_ = CONCAT44(uVar33,uVar31);
          in_stack_fffffffffffffe60 = 0.0;
          uVar38 = CONCAT22(uVar39,uVar41) & 0xfffff800;
          FUN_14006c2f0(0xf,0,(float)uStack_130,param_1[0xb],uVar38,0,CONCAT44(uVar33,uVar31),
                        auVar55._8_8_,0);
          if (2 < DAT_140e419b8) {
            auVar56._12_4_ = auVar55._12_4_;
            auVar56._0_8_ = auVar55._0_8_;
            auVar56._8_4_ = 1;
            in_stack_fffffffffffffe60 = 0.0;
            FUN_14006c2f0(0xf,0,param_1[10],param_1[0xb],
                          CONCAT22((short)(uVar38 >> 0x10),uVar41) & 0xfffff800,0,
                          (double)CONCAT44(uVar33,uVar31) + DAT_140539f68,auVar56._8_8_,0);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
    auVar57._8_8_ = dVar25;
    auVar57._0_8_ = dVar25;
    in_stack_fffffffffffffe60 = (float)((uint)in_stack_fffffffffffffe60 & 0xffff0000);
    FUN_1400c8410((&DAT_140e44660)[lVar21],0x1b,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe60
                  ,dVar25,dVar25,0xff,0xff,0xff,0xff,1,uVar34);
    if (param_1[0x15] == 0) {
      FUN_140079c10(param_1,2);
    }
    uVar39 = (undefined2)((uint)in_stack_fffffffffffffe60 >> 0x10);
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,0xf3c,5);
      FUN_140079e20(param_1,1);
      auVar58._12_4_ = auVar57._12_4_;
      auVar58._0_8_ = auVar57._0_8_;
      auVar58._8_4_ = 10;
      in_stack_fffffffffffffe60 = (float)CONCAT22(uVar39,0x4000);
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,fVar30,fVar30,in_stack_fffffffffffffe60,dVar6,auVar58._8_8_,1,
                 DAT_140e44308);
      iVar14 = DAT_140e44308;
      lVar21 = DAT_140e45d80;
      if (0 < DAT_140e44e6c) {
        for (; lVar21 != 0; lVar21 = *(longlong *)(lVar21 + 0x60)) {
          if (*(int *)(lVar21 + 4) == iVar14) {
            *(int *)(lVar21 + 0x5c) = *(int *)(lVar21 + 0x5c) + -1;
          }
        }
      }
      iVar14 = param_1[5] + 1;
      param_1[0x15] = 1;
      param_1[5] = iVar14;
    }
    else {
      iVar14 = param_1[5];
    }
    if (iStack_144 == 10) {
      FUN_140079e20(param_1,1);
      iVar14 = param_1[5] + 1;
      param_1[0x15] = 1;
      param_1[5] = iVar14;
    }
  }
  if (iVar14 == 1) {
    FUN_1400c8410((&DAT_140e44664)[lVar18],0x1b,7,param_1[10],param_1[0xb],
                  (uint)in_stack_fffffffffffffe60 & 0xffff0000,auVar10,0xff,0xff,0xff,0xff,1,uVar34)
    ;
  }
LAB_1400345d3:
  if (((iStack_144 == 10) && (param_1[0x15] = 1, uStack_150._4_4_ == 100)) || (10 < iStack_144)) {
    *param_1 = 0;
  }
  return;
}


