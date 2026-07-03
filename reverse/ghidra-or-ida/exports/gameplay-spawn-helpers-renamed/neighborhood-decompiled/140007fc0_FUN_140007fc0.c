// Function: FUN_140007fc0 @ 140007fc0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140007fc0(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined1 auVar8 [16];
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  undefined8 *puVar13;
  ushort uVar14;
  int iVar15;
  short sVar16;
  ushort uVar17;
  uint uVar18;
  float *pfVar19;
  int iVar20;
  short sVar21;
  float *pfVar22;
  bool bVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  float fVar39;
  undefined4 uVar40;
  float fVar41;
  float fVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  float fVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  int local_res18;
  undefined4 in_stack_fffffffffffffe48;
  undefined2 uVar50;
  undefined4 in_stack_fffffffffffffe50;
  undefined2 uVar52;
  undefined4 uVar51;
  undefined1 in_stack_fffffffffffffe58 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined8 uStack_150;
  undefined8 uStack_140;
  float fStack_130;
  float fStack_12c;
  int iStack_fc;
  
  dVar4 = DAT_14053a988;
  dVar6 = DAT_14053a020;
  dVar5 = DAT_140539d28;
  uVar52 = (undefined2)((uint)in_stack_fffffffffffffe50 >> 0x10);
  local_res18 = 0;
  uStack_140 = 0;
  if ((0 < DAT_140e44e6c) && (lVar12 = DAT_140e45d80, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar12 + 4) == DAT_140e44308) {
        uStack_150 = *(undefined8 *)(lVar12 + 8);
        uStack_140 = *(undefined8 *)(lVar12 + 0x18);
        fStack_130 = *(float *)(lVar12 + 0x28);
        fStack_12c = *(float *)(lVar12 + 0x2c);
        iStack_fc = *(int *)(lVar12 + 0x5c);
      }
      lVar12 = *(longlong *)(lVar12 + 0x60);
    } while (lVar12 != 0);
    local_res18 = uStack_140._4_4_;
  }
  iVar10 = param_1[3];
  pfVar19 = (float *)(param_1 + 0xb);
  pfVar22 = (float *)(param_1 + 10);
  fVar45 = (float)param_1[0xd];
  fVar39 = (float)param_1[0xc];
  fVar42 = fStack_12c + fVar45;
  fVar30 = *pfVar19;
  fVar41 = fStack_130 + fVar39;
  dVar7 = (double)iVar10;
  dVar3 = (double)FUN_140332d90(SUB84((dVar7 - 0.0) * DAT_14053a988 * DAT_14053a020 * DAT_140539d28,
                                      0));
  fVar24 = (float)dVar3 + 0.0;
  dVar3 = (double)FUN_140332d90(SUB84((dVar7 - DAT_14053a268) * dVar4 * dVar6 * dVar5,0));
  fVar28 = (float)dVar3 + _DAT_140539cbc;
  dVar4 = (double)FUN_140332d90(SUB84((dVar7 - _DAT_14053a320) * dVar4 * dVar6 * dVar5,0));
  fVar29 = (float)dVar4 + _DAT_140539cbc;
  dVar4 = (double)FUN_140332d90(SUB84((dVar7 - 0.0) * _DAT_14053a9f0 * dVar6 * dVar5,0));
  dVar4 = dVar4 * _DAT_14053aa40;
  uVar31 = SUB84((double)((int)dVar4 & 0xffff) * dVar6 * dVar5,0);
  dVar3 = (double)FUN_1403307c0(uVar31);
  fVar25 = (float)(dVar3 * DAT_14053a340) + 0.0;
  dVar3 = (double)FUN_140332d90(uVar31);
  fVar27 = *pfVar22;
  fVar26 = (float)(dVar3 * DAT_14053a340) + 0.0;
  dVar3 = (double)FUN_1403300b4(SUB84((double)(fVar42 - fVar30),0),
                                SUB84((double)(fVar41 - fVar27),0));
  uVar31 = SUB84((double)((int)(dVar3 * DAT_14053aba0) & 0xffff) * dVar6 * dVar5,0);
  fVar41 = (float)FUN_140334430(fVar27 - fVar41,DAT_140539fc0);
  fVar27 = (float)FUN_140334430(fVar30 - fVar42);
  fVar41 = fVar41 + fVar27;
  if (fVar41 < 0.0) {
    fVar41 = (float)FUN_1403352f8(fVar41);
  }
  else {
    fVar41 = SQRT(fVar41);
  }
  dVar6 = (double)fVar41 / DAT_14053a2d8;
  dVar5 = (double)FUN_1403307c0(uVar31);
  fVar27 = (float)(dVar5 * dVar6) + *pfVar22;
  *pfVar22 = fVar27;
  dVar5 = (double)FUN_140332d90(uVar31);
  auVar61 = _DAT_14053bb20;
  uVar31 = (undefined4)DAT_14053bb20;
  uVar2 = DAT_14053bb20._4_4_;
  fVar30 = (float)(dVar5 * dVar6) + fVar30;
  *pfVar19 = fVar30;
  dVar5 = auVar61._0_8_;
  if (param_1[5] == 0) {
    if (iVar10 == 0) {
      fVar45 = fVar45 * DAT_14053a2e8;
      *pfVar22 = fVar39 * DAT_14053a2e8 + fStack_130;
      *pfVar19 = fVar45 + fStack_12c;
      goto LAB_140008348;
    }
    if (iVar10 != 0x3c) goto LAB_1400086d7;
    param_1[5] = 1;
    param_1[0x15] = 0;
    param_1[3] = 0;
  }
  else {
LAB_1400086d7:
    if (param_1[5] != 1) goto LAB_140008348;
  }
  iVar10 = DAT_140e419b8;
  uVar9 = DAT_14053ac2c;
  uVar38 = (undefined4)DAT_14053a208;
  uVar40 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
  uVar48 = (undefined4)DAT_14053a1b8;
  uVar49 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
  uVar46 = (undefined4)DAT_14053a138;
  uVar47 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
  uVar43 = (undefined4)DAT_14053a0f8;
  uVar44 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
  fVar45 = (fVar30 - fVar24) - DAT_14053ac58;
  uVar34 = (undefined4)DAT_14053a0b0;
  uVar37 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
  if (param_1[6] == 0x15) {
    iVar20 = 1;
    iVar11 = (param_1[1] - DAT_1407c77a0) + 10;
    if (DAT_140e419b8 == 0) {
      iVar20 = 0x96;
    }
    else if (DAT_140e419b8 == 1) {
      iVar20 = 100;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar20 = 0x50;
    }
    else if (DAT_140e419b8 == 4) {
      iVar20 = 0x3c;
    }
    uVar32 = uVar34;
    uVar35 = uVar37;
    if ((((DAT_140e419b8 != 0) && (uVar32 = uVar43, uVar35 = uVar44, DAT_140e419b8 != 1)) &&
        (uVar32 = uVar46, uVar35 = uVar47, DAT_140e419b8 != 2)) &&
       ((uVar32 = uVar48, uVar35 = uVar49, DAT_140e419b8 != 3 &&
        (uVar32 = uVar31, uVar35 = uVar2, DAT_140e419b8 == 4)))) {
      uVar32 = uVar38;
      uVar35 = uVar40;
    }
    if (iVar11 * 10 <= uStack_150._4_4_) {
      if ((uStack_150._4_4_ + iVar11 * -10) % iVar20 == 0) {
        dVar6 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar45),0));
        uVar18 = (uStack_150._4_4_ + iVar11 * -10) % iVar20;
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar6 * DAT_14053aba0);
      }
      else if ((uStack_150._4_4_ < iVar11 * 10) ||
              (uVar18 = (uStack_150._4_4_ + iVar11 * -10) % iVar20, 0xb < (int)uVar18))
      goto LAB_140008933;
      uVar18 = uVar18 & 0x80000003;
      if ((int)uVar18 < 0) {
        uVar18 = (uVar18 - 1 | 0xfffffffc) + 1;
      }
      if (uVar18 == 0) {
        auVar53._12_4_ = in_stack_fffffffffffffe58._12_4_;
        auVar53._0_8_ = in_stack_fffffffffffffe58._0_8_;
        auVar53._8_4_ = 1;
        in_stack_fffffffffffffe58._8_8_ = auVar53._8_8_;
        in_stack_fffffffffffffe58._0_8_ = CONCAT44(uVar35,uVar32);
        in_stack_fffffffffffffe48 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                      *(undefined2 *)((longlong)param_1 + 0x42));
        uVar38 = uVar9;
        FUN_14006c2f0(7,0,fVar27,fVar45,in_stack_fffffffffffffe48,uVar9,CONCAT44(uVar35,uVar32),
                      in_stack_fffffffffffffe58._8_8_,0);
        uVar52 = (undefined2)((uint)uVar38 >> 0x10);
        if (2 < DAT_140e419b8) {
          dVar6 = (double)CONCAT44(uVar35,uVar32) - _DAT_140539f88;
          sVar21 = *(short *)((longlong)param_1 + 0x42);
          iVar10 = 0;
          do {
            auVar54._12_4_ = in_stack_fffffffffffffe58._12_4_;
            auVar54._0_8_ = in_stack_fffffffffffffe58._0_8_;
            auVar54._8_4_ = 1;
            in_stack_fffffffffffffe58._8_8_ = auVar54._8_8_;
            in_stack_fffffffffffffe58._0_8_ = dVar6;
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                          (short)iVar10 * 0x578 + sVar21 + -700);
            uVar38 = uVar9;
            FUN_14006c2f0(7,0,fVar27,fVar45,in_stack_fffffffffffffe48,uVar9,dVar6,
                          in_stack_fffffffffffffe58._8_8_,0);
            uVar52 = (undefined2)((uint)uVar38 >> 0x10);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar10 = DAT_140e419b8;
      }
      uVar38 = (undefined4)DAT_14053a208;
      uVar40 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
    }
  }
LAB_140008933:
  uVar50 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
  if (param_1[6] == 0x16) {
    uVar32 = 1;
    if (((iVar10 != 0) && (iVar10 != 1)) && ((iVar10 == 2 || ((iVar10 == 3 || (iVar10 == 4)))))) {
      uVar32 = 2;
    }
    uVar35 = 1;
    if ((iVar10 == 0) || (iVar10 == 1)) {
      uVar35 = 0;
    }
    else if (iVar10 == 2) {
      uVar35 = 0x5dc;
    }
    else if (iVar10 == 3) {
      uVar35 = 0x960;
    }
    else if (iVar10 == 4) {
      uVar35 = 3000;
    }
    iVar11 = 1;
    if (iVar10 == 0) {
      iVar11 = 0x18;
    }
    else if (iVar10 == 1) {
      iVar11 = 0xb;
    }
    else if ((iVar10 == 2) || (iVar10 == 3)) {
      iVar11 = 9;
    }
    else if (iVar10 == 4) {
      iVar11 = 5;
    }
    if (iVar10 == 0) {
      uVar33 = (int)DAT_14053a018;
      uVar36 = (int)((ulonglong)DAT_14053a018 >> 0x20);
    }
    else if (iVar10 == 1) {
      uVar33 = (int)DAT_14053a070;
      uVar36 = (int)((ulonglong)DAT_14053a070 >> 0x20);
    }
    else {
      uVar33 = uVar34;
      uVar36 = uVar37;
      if (((iVar10 != 2) && (iVar10 != 3)) && (uVar33 = uVar31, uVar36 = uVar2, iVar10 == 4)) {
        uVar33 = uVar43;
        uVar36 = uVar44;
      }
    }
    sVar16 = 1;
    sVar21 = -1;
    if (iVar10 == 0) {
      sVar16 = 100;
      sVar21 = -100;
    }
    else if (iVar10 == 1) {
      sVar16 = 0xbe;
      sVar21 = -0xbe;
    }
    else if ((iVar10 == 2) || (iVar10 == 3)) {
      sVar16 = 0xa0;
      sVar21 = -0xa0;
    }
    else if (iVar10 == 4) {
      sVar16 = 0x172;
      sVar21 = -0x172;
    }
    fVar39 = (float)param_1[0xc];
    if (fVar39 <= 0.0) {
      sVar21 = sVar16;
    }
    if ((param_1[3] == 0) && (*(undefined2 *)((longlong)param_1 + 0x42) = 0xe000, fVar39 < 0.0)) {
      *(undefined2 *)((longlong)param_1 + 0x42) = 0xa000;
    }
    if (0x59 < uStack_150._4_4_) {
      if (uStack_150._4_4_ < 0xd2) {
        uVar14 = *(short *)((longlong)param_1 + 0x42) + 200;
        if (fVar39 <= 0.0) {
          uVar14 = *(short *)((longlong)param_1 + 0x42) - 200;
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar14;
      }
      else {
        uVar1 = *(ushort *)((longlong)param_1 + 0x42);
        dVar6 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fStack_12c),0),
                                      SUB84((double)(DAT_140e445d8 - fStack_130),0));
        uVar17 = (ushort)(int)(dVar6 * DAT_14053aba0);
        iVar15 = ((int)(dVar6 * DAT_14053aba0) & 0xffffU) - (uint)uVar1;
        iVar20 = iVar15 + 0x10000;
        if (-0x8001 < iVar15) {
          iVar20 = iVar15;
        }
        iVar15 = iVar20 + -0x10000;
        if (iVar20 < 0x8001) {
          iVar15 = iVar20;
        }
        if (iVar15 < 1) {
          uVar14 = uVar1;
          if ((iVar15 < 0) && (uVar14 = uVar1 - 0x20, -0x20 < iVar15)) {
            uVar14 = uVar17;
          }
        }
        else {
          uVar14 = uVar17;
          if (0x1f < iVar15) {
            uVar14 = uVar1 + 0x20;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar14;
        if (uVar14 < 0x4fa0) {
          if (uVar14 < 0x3061) {
            *(undefined2 *)((longlong)param_1 + 0x42) = 0x3060;
            uVar14 = 0x3060;
          }
        }
        else {
          *(undefined2 *)((longlong)param_1 + 0x42) = 0x4fa0;
          uVar14 = 0x4fa0;
        }
      }
      uVar18 = uStack_150._4_4_ - 0x5aU & 0x80000003;
      if ((int)uVar18 < 0) {
        uVar18 = (uVar18 - 1 | 0xfffffffc) + 1;
      }
      if (uVar18 == 0) {
        auVar55._12_4_ = in_stack_fffffffffffffe58._12_4_;
        auVar55._0_8_ = in_stack_fffffffffffffe58._0_8_;
        auVar55._8_4_ = 1;
        in_stack_fffffffffffffe58._8_8_ = auVar55._8_8_;
        in_stack_fffffffffffffe58._0_8_ = DAT_14053a1e8;
        in_stack_fffffffffffffe48 =
             CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),uVar14);
        uVar51 = uVar9;
        FUN_1400709b0(7,0,fVar27,fVar45,in_stack_fffffffffffffe48,uVar9,DAT_14053a1e8,
                      in_stack_fffffffffffffe58._8_8_,uVar32,uVar35,0);
        uVar52 = (undefined2)((uint)uVar51 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar10 = DAT_140e419b8;
      }
      uVar50 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
      if ((0x17b < uStack_150._4_4_) && ((uStack_150._4_4_ + -0x17c) % iVar11 == 0)) {
        sVar16 = *(short *)(param_1 + 3);
        iVar10 = 0;
        do {
          auVar56._12_4_ = in_stack_fffffffffffffe58._12_4_;
          auVar56._0_8_ = in_stack_fffffffffffffe58._0_8_;
          auVar56._8_4_ = 1;
          in_stack_fffffffffffffe58._8_8_ = auVar56._8_8_;
          in_stack_fffffffffffffe58._0_8_ = CONCAT44(uVar36,uVar33);
          in_stack_fffffffffffffe48 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                        (short)iVar10 * 0x5555 + sVar16 * sVar21);
          uVar32 = uVar9;
          FUN_14006c2f0(8,0,fVar27,fVar45,in_stack_fffffffffffffe48,uVar9,CONCAT44(uVar36,uVar33),
                        in_stack_fffffffffffffe58._8_8_,0);
          uVar52 = (undefined2)((uint)uVar32 >> 0x10);
          uVar50 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
          iVar10 = iVar10 + 1;
        } while (iVar10 < 3);
        if (2 < DAT_140e419b8) {
          sVar16 = *(short *)(param_1 + 3);
          dVar6 = (double)CONCAT44(uVar36,uVar33) + dVar5;
          iVar10 = 0;
          do {
            auVar57._12_4_ = in_stack_fffffffffffffe58._12_4_;
            auVar57._0_8_ = in_stack_fffffffffffffe58._0_8_;
            auVar57._8_4_ = 1;
            in_stack_fffffffffffffe58._8_8_ = auVar57._8_8_;
            in_stack_fffffffffffffe58._0_8_ = dVar6;
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffe48 >> 0x10),
                          (short)iVar10 * 0x5555 + sVar16 * sVar21);
            uVar32 = uVar9;
            FUN_14006c2f0(8,0,fVar27,fVar45,in_stack_fffffffffffffe48,uVar9,dVar6,
                          in_stack_fffffffffffffe58._8_8_,0);
            uVar52 = (undefined2)((uint)uVar32 >> 0x10);
            uVar50 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 3);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar10 = DAT_140e419b8;
      }
    }
  }
  iVar11 = 0;
  if (param_1[6] == 0x17) {
    uVar18 = 1;
    if (iVar10 == 0) {
      uVar18 = 200;
    }
    else if (iVar10 == 1) {
      uVar18 = 0x78;
    }
    else if (iVar10 == 2) {
      uVar18 = 100;
    }
    else if (iVar10 == 3) {
      uVar18 = 0x5a;
    }
    else if (iVar10 == 4) {
      uVar18 = 0x50;
    }
    iVar20 = (param_1[1] - DAT_1407c77a0) * (uVar18 >> 1) + 0xd2;
    if ((((iVar10 != 0) && (uVar34 = uVar43, uVar37 = uVar44, iVar10 != 1)) &&
        (uVar34 = uVar46, uVar37 = uVar47, iVar10 != 2)) &&
       ((uVar34 = uVar48, uVar37 = uVar49, iVar10 != 3 &&
        (uVar34 = uVar31, uVar37 = uVar2, iVar10 == 4)))) {
      uVar34 = uVar38;
      uVar37 = uVar40;
    }
    if (iVar20 <= uStack_150._4_4_) {
      if ((uStack_150._4_4_ - iVar20) % (int)uVar18 == 0) {
        dVar6 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar45),0),
                                      SUB84((double)(DAT_140e445d8 - fVar27),0));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar6 * DAT_14053aba0);
      }
      if ((iVar20 <= uStack_150._4_4_) &&
         (uVar18 = (uStack_150._4_4_ - iVar20) % (int)uVar18, (int)uVar18 < 0x18)) {
        uVar18 = uVar18 & 0x80000003;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xfffffffc) + 1;
        }
        if (uVar18 == 0) {
          auVar58._12_4_ = in_stack_fffffffffffffe58._12_4_;
          auVar58._0_8_ = in_stack_fffffffffffffe58._0_8_;
          auVar58._8_4_ = 1;
          auVar59._8_8_ = auVar58._8_8_;
          auVar59._0_8_ = CONCAT44(uVar37,uVar34);
          uVar31 = uVar9;
          FUN_14006c2f0(0xb,0,fVar27,fVar45,
                        CONCAT22(uVar50,*(undefined2 *)((longlong)param_1 + 0x42)),uVar9,
                        CONCAT44(uVar37,uVar34),auVar59._8_8_,0);
          uVar52 = (undefined2)((uint)uVar31 >> 0x10);
          if (1 < DAT_140e419b8) {
            dVar6 = (double)CONCAT44(uVar37,uVar34) - DAT_140539ec8;
            sVar21 = *(short *)((longlong)param_1 + 0x42);
            do {
              auVar60._12_4_ = auVar59._12_4_;
              auVar60._0_8_ = auVar59._0_8_;
              auVar60._8_4_ = 1;
              auVar59._8_8_ = auVar60._8_8_;
              auVar59._0_8_ = dVar6;
              uVar31 = uVar9;
              FUN_14006c2f0(0xb,0,fVar27,fVar45,(short)iVar11 * 6000 + sVar21 + -3000,uVar9,dVar6,
                            auVar59._8_8_,0);
              uVar52 = (undefined2)((uint)uVar31 >> 0x10);
              iVar11 = iVar11 + 1;
            } while (iVar11 < 2);
          }
        }
      }
    }
  }
  FUN_140079c10(param_1,1);
LAB_140008348:
  pfVar22 = (float *)(param_1 + 10);
  pfVar19 = (float *)(param_1 + 0xb);
  sVar21 = (short)(int)dVar4;
  uVar31 = CONCAT22(uVar52,sVar21);
  FUN_1400c8410(DAT_140e44698,0x23,7,fVar25 + *pfVar22,fVar28 + *pfVar19 + fVar26,uVar31,auVar61,
                0xff,0xff,0xff,0xff,1,0);
  uVar18 = CONCAT22((short)((uint)uVar31 >> 0x10),-sVar21);
  FUN_1400c8410(DAT_140e44698,0x23,7,*pfVar22 - fVar25,fVar28 + *pfVar19 + fVar26,uVar18,auVar61,
                0xff,0xff,0xff,0xff,1,1);
  fVar45 = DAT_14053ac48;
  uVar18 = uVar18 & 0xffff0000;
  FUN_1400c8410(DAT_140e44694,0x23,7,*pfVar22,fVar29 + *pfVar19 + DAT_14053ac48,uVar18,auVar61,0xff,
                0xff,0xff,0xff,1,0);
  uVar18 = uVar18 & 0xffff0000;
  FUN_1400c8410(DAT_140e44690,0x23,7,*pfVar22,fVar28 + *pfVar19,uVar18,auVar61,0xff,0xff,0xff,0xff,1
                ,0);
  fVar39 = DAT_14053ac94;
  uVar18 = uVar18 & 0xffff0000;
  FUN_1400c8410(DAT_140e4468c,0x23,7,*pfVar22,(fVar24 + *pfVar19) - DAT_14053ac94,uVar18,auVar61,
                0xff,0xff,0xff,0xff,1,0);
  uVar31 = DAT_140e44698;
  uVar52 = (undefined2)(uVar18 >> 0x10);
  puVar13 = DAT_140e45d28;
  if ((param_1[5] == 0) && ((*(byte *)(param_1 + 3) & 1) == 0)) {
    fVar27 = fVar28 + *pfVar19 + fVar26;
    fVar30 = *pfVar22;
    iVar10 = DAT_140e45d1c;
    if (DAT_140e45d1c < 0x1000) {
      puVar13 = (undefined8 *)_malloc_base(0x60);
      if (puVar13 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar10 = DAT_140e45d1c + 1;
      *(float *)((longlong)puVar13 + 0x14) = fVar25 + fVar30;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar13 + 3) = fVar27;
      *(float *)((longlong)puVar13 + 0x1c) = fVar25 + fVar30;
      *(float *)(puVar13 + 4) = fVar27;
      *puVar13 = 1;
      *(undefined4 *)(puVar13 + 1) = 5;
      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar31;
      *(undefined4 *)(puVar13 + 2) = 0x22;
      *(short *)((longlong)puVar13 + 0x24) = sVar21;
      puVar13[5] = 0;
      puVar13[6] = 0x3ff0000000000000;
      puVar13[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar13 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
      *(undefined4 *)(puVar13 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
      puVar13[10] = 0x60;
      puVar13[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar13;
      }
      DAT_140e45d1c = iVar10;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar13;
      }
    }
    DAT_140e45d28 = puVar13;
    uVar31 = DAT_140e44698;
    fVar30 = (float)param_1[10];
    fVar26 = fVar28 + (float)param_1[0xb] + fVar26;
    puVar13 = DAT_140e45d28;
    if (iVar10 < 0x1000) {
      puVar13 = (undefined8 *)_malloc_base(0x60);
      if (puVar13 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar10 = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar31;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar13 + 0x14) = fVar30 - fVar25;
      *(float *)(puVar13 + 3) = fVar26;
      *(float *)((longlong)puVar13 + 0x1c) = fVar30 - fVar25;
      *(float *)(puVar13 + 4) = fVar26;
      *puVar13 = 1;
      *(undefined4 *)(puVar13 + 1) = 7;
      *(undefined4 *)(puVar13 + 2) = 0x22;
      *(short *)((longlong)puVar13 + 0x24) = -sVar21;
      puVar13[5] = 0;
      puVar13[6] = 0x3ff0000000000000;
      puVar13[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar13 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
      *(undefined4 *)(puVar13 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
      puVar13[10] = 0x60;
      puVar13[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar13;
      }
      DAT_140e45d1c = iVar10;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar13;
      }
    }
    DAT_140e45d28 = puVar13;
    uVar2 = DAT_140e44694;
    uVar31 = param_1[10];
    fVar45 = fVar29 + (float)param_1[0xb] + fVar45;
    puVar13 = DAT_140e45d28;
    if (iVar10 < 0x1000) {
      puVar13 = (undefined8 *)_malloc_base(0x60);
      if (puVar13 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar10 = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar13 + 0x14) = uVar31;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar13 + 3) = fVar45;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar31;
      *(float *)(puVar13 + 4) = fVar45;
      *puVar13 = 1;
      *(undefined4 *)(puVar13 + 1) = 5;
      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar2;
      *(undefined4 *)(puVar13 + 2) = 0x22;
      *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
      puVar13[5] = 0;
      puVar13[6] = 0x3ff0000000000000;
      puVar13[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar13 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
      *(undefined4 *)(puVar13 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
      puVar13[10] = 0x60;
      puVar13[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar13;
      }
      DAT_140e45d1c = iVar10;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar13;
      }
    }
    DAT_140e45d28 = puVar13;
    uVar2 = DAT_140e44690;
    uVar31 = param_1[10];
    fVar45 = (float)param_1[0xb];
    puVar13 = DAT_140e45d28;
    if (iVar10 < 0x1000) {
      puVar13 = (undefined8 *)_malloc_base(0x60);
      if (puVar13 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar10 = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar13 + 0x14) = uVar31;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar13 + 3) = fVar28 + fVar45;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar31;
      *(float *)(puVar13 + 4) = fVar28 + fVar45;
      *puVar13 = 1;
      *(undefined4 *)(puVar13 + 1) = 5;
      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar2;
      *(undefined4 *)(puVar13 + 2) = 0x22;
      *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
      puVar13[5] = 0;
      puVar13[6] = 0x3ff0000000000000;
      puVar13[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar13 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
      *(undefined4 *)(puVar13 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
      puVar13[10] = 0x60;
      puVar13[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar13;
      }
      DAT_140e45d1c = iVar10;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar13;
      }
    }
    DAT_140e45d28 = puVar13;
    uVar2 = DAT_140e4468c;
    uVar31 = param_1[10];
    fVar39 = (fVar24 + (float)param_1[0xb]) - fVar39;
    puVar13 = DAT_140e45d28;
    if (iVar10 < 0x1000) {
      puVar13 = (undefined8 *)_malloc_base(0x60);
      if (puVar13 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar13 + 0x14) = uVar31;
      *(float *)(puVar13 + 3) = fVar39;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar31;
      *(float *)(puVar13 + 4) = fVar39;
      *puVar13 = 1;
      *(undefined4 *)(puVar13 + 1) = 5;
      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar2;
      *(undefined4 *)(puVar13 + 2) = 0x22;
      *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
      puVar13[5] = 0;
      puVar13[6] = 0x3ff0000000000000;
      puVar13[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar13 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
      *(undefined4 *)(puVar13 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
      puVar13[10] = 0x60;
      puVar13[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar13;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar13;
      }
    }
  }
  DAT_140e45d28 = puVar13;
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,1000,8);
    FUN_140079e20(param_1,1);
    auVar61._8_4_ = 10;
    auVar62._8_8_ = auVar61._8_8_;
    auVar62._0_8_ = dVar5;
    uVar18 = DAT_14053b380;
    stage_entity_spawn_candidate
              (0x153,(int)param_1[8] / 2,1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar52,0x4000),dVar5
               ,auVar62._8_8_,1,DAT_140e44308);
    iVar10 = DAT_140e44308;
    lVar12 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar12 != 0; lVar12 = *(longlong *)(lVar12 + 0x60)) {
        if (*(int *)(lVar12 + 4) == iVar10) {
          *(int *)(lVar12 + 0x5c) = *(int *)(lVar12 + 0x5c) + -1;
        }
      }
    }
    if (iStack_fc == 1) {
      auVar8._12_4_ = 0;
      auVar8._0_12_ = auVar62._4_12_;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar18 & 0xffff0000,0,auVar8 << 0x20);
    }
    *param_1 = 0;
  }
  if ((local_res18 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


