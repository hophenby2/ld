// Function: FUN_1400a4440 @ 1400a4440
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a4440(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  bool bVar16;
  float fVar17;
  undefined4 uVar18;
  double dVar19;
  double dVar20;
  undefined4 uVar21;
  float fVar22;
  float fVar23;
  undefined4 uVar24;
  float fVar25;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar27;
  undefined4 uVar26;
  uint in_stack_ffffffffffffff00;
  undefined2 uVar28;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  ulonglong in_stack_ffffffffffffff18;
  undefined4 uVar34;
  ulonglong uVar33;
  undefined4 uVar35;
  
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  uVar28 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar34 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
  iVar4 = param_1[3];
  iVar14 = (DAT_140e418c8 - (DAT_140e418c8 - iVar4) / 7) - iVar4;
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(CONCAT44(param_1[0xb],DAT_140e45d24 + (float)param_1[10]),0xffffffec);
    local_res8 = (undefined4)uVar5;
    in_stack_ffffffffffffff18 = CONCAT44(uVar34,0xff);
    dVar20 = DAT_140539fc8 - (double)iVar4 * DAT_140539e60;
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar20,0);
    in_stack_ffffffffffffff08._0_8_ = dVar20;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar20 >> 0x20);
    uVar12 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar12,in_stack_ffffffffffffff08,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,1,0);
    uVar27 = (undefined2)((uint)uStackX_c >> 0x10);
    uVar28 = (undefined2)(uVar12 >> 0x10);
    iVar4 = param_1[3];
    if (param_1[3] == 0x14) {
      uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar5;
      uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
      iVar4 = 0;
    }
  }
  iVar11 = DAT_140e418c8;
  uVar21 = _UNK_14053bb2c;
  uVar18 = _UNK_14053bb28;
  uVar3 = _UNK_14053bb24;
  uVar34 = _DAT_14053bb20;
  dVar2 = DAT_14053a020;
  dVar20 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_1400a4df9;
  fVar23 = (float)param_1[0xb];
  fVar1 = (float)param_1[10];
  dVar19 = (double)FUN_140332d90(((double)DAT_140e418c8 - (double)iVar14) * DAT_14053a5a0 *
                                 DAT_14053a020 * DAT_140539d28);
  uVar35 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
  fVar22 = (float)param_1[0xd];
  iVar9 = (int)fVar22;
  iVar10 = iVar9;
  if (iVar4 >= 0) {
    iVar10 = iVar9 + -800;
  }
  param_1[10] = (float)(dVar19 * DAT_14053a2f0) + (float)param_1[0xc] + DAT_140e45d24;
  if ((iVar4 < 0) || (0x77 < iVar4)) {
    if (iVar4 < 300) goto LAB_1400a4720;
    if (iVar4 < 0x1e0) {
      dVar19 = ((double)iVar4 - DAT_14053a4a0) * DAT_14053a438;
      goto LAB_1400a4694;
    }
    fVar22 = fVar22 + DAT_140539da8;
    param_1[0xb] = (float)iVar9;
    param_1[0xd] = (float)(iVar4 + -0x1e0) * DAT_140539cd8 + fVar22;
  }
  else {
    dVar19 = ((double)iVar4 - 0.0) * DAT_14053a4d8;
LAB_1400a4694:
    dVar20 = (double)FUN_140332d90(dVar19 * dVar2 * dVar20);
    iVar10 = iVar9 - (int)(dVar20 * DAT_14053a888);
LAB_1400a4720:
    fVar17 = DAT_14053aca8;
    uVar35 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
    fVar22 = fVar22 + DAT_140539da8;
    param_1[0xb] = (float)iVar10;
    param_1[0xd] = fVar22;
    fVar25 = DAT_140e445dc;
    fVar22 = DAT_140e445d8;
    if ((((DAT_140e445d8 / DAT_14053ab70 + fVar17 <= fVar1) &&
         (fVar1 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) && (fVar17 <= fVar23)) &&
       (fVar23 <= DAT_14053aef4)) {
      dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),
                                     SUB84((double)(DAT_140e445d8 - fVar1),0));
      uVar35 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
      iVar10 = 1;
      dVar20 = dVar20 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar10 = 0x48;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 0x30;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar10 = 0x28;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 0x20;
      }
      if (DAT_140e419b8 == 0) {
        uVar26 = (undefined4)DAT_14053a078;
        uVar24 = (undefined4)((ulonglong)DAT_14053a078 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar26 = (undefined4)DAT_14053a0c8;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0c8 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar26 = (undefined4)DAT_14053a0f8;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar26 = (undefined4)DAT_14053a0d0;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else {
        uVar26 = uVar34;
        uVar24 = uVar3;
        if (DAT_140e419b8 == 4) {
          uVar26 = (undefined4)DAT_14053a138;
          uVar24 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
        }
      }
      uVar8 = (ushort)(int)dVar20;
      if ((iVar4 - 0x46U < 0x19a) && ((iVar4 + -0x46) % iVar10 == 0)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar8;
        iVar10 = (iVar4 + -0x46) % iVar10;
        fVar22 = DAT_140e445d8;
        fVar25 = DAT_140e445dc;
        uVar15 = uVar8;
LAB_1400a48b9:
        if (iVar10 == (iVar10 / 6 + (iVar10 >> 0x1f) +
                      (int)(((longlong)iVar10 / 6 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 6) {
          fVar22 = (float)FUN_140334430(fVar1 - fVar22,DAT_140539fc0);
          fVar17 = (float)FUN_140334430(fVar23 - fVar25);
          if (fVar22 + fVar17 < 0.0) {
            fVar22 = (float)FUN_1403352f8();
          }
          else {
            fVar22 = SQRT(fVar22 + fVar17);
          }
          uVar35 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
          if ((DAT_14053acfc < fVar22) && (fVar23 < DAT_14053ae30)) {
            uVar33 = in_stack_ffffffffffffff18 & 0xffffffff00000000;
            auVar29._12_4_ = in_stack_ffffffffffffff08._12_4_;
            auVar29._0_8_ = in_stack_ffffffffffffff08._0_8_;
            auVar29._8_4_ = 1;
            auVar30._8_8_ = auVar29._8_8_;
            auVar30._0_8_ = CONCAT44(uVar24,uVar26);
            uVar12 = ((uint)(iVar11 + iVar14) >> 0x1e ^ iVar11 + iVar14) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar12 = uVar12 * 0x800 ^ uVar12;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
            FUN_14006c2f0(1,0,fVar1,fVar23,
                          CONCAT22(uVar27,uVar15 + (short)((ulonglong)DAT_140e9fd1c / 0x641) *
                                                   -0x641 + (short)DAT_140e9fd1c + -800),0,
                          CONCAT44(uVar24,uVar26),auVar30._8_8_,uVar33);
            uVar35 = (undefined4)(uVar33 >> 0x20);
            iVar11 = DAT_140e418c8;
            if (2 < DAT_140e419b8) {
              uVar33 = uVar33 & 0xffffffff00000000;
              auVar31._12_4_ = auVar30._12_4_;
              auVar31._0_8_ = auVar30._0_8_;
              auVar31._8_4_ = 1;
              uVar13 = ((uint)(DAT_140e418c8 + iVar14) >> 0x1e ^ DAT_140e418c8 + iVar14) *
                       0x6c078965 + 1;
              uVar12 = uVar13 * 0x800 ^ uVar13;
              DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
              DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
              DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
              DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
              FUN_14006c2f0(1,0,fVar1,fVar23,
                            *(short *)((longlong)param_1 + 0x42) +
                            (short)((ulonglong)DAT_140e9fd1c / 0x641) * -0x641 +
                            (short)DAT_140e9fd1c + -800,0,
                            (double)CONCAT44(uVar24,uVar26) + DAT_140539fe8,auVar31._8_8_,uVar33);
              uVar35 = (undefined4)(uVar33 >> 0x20);
              iVar11 = DAT_140e418c8;
            }
          }
        }
      }
      else {
        uVar15 = *(ushort *)((longlong)param_1 + 0x42);
        if ((iVar4 - 0x46U < 0x19a) && (iVar10 = (iVar4 + -0x46) % iVar10, iVar10 < 0x12))
        goto LAB_1400a48b9;
      }
      uVar15 = *(ushort *)((longlong)param_1 + 0x42);
      iVar10 = ((int)dVar20 & 0xffffU) - (uint)uVar15;
      iVar4 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar4 = iVar10;
      }
      iVar10 = iVar4 + -0x10000;
      if (iVar4 < 0x8001) {
        iVar10 = iVar4;
      }
      if (iVar10 < 1) {
        uVar7 = uVar15;
        if ((iVar10 < 0) && (uVar7 = uVar15 - 0x80, -0x80 < iVar10)) {
          uVar7 = uVar8;
        }
      }
      else {
        uVar7 = uVar8;
        if (0x7f < iVar10) {
          uVar7 = uVar15 + 0x80;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar7;
    }
  }
  uVar12 = 0;
  iVar14 = ((iVar11 - iVar14) + 0x2670) % 0x140;
  iVar4 = FUN_1400c9580(iVar14,0,5,2,0x52,0x53);
  if (iVar14 - 0x1eU < 5) {
LAB_1400a4bef:
    iVar4 = 0x57;
LAB_1400a4bf4:
    if ((iVar14 < 0x23) || (0x7c < iVar14)) goto LAB_1400a4c10;
    uVar12 = 0x59;
    uVar26 = 0x58;
LAB_1400a4c50:
    iVar4 = FUN_1400c9580(iVar14,0,5,2,uVar26,uVar12);
  }
  else {
    if (iVar14 < 0x7d) goto LAB_1400a4bf4;
    if (iVar14 < 0x82) goto LAB_1400a4bef;
LAB_1400a4c10:
    if (iVar14 - 0xbeU < 5) {
LAB_1400a4c2b:
      iVar4 = 0x54;
LAB_1400a4c30:
      if ((0xc2 < iVar14) && (iVar14 < 0x11d)) {
        uVar12 = 0x56;
        uVar26 = 0x55;
        goto LAB_1400a4c50;
      }
    }
    else {
      if (iVar14 < 0x11d) goto LAB_1400a4c30;
      if (iVar14 < 0x122) goto LAB_1400a4c2b;
    }
  }
  auVar32._4_4_ = uVar3;
  auVar32._0_4_ = uVar34;
  auVar32._8_4_ = uVar18;
  auVar32._12_4_ = uVar21;
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar4],0x17,7,param_1[10],param_1[0xb],uVar12,auVar32,
                CONCAT44(uVar35,0xff),0xff,0xff,0xff,1,0);
  uVar21 = DAT_140e41954;
  uVar28 = (undefined2)(uVar12 >> 0x10);
  fVar23 = (float)param_1[10] - DAT_140e45d24;
  uVar18 = param_1[0xb];
  puVar6 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar6 = (undefined8 *)_malloc_base(0x60);
    if (puVar6 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar6 + 0x14) = fVar23;
    *(undefined4 *)(puVar6 + 3) = uVar18;
    *(float *)((longlong)puVar6 + 0x1c) = fVar23;
    *(undefined4 *)(puVar6 + 4) = uVar18;
    *puVar6 = 1;
    *(undefined4 *)(puVar6 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar6 + 0xc) = uVar21;
    *(undefined4 *)(puVar6 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
    puVar6[5] = 0;
    puVar6[6] = 0x3ff0000000000000;
    puVar6[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar6 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
    *(undefined4 *)(puVar6 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
    puVar6[10] = 0xc0;
    puVar6[0xb] = 0;
    if (bVar16) {
      DAT_140e45d78 = puVar6;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar6;
    }
  }
  DAT_140e45d28 = puVar6;
  FUN_140079c10(param_1,2);
LAB_1400a4df9:
  iVar4 = DAT_140e418c8;
  if ((int)param_1[7] < 1) {
    uVar13 = param_1[1] + DAT_140e418c8;
    uVar12 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar12 = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    DAT_140e9fd1c = uVar12;
    uVar5 = FUN_140134db0(uVar13,(int)DAT_140539f38,DAT_140539f58);
    uVar18 = (undefined4)uVar5;
    uVar21 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar5 = FUN_140134db0(param_1[1] + iVar4);
    FUN_140070d00(0x38,DAT_140e41948,0x15,(float)param_1[10] - DAT_140e45d24,
                  (float)param_1[0xb] + DAT_14053ac58,
                  CONCAT22(uVar28,(short)uVar12 - (short)(uVar12 / 0x10001)),CONCAT44(uVar3,uVar34),
                  uVar5,CONCAT44(uVar21,uVar18),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,600,5);
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


