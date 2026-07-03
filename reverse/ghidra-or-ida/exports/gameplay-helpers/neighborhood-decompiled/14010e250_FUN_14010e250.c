// Function: FUN_14010e250 @ 14010e250
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010e250(void)

{
  short sVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  double dVar10;
  float fVar11;
  undefined4 uVar12;
  
  iVar5 = 0;
  iVar6 = *(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4);
  iVar7 = (DAT_140e45d34 + 1) * iVar6;
  if (iVar6 * 3 < DAT_140e45d88) {
    DAT_140e45d88 = iVar6 * 3;
  }
  dVar10 = DAT_14053a460;
  if (DAT_140e45d34 != 3) {
    if (0 < DAT_140e45d34) {
      iVar5 = iVar6 * DAT_140e45d34;
    }
    dVar10 = (((double)DAT_140e45d88 - (double)iVar5) / ((double)iVar7 - (double)iVar5)) *
             DAT_14053a460;
  }
  puVar4 = DAT_140e45d28;
  if ((iVar7 <= DAT_140e45d88) && (DAT_140e45d34 < 3)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47278);
    FUN_14018a340(DAT_140e47278,1,1);
    uVar3 = DAT_140e46b80;
    uVar12 = DAT_140e445d8;
    fVar11 = DAT_140e445dc - DAT_14053ad40;
    uVar8 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar8 = uVar8 * 0x800 ^ uVar8;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
    uVar8 = DAT_140e9fd1c / 0x2ee1;
    sVar1 = (short)DAT_140e9fd1c;
    puVar4 = DAT_140e45d28;
    iVar6 = DAT_140e45d1c;
    if (DAT_140e45d1c < 0x1000) {
      puVar4 = (undefined8 *)_malloc_base(0x60);
      if (puVar4 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *(undefined4 *)((longlong)puVar4 + 0x14) = uVar12;
      iVar6 = DAT_140e45d1c + 1;
      *(float *)(puVar4 + 3) = fVar11;
      bVar9 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar4 + 0x1c) = uVar12;
      *(float *)(puVar4 + 4) = fVar11;
      *puVar4 = 1;
      *(undefined4 *)(puVar4 + 1) = 0x17;
      *(undefined4 *)((longlong)puVar4 + 0xc) = uVar3;
      *(undefined4 *)(puVar4 + 2) = 0x4b;
      *(short *)((longlong)puVar4 + 0x24) = sVar1 + (short)uVar8 * -0x2ee1 + -0x5770;
      puVar4[5] = 0x3ff0000000000000;
      puVar4[6] = 0x3ff0000000000000;
      puVar4[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar4 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
      *(undefined4 *)(puVar4 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
      puVar4[10] = 0x80;
      puVar4[0xb] = 0;
      if (bVar9) {
        DAT_140e45d78 = puVar4;
      }
      DAT_140e45d1c = iVar6;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar4;
      }
    }
    DAT_140e45d28 = puVar4;
    uVar12 = DAT_140e41a74;
    DAT_140e45d34 = DAT_140e45d34 + 1;
    puVar4 = DAT_140e45d28;
    if (((DAT_140e45d34 == 1) && (DAT_140e445d0 != 3)) && (iVar6 < 0x1000)) {
      puVar4 = (undefined8 *)_malloc_base(0x60);
      if (puVar4 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar6 = DAT_140e45d1c + 1;
      *puVar4 = 1;
      bVar9 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)(puVar4 + 1) = 0x14;
      *(undefined4 *)((longlong)puVar4 + 0xc) = uVar12;
      puVar4[2] = 0x27;
      puVar4[3] = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
      puVar4[5] = 0x3ff0000000000000;
      puVar4[6] = 0x3ff0000000000000;
      puVar4[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar4 + 8) = 0;
      *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
      *(undefined4 *)(puVar4 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
      puVar4[10] = 0xff;
      puVar4[0xb] = 0;
      if (bVar9) {
        DAT_140e45d78 = puVar4;
      }
      DAT_140e45d1c = iVar6;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar4;
      }
    }
    DAT_140e45d28 = puVar4;
    uVar12 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar4 = DAT_140e45d28;
    if (iVar6 < 0x1000) {
      puVar4 = (undefined8 *)_malloc_base(0x60);
      if (puVar4 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar9 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar4 = 1;
      *(undefined4 *)(puVar4 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar4 + 0xc) = uVar12;
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
      if (bVar9) {
        DAT_140e45d78 = puVar4;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar4;
      }
    }
  }
  DAT_140e45d28 = puVar4;
  uVar2 = _DAT_14053bb20;
  if (0x4f < DAT_140e445fc - 0xb4U) {
    uVar12 = 0xff;
    switch(DAT_1407c7798) {
    case 0:
    case 2:
    case 6:
    case 10:
      uVar12 = 0x60;
      break;
    case 1:
      uVar12 = 0x80;
    }
    FUN_1400c8410(DAT_140e473a8,0x4d,7,DAT_140e445d8,DAT_140e445dc,(short)DAT_140e44acc * -0x100,
                  _DAT_14053bb20,_UNK_14053bb28,uVar12,uVar12,uVar12,0x80,1,0);
    if (DAT_140e45d34 == 0) {
      FUN_1400c8410(DAT_140e473ac,0x4c,0x16,DAT_140e445d8,DAT_140e445dc,0,dVar10,uVar2,uVar12,uVar12
                    ,uVar12,0x80,1,0);
    }
    if (DAT_140e45d34 == 1) {
      FUN_1400c8410(DAT_140e473ac,0x4c,0x16,DAT_140e445d8,DAT_140e445dc,0,dVar10,uVar2,0x80,0xff,
                    0x80,0x80,1,0);
    }
    if (DAT_140e45d34 == 2) {
      FUN_1400c8410(DAT_140e473ac,0x4c,0x16,DAT_140e445d8,DAT_140e445dc,0,dVar10,uVar2,0x80,0xff,
                    0xff,0x80,1,0);
    }
    if (DAT_140e45d34 == 3) {
      uVar8 = DAT_140e44acc & 0x80000001;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
      }
      if (uVar8 == 0) {
        uVar12 = 0x80;
      }
      else {
        uVar12 = 0xff;
      }
      FUN_1400c8410(DAT_140e473ac,0x4c,0x16,DAT_140e445d8,DAT_140e445dc,0,dVar10,uVar2,uVar12,0xff,
                    0xff,0x80,1,0);
    }
  }
  return;
}


