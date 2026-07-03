// Function: state_2d_2e_system_menu_branch_candidate @ 1400feaa0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_2d_2e_system_menu_branch_candidate(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined1 auVar3 [16];
  int iVar4;
  undefined4 *puVar5;
  longlong lVar6;
  int *piVar7;
  int iVar8;
  bool bVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  
  dVar11 = DAT_140539f40;
  if ((DAT_140e418c8 < 0x3c) && (DAT_140e45270 == 0x2d)) {
    FUN_1400d4310(DAT_140e418c8);
  }
  uVar2 = DAT_140e41ab8;
  puVar5 = DAT_140e46c88;
  if ((DAT_140e418c8 < 0x20) && (DAT_140e45270 == 0x2e)) {
    iVar4 = DAT_140e418c8 * -8;
    puVar5 = (undefined4 *)_malloc_base(0x48);
    if (puVar5 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e84 = _DAT_140e46e84 + 1;
    bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar5 = uVar2;
    *(undefined8 *)(puVar5 + 1) = 0x7d;
    *(undefined8 *)(puVar5 + 3) = 0;
    *(undefined2 *)(puVar5 + 5) = 0;
    *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar5 + 10) = 0;
    puVar5[0xc] = 0;
    puVar5[0xd] = iVar4 + 0xff;
    *(undefined8 *)(puVar5 + 0xe) = 1;
    *(undefined8 *)(puVar5 + 0x10) = 0;
    if (bVar9) {
      DAT_140e46bf0 = puVar5;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
    }
  }
  DAT_140e46c88 = puVar5;
  if (DAT_140e418c8 == 0x1e) {
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45160);
    FUN_14018a340(DAT_140e45160,1,1);
  }
  if (DAT_140e45fac == 0) {
    if ((DAT_140e418c8 < 0x96) || (DAT_140e467c8 != 1)) goto LAB_1400fee3f;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
    puVar5 = DAT_140e46c88;
LAB_1400fed57:
    DAT_140e46c88 = puVar5;
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  else if (0 < DAT_140e45fac) {
    if ((0x27 < DAT_140e45fac) && (DAT_140e45270 == 0x2d)) {
      FUN_1400d3fd0(DAT_140e45fac + -0x28);
    }
    uVar2 = DAT_140e41ab8;
    puVar5 = DAT_140e46c88;
    if ((0x2f < DAT_140e45fac) && (DAT_140e45270 == 0x2e)) {
      iVar4 = DAT_140e45fac * 8;
      puVar5 = (undefined4 *)_malloc_base(0x48);
      if (puVar5 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e84 = _DAT_140e46e84 + 1;
      bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar5 = uVar2;
      *(undefined8 *)(puVar5 + 1) = 0x7d;
      *(undefined8 *)(puVar5 + 3) = 0;
      *(undefined2 *)(puVar5 + 5) = 0;
      *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar5 + 10) = 0;
      puVar5[0xc] = 0;
      puVar5[0xd] = iVar4 + -0x180;
      *(undefined8 *)(puVar5 + 0xe) = 1;
      *(undefined8 *)(puVar5 + 0x10) = 0;
      if (bVar9) {
        DAT_140e46bf0 = puVar5;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
      }
    }
    goto LAB_1400fed57;
  }
  if (DAT_140e45fac == 0x50) {
    DAT_140e46a20 = 0;
    FUN_1400f6fb0();
    DAT_140e418c8 = 0;
    puVar5 = &DAT_140e45100;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    do {
      FUN_14018f230(*puVar5,0);
      puVar5 = puVar5 + 1;
    } while ((longlong)puVar5 < 0x140e45178);
    lVar6 = (longlong)DAT_140e473d4;
    DAT_140e473d4 = 1;
    *(undefined4 *)(&DAT_140e46b00 + lVar6 * 4) = 0;
    piVar7 = &DAT_140e46b04;
    do {
      if (*piVar7 == 1) {
        if (DAT_140e473d4 != 0) goto LAB_1400fee3f;
        goto LAB_1400fee03;
      }
      DAT_140e473d4 = DAT_140e473d4 + 1;
      piVar7 = piVar7 + 1;
    } while ((longlong)piVar7 < 0x140e46b24);
    DAT_140e473d4 = 0;
LAB_1400fee03:
    if (DAT_140e45270 == 0x2d) {
      iVar4 = FUN_140135330();
      DAT_140e45270 = 0x10;
      if (iVar4 == 0) {
        DAT_140e45270 = 0x23;
      }
    }
    else if (DAT_140e45270 == 0x2e) {
      DAT_140e45270 = 1;
    }
  }
LAB_1400fee3f:
  iVar4 = DAT_140e418c8;
  if (DAT_140e418c8 < 0x1e) {
    dVar10 = 0.0;
  }
  else {
    dVar10 = dVar11;
    if (DAT_140e418c8 < 0x32) {
      dVar10 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a2d8) * DAT_14053a890 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar10 = dVar10 + 0.0;
    }
  }
  iVar8 = 0xff;
  if (iVar4 < 0x3c) {
    dVar11 = 0.0;
    iVar8 = 0;
  }
  if (iVar4 - 0x32U < 0x1e) {
    dVar11 = (double)FUN_140332d90();
    dVar11 = dVar11 * DAT_14053b0a8 + DAT_14053a018;
    dVar12 = (double)FUN_140332d90();
    iVar8 = (int)(dVar12 * DAT_14053a5f8);
  }
  uVar2 = DAT_140e475e0;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(double *)(puVar5 + 8) = dVar10;
  *puVar5 = uVar2;
  puVar5[1] = 100;
  puVar5[2] = 1;
  puVar5[3] = 0x44200000;
  puVar5[4] = 0x43b40000;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0x80;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar9) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
  }
  auVar3._8_4_ = SUB84(dVar11,0);
  auVar3._0_8_ = dVar11;
  auVar3._12_4_ = (int)((ulonglong)dVar11 >> 0x20);
  DAT_140e46c88 = puVar5;
  FUN_1400c8410((&DAT_140e475e0)[DAT_140e473d4],100,1,DAT_14053aedc,DAT_14053ae30,0,auVar3,0xff,0xff
                ,0xff,iVar8,1,0);
  if (0x95 < DAT_140e418c8) {
    dVar11 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a548) * DAT_14053a798 *
                                   DAT_14053a020 * DAT_140539d28);
    FUN_1400d9b60(6,0x7c,0x80 - (int)(dVar11 * DAT_14053b1c8));
  }
  uVar2 = DAT_140e467f0;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar5 = uVar2;
  *(undefined8 *)(puVar5 + 1) = 10;
  *(undefined8 *)(puVar5 + 3) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0xff;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar9) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
  }
  uVar2 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  DAT_140e46c88 = puVar5;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar5 = uVar2;
  puVar5[1] = 10;
  puVar5[2] = 1;
  puVar5[3] = 0x44200000;
  puVar5[4] = 0x43c30000;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  puVar5[10] = 0xff;
  puVar5[0xb] = 0xff;
  puVar5[0xc] = 0xff;
  puVar5[0xd] = 0x80;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  if (bVar9) {
    DAT_140e46bf0 = puVar5;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
  }
  uVar2 = DAT_140e41ab8;
  DAT_140e46c88 = puVar5;
  puVar5 = (undefined4 *)_malloc_base(0x48);
  if (puVar5 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cbc = _DAT_140e46cbc + 1;
  bVar9 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar5 = uVar2;
  *(undefined8 *)(puVar5 + 3) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar5 + 10) = 0;
  puVar5[0xc] = 0;
  *(undefined8 *)(puVar5 + 0x10) = 0;
  *(undefined8 *)(puVar5 + 1) = 0xb;
  puVar5[0xd] = 0x80;
  *(undefined8 *)(puVar5 + 0xe) = 1;
  if (bVar9) {
    DAT_140e46bf0 = puVar5;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    puVar1 = (undefined8 *)(DAT_140e46c88 + 0x10);
    DAT_140e46c88 = puVar5;
    *puVar1 = puVar5;
    puVar5 = DAT_140e46c88;
  }
  DAT_140e46c88 = puVar5;
  return;
}


