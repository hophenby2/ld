// Function: FUN_140059760 @ 140059760
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140059760(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  short sVar8;
  uint uVar9;
  short sVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  double dVar14;
  undefined4 uVar15;
  float fVar16;
  double dVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 in_stack_fffffffffffffe80;
  undefined2 uVar21;
  undefined4 uVar20;
  undefined8 local_118;
  undefined8 uStack_100;
  
  dVar4 = DAT_14053a020;
  dVar14 = DAT_140539f40;
  lVar3 = DAT_140e45d80;
  iVar6 = local_118._4_4_;
  if (0 < DAT_140e44e6c) {
    for (; iVar6 = (int)((ulonglong)local_118 >> 0x20), lVar3 != 0;
        lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == param_1[2]) {
        local_118 = *(undefined8 *)(lVar3 + 0x10);
        uStack_100 = *(undefined8 *)(lVar3 + 0x28);
      }
    }
  }
  local_118._4_4_ = iVar6;
  iVar6 = param_1[3];
  uVar18 = SUB84(DAT_140539d28,0);
  uVar19 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  if (-1 < iVar6) {
    if (iVar6 < 0x1e) {
      dVar11 = (double)FUN_140332d90(((double)iVar6 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar11 = dVar11 + 0.0;
      if (iVar6 == 0) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
      goto LAB_1400598c2;
    }
    dVar11 = DAT_140539f40;
    if (iVar6 < 0x186) goto LAB_1400598c2;
    if (iVar6 < 0x19a) {
      dVar11 = (double)FUN_140332d90(((double)iVar6 - _DAT_14053a6a0) * DAT_14053a890 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar11 = dVar11 + 0.0;
      goto LAB_1400598c2;
    }
  }
  dVar11 = 0.0;
LAB_1400598c2:
  uVar15 = SUB84(dVar11,0);
  sVar10 = *(short *)(param_1 + 0x10);
  iVar6 = param_1[3];
  fVar13 = (float)iVar6 * _DAT_140539d10;
  dVar12 = (double)FUN_1403307c0();
  fVar16 = (float)(dVar12 * (double)fVar13) + (float)uStack_100 + (float)param_1[0xc];
  dVar12 = (double)FUN_140332d90();
  uVar21 = (undefined2)((uint)in_stack_fffffffffffffe80 >> 0x10);
  iVar5 = param_1[6];
  param_1[10] = fVar16;
  sVar8 = 0x168;
  if ((iVar5 - 0x12fU & 0xfffffff9) == 0) {
    sVar8 = -0x168;
  }
  *(short *)(param_1 + 0x10) = sVar10 + sVar8;
  fVar13 = (float)(dVar12 * (double)fVar13) + uStack_100._4_4_ + (float)param_1[0xd];
  param_1[0xb] = fVar13;
  if (iVar6 - 0x1eU < 0x168) {
    iVar1 = iVar6 + -0x1e;
    if (iVar5 - 0x12eU < 2) {
      dVar12 = (double)iVar1 * DAT_140539dc8 + DAT_14053a0b0;
      if (iVar1 == (iVar1 / 5) * 5) {
        if (iVar5 == 0x12e) {
          iVar5 = 0;
          sVar10 = *(short *)((longlong)param_1 + 0x42);
          do {
            FUN_14006c2f0(4,0,fVar16,fVar13,
                          (short)iVar5 * 0x1d4c + (short)iVar6 * 0x1a4 + sVar10 + -0x1d4c,0,dVar12,1
                          ,0);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 3);
          sVar10 = *(short *)(param_1 + 3);
          uVar20 = param_1[0xb];
          iVar6 = 0;
          uVar2 = param_1[10];
          sVar8 = *(short *)((longlong)param_1 + 0x42);
          do {
            in_stack_fffffffffffffe80 = 0;
            FUN_14006c2f0(4,0,uVar2,uVar20,(short)iVar6 * 0x1d4c + sVar10 * 0x1a4 + sVar8 + 0x62b4,0
                          ,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 3);
        }
        if (param_1[6] == 0x12f) {
          sVar10 = *(short *)(param_1 + 3);
          iVar6 = 0;
          sVar8 = *(short *)((longlong)param_1 + 0x42);
          uVar20 = param_1[0xb];
          uVar2 = param_1[10];
          do {
            FUN_14006c2f0(5,0,uVar2,uVar20,(short)iVar6 * 0x1d4c + sVar8 + sVar10 * -0x1a4 + -0x1d4c
                          ,0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 3);
          sVar10 = *(short *)(param_1 + 3);
          sVar8 = *(short *)((longlong)param_1 + 0x42);
          iVar6 = 0;
          uVar20 = param_1[0xb];
          uVar2 = param_1[10];
          do {
            in_stack_fffffffffffffe80 = 0;
            FUN_14006c2f0(5,0,uVar2,uVar20,(short)iVar6 * 0x1d4c + sVar8 + sVar10 * -0x1a4 + 0x62b4,
                          0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 3);
        }
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      if (1 < local_118._4_4_) {
        FUN_140079e20(param_1,0);
        *param_1 = 0;
      }
    }
    if (param_1[6] - 0x130 < 2) {
      uVar9 = param_1[3];
      dVar12 = (double)iVar1 * _DAT_140539db0 + DAT_14053a0d0;
      if ((uVar9 - 0x1e < 0x168) && ((int)(uVar9 - 0x1e) % 10 < 5)) {
        if (param_1[6] == 0x130) {
          uVar20 = param_1[0xb];
          iVar6 = 0;
          uVar2 = param_1[10];
          sVar10 = *(short *)((longlong)param_1 + 0x42);
          do {
            in_stack_fffffffffffffe80 = 0;
            FUN_14006c2f0(0xc,0,uVar2,uVar20,(short)iVar6 * 0x4000 + (short)uVar9 * 0x1e0 + sVar10,0
                          ,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
          uVar9 = (uint)*(ushort *)(param_1 + 3);
        }
        if (param_1[6] == 0x131) {
          sVar10 = *(short *)((longlong)param_1 + 0x42);
          iVar6 = 0;
          uVar20 = param_1[0xb];
          uVar2 = param_1[10];
          do {
            in_stack_fffffffffffffe80 = 0;
            FUN_14006c2f0(0xd,0,uVar2,uVar20,(short)iVar6 * 0x4000 + sVar10 + (short)uVar9 * -0x1e0,
                          0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      if (2 < local_118._4_4_) {
        FUN_140079e20(param_1,0);
        *param_1 = 0;
      }
    }
    uVar20 = DAT_14053ac2c;
    dVar12 = DAT_140539f00;
    uVar21 = (undefined2)((uint)in_stack_fffffffffffffe80 >> 0x10);
    if (param_1[6] - 0x132 < 2) {
      sVar10 = *(short *)(param_1 + 3) * -700;
      if (param_1[6] != 0x133) {
        sVar10 = *(short *)(param_1 + 3) * 700;
      }
      sVar10 = *(short *)((longlong)param_1 + 0x42) + sVar10;
      dVar17 = (double)iVar1 * _DAT_140539d98 + DAT_14053a140;
      if ((param_1[3] - 0x1e < 0x168) &&
         (iVar6 = param_1[3] + -0x1e,
         iVar6 == (iVar6 / 6 + (iVar6 >> 0x1f) +
                  (int)(((longlong)iVar6 / 6 + ((longlong)iVar6 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                  6)) {
        iVar6 = 0;
        iVar5 = 0x5dc;
        do {
          puVar7 = param_1 + 0xb;
          if (param_1[6] == 0x132) {
            dVar14 = (double)iVar6 * dVar12 + dVar17;
            FUN_1400709b0(10,0,param_1[10],*puVar7,sVar10,uVar20,dVar14,1,2,iVar5,0);
            in_stack_fffffffffffffe80 = uVar20;
            FUN_1400709b0(10,0,param_1[10],*puVar7,sVar10 + -0x8000,uVar20,dVar14,1,2,iVar5,0);
          }
          if (param_1[6] == 0x133) {
            dVar14 = (double)iVar6 * dVar12 + dVar17;
            FUN_1400709b0(0xb,0,param_1[10],*puVar7,sVar10,uVar20,dVar14,1,2,iVar5,0);
            in_stack_fffffffffffffe80 = uVar20;
            FUN_1400709b0(0xb,0,param_1[10],*puVar7,sVar10 + -0x8000,uVar20,dVar14,1,2,iVar5,0);
          }
          uVar21 = (undefined2)((uint)in_stack_fffffffffffffe80 >> 0x10);
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + -500;
        } while (-500 < iVar5);
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar18 = SUB84(DAT_140539d28,0);
        uVar19 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
        dVar14 = DAT_140539f40;
      }
      if (local_118._4_4_ == 99) {
        FUN_140079e20(param_1,0);
        *param_1 = 0;
      }
    }
    iVar6 = param_1[6];
    if (iVar6 - 0x134U < 2) {
      sVar10 = *(short *)(param_1 + 3) * -0xfa;
      if (iVar6 != 0x135) {
        sVar10 = *(short *)(param_1 + 3) * 0xfa;
      }
      sVar10 = *(short *)((longlong)param_1 + 0x42) + sVar10;
      dVar12 = (double)iVar1 * _DAT_140539dc0 + DAT_14053a0d0;
      if ((param_1[3] - 0x1e < 0x168) && (iVar5 = param_1[3] + -0x1e, iVar5 == (iVar5 / 7) * 7)) {
        if (iVar6 == 0x134) {
          uVar20 = param_1[0xb];
          iVar6 = 0;
          uVar2 = param_1[10];
          do {
            FUN_14006c2f0(0xc,0,uVar2,uVar20,(short)iVar6 * 0x4000 + sVar10,0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
          uVar20 = param_1[0xb];
          iVar6 = 0;
          uVar2 = param_1[10];
          do {
            uVar21 = 0;
            FUN_14006c2f0(2,0,uVar2,uVar20,(short)iVar6 * 0x4000 + sVar10 + 0x2000,0,dVar12 + dVar14
                          ,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
        }
        if (param_1[6] == 0x135) {
          uVar20 = param_1[0xb];
          iVar6 = 0;
          uVar2 = param_1[10];
          do {
            FUN_14006c2f0(0xd,0,uVar2,uVar20,(short)iVar6 * 0x4000 + sVar10,0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
          dVar12 = dVar12 + DAT_140539f40;
          uVar20 = param_1[0xb];
          uVar2 = param_1[10];
          iVar6 = 0;
          do {
            uVar21 = 0;
            FUN_14006c2f0(3,0,uVar2,uVar20,(short)iVar6 * 0x4000 + sVar10 + 0x2000,0,dVar12,1,0);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 4);
        }
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      if ((local_118._4_4_ == 200) || (DAT_140e4430c < 1)) {
        FUN_140079e20(param_1,0);
        *param_1 = 0;
      }
    }
  }
  dVar14 = DAT_14053a858;
  dVar17 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a858 * dVar4 *
                                 (double)CONCAT44(uVar19,uVar18));
  dVar12 = DAT_14053a970;
  uVar20 = CONCAT22(uVar21,(short)(int)(dVar17 * DAT_14053a970));
  FUN_1400c8410(DAT_140e44e58,0x24,7,param_1[10],param_1[0xb],uVar20,dVar11,uVar15,0xff,0xff,0xff,
                0xff,1,0);
  uVar21 = (undefined2)((uint)uVar20 >> 0x10);
  if ((param_1[3] & 1) == 0) {
    dVar14 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * dVar14 * dVar4 *
                                   (double)CONCAT44(uVar19,uVar18));
    FUN_140070d00(5,DAT_140e44e58,0x23,param_1[10],param_1[0xb],
                  CONCAT22(uVar21,(short)(int)(dVar14 * dVar12)),0,uVar15,uVar15,0x10,0xff,0xff,0xff
                  ,0x60,0);
  }
  if (param_1[3] == 0x19a) {
    *param_1 = 0;
  }
  return;
}


