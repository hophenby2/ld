// Function: FUN_14024c880 @ 14024c880
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_14024c880(undefined8 param_1,float param_2,float param_3,undefined8 param_4,undefined4 param_5,
             undefined4 param_6,int param_7)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined1 auStack_138 [32];
  float *local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_f0 [8];
  int local_d0;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_138;
  lVar4 = (longlong)param_7;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    piVar5 = (int *)(&DAT_140b18a54 + lVar4 * 4);
    if (*(int *)(&DAT_140b18a54 + lVar4 * 4) < 0) {
      iVar1 = FUN_140248fc0((&PTR_s_Level_pso_14066f5b0)[lVar4],1);
      *piVar5 = iVar1;
      if (iVar1 < 0) {
        local_110 = 0x4b0;
        local_118 = (float *)0x80;
        FUN_1401c0470((&PTR_s_Level_pso_14066f5b0)[lVar4],0xffffffff,0x7ffd,local_b8);
        FUN_140159b70(&DAT_1404e8628,local_b8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar1,piVar5);
    }
    local_f8 = DAT_1407cea38;
    local_f4 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_f0,&DAT_1407ce9e8,4);
    local_118 = &local_c8;
    iVar1 = 0;
    local_108 = 0;
    local_110 = 1;
    local_c4 = DAT_140539da8 / (param_3 - param_2);
    local_d0 = 1;
    local_bc = param_6;
    local_c0 = param_5;
    local_c8 = param_2;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(*piVar5);
    FUN_140158590(1,DAT_140b18a5c);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_d0) {
      piVar5 = local_f0;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < local_d0);
    }
    FUN_140158760(local_f8);
    FUN_1401584b0(local_f4);
    local_118 = (float *)CONCAT44(local_118._4_4_,1);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar2 = 0;
  }
  return uVar2;
}


