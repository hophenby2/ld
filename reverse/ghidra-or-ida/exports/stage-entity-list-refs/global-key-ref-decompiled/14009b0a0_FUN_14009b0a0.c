// Function: FUN_14009b0a0 @ 14009b0a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14009b0a0(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  ushort uVar7;
  int iVar8;
  ulonglong *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  float fVar22;
  float fVar23;
  undefined4 in_stack_fffffffffffffe98;
  undefined2 uVar24;
  undefined4 in_stack_fffffffffffffea0;
  undefined2 uVar25;
  undefined8 in_stack_fffffffffffffeb0;
  undefined4 uVar26;
  ulonglong local_118;
  undefined8 uStack_100;
  undefined8 uStack_f0;
  
  uVar25 = (undefined2)((uint)in_stack_fffffffffffffea0 >> 0x10);
  uVar24 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar26 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  uStack_100._4_4_ = 0;
  local_118 = local_118 & 0xffffffff00000000;
  uStack_100 = 0;
  iVar12 = 0;
  if ((0 < DAT_140e44e6c) && (puVar9 = DAT_140e45d80, iVar12 = 0, DAT_140e45d80 != (ulonglong *)0x0)
     ) {
    do {
      if (*(int *)((longlong)puVar9 + 4) == param_1[2]) {
        local_118 = *puVar9;
        uStack_100 = puVar9[3];
        uStack_f0 = puVar9[5];
      }
      puVar9 = (ulonglong *)puVar9[0xc];
    } while (puVar9 != (ulonglong *)0x0);
    iVar12 = (int)local_118;
  }
  fVar23 = (float)uStack_f0 + (float)param_1[0xc];
  uStack_f0._4_4_ = uStack_f0._4_4_ + (float)param_1[0xd];
  dVar3 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - uStack_f0._4_4_),0),
                                SUB84((double)(DAT_140e445d8 - fVar23),0));
  dVar5 = DAT_14053a020;
  dVar4 = DAT_140539d28;
  uVar14 = (uint)(dVar3 * DAT_14053aba0);
  dVar3 = (double)FUN_140332d90(SUB84(((double)DAT_140e418c8 - 0.0) * _DAT_14053a928 * DAT_14053a020
                                      * DAT_140539d28,0));
  dVar6 = DAT_140539f40;
  uVar19 = SUB84(DAT_140539f40,0);
  uVar20 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  dVar3 = dVar3 * DAT_140539e60 + DAT_140539f40;
  if (param_1[5] == 0) {
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar15 = (uint)uVar1;
    uVar7 = (short)uVar14 - uVar1;
    iVar17 = ((int)(local_118 >> 0x20) - param_1[1]) * 7 + 0x2d;
    uVar10 = (uint)uVar7;
    if (0x8000 < uVar7) {
      uVar10 = 0x10000 - uVar7;
    }
    iVar11 = (uVar14 & 0xffff) - (uint)uVar1;
    iVar16 = (int)uVar10 / 10 + 0x30;
    iVar8 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar8 = iVar11;
    }
    iVar11 = iVar8 + -0x10000;
    if (iVar8 < 0x8001) {
      iVar11 = iVar8;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar15 = (uint)(ushort)(uVar1 - (short)iVar16), -iVar16 < iVar11)) {
        uVar15 = uVar14 & 0xffff;
      }
    }
    else if (iVar11 < iVar16) {
      uVar15 = uVar14 & 0xffff;
    }
    else {
      uVar15 = (uint)(ushort)(uVar1 + (short)iVar16);
    }
    *(short *)(param_1 + 0x10) = (short)uVar15;
    uVar21 = SUB84((double)uVar15 * dVar5 * dVar4,0);
    dVar4 = (double)FUN_1403307c0(uVar21);
    dVar4 = dVar4 * DAT_14053a2d8;
    fVar22 = (float)dVar4 + fVar23;
    dVar5 = (double)FUN_140332d90(uVar21);
    dVar5 = dVar5 * DAT_14053a2d8;
    param_1[10] = fVar22;
    fVar18 = (float)dVar5 + uStack_f0._4_4_;
    param_1[0xb] = fVar18;
    if (iVar17 <= (int)param_1[3]) {
      if ((((DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac80 <= fVar22) &&
           (fVar22 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aed4)) && (DAT_14053b33c <= fVar18))
         && (fVar18 <= DAT_14053af28)) {
        fVar22 = (float)dVar4 + fVar22;
        fVar18 = (float)dVar5 + fVar18;
        iVar8 = 1;
        if (DAT_140e419b8 == 0) {
          iVar8 = 0x29;
        }
        else if (DAT_140e419b8 == 1) {
          iVar8 = 0x17;
        }
        else if (DAT_140e419b8 == 2) {
          iVar8 = 0x14;
        }
        else if (DAT_140e419b8 == 3) {
          iVar8 = 0x11;
        }
        else if (DAT_140e419b8 == 4) {
          iVar8 = 0xe;
        }
        if (DAT_140e419b8 == 0) {
          uVar19 = (undefined4)DAT_14053a048;
          uVar20 = (undefined4)((ulonglong)DAT_14053a048 >> 0x20);
        }
        else if (DAT_140e419b8 == 1) {
          uVar19 = (undefined4)DAT_14053a088;
          uVar20 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
        }
        else if (DAT_140e419b8 == 2) {
          uVar19 = (undefined4)DAT_14053a0d0;
          uVar20 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
        }
        else if (DAT_140e419b8 == 3) {
          uVar19 = (undefined4)DAT_14053a0f8;
          uVar20 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
        }
        else if (DAT_140e419b8 == 4) {
          uVar19 = (undefined4)DAT_14053a178;
          uVar20 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
        }
        uVar2 = (longlong)(param_1[3] - iVar17) % (longlong)iVar8;
        if ((int)uVar2 == 0) {
          sVar13 = (short)(uVar15 + 0x400 >> 0xb) * 0x800;
          uVar25 = 0;
          FUN_14006c2f0(0,uVar2 & 0xffffffff,fVar22,fVar18,CONCAT22(uVar24,sVar13),0,
                        CONCAT44(uVar20,uVar19),CONCAT44(uVar26,1),0);
          if (2 < DAT_140e419b8) {
            uVar25 = 0;
            FUN_14006c2f0(0,0,fVar22,fVar18,sVar13,0,(double)CONCAT44(uVar20,uVar19) - DAT_140539fb8
                          ,1,0);
          }
        }
      }
    }
    FUN_1400c8410(DAT_140e44c28,0x1e,7,fVar23,uStack_f0._4_4_,
                  CONCAT22(uVar25,*(undefined2 *)(param_1 + 0x10)),dVar6,dVar3,0xff,0xff,0xff,0xff,1
                  ,0);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,3);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (uStack_100._4_4_ < 1) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (iVar12 == 0) {
    *param_1 = 0;
  }
  return;
}


