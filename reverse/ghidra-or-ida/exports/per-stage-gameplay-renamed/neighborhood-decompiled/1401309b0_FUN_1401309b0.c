// Function: FUN_1401309b0 @ 1401309b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401309b0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  double dVar5;
  
  iVar2 = DAT_140e418c8;
  if (DAT_140e418c8 < 100) {
    dVar5 = 0.0;
  }
  else {
    dVar5 = DAT_140539f40;
    if (DAT_140e418c8 < 0x78) {
      dVar5 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a460) * DAT_14053a890 *
                                    DAT_14053a020 * DAT_140539d28);
      dVar5 = dVar5 + 0.0;
    }
    if (iVar2 == 100) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
      FUN_14018a340(DAT_140e4721c,1,1);
    }
  }
  uVar1 = (&DAT_140e477d8)[param_2];
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(double *)(puVar3 + 8) = dVar5;
  *puVar3 = uVar1;
  puVar3[1] = 0x6e;
  puVar3[2] = 1;
  puVar3[3] = 0x44200000;
  puVar3[4] = 0x43b40000;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar3;
  }
  DAT_140e46c88 = puVar3;
  bVar4 = false;
  if (((DAT_140e467c8 == 1) && (bVar4 = false, DAT_140e467fc == 0)) && (0xdb < DAT_140e418c8)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    bVar4 = true;
    DAT_140e467fc = 1;
  }
  if ((DAT_140e467c8 == 0) && (DAT_140e45270 == 0x15)) {
    DAT_140e467fc = 0;
  }
  if (bVar4) {
    DAT_140e418c8 = 0x4f;
    DAT_140e46804 = param_1;
    FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  return;
}


