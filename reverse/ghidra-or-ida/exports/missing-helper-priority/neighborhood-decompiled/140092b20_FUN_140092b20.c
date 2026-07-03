// Function: FUN_140092b20 @ 140092b20
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140092b20(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  undefined4 uVar9;
  uint uVar10;
  short sVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  double dVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined4 uVar23;
  undefined2 uVar24;
  uint in_stack_ffffffffffffff10;
  undefined4 uVar25;
  undefined2 uVar26;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  
  uVar24 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  dVar12 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar26 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
  dVar12 = dVar12 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar5;
    dVar14 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_ffffffffffffff18._8_4_ = SUB84(dVar14,0);
    in_stack_ffffffffffffff18._0_8_ = dVar14;
    in_stack_ffffffffffffff18._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff10,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,0xff,1,0);
    uVar26 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
    uVar24 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar15 = DAT_14053a020;
  dVar14 = DAT_140539d28;
  if (param_1[5] == 1) {
    uVar10 = param_1[3];
    dVar13 = (double)FUN_140332d90(((double)(int)uVar10 - 0.0) * DAT_14053a908 * DAT_14053a020 *
                                   DAT_140539d28);
    fVar22 = (float)(dVar13 + dVar13) - DAT_14053ac18;
    dVar14 = (double)FUN_140332d90(((double)(int)uVar10 - _DAT_14053a298) * DAT_14053a908 * dVar15 *
                                   dVar14);
    fVar16 = (float)(dVar14 + dVar14) + 0.0;
    dVar15 = (double)FUN_140332d90();
    dVar15 = dVar15 * _DAT_14053a9c0;
    dVar13 = (double)FUN_140332d90();
    dVar13 = dVar13 * _DAT_14053a9c0;
    dVar14 = *(double *)(param_1 + 0x12);
    if ((uVar10 < 0x79) && (DAT_140539f68 < dVar14)) {
      dVar14 = dVar14 - DAT_140539e60;
    }
    uVar8 = *(ushort *)(param_1 + 0x10);
    iVar6 = ((int)dVar12 & 0xffffU) - (uint)uVar8;
    *(double *)(param_1 + 0x12) = dVar14;
    iVar4 = iVar6 + 0x10000;
    if (-0x8001 < iVar6) {
      iVar4 = iVar6;
    }
    iVar6 = iVar4 + -0x10000;
    if (iVar4 < 0x8001) {
      iVar6 = iVar4;
    }
    uVar1 = (ushort)(int)dVar12;
    if (iVar6 < 1) {
      uVar7 = uVar8;
      if ((iVar6 < 0) && (uVar7 = uVar8 - 0x80, -0x80 < iVar6)) {
        uVar7 = uVar1;
      }
    }
    else {
      uVar7 = uVar1;
      if (0x7f < iVar6) {
        uVar7 = uVar8 + 0x80;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar7;
    if (0x121 < (int)uVar10) {
      dVar14 = dVar14 - DAT_140539e60;
      *(double *)(param_1 + 0x12) = dVar14;
    }
    dVar12 = (double)FUN_1403307c0();
    fVar21 = (float)(dVar12 * dVar14) + (float)param_1[10];
    param_1[10] = fVar21;
    dVar12 = (double)FUN_140332d90();
    auVar2 = _DAT_14053bb20;
    uVar18 = (undefined4)DAT_14053bb20;
    uVar19 = DAT_14053bb20._4_4_;
    fVar20 = (float)(dVar12 * dVar14) + (float)param_1[0xb];
    param_1[0xb] = fVar20;
    if (uVar10 - 0x18 < 0x10a) {
      fVar20 = (fVar20 - DAT_14053aa20) + fVar22;
      dVar12 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar20),
                                     SUB84((double)(DAT_140e445d8 - fVar21),0));
      dVar12 = dVar12 * DAT_14053aba0;
      iVar4 = 1;
      uVar10 = (int)(uVar10 - 0x18) % 0x78;
      if (DAT_140e419b8 == 0) {
        iVar4 = 0x10;
      }
      else if (DAT_140e419b8 == 1) {
        iVar4 = 0x18;
      }
      else if (DAT_140e419b8 == 2) {
        iVar4 = 0x1c;
      }
      else if (DAT_140e419b8 == 3) {
        iVar4 = 0x20;
      }
      else if (DAT_140e419b8 == 4) {
        iVar4 = 0x24;
      }
      uVar9 = 1;
      if (DAT_140e419b8 == 0) {
        uVar9 = 3;
      }
      else if (DAT_140e419b8 == 1) {
        uVar9 = 5;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar9 = 7;
      }
      else if (DAT_140e419b8 == 4) {
        uVar9 = 9;
      }
      iVar6 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar6 = 0x140;
      }
      else if (DAT_140e419b8 == 2) {
        iVar6 = 0x15e;
      }
      else if (DAT_140e419b8 == 3) {
        iVar6 = 0x1c2;
      }
      else if (DAT_140e419b8 == 4) {
        iVar6 = 600;
      }
      if (DAT_140e419b8 == 0) {
        uVar18 = (undefined4)DAT_14053a0f8;
        uVar19 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar18 = (undefined4)DAT_14053a138;
        uVar19 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar18 = (undefined4)DAT_14053a158;
        uVar19 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar18 = (undefined4)DAT_14053a1e8;
        uVar19 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar18 = (undefined4)DAT_14053a208;
        uVar19 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
      }
      uVar8 = (ushort)(int)dVar12;
      if ((uVar10 == 0) || (uVar10 == 0x28)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar8;
      }
      if ((-1 < (int)uVar10) && ((int)uVar10 < iVar4)) {
        uVar3 = uVar10 & 0x80000003;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
        }
        if (uVar3 == 0) {
          iVar4 = (int)(uVar10 + ((int)uVar10 >> 0x1f & 3U)) >> 2;
          auVar27._12_4_ = in_stack_ffffffffffffff18._12_4_;
          auVar27._0_8_ = in_stack_ffffffffffffff18._0_8_;
          auVar27._8_4_ = 1;
          in_stack_ffffffffffffff18._8_8_ = auVar27._8_8_;
          in_stack_ffffffffffffff18._0_8_ = CONCAT44(uVar19,uVar18);
          uVar23 = CONCAT22(uVar24,*(undefined2 *)((longlong)param_1 + 0x42));
          uVar25 = DAT_14053ac2c;
          FUN_1400709b0(9,0,fVar21,fVar20,uVar23,DAT_14053ac2c,CONCAT44(uVar19,uVar18),
                        in_stack_ffffffffffffff18._8_8_,iVar4 + 1,iVar4 * iVar6,0);
          uVar26 = (undefined2)((uint)uVar25 >> 0x10);
          uVar24 = (undefined2)((uint)uVar23 >> 0x10);
        }
      }
      if (uVar10 - 0x28 < 0x1e) {
        uVar3 = uVar10 - 0x28 & 0x80000003;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
        }
        if (uVar3 == 0) {
          auVar28._12_4_ = in_stack_ffffffffffffff18._12_4_;
          auVar28._0_8_ = in_stack_ffffffffffffff18._0_8_;
          auVar28._8_4_ = 1;
          dVar17 = ((double)(int)uVar10 - DAT_14053a340) * DAT_140539e60 +
                   (double)CONCAT44(uVar19,uVar18);
          dVar14 = dVar17 + auVar2._0_8_;
          auVar29._8_8_ = auVar28._8_8_;
          auVar29._0_8_ = dVar14;
          uVar26 = 0;
          FUN_1400709b0(8,0,fVar21,fVar20,CONCAT22(uVar24,*(undefined2 *)((longlong)param_1 + 0x42))
                        ,0,dVar14,auVar29._8_8_,uVar9,20000,0);
          if (2 < DAT_140e419b8) {
            auVar30._12_4_ = auVar29._12_4_;
            auVar30._0_8_ = auVar29._0_8_;
            auVar30._8_4_ = 1;
            uVar26 = 0;
            FUN_1400709b0(8,0,fVar21,fVar20,*(undefined2 *)((longlong)param_1 + 0x42),0,
                          dVar17 - DAT_140539fc8,auVar30._8_8_,uVar9,20000,0);
          }
        }
      }
      uVar1 = *(ushort *)((longlong)param_1 + 0x42);
      iVar6 = ((int)dVar12 & 0xffffU) - (uint)uVar1;
      iVar4 = iVar6 + 0x10000;
      if (-0x8001 < iVar6) {
        iVar4 = iVar6;
      }
      iVar6 = iVar4 + -0x10000;
      if (iVar4 < 0x8001) {
        iVar6 = iVar4;
      }
      if (iVar6 < 1) {
        uVar7 = uVar1;
        if ((iVar6 < 0) && (uVar7 = uVar1 - 0x20, -0x20 < iVar6)) {
          uVar7 = uVar8;
        }
      }
      else {
        uVar7 = uVar8;
        if (0x1f < iVar6) {
          uVar7 = uVar1 + 0x20;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar7;
    }
    sVar11 = (short)(int)dVar13;
    uVar18 = CONCAT22(uVar26,sVar11);
    FUN_1400c8410(DAT_140e44bd8,0x20,7,(float)param_1[10] + DAT_14053ac80,
                  fVar16 + (float)param_1[0xb],uVar18,auVar2,0xff,0xff,0xff,0xff,1,0);
    uVar18 = CONCAT22((short)((uint)uVar18 >> 0x10),-sVar11);
    FUN_1400c8410(DAT_140e44bd8,0x20,7,(float)param_1[10] - DAT_14053ac80,
                  fVar16 + (float)param_1[0xb],uVar18,auVar2,0xff,0xff,0xff,0xff,1,1);
    sVar11 = (short)(int)dVar15;
    uVar18 = CONCAT22((short)((uint)uVar18 >> 0x10),sVar11);
    FUN_1400c8410(DAT_140e44bd4,0x20,7,(float)param_1[10] + DAT_14053ac60,
                  fVar16 + (float)param_1[0xb] + DAT_14053acfc,uVar18,auVar2,0xff,0xff,0xff,0xff,1,0
                 );
    uVar10 = CONCAT22((short)((uint)uVar18 >> 0x10),-sVar11);
    FUN_1400c8410(DAT_140e44bd4,0x20,7,(float)param_1[10] - DAT_14053ac60,
                  fVar16 + (float)param_1[0xb] + DAT_14053acfc,uVar10,auVar2,0xff,0xff,0xff,0xff,1,1
                 );
    uVar10 = uVar10 & 0xffff0000;
    FUN_1400c8410(DAT_140e44bd0,0x20,7,param_1[10],fVar16 + (float)param_1[0xb],uVar10,auVar2,0xff,
                  0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44bcc,0x20,7,param_1[10],fVar22 + (float)param_1[0xb],uVar10 & 0xffff0000,
                  auVar2,0xff,0xff,0xff,0xff,1,0);
    FUN_140079c10(param_1,1);
  }
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


