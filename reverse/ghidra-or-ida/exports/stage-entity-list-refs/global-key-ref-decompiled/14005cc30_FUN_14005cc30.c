// Function: FUN_14005cc30 @ 14005cc30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005cc30(undefined4 *param_1,undefined8 param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  undefined8 uVar6;
  float fVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ushort uVar18;
  ushort uVar19;
  uint uVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  undefined1 auVar27 [16];
  int local_res8;
  undefined4 local_res10;
  undefined4 uVar29;
  undefined2 uVar30;
  uint uVar31;
  undefined4 uVar32;
  undefined8 in_stack_fffffffffffffe58;
  undefined8 in_stack_fffffffffffffe60;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined1 local_138 [12];
  undefined4 local_128;
  undefined4 local_f8;
  undefined1 local_d8 [152];
  undefined1 auVar28 [12];
  
  uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  iVar10 = 0;
  local_res10 = 0;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == 0)) {
    auVar28._8_4_ = 0;
    auVar28._0_8_ = local_138._4_8_;
    local_f8 = param_3;
  }
  else {
    auVar27._12_4_ = 0;
    auVar27._0_12_ = local_138;
    lVar11 = DAT_140e45d80;
    do {
      if (*(int *)(lVar11 + 4) == DAT_140e44308) {
        auVar27 = *(undefined1 (*) [16])(lVar11 + 0x10);
        local_128 = *(undefined4 *)(lVar11 + 0x20);
        local_f8 = *(undefined4 *)(lVar11 + 0x50);
      }
      auVar28 = auVar27._4_12_;
      lVar11 = *(longlong *)(lVar11 + 0x60);
    } while (lVar11 != 0);
    local_res10 = auVar27._12_4_;
  }
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]),local_f8);
  dVar22 = dVar22 * DAT_14053aba0;
  uVar31 = 0;
  uVar30 = 0;
  iVar9 = FUN_1400c9580(param_1[3],0,5,3,0xd6,0xd7,CONCAT44(uVar29,0xd8));
  if ((auVar28._0_4_ == 0x3c) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    uVar33 = CONCAT44(uVar32,param_1[0x14]);
    uVar29 = param_1[0xb];
    uVar31 = uVar31 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],uVar29,uVar31,DAT_14053a4f0,uVar33,1,0);
    uVar30 = (undefined2)((uint)uVar29 >> 0x10);
    uVar32 = (undefined4)((ulonglong)uVar33 >> 0x20);
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  uVar6 = _UNK_14053bb28;
  uVar33 = _DAT_14053bb20;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar20 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar14 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
    uVar20 = uVar20 * 0x800 ^ uVar20;
    uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
    uVar15 = DAT_1407c7798 * 0x457 + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar14 >> 0xb ^ uVar20) >> 8 ^ uVar20 ^ uVar14) % 0xf1 + 0xf0);
    uVar20 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar20 = uVar20 * 0x800 ^ uVar20;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar20) >> 8 ^ DAT_140e9fd18 ^ uVar20;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  iVar16 = param_1[5];
  param_1[0x15] = 1;
  dVar4 = DAT_14053a020;
  dVar3 = DAT_140539d28;
  if (iVar16 != 0) {
    if (iVar16 != 1) {
      if (iVar16 != 99) goto LAB_14005dc67;
      iVar10 = param_1[3];
      iVar16 = 0;
      iVar9 = iVar16;
      if (iVar10 < 0x5a) {
LAB_14005d05a:
        if (iVar10 < 0x8c) {
          iVar16 = iVar9;
        }
        puVar12 = DAT_140e45d28;
        if (iVar10 == 1) {
          uVar29 = param_1[0xb];
          uVar32 = param_1[10];
          if (DAT_140e45d1c < 0x1000) {
            puVar12 = (undefined8 *)_malloc_base(0x60);
            if (puVar12 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
            *(undefined4 *)((longlong)puVar12 + 0x14) = uVar32;
            *(undefined4 *)(puVar12 + 3) = uVar29;
            *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar32;
            *(undefined4 *)(puVar12 + 4) = uVar29;
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
            if (bVar21) {
              DAT_140e45d78 = puVar12;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar12;
            }
          }
        }
      }
      else {
        iVar9 = 0xff;
        if (iVar10 < 100) {
          dVar22 = (double)FUN_140332d90(((double)iVar10 - DAT_14053a430) * DAT_14053a9d8 *
                                         DAT_14053a020 * DAT_140539d28);
          iVar16 = (int)(dVar22 * DAT_14053a5f8);
          puVar12 = DAT_140e45d28;
        }
        else {
          if (0x8b < iVar10) goto LAB_14005d05a;
          dVar22 = (double)FUN_140332d90(((double)iVar10 - DAT_14053a3a0) * DAT_14053a6d8 *
                                         DAT_14053a020 * DAT_140539d28);
          puVar12 = DAT_140e45d28;
          if (iVar10 < 0x8c) {
            iVar16 = (int)(dVar22 * DAT_14053a5f8);
          }
        }
      }
      DAT_140e45d28 = puVar12;
      iVar10 = param_1[3];
      if (iVar10 < 0x5a) {
        FUN_14007ac00(param_1);
        iVar10 = param_1[3];
        param_1[0xb] = (float)iVar10 * _DAT_140539ccc + (float)param_1[0xb];
      }
      puVar12 = DAT_140e45d28;
      if (iVar10 == 0x5a) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar29 = param_1[0xb];
        uVar32 = param_1[10];
        puVar12 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar12 = (undefined8 *)_malloc_base(0x60);
          if (puVar12 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar12 + 0x14) = uVar32;
          *(undefined4 *)(puVar12 + 3) = uVar29;
          *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar32;
          *(undefined4 *)(puVar12 + 4) = uVar29;
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
          if (bVar21) {
            DAT_140e45d78 = puVar12;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar12;
          }
        }
      }
      DAT_140e45d28 = puVar12;
      uVar31 = 0;
      iVar10 = FUN_1400c9580(param_1[3],0,5,2,0xd9,0xda);
      uVar29 = DAT_140e41ab8;
      puVar13 = (undefined4 *)_malloc_base(0x48);
      if (puVar13 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
      bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar13 = uVar29;
      puVar13[1] = 0x4e;
      *(undefined8 *)(puVar13 + 2) = 5;
      puVar13[4] = 0;
      *(undefined2 *)(puVar13 + 5) = 0;
      *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
      puVar13[10] = 0xff;
      puVar13[0xb] = 0xff;
      puVar13[0xc] = 0xff;
      puVar13[0xd] = iVar16;
      *(undefined8 *)(puVar13 + 0xe) = 1;
      *(undefined8 *)(puVar13 + 0x10) = 0;
      if (bVar21) {
        DAT_140e46bf0 = puVar13;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
      }
      DAT_140e46c88 = puVar13;
      if ((int)param_1[3] < 100) {
        uVar31 = uVar31 & 0xffff0000;
        FUN_1400c8410((&DAT_140e44ad0)[iVar10],0x1e,7,param_1[10],param_1[0xb],uVar31,uVar33,uVar6,
                      0xff,0xff,0xff,0xff,1,0);
      }
      if (param_1[3] == 0x8c) {
        *param_1 = 0;
      }
      goto LAB_14005dc67;
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar16 = ((int)dVar22 & 0xffffU) - (uint)uVar1;
    iVar10 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar10 = iVar16;
    }
    iVar16 = iVar10 + -0x10000;
    if (iVar10 < 0x8001) {
      iVar16 = iVar10;
    }
    uVar18 = (ushort)(int)dVar22;
    if (iVar16 < 1) {
      uVar19 = uVar1;
      if ((iVar16 < 0) && (uVar19 = uVar1 - 0x300, -0x300 < iVar16)) {
        uVar19 = uVar18;
      }
    }
    else {
      uVar19 = uVar18;
      if (0x2ff < iVar16) {
        uVar19 = uVar1 + 0x300;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar19;
    dVar22 = (double)FUN_1403307c0();
    fVar26 = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar26;
    dVar23 = (double)FUN_140332d90();
    dVar22 = DAT_14053a070;
    iVar10 = param_1[3];
    fVar25 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar25;
    if (iVar10 < 0) {
      *(double *)(param_1 + 0x12) = DAT_140539f00;
    }
    else {
      if (iVar10 < 0xb4) {
        dVar22 = (double)FUN_140332d90(((double)iVar10 - 0.0) * DAT_14053a438 * dVar4 * dVar3);
        dVar22 = dVar22 * DAT_14053a040 + DAT_140539f00;
      }
      *(double *)(param_1 + 0x12) = dVar22;
      uVar29 = DAT_14053b390;
      if (iVar10 == 1) {
        DAT_1407c77a0 = DAT_1407c779c;
        uVar34 = CONCAT44(uVar32,0x28);
        uVar32 = CONCAT22((short)(uVar31 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x114,99999999,0,DAT_14053ad1c,DAT_14053b390,uVar32,uVar33,uVar34,1,param_1[1]);
        uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),0x28);
        uVar32 = CONCAT22((short)((uint)uVar32 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x114,99999999,0,DAT_14053b380,uVar29,uVar32,uVar33,uVar34,1,param_1[1]);
        uVar29 = DAT_14053b36c;
        uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),0x28);
        uVar32 = CONCAT22((short)((uint)uVar32 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x114,99999999,0,DAT_14053adbc,DAT_14053b36c,uVar32,uVar33,uVar34,1,param_1[1]);
        uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),0x28);
        uVar31 = CONCAT22((short)((uint)uVar32 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x114,99999999,0,DAT_14053b3d8,uVar29,uVar31,uVar33,uVar34,1,param_1[1]);
        uVar30 = (undefined2)((uint)uVar29 >> 0x10);
        uVar32 = (undefined4)((ulonglong)uVar34 >> 0x20);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        fVar25 = (float)param_1[0xb];
        fVar26 = (float)param_1[10];
      }
    }
    fVar7 = DAT_140e445dc;
    fVar5 = DAT_14053ac58;
    if (0x27 < (int)param_1[3]) {
      iVar10 = (param_1[3] + -0x28) % 0x4b0;
      dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar25 + DAT_14053ac58)),
                                     (double)(DAT_140e445d8 - fVar26));
      if ((iVar10 < 0) || (iVar10 != (iVar10 / 0x50) * 0x50)) {
        if ((iVar10 < 0) || (0x27 < iVar10 % 0x50)) goto LAB_14005d81f;
      }
      else if (iVar10 < 0x1a4) {
        uVar8 = 0xc000;
        if (fVar25 <= fVar7) {
          uVar8 = 0x4000;
        }
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar8;
      }
      else {
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar22 * DAT_14053aba0);
      }
      uVar20 = DAT_14053ac2c;
      uVar34 = DAT_14053a178;
      if (iVar10 % 0x50 == ((iVar10 % 0x50) / 5) * 5) {
        FUN_14006c2f0(7,1,fVar26 + fVar5,fVar25 + fVar5,
                      CONCAT22(uVar30,*(undefined2 *)((longlong)param_1 + 0x42)),DAT_14053ac2c,
                      DAT_14053a178,CONCAT44(uVar32,1),0);
        FUN_14006c2f0(7,1,(float)param_1[10] - fVar5,(float)param_1[0xb] + fVar5,
                      *(undefined2 *)((longlong)param_1 + 0x42),uVar20,uVar34,1,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar31 = uVar20;
      }
    }
LAB_14005d81f:
    iVar16 = DAT_140e44308;
    iVar10 = param_1[7];
    iVar17 = auVar28._8_4_;
    if ((iVar10 < iVar17) && (lVar11 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x60)) {
        if (*(int *)(lVar11 + 4) == iVar16) {
          *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0x1c) - (iVar17 - iVar10);
        }
      }
    }
    iVar10 = param_1[7];
    if (iVar17 < iVar10) {
      param_1[7] = iVar17;
      iVar10 = iVar17;
    }
    iVar16 = DAT_140e44308;
    if ((iVar10 < 1) && (lVar11 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x60)) {
        if (*(int *)(lVar11 + 4) == iVar16) {
          *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0x1c) - iVar17;
        }
      }
    }
    uVar31 = uVar31 & 0xffff0000;
    FUN_1400c8410((&DAT_140e44ad0)[iVar9],0x1e,7,param_1[10],param_1[0xb],uVar31,uVar33,uVar6,0xff,
                  0xff,0xff,0xff,1,0);
    if ((DAT_14053a018 <= *(double *)(param_1 + 0x12)) &&
       (DAT_140e418c8 ==
        ((int)DAT_140e418c8 / 3 + ((int)DAT_140e418c8 >> 0x1f) +
        (int)((ulonglong)((longlong)(int)DAT_140e418c8 / 3 + ((longlong)(int)DAT_140e418c8 >> 0x3f))
             >> 0x1f)) * 3)) {
      uVar29 = param_1[0xb];
      uVar32 = param_1[10];
      uVar2 = (&DAT_140e44ad0)[iVar9];
      if (DAT_140e45d1c < 0x1000) {
        puVar12 = (undefined8 *)_malloc_base(0x60);
        if (puVar12 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar12 + 0xc) = uVar2;
        puVar12[6] = 0x3ff0000000000000;
        puVar12[7] = 0x3ff0000000000000;
        *(undefined4 *)((longlong)puVar12 + 0x14) = uVar32;
        *(undefined4 *)(puVar12 + 3) = uVar29;
        *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar32;
        *(undefined4 *)(puVar12 + 4) = uVar29;
        *puVar12 = 1;
        *(undefined4 *)(puVar12 + 1) = 5;
        *(undefined4 *)(puVar12 + 2) = 0x1d;
        *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
        puVar12[5] = 0;
        *(undefined4 *)(puVar12 + 8) = 0x10;
        *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
        *(undefined4 *)(puVar12 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
        puVar12[10] = 0x60;
        puVar12[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar12;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar12;
        }
        DAT_140e45d28 = puVar12;
        param_1[0x15] = 0;
        goto LAB_14005dc67;
      }
    }
    param_1[0x15] = 0;
    goto LAB_14005dc67;
  }
  uVar20 = param_1[3];
  puVar12 = (undefined8 *)FUN_140135060(local_d8,uVar20,0x14);
  dVar23 = DAT_14053a798;
  dVar4 = DAT_14053a5f8;
  dVar3 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  uVar34 = *puVar12;
  if (0x95 < (int)uVar20) {
    iVar10 = 0xff;
  }
  uVar29 = *(undefined4 *)(puVar12 + 1);
  if (((int)uVar20 < 0x96) || (0xb3 < (int)uVar20)) {
    local_res8 = ((int)uVar20 >> 0x1f & 0xffffff01U) + 0xff;
    if (-1 < (int)uVar20) {
      if ((int)uVar20 < 0x96) {
        dVar22 = (double)FUN_140332d90(((double)(int)uVar20 - 0.0) * _DAT_14053a478 * DAT_14053a020
                                       * DAT_140539d28);
        goto LAB_14005db60;
      }
      if (uVar20 < 0xb4) goto LAB_14005db39;
    }
  }
  else {
    dVar24 = (double)FUN_140332d90(((double)(int)uVar20 - DAT_14053a510) * DAT_14053a798 *
                                   DAT_14053a020 * DAT_140539d28);
    iVar10 = (int)(dVar24 * dVar4);
LAB_14005db39:
    dVar22 = (double)FUN_140332d90(((double)(int)uVar20 - DAT_14053a4a0) * dVar23 * dVar3 * dVar22);
LAB_14005db60:
    local_res8 = (int)(dVar22 * dVar4);
  }
  uVar31 = uVar31 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44ad0)[iVar9],0x1e,7,param_1[10],param_1[0xb],uVar31,uVar33,uVar6,0xff,
                0xff,0xff,iVar10,1,0);
  iVar10 = 0;
  if ((int)uVar20 < 0xb4) {
    iVar10 = local_res8;
  }
  uStack_15c = (undefined4)((ulonglong)uVar34 >> 0x20);
  local_160 = (undefined4)uVar34;
  uVar31 = uVar31 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44ad0)[iVar9],0x1e,8,param_1[10],param_1[0xb],uVar31,uVar33,uVar6,
                local_160,uStack_15c,uVar29,iVar10,1,0);
  if (param_1[3] == 0xbe) {
    param_1[5] = param_1[5] + 1;
    param_1[7] = local_res10;
    *(undefined8 *)(param_1 + 0x12) = 0x3fe0000000000000;
    param_1[3] = 0;
    param_1[8] = local_128;
  }
LAB_14005dc67:
  if (param_1[0x15] == 0) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      stage_entity_spawn_candidate(0xc3,99999999,1,0,0,uVar31 & 0xffff0000,uVar33,0x14,0,param_1[1])
      ;
      param_1[0x17] = 1;
    }
    else if (param_1[0x17] != 1) {
      return;
    }
    param_1[0x15] = 1;
    if (DAT_140e44654 < 0x3d) {
      param_1[0x17] = 0;
      param_1[0x15] = 0;
    }
  }
  return;
}


