// Function: FUN_140062060 @ 140062060
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140062060(undefined4 *param_1)

{
  float *pfVar1;
  ushort uVar2;
  undefined8 uVar3;
  double dVar4;
  double dVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  ushort uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  bool bVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float *local_res18;
  undefined8 in_stack_fffffffffffffea0;
  undefined4 uVar27;
  undefined8 uVar28;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined1 local_b0 [120];
  
  uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffea0 >> 0x20);
  uStack_100 = 0;
  uStack_100._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar9 = DAT_140e45d80, uStack_100._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar9 + 4) == DAT_140e44308) {
        local_108 = *(undefined8 *)(lVar9 + 0x10);
        uStack_100 = *(undefined8 *)(lVar9 + 0x18);
        local_f8 = *(undefined8 *)(lVar9 + 0x20);
      }
      lVar9 = *(longlong *)(lVar9 + 0x60);
    } while (lVar9 != 0);
  }
  pfVar1 = (float *)(param_1 + 0xb);
  fVar22 = *pfVar1;
  fVar23 = (float)param_1[10];
  dVar24 = (double)FUN_1403300b4((double)(DAT_140e4490c - fVar22),
                                 SUB84((double)(DAT_140e44908 - fVar23),0));
  dVar24 = dVar24 * DAT_14053aba0;
  FUN_1403300b4((double)((float)param_1[0xd] - fVar22),
                SUB84((double)((float)param_1[0xc] - fVar23),0));
  fVar22 = (float)FUN_140334430();
  fVar23 = (float)FUN_140334430();
  if (fVar22 + fVar23 < 0.0) {
    fVar22 = (float)FUN_1403352f8();
  }
  else {
    fVar22 = SQRT(fVar22 + fVar23);
  }
  if ((local_108._4_4_ == 0x78) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],*pfVar1,0,DAT_14053a4f0,CONCAT44(uVar27,param_1[0x14]),1
               ,0);
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  uVar3 = _UNK_14053bb28;
  uVar8 = _DAT_14053bb20;
  local_res18 = (float *)(param_1 + 0xb);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar17 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar12 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
    uVar17 = uVar17 * 0x800 ^ uVar17;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    uVar13 = DAT_1407c7798 * 0x457 + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar12 >> 0xb ^ uVar17) >> 8 ^ uVar12 ^ uVar17) % 0x12d + 0xd2);
    uVar17 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar17 = uVar17 * 0x800 ^ uVar17;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ uVar17 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0xdc);
  }
  iVar18 = param_1[5];
  param_1[0x15] = 1;
  if (iVar18 != 0) {
    if (iVar18 == 1) {
      dVar24 = *(double *)(param_1 + 0x12);
      dVar25 = (double)FUN_1403307c0();
      fVar23 = (float)(dVar25 * ((double)fVar22 / dVar24)) + (float)param_1[10];
      param_1[10] = fVar23;
      dVar25 = (double)FUN_140332d90();
      fVar22 = (float)(dVar25 * ((double)fVar22 / dVar24)) + *local_res18;
      *local_res18 = fVar22;
      iVar18 = param_1[3];
      if (iVar18 == 1) {
        param_1[0xc] = 320.0;
        param_1[0xd] = 220.0;
      }
      else if ((0xd1 < iVar18) && (iVar18 < 0x1a5)) {
        dVar24 = (double)FUN_140332d90(((double)iVar18 - _DAT_14053a5b0) * _DAT_14053a658 *
                                       DAT_14053a020 * DAT_140539d28);
        param_1[0xc] = (float)(dVar24 * _DAT_14053b208) + DAT_14053ae30;
        dVar24 = (double)FUN_140332d90();
        param_1[0xd] = (float)(dVar24 * DAT_14053a3f8) + DAT_14053ade8;
      }
      FUN_1400c8410(DAT_140e44a94,0x1e,7,fVar23,fVar22 - DAT_14053acfc,0,uVar8,uVar3,0xff,0xff,0xff,
                    0xff,1,0);
      if (param_1[3] == 0x1c2) {
        param_1[5] = param_1[5] + 1;
        *(undefined8 *)(param_1 + 0x12) = 0x3fe6666666666666;
        param_1[3] = 0;
      }
      param_1[0x15] = 0;
      goto LAB_140062f9f;
    }
    if (iVar18 == 2) {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar14 = ((int)dVar24 & 0xffffU) - (uint)uVar2;
      iVar18 = iVar14 + 0x10000;
      if (-0x8001 < iVar14) {
        iVar18 = iVar14;
      }
      iVar14 = iVar18 + -0x10000;
      if (iVar18 < 0x8001) {
        iVar14 = iVar18;
      }
      uVar15 = (ushort)(int)dVar24;
      if (iVar14 < 1) {
        uVar16 = uVar2;
        if ((iVar14 < 0) && (uVar16 = uVar2 - 0x200, -0x200 < iVar14)) {
          uVar16 = uVar15;
        }
      }
      else {
        uVar16 = uVar15;
        if (0x1ff < iVar14) {
          uVar16 = uVar2 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar16;
      dVar24 = (double)FUN_1403307c0();
      fVar23 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar23;
      dVar24 = (double)FUN_140332d90();
      fVar22 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar22;
      FUN_1400c8410(DAT_140e44a94,0x1e,7,fVar23,fVar22 - DAT_14053acfc,0,uVar8,uVar3,0xff,0xff,0xff,
                    0xff,1,0);
      if (param_1[3] == 800) {
        param_1[3] = 0;
        *(undefined8 *)(param_1 + 0x12) = 0x4034000000000000;
        param_1[5] = 1;
      }
      param_1[0x15] = 0;
      goto LAB_140062f9f;
    }
    if (iVar18 != 99) goto LAB_140062f9f;
    iVar18 = param_1[3];
    iVar14 = 0;
    if (iVar18 < 0x5a) {
LAB_1400626fa:
      iVar19 = 0;
      if (iVar18 < 0x8c) {
        iVar19 = iVar14;
      }
      puVar10 = DAT_140e45d28;
      if (iVar18 == 1) {
        fVar22 = *pfVar1;
        uVar27 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar10 = (undefined8 *)_malloc_base(0x60);
          if (puVar10 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar10 + 0x14) = uVar27;
          *(float *)(puVar10 + 3) = fVar22;
          *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar27;
          *(float *)(puVar10 + 4) = fVar22;
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
          if (bVar21) {
            DAT_140e45d78 = puVar10;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar10;
          }
        }
      }
    }
    else {
      iVar14 = 0xff;
      if (iVar18 < 100) {
        dVar24 = (double)FUN_140332d90(((double)iVar18 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar19 = (int)(dVar24 * DAT_14053a5f8);
        puVar10 = DAT_140e45d28;
      }
      else {
        if (0x8b < iVar18) goto LAB_1400626fa;
        dVar24 = (double)FUN_140332d90(((double)iVar18 - DAT_14053a3a0) * DAT_14053a6d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar19 = 0;
        puVar10 = DAT_140e45d28;
        if (iVar18 < 0x8c) {
          iVar19 = (int)(dVar24 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar10;
    iVar18 = param_1[3];
    if (iVar18 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar18 = param_1[3];
      *pfVar1 = (float)iVar18 * _DAT_140539ccc + *pfVar1;
    }
    puVar10 = DAT_140e45d28;
    if (iVar18 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      fVar22 = *pfVar1;
      uVar27 = param_1[10];
      puVar10 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar10 = (undefined8 *)_malloc_base(0x60);
        if (puVar10 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar10 + 0x14) = uVar27;
        *(float *)(puVar10 + 3) = fVar22;
        *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar27;
        *(float *)(puVar10 + 4) = fVar22;
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
        if (bVar21) {
          DAT_140e45d78 = puVar10;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar10;
        }
      }
    }
    DAT_140e45d28 = puVar10;
    uVar27 = DAT_140e41ab8;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar11 = uVar27;
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
    if (bVar21) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    DAT_140e46c88 = puVar11;
    if ((int)param_1[3] < 100) {
      FUN_1400c8410(DAT_140e44a94,0x1e,7,param_1[10],(float)param_1[0xb] - DAT_14053acfc,0,uVar8,
                    uVar3,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[3] == 0x8c) {
      *param_1 = 0;
    }
    goto LAB_140062f9f;
  }
  uVar17 = param_1[3];
  puVar10 = (undefined8 *)FUN_140135060(local_b0,uVar17,0x14);
  dVar5 = DAT_14053a798;
  dVar4 = DAT_14053a5f8;
  dVar25 = DAT_14053a020;
  dVar24 = DAT_140539d28;
  uVar28 = *puVar10;
  iVar18 = 0;
  if (0x95 < (int)uVar17) {
    iVar18 = 0xff;
  }
  uVar27 = *(undefined4 *)(puVar10 + 1);
  if (((int)uVar17 < 0x96) || (0xb3 < (int)uVar17)) {
    iVar14 = ((int)uVar17 >> 0x1f & 0xffffff01U) + 0xff;
    if (-1 < (int)uVar17) {
      if ((int)uVar17 < 0x96) {
        dVar24 = (double)FUN_140332d90(((double)(int)uVar17 - 0.0) * _DAT_14053a478 * DAT_14053a020
                                       * DAT_140539d28);
        goto LAB_140062bef;
      }
      if (uVar17 < 0xb4) goto LAB_140062bca;
    }
  }
  else {
    dVar26 = (double)FUN_140332d90(((double)(int)uVar17 - DAT_14053a510) * DAT_14053a798 *
                                   DAT_14053a020 * DAT_140539d28);
    iVar18 = (int)(dVar26 * dVar4);
LAB_140062bca:
    dVar24 = (double)FUN_140332d90(((double)(int)uVar17 - DAT_14053a4a0) * dVar5 * dVar25 * dVar24);
LAB_140062bef:
    iVar14 = (int)(dVar24 * dVar4);
  }
  piVar20 = param_1 + 3;
  FUN_1400c8410(DAT_140e44a94,0x1e,7,param_1[10],(float)param_1[0xb] - DAT_14053acfc,0,uVar8,uVar3,
                0xff,0xff,0xff,iVar18,1,0,uVar28);
  iVar18 = 0;
  if ((int)uVar17 < 0xb4) {
    iVar18 = iVar14;
  }
  FUN_1400c8410(DAT_140e44a94,0x1e,8,param_1[10],(float)param_1[0xb] - DAT_14053acfc,0,uVar8,uVar3,
                (int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar27,iVar18,1,0);
  uVar27 = DAT_14053b3f8;
  if (*piVar20 == 0) {
    stage_entity_spawn_candidate
              (0x11e,99999999,0,0,DAT_14053b3f8,0x4000,DAT_14053a1e8,0x3c,1,param_1[1]);
    uVar6 = DAT_14053b3bc;
    uVar3 = DAT_14053a278;
    stage_entity_spawn_candidate
              (0x11f,99999999,0,DAT_14053ace8,DAT_14053b3bc,0x4000,DAT_14053a278,0x3c,1,param_1[1]);
    stage_entity_spawn_candidate
              (0x11f,99999999,0,DAT_14053b36c,uVar6,0x4000,uVar3,0x3c,1,param_1[1]);
    uVar6 = DAT_14053b3f0;
    uVar3 = DAT_14053a2d8;
    stage_entity_spawn_candidate
              (0x120,99999999,0,DAT_14053ad80,DAT_14053b3f0,0x4000,DAT_14053a2d8,0x3c,1,param_1[1]);
    stage_entity_spawn_candidate
              (0x120,99999999,0,DAT_14053b3b0,uVar6,0x4000,uVar3,0x3c,1,param_1[1]);
    uVar7 = DAT_14053b3fc;
    uVar3 = DAT_14053a340;
    stage_entity_spawn_candidate
              (0x121,99999999,0,DAT_14053ade0,DAT_14053b3fc,0x4000,DAT_14053a340,0x3c,1,param_1[1]);
    uVar6 = DAT_14053b3e4;
    stage_entity_spawn_candidate
              (0x121,99999999,0,DAT_14053b3e4,uVar7,0x4000,uVar3,0x3c,1,param_1[1]);
    uVar3 = DAT_14053a380;
    stage_entity_spawn_candidate
              (0x122,99999999,0,DAT_14053ae14,uVar6,0x4000,DAT_14053a380,0x3c,1,param_1[1]);
    stage_entity_spawn_candidate(0x122,99999999,0,uVar27,uVar6,0x4000,uVar3,0x3c,1,param_1[1]);
  }
  if (*piVar20 == 0xbe) {
    param_1[5] = param_1[5] + 1;
    param_1[8] = (undefined4)local_f8;
    *(undefined8 *)(param_1 + 0x12) = 0x4034000000000000;
    *piVar20 = 0;
    param_1[7] = uStack_100._4_4_;
    *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
  }
LAB_140062f9f:
  iVar18 = DAT_140e44308;
  if (param_1[0x15] == 0) {
    iVar14 = param_1[7];
    if ((iVar14 < uStack_100._4_4_) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
        if (*(int *)(lVar9 + 4) == iVar18) {
          *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - (uStack_100._4_4_ - iVar14);
        }
      }
    }
    iVar18 = param_1[7];
    if (uStack_100._4_4_ < iVar18) {
      param_1[7] = uStack_100._4_4_;
      iVar18 = uStack_100._4_4_;
    }
    iVar14 = DAT_140e44308;
    if ((iVar18 < 1) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
        if (*(int *)(lVar9 + 4) == iVar14) {
          *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - uStack_100._4_4_;
        }
      }
    }
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      stage_entity_spawn_candidate(0x136,99999999,1,0,0,0,uVar8,0x14,0,param_1[1]);
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


