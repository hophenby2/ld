// Function: FUN_14005a3f0 @ 14005a3f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005a3f0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ushort uVar3;
  short sVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  uint in_stack_fffffffffffffe50;
  undefined8 in_stack_fffffffffffffe60;
  undefined4 uVar30;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined8 local_158;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined1 local_e0 [160];
  
  uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  iVar19 = 0;
  iVar17 = 0;
  uStack_130 = (ulonglong)(uint)uStack_130;
  iVar18 = iVar19;
  if ((0 < DAT_140e44e6c) && (lVar9 = DAT_140e45d80, iVar18 = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar9 + 4) == DAT_140e44308) {
        local_138 = *(undefined8 *)(lVar9 + 0x10);
        uStack_130 = *(ulonglong *)(lVar9 + 0x18);
        local_128 = *(undefined8 *)(lVar9 + 0x20);
        uStack_120 = *(undefined8 *)(lVar9 + 0x28);
      }
      lVar9 = *(longlong *)(lVar9 + 0x60);
    } while (lVar9 != 0);
    iVar18 = uStack_130._4_4_;
  }
  dVar21 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e44908 - (float)param_1[10]),0));
  uVar13 = DAT_140e418c8;
  dVar22 = DAT_14053aba0;
  dVar21 = dVar21 * DAT_14053aba0;
  puVar10 = (undefined8 *)FUN_140135060(&local_158,DAT_140e418c8,0x1e);
  uVar5 = *(undefined4 *)(puVar10 + 1);
  uVar2 = *puVar10;
  if ((local_138._4_4_ == 0x14) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,DAT_14053a4f0,
               CONCAT44(uVar30,param_1[0x14]),1,0);
    uVar13 = DAT_140e418c8;
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  uVar8 = _UNK_14053bb28;
  uVar7 = _DAT_14053bb20;
  if (uVar13 == ((int)uVar13 / 0x32) * 0x32) {
    uVar16 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    uVar12 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
    uVar16 = uVar16 * 0x800 ^ uVar16;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    uVar13 = DAT_1407c7798 * 0x457 + uVar13;
    DAT_140e44908 = (float)(((uVar12 >> 0xb ^ uVar16) >> 8 ^ uVar16 ^ uVar12) % 0x12d + 0xd2);
    uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar13 = uVar13 * 0x800 ^ uVar13;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 200);
  }
  iVar14 = param_1[5];
  param_1[0x15] = 1;
  local_168 = (undefined4)uVar2;
  uStack_164 = (undefined4)((ulonglong)uVar2 >> 0x20);
  if (iVar14 == 0) {
    uVar13 = param_1[3];
    puVar10 = (undefined8 *)FUN_140135060(local_e0,uVar13,0x14);
    dVar24 = DAT_14053a798;
    dVar23 = DAT_14053a5f8;
    dVar21 = DAT_14053a020;
    dVar22 = DAT_140539d28;
    local_158 = *puVar10;
    if (0x95 < (int)uVar13) {
      iVar19 = 0xff;
    }
    uVar30 = *(undefined4 *)(puVar10 + 1);
    if (((int)uVar13 < 0x96) || (0xb3 < (int)uVar13)) {
      iVar17 = ((int)uVar13 >> 0x1f & 0xffffff01U) + 0xff;
      if (-1 < (int)uVar13) {
        if ((int)uVar13 < 0x96) {
          dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - 0.0) * _DAT_14053a478 *
                                         DAT_14053a020 * DAT_140539d28);
          goto LAB_14005b29d;
        }
        if (uVar13 < 0xb4) goto LAB_14005b278;
      }
    }
    else {
      dVar25 = (double)FUN_140332d90(((double)(int)uVar13 - DAT_14053a510) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar19 = (int)(dVar25 * dVar23);
LAB_14005b278:
      dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - DAT_14053a4a0) * dVar24 * dVar21 *
                                     dVar22);
LAB_14005b29d:
      iVar17 = (int)(dVar22 * dVar23);
    }
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a48,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,uVar7,
                  uVar8,local_168,uStack_164,uVar5,iVar19,1,0);
    iVar19 = 0;
    if ((int)uVar13 < 0xb4) {
      iVar19 = iVar17;
    }
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a48,0x1e,8,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,uVar7,
                  uVar8,(undefined4)local_158,local_158._4_4_,uVar30,iVar19,1,0);
    if (param_1[3] == 0xbe) {
      param_1[5] = param_1[5] + 1;
      param_1[8] = (undefined4)local_128;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
      param_1[3] = 0;
      param_1[7] = iVar18;
    }
    goto LAB_14005b3a4;
  }
  if (iVar14 != 1) {
    if (iVar14 != 99) goto LAB_14005b3a4;
    iVar18 = param_1[3];
    if (0x59 < iVar18) {
      iVar17 = 0xff;
    }
    iVar19 = 0;
    if (iVar18 < 0x5a) {
LAB_14005a7c3:
      if (iVar18 < 0x8c) {
        iVar19 = iVar17;
      }
      puVar10 = DAT_140e45d28;
      if (iVar18 == 1) {
        uVar30 = param_1[0xb];
        uVar1 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar10 = (undefined8 *)_malloc_base(0x60);
          if (puVar10 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar10 + 0x14) = uVar1;
          *(undefined4 *)(puVar10 + 3) = uVar30;
          *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar1;
          *(undefined4 *)(puVar10 + 4) = uVar30;
          *puVar10 = 1;
          puVar10[1] = 0x36;
          *(undefined4 *)(puVar10 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar10 + 0x24) = 0;
          puVar10[5] = 0;
          puVar10[6] = 0x3ff0000000000000;
          puVar10[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar10 + 8) = 0;
          *(undefined4 *)((longlong)puVar10 + 0x44) = 0xff;
          *(undefined4 *)(puVar10 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar10 + 0x4c) = 0xff;
          puVar10[10] = 0xff;
          puVar10[0xb] = 0;
          if (bVar20) {
            DAT_140e45d78 = puVar10;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar10;
          }
        }
      }
    }
    else if (iVar18 < 100) {
      dVar22 = (double)FUN_140332d90(((double)iVar18 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar19 = (int)(dVar22 * DAT_14053a5f8);
      puVar10 = DAT_140e45d28;
    }
    else {
      if (0x8b < iVar18) goto LAB_14005a7c3;
      dVar22 = (double)FUN_140332d90(((double)iVar18 - DAT_14053a3a0) * DAT_14053a6d8 *
                                     DAT_14053a020 * DAT_140539d28);
      puVar10 = DAT_140e45d28;
      if (iVar18 < 0x8c) {
        iVar19 = (int)(dVar22 * DAT_14053a5f8);
      }
    }
    DAT_140e45d28 = puVar10;
    iVar18 = param_1[3];
    if (iVar18 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar18 = param_1[3];
      param_1[0xb] = (float)iVar18 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar10 = DAT_140e45d28;
    if (iVar18 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar30 = param_1[0xb];
      uVar1 = param_1[10];
      puVar10 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar10 = (undefined8 *)_malloc_base(0x60);
        if (puVar10 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar10 + 0x14) = uVar1;
        *(undefined4 *)(puVar10 + 3) = uVar30;
        *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar1;
        *(undefined4 *)(puVar10 + 4) = uVar30;
        *puVar10 = 1;
        puVar10[1] = 0x11;
        *(undefined4 *)(puVar10 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar10 + 0x24) = 0;
        puVar10[5] = 0;
        puVar10[6] = 0x3ff0000000000000;
        puVar10[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar10 + 8) = 0;
        *(undefined4 *)((longlong)puVar10 + 0x44) = 0xff;
        *(undefined4 *)(puVar10 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar10 + 0x4c) = 0xff;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0;
        if (bVar20) {
          DAT_140e45d78 = puVar10;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar10;
        }
      }
    }
    DAT_140e45d28 = puVar10;
    uVar30 = DAT_140e41ab8;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar11 = uVar30;
    puVar11[1] = 0x4e;
    *(undefined8 *)(puVar11 + 2) = 5;
    puVar11[4] = 0;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = 0xff;
    puVar11[0xc] = 0xff;
    puVar11[0xd] = iVar19;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar20) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    DAT_140e46c88 = puVar11;
    if ((int)param_1[3] < 100) {
      in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
      FUN_1400c8410(DAT_140e44a48,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,uVar7,
                    uVar8,local_168,uStack_164,uVar5,0xff,1,0);
    }
    if (param_1[3] == 0x8c) {
      *param_1 = 0;
    }
    goto LAB_14005b3a4;
  }
  uVar3 = *(ushort *)(param_1 + 0x10);
  iVar14 = ((int)dVar21 & 0xffffU) - (uint)uVar3;
  iVar17 = iVar14 + 0x10000;
  if (-0x8001 < iVar14) {
    iVar17 = iVar14;
  }
  iVar14 = iVar17 + -0x10000;
  if (iVar17 < 0x8001) {
    iVar14 = iVar17;
  }
  uVar6 = (ushort)(int)dVar21;
  if (iVar14 < 1) {
    uVar15 = uVar3;
    if ((iVar14 < 0) && (uVar15 = uVar3 - 0x200, -0x200 < iVar14)) {
      uVar15 = uVar6;
    }
  }
  else {
    uVar15 = uVar6;
    if (0x1ff < iVar14) {
      uVar15 = uVar3 + 0x200;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar15;
  dVar21 = (double)FUN_1403307c0();
  fVar27 = (float)(dVar21 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar27;
  dVar21 = (double)FUN_140332d90();
  fVar26 = (float)(dVar21 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar26;
  uVar30 = DAT_140e41a50;
  if (0x1d < (int)param_1[3]) {
    fVar28 = fVar27 - DAT_14053ad18;
    fVar29 = fVar26 - DAT_14053ad40;
    fVar27 = fVar27 + _DAT_14053ad28;
    fVar26 = fVar26 - _DAT_14053ad24;
    iVar17 = (param_1[3] + -0x1e) % 0x398;
    if ((iVar17 == 0) || (iVar17 == 0x1c2)) {
      uVar1 = param_1[1];
      puVar10 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar10 = (undefined8 *)_malloc_base(0x60);
        if (puVar10 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar10 = 1;
        *(undefined4 *)(puVar10 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar10 + 0xc) = uVar30;
        *(undefined4 *)(puVar10 + 2) = 0x23;
        *(undefined4 *)((longlong)puVar10 + 0x14) = 0xc2c60000;
        *(undefined4 *)(puVar10 + 3) = 0xc2f00000;
        *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xc2c60000;
        *(undefined4 *)(puVar10 + 4) = 0xc2f00000;
        *(undefined2 *)((longlong)puVar10 + 0x24) = 0;
        puVar10[5] = 0;
        puVar10[6] = 0x4014000000000000;
        puVar10[7] = 0x4014000000000000;
        *(undefined4 *)(puVar10 + 8) = 0x1e;
        *(undefined4 *)((longlong)puVar10 + 0x44) = 0xff;
        *(undefined4 *)(puVar10 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar10 + 0x4c) = 0xff;
        *(undefined4 *)(puVar10 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar10 + 0x54) = uVar1;
        puVar10[0xb] = 0;
        if (bVar20) {
          DAT_140e45d78 = puVar10;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar10;
        }
      }
      DAT_140e45d28 = puVar10;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
    }
    if ((iVar17 == 0x1e) || (iVar17 == 0x1e0)) {
      dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar29),
                                     SUB84((double)(DAT_140e445d8 - fVar28),0));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar21 * dVar22);
    }
    uVar13 = DAT_14053ac2c;
    uVar2 = DAT_14053a210;
    if (iVar17 - 0x1eU < 0x28) {
      uVar16 = iVar17 - 0x1eU & 0x80000003;
      if ((int)uVar16 < 0) {
        uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
      }
      if (uVar16 != 0) goto LAB_14005ad4e;
LAB_14005ad73:
      sVar4 = *(short *)((longlong)param_1 + 0x42);
      iVar18 = iVar19;
      do {
        in_stack_fffffffffffffe50 = uVar13;
        FUN_14006c2f0(0xb,0,fVar28,fVar29,(short)iVar18 * 0x9c4 + sVar4 + -5000,uVar13,uVar2,1,0);
        iVar18 = iVar18 + 1;
      } while (iVar18 < 5);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar18 = uStack_130._4_4_;
    }
    else {
LAB_14005ad4e:
      if (iVar17 - 0x1e0U < 0x28) {
        uVar16 = iVar17 - 0x1e0U & 0x80000003;
        if ((int)uVar16 < 0) {
          uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
        }
        if (uVar16 == 0) goto LAB_14005ad73;
      }
    }
    dVar21 = (double)(int)(iVar17 - 0x50U) * _DAT_140539df0 + DAT_14053a0d0;
    if (iVar17 == 0x50) {
      dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                     SUB84((double)(DAT_140e445d8 - fVar27),0));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar23 * dVar22) + -0x4000;
LAB_14005ae9d:
      if ((iVar17 - 0x50U & 1) == 0) {
        FUN_14006c2f0(2,0x39,fVar27,fVar26,*(undefined2 *)((longlong)param_1 + 0x42),uVar13,dVar21,1
                      ,0);
        FUN_14006c2f0(3,9,fVar27,fVar26,*(undefined2 *)((longlong)param_1 + 0x42),uVar13,
                      dVar21 + DAT_140539fc8,1,0);
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + -0x960;
        in_stack_fffffffffffffe50 = uVar13;
        goto LAB_14005b094;
      }
    }
    else if (iVar17 - 0x50U < 0x136) goto LAB_14005ae9d;
    dVar21 = (double)(int)(iVar17 - 0x208U) * _DAT_140539de0 + DAT_14053a0b0;
    if (iVar17 - 0x208U < 0x17c) {
      uVar16 = iVar17 - 0x208U & 0x80000007;
      if ((int)uVar16 < 0) {
        uVar16 = (uVar16 - 1 | 0xfffffff8) + 1;
      }
      if (uVar16 == 0) {
        dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                       SUB84((double)(DAT_140e445d8 - fVar27),0));
        dVar24 = (double)FUN_140332d90(((double)(int)param_1[3] - _DAT_14053a788) * DAT_14053a670 *
                                       DAT_14053a020 * DAT_140539d28);
        dVar24 = dVar24 * _DAT_14053abb0;
        do {
          in_stack_fffffffffffffe50 = uVar13;
          FUN_14006c2f0(2,0,fVar27,fVar26,
                        (short)iVar19 * 3000 + (short)(int)(dVar23 * dVar22) + (short)(int)dVar24 +
                        -12000,uVar13,dVar21,1,0);
          iVar19 = iVar19 + 1;
        } while (iVar19 < 9);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
  }
LAB_14005b094:
  iVar19 = DAT_140e44308;
  iVar17 = param_1[7];
  if ((iVar17 < iVar18) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == iVar19) {
        *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - (iVar18 - iVar17);
      }
    }
  }
  iVar17 = param_1[7];
  if (iVar18 < iVar17) {
    param_1[7] = iVar18;
    iVar17 = iVar18;
  }
  iVar19 = DAT_140e44308;
  if ((iVar17 < 1) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == iVar19) {
        *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - iVar18;
      }
    }
  }
  in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
  FUN_1400c8410(DAT_140e44a48,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,uVar7,uVar8,
                local_168,uStack_164,uVar5,0xff,1,0);
  param_1[0x15] = 0;
LAB_14005b3a4:
  if (param_1[0x15] == 0) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      stage_entity_spawn_candidate
                (0x136,99999999,1,0,0,in_stack_fffffffffffffe50 & 0xffff0000,uVar7,0x14,0,param_1[1]
                );
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


