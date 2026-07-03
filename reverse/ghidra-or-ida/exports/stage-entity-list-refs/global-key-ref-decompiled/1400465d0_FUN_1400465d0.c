// Function: FUN_1400465d0 @ 1400465d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400465d0(undefined4 *param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  ushort uVar8;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  undefined2 uVar14;
  short sVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  ushort uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar30;
  double dVar29;
  undefined4 uVar31;
  double dVar32;
  double dVar33;
  float fVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  double dVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  int local_res10;
  undefined4 in_stack_fffffffffffffda8;
  undefined2 uVar50;
  uint in_stack_fffffffffffffdb0;
  undefined8 in_stack_fffffffffffffdc0;
  undefined8 uVar51;
  ulonglong in_stack_fffffffffffffdc8;
  undefined8 uVar52;
  longlong lVar53;
  int local_1f0;
  undefined *local_1e8;
  double local_1d0 [2];
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  ushort uVar9;
  
  local_1f0 = 0;
  uStack_1a8 = (ulonglong)(uint)uStack_1a8;
  if ((0 < DAT_140e44e6c) && (puVar13 = DAT_140e45d80, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar13 + 4) == DAT_140e44308) {
        local_1c0 = *puVar13;
        uStack_1b8 = puVar13[1];
        local_1b0 = puVar13[2];
        uStack_1a8 = puVar13[3];
        local_1a0 = puVar13[4];
        uStack_198 = puVar13[5];
        local_190 = puVar13[6];
        uStack_188 = puVar13[7];
        local_180 = puVar13[8];
        uStack_178 = puVar13[9];
        local_170 = puVar13[10];
        uStack_168 = puVar13[0xb];
        local_160 = puVar13[0xc];
      }
      puVar13 = (undefined8 *)puVar13[0xc];
    } while (puVar13 != (undefined8 *)0x0);
    local_1f0 = uStack_1a8._4_4_;
  }
  puVar13 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar13 != (undefined8 *)0x0; puVar13 = (undefined8 *)puVar13[0xc]) {
      if (*(int *)((longlong)puVar13 + 4) == param_1[2]) {
        local_158 = *puVar13;
        uStack_150 = puVar13[1];
        local_148 = puVar13[2];
        uStack_140 = puVar13[3];
        local_138 = puVar13[4];
        uStack_130 = puVar13[5];
        local_128 = puVar13[6];
        uStack_120 = puVar13[7];
        local_118 = puVar13[8];
        uStack_110 = puVar13[9];
        local_108 = puVar13[10];
        uStack_100 = puVar13[0xb];
        local_f8 = puVar13[0xc];
      }
    }
  }
  fVar42 = uStack_130._4_4_;
  fVar44 = (float)uStack_130;
  fVar38 = uStack_130._4_4_ + (float)param_1[0xd];
  fVar39 = (float)param_1[0xc];
  fVar43 = (float)param_1[0xb];
  fVar34 = (float)uStack_130 + fVar39;
  fVar45 = (float)param_1[10];
  dVar37 = (double)FUN_1403300b4(SUB84((double)(fVar38 - fVar43),0),(double)(fVar34 - fVar45));
  dVar46 = DAT_14053aba0;
  uVar12 = SUB84(DAT_14053aba0,0);
  uVar49 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
  dVar37 = dVar37 * DAT_14053aba0;
  fVar26 = (float)FUN_140334430(fVar45 - fVar34);
  fVar34 = (float)FUN_140334430(fVar43 - fVar38);
  fVar26 = fVar26 + fVar34;
  if (fVar26 < 0.0) {
    fVar26 = (float)FUN_1403352f8(fVar26);
  }
  else {
    fVar26 = SQRT(fVar26);
  }
  dVar36 = DAT_14053b128;
  dVar4 = DAT_14053a798;
  dVar3 = DAT_14053a020;
  dVar35 = DAT_140539f40;
  dVar29 = DAT_140539d28;
  iVar18 = param_1[6];
  local_res10 = 0;
  if ((iVar18 == 0xba) && (fVar39 < 0.0)) {
    local_res10 = 1;
  }
  iVar6 = local_1b0._4_4_;
  uVar28 = SUB84(DAT_140539f40,0);
  uVar31 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  if (param_1[5] == 0) {
    uVar23 = param_1[3];
    if (uVar23 < 0x1e) {
      dVar37 = (double)FUN_140332d90(SUB84(((double)(int)uVar23 - DAT_14053b128) * DAT_14053a798 *
                                           DAT_14053a020 * DAT_140539d28,0));
      fVar39 = (float)(dVar37 * DAT_14053a7c8) + 0.0;
    }
    else {
      fVar39 = DAT_14053aec0;
      if (0x1d < (int)uVar23) {
        fVar39 = 0.0;
      }
    }
    if ((local_res10 == 1) && (fVar39 = DAT_14053b414, -1 < (int)uVar23)) {
      if ((int)uVar23 < 0x1e) {
        dVar37 = (double)FUN_140332d90(SUB84(((double)(int)uVar23 - dVar36) * dVar4 * DAT_14053a020
                                             * DAT_140539d28,0));
        fVar39 = (float)(dVar37 * _DAT_14053b260) + 0.0;
      }
      else {
        fVar39 = 0.0;
      }
    }
    if (iVar18 == 0xb8) {
      param_1[10] = fVar44 + (float)param_1[0xe];
      param_1[0xb] = fVar42 + (float)param_1[0xf] + fVar39;
      if (uVar23 == 0x14) {
        in_stack_fffffffffffffdc8 = CONCAT44((int)(in_stack_fffffffffffffdc8 >> 0x20),1);
        in_stack_fffffffffffffdc0 =
             CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),0x50);
        in_stack_fffffffffffffdb0 = in_stack_fffffffffffffdb0 & 0xffff0000;
        in_stack_fffffffffffffda8 = DAT_14053b3bc;
        stage_entity_spawn_candidate
                  (0xb9,99999999,1,0,DAT_14053b3bc,in_stack_fffffffffffffdb0,dVar35,
                   in_stack_fffffffffffffdc0,in_stack_fffffffffffffdc8,param_1[1]);
      }
      uVar40 = DAT_14053b360;
      uVar23 = param_1[3];
      if (uVar23 == 0x32) {
        uVar52 = CONCAT44((int)(in_stack_fffffffffffffdc8 >> 0x20),1);
        uVar51 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),0x6e);
        uVar41 = CONCAT22((short)(in_stack_fffffffffffffdb0 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0xba,99999999,1,DAT_14053ada4,DAT_14053b360,uVar41,dVar35,uVar51,uVar52,
                   param_1[1]);
        in_stack_fffffffffffffdc8 = CONCAT44((int)((ulonglong)uVar52 >> 0x20),1);
        in_stack_fffffffffffffdc0 = CONCAT44((int)((ulonglong)uVar51 >> 0x20),0x6e);
        in_stack_fffffffffffffdb0 = CONCAT22((short)((uint)uVar41 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0xba,99999999,1,DAT_14053b3c0,uVar40,in_stack_fffffffffffffdb0,dVar35,
                   in_stack_fffffffffffffdc0,in_stack_fffffffffffffdc8,param_1[1]);
        uVar23 = param_1[3];
        in_stack_fffffffffffffda8 = uVar40;
      }
    }
    if (param_1[6] == 0xb9) {
      fVar44 = fVar44 + (float)param_1[0xe];
      fVar42 = (fVar42 + (float)param_1[0xf]) - fVar39;
LAB_140046a53:
      param_1[0xb] = fVar42;
      param_1[10] = fVar44;
    }
    else if (param_1[6] == 0xba) {
      fVar42 = fVar42 + (float)param_1[0xf];
      fVar44 = fVar44 + (float)param_1[0xe] + fVar39;
      goto LAB_140046a53;
    }
    uVar51 = DAT_140539fd8;
    if (uVar23 == 0x1e) {
      iVar10 = 0;
      iVar25 = 0;
      iVar18 = iVar10;
      do {
        iVar5 = DAT_140e418c8;
        uVar50 = (undefined2)(in_stack_fffffffffffffdb0 >> 0x10);
        iVar16 = DAT_140e418c8 + iVar25;
        uVar23 = ((uint)(iVar10 + DAT_140e418c8) >> 0x1e ^ iVar10 + DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar23 = uVar23 * 0x800 ^ uVar23;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar23 = (DAT_140e9fd18 >> 0xb ^ uVar23) >> 8 ^ uVar23 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar23;
        in_stack_fffffffffffffdc8 = FUN_140134db0(iVar16,DAT_140e9fd18,uVar51);
        in_stack_fffffffffffffdc0 = FUN_140134db0(iVar16);
        uVar52 = FUN_140134db0(iVar18 + iVar5);
        in_stack_fffffffffffffda8 = param_1[0xb];
        in_stack_fffffffffffffdb0 = CONCAT22(uVar50,(short)uVar23 - (short)(uVar23 / 0x10001));
        FUN_140070d00(0x2c,DAT_140e44ea8,0x48,param_1[10],in_stack_fffffffffffffda8,
                      in_stack_fffffffffffffdb0,uVar52,in_stack_fffffffffffffdc0,
                      in_stack_fffffffffffffdc8,0,0xff,0xff,0xff,0xc0,0);
        iVar10 = iVar10 + 0x37;
        iVar25 = iVar25 + 0x15b3;
        iVar18 = iVar18 + 0x22b;
      } while (iVar10 < 0x14a);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472e8);
      FUN_14018a340(DAT_140e472e8,1,1);
    }
    uVar50 = (undefined2)(in_stack_fffffffffffffdb0 >> 0x10);
    if (iVar6 == 0x34) {
      param_1[0x15] = 0;
      uVar40 = DAT_14053b358;
      if (param_1[6] == 0xb9) {
        uVar52 = CONCAT44((int)(in_stack_fffffffffffffdc8 >> 0x20),1);
        uVar51 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),0x5a);
        in_stack_fffffffffffffdb0 = in_stack_fffffffffffffdb0 & 0xffff0000;
        stage_entity_spawn_candidate
                  (0x152,99999999,1,DAT_14053ad64,DAT_14053b358,in_stack_fffffffffffffdb0,0,uVar51,
                   uVar52,param_1[1]);
        in_stack_fffffffffffffdc8 = CONCAT44((int)((ulonglong)uVar52 >> 0x20),1);
        in_stack_fffffffffffffdc0 = CONCAT44((int)((ulonglong)uVar51 >> 0x20),0x5a);
        in_stack_fffffffffffffdb0 = in_stack_fffffffffffffdb0 & 0xffff0000;
        stage_entity_spawn_candidate
                  (0x152,99999999,1,DAT_14053b3a4,uVar40,in_stack_fffffffffffffdb0,0,
                   in_stack_fffffffffffffdc0,in_stack_fffffffffffffdc8,param_1[1]);
        uVar50 = (undefined2)(in_stack_fffffffffffffdb0 >> 0x10);
        in_stack_fffffffffffffda8 = uVar40;
      }
      if (param_1[6] == 0xba) {
        uVar14 = 0x9c4;
        if (local_res10 != 0) {
          uVar14 = 0xf63c;
        }
        in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
        in_stack_fffffffffffffdc0 =
             CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),0x32);
        in_stack_fffffffffffffda8 = 0;
        stage_entity_spawn_candidate
                  (0xbb,40000,0x4d,0,0,CONCAT22(uVar50,uVar14),dVar35,in_stack_fffffffffffffdc0,
                   in_stack_fffffffffffffdc8,param_1[1]);
        param_1[0x17] = 1;
      }
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    fVar45 = (float)param_1[10];
    fVar43 = (float)param_1[0xb];
  }
  else if (iVar18 == 0xb8) {
    fVar43 = fVar42 + (float)param_1[0xf];
    fVar45 = fVar44 + (float)param_1[0xe];
    param_1[0xb] = fVar43;
    param_1[10] = fVar45;
LAB_140046d7f:
    if (iVar18 == 0xba) {
      dVar35 = (double)fVar26 / _DAT_14053a320;
      uVar40 = SUB84((double)((int)dVar37 & 0xffff) * dVar3 * dVar29,0);
      dVar37 = (double)FUN_1403307c0(uVar40);
      fVar45 = (float)(dVar37 * dVar35) + fVar45;
      param_1[10] = fVar45;
      dVar37 = (double)FUN_140332d90(uVar40);
      fVar43 = (float)(dVar37 * dVar35) + fVar43;
      param_1[0xb] = fVar43;
    }
  }
  else {
    if (iVar18 != 0xb9) goto LAB_140046d7f;
    dVar29 = (double)fVar26 / DAT_14053a278;
    uVar40 = SUB84((double)((int)dVar37 & 0xffff) * DAT_14053a020 * DAT_140539d28,0);
    dVar37 = (double)FUN_1403307c0(uVar40);
    fVar45 = (float)(dVar37 * dVar29) + fVar45;
    param_1[10] = fVar45;
    dVar37 = (double)FUN_140332d90(uVar40);
    fVar43 = (float)(dVar37 * dVar29) + fVar43;
    param_1[0xb] = fVar43;
  }
  fVar39 = DAT_140e445d8;
  dVar35 = DAT_14053a0b0;
  dVar29 = DAT_14053a088;
  dVar37 = DAT_14053a040;
  if (param_1[5] == 1) {
    uVar47 = SUB84(DAT_14053a088,0);
    uVar48 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
    uVar40 = SUB84(DAT_14053a138,0);
    uVar41 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    uVar28 = SUB84(DAT_14053a040,0);
    uVar31 = (undefined4)((ulonglong)DAT_14053a040 >> 0x20);
    uVar23 = (param_1[3] + -100) % 0x708;
    iVar18 = DAT_140e419b8;
    if (param_1[6] == 0xb9) {
      fVar43 = fVar43 - DAT_14053ac44;
      fVar44 = fVar45 + DAT_14053ad58;
      fVar45 = fVar45 - DAT_14053ad58;
      uVar40 = SUB84((double)(DAT_140e445dc - fVar43),0);
      dVar3 = (double)FUN_1403300b4(uVar40,(double)(DAT_140e445d8 - fVar44));
      dVar4 = (double)FUN_1403300b4(uVar40,(double)(fVar39 - fVar45));
      iVar18 = DAT_140e419b8;
      uVar17 = (uint)(dVar4 * dVar46);
      uVar40 = SUB84(DAT_14053a138,0);
      uVar41 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      if ((int)uVar23 < 600) {
        uVar17 = 1;
        if (DAT_140e419b8 == 0) {
          uVar17 = 3;
        }
        else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
                (DAT_140e419b8 == 4)) {
          uVar17 = 5;
        }
        iVar10 = 1;
        if (DAT_140e419b8 == 0) {
          iVar10 = 0xe;
        }
        else if (DAT_140e419b8 == 1) {
          iVar10 = 0xb;
        }
        else if (DAT_140e419b8 == 2) {
LAB_140046fdc:
          iVar10 = 9;
        }
        else if (DAT_140e419b8 == 3) {
          iVar10 = 10;
        }
        else if (DAT_140e419b8 == 4) goto LAB_140046fdc;
        uVar27 = uVar28;
        uVar30 = uVar31;
        if (((DAT_140e419b8 != 0) && (uVar27 = uVar47, uVar30 = uVar48, DAT_140e419b8 != 1)) &&
           ((DAT_140e419b8 != 2 &&
            ((uVar27 = SUB84(dVar35,0), uVar30 = (int)((ulonglong)dVar35 >> 0x20),
             DAT_140e419b8 != 3 &&
             (uVar27 = SUB84(DAT_140539f40,0), uVar30 = (int)((ulonglong)DAT_140539f40 >> 0x20),
             DAT_140e419b8 == 4)))))) {
          uVar27 = (int)DAT_14053a120;
          uVar30 = (int)((ulonglong)DAT_14053a120 >> 0x20);
        }
        dVar46 = (double)(int)uVar23;
        dVar37 = dVar46 * DAT_140539d90 + (double)CONCAT44(uVar30,uVar27);
        dVar35 = DAT_14053a0b0;
        if ((uVar23 < 0x226) && ((int)uVar23 % iVar10 == 0)) {
          iVar10 = 0;
          iVar18 = 0;
          dVar29 = (double)FUN_1403307c0((int)DAT_14053a058);
          fVar39 = DAT_14053ad04 / (float)(int)(uVar17 - 1);
          local_1d0[0] = dVar29;
          dVar33 = (double)FUN_140332d90((int)DAT_14053a058);
          dVar4 = DAT_14053ab10;
          dVar3 = DAT_14053a588;
          dVar35 = DAT_140539f10;
          iVar25 = 0x82;
          dVar36 = DAT_14053a020;
          do {
            uVar50 = (undefined2)((uint)in_stack_fffffffffffffda8 >> 0x10);
            uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20);
            dVar32 = (double)((float)iVar18 * fVar39);
            fVar45 = (float)(dVar32 * dVar33) + 0.0;
            fVar43 = (float)(dVar32 * dVar29) + _DAT_14053ad98;
            dVar29 = (double)FUN_140332d90(SUB84((dVar46 - (double)iVar10) * dVar3 * dVar36 *
                                                 DAT_140539d28,0));
            sVar21 = (short)iVar18 * (short)(20000 / (ulonglong)uVar17);
            sVar7 = (short)(int)(dVar29 * dVar4);
            sVar15 = sVar21 + sVar7 + 0x18f0;
            dVar29 = (double)FUN_140332d90(SUB84((dVar46 - (double)iVar25) * dVar3 * dVar36 *
                                                 DAT_140539d28,0));
            sVar19 = (short)(int)(dVar29 * dVar4);
            sVar20 = (sVar19 - sVar21) + 0x6710;
            if (DAT_140e445dc < (float)param_1[0xb]) {
              sVar15 = (sVar7 - sVar21) + -0x18f0;
              sVar20 = sVar21 + sVar19 + -0x6710;
            }
            in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
            uVar51 = CONCAT44(uVar12,1);
            uVar12 = CONCAT22(uVar50,sVar15);
            FUN_14006c2f0(4,0,fVar43 + (float)param_1[10],(float)param_1[0xb] + fVar45,uVar12,0,
                          dVar37,uVar51,in_stack_fffffffffffffdc8);
            in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
            in_stack_fffffffffffffdc0 = CONCAT44((int)((ulonglong)uVar51 >> 0x20),1);
            in_stack_fffffffffffffda8 = CONCAT22((short)((uint)uVar12 >> 0x10),sVar20);
            FUN_14006c2f0(4,0,(float)param_1[10] - fVar43,fVar45 + (float)param_1[0xb],
                          in_stack_fffffffffffffda8,0,dVar37,in_stack_fffffffffffffdc0,
                          in_stack_fffffffffffffdc8);
            if (2 < DAT_140e419b8) {
              in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
              uVar51 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),1);
              uVar12 = CONCAT22((short)((uint)in_stack_fffffffffffffda8 >> 0x10),sVar15);
              FUN_14006c2f0(4,0,fVar43 + (float)param_1[10],fVar45 + (float)param_1[0xb],uVar12,0,
                            dVar37 + dVar35,uVar51,in_stack_fffffffffffffdc8);
              in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
              in_stack_fffffffffffffdc0 = CONCAT44((int)((ulonglong)uVar51 >> 0x20),1);
              in_stack_fffffffffffffda8 = CONCAT22((short)((uint)uVar12 >> 0x10),sVar20);
              FUN_14006c2f0(4,0,(float)param_1[10] - fVar43,fVar45 + (float)param_1[0xb],
                            in_stack_fffffffffffffda8,0,dVar37 + dVar35,in_stack_fffffffffffffdc0,
                            in_stack_fffffffffffffdc8);
              dVar36 = DAT_14053a020;
            }
            iVar18 = iVar18 + 1;
            iVar10 = iVar10 + 10;
            iVar25 = iVar25 + -10;
            dVar29 = local_1d0[0];
          } while (iVar18 < (int)uVar17);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          uVar47 = SUB84(DAT_14053a088,0);
          uVar48 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
          uVar28 = SUB84(DAT_14053a040,0);
          uVar31 = (undefined4)((ulonglong)DAT_14053a040 >> 0x20);
          uVar12 = SUB84(DAT_14053aba0,0);
          uVar49 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
          uVar40 = SUB84(DAT_14053a138,0);
          uVar41 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
          iVar18 = DAT_140e419b8;
          dVar35 = DAT_14053a0b0;
        }
      }
      else {
        uVar24 = (uint)(in_stack_fffffffffffffdc8 >> 0x20);
        uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20);
        uVar50 = (undefined2)((uint)in_stack_fffffffffffffda8 >> 0x10);
        if ((int)uVar23 < 0x514) {
          iVar10 = 1;
          if (DAT_140e419b8 == 0) {
            iVar10 = 0x5a;
          }
          else if (DAT_140e419b8 == 1) {
            iVar10 = 0x3c;
          }
          else if (DAT_140e419b8 == 2) {
            iVar10 = 0x30;
          }
          else if (DAT_140e419b8 == 3) {
            iVar10 = 0x20;
          }
          else if (DAT_140e419b8 == 4) {
            iVar10 = 0x1b;
          }
          dVar37 = dVar35;
          if (((DAT_140e419b8 != 0) && (dVar37 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
             ((dVar37 = DAT_14053a138, DAT_140e419b8 != 2 &&
              ((dVar37 = DAT_14053a178, DAT_140e419b8 != 3 &&
               (dVar37 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
            dVar37 = DAT_14053a1b8;
          }
          if ((uVar23 - 0x2d0 < 0x212) &&
             (uVar2 = (longlong)(int)(uVar23 - 0x2d0) % (longlong)iVar10, (int)uVar2 == 0)) {
            in_stack_fffffffffffffdc8 = (ulonglong)uVar24 << 0x20;
            sVar21 = (short)(int)(dVar3 * dVar46);
            FUN_14006c2f0(0xd,uVar2 & 0xffffffff,fVar44,fVar43,CONCAT22(uVar50,sVar21),0,dVar37,
                          CONCAT44(uVar27,1),in_stack_fffffffffffffdc8);
            dVar29 = DAT_140539f10;
            dVar46 = dVar37 - DAT_140539f10;
            iVar18 = 0;
            do {
              in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
              FUN_14006c2f0(0xd,0,fVar44,fVar43,(short)iVar18 * 0x457 + sVar21 + -0x22b,0,dVar46,1,
                            in_stack_fffffffffffffdc8);
              iVar18 = iVar18 + 1;
            } while (iVar18 < 2);
            in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
            FUN_14006c2f0(0xd,0,fVar45,fVar43,uVar17 & 0xffff,0,dVar37,1,in_stack_fffffffffffffdc8);
            iVar18 = 0;
            do {
              in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
              FUN_14006c2f0(0xd,0,fVar45,fVar43,(short)iVar18 * 0x457 + (short)uVar17 + -0x22b,0,
                            dVar37 - dVar29,1,in_stack_fffffffffffffdc8);
              iVar18 = iVar18 + 1;
            } while (iVar18 < 2);
            uVar40 = SUB84(DAT_14053a138,0);
            uVar41 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
            iVar18 = DAT_140e419b8;
            dVar35 = DAT_14053a0b0;
          }
        }
        else {
          uVar17 = 1;
          if (DAT_140e419b8 == 0) {
            uVar17 = 4;
          }
          else if (DAT_140e419b8 == 1) {
            uVar17 = 5;
          }
          else if (DAT_140e419b8 == 2) {
            uVar17 = 6;
          }
          else if (DAT_140e419b8 == 3) {
            uVar17 = 8;
          }
          else if (DAT_140e419b8 == 4) {
            uVar17 = 9;
          }
          iVar10 = 1;
          if (DAT_140e419b8 == 0) {
            iVar10 = 5;
          }
          else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
            iVar10 = 4;
          }
          else if (DAT_140e419b8 == 4) {
            iVar10 = 3;
          }
          sVar21 = 1;
          if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
            sVar21 = 0xf0;
          }
          else if (DAT_140e419b8 == 2) {
LAB_1400476d1:
            sVar21 = 0xdc;
          }
          else if (DAT_140e419b8 == 3) {
            sVar21 = 200;
          }
          else if (DAT_140e419b8 == 4) goto LAB_1400476d1;
          if (((DAT_140e419b8 != 0) && (dVar37 = dVar29, DAT_140e419b8 != 1)) &&
             ((dVar37 = dVar35, DAT_140e419b8 != 2 &&
              ((DAT_140e419b8 != 3 && (dVar37 = DAT_140539f40, DAT_140e419b8 == 4)))))) {
            dVar37 = DAT_14053a118;
          }
          if (uVar23 == 0x514) {
            *(undefined2 *)((longlong)param_1 + 0x42) = 0x4000;
            sVar7 = 0x4000;
            *(short *)(param_1 + 0x11) = (short)(0x10000 / (ulonglong)(uVar17 * 2)) + 0x4000;
          }
          else {
            sVar7 = *(short *)((longlong)param_1 + 0x42);
          }
          if (local_res10 == 0) {
            uVar11 = uVar23 - 0x514;
            if (uVar11 < 0x1b8) {
LAB_1400477a0:
              if ((int)uVar11 % (iVar10 * 2) == 0) {
                if (uVar17 == 1) {
                  lVar53 = (ulonglong)uVar24 << 0x20;
                  uVar51 = CONCAT44(uVar27,1);
                  uVar40 = CONCAT22(uVar50,sVar7);
                  FUN_14006c2f0(4,0,fVar44,fVar43,uVar40,0,dVar37,uVar51,lVar53);
                  uVar50 = (undefined2)((uint)uVar40 >> 0x10);
                  uVar40 = (undefined4)((ulonglong)uVar51 >> 0x20);
                  uVar41 = (undefined4)((ulonglong)lVar53 >> 0x20);
                }
                else {
                  iVar18 = 0;
                  do {
                    in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
                    in_stack_fffffffffffffdc0 =
                         CONCAT44((int)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20),1);
                    in_stack_fffffffffffffda8 =
                         CONCAT22((short)((uint)in_stack_fffffffffffffda8 >> 0x10),
                                  (short)iVar18 * (short)(0x10000 / (ulonglong)uVar17) + sVar7);
                    FUN_14006c2f0(4,0,fVar44,fVar43,in_stack_fffffffffffffda8,0,dVar37,
                                  in_stack_fffffffffffffdc0,in_stack_fffffffffffffdc8);
                    uVar50 = (undefined2)((uint)in_stack_fffffffffffffda8 >> 0x10);
                    uVar40 = (undefined4)((ulonglong)in_stack_fffffffffffffdc0 >> 0x20);
                    uVar41 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);
                    iVar18 = iVar18 + 1;
                  } while (iVar18 < (int)uVar17);
                }
                in_stack_fffffffffffffdc8 = CONCAT44(uVar41,uVar17);
                FUN_1400709b0(4,0,fVar45,fVar43,CONCAT22(uVar50,*(undefined2 *)(param_1 + 0x11)),0,
                              dVar37,CONCAT44(uVar40,1),in_stack_fffffffffffffdc8,0x10000,0);
                FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
                FUN_14018a340(DAT_140e472a8,1,1);
                iVar18 = DAT_140e419b8;
              }
            }
          }
          else if (((local_res10 == 1) && (iVar10 + 0x514 <= (int)uVar23)) && ((int)uVar23 < 0x6cc))
          {
            uVar11 = uVar23 - (iVar10 + 0x514);
            goto LAB_1400477a0;
          }
          *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar21;
          *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + sVar21;
          uVar40 = SUB84(DAT_14053a138,0);
          uVar41 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
        }
      }
    }
    dVar37 = DAT_140539f40;
    if (param_1[6] == 0xba) {
      dVar46 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - (float)param_1[0xb]),0),
                                     (double)(DAT_140e445d8 - (float)param_1[10]));
      uVar17 = (uint)(dVar46 * (double)CONCAT44(uVar49,uVar12));
      uVar22 = (ushort)uVar17;
      if ((int)uVar23 < 600) goto LAB_140047e33;
      uVar24 = 1;
      iVar10 = 1;
      uVar12 = (undefined4)((ulonglong)dVar35 >> 0x20);
      if ((int)uVar23 < 0x514) {
        if ((iVar18 == 0) || (iVar18 == 1)) {
          iVar10 = 7;
        }
        else if (iVar18 == 2) {
          iVar10 = 9;
        }
        else if ((iVar18 == 3) || (iVar18 == 4)) {
          iVar10 = 0xb;
        }
        uVar24 = 1;
        if (iVar18 == 0) {
          uVar24 = 9;
        }
        else if ((((iVar18 == 1) || (iVar18 == 2)) || (iVar18 == 3)) || (iVar18 == 4)) {
          uVar24 = 0xb;
        }
        iVar25 = 1;
        if (iVar18 == 0) {
          iVar25 = 0x2c;
        }
        else if (((iVar18 == 1) || (iVar18 == 2)) || (iVar18 == 3)) {
          iVar25 = 0x21;
        }
        else if (iVar18 == 4) {
          iVar25 = 0x1b;
        }
        if (((iVar18 != 0) && (uVar28 = uVar47, uVar31 = uVar48, iVar18 != 1)) &&
           ((uVar28 = SUB84(dVar35,0), uVar31 = uVar12, iVar18 != 2 &&
            ((iVar18 != 3 &&
             (uVar28 = SUB84(dVar37,0), uVar31 = (int)((ulonglong)dVar37 >> 0x20), iVar18 == 4))))))
        {
          uVar28 = SUB84(DAT_14053a0f8,0);
          uVar31 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
        }
        dVar37 = ((double)(int)uVar23 - DAT_14053a7c8) * _DAT_140539d80 +
                 (double)CONCAT44(uVar31,uVar28);
        if (((int)uVar23 < 0x4e2) && ((int)(uVar23 - 600) % (iVar25 * 5) == 0)) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar22;
        }
        dVar46 = DAT_140539f00;
        if (local_res10 == 0) {
          if ((int)uVar23 < 0x4e2) {
            iVar18 = uVar23 - 600;
LAB_140047a31:
            uVar2 = (longlong)iVar18 % (longlong)(iVar25 * 10);
            iVar18 = (int)uVar2;
            if ((iVar18 < iVar25 * 4) &&
               ((int)((longlong)((ulonglong)(uint)(iVar18 >> 0x1f) << 0x20 | uVar2 & 0xffffffff) %
                     (longlong)iVar25) == 0)) {
              iVar18 = 0;
              do {
                sVar21 = (short)(0x10000 / uVar24) * (short)iVar18;
                FUN_1400709b0(4,0,param_1[10],param_1[0xb],
                              sVar21 + *(short *)((longlong)param_1 + 0x42),0,dVar37,1,iVar10,
                              iVar10 * 0x168 + -0x168,0);
                if (2 < DAT_140e419b8) {
                  FUN_1400709b0(4,0,param_1[10],param_1[0xb],
                                sVar21 + *(short *)((longlong)param_1 + 0x42),0,dVar37 + dVar46,1,
                                iVar10,iVar10 * 0x168 + -0x2d0,0);
                }
                iVar18 = iVar18 + 1;
              } while (iVar18 < (int)uVar24);
              sVar21 = (short)(0x10000 / (ulonglong)(uint)(iVar10 * 3));
              if (local_res10 != 0) {
                sVar21 = -sVar21;
              }
              *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar21;
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
              FUN_14018a340(DAT_140e472a8,1,1);
            }
          }
        }
        else if (((local_res10 == 1) && ((iVar25 + 0x78) * 5 <= (int)uVar23)) &&
                ((int)uVar23 < 0x4e2)) {
          iVar18 = uVar23 + (iVar25 + 0x78) * -5;
          goto LAB_140047a31;
        }
      }
      else {
        if (iVar18 == 0) {
          uVar24 = 3;
        }
        else if (iVar18 == 1) {
          uVar24 = 4;
        }
        else if (iVar18 == 2) {
          uVar24 = 5;
        }
        else if (iVar18 == 3) {
          uVar24 = 7;
        }
        else if (iVar18 == 4) {
          uVar24 = 8;
        }
        iVar10 = 1;
        if (iVar18 == 0) {
          iVar10 = 6;
        }
        else if (((iVar18 == 1) || (iVar18 == 2)) || (iVar18 == 3)) {
          iVar10 = 5;
        }
        else if (iVar18 == 4) {
          iVar10 = 4;
        }
        sVar21 = 1;
        if ((iVar18 == 0) || (iVar18 == 1)) {
          sVar21 = 0xdc;
        }
        else if (iVar18 == 2) {
          sVar21 = 200;
        }
        else if (iVar18 == 3) {
          sVar21 = 0xb4;
        }
        else if (iVar18 == 4) {
          sVar21 = 0xd2;
        }
        dVar46 = DAT_14053a070;
        if (((iVar18 != 0) && (dVar46 = dVar35, iVar18 != 1)) &&
           ((dVar46 = DAT_14053a0d0, iVar18 != 2 &&
            ((iVar18 != 3 && (dVar46 = dVar37, iVar18 == 4)))))) {
          dVar46 = (double)CONCAT44(uVar41,uVar40);
        }
        if (uVar23 == 0x514) {
          if (local_res10 == 0) {
            *(undefined2 *)((longlong)param_1 + 0x42) = 0xc000;
LAB_140047d91:
            if ((int)(uVar23 - 0x514) % (iVar10 * 2) != 0) goto LAB_140047da7;
LAB_140047cfc:
            sVar7 = *(short *)((longlong)param_1 + 0x42);
            uVar12 = param_1[0xb];
            uVar49 = param_1[10];
            if (uVar24 == 1) {
              FUN_14006c2f0(2,0,uVar49,uVar12,sVar7,0,dVar46,1,
                            in_stack_fffffffffffffdc8 & 0xffffffff00000000);
            }
            else {
              uVar23 = 0;
              do {
                in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;
                FUN_14006c2f0(2,0,uVar49,uVar12,
                              (short)((uVar23 & 0xffff) * (0x10000 / uVar24 & 0xffff)) + sVar7,0,
                              dVar46,1,in_stack_fffffffffffffdc8);
                uVar23 = uVar23 + 1;
              } while ((int)uVar23 < (int)uVar24);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            goto LAB_140047da7;
          }
          *(short *)((longlong)param_1 + 0x42) =
               (short)(0x10000 / (ulonglong)(uVar24 * 2)) + -0x4000;
LAB_140047cc0:
          if (local_res10 != 1) goto LAB_140047da7;
          if (((iVar10 + 0x514 <= (int)uVar23) && ((int)uVar23 < 0x6cc)) &&
             ((int)(uVar23 - (iVar10 + 0x514)) % (iVar10 * 2) == 0)) goto LAB_140047cfc;
          sVar7 = *(short *)((longlong)param_1 + 0x42);
        }
        else {
          if (local_res10 != 0) goto LAB_140047cc0;
          if ((int)uVar23 < 0x6cc) goto LAB_140047d91;
LAB_140047da7:
          sVar7 = *(short *)((longlong)param_1 + 0x42);
          if (local_res10 == 0) {
            *(short *)((longlong)param_1 + 0x42) = sVar7 - sVar21;
            goto LAB_140047e33;
          }
        }
        *(short *)((longlong)param_1 + 0x42) = sVar21 + sVar7;
      }
LAB_140047e33:
      if (0 < (int)param_1[0x17]) {
        if ((ushort)(uVar22 + 0xcfa0) < 0x8fa0) {
          if (0x4f9f < uVar22) {
            uVar17 = 0x4fa0;
          }
        }
        else {
          uVar17 = 0x3060;
        }
        if ((int)param_1[3] % 300 < 0x32) {
          uVar22 = *(ushort *)(param_1 + 0x10);
          uVar9 = (ushort)uVar17;
          uVar8 = uVar9 - uVar22;
          uVar23 = (uint)uVar8;
          if (0x8000 < uVar8) {
            uVar23 = 0x10000 - uVar8;
          }
          iVar10 = (uVar17 & 0xffff) - (uint)uVar22;
          iVar25 = (int)uVar23 / 0x14 + 0x30;
          iVar18 = iVar10 + 0x10000;
          if (-0x8001 < iVar10) {
            iVar18 = iVar10;
          }
          iVar10 = iVar18 + -0x10000;
          if (iVar18 < 0x8001) {
            iVar10 = iVar18;
          }
          if (iVar10 < 1) {
            if ((iVar10 < 0) && (uVar22 = uVar22 - (short)iVar25, -iVar25 < iVar10)) {
              uVar22 = uVar9;
            }
            *(ushort *)(param_1 + 0x10) = uVar22;
          }
          else if (iVar10 < iVar25) {
            *(ushort *)(param_1 + 0x10) = uVar9;
          }
          else {
            *(ushort *)(param_1 + 0x10) = uVar22 + (short)iVar25;
          }
        }
      }
    }
    iVar10 = DAT_140e44308;
    iVar18 = param_1[7];
    if ((iVar18 < local_1f0) && (puVar13 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; puVar13 != (undefined8 *)0x0; puVar13 = (undefined8 *)puVar13[0xc]) {
        if (*(int *)((longlong)puVar13 + 4) == iVar10) {
          *(int *)((longlong)puVar13 + 0x1c) =
               *(int *)((longlong)puVar13 + 0x1c) - (local_1f0 - iVar18);
        }
      }
    }
    iVar18 = param_1[7];
    if (local_1f0 < iVar18) {
      param_1[7] = local_1f0;
      iVar18 = local_1f0;
    }
    iVar10 = DAT_140e44308;
    if ((iVar18 < 1) && (puVar13 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; puVar13 != (undefined8 *)0x0; puVar13 = (undefined8 *)puVar13[0xc]) {
        if (*(int *)((longlong)puVar13 + 4) == iVar10) {
          *(int *)((longlong)puVar13 + 0x1c) = *(int *)((longlong)puVar13 + 0x1c) - local_1f0;
        }
      }
    }
    uVar28 = SUB84(DAT_140539f40,0);
    uVar31 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  }
  uVar12 = DAT_140e44880;
  iVar18 = param_1[6];
  sVar21 = *(short *)(param_1 + 0x10);
  uVar49 = 0x1e;
  if (iVar18 != 0xb9) {
    uVar49 = 0x20;
  }
  uVar40 = 0xff;
  uVar23 = (iVar18 == 0xb9) + 0x39;
  local_1e8 = &DAT_ff000000ff;
  if (iVar18 == 0xba) {
    uVar49 = 0x1f;
    if ((param_1[0x17] == 1) || (uVar23 = 0x3c, iVar6 == 0x33)) {
      uVar23 = 0x3b;
    }
    if (local_res10 == 1) {
      sVar21 = sVar21 + -0x8000;
    }
  }
  iVar18 = uStack_1b8._4_4_;
  uVar41 = 0xff;
  if (iVar6 == 0x33) {
    puVar13 = DAT_140e45d28;
    if ((int)param_1[3] < 0x1e) {
      uVar40 = param_1[0xb];
      uVar47 = param_1[10];
      if (local_res10 == 0) {
        if (DAT_140e45d1c < 0x1000) {
          puVar13 = (undefined8 *)_malloc_base(0x60);
          if (puVar13 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          puVar1 = DAT_140e45d78;
          DAT_140e45d1c = DAT_140e45d1c + 1;
          puVar13[5] = 0;
          puVar13[0xb] = 0;
          *(undefined4 *)(puVar13 + 1) = 5;
LAB_14004816a:
          *(undefined4 *)((longlong)puVar13 + 0xc) = uVar12;
          puVar13[7] = 0x3ff0000000000000;
          puVar13[6] = 0x3ff0000000000000;
          *(undefined4 *)(puVar13 + 4) = uVar40;
          *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar47;
          *(undefined4 *)(puVar13 + 3) = uVar40;
          *(undefined4 *)((longlong)puVar13 + 0x14) = uVar47;
          puVar13[10] = 0x60;
          *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
          *(undefined4 *)(puVar13 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
          *(undefined4 *)(puVar13 + 8) = 0x10;
          *(short *)((longlong)puVar13 + 0x24) = sVar21;
          *(undefined4 *)(puVar13 + 2) = 0x1d;
          *puVar13 = 1;
          if (puVar1 == (undefined8 *)0x0) {
            DAT_140e45d78 = puVar13;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar13;
          }
        }
      }
      else if (DAT_140e45d1c < 0x1000) {
        puVar13 = (undefined8 *)_malloc_base();
        if (puVar13 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar1 = DAT_140e45d78;
        DAT_140e45d1c = DAT_140e45d1c + 1;
        puVar13[5] = 0;
        puVar13[0xb] = 0;
        *(undefined4 *)(puVar13 + 1) = 7;
        goto LAB_14004816a;
      }
    }
    DAT_140e45d28 = puVar13;
    uVar40 = 0xff;
    if (iVar18 < 0x96) {
      puVar13 = (undefined8 *)FUN_140135060(local_1d0,iVar18,0x14);
      local_1e8 = (undefined *)*puVar13;
      uVar40 = *(undefined4 *)(puVar13 + 1);
      uVar41 = local_1e8._0_4_;
    }
  }
  uVar12 = (undefined4)((ulonglong)local_1e8 >> 0x20);
  FUN_1400c8410((&DAT_140e44910)[uVar23],uVar49,7,param_1[10],param_1[0xb],sVar21,
                CONCAT44(uVar31,uVar28),CONCAT44(uVar31,uVar28),uVar41,uVar12,uVar40,0xff,1,
                local_res10);
  if ((iVar6 == 0x33) && (iVar18 < 0x96)) {
    FUN_1400c8410((&DAT_140e44910)[uVar23],uVar49,8,param_1[10],param_1[0xb],sVar21,
                  CONCAT44(uVar31,uVar28),CONCAT44(uVar31,uVar28),uVar41,uVar12,uVar40,0xff,1,
                  local_res10);
  }
  if (iVar6 < 0x3c) {
LAB_140048360:
    if (param_1[5] != 9) {
      return;
    }
  }
  else if (param_1[5] != 9) {
    param_1[0x15] = 1;
    param_1[0x14] = 0xb4;
    param_1[3] = 0;
    param_1[5] = 9;
    goto LAB_140048360;
  }
  iVar18 = param_1[3];
  if (iVar18 == 0x3c) {
    if (param_1[6] != 0xb9) {
      return;
    }
  }
  else {
    if (iVar18 == 0x50) {
      if (param_1[6] != 0xba) {
        return;
      }
      if (local_res10 == 0) goto LAB_1400483bd;
    }
    if (iVar18 == 100) {
      if (param_1[6] != 0xba) {
        return;
      }
      if (local_res10 == 1) goto LAB_1400483bd;
    }
    if (iVar18 != 0x78) {
      return;
    }
    if (param_1[6] != 0xb8) {
      return;
    }
  }
LAB_1400483bd:
  FUN_140079e20(param_1,2);
  *param_1 = 0;
  return;
}


