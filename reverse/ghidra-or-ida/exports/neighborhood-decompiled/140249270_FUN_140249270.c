// Function: FUN_140249270 @ 140249270
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140249270(longlong param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined *puVar7;
  longlong lVar8;
  undefined1 auStack_1b8 [32];
  undefined4 *local_198;
  undefined *local_190;
  undefined *local_188;
  undefined *local_180;
  uint local_178;
  int local_174;
  int local_170;
  undefined4 local_168;
  undefined4 local_164;
  int local_160 [8];
  int local_140;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  undefined1 local_118 [64];
  undefined1 local_d8 [128];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_1b8;
  lVar8 = (longlong)param_6;
  iVar4 = 0;
  local_170 = param_6;
  local_174 = 0;
  local_178 = param_5;
  iVar2 = FUN_1401eed30();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_140156d20(0);
  if ((((param_2 - 8 < 8) || (param_3 - 8 < 8)) || (param_4 - 8 < 8)) || (param_5 - 8 < 8)) {
LAB_1402495ad:
    piVar6 = (int *)(&DAT_140b18b48 + lVar8 * 4);
    if (-1 < *(int *)(&DAT_140b18b48 + lVar8 * 4)) goto LAB_1402496ed;
    iVar2 = FUN_140248fc0((&PTR_s_RGBAMix_Base_pso_14066f760)[lVar8],1);
    *piVar6 = iVar2;
    if (iVar2 < 0) {
      local_190 = (undefined *)CONCAT44(local_190._4_4_,0x4b0);
      local_198 = (undefined4 *)0x80;
      FUN_1401c0470((&PTR_s_RGBAMix_Base_pso_14066f760)[local_170],0xffffffff,0x7ffd,local_d8);
      FUN_140159b70(&DAT_1404e8628,local_d8);
      return 0xffffffff;
    }
  }
  else {
    if ((((*(int *)(*(longlong *)(param_1 + 0xd58) + 0xb8) !=
           *(int *)(*(longlong *)(param_1 + 0xd48) + 0xb8)) ||
         (*(int *)(*(longlong *)(param_1 + 0xd58) + 0xbc) !=
          *(int *)(*(longlong *)(param_1 + 0xd48) + 0xbc))) ||
        ((*(int *)(param_1 + 0x44) != 0 &&
         ((*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x28) ||
          (*(int *)(param_1 + 0x40) != *(int *)(param_1 + 0x2c))))))) ||
       ((*(int *)(param_1 + 0x50) != 0 &&
        ((*(int *)(param_1 + 0x48) != *(int *)(param_1 + 0x30) ||
         (*(int *)(param_1 + 0x4c) != *(int *)(param_1 + 0x34))))))) goto LAB_1402495ad;
    if ((param_2 < 4) && (((param_3 < 4 && (param_4 < 4)) && (uVar5 = param_5, param_5 < 4)))) {
LAB_1402493e3:
      lVar8 = lVar8 + ((longlong)(int)uVar5 +
                      ((longlong)(int)param_4 +
                      ((longlong)(int)param_3 + (longlong)(int)param_2 * 4) * 4) * 4) * 2;
      piVar6 = (int *)(&DAT_140b18bf0 + lVar8 * 4);
      if ((-1 < *(int *)(&DAT_140b18bf0 + lVar8 * 4)) || (DAT_140d8df68 == 0)) goto LAB_1402496ed;
      iVar2 = FUN_140155c80((&DAT_140d8df70)[lVar8],(int)(short)(&DAT_140d8ef70)[lVar8]);
      *piVar6 = iVar2;
      if (iVar2 < 0) {
        FUN_140159b70(&DAT_1404e8d80);
        return 0xffffffff;
      }
    }
    else {
      uVar3 = param_2 - 4;
      if ((((uVar3 < 4) && (param_3 - 4 < 4)) && (param_4 - 4 < 4)) &&
         (uVar5 = param_5 - 4, uVar5 < 4)) {
        uVar1 = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x10) = uVar1;
        local_174 = 1;
        param_2 = uVar3;
        param_3 = param_3 - 4;
        param_4 = param_4 - 4;
        local_178 = uVar5;
        goto LAB_1402493e3;
      }
      if (((param_2 != param_3) || (param_2 != param_4)) || ((param_2 - 3 & 0xfffffffb) == 0)) {
        if (param_2 == 0) {
          if ((param_3 == 1) && (param_4 == 2)) {
LAB_140249674:
            lVar8 = lVar8 + (longlong)(int)(param_5 - 4) * 2;
            piVar6 = (int *)(&DAT_140b18b50 + lVar8 * 4);
            if (-1 < *(int *)(&DAT_140b18b50 + lVar8 * 4)) goto LAB_1402496ed;
            local_180 = &DAT_1404b7235;
            local_188 = (&PTR_DAT_14066f770)[(int)(param_5 - 4)];
            if (local_170 != 0) {
              local_180 = &DAT_1404e8dc0;
            }
            local_190 = (&PTR_DAT_14066f770)[(int)param_4];
            local_198 = (undefined4 *)PTR_DAT_14066f778;
            puVar7 = PTR_DAT_14066f770;
            goto LAB_140249522;
          }
        }
        else if (((param_2 == 4) && (param_3 == 5)) && (param_4 == 6)) {
          uVar1 = *(undefined4 *)(param_1 + 0x14);
          param_3 = 1;
          param_5 = param_5 + 4;
          local_174 = 1;
          param_4 = 2;
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
          *(undefined4 *)(param_1 + 0x10) = uVar1;
          param_2 = 0;
          local_178 = param_5;
          goto LAB_140249674;
        }
        goto LAB_1402495ad;
      }
      if (uVar3 < 4) {
        param_3 = param_3 - 4;
        param_4 = param_4 - 4;
        local_174 = 1;
        param_5 = param_5 + 4;
        uVar1 = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x10) = uVar1;
        param_2 = uVar3;
        local_178 = param_5;
      }
      lVar8 = lVar8 + ((longlong)(int)(param_5 - 4) + (longlong)(int)param_2 * 4) * 2;
      piVar6 = (int *)(&DAT_140b18b70 + lVar8 * 4);
      if (-1 < *(int *)(&DAT_140b18b70 + lVar8 * 4)) goto LAB_1402496ed;
      local_180 = &DAT_1404b7235;
      local_188 = (&PTR_DAT_14066f770)[(int)(param_5 - 4)];
      if (local_170 != 0) {
        local_180 = &DAT_1404e8dc0;
      }
      local_190 = (&PTR_DAT_14066f770)[(int)param_4];
      local_198 = (undefined4 *)(&PTR_DAT_14066f770)[(int)param_3];
      puVar7 = (&PTR_DAT_14066f770)[(int)param_2];
LAB_140249522:
      FUN_1401ae630(local_118,0x40,"RGBAMix_S%sS%sS%sB%s%s.pso",puVar7);
      iVar2 = FUN_140248fc0(local_118,1);
      *piVar6 = iVar2;
      if (iVar2 < 0) {
        local_190 = (undefined *)CONCAT44(local_190._4_4_,0x4b0);
        local_198 = (undefined4 *)0x80;
        FUN_1401c0470(local_118,0xffffffff,0x7ffd,local_d8);
        FUN_140159b70(&DAT_1404e8df0,local_d8);
        return 0xffffffff;
      }
    }
  }
  FUN_1401b7da0(iVar2,piVar6);
LAB_1402496ed:
  local_168 = DAT_1407cea38;
  local_164 = DAT_1407cea40;
  FUN_14023de90(&DAT_140ca5d24,3);
  FUN_1401ae2f0(local_160,&DAT_1407ce9e8,8);
  local_198 = &local_138;
  local_138 = *(undefined4 *)(param_1 + 0x20);
  local_188 = (undefined *)((ulonglong)local_188 & 0xffffffff00000000);
  local_190 = (undefined *)CONCAT44(local_190._4_4_,2);
  local_140 = 2;
  local_128 = (float)(int)param_2 + DAT_140539d20;
  local_120 = (float)(int)param_4 + DAT_140539d20;
  local_124 = (float)(int)param_3 + DAT_140539d20;
  local_11c = (float)(int)local_178 + DAT_140539d20;
  uStack_134 = local_138;
  uStack_130 = local_138;
  uStack_12c = local_138;
  FUN_14023dd40(&DAT_140ca5d24,3,1);
  FUN_1401584b0(*piVar6);
  FUN_1402482c0(param_1,1);
  if (0 < local_140) {
    piVar6 = local_160;
    do {
      iVar2 = *piVar6;
      if (*piVar6 == 0) {
        iVar2 = -1;
      }
      FUN_140158590(iVar4,iVar2);
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 < local_140);
  }
  FUN_140158760(local_168);
  FUN_1401584b0(local_164);
  if (local_174 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = uVar1;
  }
  local_198 = (undefined4 *)CONCAT44(local_198._4_4_,2);
  FUN_14023dc20(&DAT_140ca5d24,3,1);
  return 0;
}


