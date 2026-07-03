// Function: FUN_14002b680 @ 14002b680
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14002b680(undefined4 *param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  ushort uVar18;
  ushort uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  double dVar26;
  undefined8 uVar27;
  double dVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  float fVar33;
  ulonglong in_stack_fffffffffffffe20;
  undefined6 uVar35;
  undefined8 uVar34;
  undefined1 in_stack_fffffffffffffe28 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  ulonglong uVar78;
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
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  int iStack_17c;
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined8 local_138;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  int iStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  uint uStack_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  
  dVar26 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e44908 - (float)param_1[10]),0));
  dVar26 = dVar26 * DAT_14053aba0;
  iVar22 = 0;
  uVar31 = (undefined4)local_138;
  uVar32 = (undefined4)((ulonglong)local_138 >> 0x20);
  local_108 = local_178;
  uStack_104 = uStack_174;
  uStack_100 = uStack_170;
  uStack_fc = uStack_16c;
  local_118 = local_188;
  uStack_114 = uStack_184;
  uStack_110 = uStack_180;
  uVar29 = uVar31;
  uVar30 = uVar32;
  local_d8 = local_148;
  uStack_d4 = uStack_144;
  uStack_d0 = uStack_140;
  uStack_cc = uStack_13c;
  local_e8 = local_158;
  uStack_e4 = uStack_154;
  uStack_e0 = uStack_150;
  uStack_dc = uStack_14c;
  local_f8 = local_168;
  uStack_f4 = uStack_164;
  uStack_f0 = uStack_160;
  uStack_ec = uStack_15c;
  uStack_124 = uStack_194;
  uStack_120 = uStack_190;
  uStack_11c = uStack_18c;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined4 *)0x0)) {
    iStack_10c = 0;
    local_128 = 0;
  }
  else {
    iStack_10c = 0;
    local_128 = 0;
    puVar14 = DAT_140e45d80;
    do {
      if (puVar14[1] == DAT_1407c77a0) {
        local_128 = *puVar14;
        uStack_124 = puVar14[1];
        uStack_120 = puVar14[2];
        uStack_11c = puVar14[3];
        local_118 = puVar14[4];
        uStack_114 = puVar14[5];
        uStack_110 = puVar14[6];
        iStack_10c = puVar14[7];
        local_108 = puVar14[8];
        uStack_104 = puVar14[9];
        uStack_100 = puVar14[10];
        uStack_fc = puVar14[0xb];
        local_f8 = puVar14[0xc];
        uStack_f4 = puVar14[0xd];
        uStack_f0 = puVar14[0xe];
        uStack_ec = puVar14[0xf];
        local_e8 = puVar14[0x10];
        uStack_e4 = puVar14[0x11];
        uStack_e0 = puVar14[0x12];
        uStack_dc = puVar14[0x13];
        local_d8 = puVar14[0x14];
        uStack_d4 = puVar14[0x15];
        uStack_d0 = puVar14[0x16];
        uStack_cc = puVar14[0x17];
        uVar29 = (undefined4)*(undefined8 *)(puVar14 + 0x18);
        uVar30 = (undefined4)((ulonglong)*(undefined8 *)(puVar14 + 0x18) >> 0x20);
      }
      puVar14 = *(undefined4 **)(puVar14 + 0x18);
    } while (puVar14 != (undefined4 *)0x0);
  }
  local_c8 = CONCAT44(uVar30,uVar29);
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == (undefined4 *)0x0)) {
    iStack_17c = 0;
    local_198 = 0;
  }
  else {
    iStack_17c = 0;
    local_198 = 0;
    puVar14 = DAT_140e45d80;
    do {
      if (puVar14[1] == DAT_1407c77a0 + 1) {
        local_198 = *puVar14;
        uStack_194 = puVar14[1];
        uStack_190 = puVar14[2];
        uStack_18c = puVar14[3];
        local_188 = puVar14[4];
        uStack_184 = puVar14[5];
        uStack_180 = puVar14[6];
        iStack_17c = puVar14[7];
        local_178 = puVar14[8];
        uStack_174 = puVar14[9];
        uStack_170 = puVar14[10];
        uStack_16c = puVar14[0xb];
        local_168 = puVar14[0xc];
        uStack_164 = puVar14[0xd];
        uStack_160 = puVar14[0xe];
        uStack_15c = puVar14[0xf];
        local_158 = puVar14[0x10];
        uStack_154 = puVar14[0x11];
        uStack_150 = puVar14[0x12];
        uStack_14c = puVar14[0x13];
        local_148 = puVar14[0x14];
        uStack_144 = puVar14[0x15];
        uStack_140 = puVar14[0x16];
        uStack_13c = puVar14[0x17];
        uVar31 = (undefined4)*(undefined8 *)(puVar14 + 0x18);
        uVar32 = (undefined4)((ulonglong)*(undefined8 *)(puVar14 + 0x18) >> 0x20);
      }
      puVar14 = *(undefined4 **)(puVar14 + 0x18);
    } while (puVar14 != (undefined4 *)0x0);
  }
  local_138 = CONCAT44(uVar32,uVar31);
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    if (DAT_140e41af8 == 5) {
      FUN_1400031d0(param_1);
      auVar36._12_4_ = in_stack_fffffffffffffe28._12_4_;
      auVar36._0_8_ = in_stack_fffffffffffffe28._0_8_;
      auVar36._8_4_ = param_1[0x14];
      in_stack_fffffffffffffe28._8_8_ = auVar36._8_8_;
      in_stack_fffffffffffffe28._0_8_ = DAT_14053a4f0;
      uVar29 = param_1[10];
      uVar21 = param_1[0xb];
LAB_14002ba29:
      in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
      stage_entity_spawn_candidate
                (0x137,99999999,0,uVar29,uVar21,in_stack_fffffffffffffe20,in_stack_fffffffffffffe28,
                 1,0);
    }
    else {
      if (param_1[5] == 0xb) {
        auVar37._12_4_ = in_stack_fffffffffffffe28._12_4_;
        auVar37._0_8_ = in_stack_fffffffffffffe28._0_8_;
        auVar37._8_4_ = 0x50;
        uVar78 = auVar37._8_8_;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar78;
        in_stack_fffffffffffffe28 = auVar5 << 0x40;
        in_stack_fffffffffffffe20 = CONCAT62((int6)(in_stack_fffffffffffffe20 >> 0x10),0x4000);
        if (iStack_10c < iStack_17c) {
          stage_entity_spawn_candidate
                    (0x81,99999999,0,uStack_100,uStack_fc,in_stack_fffffffffffffe20,0,uVar78,1,0);
          param_1[5] = 0xd;
        }
        else {
          param_1[5] = 0xc;
          stage_entity_spawn_candidate
                    (0x82,99999999,0,uStack_170,uStack_16c,in_stack_fffffffffffffe20,0,uVar78,1,0);
        }
      }
      uVar27 = DAT_14053a4f0;
      if (((param_1[5] == 0xc) || (param_1[5] - 0x15 < 0x13)) || (DAT_140e41af8 == 1)) {
        FUN_1400031d0(&local_128);
        auVar38._12_4_ = in_stack_fffffffffffffe28._12_4_;
        auVar38._0_8_ = in_stack_fffffffffffffe28._0_8_;
        auVar38._8_4_ = param_1[0x14];
        in_stack_fffffffffffffe28._8_8_ = auVar38._8_8_;
        in_stack_fffffffffffffe28._0_8_ = uVar27;
        in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
        stage_entity_spawn_candidate
                  (0x137,99999999,0,uStack_100,uStack_fc,in_stack_fffffffffffffe20,uVar27,
                   in_stack_fffffffffffffe28._8_8_,1,0);
      }
      if (((param_1[5] == 0xd) || (param_1[5] - 0x28 < 0x13)) || (DAT_140e41af8 == 1)) {
        FUN_1400031d0(&local_198);
        auVar39._12_4_ = in_stack_fffffffffffffe28._12_4_;
        auVar39._0_8_ = in_stack_fffffffffffffe28._0_8_;
        auVar39._8_4_ = param_1[0x14];
        in_stack_fffffffffffffe28._8_8_ = auVar39._8_8_;
        in_stack_fffffffffffffe28._0_8_ = uVar27;
        uVar29 = uStack_170;
        uVar21 = uStack_16c;
        goto LAB_14002ba29;
      }
    }
    param_1[3] = 0;
    if (DAT_140e41af8 == 1) {
      param_1[5] = 0x46;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      DAT_140e419bc = 2;
      param_1[5] = (param_1[5] != 0x1f) + 0x3b;
    }
    else if (DAT_140e41af8 == 3) {
      DAT_140e419bc = 2;
      uVar29 = 0x1e;
      if (param_1[5] != 0x15) {
        uVar29 = 0x32;
      }
      param_1[5] = uVar29;
    }
    else if (DAT_140e41af8 == 4) {
      if (param_1[5] == 0xc) {
        param_1[5] = 0x14;
        DAT_140e419bc = 2;
      }
      else {
        if (param_1[5] == 0xd) {
          param_1[5] = 0x28;
        }
        DAT_140e419bc = 2;
      }
    }
    else if (DAT_140e41af8 == 5) {
      param_1[5] = 10;
      DAT_140e419bc = 2;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar21 = uStack_fc;
  uVar30 = uStack_100;
  iVar17 = iStack_17c;
  uVar12 = _UNK_14053bb28;
  dVar11 = _DAT_14053bb20;
  uVar29 = DAT_14053af48;
  dVar10 = DAT_14053a020;
  uVar27 = DAT_140539ee0;
  dVar8 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar20 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar15 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
    uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 3;
    uVar20 = uVar20 * 0x800 ^ uVar20;
    uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 4;
    uVar16 = DAT_1407c7798 * 0xde + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar15 >> 0xb ^ uVar20) >> 8 ^ uVar15 ^ uVar20) % 0xc9 + 0x104);
    uVar20 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar20 = uVar20 * 0x800 ^ uVar20;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar20) >> 8 ^ uVar20 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x33 + 0xe6);
  }
  iVar23 = param_1[5];
  auVar40._12_4_ = in_stack_fffffffffffffe28._12_4_;
  auVar40._0_8_ = in_stack_fffffffffffffe28._0_8_;
  uVar35 = (undefined6)(in_stack_fffffffffffffe20 >> 0x10);
  switch(iVar23) {
  case 0:
    if (param_1[3] == 0) {
      auVar40._8_4_ = 0x46;
      auVar41._8_8_ = auVar40._8_8_;
      auVar41._0_8_ = DAT_140539ee0;
      uVar34 = CONCAT62(uVar35,0x4000);
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate
                (0x83,99999999,0,DAT_14053b370,0,uVar34,DAT_140539ee0,auVar41._8_8_,1,0);
      auVar42._12_4_ = auVar41._12_4_;
      auVar42._0_8_ = auVar41._0_8_;
      auVar42._8_4_ = 0x46;
      auVar43._8_8_ = auVar42._8_8_;
      auVar43._0_8_ = uVar27;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate(0x84,99999999,0,DAT_14053acfc,0,uVar34,uVar27,auVar43._8_8_,1,0);
      uVar31 = DAT_14053b390;
      auVar44._12_4_ = auVar43._12_4_;
      auVar44._0_8_ = auVar43._0_8_;
      auVar44._8_4_ = 0x32;
      auVar45._8_8_ = auVar44._8_8_;
      auVar45._0_8_ = uVar27;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x85,99999999,0,DAT_14053b38c,DAT_14053b390,uVar34,uVar27,auVar45._8_8_,1,0);
      uVar30 = DAT_14053ad38;
      auVar46._12_4_ = auVar45._12_4_;
      auVar46._0_8_ = auVar45._0_8_;
      auVar46._8_4_ = 0x32;
      auVar47._8_8_ = auVar46._8_8_;
      auVar47._0_8_ = uVar27;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x86,99999999,0,DAT_14053ad38,uVar31,uVar34,uVar27,auVar47._8_8_,1,0);
      uVar32 = DAT_14053b36c;
      auVar48._12_4_ = auVar47._12_4_;
      auVar48._0_8_ = auVar47._0_8_;
      auVar48._8_4_ = 0x32;
      auVar49._8_8_ = auVar48._8_8_;
      auVar49._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x87,20000,0x3c,DAT_14053add4,DAT_14053b36c,uVar34,dVar11,auVar49._8_8_,1,0);
      auVar50._12_4_ = auVar49._12_4_;
      auVar50._0_8_ = auVar49._0_8_;
      auVar50._8_4_ = 0x32;
      auVar51._8_8_ = auVar50._8_8_;
      auVar51._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x87,20000,0x3c,DAT_14053b3e0,uVar32,uVar34,dVar11,auVar51._8_8_,1,0);
      uVar31 = DAT_14053ad64;
      auVar52._12_4_ = auVar51._12_4_;
      auVar52._0_8_ = auVar51._0_8_;
      auVar52._8_4_ = 0x28;
      auVar53._8_8_ = auVar52._8_8_;
      auVar53._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x88,10000,0x18,DAT_14053ace8,DAT_14053ad64,uVar34,dVar11,auVar53._8_8_,1,0);
      auVar54._12_4_ = auVar53._12_4_;
      auVar54._0_8_ = auVar53._0_8_;
      auVar54._8_4_ = 0x28;
      auVar55._8_8_ = auVar54._8_8_;
      auVar55._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate(0x88,10000,0x18,uVar32,uVar31,uVar34,dVar11,auVar55._8_8_,1,0);
      auVar56._12_4_ = auVar55._12_4_;
      auVar56._0_8_ = auVar55._0_8_;
      auVar56._8_4_ = 0x28;
      auVar57._8_8_ = auVar56._8_8_;
      auVar57._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x88,10000,0x18,DAT_14053ada4,uVar30,uVar34,dVar11,auVar57._8_8_,1,0);
      auVar58._12_4_ = auVar57._12_4_;
      auVar58._0_8_ = auVar57._0_8_;
      auVar58._8_4_ = 0x28;
      auVar59._8_8_ = auVar58._8_8_;
      auVar59._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x88,10000,0x18,DAT_14053b3c0,uVar30,uVar34,dVar11,auVar59._8_8_,1,0);
      uVar30 = DAT_14053b3c8;
      auVar60._12_4_ = auVar59._12_4_;
      auVar60._0_8_ = auVar59._0_8_;
      auVar60._8_4_ = 0x14;
      auVar61._8_8_ = auVar60._8_8_;
      auVar61._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x89,99999999,0,DAT_14053acbc,DAT_14053b3c8,uVar34,dVar11,auVar61._8_8_,1,0);
      auVar62._12_4_ = auVar61._12_4_;
      auVar62._0_8_ = auVar61._0_8_;
      auVar62._8_4_ = 0x14;
      auVar63._8_8_ = auVar62._8_8_;
      auVar63._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x8a,99999999,0,DAT_14053b358,uVar30,uVar34,dVar11,auVar63._8_8_,1,0);
      auVar64._12_4_ = auVar63._12_4_;
      auVar64._0_8_ = auVar63._0_8_;
      auVar64._8_4_ = 0x14;
      auVar65._8_8_ = auVar64._8_8_;
      auVar65._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x8a,99999999,0,DAT_14053adb4,uVar30,uVar34,dVar11,auVar65._8_8_,1,0);
      auVar66._12_4_ = auVar65._12_4_;
      auVar66._0_8_ = auVar65._0_8_;
      auVar66._8_4_ = 0x14;
      auVar67._8_8_ = auVar66._8_8_;
      auVar67._0_8_ = dVar11;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x89,99999999,0,DAT_14053b3d0,uVar30,uVar34,dVar11,auVar67._8_8_,1,0);
      auVar68._12_4_ = auVar67._12_4_;
      auVar68._0_8_ = auVar67._0_8_;
      auVar68._8_4_ = 0x1e;
      auVar69._8_8_ = auVar68._8_8_;
      auVar69._0_8_ = uVar27;
      uVar34 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x80,99999999,0,DAT_14053ae74,uVar29,uVar34,uVar27,auVar69._8_8_,1,0);
      auVar70._12_4_ = auVar69._12_4_;
      auVar70._0_8_ = auVar69._0_8_;
      auVar70._8_4_ = 0x1e;
      in_stack_fffffffffffffe28._8_8_ = auVar70._8_8_;
      in_stack_fffffffffffffe28._0_8_ = uVar27;
      in_stack_fffffffffffffe20 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x80,99999999,0,DAT_14053adf4,uVar29,in_stack_fffffffffffffe20,uVar27,
                 in_stack_fffffffffffffe28._8_8_,1,0);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      param_1[0x17] = 6;
    }
    if (param_1[3] == 0x14) {
      auVar71._12_4_ = in_stack_fffffffffffffe28._12_4_;
      auVar71._0_8_ = in_stack_fffffffffffffe28._0_8_;
      auVar71._8_4_ = 0x1e;
      auVar72._8_8_ = auVar71._8_8_;
      auVar72._0_8_ = uVar27;
      uVar34 = CONCAT62((int6)(in_stack_fffffffffffffe20 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x80,99999999,0,DAT_14053ad2c,uVar29,uVar34,uVar27,auVar72._8_8_,1,0);
      auVar73._12_4_ = auVar72._12_4_;
      auVar73._0_8_ = auVar72._0_8_;
      auVar73._8_4_ = 0x1e;
      in_stack_fffffffffffffe20 = CONCAT62((int6)((ulonglong)uVar34 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x80,99999999,0,DAT_14053aec4,uVar29,in_stack_fffffffffffffe20,uVar27,auVar73._8_8_
                 ,1,0);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if (param_1[3] == 0x50) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
    }
    iVar22 = param_1[3];
    if (iVar22 < 0xc9) {
      fVar33 = (float)param_1[0xd];
      if (iVar22 < 0x50) {
        param_1[0xb] = DAT_14053afb0;
      }
      else {
        if (iVar22 < 200) {
          dVar26 = (double)FUN_140332d90(((double)iVar22 - DAT_14053a3f8) * DAT_14053a4d8 * dVar10 *
                                         dVar8);
          fVar33 = (float)(dVar26 * (double)(fVar33 - DAT_14053afb0)) + DAT_14053afb0;
        }
        param_1[0xb] = fVar33;
      }
    }
    else {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      if (iVar22 == 0xf0) {
        param_1[5] = param_1[5] + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 0x24220;
        DAT_140e4430c = 0xe10;
        DAT_140e4192c = 0;
        param_1[7] = 0x24220;
        DAT_140e419bc = 1;
      }
    }
    break;
  case 1:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar17 = ((int)dVar26 & 0xffffU) - (uint)uVar1;
    iVar22 = iVar17 + 0x10000;
    if (-0x8001 < iVar17) {
      iVar22 = iVar17;
    }
    iVar17 = iVar22 + -0x10000;
    if (iVar22 < 0x8001) {
      iVar17 = iVar22;
    }
    uVar18 = (ushort)(int)dVar26;
    if (iVar17 < 1) {
      uVar19 = uVar1;
      if ((iVar17 < 0) && (uVar19 = uVar1 - 0x200, -0x200 < iVar17)) {
        uVar19 = uVar18;
      }
    }
    else {
      uVar19 = uVar18;
      if (0x1ff < iVar17) {
        uVar19 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar19;
    dVar26 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar26 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar26 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
    break;
  case 10:
    iVar17 = param_1[3];
    if (0x59 < iVar17) {
      iVar22 = 0xff;
    }
    iVar23 = 0;
    if (iVar17 < 0x5a) {
LAB_14002c468:
      if (iVar17 < 0xbe) {
        iVar23 = iVar22;
      }
      puVar13 = DAT_140e45d28;
      if (iVar17 == 1) {
        uVar29 = param_1[0xb];
        uVar30 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar13 = (undefined8 *)_malloc_base(0x60);
          if (puVar13 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar13 + 0x14) = uVar30;
          *(undefined4 *)(puVar13 + 3) = uVar29;
          *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar30;
          *(undefined4 *)(puVar13 + 4) = uVar29;
          *puVar13 = 1;
          puVar13[1] = 0x36;
          *(undefined4 *)(puVar13 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
          puVar13[5] = 0;
          puVar13[6] = 0x3ff0000000000000;
          puVar13[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar13 + 8) = 0;
          *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
          *(undefined4 *)(puVar13 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
          puVar13[10] = 0xff;
          puVar13[0xb] = 0;
          if (bVar25) {
            DAT_140e45d78 = puVar13;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar13;
          }
        }
      }
    }
    else if (iVar17 < 100) {
      dVar26 = (double)FUN_140332d90(((double)iVar17 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar23 = (int)(dVar26 * DAT_14053a5f8);
      puVar13 = DAT_140e45d28;
    }
    else {
      if (0xbd < iVar17) goto LAB_14002c468;
      dVar26 = (double)FUN_140332d90(((double)iVar17 - DAT_14053a1e8) * DAT_14053a558 *
                                     DAT_14053a020 * DAT_140539d28);
      puVar13 = DAT_140e45d28;
      if (iVar17 < 0xbe) {
        iVar23 = (int)(dVar26 * DAT_14053a5f8);
      }
    }
    DAT_140e45d28 = puVar13;
    iVar22 = param_1[3];
    if (iVar22 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar22 = param_1[3];
      param_1[0xb] = (float)iVar22 * DAT_140539cd8 + (float)param_1[0xb];
    }
    puVar13 = DAT_140e45d28;
    if (iVar22 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar29 = param_1[0xb];
      uVar30 = param_1[10];
      puVar13 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar13 = (undefined8 *)_malloc_base(0x60);
        if (puVar13 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar13 + 0x14) = uVar30;
        *(undefined4 *)(puVar13 + 3) = uVar29;
        *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar30;
        *(undefined4 *)(puVar13 + 4) = uVar29;
        *puVar13 = 1;
        puVar13[1] = 0x11;
        *(undefined4 *)(puVar13 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
        puVar13[5] = 0;
        puVar13[6] = 0x3ff0000000000000;
        puVar13[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar13 + 8) = 0;
        *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
        *(undefined4 *)(puVar13 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
        puVar13[10] = 0xff;
        puVar13[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar13;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar13;
        }
      }
    }
    DAT_140e45d28 = puVar13;
    if (0xe5 < (int)param_1[3]) {
      FUN_140001900(param_1[3],0xe6,6);
    }
    uVar29 = DAT_140e41ab8;
    puVar14 = (undefined4 *)_malloc_base(0x48);
    if (puVar14 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar14 = uVar29;
    puVar14[1] = 0x4e;
    *(undefined8 *)(puVar14 + 2) = 5;
    puVar14[4] = 0;
    *(undefined2 *)(puVar14 + 5) = 0;
    *(undefined8 *)(puVar14 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
    puVar14[10] = 0xff;
    puVar14[0xb] = 0xff;
    puVar14[0xc] = 0xff;
    puVar14[0xd] = iVar23;
    *(undefined8 *)(puVar14 + 0xe) = 1;
    *(undefined8 *)(puVar14 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar14;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
    }
    DAT_140e46c88 = puVar14;
    if (param_1[3] == 0x186) {
      param_1[0x14] = 10;
      *(undefined8 *)(param_1 + 10) = 0;
      param_1[3] = 0;
      if (param_1[5] == 10) {
        DAT_140e4430c = 0x834;
        DAT_140e41b0c = 70000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    iVar24 = iStack_10c;
    if ((iStack_10c < 0) && (iVar24 = iVar22, iVar23 == 0xb)) {
      auVar74._8_4_ = 0x50;
      auVar74._0_8_ = auVar40._0_8_;
      auVar74._12_4_ = auVar40._12_4_;
      auVar75._8_8_ = 0;
      auVar75._0_8_ = auVar74._8_8_;
      auVar75 = auVar75 << 0x40;
      in_stack_fffffffffffffe20 = CONCAT62(uVar35,0x4000);
      uVar20 = uStack_fc;
      stage_entity_spawn_candidate
                (0x81,99999999,0,uStack_100,uStack_fc,in_stack_fffffffffffffe20,0,auVar74._8_8_,1,0)
      ;
      auVar6._12_4_ = 0;
      auVar6._0_12_ = auVar75._4_12_;
      in_stack_fffffffffffffe28 = auVar6 << 0x20;
      in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffff00000000;
      FUN_140109660(0x19,uVar30,uVar21,0,uVar20 & 0xffff0000,in_stack_fffffffffffffe20,
                    in_stack_fffffffffffffe28);
      iVar23 = 0xd;
      param_1[5] = 0xd;
    }
    uVar21 = uStack_16c;
    uVar29 = uStack_170;
    if ((iVar17 < 0) && (iVar17 = iVar22, iVar23 == 0xb)) {
      auVar76._12_4_ = in_stack_fffffffffffffe28._12_4_;
      auVar76._0_8_ = in_stack_fffffffffffffe28._0_8_;
      auVar76._8_4_ = 0x50;
      auVar77._8_8_ = 0;
      auVar77._0_8_ = auVar76._8_8_;
      auVar77 = auVar77 << 0x40;
      in_stack_fffffffffffffe20 = CONCAT62((int6)(in_stack_fffffffffffffe20 >> 0x10),0x4000);
      uVar20 = uStack_16c;
      stage_entity_spawn_candidate
                (0x82,99999999,0,uStack_170,uStack_16c,in_stack_fffffffffffffe20,0,auVar76._8_8_,1,0
                );
      auVar7._12_4_ = 0;
      auVar7._0_12_ = auVar77._4_12_;
      in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffff00000000;
      FUN_140109660(0x19,uVar29,uVar21,0,uVar20 & 0xffff0000,in_stack_fffffffffffffe20,
                    auVar7 << 0x20);
      param_1[5] = 0xc;
    }
    param_1[7] = iVar17 + iVar24;
    break;
  case 0x14:
  case 0x1e:
  case 0x28:
  case 0x32:
  case 0x3b:
  case 0x3c:
    if (param_1[3] == 0xb4) {
      param_1[3] = 0;
      if (iVar23 == 0x14) {
        DAT_140e41b0c = 70000;
LAB_14002c94a:
        DAT_140e4430c = 0x834;
        DAT_140e4192c = 0;
      }
      else {
        if (iVar23 == 0x1e) {
          DAT_140e41b0c = 70000;
          goto LAB_14002c94a;
        }
        if (iVar23 == 0x28) {
          DAT_140e41b0c = 70000;
          goto LAB_14002c94a;
        }
        if (iVar23 == 0x32) {
          DAT_140e41b0c = 70000;
          goto LAB_14002c94a;
        }
        if ((iVar23 == 0x3b) || (iVar23 == 0x3c)) {
          DAT_140e41b0c = 80000;
          if (iVar23 == 0x3b) {
            iVar23 = 0x3c;
          }
          goto LAB_14002c94a;
        }
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar23 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 0x15:
  case 0x1f:
  case 0x29:
  case 0x33:
  case 0x3d:
    iVar22 = param_1[7];
    if (iStack_10c < (int)param_1[7]) {
      param_1[7] = iStack_10c;
      iVar22 = iStack_10c;
    }
    if (iStack_17c < iVar22) {
      param_1[7] = iStack_17c;
    }
    break;
  case 0x46:
    FUN_140003ad0(param_1);
    uVar29 = DAT_14053ac28;
    iVar22 = param_1[3];
    if (iVar22 < 0xf0) {
      iVar17 = DAT_1407c7798 + 3;
      iVar23 = DAT_1407c7798 * 10;
      if (iVar22 - 0x3cU < 0xb4) {
        in_stack_fffffffffffffe20 = 0;
        uVar27 = FUN_1401349e0(iVar22,0x3c,0x4c,0xe0,0xf0,0,dVar11);
        uVar30 = DAT_14053accc;
        in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,DAT_14053accc,in_stack_fffffffffffffe20,
                      dVar11,uVar27,0xff,0xff,0xff,0xff,1,0);
        auVar3._8_4_ = (int)uVar27;
        auVar3._0_8_ = uVar27;
        auVar3._12_4_ = (int)((ulonglong)uVar27 >> 0x20);
        in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar17 * 4),0x6e,1,DAT_14053ae44,
                      uVar30,in_stack_fffffffffffffe20,auVar3,0xff,0xff,0xff,0xff,1,0);
        if (iVar22 == 0x4c) {
          in_stack_fffffffffffffe20 = CONCAT44((int)(in_stack_fffffffffffffe20 >> 0x20),uVar29);
          FUN_14012e070(iVar23 + 99,4);
        }
        else {
          lVar2 = DAT_140e47908;
          if (iVar22 == 0xe0) {
            while (lVar2 != 0) {
              lVar2 = *(longlong *)(lVar2 + 0x238);
              FUN_140323ce8();
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      iVar22 = param_1[3];
      if (iVar22 - 0x3cU < 0xb4) {
        in_stack_fffffffffffffe20 = 0;
        uVar27 = FUN_1401349e0(iVar22,0x3c,0x4c,0xe0,0xf0,0,dVar11);
        uVar30 = DAT_14053ad80;
        in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,DAT_14053ad80,in_stack_fffffffffffffe20,
                      dVar11,uVar27,0xff,0xff,0xff,0xff,1,0);
        auVar4._8_4_ = (int)uVar27;
        auVar4._0_8_ = uVar27;
        auVar4._12_4_ = (int)((ulonglong)uVar27 >> 0x20);
        in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e4752c,0x6e,1,DAT_14053ae44,uVar30,in_stack_fffffffffffffe20,auVar4,
                      0xff,0xff,0xff,0xff,1,0);
        if (iVar22 == 0x4c) {
          in_stack_fffffffffffffe20 = CONCAT44((int)(in_stack_fffffffffffffe20 >> 0x20),uVar29);
          FUN_14012e070(0xcb,4);
        }
        else {
          lVar2 = DAT_140e47908;
          if (iVar22 == 0xe0) {
            while (lVar2 != 0) {
              lVar2 = *(longlong *)(lVar2 + 0x238);
              FUN_140323ce8();
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
    }
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
    break;
  default:
    goto switchD_14002bcbc_default;
  }
switchD_14002bcbc_default:
  dVar26 = DAT_14053abc0;
  if (((int)param_1[5] < 10) || ((param_1[5] == 10 && ((int)param_1[3] < 100)))) {
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053abc0 * dVar10 *
                                   dVar8);
    dVar9 = DAT_140539e60;
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e41a94,0x19,8,(float)param_1[10] + DAT_14053acec,
                  (float)param_1[0xb] + DAT_14053addc,in_stack_fffffffffffffe20,dVar11,
                  dVar28 * DAT_140539e60 + dVar11,0xff,0xff,0xff,0xe1,1,1);
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar26 * dVar10 * dVar8);
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e41a94,0x19,8,(float)param_1[10] - DAT_14053acec,
                  (float)param_1[0xb] + DAT_14053addc,in_stack_fffffffffffffe20,dVar11,
                  dVar28 * dVar9 + dVar11,0xff,0xff,0xff,0xe1,1,0);
    dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar26 * dVar10 * dVar8);
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e41a94,0x19,8,(float)param_1[10] + _DAT_14053ada0,
                  (float)param_1[0xb] + DAT_14053adb8,in_stack_fffffffffffffe20,dVar11,
                  dVar28 * dVar9 + dVar11,0xff,0xff,0xff,0xe1,1,1);
    dVar26 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * dVar26 * dVar10 * dVar8);
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e41a94,0x19,8,(float)param_1[10] - _DAT_14053ada0,
                  (float)param_1[0xb] + DAT_14053adb8,in_stack_fffffffffffffe20,dVar11,
                  dVar26 * dVar9 + dVar11,0xff,0xff,0xff,0xe1,1,0);
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e449c4,0x19,7,param_1[10],(float)param_1[0xb] + DAT_14053ac58,
                  in_stack_fffffffffffffe20,dVar11,uVar12,0xff,0xff,0xff,0xff,1,0);
    uVar21 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar21 = uVar21 * 0x800 ^ uVar21;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ DAT_140e9fd18 ^ uVar21;
    if (DAT_140e9fd1c % 5 != 0) {
      in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
      FUN_1400c8410(DAT_140e449dc,0x19,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe20,dVar11,
                    uVar12,0xff,0xff,0xff,0xff,1,0);
    }
    in_stack_fffffffffffffe20 = in_stack_fffffffffffffe20 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e449d4,0x19,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe20,dVar11,
                  uVar12,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e449d8,0x1e,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffe20 & 0xffffffffffff0000,dVar11,uVar12,0xff,0xff,0xff,0xff,1
                  ,0);
    if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x12) * 0x12) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472f8);
      FUN_14018a340(DAT_140e472f8,1,1);
    }
  }
  FUN_140002260();
  return;
}


