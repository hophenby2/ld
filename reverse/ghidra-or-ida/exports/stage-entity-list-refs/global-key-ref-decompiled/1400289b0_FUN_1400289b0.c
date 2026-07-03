// Function: FUN_1400289b0 @ 1400289b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1400289b0(undefined4 *param_1)

{
  float fVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  short sVar12;
  int iVar13;
  ulonglong uVar14;
  ushort uVar15;
  short sVar16;
  int iVar17;
  undefined2 uVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int iStack_134;
  int iStack_12c;
  undefined8 uStack_b8;
  
  iStack_12c = 0;
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == DAT_140e44308) {
        iStack_134 = *(int *)(lVar3 + 0x14);
        iStack_12c = *(int *)(lVar3 + 0x1c);
      }
    }
  }
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == param_1[2]) {
        uStack_b8 = *(undefined8 *)(lVar3 + 0x28);
      }
    }
  }
  fVar1 = (float)param_1[0xe];
  dVar19 = (double)FUN_1403307c0();
  fVar21 = (float)(dVar19 * (double)fVar1) + (float)uStack_b8;
  dVar19 = (double)FUN_140332d90();
  param_1[10] = fVar21;
  uStack_b8._4_4_ = (float)(dVar19 * (double)fVar1) + uStack_b8._4_4_;
  param_1[0xb] = uStack_b8._4_4_;
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_b8._4_4_),
                                 SUB84((double)(DAT_140e445d8 - fVar21),0));
  iVar11 = DAT_140e419b8;
  uVar5 = DAT_14053ac2c;
  dVar19 = DAT_140539f40;
  uVar24 = SUB84(DAT_140539f40,0);
  uVar4 = (ulonglong)DAT_140539f40 >> 0x20;
  uVar18 = (undefined2)(int)(dVar20 * DAT_14053aba0);
  if (param_1[6] == 0x6b) {
    iVar17 = 1;
    if (DAT_140e419b8 == 0) {
      iVar17 = 0x28;
    }
    else if (DAT_140e419b8 == 1) {
      iVar17 = 0x37;
    }
    else if (DAT_140e419b8 == 2) {
LAB_140028b6e:
      iVar17 = 0x41;
    }
    else if (DAT_140e419b8 == 3) {
      iVar17 = 0x4b;
    }
    else if (DAT_140e419b8 == 4) goto LAB_140028b6e;
    uVar10 = 1;
    if (DAT_140e419b8 == 0) {
      uVar10 = 5;
    }
    else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
      uVar10 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      uVar10 = 9;
    }
    dVar20 = DAT_14053a0d0;
    if (((DAT_140e419b8 != 0) && (dVar20 = DAT_14053a110, DAT_140e419b8 != 1)) &&
       ((dVar20 = DAT_14053a138, DAT_140e419b8 != 2 &&
        ((DAT_140e419b8 != 3 && (dVar20 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
      dVar20 = DAT_14053a178;
    }
    uVar7 = param_1[3];
    dVar20 = (double)(int)uVar7 * _DAT_140539d80 + dVar20;
    if (uVar7 < 300) {
      if (uVar7 == ((int)uVar7 / 100) * 100) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar18;
      }
      else if (299 < uVar7) goto LAB_140028d4e;
      iVar13 = (int)uVar7 % 100;
      if ((iVar13 < iVar17) && (iVar13 == (iVar13 / 5) * 5)) {
        FUN_1400709b0(10,0,fVar21,param_1[0xb],*(short *)((longlong)param_1 + 0x42) + 300,uVar5,
                      dVar20,1,uVar10,30000,0);
        FUN_1400709b0(10,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + -300,
                      uVar5,dVar20,1,uVar10,30000,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar11 = DAT_140e419b8;
      }
    }
LAB_140028d4e:
    iVar17 = param_1[3];
    if (599 < iVar17) {
      iVar13 = 1;
      if (iVar11 == 0) {
        iVar13 = 0x2008;
      }
      else if (iVar11 == 1) {
        iVar13 = 7000;
      }
      else if (iVar11 == 2) {
        iVar13 = 0x19c8;
      }
      else if (iVar11 == 3) {
        iVar13 = 6000;
      }
      else if (iVar11 == 4) {
        iVar13 = 0x157c;
      }
      iVar9 = iVar13 * 3;
      uVar14 = 1;
      if (iVar11 == 0) {
        uVar14 = 0x140;
      }
      else if (iVar11 == 1) {
        uVar14 = 0x118;
      }
      else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
        uVar14 = 0xf0;
      }
      if (iVar17 == 600) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar18;
LAB_140028dff:
        uVar15 = *(ushort *)((longlong)param_1 + 0x42);
        uVar6 = 0x4000 - uVar15;
        iVar9 = iVar9 + ((iVar13 * -3 + 0xfffa) / 0x96) * (0x2ee - iVar17);
        uVar7 = (uint)uVar6;
        if (0x8000 < uVar6) {
          uVar7 = 0x10000 - uVar6;
        }
        iVar8 = -(uint)uVar15 + 0x4000;
        iVar17 = (int)uVar7 / 0x78;
        iVar13 = -(uint)uVar15 + 0x14000;
        if (-0x8001 < iVar8) {
          iVar13 = iVar8;
        }
        iVar8 = iVar13 + -0x10000;
        if (iVar13 < 0x8001) {
          iVar8 = iVar13;
        }
        if (iVar8 < 1) {
          if ((iVar8 < 0) && (uVar15 = uVar15 - (short)iVar17, -iVar17 < iVar8)) {
            uVar15 = 0x4000;
          }
        }
        else if (iVar8 < iVar17) {
          uVar15 = 0x4000;
        }
        else {
          uVar15 = uVar15 + (short)iVar17;
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar15;
      }
      else if (iVar17 - 600U < 0x96) goto LAB_140028dff;
      iVar17 = param_1[3];
      sVar16 = *(short *)((longlong)param_1 + 0x42);
      if (0x2ed < iVar17) {
        lVar3 = (longlong)((int)(uVar14 >> 2) + -0x2ee + iVar17) % (longlong)(int)uVar14;
        iVar13 = (int)lVar3;
        uVar2 = 12000 / (uVar14 >> 1);
        sVar12 = (short)uVar2;
        if ((int)(uVar14 >> 1) <= iVar13) {
          sVar12 = (short)uVar14 - (short)lVar3;
          iVar13 = (int)uVar2;
        }
        sVar16 = sVar16 + sVar12 * (short)iVar13 + -6000;
      }
      if (DAT_140e445dc < (float)param_1[0xb]) {
        sVar16 = sVar16 + -0x8000;
      }
      if ((0x259 < iVar17) && (iVar17 + -0x25a == ((iVar17 + -0x25a) / 5) * 5)) {
        FUN_1400709b0(0xb,0,param_1[10],param_1[0xb],sVar16,uVar5,DAT_14053a218,1,4,iVar9,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar11 = DAT_140e419b8;
      }
      if (DAT_140e445fc != 0) {
        param_1[3] = 600;
      }
    }
  }
  if (param_1[6] == 0x6c) {
    iVar17 = 1;
    if (iVar11 == 0) {
      iVar17 = 9;
    }
    else if (iVar11 == 1) {
LAB_140028ff3:
      iVar17 = 5;
    }
    else {
      if (iVar11 != 2) {
        if (iVar11 == 3) goto LAB_140028ff3;
        if (iVar11 != 4) goto LAB_140028fff;
      }
      iVar17 = 4;
    }
LAB_140028fff:
    iVar13 = 1;
    if (iVar11 != 0) {
      if (iVar11 == 1) {
        iVar13 = 2;
      }
      else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
        iVar13 = 3;
      }
    }
    uVar7 = param_1[3];
    iVar13 = (int)uVar7 / 0x4b + iVar13;
    dVar20 = DAT_14053a038;
    if (((iVar11 != 0) && (dVar20 = DAT_14053a070, iVar11 != 1)) &&
       ((dVar20 = DAT_14053a080, iVar11 != 2 &&
        ((dVar20 = DAT_14053a070, iVar11 != 3 && (dVar20 = dVar19, iVar11 == 4)))))) {
      dVar20 = DAT_14053a0b0;
    }
    dVar20 = (double)((int)uVar7 % 0x4b) * _DAT_140539e08 + dVar20 +
             (double)((int)uVar7 / 0x4b) * DAT_140539ef8;
    if ((int)uVar7 < 0x12d) {
      sVar16 = (short)((int)uVar7 / 0x96);
      if ((int)uVar7 % 0x96 < 0x4b) {
        sVar16 = (short)uVar7 * 0x1b4 + sVar16 * 0x88;
      }
      else {
        sVar16 = (short)uVar7 * -0x1b4 + sVar16 * -0x88 + -0x88;
      }
      *(short *)((longlong)param_1 + 0x42) = sVar16;
    }
    if ((uVar7 < 300) && ((int)((longlong)(int)uVar7 % (longlong)iVar17) == 0)) {
      FUN_1400709b0(3,(longlong)(int)uVar7 % (longlong)iVar17 & 0xffffffff,param_1[10],param_1[0xb],
                    *(undefined2 *)((longlong)param_1 + 0x42),uVar5,dVar20,1,iVar13,0x10000,0);
      if (2 < DAT_140e419b8) {
        sVar16 = 0x4b0;
        if ((int)param_1[3] % 0x96 < 0x4b) {
          sVar16 = -0x4b0;
        }
        FUN_1400709b0(3,0,param_1[10],param_1[0xb],*(short *)((longlong)param_1 + 0x42) + sVar16,
                      uVar5,dVar20 + DAT_140539f68,1,iVar13,0x10000,0);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      iVar11 = DAT_140e419b8;
    }
  }
  uVar14 = (ulonglong)(param_1[6] - 0x6c);
  if (1 < param_1[6] - 0x6c) goto LAB_1400297ff;
  iVar17 = 1;
  if (iVar11 == 0) {
    iVar17 = 0x23;
  }
  else if (iVar11 == 1) {
    iVar17 = 0x1b;
  }
  else if (iVar11 == 2) {
    iVar17 = 0x18;
  }
  else if (iVar11 == 3) {
    iVar17 = 0x16;
  }
  else if (iVar11 == 4) {
    iVar17 = 0x12;
  }
  uVar10 = 1;
  if (iVar11 == 0) {
    uVar10 = 7;
  }
  else if ((iVar11 == 1) || (iVar11 == 2)) {
LAB_1400292c4:
    uVar10 = 9;
  }
  else if (iVar11 == 3) {
    uVar10 = 8;
  }
  else if (iVar11 == 4) goto LAB_1400292c4;
  iVar13 = 1;
  if (iVar11 == 0) {
    iVar13 = 3;
  }
  else if (iVar11 == 1) {
    iVar13 = 4;
  }
  else if (iVar11 == 2) {
    iVar13 = 5;
  }
  else if ((iVar11 == 3) || (iVar11 == 4)) {
    iVar13 = 6;
  }
  uVar22 = SUB84(DAT_14053a120,0);
  uVar23 = (undefined4)((ulonglong)DAT_14053a120 >> 0x20);
  dVar20 = DAT_14053a0a0;
  if ((((iVar11 != 0) && (dVar20 = DAT_14053a0c8, iVar11 != 1)) &&
      (dVar20 = DAT_14053a0f8, iVar11 != 2)) &&
     ((dVar20 = DAT_14053a120, iVar11 != 3 && (dVar20 = dVar19, iVar11 == 4)))) {
    dVar20 = DAT_14053a160;
  }
  uVar7 = param_1[3] - 0x140;
  uVar14 = (ulonglong)uVar7;
  if ((uVar7 < 0x118) &&
     (uVar14 = (longlong)(int)uVar7 / (longlong)iVar17 & 0xffffffff, (int)uVar7 % iVar17 == 0)) {
    iVar11 = 0;
    do {
      if (param_1[6] == 0x6c) {
        uVar7 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
        FUN_1400709b0(5,0,param_1[10],param_1[0xb],
                      ((short)iVar11 * 600 - (short)(DAT_140e9fd1c / 0x10001)) +
                      (short)DAT_140e9fd1c,0,dVar20,1,uVar10,0x10000,0);
      }
      if (param_1[6] == 0x6d) {
        uVar7 = (param_1[3] + 1 >> 0x1e ^ param_1[3] + 1) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
        FUN_1400709b0(4,0,param_1[10],param_1[0xb],
                      ((short)iVar11 * -600 - (short)(DAT_140e9fd1c / 0x10001)) +
                      (short)DAT_140e9fd1c,0,dVar20,1,uVar10,0x10000,0);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar13);
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
    uVar14 = FUN_14018a340(DAT_140e472a4,1,1);
    iVar11 = DAT_140e419b8;
  }
  if ((int)param_1[3] < 0x302) goto LAB_1400297ff;
  iVar17 = 1;
  if (iVar11 == 0) {
    iVar17 = 0x4b;
  }
  else if (iVar11 == 1) {
    iVar17 = 0x2d;
  }
  else if (iVar11 == 2) {
    iVar17 = 0x27;
  }
  else if (iVar11 == 3) {
    iVar17 = 0x24;
  }
  else if (iVar11 == 4) {
    iVar17 = 0x1e;
  }
  iVar13 = 1;
  if (iVar11 == 0) {
LAB_140029656:
    uVar22 = SUB84(DAT_14053a0d0,0);
    uVar23 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  }
  else {
    if ((iVar11 == 1) || (iVar11 == 2)) {
      iVar13 = 3;
    }
    else if ((iVar11 == 3) || (iVar11 == 4)) {
      iVar13 = 5;
    }
    if (iVar11 == 0) goto LAB_140029656;
    if (iVar11 != 1) {
      if (iVar11 == 2) {
        uVar22 = (undefined4)DAT_14053a140;
        uVar23 = (undefined4)((ulonglong)DAT_14053a140 >> 0x20);
      }
      else if (iVar11 == 3) {
        uVar22 = SUB84(DAT_14053a160,0);
        uVar23 = (undefined4)((ulonglong)DAT_14053a160 >> 0x20);
      }
      else {
        uVar22 = uVar24;
        uVar23 = (int)uVar4;
        if (iVar11 == 4) {
          uVar22 = (undefined4)DAT_14053a1b8;
          uVar23 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
        }
      }
    }
  }
  if (param_1[6] == 0x6d) {
    iVar11 = param_1[3] + -0x302;
    uVar14 = (longlong)iVar11 / (longlong)(iVar17 * 2) & 0xffffffff;
    uVar7 = iVar11 % (iVar17 * 2);
    if (uVar7 == 0) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar18;
    }
    if ((0x301 < (int)param_1[3]) && ((int)uVar7 < 0xc)) {
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        FUN_1400709b0(0xc,0,param_1[10],param_1[0xb],*(undefined2 *)((longlong)param_1 + 0x42),uVar5
                      ,CONCAT44(uVar23,uVar22),1,iVar13,iVar13 * 0x960 + -0x960,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        uVar14 = FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
  }
  if (param_1[6] == 0x6c) {
    iVar9 = param_1[3];
    iVar11 = iVar17 + 0x302;
    if (iVar11 <= iVar9) {
      uVar14 = (longlong)(iVar9 - iVar11) / (longlong)(iVar17 * 2) & 0xffffffff;
      if ((iVar9 - iVar11) % (iVar17 * 2) == 0) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar18;
        uVar14 = (longlong)(iVar9 - iVar11) / (longlong)(iVar17 * 2) & 0xffffffff;
        uVar7 = (iVar9 - iVar11) % (iVar17 * 2);
      }
      else {
        if (iVar9 < iVar11) goto LAB_1400297ff;
        uVar14 = (longlong)(iVar9 - iVar11) / (longlong)(iVar17 * 2) & 0xffffffff;
        uVar7 = (iVar9 - iVar11) % (iVar17 * 2);
        if (0xb < (int)uVar7) goto LAB_1400297ff;
      }
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if ((uVar7 == 0) && (param_1[6] == 0x6c)) {
        FUN_1400709b0(0xc,0,param_1[10],param_1[0xb],*(undefined2 *)((longlong)param_1 + 0x42),uVar5
                      ,CONCAT44(uVar23,uVar22),1,iVar13,iVar13 * 0x960 + -0x960,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        uVar14 = FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
  }
LAB_1400297ff:
  if (((iStack_12c < 1) || (DAT_140e4430c < 1)) || (iStack_134 == 4)) {
    *param_1 = 0;
  }
  return uVar14;
}


