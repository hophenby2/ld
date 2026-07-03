// Function: FUN_14009d610 @ 14009d610
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009d610(undefined4 *param_1)

{
  ushort *puVar1;
  ulonglong uVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  ushort uVar13;
  short sVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  float fVar26;
  float fVar27;
  undefined4 local_res8;
  undefined4 uStackX_c;
  float local_res10;
  float fStackX_14;
  undefined4 in_stack_fffffffffffffed8;
  undefined2 uVar29;
  float fVar28;
  undefined4 in_stack_fffffffffffffee0;
  undefined1 in_stack_fffffffffffffee8 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  
  uVar29 = (undefined2)((uint)in_stack_fffffffffffffed8 >> 0x10);
  uVar15 = (ushort)((uint)in_stack_fffffffffffffee0 >> 0x10);
  fVar22 = (float)param_1[0xb];
  fVar26 = (float)param_1[10];
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar22),
                                 SUB84((double)(DAT_140e445d8 - fVar26),0));
  uVar16 = (uint)(dVar19 * DAT_14053aba0);
  dVar19 = DAT_14053aba0;
  if (param_1[5] == 0) {
    iVar6 = param_1[3];
    if (iVar6 == 0) {
      if (param_1[6] == 0x57) {
        *(undefined2 *)(param_1 + 0x10) = 0x58f0;
      }
      else if (param_1[6] == 0x58) {
        *(undefined2 *)(param_1 + 0x10) = 10000;
      }
    }
    dVar19 = (double)((float)((uint)fVar22 ^ DAT_14053bf00) * DAT_140539d58);
    dVar20 = (double)FUN_1403307c0();
    dVar21 = (double)FUN_140332d90();
    uVar7 = FUN_1401346a0(CONCAT44((float)(dVar21 * dVar19) + fVar22,
                                   (float)(dVar20 * dVar19) + fVar26),0xffffffce);
    local_res10 = (float)uVar7;
    dVar19 = DAT_14053a018 - (double)iVar6 * DAT_140539e98;
    fStackX_14 = (float)((ulonglong)uVar7 >> 0x20);
    in_stack_fffffffffffffee8._8_4_ = SUB84(dVar19,0);
    in_stack_fffffffffffffee8._0_8_ = dVar19;
    in_stack_fffffffffffffee8._12_4_ = (int)((ulonglong)dVar19 >> 0x20);
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res10,fStackX_14,(uint)uVar15 << 0x10,
                  in_stack_fffffffffffffee8,0xff,0xff,0xff,0xff,1,0);
    dVar19 = DAT_14053aba0;
    uVar29 = (undefined2)((uint)fStackX_14 >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4022000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  fVar22 = DAT_14053ab70;
  if (param_1[5] != 1) goto LAB_14009e2f8;
  uVar17 = param_1[3];
  uVar15 = (ushort)uVar16;
  if ((int)uVar17 < 100) {
    dVar20 = *(double *)(param_1 + 0x12);
    if ((uVar17 < 0x65) && (0.0 < dVar20)) {
      dVar20 = dVar20 - _DAT_140539e58;
    }
    uVar12 = *(ushort *)(param_1 + 0x10);
    iVar10 = (uVar16 & 0xffff) - (uint)uVar12;
    *(double *)(param_1 + 0x12) = dVar20;
    iVar6 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar6 = iVar10;
    }
    iVar10 = iVar6 + -0x10000;
    if (iVar6 < 0x8001) {
      iVar10 = iVar6;
    }
    if (iVar10 < 1) {
      if ((iVar10 < 0) && (uVar12 = uVar12 - 0x20, -0x20 < iVar10)) {
        uVar12 = uVar15;
      }
      *(ushort *)(param_1 + 0x10) = uVar12;
    }
    else if (iVar10 < 0x20) {
      *(ushort *)(param_1 + 0x10) = uVar15;
    }
    else {
      *(ushort *)(param_1 + 0x10) = uVar12 + 0x20;
    }
  }
  else {
    if ((int)uVar17 < 0xf0) {
      puVar1 = (ushort *)(param_1 + 0x10);
      if (uVar17 == 100) {
        *puVar1 = uVar15;
LAB_14009d8da:
        *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + _DAT_140539e28;
      }
      else if ((int)uVar17 < 0x82) goto LAB_14009d8da;
      uVar12 = *puVar1;
      iVar10 = (uVar16 & 0xffff) - (uint)uVar12;
      iVar6 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar6 = iVar10;
      }
      iVar10 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar10 = iVar6;
      }
      if (iVar10 < 1) {
        uVar13 = uVar12;
        if ((iVar10 < 0) && (uVar13 = uVar12 - 0x80, -0x80 < iVar10)) {
          uVar13 = uVar15;
        }
      }
      else {
        uVar13 = uVar15;
        if (0x7f < iVar10) {
          uVar13 = uVar12 + 0x80;
        }
      }
      *puVar1 = uVar13;
      if ((int)uVar17 < 0xf0) goto LAB_14009d95c;
    }
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) - DAT_140539e60;
  }
LAB_14009d95c:
  dVar20 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar27;
  dVar20 = (double)FUN_140332d90();
  fVar26 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar26;
  if ((int)uVar17 < 0xf0) {
    fVar26 = fVar26 + DAT_14053ac80;
    dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                   SUB84((double)(DAT_140e445d8 - fVar27),0));
    fVar5 = DAT_14053af14;
    fVar4 = DAT_14053aec0;
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 0x2f;
    }
    else if (DAT_140e419b8 == 1) {
      iVar6 = 0x13;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar6 = 0xf;
    }
    else if (DAT_140e419b8 == 4) {
      iVar6 = 10;
    }
    iVar10 = 1;
    if (DAT_140e419b8 == 0) {
      iVar10 = 3;
    }
    else if (DAT_140e419b8 == 1) {
      iVar10 = 5;
    }
    else if (DAT_140e419b8 == 2) {
      iVar10 = 7;
    }
    else if (DAT_140e419b8 == 3) {
      iVar10 = 9;
    }
    else if (DAT_140e419b8 == 4) {
      iVar10 = 0xd;
    }
    uVar23 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    if (DAT_140e419b8 == 0) {
      uVar24 = (int)DAT_14053a0b8;
      uVar25 = (int)((ulonglong)DAT_14053a0b8 >> 0x20);
    }
    else {
      uVar24 = SUB84(DAT_14053a0f8,0);
      uVar25 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
      if ((((DAT_140e419b8 != 1) &&
           (uVar24 = SUB84(DAT_14053a118,0), uVar25 = uVar23, DAT_140e419b8 != 2)) &&
          (DAT_140e419b8 != 3)) &&
         (uVar24 = SUB84(DAT_140539f40,0), uVar25 = (int)((ulonglong)DAT_140539f40 >> 0x20),
         DAT_140e419b8 == 4)) {
        uVar24 = (int)DAT_14053a158;
        uVar25 = (int)((ulonglong)DAT_14053a158 >> 0x20);
      }
    }
    dVar21 = DAT_14053a048;
    if (((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a088, DAT_140e419b8 != 1)) &&
       ((dVar21 = DAT_14053a0b0, DAT_140e419b8 != 2 &&
        ((DAT_140e419b8 != 3 && (dVar21 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
      dVar21 = DAT_14053a0f8;
    }
    if (7 < DAT_1407c7798) {
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0x18;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0xe;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar6 = 10;
      }
      else if (DAT_140e419b8 == 4) {
        iVar6 = 8;
      }
      dVar21 = DAT_14053a0d0;
      if ((((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a118, DAT_140e419b8 != 1)) &&
          (dVar21 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar21 = DAT_140539f40, DAT_140e419b8 == 4)))) {
        dVar21 = DAT_14053a178;
      }
    }
    if (((param_1[3] - 0x28 < 200) &&
        (iVar11 = param_1[3] + -0x28, iVar11 == (iVar11 / 0xa0) * 0xa0)) &&
       ((fVar22 = DAT_140e445d8 / fVar22, fVar22 + 0.0 <= fVar27 &&
        (((fVar27 <= fVar22 + DAT_14053aec0 && (0.0 <= fVar26)) && (fVar26 <= DAT_14053af14)))))) {
      iVar11 = iVar10 * 500 + -500;
      auVar30._12_4_ = in_stack_fffffffffffffee8._12_4_;
      auVar30._0_8_ = in_stack_fffffffffffffee8._0_8_;
      auVar30._8_4_ = 1;
      in_stack_fffffffffffffee8._8_8_ = auVar30._8_8_;
      in_stack_fffffffffffffee8._0_8_ = CONCAT44(uVar25,uVar24);
      FUN_1400709b0(5,0,fVar27,fVar26,CONCAT22(uVar29,(short)(int)(dVar20 * dVar19)),0,
                    CONCAT44(uVar25,uVar24),in_stack_fffffffffffffee8._8_8_,iVar10,iVar11,0);
      if (2 < DAT_140e419b8) {
        dVar3 = (double)CONCAT44(uVar25,uVar24) + DAT_140539f58;
        auVar31._12_4_ = in_stack_fffffffffffffee8._12_4_;
        auVar31._0_8_ = in_stack_fffffffffffffee8._0_8_;
        auVar31._8_4_ = 1;
        in_stack_fffffffffffffee8._8_8_ = auVar31._8_8_;
        in_stack_fffffffffffffee8._0_8_ = dVar3;
        FUN_1400709b0(5,0,fVar27,fVar26,(int)(dVar20 * dVar19) & 0xffff,0,dVar3,
                      in_stack_fffffffffffffee8._8_8_,iVar10,iVar11,0);
      }
    }
    dVar19 = DAT_140539ee0;
    iVar10 = 0x3c;
    uVar16 = 0;
    do {
      iVar11 = (uVar16 & 0xffff) * 0x5555;
      fVar28 = DAT_14053ac58;
      uVar8 = FUN_140133f30(iVar11,(float)param_1[0xb] + DAT_14053ac58,0,
                            CONCAT22((short)((uint)*(ushort *)(param_1 + 3) * 0x29a >> 0x10),
                                     (short)((uint)*(ushort *)(param_1 + 3) * 0x29a) + (short)iVar11
                                    ),DAT_14053ac58,DAT_14053aca0);
      fVar22 = DAT_140e445d8;
      uVar29 = (undefined2)((uint)fVar28 >> 0x10);
      fStackX_14 = (float)(uVar8 >> 0x20);
      local_res10 = (float)uVar8;
      dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fStackX_14),
                                     SUB84((double)(DAT_140e445d8 - local_res10),0));
      iVar11 = param_1[3];
      if (((iVar10 <= iVar11) && (iVar11 < 0xf0)) &&
         ((((iVar11 = (iVar11 - iVar10) % 0xa0, iVar11 < 0x78 &&
            ((uVar2 = (longlong)iVar11 % (longlong)(iVar6 * 4), (int)uVar2 == 0 &&
             (fVar22 / DAT_14053ab70 + 0.0 <= fVar27)))) &&
           (fVar27 <= fVar22 / DAT_14053ab70 + fVar4)) && ((0.0 <= fVar26 && (fVar26 <= fVar5))))))
      {
        auVar32._12_4_ = in_stack_fffffffffffffee8._12_4_;
        auVar32._0_8_ = in_stack_fffffffffffffee8._0_8_;
        auVar32._8_4_ = 1;
        in_stack_fffffffffffffee8._8_8_ = auVar32._8_8_;
        in_stack_fffffffffffffee8._0_8_ = dVar21;
        sVar14 = (short)(int)(dVar20 * DAT_14053aba0);
        FUN_14006c2f0(0,uVar2 & 0xffffffff,uVar8 & 0xffffffff,fStackX_14,CONCAT22(uVar29,sVar14),0,
                      dVar21,in_stack_fffffffffffffee8._8_8_,0);
        if (2 < DAT_140e419b8) {
          uVar17 = 0;
          do {
            auVar33._12_4_ = in_stack_fffffffffffffee8._12_4_;
            auVar33._0_8_ = in_stack_fffffffffffffee8._0_8_;
            auVar33._8_4_ = 1;
            in_stack_fffffffffffffee8._8_8_ = auVar33._8_8_;
            in_stack_fffffffffffffee8._0_8_ = dVar21 - dVar19;
            FUN_14006c2f0(0,0,uVar8 & 0xffffffff,fStackX_14,
                          (short)((uVar17 & 0xffff) * 0x125c) + sVar14 + -0x92e,0,dVar21 - dVar19,
                          in_stack_fffffffffffffee8._8_8_,0);
            uVar17 = uVar17 + 1;
          } while ((int)uVar17 < 2);
        }
      }
      uVar16 = uVar16 + 1;
      iVar10 = iVar10 + iVar6;
      fVar22 = DAT_14053ab70;
    } while ((int)uVar16 < 3);
  }
  uVar7 = FUN_140133f30();
  uVar23 = DAT_140e44c30;
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  local_res8 = (undefined4)uVar7;
  uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
  puVar9[3] = local_res8;
  puVar9[4] = uStackX_c;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  *puVar9 = uVar23;
  puVar9[1] = 0x20;
  puVar9[2] = 7;
  *(undefined2 *)(puVar9 + 5) = 0;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
  DAT_140e46c88 = puVar9;
  uVar7 = FUN_140133f30();
  uVar23 = DAT_140e44c30;
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  local_res8 = (undefined4)uVar7;
  uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
  *puVar9 = uVar23;
  puVar9[1] = 0x20;
  puVar9[2] = 7;
  puVar9[3] = local_res8;
  puVar9[4] = uStackX_c;
  *(undefined2 *)(puVar9 + 5) = 0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
  DAT_140e46c88 = puVar9;
  uVar7 = FUN_140133f30();
  uVar23 = DAT_140e44c30;
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  local_res8 = (undefined4)uVar7;
  uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
  *puVar9 = uVar23;
  puVar9[1] = 0x20;
  puVar9[2] = 7;
  puVar9[3] = local_res8;
  puVar9[4] = uStackX_c;
  *(undefined2 *)(puVar9 + 5) = 0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  DAT_140e46d10 = DAT_140e46d10 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
  uVar25 = DAT_140e44c2c;
  uVar23 = param_1[0xb];
  uVar24 = param_1[10];
  DAT_140e46c88 = puVar9;
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[3] = uVar24;
  puVar9[4] = uVar23;
  *puVar9 = uVar25;
  puVar9[1] = 0x20;
  puVar9[2] = 7;
  *(undefined2 *)(puVar9 + 5) = 0;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  if (bVar18) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
  }
  DAT_140e46c88 = puVar9;
  FUN_140079c10(param_1,1);
LAB_14009e2f8:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / fVar22 - DAT_14053ad4c) ||
        (DAT_140e445d8 / fVar22 + _DAT_14053af18 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) &&
     (0x77 < (int)param_1[3])) {
    *param_1 = 0;
  }
  return;
}


