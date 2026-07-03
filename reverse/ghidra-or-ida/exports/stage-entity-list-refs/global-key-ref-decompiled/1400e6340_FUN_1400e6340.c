// Function: FUN_1400e6340 @ 1400e6340
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e6340(undefined4 *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  longlong lVar8;
  double dVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  int iVar17;
  undefined4 extraout_XMM0_Da;
  undefined4 uVar18;
  float fVar19;
  undefined4 in_stack_fffffffffffffe88;
  undefined2 uVar20;
  uint in_stack_fffffffffffffe90;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  int iStack_114;
  int iStack_10c;
  undefined8 uStack_100;
  
  uVar20 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
  iStack_10c = 0;
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == DAT_140e44308) {
        iStack_114 = *(int *)(lVar8 + 0x14);
        iStack_10c = *(int *)(lVar8 + 0x1c);
        uStack_100 = *(undefined8 *)(lVar8 + 0x28);
      }
    }
  }
  iVar10 = param_1[3];
  dVar4 = (double)iVar10 - 0.0;
  dVar5 = (double)FUN_140332d90(SUB84(dVar4 * _DAT_14053aa60 * DAT_14053a020 * DAT_140539d28,0));
  dVar9 = DAT_140539f40;
  uVar18 = SUB84(DAT_140539f40,0);
  uStack_100._0_4_ = (float)uStack_100 + (float)param_1[0xc];
  fVar19 = (float)param_1[0xd];
  dVar6 = dVar5 * _DAT_14053b050 + DAT_140539f40;
  param_1[10] = (float)uStack_100;
  param_1[0xb] = uStack_100._4_4_ + fVar19;
  dVar7 = dVar9;
  dVar5 = dVar9;
  if (param_1[5] == 0) {
    if (iVar10 < 0) {
      dVar7 = 0.0;
      dVar5 = 0.0;
    }
    else if (iVar10 < 0x1e) {
      dVar5 = (double)FUN_140332d90(SUB84(dVar4 * DAT_14053a798 * DAT_14053a020 * DAT_140539d28,0));
      dVar7 = dVar5 + 0.0;
      dVar5 = 0.0;
    }
    if (iVar10 - 0x1eU < 0x14) {
      dVar5 = (double)FUN_140332d90(SUB84(((double)iVar10 - DAT_14053a2d8) * DAT_14053a890 *
                                          DAT_14053a020 * DAT_140539d28,0));
      dVar5 = dVar5 + 0.0;
    }
    if (iVar10 != 0x32) goto LAB_1400e6d6c;
    param_1[3] = 0;
    param_1[5] = 1;
    iVar10 = 0;
  }
  else if (param_1[5] != 1) goto LAB_1400e6d6c;
  fVar19 = (uStack_100._4_4_ + fVar19) - DAT_14053accc;
  dVar4 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar19),0),
                                SUB84((double)(DAT_140e445d8 - (float)uStack_100),0));
  uVar14 = DAT_14053ac2c;
  auVar21._0_8_ = in_stack_fffffffffffffe98._0_8_;
  iVar17 = param_1[1] - DAT_1407c77a0;
  uVar13 = (iVar10 + -0x3c) % 1000;
  if (0x3b < iVar10) {
    if ((int)uVar13 < 0x1cc) {
      iVar11 = 1;
      iVar10 = 1;
      sVar16 = (short)(int)(dVar4 * DAT_14053aba0);
      if (iVar17 < 2) {
        if (DAT_140e419b8 == 0) {
          iVar10 = 0x78;
        }
        else if (DAT_140e419b8 == 1) {
          iVar10 = 0x50;
        }
        else if (DAT_140e419b8 == 2) {
          iVar10 = 0x46;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar10 = 0x3c;
        }
        uVar18 = 1;
        if (DAT_140e419b8 == 0) {
          uVar18 = 800;
        }
        else if (DAT_140e419b8 == 1) {
          uVar18 = 0x4b0;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          uVar18 = 0x640;
        }
        dVar4 = DAT_14053a110;
        if ((((DAT_140e419b8 != 0) && (dVar4 = DAT_14053a178, DAT_140e419b8 != 1)) &&
            (dVar4 = DAT_14053a1b8, DAT_140e419b8 != 2)) &&
           ((dVar4 = DAT_14053a1e8, DAT_140e419b8 != 3 && (dVar4 = dVar9, DAT_140e419b8 == 4)))) {
          dVar4 = DAT_14053a210;
        }
        if ((uVar13 < 0x1cc) && ((int)uVar13 % iVar10 == 0)) {
          *(short *)(param_1 + 0x11) = sVar16;
        }
        else if ((499 < uVar13) || (0x17 < (int)uVar13 % iVar10)) goto LAB_1400e6d6c;
        uVar14 = DAT_14053ac2c;
        iVar10 = (int)uVar13 % iVar10;
        if (iVar10 == (iVar10 / 3 + (iVar10 >> 0x1f) +
                      (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3) {
          auVar21._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar21._8_4_ = 1;
          auVar22._8_8_ = auVar21._8_8_;
          auVar22._0_8_ = dVar4;
          FUN_14006c2f0(0xc,0,(float)uStack_100,fVar19,
                        CONCAT22(uVar20,*(undefined2 *)(param_1 + 0x11)),DAT_14053ac2c,dVar4,
                        auVar22._8_8_,0);
          auVar23._12_4_ = auVar22._12_4_;
          auVar23._0_8_ = auVar22._0_8_;
          auVar23._8_4_ = 1;
          FUN_1400709b0(0xc,0,(float)uStack_100,fVar19,*(undefined2 *)(param_1 + 0x11),uVar14,
                        dVar4 - DAT_140539f00,auVar23._8_8_,2,uVar18,0);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          in_stack_fffffffffffffe90 = uVar14;
        }
      }
      else {
        if (DAT_140e419b8 == 0) {
          iVar11 = 0x3c;
        }
        else if (DAT_140e419b8 == 1) {
          iVar11 = 0x30;
        }
        else if (DAT_140e419b8 == 2) {
          iVar11 = 0x24;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar11 = 0x19;
        }
        iVar10 = 1;
        if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
          iVar10 = 9;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar10 = 0xb;
        }
        else if (DAT_140e419b8 == 4) {
          iVar10 = 0xd;
        }
        dVar4 = DAT_14053a030;
        if ((((DAT_140e419b8 != 0) && (dVar4 = DAT_14053a070, DAT_140e419b8 != 1)) &&
            (dVar4 = DAT_14053a088, DAT_140e419b8 != 2)) &&
           ((dVar4 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar4 = dVar9, DAT_140e419b8 == 4)))) {
          dVar4 = DAT_14053a110;
        }
        iVar17 = 0;
        if ((uVar13 < 400) && (iVar12 = iVar17, (int)uVar13 % (iVar11 * 2) == 0)) {
          do {
            auVar24._12_4_ = in_stack_fffffffffffffe98._12_4_;
            auVar24._0_8_ = in_stack_fffffffffffffe98._0_8_;
            auVar24._8_4_ = 1;
            in_stack_fffffffffffffe98._8_8_ = auVar24._8_8_;
            in_stack_fffffffffffffe98._0_8_ = dVar4;
            in_stack_fffffffffffffe90 = uVar14;
            FUN_1400709b0(9,0,(float)uStack_100,fVar19,(short)iVar12 * 0xfa + sVar16 + -500,uVar14,
                          dVar4,in_stack_fffffffffffffe98._8_8_,iVar10,30000,0);
            iVar12 = iVar12 + 1;
          } while (iVar12 < 5);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        if (((iVar11 <= (int)uVar13) && ((int)uVar13 < 400)) &&
           ((int)(uVar13 - iVar11) % (iVar11 * 2) == 0)) {
          do {
            auVar25._12_4_ = in_stack_fffffffffffffe98._12_4_;
            auVar25._0_8_ = in_stack_fffffffffffffe98._0_8_;
            auVar25._8_4_ = 1;
            in_stack_fffffffffffffe98._8_8_ = auVar25._8_8_;
            in_stack_fffffffffffffe98._0_8_ = dVar4;
            in_stack_fffffffffffffe90 = uVar14;
            FUN_1400709b0(9,0,(float)uStack_100,fVar19,(short)iVar17 * 0xfa + sVar16 + -500,uVar14,
                          dVar4,in_stack_fffffffffffffe98._8_8_,iVar10 - 1U,
                          (int)(30000 / (ulonglong)(iVar10 - 1U)) * (iVar10 + -2) & 0xffff,0);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 5);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
    else if (499 < (int)uVar13) {
      iVar10 = 1;
      if (DAT_140e419b8 == 0) {
        iVar10 = 8;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 5;
      }
      else if (DAT_140e419b8 == 2) {
        iVar10 = 4;
      }
      else if (DAT_140e419b8 == 3) {
        iVar10 = 3;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 2;
      }
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 100;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 0x50;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0x3c;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x32;
      }
      if ((((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) || (DAT_140e419b8 == 2)) ||
         ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
        uVar18 = SUB84(DAT_14053a070,0);
      }
      dVar4 = DAT_14053a0d0;
      if (((DAT_140e419b8 != 0) && (dVar4 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
         ((dVar4 = DAT_14053a118, DAT_140e419b8 != 2 &&
          ((dVar4 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar4 = dVar9, DAT_140e419b8 == 4)))))) {
        dVar4 = DAT_14053a1a8;
      }
      if ((int)uVar13 < 900) {
        if ((int)(uVar13 - 500) % iVar10 == 0) {
          uVar15 = iVar17 * 0xde + param_1[3];
          uVar14 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar14 = uVar14 * 0x800 ^ uVar14;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
          DAT_140e9fd1c = uVar14;
          uVar2 = FUN_140134db0(uVar15,uVar18,dVar4);
          auVar26._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar26._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar26._8_4_ = 1;
          in_stack_fffffffffffffe98._8_8_ = auVar26._8_8_;
          in_stack_fffffffffffffe98._0_8_ = uVar2;
          in_stack_fffffffffffffe90 = 0;
          uVar18 = CONCAT22(uVar20,(short)uVar14 + (short)((ulonglong)uVar14 / 0x4e21) * -0x4e21 +
                                   -0x6710);
          FUN_14006c2f0(0xd,8,(float)uStack_100,fVar19,uVar18,0,uVar2,
                        in_stack_fffffffffffffe98._8_8_,0);
          uVar20 = (undefined2)((uint)uVar18 >> 0x10);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        else if (899 < (int)uVar13) goto LAB_1400e6d6c;
        uVar1 = (longlong)(int)(uVar13 - 500) % (longlong)iVar11;
        iVar11 = (int)uVar1;
        if ((iVar11 < 0x28) &&
           ((int)((longlong)((ulonglong)(uint)(iVar11 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
                 (longlong)iVar10) == 0)) {
          uVar13 = iVar17 * 0xde + param_1[3];
          uVar14 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar14 = uVar14 * 0x800 ^ uVar14;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
          DAT_140e9fd1c = uVar14;
          uVar2 = FUN_140134db0(uVar13 + 1,SUB84(DAT_14053a0b0,0),DAT_14053a1e8);
          auVar27._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar27._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar27._8_4_ = 1;
          in_stack_fffffffffffffe90 = 0;
          FUN_14006c2f0(0xc,9,(float)uStack_100,fVar19,
                        CONCAT22(uVar20,(short)uVar14 +
                                        (short)((ulonglong)uVar14 / 0x5dc1) * -0x5dc1 + -0x6ee0),0,
                        uVar2,auVar27._8_8_,0);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
    }
  }
LAB_1400e6d6c:
  in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d78,0x1e,0x17,param_1[10],(float)param_1[0xb] - DAT_14053acbc,
                in_stack_fffffffffffffe90,dVar6,dVar7,0,0,0,0x40,1,0);
  auVar28._8_8_ = dVar7;
  auVar28._0_8_ = dVar6;
  FUN_1400c8410(DAT_140e44d78,0x23,0xb,param_1[10],(float)param_1[0xb] + DAT_14053acbc,
                in_stack_fffffffffffffe90 & 0xffff0000,dVar6,dVar7,0xff,0xff,0xff,0xff,1,0);
  auVar29._4_12_ = auVar28._4_12_;
  auVar29._0_4_ = 0x16;
  uVar14 = 0;
  iVar10 = FUN_1400c9580((float)param_1[0xb] - DAT_14053accc,0,3,3,0x14,0x15,auVar29);
  auVar3._8_4_ = SUB84(dVar5,0);
  auVar3._0_8_ = dVar5;
  auVar3._12_4_ = (int)((ulonglong)dVar5 >> 0x20);
  FUN_1400c8410((&DAT_140e44660)[iVar10],0x23,7,param_1[10],extraout_XMM0_Da,uVar14 & 0xffff0000,
                auVar3,0xff,0xff,0xff,0xff,1,0);
  if ((iStack_114 == 2) && ((iStack_10c < 1 || (DAT_140e4430c < 1)))) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


