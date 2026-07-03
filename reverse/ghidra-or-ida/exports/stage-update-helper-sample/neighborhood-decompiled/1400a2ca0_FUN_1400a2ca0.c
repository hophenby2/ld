// Function: FUN_1400a2ca0 @ 1400a2ca0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a2ca0(undefined4 *param_1)

{
  float fVar1;
  longlong lVar2;
  ulonglong uVar3;
  double dVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  ushort uVar13;
  int iVar14;
  short sVar15;
  ushort uVar16;
  ushort uVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  float fVar30;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined4 uVar31;
  undefined2 uVar32;
  undefined4 in_stack_ffffffffffffff00;
  uint uVar33;
  undefined1 in_stack_ffffffffffffff08 [16];
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
  
  uVar32 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  uVar16 = (ushort)((uint)in_stack_ffffffffffffff00 >> 0x10);
  fVar30 = (float)param_1[10];
  fVar25 = (float)param_1[0xb];
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                 SUB84((double)(DAT_140e445d8 - fVar30),0));
  fVar18 = DAT_14053aedc;
  dVar4 = DAT_14053aba0;
  dVar24 = DAT_14053a020;
  dVar23 = DAT_140539d28;
  dVar19 = dVar19 * DAT_14053aba0;
  if (param_1[5] == 0) {
    iVar7 = param_1[3];
    if (iVar7 == 0) {
      fVar1 = (float)param_1[0xd];
      if (param_1[6] == 0x71) {
        fVar30 = (float)param_1[0xc] + DAT_14053aedc;
        param_1[0xb] = fVar1;
LAB_1400a2d9c:
        fVar25 = (float)param_1[0xb];
        param_1[10] = fVar30;
      }
      else if (param_1[6] == 0x72) {
        fVar30 = (float)param_1[0xc] - DAT_14053aedc;
        param_1[0xb] = fVar1;
        goto LAB_1400a2d9c;
      }
      param_1[0xd] = fVar1 - DAT_14053ad40;
    }
    dVar22 = (double)((float)((uint)fVar25 ^ DAT_14053bf00) * DAT_140539d58);
    dVar20 = (double)FUN_1403307c0();
    dVar21 = (double)FUN_140332d90();
    uVar8 = FUN_1401346a0(CONCAT44((float)(dVar21 * dVar22) + fVar25,
                                   (float)(dVar20 * dVar22) + fVar30),0xffffffce);
    local_res8 = (undefined4)uVar8;
    dVar22 = DAT_14053a018 - (double)iVar7 * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar22,0);
    in_stack_ffffffffffffff08._0_8_ = dVar22;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar22 >> 0x20);
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,(uint)uVar16 << 0x10,
                  in_stack_ffffffffffffff08,0xff,0xff,0xff,0xff,1,0);
    uVar32 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_1400a3895;
  iVar7 = param_1[3];
  if (iVar7 < 0x78) {
    if (param_1[6] == 0x71) {
      dVar19 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a4d8 * dVar24 * dVar23);
      dVar19 = dVar19 * _DAT_14053b268;
      fVar18 = (float)param_1[0xc] + fVar18;
LAB_1400a2f88:
      param_1[10] = (float)dVar19 + fVar18;
    }
    else if (param_1[6] == 0x72) {
      dVar19 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a4d8 * dVar24 * dVar23);
      dVar19 = dVar19 * _DAT_14053a7e0;
      fVar18 = (float)param_1[0xc] - fVar18;
      goto LAB_1400a2f88;
    }
    fVar30 = (float)param_1[0xd];
    dVar19 = (double)FUN_140332d90();
    fVar25 = fVar30 + DAT_140539da8;
    param_1[0xb] = (float)(dVar19 * _DAT_14053b158) + fVar30;
    param_1[0xd] = fVar25;
  }
  else if (iVar7 < 300) {
    if (iVar7 < 0x82) {
      *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + _DAT_140539e28;
    }
    uVar16 = *(ushort *)(param_1 + 0x10);
    iVar9 = ((int)dVar19 & 0xffffU) - (uint)uVar16;
    iVar7 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar7 = iVar9;
    }
    iVar9 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar9 = iVar7;
    }
    uVar17 = (ushort)(int)dVar19;
    if (iVar9 < 1) {
      uVar12 = uVar16;
      if ((iVar9 < 0) && (uVar12 = uVar16 - 0x80, -0x80 < iVar9)) {
        uVar12 = uVar17;
      }
    }
    else {
      uVar12 = uVar17;
      if (0x7f < iVar9) {
        uVar12 = uVar16 + 0x80;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
  }
  iVar7 = param_1[3];
  if (299 < iVar7) {
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) - DAT_140539e60;
  }
  dVar19 = (double)FUN_1403307c0();
  fVar25 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar25;
  dVar19 = (double)FUN_140332d90();
  fVar30 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar30;
  iVar9 = DAT_140e419b8;
  if (iVar7 < 300) {
    iVar7 = 1;
    if (DAT_140e419b8 == 0) {
      iVar7 = 0x96;
      iVar10 = 0;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 0x78;
      iVar10 = 0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar7 = 0x5a;
      iVar10 = 0;
    }
    else {
      iVar10 = DAT_140e419b8 + -3;
      if ((iVar10 == 0) || (iVar10 == 1)) {
        iVar7 = 0x50;
      }
    }
    fVar18 = fVar25 + DAT_14053aca8;
    fVar30 = fVar30 - DAT_14053aca8;
    fVar25 = fVar25 - DAT_14053aca8;
    dVar19 = (double)FUN_1403300b4(iVar10,SUB84((double)(DAT_140e445d8 - fVar18),0));
    dVar22 = (double)FUN_1403300b4();
    iVar10 = 1;
    if (iVar9 == 0) {
      iVar10 = 0x13;
    }
    else if ((iVar9 == 1) || (iVar9 == 2)) {
      iVar10 = 0xc;
    }
    else if (iVar9 == 3) {
      iVar10 = 10;
    }
    else if (iVar9 == 4) {
      iVar10 = 8;
    }
    uVar27 = (undefined4)DAT_14053a0f8;
    uVar29 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    uVar26 = uVar27;
    uVar28 = uVar29;
    if (iVar9 != 0) {
      if (iVar9 == 1) {
        uVar26 = (int)DAT_14053a138;
        uVar28 = (int)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else if (iVar9 == 2) {
        uVar26 = (int)DAT_14053a158;
        uVar28 = (int)((ulonglong)DAT_14053a158 >> 0x20);
      }
      else if (iVar9 == 3) {
        uVar26 = (int)DAT_14053a190;
        uVar28 = (int)((ulonglong)DAT_14053a190 >> 0x20);
      }
      else {
        uVar26 = (int)DAT_140539f40;
        uVar28 = (int)((ulonglong)DAT_140539f40 >> 0x20);
        if (iVar9 == 4) {
          uVar26 = (int)DAT_14053a1c8;
          uVar28 = (int)((ulonglong)DAT_14053a1c8 >> 0x20);
        }
      }
    }
    iVar11 = param_1[3];
    lVar2 = (longlong)(iVar11 + -0x46) % (longlong)iVar7;
    iVar14 = (int)lVar2;
    sVar15 = (short)lVar2;
    uVar17 = (ushort)(int)(dVar22 * dVar4);
    uVar16 = (ushort)(int)(dVar19 * dVar4);
    if ((iVar11 - 0x46U < 0xe6) && (iVar14 == 0)) {
      *(ushort *)(param_1 + 0x11) = uVar17;
      *(ushort *)((longlong)param_1 + 0x42) = uVar16;
LAB_1400a326e:
      uVar5 = DAT_14053ac2c;
      uVar3 = (longlong)(iVar11 + -0x46) % (longlong)iVar7;
      uVar3 = (longlong)((ulonglong)(uint)((int)uVar3 >> 0x1f) << 0x20 | uVar3 & 0xffffffff) %
              (longlong)iVar10;
      if ((int)uVar3 == 0) {
        auVar34._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar34._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar34._8_4_ = 1;
        auVar35._8_8_ = auVar34._8_8_;
        auVar35._0_8_ = CONCAT44(uVar28,uVar26);
        uVar31 = CONCAT22(uVar32,*(short *)((longlong)param_1 + 0x42) + sVar15 * -0x20);
        FUN_14006c2f0(9,uVar3 & 0xffffffff,fVar18,fVar30,uVar31,DAT_14053ac2c,
                      CONCAT44(uVar28,uVar26),auVar35._8_8_,0);
        auVar36._12_4_ = auVar35._12_4_;
        auVar36._0_8_ = auVar35._0_8_;
        auVar36._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar36._8_8_;
        in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar28,uVar26);
        uVar31 = CONCAT22((short)((uint)uVar31 >> 0x10),sVar15 * 0x20 + *(short *)(param_1 + 0x11));
        FUN_14006c2f0(9,0,fVar25,fVar30,uVar31,uVar5,CONCAT44(uVar28,uVar26),
                      in_stack_ffffffffffffff08._8_8_,0);
        uVar32 = (undefined2)((uint)uVar31 >> 0x10);
        iVar9 = DAT_140e419b8;
        if (1 < DAT_140e419b8) {
          auVar37._12_4_ = in_stack_ffffffffffffff08._12_4_;
          auVar37._0_8_ = in_stack_ffffffffffffff08._0_8_;
          auVar37._8_4_ = 1;
          auVar38._8_8_ = auVar37._8_8_;
          auVar38._0_8_ = CONCAT44(uVar28,uVar26);
          uVar31 = CONCAT22(uVar32,*(short *)((longlong)param_1 + 0x42) + sVar15 * -0x20 + -4000);
          FUN_14006c2f0(9,0,fVar18,fVar30,uVar31,uVar5,CONCAT44(uVar28,uVar26),auVar38._8_8_,0);
          auVar39._12_4_ = auVar38._12_4_;
          auVar39._0_8_ = auVar38._0_8_;
          auVar39._8_4_ = 1;
          in_stack_ffffffffffffff08._8_8_ = auVar39._8_8_;
          in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar28,uVar26);
          uVar31 = CONCAT22((short)((uint)uVar31 >> 0x10),
                            (sVar15 + 0x7d) * 0x20 + *(short *)(param_1 + 0x11));
          FUN_14006c2f0(9,0,fVar25,fVar30,uVar31,uVar5,CONCAT44(uVar28,uVar26),
                        in_stack_ffffffffffffff08._8_8_,0);
          uVar32 = (undefined2)((uint)uVar31 >> 0x10);
          iVar9 = DAT_140e419b8;
        }
      }
    }
    else if ((iVar11 - 0x46U < 0xe6) && (iVar14 < 0x32)) goto LAB_1400a326e;
    uVar12 = *(ushort *)((longlong)param_1 + 0x42);
    iVar11 = ((int)(dVar19 * dVar4) & 0xffffU) - (uint)uVar12;
    iVar10 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar10 = iVar11;
    }
    iVar11 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar11 = iVar10;
    }
    if (iVar11 < 1) {
      uVar13 = uVar12;
      if ((iVar11 < 0) && (uVar13 = uVar12 - 0x10, -0x10 < iVar11)) {
        uVar13 = uVar16;
      }
    }
    else {
      uVar13 = uVar16;
      if (0xf < iVar11) {
        uVar13 = uVar12 + 0x10;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar13;
    uVar16 = *(ushort *)(param_1 + 0x11);
    iVar11 = ((int)(dVar22 * dVar4) & 0xffffU) - (uint)uVar16;
    iVar10 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar10 = iVar11;
    }
    iVar11 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar11 = iVar10;
    }
    if (iVar11 < 1) {
      uVar12 = uVar16;
      if ((iVar11 < 0) && (uVar12 = uVar16 - 0x10, -0x10 < iVar11)) {
        uVar12 = uVar17;
      }
    }
    else {
      uVar12 = uVar17;
      if (0xf < iVar11) {
        uVar12 = uVar16 + 0x10;
      }
    }
    fVar25 = (float)param_1[0xb] - DAT_14053ac80;
    fVar30 = (float)param_1[10];
    *(ushort *)(param_1 + 0x11) = uVar12;
    dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                   SUB84((double)(DAT_140e445d8 - fVar30),0));
    iVar10 = 1;
    if (iVar9 == 0) {
      iVar10 = 3;
    }
    else if (((iVar9 == 1) || (iVar9 == 2)) || (iVar9 == 3)) {
      iVar10 = 5;
    }
    else if (iVar9 == 4) {
      iVar10 = 7;
    }
    if (iVar9 == 0) {
      uVar27 = (undefined4)DAT_14053a078;
      uVar29 = (undefined4)((ulonglong)DAT_14053a078 >> 0x20);
    }
    else if (iVar9 == 1) {
      uVar27 = (undefined4)DAT_14053a0b0;
      uVar29 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    }
    else if (((iVar9 != 2) && (iVar9 != 3)) &&
            (uVar27 = (int)DAT_140539f40, uVar29 = (int)((ulonglong)DAT_140539f40 >> 0x20),
            iVar9 == 4)) {
      uVar27 = (undefined4)DAT_14053a138;
      uVar29 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    }
    if ((param_1[3] - 0x7d < 0xaf) &&
       (uVar3 = (longlong)(param_1[3] + -0x7d) % (longlong)iVar7, (int)uVar3 == 0)) {
      auVar40._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar40._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar40._8_4_ = 1;
      in_stack_ffffffffffffff08._8_8_ = auVar40._8_8_;
      in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar29,uVar27);
      FUN_1400709b0(4,uVar3 & 0xffffffff,fVar30,fVar25,CONCAT22(uVar32,(short)(int)(dVar19 * dVar4))
                    ,0,CONCAT44(uVar29,uVar27),in_stack_ffffffffffffff08._8_8_,iVar10,12000,0);
      if (2 < DAT_140e419b8) {
        dVar22 = (double)CONCAT44(uVar29,uVar27) + DAT_140539f68;
        auVar41._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar41._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar41._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar41._8_8_;
        in_stack_ffffffffffffff08._0_8_ = dVar22;
        FUN_1400709b0(4,0,fVar30,fVar25,(int)(dVar19 * dVar4) & 0xffff,0,dVar22,
                      in_stack_ffffffffffffff08._8_8_,iVar10 - 1U,
                      (int)(12000 / (ulonglong)(iVar10 - 1U)) * (iVar10 + -2) & 0xffff,0);
      }
    }
  }
  auVar42._12_4_ = in_stack_ffffffffffffff08._12_4_;
  auVar42._0_8_ = in_stack_ffffffffffffff08._0_8_;
  auVar42._8_4_ = 0x6f;
  auVar43._4_12_ = auVar42._4_12_;
  auVar43._0_4_ = 0x70;
  uVar32 = 0;
  iVar7 = FUN_1400c9580(param_1[3],0,5,4,0x6e,0x6f,auVar43);
  dVar23 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053aa48 * dVar24 * dVar23)
  ;
  dVar23 = dVar23 * _DAT_14053aa18;
  dVar24 = (double)FUN_140332d90();
  uVar6 = _UNK_14053bb28;
  uVar8 = _DAT_14053bb20;
  fVar30 = DAT_14053ac4c;
  sVar15 = (short)(int)(dVar24 * _DAT_14053aa18);
  uVar27 = CONCAT22(uVar32,sVar15);
  FUN_1400c8410(DAT_140e44c98,0x20,7,param_1[10],(float)param_1[0xb] - DAT_14053ac4c,uVar27,
                _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
  uVar27 = CONCAT22((short)((uint)uVar27 >> 0x10),-sVar15);
  FUN_1400c8410(DAT_140e44c98,0x20,7,param_1[10],(float)param_1[0xb] - fVar30,uVar27,uVar8,uVar6,
                0xff,0xff,0xff,0xff,1,1);
  sVar15 = (short)(int)dVar23;
  uVar27 = CONCAT22((short)((uint)uVar27 >> 0x10),sVar15);
  FUN_1400c8410(DAT_140e44c94,0x20,7,param_1[10],(float)param_1[0xb] - fVar30,uVar27,uVar8,uVar6,
                0xff,0xff,0xff,0xff,1,0);
  uVar33 = CONCAT22((short)((uint)uVar27 >> 0x10),-sVar15);
  FUN_1400c8410(DAT_140e44c94,0x20,7,param_1[10],(float)param_1[0xb] - fVar30,uVar33,uVar8,uVar6,
                0xff,0xff,0xff,0xff,1,1);
  FUN_1400c8410((&DAT_140e44ad0)[iVar7],0x20,7,param_1[10],param_1[0xb],uVar33 & 0xffff0000,uVar8,
                uVar6,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_1400a3895:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
        (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) &&
     ((param_1[5] == 1 && (0x95 < (int)param_1[3])))) {
    *param_1 = 0;
  }
  return;
}


