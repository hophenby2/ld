// Function: FUN_14024d2a0 @ 14024d2a0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_14024d2a0(undefined8 param_1,float param_2,undefined8 *param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined1 auStack_168 [32];
  undefined4 *local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_128;
  undefined4 local_124;
  int local_120 [8];
  int local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  float local_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  lVar4 = (longlong)param_5;
  param_2 = param_2 / DAT_14053adec;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    piVar5 = (int *)(&DAT_140b18a64 + lVar4 * 4);
    if (*(int *)(&DAT_140b18a64 + lVar4 * 4) < 0) {
      iVar1 = FUN_140248fc0((&PTR_s_TwoColor_pso_14066f5c0)[lVar4],1);
      *piVar5 = iVar1;
      if (iVar1 < 0) {
        local_140 = 0x4b0;
        local_148 = (undefined4 *)0x80;
        FUN_1401c0470((&PTR_s_TwoColor_pso_14066f5c0)[lVar4],0xffffffff,0x7ffd,local_c8);
        FUN_140159b70(&DAT_1404e8628,local_c8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar1,piVar5);
    }
    local_128 = DAT_1407cea38;
    local_124 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_120,&DAT_1407ce9e8,4);
    local_148 = &local_f8;
    local_f4 = DAT_1404e8e3c;
    iVar1 = 0;
    local_e8 = *param_3;
    uStack_e0 = param_3[1];
    local_138 = 0;
    local_f8 = DAT_1404e8e38;
    local_140 = 3;
    local_d8 = *param_4;
    uStack_d4 = param_4[1];
    uStack_d0 = param_4[2];
    uStack_cc = param_4[3];
    local_100 = 1;
    local_f0 = DAT_1404e8e34;
    local_ec = param_2;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_100) {
      piVar5 = local_120;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < local_100);
    }
    FUN_140158760(local_128);
    FUN_1401584b0(local_124);
    local_148 = (undefined4 *)CONCAT44(local_148._4_4_,3);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar2 = 0;
  }
  return uVar2;
}


