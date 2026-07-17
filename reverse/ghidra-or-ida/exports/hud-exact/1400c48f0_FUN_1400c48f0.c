// Function: FUN_1400c48f0 @ 1400c48f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c48f0(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  float fVar8;

  iVar1 = DAT_140e41b70;
  if (DAT_140e41b00 == 1) {
    iVar1 = DAT_140e452ec;
  }
  iVar5 = 0;
  FUN_1400c8410(DAT_140e46b4c,param_1,1,param_2,param_3,0,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                0xff,0xff,1,0);
  fVar2 = DAT_14053ac58;
  piVar4 = &DAT_140e445c4;
  fVar8 = param_2 + DAT_14053ad1c;
  do {
    uVar6 = *(undefined4 *)(&DAT_140e46b88 + (longlong)*piVar4 * 4);
    puVar3 = (undefined4 *)_malloc_base(0x48);
    if (puVar3 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar3 = uVar6;
    puVar3[1] = param_1;
    puVar3[2] = 1;
    *(undefined2 *)(puVar3 + 5) = 0;
    *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
    puVar3[4] = param_3;
    *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
    puVar3[10] = 0xff;
    puVar3[0xb] = 0xff;
    puVar3[0xc] = 0xff;
    puVar3[0xd] = 0xff;
    *(undefined8 *)(puVar3 + 0xe) = 1;
    *(undefined8 *)(puVar3 + 0x10) = 0;
    puVar3[3] = (float)iVar5 * fVar2 + fVar8;
    (&DAT_140e46c90)[param_1] = (&DAT_140e46c90)[param_1] + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar3;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 1;
    DAT_140e46c88 = puVar3;
  } while (iVar5 < 4);
  uVar6 = DAT_140e46b98;
  if (iVar1 != 0) {
    uVar6 = DAT_140e46b9c;
  }
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  param_2 = param_2 + DAT_14053ae00;
  puVar3[4] = param_3;
  (&DAT_140e46c90)[param_1] = (&DAT_140e46c90)[param_1] + 1;
  bVar7 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  puVar3[3] = param_2;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  puVar3[0xd] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[10] = 0xff;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined2 *)(puVar3 + 5) = 0;
  puVar3[2] = 1;
  puVar3[1] = param_1;
  *puVar3 = uVar6;
  if (bVar7) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  DAT_140e46c88 = puVar3;
  return;
}
