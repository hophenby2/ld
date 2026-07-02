// Function: FUN_1401823d0 @ 1401823d0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401823d0(undefined8 param_1,longlong param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  uint uVar17;
  ushort *puVar18;
  int iVar19;
  uint uVar20;
  undefined1 auStack_d8 [32];
  uint *local_b8;
  uint *local_b0;
  uint *local_a8;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  uint local_84 [2];
  int local_7c;
  uint local_78;
  uint local_74;
  longlong local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined2 local_58;
  int local_56;
  int local_4e;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_d8;
  puVar7 = (undefined4 *)0x0;
  lVar8 = 0;
  uVar11 = 0xffffffff;
  local_60 = param_1;
  FUN_1401ae370(&local_58,0,0xe);
  cVar1 = *(char *)(param_2 + 5);
  local_58 = 0x4d42;
  local_4e = 0x36;
  local_56 = 0x36;
  if (cVar1 == '\b') {
    puVar7 = (undefined4 *)
             FUN_1401b6560(0x42c,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x1b5)
    ;
    if (puVar7 == (undefined4 *)0x0) {
LAB_140182483:
      FUN_1401594b0(&DAT_1404a86f0);
      return 0xffffffff;
    }
    iVar13 = *(int *)(param_2 + 0x428) + 3;
    uVar20 = (iVar13 >> 0x1f & 3U) + iVar13 & 0xfffffffc;
    lVar8 = FUN_1401b6560((longlong)(int)(*(int *)(param_2 + 0x42c) * uVar20),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x1bf);
    if (lVar8 == 0) {
      FUN_1401594b0(&DAT_1404a8730);
      goto LAB_140182bd5;
    }
    puVar14 = puVar7 + 10;
    lVar9 = (longlong)puVar7 - param_2;
    lVar16 = 0x40;
    puVar15 = (undefined1 *)(param_2 + 0x2a);
    do {
      *(undefined1 *)puVar14 = puVar15[-2];
      puVar14 = puVar14 + 4;
      puVar15[lVar9 + -1] = puVar15[-1];
      puVar15[lVar9] = *puVar15;
      puVar15[lVar9 + 1] = 0;
      puVar15[lVar9 + 2] = puVar15[2];
      puVar15[lVar9 + 3] = puVar15[3];
      puVar15[lVar9 + 4] = puVar15[4];
      puVar15[lVar9 + 5] = 0;
      puVar15[lVar9 + 6] = puVar15[6];
      puVar15[lVar9 + 7] = puVar15[7];
      puVar15[lVar9 + 8] = puVar15[8];
      puVar15[lVar9 + 9] = 0;
      puVar15[lVar9 + 10] = puVar15[10];
      puVar15[lVar9 + 0xb] = puVar15[0xb];
      puVar15[lVar9 + 0xc] = puVar15[0xc];
      puVar15[lVar9 + 0xd] = 0;
      lVar16 = lVar16 + -1;
      puVar15 = puVar15 + 0x10;
    } while (lVar16 != 0);
    local_4e = local_4e + 0x400;
    local_56 = *(int *)(param_2 + 0x42c) * uVar20 + local_56 + 0x400;
    *(undefined2 *)((longlong)puVar7 + 0xe) = 8;
    *puVar7 = 0x28;
    puVar7[1] = *(undefined4 *)(param_2 + 0x428);
    puVar7[2] = *(undefined4 *)(param_2 + 0x42c);
    *(undefined2 *)(puVar7 + 3) = 1;
    puVar7[4] = 0;
    uVar17 = *(int *)(param_2 + 0x42c) - 1;
    if (-1 < (int)uVar17) {
      iVar13 = 0;
      do {
        FUN_1401ae2f0(iVar13 + lVar8,
                      (longlong)(int)(*(int *)(param_2 + 0x430) * uVar17) +
                      *(longlong *)(param_2 + 0x438),(longlong)*(int *)(param_2 + 0x428));
        uVar17 = uVar17 - 1;
        iVar13 = iVar13 + uVar20;
      } while (uVar17 < 0x80000000);
    }
    thunk_FUN_1401b9570(param_1);
    lVar9 = thunk_FUN_1401b95b0(param_1);
    if (lVar9 == 0) {
      FUN_1401594b0(&DAT_1404a8760);
      uVar11 = 0xffffffff;
      goto LAB_140182bd5;
    }
    thunk_FUN_1401b96b0(lVar9,&local_58,0xe);
    thunk_FUN_1401b96b0(lVar9,puVar7,0x428,0);
    iVar13 = *(int *)(param_2 + 0x42c) * uVar20;
LAB_140182bbd:
    thunk_FUN_1401b96b0(lVar9,lVar8,iVar13,0);
    thunk_FUN_1401b9530(lVar9);
  }
  else if (((cVar1 - 0x10U & 0xe7) == 0) && (cVar1 != '(')) {
    puVar7 = (undefined4 *)
             FUN_1401b6560(0x2c,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x203);
    local_68 = puVar7;
    if (puVar7 == (undefined4 *)0x0) goto LAB_140182483;
    iVar13 = (*(int *)(param_2 + 0x428) + 1) * 3;
    uVar20 = (iVar13 >> 0x1f & 3U) + iVar13 & 0xfffffffc;
    local_90 = uVar20;
    lVar8 = FUN_1401b6560((longlong)(int)(*(int *)(param_2 + 0x42c) * uVar20),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp");
    local_70 = lVar8;
    if (lVar8 == 0) {
      FUN_1401594b0(&DAT_1404a8730);
      uVar11 = 0xffffffff;
      goto LAB_140182bd5;
    }
    local_56 = local_56 + *(int *)(param_2 + 0x42c) * uVar20;
    *(undefined2 *)((longlong)puVar7 + 0xe) = 0x18;
    *puVar7 = 0x28;
    puVar7[1] = *(undefined4 *)(param_2 + 0x428);
    puVar7[2] = *(undefined4 *)(param_2 + 0x42c);
    *(undefined2 *)(puVar7 + 3) = 1;
    puVar7[4] = 0;
    uVar17 = *(uint *)(param_2 + 0x18);
    if ((((uVar17 == 0xff0000) && (*(int *)(param_2 + 0x14) == 0xff00)) &&
        (*(int *)(param_2 + 0x10) == 0xff)) && (*(char *)(param_2 + 4) == '\x04')) {
      uVar17 = *(int *)(param_2 + 0x42c) - 1;
      if (-1 < (int)uVar17) {
        iVar13 = *(int *)(param_2 + 0x428);
        iVar19 = 0;
        do {
          iVar12 = 0;
          puVar15 = (undefined1 *)(iVar19 + lVar8);
          puVar10 = (undefined1 *)
                    ((longlong)(int)(*(int *)(param_2 + 0x430) * uVar17) +
                    *(longlong *)(param_2 + 0x438));
          if (0 < iVar13) {
            do {
              iVar12 = iVar12 + 1;
              *puVar15 = puVar10[2];
              puVar15[1] = puVar10[1];
              puVar15[2] = *puVar10;
              iVar13 = *(int *)(param_2 + 0x428);
              puVar15 = puVar15 + 3;
              puVar10 = puVar10 + 4;
            } while (iVar12 < iVar13);
          }
          uVar17 = uVar17 - 1;
          iVar19 = iVar19 + uVar20;
        } while (uVar17 < 0x80000000);
      }
    }
    else if (uVar17 == 0xff) {
      if (((*(int *)(param_2 + 0x14) == 0xff00) && (*(int *)(param_2 + 0x10) == 0xff0000)) &&
         (*(char *)(param_2 + 4) == '\x04')) {
        uVar17 = *(int *)(param_2 + 0x42c) - 1;
        if (-1 < (int)uVar17) {
          iVar13 = *(int *)(param_2 + 0x428);
          iVar19 = 0;
          do {
            iVar12 = 0;
            puVar15 = (undefined1 *)(iVar19 + lVar8);
            puVar10 = (undefined1 *)
                      ((longlong)(int)(*(int *)(param_2 + 0x430) * uVar17) +
                      *(longlong *)(param_2 + 0x438));
            if (0 < iVar13) {
              do {
                *puVar15 = *puVar10;
                iVar12 = iVar12 + 1;
                puVar15[1] = puVar10[1];
                puVar15[2] = puVar10[2];
                iVar13 = *(int *)(param_2 + 0x428);
                puVar15 = puVar15 + 3;
                puVar10 = puVar10 + 4;
              } while (iVar12 < iVar13);
            }
            uVar17 = uVar17 - 1;
            iVar19 = iVar19 + uVar20;
          } while (uVar17 < 0x80000000);
        }
      }
      else {
        if (((*(int *)(param_2 + 0x14) != 0xff00) || (*(int *)(param_2 + 0x10) != 0xff0000)) ||
           (*(char *)(param_2 + 4) != '\x03')) goto LAB_14018274d;
        uVar17 = *(int *)(param_2 + 0x42c) - 1;
        if (-1 < (int)uVar17) {
          iVar13 = *(int *)(param_2 + 0x428);
          iVar19 = 0;
          do {
            iVar12 = 0;
            puVar15 = (undefined1 *)(iVar19 + lVar8);
            puVar10 = (undefined1 *)
                      ((longlong)(int)(*(int *)(param_2 + 0x430) * uVar17) +
                      *(longlong *)(param_2 + 0x438));
            if (0 < iVar13) {
              do {
                *puVar15 = *puVar10;
                iVar12 = iVar12 + 1;
                puVar15[1] = puVar10[1];
                puVar15[2] = puVar10[2];
                iVar13 = *(int *)(param_2 + 0x428);
                puVar15 = puVar15 + 3;
                puVar10 = puVar10 + 3;
              } while (iVar12 < iVar13);
            }
            uVar17 = uVar17 - 1;
            iVar19 = iVar19 + uVar20;
          } while (uVar17 < 0x80000000);
        }
      }
    }
    else {
LAB_14018274d:
      if (*(char *)(param_2 + 4) == '\x02') {
        local_78 = *(uint *)(param_2 + 0x10);
        local_8c = *(int *)(param_2 + 0x42c) - 1;
        local_74 = *(uint *)(param_2 + 0x14);
        bVar2 = *(byte *)(param_2 + 0xc);
        local_84[0] = (uint)bVar2;
        bVar3 = *(byte *)(param_2 + 0xd);
        local_94 = (uint)bVar3;
        bVar4 = *(byte *)(param_2 + 0xe);
        local_98 = (uint)bVar4;
        cVar1 = *(char *)(param_2 + 8);
        cVar5 = *(char *)(param_2 + 9);
        local_7c = 0x18 - (uint)*(byte *)(param_2 + 10);
        if (-1 < (int)local_8c) {
          iVar13 = *(int *)(param_2 + 0x428);
          local_88 = 0;
          do {
            iVar19 = 0;
            puVar15 = (undefined1 *)(local_88 + lVar8);
            puVar18 = (ushort *)
                      ((longlong)(int)(*(int *)(param_2 + 0x430) * local_8c) +
                      *(longlong *)(param_2 + 0x438));
            if (0 < iVar13) {
              do {
                uVar6 = *puVar18;
                puVar18 = puVar18 + 1;
                iVar19 = iVar19 + 1;
                uVar20 = ((uVar6 & uVar17) >> (bVar4 & 0x1f)) << ((byte)local_7c & 0x1f) |
                         ((uVar6 & local_74) >> (bVar3 & 0x1f)) << (0x10U - cVar5 & 0x1f) |
                         ((uVar6 & local_78) >> (bVar2 & 0x1f)) << (8U - cVar1 & 0x1f);
                *puVar15 = (char)(uVar20 >> 0x10);
                puVar15[1] = (char)(uVar20 >> 8);
                puVar15[2] = (char)uVar20;
                iVar13 = *(int *)(param_2 + 0x428);
                puVar15 = puVar15 + 3;
                uVar20 = local_90;
              } while (iVar19 < iVar13);
            }
            local_8c = local_8c - 1;
            local_88 = local_88 + uVar20;
            puVar7 = local_68;
          } while (local_8c < 0x80000000);
        }
      }
      else {
        uVar17 = *(int *)(param_2 + 0x42c) - 1;
        if (-1 < (int)uVar17) {
          iVar13 = *(int *)(param_2 + 0x428);
          iVar19 = 0;
          do {
            iVar12 = 0;
            puVar15 = (undefined1 *)(iVar19 + lVar8);
            if (0 < iVar13) {
              do {
                local_a8 = local_84;
                local_b0 = &local_90;
                local_b8 = &local_94;
                FUN_14017ab40(param_2,iVar12,uVar17,&local_98);
                iVar12 = iVar12 + 1;
                *puVar15 = (undefined1)local_90;
                puVar15[1] = (undefined1)local_94;
                puVar15[2] = (undefined1)local_98;
                iVar13 = *(int *)(param_2 + 0x428);
                puVar15 = puVar15 + 3;
              } while (iVar12 < iVar13);
            }
            uVar17 = uVar17 - 1;
            iVar19 = iVar19 + uVar20;
          } while (uVar17 < 0x80000000);
        }
      }
    }
    thunk_FUN_1401b9570(local_60);
    lVar9 = thunk_FUN_1401b95b0(local_60);
    if (lVar9 == 0) {
      FUN_1401594b0(&DAT_1404a8760);
      uVar11 = 0xffffffff;
      goto LAB_140182bd5;
    }
    thunk_FUN_1401b96b0(lVar9,&local_58,0xe);
    thunk_FUN_1401b96b0(lVar9,puVar7,0x28);
    iVar13 = *(int *)(param_2 + 0x42c) * uVar20;
    goto LAB_140182bbd;
  }
  uVar11 = 0;
LAB_140182bd5:
  if (puVar7 != (undefined4 *)0x0) {
    FUN_1401b6700(puVar7);
  }
  if (lVar8 != 0) {
    FUN_1401b6700(lVar8);
  }
  return uVar11;
}


