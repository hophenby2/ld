// Function: FUN_14008dfb0 @ 14008dfb0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008dfb0(undefined4 *param_1)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auVar5 [16];
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 in_stack_ffffffffffffff18;
  undefined2 uVar23;
  undefined4 in_stack_ffffffffffffff20;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined1 in_stack_ffffffffffffff28 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  ulonglong in_stack_ffffffffffffff38;
  undefined2 uVar26;
  
  auVar5 = _DAT_14053bb20;
  uVar26 = (undefined2)((uint)in_stack_ffffffffffffff20 >> 0x10);
  uVar23 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  uVar13 = (undefined4)DAT_14053bb20;
  uVar19 = DAT_14053bb20._4_4_;
  fVar20 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar20;
  if ((param_1[5] != 0) || (fVar20 < DAT_14053b34c)) {
    if (param_1[5] != 1) goto LAB_14008e593;
  }
  else {
    param_1[5] = 1;
    param_1[3] = 0;
  }
  dVar17 = DAT_14053a020;
  uVar2 = *(ushort *)(param_1 + 0x10);
  uVar10 = (uint)uVar2;
  fVar1 = (float)param_1[10];
  dVar15 = (double)uVar2 * DAT_14053a020 * DAT_140539d28;
  dVar14 = (double)FUN_1403307c0(dVar15);
  dVar14 = dVar14 * DAT_14053a318;
  dVar15 = (double)FUN_140332d90(dVar15);
  dVar15 = dVar15 * DAT_14053a318;
  dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar20),(double)(DAT_140e445d8 - fVar1));
  iVar3 = param_1[3];
  uVar12 = (uint)(dVar16 * DAT_14053aba0);
  if (iVar3 == 0x28) {
    param_1[0x15] = 0;
  }
  uVar6 = (short)uVar12 - uVar2;
  uVar8 = (uint)uVar6;
  if (0x8000 < uVar6) {
    uVar8 = 0x10000 - uVar6;
  }
  iVar7 = (uVar12 & 0xffff) - (uint)uVar2;
  iVar9 = (int)uVar8 / 10 + 0x30;
  iVar11 = iVar7 + 0x10000;
  if (-0x8001 < iVar7) {
    iVar11 = iVar7;
  }
  iVar7 = iVar11 + -0x10000;
  if (iVar11 < 0x8001) {
    iVar7 = iVar11;
  }
  if (iVar7 < 1) {
    if (iVar7 < 0) {
      if (-iVar9 < iVar7) {
        uVar10 = uVar12 & 0xffff;
      }
      else {
        uVar10 = (uint)(ushort)(uVar2 - (short)iVar9);
      }
    }
  }
  else if (iVar7 < iVar9) {
    uVar10 = uVar12 & 0xffff;
  }
  else {
    uVar10 = (uint)(ushort)(uVar2 + (short)iVar9);
  }
  *(short *)(param_1 + 0x10) = (short)uVar10;
  if (0x27 < iVar3) {
    dVar17 = (double)uVar10 * dVar17 * DAT_140539d28;
    dVar16 = (double)FUN_1403307c0(dVar17);
    fVar21 = (float)(dVar16 * _DAT_14053a3f0) + fVar1;
    dVar17 = (double)FUN_140332d90(dVar17);
    uVar25 = DAT_14053ac2c;
    fVar22 = (float)(dVar17 * _DAT_14053a3f0) + fVar20;
    if (fVar20 < DAT_14053ae2c) {
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x3c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x24;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 0x1c;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0x18;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x12;
      }
      if (DAT_140e419b8 == 0) {
        uVar13 = (undefined4)DAT_14053a088;
        uVar19 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar13 = (undefined4)DAT_14053a0d0;
        uVar19 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar13 = (undefined4)DAT_14053a0f8;
        uVar19 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar13 = (undefined4)DAT_14053a118;
        uVar19 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar13 = (undefined4)DAT_14053a190;
        uVar19 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
      }
      if (7 < DAT_1407c7798) {
        iVar11 = 1;
        if (DAT_140e419b8 == 0) {
          iVar11 = 0x30;
        }
        else if (DAT_140e419b8 == 1) {
          iVar11 = 0x20;
        }
        else if (DAT_140e419b8 == 2) {
          iVar11 = 0x1a;
        }
        else if (DAT_140e419b8 == 3) {
          iVar11 = 0x18;
        }
        else if (DAT_140e419b8 == 4) {
          iVar11 = 0x12;
        }
      }
      uVar4 = (longlong)(iVar3 + -0x28) % (longlong)iVar11;
      if ((int)uVar4 == 0) {
        in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
        auVar27._12_4_ = in_stack_ffffffffffffff28._12_4_;
        auVar27._0_8_ = in_stack_ffffffffffffff28._0_8_;
        auVar27._8_4_ = 1;
        auVar28._8_8_ = auVar27._8_8_;
        auVar28._0_8_ = CONCAT44(uVar19,uVar13);
        FUN_14006c2f0(6,uVar4 & 0xffffffff,fVar21,fVar22,CONCAT22(uVar23,(short)uVar10),
                      DAT_14053ac2c,CONCAT44(uVar19,uVar13),auVar28._8_8_,in_stack_ffffffffffffff38)
        ;
        dVar17 = (double)CONCAT44(uVar19,uVar13) + DAT_140539ee0;
        in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
        auVar29._12_4_ = auVar28._12_4_;
        auVar29._0_8_ = auVar28._0_8_;
        auVar29._8_4_ = 1;
        auVar30._8_8_ = auVar29._8_8_;
        auVar30._0_8_ = dVar17;
        uVar24 = uVar25;
        FUN_14006c2f0(6,0,fVar21,fVar22,*(undefined2 *)(param_1 + 0x10),uVar25,dVar17,auVar30._8_8_,
                      in_stack_ffffffffffffff38);
        uVar26 = (undefined2)((uint)uVar24 >> 0x10);
        if (2 < DAT_140e419b8) {
          dVar17 = (double)CONCAT44(uVar19,uVar13) + DAT_140539f10;
          in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
          auVar31._12_4_ = auVar30._12_4_;
          auVar31._0_8_ = auVar30._0_8_;
          auVar31._8_4_ = 1;
          auVar32._8_8_ = auVar31._8_8_;
          auVar32._0_8_ = dVar17;
          FUN_14006c2f0(6,0,fVar21,fVar22,*(undefined2 *)(param_1 + 0x10),uVar25,dVar17,
                        auVar32._8_8_,in_stack_ffffffffffffff38);
          dVar17 = (double)CONCAT44(uVar19,uVar13) + DAT_140539f38;
          in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
          auVar33._12_4_ = auVar32._12_4_;
          auVar33._0_8_ = auVar32._0_8_;
          auVar33._8_4_ = 1;
          auVar34._8_8_ = auVar33._8_8_;
          auVar34._0_8_ = dVar17;
          FUN_14006c2f0(6,0,fVar21,fVar22,*(undefined2 *)(param_1 + 0x10),uVar25,dVar17,
                        auVar34._8_8_,in_stack_ffffffffffffff38);
          in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
          auVar35._12_4_ = auVar34._12_4_;
          auVar35._0_8_ = auVar34._0_8_;
          auVar35._8_4_ = 1;
          FUN_14006c2f0(6,0,fVar21,fVar22,*(undefined2 *)(param_1 + 0x10),uVar25,
                        (double)CONCAT44(uVar19,uVar13) + DAT_140539f68,auVar35._8_8_,
                        in_stack_ffffffffffffff38);
          uVar26 = (undefined2)((uint)uVar25 >> 0x10);
        }
      }
    }
  }
  uVar13 = CONCAT22(uVar26,*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e446c4,0x18,7,(float)param_1[10] + DAT_14053ac18,
                (float)param_1[0xb] + DAT_14053aa20,uVar13,auVar5,
                in_stack_ffffffffffffff38 & 0xffffffff00000000,0,0,0x40,1,0);
  uVar13 = CONCAT22((short)((uint)uVar13 >> 0x10),*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e446c4,0x19,7,param_1[10],param_1[0xb],uVar13,auVar5,0xff,0xff,0xff,0xff,1,0)
  ;
  uVar13 = CONCAT22((short)((uint)uVar13 >> 0x10),*(undefined2 *)(param_1 + 0x10));
  FUN_1400c8410(DAT_140e446c8,0x19,7,(float)dVar14 + fVar1,(float)dVar15 + fVar20,uVar13,auVar5,0xff
                ,0xff,0xff,0xff,1,0);
  uVar26 = (undefined2)((uint)uVar13 >> 0x10);
  FUN_140079c10(param_1,2);
  fVar20 = (float)param_1[0xb];
LAB_14008e593:
  if ((int)param_1[7] < 1) {
    uVar12 = param_1[1] + DAT_140e418c8;
    uVar10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar10 = uVar10 * 0x800 ^ uVar10;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar10 = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
    DAT_140e9fd1c = uVar10;
    uVar18 = FUN_140134db0(uVar12,auVar5._0_8_,DAT_140539f68);
    uVar13 = (undefined4)uVar18;
    uVar19 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar18 = FUN_140134db0(uVar12);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],fVar20,
                  CONCAT22(uVar26,(short)uVar10 - (short)(uVar10 / 0x10001)),auVar5._0_8_,uVar18,
                  CONCAT44(uVar19,uVar13),0x78,0xff,0xff,0xff,0xc0,0);
    FUN_14007b010(param_1,1000,5);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (DAT_14053af48 <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


