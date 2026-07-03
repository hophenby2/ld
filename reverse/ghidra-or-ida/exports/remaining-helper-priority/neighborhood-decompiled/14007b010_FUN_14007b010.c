// Function: FUN_14007b010 @ 14007b010
// Decompile completed: true

void FUN_14007b010(longlong param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  double dVar16;
  uint in_stack_ffffffffffffff70;
  
  iVar8 = 1;
  iVar10 = 1;
  fVar13 = (float)FUN_140334430(DAT_140e445d8 - *(float *)(param_1 + 0x28));
  fVar14 = (float)FUN_140334430(DAT_140e445dc - *(float *)(param_1 + 0x2c));
  if (fVar13 + fVar14 < 0.0) {
    fVar13 = (float)FUN_1403352f8();
  }
  else {
    fVar13 = SQRT(fVar13 + fVar14);
  }
  uVar4 = DAT_14053accc;
  uVar3 = DAT_14053a248;
  iVar7 = (int)fVar13 - *(int *)(param_1 + 0x50);
  if (0 < param_2 - *(int *)(param_1 + 0x10)) {
    iVar10 = (int)((((double)param_2 - (double)*(int *)(param_1 + 0x10)) / (double)param_2) *
                  (double)*(int *)(param_1 + 0x24));
  }
  if (DAT_140e45d18 < 0) {
    iVar10 = iVar10 * 2;
  }
  if (0x31 < iVar10) {
    iVar9 = 0;
    iVar11 = iVar10 / 0x14;
    iVar10 = iVar10 + iVar11 * -10;
    iVar11 = (iVar11 * 10) / 10;
    if (0 < iVar11) {
      do {
        uVar5 = DAT_140e418c8 + 0x29a + iVar9;
        uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        DAT_140e9fd1c = uVar5;
        uVar15 = FUN_140134db0(DAT_140e418c8 + 0x22b + iVar9,DAT_140e9fd18,uVar3);
        in_stack_ffffffffffffff70 = uVar4;
        FUN_1400ca6d0(2,(ulonglong)uVar5 / 0x10001,*(undefined4 *)(param_1 + 0x2c),
                      (short)uVar5 - (short)(uVar5 / 0x10001),uVar15,uVar4);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar11);
    }
  }
  uVar4 = DAT_14053acb0;
  if (9 < iVar10) {
    iVar9 = 0;
    iVar11 = iVar10 / 10;
    iVar10 = iVar10 + iVar11 * -5;
    iVar11 = (iVar11 * 5) / 5;
    if (0 < iVar11) {
      do {
        uVar5 = DAT_140e418c8 + 0x1bc + iVar9;
        uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        DAT_140e9fd1c = uVar5;
        uVar15 = FUN_140134db0(DAT_140e418c8 + 0x14d + iVar9,DAT_140e9fd18,uVar3);
        in_stack_ffffffffffffff70 = uVar4;
        FUN_1400ca6d0(1,(ulonglong)uVar5 / 0x10001,*(undefined4 *)(param_1 + 0x2c),
                      (short)uVar5 - (short)(uVar5 / 0x10001),uVar15,uVar4);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar11);
    }
  }
  uVar4 = DAT_14053ac80;
  iVar11 = 0;
  if (0 < iVar10) {
    do {
      uVar5 = DAT_140e418c8 + 0xde + iVar11;
      uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      DAT_140e9fd1c = uVar5;
      uVar15 = FUN_140134db0(DAT_140e418c8 + 0x6f + iVar11,DAT_140e9fd18,uVar3);
      in_stack_ffffffffffffff70 = uVar4;
      FUN_1400ca6d0(0,(ulonglong)uVar5 / 0x10001,*(undefined4 *)(param_1 + 0x2c),
                    (short)uVar5 - (short)(uVar5 / 0x10001),uVar15,uVar4);
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar10);
  }
  if (iVar7 < 0x97) {
    iVar8 = 10;
  }
  else if ((iVar7 < 0x1c2) && (iVar8 = (0x1c2 - iVar7) / 0x1e, iVar8 < 1)) {
    iVar8 = 1;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  if (DAT_140e45d18 < 0) {
    iVar8 = 10;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  dVar16 = (double)*(int *)(param_1 + 0x50) + DAT_14053a3a0;
  puVar6 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar6 = (undefined8 *)_malloc_base(0x60);
    if (puVar6 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar6 = 1;
    puVar6[1] = 0x1d;
    *(undefined4 *)(puVar6 + 2) = 0;
    *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
    puVar6[5] = 0;
    *(undefined4 *)((longlong)puVar6 + 0x14) = uVar2;
    puVar6[6] = (double)iVar8;
    *(undefined4 *)(puVar6 + 3) = uVar1;
    *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar2;
    *(undefined4 *)(puVar6 + 4) = uVar1;
    puVar6[7] = dVar16;
    *(int *)(puVar6 + 8) = param_3 * 3;
    *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
    *(undefined4 *)(puVar6 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
    puVar6[10] = 0xc0;
    puVar6[0xb] = 0;
    if (bVar12) {
      DAT_140e45d78 = puVar6;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar6;
    }
  }
  DAT_140e45d28 = puVar6;
  dVar16 = DAT_140539f40;
  if ((float)iVar7 <= DAT_14053ae88) {
    dVar16 = DAT_140539f40 + (DAT_14053a758 - (double)iVar7) / DAT_14053a598;
  }
  DAT_140e45d88 = DAT_140e45d88 + (int)((double)(*(int *)(param_1 + 0x50) + 100) * dVar16);
  if (DAT_140e45d18 < 0) {
    in_stack_ffffffffffffff70 = 0;
    FUN_140109660(0x1a);
  }
  stage_entity_spawn_candidate
            (0x137,99999999,0,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
             in_stack_ffffffffffffff70 & 0xffff0000,(double)*(int *)(param_1 + 0x50) * DAT_140539f10
             ,*(int *)(param_1 + 0x50),1,0);
  if ((DAT_140e41b00 == 0) && (DAT_140e4417c = DAT_140e4417c + 1, iVar7 < 0x97)) {
    DAT_140e44180 = DAT_140e44180 + 1;
  }
  return;
}


