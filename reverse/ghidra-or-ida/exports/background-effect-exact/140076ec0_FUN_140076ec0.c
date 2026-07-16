// Function: FUN_140076ec0 @ 140076ec0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140076ec0(undefined4 *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  float fVar18;
  undefined4 *local_res20;
  undefined4 in_stack_fffffffffffffed0;
  undefined2 uVar19;
  undefined8 in_stack_fffffffffffffed8;
  undefined8 uVar20;
  undefined8 *local_e0;
  undefined4 *local_d8;
  undefined4 *local_d0;
  undefined4 *local_c8;
  
  dVar3 = DAT_14053a020;
  dVar1 = DAT_140539d28;
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
  uVar19 = (undefined2)((uint)in_stack_fffffffffffffed0 >> 0x10);
  dVar14 = (double)FUN_1403307c0();
  fVar18 = (float)(dVar14 * *(double *)(param_1 + 10)) + (float)param_1[5];
  param_1[5] = fVar18;
  dVar15 = (double)FUN_140332d90();
  dVar2 = DAT_140539d50;
  dVar14 = DAT_140539d08;
  fVar17 = (float)(dVar15 * *(double *)(param_1 + 10)) + (float)param_1[6];
  param_1[6] = fVar17;
  if (param_1[2] != 0x3b) goto LAB_140077173;
  iVar9 = param_1[0x10];
  iVar13 = param_1[1];
  iVar8 = param_1[0x14];
  iVar12 = 0;
  if ((-1 < iVar13) && (iVar12 = iVar8, iVar13 < 0x20)) {
    dVar15 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a778 * dVar3 * dVar1);
    iVar12 = (int)(dVar15 * (double)iVar8);
  }
  iVar6 = iVar9 + -0x10;
  if (iVar6 != iVar9) {
    if (iVar13 < iVar6) {
      if (iVar9 <= iVar13) goto LAB_14007704c;
    }
    else if (iVar13 < iVar9) {
      dVar15 = (double)FUN_140332d90(((double)iVar13 - (double)(iVar6 * 2 - iVar9)) * DAT_14053a900
                                     * dVar3 * dVar1);
      iVar12 = (int)(dVar15 * (double)iVar8);
    }
    else {
LAB_14007704c:
      iVar12 = 0;
    }
  }
  uVar10 = ((uint)(DAT_140e44acc - iVar13) >> 0x1e ^ DAT_140e44acc - iVar13) * 0x6c078965 + 1;
  DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  dVar15 = ((double)iVar13 * dVar14 + dVar2) * (double)iVar13 + *(double *)(param_1 + 0xc);
  uVar5 = DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14;
  uVar10 = uVar10 * 0x800 ^ uVar10;
  *(double *)(param_1 + 0xc) = dVar15;
  DAT_140e9fd18 = uVar5 * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ DAT_140e9fd18 ^ uVar10;
  FUN_1400c8410(param_1[3],param_1[4],8,fVar18,fVar17,
                CONCAT22(uVar19,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),dVar15,
                dVar15,param_1[0x11],param_1[0x12],param_1[0x13],iVar12,1,0);
  uVar7 = (undefined4)((ulonglong)dVar15 >> 0x20);
LAB_140077173:
  dVar4 = DAT_14053ab50;
  dVar15 = DAT_14053a2f8;
  iVar9 = param_1[2];
  if ((iVar9 == 0x3d) || (iVar9 == 0x3e)) {
    iVar13 = 0;
    if ((0xb3 < DAT_140e418c8) && (iVar13 = param_1[0x14], DAT_140e418c8 < 600)) {
      dVar16 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053a548) * _DAT_14053a338 *
                                     dVar3 * dVar1);
      iVar13 = (int)(dVar16 * (double)(int)param_1[0x14]);
    }
    local_c8 = param_1 + 5;
    local_d0 = param_1 + 6;
    local_d8 = param_1 + 4;
    local_res20 = param_1 + 3;
    local_e0 = (undefined8 *)(param_1 + 0xc);
    uVar20 = CONCAT44(uVar7,0xff);
    uVar5 = 0;
    iVar8 = param_1[0x10] + -0x10;
    iVar6 = FUN_1401348b0(param_1[1],0x18,iVar8,iVar8,param_1[0x10],0,uVar20);
    uVar7 = (undefined4)((ulonglong)uVar20 >> 0x20);
    iVar8 = param_1[1];
    iVar12 = iVar8 / 0x18;
    dVar14 = ((double)iVar8 * dVar14 + dVar2) * (double)iVar8 + *(double *)(param_1 + 0xc);
    *(double *)(param_1 + 10) = *(double *)(param_1 + 10) + DAT_140539e50;
    *(double *)(param_1 + 0xc) = dVar14;
    if (iVar9 == 0x3d) {
      uVar10 = ((uint)(DAT_140e44acc - iVar8) >> 0x1e ^ DAT_140e44acc - iVar8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar10 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ DAT_140e9fd18 ^ uVar10;
      uVar5 = CONCAT22((short)(uVar5 >> 0x10),
                       (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      FUN_1400c8410(param_1[3],param_1[4] + iVar12,7,param_1[5],param_1[6],uVar5,dVar14,dVar14,iVar6
                    ,iVar6,iVar6,iVar13,1,0);
      uVar7 = (undefined4)((ulonglong)dVar14 >> 0x20);
      iVar8 = param_1[1];
    }
    if (param_1[2] == 0x3e) {
      uVar20 = *local_e0;
      uVar11 = ((uint)(DAT_140e44acc - iVar8) >> 0x1e ^ DAT_140e44acc - iVar8) * 0x6c078965 + 1;
      uVar10 = uVar11 * 0x800 ^ uVar11;
      DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
      uVar5 = CONCAT22((short)(uVar5 >> 0x10),
                       (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      FUN_1400c8410(*local_res20,*local_d8,8,*local_c8,*local_d0,uVar5,uVar20,uVar20,iVar6,iVar6,
                    iVar6,iVar13,1,0);
      uVar7 = (undefined4)((ulonglong)uVar20 >> 0x20);
    }
    if (param_1[2] == 0x42) {
      if (DAT_140e418c8 < 0x1af4) {
        dVar14 = 0.0;
      }
      else {
        dVar14 = DAT_140539f40;
        if (DAT_140e418c8 < 0x1ce8) {
          dVar14 = (double)FUN_140332d90(((double)DAT_140e418c8 - dVar4) * dVar15 * dVar3 * dVar1);
          dVar14 = dVar14 + 0.0;
        }
      }
      uVar20 = *(undefined8 *)(param_1 + 0xc);
      iVar9 = (int)((double)iVar6 * dVar14);
      FUN_1400c8410(param_1[3],iVar12 + param_1[4],7,param_1[5],param_1[6],uVar5 & 0xffff0000,uVar20
                    ,uVar20,iVar9,iVar9,iVar9,iVar13,1,0);
      uVar7 = (undefined4)((ulonglong)uVar20 >> 0x20);
    }
  }
  if (param_1[2] == 0x42) {
    iVar9 = param_1[0x14];
    iVar13 = 0;
    if ((0x1af3 < DAT_140e418c8) && (iVar13 = iVar9, DAT_140e418c8 < 0x1ce8)) {
      dVar14 = (double)FUN_140332d90(((double)DAT_140e418c8 - dVar4) * dVar15 * dVar3 * dVar1);
      iVar13 = (int)(dVar14 * (double)iVar9);
    }
    iVar8 = param_1[1];
    uVar5 = 0;
    iVar9 = param_1[0x10] + -0x10;
    uVar7 = FUN_1401348b0(iVar8,0x10,iVar9,iVar9,param_1[0x10],0,CONCAT44(uVar7,0xff));
    dVar14 = ((double)iVar8 * _DAT_140539d18 + DAT_140539d38) * (double)iVar8 +
             *(double *)(param_1 + 0xc);
    *(double *)(param_1 + 0xc) = dVar14;
    FUN_1400c8410(param_1[3],iVar8 / 0x18 + param_1[4],7,param_1[5],param_1[6],uVar5 & 0xffff0000,
                  dVar14,dVar14,uVar7,uVar7,uVar7,iVar13,1,0);
  }
  if ((param_1[1] == param_1[0x10]) || (DAT_140e418c8 == DAT_140e45d74 + 1)) {
    *param_1 = 0;
  }
  return;
}


