// Function: FUN_140003e60 @ 140003e60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140003e60(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  double dVar9;
  
  uVar4 = DAT_140e445dc;
  uVar3 = DAT_140e445d8;
  uVar2 = DAT_140e445b0;
  if (*(int *)(param_1 + 0xc) == 1) {
    DAT_140e41b08 = 1;
    DAT_140e41a3c = 1;
    DAT_140e41a38 = 1;
    DAT_140e44654 = 0x168;
  }
  iVar7 = 0;
  puVar5 = DAT_140e45d28;
  if ((((*(int *)(param_1 + 0xc) == 0x168) && (0 < DAT_140e445f8)) && (DAT_140e44590 != 0)) &&
     (DAT_140e45d1c < 0x1000)) {
    puVar5 = (undefined8 *)_malloc_base(0x60);
    if (puVar5 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar8 = DAT_140e45d78 == (undefined8 *)0x0;
    *(undefined4 *)((longlong)puVar5 + 0x14) = uVar3;
    *(undefined4 *)(puVar5 + 3) = uVar4;
    *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar3;
    *(undefined4 *)(puVar5 + 4) = uVar4;
    *puVar5 = 1;
    *(undefined4 *)(puVar5 + 1) = 0x29;
    *(undefined4 *)((longlong)puVar5 + 0xc) = uVar2;
    *(undefined4 *)(puVar5 + 2) = 0x73;
    *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
    puVar5[5] = 0;
    puVar5[6] = 0x3ff0000000000000;
    puVar5[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar5 + 8) = 0x78;
    *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
    *(undefined4 *)(puVar5 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
    puVar5[10] = 0xff;
    puVar5[0xb] = 0;
    if (bVar8) {
      DAT_140e45d78 = puVar5;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar5;
    }
  }
  DAT_140e45d28 = puVar5;
  puVar6 = DAT_140e46c88;
  if (DAT_140e41b00 == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((0x1a3 < iVar1) && (iVar7 = 0xff, iVar1 < 600)) {
      dVar9 = (double)FUN_140332d90(((double)iVar1 - DAT_14053a6e0) * DAT_14053a438 * DAT_14053a020
                                    * DAT_140539d28);
      iVar7 = (int)(dVar9 * DAT_14053a5f8);
    }
    uVar2 = DAT_140e41ab8;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e80 = _DAT_140e46e80 + 1;
    bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar6 = uVar2;
    *(undefined8 *)(puVar6 + 1) = 0x7c;
    *(undefined8 *)(puVar6 + 3) = 0;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = iVar7;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar8) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
  }
  DAT_140e46c88 = puVar6;
  if (((DAT_140e41928 == 2) && (0x21b < *(int *)(param_1 + 0xc))) && (DAT_140e41b00 == 0)) {
    transition_tile_wipe_out_candidate(*(int *)(param_1 + 0xc) + -0x21c);
  }
  if (*(int *)(param_1 + 0xc) == 600) {
    DAT_140e418cc = 0;
    DAT_140e41afc = 1;
  }
  return;
}


