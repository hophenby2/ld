// Function: dxarchive_open_from_file_wait_candidate @ 1401b3750
// Decompile completed: true

undefined8
dxarchive_open_from_file_wait_candidate(short *param_1,undefined8 param_2,char *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((*(longlong *)(param_1 + 0x24) != 0) || (*(longlong *)(param_1 + 0x28) != 0)) {
    return 0xffffffff;
  }
  pcVar7 = s_DXBDXARC_14056d890;
  if (param_3 != (char *)0x0) {
    pcVar7 = param_3;
  }
  uVar3 = FUN_1401ba9b0(0x7ffd,pcVar7);
  *(ulonglong *)(param_1 + 0x464) = uVar3;
  if (0x3f < uVar3) {
    param_1[0x464] = 0x3f;
    param_1[0x465] = 0;
    param_1[0x466] = 0;
    param_1[0x467] = 0;
  }
  FUN_1401ae2f0(param_1 + 0x444,pcVar7,*(undefined8 *)(param_1 + 0x464));
  *(undefined1 *)(*(longlong *)(param_1 + 0x464) + 0x888 + (longlong)param_1) = 0;
  FUN_1401b3280(param_1 + 0x444,*(undefined8 *)(param_1 + 0x464),(longlong)param_1 + 0x881);
  param_1[0x47c] = 0;
  param_1[0x47d] = 0;
  param_1[0x47e] = 0;
  param_1[0x47f] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  lVar4 = FUN_140139800(param_2,0,1,0);
  *(longlong *)(param_1 + 0x47c) = lVar4;
  if (lVar4 == 0) {
    return 0xffffffff;
  }
  FUN_1401aeb80(param_1 + 0x40,0x800,param_2);
  FUN_140139920(*(undefined8 *)(param_1 + 0x47c),0,2);
  uVar5 = FUN_140139990(*(undefined8 *)(param_1 + 0x47c));
  *(undefined8 *)(param_1 + 0x46c) = uVar5;
  FUN_140139920(*(undefined8 *)(param_1 + 0x47c),0,0);
  uVar5 = FUN_1401b6390(*(undefined8 *)(param_1 + 0x46c),
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x48e);
  *(undefined8 *)(param_1 + 0x28) = uVar5;
  FUN_1401398a0(param_1,4,1,*(undefined8 *)(param_1 + 0x47c));
  if ((*param_1 != 0x5844) || (param_1[1] != 8)) goto LAB_1401b3a6b;
  FUN_140139920(*(undefined8 *)(param_1 + 0x47c),0,0);
  FUN_1401398a0(*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x46c),1,
                *(undefined8 *)(param_1 + 0x47c));
  FUN_1401ae2f0(param_1,*(undefined8 *)(param_1 + 0x28),0x40);
  uVar1 = *(uint *)(param_1 + 0x14);
  *(byte *)(param_1 + 0x440) = *(byte *)(param_1 + 0x16) & 1;
  if (uVar1 < 0x4e5) {
    if (uVar1 != 0x4e4) {
      if (uVar1 < 0x3b7) {
        if ((uVar1 < 0x3b5) && (uVar1 != 0x3a4)) {
          bVar8 = uVar1 == 0x3a8;
          goto LAB_1401b39d3;
        }
      }
      else if (1 < uVar1 - 0x4b0) goto LAB_1401b39d9;
    }
LAB_1401b3953:
    *(uint *)(param_1 + 0x20) = uVar1;
  }
  else {
    if ((uVar1 == 0x7ffc) || (uVar1 - 0x7ffe < 2)) goto LAB_1401b3953;
    bVar8 = uVar1 == 0xfde9;
LAB_1401b39d3:
    if (bVar8) goto LAB_1401b3953;
LAB_1401b39d9:
    param_1[0x20] = 0x3a4;
    param_1[0x21] = 0;
  }
  lVar4 = FUN_1401b6390(*(undefined4 *)(param_1 + 2),
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x4c2);
  *(longlong *)(param_1 + 0x2c) = lVar4;
  if (lVar4 != 0) {
    if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
      FUN_1401ae2f0(lVar4,*(longlong *)(param_1 + 8) + *(longlong *)(param_1 + 0x28),
                    *(undefined4 *)(param_1 + 2));
      if ((char)param_1[0x440] == '\0') {
        FUN_1401b3000(*(undefined8 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 2),0,
                      (longlong)param_1 + 0x881);
      }
LAB_1401b3ae0:
      lVar4 = *(longlong *)(param_1 + 0x2c);
      *(longlong *)(param_1 + 0x38) = lVar4;
      *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0xc) + lVar4;
      param_1[0x478] = 1;
      param_1[0x479] = 0;
      *(longlong *)(param_1 + 0x34) = *(longlong *)(param_1 + 0x10) + lVar4;
      *(longlong *)(param_1 + 0x3c) = *(longlong *)(param_1 + 0x10) + lVar4;
      param_1[0x468] = 1;
      param_1[0x469] = 0;
      param_1[0x46a] = 0;
      param_1[0x46b] = 0;
      param_1[0x470] = 0;
      param_1[0x471] = 0;
      param_1[0x472] = 0;
      param_1[0x473] = 0;
      if (param_4 == 0) {
        iVar2 = FUN_1401b08d0(param_1);
        while (iVar2 == 0) {
          FUN_1401b7120(0);
          iVar2 = FUN_1401b08d0();
        }
      }
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x46c) - *(int *)(param_1 + 8);
    lVar4 = FUN_1401b6390(iVar2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x4da);
    if (lVar4 != 0) {
      FUN_1401ae2f0(lVar4,*(longlong *)(param_1 + 8) + *(longlong *)(param_1 + 0x28),iVar2);
      if ((char)param_1[0x440] == '\0') {
        FUN_1401b3000(lVar4,iVar2,0,(longlong)param_1 + 0x881);
      }
      uVar5 = FUN_1401b5b00(lVar4,0);
      lVar6 = FUN_1401b6390(uVar5,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x4e8)
      ;
      if (lVar6 != 0) {
        FUN_1401b5b00(lVar4,lVar6);
        FUN_1401b2550(lVar6,*(undefined8 *)(param_1 + 0x2c));
        FUN_1401b6700(lVar4);
        FUN_1401b6700(lVar6);
        goto LAB_1401b3ae0;
      }
      FUN_1401b6700();
    }
  }
LAB_1401b3a6b:
  if (*(longlong *)(param_1 + 0x47c) != 0) {
    FUN_1401396c0();
    param_1[0x47c] = 0;
    param_1[0x47d] = 0;
    param_1[0x47e] = 0;
    param_1[0x47f] = 0;
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    FUN_1401b6700();
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
  }
  param_1[0x478] = 0;
  param_1[0x479] = 0;
  return 0xffffffff;
}


