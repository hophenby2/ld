// Function: FUN_1400cd750 @ 1400cd750
// Decompile completed: true

void FUN_1400cd750(void)

{
  int iVar1;
  undefined4 uVar2;
  unkuint9 Var3;
  double dVar4;
  undefined8 uVar5;
  double dVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short sVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  short sVar17;
  longlong lVar18;
  uint uVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  float fVar25;
  undefined4 uVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  
  uVar7 = DAT_14053ac80;
  dVar6 = DAT_14053a020;
  uVar5 = DAT_140539fc8;
  dVar4 = DAT_140539d28;
  if (DAT_140e46ea0 != 0) {
    uVar26 = (undefined4)DAT_140539fc8;
    lVar18 = DAT_140e46ea0;
    iVar12 = DAT_140e45d1c;
    do {
      uVar19 = *(uint *)(lVar18 + 8);
      if ((uVar19 < 0x1f) && ((0x63737000U >> (uVar19 & 0x1f) & 1) != 0)) {
        fVar27 = *(float *)(lVar18 + 0xc);
        fVar28 = *(float *)(lVar18 + 0x10);
        fVar29 = *(float *)(lVar18 + 0x2c);
        if (uVar19 - 0xc < 0x13) {
LAB_1400cd871:
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch((&LAB_1400ceb28)[(int)(uVar19 - 0xc)]) {
          case 0:
            if (DAT_140e45260 != (int *)0x0) {
              uVar19 = DAT_140e418c8 + 0x6f;
              iVar15 = DAT_140e418c8 * 0x1a0a;
              piVar14 = DAT_140e45260;
              uVar16 = DAT_140e418c8;
              do {
                fVar24 = (float)piVar14[8];
                uVar16 = uVar16 + 1;
                iVar15 = iVar15 + 0x1a0a;
                uVar19 = uVar19 + 1;
                dVar22 = (double)*(ushort *)(piVar14 + 9) * dVar6 * dVar4;
                dVar21 = (double)FUN_1403307c0(dVar22);
                fVar25 = (float)(dVar21 * (double)fVar24) + (float)piVar14[4];
                dVar22 = (double)FUN_140332d90(dVar22);
                iVar1 = piVar14[0xe];
                fVar24 = (float)(dVar22 * (double)fVar24) + (float)piVar14[5];
                dVar22 = (double)FUN_1403316f0((double)(fVar27 - fVar25),uVar26);
                dVar21 = (double)FUN_1403316f0((double)(fVar28 - fVar24),uVar26);
                dVar23 = (double)FUN_1403316f0((double)((float)iVar1 + fVar29),uVar26);
                if (((dVar22 + dVar21 < dVar23) && (iVar1 != 0)) &&
                   ((*piVar14 == 1 && (piVar14[0x10] == 1)))) {
                  uVar11 = (DAT_140e418c8 + iVar15 >> 0x1e ^ DAT_140e418c8 + iVar15) * 0x6c078965 +
                           1;
                  uVar10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                  uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
                  uVar11 = uVar11 * 0x800 ^ uVar11;
                  uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
                  uVar11 = (uVar10 >> 0xb ^ uVar11) >> 8 ^ uVar10 ^ uVar11;
                  sVar17 = (short)uVar11 + (short)((ulonglong)uVar11 / 0x2ee1) * -0x2ee1 + -0x5770;
                  uVar10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 1;
                  DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
                  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                  uVar11 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
                  if (iVar1 < 2) {
                    uVar10 = uVar10 * 0x800 ^ uVar10;
                    DAT_140e9fd18 = uVar11 * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ DAT_140e9fd18 ^ uVar10;
                    FUN_1400ca6d0(3,fVar25,fVar24,
                                  CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                           (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),
                                  uVar5,uVar7);
                    Var3 = (unkuint9)DAT_1407c77a8;
                    iVar12 = DAT_140e45d1c;
                    puVar8 = DAT_140e45d28;
                    if (DAT_140e45d1c < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      iVar12 = DAT_140e45d1c + 1;
                      puVar8[5] = 0x3fe3333333333333;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[7] = 0x3fe999999999999a;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 4) = fVar24;
                      puVar8[6] = (double)(unkint9)Var3;
                      *puVar8 = 1;
                      puVar8[1] = 0x1c;
                      *(undefined4 *)(puVar8 + 2) = 0x4a;
                      *(short *)((longlong)puVar8 + 0x24) = sVar17;
                      *(undefined4 *)(puVar8 + 8) = 0x28;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      puVar8[10] = 0xff;
                      puVar8[0xb] = 0;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                    DAT_140e45d28 = puVar8;
                    uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
                    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                    uVar11 = uVar11 * 0x800 ^ uVar11;
                    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
                    sVar13 = (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x8001) * 0x7fff;
                    puVar8 = DAT_140e45d28;
                    if (iVar12 < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      puVar8[5] = 0x3ff0000000000000;
                      puVar8[6] = 0x3ff0000000000000;
                      uVar9 = 0x3fe0000000000000;
LAB_1400cdcb7:
                      puVar8[0xb] = 0;
                      iVar12 = DAT_140e45d1c + 1;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[10] = 0xc0;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 8) = 0x32;
                      puVar8[7] = uVar9;
                      *(short *)((longlong)puVar8 + 0x24) = sVar13 + sVar17 + 0x4000;
                      *(float *)(puVar8 + 4) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      *(undefined4 *)(puVar8 + 2) = 0x49;
                      puVar8[1] = 0x1a;
                      *puVar8 = 1;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                  }
                  else {
                    uVar10 = uVar10 * 0x800 ^ uVar10;
                    DAT_140e9fd18 = uVar11 * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
                    FUN_1400ca6d0(4,fVar25,fVar24,
                                  CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                           (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),
                                  uVar5,DAT_14053acb0);
                    Var3 = (unkuint9)DAT_1407c77a8;
                    iVar12 = DAT_140e45d1c;
                    puVar8 = DAT_140e45d28;
                    if (DAT_140e45d1c < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      iVar12 = DAT_140e45d1c + 1;
                      puVar8[5] = 0x3fe3333333333333;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[7] = 0x3fe999999999999a;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 4) = fVar24;
                      puVar8[6] = (double)(unkint9)Var3;
                      *puVar8 = 1;
                      puVar8[1] = 0x1c;
                      *(undefined4 *)(puVar8 + 2) = 0x4a;
                      *(short *)((longlong)puVar8 + 0x24) = sVar17;
                      *(undefined4 *)(puVar8 + 8) = 0x28;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      puVar8[10] = 0xff;
                      puVar8[0xb] = 0;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                    DAT_140e45d28 = puVar8;
                    uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
                    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                    uVar11 = uVar11 * 0x800 ^ uVar11;
                    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ uVar11 ^ DAT_140e9fd18;
                    sVar13 = (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x8001) * 0x7fff;
                    puVar8 = DAT_140e45d28;
                    if (iVar12 < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      puVar8[5] = 0x4014000000000000;
                      puVar8[6] = 0x4014000000000000;
                      uVar9 = 0x4004000000000000;
                      goto LAB_1400cdcb7;
                    }
                  }
                  DAT_140e45d28 = puVar8;
                  uVar2 = DAT_140e41a50;
                  puVar8 = DAT_140e45d28;
                  if (iVar12 < 0x1000) {
                    puVar8 = (undefined8 *)_malloc_base(0x60);
                    if (puVar8 == (undefined8 *)0x0) {
                      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                    }
                    iVar12 = DAT_140e45d1c + 1;
                    *(float *)((longlong)puVar8 + 0x14) = fVar25;
                    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                    *(float *)(puVar8 + 3) = fVar24;
                    *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                    *(float *)(puVar8 + 4) = fVar24;
                    *puVar8 = 1;
                    *(undefined4 *)(puVar8 + 1) = 0xc;
                    *(undefined4 *)((longlong)puVar8 + 0xc) = uVar2;
                    *(undefined4 *)(puVar8 + 2) = 0x3d;
                    *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
                    puVar8[5] = 0;
                    puVar8[6] = 0x3fe3333333333333;
                    puVar8[7] = 0x3fe3333333333333;
                    *(undefined4 *)(puVar8 + 8) = 0x10;
                    *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                    *(undefined4 *)(puVar8 + 9) = 0xff;
                    *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                    puVar8[10] = 0xff;
                    puVar8[0xb] = 0;
                    if (bVar20) {
                      DAT_140e45d78 = puVar8;
                    }
                    DAT_140e45d1c = iVar12;
                    if (DAT_140e45d28 != (undefined8 *)0x0) {
                      DAT_140e45d28[0xb] = puVar8;
                    }
                  }
                  DAT_140e45d28 = puVar8;
                  *piVar14 = 0;
                }
                piVar14 = *(int **)(piVar14 + 0x12);
              } while (piVar14 != (int *)0x0);
            }
            break;
          case 1:
            for (piVar14 = DAT_140e45260; piVar14 != (int *)0x0; piVar14 = *(int **)(piVar14 + 0x12)
                ) {
              fVar24 = (float)piVar14[8];
              dVar22 = (double)*(ushort *)(piVar14 + 9) * dVar6 * dVar4;
              dVar21 = (double)FUN_1403307c0(dVar22);
              fVar25 = (float)(dVar21 * (double)fVar24) + (float)piVar14[4];
              dVar22 = (double)FUN_140332d90(dVar22);
              iVar15 = piVar14[0xe];
              fVar24 = (float)(dVar22 * (double)fVar24) + (float)piVar14[5];
              dVar22 = (double)FUN_1403316f0((double)(fVar27 - fVar25),uVar26);
              dVar21 = (double)FUN_1403316f0((double)(fVar28 - fVar24),uVar26);
              dVar23 = (double)FUN_1403316f0((double)((float)iVar15 + fVar29),uVar26);
              uVar2 = DAT_140e41a50;
              if ((((dVar22 + dVar21 < dVar23) && (iVar15 != 0)) && (*piVar14 == 1)) &&
                 (piVar14[0x10] == 1)) {
                puVar8 = DAT_140e45d28;
                if (iVar12 < 0x1000) {
                  puVar8 = (undefined8 *)_malloc_base(0x60);
                  if (puVar8 == (undefined8 *)0x0) {
                    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                  }
                  iVar12 = DAT_140e45d1c + 1;
                  *(float *)((longlong)puVar8 + 0x14) = fVar25;
                  bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                  *(float *)(puVar8 + 3) = fVar24;
                  *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                  *(float *)(puVar8 + 4) = fVar24;
                  *puVar8 = 1;
                  *(undefined4 *)(puVar8 + 1) = 0xc;
                  *(undefined4 *)((longlong)puVar8 + 0xc) = uVar2;
                  *(undefined4 *)(puVar8 + 2) = 0x3d;
                  *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
                  puVar8[5] = 0;
                  puVar8[6] = 0x3fe3333333333333;
                  puVar8[7] = 0x3fe3333333333333;
                  *(undefined4 *)(puVar8 + 8) = 0x10;
                  *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                  *(undefined4 *)(puVar8 + 9) = 0xff;
                  *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                  puVar8[10] = 0xff;
                  puVar8[0xb] = 0;
                  if (bVar20) {
                    DAT_140e45d78 = puVar8;
                  }
                  DAT_140e45d1c = iVar12;
                  if (DAT_140e45d28 != (undefined8 *)0x0) {
                    DAT_140e45d28[0xb] = puVar8;
                  }
                }
                DAT_140e45d28 = puVar8;
                *piVar14 = 0;
              }
            }
            break;
          case 2:
            if (DAT_140e45260 != (int *)0x0) {
              uVar19 = DAT_140e418c8 + 0x6f;
              iVar15 = DAT_140e418c8 * 0x1a0a;
              piVar14 = DAT_140e45260;
              uVar16 = DAT_140e418c8;
              do {
                fVar24 = (float)piVar14[8];
                uVar16 = uVar16 + 1;
                iVar15 = iVar15 + 0x1a0a;
                uVar19 = uVar19 + 1;
                dVar22 = (double)*(ushort *)(piVar14 + 9) * dVar6 * dVar4;
                dVar21 = (double)FUN_1403307c0(dVar22);
                fVar25 = (float)(dVar21 * (double)fVar24) + (float)piVar14[4];
                dVar22 = (double)FUN_140332d90(dVar22);
                iVar1 = piVar14[0xe];
                fVar24 = (float)(dVar22 * (double)fVar24) + (float)piVar14[5];
                dVar22 = (double)FUN_1403316f0((double)(fVar27 - fVar25),uVar26);
                dVar21 = (double)FUN_1403316f0((double)(fVar28 - fVar24),uVar26);
                dVar23 = (double)FUN_1403316f0((double)((float)iVar1 + fVar29),uVar26);
                if (dVar22 + dVar21 < dVar23) {
                  uVar11 = (DAT_140e418c8 + iVar15 >> 0x1e ^ DAT_140e418c8 + iVar15) * 0x6c078965 +
                           1;
                  uVar10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                  uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
                  uVar11 = uVar11 * 0x800 ^ uVar11;
                  uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
                  uVar11 = (uVar10 >> 0xb ^ uVar11) >> 8 ^ uVar10 ^ uVar11;
                  sVar17 = (short)uVar11 + (short)((ulonglong)uVar11 / 0x2ee1) * -0x2ee1 + -0x5770;
                  uVar10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 1;
                  uVar11 = uVar10 * 0x800 ^ uVar10;
                  DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
                  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
                  uVar2 = CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                   (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
                  if (iVar1 < 2) {
                    FUN_1400ca6d0(3,fVar25,fVar24,uVar2,uVar5,uVar7);
                    Var3 = (unkuint9)DAT_1407c77a8;
                    iVar12 = DAT_140e45d1c;
                    puVar8 = DAT_140e45d28;
                    if (DAT_140e45d1c < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      iVar12 = DAT_140e45d1c + 1;
                      puVar8[5] = 0x3fe3333333333333;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[7] = 0x3ff0000000000000;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 4) = fVar24;
                      puVar8[6] = (double)(unkint9)Var3;
                      *puVar8 = 1;
                      puVar8[1] = 0x1c;
                      *(undefined4 *)(puVar8 + 2) = 0x4a;
                      *(short *)((longlong)puVar8 + 0x24) = sVar17;
                      *(undefined4 *)(puVar8 + 8) = 0x28;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      puVar8[10] = 0xff;
                      puVar8[0xb] = 0;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                    DAT_140e45d28 = puVar8;
                    uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
                    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                    uVar11 = uVar11 * 0x800 ^ uVar11;
                    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
                    sVar13 = (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x8001) * 0x7fff;
                    puVar8 = DAT_140e45d28;
                    if (iVar12 < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      puVar8[5] = 0x3ff0000000000000;
                      puVar8[6] = 0x3ff0000000000000;
                      uVar9 = 0x3fe0000000000000;
LAB_1400ce69d:
                      puVar8[0xb] = 0;
                      iVar12 = DAT_140e45d1c + 1;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[10] = 0xc0;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 8) = 0x32;
                      puVar8[7] = uVar9;
                      *(short *)((longlong)puVar8 + 0x24) = sVar13 + sVar17 + 0x4000;
                      *(float *)(puVar8 + 4) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      *(undefined4 *)(puVar8 + 2) = 0x49;
                      puVar8[1] = 0x1a;
                      *puVar8 = 1;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                  }
                  else {
                    FUN_1400ca6d0(4,fVar25,fVar24,uVar2,uVar5,DAT_14053acb0);
                    Var3 = (unkuint9)DAT_1407c77a8;
                    iVar12 = DAT_140e45d1c;
                    puVar8 = DAT_140e45d28;
                    if (DAT_140e45d1c < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      iVar12 = DAT_140e45d1c + 1;
                      puVar8[5] = 0x3fe3333333333333;
                      *(float *)((longlong)puVar8 + 0x14) = fVar25;
                      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                      puVar8[7] = 0x3ff0000000000000;
                      *(float *)(puVar8 + 3) = fVar24;
                      *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                      *(float *)(puVar8 + 4) = fVar24;
                      puVar8[6] = (double)(unkint9)Var3;
                      *puVar8 = 1;
                      puVar8[1] = 0x1c;
                      *(undefined4 *)(puVar8 + 2) = 0x4a;
                      *(short *)((longlong)puVar8 + 0x24) = sVar17;
                      *(undefined4 *)(puVar8 + 8) = 0x28;
                      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                      *(undefined4 *)(puVar8 + 9) = 0xff;
                      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                      puVar8[10] = 0xff;
                      puVar8[0xb] = 0;
                      if (bVar20) {
                        DAT_140e45d78 = puVar8;
                      }
                      DAT_140e45d1c = iVar12;
                      if (DAT_140e45d28 != (undefined8 *)0x0) {
                        DAT_140e45d28[0xb] = puVar8;
                      }
                    }
                    DAT_140e45d28 = puVar8;
                    uVar11 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
                    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
                    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
                    uVar11 = uVar11 * 0x800 ^ uVar11;
                    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
                    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ uVar11 ^ DAT_140e9fd18;
                    sVar13 = (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x8001) * 0x7fff;
                    puVar8 = DAT_140e45d28;
                    if (iVar12 < 0x1000) {
                      puVar8 = (undefined8 *)_malloc_base(0x60);
                      if (puVar8 == (undefined8 *)0x0) {
                        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                      }
                      puVar8[5] = 0x4014000000000000;
                      puVar8[6] = 0x4014000000000000;
                      uVar9 = 0x4004000000000000;
                      goto LAB_1400ce69d;
                    }
                  }
                  DAT_140e45d28 = puVar8;
                  uVar2 = DAT_140e41a50;
                  puVar8 = DAT_140e45d28;
                  if (iVar12 < 0x1000) {
                    puVar8 = (undefined8 *)_malloc_base(0x60);
                    if (puVar8 == (undefined8 *)0x0) {
                      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                    }
                    iVar12 = DAT_140e45d1c + 1;
                    *(float *)((longlong)puVar8 + 0x14) = fVar25;
                    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
                    *(float *)(puVar8 + 3) = fVar24;
                    *(float *)((longlong)puVar8 + 0x1c) = fVar25;
                    *(float *)(puVar8 + 4) = fVar24;
                    *puVar8 = 1;
                    *(undefined4 *)(puVar8 + 1) = 0xc;
                    *(undefined4 *)((longlong)puVar8 + 0xc) = uVar2;
                    *(undefined4 *)(puVar8 + 2) = 0x3d;
                    *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
                    puVar8[5] = 0;
                    puVar8[6] = 0x3fe3333333333333;
                    puVar8[7] = 0x3fe3333333333333;
                    *(undefined4 *)(puVar8 + 8) = 0x10;
                    *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
                    *(undefined4 *)(puVar8 + 9) = 0xff;
                    *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
                    puVar8[10] = 0xff;
                    puVar8[0xb] = 0;
                    if (bVar20) {
                      DAT_140e45d78 = puVar8;
                    }
                    DAT_140e45d1c = iVar12;
                    if (DAT_140e45d28 != (undefined8 *)0x0) {
                      DAT_140e45d28[0xb] = puVar8;
                    }
                  }
                  DAT_140e45d28 = puVar8;
                  *piVar14 = 0;
                }
                piVar14 = *(int **)(piVar14 + 0x12);
              } while (piVar14 != (int *)0x0);
            }
          }
        }
      }
      else if (uVar19 == 0x1a) {
        fVar27 = *(float *)(lVar18 + 0xc);
        fVar28 = *(float *)(lVar18 + 0x10);
        fVar29 = *(float *)(lVar18 + 0x2c);
        goto LAB_1400cd871;
      }
      lVar18 = *(longlong *)(lVar18 + 0x38);
    } while (lVar18 != 0);
  }
  return;
}


