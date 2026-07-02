// Function: FUN_140211390 @ 140211390
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140211390(uint param_1,int param_2,undefined8 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  int *piVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  int local_58;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = DAT_1407c6b00 ^ (ulonglong)auStack_78;
  lVar5 = (longlong)param_4;
  local_40 = 0;
  local_38 = 0;
  local_48 = 0;
  if (param_6 == 0) {
    if (DAT_14098a560 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_14098a5b0) {
      return 0xffffffff;
    }
    if (DAT_14098a5b8 <= (int)(param_1 & 0x3ffff)) {
      return 0xffffffff;
    }
    lVar2 = (ulonglong)(param_1 & 0x3ffff) * 8;
    piVar4 = *(int **)(lVar2 + DAT_14098a568);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 << 0x12 != (param_1 & 0x3fc0000)) {
      return 0xffffffff;
    }
    if (piVar4[6] != 0) {
      if ((piVar4[6] < 2) && (-1 < piVar4[8])) {
        iVar1 = FUN_1401afbe0();
      }
      else {
        iVar1 = FUN_1401b82b0(param_1);
      }
      if (iVar1 < 0) {
        return 0xffffffff;
      }
      if (*(longlong *)(lVar2 + DAT_14098a568) == 0) {
        return 0xffffffff;
      }
    }
  }
  else {
    if (DAT_14098a560 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_14098a5b0) {
      return 0xffffffff;
    }
    if (DAT_14098a5b8 <= (int)(param_1 & 0x3ffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_14098a568 + (ulonglong)(param_1 & 0x3ffff) * 8);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 << 0x12 != (param_1 & 0x3fc0000)) {
      return 0xffffffff;
    }
  }
  if (param_2 == 0) {
    local_58 = param_6;
    iVar1 = FUN_14021e020(param_3,lVar5,0,&local_40);
    if (iVar1 != 0) {
      puVar3 = &DAT_1404b3730;
      goto LAB_140211591;
    }
  }
  else if (param_2 == 1) {
    local_58 = param_6;
    iVar1 = FUN_14021dac0(param_3,lVar5,0,&local_48);
    if (iVar1 != 0) {
      puVar3 = &DAT_1404b3788;
      goto LAB_140211591;
    }
  }
  else if (param_2 == 2) {
    local_58 = param_6;
    iVar1 = FUN_14021d950(param_3,lVar5,0,&local_38);
    if (iVar1 != 0) {
      puVar3 = &DAT_1404b3758;
      goto LAB_140211591;
    }
  }
  lVar2 = FUN_1401b6560(lVar5,
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                        0x7110);
  *(longlong *)(piVar4 + 0x22) = lVar2;
  if (lVar2 != 0) {
    FUN_1401ae2f0(lVar2,param_3,lVar5);
    piVar4[0x24] = param_4;
    piVar4[0x20] = param_2;
    lVar5 = local_40;
    if (((param_2 == 0) || (lVar5 = local_48, param_2 == 1)) || (lVar5 = local_38, param_2 == 2)) {
      **(longlong **)(piVar4 + 0x26) = lVar5;
    }
    if (param_5 != 0) {
      FUN_1401b6700(param_3);
    }
    return 0;
  }
  puVar3 = &DAT_1404a7e00;
LAB_140211591:
  FUN_1401594b0(puVar3);
  if (local_40 != 0) {
    FUN_14021f550(local_40,param_6);
  }
  if (local_48 != 0) {
    FUN_14021f300(local_48,param_6);
  }
  if (param_5 != 0) {
    FUN_1401b6700(param_3);
  }
  return 0xffffffff;
}


