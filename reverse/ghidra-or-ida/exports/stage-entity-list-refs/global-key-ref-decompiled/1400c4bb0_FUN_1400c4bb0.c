// Function: FUN_1400c4bb0 @ 1400c4bb0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c4bb0(void)

{
  longlong lVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 *puVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  longlong lVar21;
  longlong lVar22;
  bool bVar23;
  float fVar24;
  float fVar25;
  double dVar26;
  undefined4 uVar27;
  ulonglong uVar28;
  undefined8 in_stack_fffffffffffffeb0;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  int local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  
  uVar19 = DAT_140e46a24;
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  puVar17 = (undefined4 *)_malloc_base(0x48);
  if (puVar17 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  lVar21 = 0;
  bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar17 = uVar19;
  *(undefined8 *)(puVar17 + 1) = 0x73;
  uVar16 = 0;
  puVar17[3] = 0;
  puVar17[4] = 0x43a50000;
  *(undefined2 *)(puVar17 + 5) = 0;
  *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
  puVar17[10] = 0xff;
  puVar17[0xb] = 0xff;
  puVar17[0xc] = 0xff;
  puVar17[0xd] = 0xff;
  *(undefined8 *)(puVar17 + 0xe) = 1;
  *(undefined8 *)(puVar17 + 0x10) = 0;
  if (bVar23) {
    DAT_140e46bf0 = puVar17;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar17;
  }
  uVar13 = DAT_140e46984;
  uVar5 = DAT_140e46964;
  uVar27 = DAT_14053ae34;
  uVar19 = DAT_14053ad40;
  DAT_140e46c88 = puVar17;
  if (DAT_1407c7798 == 10) {
    puVar17 = (undefined4 *)_malloc_base(0x48);
    if (puVar17 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar17 = uVar13;
    puVar17[1] = 0x7c;
    puVar17[2] = 4;
    puVar17[3] = 0x41f00000;
    puVar17[4] = 0x43b68000;
    *(undefined2 *)(puVar17 + 5) = 0;
    *(undefined8 *)(puVar17 + 6) = 0x3feccccccccccccd;
    *(undefined8 *)(puVar17 + 8) = 0x3feccccccccccccd;
    puVar17[10] = 0xff;
    puVar17[0xb] = 0xff;
    puVar17[0xc] = 0xff;
    puVar17[0xd] = 0xff;
    *(undefined8 *)(puVar17 + 0xe) = 1;
    *(undefined8 *)(puVar17 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar17;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
    }
  }
  else {
    puVar17 = (undefined4 *)_malloc_base();
    if (puVar17 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e5c = _DAT_140e46e5c + 1;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar17 = uVar5;
    puVar17[1] = 0x73;
    puVar17[2] = 4;
    puVar17[3] = 0x41f00000;
    puVar17[4] = 0x43b68000;
    *(undefined2 *)(puVar17 + 5) = 0;
    *(undefined8 *)(puVar17 + 6) = 0x3feccccccccccccd;
    *(undefined8 *)(puVar17 + 8) = 0x3feccccccccccccd;
    puVar17[10] = 0xff;
    puVar17[0xb] = 0xff;
    puVar17[0xc] = 0xff;
    puVar17[0xd] = 0xff;
    *(undefined8 *)(puVar17 + 0xe) = 1;
    *(undefined8 *)(puVar17 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar17;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
    }
    uVar29 = CONCAT44(uVar20,0xff);
    DAT_140e46c88 = puVar17;
    FUN_1400c95e0(0,0x73,(longlong)DAT_1407c7798,uVar19,uVar27,_DAT_14053bb10,_UNK_14053bb18,uVar29,
                  0,1);
    uVar20 = (undefined4)((ulonglong)uVar29 >> 0x20);
    puVar17 = DAT_140e46c88;
  }
  DAT_140e46c88 = puVar17;
  uVar29 = _UNK_14053bb28;
  uVar6 = _DAT_14053bb20;
  uVar5 = DAT_14053ae04;
  if (DAT_140e45270 != 0x1f) {
    uVar30 = CONCAT44(uVar20,0xff);
    FUN_1400c95e0(0,0x73,(longlong)DAT_140e418c8,DAT_14053ae04,uVar27,_DAT_14053bb20,_UNK_14053bb28,
                  uVar30,0,5);
    uVar20 = (undefined4)((ulonglong)uVar30 >> 0x20);
  }
  iVar14 = FUN_1401341a0();
  puVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == iVar14) {
        local_108 = *puVar4;
        uStack_100 = puVar4[1];
        local_f8 = puVar4[2];
        uStack_f0 = puVar4[3];
        local_e8 = puVar4[4];
        uStack_e0 = puVar4[5];
        local_d8 = puVar4[6];
        uStack_d0 = puVar4[7];
        local_c8 = puVar4[8];
        uStack_c0 = puVar4[9];
        local_b8 = *(int *)(puVar4 + 10);
        uStack_b4 = *(undefined4 *)((longlong)puVar4 + 0x54);
        uStack_b0 = *(undefined4 *)(puVar4 + 0xb);
        uStack_ac = *(undefined4 *)((longlong)puVar4 + 0x5c);
        local_a8 = puVar4[0xc];
      }
    }
  }
  iVar14 = 1;
  iVar15 = FUN_1401340e0();
  if (iVar15 != 0) {
    fVar24 = (float)FUN_140334430(DAT_140e445dc - uStack_e0._4_4_,DAT_140539fc0);
    fVar25 = (float)FUN_140334430(DAT_140e445d8 - (float)uStack_e0);
    if (fVar24 + fVar25 < 0.0) {
      fVar24 = (float)FUN_1403352f8();
    }
    else {
      fVar24 = SQRT(fVar24 + fVar25);
    }
    uVar18 = (int)fVar24 - local_b8;
    if ((uVar18 < 2000) && (uVar16 = uVar18, 0x96 < (int)uVar18)) {
      if (((int)uVar18 < 0x1c2) && (iVar14 = (int)(0x1c2 - uVar18) / 0x1e, iVar14 < 1)) {
        iVar14 = 1;
      }
    }
    else {
      iVar14 = 10;
    }
    uVar28 = uVar6;
    FUN_1400c95e0(0,0x73,(longlong)(int)uVar16,DAT_14053acc4,DAT_14053ae64,uVar6,uVar29,
                  CONCAT44(uVar20,0xff),1,4);
    dVar26 = (double)iVar14 * _DAT_140539e18 + DAT_140539ee8;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e45d38 + (longlong)iVar14 * 4),0x73,1,uVar19,DAT_14053ae70
                  ,uVar28 & 0xffffffffffff0000,dVar26,dVar26,0xff,0xff,0xff,0xff,1,0);
    uVar20 = (undefined4)((ulonglong)dVar26 >> 0x20);
  }
  FUN_1400c95e0(0,0x73,(longlong)DAT_140e451b4,uVar5,DAT_14053ae58,uVar6,uVar29,
                CONCAT44(uVar20,0xff),0,4);
  FUN_1400c95e0(0,0x73,(longlong)DAT_140e451b8,DAT_14053adfc,DAT_14053ae78,_DAT_14053baf0,
                _UNK_14053baf8,0xff,0,4);
  uVar20 = DAT_14053ae9c;
  uVar28 = uVar6;
  FUN_1400c95e0(0,0x73,(longlong)DAT_140e46bbc,DAT_14053ad58,DAT_14053ae9c,uVar6,uVar29,0xff,0,6);
  iVar14 = DAT_1407c7798;
  uVar19 = DAT_14053adc0;
  uVar27 = DAT_14053ade4;
  puVar17 = DAT_140e46c88;
  if (((DAT_140e41928 == 1) && (DAT_140e451a4 == 0)) && (DAT_1407c7798 != 10)) {
    iVar15 = FUN_1400c7d40();
    uVar13 = DAT_140e46be4;
    uVar27 = uVar19;
    if ((iVar15 == 1) || (iVar14 == 9)) {
      dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e44acc - 0.0) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar15 = 0xe0 - (int)(dVar26 * _DAT_14053b130);
      if (iVar14 == 9) {
        iVar15 = 0xff;
      }
      FUN_1400c8410(DAT_140e46be4,0x73,1,uVar5,uVar20,uVar28 & 0xffffffffffff0000,uVar6,uVar29,
                    iVar15,iVar15,iVar15,0xff,1,0);
      puVar17 = DAT_140e46c88;
    }
    else {
      puVar17 = (undefined4 *)_malloc_base(0x48);
      if (puVar17 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e5c = _DAT_140e46e5c + 1;
      bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar17 = uVar13;
      puVar17[1] = 0x73;
      puVar17[2] = 1;
      puVar17[3] = 0x438c0000;
      puVar17[4] = 0x4405c000;
      *(undefined2 *)(puVar17 + 5) = 0;
      *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
      puVar17[10] = 0x40;
      puVar17[0xb] = 0x40;
      puVar17[0xc] = 0x40;
      puVar17[0xd] = 0xff;
      *(undefined8 *)(puVar17 + 0xe) = 1;
      *(undefined8 *)(puVar17 + 0x10) = 0;
      if (bVar23) {
        DAT_140e46bf0 = puVar17;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
      }
    }
  }
  DAT_140e46c88 = puVar17;
  FUN_1400c95e0(2,0x73,(longlong)DAT_140e46b24,uVar27,DAT_14053aea0,uVar6,uVar29,0xff,1,2);
  iVar14 = DAT_140e445c0 * 0x1e;
  iVar14 = FUN_1400c9580(DAT_140e44acc,0,7,4,iVar14,iVar14 + 1,iVar14 + 2,iVar14 + 1);
  uVar19 = (&DAT_140e44e70)[iVar14];
  puVar17 = (undefined4 *)_malloc_base(0x48);
  if (puVar17 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar17 = uVar19;
  puVar17[1] = 0x73;
  puVar17[2] = 1;
  puVar17[3] = 0x425c0000;
  puVar17[4] = 0x44200000;
  *(undefined2 *)(puVar17 + 5) = 0;
  *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
  puVar17[10] = 0xff;
  puVar17[0xb] = 0xff;
  puVar17[0xc] = 0xff;
  puVar17[0xd] = 0xff;
  *(undefined8 *)(puVar17 + 0xe) = 1;
  *(undefined8 *)(puVar17 + 0x10) = 0;
  if (bVar23) {
    DAT_140e46bf0 = puVar17;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
  }
  DAT_140e46c88 = puVar17;
  if (0 < DAT_140e44654) {
    uVar16 = DAT_140e44acc & 0x80000001;
    if ((int)uVar16 < 0) {
      uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
    }
    if (uVar16 == 0) {
      uVar19 = *(undefined4 *)(&DAT_140e44eac + (longlong)iVar14 * 4);
      puVar17 = (undefined4 *)_malloc_base(0x48);
      if (puVar17 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e5c = _DAT_140e46e5c + 1;
      bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar17 = uVar19;
      puVar17[1] = 0x73;
      puVar17[2] = 1;
      puVar17[3] = 0x425c0000;
      puVar17[4] = 0x44200000;
      *(undefined2 *)(puVar17 + 5) = 0;
      *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
      puVar17[10] = 0xff;
      puVar17[0xb] = 0xff;
      puVar17[0xc] = 0xff;
      puVar17[0xd] = 0xff;
      *(undefined8 *)(puVar17 + 0xe) = 1;
      *(undefined8 *)(puVar17 + 0x10) = 0;
      if (bVar23) {
        DAT_140e46bf0 = puVar17;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
      }
    }
    DAT_140e46c88 = puVar17;
    if (0 < DAT_140e44654) {
      FUN_1400c95e0(0,0x73,(longlong)DAT_140e44654,DAT_14053acc8,DAT_14053aedc,uVar6,uVar29,0xff,1,4
                   );
    }
  }
  uVar19 = DAT_140e46bc0;
  puVar17 = (undefined4 *)_malloc_base(0x48);
  if (puVar17 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar17 = uVar19;
  puVar17[1] = 0x73;
  puVar17[2] = 1;
  puVar17[3] = 0x43200000;
  puVar17[4] = 0x4421c000;
  *(undefined2 *)(puVar17 + 5) = 0;
  *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
  puVar17[10] = 0xff;
  puVar17[0xb] = 0xff;
  puVar17[0xc] = 0xff;
  puVar17[0xd] = 0xff;
  *(undefined8 *)(puVar17 + 0xe) = 1;
  *(undefined8 *)(puVar17 + 0x10) = 0;
  if (bVar23) {
    DAT_140e46bf0 = puVar17;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
  }
  uVar12 = _UNK_14053be98;
  uVar11 = _DAT_14053be90;
  uVar10 = _UNK_14053be88;
  uVar9 = _DAT_14053be80;
  uVar8 = _UNK_14053be68;
  uVar7 = _DAT_14053be60;
  uVar30 = _UNK_14053be58;
  uVar29 = _DAT_14053be50;
  fVar24 = DAT_14053ac58;
  local_118 = 0x4000c000;
  local_114 = 0x80000000;
  local_110 = 0;
  lVar22 = lVar21;
  DAT_140e46c88 = puVar17;
  do {
    local_108 = uVar11;
    uStack_100 = uVar12;
    lVar3 = lVar22 * 2;
    local_f8 = uVar7;
    uStack_f0 = uVar8;
    lVar1 = lVar22 * 8;
    local_e8 = uVar29;
    uStack_e0 = uVar30;
    local_d8 = uVar9;
    uStack_d0 = uVar10;
    if (lVar22 < 4) {
      uVar19 = DAT_140e46bc4;
      uVar20 = DAT_140e46bc8;
      if (*(int *)((longlong)&DAT_140e467b8 + lVar21) != 0) goto LAB_1400c5885;
LAB_1400c5748:
      uVar2 = *(undefined2 *)((longlong)&local_118 + lVar3);
      uVar20 = *(undefined4 *)((longlong)&local_108 + lVar1 + 4);
      uVar27 = *(undefined4 *)(&local_108 + lVar22);
      puVar17 = (undefined4 *)_malloc_base(0x48);
      if (puVar17 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar17[3] = uVar27;
      *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 0x10) = 0;
      puVar17[4] = uVar20;
      *puVar17 = uVar19;
      puVar17[1] = 0x73;
      puVar17[2] = 1;
      *(undefined2 *)(puVar17 + 5) = uVar2;
      puVar17[10] = 0xff;
      puVar17[0xb] = 0xff;
      puVar17[0xc] = 0xff;
      puVar17[0xd] = 0xff;
      *(undefined8 *)(puVar17 + 0xe) = 1;
    }
    else {
      fVar25 = *(float *)((longlong)&local_108 + lVar1 + 4);
      uVar20 = *(undefined4 *)((longlong)&DAT_140e46bc4 + lVar21);
      uVar2 = *(undefined2 *)((longlong)&local_118 + lVar3);
      uVar19 = *(undefined4 *)(&local_108 + lVar22);
      puVar17 = (undefined4 *)_malloc_base(0x48);
      if (puVar17 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar17[3] = uVar19;
      *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 0x10) = 0;
      puVar17[4] = fVar25 - fVar24;
      *puVar17 = uVar20;
      puVar17[1] = 0x73;
      puVar17[2] = 1;
      *(undefined2 *)(puVar17 + 5) = uVar2;
      puVar17[10] = 0xff;
      puVar17[0xb] = 0xff;
      puVar17[0xc] = 0xff;
      puVar17[0xd] = 0xff;
      *(undefined8 *)(puVar17 + 0xe) = 1;
      _DAT_140e46e5c = _DAT_140e46e5c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar17;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
      }
      uVar19 = DAT_140e46bcc;
      uVar20 = DAT_140e46bd0;
      DAT_140e46c88 = puVar17;
      if (*(int *)((longlong)&DAT_140e467c0 + lVar21) == 0) goto LAB_1400c5748;
LAB_1400c5885:
      uVar2 = *(undefined2 *)((longlong)&local_118 + lVar3);
      uVar19 = *(undefined4 *)((longlong)&local_108 + lVar1 + 4);
      uVar27 = *(undefined4 *)(&local_108 + lVar22);
      puVar17 = (undefined4 *)_malloc_base();
      if (puVar17 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar17[3] = uVar27;
      puVar17[10] = 0xff;
      *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
      puVar17[0xb] = 0xff;
      puVar17[0xc] = 0xff;
      puVar17[0xd] = 0xff;
      *(undefined8 *)(puVar17 + 0x10) = 0;
      puVar17[4] = uVar19;
      *puVar17 = uVar20;
      puVar17[1] = 0x73;
      puVar17[2] = 1;
      *(undefined2 *)(puVar17 + 5) = uVar2;
      *(undefined8 *)(puVar17 + 0xe) = 1;
    }
    _DAT_140e46e5c = _DAT_140e46e5c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar17;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
    }
    lVar22 = lVar22 + 1;
    DAT_140e46c88 = puVar17;
    lVar21 = lVar21 + 4;
    if (0x1f < lVar21) {
      return;
    }
  } while( true );
}


