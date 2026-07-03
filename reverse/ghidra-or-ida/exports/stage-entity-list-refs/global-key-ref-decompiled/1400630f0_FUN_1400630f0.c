// Function: FUN_1400630f0 @ 1400630f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400630f0(undefined4 *param_1,undefined8 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  undefined8 uVar3;
  double dVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined8 uVar7;
  int iVar8;
  int *piVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  undefined4 uVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  float local_res18;
  uint in_stack_fffffffffffffd40;
  undefined8 in_stack_fffffffffffffd50;
  undefined8 uVar26;
  int local_260;
  undefined4 local_258;
  undefined4 uStack_254;
  int iStack_244;
  int iStack_240;
  int iStack_23c;
  int iStack_234;
  float fStack_220;
  float fStack_21c;
  int local_218;
  int local_208;
  int iStack_1f4;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  ulonglong uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  int local_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  undefined1 local_f8 [184];
  
  iVar14 = 0;
  uStack_1c0 = (ulonglong)(uint)uStack_1c0;
  iVar17 = 0;
  if ((0 < DAT_140e44e6c) && (piVar9 = DAT_140e45d80, iVar17 = 0, DAT_140e45d80 != (int *)0x0)) {
    do {
      if (piVar9[1] == DAT_140e44308) {
        local_1d8 = *(undefined8 *)piVar9;
        uStack_1d0 = *(undefined8 *)(piVar9 + 2);
        local_1c8 = *(undefined8 *)(piVar9 + 4);
        uStack_1c0 = *(ulonglong *)(piVar9 + 6);
        local_1b8 = *(undefined8 *)(piVar9 + 8);
        uStack_1b0 = *(undefined8 *)(piVar9 + 10);
        local_1a8 = *(undefined8 *)(piVar9 + 0xc);
        uStack_1a0 = *(ulonglong *)(piVar9 + 0xe);
        local_198 = *(undefined8 *)(piVar9 + 0x10);
        uStack_190 = *(undefined8 *)(piVar9 + 0x12);
        local_188 = *(undefined8 *)(piVar9 + 0x14);
        uStack_180 = *(undefined8 *)(piVar9 + 0x16);
        local_178 = *(undefined8 *)(piVar9 + 0x18);
      }
      piVar9 = *(int **)(piVar9 + 0x18);
    } while (piVar9 != (int *)0x0);
    iVar17 = uStack_1c0._4_4_;
  }
  local_260 = 0;
  if ((0 < DAT_140e44e6c) && (DAT_140e45d80 != (int *)0x0)) {
    local_260 = 0;
    piVar9 = DAT_140e45d80;
    do {
      if (piVar9[1] == param_1[2]) {
        local_260 = *piVar9;
        iStack_244 = piVar9[1];
        iStack_240 = piVar9[2];
        iStack_23c = piVar9[3];
        iStack_234 = piVar9[5];
        fStack_220 = (float)piVar9[10];
        fStack_21c = (float)piVar9[0xb];
        local_218 = piVar9[0xc];
        local_208 = piVar9[0x10];
        iStack_1f4 = piVar9[0x15];
      }
      piVar9 = *(int **)(piVar9 + 0x18);
      param_3 = local_208;
      param_4 = local_218;
    } while (piVar9 != (int *)0x0);
  }
  fVar1 = (float)param_1[0xc];
  fVar2 = (float)param_1[0xd];
  fVar25 = fStack_220 + fVar1;
  local_168 = local_260;
  iStack_164 = iStack_244;
  iStack_160 = iStack_240;
  iStack_15c = iStack_23c;
  FUN_1403300b4((double)((fStack_21c + fVar2) - (float)param_1[0xb]),
                (double)(fVar25 - (float)param_1[10]),param_3,param_4);
  dVar4 = DAT_14053aba0;
  fVar18 = (float)FUN_140334430();
  fVar19 = (float)FUN_140334430();
  if (fVar18 + fVar19 < 0.0) {
    local_res18 = (float)FUN_1403352f8();
  }
  else {
    local_res18 = SQRT(fVar18 + fVar19);
  }
  uVar11 = param_1[3];
  puVar10 = (undefined8 *)FUN_140135060(local_f8,uVar11,0x14);
  dVar20 = DAT_14053a798;
  dVar24 = DAT_14053a5f8;
  dVar23 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  uVar3 = *puVar10;
  uVar5 = *(undefined4 *)(puVar10 + 1);
  uVar16 = 0x20;
  if ((param_1[6] - 0x11f & 0xfffffffd) == 0) {
    uVar16 = 0x1f;
  }
  if (param_1[6] == 0x122) {
    uVar16 = 0x1d;
  }
  bVar6 = fVar1 < DAT_14053b044;
  if (param_1[5] == 0) {
    param_1[10] = fVar25;
    param_1[0xb] = fStack_21c + fVar2;
    if ((int)uVar11 < 0x96) {
      iVar13 = 0;
LAB_1400633e0:
      iVar8 = ((int)uVar11 >> 0x1f & 0xffffff01U) + 0xff;
      if (-1 < (int)uVar11) {
        if ((int)uVar11 < 0x96) {
          dVar20 = ((double)(int)uVar11 - _DAT_140539cc0) * _DAT_14053a478;
          goto LAB_14006346f;
        }
        if (uVar11 < 0xb4) goto LAB_14006345b;
      }
    }
    else {
      iVar13 = 0xff;
      if (0xb3 < (int)uVar11) goto LAB_1400633e0;
      dVar21 = (double)FUN_140332d90(((double)(int)uVar11 - DAT_14053a510) * dVar20 * dVar23 *
                                     dVar22);
      iVar13 = (int)(dVar21 * dVar24);
LAB_14006345b:
      dVar20 = ((double)(int)uVar11 - DAT_14053a4a0) * dVar20;
LAB_14006346f:
      dVar22 = (double)FUN_140332d90(dVar20 * dVar23 * dVar22);
      iVar8 = (int)(dVar22 * dVar24);
    }
    iVar14 = 0;
    if ((int)uVar11 < 0xb4) {
      iVar14 = iVar8;
    }
    if (iStack_23c == 0xbe) {
      param_1[3] = 0;
      param_1[5] = 1;
LAB_1400634bb:
      fVar1 = (float)param_1[0xb];
      fVar2 = (float)param_1[10];
      fVar18 = fVar1 + DAT_14053ad50;
      dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar18),
                                     (double)(DAT_140e445d8 - fVar2));
      dVar22 = *(double *)(param_1 + 0x12);
      dVar24 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar24 * ((double)local_res18 / dVar22)) + fVar2;
      dVar24 = (double)FUN_140332d90();
      uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffd50 >> 0x20);
      param_1[0xb] = (float)(dVar24 * ((double)local_res18 / dVar22)) + fVar1;
      if (iStack_234 == 1) {
        sVar15 = (short)(int)(dVar23 * dVar4);
        if (((param_1[6] == 0x11e) && (iStack_15c - 0x46U < 0x140)) &&
           (uVar11 = (iStack_23c + -0x46) % 0xd2, (int)uVar11 < 0x6e)) {
          uVar11 = uVar11 & 0x80000007;
          if ((int)uVar11 < 0) {
            uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
          }
          if (uVar11 == 0) {
            iVar17 = 0;
            in_stack_fffffffffffffd50 = CONCAT44(uVar12,1);
            uVar11 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar11 = uVar11 * 0x800 ^ uVar11;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ uVar11 ^ DAT_140e9fd18;
            FUN_14006c2f0(3,0,fVar2,fVar18,
                          ((short)((ulonglong)DAT_140e9fd1c / 0xbb9) * 0xbb9 - (short)DAT_140e9fd1c)
                          + sVar15 + 0x5dc,0,DAT_14053a158,in_stack_fffffffffffffd50,0);
            uVar26 = DAT_14053a190;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              FUN_14006c2f0(7,0,fVar2,fVar18,(short)iVar17 * 2000 + sVar15 + -18000,0,uVar26,
                            in_stack_fffffffffffffd50,0);
              iVar17 = iVar17 + 1;
            } while (iVar17 < 7);
            iVar17 = uStack_1c0._4_4_;
            iVar8 = 0;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              in_stack_fffffffffffffd40 = 0;
              FUN_14006c2f0(7,0,fVar2,fVar18,(short)iVar8 * 2000 + sVar15 + 6000,0,uVar26,
                            in_stack_fffffffffffffd50,0);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 7);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        uVar26 = DAT_14053a0d0;
        uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffd50 >> 0x20);
        if (((param_1[6] == 0x120) && (iStack_15c - 0x1eU < 0x168)) &&
           ((iVar8 = (iStack_23c + -0x1e) % 0xd2, iVar8 < 0x96 && (iVar8 == (iVar8 / 10) * 10)))) {
          if (bVar6) {
            iVar17 = 0;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              FUN_14006c2f0(4,0,fVar2,fVar18,(short)iVar17 * 5000 + sVar15,0,uVar26,
                            in_stack_fffffffffffffd50,0);
              uVar7 = DAT_14053a118;
              iVar17 = iVar17 + 1;
            } while (iVar17 < 3);
            iVar17 = uStack_1c0._4_4_;
            uVar11 = 0;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              in_stack_fffffffffffffd40 = 0;
              FUN_14006c2f0(0,0,fVar2,fVar18,(short)((uVar11 & 0xffff) * 5000) + sVar15 + -0x9c4,0,
                            uVar7,in_stack_fffffffffffffd50,0);
              uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffd50 >> 0x20);
              uVar11 = uVar11 + 1;
            } while ((int)uVar11 < 3);
          }
          else {
            iVar17 = 0;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              FUN_14006c2f0(4,0,fVar2,fVar18,(short)iVar17 * 5000 + sVar15 + -10000,0,uVar26,
                            in_stack_fffffffffffffd50,0);
              uVar7 = DAT_14053a118;
              iVar17 = iVar17 + 1;
            } while (iVar17 < 3);
            uVar11 = 0;
            iVar17 = uStack_1c0._4_4_;
            do {
              in_stack_fffffffffffffd50 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffd50 >> 0x20),1);
              in_stack_fffffffffffffd40 = 0;
              FUN_14006c2f0(0,0,fVar2,fVar18,(short)((uVar11 & 0xffff) * 5000) + sVar15 + -0x1d4c,0,
                            uVar7,in_stack_fffffffffffffd50,0);
              uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffd50 >> 0x20);
              uVar11 = uVar11 + 1;
            } while ((int)uVar11 < 3);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      if (iStack_234 == 2) {
        if (param_1[6] == 0x11f) {
          local_1c8 = _DAT_14053b620;
          uStack_1c0 = _UNK_14053b628;
          local_1a8 = _DAT_14053b620;
          uStack_1a0 = _UNK_14053b628;
          local_198 = _DAT_14053b610;
          uStack_190 = _UNK_14053b618;
          local_1d8 = _DAT_14053b470;
          uStack_1d0 = _UNK_14053b478;
          local_1b8 = _DAT_14053b470;
          uStack_1b0 = _UNK_14053b478;
          if ((iStack_15c - 0x32U < 0x29e) &&
             (iStack_23c + -0x32 == ((iStack_23c + -0x32) / 0x30) * 0x30)) {
            iVar8 = *(int *)((longlong)&local_1d8 + (longlong)((iStack_23c + -0x32) / 0x30) * 4);
            if (iVar8 == 0) {
              if (!bVar6) {
LAB_140063ba8:
                uVar26 = CONCAT44(uVar12,0x32);
                in_stack_fffffffffffffd40 =
                     CONCAT22((short)(in_stack_fffffffffffffd40 >> 0x10),0x4000);
                stage_entity_spawn_candidate
                          (0x123,99999999,0,fVar2,fVar18,in_stack_fffffffffffffd40,0,uVar26,1,
                           param_1[1]);
                uVar12 = (undefined4)((ulonglong)uVar26 >> 0x20);
                FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
                FUN_14018a340(DAT_140e472bc,1,1);
              }
            }
            else if ((iVar8 == 1) && (bVar6)) goto LAB_140063ba8;
          }
        }
        if (((param_1[6] == 0x122) && (iStack_15c - 10U < 0x2c6)) &&
           (iStack_23c + -10 == ((iStack_23c + -10) / 0x1e) * 0x1e)) {
          in_stack_fffffffffffffd40 = CONCAT22((short)(in_stack_fffffffffffffd40 >> 0x10),0x4000);
          stage_entity_spawn_candidate
                    (0x124,99999999,0,fVar2,fVar18,in_stack_fffffffffffffd40,0,CONCAT44(uVar12,0x1e)
                     ,1,param_1[1]);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      if (iStack_234 == 99) {
        param_1[5] = 99;
        param_1[3] = 0;
      }
    }
  }
  else {
    iVar13 = 0xff;
    if (param_1[5] == 1) goto LAB_1400634bb;
  }
  uVar7 = _UNK_14053bb28;
  uVar26 = _DAT_14053bb20;
  fVar1 = DAT_14053ace8;
  if (param_1[5] == 99) {
    dVar4 = *(double *)(param_1 + 0x12);
    dVar22 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar22 * ((double)local_res18 / dVar4)) + (float)param_1[10];
    dVar22 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar22 * ((double)local_res18 / dVar4)) + (float)param_1[0xb];
    if (99 < (int)param_1[3]) goto LAB_140063d26;
  }
  if (0 < iVar13) {
    in_stack_fffffffffffffd40 = in_stack_fffffffffffffd40 & 0xffff0000;
    uVar12 = DAT_140e44a98;
    if (param_1[6] != 0x11e) {
      uVar12 = DAT_140e44a9c;
    }
    FUN_1400c8410(uVar12,uVar16,7,param_1[10],(float)param_1[0xb] - fVar1,in_stack_fffffffffffffd40,
                  uVar26,uVar7,0xff,0xff,0xff,iVar13,1,bVar6);
  }
LAB_140063d26:
  if (0 < iVar14) {
    uStack_254 = (undefined4)((ulonglong)uVar3 >> 0x20);
    local_258 = (undefined4)uVar3;
    uVar12 = DAT_140e44a98;
    if (param_1[6] != 0x11e) {
      uVar12 = DAT_140e44a9c;
    }
    FUN_1400c8410(uVar12,uVar16,8,param_1[10],(float)param_1[0xb] - fVar1,
                  in_stack_fffffffffffffd40 & 0xffff0000,uVar26,uVar7,local_258,uStack_254,uVar5,
                  iVar14,1,bVar6);
  }
  param_1[0x15] = iStack_1f4;
  iVar14 = DAT_140e44308;
  if (iStack_1f4 == 0) {
    iVar13 = param_1[7];
    if ((iVar13 < iVar17) && (piVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; piVar9 != (int *)0x0; piVar9 = *(int **)(piVar9 + 0x18)) {
        if (piVar9[1] == iVar14) {
          piVar9[7] = piVar9[7] - (iVar17 - iVar13);
        }
      }
    }
    iVar14 = param_1[7];
    if (iVar17 < iVar14) {
      param_1[7] = iVar17;
      iVar14 = iVar17;
    }
    iVar13 = DAT_140e44308;
    if ((iVar14 < 1) && (piVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; piVar9 != (int *)0x0; piVar9 = *(int **)(piVar9 + 0x18)) {
        if (piVar9[1] == iVar13) {
          piVar9[7] = piVar9[7] - iVar17;
        }
      }
    }
  }
  if (local_260 == 0) {
    *param_1 = 0;
  }
  return;
}


