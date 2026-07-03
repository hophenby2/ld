// Function: FUN_1400e5260 @ 1400e5260
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e5260(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  short sVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  ushort uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  ushort uVar20;
  bool bVar21;
  double dVar22;
  float fVar23;
  undefined4 local_res8;
  undefined4 uStackX_c;
  uint in_stack_ffffffffffffff70;
  undefined2 uVar24;
  
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  uVar24 = (undefined2)(in_stack_ffffffffffffff70 >> 0x10);
  dVar22 = dVar22 * DAT_14053aba0;
  iVar19 = 0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_ffffffffffffff70 = in_stack_ffffffffffffff70 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_ffffffffffffff70,DAT_14053a4f0,
               param_1[0x14],1,0);
    uVar24 = (undefined2)(in_stack_ffffffffffffff70 >> 0x10);
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 300;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar17 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar12 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
    uVar17 = uVar17 * 0x800 ^ uVar17;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    uVar13 = DAT_1407c7798 * 0xde + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar12 >> 0xb ^ uVar17) >> 8 ^ uVar12 ^ uVar17) % 0x12d + 0xd2);
    uVar17 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar17 = uVar17 * 0x800 ^ uVar17;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ DAT_140e9fd18 ^ uVar17;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0xdc);
  }
  iVar7 = param_1[5];
  if (iVar7 == 0) {
    iVar7 = 0;
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar7 = param_1[5];
    }
    uVar1 = DAT_14053b358;
    uVar10 = DAT_140539f40;
    if (param_1[3] == 0x78) {
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate
                (0xc6,99999999,10,DAT_14053ace8,DAT_14053b358,CONCAT22(uVar24,0x4000),DAT_140539f40,
                 0x32,1,0);
      stage_entity_spawn_candidate(0xc6,99999999,10,DAT_14053b36c,uVar1,0x4000,uVar10,0x32,1,0);
      uVar1 = DAT_14053b388;
      stage_entity_spawn_candidate
                (0xc6,99999999,10,DAT_14053ad5c,DAT_14053b388,0x4000,uVar10,0x32,1,0);
      stage_entity_spawn_candidate(0xc6,99999999,10,DAT_14053b3a0,uVar1,0x4000,uVar10,0x32,1,0);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      iVar7 = param_1[5];
    }
    iVar14 = param_1[3];
    if (iVar14 < 0xbf) {
      iVar7 = (int)(float)param_1[0xd];
      if (iVar14 < 0) {
        param_1[0xb] = 0x44898000;
      }
      else {
        if (iVar14 < 0xb4) {
          dVar22 = (double)FUN_140332d90(((double)iVar14 - 0.0) * DAT_14053a438 * DAT_14053a020 *
                                         DAT_140539d28);
          iVar7 = (int)(dVar22 * (double)(iVar7 + -0x44c)) + 0x44c;
        }
        param_1[0xb] = (float)iVar7;
      }
    }
    else {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      if (iVar14 == 0xd2) {
        param_1[0x15] = 0;
        param_1[5] = iVar7 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 66000;
        DAT_140e4430c = 0x5dc;
        DAT_140e4192c = 0;
        param_1[7] = 66000;
        DAT_140e419bc = 1;
      }
    }
    goto LAB_1400e5b8b;
  }
  if (iVar7 == 1) {
    uVar20 = *(ushort *)(param_1 + 0x10);
    iVar14 = ((int)dVar22 & 0xffffU) - (uint)uVar20;
    iVar7 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar7 = iVar14;
    }
    iVar14 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar14 = iVar7;
    }
    uVar15 = (ushort)(int)dVar22;
    if (iVar14 < 1) {
      uVar16 = uVar20;
      if ((iVar14 < 0) && (uVar16 = uVar20 - 0x200, -0x200 < iVar14)) {
        uVar16 = uVar15;
      }
    }
    else {
      uVar16 = uVar15;
      if (0x1ff < iVar14) {
        uVar16 = uVar20 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar16;
    dVar22 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar22 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    goto LAB_1400e5b8b;
  }
  if (iVar7 != 2) goto LAB_1400e5b8b;
  iVar7 = param_1[3];
  iVar14 = 0;
  if (iVar7 < 0x5a) {
LAB_1400e55a6:
    iVar18 = 0;
    if (iVar7 < 0x96) {
      iVar18 = iVar14;
    }
    puVar8 = DAT_140e45d28;
    if (iVar7 == 1) {
      uVar1 = param_1[0xb];
      uVar2 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar2;
        *(undefined4 *)(puVar8 + 3) = uVar1;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar2;
        *(undefined4 *)(puVar8 + 4) = uVar1;
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
    iVar14 = 0xff;
    if (iVar7 < 100) {
      dVar22 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a430) * DAT_14053a9d8 * DAT_14053a020
                                     * DAT_140539d28);
      iVar18 = (int)(dVar22 * DAT_14053a5f8);
      puVar8 = DAT_140e45d28;
    }
    else {
      if (0x95 < iVar7) goto LAB_1400e55a6;
      dVar22 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a380) * DAT_14053a670 * DAT_14053a020
                                     * DAT_140539d28);
      iVar18 = 0;
      puVar8 = DAT_140e45d28;
      if (iVar7 < 0x96) {
        iVar18 = (int)(dVar22 * DAT_14053a5f8);
      }
    }
  }
  DAT_140e45d28 = puVar8;
  iVar7 = param_1[3];
  if (iVar7 < 0x5a) {
    FUN_14007ac00(param_1);
    iVar7 = param_1[3];
    param_1[0xb] = (float)iVar7 * _DAT_140539ccc + (float)param_1[0xb];
  }
  if (iVar7 == 0x5a) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
    FUN_14018a340(DAT_140e472a0,1,1);
    uVar1 = param_1[0xb];
    uVar2 = param_1[10];
    puVar8 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar8 = (undefined8 *)_malloc_base(0x60);
      if (puVar8 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar8 + 0x14) = uVar2;
      *(undefined4 *)(puVar8 + 3) = uVar1;
      *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar2;
      *(undefined4 *)(puVar8 + 4) = uVar1;
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
    DAT_140e46a08 = DAT_140e418c8;
  }
  uVar1 = DAT_140e41ab8;
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar9 = uVar1;
  puVar9[1] = 0x4e;
  *(undefined8 *)(puVar9 + 2) = 5;
  puVar9[4] = 0;
  *(undefined2 *)(puVar9 + 5) = 0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = iVar18;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
  DAT_140e46c88 = puVar9;
  if (param_1[3] == 0x96) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
LAB_1400e5b8b:
  if (((int)param_1[5] < 2) || ((param_1[5] == 2 && ((int)param_1[3] < 100)))) {
    iVar7 = FUN_1400c9580(param_1[3],0,6,4,100,0x65,0x66,0x65);
    uVar2 = DAT_140e44930;
    fVar3 = DAT_14053ade8;
    fVar5 = DAT_14053ad80;
    sVar4 = (short)DAT_140e418c8;
    uVar1 = param_1[10];
    fVar23 = ((float)param_1[0xb] - DAT_14053ad80) + DAT_14053ade8;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar9[3] = uVar1;
    puVar9[4] = fVar23;
    *puVar9 = uVar2;
    puVar9[1] = 0x1e;
    puVar9[2] = 7;
    *(short *)(puVar9 + 5) = sVar4 * 600;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar2 = DAT_140e44930;
    sVar4 = (short)DAT_140e418c8;
    fVar23 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar2;
    puVar9[1] = 0x1e;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = (fVar23 - fVar5) + fVar3;
    *(short *)(puVar9 + 5) = sVar4 * 600 + 0x4000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar2 = DAT_140e44930;
    sVar4 = (short)DAT_140e418c8;
    fVar23 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar2;
    puVar9[1] = 0x1e;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = (fVar23 - fVar5) + fVar3;
    *(short *)(puVar9 + 5) = sVar4 * 600 + -0x8000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar2 = DAT_140e44930;
    fVar23 = (float)param_1[0xb];
    sVar4 = (short)DAT_140e418c8;
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar2;
    puVar9[1] = 0x1e;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = (fVar23 - fVar5) + fVar3;
    *(short *)(puVar9 + 5) = sVar4 * 600 + -0x4000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar2 = DAT_140e4492c;
    fVar3 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d08 = DAT_140e46d08 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar9[3] = uVar1;
    puVar9[4] = (fVar3 - fVar5) + fVar5;
    *puVar9 = uVar2;
    puVar9[1] = 0x1e;
    puVar9[2] = 7;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    if (param_1[5] == 2) {
      iVar7 = FUN_1400c9580(param_1[3],0,5,2,0x6c,0x6d);
    }
    fVar3 = (float)param_1[0xb];
    uVar1 = param_1[10];
    uVar2 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar7 * 4);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d0c = DAT_140e46d0c + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar9[3] = uVar1;
    puVar9[4] = fVar3 - fVar5;
    *puVar9 = uVar2;
    puVar9[1] = 0x1f;
    puVar9[2] = 0x17;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 10) = 0;
    puVar9[0xc] = 0;
    puVar9[0xd] = 0x40;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    fVar3 = (float)param_1[0xb];
    uVar1 = param_1[10];
    uVar2 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar7 * 4);
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d10 = DAT_140e46d10 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar9[3] = uVar1;
    puVar9[4] = fVar3 - fVar5;
    *puVar9 = uVar2;
    puVar9[1] = 0x20;
    puVar9[2] = 7;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xc0;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar9;
    }
    uVar1 = DAT_14053adc0;
    uVar2 = DAT_14053ad40;
    fVar3 = DAT_14053acfc;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      uVar1 = DAT_14053adc0;
      uVar2 = DAT_14053ad40;
      fVar3 = DAT_14053acfc;
    }
    do {
      DAT_140e46c88 = puVar9;
      iVar7 = (DAT_140e418c8 & 0xffff) * 0xde;
      uVar20 = (short)iVar19 * 0x13b1 + (short)iVar7;
      uVar10 = FUN_140133f30(iVar7,((float)param_1[0xb] - fVar5) + fVar3,0,uVar20,uVar2,uVar1);
      uVar6 = DAT_140e44b90;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar10;
      uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[3] = local_res8;
      lVar11 = 0x80;
      if (0x8000 < uVar20) {
        lVar11 = 0x7c;
      }
      puVar9[4] = uStackX_c;
      *puVar9 = uVar6;
      puVar9[1] = 0x20 - (uint)(0x8000 < uVar20);
      puVar9[2] = 7;
      *(undefined2 *)(puVar9 + 5) = 0;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = 0xff;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      *(int *)((longlong)&DAT_140e46c90 + lVar11) = *(int *)((longlong)&DAT_140e46c90 + lVar11) + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      iVar19 = iVar19 + 1;
      DAT_140e46c88 = puVar9;
    } while (iVar19 < 0xd);
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


