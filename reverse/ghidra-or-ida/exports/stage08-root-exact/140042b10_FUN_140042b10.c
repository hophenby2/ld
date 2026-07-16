// Function: FUN_140042b10 @ 140042b10
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140042b10(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  ulonglong uVar3;
  double dVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  ushort uVar14;
  uint uVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar25;
  uint in_stack_ffffffffffffff00;
  uint uVar26;
  undefined2 uVar28;
  undefined4 uVar27;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  
  dVar21 = DAT_140539e60;
  uVar28 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar25 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  uVar12 = 0;
  if (param_1[5] == 0) {
    uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar8;
    dVar4 = DAT_140539fc8 - (double)(int)param_1[3] * dVar21;
    uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar4,0);
    in_stack_ffffffffffffff08._0_8_ = dVar4;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    uVar26 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar26,in_stack_ffffffffffffff08,0xff,
                  0xff,0xff,0xff,1,0);
    uVar15 = DAT_140e418c8;
    uVar28 = (undefined2)(uVar26 >> 0x10);
    uVar25 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4018000000000000;
      uVar15 = (uVar15 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar15 * 0x800 ^ uVar15;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      *(short *)(param_1 + 0x10) =
           (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9 + 0x3a24;
      uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140043677;
  fVar24 = (float)param_1[0xb];
  fVar23 = (float)param_1[10];
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                 SUB84((double)(DAT_140e445d8 - fVar23),0));
  dVar4 = DAT_14053aba0;
  iVar7 = param_1[3];
  if (iVar7 < 200) {
    uVar2 = *(ushort *)(param_1 + 0x10);
    uVar14 = (ushort)(int)(dVar19 * DAT_14053aba0);
    iVar10 = ((int)(dVar19 * DAT_14053aba0) & 0xffffU) - (uint)uVar2;
    iVar6 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar6 = iVar10;
    }
    iVar10 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar10 = iVar6;
    }
    if (iVar10 < 1) {
      uVar11 = uVar2;
      if ((iVar10 < 0) && (uVar11 = uVar2 - 0xff, -0xff < iVar10)) {
        uVar11 = uVar14;
      }
    }
    else {
      uVar11 = uVar14;
      if (0xfe < iVar10) {
        uVar11 = uVar2 + 0xff;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
  }
  dVar21 = *(double *)(param_1 + 0x12) + dVar21;
  *(double *)(param_1 + 0x12) = dVar21;
  dVar19 = (double)FUN_1403307c0();
  fVar23 = (float)(dVar19 * dVar21) + fVar23;
  param_1[10] = fVar23;
  dVar20 = (double)FUN_140332d90();
  uVar8 = _UNK_14053bb28;
  dVar19 = _DAT_14053bb20;
  fVar24 = (float)(dVar20 * dVar21) + fVar24;
  param_1[0xb] = fVar24;
  fVar17 = DAT_140e445d8;
  if ((((iVar7 < 200) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= fVar23)) &&
      (fVar23 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
     ((DAT_14053aca8 <= fVar24 && (fVar24 <= DAT_14053aef4)))) {
    dVar21 = (double)FUN_1403307c0();
    fVar23 = (float)(dVar21 * DAT_14053a278) + fVar23;
    dVar21 = (double)FUN_140332d90();
    fVar24 = (float)(dVar21 * DAT_14053a278) + fVar24;
    dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                   SUB84((double)(fVar17 - fVar23),0));
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x12;
    }
    else if (DAT_140e419b8 == 1) {
      iVar6 = 10;
    }
    else if (DAT_140e419b8 == 2) {
LAB_140042f53:
      iVar6 = 6;
    }
    else if (DAT_140e419b8 == 3) {
      iVar6 = 8;
    }
    else if (DAT_140e419b8 == 4) goto LAB_140042f53;
    dVar20 = DAT_14053a118;
    if (((DAT_140e419b8 != 0) && (dVar20 = DAT_14053a140, DAT_140e419b8 != 1)) &&
       ((dVar20 = DAT_14053a178, DAT_140e419b8 != 2 &&
        ((dVar20 = DAT_14053a190, DAT_140e419b8 != 3 && (dVar20 = dVar19, DAT_140e419b8 == 4)))))) {
      dVar20 = DAT_14053a1c8;
    }
    if (4 < iVar7) {
      uVar3 = (longlong)(iVar7 + -5) % (longlong)(iVar6 * 5);
      iVar7 = (int)uVar3;
      if ((iVar7 < iVar6 * 3) &&
         ((int)((longlong)((ulonglong)(uint)(iVar7 >> 0x1f) << 0x20 | uVar3 & 0xffffffff) %
               (longlong)iVar6) == 0)) {
        fVar17 = (float)FUN_140334430(fVar23 - fVar17,DAT_140539fc0);
        fVar18 = (float)FUN_140334430(fVar24 - DAT_140e445dc);
        if (fVar17 + fVar18 < 0.0) {
          fVar17 = (float)FUN_1403352f8();
        }
        else {
          fVar17 = SQRT(fVar17 + fVar18);
        }
        if (DAT_14053ad10 <= fVar17) {
          auVar29._12_4_ = in_stack_ffffffffffffff08._12_4_;
          auVar29._0_8_ = in_stack_ffffffffffffff08._0_8_;
          auVar29._8_4_ = 1;
          auVar30._8_8_ = auVar29._8_8_;
          auVar30._0_8_ = dVar20;
          sVar13 = (short)(((int)(dVar21 * dVar4) & 0xffffU) + 0x400 >> 0xb) * 0x800;
          uVar28 = 0;
          FUN_14006c2f0(0,0,fVar23,fVar24,CONCAT22(uVar25,sVar13),0,dVar20,auVar30._8_8_,0);
          if (2 < DAT_140e419b8) {
            do {
              auVar31._12_4_ = auVar30._12_4_;
              auVar31._0_8_ = auVar30._0_8_;
              auVar31._8_4_ = 1;
              auVar30._8_8_ = auVar31._8_8_;
              auVar30._0_8_ = dVar20 - dVar19;
              uVar28 = 0;
              FUN_14006c2f0(0,0,fVar23,fVar24,(short)((uVar12 & 0xffff) * 4000) + sVar13 + -2000,0,
                            dVar20 - dVar19,auVar30._8_8_,0);
              uVar12 = uVar12 + 1;
            } while ((int)uVar12 < 2);
          }
        }
      }
    }
  }
  dVar20 = DAT_14053a020;
  dVar4 = DAT_140539d28;
  uVar25 = *(undefined2 *)(param_1 + 0x10);
  dVar21 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a930 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar21 = (double)((float)(dVar21 * DAT_14053a070) + 0.0);
  dVar22 = (double)FUN_1403307c0();
  fVar24 = (float)(dVar22 * dVar21) + 0.0;
  dVar22 = (double)FUN_140332d90();
  uVar27 = CONCAT22(uVar28,uVar25);
  fVar23 = (float)(dVar22 * dVar21) + 0.0;
  FUN_1400c8410(DAT_140e44880,0x24,7,fVar24 + (float)param_1[10],fVar23 + (float)param_1[0xb],uVar27
                ,dVar19,uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar12 = CONCAT22((short)((uint)uVar27 >> 0x10),*(short *)(param_1 + 0x10) + -0x8000);
  FUN_1400c8410(DAT_140e44880,0x24,7,(float)param_1[10] - fVar24,(float)param_1[0xb] - fVar23,uVar12
                ,dVar19,uVar8,0xff,0xff,0xff,0xff,1,1);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar12,dVar19,uVar8,0xff,0xff,0xff,
                0xff,1,0);
  dVar21 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * dVar20 * dVar4);
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar12 & 0xffff0000,dVar19,uVar8,0xff,
                0xff,0xff,0x80 - (int)(dVar21 * DAT_14053b1c8),1,0);
  uVar27 = DAT_140e44880;
  puVar9 = DAT_140e45d28;
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    uVar25 = *(undefined2 *)(param_1 + 0x10);
    fVar17 = (float)param_1[0xb];
    fVar18 = (float)param_1[10];
    iVar7 = DAT_140e45d1c;
    if (DAT_140e45d1c < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar7 = DAT_140e45d1c + 1;
      *(float *)((longlong)puVar9 + 0x14) = fVar24 + fVar18;
      bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar9 + 3) = fVar23 + fVar17;
      *(float *)((longlong)puVar9 + 0x1c) = fVar24 + fVar18;
      *(float *)(puVar9 + 4) = fVar23 + fVar17;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 5;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar27;
      *(undefined4 *)(puVar9 + 2) = 0x23;
      *(undefined2 *)((longlong)puVar9 + 0x24) = uVar25;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      puVar9[10] = 0x60;
      puVar9[0xb] = 0;
      if (bVar16) {
        DAT_140e45d78 = puVar9;
      }
      DAT_140e45d1c = iVar7;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
    DAT_140e45d28 = puVar9;
    uVar27 = DAT_140e44880;
    sVar13 = *(short *)(param_1 + 0x10);
    fVar17 = (float)param_1[0xb];
    fVar18 = (float)param_1[10];
    puVar9 = DAT_140e45d28;
    if (iVar7 < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar7 = DAT_140e45d1c + 1;
      *(float *)((longlong)puVar9 + 0x14) = fVar18 - fVar24;
      bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar9 + 3) = fVar17 - fVar23;
      *(float *)((longlong)puVar9 + 0x1c) = fVar18 - fVar24;
      *(float *)(puVar9 + 4) = fVar17 - fVar23;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 7;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar27;
      *(undefined4 *)(puVar9 + 2) = 0x23;
      *(short *)((longlong)puVar9 + 0x24) = sVar13 + -0x8000;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      puVar9[10] = 0x60;
      puVar9[0xb] = 0;
      if (bVar16) {
        DAT_140e45d78 = puVar9;
      }
      DAT_140e45d1c = iVar7;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
    DAT_140e45d28 = puVar9;
    uVar5 = DAT_140e4487c;
    uVar27 = param_1[0xb];
    uVar1 = param_1[10];
    puVar9 = DAT_140e45d28;
    if (iVar7 < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar9 + 0x14) = uVar1;
      *(undefined4 *)(puVar9 + 3) = uVar27;
      *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar1;
      *(undefined4 *)(puVar9 + 4) = uVar27;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 5;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar5;
      *(undefined4 *)(puVar9 + 2) = 0x23;
      *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      puVar9[10] = 0x60;
      puVar9[0xb] = 0;
      if (bVar16) {
        DAT_140e45d78 = puVar9;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
  }
  DAT_140e45d28 = puVar9;
  FUN_140079c10(param_1,2);
LAB_140043677:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,200,2);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


