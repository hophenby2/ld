// Function: FUN_14004a4a0 @ 14004a4a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14004a4a0(undefined4 *param_1)

{
  int iVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 uVar16;
  undefined4 uVar17;
  double dVar15;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined8 uStack_c0;
  
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == param_1[2]) {
        uStack_c0 = *(undefined8 *)(lVar2 + 0x28);
      }
    }
  }
  uVar13 = (undefined4)DAT_140539f68;
  uVar18 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
  if (param_1[6] == 0x136) {
    uVar13 = (undefined4)DAT_140539fb8;
    uVar18 = (undefined4)((ulonglong)DAT_140539fb8 >> 0x20);
  }
  iVar7 = param_1[5];
  iVar10 = 0x168;
  if (param_1[6] != 0x136) {
    iVar10 = 0xf0;
  }
  iVar9 = 0;
  iVar6 = 0;
  param_1[10] = (undefined4)uStack_c0;
  param_1[0xb] = uStack_c0._4_4_;
  if (iVar7 == 0) {
    if (param_1[3] == 0) {
      uVar19 = (undefined4)DAT_140539fd8;
      iVar7 = 0;
      param_1[0x16] = 0;
      do {
        iVar5 = DAT_140e418c8;
        iVar1 = DAT_140e418c8 + iVar7;
        uVar8 = ((uint)(iVar9 + DAT_140e418c8) >> 0x1e ^ iVar9 + DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar8 = uVar8 * 0x800 ^ uVar8;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar8 = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
        DAT_140e9fd1c = uVar8;
        uVar14 = FUN_140134db0(iVar1,DAT_140e9fd18,uVar19);
        uVar11 = (undefined4)uVar14;
        uVar16 = (undefined4)((ulonglong)uVar14 >> 0x20);
        uVar14 = FUN_140134db0(iVar1);
        uVar12 = (undefined4)uVar14;
        uVar17 = (undefined4)((ulonglong)uVar14 >> 0x20);
        uVar14 = FUN_140134db0(iVar5 + iVar6);
        FUN_140070d00(0x2c,DAT_140e44ea8,0x48,param_1[10],param_1[0xb],
                      (short)uVar8 - (short)(uVar8 / 0x10001),uVar14,CONCAT44(uVar17,uVar12),
                      CONCAT44(uVar16,uVar11),0,0xff,0xff,0xff,0xc0,0);
        iVar9 = iVar9 + 0x58;
        iVar7 = iVar7 + 0x22b8;
        iVar6 = iVar6 + 0x378;
      } while (iVar9 < 0xb00);
      iVar7 = param_1[5];
      uStack_c0._0_4_ = param_1[10];
    }
    dVar4 = DAT_14053a778;
    dVar3 = DAT_140539e60;
    uVar8 = param_1[3];
    dVar15 = DAT_140539e60;
    if (-1 < (int)uVar8) {
      dVar15 = (double)CONCAT44(uVar18,uVar13);
    }
    if (uVar8 < 0x20) {
      dVar15 = (double)FUN_140332d90(((double)(int)uVar8 - 0.0) * DAT_14053a778 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar15 = dVar15 * ((double)CONCAT44(uVar18,uVar13) - dVar3) + dVar3;
    }
    uVar13 = SUB84(dVar15,0);
    uVar18 = (undefined4)((ulonglong)dVar15 >> 0x20);
    iVar6 = 0;
    if ((-1 < (int)uVar8) && (iVar6 = iVar10, (int)uVar8 < 0x20)) {
      dVar15 = (double)FUN_140332d90(((double)(int)uVar8 - 0.0) * dVar4 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar6 = (int)(dVar15 * (double)iVar10);
    }
    param_1[0x14] = iVar6;
    if (DAT_140e44654 < 0x3d) {
      iVar7 = iVar7 + 1;
      param_1[0x15] = 1;
      param_1[5] = iVar7;
      param_1[3] = 0;
    }
  }
  iVar10 = 0xff;
  if (iVar7 == 1) {
    uVar8 = param_1[3];
    iVar7 = 0xff;
    if (uVar8 < 0x10) {
      dVar15 = (double)FUN_140332d90(((double)(int)uVar8 - _DAT_14053b100) * DAT_14053a900 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar7 = (int)(dVar15 * DAT_14053a5f8);
    }
    iVar10 = 0;
    if ((int)uVar8 < 0x10) {
      iVar10 = iVar7;
    }
    if (uVar8 == 0x10) {
      *param_1 = 0;
    }
  }
  FUN_1400c8410(DAT_140e45078,0x3c,8,(undefined4)uStack_c0,param_1[0xb],(short)DAT_140e418c8 * 0x400
                ,CONCAT44(uVar18,uVar13),CONCAT44(uVar18,uVar13),0xff,0xff,0xff,iVar10,1,0);
  FUN_1400c8410(DAT_140e45078,0x3c,8,param_1[10],param_1[0xb],(short)DAT_140e418c8 * -0x400,
                CONCAT44(uVar18,uVar13),CONCAT44(uVar18,uVar13),0xff,0xff,0xff,iVar10,1,0);
  return;
}


