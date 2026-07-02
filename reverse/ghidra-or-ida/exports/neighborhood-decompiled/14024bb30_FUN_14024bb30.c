// Function: FUN_14024bb30 @ 14024bb30
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14024bb30(undefined8 param_1,undefined4 param_2,int param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined1 auStack_148 [32];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined4 local_108;
  undefined4 local_104;
  int local_100 [8];
  int local_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  iVar2 = FUN_1401eed30();
  if (iVar2 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    iVar2 = 0;
    lVar1 = (longlong)param_4 + (ulonglong)(param_3 != 0) * 2;
    piVar5 = (int *)(&DAT_140b18a6c + lVar1 * 4);
    if (*(int *)(&DAT_140b18a6c + lVar1 * 4) < 0) {
      iVar3 = FUN_140248fc0((&PTR_s_GradientMap_pso_14066f5d0)[lVar1],1);
      *piVar5 = iVar3;
      if (iVar3 < 0) {
        local_120 = 0x4b0;
        local_128 = (undefined4 *)0x80;
        FUN_1401c0470((&PTR_s_GradientMap_pso_14066f5d0)[lVar1],0xffffffff,0x7ffd,local_c8);
        FUN_140159b70(&DAT_1404e8628,local_c8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar3,piVar5);
    }
    local_108 = DAT_1407cea38;
    local_104 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_100,&DAT_1407ce9e8,8);
    local_128 = &local_d8;
    local_118 = 0;
    local_120 = 1;
    local_e0 = 2;
    local_d8 = _DAT_1404e8f70;
    uStack_d4 = _UNK_1404e8f74;
    uStack_d0 = _UNK_1404e8f78;
    uStack_cc = _UNK_1404e8f7c;
    FUN_14023dd40(&DAT_140ca5d24,3,1);
    FUN_1401584b0(*piVar5);
    FUN_140158590(1,param_2);
    FUN_1402482c0(param_1,1);
    if (0 < local_e0) {
      piVar5 = local_100;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar2,iVar3);
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < local_e0);
    }
    FUN_140158760(local_108);
    FUN_1401584b0(local_104);
    local_128 = (undefined4 *)CONCAT44(local_128._4_4_,1);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar4 = 0;
  }
  return uVar4;
}


