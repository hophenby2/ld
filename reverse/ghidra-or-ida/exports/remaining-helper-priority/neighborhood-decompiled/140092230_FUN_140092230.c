// Function: FUN_140092230 @ 140092230
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140092230(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  undefined8 uVar13;
  int iVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  double dVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  float fVar26;
  float fVar27;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar28;
  undefined4 in_stack_fffffffffffffef0;
  undefined2 uVar29;
  undefined8 in_stack_ffffffffffffff00;
  undefined4 uVar30;
  
  uVar5 = DAT_140e418c8;
  fVar21 = DAT_14053ab70;
  dVar22 = DAT_14053a798;
  dVar19 = DAT_14053a020;
  dVar18 = DAT_140539f40;
  dVar17 = DAT_140539d28;
  uVar29 = (undefined2)((uint)in_stack_fffffffffffffef0 >> 0x10);
  uVar28 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  uVar30 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  iVar9 = param_1[5];
  uVar13 = 0x23;
  iVar14 = 0xff;
  uVar24 = SUB84(DAT_140539f68,0);
  uVar25 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
  if (iVar9 == 0) {
    if (param_1[3] == 0) {
      uVar11 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar11 = uVar11 * 0x800 ^ uVar11;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
      *(short *)(param_1 + 0x10) =
           (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0xfa1) * -0xfa1 + -0x47d0;
    }
    uVar13 = 0xc;
    dVar16 = (double)(int)param_1[3];
    iVar14 = (int)(dVar16 * _DAT_140539fd0);
    dVar16 = dVar16 * _DAT_140539db8;
  }
  else {
    dVar16 = DAT_140539f40;
    if (iVar9 != 1) goto LAB_140092846;
  }
  iVar7 = param_1[3];
  dVar23 = dVar16 * DAT_14053a178;
  dVar17 = (double)FUN_140332d90(((double)(iVar7 % 0x1e) - 0.0) * dVar22 * dVar19 * dVar17);
  dVar23 = dVar17 * (double)CONCAT44((uint)((ulonglong)dVar23 >> 0x20) ^ _UNK_14053bef4,
                                     SUB84(dVar23,0) ^ ram0x00014053bef0) + dVar23;
  *(double *)(param_1 + 0x12) = dVar23;
  sVar3 = *(short *)(param_1 + 0x10) + 0xd05;
  if (0x1d < iVar7 % 0x3c) {
    sVar3 = *(short *)(param_1 + 0x10) + -0xd05;
  }
  *(short *)((longlong)param_1 + 0x42) = sVar3;
  dVar17 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar17 * dVar23) + (float)param_1[10];
  param_1[10] = fVar27;
  dVar17 = (double)FUN_140332d90();
  fVar26 = (float)(dVar17 * dVar23) + (float)param_1[0xb];
  param_1[0xb] = fVar26;
  fVar2 = DAT_140e445dc;
  fVar1 = DAT_140e445d8;
  if ((((iVar9 == 1) && (fVar20 = DAT_140e445d8 / fVar21, fVar20 - DAT_14053ac58 <= fVar27)) &&
      (fVar27 <= fVar20 + DAT_14053aecc)) &&
     ((DAT_14053b330 <= fVar26 && (fVar26 <= _DAT_14053af24)))) {
    fVar20 = (float)FUN_140334430(fVar26 - DAT_140e445dc,DAT_140539fc0);
    fVar15 = (float)FUN_140334430(fVar27 - fVar1);
    if (fVar20 + fVar15 < 0.0) {
      fVar20 = (float)FUN_1403352f8();
    }
    else {
      fVar20 = SQRT(fVar20 + fVar15);
    }
    if (DAT_14053acbc < fVar20) {
      dVar17 = (double)FUN_1403300b4((double)(fVar2 - fVar26),(double)(fVar1 - fVar27));
      iVar9 = 1;
      dVar17 = dVar17 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar9 = 100;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 0x3c;
      }
      else if (DAT_140e419b8 == 2) {
        iVar9 = 0x32;
      }
      else if (DAT_140e419b8 == 3) {
        iVar9 = 0x28;
      }
      else if (DAT_140e419b8 == 4) {
        iVar9 = 0x20;
      }
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 10;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 7;
      }
      else if (DAT_140e419b8 == 2) {
        iVar7 = 5;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar7 = 4;
      }
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 600;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 800;
      }
      else if (DAT_140e419b8 == 2) {
        iVar12 = 1000;
      }
      else if (DAT_140e419b8 == 3) {
        iVar12 = 0x4b0;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 0x578;
      }
      dVar19 = DAT_14053a078;
      if ((((DAT_140e419b8 != 0) && (dVar19 = DAT_14053a0b8, DAT_140e419b8 != 1)) &&
          (dVar19 = DAT_14053a0f8, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar19 = dVar18, DAT_140e419b8 == 4)))) {
        dVar19 = DAT_14053a158;
      }
      iVar4 = param_1[3];
      if (9 < iVar4) {
        uVar10 = (ushort)(int)dVar17;
        if ((iVar4 + -10) % iVar9 == 0) {
          *(ushort *)(param_1 + 0x11) = uVar10;
          iVar9 = (iVar4 + -10) % iVar9;
        }
        else if ((iVar4 < 10) || (iVar9 = (iVar4 + -10) % iVar9, 0x17 < iVar9)) goto LAB_140092810;
        if (iVar9 % iVar7 == 0) {
          sVar6 = FUN_140134d00(iVar4 * 0xad9c + uVar5,-iVar12,iVar12);
          sVar3 = *(short *)(param_1 + 0x11);
          uVar29 = 0;
          FUN_14006c2f0(0,0,fVar27,fVar26,CONCAT22(uVar28,sVar6 + sVar3),0,dVar19,CONCAT44(uVar30,1)
                        ,0);
          uVar24 = SUB84(DAT_140539f68,0);
          uVar25 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
          if (2 < DAT_140e419b8) {
            uVar29 = 0;
            FUN_14006c2f0(0,0,fVar27,fVar26,sVar6 + sVar3,0,dVar19 + DAT_140539f68,1,0);
          }
          uVar8 = *(ushort *)(param_1 + 0x11);
          iVar7 = ((int)dVar17 & 0xffffU) - (uint)uVar8;
          iVar9 = iVar7 + 0x10000;
          if (-0x8001 < iVar7) {
            iVar9 = iVar7;
          }
          iVar7 = iVar9 + -0x10000;
          if (iVar9 < 0x8001) {
            iVar7 = iVar9;
          }
          if (iVar7 < 1) {
            if ((iVar7 < 0) && (uVar8 = uVar8 - 0x80, -0x80 < iVar7)) {
              uVar8 = uVar10;
            }
            *(ushort *)(param_1 + 0x11) = uVar8;
          }
          else if (iVar7 < 0x80) {
            *(ushort *)(param_1 + 0x11) = uVar10;
          }
          else {
            *(ushort *)(param_1 + 0x11) = uVar8 + 0x80;
          }
          goto LAB_140092822;
        }
      }
    }
LAB_140092810:
    uVar24 = SUB84(DAT_140539f68,0);
    uVar25 = (undefined4)((ulonglong)DAT_140539f68 >> 0x20);
  }
LAB_140092822:
  if ((param_1[5] == 0) && (param_1[3] == 0x78)) {
    param_1[3] = 0;
    param_1[5] = 1;
    param_1[0x15] = 0;
  }
LAB_140092846:
  uVar28 = *(undefined2 *)((longlong)param_1 + 0x42);
  dVar22 = dVar16 * DAT_14053b138;
  dVar17 = (double)FUN_1403307c0();
  fVar1 = (float)param_1[10];
  dVar18 = (double)FUN_140332d90();
  fVar2 = (float)param_1[0xb];
  dVar19 = (double)FUN_140332d90();
  dVar23 = dVar19 * dVar16 * _DAT_14053b070 + dVar16 * (double)CONCAT44(uVar25,uVar24);
  dVar19 = (double)FUN_140332d90();
  FUN_1400c8410(DAT_140e44704,uVar13,7,(float)(dVar17 * (double)(float)dVar22) + fVar1,
                (float)(dVar18 * (double)(float)dVar22) + fVar2,CONCAT22(uVar29,uVar28),
                dVar19 * dVar16 * DAT_140539ee0 + dVar16 * DAT_140539f38,dVar23,0xff,0xff,0xff,
                iVar14,1,0);
  FUN_1400c8410(DAT_140e44700,uVar13,7,param_1[10],param_1[0xb],
                *(undefined2 *)((longlong)param_1 + 0x42),dVar16,dVar23,0xff,0xff,0xff,iVar14,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,3);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  fVar21 = DAT_140e445d8 / fVar21;
  if (((((float)param_1[10] < fVar21 - DAT_14053acd4) ||
       (fVar21 + _DAT_14053aeec < (float)param_1[10])) || ((float)param_1[0xb] < DAT_14053b368)) ||
     (_DAT_14053af3c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


