// Function: FUN_1400ee710 @ 1400ee710
// Decompile completed: true

ulonglong FUN_1400ee710(undefined4 *param_1)

{
  short *psVar1;
  float fVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  short sVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  double dVar16;
  float fVar17;
  undefined8 uStack_110;
  undefined8 local_f8;
  int iStack_b4;
  
  iStack_b4 = 0;
  lVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        iStack_b4 = *(int *)(lVar4 + 0x1c);
      }
    }
  }
  lVar4 = DAT_140e45d80;
  sVar11 = local_f8._4_2_;
  if (0 < DAT_140e44e6c) {
    for (; sVar11 = (short)((ulonglong)local_f8 >> 0x20), lVar4 != 0;
        lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == param_1[2]) {
        uStack_110 = *(undefined8 *)(lVar4 + 0x28);
        local_f8 = *(undefined8 *)(lVar4 + 0x40);
      }
    }
  }
  local_f8._4_2_ = sVar11;
  fVar2 = (float)param_1[0xe];
  uVar13 = SUB84((double)(ushort)(local_f8._4_2_ + *(short *)(param_1 + 0x10)) * DAT_14053a020 *
                 DAT_140539d28,0);
  dVar16 = (double)FUN_1403307c0(uVar13);
  fVar17 = (float)(dVar16 * (double)fVar2) + (float)uStack_110;
  dVar16 = (double)FUN_140332d90(uVar13);
  param_1[10] = fVar17;
  uStack_110._4_4_ = (float)(dVar16 * (double)fVar2) + uStack_110._4_4_;
  param_1[0xb] = uStack_110._4_4_;
  dVar16 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - uStack_110._4_4_),0),
                                 SUB84((double)(DAT_140e445d8 - fVar17),0));
  uVar15 = DAT_14053a178;
  uVar5 = (ulonglong)(uint)(((int)param_1[3] / 0x514) * 0x514);
  uVar8 = (int)param_1[3] % 0x514;
  sVar11 = (short)(int)(dVar16 * DAT_14053aba0);
  if ((int)uVar8 < 0x21c) {
    iVar9 = 1;
    if (DAT_140e419b8 == 0) {
      iVar9 = 0x28;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0x22;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar9 = 0x1e;
    }
    iVar10 = 1;
    if (DAT_140e419b8 == 0) {
      iVar10 = 0x14;
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      iVar10 = 0x19;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar10 = 0x1e;
    }
    sVar12 = 1;
    if ((((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) || (DAT_140e419b8 == 2)) ||
       ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
      sVar12 = 0x78;
    }
    uVar13 = 1;
    if (DAT_140e419b8 == 0) {
      uVar13 = 0xb;
    }
    else if (DAT_140e419b8 == 1) {
      uVar13 = 0x11;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      uVar13 = 0x13;
    }
    else if (DAT_140e419b8 == 4) {
      uVar13 = 0x17;
    }
    uVar15 = DAT_14053a138;
    if ((((DAT_140e419b8 != 0) && (uVar15 = DAT_14053a1b0, DAT_140e419b8 != 1)) &&
        (uVar15 = DAT_14053a190, DAT_140e419b8 != 2)) &&
       ((uVar15 = DAT_14053a1b8, DAT_140e419b8 != 3 && (uVar15 = DAT_140539f40, DAT_140e419b8 == 4))
       )) {
      uVar15 = DAT_14053a1e8;
    }
    if (uVar8 == 0) {
      *(short *)((longlong)param_1 + 0x42) = sVar11;
    }
    if ((param_1[6] == 0xcb) && (uVar8 < 0x21c)) {
      uVar5 = (longlong)(int)uVar8 / (longlong)(iVar9 * 2) & 0xffffffff;
      uVar6 = (int)uVar8 % (iVar9 * 2);
      if (((int)uVar6 < iVar10) &&
         (uVar3 = ((int)uVar6 / 5) * 5, uVar5 = (ulonglong)uVar3, uVar6 == uVar3)) {
        FUN_1400709b0(3,7,fVar17,param_1[0xb],
                      sVar12 * *(short *)(param_1 + 3) + *(short *)((longlong)param_1 + 0x42),0,
                      uVar15,1,uVar13,0x10000,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        uVar5 = FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    if ((param_1[6] == 0xcc) && (iVar9 <= (int)uVar8)) {
      uVar5 = (longlong)(int)(uVar8 - iVar9) / (longlong)(iVar9 * 2) & 0xffffffff;
      uVar8 = (int)(uVar8 - iVar9) % (iVar9 * 2);
      if (((int)uVar8 < iVar10) &&
         (uVar6 = ((int)uVar8 / 5) * 5, uVar5 = (ulonglong)uVar6, uVar8 == uVar6)) {
        FUN_1400709b0(2,7,param_1[10],param_1[0xb],
                      *(short *)((longlong)param_1 + 0x42) - *(short *)(param_1 + 3) * sVar12,0,
                      uVar15,1,uVar13,0x10000,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        uVar5 = FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    goto LAB_1400eef9d;
  }
  if (uVar8 == 0x280) {
    uVar8 = 1;
    if (DAT_140e419b8 == 0) {
      uVar8 = 9;
    }
    else if (DAT_140e419b8 == 1) {
      uVar8 = 0xb;
    }
    else if (DAT_140e419b8 == 2) {
      uVar8 = 0xd;
    }
    else if (DAT_140e419b8 == 3) {
      uVar8 = 0xf;
    }
    else if (DAT_140e419b8 == 4) {
      uVar8 = 0x11;
    }
    if (param_1[6] == 0xcb) {
      uVar13 = param_1[0xb];
      uVar14 = param_1[10];
      if (uVar8 == 1) {
        FUN_14006c2f0(3,0x29,uVar14,uVar13,sVar11,0,DAT_14053a178,1,0);
      }
      else {
        iVar9 = 0;
        do {
          FUN_14006c2f0(3,0x29,uVar14,uVar13,
                        (short)iVar9 * (short)(0x10000 / (ulonglong)uVar8) + sVar11,0,uVar15,1,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar8);
      }
    }
    if (param_1[6] == 0xcc) {
      uVar13 = param_1[0xb];
      uVar14 = param_1[10];
      if (uVar8 == 1) {
        FUN_14006c2f0(2,0x2a,uVar14,uVar13,sVar11,0,uVar15,1,0);
      }
      else {
        iVar9 = 0;
        do {
          FUN_14006c2f0(2,0x2a,uVar14,uVar13,
                        (short)iVar9 * (short)(0x10000 / (ulonglong)uVar8) + sVar11,0,uVar15,1,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar8);
      }
    }
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
    uVar5 = FUN_14018a340(DAT_140e472a4,1,1);
    goto LAB_1400eef9d;
  }
  if ((int)uVar8 < 0x348) goto LAB_1400eef9d;
  iVar9 = uVar8 - 0x348;
  iVar10 = 1;
  if (DAT_140e419b8 == 0) {
    iVar10 = 0x3c;
  }
  else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
          (DAT_140e419b8 == 4)) {
    iVar10 = 0x1e;
  }
  sVar12 = 1;
  if (DAT_140e419b8 == 0) {
    sVar12 = 0x3c;
  }
  else if (DAT_140e419b8 == 1) {
    sVar12 = 0x46;
  }
  else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
    sVar12 = 0x50;
  }
  else if (DAT_140e419b8 == 4) {
    sVar12 = 0x5a;
  }
  iVar7 = 1;
  sVar12 = sVar12 + (short)(iVar9 / iVar10) * 10;
  if (DAT_140e419b8 == 0) {
    iVar7 = 9;
  }
  else if (DAT_140e419b8 == 1) {
    iVar7 = 0xd;
  }
  else if (DAT_140e419b8 == 2) {
    iVar7 = 0xf;
  }
  else if (DAT_140e419b8 == 3) {
    iVar7 = 0x11;
  }
  else if (DAT_140e419b8 == 4) {
    iVar7 = 0x13;
  }
  uVar13 = (undefined4)DAT_140539f40;
  uVar14 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  if (DAT_140e419b8 == 0) {
    uVar13 = (undefined4)DAT_14053a0b0;
    uVar14 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
  }
  else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
    uVar13 = (undefined4)DAT_14053a0f8;
    uVar14 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
  }
  else if (DAT_140e419b8 == 4) {
    uVar13 = (undefined4)DAT_14053a138;
    uVar14 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
  }
  psVar1 = (short *)((longlong)param_1 + 0x42);
  dVar16 = (double)iVar9 * DAT_140539de8 + (double)CONCAT44(uVar14,uVar13);
  if (uVar8 == 0x348) {
    *psVar1 = (short)(0x10000 / (ulonglong)(uint)(iVar7 * 3)) * 2 + sVar11;
LAB_1400eeeb4:
    if (param_1[6] == 0xcb) {
      FUN_1400709b0(3,0,fVar17,param_1[0xb],*psVar1,0,dVar16,1,iVar7,0x10000,0);
    }
    if (param_1[6] == 0xcc) {
      FUN_1400709b0(2,0,param_1[10],param_1[0xb],*psVar1,0,dVar16,1,iVar7,0x10000,0);
    }
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
    FUN_14018a340(DAT_140e472a4,1,1);
  }
  else if ((int)uVar8 < 0x4ec) {
    uVar8 = uVar8 - 0x348 & 0x80000003;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
    }
    if (uVar8 == 0) goto LAB_1400eeeb4;
  }
  uVar5 = (longlong)iVar9 / (longlong)(iVar10 * 2) & 0xffffffff;
  if (iVar9 % (iVar10 * 2) < iVar10) {
    sVar12 = -sVar12;
  }
  *psVar1 = *psVar1 + sVar12;
LAB_1400eef9d:
  if ((iStack_b4 < 1) || (DAT_140e4430c < 1)) {
    *param_1 = 0;
  }
  return uVar5;
}


