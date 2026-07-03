// Function: FUN_140026b80 @ 140026b80
// Decompile completed: true

void FUN_140026b80(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  undefined1 auVar3 [16];
  double dVar4;
  undefined8 *puVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined8 local_128;
  undefined8 uStack_120;
  int iStack_114;
  undefined8 uStack_100;
  undefined8 local_e8;
  
  dVar11 = DAT_14053a020;
  dVar10 = DAT_140539d28;
  local_128 = 0;
  local_128._0_4_ = 0;
  if ((0 < DAT_140e44e6c) &&
     (puVar5 = DAT_140e45d80, local_128._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar5 + 4) == DAT_140e44308) {
        local_128 = *puVar5;
        uStack_120 = puVar5[1];
        iStack_114 = *(int *)((longlong)puVar5 + 0x14);
        uStack_100 = puVar5[5];
        local_e8 = puVar5[8];
      }
      puVar5 = (undefined8 *)puVar5[0xc];
    } while (puVar5 != (undefined8 *)0x0);
  }
  fVar1 = (float)param_1[0xe];
  dVar7 = (double)FUN_1403307c0();
  fVar12 = (float)(dVar7 * (double)fVar1) + (float)uStack_100;
  dVar8 = (double)FUN_140332d90();
  dVar4 = DAT_14053a890;
  dVar7 = DAT_140539f40;
  uStack_100._4_4_ = (float)(dVar8 * (double)fVar1) + uStack_100._4_4_;
  if (param_1[6] == 100) {
    iVar2 = param_1[3];
    dVar8 = DAT_140539fc8;
    if ((iVar2 < 0) || (dVar8 = DAT_140539f40, 0x13 < iVar2)) {
      iVar6 = (iVar2 >> 0x1f & 0xffffff01U) + 0xff;
    }
    else {
      dVar8 = (double)FUN_140332d90(((double)iVar2 - 0.0) * DAT_14053a890 * dVar11 * dVar10);
      dVar8 = dVar8 * DAT_14053b0a0 + DAT_140539fc8;
      dVar9 = (double)FUN_140332d90(((double)iVar2 - 0.0) * dVar4 * dVar11 * dVar10);
      iVar6 = (int)(dVar9 * DAT_14053a5f8);
    }
    param_1[10] = fVar12;
    param_1[0xb] = uStack_100._4_4_;
    if (iStack_114 - 1U < 2) {
      if (0x27 < (iVar2 + 0x14) % 0x3c) {
        *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x111;
      }
    }
    else if (2 < iStack_114) {
      if (0x13 < iVar2 % 0x1e) {
        *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x222;
      }
      if ((iStack_114 == 3) && (uStack_120._4_4_ == 0x1e)) {
        auVar13._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar13._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar13._8_4_ = 0x32;
        stage_entity_spawn_candidate(0x6c,99999999,0,0,0,0,dVar7,auVar13._8_8_,1,param_1[1]);
      }
    }
    in_stack_fffffffffffffe98._8_4_ = SUB84(dVar8,0);
    in_stack_fffffffffffffe98._0_8_ = dVar8;
    in_stack_fffffffffffffe98._12_4_ = (int)((ulonglong)dVar8 >> 0x20);
    FUN_1400c8410(DAT_140e449b0,0x21,7,param_1[10],param_1[0xb],
                  local_e8._4_2_ + *(short *)(param_1 + 0x11),in_stack_fffffffffffffe98,0xff,0xff,
                  0xff,iVar6,1,0);
  }
  if (param_1[6] == 0x65) {
    iVar2 = param_1[3];
    if (iVar2 < 0) {
      dVar8 = 0.0;
    }
    else {
      dVar8 = dVar7;
      if (iVar2 < 0x14) {
        dVar8 = (double)FUN_140332d90(((double)iVar2 - 0.0) * dVar4 * dVar11 * dVar10);
        dVar8 = dVar8 + 0.0;
      }
    }
    FUN_1403300b4((double)(DAT_140e445dc - uStack_100._4_4_),
                  SUB84((double)(DAT_140e445d8 - fVar12),0));
    dVar10 = (double)FUN_1403307c0();
    dVar10 = dVar10 * DAT_14053a2a8;
    dVar11 = (double)FUN_140332d90();
    dVar11 = dVar11 * DAT_14053a2a8;
    param_1[10] = (float)dVar10 + fVar12;
    param_1[0xb] = (float)dVar11 + uStack_100._4_4_;
    if ((iStack_114 == 3) && (uStack_120._4_4_ == 0x1e)) {
      auVar14._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar14._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar14._8_4_ = 0x32;
      stage_entity_spawn_candidate(0x6d,99999999,0,0,0,0,dVar7,auVar14._8_8_,1,param_1[1]);
    }
    auVar3._8_4_ = SUB84(dVar8,0);
    auVar3._0_8_ = dVar8;
    auVar3._12_4_ = (int)((ulonglong)dVar8 >> 0x20);
    FUN_1400c8410(DAT_140e44c64,0x1f,7,param_1[10],param_1[0xb],local_e8._4_2_,auVar3,0xff,0xff,0xff
                  ,0xff,1,0);
  }
  if ((((iStack_114 == 4) && (uStack_120._4_4_ == 0x82)) || (4 < iStack_114)) ||
     ((int)local_128 == 0)) {
    *param_1 = 0;
  }
  return;
}


