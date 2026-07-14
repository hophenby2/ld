// Function: FUN_1400853f0 @ 1400853f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400853f0(undefined4 *param_1)

{
  ushort uVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  ushort uVar12;
  short sVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  double dVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined2 uVar27;
  uint in_stack_ffffffffffffff10;
  float fVar28;
  undefined2 uVar29;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  
  uVar27 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar29 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
  dVar16 = dVar16 * DAT_14053aba0;
  if (param_1[5] == 0) {
    uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar6;
    dVar17 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
    in_stack_ffffffffffffff18._8_4_ = SUB84(dVar17,0);
    in_stack_ffffffffffffff18._0_8_ = dVar17;
    in_stack_ffffffffffffff18._12_4_ = (int)((ulonglong)dVar17 >> 0x20);
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff10,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,0xff,1,0);
    uVar29 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
    uVar27 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140085ed8;
  uVar5 = param_1[3];
  dVar17 = (double)FUN_140332d90(((double)(int)uVar5 - 0.0) * DAT_14053a8c0 * DAT_14053a020 *
                                 DAT_140539d28);
  uVar6 = _UNK_14053bb28;
  dVar3 = _DAT_14053bb20;
  dVar18 = dVar17 * _DAT_140539e28 + _DAT_14053bb20;
  dVar19 = (double)FUN_140332d90();
  dVar19 = dVar19 * _DAT_14053aa90;
  dVar17 = (double)FUN_1403307c0();
  fVar14 = (float)(dVar17 * DAT_14053a278) + 0.0;
  dVar20 = (double)FUN_140332d90();
  dVar22 = DAT_140539e60;
  dVar17 = *(double *)(param_1 + 0x12);
  fVar21 = (float)(dVar20 * DAT_14053a278) + 0.0;
  if ((uVar5 < 0x79) && (DAT_140539f90 < dVar17)) {
    dVar17 = dVar17 - DAT_140539e60;
  }
  uVar12 = *(ushort *)(param_1 + 0x10);
  iVar7 = ((int)dVar16 & 0xffffU) - (uint)uVar12;
  *(double *)(param_1 + 0x12) = dVar17;
  iVar4 = iVar7 + 0x10000;
  if (-0x8001 < iVar7) {
    iVar4 = iVar7;
  }
  iVar7 = iVar4 + -0x10000;
  if (iVar4 < 0x8001) {
    iVar7 = iVar4;
  }
  uVar1 = (ushort)(int)dVar16;
  if (iVar7 < 1) {
    uVar8 = uVar12;
    if ((iVar7 < 0) && (uVar8 = uVar12 - 0x80, -0x80 < iVar7)) {
      uVar8 = uVar1;
    }
  }
  else {
    uVar8 = uVar1;
    if (0x7f < iVar7) {
      uVar8 = uVar12 + 0x80;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar8;
  if (0xef < (int)uVar5) {
    dVar17 = dVar17 - dVar22;
    *(double *)(param_1 + 0x12) = dVar17;
  }
  dVar16 = (double)FUN_1403307c0();
  fVar24 = (float)(dVar16 * dVar17) + (float)param_1[10];
  param_1[10] = fVar24;
  dVar16 = (double)FUN_140332d90();
  fVar2 = DAT_14053ac2c;
  fVar25 = (float)(dVar16 * dVar17) + (float)param_1[0xb];
  param_1[0xb] = fVar25;
  fVar28 = DAT_140e445dc;
  if (uVar5 - 0x18 < 0xd8) {
    fVar15 = (float)dVar18;
    fVar26 = fVar15 * DAT_14053acd8 + fVar25;
    fVar25 = fVar25 - fVar15 * DAT_14053acbc;
    uVar23 = SUB84((double)(DAT_140e445d8 - fVar24),0);
    dVar16 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),uVar23);
    dVar16 = dVar16 * DAT_14053aba0;
    dVar17 = (double)FUN_1403300b4((double)(fVar28 - fVar25),uVar23);
    iVar4 = DAT_140e419b8;
    iVar7 = 1;
    dVar17 = dVar17 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar7 = 0x78;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 0x50;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar7 = 0x46;
    }
    else if (DAT_140e419b8 == 4) {
      iVar7 = 0x3c;
    }
    iVar10 = 1;
    iVar7 = (int)(uVar5 - 0x18) % iVar7;
    if (DAT_140e419b8 == 0) {
      iVar10 = 3;
    }
    else if (DAT_140e419b8 == 1) {
      iVar10 = 5;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar10 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      iVar10 = 9;
    }
    dVar22 = DAT_14053a070;
    if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
        (dVar22 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
       ((dVar22 = DAT_14053a0f8, DAT_140e419b8 != 3 && (dVar22 = dVar3, DAT_140e419b8 == 4)))) {
      dVar22 = DAT_14053a140;
    }
    iVar9 = 1;
    if (DAT_140e419b8 == 0) {
      iVar9 = 0;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0x708;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar9 = 0x12c0;
    }
    else if (DAT_140e419b8 == 4) {
      iVar9 = 0x1130;
    }
    dVar20 = DAT_14053a0d0;
    if ((((DAT_140e419b8 != 0) && (dVar20 = DAT_14053a118, DAT_140e419b8 != 1)) &&
        (dVar20 = DAT_14053a138, DAT_140e419b8 != 2)) &&
       ((dVar20 = DAT_14053a158, DAT_140e419b8 != 3 && (dVar20 = dVar3, DAT_140e419b8 == 4)))) {
      dVar20 = DAT_14053a1c8;
    }
    auVar30._12_4_ = in_stack_ffffffffffffff18._12_4_;
    auVar30._0_8_ = in_stack_ffffffffffffff18._0_8_;
    if (iVar7 == 0) {
      auVar30._8_4_ = 1;
      auVar31._8_8_ = auVar30._8_8_;
      auVar31._0_8_ = dVar22;
      uVar29 = 0;
      FUN_1400709b0(5,0,fVar24,fVar26,CONCAT22(uVar27,(short)(int)dVar16),0,dVar22,auVar31._8_8_,
                    iVar10,iVar10 * 300 + -300,0);
      if (2 < DAT_140e419b8) {
        auVar32._12_4_ = auVar31._12_4_;
        auVar32._0_8_ = auVar31._0_8_;
        auVar32._8_4_ = 1;
        uVar29 = 0;
        FUN_1400709b0(5,0,fVar24,fVar26,(int)dVar16 & 0xffff,0,dVar22 - DAT_140539f00,auVar32._8_8_,
                      iVar10,iVar10 * 0x1c2 + -0x1c2,0);
      }
    }
    else {
      uVar12 = (ushort)(int)dVar17;
      if (iVar7 == 0x1e) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar12;
LAB_1400859f6:
        puVar11 = (undefined2 *)((longlong)param_1 + 0x42);
        dVar20 = ((double)iVar7 - DAT_14053a2d8) * _DAT_140539e28 + dVar20;
        if (DAT_1407c7798 < 8) {
          auVar33._8_4_ = 1;
          auVar33._0_8_ = auVar30._0_8_;
          auVar33._12_4_ = auVar30._12_4_;
          auVar34._8_8_ = auVar33._8_8_;
          auVar34._0_8_ = dVar20;
          uVar23 = CONCAT22(uVar27,*puVar11);
          fVar28 = fVar2;
          FUN_14006c2f0(0,0,fVar24,fVar25,uVar23,fVar2,dVar20,auVar34._8_8_,0);
          uVar29 = (undefined2)((uint)fVar28 >> 0x10);
          uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          if (0 < DAT_140e419b8) {
            auVar35._12_4_ = auVar34._12_4_;
            auVar35._0_8_ = auVar34._0_8_;
            auVar35._8_4_ = 1;
            auVar34._8_8_ = auVar35._8_8_;
            auVar34._0_8_ = dVar20 - DAT_140539f00;
            uVar23 = CONCAT22(uVar27,*puVar11);
            fVar28 = fVar2;
            FUN_1400709b0(0,0,fVar24,fVar25,uVar23,fVar2,dVar20 - DAT_140539f00,auVar34._8_8_,2,
                          iVar9,0);
            uVar29 = (undefined2)((uint)fVar28 >> 0x10);
            uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          }
          if (2 < DAT_140e419b8) {
            auVar36._12_4_ = auVar34._12_4_;
            auVar36._0_8_ = auVar34._0_8_;
            auVar36._8_4_ = 1;
            auVar37._8_8_ = auVar36._8_8_;
            auVar37._0_8_ = dVar20 + DAT_140539ff0;
            uVar23 = CONCAT22(uVar27,*puVar11);
            FUN_14006c2f0(0,0,fVar24,fVar25,uVar23,fVar2,dVar20 + DAT_140539ff0,auVar37._8_8_,0);
            auVar38._12_4_ = auVar37._12_4_;
            auVar38._0_8_ = auVar37._0_8_;
            auVar38._8_4_ = 1;
            auVar34._8_8_ = auVar38._8_8_;
            auVar34._0_8_ = dVar20 + DAT_140539fc8;
            uVar23 = CONCAT22((short)((uint)uVar23 >> 0x10),*puVar11);
            fVar28 = fVar2;
            FUN_1400709b0(0,0,fVar24,fVar25,uVar23,fVar2,dVar20 + DAT_140539fc8,auVar34._8_8_,2,
                          iVar9,0);
            uVar29 = (undefined2)((uint)fVar28 >> 0x10);
            uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          }
          if (3 < DAT_140e419b8) {
            auVar39._12_4_ = auVar34._12_4_;
            auVar39._0_8_ = auVar34._0_8_;
            auVar39._8_4_ = 1;
            fVar28 = fVar2;
            FUN_1400709b0(0,0,fVar24,fVar25,
                          CONCAT22(uVar27,*(undefined2 *)((longlong)param_1 + 0x42)),fVar2,
                          dVar20 + DAT_140539f90,auVar39._8_8_,2,iVar9 * 3,0);
            uVar29 = (undefined2)((uint)fVar28 >> 0x10);
          }
        }
        else {
          uVar23 = 1;
          if (iVar4 == 0) {
            uVar23 = 5;
          }
          else if (iVar4 == 1) {
            uVar23 = 7;
          }
          else if ((iVar4 == 2) || (iVar4 == 3)) {
            uVar23 = 9;
          }
          else if (iVar4 == 4) {
            uVar23 = 0xb;
          }
          auVar40._8_4_ = 1;
          auVar40._0_8_ = auVar30._0_8_;
          auVar40._12_4_ = auVar30._12_4_;
          auVar41._8_8_ = auVar40._8_8_;
          auVar41._0_8_ = dVar20;
          fVar28 = fVar2;
          FUN_1400709b0(0,0,fVar24,fVar25,CONCAT22(uVar27,*puVar11),fVar2,dVar20,auVar41._8_8_,
                        uVar23,25000,0);
          uVar29 = (undefined2)((uint)fVar28 >> 0x10);
          if (2 < DAT_140e419b8) {
            uVar23 = 1;
            if (DAT_140e419b8 == 0) {
              uVar23 = 5;
            }
            else if (DAT_140e419b8 == 1) {
              uVar23 = 7;
            }
            else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
              uVar23 = 9;
            }
            else if (DAT_140e419b8 == 4) {
              uVar23 = 0xb;
            }
            auVar42._12_4_ = auVar41._12_4_;
            auVar42._0_8_ = auVar41._0_8_;
            auVar42._8_4_ = 1;
            fVar28 = fVar2;
            FUN_1400709b0(0,0,fVar24,fVar25,*(undefined2 *)((longlong)param_1 + 0x42),fVar2,
                          dVar20 + DAT_140539fc8,auVar42._8_8_,uVar23,25000,0);
            uVar29 = (undefined2)((uint)fVar28 >> 0x10);
          }
        }
        uVar1 = *(ushort *)((longlong)param_1 + 0x42);
        iVar7 = ((int)dVar17 & 0xffffU) - (uint)uVar1;
        iVar4 = iVar7 + 0x10000;
        if (-0x8001 < iVar7) {
          iVar4 = iVar7;
        }
        iVar7 = iVar4 + -0x10000;
        if (iVar4 < 0x8001) {
          iVar7 = iVar4;
        }
        if (iVar7 < 1) {
          uVar8 = uVar1;
          if ((iVar7 < 0) && (uVar8 = uVar1 - 0x40, -0x40 < iVar7)) {
            uVar8 = uVar12;
          }
        }
        else {
          uVar8 = uVar12;
          if (0x3f < iVar7) {
            uVar8 = uVar1 + 0x40;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar8;
      }
      else if (iVar7 - 0x1eU < 0x1e) {
        uVar5 = iVar7 - 0x1eU & 0x80000003;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
        }
        if (uVar5 == 0) goto LAB_1400859f6;
      }
    }
  }
  sVar13 = (short)(int)dVar19;
  uVar23 = CONCAT22(uVar29,sVar13);
  FUN_1400c8410(DAT_140e44b5c,0x20,7,fVar14 + (float)param_1[10] + DAT_14053ac80,
                fVar21 + (float)param_1[0xb] + fVar2,uVar23,dVar3,uVar6,0xff,0xff,0xff,0xff,1,0);
  uVar5 = CONCAT22((short)((uint)uVar23 >> 0x10),-sVar13);
  FUN_1400c8410(DAT_140e44b5c,0x20,7,((float)param_1[10] - fVar14) - DAT_14053ac80,
                fVar21 + (float)param_1[0xb] + fVar2,uVar5,dVar3,uVar6,0xff,0xff,0xff,0xff,1,1);
  FUN_1400c8410(DAT_140e44b58,0x20,7,param_1[10],param_1[0xb],uVar5 & 0xffff0000,dVar3,dVar18,0xff,
                0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_140085ed8:
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


