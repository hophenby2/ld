// Function: FUN_140075a00 @ 140075a00
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140075a00(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  longlong lVar8;
  double dVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar14;
  short sVar15;
  short sVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  undefined8 uVar21;
  double dVar22;
  undefined4 uVar23;
  double dVar24;
  float fVar25;
  undefined8 in_stack_fffffffffffffe80;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar26 [16];
  undefined8 uStack_110;
  
  dVar9 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  uVar11 = (uint)((ulonglong)in_stack_fffffffffffffe80 >> 0x20);
  iVar10 = param_1[0x14];
  if ((int)param_1[0x15] < 1) {
    uStack_110._0_4_ = (float)param_1[5];
    uStack_110._4_4_ = (float)param_1[6];
  }
  else {
    lVar8 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
        if (*(int *)(lVar8 + 4) == param_1[0x15]) {
          uStack_110 = *(undefined8 *)(lVar8 + 0x28);
        }
      }
    }
  }
  iVar2 = param_1[2];
  if (iVar2 - 0x33U < 2) {
    iVar3 = param_1[1];
    iVar4 = param_1[0x10];
    uVar12 = (DAT_140e418c8 - iVar3) + 0x6f;
    fVar18 = (float)param_1[5];
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    iVar13 = ((uint)((ulonglong)DAT_140e9fd1c / 0x12d) & 0xffff) * 0x12d;
    sVar16 = (short)DAT_140e9fd1c;
    fVar17 = 0.0;
    if (((iVar4 != 0) && (fVar17 = fVar18, -1 < iVar3)) && (fVar17 = 0.0, iVar3 < iVar4)) {
      dVar19 = (double)FUN_140332d90(iVar13,(ulonglong)DAT_140e9fd1c / 0x12d,
                                     (DAT_14053ac08 / (double)(iVar4 * 4)) * ((double)iVar3 - 0.0) *
                                     DAT_14053a020 * DAT_140539d28);
      fVar17 = (float)(dVar19 * (double)(0.0 - fVar18)) + fVar18;
    }
    sVar1 = *(short *)(param_1 + 9);
    dVar19 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar19 * (double)fVar17) + (float)uStack_110;
    dVar19 = (double)FUN_140332d90();
    auVar26._4_12_ = in_stack_fffffffffffffe88._4_12_;
    auVar26._0_4_ = iVar10;
    sVar15 = sVar1 + (short)iVar3 * -999;
    fVar18 = (float)(dVar19 * (double)fVar17) + uStack_110._4_4_;
    iVar10 = FUN_1401348b0(iVar3,0,0x10,iVar4 + -4,iVar4,(ulonglong)uVar11 << 0x20,auVar26);
    dVar19 = *(double *)(param_1 + 0xc);
    dVar24 = dVar19 + DAT_140539f40;
    dVar20 = dVar19;
    if (((iVar4 != 0) && (dVar20 = dVar24, -1 < iVar3)) && (dVar20 = dVar19, iVar3 < iVar4)) {
      dVar20 = (double)FUN_140332d90();
      dVar20 = (dVar19 - dVar24) * dVar20 + dVar24;
    }
    uVar23 = (undefined4)((ulonglong)dVar20 >> 0x20);
    *(short *)(param_1 + 9) = sVar1 - ((sVar16 - (short)iVar13) + 600);
    if (iVar2 == 0x33) {
      auVar5._8_4_ = SUB84(dVar20,0);
      auVar5._0_8_ = dVar20;
      auVar5._12_4_ = uVar23;
      FUN_1400c8410(param_1[3],param_1[4],8,fVar25,fVar18,sVar15,auVar5,param_1[0x11],param_1[0x12],
                    param_1[0x13],iVar10,1,0);
    }
    if (param_1[2] == 0x34) {
      auVar6._8_4_ = SUB84(dVar20,0);
      auVar6._0_8_ = dVar20;
      auVar6._12_4_ = uVar23;
      FUN_1400c8410(param_1[3],param_1[4],7,fVar25,fVar18,sVar15,auVar6,param_1[0x11],param_1[0x12],
                    param_1[0x13],iVar10,1,0);
    }
  }
  if (param_1[2] != 0x35) goto LAB_140076081;
  iVar2 = param_1[0x10];
  iVar3 = param_1[1];
  if (iVar3 < iVar2 + -0x1e) {
    if (iVar3 == 0) {
      fVar18 = (float)param_1[5];
      dVar19 = (double)FUN_1403307c0();
      uStack_110._0_4_ = (float)(dVar19 * (double)fVar18) + (float)uStack_110;
      dVar19 = (double)FUN_140332d90();
      param_1[7] = (float)uStack_110;
      param_1[8] = (float)(dVar19 * (double)fVar18) + uStack_110._4_4_;
    }
    else {
      uStack_110._0_4_ = (float)param_1[7];
      fVar18 = DAT_14053acbc;
      if ((iVar3 < 0) || (fVar18 = 0.0, 0x31 < iVar3)) goto LAB_140075f4b;
    }
    dVar19 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a670 * dVar9 * dVar22);
    fVar18 = (float)(dVar19 * _DAT_14053b148) + DAT_14053acbc;
  }
  else {
    dVar19 = (double)FUN_140332d90();
    uStack_110._0_4_ =
         (float)(dVar19 * (double)((float)uStack_110 - (float)param_1[7])) + (float)param_1[7];
    dVar19 = (double)FUN_140332d90();
    fVar18 = (float)(dVar19 * (double)(uStack_110._4_4_ - (float)param_1[8]));
  }
LAB_140075f4b:
  fVar17 = (float)param_1[8];
  uVar21 = FUN_1401349e0(iVar3,0,0x1e,iVar2 + -0x1e,iVar2,0,*(undefined8 *)(param_1 + 0xc));
  uVar14 = 0;
  if ((-1 < iVar3) && (iVar3 < 0x1e)) {
    dVar22 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a798 * dVar9 * dVar22);
    uVar14 = (undefined2)(int)(dVar22 * _DAT_14053ac20);
  }
  if ((iVar3 == iVar2) && (DAT_140e445d4 == 1)) {
    FUN_140184700(DAT_140e44190 * 0xc,DAT_140e4726c);
    FUN_14018a340(DAT_140e4726c,1,1);
  }
  uVar11 = DAT_140e418c8 & 0x80000001;
  if ((int)uVar11 < 0) {
    uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
  }
  if (uVar11 != 0) {
    iVar10 = iVar10 / 2;
  }
  auVar7._8_4_ = (int)uVar21;
  auVar7._0_8_ = uVar21;
  auVar7._12_4_ = (int)((ulonglong)uVar21 >> 0x20);
  FUN_1400c8410(param_1[3],param_1[4],7,(float)uStack_110,fVar18 + fVar17,uVar14,auVar7,
                param_1[0x11],param_1[0x13],param_1[0x12],iVar10,1,0);
LAB_140076081:
  if (param_1[1] == param_1[0x10]) {
    *param_1 = 0;
  }
  return;
}


