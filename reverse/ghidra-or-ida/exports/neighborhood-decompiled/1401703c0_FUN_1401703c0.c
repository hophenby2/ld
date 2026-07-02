// Function: FUN_1401703c0 @ 1401703c0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401703c0(longlong param_1,char *param_2,int param_3)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  ulonglong uVar22;
  longlong lVar23;
  uint uVar24;
  uint uVar25;
  char cVar26;
  bool bVar27;
  undefined1 auStack_158 [32];
  int local_138;
  int local_130;
  undefined4 local_128;
  undefined4 local_120;
  undefined4 local_118;
  int local_108;
  int local_104;
  undefined8 local_100;
  longlong local_f8;
  ulonglong local_f0;
  undefined1 local_e8 [4];
  int local_e4 [5];
  uint local_d0;
  uint local_cc;
  uint local_c8;
  int local_c4;
  uint local_bc;
  uint local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  int local_58 [6];
  ulonglong local_40;
  
  local_40 = DAT_1407c6b00 ^ (ulonglong)auStack_158;
  uVar4 = *(undefined8 *)(param_1 + 0x30);
  uVar12 = 0;
  cVar26 = '\0';
  local_108 = param_3;
  local_100 = uVar4;
  local_f8 = param_1;
  lVar10 = (**(code **)(param_1 + 0x10))(local_e8,4,1,uVar4);
  if (lVar10 == 0) {
    return 0xffffffff;
  }
  uVar11 = FUN_1401ae820(&DAT_1404a8908);
  iVar8 = FUN_1401ae2b0(local_e8,&DAT_1404a8908,uVar11);
  if (iVar8 != 0) {
    return 0xffffffff;
  }
  lVar10 = (**(code **)(param_1 + 0x10))(local_e4,4,1,uVar4);
  if (lVar10 == 0) {
    return 0xffffffff;
  }
  lVar10 = (**(code **)(param_1 + 0x10))(&local_d0,local_e4[0] + -4,1,uVar4);
  if (lVar10 == 0) {
    return 0xffffffff;
  }
  bVar27 = false;
  if (local_88 == 4) {
    piVar17 = &DAT_14056cb90;
    iVar8 = DAT_14056cb90;
    bVar27 = false;
    if (DAT_14056cb90 == -1) {
LAB_1401704cb:
      if (*piVar17 != -1) {
        if ((char)piVar17[1] == '\0') {
          if ((*(char *)((longlong)piVar17 + 6) == '\x10') &&
             (*(char *)((longlong)piVar17 + 5) != '\0')) {
            FUN_1401ae370(param_2,0,0x428);
            *param_2 = '\0';
            bVar2 = *(byte *)((longlong)piVar17 + 6);
            param_2[2] = bVar2;
            bVar3 = *(byte *)((longlong)piVar17 + 5);
            param_2[1] = bVar3;
            param_2[3] = '\0';
            param_2[4] = (char)((uint)bVar2 * (uint)bVar3 >> 3);
          }
          else {
            local_118 = 0;
            local_120 = 0;
            local_130 = piVar17[5];
            local_128 = 0;
            local_138 = piVar17[4];
            FUN_1401765d0(param_2,*(char *)((longlong)piVar17 + 6),piVar17[2],piVar17[3]);
          }
        }
        else {
          FUN_1401ae370(param_2,0,0x428);
          *param_2 = '\0';
          bVar2 = *(byte *)((longlong)piVar17 + 6);
          param_2[2] = bVar2;
          bVar3 = *(byte *)((longlong)piVar17 + 5);
          param_2[1] = bVar3;
          param_2[3] = '\x01';
          param_2[4] = (char)((uint)bVar2 * (uint)bVar3 >> 3);
        }
        bVar27 = true;
      }
    }
    else {
      do {
        if (iVar8 == local_84) goto LAB_1401704cb;
        piVar1 = piVar17 + 6;
        piVar17 = piVar17 + 6;
        iVar8 = *piVar1;
      } while (*piVar1 != -1);
    }
  }
  iVar8 = 6;
  iVar20 = 0;
  local_104 = 6;
  if (bVar27) goto LAB_14017074a;
  cVar26 = '\0';
  if ((local_88 & 4) != 0) {
    FUN_1401ae370(param_2,0,0x428);
    iVar20 = 0;
    cVar26 = '\0';
    if (local_84 == 0x30315844) {
      lVar10 = (**(code **)(local_f8 + 0x10))(local_58,0x14,1,local_100);
      if (lVar10 == 0) {
        return 0xffffffff;
      }
      if (local_58[0] == 0x62) {
        cVar26 = '\x06';
      }
      else {
        cVar26 = '\0';
        if (local_58[0] != 99) goto LAB_140170605;
        cVar26 = '\a';
      }
      iVar20 = 0x10;
    }
LAB_140170605:
    if (local_84 == 0x31545844) {
      cVar26 = '\x01';
      iVar20 = 8;
    }
    else if (local_84 == 0x32545844) {
      iVar20 = 0x10;
      cVar26 = '\x02';
    }
    else if (local_84 == 0x33545844) {
      iVar20 = 0x10;
      cVar26 = '\x03';
    }
    else if (local_84 == 0x34545844) {
      iVar20 = 0x10;
      cVar26 = '\x04';
    }
    else if (local_84 == 0x35545844) {
      iVar20 = 0x10;
      cVar26 = '\x05';
    }
    else if (cVar26 == '\0') goto LAB_1401706b5;
    param_2[0] = '\0';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    param_2[0x20] = '\0';
    param_2[0x21] = '\0';
    param_2[0x22] = '\0';
    param_2[0x23] = '\0';
    param_2[0x24] = '\0';
    param_2[0x25] = '\0';
    param_2[0x26] = '\0';
    param_2[0x27] = '\0';
    param_2[4] = '\x04';
    param_2[5] = ' ';
    param_2[6] = '\0';
    param_2[7] = '\0';
    param_2[0xe] = '\0';
    param_2[0xf] = '\x18';
    param_2[0x1c] = '\0';
    param_2[0x1d] = '\0';
    param_2[0x1e] = '\0';
    param_2[0x1f] = -1;
    param_2[0xb] = '\b';
    param_2[0xc] = '\x10';
    param_2[0x10] = '\0';
    param_2[0x11] = '\0';
    param_2[0x12] = -1;
    param_2[0x13] = '\0';
    param_2[8] = '\b';
    param_2[9] = '\b';
    param_2[0xd] = '\b';
    param_2[0x14] = '\0';
    param_2[0x15] = -1;
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    param_2[0x18] = -1;
    param_2[0x19] = '\0';
    param_2[0x1a] = '\0';
    param_2[0x1b] = '\0';
    param_2[10] = '\b';
    goto LAB_14017074a;
  }
LAB_1401706b5:
  if ((((byte)local_88 & 0x41) != 0x41) && ((local_88 & 0x40) == 0)) {
    return 0xffffffff;
  }
  if (local_80 == 8) {
    if (local_7c == 0xff) {
      local_80 = 8;
      local_120 = 8;
      local_128 = 1;
    }
    else {
LAB_140170722:
      local_120 = 0;
      local_128 = 0;
    }
  }
  else {
    if (((local_80 != 0x10) || (local_7c != 0xff00)) || (local_78 != 0xff)) goto LAB_140170722;
    local_120 = 8;
    local_128 = 2;
  }
  local_118 = 0;
  local_130 = local_70;
  local_138 = local_74;
  FUN_1401765d0(param_2,local_80);
LAB_14017074a:
  iVar14 = 0;
  if (((local_d0 >> 0x11 & 1) == 0) || (uVar24 = local_bc, (local_6c & 0x400008) != 0x400008)) {
    uVar24 = 0;
  }
  if (((local_68 >> 9 & 1) == 0) || ((local_68 & 0xfc00) != 0xfc00)) {
    iVar8 = 1;
    local_104 = 1;
  }
  uVar25 = uVar24;
  if (cVar26 == '\0') {
    bVar27 = local_108 == 0;
    local_f0 = uVar12;
    local_108 = 0;
    if (bVar27) {
      if ((local_d0 & 8) == 0) {
        local_c4 = (byte)param_2[4] * local_c8;
      }
      iVar20 = local_cc * local_c4;
      if (1 < (int)uVar24) {
        uVar18 = (uVar24 - 2 >> 1) + 1;
        uVar22 = (ulonglong)uVar18;
        iVar21 = iVar14;
        do {
          iVar21 = iVar21 + iVar20;
          iVar20 = iVar20 + (iVar20 >> 0x1f & 3U);
          iVar9 = iVar20 >> 2;
          iVar14 = iVar14 + iVar9;
          iVar20 = (int)(iVar9 + (iVar20 >> 0x1f & 3U)) >> 2;
          uVar22 = uVar22 - 1;
        } while (uVar22 != 0);
        iVar9 = 0;
        if ((int)(uVar18 * 2) < (int)uVar24) {
          iVar9 = iVar20;
        }
        iVar20 = iVar9 + iVar14 + iVar21;
      }
      local_108 = local_c4;
      uVar22 = FUN_1401b6390((longlong)(iVar20 * iVar8),
                             "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x14dd);
      if (uVar22 == 0) {
        return 0xffffffff;
      }
      local_f0 = uVar22;
      if ((int)uVar24 < 2) {
        lVar10 = (**(code **)(local_f8 + 0x10))(uVar22,(longlong)(iVar20 * iVar8),1,local_100);
        if (lVar10 == 0) {
          FUN_1401b6700(uVar22);
          return 0xffffffff;
        }
      }
      else {
        uVar25 = 0;
        uVar18 = local_c8;
        uVar19 = local_cc;
        if (0 < (int)uVar24) {
          do {
            lVar23 = (longlong)(int)((byte)param_2[4] * uVar19 * uVar18 * iVar8);
            lVar10 = (**(code **)(local_f8 + 0x10))(uVar22,lVar23,1,local_100);
            uVar25 = (uint)uVar12;
            iVar8 = local_104;
            if (lVar10 == 0) {
              if (uVar25 == 0) {
                FUN_1401b6700(local_f0);
                return 0xffffffff;
              }
              break;
            }
            uVar16 = uVar18 >> 1;
            uVar22 = uVar22 + lVar23;
            uVar15 = uVar19 >> 1;
            uVar25 = uVar25 + 1;
            uVar12 = (ulonglong)uVar25;
            uVar5 = uVar18 >> 1;
            uVar18 = 1;
            if (uVar5 != 0) {
              uVar18 = uVar16;
            }
            uVar5 = uVar19 >> 1;
            uVar19 = 1;
            if (uVar5 != 0) {
              uVar19 = uVar15;
            }
          } while ((int)uVar25 < (int)uVar24);
        }
      }
    }
  }
  else {
    FUN_1401ae370(param_2,0,0x428);
    uVar18 = 1;
    param_2[0] = '\0';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    cVar7 = '\0';
    param_2[4] = '\x04';
    param_2[5] = ' ';
    param_2[0x10] = '\0';
    param_2[0x11] = '\0';
    param_2[0x12] = -1;
    param_2[0x13] = '\0';
    param_2[0x14] = '\0';
    param_2[0x15] = -1;
    param_2[0x16] = '\0';
    param_2[0x17] = '\0';
    param_2[0x18] = -1;
    param_2[0x19] = '\0';
    param_2[0x1a] = '\0';
    param_2[0x1b] = '\0';
    param_2[0x1c] = '\0';
    param_2[0x1d] = '\0';
    param_2[0x1e] = '\0';
    param_2[0x1f] = -1;
    param_2[0x20] = '\0';
    param_2[0x21] = '\0';
    param_2[0x22] = '\0';
    param_2[0x23] = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff0000) == 0);
    param_2[0xc] = cVar7;
    cVar7 = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff0000) != 0);
    param_2[8] = cVar7;
    uVar18 = 1;
    cVar7 = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff00) == 0);
    param_2[0xd] = cVar7;
    cVar7 = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff00) != 0);
    param_2[9] = cVar7;
    cVar7 = '\x01';
    cVar13 = '\0';
    param_2[0xe] = '\0';
    do {
      cVar7 = cVar7 * '\x02';
      cVar13 = cVar13 + '\x01';
    } while (cVar7 != '\0');
    param_2[10] = cVar13;
    uVar18 = 1;
    cVar7 = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff000000) == 0);
    param_2[0xf] = cVar7;
    cVar7 = '\0';
    do {
      uVar18 = uVar18 * 2;
      cVar7 = cVar7 + '\x01';
    } while ((uVar18 & 0xff000000) != 0);
    param_2[0xb] = cVar7;
    param_2[6] = '\0';
    param_2[7] = '\0';
    param_2[0x20] = '\0';
    param_2[0x21] = '\0';
    param_2[0x22] = '\0';
    param_2[0x23] = '\0';
    if (local_108 == 0) {
      iVar14 = (local_c8 + 3 >> 2) * (local_cc + 3 >> 2) * iVar20;
      if (1 < (int)uVar24) {
        uVar18 = local_c8 + 3 & 0xfffffffc;
        uVar12 = (ulonglong)(local_cc + 3 & 0xfffffffc);
        iVar14 = 0;
        if (0 < (int)uVar24) {
          uVar22 = (ulonglong)uVar24;
          do {
            uVar6 = uVar12 >> 1;
            uVar19 = uVar18 >> 1;
            iVar14 = iVar14 + ((int)uVar12 + 3U >> 2) * (uVar18 + 3 >> 2) * iVar20;
            uVar24 = uVar18 >> 1;
            uVar18 = 1;
            if (uVar24 != 0) {
              uVar18 = uVar19;
            }
            uVar12 = 1;
            if ((int)uVar6 != 0) {
              uVar12 = uVar6;
            }
            uVar22 = uVar22 - 1;
          } while (uVar22 != 0);
        }
      }
      uVar12 = FUN_1401b6390((longlong)(iVar14 * iVar8),
                             "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x14ae);
      if (uVar12 == 0) {
        return 0xffffffff;
      }
      lVar10 = (**(code **)(local_f8 + 0x10))(uVar12,(longlong)(iVar14 * iVar8),1,local_100);
      if (lVar10 == 0) {
        FUN_1401b6700(uVar12);
        return 0xffffffff;
      }
    }
    *param_2 = cVar26;
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    cVar7 = '\b';
    if (cVar26 == '\x01') {
      cVar7 = '\x04';
    }
    param_2[5] = cVar7;
    local_f0 = uVar12;
    local_108 = 0;
  }
  *(uint *)(param_2 + 0x428) = local_c8;
  *(uint *)(param_2 + 0x42c) = local_cc;
  if (iVar8 == 1) {
    iVar8 = 0;
  }
  *(ulonglong *)(param_2 + 0x438) = local_f0;
  *(int *)(param_2 + 0x444) = iVar8;
  *(int *)(param_2 + 0x430) = local_108;
  *(uint *)(param_2 + 0x440) = uVar25;
  return 0;
}


