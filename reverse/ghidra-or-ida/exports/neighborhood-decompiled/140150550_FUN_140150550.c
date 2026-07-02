// Function: FUN_140150550 @ 140150550
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140150550(int *param_1,uint param_2,longlong param_3,undefined8 param_4,longlong param_5,
             longlong param_6,longlong param_7,int param_8,short *param_9,int param_10,
             undefined1 *param_11,undefined1 *param_12,undefined4 param_13,undefined4 param_14,
             undefined4 param_15,uint param_16,int param_17)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined8 uVar8;
  short *psVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined1 auStack_1188 [32];
  longlong local_1168;
  int local_1160;
  int local_115c;
  longlong local_1158;
  longlong local_1150;
  undefined8 local_1148;
  longlong local_1140;
  int *local_1138;
  short *local_1130;
  undefined1 local_1128 [4];
  undefined4 local_1124;
  undefined4 local_1120;
  undefined8 local_1110;
  undefined1 local_1108 [4];
  undefined4 local_1104;
  undefined4 local_1100;
  undefined8 local_10f0;
  undefined1 local_10e8 [1064];
  undefined4 local_cc0;
  undefined4 local_cbc;
  uint local_cb8;
  undefined8 local_cb0;
  undefined1 local_c98 [1064];
  undefined4 local_870;
  undefined4 local_86c;
  uint local_868;
  undefined8 local_860;
  short local_848 [1024];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x140150572;
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_1188;
  piVar14 = (int *)0x0;
  uVar5 = 0;
  piVar12 = (int *)0x0;
  local_1150 = param_5;
  local_1158 = param_7;
  local_115c = param_8;
  local_1130 = param_9;
  local_1160 = param_10;
  local_1140 = param_6;
  piVar13 = piVar14;
  local_1168 = param_3;
  local_1148 = param_4;
  local_1138 = param_1;
  if (param_17 == 0) {
    if (DAT_140987e88 == 0) {
      return 0xffffffff;
    }
    if ((int)param_2 < 0) {
      return 0xffffffff;
    }
    if ((param_2 & 0x7c000000) != DAT_140987ed8) {
      return 0xffffffff;
    }
    if (DAT_140987ee0 <= (int)(param_2 & 0x3ffff)) {
      return 0xffffffff;
    }
    lVar6 = (ulonglong)(param_2 & 0x3ffff) * 8;
    piVar10 = *(int **)(lVar6 + DAT_140987e90);
    if (piVar10 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar10 << 0x12 != (param_2 & 0x3fc0000)) {
      return 0xffffffff;
    }
    if (piVar10[6] != 0) {
      if ((piVar10[6] < 2) && (-1 < piVar10[8])) {
        iVar3 = FUN_1401afbe0();
      }
      else {
        iVar3 = FUN_1401b82b0(param_2);
      }
      if (iVar3 < 0) {
        return 0xffffffff;
      }
      if (*(longlong *)(lVar6 + DAT_140987e90) == 0) {
        return 0xffffffff;
      }
    }
    if ((((DAT_140987e88 != 0) && (piVar13 = piVar12, -1 < (int)param_16)) &&
        ((param_16 & 0x7c000000) == DAT_140987ed8)) &&
       ((((int)(param_16 & 0x3ffff) < DAT_140987ee0 &&
         (piVar13 = *(int **)(DAT_140987e90 + (ulonglong)(param_16 & 0x3ffff) * 8),
         piVar13 != (int *)0x0)) &&
        ((*piVar13 << 0x12 == (param_16 & 0x3fc0000) && (piVar13[6] != 0)))))) {
      if ((piVar13[6] < 2) && (-1 < piVar13[8])) {
        FUN_1401afbe0();
      }
      else {
        FUN_1401b82b0(param_16);
      }
    }
  }
  else {
    if (DAT_140987e88 == 0) {
      return 0xffffffff;
    }
    if ((int)param_2 < 0) {
      return 0xffffffff;
    }
    if ((param_2 & 0x7c000000) != DAT_140987ed8) {
      return 0xffffffff;
    }
    if (DAT_140987ee0 <= (int)(param_2 & 0x3ffff)) {
      return 0xffffffff;
    }
    piVar10 = *(int **)(DAT_140987e90 + (ulonglong)(param_2 & 0x3ffff) * 8);
    if (piVar10 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar10 << 0x12 != (param_2 & 0x3fc0000)) {
      return 0xffffffff;
    }
    if (((-1 < (int)param_16) && (piVar13 = piVar12, (param_16 & 0x7c000000) == DAT_140987ed8)) &&
       ((int)(param_16 & 0x3ffff) < DAT_140987ee0)) {
      piVar13 = *(int **)(DAT_140987e90 + (ulonglong)(param_16 & 0x3ffff) * 8);
    }
  }
  lVar6 = local_1168;
  if ((*(longlong *)(piVar10 + 0x22) != 0) &&
     (piVar12 = (int *)(*(longlong *)(piVar10 + 0x22) + 0x48), *piVar12 = *piVar12 + -1,
     *(int *)(*(longlong *)(piVar10 + 0x22) + 0x48) == 0)) {
    FUN_1401b6700();
    piVar10[0x22] = 0;
    piVar10[0x23] = 0;
  }
  lVar2 = local_1150;
  if (local_1150 != 0) {
    if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
      (*DAT_140c2c018)(1);
    }
    (*DAT_140c2be98)(lVar2,0x20,local_1128);
    FUN_1401ae370(local_10e8,0,0x448);
    uVar8 = local_1148;
    local_cb0 = local_1110;
    local_cc0 = local_1124;
    local_cbc = local_1120;
    local_cb8 = local_cb8 + 3 + ((int)(local_cb8 + 3) >> 0x1f & 3U) & 0xfffffffc;
    FUN_1401ae2f0(local_10e8,local_1148,0x428);
    param_11 = local_10e8;
    if (local_1140 != 0) {
      (*DAT_140c2be98)(local_1140,0x20,local_1108);
      FUN_1401ae370(local_c98,0,0x448);
      local_860 = local_10f0;
      local_870 = local_1104;
      local_86c = local_1100;
      local_868 = local_868 + 3 + ((int)(local_868 + 3) >> 0x1f & 3U) & 0xfffffffc;
      FUN_1401ae2f0(local_c98,uVar8,0x428);
      param_12 = local_c98;
    }
  }
  lVar2 = local_1158;
  iVar1 = local_115c;
  iVar3 = local_1160;
  if (*local_1138 == 0) {
    if (((lVar6 == 0) && (local_1158 == 0)) && (param_11 == (undefined1 *)0x0)) {
      if (piVar13 == (int *)0x0) goto LAB_140150954;
    }
    else if (piVar13 == (int *)0x0) {
      if (lVar6 == 0) {
        if (local_1158 == 0) {
          if (param_11 == (undefined1 *)0x0) goto LAB_140150c4f;
          uVar4 = FUN_14017a350(param_11);
          uVar11 = uVar4 + 0x448;
          if (param_12 != (undefined1 *)0x0) {
            uVar5 = FUN_14017a350(param_12);
            uVar11 = uVar4 + 0x890 + uVar5;
          }
          lVar6 = FUN_1401b6390((ulonglong)uVar11 + 0x50,
                                "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x76f9);
          *(longlong *)(piVar10 + 0x22) = lVar6;
          if (lVar6 == 0) {
            puVar7 = &DAT_1404a7b60;
            goto LAB_1401509f6;
          }
          FUN_1401ae370(lVar6,0,0x50);
          *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x10) = *(longlong *)(piVar10 + 0x22) + 0x50
          ;
          FUN_1401ae2f0(*(undefined8 *)(*(longlong *)(piVar10 + 0x22) + 0x10),param_11,0x448);
          *(longlong *)(*(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x10) + 0x438) =
               *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x10) + 0x448;
          FUN_1401ae2f0(*(undefined8 *)(*(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x10) + 0x438)
                        ,*(undefined8 *)(param_11 + 0x438),(ulonglong)uVar4);
          if (param_12 == (undefined1 *)0x0) goto LAB_140150c4f;
          *(ulonglong *)(*(longlong *)(piVar10 + 0x22) + 0x18) =
               *(longlong *)(*(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x10) + 0x438) +
               (ulonglong)uVar4;
          FUN_1401ae2f0(*(undefined8 *)(*(longlong *)(piVar10 + 0x22) + 0x18),param_12,0x448);
          uVar16 = (ulonglong)uVar5;
          *(longlong *)(*(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x18) + 0x438) =
               *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x18) + 0x448;
          psVar9 = *(short **)(param_12 + 0x438);
          uVar8 = *(undefined8 *)(*(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x18) + 0x438);
        }
        else {
          lVar15 = (longlong)local_115c;
          uVar16 = (ulonglong)local_1160;
          lVar6 = FUN_1401b6390(lVar15 + 0x50 + uVar16,
                                "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x76d5);
          *(longlong *)(piVar10 + 0x22) = lVar6;
          if (lVar6 == 0) {
            puVar7 = &DAT_1404a7b20;
            goto LAB_1401509f6;
          }
          FUN_1401ae370(lVar6,0,0x50);
          *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x20) = *(longlong *)(piVar10 + 0x22) + 0x50
          ;
          *(int *)(*(longlong *)(piVar10 + 0x22) + 0x28) = iVar1;
          FUN_1401ae2f0(*(undefined8 *)(*(longlong *)(piVar10 + 0x22) + 0x20),lVar2,lVar15);
          if (local_1130 == (short *)0x0) goto LAB_140150c4f;
          *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x30) =
               *(longlong *)(*(longlong *)(piVar10 + 0x22) + 0x20) + lVar15;
          *(int *)(*(longlong *)(piVar10 + 0x22) + 0x38) = iVar3;
          uVar8 = *(undefined8 *)(*(longlong *)(piVar10 + 0x22) + 0x30);
          psVar9 = local_1130;
        }
      }
      else {
        FUN_1401367e0(lVar6,local_848,0x800,0);
        while (local_848[0] != 0) {
          piVar14 = (int *)((longlong)piVar14 + 1);
          local_848[0] = local_848[(longlong)piVar14];
        }
        uVar16 = (longlong)((int)piVar14 + 1) * 2;
        lVar6 = FUN_1401b6560(uVar16 + 0x50,
                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x76c5);
        *(longlong *)(piVar10 + 0x22) = lVar6;
        if (lVar6 == 0) {
          puVar7 = &DAT_1404a7ad0;
LAB_1401509f6:
          FUN_1401594b0(puVar7);
          return 0xffffffff;
        }
        *(longlong *)(lVar6 + 8) = lVar6 + 0x50;
        uVar8 = *(undefined8 *)(*(longlong *)(piVar10 + 0x22) + 8);
        psVar9 = local_848;
      }
      FUN_1401ae2f0(uVar8,psVar9,uVar16);
LAB_140150c4f:
      *(undefined4 *)(*(longlong *)(piVar10 + 0x22) + 0x3c) = param_13;
      *(undefined4 *)(*(longlong *)(piVar10 + 0x22) + 0x40) = param_14;
      *(undefined4 *)(*(longlong *)(piVar10 + 0x22) + 0x44) = param_15;
      *(undefined4 *)(*(longlong *)(piVar10 + 0x22) + 0x48) = 1;
      return 0;
    }
    *(undefined8 *)(piVar10 + 0x22) = *(undefined8 *)(piVar13 + 0x22);
    if (*(longlong *)(piVar13 + 0x22) != 0) {
      piVar13 = (int *)(*(longlong *)(piVar13 + 0x22) + 0x48);
      *piVar13 = *piVar13 + 1;
      return 0;
    }
  }
  else {
LAB_140150954:
    piVar10[0x22] = 0;
    piVar10[0x23] = 0;
  }
  return 0;
}


