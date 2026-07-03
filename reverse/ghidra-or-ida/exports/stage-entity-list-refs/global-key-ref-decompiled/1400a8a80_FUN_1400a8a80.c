// Function: FUN_1400a8a80 @ 1400a8a80
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a8a80(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  ushort uVar3;
  ushort uVar4;
  ulonglong *puVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  double dVar13;
  float fVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  undefined4 in_stack_fffffffffffffec0;
  undefined4 uVar18;
  undefined2 uVar19;
  undefined1 in_stack_fffffffffffffec8 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  ulonglong local_f8;
  undefined8 uStack_f0;
  int iStack_dc;
  undefined8 uStack_d0;
  
  uVar19 = (undefined2)((uint)in_stack_fffffffffffffec0 >> 0x10);
  local_f8 = local_f8 & 0xffffffff00000000;
  iStack_dc = 0;
  iVar8 = 0;
  if ((0 < DAT_140e44e6c) && (puVar5 = DAT_140e45d80, iVar8 = 0, DAT_140e45d80 != (ulonglong *)0x0))
  {
    do {
      if (*(int *)((longlong)puVar5 + 4) == param_1[2]) {
        local_f8 = *puVar5;
        uStack_f0 = puVar5[1];
        iStack_dc = *(int *)((longlong)puVar5 + 0x1c);
        uStack_d0 = puVar5[5];
      }
      puVar5 = (ulonglong *)puVar5[0xc];
    } while (puVar5 != (ulonglong *)0x0);
    iVar8 = (int)local_f8;
  }
  fVar17 = (float)uStack_d0 + (float)param_1[0xc];
  dVar13 = (double)FUN_140332d90(((double)uStack_f0._4_4_ - 0.0) * DAT_14053ab78 * DAT_14053a020 *
                                 DAT_140539d28);
  param_1[10] = fVar17;
  fVar14 = (float)(dVar13 + dVar13) + 0.0 + uStack_d0._4_4_ + (float)param_1[0xd];
  param_1[0xb] = fVar14;
  if (param_1[5] == 0) {
    dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar14),
                                   SUB84((double)(DAT_140e445d8 - fVar17),0));
    auVar2 = _DAT_14053bb20;
    iVar9 = param_1[3];
    uVar7 = *(ushort *)(param_1 + 0x10);
    uVar15 = (undefined4)DAT_14053bb20;
    uVar16 = DAT_14053bb20._4_4_;
    uVar11 = (uint)(dVar13 * DAT_14053aba0);
    iVar12 = (param_1[1] - (int)(local_f8 >> 0x20)) * 0x29 + 0x46;
    uVar3 = (ushort)uVar11;
    if (iVar9 < iVar12) {
      uVar4 = uVar3 - uVar7;
      uVar6 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar6 = 0x10000 - uVar4;
      }
      iVar12 = (uVar11 & 0xffff) - (uint)uVar7;
      iVar10 = (int)uVar6 / 10 + 0x30;
      iVar9 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar9 = iVar12;
      }
      iVar12 = iVar9 + -0x10000;
      if (iVar9 < 0x8001) {
        iVar12 = iVar9;
      }
      if (iVar12 < 1) {
        if ((iVar12 < 0) && (uVar7 = uVar7 - (short)iVar10, -iVar10 < iVar12)) {
          uVar7 = uVar3;
        }
        *(ushort *)(param_1 + 0x10) = uVar7;
      }
      else if (iVar12 < iVar10) {
        *(ushort *)(param_1 + 0x10) = uVar3;
        uVar7 = uVar3;
      }
      else {
        uVar7 = uVar7 + (short)iVar10;
        *(ushort *)(param_1 + 0x10) = uVar7;
      }
    }
    else if (uStack_d0._4_4_ < DAT_14053ae30) {
      dVar13 = (double)FUN_1403307c0();
      fVar17 = (float)(dVar13 * DAT_14053a340) + fVar17;
      dVar13 = (double)FUN_140332d90();
      uVar1 = DAT_14053ac2c;
      iVar10 = 1;
      fVar14 = (float)(dVar13 * DAT_14053a340) + (float)param_1[0xb];
      if (DAT_140e419b8 == 0) {
        iVar10 = 0xa4;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 0x7b;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar10 = 0x52;
      }
      if (DAT_140e419b8 == 0) {
        uVar15 = (undefined4)DAT_14053a0d0;
        uVar16 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar15 = (undefined4)DAT_14053a120;
        uVar16 = (undefined4)((ulonglong)DAT_14053a120 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar15 = (undefined4)DAT_14053a140;
        uVar16 = (undefined4)((ulonglong)DAT_14053a140 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar15 = (undefined4)DAT_14053a160;
        uVar16 = (undefined4)((ulonglong)DAT_14053a160 >> 0x20);
      }
      else if (DAT_140e419b8 == 4) {
        uVar15 = (undefined4)DAT_14053a1a8;
        uVar16 = (undefined4)((ulonglong)DAT_14053a1a8 >> 0x20);
      }
      uVar6 = (iVar9 - iVar12) % iVar10;
      if ((int)uVar6 < 0x10) {
        uVar6 = uVar6 & 0x80000003;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
        }
        if (uVar6 == 0) {
          iVar8 = 0;
          do {
            auVar20._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar20._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar20._8_4_ = 1;
            in_stack_fffffffffffffec8._8_8_ = auVar20._8_8_;
            in_stack_fffffffffffffec8._0_8_ = CONCAT44(uVar16,uVar15);
            uVar18 = uVar1;
            FUN_14006c2f0(0xd,0,fVar17,fVar14,(short)iVar8 * 600 + uVar7 + -600,uVar1,
                          CONCAT44(uVar16,uVar15),in_stack_fffffffffffffec8._8_8_,0);
            uVar19 = (undefined2)((uint)uVar18 >> 0x10);
            iVar8 = iVar8 + 1;
          } while (iVar8 < 3);
          uVar7 = *(ushort *)(param_1 + 0x10);
          iVar8 = (int)local_f8;
          if (2 < DAT_140e419b8) {
            dVar13 = (double)CONCAT44(uVar16,uVar15) - auVar2._0_8_;
            iVar9 = 0;
            do {
              auVar21._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar21._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar21._8_4_ = 1;
              in_stack_fffffffffffffec8._8_8_ = auVar21._8_8_;
              in_stack_fffffffffffffec8._0_8_ = dVar13;
              uVar15 = uVar1;
              FUN_14006c2f0(0xd,0,fVar17,fVar14,(short)iVar9 * 8000 + uVar7 + -4000,uVar1,dVar13,
                            in_stack_fffffffffffffec8._8_8_,0);
              uVar19 = (undefined2)((uint)uVar15 >> 0x10);
              iVar9 = iVar9 + 1;
            } while (iVar9 < 2);
            uVar7 = *(ushort *)(param_1 + 0x10);
          }
        }
      }
      if (((int)param_1[3] < iVar12) || (0xf < (param_1[3] - iVar12) % iVar10)) {
        uVar4 = *(ushort *)(param_1 + 0x10);
        uVar7 = uVar3 - uVar4;
        uVar6 = (uint)uVar7;
        if (0x8000 < uVar7) {
          uVar6 = 0x10000 - uVar7;
        }
        iVar12 = (uVar11 & 0xffff) - (uint)uVar4;
        iVar10 = (int)uVar6 / 10 + 0x30;
        iVar9 = iVar12 + 0x10000;
        if (-0x8001 < iVar12) {
          iVar9 = iVar12;
        }
        iVar12 = iVar9 + -0x10000;
        if (iVar9 < 0x8001) {
          iVar12 = iVar9;
        }
        if (iVar12 < 1) {
          uVar7 = uVar4;
          if ((iVar12 < 0) && (uVar7 = uVar4 - (short)iVar10, -iVar10 < iVar12)) {
            uVar7 = uVar3;
          }
        }
        else {
          uVar7 = uVar3;
          if (iVar10 <= iVar12) {
            uVar7 = uVar4 + (short)iVar10;
          }
        }
        *(ushort *)(param_1 + 0x10) = uVar7;
      }
    }
    FUN_1400c8410(DAT_140e44cbc,0x1e,7,param_1[10],param_1[0xb],CONCAT22(uVar19,uVar7),auVar2,0xff,
                  0xff,0xff,0xff,1,0);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,5);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (iStack_dc < 1) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (iVar8 == 0) {
    *param_1 = 0;
  }
  return;
}


