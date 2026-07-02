// Function: FUN_140176e30 @ 140176e30
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140176e30(longlong param_1,undefined8 param_2,longlong param_3,int param_4,int param_5,
             int param_6,int param_7,int param_8,undefined8 *param_9,longlong *param_10,
             undefined8 param_11)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int iVar13;
  uint uVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong lVar17;
  char *pcVar18;
  char *pcVar19;
  undefined8 *puVar20;
  uint *puVar21;
  longlong lVar22;
  undefined8 *puVar23;
  uint uVar24;
  undefined1 auStack_968 [32];
  undefined4 local_948;
  undefined4 local_940;
  undefined8 *local_938;
  char *local_930;
  undefined8 local_928;
  undefined1 local_920 [40];
  code *local_8f8;
  longlong local_8f0;
  char local_8e8 [3];
  char cStack_8e5;
  char cStack_8e4;
  char cStack_8e3;
  char cStack_8dd;
  int local_8d8;
  int iStack_8d4;
  int iStack_8d0;
  int iStack_8cc;
  int local_8c8;
  uint local_4c0;
  uint local_4bc;
  int local_4b8;
  longlong local_4b0;
  undefined8 local_498 [133];
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_60;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_968;
  lVar17 = 0;
  local_928 = param_11;
  if (param_5 == 0) {
    lVar15 = (**(code **)(param_1 + 0x58))(param_2,0,1,0);
    if (lVar15 == 0) {
      return 0xffffffff;
    }
    (**(code **)(param_1 + 0x70))(lVar15,0,2);
    uVar16 = (**(code **)(param_1 + 0x68))(lVar15);
    (**(code **)(param_1 + 0x70))(lVar15,0,0);
    lVar17 = FUN_1401b6390(uVar16,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x461
                          );
    if (lVar17 == 0) {
      return 0xffffffff;
    }
    (**(code **)(param_1 + 0x78))(lVar17,uVar16,1,lVar15);
    (**(code **)(param_1 + 0x60))(lVar15);
    local_8f0 = FUN_140139630(lVar17,uVar16);
    if (local_8f0 == 0) {
      return 0xffffffff;
    }
    FUN_1401ae2f0(local_920,param_1 + 0xf8,0x30);
    param_11 = local_928;
  }
  else {
    if (param_3 == 0) {
      return 0xffffffff;
    }
    local_8f0 = FUN_140139630(param_3,(longlong)param_4);
    if (local_8f0 == 0) {
      return 0xffffffff;
    }
    FUN_1401ae2f0(local_920,param_1 + 0xf8,0x30);
  }
  iVar13 = FUN_1401773d0(param_1,local_920,local_8e8);
  if (iVar13 != 0) goto LAB_14017738a;
  (*local_8f8)(local_8f0);
  local_8f0 = 0;
  if (*(int *)(param_1 + 0x54) == 0) {
    if (param_7 == 1) {
      FUN_140172050(local_8e8,1);
      FUN_140182190(local_8e8);
    }
    if (*(int *)(param_1 + 300) != 0) {
      FUN_140172050(local_8e8,1);
    }
    lVar15 = 8;
    if (*(int *)(param_1 + 0x128) == 0) {
LAB_140177252:
      if (param_6 == 0) {
        pcVar18 = local_8e8;
        do {
          puVar23 = param_9 + 0x10;
          uVar16 = *(undefined8 *)(pcVar18 + 8);
          uVar10 = *(undefined8 *)(pcVar18 + 0x10);
          uVar11 = *(undefined8 *)(pcVar18 + 0x18);
          pcVar19 = pcVar18 + 0x80;
          *param_9 = *(undefined8 *)pcVar18;
          param_9[1] = uVar16;
          uVar16 = *(undefined8 *)(pcVar18 + 0x20);
          uVar12 = *(undefined8 *)(pcVar18 + 0x28);
          param_9[2] = uVar10;
          param_9[3] = uVar11;
          uVar10 = *(undefined8 *)(pcVar18 + 0x30);
          uVar11 = *(undefined8 *)(pcVar18 + 0x38);
          param_9[4] = uVar16;
          param_9[5] = uVar12;
          uVar16 = *(undefined8 *)(pcVar18 + 0x40);
          uVar12 = *(undefined8 *)(pcVar18 + 0x48);
          param_9[6] = uVar10;
          param_9[7] = uVar11;
          uVar10 = *(undefined8 *)(pcVar18 + 0x50);
          uVar11 = *(undefined8 *)(pcVar18 + 0x58);
          param_9[8] = uVar16;
          param_9[9] = uVar12;
          uVar16 = *(undefined8 *)(pcVar18 + 0x60);
          uVar12 = *(undefined8 *)(pcVar18 + 0x68);
          param_9[10] = uVar10;
          param_9[0xb] = uVar11;
          uVar10 = *(undefined8 *)(pcVar18 + 0x70);
          uVar11 = *(undefined8 *)(pcVar18 + 0x78);
          param_9[0xc] = uVar16;
          param_9[0xd] = uVar12;
          param_9[0xe] = uVar10;
          param_9[0xf] = uVar11;
          lVar15 = lVar15 + -1;
          pcVar18 = pcVar19;
          param_9 = puVar23;
        } while (lVar15 != 0);
        goto LAB_140177343;
      }
      FUN_140172050(local_8e8,1);
      lVar15 = FUN_1401b6390(0x42c,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                             0x4f9);
      *param_10 = lVar15;
      if (lVar15 != 0) {
        local_948 = 0;
        iVar13 = FUN_140171410(local_8e8,lVar15,param_11,0);
        if (iVar13 == -1) {
          FUN_1401b6700(local_4b0);
          FUN_1401b6700(*param_10);
        }
        else if (iVar13 == 1) {
          FUN_1401b6700(local_4b0);
        }
        goto LAB_140177369;
      }
    }
    else {
      if (((cStack_8dd == '\0') && (*(int *)(param_1 + 0x130) == 1)) && (param_8 == 0)) {
        if ((local_8e8[0] != '\0') && (iVar13 = FUN_140172050(local_8e8,1), iVar13 < 0)) {
          return 0xffffffff;
        }
        if (((cStack_8e3 != ' ') || (cStack_8e4 != '\x04')) ||
           ((cStack_8e5 != '\0' ||
            ((((local_8c8 != 0 || (iStack_8cc != -0x1000000)) || (local_8d8 != 0xff0000)) ||
             ((iStack_8d4 != 0xff00 || (iStack_8d0 != 0xff)))))))) {
          lVar22 = 8;
          pcVar18 = local_8e8;
          puVar23 = local_498;
          do {
            puVar20 = puVar23;
            pcVar19 = pcVar18;
            uVar16 = *(undefined8 *)(pcVar19 + 8);
            uVar10 = *(undefined8 *)(pcVar19 + 0x10);
            uVar11 = *(undefined8 *)(pcVar19 + 0x18);
            *puVar20 = *(undefined8 *)pcVar19;
            puVar20[1] = uVar16;
            uVar16 = *(undefined8 *)(pcVar19 + 0x20);
            uVar12 = *(undefined8 *)(pcVar19 + 0x28);
            puVar20[2] = uVar10;
            puVar20[3] = uVar11;
            uVar10 = *(undefined8 *)(pcVar19 + 0x30);
            uVar11 = *(undefined8 *)(pcVar19 + 0x38);
            puVar20[4] = uVar16;
            puVar20[5] = uVar12;
            uVar16 = *(undefined8 *)(pcVar19 + 0x40);
            uVar12 = *(undefined8 *)(pcVar19 + 0x48);
            puVar20[6] = uVar10;
            puVar20[7] = uVar11;
            uVar10 = *(undefined8 *)(pcVar19 + 0x50);
            uVar11 = *(undefined8 *)(pcVar19 + 0x58);
            puVar20[8] = uVar16;
            puVar20[9] = uVar12;
            uVar16 = *(undefined8 *)(pcVar19 + 0x60);
            uVar12 = *(undefined8 *)(pcVar19 + 0x68);
            puVar20[10] = uVar10;
            puVar20[0xb] = uVar11;
            uVar10 = *(undefined8 *)(pcVar19 + 0x70);
            uVar11 = *(undefined8 *)(pcVar19 + 0x78);
            puVar20[0xc] = uVar16;
            puVar20[0xd] = uVar12;
            puVar20[0xe] = uVar10;
            puVar20[0xf] = uVar11;
            lVar22 = lVar22 + -1;
            pcVar18 = pcVar19 + 0x80;
            puVar23 = puVar20 + 0x10;
          } while (lVar22 != 0);
          uVar16 = *(undefined8 *)(pcVar19 + 0x88);
          uVar10 = *(undefined8 *)(pcVar19 + 0x90);
          uVar11 = *(undefined8 *)(pcVar19 + 0x98);
          puVar20[0x10] = *(undefined8 *)(pcVar19 + 0x80);
          puVar20[0x11] = uVar16;
          uVar2 = *(undefined4 *)(pcVar19 + 0xa0);
          uVar3 = *(undefined4 *)(pcVar19 + 0xa4);
          uVar4 = *(undefined4 *)(pcVar19 + 0xa8);
          uVar5 = *(undefined4 *)(pcVar19 + 0xac);
          puVar20[0x12] = uVar10;
          puVar20[0x13] = uVar11;
          uVar6 = *(undefined4 *)(pcVar19 + 0xb0);
          uVar7 = *(undefined4 *)(pcVar19 + 0xb4);
          uVar8 = *(undefined4 *)(pcVar19 + 0xb8);
          uVar9 = *(undefined4 *)(pcVar19 + 0xbc);
          uVar16 = *(undefined8 *)(pcVar19 + 0xc0);
          *(undefined4 *)(puVar20 + 0x14) = uVar2;
          *(undefined4 *)((longlong)puVar20 + 0xa4) = uVar3;
          *(undefined4 *)(puVar20 + 0x15) = uVar4;
          *(undefined4 *)((longlong)puVar20 + 0xac) = uVar5;
          *(undefined4 *)(puVar20 + 0x16) = uVar6;
          *(undefined4 *)((longlong)puVar20 + 0xb4) = uVar7;
          *(undefined4 *)(puVar20 + 0x17) = uVar8;
          *(undefined4 *)((longlong)puVar20 + 0xbc) = uVar9;
          puVar20[0x18] = uVar16;
          FUN_140176240(local_4c0,local_4bc,local_8e8);
          local_930 = local_8e8;
          local_938 = local_498;
          local_940 = 0;
          local_948 = 0;
          FUN_140170b70(0,0,local_70,local_6c);
          if (local_60 != 0) {
            FUN_1401b6700();
            local_60 = 0;
          }
          FUN_1401ae370(local_498,0,0x448);
        }
        uVar1 = *(uint *)(param_1 + 0x134);
        uVar24 = 0;
        if (local_4bc != 0) {
          do {
            uVar14 = 0;
            puVar21 = (uint *)((ulonglong)(local_4b8 * uVar24) + local_4b0);
            if (local_4c0 != 0) {
              do {
                if (*puVar21 == (uVar1 | 0xff000000)) {
                  *puVar21 = 0;
                }
                uVar14 = uVar14 + 1;
                puVar21 = puVar21 + 1;
              } while (uVar14 < local_4c0);
            }
            uVar24 = uVar24 + 1;
          } while (uVar24 < local_4bc);
        }
        goto LAB_140177252;
      }
      iVar13 = FUN_140175310(local_8e8);
      if (-1 < iVar13) goto LAB_140177252;
    }
    FUN_1401b6700(local_4b0);
LAB_14017738a:
    if ((param_5 == 0) && (lVar17 != 0)) {
      FUN_1401b6700(lVar17);
    }
    (*local_8f8)(local_8f0);
    return 0xffffffff;
  }
  lVar15 = 8;
  pcVar18 = local_8e8;
  do {
    puVar23 = param_9 + 0x10;
    uVar16 = *(undefined8 *)(pcVar18 + 8);
    uVar10 = *(undefined8 *)(pcVar18 + 0x10);
    uVar11 = *(undefined8 *)(pcVar18 + 0x18);
    pcVar19 = pcVar18 + 0x80;
    *param_9 = *(undefined8 *)pcVar18;
    param_9[1] = uVar16;
    uVar16 = *(undefined8 *)(pcVar18 + 0x20);
    uVar12 = *(undefined8 *)(pcVar18 + 0x28);
    param_9[2] = uVar10;
    param_9[3] = uVar11;
    uVar10 = *(undefined8 *)(pcVar18 + 0x30);
    uVar11 = *(undefined8 *)(pcVar18 + 0x38);
    param_9[4] = uVar16;
    param_9[5] = uVar12;
    uVar16 = *(undefined8 *)(pcVar18 + 0x40);
    uVar12 = *(undefined8 *)(pcVar18 + 0x48);
    param_9[6] = uVar10;
    param_9[7] = uVar11;
    uVar10 = *(undefined8 *)(pcVar18 + 0x50);
    uVar11 = *(undefined8 *)(pcVar18 + 0x58);
    param_9[8] = uVar16;
    param_9[9] = uVar12;
    uVar16 = *(undefined8 *)(pcVar18 + 0x60);
    uVar12 = *(undefined8 *)(pcVar18 + 0x68);
    param_9[10] = uVar10;
    param_9[0xb] = uVar11;
    uVar10 = *(undefined8 *)(pcVar18 + 0x70);
    uVar11 = *(undefined8 *)(pcVar18 + 0x78);
    param_9[0xc] = uVar16;
    param_9[0xd] = uVar12;
    param_9[0xe] = uVar10;
    param_9[0xf] = uVar11;
    lVar15 = lVar15 + -1;
    pcVar18 = pcVar19;
    param_9 = puVar23;
  } while (lVar15 != 0);
LAB_140177343:
  uVar16 = *(undefined8 *)(pcVar19 + 8);
  uVar10 = *(undefined8 *)(pcVar19 + 0x10);
  uVar11 = *(undefined8 *)(pcVar19 + 0x18);
  *puVar23 = *(undefined8 *)pcVar19;
  puVar23[1] = uVar16;
  uVar2 = *(undefined4 *)(pcVar19 + 0x20);
  uVar3 = *(undefined4 *)(pcVar19 + 0x24);
  uVar4 = *(undefined4 *)(pcVar19 + 0x28);
  uVar5 = *(undefined4 *)(pcVar19 + 0x2c);
  puVar23[2] = uVar10;
  puVar23[3] = uVar11;
  uVar10 = *(undefined8 *)(pcVar19 + 0x30);
  uVar11 = *(undefined8 *)(pcVar19 + 0x38);
  uVar16 = *(undefined8 *)(pcVar19 + 0x40);
  *(undefined4 *)(puVar23 + 4) = uVar2;
  *(undefined4 *)((longlong)puVar23 + 0x24) = uVar3;
  *(undefined4 *)(puVar23 + 5) = uVar4;
  *(undefined4 *)((longlong)puVar23 + 0x2c) = uVar5;
  puVar23[6] = uVar10;
  puVar23[7] = uVar11;
  puVar23[8] = uVar16;
LAB_140177369:
  if (param_5 == 0) {
    FUN_1401b6700(lVar17);
  }
  return 0;
}


