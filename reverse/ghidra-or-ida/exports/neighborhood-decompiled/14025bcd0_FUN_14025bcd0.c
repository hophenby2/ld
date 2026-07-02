// Function: FUN_14025bcd0 @ 14025bcd0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14025bcd0(uint param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  char cVar13;
  int *piVar14;
  longlong lVar15;
  ulonglong uVar16;
  short *psVar17;
  undefined8 *puVar18;
  short *psVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  int iVar22;
  undefined8 *puVar23;
  longlong *plVar24;
  undefined8 *puVar25;
  int iVar26;
  int *piVar27;
  int *piVar28;
  longlong lVar29;
  undefined1 auStack_278 [32];
  undefined4 *local_258;
  undefined4 local_250;
  int local_248;
  int local_244;
  int *local_240;
  longlong *local_238;
  ulonglong local_230;
  longlong local_228;
  longlong local_220;
  int *local_218;
  undefined4 local_210;
  undefined8 *local_208;
  int *local_200;
  longlong local_1f8 [54];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_278;
  if (((DAT_1407cd880 == 0) || (DAT_1407cd9dc != 0)) ||
     ((DAT_140ca5b88 == 0 && (DAT_140ca5d14 == 0)))) {
    return 0;
  }
  if ((((DAT_14098a8e8 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_14098a938))
     && ((int)(param_1 & 0x3ffff) < DAT_14098a940)) {
    piVar28 = *(int **)(DAT_14098a8f0 + (ulonglong)(param_1 & 0x3ffff) * 8);
    if ((piVar28 != (int *)0x0) && (*piVar28 << 0x12 == (param_1 & 0x3fc0000))) {
      local_218 = piVar28;
      local_210 = param_3;
      if (piVar28[6] != 0) {
        if ((piVar28[6] < 2) && (-1 < piVar28[8])) {
          iVar4 = FUN_1401afbe0();
        }
        else {
          iVar4 = FUN_1401b82b0(param_1);
        }
        if (iVar4 < 0) {
          return 0xffffffff;
        }
        if (*(longlong *)(DAT_14098a8f0 + (ulonglong)(param_1 & 0x3ffff) * 8) == 0) {
          return 0xffffffff;
        }
      }
      if (piVar28[0xcd] != 0) {
        return 0;
      }
      piVar28[0x1dc] = param_2;
      FUN_1401ae370(piVar28 + 0x104,0,0x1b0);
      local_200 = piVar28 + 0x170;
      FUN_1401ae370(local_200,0,0x1b0);
      FUN_1401ae370(piVar28 + 0xce,0,0xd8);
      piVar28[0xcc] = 0;
      FUN_1401ae370(local_1f8,0,0x1b0);
      plVar8 = *(longlong **)(piVar28 + 0x84);
      local_244 = 0;
      if (0 < piVar28[0x82]) {
        do {
          sVar1 = (short)plVar8[1];
          iVar4 = *(int *)(*plVar8 + 100);
          if (iVar4 == 1) {
            iVar4 = 2;
          }
          if (sVar1 == 0) {
            uVar11 = (uint)(piVar28[0x2a] != 0);
LAB_14025bef0:
            iVar26 = (int)plVar8[2];
            iVar22 = (uint)*(ushort *)(plVar8 + 0x26) + (uint)*(ushort *)((longlong)plVar8 + 0x124);
            if (piVar28[0x2a] != 0) {
              iVar26 = iVar26 * (int)plVar8[0x28];
              iVar22 = iVar22 * (int)plVar8[0x28];
            }
            local_238 = (longlong *)(longlong)iVar4;
            local_230 = (ulonglong)(*(int *)(*(longlong *)(*plVar8 + 8) + 0x170) != 0);
            lVar15 = (ulonglong)uVar11 * 2;
            if (local_1f8[(longlong)local_238 + (lVar15 + local_230) * 9] == 0) {
              piVar28[0xcc] = piVar28[0xcc] + 1;
              lVar29 = (longlong)local_238 + (lVar15 + local_230) * 9;
              piVar28[lVar29 + 0xce] = piVar28[lVar29 + 0xce] + 1;
              lVar5 = FUN_1401b6390(0x50,
                                    "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp"
                                    ,0x917);
              local_1f8[lVar29] = lVar5;
              FUN_1401ae370(lVar5,0,0x50);
              *(longlong *)(local_1f8[lVar29] + 0x20) = local_1f8[lVar29] + 0x38;
              *(longlong *)(piVar28 + lVar29 * 2 + 0x104) = local_1f8[lVar29];
              *(longlong *)(piVar28 + lVar29 * 2 + 0x170) = local_1f8[lVar29];
            }
            piVar14 = (int *)local_1f8[(longlong)local_238 + ((local_230 & 0xffffffff) + lVar15) * 9
                                      ];
            if ((0xbffff < piVar14[1] + iVar22) || (0x5ffff < *piVar14 + iVar26)) {
              piVar28[0xcc] = piVar28[0xcc] + 1;
              lVar15 = (longlong)local_238 + ((local_230 & 0xffffffff) + lVar15) * 9;
              piVar28[lVar15 + 0xce] = piVar28[lVar15 + 0xce] + 1;
              uVar6 = FUN_1401b6390(0x50,
                                    "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp"
                                    ,0x925);
              *(undefined8 *)(piVar14 + 10) = uVar6;
              FUN_1401ae370(uVar6,0,0x50);
              *(longlong *)(*(longlong *)(piVar14 + 10) + 0x20) = *(longlong *)(piVar14 + 10) + 0x38
              ;
              *(int **)(*(longlong *)(piVar14 + 10) + 0x30) = piVar14;
              *(undefined8 *)(piVar28 + lVar15 * 2 + 0x170) = *(undefined8 *)(piVar14 + 10);
              piVar14 = *(int **)(piVar14 + 10);
              local_1f8[lVar15] = (longlong)piVar14;
            }
            plVar8[0x29] = (longlong)piVar14;
            *(int *)(plVar8 + 0x2a) = *piVar14;
            iVar4 = piVar14[1];
            *(int *)((longlong)plVar8 + 0x154) = iVar4;
            if (piVar28[0x2a] == 0) {
              *(uint *)(plVar8 + 0x2b) = (uint)*(ushort *)((longlong)plVar8 + 0x124) + iVar4;
            }
            else {
              *(uint *)(plVar8 + 0x2b) =
                   (int)plVar8[0x28] * (uint)*(ushort *)((longlong)plVar8 + 0x124) + iVar4;
            }
            *piVar14 = *piVar14 + iVar26;
            piVar14[1] = piVar14[1] + iVar22;
          }
          else {
            if (sVar1 == 1) {
              uVar11 = 1;
              goto LAB_14025bef0;
            }
            if (sVar1 == 2) {
              uVar11 = 2;
              goto LAB_14025bef0;
            }
          }
          local_244 = local_244 + 1;
          plVar8 = plVar8 + 0x2c;
        } while (local_244 < piVar28[0x82]);
      }
      plVar24 = (longlong *)(piVar28 + 0x104);
      lVar15 = 0xce;
      plVar8 = (longlong *)(piVar28 + 0x170);
      do {
        lVar29 = 2;
        do {
          lVar5 = 0;
          do {
            lVar10 = *plVar8;
            if ((lVar10 != 0) && (*(int *)(lVar10 + 4) == 0)) {
              *plVar8 = *(longlong *)(lVar10 + 0x30);
              if (*(longlong *)(lVar10 + 0x30) != 0) {
                *(undefined8 *)(*(longlong *)(lVar10 + 0x30) + 0x28) = 0;
              }
              FUN_1401b6700();
              piVar28[0xcc] = piVar28[0xcc] + -1;
              piVar28[lVar5 + lVar15] = piVar28[lVar5 + lVar15] + -1;
            }
            iVar4 = 0;
            lVar5 = lVar5 + 1;
            plVar8 = plVar8 + 1;
          } while (lVar5 < 9);
          lVar15 = lVar15 + 9;
          lVar29 = lVar29 + -1;
        } while (lVar29 != 0);
      } while (lVar15 < 0x104);
      lVar15 = (longlong)piVar28 - (longlong)local_1f8;
      local_230 = 0;
      local_220 = lVar15;
      do {
        lVar29 = 0;
        local_248 = 0;
        do {
          local_244 = -1;
          iVar26 = 0x60;
          local_238 = local_1f8 + (local_230 + lVar29) * 9;
          do {
            uVar11 = 0;
            switch(local_244) {
            case 0:
              uVar11 = 0x20100;
              break;
            case 1:
              uVar11 = 0xa0200;
              break;
            case 2:
              uVar11 = 0x2a0300;
              break;
            case 3:
              uVar11 = 0xaa0400;
              break;
            case 4:
              uVar11 = 0x2aa0500;
              break;
            case 5:
              uVar11 = 0xaaa0600;
              break;
            case 6:
              uVar11 = 0x2aaa0700;
              break;
            case 7:
              uVar11 = 0xaaaa0800;
            }
            piVar14 = *(int **)(lVar15 + 0x410 + (longlong)local_238);
            *local_238 = (longlong)piVar14;
            for (; piVar14 != (int *)0x0; piVar14 = *(int **)(piVar14 + 10)) {
              if (iVar4 == 0) {
                if (lVar29 != 0) {
                  if (DAT_1407cd8d4 != 0) {
                    iVar22 = iVar26 + -0x28;
                    goto LAB_14025c2cd;
                  }
                  goto LAB_14025c38a;
                }
                piVar14[6] = iVar26 + -0x20;
                **(uint **)(piVar14 + 8) = uVar11 | 0xd2;
                local_258 = *(undefined4 **)(piVar14 + 8);
                uVar20 = *local_258;
LAB_14025c2e2:
                local_258 = local_258 + 2;
                local_250 = param_3;
                iVar22 = FUN_1402211d0(piVar14[6] * *piVar14,8,uVar20);
                if (iVar22 < 0) {
LAB_14025c679:
                  piVar14 = piVar28 + 0xce;
                  local_238 = (longlong *)0x3;
                  do {
                    lVar15 = 2;
                    do {
                      lVar29 = 9;
                      do {
                        lVar5 = *plVar24;
                        while (lVar5 != 0) {
                          lVar10 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 8);
                          if (lVar10 != 0) {
                            FUN_140222e30(lVar10,param_3);
                            FUN_140220340(*(undefined8 *)(*(longlong *)(lVar5 + 0x20) + 8),param_3);
                          }
                          lVar10 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 0x10);
                          if (lVar10 != 0) {
                            FUN_140222e30(lVar10,param_3);
                            FUN_140220340(*(undefined8 *)(*(longlong *)(lVar5 + 0x20) + 0x10),
                                          param_3);
                          }
                          lVar10 = *(longlong *)(lVar5 + 0x28);
                          FUN_1401b6700(lVar5);
                          lVar5 = lVar10;
                        }
                        *plVar24 = 0;
                        plVar24[0x36] = 0;
                        plVar24 = plVar24 + 1;
                        *piVar14 = 0;
                        piVar14 = piVar14 + 1;
                        lVar29 = lVar29 + -1;
                      } while (lVar29 != 0);
                      lVar15 = lVar15 + -1;
                    } while (lVar15 != 0);
                    local_238 = (longlong *)((longlong)local_238 + -1);
                  } while (local_238 != (longlong *)0x0);
                  piVar28[0xcc] = 0;
                  return 0xffffffff;
                }
                local_258 = (undefined4 *)((ulonglong)local_258 & 0xffffffff00000000);
                local_250 = param_3;
                iVar22 = FUN_140222d60(*(undefined8 *)(*(longlong *)(piVar14 + 8) + 8),0,0);
                if (iVar22 != 0) goto LAB_14025c679;
                local_258 = (undefined4 *)(*(longlong *)(piVar14 + 8) + 0x10);
                local_250 = param_3;
                iVar22 = FUN_140220af0(piVar14[1] * 2,8);
                if (iVar22 < 0) goto LAB_14025c679;
                local_258 = (undefined4 *)((ulonglong)local_258 & 0xffffffff00000000);
                local_250 = param_3;
                iVar22 = FUN_140222d60(*(undefined8 *)(*(longlong *)(piVar14 + 8) + 0x10),0);
                if (iVar22 != 0) goto LAB_14025c679;
              }
              else if (iVar4 == 1) {
                if (lVar29 == 0) {
                  if (DAT_1407cd8d4 != 0) {
                    iVar22 = iVar26 + -0x2c;
LAB_14025c2cd:
                    piVar14[6] = iVar22;
LAB_14025c2d0:
                    **(undefined4 **)(piVar14 + 8) = 0;
                    local_258 = *(undefined4 **)(piVar14 + 8);
                    uVar20 = 0;
                    goto LAB_14025c2e2;
                  }
                }
                else if (DAT_1407cd8d4 != 0) {
                  iVar22 = iVar26 + -0x14;
                  goto LAB_14025c2cd;
                }
              }
              else if (iVar4 == 2) {
                if (lVar29 == 0) {
                  if (DAT_1407cd8d4 != 0) {
                    iVar22 = iVar26 + -0x18;
                    goto LAB_14025c2cd;
                  }
                }
                else if (DAT_1407cd8d4 != 0) {
                  piVar14[6] = iVar26;
                  goto LAB_14025c2d0;
                }
              }
LAB_14025c38a:
              lVar15 = local_220;
            }
            local_244 = local_244 + 1;
            local_238 = local_238 + 1;
            iVar26 = iVar26 + 0x10;
          } while (iVar26 < 0xf0);
          lVar29 = lVar29 + 1;
          local_248 = local_248 + 1;
        } while (local_248 < 2);
        local_230 = local_230 + 2;
        iVar4 = iVar4 + 1;
        if (2 < iVar4) {
          plVar8 = *(longlong **)(piVar28 + 0x84);
          local_238 = (longlong *)0x3;
          local_244 = 0;
          if (0 < piVar28[0x82]) {
            do {
              local_230 = plVar8[0x29];
              if (((local_230 != 0) && (*(longlong *)(*(longlong *)(local_230 + 0x20) + 8) != 0)) &&
                 (*(longlong *)(*(longlong *)(local_230 + 0x20) + 0x10) != 0)) {
                plVar24 = (longlong *)*plVar8;
                local_240 = (int *)plVar8[0x1f];
                uVar11 = *(uint *)(plVar8 + 2);
                uVar12 = (ulonglong)uVar11;
                local_220 = plVar24[0xf];
                local_248 = *(int *)((longlong)plVar24 + 0x74);
                iVar4 = *(int *)(plVar24[1] + 0x170);
                iVar26 = *(int *)((longlong)plVar24 + 100);
                if (*(int *)((longlong)plVar24 + 100) == 1) {
                  iVar26 = 2;
                }
                lVar15 = (longlong)iVar26;
                sVar1 = (short)plVar8[1];
                local_228 = *(longlong *)(*plVar24 + 0x210);
                if (sVar1 == 0) {
                  if (piVar28[0x2a] == 0) {
                    puVar18 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    if (iVar4 == 0) {
                      puVar23 = (undefined8 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                      if (0 < (int)uVar11) {
                        do {
                          lVar29 = 0;
                          lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                          uVar11 = *(uint *)(lVar5 + 4);
                          *puVar18 = *puVar23;
                          *(undefined4 *)(puVar18 + 1) = *(undefined4 *)(puVar23 + 1);
                          *(undefined8 *)((longlong)puVar18 + 0xc) =
                               *(undefined8 *)(local_228 + (ulonglong)uVar11 * 0x24);
                          *(undefined4 *)((longlong)puVar18 + 0x14) =
                               *(undefined4 *)(local_228 + 8 + (ulonglong)uVar11 * 0x24);
                          *(undefined4 *)(puVar18 + 3) = *(undefined4 *)(lVar5 + 8);
                          *(undefined4 *)((longlong)puVar18 + 0x1c) = *(undefined4 *)(lVar5 + 0xc);
                          if (3 < lVar15) {
                            lVar10 = lVar29;
                            do {
                              if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x34) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + (lVar10 + 2) * 2) =
                                     *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x24) =
                                     *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                              }
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 5) = 0x3f800000;
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x2c) = 0x3f800000
                              ;
                              if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x34) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + (lVar10 + 3) * 2) =
                                     *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x34) =
                                     *(undefined4 *)(lVar5 + 0x20 + lVar10 * 8);
                              }
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 7) = 0x3f800000;
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x3c) = 0x3f800000
                              ;
                              if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x34) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + (lVar10 + 4) * 2) =
                                     *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x44) =
                                     *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                              }
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 9) = 0x3f800000;
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) = 0x3f800000
                              ;
                              if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x34) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) =
                                     *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) =
                                     *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                              }
                              lVar29 = lVar10 + 4;
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) = 0x3f800000;
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) = 0x3f800000
                              ;
                              lVar10 = lVar29;
                            } while (lVar29 < lVar15 + -3);
                          }
                          for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                            if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x34) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + (lVar29 + 2) * 2) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x24) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                            }
                            *(undefined4 *)(puVar18 + lVar29 * 2 + 5) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x2c) = 0x3f800000;
                          }
                          puVar23 = puVar23 + 4;
                          local_240 = local_240 + 1;
                          puVar18 = (undefined8 *)
                                    ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                          uVar12 = uVar12 - 1;
                        } while (uVar12 != 0);
                      }
                    }
                    else {
                      puVar23 = (undefined8 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                      if (0 < (int)uVar11) {
                        do {
                          lVar29 = 0;
                          lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                          uVar16 = (ulonglong)*(uint *)(lVar5 + 4);
                          *puVar18 = *puVar23;
                          *(undefined4 *)(puVar18 + 1) = *(undefined4 *)(puVar23 + 1);
                          *(undefined8 *)((longlong)puVar18 + 0x24) =
                               *(undefined8 *)(local_228 + uVar16 * 0x24);
                          *(undefined4 *)((longlong)puVar18 + 0x2c) =
                               *(undefined4 *)(local_228 + 8 + uVar16 * 0x24);
                          puVar18[3] = *(undefined8 *)(local_228 + 0x18 + uVar16 * 0x24);
                          *(undefined4 *)(puVar18 + 4) =
                               *(undefined4 *)(local_228 + 0x20 + uVar16 * 0x24);
                          *(undefined8 *)((longlong)puVar18 + 0xc) =
                               *(undefined8 *)(local_228 + 0xc + uVar16 * 0x24);
                          *(undefined4 *)((longlong)puVar18 + 0x14) =
                               *(undefined4 *)(local_228 + 0x14 + uVar16 * 0x24);
                          *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 8);
                          *(undefined4 *)((longlong)puVar18 + 0x34) = *(undefined4 *)(lVar5 + 0xc);
                          if (3 < lVar15) {
                            lVar10 = lVar29;
                            do {
                              if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x4c) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + lVar10 * 2 + 7) =
                                     *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x3c) =
                                     *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                              }
                              lVar29 = lVar10 + 4;
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x44) = 0x3f800000
                              ;
                              *(undefined4 *)(puVar18 + lVar29 * 2) = 0x3f800000;
                              if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x4c) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + lVar10 * 2 + 9) =
                                     *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) =
                                     *(undefined4 *)(lVar5 + lVar29 * 8);
                              }
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) = 0x3f800000
                              ;
                              *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) = 0x3f800000;
                              if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x4c) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) =
                                     *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) =
                                     *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                              }
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) = 0x3f800000;
                              *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) = 0x3f800000;
                              if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                                *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x14);
                                *(undefined4 *)((longlong)puVar18 + 0x4c) =
                                     *(undefined4 *)(lVar5 + 0x18);
                              }
                              else {
                                *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) =
                                     *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                                *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) =
                                     *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                              }
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x74) = 0x3f800000
                              ;
                              *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) = 0x3f800000;
                              lVar10 = lVar29;
                            } while (lVar29 < lVar15 + -3);
                          }
                          for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                            if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x4c) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + lVar29 * 2 + 7) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x3c) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                            }
                            *(undefined4 *)(puVar18 + (lVar29 + 4) * 2) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x44) = 0x3f800000;
                          }
                          puVar23 = puVar23 + 4;
                          local_240 = local_240 + 1;
                          puVar18 = (undefined8 *)
                                    ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                          uVar12 = uVar12 - 1;
                        } while (uVar12 != 0);
                      }
                    }
                  }
                  else if (iVar4 == 0) {
                    puVar23 = (undefined8 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                    puVar25 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    puVar18 = puVar25;
                    uVar16 = uVar12;
                    if (0 < (int)uVar11) {
                      do {
                        lVar29 = 0;
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar2 = *(uint *)(lVar5 + 4);
                        *puVar18 = *puVar23;
                        *(undefined4 *)(puVar18 + 1) = *(undefined4 *)(puVar23 + 1);
                        *(undefined4 *)((longlong)puVar18 + 0xc) = 0;
                        puVar18[2] = 0x3f800000;
                        puVar18[3] = 0;
                        puVar18[4] = *(undefined8 *)(local_228 + (ulonglong)uVar2 * 0x24);
                        *(undefined4 *)(puVar18 + 5) =
                             *(undefined4 *)(local_228 + 8 + (ulonglong)uVar2 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x2c) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0xc);
                        if (3 < lVar15) {
                          lVar10 = lVar29;
                          do {
                            if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x34) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 7) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                            }
                            lVar29 = lVar10 + 4;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x3c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar29 * 2) = 0x3f800000;
                            if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 9) =
                                   *(undefined4 *)(lVar5 + lVar29 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) = 0x3f800000;
                            if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) = 0x3f800000;
                            if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) = 0x3f800000;
                            lVar10 = lVar29;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)((longlong)puVar18 + 0x44) =
                                 *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x34) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)(puVar18 + lVar29 * 2 + 7) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x3c) = 0x3f800000;
                          *(undefined4 *)(puVar18 + (lVar29 + 4) * 2) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar23 = puVar23 + 4;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    iVar4 = 1;
                    cVar13 = '\x03';
                    if (1 < (int)plVar8[0x28]) {
                      do {
                        FUN_1401ae2f0(puVar18,puVar25,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                        uVar16 = uVar12;
                        if (0 < (int)uVar11) {
                          do {
                            *(char *)((longlong)puVar18 + 0xc) = cVar13;
                            puVar18 = (undefined8 *)
                                      ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18)
                                      );
                            uVar16 = uVar16 - 1;
                          } while (uVar16 != 0);
                        }
                        iVar4 = iVar4 + 1;
                        cVar13 = cVar13 + '\x03';
                      } while (iVar4 < (int)plVar8[0x28]);
                    }
                  }
                  else {
                    puVar23 = (undefined8 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                    puVar25 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    uVar16 = uVar12;
                    puVar18 = puVar25;
                    if (0 < (int)uVar11) {
                      do {
                        lVar29 = 0;
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar7 = (ulonglong)*(uint *)(lVar5 + 4);
                        *puVar18 = *puVar23;
                        *(undefined4 *)(puVar18 + 1) = *(undefined4 *)(puVar23 + 1);
                        *(undefined4 *)((longlong)puVar18 + 0xc) = 0;
                        puVar18[2] = 0x3f800000;
                        puVar18[3] = 0;
                        puVar18[7] = *(undefined8 *)(local_228 + uVar7 * 0x24);
                        *(undefined4 *)(puVar18 + 8) = *(undefined4 *)(local_228 + 8 + uVar7 * 0x24)
                        ;
                        *(undefined8 *)((longlong)puVar18 + 0x2c) =
                             *(undefined8 *)(local_228 + 0x18 + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x34) =
                             *(undefined4 *)(local_228 + 0x20 + uVar7 * 0x24);
                        puVar18[4] = *(undefined8 *)(local_228 + 0xc + uVar7 * 0x24);
                        *(undefined4 *)(puVar18 + 5) =
                             *(undefined4 *)(local_228 + 0x14 + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x44) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0xc);
                        if (3 < lVar15) {
                          lVar10 = lVar29;
                          do {
                            if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) = 0x3f800000;
                            if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) =
                                   *(undefined4 *)(lVar5 + 0x20 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) = 0x3f800000;
                            if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x74) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xf) = 0x3f800000;
                            if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x7c) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 8) * 2) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                            }
                            lVar29 = lVar10 + 4;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x84) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0x11) = 0x3f800000;
                            lVar10 = lVar29;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                 *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x4c) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)(puVar18 + (lVar29 + 5) * 2) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x54) = 0x3f800000;
                          *(undefined4 *)(puVar18 + lVar29 * 2 + 0xb) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar23 = puVar23 + 4;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    iVar4 = 1;
                    cVar13 = '\x03';
                    if (1 < (int)plVar8[0x28]) {
                      do {
                        FUN_1401ae2f0(puVar18,puVar25,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                        uVar16 = uVar12;
                        if (0 < (int)uVar11) {
                          do {
                            *(char *)((longlong)puVar18 + 0xc) = cVar13;
                            puVar18 = (undefined8 *)
                                      ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18)
                                      );
                            uVar16 = uVar16 - 1;
                          } while (uVar16 != 0);
                        }
                        iVar4 = iVar4 + 1;
                        cVar13 = cVar13 + '\x03';
                      } while (iVar4 < (int)plVar8[0x28]);
                    }
                  }
                }
                else if (sVar1 == 1) {
                  if (iVar4 == 0) {
                    puVar21 = (undefined4 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                    puVar23 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    puVar18 = puVar23;
                    uVar16 = uVar12;
                    if (0 < (int)uVar11) {
                      do {
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar2 = *(uint *)(lVar5 + 4);
                        *puVar18 = *(undefined8 *)(puVar21 + 4);
                        *(undefined4 *)(puVar18 + 1) = puVar21[6];
                        *(char *)((longlong)puVar18 + 0xc) = *(char *)(puVar21 + 0xb) * '\x03';
                        *(char *)((longlong)puVar18 + 0xd) =
                             *(char *)((longlong)puVar21 + 0x2d) * '\x03';
                        *(char *)((longlong)puVar18 + 0xe) =
                             *(char *)((longlong)puVar21 + 0x2e) * '\x03';
                        *(char *)((longlong)puVar18 + 0xf) =
                             *(char *)((longlong)puVar21 + 0x2f) * '\x03';
                        *(undefined4 *)(puVar18 + 2) = *puVar21;
                        *(undefined4 *)((longlong)puVar18 + 0x14) = puVar21[1];
                        *(undefined4 *)(puVar18 + 3) = puVar21[2];
                        *(undefined4 *)((longlong)puVar18 + 0x1c) = puVar21[3];
                        puVar18[4] = *(undefined8 *)(local_228 + (ulonglong)uVar2 * 0x24);
                        lVar29 = 0;
                        *(undefined4 *)(puVar18 + 5) =
                             *(undefined4 *)(local_228 + 8 + (ulonglong)uVar2 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x2c) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(lVar5 + 0xc);
                        if (3 < lVar15) {
                          lVar10 = lVar29;
                          do {
                            if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x34) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 7) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                            }
                            lVar29 = lVar10 + 4;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x3c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar29 * 2) = 0x3f800000;
                            if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 9) =
                                   *(undefined4 *)(lVar5 + lVar29 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) = 0x3f800000;
                            if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) = 0x3f800000;
                            if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x44) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) = 0x3f800000;
                            lVar10 = lVar29;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)((longlong)puVar18 + 0x44) =
                                 *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x34) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)(puVar18 + lVar29 * 2 + 7) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x3c) = 0x3f800000;
                          *(undefined4 *)(puVar18 + (lVar29 + 4) * 2) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar21 = puVar21 + 0xc;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    local_208 = puVar23;
                    if (piVar28[0x2a] != 0) {
                      iVar26 = 1;
                      iVar4 = (int)plVar8[3] * 3;
                      if (1 < (int)plVar8[0x28]) {
                        do {
                          FUN_1401ae2f0(puVar18,puVar23,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                          uVar16 = uVar12;
                          if (0 < (int)uVar11) {
                            do {
                              cVar13 = (char)iVar4;
                              *(char *)((longlong)puVar18 + 0xc) =
                                   *(char *)((longlong)puVar18 + 0xc) + cVar13;
                              *(char *)((longlong)puVar18 + 0xd) =
                                   *(char *)((longlong)puVar18 + 0xd) + cVar13;
                              *(char *)((longlong)puVar18 + 0xe) =
                                   *(char *)((longlong)puVar18 + 0xe) + cVar13;
                              *(char *)((longlong)puVar18 + 0xf) =
                                   *(char *)((longlong)puVar18 + 0xf) + cVar13;
                              puVar18 = (undefined8 *)
                                        ((longlong)puVar18 +
                                        (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                              uVar16 = uVar16 - 1;
                            } while (uVar16 != 0);
                          }
                          iVar26 = iVar26 + 1;
                          iVar4 = (int)plVar8[3] * 3 + iVar4;
                        } while (iVar26 < (int)plVar8[0x28]);
                      }
                    }
                  }
                  else {
                    puVar21 = (undefined4 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                    puVar23 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    uVar16 = uVar12;
                    puVar18 = puVar23;
                    if (0 < (int)uVar11) {
                      do {
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar7 = (ulonglong)*(uint *)(lVar5 + 4);
                        *puVar18 = *(undefined8 *)(puVar21 + 4);
                        *(undefined4 *)(puVar18 + 1) = puVar21[6];
                        *(char *)((longlong)puVar18 + 0xc) = *(char *)(puVar21 + 0xb) * '\x03';
                        *(char *)((longlong)puVar18 + 0xd) =
                             *(char *)((longlong)puVar21 + 0x2d) * '\x03';
                        *(char *)((longlong)puVar18 + 0xe) =
                             *(char *)((longlong)puVar21 + 0x2e) * '\x03';
                        *(char *)((longlong)puVar18 + 0xf) =
                             *(char *)((longlong)puVar21 + 0x2f) * '\x03';
                        *(undefined4 *)(puVar18 + 2) = *puVar21;
                        *(undefined4 *)((longlong)puVar18 + 0x14) = puVar21[1];
                        *(undefined4 *)(puVar18 + 3) = puVar21[2];
                        *(undefined4 *)((longlong)puVar18 + 0x1c) = puVar21[3];
                        puVar18[7] = *(undefined8 *)(local_228 + uVar7 * 0x24);
                        *(undefined4 *)(puVar18 + 8) = *(undefined4 *)(local_228 + 8 + uVar7 * 0x24)
                        ;
                        *(undefined8 *)((longlong)puVar18 + 0x2c) =
                             *(undefined8 *)(local_228 + 0x18 + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x34) =
                             *(undefined4 *)(local_228 + 0x20 + uVar7 * 0x24);
                        puVar18[4] = *(undefined8 *)(local_228 + 0xc + uVar7 * 0x24);
                        lVar29 = 0;
                        *(undefined4 *)(puVar18 + 5) =
                             *(undefined4 *)(local_228 + 0x14 + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x44) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(lVar5 + 0xc);
                        if (3 < lVar15) {
                          lVar10 = lVar29;
                          do {
                            if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x4c) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 5) * 2) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x54) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xb) = 0x3f800000;
                            if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) =
                                   *(undefined4 *)(lVar5 + 0x20 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) = 0x3f800000;
                            if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x74) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xf) = 0x3f800000;
                            if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x7c) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                              *(undefined4 *)(puVar18 + (lVar10 + 8) * 2) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                            }
                            lVar29 = lVar10 + 4;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x84) = 0x3f800000;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0x11) = 0x3f800000;
                            lVar10 = lVar29;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                 *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)(puVar18 + 0xc) = *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x4c) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)(puVar18 + (lVar29 + 5) * 2) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x54) = 0x3f800000;
                          *(undefined4 *)(puVar18 + lVar29 * 2 + 0xb) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar21 = puVar21 + 0xc;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    if (piVar28[0x2a] != 0) {
                      iVar26 = 1;
                      iVar4 = (int)plVar8[3] * 3;
                      if (1 < (int)plVar8[0x28]) {
                        do {
                          FUN_1401ae2f0(puVar18,puVar23,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                          uVar16 = uVar12;
                          if (0 < (int)uVar11) {
                            do {
                              cVar13 = (char)iVar4;
                              *(char *)((longlong)puVar18 + 0xc) =
                                   *(char *)((longlong)puVar18 + 0xc) + cVar13;
                              *(char *)((longlong)puVar18 + 0xd) =
                                   *(char *)((longlong)puVar18 + 0xd) + cVar13;
                              *(char *)((longlong)puVar18 + 0xe) =
                                   *(char *)((longlong)puVar18 + 0xe) + cVar13;
                              *(char *)((longlong)puVar18 + 0xf) =
                                   *(char *)((longlong)puVar18 + 0xf) + cVar13;
                              puVar18 = (undefined8 *)
                                        ((longlong)puVar18 +
                                        (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                              uVar16 = uVar16 - 1;
                            } while (uVar16 != 0);
                          }
                          iVar26 = iVar26 + 1;
                          iVar4 = (int)plVar8[3] * 3 + iVar4;
                        } while (iVar26 < (int)plVar8[0x28]);
                      }
                    }
                  }
                }
                else if (sVar1 == 2) {
                  puVar21 = (undefined4 *)(plVar8[0x23] + 0xfU & 0xfffffffffffffff0);
                  if (iVar4 == 0) {
                    puVar23 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    puVar18 = puVar23;
                    uVar16 = uVar12;
                    if (0 < (int)uVar11) {
                      do {
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar2 = *(uint *)(lVar5 + 4);
                        *puVar18 = *(undefined8 *)(puVar21 + 0xc);
                        *(undefined4 *)(puVar18 + 1) = puVar21[0xe];
                        *(char *)((longlong)puVar18 + 0xc) = *(char *)(puVar21 + 0xb) * '\x03';
                        *(char *)((longlong)puVar18 + 0xd) =
                             *(char *)((longlong)puVar21 + 0x2d) * '\x03';
                        *(char *)((longlong)puVar18 + 0xe) =
                             *(char *)((longlong)puVar21 + 0x2e) * '\x03';
                        *(char *)((longlong)puVar18 + 0xf) =
                             *(char *)((longlong)puVar21 + 0x2f) * '\x03';
                        *(char *)(puVar18 + 2) = *(char *)(puVar21 + 0xf) * '\x03';
                        *(char *)((longlong)puVar18 + 0x11) =
                             *(char *)((longlong)puVar21 + 0x3d) * '\x03';
                        *(char *)((longlong)puVar18 + 0x12) =
                             *(char *)((longlong)puVar21 + 0x3e) * '\x03';
                        *(char *)((longlong)puVar18 + 0x13) =
                             *(char *)((longlong)puVar21 + 0x3f) * '\x03';
                        *(undefined4 *)((longlong)puVar18 + 0x14) = *puVar21;
                        *(undefined4 *)(puVar18 + 3) = puVar21[1];
                        *(undefined4 *)((longlong)puVar18 + 0x1c) = puVar21[2];
                        *(undefined4 *)(puVar18 + 4) = puVar21[3];
                        *(undefined4 *)((longlong)puVar18 + 0x24) = puVar21[4];
                        *(undefined4 *)(puVar18 + 5) = puVar21[5];
                        *(undefined4 *)((longlong)puVar18 + 0x2c) = puVar21[6];
                        *(undefined4 *)(puVar18 + 6) = puVar21[7];
                        *(undefined8 *)((longlong)puVar18 + 0x34) =
                             *(undefined8 *)(local_228 + (ulonglong)uVar2 * 0x24);
                        lVar29 = 0;
                        *(undefined4 *)((longlong)puVar18 + 0x3c) =
                             *(undefined4 *)(local_228 + 8 + (ulonglong)uVar2 * 0x24);
                        *(undefined4 *)(puVar18 + 8) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)((longlong)puVar18 + 0x44) = *(undefined4 *)(lVar5 + 0xc);
                        if (3 < lVar15) {
                          do {
                            if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + lVar29 * 2 + 9) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x4c) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                            }
                            *(undefined4 *)(puVar18 + (lVar29 + 5) * 2) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x54) = 0x3f800000;
                            if ((lVar29 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + lVar29 * 2 + 0xb) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x20 + lVar29 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 100) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar29 + 6) * 2) = 0x3f800000;
                            if ((lVar29 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + lVar29 * 2 + 0xd) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x6c) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar29 * 8);
                            }
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x74) = 0x3f800000;
                            *(undefined4 *)(puVar18 + (lVar29 + 7) * 2) = 0x3f800000;
                            if ((lVar29 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + lVar29 * 2 + 0xf) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar29 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x7c) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar29 * 8);
                            }
                            lVar10 = lVar29 + 8;
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x84) = 0x3f800000;
                            lVar29 = lVar29 + 4;
                            *(undefined4 *)(puVar18 + lVar10 * 2) = 0x3f800000;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)((longlong)puVar18 + 0x5c) =
                                 *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)(puVar18 + lVar29 * 2 + 9) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x4c) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)(puVar18 + (lVar29 + 5) * 2) = 0x3f800000;
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x54) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar21 = puVar21 + 0x10;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    local_208 = puVar23;
                    if (piVar28[0x2a] != 0) {
                      iVar26 = 1;
                      iVar4 = (int)plVar8[3] * 3;
                      if (1 < (int)plVar8[0x28]) {
                        do {
                          FUN_1401ae2f0(puVar18,puVar23,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                          uVar16 = uVar12;
                          if (0 < (int)uVar11) {
                            do {
                              cVar13 = (char)iVar4;
                              *(char *)((longlong)puVar18 + 0xc) =
                                   *(char *)((longlong)puVar18 + 0xc) + cVar13;
                              *(char *)((longlong)puVar18 + 0xd) =
                                   *(char *)((longlong)puVar18 + 0xd) + cVar13;
                              *(char *)((longlong)puVar18 + 0xe) =
                                   *(char *)((longlong)puVar18 + 0xe) + cVar13;
                              *(char *)((longlong)puVar18 + 0xf) =
                                   *(char *)((longlong)puVar18 + 0xf) + cVar13;
                              *(char *)(puVar18 + 2) = *(char *)(puVar18 + 2) + cVar13;
                              *(char *)((longlong)puVar18 + 0x11) =
                                   *(char *)((longlong)puVar18 + 0x11) + cVar13;
                              *(char *)((longlong)puVar18 + 0x12) =
                                   *(char *)((longlong)puVar18 + 0x12) + cVar13;
                              *(char *)((longlong)puVar18 + 0x13) =
                                   *(char *)((longlong)puVar18 + 0x13) + cVar13;
                              puVar18 = (undefined8 *)
                                        ((longlong)puVar18 +
                                        (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                              uVar16 = uVar16 - 1;
                            } while (uVar16 != 0);
                          }
                          iVar26 = iVar26 + 1;
                          iVar4 = (int)plVar8[3] * 3 + iVar4;
                        } while (iVar26 < (int)plVar8[0x28]);
                      }
                    }
                  }
                  else {
                    puVar23 = (undefined8 *)
                              ((ulonglong)(uint)(*(int *)(local_230 + 0x18) * (int)plVar8[0x2a]) +
                              *(longlong *)(local_230 + 8));
                    puVar18 = puVar23;
                    if (0 < (int)uVar11) {
                      uVar16 = (ulonglong)uVar11;
                      do {
                        lVar5 = (ulonglong)(uint)(*local_240 * local_248) + local_220;
                        uVar7 = (ulonglong)*(uint *)(lVar5 + 4);
                        *puVar18 = *(undefined8 *)(puVar21 + 0xc);
                        *(undefined4 *)(puVar18 + 1) = puVar21[0xe];
                        *(char *)((longlong)puVar18 + 0xc) = *(char *)(puVar21 + 0xb) * '\x03';
                        *(char *)((longlong)puVar18 + 0xd) =
                             *(char *)((longlong)puVar21 + 0x2d) * '\x03';
                        *(char *)((longlong)puVar18 + 0xe) =
                             *(char *)((longlong)puVar21 + 0x2e) * '\x03';
                        *(char *)((longlong)puVar18 + 0xf) =
                             *(char *)((longlong)puVar21 + 0x2f) * '\x03';
                        *(char *)(puVar18 + 2) = *(char *)(puVar21 + 0xf) * '\x03';
                        *(char *)((longlong)puVar18 + 0x11) =
                             *(char *)((longlong)puVar21 + 0x3d) * '\x03';
                        *(char *)((longlong)puVar18 + 0x12) =
                             *(char *)((longlong)puVar21 + 0x3e) * '\x03';
                        *(char *)((longlong)puVar18 + 0x13) =
                             *(char *)((longlong)puVar21 + 0x3f) * '\x03';
                        *(undefined4 *)((longlong)puVar18 + 0x14) = *puVar21;
                        *(undefined4 *)(puVar18 + 3) = puVar21[1];
                        *(undefined4 *)((longlong)puVar18 + 0x1c) = puVar21[2];
                        *(undefined4 *)(puVar18 + 4) = puVar21[3];
                        *(undefined4 *)((longlong)puVar18 + 0x24) = puVar21[4];
                        *(undefined4 *)(puVar18 + 5) = puVar21[5];
                        *(undefined4 *)((longlong)puVar18 + 0x2c) = puVar21[6];
                        *(undefined4 *)(puVar18 + 6) = puVar21[7];
                        *(undefined8 *)((longlong)puVar18 + 0x4c) =
                             *(undefined8 *)(local_228 + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x54) =
                             *(undefined4 *)(local_228 + 8 + uVar7 * 0x24);
                        puVar18[8] = *(undefined8 *)(local_228 + 0x18 + uVar7 * 0x24);
                        *(undefined4 *)(puVar18 + 9) =
                             *(undefined4 *)(local_228 + 0x20 + uVar7 * 0x24);
                        *(undefined8 *)((longlong)puVar18 + 0x34) =
                             *(undefined8 *)(local_228 + 0xc + uVar7 * 0x24);
                        *(undefined4 *)((longlong)puVar18 + 0x3c) =
                             *(undefined4 *)(local_228 + 0x14 + uVar7 * 0x24);
                        *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(lVar5 + 8);
                        *(undefined4 *)((longlong)puVar18 + 0x5c) = *(undefined4 *)(lVar5 + 0xc);
                        lVar29 = 0;
                        if (3 < lVar15) {
                          lVar10 = lVar29;
                          do {
                            if ((lVar10 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xe) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x74) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + (lVar10 + 6) * 2) =
                                   *(undefined4 *)(lVar5 + 0x14 + lVar10 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 100) =
                                   *(undefined4 *)(lVar5 + 0x18 + lVar10 * 8);
                            }
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xd) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x6c) = 0x3f800000;
                            if ((lVar10 == 0) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xe) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x74) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + (lVar10 + 7) * 2) =
                                   *(undefined4 *)(lVar5 + 0x1c + lVar10 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x74) =
                                   *(undefined4 *)(lVar5 + 0x20 + lVar10 * 8);
                            }
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0xf) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x7c) = 0x3f800000;
                            if ((lVar10 == -1) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xe) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x74) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + (lVar10 + 8) * 2) =
                                   *(undefined4 *)(lVar5 + 0x24 + lVar10 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x84) =
                                   *(undefined4 *)(lVar5 + 0x28 + lVar10 * 8);
                            }
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0x11) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x8c) = 0x3f800000;
                            if ((lVar10 == -2) && (*(int *)(*plVar8 + 100) == 1)) {
                              *(undefined4 *)(puVar18 + 0xe) = *(undefined4 *)(lVar5 + 0x14);
                              *(undefined4 *)((longlong)puVar18 + 0x74) =
                                   *(undefined4 *)(lVar5 + 0x18);
                            }
                            else {
                              *(undefined4 *)(puVar18 + (lVar10 + 9) * 2) =
                                   *(undefined4 *)(lVar5 + 0x2c + lVar10 * 8);
                              *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x94) =
                                   *(undefined4 *)(lVar5 + 0x30 + lVar10 * 8);
                            }
                            lVar29 = lVar10 + 4;
                            *(undefined4 *)(puVar18 + lVar10 * 2 + 0x13) = 0x3f800000;
                            *(undefined4 *)((longlong)puVar18 + lVar10 * 0x10 + 0x9c) = 0x3f800000;
                            lVar10 = lVar29;
                          } while (lVar29 < lVar15 + -3);
                        }
                        for (; lVar29 < lVar15; lVar29 = lVar29 + 1) {
                          if ((lVar29 == 1) && (*(int *)(*plVar8 + 100) == 1)) {
                            *(undefined4 *)(puVar18 + 0xe) = *(undefined4 *)(lVar5 + 0x14);
                            *(undefined4 *)((longlong)puVar18 + 0x74) =
                                 *(undefined4 *)(lVar5 + 0x18);
                          }
                          else {
                            *(undefined4 *)(puVar18 + (lVar29 + 6) * 2) =
                                 *(undefined4 *)(lVar5 + 0x14 + lVar29 * 8);
                            *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 100) =
                                 *(undefined4 *)(lVar5 + 0x18 + lVar29 * 8);
                          }
                          *(undefined4 *)(puVar18 + lVar29 * 2 + 0xd) = 0x3f800000;
                          *(undefined4 *)((longlong)puVar18 + lVar29 * 0x10 + 0x6c) = 0x3f800000;
                        }
                        local_240 = local_240 + 1;
                        puVar21 = puVar21 + 0x10;
                        puVar18 = (undefined8 *)
                                  ((longlong)puVar18 + (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                        uVar16 = uVar16 - 1;
                        piVar28 = local_218;
                      } while (uVar16 != 0);
                    }
                    if (piVar28[0x2a] != 0) {
                      iVar26 = 1;
                      iVar4 = (int)plVar8[3] * 3;
                      if (1 < (int)plVar8[0x28]) {
                        do {
                          FUN_1401ae2f0(puVar18,puVar23,*(int *)(plVar8[0x29] + 0x18) * uVar11);
                          uVar16 = uVar12;
                          if (0 < (int)uVar11) {
                            do {
                              cVar13 = (char)iVar4;
                              *(char *)((longlong)puVar18 + 0xc) =
                                   *(char *)((longlong)puVar18 + 0xc) + cVar13;
                              *(char *)((longlong)puVar18 + 0xd) =
                                   *(char *)((longlong)puVar18 + 0xd) + cVar13;
                              *(char *)((longlong)puVar18 + 0xe) =
                                   *(char *)((longlong)puVar18 + 0xe) + cVar13;
                              *(char *)((longlong)puVar18 + 0xf) =
                                   *(char *)((longlong)puVar18 + 0xf) + cVar13;
                              *(char *)(puVar18 + 2) = *(char *)(puVar18 + 2) + cVar13;
                              *(char *)((longlong)puVar18 + 0x11) =
                                   *(char *)((longlong)puVar18 + 0x11) + cVar13;
                              *(char *)((longlong)puVar18 + 0x12) =
                                   *(char *)((longlong)puVar18 + 0x12) + cVar13;
                              *(char *)((longlong)puVar18 + 0x13) =
                                   *(char *)((longlong)puVar18 + 0x13) + cVar13;
                              puVar18 = (undefined8 *)
                                        ((longlong)puVar18 +
                                        (ulonglong)*(uint *)(plVar8[0x29] + 0x18));
                              uVar16 = uVar16 - 1;
                            } while (uVar16 != 0);
                          }
                          iVar26 = iVar26 + 1;
                          iVar4 = (int)plVar8[3] * 3 + iVar4;
                        } while (iVar26 < (int)plVar8[0x28]);
                      }
                    }
                  }
                }
                lVar15 = *(longlong *)(local_230 + 0x10) +
                         (longlong)*(int *)((longlong)plVar8 + 0x154) * 2;
                lVar29 = *(longlong *)(local_230 + 0x10) + (longlong)(int)plVar8[0x2b] * 2;
                FUN_1401ae2f0(lVar15,plVar8[0x25],
                              (ulonglong)*(ushort *)((longlong)plVar8 + 0x124) * 2);
                if (*(ushort *)(plVar8 + 0x26) != 0) {
                  FUN_1401ae2f0(lVar29,plVar8[0x27],(ulonglong)*(ushort *)(plVar8 + 0x26) * 2);
                }
                if (piVar28[0x2a] != 0) {
                  iVar22 = 1;
                  iVar4 = (int)plVar8[2];
                  psVar19 = (short *)(lVar15 + (ulonglong)*(ushort *)((longlong)plVar8 + 0x124) * 2)
                  ;
                  psVar17 = (short *)(lVar29 + (ulonglong)*(ushort *)(plVar8 + 0x26) * 2);
                  iVar26 = iVar4;
                  if (1 < (int)plVar8[0x28]) {
                    do {
                      FUN_1401ae2f0(psVar19,plVar8[0x25],
                                    (ulonglong)*(ushort *)((longlong)plVar8 + 0x124) * 2);
                      iVar9 = 0;
                      if (*(short *)((longlong)plVar8 + 0x124) != 0) {
                        do {
                          *psVar19 = *psVar19 + (short)iVar4;
                          iVar9 = iVar9 + 1;
                          psVar19 = psVar19 + 1;
                        } while (iVar9 < (int)(uint)*(ushort *)((longlong)plVar8 + 0x124));
                      }
                      iVar4 = iVar4 + (int)plVar8[2];
                      if (*(ushort *)(plVar8 + 0x26) != 0) {
                        FUN_1401ae2f0(psVar17,plVar8[0x27],(ulonglong)*(ushort *)(plVar8 + 0x26) * 2
                                     );
                        iVar9 = 0;
                        if ((short)plVar8[0x26] != 0) {
                          do {
                            *psVar17 = *psVar17 + (short)iVar26;
                            iVar9 = iVar9 + 1;
                            psVar17 = psVar17 + 1;
                          } while (iVar9 < (int)(uint)*(ushort *)(plVar8 + 0x26));
                        }
                        iVar26 = iVar26 + (int)plVar8[2];
                      }
                      iVar22 = iVar22 + 1;
                    } while (iVar22 < (int)plVar8[0x28]);
                  }
                }
              }
              local_244 = local_244 + 1;
              plVar8 = plVar8 + 0x2c;
              param_3 = local_210;
            } while (local_244 < piVar28[0x82]);
          }
          piVar14 = piVar28 + 0xce;
          do {
            lVar15 = 2;
            do {
              lVar29 = 9;
              piVar27 = local_200;
              do {
                lVar5 = *(longlong *)(piVar27 + -0x6c);
                while (lVar5 != 0) {
                  lVar10 = *(longlong *)(lVar5 + 0x28);
                  lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 8);
                  if ((lVar3 == 0) || (*(longlong *)(*(longlong *)(lVar5 + 0x20) + 0x10) == 0)) {
                    if (*(longlong *)(lVar5 + 0x30) == 0) {
                      *(longlong *)(piVar27 + -0x6c) = lVar10;
                    }
                    else {
                      *(longlong *)(*(longlong *)(lVar5 + 0x30) + 0x28) = lVar10;
                    }
                    if (*(longlong *)(lVar5 + 0x28) == 0) {
                      *(undefined8 *)piVar27 = *(undefined8 *)(lVar5 + 0x30);
                    }
                    else {
                      *(undefined8 *)(*(longlong *)(lVar5 + 0x28) + 0x30) =
                           *(undefined8 *)(lVar5 + 0x30);
                    }
                    lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 8);
                    if (lVar3 != 0) {
                      FUN_140220340(lVar3,param_3);
                      *(undefined8 *)(*(longlong *)(lVar5 + 0x20) + 8) = 0;
                    }
                    lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 0x10);
                    if (lVar3 != 0) {
                      FUN_140220340(lVar3,param_3);
                      *(undefined8 *)(*(longlong *)(lVar5 + 0x20) + 0x10) = 0;
                    }
                    iVar4 = 0;
                    if (0 < piVar28[0x82]) {
                      plVar8 = (longlong *)(*(longlong *)(piVar28 + 0x84) + 0x148);
                      do {
                        if (*plVar8 == lVar5) {
                          *plVar8 = 0;
                        }
                        iVar4 = iVar4 + 1;
                        plVar8 = plVar8 + 0x2c;
                      } while (iVar4 < piVar28[0x82]);
                    }
                    FUN_1401b6700(lVar5);
                    *piVar14 = *piVar14 + -1;
                    piVar28[0xcc] = piVar28[0xcc] + -1;
                    lVar5 = lVar10;
                  }
                  else {
                    FUN_140222e30(lVar3,param_3);
                    lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x20) + 0x10);
                    lVar5 = lVar10;
                    if (lVar3 != 0) {
                      FUN_140222e30(lVar3,param_3);
                    }
                  }
                }
                piVar27 = piVar27 + 2;
                piVar14 = piVar14 + 1;
                lVar29 = lVar29 + -1;
              } while (lVar29 != 0);
              lVar15 = lVar15 + -1;
              local_200 = piVar27;
            } while (lVar15 != 0);
            local_238 = (longlong *)((longlong)local_238 + -1);
          } while (local_238 != (longlong *)0x0);
          piVar28[0xcd] = 1;
          if ((DAT_14098ac70 != 0) &&
             (uVar12 = (ulonglong)DAT_14098acd0, DAT_14098acd0 <= DAT_14098acd4)) {
            lVar15 = uVar12 * 8;
            local_238 = (longlong *)0x0;
            iVar4 = DAT_14098acd4;
            do {
              lVar29 = *(longlong *)(DAT_14098ac78 + lVar15);
              if (((lVar29 != 0) && (*(int *)(lVar29 + 0x18) == 0)) &&
                 (*(int **)(lVar29 + 0xa0) == piVar28)) {
                FUN_14021b5c0(*(undefined4 *)(lVar29 + 4),param_3);
                iVar4 = DAT_14098acd4;
              }
              uVar11 = (int)uVar12 + 1;
              uVar12 = (ulonglong)uVar11;
              lVar15 = lVar15 + 8;
            } while ((int)uVar11 <= iVar4);
          }
          return 0;
        }
      } while( true );
    }
  }
  return 0xffffffff;
}


