// Function: FUN_140159760 @ 140159760
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_140159760(int param_1,int param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  short *psVar10;
  undefined1 auStack_1478 [40];
  short *local_1450;
  short local_1448 [1536];
  short local_848 [1024];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_1478;
  uVar9 = 0;
  local_1450 = (short *)0x0;
  if (param_2 != 0) {
    FUN_1401aee10(param_2,param_3);
  }
  if ((DAT_1407e50a8 != 1) && ((param_1 != 1 || (DAT_1407e50ac != 1)))) {
    if ((DAT_1407e50a0 == 0) && (iVar2 = FUN_140159da0(), iVar2 < 0)) {
      return -1;
    }
    FUN_1401b6dc0(&DAT_1407e60c0,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxLog.cpp",0xcd);
    sVar1 = *param_3;
    uVar3 = uVar9;
    while (sVar1 != 0) {
      uVar3 = uVar3 + 1;
      sVar1 = param_3[uVar3];
    }
    uVar7 = DAT_1407e60b8 + 0x10 + (int)uVar3 * 2;
    if (uVar7 < 0x400) {
      psVar4 = local_848;
    }
    else {
      psVar4 = (short *)FUN_1401b6390((ulonglong)uVar7 * 2,0,0xffffffff);
      local_1450 = psVar4;
    }
    psVar6 = psVar4;
    if (DAT_1407e60bc == 0) {
      if (DAT_1407e50a4 == 0) {
        iVar2 = FUN_1401ad0e0(0);
        FUN_1401ae8f0(psVar4,&DAT_1404a7fb0,iVar2 - _DAT_1407e50b0);
        sVar1 = *psVar4;
        uVar3 = uVar9;
        while (sVar1 != 0) {
          uVar3 = uVar3 + 1;
          sVar1 = psVar4[uVar3];
        }
        psVar6 = psVar4 + uVar3;
      }
      if (DAT_1407e60b8 != 0) {
        uVar3 = uVar9;
        if (0 < DAT_1407e60b8) {
          do {
            *psVar6 = 9;
            uVar7 = (int)uVar3 + 1;
            psVar6 = psVar6 + 1;
            uVar3 = (ulonglong)uVar7;
          } while ((int)uVar7 < DAT_1407e60b8);
        }
        *psVar6 = 0;
      }
    }
    psVar5 = (short *)FUN_1401aeac0(param_3,10);
    psVar10 = param_3;
    while ((psVar5 != (short *)0x0 && ((param_3 == psVar5 || (psVar5[-1] != 0xd))))) {
      lVar8 = (longlong)psVar5 - (longlong)psVar10 >> 1;
      FUN_1401ae2f0(psVar6,psVar10,lVar8 * 2);
      psVar6 = psVar6 + lVar8;
      psVar10 = psVar5 + 1;
      psVar6[0] = 0xd;
      psVar6[1] = 10;
      psVar6 = psVar6 + 2;
      *psVar6 = 0;
      psVar5 = (short *)FUN_1401aeac0(psVar10,10);
    }
    FUN_1401aeb40(psVar6,psVar10);
    sVar1 = *psVar4;
    uVar3 = uVar9;
    while (sVar1 != 0) {
      uVar3 = uVar3 + 1;
      sVar1 = psVar4[uVar3];
    }
    psVar6 = local_1448;
    DAT_1407e60bc = (uint)(psVar4[uVar3 - 1] != 10);
    if (DAT_1407e52b4 == 0) {
      FUN_1401399c0(psVar6,0xc00);
      psVar10 = local_1448;
      psVar6 = &DAT_1407e52b4;
    }
    else {
      psVar10 = &DAT_1407e52b4;
    }
    FUN_1401aeb80(psVar6,0xc00,psVar10);
    uVar3 = uVar9;
    sVar1 = local_1448[0];
    while (sVar1 != 0) {
      uVar3 = uVar3 + 1;
      sVar1 = local_1448[uVar3];
    }
    iVar2 = (int)uVar3;
    if ((local_1448[iVar2 + -1] != 0x5c) && (local_1448[iVar2 + -1] != 0x2f)) {
      FUN_1401aea70(local_1448,0xc00,&DAT_1404a75f0);
      while (local_1448[0] != 0) {
        uVar9 = uVar9 + 1;
        local_1448[0] = local_1448[uVar9];
      }
      iVar2 = (int)uVar9;
    }
    FUN_1401aeb80(local_1448 + iVar2,(longlong)iVar2 * -2 + 0xc00,&DAT_1407e5eb8);
    FUN_1401f0cb0(local_1448,psVar4);
    if (local_1450 != (short *)0x0) {
      FUN_1401b6700(local_1450);
    }
    FUN_1401b6e70(&DAT_1407e60c0);
  }
  return -(uint)(param_2 != 0);
}


