// Function: FUN_1400a9080 @ 1400a9080
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a9080(undefined4 *param_1)

{
  int iVar1;
  float fVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  float fVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float local_res8;
  float local_res10;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar26;
  uint in_stack_fffffffffffffef0;
  undefined2 uVar27;
  undefined8 in_stack_ffffffffffffff00;
  ulonglong in_stack_ffffffffffffff08;
  ulonglong uVar28;
  
  uVar27 = (undefined2)(in_stack_fffffffffffffef0 >> 0x10);
  uVar26 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  fVar22 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar22;
  dVar3 = DAT_14053b0a8;
  fVar2 = DAT_14053aa20;
  dVar12 = DAT_14053a930;
  dVar13 = DAT_14053a020;
  dVar14 = DAT_140539d28;
  if (param_1[5] == 0) {
    iVar1 = param_1[3];
    local_res10 = DAT_14053aa20;
    iVar7 = iVar1 % 0x1e;
    if (iVar7 < 0x1f) {
      dVar11 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a930 * DAT_14053a020 *
                                     DAT_140539d28);
      local_res10 = (float)(dVar11 * dVar3) + fVar2;
    }
    iVar5 = (iVar1 + -6) % 0x1e;
    fVar23 = DAT_14053b310;
    if (iVar5 < 0x1f) {
      dVar11 = (double)FUN_140332d90(((double)iVar5 - 0.0) * dVar12 * dVar13 * dVar14);
      fVar23 = (float)(dVar11 * dVar3) - DAT_14053abf8;
    }
    local_res8 = DAT_14053b328;
    iVar5 = (iVar1 + -0xc) % 0x1e;
    if (iVar5 < 0x1f) {
      dVar11 = (double)FUN_140332d90(((double)iVar5 - 0.0) * dVar12 * dVar13 * dVar14);
      local_res8 = (float)(dVar11 * dVar3) - DAT_14053ac34;
    }
    dVar3 = DAT_14053b0d8;
    fVar25 = fVar2;
    if (iVar1 % 0x3c < 0x1f) {
      dVar11 = (double)FUN_140332d90(((double)(iVar1 % 0x3c) - 0.0) * dVar12 * dVar13 * dVar14);
      fVar25 = (float)(dVar11 * dVar3) + fVar2;
    }
    iVar5 = (iVar1 + -0x1e) % 0x3c;
    fVar24 = fVar2;
    if (iVar5 < 0x1f) {
      dVar12 = (double)FUN_140332d90(((double)iVar5 - 0.0) * dVar12 * dVar13 * dVar14);
      fVar24 = (float)(dVar12 * dVar3) + fVar2;
    }
    if (iVar1 == 0) {
      *(undefined8 *)(param_1 + 0x12) = 0x3ff0000000000000;
    }
    if (param_1[0x15] == 1) {
      if ((((DAT_140e445d8 / DAT_14053ab70 + DAT_14053aca8 <= (float)param_1[10]) &&
           ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aea8)) &&
          (DAT_14053aca8 <= fVar22)) && (fVar22 <= DAT_14053aef4)) {
        param_1[0x15] = 0;
      }
    }
    if (0x13 < iVar7) {
      dVar14 = (double)*(ushort *)(param_1 + 0x10) * dVar13 * dVar14;
      dVar13 = (double)FUN_1403307c0(dVar14);
      param_1[10] = (float)(dVar13 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar14 = (double)FUN_140332d90(dVar14);
      param_1[0xb] = (float)(dVar14 * *(double *)(param_1 + 0x12)) + fVar22;
    }
    fVar22 = DAT_140e445d8;
    uVar10 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
    if ((float)param_1[0xb] < DAT_14053ae30) {
      fVar21 = (float)param_1[10] - DAT_14053ac60;
      fVar18 = ((float)param_1[0xb] + fVar23) - DAT_14053acbc;
      dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18),
                                     (double)(DAT_140e445d8 - fVar21));
      uVar10 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
      iVar7 = 1;
      dVar14 = dVar14 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0x27;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 0x18;
      }
      else if (DAT_140e419b8 == 2) {
        iVar7 = 0x12;
      }
      else if (DAT_140e419b8 == 3) {
        iVar7 = 0xe;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 0xc;
      }
      uVar20 = (undefined4)DAT_140539f40;
      uVar16 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      if (DAT_140e419b8 == 0) {
        uVar20 = (undefined4)DAT_14053a0d0;
        uVar16 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar20 = (undefined4)DAT_14053a118;
        uVar16 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar20 = (undefined4)DAT_14053a138;
        uVar16 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar20 = (undefined4)DAT_14053a158;
        uVar16 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar20 = (undefined4)DAT_14053a1b8;
        uVar16 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
      }
      if ((((-1 < iVar1) && (iVar1 % iVar7 == 0)) &&
          ((fVar17 = fVar22 / DAT_14053ab70, fVar17 + 0.0 <= fVar21 &&
           ((fVar21 <= fVar17 + DAT_14053aec0 && (0.0 <= fVar18)))))) && (fVar18 <= DAT_14053af14))
      {
        fVar17 = (float)FUN_140334430(fVar21 - fVar22,DAT_140539fc0);
        fVar22 = (float)FUN_140334430(fVar18 - DAT_140e445dc);
        fVar17 = fVar17 + fVar22;
        if (fVar17 < 0.0) {
          fVar17 = (float)FUN_1403352f8(fVar17);
        }
        else {
          fVar17 = SQRT(fVar17);
        }
        uVar9 = DAT_14053ac2c;
        uVar10 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
        if (DAT_14053acbc < fVar17) {
          uVar28 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
          sVar6 = (short)(((int)dVar14 & 0xffffU) + 0x800 >> 0xc) * 0x1000;
          FUN_14006c2f0(9,0,fVar21,fVar18,CONCAT22(uVar26,sVar6),DAT_14053ac2c,
                        CONCAT44(uVar16,uVar20),CONCAT44(uVar19,1),uVar28);
          uVar28 = uVar28 & 0xffffffff00000000;
          FUN_14006c2f0(9,0,fVar21,fVar18,sVar6,uVar9,
                        (double)CONCAT44(uVar16,uVar20) + DAT_140539ec8,1,uVar28);
          uVar10 = (undefined4)(uVar28 >> 0x20);
          in_stack_fffffffffffffef0 = uVar9;
        }
      }
    }
    uVar4 = _UNK_14053bb2c;
    uVar16 = _UNK_14053bb28;
    uVar20 = _UNK_14053bb24;
    uVar19 = _DAT_14053bb20;
    uVar15 = CONCAT44(uVar10,0xff);
    uVar9 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e44848,0x19,7,param_1[10],local_res8 + (float)param_1[0xb],uVar9,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  uVar15,0xff,0xff,0xff,1,0);
    uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),0xff);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e4483c,0x19,7,param_1[10],fVar25 + (float)param_1[0xb],uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar15,0xff,0xff,0xff,1,0);
    uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),0xff);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e4483c,0x19,7,param_1[10],fVar24 + (float)param_1[0xb],uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar15,0xff,0xff,0xff,1,1);
    uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),0xff);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e44840,0x19,7,param_1[10],local_res10 + (float)param_1[0xb],uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar15,0xff,0xff,0xff,1,0);
    uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),0xff);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e44844,0x19,7,param_1[10],local_res8 + (float)param_1[0xb],uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar15,0xff,0xff,0xff,1,0);
    uVar28 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),0xff);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e4484c,0x19,7,param_1[10],fVar23 + (float)param_1[0xb],uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar28,0xff,0xff,0xff,1,0);
    uVar9 = uVar9 & 0xffff0000;
    FUN_1400c8410(DAT_140e44850,0x18,7,param_1[10],(float)param_1[0xb] + fVar2,uVar9,
                  CONCAT44(uVar20,uVar19),CONCAT44(uVar4,uVar16),uVar28 & 0xffffffff00000000,0,0,
                  0x40,1,0);
    uVar27 = (undefined2)(uVar9 >> 0x10);
    if (param_1[0x15] == 0) {
      FUN_140079c10(param_1,2);
    }
  }
  else {
    uVar19 = (undefined4)DAT_140539f40;
    uVar20 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  }
  if ((int)param_1[7] < 1) {
    uVar8 = param_1[1] + DAT_140e418c8;
    uVar9 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar9 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar9 = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
    DAT_140e9fd1c = uVar9;
    uVar15 = FUN_140134db0(uVar8,DAT_140539f28,DAT_140539f38);
    uVar10 = (undefined4)uVar15;
    uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar15 = FUN_140134db0(uVar8);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],(float)param_1[0xb] + DAT_14053ac58,
                  CONCAT22(uVar27,(short)uVar9 - (short)(uVar9 / 0x10001)),CONCAT44(uVar20,uVar19),
                  uVar15,CONCAT44(uVar16,uVar10),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,1000,4);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (param_1[0x15] == 0) {
    if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad1c) ||
         (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af04 < (float)param_1[10])) ||
        ((float)param_1[0xb] < DAT_14053b380)) || (DAT_14053af54 < (float)param_1[0xb])) {
      *param_1 = 0;
    }
  }
  return;
}


