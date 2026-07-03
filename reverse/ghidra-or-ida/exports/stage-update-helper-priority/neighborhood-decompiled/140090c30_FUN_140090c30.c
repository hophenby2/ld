// Function: FUN_140090c30 @ 140090c30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140090c30(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  short sVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined2 uVar19;
  uint in_stack_ffffffffffffff10;
  uint uVar20;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  
  fVar4 = DAT_14053af14;
  dVar10 = DAT_140539e60;
  uVar19 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar5;
    dVar3 = DAT_140539fc8 - (double)(int)param_1[3] * dVar10;
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_ffffffffffffff18._8_4_ = SUB84(dVar3,0);
    in_stack_ffffffffffffff18._0_8_ = dVar3;
    in_stack_ffffffffffffff18._12_4_ = (int)((ulonglong)dVar3 >> 0x20);
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff10,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,0xff,1,0);
    uVar19 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4028000000000000;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (fVar4 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  fVar13 = DAT_14053ac58;
  if (param_1[5] == 1) {
    iVar8 = param_1[3];
    fVar1 = (float)param_1[0xb];
    fVar2 = (float)param_1[10];
    fVar16 = fVar1 + DAT_14053ac58;
    dVar9 = (double)FUN_140332d90(((double)iVar8 - 0.0) * _DAT_14053aa70 * DAT_14053a020 *
                                  DAT_140539d28);
    dVar3 = DAT_140539f40;
    uVar17 = SUB84(DAT_140539f40,0);
    uVar18 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    sVar7 = 0x3c;
    dVar10 = dVar9 * dVar10 + DAT_140539f40;
    if ((0x2c < iVar8) && (iVar8 < 0x41)) {
      sVar7 = 0x514;
    }
    if ((((float)param_1[0xc] <= 0.0) && (DAT_14053ae14 <= (float)param_1[0xd])) ||
       ((fVar4 <= (float)param_1[0xc] &&
        ((float)param_1[0xd] <= DAT_14053ae14 && DAT_14053ae14 != (float)param_1[0xd])))) {
      sVar7 = -sVar7;
    }
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar7;
    dVar9 = (double)FUN_1403307c0();
    fVar15 = (float)(dVar9 * *(double *)(param_1 + 0x12)) + fVar2;
    param_1[10] = fVar15;
    dVar9 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar9 * *(double *)(param_1 + 0x12)) + fVar1;
    fVar4 = DAT_140e445d8;
    if ((((iVar8 < 200) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= fVar2)) &&
        (fVar2 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
       ((DAT_14053aca8 <= fVar16 && (fVar16 <= DAT_14053aef4)))) {
      dVar9 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar16),
                                    SUB84((double)(DAT_140e445d8 - fVar2),0));
      uVar20 = DAT_14053ac2c;
      auVar21._0_8_ = in_stack_ffffffffffffff18._0_8_;
      iVar8 = 1;
      dVar9 = dVar9 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0x2a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x10;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar8 = 10;
      }
      else if (DAT_140e419b8 == 4) {
        iVar8 = 8;
      }
      uVar11 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
      if (DAT_140e419b8 == 0) {
        uVar12 = (undefined4)DAT_14053a0b0;
        uVar14 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar12 = (undefined4)DAT_14053a0f8;
        uVar14 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar12 = (undefined4)DAT_14053a138;
        uVar14 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else {
        uVar12 = uVar17;
        uVar14 = uVar18;
        if (DAT_140e419b8 == 4) {
          uVar12 = (int)DAT_14053a1b8;
          uVar14 = uVar11;
        }
      }
      if (7 < DAT_1407c7798) {
        iVar8 = 1;
        if (DAT_140e419b8 == 0) {
          iVar8 = 0x18;
        }
        else if (DAT_140e419b8 == 1) {
          iVar8 = 0xc;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar8 = 8;
        }
        if (DAT_140e419b8 == 0) {
          uVar12 = (undefined4)DAT_14053a0d0;
          uVar14 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
        }
        else if (DAT_140e419b8 == 1) {
          uVar12 = (undefined4)DAT_14053a120;
          uVar14 = (undefined4)((ulonglong)DAT_14053a120 >> 0x20);
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar12 = (undefined4)DAT_14053a158;
          uVar14 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
        }
        else {
          uVar12 = uVar17;
          uVar14 = uVar18;
          if (DAT_140e419b8 == 4) {
            uVar12 = (int)DAT_14053a1b8;
            uVar14 = uVar11;
          }
        }
      }
      if ((-1 < DAT_140e418c8) && ((int)((longlong)DAT_140e418c8 % (longlong)iVar8) == 0)) {
        if ((fVar4 / DAT_14053ab70 + fVar13 <= fVar15) &&
           (((fVar15 <= fVar4 / DAT_14053ab70 + DAT_14053aeb8 && (fVar13 <= (float)param_1[0xb])) &&
            ((float)param_1[0xb] <= DAT_14053af04)))) {
          auVar21._12_4_ = in_stack_ffffffffffffff18._12_4_;
          auVar21._8_4_ = 1;
          auVar22._8_8_ = auVar21._8_8_;
          auVar22._0_8_ = CONCAT44(uVar14,uVar12);
          in_stack_ffffffffffffff10 = DAT_14053ac2c;
          FUN_14006c2f0(6,(longlong)DAT_140e418c8 % (longlong)iVar8 & 0xffffffff,fVar2,fVar16,
                        CONCAT22(uVar19,(short)(int)dVar9),DAT_14053ac2c,CONCAT44(uVar14,uVar12),
                        auVar22._8_8_,0);
          auVar23._0_8_ = auVar22._0_8_;
          if (2 < DAT_140e419b8) {
            auVar23._12_4_ = auVar22._12_4_;
            auVar23._8_4_ = 1;
            FUN_14006c2f0(6,0,fVar2,fVar16,(int)dVar9 & 0xffff,uVar20,
                          (double)CONCAT44(uVar14,uVar12) + DAT_140539fd8,auVar23._8_8_,0);
            in_stack_ffffffffffffff10 = uVar20;
          }
        }
      }
    }
    FUN_1400c8410(DAT_140e446e0,0x23,7,param_1[10],param_1[0xb],
                  in_stack_ffffffffffffff10 & 0xffff0000,dVar10,dVar3,0xff,0xff,0xff,0xff,1,0);
    uVar18 = DAT_140e446e4;
    fVar4 = DAT_14053ac9c;
    sVar7 = *(short *)(param_1 + 3);
    uVar17 = param_1[10];
    fVar13 = (float)param_1[0xb] - DAT_14053ac9c;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar6[3] = uVar17;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[4] = fVar13;
    *puVar6 = uVar18;
    puVar6[1] = 0x23;
    puVar6[2] = 7;
    *(short *)(puVar6 + 5) = sVar7 * 2000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar18 = DAT_140e446e4;
    sVar7 = *(short *)(param_1 + 3);
    fVar13 = (float)param_1[0xb];
    uVar17 = param_1[10];
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar18;
    puVar6[1] = 0x23;
    puVar6[2] = 7;
    puVar6[3] = uVar17;
    puVar6[4] = fVar13 - fVar4;
    *(short *)(puVar6 + 5) = sVar7 * 2000 + 0x5555;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    uVar18 = DAT_140e446e4;
    sVar7 = *(short *)(param_1 + 3);
    fVar13 = (float)param_1[0xb];
    uVar17 = param_1[10];
    DAT_140e46c88 = puVar6;
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar6 = uVar18;
    puVar6[1] = 0x23;
    puVar6[2] = 7;
    puVar6[3] = uVar17;
    puVar6[4] = fVar13 - fVar4;
    *(short *)(puVar6 + 5) = sVar7 * 2000 + -0x5556;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    _DAT_140e46d1c = _DAT_140e46d1c + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    DAT_140e46c88 = puVar6;
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,200,2);
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


