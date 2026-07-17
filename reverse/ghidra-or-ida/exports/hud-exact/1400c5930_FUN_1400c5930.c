// Function: FUN_1400c5930 @ 1400c5930
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c5930(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  float fVar15;

  uVar3 = DAT_140e46afc;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e50 = _DAT_140e46e50 + 1;
  *puVar10 = uVar3;
  iVar13 = 0;
  bVar14 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar10 + 1) = 0x70;
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
  if (bVar14) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar10;
  }
  fVar2 = DAT_14053afa4;
  fVar1 = DAT_14053ac5c;
  DAT_140e46c88 = puVar10;
  if (0 < DAT_1407c77a4) {
    do {
      uVar3 = DAT_140e41934;
      puVar10 = (undefined4 *)_malloc_base(0x48);
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar10 = uVar3;
      puVar10[1] = 0x70;
      puVar10[2] = 1;
      puVar10[4] = 0x41700000;
      *(undefined2 *)(puVar10 + 5) = 0;
      *(undefined8 *)(puVar10 + 6) = 0x3fd999999999999a;
      *(undefined8 *)(puVar10 + 8) = 0x3fd999999999999a;
      puVar10[10] = 0xff;
      puVar10[0xb] = 0xff;
      puVar10[0xc] = 0xff;
      puVar10[0xd] = 0xff;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      puVar10[3] = (float)iVar13 * fVar1 + fVar2;
      _DAT_140e46e50 = _DAT_140e46e50 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar10;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
      iVar13 = iVar13 + 1;
      DAT_140e46c88 = puVar10;
    } while (iVar13 < DAT_1407c77a4);
  }
  uVar9 = _UNK_14053bb28;
  uVar8 = _DAT_14053bb20;
  uVar7 = _UNK_14053baf8;
  uVar6 = _DAT_14053baf0;
  uVar5 = DAT_14053afd8;
  uVar4 = DAT_14053afc0;
  uVar3 = DAT_14053adf8;
  fVar2 = DAT_14053acbc;
  fVar1 = DAT_14053ac70;
  if (DAT_140e41928 == 1) {
    piVar11 = &DAT_140e45cc8;
    iVar13 = 0;
    do {
      iVar12 = iVar13 + 1;
      if (iVar12 < DAT_1407c7798) {
        fVar15 = (float)iVar13 * fVar1 + fVar2;
        FUN_1400c9c90(0,0x70,piVar11[2],uVar4,fVar15,uVar6,uVar7);
        FUN_1400c9c90(0,0x70,piVar11[2] - *piVar11,uVar5,fVar15,uVar6,uVar7);
      }
      if (DAT_1407c7798 == iVar12) {
        fVar15 = (float)iVar13 * fVar1 + fVar2;
        FUN_1400c9c90(0,0x70,DAT_140e451b0,uVar4,fVar15,uVar6,uVar7);
        FUN_1400c9c90(0,0x70,DAT_140e451b0 - *piVar11,uVar5,fVar15,uVar6,uVar7);
      }
      piVar11 = piVar11 + 2;
      iVar13 = iVar12;
    } while (iVar12 < 8);
    FUN_1400c9c90(0,0x70,DAT_140e451b0,DAT_14053afc8,uVar3,uVar8,uVar9);
    FUN_1400c9c90(0,0x70,DAT_140e46bb8,DAT_14053afc8,DAT_14053ae10,uVar8,uVar9);
  }
  if (DAT_140e41928 == 2) {
    FUN_1400c9c90(0,0x70,DAT_140e451b0,DAT_14053afc8,uVar3,uVar8,uVar9);
  }
  return;
}
