// Function: FUN_140044910 @ 140044910
// Decompile completed: true

void FUN_140044910(undefined4 *param_1)

{
  undefined4 uVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  longlong lVar9;
  double dVar10;
  double dVar11;
  int iVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  int iVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 uVar26;
  undefined2 uVar27;
  undefined2 uVar29;
  uint uVar28;
  undefined1 in_stack_fffffffffffffec8 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  int iStack_dc;
  undefined8 uStack_d0;
  ulonglong uVar36;
  
  dVar21 = DAT_14053a890;
  dVar11 = DAT_14053a020;
  dVar22 = DAT_140539f40;
  dVar10 = DAT_140539d28;
  iStack_dc = 0;
  lVar9 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == DAT_140e44308) {
        iStack_dc = *(int *)(lVar9 + 0x1c);
        uStack_d0 = *(undefined8 *)(lVar9 + 0x28);
      }
    }
  }
  iVar3 = param_1[3];
  dVar2 = *(double *)(param_1 + 0x12);
  if (iVar3 < 0) {
    dVar22 = 0.0;
    dVar20 = DAT_140539e60;
  }
  else {
    dVar20 = DAT_140539f40;
    if (iVar3 < 0x14) {
      dVar20 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a890 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar20 = dVar20 * DAT_140539f38 + DAT_140539e60;
    }
    if (iVar3 < 10) {
      dVar22 = 0.0;
    }
    else if (iVar3 < 0x1e) {
      dVar22 = (double)FUN_140332d90(((double)iVar3 - DAT_14053a1e8) * dVar21 * dVar11 * dVar10);
      dVar22 = dVar22 + 0.0;
    }
  }
  uVar25 = (undefined4)((ulonglong)dVar20 >> 0x20);
  puVar14 = DAT_140e45d28;
  if (param_1[5] != 0) goto LAB_14004500a;
  if (iVar3 == 0) {
    param_1[0xc] = 0.0;
LAB_140044aaa:
    dVar21 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a4d8 * dVar11 * dVar10);
    fVar24 = (float)(dVar21 * DAT_14053a510) + 0.0;
  }
  else if (iVar3 < 0) {
    fVar24 = 0.0;
  }
  else {
    fVar24 = DAT_14053ad70;
    if (iVar3 < 0x78) goto LAB_140044aaa;
  }
  iVar4 = param_1[6];
  sVar16 = *(short *)(param_1 + 0x10);
  param_1[0xc] = fVar24;
  sVar15 = (short)(int)dVar2;
  if (iVar4 == 0xb4) {
    sVar17 = *(short *)(param_1 + 0x11) + 0x4d;
  }
  else {
    sVar15 = -sVar15;
    sVar17 = *(short *)(param_1 + 0x11) + -0x4d;
  }
  *(short *)(param_1 + 0x10) = sVar16 + sVar15;
  *(short *)(param_1 + 0x11) = sVar17;
  fVar23 = fVar24 * DAT_140539d20;
  uVar13 = FUN_140133f30((float)uStack_d0 + (float)param_1[0xe],
                         uStack_d0._4_4_ + (float)param_1[0xf],fVar23,sVar16 + sVar15,fVar23,fVar24)
  ;
  iVar12 = DAT_140e419b8;
  uVar29 = (undefined2)((uint)fVar24 >> 0x10);
  iVar18 = 1;
  local_res8 = (undefined4)uVar13;
  uStackX_c = (undefined4)((ulonglong)uVar13 >> 0x20);
  param_1[10] = local_res8;
  param_1[0xb] = uStackX_c;
  if (iVar12 == 0) {
    iVar18 = 3;
  }
  else if (iVar12 == 1) {
    iVar18 = 2;
  }
  sVar16 = 1;
  if (iVar12 == 0) {
    sVar16 = 0xce4;
  }
  else if (iVar12 == 1) {
    sVar16 = 0x8fc;
  }
  else if (((iVar12 == 2) || (iVar12 == 3)) || (iVar12 == 4)) {
    sVar16 = 0x834;
  }
  if ((0x31 < iVar3) && ((iVar3 + -0x32) % iVar18 == 0)) {
    auVar30._12_4_ = in_stack_fffffffffffffec8._12_4_;
    auVar30._0_8_ = in_stack_fffffffffffffec8._0_8_;
    auVar30._8_4_ = 1;
    uVar36 = auVar30._8_8_;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar36;
    auVar31 = auVar8 << 0x40;
    uVar29 = 0;
    uVar26 = CONCAT22((short)((uint)fVar23 >> 0x10),*(undefined2 *)((longlong)param_1 + 0x42));
    if (iVar4 == 0xb4) {
      FUN_14006c2f0(0xd,1,local_res8,uStackX_c,uVar26,0,0,uVar36,0);
      uVar27 = (undefined2)((uint)uVar26 >> 0x10);
      if (2 < DAT_140e419b8) {
        auVar32._12_4_ = auVar31._12_4_;
        auVar32._0_8_ = auVar31._0_8_;
        auVar32._8_4_ = 1;
        auVar31._8_8_ = auVar32._8_8_;
        auVar31._0_8_ = DAT_140539f00;
        uVar29 = 0;
        uVar26 = CONCAT22(uVar27,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_14006c2f0(0xd,1,param_1[10],param_1[0xb],uVar26,0,DAT_140539f00,auVar31._8_8_,0);
        uVar27 = (undefined2)((uint)uVar26 >> 0x10);
      }
      if (3 < DAT_140e419b8) {
        auVar33._12_4_ = auVar31._12_4_;
        auVar33._0_8_ = auVar31._0_8_;
        auVar33._8_4_ = 1;
        uVar29 = 0;
        FUN_14006c2f0(0xd,1,param_1[10],param_1[0xb],
                      CONCAT22(uVar27,*(short *)((longlong)param_1 + 0x42) + -0x8000),0,0,
                      auVar33._8_8_,0);
      }
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar16;
    }
    else {
      FUN_14006c2f0(0xc,1,local_res8,uStackX_c,uVar26,0,0,uVar36,0);
      uVar27 = (undefined2)((uint)uVar26 >> 0x10);
      if (2 < DAT_140e419b8) {
        auVar34._12_4_ = auVar31._12_4_;
        auVar34._0_8_ = auVar31._0_8_;
        auVar34._8_4_ = 1;
        auVar31._8_8_ = auVar34._8_8_;
        auVar31._0_8_ = DAT_140539f00;
        uVar29 = 0;
        uVar26 = CONCAT22(uVar27,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_14006c2f0(0xc,1,param_1[10],param_1[0xb],uVar26,0,DAT_140539f00,auVar31._8_8_,0);
        uVar27 = (undefined2)((uint)uVar26 >> 0x10);
      }
      if (3 < DAT_140e419b8) {
        auVar35._12_4_ = auVar31._12_4_;
        auVar35._0_8_ = auVar31._0_8_;
        auVar35._8_4_ = 1;
        uVar29 = 0;
        FUN_14006c2f0(0xc,1,param_1[10],param_1[0xb],
                      CONCAT22(uVar27,*(short *)((longlong)param_1 + 0x42) + -0x8000),0,0,
                      auVar35._8_8_,0);
      }
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar16;
    }
    FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
    FUN_14018a340(DAT_140e472a4,1,1);
  }
  auVar7._8_4_ = SUB84(dVar22,0);
  auVar7._0_8_ = dVar22;
  auVar7._12_4_ = (int)((ulonglong)dVar22 >> 0x20);
  uVar28 = CONCAT22(uVar29,*(short *)(param_1 + 3) * 0x309);
  FUN_1400c8410(DAT_140e44884,0x24,8,param_1[10],param_1[0xb],uVar28,auVar7,0xff,0xff,0xff,0xc0,1,0)
  ;
  auVar5._8_4_ = SUB84(dVar20,0);
  auVar5._0_8_ = dVar20;
  auVar5._12_4_ = uVar25;
  uVar28 = uVar28 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar28,auVar5,0xff,0xff,0xff,0xff,1,0)
  ;
  dVar22 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * dVar11 * dVar10);
  auVar6._8_4_ = SUB84(dVar20,0);
  auVar6._0_8_ = dVar20;
  auVar6._12_4_ = uVar25;
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar28 & 0xffff0000,auVar6,0xff,0xff,
                0xff,0x80 - (int)(dVar22 * DAT_14053b1c8),1,0);
  uVar25 = DAT_140e44884;
  uVar28 = param_1[3];
  puVar14 = DAT_140e45d28;
  if ((uVar28 & 1) == 0) {
    uVar26 = param_1[0xb];
    uVar1 = param_1[10];
    if (DAT_140e45d1c < 0x1000) {
      puVar14 = (undefined8 *)_malloc_base(0x60);
      if (puVar14 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar14 + 0x14) = uVar1;
      *(undefined4 *)(puVar14 + 3) = uVar26;
      *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar1;
      *(undefined4 *)(puVar14 + 4) = uVar26;
      *puVar14 = 1;
      *(undefined4 *)(puVar14 + 1) = 5;
      *(undefined4 *)((longlong)puVar14 + 0xc) = uVar25;
      *(undefined4 *)(puVar14 + 2) = 0x23;
      *(short *)((longlong)puVar14 + 0x24) = (short)uVar28 * 0x309;
      puVar14[5] = 0;
      puVar14[6] = 0x3ff0000000000000;
      puVar14[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar14 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
      *(undefined4 *)(puVar14 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
      puVar14[10] = 0x60;
      puVar14[0xb] = 0;
      if (bVar19) {
        DAT_140e45d78 = puVar14;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar14;
      }
    }
  }
LAB_14004500a:
  DAT_140e45d28 = puVar14;
  if ((iStack_dc < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  return;
}


