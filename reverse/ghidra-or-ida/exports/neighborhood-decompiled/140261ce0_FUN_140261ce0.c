// Function: FUN_140261ce0 @ 140261ce0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140261ce0(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  int local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_d8;
  lVar1 = *param_1;
  lVar2 = param_1[1];
  lVar3 = param_1[2];
  if (*(char *)((longlong)param_1 + 0x71) == '\0') {
    if (*(float *)(lVar3 + 0x14) <= DAT_1404a7e1c) {
      return 0;
    }
    local_88 = *(undefined8 *)(lVar3 + 8);
    uStack_80 = *(undefined8 *)(lVar3 + 0x10);
    local_68 = *(undefined8 *)(lVar3 + 0x28);
    uStack_60 = *(undefined8 *)(lVar3 + 0x30);
    local_78 = *(undefined8 *)(lVar3 + 0x18);
    uStack_70 = *(undefined8 *)(lVar3 + 0x20);
    local_58 = *(undefined8 *)(lVar3 + 0x38);
    uStack_50 = *(undefined8 *)(lVar3 + 0x40);
  }
  else {
    if (*(float *)(param_1 + 0x10) * *(float *)(lVar3 + 0x14) <= DAT_1404a7e1c) {
      return 0;
    }
    local_88 = CONCAT44(*(float *)(param_1 + 0xf) * *(float *)(lVar3 + 0xc),
                        *(float *)((longlong)param_1 + 0x74) * *(float *)(lVar3 + 8));
    uStack_80 = CONCAT44(*(float *)(param_1 + 0x10) * *(float *)(lVar3 + 0x14),
                         *(float *)((longlong)param_1 + 0x7c) * *(float *)(lVar3 + 0x10));
    local_68 = CONCAT44(*(float *)(param_1 + 0x13) * *(float *)(lVar3 + 0x2c),
                        *(float *)((longlong)param_1 + 0x94) * *(float *)(lVar3 + 0x28));
    uStack_60 = CONCAT44(*(float *)(param_1 + 0x14) * *(float *)(lVar3 + 0x34),
                         *(float *)((longlong)param_1 + 0x9c) * *(float *)(lVar3 + 0x30));
    local_58 = CONCAT44(*(float *)(param_1 + 0x15) * *(float *)(lVar3 + 0x3c),
                        *(float *)((longlong)param_1 + 0xa4) * *(float *)(lVar3 + 0x38));
    uStack_50 = CONCAT44(*(float *)(param_1 + 0x16) * *(float *)(lVar3 + 0x44),
                         *(float *)((longlong)param_1 + 0xac) * *(float *)(lVar3 + 0x40));
    local_78 = CONCAT44(*(float *)(param_1 + 0x11) * *(float *)(lVar3 + 0x1c),
                        *(float *)((longlong)param_1 + 0x84) * *(float *)(lVar3 + 0x18));
    uStack_70 = CONCAT44(*(float *)(param_1 + 0x12) * *(float *)(lVar3 + 0x24),
                         *(float *)((longlong)param_1 + 0x8c) * *(float *)(lVar3 + 0x20));
  }
  local_48 = *(undefined4 *)(lVar3 + 0x48);
  FUN_1401ae2f0(&DAT_1407cea94,lVar3 + 0x4c,0x10);
  DAT_1407cea4c = 1;
  DAT_140c491d4 = 1;
  FUN_1401f77e0(&local_88);
  uVar6 = 0;
  uVar5 = 0;
  if (DAT_1407cdd58 == 0) {
    uVar5 = *(undefined1 *)(lVar2 + 0x61);
  }
  FUN_1401f6b70(uVar5);
  iVar4 = *(int *)((longlong)param_1 + 0xd4);
  local_38 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  if (iVar4 == -1) {
    iVar4 = *(int *)(lVar3 + 0x1a4);
  }
  local_2c = ((float)iVar4 * *(float *)((longlong)param_1 + 0xb4)) / DAT_14053adec;
  FUN_1401f6f20(&local_38);
  FUN_140156590(*(undefined4 *)(lVar3 + 0x1a8),*(undefined4 *)(lVar3 + 0x1ac),
                *(undefined4 *)(lVar3 + 0x1b0));
  uVar7 = uVar6;
  if ((DAT_1407cdd58 == 0) && (DAT_140b198c8 != 1)) {
    uVar7 = *(uint *)(param_1 + 0x1a);
    if (uVar7 == 0xffffffff) {
      uVar7 = *(uint *)(lVar3 + 0x1a0);
    }
    if (0xe < uVar7) goto switchD_140261f89_caseD_4026202d;
  }
  switch(IMAGE_DOS_HEADER_140000000.e_magic +
         (&switchD_140261f89::switchdataD_1402620a8)[(int)uVar7]) {
  case (char *)0x140261f8b:
    if ((DAT_140b198c8 == 1) || (local_98 = 1, DAT_1407cdd88 == 0)) {
      local_98 = 0;
    }
    break;
  case (char *)0x140261fa4:
    uVar7 = 0x10;
    local_98 = DAT_1407cdd88;
    break;
  case (char *)0x140261fab:
    local_98 = DAT_1407cdd88;
    if (*(char *)(*(longlong *)(lVar1 + 8) + 0x336) == '\0') {
      uVar7 = 1;
    }
    else {
      uVar7 = 0x11;
    }
    break;
  case (char *)0x140261fe9:
    uVar7 = 0x12;
    local_98 = DAT_1407cdd88;
    if (*(char *)(*(longlong *)(lVar1 + 8) + 0x336) == '\0') {
      uVar7 = 2;
    }
    break;
  case (char *)0x14026202d:
    goto switchD_140261f89_caseD_4026202d;
  }
  local_a0 = 0;
  local_a8 = 0;
  local_b0 = 1;
  local_b8 = 0;
  FUN_1401f6a20(uVar7,0,1,0);
switchD_140261f89_caseD_4026202d:
  if ((((*(int *)(lVar2 + 0x2c) != 0) || (DAT_1404a7e20 < (float)local_68)) ||
      (DAT_1404a7e20 < local_68._4_4_)) || (DAT_1404a7e20 < (float)uStack_60)) {
    uVar6 = 1;
  }
  FUN_1401f8380(uVar6);
  FUN_1401f8c20(*(undefined4 *)(lVar2 + 0x28));
  FUN_1401f8cc0(*(undefined4 *)(lVar2 + 0x2c));
  return 1;
}


