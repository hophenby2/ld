// Function: FUN_140085f70 @ 140085f70
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140085f70(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;
  double dVar3;
  uint uVar4;
  float fVar5;
  undefined1 auVar6 [16];
  undefined2 uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  double dVar18;
  double dVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined4 uVar34;
  undefined2 uVar35;
  uint in_stack_ffffffffffffff00;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  
  fVar5 = DAT_14053ae30;
  uVar35 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  iVar16 = 0;
  if (param_1[5] == 0) {
    uVar9 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    dVar18 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)(uVar9 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar18,0);
    in_stack_ffffffffffffff08._0_8_ = dVar18;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar18 >> 0x20);
    in_stack_ffffffffffffff00 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar9 & 0xffffffff,uStackX_c,in_stack_ffffffffffffff00,
                  in_stack_ffffffffffffff08,0xff,0xff,0xff,0xff,1,0);
    uVar35 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4004000000000000;
      uVar7 = 0x6890;
      if ((float)param_1[10] <= fVar5) {
        uVar7 = 6000;
      }
      *(undefined2 *)(param_1 + 0x10) = uVar7;
      uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffff9c);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar10;
      uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] == 1) {
    iVar14 = param_1[3];
    dVar18 = (double)FUN_140332d90(((double)iVar14 - 0.0) * _DAT_14053a928 * DAT_14053a020 *
                                   DAT_140539d28);
    auVar6 = _DAT_14053bb20;
    uVar13 = *(ushort *)(param_1 + 0x10);
    uVar34 = (undefined4)DAT_14053bb20;
    uVar2 = DAT_14053bb20._4_4_;
    iVar12 = -(uint)uVar13 + 0xc000;
    dVar18 = dVar18 * _DAT_140539e28;
    iVar8 = -(uint)uVar13 + 0x1c000;
    if (-0x8001 < iVar12) {
      iVar8 = iVar12;
    }
    dVar3 = (double)DAT_14053bb20;
    iVar12 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar12 = iVar8;
    }
    if (iVar12 < 1) {
      if ((iVar12 < 0) && (uVar13 = uVar13 - 0x14, -0x14 < iVar12)) {
        uVar13 = 0xc000;
      }
    }
    else if (iVar12 < 0x14) {
      uVar13 = 0xc000;
    }
    else {
      uVar13 = uVar13 + 0x14;
    }
    *(ushort *)(param_1 + 0x10) = uVar13;
    dVar19 = (double)FUN_1403307c0();
    fVar32 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar32;
    dVar19 = (double)FUN_140332d90();
    fVar33 = (float)(dVar19 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar33;
    fVar31 = DAT_140e445d8;
    fVar33 = fVar33 + DAT_14053ac80;
    dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar33),
                                   SUB84((double)(DAT_140e445d8 - fVar32),0));
    iVar8 = 1;
    dVar19 = dVar19 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar8 = 100;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x50;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x36;
    }
    iVar12 = 1;
    if (DAT_140e419b8 == 0) {
      iVar12 = 0x15;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0x1e;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar12 = 0x24;
    }
    uVar21 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    uVar23 = (undefined4)((ulonglong)DAT_14053a1f8 >> 0x20);
    uVar22 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
    uVar24 = (undefined4)DAT_14053a118;
    uVar25 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    uVar26 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    uVar29 = (int)DAT_14053a0d0;
    uVar30 = uVar26;
    if (((DAT_140e419b8 != 0) && (uVar29 = uVar24, uVar30 = uVar25, DAT_140e419b8 != 1)) &&
       ((uVar29 = (int)DAT_14053a178, uVar30 = uVar21, DAT_140e419b8 != 2 &&
        ((uVar29 = (int)DAT_14053a1b8, uVar30 = uVar22, DAT_140e419b8 != 3 &&
         (uVar29 = uVar34, uVar30 = uVar2, DAT_140e419b8 == 4)))))) {
      uVar29 = (int)DAT_14053a1f8;
      uVar30 = uVar23;
    }
    uVar15 = 1;
    if (DAT_140e419b8 == 0) {
      uVar15 = 4;
    }
    else if (DAT_140e419b8 == 1) {
      uVar15 = 8;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      uVar15 = 10;
    }
    else if (DAT_140e419b8 == 4) {
      uVar15 = 0xc;
    }
    uVar17 = (undefined4)DAT_14053a0b0;
    uVar20 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    uVar27 = uVar17;
    uVar28 = uVar20;
    if (DAT_140e419b8 == 0) {
      uVar27 = (int)DAT_14053a040;
      uVar28 = (int)((ulonglong)DAT_14053a040 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar27 = (int)DAT_14053a088;
      uVar28 = (int)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
            (uVar27 = uVar34, uVar28 = uVar2, DAT_140e419b8 == 4)) {
      uVar27 = uVar24;
      uVar28 = uVar25;
    }
    if (7 < DAT_1407c7798) {
      if (DAT_140e419b8 == 0) {
        uVar29 = (int)DAT_14053a110;
        uVar30 = (int)((ulonglong)DAT_14053a110 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar29 = (int)DAT_14053a140;
        uVar30 = (int)((ulonglong)DAT_14053a140 >> 0x20);
      }
      else {
        uVar29 = (int)DAT_14053a178;
        uVar30 = uVar21;
        if (((DAT_140e419b8 != 2) &&
            (uVar29 = (int)DAT_14053a1b8, uVar30 = uVar22, DAT_140e419b8 != 3)) &&
           (uVar29 = uVar34, uVar30 = uVar2, DAT_140e419b8 == 4)) {
          uVar29 = (int)DAT_14053a1f8;
          uVar30 = uVar23;
        }
      }
      if (DAT_140e419b8 == 0) {
        uVar27 = (int)DAT_14053a070;
        uVar28 = (int)((ulonglong)DAT_14053a070 >> 0x20);
      }
      else {
        uVar27 = uVar17;
        uVar28 = uVar20;
        if (((DAT_140e419b8 != 1) &&
            (uVar27 = (int)DAT_14053a0d0, uVar28 = uVar26, DAT_140e419b8 != 2)) &&
           ((uVar27 = uVar17, uVar28 = uVar20, DAT_140e419b8 != 3 &&
            (uVar27 = uVar34, uVar28 = uVar2, DAT_140e419b8 == 4)))) {
          uVar27 = uVar24;
          uVar28 = uVar25;
        }
      }
    }
    uVar7 = (undefined2)(int)dVar19;
    if ((iVar14 - 0x2dU < 0xff) && ((iVar14 + -0x2d) % iVar8 == 0)) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar7;
      fVar31 = DAT_140e445d8;
    }
    uVar4 = DAT_14053ac2c;
    if ((((fVar31 / DAT_14053ab70 + 0.0 <= fVar32) &&
         (fVar32 <= fVar31 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= (float)param_1[0xb])) &&
       ((float)param_1[0xb] <= DAT_14053af14)) {
      if (((iVar14 - 0x2dU < 0xff) && (iVar14 = (iVar14 + -0x2d) % iVar8, iVar14 < iVar12)) &&
         (iVar14 == (iVar14 / 3 + (iVar14 >> 0x1f) +
                    (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3)) {
        auVar36._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar36._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar36._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar36._8_8_;
        in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar30,uVar29);
        uVar34 = CONCAT22(uVar35,*(undefined2 *)((longlong)param_1 + 0x42));
        in_stack_ffffffffffffff00 = DAT_14053ac2c;
        FUN_14006c2f0(9,0,fVar32,fVar33,uVar34,DAT_14053ac2c,CONCAT44(uVar30,uVar29),
                      in_stack_ffffffffffffff08._8_8_,0);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        if ((2 < DAT_140e419b8) || (7 < DAT_1407c7798)) {
          sVar1 = *(short *)((longlong)param_1 + 0x42);
          do {
            auVar37._12_4_ = in_stack_ffffffffffffff08._12_4_;
            auVar37._0_8_ = in_stack_ffffffffffffff08._0_8_;
            auVar37._8_4_ = 1;
            in_stack_ffffffffffffff08._8_8_ = auVar37._8_8_;
            in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar30,uVar29);
            uVar34 = CONCAT22((short)((uint)uVar34 >> 0x10),(short)iVar16 * 7000 + sVar1 + -0xdac);
            in_stack_ffffffffffffff00 = uVar4;
            FUN_14006c2f0(9,0,fVar32,fVar33,uVar34,uVar4,CONCAT44(uVar30,uVar29),
                          in_stack_ffffffffffffff08._8_8_,0);
            uVar35 = (undefined2)((uint)uVar34 >> 0x10);
            iVar16 = iVar16 + 1;
          } while (iVar16 < 2);
        }
      }
      if ((param_1[3] - 0x55 < 0xd7) &&
         (uVar9 = (longlong)(param_1[3] + -0x55) % (longlong)iVar8, (int)uVar9 == 0)) {
        auVar38._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar38._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar38._8_4_ = 1;
        auVar39._8_8_ = auVar38._8_8_;
        auVar39._0_8_ = CONCAT44(uVar28,uVar27);
        in_stack_ffffffffffffff00 = 0;
        FUN_1400709b0(4,uVar9 & 0xffffffff,fVar32,fVar33,CONCAT22(uVar35,uVar7),0,
                      CONCAT44(uVar28,uVar27),auVar39._8_8_,uVar15,27000,0);
        if (2 < DAT_140e419b8) {
          auVar40._12_4_ = auVar39._12_4_;
          auVar40._0_8_ = auVar39._0_8_;
          auVar40._8_4_ = 1;
          in_stack_ffffffffffffff00 = 0;
          FUN_1400709b0(4,0,fVar32,fVar33,(int)dVar19 & 0xffff,0,
                        (double)CONCAT44(uVar28,uVar27) + DAT_140539f68,auVar40._8_8_,uVar15,27000,0
                       );
        }
      }
    }
    in_stack_ffffffffffffff00 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e44b64,0x20,7,param_1[10],(float)param_1[0xb] + DAT_14053ac9c,
                  in_stack_ffffffffffffff00,auVar6,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44b60,0x20,7,param_1[10],param_1[0xb],
                  in_stack_ffffffffffffff00 & 0xffff0000,dVar18 + dVar3,dVar3,0xff,0xff,0xff,0xff,1,
                  0);
    uVar2 = DAT_140e44b68;
    fVar31 = DAT_14053acbc;
    sVar1 = *(short *)(param_1 + 3);
    uVar34 = param_1[10];
    fVar32 = (float)param_1[0xb] - DAT_14053acbc;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar11[3] = uVar34;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[4] = fVar32;
    *puVar11 = uVar2;
    puVar11[1] = 0x20;
    puVar11[2] = 7;
    *(short *)(puVar11 + 5) = sVar1 * 0x708;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xd] = 0xff;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    DAT_140e46d10 = DAT_140e46d10 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    uVar2 = DAT_140e44b68;
    sVar1 = *(short *)(param_1 + 3);
    fVar32 = (float)param_1[0xb];
    uVar34 = param_1[10];
    DAT_140e46c88 = puVar11;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar11 = uVar2;
    puVar11[1] = 0x20;
    puVar11[2] = 7;
    puVar11[3] = uVar34;
    puVar11[4] = fVar32 - fVar31;
    *(short *)(puVar11 + 5) = sVar1 * 0x708 + 0x5555;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xd] = 0xff;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    DAT_140e46d10 = DAT_140e46d10 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    uVar2 = DAT_140e44b68;
    sVar1 = *(short *)(param_1 + 3);
    fVar32 = (float)param_1[0xb];
    uVar34 = param_1[10];
    DAT_140e46c88 = puVar11;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar11 = uVar2;
    puVar11[1] = 0x20;
    puVar11[2] = 7;
    puVar11[3] = uVar34;
    puVar11[4] = fVar32 - fVar31;
    *(short *)(puVar11 + 5) = sVar1 * 0x708 + -0x5556;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xd] = 0xff;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    DAT_140e46d10 = DAT_140e46d10 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    DAT_140e46c88 = puVar11;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - fVar5) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053afa0 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b400)) || (DAT_14053afcc < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


