// Function: FUN_1401b3410 @ 1401b3410
// Decompile completed: true

undefined8 FUN_1401b3410(short *param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  char *pcVar8;
  longlong lVar9;
  bool bVar10;
  
  if ((*(longlong *)(param_1 + 0x24) != 0) || (*(longlong *)(param_1 + 0x28) != 0)) {
    return 0xffffffff;
  }
  FUN_1401ae370(param_1,0,0x40);
  lVar2 = FUN_140139800(param_2,0,1);
  *(longlong *)(param_1 + 0x24) = lVar2;
  if (lVar2 == 0) {
    return 0xffffffff;
  }
  FUN_1401aeb80(param_1 + 0x40,0x800,param_2);
  pcVar8 = s_DXBDXARC_14056d890;
  if (param_3 != (char *)0x0) {
    pcVar8 = param_3;
  }
  uVar3 = FUN_1401ba9b0(0x7ffd,pcVar8);
  if (0x3f < uVar3) {
    uVar3 = 0x3f;
  }
  *(ulonglong *)(param_1 + 0x464) = uVar3;
  FUN_1401ae2f0(param_1 + 0x444,pcVar8,uVar3);
  lVar2 = (longlong)param_1 + 0x881;
  *(undefined1 *)(*(longlong *)(param_1 + 0x464) + 0x888 + (longlong)param_1) = 0;
  FUN_1401b3280(param_1 + 0x444,*(undefined8 *)(param_1 + 0x464),lVar2);
  FUN_1401398a0(param_1,4,1,*(undefined8 *)(param_1 + 0x24));
  if ((*param_1 != 0x5844) || (param_1[1] != 8)) goto LAB_1401b36ae;
  FUN_1401398a0(param_1 + 2,0x3c,1,*(undefined8 *)(param_1 + 0x24));
  uVar1 = *(uint *)(param_1 + 0x14);
  *(byte *)(param_1 + 0x440) = *(byte *)(param_1 + 0x16) & 1;
  if (uVar1 < 0x4e5) {
    if (uVar1 != 0x4e4) {
      if (uVar1 < 0x3b7) {
        if ((uVar1 < 0x3b5) && (uVar1 != 0x3a4)) {
          bVar10 = uVar1 == 0x3a8;
          goto LAB_1401b3600;
        }
      }
      else if (1 < uVar1 - 0x4b0) goto LAB_1401b3602;
    }
LAB_1401b3585:
    *(uint *)(param_1 + 0x20) = uVar1;
  }
  else {
    if ((uVar1 == 0x7ffc) || (uVar1 - 0x7ffe < 2)) goto LAB_1401b3585;
    bVar10 = uVar1 == 0xfde9;
LAB_1401b3600:
    if (bVar10) goto LAB_1401b3585;
LAB_1401b3602:
    param_1[0x20] = 0x3a4;
    param_1[0x21] = 0;
  }
  lVar4 = FUN_1401b6390(*(undefined4 *)(param_1 + 2),
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x582);
  *(longlong *)(param_1 + 0x2c) = lVar4;
  if (lVar4 != 0) {
    if ((*(byte *)(param_1 + 0x16) & 2) != 0) {
      FUN_140139920(*(undefined8 *)(param_1 + 0x24),*(undefined8 *)(param_1 + 8),0);
      lVar4 = 0;
      if ((char)param_1[0x440] == '\0') {
        lVar4 = lVar2;
      }
      FUN_1401b31d0(*(undefined8 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 2),
                    *(undefined8 *)(param_1 + 0x24),lVar4,0);
LAB_1401b3713:
      lVar2 = *(longlong *)(param_1 + 0x2c);
      *(longlong *)(param_1 + 0x38) = lVar2;
      *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0xc) + lVar2;
      param_1[0x468] = 0;
      param_1[0x469] = 0;
      param_1[0x46a] = 0;
      param_1[0x46b] = 0;
      *(longlong *)(param_1 + 0x34) = *(longlong *)(param_1 + 0x10) + lVar2;
      *(longlong *)(param_1 + 0x3c) = *(longlong *)(param_1 + 0x10) + lVar2;
      param_1[0x470] = 0;
      param_1[0x471] = 0;
      param_1[0x472] = 0;
      param_1[0x473] = 0;
      return 0;
    }
    FUN_140139920(*(undefined8 *)(param_1 + 0x24),0,2);
    lVar4 = FUN_140139990(*(undefined8 *)(param_1 + 0x24));
    FUN_140139920(*(undefined8 *)(param_1 + 0x24),*(undefined8 *)(param_1 + 8),0);
    lVar5 = FUN_140139990(*(undefined8 *)(param_1 + 0x24));
    lVar6 = FUN_1401b6390(lVar4 - lVar5,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                          0x59e);
    if (lVar6 != 0) {
      lVar9 = 0;
      if ((char)param_1[0x440] == '\0') {
        lVar9 = lVar2;
      }
      FUN_1401b31d0(lVar6,lVar4 - lVar5,*(undefined8 *)(param_1 + 0x24),lVar9,0);
      uVar7 = FUN_1401b5b00(lVar6,0);
      lVar2 = FUN_1401b6390(uVar7,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x5ab)
      ;
      if (lVar2 != 0) {
        FUN_1401b5b00(lVar6,lVar2);
        FUN_1401b2550(lVar2,*(undefined8 *)(param_1 + 0x2c));
        FUN_1401b6700(lVar6);
        FUN_1401b6700(lVar2);
        goto LAB_1401b3713;
      }
      FUN_1401b6700();
    }
  }
LAB_1401b36ae:
  if (*(longlong *)(param_1 + 0x24) != 0) {
    FUN_1401396c0();
    param_1[0x24] = 0;
    param_1[0x25] = 0;
    param_1[0x26] = 0;
    param_1[0x27] = 0;
  }
  if (*(longlong *)(param_1 + 0x2c) != 0) {
    FUN_1401b6700();
    param_1[0x2c] = 0;
    param_1[0x2d] = 0;
    param_1[0x2e] = 0;
    param_1[0x2f] = 0;
  }
  return 0xffffffff;
}


