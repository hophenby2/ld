// Function: stage_hud_or_option_panel_candidate @ 140130be0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_hud_or_option_panel_candidate(undefined4 param_1)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  bool bVar13;
  double dVar14;
  undefined8 in_stack_ffffffffffffff58;
  uint uVar15;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  iVar11 = 0xc0;
  if (DAT_140e418c8 < 0x78) {
    dVar14 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a460) * DAT_14053a890 *
                                   DAT_14053a020 * DAT_140539d28);
    iVar11 = (int)(dVar14 * DAT_14053a578);
  }
  uVar4 = DAT_140e475d8;
  uVar5 = DAT_140e475d0;
  iVar10 = 0;
  iVar6 = 0;
  iVar7 = 0;
  puVar9 = DAT_140e46c88;
  switch(param_1) {
  case 0:
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar5;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x42a00000;
    *(undefined2 *)(puVar9 + 5) = 0;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar5 = DAT_140e475bc;
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar5;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43340000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    if (DAT_140e441cc < 5) {
      DAT_140e46c88 = puVar9;
      uVar5 = FUN_1400dacb0(0xffffffff);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar5;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x43960000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      DAT_140e46c88 = puVar9;
      iVar6 = FUN_1400c9580(DAT_140e44acc,0,10,2,CONCAT44(uVar8,4),5);
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar6 * 4);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x43b40000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
    }
    DAT_140e46c88 = puVar9;
    if (DAT_140e441cc != 5) {
      return;
    }
    local_58 = _DAT_14053bd80;
    uStack_50 = _UNK_14053bd88;
    local_48 = _DAT_14053bd70;
    uStack_40 = _UNK_14053bd78;
    uVar8 = FUN_1400dacb0(0);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43700000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    uVar8 = FUN_1400dacb0(1);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43870000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    uVar8 = FUN_1400dacb0(2);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44278000;
    puVar9[4] = 0x43870000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    uVar8 = FUN_1400dacb0(3);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44188000;
    puVar9[4] = 0x43870000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar3 = _UNK_14053bb28;
    uVar2 = _DAT_14053bb20;
    fVar1 = DAT_14053aedc;
    pfVar12 = (float *)&local_58;
    DAT_140e46c88 = puVar9;
    do {
      uVar15 = 0;
      iVar6 = FUN_1400c9580(DAT_140e44acc + iVar10,0,10,4,2,2,2,3);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e475a0 + (longlong)iVar6 * 4),0x14,1,*pfVar12 + fVar1,
                    pfVar12[1],uVar15 & 0xffff0000,uVar2,uVar3,0xff,0xff,0xff,iVar11,1,0);
      iVar10 = iVar10 + 10;
      pfVar12 = pfVar12 + 2;
    } while (iVar10 < 0x28);
    return;
  case 1:
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar4;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43160000;
    *(undefined2 *)(puVar9 + 5) = 0;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar8 = DAT_140e475c0;
    DAT_140e46c88 = puVar9;
    if (DAT_140e44194 == 1) {
      puVar9 = (undefined4 *)_malloc_base();
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x437a0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      iVar6 = DAT_140e44acc;
      DAT_140e46c88 = puVar9;
      if (DAT_140e441cc < 5) {
        iVar7 = FUN_1400c9580(DAT_140e44acc,0,10,6,0,1,1,1,1,1);
      }
      if (DAT_140e441cc == 5) {
        iVar7 = FUN_1400c9580(iVar6,0,10,6,2,3,3,3,3,3);
      }
      uVar8 = FUN_1400dacb0(6);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar7 * 4);
    }
    else {
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x43f50000;
      puVar9[4] = 0x437a0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = DAT_140e475c8;
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44458000;
      puVar9[4] = 0x437a0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      iVar7 = DAT_140e44acc;
      DAT_140e46c88 = puVar9;
      if (DAT_140e441cc < 5) {
        iVar6 = FUN_1400c9580(DAT_140e44acc,0,10,2,0,1);
      }
      if (DAT_140e441cc == 5) {
        iVar6 = FUN_1400c9580(iVar7,0,10,2,2,3);
      }
      uVar8 = FUN_1400dacb0(6);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x43f50000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar6 * 4);
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x43f50000;
      puVar9[4] = 0x43be0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      iVar7 = DAT_140e44acc;
      DAT_140e46c88 = puVar9;
      if (DAT_140e441cc < 5) {
        iVar6 = FUN_1400c9580(DAT_140e44acc,0,10,6,0,1,1,1,1,1);
      }
      if (DAT_140e441cc == 5) {
        iVar6 = FUN_1400c9580(iVar7,0,10,6,2,3,3,3,3,3);
      }
      uVar8 = FUN_1400dacb0(8);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44458000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar6 * 4);
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44458000;
      puVar9[4] = 0x43be0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      uVar8 = DAT_140e475b8;
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
        uVar8 = DAT_140e475b8;
      }
    }
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar9[4] = 0x43be0000;
    *puVar9 = uVar8;
    break;
  case 2:
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar4;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x42a00000;
    *(undefined2 *)(puVar9 + 5) = 0;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar8 = DAT_140e475c0;
    DAT_140e46c88 = puVar9;
    if (DAT_140e44194 == 1) {
      puVar9 = (undefined4 *)_malloc_base();
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x442c8000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = DAT_140e475cc;
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44138000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      if (DAT_140e441cc < 5) {
        DAT_140e46c88 = puVar9;
        iVar7 = FUN_1400c9580(DAT_140e44acc,0,10,6,0,1,1,1,1,1);
        uVar8 = DAT_140e475a4;
        puVar9 = (undefined4 *)_malloc_base(0x48);
        if (puVar9 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
        bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar9 = uVar8;
        puVar9[1] = 0x14;
        puVar9[2] = 1;
        puVar9[3] = 0x442c8000;
        puVar9[4] = 0x43dc0000;
        *(undefined2 *)(puVar9 + 5) = 0;
        *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
        puVar9[10] = 0xff;
        puVar9[0xb] = 0xff;
        puVar9[0xc] = 0xff;
        puVar9[0xd] = iVar11;
        *(undefined8 *)(puVar9 + 0xe) = 1;
        *(undefined8 *)(puVar9 + 0x10) = 0;
        if (bVar13) {
          DAT_140e46bf0 = puVar9;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
        }
      }
      DAT_140e46c88 = puVar9;
      puVar9 = DAT_140e46c88;
      if (DAT_140e441cc == 5) {
        iVar7 = FUN_1400c9580(DAT_140e44acc,0,10,6,2,3,3,3,3,3);
        uVar8 = DAT_140e475ac;
        puVar9 = (undefined4 *)_malloc_base(0x48);
        if (puVar9 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
        bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar9 = uVar8;
        puVar9[1] = 0x14;
        puVar9[2] = 1;
        puVar9[3] = 0x442c8000;
        puVar9[4] = 0x43dc0000;
        *(undefined2 *)(puVar9 + 5) = 0;
        *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
        puVar9[10] = 0xff;
        puVar9[0xb] = 0xff;
        puVar9[0xc] = 0xff;
        puVar9[0xd] = iVar11;
        *(undefined8 *)(puVar9 + 0xe) = 1;
        *(undefined8 *)(puVar9 + 0x10) = 0;
        if (bVar13) {
          DAT_140e46bf0 = puVar9;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
        }
      }
      DAT_140e46c88 = puVar9;
      uVar8 = FUN_1400dacb0(6);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x442c8000;
      puVar9[4] = 0x43be0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      DAT_140e46c88 = puVar9;
      uVar8 = FUN_1400dacb0(9);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44138000;
      puVar9[4] = 0x43be0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar7 * 4);
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar9[3] = 0x44138000;
    }
    else {
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x43a00000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      iVar6 = DAT_140e44acc;
      DAT_140e46c88 = puVar9;
      if (DAT_140e441cc < 5) {
        iVar7 = FUN_1400c9580(DAT_140e44acc,0,10,6,0,1,1,1,1,1);
      }
      if (DAT_140e441cc == 5) {
        iVar7 = FUN_1400c9580(iVar6,0,10,6,2,3,3,3,3,3);
      }
      uVar8 = FUN_1400dacb0(6);
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar9 = uVar8;
      puVar9[1] = 0x14;
      puVar9[2] = 1;
      puVar9[3] = 0x44200000;
      puVar9[4] = 0x43be0000;
      *(undefined2 *)(puVar9 + 5) = 0;
      *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
      puVar9[10] = 0xff;
      puVar9[0xb] = 0xff;
      puVar9[0xc] = 0xff;
      puVar9[0xd] = iVar11;
      *(undefined8 *)(puVar9 + 0xe) = 1;
      *(undefined8 *)(puVar9 + 0x10) = 0;
      if (bVar13) {
        DAT_140e46bf0 = puVar9;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
      }
      uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar7 * 4);
      DAT_140e46c88 = puVar9;
      puVar9 = (undefined4 *)_malloc_base(0x48);
      if (puVar9 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar9[3] = 0x44200000;
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar9[4] = 0x43dc0000;
    *puVar9 = uVar8;
    goto LAB_140132720;
  case 3:
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar5;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x42f00000;
    *(undefined2 *)(puVar9 + 5) = 0;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar8 = DAT_140e475c4;
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x437a0000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    iVar6 = DAT_140e44acc;
    DAT_140e46c88 = puVar9;
    if (DAT_140e441cc < 5) {
      iVar7 = FUN_1400c9580(DAT_140e44acc,0,10,4,0,1,0,0);
    }
    if (DAT_140e441cc == 5) {
      iVar7 = FUN_1400c9580(iVar6,0,10,4,2,3,2,2);
    }
    uVar8 = FUN_1400dacb0(7);
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[1] = 0x14;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43a00000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar11;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar8 = *(undefined4 *)(&DAT_140e475a0 + (longlong)iVar7 * 4);
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[4] = 0x43be0000;
    break;
  case 4:
    uVar8 = DAT_140e475d8;
    goto LAB_1401326ce;
  case 5:
    uVar8 = DAT_140e475d4;
LAB_1401326ce:
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar8;
    puVar9[4] = 0x43a50000;
    break;
  default:
    goto switchD_140130c76_default;
  }
  puVar9[3] = 0x44200000;
LAB_140132720:
  puVar9[1] = 0x14;
  puVar9[2] = 1;
  *(undefined2 *)(puVar9 + 5) = 0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = iVar11;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  if (bVar13) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
switchD_140130c76_default:
  DAT_140e46c88 = puVar9;
  return;
}


