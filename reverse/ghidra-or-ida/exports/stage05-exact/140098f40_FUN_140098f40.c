// Function: FUN_140098f40 @ 140098f40
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140098f40(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  double dVar4;
  undefined1 auVar5 [16];
  double dVar6;
  double dVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  undefined4 in_stack_fffffffffffffe78;
  undefined2 uVar21;
  uint in_stack_fffffffffffffe80;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined8 local_138;
  undefined8 uStack_120;
  undefined8 uStack_110;
  
  dVar7 = DAT_14053a020;
  dVar18 = DAT_140539d28;
  uVar21 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
  local_138 = 0;
  uStack_120 = (ulonglong)(uint)uStack_120;
  iVar10 = 0;
  local_138._0_4_ = 0;
  if ((0 < DAT_140e44e6c) &&
     (puVar8 = DAT_140e45d80, local_138._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar8 + 4) == param_1[2]) {
        local_138 = *puVar8;
        uStack_120 = puVar8[3];
        uStack_110 = puVar8[5];
      }
      puVar8 = (undefined8 *)puVar8[0xc];
    } while (puVar8 != (undefined8 *)0x0);
    iVar10 = uStack_120._4_4_;
  }
  sVar1 = *(short *)(param_1 + 0x10);
  fVar14 = (float)param_1[0xc];
  dVar16 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar16 * (double)fVar14) + (float)uStack_110;
  dVar16 = (double)FUN_140332d90();
  iVar2 = param_1[3];
  fVar15 = (float)param_1[10];
  fVar19 = (float)(dVar16 * (double)fVar14) + uStack_110._4_4_;
  dVar16 = (double)FUN_140332d90(((double)iVar2 - 0.0) * _DAT_14053a8e8 * dVar7 * dVar18);
  dVar6 = DAT_140539f40;
  dVar16 = dVar16 * _DAT_140539e28 + 0.0 + DAT_140539f40;
  FUN_1403300b4((double)(fVar19 - (float)param_1[0xb]),(double)(fVar20 - fVar15));
  fVar14 = (float)FUN_140334430(fVar15 - fVar20);
  fVar15 = (float)FUN_140334430((float)param_1[0xb] - fVar19);
  if (fVar14 + fVar15 < 0.0) {
    fVar14 = (float)FUN_1403352f8();
  }
  else {
    fVar14 = SQRT(fVar14 + fVar15);
  }
  dVar4 = (double)fVar14 / DAT_14053a278;
  dVar17 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar17 * dVar4) + (float)param_1[10];
  dVar17 = (double)FUN_140332d90();
  sVar11 = sVar1 + -0x1bc;
  if ((uint)uStack_120 == 0x47) {
    sVar11 = sVar1 + 0x1bc;
  }
  param_1[0xb] = (float)(dVar17 * dVar4) + (float)param_1[0xb];
  *(short *)(param_1 + 0x10) = sVar11;
  dVar4 = DAT_14053a798;
  if (param_1[5] != 0) {
    if (param_1[5] != 1) goto LAB_140099429;
LAB_1400992aa:
    iVar2 = param_1[3];
    if (iVar2 < 300) {
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0x96;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0x78;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar13 = 0x5a;
      }
      else if (DAT_140e419b8 == 4) {
        iVar13 = 0x46;
      }
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 0xc;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 7;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar12 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 4;
      }
      dVar18 = DAT_14053a040;
      if ((((DAT_140e419b8 != 0) && (dVar18 = DAT_14053a088, DAT_140e419b8 != 1)) &&
          (dVar18 = DAT_14053a0b0, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar18 = dVar6, DAT_140e419b8 == 4)))) {
        dVar18 = DAT_14053a0f8;
      }
      if (-1 < iVar2) {
        iVar9 = (int)((longlong)iVar2 % (longlong)iVar13);
        if ((iVar9 < 0x1e) &&
           (uVar3 = (longlong)
                    ((ulonglong)(uint)(iVar9 >> 0x1f) << 0x20 |
                    (longlong)iVar2 % (longlong)iVar13 & 0xffffffffU) % (longlong)iVar12,
           (int)uVar3 == 0)) {
          sVar1 = *(short *)(param_1 + 0x10);
          auVar22._12_4_ = in_stack_fffffffffffffe88._12_4_;
          auVar22._0_8_ = in_stack_fffffffffffffe88._0_8_;
          auVar22._8_4_ = 1;
          auVar23._8_8_ = auVar22._8_8_;
          auVar23._0_8_ = dVar18;
          in_stack_fffffffffffffe80 = 0;
          FUN_14006c2f0(4,uVar3 & 0xffffffff,param_1[10],param_1[0xb],
                        CONCAT22(uVar21,sVar1 + -0x8000),0,dVar18,auVar23._8_8_,0);
          if (2 < DAT_140e419b8) {
            auVar24._12_4_ = auVar23._12_4_;
            auVar24._0_8_ = auVar23._0_8_;
            auVar24._8_4_ = 1;
            in_stack_fffffffffffffe80 = 0;
            FUN_14006c2f0(4,0,param_1[10],param_1[0xb],sVar1 + -0x8000,0,dVar18 + DAT_140539f58,
                          auVar24._8_8_,0);
          }
        }
      }
    }
    goto LAB_140099429;
  }
  fVar14 = (float)param_1[0xe];
  if (iVar2 == 0) {
    param_1[10] = (float)uStack_110;
    param_1[0xb] = uStack_110._4_4_;
LAB_140099212:
    dVar18 = (double)FUN_140332d90(((double)iVar2 - 0.0) * dVar4 * dVar7 * dVar18);
    param_1[0xc] = (float)(int)(dVar18 * (double)(int)fVar14);
  }
  else {
    iVar13 = 0;
    if ((-1 < iVar2) && (iVar13 = (int)fVar14, iVar2 < 0x1e)) goto LAB_140099212;
    param_1[0xc] = (float)iVar13;
    dVar16 = 0.0;
    if (iVar2 < 0) goto LAB_140099429;
    if (0x1d < iVar2) {
      dVar16 = dVar6;
      if (iVar2 != 0x1e) goto LAB_140099429;
      param_1[0x15] = 0;
      param_1[3] = 0;
      param_1[5] = 1;
      goto LAB_1400992aa;
    }
  }
  dVar18 = (double)FUN_140332d90();
  dVar16 = dVar18 + 0.0;
LAB_140099429:
  auVar5._8_4_ = SUB84(dVar16,0);
  auVar5._0_8_ = dVar16;
  auVar5._12_4_ = (int)((ulonglong)dVar16 >> 0x20);
  FUN_1400c8410(DAT_140e44c18,0x20,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe80 & 0xffff0000
                ,auVar5,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,1);
    FUN_140079e20(param_1,0);
    iVar2 = param_1[2];
    puVar8 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)puVar8[0xc]) {
        if (*(int *)((longlong)puVar8 + 4) == iVar2) {
          *(int *)((longlong)puVar8 + 0x5c) = *(int *)((longlong)puVar8 + 0x5c) + -1;
        }
      }
    }
    *param_1 = 0;
  }
  if (iVar10 < 1) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((int)local_138 == 0) {
    *param_1 = 0;
  }
  return;
}


