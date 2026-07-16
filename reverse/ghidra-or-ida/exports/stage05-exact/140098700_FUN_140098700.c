// Function: FUN_140098700 @ 140098700
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140098700(undefined4 *param_1)

{
  double dVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined1 auVar4 [16];
  ushort uVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  undefined4 in_stack_fffffffffffffef8;
  undefined2 uVar20;
  undefined4 in_stack_ffffffffffffff00;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined2 uVar23;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  
  uVar20 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  fVar19 = (float)param_1[10];
  dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - fVar19));
  dVar1 = DAT_14053a020;
  dVar17 = DAT_140539d28;
  dVar14 = dVar14 * DAT_14053aba0;
  dVar15 = (double)FUN_140332d90(((double)DAT_140e44acc - (double)(param_1[1] * 0xd)) *
                                 DAT_14053a858 * DAT_14053a020 * DAT_140539d28);
  dVar15 = dVar15 * _DAT_14053a810;
  uVar12 = param_1[3];
  dVar16 = (double)FUN_140332d90(((double)(int)uVar12 - 0.0) * _DAT_14053a8e8 * dVar1 * dVar17);
  dVar7 = DAT_14053a558;
  dVar6 = DAT_140539f40;
  uVar23 = (undefined2)((uint)in_stack_ffffffffffffff00 >> 0x10);
  dVar16 = dVar16 * _DAT_140539e28 + 0.0 + DAT_140539f40;
  if (param_1[5] != 0) goto LAB_140098ac7;
  if (uVar12 < 0x5a) {
    FUN_140332d90(((double)(int)uVar12 - 0.0) * DAT_14053a558 * dVar1 * dVar17);
LAB_140098894:
    dVar16 = (double)FUN_140332d90();
    uVar8 = 0x5a - (int)(dVar16 * DAT_14053a430);
  }
  else {
    uVar8 = (int)uVar12 >> 0x1f & 0x5a;
    if ((-1 < (int)uVar12) && ((int)uVar12 < 0x5a)) goto LAB_140098894;
  }
  if (uVar12 == 0) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
    FUN_14018a340(DAT_140e472bc,1,1);
  }
  uVar22 = DAT_14053ad9c;
  uVar23 = (undefined2)((uint)in_stack_ffffffffffffff00 >> 0x10);
  uVar12 = param_1[3];
  if (uVar12 == 0x3c) {
    uVar12 = 1;
    if (DAT_140e419b8 == 0) {
      uVar12 = 5;
    }
    else if (DAT_140e419b8 == 1) {
      uVar12 = 7;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      uVar12 = 9;
    }
    else if (DAT_140e419b8 == 4) {
      uVar12 = 8;
    }
    param_1[0x17] = uVar12;
    iVar11 = 0;
    do {
      auVar24._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar24._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar24._8_4_ = 0x23;
      in_stack_ffffffffffffff08._8_8_ = 0;
      in_stack_ffffffffffffff08._0_8_ = auVar24._8_8_;
      in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 << 0x40;
      in_stack_ffffffffffffff00 =
           CONCAT22((short)((uint)in_stack_ffffffffffffff00 >> 0x10),
                    (short)iVar11 * (short)(0x10000 / (ulonglong)uVar12) + -0x4000);
      uVar20 = 0;
      stage_entity_spawn_candidate
                (0x49,0x4b0,5,uVar22,0,in_stack_ffffffffffffff00,0,auVar24._8_8_,1,param_1[1]);
      uVar23 = (undefined2)((uint)in_stack_ffffffffffffff00 >> 0x10);
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)uVar12);
    uVar12 = param_1[3];
  }
  if (((param_1[6] == 0x48) && (-1 < (int)uVar12)) && ((int)uVar12 < 0x5a)) {
    FUN_140332d90(((double)(int)uVar12 - 0.0) * dVar7 * dVar1 * dVar17);
  }
  if ((int)uVar12 < 0) {
    dVar16 = 0.0;
  }
  else {
    dVar16 = dVar6;
    if ((int)uVar12 < 0x5a) {
      dVar16 = (double)FUN_140332d90(((double)(int)uVar12 - 0.0) * dVar7 * dVar1 * dVar17);
      dVar16 = dVar16 + 0.0;
    }
  }
  dVar17 = (double)FUN_1403307c0();
  fVar19 = (float)(dVar17 * (double)(int)uVar8) + (float)param_1[0xc];
  dVar17 = (double)FUN_140332d90();
  param_1[10] = fVar19;
  param_1[0xb] = (float)(dVar17 * (double)(int)uVar8) + (float)param_1[0xd];
  if (uVar12 == 0x5a) {
    param_1[5] = param_1[5] + 1;
    *(undefined8 *)(param_1 + 0x12) = 0x3fe0000000000000;
    uVar12 = 0;
    param_1[0x15] = 0;
    param_1[3] = 0;
  }
LAB_140098ac7:
  dVar17 = DAT_140539e60;
  if (param_1[5] == 1) {
    dVar1 = *(double *)(param_1 + 0x12);
    if ((uVar12 < 0x79) && (DAT_140539f68 < dVar1)) {
      dVar1 = dVar1 - DAT_140539e60;
    }
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar9 = ((int)dVar14 & 0xffffU) - (uint)uVar2;
    *(double *)(param_1 + 0x12) = dVar1;
    iVar11 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar11 = iVar9;
    }
    iVar9 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar9 = iVar11;
    }
    uVar5 = (ushort)(int)dVar14;
    if (iVar9 < 1) {
      uVar10 = uVar2;
      if ((iVar9 < 0) && (uVar10 = uVar2 - 0x80, -0x80 < iVar9)) {
        uVar10 = uVar5;
      }
    }
    else {
      uVar10 = uVar5;
      if (0x7f < iVar9) {
        uVar10 = uVar2 + 0x80;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar10;
    if (299 < (int)uVar12) {
      dVar1 = dVar1 - dVar17;
      *(double *)(param_1 + 0x12) = dVar1;
    }
    dVar17 = (double)FUN_1403307c0();
    fVar19 = (float)(dVar17 * dVar1) + fVar19;
    param_1[10] = fVar19;
    dVar17 = (double)FUN_140332d90();
    fVar18 = (float)(dVar17 * dVar1) + (float)param_1[0xb];
    param_1[0xb] = fVar18;
    if (uVar12 - 0x50 < 0xdc) {
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18),
                                     (double)(DAT_140e445d8 - fVar19));
      uVar22 = DAT_14053ac2c;
      iVar11 = 1;
      dVar17 = dVar17 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x96;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x78;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar11 = 0x5a;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x46;
      }
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 3;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 5;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar9 = 7;
      }
      else if (DAT_140e419b8 == 4) {
        iVar9 = 9;
      }
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0x12c0;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0xe10;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar13 = 0x834;
      }
      else if (DAT_140e419b8 == 4) {
        iVar13 = 0x708;
      }
      dVar1 = DAT_14053a070;
      if ((((DAT_140e419b8 != 0) && (dVar1 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
          (dVar1 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
         ((dVar1 = DAT_14053a118, DAT_140e419b8 != 3 && (dVar1 = dVar6, DAT_140e419b8 == 4)))) {
        dVar1 = DAT_14053a158;
      }
      if ((param_1[3] - 0x50 < 0xdc) &&
         (uVar3 = (longlong)(param_1[3] + -0x50) % (longlong)iVar11, (int)uVar3 == 0)) {
        auVar25._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar25._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar25._8_4_ = 1;
        auVar26._8_8_ = auVar25._8_8_;
        auVar26._0_8_ = dVar1;
        uVar21 = DAT_14053ac2c;
        FUN_1400709b0(0xb,uVar3 & 0xffffffff,fVar19,fVar18,CONCAT22(uVar20,(short)(int)dVar17),
                      DAT_14053ac2c,dVar1,auVar26._8_8_,iVar9,(iVar9 + -1) * iVar13,0);
        uVar23 = (undefined2)((uint)uVar21 >> 0x10);
        if (2 < DAT_140e419b8) {
          auVar27._12_4_ = auVar26._12_4_;
          auVar27._0_8_ = auVar26._0_8_;
          auVar27._8_4_ = 1;
          FUN_1400709b0(0xb,0,param_1[10],param_1[0xb],(int)dVar17 & 0xffff,uVar22,
                        dVar1 - DAT_140539f90,auVar27._8_8_,iVar9,
                        (int)((double)iVar13 * _DAT_140539f88) * (iVar9 + -1),0);
          uVar23 = (undefined2)((uint)uVar22 >> 0x10);
        }
      }
    }
    FUN_140079c10(param_1,1);
  }
  auVar4._8_4_ = SUB84(dVar16,0);
  auVar4._0_8_ = dVar16;
  auVar4._12_4_ = (int)((ulonglong)dVar16 >> 0x20);
  FUN_1400c8410(DAT_140e44c14,0x21,7,param_1[10],param_1[0xb],CONCAT22(uVar23,(short)(int)dVar15),
                auVar4,0xff,0xff,0xff,0xff,1,0);
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


