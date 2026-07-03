// Function: FUN_14000ed10 @ 14000ed10
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000ed10(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  longlong lVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int *piVar18;
  undefined2 uVar19;
  ushort uVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  float fVar25;
  ulonglong in_stack_fffffffffffffef0;
  undefined4 uVar28;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined8 in_stack_fffffffffffffef8;
  undefined8 uVar29;
  undefined4 uVar30;
  undefined8 in_stack_ffffffffffffff00;
  undefined4 uVar31;
  
  uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  uVar31 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar23 = DAT_14053aba0;
  uVar17 = (uint)(dVar22 * DAT_14053aba0);
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffffffffffff0000;
    uVar29 = DAT_14053a4f0;
    stage_entity_spawn_candidate(0x137,99999999,0);
    uVar30 = (undefined4)((ulonglong)uVar29 >> 0x20);
    if (DAT_140e41af8 == 1) {
      param_1[5] = 8;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      param_1[5] = 6;
      DAT_140e419bc = 2;
    }
    else {
      if (DAT_140e41af8 == 3) {
        param_1[5] = 4;
      }
      else {
        if (DAT_140e41af8 != 4) goto LAB_14000ee49;
        param_1[5] = 2;
      }
      DAT_140e419bc = 2;
      param_1[0x14] = 200;
    }
LAB_14000ee49:
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar29 = _DAT_14053bb20;
  uVar28 = (undefined4)(in_stack_fffffffffffffef0 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar15 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar9 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
    uVar10 = DAT_1407c7798 * 0x14d + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar9 >> 0xb ^ uVar15) >> 8 ^ uVar9 ^ uVar15) % 0x12d + 0xd2);
    uVar15 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  iVar6 = param_1[5];
  iVar13 = 0;
  uVar20 = (ushort)uVar17;
  switch(iVar6) {
  case 0:
    if (param_1[3] == 0) {
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate(0x30,10000,0x30);
      stage_entity_spawn_candidate(0x30,10000,0x30);
      stage_entity_spawn_candidate(0x31,99999999,0);
      stage_entity_spawn_candidate(0x31,99999999,0);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar6 = param_1[5];
      DAT_140e44ac8 = 0;
    }
    uVar17 = param_1[3];
    if ((int)uVar17 < 0x3d) {
      iVar13 = (int)((float)param_1[0xd] - DAT_14053ae48);
      iVar16 = (int)((float)param_1[0xd] + DAT_14053adb4);
      iVar6 = iVar13;
      if (-1 < (int)uVar17) {
        iVar6 = iVar16;
      }
      if (uVar17 < 0x3c) {
        dVar23 = (double)FUN_140332d90(((double)(int)uVar17 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                       DAT_140539d28);
        iVar6 = (int)(dVar23 * (double)(iVar16 - iVar13)) + iVar13;
      }
      param_1[0xb] = (float)iVar6;
    }
    else if ((int)uVar17 < 0xb5) {
      fVar25 = (float)param_1[0xd] + DAT_14053adb4;
      iVar13 = (int)(float)param_1[0xd];
      if ((int)uVar17 < 0xb4) {
        dVar23 = (double)FUN_140332d90(((double)(int)uVar17 - _DAT_14053b158) * DAT_14053a4d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar13 = (int)(dVar23 * (double)((int)fVar25 - iVar13)) + iVar13;
      }
      param_1[0xb] = (float)iVar13;
      if (uVar17 == 0xb4) {
        param_1[0x15] = 0;
        param_1[5] = iVar6 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 70000;
        DAT_140e4430c = 0x708;
        DAT_140e4192c = 0;
        param_1[7] = 70000;
        DAT_140e419bc = 1;
      }
    }
    break;
  case 1:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar17 & 0xffff) - (uint)uVar2;
    iVar6 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar6 = iVar13;
    }
    iVar13 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar13 = iVar6;
    }
    if (iVar13 < 1) {
      uVar14 = uVar2;
      if ((iVar13 < 0) && (uVar14 = uVar2 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar20;
      }
    }
    else {
      uVar14 = uVar20;
      if (0x1ff < iVar13) {
        uVar14 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar22 = (double)FUN_1403307c0();
    fVar24 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar24;
    dVar22 = (double)FUN_140332d90();
    fVar25 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar25;
    iVar6 = (int)param_1[3] % 1000;
    dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar25 + DAT_14053ad5c)),
                                   (double)(DAT_140e445d8 - fVar24));
    uVar30 = DAT_140e41a50;
    if (400 < iVar6) break;
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 0x14;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0x24;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 0x32;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar13 = 0x3c;
    }
    if (iVar6 == 0x32) {
      uVar31 = param_1[1];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base();
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        puVar8[6] = 0x4014000000000000;
        puVar8[7] = 0x4014000000000000;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        *(undefined4 *)(puVar8 + 10) = 0xff;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar30;
        puVar8[2] = 0x23;
        puVar8[3] = 0x430c0000;
        *(undefined4 *)(puVar8 + 4) = 0x430c0000;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        *(undefined4 *)(puVar8 + 8) = 0x1e;
        *(undefined4 *)((longlong)puVar8 + 0x54) = uVar31;
        puVar8[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
LAB_14000f9c7:
      if (0x13f < iVar6 - 0x50U) break;
    }
    else {
      if ((0x13f < iVar6 - 0x50U) || (iVar6 + -0x50 != ((iVar6 + -0x50) / 0x50) * 0x50))
      goto LAB_14000f9c7;
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar22 * dVar23);
    }
    if ((iVar6 + -0x50) % 0x50 < iVar13) {
      uVar17 = (iVar6 + -0x50) % 0x50 & 0x80000003;
      if ((int)uVar17 < 0) {
        uVar17 = (uVar17 - 1 | 0xfffffffc) + 1;
      }
      if (uVar17 == 0) {
        FUN_1400709b0(0xc,0,fVar24);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    break;
  case 2:
    iVar6 = param_1[3];
    iVar16 = 0;
    if (iVar6 < 0x5a) {
LAB_14000fd39:
      if (iVar6 < 0xb4) {
        iVar13 = iVar16;
      }
      puVar8 = DAT_140e45d28;
      if (iVar6 == 1) {
        uVar30 = param_1[0xb];
        uVar31 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar8 = (undefined8 *)_malloc_base(0x60);
          if (puVar8 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar8 + 0x14) = uVar31;
          *(undefined4 *)(puVar8 + 3) = uVar30;
          *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar31;
          *(undefined4 *)(puVar8 + 4) = uVar30;
          *puVar8 = 1;
          puVar8[1] = 0x36;
          *(undefined4 *)(puVar8 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
          puVar8[5] = 0;
          puVar8[6] = 0x3ff0000000000000;
          puVar8[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar8 + 8) = 0;
          *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
          *(undefined4 *)(puVar8 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
          puVar8[10] = 0xff;
          puVar8[0xb] = 0;
          if (bVar21) {
            DAT_140e45d78 = puVar8;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar8;
          }
        }
      }
    }
    else {
      iVar16 = 0xff;
      if (iVar6 < 100) {
        dVar23 = (double)FUN_140332d90(((double)iVar6 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar13 = (int)(dVar23 * DAT_14053a5f8);
        puVar8 = DAT_140e45d28;
      }
      else {
        if (0xb3 < iVar6) goto LAB_14000fd39;
        dVar23 = (double)FUN_140332d90(((double)iVar6 - DAT_14053a278) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar13 = 0;
        puVar8 = DAT_140e45d28;
        if (iVar6 < 0xb4) {
          iVar13 = (int)(dVar23 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar8;
    iVar6 = param_1[3];
    if (iVar6 < 0x5a) {
      param_1[0xb] = (float)iVar6 * _DAT_140539cd4 + (float)param_1[0xb];
      FUN_14007ac00(param_1);
    }
    uVar30 = DAT_140e472a0;
    iVar6 = param_1[3];
    if (iVar6 == 0x5a) {
      *(undefined8 *)(param_1 + 0x12) = 0x4008000000000000;
      FUN_140184700(DAT_140e44190 * 0x19,uVar30);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar30 = param_1[0xb];
      uVar31 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar31;
        *(undefined4 *)(puVar8 + 3) = uVar30;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar31;
        *(undefined4 *)(puVar8 + 4) = uVar30;
        *puVar8 = 1;
        puVar8[1] = 0x11;
        *(undefined4 *)(puVar8 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      iVar6 = param_1[3];
    }
    if (0x59 < iVar6) {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar16 = (uVar17 & 0xffff) - (uint)uVar2;
      iVar6 = iVar16 + 0x10000;
      if (-0x8001 < iVar16) {
        iVar6 = iVar16;
      }
      iVar16 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar16 = iVar6;
      }
      if (iVar16 < 1) {
        uVar14 = uVar2;
        if ((iVar16 < 0) && (uVar14 = uVar2 - 0x309, -0x309 < iVar16)) {
          uVar14 = uVar20;
        }
      }
      else {
        uVar14 = uVar20;
        if (0x308 < iVar16) {
          uVar14 = uVar2 + 0x309;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar23 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar23 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    uVar30 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar7 = uVar30;
    puVar7[1] = 0x4e;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar13;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    if (param_1[3] != 200) break;
    iVar6 = param_1[5];
    *(undefined8 *)(param_1 + 0x14) = 0x96;
    param_1[3] = 0;
    if (iVar6 == 2) {
      DAT_140e41b0c = 66000;
LAB_14000ff5c:
      DAT_140e4430c = 0x708;
      DAT_140e4192c = 0;
    }
    goto LAB_14000ff7b;
  case 3:
    if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x19) * 0x19) {
      uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar15 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 4;
      uVar10 = DAT_1407c7798 * 0x14d + DAT_140e418c8;
      DAT_140e44908 = (float)(((uVar15 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ uVar15) % 0x12d + 0xd2);
      uVar9 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
      uVar15 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
      DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x78);
    }
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar17 & 0xffff) - (uint)uVar2;
    iVar6 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar6 = iVar13;
    }
    iVar13 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar13 = iVar6;
    }
    if (iVar13 < 1) {
      uVar14 = uVar2;
      if ((iVar13 < 0) && (uVar14 = uVar2 - 0x309, -0x309 < iVar13)) {
        uVar14 = uVar20;
      }
    }
    else {
      uVar14 = uVar20;
      if (0x308 < iVar13) {
        uVar14 = uVar2 + 0x309;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar22 = (double)FUN_1403307c0();
    fVar24 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar24;
    dVar22 = (double)FUN_140332d90();
    fVar25 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar25;
    iVar13 = (int)param_1[3] % 0x4b0;
    dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar25 + DAT_14053ad5c)),
                                   (double)(DAT_140e445d8 - fVar24));
    uVar30 = DAT_140e41a50;
    iVar6 = DAT_140e419b8;
    uVar20 = (ushort)(int)(dVar22 * dVar23);
    if (iVar13 < 0x119) {
      iVar16 = 1;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x28;
      }
      else if (DAT_140e419b8 == 1) {
        iVar16 = 0x24;
      }
      else if (DAT_140e419b8 == 2) {
        iVar16 = 0x1e;
      }
      else if (DAT_140e419b8 == 3) {
        iVar16 = 0x14;
      }
      else if (DAT_140e419b8 == 4) {
        iVar16 = 0x10;
      }
      if (iVar13 == 1) {
        uVar31 = param_1[1];
        puVar8 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar8 = (undefined8 *)_malloc_base();
          if (puVar8 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar8 + 0xc) = uVar30;
          puVar8[6] = 0x4014000000000000;
          puVar8[7] = 0x4014000000000000;
          *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
          *(undefined4 *)(puVar8 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
          *(undefined4 *)(puVar8 + 10) = 0xff;
          *puVar8 = 1;
          *(undefined4 *)(puVar8 + 1) = 0x31;
          puVar8[2] = 0x23;
          puVar8[3] = 0x430c0000;
          *(undefined4 *)(puVar8 + 4) = 0x430c0000;
          *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
          puVar8[5] = 0;
          *(undefined4 *)(puVar8 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar8 + 0x54) = uVar31;
          puVar8[0xb] = 0;
          if (bVar21) {
            DAT_140e45d78 = puVar8;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar8;
          }
        }
        DAT_140e45d28 = puVar8;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
LAB_1400103e6:
        iVar6 = DAT_140e419b8;
        if (0xf9 < iVar13 - 0x1eU) goto LAB_1400104df;
      }
      else {
        if ((0xf9 < iVar13 - 0x1eU) || ((iVar13 + -0x1e) % (iVar16 * 3) != 0)) goto LAB_1400103e6;
        *(ushort *)((longlong)param_1 + 0x42) = uVar20;
      }
      if ((iVar13 + -0x1e) % iVar16 == 0) {
        if (0 < iVar6) {
          FUN_1400709b0(1,0,fVar24);
        }
        FUN_1400709b0(5,0,fVar24);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar6 = DAT_140e419b8;
      }
    }
LAB_1400104df:
    if (iVar13 - 0x140U < 0x154) {
      iVar16 = 0x140;
      iVar12 = 1;
      if (iVar6 == 0) {
        iVar12 = 0x46;
      }
      else if (iVar6 == 1) {
        iVar12 = 0x32;
      }
      else if (((iVar6 == 2) || (iVar6 == 3)) || (iVar6 == 4)) {
        iVar12 = 0x28;
      }
      iVar6 = 0;
      do {
        iVar5 = iVar16 + 0x1e + iVar6;
        if (iVar13 == iVar16) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar20;
LAB_140010658:
          if (((iVar13 < iVar5) || (iVar5 == 0)) && (iVar13 - iVar16 == ((iVar13 - iVar16) / 5) * 5)
             ) {
            FUN_1400709b0(3,0,fVar24);
            if (2 < DAT_140e419b8) {
              FUN_1400709b0(3,0,fVar24);
            }
            uVar2 = *(ushort *)((longlong)param_1 + 0x42);
            iVar11 = ((int)(dVar22 * dVar23) & 0xffffU) - (uint)uVar2;
            iVar5 = iVar11 + 0x10000;
            if (-0x8001 < iVar11) {
              iVar5 = iVar11;
            }
            iVar11 = iVar5 + -0x10000;
            if (iVar5 < 0x8001) {
              iVar11 = iVar5;
            }
            if (iVar11 < 1) {
              uVar14 = uVar2;
              if ((iVar11 < 0) && (uVar14 = uVar2 - 0x78, -0x78 < iVar11)) {
                uVar14 = uVar20;
              }
            }
            else {
              uVar14 = uVar20;
              if (0x77 < iVar11) {
                uVar14 = uVar2 + 0x78;
              }
            }
            *(ushort *)((longlong)param_1 + 0x42) = uVar14;
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        else if (iVar16 <= iVar13) goto LAB_140010658;
        iVar5 = iVar6 + iVar12;
        iVar6 = iVar6 + 0xf;
        iVar16 = iVar16 + iVar5;
      } while (iVar6 < 0x78);
    }
    break;
  case 4:
    iVar6 = param_1[3];
    iVar16 = iVar13;
    if (iVar6 < 0x78) {
LAB_140010a2b:
      if (iVar6 < 0xdc) {
        iVar13 = iVar16;
      }
      puVar8 = DAT_140e45d28;
      if (iVar6 == 1) {
        uVar31 = param_1[0xb];
        uVar1 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar8 = (undefined8 *)_malloc_base(0x60);
          if (puVar8 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar8 + 0x14) = uVar1;
          *(undefined4 *)(puVar8 + 3) = uVar31;
          *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar1;
          *(undefined4 *)(puVar8 + 4) = uVar31;
          *puVar8 = 1;
          puVar8[1] = 0x36;
          *(undefined4 *)(puVar8 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
          puVar8[5] = 0;
          puVar8[6] = 0x3ff0000000000000;
          puVar8[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar8 + 8) = 0;
          *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
          *(undefined4 *)(puVar8 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
          puVar8[10] = 0xff;
          puVar8[0xb] = 0;
          if (bVar21) {
            DAT_140e45d78 = puVar8;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar8;
          }
        }
      }
    }
    else {
      iVar16 = 0xff;
      if (iVar6 < 0x82) {
        dVar23 = (double)FUN_140332d90(((double)iVar6 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar13 = (int)(dVar23 * DAT_14053a5f8);
        puVar8 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar6) goto LAB_140010a2b;
        dVar23 = (double)FUN_140332d90(((double)iVar6 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar8 = DAT_140e45d28;
        if (iVar6 < 0xdc) {
          iVar13 = (int)(dVar23 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar8;
    iVar6 = param_1[3];
    if (iVar6 < 0x78) {
      FUN_14007ac00(param_1);
      iVar6 = param_1[3];
      param_1[0xb] = (float)iVar6 * _DAT_140539ccc + (float)param_1[0xb];
    }
    uVar31 = DAT_140e472a0;
    puVar8 = DAT_140e45d28;
    if (iVar6 == 0x78) {
      *(undefined8 *)(param_1 + 0x12) = 0x3fe0000000000000;
      FUN_140184700(DAT_140e44190 * 0x19,uVar31);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar31 = param_1[0xb];
      uVar1 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar1;
        *(undefined4 *)(puVar8 + 3) = uVar31;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar1;
        *(undefined4 *)(puVar8 + 4) = uVar31;
        *puVar8 = 1;
        puVar8[1] = 0x11;
        *(undefined4 *)(puVar8 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
    }
    DAT_140e45d28 = puVar8;
    iVar6 = param_1[3];
    if (0xdb < iVar6) {
      FUN_140001900(iVar6,0xdc,2);
    }
    iVar6 = param_1[3];
    if (0x81 < iVar6) {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar12 = (uVar17 & 0xffff) - (uint)uVar2;
      iVar16 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar16 = iVar12;
      }
      iVar12 = iVar16 + -0x10000;
      if (iVar16 < 0x8001) {
        iVar12 = iVar16;
      }
      if (iVar12 < 1) {
        uVar14 = uVar2;
        if ((iVar12 < 0) && (uVar14 = uVar2 - 0x200, -0x200 < iVar12)) {
          uVar14 = uVar20;
        }
      }
      else {
        uVar14 = uVar20;
        if (0x1ff < iVar12) {
          uVar14 = uVar2 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar23 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar23 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar6 = FUN_1400c9580(iVar6,0,7,3,0x14,CONCAT44(uVar28,0x15),CONCAT44(uVar30,0x16));
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar6 * 4),0x1e,7);
    }
    uVar30 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar7 = uVar30;
    puVar7[1] = 0x4e;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar13;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    if (param_1[3] != 0x17c) break;
    iVar6 = param_1[5];
    *(undefined8 *)(param_1 + 0x14) = 0x50;
    param_1[3] = 0;
    if (iVar6 == 4) {
      DAT_140e41b0c = 40000;
      goto LAB_14000ff5c;
    }
LAB_14000ff7b:
    param_1[7] = DAT_140e41b0c;
    param_1[5] = iVar6 + 1;
    DAT_140e419bc = 1;
    break;
  case 5:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar17 & 0xffff) - (uint)uVar2;
    iVar6 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar6 = iVar13;
    }
    iVar13 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar13 = iVar6;
    }
    if (iVar13 < 1) {
      uVar14 = uVar2;
      if ((iVar13 < 0) && (uVar14 = uVar2 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar20;
      }
    }
    else {
      uVar14 = uVar20;
      if (0x1ff < iVar13) {
        uVar14 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar22 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar25;
    dVar22 = (double)FUN_140332d90();
    iVar6 = DAT_140e419b8;
    iVar13 = 1;
    param_1[0xb] = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (iVar6 == 0) {
      iVar13 = 0x96;
    }
    else if (iVar6 == 1) {
      iVar13 = 0x78;
    }
    else if (((iVar6 == 2) || (iVar6 == 3)) || (iVar6 == 4)) {
      iVar13 = 100;
    }
    iVar16 = 1;
    uVar27 = (longlong)(param_1[3] + -10) % (longlong)(iVar13 * 2);
    if (iVar6 == 0) {
      iVar16 = 10;
    }
    else if (iVar6 == 1) {
      iVar16 = 9;
    }
    else if (((iVar6 == 2) || (iVar6 == 3)) || (iVar6 == 4)) {
      iVar16 = 8;
    }
    dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - _DAT_14053b434),
                                   (double)(DAT_140e445d8 - fVar25));
    fVar25 = DAT_14053ac34;
    uVar17 = (uint)uVar27;
    uVar19 = (undefined2)(int)(dVar22 * dVar23);
    if ((uVar17 < 0x3c) &&
       ((int)((longlong)((ulonglong)(uint)((int)uVar17 >> 0x1f) << 0x20 | uVar27 & 0xffffffff) %
             (longlong)iVar16) == 0)) {
      uVar26 = CONCAT44(uVar31,0x1e);
      in_stack_fffffffffffffef0 = CONCAT62((int6)(in_stack_fffffffffffffef0 >> 0x10),uVar19);
      stage_entity_spawn_candidate
                (0x32,500,4,(float)(int)uVar17 * DAT_14053ac34,0,in_stack_fffffffffffffef0,uVar29,
                 uVar26,1,param_1[1]);
      uVar30 = (undefined4)((ulonglong)uVar29 >> 0x20);
      uVar31 = (undefined4)((ulonglong)uVar26 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar28 = (undefined4)(in_stack_fffffffffffffef0 >> 0x20);
    if (((iVar13 <= (int)uVar17) && ((int)uVar17 < iVar13 + 0x3c)) &&
       ((int)(uVar17 - iVar13) % iVar16 == 0)) {
      uVar26 = CONCAT62((int6)(in_stack_fffffffffffffef0 >> 0x10),uVar19);
      uVar29 = DAT_140539f90;
      stage_entity_spawn_candidate
                (0x33,500,4,DAT_14053af14 - (float)(int)(uVar17 - iVar13) * fVar25,0,uVar26,
                 DAT_140539f90,CONCAT44(uVar31,0x1e),1,param_1[1]);
      uVar28 = (undefined4)((ulonglong)uVar26 >> 0x20);
      uVar30 = (undefined4)((ulonglong)uVar29 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    if (((0x1d < DAT_140e44ac8) && (DAT_140e41b00 == 0)) &&
       ((DAT_140e467e8 == 0 && (DAT_140e4403c == 0)))) {
      DAT_140e4403c = 1;
      FUN_1400b4350(1,0x16);
      save_init_or_reset_candidate();
      DAT_140e45f68 = 0x3c;
    }
    iVar6 = FUN_1400c9580(param_1[3],0,7,3,0x14,CONCAT44(uVar28,0x15),CONCAT44(uVar30,0x16));
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar6 * 4),0x1e,7);
    break;
  case 6:
    iVar6 = param_1[3];
    FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a558 * DAT_14053a020 * DAT_140539d28);
    puVar8 = DAT_140e45d28;
    if (iVar6 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar30 = param_1[0xb];
      uVar31 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar31;
        *(undefined4 *)(puVar8 + 3) = uVar30;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar31;
        *(undefined4 *)(puVar8 + 4) = uVar30;
        *puVar8 = 1;
        puVar8[1] = 0x36;
        *(undefined4 *)(puVar8 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
    }
    DAT_140e45d28 = puVar8;
    piVar18 = param_1 + 3;
    if (*piVar18 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar6 = FUN_1400c9580(*piVar18,0,5,2,0x17,0x18);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar6 * 4),0x1e,7);
    if (*piVar18 == 0xb4) {
      iVar6 = param_1[5];
      param_1[0x15] = 0;
      *piVar18 = 0;
      if (iVar6 == 6) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 50000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar6 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 7:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar17 & 0xffff) - (uint)uVar2;
    iVar6 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar6 = iVar13;
    }
    iVar13 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar13 = iVar6;
    }
    if (iVar13 < 1) {
      uVar14 = uVar2;
      if ((iVar13 < 0) && (uVar14 = uVar2 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar20;
      }
    }
    else {
      uVar14 = uVar20;
      if (0x1ff < iVar13) {
        uVar14 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar23 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar23 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    puVar8 = DAT_140e45d28;
    if ((param_1[3] == 1) && (uVar30 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar8 = (undefined8 *)_malloc_base(0x60);
      if (puVar8 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar8 = 1;
      puVar8[1] = 0x2d;
      puVar8[2] = 0x3c;
      puVar8[3] = 0;
      *(undefined4 *)(puVar8 + 4) = 0;
      *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
      puVar8[5] = 0x3ff0000000000000;
      puVar8[6] = 0x3ff0000000000000;
      puVar8[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar8 + 8) = 0x28;
      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
      *(undefined4 *)(puVar8 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
      *(undefined4 *)(puVar8 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar8 + 0x54) = uVar30;
      puVar8[0xb] = 0;
      if (bVar21) {
        DAT_140e45d78 = puVar8;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar8;
      }
    }
    DAT_140e45d28 = puVar8;
    if (param_1[3] == 10) {
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate(0x34,9000,0x18);
      stage_entity_spawn_candidate(0x34,9000,0x18);
      stage_entity_spawn_candidate(0x34,9000,0x18);
      stage_entity_spawn_candidate(0x34,9000,0x18);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      param_1[0x17] = 4;
    }
    if ((((0x1d < DAT_140e44ac8) && (DAT_140e41b00 == 0)) && (DAT_140e467e8 == 0)) &&
       (DAT_140e4403c == 0)) {
      DAT_140e4403c = 1;
      FUN_1400b4350(1,0x16);
      save_init_or_reset_candidate();
      DAT_140e45f68 = 0x3c;
    }
    piVar18 = param_1 + 3;
    iVar6 = FUN_1400c9580(*piVar18,0,7,3,0x14,0x15,0x16);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar6 * 4),0x1e,7);
    if ((99 < *piVar18) && (param_1[0x17] == 0)) {
      *piVar18 = 0;
    }
    break;
  case 8:
    FUN_140003ad0(param_1);
    iVar6 = param_1[3];
    if (iVar6 < 0xf0) {
      iVar13 = DAT_1407c7798 + 3;
      iVar16 = DAT_1407c7798 * 10;
      if (iVar6 - 0x3cU < 0xb4) {
        uVar27 = 0;
        FUN_1401349e0(iVar6,0x3c,0x4c,0xe0,0xf0,0,uVar29);
        uVar27 = uVar27 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1);
        uVar27 = uVar27 & 0xffffffffffff0000;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar13 * 4),0x6e,1);
        uVar28 = (undefined4)(uVar27 >> 0x20);
        if (iVar6 == 0x4c) {
          FUN_14012e070(iVar16 + 99,4);
        }
        else {
          lVar3 = DAT_140e47908;
          if (iVar6 == 0xe0) {
            while (lVar3 != 0) {
              lVar3 = *(longlong *)(lVar3 + 0x238);
              FUN_140323ce8();
              uVar28 = (undefined4)(uVar27 >> 0x20);
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar6 = FUN_1400c9580(param_1[3],0,5,2,0x17,CONCAT44(uVar28,0x18));
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar6 * 4),0x1e,7);
    }
    puVar8 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar30 = param_1[0xb];
      uVar31 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar31;
        *(undefined4 *)(puVar8 + 3) = uVar30;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar31;
        *(undefined4 *)(puVar8 + 4) = uVar30;
        *puVar8 = 1;
        puVar8[1] = 0x10;
        *(undefined4 *)(puVar8 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
    }
    DAT_140e45d28 = puVar8;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
  }
  if (((int)param_1[5] < 4) ||
     ((puVar7 = DAT_140e46c88, param_1[5] == 4 && ((int)param_1[3] < 0x82)))) {
    FUN_1400c8410(DAT_140e44944,0x20,7);
    uVar31 = DAT_140e4494c;
    fVar25 = DAT_14053adec;
    sVar4 = (short)DAT_140e418c8;
    uVar30 = param_1[10];
    fVar24 = (float)param_1[0xb] - DAT_14053adec;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[3] = uVar30;
    puVar7[4] = fVar24;
    *puVar7 = uVar31;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    *(short *)(puVar7 + 5) = sVar4 * 0x500;
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
    uVar31 = DAT_140e4494c;
    sVar4 = (short)DAT_140e418c8;
    fVar24 = (float)param_1[0xb];
    uVar30 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar31;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar30;
    puVar7[4] = fVar24 - fVar25;
    *(short *)(puVar7 + 5) = sVar4 * 0x500 + 0x4000;
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
    uVar31 = DAT_140e4494c;
    sVar4 = (short)DAT_140e418c8;
    fVar24 = (float)param_1[0xb];
    uVar30 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar31;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar30;
    puVar7[4] = fVar24 - fVar25;
    *(short *)(puVar7 + 5) = sVar4 * 0x500 + -0x8000;
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
    uVar31 = DAT_140e4494c;
    sVar4 = (short)DAT_140e418c8;
    fVar24 = (float)param_1[0xb];
    uVar30 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar31;
    puVar7[1] = 0x22;
    puVar7[2] = 7;
    puVar7[3] = uVar30;
    puVar7[4] = fVar24 - fVar25;
    *(short *)(puVar7 + 5) = sVar4 * 0x500 + -0x4000;
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


