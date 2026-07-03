// Function: FUN_140007960 @ 140007960
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140007960(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  longlong lVar7;
  double dVar8;
  double dVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined2 uVar13;
  short sVar14;
  undefined8 *puVar15;
  undefined4 uVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  double dVar21;
  undefined4 uVar22;
  undefined8 in_stack_fffffffffffffe20;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 uStack_108;
  undefined1 local_c8 [160];
  
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
  lVar7 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar7 != 0; lVar7 = *(longlong *)(lVar7 + 0x60)) {
      if (*(int *)(lVar7 + 4) == param_1[2]) {
        uStack_108 = *(undefined8 *)(lVar7 + 0x28);
      }
    }
  }
  lVar7 = DAT_140e45d80;
  iVar17 = local_188._4_4_;
  iVar3 = uStack_190._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar17 = (int)((ulonglong)local_188 >> 0x20);
      iVar3 = (int)((ulonglong)uStack_190 >> 0x20);
      if (lVar7 == 0) break;
      if (*(int *)(lVar7 + 4) == DAT_140e44308) {
        uStack_190 = *(undefined8 *)(lVar7 + 8);
        local_188 = *(undefined8 *)(lVar7 + 0x10);
        uStack_180 = *(undefined8 *)(lVar7 + 0x18);
      }
      lVar7 = *(longlong *)(lVar7 + 0x60);
    }
  }
  uStack_190._4_4_ = iVar3;
  local_188._4_4_ = iVar17;
  fVar19 = (float)param_1[0xd];
  fVar1 = (float)param_1[0xb];
  fVar18 = (float)param_1[0xc];
  fVar2 = (float)param_1[10];
  dVar6 = (double)FUN_1403300b4(SUB84((double)((uStack_108._4_4_ + fVar19) - fVar1),0),
                                SUB84((double)(((float)uStack_108 + fVar18) - fVar2),0));
  dVar6 = dVar6 * DAT_14053aba0;
  fVar18 = (float)FUN_140334430(fVar2 - ((float)uStack_108 + fVar18),DAT_140539fc0);
  fVar19 = (float)FUN_140334430(fVar1 - (uStack_108._4_4_ + fVar19));
  fVar18 = fVar18 + fVar19;
  if (fVar18 < 0.0) {
    fVar18 = (float)FUN_1403352f8(fVar18);
  }
  else {
    fVar18 = SQRT(fVar18);
  }
  dVar9 = DAT_14053a020;
  dVar8 = DAT_140539d28;
  local_1a8 = 0xff;
  uVar16 = 7;
  iVar17 = 0x82;
  if ((int)uStack_180 == 0x146) {
    iVar17 = 100;
  }
  dVar21 = (double)fVar18 / DAT_14053a0b0;
  uVar22 = SUB84((double)((int)dVar6 & 0xffff) * DAT_14053a020 * DAT_140539d28,0);
  dVar6 = (double)FUN_1403307c0(uVar22);
  param_1[10] = (float)(dVar6 * dVar21) + fVar2;
  dVar6 = (double)FUN_140332d90(uVar22);
  iVar3 = param_1[3];
  param_1[0xb] = (float)(dVar6 * dVar21) + fVar1;
  if (iVar3 == 0) {
    param_1[10] = (float)uStack_108;
    param_1[0xb] = uStack_108._4_4_;
  }
  uStack_1a4 = 0xff;
  uVar22 = 0xff;
  if ((local_188._4_4_ == 0) && (uStack_1a4 = 0xff, uVar22 = 0xff, uStack_190._4_4_ < 0xbf)) {
    uVar16 = 8;
    puVar15 = (undefined8 *)FUN_140135060(local_c8,iVar3,0x14);
    uVar22 = *(undefined4 *)(puVar15 + 1);
    uStack_1a4 = (undefined4)((ulonglong)*puVar15 >> 0x20);
    local_1a8 = (undefined4)*puVar15;
  }
  uVar12 = _UNK_14053bb28;
  uVar11 = _DAT_14053bb20;
  dVar6 = DAT_14053a808;
  if (param_1[6] == 0x12) {
    dVar21 = (double)FUN_140332d90(SUB84(((double)iVar3 - 0.0) * DAT_14053a808 * dVar9 * dVar8,0));
    uVar10 = DAT_14053ad40;
    if (iVar3 == 0) {
      stage_entity_spawn_candidate
                (0x13,99999999,0,DAT_14053accc,DAT_14053ad40,0x4000,uVar11,CONCAT44(uVar20,100),1,
                 param_1[1]);
      stage_entity_spawn_candidate
                (0x13,99999999,0,DAT_14053b360,uVar10,0x4000,uVar11,100,1,param_1[1]);
      uVar20 = DAT_14053b370;
      stage_entity_spawn_candidate
                (0x14,99999999,0,DAT_14053acfc,DAT_14053b370,0x4000,uVar11,100,1,param_1[1]);
      stage_entity_spawn_candidate(0x14,99999999,0,uVar20,uVar20,0x4000,uVar11,100,1,param_1[1]);
    }
    FUN_1400c8410(DAT_140e44918,0x1d,uVar16,param_1[10],param_1[0xb],0,uVar11,uVar12,local_1a8,
                  uStack_1a4,uVar22,0xff,1,0);
    FUN_1400c8410(DAT_140e44914,0x1d,uVar16,param_1[10],
                  ((float)(dVar21 + dVar21) + 0.0 + (float)param_1[0xb]) - DAT_14053acbc,0,uVar11,
                  uVar12,local_1a8,uStack_1a4,uVar22,0xff,1,0);
  }
  if (param_1[6] == 0x13) {
    uVar20 = SUB84(((double)(int)param_1[3] - _DAT_14053a3c0) * dVar6 * dVar9 * dVar8,0);
    dVar21 = (double)FUN_140332d90(uVar20);
    bVar4 = (float)param_1[0xc] != 0.0;
    bVar5 = (float)param_1[0xc] <= 0.0;
    uVar13 = (undefined2)(int)(dVar21 * DAT_14053a840);
    if (bVar5 && bVar4) {
      dVar21 = (double)FUN_140332d90(uVar20);
      uVar13 = (undefined2)(int)(dVar21 * _DAT_14053b278);
    }
    FUN_1400c8410(DAT_140e4491c,0x1c,uVar16,param_1[10],param_1[0xb],uVar13,uVar11,uVar12,local_1a8,
                  uStack_1a4,uVar22,0xff,1,bVar5 && bVar4);
  }
  if (param_1[6] == 0x14) {
    uVar20 = SUB84(((double)(int)param_1[3] - _DAT_14053a300) * dVar6 * dVar9 * dVar8,0);
    dVar6 = (double)FUN_140332d90(uVar20);
    sVar14 = (short)(int)(dVar6 * _DAT_14053a8b8) + 8000;
    bVar4 = (float)param_1[0xc] != 0.0;
    bVar5 = (float)param_1[0xc] <= 0.0;
    if (bVar5 && bVar4) {
      dVar6 = (double)FUN_140332d90(uVar20);
      sVar14 = (short)(int)(dVar6 * _DAT_14053b298) + -8000;
    }
    FUN_1400c8410(DAT_140e44920,0x1c,uVar16,param_1[10],param_1[0xb],sVar14,uVar11,uVar12,local_1a8,
                  uStack_1a4,uVar22,0xff,1,bVar5 && bVar4);
  }
  if ((local_188._4_4_ == 2) && (uStack_190._4_4_ == iVar17)) {
    *param_1 = 0;
  }
  return;
}


