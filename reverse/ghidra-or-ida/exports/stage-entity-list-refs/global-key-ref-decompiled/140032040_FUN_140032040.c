// Function: FUN_140032040 @ 140032040
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140032040(undefined4 *param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  longlong lVar6;
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float fVar16;
  longlong lStack_f0;
  int iStack_e4;
  
  iVar10 = DAT_140e44308;
  dVar8 = DAT_14053a020;
  dVar7 = DAT_140539d28;
  lVar6 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x60)) {
      if (*(int *)(lVar6 + 4) == DAT_140e44308) {
        lStack_f0 = *(longlong *)(lVar6 + 8);
        iStack_e4 = *(int *)(lVar6 + 0x14);
      }
    }
  }
  iVar5 = param_1[3];
  dVar12 = (double)FUN_140332d90();
  *(short *)((longlong)param_1 + 0x42) = 0x4000 - (short)(int)(dVar12 * _DAT_14053b2e8);
  if ((param_1[1] - iVar10 & 1U) == 0) {
    dVar12 = (double)FUN_140332d90();
    *(short *)((longlong)param_1 + 0x42) = 0x4000 - (short)(int)(dVar12 * _DAT_14053aac8);
  }
  dVar12 = DAT_14053a278;
  iVar10 = (int)((ulonglong)lStack_f0 >> 0x20);
  if (param_1[5] == 0) {
    fVar15 = DAT_14053af48;
    if ((-1 < iVar5) && (fVar15 = DAT_14053b380, iVar5 < 0x78)) {
      dVar13 = (double)FUN_140332d90();
      fVar15 = (float)(dVar13 * _DAT_14053b298) + DAT_14053af48;
    }
    param_1[0xd] = fVar15;
    dVar13 = (double)FUN_1403307c0();
    fVar16 = (float)param_1[0xc];
    dVar14 = (double)FUN_140332d90();
    fVar15 = fVar15 + DAT_14053ac5c;
    param_1[10] = (float)(dVar13 * dVar12) + fVar16;
    param_1[0xb] = (float)(dVar14 * dVar12) + fVar15;
    if ((iStack_e4 != 0x46) || (iVar10 != 1)) goto LAB_140032327;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_140032327;
  fVar16 = (float)iVar10 * _DAT_140539ce8 + (float)param_1[0xd];
  param_1[0xd] = fVar16;
  dVar13 = (double)FUN_1403307c0();
  fVar15 = (float)param_1[0xc];
  dVar14 = (double)FUN_140332d90();
  param_1[10] = (float)(dVar13 * dVar12) + fVar15;
  param_1[0xb] = (float)(dVar14 * dVar12) + fVar16 + DAT_14053ac5c;
  if ((-1 < lStack_f0) && (iVar10 < 0x3c)) {
    FUN_140332d90(((double)iVar10 - _DAT_14053b158) * DAT_14053a628 * dVar8 * dVar7);
  }
  if (iVar10 == 0x50) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
LAB_140032327:
  FUN_1403307c0();
  FUN_140332d90();
  FUN_1400c8410(DAT_140e4479c,0xf,7);
  FUN_1400c8410(DAT_140e447a0,0xf,7);
  FUN_1400c8410(DAT_140e450e4,0xf,8);
  uVar9 = DAT_140e44798;
  sVar4 = *(short *)(param_1 + 3);
  uVar2 = param_1[0xd];
  uVar3 = param_1[0xc];
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar11 = uVar9;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[3] = uVar3;
  puVar11[4] = uVar2;
  puVar11[1] = 0xf;
  puVar11[2] = 7;
  *(short *)(puVar11 + 5) = sVar4 * 0xf3c;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  _DAT_140e46ccc = _DAT_140e46ccc + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  uVar9 = DAT_140e44798;
  sVar4 = *(short *)(param_1 + 3);
  uVar2 = param_1[0xd];
  uVar3 = param_1[0xc];
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar11 = uVar9;
  puVar11[1] = 0xf;
  puVar11[2] = 7;
  puVar11[3] = uVar3;
  puVar11[4] = uVar2;
  *(short *)(puVar11 + 5) = sVar4 * 0xf3c + -0x8000;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  _DAT_140e46ccc = _DAT_140e46ccc + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    puVar1 = (undefined8 *)(DAT_140e46c88 + 0x10);
    DAT_140e46c88 = puVar11;
    *puVar1 = puVar11;
    puVar11 = DAT_140e46c88;
  }
  DAT_140e46c88 = puVar11;
  return;
}


