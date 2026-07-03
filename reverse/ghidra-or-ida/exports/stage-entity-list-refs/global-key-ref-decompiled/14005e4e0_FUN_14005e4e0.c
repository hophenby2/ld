// Function: FUN_14005e4e0 @ 14005e4e0
// Decompile completed: true

void FUN_14005e4e0(undefined4 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iStack_a4;
  
  lVar1 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        iStack_a4 = *(int *)(lVar1 + 0x14);
      }
    }
  }
  if ((iStack_a4 == 0x50) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  iVar6 = param_1[5];
  if (iVar6 == 0) {
    if (param_1[3] == 0) {
      stage_entity_spawn_candidate(0x116,7000,0x50);
      stage_entity_spawn_candidate(0x117,7000,0x50);
    }
    if (param_1[3] == 0xbe) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  else if (iVar6 == 1) {
    uVar3 = 0x14;
    uVar4 = 0;
    do {
      uVar2 = uVar4 & 3;
      iVar6 = (uVar2 == 1) + 0x118;
      if (uVar2 == 2) {
        iVar6 = 0x116;
      }
      else if (uVar2 == 3) {
        iVar6 = 0x117;
      }
      uVar2 = param_1[3];
      if (((int)uVar2 < 0x14) || ((int)uVar3 <= (int)uVar2)) {
        if (uVar2 == uVar3) goto LAB_14005e652;
      }
      else if (DAT_140e44e6c < 3) {
        param_1[3] = uVar3;
        uVar2 = uVar3;
LAB_14005e652:
        if (uVar4 == (uVar4 / 3) * 3) {
          uVar2 = (uVar2 >> 0x1e ^ uVar2) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar2 >> 0x1e ^ uVar2) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar2 = uVar2 * 0x800 ^ uVar2;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar2) >> 8 ^ DAT_140e9fd18 ^ uVar2;
        }
        else if ((uVar4 % 3 != 1) && (uVar4 % 3 != 2)) goto LAB_14005e759;
        stage_entity_spawn_candidate(iVar6,10000,0x50);
      }
LAB_14005e759:
      uVar5 = uVar4 + 1;
      uVar2 = uVar3 + 0x104;
      if (uVar4 % 3 == 1) {
        uVar2 = uVar3;
      }
      uVar3 = uVar2;
      uVar4 = uVar5;
    } while ((int)uVar5 < 0x1e);
  }
  else if ((iVar6 == 99) && (param_1[3] == 0x8c)) {
    *param_1 = 0;
  }
  return;
}


