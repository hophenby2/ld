// Function: FUN_140029880 @ 140029880
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140029880(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  ushort uVar9;
  undefined8 uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  longlong lVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  short sVar19;
  int iVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  float fVar39;
  float fVar40;
  undefined1 auStack_208 [32];
  undefined4 local_1e8;
  undefined4 local_1e0;
  undefined8 local_1d8;
  double dStack_1d0;
  undefined8 local_1c8;
  uint local_1c0;
  uint local_1b8;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined4 local_1a0;
  undefined4 local_198;
  float local_188;
  uint local_184;
  float local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  int local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  ulonglong local_d8;
  
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_208;
  uStack_128 = (ulonglong)(uint)uStack_128;
  lVar15 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar15 != 0; lVar15 = *(longlong *)(lVar15 + 0x60)) {
      if (*(int *)(lVar15 + 4) == DAT_140e44308) {
        local_130 = *(undefined8 *)(lVar15 + 0x10);
        uStack_128 = *(ulonglong *)(lVar15 + 0x18);
        local_120 = *(undefined8 *)(lVar15 + 0x20);
        uStack_118 = *(undefined8 *)(lVar15 + 0x28);
      }
    }
  }
  uVar13 = param_1[1] - DAT_1407c77a0;
  fVar31 = (float)param_1[0xd];
  fVar34 = (float)param_1[0xb];
  fVar1 = (float)param_1[0xc];
  fVar2 = (float)param_1[10];
  local_1c0 = 0x4d;
  local_1c8._0_4_ = 1.06499e-43;
  dStack_1d0._0_4_ = 0x4b;
  local_1d8._0_4_ = 0x4a;
  local_1e0 = 0x49;
  local_1e8 = 0x48;
  local_160 = _DAT_14053bfd0;
  uStack_158 = _UNK_14053bfd8;
  local_150 = _DAT_14053bfb0;
  uStack_148 = _UNK_14053bfb8;
  local_184 = uVar13;
  local_168 = FUN_1400c9580(DAT_140e418c8,0,4,6);
  fVar22 = (float)FUN_140334430(fVar2 - fVar1);
  fVar23 = (float)FUN_140334430(fVar34 - fVar31);
  if (fVar22 + fVar23 < 0.0) {
    fVar22 = (float)FUN_1403352f8();
  }
  else {
    fVar22 = SQRT(fVar22 + fVar23);
  }
  dVar25 = (double)fVar22 / DAT_14053a1e8;
  *(double *)(param_1 + 0x12) = dVar25;
  FUN_1403300b4((double)(fVar31 - fVar34),(double)(fVar1 - fVar2));
  dVar26 = DAT_14053a020;
  dVar24 = (double)FUN_1403307c0();
  fVar31 = (float)(dVar24 * dVar25) + (float)param_1[10];
  param_1[10] = fVar31;
  dVar24 = (double)FUN_140332d90();
  uVar4 = *(ushort *)(param_1 + 0x10);
  uVar5 = *(ushort *)((longlong)param_1 + 0x42);
  uVar9 = uVar4 - uVar5;
  uVar11 = (uint)uVar9;
  if (0x8000 < uVar9) {
    uVar11 = 0x10000 - uVar9;
  }
  iVar12 = (uint)uVar5 - (uint)uVar4;
  fVar34 = (float)(dVar24 * dVar25) + (float)param_1[0xb];
  iVar17 = (int)uVar11 / 10 + 0x80;
  param_1[0xb] = fVar34;
  iVar14 = iVar12 + 0x10000;
  if (-0x8001 < iVar12) {
    iVar14 = iVar12;
  }
  iVar12 = iVar14 + -0x10000;
  if (iVar14 < 0x8001) {
    iVar12 = iVar14;
  }
  if (iVar12 < 1) {
    uVar9 = uVar4;
    if ((iVar12 < 0) && (uVar9 = uVar4 - (short)iVar17, -iVar17 < iVar12)) {
      uVar9 = uVar5;
    }
  }
  else {
    uVar9 = uVar5;
    if (iVar17 <= iVar12) {
      uVar9 = uVar4 + (short)iVar17;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar9;
  dVar24 = (double)FUN_1403307c0();
  dVar25 = DAT_14053a330;
  fVar22 = (float)(dVar24 * DAT_14053a330) + fVar31;
  local_180 = fVar22;
  dVar24 = (double)FUN_140332d90();
  fVar23 = (float)(dVar24 * dVar25) + fVar34;
  local_188 = fVar23;
  dVar24 = (double)FUN_1403307c0();
  fVar39 = (float)(dVar24 * dVar25) + fVar31;
  dVar24 = (double)FUN_140332d90();
  fVar2 = uStack_118._4_4_;
  fVar1 = (float)uStack_118;
  fVar40 = (float)(dVar24 * dVar25) + fVar34;
  if (param_1[5] == 0) {
    iVar14 = param_1[3];
    if (iVar14 == 0) {
      fVar31 = (float)uStack_118 - DAT_14053ac98;
      fVar34 = uStack_118._4_4_ - DAT_14053ad00;
      param_1[10] = fVar31;
      param_1[0xb] = fVar34;
    }
    fVar3 = *(float *)((longlong)&local_160 + (longlong)(int)uVar13 * 8 + 4);
    param_1[0xc] = (float)uStack_118 + *(float *)(&local_160 + (int)uVar13);
    param_1[0xd] = uStack_118._4_4_ + fVar3;
    if (iVar14 < 0) {
      uVar37 = 0;
      uVar38 = 0;
    }
    else {
      uVar37 = SUB84(DAT_140539f40,0);
      uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      if (iVar14 < 0x28) {
        dVar25 = (double)FUN_140332d90(((double)iVar14 - 0.0) * DAT_14053a6d8 * dVar26 *
                                       DAT_140539d28);
        dVar25 = dVar25 + 0.0;
        goto LAB_14002a910;
      }
      if (iVar14 == 0x28) {
        param_1[3] = 0;
        param_1[5] = 1;
        goto LAB_140029ce5;
      }
    }
  }
  else {
    uVar37 = SUB84(DAT_140539f40,0);
    uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    if (param_1[5] == 1) {
LAB_140029ce5:
      iVar12 = (int)param_1[3] % 0x4b0;
      dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                     (double)(DAT_140e445d8 - fVar31));
      iVar14 = DAT_140e419b8;
      uVar8 = DAT_14053ac2c;
      dVar25 = DAT_14053aba0;
      dVar26 = dVar26 * DAT_14053aba0;
      if (0x398 < iVar12 - 0xf0U) {
        iVar17 = 1;
        local_178 = _DAT_14053b9a0;
        uStack_170 = _UNK_14053b9a8;
        if (DAT_140e419b8 == 0) {
          iVar17 = 0x78;
        }
        else if (DAT_140e419b8 == 1) {
          iVar17 = 0x5a;
        }
        else if (DAT_140e419b8 == 2) {
          iVar17 = 0x3c;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar17 = 0x32;
        }
        lVar15 = (longlong)(int)uVar13;
        iVar21 = 0x1e;
        if ((int)uVar13 < 2) {
          iVar21 = 10;
        }
        fVar31 = *(float *)((longlong)&local_160 + lVar15 * 8 + 4);
        param_1[0xc] = fVar1 + *(float *)(&local_160 + lVar15);
        param_1[0xd] = fVar2 + fVar31;
        dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                       (double)(DAT_140e445d8 - fVar1));
        uVar13 = local_184;
        *(short *)((longlong)param_1 + 0x42) =
             (short)(int)(dVar24 * dVar25) + *(short *)((longlong)&local_178 + lVar15 * 4);
        if (((iVar21 <= iVar12) && (iVar12 < 0xf0)) && ((iVar12 - iVar21) % iVar17 == 0)) {
          local_1c8._0_4_ = 0.0;
          dStack_1d0._0_4_ = 1;
          local_1d8._0_4_ = (undefined4)DAT_14053a218;
          local_1d8._4_4_ = (undefined4)((ulonglong)DAT_14053a218 >> 0x20);
          local_1e0 = uVar8;
          local_1e8 = CONCAT22(local_1e8._2_2_,uVar9);
          FUN_14006c2f0(2,(local_184 & 1) + 0x1d,fVar22,fVar23);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar14 = DAT_140e419b8;
        }
      }
      dVar24 = DAT_14053a0f8;
      if (iVar12 - 0xfaU < 0x8c) {
        uVar32 = 1;
        if (iVar14 == 0) {
          uVar32 = 3;
        }
        else if (iVar14 == 1) {
          uVar32 = 5;
        }
        else if (iVar14 == 2) {
          uVar32 = 7;
        }
        else if ((iVar14 == 3) || (iVar14 == 4)) {
          uVar32 = 9;
        }
        if (iVar12 < 0x10e) {
          *(short *)((longlong)param_1 + 0x42) = (short)(int)dVar26;
        }
        uVar11 = iVar12 - 0x111;
        fVar31 = *(float *)((longlong)&local_160 + (longlong)(int)uVar13 * 8 + 4);
        param_1[0xc] = fVar1 + *(float *)(&local_160 + (int)uVar13);
        param_1[0xd] = uStack_118._4_4_ + fVar31;
        local_1d8 = (double)CONCAT44(local_1d8._4_4_,(undefined4)local_1d8);
        if ((uVar11 < 0x75) &&
           (local_1d8 = (double)CONCAT44(local_1d8._4_4_,(undefined4)local_1d8),
           uVar11 == ((int)uVar11 / 3 + ((int)uVar11 >> 0x1f) +
                     (int)(((longlong)(int)uVar11 / 3 + ((longlong)(int)uVar11 >> 0x3f) &
                           0xffffffffU) >> 0x1f)) * 3)) {
          local_1b8 = 0;
          dStack_1d0._0_4_ = 1;
          local_1d8 = ((double)iVar12 - DAT_14053a620) * DAT_140539e70 + dVar24;
          local_1e0 = uVar8;
          local_1e8 = CONCAT22(local_1e8._2_2_,*(undefined2 *)(param_1 + 0x10));
          local_1c8._0_4_ = (float)uVar32;
          local_1c0 = iVar12 * -0x140 + 0x214d0;
          FUN_1400709b0(6,0,fVar22,fVar23);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar14 = DAT_140e419b8;
        }
      }
      if (399 < iVar12) {
        uVar28 = (undefined4)((ulonglong)dVar24 >> 0x20);
        uVar35 = SUB84(DAT_140539f40,0);
        uVar36 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
        uVar32 = (undefined4)DAT_14053a048;
        uVar33 = (undefined4)((ulonglong)DAT_14053a048 >> 0x20);
        if (iVar12 < 0x294) {
          sVar19 = 1;
          if (iVar14 == 0) {
            sVar19 = 0xfa;
          }
          else if (iVar14 == 1) {
            sVar19 = 0x15e;
          }
          else if ((iVar14 == 2) || (iVar14 == 3)) {
            sVar19 = 0x1a4;
          }
          else if (iVar14 == 4) {
            sVar19 = 0x1e0;
          }
          if (iVar14 == 0) {
            uVar32 = (int)DAT_14053a018;
            uVar33 = (int)((ulonglong)DAT_14053a018 >> 0x20);
          }
          else if (iVar14 != 1) {
            if (iVar14 == 2) {
              uVar32 = (int)DAT_14053a0a0;
              uVar33 = (int)((ulonglong)DAT_14053a0a0 >> 0x20);
            }
            else {
              uVar32 = SUB84(dVar24,0);
              uVar33 = uVar28;
              if ((iVar14 != 3) && (uVar32 = uVar35, uVar33 = uVar36, iVar14 == 4)) {
                uVar32 = (int)DAT_14053a158;
                uVar33 = (int)((ulonglong)DAT_14053a158 >> 0x20);
              }
            }
          }
          sVar6 = *(short *)(param_1 + 3);
          fVar31 = (float)param_1[0xe];
          dVar26 = (double)FUN_1403300b4((double)((float)param_1[0xf] - local_188),
                                         (double)(fVar31 - local_180));
          if (iVar12 == 400) {
            uVar10 = FUN_1401346a0(CONCAT44(DAT_140e445dc,DAT_140e445d8),0xb4);
            local_178._0_4_ = (float)uVar10;
            local_178._4_4_ = (undefined4)((ulonglong)uVar10 >> 0x20);
            param_1[0xe] = (float)local_178;
            param_1[0xf] = local_178._4_4_;
            fVar31 = (float)local_178;
            local_178 = uVar10;
          }
          dVar24 = (double)FUN_1403307c0();
          dVar24 = dVar24 * DAT_14053a5f0;
          fVar34 = (float)param_1[0xf];
          dVar27 = (double)FUN_140332d90();
          dVar27 = dVar27 * DAT_14053a5f0;
          param_1[0xc] = (float)dVar24 + fVar31;
          *(short *)((longlong)param_1 + 0x42) = sVar19 * sVar6 + (short)uVar13 * 0x4000 + -0x8000;
          param_1[0xd] = (float)dVar27 + fVar34;
          dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                         (double)(DAT_140e445d8 - fVar31));
          dVar24 = (double)FUN_1403307c0((double)((int)(dVar24 * DAT_14053aba0) & 0xffff) *
                                         DAT_14053a020 * DAT_140539d28);
          fVar31 = (float)(dVar24 * DAT_140539f00) + fVar31;
          param_1[0xe] = fVar31;
          dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                         (double)(DAT_140e445d8 - fVar31));
          dVar24 = (double)FUN_140332d90((double)((int)(dVar24 * DAT_14053aba0) & 0xffff) *
                                         DAT_14053a020 * DAT_140539d28);
          param_1[0xf] = (float)(dVar24 * DAT_140539f00) + fVar34;
          uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 0xe),0xb4);
          uVar13 = iVar12 - 0x1c2;
          local_178._0_4_ = (float)uVar10;
          local_178._4_4_ = (undefined4)((ulonglong)uVar10 >> 0x20);
          param_1[0xe] = (float)local_178;
          param_1[0xf] = local_178._4_4_;
          local_178 = uVar10;
          if ((uVar13 < 0x96) &&
             (uVar13 == ((int)uVar13 / 3 + ((int)uVar13 >> 0x1f) +
                        (int)(((longlong)(int)uVar13 / 3 + ((longlong)(int)uVar13 >> 0x3f) &
                              0xffffffffU) >> 0x1f)) * 3)) {
            sVar19 = (short)(int)(dVar26 * dVar25);
            if ((2 < iVar14) || ((local_184 & 1) != 0)) {
              local_1c8._0_4_ = 0.0;
              dStack_1d0._0_4_ = 1;
              local_1e0 = uVar8;
              local_1e8 = CONCAT22(local_1e8._2_2_,sVar19);
              local_1d8._0_4_ = uVar32;
              local_1d8._4_4_ = uVar33;
              FUN_14006c2f0(7,3,local_180,local_188);
            }
            iVar14 = 0;
            do {
              local_1c8._0_4_ = 0.0;
              dStack_1d0._0_4_ = 1;
              local_1e0 = uVar8;
              local_1e8 = CONCAT22(local_1e8._2_2_,(short)iVar14 * 0x5555 + sVar19 + 0x5556);
              local_1d8._0_4_ = uVar32;
              local_1d8._4_4_ = uVar33;
              FUN_14006c2f0(7,3,fVar39,fVar40);
              iVar14 = iVar14 + 1;
            } while (iVar14 < 2);
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        else if (iVar12 < 0x488) {
          iVar17 = 1;
          if (iVar14 == 0) {
            iVar17 = 0x3c;
          }
          else if ((iVar14 == 1) || (iVar14 == 2)) {
LAB_14002a42b:
            iVar17 = 0x28;
          }
          else if (iVar14 == 3) {
            iVar17 = 0x30;
          }
          else if (iVar14 == 4) goto LAB_14002a42b;
          local_188 = 1.4013e-45;
          if (((iVar14 == 0) || (iVar14 == 1)) || (iVar14 == 2)) {
            local_188 = 1.4013e-45;
          }
          else if ((iVar14 == 3) || (iVar14 == 4)) {
            local_188 = 2.8026e-45;
          }
          iVar21 = 1;
          if (iVar14 == 0) {
            iVar21 = 0x10;
          }
          else if (iVar14 == 1) {
LAB_14002a4a0:
            iVar21 = 0x14;
          }
          else {
            if (iVar14 != 2) {
              if (iVar14 == 3) goto LAB_14002a4a0;
              if (iVar14 != 4) goto LAB_14002a4ac;
            }
            iVar21 = 0x18;
          }
LAB_14002a4ac:
          iVar16 = 1;
          if (iVar14 == 0) {
            iVar16 = 0x50;
          }
          else if (iVar14 == 1) {
LAB_14002a4ce:
            iVar16 = 0x8c;
          }
          else {
            if (iVar14 != 2) {
              if (iVar14 == 3) goto LAB_14002a4ce;
              if (iVar14 != 4) goto LAB_14002a4da;
            }
            iVar16 = 0xa0;
          }
LAB_14002a4da:
          uVar29 = (undefined4)DAT_14053a0b0;
          uVar30 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
          if (iVar14 == 0) {
            uVar32 = (undefined4)DAT_14053a030;
            uVar33 = (undefined4)((ulonglong)DAT_14053a030 >> 0x20);
          }
          else if (iVar14 != 1) {
            if ((iVar14 == 2) || (iVar14 == 3)) {
              uVar32 = (undefined4)DAT_14053a070;
              uVar33 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
            }
            else {
              uVar32 = uVar35;
              uVar33 = uVar36;
              if (iVar14 == 4) {
                uVar32 = uVar29;
                uVar33 = uVar30;
              }
            }
          }
          iVar18 = 1;
          if (iVar14 == 0) {
            iVar18 = 0x78;
          }
          else if (iVar14 == 1) {
            iVar18 = 100;
          }
          else if (((iVar14 == 2) || (iVar14 == 3)) || (iVar14 == 4)) {
            iVar18 = 0x5a;
          }
          iVar20 = 1;
          if (iVar14 == 0) {
            iVar20 = 6;
          }
          else if (iVar14 == 1) {
LAB_14002a58b:
            iVar20 = 8;
          }
          else {
            if (iVar14 != 2) {
              if (iVar14 == 3) goto LAB_14002a58b;
              if (iVar14 != 4) goto LAB_14002a599;
            }
            iVar20 = 9;
          }
LAB_14002a599:
          if (iVar14 == 0) {
            uVar29 = (undefined4)DAT_14053a060;
            uVar30 = (undefined4)((ulonglong)DAT_14053a060 >> 0x20);
          }
          else if (iVar14 == 1) {
            uVar29 = (undefined4)DAT_14053a088;
            uVar30 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
          }
          else if (((iVar14 != 2) && (iVar14 != 3)) &&
                  (uVar29 = uVar35, uVar30 = uVar36, iVar14 == 4)) {
            uVar29 = SUB84(dVar24,0);
            uVar30 = uVar28;
          }
          if (iVar12 == 0x294) {
            *(short *)(param_1 + 0x11) = (short)((local_184 & 0xffff) * 0x4000) + 0x2000;
          }
          dVar25 = (double)FUN_140332d90(((double)(int)param_1[3] - _DAT_14053a800) * DAT_14053a2f8
                                         * DAT_14053a020 * DAT_140539d28);
          *(short *)(param_1 + 0x11) =
               *(short *)(param_1 + 0x11) + (short)(int)(dVar25 * (double)iVar16);
          FUN_140332d90();
          fVar31 = (float)uStack_118;
          local_1e0 = DAT_14053ade0;
          local_1e8 = DAT_14053ad2c;
          uVar10 = FUN_140133f30();
          local_178._4_4_ = (undefined4)((ulonglong)uVar10 >> 0x20);
          local_178._0_4_ = (float)uVar10;
          param_1[0xc] = (float)local_178;
          param_1[0xd] = local_178._4_4_;
          local_178 = uVar10;
          dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - DAT_14053b420),
                                         (double)(DAT_140e445d8 - fVar31));
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar25 * DAT_14053aba0);
          if ((iVar12 - 700U < 0x1c2) &&
             (local_1b8 = (int)(iVar12 - 700U) % iVar17, (int)local_1b8 < iVar21)) {
            local_1b8 = local_1b8 & 0x80000003;
            if ((int)local_1b8 < 0) {
              local_1b8 = (local_1b8 - 1 | 0xfffffffc) + 1;
            }
            if (local_1b8 == 0) {
              local_1c0 = 3000;
              local_1c8._0_4_ = local_188;
              dStack_1d0._0_4_ = 1;
              local_1e0 = uVar8;
              local_1e8 = CONCAT22(local_1e8._2_2_,*(undefined2 *)(param_1 + 0x10));
              local_1d8._0_4_ = uVar32;
              local_1d8._4_4_ = uVar33;
              FUN_1400709b0(2,1,fVar22,fVar23);
              sVar19 = *(short *)(param_1 + 0x10);
              iVar14 = 0;
              do {
                local_1c8._0_4_ = 0.0;
                dStack_1d0._0_4_ = 1;
                local_1e0 = uVar8;
                local_1e8 = CONCAT22(local_1e8._2_2_,(short)iVar14 * 0x5555 + sVar19 + 0x5556);
                local_1d8._0_4_ = uVar32;
                local_1d8._4_4_ = uVar33;
                FUN_14006c2f0(2,1,fVar22,fVar23);
                iVar14 = iVar14 + 1;
              } while (iVar14 < 2);
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
            }
          }
          if (iVar12 - 800U < 0x168) {
            uVar7 = (longlong)(int)(iVar12 - 800U) % (longlong)iVar18;
            local_1b8 = (uint)uVar7;
            if ((local_1b8 == 0) && ((local_184 & 1) == 0)) {
              local_1c0 = 16000;
              dStack_1d0._0_4_ = 1;
              local_1e0 = 0;
              local_1d8._0_4_ = uVar29;
              local_1d8._4_4_ = uVar30;
              local_1c8._0_4_ = (float)iVar20;
              local_1e8._0_2_ = *(undefined2 *)(param_1 + 0x10);
              FUN_1400709b0(5,uVar7 & 0xffffffff,fVar22,fVar23);
              if (2 < DAT_140e419b8) {
                local_1d8 = (double)CONCAT44(uVar30,uVar29) + DAT_140539f28;
                local_1b8 = 0;
                local_1c8._0_4_ = (float)(iVar20 + -1);
                local_1c0 = (int)(16000 / (longlong)(int)(float)local_1c8) * (iVar20 + -2) & 0xffff;
                dStack_1d0._0_4_ = 1;
                local_1e0 = 0;
                local_1e8 = CONCAT22(local_1e8._2_2_,*(undefined2 *)(param_1 + 0x10));
                FUN_1400709b0(5,0,fVar22,fVar23);
              }
            }
          }
        }
      }
    }
  }
  dVar25 = (double)CONCAT44(uVar38,uVar37);
LAB_14002a910:
  local_1e8 = param_1[0xb];
  lVar15 = (longlong)local_168;
  local_1a0 = 0;
  local_1a8 = 1;
  local_1b0 = 0xff;
  local_1b8 = 0xff;
  local_1c0 = 0xff;
  local_1c8._0_4_ = 3.57331e-43;
  local_1e0._0_2_ = *(undefined2 *)(param_1 + 0x10);
  dStack_1d0 = dVar25;
  local_1d8 = dVar25;
  FUN_1400c8410((&DAT_140e44660)[lVar15],0x23,7,param_1[10]);
  if (DAT_140539f40 <= *(double *)(param_1 + 0x12)) {
    local_1e0._0_2_ = *(undefined2 *)(param_1 + 0x10);
    local_1e8 = param_1[0xb];
    local_198 = 0;
    local_1a0 = 0x60;
    local_1a8 = 0xff;
    local_1b0 = 0xff;
    local_1b8 = 0xff;
    local_1c0 = 0x10;
    local_1d8._0_4_ = 0;
    local_1d8._4_4_ = 0;
    local_1c8 = dVar25;
    dStack_1d0 = dVar25;
    FUN_140070d00(5,(&DAT_140e44660)[lVar15],0x22,param_1[10]);
  }
  if ((uStack_128._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


