// Function: FUN_1400526c0 @ 1400526c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400526c0(undefined4 *param_1)

{
  undefined2 *puVar1;
  short sVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  float fVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined2 uVar18;
  ulonglong in_stack_fffffffffffffe70;
  ulonglong uVar19;
  undefined8 uStack_130;
  undefined8 uStack_120;
  undefined8 uStack_110;
  
  uStack_120 = 0;
  uStack_120._4_4_ = 0;
  lVar4 = DAT_140e45d80;
  uVar8 = uStack_130._4_4_;
  iVar7 = uStack_120._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      uVar8 = (uint)((ulonglong)uStack_130 >> 0x20);
      iVar7 = (int)((ulonglong)uStack_120 >> 0x20);
      if (lVar4 == 0) break;
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        uStack_130 = *(undefined8 *)(lVar4 + 8);
        uStack_120 = *(undefined8 *)(lVar4 + 0x18);
        uStack_110 = *(undefined8 *)(lVar4 + 0x28);
      }
      lVar4 = *(longlong *)(lVar4 + 0x60);
    }
  }
  uStack_120._4_4_ = iVar7;
  uStack_130._4_4_ = uVar8;
  iVar7 = param_1[3];
  dVar14 = *(double *)(param_1 + 0x12);
  fVar11 = (float)FUN_140134b10(iVar7,0,0x96,0x96,300,in_stack_fffffffffffffe70 & 0xffffffff00000000
                                ,param_1[0xe]);
  dVar15 = DAT_140539f40;
  if (iVar7 < 0) {
LAB_140052829:
    dVar13 = 0.0;
  }
  else {
    if (iVar7 < 0x1e) {
      dVar13 = (double)iVar7 - 0.0;
    }
    else {
      dVar13 = DAT_140539f40;
      if (iVar7 < 0x10e) goto LAB_14005282d;
      if (299 < iVar7) goto LAB_140052829;
      dVar13 = (double)iVar7 - DAT_14053a5e8;
    }
    dVar13 = (double)FUN_140332d90(dVar13 * DAT_14053a798 * DAT_14053a020 * DAT_140539d28);
    dVar13 = dVar13 + 0.0;
  }
LAB_14005282d:
  uVar16 = SUB84(dVar13,0);
  uVar19 = 0;
  uVar18 = 0;
  uVar12 = FUN_1401349e0(iVar7,0,0xf,0x11d,300,0,SUB84(dVar15,0));
  param_1[0xd] = uStack_110._4_4_;
  param_1[0xc] = (float)uStack_110;
  if (param_1[5] != 0) goto LAB_140052d6f;
  sVar10 = (short)(int)dVar14;
  *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar10;
  sVar2 = *(short *)(param_1 + 0x10);
  dVar14 = (double)FUN_1403307c0();
  uStack_110._0_4_ = (float)(dVar14 * (double)fVar11) + (float)uStack_110;
  dVar14 = (double)FUN_140332d90();
  param_1[10] = (float)uStack_110;
  param_1[0xb] = (float)(dVar14 * (double)fVar11) + (float)param_1[0xd];
  iVar5 = DAT_140e419b8;
  if (0x1d < iVar7) {
    iVar9 = 1;
    if (DAT_140e419b8 == 0) {
      iVar9 = 6;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 5;
    }
    else if (DAT_140e419b8 == 2) {
      iVar9 = 4;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar9 = 3;
    }
    sVar6 = 1;
    if (DAT_140e419b8 == 0) {
      sVar6 = 200;
    }
    else if (DAT_140e419b8 == 1) {
      sVar6 = 0xe6;
    }
    else if (DAT_140e419b8 == 2) {
      sVar6 = 0x10e;
    }
    else if (DAT_140e419b8 == 3) {
      sVar6 = 0x154;
    }
    else if (DAT_140e419b8 == 4) {
      sVar6 = 0x1d6;
    }
    dVar14 = DAT_14053a0b0;
    if ((((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
        (dVar14 = DAT_14053a118, DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 == 3 || (dVar14 = dVar15, DAT_140e419b8 == 4)))) {
      dVar14 = DAT_14053a138;
    }
    dVar15 = (double)(iVar7 + -0x1e);
    uVar3 = SUB84(dVar15 * _DAT_140539dd0 + dVar14,0);
    if (3 < DAT_140e419b8) {
      uVar3 = SUB84(dVar15 * DAT_140539de8 + DAT_14053a138,0);
    }
    if (iVar7 == 0x1e) {
      uVar8 = (uStack_130._4_4_ >> 0x1e ^ uStack_130._4_4_) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar8 = uVar8 * 0x800 ^ uVar8;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
      *(short *)((longlong)param_1 + 0x42) =
           (sVar2 - (short)(DAT_140e9fd1c / 0x10001)) + (short)DAT_140e9fd1c;
LAB_140052ac6:
      if ((iVar7 + -0x1e) % iVar9 == 0) {
        if (iVar5 < 4) {
          sVar2 = *(short *)((longlong)param_1 + 0x42);
          uVar17 = param_1[0xb];
          iVar7 = 0;
          if (param_1[6] - 0xda < 2) {
            do {
              uVar19 = uVar19 & 0xffffffff00000000;
              FUN_14006c2f0(3,0,(float)uStack_110,uVar17,(short)iVar7 * -0x8000 + sVar2,uVar19,uVar3
                            ,1,0);
              iVar7 = iVar7 + 1;
            } while (iVar7 < 2);
          }
          else {
            do {
              uVar19 = uVar19 & 0xffffffff00000000;
              FUN_14006c2f0(2,0,(float)uStack_110,uVar17,(short)iVar7 * -0x8000 + sVar2,uVar19,uVar3
                            ,1,0);
              iVar7 = iVar7 + 1;
            } while (iVar7 < 2);
          }
        }
        else {
          puVar1 = (undefined2 *)((longlong)param_1 + 0x42);
          if (param_1[6] == 0xda) {
            uVar19 = uVar19 & 0xffffffff00000000;
            uVar17 = CONCAT22(uVar18,*puVar1);
            FUN_14006c2f0(0xd,0x2c,(float)uStack_110,param_1[0xb],uVar17,uVar19,uVar3,1,0);
            uVar18 = (undefined2)((uint)uVar17 >> 0x10);
          }
          if (param_1[6] == 0xdb) {
            uVar19 = uVar19 & 0xffffffff00000000;
            uVar17 = CONCAT22(uVar18,*puVar1);
            FUN_14006c2f0(0xd,0x2d,param_1[10],param_1[0xb],uVar17,uVar19,uVar3,1,0);
            uVar18 = (undefined2)((uint)uVar17 >> 0x10);
          }
          if (param_1[6] == 0xdc) {
            uVar19 = uVar19 & 0xffffffff00000000;
            uVar17 = CONCAT22(uVar18,*puVar1);
            FUN_14006c2f0(0xc,0x2c,param_1[10],param_1[0xb],uVar17,uVar19,uVar3,1,0);
            uVar18 = (undefined2)((uint)uVar17 >> 0x10);
          }
          if (param_1[6] == 0xdd) {
            uVar19 = uVar19 & 0xffffffff00000000;
            FUN_14006c2f0(0xc,0x2d,param_1[10],param_1[0xb],CONCAT22(uVar18,*puVar1),uVar19,uVar3,1,
                          0);
          }
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    else if (iVar7 < 0x10e) goto LAB_140052ac6;
    iVar7 = param_1[6];
    if ((iVar7 == 0xda) || (iVar7 == 0xdc)) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar10 + sVar6;
    }
    if ((iVar7 - 0xdbU & 0xfffffffd) == 0) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + (sVar10 - sVar6)
      ;
    }
  }
  if (param_1[3] == 300) {
    *param_1 = 0;
  }
LAB_140052d6f:
  uVar19 = CONCAT62((int6)(uVar19 >> 0x10),uStack_130._4_2_ * 999 + *(short *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e44898,0x23,7,param_1[10],param_1[0xb],uVar19,uVar16,uVar16,0xff,0xff,0xff,
                0xff,1,0);
  uVar19 = uVar19 & 0xffffffffffff0000;
  FUN_1400c8410(DAT_140e4489c,0x23,7,param_1[10],param_1[0xb],uVar19,uVar12,uVar12,0xff,0xff,0xff,
                0xff,1,0);
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    uVar19 = CONCAT62((int6)(uVar19 >> 0x10),uStack_130._4_2_ * 999 + *(short *)(param_1 + 0x10));
    FUN_140070d00(5,DAT_140e44898,0x22,param_1[10],param_1[0xb],uVar19,0,uVar16,uVar16,0x18,0xff,
                  0xff,0xff,0x60,0);
    FUN_140070d00(5,DAT_140e4489c,0x22,param_1[10],param_1[0xb],uVar19 & 0xffffffffffff0000,0,uVar12
                  ,uVar12,0x18,0xff,0xff,0xff,0x60,0);
  }
  if ((uStack_120._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


