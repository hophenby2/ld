// Function: FUN_14024d000 @ 14024d000
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14024d000(undefined8 param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined1 auStack_168 [32];
  float *local_148;
  undefined4 local_140;
  undefined4 local_138;
  uint local_128;
  uint local_120;
  undefined4 local_118;
  undefined4 local_114;
  int local_110 [8];
  int local_f0;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  lVar4 = (longlong)param_4;
  local_128 = param_2;
  local_120 = param_3;
  iVar1 = FUN_1401eed30();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    piVar5 = (int *)(&DAT_140b18a7c + lVar4 * 4);
    if (*(int *)(&DAT_140b18a7c + lVar4 * 4) < 0) {
      iVar1 = FUN_140248fc0((&PTR_s_Replacement_pso_14066f5f0)[lVar4],1);
      *piVar5 = iVar1;
      if (iVar1 < 0) {
        local_140 = 0x4b0;
        local_148 = (float *)0x80;
        FUN_1401c0470((&PTR_s_Replacement_pso_14066f5f0)[lVar4],0xffffffff,0x7ffd,local_c8);
        FUN_140159b70(&DAT_1404e8628,local_c8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar1,piVar5);
    }
    local_118 = DAT_1407cea38;
    local_114 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_110,&DAT_1407ce9e8,4);
    local_f0 = 1;
    local_e8 = (float)(local_128 >> 0x10 & 0xff) / DAT_14053adec;
    iVar1 = 0;
    local_138 = 0;
    local_140 = 2;
    local_e4 = (float)(local_128 >> 8 & 0xff) / DAT_14053adec;
    local_e0 = (float)(param_2 & 0xff) / DAT_14053adec;
    local_dc = (float)(local_128 >> 0x18) / DAT_14053adec;
    local_d8 = (float)(local_120 >> 0x10 & 0xff) / DAT_14053adec;
    local_d4 = (float)(local_120 >> 8 & 0xff) / DAT_14053adec;
    local_148 = &local_e8;
    local_d0 = (float)(param_3 & 0xff) / DAT_14053adec;
    local_cc = (float)(local_120 >> 0x18) / DAT_14053adec;
    FUN_14023dd40(&DAT_140ca5d24,3,1,0);
    FUN_1401584b0(*piVar5);
    FUN_1402482c0(param_1,1,0);
    if (0 < local_f0) {
      piVar5 = local_110;
      do {
        iVar3 = *piVar5;
        if (*piVar5 == 0) {
          iVar3 = -1;
        }
        FUN_140158590(iVar1,iVar3);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < local_f0);
    }
    FUN_140158760(local_118);
    FUN_1401584b0(local_114);
    local_148 = (float *)CONCAT44(local_148._4_4_,2);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar2 = 0;
  }
  return uVar2;
}


