// Function: FUN_1401e1e80 @ 1401e1e80
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1401e1e80(longlong param_1,longlong param_2,longlong param_3,int param_4,int param_5,
                  int param_6,int param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  uint *puVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  undefined8 uVar13;
  uint3 *puVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  longlong lVar18;
  ulonglong uVar19;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  longlong local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  longlong local_b8;
  undefined8 local_b0;
  int *local_a8;
  undefined4 local_a0;
  int local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  ulonglong local_40;
  
  local_40 = DAT_1407c6b00 ^ (ulonglong)auStack_f8;
  lVar3 = *(longlong *)(param_3 + 0x20);
  local_58 = param_8;
  uStack_54 = param_9;
  local_48 = param_4 + param_6;
  local_44 = param_5 + param_7;
  uVar13 = *(undefined8 *)(param_1 + 0x438);
  local_4c = param_5;
  uVar4 = *(undefined8 *)(lVar3 + 0x18);
  local_68 = 0;
  local_70 = 0;
  local_d0 = param_1;
  local_50 = param_4;
  if (*(int *)(lVar3 + 0x28) - 2U < 2) {
    local_a8 = &local_50;
    local_78 = 1;
    local_80 = 1;
    local_88 = 0;
    local_90 = 0;
    local_98 = 0;
    local_a0 = 0;
    local_b0 = CONCAT44(param_9,param_8);
    local_d8 = *(undefined4 *)(param_1 + 0x430);
    local_b8 = 0;
    local_c0 = 0;
    local_c8 = 0;
    FUN_14017ae00(*(undefined8 *)(param_3 + 0x10),*(undefined4 *)(lVar3 + 0xc),uVar4,uVar13);
  }
  else {
    local_90 = *(undefined4 *)(lVar3 + 0x24);
    local_78 = 0;
    local_80 = 0;
    local_88 = 0;
    local_a8 = &local_50;
    local_98 = param_10;
    local_a0 = 0;
    local_b0 = CONCAT44(param_9,param_8);
    if (param_2 == 0) {
      local_d8 = *(undefined4 *)(param_1 + 0x430);
      local_b8 = 0;
      local_c0 = 0;
      local_c8 = 0;
      iVar7 = FUN_14017ae00(*(undefined8 *)(param_3 + 0x10),*(undefined4 *)(lVar3 + 0xc),uVar4,
                            uVar13);
      if (iVar7 < 0) {
        return;
      }
      if (*(int *)(*(longlong *)(param_3 + 0x20) + 0x2c) == 1) {
        *(int *)(*(longlong *)(param_3 + 0x20) + 0x30) = iVar7 + 1;
      }
    }
    else {
      local_c0 = *(undefined4 *)(param_2 + 0x430);
      local_c8 = *(undefined8 *)(param_2 + 0x438);
      local_d8 = *(undefined4 *)(param_1 + 0x430);
      local_b8 = param_2;
      iVar7 = FUN_14017ae00(*(undefined8 *)(param_3 + 0x10),*(undefined4 *)(lVar3 + 0xc),uVar4,
                            uVar13);
      if (iVar7 < 0) {
        return;
      }
    }
  }
  lVar3 = *(longlong *)(param_3 + 0x20);
  if (*(int *)(lVar3 + 0x2c) == 1) {
    puVar14 = (uint3 *)(param_1 + 0x28);
    puVar9 = *(uint **)(lVar3 + 0x48);
    lVar18 = 0x100;
    if (*(int *)(lVar3 + 0x28) == 0) {
      do {
        *(ushort *)puVar9 =
             ((*(byte *)((longlong)puVar14 + 2) & 0xfff8) << 5 |
             *(byte *)((longlong)puVar14 + 1) & 0xfffc) << 3 | (ushort)(byte)((byte)*puVar14 >> 3);
        lVar18 = lVar18 + -1;
        puVar9 = (uint *)((longlong)puVar9 + 2);
        puVar14 = puVar14 + 1;
      } while (lVar18 != 0);
      uVar13 = 0x200;
    }
    else {
      do {
        *puVar9 = (uint)*puVar14;
        lVar18 = lVar18 + -1;
        puVar9 = puVar9 + 1;
        puVar14 = puVar14 + 1;
      } while (lVar18 != 0);
      uVar13 = 0x400;
    }
    FUN_1401ae2f0(*(undefined8 *)(*(longlong *)(param_3 + 0x20) + 0x50),
                  *(undefined8 *)(*(longlong *)(param_3 + 0x20) + 0x48),uVar13);
  }
  lVar3 = *(longlong *)(param_3 + 0x20);
  if ((*(uint *)(lVar3 + 0x28) < 2) && (*(int *)(lVar3 + 0x34) == 0)) {
    *(uint *)(lVar3 + 0x20) = (uint)(param_10 != 0);
  }
  *(undefined4 *)(*(longlong *)(param_3 + 0x20) + 0x38) = 0;
  *(undefined4 *)(*(longlong *)(param_3 + 0x20) + 0x3c) = 0;
  if ((((param_6 == *(int *)(param_3 + 4)) && (param_7 == *(int *)(param_3 + 8))) &&
      (lVar3 = *(longlong *)(param_3 + 0x20), *(uint *)(lVar3 + 0x28) < 2)) &&
     (*(longlong *)(lVar3 + 0x68) != 0)) {
    *(undefined4 *)(lVar3 + 0x3c) = 1;
    lVar3 = *(longlong *)(param_3 + 0x20);
    uVar17 = *(uint *)(lVar3 + 0x24);
    if ((*(int *)(lVar3 + 0x34) == 1) && (*(longlong *)(lVar3 + 0x60) != 0)) {
      *(undefined4 *)(lVar3 + 0x38) = 1;
      puVar9 = *(uint **)(param_3 + 0x18);
      puVar8 = *(ushort **)(param_3 + 0x10);
      iVar7 = *(int *)(*(longlong *)(param_3 + 0x20) + 0xc) + *(int *)(param_3 + 4) * -4;
      if (*(int *)(*(longlong *)(param_3 + 0x20) + 0x28) == 0) {
        iVar11 = *(int *)(param_3 + 8);
        iVar12 = param_6;
        do {
          do {
            uVar2 = *puVar8;
            bVar15 = (byte)puVar8[1];
            *puVar9 = ((uVar2 & 0xf800) * (uint)bVar15 & 0xf80000 |
                       (uVar2 & 0x7e0) * (uint)bVar15 & 0x7e000 |
                      (uVar2 & 0x1f) * (uint)bVar15 & 0x1f00) >> 8;
            puVar1 = puVar8 + 1;
            puVar8 = puVar8 + 2;
            *(byte *)((longlong)puVar9 + 2) = (byte)*puVar1;
            puVar9 = puVar9 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          puVar8 = (ushort *)((longlong)puVar8 + (longlong)iVar7);
          puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar7);
          iVar11 = iVar11 + -1;
          iVar12 = param_6;
        } while (iVar11 != 0);
      }
      else {
        iVar11 = *(int *)(param_3 + 8);
        iVar12 = param_6;
        do {
          do {
            *(char *)puVar9 =
                 (char)((uint)(byte)*puVar8 * (uint)*(byte *)((longlong)puVar8 + 3) >> 8);
            *(char *)((longlong)puVar9 + 1) =
                 (char)((uint)*(byte *)((longlong)puVar8 + 1) *
                        (uint)*(byte *)((longlong)puVar8 + 3) >> 8);
            *(char *)((longlong)puVar9 + 2) =
                 (char)((uint)(byte)puVar8[1] * (uint)*(byte *)((longlong)puVar8 + 3) >> 8);
            puVar1 = puVar8 + 1;
            puVar8 = puVar8 + 2;
            *(byte *)((longlong)puVar9 + 3) = (byte)*puVar1;
            puVar9 = puVar9 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          puVar8 = (ushort *)((longlong)puVar8 + (longlong)iVar7);
          puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar7);
          iVar11 = iVar11 + -1;
          iVar12 = param_6;
        } while (iVar11 != 0);
      }
    }
    lVar3 = *(longlong *)(param_3 + 0x20);
    puVar9 = *(uint **)(param_3 + 0x10);
    pbVar5 = *(byte **)(lVar3 + 0x68);
    iVar7 = *(int *)(param_3 + 8);
    lVar18 = (longlong)
             (int)(*(int *)(lVar3 + 0xc) -
                  (uint)*(byte *)(*(longlong *)(lVar3 + 0x18) + 4) * *(int *)(param_3 + 4));
    iVar11 = param_6;
    if (*(int *)(lVar3 + 0x2c) == 1) {
      do {
        do {
          pbVar10 = pbVar5;
          uVar6 = *puVar9;
          uVar16 = 1;
          puVar9 = (uint *)((longlong)puVar9 + 1);
          if ((byte)uVar6 == uVar17) {
            iVar11 = iVar11 + -1;
            if (iVar11 != 0) {
              do {
                if ((byte)*puVar9 != uVar17) break;
                puVar9 = (uint *)((longlong)puVar9 + 1);
                uVar16 = uVar16 + 1;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0 && uVar16 < 0x40);
            }
            bVar15 = (char)uVar16 - 1;
          }
          else {
            iVar11 = iVar11 + -1;
            if (iVar11 != 0) {
              do {
                if ((byte)*puVar9 == uVar17) break;
                puVar9 = (uint *)((longlong)puVar9 + 1);
                uVar16 = uVar16 + 1;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0 && uVar16 < 0x40);
            }
            bVar15 = (char)uVar16 - 1U | 0x40;
          }
          *pbVar10 = bVar15;
          pbVar5 = pbVar10 + 1;
        } while (iVar11 != 0);
        pbVar10[1] = 0xc0;
        puVar9 = (uint *)((longlong)puVar9 + lVar18);
        iVar7 = iVar7 + -1;
        pbVar5 = pbVar10 + 2;
        iVar11 = param_6;
      } while (iVar7 != 0);
    }
    else if (*(int *)(lVar3 + 0x34) == 0) {
      if (*(int *)(lVar3 + 0x28) == 0) {
        do {
          do {
            pbVar10 = pbVar5;
            uVar6 = *puVar9;
            uVar16 = 1;
            puVar9 = (uint *)((longlong)puVar9 + 2);
            if ((ushort)uVar6 == uVar17) {
              iVar11 = iVar11 + -1;
              if (iVar11 != 0) {
                do {
                  if ((ushort)*puVar9 != uVar17) break;
                  puVar9 = (uint *)((longlong)puVar9 + 2);
                  uVar16 = uVar16 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0 && uVar16 < 0x40);
              }
              bVar15 = (char)uVar16 - 1;
            }
            else {
              iVar11 = iVar11 + -1;
              if (iVar11 != 0) {
                do {
                  if ((ushort)*puVar9 == uVar17) break;
                  puVar9 = (uint *)((longlong)puVar9 + 2);
                  uVar16 = uVar16 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0 && uVar16 < 0x40);
              }
              bVar15 = (char)uVar16 - 1U | 0x40;
            }
            *pbVar10 = bVar15;
            pbVar5 = pbVar10 + 1;
          } while (iVar11 != 0);
          pbVar10[1] = 0xc0;
          puVar9 = (uint *)((longlong)puVar9 + lVar18);
          iVar7 = iVar7 + -1;
          pbVar5 = pbVar10 + 2;
          iVar11 = param_6;
        } while (iVar7 != 0);
      }
      else {
        do {
          do {
            pbVar10 = pbVar5;
            uVar6 = *puVar9;
            uVar16 = 1;
            puVar9 = puVar9 + 1;
            if (uVar6 == uVar17) {
              iVar11 = iVar11 + -1;
              if (iVar11 != 0) {
                do {
                  if (*puVar9 != uVar17) break;
                  puVar9 = puVar9 + 1;
                  uVar16 = uVar16 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0 && uVar16 < 0x40);
              }
              bVar15 = (char)uVar16 - 1;
            }
            else {
              iVar11 = iVar11 + -1;
              if (iVar11 != 0) {
                do {
                  if (*puVar9 == uVar17) break;
                  puVar9 = puVar9 + 1;
                  uVar16 = uVar16 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0 && uVar16 < 0x40);
              }
              bVar15 = (char)uVar16 - 1U | 0x40;
            }
            *pbVar10 = bVar15;
            pbVar5 = pbVar10 + 1;
          } while (iVar11 != 0);
          pbVar10[1] = 0xc0;
          puVar9 = (uint *)((longlong)puVar9 + lVar18);
          iVar7 = iVar7 + -1;
          pbVar5 = pbVar10 + 2;
          iVar11 = param_6;
        } while (iVar7 != 0);
      }
    }
    else {
      uVar19 = (ulonglong)(*(int *)(lVar3 + 0x28) != 0);
      do {
        do {
          pbVar10 = pbVar5;
          bVar15 = *(byte *)(uVar19 + 2 + (longlong)puVar9);
          puVar9 = puVar9 + 1;
          uVar17 = 1;
          if (bVar15 == 0) {
            iVar11 = iVar11 + -1;
            if (iVar11 != 0) {
              do {
                if (*(byte *)((longlong)puVar9 + uVar19 + 2) != 0) break;
                puVar9 = puVar9 + 1;
                uVar17 = uVar17 + 1;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0 && uVar17 < 0x40);
            }
            bVar15 = (char)uVar17 - 1;
          }
          else if (bVar15 == 0xff) {
            iVar11 = iVar11 + -1;
            if (iVar11 != 0) {
              do {
                if (*(byte *)((longlong)puVar9 + uVar19 + 2) != 0xff) break;
                puVar9 = puVar9 + 1;
                uVar17 = uVar17 + 1;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0 && uVar17 < 0x40);
            }
            bVar15 = (char)uVar17 - 1U | 0x40;
          }
          else {
            iVar11 = iVar11 + -1;
            if (iVar11 != 0) {
              do {
                if (0xfd < (byte)(*(byte *)((longlong)puVar9 + uVar19 + 2) - 1)) break;
                puVar9 = puVar9 + 1;
                uVar17 = uVar17 + 1;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0 && uVar17 < 0x40);
            }
            bVar15 = (char)uVar17 - 1U | 0x80;
          }
          *pbVar10 = bVar15;
          pbVar5 = pbVar10 + 1;
        } while (iVar11 != 0);
        pbVar10[1] = 0xc0;
        puVar9 = (uint *)((longlong)puVar9 + lVar18);
        iVar7 = iVar7 + -1;
        pbVar5 = pbVar10 + 2;
        iVar11 = param_6;
      } while (iVar7 != 0);
    }
  }
  return;
}


