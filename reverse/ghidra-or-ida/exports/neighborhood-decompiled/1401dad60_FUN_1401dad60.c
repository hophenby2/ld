// Function: FUN_1401dad60 @ 1401dad60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401dad60(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  uVar3 = DAT_140b19858;
  lVar7 = DAT_140b19850;
  iVar2 = DAT_140b19848;
  iVar4 = DAT_140b19844;
  local_30 = DAT_1407c6b00 ^ (ulonglong)auStack_88;
  bVar1 = false;
  if (param_1 != 0) {
    lVar10 = 0;
    iVar8 = 0;
    uVar9 = 0;
    iVar6 = 0;
    if (DAT_140b19850 != 0) {
      if (param_2 < DAT_140b19844) {
        param_2 = DAT_140b19844;
      }
      if (param_3 < DAT_140b19848) {
        param_3 = DAT_140b19848;
      }
      if ((DAT_140b19844 < param_2) || (iVar8 = 0, uVar9 = 0, DAT_140b19848 < param_3)) {
        bVar1 = true;
        DAT_140b19850 = 0;
        local_58 = _DAT_140b19880;
        uStack_50 = uRam0000000140b19888;
        local_48 = _DAT_140b19890;
        uStack_44 = uRam0000000140b19894;
        uStack_40 = uRam0000000140b19898;
        uStack_3c = uRam0000000140b1989c;
        local_38 = DAT_140b198a0;
        FUN_1401ae370(&DAT_140b19880,0,0x28);
        FUN_14021b440();
        lVar10 = lVar7;
        iVar8 = iVar4;
        uVar9 = uVar3;
        iVar6 = iVar2;
      }
    }
    DAT_140b19844 = param_2;
    DAT_140b19848 = param_3;
    if (DAT_140b19850 == 0) {
      DAT_140b19858 = param_2 + 3 + (param_2 + 3 >> 0x1f & 3U) & 0xfffffffc;
      DAT_140b19850 =
           FUN_1401b6390((longlong)(int)(DAT_140b19858 * param_3),
                         "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxMask.cpp",0x7fe);
      FUN_1401ae370(DAT_140b19850,0,(longlong)(int)(DAT_140b19858 * param_3));
    }
    if ((DAT_1407cd880 == 0) || (DAT_1407cd9dc != 0)) {
      iVar4 = FUN_1401e2780(&DAT_140b19880);
      if (iVar4 == 0) {
        iVar4 = FUN_1401e31b0(&DAT_140b19880,param_2,param_3,0xffffffff);
        if (iVar4 < 0) {
          uVar5 = FUN_1401594b0(&DAT_1404ad280);
          return uVar5;
        }
        DAT_140b1987c = 1;
      }
    }
    else {
      iVar4 = FUN_14021b460(param_2,param_3);
      if (iVar4 < 0) {
        return 0xffffffff;
      }
    }
    if (bVar1) {
      iVar4 = 0;
      if (0 < iVar6) {
        lVar7 = lVar10;
        do {
          FUN_1401ae2f0((int)(DAT_140b19858 * iVar4) + DAT_140b19850,lVar7,(longlong)iVar8);
          iVar4 = iVar4 + 1;
          lVar7 = lVar7 + (int)uVar9;
        } while (iVar4 < iVar6);
      }
      FUN_1401b6700(lVar10);
      if ((DAT_1407cd880 == 0) || (DAT_1407cd9dc != 0)) {
        local_60 = 0;
        local_68 = 0;
        FUN_14036baf0(&DAT_140b19880,&local_58,0,0);
        FUN_1401e3320(&local_58);
      }
      else {
        iVar4 = FUN_14021b480(iVar8,iVar6);
        if (iVar4 < 0) {
          return 0xffffffff;
        }
      }
    }
  }
  return 0;
}


