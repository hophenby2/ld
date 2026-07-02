// Function: dxarchive_open_from_memory_candidate @ 1401b3b60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
dxarchive_open_from_memory_candidate
          (short *param_1,undefined8 param_2,int param_3,int param_4,int param_5,char *param_6,
          longlong param_7)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char *pcVar5;
  longlong lVar6;
  int iVar7;
  undefined1 auStack_868 [32];
  undefined1 local_848 [2048];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_868;
  lVar6 = (longlong)param_3;
  iVar7 = 0;
  if (param_4 == 0) {
    iVar7 = param_5;
  }
  if ((*(longlong *)(param_1 + 0x24) != 0) || (*(longlong *)(param_1 + 0x28) != 0)) {
    return 0xffffffff;
  }
  pcVar5 = s_DXBDXARC_14056d890;
  if (param_6 != (char *)0x0) {
    pcVar5 = param_6;
  }
  uVar2 = FUN_1401ba9b0(0x7ffd,pcVar5);
  if (0x3f < uVar2) {
    uVar2 = 0x3f;
  }
  *(ulonglong *)(param_1 + 0x464) = uVar2;
  FUN_1401ae2f0(param_1 + 0x444,pcVar5,uVar2);
  *(undefined1 *)(*(longlong *)(param_1 + 0x464) + 0x888 + (longlong)param_1) = 0;
  FUN_1401b3280(param_1 + 0x444,*(undefined8 *)(param_1 + 0x464),(longlong)param_1 + 0x881);
  if (param_7 == 0) {
    FUN_1401ae370(param_1 + 0x40,0,0x800);
  }
  else {
    FUN_1401aeb80(param_1 + 0x40,0x800,param_7);
  }
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  *(longlong *)(param_1 + 0x46c) = lVar6;
  if (param_4 == 0) {
    *(undefined8 *)(param_1 + 0x28) = param_2;
    param_1[0x474] = 0;
    param_1[0x475] = 0;
    param_1[0x476] = 0;
    param_1[0x477] = 0;
  }
  else {
    lVar3 = FUN_1401b6390(lVar6,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x396);
    *(longlong *)(param_1 + 0x28) = lVar3;
    if (lVar3 == 0) {
      return 0xffffffff;
    }
    FUN_1401ae2f0(lVar3,param_2,lVar6);
    *(undefined8 *)(param_1 + 0x474) = param_2;
    param_2 = *(undefined8 *)(param_1 + 0x28);
  }
  FUN_1401ae2f0(param_1,param_2,4);
  if ((*param_1 == 0x5844) && (param_1[1] == 8)) {
    FUN_1401ae2f0(param_1,param_2,0x40);
    *(byte *)(param_1 + 0x440) = *(byte *)(param_1 + 0x16) & 1;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x20] = 0x3a4;
    param_1[0x21] = 0;
    lVar6 = FUN_1401b6390(*(undefined4 *)(param_1 + 2),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x3da);
    *(longlong *)(param_1 + 0x2c) = lVar6;
    if (lVar6 != 0) {
      if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
        FUN_1401ae2f0(lVar6,*(longlong *)(param_1 + 8) + *(longlong *)(param_1 + 0x28),
                      *(undefined4 *)(param_1 + 2));
        if ((char)param_1[0x440] == '\0') {
          FUN_1401b3000(*(undefined8 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 2),0,
                        (longlong)param_1 + 0x881);
        }
LAB_1401b3e49:
        lVar6 = *(longlong *)(param_1 + 0x2c);
        *(longlong *)(param_1 + 0x38) = lVar6;
        lVar3 = lVar6 + *(longlong *)(param_1 + 0x10);
        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0xc) + lVar6;
        *(longlong *)(param_1 + 0x34) = lVar3;
        *(longlong *)(param_1 + 0x3c) = lVar3;
        param_1[0x468] = 1;
        param_1[0x469] = 0;
        param_1[0x46a] = 1;
        param_1[0x46b] = 0;
        *(int *)(param_1 + 0x470) = param_4;
        *(int *)(param_1 + 0x472) = iVar7;
        if (((char)param_1[0x440] == '\0') && (iVar7 == 0)) {
          FUN_1401b2710(param_1,lVar3,local_848);
        }
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x46c) - *(int *)(param_1 + 8);
      lVar6 = FUN_1401b6390(iVar1,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x3f2)
      ;
      if (lVar6 != 0) {
        FUN_1401ae2f0(lVar6,*(longlong *)(param_1 + 0x28) + *(longlong *)(param_1 + 8),iVar1);
        if ((char)param_1[0x440] == '\0') {
          FUN_1401b3000(lVar6,iVar1,0,(longlong)param_1 + 0x881);
        }
        uVar4 = FUN_1401b5b00(lVar6,0);
        lVar3 = FUN_1401b6390(uVar4,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                              0x400);
        if (lVar3 != 0) {
          FUN_1401b5b00(lVar6,lVar3);
          FUN_1401b2550(lVar3,*(undefined8 *)(param_1 + 0x2c));
          FUN_1401b6700(lVar6);
          FUN_1401b6700(lVar3);
          goto LAB_1401b3e49;
        }
        FUN_1401b6700();
      }
    }
  }
  if (param_4 == 0) {
    if (*(longlong *)(param_1 + 0x2c) != 0) {
      FUN_1401b6700();
      param_1[0x2c] = 0;
      param_1[0x2d] = 0;
      param_1[0x2e] = 0;
      param_1[0x2f] = 0;
    }
  }
  else if (*(longlong *)(param_1 + 0x28) != 0) {
    FUN_1401b6700();
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
    return 0xffffffff;
  }
  return 0xffffffff;
}


