// Function: FUN_1400841d0 @ 1400841d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400841d0(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  ushort uVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  int *piVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined4 uVar20;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  float fVar28;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined2 uVar29;
  uint in_stack_ffffffffffffff10;
  undefined2 uVar31;
  uint uVar30;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  
  uVar29 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar31 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
  dVar17 = dVar17 * DAT_14053aba0;
  piVar15 = param_1 + 5;
  if (param_1[5] == 0) {
    uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    dVar18 = DAT_140539fc8 - (double)(int)param_1[3] * DAT_140539e60;
    uStackX_c = (undefined4)(uVar6 >> 0x20);
    in_stack_ffffffffffffff18._8_4_ = SUB84(dVar18,0);
    in_stack_ffffffffffffff18._0_8_ = dVar18;
    in_stack_ffffffffffffff18._12_4_ = (int)((ulonglong)dVar18 >> 0x20);
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,uVar6 & 0xffffffff,uStackX_c,in_stack_ffffffffffffff10,
                  in_stack_ffffffffffffff18,0xff,0xff,0xff,0xff,1,0);
    uVar29 = (undefined2)((uint)uStackX_c >> 0x10);
    uVar31 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
    piVar15 = param_1 + 5;
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x3ff6666666666666;
      if ((float)param_1[10] <= 0.0) {
        *(undefined2 *)(param_1 + 0x10) = 0;
      }
      if (DAT_14053af14 <= (float)param_1[10]) {
        *(undefined2 *)(param_1 + 0x10) = 0x8000;
      }
      piVar15 = param_1 + 5;
      uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      *piVar15 = *piVar15 + 1;
      local_res8 = (undefined4)uVar7;
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  if (*piVar15 == 1) {
    iVar12 = param_1[3];
    fVar1 = (float)param_1[0xb];
    fVar2 = (float)param_1[10];
    fVar28 = fVar1 + DAT_14053ac2c;
    dVar18 = (double)FUN_140332d90(((double)iVar12 - 0.0) * _DAT_14053a978 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar18 = dVar18 * DAT_140539e60 + DAT_140539f40;
    dVar19 = (double)FUN_140332d90();
    sVar13 = (short)(int)(dVar19 * _DAT_14053ab28) + -8000;
    dVar19 = (double)FUN_1403307c0();
    fVar16 = (float)(dVar19 * DAT_14053a340) + 0.0;
    dVar19 = (double)FUN_140332d90();
    uVar3 = *(ushort *)(param_1 + 0x10);
    fVar21 = (float)(dVar19 * DAT_14053a340) + 0.0;
    uVar11 = uVar3;
    if (iVar12 < 0x96) {
      iVar8 = ((int)dVar17 & 0xffffU) - (uint)uVar3;
      if (iVar8 < -0x8000) {
        iVar8 = iVar8 + 0x10000;
      }
      iVar9 = iVar8 + -0x10000;
      if (iVar8 < 0x8001) {
        iVar9 = iVar8;
      }
      uVar10 = (ushort)(int)dVar17;
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar11 = uVar3 - 0x80, -0x80 < iVar9)) {
          uVar11 = uVar10;
        }
      }
      else {
        uVar11 = uVar10;
        if (0x7f < iVar9) {
          uVar11 = uVar3 + 0x80;
        }
      }
      dVar17 = *(double *)(param_1 + 0x12) + DAT_140539de8;
    }
    else {
      iVar8 = -(uint)uVar3;
      iVar9 = iVar8 + 0xc000;
      iVar8 = iVar8 + 0x1c000;
      if (-0x8001 < iVar9) {
        iVar8 = iVar9;
      }
      iVar9 = iVar8 + -0x10000;
      if (iVar8 < 0x8001) {
        iVar9 = iVar8;
      }
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar11 = uVar3 - 0x100, -0x100 < iVar9)) {
          uVar11 = 0xc000;
        }
      }
      else if (iVar9 < 0x100) {
        uVar11 = 0xc000;
      }
      else {
        uVar11 = uVar3 + 0x100;
      }
      dVar17 = *(double *)(param_1 + 0x12) + DAT_140539e60;
    }
    *(double *)(param_1 + 0x12) = dVar17;
    *(ushort *)(param_1 + 0x10) = uVar11;
    dVar19 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar19 * dVar17) + fVar2;
    dVar19 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar19 * dVar17) + fVar1;
    if ((((iVar12 < 0x96) && (DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar2)) &&
        (fVar2 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
       ((0.0 <= fVar28 && (fVar28 <= DAT_14053af14)))) {
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar28),
                                     SUB84((double)(DAT_140e445d8 - fVar2),0));
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 0x24;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 0x1e;
      }
      else if (DAT_140e419b8 == 2) {
        iVar12 = 0x18;
      }
      else if (DAT_140e419b8 == 3) {
        iVar12 = 0x14;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 0x10;
      }
      iVar8 = 1;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0x96;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x30;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar8 = 0x20;
      }
      else if (DAT_140e419b8 == 4) {
        iVar8 = 0x14;
      }
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 900;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 0xaf0;
      }
      else if (DAT_140e419b8 == 2) {
        iVar9 = 4000;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar9 = 0x9c4;
      }
      uVar25 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      uVar22 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      uVar24 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
      uVar23 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      uVar20 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
      if (DAT_140e419b8 == 0) {
        uVar26 = (int)DAT_14053a070;
        uVar27 = (int)((ulonglong)DAT_14053a070 >> 0x20);
      }
      else {
        uVar26 = (int)DAT_14053a0b0;
        uVar27 = uVar20;
        if ((((DAT_140e419b8 != 1) &&
             (uVar26 = (int)DAT_14053a0f8, uVar27 = uVar22, DAT_140e419b8 != 2)) &&
            (uVar26 = (int)DAT_14053a138, uVar27 = uVar23, DAT_140e419b8 != 3)) &&
           (uVar26 = SUB84(DAT_140539f40,0), uVar27 = uVar25, DAT_140e419b8 == 4)) {
          uVar26 = (int)DAT_14053a190;
          uVar27 = uVar24;
        }
      }
      if (7 < DAT_1407c7798) {
        iVar12 = 1;
        if (DAT_140e419b8 == 0) {
          iVar12 = 0x20;
        }
        else if (DAT_140e419b8 == 1) {
          iVar12 = 0x18;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar12 = 0x14;
        }
        else if (DAT_140e419b8 == 4) {
          iVar12 = 0x10;
        }
        iVar8 = 1;
        if (DAT_140e419b8 == 0) {
          iVar8 = 0x50;
        }
        else if (DAT_140e419b8 == 1) {
          iVar8 = 0x28;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar8 = 0x20;
        }
        else if (DAT_140e419b8 == 4) {
          iVar8 = 0x14;
        }
        uVar26 = (int)DAT_14053a0b0;
        uVar27 = uVar20;
        if ((DAT_140e419b8 != 0) &&
           (uVar26 = (int)DAT_14053a0f8, uVar27 = uVar22, DAT_140e419b8 != 1)) {
          if (DAT_140e419b8 == 2) {
            uVar26 = (int)DAT_14053a118;
            uVar27 = (int)((ulonglong)DAT_14053a118 >> 0x20);
          }
          else {
            uVar26 = (int)DAT_14053a138;
            uVar27 = uVar23;
            if ((DAT_140e419b8 != 3) &&
               (uVar26 = SUB84(DAT_140539f40,0), uVar27 = uVar25, DAT_140e419b8 == 4)) {
              uVar26 = (int)DAT_14053a190;
              uVar27 = uVar24;
            }
          }
        }
      }
      iVar4 = param_1[3];
      if (((iVar12 <= iVar4) && (iVar4 < 0x96)) &&
         (uVar6 = (longlong)(iVar4 - iVar12) % (longlong)iVar8, (int)uVar6 == 0)) {
        sVar14 = (short)(((int)(dVar17 * DAT_14053aba0) & 0xffffU) + 0x400 >> 0xb) * 0x800;
        if (2 < DAT_140e419b8) {
          dVar17 = (double)CONCAT44(uVar27,uVar26) * DAT_140539f38;
          auVar32._12_4_ = in_stack_ffffffffffffff18._12_4_;
          auVar32._0_8_ = in_stack_ffffffffffffff18._0_8_;
          auVar32._8_4_ = 1;
          in_stack_ffffffffffffff18._8_8_ = auVar32._8_8_;
          in_stack_ffffffffffffff18._0_8_ = dVar17;
          uVar20 = CONCAT22(uVar29,sVar14);
          FUN_1400709b0(5,uVar6 & 0xffffffff,fVar2,fVar28,uVar20,0,dVar17,
                        in_stack_ffffffffffffff18._8_8_,2,iVar9 * 2,0);
          uVar29 = (undefined2)((uint)uVar20 >> 0x10);
        }
        auVar33._12_4_ = in_stack_ffffffffffffff18._12_4_;
        auVar33._0_8_ = in_stack_ffffffffffffff18._0_8_;
        auVar33._8_4_ = 1;
        auVar34._8_8_ = auVar33._8_8_;
        auVar34._0_8_ = CONCAT44(uVar27,uVar26);
        FUN_1400709b0(5,0,fVar2,fVar28,CONCAT22(uVar29,sVar14),0,CONCAT44(uVar27,uVar26),
                      auVar34._8_8_,2,iVar9,0);
        auVar35._12_4_ = auVar34._12_4_;
        auVar35._0_8_ = auVar34._0_8_;
        auVar35._8_4_ = 1;
        uVar31 = 0;
        FUN_14006c2f0(5,0,fVar2,fVar28,sVar14,0,(double)CONCAT44(uVar27,uVar26) * DAT_140539f58,
                      auVar35._8_8_,0);
      }
    }
    uVar5 = _UNK_14053bb28;
    uVar7 = _DAT_14053bb20;
    uVar20 = CONCAT22(uVar31,sVar13);
    FUN_1400c8410(DAT_140e446a0,0x23,7,fVar16 + (float)param_1[10] + DAT_14053ac44,
                  (fVar21 + (float)param_1[0xb]) - DAT_14053aa20,uVar20,_DAT_14053bb20,
                  _UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    uVar30 = CONCAT22((short)((uint)uVar20 >> 0x10),-sVar13);
    FUN_1400c8410(DAT_140e446a0,0x23,7,((float)param_1[10] - fVar16) - DAT_14053ac44,
                  (fVar21 + (float)param_1[0xb]) - DAT_14053aa20,uVar30,uVar7,uVar5,0xff,0xff,0xff,
                  0xff,1,1);
    FUN_1400c8410(DAT_140e4469c,0x23,7,param_1[10],param_1[0xb],uVar30 & 0xffff0000,dVar18,dVar18,
                  0xff,0xff,0xff,0xff,1,0);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,3);
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


