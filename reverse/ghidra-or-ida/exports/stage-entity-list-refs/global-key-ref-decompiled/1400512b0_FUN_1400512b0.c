// Function: FUN_1400512b0 @ 1400512b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400512b0(undefined4 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  double dVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  longlong lVar8;
  short sVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  undefined4 uVar26;
  float fVar27;
  undefined4 uVar28;
  float fVar29;
  int iVar30;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar31;
  undefined4 in_stack_fffffffffffffe70;
  undefined4 uVar32;
  undefined2 uVar33;
  undefined1 in_stack_fffffffffffffe78 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
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
  float fStack_120;
  float fStack_11c;
  undefined4 local_118;
  undefined4 local_108;
  
  uVar33 = (undefined2)((uint)in_stack_fffffffffffffe70 >> 0x10);
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == 0)) {
    iVar30 = 0;
  }
  else {
    iVar30 = 0;
    lVar8 = DAT_140e45d80;
    do {
      if (*(int *)(lVar8 + 4) == DAT_140e44308) {
        iVar30 = *(int *)(lVar8 + 0x1c);
        fStack_120 = *(float *)(lVar8 + 0x28);
        fStack_11c = *(float *)(lVar8 + 0x2c);
        local_118 = *(undefined4 *)(lVar8 + 0x30);
        local_108 = *(undefined4 *)(lVar8 + 0x40);
      }
      lVar8 = *(longlong *)(lVar8 + 0x60);
      param_3 = local_108;
      param_4 = local_118;
    } while (lVar8 != 0);
  }
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]),param_3,param_4);
  fVar27 = (float)param_1[0xd];
  fVar29 = (float)param_1[0xc];
  uVar19 = (uint)(dVar20 * DAT_14053aba0);
  dVar21 = (double)FUN_1403300b4((double)(fVar27 - 0.0),(double)(fVar29 - 0.0));
  dVar23 = DAT_14053a020;
  dVar4 = DAT_140539f40;
  dVar21 = dVar21 * DAT_14053aba0;
  param_1[10] = fVar29 + fStack_120;
  dVar25 = DAT_14053a890;
  param_1[0xb] = fVar27 + fStack_11c;
  dVar22 = DAT_140539d28;
  uVar26 = SUB84(DAT_140539d28,0);
  uVar28 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  uVar5 = (ushort)uVar19;
  dVar20 = dVar4;
  if (param_1[5] == 0) {
    iVar14 = param_1[3];
    if (iVar14 < 0) {
      dVar20 = 0.0;
    }
    else if (iVar14 < 0x14) {
      dVar20 = (double)FUN_140332d90(((double)iVar14 - 0.0) * dVar25 * dVar23 * DAT_140539d28);
      dVar20 = dVar20 + 0.0;
    }
    if ((param_1[6] - 0xce < 0xb) && ((0x4e1U >> (param_1[6] - 0xce & 0x1f) & 1) != 0)) {
      uVar10 = *(ushort *)(param_1 + 0x10);
      uVar6 = uVar5 - uVar10;
      uVar7 = (uint)uVar6;
      if (0x8000 < uVar6) {
        uVar7 = 0x10000 - uVar6;
      }
      iVar11 = (uVar19 & 0xffff) - (uint)uVar10;
      iVar16 = (int)uVar7 / 5 + 0x40;
      iVar14 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar14 = iVar11;
      }
      iVar11 = iVar14 + -0x10000;
      if (iVar14 < 0x8001) {
        iVar11 = iVar14;
      }
      if (iVar11 < 1) {
        uVar6 = uVar10;
        if ((iVar11 < 0) && (uVar6 = uVar10 - (short)iVar16, -iVar16 < iVar11)) {
          uVar6 = uVar5;
        }
      }
      else {
        uVar6 = uVar5;
        if (iVar16 <= iVar11) {
          uVar6 = uVar10 + (short)iVar16;
        }
      }
    }
    else {
      sVar9 = 0;
      if ((-1 < iVar14) && (sVar9 = 0, iVar14 < 0x14)) {
        dVar22 = (double)FUN_140332d90(((double)iVar14 - 0.0) * dVar25 * dVar23 * dVar22);
        sVar9 = (short)(int)(dVar22 * DAT_14053ac08);
      }
      uVar6 = sVar9 + *(short *)((longlong)param_1 + 0x42);
    }
    *(ushort *)(param_1 + 0x10) = uVar6;
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140052502;
  uVar31 = *(undefined2 *)(param_1 + 0x10);
  dVar22 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar22 * DAT_14053a1e8) + (float)param_1[10];
  dVar23 = (double)FUN_140332d90();
  uVar26 = DAT_14053ac2c;
  dVar22 = DAT_14053a0f8;
  iVar14 = param_1[6];
  iVar11 = 0x32;
  fVar29 = (float)(dVar23 * DAT_14053a1e8) + (float)param_1[0xb];
  if ((iVar14 == 0xce) || (iVar14 == 0xd9)) {
    dVar23 = DAT_14053a0f8;
    if (((DAT_140e419b8 != 0) &&
        (((dVar23 = DAT_14053a138, DAT_140e419b8 != 1 &&
          (dVar23 = DAT_14053a178, DAT_140e419b8 != 2)) &&
         (dVar23 = DAT_14053a1b8, DAT_140e419b8 != 3)))) && (dVar23 = dVar4, DAT_140e419b8 == 4)) {
      dVar23 = DAT_14053a208;
    }
    iVar16 = param_1[3];
    iVar11 = 0x24;
    if (iVar14 != 0xd9) {
      iVar11 = 0x32;
    }
    dVar23 = (double)iVar16 * DAT_140539e60 + dVar23;
    if ((9 < iVar16) && (iVar16 < iVar11)) {
      uVar7 = iVar16 - 10U & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        auVar34._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar34._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar34._8_4_ = 1;
        in_stack_fffffffffffffe78._8_8_ = auVar34._8_8_;
        in_stack_fffffffffffffe78._0_8_ = dVar23;
        in_stack_fffffffffffffe68 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),uVar31);
        FUN_14006c2f0(10,0,fVar27,fVar29,in_stack_fffffffffffffe68,DAT_14053ac2c,dVar23,
                      in_stack_fffffffffffffe78._8_8_,0);
        sVar9 = *(short *)(param_1 + 0x10);
        dVar25 = dVar23 - DAT_140539f00;
        iVar14 = 0;
        do {
          auVar35._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar35._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar35._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar35._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar25;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                        (short)iVar14 * 0x4b0 + sVar9 + -600);
          uVar28 = uVar26;
          FUN_14006c2f0(10,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                        in_stack_fffffffffffffe78._8_8_,0);
          uVar33 = (undefined2)((uint)uVar28 >> 0x10);
          iVar14 = iVar14 + 1;
        } while (iVar14 < 2);
        sVar9 = *(short *)(param_1 + 0x10);
        if (2 < DAT_140e419b8) {
          iVar14 = 0;
          dVar25 = dVar23 - DAT_140539f68;
          do {
            auVar36._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar36._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar36._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar36._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar25;
            in_stack_fffffffffffffe68 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                          (short)iVar14 * 2000 + sVar9 + -1000);
            uVar28 = uVar26;
            FUN_14006c2f0(10,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                          in_stack_fffffffffffffe78._8_8_,0);
            uVar33 = (undefined2)((uint)uVar28 >> 0x10);
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
          sVar9 = *(short *)(param_1 + 0x10);
        }
        if (param_1[6] == 0xce) {
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          sVar9 = *(short *)(param_1 + 0x10);
        }
        if (param_1[6] == 0xd9) {
          iVar14 = 0;
          do {
            auVar37._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar37._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar37._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar37._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar23;
            in_stack_fffffffffffffe68 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                          (short)iVar14 * 0x5555 + sVar9 + 0x5556);
            uVar28 = uVar26;
            FUN_14006c2f0(0xb,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar23,
                          in_stack_fffffffffffffe78._8_8_,0);
            uVar33 = (undefined2)((uint)uVar28 >> 0x10);
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
          FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
  }
  dVar23 = DAT_14053a0b0;
  iVar14 = param_1[6];
  if ((iVar14 == 0xcf) || (iVar14 == 0xd0)) {
    iVar14 = 1;
    if (DAT_140e419b8 == 0) {
      iVar14 = 0xb;
    }
    else if (DAT_140e419b8 == 1) {
LAB_140051951:
      iVar14 = 7;
    }
    else {
      if (DAT_140e419b8 != 2) {
        if (DAT_140e419b8 == 3) goto LAB_140051951;
        if (DAT_140e419b8 != 4) goto LAB_14005195f;
      }
      iVar14 = 6;
    }
LAB_14005195f:
    uVar28 = 1;
    if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) && (DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
      uVar28 = 2;
    }
    dVar25 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar25 = dVar22, DAT_140e419b8 != 1)) &&
       ((dVar25 = DAT_14053a118, DAT_140e419b8 != 2 &&
        ((dVar25 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar25 = dVar4, DAT_140e419b8 == 4)))))) {
      dVar25 = DAT_14053a190;
    }
    iVar11 = 0xf0;
    iVar16 = 0xf0;
    if ((param_1[3] - 10 < 0xe6) &&
       (uVar2 = (longlong)(param_1[3] + -10) % (longlong)iVar14, (int)uVar2 == 0)) {
      auVar38._12_4_ = in_stack_fffffffffffffe78._12_4_;
      auVar38._0_8_ = in_stack_fffffffffffffe78._0_8_;
      auVar38._8_4_ = 1;
      in_stack_fffffffffffffe78._8_8_ = auVar38._8_8_;
      in_stack_fffffffffffffe78._0_8_ = dVar25;
      in_stack_fffffffffffffe68 =
           CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),*(undefined2 *)(param_1 + 0x10)
                   );
      uVar32 = uVar26;
      FUN_1400709b0(0xd,uVar2 & 0xffffffff,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                    in_stack_fffffffffffffe78._8_8_,uVar28,0x8ae,0);
      uVar33 = (undefined2)((uint)uVar32 >> 0x10);
      FUN_140184700(DAT_140e44190 * 9,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    iVar17 = DAT_140e419b8;
    iVar14 = param_1[6];
    if (iVar14 == 0xcf) {
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + 0xde;
    }
    else {
      if (iVar14 != 0xd0) goto LAB_140051a7f;
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + -0xde;
    }
  }
  else {
LAB_140051a7f:
    if ((iVar14 == 0xd1) || (iVar14 == 0xd2)) {
      sVar9 = 1;
      if (DAT_140e419b8 == 0) {
        sVar9 = 100;
      }
      else if (DAT_140e419b8 == 1) {
        sVar9 = 0x6e;
      }
      else if (DAT_140e419b8 == 2) {
        sVar9 = 0x78;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        sVar9 = 0x80;
      }
      iVar14 = param_1[3];
      iVar16 = 0x5a;
      if ((iVar14 - 10U < 0x50) && (iVar14 + -10 == ((iVar14 + -10) / 5) * 5)) {
        iVar11 = 0;
        sVar1 = *(short *)(param_1 + 0x10);
        dVar25 = (double)iVar14 * DAT_140539de8 + dVar22;
        if (DAT_140e445dc < (float)param_1[0xb] || DAT_140e445dc == (float)param_1[0xb]) {
          do {
            auVar40._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar40._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar40._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar40._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar25;
            in_stack_fffffffffffffe68 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                          (short)iVar11 * 0x2000 + sVar1 + 0x7000);
            uVar28 = uVar26;
            FUN_14006c2f0(3,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                          in_stack_fffffffffffffe78._8_8_,0);
            uVar33 = (undefined2)((uint)uVar28 >> 0x10);
            iVar11 = iVar11 + 1;
          } while (iVar11 < 2);
        }
        else {
          do {
            auVar39._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar39._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar39._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar39._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar25;
            in_stack_fffffffffffffe68 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                          (short)iVar11 * 0x2000 + sVar1 + -0x1000);
            uVar28 = uVar26;
            FUN_14006c2f0(3,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                          in_stack_fffffffffffffe78._8_8_,0);
            uVar33 = (undefined2)((uint)uVar28 >> 0x10);
            iVar11 = iVar11 + 1;
          } while (iVar11 < 2);
        }
        FUN_140184700(DAT_140e44190 * 9,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      iVar17 = DAT_140e419b8;
      iVar14 = param_1[6];
      if (iVar14 == 0xd1) {
        *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar9;
      }
      else {
        iVar11 = 0x5a;
        if (iVar14 != 0xd2) goto LAB_140051c2e;
        *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) - sVar9;
      }
    }
    else {
LAB_140051c2e:
      iVar16 = iVar11;
      iVar17 = DAT_140e419b8;
      if (iVar14 == 0xd3) {
        iVar14 = 1;
        if (DAT_140e419b8 == 0) {
          iVar14 = 0x28;
        }
        else if (DAT_140e419b8 == 1) {
          iVar14 = 0x1e;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar14 = 0x18;
        }
        else if (DAT_140e419b8 == 4) {
          iVar14 = 0x14;
        }
        iVar11 = 1;
        if (DAT_140e419b8 == 0) {
          iVar11 = 5;
        }
        else if (DAT_140e419b8 == 1) {
LAB_140051c99:
          iVar11 = 7;
        }
        else {
          if (DAT_140e419b8 != 2) {
            if (DAT_140e419b8 == 3) goto LAB_140051c99;
            if (DAT_140e419b8 != 4) goto LAB_140051ca5;
          }
          iVar11 = 9;
        }
LAB_140051ca5:
        dVar25 = dVar23;
        if ((((DAT_140e419b8 != 0) && (dVar25 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
            (dVar25 = dVar22, DAT_140e419b8 != 2)) &&
           ((DAT_140e419b8 != 3 && (dVar25 = dVar4, DAT_140e419b8 == 4)))) {
          dVar25 = DAT_14053a138;
        }
        iVar18 = param_1[3];
        uVar6 = *(ushort *)((longlong)param_1 + 0x42);
        uVar10 = uVar5 - uVar6;
        iVar16 = 0x14a;
        uVar7 = (uint)uVar10;
        if (0x8000 < uVar10) {
          uVar7 = 0x10000 - uVar10;
        }
        dVar25 = dVar25 - (double)iVar18 * _DAT_140539db0;
        iVar12 = (uVar19 & 0xffff) - (uint)uVar6;
        iVar15 = (int)uVar7 / 0x14 + 0x30;
        if (iVar12 < -0x8000) {
          iVar12 = iVar12 + 0x10000;
        }
        iVar13 = iVar12 + -0x10000;
        if (iVar12 < 0x8001) {
          iVar13 = iVar12;
        }
        if (iVar13 < 1) {
          uVar10 = uVar6;
          if ((iVar13 < 0) && (uVar10 = uVar6 - (short)iVar15, -iVar15 < iVar13)) {
            uVar10 = uVar5;
          }
        }
        else {
          uVar10 = uVar5;
          if (iVar15 <= iVar13) {
            uVar10 = uVar6 + (short)iVar15;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar10;
        dVar24 = (double)FUN_140332d90(((double)iVar18 - 0.0) * DAT_14053a8c8 * DAT_14053a020 *
                                       DAT_140539d28);
        sVar9 = (short)(int)(dVar24 * _DAT_14053a960) + uVar10;
        *(short *)(param_1 + 0x10) = sVar9;
        if ((iVar18 - 10U < 0x140) &&
           (uVar2 = (longlong)(iVar18 + -10) % (longlong)iVar14, (int)uVar2 == 0)) {
          auVar41._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar41._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar41._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar41._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar25;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),sVar9);
          uVar28 = uVar26;
          FUN_1400709b0(8,uVar2 & 0xffffffff,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                        in_stack_fffffffffffffe78._8_8_,iVar11,12000,0);
          uVar33 = (undefined2)((uint)uVar28 >> 0x10);
          if (2 < DAT_140e419b8) {
            auVar42._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar42._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar42._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar42._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar25 + dVar4;
            in_stack_fffffffffffffe68 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                          *(undefined2 *)(param_1 + 0x10));
            uVar28 = uVar26;
            FUN_1400709b0(8,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25 + dVar4,
                          in_stack_fffffffffffffe78._8_8_,iVar11 - 1U,
                          (int)(12000 / (ulonglong)(iVar11 - 1U)) * (iVar11 + -2) & 0xffff,0);
            uVar33 = (undefined2)((uint)uVar28 >> 0x10);
          }
          FUN_140184700(DAT_140e44190 * 6,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          iVar17 = DAT_140e419b8;
        }
      }
    }
  }
  if (param_1[6] - 0xd4 < 2) {
    iVar14 = 1;
    if (iVar17 == 0) {
      iVar14 = 0x20;
    }
    else if (iVar17 == 1) {
      iVar14 = 0x18;
    }
    else if (iVar17 == 2) {
      iVar14 = 0x14;
    }
    else if ((iVar17 == 3) || (iVar17 == 4)) {
      iVar14 = 0x10;
    }
    iVar11 = 1;
    if (iVar17 == 0) {
      iVar11 = 9;
    }
    else if (iVar17 == 1) {
      iVar11 = 0xd;
    }
    else if ((iVar17 == 2) || (iVar17 == 3)) {
      iVar11 = 0xf;
    }
    else if (iVar17 == 4) {
      iVar11 = 0x11;
    }
    iVar18 = param_1[3];
    iVar11 = iVar11 + (iVar18 + -10) / iVar14;
    dVar25 = DAT_14053a070;
    if ((((iVar17 != 0) && (dVar25 = DAT_14053a088, iVar17 != 1)) && (dVar25 = dVar23, iVar17 != 2))
       && ((iVar17 != 3 && (dVar25 = dVar4, iVar17 == 4)))) {
      dVar25 = DAT_14053a110;
    }
    uVar6 = *(ushort *)(param_1 + 0x10);
    iVar16 = (uVar19 & 0xffff) - (uint)uVar6;
    iVar14 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar14 = iVar16;
    }
    iVar16 = iVar14 + -0x10000;
    if (iVar14 < 0x8001) {
      iVar16 = iVar14;
    }
    dVar25 = (double)iVar18 * DAT_140539e20 + dVar25;
    if (iVar16 < 1) {
      uVar10 = uVar6;
      if ((iVar16 < 0) && (uVar10 = uVar6 - 0x18, -0x18 < iVar16)) {
        uVar10 = uVar5;
      }
    }
    else {
      uVar10 = uVar5;
      if (0x17 < iVar16) {
        uVar10 = uVar6 + 0x18;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar10;
    iVar16 = 0x140;
    if (iVar18 - 10U < 0x136) {
      uVar7 = iVar18 - 10U & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      iVar16 = 0x140;
      if (uVar7 == 0) {
        if (param_1[6] == 0xd4) {
          auVar43._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar43._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar43._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar43._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar25;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),uVar10);
          uVar28 = uVar26;
          FUN_1400709b0(0xd,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                        in_stack_fffffffffffffe78._8_8_,iVar11,0x10000,0);
          uVar33 = (undefined2)((uint)uVar28 >> 0x10);
          uVar10 = *(ushort *)(param_1 + 0x10);
        }
        if (param_1[6] == 0xd5) {
          auVar44._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar44._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar44._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar44._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar25;
          in_stack_fffffffffffffe68 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),uVar10);
          uVar28 = uVar26;
          FUN_1400709b0(0xc,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar25,
                        in_stack_fffffffffffffe78._8_8_,iVar11,0x10000,0);
          uVar33 = (undefined2)((uint)uVar28 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar17 = DAT_140e419b8;
      }
    }
  }
  dVar25 = DAT_140539f90;
  uVar31 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  iVar14 = param_1[6];
  if ((iVar14 == 0xd6) || (iVar14 == 0xd7)) {
    iVar14 = 1;
    if (iVar17 == 0) {
      iVar14 = 0xe;
    }
    else if (iVar17 == 1) {
      iVar14 = 10;
    }
    else if ((iVar17 == 2) || (iVar17 == 3)) {
      iVar14 = 8;
    }
    else if (iVar17 == 4) {
      iVar14 = 7;
    }
    iVar11 = 1;
    if (iVar17 == 0) {
      iVar11 = 2;
    }
    else if ((iVar17 == 1) || (iVar17 == 2)) {
      iVar11 = 3;
    }
    else if (iVar17 == 3) {
      iVar11 = 4;
    }
    else if (iVar17 == 4) {
      iVar11 = 5;
    }
    sVar9 = 1;
    if (iVar17 == 0) {
      sVar9 = 0x78;
    }
    else if (iVar17 == 1) {
      sVar9 = 0xa0;
    }
    else if ((iVar17 == 2) || (iVar17 == 3)) {
      sVar9 = 200;
    }
    else if (iVar17 == 4) {
      sVar9 = 0xfa;
    }
    if ((((iVar17 != 0) && (iVar17 != 1)) && (iVar17 != 2)) &&
       ((iVar17 != 3 && (dVar23 = dVar4, iVar17 == 4)))) {
      dVar23 = dVar22;
    }
    iVar18 = 0x2d0;
    if ((param_1[3] - 10 < 0x2c6) && ((param_1[3] + -10) % iVar14 == 0)) {
      iVar14 = 0;
      do {
        auVar45._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar45._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar45._8_4_ = 1;
        dVar24 = (double)iVar14 * dVar25 + dVar23;
        sVar1 = (short)iVar14 * -0x140;
        if (param_1[6] != 0xd6) {
          sVar1 = (short)iVar14 * 0x140;
        }
        in_stack_fffffffffffffe78._8_8_ = auVar45._8_8_;
        in_stack_fffffffffffffe78._0_8_ = dVar24;
        in_stack_fffffffffffffe68 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                      *(short *)(param_1 + 0x10) + sVar1);
        uVar28 = uVar26;
        FUN_14006c2f0(9,0,fVar27,fVar29,in_stack_fffffffffffffe68,uVar26,dVar24,
                      in_stack_fffffffffffffe78._8_8_,0);
        uVar33 = (undefined2)((uint)uVar28 >> 0x10);
        uVar31 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar11);
      FUN_140184700(DAT_140e44190 * 9,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      iVar17 = DAT_140e419b8;
    }
    iVar14 = param_1[6];
    if (iVar14 == 0xd6) {
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar9;
    }
    else {
      iVar16 = 0x2d0;
      if (iVar14 != 0xd7) goto LAB_1400522cf;
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) - sVar9;
    }
  }
  else {
LAB_1400522cf:
    iVar18 = iVar16;
    if (iVar14 == 0xd8) {
      iVar14 = 1;
      if (iVar17 == 0) {
        iVar14 = 0x78;
      }
      else if (iVar17 == 1) {
        iVar14 = 100;
      }
      else if ((iVar17 == 2) || (iVar17 == 3)) {
        iVar14 = 0x50;
      }
      else if (iVar17 == 4) {
        iVar14 = 0x3c;
      }
      dVar23 = dVar22;
      if (((iVar17 != 0) && (dVar23 = DAT_14053a138, iVar17 != 1)) &&
         ((iVar17 == 2 || ((dVar23 = dVar22, iVar17 != 3 && (dVar23 = dVar4, iVar17 == 4)))))) {
        dVar23 = DAT_14053a158;
      }
      uVar6 = *(ushort *)(param_1 + 0x10);
      uVar10 = uVar5 - uVar6;
      iVar18 = 600;
      uVar7 = (uint)uVar10;
      if (0x8000 < uVar10) {
        uVar7 = 0x10000 - uVar10;
      }
      iVar16 = (uVar19 & 0xffff) - (uint)uVar6;
      iVar17 = (int)uVar7 / 0x14 + 0x30;
      iVar11 = iVar16 + 0x10000;
      if (-0x8001 < iVar16) {
        iVar11 = iVar16;
      }
      iVar16 = iVar11 + -0x10000;
      if (iVar11 < 0x8001) {
        iVar16 = iVar11;
      }
      if (iVar16 < 1) {
        uVar10 = uVar6;
        if ((iVar16 < 0) && (uVar10 = uVar6 - (short)iVar17, -iVar17 < iVar16)) {
          uVar10 = uVar5;
        }
      }
      else {
        uVar10 = uVar5;
        if (iVar17 <= iVar16) {
          uVar10 = uVar6 + (short)iVar17;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar10;
      if ((param_1[3] - 0x1e < 0x23a) &&
         (uVar2 = (longlong)(param_1[3] + -0x1e) % (longlong)iVar14, (int)uVar2 == 0)) {
        auVar46._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar46._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar46._8_4_ = 1;
        auVar47._8_8_ = auVar46._8_8_;
        auVar47._0_8_ = dVar23;
        uVar28 = uVar26;
        FUN_14006c2f0(0xc,uVar2 & 0xffffffff,fVar27,fVar29,CONCAT22(uVar31,uVar10),uVar26,dVar23,
                      auVar47._8_8_,0);
        uVar33 = (undefined2)((uint)uVar28 >> 0x10);
        if (2 < DAT_140e419b8) {
          auVar48._12_4_ = auVar47._12_4_;
          auVar48._0_8_ = auVar47._0_8_;
          auVar48._8_4_ = 1;
          FUN_14006c2f0(0xc,0,fVar27,fVar29,*(undefined2 *)(param_1 + 0x10),uVar26,
                        dVar23 + DAT_14053a018,auVar48._8_8_,0);
          uVar33 = (undefined2)((uint)uVar26 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
  }
  if (((param_1[3] == iVar18) || (iVar30 < 1)) || (DAT_140e4430c < 1)) {
    param_1[5] = param_1[5] + 1;
    param_1[3] = 0;
  }
  uVar26 = SUB84(DAT_140539d28,0);
  uVar28 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar25 = DAT_14053a890;
  dVar23 = DAT_14053a020;
LAB_140052502:
  if ((param_1[5] == 2) && (iVar30 = param_1[3], dVar20 = dVar4, -1 < iVar30)) {
    if (iVar30 < 0x14) {
      dVar20 = (double)FUN_140332d90(((double)iVar30 - _DAT_14053b110) * dVar25 * dVar23 *
                                     (double)CONCAT44(uVar28,uVar26));
      dVar20 = dVar20 + 0.0;
    }
    else {
      dVar20 = 0.0;
      if (iVar30 == 0x14) {
        *param_1 = 0;
        dVar20 = 0.0;
      }
    }
  }
  dVar22 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a988 * dVar23 *
                                 (double)CONCAT44(uVar28,uVar26));
  FUN_1400c8410(DAT_140e44890,0x1f,7,param_1[10],param_1[0xb],CONCAT22(uVar33,(short)(int)dVar21),
                (dVar22 * _DAT_140539e28 + dVar4) * dVar20,dVar20,0xff,0xff,0xff,0xff,1,0);
  auVar3._8_4_ = SUB84(dVar20,0);
  auVar3._0_8_ = dVar20;
  auVar3._12_4_ = (int)((ulonglong)dVar20 >> 0x20);
  FUN_1400c8410(DAT_140e44894,0x20,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x10),auVar3
                ,0xff,0xff,0xff,0xff,1,0);
  return;
}


