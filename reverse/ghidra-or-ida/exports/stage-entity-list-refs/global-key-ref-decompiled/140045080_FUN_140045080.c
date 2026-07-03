// Function: FUN_140045080 @ 140045080
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140045080(undefined4 *param_1)

{
  ulonglong uVar1;
  double dVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  double dVar5;
  double dVar6;
  longlong lVar7;
  int iVar8;
  undefined8 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 in_stack_fffffffffffffe98;
  undefined2 uVar22;
  undefined4 uVar21;
  undefined4 in_stack_fffffffffffffea0;
  undefined2 uVar24;
  uint uVar23;
  undefined1 in_stack_fffffffffffffea8 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined8 uStack_110;
  undefined8 uStack_100;
  
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffea0 >> 0x10);
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uStack_100 = 0;
  uStack_100._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar7 = DAT_140e45d80, uStack_100._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar7 + 4) == DAT_140e44308) {
        uStack_110 = *(undefined8 *)(lVar7 + 8);
        uStack_100 = *(undefined8 *)(lVar7 + 0x18);
      }
      lVar7 = *(longlong *)(lVar7 + 0x60);
    } while (lVar7 != 0);
  }
  fVar18 = (float)param_1[0xb];
  fVar20 = (float)param_1[10];
  dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18));
  dVar6 = DAT_14053a020;
  dVar5 = DAT_140539f40;
  dVar16 = DAT_140539d28;
  uVar9 = 2;
  dVar14 = dVar14 * DAT_14053aba0;
  dVar17 = 0.0;
  if (param_1[5] == 0) {
    iVar11 = param_1[3];
    dVar15 = *(double *)(param_1 + 0x12);
    if (iVar11 < 0) {
      param_1[0xc] = 0;
      dVar17 = dVar15;
    }
    else {
      if (iVar11 < 0x3c) {
        dVar17 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                       DAT_140539d28);
        dVar17 = dVar17 * (0.0 - dVar15) + dVar15;
      }
      if (iVar11 < 0x1e) {
        dVar15 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a798 * dVar6 * dVar16);
        param_1[0xc] = (float)(dVar15 * DAT_14053a598) + _DAT_140539cbc;
      }
      else if (param_1[0x15] == 1) {
        param_1[0x15] = 0;
      }
    }
    dVar15 = (double)FUN_1403307c0();
    fVar20 = (float)(dVar15 * dVar17) + fVar20;
    param_1[10] = fVar20;
    dVar15 = (double)FUN_140332d90();
    iVar11 = DAT_140e419b8;
    iVar8 = 1;
    fVar18 = (float)(dVar15 * dVar17) + fVar18;
    param_1[0xb] = fVar18;
    uVar19 = DAT_14053ac2c;
    iVar13 = (uStack_110._4_4_ % 0x640) % 0x15e;
    if (iVar11 == 0) {
      iVar8 = 0x82;
    }
    else if (iVar11 == 1) {
      iVar8 = 0x6e;
    }
    else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
      iVar8 = 100;
    }
    iVar12 = 1;
    if (iVar11 == 0) {
      iVar12 = 0x96;
    }
    else if (iVar11 == 1) {
      iVar12 = 0x3c;
    }
    else if (iVar11 == 2) {
      iVar12 = 0x32;
    }
    else if ((iVar11 == 3) || (iVar11 == 4)) {
      iVar12 = 0x28;
    }
    iVar10 = 1;
    if (iVar11 == 0) {
      iVar10 = 3;
    }
    else if (iVar11 == 1) {
      iVar10 = 5;
    }
    else if ((iVar11 == 2) || (iVar11 == 3)) {
      iVar10 = 7;
    }
    else if (iVar11 == 4) {
      iVar10 = 9;
    }
    dVar17 = DAT_14053a0b0;
    if ((((iVar11 != 0) && (dVar17 = DAT_14053a0f8, iVar11 != 1)) &&
        (dVar17 = DAT_14053a118, iVar11 != 2)) &&
       ((dVar17 = DAT_14053a158, iVar11 != 3 && (dVar17 = dVar5, iVar11 == 4)))) {
      dVar17 = DAT_14053a190;
    }
    if (((iVar8 <= iVar13) && (iVar13 < 0xf0)) &&
       (uVar1 = (longlong)(iVar13 - iVar8) % (longlong)iVar12, (int)uVar1 == 0)) {
      auVar25._12_4_ = in_stack_fffffffffffffea8._12_4_;
      auVar25._0_8_ = in_stack_fffffffffffffea8._0_8_;
      auVar25._8_4_ = 1;
      auVar26._8_8_ = auVar25._8_8_;
      auVar26._0_8_ = dVar17;
      uVar21 = DAT_14053ac2c;
      FUN_1400709b0(0xd,uVar1 & 0xffffffff,fVar20,fVar18,CONCAT22(uVar22,(short)(int)dVar14),
                    DAT_14053ac2c,dVar17,auVar26._8_8_,iVar10,iVar10 * 0x168 + -0x168,0);
      uVar24 = (undefined2)((uint)uVar21 >> 0x10);
      if (2 < DAT_140e419b8) {
        auVar27._12_4_ = auVar26._12_4_;
        auVar27._0_8_ = auVar26._0_8_;
        auVar27._8_4_ = 1;
        FUN_1400709b0(0xd,0,param_1[10],param_1[0xb],(int)dVar14 & 0xffff,uVar19,
                      dVar17 + DAT_140539f10,auVar27._8_8_,iVar10 + -1,iVar10 * 0x168 + -0x2d0,0);
        uVar24 = (undefined2)((uint)uVar19 >> 0x10);
      }
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    dVar14 = DAT_14053a890;
    dVar17 = DAT_14053a3a0;
    iVar11 = param_1[3];
    if (iVar11 < 0) {
      dVar15 = DAT_140539e60;
      dVar14 = 0.0;
      dVar2 = 0.0;
    }
    else {
      dVar15 = dVar5;
      if (iVar11 < 0x14) {
        dVar15 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a890 * dVar6 * dVar16);
        dVar15 = dVar15 * DAT_140539f38 + DAT_140539e60;
      }
      dVar2 = DAT_140539ec8;
      if (iVar11 < 10) {
        dVar14 = 0.0;
        dVar2 = 0.0;
      }
      else if (iVar11 < 0x1e) {
        dVar17 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a1e8) * dVar14 * dVar6 * dVar16);
        dVar14 = dVar17 + 0.0;
        dVar2 = 0.0;
      }
      else {
        dVar14 = dVar5;
        if (iVar11 < 0x3c) {
          dVar2 = 0.0;
        }
        else if (iVar11 < 200) {
          dVar17 = (double)FUN_140332d90(((double)iVar11 - dVar17) * _DAT_14053a490 * dVar6 * dVar16
                                        );
          dVar2 = dVar2 * dVar17 + 0.0;
        }
      }
    }
    uVar19 = (undefined4)((ulonglong)dVar15 >> 0x20);
    dVar16 = (double)FUN_140332d90(((double)iVar11 - 0.0) * _DAT_14053ab90 * dVar6 * dVar16);
    dVar17 = DAT_140539d28;
    iVar8 = 0xff;
    if (0x3b < iVar11) {
      iVar8 = 0x40;
    }
    dVar14 = dVar16 * dVar2 + 0.0 + dVar14;
    if ((0x3b < iVar11) && (iVar11 < 200)) {
      dVar16 = (double)FUN_140332d90();
      iVar8 = 0xff - (int)(dVar16 * _DAT_14053a570);
    }
    auVar4._8_4_ = SUB84(dVar14,0);
    auVar4._0_8_ = dVar14;
    auVar4._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
    uVar23 = CONCAT22(uVar24,(short)iVar11 * 0x309);
    FUN_1400c8410(DAT_140e44884,0x24,7,param_1[10],param_1[0xb],uVar23,auVar4,0xff,iVar8,iVar8,0xff,
                  1,0);
    auVar3._8_4_ = SUB84(dVar15,0);
    auVar3._0_8_ = dVar15;
    auVar3._12_4_ = uVar19;
    uVar23 = uVar23 & 0xffff0000;
    FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar23,auVar3,0xff,0xff,0xff,0xff,1,
                  0);
    dVar17 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * dVar6 * dVar17)
    ;
    uVar21 = param_1[0xb];
    in_stack_fffffffffffffea8._8_4_ = SUB84(dVar15,0);
    in_stack_fffffffffffffea8._0_8_ = dVar15;
    in_stack_fffffffffffffea8._12_4_ = uVar19;
    uVar23 = uVar23 & 0xffff0000;
    FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],uVar21,uVar23,in_stack_fffffffffffffea8,0xff,0xff
                  ,0xff,0x80 - (int)(dVar17 * DAT_14053b1c8),1,0);
    uVar22 = (undefined2)((uint)uVar21 >> 0x10);
    uVar24 = (undefined2)(uVar23 >> 0x10);
    if (param_1[0x15] == 0) {
      uVar19 = DAT_14053b360;
      FUN_140079c10(param_1,2);
      uVar22 = (undefined2)((uint)uVar19 >> 0x10);
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,3);
    if (DAT_140e44600 == 0) {
      auVar28._12_4_ = in_stack_fffffffffffffea8._12_4_;
      auVar28._0_8_ = in_stack_fffffffffffffea8._0_8_;
      auVar28._8_4_ = 10;
      in_stack_fffffffffffffea8._8_8_ = auVar28._8_8_;
      in_stack_fffffffffffffea8._0_8_ = dVar5;
      uVar19 = DAT_14053b380;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar24,0x4000),dVar5,
                 in_stack_fffffffffffffea8._8_8_,1,DAT_140e44308);
      uVar22 = (undefined2)((uint)uVar19 >> 0x10);
    }
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (param_1[3] != 200) goto LAB_1400459f2;
  iVar11 = 1;
  if (DAT_140e419b8 == 0) {
    iVar11 = 0x11;
  }
  else if (DAT_140e419b8 == 1) {
    iVar11 = 0x19;
  }
  else if (DAT_140e419b8 == 2) {
    iVar11 = 0x1f;
  }
  else if (DAT_140e419b8 == 3) {
    iVar11 = 0x17;
  }
  else if (DAT_140e419b8 == 4) {
    iVar11 = 0x1b;
  }
  dVar17 = DAT_14053a088;
  if (DAT_140e419b8 == 0) {
LAB_14004593f:
    if (2 < DAT_140e419b8) {
LAB_140045944:
      uVar9 = 4;
      auVar29._12_4_ = in_stack_fffffffffffffea8._12_4_;
      auVar29._0_8_ = in_stack_fffffffffffffea8._0_8_;
      auVar29._8_4_ = 1;
      in_stack_fffffffffffffea8._8_8_ = auVar29._8_8_;
      in_stack_fffffffffffffea8._0_8_ = dVar17 - dVar5;
      uVar19 = CONCAT22(uVar22,(short)(0x10000 / (ulonglong)(uint)(iVar11 * 2)) +
                               *(short *)(param_1 + 0x10));
      FUN_1400709b0(4,7,param_1[10],param_1[0xb],uVar19,0,dVar17 - dVar5,
                    in_stack_fffffffffffffea8._8_8_,iVar11,0x10000,0);
      uVar22 = (undefined2)((uint)uVar19 >> 0x10);
    }
  }
  else {
    dVar17 = DAT_14053a0d0;
    if ((DAT_140e419b8 != 1) && (dVar17 = DAT_14053a0f8, DAT_140e419b8 != 2)) {
      dVar17 = DAT_14053a118;
      if (DAT_140e419b8 != 3) {
        dVar17 = dVar5;
        if (DAT_140e419b8 == 4) {
          dVar17 = DAT_14053a158;
        }
        goto LAB_14004593f;
      }
      goto LAB_140045944;
    }
  }
  auVar30._12_4_ = in_stack_fffffffffffffea8._12_4_;
  auVar30._0_8_ = in_stack_fffffffffffffea8._0_8_;
  auVar30._8_4_ = 1;
  FUN_1400709b0(uVar9,7,param_1[10],param_1[0xb],CONCAT22(uVar22,*(undefined2 *)(param_1 + 0x10)),0,
                dVar17,auVar30._8_8_,iVar11,0x10000,0);
  FUN_140079e20(param_1,0);
  *param_1 = 0;
LAB_1400459f2:
  if ((uStack_100._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


