// Function: FUN_14010cc90 @ 14010cc90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14010cc90(void)

{
  float fVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  ulonglong *puVar11;
  undefined4 *puVar12;
  int iVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  int iVar17;
  uint uVar18;
  ulonglong uVar19;
  ushort uVar20;
  ushort uVar22;
  float fVar23;
  float fVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  float fVar38;
  undefined4 uVar39;
  undefined1 in_stack_fffffffffffffc98 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  ulonglong local_2b8;
  ulonglong uStack_2b0;
  ulonglong local_298;
  undefined8 uStack_290;
  undefined8 local_268;
  ulonglong uStack_260;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  ushort uVar21;
  
  uVar7 = DAT_140539fc0;
  uVar15 = 0;
  uVar32 = (undefined4)DAT_14053aba0;
  uVar33 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
  uVar34 = (undefined4)DAT_14053a020;
  uVar36 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar37 = (undefined4)DAT_140539d28;
  uVar39 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  uVar19 = uVar15;
  do {
    fVar35 = DAT_140e445dc;
    fVar38 = DAT_140e445d8;
    iVar13 = DAT_140e445c0;
    dVar26 = DAT_140539f40;
    iVar9 = 0;
    uVar8 = 0xc000;
    fVar30 = 0.0;
    fVar28 = 0.0;
    uVar21 = 0;
    uVar22 = 0;
    uVar20 = 0;
    bVar5 = false;
    local_248 = _DAT_14053bc40;
    uStack_240 = _UNK_14053bc48;
    iVar10 = 0x5a;
    local_238 = _DAT_14053bbc0;
    uStack_230 = _UNK_14053bbc8;
    local_228 = _DAT_14053bf40;
    uStack_220 = _UNK_14053bf48;
    local_218 = _DAT_14053bbe0;
    uStack_210 = _UNK_14053bbe8;
    local_208 = _DAT_14053b550;
    uStack_200 = _UNK_14053b558;
    local_1f8 = _DAT_14053bc00;
    uStack_1f0 = _UNK_14053bc08;
    local_1c8 = _DAT_14053bf60;
    uStack_1c0 = _UNK_14053bf68;
    local_1b8 = _DAT_14053bbf0;
    uStack_1b0 = _UNK_14053bbf8;
    local_1a8 = 0;
    uStack_1a0 = 0;
    local_148 = _DAT_14053bc50;
    uStack_140 = _UNK_14053bc58;
    local_138 = _DAT_14053b600;
    uStack_130 = _UNK_14053b608;
    local_128 = _DAT_14053bf80;
    uStack_120 = _UNK_14053bf88;
    local_118 = _DAT_14053bf30;
    uStack_110 = _UNK_14053bf38;
    local_108 = _DAT_14053bc30;
    uStack_100 = _UNK_14053bc38;
    local_f8 = _DAT_14053b5f0;
    uStack_f0 = _UNK_14053b5f8;
    local_e8 = _DAT_14053bf70;
    uStack_e0 = _UNK_14053bf78;
    local_d8 = _DAT_14053bf20;
    uStack_d0 = _UNK_14053bf28;
    local_1e8 = _DAT_14053bf10;
    uStack_1e0 = _UNK_14053bf18;
    local_1d8 = _DAT_14053bf90;
    uStack_1d0 = _UNK_14053bf98;
    local_198 = 0;
    uStack_190 = 0;
    local_188 = _DAT_14053bf10;
    uStack_180 = _UNK_14053bf18;
    local_178 = _DAT_14053bf90;
    uStack_170 = _UNK_14053bf98;
    local_168 = _DAT_14053bf10;
    uStack_160 = _UNK_14053bf18;
    local_158 = _DAT_14053bf90;
    uStack_150 = _UNK_14053bf98;
    local_328 = 0xba24c5dc;
    local_324 = 0xb060cfa0;
    local_320 = 0xb448cbb8;
    local_31c = 0xa890d770;
    local_318 = 0xc000c000;
    local_314 = 0xc000c000;
    local_310 = 0xbe0cc1f4;
    local_30c = 0xc000c000;
    local_308 = 0xbf38c0c8;
    local_304 = 0xbd44c2bc;
    local_300 = 0xfe0c01f4;
    local_2fc = 0xfa2405dc;
    local_2f8 = 0xbc18c3e8;
    local_2f4 = 0xbe0cc1f4;
    local_2f0 = 0xc000c000;
    local_2ec = 0xc000c000;
    local_2e8 = 0xc000c000;
    local_2e4 = 0xc000c000;
    local_2e0 = 0xc000c000;
    local_2dc = 0xbc18c3e8;
    local_2d8 = 0xc000c000;
    local_2d4 = 0xc000c000;
    local_2d0 = 0xc000c000;
    local_2cc = 0xbe0cc1f4;
    if (DAT_140e44644 == 0) {
      lVar16 = (longlong)DAT_140e445c0;
      lVar14 = (longlong)DAT_140e445c4;
      if (DAT_140e445c0 == 1) {
        if (DAT_140e445c4 == 1) {
LAB_14010cf8f:
          uVar18 = (uint)DAT_140e4463c;
          uVar20 = DAT_140e4463c;
          if (DAT_140e467c4 == 1) {
            iVar17 = -uVar18 + 0xae6c;
            iVar9 = -uVar18 + 0x1ae6c;
            if (-0x8001 < iVar17) {
              iVar9 = iVar17;
            }
            iVar17 = iVar9 + -0x10000;
            if (iVar9 < 0x8001) {
              iVar17 = iVar9;
            }
            if (iVar17 < 1) {
              if (iVar17 < 0) {
                if (iVar17 < -0x59) goto LAB_14010d073;
                uVar20 = 0xae6c;
              }
            }
            else {
              if (0x59 < iVar17) goto LAB_14010d060;
              uVar20 = 0xae6c;
            }
          }
          else if (DAT_140e467c0 == 1) {
            iVar17 = -uVar18 + 0xd194;
            iVar9 = -uVar18 + 0x1d194;
            if (-0x8001 < iVar17) {
              iVar9 = iVar17;
            }
            iVar17 = iVar9 + -0x10000;
            if (iVar9 < 0x8001) {
              iVar17 = iVar9;
            }
            if (iVar17 < 1) {
              if (iVar17 < 0) {
                if (iVar17 < -0x59) {
LAB_14010d073:
                  uVar20 = DAT_140e4463c - 0x5a;
                }
                else {
                  uVar20 = 0xd194;
                }
              }
            }
            else if (iVar17 < 0x5a) {
              uVar20 = 0xd194;
            }
            else {
LAB_14010d060:
              uVar20 = DAT_140e4463c + 0x5a;
            }
          }
          else {
            iVar17 = -uVar18 + 0xc000;
            iVar9 = -uVar18 + 0x1c000;
            if (-0x8001 < iVar17) {
              iVar9 = iVar17;
            }
            iVar17 = iVar9 + -0x10000;
            if (iVar9 < 0x8001) {
              iVar17 = iVar9;
            }
            if (iVar17 < 1) {
              if (iVar17 < 0) {
                if (iVar17 < -0x59) goto LAB_14010d073;
                uVar20 = 0xc000;
              }
            }
            else {
              if (0x59 < iVar17) goto LAB_14010d060;
              uVar20 = 0xc000;
            }
          }
          uVar22 = uVar21;
          DAT_140e4463c = uVar20;
          if (DAT_140e445c0 == 1) {
            if (DAT_140e445c4 == 1) {
              local_2c8 = _DAT_14053c580;
              uStack_2c0 = _UNK_14053c588;
              dVar25 = (double)FUN_1403307c0();
              fVar30 = (float)(dVar25 * DAT_14053a460) + fVar38;
              dVar25 = (double)FUN_140332d90();
              fVar28 = (float)(dVar25 * DAT_14053a460) + fVar35 + DAT_14053ac58;
              uVar22 = *(short *)((longlong)&local_300 + uVar19 * 2) + uVar20;
            }
          }
          else if ((DAT_140e445c0 == 2) && (DAT_140e445c4 == 0)) {
            fVar30 = DAT_140e445d8 + *(float *)(&local_148 + uVar19);
            fVar28 = DAT_140e445dc + *(float *)((longlong)&local_148 + uVar19 * 8 + 4);
            uVar22 = uVar20;
          }
          bVar5 = true;
          if (iVar13 == 2) goto LAB_14010d140;
          goto LAB_14010d199;
        }
      }
      else if (DAT_140e445c0 == 2) {
        if (DAT_140e445c4 == 0) goto LAB_14010cf8f;
LAB_14010d140:
        if (DAT_140e445c8 == 1) {
          if (DAT_140e44648 < 0x11) {
            lVar14 = uVar19 + lVar14 * 4;
            fVar30 = DAT_140e445e0 + *(float *)(&local_148 + lVar14);
            fVar28 = DAT_140e445e4 + *(float *)((longlong)&local_148 + lVar14 * 8 + 4);
            uVar22 = *(ushort *)((longlong)&local_2e8 + lVar14 * 2);
            goto LAB_14010d199;
          }
          DAT_140e445e0 = fVar38;
          DAT_140e445e4 = fVar35;
        }
        if (bVar5) goto LAB_14010d199;
      }
      lVar14 = uVar19 + (lVar14 + lVar16 * 4) * 4;
      fVar30 = fVar38 + *(float *)(&local_248 + lVar14);
      fVar28 = fVar35 + *(float *)((longlong)&local_248 + lVar14 * 8 + 4);
      uVar22 = *(ushort *)((longlong)&local_328 + lVar14 * 2);
      goto LAB_14010d199;
    }
    if (DAT_140e445c0 == 0) {
      if (DAT_140e445c8 == 0) {
        fVar30 = DAT_140e445d8 + *(float *)(&local_208 + uVar19);
        fVar28 = DAT_140e445dc + *(float *)((longlong)&local_208 + uVar19 * 8 + 4);
        uVar8 = 0xc000;
        iVar13 = FUN_1401340e0();
        if (((iVar13 < 1) || ((-1 - (int)uVar15) * 5 < DAT_140e44648)) || (DAT_140e44640 < 1)) {
          (&DAT_140e4462c)[uVar19] = 0;
          uVar20 = uVar8;
        }
        else {
          uVar20 = 0;
          if ((&DAT_140e4462c)[uVar19] == 0) {
            iVar9 = FUN_1401341a0();
            (&DAT_140e4462c)[uVar19] = iVar9;
            if (iVar9 == 0) {
              uVar8 = 0xc000;
              uVar20 = 0xc000;
            }
            else {
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47240);
              FUN_14018a340(DAT_140e47240,1,1);
              uVar8 = 0xc000;
            }
          }
          else {
            local_2b8 = local_2b8 & 0xffffffff00000000;
            if ((0 < DAT_140e44e6c) && (puVar11 = DAT_140e45d80, DAT_140e45d80 != (ulonglong *)0x0))
            {
              do {
                if (*(int *)((longlong)puVar11 + 4) == (&DAT_140e4462c)[uVar19]) {
                  local_2b8 = *puVar11;
                  uStack_2b0 = puVar11[1];
                  local_268 = puVar11[10];
                  uStack_260 = puVar11[0xb];
                  local_298 = puVar11[4];
                  uStack_290 = puVar11[5];
                }
                puVar11 = (ulonglong *)puVar11[0xc];
              } while (puVar11 != (ulonglong *)0x0);
              iVar9 = (int)local_2b8;
            }
            if ((iVar9 == 1) && (local_268._4_4_ == 0)) {
              dVar25 = (double)(int)local_268 / DAT_14053a460;
              dVar27 = (double)FUN_140332d90(((double)DAT_140e44acc - 0.0) * _DAT_14053ab30 *
                                             (double)CONCAT44(uVar36,uVar34) *
                                             (double)CONCAT44(uVar39,uVar37));
              dVar25 = dVar27 * dVar25 * DAT_140539e60 + dVar25;
              dVar27 = (double)FUN_1403300b4((double)(uStack_290._4_4_ -
                                                     (float)(&DAT_140e44608)[uVar19 * 2]),
                                             SUB84((double)((float)uStack_290 -
                                                           (float)(&DAT_140e44604)[uVar19 * 2]),0));
              in_stack_fffffffffffffc98._8_4_ = SUB84(dVar25,0);
              in_stack_fffffffffffffc98._0_8_ = dVar25;
              in_stack_fffffffffffffc98._12_4_ = (int)((ulonglong)dVar25 >> 0x20);
              FUN_1400c8410(DAT_140e41a80,0x46,7);
              uVar8 = 0xc000;
              uVar20 = (ushort)(int)(dVar27 * (double)CONCAT44(uVar33,uVar32));
            }
            else {
              (&DAT_140e4462c)[uVar19] = 0;
            }
          }
        }
        iVar9 = 1;
        goto LAB_14010d4c6;
      }
LAB_14010d4e9:
      lVar14 = uVar19 + ((longlong)DAT_140e445c8 + (longlong)DAT_140e445c0 * 4) * 4;
      fVar30 = DAT_140e445d8 + *(float *)(&local_208 + lVar14);
      fVar28 = DAT_140e445dc + *(float *)((longlong)&local_208 + lVar14 * 8 + 4);
      uVar22 = *(ushort *)((longlong)&local_318 + lVar14 * 2);
    }
    else {
LAB_14010d4c6:
      fVar29 = DAT_140e445e4;
      fVar31 = DAT_140e445e0;
      fVar35 = DAT_140e445dc;
      fVar38 = DAT_140e445d8;
      if (DAT_140e445c0 == 1) {
        if (DAT_140e445c4 == 1) {
          DAT_140e4463c = uVar8;
        }
LAB_14010d4e1:
        uVar22 = uVar20;
        if (iVar9 == 0) goto LAB_14010d4e9;
      }
      else {
        if (DAT_140e445c0 != 2) goto LAB_14010d4e1;
        if (DAT_140e445c8 == 0) {
          fVar30 = DAT_140e445d8 + *(float *)(&local_108 + uVar19);
          fVar28 = DAT_140e445dc + *(float *)((longlong)&local_108 + uVar19 * 8 + 4);
          uVar22 = DAT_140e4463c;
        }
        else {
          if (DAT_140e445c8 != 1) goto LAB_14010d4e1;
          FUN_1403300b4((double)(DAT_140e445dc - DAT_140e445e4),
                        SUB84((double)(DAT_140e445d8 - DAT_140e445e0),0));
          if (DAT_140e44648 == -2) {
            fVar28 = (float)FUN_140334430();
            fVar30 = (float)FUN_140334430();
            if (fVar28 + fVar30 < 0.0) {
              fVar28 = (float)FUN_1403352f8();
            }
            else {
              fVar28 = SQRT(fVar28 + fVar30);
            }
            if (fVar28 <= DAT_14053ac80) {
              DAT_140e445e0 = fVar38;
              DAT_140e445e4 = fVar35;
              fVar29 = fVar35;
              fVar31 = fVar38;
            }
          }
          iVar9 = FUN_1401340e0();
          fVar35 = DAT_14053b02c;
          fVar28 = DAT_14053b438;
          puVar11 = DAT_140e45d80;
          if (0 < iVar9) {
            for (; puVar11 != (ulonglong *)0x0; puVar11 = (ulonglong *)puVar11[0xc]) {
              fVar30 = *(float *)(puVar11 + 5);
              fVar1 = *(float *)((longlong)puVar11 + 0x2c);
              uVar6 = puVar11[10];
              fVar23 = (float)FUN_140334430(fVar31 - fVar30,uVar7);
              fVar24 = (float)FUN_140334430(fVar29 - fVar1);
              if (fVar23 + fVar24 < 0.0) {
                fVar23 = (float)FUN_1403352f8();
              }
              else {
                fVar23 = SQRT(fVar23 + fVar24);
              }
              fVar23 = fVar23 - (float)(int)uVar6;
              if ((((fVar23 < fVar35) && (*(int *)((longlong)puVar11 + 0x54) == 0)) &&
                  ((int)puVar11[0xb] == 1)) &&
                 (iVar9 = FUN_140134750(puVar11[5],(int)uVar6 + 100), iVar9 == 1)) {
                fVar28 = fVar1;
                fVar35 = fVar23;
                fVar38 = fVar30;
              }
            }
            FUN_1403300b4((double)((fVar28 + DAT_14053adb4) - fVar29),
                          SUB84((double)(fVar38 - fVar31),0));
            uVar34 = (undefined4)DAT_14053a020;
            uVar36 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
          }
          uVar37 = (undefined4)DAT_140539d28;
          uVar39 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
          dVar25 = (double)FUN_1403307c0();
          fVar31 = fVar31 + (float)(dVar25 * DAT_140539e60);
          DAT_140e445e0 = fVar31;
          dVar25 = (double)FUN_140332d90();
          fVar30 = fVar31 + *(float *)(&local_e8 + uVar19);
          DAT_140e445e4 = fVar29 + (float)(dVar25 * DAT_140539e60);
          fVar28 = DAT_140e445e4 + *(float *)((longlong)&local_e8 + uVar19 * 8 + 4);
          uVar22 = *(ushort *)((longlong)&local_2d0 + uVar19 * 2);
        }
      }
    }
LAB_14010d199:
    fVar38 = (float)(&DAT_140e44608)[uVar19 * 2];
    fVar35 = (float)(&DAT_140e44604)[uVar19 * 2];
    FUN_1403300b4((double)(fVar28 - fVar38),SUB84((double)(fVar30 - fVar35),0));
    fVar30 = (float)FUN_140334430(fVar35 - fVar30,uVar7);
    fVar28 = (float)FUN_140334430(fVar38 - fVar28);
    if (fVar30 + fVar28 < 0.0) {
      fVar28 = (float)FUN_1403352f8();
    }
    else {
      fVar28 = SQRT(fVar30 + fVar28);
    }
    dVar27 = (double)fVar28 * DAT_140539ed8;
    dVar25 = (double)FUN_1403307c0();
    (&DAT_140e44604)[uVar19 * 2] = (float)(dVar25 * dVar27) + fVar35;
    dVar25 = (double)FUN_140332d90();
    (&DAT_140e44608)[uVar19 * 2] = (float)(dVar25 * dVar27) + fVar38;
    uVar20 = (&DAT_140e44624)[uVar19];
    uVar8 = uVar22 - uVar20;
    uVar18 = (uint)uVar8;
    if (0x8000 < uVar8) {
      uVar18 = 0x10000 - uVar8;
    }
    iVar13 = (uint)uVar22 - (uint)uVar20;
    iVar17 = (int)uVar18 / 10 + 0x80;
    iVar9 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar9 = iVar13;
    }
    iVar13 = iVar9 + -0x10000;
    if (iVar9 < 0x8001) {
      iVar13 = iVar9;
    }
    if (iVar13 < 1) {
      uVar8 = uVar20;
      if ((iVar13 < 0) && (uVar8 = uVar20 - (short)iVar17, -iVar17 < iVar13)) {
        uVar8 = uVar22;
      }
    }
    else {
      uVar8 = uVar22;
      if (iVar17 <= iVar13) {
        uVar8 = uVar20 + (short)iVar17;
      }
    }
    (&DAT_140e44624)[uVar19] = uVar8;
    if ((DAT_140e445fc - 0xb4U < 0x50) && (dVar26 = DAT_140539f40, 0xb3 < DAT_140e445fc)) {
      if (DAT_140e445fc < 0xbe) {
        dVar26 = (double)DAT_140e445fc - DAT_14053a548;
      }
      else {
        dVar26 = 0.0;
        if ((DAT_140e445fc < 0xfa) || (dVar26 = DAT_140539f40, 0x103 < DAT_140e445fc))
        goto LAB_14010d92f;
        dVar26 = (double)DAT_140e445fc - DAT_14053a5e8;
      }
      dVar26 = (double)FUN_140332d90(dVar26 * DAT_14053a9d8 * (double)CONCAT44(uVar36,uVar34) *
                                     (double)CONCAT44(uVar39,uVar37));
      dVar26 = dVar26 * DAT_14053b0a0 + DAT_140539f40;
    }
LAB_14010d92f:
    iVar9 = DAT_140e44acc;
    if (DAT_140e445c0 == 0) {
      auVar40._12_4_ = in_stack_fffffffffffffc98._12_4_;
      auVar40._0_8_ = in_stack_fffffffffffffc98._0_8_;
      auVar40._8_4_ = 0x5d;
      in_stack_fffffffffffffc98._4_12_ = auVar40._4_12_;
      in_stack_fffffffffffffc98._0_4_ = 0x5c;
      iVar10 = FUN_1400c9580(DAT_140e44acc,0,6,5,0x5a,0x5b,in_stack_fffffffffffffc98,0x5e);
    }
    if (DAT_140e445c0 == 1) {
      auVar41._12_4_ = in_stack_fffffffffffffc98._12_4_;
      auVar41._0_8_ = in_stack_fffffffffffffc98._0_8_;
      auVar41._8_4_ = 0x60;
      in_stack_fffffffffffffc98._4_12_ = auVar41._4_12_;
      in_stack_fffffffffffffc98._0_4_ = 0x61;
      iVar10 = FUN_1400c9580(iVar9,0,6,4,0x5f,0x60,in_stack_fffffffffffffc98);
    }
    if (DAT_140e445c0 == 2) {
      auVar42._12_4_ = in_stack_fffffffffffffc98._12_4_;
      auVar42._0_8_ = in_stack_fffffffffffffc98._0_8_;
      auVar42._8_4_ = 0x65;
      in_stack_fffffffffffffc98._4_12_ = auVar42._4_12_;
      in_stack_fffffffffffffc98._0_4_ = 100;
      iVar10 = FUN_1400c9580(iVar9,0,6,5,0x62,99,in_stack_fffffffffffffc98,0x66);
    }
    uVar2 = (&DAT_140e44624)[uVar19];
    uVar32 = (&DAT_140e44608)[uVar19 * 2];
    uVar33 = (&DAT_140e44604)[uVar19 * 2];
    uVar3 = (&DAT_140e44e70)[iVar10];
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(undefined2 *)(puVar12 + 5) = uVar2;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    puVar12[3] = uVar33;
    puVar12[4] = uVar32;
    *puVar12 = uVar3;
    puVar12[1] = 0x2c;
    puVar12[2] = 7;
    auVar4._8_4_ = SUB84(dVar26,0);
    auVar4._0_8_ = dVar26;
    auVar4._12_4_ = (int)((ulonglong)dVar26 >> 0x20);
    *(undefined1 (*) [16])(puVar12 + 6) = auVar4;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = 0xff;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    _DAT_140e46d40 = _DAT_140e46d40 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
    uVar32 = (undefined4)DAT_14053aba0;
    uVar33 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
    uVar18 = (int)uVar15 + 1;
    uVar15 = (ulonglong)uVar18;
    DAT_140e46c88 = puVar12;
    uVar19 = uVar19 + 1;
    if (3 < (int)uVar18) {
      return;
    }
  } while( true );
}


