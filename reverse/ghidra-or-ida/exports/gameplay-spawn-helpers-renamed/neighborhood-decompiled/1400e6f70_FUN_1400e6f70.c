// Function: FUN_1400e6f70 @ 1400e6f70
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e6f70(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  double dVar4;
  ushort uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  short sVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined2 uVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  float fVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  uint in_stack_fffffffffffffef0;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  
  dVar23 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar24 = DAT_14053aba0;
  dVar23 = dVar23 * DAT_14053aba0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar32._12_4_ = in_stack_fffffffffffffef8._12_4_;
    auVar32._0_8_ = in_stack_fffffffffffffef8._0_8_;
    auVar32._8_4_ = param_1[0x14];
    in_stack_fffffffffffffef8._8_8_ = auVar32._8_8_;
    in_stack_fffffffffffffef8._0_8_ = DAT_14053a4f0;
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_fffffffffffffef0,DAT_14053a4f0,
               in_stack_fffffffffffffef8._8_8_,1,0);
    if (DAT_140e41928 == 0) {
      uVar18 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar18 = uVar18 * 0x800 ^ uVar18;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ DAT_140e9fd18 ^ uVar18;
      in_stack_fffffffffffffef0 = DAT_14053ac80;
      FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                    DAT_14053a070,DAT_14053ac80);
    }
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 200;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  auVar32 = _DAT_14053bb20;
  uVar2 = DAT_14053b380;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x1e) * 0x1e) {
    uVar18 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar9 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
    uVar18 = uVar18 * 0x800 ^ uVar18;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
    uVar10 = DAT_1407c7798 * 0x14d + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar9 >> 0xb ^ uVar18) >> 8 ^ uVar18 ^ uVar9) % 0x12d + 0xd2);
    uVar18 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar18 = uVar18 * 0x800 ^ uVar18;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ DAT_140e9fd18 ^ uVar18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x78);
  }
  iVar19 = param_1[5];
  dVar4 = (double)DAT_14053bb20;
  uVar29 = (undefined4)DAT_14053bb20;
  uVar30 = DAT_14053bb20._4_4_;
  if (iVar19 == 0) {
    iVar19 = 0;
    if (param_1[3] == 0) {
      DAT_1407c77a0 = DAT_1407c779c;
      auVar38._12_4_ = in_stack_fffffffffffffef8._12_4_;
      auVar38._0_8_ = in_stack_fffffffffffffef8._0_8_;
      auVar38._8_4_ = 0x32;
      auVar39._8_8_ = auVar38._8_8_;
      auVar39._0_8_ = dVar4;
      uVar29 = CONCAT22((short)(in_stack_fffffffffffffef0 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (199,99999999,0,DAT_14053ad1c,DAT_14053b380,uVar29,dVar4,auVar39._8_8_,1,param_1[1])
      ;
      auVar40._12_4_ = auVar39._12_4_;
      auVar40._0_8_ = auVar39._0_8_;
      auVar40._8_4_ = 0x32;
      in_stack_fffffffffffffef0 = CONCAT22((short)((uint)uVar29 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (199,99999999,0,uVar2,uVar2,in_stack_fffffffffffffef0,dVar4,auVar40._8_8_,1,
                 param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar19 = param_1[5];
    }
    uVar18 = param_1[3];
    if ((int)uVar18 < 0x3d) {
      iVar11 = (int)((float)param_1[0xd] - DAT_14053ae48);
      iVar17 = (int)((float)param_1[0xd] + DAT_14053adb4);
      iVar19 = iVar11;
      if (-1 < (int)uVar18) {
        iVar19 = iVar17;
      }
      if (uVar18 < 0x3c) {
        dVar24 = (double)FUN_140332d90(((double)(int)uVar18 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                       DAT_140539d28);
        iVar19 = (int)(dVar24 * (double)(iVar17 - iVar11)) + iVar11;
      }
      param_1[0xb] = (float)iVar19;
    }
    else if ((int)uVar18 < 0xb5) {
      fVar31 = (float)param_1[0xd] + DAT_14053adb4;
      iVar11 = (int)(float)param_1[0xd];
      if ((int)uVar18 < 0xb4) {
        dVar24 = (double)FUN_140332d90(((double)(int)uVar18 - _DAT_14053b158) * DAT_14053a4d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar11 = (int)(dVar24 * (double)((int)fVar31 - iVar11)) + iVar11;
      }
      param_1[0xb] = (float)iVar11;
      if (uVar18 == 0xb4) {
        param_1[0x15] = 0;
        param_1[5] = iVar19 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 64000;
        DAT_140e4430c = 0x708;
        DAT_140e4192c = 0;
        param_1[7] = 64000;
        DAT_140e419bc = 1;
      }
    }
    goto LAB_1400e8197;
  }
  if (iVar19 == 1) {
    uVar3 = *(ushort *)(param_1 + 0x10);
    iVar11 = ((int)dVar23 & 0xffffU) - (uint)uVar3;
    iVar19 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar19 = iVar11;
    }
    iVar11 = iVar19 + -0x10000;
    if (iVar19 < 0x8001) {
      iVar11 = iVar19;
    }
    uVar5 = (ushort)(int)dVar23;
    if (iVar11 < 1) {
      uVar12 = uVar3;
      if ((iVar11 < 0) && (uVar12 = uVar3 - 0x309, -0x309 < iVar11)) {
        uVar12 = uVar5;
      }
    }
    else {
      uVar12 = uVar5;
      if (0x308 < iVar11) {
        uVar12 = uVar3 + 0x309;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar23 = (double)FUN_1403307c0();
    fVar28 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar28;
    dVar23 = (double)FUN_140332d90();
    fVar31 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar31;
    fVar31 = fVar31 + DAT_14053ad5c;
    uVar18 = (int)param_1[3] % 0x4b0;
    dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar31),(double)(DAT_140e445d8 - fVar28)
                                  );
    uVar2 = DAT_140e41a50;
    dVar26 = DAT_14053a118;
    dVar23 = DAT_140539f68;
    if ((int)uVar18 < 0x168) {
      iVar19 = 1;
      if (DAT_140e419b8 == 0) {
        iVar19 = 8;
      }
      else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
              (DAT_140e419b8 == 4)) {
        iVar19 = 6;
      }
      uVar14 = 1;
      if (DAT_140e419b8 == 0) {
        uVar14 = 2;
      }
      else if (DAT_140e419b8 == 1) {
        uVar14 = 3;
      }
      else if (DAT_140e419b8 == 2) {
        uVar14 = 4;
      }
      else if (DAT_140e419b8 == 3) {
        uVar14 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        uVar14 = 6;
      }
      dVar27 = DAT_14053a080;
      if (((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
         ((dVar27 = DAT_14053a118, DAT_140e419b8 != 2 &&
          ((dVar27 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar27 = dVar4, DAT_140e419b8 == 4))))))
      {
        dVar27 = DAT_14053a190;
      }
      dVar27 = (double)(int)(uVar18 - 0x1e) * _DAT_140539d80 + dVar27;
      if (uVar18 == 1) {
        uVar29 = param_1[1];
        puVar6 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar2;
          puVar6[2] = 0x23;
          puVar6[3] = 0x430c0000;
          *(undefined4 *)(puVar6 + 4) = 0x430c0000;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x4014000000000000;
          puVar6[7] = 0x4014000000000000;
          *(undefined4 *)(puVar6 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          *(undefined4 *)(puVar6 + 10) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x54) = uVar29;
          puVar6[0xb] = 0;
          if (bVar22) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
        DAT_140e45d28 = puVar6;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
        goto LAB_1400e8197;
      }
      if ((0x1d < (int)uVar18) && ((int)(uVar18 - 0x1e) % iVar19 == 0)) {
        sVar13 = (short)uVar18 * 0x16c;
        if ((int)uVar18 % 0x168 < 0xb4) {
          sVar8 = ((short)((ulonglong)((longlong)(int)uVar18 * 0xb60b60b7) >> 0x28) -
                  ((short)(char)((char)((int)uVar18 / 0x1680000) + (char)((int)uVar18 >> 0x1f)) >>
                  0xf)) * 0x20 + sVar13;
        }
        else {
          sVar8 = (short)uVar18 * -0x16c + (short)((int)uVar18 / 0x168 + 1) * -0x20;
        }
        auVar33._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar33._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar33._8_4_ = 1;
        auVar34._8_8_ = auVar33._8_8_;
        auVar34._0_8_ = dVar27 - DAT_140539f68;
        FUN_1400709b0(5,0,fVar28,fVar31,sVar8,0,dVar27 - DAT_140539f68,auVar34._8_8_,uVar14,0x10000,
                      0);
        if ((int)uVar18 % 0x168 < 0xb4) {
          sVar13 = (short)((int)uVar18 / 0x168) * 0x20 + sVar13;
        }
        else {
          sVar13 = (short)((uVar18 & 0xffff) * 0xfe94) + ((short)((int)uVar18 / 0x168) + 1) * -0x20;
        }
        auVar35._12_4_ = auVar34._12_4_;
        auVar35._0_8_ = auVar34._0_8_;
        auVar35._8_4_ = 1;
        in_stack_fffffffffffffef8._8_8_ = auVar35._8_8_;
        in_stack_fffffffffffffef8._0_8_ = dVar27;
        in_stack_fffffffffffffef0 = 0;
        FUN_1400709b0(3,0,fVar28,fVar31,(short)iVar19 * 0xb6 + sVar13,0,dVar27,
                      in_stack_fffffffffffffef8._8_8_,uVar14,0x10000,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    uVar2 = DAT_140e41a50;
    if (uVar18 - 0x1a4 < 0x17c) {
      iVar19 = 1;
      if (DAT_140e419b8 == 0) {
        iVar19 = 100;
      }
      else if (DAT_140e419b8 == 1) {
        iVar19 = 0x5a;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar19 = 0x50;
      }
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 6;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 8;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 10;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0xc;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0xe;
      }
      if (DAT_140e419b8 == 0) {
        uVar29 = (undefined4)DAT_14053a178;
        uVar30 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar29 = (undefined4)DAT_14053a1e8;
        uVar30 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar29 = (undefined4)DAT_14053a1f8;
        uVar30 = (undefined4)((ulonglong)DAT_14053a1f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar29 = (undefined4)DAT_14053a208;
        uVar30 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar29 = (undefined4)DAT_14053a220;
        uVar30 = (undefined4)((ulonglong)DAT_14053a220 >> 0x20);
      }
      iVar17 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar17 = 2;
      }
      else if (DAT_140e419b8 == 2) {
        iVar17 = 3;
      }
      else if (DAT_140e419b8 == 3) {
        iVar17 = 4;
      }
      else if (DAT_140e419b8 == 4) {
        iVar17 = 5;
      }
      iVar20 = 1;
      if (DAT_140e419b8 == 0) {
        iVar20 = 8;
      }
      else if (DAT_140e419b8 == 1) {
        iVar20 = 0xc;
      }
      else if (DAT_140e419b8 == 2) {
        iVar20 = 0xe;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar20 = 0x10;
      }
      iVar15 = 1;
      if (DAT_140e419b8 == 0) {
        iVar15 = 4000;
      }
      else if (DAT_140e419b8 == 1) {
        iVar15 = 0xc80;
      }
      else if (DAT_140e419b8 == 2) {
        iVar15 = 0xaf0;
      }
      else if (DAT_140e419b8 == 3) {
        iVar15 = 0x960;
      }
      else if (DAT_140e419b8 == 4) {
        iVar15 = 0x834;
      }
      dVar27 = DAT_14053a0f8;
      if ((((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar27 = dVar26, DAT_140e419b8 != 2)) &&
         ((dVar27 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar27 = dVar4, DAT_140e419b8 == 4)))) {
        dVar27 = DAT_14053a1a8;
      }
      if (((int)uVar18 < 0x2e4) && ((int)(uVar18 - 0x1a4) % iVar19 == 0)) {
        uVar14 = param_1[1];
        puVar6 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base();
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar2;
          puVar6[6] = 0x4014000000000000;
          puVar6[7] = 0x4014000000000000;
          *(undefined4 *)((longlong)puVar6 + 0x54) = uVar14;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x31;
          puVar6[2] = 0x23;
          puVar6[3] = 0x430c0000;
          *(undefined4 *)(puVar6 + 4) = 0x430c0000;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          *(undefined4 *)(puVar6 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          *(undefined4 *)(puVar6 + 10) = 0xff;
          puVar6[0xb] = 0;
          if (bVar22) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
        DAT_140e45d28 = puVar6;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
      }
      uVar9 = DAT_14053ac2c;
      dVar4 = DAT_140539f10;
      if ((uVar18 - 0x1c2 < 0x140) && ((int)(uVar18 - 0x1c2) % iVar19 == 0)) {
        iVar16 = 0;
        iVar19 = 0;
        do {
          iVar1 = iVar19 + 1;
          auVar36._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar36._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar36._8_4_ = 1;
          dVar26 = (double)CONCAT44(uVar30,uVar29) - (double)iVar19 * dVar4;
          in_stack_fffffffffffffef8._8_8_ = auVar36._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar26;
          uVar21 = (undefined2)(int)(dVar25 * dVar24);
          FUN_1400709b0(2,0,fVar28,fVar31,uVar21,uVar9,dVar26,in_stack_fffffffffffffef8._8_8_,iVar1,
                        iVar16,0);
          iVar16 = iVar16 + 800;
          iVar19 = iVar1;
        } while (iVar1 < iVar11);
        iVar19 = 0;
        iVar11 = (iVar20 + -1) * iVar15;
        do {
          auVar37._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar37._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar37._8_4_ = 1;
          dVar24 = dVar27 - (double)iVar19 * dVar23;
          in_stack_fffffffffffffef8._8_8_ = auVar37._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar24;
          in_stack_fffffffffffffef0 = uVar9;
          FUN_1400709b0(5,0,fVar28,fVar31,uVar21,uVar9,dVar24,in_stack_fffffffffffffef8._8_8_,
                        iVar20 + iVar19,iVar11,0);
          iVar19 = iVar19 + 1;
          iVar11 = iVar11 + iVar15;
        } while (iVar19 < iVar17);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    goto LAB_1400e8197;
  }
  if (iVar19 != 2) goto LAB_1400e8197;
  iVar19 = param_1[3];
  iVar11 = 0;
  if (iVar19 < 0x5a) {
LAB_1400e73b5:
    iVar17 = 0;
    if (iVar19 < 0x96) {
      iVar17 = iVar11;
    }
    puVar6 = DAT_140e45d28;
    if (iVar19 == 1) {
      uVar2 = param_1[0xb];
      uVar29 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar29;
        *(undefined4 *)(puVar6 + 3) = uVar2;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar29;
        *(undefined4 *)(puVar6 + 4) = uVar2;
        *puVar6 = 1;
        puVar6[1] = 0x36;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar22) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
  }
  else {
    iVar11 = 0xff;
    if (iVar19 < 100) {
      dVar24 = (double)FUN_140332d90(((double)iVar19 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar17 = (int)(dVar24 * DAT_14053a5f8);
      puVar6 = DAT_140e45d28;
    }
    else {
      if (0x95 < iVar19) goto LAB_1400e73b5;
      dVar24 = (double)FUN_140332d90(((double)iVar19 - DAT_14053a380) * DAT_14053a670 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar17 = 0;
      puVar6 = DAT_140e45d28;
      if (iVar19 < 0x96) {
        iVar17 = (int)(dVar24 * DAT_14053a5f8);
      }
    }
  }
  DAT_140e45d28 = puVar6;
  iVar19 = param_1[3];
  if (iVar19 < 0x5a) {
    FUN_14007ac00(param_1);
    iVar19 = param_1[3];
    param_1[0xb] = (float)iVar19 * _DAT_140539ccc + (float)param_1[0xb];
  }
  if (iVar19 == 0x5a) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
    FUN_14018a340(DAT_140e472a0,1,1);
    uVar2 = param_1[0xb];
    uVar29 = param_1[10];
    puVar6 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar6 + 0x14) = uVar29;
      *(undefined4 *)(puVar6 + 3) = uVar2;
      *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar29;
      *(undefined4 *)(puVar6 + 4) = uVar2;
      *puVar6 = 1;
      puVar6[1] = 0x11;
      *(undefined4 *)(puVar6 + 2) = 0x28;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0;
      if (bVar22) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    DAT_140e46a08 = DAT_140e418c8;
  }
  uVar2 = DAT_140e41ab8;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar7 = uVar2;
  puVar7[1] = 0x4e;
  *(undefined8 *)(puVar7 + 2) = 5;
  puVar7[4] = 0;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = iVar17;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  DAT_140e46c88 = puVar7;
  if (param_1[3] == 0x96) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
LAB_1400e8197:
  if (((int)param_1[5] < 2) ||
     ((puVar7 = DAT_140e46c88, param_1[5] == 2 && ((int)param_1[3] < 100)))) {
    FUN_1400c8410(DAT_140e44944,0x20,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffef0 & 0xffff0000,auVar32,0xff,0xff,0xff,0xff,1,0);
    uVar29 = DAT_140e4494c;
    fVar31 = DAT_14053adec;
    sVar13 = (short)DAT_140e418c8;
    uVar2 = param_1[10];
    fVar28 = (float)param_1[0xb] - DAT_14053adec;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[3] = uVar2;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[4] = fVar28;
    *puVar7 = uVar29;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    *(short *)(puVar7 + 5) = sVar13 * 0x500;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar29 = DAT_140e4494c;
    sVar13 = (short)DAT_140e418c8;
    fVar28 = (float)param_1[0xb];
    uVar2 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar29;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar2;
    puVar7[4] = fVar28 - fVar31;
    *(short *)(puVar7 + 5) = sVar13 * 0x500 + 0x4000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar29 = DAT_140e4494c;
    sVar13 = (short)DAT_140e418c8;
    fVar28 = (float)param_1[0xb];
    uVar2 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar29;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar2;
    puVar7[4] = fVar28 - fVar31;
    *(short *)(puVar7 + 5) = sVar13 * 0x500 + -0x8000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar29 = DAT_140e4494c;
    sVar13 = (short)DAT_140e418c8;
    fVar28 = (float)param_1[0xb];
    uVar2 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar29;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar2;
    puVar7[4] = fVar28 - fVar31;
    *(short *)(puVar7 + 5) = sVar13 * 0x500 + -0x4000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
  }
  DAT_140e46c88 = puVar7;
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


