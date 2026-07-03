// Function: FUN_1400f4430 @ 1400f4430
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400f4430(int *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  longlong lVar8;
  ushort uVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 in_stack_fffffffffffffe78;
  undefined2 uVar20;
  uint in_stack_fffffffffffffe80;
  undefined8 in_stack_fffffffffffffe90;
  undefined4 uVar21;
  int iStack_12c;
  int iStack_124;
  undefined8 uStack_110;
  undefined4 local_108;
  
  iVar6 = DAT_140e418c8;
  uVar20 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
  uVar21 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == DAT_140e44308) {
        iStack_12c = *(int *)(lVar8 + 0xc);
        iStack_124 = *(int *)(lVar8 + 0x14);
        uStack_110._0_4_ = *(float *)(lVar8 + 0x28);
        uStack_110._4_4_ = *(float *)(lVar8 + 0x2c);
        local_108 = *(undefined4 *)(lVar8 + 0x30);
      }
      param_4 = local_108;
    }
  }
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == param_1[2]) {
        uStack_110 = *(undefined8 *)(lVar8 + 0x28);
      }
    }
  }
  fVar13 = (float)uStack_110 + (float)param_1[0xe];
  fVar17 = uStack_110._4_4_ + (float)param_1[0xf];
  uVar4 = param_1[6] - 0xf2;
  uVar11 = 0;
  iVar10 = 0x514;
  iVar5 = 3000;
  lVar8 = 0x90;
  uVar12 = 0;
  if (7 < uVar4) goto LAB_1400f48db;
  uVar12 = uVar11;
  switch(param_1[6]) {
  case 0xf2:
    dVar15 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053b178) * DAT_14053a7f8 *
                                   DAT_14053a020 * DAT_140539d28,&IMAGE_DOS_HEADER_140000000,
                                   DAT_140e44e6c,param_4);
    dVar16 = DAT_14053a6d0;
    dVar15 = dVar15 * DAT_14053a6d0;
    dVar14 = (double)FUN_1403307c0();
    fVar13 = (float)(dVar14 * dVar16) + (float)uStack_110;
    dVar14 = (double)FUN_140332d90();
    fVar17 = (float)(dVar14 * dVar16) + uStack_110._4_4_;
    uVar12 = (short)(int)dVar15;
    break;
  case 0xf3:
    FUN_140332d90(IMAGE_DOS_HEADER_140000000.e_magic +
                  (&switchD_1400f45dd::switchdataD_1400f4ec0)[(int)uVar4],
                  &IMAGE_DOS_HEADER_140000000,DAT_140e44e6c,param_4);
    dVar16 = (double)FUN_1403307c0();
    dVar16 = dVar16 * _DAT_14053a6a0;
    dVar15 = (double)FUN_140332d90();
    dVar15 = dVar15 * _DAT_14053a6a0;
    dVar14 = (double)FUN_140332d90();
    dVar14 = dVar14 * DAT_14053a6d0;
    lVar8 = 0x91;
    iVar5 = 3000;
    iVar10 = 0x514;
    goto LAB_1400f48d3;
  case 0xf4:
    iVar10 = 2000;
    iVar5 = 0x157c;
    lVar8 = 0x92;
    break;
  case 0xf5:
    iVar10 = 2000;
    iVar5 = 0x157c;
    lVar8 = 0x93;
    break;
  case 0xf6:
    iVar10 = 2000;
    iVar5 = 0x157c;
    lVar8 = 0x94;
    break;
  case 0xf7:
    iVar10 = 2000;
    iVar5 = 0x157c;
    lVar8 = 0x95;
    break;
  case 0xf8:
    iVar10 = 0x1644;
    iVar5 = 0x2134;
    dVar16 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053b128) * DAT_14053a7f8 *
                                   DAT_14053a020 * DAT_140539d28,&IMAGE_DOS_HEADER_140000000,
                                   DAT_140e44e6c,param_4);
    dVar16 = dVar16 * DAT_14053a840;
    dVar15 = (double)FUN_1403307c0();
    fVar13 = (float)(dVar15 * DAT_14053a568) + (float)uStack_110;
    dVar15 = (double)FUN_140332d90();
    lVar8 = 0x96;
    fVar17 = (float)(dVar15 * DAT_14053a568) + uStack_110._4_4_;
    uVar12 = (short)(int)dVar16;
    break;
  case 0xf9:
    FUN_140332d90(IMAGE_DOS_HEADER_140000000.e_magic +
                  (&switchD_1400f45dd::switchdataD_1400f4ec0)[(int)uVar4],
                  &IMAGE_DOS_HEADER_140000000,DAT_140e44e6c,param_4);
    dVar16 = (double)FUN_1403307c0();
    dVar16 = dVar16 * DAT_14053a568;
    dVar15 = (double)FUN_140332d90();
    dVar15 = dVar15 * DAT_14053a568;
    dVar14 = (double)FUN_140332d90();
    dVar14 = dVar14 * _DAT_14053b278;
    lVar8 = 0x97;
    iVar5 = 0x238c;
    iVar10 = 0x1edc;
LAB_1400f48d3:
    fVar13 = (float)dVar16 + (float)uStack_110;
    fVar17 = (float)dVar15 + uStack_110._4_4_;
    uVar12 = (short)(int)dVar14;
  }
LAB_1400f48db:
  fVar19 = (float)param_1[0xb];
  fVar18 = (float)param_1[10];
  FUN_1403300b4((double)(fVar17 - fVar19),(double)(fVar13 - fVar18));
  dVar16 = DAT_14053aba0;
  fVar13 = (float)FUN_140334430(fVar18 - fVar13,DAT_140539fc0);
  fVar17 = (float)FUN_140334430(fVar19 - fVar17);
  if (fVar13 + fVar17 < 0.0) {
    fVar13 = (float)FUN_1403352f8();
  }
  else {
    fVar13 = SQRT(fVar13 + fVar17);
  }
  dVar15 = (double)fVar13 / DAT_14053a018;
  dVar14 = (double)FUN_1403307c0();
  fVar18 = (float)(dVar14 * dVar15) + fVar18;
  param_1[10] = (int)fVar18;
  dVar14 = (double)FUN_140332d90();
  fVar19 = (float)(dVar14 * dVar15) + fVar19;
  param_1[0xb] = (int)fVar19;
  if (param_1[5] == 0) {
    if ((param_1[3] == 0) && (iVar10 <= iVar6)) {
      *param_1 = 0;
    }
    else if (*param_1 == 1) {
      if ((((iVar10 <= iVar6) && (DAT_14053accc <= fVar18)) && (fVar18 <= DAT_14053aee8)) &&
         ((DAT_14053accc <= fVar19 && (fVar19 <= DAT_14053aee8)))) {
        param_1[0x15] = 0;
        param_1[3] = 0;
        param_1[5] = 1;
      }
      if (0 < iStack_124) {
        param_1[0x15] = 1;
        param_1[5] = 2;
      }
    }
  }
  fVar13 = DAT_14053ab70;
  if (param_1[5] != 1) goto LAB_1400f4c79;
  if ((iVar6 < iVar5) && (param_1[0x15] == 0)) {
    fVar17 = (float)param_1[10];
    dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),(double)(DAT_140e445d8 - fVar17)
                                  );
    iVar6 = param_1[3];
    uVar4 = (iVar6 + -0x14) % 0x32;
    dVar14 = (double)(int)uVar4 * DAT_140539ec8 + DAT_14053a110;
    if (0x13 < iVar6) {
      uVar9 = (ushort)(int)(dVar15 * dVar16);
      if (uVar4 == 0) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar9;
LAB_1400f4b31:
        FUN_14006c2f0(0xd,0,fVar17,fVar19,CONCAT22(uVar20,*(undefined2 *)((longlong)param_1 + 0x42))
                      ,0,dVar14,CONCAT44(uVar21,1),0);
        in_stack_fffffffffffffe80 = 0;
        FUN_14006c2f0(0xd,0,param_1[10],param_1[0xb],*(undefined2 *)((longlong)param_1 + 0x42),0,
                      dVar14 + DAT_140539fc8,1,0);
        uVar1 = *(ushort *)((longlong)param_1 + 0x42);
        iVar5 = ((int)(dVar15 * dVar16) & 0xffffU) - (uint)uVar1;
        iVar6 = iVar5 + 0x10000;
        if (-0x8001 < iVar5) {
          iVar6 = iVar5;
        }
        iVar5 = iVar6 + -0x10000;
        if (iVar6 < 0x8001) {
          iVar5 = iVar6;
        }
        if (iVar5 < 1) {
          uVar7 = uVar1;
          if ((iVar5 < 0) && (uVar7 = uVar1 - 0x100, -0x100 < iVar5)) {
            uVar7 = uVar9;
          }
        }
        else {
          uVar7 = uVar9;
          if (0xff < iVar5) {
            uVar7 = uVar1 + 0x100;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar7;
      }
      else if ((0x13 < iVar6) && ((int)uVar4 < 0x18)) {
        uVar4 = uVar4 & 0x80000003;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
        }
        if (uVar4 == 0) goto LAB_1400f4b31;
      }
    }
  }
  fVar17 = DAT_140e445d8 / fVar13;
  if (((((float)param_1[10] < fVar17 + 0.0) || (fVar17 + DAT_14053aec0 < (float)param_1[10])) ||
      ((float)param_1[0xb] < 0.0)) || (DAT_14053af14 < (float)param_1[0xb])) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  param_1[0x15] = iVar6;
  if (param_1[7] < 1) {
    FUN_14007b010(param_1,1000,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
LAB_1400f4c79:
  uVar3 = _UNK_14053bb28;
  uVar2 = _DAT_14053bb20;
  fVar17 = (float)param_1[10];
  fVar19 = (float)param_1[0xb];
  fVar13 = DAT_140e445d8 / fVar13;
  if (((fVar13 - DAT_14053acfc <= fVar17) && (fVar17 <= fVar13 + DAT_14053aef4)) &&
     ((DAT_14053b370 <= fVar19 && ((fVar19 <= DAT_14053af48 && (*param_1 == 1)))))) {
    in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
    FUN_1400c8410((&DAT_140e44660)[lVar8],0x17,7,fVar17,fVar19,in_stack_fffffffffffffe80,
                  _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    uVar20 = (undefined2)(in_stack_fffffffffffffe80 >> 0x10);
    if ((param_1[5] == 1) && (uVar4 = param_1[3], (int)uVar4 < 0x28)) {
      iVar6 = 0xff;
      if (uVar4 < 0x28) {
        dVar16 = (double)FUN_140332d90(((double)(int)uVar4 - DAT_14053b138) * DAT_14053a6d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar6 = (int)(dVar16 * DAT_14053a5f8);
      }
      FUN_1400c8410((&DAT_140e44660)[lVar8],0x17,8,param_1[10],param_1[0xb],CONCAT22(uVar20,uVar12),
                    uVar2,uVar3,0xff,0xff,0xff,iVar6,1,0);
    }
    if (param_1[0x15] == 0) {
      FUN_140079c10(param_1,2);
    }
  }
  if ((iStack_124 == 7) && (iStack_12c == 0xa0)) {
    *param_1 = 0;
  }
  return;
}


