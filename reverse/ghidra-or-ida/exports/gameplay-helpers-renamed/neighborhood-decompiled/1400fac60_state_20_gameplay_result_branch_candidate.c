// Function: state_20_gameplay_result_branch_candidate @ 1400fac60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_20_gameplay_result_branch_candidate(void)

{
  float fVar1;
  bool bVar2;
  ulonglong uVar3;
  float fVar4;
  double dVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  longlong lVar13;
  int iVar14;
  float *pfVar15;
  ulonglong uVar16;
  int iVar17;
  uint uVar18;
  short sVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  double dVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined1 auVar35 [16];
  undefined8 local_108;
  undefined8 uStack_100;
  undefined1 local_f8 [16];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  
  uVar18 = DAT_140e418c8;
  dVar25 = DAT_14053a628;
  dVar5 = DAT_14053a020;
  dVar28 = DAT_140539d28;
  dVar24 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a628 * DAT_14053a020
                                 * DAT_140539d28);
  iVar14 = 0;
  bVar2 = false;
  iVar11 = DAT_140e445c0 * 10;
  iVar17 = (int)(dVar24 * DAT_14053a5f8);
  if (DAT_140e41928 == 0) {
    bVar2 = DAT_1407c7798 - 8U < 2;
    if (DAT_140e467e8 != 0) {
      bVar22 = DAT_1407c7798 == DAT_140e467e8;
LAB_1400fada6:
      if (bVar22) {
LAB_1400fada8:
        bVar2 = true;
      }
    }
  }
  else if ((DAT_140e41928 == 1) && (-1 < DAT_140e41abc)) {
    if (((DAT_140e44e68 == 0) && (DAT_1407c7798 == 8)) || (DAT_1407c7798 == 9)) {
      bVar2 = true;
    }
    if (DAT_140e467e8 != 0) {
      if (DAT_140e467e8 == DAT_1407c7798) goto LAB_1400fada8;
      if (DAT_140e467e8 == DAT_1407c7798 + 1) {
        bVar22 = DAT_140e41abc == 0;
        goto LAB_1400fada6;
      }
    }
  }
  lVar13 = DAT_140e45d78;
  if (uVar18 == 1) {
    while (lVar13 != 0) {
      lVar13 = *(longlong *)(lVar13 + 0x58);
      FUN_140323ce8();
    }
    DAT_140e45d78 = 0;
    DAT_140e45d28 = 0;
    DAT_140e45d1c = 0;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45158);
    FUN_14018a340(DAT_140e45158,1,1);
    uVar18 = DAT_140e418c8;
  }
  if (0x3b < (int)uVar18) {
    iVar17 = 0xff;
  }
  if (((DAT_140e45fac == 0) && (0x167 < (int)uVar18)) && (DAT_140e467c8 == 1)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
  }
  uVar33 = DAT_140e47390;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e74 = _DAT_140e46e74 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar7 = uVar33;
  *(undefined8 *)(puVar7 + 1) = 0x79;
  *(undefined8 *)(puVar7 + 3) = 0;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = iVar17;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar7;
  }
  fVar30 = DAT_14053b00c;
  fVar23 = DAT_14053af14;
  fVar1 = DAT_14053ad80;
  fVar4 = DAT_14053ad40;
  dVar24 = DAT_14053a2a8;
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar7;
    fVar30 = DAT_14053b00c;
    fVar23 = DAT_14053af14;
    fVar1 = DAT_14053ad80;
    fVar4 = DAT_14053ad40;
    dVar24 = DAT_14053a2a8;
  }
  do {
    DAT_140e46c88 = puVar7;
    uVar18 = DAT_140e418c8;
    iVar17 = ((int)DAT_140e418c8 >> 0x1f & 0xffffffe8U) + 0x18;
    if ((-1 < (int)DAT_140e418c8) && ((int)DAT_140e418c8 < 0x3c)) {
      dVar25 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar25 * dVar5 * dVar28);
      iVar17 = (int)(dVar25 * dVar24);
    }
    uVar33 = DAT_140e45074;
    fVar29 = (float)((int)uVar18 % 0x78) + (float)iVar14 * fVar4;
    fVar31 = (float)((int)uVar18 % 0xa0) + (float)iVar14 * fVar1;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(undefined8 *)(puVar7 + 6) = 0x4008000000000000;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    puVar7[3] = fVar29;
    *puVar7 = uVar33;
    puVar7[1] = 0x79;
    puVar7[2] = 1;
    puVar7[4] = 0x43b40000;
    *(undefined2 *)(puVar7 + 5) = 0x4000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar17;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    _DAT_140e46e74 = _DAT_140e46e74 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar33 = DAT_140e45074;
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar33;
    puVar7[1] = 0x79;
    puVar7[2] = 1;
    puVar7[4] = 0x43b40000;
    *(undefined2 *)(puVar7 + 5) = 0x4000;
    *(undefined8 *)(puVar7 + 6) = 0x4008000000000000;
    puVar7[3] = fVar30 - fVar29;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar17;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46e74 = _DAT_140e46e74 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar33 = DAT_140e45074;
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[4] = fVar31;
    *(undefined8 *)(puVar7 + 6) = 0x4008000000000000;
    *puVar7 = uVar33;
    puVar7[1] = 0x79;
    puVar7[2] = 1;
    puVar7[3] = 0x44200000;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar17;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46e74 = _DAT_140e46e74 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar33 = DAT_140e45074;
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar33;
    uVar16 = 0;
    iVar10 = 0;
    puVar7[1] = 0x79;
    puVar7[2] = 1;
    puVar7[3] = 0x44200000;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x4008000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[4] = fVar23 - fVar31;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar17;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46e74 = _DAT_140e46e74 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar18 = DAT_140e451bc;
    dVar26 = DAT_14053a1e8;
    dVar32 = DAT_140539ef8;
    iVar14 = iVar14 + 1;
    dVar25 = DAT_14053a628;
  } while (iVar14 < 0xc);
  DAT_140e46c88 = puVar7;
  if ((int)DAT_140e418c8 < 0x5a) {
    dVar24 = (double)FUN_140134db0(DAT_140e451bc);
    uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
    dVar25 = dVar24 * dVar26;
    auVar35._8_4_ = SUB84(dVar24,0);
    auVar35._0_8_ = dVar24;
    auVar35._12_4_ = (int)((ulonglong)dVar24 >> 0x20);
    DAT_140e9fd10 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar18 = uVar18 ^ uVar18 * 0x800;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar20 = DAT_140e9fd18 >> 0xb;
    DAT_140e9fd1c = (uVar18 ^ uVar20) >> 8 ^ uVar18 ^ DAT_140e9fd18;
    uVar12 = 3;
    sVar19 = (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x7d1) * -0x7d1 + -0x3830;
    fVar23 = DAT_14053af48;
LAB_1400fb5ca:
    FUN_140070d00(uVar12,DAT_140e41a40,0x7a,uVar20,fVar23,sVar19,dVar25,auVar35,0,0xff,0xff,0xff,
                  0x80,0);
  }
  else {
    uVar21 = DAT_140e418c8 & 0x80000007;
    if ((int)uVar21 < 0) {
      uVar21 = (uVar21 - 1 | 0xfffffff8) + 1;
    }
    if (uVar21 == 0) {
      dVar24 = (double)FUN_140134db0(DAT_140e451bc - 0x29a,DAT_140539f00,_DAT_14053bb20);
      uVar21 = (uVar18 + 6 >> 0x1e ^ uVar18 + 6) * 0x6c078965 + 1;
      uVar9 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
      uVar21 = uVar21 * 0x800 ^ uVar21;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
      uVar20 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar18 = uVar20 * 0x800 ^ uVar20;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ DAT_140e9fd18 ^ uVar18;
      dVar25 = dVar24 * DAT_14053a0b0;
      fVar23 = (float)(((uVar9 >> 0xb ^ uVar21) >> 8 ^ uVar21 ^ uVar9) % 0x1a5 + 400);
      auVar35._8_4_ = SUB84(dVar24,0);
      auVar35._0_8_ = dVar24;
      auVar35._12_4_ = (int)((ulonglong)dVar24 >> 0x20);
      sVar19 = -0x4000;
      uVar12 = 0;
      goto LAB_1400fb5ca;
    }
  }
  uVar18 = DAT_140e418c8;
  dVar24 = DAT_14053a578;
  dVar25 = DAT_14053a4a0;
  if ((int)DAT_140e418c8 < 0x78) {
    if ((9 < (int)DAT_140e418c8) && (iVar10 = 0xc0, (int)DAT_140e418c8 < 0x28)) {
      dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - dVar26) * DAT_14053a798 * dVar5 *
                                     dVar28);
      iVar10 = (int)(dVar26 * dVar24);
    }
    if (uVar18 - 0x46 < 0x1e) {
      dVar26 = (double)FUN_140332d90(((double)(int)uVar18 - DAT_14053a340) * DAT_14053a798 * dVar5 *
                                     dVar28);
      iVar10 = (int)(dVar26 * dVar24);
    }
    uVar33 = *(undefined4 *)(&DAT_140e44264 + (longlong)iVar11 * 4);
    iVar14 = 0;
    if ((int)uVar18 < 100) {
      iVar14 = iVar10;
    }
    fVar23 = (float)(int)uVar18 * DAT_14053ac18;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e7c = _DAT_140e46e7c + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar7 = uVar33;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[3] = fVar30 - fVar23;
    puVar7[1] = 0x7b;
    puVar7[2] = 1;
    puVar7[4] = 0x43b40000;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x4003333333333333;
    *(undefined8 *)(puVar7 + 8) = 0x4003333333333333;
    puVar7[0xd] = iVar14;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    if (0x77 < (int)DAT_140e418c8) goto LAB_1400fb8de;
  }
  else {
LAB_1400fb8de:
    uVar18 = DAT_140e418c8;
    iVar14 = -400;
    if ((0x77 < (int)DAT_140e418c8) && (iVar14 = 0x3ac, (int)DAT_140e418c8 < 0xb4)) {
      dVar24 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - dVar25) * DAT_14053a628 * dVar5 *
                                     dVar28);
      iVar14 = -400 - (int)(dVar24 * _DAT_14053b2c0);
    }
    dVar24 = (double)FUN_140332d90(((double)(int)uVar18 - 0.0) * DAT_14053a698 * dVar5 * dVar28);
    fVar30 = (float)(dVar24 * DAT_14053b0d8) + DAT_14053ae30;
    if ((int)uVar18 < 0x8c) {
      dVar32 = 0.0;
    }
    else if ((int)uVar18 < 200) {
      dVar24 = (double)FUN_140332d90();
      dVar32 = dVar32 * dVar24 + 0.0;
    }
    uVar33 = DAT_140e47394;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e7c = _DAT_140e46e7c + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *(double *)(puVar7 + 8) = dVar32;
    *puVar7 = uVar33;
    puVar7[1] = 0x7b;
    puVar7[2] = 1;
    puVar7[3] = 0x44200000;
    puVar7[4] = 0x43b40000;
    *(undefined2 *)(puVar7 + 5) = 0xa64;
    *(undefined8 *)(puVar7 + 6) = 0x4000000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xc0;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar33 = *(undefined4 *)(&DAT_140e44264 + (longlong)iVar11 * 4);
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e7c = _DAT_140e46e7c + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar7[3] = (float)iVar14;
    puVar7[4] = fVar30;
    *puVar7 = uVar33;
    puVar7[1] = 0x7b;
    puVar7[2] = 1;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    dVar26 = DAT_14053b0f0;
    fVar30 = DAT_14053acfc;
    dVar32 = DAT_14053a9d8;
    dVar24 = DAT_14053a530;
    DAT_140e46c88 = puVar7;
    if (0x77 < (int)DAT_140e418c8) {
      pfVar15 = (float *)&local_108;
      iVar11 = 0;
      local_108 = _DAT_14053bed0;
      uStack_100 = _UNK_14053bed8;
      local_e8 = 0x42f00000;
      local_f8 = _DAT_14053be10;
      local_e4 = 0x44520000;
      local_e0 = 0x44a50000;
      do {
        uVar18 = DAT_140e418c8;
        iVar14 = 0x438;
        if ((0x77 < (int)DAT_140e418c8) && (iVar14 = 0x2b2, (int)DAT_140e418c8 < 0xdc)) {
          dVar27 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - dVar25) * dVar24 * dVar5 *
                                         dVar28);
          iVar14 = 0x438 - (int)(dVar27 * _DAT_14053a6c0);
        }
        uVar21 = ((uint)(uVar16 >> 0x1e) ^ (uint)uVar16) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
        iVar17 = (iVar11 + uVar18) * 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar21 = uVar21 * 0x800 ^ uVar21;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ DAT_140e9fd18 ^ uVar21;
        fVar23 = (float)(int)(DAT_140e9fd1c % 0x3d - 0x1e) + (float)iVar14;
        if (99 < iVar17 % 0x78) {
          dVar27 = (double)FUN_140332d90(((double)(iVar17 % 0x14) - 0.0) * dVar32 * dVar5 * dVar28);
          fVar23 = fVar23 + (float)(dVar27 * dVar26) + 0.0;
        }
        uVar33 = DAT_140e41a84;
        fVar1 = *pfVar15;
        puVar7 = (undefined4 *)_malloc_base(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar7 = uVar33;
        puVar7[3] = fVar1 - fVar30;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0xff;
        puVar7[0xc] = 0xff;
        puVar7[0xd] = 0xff;
        puVar7[4] = fVar23;
        puVar7[1] = 0x7b;
        puVar7[2] = 1;
        *(undefined2 *)(puVar7 + 5) = 0;
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 0xe) = 1;
        *(undefined8 *)(puVar7 + 0x10) = 0;
        _DAT_140e46e7c = _DAT_140e46e7c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar7;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
        }
        uVar16 = (ulonglong)((uint)uVar16 + 1);
        iVar11 = iVar11 + 10;
        pfVar15 = pfVar15 + 1;
        DAT_140e46c88 = puVar7;
      } while (iVar11 < 0x6e);
    }
  }
  uVar18 = DAT_140e418c8;
  dVar32 = DAT_14053b0c0;
  dVar24 = DAT_14053a848;
  if ((int)DAT_140e418c8 < 0x8c) {
    uVar33 = SUB84(DAT_14053a698,0);
    uVar34 = (undefined4)((ulonglong)DAT_14053a698 >> 0x20);
    puVar7 = DAT_140e46c88;
  }
  else {
    iVar11 = 0x438;
    if (0x8b < (int)DAT_140e418c8) {
      iVar11 = 0x168;
    }
    if ((int)DAT_140e418c8 < 200) {
      dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a4f0) * DAT_14053a628 *
                                     dVar5 * dVar28);
      iVar11 = 0x438 - (int)(dVar26 * dVar24);
    }
    uVar33 = SUB84(DAT_14053a698,0);
    uVar34 = (undefined4)((ulonglong)DAT_14053a698 >> 0x20);
    dVar26 = (double)FUN_140332d90(((double)(int)uVar18 - DAT_14053a3a0) * DAT_14053a698 * dVar5 *
                                   dVar28);
    uVar6 = DAT_140e47398;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e84 = _DAT_140e46e84 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar7 = uVar6;
    puVar7[1] = 0x7d;
    puVar7[2] = 1;
    puVar7[4] = (float)(dVar26 * dVar32) + 0.0 + (float)iVar11;
    puVar7[3] = 0x44200000;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
  }
  DAT_140e46c88 = puVar7;
  uVar18 = DAT_140e418c8;
  lVar13 = (longlong)(int)DAT_140e418c8;
  if ((int)DAT_140e418c8 < 0xaa) goto LAB_1400fcb28;
  iVar11 = 0x438;
  if (0xa9 < (int)DAT_140e418c8) {
    iVar11 = 0x168;
  }
  if ((int)DAT_140e418c8 < 0xe6) {
    dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_14053a540) * DAT_14053a628 *
                                   dVar5 * dVar28);
    iVar11 = 0x438 - (int)(dVar26 * dVar24);
  }
  dVar25 = (double)FUN_140332d90(((double)(int)uVar18 - dVar25) * (double)CONCAT44(uVar34,uVar33) *
                                 dVar5 * dVar28);
  fVar30 = (float)(dVar25 * dVar32) + 0.0 + (float)iVar11;
  uVar16 = DAT_140e44590;
  if (((int)uVar18 < 0x140) &&
     (uVar16 = (lVar13 + -0xaa) * (DAT_140e44590 / 0x96), uVar18 != ((int)uVar18 / 5) * 5)) {
    FUN_140184700(DAT_140e44190 * 4,DAT_140e4726c);
    FUN_14018a340(DAT_140e4726c,1,1);
  }
  uVar33 = DAT_140e46964;
  if (DAT_140e41928 == 0) {
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar7 = uVar33;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[4] = fVar30;
    puVar7[1] = 0x7c;
    puVar7[2] = 4;
    puVar7[3] = 0x428c0000;
    *(undefined2 *)(puVar7 + 5) = 0;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    FUN_1400c95e0(0,0x7c,(longlong)DAT_1407c7798);
  }
  uVar33 = DAT_140e46984;
  puVar7 = DAT_140e46c88;
  if (DAT_140e41928 == 1) {
    if (DAT_1407c7798 == 10) {
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[4] = fVar30;
      *puVar7 = uVar33;
      puVar7[1] = 0x7c;
      puVar7[2] = 4;
      puVar7[3] = 0x428c0000;
      *(undefined2 *)(puVar7 + 5) = 0;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xd] = 0xff;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
    DAT_140e46c88 = puVar7;
    uVar34 = DAT_140e4696c;
    uVar33 = DAT_140e46968;
    puVar7 = DAT_140e46c88;
    if (DAT_140e41abc == 0) {
      if (DAT_1407c7798 == 9) {
        puVar7 = (undefined4 *)_malloc_base();
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
        uVar33 = uVar34;
      }
      else {
        puVar7 = (undefined4 *)_malloc_base(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[4] = fVar30;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      puVar7[0xd] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[10] = 0xff;
      *(undefined2 *)(puVar7 + 5) = 0;
      puVar7[3] = 0x428c0000;
      puVar7[2] = 4;
      puVar7[1] = 0x7c;
      *puVar7 = uVar33;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
    DAT_140e46c88 = puVar7;
    uVar34 = DAT_140e4699c;
    uVar33 = DAT_140e46998;
    puVar7 = DAT_140e46c88;
    if (DAT_140e41abc == 1) {
      if (DAT_1407c7798 == 9) {
        puVar7 = (undefined4 *)_malloc_base();
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
        uVar33 = uVar34;
      }
      else {
        puVar7 = (undefined4 *)_malloc_base(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[4] = fVar30;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      puVar7[0xd] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[10] = 0xff;
      *(undefined2 *)(puVar7 + 5) = 0;
      puVar7[3] = 0x428c0000;
      puVar7[2] = 4;
      puVar7[1] = 0x7c;
      *puVar7 = uVar33;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
    DAT_140e46c88 = puVar7;
    uVar34 = DAT_140e469a4;
    uVar33 = DAT_140e469a0;
    puVar7 = DAT_140e46c88;
    if (DAT_140e41abc == 2) {
      if (DAT_1407c7798 == 9) {
        puVar7 = (undefined4 *)_malloc_base();
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
        uVar33 = uVar34;
      }
      else {
        puVar7 = (undefined4 *)_malloc_base(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[4] = fVar30;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      puVar7[0xd] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[10] = 0xff;
      *(undefined2 *)(puVar7 + 5) = 0;
      puVar7[3] = 0x428c0000;
      puVar7[2] = 4;
      puVar7[1] = 0x7c;
      *puVar7 = uVar33;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
    DAT_140e46c88 = puVar7;
    uVar33 = DAT_140e469a8;
    puVar7 = DAT_140e46c88;
    if (DAT_140e41abc == 3) {
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[4] = fVar30;
      *puVar7 = uVar33;
      puVar7[1] = 0x7c;
      puVar7[2] = 4;
      puVar7[3] = 0x428c0000;
      *(undefined2 *)(puVar7 + 5) = 0;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xd] = 0xff;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
  }
  DAT_140e46c88 = puVar7;
  puVar7 = DAT_140e46c88;
  if (DAT_1407c7798 != 10) {
    uVar33 = (&DAT_140e46960)[DAT_140e419b8 + 4];
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar7[4] = fVar30;
    *puVar7 = uVar33;
    puVar7[1] = 0x7c;
    puVar7[2] = 4;
    puVar7[3] = 0x435c0000;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar33 = DAT_140e4698c;
    if (DAT_140e45268 == 1) {
      iVar11 = 1;
      if (((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) || (DAT_140e419b8 == 2)) {
        iVar11 = 0x6e;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0xa0;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 100;
      }
      fVar23 = (float)iVar11 + DAT_14053adc4;
      DAT_140e46c88 = puVar7;
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar7[3] = fVar23;
      puVar7[4] = fVar30;
      *puVar7 = uVar33;
      puVar7[1] = 0x7c;
      puVar7[2] = 4;
      *(undefined2 *)(puVar7 + 5) = 0;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xd] = 0xff;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
    }
  }
  DAT_140e46c88 = puVar7;
  uVar34 = DAT_140e469ac;
  uVar33 = DAT_140e46960;
  if (DAT_140e451a4 == 0) {
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    fVar23 = fVar30 + DAT_14053ace8;
    *puVar7 = uVar33;
    puVar7[1] = 0x7c;
    puVar7[2] = 4;
    puVar7[3] = 0x42b40000;
    puVar7[4] = fVar23;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    uVar3 = uVar16;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    for (; uVar3 != 0; uVar3 = uVar3 / 10) {
    }
    DAT_140e46c88 = puVar7;
    if (uVar16 < 10) {
      FUN_1400c8410((&DAT_140e46bf8)[uVar16],0x7c,1);
    }
    else {
      FUN_1400c8410((&DAT_140e46bf8)[(int)uVar16 + (int)(uVar16 / 10) * -10],0x7c,1);
      uVar16 = uVar16 / 10;
      do {
        FUN_1400c8410((&DAT_140e46bf8)[(int)uVar16 + (int)(uVar16 / 10) * -10],0x7c,1);
        bVar22 = 9 < uVar16;
        uVar16 = uVar16 / 10;
      } while (bVar22);
    }
    uVar33 = DAT_140e46990;
    if (((0x13f < (int)DAT_140e418c8) && (DAT_140e44590 == DAT_140e46ae0)) && (DAT_140e44590 != 0))
    {
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar7[3] = 0x44340000;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
LAB_1400fca71:
      _DAT_140e46e80 = _DAT_140e46e80 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      fVar30 = fVar30 + DAT_14053ac80;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      puVar7[0xd] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[4] = fVar30;
      puVar7[0xb] = 0xff;
      puVar7[10] = 0xff;
      *(undefined2 *)(puVar7 + 5) = 0;
      puVar7[2] = 1;
      puVar7[1] = 0x7c;
      *puVar7 = uVar33;
      if (bVar22) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
      DAT_140e46c88 = puVar7;
      if (DAT_140e418c8 == 0x140) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47274);
        FUN_14018a340(DAT_140e47274,1,1);
      }
    }
  }
  else {
    iVar11 = DAT_140e451b0;
    if ((int)DAT_140e418c8 < 0x140) {
      iVar11 = (DAT_140e451b0 / 0x96) * (DAT_140e418c8 - 0xaa);
    }
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    fVar23 = fVar30 + DAT_14053ace8;
    *puVar7 = uVar34;
    puVar7[1] = 0x7c;
    puVar7[2] = 4;
    puVar7[3] = 0x42b40000;
    puVar7[4] = fVar23;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    FUN_1400c9c90(1,0x7c,iVar11);
    uVar33 = DAT_140e46990;
    if ((0x13f < (int)DAT_140e418c8) && (DAT_140e451b0 < DAT_140e46bb8)) {
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar7[3] = 0x441b0000;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      goto LAB_1400fca71;
    }
  }
  FUN_1400c48f0(0x7c);
LAB_1400fcb28:
  if (0x167 < (int)DAT_140e418c8) {
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_14053a6c0) * DAT_14053a798 *
                                   dVar5 * dVar28);
    FUN_1400d9b60(6,0x7c,0x80 - (int)(dVar28 * DAT_14053b1c8));
  }
  if (0 < DAT_140e45fac) {
    if (0x27 < DAT_140e45fac) {
      transition_tile_wipe_out_candidate(DAT_140e45fac + -0x28);
    }
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (DAT_140e45fac == 0x50) {
    DAT_140e46a20 = 0;
    FUN_1400f6fb0();
    DAT_140e418c8 = 0;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    lVar13 = DAT_140e45d78;
    while (lVar13 != 0) {
      lVar13 = *(longlong *)(lVar13 + 0x58);
      FUN_140323ce8();
    }
    DAT_140e45d78 = 0;
    puVar7 = &DAT_140e45100;
    DAT_140e45d28 = 0;
    DAT_140e45d1c = 0;
    do {
      FUN_14018f230(*puVar7,0);
      puVar7 = puVar7 + 1;
    } while ((longlong)puVar7 < 0x140e45178);
    if (bVar2) {
      DAT_140e45270 = 0x2f;
      if (DAT_140e467e8 == 0) {
        DAT_140e45270 = 0x2c;
      }
    }
    else {
      piVar8 = &DAT_140e46b04;
      DAT_140e473d4 = 1;
      do {
        if (*piVar8 == 1) {
          if (DAT_140e473d4 == 0) goto LAB_1400fcc88;
          DAT_140e45270 = 0x2d;
          goto LAB_1400fccae;
        }
        DAT_140e473d4 = DAT_140e473d4 + 1;
        piVar8 = piVar8 + 1;
      } while ((longlong)piVar8 < 0x140e46b24);
      DAT_140e473d4 = 0;
LAB_1400fcc88:
      iVar11 = result_route_predicate_candidate();
      DAT_140e45270 = 0x23;
      if (iVar11 != 0) {
        DAT_140e45270 = 0x10;
      }
    }
  }
LAB_1400fccae:
  FUN_140070e40();
  FUN_1400714d0();
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


