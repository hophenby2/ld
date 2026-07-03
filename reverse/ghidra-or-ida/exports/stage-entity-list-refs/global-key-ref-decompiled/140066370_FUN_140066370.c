// Function: FUN_140066370 @ 140066370
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140066370(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  ushort uVar13;
  float *pfVar14;
  uint uVar15;
  longlong lVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  ulonglong uVar28;
  float fVar29;
  double dVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  float local_res18;
  float fStackX_1c;
  undefined4 in_stack_fffffffffffffe08;
  undefined2 uVar38;
  uint in_stack_fffffffffffffe10;
  undefined2 uVar39;
  undefined1 in_stack_fffffffffffffe18 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  ulonglong in_stack_fffffffffffffe28;
  undefined4 uVar45;
  int local_198;
  uint local_194;
  float local_190;
  float fStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined1 local_100 [192];
  
  uVar38 = (undefined2)((uint)in_stack_fffffffffffffe08 >> 0x10);
  uStack_150 = 0;
  uStack_150._4_4_ = 0;
  lVar16 = DAT_140e45d80;
  iVar17 = local_158._4_4_;
  uVar5 = uStack_160._4_4_;
  uVar4 = uStack_150._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar17 = (int)((ulonglong)local_158 >> 0x20);
      uVar5 = (uint)((ulonglong)uStack_160 >> 0x20);
      uVar4 = (int)((ulonglong)uStack_150 >> 0x20);
      if (lVar16 == 0) break;
      if (*(int *)(lVar16 + 4) == DAT_140e44308) {
        uStack_160 = *(undefined8 *)(lVar16 + 8);
        local_158 = *(undefined8 *)(lVar16 + 0x10);
        uStack_150 = *(undefined8 *)(lVar16 + 0x18);
        local_148 = *(undefined8 *)(lVar16 + 0x20);
        uStack_140 = *(undefined8 *)(lVar16 + 0x28);
      }
      lVar16 = *(longlong *)(lVar16 + 0x60);
    }
  }
  uStack_150._4_4_ = uVar4;
  uStack_160._4_4_ = uVar5;
  local_158._4_4_ = iVar17;
  fVar35 = (float)param_1[0xb];
  uVar4 = param_1[10];
  dVar21 = (double)FUN_1403300b4((double)(DAT_140e4490c - fVar35));
  uVar36 = (undefined4)DAT_14053bb20;
  uVar37 = DAT_14053bb20._4_4_;
  dVar27 = (double)DAT_14053bb20;
  uVar5 = param_1[3];
  uVar3 = (uint)(dVar21 * DAT_14053aba0);
  FUN_140135060(local_100,uVar5,0x14);
  uVar39 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
  uVar45 = (undefined4)(in_stack_fffffffffffffe28 >> 0x20);
  uVar9 = 0;
  local_198 = 0xff;
  uVar10 = 0;
  local_194 = 0;
  lVar16 = 0xdd;
  if ((local_158._4_4_ == 0x8e) && ((int)param_1[5] < 0x62)) {
    param_1[5] = 0x62;
    param_1[3] = 0;
    param_1[0x17] = 0;
    uVar5 = uVar10;
  }
  dVar25 = DAT_140539f00;
  pfVar14 = (float *)(param_1 + 10);
  iVar17 = param_1[5];
  param_1[0x15] = 1;
  fVar33 = DAT_14053af04;
  fVar31 = DAT_14053ae70;
  fVar32 = DAT_14053ae1c;
  fVar34 = DAT_14053adb4;
  fVar29 = DAT_14053ad40;
  dVar30 = DAT_14053a020;
  dVar26 = DAT_140539fa8;
  dVar22 = DAT_140539d28;
  uVar12 = (ushort)uVar3;
  dVar21 = dVar27;
  dVar24 = dVar27;
  switch(iVar17) {
  case 0:
    if ((int)uVar5 < 0) {
      param_1[10] = (float)uStack_140;
      param_1[0xb] = uStack_140._4_4_;
    }
    else {
      if ((int)uVar5 < 0xf0) {
        FUN_140332d90(((double)(int)uVar5 - 0.0) * _DAT_14053a3c8 * DAT_14053a020 * DAT_140539d28);
      }
      param_1[10] = (float)uStack_140;
      param_1[0xb] = uStack_140._4_4_;
      if ((0xb3 < (int)uVar5) && ((int)uVar5 < 0xf0)) {
        FUN_140332d90(((double)(int)uVar5 - DAT_14053a4a0) * DAT_14053a628 * dVar30 * dVar22);
      }
    }
    dVar27 = (double)(int)uVar5;
    FUN_140332d90((dVar27 - 0.0) * _DAT_14053a9b8 * dVar30 * dVar22);
    if ((0xb3 < (int)uVar5) && ((int)uVar5 < 0xf0)) {
      FUN_140332d90((dVar27 - DAT_14053a4a0) * DAT_14053a628 * dVar30 * dVar22);
    }
    FUN_140332d90((dVar27 - DAT_14053a290) * _DAT_14053a9b8 * dVar30 * dVar22);
    if ((int)uVar5 < 0xe6) {
      uVar36 = 0;
      uVar37 = 0;
LAB_140066760:
      dVar24 = (double)CONCAT44(uVar37,uVar36);
    }
    else {
      if (0x10d < (int)uVar5) goto LAB_140066760;
      dVar24 = (double)FUN_140332d90((dVar27 - _DAT_14053a5d0) * DAT_14053a6d8 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar24 = dVar24 + 0.0;
    }
    uVar3 = 0xff;
    if (uVar5 - 0xe6 < 0x28) {
      dVar27 = (double)FUN_140332d90();
      uVar3 = (uint)(dVar27 * DAT_14053a5f8);
    }
    uVar9 = 0;
    if ((int)uVar5 < 0x10e) {
      uVar9 = uVar3;
    }
    if (uVar5 == 0x10e) {
      param_1[3] = 0;
      param_1[8] = (undefined4)local_148;
      param_1[7] = uStack_150._4_4_;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
      param_1[5] = iVar17 + 1;
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 6:
  case 7:
  case 9:
  case 0xb:
  case 0xe:
  case 0x10:
  case 0x19:
  case 0x62:
    if (uVar5 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47304);
      FUN_14018a340(DAT_140e47304,1,1);
    }
    dVar30 = DAT_14053b0a0;
    dVar26 = DAT_14053a9d8;
    dVar25 = DAT_14053a020;
    dVar22 = DAT_140539d28;
    iVar17 = param_1[3];
    if (iVar17 < 10) {
      if (-1 < iVar17) {
        dVar21 = (double)FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                       DAT_140539d28);
        dVar24 = (double)FUN_140332d90(((double)iVar17 - 0.0) * dVar26 * dVar25 * dVar22);
        dVar21 = dVar21 + dVar27;
        dVar24 = dVar24 * dVar30 + dVar27;
      }
    }
    else if (iVar17 < 0x14) {
      dVar27 = (double)FUN_140332d90();
      dVar21 = dVar27 * DAT_14053b0a8 + DAT_140539fc8;
      dVar27 = (double)FUN_140332d90();
      dVar24 = (dVar27 + dVar27 + 0.0) * 0.0;
      break;
    }
    fVar29 = DAT_140e445dc;
    fVar35 = DAT_140e445d8;
    if (iVar17 < 0) break;
    if (iVar17 < 5) {
      dVar22 = (double)FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053aa88 * dVar25 * dVar22);
      dVar24 = dVar24 * (dVar22 * dVar30 + dVar27);
      break;
    }
    if (0x18 < iVar17) {
      if (iVar17 < 0x1e) {
        dVar23 = (double)FUN_140332d90(((double)iVar17 - DAT_14053a278) * DAT_14053aa88 * dVar25 *
                                       dVar22);
        dVar24 = dVar24 * (dVar23 * dVar30 + dVar27);
        goto LAB_140066e58;
      }
      dVar24 = dVar27 * dVar24;
      goto LAB_140066c01;
    }
    dVar24 = dVar24 * 0.0;
    if (iVar17 != 0x14) {
      if (0x13 < iVar17) {
        if (0x1d < iVar17) goto LAB_140066c01;
        goto LAB_140066e58;
      }
      goto LAB_140066c1b;
    }
    switch(param_1[5]) {
    case 4:
      uVar7 = 0xf0;
      goto LAB_140066ca5;
    default:
      uVar5 = (uStack_160._4_4_ + 0x223d >> 0x1e ^ uStack_160._4_4_ + 0x223d) * 0x6c078965 + 1;
      uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      uVar3 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
      uVar9 = (uStack_160._4_4_ >> 0x1e ^ uStack_160._4_4_) * 0x6c078965 + 1;
      param_1[10] = (float)(((uVar3 >> 0xb ^ uVar5) >> 8 ^ uVar3 ^ uVar5) % 0x191 + 0xa0);
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ DAT_140e9fd18;
      param_1[0xb] = (float)(DAT_140e9fd1c % 0x12d + 200);
      break;
    case 7:
    case 9:
    case 0xb:
      uVar7 = 100;
LAB_140066ca5:
      param_1[10] = DAT_140e445d8;
      param_1[0xb] = fVar29;
      uVar7 = FUN_1401346a0(CONCAT44(fVar29,fVar35),uVar7);
      local_188 = (undefined4)uVar7;
      uStack_184 = (undefined4)((ulonglong)uVar7 >> 0x20);
      param_1[10] = local_188;
      param_1[0xb] = uStack_184;
      break;
    case 0xe:
    case 0x19:
      param_1[10] = 0x43b40000;
      param_1[0xb] = 0x437a0000;
      break;
    case 0x10:
      param_1[10] = 0x438c0000;
      param_1[0xb] = 0x43b40000;
    }
LAB_140066e58:
    FUN_140332d90(((double)iVar17 - DAT_14053a1e8) * dVar26 * dVar25 * dVar22);
    FUN_140332d90(((double)iVar17 - DAT_14053a1e8) * dVar26 * dVar25 * dVar22);
LAB_140066c01:
    if (param_1[5] == 0x62) {
      param_1[10] = (float)uStack_140;
      param_1[0xb] = uStack_140._4_4_;
    }
LAB_140066c1b:
    uVar9 = uVar10;
    if (iVar17 == 0x23) {
      DAT_140e44908 = param_1[10];
      DAT_140e4490c = (float)param_1[0xb];
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    break;
  case 5:
  case 8:
  case 10:
  case 0xc:
  case 0xd:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar18 = (uVar3 & 0xffff) - (uint)uVar1;
    iVar19 = iVar18 + 0x10000;
    if (-0x8001 < iVar18) {
      iVar19 = iVar18;
    }
    iVar18 = iVar19 + -0x10000;
    if (iVar19 < 0x8001) {
      iVar18 = iVar19;
    }
    if (iVar18 < 1) {
      uVar13 = uVar1;
      if ((iVar18 < 0) && (uVar13 = uVar1 - 0x200, -0x200 < iVar18)) {
        uVar13 = uVar12;
      }
    }
    else {
      uVar13 = uVar12;
      if (0x1ff < iVar18) {
        uVar13 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar13;
    dVar27 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90();
    iVar19 = 0x3c;
    if (iVar17 != 0xc) {
      iVar19 = 0x5a;
    }
    if (iVar17 == 0xd) {
      iVar19 = 0x78;
    }
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + fVar35;
    uVar4 = DAT_140e41a50;
    if (uVar5 == 1) {
      uVar36 = param_1[1];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base();
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        *(undefined4 *)(puVar6 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar4;
        puVar6[2] = 0x23;
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x4014000000000000;
        puVar6[7] = 0x4014000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar36;
        puVar6[0xb] = 0;
        if (bVar20) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
    }
    iVar17 = param_1[3];
    if (iVar17 < 0x28) {
      if (-1 < iVar17) {
        FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a6d8 * dVar30 * dVar22);
        FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a6d8 * dVar30 * dVar22);
      }
      lVar16 = 0xde;
    }
    else {
      if (iVar17 < 0x32) {
        FUN_140332d90(((double)iVar17 - DAT_14053a340) * DAT_14053a9d8 * dVar30 * dVar22);
        FUN_140332d90(((double)iVar17 - DAT_14053a340) * DAT_14053a9d8 * dVar30 * dVar22);
      }
      else if (iVar17 < 0x3c) {
        FUN_140332d90(((double)iVar17 - DAT_14053a340) * DAT_14053a9d8 * dVar30 * dVar22);
        FUN_140332d90(((double)iVar17 - DAT_14053a340) * DAT_14053a9d8 * dVar30 * dVar22);
      }
      lVar16 = 0xdf;
      if (iVar17 == 0x28) {
        FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                      SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
        stage_entity_spawn_candidate((param_1[5] == 0xd) + 299,99999999,0);
        stage_entity_spawn_candidate((param_1[5] == 0xd) + 299,99999999,0);
        iVar17 = 0;
        stage_entity_spawn_candidate((param_1[5] == 0xd) + 299,99999999,0);
        stage_entity_spawn_candidate((param_1[5] == 0xd) + 299,99999999,0);
        if (param_1[5] != 0xd) {
          uVar4 = param_1[10];
          do {
            FUN_14006c2f0(0xc,1,uVar4);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 0x14);
        }
        lVar16 = 0xdf;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47308);
        FUN_14018a340(DAT_140e47308,1,1);
      }
    }
    if (param_1[3] == iVar19) {
      DAT_140e44908 = param_1[10];
      DAT_140e4490c = (float)param_1[0xb];
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    param_1[0x15] = 0;
    uVar9 = 0;
    break;
  case 0xf:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar19 = (uVar3 & 0xffff) - (uint)uVar1;
    iVar17 = iVar19 + 0x10000;
    if (-0x8001 < iVar19) {
      iVar17 = iVar19;
    }
    iVar19 = iVar17 + -0x10000;
    if (iVar17 < 0x8001) {
      iVar19 = iVar17;
    }
    if (iVar19 < 1) {
      uVar13 = uVar1;
      if ((iVar19 < 0) && (uVar13 = uVar1 - 0x200, -0x200 < iVar19)) {
        uVar13 = uVar12;
      }
    }
    else {
      uVar13 = uVar12;
      if (0x1ff < iVar19) {
        uVar13 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar13;
    dVar21 = (double)FUN_1403307c0();
    *pfVar14 = (float)(dVar21 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar21 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar21 * *(double *)(param_1 + 0x12)) + fVar35;
    puVar6 = DAT_140e45d28;
    if ((uVar5 == 1) && (uVar4 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base();
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      puVar6[1] = 0x2f;
      puVar6[2] = 0x3c;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 4) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0x32;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0x40;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      *(undefined4 *)(puVar6 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x54) = uVar4;
      puVar6[0xb] = 0;
      if (bVar20) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    dVar21 = DAT_14053a5f8;
    iVar19 = 0;
    iVar17 = param_1[3];
    if (iVar17 < 0) {
      local_198 = 0xff;
    }
    else if (iVar17 < 0x5a) {
      FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a558 * dVar30 * dVar22);
      FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a558 * dVar30 * dVar22);
      local_198 = 0xff;
    }
    else if (iVar17 < 100) {
      dVar24 = (double)FUN_140332d90(((double)iVar17 - DAT_14053a3f8) * DAT_14053a9d8 * dVar30 *
                                     dVar22);
      local_198 = (int)(dVar24 * dVar21);
    }
    else {
      local_198 = 0;
    }
    uVar7 = DAT_14053a178;
    lVar16 = 0xde;
    if (iVar17 == 0x5a) {
      uVar9 = (uStack_160._4_4_ * 0x22b8 >> 0x1e ^ uStack_160._4_4_ * 0x22b8) * 0x6c078965 + 1;
      uVar5 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 3;
      uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 4;
      uVar4 = (undefined4)DAT_14053a070;
      iVar17 = iVar19;
      do {
        uVar36 = (undefined4)(in_stack_fffffffffffffe28 >> 0x20);
        uVar3 = uVar9 * 0x800 ^ uVar9;
        FUN_1403307c0();
        dVar21 = (double)FUN_140332d90();
        uVar10 = param_1[3] + iVar19;
        uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
        uVar38 = (undefined2)
                 ((uint)((float)(dVar21 * (double)(((uVar5 >> 0xb ^ uVar3) >> 8 ^ uVar5 ^ uVar3) %
                                                  0x29)) + (float)param_1[0xb]) >> 0x10);
        uVar3 = uVar10 * 0x800 ^ uVar10;
        DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
        uVar8 = FUN_140134db0(iVar17 + param_1[3],uVar4,uVar7);
        in_stack_fffffffffffffe28 = CONCAT44(uVar36,1);
        auVar40._12_4_ = in_stack_fffffffffffffe18._12_4_;
        auVar40._0_8_ = in_stack_fffffffffffffe18._0_8_;
        auVar40._8_4_ = 0x14;
        in_stack_fffffffffffffe18._8_8_ = auVar40._8_8_;
        in_stack_fffffffffffffe18._0_8_ = uVar8;
        stage_entity_spawn_candidate(0x129,99999999,0);
        iVar19 = iVar19 + 1;
        iVar17 = iVar17 + 0x58;
      } while (iVar17 < 0xb00);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar5 = param_1[3];
    if (uVar5 == 100) {
      param_1[10] = 0xc47a0000;
      param_1[0xb] = 0xc47a0000;
    }
    else if ((0x95 < (int)uVar5) && (uVar5 - 0x96 < 0x21c)) {
      iVar17 = 6;
      if ((int)uVar5 < 0xf6) {
        iVar17 = 0x18;
      }
      if ((int)(uVar5 - 0x96) % iVar17 == 0) {
        fVar35 = DAT_140e445d8 / DAT_14053ab70;
        uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        uVar3 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 3;
        uVar9 = uVar9 * 0x800 ^ uVar9;
        uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 4;
        dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - DAT_14053ac2c));
        uVar10 = (uVar5 + 0x15b38 >> 0x1e ^ uVar5 + 0x15b38) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar5 = uVar10 * 0x800 ^ uVar10;
        auVar41._12_4_ = in_stack_fffffffffffffe18._12_4_;
        auVar41._0_8_ = in_stack_fffffffffffffe18._0_8_;
        auVar41._8_4_ = 1;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
        FUN_14006c2f0(2,0x3c,(float)(((uVar3 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ uVar3) % 0x259) + fVar35
                      ,uVar10,CONCAT22(uVar38,(short)DAT_140e9fd1c +
                                              (short)((ulonglong)DAT_140e9fd1c / 0xe11) * -0xe11 +
                                              (short)(int)(dVar21 * DAT_14053aba0) + -0x708),0,
                      DAT_14053a138,auVar41._8_8_,in_stack_fffffffffffffe28 & 0xffffffff00000000);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
    }
    if ((int)param_1[3] < 0x5a) {
      param_1[0x15] = 0;
    }
    else if (param_1[3] == 0x2d0) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  default:
switchD_140066583_caseD_20:
    uVar9 = 0;
    dVar24 = dVar27;
    dVar21 = dVar27;
    if (local_198 < 1) goto LAB_140066a13;
    break;
  case 0x11:
    if (uVar5 == 1) {
      fVar35 = fVar35 + DAT_14053ad40;
      param_1[0xc] = uVar4;
      param_1[0xd] = fVar35;
LAB_140067e18:
      dVar21 = (double)FUN_140332d90(((double)(int)uVar5 - 0.0) * DAT_14053a890 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar21 = dVar21 * _DAT_14053b090 + dVar27;
    }
    else if ((-1 < (int)uVar5) && (dVar21 = DAT_140539ef8, (int)uVar5 < 0x14)) goto LAB_140067e18;
    param_1[10] = param_1[0xc];
    param_1[0xb] = (float)param_1[0xd] - (float)dVar21 * fVar29;
    FUN_1400c8410(DAT_140e44aa4,0x1e,0xb,0,param_1[0xd],in_stack_fffffffffffffe10 & 0xffff0000,
                  dVar27,dVar21,CONCAT44(uVar45,0xff),0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44e48,0x1e,7);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    param_1[0x15] = 0;
    goto LAB_140066a13;
  case 0x12:
  case 0x13:
  case 0x14:
    dVar21 = dVar25;
    if (uVar5 == 1) {
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 0xc);
      dVar21 = DAT_140539f00;
    }
    dVar22 = DAT_14053a020;
    uVar4 = SUB84(DAT_140539d28,0);
    uVar36 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    fVar35 = fVar31;
    fVar29 = fVar32;
    dVar26 = dVar25;
    if (iVar17 == 0x12) {
      if (-1 < (int)uVar5) {
        dVar21 = dVar27;
        if ((int)uVar5 < 0x32) {
          FUN_140332d90(((double)(int)uVar5 - 0.0) * DAT_14053a670 * DAT_14053a020 * DAT_140539d28);
          uVar4 = SUB84(DAT_140539d28,0);
          uVar36 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
        }
        goto LAB_140068052;
      }
    }
    else {
      fVar35 = DAT_14053ade0;
      fVar29 = DAT_14053ae4c;
      dVar26 = DAT_140539f38;
      if ((iVar17 != 0x13) &&
         (fVar35 = fVar31, fVar29 = fVar32, dVar26 = dVar25, dVar21 = dVar27, iVar17 == 0x14)) {
        fVar35 = DAT_14053ae90;
        fVar29 = DAT_14053ae7c;
        dVar26 = DAT_140539f80;
        dVar21 = DAT_140539f38;
      }
LAB_140068052:
      dVar24 = dVar21;
      if ((-1 < (int)uVar5) && (dVar24 = dVar26, (int)uVar5 < 0x32)) {
        dVar24 = (double)FUN_140332d90(((double)(int)uVar5 - 0.0) * DAT_14053a670 * dVar22 *
                                       (double)CONCAT44(uVar36,uVar4));
        dVar24 = (dVar26 - dVar21) * dVar24 + dVar21;
      }
    }
    dVar21 = (double)FUN_140332d90();
    fVar34 = (float)(dVar21 * (double)(fVar35 - (float)param_1[0xe])) + (float)param_1[0xe];
    dVar21 = (double)FUN_140332d90();
    param_1[0xc] = fVar34;
    fVar29 = (float)(dVar21 * (double)(fVar29 - (float)param_1[0xf])) + (float)param_1[0xf];
    dVar21 = (double)FUN_140332d90();
    param_1[0xd] = fVar29;
    fVar35 = (float)dVar24 * DAT_14053b400;
    dVar22 = (double)FUN_140332d90();
    dVar27 = (dVar22 * DAT_14053b088 + dVar27) * dVar24;
    dVar22 = (double)FUN_140332d90();
    param_1[10] = fVar34;
    dVar24 = (dVar22 + DAT_140539f00) * dVar24;
    param_1[0xb] = ((float)(dVar21 * (double)fVar35) + fVar29) - (float)dVar24 * DAT_14053ad40;
    FUN_1400c8410(DAT_140e44aa4,0x1e,0xb);
    lVar16 = 0x37c;
    if (0x18 < (int)uVar5) {
      lVar16 = 0x378;
    }
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44ad0 + lVar16),0x1e,7);
    FUN_1400c8410(DAT_140e44a74,0x19,0xb);
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      FUN_140070d00(10,DAT_140e44aa4,0x1d);
    }
    if (param_1[3] == 0x32) {
      iVar17 = 0;
      uVar4 = param_1[0xc];
      uVar5 = ((uint)(param_1[5] * 0x4d) >> 0x1e ^ param_1[5] * 0x4d) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      do {
        FUN_14006c2f0(5,0,uVar4);
        iVar17 = iVar17 + 1;
      } while (iVar17 < 0x11);
      FUN_140184700(((param_1[5] * 0x14 + -0xa5) / 10) * DAT_140e44190,DAT_140e47300);
      FUN_14018a340(DAT_140e47300,1,1);
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    goto LAB_140066a13;
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    fVar35 = (float)param_1[0xc];
    fVar29 = (float)param_1[0xd];
    if (uVar5 == 1) {
      param_1[0xe] = fVar35;
      param_1[0xf] = fVar29;
    }
    fVar32 = DAT_14053ae90;
    dVar21 = dVar26;
    if ((iVar17 != 0x16) && (fVar32 = DAT_14053ae30, iVar17 != 0x17)) {
      if (iVar17 == 0x18) {
        fVar33 = DAT_14053b380;
        if ((-1 < (int)uVar5) && ((int)uVar5 < 0x46)) {
          FUN_140332d90(((double)(int)uVar5 - _DAT_14053b170) * DAT_14053a5d8 * DAT_14053a020 *
                        DAT_140539d28);
          fVar33 = DAT_14053b380;
          fVar32 = DAT_14053ae30;
        }
      }
      else {
        fVar32 = fVar34;
        if (((iVar17 == 0x15) && (dVar21 = DAT_140539f58, -1 < (int)uVar5)) &&
           (dVar21 = dVar26, (int)uVar5 < 0x46)) {
          dVar21 = (double)FUN_140332d90(((double)(int)uVar5 - _DAT_140539cc0) * DAT_14053a5d8 *
                                         DAT_14053a020 * DAT_140539d28);
          dVar21 = dVar21 * DAT_140539f00 + DAT_140539f58;
        }
      }
    }
    if ((int)uVar5 < 0x47) {
      dVar24 = (double)FUN_140332d90();
      fVar35 = (float)(dVar24 * (double)(fVar32 - (float)param_1[0xe])) + (float)param_1[0xe];
      dVar24 = (double)FUN_140332d90();
      param_1[0xc] = fVar35;
      fVar29 = (float)(dVar24 * (double)(fVar33 - (float)param_1[0xf])) + (float)param_1[0xf];
      dVar24 = (double)FUN_140332d90();
      param_1[0xd] = fVar29;
      fVar29 = (float)(dVar24 * (double)((float)dVar21 * DAT_14053b400)) + fVar29;
      dVar24 = (double)FUN_140332d90();
      dVar27 = (dVar24 * DAT_14053b088 + dVar27) * dVar21;
      dVar24 = (double)FUN_140332d90();
      dVar25 = DAT_14053a018;
      dVar22 = DAT_140539f68;
      iVar17 = 0;
      uVar9 = ((int)uVar5 < 0x23) + 0xde;
      dVar24 = (dVar24 + DAT_140539f00) * dVar21;
      if (uVar5 == 0x46) {
        uVar5 = 0;
        iVar19 = 0;
        uVar3 = 0x1b;
        do {
          uVar10 = param_1[5] * 0x58 + iVar19;
          uVar15 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
          uVar7 = 5;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar10 = uVar15 * 0x800 ^ uVar15;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ DAT_140e9fd18 ^ uVar10;
          if ((uVar5 & 1) != 0) {
            uVar7 = 3;
          }
          uVar28 = (ulonglong)uVar3;
          auVar42._12_4_ = in_stack_fffffffffffffe18._12_4_;
          auVar42._0_8_ = in_stack_fffffffffffffe18._0_8_;
          auVar42._8_4_ = 1;
          dVar26 = (double)(int)uVar5 * dVar22 + dVar25;
          in_stack_fffffffffffffe18._8_8_ = auVar42._8_8_;
          in_stack_fffffffffffffe18._0_8_ = dVar26;
          FUN_1400709b0(uVar7,0,param_1[0xc],uVar15,
                        (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001),0,dVar26,
                        in_stack_fffffffffffffe18._8_8_,uVar28,0x10000,0);
          uVar5 = uVar5 + 1;
          iVar19 = iVar19 + 0x378;
          uVar3 = uVar3 + 2;
        } while ((int)uVar3 < 0x23);
        iVar19 = 0;
        iVar18 = 0;
        fVar34 = (float)dVar24 * DAT_14053ad40;
        fVar32 = (float)dVar27 * DAT_14053ad40;
        do {
          iVar2 = param_1[5];
          uVar5 = ((uint)(iVar18 + iVar2) >> 0x1e ^ iVar18 + iVar2) * 0x6c078965 + 1;
          uVar3 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
          uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 3;
          uVar5 = uVar5 * 0x800 ^ uVar5;
          uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 4;
          uVar5 = (uVar3 >> 0xb ^ uVar5) >> 8 ^ uVar3 ^ uVar5;
          iVar11 = (uVar5 / 0x6401 & 0xffff) * 0x6401;
          uVar4 = FUN_140133f30(iVar11,param_1[0xb],0,
                                CONCAT22((short)(uVar5 >> 0x10),
                                         ((short)uVar5 - (short)iVar11) + -0x7200),fVar32,fVar34,
                                in_stack_fffffffffffffe18,uVar28);
          uVar5 = iVar2 * 0x2c + iVar19;
          uVar3 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
          uVar5 = uVar3 * 0x800 ^ uVar3;
          DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
          uVar7 = FUN_140134db0(iVar17 + iVar2,(int)DAT_14053a0b0,DAT_14053a268);
          uVar28 = 0;
          auVar43._12_4_ = in_stack_fffffffffffffe18._12_4_;
          auVar43._0_8_ = in_stack_fffffffffffffe18._0_8_;
          auVar43._8_4_ = 1;
          in_stack_fffffffffffffe18._8_8_ = auVar43._8_8_;
          in_stack_fffffffffffffe18._0_8_ = uVar7;
          FUN_14006c2f0(0xc,0,uVar4);
          iVar18 = iVar18 + 99;
          iVar17 = iVar17 + 999;
          iVar19 = iVar19 + 9999;
        } while (iVar18 < 0x3180);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47300);
        FUN_14018a340(DAT_140e47300,1,1);
      }
    }
    else {
      dVar27 = (double)FUN_140332d90();
      uVar9 = 0xde;
      dVar24 = (dVar27 * _DAT_14053b048 + DAT_140539f00) * dVar21;
      dVar27 = dVar21;
    }
    param_1[10] = fVar35;
    param_1[0xb] = fVar29 - (float)dVar24 * DAT_14053ad40;
    FUN_1400c8410(DAT_140e44aa4,0x1e,0xb);
    FUN_1400c8410((&DAT_140e44ad0)[uVar9],0x1e,7);
    FUN_1400c8410(DAT_140e44a74,0x19,0xb);
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      FUN_140070d00(10,DAT_140e44aa4,0x1d);
    }
    if ((param_1[3] == 0x78) || ((param_1[5] == 0x18 && (param_1[3] == 0x23)))) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    if (DAT_140539f80 <= dVar21) {
      param_1[0x15] = 0;
    }
    goto LAB_140066a13;
  case 0x1a:
    puVar6 = DAT_140e45d28;
    if ((uVar5 == 1) && (uVar4 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base();
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      puVar6[1] = 0x2f;
      puVar6[2] = 0x3c;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 4) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0x1e;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0x40;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      *(undefined4 *)(puVar6 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x54) = uVar4;
      puVar6[0xb] = 0;
      if (bVar20) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    dVar26 = DAT_14053a9d8;
    dVar25 = DAT_14053a3d0;
    dVar22 = DAT_14053a020;
    dVar27 = DAT_140539d28;
    iVar17 = param_1[3];
    if (iVar17 < 0x5a) {
      uVar4 = SUB84(DAT_14053a5a0,0);
      uVar36 = (undefined4)((ulonglong)DAT_14053a5a0 >> 0x20);
      if (iVar17 < 0) {
LAB_140068edf:
        local_194 = (iVar17 >> 0x1f & 0xffffff01U) + 0xff;
        if (-1 < iVar17) {
          if (0x4f < iVar17) goto LAB_140068f7a;
          dVar25 = ((double)iVar17 - 0.0) * (double)CONCAT44(uVar36,uVar4);
          goto LAB_140068f8e;
        }
        if (0x4f < iVar17) goto LAB_140068f7a;
      }
      else {
        if (iVar17 < 0x50) {
          FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a5a0 * DAT_14053a020 * DAT_140539d28);
          FUN_140332d90(((double)iVar17 - 0.0) * DAT_14053a5a0 * dVar22 * dVar27);
          uVar4 = SUB84(DAT_14053a5a0,0);
          uVar36 = (undefined4)((ulonglong)DAT_14053a5a0 >> 0x20);
          goto LAB_140068edf;
        }
        FUN_140332d90(((double)iVar17 - DAT_14053a3d0) * DAT_14053a9d8 * DAT_14053a020 *
                      DAT_140539d28);
        FUN_140332d90(((double)iVar17 - dVar25) * dVar26 * dVar22 * dVar27);
LAB_140068f7a:
        dVar25 = ((double)iVar17 - DAT_14053a3d0) * dVar26;
LAB_140068f8e:
        dVar25 = (double)FUN_140332d90(dVar25 * dVar22 * dVar27);
        local_194 = (uint)(dVar25 * DAT_14053a5f8);
      }
      if (0x4f < iVar17) {
        if (iVar17 < 0x5a) {
          FUN_140332d90(((double)iVar17 - DAT_14053a3f8) * dVar26 * dVar22 * dVar27);
        }
        if (iVar17 == 0x50) {
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472cc);
          FUN_14018a340(DAT_140e472cc,1,1);
        }
        goto LAB_1400690b3;
      }
      lVar16 = 0xde;
    }
    else {
      FUN_140332d90();
      FUN_140332d90();
LAB_1400690b3:
      FUN_1400c8410(DAT_140e44aa8,0x1d,8);
      FUN_1400c8410(DAT_140e44aa8,0x1d,8);
      lVar16 = 0xe0;
    }
    if (param_1[3] == 0x50) {
      iVar19 = 0;
      iVar17 = 0;
      do {
        iVar18 = param_1[3];
        uVar5 = iVar18 + iVar17;
        uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
        dVar30 = (double)(((uVar9 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ uVar9) % 0x51);
        dVar25 = (double)FUN_1403307c0();
        fVar35 = (float)param_1[10];
        dVar26 = (double)FUN_140332d90();
        uVar5 = iVar18 * 0x2c + iVar19;
        uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        uVar5 = uVar9 * 0x800 ^ uVar9;
        DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        FUN_140134db0(dVar26 * dVar30,(int)DAT_140539ff0,DAT_14053a1b8);
        FUN_14006c2f0(0xc,0,(float)(dVar25 * dVar30) + fVar35);
        iVar17 = iVar17 + 999;
        iVar19 = iVar19 + 0xd05;
      } while (iVar17 < 0x25cdd);
    }
    uVar5 = param_1[3];
    if ((int)uVar5 < 0x78) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar19 = (uVar3 & 0xffff) - (uint)uVar1;
      iVar17 = iVar19 + 0x10000;
      if (-0x8001 < iVar19) {
        iVar17 = iVar19;
      }
      iVar19 = iVar17 + -0x10000;
      if (iVar17 < 0x8001) {
        iVar19 = iVar17;
      }
      if (iVar19 < 1) {
        uVar13 = uVar1;
        if ((iVar19 < 0) && (uVar13 = uVar1 - 0x200, -0x200 < iVar19)) {
          uVar13 = uVar12;
        }
      }
      else {
        uVar13 = uVar12;
        if (0x1ff < iVar19) {
          uVar13 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar13;
      dVar27 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar27 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    else {
      if (uVar5 == 0x78) {
        *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
LAB_140069523:
        dVar27 = (double)FUN_140332d90(((double)(int)uVar5 - 0.0) * DAT_14053a4d8 * dVar22 * dVar27)
        ;
        fVar35 = (float)(dVar27 * _DAT_14053a7b0) - DAT_14053aea8;
      }
      else {
        fVar35 = DAT_14053b410;
        if ((int)uVar5 < 0xf0) goto LAB_140069523;
      }
      dVar27 = (double)FUN_140332d90();
      param_1[10] = (float)(dVar27 * (double)fVar35) + (float)param_1[0xc];
      dVar27 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar27 * DAT_14053a3a0) + (float)param_1[0xd];
      if ((uVar5 & 1) == 0) {
        FUN_140070d00(5,DAT_140e44aa0,0x1c);
      }
    }
    if (param_1[3] == 0xf0) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    param_1[0x15] = 0;
    uVar9 = local_194;
    break;
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    if (uVar5 == 1) {
      if (iVar17 == 0x1b) {
        param_1[0xb] = 0x42c80000;
LAB_1400696bc:
        *(undefined2 *)(param_1 + 0x10) = 0x7830;
        *pfVar14 = 870.0;
      }
      else if (iVar17 == 0x1c) {
        *pfVar14 = -150.0;
        param_1[0xb] = 0x43700000;
        *(undefined2 *)(param_1 + 0x10) = 2000;
      }
      else {
        if (iVar17 == 0x1d) {
          param_1[0xb] = 0x43f00000;
          goto LAB_1400696bc;
        }
        if (iVar17 == 0x1e) {
          *pfVar14 = 120.0;
          param_1[0xb] = 0x44598000;
          *(undefined2 *)(param_1 + 0x10) = 0xc7d0;
        }
        else if (iVar17 == 0x1f) {
          *pfVar14 = 400.0;
          param_1[0xb] = 0xc3160000;
          *(undefined2 *)(param_1 + 0x10) = 0x3830;
        }
      }
      uVar8 = _UNK_14053bb38;
      uVar7 = _DAT_14053bb30;
      *(undefined8 *)(param_1 + 0x12) = 0x4024000000000000;
      FUN_140070d00(0x41,DAT_140e41a90,0x50,0,param_1[0xb],
                    CONCAT22(uVar39,*(undefined2 *)(param_1 + 0x10)),0,uVar7,uVar8,0x32,0xff,0xff,
                    0xff,0x80,param_1[1]);
    }
    dVar22 = DAT_14053a020;
    dVar27 = DAT_140539d28;
    iVar17 = param_1[3];
    if (0x31 < iVar17) {
      dVar25 = *(double *)(param_1 + 0x12);
      dVar26 = (double)FUN_1403307c0();
      fVar32 = (float)(dVar26 * dVar25) + (float)param_1[10];
      param_1[10] = fVar32;
      dVar26 = (double)FUN_140332d90();
      dVar30 = (double)iVar17 - DAT_14053a380;
      fVar31 = (float)(dVar26 * dVar25) + (float)param_1[0xb];
      *(double *)(param_1 + 0x12) = dVar25 + DAT_140539e60;
      dVar30 = dVar30 * _DAT_14053a990;
      param_1[0xb] = fVar31;
      FUN_140332d90(dVar30 * dVar22 * dVar27);
      FUN_140332d90();
      iVar19 = param_1[5];
      lVar16 = 0xe0;
      uVar5 = iVar17 * 0x58 + iVar19;
      uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
      uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      uVar3 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
      uVar9 = iVar17 * 0x378 + iVar19;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
      dVar22 = (double)(((uVar3 >> 0xb ^ uVar5) >> 8 ^ uVar3 ^ uVar5) % 0x6f);
      DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
      dVar27 = (double)FUN_1403307c0();
      fVar32 = (float)(dVar27 * dVar22) + fVar32;
      dVar27 = (double)FUN_140332d90();
      fVar34 = DAT_14053af04;
      fVar29 = DAT_14053aeb8;
      fVar35 = DAT_14053ac58;
      uVar28 = (ulonglong)(uint)fVar32;
      fVar31 = (float)(dVar27 * dVar22) + fVar31;
      if ((((DAT_140e445d8 / DAT_14053ab70 + DAT_14053ac58 <= fVar32) &&
           (fVar32 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aeb8)) && (DAT_14053ac58 <= fVar31))
         && (fVar31 <= DAT_14053af04)) {
        uVar5 = iVar17 * 0x22b + iVar19;
        uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        FUN_140134db0(iVar17 * 0x15b3 + iVar19,uVar36,DAT_140539ff0);
        FUN_14006c2f0(2,0x12,uVar28);
      }
      fVar32 = DAT_140e445d8;
      iVar17 = param_1[3];
      if (iVar17 - 0x32U < 0x5a) {
        uVar7 = FUN_140133f30(iVar17,param_1[0xb],*(undefined2 *)(param_1 + 0x10),
                              (short)iVar17 * 0x9c4,DAT_14053ad54,DAT_14053ad2c);
        uVar8 = FUN_140133f30();
        fVar31 = DAT_14053ab70;
        local_res18 = (float)uVar7;
        if (((fVar32 / DAT_14053ab70 + fVar35 <= local_res18) &&
            (local_res18 <= fVar32 / DAT_14053ab70 + fVar29)) &&
           ((fStackX_1c = (float)((ulonglong)uVar7 >> 0x20), fVar35 <= fStackX_1c &&
            (fStackX_1c <= fVar34)))) {
          FUN_14006c2f0(0xd,3);
          fVar32 = DAT_140e445d8;
        }
        local_190 = (float)uVar8;
        if (((fVar32 / fVar31 + fVar35 <= local_190) && (local_190 <= fVar32 / fVar31 + fVar29)) &&
           ((fStack_18c = (float)((ulonglong)uVar8 >> 0x20), fVar35 <= fStack_18c &&
            (fStack_18c <= fVar34)))) {
          FUN_14006c2f0(0xd,3);
        }
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      FUN_1400c8410(DAT_140e44aa8,0x1d,8);
      FUN_1400c8410(DAT_140e44aa8,0x1d,8);
      if ((*(byte *)(param_1 + 3) & 1) == 0) {
        FUN_140070d00(5,DAT_140e44aa0,0x1c);
      }
    }
    if (param_1[3] == 0x8c) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    param_1[0x15] = 0;
    uVar9 = local_194;
    break;
  case 99:
    if ((int)uVar5 < 0) {
      *pfVar14 = (float)uStack_140;
      param_1[0xb] = uStack_140._4_4_;
    }
    else {
      if ((int)uVar5 < 300) {
        dVar27 = (double)FUN_140332d90(((double)(int)uVar5 - _DAT_14053b220) * DAT_14053a388 *
                                       DAT_14053a020 * DAT_140539d28);
        *pfVar14 = (float)uStack_140;
        dVar27 = dVar27 + 0.0;
        param_1[0xb] = uStack_140._4_4_;
        if ((int)uVar5 < 0xf0) {
          FUN_140332d90(((double)(int)uVar5 - 0.0) * _DAT_14053a3c8 * dVar30 * dVar22);
          goto LAB_140069ffa;
        }
      }
      else {
        dVar27 = 0.0;
        *pfVar14 = (float)uStack_140;
        param_1[0xb] = uStack_140._4_4_;
      }
      if ((int)uVar5 < 300) {
        FUN_140332d90(((double)(int)uVar5 - DAT_14053a548) * DAT_14053a628 * dVar30 * dVar22);
      }
    }
LAB_140069ffa:
    FUN_140332d90(((double)(int)uVar5 - 0.0) * _DAT_14053a9b8 * dVar30 * dVar22);
    if ((-1 < (int)uVar5) && (((int)uVar5 < 0xf0 || ((int)uVar5 < 300)))) {
      FUN_140332d90();
    }
    FUN_140332d90();
    lVar16 = 0xe0;
    if ((uVar5 < 0x118) && ((uVar5 & 1) == 0)) {
      uVar3 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      auVar44._12_4_ = in_stack_fffffffffffffe18._12_4_;
      auVar44._0_8_ = in_stack_fffffffffffffe18._0_8_;
      auVar44._8_4_ = 0x14;
      stage_entity_spawn_candidate
                (0x12a,99999999,0,uVar3,param_1[0xb],
                 CONCAT22(uVar39,(short)(DAT_140e9fd1c / 0xd2f1) * 0x2d0f + (short)DAT_140e9fd1c +
                                 0x5688),DAT_14053a218,auVar44._8_8_,CONCAT44(uVar45,1),param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d4);
      FUN_14018a340(DAT_140e472d4,1,1);
    }
    dVar21 = dVar27;
    dVar24 = dVar27;
    if ((int)param_1[3] < 0xb4) {
      param_1[0x15] = 0;
    }
    else {
      if (param_1[3] != 300) goto switchD_140066583_caseD_20;
      *param_1 = 0;
    }
  }
  dVar27 = dVar21;
  FUN_1400c8410(DAT_140e44aa0,0x1e,7);
  if (0 < (int)uVar9) {
    FUN_1400c8410(DAT_140e44aa0,0x1e,8);
  }
  FUN_1400c8410((&DAT_140e44ad0)[lVar16],0x1e,7);
LAB_140066a13:
  param_1[0x14] = (int)((dVar24 + dVar27) * DAT_14053a4a0 * DAT_140539f00);
  return;
}


