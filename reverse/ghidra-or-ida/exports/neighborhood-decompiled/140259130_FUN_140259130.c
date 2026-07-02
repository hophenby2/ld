// Function: FUN_140259130 @ 140259130
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140259130(int *param_1,int *param_2,int *param_3,int *param_4,undefined4 *param_5,
             longlong *param_6,uint *param_7)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_f8 [32];
  longlong local_d8;
  longlong local_d0;
  uint *local_c8;
  longlong local_c0;
  int *local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_f8;
  plVar2 = (longlong *)param_6[2];
  local_c8 = param_7;
  local_d8 = *param_6;
  local_d0 = param_6[1];
  local_c0 = *plVar2;
  if (*(char *)((longlong)param_6 + 0x71) == '\0') {
    if (*(float *)((longlong)plVar2 + 0x14) <= DAT_1404a7e1c) {
      return 0;
    }
    local_a8 = plVar2[1];
    uStack_a0 = plVar2[2];
    local_88 = plVar2[5];
    uStack_80 = plVar2[6];
    local_98 = plVar2[3];
    uStack_90 = plVar2[4];
    local_78 = plVar2[7];
    uStack_70 = plVar2[8];
  }
  else {
    if (*(float *)(param_6 + 0x10) * *(float *)((longlong)plVar2 + 0x14) <= DAT_1404a7e1c) {
      return 0;
    }
    local_a8 = CONCAT44(*(float *)(param_6 + 0xf) * *(float *)((longlong)plVar2 + 0xc),
                        *(float *)((longlong)param_6 + 0x74) * *(float *)(plVar2 + 1));
    uStack_a0 = CONCAT44(*(float *)(param_6 + 0x10) * *(float *)((longlong)plVar2 + 0x14),
                         *(float *)((longlong)param_6 + 0x7c) * *(float *)(plVar2 + 2));
    local_88 = CONCAT44(*(float *)(param_6 + 0x13) * *(float *)((longlong)plVar2 + 0x2c),
                        *(float *)((longlong)param_6 + 0x94) * *(float *)(plVar2 + 5));
    uStack_80 = CONCAT44(*(float *)(param_6 + 0x14) * *(float *)((longlong)plVar2 + 0x34),
                         *(float *)((longlong)param_6 + 0x9c) * *(float *)(plVar2 + 6));
    local_78 = CONCAT44(*(float *)(param_6 + 0x15) * *(float *)((longlong)plVar2 + 0x3c),
                        *(float *)((longlong)param_6 + 0xa4) * *(float *)(plVar2 + 7));
    uStack_70 = CONCAT44(*(float *)(param_6 + 0x16) * *(float *)((longlong)plVar2 + 0x44),
                         *(float *)((longlong)param_6 + 0xac) * *(float *)(plVar2 + 8));
    local_98 = CONCAT44(*(float *)(param_6 + 0x11) * *(float *)((longlong)plVar2 + 0x1c),
                        *(float *)((longlong)param_6 + 0x84) * *(float *)(plVar2 + 3));
    uStack_90 = CONCAT44(*(float *)(param_6 + 0x12) * *(float *)((longlong)plVar2 + 0x24),
                         *(float *)((longlong)param_6 + 0x8c) * *(float *)(plVar2 + 4));
  }
  local_68 = (undefined4)plVar2[9];
  local_b8 = param_3;
  FUN_1401ae2f0(&DAT_1407cea94,(longlong)plVar2 + 0x4c,0x10);
  DAT_1407cea4c = 1;
  DAT_140d3ad94 = 1;
  FUN_140229870(&local_a8);
  uVar6 = 0;
  uVar7 = 0;
  uVar9 = uVar6;
  if (DAT_1407cdd58 == 0) {
    uVar9 = (uint)*(byte *)(local_d0 + 0x61);
  }
  FUN_1402286b0(uVar9);
  FUN_140156590((int)plVar2[0x35],*(undefined4 *)((longlong)plVar2 + 0x1ac),(int)plVar2[0x36]);
  puVar4 = local_c8;
  lVar3 = local_d0;
  param_5[4] = 0;
  *(undefined8 *)(param_5 + 9) = 0xffffffffffffffff;
  param_5[0xb] = 0xffffffff;
  *param_5 = *(undefined4 *)((longlong)plVar2 + 0x194);
  param_5[2] = (int)plVar2[0x33];
  param_5[1] = *(undefined4 *)((longlong)plVar2 + 0x19c);
  iVar8 = *(int *)((longlong)param_6 + 0xd4);
  if (iVar8 == -1) {
    iVar8 = *(int *)((longlong)plVar2 + 0x1a4);
  }
  param_5[5] = (int)((float)iVar8 * *(float *)((longlong)param_6 + 0xb4)) << 0x18 | 0xffffff;
  if (DAT_1407cdd58 == 0) {
    uVar7 = *(uint *)(param_6 + 0x1a);
    if (uVar7 == 0xffffffff) {
      uVar7 = *(uint *)(plVar2 + 0x34);
    }
    if (0xe < uVar7) goto switchD_14025941f_caseD_5;
  }
  switch(uVar7) {
  default:
    param_5[3] = 0;
    param_5[6] = DAT_140d7aa90;
    param_5[7] = DAT_140d7aa94;
    param_5[8] = DAT_140d7aa98;
    goto switchD_14025941f_caseD_5;
  case 1:
    param_5[3] = 1;
    cVar1 = *(char *)(*(longlong *)(local_d8 + 8) + 0x336);
    param_5[7] = 6;
    uVar5 = 5;
    if (cVar1 != '\0') {
      uVar5 = 2;
    }
    param_5[6] = uVar5;
    goto LAB_14025950e;
  case 2:
    param_5[3] = 1;
    cVar1 = *(char *)(*(longlong *)(local_d8 + 8) + 0x336);
    param_5[7] = 2;
    uVar5 = 5;
    if (cVar1 != '\0') {
      uVar5 = 2;
    }
    param_5[6] = uVar5;
    goto LAB_14025950e;
  case 3:
    param_5[3] = 1;
    cVar1 = *(char *)(*(longlong *)(local_d8 + 8) + 0x336);
    param_5[7] = 2;
    uVar5 = 5;
    if (cVar1 != '\0') {
      uVar5 = 2;
    }
    param_5[8] = 3;
    param_5[6] = uVar5;
    goto switchD_14025941f_caseD_5;
  case 4:
  case 0xb:
    param_5[6] = 1;
    param_5[7] = 3;
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
    goto switchD_14025941f_caseD_5;
  case 10:
    param_5[7] = 6;
    param_5[6] = 5;
    break;
  case 0xe:
    param_5[7] = 1;
    param_5[6] = 2;
  }
  param_5[3] = 1;
LAB_14025950e:
  param_5[8] = 1;
switchD_14025941f_caseD_5:
  param_5[0xc] = *(undefined4 *)((longlong)plVar2 + 0x5c);
  if ((((*(int *)(local_d0 + 0x2c) != 0) || (DAT_1404a7e20 < (float)local_88)) ||
      (DAT_1404a7e20 < local_88._4_4_)) || (DAT_1404a7e20 < (float)uStack_80)) {
    uVar6 = 1;
  }
  *local_c8 = uVar6;
  if (DAT_1407cd8d4 == 0) {
    if (*(int *)(*plVar2 + 0x10) - 1U < 2) {
      uVar6 = 0;
    }
    *local_c8 = uVar6;
  }
  FUN_14022a0e0(*local_c8);
  if ((DAT_1407cd8d4 == 0) && (*(int *)(*plVar2 + 0x10) - 1U < 2)) {
    FUN_1402287a0(1);
    uVar5 = 1;
  }
  else {
    FUN_1402287a0(*(undefined4 *)(lVar3 + 0x28));
    uVar5 = *(undefined4 *)(lVar3 + 0x2c);
  }
  FUN_14022a150(uVar5);
  if (*(int *)(*plVar2 + 0x10) - 1U < 8) {
    FUN_140229790(0);
  }
  else {
    FUN_140158470(DAT_1407cea48 == 0);
  }
  if (*(int *)(*plVar2 + 0x10) - 3U < 6) {
    *param_4 = *param_4 + ((*param_4 / 2) % 0x54) * -2;
    *param_2 = *param_2 + ((*param_2 / 2) % 10) * -2;
    iVar8 = *param_1 / 0xf00;
    iVar8 = *param_1 +
            (iVar8 + (iVar8 / 3 + (iVar8 >> 0x1f) +
                     (int)(((longlong)iVar8 / 3 + ((longlong)iVar8 >> 0x3f) & 0xffffffffU) >> 0x1f))
                     * -3) * -0xf00;
    iVar8 = iVar8 + ((iVar8 / 2) % 0x14) * -2;
    uVar7 = iVar8 / 0x28 & 0x80000003;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
    }
    iVar8 = iVar8 + uVar7 * -0x28;
    uVar7 = iVar8 / 0xa0 & 0x80000001;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
    }
    uVar9 = iVar8 + uVar7 * -0xa0;
    uVar7 = uVar9 & 0x80000001;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
    }
    *param_1 = uVar9 - uVar7;
    *param_2 = *param_2 + *(int *)(*plVar2 + 0x10) * 0x38400;
  }
  iVar8 = *(int *)(*plVar2 + 0x10);
  if (iVar8 - 1U < 2) {
    if (iVar8 == 1) {
      *param_2 = *param_2 + 0x780;
      *param_4 = *param_4 + 0x27600;
      if ((int)plVar2[0x2e] == 2) {
        *param_2 = *param_2 + 0xa0;
        *param_4 = *param_4 + 0x540;
      }
      if ((*(int *)((longlong)plVar2 + 0x174) == 1) && (*puVar4 != 0)) {
        *param_2 = *param_2 + 0x50;
        *param_4 = *param_4 + 0x2a0;
      }
    }
    else if (iVar8 == 2) {
      *param_2 = *param_2 + 0xb40;
      *param_4 = *param_4 + 0x29580;
      if (-1 < *(int *)((longlong)plVar2 + 0x16c)) {
        if ((int)plVar2[0x2f] == 2) {
          *param_2 = *param_2 + 0x140;
          *param_4 = *param_4 + 0xa80;
        }
        else if ((int)plVar2[0x2f] == 1) {
          *param_2 = *param_2 + 0x280;
          *param_4 = *param_4 + 0x1500;
        }
      }
    }
  }
  if (1 < *(int *)((longlong)plVar2 + 0x5c)) {
    *param_2 = *param_2 + *(int *)((longlong)plVar2 + 0x7c) * 0xf00 + 0xf00;
    *param_4 = *param_4 + *(int *)((longlong)plVar2 + 0x7c) * 0x3f00 + 0x3f00;
  }
  if (*(int *)(local_c0 + 0x170) != 0) {
    *param_1 = *param_1 + 0xa0;
    *param_2 = *param_2 + 0x14;
    *local_b8 = *local_b8 + 4;
    *param_4 = *param_4 + 0xa8;
  }
  if (*puVar4 != 0) {
    *param_1 = *param_1 + 1;
    *param_2 = *param_2 + 1;
    *param_4 = *param_4 + 1;
  }
  if ((int)plVar2[0x1c] != 0) {
    *param_2 = *param_2 + 0x28;
    *param_4 = *param_4 + 0x150;
  }
  return 1;
}


