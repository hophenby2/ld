// Function: FUN_1400e8d20 @ 1400e8d20
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e8d20(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  double dVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  ushort uVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  double dVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  double dVar27;
  float fVar28;
  uint in_stack_ffffffffffffff10;
  undefined4 uVar29;
  undefined1 in_stack_ffffffffffffff18 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  
  dVar20 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar21 = DAT_14053aba0;
  uVar17 = 0;
  dVar20 = dVar20 * DAT_14053aba0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar30._12_4_ = in_stack_ffffffffffffff18._12_4_;
    auVar30._0_8_ = in_stack_ffffffffffffff18._0_8_;
    auVar30._8_4_ = param_1[0x14];
    in_stack_ffffffffffffff18._8_8_ = auVar30._8_8_;
    in_stack_ffffffffffffff18._0_8_ = DAT_14053a4f0;
    in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_ffffffffffffff10,DAT_14053a4f0,
               in_stack_ffffffffffffff18._8_8_,1,0);
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 0xf0;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar18 = DAT_140e418c8;
  dVar6 = DAT_14053a020;
  dVar27 = DAT_140539f40;
  dVar22 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar15 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
    uVar11 = DAT_1407c7798 * 0x1bc + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar10 >> 0xb ^ uVar15) >> 8 ^ uVar10 ^ uVar15) % 0xc9 + 0x104);
    uVar15 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x79 + 0x3c);
  }
  iVar7 = param_1[5];
  if (iVar7 != 0) {
    if (iVar7 == 1) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar12 = ((int)dVar20 & 0xffffU) - (uint)uVar1;
      iVar7 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar7 = iVar12;
      }
      iVar12 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar12 = iVar7;
      }
      uVar13 = (ushort)(int)dVar20;
      if (iVar12 < 1) {
        uVar14 = uVar1;
        if ((iVar12 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar12)) {
          uVar14 = uVar13;
        }
      }
      else {
        uVar14 = uVar13;
        if (0x1ff < iVar12) {
          uVar14 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar20 = (double)FUN_1403307c0();
      fVar28 = (float)(dVar20 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar28;
      dVar22 = (double)FUN_140332d90();
      auVar30 = _DAT_14053bb20;
      iVar7 = param_1[3];
      uVar25 = (undefined4)DAT_14053bb20;
      uVar26 = DAT_14053bb20._4_4_;
      dVar20 = (double)DAT_14053bb20;
      fVar23 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar23;
      if (0x27 < iVar7) {
        dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),
                                       (double)(DAT_140e445d8 - fVar28));
        uVar15 = DAT_14053ac2c;
        dVar22 = DAT_140539fe8;
        iVar12 = 1;
        if (DAT_140e419b8 == 0) {
          iVar12 = 200;
        }
        else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
                (DAT_140e419b8 == 4)) {
          iVar12 = 0xa0;
        }
        uVar10 = 1;
        if (DAT_140e419b8 == 0) {
          uVar10 = 0xc;
        }
        else if (DAT_140e419b8 == 1) {
          uVar10 = 0xf;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar10 = 0x12;
        }
        else if (DAT_140e419b8 == 4) {
          uVar10 = 0x14;
        }
        if (DAT_140e419b8 == 0) {
          uVar25 = (undefined4)DAT_14053a088;
          uVar26 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
        }
        else if (DAT_140e419b8 == 1) {
          uVar25 = (undefined4)DAT_14053a0d0;
          uVar26 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
        }
        else if (DAT_140e419b8 == 2) {
          uVar25 = (undefined4)DAT_14053a0f8;
          uVar26 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
        }
        else if (DAT_140e419b8 == 3) {
          uVar25 = (undefined4)DAT_14053a118;
          uVar26 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
        }
        else if (DAT_140e419b8 == 4) {
          uVar25 = (undefined4)DAT_14053a160;
          uVar26 = (undefined4)((ulonglong)DAT_14053a160 >> 0x20);
        }
        if ((0x3f < iVar7) && ((iVar7 + -0x40) % iVar12 == 0)) {
          dVar6 = (double)CONCAT44(uVar26,uVar25) - dVar20;
          uVar18 = uVar17;
          do {
            auVar31._12_4_ = in_stack_ffffffffffffff18._12_4_;
            auVar31._0_8_ = in_stack_ffffffffffffff18._0_8_;
            auVar31._8_4_ = 1;
            dVar24 = (double)CONCAT44(uVar26,uVar25) -
                     (double)(int)uVar18 * (dVar6 / (double)uVar10);
            in_stack_ffffffffffffff18._8_8_ = auVar31._8_8_;
            in_stack_ffffffffffffff18._0_8_ = dVar24;
            in_stack_ffffffffffffff10 = uVar15;
            FUN_1400709b0(10,0,param_1[10],param_1[0xb],(int)(dVar27 * dVar21) & 0xffff,uVar15,
                          dVar24,in_stack_ffffffffffffff18._8_8_,2,uVar17,0);
            if ((2 < DAT_140e419b8) && (uVar18 < uVar10)) {
              auVar32._12_4_ = in_stack_ffffffffffffff18._12_4_;
              auVar32._0_8_ = in_stack_ffffffffffffff18._0_8_;
              auVar32._8_4_ = 1;
              dVar24 = dVar6 - (((double)CONCAT44(uVar26,uVar25) - dVar22) / (double)uVar10) *
                               (double)(int)uVar18;
              in_stack_ffffffffffffff18._8_8_ = auVar32._8_8_;
              in_stack_ffffffffffffff18._0_8_ = dVar24;
              in_stack_ffffffffffffff10 = uVar15;
              FUN_1400709b0(10,0,param_1[10],param_1[0xb],(int)(dVar27 * dVar21) & 0xffff,uVar15,
                            dVar24,in_stack_ffffffffffffff18._8_8_,2,uVar17 + 0x5dc,0);
            }
            uVar18 = uVar18 + 1;
            uVar17 = uVar17 + 0x10000 / uVar10;
          } while ((int)uVar18 <= (int)uVar10);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          uVar18 = DAT_140e418c8;
        }
      }
      if ((int)uVar18 % 0x28 < 0xb) {
        dVar21 = (double)FUN_140332d90(((double)((int)uVar18 % 0x28) - 0.0) * DAT_14053aa88 *
                                       DAT_14053a020 * DAT_140539d28);
        dVar20 = dVar21 * DAT_14053b058 + dVar20;
      }
      in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
      FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],param_1[0xb],in_stack_ffffffffffffff10,auVar30,
                    0xff,0xff,0xff,0xff,1,0);
      auVar3._8_4_ = SUB84(dVar20,0);
      auVar3._0_8_ = dVar20;
      auVar3._12_4_ = (int)((ulonglong)dVar20 >> 0x20);
      FUN_1400c8410(DAT_140e44960,0x1b,7,param_1[10],param_1[0xb],
                    in_stack_ffffffffffffff10 & 0xffff0000,auVar3,0xff,0xff,0xff,0xff,1,0);
      if (param_1[3] == 0x4b0) {
        param_1[3] = 0;
      }
      goto LAB_1400e9da2;
    }
    if (iVar7 != 2) goto LAB_1400e9da2;
    iVar7 = param_1[3];
    iVar12 = 0;
    if (iVar7 < 0x5a) {
LAB_1400e9095:
      iVar16 = 0;
      if (iVar7 < 0x96) {
        iVar16 = iVar12;
      }
      puVar8 = DAT_140e45d28;
      if (iVar7 == 1) {
        uVar25 = param_1[0xb];
        uVar26 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar8 = (undefined8 *)_malloc_base(0x60);
          if (puVar8 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar8 + 0x14) = uVar26;
          *(undefined4 *)(puVar8 + 3) = uVar25;
          *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar26;
          *(undefined4 *)(puVar8 + 4) = uVar25;
          *puVar8 = 1;
          puVar8[1] = 0x36;
          *(undefined4 *)(puVar8 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
          puVar8[5] = 0;
          puVar8[6] = 0x3ff0000000000000;
          puVar8[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar8 + 8) = 0;
          *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
          *(undefined4 *)(puVar8 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
          puVar8[10] = 0xff;
          puVar8[0xb] = 0;
          if (bVar19) {
            DAT_140e45d78 = puVar8;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar8;
          }
        }
      }
    }
    else {
      iVar12 = 0xff;
      if (iVar7 < 100) {
        dVar21 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar16 = (int)(dVar21 * DAT_14053a5f8);
        puVar8 = DAT_140e45d28;
      }
      else {
        if (0x95 < iVar7) goto LAB_1400e9095;
        dVar21 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a380) * DAT_14053a670 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar16 = 0;
        puVar8 = DAT_140e45d28;
        if (iVar7 < 0x96) {
          iVar16 = (int)(dVar21 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar8;
    iVar7 = param_1[3];
    if (iVar7 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar7 = param_1[3];
      param_1[0xb] = (float)iVar7 * _DAT_140539ccc + (float)param_1[0xb];
    }
    if (iVar7 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar25 = param_1[0xb];
      uVar26 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar26;
        *(undefined4 *)(puVar8 + 3) = uVar25;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar26;
        *(undefined4 *)(puVar8 + 4) = uVar25;
        *puVar8 = 1;
        puVar8[1] = 0x11;
        *(undefined4 *)(puVar8 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar19) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      DAT_140e46a08 = DAT_140e418c8;
    }
    uVar25 = DAT_140e41ab8;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar25;
    puVar9[1] = 0x4e;
    *(undefined8 *)(puVar9 + 2) = 5;
    puVar9[4] = 0;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = iVar16;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar17 = DAT_140e418c8;
    DAT_140e46c88 = puVar9;
    if ((int)param_1[3] < 100) {
      dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053aa80 * dVar6 *
                                     dVar22);
      dVar20 = DAT_140539f40;
      dVar27 = dVar21 * DAT_140539e60 + DAT_140539f40;
      dVar21 = DAT_140539f40;
      if ((int)uVar17 % 5 < 6) {
        dVar21 = (double)FUN_140332d90(((double)((int)uVar17 % 5) - 0.0) * _DAT_14053ab30 * dVar6 *
                                       dVar22);
        dVar21 = dVar21 * _DAT_14053b068 + dVar20;
      }
      in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
      FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],param_1[0xb],in_stack_ffffffffffffff10,dVar27,
                    dVar20,0xff,0xff,0xff,0xff,1,0);
      auVar2._8_4_ = SUB84(dVar21,0);
      auVar2._0_8_ = dVar21;
      auVar2._12_4_ = (int)((ulonglong)dVar21 >> 0x20);
      FUN_1400c8410(DAT_140e44960,0x1b,7,param_1[10],param_1[0xb],
                    in_stack_ffffffffffffff10 & 0xffff0000,auVar2,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[3] == 0x96) {
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
    goto LAB_1400e9da2;
  }
  iVar7 = param_1[3];
  if (0x3b < iVar7) {
    uVar17 = 0xff;
  }
  if ((iVar7 < 0x3c) || (0xb3 < iVar7)) {
    iVar12 = (iVar7 >> 0x1f & 0xffffff01U) + 0xff;
    if ((-1 < iVar7) && (iVar7 < 0x3c)) {
      dVar21 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar12 = (int)(dVar21 * DAT_14053a5f8);
      goto LAB_1400e99c8;
    }
    dVar21 = DAT_140539ee0;
    if ((-1 < iVar7) && (dVar21 = DAT_140539f40, iVar7 < 0xb4)) goto LAB_1400e99c8;
  }
  else {
    dVar21 = (double)FUN_140332d90(((double)iVar7 - DAT_14053a3a0) * DAT_14053a4d8 * DAT_14053a020 *
                                   DAT_140539d28);
    iVar12 = (iVar7 >> 0x1f & 0xffffff01U) + 0xff;
    uVar17 = (uint)(dVar21 * DAT_14053a5f8);
LAB_1400e99c8:
    dVar21 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a438 * dVar6 * dVar22);
    dVar21 = dVar21 * DAT_140539f18 + DAT_140539ee0;
  }
  dVar20 = dVar21;
  if ((int)uVar18 % 0x28 < 0xb) {
    dVar20 = (double)FUN_140332d90(((double)((int)uVar18 % 0x28) - 0.0) * DAT_14053aa88 * dVar6 *
                                   dVar22);
    dVar20 = dVar20 * dVar21 * DAT_14053b058 + dVar21;
  }
  if (param_1[3] == 0) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
    FUN_14018a340(DAT_140e472d8,1,1);
  }
  iVar7 = param_1[3];
  uVar18 = iVar7 >> 0x1f & 500;
  if ((-1 < iVar7) && (iVar7 < 0xf0)) {
    dVar22 = (double)FUN_140332d90(((double)iVar7 - 0.0) * _DAT_14053a3c8 * dVar6 * dVar22);
    uVar18 = 500 - (int)(dVar22 * DAT_14053a758);
  }
  param_1[0xb] = (float)(int)uVar18 + (float)param_1[0xd];
  uVar25 = DAT_14053adf4;
  if (iVar7 == 0xb4) {
    auVar33._12_4_ = in_stack_ffffffffffffff18._12_4_;
    auVar33._0_8_ = in_stack_ffffffffffffff18._0_8_;
    auVar33._8_4_ = 0x1e;
    auVar34._8_8_ = auVar33._8_8_;
    auVar34._0_8_ = dVar27;
    uVar26 = CONCAT22((short)(in_stack_ffffffffffffff10 >> 0x10),0x4000);
    DAT_1407c77a0 = DAT_1407c779c;
    stage_entity_spawn_candidate
              (200,7000,0xf,DAT_14053accc,DAT_14053adf4,uVar26,dVar27,auVar34._8_8_,1,0);
    auVar35._12_4_ = auVar34._12_4_;
    auVar35._0_8_ = auVar34._0_8_;
    auVar35._8_4_ = 0x1e;
    auVar36._8_8_ = auVar35._8_8_;
    auVar36._0_8_ = dVar27;
    uVar29 = CONCAT22((short)((uint)uVar26 >> 0x10),0x4000);
    stage_entity_spawn_candidate(200,7000,0xf,DAT_14053b360,uVar25,uVar29,dVar27,auVar36._8_8_,1,0);
    uVar26 = DAT_14053add4;
    auVar37._12_4_ = auVar36._12_4_;
    auVar37._0_8_ = auVar36._0_8_;
    auVar37._8_4_ = 0x1e;
    auVar38._8_8_ = auVar37._8_8_;
    auVar38._0_8_ = dVar27;
    uVar25 = CONCAT22((short)((uint)uVar29 >> 0x10),0x4000);
    stage_entity_spawn_candidate
              (200,7000,0xf,DAT_14053ad70,DAT_14053add4,uVar25,dVar27,auVar38._8_8_,1,0);
    auVar39._12_4_ = auVar38._12_4_;
    auVar39._0_8_ = auVar38._0_8_;
    auVar39._8_4_ = 0x1e;
    auVar40._8_8_ = auVar39._8_8_;
    auVar40._0_8_ = dVar27;
    uVar29 = CONCAT22((short)((uint)uVar25 >> 0x10),0x4000);
    stage_entity_spawn_candidate(200,7000,0xf,DAT_14053b3ac,uVar26,uVar29,dVar27,auVar40._8_8_,1,0);
    uVar25 = DAT_14053ad90;
    auVar41._12_4_ = auVar40._12_4_;
    auVar41._0_8_ = auVar40._0_8_;
    auVar41._8_4_ = 0x1e;
    auVar42._8_8_ = auVar41._8_8_;
    auVar42._0_8_ = dVar27;
    uVar29 = CONCAT22((short)((uint)uVar29 >> 0x10),0x4000);
    stage_entity_spawn_candidate(200,7000,0xf,uVar26,DAT_14053ad90,uVar29,dVar27,auVar42._8_8_,1,0);
    auVar43._12_4_ = auVar42._12_4_;
    auVar43._0_8_ = auVar42._0_8_;
    auVar43._8_4_ = 0x1e;
    in_stack_ffffffffffffff10 = CONCAT22((short)((uint)uVar29 >> 0x10),0x4000);
    stage_entity_spawn_candidate
              (200,7000,0xf,DAT_14053b3e0,uVar25,in_stack_ffffffffffffff10,dVar27,auVar43._8_8_,1,0)
    ;
  }
  auVar4._8_4_ = SUB84(dVar21,0);
  auVar4._0_8_ = dVar21;
  auVar4._12_4_ = (int)((ulonglong)dVar21 >> 0x20);
  in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
  FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],param_1[0xb],in_stack_ffffffffffffff10,auVar4,
                uVar17,uVar17,uVar17,iVar12,1,0);
  auVar5._8_4_ = SUB84(dVar20,0);
  auVar5._0_8_ = dVar20;
  auVar5._12_4_ = (int)((ulonglong)dVar20 >> 0x20);
  FUN_1400c8410(DAT_140e44960,0x1b,7,param_1[10],param_1[0xb],in_stack_ffffffffffffff10 & 0xffff0000
                ,auVar5,uVar17,uVar17,uVar17,iVar12,1,0);
  if (param_1[3] == 0xf0) {
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 0;
    param_1[3] = 0;
    DAT_140e41b0c = 70000;
    DAT_140e4430c = 0x708;
    DAT_140e4192c = 0;
    param_1[7] = 70000;
    DAT_140e419bc = 1;
  }
LAB_1400e9da2:
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


