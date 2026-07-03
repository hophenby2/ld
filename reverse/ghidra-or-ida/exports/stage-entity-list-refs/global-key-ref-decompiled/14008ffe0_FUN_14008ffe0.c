// Function: FUN_14008ffe0 @ 14008ffe0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008ffe0(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  int iVar16;
  undefined4 uVar17;
  bool bVar18;
  float fVar19;
  float fVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  double dVar27;
  double dVar28;
  float fVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  float fVar32;
  undefined4 uVar33;
  float fVar34;
  float fVar35;
  undefined4 uVar36;
  int local_res10;
  uint in_stack_fffffffffffffe78;
  undefined2 uVar37;
  undefined8 local_148;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  
  local_148 = 0;
  local_148._0_4_ = 0;
  uStack_130 = 0;
  uStack_130._4_4_ = 0;
  puVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == param_1[2]) {
        local_148 = *puVar4;
        uStack_130 = puVar4[3];
        local_128 = puVar4[4];
        uStack_120 = puVar4[5];
      }
    }
  }
  fVar34 = (float)param_1[0xb];
  fVar35 = (float)param_1[10];
  fVar29 = uStack_120._4_4_ + (float)param_1[0xd];
  fVar32 = (float)uStack_120 + (float)param_1[0xc];
  FUN_1403300b4((double)(fVar29 - fVar34),SUB84((double)(fVar32 - fVar35),0));
  fVar19 = (float)FUN_140334430(fVar34 - fVar29,DAT_140539fc0);
  fVar20 = (float)FUN_140334430(fVar35 - fVar32);
  if (fVar19 + fVar20 < 0.0) {
    fVar19 = (float)FUN_1403352f8();
  }
  else {
    fVar19 = SQRT(fVar19 + fVar20);
  }
  dVar27 = (double)fVar19 / DAT_14053a138;
  dVar21 = (double)FUN_1403307c0();
  fVar35 = (float)(dVar21 * dVar27) + fVar35;
  param_1[10] = fVar35;
  dVar21 = (double)FUN_140332d90();
  fVar34 = (float)(dVar21 * dVar27) + fVar34;
  param_1[0xb] = fVar34;
  if (param_1[5] == 0) {
    if (param_1[3] == 0) {
      param_1[10] = fVar32;
      param_1[0xb] = fVar29;
      goto LAB_1400907a2;
    }
    if (param_1[3] != 0x78) goto LAB_1400907a2;
    param_1[8] = (undefined4)local_128;
    param_1[7] = uStack_130._4_4_;
    param_1[0x15] = 0;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_1400907a2;
  iVar16 = param_1[3];
  if (iVar16 < 0x514) {
    fVar34 = fVar34 + DAT_14053ad10;
    dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                   SUB84((double)(DAT_140e445d8 - fVar35),0));
    dVar7 = DAT_14053a178;
    dVar6 = DAT_14053a118;
    dVar24 = DAT_14053a0b0;
    dVar27 = DAT_140539f40;
    dVar21 = DAT_140539e70;
    uVar37 = (undefined2)(in_stack_fffffffffffffe78 >> 0x10);
    dVar22 = dVar22 * DAT_14053aba0;
    iVar14 = 10;
    uVar36 = SUB84(DAT_140539f40,0);
    uVar2 = (ulonglong)DAT_140539f40 >> 0x20;
    uVar15 = (ushort)(int)dVar22;
    dVar23 = DAT_14053a040;
    dVar28 = DAT_14053a0f8;
    iVar13 = DAT_140e419b8;
    if ((9 < iVar16) && (iVar16 < 500)) {
      uVar17 = 1;
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          uVar17 = 3;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          uVar17 = 5;
        }
      }
      uVar33 = SUB84(DAT_14053a118,0);
      uVar5 = (ulonglong)DAT_14053a118 >> 0x20;
      uVar30 = SUB84(DAT_14053a0b0,0);
      uVar31 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      iVar16 = 0;
      local_res10 = 0;
      do {
        if (iVar13 == 0) {
          uVar25 = SUB84(dVar23,0);
          uVar26 = (int)((ulonglong)dVar23 >> 0x20);
        }
        else if (iVar13 == 1) {
          uVar25 = SUB84(DAT_14053a088,0);
          uVar26 = (int)((ulonglong)DAT_14053a088 >> 0x20);
        }
        else {
          uVar25 = uVar30;
          uVar26 = uVar31;
          if (((iVar13 != 2) && (iVar13 != 3)) &&
             (uVar25 = uVar36, uVar26 = (int)uVar2, iVar13 == 4)) {
            uVar25 = uVar33;
            uVar26 = (int)uVar5;
          }
        }
        iVar9 = param_1[3];
        dVar3 = (double)CONCAT44(uVar26,uVar25);
        if (((7 < DAT_1407c7798) && (dVar3 = dVar24, iVar13 != 0)) &&
           ((dVar3 = dVar28, iVar13 != 1 &&
            (((dVar3 = dVar6, iVar13 != 2 && (iVar13 != 3)) && (dVar3 = dVar27, iVar13 == 4)))))) {
          dVar3 = dVar7;
        }
        if (iVar9 == iVar14) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar15;
          iVar8 = iVar16 + 0x14 + iVar14;
LAB_1400903d8:
          if ((iVar9 < iVar8) || (iVar8 == 0)) {
            uVar11 = iVar9 - iVar14 & 0x80000003;
            if ((int)uVar11 < 0) {
              uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
            }
            if (uVar11 == 0) {
              in_stack_fffffffffffffe78 =
                   CONCAT22((short)(in_stack_fffffffffffffe78 >> 0x10),
                            *(undefined2 *)((longlong)param_1 + 0x42));
              FUN_1400709b0(0xd,0,param_1 + 3,fVar34,in_stack_fffffffffffffe78,0,
                            ((double)iVar9 - (double)iVar14) * dVar21 + dVar3,1,uVar17,27000,0);
              if (2 < DAT_140e419b8) {
                iVar13 = 0;
                do {
                  in_stack_fffffffffffffe78 = in_stack_fffffffffffffe78 & 0xffff0000;
                  FUN_14006c2f0(0xd,0);
                  iVar13 = iVar13 + 1;
                } while (iVar13 < 2);
              }
              iVar13 = DAT_140e419b8;
              dVar28 = DAT_14053a0f8;
              dVar23 = DAT_14053a040;
              uVar1 = *(ushort *)((longlong)param_1 + 0x42);
              iVar8 = ((int)dVar22 & 0xffffU) - (uint)uVar1;
              iVar9 = iVar8 + 0x10000;
              if (-0x8001 < iVar8) {
                iVar9 = iVar8;
              }
              iVar8 = iVar9 + -0x10000;
              if (iVar9 < 0x8001) {
                iVar8 = iVar9;
              }
              if (iVar8 < 1) {
                uVar12 = uVar1;
                if ((iVar8 < 0) && (uVar12 = uVar1 - 400, -400 < iVar8)) {
                  uVar12 = uVar15;
                }
              }
              else {
                uVar12 = uVar15;
                if (399 < iVar8) {
                  uVar12 = uVar1 + 400;
                }
              }
              *(ushort *)((longlong)param_1 + 0x42) = uVar12;
            }
          }
        }
        else {
          iVar8 = iVar14 + 0x14 + iVar16;
          if (iVar14 <= iVar9) goto LAB_1400903d8;
        }
        uVar37 = (undefined2)(in_stack_fffffffffffffe78 >> 0x10);
        iVar14 = iVar14 + 0x30 + local_res10;
        iVar16 = iVar16 + 0xc;
        local_res10 = local_res10 + 8;
      } while (iVar16 < 0x60);
    }
    if ((7 < DAT_1407c7798) && (iVar16 = param_1[3], 599 < iVar16)) {
      uVar36 = 1;
      if (iVar13 == 0) {
        uVar36 = 7;
      }
      else if (iVar13 == 1) {
        uVar36 = 9;
      }
      else if ((iVar13 == 2) || (iVar13 == 3)) {
        uVar36 = 0xb;
      }
      else if (iVar13 == 4) {
        uVar36 = 0xd;
      }
      iVar9 = 1;
      if (iVar13 == 0) {
        iVar9 = 0x78;
      }
      else if (iVar13 == 1) {
        iVar9 = 0x50;
      }
      else if ((iVar13 == 2) || (iVar13 == 3)) {
        iVar9 = 0x3c;
      }
      else if (iVar13 == 4) {
        iVar9 = 0x32;
      }
      if ((((iVar13 != 0) && (dVar23 = DAT_14053a070, iVar13 != 1)) &&
          (dVar23 = DAT_14053a088, iVar13 != 2)) &&
         ((iVar13 != 3 && (dVar23 = dVar27, iVar13 == 4)))) {
        dVar23 = dVar28;
      }
      if (((iVar14 <= iVar16) && (iVar16 < 0x514)) &&
         ((uVar2 = (longlong)(iVar16 - iVar14) % (longlong)iVar9, (int)uVar2 == 0 &&
          (FUN_1400709b0(4,uVar2 & 0xffffffff,iVar9,fVar34,CONCAT22(uVar37,uVar15),0,
                         ((double)iVar16 - DAT_14053a7c8) * _DAT_140539d98 + dVar23,1,uVar36,30000,0
                        ), 2 < DAT_140e419b8)))) {
        FUN_1400709b0(4,0);
      }
    }
  }
  iVar16 = param_1[7];
  if (iVar16 < uStack_130._4_4_) {
    iVar13 = param_1[2];
    puVar4 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
        if (*(int *)((longlong)puVar4 + 4) == iVar13) {
          *(int *)((longlong)puVar4 + 0x1c) =
               *(int *)((longlong)puVar4 + 0x1c) - (uStack_130._4_4_ - iVar16);
        }
      }
    }
  }
  iVar16 = param_1[7];
  if (uStack_130._4_4_ < iVar16) {
    param_1[7] = uStack_130._4_4_;
    iVar16 = uStack_130._4_4_;
  }
  if ((iVar16 < 1) && (iVar16 = param_1[2], puVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
      if (*(int *)((longlong)puVar4 + 4) == iVar16) {
        *(int *)((longlong)puVar4 + 0x1c) = *(int *)((longlong)puVar4 + 0x1c) - uStack_130._4_4_;
      }
    }
  }
LAB_1400907a2:
  uStack_120._4_4_ = uStack_120._4_4_ + DAT_14053ad70;
  fVar34 = (float)param_1[0xb];
  fVar35 = (float)param_1[10];
  dVar27 = (double)FUN_1403300b4((double)(fVar34 - uStack_120._4_4_),
                                 SUB84((double)(fVar35 - (float)uStack_120),0));
  dVar21 = DAT_14053aba0;
  uVar36 = DAT_140539fc0;
  dVar27 = dVar27 * DAT_14053aba0;
  fVar34 = (float)FUN_140334430(uStack_120._4_4_ - fVar34,DAT_140539fc0);
  fVar35 = (float)FUN_140334430((float)uStack_120 - fVar35);
  if (fVar34 + fVar35 < 0.0) {
    fVar34 = (float)FUN_1403352f8();
  }
  else {
    fVar34 = SQRT(fVar34 + fVar35);
  }
  fVar35 = DAT_140539d20;
  dVar28 = (double)(fVar34 * DAT_140539d20 * 0.0);
  dVar23 = (double)FUN_1403307c0();
  dVar24 = (double)FUN_140332d90();
  uVar17 = DAT_140e44bc4;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  puVar10[3] = (float)(dVar23 * dVar28) + (float)uStack_120;
  puVar10[4] = (float)(dVar24 * dVar28) + uStack_120._4_4_;
  *puVar10 = uVar17;
  *(short *)(puVar10 + 5) = (short)(int)dVar27 + -0x4000;
  puVar10[1] = 0x21;
  puVar10[2] = 7;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  DAT_140e46d14 = DAT_140e46d14 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar10;
  }
  fVar34 = (float)param_1[0xb];
  fVar19 = (float)param_1[10];
  DAT_140e46c88 = puVar10;
  dVar27 = (double)FUN_1403300b4((double)(fVar34 - uStack_120._4_4_),
                                 SUB84((double)(fVar19 - (float)uStack_120),0));
  fVar34 = (float)FUN_140334430(uStack_120._4_4_ - fVar34,uVar36);
  fVar19 = (float)FUN_140334430((float)uStack_120 - fVar19);
  if (fVar34 + fVar19 < 0.0) {
    fVar34 = (float)FUN_1403352f8();
  }
  else {
    fVar34 = SQRT(fVar34 + fVar19);
  }
  dVar23 = (double)FUN_1403307c0();
  dVar24 = (double)FUN_140332d90();
  uVar36 = DAT_140e44bc4;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar10 = uVar36;
  puVar10[1] = 0x21;
  puVar10[2] = 7;
  puVar10[3] = (float)(dVar23 * (double)(fVar34 * fVar35)) + (float)uStack_120;
  puVar10[4] = (float)(dVar24 * (double)(fVar34 * fVar35)) + uStack_120._4_4_;
  *(short *)(puVar10 + 5) = (short)(int)(dVar27 * dVar21) + -0x4000;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  DAT_140e46d14 = DAT_140e46d14 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  uVar30 = DAT_140e44bc0;
  uVar36 = param_1[0xb];
  uVar17 = param_1[10];
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46d18 = _DAT_140e46d18 + 1;
  bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar10[3] = uVar17;
  puVar10[4] = uVar36;
  *puVar10 = uVar30;
  puVar10[1] = 0x22;
  puVar10[2] = 7;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar18) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  DAT_140e46c88 = puVar10;
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if (((int)param_1[7] < 1) || (uStack_130._4_4_ < 1)) {
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 1;
  }
  if ((int)local_148 == 0) {
    *param_1 = 0;
  }
  return;
}


