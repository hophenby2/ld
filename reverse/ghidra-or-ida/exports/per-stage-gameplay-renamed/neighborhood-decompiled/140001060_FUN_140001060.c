// Function: FUN_140001060 @ 140001060
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001060(int param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  longlong local_res10;
  undefined4 in_stack_fffffffffffffee0;
  ushort uVar21;
  undefined4 uVar20;
  
  dVar14 = DAT_14053a628;
  dVar17 = DAT_14053a4b8;
  dVar15 = DAT_14053a020;
  dVar16 = DAT_140539d28;
  uVar21 = (ushort)((uint)in_stack_fffffffffffffee0 >> 0x10);
  uVar9 = DAT_140e418c8 - param_1;
  iVar8 = ((int)uVar9 >> 0x1f & 0xffffff80U) + 0x80;
  if ((-1 < (int)uVar9) && ((int)uVar9 < 0x3c)) {
    dVar13 = (double)FUN_140332d90(((double)(int)uVar9 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                   DAT_140539d28);
    iVar8 = (int)(dVar13 * dVar17);
  }
  if (uVar9 - 0xf0 < 0x3c) {
    dVar13 = (double)FUN_140332d90(((double)(int)uVar9 - DAT_14053a548) * dVar14 * dVar15 * dVar16);
    iVar8 = (int)(dVar13 * dVar17);
  }
  dVar17 = DAT_14053a5f8;
  iVar11 = 0;
  if ((int)uVar9 < 300) {
    iVar11 = iVar8;
  }
  iVar8 = ((int)uVar9 >> 0x1f & 0xffffff01U) + 0xff;
  if ((-1 < (int)uVar9) && ((int)uVar9 < 0x3c)) {
    dVar14 = (double)FUN_140332d90(((double)(int)uVar9 - 0.0) * dVar14 * dVar15 * dVar16);
    iVar8 = (int)(dVar14 * dVar17);
  }
  if (uVar9 - 0x10e < 0x1e) {
    dVar14 = (double)FUN_140332d90(((double)(int)uVar9 - DAT_14053a5e8) * DAT_14053a798 * dVar15 *
                                   dVar16);
    iVar8 = (int)(dVar14 * dVar17);
  }
  dVar15 = (double)FUN_140332d90(((double)(int)uVar9 - 0.0) * DAT_14053aa88 * dVar15 * dVar16);
  dVar16 = DAT_140539f40;
  iVar10 = 0;
  if ((int)uVar9 < 300) {
    iVar10 = iVar8;
  }
  iVar8 = (iVar10 - (int)(dVar15 * DAT_14053b140)) + -0x30;
  dVar15 = DAT_14053a0b0;
  if ((-1 < (int)uVar9) &&
     (((int)uVar9 < 0x3c ||
      ((dVar15 = DAT_140539f40, 0x10d < (int)uVar9 && (dVar15 = DAT_14053a0b0, (int)uVar9 < 300)))))
     ) {
    dVar15 = (double)FUN_140332d90();
    dVar15 = dVar15 * DAT_14053b0b0 + DAT_14053a0b0;
  }
  fVar3 = DAT_14053ae14;
  uVar20 = (undefined4)((ulonglong)dVar15 >> 0x20);
  FUN_1400c8410(DAT_140e41b04,99,1,DAT_14053aedc,DAT_14053ae14,(uint)uVar21 << 0x10,dVar16,dVar15,
                0xff,0xff,0xff,iVar8,1,0);
  fVar5 = DAT_14053b00c;
  fVar4 = DAT_14053ae50;
  dVar16 = dVar15 * DAT_14053a430;
  fVar19 = (float)((int)uVar9 % 0x69) * DAT_14053a770;
  iVar10 = 0;
  do {
    uVar6 = DAT_140e41ac0;
    fVar18 = (float)iVar10 * fVar4 + fVar19;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[3] = fVar18;
    puVar7[4] = fVar3 - (float)dVar16;
    *puVar7 = uVar6;
    puVar7[1] = 99;
    puVar7[2] = 1;
    *(undefined2 *)(puVar7 + 5) = 0;
    auVar1._8_4_ = SUB84(dVar15,0);
    auVar1._0_8_ = dVar15;
    auVar1._12_4_ = uVar20;
    *(undefined1 (*) [16])(puVar7 + 6) = auVar1;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0x40;
    puVar7[0xd] = iVar8;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46e1c = _DAT_140e46e1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar6 = DAT_140e41ac0;
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[4] = (float)dVar16 + fVar3;
    *puVar7 = uVar6;
    puVar7[1] = 99;
    puVar7[2] = 1;
    *(undefined2 *)(puVar7 + 5) = 0;
    auVar2._8_4_ = SUB84(dVar15,0);
    auVar2._0_8_ = dVar15;
    auVar2._12_4_ = uVar20;
    *(undefined1 (*) [16])(puVar7 + 6) = auVar2;
    puVar7[10] = 0xff;
    puVar7[3] = fVar5 - fVar18;
    puVar7[0xb] = 0x40;
    puVar7[0xc] = 0x40;
    puVar7[0xd] = iVar8;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46e1c = _DAT_140e46e1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    iVar10 = iVar10 + 1;
    DAT_140e46c88 = puVar7;
  } while (iVar10 < 4);
  if (DAT_1407c7798 == 9) {
    FUN_14012e8e0(0xb7,0xc,uVar9,0,0xa0,1);
    iVar10 = 0xb8;
    iVar8 = DAT_1407c7798 + 3;
    uVar20 = 1;
  }
  else {
    FUN_14012e8e0(DAT_1407c7798 * 10 + 0x5d + DAT_140e445c0,DAT_1407c7798 + 3,uVar9,0,0xa0,1);
    if (DAT_1407c7798 == 7) {
      FUN_14012e8e0(DAT_140e445c0 + 200,0xf,uVar9,0,0xa0,2);
    }
    uVar20 = 0;
    iVar10 = DAT_140e445c0 + (DAT_1407c7798 * 5 + 0x30) * 2;
    iVar8 = DAT_140e445c0;
  }
  FUN_14012e8e0(iVar10,iVar8,uVar9,0x8c,300,uVar20);
  uVar20 = DAT_140e41ab8;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  bVar12 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar7 = uVar20;
  *(undefined8 *)(puVar7 + 1) = 0x1d;
  *(undefined8 *)(puVar7 + 3) = 0;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 10) = 0;
  puVar7[0xc] = 0;
  puVar7[0xd] = iVar11;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar12) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  iVar8 = DAT_140e418c8 % 0xd2;
  DAT_140e46c88 = puVar7;
  dVar16 = (double)FUN_140332d90();
  dVar16 = dVar16 * _DAT_14053b110;
  dVar15 = (double)FUN_1403307c0(DAT_14053a0f0);
  dVar17 = (double)FUN_140332d90(DAT_14053a0f0);
  dVar14 = (double)FUN_1403307c0(DAT_14053a0a8);
  dVar13 = (double)FUN_140332d90(DAT_14053a0a8);
  fVar4 = DAT_14053b018;
  fVar3 = DAT_14053afb0;
  iVar8 = iVar8 * 2;
  local_res10 = 7;
  do {
    iVar11 = 0;
    do {
      uVar20 = DAT_140e41ac0;
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar7[3] = (float)((double)iVar11 * dVar14) + ((float)((double)iVar8 * dVar15) - fVar3);
      puVar7[4] = (float)((double)iVar11 * dVar13) + (float)((double)iVar8 * dVar17) + fVar4;
      *puVar7 = uVar20;
      puVar7[1] = 0x1d;
      puVar7[2] = 7;
      *(undefined2 *)(puVar7 + 5) = 0xeee0;
      *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xd] = 0x14 - (int)dVar16;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      _DAT_140e46d04 = _DAT_140e46d04 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
      iVar11 = iVar11 + 0x3c;
      DAT_140e46c88 = puVar7;
    } while (iVar11 < 0x780);
    iVar8 = iVar8 + 0x1a4;
    local_res10 = local_res10 + -1;
  } while (local_res10 != 0);
  if ((uVar9 < 0x10e) && (uVar9 == ((int)uVar9 / 0x14) * 0x14)) {
    FUN_140184700(DAT_140e44190 * 0x14,DAT_140e472b0);
    FUN_14018a340(DAT_140e472b0,1,1);
  }
  return;
}


