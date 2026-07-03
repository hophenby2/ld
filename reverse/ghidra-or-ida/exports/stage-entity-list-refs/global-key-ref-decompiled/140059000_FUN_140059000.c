// Function: FUN_140059000 @ 140059000
// Decompile completed: true

void FUN_140059000(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  undefined1 auVar6 [16];
  double dVar7;
  double dVar8;
  double dVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  float fVar13;
  undefined4 uVar14;
  float fVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 uVar21;
  float fVar22;
  float fVar23;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffe98;
  undefined2 uVar24;
  uint in_stack_fffffffffffffea0;
  ushort uVar25;
  undefined1 in_stack_fffffffffffffea8 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined8 uStack_110;
  undefined8 uStack_100;
  undefined8 uStack_f0;
  
  fVar13 = DAT_14053ae30;
  dVar8 = DAT_140539f40;
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar25 = (ushort)(in_stack_fffffffffffffea0 >> 0x10);
  uStack_100 = 0;
  uStack_100._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar10 = DAT_140e45d80, uStack_100._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar10 + 4) == DAT_140e44308) {
        uStack_110 = *(undefined8 *)(lVar10 + 8);
        uStack_100 = *(undefined8 *)(lVar10 + 0x18);
        uStack_f0 = *(undefined8 *)(lVar10 + 0x28);
      }
      lVar10 = *(longlong *)(lVar10 + 0x60);
    } while (lVar10 != 0);
  }
  uVar19 = SUB84(DAT_14053a020,0);
  uVar21 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar14 = SUB84(DAT_140539d28,0);
  uVar16 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  fVar23 = DAT_140e445d8 / DAT_14053ab70;
  fVar22 = DAT_14053ab70;
  dVar4 = DAT_140539f40;
  if (param_1[5] == 0) {
    iVar3 = param_1[3];
    if (iVar3 == 0) {
      param_1[0xd] = uStack_f0._4_4_;
      uVar14 = SUB84(DAT_140539d28,0);
      uVar16 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      param_1[0xc] = (undefined4)uStack_f0;
    }
    fVar22 = DAT_14053ac2c;
    if (fVar13 <= (float)param_1[0xe]) {
      fVar22 = DAT_14053aebc;
    }
    fVar22 = fVar23 + fVar22;
    param_1[0xe] = fVar22;
    uVar14 = SUB84((double)iVar3 * DAT_14053a628 * DAT_14053a020 * (double)CONCAT44(uVar16,uVar14),0
                  );
    dVar5 = (double)FUN_140332d90(uVar14);
    fVar13 = (float)param_1[0xc];
    fVar15 = (float)param_1[0xc];
    dVar18 = (double)FUN_140332d90(uVar14);
    dVar9 = DAT_14053a020;
    fVar20 = (float)param_1[0xf];
    fVar1 = (float)param_1[0xd];
    uVar19 = SUB84(DAT_14053a020,0);
    uVar21 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    dVar7 = (double)iVar3 - 0.0;
    fVar2 = (float)param_1[0xd];
    uVar14 = SUB84((double)(ushort)(((short)DAT_140e418c8 * 2 - (short)iVar3) * 0x168) *
                   DAT_14053a020 * DAT_140539d28,0);
    dVar4 = (double)FUN_140332d90(SUB84(dVar7 * DAT_14053a798 * DAT_14053a020 * DAT_140539d28,0));
    dVar17 = (double)((float)(dVar4 * DAT_14053a460) + 0.0);
    dVar4 = (double)FUN_1403307c0(uVar14);
    fVar13 = (float)(dVar4 * dVar17) + (float)(dVar5 * (double)(fVar22 - fVar13)) + fVar15;
    dVar4 = (double)FUN_140332d90(uVar14);
    param_1[10] = fVar13;
    param_1[0xb] = (float)(dVar4 * dVar17) + (float)(dVar18 * (double)(fVar20 - fVar1)) + fVar2;
    if (iVar3 < 0) {
      dVar4 = 0.0;
    }
    else {
      dVar4 = dVar8;
      if (iVar3 < 0x3c) {
        dVar4 = (double)FUN_140332d90(SUB84(dVar7 * DAT_14053a628 * dVar9 * DAT_140539d28,0));
        dVar4 = dVar4 + 0.0;
      }
    }
    uVar14 = param_1[0xb];
    in_stack_fffffffffffffea8._8_4_ = SUB84(dVar4,0);
    in_stack_fffffffffffffea8._0_8_ = dVar4;
    in_stack_fffffffffffffea8._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    in_stack_fffffffffffffea0 = (uint)uVar25 << 0x10;
    FUN_1400c8410(DAT_140e44904,0x24,7,fVar13,uVar14,in_stack_fffffffffffffea0,
                  in_stack_fffffffffffffea8,0xff,0xff,0xff,0xff,1,0);
    fVar13 = DAT_14053ae30;
    fVar22 = DAT_14053ab70;
    uVar24 = (undefined2)((uint)uVar14 >> 0x10);
    uVar14 = SUB84(DAT_140539d28,0);
    uVar16 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    if (param_1[3] == 0x3c) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  iVar3 = param_1[5];
  if (0 < iVar3) {
    uVar25 = *(ushort *)(param_1 + 0x10);
    uVar14 = SUB84((double)uVar25 * (double)CONCAT44(uVar21,uVar19) *
                   (double)CONCAT44(uVar16,uVar14),0);
    dVar5 = (double)FUN_1403307c0(uVar14);
    fVar20 = (float)(dVar5 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar20;
    dVar5 = (double)FUN_140332d90(uVar14);
    fVar15 = (float)(dVar5 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar15;
    if ((iVar3 == 1) || (iVar3 == 3)) {
      fVar1 = DAT_14053ac2c;
      if (fVar13 <= fVar20) {
        fVar1 = DAT_14053aebc;
      }
      fVar20 = fVar23 + fVar1;
      param_1[10] = fVar20;
    }
    if ((((fVar20 < DAT_140e445d8 / fVar22 - DAT_14053ac2c) ||
         (DAT_140e445d8 / fVar22 + DAT_14053aec4 < fVar20)) || (fVar15 < DAT_14053b320)) ||
       (DAT_14053af1c < fVar15)) {
      if (iVar3 < 4) {
        if (param_1[6] == 0x10f) {
          *(ushort *)(param_1 + 0x10) = uVar25 + 0xc000;
        }
        else if (param_1[6] == 0x110) {
          *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + 0x4000;
        }
        uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),10);
        param_1[5] = param_1[5] + 1;
        local_res8 = (undefined4)uVar11;
        uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
        param_1[10] = local_res8;
        param_1[0xb] = uStackX_c;
      }
      else {
        *param_1 = 0;
      }
    }
    if ((-1 < (int)param_1[3]) && ((param_1[3] & 1) == 0)) {
      fVar13 = (float)param_1[0xb];
      fVar23 = (float)param_1[10];
      dVar5 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar13),0),
                                    SUB84((double)(DAT_140e445d8 - fVar23),0));
      dVar5 = dVar5 * DAT_14053aba0;
      dVar18 = (double)(uStack_110._4_4_ + -0x5a) * DAT_140539d90 + DAT_14053a0b0;
      uVar12 = (undefined2)(int)dVar5;
      if (param_1[6] == 0x10f) {
        auVar26._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar26._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar26._8_4_ = 1;
        auVar27._8_8_ = auVar26._8_8_;
        auVar27._0_8_ = dVar18;
        uVar14 = CONCAT22(uVar24,uVar12);
        FUN_14006c2f0(0xd,0,fVar23,fVar13,uVar14,0,dVar18,auVar27._8_8_,0);
        auVar28._12_4_ = auVar27._12_4_;
        auVar28._0_8_ = auVar27._0_8_;
        auVar28._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar28._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar18 + dVar8;
        in_stack_fffffffffffffea0 = 0;
        uVar14 = CONCAT22((short)((uint)uVar14 >> 0x10),uVar12);
        FUN_14006c2f0(0xd,0,param_1[10],param_1[0xb],uVar14,0,dVar18 + dVar8,
                      in_stack_fffffffffffffea8._8_8_,0);
        uVar24 = (undefined2)((uint)uVar14 >> 0x10);
        fVar13 = (float)param_1[0xb];
        fVar23 = (float)param_1[10];
      }
      if (param_1[6] == 0x110) {
        auVar29._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar29._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar29._8_4_ = 1;
        auVar30._8_8_ = auVar29._8_8_;
        auVar30._0_8_ = dVar18;
        FUN_14006c2f0(0xc,0,fVar23,fVar13,CONCAT22(uVar24,uVar12),0,dVar18,auVar30._8_8_,0);
        auVar31._12_4_ = auVar30._12_4_;
        auVar31._0_8_ = auVar30._0_8_;
        auVar31._8_4_ = 1;
        in_stack_fffffffffffffea0 = 0;
        FUN_14006c2f0(0xc,0,param_1[10],param_1[0xb],(int)dVar5 & 0xffff,0,dVar18 + dVar8,
                      auVar31._8_8_,0);
      }
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    auVar6._8_4_ = SUB84(dVar4,0);
    auVar6._0_8_ = dVar4;
    auVar6._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    FUN_1400c8410(DAT_140e44904,0x24,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffea0 & 0xffff0000,auVar6,0xff,0xff,0xff,0xff,1,0);
    if ((((float)param_1[10] < DAT_140e445d8 / fVar22 - DAT_14053ad9c) ||
        (DAT_140e445d8 / fVar22 + DAT_14053af38 < (float)param_1[10])) ||
       (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
      *param_1 = 0;
    }
  }
  if ((uStack_100._4_4_ < 1) || (DAT_140e4430c < 1)) {
    *param_1 = 0;
  }
  return;
}


