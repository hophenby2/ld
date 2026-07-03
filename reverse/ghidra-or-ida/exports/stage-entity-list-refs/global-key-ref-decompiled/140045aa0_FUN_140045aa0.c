// Function: FUN_140045aa0 @ 140045aa0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140045aa0(undefined4 *param_1)

{
  longlong lVar1;
  double dVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar21;
  undefined4 in_stack_fffffffffffffe70;
  undefined2 uVar23;
  undefined4 uVar22;
  int iStack_11c;
  
  dVar2 = DAT_140539f40;
  uVar23 = (undefined2)((uint)in_stack_fffffffffffffe70 >> 0x10);
  uVar21 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  iStack_11c = 0;
  iVar5 = 0;
  lVar1 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_11c = iVar5, lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        iStack_11c = *(int *)(lVar1 + 0x1c);
      }
      iVar5 = iStack_11c;
    }
  }
  uVar15 = SUB84(DAT_14053a020,0);
  uVar16 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar19 = SUB84(DAT_140539d28,0);
  uVar20 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar10 = DAT_140539f40;
  if (param_1[5] == 0) {
    iVar5 = param_1[3];
    dVar10 = DAT_140539ec8;
    if ((-1 < iVar5) && (dVar10 = DAT_140539f40, iVar5 < 0x32)) {
      dVar10 = (double)FUN_140332d90(((double)iVar5 - _DAT_140539cc0) * DAT_14053a670 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar10 = dVar10 * DAT_140539f28 + DAT_140539ec8;
    }
    dVar11 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar11 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar11 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar11 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (iVar5 != 0x32) goto LAB_1400460e2;
    *(undefined8 *)(param_1 + 0x12) = 0x4020000000000000;
    uVar3 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
    local_res8 = (undefined4)uVar3;
    uStackX_c = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar4 = DAT_140e418c8 >> 0x1e ^ DAT_140e418c8;
    param_1[10] = local_res8;
    param_1[0xb] = uStackX_c;
    param_1[3] = 0;
    param_1[5] = 1;
    uVar4 = uVar4 * 0x6c078965 + 1;
    param_1[0x15] = 0;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    *(short *)(param_1 + 0x10) =
         (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0xbb9) * -0xbb9 + 0x3a24;
  }
  else if (param_1[5] != 1) goto LAB_1400460e2;
  dVar11 = *(double *)(param_1 + 0x12) + DAT_140539e60;
  *(double *)(param_1 + 0x12) = dVar11;
  dVar12 = (double)FUN_1403307c0();
  fVar17 = (float)(dVar12 * dVar11) + (float)param_1[10];
  param_1[10] = fVar17;
  dVar12 = (double)FUN_140332d90();
  iVar5 = param_1[3];
  fVar18 = (float)(dVar12 * dVar11) + (float)param_1[0xb];
  param_1[0xb] = fVar18;
  fVar13 = DAT_140e445d8;
  if ((((iVar5 < 0x28) && (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= fVar17)) &&
      (fVar17 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
     ((DAT_14053aca8 <= fVar18 && (fVar18 <= DAT_14053aef4)))) {
    dVar11 = (double)FUN_1403307c0();
    fVar17 = (float)(dVar11 * DAT_14053a278) + fVar17;
    dVar11 = (double)FUN_140332d90();
    fVar18 = (float)(dVar11 * DAT_14053a278) + fVar18;
    dVar11 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18),
                                   SUB84((double)(fVar13 - fVar17),0));
    iVar7 = 1;
    dVar11 = dVar11 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar7 = 0x16;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 0xf;
    }
    else if (DAT_140e419b8 == 2) {
      iVar7 = 9;
    }
    else if (DAT_140e419b8 == 3) {
      iVar7 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      iVar7 = 6;
    }
    dVar12 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar12 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
       ((dVar12 = DAT_14053a118, DAT_140e419b8 != 2 &&
        ((dVar12 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar12 = dVar2, DAT_140e419b8 == 4)))))) {
      dVar12 = DAT_14053a1a8;
    }
    if ((-1 < iVar5) && (iVar5 % iVar7 == 0)) {
      fVar8 = (float)FUN_140334430(fVar17 - fVar13,DAT_140539fc0);
      fVar9 = (float)FUN_140334430(fVar18 - DAT_140e445dc);
      if (fVar8 + fVar9 < 0.0) {
        fVar8 = (float)FUN_1403352f8();
      }
      else {
        fVar8 = SQRT(fVar8 + fVar9);
      }
      if (DAT_14053ad10 <= fVar8) {
        sVar6 = (short)(((int)dVar11 & 0xffffU) + 0x400 >> 0xb) * 0x800;
        uVar23 = 0;
        FUN_14006c2f0(0xc,0,fVar17,fVar18,CONCAT22(uVar21,sVar6),0,dVar12,1,0);
        if (2 < DAT_140e419b8) {
          iVar5 = 0;
          do {
            uVar23 = 0;
            FUN_14006c2f0(0xc,0,fVar17,fVar18,(short)iVar5 * 0x2b5c + sVar6 + -0x15ae,0,
                          dVar12 - dVar2,1,0);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        fVar13 = DAT_140e445d8;
      }
    }
    uVar15 = SUB84(DAT_14053a020,0);
    uVar16 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar19 = SUB84(DAT_140539d28,0);
    uVar20 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  }
  if (((((float)param_1[10] < fVar13 / DAT_14053ab70 - DAT_14053ad9c) ||
       (fVar13 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
LAB_1400460e2:
  uVar14 = SUB84(dVar10,0);
  uVar21 = *(undefined2 *)(param_1 + 0x10);
  dVar11 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a930 *
                                 (double)CONCAT44(uVar16,uVar15) * (double)CONCAT44(uVar20,uVar19));
  dVar11 = (double)((float)(dVar11 * (double)((float)dVar10 * DAT_14053a770)) + 0.0);
  dVar12 = (double)FUN_1403307c0();
  fVar17 = (float)(dVar12 * dVar11) + 0.0;
  dVar12 = (double)FUN_140332d90();
  uVar22 = CONCAT22(uVar23,uVar21);
  fVar13 = (float)(dVar12 * dVar11) + 0.0;
  FUN_1400c8410(DAT_140e44880,0x24,7,fVar17 + (float)param_1[10],fVar13 + (float)param_1[0xb],uVar22
                ,dVar10,uVar14,0xff,0xff,0xff,0xff,1,0);
  uVar4 = CONCAT22((short)((uint)uVar22 >> 0x10),*(short *)(param_1 + 0x10) + -0x8000);
  FUN_1400c8410(DAT_140e44880,0x24,7,(float)param_1[10] - fVar17,(float)param_1[0xb] - fVar13,uVar4,
                dVar10,uVar14,0xff,0xff,0xff,0xff,1,1);
  uVar4 = uVar4 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar4,dVar10,uVar14,0xff,0xff,0xff,
                0xff,1,0);
  dVar11 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 *
                                 (double)CONCAT44(uVar16,uVar15) * (double)CONCAT44(uVar20,uVar19));
  uVar4 = uVar4 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar4,dVar10,uVar14,0xff,0xff,0xff,
                0x80 - (int)(dVar11 * DAT_14053b1c8),1,0);
  uVar21 = (undefined2)(uVar4 >> 0x10);
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    uVar15 = CONCAT22(uVar21,*(undefined2 *)(param_1 + 0x10));
    FUN_140070d00(5,DAT_140e44880,0x23,fVar17 + (float)param_1[10],fVar13 + (float)param_1[0xb],
                  uVar15,0,uVar14,uVar14,0x10,0xff,0xff,0xff,0x60,0);
    uVar4 = CONCAT22((short)((uint)uVar15 >> 0x10),*(short *)(param_1 + 0x10) + -0x8000);
    FUN_140070d00(7,DAT_140e44880,0x23,(float)param_1[10] - fVar17,(float)param_1[0xb] - fVar13,
                  uVar4,0,uVar14,uVar14,0x18,0xff,0xff,0xff,0x60,0);
    uVar4 = uVar4 & 0xffff0000;
    FUN_140070d00(5,DAT_140e4487c,0x23,param_1[10],param_1[0xb],uVar4,0,uVar14,uVar14,0x18,0xff,0xff
                  ,0xff,0x60,0);
    uVar21 = (undefined2)(uVar4 >> 0x10);
  }
  FUN_140079c10(param_1,2);
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,200,2);
    if (DAT_140e44600 == 0) {
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar21,0x4000),dVar2,10,1,
                 DAT_140e44308);
    }
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((iStack_11c < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  return;
}


