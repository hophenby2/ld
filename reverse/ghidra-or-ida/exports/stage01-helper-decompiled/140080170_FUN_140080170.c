// Function: FUN_140080170 @ 140080170
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140080170(undefined4 *param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  ushort uVar4;
  double dVar5;
  float fVar6;
  undefined1 auVar7 [16];
  float fVar8;
  short sVar9;
  ulonglong uVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  undefined4 uVar24;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffeb8;
  undefined2 uVar44;
  undefined4 uVar43;
  uint in_stack_fffffffffffffec0;
  undefined2 uVar46;
  uint uVar45;
  undefined1 in_stack_fffffffffffffec8 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
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
  
  uVar44 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar46 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
  dVar19 = dVar19 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    dVar21 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)(uVar10 >> 0x20);
    in_stack_fffffffffffffec8._8_4_ = SUB84(dVar21,0);
    in_stack_fffffffffffffec8._0_8_ = dVar21;
    in_stack_fffffffffffffec8._12_4_ = (int)((ulonglong)dVar21 >> 0x20);
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar10 & 0xffffffff,uStackX_c,in_stack_fffffffffffffec0,
                  in_stack_fffffffffffffec8,0xff,0xff,0xff,0xff,1,0);
    uVar46 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
    uVar44 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      bVar2 = (float)param_1[10] <= DAT_14053ae30;
      *(undefined8 *)(param_1 + 0x12) = 0x4022000000000000;
      if (bVar2) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar22 = DAT_14053a8c0;
  dVar5 = DAT_14053a020;
  dVar21 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_140080ef7;
  uVar45 = param_1[3];
  dVar20 = (double)FUN_140332d90(((double)(int)uVar45 - 0.0) * DAT_14053a8c0 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar39 = (float)dVar20 + 0.0;
  dVar21 = (double)FUN_140332d90(((double)(int)uVar45 - _DAT_14053a258) * dVar22 * dVar5 * dVar21);
  fVar41 = (float)dVar21 + 0.0;
  dVar22 = (double)FUN_140332d90();
  dVar20 = (double)FUN_140332d90();
  dVar20 = dVar20 * _DAT_14053aa18;
  dVar21 = (double)FUN_1403307c0();
  fVar16 = (float)(dVar21 * _DAT_14053a440) + 0.0;
  dVar23 = (double)FUN_140332d90();
  auVar7 = _DAT_14053bb20;
  dVar5 = DAT_140539e60;
  dVar21 = *(double *)(param_1 + 0x12);
  uVar43 = (undefined4)DAT_14053bb20;
  uVar3 = DAT_14053bb20._4_4_;
  fVar17 = (float)(dVar23 * _DAT_14053a440) + 0.0;
  if ((uVar45 < 0x79) && ((double)DAT_14053bb20 < dVar21)) {
    dVar21 = dVar21 - DAT_140539e60;
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar11 = ((int)dVar19 & 0xffffU) - (uint)uVar1;
  *(double *)(param_1 + 0x12) = dVar21;
  iVar13 = iVar11 + 0x10000;
  if (-0x8001 < iVar11) {
    iVar13 = iVar11;
  }
  iVar11 = iVar13 + -0x10000;
  if (iVar13 < 0x8001) {
    iVar11 = iVar13;
  }
  uVar4 = (ushort)(int)dVar19;
  if (iVar11 < 1) {
    uVar12 = uVar1;
    if ((iVar11 < 0) && (uVar12 = uVar1 - 0x80, -0x80 < iVar11)) {
      uVar12 = uVar4;
    }
  }
  else {
    uVar12 = uVar4;
    if (0x7f < iVar11) {
      uVar12 = uVar1 + 0x80;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar12;
  if (299 < (int)uVar45) {
    dVar21 = dVar21 - dVar5;
    *(double *)(param_1 + 0x12) = dVar21;
  }
  dVar19 = (double)FUN_1403307c0();
  fVar35 = (float)(dVar19 * dVar21) + (float)param_1[10];
  param_1[10] = fVar35;
  dVar19 = (double)FUN_140332d90();
  fVar38 = DAT_14053ac44;
  fVar40 = DAT_14053ac2c;
  fVar25 = (float)(dVar19 * dVar21) + (float)param_1[0xb];
  param_1[0xb] = fVar25;
  fVar8 = DAT_140e445dc;
  fVar6 = DAT_14053ac80;
  if (uVar45 - 0x28 < 0x104) {
    fVar42 = (fVar35 - fVar16) - fVar40;
    fVar40 = fVar35 + fVar16 + fVar40;
    fVar38 = (fVar25 + fVar41 + fVar17) - fVar38;
    dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((fVar25 + fVar39) - DAT_14053ac80)),
                                   SUB84((double)(DAT_140e445d8 - fVar35),0));
    iVar13 = 1;
    dVar19 = dVar19 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar13 = 200;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0x78;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 100;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar13 = 0x5a;
    }
    iVar11 = 1;
    uVar10 = (longlong)(int)(uVar45 - 0x28) % (longlong)iVar13;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x1e;
    }
    else if (DAT_140e419b8 == 1) {
      iVar11 = 0x28;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar11 = 0x32;
    }
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 800;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0x4b0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 0x708;
    }
    else if (DAT_140e419b8 == 3) {
      iVar13 = 0x960;
    }
    else if (DAT_140e419b8 == 4) {
      iVar13 = 3000;
    }
    uVar26 = (undefined4)DAT_14053a0f8;
    uVar27 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    uVar32 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
    uVar29 = (undefined4)DAT_14053a138;
    uVar30 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    uVar18 = (undefined4)DAT_14053a0d0;
    uVar24 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    if (DAT_140e419b8 == 0) {
      uVar36 = (int)DAT_14053a070;
      uVar37 = (int)((ulonglong)DAT_14053a070 >> 0x20);
    }
    else {
      uVar36 = uVar18;
      uVar37 = uVar24;
      if (((DAT_140e419b8 != 1) && (uVar36 = uVar26, uVar37 = uVar27, DAT_140e419b8 != 2)) &&
         ((uVar36 = uVar29, uVar37 = uVar30, DAT_140e419b8 != 3 &&
          (uVar36 = uVar43, uVar37 = uVar3, DAT_140e419b8 == 4)))) {
        uVar36 = (int)DAT_14053a190;
        uVar37 = uVar32;
      }
    }
    iVar15 = 1;
    if (DAT_140e419b8 == 0) {
      iVar15 = 5;
    }
    else if (DAT_140e419b8 == 1) {
      iVar15 = 0xb;
    }
    else if (DAT_140e419b8 == 2) {
      iVar15 = 0xf;
    }
    else if (DAT_140e419b8 == 3) {
      iVar15 = 0x11;
    }
    else if (DAT_140e419b8 == 4) {
      iVar15 = 0x13;
    }
    uVar31 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    uVar28 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
    if (DAT_140e419b8 == 0) {
      uVar33 = (int)DAT_14053a040;
      uVar34 = (int)((ulonglong)DAT_14053a040 >> 0x20);
    }
    else {
      uVar33 = (int)DAT_14053a088;
      uVar34 = uVar28;
      if (((DAT_140e419b8 != 1) && (uVar33 = uVar18, uVar34 = uVar24, DAT_140e419b8 != 2)) &&
         ((uVar33 = uVar26, uVar34 = uVar27, DAT_140e419b8 != 3 &&
          (uVar33 = uVar43, uVar34 = uVar3, DAT_140e419b8 == 4)))) {
        uVar33 = (int)DAT_14053a158;
        uVar34 = uVar31;
      }
    }
    if (4 < DAT_1407c7798) {
      uVar36 = uVar18;
      uVar37 = uVar24;
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          uVar36 = (int)DAT_14053a118;
          uVar37 = (int)((ulonglong)DAT_14053a118 >> 0x20);
        }
        else {
          uVar36 = uVar29;
          uVar37 = uVar30;
          if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
             (uVar36 = uVar43, uVar37 = uVar3, DAT_140e419b8 == 4)) {
            uVar36 = (int)DAT_14053a190;
            uVar37 = uVar32;
          }
        }
      }
      uVar33 = (int)DAT_14053a088;
      uVar34 = uVar28;
      if (((DAT_140e419b8 != 0) && (uVar33 = uVar18, uVar34 = uVar24, DAT_140e419b8 != 1)) &&
         ((uVar33 = uVar26, uVar34 = uVar27, DAT_140e419b8 != 2 &&
          ((DAT_140e419b8 != 3 && (uVar33 = uVar43, uVar34 = uVar3, DAT_140e419b8 == 4)))))) {
        uVar33 = (int)DAT_14053a158;
        uVar34 = uVar31;
      }
    }
    iVar14 = (int)uVar10;
    if (iVar14 == 0) {
      dVar21 = (double)FUN_1403300b4((double)(fVar8 - fVar38),
                                     SUB84((double)(DAT_140e445d8 - fVar40),0));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar21 * DAT_14053aba0);
      dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar38),
                                     SUB84((double)(DAT_140e445d8 - fVar42),0));
      *(short *)(param_1 + 0x11) = (short)(int)(dVar21 * DAT_14053aba0);
LAB_140080899:
      if ((iVar14 < iVar11) && ((uVar10 & 1) == 0)) {
        sVar9 = FUN_140134d00(DAT_140e418c8 * 0x6f + uVar45,-iVar13,iVar13);
        auVar47._12_4_ = in_stack_fffffffffffffec8._12_4_;
        auVar47._0_8_ = in_stack_fffffffffffffec8._0_8_;
        auVar47._8_4_ = 1;
        dVar21 = (double)iVar14 * DAT_140539e60 + (double)CONCAT44(uVar37,uVar36);
        auVar48._8_8_ = auVar47._8_8_;
        auVar48._0_8_ = dVar21;
        uVar43 = CONCAT22(uVar44,sVar9 + *(short *)((longlong)param_1 + 0x42));
        FUN_14006c2f0(5,0,fVar40,fVar38,uVar43,0,dVar21,auVar48._8_8_,0);
        uVar44 = (undefined2)((uint)uVar43 >> 0x10);
        sVar9 = FUN_140134d00(DAT_140e418c8 * 0x6f + param_1[3],-iVar13,iVar13);
        auVar49._12_4_ = auVar48._12_4_;
        auVar49._0_8_ = auVar48._0_8_;
        auVar49._8_4_ = 1;
        in_stack_fffffffffffffec8._8_8_ = auVar49._8_8_;
        in_stack_fffffffffffffec8._0_8_ = dVar21;
        uVar46 = 0;
        uVar43 = CONCAT22(uVar44,sVar9 + *(short *)(param_1 + 0x11));
        FUN_14006c2f0(5,0,fVar42,fVar38,uVar43,0,dVar21,in_stack_fffffffffffffec8._8_8_,0);
        uVar44 = (undefined2)((uint)uVar43 >> 0x10);
      }
    }
    else if (-1 < iVar14) goto LAB_140080899;
    if (((0 < iVar14) && (iVar14 < iVar11)) && ((iVar14 - 1U & 1) == 0)) {
      sVar9 = FUN_140134d00(DAT_140e418c8 * 0x6f + param_1[3],-iVar13,iVar13);
      auVar50._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar50._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar50._8_4_ = 1;
      dVar21 = (double)iVar14 * DAT_140539e60 + (double)CONCAT44(uVar37,uVar36);
      auVar51._8_8_ = auVar50._8_8_;
      auVar51._0_8_ = dVar21;
      uVar43 = CONCAT22(uVar44,sVar9 + *(short *)((longlong)param_1 + 0x42));
      FUN_14006c2f0(1,0,fVar40,fVar38,uVar43,0,dVar21,auVar51._8_8_,0);
      uVar44 = (undefined2)((uint)uVar43 >> 0x10);
      sVar9 = FUN_140134d00(DAT_140e418c8 * 0x6f + param_1[3],-iVar13,iVar13);
      auVar52._12_4_ = auVar51._12_4_;
      auVar52._0_8_ = auVar51._0_8_;
      auVar52._8_4_ = 1;
      in_stack_fffffffffffffec8._8_8_ = auVar52._8_8_;
      in_stack_fffffffffffffec8._0_8_ = dVar21;
      uVar46 = 0;
      uVar43 = CONCAT22(uVar44,sVar9 + *(short *)(param_1 + 0x11));
      FUN_14006c2f0(1,0,fVar42,fVar38,uVar43,0,dVar21,in_stack_fffffffffffffec8._8_8_,0);
      uVar44 = (undefined2)((uint)uVar43 >> 0x10);
    }
    fVar38 = DAT_14053ac44;
    if (iVar14 == 0x41) {
      iVar13 = iVar15 * 0xf0 + -0xf0;
      auVar53._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar53._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar53._8_4_ = 1;
      auVar54._8_8_ = auVar53._8_8_;
      auVar54._0_8_ = CONCAT44(uVar34,uVar33);
      uVar46 = 0;
      sVar9 = (short)(int)dVar19;
      uVar43 = CONCAT22(uVar44,sVar9);
      FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,uVar43,0,
                    CONCAT44(uVar34,uVar33),auVar54._8_8_,iVar15,iVar13,0);
      uVar44 = (undefined2)((uint)uVar43 >> 0x10);
      if (0 < DAT_140e419b8) {
        auVar55._12_4_ = auVar54._12_4_;
        auVar55._0_8_ = auVar54._0_8_;
        auVar55._8_4_ = 1;
        auVar56._8_8_ = auVar55._8_8_;
        auVar56._0_8_ = CONCAT44(uVar34,uVar33);
        uVar43 = CONCAT22(uVar44,sVar9 + 10000);
        FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,uVar43,0,
                      CONCAT44(uVar34,uVar33),auVar56._8_8_,iVar15,iVar13,0);
        auVar57._12_4_ = auVar56._12_4_;
        auVar57._0_8_ = auVar56._0_8_;
        auVar57._8_4_ = 1;
        auVar54._8_8_ = auVar57._8_8_;
        auVar54._0_8_ = CONCAT44(uVar34,uVar33);
        uVar46 = 0;
        uVar43 = CONCAT22((short)((uint)uVar43 >> 0x10),sVar9 + -10000);
        FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,uVar43,0,
                      CONCAT44(uVar34,uVar33),auVar54._8_8_,iVar15,iVar13,0);
        uVar44 = (undefined2)((uint)uVar43 >> 0x10);
      }
      fVar38 = DAT_14053ac44;
      if (2 < DAT_140e419b8) {
        dVar19 = (double)CONCAT44(uVar34,uVar33) + DAT_140539f68;
        auVar58._12_4_ = auVar54._12_4_;
        auVar58._0_8_ = auVar54._0_8_;
        auVar58._8_4_ = 1;
        auVar59._8_8_ = auVar58._8_8_;
        auVar59._0_8_ = dVar19;
        FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,CONCAT22(uVar44,sVar9),
                      0,dVar19,auVar59._8_8_,iVar15,iVar13,0);
        auVar60._12_4_ = auVar59._12_4_;
        auVar60._0_8_ = auVar59._0_8_;
        auVar60._8_4_ = 1;
        auVar61._8_8_ = auVar60._8_8_;
        auVar61._0_8_ = dVar19;
        FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,sVar9 + 10000,0,dVar19,
                      auVar61._8_8_,iVar15,iVar13,0);
        auVar62._12_4_ = auVar61._12_4_;
        auVar62._0_8_ = auVar61._0_8_;
        auVar62._8_4_ = 1;
        uVar46 = 0;
        FUN_1400709b0(4,0,param_1[10],(fVar39 + (float)param_1[0xb]) - fVar6,sVar9 + -10000,0,dVar19
                      ,auVar62._8_8_,iVar15,iVar13,0);
        fVar38 = DAT_14053ac44;
      }
    }
  }
  sVar9 = (short)(int)dVar20;
  uVar43 = CONCAT22(uVar46,sVar9);
  FUN_1400c8410(DAT_140e44b34,0x20,7,fVar16 + (float)param_1[10] + DAT_14053ac2c,
                (fVar41 + (float)param_1[0xb] + fVar17) - fVar38,uVar43,auVar7,0xff,0xff,0xff,0xff,1
                ,0);
  uVar45 = CONCAT22((short)((uint)uVar43 >> 0x10),-sVar9);
  FUN_1400c8410(DAT_140e44b34,0x20,7,((float)param_1[10] - fVar16) - DAT_14053ac2c,
                (fVar41 + (float)param_1[0xb] + fVar17) - fVar38,uVar45,auVar7,0xff,0xff,0xff,0xff,1
                ,1);
  uVar45 = uVar45 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b30,0x20,7,param_1[10],(float)dVar22 + 0.0 + (float)param_1[0xb],uVar45,
                auVar7,0xff,0xff,0xff,0xff,1,0);
  uVar45 = uVar45 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b2c,0x20,7,param_1[10],fVar41 + (float)param_1[0xb],uVar45,auVar7,0xff,
                0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44b28,0x20,7,param_1[10],fVar39 + (float)param_1[0xb],uVar45 & 0xffff0000,
                auVar7,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_140080ef7:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ae30) ||
      (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053afa0 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b400 || (DAT_14053afcc < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


