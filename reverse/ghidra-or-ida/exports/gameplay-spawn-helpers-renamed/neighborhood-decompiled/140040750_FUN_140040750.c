// Function: FUN_140040750 @ 140040750
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140040750(undefined4 *param_1)

{
  float fVar1;
  ushort uVar2;
  undefined4 *puVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined4 *puVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  ulonglong uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  ulonglong uVar19;
  longlong lVar20;
  int iVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined1 auStack_258 [32];
  undefined4 local_238;
  uint local_230;
  double local_228;
  undefined4 local_220;
  undefined4 local_218;
  undefined4 local_210;
  uint local_208;
  int local_204;
  uint local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  undefined8 local_1e0;
  int local_1d8 [4];
  int local_1c8 [4];
  int local_1b8;
  ulonglong local_1b0;
  undefined4 *local_1a8;
  undefined4 local_1a0;
  int iStack_19c;
  undefined4 uStack_198;
  int iStack_194;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  undefined4 local_168;
  int iStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  float fStack_150;
  float fStack_14c;
  undefined8 local_128;
  undefined8 uStack_120;
  float afStack_108 [12];
  ulonglong local_d8;
  
  iVar17 = DAT_140e419b8;
  uVar11 = DAT_14053ac2c;
  dVar22 = DAT_14053a778;
  dVar23 = DAT_14053a628;
  dVar7 = DAT_14053a3d0;
  dVar6 = DAT_14053a020;
  dVar5 = DAT_140539f40;
  dVar4 = DAT_140539d28;
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_258;
  uVar15 = 0;
  uStack_15c = 0;
  iVar18 = iStack_164;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined4 *)0x0)) {
    iStack_194 = 0;
    local_178 = 0;
  }
  else {
    iStack_194 = 0;
    local_178 = 0;
    puVar8 = DAT_140e45d80;
    do {
      if (puVar8[1] == DAT_140e44308) {
        local_178 = *puVar8;
        uStack_174 = puVar8[1];
        uStack_170 = puVar8[2];
        iStack_16c = puVar8[3];
        local_168 = puVar8[4];
        iVar18 = puVar8[5];
        uStack_160 = puVar8[6];
        iStack_194 = puVar8[7];
        fStack_150 = (float)puVar8[10];
        fStack_14c = (float)puVar8[0xb];
        local_128 = *(undefined8 *)(puVar8 + 0x14);
        uStack_120 = *(undefined8 *)(puVar8 + 0x16);
      }
      puVar8 = *(undefined4 **)(puVar8 + 0x18);
    } while (puVar8 != (undefined4 *)0x0);
  }
  local_1c8[0] = 0;
  local_1c8[1] = 0;
  iVar14 = 6000;
  local_1c8[2] = 0;
  local_1d8[0] = 0;
  local_1d8[1] = 0;
  local_1d8[2] = 0;
  iVar16 = 8000;
  if ((param_1[6] - 0xa8 & 0xfffffffd) == 0) {
    iVar14 = 2000;
    iVar16 = 6000;
  }
  fVar24 = (float)param_1[0xe];
  uVar25 = (undefined4)DAT_14053a3f8;
  uVar27 = (undefined4)((ulonglong)DAT_14053a3f8 >> 0x20);
  local_208 = 0;
  local_200 = (uint)(fVar24 < 0.0);
  local_1f0 = -2000;
  if (0.0 <= fVar24) {
    local_1f0 = 2000;
  }
  local_1e8 = 2000;
  if (0.0 <= fVar24) {
    local_1e8 = -2000;
  }
  local_1ec = -16000;
  if (0.0 <= fVar24) {
    local_1ec = 16000;
  }
  local_1b8 = -0x4b0;
  if (0.0 <= fVar24) {
    local_1b8 = 0x4b0;
  }
  local_1f4 = -iVar16;
  if (0.0 <= fVar24) {
    local_1f4 = iVar16;
  }
  local_1f8 = -iVar14;
  if (0.0 <= fVar24) {
    local_1f8 = iVar14;
  }
  param_1[10] = fStack_150 + fVar24;
  param_1[0xb] = fStack_14c + (float)param_1[0xf];
  local_204 = iVar18;
  local_1fc = iStack_16c;
  local_1a8 = param_1;
  local_1a0 = local_168;
  iStack_19c = iVar18;
  uStack_198 = uStack_160;
  local_190 = local_128;
  uStack_188 = uStack_120;
  do {
    iVar16 = local_1fc;
    uVar12 = (uint)uVar15;
    sVar9 = (short)local_1f8;
    local_1b0 = uVar15;
    if (iVar18 < 0xb) {
      *(ushort *)(param_1 + 0x10) = sVar9 + 0xc000U;
      iVar14 = local_1e8 * uVar12 + (uint)(ushort)(sVar9 + 0xc000U);
      local_1c8[uVar15] = iVar14;
      dVar22 = (double)FUN_140332d90(((double)(int)(uVar12 * -0xc + -0x14) - 0.0) * dVar22 * dVar6 *
                                     dVar4);
      local_1d8[uVar15] = (int)(dVar22 * (double)local_1f0) + iVar14 + local_1ec;
      uVar19 = uVar15;
    }
    else {
      if (iVar18 == 0xb) {
        param_1[3] = local_1fc;
        if ((-1 < local_1fc) && (sVar9 = (short)local_1f4 + sVar9, local_1fc < 0x3c)) {
          dVar23 = (double)FUN_140332d90(((double)local_1fc - 0.0) * dVar23 * dVar6 * dVar4);
          sVar9 = (short)(int)(dVar23 * (double)local_1f4) + (short)local_1f8;
        }
        *(short *)(param_1 + 0x10) = sVar9 + -0x4000;
      }
      uVar15 = local_1b0 & 0xffffffff;
      iVar16 = local_1e8 * uVar12;
      uVar2 = *(ushort *)(param_1 + 0x10);
      if ((int)(uVar12 * 0xc) <= (int)param_1[3]) {
        dVar23 = (double)FUN_140332d90(((double)(int)param_1[3] - (double)(int)(uVar12 * 0xc)) *
                                       dVar22 * dVar6 * dVar4);
        iVar16 = (int)(dVar23 * (double)local_1b8) + iVar16;
      }
      uVar12 = local_208;
      local_1c8[uVar15] = iVar16 + (uint)uVar2;
      dVar22 = (double)FUN_140332d90(((double)(int)param_1[3] -
                                     (double)(int)(local_208 * 0xc + 0x14)) * dVar22 * dVar6 * dVar4
                                    );
      uVar19 = local_1b0;
      local_1d8[uVar15] = (int)(dVar22 * (double)local_1f0) + iVar16 + (uint)uVar2 + local_1ec;
      iVar16 = local_1fc;
    }
    dVar22 = (double)FUN_1403307c0();
    dVar23 = (double)FUN_140332d90();
    dVar22 = dVar22 * dVar7;
    fVar24 = (float)(dVar23 * dVar7);
    if ((int)uVar19 == 0) {
      local_1e0 = CONCAT44(fVar24 + (float)param_1[0xb],(float)dVar22 + (float)param_1[10]);
    }
    else {
      local_1e0 = CONCAT44(fVar24 + afStack_108[(uVar19 & 0xffffffff) * 2 + 5],
                           (float)dVar22 + afStack_108[(uVar19 & 0xffffffff) * 2 + 4]);
    }
    fVar24 = (float)local_1e0;
    afStack_108[uVar15 * 2 + 6] = (float)local_1e0;
    afStack_108[uVar15 * 2 + 7] = local_1e0._4_4_;
    dVar22 = (double)FUN_1403307c0();
    dVar23 = (double)FUN_140332d90();
    afStack_108[uVar15 * 2] = (float)(dVar22 * (double)CONCAT44(uVar27,uVar25)) + fVar24;
    afStack_108[uVar15 * 2 + 1] =
         (float)(dVar23 * (double)CONCAT44(uVar27,uVar25)) + afStack_108[uVar15 * 2 + 7];
    if (iVar18 == 0xb) {
      if (iVar16 == 1) {
        if (param_1[6] == 0xa7) {
          local_210 = param_1[1];
          local_238 = param_1[0xf];
          local_218 = 0;
          local_220 = 0x32;
          local_228 = 0.0;
          local_230 = local_230 & 0xffff0000;
          stage_entity_spawn_candidate(0xa9,99999999,0,param_1[0xe]);
          iVar17 = DAT_140e419b8;
        }
        if (param_1[6] == 0xa8) {
          local_210 = param_1[1];
          local_238 = param_1[0xf];
          local_218 = 0;
          local_220 = 0x32;
          local_228 = 0.0;
          local_230 = local_230 & 0xffff0000;
          stage_entity_spawn_candidate(0xaa,99999999,0,param_1[0xe]);
          iVar17 = DAT_140e419b8;
        }
      }
      if (param_1[6] == 0xa7) {
        iVar16 = (param_1[3] + -0x3c) % 0x640;
        local_1e0 = CONCAT44(local_1e0._4_4_,iVar16);
        uVar26 = SUB84(dVar5,0);
        uVar28 = (undefined4)((ulonglong)dVar5 >> 0x20);
        if (iVar16 - 0x15eU < 0x119) {
          iVar18 = 1;
          if (iVar17 == 0) {
            iVar18 = 9;
          }
          else if (iVar17 == 1) {
LAB_140040da3:
            iVar18 = 6;
          }
          else {
            if (iVar17 != 2) {
              if (iVar17 == 3) goto LAB_140040da3;
              if (iVar17 != 4) goto LAB_140040db1;
            }
            iVar18 = 5;
          }
LAB_140040db1:
          dVar22 = DAT_14053a070;
          if ((((iVar17 != 0) && (dVar22 = DAT_14053a0b0, iVar17 != 1)) &&
              (dVar22 = DAT_14053a0f8, iVar17 != 2)) &&
             ((dVar22 = DAT_14053a0d0, iVar17 != 3 && (dVar22 = dVar5, iVar17 == 4)))) {
            dVar22 = DAT_14053a120;
          }
          if ((iVar16 < 0x276) && ((int)(iVar16 - 0x15eU) % iVar18 == 0)) {
            sVar9 = (short)iVar16 * 0x140 + 0x4a80;
            sVar13 = ((short)uVar12 * 6000 - sVar9) + -0x8000;
            if (local_200 == 1) {
              sVar13 = sVar9 + (short)uVar12 * -6000 + 0x6000;
            }
            iVar17 = 0;
            fVar24 = afStack_108[(uVar19 & 0xffffffff) * 2 + 1];
            fVar1 = afStack_108[(uVar19 & 0xffffffff) * 2];
            iVar18 = iVar17;
            do {
              local_218 = 0;
              local_220 = 1;
              local_230 = uVar11;
              local_238 = CONCAT22(local_238._2_2_,(short)iVar18 * 300 + sVar13 + -0x96);
              local_228 = dVar22;
              FUN_14006c2f0(8,0,fVar1,fVar24);
              iVar18 = iVar18 + 1;
            } while (iVar18 < 2);
            if (2 < DAT_140e419b8) {
              do {
                local_218 = 0;
                local_220 = 1;
                local_230 = uVar11;
                local_238 = CONCAT22(local_238._2_2_,(short)iVar17 * 300 + sVar13 + -0x96);
                local_228 = dVar22 + dVar5;
                FUN_14006c2f0(8,0,fVar1,fVar24);
                iVar17 = iVar17 + 1;
              } while (iVar17 < 2);
            }
            uVar12 = local_208;
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            uVar19 = local_1b0;
            iVar17 = DAT_140e419b8;
          }
        }
        iVar18 = local_204;
        if (iVar16 - 0x424U < 0x1f5) {
          iVar18 = uVar12 + 0x3c;
          iVar14 = 1;
          iVar21 = iVar18 * 0x14;
          if (iVar17 == 0) {
            iVar14 = 0xd2;
          }
          else if ((iVar17 == 1) || (iVar17 == 2)) {
            iVar14 = 0x96;
          }
          else if (iVar17 == 3) {
            iVar14 = 0x78;
          }
          else if (iVar17 == 4) {
            iVar14 = 100;
          }
          if (iVar17 == 0) {
            uVar26 = (undefined4)DAT_14053a118;
            uVar28 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
          }
          else if (iVar17 == 1) {
            uVar26 = (undefined4)DAT_14053a178;
            uVar28 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
          }
          else if (iVar17 == 2) {
            uVar26 = (undefined4)DAT_14053a190;
            uVar28 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
          }
          else if (iVar17 == 3) {
            uVar26 = (undefined4)DAT_14053a1b8;
            uVar28 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
          }
          else if (iVar17 == 4) {
            uVar26 = (undefined4)DAT_14053a200;
            uVar28 = (undefined4)((ulonglong)DAT_14053a200 >> 0x20);
          }
          if (iVar21 <= iVar16) {
            if ((iVar16 < 0x618) && ((iVar16 + iVar18 * -0x14) % iVar14 == 0)) {
              dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc -
                                                     afStack_108[(uVar19 & 0xffffffff) * 2 + 1]),
                                             (double)(DAT_140e445d8 -
                                                     afStack_108[(uVar19 & 0xffffffff) * 2]));
              *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar22 * DAT_14053aba0);
              uVar12 = (iVar16 + iVar18 * -0x14) % iVar14;
            }
            else if ((iVar16 < iVar21) ||
                    ((0x617 < iVar16 ||
                     (uVar12 = (iVar16 + iVar18 * -0x14) % iVar14, 0x13 < (int)uVar12))))
            goto LAB_140041220;
            uVar12 = uVar12 & 0x80000003;
            if ((int)uVar12 < 0) {
              uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
            }
            if (uVar12 == 0) {
              iVar18 = 0;
              local_218 = 0;
              local_220 = 1;
              local_228 = (double)CONCAT44(uVar28,uVar26);
              fVar24 = afStack_108[(uVar19 & 0xffffffff) * 2 + 1];
              local_230 = uVar11;
              fVar1 = afStack_108[(uVar19 & 0xffffffff) * 2];
              local_238 = CONCAT22(local_238._2_2_,*(undefined2 *)((longlong)param_1 + 0x42));
              FUN_14006c2f0(9,0,fVar1,fVar24);
              if (2 < DAT_140e419b8) {
                sVar9 = *(short *)((longlong)param_1 + 0x42);
                dVar22 = (double)CONCAT44(uVar28,uVar26) - DAT_140539f00;
                iVar17 = iVar18;
                do {
                  local_218 = 0;
                  local_220 = 1;
                  local_230 = uVar11;
                  local_238 = CONCAT22(local_238._2_2_,(short)iVar17 * 1000 + sVar9 + -500);
                  local_228 = dVar22;
                  FUN_14006c2f0(9,0,fVar1,fVar24);
                  iVar17 = iVar17 + 1;
                } while (iVar17 < 2);
                param_1 = local_1a8;
                iVar16 = (int)(float)local_1e0;
              }
              if (iVar21 + iVar14 * 2 <= iVar16) {
                sVar9 = *(short *)((longlong)param_1 + 0x42);
                do {
                  local_218 = 0;
                  local_220 = 1;
                  local_228 = (double)CONCAT44(uVar28,uVar26);
                  local_230 = uVar11;
                  local_238 = CONCAT22(local_238._2_2_,(short)iVar18 * 0x1e61 + sVar9 + -0xf30);
                  FUN_14006c2f0(9,0,fVar1,fVar24);
                  iVar18 = iVar18 + 1;
                  param_1 = local_1a8;
                } while (iVar18 < 2);
              }
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
              iVar17 = DAT_140e419b8;
            }
          }
LAB_140041220:
          uVar25 = (undefined4)DAT_14053a3f8;
          uVar27 = (undefined4)((ulonglong)DAT_14053a3f8 >> 0x20);
          iVar18 = local_204;
          uVar12 = local_208;
        }
      }
    }
    iVar21 = local_1fc;
    puVar8 = DAT_140e45d80;
    iVar14 = DAT_140e44e6c;
    iVar16 = DAT_140e44308;
    local_208 = uVar12 + 1;
    uVar15 = (ulonglong)local_208;
    dVar23 = DAT_14053a628;
    dVar22 = DAT_14053a778;
  } while ((int)local_208 < 3);
  if (param_1[6] - 0xa9 < 2) {
    iVar10 = param_1[1] - DAT_1407c77a0;
    iVar17 = param_1[7];
    *(undefined8 *)(param_1 + 10) =
         *(undefined8 *)
          (afStack_108 +
          (longlong)
          (iVar10 + (iVar10 / 3 + (iVar10 >> 0x1f) +
                    (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * -3) * 2);
    if ((iVar17 < iStack_194) && (puVar3 = puVar8, 0 < iVar14)) {
      for (; puVar3 != (undefined4 *)0x0; puVar3 = *(undefined4 **)(puVar3 + 0x18)) {
        if (puVar3[1] == iVar16) {
          puVar3[7] = puVar3[7] - (iStack_194 - iVar17);
        }
      }
    }
    iVar17 = param_1[7];
    if (iStack_194 < (int)param_1[7]) {
      param_1[7] = iStack_194;
      iVar17 = iStack_194;
    }
    if ((iVar17 < 1) && (0 < iVar14)) {
      for (; puVar8 != (undefined4 *)0x0; puVar8 = *(undefined4 **)(puVar8 + 0x18)) {
        if (puVar8[1] == iVar16) {
          puVar8[7] = puVar8[7] - iStack_194;
        }
      }
    }
    if (local_190._4_4_ == 1) {
      param_1[0x15] = 1;
    }
  }
  puVar8 = DAT_140e46c88;
  if (param_1[6] - 0xa7 < 2) {
    lVar20 = 2;
    iVar17 = 10;
    uVar11 = local_200;
    do {
      uVar25 = DAT_140e44d70;
      if (uVar11 == 1) {
        local_1c8[lVar20] = local_1c8[lVar20] + 0x8000;
        local_1d8[lVar20] = local_1d8[lVar20] + 0x8000;
      }
      if ((iVar18 < 0x14) || ((puVar8 = DAT_140e46c88, iVar18 < 0x15 && (iVar21 <= iVar17)))) {
        iVar18 = local_1d8[lVar20];
        fVar24 = afStack_108[lVar20 * 2 + 1];
        fVar1 = afStack_108[lVar20 * 2];
        puVar8 = (undefined4 *)_malloc_base(0x48);
        if (puVar8 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        uVar11 = local_200;
        *puVar8 = uVar25;
        *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
        puVar8[0xf] = local_200;
        puVar8[3] = fVar1;
        puVar8[4] = fVar24;
        puVar8[1] = 0x1d;
        puVar8[2] = 7;
        *(short *)(puVar8 + 5) = (short)iVar18;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0xff;
        puVar8[0xc] = 0xff;
        puVar8[0xd] = 0xff;
        puVar8[0xe] = 1;
        *(undefined8 *)(puVar8 + 0x10) = 0;
        _DAT_140e46d04 = _DAT_140e46d04 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar8;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
        }
        uVar25 = DAT_140e44d6c;
        iVar18 = local_1c8[lVar20];
        DAT_140e46c88 = puVar8;
        if (lVar20 == 0) {
          uVar27 = param_1[0xb];
          uVar26 = param_1[10];
          puVar8 = (undefined4 *)_malloc_base(0x48);
          if (puVar8 == (undefined4 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          puVar8[3] = uVar26;
          *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
          *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
          puVar8[4] = uVar27;
          *puVar8 = uVar25;
          puVar8[1] = 0x1d;
          puVar8[2] = 7;
          *(short *)(puVar8 + 5) = (short)iVar18;
          puVar8[10] = 0xff;
          puVar8[0xb] = 0xff;
          puVar8[0xc] = 0xff;
          puVar8[0xd] = 0xff;
          puVar8[0xe] = 1;
          puVar8[0xf] = uVar11;
          *(undefined8 *)(puVar8 + 0x10) = 0;
          _DAT_140e46d04 = _DAT_140e46d04 + 1;
          if (DAT_140e46bf0 == (undefined4 *)0x0) {
            DAT_140e46bf0 = puVar8;
          }
          if (DAT_140e46c88 != (undefined4 *)0x0) {
            *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
          }
          break;
        }
        fVar24 = afStack_108[lVar20 * 2 + 5];
        fVar1 = afStack_108[lVar20 * 2 + 4];
        puVar8 = (undefined4 *)_malloc_base();
        if (puVar8 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
        puVar8[3] = fVar1;
        puVar8[4] = fVar24;
        *puVar8 = uVar25;
        puVar8[1] = 0x1d;
        puVar8[2] = 7;
        *(short *)(puVar8 + 5) = (short)iVar18;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0xff;
        puVar8[0xc] = 0xff;
        puVar8[0xd] = 0xff;
        puVar8[0xe] = 1;
        puVar8[0xf] = local_200;
        *(undefined8 *)(puVar8 + 0x10) = 0;
        _DAT_140e46d04 = _DAT_140e46d04 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar8;
        }
        iVar18 = local_204;
        uVar11 = local_200;
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
        }
      }
      DAT_140e46c88 = puVar8;
      iVar17 = iVar17 + 10;
      lVar20 = lVar20 + -1;
      puVar8 = DAT_140e46c88;
    } while (-1 < lVar20);
  }
  DAT_140e46c88 = puVar8;
  if (0x13 < local_204) {
    if ((param_1[6] - 0xa9 < 2) &&
       (iVar18 = param_1[1] - DAT_1407c77a0,
       iVar21 == (3 - (iVar18 + (iVar18 / 3 + (iVar18 >> 0x1f) +
                                (int)(((longlong)iVar18 / 3 + ((longlong)iVar18 >> 0x3f) &
                                      0xffffffffU) >> 0x1f)) * -3)) * 10)) {
      FUN_140079e20(param_1,0);
    }
    if (iVar21 == 0x3c) {
      *param_1 = 0;
    }
  }
  return;
}


