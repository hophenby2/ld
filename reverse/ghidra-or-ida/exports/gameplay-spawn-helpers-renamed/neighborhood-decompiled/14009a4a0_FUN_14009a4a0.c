// Function: FUN_14009a4a0 @ 14009a4a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009a4a0(undefined4 *param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined4 uVar4;
  undefined1 auVar5 [16];
  int iVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  short sVar17;
  ushort uVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  double dVar26;
  float fVar27;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined4 uVar28;
  undefined2 uVar30;
  uint uVar29;
  uint in_stack_ffffffffffffff00;
  undefined2 uVar32;
  undefined4 uVar31;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  fVar23 = (float)param_1[10];
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - fVar23));
  dVar20 = dVar20 * DAT_14053aba0;
  dVar21 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a838 * DAT_14053a020 *
                                 DAT_140539d28);
  auVar5 = _DAT_14053bb20;
  dVar22 = DAT_140539e60;
  uVar24 = (undefined4)DAT_14053bb20;
  uVar25 = DAT_14053bb20._4_4_;
  iVar16 = 0;
  iVar13 = param_1[5];
  dVar21 = dVar21 * DAT_140539e60 + (double)DAT_14053bb20;
  if (iVar13 == 0) {
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar13 = param_1[5];
      fVar23 = (float)param_1[10];
    }
    uVar32 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
    puVar8 = param_1 + 10;
    if (param_1[3] == 0x14) {
      if (fVar23 <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= fVar23) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffff6a);
      uVar28 = DAT_14053ac48;
      local_res8 = (undefined4)uVar7;
      uVar15 = param_1[1];
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
      *puVar8 = local_res8;
      uVar4 = DAT_14053ad18;
      auVar33._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar33._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar33._8_4_ = 0x1e;
      auVar34._8_8_ = 0;
      auVar34._0_8_ = auVar33._8_8_;
      auVar34 = auVar34 << 0x40;
      puVar8[1] = uStackX_c;
      uVar31 = CONCAT22(uVar32,0xc000);
      stage_entity_spawn_candidate(0x4e,0xa8c,8,uVar28,uVar4,uVar31,0,auVar33._8_8_,0,uVar15);
      auVar35._12_4_ = auVar34._12_4_;
      auVar35._0_8_ = auVar34._0_8_;
      auVar35._8_4_ = 0x1e;
      auVar36._8_8_ = 0;
      auVar36._0_8_ = auVar35._8_8_;
      auVar36 = auVar36 << 0x40;
      uVar15 = CONCAT22((short)((uint)uVar31 >> 0x10),0xc000);
      stage_entity_spawn_candidate
                (0x4e,0xa8c,8,DAT_14053acf8,DAT_14053ace8,uVar15,0,auVar35._8_8_,0,param_1[1]);
      auVar37._12_4_ = auVar36._12_4_;
      auVar37._0_8_ = auVar36._0_8_;
      auVar37._8_4_ = 0x1e;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = auVar37._8_8_;
      in_stack_ffffffffffffff08 = auVar2 << 0x40;
      in_stack_ffffffffffffff00 = CONCAT22((short)((uint)uVar15 >> 0x10),0xc000);
      uVar15 = DAT_14053ace0;
      stage_entity_spawn_candidate
                (0x4e,0xa8c,8,DAT_14053b364,DAT_14053ace0,in_stack_ffffffffffffff00,0,auVar37._8_8_,
                 0,param_1[1]);
      uVar30 = (undefined2)((uint)uVar15 >> 0x10);
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4022000000000000;
      iVar13 = param_1[5];
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (iVar13 == 1) {
    uVar29 = param_1[3];
    dVar26 = *(double *)(param_1 + 0x12);
    if ((uVar29 < 0x5b) && (DAT_140539f00 < dVar26)) {
      dVar26 = dVar26 - dVar22;
    }
    uVar10 = *(ushort *)(param_1 + 0x10);
    iVar13 = ((int)dVar20 & 0xffffU) - (uint)uVar10;
    *(double *)(param_1 + 0x12) = dVar26;
    uVar18 = (ushort)(int)dVar20;
    if ((int)uVar29 < 0x5a) {
      iVar6 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar6 = iVar13;
      }
      iVar13 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar13 = iVar6;
      }
      sVar17 = (short)(uVar29 * 4);
      if (iVar13 < 1) {
        if ((iVar13 < 0) && (uVar10 = uVar10 - sVar17, (int)(uVar29 * -4) < iVar13)) {
          uVar10 = uVar18;
        }
        *(ushort *)(param_1 + 0x10) = uVar10;
      }
      else if (iVar13 < (int)(uVar29 * 4)) {
        *(ushort *)(param_1 + 0x10) = uVar18;
      }
      else {
        *(ushort *)(param_1 + 0x10) = uVar10 + sVar17;
      }
    }
    else {
      iVar6 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar6 = iVar13;
      }
      iVar13 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar13 = iVar6;
      }
      if (iVar13 < 1) {
        uVar11 = uVar10;
        if ((iVar13 < 0) && (uVar11 = uVar10 - 0x40, -0x40 < iVar13)) {
          uVar11 = uVar18;
        }
      }
      else {
        uVar11 = uVar18;
        if (0x3f < iVar13) {
          uVar11 = uVar10 + 0x40;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar11;
      if (0x167 < (int)uVar29) {
        dVar26 = dVar26 - dVar22;
        *(double *)(param_1 + 0x12) = dVar26;
      }
    }
    dVar22 = (double)FUN_1403307c0();
    fVar27 = (float)(dVar22 * dVar26) + (float)param_1[10];
    param_1[10] = fVar27;
    dVar22 = (double)FUN_140332d90();
    fVar23 = (float)(dVar22 * dVar26) + (float)param_1[0xb];
    param_1[0xb] = fVar23;
    if (uVar29 - 0x5a < 0x10e) {
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0x65;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0x48;
      }
      else if (DAT_140e419b8 == 2) {
        iVar13 = 0x41;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar13 = 0x3c;
      }
      uVar15 = 1;
      if (DAT_140e419b8 == 0) {
        uVar15 = 5;
      }
      else if (DAT_140e419b8 == 1) {
        uVar15 = 9;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar15 = 0xb;
      }
      else if (DAT_140e419b8 == 4) {
        uVar15 = 0xd;
      }
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0x1e;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar6 = 0x23;
      }
      if (DAT_140e419b8 == 0) {
        uVar24 = (undefined4)DAT_14053a120;
        uVar25 = (undefined4)((ulonglong)DAT_14053a120 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar24 = (undefined4)DAT_14053a178;
        uVar25 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar24 = (undefined4)DAT_14053a1b8;
        uVar25 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar24 = (undefined4)DAT_14053a1e8;
        uVar25 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar24 = (undefined4)DAT_14053a218;
        uVar25 = (undefined4)((ulonglong)DAT_14053a218 >> 0x20);
      }
      sVar17 = -1;
      lVar1 = (longlong)(param_1[3] + -0x5a) % (longlong)iVar13;
      sVar12 = 1;
      if (DAT_140e419b8 == 0) {
        sVar12 = 0x21;
        sVar17 = -0x21;
      }
      else if (DAT_140e419b8 == 1) {
        sVar12 = 0x37;
        sVar17 = -0x37;
      }
      else if (DAT_140e419b8 == 2) {
        sVar12 = 0x42;
        sVar17 = -0x42;
      }
      else if (DAT_140e419b8 == 3) {
        sVar12 = 99;
        sVar17 = -99;
      }
      else if (DAT_140e419b8 == 4) {
        sVar12 = 0x78;
        sVar17 = -0x78;
      }
      if (DAT_14053ae30 < (float)param_1[0xc] || DAT_14053ae30 == (float)param_1[0xc]) {
        sVar17 = sVar12;
      }
      if ((param_1[3] - 0x5a < 0x10e) && ((int)lVar1 == 0)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar18;
      }
      uVar29 = DAT_14053ac2c;
      sVar12 = (short)lVar1;
      if (((param_1[3] - 0x5a < 0x10e) &&
          (iVar14 = (param_1[3] + -0x5a) % (iVar13 * 2), iVar14 < iVar6)) &&
         (iVar14 == (iVar14 / 5) * 5)) {
        auVar38._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar38._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar38._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar38._8_8_;
        in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar25,uVar24);
        uVar28 = CONCAT22(uVar30,sVar12 * sVar17 + *(short *)((longlong)param_1 + 0x42));
        in_stack_ffffffffffffff00 = DAT_14053ac2c;
        FUN_1400709b0(3,7,fVar27,fVar23,uVar28,DAT_14053ac2c,CONCAT44(uVar25,uVar24),
                      in_stack_ffffffffffffff08._8_8_,uVar15,30000,0);
        uVar30 = (undefined2)((uint)uVar28 >> 0x10);
      }
      iVar14 = param_1[3];
      if ((((iVar13 + 0x5a <= iVar14) && (iVar14 < 0x168)) &&
          (iVar13 = (iVar14 - (iVar13 + 0x5a)) % (iVar13 * 2), iVar13 < iVar6)) &&
         (iVar13 == (iVar13 / 5) * 5)) {
        auVar39._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar39._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar39._8_4_ = 1;
        FUN_1400709b0(3,7,param_1[10],param_1[0xb],
                      CONCAT22(uVar30,*(short *)((longlong)param_1 + 0x42) - sVar17 * sVar12),uVar29
                      ,CONCAT44(uVar25,uVar24),auVar39._8_8_,uVar15,30000,0);
        in_stack_ffffffffffffff00 = uVar29;
      }
    }
    dVar22 = dVar21 * DAT_14053a380;
    do {
      uVar30 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
      sVar17 = *(short *)(param_1 + 3);
      dVar20 = (double)FUN_1403307c0();
      fVar23 = (float)param_1[10];
      dVar26 = (double)FUN_140332d90();
      auVar40._8_4_ = SUB84(dVar21,0);
      auVar40._0_8_ = dVar21;
      auVar40._12_4_ = (int)((ulonglong)dVar21 >> 0x20);
      in_stack_ffffffffffffff00 = CONCAT22(uVar30,(short)iVar16 * 0x3333 + sVar17 * 0x1c8);
      FUN_1400c8410(DAT_140e44c24,0x20,7,(float)(dVar20 * (double)(float)dVar22) + fVar23,
                    (float)(dVar26 * (double)(float)dVar22) + (float)param_1[0xb],
                    in_stack_ffffffffffffff00,auVar40,0xff,0xff,0xff,0xff,1,0);
      uVar24 = DAT_140e4473c;
      iVar16 = iVar16 + 1;
    } while (iVar16 < 5);
    sVar17 = (short)DAT_140e418c8;
    uVar25 = param_1[0xb];
    uVar15 = param_1[10];
    puVar8 = (undefined4 *)_malloc_base(0x48);
    if (puVar8 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d10 = DAT_140e46d10 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar8 = uVar24;
    *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
    puVar8[3] = uVar15;
    puVar8[4] = uVar25;
    puVar8[1] = 0x20;
    puVar8[2] = 7;
    *(short *)(puVar8 + 5) = sVar17 * -0x7b;
    puVar8[10] = 0xff;
    puVar8[0xb] = 0xff;
    puVar8[0xc] = 0xff;
    puVar8[0xd] = 0xff;
    *(undefined8 *)(puVar8 + 0xe) = 1;
    *(undefined8 *)(puVar8 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar8;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
    }
    uVar25 = DAT_140e44964;
    fVar23 = (float)param_1[0xb] + DAT_14053ad38;
    uVar24 = param_1[10];
    DAT_140e46c88 = puVar8;
    puVar8 = (undefined4 *)_malloc_base(0x48);
    if (puVar8 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d08 = DAT_140e46d08 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar8[3] = uVar24;
    puVar8[4] = fVar23;
    *puVar8 = uVar25;
    puVar8[1] = 0x1e;
    puVar8[2] = 7;
    *(undefined2 *)(puVar8 + 5) = 0;
    *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
    puVar8[10] = 0xff;
    puVar8[0xb] = 0xff;
    puVar8[0xc] = 0xff;
    puVar8[0xd] = 0xff;
    *(undefined8 *)(puVar8 + 0xe) = 1;
    *(undefined8 *)(puVar8 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar8;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
    }
    DAT_140e46c88 = puVar8;
    uVar29 = DAT_14053b388;
    FUN_140079c10(param_1,0);
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,500,0xf);
      auVar3._12_4_ = 0;
      auVar3._0_12_ = auVar40._4_12_;
      in_stack_ffffffffffffff00 = 0;
      FUN_140109660(0x18,param_1[10],param_1[0xb],0,uVar29 & 0xffff0000,0,auVar3 << 0x20);
      uVar24 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar9 = 1;
        *(undefined4 *)(puVar9 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar9 + 0xc) = uVar24;
        puVar9[2] = 0x6f;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        puVar9[6] = 0x3ff0000000000000;
        puVar9[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar9 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        puVar9[10] = 0xff;
        puVar9[0xb] = 0;
        if (bVar19) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
      DAT_140e45d28 = puVar9;
      FUN_140079e20(param_1,2);
      fVar23 = (float)param_1[0xb] + DAT_14053add4;
      param_1[5] = param_1[5] + 1;
      param_1[0x14] = 0x96;
      param_1[0x15] = 1;
      param_1[3] = 0;
      param_1[0xb] = fVar23;
    }
  }
  if (((int)param_1[7] < 1) && (param_1[0x15] == 1)) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    fVar23 = (float)(int)param_1[3] * _DAT_140539cdc + (float)param_1[0xb];
    param_1[0xb] = fVar23;
    FUN_1400c8410(DAT_140e44964,0x1e,7,param_1[10],fVar23 - DAT_14053ad38,
                  in_stack_ffffffffffffff00 & 0xffff0000,auVar5,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x3c) {
      FUN_140079e20(param_1,2);
      *param_1 = 0;
    }
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ae48) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053afb0 < (float)param_1[10])) ||
      (((float)param_1[0xb] < DAT_14053b404 || (DAT_14053afd4 < (float)param_1[0xb])))) &&
     (param_1[0x15] == 0)) {
    *param_1 = 0;
  }
  return;
}


