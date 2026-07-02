// Function: FUN_1402632c0 @ 1402632c0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1402632c0(uint param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  longlong *plVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined8 uVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  undefined8 uVar15;
  uint uVar16;
  longlong *plVar17;
  int *piVar18;
  undefined8 *puVar19;
  short *psVar20;
  int *piVar21;
  int *piVar22;
  longlong lVar23;
  longlong lVar24;
  undefined8 *puVar25;
  short *psVar26;
  undefined8 *puVar27;
  char *pcVar28;
  char *pcVar29;
  char *pcVar30;
  undefined4 *puVar31;
  undefined4 *puVar32;
  undefined8 *puVar33;
  undefined4 *puVar34;
  undefined8 *puVar35;
  undefined8 *puVar36;
  ulonglong uVar37;
  char cVar38;
  int iVar39;
  char cVar40;
  int iVar41;
  ulonglong uVar42;
  ulonglong uVar43;
  undefined1 auStack_328 [32];
  ulonglong local_308;
  ulonglong local_300;
  undefined8 local_2f8;
  ulonglong local_2f0;
  ulonglong local_2e8;
  undefined4 *local_2e0;
  ulonglong local_2d8;
  undefined4 *local_2d0;
  longlong local_2c8;
  int local_2b8;
  int local_2b4;
  undefined4 local_2b0;
  longlong *local_2a8;
  uint local_2a0;
  longlong *local_298;
  longlong local_290;
  longlong local_288;
  char local_280;
  char local_27f;
  int local_278;
  int *local_270;
  char *local_268;
  int local_260;
  undefined4 local_25c;
  longlong local_258;
  ulonglong local_250;
  undefined8 local_248;
  ulonglong local_238;
  undefined8 local_230;
  undefined4 local_220;
  undefined8 local_218;
  undefined4 local_210;
  int local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined8 local_1f8 [2];
  longlong alStack_1e8 [52];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_328;
  if ((((DAT_14098a8e8 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_14098a938))
     && ((int)(param_1 & 0x3ffff) < DAT_14098a940)) {
    piVar22 = *(int **)(DAT_14098a8f0 + (ulonglong)(param_1 & 0x3ffff) * 8);
    if ((piVar22 != (int *)0x0) && (*piVar22 << 0x12 == (param_1 & 0x3fc0000))) {
      local_270 = piVar22;
      local_25c = param_3;
      if (piVar22[6] != 0) {
        if ((piVar22[6] < 2) && (-1 < piVar22[8])) {
          iVar12 = FUN_1401afbe0();
        }
        else {
          iVar12 = FUN_1401b82b0(param_1);
        }
        if (iVar12 < 0) {
          return 0xffffffff;
        }
        if (*(longlong *)(DAT_14098a8f0 + (ulonglong)(param_1 & 0x3ffff) * 8) == 0) {
          return 0xffffffff;
        }
      }
      if (piVar22[0xcd] != 0) {
        return 0;
      }
      piVar22[0x1dc] = param_2;
      FUN_1401ae370(piVar22 + 0x104,0,0x1b0);
      FUN_1401ae370(piVar22 + 0x170,0,0x1b0);
      piVar21 = piVar22 + 0xce;
      FUN_1401ae370(piVar21,0,0xd8);
      piVar22[0xcc] = 0;
      FUN_1401ae370(local_1f8,0,0x1b0);
      plVar17 = *(longlong **)(piVar22 + 0x84);
      local_2a0 = 0;
      if (0 < piVar22[0x82]) {
        do {
          sVar2 = (short)plVar17[1];
          if (sVar2 == 0) {
            uVar42 = (ulonglong)(piVar22[0x2a] != 0);
LAB_14026348a:
            local_2b0 = (int)plVar17[2];
            iVar12 = (uint)*(ushort *)(plVar17 + 0x26) +
                     (uint)*(ushort *)((longlong)plVar17 + 0x124);
            if (piVar22[0x2a] != 0) {
              local_2b0 = local_2b0 * (int)plVar17[0x28];
              iVar12 = iVar12 * (int)plVar17[0x28];
            }
            local_298 = (longlong *)(ulonglong)(*(int *)(*(longlong *)(*plVar17 + 8) + 0x170) != 0);
            local_2a8 = (longlong *)(uVar42 * 2);
            local_278 = iVar12;
            if (alStack_1e8[((longlong)local_2a8 + (longlong)local_298) * 9] == 0) {
              piVar22[0xcc] = piVar22[0xcc] + 1;
              lVar23 = (longlong)local_2a8 + (longlong)local_298;
              piVar22[lVar23 * 9 + 0xd0] = piVar22[lVar23 * 9 + 0xd0] + 1;
              lVar14 = FUN_1401b6390(0x50,
                                     "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                     ,0x1d2);
              alStack_1e8[lVar23 * 9] = lVar14;
              FUN_1401ae370(lVar14,0,0x50);
              *(longlong *)(alStack_1e8[lVar23 * 9] + 0x20) = alStack_1e8[lVar23 * 9] + 0x38;
              *(longlong *)(piVar22 + lVar23 * 0x12 + 0x108) = alStack_1e8[lVar23 * 9];
              *(longlong *)(piVar22 + lVar23 * 0x12 + 0x174) = alStack_1e8[lVar23 * 9];
            }
            piVar18 = (int *)alStack_1e8
                             [(((ulonglong)local_298 & 0xffffffff) + (longlong)local_2a8) * 9];
            if ((0xbffff < piVar18[1] + iVar12) || (0x5ffff < *piVar18 + local_2b0)) {
              piVar22[0xcc] = piVar22[0xcc] + 1;
              lVar23 = ((ulonglong)local_298 & 0xffffffff) + (longlong)local_2a8;
              piVar22[lVar23 * 9 + 0xd0] = piVar22[lVar23 * 9 + 0xd0] + 1;
              uVar15 = FUN_1401b6390(0x50,
                                     "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                     ,0x1e2);
              *(undefined8 *)(piVar18 + 10) = uVar15;
              FUN_1401ae370(uVar15,0,0x50);
              *(longlong *)(*(longlong *)(piVar18 + 10) + 0x20) = *(longlong *)(piVar18 + 10) + 0x38
              ;
              *(int **)(*(longlong *)(piVar18 + 10) + 0x30) = piVar18;
              *(undefined8 *)(piVar22 + lVar23 * 0x12 + 0x174) = *(undefined8 *)(piVar18 + 10);
              piVar18 = *(int **)(piVar18 + 10);
              alStack_1e8[lVar23 * 9] = (longlong)piVar18;
              iVar12 = local_278;
            }
            plVar17[0x29] = (longlong)piVar18;
            *(int *)(plVar17 + 0x2a) = *piVar18;
            iVar41 = piVar18[1];
            *(int *)((longlong)plVar17 + 0x154) = iVar41;
            if (piVar22[0x2a] == 0) {
              *(uint *)(plVar17 + 0x2b) = (uint)*(ushort *)((longlong)plVar17 + 0x124) + iVar41;
            }
            else {
              *(uint *)(plVar17 + 0x2b) =
                   (int)plVar17[0x28] * (uint)*(ushort *)((longlong)plVar17 + 0x124) + iVar41;
            }
            *piVar18 = *piVar18 + local_2b0;
            piVar18[1] = piVar18[1] + iVar12;
          }
          else {
            if (sVar2 == 1) {
              uVar42 = 1;
              goto LAB_14026348a;
            }
            uVar42 = 2;
            if ((sVar2 == 2) || (uVar42 = 0, sVar2 == 3)) goto LAB_14026348a;
          }
          local_2a0 = local_2a0 + 1;
          plVar17 = plVar17 + 0x2c;
        } while ((int)local_2a0 < piVar22[0x82]);
      }
      lVar23 = 0xce;
      plVar17 = (longlong *)(piVar22 + 0x170);
      do {
        lVar14 = 2;
        do {
          lVar24 = 0;
          do {
            lVar3 = *plVar17;
            if ((lVar3 != 0) && (*(int *)(lVar3 + 4) == 0)) {
              *plVar17 = *(longlong *)(lVar3 + 0x30);
              if (*(longlong *)(lVar3 + 0x30) != 0) {
                *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x28) = 0;
              }
              FUN_1401b6700();
              piVar22[0xcc] = piVar22[0xcc] + -1;
              piVar22[lVar23 + lVar24] = piVar22[lVar23 + lVar24] + -1;
            }
            lVar24 = lVar24 + 1;
            plVar17 = plVar17 + 1;
          } while (lVar24 < 9);
          lVar23 = lVar23 + 9;
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
      } while (lVar23 < 0x104);
      FUN_1401ae370(&local_250,0,0x18);
      local_248 = 1;
      local_250 = 0;
      FUN_1401ae370(&local_238,0,0x18);
      local_238 = 0;
      local_230 = 2;
      lVar23 = (longlong)piVar22 - (longlong)local_1f8;
      local_2b0 = 0;
      puVar27 = local_1f8;
      local_288 = lVar23;
      do {
        local_278 = 0;
        local_2a8 = puVar27;
        iVar12 = local_2b0;
        do {
          iVar39 = 0;
          local_298 = puVar27;
          iVar41 = local_278;
          do {
            piVar18 = *(int **)(lVar23 + 0x410 + (longlong)puVar27);
            *puVar27 = piVar18;
            if (piVar18 != (int *)0x0) {
              iVar13 = FUN_140260f20(iVar41,iVar12);
              do {
                piVar18[6] = iVar13;
                local_250 = CONCAT44(local_250._4_4_,iVar13 * *piVar18);
                iVar12 = FUN_14021d710(&local_250,0,*(undefined8 *)(piVar18 + 8),param_3);
                if (iVar12 < 0) {
LAB_140263a70:
                  local_298 = (longlong *)0x3;
                  local_2a8 = (longlong *)(piVar22 + 0x104);
                  do {
                    lVar23 = 2;
                    do {
                      lVar14 = 9;
                      do {
                        lVar24 = *local_2a8;
                        while (lVar24 != 0) {
                          if (*(longlong *)(lVar24 + 8) != 0) {
                            FUN_1401b6700();
                            *(undefined8 *)(lVar24 + 8) = 0;
                          }
                          if (*(longlong *)(lVar24 + 0x10) != 0) {
                            FUN_1401b6700();
                            *(undefined8 *)(lVar24 + 0x10) = 0;
                          }
                          if (**(longlong **)(lVar24 + 0x20) != 0) {
                            FUN_14021f170(**(longlong **)(lVar24 + 0x20),param_3);
                          }
                          lVar3 = *(longlong *)(*(longlong *)(lVar24 + 0x20) + 8);
                          if (lVar3 != 0) {
                            FUN_14021f170(lVar3,param_3);
                          }
                          lVar3 = *(longlong *)(lVar24 + 0x28);
                          FUN_1401b6700(lVar24);
                          lVar24 = lVar3;
                        }
                        *local_2a8 = 0;
                        local_2a8[0x36] = 0;
                        local_2a8 = local_2a8 + 1;
                        *piVar21 = 0;
                        piVar21 = piVar21 + 1;
                        lVar14 = lVar14 + -1;
                      } while (lVar14 != 0);
                      lVar23 = lVar23 + -1;
                    } while (lVar23 != 0);
                    local_298 = (longlong *)((longlong)local_298 + -1);
                  } while (local_298 != (longlong *)0x0);
                  local_270[0xcc] = 0;
                  return 0xffffffff;
                }
                lVar23 = FUN_1401b6390(local_250 & 0xffffffff,
                                       "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                       ,0x239);
                *(longlong *)(piVar18 + 2) = lVar23;
                if (lVar23 == 0) goto LAB_140263a70;
                local_238 = CONCAT44(local_238._4_4_,piVar18[1] * 2);
                iVar12 = FUN_14021d710(&local_238,0,*(longlong *)(piVar18 + 8) + 8,param_3);
                if (iVar12 < 0) goto LAB_140263a70;
                lVar23 = FUN_1401b6390(local_238 & 0xffffffff,
                                       "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                       ,0x248);
                *(longlong *)(piVar18 + 4) = lVar23;
                if (lVar23 == 0) goto LAB_140263a70;
                piVar18 = *(int **)(piVar18 + 10);
                lVar23 = local_288;
                iVar41 = local_278;
                iVar12 = local_2b0;
              } while (piVar18 != (int *)0x0);
            }
            iVar39 = iVar39 + 1;
            puVar27 = puVar27 + 1;
          } while (iVar39 < 9);
          local_278 = iVar41 + 1;
          puVar27 = local_298 + 9;
        } while (local_278 < 2);
        local_2b0 = iVar12 + 1;
        puVar27 = local_2a8 + 0x12;
        if (2 < local_2b0) {
          plVar17 = *(longlong **)(piVar22 + 0x84);
          local_260 = 0;
          if (0 < piVar22[0x82]) {
            do {
              uVar11 = _UNK_1404ad428;
              uVar15 = _DAT_1404ad420;
              local_258 = plVar17[0x29];
              if (((local_258 != 0) && (**(longlong **)(local_258 + 0x20) != 0)) &&
                 ((*(longlong **)(local_258 + 0x20))[1] != 0)) {
                plVar4 = (longlong *)*plVar17;
                local_2a0 = *(uint *)(plVar17 + 2);
                uVar42 = (ulonglong)local_2a0;
                local_2b8 = *(int *)((longlong)plVar4 + 0x74);
                local_288 = plVar4[0xf];
                local_2b4 = *(int *)(plVar4[1] + 0x170);
                local_290 = *(longlong *)(*plVar4 + 0x210);
                iVar12 = *(int *)((longlong)plVar4 + 100);
                if (2 < *(int *)((longlong)plVar4 + 100)) {
                  iVar12 = 2;
                }
                local_2a8 = (longlong *)(longlong)iVar12;
                sVar2 = (short)plVar17[1];
                pcVar28 = local_268;
                local_298 = plVar17;
                if (sVar2 == 0) {
                  puVar27 = (undefined8 *)(plVar17[0x23] + 0xfU & 0xfffffffffffffff0);
                  pcVar29 = (char *)((ulonglong)
                                     (uint)((int)plVar17[0x2a] * *(int *)(local_258 + 0x18)) +
                                    *(longlong *)(local_258 + 8));
                  piVar21 = (int *)plVar17[0x1f];
                  if (piVar22[0x2a] == 0) {
                    if (0 < (int)local_2a0) {
                      puVar36 = (undefined8 *)0x0;
                      do {
                        lVar23 = (ulonglong)(uint)(*piVar21 * local_2b8) + local_288;
                        uVar37 = (ulonglong)*(uint *)(lVar23 + 4);
                        *(undefined8 *)pcVar29 = *puVar27;
                        *(undefined4 *)(pcVar29 + 8) = *(undefined4 *)(puVar27 + 1);
                        puVar25 = (undefined8 *)(local_290 + (uVar37 * 9 + 6) * 4);
                        if (local_2b4 == 0) {
                          puVar25 = puVar36;
                        }
                        *(undefined8 *)(pcVar29 + 0xc) = *(undefined8 *)(local_290 + uVar37 * 0x24);
                        puVar19 = (undefined8 *)(local_290 + uVar37 * 0x24 + 0xc);
                        if (local_2b4 == 0) {
                          puVar19 = puVar36;
                        }
                        *(undefined4 *)(pcVar29 + 0x14) =
                             *(undefined4 *)(local_290 + 8 + uVar37 * 0x24);
                        puVar35 = (undefined8 *)(lVar23 + 0x1c);
                        if ((longlong)local_2a8 < 2) {
                          puVar35 = puVar36;
                        }
                        pcVar29[0x1a] = *(char *)(lVar23 + 8);
                        pcVar29[0x19] = *(char *)(lVar23 + 9);
                        puVar33 = (undefined8 *)(lVar23 + 0x14);
                        if ((longlong)local_2a8 < 1) {
                          puVar33 = puVar36;
                        }
                        pcVar29[0x18] = *(char *)(lVar23 + 10);
                        pcVar29[0x1b] = *(char *)(lVar23 + 0xb);
                        pcVar29[0x1e] = *(char *)(lVar23 + 0xc);
                        pcVar29[0x1d] = *(char *)(lVar23 + 0xd);
                        pcVar29[0x1c] = *(char *)(lVar23 + 0xe);
                        pcVar29[0x1f] = *(char *)(lVar23 + 0xf);
                        if (puVar33 == (undefined8 *)0x0) {
                          pcVar29[0x20] = '\0';
                          pcVar29[0x21] = '\0';
                          pcVar29[0x22] = '\0';
                          pcVar29[0x23] = '\0';
                          pcVar29[0x24] = '\0';
                          pcVar29[0x25] = '\0';
                          pcVar29[0x26] = '\0';
                          pcVar29[0x27] = '\0';
                        }
                        else {
                          *(undefined4 *)(pcVar29 + 0x20) = *(undefined4 *)puVar33;
                          *(undefined4 *)(pcVar29 + 0x24) = *(undefined4 *)((longlong)puVar33 + 4);
                        }
                        pcVar29[0x28] = '\0';
                        pcVar29[0x29] = '\0';
                        pcVar29[0x2a] = -0x80;
                        pcVar29[0x2b] = '?';
                        pcVar29[0x2c] = '\0';
                        pcVar29[0x2d] = '\0';
                        pcVar29[0x2e] = -0x80;
                        pcVar29[0x2f] = '?';
                        if (puVar35 == (undefined8 *)0x0) {
                          if (puVar33 == (undefined8 *)0x0) {
                            pcVar29[0x30] = '\0';
                            pcVar29[0x31] = '\0';
                            pcVar29[0x32] = '\0';
                            pcVar29[0x33] = '\0';
                            pcVar29[0x34] = '\0';
                            pcVar29[0x35] = '\0';
                            pcVar29[0x36] = '\0';
                            pcVar29[0x37] = '\0';
                          }
                          else {
                            *(undefined4 *)(pcVar29 + 0x30) = *(undefined4 *)puVar33;
                            *(undefined4 *)(pcVar29 + 0x34) = *(undefined4 *)((longlong)puVar33 + 4)
                            ;
                          }
                        }
                        else {
                          *(undefined4 *)(pcVar29 + 0x30) = *(undefined4 *)puVar35;
                          *(undefined4 *)(pcVar29 + 0x34) = *(undefined4 *)((longlong)puVar35 + 4);
                        }
                        pcVar29[0x38] = '\0';
                        pcVar29[0x39] = '\0';
                        pcVar29[0x3a] = -0x80;
                        pcVar29[0x3b] = '?';
                        pcVar29[0x3c] = '\0';
                        pcVar29[0x3d] = '\0';
                        pcVar29[0x3e] = -0x80;
                        pcVar29[0x3f] = '?';
                        pcVar30 = pcVar29 + 0x40;
                        if (puVar19 != (undefined8 *)0x0) {
                          *(undefined8 *)(pcVar29 + 0x40) = *puVar19;
                          *(undefined4 *)(pcVar29 + 0x48) = *(undefined4 *)(puVar19 + 1);
                          pcVar30 = pcVar29 + 0x4c;
                        }
                        pcVar29 = pcVar30;
                        if (puVar25 != (undefined8 *)0x0) {
                          *(undefined8 *)pcVar29 = *puVar25;
                          *(undefined4 *)(pcVar29 + 8) = *(undefined4 *)(puVar25 + 1);
                          pcVar29 = pcVar29 + 0xc;
                        }
                        puVar27 = puVar27 + 4;
                        piVar21 = piVar21 + 1;
                        uVar42 = uVar42 - 1;
                        piVar22 = local_270;
                      } while (uVar42 != 0);
                    }
                  }
                  else {
                    local_220 = 0;
                    if (0 < (int)local_2a0) {
                      puVar36 = (undefined8 *)0x0;
                      do {
                        lVar23 = (ulonglong)(uint)(*piVar21 * local_2b8) + local_288;
                        uVar37 = (ulonglong)*(uint *)(lVar23 + 4);
                        *(undefined8 *)pcVar29 = *puVar27;
                        *(undefined4 *)(pcVar29 + 8) = *(undefined4 *)(puVar27 + 1);
                        puVar25 = (undefined8 *)(local_290 + (uVar37 * 9 + 6) * 4);
                        if (local_2b4 == 0) {
                          puVar25 = puVar36;
                        }
                        *(undefined8 *)(pcVar29 + 0xc) = *(undefined8 *)(local_290 + uVar37 * 0x24);
                        puVar19 = (undefined8 *)(local_290 + uVar37 * 0x24 + 0xc);
                        if (local_2b4 == 0) {
                          puVar19 = puVar36;
                        }
                        *(undefined4 *)(pcVar29 + 0x14) =
                             *(undefined4 *)(local_290 + 8 + uVar37 * 0x24);
                        puVar35 = (undefined8 *)(lVar23 + 0x1c);
                        if ((longlong)local_2a8 < 2) {
                          puVar35 = puVar36;
                        }
                        pcVar29[0x1a] = *(char *)(lVar23 + 8);
                        pcVar29[0x19] = *(char *)(lVar23 + 9);
                        puVar33 = (undefined8 *)(lVar23 + 0x14);
                        if ((longlong)local_2a8 < 1) {
                          puVar33 = puVar36;
                        }
                        pcVar29[0x18] = *(char *)(lVar23 + 10);
                        pcVar29[0x1b] = *(char *)(lVar23 + 0xb);
                        pcVar29[0x1e] = *(char *)(lVar23 + 0xc);
                        pcVar29[0x1d] = *(char *)(lVar23 + 0xd);
                        pcVar29[0x1c] = *(char *)(lVar23 + 0xe);
                        pcVar29[0x1f] = *(char *)(lVar23 + 0xf);
                        if (puVar33 == (undefined8 *)0x0) {
                          pcVar29[0x20] = '\0';
                          pcVar29[0x21] = '\0';
                          pcVar29[0x22] = '\0';
                          pcVar29[0x23] = '\0';
                          pcVar29[0x24] = '\0';
                          pcVar29[0x25] = '\0';
                          pcVar29[0x26] = '\0';
                          pcVar29[0x27] = '\0';
                        }
                        else {
                          *(undefined4 *)(pcVar29 + 0x20) = *(undefined4 *)puVar33;
                          *(undefined4 *)(pcVar29 + 0x24) = *(undefined4 *)((longlong)puVar33 + 4);
                        }
                        pcVar29[0x28] = '\0';
                        pcVar29[0x29] = '\0';
                        pcVar29[0x2a] = -0x80;
                        pcVar29[0x2b] = '?';
                        pcVar29[0x2c] = '\0';
                        pcVar29[0x2d] = '\0';
                        pcVar29[0x2e] = -0x80;
                        pcVar29[0x2f] = '?';
                        if (puVar35 == (undefined8 *)0x0) {
                          if (puVar33 == (undefined8 *)0x0) {
                            pcVar29[0x30] = '\0';
                            pcVar29[0x31] = '\0';
                            pcVar29[0x32] = '\0';
                            pcVar29[0x33] = '\0';
                            pcVar29[0x34] = '\0';
                            pcVar29[0x35] = '\0';
                            pcVar29[0x36] = '\0';
                            pcVar29[0x37] = '\0';
                          }
                          else {
                            *(undefined4 *)(pcVar29 + 0x30) = *(undefined4 *)puVar33;
                            *(undefined4 *)(pcVar29 + 0x34) = *(undefined4 *)((longlong)puVar33 + 4)
                            ;
                          }
                        }
                        else {
                          *(undefined4 *)(pcVar29 + 0x30) = *(undefined4 *)puVar35;
                          *(undefined4 *)(pcVar29 + 0x34) = *(undefined4 *)((longlong)puVar35 + 4);
                        }
                        pcVar29[0x38] = '\0';
                        pcVar29[0x39] = '\0';
                        pcVar29[0x3a] = -0x80;
                        pcVar29[0x3b] = '?';
                        pcVar29[0x3c] = '\0';
                        pcVar29[0x3d] = '\0';
                        pcVar29[0x3e] = -0x80;
                        pcVar29[0x3f] = '?';
                        pcVar28 = pcVar29 + 0x40;
                        if (puVar19 != (undefined8 *)0x0) {
                          *(undefined8 *)pcVar28 = *puVar19;
                          *(undefined4 *)(pcVar29 + 0x48) = *(undefined4 *)(puVar19 + 1);
                          pcVar28 = pcVar29 + 0x4c;
                        }
                        if (puVar25 != (undefined8 *)0x0) {
                          *(undefined8 *)pcVar28 = *puVar25;
                          *(undefined4 *)(pcVar28 + 8) = *(undefined4 *)(puVar25 + 1);
                          pcVar28 = pcVar28 + 0xc;
                        }
                        puVar27 = puVar27 + 4;
                        piVar21 = piVar21 + 1;
                        pcVar28[0] = '\0';
                        pcVar28[1] = '\0';
                        pcVar28[2] = '\0';
                        pcVar28[3] = '\0';
                        *(undefined8 *)(pcVar28 + 4) = uVar15;
                        *(undefined8 *)(pcVar28 + 0xc) = uVar11;
                        pcVar29 = pcVar28 + 0x14;
                        uVar42 = uVar42 - 1;
                        piVar22 = local_270;
                      } while (uVar42 != 0);
                    }
                    local_268 = (char *)CONCAT44(local_268._4_4_,1);
                    pcVar28 = local_268;
                    if (1 < (int)plVar17[0x28]) {
                      local_268._0_4_ = 1;
                      do {
                        uVar42 = (ulonglong)local_2a0;
                        piVar22 = (int *)plVar17[0x1f];
                        puVar27 = (undefined8 *)(plVar17[0x23] + 0xfU & 0xfffffffffffffff0);
                        if (0 < (int)local_2a0) {
                          do {
                            local_220 = (uint)local_268 & 0xff;
                            lVar23 = (ulonglong)(uint)(*piVar22 * local_2b8) + local_288;
                            uVar37 = (ulonglong)*(uint *)(lVar23 + 4);
                            puVar31 = (undefined4 *)(lVar23 + 0x14);
                            *(undefined8 *)pcVar29 = *puVar27;
                            puVar36 = (undefined8 *)(local_290 + (uVar37 * 9 + 6) * 4);
                            if (local_2b4 == 0) {
                              puVar36 = (undefined8 *)0x0;
                            }
                            puVar25 = (undefined8 *)(local_290 + uVar37 * 0x24 + 0xc);
                            puVar34 = (undefined4 *)(lVar23 + 0x1c);
                            if (local_2b4 == 0) {
                              puVar25 = (undefined8 *)0x0;
                            }
                            if ((longlong)local_2a8 < 2) {
                              puVar34 = (undefined4 *)0x0;
                            }
                            if ((longlong)local_2a8 < 1) {
                              puVar31 = (undefined4 *)0x0;
                            }
                            *(undefined4 *)(pcVar29 + 8) = *(undefined4 *)(puVar27 + 1);
                            *(undefined8 *)(pcVar29 + 0xc) =
                                 *(undefined8 *)(local_290 + uVar37 * 0x24);
                            *(undefined4 *)(pcVar29 + 0x14) =
                                 *(undefined4 *)(local_290 + 8 + uVar37 * 0x24);
                            pcVar29[0x1a] = *(char *)(lVar23 + 8);
                            pcVar29[0x19] = *(char *)(lVar23 + 9);
                            pcVar29[0x18] = *(char *)(lVar23 + 10);
                            pcVar29[0x1b] = *(char *)(lVar23 + 0xb);
                            pcVar29[0x1e] = *(char *)(lVar23 + 0xc);
                            pcVar29[0x1d] = *(char *)(lVar23 + 0xd);
                            pcVar29[0x1c] = *(char *)(lVar23 + 0xe);
                            pcVar29[0x1f] = *(char *)(lVar23 + 0xf);
                            if (puVar31 == (undefined4 *)0x0) {
                              pcVar29[0x20] = '\0';
                              pcVar29[0x21] = '\0';
                              pcVar29[0x22] = '\0';
                              pcVar29[0x23] = '\0';
                              pcVar29[0x24] = '\0';
                              pcVar29[0x25] = '\0';
                              pcVar29[0x26] = '\0';
                              pcVar29[0x27] = '\0';
                            }
                            else {
                              *(undefined4 *)(pcVar29 + 0x20) = *puVar31;
                              *(undefined4 *)(pcVar29 + 0x24) = puVar31[1];
                            }
                            pcVar29[0x28] = '\0';
                            pcVar29[0x29] = '\0';
                            pcVar29[0x2a] = -0x80;
                            pcVar29[0x2b] = '?';
                            pcVar29[0x2c] = '\0';
                            pcVar29[0x2d] = '\0';
                            pcVar29[0x2e] = -0x80;
                            pcVar29[0x2f] = '?';
                            if (puVar34 == (undefined4 *)0x0) {
                              if (puVar31 == (undefined4 *)0x0) {
                                pcVar29[0x30] = '\0';
                                pcVar29[0x31] = '\0';
                                pcVar29[0x32] = '\0';
                                pcVar29[0x33] = '\0';
                                pcVar29[0x34] = '\0';
                                pcVar29[0x35] = '\0';
                                pcVar29[0x36] = '\0';
                                pcVar29[0x37] = '\0';
                              }
                              else {
                                *(undefined4 *)(pcVar29 + 0x30) = *puVar31;
                                *(undefined4 *)(pcVar29 + 0x34) = puVar31[1];
                              }
                            }
                            else {
                              *(undefined4 *)(pcVar29 + 0x30) = *puVar34;
                              *(undefined4 *)(pcVar29 + 0x34) = puVar34[1];
                            }
                            pcVar29[0x38] = '\0';
                            pcVar29[0x39] = '\0';
                            pcVar29[0x3a] = -0x80;
                            pcVar29[0x3b] = '?';
                            pcVar29[0x3c] = '\0';
                            pcVar29[0x3d] = '\0';
                            pcVar29[0x3e] = -0x80;
                            pcVar29[0x3f] = '?';
                            pcVar30 = pcVar29 + 0x40;
                            if (puVar25 != (undefined8 *)0x0) {
                              *(undefined8 *)pcVar30 = *puVar25;
                              *(undefined4 *)(pcVar29 + 0x48) = *(undefined4 *)(puVar25 + 1);
                              pcVar30 = pcVar29 + 0x4c;
                            }
                            if (puVar36 != (undefined8 *)0x0) {
                              *(undefined8 *)pcVar30 = *puVar36;
                              *(undefined4 *)(pcVar30 + 8) = *(undefined4 *)(puVar36 + 1);
                              pcVar30 = pcVar30 + 0xc;
                            }
                            puVar27 = puVar27 + 4;
                            piVar22 = piVar22 + 1;
                            *pcVar30 = (char)(uint)local_268 * '\x03';
                            pcVar30[1] = '\0';
                            pcVar30[2] = '\0';
                            pcVar30[3] = '\0';
                            *(undefined8 *)(pcVar30 + 4) = uVar15;
                            *(undefined8 *)(pcVar30 + 0xc) = uVar11;
                            pcVar29 = pcVar30 + 0x14;
                            uVar42 = uVar42 - 1;
                          } while (uVar42 != 0);
                        }
                        local_268._0_4_ = (uint)local_268 + 1;
                        piVar22 = local_270;
                      } while ((int)(uint)local_268 < (int)plVar17[0x28]);
                    }
                  }
                }
                else if (sVar2 == 1) {
                  piVar21 = (int *)plVar17[0x1f];
                  local_268 = (char *)((ulonglong)
                                       (uint)((int)plVar17[0x2a] * *(int *)(local_258 + 0x18)) +
                                      *(longlong *)(local_258 + 8));
                  uVar37 = plVar17[0x23] + 0xfU & 0xfffffffffffffff0;
                  if (0 < (int)local_2a0) {
                    uVar43 = 0;
                    do {
                      local_2c8 = 0;
                      local_2e0 = (undefined4 *)(uVar37 + 0x2c);
                      local_2d0 = (undefined4 *)0x0;
                      lVar14 = (ulonglong)(uint)(*piVar21 * local_2b8) + local_288;
                      lVar23 = local_290 + (ulonglong)*(uint *)(lVar14 + 4) * 0x24;
                      local_308 = lVar14 + 0xc;
                      local_2f0 = lVar23 + 0xc;
                      local_2e8 = lVar23 + 0x18;
                      if (local_2b4 == 0) {
                        local_2f0 = uVar43;
                        local_2e8 = uVar43;
                      }
                      local_2f8 = lVar14 + 0x1c;
                      if ((longlong)local_2a8 < 2) {
                        local_2f8 = uVar43;
                      }
                      local_300 = lVar14 + 0x14;
                      if ((longlong)local_2a8 < 1) {
                        local_300 = uVar43;
                      }
                      local_2d8 = uVar37;
                      FUN_140260f50(&local_268,uVar37 + 0x10,lVar23,lVar14 + 8);
                      uVar37 = uVar37 + 0x30;
                      piVar21 = piVar21 + 1;
                      uVar42 = uVar42 - 1;
                    } while (uVar42 != 0);
                    uVar42 = (ulonglong)local_2a0;
                    piVar22 = local_270;
                  }
                  pcVar29 = local_268;
                  pcVar28 = local_268;
                  if (piVar22[0x2a] != 0) {
                    local_278 = (int)plVar17[3];
                    iVar12 = 1;
                    local_268 = (char *)CONCAT44(local_268._4_4_,1);
                    pcVar28 = local_268;
                    if (1 < (int)plVar17[0x28]) {
                      do {
                        piVar22 = (int *)plVar17[0x1f];
                        puVar31 = (undefined4 *)(plVar17[0x23] + 0xfU & 0xfffffffffffffff0);
                        if (0 < (int)uVar42) {
                          do {
                            cVar40 = *(char *)(puVar31 + 0xb);
                            cVar1 = *(char *)((longlong)puVar31 + 0x2d);
                            cVar38 = (char)local_278;
                            lVar23 = (ulonglong)(uint)(*piVar22 * local_2b8) + local_288;
                            uVar37 = (ulonglong)*(uint *)(lVar23 + 4);
                            puVar34 = (undefined4 *)(lVar23 + 0x1c);
                            local_280 = *(char *)((longlong)puVar31 + 0x2e) + cVar38;
                            puVar27 = (undefined8 *)(local_290 + (uVar37 * 9 + 6) * 4);
                            local_27f = *(char *)((longlong)puVar31 + 0x2f);
                            *(undefined8 *)pcVar29 = *(undefined8 *)(puVar31 + 4);
                            local_27f = local_27f + cVar38;
                            puVar36 = (undefined8 *)(local_290 + uVar37 * 0x24 + 0xc);
                            if (local_2b4 == 0) {
                              puVar27 = (undefined8 *)0x0;
                              puVar36 = (undefined8 *)0x0;
                            }
                            if ((longlong)local_2a8 < 2) {
                              puVar34 = (undefined4 *)0x0;
                            }
                            puVar32 = (undefined4 *)(lVar23 + 0x14);
                            if ((longlong)local_2a8 < 1) {
                              puVar32 = (undefined4 *)0x0;
                            }
                            *(undefined4 *)(pcVar29 + 8) = puVar31[6];
                            *(undefined8 *)(pcVar29 + 0xc) =
                                 *(undefined8 *)(local_290 + uVar37 * 0x24);
                            *(undefined4 *)(pcVar29 + 0x14) =
                                 *(undefined4 *)(local_290 + 8 + uVar37 * 0x24);
                            pcVar29[0x1a] = *(char *)(lVar23 + 8);
                            pcVar29[0x19] = *(char *)(lVar23 + 9);
                            pcVar29[0x18] = *(char *)(lVar23 + 10);
                            pcVar29[0x1b] = *(char *)(lVar23 + 0xb);
                            pcVar29[0x1e] = *(char *)(lVar23 + 0xc);
                            pcVar29[0x1d] = *(char *)(lVar23 + 0xd);
                            pcVar29[0x1c] = *(char *)(lVar23 + 0xe);
                            pcVar29[0x1f] = *(char *)(lVar23 + 0xf);
                            if (puVar32 == (undefined4 *)0x0) {
                              pcVar29[0x20] = '\0';
                              pcVar29[0x21] = '\0';
                              pcVar29[0x22] = '\0';
                              pcVar29[0x23] = '\0';
                              pcVar29[0x24] = '\0';
                              pcVar29[0x25] = '\0';
                              pcVar29[0x26] = '\0';
                              pcVar29[0x27] = '\0';
                            }
                            else {
                              *(undefined4 *)(pcVar29 + 0x20) = *puVar32;
                              *(undefined4 *)(pcVar29 + 0x24) = puVar32[1];
                            }
                            pcVar29[0x28] = '\0';
                            pcVar29[0x29] = '\0';
                            pcVar29[0x2a] = -0x80;
                            pcVar29[0x2b] = '?';
                            pcVar29[0x2c] = '\0';
                            pcVar29[0x2d] = '\0';
                            pcVar29[0x2e] = -0x80;
                            pcVar29[0x2f] = '?';
                            if (puVar34 == (undefined4 *)0x0) {
                              if (puVar32 == (undefined4 *)0x0) {
                                pcVar29[0x30] = '\0';
                                pcVar29[0x31] = '\0';
                                pcVar29[0x32] = '\0';
                                pcVar29[0x33] = '\0';
                                pcVar29[0x34] = '\0';
                                pcVar29[0x35] = '\0';
                                pcVar29[0x36] = '\0';
                                pcVar29[0x37] = '\0';
                              }
                              else {
                                *(undefined4 *)(pcVar29 + 0x30) = *puVar32;
                                *(undefined4 *)(pcVar29 + 0x34) = puVar32[1];
                              }
                            }
                            else {
                              *(undefined4 *)(pcVar29 + 0x30) = *puVar34;
                              *(undefined4 *)(pcVar29 + 0x34) = puVar34[1];
                            }
                            pcVar29[0x38] = '\0';
                            pcVar29[0x39] = '\0';
                            pcVar29[0x3a] = -0x80;
                            pcVar29[0x3b] = '?';
                            pcVar29[0x3c] = '\0';
                            pcVar29[0x3d] = '\0';
                            pcVar29[0x3e] = -0x80;
                            pcVar29[0x3f] = '?';
                            pcVar28 = pcVar29 + 0x40;
                            if (puVar36 != (undefined8 *)0x0) {
                              *(undefined8 *)pcVar28 = *puVar36;
                              *(undefined4 *)(pcVar29 + 0x48) = *(undefined4 *)(puVar36 + 1);
                              pcVar28 = pcVar29 + 0x4c;
                            }
                            if (puVar27 != (undefined8 *)0x0) {
                              *(undefined8 *)pcVar28 = *puVar27;
                              *(undefined4 *)(pcVar28 + 8) = *(undefined4 *)(puVar27 + 1);
                              pcVar28 = pcVar28 + 0xc;
                            }
                            *pcVar28 = (cVar40 + cVar38) * '\x03';
                            piVar22 = piVar22 + 1;
                            pcVar28[1] = (cVar1 + cVar38) * '\x03';
                            pcVar28[2] = local_280 * '\x03';
                            pcVar28[3] = local_27f * '\x03';
                            uVar6 = *puVar31;
                            uVar7 = puVar31[1];
                            uVar8 = puVar31[2];
                            uVar9 = puVar31[3];
                            puVar31 = puVar31 + 0xc;
                            *(undefined4 *)(pcVar28 + 4) = uVar6;
                            *(undefined4 *)(pcVar28 + 8) = uVar7;
                            *(undefined4 *)(pcVar28 + 0xc) = uVar8;
                            *(undefined4 *)(pcVar28 + 0x10) = uVar9;
                            pcVar29 = pcVar28 + 0x14;
                            uVar42 = uVar42 - 1;
                          } while (uVar42 != 0);
                          uVar42 = (ulonglong)local_2a0;
                          plVar17 = local_298;
                          iVar12 = (uint)local_268;
                        }
                        local_278 = local_278 + (int)plVar17[3];
                        iVar12 = iVar12 + 1;
                        local_268 = (char *)CONCAT44(local_268._4_4_,iVar12);
                        piVar22 = local_270;
                        pcVar28 = local_268;
                      } while (iVar12 < (int)plVar17[0x28]);
                    }
                  }
                }
                else if (sVar2 == 2) {
                  piVar21 = (int *)plVar17[0x1f];
                  uVar37 = plVar17[0x23] + 0xfU & 0xfffffffffffffff0;
                  local_268 = (char *)((ulonglong)
                                       (uint)((int)plVar17[0x2a] * *(int *)(local_258 + 0x18)) +
                                      *(longlong *)(local_258 + 8));
                  if (0 < (int)local_2a0) {
                    do {
                      local_2e0 = (undefined4 *)(uVar37 + 0x2c);
                      local_2d0 = (undefined4 *)(uVar37 + 0x3c);
                      lVar14 = (ulonglong)(uint)(*piVar21 * local_2b8) + local_288;
                      local_2f8 = lVar14 + 0x1c;
                      lVar23 = local_290 + (ulonglong)*(uint *)(lVar14 + 4) * 0x24;
                      local_300 = lVar14 + 0x14;
                      local_2e8 = lVar23 + 0x18;
                      local_2f0 = lVar23 + 0xc;
                      if (local_2b4 == 0) {
                        local_2e8 = 0;
                        local_2f0 = 0;
                      }
                      local_2c8 = uVar37 + 0x10;
                      if ((longlong)local_2a8 < 2) {
                        local_2f8 = 0;
                      }
                      if ((longlong)local_2a8 < 1) {
                        local_300 = 0;
                      }
                      local_308 = lVar14 + 0xc;
                      local_2d8 = uVar37;
                      FUN_140260f50(&local_268,uVar37 + 0x30,lVar23,lVar14 + 8);
                      piVar21 = piVar21 + 1;
                      uVar37 = uVar37 + 0x40;
                      uVar42 = uVar42 - 1;
                    } while (uVar42 != 0);
                    uVar42 = (ulonglong)local_2a0;
                    piVar22 = local_270;
                  }
                  plVar17 = local_298;
                  pcVar28 = local_268;
                  if (piVar22[0x2a] != 0) {
                    iVar12 = (int)local_298[3];
                    local_278 = 1;
                    if (1 < (int)local_298[0x28]) {
                      do {
                        lVar23 = local_290;
                        piVar22 = (int *)plVar17[0x1f];
                        uVar37 = plVar17[0x23] + 0xfU & 0xfffffffffffffff0;
                        if (0 < (int)uVar42) {
                          do {
                            lVar24 = (ulonglong)(uint)(*piVar22 * local_2b8) + local_288;
                            local_2c8 = uVar37 + 0x10;
                            local_2d0 = &local_2b0;
                            local_2e0 = &local_220;
                            cVar40 = (char)iVar12;
                            local_300 = lVar24 + 0x14;
                            lVar14 = (ulonglong)*(uint *)(lVar24 + 4) * 0x24 + lVar23;
                            local_2e8 = lVar14 + 0x18;
                            local_2f0 = lVar14 + 0xc;
                            local_220 = CONCAT13(*(char *)(uVar37 + 0x2f) + cVar40,
                                                 CONCAT12(*(char *)(uVar37 + 0x2e) + cVar40,
                                                          CONCAT11(*(char *)(uVar37 + 0x2d) + cVar40
                                                                   ,*(char *)(uVar37 + 0x2c) +
                                                                    cVar40)));
                            local_2b0 = CONCAT13(*(char *)(uVar37 + 0x3f) + cVar40,
                                                 CONCAT12(*(char *)(uVar37 + 0x3e) + cVar40,
                                                          CONCAT11(*(char *)(uVar37 + 0x3d) + cVar40
                                                                   ,*(char *)(uVar37 + 0x3c) +
                                                                    cVar40)));
                            local_2f8 = lVar24 + 0x1c;
                            if (local_2b4 == 0) {
                              local_2e8 = 0;
                              local_2f0 = 0;
                            }
                            if ((longlong)local_2a8 < 2) {
                              local_2f8 = 0;
                            }
                            if ((longlong)local_2a8 < 1) {
                              local_300 = 0;
                            }
                            local_308 = lVar24 + 0xc;
                            local_2d8 = uVar37;
                            FUN_140260f50(&local_268,uVar37 + 0x30,lVar14,lVar24 + 8);
                            uVar37 = uVar37 + 0x40;
                            piVar22 = piVar22 + 1;
                            uVar42 = uVar42 - 1;
                          } while (uVar42 != 0);
                          uVar42 = (ulonglong)local_2a0;
                          plVar17 = local_298;
                        }
                        iVar12 = iVar12 + (int)plVar17[3];
                        local_278 = local_278 + 1;
                        piVar22 = local_270;
                        pcVar28 = local_268;
                      } while (local_278 < (int)plVar17[0x28]);
                    }
                  }
                }
                else if ((sVar2 == 3) && (piVar22[0x2a] == 0)) {
                  puVar36 = (undefined8 *)(plVar17[0x23] + 0xfU & 0xfffffffffffffff0);
                  puVar27 = (undefined8 *)
                            ((ulonglong)(uint)((int)plVar17[0x2a] * *(int *)(local_258 + 0x18)) +
                            *(longlong *)(local_258 + 8));
                  piVar21 = (int *)plVar17[0x1f];
                  if (0 < (int)local_2a0) {
                    uVar42 = (ulonglong)local_2a0;
                    do {
                      lVar23 = (ulonglong)(uint)(*piVar21 * local_2b8) + local_288;
                      uVar37 = (ulonglong)*(uint *)(lVar23 + 4);
                      puVar31 = (undefined4 *)(lVar23 + 0x14);
                      *puVar27 = *puVar36;
                      puVar25 = (undefined8 *)(local_290 + (uVar37 * 9 + 6) * 4);
                      if (local_2b4 == 0) {
                        puVar25 = (undefined8 *)0x0;
                      }
                      puVar19 = (undefined8 *)(local_290 + uVar37 * 0x24 + 0xc);
                      puVar34 = (undefined4 *)(lVar23 + 0x1c);
                      if (local_2b4 == 0) {
                        puVar19 = (undefined8 *)0x0;
                      }
                      if ((longlong)local_2a8 < 2) {
                        puVar34 = (undefined4 *)0x0;
                      }
                      if ((longlong)local_2a8 < 1) {
                        puVar31 = (undefined4 *)0x0;
                      }
                      *(undefined4 *)(puVar27 + 1) = *(undefined4 *)(puVar36 + 1);
                      *(undefined8 *)((longlong)puVar27 + 0xc) =
                           *(undefined8 *)(local_290 + uVar37 * 0x24);
                      *(undefined4 *)((longlong)puVar27 + 0x14) =
                           *(undefined4 *)(local_290 + 8 + uVar37 * 0x24);
                      *(undefined1 *)((longlong)puVar27 + 0x1a) = *(undefined1 *)(lVar23 + 8);
                      *(undefined1 *)((longlong)puVar27 + 0x19) = *(undefined1 *)(lVar23 + 9);
                      *(undefined1 *)(puVar27 + 3) = *(undefined1 *)(lVar23 + 10);
                      *(undefined1 *)((longlong)puVar27 + 0x1b) = *(undefined1 *)(lVar23 + 0xb);
                      *(undefined1 *)((longlong)puVar27 + 0x1e) = *(undefined1 *)(lVar23 + 0xc);
                      *(undefined1 *)((longlong)puVar27 + 0x1d) = *(undefined1 *)(lVar23 + 0xd);
                      *(undefined1 *)((longlong)puVar27 + 0x1c) = *(undefined1 *)(lVar23 + 0xe);
                      *(undefined1 *)((longlong)puVar27 + 0x1f) = *(undefined1 *)(lVar23 + 0xf);
                      if (puVar31 == (undefined4 *)0x0) {
                        puVar27[4] = 0;
                      }
                      else {
                        *(undefined4 *)(puVar27 + 4) = *puVar31;
                        *(undefined4 *)((longlong)puVar27 + 0x24) = puVar31[1];
                      }
                      *(undefined4 *)(puVar27 + 5) = 0x3f800000;
                      *(undefined4 *)((longlong)puVar27 + 0x2c) = 0x3f800000;
                      if (puVar34 == (undefined4 *)0x0) {
                        if (puVar31 == (undefined4 *)0x0) {
                          puVar27[6] = 0;
                        }
                        else {
                          *(undefined4 *)(puVar27 + 6) = *puVar31;
                          *(undefined4 *)((longlong)puVar27 + 0x34) = puVar31[1];
                        }
                      }
                      else {
                        *(undefined4 *)(puVar27 + 6) = *puVar34;
                        *(undefined4 *)((longlong)puVar27 + 0x34) = puVar34[1];
                      }
                      *(undefined4 *)(puVar27 + 7) = 0x3f800000;
                      *(undefined4 *)((longlong)puVar27 + 0x3c) = 0x3f800000;
                      puVar35 = puVar27 + 8;
                      if (puVar19 != (undefined8 *)0x0) {
                        puVar27[8] = *puVar19;
                        *(undefined4 *)(puVar27 + 9) = *(undefined4 *)(puVar19 + 1);
                        puVar35 = (undefined8 *)((longlong)puVar27 + 0x4c);
                      }
                      puVar27 = puVar35;
                      if (puVar25 != (undefined8 *)0x0) {
                        *puVar27 = *puVar25;
                        *(undefined4 *)(puVar27 + 1) = *(undefined4 *)(puVar25 + 1);
                        puVar27 = (undefined8 *)((longlong)puVar27 + 0xc);
                      }
                      piVar21 = piVar21 + 1;
                      puVar36 = (undefined8 *)
                                ((longlong)puVar36 + (ulonglong)*(ushort *)((longlong)plVar17 + 10))
                      ;
                      uVar42 = uVar42 - 1;
                      piVar22 = local_270;
                    } while (uVar42 != 0);
                  }
                }
                local_268 = pcVar28;
                lVar23 = *(longlong *)(local_258 + 0x10) +
                         (longlong)*(int *)((longlong)plVar17 + 0x154) * 2;
                lVar14 = *(longlong *)(local_258 + 0x10) + (longlong)(int)plVar17[0x2b] * 2;
                FUN_1401ae2f0(lVar23,plVar17[0x25],
                              (ulonglong)*(ushort *)((longlong)plVar17 + 0x124) * 2);
                if (*(ushort *)(plVar17 + 0x26) != 0) {
                  FUN_1401ae2f0(lVar14,plVar17[0x27],(ulonglong)*(ushort *)(plVar17 + 0x26) * 2);
                }
                if (piVar22[0x2a] != 0) {
                  iVar39 = 1;
                  iVar12 = (int)plVar17[2];
                  psVar20 = (short *)(lVar23 + (ulonglong)*(ushort *)((longlong)plVar17 + 0x124) * 2
                                     );
                  psVar26 = (short *)(lVar14 + (ulonglong)*(ushort *)(plVar17 + 0x26) * 2);
                  iVar41 = iVar12;
                  if (1 < (int)plVar17[0x28]) {
                    do {
                      FUN_1401ae2f0(psVar20,plVar17[0x25],
                                    (ulonglong)*(ushort *)((longlong)plVar17 + 0x124) * 2);
                      iVar13 = 0;
                      if (*(short *)((longlong)plVar17 + 0x124) != 0) {
                        do {
                          *psVar20 = *psVar20 + (short)iVar12;
                          iVar13 = iVar13 + 1;
                          psVar20 = psVar20 + 1;
                        } while (iVar13 < (int)(uint)*(ushort *)((longlong)plVar17 + 0x124));
                      }
                      iVar12 = iVar12 + (int)plVar17[2];
                      if (*(ushort *)(plVar17 + 0x26) != 0) {
                        FUN_1401ae2f0(psVar26,plVar17[0x27],
                                      (ulonglong)*(ushort *)(plVar17 + 0x26) * 2);
                        iVar13 = 0;
                        if ((short)plVar17[0x26] != 0) {
                          do {
                            *psVar26 = *psVar26 + (short)iVar41;
                            iVar13 = iVar13 + 1;
                            psVar26 = psVar26 + 1;
                          } while (iVar13 < (int)(uint)*(ushort *)(plVar17 + 0x26));
                        }
                        iVar41 = iVar41 + (int)plVar17[2];
                      }
                      iVar39 = iVar39 + 1;
                    } while (iVar39 < (int)plVar17[0x28]);
                  }
                }
              }
              plVar17 = plVar17 + 0x2c;
              local_260 = local_260 + 1;
            } while (local_260 < piVar22[0x82]);
            piVar21 = piVar22 + 0xce;
            param_3 = local_25c;
          }
          local_2a8 = (longlong *)0x2;
          local_298 = (longlong *)0x3;
          local_288 = 3;
          piVar18 = piVar22 + 0x170;
          local_270 = (int *)0x9;
          while( true ) {
            while( true ) {
              do {
                piVar5 = *(int **)(piVar18 + -0x6c);
                while (piVar10 = piVar5, piVar10 != (int *)0x0) {
                  piVar5 = *(int **)(piVar10 + 10);
                  lVar23 = **(longlong **)(piVar10 + 8);
                  if ((lVar23 == 0) || ((*(longlong **)(piVar10 + 8))[1] == 0)) {
                    if (*(longlong *)(piVar10 + 0xc) == 0) {
                      *(int **)(piVar18 + -0x6c) = piVar5;
                    }
                    else {
                      *(int **)(*(longlong *)(piVar10 + 0xc) + 0x28) = piVar5;
                    }
                    if (*(longlong *)(piVar10 + 10) == 0) {
                      *(undefined8 *)piVar18 = *(undefined8 *)(piVar10 + 0xc);
                    }
                    else {
                      *(undefined8 *)(*(longlong *)(piVar10 + 10) + 0x30) =
                           *(undefined8 *)(piVar10 + 0xc);
                    }
                    if (*(longlong *)(piVar10 + 2) != 0) {
                      FUN_1401b6700();
                      piVar10[2] = 0;
                      piVar10[3] = 0;
                    }
                    if (*(longlong *)(piVar10 + 4) != 0) {
                      FUN_1401b6700();
                      piVar10[4] = 0;
                      piVar10[5] = 0;
                    }
                    if (**(longlong **)(piVar10 + 8) != 0) {
                      FUN_14021f170();
                      **(undefined8 **)(piVar10 + 8) = 0;
                    }
                    if (*(longlong *)(*(longlong *)(piVar10 + 8) + 8) != 0) {
                      FUN_14021f170();
                      *(undefined8 *)(*(longlong *)(piVar10 + 8) + 8) = 0;
                    }
                    iVar12 = 0;
                    if (0 < piVar22[0x82]) {
                      puVar27 = (undefined8 *)(*(longlong *)(piVar22 + 0x84) + 0x148);
                      do {
                        if ((int *)*puVar27 == piVar10) {
                          *puVar27 = 0;
                        }
                        iVar12 = iVar12 + 1;
                        puVar27 = puVar27 + 0x2c;
                      } while (iVar12 < piVar22[0x82]);
                    }
                    FUN_1401b6700(piVar10);
                    *piVar21 = *piVar21 + -1;
                    piVar22[0xcc] = piVar22[0xcc] + -1;
                  }
                  else {
                    local_20c = piVar10[6] * *piVar10;
                    local_2f8._4_4_ = (undefined4)(local_2f8 >> 0x20);
                    local_2f8 = CONCAT44(local_2f8._4_4_,param_3);
                    local_300 = local_300 & 0xffffffff00000000;
                    local_210 = 0;
                    local_308 = local_308 & 0xffffffff00000000;
                    local_218 = 0;
                    local_208 = 1;
                    local_204 = 1;
                    FUN_14021d370(lVar23,0,&local_218,*(undefined8 *)(piVar10 + 2));
                    if (*(longlong *)(*(longlong *)(piVar10 + 8) + 8) != 0) {
                      local_20c = piVar10[1] * 2;
                      local_2f8 = CONCAT44(local_2f8._4_4_,param_3);
                      local_300 = local_300 & 0xffffffff00000000;
                      local_308 = local_308 & 0xffffffff00000000;
                      FUN_14021d370(*(undefined8 *)(*(longlong *)(piVar10 + 8) + 8),0,&local_218,
                                    *(undefined8 *)(piVar10 + 4));
                    }
                  }
                }
                piVar18 = piVar18 + 2;
                piVar21 = piVar21 + 1;
                local_270 = (int *)((longlong)local_270 + -1);
              } while (local_270 != (int *)0x0);
              local_2a8 = (longlong *)((longlong)local_2a8 + -1);
              if (local_2a8 == (longlong *)0x0) break;
              local_270 = (int *)0x9;
            }
            local_288 = local_288 + -1;
            if (local_288 == 0) break;
            local_2a8 = (longlong *)0x2;
            local_270 = (int *)0x9;
          }
          plVar17 = (longlong *)(piVar22 + 0x104);
          local_270 = (int *)0x0;
          local_2a8 = (longlong *)0x0;
          local_288 = 0;
          do {
            lVar23 = 2;
            do {
              lVar14 = 9;
              do {
                uVar6 = local_25c;
                for (lVar24 = *plVar17; local_25c = uVar6, lVar24 != 0;
                    lVar24 = *(longlong *)(lVar24 + 0x28)) {
                  if (*(longlong *)(lVar24 + 8) != 0) {
                    FUN_1401b6700();
                    *(undefined8 *)(lVar24 + 8) = 0;
                  }
                  if (*(longlong *)(lVar24 + 0x10) != 0) {
                    FUN_1401b6700();
                    *(undefined8 *)(lVar24 + 0x10) = 0;
                  }
                  uVar6 = local_25c;
                }
                plVar17 = plVar17 + 1;
                lVar14 = lVar14 + -1;
              } while (lVar14 != 0);
              lVar23 = lVar23 + -1;
            } while (lVar23 != 0);
            local_298 = (longlong *)((longlong)local_298 + -1);
          } while (local_298 != (longlong *)0x0);
          piVar22[0xcd] = 1;
          if ((DAT_14098ac70 != 0) &&
             (uVar42 = (ulonglong)DAT_14098acd0, DAT_14098acd0 <= DAT_14098acd4)) {
            lVar23 = uVar42 * 8;
            local_298 = (longlong *)0x0;
            iVar12 = DAT_14098acd4;
            do {
              lVar14 = *(longlong *)(lVar23 + DAT_14098ac78);
              if (((lVar14 != 0) && (*(int *)(lVar14 + 0x18) == 0)) &&
                 (*(int **)(lVar14 + 0xa0) == piVar22)) {
                FUN_14021b5c0(*(undefined4 *)(lVar14 + 4),uVar6);
                iVar12 = DAT_14098acd4;
              }
              uVar16 = (int)uVar42 + 1;
              uVar42 = (ulonglong)uVar16;
              lVar23 = lVar23 + 8;
            } while ((int)uVar16 <= iVar12);
          }
          return 0;
        }
      } while( true );
    }
  }
  return 0xffffffff;
}


