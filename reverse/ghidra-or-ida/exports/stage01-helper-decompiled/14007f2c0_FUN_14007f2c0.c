// Function: FUN_14007f2c0 @ 14007f2c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14007f2c0(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  short sVar3;
  ushort uVar4;
  double dVar5;
  undefined1 auVar6 [16];
  float fVar7;
  float fVar8;
  int iVar9;
  undefined8 uVar10;
  int iVar11;
  ushort uVar12;
  short sVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined2 *puVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffea8;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined2 uVar39;
  uint in_stack_fffffffffffffeb0;
  undefined4 uVar40;
  undefined2 uVar41;
  undefined1 in_stack_fffffffffffffeb8 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  
  uVar39 = (undefined2)((uint)in_stack_fffffffffffffea8 >> 0x10);
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar5 = DAT_14053aba0;
  dVar26 = DAT_14053a018;
  uVar41 = (undefined2)(in_stack_fffffffffffffeb0 >> 0x10);
  dVar22 = dVar22 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar10;
    dVar26 = dVar26 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    in_stack_fffffffffffffeb8._8_4_ = SUB84(dVar26,0);
    in_stack_fffffffffffffeb8._0_8_ = dVar26;
    in_stack_fffffffffffffeb8._12_4_ = (int)((ulonglong)dVar26 >> 0x20);
    in_stack_fffffffffffffeb0 = in_stack_fffffffffffffeb0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_fffffffffffffeb0,
                  in_stack_fffffffffffffeb8,0xff,0xff,0xff,0xff,1,0);
    uVar41 = (undefined2)(in_stack_fffffffffffffeb0 >> 0x10);
    uVar39 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar24 = DAT_14053a908;
  dVar28 = DAT_14053a020;
  dVar26 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_1400800ca;
  uVar15 = param_1[3];
  dVar23 = (double)FUN_140332d90();
  fVar34 = (float)(dVar23 + dVar23) - DAT_14053ac5c;
  dVar23 = (double)FUN_140332d90(((double)(int)uVar15 - _DAT_14053a298) * dVar24 * dVar28 * dVar26);
  fVar17 = (float)(dVar23 + dVar23) + 0.0;
  dVar24 = (double)FUN_140332d90(((double)(int)uVar15 - _DAT_14053a360) * dVar24 * dVar28 * dVar26);
  dVar23 = (double)FUN_140332d90();
  dVar23 = dVar23 * _DAT_14053aa40;
  dVar25 = (double)FUN_140332d90();
  dVar25 = dVar25 * _DAT_14053aa18;
  dVar26 = (double)FUN_140332d90();
  sVar13 = (short)(int)(dVar26 * _DAT_14053aa18) + 10000;
  dVar26 = (double)FUN_1403307c0();
  fVar18 = (float)(dVar26 * _DAT_14053a410) + 0.0;
  dVar26 = (double)FUN_140332d90();
  fVar19 = (float)(dVar26 * _DAT_14053a410) + 0.0;
  dVar26 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar26 * DAT_14053a3d0) + 0.0;
  dVar27 = (double)FUN_140332d90();
  dVar28 = DAT_140539e60;
  dVar26 = *(double *)(param_1 + 0x12);
  fVar21 = (float)(dVar27 * DAT_14053a3d0) + 0.0;
  if ((uVar15 < 0x79) && (DAT_140539f68 < dVar26)) {
    dVar26 = dVar26 - DAT_140539e60;
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar11 = ((int)dVar22 & 0xffffU) - (uint)uVar1;
  *(double *)(param_1 + 0x12) = dVar26;
  iVar9 = iVar11 + 0x10000;
  if (-0x8001 < iVar11) {
    iVar9 = iVar11;
  }
  iVar11 = iVar9 + -0x10000;
  if (iVar9 < 0x8001) {
    iVar11 = iVar9;
  }
  uVar4 = (ushort)(int)dVar22;
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
  if (299 < (int)uVar15) {
    dVar26 = dVar26 - dVar28;
    *(double *)(param_1 + 0x12) = dVar26;
  }
  dVar22 = (double)FUN_1403307c0();
  fVar33 = (float)(dVar22 * dVar26) + (float)param_1[10];
  param_1[10] = fVar33;
  dVar22 = (double)FUN_140332d90();
  auVar6 = _DAT_14053bb20;
  uVar29 = (undefined4)DAT_14053bb20;
  uVar30 = DAT_14053bb20._4_4_;
  fVar32 = (float)(dVar22 * dVar26) + (float)param_1[0xb];
  param_1[0xb] = fVar32;
  fVar8 = DAT_140e445dc;
  fVar7 = DAT_140e445d8;
  if (uVar15 - 0x18 < 0x114) {
    fVar35 = fVar33 + DAT_14053acc8;
    fVar31 = fVar32 + DAT_14053ac44 + fVar17;
    fVar36 = fVar33 - DAT_14053acc8;
    dVar22 = (double)FUN_1403300b4();
    dVar28 = (double)FUN_1403300b4();
    dVar27 = (double)FUN_1403300b4((double)(fVar8 - (fVar32 + fVar34)),
                                   SUB84((double)(fVar7 - fVar33),0));
    uVar40 = DAT_14053ac2c;
    dVar26 = DAT_140539fc8;
    iVar9 = 1;
    uVar15 = (int)(uVar15 - 0x18) % 0x96;
    if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
      iVar9 = 0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar9 = 0x708;
    }
    else if (DAT_140e419b8 == 3) {
      iVar9 = 0xce4;
    }
    else if (DAT_140e419b8 == 4) {
      iVar9 = 0x9c4;
    }
    if (DAT_140e419b8 == 0) {
      uVar29 = (undefined4)DAT_14053a0f8;
      uVar30 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar29 = (undefined4)DAT_14053a158;
      uVar30 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar29 = (undefined4)DAT_14053a190;
      uVar30 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar29 = (undefined4)DAT_14053a1b8;
      uVar30 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar29 = (undefined4)DAT_14053a208;
      uVar30 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
    }
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x28;
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      iVar11 = 0x1e;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar11 = 0xf;
    }
    uVar14 = 1;
    if (DAT_140e419b8 == 0) {
      uVar14 = 4;
    }
    else if (DAT_140e419b8 == 1) {
      uVar14 = 6;
    }
    else if (DAT_140e419b8 == 2) {
      uVar14 = 10;
    }
    else if (DAT_140e419b8 == 3) {
      uVar14 = 0xc;
    }
    else if (DAT_140e419b8 == 4) {
      uVar14 = 0xd;
    }
    if (uVar15 == 0) {
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar22 * dVar5);
LAB_14007f972:
      puVar16 = (undefined2 *)((longlong)param_1 + 0x42);
      auVar42._12_4_ = in_stack_fffffffffffffeb8._12_4_;
      auVar42._0_8_ = in_stack_fffffffffffffeb8._0_8_;
      auVar42._8_4_ = 1;
      in_stack_fffffffffffffeb8._8_8_ = auVar42._8_8_;
      in_stack_fffffffffffffeb8._0_8_ = CONCAT44(uVar30,uVar29);
      uVar37 = CONCAT22(uVar39,*puVar16);
      uVar38 = uVar40;
      FUN_14006c2f0(9,0,fVar35,fVar31,uVar37,uVar40,CONCAT44(uVar30,uVar29),
                    in_stack_fffffffffffffeb8._8_8_,0);
      uVar41 = (undefined2)((uint)uVar38 >> 0x10);
      uVar39 = (undefined2)((uint)uVar37 >> 0x10);
      if (1 < DAT_140e419b8) {
        dVar22 = (double)CONCAT44(uVar30,uVar29) - auVar6._0_8_;
        auVar43._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar43._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar43._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar43._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = dVar22;
        uVar37 = CONCAT22(uVar39,*puVar16);
        uVar38 = uVar40;
        FUN_1400709b0(9,0,fVar35,fVar31,uVar37,uVar40,dVar22,in_stack_fffffffffffffeb8._8_8_,2,iVar9
                      ,0);
        uVar41 = (undefined2)((uint)uVar38 >> 0x10);
        uVar39 = (undefined2)((uint)uVar37 >> 0x10);
      }
      if (3 < DAT_140e419b8) {
        dVar22 = (double)CONCAT44(uVar30,uVar29) - dVar26;
        auVar44._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar44._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar44._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar44._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = dVar22;
        uVar37 = CONCAT22(uVar39,*puVar16);
        uVar38 = uVar40;
        FUN_1400709b0(9,0,fVar35,fVar31,uVar37,uVar40,dVar22,in_stack_fffffffffffffeb8._8_8_,2,
                      iVar9 * 2,0);
        uVar41 = (undefined2)((uint)uVar38 >> 0x10);
        uVar39 = (undefined2)((uint)uVar37 >> 0x10);
      }
    }
    else if ((uVar15 < 0x1e) && (uVar15 == ((int)uVar15 / 5) * 5)) goto LAB_14007f972;
    if (uVar15 == 0x28) {
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar28 * dVar5);
LAB_14007fa9f:
      auVar45._12_4_ = in_stack_fffffffffffffeb8._12_4_;
      auVar45._0_8_ = in_stack_fffffffffffffeb8._0_8_;
      auVar45._8_4_ = 1;
      in_stack_fffffffffffffeb8._8_8_ = auVar45._8_8_;
      in_stack_fffffffffffffeb8._0_8_ = CONCAT44(uVar30,uVar29);
      uVar37 = CONCAT22(uVar39,*(undefined2 *)((longlong)param_1 + 0x42));
      uVar38 = uVar40;
      FUN_14006c2f0(9,0,fVar36,fVar31,uVar37,uVar40,CONCAT44(uVar30,uVar29),
                    in_stack_fffffffffffffeb8._8_8_,0);
      uVar41 = (undefined2)((uint)uVar38 >> 0x10);
      uVar39 = (undefined2)((uint)uVar37 >> 0x10);
      if (1 < DAT_140e419b8) {
        dVar22 = (double)CONCAT44(uVar30,uVar29) - auVar6._0_8_;
        auVar46._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar46._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar46._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar46._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = dVar22;
        uVar37 = CONCAT22(uVar39,*(undefined2 *)((longlong)param_1 + 0x42));
        uVar38 = uVar40;
        FUN_1400709b0(9,0,fVar36,fVar31,uVar37,uVar40,dVar22,in_stack_fffffffffffffeb8._8_8_,2,iVar9
                      ,0);
        uVar41 = (undefined2)((uint)uVar38 >> 0x10);
        uVar39 = (undefined2)((uint)uVar37 >> 0x10);
      }
      if (3 < DAT_140e419b8) {
        dVar26 = (double)CONCAT44(uVar30,uVar29) - dVar26;
        auVar47._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar47._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar47._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar47._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = dVar26;
        uVar38 = CONCAT22(uVar39,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(9,0,fVar36,fVar31,uVar38,uVar40,dVar26,in_stack_fffffffffffffeb8._8_8_,2,
                      iVar9 * 2,0);
        uVar41 = (undefined2)((uint)uVar40 >> 0x10);
        uVar39 = (undefined2)((uint)uVar38 >> 0x10);
      }
    }
    else if ((uVar15 - 0x28 < 0x1e) && (uVar15 - 0x28 == ((int)(uVar15 - 0x28) / 5) * 5))
    goto LAB_14007fa9f;
    if ((uVar15 - 0x50 < 0x28) &&
       (uVar2 = (longlong)(int)(uVar15 - 0x50) % (longlong)iVar11, (int)uVar2 == 0)) {
      dVar26 = (double)CONCAT44(uVar30,uVar29) - DAT_140539ff0;
      auVar48._12_4_ = in_stack_fffffffffffffeb8._12_4_;
      auVar48._0_8_ = in_stack_fffffffffffffeb8._0_8_;
      auVar48._8_4_ = 1;
      auVar49._8_8_ = auVar48._8_8_;
      auVar49._0_8_ = dVar26;
      sVar3 = (short)(int)(dVar27 * dVar5);
      FUN_1400709b0(0,uVar2 & 0xffffffff,param_1[10],fVar34 + (float)param_1[0xb],
                    CONCAT22(uVar39,sVar3 + 200),0,dVar26,auVar49._8_8_,uVar14,28000,0);
      auVar50._12_4_ = auVar49._12_4_;
      auVar50._0_8_ = auVar49._0_8_;
      auVar50._8_4_ = 1;
      uVar41 = 0;
      FUN_1400709b0(0,0,param_1[10],fVar34 + (float)param_1[0xb],sVar3 + -200,0,dVar26,auVar50._8_8_
                    ,uVar14,28000,0);
    }
  }
  uVar29 = CONCAT22(uVar41,sVar13);
  FUN_1400c8410(DAT_140e44b24,0x20,7,fVar20 + (float)param_1[10],
                fVar17 + (float)param_1[0xb] + fVar21,uVar29,auVar6,0xff,0xff,0xff,0xff,1,0);
  uVar29 = CONCAT22((short)((uint)uVar29 >> 0x10),-sVar13);
  FUN_1400c8410(DAT_140e44b24,0x20,7,(float)param_1[10] - fVar20,
                fVar17 + (float)param_1[0xb] + fVar21,uVar29,auVar6,0xff,0xff,0xff,0xff,1,1);
  sVar13 = (short)(int)dVar25;
  uVar29 = CONCAT22((short)((uint)uVar29 >> 0x10),sVar13);
  FUN_1400c8410(DAT_140e44b20,0x20,7,fVar18 + (float)param_1[10],
                fVar17 + (float)param_1[0xb] + fVar19,uVar29,auVar6,0xff,0xff,0xff,0xff,1,0);
  uVar15 = CONCAT22((short)((uint)uVar29 >> 0x10),-sVar13);
  FUN_1400c8410(DAT_140e44b20,0x20,7,(float)param_1[10] - fVar18,
                fVar17 + (float)param_1[0xb] + fVar19,uVar15,auVar6,0xff,0xff,0xff,0xff,1,1);
  uVar15 = uVar15 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b1c,0x20,7,param_1[10],
                (float)(dVar24 + dVar24) + 0.0 + (float)param_1[0xb],uVar15,auVar6,0xff,0xff,0xff,
                0xff,1,0);
  uVar15 = uVar15 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b18,0x20,7,param_1[10],fVar17 + (float)param_1[0xb],uVar15,auVar6,0xff,
                0xff,0xff,0xff,1,0);
  sVar13 = (short)(int)dVar23;
  uVar29 = CONCAT22((short)(uVar15 >> 0x10),sVar13 + -1000);
  FUN_1400c8410(DAT_140e44b14,0x20,7,(float)param_1[10] + DAT_14053acb0,
                (fVar34 + (float)param_1[0xb]) - DAT_14053accc,uVar29,auVar6,0xff,0xff,0xff,0xff,1,0
               );
  uVar15 = CONCAT22((short)((uint)uVar29 >> 0x10),1000 - sVar13);
  FUN_1400c8410(DAT_140e44b14,0x20,7,(float)param_1[10] - DAT_14053acb0,
                (fVar34 + (float)param_1[0xb]) - DAT_14053accc,uVar15,auVar6,0xff,0xff,0xff,0xff,1,1
               );
  FUN_1400c8410(DAT_140e44b10,0x20,7,param_1[10],fVar34 + (float)param_1[0xb],uVar15 & 0xffff0000,
                auVar6,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_1400800ca:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


