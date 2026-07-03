// Function: FUN_140088c20 @ 140088c20
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140088c20(undefined4 *param_1)

{
  float fVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  int *piVar5;
  double dVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  float fVar18;
  undefined4 uVar19;
  double dVar20;
  undefined4 uVar21;
  float fVar22;
  undefined4 in_stack_fffffffffffffe98;
  undefined4 uVar23;
  undefined2 uVar24;
  undefined4 in_stack_fffffffffffffea0;
  ushort uVar25;
  undefined8 in_stack_fffffffffffffeb0;
  undefined8 uVar26;
  undefined8 in_stack_fffffffffffffeb8;
  int local_108;
  int iStack_ec;
  
  dVar6 = DAT_140539f40;
  uVar25 = (ushort)((uint)in_stack_fffffffffffffea0 >> 0x10);
  uVar14 = (uint)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar19 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  local_108 = 0;
  iStack_ec = 0;
  iVar8 = 0;
  piVar5 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; local_108 = iVar8, piVar5 != (int *)0x0; piVar5 = *(int **)(piVar5 + 0x18)) {
      if (piVar5[1] == param_1[2]) {
        local_108 = *piVar5;
        iStack_ec = piVar5[7];
      }
      iVar8 = local_108;
    }
  }
  fVar18 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar18;
  if ((param_1[5] != 0) || (fVar18 < DAT_14053b358)) {
    if (param_1[5] != 1) goto LAB_14008915f;
  }
  else {
    param_1[5] = 1;
    param_1[3] = 0;
  }
  iVar8 = param_1[3];
  dVar4 = (double)FUN_140332d90(SUB84(((double)iVar8 - 0.0) * DAT_14053a8c0 * DAT_14053a020 *
                                      DAT_140539d28,0));
  dVar4 = dVar4 * _DAT_14053b050 + dVar6;
  if (iVar8 == 0x1e) {
    param_1[0x15] = 0;
  }
  fVar1 = (float)param_1[10];
  if ((((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= fVar1) &&
       (fVar1 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) && (0.0 <= (float)param_1[0xb])) &&
     ((float)param_1[0xb] <= DAT_14053af14)) {
    fVar22 = fVar18 - DAT_14053ac58;
    dVar3 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar22),0),
                                  SUB84((double)(DAT_140e445d8 - fVar1),0));
    iVar13 = DAT_140e419b8;
    uVar21 = DAT_14053ac2c;
    if (fVar18 < DAT_14053ae2c) {
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0xb4;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 0x96;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar7 = 0x78;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 100;
      }
      iVar16 = 1;
      uVar2 = (longlong)(iVar8 + -0x3c) % (longlong)iVar7;
      uVar11 = uVar2 & 0xffffffff;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar16 = 0xe;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar16 = 10;
      }
      else if (DAT_140e419b8 == 4) {
        iVar16 = 8;
      }
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 6000;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 0x1130;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar12 = 0xc80;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 0xaf0;
      }
      dVar20 = DAT_14053a070;
      if ((((DAT_140e419b8 != 0) && (dVar20 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
          (dVar20 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
         ((dVar20 = DAT_14053a0f8, DAT_140e419b8 != 3 && (dVar20 = dVar6, DAT_140e419b8 == 4)))) {
        dVar20 = DAT_14053a158;
      }
      iVar9 = (int)uVar2;
      if (0x3b < iVar8) {
        if (iVar9 == 0) {
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar3 * DAT_14053aba0);
        }
        else if ((iVar8 < 0x3c) || (0x2f < iVar9)) goto LAB_140088fae;
        if ((int)((longlong)((ulonglong)(uint)(iVar9 >> 0x1f) << 0x20 | uVar11) % (longlong)iVar16)
            == 0) {
          iVar8 = (int)((longlong)((ulonglong)(uint)(iVar9 >> 0x1f) << 0x20 | uVar11) /
                       (longlong)iVar16);
          uVar17 = CONCAT44(uVar14,iVar8 + 1);
          uVar26 = CONCAT44(uVar19,1);
          uVar23 = CONCAT22(uVar24,*(undefined2 *)((longlong)param_1 + 0x42));
          uVar19 = uVar21;
          FUN_1400709b0(0xc,0,fVar1,fVar22,uVar23,uVar21,dVar20,uVar26,uVar17,iVar12 * iVar8,0);
          uVar25 = (ushort)((uint)uVar19 >> 0x10);
          uVar14 = (uint)((ulonglong)uVar17 >> 0x20);
          uVar24 = (undefined2)((uint)uVar23 >> 0x10);
          uVar19 = (undefined4)((ulonglong)uVar26 >> 0x20);
          iVar13 = DAT_140e419b8;
        }
      }
LAB_140088fae:
      if ((((2 < iVar13) && (0x3b < (int)param_1[3])) &&
          (iVar7 = (param_1[3] + -0x3c) % iVar7, iVar7 < 0x19)) && (iVar7 == (iVar7 / 5) * 5)) {
        iVar8 = iVar9 / 5 + 1;
        uVar26 = CONCAT44(uVar14,iVar8);
        FUN_1400709b0(0xd,0,fVar1,fVar22,CONCAT22(uVar24,*(undefined2 *)((longlong)param_1 + 0x42)),
                      uVar21,dVar20 + DAT_14053a018,CONCAT44(uVar19,1),uVar26,iVar8 * 0xfa + -0xfa,0
                     );
        uVar25 = (ushort)((uint)uVar21 >> 0x10);
        uVar14 = (uint)((ulonglong)uVar26 >> 0x20);
      }
    }
  }
  uVar10 = (uint)uVar25 << 0x10;
  FUN_1400c8410(DAT_140e44b80,0x18,0x17,param_1[10],(float)param_1[0xb] - DAT_14053acbc,uVar10,dVar4
                ,dVar6,(ulonglong)uVar14 << 0x20,0,0,0x40,1,0);
  uVar10 = uVar10 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b80,0x19,7,param_1[10],(float)param_1[0xb] - DAT_14053acbc,uVar10,dVar4,
                dVar6,0xff,0xff,0xff,0xff,1,0);
  uVar25 = (ushort)(uVar10 >> 0x10);
  FUN_140079c10(param_1,1);
LAB_14008915f:
  fVar18 = DAT_14053aa20;
  uVar21 = (undefined4)DAT_140539f10;
  uVar19 = (undefined4)DAT_140539f28;
  if ((int)param_1[7] < 1) {
    uVar10 = param_1[1] + DAT_140e418c8;
    uVar14 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar14 = uVar14 * 0x800 ^ uVar14;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
    DAT_140e9fd1c = uVar14;
    uVar17 = FUN_140134db0(uVar10,uVar21,uVar19);
    uVar26 = FUN_140134db0(uVar10);
    uVar23 = CONCAT22(uVar25,(short)uVar14 - (short)(uVar14 / 0x10001));
    FUN_140070d00(0x37,DAT_140e41a88,0x15,param_1[10],(float)param_1[0xb] + fVar18,uVar23,dVar6,
                  uVar26,uVar17,0x78,0xff,0xff,0xff,0x80,0);
    uVar25 = (ushort)((uint)uVar23 >> 0x10);
    FUN_14007b010(param_1,1000,9);
    FUN_140079e20(param_1,1);
    iVar8 = param_1[2];
    piVar5 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; piVar5 != (int *)0x0; piVar5 = *(int **)(piVar5 + 0x18)) {
        if (piVar5[1] == iVar8) {
          piVar5[0x17] = piVar5[0x17] + -1;
        }
      }
    }
    *param_1 = 0;
  }
  if (iStack_ec < 1) {
    uVar10 = param_1[1] + DAT_140e418c8;
    uVar15 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    uVar14 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar14 = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
    DAT_140e9fd1c = uVar14;
    uVar17 = FUN_140134db0(uVar10,uVar21,uVar19);
    uVar26 = FUN_140134db0(uVar10);
    FUN_140070d00(0x37,DAT_140e41a88,0x15,param_1[10],(float)param_1[0xb] + fVar18,
                  CONCAT22(uVar25,(short)uVar14 - (short)(uVar14 / 0x10001)),dVar6,uVar26,uVar17,
                  0x78,0xff,0xff,0xff,0x80,0);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (local_108 == 0) {
    *param_1 = 0;
  }
  return;
}


