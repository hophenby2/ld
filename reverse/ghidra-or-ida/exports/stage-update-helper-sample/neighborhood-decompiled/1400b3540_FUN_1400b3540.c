// Function: FUN_1400b3540 @ 1400b3540
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b3540(undefined4 *param_1)

{
  ushort *puVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short sVar7;
  double dVar8;
  float fVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  uint uVar18;
  ulonglong uVar19;
  uint uVar20;
  ulonglong uVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffee0;
  undefined1 in_stack_fffffffffffffee8 [16];
  undefined1 auVar31 [16];
  undefined1 local_d8 [16];
  float local_c8 [40];
  
  uVar17 = (ushort)((uint)in_stack_fffffffffffffee0 >> 0x10);
  fVar27 = (float)param_1[0xb];
  fVar2 = (float)param_1[10];
  dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar27),
                                 SUB84((double)(DAT_140e445d8 - fVar2),0));
  dVar8 = DAT_14053aba0;
  uVar21 = 0;
  uVar20 = (uint)(dVar23 * DAT_14053aba0);
  if (param_1[5] == 0) {
    iVar14 = param_1[3];
    if (iVar14 == 0) {
      if (param_1[6] == 0x103) {
        *(undefined2 *)(param_1 + 0x10) = 0x64a8;
      }
      else if (param_1[6] == 0x104) {
        *(undefined2 *)(param_1 + 0x10) = 7000;
      }
    }
    dVar23 = (double)((float)((uint)fVar27 ^ DAT_14053bf00) * DAT_140539d58);
    dVar24 = (double)FUN_1403307c0();
    dVar25 = (double)FUN_140332d90();
    uVar11 = FUN_1401346a0(CONCAT44((float)(dVar25 * dVar23) + fVar27,
                                    (float)(dVar24 * dVar23) + fVar2),0xffffffce);
    local_res8 = (undefined4)uVar11;
    dVar23 = DAT_14053a018 - (double)iVar14 * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
    in_stack_fffffffffffffee8._8_4_ = SUB84(dVar23,0);
    in_stack_fffffffffffffee8._0_8_ = dVar23;
    in_stack_fffffffffffffee8._12_4_ = (int)((ulonglong)dVar23 >> 0x20);
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,(uint)uVar17 << 0x10,
                  in_stack_fffffffffffffee8,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4028000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  fVar27 = DAT_14053ab70;
  if (param_1[5] != 1) goto LAB_1400b4270;
  uVar18 = param_1[3];
  uVar17 = (ushort)uVar20;
  if ((int)uVar18 < 100) {
    dVar23 = *(double *)(param_1 + 0x12);
    if ((uVar18 < 0x65) && (0.0 < dVar23)) {
      dVar23 = dVar23 - DAT_140539e70;
    }
    uVar15 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar20 & 0xffff) - (uint)uVar15;
    *(double *)(param_1 + 0x12) = dVar23;
    iVar14 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar14 = iVar13;
    }
    iVar13 = iVar14 + -0x10000;
    if (iVar14 < 0x8001) {
      iVar13 = iVar14;
    }
    if (iVar13 < 1) {
      if ((iVar13 < 0) && (uVar15 = uVar15 - 0x20, -0x20 < iVar13)) {
        uVar15 = uVar17;
      }
      *(ushort *)(param_1 + 0x10) = uVar15;
    }
    else if (iVar13 < 0x20) {
      *(ushort *)(param_1 + 0x10) = uVar17;
    }
    else {
      *(ushort *)(param_1 + 0x10) = uVar15 + 0x20;
    }
  }
  else {
    if ((int)uVar18 < 0xf0) {
      puVar1 = (ushort *)(param_1 + 0x10);
      if (uVar18 == 100) {
        uVar18 = param_1[3];
        *puVar1 = uVar17;
LAB_1400b3817:
        *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + _DAT_140539e28;
      }
      else if ((int)uVar18 < 0x82) goto LAB_1400b3817;
      uVar15 = *puVar1;
      iVar13 = (uVar20 & 0xffff) - (uint)uVar15;
      iVar14 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar14 = iVar13;
      }
      iVar13 = iVar14 + -0x10000;
      if (iVar14 < 0x8001) {
        iVar13 = iVar14;
      }
      if (iVar13 < 1) {
        uVar16 = uVar15;
        if ((iVar13 < 0) && (uVar16 = uVar15 - 0x80, -0x80 < iVar13)) {
          uVar16 = uVar17;
        }
      }
      else {
        uVar16 = uVar17;
        if (0x7f < iVar13) {
          uVar16 = uVar15 + 0x80;
        }
      }
      *puVar1 = uVar16;
      if ((int)uVar18 < 0xf0) goto LAB_1400b3896;
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) - DAT_140539e60;
  }
LAB_1400b3896:
  dVar23 = (double)FUN_1403307c0();
  fVar30 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar30;
  dVar23 = (double)FUN_140332d90();
  fVar28 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar28;
  fVar9 = DAT_14053af14;
  fVar29 = DAT_14053aec0;
  fVar2 = DAT_14053acd4;
  uVar11 = DAT_14053a138;
  if ((int)uVar18 < 0xf0) {
    local_c8[0] = fVar30 + DAT_14053ac5c;
    local_c8[1] = fVar28 - DAT_14053aca0;
    local_c8[3] = fVar28 - DAT_14053aca0;
    local_c8[2] = fVar30 - DAT_14053ac5c;
    local_d8 = _DAT_14053b990;
    local_c8[6] = fVar30 - _DAT_14053acb8;
    local_c8[4] = fVar30 + _DAT_14053acb8;
    local_c8[5] = fVar28 - DAT_14053acd4;
    local_c8[7] = fVar28 - DAT_14053acd4;
    uVar19 = uVar21;
    do {
      iVar14 = param_1[3];
      uVar20 = iVar14 - 0x32;
      if (uVar20 < 0xbe) {
        if (uVar20 == ((int)uVar20 / 100) * 100) {
          dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((float)param_1[0xb] - fVar2)),
                                         SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar23 * dVar8);
          iVar14 = (iVar14 + -0x32) % 100;
        }
        else if ((0xbd < uVar20) || (iVar14 = (iVar14 + -0x32) % 100, 0x1d < iVar14))
        goto LAB_1400b3b02;
        if (iVar14 == (iVar14 / 5) * 5) {
          fVar28 = local_c8[uVar19 * 2];
          fVar30 = local_c8[uVar19 * 2 + 1];
          fVar26 = DAT_140e445d8 / fVar27;
          if ((((fVar26 + 0.0 <= fVar28) && (fVar28 <= fVar26 + fVar29)) && (0.0 <= fVar30)) &&
             (fVar30 <= fVar9)) {
            auVar31._12_4_ = in_stack_fffffffffffffee8._12_4_;
            auVar31._0_8_ = in_stack_fffffffffffffee8._0_8_;
            auVar31._8_4_ = 1;
            in_stack_fffffffffffffee8._8_8_ = auVar31._8_8_;
            in_stack_fffffffffffffee8._0_8_ = uVar11;
            FUN_14006c2f0(4,0x34,fVar28,fVar30,
                          *(short *)(local_d8 + uVar19 * 4) + *(short *)((longlong)param_1 + 0x42),0
                          ,uVar11,in_stack_fffffffffffffee8._8_8_,0);
          }
        }
      }
LAB_1400b3b02:
      uVar19 = uVar19 + 1;
    } while ((longlong)uVar19 < 4);
  }
  uVar4 = DAT_140e44e24;
  fVar2 = DAT_14053acbc;
  sVar7 = *(short *)(param_1 + 3);
  uVar3 = param_1[10];
  fVar29 = (float)param_1[0xb] + DAT_14053acbc;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  puVar12[3] = uVar3;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[4] = fVar29;
  *puVar12 = uVar4;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  *(short *)(puVar12 + 5) = sVar7 * 600;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar4 = DAT_140e44e24;
  sVar7 = *(short *)(param_1 + 3);
  fVar29 = (float)param_1[0xb];
  uVar3 = param_1[10];
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar12 = uVar4;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  puVar12[3] = uVar3;
  puVar12[4] = fVar29 + fVar2;
  *(short *)(puVar12 + 5) = sVar7 * 600 + 0x4000;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar4 = DAT_140e44e24;
  sVar7 = *(short *)(param_1 + 3);
  fVar29 = (float)param_1[0xb];
  uVar3 = param_1[10];
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar12 = uVar4;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  puVar12[3] = uVar3;
  puVar12[4] = fVar29 + fVar2;
  *(short *)(puVar12 + 5) = sVar7 * 600 + -0x8000;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar4 = DAT_140e44e24;
  sVar7 = *(short *)(param_1 + 3);
  fVar29 = (float)param_1[0xb];
  uVar3 = param_1[10];
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar12 = uVar4;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  puVar12[3] = uVar3;
  puVar12[4] = fVar29 + fVar2;
  *(short *)(puVar12 + 5) = sVar7 * 600 + -0x4000;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  uVar10 = DAT_140e44e20;
  uVar3 = param_1[0xb];
  uVar4 = param_1[10];
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar12[3] = uVar4;
  puVar12[4] = uVar3;
  *puVar12 = uVar10;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar12;
  }
  uVar19 = uVar21;
  uVar3 = DAT_14053acec;
  uVar4 = DAT_14053aca8;
  fVar2 = DAT_14053ac18;
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    uVar3 = DAT_14053acec;
    uVar4 = DAT_14053aca8;
    fVar2 = DAT_14053ac18;
  }
  do {
    DAT_140e46c88 = puVar12;
    uVar17 = (short)uVar19 * 0x13b1 + (short)((uint)(ushort)DAT_140e418c8 * 0xde);
    uVar11 = FUN_140133f30((uint)(ushort)DAT_140e418c8 * 0xde,(float)param_1[0xb] - fVar2,0,uVar17,
                           uVar4,uVar3);
    uVar10 = DAT_140e448f4;
    puVar12 = DAT_140e46c88;
    if (0x8000 < uVar17) {
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar11;
      uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
      puVar12[3] = local_res8;
      puVar12[4] = uStackX_c;
      *puVar12 = uVar10;
      puVar12[1] = 0x20;
      puVar12[2] = 7;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      DAT_140e46d10 = DAT_140e46d10 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    uVar10 = DAT_140e44e1c;
    uVar20 = (int)uVar19 + 1;
    uVar19 = (ulonglong)uVar20;
    puVar12 = DAT_140e46c88;
  } while ((int)uVar20 < 0xd);
  uVar5 = param_1[0xb];
  uVar6 = param_1[10];
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar12[3] = uVar6;
  puVar12[4] = uVar5;
  *puVar12 = uVar10;
  puVar12[1] = 0x20;
  puVar12[2] = 7;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  do {
    DAT_140e46c88 = puVar12;
    uVar17 = (short)uVar21 * 0x13b1 + (short)((uint)(ushort)DAT_140e418c8 * 0xde);
    uVar11 = FUN_140133f30((uint)(ushort)DAT_140e418c8 * 0xde,(float)param_1[0xb] - fVar2,0,uVar17,
                           uVar4,uVar3);
    uVar10 = DAT_140e448f4;
    puVar12 = DAT_140e46c88;
    if (uVar17 < 0x8001) {
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      local_res8 = (undefined4)uVar11;
      uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
      puVar12[3] = local_res8;
      puVar12[4] = uStackX_c;
      *puVar12 = uVar10;
      puVar12[1] = 0x20;
      puVar12[2] = 7;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      DAT_140e46d10 = DAT_140e46d10 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    uVar20 = (int)uVar21 + 1;
    uVar21 = (ulonglong)uVar20;
    puVar12 = DAT_140e46c88;
  } while ((int)uVar20 < 0xd);
  FUN_140079c10(param_1,1);
LAB_1400b4270:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  fVar27 = DAT_140e445d8 / fVar27;
  if (((((float)param_1[10] < fVar27 - DAT_14053ad4c) ||
       (fVar27 + _DAT_14053af18 < (float)param_1[10])) ||
      (((float)param_1[0xb] < DAT_14053b398 || (_DAT_14053af5c < (float)param_1[0xb])))) &&
     (0x77 < (int)param_1[3])) {
    *param_1 = 0;
  }
  return;
}


