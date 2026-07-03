// Function: FUN_1400c2860 @ 1400c2860
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c2860(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  int iVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  double dVar25;
  float fVar26;
  undefined4 uVar27;
  ulonglong in_stack_fffffffffffffed0;
  uint6 uVar28;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined1 local_d8 [176];
  
  uVar27 = DAT_140e419c0;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  uVar20 = 0;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar27;
  *(undefined8 *)(puVar10 + 1) = 0x6e;
  *(undefined8 *)(puVar10 + 3) = 0x446b0000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar10;
  }
  if (DAT_140e45270 == 0x1f) {
    uVar27 = *(undefined4 *)(&DAT_140e419e4 + (longlong)(DAT_140e445c0 * 10) * 4);
  }
  else {
    uVar27 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
  }
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  puVar10[0xd] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[10] = 0xff;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 3) = 0;
  *(undefined8 *)(puVar10 + 1) = 0x6e;
  *puVar10 = uVar27;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar8 = _UNK_14053bb08;
  uVar17 = _DAT_14053bb00;
  uVar2 = DAT_14053b004;
  uVar14 = DAT_14053aff0;
  uVar27 = DAT_14053ac34;
  iVar15 = 0;
  DAT_140e46c88 = puVar10;
  if (DAT_140e468f4 == 0) {
    FUN_1400c95e0(0,0x78,(longlong)DAT_140e468c4,DAT_14053aff0,DAT_14053ac34,_DAT_14053bb00,
                  _UNK_14053bb08,0xff,0,3);
    in_stack_fffffffffffffed0 = uVar17;
    FUN_1400c95e0(0,0x6e,0x3c,uVar2,uVar27,uVar17,uVar8,0xff,0,3);
  }
  if (DAT_140e468f4 == 1) {
    FUN_1400c95e0(0,0x78,(longlong)(DAT_140e468c4 / 2),uVar14,uVar27,uVar17,uVar8,0xff,0,3);
    in_stack_fffffffffffffed0 = uVar17;
    FUN_1400c95e0(0,0x6e,0x1e,uVar2,uVar27,uVar17,uVar8,0xff,0,3);
  }
  if (DAT_140e468f4 == 2) {
    FUN_1400c95e0(0,0x78,(longlong)
                         (DAT_140e468c4 / 3 + (DAT_140e468c4 >> 0x1f) +
                         (int)((ulonglong)
                               ((longlong)DAT_140e468c4 / 3 + ((longlong)DAT_140e468c4 >> 0x3f)) >>
                              0x1f)),uVar14,uVar27,uVar17,uVar8,0xff,0,3);
    FUN_1400c95e0(0,0x6e,0x14,uVar2,uVar27,uVar17,uVar8,0xff,0,3);
    in_stack_fffffffffffffed0 = uVar17;
  }
  uVar27 = DAT_140e419b0;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar27;
  *(undefined8 *)(puVar10 + 1) = 0x6e;
  *(undefined8 *)(puVar10 + 3) = 0x449a6000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3fe999999999999a;
  *(undefined8 *)(puVar10 + 8) = 0x3fe999999999999a;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar8 = _UNK_14053bb28;
  dVar23 = _DAT_14053bb20;
  uVar14 = DAT_14053afd0;
  uVar27 = DAT_14053ae28;
  DAT_140e46c88 = puVar10;
  if (DAT_140e41928 == -1) {
LAB_1400c2d2f:
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e46b6c,0x6f,1,uVar14,uVar27,in_stack_fffffffffffffed0,dVar23,uVar8,0xff,
                  0xff,0xff,0xff,1,0);
  }
  else {
    if (DAT_1407c7798 != 10) {
      in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
      FUN_1400c8410((&DAT_140e46b30)[DAT_140e419b8 + 10],0x6f,1,DAT_14053afd0,DAT_14053ae28,
                    in_stack_fffffffffffffed0,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0)
      ;
    }
    if (DAT_140e41928 == -1) goto LAB_1400c2d2f;
  }
  if (DAT_1407c7798 == 10) {
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e46b70,0x6f,1,uVar14,uVar27,in_stack_fffffffffffffed0,dVar23,uVar8,0xff,
                  0xff,0xff,0xff,1,0);
  }
  uVar27 = DAT_14053ae38;
  if (DAT_140e41928 == 1) {
    if (DAT_1407c7798 == 10) goto LAB_1400c2ebf;
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e46b74,0x6f,1,uVar14,DAT_14053ae38,in_stack_fffffffffffffed0,dVar23,uVar8,
                  0xff,0xff,0xff,0xff,1,0);
  }
  if (DAT_140e41928 == 2) {
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e46ba0,0x6f,1,uVar14,uVar27,in_stack_fffffffffffffed0,dVar23,uVar8,0xff,
                  0xff,0xff,0xff,1,0);
  }
LAB_1400c2ebf:
  uVar14 = DAT_140e46ba4;
  uVar27 = DAT_140e46b30;
  if (DAT_140e46904 == 0) {
    puVar10 = (undefined4 *)_malloc_base();
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar27;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[3] = 0x44820000;
    puVar10[4] = 0x43cd0000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar10;
    }
    uVar27 = DAT_140e46b34;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      uVar27 = DAT_140e46b34;
    }
  }
  else {
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar14;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[3] = 0x44820000;
    puVar10[4] = 0x43cd0000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar10;
    }
    uVar27 = DAT_140e46ba8;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      uVar27 = DAT_140e46ba8;
    }
  }
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  puVar10[0xd] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[10] = 0xff;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined2 *)(puVar10 + 5) = 0;
  puVar10[4] = 0x43e10000;
  puVar10[3] = 0x44820000;
  puVar10[2] = 1;
  puVar10[1] = 0x6f;
  *puVar10 = uVar27;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar3 = DAT_140e46ae0;
  fVar26 = DAT_14053aff8;
  dVar7 = DAT_14053ae68;
  uVar27 = (undefined4)DAT_14053a1e8;
  uVar16 = uVar20;
  uVar17 = uVar20;
  DAT_140e46c88 = puVar10;
  do {
    dVar22 = (double)FUN_1403316f0(uVar27,(double)(int)uVar16);
    fVar6 = DAT_14053b32c;
    fVar5 = DAT_14053b2c8;
    uVar2 = DAT_14053b000;
    uVar14 = DAT_14053ae4c;
    fVar4 = DAT_14053ac48;
    lVar11 = 0;
    if ((dVar7 <= dVar22) && (dVar22 = dVar22 - dVar7, dVar22 < dVar7)) {
      lVar11 = -0x8000000000000000;
    }
    uVar13 = (int)uVar16 + 1;
    uVar16 = (ulonglong)uVar13;
    uVar17 = uVar17 + ((longlong)dVar22 + lVar11) * 9;
  } while ((int)uVar13 < 0xc);
  uVar16 = uVar17;
  if (uVar3 <= uVar17) {
    uVar16 = uVar3;
  }
  uVar28 = (uint6)(in_stack_fffffffffffffed0 >> 0x10);
  if (uVar3 < 10) {
    in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
    FUN_1400c8410((&DAT_140e41980)[uVar3],0x6f,1,fVar26,DAT_14053ae4c,in_stack_fffffffffffffed0,
                  dVar23,uVar8,0xff,0xff,0xff,0xff,1,0);
  }
  else {
    uVar19 = uVar16;
    fVar24 = fVar26;
    if (uVar3 <= uVar17) goto LAB_1400c3212;
    in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
    FUN_1400c8410(DAT_140e419ac,0x6f,1,DAT_14053b000,DAT_14053ae4c,in_stack_fffffffffffffed0,dVar23,
                  uVar8,0xff,0xff,0xff,0xff,1,0);
    uVar17 = uVar20;
    while( true ) {
      while( true ) {
        iVar15 = (int)uVar17;
        uVar19 = uVar16;
LAB_1400c3212:
        uVar16 = uVar19 / 10;
        uVar1 = (&DAT_140e41980)[(int)uVar19 + (int)uVar16 * -10];
        puVar10 = (undefined4 *)_malloc_base(0x48);
        if (puVar10 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar10[3] = fVar24;
        *puVar10 = uVar1;
        puVar10[1] = 0x6f;
        puVar10[2] = 1;
        puVar10[4] = 0x43cd0000;
        *(undefined2 *)(puVar10 + 5) = 0;
        *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0xff;
        puVar10[0xc] = 0xff;
        puVar10[0xd] = 0xff;
        *(undefined8 *)(puVar10 + 0xe) = 1;
        *(undefined8 *)(puVar10 + 0x10) = 0;
        _DAT_140e46e4c = _DAT_140e46e4c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar10;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
        }
        fVar24 = fVar24 + fVar6;
        DAT_140e46c88 = puVar10;
        if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                     (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * -3 != 2) break;
        if (uVar19 < 10) goto LAB_1400c33eb;
        fVar24 = fVar24 + fVar5;
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar24 + fVar4,uVar14,in_stack_fffffffffffffed0,dVar23,
                      uVar8,0xff,0xff,0xff,0xff,1,0);
        uVar17 = (ulonglong)(iVar15 + 1);
      }
      if (uVar19 < 10) break;
      uVar17 = (ulonglong)(iVar15 + 1);
    }
  }
LAB_1400c33eb:
  uVar3 = DAT_140e44590;
  uVar16 = uVar20;
  uVar17 = uVar20;
  do {
    dVar22 = (double)FUN_1403316f0(uVar27,(double)(int)uVar16);
    uVar14 = DAT_14053ae70;
    lVar11 = 0;
    if ((dVar7 <= dVar22) && (dVar22 = dVar22 - dVar7, dVar22 < dVar7)) {
      lVar11 = -0x8000000000000000;
    }
    uVar13 = (int)uVar16 + 1;
    uVar16 = (ulonglong)uVar13;
    uVar17 = uVar17 + ((longlong)dVar22 + lVar11) * 9;
  } while ((int)uVar13 < 0xc);
  uVar16 = uVar17;
  if (uVar3 <= uVar17) {
    uVar16 = uVar3;
  }
  uVar28 = (uint6)(in_stack_fffffffffffffed0 >> 0x10);
  if (uVar3 < 10) {
    in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
    FUN_1400c8410((&DAT_140e41980)[uVar3],0x6f,1,fVar26,DAT_14053ae70,in_stack_fffffffffffffed0,
                  dVar23,uVar8,0xff,0xff,0xff,0xff,1,0);
  }
  else {
    uVar19 = uVar20;
    fVar24 = fVar26;
    if (uVar17 < uVar3) {
      in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
      FUN_1400c8410(DAT_140e419ac,0x6f,1,uVar2,DAT_14053ae70,in_stack_fffffffffffffed0,dVar23,uVar8,
                    0xff,0xff,0xff,0xff,1,0);
      uVar19 = 0;
    }
    while( true ) {
      while( true ) {
        uVar17 = uVar16 / 10;
        uVar1 = (&DAT_140e41980)[(int)uVar16 + (int)uVar17 * -10];
        puVar10 = (undefined4 *)_malloc_base(0x48);
        if (puVar10 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar10[3] = fVar24;
        *puVar10 = uVar1;
        puVar10[1] = 0x6f;
        puVar10[2] = 1;
        puVar10[4] = 0x43e10000;
        *(undefined2 *)(puVar10 + 5) = 0;
        *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0xff;
        puVar10[0xc] = 0xff;
        puVar10[0xd] = 0xff;
        *(undefined8 *)(puVar10 + 0xe) = 1;
        *(undefined8 *)(puVar10 + 0x10) = 0;
        _DAT_140e46e4c = _DAT_140e46e4c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar10;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
        }
        iVar15 = (int)uVar19;
        fVar24 = fVar24 + fVar6;
        DAT_140e46c88 = puVar10;
        if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                     (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * -3 != 2) break;
        if (uVar16 < 10) goto LAB_1400c36b3;
        fVar24 = fVar24 + fVar5;
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar24 + fVar4,uVar14,in_stack_fffffffffffffed0,dVar23,
                      uVar8,0xff,0xff,0xff,0xff,1,0);
        uVar19 = (ulonglong)(iVar15 + 1);
        uVar16 = uVar17;
      }
      if (uVar16 < 10) break;
      uVar19 = (ulonglong)(iVar15 + 1);
      uVar16 = uVar17;
    }
  }
LAB_1400c36b3:
  uVar14 = DAT_140e46b38;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar14;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44820000;
  puVar10[4] = 0x43fa0000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar3 = DAT_1407c77a8;
  uVar16 = uVar20;
  uVar17 = uVar20;
  DAT_140e46c88 = puVar10;
  do {
    dVar22 = (double)FUN_1403316f0(uVar27,(double)(int)uVar16);
    uVar14 = DAT_14053ae88;
    lVar11 = 0;
    if ((dVar7 <= dVar22) && (dVar22 = dVar22 - dVar7, dVar22 < dVar7)) {
      lVar11 = -0x8000000000000000;
    }
    uVar13 = (int)uVar16 + 1;
    uVar16 = (ulonglong)uVar13;
    uVar17 = uVar17 + ((longlong)dVar22 + lVar11) * 9;
  } while ((int)uVar13 < 9);
  uVar16 = uVar17;
  if (uVar3 <= uVar17) {
    uVar16 = uVar3;
  }
  uVar28 = (uint6)(in_stack_fffffffffffffed0 >> 0x10);
  if (uVar3 < 10) {
    in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
    FUN_1400c8410((&DAT_140e41980)[uVar3],0x6f,1,fVar26,DAT_14053ae88,in_stack_fffffffffffffed0,
                  dVar23,uVar8,0xff,0xff,0xff,0xff,1,0);
  }
  else {
    uVar19 = uVar20;
    fVar24 = fVar26;
    if (uVar17 < uVar3) {
      in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
      FUN_1400c8410(DAT_140e419ac,0x6f,1,uVar2,DAT_14053ae88,in_stack_fffffffffffffed0,dVar23,uVar8,
                    0xff,0xff,0xff,0xff,1,0);
      uVar19 = 0;
    }
    while( true ) {
      while( true ) {
        uVar17 = uVar16 / 10;
        uVar2 = (&DAT_140e41980)[(int)uVar16 + (int)uVar17 * -10];
        puVar10 = (undefined4 *)_malloc_base(0x48);
        if (puVar10 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar10[3] = fVar24;
        *puVar10 = uVar2;
        puVar10[1] = 0x6f;
        puVar10[2] = 1;
        puVar10[4] = 0x43fa0000;
        *(undefined2 *)(puVar10 + 5) = 0;
        *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0xff;
        puVar10[0xc] = 0xff;
        puVar10[0xd] = 0xff;
        *(undefined8 *)(puVar10 + 0xe) = 1;
        *(undefined8 *)(puVar10 + 0x10) = 0;
        _DAT_140e46e4c = _DAT_140e46e4c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar10;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
        }
        iVar15 = (int)uVar19;
        fVar24 = fVar24 + fVar6;
        DAT_140e46c88 = puVar10;
        if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                     (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * -3 != 2) break;
        if (uVar16 < 10) goto LAB_1400c3a33;
        fVar24 = fVar24 + fVar5;
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar24 + fVar4,uVar14,in_stack_fffffffffffffed0,dVar23,
                      uVar8,0xff,0xff,0xff,0xff,1,0);
        uVar19 = (ulonglong)(iVar15 + 1);
        uVar16 = uVar17;
      }
      if (uVar16 < 10) break;
      uVar19 = (ulonglong)(iVar15 + 1);
      uVar16 = uVar17;
    }
  }
LAB_1400c3a33:
  uVar13 = DAT_140e45d18;
  uStack_e4 = 0x40;
  local_e8 = 0xff;
  uVar14 = 0x40;
  dVar25 = (double)DAT_140e45d20 / DAT_14053a3a0;
  dVar22 = (double)(int)DAT_140e45d18 / _DAT_14053ac00;
  if (49999 < DAT_140e45d18) {
    dVar22 = (double)(int)-DAT_140e45d18 / DAT_14053a7c8;
    puVar12 = (undefined8 *)FUN_140135060(local_d8,DAT_140e44acc,0x14);
    uVar14 = *(undefined4 *)(puVar12 + 1);
    uStack_e4 = (undefined4)((ulonglong)*puVar12 >> 0x20);
    local_e8 = (undefined4)*puVar12;
    if (49999 < (int)uVar13) {
      dVar22 = dVar23;
    }
  }
  uVar2 = DAT_140e46b3c;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar2;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44820000;
  puVar10[4] = 0x44048000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar2 = DAT_140e45d98;
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar2;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x448de000;
  puVar10[4] = 0x44058000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0x40;
  puVar10[0xb] = 0x40;
  puVar10[0xc] = 0x80;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
  DAT_140e46c88 = puVar10;
  FUN_1400c8410(DAT_140e45d8c,0x6f,0,DAT_14053afb8,DAT_14053ae94,in_stack_fffffffffffffed0,dVar22,
                dVar23,local_e8,uStack_e4,uVar14,0xff,1,0);
  uVar14 = DAT_140e45d8c;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(double *)(puVar10 + 6) = dVar25;
  *puVar10 = uVar14;
  *(undefined8 *)(puVar10 + 1) = 0x6f;
  puVar10[3] = 0x447dc000;
  puVar10[4] = 0x4407c000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 8) = 0x3fe0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0x80;
  puVar10[0xc] = 0x40;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar14 = DAT_140e46b40;
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar14;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44820000;
  puVar10[4] = 0x44110000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  iVar15 = 1;
  iVar18 = 0x40d;
  DAT_140e46c88 = puVar10;
  do {
    uVar14 = DAT_140e46b50;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar10 = uVar14;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[4] = 0x44110000;
    *(undefined2 *)(puVar10 + 5) = 0;
    puVar10[3] = (float)iVar18;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 10) = 0;
    puVar10[0xc] = 0;
    puVar10[0xd] = 0x40;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
    uVar14 = DAT_140e46b50;
    if (iVar15 <= DAT_140e445f8) {
      DAT_140e46c88 = puVar10;
      puVar10 = (undefined4 *)_malloc_base(0x48);
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar10[3] = (float)iVar18;
      *puVar10 = uVar14;
      puVar10[1] = 0x6f;
      puVar10[2] = 1;
      puVar10[4] = 0x44110000;
      *(undefined2 *)(puVar10 + 5) = 0;
      *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
      puVar10[10] = 0xff;
      puVar10[0xb] = 0xff;
      puVar10[0xc] = 0xff;
      puVar10[0xd] = 0xff;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      _DAT_140e46e4c = _DAT_140e46e4c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar10;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
    }
    DAT_140e46c88 = puVar10;
    uVar14 = DAT_140e46b44;
    iVar15 = iVar15 + 1;
    iVar18 = iVar18 + 0x1b;
  } while (iVar18 < 0x4e6);
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar14;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44834000;
  puVar10[4] = 0x44188000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  DAT_140e46c88 = puVar10;
  if (DAT_140e46808 < 5) {
    uVar3 = *(ulonglong *)
             (&DAT_140538b10 + ((longlong)DAT_140e419b8 * 5 + (longlong)DAT_140e46808) * 8);
    uVar16 = uVar20;
    uVar17 = uVar20;
    do {
      dVar23 = (double)FUN_1403316f0(uVar27,(double)(int)uVar16);
      uVar9 = _UNK_14053baf8;
      uVar8 = _DAT_14053baf0;
      uVar14 = DAT_14053aec8;
      lVar11 = 0;
      if ((dVar7 <= dVar23) && (dVar23 = dVar23 - dVar7, dVar23 < dVar7)) {
        lVar11 = -0x8000000000000000;
      }
      uVar13 = (int)uVar16 + 1;
      uVar16 = (ulonglong)uVar13;
      uVar17 = uVar17 + ((longlong)dVar23 + lVar11) * 9;
    } while ((int)uVar13 < 0xc);
    uVar16 = uVar17;
    if (uVar3 <= uVar17) {
      uVar16 = uVar3;
    }
    uVar28 = (uint6)(in_stack_fffffffffffffed0 >> 0x10);
    if (uVar3 < 10) {
      FUN_1400c8410((&DAT_140e41980)[uVar3],0x6f,1,fVar26,DAT_14053aec8,(ulonglong)uVar28 << 0x10,
                    _DAT_14053baf0,_UNK_14053baf8,0xff,0xff,0xff,0xff,1,0);
    }
    else {
      fVar4 = DAT_14053b324;
      fVar5 = DAT_14053b1c0;
      fVar6 = DAT_14053ac30;
      if (uVar17 < uVar3) {
        in_stack_fffffffffffffed0 = (ulonglong)uVar28 << 0x10;
        FUN_1400c8410(DAT_140e419ac,0x6f,1,DAT_14053affc,DAT_14053aec8,in_stack_fffffffffffffed0,
                      _DAT_14053baf0,_UNK_14053baf8,0xff,0xff,0xff,0xff,1,0);
        fVar4 = DAT_14053b324;
        fVar5 = DAT_14053b1c0;
        fVar6 = DAT_14053ac30;
      }
      while( true ) {
        while( true ) {
          uVar17 = uVar16 / 10;
          uVar27 = (&DAT_140e41980)[(int)uVar16 + (int)uVar17 * -10];
          puVar10 = (undefined4 *)_malloc_base(0x48);
          if (puVar10 == (undefined4 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          puVar10[3] = fVar26;
          *(undefined8 *)(puVar10 + 6) = 0x3fe6666666666666;
          *(undefined8 *)(puVar10 + 8) = 0x3fe6666666666666;
          *puVar10 = uVar27;
          puVar10[1] = 0x6f;
          puVar10[2] = 1;
          puVar10[4] = 0x4418c000;
          *(undefined2 *)(puVar10 + 5) = 0;
          puVar10[10] = 0xff;
          puVar10[0xb] = 0xff;
          puVar10[0xc] = 0xff;
          puVar10[0xd] = 0xff;
          *(undefined8 *)(puVar10 + 0xe) = 1;
          *(undefined8 *)(puVar10 + 0x10) = 0;
          _DAT_140e46e4c = _DAT_140e46e4c + 1;
          if (DAT_140e46bf0 == (undefined4 *)0x0) {
            DAT_140e46bf0 = puVar10;
          }
          if (DAT_140e46c88 != (undefined4 *)0x0) {
            *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
          }
          iVar15 = (int)uVar20;
          fVar26 = fVar26 + fVar4;
          DAT_140e46c88 = puVar10;
          if (iVar15 + (iVar15 / 3 + (iVar15 >> 0x1f) +
                       (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >>
                            0x1f)) * -3 != 2) break;
          if (uVar16 < 10) goto LAB_1400c434e;
          fVar26 = fVar26 + fVar5;
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
          FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar26 + fVar6,uVar14,in_stack_fffffffffffffed0,uVar8,
                        uVar9,0xff,0xff,0xff,0xff,1,0);
          uVar20 = (ulonglong)(iVar15 + 1);
          uVar16 = uVar17;
        }
        if (uVar16 < 10) break;
        uVar20 = (ulonglong)(iVar15 + 1);
        uVar16 = uVar17;
      }
    }
  }
LAB_1400c434e:
  uVar27 = DAT_140e46b48;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar27;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44820000;
  puVar10[4] = 0x44228000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar27 = DAT_140e46b54;
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar10 = uVar27;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44898000;
  puVar10[4] = 0x44228000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 10) = 0;
  puVar10[0xc] = 0;
  puVar10[0xd] = 0x40;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar27 = DAT_140e46b54;
  if (0 < DAT_140e45d34) {
    DAT_140e46c88 = puVar10;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar10 = uVar27;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[3] = 0x44898000;
    puVar10[4] = 0x44228000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  uVar27 = DAT_140e46b54;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar10 = uVar27;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x448de000;
  puVar10[4] = 0x44228000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 10) = 0;
  puVar10[0xc] = 0;
  puVar10[0xd] = 0x40;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar27 = DAT_140e46b54;
  if (1 < DAT_140e45d34) {
    DAT_140e46c88 = puVar10;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar10 = uVar27;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[3] = 0x448de000;
    puVar10[4] = 0x44228000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  uVar27 = DAT_140e46b54;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar10 = uVar27;
  puVar10[1] = 0x6f;
  puVar10[2] = 1;
  puVar10[3] = 0x44924000;
  puVar10[4] = 0x44228000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 10) = 0;
  puVar10[0xc] = 0;
  puVar10[0xd] = 0x40;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  _DAT_140e46e4c = _DAT_140e46e4c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar27 = DAT_140e46b54;
  if (2 < DAT_140e45d34) {
    DAT_140e46c88 = puVar10;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar10 = uVar27;
    puVar10[1] = 0x6f;
    puVar10[2] = 1;
    puVar10[3] = 0x44924000;
    puVar10[4] = 0x44228000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  FUN_1400c48f0(0x6f);
  if (DAT_140e451a4 == 1) {
    FUN_1400c5930();
  }
  if ((DAT_140e441b8 == 1) && (DAT_140e41928 != -1)) {
    FUN_1400c4bb0();
  }
  return;
}


