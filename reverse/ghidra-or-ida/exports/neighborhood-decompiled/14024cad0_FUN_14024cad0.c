// Function: FUN_14024cad0 @ 14024cad0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14024cad0(undefined8 param_1,float param_2,float param_3)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_148 [32];
  undefined8 *local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined4 local_108;
  undefined4 local_104;
  int local_100 [8];
  int local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  float local_c8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    if (DAT_140b18a48 < 0) {
      DAT_140b18a48 = FUN_140248fc0(PTR_s_Mono_pso_14066f4e0,1);
      if (DAT_140b18a48 < 0) {
        local_120 = 0x4b0;
        local_128 = (undefined8 *)0x80;
        FUN_1401c0470(PTR_s_Mono_pso_14066f4e0,0xffffffff,0x7ffd,local_b8);
        FUN_140159b70(&DAT_1404e8628,local_b8);
        return 0xffffffff;
      }
      FUN_1401b7da0(DAT_140b18a48,&DAT_140b18a48);
    }
    local_108 = DAT_1407cea38;
    local_104 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_100,&DAT_1407ce9e8,4);
    local_128 = &local_d8;
    local_d8 = _DAT_1404e8f70;
    uStack_d0 = _UNK_1404e8f78;
    local_e0 = 1;
    iVar1 = 0;
    local_118 = 0;
    local_120 = 2;
    local_c0 = param_2 * _DAT_1404ad214;
    local_c8 = param_3 * _DAT_1404ad210;
    local_c4 = param_2 * _DAT_1404ad208 - param_3 * _DAT_1404ad20c;
    local_bc = 0;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(DAT_140b18a48);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_e0) {
      piVar4 = local_100;
      do {
        iVar3 = *piVar4;
        if (*piVar4 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar1 < local_e0);
    }
    FUN_140158760(local_108);
    FUN_1401584b0(local_104);
    local_128 = (undefined8 *)CONCAT44(local_128._4_4_,2);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar2 = 0;
  }
  return uVar2;
}


