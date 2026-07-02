// Function: FUN_140224950 @ 140224950
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140224950(longlong param_1,int *param_2,int *param_3,int param_4,undefined8 param_5,int param_6,
             int param_7,int param_8,int param_9,char *param_10,longlong param_11,longlong param_12,
             undefined4 param_13,int param_14,undefined4 param_15)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined8 local_140;
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
  longlong local_c8;
  int local_c0;
  int local_bc;
  int local_b8;
  char *local_b0;
  longlong local_a8;
  undefined8 local_a0;
  longlong local_98;
  int local_90;
  int *local_88;
  longlong local_80;
  undefined8 local_78;
  int local_70 [2];
  longlong local_68;
  int local_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int local_50;
  int local_4c;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  uVar8 = 0;
  local_b0 = param_10;
  local_60 = *param_3;
  iStack_5c = param_3[1];
  iStack_58 = param_3[2];
  iStack_54 = param_3[3];
  local_80 = param_11;
  local_a0 = param_5;
  local_c0 = param_8;
  local_bc = param_9;
  local_a8 = param_12;
  local_78 = 0;
  local_c8 = 0;
  if ((param_8 < param_6) && (local_c8 = 0, param_8 == iStack_58)) {
    iStack_58 = iStack_58 + 1;
    local_c8 = 1;
  }
  local_98 = 0;
  if ((param_9 < param_7) && (local_98 = 0, param_9 == iStack_54)) {
    iStack_54 = iStack_54 + 1;
    local_98 = 1;
  }
  local_90 = 1;
  uVar10 = uVar8;
  local_b8 = param_4;
  local_88 = param_2;
  if (*(char *)(param_1 + 9) != '\0') {
    local_90 = 6;
  }
  while( true ) {
    iVar9 = (int)uVar10;
    if (local_b8 == 0) {
      if (*(char *)(param_1 + 9) == '\0') {
        local_140 = (char *)CONCAT44(local_140._4_4_,param_15);
        local_148 = (int *)((ulonglong)local_148 & 0xffffffff00000000);
        iVar3 = FUN_1402230e0(local_a0,0,local_70,&local_60);
        iVar4 = -1;
      }
      else {
        local_138 = CONCAT44(local_138._4_4_,param_15);
        local_148 = &local_60;
        local_140 = (char *)((ulonglong)local_140._4_4_ << 0x20);
        iVar3 = FUN_1402204c0(local_a0,uVar10,0,local_70);
        iVar4 = -1;
      }
    }
    else {
      iVar4 = FUN_14023ba80(param_6,param_7,
                            *(undefined4 *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                            param_15);
      while (iVar4 == -1) {
        iVar4 = FUN_1401ad850();
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        FUN_1401b7120(1);
        iVar4 = FUN_14023ba80(param_6,param_7,
                              *(undefined4 *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                              param_15);
      }
      local_148._4_4_ = (undefined4)((ulonglong)local_148 >> 0x20);
      local_148 = (int *)CONCAT44(local_148._4_4_,param_15);
      uVar8 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
      iVar3 = FUN_140222ed0(uVar8,local_70,&local_60,0x2000);
    }
    if (iVar3 != 0) break;
    if (((((*param_3 == 0) && (param_3[2] == param_6)) && (param_3[1] == 0)) &&
        (param_3[3] == param_7)) &&
       ((((((cVar1 = *local_b0, cVar1 == '\x01' &&
            (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x31545844)) ||
           ((cVar1 == '\x02' &&
            (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x32545844)))) ||
          ((cVar1 == '\x03' &&
           (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x33545844)))) ||
         ((cVar1 == '\x04' &&
          (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x34545844)))) ||
        ((cVar1 == '\x05' &&
         (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x35545844)))))) {
      iVar3 = (uint)(byte)local_b0[5] * *(int *)(local_b0 + 0x42c) * *(int *)(local_b0 + 0x428);
      FUN_1401ae2f0(local_68,(ulonglong)(uint)(((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) * iVar9) +
                             *(longlong *)(local_b0 + 0x438));
    }
    else if ((*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) + 0xceaba7bcU <
              0x4000001) &&
            ((*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) + 0xceaba7bcU &
             0xffffff) == 0)) {
      FUN_1401594b0(&DAT_1404b30d0);
    }
    else {
      local_130 = *(int *)(local_80 + 0x430);
      local_138 = (ulonglong)(uint)(*(int *)(local_80 + 0x42c) * local_130 * iVar9) +
                  *(longlong *)(local_80 + 0x438);
      if (((param_14 == 0) || (*(char *)(local_a8 + 0xb) == '\0')) ||
         (*(longlong *)(local_80 + 0x438) != 0)) {
        local_108 = 0;
      }
      else {
        local_108 = 1;
      }
      local_d8 = 0;
      local_e0 = 0;
      local_e8 = param_13;
      local_f0 = 0;
      local_f8 = DAT_140824374;
      local_100 = *(undefined4 *)(param_1 + 0x1c);
      local_110 = 0;
      local_118 = local_88;
      local_120 = 0;
      local_128 = local_80;
      local_140 = local_b0;
      local_148 = (int *)CONCAT44(local_148._4_4_,*(int *)(local_b0 + 0x430));
      FUN_14017ae00(local_68,local_70[0],local_a8,
                    (ulonglong)
                    (uint)(*(int *)(local_b0 + 0x42c) * *(int *)(local_b0 + 0x430) * iVar9) +
                    *(longlong *)(local_b0 + 0x438));
      if (local_98 != 0) {
        FUN_1401ae2f0((local_bc - param_3[1]) * local_70[0] + local_68,
                      ((local_bc - param_3[1]) + -1) * local_70[0] + local_68,
                      (longlong)(int)((local_88[2] - *local_88) * (uint)*(byte *)(local_a8 + 4)));
      }
      if (local_c8 != 0) {
        bVar2 = *(byte *)(local_a8 + 4);
        uVar6 = local_88[3] - local_88[1];
        uVar7 = (ulonglong)uVar6;
        puVar5 = (undefined4 *)((int)((local_c0 - *param_3) * (uint)bVar2) + local_68);
        if (bVar2 == 2) {
          if (0 < (int)uVar6) {
            do {
              *(undefined2 *)puVar5 = *(undefined2 *)((longlong)puVar5 + -2);
              puVar5 = (undefined4 *)((longlong)puVar5 + (longlong)local_70[0]);
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
        }
        else if ((bVar2 == 4) && (0 < (int)uVar6)) {
          do {
            *puVar5 = puVar5[-1];
            puVar5 = (undefined4 *)((longlong)puVar5 + (longlong)local_70[0]);
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
      }
      if ((local_98 != 0) && (local_c8 != 0)) {
        bVar2 = *(byte *)(local_a8 + 4);
        puVar5 = (undefined4 *)
                 ((longlong)(int)((local_c0 - *param_3) * (uint)bVar2) +
                 (local_bc - param_3[1]) * local_70[0] + local_68);
        if (bVar2 == 2) {
          *(undefined2 *)puVar5 = *(undefined2 *)((longlong)puVar5 + (-2 - (longlong)local_70[0]));
        }
        else if (bVar2 == 4) {
          *puVar5 = *(undefined4 *)((longlong)puVar5 + (-4 - (longlong)local_70[0]));
        }
      }
    }
    if (local_b8 == 0) {
      if (*(char *)(param_1 + 9) == '\0') {
        FUN_1402231b0(local_a0,0);
      }
      else {
        FUN_1402205c0(local_a0,uVar10,0,param_15);
      }
    }
    else {
      local_78 = 0;
      FUN_140222fa0(uVar8,param_15);
      if (*(char *)(param_1 + 9) == '\0') {
        FUN_140223040(local_a0,0,&local_78,param_15);
      }
      else {
        local_148 = (int *)CONCAT44(local_148._4_4_,param_15);
        FUN_140220400(local_a0,uVar10,0,&local_78);
      }
      local_50 = local_60;
      local_4c = iStack_5c;
      local_148 = (int *)CONCAT44(local_148._4_4_,param_15);
      FUN_140222ba0(uVar8,&local_60,local_78,&local_50);
      FUN_140220340(local_78,param_15);
      FUN_14023c5b0(iVar4,param_15);
    }
    uVar10 = (ulonglong)(iVar9 + 1U);
    if (local_90 <= (int)(iVar9 + 1U)) {
      return 0;
    }
  }
  FUN_1401594b0(&DAT_1404e7fd8);
  return 0xffffffff;
}


