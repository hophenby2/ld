// Function: FUN_1400a4fe0 @ 1400a4fe0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a4fe0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  double dVar3;
  double dVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  float fVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined4 local_res8;
  undefined4 uStackX_c;
  uint in_stack_ffffffffffffff00;
  undefined2 uVar24;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  ulonglong in_stack_ffffffffffffff18;
  undefined8 uVar29;
  ulonglong uVar30;
  
  uVar24 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar16 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
  iVar8 = 0;
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    in_stack_ffffffffffffff18 = CONCAT44(uVar16,0xff);
    local_res8 = (undefined4)uVar5;
    dVar19 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar19,0);
    in_stack_ffffffffffffff08._0_8_ = dVar19;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar19 >> 0x20);
    uVar12 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar12,in_stack_ffffffffffffff08,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,1,0);
    uVar24 = (undefined2)(uVar12 >> 0x10);
    if (param_1[3] == 0x14) {
      uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar5;
      uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  uVar5 = _UNK_14053bb28;
  dVar4 = _DAT_14053bb20;
  fVar15 = DAT_14053ab70;
  dVar3 = DAT_14053a020;
  dVar19 = DAT_140539d28;
  uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
  uVar16 = SUB84(_DAT_14053bb20,0);
  if (param_1[5] != 1) goto LAB_1400a5bf5;
  iVar7 = param_1[3];
  fVar21 = (float)param_1[0xd];
  fVar23 = (float)param_1[0xb] + DAT_14053ac58;
  fVar22 = (float)param_1[10];
  iVar10 = (int)fVar21;
  param_1[10] = DAT_140e45d24 + (float)param_1[0xc];
  iVar11 = iVar10;
  if ((iVar7 < 0) || (iVar11 = iVar10 + -800, 0x77 < iVar7)) {
    if (iVar7 < 300) goto LAB_1400a52a4;
    if (iVar7 < 0x1e0) {
      dVar17 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a4a0) * DAT_14053a438 * dVar3 *
                                     dVar19);
      dVar17 = dVar17 * DAT_14053a888;
      param_1[0xd] = fVar21 + DAT_140539d20;
      param_1[0xb] = (float)(iVar10 - (int)dVar17);
      goto LAB_1400a52c4;
    }
    fVar21 = fVar21 + DAT_140539d20;
    param_1[0xb] = (float)iVar10;
    param_1[0xd] = (float)(iVar7 + -0x1e0) * DAT_140539cd8 + fVar21;
  }
  else {
    dVar17 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a4d8 * dVar3 * dVar19);
    iVar11 = iVar10 - (int)(dVar17 * DAT_14053a888);
LAB_1400a52a4:
    uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
    fVar21 = fVar21 + DAT_140539d20;
    param_1[0xb] = (float)iVar11;
    param_1[0xd] = fVar21;
    if (iVar7 - 0x3cU < 0x1a4) {
LAB_1400a52c4:
      fVar21 = DAT_140e445d8;
      uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
      if ((((DAT_140e445d8 / fVar15 + DAT_14053aca8 <= fVar22) &&
           (fVar22 <= DAT_140e445d8 / fVar15 + DAT_14053aea8)) && (DAT_14053aca8 <= fVar23)) &&
         (fVar23 <= DAT_14053aef4)) {
        dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),
                                       SUB84((double)(DAT_140e445d8 - fVar22),0));
        iVar11 = DAT_140e419b8;
        uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
        iVar7 = 1;
        dVar17 = dVar17 * DAT_14053aba0;
        if (DAT_140e419b8 == 0) {
          iVar7 = 2;
          dVar18 = DAT_14053a070;
        }
        else {
          dVar18 = DAT_14053a0d0;
          if (((DAT_140e419b8 != 1) && (dVar18 = DAT_14053a118, DAT_140e419b8 != 2)) &&
             ((DAT_140e419b8 != 3 && (dVar18 = dVar4, DAT_140e419b8 == 4)))) {
            dVar18 = DAT_14053a160;
          }
        }
        if ((-1 < DAT_140e418c8) && (DAT_140e418c8 % (iVar7 * 0x29) == 0)) {
          fVar15 = (float)FUN_140334430(fVar22 - fVar21,DAT_140539fc0);
          fVar21 = (float)FUN_140334430(fVar23 - DAT_140e445dc);
          if (fVar15 + fVar21 < 0.0) {
            fVar15 = (float)FUN_1403352f8();
          }
          else {
            fVar15 = SQRT(fVar15 + fVar21);
          }
          uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
          if ((DAT_14053acfc < fVar15) && (fVar23 < DAT_14053ae30)) {
            sVar9 = (short)(int)dVar17;
            iVar7 = iVar8;
            if (iVar11 < 1) {
LAB_1400a54a1:
              iVar7 = iVar8;
              do {
                in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffff00000000;
                auVar26._12_4_ = in_stack_ffffffffffffff08._12_4_;
                auVar26._0_8_ = in_stack_ffffffffffffff08._0_8_;
                auVar26._8_4_ = 1;
                in_stack_ffffffffffffff08._8_8_ = auVar26._8_8_;
                in_stack_ffffffffffffff08._0_8_ = dVar18 + dVar4;
                FUN_14006c2f0(5,0,fVar22,fVar23,(short)iVar7 * 2000 + sVar9 + -1000,0,dVar18 + dVar4
                              ,in_stack_ffffffffffffff08._8_8_,in_stack_ffffffffffffff18);
                iVar7 = iVar7 + 1;
              } while (iVar7 < 2);
            }
            else {
              do {
                in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffff00000000;
                auVar25._12_4_ = in_stack_ffffffffffffff08._12_4_;
                auVar25._0_8_ = in_stack_ffffffffffffff08._0_8_;
                auVar25._8_4_ = 1;
                in_stack_ffffffffffffff08._8_8_ = auVar25._8_8_;
                in_stack_ffffffffffffff08._0_8_ = dVar18;
                FUN_14006c2f0(5,0,fVar22,fVar23,(short)iVar7 * 2000 + sVar9 + -2000,0,dVar18,
                              in_stack_ffffffffffffff08._8_8_,in_stack_ffffffffffffff18);
                iVar7 = iVar7 + 1;
              } while (iVar7 < 3);
              if (DAT_140e419b8 != 1) goto LAB_1400a54a1;
            }
            uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
            iVar7 = iVar8;
            if (2 < DAT_140e419b8) {
              do {
                in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffff00000000;
                auVar27._12_4_ = in_stack_ffffffffffffff08._12_4_;
                auVar27._0_8_ = in_stack_ffffffffffffff08._0_8_;
                auVar27._8_4_ = 1;
                in_stack_ffffffffffffff08._8_8_ = auVar27._8_8_;
                in_stack_ffffffffffffff08._0_8_ = dVar18;
                FUN_14006c2f0(5,0,fVar22,fVar23,(short)iVar7 * 8000 + sVar9 + -4000,0,dVar18,
                              in_stack_ffffffffffffff08._8_8_,in_stack_ffffffffffffff18);
                iVar7 = iVar7 + 1;
              } while (iVar7 < 2);
              do {
                in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffff00000000;
                auVar28._12_4_ = in_stack_ffffffffffffff08._12_4_;
                auVar28._0_8_ = in_stack_ffffffffffffff08._0_8_;
                auVar28._8_4_ = 1;
                in_stack_ffffffffffffff08._8_8_ = auVar28._8_8_;
                in_stack_ffffffffffffff08._0_8_ = dVar18 + dVar4;
                FUN_14006c2f0(5,0,fVar22,fVar23,(short)iVar8 * 6000 + sVar9 + -3000,0,dVar18 + dVar4
                              ,in_stack_ffffffffffffff08._8_8_,in_stack_ffffffffffffff18);
                uVar20 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
          }
        }
      }
    }
  }
  iVar8 = param_1[3];
  dVar17 = (double)FUN_140332d90(((double)iVar8 - 0.0) * DAT_14053abc0 * dVar3 * dVar19);
  fVar15 = (float)(dVar17 * DAT_140539f90) + 0.0;
  dVar18 = (double)FUN_140332d90();
  dVar18 = dVar18 * DAT_140539f90;
  dVar17 = dVar4;
  if (DAT_140e418c8 % 0x29 < 9) {
    dVar19 = (double)FUN_140332d90(((double)(DAT_140e418c8 % 0x29) - 0.0) * DAT_14053aad0 * dVar3 *
                                   dVar19);
    dVar17 = dVar19 * DAT_140539e60 + dVar4;
  }
  uVar12 = 0;
  iVar8 = FUN_1400c9580(iVar8,0,5,2,0x5c,0x5d);
  fVar21 = DAT_14053ac78;
  uVar29 = CONCAT44(uVar20,0xff);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar8],0x19,7,param_1[10],(float)param_1[0xb] + DAT_14053ac78,
                uVar12,dVar4,uVar5,uVar29,0xff,0xff,0xff,1,0);
  uVar29 = CONCAT44((int)((ulonglong)uVar29 >> 0x20),0xff);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410(DAT_140e447c8,0x19,7,param_1[10],(float)param_1[0xb] + DAT_14053ac4c + fVar15,uVar12
                ,dVar4,uVar5,uVar29,0xff,0xff,0xff,1,0);
  uVar30 = CONCAT44((int)((ulonglong)uVar29 >> 0x20),0xff);
  auVar2._8_4_ = SUB84(dVar17,0);
  auVar2._0_8_ = dVar17;
  auVar2._12_4_ = (int)((ulonglong)dVar17 >> 0x20);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410(DAT_140e447cc,0x1a,7,param_1[10],(float)dVar18 + 0.0 + (float)param_1[0xb],uVar12,
                auVar2,uVar30,0xff,0xff,0xff,1,0);
  uVar12 = uVar12 & 0xffff0000;
  FUN_1400c8410(DAT_140e447c8,0x17,7,param_1[10],(float)param_1[0xb] + DAT_14053ac60 + fVar15,uVar12
                ,dVar4,uVar5,uVar30 & 0xffffffff00000000,0,0x20,0x40,1,0);
  uVar20 = DAT_140e41958;
  fVar15 = DAT_14053acd4;
  uVar24 = (undefined2)(uVar12 >> 0x10);
  fVar23 = (float)param_1[0xb] + DAT_14053acd4;
  fVar22 = ((float)param_1[10] + fVar21) - DAT_140e45d24;
  iVar8 = DAT_140e45d1c;
  puVar6 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar6 = (undefined8 *)_malloc_base(0x60);
    if (puVar6 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar8 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar6 + 0x14) = fVar22;
    bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar6 + 3) = fVar23;
    *(float *)((longlong)puVar6 + 0x1c) = fVar22;
    *(float *)(puVar6 + 4) = fVar23;
    *puVar6 = 1;
    *(undefined4 *)(puVar6 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar6 + 0xc) = uVar20;
    *(undefined4 *)(puVar6 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
    puVar6[5] = 0;
    puVar6[6] = 0x3ff0000000000000;
    puVar6[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar6 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
    *(undefined4 *)(puVar6 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
    puVar6[10] = 0x80;
    puVar6[0xb] = 0;
    if (bVar14) {
      DAT_140e45d78 = puVar6;
    }
    DAT_140e45d1c = iVar8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar6;
    }
  }
  DAT_140e45d28 = puVar6;
  uVar20 = DAT_140e41958;
  fVar22 = (float)param_1[0xb];
  fVar21 = ((float)param_1[10] - fVar21) - DAT_140e45d24;
  puVar6 = DAT_140e45d28;
  if (iVar8 < 0x1000) {
    puVar6 = (undefined8 *)_malloc_base(0x60);
    if (puVar6 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar8 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar6 + 0x14) = fVar21;
    bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar6 + 3) = fVar22 + fVar15;
    *(float *)((longlong)puVar6 + 0x1c) = fVar21;
    *(float *)(puVar6 + 4) = fVar22 + fVar15;
    *puVar6 = 1;
    *(undefined4 *)(puVar6 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar6 + 0xc) = uVar20;
    *(undefined4 *)(puVar6 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
    puVar6[5] = 0;
    puVar6[6] = 0x3ff0000000000000;
    puVar6[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar6 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
    *(undefined4 *)(puVar6 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
    puVar6[10] = 0x80;
    puVar6[0xb] = 0;
    if (bVar14) {
      DAT_140e45d78 = puVar6;
    }
    DAT_140e45d1c = iVar8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar6;
    }
  }
  DAT_140e45d28 = puVar6;
  uVar20 = DAT_140e41a50;
  puVar6 = DAT_140e45d28;
  if ((DAT_140e418c8 == (DAT_140e418c8 / 0x29) * 0x29) && (uVar1 = param_1[1], iVar8 < 0x1000)) {
    puVar6 = (undefined8 *)_malloc_base(0x60);
    if (puVar6 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar6 = 1;
    *(undefined4 *)(puVar6 + 1) = 0x25;
    *(undefined4 *)((longlong)puVar6 + 0xc) = uVar20;
    puVar6[2] = 0x1e;
    puVar6[3] = 0x41a00000;
    *(undefined4 *)(puVar6 + 4) = 0x41a00000;
    *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
    puVar6[5] = 0;
    puVar6[6] = 0x3ff0000000000000;
    puVar6[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar6 + 8) = 0x10;
    *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
    *(undefined4 *)(puVar6 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
    *(undefined4 *)(puVar6 + 10) = 0x80;
    *(undefined4 *)((longlong)puVar6 + 0x54) = uVar1;
    puVar6[0xb] = 0;
    if (bVar14) {
      DAT_140e45d78 = puVar6;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar6;
    }
  }
  DAT_140e45d28 = puVar6;
  FUN_140079c10(param_1,2);
LAB_1400a5bf5:
  fVar15 = DAT_14053ab70;
  if ((int)param_1[7] < 1) {
    uVar13 = param_1[1] + DAT_140e418c8;
    uVar12 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar12 = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    fVar21 = DAT_14053ac58;
    DAT_140e9fd1c = uVar12;
    uVar5 = FUN_140134db0(uVar13,uVar16,DAT_140539f68);
    uVar16 = (undefined4)uVar5;
    uVar20 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar5 = FUN_140134db0(param_1[1] + DAT_140e418c8);
    FUN_140070d00(0x38,DAT_140e41948,0x15,(float)param_1[10] - DAT_140e45d24,
                  (float)param_1[0xb] + fVar21,
                  CONCAT22(uVar24,(short)uVar12 - (short)(uVar12 / 0x10001)),dVar4,uVar5,
                  CONCAT44(uVar20,uVar16),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,600,10);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / fVar15 - DAT_14053ae14) ||
       (DAT_140e445d8 / fVar15 + DAT_14053af80 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3f8)) || (DAT_14053afbc < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


