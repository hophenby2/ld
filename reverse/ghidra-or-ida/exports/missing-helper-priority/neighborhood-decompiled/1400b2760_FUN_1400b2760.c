// Function: FUN_1400b2760 @ 1400b2760
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b2760(undefined4 *param_1)

{
  ushort uVar1;
  double dVar2;
  double dVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  longlong lVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined4 in_stack_fffffffffffffeb8;
  undefined2 uVar33;
  uint in_stack_fffffffffffffec0;
  undefined2 uVar34;
  double in_stack_fffffffffffffed0;
  undefined4 uVar35;
  
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  dVar24 = DAT_14053aba0;
  uVar34 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
  dVar19 = dVar19 * DAT_14053aba0;
  uVar12 = (ushort)(int)dVar19;
  if (param_1[5] == 0) {
    uVar5 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res10 = (undefined4)uVar5;
    in_stack_fffffffffffffed0 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    uStackX_14 = (undefined4)((ulonglong)uVar5 >> 0x20);
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res10,uStackX_14,in_stack_fffffffffffffec0,
                  in_stack_fffffffffffffed0,in_stack_fffffffffffffed0,0xff,0xff,0xff,0xff,1,0);
    uVar34 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
    in_stack_fffffffffffffeb8 = uStackX_14;
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar21 = DAT_14053a8d0;
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_1400b349f;
  uVar9 = param_1[3];
  dVar23 = (double)(int)uVar9;
  dVar20 = (double)FUN_140332d90((dVar23 - 0.0) * DAT_14053a8d0 * DAT_14053a020 * DAT_140539d28);
  fVar16 = (float)(dVar20 + dVar20) - _DAT_14053acd0;
  dVar20 = (double)FUN_140332d90((dVar23 - DAT_14053a218) * dVar21 * dVar3 * dVar2);
  fVar29 = (float)(dVar20 + dVar20) - DAT_14053ac2c;
  dVar21 = (double)FUN_140332d90((dVar23 - DAT_14053a2a8) * dVar21 * dVar3 * dVar2);
  fVar17 = (float)(dVar21 + dVar21) + DAT_14053acbc;
  dVar20 = (double)FUN_140332d90();
  dVar23 = DAT_140539e60;
  dVar21 = *(double *)(param_1 + 0x12);
  fVar18 = (float)(dVar20 + dVar20) + 0.0;
  if ((uVar9 < 0x79) && (DAT_140539f68 < dVar21)) {
    dVar21 = dVar21 - DAT_140539e60;
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar6 = ((int)dVar19 & 0xffffU) - (uint)uVar1;
  *(double *)(param_1 + 0x12) = dVar21;
  iVar15 = iVar6 + 0x10000;
  if (-0x8001 < iVar6) {
    iVar15 = iVar6;
  }
  iVar6 = iVar15 + -0x10000;
  if (iVar15 < 0x8001) {
    iVar6 = iVar15;
  }
  if (iVar6 < 1) {
    uVar8 = uVar1;
    if ((iVar6 < 0) && (uVar8 = uVar1 - 0x80, -0x80 < iVar6)) {
      uVar8 = uVar12;
    }
  }
  else {
    uVar8 = uVar12;
    if (0x7f < iVar6) {
      uVar8 = uVar1 + 0x80;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar8;
  if (299 < (int)uVar9) {
    dVar21 = dVar21 - dVar23;
    *(double *)(param_1 + 0x12) = dVar21;
  }
  dVar19 = (double)FUN_1403307c0();
  fVar28 = (float)(dVar19 * dVar21) + (float)param_1[10];
  param_1[10] = fVar28;
  dVar19 = (double)FUN_140332d90();
  fVar27 = (float)(dVar19 * dVar21) + (float)param_1[0xb];
  param_1[0xb] = fVar27;
  fVar26 = DAT_140e445dc;
  fVar25 = DAT_140e445d8;
  if (uVar9 - 0x18 < 0x114) {
    fVar27 = fVar27 + fVar18;
    fVar30 = fVar27 - DAT_14053acbc;
    fVar27 = fVar27 + _DAT_14053ac74;
    fVar31 = fVar28 - _DAT_14053ace4;
    fVar28 = fVar28 + DAT_14053acd8;
    uVar11 = DAT_140e418c8 * 0x115c + uVar9 * -0x115b;
    dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar30),(double)(DAT_140e445d8 - fVar31)
                                  );
    uVar13 = (uint)(dVar19 * dVar24);
    dVar19 = (double)FUN_1403300b4((double)(fVar26 - fVar27),(double)(fVar25 - fVar28));
    uVar33 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
    uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
    iVar15 = (int)(uVar9 - 0x18) % 0x32;
    dVar21 = (double)iVar15 * DAT_140539ec8 + DAT_14053a0f8;
    uVar12 = (ushort)uVar13;
    if (iVar15 == 0) {
      *(ushort *)((longlong)param_1 + 0x42) = uVar12;
      fVar25 = DAT_140e445d8;
LAB_1400b2bd1:
      if ((((fVar25 / DAT_14053ab70 + 0.0 <= fVar31) &&
           (fVar31 <= fVar25 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= fVar30)) &&
         (fVar30 <= DAT_14053af14)) {
        uVar9 = ((uVar11 & 0x3fffffff) >> 0x1c ^ uVar11 * 4) * 0x6c078965 + 1;
        uVar7 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 4;
        dVar23 = (double)(((uVar7 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ uVar7) % 0xb);
        dVar20 = (double)FUN_1403307c0();
        dVar22 = (double)FUN_140332d90();
        in_stack_fffffffffffffed0 = (double)CONCAT44(uVar32,1);
        uVar9 = (uVar11 * 0x2c >> 0x1e ^ uVar11 * 0x2c) * 0x6c078965 + 1;
        uVar34 = 0;
        DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
        in_stack_fffffffffffffeb8 =
             CONCAT22(uVar33,*(short *)((longlong)param_1 + 0x42) +
                             (short)((ulonglong)DAT_140e9fd1c / 0x641) * -0x641 +
                             (short)DAT_140e9fd1c + -800);
        FUN_14006c2f0(0xd,0,(float)(dVar20 * dVar23) + fVar31,(float)(dVar22 * dVar23) + fVar30,
                      in_stack_fffffffffffffeb8,0,dVar21,in_stack_fffffffffffffed0,0);
        uVar1 = *(ushort *)((longlong)param_1 + 0x42);
        iVar6 = (uVar13 & 0xffff) - (uint)uVar1;
        iVar15 = iVar6 + 0x10000;
        if (-0x8001 < iVar6) {
          iVar15 = iVar6;
        }
        iVar6 = iVar15 + -0x10000;
        if (iVar15 < 0x8001) {
          iVar6 = iVar15;
        }
        if (iVar6 < 1) {
          uVar8 = uVar1;
          if ((iVar6 < 0) && (uVar8 = uVar1 - 0x48, -0x48 < iVar6)) {
            uVar8 = uVar12;
          }
        }
        else {
          uVar8 = uVar12;
          if (0x47 < iVar6) {
            uVar8 = uVar1 + 0x48;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar8;
      }
    }
    else if (iVar15 < 0x28) goto LAB_1400b2bd1;
    if ((param_1[3] - 0x40 < 0xec) && (iVar15 = param_1[3] + -0x40, iVar15 == (iVar15 / 100) * 100))
    {
      uVar32 = (undefined4)DAT_14053a138;
      lVar14 = 0xf;
      uVar9 = uVar11 * 0x115c;
      do {
        uVar33 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
        uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
        uVar7 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
        uVar13 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 4;
        dVar21 = (double)(((uVar13 >> 0xb ^ uVar7) >> 8 ^ uVar13 ^ uVar7) % 0x21);
        dVar23 = (double)FUN_1403307c0();
        dVar20 = (double)FUN_140332d90();
        uVar13 = uVar11 * -0x111a + uVar9;
        dVar20 = dVar20 * dVar21;
        uVar7 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
        fVar25 = (float)dVar20 + fVar27;
        uVar13 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar7 = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
        DAT_140e9fd1c = uVar7;
        uVar5 = FUN_140134db0(dVar20,uVar13,uVar32);
        in_stack_fffffffffffffed0 = (double)CONCAT44(uVar35,1);
        uVar34 = 0;
        in_stack_fffffffffffffeb8 =
             CONCAT22(uVar33,(short)uVar7 + (short)(uVar7 / 0x5dc1) * -0x5dc1 +
                             (short)(int)(dVar19 * dVar24) + -12000);
        FUN_14006c2f0(0,0,(float)(dVar23 * dVar21) + fVar28,fVar25,in_stack_fffffffffffffeb8,0,uVar5
                      ,in_stack_fffffffffffffed0,0);
        uVar9 = uVar9 + 1;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
    }
  }
  dVar24 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a8d0 * dVar3 * dVar2);
  dVar24 = dVar24 * _DAT_14053aae8;
  dVar19 = (double)FUN_1403307c0();
  fVar26 = (float)(dVar19 * DAT_14053a3f8) + DAT_14053ac2c;
  dVar19 = (double)FUN_140332d90();
  uVar4 = _UNK_14053bb28;
  uVar5 = _DAT_14053bb20;
  sVar10 = (short)(int)dVar24;
  uVar32 = CONCAT22(uVar34,sVar10);
  fVar25 = (float)(dVar19 * DAT_14053a3f8) + 0.0;
  FUN_1400c8410(DAT_140e44e14,0x20,7,fVar26 + (float)param_1[10],
                fVar29 + (float)param_1[0xb] + fVar25,uVar32,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff
                ,0xff,0xff,1,0);
  uVar9 = CONCAT22((short)((uint)uVar32 >> 0x10),-sVar10);
  FUN_1400c8410(DAT_140e44e14,0x20,7,(float)param_1[10] - fVar26,
                fVar29 + (float)param_1[0xb] + fVar25,uVar9,uVar5,uVar4,0xff,0xff,0xff,0xff,1,1);
  uVar9 = uVar9 & 0xffff0000;
  FUN_1400c8410(DAT_140e448f0,0x20,7,param_1[10],fVar17 + (float)param_1[0xb],uVar9,uVar5,uVar4,0xff
                ,0xff,0xff,0xff,1,0);
  uVar9 = uVar9 & 0xffff0000;
  FUN_1400c8410(DAT_140e44e10,0x20,7,param_1[10],fVar29 + (float)param_1[0xb],uVar9,uVar5,uVar4,0xff
                ,0xff,0xff,0xff,1,0);
  uVar9 = uVar9 & 0xffff0000;
  FUN_1400c8410(DAT_140e448ec,0x20,7,param_1[10],fVar16 + (float)param_1[0xb],uVar9,uVar5,uVar4,0xff
                ,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44e18,0x20,7,param_1[10],fVar18 + (float)param_1[0xb],uVar9 & 0xffff0000,
                uVar5,uVar4,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_1400b349f:
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


