// Function: FUN_1400cbd30 @ 1400cbd30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1400cbd30(void)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  undefined8 uVar13;
  uint uVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined8 uVar21;
  float fVar22;
  float fVar23;
  
  uVar8 = _UNK_14053bab8;
  uVar7 = _DAT_14053bab0;
  fVar6 = DAT_14053acb4;
  uVar13 = 0;
  iVar3 = 4;
  if (4 < DAT_140e4464c + 2U) {
    iVar3 = 3;
  }
  if (DAT_140e45260 != (int *)0x0) {
    piVar11 = DAT_140e45260;
    uVar10 = DAT_140e418c8;
    uVar5 = DAT_140e418c8 + 0x6f;
    do {
      fVar16 = (float)piVar11[8];
      dVar18 = (double)FUN_1403307c0();
      fVar22 = (float)(dVar18 * (double)fVar16) + (float)piVar11[4];
      dVar18 = (double)FUN_140332d90();
      fVar23 = (float)(dVar18 * (double)fVar16) + (float)piVar11[5];
      fVar16 = (float)FUN_140334430(fVar22 - DAT_140e445d8);
      fVar17 = (float)FUN_140334430(fVar23 - DAT_140e445dc);
      if (fVar16 + fVar17 < 0.0) {
        fVar16 = (float)FUN_1403352f8();
      }
      else {
        fVar16 = SQRT(fVar16 + fVar17);
      }
      iVar1 = piVar11[0xe];
      uVar10 = uVar10 + 1;
      uVar14 = uVar5 + 1;
      if (0 < iVar1) {
        if (fVar16 <= (float)(iVar1 + iVar3)) {
          *piVar11 = 0;
          uVar13 = 1;
        }
        if ((((piVar11[0xf] == 0) && (*piVar11 == 1)) && (DAT_140e45270 != 0x15)) &&
           ((DAT_140e445d4 == 1 && (fVar16 <= (float)iVar1 + fVar6)))) {
          dVar18 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),
                                         (double)(DAT_140e445d8 - fVar22));
          dVar18 = dVar18 * DAT_14053aba0;
          fVar16 = fVar16 * DAT_140539d20;
          dVar19 = (double)FUN_1403307c0();
          dVar20 = (double)FUN_140332d90();
          uVar12 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar12 = uVar12 * 0x800 ^ uVar12;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
          uVar2 = (ulonglong)DAT_140e9fd1c;
          sVar4 = (short)DAT_140e9fd1c;
          puVar9 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar9 = (undefined8 *)_malloc_base(0x60);
            if (puVar9 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            *(float *)((longlong)puVar9 + 0x14) = fVar22;
            *(float *)(puVar9 + 3) = fVar23;
            *(short *)((longlong)puVar9 + 0x24) =
                 sVar4 + (short)(uVar2 / 0x8001) * 0x7fff + (short)(int)dVar18 + 0x4000;
            bVar15 = DAT_140e45d78 == (undefined8 *)0x0;
            puVar9[5] = 0x3ff0000000000000;
            puVar9[6] = 0x3ff0000000000000;
            *(float *)((longlong)puVar9 + 0x1c) = fVar22;
            *(float *)(puVar9 + 4) = fVar23;
            *puVar9 = 1;
            puVar9[1] = 0x19;
            *(undefined4 *)(puVar9 + 2) = 0x42;
            puVar9[7] = 0x3fe0000000000000;
            *(undefined4 *)(puVar9 + 8) = 0x32;
            *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
            *(undefined4 *)(puVar9 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
            puVar9[10] = 0xc0;
            puVar9[0xb] = 0;
            if (bVar15) {
              DAT_140e45d78 = puVar9;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar9;
            }
          }
          DAT_140e45d28 = puVar9;
          uVar12 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar12 = uVar12 * 0x800 ^ uVar12;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar12 = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
          DAT_140e9fd1c = uVar12;
          uVar21 = FUN_140134db0(uVar5 + 0x26a1,DAT_14053a0b0,DAT_14053a178);
          FUN_140070d00(0xe,DAT_140e44ea8,0x44,(float)(dVar19 * (double)fVar16) + fVar22,
                        (float)(dVar20 * (double)fVar16) + fVar23,
                        (short)uVar12 - (short)(uVar12 / 0x10001),uVar21,uVar7,uVar8,0xc,0xff,0xff,
                        0xff,0xff,0);
          FUN_140184700(DAT_140e44190 << 4,DAT_140e472ac);
          FUN_14018a340(DAT_140e472ac,1,1);
          DAT_140e46bbc = DAT_140e46bbc + 1;
          if (DAT_140e41b00 == 0) {
            DAT_140e44184 = DAT_140e44184 + 1;
          }
          DAT_140e45d20 = 0x3c;
          piVar11[0xf] = 1;
        }
      }
      piVar11 = *(int **)(piVar11 + 0x12);
      uVar5 = uVar14;
    } while (piVar11 != (int *)0x0);
  }
  return uVar13;
}


