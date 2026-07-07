// Function: FUN_14007c9c0 @ 14007c9c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14007c9c0(undefined4 *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  ushort uVar11;
  undefined4 uVar12;
  uint uVar13;
  short sVar14;
  float fVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  undefined2 uVar26;
  undefined2 uVar28;
  undefined4 uVar27;
  undefined1 in_stack_fffffffffffffed8 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  
  dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  iVar10 = DAT_140e44acc;
  dVar17 = dVar17 * DAT_14053aba0;
  auVar29._4_12_ = in_stack_fffffffffffffed8._4_12_;
  auVar29._0_4_ = 0xe;
  uVar28 = 0;
  uVar26 = 0;
  iVar5 = FUN_1400c9580(DAT_140e44acc + param_1[1] * 5,0,6,3,0xc,0xd,auVar29);
  dVar21 = DAT_14053a020;
  dVar20 = DAT_140539d28;
  uVar13 = param_1[1];
  dVar18 = (double)FUN_140332d90(((double)(int)(iVar10 + uVar13 * 5) - 0.0) * DAT_14053ab78 *
                                 DAT_14053a020 * DAT_140539d28);
  dVar4 = DAT_140539f40;
  dVar18 = dVar18 * DAT_14053aa78;
  uVar11 = (ushort)(int)dVar17;
  if (param_1[5] == 0) {
    fVar25 = (float)param_1[0xc];
    uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
    dVar19 = (double)FUN_1403307c0();
    fVar24 = (float)param_1[0xd];
    fVar15 = (float)(dVar19 * DAT_14053a650) + fVar25;
    dVar19 = (double)FUN_140332d90();
    iVar10 = param_1[3];
    fVar16 = (float)(dVar19 * DAT_14053a650) + fVar24;
    if (iVar10 < 0) {
      dVar19 = 0.0;
    }
    else {
      dVar19 = dVar4;
      if (iVar10 < 0x78) {
        dVar19 = (double)FUN_140332d90(((double)iVar10 - 0.0) * DAT_14053a4d8 * dVar21 * dVar20);
        dVar19 = dVar19 + 0.0;
      }
    }
    dVar20 = (double)FUN_140332d90();
    dVar21 = (double)FUN_140332d90();
    param_1[10] = (float)(dVar20 * (double)(fVar25 - fVar15)) + fVar15;
    uVar12 = 7;
    param_1[0xb] = (float)(dVar21 * (double)(fVar24 - fVar16)) + fVar16;
    fVar25 = DAT_14053ac44;
    if (iVar10 != 0x78) goto LAB_14007d27a;
    *(undefined8 *)(param_1 + 0x12) = 0x3fe999999999999a;
    *(ushort *)(param_1 + 0x10) = uVar11;
    param_1[3] = 0;
    param_1[5] = 1;
    param_1[0x15] = 0;
  }
  else {
    uVar12 = 0x23;
    fVar25 = DAT_14053ac44;
    dVar19 = DAT_140539f40;
    if (param_1[5] != 1) goto LAB_14007d27a;
  }
  iVar10 = param_1[3];
  uVar8 = *(ushort *)(param_1 + 0x10);
  if (iVar10 < 300) {
    iVar6 = ((int)dVar17 & 0xffffU) - (uint)uVar8;
    iVar7 = iVar6 + 0x10000;
    if (-0x8001 < iVar6) {
      iVar7 = iVar6;
    }
    iVar6 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar6 = iVar7;
    }
    if (iVar6 < 1) {
      uVar9 = uVar8;
      if ((iVar6 < 0) && (uVar9 = uVar8 - 0x100, -0x100 < iVar6)) {
        uVar9 = uVar11;
      }
    }
    else {
      uVar9 = uVar11;
      if (0xff < iVar6) {
        uVar9 = uVar8 + 0x100;
      }
    }
  }
  else {
    iVar7 = -(uint)uVar8;
    iVar6 = iVar7 + 0xc000;
    iVar7 = iVar7 + 0x1c000;
    if (-0x8001 < iVar6) {
      iVar7 = iVar6;
    }
    iVar6 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar6 = iVar7;
    }
    if (iVar6 < 1) {
      if ((iVar6 < 0) && (uVar8 = uVar8 - 0x100, -0x100 < iVar6)) {
        uVar8 = 0xc000;
      }
    }
    else if (iVar6 < 0x100) {
      uVar8 = 0xc000;
    }
    else {
      uVar8 = uVar8 + 0x100;
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + DAT_140539e60;
    uVar9 = uVar8;
  }
  *(ushort *)(param_1 + 0x10) = uVar9;
  dVar20 = (double)FUN_1403307c0();
  fVar15 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar15;
  dVar20 = (double)FUN_140332d90();
  fVar24 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar24;
  if (iVar10 < 300) {
    dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar24 - fVar25)),
                                   (double)(DAT_140e445d8 - fVar15));
    iVar7 = 1;
    dVar20 = dVar20 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar7 = 0x14;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 10;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar7 = 0;
    }
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x96;
    }
    else if (DAT_140e419b8 == 1) {
      iVar6 = 0x78;
    }
    else if (DAT_140e419b8 == 2) {
      iVar6 = 0x3c;
    }
    else if (DAT_140e419b8 == 3) {
      iVar6 = 0x28;
    }
    else if (DAT_140e419b8 == 4) {
      iVar6 = 0x20;
    }
    dVar21 = DAT_14053a070;
    if (((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
       ((dVar21 = DAT_14053a118, DAT_140e419b8 != 2 &&
        ((dVar21 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar21 = dVar4, DAT_140e419b8 == 4)))))) {
      dVar21 = DAT_14053a178;
    }
    if (7 < DAT_1407c7798) {
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0x78;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0x5a;
      }
      else if (DAT_140e419b8 == 2) {
        iVar6 = 0x32;
      }
      else if (DAT_140e419b8 == 3) {
        iVar6 = 0x28;
      }
      else if (DAT_140e419b8 == 4) {
        iVar6 = 0x20;
      }
      dVar21 = DAT_14053a0b0;
      if ((((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar21 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((dVar21 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar21 = dVar4, DAT_140e419b8 == 4)))) {
        dVar21 = DAT_14053a178;
      }
    }
    if (iVar7 <= iVar10) {
      uVar11 = (ushort)(int)dVar20;
      if ((iVar10 - iVar7) % iVar6 == 0) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar11;
        iVar6 = (iVar10 - iVar7) % iVar6;
      }
      else if ((iVar10 < iVar7) || (iVar6 = (iVar10 - iVar7) % iVar6, 0x13 < iVar6))
      goto LAB_14007d27a;
      if (iVar6 == (iVar6 / 3 + (iVar6 >> 0x1f) +
                   (int)(((longlong)iVar6 / 3 + ((longlong)iVar6 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                   3) {
        iVar10 = 0;
        auVar30._12_4_ = auVar29._12_4_;
        auVar30._0_8_ = auVar29._0_8_;
        auVar30._8_4_ = 1;
        auVar31._8_8_ = auVar30._8_8_;
        auVar31._0_8_ = dVar21;
        FUN_14006c2f0(4,0,fVar15 + DAT_14053aa20,fVar24 - DAT_14053ac58,
                      CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42)),0,dVar21,
                      auVar31._8_8_,0);
        auVar32._12_4_ = auVar31._12_4_;
        auVar32._0_8_ = auVar31._0_8_;
        auVar32._8_4_ = 1;
        auVar33._8_8_ = auVar32._8_8_;
        auVar33._0_8_ = dVar21;
        FUN_14006c2f0(4,0,(float)param_1[10] - DAT_14053aa20,(float)param_1[0xb] - DAT_14053ac58,
                      *(undefined2 *)((longlong)param_1 + 0x42),0,dVar21,auVar33._8_8_,0);
        auVar34._12_4_ = auVar33._12_4_;
        auVar34._0_8_ = auVar33._0_8_;
        auVar34._8_4_ = 1;
        auVar35._8_8_ = auVar34._8_8_;
        auVar35._0_8_ = dVar21;
        uVar28 = 0;
        FUN_14006c2f0(4,0,param_1[10],(float)param_1[0xb] - fVar25,
                      *(undefined2 *)((longlong)param_1 + 0x42),0,dVar21,auVar35._8_8_,0);
        if (2 < DAT_140e419b8) {
          auVar36._12_4_ = auVar35._12_4_;
          auVar36._0_8_ = auVar35._0_8_;
          auVar36._8_4_ = 1;
          auVar35._8_8_ = auVar36._8_8_;
          auVar35._0_8_ = dVar21 + DAT_140539fc8;
          uVar28 = 0;
          FUN_14006c2f0(4,0,param_1[10],(float)param_1[0xb] - fVar25,
                        *(undefined2 *)((longlong)param_1 + 0x42),0,dVar21 + DAT_140539fc8,
                        auVar35._8_8_,0);
        }
        if (3 < DAT_140e419b8) {
          fVar24 = (float)param_1[0xb];
          sVar14 = *(short *)((longlong)param_1 + 0x42);
          uVar22 = param_1[10];
          do {
            auVar37._12_4_ = auVar35._12_4_;
            auVar37._0_8_ = auVar35._0_8_;
            auVar37._8_4_ = 1;
            auVar35._8_8_ = auVar37._8_8_;
            auVar35._0_8_ = dVar21;
            uVar28 = 0;
            FUN_14006c2f0(4,0,uVar22,fVar24 - fVar25,(short)iVar10 * 0x8ae + sVar14 + -0x457,0,
                          dVar21,auVar35._8_8_,0);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 2);
        }
        uVar8 = *(ushort *)((longlong)param_1 + 0x42);
        iVar7 = ((int)dVar20 & 0xffffU) - (uint)uVar8;
        iVar10 = iVar7 + 0x10000;
        if (-0x8001 < iVar7) {
          iVar10 = iVar7;
        }
        iVar7 = iVar10 + -0x10000;
        if (iVar10 < 0x8001) {
          iVar7 = iVar10;
        }
        if (iVar7 < 1) {
          if ((iVar7 < 0) && (uVar8 = uVar8 - 0x40, -0x40 < iVar7)) {
            uVar8 = uVar11;
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar8;
        }
        else if (iVar7 < 0x40) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar11;
        }
        else {
          *(ushort *)((longlong)param_1 + 0x42) = uVar8 + 0x40;
        }
      }
    }
  }
LAB_14007d27a:
  uVar23 = (undefined4)((ulonglong)dVar19 >> 0x20);
  uVar22 = SUB84(dVar19,0);
  auVar1._8_4_ = uVar22;
  auVar1._0_8_ = dVar19;
  auVar1._12_4_ = uVar23;
  sVar14 = (short)(int)dVar18;
  uVar27 = CONCAT22(uVar28,sVar14);
  FUN_1400c8410(DAT_140e44b0c,uVar12,7,param_1[10],(float)param_1[0xb] - DAT_14053ac44,uVar27,auVar1
                ,0xff,0xff,0xff,0xff,1,0);
  auVar2._8_4_ = uVar22;
  auVar2._0_8_ = dVar19;
  auVar2._12_4_ = uVar23;
  uVar13 = CONCAT22((short)((uint)uVar27 >> 0x10),-sVar14);
  FUN_1400c8410(DAT_140e44b0c,uVar12,7,param_1[10],(float)param_1[0xb] - DAT_14053ac44,uVar13,auVar2
                ,0xff,0xff,0xff,0xff,1,1);
  auVar3._8_4_ = uVar22;
  auVar3._0_8_ = dVar19;
  auVar3._12_4_ = uVar23;
  FUN_1400c8410((&DAT_140e44ad0)[iVar5],uVar12,7,param_1[10],param_1[0xb],uVar13 & 0xffff0000,auVar3
                ,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,400,5);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053acd4) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053aeec < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b368)) || (_DAT_14053af3c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


