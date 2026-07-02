// Function: FUN_1401b28a0 @ 1401b28a0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_1401b28a0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  longlong *plVar3;
  undefined1 auStack_c68 [32];
  undefined1 *local_c48;
  undefined8 local_c40;
  undefined1 local_c38 [16];
  undefined1 local_c28 [1536];
  undefined1 local_628 [1536];
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_c68;
  if (*(int *)(param_1 + 0x8f0) == 1) {
    iVar2 = FUN_1401b08d0();
    while (iVar2 == 0) {
      FUN_1401b7120(0);
      iVar2 = FUN_1401b08d0();
    }
  }
  plVar3 = (longlong *)
           FUN_1401b6390(0x618,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x795);
  if (plVar3 == (longlong *)0x0) {
LAB_1401b29ad:
    plVar3 = (longlong *)0xffffffffffffffff;
  }
  else {
    *plVar3 = param_1;
    local_c48 = local_c28;
    local_c40 = 0x600;
    FUN_1401b0e00(param_1,param_2,local_628,0x600);
    FUN_1401bb1c0(*(undefined4 *)(param_1 + 0x40),local_c28);
    FUN_1401bb1c0(*(undefined4 *)(param_1 + 0x40),local_628);
    iVar2 = FUN_1401c4e50(local_c28,*(undefined4 *)(param_1 + 0x40),local_c38);
    if (iVar2 == 0) {
      plVar3[0xc1] = *(longlong *)(param_1 + 0x78);
    }
    else {
      uVar1 = *(undefined8 *)(param_1 + 0x78);
      iVar2 = FUN_1401b04e0(param_1,local_c28,0,0);
      if (iVar2 == -1) {
        FUN_1401b6700(plVar3);
        *(undefined8 *)(param_1 + 0x78) = uVar1;
        goto LAB_1401b29ad;
      }
      plVar3[0xc1] = *(longlong *)(param_1 + 0x78);
      *(undefined8 *)(param_1 + 0x78) = uVar1;
    }
    *(undefined4 *)(plVar3 + 0xc2) = 0;
    FUN_1401ba4c0(*(undefined4 *)(param_1 + 0x40),plVar3 + 1,0x600,local_628);
    iVar2 = FUN_1401b2a30(plVar3,param_3);
    if (iVar2 == -1) {
      FUN_1401b6700(plVar3);
      plVar3 = (longlong *)0xffffffffffffffff;
    }
    else {
      *(int *)(plVar3 + 0xc2) = (int)plVar3[0xc2] + 1;
    }
  }
  return plVar3;
}


