// Function: FUN_1400ca7b0 @ 1400ca7b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ca7b0(void)

{
  ushort *puVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  ushort uVar6;
  short sVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  unkuint9 Var13;
  undefined8 uVar14;
  float fVar15;
  float fVar16;
  int iVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  short sVar20;
  int iVar21;
  ushort uVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined2 uVar25;
  ushort uVar26;
  uint uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  bool bVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 local_res18;
  undefined4 uStackX_1c;
  
  fVar16 = DAT_140e445dc;
  fVar15 = DAT_140e445d8;
  uVar14 = DAT_140539fc8;
  if (DAT_140e46e90 != (undefined4 *)0x0) {
    uVar29 = 0;
    puVar23 = DAT_140e46e90;
    dVar33 = DAT_14053a020;
    dVar34 = DAT_140539d28;
    do {
      fVar39 = DAT_140e445dc;
      fVar37 = DAT_140e445d8;
      fVar2 = (float)puVar23[3];
      fVar38 = (float)puVar23[4];
      iVar17 = puVar23[2];
      switch(iVar17) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        iVar24 = puVar23[1];
        dVar35 = *(double *)(puVar23 + 6);
        fVar5 = (float)puVar23[8];
        dVar33 = (double)FUN_140332d90(((double)iVar24 - 0.0) * _DAT_14053a8e8 * dVar33 * dVar34);
        uVar42 = 0xa0;
        if (DAT_140e468fc == 1) {
          uVar42 = 0x80;
        }
        dVar33 = dVar33 * DAT_140539ec8 + DAT_140539f40;
        uVar30 = uVar29;
        if (DAT_140e46904 == 1) {
          uVar30 = 0xd;
          uVar42 = 200;
        }
        dVar34 = dVar35;
        if (puVar23[9] == 0) {
          if (iVar24 < 0x21) {
            dVar34 = (double)FUN_140332d90();
            dVar34 = dVar34 * (double)CONCAT44((uint)((ulonglong)dVar35 >> 0x20) ^ _UNK_14053bef4,
                                               SUB84(dVar35,0) ^ ram0x00014053bef0) + dVar35;
            if (iVar24 != 0x20) goto LAB_1400caa84;
            uVar27 = DAT_140e418c8 + (int)(fVar2 + fVar38);
            *(undefined8 *)(puVar23 + 6) = 0;
            uVar27 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar27 = uVar27 * 0x800 ^ uVar27;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar27) >> 8 ^ uVar27 ^ DAT_140e9fd18;
            *(short *)(puVar23 + 5) =
                 (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x801) * -0x801 + 0x3c00;
            if (DAT_140e445fc < 0xb5) {
              if (iVar17 - 3U < 3) {
                puVar23[9] = 1;
                goto LAB_1400caaa6;
              }
              puVar23[1] = 0x21;
              iVar24 = 0x21;
              dVar35 = 0.0;
              goto LAB_1400caa88;
            }
          }
          else {
LAB_1400caa84:
            if (0x20 < iVar24) {
LAB_1400caa88:
              if (dVar35 < DAT_14053a0b0) {
                *(double *)(puVar23 + 6) = dVar35 + _DAT_140539e28;
              }
            }
          }
LAB_1400caaa6:
          dVar35 = (double)FUN_1403316f0((double)(fVar38 - fVar16),uVar14);
          dVar36 = (double)FUN_1403316f0((double)(fVar2 - fVar15),uVar14);
          dVar32 = (double)FUN_1403316f0((double)(DAT_14053ad80 + fVar5),uVar14);
          if (((dVar35 + dVar36 < dVar32) && (0x1f < iVar24)) && (DAT_140e445fc < 0xb5)) {
            puVar23[9] = 1;
          }
        }
        else {
          dVar35 = (double)FUN_1403300b4((double)(fVar39 - fVar38),(double)(fVar37 - fVar2));
          dVar35 = dVar35 * DAT_14053aba0;
          puVar1 = (ushort *)(puVar23 + 5);
          uVar6 = *puVar1;
          *(undefined8 *)(puVar23 + 6) = 0x4028000000000000;
          uVar26 = (ushort)(int)dVar35;
          iVar21 = ((int)dVar35 & 0xffffU) - (uint)uVar6;
          iVar24 = iVar21 + 0x10000;
          if (-0x8001 < iVar21) {
            iVar24 = iVar21;
          }
          iVar21 = iVar24 + -0x10000;
          if (iVar24 < 0x8001) {
            iVar21 = iVar24;
          }
          if (iVar21 < 1) {
            uVar22 = uVar6;
            if ((iVar21 < 0) && (uVar22 = uVar6 - 0x1000, -0x1000 < iVar21)) {
              uVar22 = uVar26;
            }
          }
          else {
            uVar22 = uVar26;
            if (0xfff < iVar21) {
              uVar22 = uVar6 + 0x1000;
            }
          }
          *puVar1 = uVar22;
          if (DAT_140e445fc == 0x103) {
            uVar27 = DAT_140e418c8 + (int)(fVar2 + fVar38);
            puVar23[1] = 0x28;
            *(undefined8 *)(puVar23 + 6) = 0;
            puVar23[9] = 0;
            uVar27 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar27 = uVar27 * 0x800 ^ uVar27;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar27) >> 8 ^ uVar27 ^ DAT_140e9fd18;
            *puVar1 = (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x801) * -0x801 +
                      0x3c00;
          }
        }
        dVar35 = (double)FUN_1403307c0();
        fVar39 = (float)(dVar35 * dVar34) + fVar2;
        puVar23[3] = fVar39;
        dVar35 = (double)FUN_140332d90();
        fVar37 = (float)(dVar35 * dVar34) + fVar38;
        puVar23[4] = fVar37;
        dVar34 = (double)FUN_1403316f0((double)(fVar2 - fVar15),uVar14);
        dVar35 = (double)FUN_1403316f0((double)(fVar38 - fVar16),uVar14);
        dVar36 = (double)FUN_1403316f0((double)(DAT_14053aca0 + fVar5),uVar14);
        if (((dVar34 + dVar35 < dVar36) && (0x20 < (int)puVar23[1])) && (DAT_140e445fc < 0xb5)) {
          dVar34 = (double)FUN_1403300b4((double)(fVar37 - DAT_140e445dc),
                                         (double)(fVar39 - DAT_140e445d8));
          uVar25 = (undefined2)(int)(dVar34 * DAT_14053aba0);
          puVar19 = DAT_140e45d28;
          if (iVar17 == 0) {
            Var13 = (unkuint9)DAT_1407c77a8;
            if (DAT_140e45d1c < 0x1000) {
              puVar19 = (undefined8 *)_malloc_base(0x60);
              if (puVar19 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar31 = DAT_140e45d78 == (undefined8 *)0x0;
              puVar19[5] = 0x4000000000000000;
              puVar19[7] = 0x3fe999999999999a;
              *(float *)((longlong)puVar19 + 0x14) = fVar39;
              *(float *)(puVar19 + 3) = fVar37;
              *(float *)((longlong)puVar19 + 0x1c) = fVar39;
              *(float *)(puVar19 + 4) = fVar37;
              puVar19[6] = (double)(unkint9)Var13;
              *puVar19 = 1;
              puVar19[1] = 0x1b;
              *(undefined4 *)(puVar19 + 2) = 0x42;
              *(undefined2 *)((longlong)puVar19 + 0x24) = uVar25;
              *(undefined4 *)(puVar19 + 8) = 0x28;
              *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
              *(undefined4 *)(puVar19 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
              puVar19[10] = 0x80;
              puVar19[0xb] = 0;
              if (bVar31) {
                DAT_140e45d78 = puVar19;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar19;
              }
            }
LAB_1400caef2:
            DAT_140e45d28 = puVar19;
            DAT_140e44590 = DAT_140e44590 + DAT_1407c77a8;
            if ((int)DAT_140e45d18 < 0) goto LAB_1400cada4;
            uVar43 = SUB84(DAT_140539e60,0);
            uVar44 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
            uVar40 = SUB84(DAT_140539f40,0);
            uVar41 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
            uVar45 = SUB84(DAT_140539f10,0);
            uVar46 = (undefined4)((ulonglong)DAT_140539f10 >> 0x20);
            uVar47 = SUB84(DAT_14053a1e8,0);
            uVar48 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
            dVar35 = DAT_140539f40 - (double)(DAT_1407c7798 / 2) * DAT_140539e60;
            dVar34 = DAT_140539f10;
            if (DAT_140539f10 <= dVar35) {
              dVar34 = dVar35;
            }
            DAT_140e45d18 = DAT_140e45d18 + (int)(dVar34 * DAT_14053a1e8);
            uVar28 = (ulonglong)DAT_140e45d18;
            if ((int)DAT_140e45d18 < 0) {
              DAT_140e45d18 = 0;
              uVar28 = uVar29;
            }
          }
          else {
            if (iVar17 == 3) goto LAB_1400caef2;
LAB_1400cada4:
            uVar47 = SUB84(DAT_14053a1e8,0);
            uVar48 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
            uVar45 = SUB84(DAT_140539f10,0);
            uVar46 = (undefined4)((ulonglong)DAT_140539f10 >> 0x20);
            uVar43 = SUB84(DAT_140539e60,0);
            uVar44 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
            uVar40 = SUB84(DAT_140539f40,0);
            uVar41 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
            uVar28 = (ulonglong)DAT_140e45d18;
          }
          if (puVar23[2] == 1) {
            dVar34 = (double)DAT_1407c77a8 * DAT_14053a0b0;
            uVar3 = puVar23[4];
            uVar4 = puVar23[3];
            if (DAT_140e45d1c < 0x1000) {
              puVar19 = (undefined8 *)_malloc_base(0x60);
              if (puVar19 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar31 = DAT_140e45d78 == (undefined8 *)0x0;
              puVar19[5] = 0x4002666666666666;
              puVar19[7] = 0x3ff0000000000000;
              *(undefined4 *)((longlong)puVar19 + 0x14) = uVar4;
              *(undefined4 *)(puVar19 + 3) = uVar3;
              *(undefined4 *)((longlong)puVar19 + 0x1c) = uVar4;
              *(undefined4 *)(puVar19 + 4) = uVar3;
              puVar19[6] = dVar34;
              *puVar19 = 1;
              puVar19[1] = 0x1b;
              *(undefined4 *)(puVar19 + 2) = 0x42;
              *(undefined2 *)((longlong)puVar19 + 0x24) = uVar25;
              *(undefined4 *)(puVar19 + 8) = 0x28;
              *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
              *(undefined4 *)(puVar19 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
              puVar19[10] = 0x80;
              puVar19[0xb] = 0;
              if (bVar31) {
                DAT_140e45d78 = puVar19;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar19;
              }
              uVar28 = (ulonglong)DAT_140e45d18;
              DAT_140e45d28 = puVar19;
            }
LAB_1400cb0a7:
            DAT_140e44590 = DAT_1407c77a8 * 5 + DAT_140e44590;
            if (-1 < (int)uVar28) {
              dVar35 = (double)CONCAT44(uVar41,uVar40) -
                       (double)(DAT_1407c7798 / 2) * (double)CONCAT44(uVar44,uVar43);
              dVar34 = (double)CONCAT44(uVar46,uVar45);
              if ((double)CONCAT44(uVar46,uVar45) <= dVar35) {
                dVar34 = dVar35;
              }
              DAT_140e45d18 = (int)uVar28 + (int)(dVar34 * DAT_14053a380);
              uVar28 = (ulonglong)DAT_140e45d18;
              if ((int)DAT_140e45d18 < 0) {
                DAT_140e45d18 = 0;
                uVar28 = uVar29;
              }
            }
          }
          else if (puVar23[2] == 4) goto LAB_1400cb0a7;
          uVar27 = (uint)uVar28;
          puVar19 = DAT_140e45d28;
          if (puVar23[2] == 2) {
            Var13 = (unkuint9)DAT_1407c77a8;
            uVar3 = puVar23[4];
            uVar4 = puVar23[3];
            if (DAT_140e45d1c < 0x1000) {
              puVar19 = (undefined8 *)_malloc_base(0x60);
              if (puVar19 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar31 = DAT_140e45d78 == (undefined8 *)0x0;
              puVar19[5] = 0x4004cccccccccccd;
              puVar19[7] = 0x3ff3333333333333;
              *(undefined4 *)((longlong)puVar19 + 0x14) = uVar4;
              *(undefined4 *)(puVar19 + 3) = uVar3;
              *(undefined4 *)((longlong)puVar19 + 0x1c) = uVar4;
              *(undefined4 *)(puVar19 + 4) = uVar3;
              puVar19[6] = (double)(unkint9)Var13 * (double)CONCAT44(uVar48,uVar47);
              *puVar19 = 1;
              puVar19[1] = 0x1b;
              *(undefined4 *)(puVar19 + 2) = 0x42;
              *(undefined2 *)((longlong)puVar19 + 0x24) = uVar25;
              *(undefined4 *)(puVar19 + 8) = 0x28;
              *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
              *(undefined4 *)(puVar19 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
              puVar19[10] = 0x80;
              puVar19[0xb] = 0;
              if (bVar31) {
                DAT_140e45d78 = puVar19;
              }
              uVar27 = DAT_140e45d18;
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar19;
                uVar27 = DAT_140e45d18;
              }
            }
LAB_1400cb248:
            DAT_140e45d28 = puVar19;
            DAT_140e44590 = DAT_140e44590 + DAT_1407c77a8 * 10;
            if (-1 < (int)uVar27) {
              dVar35 = (double)CONCAT44(uVar41,uVar40) -
                       (double)(DAT_1407c7798 / 2) * (double)CONCAT44(uVar44,uVar43);
              dVar34 = (double)CONCAT44(uVar46,uVar45);
              if ((double)CONCAT44(uVar46,uVar45) <= dVar35) {
                dVar34 = dVar35;
              }
              DAT_140e45d18 = uVar27 + (int)(dVar34 * DAT_14053a460);
              if ((int)DAT_140e45d18 < 0) {
                DAT_140e45d18 = 0;
              }
            }
          }
          else if (puVar23[2] == 5) goto LAB_1400cb248;
          DAT_140e45d20 = 0x3c;
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e4726c);
          FUN_14018a340(DAT_140e4726c,1,1);
          *puVar23 = 0;
        }
        if ((puVar23[2] == 0) || (puVar23[2] == 3)) {
          FUN_1400c8410(*(undefined4 *)(&DAT_140e45d38 + uVar30 * 4),0x41,7,puVar23[3],puVar23[4],0,
                        dVar33 * DAT_140539f20,dVar33 * DAT_140539f20,0xff,0xff,0xff,uVar42,1,0);
        }
        if ((puVar23[2] == 1) || (puVar23[2] == 4)) {
          auVar11._8_4_ = SUB84(dVar33,0);
          auVar11._0_8_ = dVar33;
          auVar11._12_4_ = (int)((ulonglong)dVar33 >> 0x20);
          FUN_1400c8410(*(undefined4 *)(&DAT_140e45d38 + uVar30 * 4),0x41,7,puVar23[3],puVar23[4],0,
                        auVar11,0xff,0xff,0xff,uVar42,1,0);
        }
        if (puVar23[2] == 2) {
          dVar33 = dVar33 * DAT_140539f90;
          auVar12._8_4_ = SUB84(dVar33,0);
          auVar12._0_8_ = dVar33;
          auVar12._12_4_ = (int)((ulonglong)dVar33 >> 0x20);
          FUN_1400c8410(*(undefined4 *)(&DAT_140e45d38 + uVar30 * 4),0x41,7,puVar23[3],puVar23[4],0,
                        auVar12,0xff,0xff,0xff,uVar42,1,0);
        }
        if (((((float)puVar23[3] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
             (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)puVar23[3])) ||
            ((float)puVar23[4] < DAT_14053b398)) ||
           (dVar33 = DAT_14053a020, dVar34 = DAT_140539d28, _DAT_14053af5c < (float)puVar23[4])) {
          *puVar23 = 0;
          dVar33 = DAT_14053a020;
          dVar34 = DAT_140539d28;
        }
        break;
      case 6:
      case 7:
      case 8:
        iVar24 = puVar23[1];
        fVar5 = (float)puVar23[8];
        dVar33 = (double)FUN_140332d90(((double)iVar24 - 0.0) * DAT_14053a900 * dVar33 * dVar34);
        dVar33 = dVar33 * DAT_140539e60 + DAT_140539f40;
        uVar42 = SUB84(dVar33,0);
        uVar40 = (undefined4)((ulonglong)dVar33 >> 0x20);
        if (puVar23[9] == 0) {
          dVar34 = (double)FUN_1403316f0((double)(fVar38 - fVar16),uVar14);
          dVar35 = (double)FUN_1403316f0((double)(fVar2 - fVar15),uVar14);
          dVar36 = (double)FUN_1403316f0((double)(DAT_14053acfc + fVar5),uVar14);
          if (((dVar34 + dVar35 < dVar36) && (DAT_140e445fc < 0xb5)) &&
             ((DAT_140e45d34 != 3 || (iVar17 != 6)))) {
            dVar34 = (double)FUN_1403300b4((double)(fVar39 - fVar38),(double)(fVar37 - fVar2));
            dVar34 = dVar34 * DAT_14053aba0;
            puVar23[9] = 1;
            *(short *)(puVar23 + 5) = (short)(int)dVar34;
          }
        }
        else {
          dVar34 = (double)FUN_1403300b4((double)(fVar39 - fVar38),(double)(fVar37 - fVar2));
          dVar34 = dVar34 * DAT_14053aba0;
          uVar6 = *(ushort *)(puVar23 + 5);
          *(undefined8 *)(puVar23 + 6) = 0x4028000000000000;
          uVar26 = (ushort)(int)dVar34;
          iVar21 = ((int)dVar34 & 0xffffU) - (uint)uVar6;
          iVar17 = iVar21 + 0x10000;
          if (-0x8001 < iVar21) {
            iVar17 = iVar21;
          }
          iVar21 = iVar17 + -0x10000;
          if (iVar17 < 0x8001) {
            iVar21 = iVar17;
          }
          if (iVar21 < 1) {
            uVar22 = uVar6;
            if ((iVar21 < 0) && (uVar22 = uVar6 - 0x1000, -0x1000 < iVar21)) {
              uVar22 = uVar26;
            }
          }
          else {
            uVar22 = uVar26;
            if (0xfff < iVar21) {
              uVar22 = uVar6 + 0x1000;
            }
          }
          *(ushort *)(puVar23 + 5) = uVar22;
          if (0xb4 < DAT_140e445fc) {
            puVar23[9] = 0;
            *(undefined8 *)(puVar23 + 6) = 0x4010000000000000;
          }
        }
        sVar7 = *(short *)(puVar23 + 5);
        dVar34 = (double)FUN_1403307c0();
        fVar39 = (float)(dVar34 * *(double *)(puVar23 + 6)) + fVar2;
        puVar23[3] = fVar39;
        dVar34 = (double)FUN_140332d90();
        fVar37 = (float)(dVar34 * *(double *)(puVar23 + 6)) + fVar38;
        puVar23[4] = fVar37;
        if (iVar24 < 0x4b0) {
          sVar20 = -0x8000 - sVar7;
          if (DAT_140e445d8 / DAT_14053ab70 + DAT_14053ac80 <= fVar39) {
            sVar20 = sVar7;
          }
          if (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aeb0 < fVar39) {
            sVar20 = -0x8000 - sVar7;
          }
          if (fVar37 < DAT_14053ac80) {
            sVar20 = -sVar7;
          }
          if (DAT_14053aefc < fVar37) {
            sVar20 = -sVar7;
          }
          *(short *)(puVar23 + 5) = sVar20;
          uVar18 = FUN_1401346a0(*(undefined8 *)(puVar23 + 3),0x1e);
          local_res18 = (undefined4)uVar18;
          uStackX_1c = (undefined4)((ulonglong)uVar18 >> 0x20);
          puVar23[3] = local_res18;
          puVar23[4] = uStackX_1c;
        }
        dVar34 = (double)FUN_1403316f0((double)(fVar2 - fVar15),uVar14);
        dVar35 = (double)FUN_1403316f0((double)(fVar38 - fVar16),uVar14);
        dVar36 = (double)FUN_1403316f0((double)(DAT_14053aca0 + fVar5),uVar14);
        uVar41 = DAT_140e46b7c;
        fVar2 = DAT_140e445d8;
        if ((dVar34 + dVar35 < dVar36) && (DAT_140e445fc < 0xb5)) {
          if (puVar23[2] == 7) {
            if (DAT_140e445f8 < 9) {
              DAT_140e445f8 = DAT_140e445f8 + 1;
            }
            fVar38 = DAT_140e445dc - DAT_14053ad40;
            uVar27 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar27 = uVar27 * 0x800 ^ uVar27;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar27) >> 8 ^ DAT_140e9fd18 ^ uVar27;
            uVar30 = (ulonglong)DAT_140e9fd1c;
            sVar7 = (short)DAT_140e9fd1c;
            puVar19 = DAT_140e45d28;
            if (DAT_140e45d1c < 0x1000) {
              puVar19 = (undefined8 *)_malloc_base(0x60);
              if (puVar19 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              *(float *)((longlong)puVar19 + 0x14) = fVar2;
              bVar31 = DAT_140e45d78 == (undefined8 *)0x0;
              *(float *)(puVar19 + 3) = fVar38;
              *(float *)((longlong)puVar19 + 0x1c) = fVar2;
              *(float *)(puVar19 + 4) = fVar38;
              *puVar19 = 1;
              *(undefined4 *)(puVar19 + 1) = 0x17;
              *(undefined4 *)((longlong)puVar19 + 0xc) = uVar41;
              *(undefined4 *)(puVar19 + 2) = 0x4b;
              *(short *)((longlong)puVar19 + 0x24) =
                   sVar7 + (short)(uVar30 / 0x2ee1) * -0x2ee1 + -0x5770;
              puVar19[5] = 0x3ff0000000000000;
              puVar19[6] = 0x3ff0000000000000;
              puVar19[7] = 0x3ff0000000000000;
              *(undefined4 *)(puVar19 + 8) = 0x78;
              *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
              *(undefined4 *)(puVar19 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
              puVar19[10] = 0x80;
              puVar19[0xb] = 0;
              if (bVar31) {
                DAT_140e45d78 = puVar19;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar19;
              }
            }
            DAT_140e45d28 = puVar19;
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47228);
            FUN_14018a340(DAT_140e47228,1,1);
          }
          puVar19 = DAT_140e45d28;
          if (puVar23[2] == 6) {
            if (DAT_140e45d34 < 3) {
              DAT_140e45d88 = DAT_140e45d88 + *(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4)
              ;
            }
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47274);
            FUN_14018a340(DAT_140e47274,1,1);
            uVar41 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
            puVar19 = DAT_140e45d28;
            if (DAT_140e45d1c < 0x1000) {
              puVar19 = (undefined8 *)_malloc_base(0x60);
              if (puVar19 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar31 = DAT_140e45d78 == (undefined8 *)0x0;
              *puVar19 = 1;
              *(undefined4 *)(puVar19 + 1) = 0x16;
              *(undefined4 *)((longlong)puVar19 + 0xc) = uVar41;
              puVar19[2] = 0x6f;
              puVar19[3] = 0;
              *(undefined4 *)(puVar19 + 4) = 0;
              *(undefined2 *)((longlong)puVar19 + 0x24) = 0;
              puVar19[5] = 0;
              puVar19[6] = 0x3ff0000000000000;
              puVar19[7] = 0x3ff0000000000000;
              *(undefined4 *)(puVar19 + 8) = 0x78;
              *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
              *(undefined4 *)(puVar19 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
              puVar19[10] = 0xff;
              puVar19[0xb] = 0;
              if (bVar31) {
                DAT_140e45d78 = puVar19;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar19;
              }
            }
          }
          DAT_140e45d28 = puVar19;
          if (puVar23[2] == 8) {
            DAT_140e45d88 = DAT_140e45d88 + 99999;
            DAT_140e445f8 = 9;
          }
          DAT_140e45d20 = 0x3c;
          *puVar23 = 0;
        }
        if (puVar23[2] == 7) {
          auVar8._8_4_ = uVar42;
          auVar8._0_8_ = dVar33;
          auVar8._12_4_ = uVar40;
          FUN_1400c8410(DAT_140e45d68,0x4c,7,puVar23[3],puVar23[4],0,auVar8,0xff,0xff,0xff,0xff,1,0)
          ;
        }
        if (puVar23[2] == 6) {
          auVar9._8_4_ = uVar42;
          auVar9._0_8_ = dVar33;
          auVar9._12_4_ = uVar40;
          FUN_1400c8410(DAT_140e45d64,0x4c,7,puVar23[3],puVar23[4],0,auVar9,0xff,0xff,0xff,0xff,1,0)
          ;
        }
        if (puVar23[2] == 8) {
          auVar10._8_4_ = uVar42;
          auVar10._0_8_ = dVar33;
          auVar10._12_4_ = uVar40;
          FUN_1400c8410(DAT_140e4468c,0x4c,7,puVar23[3],puVar23[4],0,auVar10,0xff,0x20,0xff,0xff,1,0
                       );
        }
        if (((((float)puVar23[3] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
             (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)puVar23[3])) ||
            ((float)puVar23[4] < DAT_14053b398)) ||
           (dVar33 = DAT_14053a020, dVar34 = DAT_140539d28, _DAT_14053af5c < (float)puVar23[4])) {
          *puVar23 = 0;
          dVar33 = DAT_14053a020;
          dVar34 = DAT_140539d28;
        }
        break;
      default:
        *puVar23 = 0;
      }
      puVar23[1] = puVar23[1] + 1;
      puVar23 = *(undefined4 **)(puVar23 + 10);
    } while (puVar23 != (undefined4 *)0x0);
  }
  return;
}


