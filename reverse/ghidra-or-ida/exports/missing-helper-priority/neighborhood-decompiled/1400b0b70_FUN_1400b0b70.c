// Function: FUN_1400b0b70 @ 1400b0b70
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b0b70(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  double dVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  int *piVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff48;
  undefined2 uVar20;
  uint in_stack_ffffffffffffff50;
  undefined1 in_stack_ffffffffffffff58 [16];
  undefined1 auVar21 [16];
  
  uVar20 = (undefined2)((uint)in_stack_ffffffffffffff48 >> 0x10);
  dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar16 = DAT_140539fc8;
  dVar17 = DAT_140539e60;
  dVar15 = dVar15 * DAT_14053aba0;
  piVar14 = param_1 + 5;
  if (param_1[5] == 0) {
    uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar8;
    dVar4 = dVar16 - (double)(int)param_1[3] * dVar17;
    uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
    in_stack_ffffffffffffff58._8_4_ = SUB84(dVar4,0);
    in_stack_ffffffffffffff58._0_8_ = dVar4;
    in_stack_ffffffffffffff58._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    in_stack_ffffffffffffff50 = in_stack_ffffffffffffff50 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff50,
                  in_stack_ffffffffffffff58,0xff,0xff,0xff,0xff,1,0);
    uVar20 = (undefined2)((uint)uStackX_c >> 0x10);
    piVar14 = param_1 + 5;
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4018000000000000;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      piVar14 = param_1 + 5;
      uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
      *piVar14 = *piVar14 + 1;
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (*piVar14 == 1) {
    if ((int)param_1[3] < 0x5a) {
      dVar17 = *(double *)(param_1 + 0x12);
      if ((-1 < (int)param_1[3]) && (dVar16 < dVar17)) {
        dVar17 = dVar17 - _DAT_140539e28;
      }
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar10 = ((int)dVar15 & 0xffffU) - (uint)uVar2;
      *(double *)(param_1 + 0x12) = dVar17;
      iVar7 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar7 = iVar10;
      }
      iVar10 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar10 = iVar7;
      }
      uVar11 = (ushort)(int)dVar15;
      if (iVar10 < 1) {
        uVar12 = uVar2;
        if ((iVar10 < 0) && (uVar12 = uVar2 - 0x30, -0x30 < iVar10)) {
          uVar12 = uVar11;
        }
      }
      else {
        uVar12 = uVar11;
        if (0x2f < iVar10) {
          uVar12 = uVar2 + 0x30;
        }
      }
    }
    else {
      uVar12 = *(ushort *)(param_1 + 0x10);
      iVar10 = -(uint)uVar12 + 0xc000;
      iVar7 = -(uint)uVar12 + 0x1c000;
      if (-0x8001 < iVar10) {
        iVar7 = iVar10;
      }
      iVar10 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar10 = iVar7;
      }
      if (iVar10 < 1) {
        if ((iVar10 < 0) && (uVar12 = uVar12 - 0x200, -0x200 < iVar10)) {
          uVar12 = 0xc000;
        }
      }
      else if (iVar10 < 0x200) {
        uVar12 = 0xc000;
      }
      else {
        uVar12 = uVar12 + 0x200;
      }
      dVar17 = *(double *)(param_1 + 0x12) + dVar17;
      *(double *)(param_1 + 0x12) = dVar17;
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar16 = (double)FUN_1403307c0();
    fVar19 = (float)(dVar16 * dVar17) + (float)param_1[10];
    param_1[10] = fVar19;
    dVar16 = (double)FUN_140332d90();
    iVar7 = param_1[3];
    fVar18 = (float)(dVar16 * dVar17) + (float)param_1[0xb];
    param_1[0xb] = fVar18;
    fVar5 = DAT_140e445d8;
    if (iVar7 < 0x5a) {
      fVar18 = fVar18 + DAT_14053aca8;
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18),
                                     SUB84((double)(DAT_140e445d8 - fVar19),0));
      iVar10 = (iVar7 + -10) % 0x3c;
      if ((((fVar5 / DAT_14053ab70 + 0.0 <= fVar19) &&
           (fVar19 <= fVar5 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= fVar18)) &&
         (fVar18 <= DAT_14053af14)) {
        if ((9 < iVar7) && (iVar10 == 0)) {
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar17 * DAT_14053aba0);
        }
        iVar7 = param_1[3];
        if ((9 < iVar7) && ((iVar7 + -10) % 0x3c < 0x18)) {
          uVar13 = (iVar7 + -10) % 0x3c & 0x80000003;
          if ((int)uVar13 < 0) {
            uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
          }
          if (uVar13 == 0) {
            iVar7 = ((int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2) + 1;
            auVar21._12_4_ = in_stack_ffffffffffffff58._12_4_;
            auVar21._0_8_ = in_stack_ffffffffffffff58._0_8_;
            auVar21._8_4_ = 1;
            in_stack_ffffffffffffff50 = DAT_14053ac2c;
            FUN_1400709b0(0xd,0,fVar19,fVar18,
                          CONCAT22(uVar20,*(undefined2 *)((longlong)param_1 + 0x42)),DAT_14053ac2c,
                          DAT_14053a1b8,auVar21._8_8_,iVar7,iVar7 * 400 + -400,0);
          }
        }
      }
    }
    FUN_1400c8410(DAT_140e44df8,0x22,7,param_1[10],param_1[0xb],
                  in_stack_ffffffffffffff50 & 0xffff0000,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                  0xff,0xff,1,0);
    uVar6 = DAT_140e44dfc;
    fVar5 = DAT_14053acfc;
    sVar3 = *(short *)(param_1 + 3);
    uVar1 = param_1[10];
    fVar18 = (float)param_1[0xb] - DAT_14053acfc;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar9[3] = uVar1;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[4] = fVar18;
    *puVar9 = uVar6;
    puVar9[1] = 0x22;
    puVar9[2] = 7;
    *(short *)(puVar9 + 5) = sVar3 * 1000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar6 = DAT_140e44dfc;
    sVar3 = *(short *)(param_1 + 3);
    fVar18 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar6;
    puVar9[1] = 0x22;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = fVar18 - fVar5;
    *(short *)(puVar9 + 5) = sVar3 * 1000 + 0x4000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar6 = DAT_140e44dfc;
    sVar3 = *(short *)(param_1 + 3);
    fVar18 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar6;
    puVar9[1] = 0x22;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = fVar18 - fVar5;
    *(short *)(puVar9 + 5) = sVar3 * 1000 + -0x8000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar6 = DAT_140e44dfc;
    sVar3 = *(short *)(param_1 + 3);
    fVar18 = (float)param_1[0xb];
    uVar1 = param_1[10];
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar9 = uVar6;
    puVar9[1] = 0x22;
    puVar9[2] = 7;
    puVar9[3] = uVar1;
    puVar9[4] = fVar18 - fVar5;
    *(short *)(puVar9 + 5) = sVar3 * 1000 + -0x4000;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    _DAT_140e46d18 = _DAT_140e46d18 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,3);
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


