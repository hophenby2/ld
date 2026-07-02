// Function: FUN_140244660 @ 140244660
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140244660(uint param_1,int param_2,undefined8 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  int *piVar4;
  undefined1 auStack_78 [32];
  longlong local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_78;
  local_50 = 0;
  local_58 = 0;
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
    iVar1 = FUN_140221350(param_3,&local_58,param_6);
    if (iVar1 != 0) {
      puVar3 = &DAT_1404b3730;
      goto LAB_140244824;
    }
  }
  else {
    if (param_2 != 1) {
      puVar3 = &DAT_1404e8278;
      goto LAB_140244824;
    }
    iVar1 = FUN_140220d90(param_3,&local_50,param_6);
    if (iVar1 != 0) {
      puVar3 = &DAT_1404b3788;
      goto LAB_140244824;
    }
  }
  lVar2 = FUN_1401b6560((longlong)param_4,
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp",
                        0x7664);
  *(longlong *)(piVar4 + 0x22) = lVar2;
  if (lVar2 != 0) {
    FUN_1401ae2f0(lVar2,param_3,(longlong)param_4);
    lVar2 = *(longlong *)(piVar4 + 0x22);
    piVar4[0x20] = param_2;
    if ((*(char *)(lVar2 + 4) == -2) && (*(char *)(lVar2 + 5) == -1)) {
      *(longlong *)(*(longlong *)(piVar4 + 0x26) + 0x10) = lVar2 + 0x28;
      *(undefined4 *)(*(longlong *)(piVar4 + 0x26) + 8) =
           *(undefined4 *)(*(longlong *)(piVar4 + 0x22) + 0x18);
    }
    else {
      *(undefined8 *)(*(longlong *)(piVar4 + 0x26) + 0x10) = 0;
      *(undefined4 *)(*(longlong *)(piVar4 + 0x26) + 8) = 0;
    }
    lVar2 = local_58;
    if (param_2 != 0) {
      lVar2 = local_50;
    }
    **(longlong **)(piVar4 + 0x26) = lVar2;
    if (param_5 != 0) {
      FUN_1401b6700(param_3);
    }
    return 0;
  }
  puVar3 = &DAT_1404a7e00;
LAB_140244824:
  FUN_1401594b0(puVar3);
  if (local_58 != 0) {
    FUN_140220340(local_58,param_6);
  }
  if (local_50 != 0) {
    FUN_140220340(local_50,param_6);
  }
  if (param_5 != 0) {
    FUN_1401b6700(param_3);
  }
  return 0xffffffff;
}


