// Function: FUN_140014bf0 @ 140014bf0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140014bf0(undefined4 *param_1)

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
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  ulonglong *puVar14;
  uint uVar15;
  int iVar16;
  ushort uVar17;
  ushort uVar18;
  uint uVar19;
  undefined8 uVar20;
  int iVar21;
  undefined2 uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  short sVar26;
  uint uVar27;
  bool bVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  undefined8 uVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  int local_res18;
  int local_res20;
  double in_stack_fffffffffffffe98;
  undefined4 uVar40;
  uint6 uVar39;
  undefined8 uVar38;
  ulonglong in_stack_fffffffffffffea0;
  undefined4 uVar42;
  undefined4 uVar43;
  ulonglong uVar41;
  undefined1 in_stack_fffffffffffffea8 [16];
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
  undefined1 auVar93 [12];
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
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  longlong local_108;
  int local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  
  dVar29 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  uVar40 = DAT_14053ac80;
  dVar31 = DAT_14053aba0;
  dVar30 = DAT_14053a070;
  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  iVar11 = 0;
  uVar27 = (uint)(dVar29 * DAT_14053aba0);
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar44._12_4_ = in_stack_fffffffffffffea8._12_4_;
    auVar44._0_8_ = in_stack_fffffffffffffea8._0_8_;
    auVar44._8_4_ = param_1[0x14];
    in_stack_fffffffffffffea8._8_8_ = auVar44._8_8_;
    in_stack_fffffffffffffea8._0_8_ = DAT_14053a4f0;
    in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffffffff0000;
    in_stack_fffffffffffffe98 = (double)CONCAT44(uVar42,param_1[0xb]);
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,
               DAT_14053a4f0,in_stack_fffffffffffffea8._8_8_,1,0);
    iVar16 = DAT_140e41af8;
    if (DAT_140e41af8 == 1) {
      param_1[5] = 0xb;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      param_1[5] = 8;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 3) {
      param_1[5] = 6;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 4) {
      bVar28 = DAT_140e41928 == 1;
      param_1[5] = 2;
      DAT_140e419bc = 2;
      param_1[0x14] = 0xf0;
      if ((bVar28) && (DAT_140e41abc == 1)) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
        uVar25 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar25 = uVar25 * 0x800 ^ uVar25;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar25) >> 8 ^ uVar25 ^ DAT_140e9fd18;
        in_stack_fffffffffffffe98 = dVar30;
        FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,DAT_140e9fd10,
                      CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                               (short)DAT_140e9fd1c +
                               (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),dVar30
                      ,in_stack_fffffffffffffea0);
        iVar16 = DAT_140e41af8;
      }
    }
    DAT_140e41af8 = iVar16 + -1;
    param_1[0x17] = 0;
  }
  uVar25 = DAT_140e418c8;
  dVar9 = DAT_14053b1b8;
  dVar8 = DAT_14053a020;
  dVar32 = DAT_140539f40;
  dVar29 = DAT_140539d28;
  uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar15 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
    uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 3;
    uVar19 = uVar19 * 0x800 ^ uVar19;
    uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 4;
    uVar19 = (uVar15 >> 0xb ^ uVar19) >> 8 ^ uVar15 ^ uVar19;
    uVar15 = DAT_1407c7798 * 0x1bc + DAT_140e418c8;
    if (param_1[5] == 1) {
      iVar24 = uVar19 % 0xc9 + 0x104;
      uVar19 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      iVar16 = DAT_140e9fd1c % 0x79 + 0x3c;
    }
    else {
      iVar24 = uVar19 % 0x12d + 0xd2;
      uVar19 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      iVar16 = DAT_140e9fd1c % 0x65 + 0x96;
    }
    DAT_140e44908 = (float)iVar24;
    DAT_140e4490c = (float)iVar16;
  }
  uVar17 = (ushort)uVar27;
  switch(param_1[5]) {
  case 0:
    iVar16 = param_1[3];
    if (0x3b < iVar16) {
      iVar11 = 0xff;
    }
    if ((iVar16 < 0x3c) || (0xb3 < iVar16)) {
      iVar24 = (iVar16 >> 0x1f & 0xffffff01U) + 0xff;
      if ((-1 < iVar16) && (iVar16 < 0x3c)) {
        dVar30 = (double)FUN_140332d90(((double)iVar16 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                       DAT_140539d28);
        iVar24 = (int)(dVar30 * DAT_14053a5f8);
        goto LAB_1400151cd;
      }
      dVar30 = DAT_140539ee0;
      if ((-1 < iVar16) && (dVar30 = DAT_140539f40, iVar16 < 0xb4)) goto LAB_1400151cd;
    }
    else {
      dVar30 = (double)FUN_140332d90(((double)iVar16 - DAT_14053a3a0) * DAT_14053a4d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar24 = (iVar16 >> 0x1f & 0xffffff01U) + 0xff;
      iVar11 = (int)(dVar30 * DAT_14053a5f8);
LAB_1400151cd:
      dVar30 = (double)FUN_140332d90(((double)iVar16 - 0.0) * DAT_14053a438 * dVar8 * dVar29);
      dVar30 = dVar30 * DAT_140539f18 + DAT_140539ee0;
    }
    dVar31 = dVar30;
    if ((int)uVar25 % 0x28 < 0xb) {
      dVar31 = (double)FUN_140332d90(((double)((int)uVar25 % 0x28) - 0.0) * DAT_14053aa88 * dVar8 *
                                     dVar29);
      dVar31 = dVar31 * dVar30 * DAT_14053b058 + dVar30;
    }
    if (iVar16 == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
    }
    iVar16 = param_1[3];
    uVar27 = iVar16 >> 0x1f & 500;
    if ((-1 < iVar16) && (iVar16 < 0xf0)) {
      dVar29 = (double)FUN_140332d90(((double)iVar16 - 0.0) * _DAT_14053a3c8 * dVar8 * dVar29);
      uVar27 = 500 - (int)(dVar29 * DAT_14053a758);
    }
    param_1[0xb] = (float)(int)uVar27 + (float)param_1[0xd];
    uVar42 = DAT_14053adf4;
    if (iVar16 == 0xb4) {
      auVar45._12_4_ = in_stack_fffffffffffffea8._12_4_;
      auVar45._0_8_ = in_stack_fffffffffffffea8._0_8_;
      auVar45._8_4_ = 0x1e;
      auVar46._8_8_ = auVar45._8_8_;
      auVar46._0_8_ = dVar32;
      uVar38 = CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),0x4000);
      uVar20 = CONCAT44(uVar40,DAT_14053adf4);
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate
                (0x40,12000,0xf,DAT_14053accc,uVar20,uVar38,dVar32,auVar46._8_8_,1,0);
      auVar47._12_4_ = auVar46._12_4_;
      auVar47._0_8_ = auVar46._0_8_;
      auVar47._8_4_ = 0x1e;
      auVar48._8_8_ = auVar47._8_8_;
      auVar48._0_8_ = dVar32;
      uVar38 = CONCAT62((int6)((ulonglong)uVar38 >> 0x10),0x4000);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),uVar42);
      stage_entity_spawn_candidate
                (0x40,12000,0xf,DAT_14053b360,uVar20,uVar38,dVar32,auVar48._8_8_,1,0);
      uVar42 = DAT_14053add4;
      auVar49._12_4_ = auVar48._12_4_;
      auVar49._0_8_ = auVar48._0_8_;
      auVar49._8_4_ = 0x1e;
      auVar50._8_8_ = auVar49._8_8_;
      auVar50._0_8_ = dVar32;
      uVar38 = CONCAT62((int6)((ulonglong)uVar38 >> 0x10),0x4000);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),DAT_14053add4);
      stage_entity_spawn_candidate
                (0x40,12000,0xf,DAT_14053ad70,uVar20,uVar38,dVar32,auVar50._8_8_,1,0);
      auVar51._12_4_ = auVar50._12_4_;
      auVar51._0_8_ = auVar50._0_8_;
      auVar51._8_4_ = 0x1e;
      auVar52._8_8_ = auVar51._8_8_;
      auVar52._0_8_ = dVar32;
      uVar38 = CONCAT62((int6)((ulonglong)uVar38 >> 0x10),0x4000);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),uVar42);
      stage_entity_spawn_candidate
                (0x40,12000,0xf,DAT_14053b3ac,uVar20,uVar38,dVar32,auVar52._8_8_,1,0);
      uVar40 = DAT_14053ad90;
      auVar53._12_4_ = auVar52._12_4_;
      auVar53._0_8_ = auVar52._0_8_;
      auVar53._8_4_ = 0x1e;
      auVar54._8_8_ = auVar53._8_8_;
      auVar54._0_8_ = dVar32;
      uVar38 = CONCAT62((int6)((ulonglong)uVar38 >> 0x10),0x4000);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),DAT_14053ad90);
      stage_entity_spawn_candidate(0x40,12000,0xf,uVar42,uVar20,uVar38,dVar32,auVar54._8_8_,1,0);
      auVar55._12_4_ = auVar54._12_4_;
      auVar55._0_8_ = auVar54._0_8_;
      auVar55._8_4_ = 0x1e;
      in_stack_fffffffffffffea0 = CONCAT62((int6)((ulonglong)uVar38 >> 0x10),0x4000);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),uVar40);
      stage_entity_spawn_candidate
                (0x40,12000,0xf,DAT_14053b3e0,uVar20,in_stack_fffffffffffffea0,dVar32,auVar55._8_8_,
                 1,0);
      uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
    }
    auVar3._8_4_ = SUB84(dVar30,0);
    auVar3._0_8_ = dVar30;
    auVar3._12_4_ = (int)((ulonglong)dVar30 >> 0x20);
    in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],CONCAT44(uVar40,param_1[0xb]),
                  in_stack_fffffffffffffea0,auVar3,iVar11,iVar11,iVar11,iVar24,1,0);
    auVar4._8_4_ = SUB84(dVar31,0);
    auVar4._0_8_ = dVar31;
    auVar4._12_4_ = (int)((ulonglong)dVar31 >> 0x20);
    FUN_1400c8410(DAT_140e44960,0x1b,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffea0 & 0xffffffffffff0000,auVar4,iVar11,iVar11,iVar11,iVar24,
                  1,0);
    if (param_1[3] == 0xf0) {
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
      DAT_140e41b0c = 0x2f9b8;
      DAT_140e4430c = 0x1194;
      DAT_140e4192c = 0;
      param_1[7] = 0x2f9b8;
      DAT_140e419bc = 1;
    }
    break;
  case 1:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar16 = (uVar27 & 0xffff) - (uint)uVar1;
    iVar11 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar11 = iVar16;
    }
    iVar16 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar16 = iVar11;
    }
    if (iVar16 < 1) {
      uVar18 = uVar1;
      if ((iVar16 < 0) && (uVar18 = uVar1 - 0x200, -0x200 < iVar16)) {
        uVar18 = uVar17;
      }
    }
    else {
      uVar18 = uVar17;
      if (0x1ff < iVar16) {
        uVar18 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar30 = (double)FUN_1403307c0();
    fVar36 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar36;
    dVar31 = (double)FUN_140332d90();
    uVar20 = _UNK_14053bb28;
    dVar30 = _DAT_14053bb20;
    uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
    iVar11 = param_1[3];
    fVar37 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar37;
    if (0x27 < iVar11) {
      FUN_1403300b4((double)(DAT_140e445dc - fVar37),(double)(DAT_140e445d8 - fVar36));
      uVar42 = DAT_14053ac2c;
      uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
      iVar16 = 1;
      if (DAT_140e419b8 == 0) {
        iVar16 = 200;
      }
      else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
        iVar16 = 0xa0;
      }
      else if (DAT_140e419b8 == 4) {
        iVar16 = 0x78;
      }
      uVar27 = 1;
      if (DAT_140e419b8 == 0) {
        uVar27 = 0xb;
      }
      else if (DAT_140e419b8 == 1) {
        uVar27 = 0x11;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        uVar27 = 0x14;
      }
      if ((0x3f < iVar11) && ((iVar11 + -0x40) % iVar16 == 0)) {
        uVar25 = 0;
        do {
          in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar42);
          in_stack_fffffffffffffe98 =
               (double)((ulonglong)in_stack_fffffffffffffe98 & 0xffffffffffff0000);
          FUN_1400709b0(10,0);
          if ((2 < DAT_140e419b8) && (uVar25 < uVar27)) {
            in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar42);
            in_stack_fffffffffffffe98 =
                 (double)((ulonglong)in_stack_fffffffffffffe98 & 0xffffffffffff0000);
            FUN_1400709b0(10,0);
          }
          uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
          uVar25 = uVar25 + 1;
        } while ((int)uVar25 <= (int)uVar27);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        uVar25 = DAT_140e418c8;
      }
    }
    if ((((param_1[0x17] == 0) && (DAT_140e41b00 == 0)) && (DAT_140e467e8 == 0)) &&
       (DAT_140e44040 == 0)) {
      DAT_140e44040 = 1;
      FUN_1400b4350(1,0x17);
      save_init_or_reset_candidate();
      DAT_140e45f68 = 0x3c;
      uVar25 = DAT_140e418c8;
    }
    dVar31 = dVar30;
    if ((int)uVar25 % 0x28 < 0xb) {
      dVar31 = (double)FUN_140332d90(((double)((int)uVar25 % 0x28) - 0.0) * DAT_14053aa88 * dVar8 *
                                     dVar29);
      dVar31 = dVar31 * DAT_14053b058 + dVar30;
    }
    in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],CONCAT44(uVar40,param_1[0xb]),
                  in_stack_fffffffffffffea0,dVar30,uVar20,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44960,0x1b,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffea0 & 0xffffffffffff0000,dVar31,dVar31,0xff,0xff,0xff,0xff,1
                  ,0);
    if (param_1[3] == 0xd5c) {
      param_1[3] = 0;
    }
    break;
  case 2:
    iVar11 = param_1[3];
    iVar16 = 0;
    if (iVar11 < 0x78) {
LAB_140015afd:
      iVar24 = 0;
      if (iVar11 < 0xdc) {
        iVar24 = iVar16;
      }
      puVar14 = DAT_140e45d28;
      if (iVar11 == 1) {
        uVar42 = param_1[0xb];
        uVar43 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar14 = (ulonglong *)_malloc_base(0x60);
          if (puVar14 == (ulonglong *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar28 = DAT_140e45d78 == (ulonglong *)0x0;
          *(undefined4 *)((longlong)puVar14 + 0x14) = uVar43;
          *(undefined4 *)(puVar14 + 3) = uVar42;
          *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar43;
          *(undefined4 *)(puVar14 + 4) = uVar42;
          *puVar14 = 1;
          puVar14[1] = 0x36;
          *(undefined4 *)(puVar14 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar14 + 0x24) = 0;
          puVar14[5] = 0;
          puVar14[6] = 0x3ff0000000000000;
          puVar14[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar14 + 8) = 0;
          *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
          *(undefined4 *)(puVar14 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
          puVar14[10] = 0xff;
          puVar14[0xb] = 0;
          if (bVar28) {
            DAT_140e45d78 = puVar14;
          }
          if (DAT_140e45d28 != (ulonglong *)0x0) {
            DAT_140e45d28[0xb] = (ulonglong)puVar14;
          }
        }
      }
    }
    else {
      iVar16 = 0xff;
      if (iVar11 < 0x82) {
        dVar30 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar24 = (int)(dVar30 * DAT_14053a5f8);
        puVar14 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar11) goto LAB_140015afd;
        dVar30 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar24 = 0;
        puVar14 = DAT_140e45d28;
        if (iVar11 < 0xdc) {
          iVar24 = (int)(dVar30 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar14;
    iVar11 = param_1[3];
    if (iVar11 < 0x78) {
      FUN_14007ac00(param_1);
      iVar11 = param_1[3];
      param_1[0xb] = (float)iVar11 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar14 = DAT_140e45d28;
    if (iVar11 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar42 = param_1[0xb];
      uVar43 = param_1[10];
      puVar14 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar14 = (ulonglong *)_malloc_base(0x60);
        if (puVar14 == (ulonglong *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (ulonglong *)0x0;
        *(undefined4 *)((longlong)puVar14 + 0x14) = uVar43;
        *(undefined4 *)(puVar14 + 3) = uVar42;
        *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar43;
        *(undefined4 *)(puVar14 + 4) = uVar42;
        *puVar14 = 1;
        puVar14[1] = 0x11;
        *(undefined4 *)(puVar14 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar14 + 0x24) = 0;
        puVar14[5] = 0;
        puVar14[6] = 0x3ff0000000000000;
        puVar14[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar14 + 8) = 0;
        *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
        *(undefined4 *)(puVar14 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
        puVar14[10] = 0xff;
        puVar14[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar14;
        }
        if (DAT_140e45d28 != (ulonglong *)0x0) {
          DAT_140e45d28[0xb] = (ulonglong)puVar14;
        }
      }
    }
    DAT_140e45d28 = puVar14;
    if (0xdb < (int)param_1[3]) {
      FUN_140001900(param_1[3],0xdc,3);
    }
    uVar42 = DAT_140e41ab8;
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    *puVar12 = uVar42;
    bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar12[1] = 0x4e;
    *(undefined8 *)(puVar12 + 2) = 5;
    puVar12[4] = 0;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = iVar24;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    if (bVar28) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
    uVar25 = DAT_140e418c8;
    iVar11 = param_1[3];
    DAT_140e46c88 = puVar12;
    if (iVar11 < 0x82) {
      dVar31 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053aa80 * dVar8 *
                                     dVar29);
      dVar30 = DAT_140539f40;
      dVar32 = dVar31 * DAT_140539e60 + DAT_140539f40;
      dVar31 = DAT_140539f40;
      if ((int)uVar25 % 5 < 6) {
        dVar31 = (double)FUN_140332d90(((double)((int)uVar25 % 5) - 0.0) * _DAT_14053ab30 * dVar8 *
                                       dVar29);
        dVar31 = dVar31 * _DAT_14053b068 + dVar30;
      }
      in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffffffff0000;
      uVar20 = CONCAT44(uVar40,param_1[0xb]);
      FUN_1400c8410(DAT_140e4495c,0x1e,7,param_1[10],uVar20,in_stack_fffffffffffffea0,dVar32,dVar30,
                    0xff,0xff,0xff,0xff,1,0);
      uVar42 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar20 = 0x1b;
      auVar56._8_8_ = dVar31;
      auVar56._0_8_ = dVar31;
      uVar40 = DAT_140e44960;
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar24 = (uVar27 & 0xffff) - (uint)uVar1;
      iVar16 = iVar24 + 0x10000;
      if (-0x8001 < iVar24) {
        iVar16 = iVar24;
      }
      iVar24 = iVar16 + -0x10000;
      if (iVar16 < 0x8001) {
        iVar24 = iVar16;
      }
      if (iVar24 < 1) {
        uVar18 = uVar1;
        if ((iVar24 < 0) && (uVar18 = uVar1 - 0x200, -0x200 < iVar24)) {
          uVar18 = uVar17;
        }
      }
      else {
        uVar18 = uVar17;
        if (0x1ff < iVar24) {
          uVar18 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar18;
      dVar30 = (double)FUN_1403307c0();
      uVar42 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
      param_1[10] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar30 = (double)FUN_140332d90();
      auVar57._4_12_ = in_stack_fffffffffffffea8._4_12_;
      auVar57._0_4_ = 0x1b;
      in_stack_fffffffffffffea0 = CONCAT44(uVar42,0x1a);
      uVar20 = CONCAT44(uVar40,0x19);
      param_1[0xb] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar11 = FUN_1400c9580(iVar11,0,7,3,uVar20,in_stack_fffffffffffffea0,auVar57);
      uVar42 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar20 = 0x1e;
      auVar56._8_8_ = _UNK_14053bb28;
      auVar56._0_8_ = _DAT_14053bb20;
      uVar40 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4);
    }
    FUN_1400c8410(uVar40,uVar20,7,param_1[10],CONCAT44(uVar42,param_1[0xb]),
                  in_stack_fffffffffffffea0 & 0xffffffffffff0000,auVar56,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x17c) {
      *(undefined8 *)(param_1 + 0x14) = 0x50;
      param_1[3] = 0;
      if (param_1[5] == 2) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 45000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 3:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar16 = (uVar27 & 0xffff) - (uint)uVar1;
    iVar11 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar11 = iVar16;
    }
    iVar16 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar16 = iVar11;
    }
    if (iVar16 < 1) {
      uVar18 = uVar1;
      if ((iVar16 < 0) && (uVar18 = uVar1 - 0x200, -0x200 < iVar16)) {
        uVar18 = uVar17;
      }
    }
    else {
      uVar18 = uVar17;
      if (0x1ff < iVar16) {
        uVar18 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar30 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar30 = (double)FUN_140332d90();
    uVar43 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
    auVar93 = in_stack_fffffffffffffea8._4_12_;
    param_1[0xb] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    fVar37 = DAT_14053adb4;
    uVar40 = DAT_14053ad1c;
    if (param_1[3] == 10) {
      uVar27 = 1;
      if (DAT_140e419b8 == 0) {
        uVar27 = 7;
      }
      else if (DAT_140e419b8 == 1) {
        uVar27 = 9;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar27 = 0xb;
      }
      else if (DAT_140e419b8 == 4) {
        uVar27 = 0xd;
      }
      iVar11 = 0;
      do {
        auVar58._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar58._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar58._8_4_ = 0x1e;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = auVar58._8_8_;
        in_stack_fffffffffffffea8 = auVar5 << 0x40;
        in_stack_fffffffffffffea0 =
             CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),
                      (short)iVar11 * (short)(0x10000 / uVar27) + -0x4000);
        in_stack_fffffffffffffe98 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe98 >> 0x20),fVar37);
        stage_entity_spawn_candidate
                  (0x41,99999999,10,uVar40,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,0,
                   auVar58._8_8_,1,0);
        uVar43 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
        uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)uVar27);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      auVar93 = in_stack_fffffffffffffea8._4_12_;
    }
    auVar59._4_12_ = auVar93;
    auVar59._0_4_ = 0x1b;
    uVar41 = CONCAT44(uVar43,0x1a);
    iVar11 = FUN_1400c9580(param_1[3],0,7,3,CONCAT44(uVar42,0x19),uVar41,auVar59);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar41 & 0xffffffffffff0000,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                  0xff,0xff,1,0);
    if (param_1[3] == 0x96) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    break;
  case 4:
  case 9:
    uVar41 = (ulonglong)(uint)param_1[3];
    iVar11 = 0x3c;
    if (param_1[3] == 1) {
      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
      if (param_1[5] == 4) {
        fVar37 = (float)param_1[10];
        uVar15 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 1;
        uVar27 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
        uVar19 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 3;
        uVar27 = uVar15 * 0x800 ^ uVar15;
        uVar19 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 4;
        fVar36 = (float)(((uVar27 ^ uVar19 >> 0xb) >> 8 ^ uVar27 ^ uVar19) % 0x29 + 0x50);
        if ((((byte)(uVar15 >> 8) ^ (byte)((uVar19 >> 0xb) >> 8) ^ (byte)uVar15 ^ (byte)uVar19) & 1)
            == 0) {
          fVar35 = fVar37 + fVar36;
          if (DAT_14053ae90 < fVar35) {
            fVar35 = fVar37 - fVar36;
          }
        }
        else {
          fVar35 = fVar37 - fVar36;
          if (fVar35 < DAT_14053adb4) {
            fVar35 = fVar37 + fVar36;
          }
        }
        param_1[0xe] = fVar35;
        uVar41 = (ulonglong)(uint)param_1[3];
        uVar27 = (uVar25 + 0x1bc >> 0x1e ^ uVar25 + 0x1bc) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar27 = uVar27 * 0x800 ^ uVar27;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar27) >> 8 ^ uVar27 ^ DAT_140e9fd18;
        param_1[0xf] = (float)(DAT_140e9fd1c % 0x65 + 0x96);
      }
      if (param_1[5] == 9) {
        if (((int)uVar41 == 1) && (uVar42 = param_1[1], DAT_140e45d1c < 0x1000)) {
          puVar14 = (ulonglong *)_malloc_base(0x60);
          if (puVar14 == (ulonglong *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar28 = DAT_140e45d78 == (ulonglong *)0x0;
          *puVar14 = uVar41;
          puVar14[1] = 0x2d;
          puVar14[2] = 0x28;
          puVar14[3] = 0;
          *(undefined4 *)(puVar14 + 4) = 0;
          *(undefined2 *)((longlong)puVar14 + 0x24) = 0;
          puVar14[5] = 0x3ff0000000000000;
          puVar14[6] = 0x3ff0000000000000;
          puVar14[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar14 + 8) = 0x3c;
          *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
          *(undefined4 *)(puVar14 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
          *(undefined4 *)(puVar14 + 10) = 0xff;
          *(undefined4 *)((longlong)puVar14 + 0x54) = uVar42;
          puVar14[0xb] = 0;
          if (bVar28) {
            DAT_140e45d78 = puVar14;
          }
          if (DAT_140e45d28 != (ulonglong *)0x0) {
            DAT_140e45d28[0xb] = (ulonglong)puVar14;
          }
          uVar41 = (ulonglong)(uint)param_1[3];
          DAT_140e45d28 = puVar14;
        }
        iVar11 = 0x28;
        param_1[0xe] = 0x43dc0000;
        param_1[0xf] = 0x43160000;
      }
    }
    fVar37 = (float)param_1[0xc];
    fVar36 = (float)param_1[0xe];
    dVar30 = (double)FUN_140332d90();
    dVar31 = (double)FUN_140332d90();
    param_1[10] = (float)(dVar30 * (double)(fVar36 - fVar37)) + fVar37;
    param_1[0xb] = (float)(dVar31 * (double)((float)param_1[0xf] - (float)param_1[0xd])) +
                   (float)param_1[0xd];
    if (fVar36 <= fVar37) {
      iVar16 = 0x19;
    }
    else {
      if ((int)uVar41 < 10) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x1d);
        uVar20 = CONCAT44(uVar40,0x1c);
        iVar16 = FUN_1400c9580(uVar41,0,5,2,uVar20,in_stack_fffffffffffffea0);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
      }
      else {
        iVar16 = 0x19;
      }
      iVar24 = param_1[3];
      if ((9 < iVar24) && (iVar24 < iVar11 + -10)) {
        in_stack_fffffffffffffea8._0_4_ = 0x20;
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x1f);
        uVar20 = CONCAT44(uVar40,0x1e);
        iVar16 = FUN_1400c9580(iVar24,10,5,3,uVar20,in_stack_fffffffffffffea0,
                               in_stack_fffffffffffffea8);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
      }
      iVar24 = param_1[3];
      if ((iVar11 + -10 <= iVar24) && (iVar24 < iVar11)) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x1c);
        uVar20 = CONCAT44(uVar40,0x1d);
        iVar16 = FUN_1400c9580(iVar24,iVar11 + -10,5,2,uVar20,in_stack_fffffffffffffea0);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
      }
    }
    auVar93 = in_stack_fffffffffffffea8._4_12_;
    piVar13 = param_1 + 3;
    if ((float)param_1[0xe] <= (float)param_1[0xc] && (float)param_1[0xc] != (float)param_1[0xe]) {
      if (*piVar13 < 10) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x22);
        uVar20 = CONCAT44(uVar40,0x21);
        iVar16 = FUN_1400c9580(*piVar13,0,5,2,uVar20,in_stack_fffffffffffffea0);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
        auVar93 = in_stack_fffffffffffffea8._4_12_;
      }
      iVar24 = *piVar13;
      if ((9 < iVar24) && (iVar24 < iVar11 + -10)) {
        auVar60._4_12_ = auVar93;
        auVar60._0_4_ = 0x25;
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x24);
        uVar20 = CONCAT44(uVar40,0x23);
        iVar16 = FUN_1400c9580(iVar24,10,5,3,uVar20,in_stack_fffffffffffffea0,auVar60);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
      }
      iVar24 = *piVar13;
      if ((iVar11 + -10 <= iVar24) && (iVar24 < iVar11)) {
        in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),0x21);
        uVar20 = CONCAT44(uVar40,0x22);
        iVar16 = FUN_1400c9580(iVar24,iVar11 + -10,5,2,uVar20,in_stack_fffffffffffffea0);
        uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
      }
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar16 * 4),0x1e,7,param_1[10],
                  CONCAT44(uVar40,param_1[0xb]),in_stack_fffffffffffffea0 & 0xffffffffffff0000,
                  _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == iVar11) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    break;
  case 5:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar16 = (uVar27 & 0xffff) - (uint)uVar1;
    iVar11 = iVar16 + 0x10000;
    if (-0x8001 < iVar16) {
      iVar11 = iVar16;
    }
    iVar16 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar16 = iVar11;
    }
    if (iVar16 < 1) {
      uVar18 = uVar1;
      if ((iVar16 < 0) && (uVar18 = uVar1 - 0x200, -0x200 < iVar16)) {
        uVar18 = uVar17;
      }
    }
    else {
      uVar18 = uVar17;
      if (0x1ff < iVar16) {
        uVar18 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar30 = (double)FUN_1403307c0();
    uVar42 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    param_1[10] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar30 = (double)FUN_140332d90();
    auVar61._4_12_ = in_stack_fffffffffffffea8._4_12_;
    auVar61._0_4_ = 0x1b;
    uVar41 = CONCAT44(uVar42,0x1a);
    param_1[0xb] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar11 = FUN_1400c9580(param_1[3],0,7,3,CONCAT44(uVar40,0x19),uVar41,auVar61);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar41 & 0xffffffffffff0000,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,
                  0xff,0xff,1,0);
    if (param_1[3] == 0x5a) {
      param_1[3] = 0;
      param_1[5] = 4;
    }
    break;
  case 6:
  case 8:
    iVar11 = param_1[3];
    dVar30 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar40 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    dVar30 = dVar30 * _DAT_14053b070 + DAT_140539f40;
    puVar14 = DAT_140e45d28;
    if (iVar11 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar42 = param_1[0xb];
      uVar43 = param_1[10];
      puVar14 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar14 = (ulonglong *)_malloc_base(0x60);
        if (puVar14 == (ulonglong *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (ulonglong *)0x0;
        *(undefined4 *)((longlong)puVar14 + 0x14) = uVar43;
        *(undefined4 *)(puVar14 + 3) = uVar42;
        *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar43;
        *(undefined4 *)(puVar14 + 4) = uVar42;
        *puVar14 = 1;
        puVar14[1] = 0x36;
        *(undefined4 *)(puVar14 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar14 + 0x24) = 0;
        puVar14[5] = 0;
        puVar14[6] = 0x3ff0000000000000;
        puVar14[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar14 + 8) = 0;
        *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
        *(undefined4 *)(puVar14 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
        puVar14[10] = 0xff;
        puVar14[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar14;
        }
        if (DAT_140e45d28 != (ulonglong *)0x0) {
          DAT_140e45d28[0xb] = (ulonglong)puVar14;
        }
      }
    }
    DAT_140e45d28 = puVar14;
    piVar13 = param_1 + 3;
    if (*piVar13 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar41 = CONCAT44(uVar40,0x27);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar11 = FUN_1400c9580(*piVar13,0,5,2,0x26,uVar41);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar41 & 0xffffffffffff0000,dVar30,dVar30,0xff,0xff,0xff,0xff,1,0);
    if (*piVar13 == 0xb4) {
      iVar11 = param_1[5];
      param_1[0x15] = 0;
      *piVar13 = 0;
      if (iVar11 == 6) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 58000;
        DAT_140e4192c = 0;
      }
      else if (iVar11 == 8) {
        DAT_140e4430c = 0x834;
        DAT_140e41b0c = 70000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar11 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 7:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar24 = (uVar27 & 0xffff) - (uint)uVar1;
    iVar16 = iVar24 + 0x10000;
    if (-0x8001 < iVar24) {
      iVar16 = iVar24;
    }
    iVar24 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar24 = iVar16;
    }
    if (iVar24 < 1) {
      uVar18 = uVar1;
      if ((iVar24 < 0) && (uVar18 = uVar1 - 0x200, -0x200 < iVar24)) {
        uVar18 = uVar17;
      }
    }
    else {
      uVar18 = uVar17;
      if (0x1ff < iVar24) {
        uVar18 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar18;
    dVar30 = (double)FUN_1403307c0();
    fVar37 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar37;
    dVar30 = (double)FUN_140332d90();
    fVar36 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar36;
    uVar40 = DAT_14053ad9c;
    if (param_1[3] == 10) {
      DAT_1407c77a0 = DAT_1407c779c;
      do {
        auVar62._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar62._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar62._8_4_ = 0x32;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = auVar62._8_8_;
        in_stack_fffffffffffffea8 = auVar6 << 0x40;
        in_stack_fffffffffffffea0 =
             CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),(short)iVar11 * 0x5555 + -0x4000);
        in_stack_fffffffffffffe98 =
             (double)((ulonglong)in_stack_fffffffffffffe98 & 0xffffffff00000000);
        stage_entity_spawn_candidate
                  (0x42,param_1[8],10,uVar40,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,0,
                   auVar62._8_8_,1,0);
        iVar11 = iVar11 + 1;
      } while (iVar11 < 3);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      fVar37 = (float)param_1[10];
      fVar36 = (float)param_1[0xb];
    }
    uVar20 = _UNK_14053bb28;
    dVar30 = _DAT_14053bb20;
    uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
    uVar42 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    auVar93 = in_stack_fffffffffffffea8._4_12_;
    iVar11 = param_1[3];
    if (0x3b < iVar11) {
      fVar36 = fVar36 - DAT_14053accc;
      local_100 = 300;
      local_fc = 0x1cc;
      local_f8 = 0x26c;
      dVar29 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar36),
                                     (double)(DAT_140e445d8 - fVar37));
      iVar16 = 1;
      iVar11 = (iVar11 + -0x3c) % 0x4b0;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x1c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar16 = 0x18;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar16 = 0x14;
      }
      else if (DAT_140e419b8 == 4) {
        iVar16 = 0x10;
      }
      local_res20 = 1;
      if (DAT_140e419b8 == 0) {
        local_res20 = 4;
      }
      else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
              (DAT_140e419b8 == 4)) {
        local_res20 = 7;
      }
      local_res18 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        local_res18 = 2;
      }
      else if (DAT_140e419b8 == 2) {
        local_res18 = 3;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        local_res18 = 4;
      }
      dVar32 = DAT_14053a088;
      if ((((DAT_140e419b8 != 0) && (dVar32 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar32 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((dVar32 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar32 = dVar30, DAT_140e419b8 == 4)))) {
        dVar32 = DAT_14053a190;
      }
      piVar13 = &local_100;
      local_108 = 3;
      do {
        iVar24 = *piVar13;
        uVar22 = (undefined2)(int)(dVar29 * dVar31);
        if (((iVar24 <= iVar11) && ((iVar11 < iVar24 + 0x50 || (iVar24 == -0x50)))) &&
           (uVar41 = (longlong)(iVar11 - iVar24) % (longlong)(iVar16 * 2), (int)uVar41 == 0)) {
          auVar63._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar63._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar63._8_4_ = 1;
          in_stack_fffffffffffffea8._8_8_ = auVar63._8_8_;
          in_stack_fffffffffffffea8._0_8_ = dVar32;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          in_stack_fffffffffffffe98 =
               (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),uVar22);
          FUN_1400709b0(4,uVar41 & 0xffffffff,iVar11,fVar36,in_stack_fffffffffffffe98,
                        in_stack_fffffffffffffea0,dVar32,in_stack_fffffffffffffea8._8_8_,local_res20
                        ,0x8000,0);
          iVar21 = 1;
          do {
            auVar64._12_4_ = in_stack_fffffffffffffea8._12_4_;
            auVar64._0_8_ = in_stack_fffffffffffffea8._0_8_;
            auVar64._8_4_ = 1;
            auVar65._8_8_ = auVar64._8_8_;
            auVar65._0_8_ = dVar32;
            in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
            uVar39 = (uint6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10);
            FUN_1400709b0(4,0);
            auVar66._12_4_ = auVar65._12_4_;
            auVar66._0_8_ = auVar65._0_8_;
            auVar66._8_4_ = 1;
            in_stack_fffffffffffffea8._8_8_ = auVar66._8_8_;
            in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
            in_stack_fffffffffffffe98 = (double)((ulonglong)uVar39 << 0x10);
            FUN_1400709b0(4);
            iVar21 = iVar21 + 1;
          } while (iVar21 <= local_res18);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
        if ((iVar16 + iVar24 <= iVar11) &&
           (((iVar11 < iVar24 + 0x50 || (iVar24 == -0x50)) &&
            ((iVar11 - (iVar16 + iVar24)) % (iVar16 * 2) == 0)))) {
          auVar67._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar67._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar67._8_4_ = 1;
          in_stack_fffffffffffffea8._8_8_ = auVar67._8_8_;
          in_stack_fffffffffffffea8._0_8_ = dVar32;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          in_stack_fffffffffffffe98 =
               (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),uVar22);
          FUN_1400709b0(4,0,iVar11,fVar36,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,dVar32
                        ,in_stack_fffffffffffffea8._8_8_,local_res20 + -1,
                        (int)(0x8000 / (longlong)(local_res20 + -1)) * (local_res20 + -2) & 0xffff,0
                       );
          iVar24 = 1;
          do {
            auVar68._12_4_ = in_stack_fffffffffffffea8._12_4_;
            auVar68._0_8_ = in_stack_fffffffffffffea8._0_8_;
            auVar68._8_4_ = 1;
            auVar69._8_8_ = auVar68._8_8_;
            auVar69._0_8_ = dVar32;
            in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
            uVar39 = (uint6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10);
            FUN_1400709b0(4,0);
            auVar70._12_4_ = auVar69._12_4_;
            auVar70._0_8_ = auVar69._0_8_;
            auVar70._8_4_ = 1;
            in_stack_fffffffffffffea8._8_8_ = auVar70._8_8_;
            in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
            in_stack_fffffffffffffe98 = (double)((ulonglong)uVar39 << 0x10);
            FUN_1400709b0(4);
            iVar24 = iVar24 + 1;
          } while (iVar24 <= local_res18);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
        uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
        uVar42 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
        auVar93 = in_stack_fffffffffffffea8._4_12_;
        piVar13 = piVar13 + 1;
        local_108 = local_108 + -1;
      } while (local_108 != 0);
    }
    auVar71._4_12_ = auVar93;
    auVar71._0_4_ = 0x1b;
    uVar41 = CONCAT44(uVar42,0x1a);
    uVar38 = CONCAT44(uVar40,0x19);
    iVar11 = FUN_1400c9580(param_1[3],0,7,3,uVar38,uVar41,auVar71);
    uVar40 = (undefined4)((ulonglong)uVar38 >> 0x20);
    auVar72._8_8_ = uVar20;
    auVar72._0_8_ = dVar30;
    goto LAB_140017d90;
  case 10:
    iVar16 = param_1[3];
    iVar21 = (iVar16 >> 0x1f & 0xffffff88U) + 200;
    iVar24 = iVar16 % 0x16c;
    if ((-1 < iVar16) && (iVar16 < 0x309)) {
      dVar32 = (double)FUN_140332d90(((double)iVar16 - 0.0) * _DAT_14053a288 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar21 = 0x50 - (int)(dVar32 * dVar9);
    }
    dVar29 = (double)FUN_140332d90(((double)iVar16 - _DAT_14053b190) * _DAT_14053a550 * dVar8 *
                                   dVar29);
    param_1[10] = (float)(dVar29 * (double)iVar21) + DAT_14053ae30;
    dVar29 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar29 * _DAT_14053b148) + DAT_14053adb4;
    uVar40 = DAT_14053ad50;
    if (iVar16 == 300) {
      DAT_1407c77a0 = DAT_1407c779c;
      do {
        auVar73._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar73._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar73._8_4_ = 0x32;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = auVar73._8_8_;
        in_stack_fffffffffffffea8 = auVar7 << 0x40;
        in_stack_fffffffffffffea0 =
             CONCAT62((int6)(in_stack_fffffffffffffea0 >> 0x10),(short)iVar11 * 0x5555 + -0x4000);
        in_stack_fffffffffffffe98 =
             (double)((ulonglong)in_stack_fffffffffffffe98 & 0xffffffff00000000);
        stage_entity_spawn_candidate
                  (0x43,param_1[8],10,uVar40,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,0,
                   auVar73._8_8_,1,0);
        iVar11 = iVar11 + 1;
      } while (iVar11 < 3);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    fVar37 = (float)param_1[0xb] - DAT_14053accc;
    dVar33 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar37),
                                   (double)(DAT_140e445d8 - (float)param_1[10]));
    dVar9 = DAT_14053a0f8;
    dVar32 = DAT_14053a0d0;
    dVar29 = DAT_140539f40;
    uVar27 = (uint)(dVar33 * dVar31);
    sVar26 = (short)uVar27;
    if (((int)param_1[3] < 0xb4) || (param_1[3] - 0x168 < 300)) {
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x2c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x1b;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 0x17;
      }
      else if (DAT_140e419b8 == 3) {
        iVar11 = 0x12;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x10;
      }
      local_res20 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        local_res20 = 2;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        local_res20 = 3;
      }
      local_res18 = 1;
      if (DAT_140e419b8 == 0) {
        local_res18 = 9;
      }
      else if (DAT_140e419b8 == 1) {
        local_res18 = 0xf;
      }
      else if (DAT_140e419b8 == 2) {
        local_res18 = 0x13;
      }
      else if (DAT_140e419b8 == 3) {
        local_res18 = 0x15;
      }
      else if (DAT_140e419b8 == 4) {
        local_res18 = 0x17;
      }
      dVar31 = DAT_14053a088;
      if (((DAT_140e419b8 != 0) && (dVar31 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
         ((dVar31 = DAT_14053a0d0, DAT_140e419b8 != 2 &&
          ((dVar31 = DAT_14053a0f8, DAT_140e419b8 != 3 &&
           (dVar31 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
        dVar31 = DAT_14053a140;
      }
      if (((uint)param_1[3] < 0x294) && ((int)param_1[3] % (iVar11 * 6) == 0)) {
        auVar74._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar74._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar74._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar74._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar31;
        in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
        in_stack_fffffffffffffe98 =
             (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),sVar26);
        FUN_1400709b0(4);
        iVar16 = 1;
        do {
          auVar75._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar75._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar75._8_4_ = 1;
          auVar76._8_8_ = auVar75._8_8_;
          auVar76._0_8_ = dVar31;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          uVar39 = (uint6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10);
          FUN_1400709b0(4,0);
          auVar77._12_4_ = auVar76._12_4_;
          auVar77._0_8_ = auVar76._0_8_;
          auVar77._8_4_ = 1;
          in_stack_fffffffffffffea8._8_8_ = auVar77._8_8_;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          in_stack_fffffffffffffe98 = (double)((ulonglong)uVar39 << 0x10);
          FUN_1400709b0(4);
          iVar16 = iVar16 + 1;
        } while (iVar16 <= local_res20);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      iVar16 = param_1[3];
      if (((iVar11 * 3 <= iVar16) && (iVar16 < 0x294)) &&
         ((iVar16 + iVar11 * -3) % (iVar11 * 6) == 0)) {
        auVar78._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar78._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar78._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar78._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar31;
        in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
        in_stack_fffffffffffffe98 =
             (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),sVar26);
        FUN_1400709b0(4,0);
        iVar16 = 1;
        do {
          auVar79._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar79._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar79._8_4_ = 1;
          auVar80._8_8_ = auVar79._8_8_;
          auVar80._0_8_ = dVar31;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          uVar39 = (uint6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10);
          FUN_1400709b0(4,0);
          auVar81._12_4_ = auVar80._12_4_;
          auVar81._0_8_ = auVar80._0_8_;
          auVar81._8_4_ = 1;
          in_stack_fffffffffffffea8._8_8_ = auVar81._8_8_;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          in_stack_fffffffffffffe98 = (double)((ulonglong)uVar39 << 0x10);
          FUN_1400709b0(4);
          iVar16 = iVar16 + 1;
        } while (iVar16 <= local_res20);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      iVar16 = param_1[3];
      if (((iVar11 <= iVar16) && (iVar16 < 0x294)) && ((iVar16 - iVar11) % (iVar11 * 3) == 0)) {
        auVar82._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar82._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar82._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar82._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar31;
        in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
        in_stack_fffffffffffffe98 =
             (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),sVar26);
        FUN_1400709b0(0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      iVar16 = param_1[3];
      if (((iVar11 * 2 <= iVar16) && (iVar16 < 0x294)) &&
         ((iVar16 + iVar11 * -2) % (iVar11 * 3) == 0)) {
        uVar25 = local_res18 - 1;
        auVar83._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar83._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar83._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar83._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar31;
        in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
        in_stack_fffffffffffffe98 =
             (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),sVar26);
        FUN_1400709b0(0,0,(ulonglong)uVar25,fVar37,in_stack_fffffffffffffe98,
                      in_stack_fffffffffffffea0,dVar31,in_stack_fffffffffffffea8._8_8_,uVar25,
                      (int)(0x8000 / (ulonglong)uVar25) * (local_res18 + -2) & 0xffff,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    iVar11 = DAT_140e419b8;
    if (param_1[3] - 200 < 0x96) {
      iVar16 = 1;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x32;
      }
      else if (DAT_140e419b8 == 1) {
        iVar16 = 0x28;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar16 = 0x1e;
      }
      else if (DAT_140e419b8 == 4) {
        iVar16 = 0x26;
      }
      iVar21 = 1;
      if (DAT_140e419b8 == 0) {
        iVar21 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar21 = 0x1c;
      }
      else if (DAT_140e419b8 == 2) {
        iVar21 = 0x1b;
      }
      else if (DAT_140e419b8 == 3) {
        iVar21 = 0x1e;
      }
      else if (DAT_140e419b8 == 4) {
        iVar21 = 0x24;
      }
      dVar31 = DAT_140539e50;
      if ((((DAT_140e419b8 != 0) && (dVar31 = DAT_140539e70, DAT_140e419b8 != 1)) &&
          (dVar31 = DAT_140539e90, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar31 = dVar29, DAT_140e419b8 == 4)))) {
        dVar31 = DAT_140539ea0;
      }
      iVar10 = param_1[3] + -200;
      if (DAT_140e419b8 == 0) {
        uVar41 = (longlong)iVar10 % (longlong)iVar16 & 0xffffffff;
        dVar29 = (double)(int)((longlong)iVar10 % (longlong)iVar16) * dVar31 + dVar30;
LAB_140017903:
        iVar23 = (int)uVar41;
      }
      else {
        if (DAT_140e419b8 == 1) {
          uVar41 = (longlong)iVar10 % (longlong)iVar16 & 0xffffffff;
          dVar29 = (double)(int)((longlong)iVar10 % (longlong)iVar16) * dVar31 + dVar32;
          goto LAB_140017903;
        }
        if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar41 = (longlong)iVar10 % (longlong)iVar16 & 0xffffffff;
          dVar29 = (double)(int)((longlong)iVar10 % (longlong)iVar16) * dVar31 + dVar9;
          goto LAB_140017903;
        }
        iVar23 = (int)((longlong)iVar10 % (longlong)iVar16);
        uVar41 = (longlong)iVar10 % (longlong)iVar16 & 0xffffffff;
        if (DAT_140e419b8 == 4) {
          dVar29 = (double)iVar23 * dVar31 + DAT_14053a158;
        }
        else {
          dVar29 = (double)iVar23 * dVar31 + dVar29;
        }
      }
      iVar16 = iVar23 / 3 + 1;
      if (iVar23 == 0) {
        *(short *)((longlong)param_1 + 0x42) = sVar26;
      }
      if (((param_1[3] - 200 < 0x96) && (iVar23 < iVar21)) &&
         (iVar21 = (int)uVar41,
         iVar21 == (iVar21 / 3 + (iVar21 >> 0x1f) +
                   (int)(((longlong)iVar21 / 3 + ((longlong)iVar21 >> 0x3f) & 0xffffffffU) >> 0x1f))
                   * 3)) {
        auVar84._12_4_ = in_stack_fffffffffffffea8._12_4_;
        auVar84._0_8_ = in_stack_fffffffffffffea8._0_8_;
        auVar84._8_4_ = 1;
        in_stack_fffffffffffffea8._8_8_ = auVar84._8_8_;
        in_stack_fffffffffffffea8._0_8_ = dVar29;
        in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
        in_stack_fffffffffffffe98 =
             (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),
                              *(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(0xc,0,uVar41,fVar37,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,dVar29
                      ,in_stack_fffffffffffffea8._8_8_,iVar16,iVar16 * 600 + -600,0);
        if (2 < DAT_140e419b8) {
          auVar85._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar85._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar85._8_4_ = 1;
          auVar86._8_8_ = auVar85._8_8_;
          auVar86._0_8_ = dVar29;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          uVar39 = (uint6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10);
          FUN_1400709b0(0xc,0);
          auVar87._12_4_ = auVar86._12_4_;
          auVar87._0_8_ = auVar86._0_8_;
          auVar87._8_4_ = 1;
          in_stack_fffffffffffffea8._8_8_ = auVar87._8_8_;
          in_stack_fffffffffffffea0 = in_stack_fffffffffffffea0 & 0xffffffff00000000;
          in_stack_fffffffffffffe98 = (double)((ulonglong)uVar39 << 0x10);
          FUN_1400709b0(0xc,0);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar11 = DAT_140e419b8;
      }
    }
    uVar40 = DAT_14053ac2c;
    dVar9 = DAT_14053a950;
    dVar32 = DAT_14053a888;
    dVar29 = DAT_14053a818;
    dVar31 = DAT_14053a778;
    dVar30 = DAT_14053a4b0;
    uVar20 = DAT_14053a218;
    uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
    uVar43 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    if (0x29d < (int)param_1[3]) {
      iVar16 = 0;
      do {
        iVar21 = 1;
        if (iVar11 == 0) {
          iVar21 = 10000;
        }
        else if (iVar11 == 1) {
          iVar21 = 8000;
        }
        else if ((iVar11 == 2) || (iVar11 == 3)) {
          iVar21 = 0x1d4c;
        }
        else if (iVar11 == 4) {
          iVar21 = 7000;
        }
        iVar10 = param_1[3];
        iVar21 = iVar21 + iVar16;
        iVar23 = iVar21 * 5;
        if (0x29d < iVar10) {
          iVar23 = iVar21;
        }
        if (iVar10 - 0x29eU < 0x82) {
          dVar33 = (double)FUN_140332d90(((double)iVar10 - dVar29) * dVar30 * dVar8 * DAT_140539d28)
          ;
          uVar25 = uVar27 & 0xffff;
          iVar23 = (int)(dVar33 * (double)(iVar21 * -4)) + iVar21 * 5;
LAB_140017ba5:
          iVar10 = iVar10 + -0x29e;
          if (iVar10 == (iVar10 / 3 + (iVar10 >> 0x1f) +
                        (int)(((longlong)iVar10 / 3 + ((longlong)iVar10 >> 0x3f) & 0xffffffffU) >>
                             0x1f)) * 3) {
            auVar88._12_4_ = in_stack_fffffffffffffea8._12_4_;
            auVar88._0_8_ = in_stack_fffffffffffffea8._0_8_;
            auVar88._8_4_ = 1;
            in_stack_fffffffffffffea8._8_8_ = auVar88._8_8_;
            in_stack_fffffffffffffea8._0_8_ = uVar20;
            in_stack_fffffffffffffea0 = CONCAT44((int)(in_stack_fffffffffffffea0 >> 0x20),uVar40);
            in_stack_fffffffffffffe98 =
                 (double)CONCAT62((int6)((ulonglong)in_stack_fffffffffffffe98 >> 0x10),(short)uVar25
                                 );
            FUN_1400709b0(8,0,uVar25,fVar37,in_stack_fffffffffffffe98,in_stack_fffffffffffffea0,
                          uVar20,in_stack_fffffffffffffea8._8_8_,2,iVar23,0);
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar11 = DAT_140e419b8;
          }
        }
        else {
          if (799 < iVar10) {
            dVar33 = (double)FUN_140332d90(((double)iVar10 - dVar32) * dVar31 * dVar8 *
                                           DAT_140539d28);
            uVar25 = CONCAT22((short)((uint)(int)(dVar33 * dVar9) >> 0x10),
                              (short)(int)(dVar33 * dVar9) + sVar26);
            goto LAB_140017ba5;
          }
          uVar25 = uVar27 & 0xffff;
          if (0x29d < iVar10) goto LAB_140017ba5;
        }
        uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
        uVar43 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
        iVar16 = iVar16 + 5000;
      } while (iVar16 < 15000);
    }
    auVar89._4_12_ = in_stack_fffffffffffffea8._4_12_;
    if (iVar24 < 0xf) {
      auVar89._0_4_ = 0x22;
      uVar41 = CONCAT44(uVar43,0x21);
      uVar20 = CONCAT44(uVar42,0x1a);
      iVar11 = FUN_1400c9580(iVar24,0,5,3,uVar20,uVar41,auVar89);
      uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
    }
    else {
      if (iVar24 < 0xa7) {
        auVar90._4_12_ = auVar89._4_12_;
        auVar90._0_4_ = 0x25;
        uVar20 = 0xf;
        uVar41 = CONCAT44(uVar43,0x24);
        uVar38 = CONCAT44(uVar42,0x23);
      }
      else {
        if (iVar24 < 0xc5) {
          auVar91._12_4_ = in_stack_fffffffffffffea8._12_4_;
          auVar91._0_8_ = in_stack_fffffffffffffea8._0_8_;
          auVar91._8_4_ = 0x1a;
          auVar92._4_12_ = auVar91._4_12_;
          auVar92._0_4_ = 0x19;
          uVar41 = CONCAT44(uVar43,0x21);
          uVar20 = CONCAT44(uVar42,0x22);
          iVar11 = FUN_1400c9580(iVar24,0xa7,5,6,uVar20,uVar41,auVar92,0x1c,0x1d);
          uVar40 = (undefined4)((ulonglong)uVar20 >> 0x20);
          goto LAB_140017d59;
        }
        if (iVar24 < 0x15d) {
          auVar90._4_12_ = auVar89._4_12_;
          auVar90._0_4_ = 0x20;
          uVar20 = 0xc5;
          uVar41 = CONCAT44(uVar43,0x1f);
          uVar38 = CONCAT44(uVar42,0x1e);
        }
        else {
          auVar90._4_12_ = auVar89._4_12_;
          auVar90._0_4_ = 0x19;
          uVar20 = 0x15d;
          uVar41 = CONCAT44(uVar43,0x1c);
          uVar38 = CONCAT44(uVar42,0x1d);
        }
      }
      iVar11 = FUN_1400c9580(iVar24,uVar20,5,3,uVar38,uVar41,auVar90);
      uVar40 = (undefined4)((ulonglong)uVar38 >> 0x20);
    }
LAB_140017d59:
    auVar72._8_8_ = _UNK_14053bb28;
    auVar72._0_8_ = _DAT_14053bb20;
LAB_140017d90:
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4),0x1e,7,param_1[10],
                  CONCAT44(uVar40,param_1[0xb]),uVar41 & 0xffffffffffff0000,auVar72,0xff,0xff,0xff,
                  0xff,1,0);
    break;
  case 0xb:
    FUN_140003ad0(param_1);
    uVar20 = _UNK_14053bb28;
    dVar30 = _DAT_14053bb20;
    uVar42 = (undefined4)(in_stack_fffffffffffffea0 >> 0x20);
    iVar11 = param_1[3];
    if (iVar11 < 0xf0) {
      iVar16 = DAT_1407c7798 + 3;
      iVar24 = DAT_1407c7798 * 10;
      if (iVar11 - 0x3cU < 0xb4) {
        uVar41 = 0;
        uVar38 = CONCAT44(uVar40,0xf0);
        uVar34 = FUN_1401349e0(iVar11,0x3c,0x4c,0xe0,uVar38,0,_DAT_14053bb20);
        fVar37 = DAT_14053accc;
        uVar41 = uVar41 & 0xffffffffffff0000;
        uVar38 = CONCAT44((int)((ulonglong)uVar38 >> 0x20),DAT_14053accc);
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,uVar38,uVar41,dVar30,uVar34,0xff,0xff,0xff,
                      0xff,1,0);
        uVar41 = uVar41 & 0xffffffffffff0000;
        uVar38 = CONCAT44((int)((ulonglong)uVar38 >> 0x20),fVar37);
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar16 * 4),0x6e,1,DAT_14053ae44,
                      uVar38,uVar41,uVar34,uVar34,0xff,0xff,0xff,0xff,1,0);
        uVar40 = (undefined4)((ulonglong)uVar38 >> 0x20);
        uVar42 = (undefined4)(uVar41 >> 0x20);
        if (iVar11 == 0x4c) {
          FUN_14012e070(iVar24 + 99,4);
        }
        else {
          lVar2 = DAT_140e47908;
          if (iVar11 == 0xe0) {
            while (lVar2 != 0) {
              lVar2 = *(longlong *)(lVar2 + 0x238);
              FUN_140323ce8();
              uVar40 = (undefined4)((ulonglong)uVar38 >> 0x20);
              uVar42 = (undefined4)(uVar41 >> 0x20);
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar41 = CONCAT44(uVar42,0x27);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar11 = FUN_1400c9580(param_1[3],0,5,2,CONCAT44(uVar40,0x26),uVar41);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar11 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar41 & 0xffffffffffff0000,dVar30,uVar20,0xff,0xff,0xff,0xff,1,0);
    }
    puVar14 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar40 = param_1[0xb];
      uVar42 = param_1[10];
      puVar14 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar14 = (ulonglong *)_malloc_base(0x60);
        if (puVar14 == (ulonglong *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (ulonglong *)0x0;
        *(undefined4 *)((longlong)puVar14 + 0x14) = uVar42;
        *(undefined4 *)(puVar14 + 3) = uVar40;
        *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar42;
        *(undefined4 *)(puVar14 + 4) = uVar40;
        *puVar14 = 1;
        puVar14[1] = 0x10;
        *(undefined4 *)(puVar14 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar14 + 0x24) = 0;
        puVar14[5] = 0;
        puVar14[6] = 0x3ff0000000000000;
        puVar14[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar14 + 8) = 0;
        *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
        *(undefined4 *)(puVar14 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
        puVar14[10] = 0xff;
        puVar14[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar14;
        }
        if (DAT_140e45d28 != (ulonglong *)0x0) {
          DAT_140e45d28[0xb] = (ulonglong)puVar14;
        }
      }
    }
    DAT_140e45d28 = puVar14;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


