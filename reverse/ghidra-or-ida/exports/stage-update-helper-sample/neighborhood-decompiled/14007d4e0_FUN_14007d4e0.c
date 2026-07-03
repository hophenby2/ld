// Function: FUN_14007d4e0 @ 14007d4e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14007d4e0(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  ushort uVar3;
  ulonglong uVar4;
  double dVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  int iVar8;
  ushort uVar9;
  ushort uVar10;
  int iVar11;
  short sVar12;
  int *piVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  float fVar19;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff18;
  undefined2 uVar20;
  uint in_stack_ffffffffffffff20;
  undefined1 in_stack_ffffffffffffff28 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  
  uVar20 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar16 = DAT_140539e60;
  dVar14 = dVar14 * DAT_14053aba0;
  piVar13 = param_1 + 5;
  if (param_1[5] == 0) {
    uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar6;
    dVar15 = DAT_140539fc8 - (double)(int)param_1[3] * dVar16;
    uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
    in_stack_ffffffffffffff28._8_4_ = SUB84(dVar15,0);
    in_stack_ffffffffffffff28._0_8_ = dVar15;
    in_stack_ffffffffffffff28._12_4_ = (int)((ulonglong)dVar15 >> 0x20);
    in_stack_ffffffffffffff20 = in_stack_ffffffffffffff20 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff20,
                  in_stack_ffffffffffffff28,0xff,0xff,0xff,0xff,1,0);
    uVar20 = (undefined2)((uint)uStackX_c >> 0x10);
    piVar13 = param_1 + 5;
    if (param_1[3] == 0x14) {
      uVar6 = FUN_140134db0(DAT_140e418c8,(int)DAT_14053a138,DAT_14053a1b8);
      *(undefined8 *)(param_1 + 0x12) = uVar6;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      piVar13 = param_1 + 5;
      uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      *piVar13 = *piVar13 + 1;
      local_res8 = (undefined4)uVar6;
      uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (*piVar13 == 1) {
    iVar11 = param_1[3];
    fVar19 = (float)param_1[0xb] + DAT_14053ac60;
    fVar1 = (float)param_1[10];
    dVar15 = (double)FUN_140332d90(((double)iVar11 - 0.0) * _DAT_14053a978 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar5 = DAT_140539f40;
    uVar17 = SUB84(DAT_140539f40,0);
    uVar18 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    dVar15 = dVar15 * dVar16 + DAT_140539f40;
    if (iVar11 < 200) {
      dVar2 = *(double *)(param_1 + 0x12);
      if ((-1 < iVar11) && (DAT_140539f40 < dVar2)) {
        dVar2 = dVar2 - dVar16;
      }
      uVar3 = *(ushort *)(param_1 + 0x10);
      iVar8 = ((int)dVar14 & 0xffffU) - (uint)uVar3;
      *(double *)(param_1 + 0x12) = dVar2;
      iVar11 = iVar8 + 0x10000;
      if (-0x8001 < iVar8) {
        iVar11 = iVar8;
      }
      iVar8 = iVar11 + -0x10000;
      if (iVar11 < 0x8001) {
        iVar8 = iVar11;
      }
      uVar9 = (ushort)(int)dVar14;
      if (iVar8 < 1) {
        uVar10 = uVar3;
        if ((iVar8 < 0) && (uVar10 = uVar3 - 0x80, -0x80 < iVar8)) {
          uVar10 = uVar9;
        }
      }
      else {
        uVar10 = uVar9;
        if (0x7f < iVar8) {
          uVar10 = uVar3 + 0x80;
        }
      }
    }
    else {
      uVar10 = *(ushort *)(param_1 + 0x10);
      iVar8 = -(uint)uVar10 + 0xc000;
      iVar11 = -(uint)uVar10 + 0x1c000;
      if (-0x8001 < iVar8) {
        iVar11 = iVar8;
      }
      iVar8 = iVar11 + -0x10000;
      if (iVar11 < 0x8001) {
        iVar8 = iVar11;
      }
      if (iVar8 < 1) {
        if ((iVar8 < 0) && (uVar10 = uVar10 - 0x200, -0x200 < iVar8)) {
          uVar10 = 0xc000;
        }
      }
      else if (iVar8 < 0x200) {
        uVar10 = 0xc000;
      }
      else {
        uVar10 = uVar10 + 0x200;
      }
      dVar2 = *(double *)(param_1 + 0x12) + dVar16;
      *(double *)(param_1 + 0x12) = dVar2;
    }
    *(ushort *)(param_1 + 0x10) = uVar10;
    dVar16 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar16 * dVar2) + (float)param_1[10];
    dVar16 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar16 * dVar2) + (float)param_1[0xb];
    if (((((int)param_1[3] < 200) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= fVar1)) &&
        (fVar1 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
       ((DAT_14053aca8 <= fVar19 && (fVar19 <= DAT_14053aef4)))) {
      dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),
                                     SUB84((double)(DAT_140e445d8 - fVar1),0));
      auVar21._0_8_ = in_stack_ffffffffffffff28._0_8_;
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x1e;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x10;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 0xc;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 8;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 6;
      }
      iVar8 = 1;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0x20;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x1b;
      }
      else if (DAT_140e419b8 == 2) {
        iVar8 = 0x14;
      }
      else if (DAT_140e419b8 == 3) {
        iVar8 = 0xf;
      }
      else if (DAT_140e419b8 == 4) {
        iVar8 = 6;
      }
      if (DAT_140e419b8 == 0) {
        uVar17 = (undefined4)DAT_14053a088;
        uVar18 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar17 = (undefined4)DAT_14053a0d0;
        uVar18 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar17 = (undefined4)DAT_14053a118;
        uVar18 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar17 = (undefined4)DAT_14053a190;
        uVar18 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
      }
      if (3 < DAT_1407c7798) {
        iVar8 = 1;
        if (DAT_140e419b8 == 0) {
          iVar8 = 0x18;
        }
        else if (DAT_140e419b8 == 1) {
          iVar8 = 0x14;
        }
        else if (DAT_140e419b8 == 2) {
          iVar8 = 0x10;
        }
        else if (DAT_140e419b8 == 3) {
          iVar8 = 0xc;
        }
        else if (DAT_140e419b8 == 4) {
          iVar8 = 6;
        }
      }
      if (iVar11 <= (int)param_1[3]) {
        uVar4 = (longlong)(param_1[3] - iVar11) % (longlong)(iVar8 * 5);
        iVar11 = (int)uVar4;
        if ((iVar11 < iVar8 * 3) &&
           (uVar4 = (longlong)((ulonglong)(uint)(iVar11 >> 0x1f) << 0x20 | uVar4 & 0xffffffff) %
                    (longlong)iVar8, (int)uVar4 == 0)) {
          auVar21._12_4_ = in_stack_ffffffffffffff28._12_4_;
          auVar21._8_4_ = 1;
          auVar22._8_8_ = auVar21._8_8_;
          auVar22._0_8_ = CONCAT44(uVar18,uVar17);
          in_stack_ffffffffffffff20 = 0;
          sVar12 = (short)(((int)(dVar16 * DAT_14053aba0) & 0xffffU) + 0x400 >> 0xb) * 0x800;
          FUN_14006c2f0(0,uVar4 & 0xffffffff,fVar1,fVar19,CONCAT22(uVar20,sVar12),0,
                        CONCAT44(uVar18,uVar17),auVar22._8_8_,0);
          auVar23._0_8_ = auVar22._0_8_;
          if (2 < DAT_140e419b8) {
            auVar23._12_4_ = auVar22._12_4_;
            auVar23._8_4_ = 1;
            in_stack_ffffffffffffff20 = 0;
            FUN_14006c2f0(0,0,fVar1,fVar19,sVar12,0,(double)CONCAT44(uVar18,uVar17) + DAT_140539fa8,
                          auVar23._8_8_,0);
          }
        }
      }
    }
    FUN_1400c8410(DAT_140e44670,0x23,7,param_1[10],param_1[0xb],
                  in_stack_ffffffffffffff20 & 0xffff0000,dVar15,dVar5,0xff,0xff,0xff,0xff,1,0);
    uVar18 = DAT_140e44674;
    fVar1 = DAT_14053acb0;
    sVar12 = *(short *)(param_1 + 3);
    uVar17 = param_1[10];
    fVar19 = (float)param_1[0xb] - DAT_14053acb0;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar7[3] = uVar17;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[4] = fVar19;
    *puVar7 = uVar18;
    puVar7[1] = 0x23;
    puVar7[2] = 7;
    *(short *)(puVar7 + 5) = sVar12 * 2000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar18 = DAT_140e44674;
    sVar12 = *(short *)(param_1 + 3);
    fVar19 = (float)param_1[0xb];
    uVar17 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar18;
    puVar7[1] = 0x23;
    puVar7[2] = 7;
    puVar7[3] = uVar17;
    puVar7[4] = fVar19 - fVar1;
    *(short *)(puVar7 + 5) = sVar12 * 2000 + 0x4000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar18 = DAT_140e44674;
    sVar12 = *(short *)(param_1 + 3);
    fVar19 = (float)param_1[0xb];
    uVar17 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar18;
    puVar7[1] = 0x23;
    puVar7[2] = 7;
    puVar7[3] = uVar17;
    puVar7[4] = fVar19 - fVar1;
    *(short *)(puVar7 + 5) = sVar12 * 2000 + -0x8000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar18 = DAT_140e44674;
    sVar12 = *(short *)(param_1 + 3);
    fVar19 = (float)param_1[0xb];
    uVar17 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar18;
    puVar7[1] = 0x23;
    puVar7[2] = 7;
    puVar7[3] = uVar17;
    puVar7[4] = fVar19 - fVar1;
    *(short *)(puVar7 + 5) = sVar12 * 2000 + -0x4000;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
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


