// Function: FUN_140288d60 @ 140288d60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140288d60(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  longlong local_78;
  undefined4 local_70;
  longlong local_68;
  longlong local_60;
  int local_58 [2];
  undefined1 *local_50;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_a8;
  local_50 = (undefined1 *)0x0;
  iVar8 = 0;
  local_58[0] = 0;
  local_70 = param_3;
  while (((*(int *)(param_1 + 0x9e0) == 0 || (*(int *)(param_1 + 0x9e4) != 0)) ||
         (local_88 = param_3, iVar4 = FUN_140222ed0(**(undefined8 **)(param_1 + 0xa00),local_58,0),
         iVar4 != 0))) {
    FUN_140267e20(param_1,param_3);
    iVar8 = iVar8 + 1;
    if (2 < iVar8) {
      return 0;
    }
  }
  puVar15 = *(undefined1 **)(param_2 + 8);
  puVar12 = *(undefined1 **)(param_2 + 0x10);
  local_78 = CONCAT44(local_78._4_4_,local_58[0]);
  if (*(int *)(param_1 + 0x9e8) == 0x32315659) {
    if ((*(int *)(param_2 + 0x18) == *(int *)(param_2 + 0x24) * 2) &&
       (*(int *)(param_2 + 0x1c) == *(int *)(param_2 + 0x28) * 2)) {
      puVar10 = puVar12 + 1;
      iVar4 = 0;
      puVar9 = local_50;
      iVar8 = local_58[0];
      if (0 < *(int *)(param_2 + 0x1c)) {
        lVar14 = (longlong)local_58[0];
        do {
          FUN_1401ae2f0(puVar9,puVar15,(longlong)*(int *)(param_2 + 0x18));
          iVar4 = iVar4 + 1;
          puVar15 = puVar15 + *(int *)(param_2 + 0x20);
          puVar9 = puVar9 + lVar14;
        } while (iVar4 < *(int *)(param_2 + 0x1c));
        iVar8 = (int)local_78;
      }
      iVar4 = 0;
      if (0 < *(int *)(param_2 + 0x28)) {
        do {
          iVar7 = 0;
          puVar15 = puVar9;
          if (0 < *(int *)(param_2 + 0x24)) {
            do {
              iVar2 = iVar7 * 2;
              iVar7 = iVar7 + 1;
              *puVar15 = puVar10[iVar2];
              puVar15 = puVar15 + 1;
            } while (iVar7 < *(int *)(param_2 + 0x24));
          }
          iVar4 = iVar4 + 1;
          puVar10 = puVar10 + *(int *)(param_2 + 0x2c);
          puVar9 = puVar9 + iVar8 / 2;
        } while (iVar4 < *(int *)(param_2 + 0x28));
      }
      iVar4 = 0;
      if (0 < *(int *)(param_2 + 0x28)) {
        do {
          iVar7 = 0;
          puVar15 = puVar9;
          if (0 < *(int *)(param_2 + 0x24)) {
            do {
              iVar2 = iVar7 * 2;
              iVar7 = iVar7 + 1;
              *puVar15 = puVar12[iVar2];
              puVar15 = puVar15 + 1;
            } while (iVar7 < *(int *)(param_2 + 0x24));
          }
          iVar4 = iVar4 + 1;
          puVar12 = puVar12 + *(int *)(param_2 + 0x2c);
          puVar9 = puVar9 + iVar8 / 2;
        } while (iVar4 < *(int *)(param_2 + 0x28));
      }
    }
  }
  else {
    lVar14 = (longlong)local_58[0];
    if (*(int *)(param_1 + 0x9e8) == 0x32595559) {
      if ((*(int *)(param_2 + 0x18) == *(int *)(param_2 + 0x24) * 2) &&
         (*(int *)(param_2 + 0x1c) == *(int *)(param_2 + 0x28) * 2)) {
        uVar5 = *(int *)(param_2 + 0x18) / 2;
        uVar6 = *(int *)(param_2 + 0x1c) / 2;
        if (0 < (int)uVar6) {
          local_78 = (longlong)((local_58[0] - *(int *)(param_2 + 0x18)) * 2);
          local_60 = (longlong)(*(int *)(param_2 + 0x2c) + *(int *)(param_2 + 0x24) * -2);
          local_68 = (longlong)(*(int *)(param_2 + 0x20) * 2 - *(int *)(param_2 + 0x18));
          uVar13 = (ulonglong)uVar6;
          puVar10 = local_50;
          do {
            if (0 < (int)uVar5) {
              puVar9 = puVar10 + lVar14;
              uVar11 = (ulonglong)uVar5;
              do {
                *puVar10 = *puVar15;
                puVar10 = puVar10 + 4;
                puVar9[2 - lVar14] = puVar15[1];
                *puVar9 = puVar15[*(int *)(param_2 + 0x20)];
                puVar1 = puVar15 + (longlong)*(int *)(param_2 + 0x20) + 1;
                puVar15 = puVar15 + 2;
                puVar9[2] = *puVar1;
                puVar9[1 - lVar14] = *puVar12;
                puVar9[1] = *puVar12;
                puVar9[3 - lVar14] = puVar12[1];
                puVar1 = puVar12 + 1;
                puVar12 = puVar12 + 2;
                puVar9[3] = *puVar1;
                uVar11 = uVar11 - 1;
                puVar9 = puVar9 + 4;
              } while (uVar11 != 0);
            }
            puVar10 = puVar10 + local_78;
            puVar15 = puVar15 + local_68;
            puVar12 = puVar12 + local_60;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
      }
    }
    else if (((*(int *)(param_1 + 0x9e8) == 0x59565955) &&
             (*(int *)(param_2 + 0x18) == *(int *)(param_2 + 0x24) * 2)) &&
            (*(int *)(param_2 + 0x1c) == *(int *)(param_2 + 0x28) * 2)) {
      iVar8 = *(int *)(param_2 + 0x20);
      iVar4 = *(int *)(param_2 + 0x18);
      iVar7 = *(int *)(param_2 + 0x24);
      iVar2 = *(int *)(param_2 + 0x2c);
      iVar3 = *(int *)(param_2 + 0x18);
      uVar5 = *(int *)(param_2 + 0x18) / 2;
      uVar6 = *(int *)(param_2 + 0x1c) / 2;
      if (0 < (int)uVar6) {
        uVar13 = (ulonglong)uVar6;
        puVar10 = local_50;
        do {
          uVar11 = (ulonglong)uVar5;
          if (0 < (int)uVar5) {
            do {
              puVar10[1] = *puVar15;
              puVar10[3] = puVar15[1];
              puVar10[lVar14 + 1] = puVar15[*(int *)(param_2 + 0x20)];
              puVar9 = puVar15 + (longlong)*(int *)(param_2 + 0x20) + 1;
              puVar15 = puVar15 + 2;
              puVar10[lVar14 + 3] = *puVar9;
              *puVar10 = *puVar12;
              puVar10[lVar14] = *puVar12;
              puVar10[2] = puVar12[1];
              puVar9 = puVar12 + 1;
              puVar12 = puVar12 + 2;
              puVar10[lVar14 + 2] = *puVar9;
              puVar10 = puVar10 + 4;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          puVar10 = puVar10 + (local_58[0] - iVar3) * 2;
          puVar15 = puVar15 + (iVar8 * 2 - iVar4);
          puVar12 = puVar12 + (iVar2 + iVar7 * -2);
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
    }
  }
  FUN_140222fa0(**(undefined8 **)(param_1 + 0xa00),local_70);
  *(undefined4 *)(param_1 + 0x9ec) = 1;
  return 0;
}


