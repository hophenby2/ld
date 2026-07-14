// Function: FUN_140004140 @ 140004140
// Decompile completed: true

void FUN_140004140(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  double dVar4;
  short sVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  bool bVar13;
  double dVar14;
  float fVar15;
  double dVar16;
  float fVar17;
  float fVar18;
  
  uVar9 = DAT_140e418c8;
  puVar7 = DAT_140e45d28;
  if (((*(int *)(param_1 + 0x54) == 0) && (DAT_140e445fc - 0xb4U < 0x50)) &&
     (DAT_140e445fc % 5 == 4)) {
    uVar12 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar6 = uVar12 ^ uVar12 * 0x800;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    uVar6 = (DAT_140e9fd18 >> 0xb ^ uVar6) >> 8 ^ DAT_140e9fd18 ^ uVar6;
    uVar11 = (short)uVar6 - (short)(uVar6 / 0x10001);
    iVar10 = DAT_140e9fd1c % 0x79 + 0x78;
    fVar17 = (float)iVar10;
    dVar16 = (double)uVar11 * DAT_14053a020 * DAT_140539d28;
    dVar4 = (double)iVar10;
    dVar14 = (double)FUN_1403307c0(dVar16);
    fVar18 = (float)(dVar14 * dVar4) + *(float *)(param_1 + 0x28);
    dVar14 = (double)FUN_140332d90(dVar16);
    uVar1 = DAT_140e41a98;
    uVar2 = DAT_140e41a40;
    fVar15 = (float)(dVar14 * dVar4) + *(float *)(param_1 + 0x2c);
    if ((*(int *)(param_1 + 0x18) - 0x13fU < 2) || (*(int *)(param_1 + 0x18) - 0x146U < 6)) {
      uVar2 = *(undefined4 *)(param_1 + 4);
      if (0xfff < DAT_140e45d1c) {
        return;
      }
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *(float *)((longlong)puVar7 + 0x14) = fVar17;
      *(undefined4 *)(puVar7 + 3) = 0;
      uVar8 = 0x3fe0000000000000;
      *(undefined4 *)(puVar7 + 4) = 0;
      puVar7[5] = 0;
      *(float *)((longlong)puVar7 + 0x1c) = fVar17;
      *(undefined4 *)(puVar7 + 1) = 0x35;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar1;
      *(undefined4 *)(puVar7 + 2) = 0x2d;
      *(ushort *)((longlong)puVar7 + 0x24) = uVar11;
      *(undefined4 *)(puVar7 + 8) = 0x50;
      *(undefined4 *)(puVar7 + 10) = 0xc0;
      *(undefined4 *)((longlong)puVar7 + 0x54) = uVar2;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 4);
      iVar10 = DAT_140e45d1c;
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        *(float *)((longlong)puVar7 + 0x14) = fVar17;
        bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)((longlong)puVar7 + 0x1c) = fVar17;
        *puVar7 = 1;
        *(undefined4 *)(puVar7 + 1) = 0x35;
        *(undefined4 *)((longlong)puVar7 + 0xc) = uVar2;
        *(undefined4 *)(puVar7 + 2) = 0x2d;
        *(undefined4 *)(puVar7 + 3) = 0;
        *(undefined4 *)(puVar7 + 4) = 0;
        *(ushort *)((longlong)puVar7 + 0x24) = uVar11;
        puVar7[5] = 0;
        puVar7[6] = 0x3fe0000000000000;
        puVar7[7] = 0x3fe0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0x50;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        *(undefined4 *)(puVar7 + 10) = 0xc0;
        *(undefined4 *)((longlong)puVar7 + 0x54) = uVar1;
        puVar7[0xb] = 0;
        if (bVar13) {
          DAT_140e45d78 = puVar7;
        }
        uVar9 = DAT_140e418c8;
        DAT_140e45d1c = iVar10;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
          uVar9 = DAT_140e418c8;
        }
      }
      DAT_140e45d28 = puVar7;
      uVar2 = DAT_140e41964;
      uVar9 = *(int *)(param_1 + 0xc) * 0x22b8 + uVar9;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
      uVar3 = (ulonglong)DAT_140e9fd1c;
      sVar5 = (short)DAT_140e9fd1c;
      if (0xfff < iVar10) {
        return;
      }
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *(float *)((longlong)puVar7 + 0x14) = fVar18;
      *(float *)(puVar7 + 3) = fVar15;
      uVar8 = 0x3ff0000000000000;
      *(float *)((longlong)puVar7 + 0x1c) = fVar18;
      puVar7[5] = 0x3ff0000000000000;
      *(float *)(puVar7 + 4) = fVar15;
      *(undefined4 *)(puVar7 + 1) = 0x17;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar2;
      *(undefined4 *)(puVar7 + 2) = 0x2e;
      *(short *)((longlong)puVar7 + 0x24) = sVar5 + (short)(uVar3 / 0x2ee1) * -0x2ee1 + -0x5770;
      *(undefined4 *)(puVar7 + 8) = 0x3c;
      puVar7[10] = 0xc0;
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
    puVar7[0xb] = 0;
    *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
    *(undefined4 *)(puVar7 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
    puVar7[7] = uVar8;
    puVar7[6] = uVar8;
    *puVar7 = 1;
    if (bVar13) {
      DAT_140e45d78 = puVar7;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar7;
    }
  }
  DAT_140e45d28 = puVar7;
  return;
}


