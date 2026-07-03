// Function: FUN_140012dc0 @ 140012dc0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140012dc0(undefined4 *param_1)

{
  undefined4 uVar1;
  short sVar2;
  double dVar3;
  double dVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  longlong lVar14;
  float fVar15;
  undefined4 *puVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 uVar26;
  double dVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  undefined2 uVar32;
  uint in_stack_fffffffffffffe70;
  undefined2 uVar33;
  undefined8 uStack_130;
  int iStack_11c;
  undefined8 uStack_110;
  
  fVar22 = DAT_14053ac80;
  dVar13 = DAT_14053a020;
  dVar27 = DAT_140539f40;
  dVar3 = DAT_140539d28;
  iVar21 = 0;
  iStack_11c = 0;
  lVar14 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar14 != 0; lVar14 = *(longlong *)(lVar14 + 0x60)) {
      if (*(int *)(lVar14 + 4) == DAT_140e44308) {
        uStack_130 = *(undefined8 *)(lVar14 + 8);
        iStack_11c = *(int *)(lVar14 + 0x1c);
        uStack_110 = *(undefined8 *)(lVar14 + 0x28);
      }
    }
  }
  dVar11 = dVar27;
  dVar12 = dVar27;
  if (param_1[5] == 0) {
    iVar20 = param_1[3];
    if (iVar20 == 0) {
      param_1[0xc] = (float)uStack_110;
      param_1[0xd] = uStack_110._4_4_;
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 10);
    }
    dVar10 = (double)iVar20;
    uVar28 = SUB84(dVar10 * DAT_14053a6d8 * dVar13 * dVar3,0);
    dVar4 = (double)FUN_140332d90(uVar28);
    fVar31 = (float)(dVar4 * (double)((float)param_1[0xe] - (float)param_1[0xc])) +
             (float)param_1[0xc];
    dVar4 = (double)FUN_140332d90(uVar28);
    param_1[10] = fVar31;
    fVar25 = (float)(dVar4 * (double)((float)param_1[0xf] - (float)param_1[0xd])) +
             (float)param_1[0xd];
    param_1[0xb] = fVar25;
    if (iVar20 < 0) {
      dVar11 = 0.0;
      dVar12 = 0.0;
      goto LAB_14001341d;
    }
    if (iVar20 < 10) {
      dVar3 = (double)FUN_140332d90(SUB84((dVar10 - 0.0) * DAT_14053a9d8 * dVar13 * dVar3,0));
      dVar11 = 0.0;
      dVar12 = dVar3 + 0.0;
      goto LAB_14001341d;
    }
    if (iVar20 < 0x28) {
      dVar3 = (double)FUN_140332d90(SUB84((dVar10 - DAT_14053a1e8) * DAT_14053a798 * dVar13 * dVar3,
                                          0));
      dVar11 = dVar3 + 0.0;
      goto LAB_14001341d;
    }
    if (iVar20 != 0x28) goto LAB_14001341d;
    param_1[0xc] = fVar31;
    param_1[0xd] = fVar25;
    param_1[0x15] = 0;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_14001341d;
  uVar28 = param_1[10];
  uVar1 = param_1[0xb];
  uVar26 = SUB84(((double)(int)param_1[3] - _DAT_140539cc0) * _DAT_14053a6f8 * dVar13 * dVar3,0);
  dVar27 = (double)FUN_140332d90(uVar26);
  dVar27 = dVar27 * DAT_14053a2d8;
  if (param_1[6] == 0x33) {
    dVar27 = (double)FUN_140332d90(uVar26);
    dVar27 = dVar27 * DAT_14053b128;
  }
  dVar4 = *(double *)(param_1 + 0x12);
  uVar26 = SUB84((double)*(ushort *)(param_1 + 0x10) * dVar13 * dVar3,0);
  dVar3 = (double)FUN_1403307c0(uVar26);
  fVar31 = (float)(dVar3 * dVar4) + (float)param_1[0xc];
  param_1[0xc] = fVar31;
  dVar3 = (double)FUN_140332d90(uVar26);
  iVar20 = DAT_140e419b8;
  fVar31 = fVar31 + (float)dVar27 + 0.0;
  iVar19 = 1;
  dVar27 = dVar4 + DAT_140539e20;
  param_1[10] = fVar31;
  *(double *)(param_1 + 0x12) = dVar27;
  fVar25 = (float)(dVar3 * dVar4) + (float)param_1[0xd];
  param_1[0xd] = fVar25;
  param_1[0xb] = fVar25;
  if (iVar20 == 0) {
    iVar19 = 0x50;
  }
  else if (iVar20 == 1) {
    iVar19 = 0x3c;
  }
  else if (((iVar20 == 2) || (iVar20 == 3)) || (iVar20 == 4)) {
    iVar19 = 0x32;
  }
  iVar18 = 1;
  if (iVar20 == 0) {
    iVar18 = 0x18;
  }
  else if (iVar20 == 1) {
    iVar18 = 0x20;
  }
  else if ((iVar20 == 2) || (iVar20 == 3)) {
    iVar18 = 0x24;
  }
  else if (iVar20 == 4) {
    iVar18 = 0x28;
  }
  dVar27 = DAT_14053a0d0;
  if (((iVar20 != 0) && (dVar27 = DAT_14053a118, iVar20 != 1)) &&
     ((dVar27 = DAT_14053a138, iVar20 != 2 &&
      ((dVar27 = DAT_14053a0f8, iVar20 != 3 && (dVar27 = DAT_140539f40, iVar20 == 4)))))) {
    dVar27 = DAT_14053a158;
  }
  fVar22 = DAT_14053ac80;
  if (0x3b < uStack_130._4_4_) {
    if ((uStack_130._4_4_ + -0x3c) % iVar19 == 0) {
      dVar3 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - DAT_14053b3d0),0),
                                    SUB84((double)(DAT_140e445d8 - (float)uStack_110),0));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar3 * DAT_14053aba0);
    }
    else if (uStack_130._4_4_ < 0x3c) goto LAB_1400133e4;
    uVar17 = (uStack_130._4_4_ + -0x3c) % iVar19;
    fVar22 = DAT_14053ac80;
    if ((int)uVar17 < iVar18) {
      uVar17 = uVar17 & 0x80000003;
      if ((int)uVar17 < 0) {
        uVar17 = (uVar17 - 1 | 0xfffffffc) + 1;
      }
      if ((uVar17 == 0) && (fVar25 < DAT_14053af04)) {
        fVar31 = (float)FUN_140334430(fVar31 - DAT_140e445d8,DAT_140539fc0);
        fVar22 = (float)FUN_140334430(fVar25 - DAT_140e445dc);
        fVar31 = fVar31 + fVar22;
        if (fVar31 < 0.0) {
          fVar31 = (float)FUN_1403352f8(fVar31);
        }
        else {
          fVar31 = SQRT(fVar31);
        }
        fVar22 = DAT_14053ac80;
        uVar17 = DAT_14053ac2c;
        if (DAT_14053ac80 < fVar31) {
          sVar2 = *(short *)((longlong)param_1 + 0x42);
          iVar20 = iVar21;
          do {
            in_stack_fffffffffffffe70 = uVar17;
            FUN_14006c2f0(7,0,uVar28,uVar1,(short)iVar20 * -0x8000 + sVar2,uVar17,dVar27,1,0);
            iVar20 = iVar20 + 1;
          } while (iVar20 < 2);
          if (2 < DAT_140e419b8) {
            dVar27 = dVar27 + DAT_140539fc8;
            sVar2 = *(short *)((longlong)param_1 + 0x42);
            do {
              in_stack_fffffffffffffe70 = uVar17;
              FUN_14006c2f0(7,0,uVar28,uVar1,(short)iVar21 * -0x8000 + sVar2,uVar17,dVar27,1,0);
              iVar21 = iVar21 + 1;
            } while (iVar21 < 2);
          }
          FUN_140184700(DAT_140e44190 * 9,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
  }
LAB_1400133e4:
  FUN_140079c10(param_1,2);
  dVar27 = DAT_140539f40;
LAB_14001341d:
  uVar30 = SUB84(dVar12,0);
  uVar29 = (undefined4)((ulonglong)dVar11 >> 0x20);
  uVar26 = SUB84(dVar11,0);
  uVar17 = in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e446d8,0x23,7,param_1[10],param_1[0xb],uVar17,dVar11,uVar26,0xff,0xff,0xff,
                0xff,1,0);
  uVar28 = param_1[0xb];
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410(DAT_140e446d4,0x23,7,param_1[10],uVar28,uVar17,dVar12,uVar30,0xff,0xff,0xff,0xff,1,0
               );
  uVar1 = DAT_140e446dc;
  uVar32 = (undefined2)((uint)uVar28 >> 0x10);
  fVar25 = (float)param_1[0xb];
  uVar33 = *(undefined2 *)(param_1 + 0x11);
  uVar28 = param_1[10];
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  puVar16[3] = uVar28;
  puVar16[4] = fVar25 - fVar22;
  *puVar16 = uVar1;
  puVar16[1] = 0x23;
  puVar16[2] = 7;
  *(undefined2 *)(puVar16 + 5) = uVar33;
  auVar5._8_4_ = uVar26;
  auVar5._0_8_ = dVar11;
  auVar5._12_4_ = uVar29;
  *(undefined1 (*) [16])(puVar16 + 6) = auVar5;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar16;
  }
  uVar1 = DAT_140e446dc;
  fVar25 = (float)param_1[0xb];
  sVar2 = *(short *)(param_1 + 0x11);
  uVar28 = param_1[10];
  DAT_140e46c88 = puVar16;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar16 = uVar1;
  puVar16[1] = 0x23;
  puVar16[2] = 7;
  puVar16[3] = uVar28;
  puVar16[4] = fVar25 - fVar22;
  *(short *)(puVar16 + 5) = sVar2 + 0x3333;
  auVar6._8_4_ = uVar26;
  auVar6._0_8_ = dVar11;
  auVar6._12_4_ = uVar29;
  *(undefined1 (*) [16])(puVar16 + 6) = auVar6;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
  }
  uVar1 = DAT_140e446dc;
  fVar25 = (float)param_1[0xb];
  sVar2 = *(short *)(param_1 + 0x11);
  uVar28 = param_1[10];
  DAT_140e46c88 = puVar16;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar16 = uVar1;
  puVar16[1] = 0x23;
  puVar16[2] = 7;
  puVar16[3] = uVar28;
  puVar16[4] = fVar25 - fVar22;
  *(short *)(puVar16 + 5) = sVar2 + 0x6666;
  auVar7._8_4_ = uVar26;
  auVar7._0_8_ = dVar11;
  auVar7._12_4_ = uVar29;
  *(undefined1 (*) [16])(puVar16 + 6) = auVar7;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
  }
  uVar1 = DAT_140e446dc;
  sVar2 = *(short *)(param_1 + 0x11);
  fVar25 = (float)param_1[0xb];
  uVar28 = param_1[10];
  DAT_140e46c88 = puVar16;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar16 = uVar1;
  puVar16[1] = 0x23;
  puVar16[2] = 7;
  puVar16[3] = uVar28;
  puVar16[4] = fVar25 - fVar22;
  *(short *)(puVar16 + 5) = sVar2 + -0x6667;
  auVar8._8_4_ = uVar26;
  auVar8._0_8_ = dVar11;
  auVar8._12_4_ = uVar29;
  *(undefined1 (*) [16])(puVar16 + 6) = auVar8;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
  }
  uVar1 = DAT_140e446dc;
  sVar2 = *(short *)(param_1 + 0x11);
  fVar25 = (float)param_1[0xb];
  uVar28 = param_1[10];
  DAT_140e46c88 = puVar16;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  uVar33 = (undefined2)(uVar17 >> 0x10);
  *puVar16 = uVar1;
  puVar16[1] = 0x23;
  puVar16[2] = 7;
  puVar16[3] = uVar28;
  puVar16[4] = fVar25 - fVar22;
  *(short *)(puVar16 + 5) = sVar2 + -0x3334;
  auVar9._8_4_ = uVar26;
  auVar9._0_8_ = dVar11;
  auVar9._12_4_ = uVar29;
  *(undefined1 (*) [16])(puVar16 + 6) = auVar9;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
  }
  DAT_140e46c88 = puVar16;
  if ((param_1[5] == 0) && ((*(byte *)(param_1 + 3) & 1) == 0)) {
    uVar28 = param_1[0xb];
    uVar17 = uVar17 & 0xffff0000;
    FUN_140070d00(5,DAT_140e446d4,0x22,param_1[10],uVar28,uVar17,0,uVar30,uVar30,0x18,0xff,0xff,0xff
                  ,0x60,0);
    uVar33 = (undefined2)(uVar17 >> 0x10);
    uVar32 = (undefined2)((uint)uVar28 >> 0x10);
  }
  *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 2000;
  fVar22 = DAT_140e445dc;
  if ((int)param_1[7] < 1) {
    fVar25 = (float)param_1[0xb];
    if (fVar25 < DAT_14053ae90) {
      fVar31 = (float)param_1[10];
      fVar23 = (float)FUN_140334430(fVar25 - DAT_140e445dc,DAT_140539fc0);
      fVar15 = DAT_140e445d8;
      fVar24 = (float)FUN_140334430(fVar31 - DAT_140e445d8);
      fVar23 = fVar23 + fVar24;
      if (fVar23 < 0.0) {
        fVar23 = (float)FUN_1403352f8(fVar23);
      }
      else {
        fVar23 = SQRT(fVar23);
      }
      if (DAT_14053acfc < fVar23) {
        dVar3 = (double)FUN_1403300b4(SUB84((double)(fVar22 - fVar25),0),
                                      SUB84((double)(fVar15 - fVar31),0));
        dVar10 = DAT_14053a158;
        dVar4 = DAT_14053a118;
        dVar12 = DAT_14053a0f8;
        dVar11 = DAT_14053a0b0;
        dVar3 = dVar3 * DAT_14053aba0;
        dVar13 = DAT_14053a0b0;
        if ((((DAT_140e419b8 != 0) && (dVar13 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
            (dVar13 = DAT_14053a118, DAT_140e419b8 != 2)) &&
           ((DAT_140e419b8 != 3 && (dVar13 = dVar27, DAT_140e419b8 == 4)))) {
          dVar13 = DAT_14053a158;
        }
        uVar33 = 0;
        FUN_14006c2f0(2,3,fVar31,fVar25,CONCAT22(uVar32,(short)(int)dVar3),0,dVar13,1,0);
        if (2 < DAT_140e419b8) {
          if (((DAT_140e419b8 != 0) && (dVar11 = dVar12, DAT_140e419b8 != 1)) &&
             ((dVar11 = dVar4, DAT_140e419b8 != 2 &&
              ((DAT_140e419b8 != 3 && (dVar11 = dVar27, DAT_140e419b8 == 4)))))) {
            dVar11 = dVar10;
          }
          uVar33 = 0;
          FUN_14006c2f0(2,3,param_1[10],param_1[0xb],(int)dVar3 & 0xffff,0,dVar11 + DAT_140539f90,1,
                        0);
        }
      }
    }
    DAT_140e44ac8 = DAT_140e44ac8 + 1;
    FUN_14007b010(param_1,500,1);
    FUN_140079e20(param_1,0);
    if (DAT_140e44654 == 0) {
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar33,0x4000),dVar27,10,1,
                 DAT_140e44308);
    }
    *param_1 = 0;
  }
  if ((iStack_11c < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


