// Function: FUN_1400f1250 @ 1400f1250
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400f1250(undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  float *pfVar8;
  short sVar9;
  float *pfVar10;
  undefined2 uVar11;
  short sVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  float local_res10;
  float *local_res18;
  float *local_res20;
  undefined8 in_stack_fffffffffffffdd0;
  undefined8 uVar23;
  int iStack_1dc;
  uint uStack_1d4;
  undefined8 uStack_1c0;
  float local_1b8;
  undefined4 uStack_1b4;
  float fStack_1b0;
  undefined4 local_1a8;
  undefined4 local_198;
  undefined8 local_170;
  
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffdd0 >> 0x20);
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == 0)) {
    local_170._4_4_ = uStack_1d4;
  }
  else {
    local_170 = (ulonglong)uStack_1d4 << 0x20;
    lVar6 = DAT_140e45d80;
    do {
      if (*(int *)(lVar6 + 4) == DAT_140e44308) {
        local_170 = *(longlong *)(lVar6 + 0x10);
        iStack_1dc = *(int *)(lVar6 + 0xc);
        uStack_1c0._0_4_ = *(float *)(lVar6 + 0x28);
        uStack_1c0._4_4_ = *(float *)(lVar6 + 0x2c);
        local_1b8 = *(float *)(lVar6 + 0x30);
        uStack_1b4 = *(undefined4 *)(lVar6 + 0x34);
        fStack_1b0 = *(float *)(lVar6 + 0x38);
        local_1a8 = *(undefined4 *)(lVar6 + 0x40);
        local_198 = *(undefined4 *)(lVar6 + 0x50);
      }
      lVar6 = *(longlong *)(lVar6 + 0x60);
    } while (lVar6 != 0);
  }
  lVar6 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x60)) {
      if (*(int *)(lVar6 + 4) == param_1[2]) {
        uStack_1c0 = *(undefined8 *)(lVar6 + 0x28);
        local_1b8 = *(float *)(lVar6 + 0x30);
        uStack_1b4 = *(undefined4 *)(lVar6 + 0x34);
        fStack_1b0 = *(float *)(lVar6 + 0x38);
        local_1a8 = *(undefined4 *)(lVar6 + 0x40);
        local_198 = *(undefined4 *)(lVar6 + 0x50);
      }
    }
  }
  if (param_1[3] == 0) {
    param_1[0xb] = 0xc53b8000;
    param_1[0xd] = 0xc53b8000;
  }
  uVar4 = _UNK_14053bb28;
  dVar3 = _DAT_14053bb20;
  dVar13 = DAT_14053a7f8;
  dVar2 = DAT_14053a020;
  dVar17 = DAT_140539d28;
  if (param_1[6] == 0xde) {
    if (param_1[3] == 0) {
      stage_entity_spawn_candidate
                (0xdf,local_198,local_1a8,0,DAT_14053ae5c,0x4000,_DAT_14053bb20,CONCAT44(uVar7,300),
                 1,param_1[1]);
      uVar7 = DAT_14053b3e4;
      stage_entity_spawn_candidate
                (0xe0,99999999,0,DAT_14053ad90,DAT_14053b3e4,0x4000,dVar3,100,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xe0,99999999,0,DAT_14053b3b4,uVar7,0x4000,dVar3,100,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xef,7000,0x32,DAT_14053adbc,DAT_14053ad5c,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate(0xf0,7000,0x32,DAT_14053b3bc,0,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate(0xf1,20000,0x50,0,0,0x4000,dVar3,0x3c,1,param_1[1]);
    }
    fVar22 = (float)uStack_1c0 + (float)param_1[0xe];
    dVar20 = (double)DAT_140e418c8;
    param_1[10] = fVar22;
    dVar13 = (double)FUN_140332d90((dVar20 - _DAT_14053b110) * dVar13 * dVar2 * dVar17);
    dVar13 = dVar13 * DAT_14053a018;
    param_1[0xc] = fVar22;
    fVar21 = (float)dVar13 + (float)param_1[0xf] + uStack_1c0._4_4_;
    param_1[0xb] = fVar21;
    dVar13 = (double)FUN_140332d90();
    param_1[0xd] = (float)(dVar13 * DAT_14053a018) + (fVar21 - DAT_14053ad1c);
    FUN_1400c8410(DAT_140e46ea8,0x13,7,fVar22,fVar21,0,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44a2c,0x13,7,param_1[10],(float)param_1[0xb] - DAT_14053ade0,0,dVar3,uVar4
                  ,0xff,0xff,0xff,0xff,1,0);
    dVar13 = DAT_14053a7f8;
    dVar14 = (double)FUN_140332d90(((double)DAT_140e418c8 - DAT_14053b128) * DAT_14053a7f8 * dVar2 *
                                   dVar17);
    dVar20 = dVar3;
    FUN_1400c8410(DAT_140e44a30,0x13,7,param_1[0xc],param_1[0xd],0,dVar14 * DAT_140539e60 + dVar3,
                  dVar3,0xff,0xff,0xff,0xff,1,0);
    uVar7 = (undefined4)((ulonglong)dVar20 >> 0x20);
  }
  uVar5 = DAT_14053ac9c;
  if (param_1[6] == 0xdf) {
    if (param_1[3] == 0) {
      stage_entity_spawn_candidate
                (0xe2,99999999,0,DAT_14053ad94,DAT_14053ac9c,0x43e8,dVar3,CONCAT44(uVar7,100),1,
                 param_1[1]);
      stage_entity_spawn_candidate
                (0xe2,99999999,0,DAT_14053b3b8,uVar5,0x3830,dVar3,100,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xe8,7000,0x32,DAT_14053b35c,DAT_14053adb0,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xe9,7000,0x32,DAT_14053b3e8,DAT_14053ad1c,0x4000,dVar3,0x3c,1,param_1[1]);
      uVar7 = DAT_14053ace8;
      stage_entity_spawn_candidate
                (0xea,7000,0x32,DAT_14053adcc,DAT_14053ace8,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xeb,7000,0x32,DAT_14053ac60,DAT_14053b330,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xec,7000,0x32,DAT_14053b3cc,DAT_14053b348,0x4000,dVar3,0x3c,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xf4,3000,0x14,DAT_14053acf0,DAT_14053ada4,0x4000,dVar3,0x28,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xf5,3000,0x14,DAT_14053ac44,DAT_14053ad14,0x4000,dVar3,0x28,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xf6,3000,0x14,DAT_14053b378,uVar7,0x4000,dVar3,0x28,1,param_1[1]);
      stage_entity_spawn_candidate
                (0xf7,3000,0x14,DAT_14053ad80,DAT_14053b358,0x4000,dVar3,0x28,1,param_1[1]);
    }
    local_res18 = (float *)(param_1 + 0xf);
    fVar21 = (float)param_1[0xe];
    dVar20 = (double)DAT_140e418c8;
    param_1[10] = (float)uStack_1c0 + fVar21;
    dVar20 = (double)FUN_140332d90((dVar20 - DAT_14053b138) * dVar13 * dVar2 * dVar17);
    fVar22 = (float)(dVar20 * DAT_14053a018) + *local_res18 + uStack_1c0._4_4_;
    param_1[0xb] = fVar22;
    uVar23 = uVar4;
    FUN_1400c8410(DAT_140e46eac,0x12,7,(float)uStack_1c0 + fVar21,fVar22,0,dVar3,uVar4,0xff,0xff,
                  0xff,0xff,1,0);
    uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
  }
  local_res18 = (float *)(param_1 + 0xf);
  pfVar10 = (float *)(param_1 + 0xe);
  if (param_1[6] == 0xe0) {
    dVar13 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053b110) * dVar13 * dVar2 *
                                   dVar17);
    fVar21 = (float)uStack_1c0 + *pfVar10;
    sVar9 = (short)(int)(dVar13 * DAT_14053a6d0) + 0x3060;
    param_1[10] = fVar21;
    fVar22 = uStack_1c0._4_4_ + *local_res18;
    param_1[0xb] = fVar22;
    if (0.0 < *pfVar10 || *pfVar10 == 0.0) {
      dVar13 = (double)FUN_1403307c0();
      fVar18 = (float)(dVar13 * DAT_14053a598) + fVar21;
      dVar13 = (double)FUN_140332d90();
      fVar19 = (float)(dVar13 * DAT_14053a598) + fVar22;
      dVar13 = (double)FUN_1403307c0();
      dVar13 = dVar13 * _DAT_14053a6c0;
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053a6c0;
      param_1[0xc] = (float)dVar13 + fVar21;
      param_1[0xd] = (float)dVar20 + fVar22;
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xe1,99999999,0,DAT_14053ac2c,DAT_14053b430,0x4000,dVar3,CONCAT44(uVar7,100),1,
                   param_1[1]);
      }
      uVar5 = 0;
    }
    else {
      dVar13 = (double)FUN_140332d90();
      sVar9 = (short)(int)(dVar13 * _DAT_14053b230) + -0x3060;
      dVar13 = (double)FUN_1403307c0();
      fVar18 = (float)(dVar13 * DAT_14053a598) + fVar21;
      dVar13 = (double)FUN_140332d90();
      fVar19 = (float)(dVar13 * DAT_14053a598) + fVar22;
      dVar13 = (double)FUN_1403307c0();
      dVar13 = dVar13 * _DAT_14053a6c0;
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053a6c0;
      uVar5 = 1;
      param_1[0xc] = (float)dVar13 + fVar21;
      param_1[0xd] = (float)dVar20 + fVar22;
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xe1,99999999,0,DAT_14053b320,DAT_14053b430,0x4000,dVar3,CONCAT44(uVar7,100),1,
                   param_1[1]);
        uVar5 = 1;
      }
    }
    uVar23 = uVar4;
    FUN_1400c8410(DAT_140e46eb0,0x11,7,fVar18,fVar19,sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,uVar5);
    uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
  }
  pfVar8 = (float *)(param_1 + 0xb);
  pfVar10 = (float *)(param_1 + 10);
  if (param_1[6] == 0xe1) {
    dVar13 = (double)FUN_140332d90();
    sVar9 = (short)(int)(dVar13 * DAT_14053a840) + 0x24a8;
    dVar13 = (double)FUN_1403307c0();
    local_res10 = (float)(dVar13 * DAT_14053a598) + *pfVar10;
    dVar13 = (double)FUN_140332d90();
    fVar21 = (float)(dVar13 * DAT_14053a598) + *pfVar8;
    *pfVar10 = local_1b8;
    param_1[0xb] = uStack_1b4;
    if (0.0 <= fStack_1b0) {
      dVar13 = (double)FUN_140332d90();
      dVar13 = dVar13 * DAT_14053a888;
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xed,20000,100,0,0,0x4000,dVar3,CONCAT44(uVar7,0x3c),1,param_1[1]);
        stage_entity_spawn_candidate(0xf8,4000,0x1e,0,0,0x4000,dVar3,0x28,1,param_1[1]);
      }
      dVar20 = (double)FUN_1403307c0();
      fVar18 = (float)(dVar20 * _DAT_14053a660) + *pfVar10;
      dVar20 = (double)FUN_140332d90();
      local_res18._0_2_ = (undefined2)(int)dVar13;
      fVar22 = (float)(dVar20 * _DAT_14053a660) + *pfVar8;
      uVar7 = 0;
      sVar12 = sVar9;
    }
    else {
      dVar13 = (double)FUN_140332d90();
      sVar12 = (short)(int)(dVar13 * _DAT_14053b230);
      sVar9 = sVar12 + -0x24a8;
      dVar13 = (double)FUN_1403307c0();
      local_res10 = (float)(dVar13 * DAT_14053a598) + local_1b8;
      dVar13 = (double)FUN_140332d90();
      fVar21 = (float)(dVar13 * DAT_14053a598) + *pfVar8;
      dVar13 = (double)FUN_140332d90();
      local_res18._0_2_ = (undefined2)(int)(dVar13 * _DAT_14053b290);
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xee,20000,100,0,0,0x4000,dVar3,CONCAT44(uVar7,0x3c),1,param_1[1]);
        stage_entity_spawn_candidate(0xf9,4000,0x1e,0,0,0x4000,dVar3,0x28,1,param_1[1]);
      }
      dVar13 = (double)FUN_1403307c0();
      fVar18 = (float)(dVar13 * _DAT_14053a660) + *pfVar10;
      dVar13 = (double)FUN_140332d90();
      fVar22 = (float)(dVar13 * _DAT_14053a660) + *pfVar8;
      uVar7 = 1;
      sVar12 = sVar12 + 0x5b58;
    }
    param_1[0xc] = fVar18;
    param_1[0xd] = fVar22;
    *(short *)((longlong)param_1 + 0x42) = sVar12;
    FUN_1400c8410(DAT_140e46eb4,0x12,7,local_res10,fVar21,sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,
                  uVar7);
    uVar23 = uVar4;
    FUN_1400c8410(DAT_140e44a34,0x11,7,param_1[0xc],param_1[0xd],local_res18._0_2_,dVar3,uVar4,0xff,
                  0xff,0xff,0xff,1,uVar7);
    uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
  }
  dVar13 = DAT_14053a650;
  local_res18 = (float *)(param_1 + 0xf);
  if (param_1[6] == 0xe2) {
    dVar20 = (double)FUN_140332d90();
    fVar21 = (float)param_1[0xe];
    sVar9 = (short)(int)(dVar20 * DAT_14053a598) + *(short *)(param_1 + 0x10);
    uStack_1c0._0_4_ = fVar21 + (float)uStack_1c0;
    uStack_1c0._4_4_ = uStack_1c0._4_4_ + *local_res18;
    param_1[10] = (float)uStack_1c0;
    param_1[0xb] = uStack_1c0._4_4_;
    if (fVar21 < 0.0) {
      dVar20 = (double)FUN_140332d90();
      sVar9 = (short)(int)(dVar20 * DAT_14053b1f0) + *(short *)(param_1 + 0x10);
    }
    dVar14 = (double)FUN_1403307c0();
    dVar15 = (double)FUN_140332d90();
    dVar16 = (double)FUN_1403307c0();
    dVar20 = (double)FUN_140332d90();
    fVar22 = (float)(dVar14 * dVar13) + (float)uStack_1c0;
    fVar18 = (float)(dVar15 * dVar13) + uStack_1c0._4_4_;
    if (fVar21 < 0.0) {
      dVar20 = dVar20 * _DAT_14053a748;
      param_1[0xc] = (float)(dVar16 * _DAT_14053a748) + (float)uStack_1c0;
      param_1[0xd] = (float)dVar20 + uStack_1c0._4_4_;
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xe3,99999999,0,DAT_14053b320,DAT_14053b430,0x4fa0,dVar3,CONCAT44(uVar7,100),1,
                   param_1[1]);
      }
      uVar23 = uVar4;
      FUN_1400c8410(DAT_140e46ec0,0x11,7,fVar22,fVar18,sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
    }
    else {
      dVar20 = dVar20 * _DAT_14053a7b0;
      param_1[0xc] = (float)(dVar16 * _DAT_14053a7b0) + (float)uStack_1c0;
      param_1[0xd] = (float)dVar20 + uStack_1c0._4_4_;
      if (param_1[3] == 0) {
        stage_entity_spawn_candidate
                  (0xe3,99999999,0,DAT_14053ac2c,DAT_14053b430,0x3830,dVar3,CONCAT44(uVar7,100),1,
                   param_1[1]);
      }
      uVar23 = uVar4;
      FUN_1400c8410(DAT_140e46eb8,0x11,7,fVar22,fVar18,sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
    }
  }
  pfVar8 = (float *)(param_1 + 0xb);
  pfVar10 = (float *)(param_1 + 10);
  if (param_1[6] == 0xe3) {
    dVar13 = (double)FUN_140332d90();
    sVar9 = (short)(int)(dVar13 * DAT_14053a6d0) + *(short *)(param_1 + 0x10);
    dVar13 = (double)FUN_140332d90();
    fVar21 = *pfVar10;
    sVar12 = (short)(int)(dVar13 * DAT_14053a888) + 1000;
    dVar20 = (double)FUN_1403307c0();
    dVar13 = DAT_14053a650;
    dVar20 = dVar20 * DAT_14053a650;
    dVar14 = (double)FUN_140332d90();
    iVar1 = param_1[3];
    fVar22 = *pfVar8;
    fVar18 = fVar21;
    if (0 < iVar1) {
      *pfVar10 = local_1b8;
      param_1[0xb] = uStack_1b4;
      fVar18 = local_1b8;
    }
    local_res20 = (float *)(param_1 + 0xb);
    local_res18 = (float *)(param_1 + 10);
    if (0.0 <= fStack_1b0) {
      *(short *)((longlong)param_1 + 0x42) = sVar9;
      *(short *)(param_1 + 0x11) = sVar12;
      if (iVar1 == 0) {
        stage_entity_spawn_candidate
                  (0xe4,7000,0x32,0,0,0x4000,dVar3,CONCAT44(uVar7,0x3c),1,param_1[1]);
        stage_entity_spawn_candidate(0xe5,7000,0x32,0,0,0x4000,dVar3,0x3c,1,param_1[1]);
        stage_entity_spawn_candidate(0xf2,3000,0x1e,0,0,0x4000,dVar3,0x28,1,param_1[1]);
      }
      dVar15 = (double)FUN_1403307c0();
      fVar19 = (float)(dVar15 * _DAT_14053a748) + *pfVar10;
      dVar15 = (double)FUN_140332d90();
      dVar15 = dVar15 * _DAT_14053a748;
      param_1[0xc] = fVar19;
      fVar18 = (float)dVar15 + *pfVar8;
      dVar15 = (double)FUN_1403307c0();
      dVar15 = dVar15 * DAT_14053a3d0;
      param_1[0xd] = fVar18;
      dVar16 = (double)FUN_140332d90();
      dVar16 = dVar16 * DAT_14053a3d0;
      FUN_1400c8410(DAT_140e44a3c,0x10,7,fVar19,fVar18,sVar12,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      FUN_1400c8410(DAT_140e46ebc,0x10,7,(float)dVar20 + fVar21,(float)(dVar14 * dVar13) + fVar22,
                    sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      dVar17 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053b180) * DAT_14053a7f8 *
                                     dVar2 * dVar17);
      FUN_1400c8410(DAT_140e44a38,0x10,7,(float)dVar15 + fVar19,(float)dVar16 + fVar18,sVar12,
                    dVar17 * DAT_140539e60 + dVar3,dVar3,0xff,0xff,0xff,0xff,1,0);
    }
    else {
      dVar20 = (double)FUN_140332d90();
      sVar9 = (short)(int)(dVar20 * _DAT_14053b220) + *(short *)(param_1 + 0x10);
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053b260;
      dVar14 = (double)FUN_1403307c0();
      dVar15 = (double)FUN_140332d90();
      *(short *)((longlong)param_1 + 0x42) = sVar9;
      uVar11 = (undefined2)(int)dVar20;
      *(undefined2 *)(param_1 + 0x11) = uVar11;
      fVar21 = *pfVar8;
      if (iVar1 == 0) {
        stage_entity_spawn_candidate
                  (0xe6,7000,0x32,0,0,0x4000,dVar3,CONCAT44(uVar7,0x3c),1,param_1[1]);
        stage_entity_spawn_candidate(0xe7,7000,0x32,0,0,0x4000,dVar3,0x3c,1,param_1[1]);
        stage_entity_spawn_candidate(0xf3,3000,0x1e,0,0,0x4000,dVar3,0x28,1,param_1[1]);
      }
      dVar20 = (double)FUN_1403307c0();
      fVar19 = (float)(dVar20 * DAT_14053a6e0) + *local_res18;
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * DAT_14053a6e0;
      param_1[0xc] = fVar19;
      fVar22 = (float)dVar20 + *local_res20;
      dVar20 = (double)FUN_1403307c0();
      dVar20 = dVar20 * DAT_14053a3a0;
      param_1[0xd] = fVar22;
      dVar16 = (double)FUN_140332d90();
      dVar16 = dVar16 * DAT_14053a3a0;
      FUN_1400c8410(DAT_140e44a44,0x10,7,fVar19,fVar22,uVar11,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      FUN_1400c8410(DAT_140e46ec4,0x10,7,(float)(dVar14 * dVar13) + fVar18,
                    (float)(dVar15 * dVar13) + fVar21,sVar9,dVar3,uVar4,0xff,0xff,0xff,0xff,1,0);
      dVar17 = (double)FUN_140332d90(((double)DAT_140e418c8 - _DAT_14053b180) * DAT_14053a7f8 *
                                     dVar2 * dVar17);
      FUN_1400c8410(DAT_140e44a40,0x10,7,(float)dVar20 + fVar19,(float)dVar16 + fVar22,uVar11,
                    dVar17 * DAT_140539e60 + dVar3,dVar3,0xff,0xff,0xff,0xff,1,0);
    }
  }
  if ((local_170._4_4_ == 7) && (iStack_1dc == 0xa0)) {
    *param_1 = 0;
  }
  return;
}


