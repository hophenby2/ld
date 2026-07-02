// Function: FUN_140171410 @ 140171410
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_140171410(longlong param_1,undefined4 *param_2,longlong *param_3,int param_4,int param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 auStack_538 [32];
  undefined4 local_518;
  longlong local_510;
  undefined8 local_508;
  undefined4 local_500;
  undefined8 local_4f8;
  undefined8 local_4f0;
  undefined8 *local_4e8;
  undefined4 local_4e0;
  undefined4 local_4d8;
  undefined4 local_4d0;
  undefined4 local_4c8;
  undefined4 local_4c0;
  undefined4 local_4b8;
  undefined4 local_4b0;
  undefined4 local_4a8;
  undefined8 local_498;
  undefined8 local_490;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_478;
  undefined2 local_474;
  undefined2 local_470;
  undefined1 local_46e;
  undefined2 local_46d;
  undefined1 local_46b;
  undefined2 local_46a;
  undefined4 local_468;
  undefined4 local_464;
  undefined8 local_460;
  undefined8 local_458;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_538;
  if ((*(char *)(param_1 + 5) == '\b') && (param_5 == 0)) {
    FUN_1401ae370(param_2,0,0x2c);
    *param_2 = 0x28;
    param_2[1] = *(undefined4 *)(param_1 + 0x428);
    iVar1 = *(int *)(param_1 + 0x42c);
    *(undefined8 *)(param_2 + 3) = 0x80001;
    param_2[2] = -iVar1;
    iVar4 = 0;
    FUN_1401ae2f0(param_2 + 10,param_1 + 0x28,0x400);
    iVar1 = *(int *)(param_1 + 0x428) + 3;
    uVar5 = (iVar1 >> 0x1f & 3U) + iVar1 & 0xfffffffc;
    if ((param_4 != 1) && (uVar5 == *(uint *)(param_1 + 0x430))) {
LAB_14017165a:
      *param_3 = *(longlong *)(param_1 + 0x438);
      return param_4;
    }
    lVar2 = FUN_1401b6390((longlong)(int)(*(int *)(param_1 + 0x42c) * uVar5),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xaab);
    *param_3 = lVar2;
    if (lVar2 != 0) {
      lVar6 = *(longlong *)(param_1 + 0x438);
      if (0 < *(int *)(param_1 + 0x42c)) {
        do {
          FUN_1401ae2f0(lVar2,lVar6,(longlong)*(int *)(param_1 + 0x428));
          iVar4 = iVar4 + 1;
          lVar6 = lVar6 + *(int *)(param_1 + 0x430);
          lVar2 = lVar2 + (int)uVar5;
        } while (iVar4 < *(int *)(param_1 + 0x42c));
      }
      return 1;
    }
  }
  else {
    FUN_1401ae370(param_2,0,0x2c);
    *param_2 = 0x28;
    param_2[1] = *(undefined4 *)(param_1 + 0x428);
    iVar1 = *(int *)(param_1 + 0x42c);
    param_2[3] = 0x180001;
    param_2[2] = -iVar1;
    iVar1 = (*(int *)(param_1 + 0x428) + 1) * 3;
    uVar5 = (iVar1 >> 0x1f & 3U) + iVar1 & 0xfffffffc;
    if (((*(char *)(param_1 + 5) == '\x18') &&
        (((param_4 != 1 && (*(int *)(param_1 + 0x10) == 0xff0000)) &&
         (*(int *)(param_1 + 0x14) == 0xff00)))) && (*(int *)(param_1 + 0x18) == 0xff)) {
      if (uVar5 == *(uint *)(param_1 + 0x430)) goto LAB_14017165a;
      lVar2 = FUN_1401b6390((longlong)(int)(*(int *)(param_1 + 0x42c) * uVar5),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xaf6);
      *param_3 = lVar2;
      if (lVar2 != 0) {
        lVar6 = *(longlong *)(param_1 + 0x438);
        iVar1 = 0;
        if (0 < *(int *)(param_1 + 0x42c)) {
          lVar3 = (longlong)*(int *)(param_1 + 0x430);
          do {
            FUN_1401ae2f0(lVar2,lVar6,lVar3);
            lVar3 = (longlong)*(int *)(param_1 + 0x430);
            iVar1 = iVar1 + 1;
            lVar6 = lVar6 + lVar3;
            lVar2 = lVar2 + (int)uVar5;
          } while (iVar1 < *(int *)(param_1 + 0x42c));
          return 1;
        }
        return 1;
      }
    }
    else {
      lVar2 = FUN_1401b6390((longlong)(int)(*(int *)(param_1 + 0x42c) * uVar5),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xada);
      *param_3 = lVar2;
      if (lVar2 != 0) {
        local_488 = *(undefined4 *)(param_1 + 0x428);
        local_4a8 = 0;
        local_4b0 = 0;
        local_4b8 = 0;
        local_4c0 = 0;
        local_4c8 = 0;
        local_4d0 = 0;
        local_4d8 = 0;
        local_4e0 = 0;
        local_484 = *(undefined4 *)(param_1 + 0x42c);
        local_4e8 = &local_490;
        local_4f0 = 0;
        local_518 = *(undefined4 *)(param_1 + 0x430);
        local_4f8 = 0;
        local_500 = 0;
        local_508 = 0;
        local_478 = 0;
        local_474 = 0x1803;
        local_458 = 0;
        local_46a = 0;
        local_460 = 0xff;
        local_46d = 0x1000;
        local_468 = 0xff0000;
        local_470 = 0x808;
        local_46b = 8;
        local_464 = 0xff00;
        local_46e = 8;
        local_498 = 0;
        local_490 = 0;
        local_510 = param_1;
        FUN_14017ae00(lVar2,uVar5,&local_478,*(undefined8 *)(param_1 + 0x438));
        return 1;
      }
    }
  }
  return -1;
}


