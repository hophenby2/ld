// Function: FUN_140249e20 @ 140249e20
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_140249e20(undefined8 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5,
             int param_6)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined1 auStack_168 [32];
  undefined4 *local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_128;
  undefined4 local_124;
  int local_120 [8];
  int local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  iVar4 = 0;
  uVar6 = 0;
  iVar2 = FUN_1401eed30();
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    if ((param_2 != 2) && (param_2 == 5)) {
      uVar6 = 1;
    }
    lVar1 = (longlong)param_6 + ((ulonglong)(param_4 == 1) + (ulonglong)uVar6 * 2) * 2;
    piVar5 = (int *)(&DAT_140b189fc + lVar1 * 4);
    if (*(int *)(&DAT_140b189fc + lVar1 * 4) < 0) {
      iVar2 = FUN_140248fc0((&PTR_s_BrightClipLess_pso_14066f520)[lVar1],1);
      *piVar5 = iVar2;
      if (iVar2 < 0) {
        local_140 = 0x4b0;
        local_148 = (undefined4 *)0x80;
        FUN_1401c0470((&PTR_s_BrightClipLess_pso_14066f520)[lVar1],0xffffffff,0x7ffd,local_c8);
        FUN_140159b70(&DAT_1404e8628,local_c8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar2,piVar5);
    }
    local_128 = DAT_1407cea38;
    local_124 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_120,&DAT_1407ce9e8,4);
    local_100 = 1;
    local_e8 = _DAT_1404e8f70;
    uStack_e4 = _UNK_1404e8f74;
    uStack_e0 = _UNK_1404e8f78;
    uStack_dc = _UNK_1404e8f7c;
    if (param_5 != (undefined4 *)0x0) {
      local_d8 = *param_5;
      uStack_d4 = param_5[1];
      uStack_d0 = param_5[2];
      uStack_cc = param_5[3];
    }
    local_138 = 0;
    local_148 = &local_f8;
    local_140 = 3;
    local_f8 = param_3;
    uStack_f4 = param_3;
    uStack_f0 = param_3;
    uStack_ec = param_3;
    FUN_14023dd40(&DAT_140ca5d24,3,1);
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1);
    if (0 < local_100) {
      piVar5 = local_120;
      do {
        iVar2 = *piVar5;
        if (*piVar5 == 0) {
          iVar2 = -1;
        }
        FUN_140158590(iVar4,iVar2);
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < local_100);
    }
    FUN_140158760(local_128);
    FUN_1401584b0(local_124);
    local_148 = (undefined4 *)CONCAT44(local_148._4_4_,3);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar3 = 0;
  }
  return uVar3;
}


