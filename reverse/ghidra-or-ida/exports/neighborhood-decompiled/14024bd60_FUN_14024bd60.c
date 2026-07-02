// Function: FUN_14024bd60 @ 14024bd60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_14024bd60(longlong param_1,int param_2,undefined4 param_3,float param_4,undefined4 param_5,
             int param_6)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_158 [32];
  undefined4 *local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined4 local_118;
  undefined4 local_114;
  int local_110 [8];
  int local_f0;
  undefined4 local_e8;
  float local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined4 local_bc;
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_158;
  iVar2 = FUN_1401eed30();
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    iVar2 = 2;
    if (param_2 != 1) {
      iVar2 = *(int *)(param_1 + 0x24);
    }
    lVar1 = (longlong)param_6 + (longlong)iVar2 * 2;
    piVar5 = (int *)(&DAT_140b18a30 + lVar1 * 4);
    if (*(int *)(&DAT_140b18a30 + lVar1 * 4) < 0) {
      iVar2 = FUN_140248fc0((&PTR_s_Hsb_RGB_TO_HSB_pso_14066f570)[lVar1],1);
      *piVar5 = iVar2;
      if (iVar2 < 0) {
        local_130 = 0x4b0;
        local_138 = (undefined4 *)0x80;
        FUN_1401c0470((&PTR_s_Hsb_RGB_TO_HSB_pso_14066f570)[lVar1],0xffffffff,0x7ffd,local_b8);
        FUN_140159b70(&DAT_1404e8628,local_b8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar2,piVar5);
    }
    local_118 = DAT_1407cea38;
    local_114 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_110,&DAT_1407ce9e8,4);
    local_f0 = 1;
    if (0.0 < param_4) {
      param_4 = param_4 * DAT_14053aa20;
    }
    local_138 = &local_e8;
    local_e0 = param_5;
    iVar2 = 0;
    local_cc = _DAT_1404e8fa0;
    uStack_c4 = _UNK_1404e8fa8;
    local_128 = 0;
    local_130 = 3;
    local_bc = DAT_140539da8;
    local_dc = _DAT_1404e8f80;
    uStack_d8 = _UNK_1404e8f84;
    uStack_d4 = _UNK_1404e8f88;
    uStack_d0 = _UNK_1404e8f8c;
    local_e8 = param_3;
    local_e4 = param_4;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_f0) {
      piVar5 = local_110;
      do {
        iVar4 = *piVar5;
        if (*piVar5 == 0) {
          iVar4 = -1;
        }
        FUN_140158590(iVar2,iVar4);
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < local_f0);
    }
    FUN_140158760(local_118);
    FUN_1401584b0(local_114);
    local_138 = (undefined4 *)CONCAT44(local_138._4_4_,3);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar3 = 0;
  }
  return uVar3;
}


