// Function: FUN_140084be0 @ 140084be0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140084be0(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auVar4 [16];
  double dVar5;
  undefined1 auVar6 [16];
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff28;
  undefined2 uVar23;
  uint in_stack_ffffffffffffff30;
  undefined2 uVar24;
  undefined1 in_stack_ffffffffffffff38 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  
  uVar23 = (undefined2)((uint)in_stack_ffffffffffffff28 >> 0x10);
  dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar5 = DAT_140539e60;
  uVar24 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
  uVar13 = (uint)(dVar17 * DAT_14053aba0);
  if (param_1[5] == 0) {
    uVar9 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar9;
    dVar17 = DAT_140539fc8 - (double)(int)param_1[3] * dVar5;
    uStackX_c = (undefined4)((ulonglong)uVar9 >> 0x20);
    in_stack_ffffffffffffff38._8_4_ = SUB84(dVar17,0);
    in_stack_ffffffffffffff38._0_8_ = dVar17;
    in_stack_ffffffffffffff38._12_4_ = (int)((ulonglong)dVar17 >> 0x20);
    in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff30,
                  in_stack_ffffffffffffff38,0xff,0xff,0xff,0xff,1,0);
    uVar7 = DAT_140e418c8;
    uVar24 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
    uVar23 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4021333333333333;
      uVar14 = (uVar7 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar7 = uVar14 ^ uVar14 * 0x800;
      uVar14 = uVar14 ^ uVar14 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
      uVar7 = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
      DAT_140e9fd1c = uVar14;
      *(short *)(param_1 + 0x10) =
           (short)uVar7 + (short)((ulonglong)uVar7 / 0x961) * -0x961 + 0x3b50;
      *(short *)((longlong)param_1 + 0x42) = (short)uVar14 - (short)(uVar14 / 0x10001);
      uVar9 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar9;
      uStackX_c = (undefined4)((ulonglong)uVar9 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (param_1[5] == 1) {
    iVar2 = param_1[3];
    dVar17 = (double)FUN_140332d90(((double)iVar2 - 0.0) * _DAT_14053aa70 * DAT_14053a020 *
                                   DAT_140539d28);
    auVar6 = _DAT_14053bb20;
    uVar19 = (undefined4)DAT_14053bb20;
    uVar20 = DAT_14053bb20._4_4_;
    dVar5 = dVar17 * dVar5 + (double)DAT_14053bb20;
    uVar12 = (ushort)uVar13;
    if (iVar2 < 0x28) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar10 = (uVar13 & 0xffff) - (uint)uVar1;
      iVar8 = iVar10 + 0x10000;
      if (-0x8001 < iVar10) {
        iVar8 = iVar10;
      }
      iVar10 = iVar8 + -0x10000;
      if (iVar8 < 0x8001) {
        iVar10 = iVar8;
      }
      if (iVar10 < 1) {
        uVar11 = uVar1;
        if ((iVar10 < 0) && (uVar11 = uVar1 - 0x80, -0x80 < iVar10)) {
          uVar11 = uVar12;
        }
      }
      else {
        uVar11 = uVar12;
        if (0x7f < iVar10) {
          uVar11 = uVar1 + 0x80;
        }
      }
      dVar17 = *(double *)(param_1 + 0x12);
      *(ushort *)(param_1 + 0x10) = uVar11;
      if ((-1 < iVar2) && (DAT_140539f10 < dVar17)) {
        dVar17 = dVar17 - DAT_140539ec8;
      }
    }
    else {
      dVar17 = *(double *)(param_1 + 0x12) + DAT_140539ea0;
    }
    *(double *)(param_1 + 0x12) = dVar17;
    dVar18 = (double)FUN_1403307c0();
    fVar21 = (float)(dVar18 * dVar17) + (float)param_1[10];
    param_1[10] = fVar21;
    dVar18 = (double)FUN_140332d90();
    *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + 0x378;
    fVar22 = (float)(dVar18 * dVar17) + (float)param_1[0xb];
    param_1[0xb] = fVar22;
    if ((((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar21) &&
         (fVar21 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= fVar22)) &&
       (fVar22 <= DAT_14053af14)) {
      fVar15 = (float)FUN_140334430(fVar22 - DAT_140e445dc,DAT_140539fc0);
      fVar16 = (float)FUN_140334430(fVar21 - DAT_140e445d8);
      if (fVar15 + fVar16 < 0.0) {
        fVar15 = (float)FUN_1403352f8();
      }
      else {
        fVar15 = SQRT(fVar15 + fVar16);
      }
      if (DAT_14053ad1c < fVar15) {
        iVar8 = 1;
        if (DAT_140e419b8 == 0) {
          iVar8 = 0x12;
        }
        else if (DAT_140e419b8 == 1) {
          iVar8 = 0xe;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar8 = 0xc;
        }
        else if (DAT_140e419b8 == 4) {
          iVar8 = 8;
        }
        iVar10 = 1;
        if (DAT_140e419b8 == 0) {
          iVar10 = 0x20;
        }
        else if (DAT_140e419b8 == 1) {
          iVar10 = 0x18;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar10 = 0x10;
        }
        else if (DAT_140e419b8 == 4) {
          iVar10 = 8;
        }
        if (DAT_140e419b8 == 0) {
          uVar19 = (undefined4)DAT_14053a0d0;
          uVar20 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
        }
        else if (DAT_140e419b8 == 1) {
          uVar19 = (undefined4)DAT_14053a118;
          uVar20 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
        }
        else if (DAT_140e419b8 == 2) {
          uVar19 = (undefined4)DAT_14053a158;
          uVar20 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
        }
        else if (DAT_140e419b8 == 3) {
          uVar19 = (undefined4)DAT_14053a178;
          uVar20 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
        }
        else if (DAT_140e419b8 == 4) {
          uVar19 = (undefined4)DAT_14053a1d0;
          uVar20 = (undefined4)((ulonglong)DAT_14053a1d0 >> 0x20);
        }
        if (3 < DAT_1407c7798) {
          iVar8 = 1;
          if (DAT_140e419b8 == 0) {
            iVar8 = 0x10;
          }
          else if (DAT_140e419b8 == 1) {
            iVar8 = 0xc;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            iVar8 = 8;
          }
          iVar10 = 1;
          if (DAT_140e419b8 == 0) {
            iVar10 = 0x1b;
          }
          else if (DAT_140e419b8 == 1) {
            iVar10 = 0x14;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            iVar10 = 0xd;
          }
          else if (DAT_140e419b8 == 4) {
            iVar10 = 8;
          }
        }
        if (((iVar8 <= iVar2) && (iVar2 < 0x5a)) &&
           (uVar3 = (longlong)(iVar2 - iVar8) % (longlong)iVar10, (int)uVar3 == 0)) {
          auVar25._12_4_ = in_stack_ffffffffffffff38._12_4_;
          auVar25._0_8_ = in_stack_ffffffffffffff38._0_8_;
          auVar25._8_4_ = 1;
          auVar26._8_8_ = auVar25._8_8_;
          auVar26._0_8_ = CONCAT44(uVar20,uVar19);
          uVar24 = 0;
          FUN_14006c2f0(0xe,uVar3 & 0xffffffff,fVar21,fVar22,CONCAT22(uVar23,uVar12),0,
                        CONCAT44(uVar20,uVar19),auVar26._8_8_,0);
          if (2 < DAT_140e419b8) {
            auVar27._12_4_ = auVar26._12_4_;
            auVar27._0_8_ = auVar26._0_8_;
            auVar27._8_4_ = 1;
            uVar24 = 0;
            FUN_14006c2f0(0xe,0,param_1[10],param_1[0xb],uVar13 & 0xffff,0,
                          (double)CONCAT44(uVar20,uVar19) - DAT_140539fc8,auVar27._8_8_,0);
          }
        }
      }
    }
    auVar4._8_4_ = SUB84(dVar5,0);
    auVar4._0_8_ = dVar5;
    auVar4._12_4_ = (int)((ulonglong)dVar5 >> 0x20);
    uVar13 = CONCAT22(uVar24,*(undefined2 *)((longlong)param_1 + 0x42));
    FUN_1400c8410(DAT_140e446a4,0x23,7,param_1[10],param_1[0xb],uVar13,auVar4,0xff,0xff,0xff,0xff,1,
                  0);
    FUN_1400c8410(DAT_140e446a8,0x23,7,param_1[10],param_1[0xb],uVar13 & 0xffff0000,auVar6,0xff,0xff
                  ,0xff,0xff,1,0);
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


