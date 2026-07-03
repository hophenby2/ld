// Function: state_2f_system_menu_branch_candidate @ 1400ff2d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_2f_system_menu_branch_candidate(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  double dVar5;
  
  if (DAT_140e418c8 == 1) {
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45110);
    FUN_14018a340(DAT_140e45110,1,1);
  }
  if (DAT_140e418c8 < 0x3c) {
    FUN_1400d4310(DAT_140e418c8);
  }
  if (DAT_140e418c8 == 100) {
    DAT_140e418c8 = 0x5a;
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e418c8 - 0x3dU < 0x28)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e418c8 = 600;
  }
  uVar1 = DAT_140e473a4;
  puVar2 = (undefined4 *)_malloc_base(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46c94 = DAT_140e46c94 + 1;
  *puVar2 = uVar1;
  bVar4 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar2 + 1) = 1;
  *(undefined8 *)(puVar2 + 3) = 0;
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined8 *)(puVar2 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
  puVar2[10] = 0xff;
  puVar2[0xb] = 0xff;
  puVar2[0xc] = 0xff;
  puVar2[0xd] = 0xff;
  *(undefined8 *)(puVar2 + 0xe) = 1;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  if (bVar4) {
    DAT_140e46bf0 = puVar2;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar2;
  }
  DAT_140e46c88 = puVar2;
  dVar5 = (double)FUN_140332d90(((double)DAT_140e451bc - DAT_14053b128) * DAT_14053a798 *
                                DAT_14053a020 * DAT_140539d28);
  FUN_1400d9b60(6,0x7c,0x80 - (int)(dVar5 * DAT_14053b1c8));
  if (0x26b < DAT_140e418c8) {
    FUN_1400d3fd0(DAT_140e418c8 + -0x26c);
  }
  if (DAT_140e418c8 < 0x294) {
    DAT_140e418c8 = DAT_140e418c8 + 1;
    return;
  }
  puVar2 = &DAT_140e45100;
  do {
    FUN_14018f230(*puVar2,0);
    puVar2 = puVar2 + 1;
  } while ((longlong)puVar2 < 0x140e45178);
  FUN_1400f6fb0();
  piVar3 = &DAT_140e46b04;
  DAT_140e473d4 = 1;
  do {
    if (*piVar3 == 1) {
      if (DAT_140e473d4 != 0) {
        DAT_140e418c8 = DAT_140e418c8 + 1;
        DAT_140e45270 = 0x2d;
        return;
      }
      goto LAB_1400ff512;
    }
    DAT_140e473d4 = DAT_140e473d4 + 1;
    piVar3 = piVar3 + 1;
  } while ((longlong)piVar3 < 0x140e46b24);
  DAT_140e473d4 = 0;
LAB_1400ff512:
  DAT_140e418c8 = DAT_140e418c8 + 1;
  DAT_140e45270 = 0x23;
  return;
}


