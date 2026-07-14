// Function: FUN_14008e710 @ 14008e710
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008e710(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  undefined1 auVar3 [16];
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined8 uVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 in_stack_fffffffffffffed8;
  undefined2 uVar28;
  undefined4 in_stack_fffffffffffffee0;
  undefined4 uVar29;
  undefined2 uVar30;
  undefined1 in_stack_fffffffffffffee8 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined8 in_stack_fffffffffffffef8;
  ulonglong uVar38;
  
  auVar3 = _DAT_14053bb20;
  fVar1 = DAT_14053b380;
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffee0 >> 0x10);
  uVar13 = (uint)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  uVar28 = (undefined2)((uint)in_stack_fffffffffffffed8 >> 0x10);
  uVar15 = (undefined4)DAT_14053bb20;
  uVar22 = DAT_14053bb20._4_4_;
  fVar23 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar23;
  if ((param_1[5] != 0) || (fVar23 < fVar1)) {
    if (param_1[5] != 1) goto LAB_14008ee35;
  }
  else {
    param_1[5] = 1;
    param_1[3] = 0;
  }
  dVar20 = DAT_14053a020;
  uVar10 = *(ushort *)(param_1 + 0x10);
  fVar1 = (float)param_1[10];
  dVar17 = (double)uVar10 * DAT_14053a020 * DAT_140539d28;
  dVar16 = (double)FUN_1403307c0(dVar17);
  dVar16 = dVar16 * DAT_14053a460;
  dVar17 = (double)FUN_140332d90(dVar17);
  dVar17 = dVar17 * DAT_14053a460;
  dVar18 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),(double)(DAT_140e445d8 - fVar1));
  iVar7 = param_1[3];
  uVar14 = (uint)(dVar18 * DAT_14053aba0);
  uVar5 = (ushort)uVar14;
  uVar4 = uVar5;
  if (iVar7 == 0x3c) {
    param_1[0x15] = 0;
LAB_14008e868:
    if (DAT_14053ae2c <= fVar23) goto LAB_14008ec3a;
    dVar18 = (double)(ushort)(uVar10 + 0xce4) * dVar20 * DAT_140539d28;
    dVar19 = (double)FUN_1403307c0(dVar18);
    dVar2 = DAT_14053a510;
    fVar26 = (float)(dVar19 * DAT_14053a510) + fVar1;
    dVar18 = (double)FUN_140332d90(dVar18);
    fVar27 = (float)(dVar18 * dVar2) + fVar23;
    dVar20 = (double)(ushort)(uVar10 - 0xce4) * dVar20 * DAT_140539d28;
    dVar18 = (double)FUN_1403307c0(dVar20);
    fVar25 = (float)(dVar18 * dVar2) + fVar1;
    dVar20 = (double)FUN_140332d90(dVar20);
    uVar29 = DAT_14053ac2c;
    iVar8 = 1;
    fVar24 = (float)(dVar20 * dVar2) + fVar23;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x78;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x50;
    }
    else if (DAT_140e419b8 == 2) {
      iVar8 = 0x46;
    }
    else if (DAT_140e419b8 == 3) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x2d;
    }
    iVar12 = 1;
    if (DAT_140e419b8 == 0) {
      iVar12 = 0x10;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0x14;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar12 = 0x18;
    }
    uVar11 = 1;
    if (DAT_140e419b8 == 0) {
LAB_14008ea41:
      uVar15 = (undefined4)DAT_14053a0d0;
      uVar22 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
LAB_14008ea49:
      uVar9 = (iVar7 + -0x3c) % iVar8;
      if ((int)uVar9 < iVar12) {
        uVar9 = uVar9 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if (uVar9 == 0) {
          uVar21 = CONCAT44(uVar13,uVar11);
          auVar31._12_4_ = in_stack_fffffffffffffee8._12_4_;
          auVar31._0_8_ = in_stack_fffffffffffffee8._0_8_;
          auVar31._8_4_ = 1;
          auVar32._8_8_ = auVar31._8_8_;
          auVar32._0_8_ = CONCAT44(uVar22,uVar15);
          FUN_1400709b0(7,0,fVar26,fVar27,CONCAT22(uVar28,uVar10),DAT_14053ac2c,
                        CONCAT44(uVar22,uVar15),auVar32._8_8_,uVar21,0x578,0);
          uVar38 = CONCAT44((int)((ulonglong)uVar21 >> 0x20),uVar11);
          auVar33._12_4_ = auVar32._12_4_;
          auVar33._0_8_ = auVar32._0_8_;
          auVar33._8_4_ = 1;
          auVar34._8_8_ = auVar33._8_8_;
          auVar34._0_8_ = CONCAT44(uVar22,uVar15);
          uVar11 = uVar29;
          FUN_1400709b0(7,0,fVar25,fVar24,*(undefined2 *)(param_1 + 0x10),uVar29,
                        CONCAT44(uVar22,uVar15),auVar34._8_8_,uVar38,0x578,0);
          uVar30 = (undefined2)((uint)uVar11 >> 0x10);
          uVar13 = (uint)(uVar38 >> 0x20);
          if (2 < DAT_140e419b8) {
            dVar20 = (double)CONCAT44(uVar22,uVar15) + DAT_140539fc8;
            uVar38 = uVar38 & 0xffffffff00000000;
            auVar35._12_4_ = auVar34._12_4_;
            auVar35._0_8_ = auVar34._0_8_;
            auVar35._8_4_ = 1;
            auVar36._8_8_ = auVar35._8_8_;
            auVar36._0_8_ = dVar20;
            FUN_14006c2f0(7,0,fVar26,fVar27,*(undefined2 *)(param_1 + 0x10),uVar29,dVar20,
                          auVar36._8_8_,uVar38);
            uVar38 = uVar38 & 0xffffffff00000000;
            auVar37._12_4_ = auVar36._12_4_;
            auVar37._0_8_ = auVar36._0_8_;
            auVar37._8_4_ = 1;
            FUN_14006c2f0(7,0,fVar25,fVar24,*(undefined2 *)(param_1 + 0x10),uVar29,dVar20,
                          auVar37._8_8_,uVar38);
            uVar30 = (undefined2)((uint)uVar29 >> 0x10);
            uVar13 = (uint)(uVar38 >> 0x20);
          }
        }
      }
    }
    else {
      if ((DAT_140e419b8 != 1) &&
         (((DAT_140e419b8 == 2 || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)))) {
        uVar11 = 2;
      }
      if (DAT_140e419b8 == 0) goto LAB_14008ea41;
      if (DAT_140e419b8 == 1) {
        uVar15 = (undefined4)DAT_14053a118;
        uVar22 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
        goto LAB_14008ea49;
      }
      if (DAT_140e419b8 == 2) {
        uVar15 = (undefined4)DAT_14053a158;
        uVar22 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
        goto LAB_14008ea49;
      }
      if (DAT_140e419b8 == 3) {
        uVar15 = (undefined4)DAT_14053a178;
        uVar22 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
        goto LAB_14008ea49;
      }
      if (DAT_140e419b8 == 4) {
        uVar15 = (undefined4)DAT_14053a1e8;
        uVar22 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
        goto LAB_14008ea49;
      }
      if (0x3b < iVar7) goto LAB_14008ea49;
    }
    uVar10 = *(ushort *)(param_1 + 0x10);
    if (iVar12 < (param_1[3] + -0x3c) % iVar8) {
      uVar6 = uVar5 - uVar10;
      uVar9 = (uint)uVar6;
      if (0x8000 < uVar6) {
        uVar9 = 0x10000 - uVar6;
      }
      iVar8 = (uVar14 & 0xffff) - (uint)uVar10;
      iVar12 = (int)uVar9 / 10 + 0x30;
      iVar7 = iVar8 + 0x10000;
      if (-0x8001 < iVar8) {
        iVar7 = iVar8;
      }
      iVar8 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar8 = iVar7;
      }
      if (0 < iVar8) {
        if (iVar8 < iVar12) goto LAB_14008ecb9;
        goto LAB_14008ec9e;
      }
      uVar4 = uVar10;
      if ((iVar8 < 0) && (uVar4 = uVar5, iVar8 <= -iVar12)) goto LAB_14008ecb5;
      goto LAB_14008ecb9;
    }
  }
  else {
    if (0x3b < iVar7) goto LAB_14008e868;
LAB_14008ec3a:
    uVar6 = uVar5 - uVar10;
    uVar9 = (uint)uVar6;
    if (0x8000 < uVar6) {
      uVar9 = 0x10000 - uVar6;
    }
    iVar8 = (uVar14 & 0xffff) - (uint)uVar10;
    iVar12 = (int)uVar9 / 10 + 0x30;
    iVar7 = iVar8 + 0x10000;
    if (-0x8001 < iVar8) {
      iVar7 = iVar8;
    }
    iVar8 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar8 = iVar7;
    }
    if (iVar8 < 1) {
      uVar4 = uVar10;
      if ((iVar8 < 0) && (uVar4 = uVar5, iVar8 <= -iVar12)) {
LAB_14008ecb5:
        uVar4 = uVar10 - (short)iVar12;
      }
    }
    else if (iVar12 <= iVar8) {
LAB_14008ec9e:
      uVar4 = uVar10 + (short)iVar12;
    }
LAB_14008ecb9:
    uVar10 = uVar4;
    *(ushort *)(param_1 + 0x10) = uVar10;
  }
  uVar15 = CONCAT22(uVar30,uVar10);
  FUN_1400c8410(DAT_140e44bb8,0x18,7,(float)param_1[10] + DAT_14053ac48,
                (float)param_1[0xb] + DAT_14053ac28,uVar15,auVar3,(ulonglong)uVar13 << 0x20,0,0,0x40
                ,1,0);
  uVar15 = CONCAT22((short)((uint)uVar15 >> 0x10),*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e44bb8,0x1a,7,param_1[10],param_1[0xb],uVar15,auVar3,0xff,0xff,0xff,0xff,1,0)
  ;
  uVar15 = CONCAT22((short)((uint)uVar15 >> 0x10),*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e44bbc,0x1a,7,(float)dVar16 + fVar1,(float)dVar17 + fVar23,uVar15,auVar3,0xff
                ,0xff,0xff,0xff,1,0);
  uVar30 = (undefined2)((uint)uVar15 >> 0x10);
  FUN_140079c10(param_1,1);
  fVar23 = (float)param_1[0xb];
LAB_14008ee35:
  if ((int)param_1[7] < 1) {
    uVar14 = param_1[1] + DAT_140e418c8;
    uVar13 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar13 = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
    DAT_140e9fd1c = uVar13;
    uVar21 = FUN_140134db0(uVar14,auVar3._0_8_,DAT_140539f58);
    uVar15 = (undefined4)uVar21;
    uVar22 = (undefined4)((ulonglong)uVar21 >> 0x20);
    uVar21 = FUN_140134db0(uVar14);
    FUN_140070d00(0x37,DAT_140e41a88,0x15,param_1[10],fVar23,
                  CONCAT22(uVar30,(short)uVar13 - (short)(uVar13 / 0x10001)),auVar3._0_8_,uVar21,
                  CONCAT44(uVar22,uVar15),0x78,0xff,0xff,0xff,0xc0,0);
    FUN_14007b010(param_1,1000,10);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (DAT_14053af80 <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


