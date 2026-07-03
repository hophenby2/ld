// Function: FUN_14000d480 @ 14000d480
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000d480(undefined4 *param_1)

{
  ulonglong uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined1 auVar6 [16];
  double dVar7;
  longlong lVar8;
  double dVar9;
  int iVar10;
  undefined8 uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  short sVar17;
  short sVar18;
  int iVar19;
  undefined4 extraout_XMM0_Da;
  float fVar20;
  int local_res8;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar22;
  undefined4 uVar21;
  undefined4 in_stack_fffffffffffffe70;
  undefined4 uVar23;
  undefined4 uVar24;
  ushort uVar25;
  undefined1 in_stack_fffffffffffffe78 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  int iStack_134;
  int iStack_12c;
  undefined8 uStack_120;
  
  dVar2 = DAT_14053a020;
  uVar25 = (ushort)((uint)in_stack_fffffffffffffe70 >> 0x10);
  iStack_12c = 0;
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == DAT_140e44308) {
        iStack_134 = *(int *)(lVar8 + 0x14);
        iStack_12c = *(int *)(lVar8 + 0x1c);
        uStack_120 = *(undefined8 *)(lVar8 + 0x28);
      }
    }
  }
  iVar16 = param_1[3];
  dVar4 = (double)iVar16 - 0.0;
  dVar3 = (double)FUN_140332d90(SUB84(dVar4 * _DAT_14053aa60 * DAT_14053a020 * DAT_140539d28,0));
  dVar9 = DAT_140539f40;
  uStack_120._0_4_ = (float)uStack_120 + (float)param_1[0xc];
  dVar3 = dVar3 * _DAT_14053b050 + DAT_140539f40;
  fVar20 = (float)param_1[0xd];
  param_1[10] = (float)uStack_120;
  param_1[0xb] = uStack_120._4_4_ + fVar20;
  dVar7 = dVar9;
  dVar5 = dVar9;
  if (param_1[5] == 0) {
    if (iVar16 < 0) {
      dVar7 = 0.0;
      dVar5 = 0.0;
    }
    else if (iVar16 < 0x1e) {
      dVar4 = (double)FUN_140332d90(SUB84(dVar4 * DAT_14053a798 * dVar2 * DAT_140539d28,0));
      dVar7 = dVar4 + 0.0;
      dVar5 = 0.0;
    }
    if (iVar16 - 0x1eU < 0x14) {
      dVar5 = (double)FUN_140332d90(SUB84(((double)iVar16 - DAT_14053a2d8) * DAT_14053a890 * dVar2 *
                                          DAT_140539d28,0));
      dVar5 = dVar5 + 0.0;
    }
    if (iVar16 != 0x32) goto LAB_14000e025;
    param_1[3] = 0;
    param_1[5] = 1;
    iVar16 = 0;
  }
  else if (param_1[5] != 1) goto LAB_14000e025;
  fVar20 = (uStack_120._4_4_ + fVar20) - DAT_14053accc;
  dVar2 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar20),0),
                                SUB84((double)(DAT_140e445d8 - (float)uStack_120),0));
  iVar12 = DAT_140e419b8;
  uVar24 = DAT_14053ac2c;
  auVar26._0_8_ = in_stack_fffffffffffffe78._0_8_;
  if (param_1[6] != 0x22) goto LAB_14000e025;
  uVar14 = param_1[1] - DAT_1407c77a0;
  uVar15 = (iVar16 + -0x14) % 0x4b0;
  sVar18 = (short)(int)(dVar2 * DAT_14053aba0);
  if ((int)uVar15 < 0x277) {
    local_res8 = 1;
    if (DAT_140e419b8 == 0) {
      local_res8 = 0x18;
    }
    else if (DAT_140e419b8 == 1) {
LAB_14000d73f:
      local_res8 = 0x14;
    }
    else if (DAT_140e419b8 == 2) {
      local_res8 = 0x12;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) goto LAB_14000d73f;
    iVar16 = 1;
    if (DAT_140e419b8 == 0) {
      iVar16 = 6;
    }
    else if (DAT_140e419b8 == 1) {
      iVar16 = 8;
    }
    else if (DAT_140e419b8 == 2) {
      iVar16 = 10;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar16 = 0xc;
    }
    iVar19 = 1;
    if (DAT_140e419b8 == 0) {
      iVar19 = 2;
    }
    else if (DAT_140e419b8 == 1) {
      iVar19 = 4;
    }
    else if (DAT_140e419b8 == 2) {
      iVar19 = 5;
    }
    else if (DAT_140e419b8 == 3) {
      iVar19 = 6;
    }
    else if (DAT_140e419b8 == 4) {
      iVar19 = 7;
    }
    dVar2 = DAT_14053a040;
    if ((((DAT_140e419b8 != 0) && (dVar2 = DAT_14053a088, DAT_140e419b8 != 1)) &&
        (dVar2 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
       ((dVar2 = DAT_14053a0f8, DAT_140e419b8 != 3 && (dVar2 = dVar9, DAT_140e419b8 == 4)))) {
      dVar2 = DAT_14053a158;
    }
    sVar17 = 1;
    if (DAT_140e419b8 == 0) {
      sVar17 = 0x96;
    }
    else if (DAT_140e419b8 == 1) {
      sVar17 = 0xb4;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      sVar17 = 200;
    }
    iVar10 = 1;
    if (DAT_140e419b8 == 0) {
      iVar10 = 0x78;
    }
    else if (DAT_140e419b8 == 1) {
      iVar10 = 0x50;
    }
    else if (DAT_140e419b8 == 2) {
      iVar10 = 0x3c;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar10 = 0x30;
    }
    dVar4 = DAT_14053a0b0;
    if ((((DAT_140e419b8 != 0) && (dVar4 = DAT_14053a120, DAT_140e419b8 != 1)) &&
        (dVar4 = DAT_14053a178, DAT_140e419b8 != 2)) &&
       ((dVar4 = DAT_14053a1b8, DAT_140e419b8 != 3 && (dVar4 = dVar9, DAT_140e419b8 == 4)))) {
      dVar4 = DAT_14053a208;
    }
    if (uVar15 == 0) {
      *(short *)((longlong)param_1 + 0x42) =
           (short)(0x10000 / (ulonglong)(uint)(iVar19 * 4)) * (short)uVar14;
    }
    if ((uVar14 == 0) || (uVar14 == 3)) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar17;
    }
    if (uVar14 - 1 < 2) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar17;
    }
    auVar26._12_4_ = in_stack_fffffffffffffe78._12_4_;
    uVar22 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
    if ((int)uVar14 < 2) {
      uVar13 = uVar15 - 0x3c;
      if (uVar13 < 0xf0) {
        if ((int)uVar13 % iVar10 == 0) {
          *(short *)(param_1 + 0x11) = sVar18;
        }
        else if ((0xef < uVar13) || (0x17 < (int)uVar13 % iVar10)) goto LAB_14000da89;
        iVar10 = (int)uVar13 % iVar10;
        if (iVar10 == (iVar10 / 3 + (iVar10 >> 0x1f) +
                      (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3) {
          auVar26._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar26._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar4;
          in_stack_fffffffffffffe68 = CONCAT22(uVar22,*(undefined2 *)(param_1 + 0x11));
          uVar23 = uVar24;
          FUN_14006c2f0(0xc,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar4,
                        in_stack_fffffffffffffe78._8_8_,0);
          uVar25 = (ushort)((uint)uVar23 >> 0x10);
          if (2 < DAT_140e419b8) {
            sVar17 = *(short *)(param_1 + 0x11);
            iVar12 = 0;
            do {
              auVar27._12_4_ = in_stack_fffffffffffffe78._12_4_;
              auVar27._0_8_ = in_stack_fffffffffffffe78._0_8_;
              auVar27._8_4_ = 1;
              in_stack_fffffffffffffe78._8_8_ = auVar27._8_8_;
              in_stack_fffffffffffffe68 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                            (short)iVar12 * 0x640 + sVar17 + -800);
              uVar23 = uVar24;
              FUN_14006c2f0(0xc,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar4,
                            in_stack_fffffffffffffe78._8_8_,0);
              uVar25 = (ushort)((uint)uVar23 >> 0x10);
              iVar12 = iVar12 + 1;
            } while (iVar12 < 2);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar12 = DAT_140e419b8;
        }
      }
LAB_14000da89:
      if (((uVar15 - 0x14a < 300) &&
          (uVar1 = (longlong)(int)(uVar15 - 0x14a) % (longlong)(local_res8 + -2),
          (int)uVar1 < iVar16 + -2)) && ((uVar1 & 1) == 0)) {
        auVar28._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar28._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar28._8_4_ = 1;
        in_stack_fffffffffffffe78._8_8_ = auVar28._8_8_;
        in_stack_fffffffffffffe78._0_8_ = dVar2;
        in_stack_fffffffffffffe68 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                      *(undefined2 *)((longlong)param_1 + 0x42));
        uVar23 = uVar24;
        FUN_1400709b0(0xc,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar2,
                      in_stack_fffffffffffffe78._8_8_,iVar19,0x10000,0);
        uVar25 = (ushort)((uint)uVar23 >> 0x10);
        if (3 < DAT_140e419b8) {
          auVar29._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar29._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar29._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar29._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar2 + DAT_140539f28;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                        *(undefined2 *)((longlong)param_1 + 0x42));
          uVar23 = uVar24;
          FUN_1400709b0(0xc,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,
                        dVar2 + DAT_140539f28,in_stack_fffffffffffffe78._8_8_,iVar19,0x10000,0);
          uVar25 = (ushort)((uint)uVar23 >> 0x10);
        }
LAB_14000dd68:
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar12 = DAT_140e419b8;
      }
    }
    else {
      if (((uVar15 < 300) && ((int)((longlong)(int)uVar15 % (longlong)local_res8) < iVar16)) &&
         (((longlong)(int)uVar15 % (longlong)local_res8 & 1U) == 0)) {
        auVar30._8_4_ = 1;
        auVar30._0_8_ = auVar26._0_8_;
        auVar30._12_4_ = auVar26._12_4_;
        in_stack_fffffffffffffe78._8_8_ = auVar30._8_8_;
        in_stack_fffffffffffffe78._0_8_ = dVar2;
        in_stack_fffffffffffffe68 = CONCAT22(uVar22,*(undefined2 *)((longlong)param_1 + 0x42));
        uVar23 = uVar24;
        FUN_1400709b0(0xd,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar2,
                      in_stack_fffffffffffffe78._8_8_,iVar19,0x10000,0);
        uVar25 = (ushort)((uint)uVar23 >> 0x10);
        if (3 < DAT_140e419b8) {
          auVar31._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar31._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar31._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar31._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar2 + DAT_140539f28;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                        *(undefined2 *)((longlong)param_1 + 0x42));
          uVar23 = uVar24;
          FUN_1400709b0(0xd,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,
                        dVar2 + DAT_140539f28,in_stack_fffffffffffffe78._8_8_,iVar19,0x10000,0);
          uVar25 = (ushort)((uint)uVar23 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar12 = DAT_140e419b8;
      }
      uVar13 = uVar15 - 0x186;
      if (uVar13 < 0xf0) {
        if ((int)uVar13 % iVar10 == 0) {
          *(short *)(param_1 + 0x11) = sVar18;
        }
        else if ((0xef < uVar13) || (0x17 < (int)uVar13 % iVar10)) goto LAB_14000ddae;
        iVar10 = (int)uVar13 % iVar10;
        if (iVar10 == (iVar10 / 3 + (iVar10 >> 0x1f) +
                      (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3) {
          auVar32._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar32._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar32._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar32._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar4;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                        *(undefined2 *)(param_1 + 0x11));
          uVar23 = uVar24;
          FUN_14006c2f0(0xd,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar4,
                        in_stack_fffffffffffffe78._8_8_,0);
          uVar25 = (ushort)((uint)uVar23 >> 0x10);
          if (2 < DAT_140e419b8) {
            sVar17 = *(short *)(param_1 + 0x11);
            iVar16 = 0;
            do {
              auVar33._12_4_ = in_stack_fffffffffffffe78._12_4_;
              auVar33._0_8_ = in_stack_fffffffffffffe78._0_8_;
              auVar33._8_4_ = 1;
              in_stack_fffffffffffffe78._8_8_ = auVar33._8_8_;
              in_stack_fffffffffffffe68 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                            (short)iVar16 * 0x640 + sVar17 + -800);
              uVar23 = uVar24;
              FUN_14006c2f0(0xd,0,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,dVar4,
                            in_stack_fffffffffffffe78._8_8_,0);
              uVar25 = (ushort)((uint)uVar23 >> 0x10);
              iVar16 = iVar16 + 1;
            } while (iVar16 < 2);
          }
          goto LAB_14000dd68;
        }
      }
    }
  }
LAB_14000ddae:
  uVar11 = DAT_14053a138;
  if (500 < uVar15 - 0x28a) goto LAB_14000e025;
  iVar16 = 1;
  if (iVar12 == 0) {
    iVar16 = 0x5a;
  }
  else if (iVar12 == 1) {
    iVar16 = 0x3c;
  }
  else if ((iVar12 == 2) || (iVar12 == 3)) {
    iVar16 = 0x28;
  }
  else if (iVar12 == 4) {
    iVar16 = 0x24;
  }
  uVar13 = 1;
  if (iVar12 == 0) {
    uVar13 = 0xf;
  }
  else if (iVar12 == 1) {
    uVar13 = 0x17;
  }
  else if (iVar12 == 2) {
LAB_14000de14:
    uVar13 = 0x1b;
  }
  else if (iVar12 == 3) {
    uVar13 = 0x19;
  }
  else if (iVar12 == 4) goto LAB_14000de14;
  iVar12 = iVar16 * uVar14 + 0x28a;
  if ((((int)uVar15 < iVar12) || (0x47d < (int)uVar15)) ||
     ((int)(uVar15 - iVar12) % (iVar16 * 4) != 0)) goto LAB_14000e025;
  auVar35._12_4_ = in_stack_fffffffffffffe78._12_4_;
  auVar35._0_8_ = in_stack_fffffffffffffe78._0_8_;
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  if ((uVar14 & 1) == 0) {
    if (uVar13 == 1) {
      auVar35._8_4_ = 1;
      in_stack_fffffffffffffe78._8_8_ = auVar35._8_8_;
      in_stack_fffffffffffffe78._0_8_ = DAT_14053a138;
      uVar21 = CONCAT22(uVar22,sVar18);
      uVar23 = uVar24;
      FUN_14006c2f0(3,0x18,(float)uStack_120,fVar20,uVar21,uVar24,DAT_14053a138,
                    in_stack_fffffffffffffe78._8_8_,0);
      uVar22 = (undefined2)((uint)uVar21 >> 0x10);
      uVar25 = (ushort)((uint)uVar23 >> 0x10);
    }
    else {
      iVar16 = 0;
      do {
        auVar34._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar34._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar34._8_4_ = 1;
        in_stack_fffffffffffffe78._8_8_ = auVar34._8_8_;
        in_stack_fffffffffffffe78._0_8_ = uVar11;
        in_stack_fffffffffffffe68 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                      (short)(0x10000 / (ulonglong)uVar13) * (short)iVar16 + sVar18);
        uVar23 = uVar24;
        FUN_14006c2f0(3,0x18,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,uVar11,
                      in_stack_fffffffffffffe78._8_8_,0);
        uVar22 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
        uVar25 = (ushort)((uint)uVar23 >> 0x10);
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)uVar13);
    }
    uVar11 = DAT_14053a180;
    if (2 < DAT_140e419b8) {
      if (uVar13 == 1) {
        uVar11 = 0x18;
LAB_14000dfa0:
        auVar37._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar37._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar37._8_4_ = 1;
        FUN_14006c2f0(3,uVar11,(float)uStack_120,fVar20,CONCAT22(uVar22,sVar18),uVar24,DAT_14053a180
                      ,auVar37._8_8_,0);
        uVar25 = (ushort)((uint)uVar24 >> 0x10);
      }
      else {
        iVar16 = 0;
        do {
          auVar36._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar36._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar36._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar36._8_8_;
          in_stack_fffffffffffffe78._0_8_ = uVar11;
          uVar23 = uVar24;
          FUN_14006c2f0(3,0x18,(float)uStack_120,fVar20,
                        (short)(0x10000 / (ulonglong)uVar13) * (short)iVar16 + sVar18,uVar24,uVar11,
                        in_stack_fffffffffffffe78._8_8_,0);
          uVar25 = (ushort)((uint)uVar23 >> 0x10);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar13);
      }
    }
  }
  else {
    if (uVar13 == 1) {
      auVar41._8_4_ = 1;
      auVar41._0_8_ = auVar35._0_8_;
      auVar41._12_4_ = auVar35._12_4_;
      in_stack_fffffffffffffe78._8_8_ = auVar41._8_8_;
      in_stack_fffffffffffffe78._0_8_ = DAT_14053a138;
      uVar21 = CONCAT22(uVar22,sVar18);
      uVar23 = uVar24;
      FUN_14006c2f0(3,0x19,(float)uStack_120,fVar20,uVar21,uVar24,DAT_14053a138,
                    in_stack_fffffffffffffe78._8_8_,0);
      uVar22 = (undefined2)((uint)uVar21 >> 0x10);
      uVar25 = (ushort)((uint)uVar23 >> 0x10);
    }
    else {
      iVar16 = 0;
      do {
        auVar40._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar40._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar40._8_4_ = 1;
        in_stack_fffffffffffffe78._8_8_ = auVar40._8_8_;
        in_stack_fffffffffffffe78._0_8_ = uVar11;
        in_stack_fffffffffffffe68 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                      (short)(0x10000 / (ulonglong)uVar13) * (short)iVar16 + sVar18);
        uVar23 = uVar24;
        FUN_14006c2f0(3,0x19,(float)uStack_120,fVar20,in_stack_fffffffffffffe68,uVar24,uVar11,
                      in_stack_fffffffffffffe78._8_8_,0);
        uVar22 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
        uVar25 = (ushort)((uint)uVar23 >> 0x10);
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)uVar13);
    }
    uVar11 = DAT_14053a180;
    if (2 < DAT_140e419b8) {
      if (uVar13 == 1) {
        uVar11 = 0x19;
        goto LAB_14000dfa0;
      }
      iVar16 = 0;
      do {
        auVar42._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar42._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar42._8_4_ = 1;
        in_stack_fffffffffffffe78._8_8_ = auVar42._8_8_;
        in_stack_fffffffffffffe78._0_8_ = uVar11;
        uVar23 = uVar24;
        FUN_14006c2f0(3,0x19,(float)uStack_120,fVar20,
                      (short)(0x10000 / (ulonglong)uVar13) * (short)iVar16 + sVar18,uVar24,uVar11,
                      in_stack_fffffffffffffe78._8_8_,0);
        uVar25 = (ushort)((uint)uVar23 >> 0x10);
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)uVar13);
    }
  }
  FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
  FUN_14018a340(DAT_140e472a8,1,1);
LAB_14000e025:
  fVar20 = DAT_14053acbc;
  uVar14 = param_1[1] & 0x80000003;
  if ((int)uVar14 < 0) {
    uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
  }
  uVar15 = (uint)uVar25 << 0x10;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44b6c + (longlong)(int)uVar14 * 4),0x1e,0x17,param_1[10],
                (float)param_1[0xb] - DAT_14053acbc,uVar15,dVar3,dVar7,0,0,0,0x40,1,0);
  uVar14 = param_1[1] & 0x80000003;
  if ((int)uVar14 < 0) {
    uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
  }
  auVar38._8_8_ = dVar7;
  auVar38._0_8_ = dVar3;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44b6c + (longlong)(int)uVar14 * 4),0x23,0xb,param_1[10],
                (float)param_1[0xb] + fVar20,uVar15 & 0xffff0000,dVar3,dVar7,0xff,0xff,0xff,0xff,1,0
               );
  auVar39._4_12_ = auVar38._4_12_;
  auVar39._0_4_ = 0x16;
  uVar14 = 0;
  iVar16 = FUN_1400c9580((float)param_1[0xb] - DAT_14053accc,0,3,3,0x14,0x15,auVar39);
  auVar6._8_4_ = SUB84(dVar5,0);
  auVar6._0_8_ = dVar5;
  auVar6._12_4_ = (int)((ulonglong)dVar5 >> 0x20);
  FUN_1400c8410((&DAT_140e44660)[iVar16],0x23,7,param_1[10],extraout_XMM0_Da,uVar14 & 0xffff0000,
                auVar6,0xff,0xff,0xff,0xff,1,0);
  if ((iStack_134 == 3) && ((iStack_12c < 1 || (DAT_140e4430c < 1)))) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


