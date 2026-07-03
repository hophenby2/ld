// Function: FUN_1400ee200 @ 1400ee200
// Decompile completed: true

void FUN_1400ee200(undefined4 *param_1)

{
  longlong *plVar1;
  float fVar2;
  int iVar3;
  undefined1 auVar4 [16];
  double dVar5;
  undefined8 *puVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined8 local_128;
  undefined8 uStack_120;
  int iStack_114;
  undefined8 uStack_100;
  undefined8 local_e8;
  
  dVar12 = DAT_14053a020;
  dVar11 = DAT_140539d28;
  local_128 = 0;
  local_128._0_4_ = 0;
  if ((0 < DAT_140e44e6c) &&
     (puVar6 = DAT_140e45d80, local_128._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar6 + 4) == DAT_140e44308) {
        local_128 = *puVar6;
        uStack_120 = puVar6[1];
        iStack_114 = *(int *)((longlong)puVar6 + 0x14);
        uStack_100 = puVar6[5];
        local_e8 = puVar6[8];
      }
      plVar1 = puVar6 + 0xc;
      puVar6 = (undefined8 *)*plVar1;
    } while ((undefined8 *)*plVar1 != (undefined8 *)0x0);
  }
  fVar2 = (float)param_1[0xe];
  dVar8 = (double)FUN_1403307c0();
  fVar13 = (float)(dVar8 * (double)fVar2) + (float)uStack_100;
  dVar9 = (double)FUN_140332d90();
  dVar5 = DAT_14053a890;
  dVar8 = DAT_140539f40;
  uStack_100._4_4_ = (float)(dVar9 * (double)fVar2) + uStack_100._4_4_;
  if (param_1[6] == 0xc9) {
    iVar3 = param_1[3];
    dVar9 = DAT_140539fc8;
    if ((iVar3 < 0) || (dVar9 = DAT_140539f40, 0x13 < iVar3)) {
      iVar7 = (iVar3 >> 0x1f & 0xffffff01U) + 0xff;
    }
    else {
      dVar9 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a890 * dVar12 * dVar11);
      dVar9 = dVar9 * DAT_14053b0a0 + DAT_140539fc8;
      dVar10 = (double)FUN_140332d90(((double)iVar3 - 0.0) * dVar5 * dVar12 * dVar11);
      iVar7 = (int)(dVar10 * DAT_14053a5f8);
    }
    param_1[10] = fVar13;
    param_1[0xb] = uStack_100._4_4_;
    if (0x13 < iVar3 % 0x1e) {
      *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x222;
    }
    if ((iStack_114 == 1) && (uStack_120._4_4_ == 10)) {
      auVar14._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar14._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar14._8_4_ = 0x32;
      stage_entity_spawn_candidate(0xcb,99999999,0,0,0,0,dVar8,auVar14._8_8_,1,param_1[1]);
    }
    in_stack_fffffffffffffe98._8_4_ = SUB84(dVar9,0);
    in_stack_fffffffffffffe98._0_8_ = dVar9;
    in_stack_fffffffffffffe98._12_4_ = (int)((ulonglong)dVar9 >> 0x20);
    FUN_1400c8410(DAT_140e449b0,0x1c,7,param_1[10],param_1[0xb],
                  local_e8._4_2_ + *(short *)(param_1 + 0x11),in_stack_fffffffffffffe98,0xff,0xff,
                  0xff,iVar7,1,0);
  }
  if (param_1[6] == 0xca) {
    iVar3 = param_1[3];
    if (iVar3 < 0) {
      dVar9 = 0.0;
    }
    else {
      dVar9 = dVar8;
      if (iVar3 < 0x14) {
        dVar9 = (double)FUN_140332d90(((double)iVar3 - 0.0) * dVar5 * dVar12 * dVar11);
        dVar9 = dVar9 + 0.0;
      }
    }
    FUN_1403300b4((double)(DAT_140e445dc - uStack_100._4_4_),
                  SUB84((double)(DAT_140e445d8 - fVar13),0));
    dVar11 = (double)FUN_1403307c0();
    dVar11 = dVar11 * DAT_14053a2a8;
    dVar12 = (double)FUN_140332d90();
    dVar12 = dVar12 * DAT_14053a2a8;
    param_1[10] = (float)dVar11 + fVar13;
    param_1[0xb] = (float)dVar12 + uStack_100._4_4_;
    if ((iStack_114 == 1) && (uStack_120._4_4_ == 10)) {
      auVar15._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar15._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar15._8_4_ = 0x32;
      stage_entity_spawn_candidate(0xcc,99999999,0,0,0,0,dVar8,auVar15._8_8_,1,param_1[1]);
    }
    auVar4._8_4_ = SUB84(dVar9,0);
    auVar4._0_8_ = dVar9;
    auVar4._12_4_ = (int)((ulonglong)dVar9 >> 0x20);
    FUN_1400c8410(DAT_140e44c64,0x1a,7,param_1[10],param_1[0xb],local_e8._4_2_,auVar4,0xff,0xff,0xff
                  ,0xff,1,0);
  }
  if (((iStack_114 == 2) && (uStack_120._4_4_ == 100)) || ((int)local_128 == 0)) {
    *param_1 = 0;
  }
  return;
}


