// Function: FUN_14021abd0 @ 14021abd0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14021abd0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined1 auStack_68 [32];
  undefined1 local_48 [32];
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_68;
  FUN_1401b6dc0(param_1 + 0xd0,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x647);
  if (*(int *)(param_1 + 0x50) == 0) {
    plVar3 = (longlong *)(param_2 + 0xfU & 0xfffffffffffffff0);
  }
  else {
    for (plVar3 = *(longlong **)(param_1 + 0x88); plVar3 != (longlong *)0x0;
        plVar3 = (longlong *)plVar3[9]) {
      if (*plVar3 == param_2) goto LAB_14021ac52;
    }
    FUN_140159b70(&DAT_1404b55e0,param_2);
    _DAT_00000000 = 0xffffffff;
  }
LAB_14021ac52:
  if (plVar3[6] != 0) {
    FUN_140159b70(&DAT_1404b5680);
    _DAT_00000000 = 0xffffffff;
  }
  lVar1 = plVar3[7];
  if ((*(byte *)(lVar1 + 0x16) & 4) != 0) {
    FUN_140159b70(&DAT_1404b5730);
    lVar2 = lVar1;
    if (*(int *)(param_1 + 0x50) == 0) {
      lVar2 = *(longlong *)(lVar1 + 0x30);
    }
    FUN_14021a5d0(lVar2);
    _DAT_00000000 = 0xffffffff;
  }
  if (*(longlong **)(lVar1 + 0x68) != plVar3) {
    FUN_140159b70(&DAT_1404b57a0,*(longlong **)(lVar1 + 0x68),plVar3);
    lVar2 = lVar1;
    if (*(int *)(param_1 + 0x50) == 0) {
      lVar2 = *(longlong *)(lVar1 + 0x30);
    }
    FUN_14021a5d0(lVar2);
    _DAT_00000000 = 0xffffffff;
  }
  if ((*(longlong *)(lVar1 + 0x48) != 0) &&
     (*(longlong **)(*(longlong *)(lVar1 + 0x48) + 0x68) == plVar3)) {
    FUN_140159b70(&DAT_1404b5890);
    lVar2 = lVar1;
    if (*(int *)(param_1 + 0x50) == 0) {
      lVar2 = *(longlong *)(lVar1 + 0x30);
    }
    FUN_14021a5d0(lVar2);
    _DAT_00000000 = 0xffffffff;
  }
  *(longlong *)(param_1 + 0x98) = *(longlong *)(param_1 + 0x98) - *(longlong *)(lVar1 + 0x20);
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -1;
  if (*(longlong *)(lVar1 + 0x40) == 0) {
    *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(lVar1 + 0x48);
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar1 + 0x40) + 0x48) = *(undefined8 *)(lVar1 + 0x48);
  }
  if (*(longlong *)(lVar1 + 0x48) == 0) {
    *(undefined8 *)(param_1 + 0xa8) = *(undefined8 *)(lVar1 + 0x40);
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar1 + 0x48) + 0x40) = *(undefined8 *)(lVar1 + 0x40);
  }
  lVar2 = 0;
  if (*(int *)(param_1 + 0x38) == 0) {
    if (*(longlong *)(lVar1 + 0x50) == 0) {
      *(undefined8 *)(param_1 + 0x8408) = *(undefined8 *)(lVar1 + 0x58);
    }
    else {
      *(undefined8 *)(*(longlong *)(lVar1 + 0x50) + 0x58) = *(undefined8 *)(lVar1 + 0x58);
    }
    if (*(longlong *)(lVar1 + 0x58) == 0) {
      *(undefined8 *)(param_1 + 0x8410) = *(undefined8 *)(lVar1 + 0x50);
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined8 *)(lVar1 + 0x58) = 0;
    }
    else {
      *(undefined8 *)(*(longlong *)(lVar1 + 0x58) + 0x50) = *(undefined8 *)(lVar1 + 0x50);
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined8 *)(lVar1 + 0x58) = 0;
    }
  }
  else if (*(int *)(param_1 + 0x38) == 1) {
    FUN_14021a2c0(param_1,lVar1);
  }
  if (plVar3[8] == 0) {
    *(longlong *)(param_1 + 0x88) = plVar3[9];
  }
  else {
    *(longlong *)(plVar3[8] + 0x48) = plVar3[9];
  }
  if (plVar3[9] != 0) {
    *(longlong *)(plVar3[9] + 0x40) = plVar3[8];
  }
  if (*(int *)(param_1 + 0x50) != (int)lVar2) {
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
    plVar3[9] = *(longlong *)(param_1 + 0x80);
    plVar3[8] = lVar2;
    *(longlong **)(param_1 + 0x80) = plVar3;
    if (plVar3[9] != 0) {
      *(longlong **)(plVar3[9] + 0x40) = plVar3;
    }
  }
  if ((*(byte *)(plVar3 + 10) & 1) != 0) {
    FUN_1401ae2f0(local_48,(longlong)plVar3 + 0x54,0x20);
    (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x10),local_48);
  }
  FUN_1401b6e70(param_1 + 0xd0);
  return 0;
}


