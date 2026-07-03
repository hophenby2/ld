// Function: FUN_14009b5f0 @ 14009b5f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009b5f0(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  double dVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ushort uVar6;
  double dVar7;
  undefined8 uVar8;
  double dVar9;
  undefined8 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ushort uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  short sVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  float fVar28;
  undefined4 uVar29;
  float fVar30;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar32;
  undefined4 uVar31;
  undefined4 in_stack_fffffffffffffef0;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined2 uVar35;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  
  uVar21 = DAT_140e418c8;
  dVar3 = DAT_14053a020;
  dVar7 = DAT_140539f40;
  dVar26 = DAT_140539d28;
  uVar32 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  uVar35 = (undefined2)((uint)in_stack_fffffffffffffef0 >> 0x10);
  iVar16 = 0xff;
  iVar15 = 0xff;
  dVar24 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a808 * DAT_14053a020
                                 * DAT_140539d28);
  dVar24 = dVar24 * DAT_14053a8f8;
  if (uVar21 == ((int)uVar21 / 0x32) * 0x32) {
    uVar13 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 1;
    uVar11 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 4;
    uVar21 = (uVar21 + 0x15b3 >> 0x1e ^ uVar21 + 0x15b3) * 0x6c078965 + 1;
    param_1[0xe] = (float)(((uVar11 >> 0xb ^ uVar13) >> 8 ^ uVar11 ^ uVar13) % 0x12d + 0xd2);
    DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar21 = uVar21 * 0x800 ^ uVar21;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ uVar21 ^ DAT_140e9fd18;
    param_1[0xf] = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  dVar9 = DAT_14053a5f8;
  dVar27 = DAT_14053a530;
  iVar18 = param_1[5];
  dVar25 = dVar7;
  if (iVar18 == 0) {
    uVar21 = param_1[3];
    fVar28 = (float)param_1[0xd];
    uVar13 = (int)uVar21 >> 0x1f;
    if ((int)uVar21 < 0) {
      param_1[0xb] = 0x44110000;
      dVar25 = 0.0;
      iVar15 = (uVar13 & 0xffffff01) + 0xff;
      iVar16 = iVar15;
    }
    else {
      if ((int)uVar21 < 100) {
        dVar25 = (double)FUN_140332d90(((double)(int)uVar21 - 0.0) * DAT_14053a530 * dVar3 * dVar26)
        ;
        iVar18 = param_1[5];
        param_1[0xb] = (float)((int)(dVar25 * (double)((int)fVar28 + -0x244)) + 0x244);
        dVar25 = (double)FUN_140332d90(((double)(int)uVar21 - 0.0) * dVar27 * dVar3 * dVar26);
        iVar15 = (uVar13 & 0xffffff01) + 0xff;
        dVar27 = (double)FUN_140332d90(((double)(int)uVar21 - 0.0) * dVar27 * dVar3 * dVar26);
        iVar16 = (int)(dVar27 * dVar9);
        dVar25 = dVar25 + 0.0;
      }
      else {
        iVar15 = (uVar13 & 0xffffff01) + 0xff;
        param_1[0xb] = (float)(int)fVar28;
        iVar16 = iVar15;
      }
      if (uVar21 < 10) {
        dVar26 = (double)FUN_140332d90(((double)(int)uVar21 - 0.0) * DAT_14053a9d8 * dVar3 * dVar26)
        ;
        iVar15 = (int)(dVar26 * dVar9);
      }
      if (uVar21 == 0) {
        auVar36._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar36._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar36._8_4_ = 100;
        in_stack_fffffffffffffef8._8_8_ = auVar36._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar7;
        uVar33 = CONCAT22(uVar35,0x4000);
        uVar29 = DAT_14053adbc;
        stage_entity_spawn_candidate
                  (0x50,99999999,0,0,DAT_14053adbc,uVar33,dVar7,in_stack_fffffffffffffef8._8_8_,1,
                   param_1[1]);
        uVar32 = (undefined2)((uint)uVar29 >> 0x10);
        uVar35 = (undefined2)((uint)uVar33 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
        FUN_14018a340(DAT_140e472d8,1,1);
        iVar18 = param_1[5];
      }
    }
    if (param_1[3] == 100) {
      param_1[0x15] = 0;
      iVar18 = iVar18 + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd999999999999a;
      param_1[5] = iVar18;
      param_1[3] = 0;
    }
  }
  uVar29 = (undefined4)((ulonglong)dVar25 >> 0x20);
  if (iVar18 == 1) {
    fVar28 = (float)param_1[0xb];
    if ((int)param_1[3] < 0x4b0) {
      fVar30 = (float)param_1[10];
      uVar1 = *(ushort *)(param_1 + 0x10);
      dVar26 = (double)FUN_1403300b4((double)((float)param_1[0xf] - fVar28),
                                     (double)((float)param_1[0xe] - fVar30));
      iVar12 = ((int)(dVar26 * DAT_14053aba0) & 0xffffU) - (uint)uVar1;
      iVar18 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar18 = iVar12;
      }
      iVar12 = iVar18 + -0x10000;
      if (iVar18 < 0x8001) {
        iVar12 = iVar18;
      }
      uVar6 = (ushort)(int)(dVar26 * DAT_14053aba0);
      if (iVar12 < 1) {
        uVar17 = uVar1;
        if ((iVar12 < 0) && (uVar17 = uVar1 - 0x200, -0x200 < iVar12)) {
          uVar17 = uVar6;
        }
      }
      else {
        uVar17 = uVar6;
        if (0x1ff < iVar12) {
          uVar17 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar17;
      dVar26 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + fVar30;
      dVar26 = (double)FUN_140332d90();
      iVar18 = DAT_140e419b8;
      iVar12 = 1;
      param_1[0xb] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + fVar28;
      uVar33 = DAT_14053ac2c;
      if (iVar18 == 0) {
        iVar12 = 2;
      }
      iVar14 = 1;
      if (((iVar18 != 0) && (iVar18 != 1)) && ((iVar18 == 2 || ((iVar18 == 3 || (iVar18 == 4)))))) {
        iVar14 = 2;
      }
      iVar19 = 1;
      if (iVar18 == 0) {
        iVar19 = 0x578;
      }
      else if (iVar18 == 1) {
        iVar19 = 0x9c4;
      }
      else if (((iVar18 == 2) || (iVar18 == 3)) || (iVar18 == 4)) {
        iVar19 = 0x898;
      }
      dVar26 = DAT_14053a088;
      if (((iVar18 != 0) && (dVar26 = DAT_14053a0d0, iVar18 != 1)) &&
         ((dVar26 = DAT_14053a0f8, iVar18 != 2 && ((iVar18 != 3 && (dVar26 = dVar7, iVar18 == 4)))))
         ) {
        dVar26 = DAT_14053a178;
      }
      iVar2 = param_1[3];
      if ((iVar2 - 0x14U < 100) && ((iVar2 + -0x14) % iVar12 == 0)) {
        dVar3 = (double)((float)(iVar2 + -0x14) * DAT_140539e78);
        dVar27 = (double)FUN_1403307c0();
        fVar30 = (float)(dVar27 * dVar3) + (float)param_1[10];
        dVar27 = (double)FUN_140332d90();
        sVar22 = (short)((iVar2 - 0x14U & 0xffff) * iVar19) + -0x4000;
        auVar37._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar37._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar37._8_4_ = 1;
        fVar28 = (float)(dVar27 * dVar3) + (float)param_1[0xb];
        in_stack_fffffffffffffef8._8_8_ = auVar37._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar26;
        uVar31 = CONCAT22(uVar32,sVar22);
        uVar34 = uVar33;
        FUN_1400709b0(10,2,fVar30,fVar28,uVar31,uVar33,dVar26,in_stack_fffffffffffffef8._8_8_,iVar14
                      ,iVar14 * 7000 + -7000,0);
        uVar32 = (undefined2)((uint)uVar31 >> 0x10);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        iVar18 = DAT_140e419b8;
        if (2 < DAT_140e419b8) {
          auVar38._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar38._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar38._8_4_ = 1;
          in_stack_fffffffffffffef8._8_8_ = auVar38._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar26 + DAT_140539f90;
          uVar31 = CONCAT22(uVar32,sVar22);
          uVar34 = uVar33;
          FUN_1400709b0(10,2,fVar30,fVar28,uVar31,uVar33,dVar26 + DAT_140539f90,
                        in_stack_fffffffffffffef8._8_8_,iVar14,iVar14 * 12000 + -12000,0);
          uVar32 = (undefined2)((uint)uVar31 >> 0x10);
          uVar35 = (undefined2)((uint)uVar34 >> 0x10);
          iVar18 = DAT_140e419b8;
        }
      }
      iVar20 = 0;
      iVar2 = param_1[3];
      if ((iVar2 - 0x78U < 100) && ((iVar2 + -0x78) % iVar12 == 0)) {
        dVar3 = (double)((float)(iVar2 + -0x78) * DAT_140539e78);
        dVar27 = (double)FUN_1403307c0();
        fVar30 = (float)(dVar27 * dVar3) + (float)param_1[10];
        dVar27 = (double)FUN_140332d90();
        sVar22 = (100 - (short)iVar2) * (short)iVar19 + 0x4000;
        auVar39._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar39._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar39._8_4_ = 1;
        fVar28 = (float)(dVar27 * dVar3) + (float)param_1[0xb];
        in_stack_fffffffffffffef8._8_8_ = auVar39._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar26;
        uVar34 = uVar33;
        FUN_1400709b0(0xb,2,fVar30,fVar28,CONCAT22(uVar32,sVar22),uVar33,dVar26,
                      in_stack_fffffffffffffef8._8_8_,iVar14,iVar14 * 7000 + -7000,0);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        iVar18 = DAT_140e419b8;
        if (2 < DAT_140e419b8) {
          auVar40._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar40._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar40._8_4_ = 1;
          in_stack_fffffffffffffef8._8_8_ = auVar40._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar26 + dVar7;
          FUN_1400709b0(0xb,2,fVar30,fVar28,sVar22,uVar33,dVar26 + dVar7,
                        in_stack_fffffffffffffef8._8_8_,iVar14,iVar14 * 12000 + -12000,0);
          uVar35 = (undefined2)((uint)uVar33 >> 0x10);
          iVar18 = DAT_140e419b8;
        }
      }
      uVar33 = DAT_14053b34c;
      if (param_1[3] == 0xdc) {
        auVar41._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar41._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar41._8_4_ = 0x28;
        in_stack_fffffffffffffef8._8_8_ = auVar41._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar7;
        uVar34 = CONCAT22(uVar35,0x4000);
        stage_entity_spawn_candidate
                  (0x53,99999999,1,DAT_14053adc4,DAT_14053b34c,uVar34,dVar7,
                   in_stack_fffffffffffffef8._8_8_,1,param_1[1]);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        DAT_1407c77a0 = DAT_1407c779c;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
        iVar18 = DAT_140e419b8;
      }
      if (param_1[3] == 0xe6) {
        auVar42._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar42._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar42._8_4_ = 0x28;
        in_stack_fffffffffffffef8._8_8_ = auVar42._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar7;
        uVar34 = CONCAT22(uVar35,0x4000);
        stage_entity_spawn_candidate
                  (0x53,99999999,1,DAT_14053b3dc,uVar33,uVar34,dVar7,in_stack_fffffffffffffef8._8_8_
                   ,1,param_1[1]);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
        iVar18 = DAT_140e419b8;
      }
      uVar33 = DAT_14053b390;
      if (param_1[3] == 0xf0) {
        auVar43._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar43._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar43._8_4_ = 0x28;
        in_stack_fffffffffffffef8._8_8_ = auVar43._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar7;
        uVar34 = CONCAT22(uVar35,0x4000);
        stage_entity_spawn_candidate
                  (0x53,99999999,1,DAT_14053ad40,DAT_14053b390,uVar34,dVar7,
                   in_stack_fffffffffffffef8._8_8_,1,param_1[1]);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
        iVar18 = DAT_140e419b8;
      }
      iVar12 = param_1[3];
      if (iVar12 == 0xfa) {
        auVar44._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar44._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar44._8_4_ = 0x28;
        in_stack_fffffffffffffef8._8_8_ = auVar44._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar7;
        uVar34 = CONCAT22(uVar35,0x4000);
        stage_entity_spawn_candidate
                  (0x53,99999999,1,uVar33,uVar33,uVar34,dVar7,in_stack_fffffffffffffef8._8_8_,1,
                   param_1[1]);
        uVar35 = (undefined2)((uint)uVar34 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
        iVar12 = param_1[3];
        iVar18 = DAT_140e419b8;
      }
      iVar14 = 1;
      if (iVar18 == 0) {
        iVar14 = 0x5f;
      }
      else if (iVar18 == 1) {
        iVar14 = 0x36;
      }
      else if ((iVar18 == 2) || (iVar18 == 3)) {
        iVar14 = 0x2d;
      }
      else if (iVar18 == 4) {
        iVar14 = 0x23;
      }
      if ((0x1df < iVar12) && ((iVar12 + -0x1e0) % iVar14 == 0)) {
        fVar28 = (float)param_1[10] + DAT_14053acd8;
        fVar30 = (float)param_1[0xb] + DAT_14053aca8;
        dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - _DAT_14053b428),
                                       (double)(DAT_140e445d8 - (float)param_1[10]));
        uVar8 = DAT_14053a218;
        dVar26 = dVar26 * DAT_14053aba0;
        do {
          auVar45._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar45._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar45._8_4_ = 1;
          in_stack_fffffffffffffef8._8_8_ = auVar45._8_8_;
          in_stack_fffffffffffffef8._0_8_ = uVar8;
          uVar35 = 0;
          FUN_14006c2f0(3,0x1c,fVar28,fVar30,(short)iVar20 * -0x8000 + (short)(int)dVar26 + -0x4000,
                        0,uVar8,in_stack_fffffffffffffef8._8_8_,0);
          iVar20 = iVar20 + 1;
        } while (iVar20 < 2);
      }
    }
    else {
      param_1[0xb] = fVar28 - ((float)(int)param_1[3] - DAT_14053afe4) * DAT_140539ce4;
    }
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,0x708,0x1e);
      uVar35 = 0;
      FUN_140109660(0x18);
      uVar33 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar10 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar10 = (undefined8 *)_malloc_base(0x60);
        if (puVar10 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar10 = 1;
        *(undefined4 *)(puVar10 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar10 + 0xc) = uVar33;
        puVar10[2] = 0x6f;
        puVar10[3] = 0;
        *(undefined4 *)(puVar10 + 4) = 0;
        *(undefined2 *)((longlong)puVar10 + 0x24) = 0;
        puVar10[5] = 0;
        puVar10[6] = 0x3ff0000000000000;
        puVar10[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar10 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar10 + 0x44) = 0xff;
        *(undefined4 *)(puVar10 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar10 + 0x4c) = 0xff;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0;
        if (bVar23) {
          DAT_140e45d78 = puVar10;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar10;
        }
      }
      DAT_140e45d28 = puVar10;
      param_1[5] = param_1[5] + 1;
      param_1[0x14] = 0xf0;
      param_1[0x15] = 1;
      param_1[3] = 0;
    }
  }
  if (((int)param_1[7] < 1) && (param_1[0x15] == 1)) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)(int)param_1[3] * _DAT_140539ce8 + (float)param_1[0xb];
    if (param_1[3] == 0x3c) {
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  auVar4._8_4_ = SUB84(dVar25,0);
  auVar4._0_8_ = dVar25;
  auVar4._12_4_ = uVar29;
  uVar21 = CONCAT22(uVar35,(short)(int)dVar24);
  FUN_1400c8410(DAT_140e4496c,0x20,7,(float)(dVar25 * DAT_14053a4b8) + (float)param_1[10],
                (float)(dVar25 * _DAT_14053b198) + (float)param_1[0xb],uVar21,auVar4,iVar16,iVar16,
                iVar16,iVar15,1,0);
  auVar5._8_4_ = SUB84(dVar25,0);
  auVar5._0_8_ = dVar25;
  auVar5._12_4_ = uVar29;
  FUN_1400c8410(DAT_140e44968,0x20,7,param_1[10],param_1[0xb],uVar21 & 0xffff0000,auVar5,iVar16,
                iVar16,iVar16,iVar15,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053afb0) ||
        (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053b020 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b424)) || (_DAT_14053b024 < (float)param_1[0xb])) &&
     (param_1[0x15] == 0)) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
  return;
}


