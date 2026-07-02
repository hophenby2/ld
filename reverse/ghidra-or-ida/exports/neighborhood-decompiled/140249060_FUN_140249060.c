// Function: FUN_140249060 @ 140249060
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140249060(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined1 auStack_128 [32];
  undefined4 *local_108;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0 [8];
  int local_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1407c6b00 ^ (ulonglong)auStack_128;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar4 = (longlong)*(int *)(param_1 + 0xc);
    piVar5 = (int *)(&DAT_140b18ab8 + lVar4 * 4);
    if (*(int *)(&DAT_140b18ab8 + lVar4 * 4) < 0) {
      iVar1 = FUN_140248fc0((&PTR_s_BasBF_Normal_pso_14066f640)[lVar4],1);
      *piVar5 = iVar1;
      if (iVar1 < 0) {
        local_100 = 0x4b0;
        local_108 = (undefined4 *)0x80;
        FUN_1401c0470((&PTR_s_BasBF_Normal_pso_14066f640)[lVar4],0xffffffff,0x7ffd,local_98);
        FUN_140159b70(&DAT_1404e8628,local_98);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar1,piVar5);
    }
    local_e8 = DAT_1407cea38;
    local_e4 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_e0,&DAT_1407ce9e8,8);
    local_b8 = *(undefined4 *)(param_1 + 0x20);
    local_108 = &local_b8;
    iVar1 = 0;
    local_f8 = 0;
    local_100 = 2;
    local_c0 = 2;
    local_a8 = _DAT_1404ad450;
    uStack_a4 = _UNK_1404ad454;
    uStack_a0 = _UNK_1404ad458;
    uStack_9c = _UNK_1404ad45c;
    uStack_b4 = local_b8;
    uStack_b0 = local_b8;
    uStack_ac = local_b8;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_c0) {
      piVar5 = local_e0;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < local_c0);
    }
    FUN_140158760(local_e8);
    FUN_1401584b0(local_e4);
    local_108 = (undefined4 *)CONCAT44(local_108._4_4_,2);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar2 = 0;
  }
  return uVar2;
}


