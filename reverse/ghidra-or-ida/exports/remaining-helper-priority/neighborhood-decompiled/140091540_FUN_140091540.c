// Function: FUN_140091540 @ 140091540
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140091540(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  undefined1 auVar4 [16];
  float fVar5;
  int iVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  undefined8 *puVar17;
  ushort uVar18;
  short sVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  undefined4 local_res8;
  undefined4 uStackX_c;
  uint in_stack_fffffffffffffec0;
  undefined2 uVar35;
  undefined1 in_stack_fffffffffffffec8 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  fVar1 = DAT_14053af14;
  dVar3 = DAT_14053aba0;
  dVar21 = DAT_140539e60;
  uVar35 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
  piVar15 = param_1 + 5;
  dVar20 = dVar20 * DAT_14053aba0;
  uVar18 = (ushort)(int)dVar20;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar7;
    dVar2 = DAT_140539fc8 - (double)(int)param_1[3] * dVar21;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    in_stack_fffffffffffffec8._8_4_ = SUB84(dVar2,0);
    in_stack_fffffffffffffec8._0_8_ = dVar2;
    in_stack_fffffffffffffec8._12_4_ = (int)((ulonglong)dVar2 >> 0x20);
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_fffffffffffffec0,
                  in_stack_fffffffffffffec8,0xff,0xff,0xff,0xff,1,0);
    uVar9 = DAT_140e418c8;
    uVar35 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
    piVar15 = param_1 + 5;
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x402e000000000000;
      if ((float)param_1[10] <= 0.0) {
        uVar16 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar16 = uVar16 * 0x800 ^ uVar16;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar16) >> 8 ^ DAT_140e9fd18 ^ uVar16;
        *(short *)(param_1 + 0x10) =
             ((short)(DAT_140e9fd1c / 0x1389) * 0x1389 - (short)DAT_140e9fd1c) + -9000;
      }
      if (fVar1 <= (float)param_1[10]) {
        uVar16 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
        uVar9 = uVar16 * 0x800 ^ uVar16;
        DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
        *(short *)(param_1 + 0x10) =
             (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x1389) * -0x1389 + -0x5cd8;
      }
      piVar15 = param_1 + 5;
      puVar17 = (undefined8 *)(param_1 + 10);
      uVar7 = FUN_1401346a0(*puVar17,0xffffffec);
      *piVar15 = *piVar15 + 1;
      local_res8 = (undefined4)uVar7;
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
      *(undefined4 *)puVar17 = local_res8;
      *(undefined4 *)((longlong)puVar17 + 4) = uStackX_c;
      param_1[3] = 0;
    }
  }
  auVar4 = _DAT_14053bb20;
  if (*piVar15 != 1) goto LAB_14009215b;
  iVar13 = param_1[3];
  uVar11 = *(ushort *)(param_1 + 0x10);
  uVar32 = (undefined4)DAT_14053bb20;
  uVar33 = DAT_14053bb20._4_4_;
  dVar2 = (double)DAT_14053bb20;
  if (iVar13 < 0xc9) {
    uVar9 = (int)dVar20 & 0xffff;
    if (iVar13 < 0x50) {
      dVar21 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a5a0 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar14 = uVar9 - uVar11;
      iVar6 = iVar14 + 0x10000;
      if (-0x8001 < iVar14) {
        iVar6 = iVar14;
      }
      iVar8 = (int)(dVar21 * DAT_14053a840);
      iVar14 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar14 = iVar6;
      }
      if (iVar14 < 1) {
        uVar10 = uVar11;
        if ((iVar14 < 0) && (uVar10 = uVar11 - (short)iVar8, -iVar8 < iVar14)) {
          uVar10 = uVar18;
        }
      }
      else {
        uVar10 = uVar18;
        if (iVar8 <= iVar14) {
          uVar10 = uVar11 + (short)iVar8;
        }
      }
      dVar21 = *(double *)(param_1 + 0x12);
      *(ushort *)(param_1 + 0x10) = uVar10;
      if ((-1 < iVar13) && (dVar2 < dVar21)) {
        dVar21 = dVar21 - DAT_140539eb8;
      }
      goto LAB_140091a2c;
    }
    iVar14 = uVar9 - uVar11;
    iVar6 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar6 = iVar14;
    }
    iVar14 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar14 = iVar6;
    }
    if (iVar14 < 1) {
      uVar10 = uVar11;
      if ((iVar14 < 0) && (uVar10 = uVar11 - 0x80, -0x80 < iVar14)) {
        uVar10 = uVar18;
      }
    }
    else {
      uVar10 = uVar18;
      if (0x7f < iVar14) {
        uVar10 = uVar11 + 0x80;
      }
    }
    dVar21 = *(double *)(param_1 + 0x12);
    *(ushort *)(param_1 + 0x10) = uVar10;
    if (iVar13 == 0x50) {
      param_1[0x15] = 0;
    }
  }
  else {
    iVar6 = -(uint)uVar11;
    iVar14 = iVar6 + 0xc000;
    iVar6 = iVar6 + 0x1c000;
    if (-0x8001 < iVar14) {
      iVar6 = iVar14;
    }
    iVar14 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar14 = iVar6;
    }
    if (iVar14 < 1) {
      if ((iVar14 < 0) && (uVar11 = uVar11 - 200, -200 < iVar14)) {
        uVar11 = 0xc000;
      }
    }
    else if (iVar14 < 200) {
      uVar11 = 0xc000;
    }
    else {
      uVar11 = uVar11 + 200;
    }
    dVar21 = *(double *)(param_1 + 0x12) + dVar21;
    *(ushort *)(param_1 + 0x10) = uVar11;
LAB_140091a2c:
    *(double *)(param_1 + 0x12) = dVar21;
  }
  dVar20 = (double)FUN_1403307c0();
  fVar34 = (float)(dVar20 * dVar21) + (float)param_1[10];
  param_1[10] = fVar34;
  dVar22 = (double)FUN_140332d90();
  dVar20 = DAT_14053a278;
  fVar31 = (float)(dVar22 * dVar21) + (float)param_1[0xb];
  param_1[0xb] = fVar31;
  if (iVar13 < 200) {
    dVar21 = (double)FUN_1403307c0();
    fVar34 = (float)(dVar21 * dVar20) + fVar34;
    dVar21 = (double)FUN_140332d90();
    fVar5 = DAT_140e445d8;
    fVar31 = (float)(dVar21 * dVar20) + fVar31;
    dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar31),
                                   SUB84((double)(DAT_140e445d8 - fVar34),0));
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x3c;
    }
    else if (DAT_140e419b8 == 1) {
      iVar6 = 0x28;
    }
    else if (DAT_140e419b8 == 2) {
      iVar6 = 0x1e;
    }
    else if (DAT_140e419b8 == 3) {
      iVar6 = 0x18;
    }
    else if (DAT_140e419b8 == 4) {
      iVar6 = 0x10;
    }
    if (DAT_140e419b8 == 0) {
      uVar32 = (undefined4)DAT_14053a070;
      uVar33 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar32 = (undefined4)DAT_14053a0b8;
      uVar33 = (undefined4)((ulonglong)DAT_14053a0b8 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar32 = (undefined4)DAT_14053a118;
      uVar33 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar32 = (undefined4)DAT_14053a158;
      uVar33 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar32 = (undefined4)DAT_14053a1b8;
      uVar33 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
    }
    if ((((0x4f < iVar13) && ((iVar13 + -0x50) % iVar6 == 0)) &&
        (fVar5 / DAT_14053ab70 + 0.0 <= fVar34)) &&
       (((fVar34 <= fVar5 / DAT_14053ab70 + DAT_14053aec0 && (0.0 <= fVar31)) && (fVar31 <= fVar1)))
       ) {
      sVar12 = (short)(((int)(dVar21 * dVar3) & 0xffffU) + 0x400 >> 0xb);
      if (2 < DAT_140e419b8) {
        dVar21 = (double)CONCAT44(uVar33,uVar32) - DAT_140539f00;
        iVar13 = 0;
        do {
          auVar36._12_4_ = in_stack_fffffffffffffec8._12_4_;
          auVar36._0_8_ = in_stack_fffffffffffffec8._0_8_;
          auVar36._8_4_ = 1;
          in_stack_fffffffffffffec8._8_8_ = auVar36._8_8_;
          in_stack_fffffffffffffec8._0_8_ = dVar21;
          FUN_14006c2f0(4,0,fVar34,fVar31,(short)iVar13 * 0x5dc + sVar12 * 0x800 + -0x2ee,0,dVar21,
                        in_stack_fffffffffffffec8._8_8_,0);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
      }
      iVar13 = 0;
      sVar12 = sVar12 * 0x800;
      do {
        auVar37._12_4_ = in_stack_fffffffffffffec8._12_4_;
        auVar37._0_8_ = in_stack_fffffffffffffec8._0_8_;
        auVar37._8_4_ = 1;
        in_stack_fffffffffffffec8._8_8_ = auVar37._8_8_;
        in_stack_fffffffffffffec8._0_8_ = CONCAT44(uVar33,uVar32);
        FUN_14006c2f0(4,0,fVar34,fVar31,(short)iVar13 * 400 + sVar12 + -200,0,
                      CONCAT44(uVar33,uVar32),in_stack_fffffffffffffec8._8_8_,0);
        iVar13 = iVar13 + 1;
      } while (iVar13 < 2);
      auVar38._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar38._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar38._8_4_ = 1;
      uVar35 = 0;
      FUN_14006c2f0(4,0,fVar34,fVar31,sVar12,0,(double)CONCAT44(uVar33,uVar32) + DAT_140539ee0,
                    auVar38._8_8_,0);
    }
  }
  sVar12 = *(short *)(param_1 + 0x10);
  fVar1 = (float)param_1[10];
  iVar6 = 0x22;
  dVar22 = (double)FUN_1403307c0();
  dVar22 = dVar22 * DAT_14053b0f0;
  fVar31 = (float)param_1[0xb];
  dVar23 = (double)FUN_140332d90();
  dVar23 = dVar23 * DAT_14053b0f0;
  dVar24 = (double)FUN_1403307c0();
  dVar25 = (double)FUN_140332d90();
  iVar13 = param_1[3];
  dVar21 = (double)FUN_140332d90(((double)iVar13 - 0.0) * _DAT_14053a9a0 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar21 = dVar21 * DAT_140539e60 + dVar2;
  dVar26 = (double)FUN_1403307c0();
  dVar3 = DAT_14053a1e8;
  dVar26 = dVar26 * DAT_14053a1e8;
  dVar27 = (double)FUN_140332d90();
  dVar28 = (double)FUN_1403307c0();
  dVar29 = (double)FUN_140332d90();
  dVar30 = (double)FUN_140332d90();
  dVar30 = dVar30 * _DAT_14053ab20;
  if ((0x45 < iVar13) && (iVar13 < 0x50)) {
    uVar35 = 0;
    iVar6 = FUN_1400c9580(iVar13,0x46,5,2,0x23,0x24);
    sVar12 = *(short *)(param_1 + 0x10);
  }
  if (0x4f < (int)param_1[3]) {
    iVar6 = 0x25;
  }
  sVar19 = (short)(int)dVar30;
  FUN_1400c8410(DAT_140e446fc,0x23,7,(float)dVar26 + fVar1,(float)(dVar27 * dVar3) + fVar31,
                CONCAT22(uVar35,sVar12 + sVar19 + 0x4000),auVar4,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e446fc,0x23,7,(float)(dVar28 * dVar3) + fVar1,
                (float)(dVar29 * dVar3) + fVar31,(*(short *)(param_1 + 0x10) - sVar19) + 0x4000,
                auVar4,0xff,0xff,0xff,0xff,1,1);
  FUN_1400c8410(DAT_140e446f8,0x23,7,(float)dVar22 + fVar1,(float)dVar23 + fVar31,
                *(undefined2 *)(param_1 + 0x10),dVar2,dVar21,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410((&DAT_140e44660)[iVar6],0x23,7,(float)(dVar24 * dVar20) + fVar1,
                (float)(dVar25 * dVar20) + fVar31,*(undefined2 *)(param_1 + 0x10),dVar2,dVar21,0xff,
                0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
LAB_14009215b:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,3);
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


