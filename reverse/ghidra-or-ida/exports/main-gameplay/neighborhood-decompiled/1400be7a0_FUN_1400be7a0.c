// Function: FUN_1400be7a0 @ 1400be7a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400be7a0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  int iVar11;
  bool bVar12;
  undefined8 uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  int local_res8;
  int local_res10;
  longlong local_res18;
  uint in_stack_fffffffffffffe10;
  undefined2 uVar28;
  undefined8 in_stack_fffffffffffffe18;
  undefined4 uVar29;
  undefined8 in_stack_fffffffffffffe20;
  undefined8 uVar30;
  undefined4 uVar31;
  undefined8 in_stack_fffffffffffffe28;
  undefined8 uVar32;
  undefined4 uVar33;
  undefined8 local_198;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 local_168;
  longlong lStack_160;
  undefined1 auStack_158 [16];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined1 local_f8 [16];
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  
  uVar27 = DAT_140e46a0c;
  uVar26 = DAT_140e450dc;
  uVar1 = DAT_140e418c8;
  iVar4 = DAT_1407c7798;
  fVar25 = DAT_14053ae30;
  fVar20 = DAT_14053ac2c;
  dVar14 = DAT_14053ac08;
  dVar16 = DAT_14053a5f8;
  dVar18 = DAT_14053a4d8;
  dVar24 = DAT_14053a020;
  fVar22 = DAT_140539da8;
  dVar17 = DAT_140539d28;
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
  iVar5 = 0;
  lVar10 = (longlong)DAT_1407c7798;
  iVar3 = 0;
  switch(DAT_1407c7798) {
  default:
    uVar32 = CONCAT44(uVar33,0xff);
    uVar30 = CONCAT44(uVar31,0xff);
    uVar13 = CONCAT44(uVar29,0xff);
    FUN_1400c2670(0,DAT_140e469b0,4,0xe,DAT_14053ae30,0xff,uVar13,uVar30,uVar32,DAT_140539da8);
    uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
    dVar17 = (double)FUN_140332d90(((double)(int)DAT_140e44acc - 0.0) * DAT_14053a628 *
                                   DAT_14053a020 * DAT_140539d28);
    FUN_1400c2670(1,DAT_140e469b4,5,0xe,fVar25,0xff,CONCAT44(uVar26,0x40),CONCAT44(uVar27,0x40),
                  CONCAT44(uVar29,0x30 - (int)(dVar17 * _DAT_14053b130)),DAT_14053a2e8);
    fVar25 = DAT_14053af14;
    fVar20 = DAT_14053ad80;
    fVar22 = DAT_14053ad40;
    do {
      uVar26 = DAT_140e45074;
      fVar19 = (float)((int)DAT_140e44acc % 0x78) + (float)iVar5 * fVar22;
      fVar23 = (float)((int)DAT_140e44acc % 0xa0) + (float)iVar5 * fVar20;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar2[3] = fVar19;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      *puVar2 = uVar26;
      puVar2[1] = 6;
      puVar2[2] = 7;
      puVar2[4] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0x4000;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0x40;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0x18;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      _DAT_140e46ca8 = _DAT_140e46ca8 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e45074;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar2 = uVar26;
      puVar2[1] = 6;
      puVar2[2] = 7;
      puVar2[4] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0x4000;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[3] = fVar25 - fVar19;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0x40;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0x18;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      _DAT_140e46ca8 = _DAT_140e46ca8 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e45074;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar2[4] = fVar23;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      *puVar2 = uVar26;
      puVar2[1] = 6;
      puVar2[2] = 7;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0x40;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0x18;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      _DAT_140e46ca8 = _DAT_140e46ca8 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e45074;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar2 = uVar26;
      puVar2[1] = 6;
      puVar2[2] = 7;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[4] = fVar25 - fVar23;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0x40;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0x18;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      _DAT_140e46ca8 = _DAT_140e46ca8 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      iVar5 = iVar5 + 1;
      puVar6 = DAT_140e45d28;
      DAT_140e46c88 = puVar2;
    } while (iVar5 < 7);
    break;
  case 1:
    iVar4 = 0xff;
    if (DAT_140e418c8 - 300 < 300) {
      dVar17 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a388 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar4 = (int)(dVar17 * DAT_14053a5f8);
    }
    uVar13 = CONCAT44(uVar29,DAT_14053a170);
    fVar20 = (float)FUN_140134b10(uVar1,600,0x348,*(int *)(&UNK_140538ad8 + lVar10 * 4) + -300,
                                  *(int *)(&UNK_140538ad8 + lVar10 * 4),DAT_14053ac2c,uVar13);
    fVar22 = DAT_14053ae30;
    uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if ((int)uVar1 < 0x259) {
      if ((int)uVar1 < 600) {
        iVar3 = iVar4;
      }
      uVar32 = CONCAT44(uVar33,iVar3);
      uVar30 = CONCAT44(uVar31,0xff);
      uVar13 = CONCAT44(uVar26,0xff);
      FUN_1400c2670(0,DAT_140e469b8,4,0xe,DAT_14053ae30,0xff,uVar13,uVar30,uVar32,fVar20 + fVar20);
      uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar31 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar33 = (undefined4)((ulonglong)uVar32 >> 0x20);
    }
    FUN_1400c2670(1,DAT_140e469c0,1,0xe,fVar22,0xff,CONCAT44(uVar26,0xff),CONCAT44(uVar31,0xff),
                  CONCAT44(uVar33,0xff),fVar20 * DAT_140539d20);
    FUN_1400c2670(2,DAT_140e469c4,3,0xe,fVar22,0xff,0xff,0xff,0xff,fVar20);
    FUN_1400c2670(3,DAT_140e469bc,5,0xe,fVar22,0xff,0xff,0xff,0x80,fVar20 * DAT_14053a2e8);
    puVar6 = DAT_140e45d28;
    break;
  case 2:
    iVar4 = *(int *)(&UNK_140538ad8 + lVar10 * 4);
    fVar22 = (float)FUN_140134b10(DAT_140e418c8,0,300,iVar4,iVar4 + 600,DAT_14053ac58,
                                  CONCAT44(uVar29,DAT_140539da8));
    uVar26 = DAT_140e46874;
    puVar2 = DAT_140e46c88;
    if ((0x2ed < (int)uVar1) && ((int)uVar1 <= iVar4 + 300)) {
      fVar20 = (float)(int)uVar1 - _DAT_14053b038;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = fVar20;
      *puVar2 = uVar26;
      puVar2[1] = 0x14;
      puVar2[2] = 0xe;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 10) = 0;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0x30;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e46874;
      fVar20 = (float)(int)DAT_140e418c8 - _DAT_14053b03c;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = fVar20;
      *puVar2 = uVar26;
      puVar2[1] = 0x14;
      puVar2[2] = 0xe;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0xff;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
    }
    DAT_140e46c88 = puVar2;
    fVar20 = DAT_14053ae30;
    FUN_1400c2670(0,DAT_140e469c8,2,0xe,DAT_14053ae30,0xff,0xff,CONCAT44(uVar31,0xff),
                  CONCAT44(uVar33,0xff),fVar22 * DAT_140539d20);
    FUN_1400c2670(1,DAT_140e469cc,4,0xe,fVar20,0xff,0xff,0xff,0xff,fVar22 * DAT_140539d4c);
    puVar6 = DAT_140e45d28;
    break;
  case 3:
    puVar2 = DAT_140e46c88;
    if (DAT_140e418c8 - 0x5dc < 0x1f41) {
      iVar4 = DAT_140e418c8 - 0x5dc;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = (float)iVar4;
      *puVar2 = uVar27;
      puVar2[1] = 0x14;
      puVar2[2] = 0x10;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0xff;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
    }
    DAT_140e46c88 = puVar2;
    uVar26 = DAT_140e45094;
    iVar4 = DAT_140e45d1c;
    puVar6 = DAT_140e45d28;
    if (DAT_140e418c8 == 0x578) {
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar4 = DAT_140e45d1c + 1;
        *puVar6 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar6 + 1) = 0x3a;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
        *(undefined4 *)(puVar6 + 2) = 0x13;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43f60000;
        *(undefined4 *)(puVar6 + 3) = 0xc3480000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43f60000;
        *(undefined4 *)(puVar6 + 4) = 0xc3480000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar6;
        }
        DAT_140e45d1c = iVar4;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
        goto LAB_1400bedf5;
      }
    }
    else {
LAB_1400bedf5:
      DAT_140e45d28 = puVar6;
      uVar26 = DAT_140e45094;
      puVar6 = DAT_140e45d28;
      if (DAT_140e418c8 == 0x10b8) {
        if (0xfff < iVar4) goto LAB_1400bf06c;
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar4 = DAT_140e45d1c + 1;
        *puVar6 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar6 + 1) = 0x3a;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
        *(undefined4 *)(puVar6 + 2) = 0x13;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43550000;
        *(undefined4 *)(puVar6 + 3) = 0xc3480000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43550000;
        *(undefined4 *)(puVar6 + 4) = 0xc3480000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar6;
        }
        DAT_140e45d1c = iVar4;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      uVar26 = DAT_140e45094;
      puVar6 = DAT_140e45d28;
      if ((DAT_140e418c8 == 0x1c0c) && (iVar4 < 0x1000)) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar4 = DAT_140e45d1c + 1;
        *puVar6 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar6 + 1) = 0x3a;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
        *(undefined4 *)(puVar6 + 2) = 0x13;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0x42d20000;
        *(undefined4 *)(puVar6 + 3) = 0xc3480000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x42d20000;
        *(undefined4 *)(puVar6 + 4) = 0xc3480000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar6;
        }
        DAT_140e45d1c = iVar4;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
        uVar26 = DAT_140e45094;
        if (iVar4 < 0x1000) {
          DAT_140e45d28 = puVar6;
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x3a;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
          *(undefined4 *)(puVar6 + 2) = 0x13;
          *(undefined4 *)((longlong)puVar6 + 0x14) = 0x441b8000;
          *(undefined4 *)(puVar6 + 3) = 0xc3480000;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x441b8000;
          *(undefined4 *)(puVar6 + 4) = 0xc3480000;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar12) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
    }
LAB_1400bf06c:
    DAT_140e45d28 = puVar6;
    fVar22 = DAT_14053ae30;
    FUN_1400c2670(0,DAT_140e469d0,2,0xe,DAT_14053ae30,0xff,CONCAT44(uVar29,0xff),
                  CONCAT44(uVar31,0xff),CONCAT44(uVar33,0xff),DAT_14053ab70);
    FUN_1400c2670(1,DAT_140e469d4,4,0xf,fVar22,0xff,0xff,0xff,0xff,DAT_14053ac34);
    fVar25 = DAT_14053af14;
    fVar20 = DAT_14053adb4;
    fVar22 = DAT_14053ad70;
    do {
      uVar26 = DAT_140e45074;
      iVar4 = DAT_140e44acc * 0xf;
      fVar19 = (float)((int)(DAT_140e44acc * 2) % 0x96) + (float)iVar5 * fVar22;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar2 = uVar26;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      puVar2[3] = fVar19;
      puVar2[1] = 3;
      puVar2[2] = 8;
      puVar2[4] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0x4000;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xc0;
      puVar2[0xd] = 0x30;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      _DAT_140e46c9c = _DAT_140e46c9c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e45074;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar2 = uVar26;
      puVar2[1] = 3;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[2] = 8;
      puVar2[4] = 0x43b40000;
      puVar2[3] = fVar25 - fVar19;
      *(undefined2 *)(puVar2 + 5) = 0x4000;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      puVar2[10] = 0;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xc0;
      puVar2[0xd] = 0x30;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      _DAT_140e46c9c = _DAT_140e46c9c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      uVar26 = DAT_140e45074;
      DAT_140e46c88 = puVar2;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar2 = uVar26;
      *(undefined2 *)(puVar2 + 5) = 0;
      puVar2[10] = 0;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      puVar2[4] = (float)(iVar4 % 200) + (float)iVar5 * fVar20;
      puVar2[1] = 3;
      puVar2[2] = 8;
      puVar2[3] = 0x43b40000;
      *(undefined8 *)(puVar2 + 6) = 0x4000000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xc0;
      puVar2[0xd] = 0x30;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      _DAT_140e46c9c = _DAT_140e46c9c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
      iVar5 = iVar5 + 1;
      puVar6 = DAT_140e45d28;
      DAT_140e46c88 = puVar2;
    } while (iVar5 < 7);
    break;
  case 4:
    iVar4 = *(int *)(&UNK_140538ad8 + lVar10 * 4);
    iVar3 = 0xff;
    if (iVar4 == 0) {
LAB_1400bf48a:
      iVar5 = 0xff;
      if (iVar4 == 0) goto LAB_1400bf4f6;
LAB_1400bf493:
      iVar5 = 0xff;
      if ((int)DAT_140e418c8 < 0) {
        if ((int)DAT_140e418c8 < iVar4) goto LAB_1400bf4f6;
      }
      else if ((int)DAT_140e418c8 < iVar4) goto LAB_1400bf4a5;
      iVar5 = 0x60;
LAB_1400bf4ff:
      iVar11 = 0xc0;
      if ((int)uVar1 < 0) {
        if (iVar4 <= (int)uVar1) goto LAB_1400bf571;
      }
      else if ((int)uVar1 < iVar4) {
        dVar17 = (double)FUN_140332d90();
        iVar11 = 0x80 - (int)(dVar17 * DAT_14053b160);
      }
      else {
LAB_1400bf571:
        iVar11 = 0x80;
      }
    }
    else {
      if ((int)DAT_140e418c8 < 0) {
        if ((int)DAT_140e418c8 < iVar4) goto LAB_1400bf48a;
LAB_1400bf47d:
        iVar3 = 0x20;
        goto LAB_1400bf493;
      }
      if (iVar4 <= (int)DAT_140e418c8) goto LAB_1400bf47d;
      dVar18 = (double)FUN_140332d90((DAT_14053ac08 / (double)(iVar4 * 4)) *
                                     ((double)(int)DAT_140e418c8 - (double)-iVar4) * DAT_14053a020 *
                                     DAT_140539d28);
      iVar3 = 0x20 - (int)(dVar18 * _DAT_14053b200);
LAB_1400bf4a5:
      dVar17 = (double)FUN_140332d90((dVar14 / (double)(iVar4 * 4)) *
                                     ((double)(int)uVar1 - (double)-iVar4) * dVar24 * dVar17);
      iVar5 = 0x60 - (int)(dVar17 * _DAT_14053b1e0);
LAB_1400bf4f6:
      iVar11 = 0xc0;
      if (iVar4 != 0) goto LAB_1400bf4ff;
    }
    fVar22 = DAT_14053ae30;
    FUN_1400c2670(0,DAT_140e46ab8,1,0xe,DAT_14053ae30,iVar3,CONCAT44(uVar29,iVar3),
                  CONCAT44(uVar31,iVar5),CONCAT44(uVar33,0xff),DAT_14053b040);
    FUN_1400c2670(1,DAT_140e46abc,3,0xf,fVar22,iVar3,iVar3,iVar5,0x48,DAT_14053b060);
    uVar26 = DAT_140e45098;
    uVar28 = (undefined2)((uint)iVar3 >> 0x10);
    puVar6 = DAT_140e45d28;
    if (((int)DAT_140e418c8 % 0x28 == 5) && (DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      *(undefined4 *)(puVar6 + 1) = 0x3b;
      *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
      *(undefined4 *)(puVar6 + 2) = 5;
      *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43b40000;
      *(undefined4 *)(puVar6 + 3) = 0x443b8000;
      *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43b40000;
      *(undefined4 *)(puVar6 + 4) = 0x443b8000;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0xc000;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0;
      puVar6[7] = 0;
      *(undefined4 *)(puVar6 + 8) = 0x5a;
      *(int *)((longlong)puVar6 + 0x44) = iVar11;
      *(int *)(puVar6 + 9) = iVar11;
      *(int *)((longlong)puVar6 + 0x4c) = iVar11;
      puVar6[10] = 0x60;
      puVar6[0xb] = 0;
      if (bVar12) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    puVar6 = DAT_140e45d28;
    if ((int)DAT_140e418c8 % 0x3f == 5) {
      uVar1 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar1 >> 0x1e ^ uVar1) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar1 = uVar1 * 0x800 ^ uVar1;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar1 = (DAT_140e9fd18 >> 0xb ^ uVar1) >> 8 ^ uVar1 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar1;
      uVar13 = FUN_140134db0(DAT_140e418c8,DAT_140539f90,DAT_14053a018);
      FUN_140070d00(0x3c,DAT_140e41a8c,6,fVar22,DAT_14053af28,
                    CONCAT22(uVar28,(short)uVar1 + (short)((ulonglong)uVar1 / 0x5dc1) * -0x5dc1 +
                                    -0x6ee0),uVar13,0,0,0x96,iVar11,iVar11,iVar11,0x60,0);
      puVar6 = DAT_140e45d28;
    }
    break;
  case 5:
    iVar4 = *(int *)(&UNK_140538ad8 + lVar10 * 4);
    if (iVar4 + -600 < (int)DAT_140e418c8) {
      iVar3 = iVar4 + -0x1c2;
      iVar5 = 0xff;
      if (((iVar3 != iVar4) && (iVar5 = 0, iVar3 <= (int)DAT_140e418c8)) &&
         (iVar5 = 0xff, (int)DAT_140e418c8 < iVar4)) {
        dVar18 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)iVar3) * _DAT_14053a328
                                       * DAT_14053a020 * DAT_140539d28);
        iVar5 = (int)(dVar18 * DAT_14053a5f8);
      }
      fVar22 = DAT_14053a2e8;
      if (((iVar4 != iVar4 + 600) && (fVar22 = DAT_140539cec, iVar4 <= (int)uVar1)) &&
         (fVar22 = DAT_14053a2e8, (int)uVar1 < iVar4 + 600)) {
        dVar17 = (double)FUN_140332d90(((double)(int)uVar1 - (double)iVar4) * DAT_14053a2c0 * dVar24
                                       * dVar17);
        fVar22 = (float)(dVar17 * _DAT_14053a008) + DAT_140539cec;
      }
      fVar20 = DAT_14053ae30;
      FUN_1400c2670(0,DAT_140e46ac0,1,0xe,DAT_14053ae30,iVar5,CONCAT44(uVar29,iVar5),
                    CONCAT44(uVar31,iVar5),CONCAT44(uVar33,0xff),fVar22);
      FUN_1400c2670(1,DAT_140e46ac4,2,0xe,fVar20,iVar5,iVar5,iVar5,0xff,fVar22 * _DAT_14053a050);
      FUN_1400c2670(2,DAT_140e46ac8,3,0xe,fVar20,iVar5,iVar5,iVar5,0xff,fVar22 * _DAT_14053a470);
      FUN_1400c2670(3,DAT_140e46acc,4,0xe,fVar20,iVar5,iVar5,iVar5,0xff,fVar22 * _DAT_14053a958);
      puVar6 = DAT_140e45d28;
    }
    else {
      iVar4 = DAT_140e45d1c;
      puVar6 = DAT_140e45d28;
      if ((DAT_140e44acc == ((int)DAT_140e44acc / 0x18) * 0x18) && (DAT_140e45d1c < 0x1000)) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar4 = DAT_140e45d1c + 1;
        *puVar6 = 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar6 + 1) = 0x3d;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
        *(undefined4 *)(puVar6 + 2) = 5;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43b40000;
        *(undefined4 *)(puVar6 + 3) = 0x44200000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43b40000;
        *(undefined4 *)(puVar6 + 4) = 0x44200000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0xc000;
        puVar6[5] = 0x3fe0000000000000;
        puVar6[6] = 0;
        puVar6[7] = 0;
        *(undefined4 *)(puVar6 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar6;
        }
        DAT_140e45d1c = iVar4;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      uVar26 = DAT_140e450e0;
      puVar6 = DAT_140e45d28;
      if ((DAT_140e44acc == ((int)DAT_140e44acc / 0x13) * 0x13) && (iVar4 < 0x1000)) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        *(undefined4 *)(puVar6 + 1) = 0x3e;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
        *(undefined4 *)(puVar6 + 2) = 10;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43b40000;
        *(undefined4 *)(puVar6 + 3) = 0x44200000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43b40000;
        *(undefined4 *)(puVar6 + 4) = 0x44200000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0xc000;
        puVar6[5] = 0x3fe0000000000000;
        puVar6[6] = 0;
        puVar6[7] = 0;
        *(undefined4 *)(puVar6 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0x80;
        puVar6[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    break;
  case 6:
    fVar20 = DAT_14053ac58;
    if ((-1 < (int)DAT_140e418c8) && (fVar20 = DAT_140539da8, (int)DAT_140e418c8 < 300)) {
      dVar18 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a388 *
                                     DAT_14053a020 * DAT_140539d28);
      fVar20 = (float)(dVar18 * _DAT_14053b108) + DAT_14053ac58;
    }
    iVar3 = *(int *)(&UNK_140538ad8 + lVar10 * 4) + 300;
    if (((iVar3 <= (int)uVar1) &&
        (iVar5 = *(int *)(&UNK_140538ad8 + lVar10 * 4) + 900, fVar20 = fVar22, iVar3 != iVar5)) &&
       (fVar20 = DAT_14053ac2c, (int)uVar1 < iVar5)) {
      dVar18 = (double)FUN_140332d90(((double)(int)uVar1 - (double)(iVar3 * 2 - iVar5)) *
                                     DAT_14053a2c0 * dVar24 * dVar17);
      fVar20 = (float)(dVar18 * _DAT_14053b0d0) + DAT_14053ac2c;
    }
    uVar26 = DAT_140e468c0;
    puVar2 = DAT_140e46c88;
    if (((0x419 < (int)uVar1) && ((int)uVar1 <= iVar3)) && (iVar4 == 6)) {
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = (float)(int)(uVar1 - 0x44c);
      *puVar2 = uVar26;
      puVar2[1] = 0x14;
      puVar2[2] = 0x10;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0xff;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      uVar1 = DAT_140e418c8;
      iVar4 = DAT_1407c7798;
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
        uVar1 = DAT_140e418c8;
        iVar4 = DAT_1407c7798;
      }
    }
    DAT_140e46c88 = puVar2;
    puVar2 = DAT_140e46c88;
    if (((0x1963 < (int)uVar1) &&
        ((int)uVar1 <= *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4) + 0x78)) && (iVar4 == 6)) {
      iVar4 = *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4) + 0x3c;
      fVar22 = DAT_14053ad70;
      if (((iVar4 != 0x1964) && (fVar22 = DAT_14053b390, 0x1963 < (int)uVar1)) &&
         (fVar22 = DAT_14053ad70, (int)uVar1 < iVar4)) {
        dVar17 = (double)FUN_140332d90((DAT_14053ac08 / (double)(iVar4 * 4 + -26000)) *
                                       ((double)(int)uVar1 - _DAT_14053ab28) * dVar24 * dVar17);
        fVar22 = (float)(dVar17 * DAT_14053a620) - DAT_14053ad40;
      }
      uVar26 = DAT_140e44c84;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = fVar22;
      *puVar2 = uVar26;
      puVar2[1] = 10;
      puVar2[2] = 7;
      puVar2[3] = 0x43f00000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0xc0;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
    }
    DAT_140e46c88 = puVar2;
    fVar22 = DAT_14053ae30;
    FUN_1400c2670(0,DAT_140e46ad0,1,0xe,DAT_14053ae30,0xff,CONCAT44(uVar29,0xff),
                  CONCAT44(uVar31,0xff),CONCAT44(uVar33,0xff),fVar20 * DAT_140539d20);
    FUN_1400c2670(1,DAT_140e46ad4,2,0xf,fVar22,0x80,0x80,0xff,0x32,fVar20 * DAT_140539d48);
    FUN_1400c2670(2,DAT_140e46ad8,3,0xf,fVar22,0xc0,0xc0,0xff,0x4b,fVar20);
    FUN_1400c2670(3,DAT_140e46adc,4,0xf,fVar22,0xff,0xff,0xff,100,fVar20 * _DAT_140539e48);
    puVar6 = DAT_140e45d28;
    break;
  case 7:
    puVar6 = (undefined8 *)FUN_140135060(&local_198,DAT_140e44acc,300);
    uVar1 = DAT_140e418c8;
    dVar24 = DAT_14053a020;
    dVar17 = DAT_140539d28;
    local_178 = *puVar6;
    iVar4 = *(int *)(puVar6 + 1);
    iVar3 = ((int)DAT_140e418c8 >> 0x1f & 0xffffff01U) + 0xff;
    if ((-1 < (int)DAT_140e418c8) && ((int)DAT_140e418c8 < 300)) {
      dVar18 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a388 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar3 = (int)(dVar18 * DAT_14053a5f8);
    }
    dVar17 = (double)FUN_140332d90(((double)(int)uVar1 - 0.0) * _DAT_14053a270 * dVar24 * dVar17);
    fVar22 = DAT_14053ae30;
    DAT_140e45d24 = (float)(dVar17 * DAT_14053a3f8) + 0.0;
    uVar32 = CONCAT44(uVar33,0xff);
    uVar30 = CONCAT44(uVar31,iVar4);
    uVar13 = CONCAT44(uVar29,(int)((ulonglong)local_178 >> 0x20));
    iVar5 = (int)local_178;
    FUN_1400c2670(0,DAT_140e469d8,1,0xe,DAT_14053ae30,iVar5,uVar13,uVar30,uVar32,DAT_14053ac18);
    uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),0xff);
    uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),iVar4 / 3);
    uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),local_178._4_4_ / 3);
    FUN_1400c2670(1,DAT_140e469dc,2,0xe,fVar22,
                  iVar5 / 3 + (iVar5 >> 0x1f) +
                  (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >> 0x1f),
                  uVar13,uVar30,uVar32,DAT_14053a9e0);
    uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),0xc0);
    uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),0x80);
    uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0x80);
    FUN_1400c2670(2,DAT_140e469bc,4,0xf,fVar22,0x80,uVar13,uVar30,uVar32,DAT_14053ac38);
    uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
    uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if ((int)DAT_140e418c8 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x1e0) {
      uVar32 = CONCAT44(uVar29,0xff);
      uVar30 = CONCAT44(uVar27,iVar3);
      uVar13 = CONCAT44(uVar26,iVar3);
      FUN_1400c2670(2,DAT_140e469e0,0x14,0xe,DAT_140e45d24 + fVar22,iVar3,uVar13,uVar30,uVar32,
                    DAT_14053ac48);
      uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
    }
    iVar4 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4);
    puVar6 = DAT_140e45d28;
    if ((iVar4 + -600 <= (int)DAT_140e418c8) && ((int)DAT_140e418c8 < iVar4 + -300)) {
      uVar26 = FUN_1401348b0(DAT_140e418c8,iVar4 + -600,iVar4 + -0x1e0,iVar4 + -0x1e0,iVar4 + -300,0
                             ,CONCAT44(uVar26,0xff));
      FUN_1400c2670(3,DAT_140e469b8,0x18,0xe,fVar22,0x80,0x80,CONCAT44(uVar27,0x80),
                    CONCAT44(uVar29,uVar26),DAT_14053ac94);
      puVar6 = DAT_140e45d28;
    }
    break;
  case 8:
    puVar2 = DAT_140e46c88;
    if ((int)DAT_140e418c8 < 0x1af4) {
      iVar5 = 0xff;
      if (DAT_140e418c8 - 0xf0 < 0x78) {
        dVar14 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a4a0) * DAT_14053a4d8
                                       * DAT_14053a020 * DAT_140539d28);
        iVar5 = (int)(dVar14 * dVar16);
      }
      iVar11 = iVar3;
      if ((int)uVar1 < 0x168) {
        iVar11 = iVar5;
      }
      fVar19 = fVar20;
      if ((int)uVar1 < 0xf0) {
LAB_1400c046b:
        uVar32 = CONCAT44(uVar33,iVar11);
        uVar30 = CONCAT44(uVar31,0x80);
        uVar13 = CONCAT44(uVar29,0x80);
        FUN_1400c2670(0,DAT_140e469b8,4,0xe,fVar25,0x80,uVar13,uVar30,uVar32,DAT_14053ac94);
        uVar29 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar31 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar33 = (undefined4)((ulonglong)uVar32 >> 0x20);
        uVar1 = DAT_140e418c8;
        iVar4 = DAT_1407c7798;
      }
      else {
        if ((int)uVar1 < 0x168) {
          dVar14 = (double)FUN_140332d90();
          fVar19 = (float)(dVar14 * _DAT_14053b0d0) + fVar20;
          goto LAB_1400c046b;
        }
        fVar19 = fVar22;
        if ((int)uVar1 < 0x191) goto LAB_1400c046b;
      }
      if ((int)uVar1 < 0x1771) {
        uVar32 = CONCAT44(uVar33,0xff);
        uVar30 = CONCAT44(uVar31,0xff);
        uVar13 = CONCAT44(uVar29,0xff);
        FUN_1400c2670(1,DAT_140e469c0,1,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar19 * DAT_140539d20)
        ;
        uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),0x80);
        uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),0xff);
        uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0xff);
        FUN_1400c2670(2,DAT_140e469bc,3,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar19 * DAT_14053abf8)
        ;
        uVar29 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar31 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar33 = (undefined4)((ulonglong)uVar32 >> 0x20);
        uVar1 = DAT_140e418c8;
        iVar4 = DAT_1407c7798;
      }
      uVar26 = DAT_140e46a18;
      puVar2 = DAT_140e46c88;
      if ((uVar1 - 400 < 0x1965) && (iVar4 == 8)) {
        puVar2 = (undefined4 *)_malloc_base(0x48);
        if (puVar2 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
        bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
        puVar2[4] = (float)(int)(uVar1 - 400);
        *puVar2 = uVar26;
        puVar2[1] = 0x14;
        puVar2[2] = 0x10;
        puVar2[3] = 0x43b40000;
        *(undefined2 *)(puVar2 + 5) = 0;
        *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
        puVar2[10] = 0xff;
        puVar2[0xb] = 0xff;
        puVar2[0xc] = 0xff;
        puVar2[0xd] = 0xff;
        *(undefined8 *)(puVar2 + 0xe) = 1;
        *(undefined8 *)(puVar2 + 0x10) = 0;
        if (bVar12) {
          DAT_140e46bf0 = puVar2;
        }
        uVar1 = DAT_140e418c8;
        iVar4 = DAT_1407c7798;
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
          uVar1 = DAT_140e418c8;
          iVar4 = DAT_1407c7798;
        }
      }
    }
    DAT_140e46c88 = puVar2;
    puVar2 = DAT_140e46c88;
    if ((int)uVar1 < 6000) {
LAB_1400c0879:
      DAT_140e46c88 = puVar2;
      puVar6 = DAT_140e45d28;
      if ((int)uVar1 < 0x29cc) break;
    }
    else if ((int)uVar1 < 0x29cc) {
      iVar5 = 0xff;
      if (uVar1 - 0x1a5e < 0x96) {
        dVar14 = (double)FUN_140332d90(((double)(int)uVar1 - _DAT_14053ab38) * _DAT_14053a478 *
                                       dVar24 * dVar17);
        iVar5 = (int)(dVar14 * dVar16);
      }
      uVar26 = DAT_140e450ec;
      if ((int)uVar1 < 0x1af4) {
        iVar3 = iVar5;
      }
      puVar6 = DAT_140e45d28;
      if ((0x1a8f < (int)uVar1) && ((int)uVar1 < 0x2968)) {
        uVar8 = DAT_140e44acc & 0x8000001f;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
        }
        if ((uVar8 == 0) && (DAT_140e45d1c < 0x1000)) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x42;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar26;
          *(undefined4 *)(puVar6 + 2) = 5;
          *(undefined4 *)((longlong)puVar6 + 0x14) = 0x43b40000;
          *(undefined4 *)(puVar6 + 3) = 0x44200000;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x43b40000;
          *(undefined4 *)(puVar6 + 4) = 0x44200000;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0xc000;
          puVar6[5] = 0x4000000000000000;
          puVar6[6] = 0;
          puVar6[7] = 0;
          *(undefined4 *)(puVar6 + 8) = 100;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar12) {
            DAT_140e45d78 = puVar6;
          }
          uVar1 = DAT_140e418c8;
          iVar4 = DAT_1407c7798;
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
            uVar1 = DAT_140e418c8;
            iVar4 = DAT_1407c7798;
          }
        }
      }
      DAT_140e45d28 = puVar6;
      uVar26 = DAT_140e450e8;
      puVar2 = DAT_140e46c88;
      if ((int)uVar1 < 0x1af4) {
        puVar2 = (undefined4 *)_malloc_base(0x48);
        if (puVar2 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e46c94 = DAT_140e46c94 + 1;
        bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar2 = uVar26;
        puVar2[1] = 1;
        puVar2[2] = 8;
        puVar2[3] = 0x43b40000;
        puVar2[4] = 0x43b40000;
        *(undefined2 *)(puVar2 + 5) = 0;
        *(undefined8 *)(puVar2 + 6) = 0x3ff0147ae147ae14;
        *(undefined8 *)(puVar2 + 8) = 0x3ff0147ae147ae14;
        puVar2[10] = 0xff;
        puVar2[0xb] = 0xff;
        puVar2[0xc] = 0xff;
        puVar2[0xd] = iVar3;
        *(undefined8 *)(puVar2 + 0xe) = 1;
        *(undefined8 *)(puVar2 + 0x10) = 0;
        if (bVar12) {
          DAT_140e46bf0 = puVar2;
        }
        uVar1 = DAT_140e418c8;
        iVar4 = DAT_1407c7798;
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
          uVar1 = DAT_140e418c8;
          iVar4 = DAT_1407c7798;
        }
      }
      goto LAB_1400c0879;
    }
    dVar14 = DAT_14053aba8;
    iVar3 = *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4);
    iVar5 = 0;
    if ((0x29cb < (int)uVar1) && (iVar5 = 0xff, (int)uVar1 < 0x2c24)) {
      dVar15 = (double)FUN_140332d90(((double)(int)uVar1 - DAT_14053aba8) * DAT_14053a2c0 * dVar24 *
                                     dVar17);
      iVar5 = (int)(dVar15 * dVar16);
    }
    iVar9 = iVar3 + -0x1e0;
    iVar11 = iVar3 + -600;
    if (iVar11 != iVar9) {
      if ((int)uVar1 < iVar11) {
        if (iVar9 <= (int)uVar1) goto LAB_1400c093a;
      }
      else if ((int)uVar1 < iVar9) {
        dVar18 = (double)FUN_140332d90(((double)(int)uVar1 - (double)(iVar11 * 2 - iVar9)) * dVar18
                                       * dVar24 * dVar17);
        iVar5 = (int)(dVar18 * dVar16);
      }
      else {
LAB_1400c093a:
        iVar5 = 0;
      }
    }
    fVar19 = 0.0;
    if (0x29cb < (int)uVar1) {
      if ((int)uVar1 < 0x300c) {
        dVar18 = (double)FUN_140332d90(((double)(int)uVar1 - dVar14) * _DAT_14053a1f0 * dVar24 *
                                       dVar17);
        fVar19 = (float)dVar18 + 0.0;
      }
      else {
        fVar19 = fVar22;
        if (0x4393 < (int)uVar1) {
          uVar13 = CONCAT44(uVar29,DAT_14053ac34);
          fVar19 = (float)FUN_140134b10(uVar1,0x4394,0x45ec,iVar9,iVar3 + -300,fVar22,uVar13);
          uVar29 = (undefined4)((ulonglong)uVar13 >> 0x20);
        }
      }
    }
    iVar3 = iVar3 + -300;
    if (iVar3 <= (int)uVar1) {
      iVar5 = 0xff;
      if (((iVar3 != *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4)) &&
          (iVar5 = 0, iVar3 <= (int)uVar1)) &&
         (iVar5 = 0xff, (int)uVar1 < *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4))) {
        dVar18 = (double)FUN_140332d90(((double)(int)uVar1 - (double)iVar3) * DAT_14053a388 * dVar24
                                       * dVar17);
        iVar5 = (int)(dVar18 * dVar16);
      }
    }
    fVar23 = fVar19;
    if (*(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4) <= (int)uVar1) {
      puVar6 = DAT_140e45d80;
      if (0 < DAT_140e44e6c) {
        for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)puVar6[0xc]) {
          if (*(int *)((longlong)puVar6 + 4) == DAT_140e44308) {
            local_168 = *puVar6;
            lStack_160 = puVar6[1];
            auStack_158 = *(undefined1 (*) [16])(puVar6 + 2);
          }
        }
      }
      fVar23 = fVar22;
      if ((DAT_140e418cc != 0) && (uVar8 = auStack_158._4_4_, 10 < (int)uVar8)) {
        if (uVar8 == 0xb) {
          iVar4 = (int)((ulonglong)lStack_160 >> 0x20);
          if ((-1 < lStack_160) && (fVar23 = fVar20, iVar4 < 300)) {
            dVar18 = (double)FUN_140332d90(((double)iVar4 - 0.0) * DAT_14053a388 * dVar24 * dVar17);
            fVar23 = (float)(dVar18 * DAT_14053a1b8) + fVar22;
          }
        }
        else {
          fVar23 = fVar19;
          if (0xb < uVar8) {
            fVar23 = fVar20;
          }
        }
      }
    }
    if (uVar1 == 0x29cc) {
      _DAT_140e46a38 = 0;
      _DAT_140e46a28 = 0;
      _DAT_140e46a30 = 0;
    }
    uVar32 = CONCAT44(uVar33,iVar5);
    uVar30 = CONCAT44(uVar31,0xff);
    uVar13 = CONCAT44(uVar29,0xff);
    uVar1 = 0;
    FUN_1400c2670(0,DAT_140e469e4,1,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * _DAT_140539cf4);
    dVar16 = DAT_140539f28;
    dVar18 = DAT_140539ee0;
    if ((int)DAT_140e418c8 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x1e0) {
      uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),(int)((double)iVar5 * DAT_140539f10));
      uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),0xff);
      uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0xff);
      FUN_1400c2670(1,DAT_140e469e8,2,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * DAT_140539d20);
      fVar22 = DAT_140539d48;
      uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      dVar14 = (double)iVar5 * dVar16;
      if (DAT_140e441b4 == 0) {
        uVar32 = CONCAT44(uVar29,(int)dVar14);
        uVar30 = CONCAT44(uVar27,0xff);
        uVar13 = CONCAT44(uVar26,0xff);
        FUN_1400c2670(2,DAT_140e469ec,3,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * DAT_140539d48)
        ;
        uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      }
      iVar4 = (int)dVar14;
      if (DAT_140e441b4 == 1) {
        uVar32 = CONCAT44(uVar29,iVar4);
        uVar30 = CONCAT44(uVar27,0xff);
        uVar13 = CONCAT44(uVar26,0xff);
        FUN_1400c2670(2,DAT_140e469f0,3,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * fVar22);
        uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      }
      if (DAT_140e441b4 == 2) {
        uVar32 = CONCAT44(uVar29,iVar4);
        uVar30 = CONCAT44(uVar27,0xff);
        uVar13 = CONCAT44(uVar26,0xff);
        FUN_1400c2670(2,DAT_140e46a00,3,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * fVar22);
        uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      }
      if (DAT_140e441b4 == 3) {
        uVar32 = CONCAT44(uVar29,iVar4);
        uVar30 = CONCAT44(uVar27,0xff);
        uVar13 = CONCAT44(uVar26,0xff);
        FUN_1400c2670(2,DAT_140e46a04,3,0xe,fVar25,0xff,uVar13,uVar30,uVar32,fVar23 * fVar22);
        uVar26 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar27 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar29 = (undefined4)((ulonglong)uVar32 >> 0x20);
      }
      uVar1 = 0;
      FUN_1400c2670(3,DAT_140e469b4,4,0xe,fVar25,0x40,CONCAT44(uVar26,0xff),CONCAT44(uVar27,0xc0),
                    CONCAT44(uVar29,(int)((double)iVar5 * dVar18)),fVar23 * DAT_140539e78);
    }
    uVar26 = DAT_140e46a3c;
    puVar2 = DAT_140e46c88;
    if (((0x2a2f < (int)DAT_140e418c8) &&
        ((int)DAT_140e418c8 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) &&
       (DAT_1407c7798 == 8)) {
      iVar4 = DAT_140e418c8 - 0x2a30;
      puVar2 = (undefined4 *)_malloc_base(0x48);
      if (puVar2 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar2[4] = (float)iVar4;
      *puVar2 = uVar26;
      puVar2[1] = 0x14;
      puVar2[2] = 0x10;
      puVar2[3] = 0x43b40000;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0xff;
      puVar2[0xc] = 0xff;
      puVar2[0xd] = 0xff;
      *(undefined8 *)(puVar2 + 0xe) = 1;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      if (bVar12) {
        DAT_140e46bf0 = puVar2;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
      }
    }
    DAT_140e46c88 = puVar2;
    uVar13 = DAT_140539f40;
    iVar11 = 0;
    uVar26 = (undefined4)DAT_140539f40;
    uVar27 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    iVar4 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4);
    iVar3 = iVar4 + -300;
    if (iVar3 <= (int)DAT_140e418c8) {
      if (iVar3 == iVar4) {
LAB_1400c0ee2:
        dVar17 = (double)CONCAT44(uVar27,uVar26);
      }
      else {
        if ((int)DAT_140e418c8 < iVar3) {
          uVar26 = 0;
          uVar27 = 0;
          goto LAB_1400c0ee2;
        }
        if (iVar4 <= (int)DAT_140e418c8) goto LAB_1400c0ee2;
        dVar17 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)iVar3) * DAT_14053a388
                                       * dVar24 * dVar17);
        dVar17 = dVar17 + 0.0;
      }
      dVar14 = dVar17 * DAT_14053a578;
      dVar24 = dVar17 * DAT_14053a5f8;
      dVar17 = dVar17 * 0.0;
      FUN_1400c2670(3,DAT_140e469f4,2,0xe,fVar25,(int)(dVar17 * dVar18),(int)(dVar24 * dVar18),
                    (int)(dVar14 * dVar18),0xff,fVar23 * DAT_140539d20);
      FUN_1400c2670(2,DAT_140e469f8,3,0xe,fVar25,(int)(dVar17 * DAT_140539f08),
                    (int)(dVar24 * DAT_140539f08),(int)(dVar14 * DAT_140539f08),0xff,
                    fVar23 * DAT_140539d58);
      uVar1 = (uint)(dVar17 * dVar16);
      FUN_1400c2670(1,DAT_140e469fc,4,0xe,fVar25,uVar1,(int)(dVar24 * dVar16),(int)(dVar14 * dVar16)
                    ,0xff,fVar23 * _DAT_140539df8);
    }
    fVar19 = DAT_14053af14;
    fVar20 = DAT_14053ad80;
    fVar22 = DAT_14053ad40;
    uVar30 = DAT_140539fc8;
    iVar5 = iVar5 / 10;
    do {
      uVar26 = CONCAT22((short)(uVar1 >> 0x10),0x4000);
      fVar23 = (float)((int)DAT_140e44acc % 0x78) + (float)iVar11 * fVar22;
      fVar21 = (float)((int)DAT_140e44acc % 0xa0) + (float)iVar11 * fVar20;
      FUN_1400c8410(DAT_140e45074,6,7,fVar23,fVar25,uVar26,uVar30,uVar13,0x40,0xff,0xff,iVar5,1,0);
      uVar1 = CONCAT22((short)((uint)uVar26 >> 0x10),0x4000);
      FUN_1400c8410(DAT_140e45074,6,7,fVar19 - fVar23,fVar25,uVar1,uVar30,uVar13,0x40,0xff,0xff,
                    iVar5,1,0);
      uVar1 = uVar1 & 0xffff0000;
      FUN_1400c8410(DAT_140e45074,6,7,fVar25,fVar21,uVar1,uVar30,uVar13,0x40,0xff,0xff,iVar5,1,0);
      uVar1 = uVar1 & 0xffff0000;
      FUN_1400c8410(DAT_140e45074,6,7,fVar25,fVar19 - fVar21,uVar1,uVar30,uVar13,0x40,0xff,0xff,
                    iVar5,1,0);
      iVar11 = iVar11 + 1;
      puVar6 = DAT_140e45d28;
    } while (iVar11 < 7);
    break;
  case 9:
    iVar9 = 0x40;
    uVar8 = 0xc0;
    iVar11 = 0x40;
    local_res8 = 0x40;
    dVar16 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a270 *
                                   DAT_14053a020 * DAT_140539d28);
    fVar20 = DAT_14053ae30;
    fVar22 = DAT_14053ac2c;
    dVar18 = DAT_14053a5f8;
    iVar5 = *(int *)(&UNK_140538ad8 + lVar10 * 4);
    iVar3 = iVar5 + -0x1e0;
    DAT_140e45d24 = (float)(dVar16 * _DAT_14053b178) + 0.0;
    if ((int)uVar1 < iVar3) {
      iVar4 = iVar5 + -600;
      local_168 = _DAT_14053b8d0;
      lStack_160 = _UNK_14053b8d8;
      auStack_158._8_8_ = _UNK_14053b8b8;
      auStack_158._0_8_ = _DAT_14053b8b0;
      local_e0 = iVar5;
      local_res10 = 0;
      local_148 = _DAT_14053b8a0;
      uStack_140 = _UNK_14053b8a8;
      local_138 = _DAT_14053b840;
      uStack_130 = _UNK_14053b848;
      if (299 < (int)uVar1) {
        local_res10 = 0xff;
      }
      uStack_128 = _DAT_14053b830;
      uStack_120 = _UNK_14053b838;
      local_f8 = _DAT_14053ba00;
      local_118 = 0x40;
      local_e8 = 0x2e54;
      local_e4 = 0x364c;
      if ((299 < (int)uVar1) && ((int)uVar1 < 0x5dc)) {
        dVar16 = (double)FUN_140332d90(((double)(int)uVar1 - DAT_14053a650) * _DAT_14053a230 *
                                       dVar24 * dVar17);
        local_res10 = (int)(dVar16 * dVar18);
      }
      if (iVar4 != iVar3) {
        if ((int)uVar1 < iVar4) {
          if (iVar3 <= (int)uVar1) goto LAB_1400c1479;
        }
        else if ((int)uVar1 < iVar3) {
          dVar16 = (double)FUN_140332d90(((double)(int)uVar1 - (double)(iVar4 * 2 - iVar3)) *
                                         DAT_14053a4d8 * dVar24 * dVar17);
          local_res10 = (int)(dVar16 * dVar18);
        }
        else {
LAB_1400c1479:
          local_res10 = 0;
        }
      }
      puVar6 = (undefined8 *)(auStack_158 + 8);
      piVar7 = (int *)(local_f8 + 8);
      local_res18 = 2;
      do {
        iVar3 = piVar7[-2];
        iVar4 = iVar3 + 0xb4;
        if ((int)uVar1 < iVar3) {
          if (iVar4 <= (int)uVar1) goto LAB_1400c156c;
        }
        else {
          if ((int)uVar1 < iVar4) {
            local_188 = puVar6[-3];
            dVar18 = (double)(int)(uVar1 - iVar3);
            iVar11 = (int)(DAT_14053a3b0 -
                          ((double)(0x40 - *(int *)(puVar6 + -2)) / DAT_14053a548) * dVar18);
            uVar8 = (int)(DAT_14053a578 - ((double)(0xc0 - (int)local_188) / DAT_14053a548) * dVar18
                         );
            iVar9 = (int)(DAT_14053a3b0 -
                         ((double)(0x40 - (int)((ulonglong)local_188 >> 0x20)) / DAT_14053a548) *
                         dVar18);
          }
          else {
LAB_1400c156c:
            if (((int)uVar1 < piVar7[-1] + -0xb4) && (DAT_140e418cc == 1)) {
              uVar13 = puVar6[-3];
              iVar11 = *(int *)(puVar6 + -2);
              local_198._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
              local_198._0_4_ = (uint)uVar13;
              uVar8 = (uint)local_198;
              iVar9 = local_198._4_4_;
              local_198 = uVar13;
            }
          }
          if (((iVar4 <= (int)uVar1) && (DAT_140e46a08 <= (int)uVar1)) &&
             ((int)uVar1 < DAT_140e46a08 + 0xb4)) {
            local_178 = puVar6[-3];
            dVar18 = (double)(int)(uVar1 - DAT_140e46a08);
            iVar4 = (int)((ulonglong)local_178 >> 0x20);
            uVar8 = (uint)((double)(int)local_178 -
                          ((double)((int)local_178 + -0xc0) / DAT_14053a548) * dVar18);
            iVar9 = (int)((double)iVar4 - ((double)(iVar4 + -0x40) / DAT_14053a548) * dVar18);
            iVar11 = (int)((double)*(int *)(puVar6 + -2) -
                          ((double)(*(int *)(puVar6 + -2) + -0x40) / DAT_14053a548) * dVar18);
          }
        }
        iVar3 = piVar7[-1];
        iVar4 = iVar3 + 0xb4;
        if ((int)uVar1 < iVar3) {
          if (iVar4 <= (int)uVar1) goto LAB_1400c16f3;
        }
        else {
          if ((int)uVar1 < iVar4) {
            local_188 = *(undefined8 *)((longlong)puVar6 + -0xc);
            dVar18 = (double)(int)(uVar1 - iVar3);
            iVar11 = (int)(DAT_14053a3b0 -
                          ((double)(0x40 - *(int *)((longlong)puVar6 + -4)) / DAT_14053a548) *
                          dVar18);
            uVar8 = (int)(DAT_14053a578 - ((double)(0xc0 - (int)local_188) / DAT_14053a548) * dVar18
                         );
            iVar9 = (int)(DAT_14053a3b0 -
                         ((double)(0x40 - (int)((ulonglong)local_188 >> 0x20)) / DAT_14053a548) *
                         dVar18);
          }
          else {
LAB_1400c16f3:
            if (((int)uVar1 < *piVar7 + -0xb4) && (DAT_140e418cc == 1)) {
              uVar13 = *(undefined8 *)((longlong)puVar6 + -0xc);
              iVar11 = *(int *)((longlong)puVar6 + -4);
              local_198._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
              local_198._0_4_ = (uint)uVar13;
              uVar8 = (uint)local_198;
              iVar9 = local_198._4_4_;
              local_198 = uVar13;
            }
          }
          if (((iVar4 <= (int)uVar1) && (DAT_140e46a08 <= (int)uVar1)) &&
             ((int)uVar1 < DAT_140e46a08 + 0xb4)) {
            local_178 = *(undefined8 *)((longlong)puVar6 + -0xc);
            dVar18 = (double)(int)(uVar1 - DAT_140e46a08);
            iVar4 = (int)((ulonglong)local_178 >> 0x20);
            uVar8 = (uint)((double)(int)local_178 -
                          ((double)((int)local_178 + -0xc0) / DAT_14053a548) * dVar18);
            iVar9 = (int)((double)iVar4 - ((double)(iVar4 + -0x40) / DAT_14053a548) * dVar18);
            iVar11 = (int)((double)*(int *)((longlong)puVar6 + -4) -
                          ((double)(*(int *)((longlong)puVar6 + -4) + -0x40) / DAT_14053a548) *
                          dVar18);
          }
        }
        iVar4 = *piVar7;
        iVar3 = iVar4 + 0xb4;
        if ((int)uVar1 < iVar4) {
          if (iVar3 <= (int)uVar1) goto LAB_1400c1877;
        }
        else {
          if ((int)uVar1 < iVar3) {
            local_188 = *puVar6;
            dVar18 = (double)(int)(uVar1 - iVar4);
            iVar11 = (int)(DAT_14053a3b0 -
                          ((double)(0x40 - *(int *)(puVar6 + 1)) / DAT_14053a548) * dVar18);
            uVar8 = (int)(DAT_14053a578 - ((double)(0xc0 - (int)local_188) / DAT_14053a548) * dVar18
                         );
            iVar9 = (int)(DAT_14053a3b0 -
                         ((double)(0x40 - (int)((ulonglong)local_188 >> 0x20)) / DAT_14053a548) *
                         dVar18);
          }
          else {
LAB_1400c1877:
            if (((int)uVar1 < piVar7[1] + -0xb4) && (DAT_140e418cc == 1)) {
              uVar13 = *puVar6;
              iVar11 = *(int *)(puVar6 + 1);
              local_198._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
              local_198._0_4_ = (uint)uVar13;
              uVar8 = (uint)local_198;
              iVar9 = local_198._4_4_;
              local_198 = uVar13;
            }
          }
          if (((iVar3 <= (int)uVar1) && (DAT_140e46a08 <= (int)uVar1)) &&
             ((int)uVar1 < DAT_140e46a08 + 0xb4)) {
            local_178 = *puVar6;
            dVar18 = (double)(int)(uVar1 - DAT_140e46a08);
            iVar4 = (int)((ulonglong)local_178 >> 0x20);
            uVar8 = (uint)((double)(int)local_178 -
                          ((double)((int)local_178 + -0xc0) / DAT_14053a548) * dVar18);
            iVar9 = (int)((double)iVar4 - ((double)(iVar4 + -0x40) / DAT_14053a548) * dVar18);
            iVar11 = (int)((double)*(int *)(puVar6 + 1) -
                          ((double)(*(int *)(puVar6 + 1) + -0x40) / DAT_14053a548) * dVar18);
          }
        }
        piVar7 = piVar7 + 3;
        puVar6 = (undefined8 *)((longlong)puVar6 + 0x24);
        local_res18 = local_res18 + -1;
      } while (local_res18 != 0);
      local_res8 = iVar11;
      if (0x3ee2 < (int)uVar1) {
        iVar9 = 0x40;
        local_res8 = 0x40;
        uVar8 = 0xc0;
      }
      uVar32 = CONCAT44(uVar33,local_res10);
      uVar30 = CONCAT44(uVar31,local_res8);
      uVar13 = CONCAT44(uVar29,iVar9);
      FUN_1400c2670(0,DAT_140e45178,1,0xe,fVar20,uVar8,uVar13,uVar30,uVar32,DAT_14053a2e8);
      uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),local_res10);
      uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),local_res8);
      uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),iVar9);
      FUN_1400c2670(1,DAT_140e4517c,2,0xe,fVar20,uVar8,uVar13,uVar30,uVar32,DAT_14053abf8);
      uVar32 = CONCAT44((int)((ulonglong)uVar32 >> 0x20),local_res10);
      uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),local_res8);
      uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),iVar9);
      in_stack_fffffffffffffe10 = uVar8;
      FUN_1400c2670(2,DAT_140e45180,4,0xe,fVar20,uVar8,uVar13,uVar30,uVar32,fVar22);
      uVar33 = (undefined4)((ulonglong)uVar32 >> 0x20);
      uVar29 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar31 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar1 = DAT_140e418c8;
      iVar4 = DAT_1407c7798;
    }
    dVar18 = DAT_14053a5f8;
    uVar13 = DAT_140539f40;
    uVar26 = (undefined4)DAT_140539f40;
    uVar27 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    iVar3 = *(int *)(&UNK_140538ad8 + (longlong)iVar4 * 4);
    iVar4 = iVar3 + -0x1e0;
    if (iVar4 <= (int)uVar1) {
      iVar5 = iVar3 + -300;
      if (iVar5 == iVar3) {
LAB_1400c1aa5:
        dVar16 = (double)CONCAT44(uVar27,uVar26);
        if (iVar3 <= (int)uVar1) goto LAB_1400c1aad;
LAB_1400c1b4e:
        fVar25 = 0.0;
        if (((iVar4 != iVar3) && (fVar25 = fVar22, iVar4 <= (int)uVar1)) &&
           (fVar25 = 0.0, (int)uVar1 < iVar3)) {
          dVar17 = (double)FUN_140332d90(((double)(int)uVar1 - (double)iVar4) * _DAT_14053a310 *
                                         dVar24 * dVar17);
          fVar25 = (float)(dVar17 * DAT_14053b0d8) + fVar22;
        }
      }
      else {
        if ((int)uVar1 < iVar5) {
          uVar26 = 0;
          uVar27 = 0;
          goto LAB_1400c1aa5;
        }
        if ((int)uVar1 < iVar3) {
          dVar16 = (double)FUN_140332d90(((double)(int)uVar1 - (double)iVar5) * DAT_14053a388 *
                                         dVar24 * dVar17);
          dVar16 = dVar16 + 0.0;
          goto LAB_1400c1b4e;
        }
LAB_1400c1aad:
        dVar16 = (double)CONCAT44(uVar27,uVar26);
        puVar6 = DAT_140e45d80;
        if (0 < DAT_140e44e6c) {
          for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)puVar6[0xc]) {
            if (*(int *)((longlong)puVar6 + 4) == DAT_140e44308) {
              local_168 = *puVar6;
              lStack_160 = puVar6[1];
              auStack_158 = *(undefined1 (*) [16])(puVar6 + 2);
            }
          }
        }
        if ((DAT_140e418cc == 0) || (iVar4 = auStack_158._4_4_, iVar4 < 0xb)) {
LAB_1400c1b7e:
          fVar25 = 0.0;
          dVar16 = (double)CONCAT44(uVar27,uVar26);
        }
        else {
          fVar25 = DAT_14053ac48;
          if ((iVar4 == 0xb) || (iVar4 == 0x6f)) {
            iVar4 = (int)((ulonglong)lStack_160 >> 0x20);
            if (lStack_160 < 0) goto LAB_1400c1b7e;
            dVar16 = (double)CONCAT44(uVar27,uVar26);
            if (iVar4 < 300) {
              dVar17 = (double)FUN_140332d90(((double)iVar4 - 0.0) * DAT_14053a388 * dVar24 * dVar17
                                            );
              fVar25 = (float)(dVar17 * DAT_14053a248) + 0.0;
              dVar16 = (double)CONCAT44(uVar27,uVar26);
            }
          }
        }
      }
      FUN_1400c2670(0,DAT_140e45178,1,0xe,fVar20,uVar8,CONCAT44(uVar29,iVar9),
                    CONCAT44(uVar31,local_res8),CONCAT44(uVar33,(int)(dVar16 * dVar18)),
                    fVar25 * _DAT_140539cf4);
      dVar17 = (double)local_res8 * dVar16;
      dVar24 = (double)iVar9 * dVar16;
      dVar16 = (double)(int)uVar8 * dVar16;
      FUN_1400c2670(1,DAT_140e469f4,2,0xe,fVar20,(int)(dVar16 * DAT_140539ee0),
                    (int)(dVar24 * DAT_140539ee0),(int)(dVar17 * DAT_140539ee0),0xff,
                    fVar25 * DAT_140539d20);
      FUN_1400c2670(2,DAT_140e469f8,3,0xe,fVar20,(int)(dVar16 * DAT_140539f08),
                    (int)(dVar24 * DAT_140539f08),(int)(dVar17 * DAT_140539f08),0xff,
                    fVar25 * DAT_140539d58);
      in_stack_fffffffffffffe10 = (uint)(dVar16 * DAT_140539f28);
      FUN_1400c2670(3,DAT_140e469fc,4,0xe,fVar20,in_stack_fffffffffffffe10,
                    (int)(dVar24 * DAT_140539f28),(int)(dVar17 * DAT_140539f28),0xff,
                    fVar25 * _DAT_140539df8);
    }
    fVar19 = DAT_14053af14;
    fVar25 = DAT_14053adb4;
    fVar22 = DAT_14053ad70;
    uVar30 = DAT_140539fc8;
    iVar4 = 0;
    do {
      uVar26 = CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),0x4000);
      iVar3 = DAT_140e44acc * 0xf;
      fVar23 = (float)((int)(DAT_140e44acc * 2) % 0x96) + (float)iVar4 * fVar22;
      FUN_1400c8410(DAT_140e45074,5,8,fVar23,fVar20,uVar26,uVar30,uVar13,uVar8,iVar9,local_res8,0x30
                    ,1,0);
      in_stack_fffffffffffffe10 = CONCAT22((short)((uint)uVar26 >> 0x10),0x4000);
      FUN_1400c8410(DAT_140e45074,5,8,fVar19 - fVar23,fVar20,in_stack_fffffffffffffe10,uVar30,uVar13
                    ,uVar8,iVar9,local_res8,0x30,1,0);
      in_stack_fffffffffffffe10 = in_stack_fffffffffffffe10 & 0xffff0000;
      FUN_1400c8410(DAT_140e45074,5,8,fVar20,(float)(iVar3 % 200) + (float)iVar4 * fVar25,
                    in_stack_fffffffffffffe10,uVar30,uVar13,uVar8,iVar9,local_res8,0x30,1,0);
      iVar4 = iVar4 + 1;
      puVar6 = DAT_140e45d28;
    } while (iVar4 < 7);
    break;
  case 10:
    fVar22 = DAT_14053ac2c;
    if ((-1 < (int)DAT_140e418c8) && (fVar22 = DAT_140539fc0, (int)DAT_140e418c8 < 0x1e0)) {
      dVar17 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a310 *
                                     DAT_14053a020 * DAT_140539d28);
      fVar22 = (float)(dVar17 * DAT_14053b0c8) + DAT_14053ac2c;
    }
    fVar20 = DAT_14053ae30;
    FUN_1400c2670(0,DAT_140e45184,1,0xe,DAT_14053ae30,0xff,0xff,0xff,0xff,fVar22 * _DAT_140539d00);
    FUN_1400c2670(1,DAT_140e45188,1,0xe,fVar20,0xff,0xff,0xff,0xff,fVar22);
    FUN_1400c2670(2,DAT_140e4518c,3,0xe,fVar20,0xff,0xff,0xff,0xff,DAT_14053ac48);
    puVar6 = DAT_140e45d28;
  }
  DAT_140e45d28 = puVar6;
  uVar26 = DAT_140e41ab8;
  puVar2 = DAT_140e46c88;
  if (DAT_140e468fc == 1) {
    puVar2 = (undefined4 *)_malloc_base(0x48);
    if (puVar2 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce8 = _DAT_140e46ce8 + 1;
    bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar2 = uVar26;
    *(undefined8 *)(puVar2 + 1) = 0x16;
    *(undefined8 *)(puVar2 + 3) = 0;
    *(undefined2 *)(puVar2 + 5) = 0;
    *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar2 + 10) = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0x40;
    *(undefined8 *)(puVar2 + 0xe) = 1;
    *(undefined8 *)(puVar2 + 0x10) = 0;
    if (bVar12) {
      DAT_140e46bf0 = puVar2;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar2;
    }
  }
  DAT_140e46c88 = puVar2;
  return;
}


