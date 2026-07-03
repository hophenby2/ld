// Function: FUN_1400eb780 @ 1400eb780
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400eb780(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  short sVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ushort uVar17;
  ushort uVar18;
  uint uVar19;
  short sVar20;
  ushort uVar21;
  short sVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  uint local_res8;
  longlong local_res10;
  float in_stack_fffffffffffffe98;
  undefined2 uVar34;
  uint in_stack_fffffffffffffea0;
  undefined1 in_stack_fffffffffffffea8 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  short local_118 [8];
  float local_108 [4];
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  
  dVar26 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar26 = dVar26 * DAT_14053aba0;
  iVar11 = 0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar35._12_4_ = in_stack_fffffffffffffea8._12_4_;
    auVar35._0_8_ = in_stack_fffffffffffffea8._0_8_;
    auVar35._8_4_ = param_1[0x14];
    in_stack_fffffffffffffea8._8_8_ = auVar35._8_8_;
    in_stack_fffffffffffffea8._0_8_ = DAT_14053a4f0;
    in_stack_fffffffffffffe98 = (float)param_1[0xb];
    in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,
               DAT_14053a4f0,in_stack_fffffffffffffea8._8_8_,1,0);
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 200;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar8 = DAT_14053a020;
  dVar7 = DAT_140539f40;
  dVar6 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar14 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
    uVar19 = uVar19 * 0x800 ^ uVar19;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
    uVar15 = DAT_1407c7798 * 0x6f + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar14 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ uVar14) % 0x12d + 0xd2);
    uVar19 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar19 = uVar19 * 0x800 ^ uVar19;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  iVar16 = param_1[5];
  uVar33 = SUB84(DAT_140539f40,0);
  uVar5 = (ulonglong)DAT_140539f40 >> 0x20;
  if (iVar16 == 0) {
    iVar11 = 0;
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar11 = param_1[5];
    }
    iVar16 = param_1[3];
    if (iVar16 < 0x79) {
      iVar11 = (int)(float)param_1[0xd];
      if (iVar16 < 0) {
        param_1[0xb] = 0x44bb8000;
      }
      else {
        if (iVar16 < 0x78) {
          dVar26 = (double)FUN_140332d90(((double)iVar16 - 0.0) * DAT_14053a4d8 * dVar8 * dVar6);
          iVar11 = (int)(dVar26 * (double)(iVar11 + -0x5dc)) + 0x5dc;
        }
        param_1[0xb] = (float)iVar11;
      }
    }
    else {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      if (iVar16 == 0x8c) {
        param_1[0x15] = 0;
        DAT_140e4430c = 0x5dc;
        param_1[5] = iVar11 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 64000;
        DAT_140e4192c = 0;
        param_1[7] = 64000;
        DAT_140e419bc = 1;
      }
    }
    goto LAB_1400ecdd6;
  }
  if (iVar16 == 1) {
    uVar21 = *(ushort *)(param_1 + 0x10);
    iVar16 = ((int)dVar26 & 0xffffU) - (uint)uVar21;
    iVar11 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar11 = iVar16;
    }
    iVar16 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar16 = iVar11;
    }
    uVar17 = (ushort)(int)dVar26;
    if (iVar16 < 1) {
      uVar18 = uVar21;
      if ((iVar16 < 0) && (uVar18 = uVar21 - 0x200, -0x200 < iVar16)) {
        uVar18 = uVar17;
      }
    }
    else {
      uVar18 = uVar17;
      if (0x1ff < iVar16) {
        uVar18 = uVar21 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar26 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90();
    fVar29 = DAT_14053ad7c;
    dVar26 = DAT_14053a0b0;
    uVar31 = (undefined4)DAT_140539f00;
    uVar32 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
    local_res8 = 0;
    local_res10 = 0;
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    do {
      uVar34 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
      iVar16 = 0;
      fVar30 = (float)param_1[10];
      fVar1 = (float)param_1[0xb];
      local_108[0] = fVar30 + DAT_14053ad10;
      local_108[1] = fVar1 - DAT_14053ac58;
      local_108[3] = fVar1 - DAT_14053ac58;
      local_f8 = fVar30 + fVar29;
      local_108[2] = fVar30 - DAT_14053ad14;
      local_f0 = fVar30 - fVar29;
      local_e8 = fVar30 + fVar29;
      local_e0 = fVar30 - fVar29;
      local_f4 = fVar1 + DAT_14053acbc;
      local_ec = fVar1 + DAT_14053acbc;
      local_e4 = fVar1 - DAT_14053ad1c;
      local_dc = fVar1 - DAT_14053ad1c;
      in_stack_fffffffffffffe98 = local_108[local_res10 * 2 + 1];
      fVar29 = local_108[local_res10 * 2];
      dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - in_stack_fffffffffffffe98),
                                     (double)(DAT_140e445d8 - fVar29));
      iVar11 = param_1[3];
      uVar19 = (uint)(dVar27 * DAT_14053aba0);
      iVar23 = iVar11 % 0x44c;
      dVar27 = DAT_140539e60;
      if ((-1 < iVar11) && (dVar27 = DAT_140539f18, iVar11 < 0x1e)) {
        dVar27 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a798 * dVar8 * dVar6);
        dVar27 = dVar27 * DAT_140539f10 + DAT_140539e60;
      }
      dVar28 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053ab68 * dVar8 * dVar6);
      uVar9 = DAT_140e41a50;
      dVar27 = dVar28 * DAT_140539ec8 + 0.0 + dVar27;
      auVar37._12_4_ = in_stack_fffffffffffffea8._12_4_;
      auVar37._0_8_ = in_stack_fffffffffffffea8._0_8_;
      if (iVar23 < 400) {
        if (local_res8 < 2) {
LAB_1400ec446:
          iVar11 = 1;
          if (DAT_140e419b8 == 0) {
            iVar11 = 0xa0;
          }
          else if (DAT_140e419b8 == 1) {
            iVar11 = 0x78;
          }
          else if (DAT_140e419b8 == 2) {
            iVar11 = 0x50;
          }
          else if (DAT_140e419b8 == 3) {
            iVar11 = 0x3c;
          }
          else if (DAT_140e419b8 == 4) {
            iVar11 = 0x32;
          }
          iVar16 = 1;
          if (DAT_140e419b8 == 0) {
            iVar16 = 0xf;
          }
          else if (DAT_140e419b8 == 1) {
            iVar16 = 0x15;
          }
          else if (DAT_140e419b8 == 2) {
            iVar16 = 0x1b;
          }
          else if (DAT_140e419b8 == 3) {
            iVar16 = 0x1e;
          }
          else if (DAT_140e419b8 == 4) {
            iVar16 = 0x21;
          }
          dVar28 = DAT_140539ff0;
          if (((DAT_140e419b8 != 0) && (dVar28 = DAT_14053a018, DAT_140e419b8 != 1)) &&
             ((dVar28 = DAT_14053a040, DAT_140e419b8 != 2 &&
              ((dVar28 = DAT_14053a070, DAT_140e419b8 != 3 && (dVar28 = dVar7, DAT_140e419b8 == 4)))
              ))) {
            dVar28 = DAT_14053a0d0;
          }
          iVar10 = (1 - local_res8) * iVar11 + 100;
          uVar21 = (ushort)uVar19;
          if ((iVar23 < iVar10) || (0x1b7 < iVar23)) {
            if (iVar23 == 0x208) {
              fVar30 = (float)param_1[0xb];
              uVar2 = param_1[1];
              fVar1 = (float)param_1[10];
              puVar12 = DAT_140e45d28;
              if (DAT_140e45d1c < 0x1000) {
                puVar12 = (undefined8 *)_malloc_base(0x60);
                if (puVar12 == (undefined8 *)0x0) {
                  MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
                }
                DAT_140e45d1c = DAT_140e45d1c + 1;
                bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
                *(float *)((longlong)puVar12 + 0x14) = fVar29 - fVar1;
                *(float *)(puVar12 + 3) = in_stack_fffffffffffffe98 - fVar30;
                *(float *)((longlong)puVar12 + 0x1c) = fVar29 - fVar1;
                *(float *)(puVar12 + 4) = in_stack_fffffffffffffe98 - fVar30;
                *puVar12 = 1;
                *(undefined4 *)(puVar12 + 1) = 0x31;
                *(undefined4 *)((longlong)puVar12 + 0xc) = uVar9;
                *(undefined4 *)(puVar12 + 2) = 0x23;
                *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
                puVar12[5] = 0;
                puVar12[6] = 0x4014000000000000;
                puVar12[7] = 0x4014000000000000;
                *(undefined4 *)(puVar12 + 8) = 0x28;
                *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
                *(undefined4 *)(puVar12 + 9) = 0xff;
                *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
                *(undefined4 *)(puVar12 + 10) = 0x80;
                *(undefined4 *)((longlong)puVar12 + 0x54) = uVar2;
                puVar12[0xb] = 0;
                if (bVar25) {
                  DAT_140e45d78 = puVar12;
                }
                if (DAT_140e45d28 != (undefined8 *)0x0) {
                  DAT_140e45d28[0xb] = puVar12;
                }
              }
              DAT_140e45d28 = puVar12;
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472c0);
              FUN_14018a340(DAT_140e472c0,1,1);
            }
            else if (iVar23 == 0x230) {
              if (local_res8 == 0) {
                *(ushort *)((longlong)param_1 + 0x42) = uVar21;
LAB_1400ec721:
                auVar38._8_4_ = 1;
                auVar38._0_8_ = auVar37._0_8_;
                auVar38._12_4_ = auVar37._12_4_;
                in_stack_fffffffffffffea0 = 0;
                FUN_1400709b0(2,0,fVar29,in_stack_fffffffffffffe98,
                              CONCAT22(uVar34,*(undefined2 *)((longlong)param_1 + 0x42)),0,
                              dVar28 + dVar26,auVar38._8_8_,iVar16 + -4,0x10000,0);
                uVar17 = *(ushort *)((longlong)param_1 + 0x42);
                iVar16 = (uVar19 & 0xffff) - (uint)uVar17;
                iVar11 = iVar16 + 0x10000;
                if (-0x8001 < iVar16) {
                  iVar11 = iVar16;
                }
                iVar16 = iVar11 + -0x10000;
                if (iVar11 < 0x8001) {
                  iVar16 = iVar11;
                }
                if (iVar16 < 1) {
                  if (iVar16 < 0) {
                    if (-0x80 < iVar16) {
                      *(ushort *)((longlong)param_1 + 0x42) = uVar21;
                      goto LAB_1400ec890;
                    }
                    uVar17 = uVar17 - 0x80;
                  }
                  *(ushort *)((longlong)param_1 + 0x42) = uVar17;
                }
                else if (iVar16 < 0x80) {
                  *(ushort *)((longlong)param_1 + 0x42) = uVar21;
                }
                else {
                  *(ushort *)((longlong)param_1 + 0x42) = uVar17 + 0x80;
                }
              }
              else if (local_res8 == 1) {
                *(ushort *)(param_1 + 0x11) = uVar21;
LAB_1400ec7ed:
                auVar39._8_4_ = 1;
                auVar39._0_8_ = auVar37._0_8_;
                auVar39._12_4_ = auVar37._12_4_;
                in_stack_fffffffffffffea0 = 0;
                FUN_1400709b0(2,0,fVar29,in_stack_fffffffffffffe98,
                              CONCAT22(uVar34,*(undefined2 *)(param_1 + 0x11)),0,dVar28 + dVar26,
                              auVar39._8_8_,iVar16 + -4,0x10000,0);
                uVar17 = *(ushort *)(param_1 + 0x11);
                iVar16 = (uVar19 & 0xffff) - (uint)uVar17;
                iVar11 = iVar16 + 0x10000;
                if (-0x8001 < iVar16) {
                  iVar11 = iVar16;
                }
                iVar16 = iVar11 + -0x10000;
                if (iVar11 < 0x8001) {
                  iVar16 = iVar11;
                }
                if (iVar16 < 1) {
                  uVar18 = uVar17;
                  if ((iVar16 < 0) && (uVar18 = uVar21, iVar16 < -0x7f)) {
                    uVar18 = uVar17 - 0x80;
                  }
                }
                else {
                  uVar18 = uVar21;
                  if (0x7f < iVar16) {
                    uVar18 = uVar17 + 0x80;
                  }
                }
                *(ushort *)(param_1 + 0x11) = uVar18;
              }
LAB_1400ec890:
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
            }
            else if (0x22f < iVar23) {
              uVar14 = iVar23 - 0x230U & 0x80000003;
              if ((int)uVar14 < 0) {
                uVar14 = (uVar14 - 1 | 0xfffffffc) + 1;
              }
              if (uVar14 == 0) {
                if (local_res8 == 0) goto LAB_1400ec721;
                if (local_res8 == 1) goto LAB_1400ec7ed;
                goto LAB_1400ec890;
              }
            }
          }
          else {
            uVar3 = (longlong)(iVar23 - iVar10) % (longlong)(iVar11 * 2);
            if ((int)uVar3 == 0) {
              auVar37._8_4_ = 1;
              in_stack_fffffffffffffea0 = 0;
              FUN_1400709b0(2,uVar3 & 0xffffffff,fVar29,in_stack_fffffffffffffe98,
                            CONCAT22(uVar34,uVar21),0,dVar28,auVar37._8_8_,iVar16,0x10000,0);
              goto LAB_1400ec890;
            }
          }
        }
        else {
          iVar11 = 1;
          if (DAT_140e419b8 == 0) {
            iVar11 = 0x78;
          }
          else if (DAT_140e419b8 == 1) {
            iVar11 = 0x5a;
          }
          else if (DAT_140e419b8 == 2) {
            iVar11 = 0x3c;
          }
          else if (DAT_140e419b8 == 3) {
            iVar11 = 0x28;
          }
          else if (DAT_140e419b8 == 4) {
            iVar11 = 0x24;
          }
          iVar10 = 1;
          iVar16 = (local_res8 - 2) * iVar11;
          iVar24 = iVar16 + 10;
          if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
LAB_1400ec12d:
            iVar10 = 0x172;
          }
          else if (DAT_140e419b8 == 2) {
            iVar10 = 0x15e;
          }
          else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) goto LAB_1400ec12d;
          if (DAT_140e419b8 == 0) {
            uVar31 = SUB84(DAT_14053a0f8,0);
            uVar32 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
          }
          else if (DAT_140e419b8 == 1) {
            uVar31 = SUB84(DAT_14053a138,0);
            uVar32 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
          }
          else if (DAT_140e419b8 == 2) {
            uVar31 = (undefined4)DAT_14053a178;
            uVar32 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
          }
          else if (DAT_140e419b8 == 3) {
            uVar31 = (undefined4)DAT_14053a1b8;
            uVar32 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
          }
          else {
            uVar31 = uVar33;
            uVar32 = (int)uVar5;
            if (DAT_140e419b8 == 4) {
              uVar31 = (undefined4)DAT_14053a1e8;
              uVar32 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
            }
          }
          if (((iVar24 <= iVar23) && (iVar23 < iVar10 + -0x28)) &&
             ((iVar23 - iVar24) % (iVar11 * 4) == 0)) {
            fVar30 = (float)param_1[0xb];
            uVar2 = param_1[1];
            fVar1 = (float)param_1[10];
            puVar12 = DAT_140e45d28;
            if (DAT_140e45d1c < 0x1000) {
              puVar12 = (undefined8 *)_malloc_base(0x60);
              if (puVar12 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
              *(float *)((longlong)puVar12 + 0x14) = fVar29 - fVar1;
              *(float *)(puVar12 + 3) = in_stack_fffffffffffffe98 - fVar30;
              *(float *)((longlong)puVar12 + 0x1c) = fVar29 - fVar1;
              *(float *)(puVar12 + 4) = in_stack_fffffffffffffe98 - fVar30;
              *puVar12 = 1;
              *(undefined4 *)(puVar12 + 1) = 0x31;
              *(undefined4 *)((longlong)puVar12 + 0xc) = uVar9;
              *(undefined4 *)(puVar12 + 2) = 0x23;
              *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
              puVar12[5] = 0;
              puVar12[6] = 0x4014000000000000;
              puVar12[7] = 0x4014000000000000;
              *(undefined4 *)(puVar12 + 8) = 0x28;
              *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
              *(undefined4 *)(puVar12 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
              *(undefined4 *)(puVar12 + 10) = 0x80;
              *(undefined4 *)((longlong)puVar12 + 0x54) = uVar2;
              puVar12[0xb] = 0;
              if (bVar25) {
                DAT_140e45d78 = puVar12;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar12;
              }
            }
            DAT_140e45d28 = puVar12;
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
            FUN_14018a340(DAT_140e472c0,1,1);
          }
          iVar16 = iVar16 + 0x32;
          if (((iVar16 <= iVar23) && (iVar23 < iVar10)) && ((iVar23 - iVar16) % (iVar11 * 4) == 0))
          {
            auVar36._12_4_ = in_stack_fffffffffffffea8._12_4_;
            auVar36._0_8_ = in_stack_fffffffffffffea8._0_8_;
            auVar36._8_4_ = 1;
            in_stack_fffffffffffffea0 = 0;
            FUN_14006c2f0(0x12,0xe,fVar29,in_stack_fffffffffffffe98,
                          CONCAT22(uVar34,(short)local_res8 << 0xf),0,CONCAT44(uVar32,uVar31),
                          auVar36._8_8_,0);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
          }
          uVar31 = (undefined4)DAT_140539f00;
          uVar32 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
        }
      }
      else if (iVar23 < 600) {
        if (local_res8 < 2) goto LAB_1400ec446;
      }
      else if (0x275 < iVar23) {
        iVar11 = iVar23 + -0x276;
        iVar10 = 1;
        if (DAT_140e419b8 == 0) {
          iVar10 = 0xc;
        }
        else if (DAT_140e419b8 == 1) {
          iVar10 = 7;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar10 = 6;
        }
        else if (DAT_140e419b8 == 4) {
          iVar10 = 5;
        }
        dVar28 = DAT_14053a070;
        if ((((DAT_140e419b8 != 0) && (dVar28 = dVar26, DAT_140e419b8 != 1)) &&
            (dVar28 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
           ((dVar28 = DAT_14053a0f8, DAT_140e419b8 != 3 && (dVar28 = dVar7, DAT_140e419b8 == 4)))) {
          dVar28 = DAT_14053a138;
        }
        local_118[0] = 0x4000;
        local_118[1] = 0x4000;
        local_118[2] = 0;
        local_118[3] = -0x8000;
        local_118[4] = 0;
        local_118[5] = -0x8000;
        dVar28 = (double)iVar11 * DAT_140539dc8 + dVar28;
        sVar4 = (short)iVar11;
        if (local_res8 < 2) {
          if ((iVar23 < 0x42e) && (iVar11 % (iVar10 + 2) == 0)) {
            sVar22 = local_118[local_res10];
            iVar11 = iVar16;
            do {
              auVar40._12_4_ = in_stack_fffffffffffffea8._12_4_;
              auVar40._0_8_ = in_stack_fffffffffffffea8._0_8_;
              auVar40._8_4_ = 1;
              in_stack_fffffffffffffea8._8_8_ = auVar40._8_8_;
              in_stack_fffffffffffffea8._0_8_ = dVar28;
              FUN_14006c2f0(3,0,fVar29,in_stack_fffffffffffffe98,
                            (short)iVar11 * -0x8000 + sVar4 * 200 + sVar22,0,dVar28,
                            in_stack_fffffffffffffea8._8_8_,0);
              iVar11 = iVar11 + 1;
            } while (iVar11 < 2);
            iVar11 = iVar16;
            do {
              auVar41._12_4_ = in_stack_fffffffffffffea8._12_4_;
              auVar41._0_8_ = in_stack_fffffffffffffea8._0_8_;
              auVar41._8_4_ = 1;
              in_stack_fffffffffffffea8._8_8_ = auVar41._8_8_;
              in_stack_fffffffffffffea0 = 0;
              FUN_14006c2f0(3,0,fVar29,in_stack_fffffffffffffe98,
                            (short)iVar11 * -0x8000 + sVar22 + sVar4 * -200,0,dVar28,
                            in_stack_fffffffffffffea8._8_8_,0);
              iVar11 = iVar11 + 1;
            } while (iVar11 < 2);
            if (2 < DAT_140e419b8) {
              dVar26 = dVar28 - (double)CONCAT44(uVar32,uVar31);
              iVar11 = iVar16;
              do {
                auVar42._12_4_ = in_stack_fffffffffffffea8._12_4_;
                auVar42._0_8_ = in_stack_fffffffffffffea8._0_8_;
                auVar42._8_4_ = 1;
                in_stack_fffffffffffffea8._8_8_ = auVar42._8_8_;
                in_stack_fffffffffffffea8._0_8_ = dVar26;
                FUN_14006c2f0(3,0,fVar29,in_stack_fffffffffffffe98,
                              (short)iVar11 * -0x8000 + sVar4 * 200 + sVar22,0,dVar26,
                              in_stack_fffffffffffffea8._8_8_,0);
                iVar11 = iVar11 + 1;
              } while (iVar11 < 2);
              dVar28 = dVar28 - (double)CONCAT44(uVar32,uVar31);
              do {
                auVar43._12_4_ = in_stack_fffffffffffffea8._12_4_;
                auVar43._0_8_ = in_stack_fffffffffffffea8._0_8_;
                auVar43._8_4_ = 1;
                in_stack_fffffffffffffea8._8_8_ = auVar43._8_8_;
                in_stack_fffffffffffffea8._0_8_ = dVar28;
                in_stack_fffffffffffffea0 = 0;
                FUN_14006c2f0(3,0,fVar29,in_stack_fffffffffffffe98,
                              (short)iVar16 * -0x8000 + sVar22 + sVar4 * -200,0,dVar28,
                              in_stack_fffffffffffffea8._8_8_,0);
                iVar16 = iVar16 + 1;
              } while (iVar16 < 2);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        else if ((iVar23 < 0x42e) && ((int)((longlong)iVar11 % (longlong)iVar10) == 0)) {
          auVar44._8_4_ = 1;
          auVar44._0_8_ = auVar37._0_8_;
          auVar44._12_4_ = auVar37._12_4_;
          auVar45._8_8_ = auVar44._8_8_;
          auVar45._0_8_ = dVar28;
          sVar22 = local_118[local_res10];
          sVar20 = sVar4 * 0xd2 + sVar22;
          FUN_14006c2f0(5,(longlong)iVar11 % (longlong)iVar10 & 0xffffffff,fVar29,
                        in_stack_fffffffffffffe98,CONCAT22(uVar34,sVar20),0,dVar28,auVar45._8_8_,0);
          sVar22 = sVar22 + sVar4 * -0xd2;
          auVar46._12_4_ = auVar45._12_4_;
          auVar46._0_8_ = auVar45._0_8_;
          auVar46._8_4_ = 1;
          auVar47._8_8_ = auVar46._8_8_;
          auVar47._0_8_ = dVar28;
          in_stack_fffffffffffffea0 = 0;
          FUN_14006c2f0(5,0,fVar29,in_stack_fffffffffffffe98,sVar22,0,dVar28,auVar47._8_8_,0);
          if (2 < DAT_140e419b8) {
            dVar28 = dVar28 - (double)CONCAT44(uVar32,uVar31);
            auVar48._12_4_ = auVar47._12_4_;
            auVar48._0_8_ = auVar47._0_8_;
            auVar48._8_4_ = 1;
            auVar49._8_8_ = auVar48._8_8_;
            auVar49._0_8_ = dVar28;
            FUN_14006c2f0(5,0,fVar29,in_stack_fffffffffffffe98,sVar20,0,dVar28,auVar49._8_8_,0);
            auVar50._12_4_ = auVar49._12_4_;
            auVar50._0_8_ = auVar49._0_8_;
            auVar50._8_4_ = 1;
            in_stack_fffffffffffffea0 = 0;
            FUN_14006c2f0(5,0,fVar29,in_stack_fffffffffffffe98,sVar22,0,dVar28,auVar50._8_8_,0);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      in_stack_fffffffffffffea8._8_4_ = SUB84(dVar27,0);
      in_stack_fffffffffffffea8._0_8_ = dVar27;
      in_stack_fffffffffffffea8._12_4_ = (int)((ulonglong)dVar27 >> 0x20);
      in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffff0000;
      FUN_1400c8410(DAT_140e44740,0x1f,8,fVar29,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,
                    in_stack_fffffffffffffea8,0xff,0xff,0xff,0xc0,1,0);
      local_res8 = local_res8 + 1;
      local_res10 = local_res10 + 1;
      fVar29 = DAT_14053ad7c;
      dVar26 = DAT_14053a0b0;
    } while ((int)local_res8 < 6);
    goto LAB_1400ecdd6;
  }
  if (iVar16 != 2) goto LAB_1400ecdd6;
  iVar16 = param_1[3];
  iVar23 = iVar11;
  if (iVar16 < 0x5a) {
LAB_1400ebb0f:
    if (iVar16 < 0x96) {
      iVar11 = iVar23;
    }
    puVar12 = DAT_140e45d28;
    if (iVar16 == 1) {
      uVar33 = param_1[0xb];
      uVar31 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar12 = (undefined8 *)_malloc_base(0x60);
        if (puVar12 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar12 + 0x14) = uVar31;
        *(undefined4 *)(puVar12 + 3) = uVar33;
        *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar31;
        *(undefined4 *)(puVar12 + 4) = uVar33;
        *puVar12 = 1;
        puVar12[1] = 0x36;
        *(undefined4 *)(puVar12 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
        puVar12[5] = 0;
        puVar12[6] = 0x3ff0000000000000;
        puVar12[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar12 + 8) = 0;
        *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
        *(undefined4 *)(puVar12 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
        puVar12[10] = 0xff;
        puVar12[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar12;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar12;
        }
      }
    }
  }
  else {
    iVar23 = 0xff;
    if (iVar16 < 100) {
      dVar26 = (double)FUN_140332d90(((double)iVar16 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar11 = (int)(dVar26 * DAT_14053a5f8);
      puVar12 = DAT_140e45d28;
    }
    else {
      if (0x95 < iVar16) goto LAB_1400ebb0f;
      dVar26 = (double)FUN_140332d90(((double)iVar16 - DAT_14053a380) * DAT_14053a670 *
                                     DAT_14053a020 * DAT_140539d28);
      puVar12 = DAT_140e45d28;
      if (iVar16 < 0x96) {
        iVar11 = (int)(dVar26 * DAT_14053a5f8);
      }
    }
  }
  DAT_140e45d28 = puVar12;
  iVar16 = param_1[3];
  if (iVar16 < 0x5a) {
    FUN_14007ac00(param_1);
    iVar16 = param_1[3];
    param_1[0xb] = (float)iVar16 * _DAT_140539ccc + (float)param_1[0xb];
  }
  if (iVar16 == 0x5a) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
    FUN_14018a340(DAT_140e472a0,1,1);
    uVar33 = param_1[0xb];
    uVar31 = param_1[10];
    puVar12 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar12 = (undefined8 *)_malloc_base(0x60);
      if (puVar12 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar12 + 0x14) = uVar31;
      *(undefined4 *)(puVar12 + 3) = uVar33;
      *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar31;
      *(undefined4 *)(puVar12 + 4) = uVar33;
      *puVar12 = 1;
      puVar12[1] = 0x11;
      *(undefined4 *)(puVar12 + 2) = 0x28;
      *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
      puVar12[5] = 0;
      puVar12[6] = 0x3ff0000000000000;
      puVar12[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar12 + 8) = 0;
      *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
      *(undefined4 *)(puVar12 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0;
      if (bVar25) {
        DAT_140e45d78 = puVar12;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar12;
      }
    }
    DAT_140e45d28 = puVar12;
    DAT_140e46a08 = DAT_140e418c8;
  }
  uVar33 = DAT_140e41ab8;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
  bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar13 = uVar33;
  puVar13[1] = 0x4e;
  *(undefined8 *)(puVar13 + 2) = 5;
  puVar13[4] = 0;
  *(undefined2 *)(puVar13 + 5) = 0;
  *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = iVar11;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  if (bVar25) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  DAT_140e46c88 = puVar13;
  if (param_1[3] == 0x96) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
LAB_1400ecdd6:
  if (((int)param_1[5] < 2) || ((param_1[5] == 2 && ((int)param_1[3] < 100)))) {
    auVar51._12_4_ = in_stack_fffffffffffffea8._12_4_;
    auVar51._0_8_ = in_stack_fffffffffffffea8._0_8_;
    auVar51._8_4_ = 0x6f;
    auVar52._4_12_ = auVar51._4_12_;
    auVar52._0_4_ = 0x70;
    uVar19 = 0;
    iVar11 = FUN_1400c9580(param_1[3],0,6,4,0x6e,0x6f,auVar52);
    uVar31 = DAT_140e44984;
    fVar29 = DAT_14053ad2c;
    uVar33 = param_1[10];
    fVar30 = (float)param_1[0xb] - DAT_14053ad2c;
    puVar13 = (undefined4 *)_malloc_base(0x48);
    if (puVar13 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d08 = DAT_140e46d08 + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar13[3] = uVar33;
    puVar13[4] = fVar30;
    *puVar13 = uVar31;
    puVar13[1] = 0x1e;
    puVar13[2] = 7;
    *(undefined2 *)(puVar13 + 5) = 0;
    *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
    puVar13[10] = 0xff;
    puVar13[0xb] = 0xff;
    puVar13[0xc] = 0xff;
    puVar13[0xd] = 0xff;
    *(undefined8 *)(puVar13 + 0xe) = 1;
    *(undefined8 *)(puVar13 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar13;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
    }
    uVar31 = DAT_140e44994;
    fVar30 = (float)param_1[0xb];
    uVar33 = param_1[10];
    DAT_140e46c88 = puVar13;
    puVar13 = (undefined4 *)_malloc_base(0x48);
    if (puVar13 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d10 = DAT_140e46d10 + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar13[3] = uVar33;
    puVar13[4] = fVar30 - fVar29;
    *puVar13 = uVar31;
    puVar13[1] = 0x20;
    puVar13[2] = 7;
    *(undefined2 *)(puVar13 + 5) = 0;
    *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
    puVar13[10] = 0xff;
    puVar13[0xb] = 0xff;
    puVar13[0xc] = 0xff;
    puVar13[0xd] = 0xff;
    *(undefined8 *)(puVar13 + 0xe) = 1;
    *(undefined8 *)(puVar13 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar13;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
    }
    DAT_140e46c88 = puVar13;
    if (param_1[5] == 2) {
      uVar19 = 0;
      iVar11 = FUN_1400c9580(param_1[3],0,5,2,0x71,0x72);
    }
    uVar33 = param_1[0xb];
    uVar31 = param_1[10];
    uVar32 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4);
    puVar13 = (undefined4 *)_malloc_base(0x48);
    if (puVar13 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d0c = DAT_140e46d0c + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar13[3] = uVar31;
    puVar13[4] = uVar33;
    *puVar13 = uVar32;
    puVar13[1] = 0x1f;
    puVar13[2] = 7;
    *(undefined2 *)(puVar13 + 5) = 0;
    *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
    puVar13[10] = 0xff;
    puVar13[0xb] = 0xff;
    puVar13[0xc] = 0xff;
    puVar13[0xd] = 0xc0;
    *(undefined8 *)(puVar13 + 0xe) = 1;
    *(undefined8 *)(puVar13 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar13;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
    }
    uVar31 = DAT_140e44998;
    fVar30 = (float)param_1[0xb] - _DAT_14053ae84;
    uVar33 = param_1[10];
    DAT_140e46c88 = puVar13;
    puVar13 = (undefined4 *)_malloc_base(0x48);
    if (puVar13 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d10 = DAT_140e46d10 + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar13[3] = uVar33;
    puVar13[4] = fVar30;
    *puVar13 = uVar31;
    puVar13[1] = 0x20;
    puVar13[2] = 7;
    *(undefined2 *)(puVar13 + 5) = 0;
    *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
    puVar13[10] = 0xff;
    puVar13[0xb] = 0xff;
    puVar13[0xc] = 0xff;
    puVar13[0xd] = 0xff;
    *(undefined8 *)(puVar13 + 0xe) = 1;
    *(undefined8 *)(puVar13 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar13;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
    }
    DAT_140e46c88 = puVar13;
    dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053abc0 * dVar8 *
                                   dVar6);
    FUN_1400c8410(DAT_140e4509c,0x1c,8,param_1[10],(float)param_1[0xb] + fVar29,uVar19 & 0xffff0000,
                  dVar7,dVar26 * DAT_140539e60 + dVar7,0xff,0xff,0xff,0xe1,1,0);
    if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x12) * 0x12) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472f8);
      FUN_14018a340(DAT_140e472f8,1,1);
    }
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


