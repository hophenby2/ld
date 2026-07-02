// Function: FUN_1401f3e00 @ 1401f3e00
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1401f3e00(longlong param_1,int *param_2,int *param_3,undefined8 param_4,int param_5,int param_6,
             int param_7,int param_8,byte *param_9,longlong param_10,longlong param_11,
             undefined4 param_12,int param_13,int param_14)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined1 auStack_168 [32];
  int local_148;
  byte *local_140;
  longlong local_138;
  int local_130;
  longlong local_128;
  undefined8 local_120;
  int *local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  uint local_c8;
  ulonglong local_c0;
  int local_b8;
  int local_b4;
  undefined8 local_b0;
  uint local_a8;
  byte *local_a0;
  undefined8 local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  int *local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined4 local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  ulonglong local_50;
  
  local_50 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  local_90 = param_10;
  iVar12 = 0;
  uVar13 = 1;
  local_b8 = param_7;
  local_b4 = param_8;
  local_a0 = param_9;
  if ((7 < *param_9) || (local_c8 = uVar13, (0xeaU >> (*param_9 & 0x1f) & 1) == 0)) {
    local_c8 = 0;
  }
  uVar11 = 0;
  local_98 = 0;
  lVar9 = 0;
  lVar4 = 0;
  local_b0 = param_4;
  local_80 = param_1;
  local_78 = param_2;
  if (local_c8 == 0) {
    if ((param_7 < param_5) && (uVar11 = 0, param_7 == param_3[2])) {
      uVar11 = uVar13;
    }
    if ((param_8 < param_6) && (lVar9 = 0, param_8 == param_3[3])) {
      lVar9 = 1;
    }
    iVar12 = (param_7 + uVar11) * (uint)*(byte *)(param_11 + 4);
    iVar7 = (param_8 + (int)lVar9) * iVar12;
    if (param_14 == 0) {
      iVar7 = FUN_14020dc10(iVar7);
      lVar4 = DAT_140c99180;
      if (-1 < iVar7) goto LAB_1401f3f66;
    }
    else {
      lVar4 = FUN_1401b6390(iVar7,
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                           );
      if (lVar4 != 0) goto LAB_1401f3f66;
      FUN_140159b70(&DAT_1404b3170);
    }
    uVar5 = 0xffffffff;
  }
  else {
LAB_1401f3f66:
    uVar5 = local_98;
    iVar7 = 0;
    lVar10 = (longlong)iVar12;
    if (*(char *)(param_1 + 9) != '\0') {
      uVar13 = 6;
    }
    local_c0 = (ulonglong)uVar11;
    local_70 = (ulonglong)local_c8;
    local_a8 = uVar13;
    local_88 = lVar9;
    do {
      piVar2 = local_78;
      if ((((*param_3 == 0) && (param_3[2] == param_5)) && (param_3[1] == 0)) &&
         (param_3[3] == param_6)) {
        if (local_70 == 0) {
LAB_1401f4098:
          local_148 = *(int *)(local_a0 + 0x430);
          local_130 = *(int *)(local_90 + 0x430);
          local_138 = (ulonglong)(uint)(*(int *)(local_90 + 0x42c) * local_130 * iVar7) +
                      *(longlong *)(local_90 + 0x438);
          if (((param_13 == 0) || (*(char *)(param_11 + 0xb) == '\0')) ||
             (*(longlong *)(local_90 + 0x438) != 0)) {
            local_108 = 0;
          }
          else {
            local_108 = 1;
          }
          local_d8 = 0;
          local_e0 = 0;
          local_e8 = param_12;
          local_f0 = 0;
          local_f8 = DAT_140824374;
          local_100 = *(undefined4 *)(local_80 + 0x1c);
          local_110 = 0;
          local_118 = local_78;
          local_120 = uVar5;
          local_128 = local_90;
          local_140 = local_a0;
          FUN_14017ae00(lVar4,iVar12,param_11,
                        (ulonglong)(uint)(*(int *)(local_a0 + 0x42c) * local_148 * iVar7) +
                        *(longlong *)(local_a0 + 0x438));
          if (local_88 != 0) {
            FUN_1401ae2f0((local_b4 - param_3[1]) * iVar12 + lVar4,
                          ((local_b4 - param_3[1]) + -1) * iVar12 + lVar4,
                          (longlong)(int)((piVar2[2] - *piVar2) * (uint)*(byte *)(param_11 + 4)));
          }
          if (local_c0 != 0) {
            bVar1 = *(byte *)(param_11 + 4);
            uVar13 = piVar2[3] - piVar2[1];
            uVar8 = (ulonglong)uVar13;
            puVar6 = (undefined4 *)((int)((local_b8 - *param_3) * (uint)bVar1) + lVar4);
            if (bVar1 == 2) {
              if (0 < (int)uVar13) {
                do {
                  *(undefined2 *)puVar6 = *(undefined2 *)((longlong)puVar6 + -2);
                  puVar6 = (undefined4 *)((longlong)puVar6 + lVar10);
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
            }
            else if ((bVar1 == 4) && (0 < (int)uVar13)) {
              do {
                *puVar6 = puVar6[-1];
                puVar6 = (undefined4 *)((longlong)puVar6 + lVar10);
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
          }
          if ((local_88 != 0) && (local_c0 != 0)) {
            bVar1 = *(byte *)(param_11 + 4);
            puVar6 = (undefined4 *)
                     ((longlong)(int)((local_b8 - *param_3) * (uint)bVar1) +
                     lVar4 + (local_b4 - param_3[1]) * iVar12);
            if (bVar1 == 2) {
              *(undefined2 *)puVar6 = *(undefined2 *)((longlong)puVar6 + (-2 - lVar10));
            }
            else if (bVar1 == 4) {
              *puVar6 = *(undefined4 *)((longlong)puVar6 + (-4 - lVar10));
            }
          }
          local_68 = *(undefined8 *)param_3;
          local_5c = param_3[2];
          local_138 = CONCAT44(local_138._4_4_,param_14);
          local_140 = (byte *)((ulonglong)local_140 & 0xffffffff00000000);
          local_58 = param_3[3];
          local_60 = 0;
          local_54 = 1;
          local_148 = iVar12;
          FUN_14021d370(local_b0,iVar7,&local_68,lVar4);
        }
        else {
          local_60 = 0;
          local_58 = param_6;
          local_5c = param_5;
          local_138 = CONCAT44(local_138._4_4_,param_14);
          local_68 = 0;
          local_54 = 1;
          local_148 = ((int)((uint)local_a0[5] * 4) >> 3) * param_5;
          iVar3 = *(int *)(local_a0 + 0x42c) * *(int *)(local_a0 + 0x428) * (uint)local_a0[5];
          local_140 = (byte *)((ulonglong)local_140 & 0xffffffff00000000);
          FUN_14021d370(local_b0,iVar7,&local_68,
                        (ulonglong)(uint)(((int)((iVar3 >> 0x1f & 7U) + iVar3) >> 3) * iVar7) +
                        *(longlong *)(local_a0 + 0x438));
        }
      }
      else {
        if (local_70 == 0) goto LAB_1401f4098;
        FUN_1401594b0(&DAT_1404b30d0);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)local_a8);
    if (((local_c8 == 0) && (param_14 != 0)) && (lVar4 != 0)) {
      FUN_1401b6700(lVar4);
    }
    uVar5 = 0;
  }
  return uVar5;
}


