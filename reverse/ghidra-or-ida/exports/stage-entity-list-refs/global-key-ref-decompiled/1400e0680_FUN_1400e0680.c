// Function: FUN_1400e0680 @ 1400e0680
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e0680(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  bool bVar2;
  undefined1 auVar3 [16];
  undefined8 uVar4;
  double dVar5;
  ushort uVar6;
  undefined1 (*pauVar7) [16];
  undefined8 *puVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  short sVar14;
  int iVar15;
  undefined1 (*pauVar16) [16];
  int iVar17;
  undefined2 uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int *piVar24;
  longlong lVar25;
  bool bVar26;
  float fVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  float fVar34;
  double dVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  undefined4 in_stack_fffffffffffffd08;
  float in_stack_fffffffffffffd10;
  undefined2 uVar44;
  undefined1 in_stack_fffffffffffffd18 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 local_2a8 [12];
  int iStack_29c;
  int iStack_294;
  int iStack_28c;
  undefined4 local_288;
  float fStack_280;
  float fStack_27c;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_220;
  undefined8 uStack_200;
  undefined8 uStack_198;
  
  pauVar16 = DAT_140e45d80;
  iVar11 = DAT_140e44e6c;
  iVar22 = DAT_140e44308;
  uVar18 = (undefined2)((uint)in_stack_fffffffffffffd08 >> 0x10);
  auVar31._12_4_ = 0;
  auVar31._0_12_ = stack0xfffffffffffffd5c;
  _local_2a8 = auVar31 << 0x20;
  iStack_28c = 0;
  auVar31 = _local_2a8;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined1 (*) [16])0x0)) {
    uStack_220._4_4_ = (int)((ulonglong)uStack_250 >> 0x20);
  }
  else {
    iStack_28c = 0;
    uStack_220 = uStack_250;
    pauVar7 = DAT_140e45d80;
    do {
      if (*(int *)(*pauVar7 + 4) == DAT_140e44308) {
        auVar31 = *pauVar7;
        uStack_220 = *(undefined8 *)(pauVar7[5] + 8);
        iStack_294 = *(int *)(pauVar7[1] + 4);
        iStack_28c = *(int *)(pauVar7[1] + 0xc);
        local_288 = *(undefined4 *)pauVar7[2];
        fStack_280 = *(float *)(pauVar7[2] + 8);
        fStack_27c = *(float *)(pauVar7[2] + 0xc);
        local_248 = *(undefined8 *)pauVar7[6];
        _local_2a8 = auVar31;
      }
      pauVar7 = *(undefined1 (**) [16])pauVar7[6];
      param_4 = local_248;
    } while (pauVar7 != (undefined1 (*) [16])0x0);
  }
  iVar20 = auVar31._12_4_;
  if ((iStack_294 == 1) && (iVar20 == 1)) {
    param_1[0x15] = 0;
  }
  auVar32._4_4_ = fStack_280;
  auVar32._0_4_ = fStack_280;
  if (param_1[6] == 0x79) {
    auVar32._8_4_ = fStack_280;
    auVar32._12_4_ = fStack_280;
    auVar33._4_12_ = auVar32._4_12_;
    auVar33._0_4_ = fStack_280 + (float)param_1[0xc];
    param_1[10] = auVar33._0_4_;
    param_1[0xb] = fStack_27c + (float)param_1[0xd];
    if ((iStack_294 == 1) && (iVar20 == 1)) {
      param_1[8] = local_288;
      param_1[7] = iStack_28c;
    }
    iVar17 = param_1[7];
    if ((iVar17 < iStack_28c) && (pauVar7 = pauVar16, 0 < iVar11)) {
      for (; pauVar7 != (undefined1 (*) [16])0x0; pauVar7 = *(undefined1 (**) [16])pauVar7[6]) {
        if (*(int *)(*pauVar7 + 4) == iVar22) {
          *(int *)(pauVar7[1] + 0xc) = *(int *)(pauVar7[1] + 0xc) - (iStack_28c - iVar17);
        }
      }
    }
    iVar17 = param_1[7];
    if (iStack_28c < (int)param_1[7]) {
      param_1[7] = iStack_28c;
      iVar17 = iStack_28c;
    }
    if ((iVar17 < 1) && (0 < iVar11)) {
      for (; pauVar16 != (undefined1 (*) [16])0x0; pauVar16 = *(undefined1 (**) [16])pauVar16[6]) {
        if (*(int *)(*pauVar16 + 4) == iVar22) {
          *(int *)(pauVar16[1] + 0xc) = *(int *)(pauVar16[1] + 0xc) - iStack_28c;
        }
      }
    }
    FUN_140004140(param_1,auVar33._0_8_,iStack_28c,param_4);
    pauVar16 = DAT_140e45d80;
    iVar11 = DAT_140e44e6c;
  }
  iVar22 = DAT_140e418c8;
  fVar34 = DAT_14053ac2c;
  dVar5 = DAT_14053a0f8;
  dVar29 = DAT_140539f40;
  dVar30 = DAT_140539e60;
  uVar44 = (undefined2)((uint)in_stack_fffffffffffffd10 >> 0x10);
  uVar36 = SUB84(DAT_14053aba0,0);
  uVar37 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
  if (param_1[6] == 0x7a || param_1[6] == 0x7b) {
    dVar28 = DAT_140539f40;
    if (DAT_140e418c8 % 0x29 < 9) {
      dVar28 = (double)FUN_140332d90(((double)(DAT_140e418c8 % 0x29) - 0.0) * DAT_14053aad0 *
                                     DAT_14053a020 * DAT_140539d28);
      dVar28 = dVar28 * dVar30 + dVar29;
    }
    uVar36 = (undefined4)((ulonglong)dVar28 >> 0x20);
    fVar38 = fStack_280 + (float)param_1[0xc];
    bVar2 = (float)param_1[0xc] <= 0.0 && (float)param_1[0xc] != 0.0;
    iVar17 = param_1[5];
    param_1[10] = fVar38;
    param_1[0xb] = fStack_27c + (float)param_1[0xd];
    if (iVar17 == 0) {
      fVar39 = (float)param_1[0xb] + DAT_14053ac80;
      dVar29 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar39),
                                     (double)(DAT_140e445d8 - fVar38));
      dVar29 = dVar29 * DAT_14053aba0;
      uVar13 = (ushort)(int)dVar29;
      if (param_1[6] == 0x7a) {
        if ((iStack_294 == 1) && (iVar22 = iStack_29c % 0x578, iVar22 < 0x26c)) {
          iVar11 = 1;
          if (DAT_140e419b8 == 0) {
            iVar11 = 0xa4;
          }
          else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
                  (DAT_140e419b8 == 4)) {
            iVar11 = 0x7b;
          }
          iVar17 = 1;
          if (DAT_140e419b8 != 0) {
            if (DAT_140e419b8 == 1) {
              iVar17 = 3;
            }
            else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
              iVar17 = 5;
            }
            else {
              iVar17 = 1;
              if (DAT_140e419b8 == 4) {
                iVar17 = 7;
              }
            }
          }
          iVar17 = iVar17 + ((iVar22 + -0x5a) / (iVar11 * 2)) * 2;
          iVar23 = 1;
          if (DAT_140e419b8 == 0) {
            iVar23 = 0x19;
          }
          else if (DAT_140e419b8 == 1) {
            iVar23 = 0x1e;
          }
          else if (DAT_140e419b8 == 2) {
            iVar23 = 0x28;
          }
          else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
            iVar23 = 0x32;
          }
          dVar35 = DAT_14053a0d0;
          if ((((DAT_140e419b8 != 0) && (dVar35 = dVar5, DAT_140e419b8 != 1)) &&
              (dVar35 = DAT_14053a118, DAT_140e419b8 != 2)) &&
             ((dVar35 = DAT_14053a138, DAT_140e419b8 != 3 &&
              (dVar35 = DAT_140539f40, DAT_140e419b8 == 4)))) {
            dVar35 = DAT_14053a1b8;
          }
          iVar11 = (iVar22 + -0x5a) % iVar11;
          dVar35 = (double)iVar11 * dVar30 * (double)iVar22 * _DAT_140539d70 + dVar35;
          if ((iVar22 < 0x5a) || (iVar11 != 0)) {
            uVar9 = *(ushort *)((longlong)param_1 + 0x42);
            if (0x59 < iVar22) goto LAB_1400e0b85;
          }
          else {
            *(ushort *)((longlong)param_1 + 0x42) = uVar13;
            uVar9 = uVar13;
LAB_1400e0b85:
            if ((iVar11 < iVar23) && (iVar11 == (iVar11 / 5) * 5)) {
              auVar45._12_4_ = in_stack_fffffffffffffd18._12_4_;
              auVar45._0_8_ = in_stack_fffffffffffffd18._0_8_;
              auVar45._8_4_ = 1;
              auVar46._8_8_ = auVar45._8_8_;
              auVar46._0_8_ = dVar35;
              in_stack_fffffffffffffd10 = fVar34;
              FUN_1400709b0(2,0,fVar38,fVar39,uVar9,fVar34,dVar35,auVar46._8_8_,iVar17,27000,0);
              if (2 < DAT_140e419b8) {
                auVar47._12_4_ = auVar46._12_4_;
                auVar47._0_8_ = auVar46._0_8_;
                auVar47._8_4_ = 1;
                in_stack_fffffffffffffd10 = fVar34;
                FUN_1400709b0(2,0,fVar38,fVar39,*(undefined2 *)((longlong)param_1 + 0x42),fVar34,
                              dVar35 - DAT_140539ff0,auVar47._8_8_,iVar17,27000,0);
              }
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
              FUN_14018a340(DAT_140e472a8,1,1);
            }
          }
          uVar9 = *(ushort *)((longlong)param_1 + 0x42);
          iVar11 = ((int)dVar29 & 0xffffU) - (uint)uVar9;
          iVar22 = iVar11 + 0x10000;
          if (-0x8001 < iVar11) {
            iVar22 = iVar11;
          }
          iVar11 = iVar22 + -0x10000;
          if (iVar22 < 0x8001) {
            iVar11 = iVar22;
          }
          if (iVar11 < 1) {
            uVar6 = uVar9;
            if ((iVar11 < 0) && (uVar6 = uVar9 - 0x20, -0x20 < iVar11)) {
              uVar6 = uVar13;
            }
          }
          else {
            uVar6 = uVar13;
            if (0x1f < iVar11) {
              uVar6 = uVar9 + 0x20;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar6;
        }
        fVar27 = (float)param_1[0xb] + fVar34;
        in_stack_fffffffffffffd18._8_4_ = SUB84(dVar28,0);
        in_stack_fffffffffffffd18._0_8_ = dVar28;
        in_stack_fffffffffffffd18._12_4_ = uVar36;
        in_stack_fffffffffffffd10 = (float)((uint)in_stack_fffffffffffffd10 & 0xffff0000);
        FUN_1400c8410(DAT_140e44ce8,0x1b,7,param_1[10],fVar27,in_stack_fffffffffffffd10,
                      in_stack_fffffffffffffd18,0xff,0xff,0xff,0xff,1,bVar2);
        uVar18 = (undefined2)((uint)fVar27 >> 0x10);
        iVar17 = param_1[5];
        pauVar16 = DAT_140e45d80;
        iVar11 = DAT_140e44e6c;
        iVar22 = DAT_140e418c8;
      }
      if (param_1[6] == 0x7b) {
        if (iStack_294 == 1) {
          uStack_200 = 0;
          uStack_200._4_4_ = 0;
          pauVar7 = pauVar16;
          iVar22 = uStack_200._4_4_;
          if (0 < iVar11) {
            for (; iVar22 = (int)((ulonglong)uStack_200 >> 0x20),
                pauVar7 != (undefined1 (*) [16])0x0; pauVar7 = *(undefined1 (**) [16])pauVar7[6]) {
              if (*(int *)(*pauVar7 + 4) == DAT_1407c77a0 + 1) {
                uStack_200 = *(undefined8 *)(pauVar7[1] + 8);
              }
            }
          }
          uStack_200._4_4_ = iVar22;
          uStack_198 = 0;
          uStack_198._4_4_ = 0;
          iVar22 = uStack_198._4_4_;
          if (0 < iVar11) {
            for (; iVar22 = (int)((ulonglong)uStack_198 >> 0x20),
                pauVar16 != (undefined1 (*) [16])0x0; pauVar16 = *(undefined1 (**) [16])pauVar16[6])
            {
              if (*(int *)(*pauVar16 + 4) == DAT_1407c77a0 + 2) {
                uStack_198 = *(undefined8 *)(pauVar16[1] + 8);
              }
            }
          }
          uStack_198._4_4_ = iVar22;
          iVar22 = iStack_29c % 0x578;
          if (iVar22 < 0x262) {
            iVar11 = 1;
            if (DAT_140e419b8 == 0) {
              iVar11 = 0x2d;
            }
            else if (DAT_140e419b8 == 1) {
              iVar11 = 0x1e;
            }
            else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
              iVar11 = 0x19;
            }
            iVar17 = 1;
            if (DAT_140e419b8 == 0) {
              iVar17 = 6;
            }
            else if (DAT_140e419b8 == 1) {
              iVar17 = 9;
            }
            else if (DAT_140e419b8 == 2) {
              iVar17 = 0xc;
            }
            else if (DAT_140e419b8 == 3) {
              iVar17 = 0xb;
            }
            else if (DAT_140e419b8 == 4) {
              iVar17 = 0xd;
            }
            sVar14 = 1;
            iVar23 = 0x78;
            iVar17 = iVar17 + ((iVar22 + -0x78) / 0x7b) * 2;
            if (DAT_140e419b8 == 0) {
              sVar14 = 0x46;
            }
            else if (DAT_140e419b8 == 1) {
              sVar14 = 100;
            }
            else if (DAT_140e419b8 == 2) {
              sVar14 = 0x6e;
            }
            else if (DAT_140e419b8 == 3) {
              sVar14 = 0x78;
            }
            else if (DAT_140e419b8 == 4) {
              sVar14 = 0x8c;
            }
            dVar29 = DAT_14053a070;
            if (((DAT_140e419b8 != 0) && (dVar29 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
               ((dVar29 = dVar5, DAT_140e419b8 != 2 &&
                ((DAT_140e419b8 != 3 && (dVar29 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
              dVar29 = DAT_14053a140;
            }
            dVar29 = (double)iVar22 * _DAT_140539d80 + dVar29;
            if (0x7a < (iVar22 + -0x78) % 0xf6) {
              sVar14 = -sVar14;
            }
            if ((uStack_200._4_4_ < 1) || (lVar25 = 2, uStack_198._4_4_ < 1)) {
              lVar25 = 4;
            }
            iVar15 = 0x78;
            if ((0x77 < iVar22) && (iVar22 + -0x78 == ((iVar22 + -0x78) / 0x7b) * 0x7b)) {
              *(ushort *)((longlong)param_1 + 0x42) = uVar13;
            }
            if (bVar2) {
              do {
                if ((uStack_200._4_4_ < 1) || (iVar10 = iVar15, uStack_198._4_4_ < 1)) {
                  iVar10 = iVar23;
                }
                if ((iVar10 <= iVar22) &&
                   (((iVar22 < iVar10 + 100 || (iVar10 == -100)) &&
                    (uVar12 = (iVar22 - iVar10) % iVar11, (int)uVar12 < 0x10)))) {
                  uVar12 = uVar12 & 0x80000003;
                  if ((int)uVar12 < 0) {
                    uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
                  }
                  if (uVar12 == 0) {
                    auVar50._12_4_ = in_stack_fffffffffffffd18._12_4_;
                    auVar50._0_8_ = in_stack_fffffffffffffd18._0_8_;
                    auVar50._8_4_ = 1;
                    in_stack_fffffffffffffd18._8_8_ = auVar50._8_8_;
                    in_stack_fffffffffffffd18._0_8_ = dVar29;
                    in_stack_fffffffffffffd10 = fVar34;
                    FUN_1400709b0(0xb,0,fVar38,fVar39,*(undefined2 *)((longlong)param_1 + 0x42),
                                  fVar34,dVar29,in_stack_fffffffffffffd18._8_8_,iVar17,0x10000,0);
                    if (2 < DAT_140e419b8) {
                      auVar51._12_4_ = in_stack_fffffffffffffd18._12_4_;
                      auVar51._0_8_ = in_stack_fffffffffffffd18._0_8_;
                      auVar51._8_4_ = 1;
                      in_stack_fffffffffffffd18._8_8_ = auVar51._8_8_;
                      in_stack_fffffffffffffd10 = fVar34;
                      FUN_1400709b0(0xb,0,fVar38,fVar39,*(short *)((longlong)param_1 + 0x42) + 800,
                                    fVar34,dVar29,in_stack_fffffffffffffd18._8_8_,iVar17,0x10000,0);
                    }
                    FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
                    FUN_14018a340(DAT_140e472a8,1,1);
                  }
                }
                iVar15 = iVar15 + 0xf6;
                iVar23 = iVar23 + 0x7b;
                lVar25 = lVar25 + -1;
              } while (lVar25 != 0);
            }
            else {
              iVar15 = 0xf3;
              do {
                if ((uStack_200._4_4_ < 1) || (iVar10 = iVar15, uStack_198._4_4_ < 1)) {
                  iVar10 = iVar23;
                }
                if (((iVar10 <= iVar22) && ((iVar22 < iVar10 + 100 || (iVar10 == -100)))) &&
                   (uVar12 = (iVar22 - iVar10) % iVar11, (int)uVar12 < 0x10)) {
                  uVar12 = uVar12 & 0x80000003;
                  if ((int)uVar12 < 0) {
                    uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
                  }
                  if (uVar12 == 0) {
                    auVar48._12_4_ = in_stack_fffffffffffffd18._12_4_;
                    auVar48._0_8_ = in_stack_fffffffffffffd18._0_8_;
                    auVar48._8_4_ = 1;
                    in_stack_fffffffffffffd18._8_8_ = auVar48._8_8_;
                    in_stack_fffffffffffffd18._0_8_ = dVar29;
                    in_stack_fffffffffffffd10 = fVar34;
                    FUN_1400709b0(0xb,0,fVar38,fVar39,*(undefined2 *)((longlong)param_1 + 0x42),
                                  fVar34,dVar29,in_stack_fffffffffffffd18._8_8_,iVar17,0x10000,0);
                    if (2 < DAT_140e419b8) {
                      auVar49._12_4_ = in_stack_fffffffffffffd18._12_4_;
                      auVar49._0_8_ = in_stack_fffffffffffffd18._0_8_;
                      auVar49._8_4_ = 1;
                      in_stack_fffffffffffffd18._8_8_ = auVar49._8_8_;
                      in_stack_fffffffffffffd10 = fVar34;
                      FUN_1400709b0(0xb,0,fVar38,fVar39,*(short *)((longlong)param_1 + 0x42) + 800,
                                    fVar34,dVar29,in_stack_fffffffffffffd18._8_8_,iVar17,0x10000,0);
                    }
                    FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
                    FUN_14018a340(DAT_140e472a8,1,1);
                  }
                }
                iVar15 = iVar15 + 0xf6;
                iVar23 = iVar23 + 0x7b;
                lVar25 = lVar25 + -1;
              } while (lVar25 != 0);
            }
            *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar14;
          }
        }
        fVar38 = (float)param_1[0xb] + fVar34;
        in_stack_fffffffffffffd18._8_4_ = SUB84(dVar28,0);
        in_stack_fffffffffffffd18._0_8_ = dVar28;
        in_stack_fffffffffffffd18._12_4_ = uVar36;
        in_stack_fffffffffffffd10 = (float)((uint)in_stack_fffffffffffffd10 & 0xffff0000);
        FUN_1400c8410(DAT_140e44cec,0x1b,7,param_1[10],fVar38,in_stack_fffffffffffffd10,
                      in_stack_fffffffffffffd18,0xff,0xff,0xff,0xff,1,bVar2);
        uVar18 = (undefined2)((uint)fVar38 >> 0x10);
        iVar17 = param_1[5];
        iVar22 = DAT_140e418c8;
      }
      uVar36 = DAT_140e41a50;
      if ((iVar22 == (iVar22 / 0x29) * 0x29) && (uVar37 = param_1[1], DAT_140e45d1c < 0x1000)) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar36;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 0x25;
        puVar8[2] = 0x1e;
        puVar8[3] = 0x41f00000;
        *(undefined4 *)(puVar8 + 4) = 0x41f00000;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0x10;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        *(undefined4 *)(puVar8 + 10) = 0x80;
        *(undefined4 *)((longlong)puVar8 + 0x54) = uVar37;
        puVar8[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
        iVar17 = param_1[5];
        DAT_140e45d28 = puVar8;
      }
      uVar36 = DAT_14053b380;
      if (param_1[0x15] == 0) {
        uVar37 = DAT_14053b380;
        FUN_140079c10(param_1,1);
        uVar18 = (undefined2)((uint)uVar37 >> 0x10);
        iVar17 = param_1[5];
      }
      uVar44 = (undefined2)((uint)in_stack_fffffffffffffd10 >> 0x10);
      if ((int)param_1[7] < 1) {
        FUN_14007b010(param_1,0x960,8);
        FUN_140079e20(param_1,2);
        uVar37 = SUB84(DAT_140539f40,0);
        uVar40 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
        auVar52._12_4_ = in_stack_fffffffffffffd18._12_4_;
        auVar52._0_8_ = in_stack_fffffffffffffd18._0_8_;
        auVar52._8_4_ = 10;
        auVar53._8_8_ = auVar52._8_8_;
        auVar53._0_8_ = DAT_140539f40;
        stage_entity_spawn_candidate
                  (0x153,param_1[8],1,uVar36,uVar36,CONCAT22(uVar44,0x4000),DAT_140539f40,
                   auVar53._8_8_,1,DAT_140e44308);
        iVar22 = DAT_140e44308;
        pauVar16 = DAT_140e45d80;
        if (0 < DAT_140e44e6c) {
          for (; pauVar16 != (undefined1 (*) [16])0x0; pauVar16 = *(undefined1 (**) [16])pauVar16[6]
              ) {
            if (*(int *)(*pauVar16 + 4) == iVar22) {
              *(int *)(pauVar16[5] + 0xc) = *(int *)(pauVar16[5] + 0xc) + -1;
            }
          }
        }
        piVar24 = param_1 + 5;
        auVar3._12_4_ = 0;
        auVar3._0_12_ = auVar53._4_12_;
        in_stack_fffffffffffffd18 = auVar3 << 0x20;
        in_stack_fffffffffffffd10 = 0.0;
        uVar18 = (undefined2)((uint)uVar36 >> 0x10);
        FUN_140109660(0x19);
        param_1[0x15] = 1;
        if (param_1[6] == 0x7b) {
          DAT_140e45da4 = DAT_140e45da4 + 1;
        }
        *piVar24 = *piVar24 + 1;
        iVar17 = *piVar24;
      }
      else {
        uVar37 = SUB84(DAT_140539f40,0);
        uVar40 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
      piVar24 = param_1 + 5;
      dVar29 = (double)CONCAT44(uVar40,uVar37);
      if (iStack_294 == 3) {
        FUN_140079e20(param_1,2);
        *piVar24 = *piVar24 + 1;
        iVar17 = *piVar24;
        param_1[0x15] = 1;
      }
    }
    uVar44 = (undefined2)((uint)in_stack_fffffffffffffd10 >> 0x10);
    uVar36 = (undefined4)((ulonglong)dVar29 >> 0x20);
    if (iVar17 == 1) {
      if (param_1[6] == 0x7a) {
        fVar38 = (float)param_1[0xb] + fVar34;
        in_stack_fffffffffffffd18._8_4_ = SUB84(dVar29,0);
        in_stack_fffffffffffffd18._0_8_ = dVar29;
        in_stack_fffffffffffffd18._12_4_ = uVar36;
        in_stack_fffffffffffffd10 = (float)((uint)in_stack_fffffffffffffd10 & 0xffff0000);
        FUN_1400c8410(DAT_140e44cf0,0x1b,7,param_1[10],fVar38,in_stack_fffffffffffffd10,
                      in_stack_fffffffffffffd18,0xff,0xff,0xff,0xff,1,bVar2);
        uVar18 = (undefined2)((uint)fVar38 >> 0x10);
      }
      uVar44 = (undefined2)((uint)in_stack_fffffffffffffd10 >> 0x10);
      if (param_1[6] == 0x7b) {
        fVar38 = (float)param_1[0xb] + fVar34;
        in_stack_fffffffffffffd18._8_4_ = SUB84(dVar29,0);
        in_stack_fffffffffffffd18._0_8_ = dVar29;
        in_stack_fffffffffffffd18._12_4_ = uVar36;
        uVar12 = (uint)in_stack_fffffffffffffd10 & 0xffff0000;
        FUN_1400c8410(DAT_140e44cf4,0x1b,7,param_1[10],fVar38,uVar12,in_stack_fffffffffffffd18,0xff,
                      0xff,0xff,0xff,1,bVar2);
        uVar44 = (undefined2)(uVar12 >> 0x10);
        uVar18 = (undefined2)((uint)fVar38 >> 0x10);
      }
    }
    uVar36 = SUB84(DAT_14053aba0,0);
    uVar37 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
  }
  iVar22 = param_1[6];
  if (1 < iVar22 - 0x7cU) {
    if (iStack_294 != 3) {
      return;
    }
    goto LAB_1400e2077;
  }
  fVar43 = fStack_27c + (float)param_1[0xd];
  fVar38 = (float)param_1[0xc];
  fVar42 = fStack_280 + fVar38;
  dVar29 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar43),(double)(DAT_140e445d8 - fVar42));
  uVar13 = *(ushort *)(param_1 + 0x10);
  uVar12 = (uint)(dVar29 * (double)CONCAT44(uVar37,uVar36));
  dVar29 = (double)FUN_1403307c0();
  dVar29 = dVar29 * DAT_14053a278;
  dVar30 = (double)FUN_140332d90();
  dVar30 = dVar30 * DAT_14053a278;
  param_1[10] = (float)dVar29 + fVar42;
  param_1[0xb] = (float)dVar30 + fVar43;
  dVar29 = (double)FUN_1403307c0();
  fVar41 = (float)(dVar29 * DAT_14053a380) + fVar42;
  dVar30 = (double)FUN_140332d90();
  iVar11 = DAT_140e419b8;
  fVar39 = DAT_14053ad90;
  dVar29 = DAT_140539d60;
  fVar27 = (float)(dVar30 * DAT_14053a380) + fVar43;
  if ((iVar22 == 0x7c) && (iStack_294 == 1)) {
    iStack_29c = iStack_29c % 0x578;
    if (iStack_29c < 600) {
      dVar30 = (double)FUN_1403300b4((double)((fStack_27c + DAT_14053ad90) - fVar43),
                                     (double)(fStack_280 - fVar42));
      uVar9 = (ushort)(int)(dVar30 * DAT_14053aba0);
LAB_1400e179b:
      *(ushort *)((longlong)param_1 + 0x42) = uVar9;
      uVar6 = uVar9 - uVar13;
      uVar19 = (uint)uVar6;
      if (0x8000 < uVar6) {
        uVar19 = 0x10000 - uVar6;
      }
      iVar11 = (uint)uVar9 - (uint)uVar13;
      iVar17 = (int)uVar19 / 10 + 0x30;
      iVar22 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar22 = iVar11;
      }
      iVar11 = iVar22 + -0x10000;
      if (iVar22 < 0x8001) {
        iVar11 = iVar22;
      }
      if (iVar11 < 1) {
        if ((iVar11 < 0) && (uVar13 = uVar13 - (short)iVar17, -iVar17 < iVar11)) {
          uVar13 = uVar9;
        }
        *(ushort *)(param_1 + 0x10) = uVar13;
      }
      else if (iVar11 < iVar17) {
        *(ushort *)(param_1 + 0x10) = uVar9;
        uVar13 = uVar9;
      }
      else {
        uVar13 = uVar13 + (short)iVar17;
        *(ushort *)(param_1 + 0x10) = uVar13;
      }
      goto LAB_1400e1a75;
    }
    if (iStack_29c < 700) {
      uVar9 = -(ushort)(fVar38 < 0.0) & 0x8000;
      goto LAB_1400e179b;
    }
    if (DAT_140e419b8 == 0) {
      iVar22 = 0xc;
    }
    else if (DAT_140e419b8 == 1) {
      iVar22 = 8;
    }
    else if (DAT_140e419b8 == 2) {
      iVar22 = 7;
    }
    else if (DAT_140e419b8 == 3) {
      iVar22 = 6;
    }
    else {
      iVar22 = 1;
      if (DAT_140e419b8 == 4) {
        iVar22 = 5;
      }
    }
    iVar17 = 1;
    if (DAT_140e419b8 == 0) {
      iVar17 = 3;
    }
    else if (DAT_140e419b8 == 1) {
      iVar17 = 5;
    }
    else if (DAT_140e419b8 == 2) {
      iVar17 = 6;
    }
    else if (DAT_140e419b8 == 3) {
      iVar17 = 7;
    }
    else if (DAT_140e419b8 == 4) {
      iVar17 = 8;
    }
    if (DAT_140e419b8 == 0) {
      sVar14 = 0xf0;
    }
    else if (DAT_140e419b8 == 1) {
      sVar14 = 300;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (sVar14 = 1, DAT_140e419b8 == 4)) {
      sVar14 = 0x15e;
    }
    uVar36 = SUB84(DAT_140539f40,0);
    uVar37 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    sVar14 = (short)iStack_29c + -700 + sVar14;
    dVar30 = DAT_14053a088;
    if (((DAT_140e419b8 != 0) && (dVar30 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
       ((dVar30 = DAT_14053a0f8, DAT_140e419b8 != 2 &&
        ((dVar30 = DAT_14053a118, DAT_140e419b8 != 3 && (dVar30 = DAT_140539f40, DAT_140e419b8 == 4)
         ))))) {
      dVar30 = DAT_14053a158;
    }
    dVar30 = ((double)iStack_29c - DAT_14053a840) * DAT_140539d60 + dVar30;
    if (uStack_220._4_4_ == 1) {
      iVar17 = iVar17 + 2;
    }
    if (fVar38 < 0.0) {
      uVar13 = uVar13 - sVar14;
      *(ushort *)(param_1 + 0x10) = uVar13;
    }
    else {
      uVar13 = sVar14 + *(short *)(param_1 + 0x10);
      *(ushort *)(param_1 + 0x10) = uVar13;
    }
    if ((iStack_29c < 0x550) &&
       (uVar1 = (longlong)(iStack_29c + -700) % (longlong)iVar22, (int)uVar1 == 0)) {
      auVar54._12_4_ = in_stack_fffffffffffffd18._12_4_;
      auVar54._0_8_ = in_stack_fffffffffffffd18._0_8_;
      auVar54._8_4_ = 1;
      in_stack_fffffffffffffd18._8_8_ = auVar54._8_8_;
      in_stack_fffffffffffffd18._0_8_ = dVar30;
      uVar40 = CONCAT22(uVar18,uVar13);
      fVar38 = fVar34;
      FUN_1400709b0(0xc,uVar1 & 0xffffffff,fVar41,fVar27,uVar40,fVar34,dVar30,
                    in_stack_fffffffffffffd18._8_8_,iVar17,iVar17 * 0x115c + -0x115c,0);
      uVar44 = (undefined2)((uint)fVar38 >> 0x10);
      uVar18 = (undefined2)((uint)uVar40 >> 0x10);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar13 = *(ushort *)(param_1 + 0x10);
      iVar11 = DAT_140e419b8;
    }
  }
  else {
LAB_1400e1a75:
    uVar36 = SUB84(DAT_140539f40,0);
    uVar37 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    iVar11 = DAT_140e419b8;
  }
  dVar30 = DAT_140539fc8;
  uVar19 = (uint)uVar13;
  if ((param_1[6] == 0x7d) && (iStack_294 == 1)) {
    iVar22 = iVar20 % 0x578;
    if (iVar22 < 0x26c) {
      dVar29 = (double)FUN_1403300b4((double)((fStack_27c + fVar39) - fVar43),
                                     (double)(fStack_280 - fVar42));
      uVar19 = (uint)uVar13;
      uVar21 = (uint)(dVar29 * DAT_14053aba0);
      uVar6 = (ushort)uVar21;
      *(ushort *)((longlong)param_1 + 0x42) = uVar6;
      uVar9 = uVar6 - uVar13;
      uVar12 = (uint)uVar9;
      if (0x8000 < uVar9) {
        uVar12 = 0x10000 - uVar9;
      }
      iVar11 = (uVar21 & 0xffff) - (uint)uVar13;
      iVar17 = (int)uVar12 / 10 + 0x30;
      iVar22 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar22 = iVar11;
      }
      iVar11 = iVar22 + -0x10000;
      if (iVar22 < 0x8001) {
        iVar11 = iVar22;
      }
      if (iVar11 < 1) {
        if (iVar11 < 0) {
          uVar13 = uVar13 - (short)iVar17;
          if (-iVar17 < iVar11) {
            uVar13 = uVar6;
          }
          uVar19 = (uint)uVar13;
        }
      }
      else if (iVar11 < iVar17) {
        uVar19 = uVar21 & 0xffff;
      }
      else {
LAB_1400e1b87:
        uVar19 = (uint)(ushort)(uVar13 + (short)iVar17);
      }
    }
    else {
      uVar9 = (ushort)uVar12;
      *(ushort *)((longlong)param_1 + 0x42) = uVar9;
      if (iVar22 < 0x294) {
        uVar19 = (uint)uVar13;
        uVar6 = uVar9 - uVar13;
        uVar21 = (uint)uVar6;
        if (0x8000 < uVar6) {
          uVar21 = 0x10000 - uVar6;
        }
        iVar11 = (uVar12 & 0xffff) - (uint)uVar13;
        iVar17 = (int)uVar21 / 10 + 0x30;
        iVar22 = iVar11 + 0x10000;
        if (-0x8001 < iVar11) {
          iVar22 = iVar11;
        }
        iVar11 = iVar22 + -0x10000;
        if (iVar22 < 0x8001) {
          iVar11 = iVar22;
        }
        if (iVar11 < 1) {
          if (iVar11 < 0) {
            uVar13 = uVar13 - (short)iVar17;
            if (-iVar17 < iVar11) {
              uVar13 = uVar9;
            }
            uVar19 = (uint)uVar13;
          }
        }
        else {
          if (iVar17 <= iVar11) goto LAB_1400e1b87;
          uVar19 = uVar12 & 0xffff;
        }
      }
      else {
        iVar17 = 1;
        if (iVar11 == 0) {
          iVar17 = 0x21;
        }
        else if (((iVar11 == 1) || (iVar11 == 2)) || (iVar11 == 3)) {
          iVar17 = 0x1b;
        }
        else if (iVar11 == 4) {
          iVar17 = 0x15;
        }
        iVar23 = 1;
        if (iVar11 == 0) {
          iVar23 = 9;
        }
        else if (iVar11 == 1) {
          iVar23 = 0xc;
        }
        else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
          iVar23 = 0xf;
        }
        dVar29 = ((double)iVar22 - _DAT_14053a800) * dVar29;
        if (iVar11 == 0) {
          dVar29 = dVar29 + DAT_14053a0d0;
        }
        else if (iVar11 == 1) {
          dVar29 = dVar29 + DAT_14053a118;
        }
        else if (iVar11 == 2) {
          dVar29 = dVar29 + DAT_14053a178;
        }
        else if (iVar11 == 3) {
          dVar29 = dVar29 + DAT_14053a138;
        }
        else if (iVar11 == 4) {
          dVar29 = dVar29 + DAT_14053a1b8;
        }
        else {
          dVar29 = dVar29 + (double)CONCAT44(uVar37,uVar36);
        }
        if (((iVar22 < 0x550) && (iVar11 = (iVar22 + -0x294) % iVar17, iVar11 < iVar23)) &&
           (iVar11 == (iVar11 / 3 + (iVar11 >> 0x1f) +
                      (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3)) {
          auVar55._12_4_ = in_stack_fffffffffffffd18._12_4_;
          auVar55._0_8_ = in_stack_fffffffffffffd18._0_8_;
          auVar55._8_4_ = 1;
          auVar56._8_8_ = auVar55._8_8_;
          auVar56._0_8_ = dVar29;
          fVar38 = fVar34;
          FUN_14006c2f0(6,0,fVar41,fVar27,CONCAT22(uVar18,*(undefined2 *)(param_1 + 0x10)),fVar34,
                        dVar29,auVar56._8_8_,0);
          uVar44 = (undefined2)((uint)fVar38 >> 0x10);
          if (2 < DAT_140e419b8) {
            auVar57._12_4_ = auVar56._12_4_;
            auVar57._0_8_ = auVar56._0_8_;
            auVar57._8_4_ = 1;
            FUN_14006c2f0(6,0,fVar41,fVar27,*(undefined2 *)(param_1 + 0x10),fVar34,dVar29 + dVar30,
                          auVar57._8_8_,0);
            uVar44 = (undefined2)((uint)fVar34 >> 0x10);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          uVar19 = (uint)*(ushort *)(param_1 + 0x10);
LAB_1400e1dfc:
          if ((iVar22 + -0x294) % iVar17 < iVar23 + -2) goto LAB_1400e1e72;
        }
        else {
          uVar19 = (uint)uVar13;
          if (iVar22 < 0x550) goto LAB_1400e1dfc;
        }
        uVar13 = *(ushort *)((longlong)param_1 + 0x42);
        iVar11 = uVar13 - uVar19;
        iVar22 = iVar11 + 0x10000;
        if (-0x8001 < iVar11) {
          iVar22 = iVar11;
        }
        iVar11 = iVar22 + -0x10000;
        if (iVar22 < 0x8001) {
          iVar11 = iVar22;
        }
        if (iVar11 < 1) {
          if ((iVar11 < 0) && (uVar19 = (uint)(ushort)((short)uVar19 - 0x8ae), -0x8ae < iVar11)) {
            uVar19 = (uint)uVar13;
          }
        }
        else {
          if (0x8ad < iVar11) {
            uVar13 = (short)uVar19 + 0x8ae;
          }
          uVar19 = (uint)uVar13;
        }
      }
    }
    *(short *)(param_1 + 0x10) = (short)uVar19;
  }
LAB_1400e1e72:
  uVar18 = (undefined2)uVar19;
  dVar29 = (double)FUN_1403307c0();
  fVar38 = (float)(dVar29 * DAT_14053a4a0) + fVar42;
  dVar29 = (double)FUN_140332d90();
  uVar4 = DAT_140539f38;
  fVar34 = (float)(dVar29 * DAT_14053a4a0) + fVar43;
  if (param_1[6] == 0x7c) {
    uVar40 = CONCAT22(uVar44,uVar18);
    FUN_1400c8410(DAT_140e447a4,0x1c,8,fVar38,fVar34,uVar40,dVar30,DAT_140539f38,0xff,0,0xff,0x40,1,
                  0);
    uVar44 = (undefined2)((uint)uVar40 >> 0x10);
    uVar18 = *(undefined2 *)(param_1 + 0x10);
  }
  if (param_1[6] == 0x7d) {
    uVar40 = CONCAT22(uVar44,uVar18);
    FUN_1400c8410(DAT_140e447a4,0x1c,8,fVar38,fVar34,uVar40,dVar30,uVar4,0,0xff,0xff,0x40,1,0);
    uVar44 = (undefined2)((uint)uVar40 >> 0x10);
  }
  auVar58._4_4_ = uVar37;
  auVar58._0_4_ = uVar36;
  auVar58._8_4_ = uVar36;
  auVar58._12_4_ = uVar37;
  FUN_1400c8410(DAT_140e447f0,0x1c,7,CONCAT44(fStack_280,fVar42),fVar43,
                CONCAT22(uVar44,*(undefined2 *)(param_1 + 0x10)),auVar58,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x960,6);
    FUN_140079e20(param_1,1);
    iVar22 = DAT_140e44308;
    pauVar16 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; pauVar16 != (undefined1 (*) [16])0x0; pauVar16 = *(undefined1 (**) [16])pauVar16[6]) {
        if (*(int *)(*pauVar16 + 4) == iVar22) {
          *(int *)(pauVar16[5] + 0xc) = *(int *)(pauVar16[5] + 0xc) + -1;
        }
      }
    }
    *param_1 = 0;
  }
  if (iStack_294 != 3) {
    return;
  }
  FUN_140079e20(param_1,1);
  *param_1 = 0;
LAB_1400e2077:
  param_1[0x15] = 1;
  if (iVar20 == 0x46) {
    *param_1 = 0;
  }
  return;
}


