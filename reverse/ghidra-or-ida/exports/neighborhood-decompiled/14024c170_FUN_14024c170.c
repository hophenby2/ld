// Function: FUN_14024c170 @ 14024c170
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14024c170(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0 [8];
  int local_a0;
  undefined1 local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_1407c6b00 ^ (ulonglong)auStack_f8;
  lVar4 = (longlong)param_2;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    piVar5 = (int *)(&DAT_140b18a4c + lVar4 * 4);
    if (*(int *)(&DAT_140b18a4c + lVar4 * 4) < 0) {
      iVar1 = FUN_140248fc0((&PTR_s_Invert_pso_14066f5a0)[lVar4],1);
      *piVar5 = iVar1;
      if (iVar1 < 0) {
        local_d0 = 0x4b0;
        local_d8 = 0x80;
        FUN_1401c0470((&PTR_s_Invert_pso_14066f5a0)[lVar4],0xffffffff,0x7ffd,local_98);
        FUN_140159b70(&DAT_1404e8628,local_98);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar1,piVar5);
    }
    local_c8 = DAT_1407cea38;
    local_c4 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_c0,&DAT_1407ce9e8,4);
    local_a0 = 1;
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1);
    iVar1 = 0;
    if (0 < local_a0) {
      piVar5 = local_c0;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < local_a0);
    }
    FUN_140158760(local_c8);
    FUN_1401584b0(local_c4);
    uVar2 = 0;
  }
  return uVar2;
}


