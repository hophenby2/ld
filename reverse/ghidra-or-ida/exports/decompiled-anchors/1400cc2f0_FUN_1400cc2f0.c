// Function: FUN_1400cc2f0 @ 1400cc2f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400cc2f0(longlong param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  float fVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined8 in_stack_fffffffffffffec8;
  undefined4 in_stack_fffffffffffffed0;
  undefined4 uVar28;
  undefined2 uVar29;
  double in_stack_fffffffffffffed8;
  
  uVar6 = DAT_140539fc8;
  fVar1 = *(float *)(param_1 + 0x2c);
  iVar3 = *(int *)(param_1 + 0x50);
  fVar2 = *(float *)(param_1 + 0x28);
  puVar4 = DAT_140e46ea0;
  uVar15 = DAT_140e418c8;
  do {
    if (puVar4 == (undefined4 *)0x0) {
      return;
    }
    fVar25 = (float)puVar4[3];
    fVar17 = (float)puVar4[4];
    fVar21 = (float)puVar4[0xb];
    dVar18 = (double)FUN_1403316f0((double)(fVar2 - fVar25));
    dVar19 = (double)FUN_1403316f0((double)(fVar1 - fVar17));
    dVar20 = (double)FUN_1403316f0((double)((float)iVar3 + fVar21));
    if ((dVar18 + dVar19 < dVar20) && (iVar9 = *(int *)(param_1 + 0x50), iVar9 != 0)) {
      dVar19 = (double)FUN_1403300b4((double)(fVar1 - fVar17));
      dVar18 = (double)fVar21;
      dVar19 = (double)((int)(dVar19 * DAT_14053aba0) & 0xffff) * DAT_14053a020 * DAT_140539d28;
      dVar20 = (double)FUN_1403307c0(dVar19);
      fVar26 = (float)(dVar20 * dVar18) + fVar25;
      dVar19 = (double)FUN_140332d90(dVar19);
      fVar27 = (float)(dVar19 * dVar18) + fVar17;
      dVar19 = (double)FUN_1403300b4((double)(fVar17 - fVar1),(double)(fVar25 - fVar2));
      dVar18 = (double)iVar3;
      dVar19 = (double)((int)(dVar19 * DAT_14053aba0) & 0xffff) * DAT_14053a020 * DAT_140539d28;
      dVar20 = (double)FUN_1403307c0(dVar19);
      fVar25 = (float)(dVar20 * dVar18) + fVar2;
      dVar20 = (double)FUN_140332d90(dVar19);
      dVar19 = DAT_140539f40;
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
      uVar29 = (undefined2)((uint)in_stack_fffffffffffffed0 >> 0x10);
      iVar7 = puVar4[2];
      uVar15 = uVar15 + 1;
      fVar21 = (float)(dVar20 * dVar18) + fVar1;
      iVar14 = 0;
      switch(iVar7) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0x10:
        DAT_140e44590 = DAT_140e44590 + 0x10;
        uVar22 = SUB84(DAT_140539f40,0);
        uVar5 = (ulonglong)DAT_140539f40 >> 0x20;
        if ((int)puVar4[1] < 0x11) {
          DAT_140e45d88 = DAT_140e45d88 + (0x15 - puVar4[1]) * 2;
        }
        else {
          DAT_140e45d88 = DAT_140e45d88 + 10;
        }
        if (DAT_140e45d18 < 0) {
          fVar17 = (float)FUN_140334430(DAT_140e445d8 - *(float *)(param_1 + 0x28));
          fVar25 = (float)FUN_140334430(DAT_140e445dc - *(float *)(param_1 + 0x2c));
          fVar17 = fVar17 + fVar25;
          if (fVar17 < 0.0) {
            fVar17 = (float)FUN_1403352f8(fVar17);
          }
          else {
            fVar17 = SQRT(fVar17);
          }
          iVar7 = (int)(fVar17 - (float)iVar9) / 0x3c + 2;
          iVar9 = 2;
          if (1 < iVar7) {
            iVar9 = iVar7;
          }
          iVar9 = FUN_140134d00(DAT_140e418c8 + uVar15,0,iVar9);
          if (iVar9 == 0) {
            uVar8 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar8 = uVar8 * 0x800 ^ uVar8;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
            uVar11 = uVar6;
            uVar28 = DAT_14053ac80;
            FUN_1400ca6d0(0,(ulonglong)DAT_140e9fd1c / 0x10001,fVar27,
                          CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                   (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),uVar6,
                          DAT_14053ac80);
            uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);
            uVar29 = (undefined2)((uint)uVar28 >> 0x10);
          }
        }
        dVar20 = DAT_14053a0b0;
        uVar8 = (uVar15 * 0x42 >> 0x1e ^ uVar15 * 0x42) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar8 = uVar8 * 0x800 ^ uVar8;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar8 = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar8;
        in_stack_fffffffffffffed8 = (double)FUN_140134db0(uVar15 * 0x2c,DAT_140e9fd18,DAT_14053a178)
        ;
        in_stack_fffffffffffffed0 = CONCAT22(uVar29,(short)uVar8 - (short)(uVar8 / 0x10001));
        in_stack_fffffffffffffec8 = CONCAT44(uVar23,fVar27);
        FUN_140070d00(0xe,DAT_140e44ea8,0x48,fVar26,in_stack_fffffffffffffec8,
                      in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,_DAT_14053bab0,
                      _UNK_14053bab8,0xc,0xff,0xff,0xff,0xff,0);
        dVar18 = DAT_140539f90;
        uVar8 = puVar4[2];
        iVar9 = 0x1c;
        if (uVar8 < 2) {
          if (DAT_140e445c0 == 0) {
            iVar9 = 0x1c;
          }
          else if (DAT_140e445c0 == 1) {
            iVar9 = 0x2c;
          }
          else if (DAT_140e445c0 == 2) {
            iVar9 = 0x3f;
          }
          else {
            iVar9 = 1;
            if (DAT_140e445c0 == 3) {
              iVar9 = iVar14;
            }
          }
        }
        uVar28 = SUB84(DAT_140539f90,0);
        uVar24 = (undefined4)((ulonglong)DAT_140539f90 >> 0x20);
        uVar23 = (int)uVar5;
        if (uVar8 - 2 < 3) {
          uVar22 = uVar28;
          uVar23 = uVar24;
          if (DAT_140e445c0 == 0) {
            iVar9 = 0x1d;
          }
          else if (DAT_140e445c0 == 1) {
            iVar9 = 0x3a;
          }
          else if (DAT_140e445c0 == 2) {
            iVar9 = 0x40;
          }
          else {
            iVar9 = 1;
            if (DAT_140e445c0 == 3) {
              iVar9 = iVar14;
            }
          }
        }
        if (uVar8 - 5 < 3) {
          if (DAT_140e445c0 == 0) {
            iVar9 = 0x2b;
          }
          else if (DAT_140e445c0 == 1) {
            iVar9 = 0x3b;
          }
          else if (DAT_140e445c0 == 2) {
            iVar9 = 0x58;
          }
          else {
            iVar9 = 1;
            if (DAT_140e445c0 == 3) {
              iVar9 = iVar14;
            }
          }
        }
        if (uVar8 - 8 < 3) {
          if (DAT_140e445c0 == 0) {
LAB_1400cc912:
            iVar9 = 0x59;
          }
          else if (DAT_140e445c0 == 1) {
            iVar9 = 0x67;
          }
          else {
            if (DAT_140e445c0 == 2) goto LAB_1400cc912;
            iVar9 = 1;
            if (DAT_140e445c0 == 3) {
              iVar9 = iVar14;
            }
          }
        }
        if ((uVar8 < 9) && ((0x125U >> (uVar8 & 0x1f) & 1) != 0)) {
          in_stack_fffffffffffffed8 = *(double *)(puVar4 + 8) / dVar20;
          in_stack_fffffffffffffed0 =
               CONCAT22((short)((uint)in_stack_fffffffffffffed0 >> 0x10),*(undefined2 *)(puVar4 + 7)
                       );
          in_stack_fffffffffffffec8 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),puVar4[4]);
          FUN_140070d00(0xd,(&DAT_140e44e70)[iVar9],0x2d,puVar4[3],in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,CONCAT44(uVar23,uVar22),
                        dVar19,8,0xff,0xff,0xff,0x60,0);
        }
        if (((uint)puVar4[2] < 10) && ((0x248U >> (puVar4[2] & 0x1f) & 1) != 0)) {
          in_stack_fffffffffffffed8 = *(double *)(puVar4 + 8) / dVar20;
          in_stack_fffffffffffffed0 =
               CONCAT22((short)((uint)in_stack_fffffffffffffed0 >> 0x10),*(undefined2 *)(puVar4 + 7)
                       );
          in_stack_fffffffffffffec8 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),puVar4[4]);
          FUN_140070d00(0xd,(&DAT_140e44e70)[iVar9],0x2d,puVar4[3],in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,
                        (double)CONCAT44(uVar23,uVar22) * dVar18,dVar18,8,0xff,0xff,0xff,0x60,0);
        }
        if (((uint)puVar4[2] < 0xb) && ((0x492U >> (puVar4[2] & 0x1f) & 1) != 0)) {
          in_stack_fffffffffffffed8 = *(double *)(puVar4 + 8) / dVar20;
          in_stack_fffffffffffffed0 =
               CONCAT22((short)((uint)in_stack_fffffffffffffed0 >> 0x10),*(undefined2 *)(puVar4 + 7)
                       );
          in_stack_fffffffffffffec8 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),puVar4[4]);
          FUN_140070d00(0xd,(&DAT_140e44e70)[iVar9],0x2d,puVar4[3],in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,
                        (double)CONCAT44(uVar23,uVar22) + (double)CONCAT44(uVar23,uVar22),uVar6,8,
                        0xff,0xff,0xff,0x60,0);
        }
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
        uVar29 = (undefined2)((uint)in_stack_fffffffffffffed0 >> 0x10);
        if (puVar4[2] == 0x10) {
          uVar8 = (uVar15 * 0x16 >> 0x1e ^ uVar15 * 0x16) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar8 * 0x800 ^ uVar8;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
          puVar10 = DAT_140e45d28;
          if (DAT_140e9fd1c == (DAT_140e9fd1c / 6) * 6) {
            uVar8 = (uVar15 * 0x8ae >> 0x1e ^ uVar15 * 0x8ae) * 0x6c078965 + 1;
            uVar12 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
            uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
            uVar8 = uVar8 * 0x800 ^ uVar8;
            uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
            uVar12 = (uVar12 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ uVar12;
            uVar13 = (uVar15 * 0xde >> 0x1e ^ uVar15 * 0xde) * 0x6c078965 + 1;
            uVar8 = uVar13 * 0x800 ^ uVar13;
            DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ DAT_140e9fd18;
            uVar22 = *(undefined4 *)(&DAT_140e41a60 + (ulonglong)(DAT_140e9fd1c & 3) * 4);
            if (DAT_140e45d1c < 0x1000) {
              puVar10 = (undefined8 *)_malloc_base(0x60);
              if (puVar10 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              *(undefined4 *)((longlong)puVar10 + 0xc) = uVar22;
              bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
              puVar10[5] = 0x4000000000000000;
              puVar10[6] = 0x3ff0000000000000;
              puVar10[7] = 0x3ff0000000000000;
              *(float *)((longlong)puVar10 + 0x14) = fVar26;
              *(float *)(puVar10 + 3) = fVar27;
              *(float *)((longlong)puVar10 + 0x1c) = fVar26;
              *(float *)(puVar10 + 4) = fVar27;
              *puVar10 = 1;
              *(undefined4 *)(puVar10 + 1) = 0x17;
              *(undefined4 *)(puVar10 + 2) = 0x4b;
              *(short *)((longlong)puVar10 + 0x24) = (short)uVar12 - (short)(uVar12 / 0x10001);
              *(undefined4 *)(puVar10 + 8) = 0x18;
              *(undefined4 *)((longlong)puVar10 + 0x44) = 0xff;
              *(undefined4 *)(puVar10 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar10 + 0x4c) = 0xff;
              puVar10[10] = 0x80;
              puVar10[0xb] = 0;
              if (bVar16) {
                DAT_140e45d78 = puVar10;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar10;
              }
            }
          }
          DAT_140e45d28 = puVar10;
          in_stack_fffffffffffffed8 = *(double *)(puVar4 + 8) / dVar20;
          in_stack_fffffffffffffed0 = CONCAT22(uVar29,*(undefined2 *)(puVar4 + 7));
          in_stack_fffffffffffffec8 = CONCAT44(uVar23,puVar4[4]);
          FUN_140070d00(0xd,DAT_140e41a5c,0x2d,puVar4[3],in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,DAT_14053a018,uVar6,8,
                        0xff,0xff,0xff,0x60,0);
        }
        *puVar4 = 0;
        break;
      case 0xc:
        in_stack_fffffffffffffed8 =
             (double)((ulonglong)in_stack_fffffffffffffed8 & 0xffffffff00000000);
        in_stack_fffffffffffffed0 = 0;
        in_stack_fffffffffffffec8 =
             CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),
                      *(undefined2 *)(puVar4 + 7));
        FUN_140109660(0xd,(longlong)iVar7,fVar17,0,in_stack_fffffffffffffec8,10,
                      in_stack_fffffffffffffed8);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47254);
        FUN_14018a340(DAT_140e47254,1,1);
        *puVar4 = 0;
        break;
      case 0xd:
      case 0xe:
      case 0x14:
      case 0x15:
        if (((iVar7 - 0xdU & 0xfffffff6) == 0) && (iVar7 != 0x16)) {
          DAT_140e45d88 = DAT_140e45d88 + 5;
        }
        if (iVar7 == 0x14) {
          DAT_140e45d88 = DAT_140e45d88 + 3;
        }
        iVar7 = *(int *)(param_1 + 0xc);
        if (*(int *)(param_1 + 0xc) ==
            (iVar7 / 3 + (iVar7 >> 0x1f) +
            (int)(((longlong)iVar7 / 3 + ((longlong)iVar7 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 3) {
          FUN_140134d00(uVar15,0,iVar9);
          uVar8 = (uVar15 * 0x42 >> 0x1e ^ uVar15 * 0x42) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar8 * 0x800 ^ uVar8;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar8 = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ DAT_140e9fd18;
          DAT_140e9fd1c = uVar8;
          in_stack_fffffffffffffed8 =
               (double)FUN_140134db0(uVar15 * 0x2c,DAT_14053a0b0,DAT_14053a178);
          in_stack_fffffffffffffed0 = CONCAT22(uVar29,(short)uVar8 - (short)(uVar8 / 0x10001));
          in_stack_fffffffffffffec8 = CONCAT44(uVar23,fVar21);
          goto LAB_1400cd088;
        }
        break;
      case 0x1b:
        DAT_140e44590 = DAT_140e44590 + 10;
        break;
      case 0x1c:
        DAT_140e44590 = DAT_140e44590 + 10;
        uVar8 = (uVar15 * 0x42 >> 0x1e ^ uVar15 * 0x42) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar8 = uVar8 * 0x800 ^ uVar8;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar8 = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
        DAT_140e9fd1c = uVar8;
        in_stack_fffffffffffffed8 = (double)FUN_140134db0(uVar15 * 0x2c,DAT_14053a0b0,DAT_14053a178)
        ;
        in_stack_fffffffffffffed0 = CONCAT22(uVar29,(short)uVar8 - (short)(uVar8 / 0x10001));
        in_stack_fffffffffffffec8 = CONCAT44(uVar23,fVar27);
        fVar25 = fVar26;
LAB_1400cd088:
        FUN_140070d00(0xe,DAT_140e44ea8,0x48,fVar25,in_stack_fffffffffffffec8,
                      in_stack_fffffffffffffed0,in_stack_fffffffffffffed8,_DAT_14053bab0,
                      _UNK_14053bab8,0xc,0xff,0xff,0xff,0xff,0);
      }
      iVar9 = puVar4[10];
      if (0 < iVar9) {
        fVar17 = (float)FUN_140334430(DAT_140e445d8 - *(float *)(param_1 + 0x28));
        fVar25 = (float)FUN_140334430(DAT_140e445dc - *(float *)(param_1 + 0x2c));
        fVar17 = fVar17 + fVar25;
        if (fVar17 < 0.0) {
          fVar17 = (float)FUN_1403352f8(fVar17);
        }
        else {
          fVar17 = SQRT(fVar17);
        }
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - iVar9;
        iVar7 = ((int)fVar17 - *(int *)(param_1 + 0x50)) + -0x3c;
        iVar9 = 0;
        if (-1 < iVar7) {
          iVar9 = iVar7;
        }
        FUN_140184700(((0x8c - iVar9 / 10) / 10) * DAT_140e44190,DAT_140e47244);
        FUN_14018a340(DAT_140e47244,1,1);
      }
      uVar8 = *(uint *)(param_1 + 0x18);
      if ((((uVar8 - 0x138 < 8) ||
           ((uVar8 < 0x2f && ((0x400100010000U >> ((longlong)(int)uVar8 & 0x3fU) & 1) != 0)))) ||
          ((uVar8 = *(int *)(param_1 + 0x18) - 0x2f, uVar8 < 0x28 &&
           ((0xb1001b0003U >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)))) ||
         (((*(int *)(param_1 + 0x18) - 0x143U < 3 ||
           ((uVar8 = *(int *)(param_1 + 0x18) - 0x66, uVar8 < 0x1e &&
            ((0x2008001fU >> (uVar8 & 0x1f) & 1) != 0)))) ||
          (((uVar8 = *(int *)(param_1 + 0x18) - 0x84, uVar8 < 0x29 &&
            ((0x1670000000fU >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)) ||
           ((((((iVar9 = *(int *)(param_1 + 0x18), iVar9 - 0xb8U < 4 || (iVar9 - 0x146U < 5)) ||
               (iVar9 == 200)) ||
              (((iVar9 - 0x111U < 0x3c &&
                ((0xc01800000000003U >> ((ulonglong)(iVar9 - 0x111U) & 0x3f) & 1) != 0)) ||
               ((iVar9 - 0xc3U < 0x2f &&
                ((0x4c0000000001U >> ((ulonglong)(iVar9 - 0xc3U) & 0x3f) & 1) != 0)))))) ||
             ((uVar8 = *(int *)(param_1 + 0x18) - 0x113, uVar8 < 0xe &&
              ((0x3cf9U >> (uVar8 & 0x1f) & 1) != 0)))) ||
            ((uVar8 = *(int *)(param_1 + 0x18) - 0x121, uVar8 < 0x32 &&
             ((0x2000000001073U >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)))))))))) {
        switch(puVar4[2]) {
        case 0xd:
          uVar11 = 0xf0;
          break;
        case 0xe:
        case 0x11:
          uVar11 = 0x3c;
          break;
        default:
          uVar11 = 0xc;
          break;
        case 0x10:
          uVar11 = 9;
          break;
        case 0x14:
          uVar11 = 0x168;
          break;
        case 0x15:
          uVar11 = 0x5a;
          break;
        case 0x1b:
          uVar11 = 0x78;
        }
        iVar9 = FUN_140134d00(DAT_140e418c8 + uVar15,0,uVar11);
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
        uVar29 = (undefined2)((uint)in_stack_fffffffffffffed0 >> 0x10);
        if ((iVar9 == 0) && (0 < (int)puVar4[10])) {
          iVar9 = *(int *)(param_1 + 0x50);
          uVar8 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar8 * 0x800 ^ uVar8;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
          dVar18 = (double)(DAT_140e9fd1c + (DAT_140e9fd1c / 0x8001) * 0x7fff + -0x8000 & 0xffff) *
                   DAT_14053a020 * DAT_140539d28;
          iVar7 = FUN_140134d00(uVar15,0,iVar9);
          FUN_1403307c0(dVar18);
          fVar25 = *(float *)(param_1 + 0x2c);
          dVar18 = (double)FUN_140332d90(dVar18);
          fVar21 = fVar25 - DAT_14053ad1c;
          fVar17 = (float)FUN_140334430(DAT_140e445dc - fVar25);
          fVar25 = (float)FUN_140334430(DAT_140e445d8 - *(float *)(param_1 + 0x28));
          fVar17 = fVar17 + fVar25;
          if (fVar17 < 0.0) {
            fVar17 = (float)FUN_1403352f8(fVar17);
          }
          else {
            fVar17 = SQRT(fVar17);
          }
          iVar14 = 1;
          iVar9 = (int)fVar17 - iVar9;
          if (iVar9 < 0x97) {
            iVar14 = 10;
          }
          else if (iVar9 < 0x1c2) {
            iVar14 = (0x1c2 - iVar9) / 0x1e;
          }
          if (DAT_140e45d18 < 0) {
            iVar14 = 10;
          }
          else if (iVar14 < 1) {
            iVar14 = 1;
          }
          uVar8 = uVar15 * 0x1bc + DAT_140e418c8;
          uVar12 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar12 * 0x800 ^ uVar12;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
          in_stack_fffffffffffffed0 =
               CONCAT22(uVar29,(short)((ulonglong)DAT_140e9fd1c / 0x8001) * 0x7fff +
                               (short)DAT_140e9fd1c + -0x8000);
          in_stack_fffffffffffffec8 = CONCAT44(uVar23,(float)(dVar18 * (double)iVar7) + fVar21);
          in_stack_fffffffffffffed8 = DAT_140539f40;
          FUN_140070d00(0x19,0,0x42,uVar12,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                        DAT_140539f40,(double)iVar14,(double)iVar14 * DAT_140539e60 + DAT_140539f00,
                        0x32,0xff,0xff,0xff,0xc0,0);
        }
      }
      uVar8 = *(int *)(param_1 + 0x18) - 0x127;
      if ((((uVar8 < 0x2a) && ((0x28000008001U >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)) ||
          (*(int *)(param_1 + 0x18) == 0xc3)) && (puVar4[2] != 0x1e)) {
        FUN_140184700(DAT_140e44190 * 9,DAT_140e47248);
        FUN_14018a340(DAT_140e47248,1,1);
      }
    }
    puVar4 = *(undefined4 **)(puVar4 + 0xe);
  } while( true );
}


