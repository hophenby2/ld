// Function: FUN_140089e00 @ 140089e00
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140089e00(undefined4 *param_1)

{
  ushort uVar1;
  short sVar2;
  double dVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  ulonglong uVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined2 uVar18;
  undefined2 uVar19;
  uint uVar20;
  undefined4 uVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined4 uVar26;
  double dVar25;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 uStackX_14;
  undefined4 in_stack_fffffffffffffec8;
  undefined2 uVar34;
  float in_stack_fffffffffffffed0;
  undefined1 in_stack_fffffffffffffed8 [16];
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
  
  uVar34 = (undefined2)((uint)in_stack_fffffffffffffec8 >> 0x10);
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar25 = DAT_14053aba0;
  dVar22 = dVar22 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    dVar3 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_14 = (undefined4)(uVar8 >> 0x20);
    in_stack_fffffffffffffed8._8_4_ = SUB84(dVar3,0);
    in_stack_fffffffffffffed8._0_8_ = dVar3;
    in_stack_fffffffffffffed8._12_4_ = (int)((ulonglong)dVar3 >> 0x20);
    in_stack_fffffffffffffed0 = (float)((uint)in_stack_fffffffffffffed0 & 0xffff0000);
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar8 & 0xffffffff,uStackX_14,in_stack_fffffffffffffed0,
                  in_stack_fffffffffffffed8,0xff,0xff,0xff,0xff,1,0);
    uVar34 = (undefined2)((uint)uStackX_14 >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4018000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar3 = DAT_140539f90;
  if (param_1[5] != 1) goto LAB_14008a8d1;
  if ((int)param_1[3] < 0xd2) {
    dVar23 = *(double *)(param_1 + 0x12);
    if (((uint)param_1[3] < 0x79) && (DAT_140539f90 < dVar23)) {
      dVar23 = dVar23 - DAT_140539e60;
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar9 = ((int)dVar22 & 0xffffU) - (uint)uVar1;
    *(double *)(param_1 + 0x12) = dVar23;
    iVar11 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar11 = iVar9;
    }
    iVar9 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar9 = iVar11;
    }
    uVar12 = (ushort)(int)dVar22;
    if (iVar9 < 1) {
      uVar10 = uVar1;
      if ((iVar9 < 0) && (uVar10 = uVar1 - 0x40, -0x40 < iVar9)) {
        uVar10 = uVar12;
      }
    }
    else {
      uVar10 = uVar12;
      if (0x3f < iVar9) {
        uVar10 = uVar1 + 0x40;
      }
    }
  }
  else {
    uVar10 = *(ushort *)(param_1 + 0x10);
    iVar9 = -(uint)uVar10 + 0xc000;
    iVar11 = -(uint)uVar10 + 0x1c000;
    if (-0x8001 < iVar9) {
      iVar11 = iVar9;
    }
    iVar9 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar9 = iVar11;
    }
    if (iVar9 < 1) {
      if ((iVar9 < 0) && (uVar10 = uVar10 - 0xa0, -0xa0 < iVar9)) {
        uVar10 = 0xc000;
      }
    }
    else if (iVar9 < 0xa0) {
      uVar10 = 0xc000;
    }
    else {
      uVar10 = uVar10 + 0xa0;
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + DAT_140539e60;
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  dVar22 = (double)FUN_1403307c0();
  fVar32 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar32;
  dVar23 = (double)FUN_140332d90();
  auVar7 = _DAT_14053bb20;
  fVar33 = DAT_14053acbc;
  fVar4 = DAT_14053ac2c;
  iVar11 = param_1[3];
  dVar22 = (double)DAT_14053bb20;
  uVar16 = (undefined4)DAT_14053bb20;
  uVar14 = DAT_14053bb20._4_4_;
  fVar31 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar31;
  if (iVar11 - 0x18U < 0xba) {
    fVar31 = fVar31 + DAT_14053acfc;
    fVar33 = fVar32 + DAT_14053acbc;
    fVar32 = fVar32 - DAT_14053acbc;
    dVar23 = (double)FUN_1403300b4();
    dVar24 = (double)FUN_1403300b4();
    iVar9 = 1;
    uVar20 = (uint)(dVar24 * dVar25);
    if (DAT_140e419b8 == 0) {
      iVar9 = 0x6e;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0x46;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar9 = 0x3c;
    }
    uVar17 = (iVar11 + -0x18) % iVar9;
    uVar27 = (undefined4)((ulonglong)DAT_14053a1c8 >> 0x20);
    uVar21 = SUB84(DAT_14053a178,0);
    uVar26 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    uVar28 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    uVar29 = SUB84(DAT_14053a0f8,0);
    uVar30 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
    if (((DAT_140e419b8 != 0) &&
        (uVar29 = SUB84(DAT_14053a138,0), uVar30 = uVar28, DAT_140e419b8 != 1)) &&
       ((uVar29 = uVar21, uVar30 = uVar26, DAT_140e419b8 != 2 &&
        ((DAT_140e419b8 != 3 && (uVar29 = uVar16, uVar30 = uVar14, DAT_140e419b8 == 4)))))) {
      uVar29 = (int)DAT_14053a1c8;
      uVar30 = uVar27;
    }
    iVar15 = 1;
    iVar11 = (iVar11 + -0x18) % (iVar9 * 2);
    if (DAT_140e419b8 == 0) {
      iVar15 = 5;
    }
    else if (DAT_140e419b8 == 1) {
LAB_14008a25b:
      iVar15 = 7;
    }
    else if (DAT_140e419b8 == 2) {
      iVar15 = 9;
    }
    else {
      if (DAT_140e419b8 == 3) goto LAB_14008a25b;
      if (DAT_140e419b8 == 4) {
        iVar15 = 0xb;
      }
    }
    dVar24 = DAT_14053a070;
    if ((((DAT_140e419b8 != 0) && (dVar24 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
        (dVar24 = DAT_14053a0f8, DAT_140e419b8 != 2)) &&
       ((dVar24 = DAT_14053a118, DAT_140e419b8 != 3 && (dVar24 = dVar22, DAT_140e419b8 == 4)))) {
      dVar24 = DAT_14053a178;
    }
    if (5 < DAT_1407c7798) {
      uVar29 = SUB84(DAT_14053a138,0);
      uVar30 = uVar28;
      if ((DAT_140e419b8 != 0) && (uVar29 = uVar21, uVar30 = uVar26, DAT_140e419b8 != 1)) {
        if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar29 = (int)DAT_14053a1b8;
          uVar30 = (int)((ulonglong)DAT_14053a1b8 >> 0x20);
        }
        else {
          uVar29 = uVar16;
          uVar30 = uVar14;
          if (DAT_140e419b8 == 4) {
            uVar29 = (int)DAT_14053a1c8;
            uVar30 = uVar27;
          }
        }
      }
      iVar15 = 1;
      if (DAT_140e419b8 == 0) {
        iVar15 = 7;
      }
      else if (DAT_140e419b8 == 1) {
LAB_14008a318:
        iVar15 = 9;
      }
      else {
        if (DAT_140e419b8 != 2) {
          if (DAT_140e419b8 == 3) goto LAB_14008a318;
          if (DAT_140e419b8 != 4) goto LAB_14008a324;
        }
        iVar15 = 0xb;
      }
LAB_14008a324:
      dVar24 = DAT_14053a0b0;
      if ((((DAT_140e419b8 != 0) && (dVar24 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar24 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((dVar24 = DAT_14053a158, DAT_140e419b8 != 3 && (dVar24 = dVar22, DAT_140e419b8 == 4)))) {
        dVar24 = DAT_14053a178;
      }
    }
    uVar18 = (undefined2)(int)(dVar23 * dVar25);
    uVar19 = (undefined2)uVar20;
    if (uVar17 == 0) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar18;
      *(undefined2 *)(param_1 + 0x11) = uVar19;
LAB_14008a398:
      auVar35._12_4_ = in_stack_fffffffffffffed8._12_4_;
      auVar35._0_8_ = in_stack_fffffffffffffed8._0_8_;
      auVar35._8_4_ = 1;
      auVar36._8_8_ = auVar35._8_8_;
      auVar36._0_8_ = CONCAT44(uVar30,uVar29);
      uVar16 = CONCAT22(uVar34,*(undefined2 *)((longlong)param_1 + 0x42));
      FUN_14006c2f0(7,0,fVar33,fVar31,uVar16,fVar4,CONCAT44(uVar30,uVar29),auVar36._8_8_,0);
      auVar37._12_4_ = auVar36._12_4_;
      auVar37._0_8_ = auVar36._0_8_;
      auVar37._8_4_ = 1;
      in_stack_fffffffffffffed8._8_8_ = auVar37._8_8_;
      in_stack_fffffffffffffed8._0_8_ = CONCAT44(uVar30,uVar29);
      uVar16 = CONCAT22((short)((uint)uVar16 >> 0x10),*(undefined2 *)(param_1 + 0x11));
      in_stack_fffffffffffffed0 = fVar4;
      FUN_14006c2f0(7,0,fVar32,fVar31,uVar16,fVar4,CONCAT44(uVar30,uVar29),
                    in_stack_fffffffffffffed8._8_8_,0);
      uVar34 = (undefined2)((uint)uVar16 >> 0x10);
      if (2 < DAT_140e419b8) {
        sVar2 = *(short *)((longlong)param_1 + 0x42);
        iVar13 = 0;
        do {
          auVar38._12_4_ = in_stack_fffffffffffffed8._12_4_;
          auVar38._0_8_ = in_stack_fffffffffffffed8._0_8_;
          auVar38._8_4_ = 1;
          in_stack_fffffffffffffed8._8_8_ = auVar38._8_8_;
          in_stack_fffffffffffffed8._0_8_ = CONCAT44(uVar30,uVar29);
          uVar16 = CONCAT22((short)((uint)uVar16 >> 0x10),(short)iVar13 * 2000 + sVar2 + -1000);
          FUN_14006c2f0(7,0,fVar33,fVar31,uVar16,fVar4,CONCAT44(uVar30,uVar29),
                        in_stack_fffffffffffffed8._8_8_,0);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
        sVar2 = *(short *)(param_1 + 0x11);
        iVar13 = 0;
        do {
          auVar39._12_4_ = in_stack_fffffffffffffed8._12_4_;
          auVar39._0_8_ = in_stack_fffffffffffffed8._0_8_;
          auVar39._8_4_ = 1;
          in_stack_fffffffffffffed8._8_8_ = auVar39._8_8_;
          in_stack_fffffffffffffed8._0_8_ = CONCAT44(uVar30,uVar29);
          uVar16 = CONCAT22((short)((uint)uVar16 >> 0x10),(short)iVar13 * 2000 + sVar2 + -1000);
          in_stack_fffffffffffffed0 = fVar4;
          FUN_14006c2f0(7,0,fVar32,fVar31,uVar16,fVar4,CONCAT44(uVar30,uVar29),
                        in_stack_fffffffffffffed8._8_8_,0);
          uVar34 = (undefined2)((uint)uVar16 >> 0x10);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
      }
    }
    else if (uVar17 < 0x18) {
      uVar17 = uVar17 & 0x80000003;
      if ((int)uVar17 < 0) {
        uVar17 = (uVar17 - 1 | 0xfffffffc) + 1;
      }
      if (uVar17 == 0) goto LAB_14008a398;
    }
    if (iVar11 == 0x20) {
      auVar40._12_4_ = in_stack_fffffffffffffed8._12_4_;
      auVar40._0_8_ = in_stack_fffffffffffffed8._0_8_;
      auVar40._8_4_ = 1;
      in_stack_fffffffffffffed8._8_8_ = auVar40._8_8_;
      in_stack_fffffffffffffed8._0_8_ = dVar24;
      in_stack_fffffffffffffed0 = 0.0;
      uVar16 = CONCAT22(uVar34,uVar18);
      FUN_1400709b0(4,0,fVar33,fVar31,uVar16,0,dVar24,in_stack_fffffffffffffed8._8_8_,iVar15,20000,0
                   );
      uVar34 = (undefined2)((uint)uVar16 >> 0x10);
      if (2 < DAT_140e419b8) {
        dVar25 = dVar24 - dVar3;
        auVar41._12_4_ = in_stack_fffffffffffffed8._12_4_;
        auVar41._0_8_ = in_stack_fffffffffffffed8._0_8_;
        auVar41._8_4_ = 1;
        in_stack_fffffffffffffed8._8_8_ = auVar41._8_8_;
        in_stack_fffffffffffffed8._0_8_ = dVar25;
        in_stack_fffffffffffffed0 = 0.0;
        uVar16 = CONCAT22(uVar34,uVar18);
        FUN_1400709b0(4,0,fVar33,fVar31,uVar16,0,dVar25,in_stack_fffffffffffffed8._8_8_,iVar15 - 1U,
                      (int)(20000 / (ulonglong)(iVar15 - 1U)) * (iVar15 + -2) & 0xffff,0);
        uVar34 = (undefined2)((uint)uVar16 >> 0x10);
      }
    }
    fVar33 = DAT_14053acbc;
    if (iVar11 == iVar9 + 0x20) {
      auVar42._12_4_ = in_stack_fffffffffffffed8._12_4_;
      auVar42._0_8_ = in_stack_fffffffffffffed8._0_8_;
      auVar42._8_4_ = 1;
      auVar43._8_8_ = auVar42._8_8_;
      auVar43._0_8_ = dVar24;
      in_stack_fffffffffffffed0 = 0.0;
      FUN_1400709b0(4,0,fVar32,fVar31,CONCAT22(uVar34,uVar19),0,dVar24,auVar43._8_8_,iVar15,20000,0)
      ;
      fVar33 = DAT_14053acbc;
      if (2 < DAT_140e419b8) {
        auVar44._12_4_ = auVar43._12_4_;
        auVar44._0_8_ = auVar43._0_8_;
        auVar44._8_4_ = 1;
        in_stack_fffffffffffffed0 = 0.0;
        FUN_1400709b0(4,0,fVar32,fVar31,uVar20 & 0xffff,0,dVar24 - dVar3,auVar44._8_8_,iVar15 - 1U,
                      (int)(20000 / (ulonglong)(iVar15 - 1U)) * (iVar15 + -2) & 0xffff,0);
        fVar33 = DAT_14053acbc;
      }
    }
  }
  uVar6 = _UNK_14053bb08;
  uVar5 = _DAT_14053bb00;
  uVar20 = param_1[3] & 0x80000003;
  if ((int)uVar20 < 0) {
    uVar20 = (uVar20 - 1 | 0xfffffffc) + 1;
  }
  uVar16 = 0;
  if ((int)uVar20 < 2) {
    uVar16 = 0xff;
  }
  uVar14 = 0x80;
  if ((int)uVar20 < 2) {
    uVar14 = 0xff;
  }
  uVar20 = (uint)in_stack_fffffffffffffed0 & 0xffff0000;
  FUN_1400c8410(DAT_140e41930,0x20,7,(float)param_1[10] + fVar33,(float)param_1[0xb] - DAT_14053acc8
                ,uVar20,_DAT_14053bb00,_UNK_14053bb08,0xff,uVar14,uVar16,0xc0,1,0);
  uVar20 = uVar20 & 0xffff0000;
  FUN_1400c8410(DAT_140e41930,0x20,7,(float)param_1[10] - fVar33,(float)param_1[0xb] - DAT_14053acc8
                ,uVar20,uVar5,uVar6,0xff,uVar14,uVar16,0xc0,1,0);
  uVar20 = uVar20 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b98,0x20,7,(float)param_1[10] + fVar33,(float)param_1[0xb] + fVar4,uVar20,
                auVar7,0xff,0xff,0xff,0xff,1,0);
  uVar20 = uVar20 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b98,0x20,7,(float)param_1[10] - fVar33,(float)param_1[0xb] + fVar4,uVar20,
                auVar7,0xff,0xff,0xff,0xff,1,1);
  FUN_1400c8410(DAT_140e44b94,0x20,7,param_1[10],param_1[0xb],uVar20 & 0xffff0000,auVar7,0xff,0xff,
                0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_14008a8d1:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
      (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b398 || (_DAT_14053af5c < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


