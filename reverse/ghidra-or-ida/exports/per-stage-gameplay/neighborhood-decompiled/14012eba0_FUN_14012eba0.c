// Function: FUN_14012eba0 @ 14012eba0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14012eba0(void)

{
  ulonglong uVar1;
  undefined1 auVar2 [16];
  double dVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined4 *puVar6;
  short sVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint in_stack_ffffffffffffff40;
  
  uVar16 = DAT_14053aee8;
  fVar15 = DAT_14053ac64;
  dVar3 = DAT_140539f40;
  cVar8 = '2';
  if (DAT_140e418c8 == 1) {
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e4510c);
    FUN_14018a340(DAT_140e4510c,3,1);
    DAT_140e45100 = DAT_140e4510c;
  }
  uVar17 = DAT_14053accc;
  uVar9 = DAT_14053ac80;
  dVar13 = dVar3;
  switch(DAT_140e46804) {
  case 0:
    if ((int)DAT_140e418c8 < 0x5a) {
      dVar13 = 0.0;
    }
    else if ((int)DAT_140e418c8 < 0x78) {
      dVar13 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a430) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar13 = dVar13 + 0.0;
    }
    else if (DAT_140e418c8 == 0x78) {
      DAT_140e46804 = DAT_140e46804 + 1;
      DAT_140e418c8 = 99;
      goto LAB_140130502;
    }
    break;
  case 1:
    FUN_1401307e0(2);
    break;
  case 2:
    cVar8 = '3';
    FUN_1401307e0(3);
    break;
  case 3:
    cVar8 = '4';
    FUN_1401307e0(4);
    break;
  case 4:
    cVar8 = '5';
    FUN_1401307e0(5);
    break;
  case 5:
    cVar8 = '6';
    if (DAT_140e445f0 != 0.0) {
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    FUN_140130be0(0);
    if (0xb3 < (int)DAT_140e9fd0c) {
      DAT_140e46804 = 6;
      uVar17 = uVar16;
LAB_14012ed92:
      DAT_140e9fd0c = 0;
      DAT_140e418c8 = 99;
      uVar16 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      iVar10 = DAT_140e45d1c;
      puVar4 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        puVar4[0xb] = 0;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        DAT_140e45d1c = iVar10;
        puVar4[10] = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        puVar4[7] = 0x3ff0000000000000;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[5] = 0;
        *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        puVar4[3] = 0;
        puVar4[2] = 0x6f;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar16;
        *(undefined4 *)(puVar4 + 1) = 0x16;
        *puVar4 = 1;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
      DAT_140e45d28 = puVar4;
      uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
LAB_14012eefe:
      uVar11 = DAT_140e475dc;
      uVar16 = DAT_140e445d8;
      fVar15 = DAT_140e445dc - DAT_14053ad40;
      uVar1 = (ulonglong)DAT_140e9fd1c;
      sVar7 = (short)DAT_140e9fd1c;
      puVar4 = DAT_140e45d28;
      if (iVar10 < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        sVar7 = sVar7 + (short)(uVar1 / 0x2ee1) * -0x2ee1 + -0x5770;
LAB_14012ef8e:
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)(puVar4 + 4) = fVar15;
        *(undefined4 *)((longlong)puVar4 + 0x1c) = uVar16;
        *(float *)(puVar4 + 3) = fVar15;
        *(undefined4 *)((longlong)puVar4 + 0x14) = uVar16;
        *(undefined4 *)(puVar4 + 2) = 0x4b;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar11;
        *(undefined4 *)(puVar4 + 1) = 0x17;
        *puVar4 = 1;
        *(short *)((longlong)puVar4 + 0x24) = sVar7;
        puVar4[5] = 0x3ff0000000000000;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        puVar4[10] = 0xff;
        puVar4[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
LAB_14012f02b:
      DAT_140e45d28 = puVar4;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47228);
      FUN_14018a340(DAT_140e47228,1,1);
      uVar16 = uVar17;
    }
    break;
  case 6:
    cVar8 = '7';
    FUN_1401307e0(7);
    break;
  case 7:
    cVar8 = '8';
    FUN_1401307e0(8);
    break;
  case 8:
    cVar8 = (DAT_140e44194 != 1) + '9';
    FUN_1401307e0(9);
    break;
  case 9:
    cVar8 = ';';
    FUN_140130be0(1);
    if (DAT_140e418c8 == 100) {
      FUN_14007b710(0,0x5dc,0xf0,0);
      FUN_14007b710(0,0x5dc,0x1e0,0);
    }
    if (DAT_140e9fd0c == 2) {
      FUN_14007b710(0,0x5dc,0xdc,0);
      FUN_14007b710(0,0x5dc,0x168,0);
      FUN_14007b710(0,0x5dc,500,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e9fd0c == 6) {
      FUN_14007b710(0,0x5dc,0x78,0);
      FUN_14007b710(0,0x5dc,0x118,0);
      FUN_14007b710(0,0x5dc,0x1b8,0);
      FUN_14007b710(0,0x5dc,600,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    uVar16 = uVar17;
    if (10 < (int)DAT_140e9fd0c) {
      DAT_140e46804 = 10;
      goto LAB_14012ed92;
    }
    break;
  case 10:
    cVar8 = '<';
    FUN_1401307e0(0xb);
    break;
  case 0xb:
    cVar8 = '=';
    FUN_1401307e0(0xc);
    break;
  case 0xc:
    cVar8 = (DAT_140e44194 != 1) + '>';
    FUN_1401307e0(0xd);
    break;
  case 0xd:
    cVar8 = '@';
    FUN_1401307e0(0xe);
    break;
  case 0xe:
    cVar8 = 'A';
    FUN_140130be0(2);
    if (DAT_140e418c8 == 100) {
      FUN_14007b710(2,8000,0x168,0);
    }
    if (DAT_140e9fd0c == 1) {
      FUN_14007b710(2,8000,0xb4,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e9fd0c == 3) {
      FUN_14007b710(2,8000,0x21c,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e9fd0c == 5) {
      FUN_14007b710(2,8000,0xdc,0);
      FUN_14007b710(2,8000,500,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    uVar16 = uVar17;
    if (7 < (int)DAT_140e9fd0c) {
      DAT_140e418c8 = 99;
      DAT_140e46804 = 0xf;
      DAT_140e9fd0c = 0;
      uVar16 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      iVar10 = DAT_140e45d1c;
      puVar4 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        *puVar4 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar4 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar16;
        puVar4[2] = 0x6f;
        puVar4[3] = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
        puVar4[5] = 0;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        puVar4[10] = 0xff;
        puVar4[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        DAT_140e45d1c = iVar10;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
      DAT_140e45d28 = puVar4;
      uVar9 = DAT_140e418c8 >> 0x1e ^ DAT_140e418c8;
LAB_14012f420:
      uVar9 = uVar9 * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
      goto LAB_14012eefe;
    }
    break;
  case 0xf:
    cVar8 = 'B';
    FUN_1401307e0(0x10);
    break;
  case 0x10:
    cVar8 = 'C';
    FUN_1401307e0(0x11);
    break;
  case 0x11:
    cVar8 = 'D';
    FUN_1401307e0(0x12);
    break;
  case 0x12:
    cVar8 = 'E';
    FUN_1401307e0(0x13);
    break;
  case 0x13:
    cVar8 = 'F';
    FUN_140130be0(4);
    if (DAT_140e418c8 == 0xa0) {
      FUN_14007b710(1,3000,0x168,0);
    }
    if (DAT_140e9fd0c == 1) {
      FUN_14007b710(1,3000,0xb4,0);
      FUN_14007b710(1,3000,0x21c,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e9fd0c == 4) {
      FUN_14007b710(1,3000,0xa0,0);
      FUN_14007b710(1,3000,0x168,0);
      FUN_14007b710(1,3000,0x230,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e9fd0c == 8) {
      FUN_14007b710(3,40000,0x168,0);
      DAT_140e9fd0c = DAT_140e9fd0c + 1;
    }
    if (DAT_140e445fc == 0xb4) {
      DAT_140e418c8 = 99;
      DAT_140e46804 = 0x14;
      DAT_140e9fd0c = 0;
      FUN_140079b00();
    }
    uVar16 = uVar17;
    if (9 < (int)DAT_140e9fd0c) {
      DAT_140e418c8 = 99;
      DAT_140e46804 = 0x15;
      DAT_140e9fd0c = 0;
      FUN_14006c420();
      uVar16 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      iVar10 = DAT_140e45d1c;
      puVar4 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        *puVar4 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar4 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar16;
        puVar4[2] = 0x6f;
        puVar4[3] = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
        puVar4[5] = 0;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        puVar4[10] = 0xff;
        puVar4[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        DAT_140e45d1c = iVar10;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
      DAT_140e45d28 = puVar4;
      uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
LAB_14012f77f:
      uVar11 = DAT_140e475dc;
      uVar16 = DAT_140e445d8;
      fVar15 = DAT_140e445dc - DAT_14053ad40;
      sVar7 = (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x2ee1) * -0x2ee1 + -0x5770;
      puVar4 = DAT_140e45d28;
      if (iVar10 < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        goto LAB_14012ef8e;
      }
      goto LAB_14012f02b;
    }
    break;
  case 0x14:
    cVar8 = 'G';
    FUN_1401307e0(0x13);
    break;
  case 0x15:
    cVar8 = 'H';
    FUN_1401307e0(0x16);
    break;
  case 0x16:
    cVar8 = 'I';
    FUN_1401307e0(0x17);
    break;
  case 0x17:
    FUN_1401309b0(0x18,0);
    break;
  case 0x18:
    dVar14 = dVar3;
    if (0x4f < (int)DAT_140e418c8) {
      if ((int)DAT_140e418c8 < 100) {
        dVar14 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a3a0) * DAT_14053a890
                                       * DAT_14053a020 * DAT_140539d28);
        dVar14 = dVar14 + 0.0;
      }
      else {
        dVar14 = 0.0;
      }
    }
    uVar17 = DAT_140e477d8;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar17;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(double *)(puVar6 + 8) = dVar14;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x43b40000;
    *(undefined2 *)(puVar6 + 5) = 0;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar12) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    cVar8 = 'J';
    DAT_140e46c88 = puVar6;
    FUN_1401307e0(0x19);
    break;
  case 0x19:
    cVar8 = 'K';
    FUN_1401307e0(0x1a);
    break;
  case 0x1a:
    cVar8 = 'L';
    FUN_1401307e0(0x1b);
    break;
  case 0x1b:
    cVar8 = 'M';
    FUN_140130be0(4);
    if (DAT_140e418c8 == 100) {
      DAT_140e9fd10 = 0x7a4d422b;
      DAT_140e9fd14 = 0x20099495;
      DAT_140e9fd18 = 0xb05e5bcd;
      DAT_140e9fd1c = 0xf4be4b0;
      FUN_14007b710(4,10000,0x1c5,0);
    }
    if (0 < (int)DAT_140e9fd0c) {
      uVar9 = DAT_140e9fd0c & 0x80000001;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
      }
      if (uVar9 == 1) {
        uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
        FUN_14007b710(4,10000,DAT_140e9fd1c % 0x169 + 0x78,0);
        DAT_140e9fd0c = DAT_140e9fd0c + 1;
      }
    }
    uVar16 = uVar17;
    if (0 < DAT_140e45d34) {
      DAT_140e46804 = 0x1c;
      DAT_140e418c8 = 99;
      DAT_140e9fd0c = 0;
      FUN_140079b00();
LAB_14012fb21:
      uVar16 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      iVar10 = DAT_140e45d1c;
      puVar4 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        puVar4[0xb] = 0;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        DAT_140e45d1c = iVar10;
        puVar4[10] = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        puVar4[7] = 0x3ff0000000000000;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[5] = 0;
        *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        puVar4[3] = 0;
        puVar4[2] = 0x6f;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar16;
        *(undefined4 *)(puVar4 + 1) = 0x16;
        *puVar4 = 1;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
      DAT_140e45d28 = puVar4;
      uVar9 = DAT_140e418c8 >> 0x1e ^ DAT_140e418c8;
      goto LAB_14012f420;
    }
    break;
  case 0x1c:
    cVar8 = 'N';
    FUN_1401307e0(0x1d);
    break;
  case 0x1d:
    cVar8 = 'O';
    FUN_140130be0(5);
    if (DAT_140e418c8 == 0x82) {
      FUN_14007b710(5,99999999,0x168,0);
    }
    uVar16 = uVar17;
    if ((DAT_140e45d34 == 0) && (DAT_140e44600 == -0x1e)) {
      DAT_140e46804 = 0x1e;
      DAT_140e418c8 = 99;
      DAT_140e9fd0c = 0;
      FUN_140079b00();
      FUN_14006c420();
      goto LAB_14012fb21;
    }
    break;
  case 0x1e:
    cVar8 = 'P';
    FUN_1401307e0(0x1f);
    break;
  case 0x1f:
    cVar8 = 'Q';
    FUN_1401307e0(0x20);
    break;
  case 0x20:
    cVar8 = 'R';
    FUN_1401307e0(0x21);
    break;
  case 0x21:
    cVar8 = 'S';
    FUN_140130be0(3);
    if (DAT_140e418c8 == 100) {
      DAT_140e9fd10 = 0x7a4d422b;
      DAT_140e9fd14 = 0x20099495;
      DAT_140e9fd18 = 0xb05e5bcd;
      DAT_140e9fd1c = 0xf4be4b0;
      FUN_1400ca6d0(6);
      in_stack_ffffffffffffff40 = uVar9;
    }
    if ((DAT_140e45d34 == 0) && (DAT_140e418c8 == 0xa1)) {
      DAT_140e418c8 = 0xa0;
    }
    else if (DAT_140e418c8 == 0xdc) {
      FUN_14007b710(5,99999999,0x168,0);
    }
    if (DAT_140e445fc == 0x104) {
      DAT_140e418c8 = 99;
      DAT_140e46804 = 0x22;
      DAT_140e9fd0c = 0;
      FUN_140079b00();
    }
    uVar16 = uVar17;
    if (((DAT_140e45d34 == 0) && (DAT_140e44600 == -0x3c)) && (0x95 < (int)DAT_140e418c8)) {
      DAT_140e418c8 = 99;
      DAT_140e46804 = 0x23;
      DAT_140e9fd0c = 0;
      FUN_140079b00();
      FUN_14006c420();
      uVar16 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      iVar10 = DAT_140e45d1c;
      puVar4 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar4 = (undefined8 *)_malloc_base(0x60);
        if (puVar4 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar10 = DAT_140e45d1c + 1;
        *puVar4 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar4 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar4 + 0xc) = uVar16;
        puVar4[2] = 0x6f;
        puVar4[3] = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
        puVar4[5] = 0;
        puVar4[6] = 0x3ff0000000000000;
        puVar4[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar4 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
        *(undefined4 *)(puVar4 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
        puVar4[10] = 0xff;
        puVar4[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar4;
        }
        DAT_140e45d1c = iVar10;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar4;
        }
      }
      DAT_140e45d28 = puVar4;
      uVar9 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
      goto LAB_14012f77f;
    }
    break;
  case 0x22:
    cVar8 = 'T';
    FUN_1401307e0(0x21);
    if (DAT_140e418c8 == 0xa0) {
      DAT_140e45d88 = 0;
      DAT_140e45d34 = 0;
      goto LAB_140130502;
    }
    break;
  case 0x23:
    cVar8 = 'U';
    FUN_1401307e0(0x24);
    break;
  case 0x24:
    cVar8 = 'V';
    FUN_1401307e0(0x25);
    break;
  case 0x25:
    FUN_1401309b0(0x26,1);
    break;
  case 0x26:
    dVar14 = dVar3;
    if (0x4f < (int)DAT_140e418c8) {
      if ((int)DAT_140e418c8 < 100) {
        dVar14 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a3a0) * DAT_14053a890
                                       * DAT_14053a020 * DAT_140539d28);
        dVar14 = dVar14 + 0.0;
      }
      else {
        dVar14 = 0.0;
      }
    }
    uVar17 = DAT_140e477dc;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar17;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(double *)(puVar6 + 8) = dVar14;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x43b40000;
    *(undefined2 *)(puVar6 + 5) = 0;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar12) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    cVar8 = 'W';
    DAT_140e46c88 = puVar6;
    FUN_1401307e0(0x27);
    break;
  case 0x27:
    cVar8 = 'X';
    FUN_1401307e0(0x28);
    break;
  case 0x28:
    cVar8 = 'Y';
    FUN_1401307e0(0x29);
    break;
  case 0x29:
    cVar8 = 'Z';
    FUN_1401307e0(0x2a);
    break;
  case 0x2a:
    cVar8 = '[';
    FUN_1401307e0(0x2b);
    break;
  case 0x2b:
    cVar8 = '\\';
    FUN_1401307e0(0x2c);
    break;
  case 0x2c:
    cVar8 = ']';
    FUN_1401307e0(0x2d);
    break;
  case 0x2d:
    FUN_1401309b0(0x2e,2);
    break;
  case 0x2e:
    dVar14 = dVar3;
    if (0x4f < (int)DAT_140e418c8) {
      if ((int)DAT_140e418c8 < 100) {
        dVar14 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a3a0) * DAT_14053a890
                                       * DAT_14053a020 * DAT_140539d28);
        dVar14 = dVar14 + 0.0;
      }
      else {
        dVar14 = 0.0;
      }
    }
    uVar17 = DAT_140e477e0;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e48 = _DAT_140e46e48 + 1;
    bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar17;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(double *)(puVar6 + 8) = dVar14;
    puVar6[1] = 0x6e;
    puVar6[2] = 1;
    puVar6[3] = 0x44200000;
    puVar6[4] = 0x43b40000;
    *(undefined2 *)(puVar6 + 5) = 0;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar12) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    cVar8 = '^';
    DAT_140e46c88 = puVar6;
    FUN_1401307e0(0x2f);
    break;
  case 0x2f:
    if (0x9f < (int)DAT_140e418c8) {
      if ((int)DAT_140e418c8 < 0xbe) {
        dVar13 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_14053a4c8) * DAT_14053a798
                                       * DAT_14053a020 * DAT_140539d28);
        dVar13 = dVar13 + 0.0;
      }
      else {
        dVar13 = 0.0;
      }
      transition_tile_wipe_out_candidate(DAT_140e418c8 - 0xa0);
    }
    if ((int)DAT_140e418c8 < 200) {
      dVar14 = dVar3;
      if (0x77 < (int)DAT_140e418c8) {
        if ((int)DAT_140e418c8 < 200) {
          dVar14 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a340) *
                                         DAT_14053a5a0 * DAT_14053a020 * DAT_140539d28);
          dVar14 = dVar14 + 0.0;
        }
        else {
          dVar14 = 0.0;
        }
      }
      _DAT_1407c777c = (float)dVar14;
      FUN_140184700((int)((float)DAT_140e4418c * fVar15 * _DAT_1407c777c),DAT_140e45100);
    }
    if (DAT_140e418c8 == 200) {
      FUN_1400f6fb0();
      DAT_140e418c8 = 0;
      puVar6 = &DAT_140e45100;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      DAT_140e41928 = 0;
      DAT_1407c7798 = 1;
      do {
        FUN_14018f230(*puVar6,0);
        puVar6 = puVar6 + 1;
      } while ((longlong)puVar6 < 0x140e45178);
      _DAT_1407c777c = 1.0;
      FUN_140184700((int)((float)DAT_140e4418c * fVar15),DAT_140e45108);
      FUN_14018a340(DAT_140e45108,3,1);
      if (DAT_140e441bc == 0) {
        DAT_140e441bc = 1;
        puVar4 = (undefined8 *)&DAT_140e41b28;
        DAT_140e45274 = 0;
        lVar5 = 3;
        DAT_140e46064 = 0;
        do {
          _DAT_140e445c4 = *puVar4;
          _DAT_140e445cc = puVar4[1];
          puVar4 = puVar4 + 2;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        DAT_140e45270 = 3;
      }
      else {
        DAT_140e45274 = 7;
        DAT_140e45270 = 10;
      }
    }
  }
  lVar5 = DAT_140e47908;
  if (DAT_140e418c8 == 100) {
    while (lVar5 != 0) {
      lVar5 = *(longlong *)(lVar5 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
  }
LAB_140130502:
  if ((0x2d < DAT_140e46804) ||
     ((0x202000800000U >> ((longlong)(int)DAT_140e46804 & 0x3fU) & 1) == 0)) {
    uVar9 = in_stack_ffffffffffffff40 & 0xffff0000;
    FUN_1400c8410(DAT_140e47540,0x6e,1,DAT_14053aedc,uVar16,uVar9,dVar3,dVar13,0xff,0xff,0xff,0xff,1
                  ,0);
    if ((DAT_140e46804 != 0) && (DAT_140e46804 != 0x2f)) {
      auVar2._8_4_ = SUB84(dVar13,0);
      auVar2._0_8_ = dVar13;
      auVar2._12_4_ = (int)((ulonglong)dVar13 >> 0x20);
      FUN_1400c8410(DAT_140e474fc,0x6e,1,DAT_14053ae44,uVar16,uVar9 & 0xffff0000,auVar2,0xff,0xff,
                    0xff,0xff,1,0);
    }
    if ((DAT_140e418c8 == 100) && (DAT_140e46804 - 1 < 0x2e)) {
      FUN_14012e070(cVar8,4);
    }
  }
  FUN_1400d9b60(3,0x70,0xff);
  if (((int)DAT_140e46804 < 0x1b) && (30000 < DAT_140e45d88)) {
    DAT_140e45d88 = 30000;
  }
  DAT_140e41a3c = (uint)((int)DAT_140e46804 < 0x21);
  return;
}


