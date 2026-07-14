// Function: FUN_1400894a0 @ 1400894a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400894a0(undefined4 *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double dVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 extraout_var;
  undefined8 uVar11;
  undefined8 *puVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff38;
  undefined2 uVar26;
  uint in_stack_ffffffffffffff40;
  undefined1 in_stack_ffffffffffffff48 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  
  uVar26 = (undefined2)((uint)in_stack_ffffffffffffff38 >> 0x10);
  dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xd]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[0xc]),0));
  dVar21 = dVar21 * DAT_14053aba0;
  dVar22 = (double)FUN_140332d90(((double)DAT_140e418c8 - (double)(param_1[1] * 0x37)) *
                                 DAT_14053a5a0 * DAT_14053a020 * DAT_140539d28);
  dVar5 = DAT_140539e60;
  fVar25 = (float)(dVar22 * DAT_14053a460) + (float)param_1[0xc];
  uVar19 = 0;
  if (param_1[5] == 0) {
    FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    dVar22 = DAT_140539fc8 - (double)(int)param_1[3] * dVar5;
    in_stack_ffffffffffffff48._8_4_ = SUB84(dVar22,0);
    in_stack_ffffffffffffff48._0_8_ = dVar22;
    in_stack_ffffffffffffff48._12_4_ = (int)((ulonglong)dVar22 >> 0x20);
    in_stack_ffffffffffffff40 = in_stack_ffffffffffffff40 & 0xffff0000;
    uVar18 = extraout_var;
    FUN_1400c8410(DAT_140e41a50,0x32,8,fVar25,extraout_var,in_stack_ffffffffffffff40,
                  in_stack_ffffffffffffff48,0xff,0xff,0xff,0xff,1,0);
    uVar26 = (undefined2)((uint)uVar18 >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4000000000000000;
      *(undefined2 *)(param_1 + 0x10) = 0x4000;
      uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar11;
      uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140089d42;
  uVar16 = *(ushort *)(param_1 + 0x10);
  iVar4 = param_1[3];
  dVar22 = *(double *)(param_1 + 0x12);
  dVar23 = (double)FUN_1403307c0();
  dVar24 = (double)FUN_140332d90();
  if (iVar4 < 0xb4) {
    iVar9 = ((int)dVar21 & 0xffffU) - (uint)uVar16;
    param_1[10] = fVar25;
    iVar13 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar13 = iVar9;
    }
    iVar9 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar9 = iVar13;
    }
    fVar25 = (float)(dVar24 * dVar22) + (float)param_1[0xd];
    param_1[0xd] = fVar25;
    param_1[0xc] = (float)(dVar22 * dVar23) + (float)param_1[0xc];
    param_1[0xb] = fVar25;
    uVar15 = (ushort)(int)dVar21;
    if (iVar9 < 1) {
      uVar17 = uVar16;
      if ((iVar9 < 0) && (uVar17 = uVar15, iVar9 < -0x3f)) {
        uVar17 = uVar16 - 0x40;
      }
    }
    else {
      uVar17 = uVar15;
      if (0x3f < iVar9) {
        uVar17 = uVar16 + 0x40;
      }
    }
  }
  else {
    iVar9 = -(uint)uVar16 + 0xc000;
    iVar13 = -(uint)uVar16 + 0x1c000;
    if (-0x8001 < iVar9) {
      iVar13 = iVar9;
    }
    iVar9 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar9 = iVar13;
    }
    param_1[10] = (float)(dVar22 * dVar23) + (float)param_1[10];
    param_1[0xb] = (float)(dVar24 * dVar22) + (float)param_1[0xb];
    if (iVar9 < 1) {
      if (iVar9 < 0) {
        if (iVar9 < -0x9f) {
          uVar16 = uVar16 - 0xa0;
        }
        else {
          uVar16 = 0xc000;
        }
      }
    }
    else if (iVar9 < 0xa0) {
      uVar16 = 0xc000;
    }
    else {
      uVar16 = uVar16 + 0xa0;
    }
    *(double *)(param_1 + 0x12) = dVar22 + dVar5;
    uVar17 = uVar16;
  }
  iVar13 = DAT_140e419b8;
  *(ushort *)(param_1 + 0x10) = uVar17;
  uVar11 = _UNK_14053bb28;
  dVar5 = _DAT_14053bb20;
  iVar9 = 1;
  if (iVar13 == 0) {
    iVar9 = 0x18;
  }
  else if (iVar13 == 1) {
    iVar9 = 0x12;
  }
  else if (((iVar13 == 2) || (iVar13 == 3)) || (iVar13 == 4)) {
    iVar9 = 0xf;
  }
  iVar14 = 1;
  if (iVar13 == 0) {
    iVar14 = 0x78;
  }
  else if (iVar13 == 1) {
    iVar14 = 0x50;
  }
  else if (iVar13 == 2) {
    iVar14 = 0x46;
  }
  else if (iVar13 == 3) {
    iVar14 = 0x3c;
  }
  else if (iVar13 == 4) {
    iVar14 = 0x32;
  }
  dVar21 = DAT_14053a0f8;
  if (((iVar13 != 0) && (dVar21 = DAT_14053a138, iVar13 != 1)) &&
     ((dVar21 = DAT_14053a178, iVar13 != 2 &&
      ((dVar21 = DAT_14053a1a8, iVar13 != 3 && (dVar21 = _DAT_14053bb20, iVar13 == 4)))))) {
    dVar21 = DAT_14053a200;
  }
  if (iVar9 <= iVar4) {
    if ((iVar4 < 0xb4) && ((iVar4 - iVar9) % iVar14 == 0)) {
      dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                     SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
      iVar14 = (iVar4 - iVar9) % iVar14;
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar22 * DAT_14053aba0);
    }
    else if ((iVar4 < iVar9) ||
            ((0xb3 < iVar4 || (iVar14 = (iVar4 - iVar9) % iVar14, 0x1d < iVar14))))
    goto LAB_140089ac0;
    fVar6 = DAT_14053aca8;
    fVar25 = DAT_14053ac48;
    uVar10 = DAT_14053ac2c;
    if (iVar14 == (iVar14 / 5) * 5) {
      fVar2 = (float)param_1[10];
      fVar3 = (float)param_1[0xb];
      if ((((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar2) &&
           (fVar2 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= fVar3)) &&
         (fVar3 <= DAT_14053af14)) {
        auVar27._12_4_ = in_stack_ffffffffffffff48._12_4_;
        auVar27._0_8_ = in_stack_ffffffffffffff48._0_8_;
        auVar27._8_4_ = 1;
        auVar28._8_8_ = auVar27._8_8_;
        auVar28._0_8_ = dVar21;
        FUN_14006c2f0(7,0,fVar2 + DAT_14053ac48,fVar3 + DAT_14053aca8,
                      CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42)),DAT_14053ac2c,
                      dVar21,auVar28._8_8_,0);
        auVar29._12_4_ = auVar28._12_4_;
        auVar29._0_8_ = auVar28._0_8_;
        auVar29._8_4_ = 1;
        auVar30._8_8_ = auVar29._8_8_;
        auVar30._0_8_ = dVar21;
        in_stack_ffffffffffffff40 = uVar10;
        FUN_14006c2f0(7,0,(float)param_1[10] - fVar25,(float)param_1[0xb] + fVar6,
                      *(undefined2 *)((longlong)param_1 + 0x42),uVar10,dVar21,auVar30._8_8_,0);
        if (2 < DAT_140e419b8) {
          dVar21 = dVar21 - DAT_140539ec8;
          auVar31._12_4_ = auVar30._12_4_;
          auVar31._0_8_ = auVar30._0_8_;
          auVar31._8_4_ = 1;
          auVar32._8_8_ = auVar31._8_8_;
          auVar32._0_8_ = dVar21;
          FUN_14006c2f0(7,0,(float)param_1[10] + fVar25,(float)param_1[0xb] + fVar6,
                        *(short *)((longlong)param_1 + 0x42) + -400,uVar10,dVar21,auVar32._8_8_,0);
          auVar33._12_4_ = auVar32._12_4_;
          auVar33._0_8_ = auVar32._0_8_;
          auVar33._8_4_ = 1;
          FUN_14006c2f0(7,0,(float)param_1[10] - fVar25,(float)param_1[0xb] + fVar6,
                        *(short *)((longlong)param_1 + 0x42) + 400,uVar10,dVar21,auVar33._8_8_,0);
          in_stack_ffffffffffffff40 = uVar10;
        }
      }
    }
  }
LAB_140089ac0:
  uVar8 = _UNK_14053bac8;
  uVar7 = _DAT_14053bac0;
  uVar10 = param_1[3] & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  pfVar1 = (float *)(param_1 + 10);
  if ((int)uVar10 < 2) {
    uVar19 = 0xff;
  }
  uVar18 = 0x80;
  if ((int)uVar10 < 2) {
    uVar18 = 0xff;
  }
  in_stack_ffffffffffffff40 = in_stack_ffffffffffffff40 & 0xffff0000;
  FUN_1400c8410(DAT_140e41930,0x23,7,*pfVar1 + DAT_14053ac34,(float)param_1[0xb] - DAT_14053ac94,
                in_stack_ffffffffffffff40,_DAT_14053bac0,_UNK_14053bac8,0xff,uVar18,uVar19,0xc0,1,0)
  ;
  in_stack_ffffffffffffff40 = in_stack_ffffffffffffff40 & 0xffff0000;
  FUN_1400c8410(DAT_140e41930,0x23,7,*pfVar1 - DAT_14053ac34,(float)param_1[0xb] - DAT_14053ac94,
                in_stack_ffffffffffffff40,uVar7,uVar8,0xff,uVar18,uVar19,0xc0,1,0);
  FUN_1400c8410(DAT_140e446c0,0x23,7,*pfVar1,param_1[0xb],in_stack_ffffffffffffff40 & 0xffff0000,
                dVar5,uVar11,0xff,0xff,0xff,0xff,1,0);
  uVar19 = DAT_140e446c0;
  uVar10 = param_1[3] & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  puVar12 = DAT_140e45d28;
  if (uVar10 == 0) {
    uVar18 = param_1[0xb];
    fVar25 = *pfVar1;
    if (DAT_140e45d1c < 0x1000) {
      puVar12 = (undefined8 *)_malloc_base(0x60);
      if (puVar12 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar12 + 0x14) = fVar25;
      *(undefined4 *)(puVar12 + 3) = uVar18;
      *(float *)((longlong)puVar12 + 0x1c) = fVar25;
      *(undefined4 *)(puVar12 + 4) = uVar18;
      *puVar12 = 1;
      *(undefined4 *)(puVar12 + 1) = 5;
      *(undefined4 *)((longlong)puVar12 + 0xc) = uVar19;
      *(undefined4 *)(puVar12 + 2) = 0x22;
      *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
      puVar12[5] = 0;
      puVar12[6] = 0x3ff0000000000000;
      puVar12[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar12 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
      *(undefined4 *)(puVar12 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
      puVar12[10] = 0x40;
      puVar12[0xb] = 0;
      if (bVar20) {
        DAT_140e45d78 = puVar12;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar12;
      }
    }
  }
  DAT_140e45d28 = puVar12;
  FUN_140079c10(param_1,2);
LAB_140089d42:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,4);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


