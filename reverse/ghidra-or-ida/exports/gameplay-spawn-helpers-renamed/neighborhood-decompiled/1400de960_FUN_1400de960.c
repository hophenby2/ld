// Function: FUN_1400de960 @ 1400de960
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400de960(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  longlong lVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  float *pfVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  float fVar37;
  undefined4 uVar38;
  int local_res8;
  int local_res18;
  undefined8 in_stack_fffffffffffffea8;
  undefined4 uVar41;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined2 uVar42;
  undefined8 in_stack_fffffffffffffec0;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  undefined4 uVar51;
  undefined4 uVar52;
  undefined4 uVar53;
  undefined4 uVar54;
  
  uVar54 = 0x61;
  uVar53 = 0x60;
  uVar52 = 0x61;
  uVar51 = 0x5f;
  uVar50 = 0x5e;
  uVar49 = 0x5d;
  uVar48 = 0x5c;
  uVar47 = 0x5b;
  uVar46 = 0x5a;
  uVar45 = 0x5b;
  uVar44 = 0x5a;
  uVar43 = 0x5c;
  uVar39 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffec0 >> 0x20),0x5d);
  dVar28 = 4.64421707090772e-322;
  uVar19 = 0;
  dVar29 = (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffea8 >> 0x20),0x60);
  iVar9 = FUN_1400c9580(DAT_140e418c8,0,5,0x10,dVar29,0x5f,0x5e,uVar39,0x5c,0x5a,0x5b,0x5a,0x5b,0x5c
                        ,0x5d,0x5e,0x5f,0x61,0x60,0x61);
  dVar25 = DAT_14053a070;
  uVar34 = (undefined4)((ulonglong)dVar29 >> 0x20);
  uVar42 = (undefined2)(uVar19 >> 0x10);
  iVar10 = 0;
  iVar17 = 0x83;
  local_res8 = 0x83;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    uVar44 = 0;
    uVar43 = 1;
    uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),param_1[0x14]);
    uVar19 = uVar19 & 0xffff0000;
    dVar29 = (double)CONCAT44(uVar34,param_1[0xb]);
    dVar28 = DAT_14053a4f0;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],dVar29,uVar19,DAT_14053a4f0,uVar39,1,0);
    uVar42 = (undefined2)(uVar19 >> 0x10);
    if (DAT_140e45da4 == 2) {
      uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      dVar29 = dVar25;
      uVar34 = DAT_14053ac80;
      FUN_1400ca6d0(7,param_1[10],param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),dVar25,
                    DAT_14053ac80);
      uVar42 = (undefined2)((uint)uVar34 >> 0x10);
      if (((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e4404c == 0)) {
        DAT_140e4404c = 1;
        FUN_1400b4350(1,0x1a);
        save_init_or_reset_candidate();
        DAT_140e45f68 = 0x3c;
      }
    }
    if (DAT_140e41af8 == 1) {
      param_1[5] = 3;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar6 = DAT_14053a020;
  dVar27 = DAT_140539d28;
  uVar36 = SUB84(DAT_140539d28,0);
  uVar38 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar24 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a498 * DAT_14053a020
                                 * DAT_140539d28);
  uVar8 = _UNK_14053bb28;
  dVar7 = _DAT_14053bb20;
  dVar26 = DAT_14053a5f8;
  uVar41 = (undefined4)((ulonglong)dVar29 >> 0x20);
  iVar16 = param_1[5];
  uVar34 = SUB84(DAT_14053a5f8,0);
  uVar35 = (undefined4)((ulonglong)DAT_14053a5f8 >> 0x20);
  fVar30 = (float)(dVar24 * DAT_14053b0d8) + 0.0 + DAT_140e45d24 + (float)param_1[0xc];
  param_1[10] = fVar30;
  if (iVar16 == 0) {
    iVar10 = 0;
    if (param_1[3] == 0) {
      uVar39 = CONCAT44(uVar41,DAT_14053ad50);
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate(0x79,99999999,0,0,uVar39,CONCAT22(uVar42,0x4000),dVar7,0x46,1,0);
      uVar43 = DAT_14053ad2c;
      uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),DAT_14053ad2c);
      stage_entity_spawn_candidate(0x7b,15000,0x3c,DAT_14053ada8,uVar39,0x4000,dVar7,0x2d,1,0);
      uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),uVar43);
      stage_entity_spawn_candidate(0x7b,15000,0x3c,DAT_14053b3c4,uVar39,0x4000,dVar7,0x2d,1,0);
      uVar41 = DAT_14053b36c;
      uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),DAT_14053b36c);
      stage_entity_spawn_candidate(0x7d,6000,0x1e,DAT_14053accc,uVar39,0x4000,dVar7,0x28,1,0);
      uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),uVar41);
      stage_entity_spawn_candidate(0x7d,6000,0x1e,DAT_14053b360,uVar39,0x4000,dVar7,0x28,1,0);
      uVar40 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),uVar41);
      stage_entity_spawn_candidate(0x7d,6000,0x1e,DAT_14053ad70,uVar40,0x4000,dVar7,0x28,1,0);
      uVar44 = 0;
      uVar43 = 1;
      uVar39 = 0x28;
      uVar40 = CONCAT44((int)((ulonglong)uVar40 >> 0x20),uVar41);
      dVar28 = dVar7;
      stage_entity_spawn_candidate(0x7d,6000,0x1e,DAT_14053b3ac,uVar40,0x4000,dVar7,0x28,1,0);
      uVar2 = DAT_140e472d8;
      uVar41 = (undefined4)((ulonglong)uVar40 >> 0x20);
      param_1[0x17] = 6;
      FUN_140184700(DAT_140e44190 * 0x19,uVar2);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar10 = param_1[5];
    }
    uVar19 = param_1[3];
    if (uVar19 < 0x78) {
      dVar25 = (double)FUN_140332d90(((double)(int)uVar19 - 0.0) * DAT_14053a4d8 * dVar6 * dVar27);
      param_1[0xb] = (float)(900 - (int)(dVar25 * DAT_14053a888));
      local_res8 = iVar17;
      puVar13 = DAT_140e46c88;
    }
    else {
      param_1[0xb] = (float)(((int)uVar19 >> 0x1f & 800U) + 100);
      local_res8 = iVar17;
      puVar13 = DAT_140e46c88;
      if (uVar19 == 0x82) {
        DAT_140e45da4 = 0;
        param_1[5] = iVar10 + 1;
        param_1[0x15] = 0;
        param_1[3] = 0;
        DAT_140e41b0c = 60000;
        DAT_140e4430c = 0x834;
        DAT_140e4192c = 0;
        param_1[7] = 60000;
        DAT_140e419bc = 1;
        puVar13 = DAT_140e46c88;
      }
    }
  }
  else if ((iVar16 == 1) || (iVar16 == 2)) {
    iVar10 = param_1[3];
    dVar26 = (double)FUN_140332d90(((double)iVar10 - _DAT_14053b1f8) * _DAT_14053a3e0 * dVar6 *
                                   dVar27);
    dVar27 = DAT_14053a0b0;
    uVar41 = (undefined4)((ulonglong)dVar29 >> 0x20);
    fVar33 = (float)(dVar26 * DAT_14053b120) + DAT_14053ad48;
    param_1[0xb] = fVar33;
    iVar17 = iVar10 % 0x578;
    if ((iVar17 < 0x230) || (iVar11 = DAT_140e419b8, iVar16 == 2)) {
      iVar16 = 1;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x28;
      }
      else if (DAT_140e419b8 == 1) {
        iVar16 = 0x3c;
      }
      else if (DAT_140e419b8 == 2) {
        iVar16 = 0x50;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar16 = 100;
      }
      iVar21 = iVar17 % 0xb8;
      if (((9 < iVar17) && (iVar11 = (iVar17 + -10) % 0xb8, iVar11 < iVar16)) &&
         (iVar11 == (iVar11 / 10) * 10)) {
        uVar19 = (iVar10 + 2U >> 0x1e ^ iVar10 + 2U) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar19;
        dVar28 = (double)FUN_140134db0(iVar10,dVar27,DAT_14053a1e8);
        uVar44 = 0;
        uVar43 = 1;
        uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),0x14);
        dVar29 = (double)CONCAT44(uVar41,fVar33 + DAT_14053aca4);
        stage_entity_spawn_candidate
                  (0x7f,500,3,fVar30,dVar29,
                   CONCAT22(uVar42,(short)((ulonglong)uVar19 / 0x8001) * 0x7fff + (short)uVar19),
                   dVar28,uVar39,1,0);
      }
      iVar11 = DAT_140e419b8;
      if (iVar21 < 10) {
        dVar29 = (double)CONCAT44((int)((ulonglong)dVar29 >> 0x20),0x84);
        local_res8 = FUN_1400c9580(iVar21,0,5,2,dVar29,0x85);
        if (iVar16 <= iVar21) {
LAB_1400df1ff:
          if (iVar21 < iVar16 + 10) {
            dVar29 = (double)CONCAT44((int)((ulonglong)dVar29 >> 0x20),0x84);
            local_res8 = FUN_1400c9580(iVar21,iVar16,5,2,dVar29,0x83);
          }
        }
      }
      else {
        if (iVar16 <= iVar21) goto LAB_1400df1ff;
        local_res8 = 0x85;
      }
    }
    uVar41 = (undefined4)((ulonglong)dVar29 >> 0x20);
    iVar10 = 600;
    if ((599 < iVar17) || (param_1[5] == 2)) {
      iVar16 = 1;
      iVar21 = 0x550;
      if (iVar11 == 0) {
        iVar16 = 0xa4;
      }
      else if (iVar11 == 1) {
        iVar16 = 0x7b;
      }
      else if ((iVar11 == 2) || (iVar11 == 3)) {
        iVar16 = 0x52;
      }
      else if (iVar11 == 4) {
        iVar16 = 0x29;
      }
      uVar19 = 1;
      if (iVar11 == 0) {
        uVar19 = 0x78;
      }
      else if (iVar11 == 1) {
        uVar19 = 100;
      }
      else if ((iVar11 == 2) || (iVar11 == 3)) {
        uVar19 = 0x50;
      }
      else if (iVar11 == 4) {
        uVar19 = 0x28;
      }
      iVar22 = 1;
      if (iVar11 == 0) {
        iVar22 = 0xb;
      }
      else if (iVar11 == 1) {
        iVar22 = 6;
      }
      else if ((iVar11 == 2) || (iVar11 == 3)) {
        iVar22 = 4;
      }
      else if (iVar11 == 4) {
        iVar22 = 3;
      }
      dVar26 = dVar25;
      if ((((iVar11 != 0) && (dVar26 = DAT_14053a088, iVar11 != 1)) &&
          (dVar26 = dVar27, iVar11 != 2)) &&
         ((dVar26 = dVar25, iVar11 != 3 && (dVar26 = dVar7, iVar11 == 4)))) {
        dVar26 = DAT_14053a0f8;
      }
      dVar25 = ((double)iVar17 - DAT_14053a7c8) * _DAT_140539d80 + dVar26;
      local_res18 = iVar17 + -600;
      if (param_1[5] == 2) {
        iVar10 = 0;
        iVar21 = 0;
        dVar25 = DAT_14053a0d0;
        local_res18 = iVar17;
        if (((iVar11 != 0) && (dVar25 = DAT_14053a0f8, iVar11 != 1)) &&
           ((iVar11 == 2 || ((dVar25 = DAT_14053a0d0, iVar11 != 3 && (dVar25 = dVar7, iVar11 == 4)))
            ))) {
          dVar25 = DAT_14053a118;
        }
      }
      local_res18 = local_res18 % iVar16;
      if (iVar10 <= iVar17) {
        if (((iVar17 < iVar21) || (iVar21 == 0)) && ((iVar17 - iVar10) % iVar16 == 0)) {
          dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                         (double)(DAT_140e445d8 - (float)param_1[10]));
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar27 * DAT_14053aba0);
        }
        else if (iVar17 < iVar10) goto LAB_1400df709;
        uVar41 = (undefined4)((ulonglong)dVar29 >> 0x20);
        if ((iVar17 < iVar21) || (iVar21 == 0)) {
          uVar5 = (longlong)(iVar17 - iVar10) % (longlong)iVar16;
          iVar10 = (int)uVar5;
          if ((iVar10 < (int)uVar19) &&
             ((int)((longlong)((ulonglong)(uint)(iVar10 >> 0x1f) << 0x20 | uVar5 & 0xffffffff) %
                   (longlong)iVar22) == 0)) {
            sVar4 = *(short *)((longlong)param_1 + 0x42);
            sVar15 = (short)(0x8000 / (ulonglong)uVar19) * (short)local_res18 + -0x4000;
            dVar27 = (double)FUN_1403307c0((short)local_res18,0x8000 % (ulonglong)uVar19);
            dVar28 = DAT_14053a380;
            uVar34 = (undefined4)((ulonglong)uVar39 >> 0x20);
            fVar33 = (float)(dVar27 * DAT_14053a380) + (float)param_1[10];
            dVar27 = (double)FUN_140332d90();
            fVar32 = (float)(dVar27 * dVar28) + (float)param_1[0xb];
            dVar27 = (double)FUN_1403307c0();
            fVar37 = (float)(dVar27 * dVar28) + (float)param_1[10];
            dVar27 = (double)FUN_140332d90();
            fVar30 = (float)(dVar27 * dVar28) + (float)param_1[0xb];
            uVar39 = CONCAT62((int6)((ulonglong)dVar29 >> 0x10),sVar4 + sVar15 + -2000);
            FUN_14006c2f0(0xd,2,fVar33,fVar32,uVar39,0,dVar25,CONCAT44(uVar34,1),0);
            uVar39 = CONCAT62((int6)((ulonglong)uVar39 >> 0x10),
                              (*(short *)((longlong)param_1 + 0x42) - sVar15) + 2000);
            FUN_14006c2f0(0xd,2,fVar37,fVar30,uVar39,0,dVar25,1,0);
            uVar40 = CONCAT62((int6)((ulonglong)uVar39 >> 0x10),
                              sVar15 + *(short *)((longlong)param_1 + 0x42) + -0x8000);
            FUN_14006c2f0(0xd,2,fVar33,fVar32,uVar40,0,dVar25,1,0);
            uVar43 = 0;
            uVar39 = 1;
            uVar40 = CONCAT62((int6)((ulonglong)uVar40 >> 0x10),
                              (*(short *)((longlong)param_1 + 0x42) - sVar15) + -0x8000);
            dVar28 = dVar25;
            FUN_14006c2f0(0xd,2,fVar37,fVar30,uVar40,0,dVar25,1,0);
            uVar41 = (undefined4)((ulonglong)uVar40 >> 0x20);
            if (2 < DAT_140e419b8) {
              dVar28 = dVar25 + DAT_140539f90;
              uVar40 = CONCAT62((int6)((ulonglong)uVar40 >> 0x10),
                                sVar15 + *(short *)((longlong)param_1 + 0x42) + -0xafa);
              FUN_14006c2f0(0xd,2,fVar33,fVar32,uVar40,0,dVar28,1,0);
              uVar43 = 0;
              uVar39 = 1;
              uVar40 = CONCAT62((int6)((ulonglong)uVar40 >> 0x10),
                                (*(short *)((longlong)param_1 + 0x42) - sVar15) + 0xafa);
              FUN_14006c2f0(0xd,2,fVar37,fVar30,uVar40,0,dVar28,1,0);
              uVar41 = (undefined4)((ulonglong)uVar40 >> 0x20);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            uVar36 = SUB84(DAT_140539d28,0);
            uVar38 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
            uVar34 = SUB84(DAT_14053a5f8,0);
            uVar35 = (undefined4)((ulonglong)DAT_14053a5f8 >> 0x20);
          }
        }
      }
    }
LAB_1400df709:
    puVar13 = DAT_140e46c88;
    if (param_1[5] == 2) {
      local_res8 = 0x85;
    }
    else if ((param_1[5] == 1) && ((int)param_1[0x17] < 1)) {
      param_1[5] = 2;
      puVar13 = DAT_140e46c88;
    }
  }
  else {
    local_res8 = iVar17;
    puVar13 = DAT_140e46c88;
    if (iVar16 == 3) {
      iVar9 = param_1[3];
      piVar1 = param_1 + 3;
      if (0x3b < iVar9) {
        iVar10 = 0xff;
      }
      if (0x3b < iVar9) {
        if (iVar9 < 0x46) {
          dVar25 = ((double)iVar9 - DAT_14053a3a0) * DAT_14053a9d8;
        }
        else {
          if (0x77 < iVar9) goto LAB_1400ded64;
          dVar25 = ((double)iVar9 - DAT_14053a278) * DAT_14053a670;
        }
        dVar25 = (double)FUN_140332d90(dVar25 * dVar6 * dVar27);
        iVar10 = (int)(dVar25 * dVar26);
      }
LAB_1400ded64:
      uVar40 = CONCAT44(uVar41,0x62);
      iVar17 = 0;
      if (iVar9 < 0x78) {
        iVar17 = iVar10;
      }
      iVar9 = FUN_1400c9580(iVar9,0,5,2,uVar40,99,dVar28,uVar39,uVar43,uVar44,uVar45,uVar46,uVar47,
                            uVar48,uVar49,uVar50,uVar51,uVar52,uVar53,uVar54);
      dVar28 = 6.57107308968858e-322;
      uVar40 = CONCAT44((int)((ulonglong)uVar40 >> 0x20),0x83);
      local_res8 = FUN_1400c9580(*piVar1,0,3,3,uVar40,0x84,0x85);
      uVar41 = (undefined4)((ulonglong)uVar40 >> 0x20);
      iVar10 = *piVar1;
      if (iVar10 < 0x3c) {
        FUN_14007ac00(param_1);
        iVar10 = *piVar1;
        param_1[0xb] = (float)iVar10 * DAT_140539ce4 + (float)param_1[0xb];
      }
      puVar12 = DAT_140e45d28;
      if (iVar10 == 0x3c) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar2 = param_1[0xb];
        uVar3 = param_1[10];
        puVar12 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar12 = (undefined8 *)_malloc_base(0x60);
          if (puVar12 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar12 + 0x14) = uVar3;
          *(undefined4 *)(puVar12 + 3) = uVar2;
          *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar3;
          *(undefined4 *)(puVar12 + 4) = uVar2;
          *puVar12 = 1;
          puVar12[1] = 0x11;
          *(undefined4 *)(puVar12 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
          puVar12[5] = 0;
          puVar12[6] = 0x3ff0000000000000;
          puVar12[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar12 + 8) = 0;
          *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
          *(undefined4 *)(puVar12 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
          puVar12[10] = 0xff;
          puVar12[0xb] = 0;
          if (bVar23) {
            DAT_140e45d78 = puVar12;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar12;
          }
        }
      }
      DAT_140e45d28 = puVar12;
      if (param_1[3] == 0x78) {
        DAT_140e418cc = 0;
        *param_1 = 0;
      }
      uVar2 = DAT_140e41ab8;
      puVar13 = (undefined4 *)_malloc_base(0x48);
      if (puVar13 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
      bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar13 = uVar2;
      puVar13[1] = 0x4e;
      *(undefined8 *)(puVar13 + 2) = 5;
      puVar13[4] = 0;
      *(undefined2 *)(puVar13 + 5) = 0;
      *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
      puVar13[10] = 0xff;
      puVar13[0xb] = 0xff;
      puVar13[0xc] = 0xff;
      puVar13[0xd] = iVar17;
      *(undefined8 *)(puVar13 + 0xe) = 1;
      *(undefined8 *)(puVar13 + 0x10) = 0;
      if (bVar23) {
        DAT_140e46bf0 = puVar13;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
      }
    }
  }
  DAT_140e46c88 = puVar13;
  if ((param_1[5] == 3) && (0x45 < (int)param_1[3])) goto LAB_1400e0589;
  uVar19 = 0;
  uVar40 = CONCAT44(uVar41,0x62);
  iVar10 = FUN_1400c9580(DAT_140e418c8,0,3,2,uVar40,99,dVar28,uVar39,uVar43,uVar44,uVar45,uVar46,
                         uVar47,uVar48,uVar49,uVar50,uVar51,uVar52,uVar53,uVar54);
  fVar37 = DAT_14053ae14;
  fVar32 = DAT_14053ad80;
  pfVar18 = (float *)(param_1 + 0xb);
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar40 >> 0x20),(float)param_1[0xb] + DAT_14053ae14);
  FUN_1400c8410((&DAT_140e44660)[iVar10],0x19,7,(float)param_1[10] + DAT_14053ad80,uVar39,uVar19,
                dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  fVar33 = DAT_14053ad10;
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),*pfVar18 + fVar37);
  FUN_1400c8410((&DAT_140e44660)[iVar10],0x19,7,(float)param_1[10] + DAT_14053ad10,uVar39,uVar19,
                dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),*pfVar18 + fVar37);
  FUN_1400c8410((&DAT_140e44660)[iVar10],0x19,7,(float)param_1[10] - fVar32,uVar39,uVar19,dVar7,
                uVar8,0xff,0xff,0xff,0xff,1,0);
  iVar17 = 0xff;
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),*pfVar18 + fVar37);
  FUN_1400c8410((&DAT_140e44660)[iVar10],0x19,7,(float)param_1[10] - fVar33,uVar39,uVar19,dVar7,
                uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar43 = DAT_140e41960;
  uVar44 = (undefined4)((ulonglong)uVar39 >> 0x20);
  fVar30 = *pfVar18;
  fVar31 = ((float)param_1[10] + fVar32) - DAT_140e45d24;
  iVar10 = DAT_140e45d1c;
  puVar12 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar12 = (undefined8 *)_malloc_base(0x60);
    if (puVar12 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar10 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar12 + 0x14) = fVar31;
    bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar12 + 3) = fVar30 + fVar37;
    *(float *)((longlong)puVar12 + 0x1c) = fVar31;
    *(float *)(puVar12 + 4) = fVar30 + fVar37;
    *puVar12 = 1;
    *(undefined4 *)(puVar12 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar12 + 0xc) = uVar43;
    *(undefined4 *)(puVar12 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
    puVar12[5] = 0;
    puVar12[6] = 0x3ffe666666666666;
    puVar12[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar12 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
    *(undefined4 *)(puVar12 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
    puVar12[10] = 0x40;
    puVar12[0xb] = 0;
    if (bVar23) {
      DAT_140e45d78 = puVar12;
    }
    DAT_140e45d1c = iVar10;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar12;
    }
  }
  DAT_140e45d28 = puVar12;
  uVar43 = DAT_140e41960;
  fVar30 = (float)param_1[0xb];
  fVar31 = ((float)param_1[10] + fVar33) - DAT_140e45d24;
  puVar12 = DAT_140e45d28;
  if (iVar10 < 0x1000) {
    puVar12 = (undefined8 *)_malloc_base(0x60);
    if (puVar12 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar10 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar12 + 0x14) = fVar31;
    bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar12 + 3) = fVar30 + fVar37;
    *(float *)((longlong)puVar12 + 0x1c) = fVar31;
    *(float *)(puVar12 + 4) = fVar30 + fVar37;
    *puVar12 = 1;
    *(undefined4 *)(puVar12 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar12 + 0xc) = uVar43;
    *(undefined4 *)(puVar12 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
    puVar12[5] = 0;
    puVar12[6] = 0x3ffe666666666666;
    puVar12[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar12 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
    *(undefined4 *)(puVar12 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
    puVar12[10] = 0x40;
    puVar12[0xb] = 0;
    if (bVar23) {
      DAT_140e45d78 = puVar12;
    }
    DAT_140e45d1c = iVar10;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar12;
    }
  }
  DAT_140e45d28 = puVar12;
  uVar43 = DAT_140e41960;
  fVar30 = (float)param_1[0xb];
  fVar32 = ((float)param_1[10] - fVar32) - DAT_140e45d24;
  puVar12 = DAT_140e45d28;
  if (iVar10 < 0x1000) {
    puVar12 = (undefined8 *)_malloc_base(0x60);
    if (puVar12 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(float *)((longlong)puVar12 + 0x14) = fVar32;
    puVar12[6] = 0x3ffe666666666666;
    puVar12[7] = 0x3ffe666666666666;
    iVar10 = DAT_140e45d1c + 1;
    *(float *)(puVar12 + 3) = fVar30 + fVar37;
    bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar12 + 0x1c) = fVar32;
    *(float *)(puVar12 + 4) = fVar30 + fVar37;
    *puVar12 = 1;
    *(undefined4 *)(puVar12 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar12 + 0xc) = uVar43;
    *(undefined4 *)(puVar12 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
    puVar12[5] = 0;
    *(undefined4 *)(puVar12 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
    *(undefined4 *)(puVar12 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
    puVar12[10] = 0x40;
    puVar12[0xb] = 0;
    if (bVar23) {
      DAT_140e45d78 = puVar12;
    }
    DAT_140e45d1c = iVar10;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar12;
    }
  }
  DAT_140e45d28 = puVar12;
  uVar43 = DAT_140e41960;
  fVar30 = (float)param_1[0xb];
  fVar33 = ((float)param_1[10] - fVar33) - DAT_140e45d24;
  puVar12 = DAT_140e45d28;
  if (iVar10 < 0x1000) {
    puVar12 = (undefined8 *)_malloc_base(0x60);
    if (puVar12 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar12 + 0x14) = fVar33;
    *(float *)(puVar12 + 3) = fVar30 + fVar37;
    *(float *)((longlong)puVar12 + 0x1c) = fVar33;
    *(float *)(puVar12 + 4) = fVar30 + fVar37;
    *puVar12 = 1;
    *(undefined4 *)(puVar12 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar12 + 0xc) = uVar43;
    *(undefined4 *)(puVar12 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
    puVar12[5] = 0;
    puVar12[6] = 0x3ffe666666666666;
    puVar12[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar12 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
    *(undefined4 *)(puVar12 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
    puVar12[10] = 0x40;
    puVar12[0xb] = 0;
    if (bVar23) {
      DAT_140e45d78 = puVar12;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar12;
    }
  }
  DAT_140e45d28 = puVar12;
  fVar30 = DAT_14053ad5c;
  pfVar18 = (float *)(param_1 + 0xb);
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44(uVar44,*pfVar18 + DAT_14053ad5c);
  FUN_1400c8410(DAT_140e449c4,0x19,7,param_1[10],uVar39,uVar19,dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar43 = (undefined4)((ulonglong)uVar39 >> 0x20);
  uVar20 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
  DAT_140e9fd10 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  uVar20 = uVar20 * 0x800 ^ uVar20;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar20) >> 8 ^ uVar20 ^ DAT_140e9fd18;
  if (DAT_140e9fd1c % 5 != 0) {
    uVar19 = uVar19 & 0xffff0000;
    uVar39 = CONCAT44(uVar43,*pfVar18 + fVar30);
    FUN_1400c8410(DAT_140e449cc,0x19,7,param_1[10],uVar39,uVar19,dVar7,uVar8,0xff,0xff,0xff,0xff,1,0
                 );
    uVar43 = (undefined4)((ulonglong)uVar39 >> 0x20);
  }
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44(uVar43,*pfVar18 + fVar30);
  FUN_1400c8410(DAT_140e449bc,0x19,7,param_1[10],uVar39,uVar19,dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),*pfVar18 + DAT_14053ad84);
  FUN_1400c8410(DAT_140e449d0,0x17,7,param_1[10],uVar39,uVar19,dVar7,uVar8,0,0,0x20,0x40,1,0);
  dVar29 = DAT_14053a890;
  dVar25 = DAT_14053a1e8;
  uVar43 = (undefined4)((ulonglong)uVar39 >> 0x20);
  iVar10 = 0xff;
  if (param_1[5] == 3) {
    iVar16 = param_1[3];
    iVar10 = 0xff;
    if (iVar16 - 0x1eU < 0x14) {
      dVar28 = (double)FUN_140332d90(((double)iVar16 - DAT_14053a1e8) * DAT_14053a890 * dVar6 *
                                     (double)CONCAT44(uVar38,uVar36));
      iVar10 = (int)(dVar28 * (double)CONCAT44(uVar35,uVar34));
    }
    iVar17 = 0;
    if (iVar16 < 0x32) {
      iVar17 = iVar10;
    }
    iVar11 = (iVar16 >> 0x1f & 0xffffff01U) + 0xff;
    if (-1 < iVar16) {
      if (iVar16 < 0x1e) {
        dVar29 = ((double)iVar16 - 0.0) * DAT_14053a798;
      }
      else {
        if (0x31 < iVar16) goto LAB_1400e02de;
        dVar29 = ((double)iVar16 - dVar25) * dVar29;
      }
      dVar25 = (double)FUN_140332d90(dVar29 * dVar6 * (double)CONCAT44(uVar38,uVar36));
      iVar11 = (int)(dVar25 * (double)CONCAT44(uVar35,uVar34));
    }
LAB_1400e02de:
    iVar10 = 0;
    if (iVar16 < 0x32) {
      iVar10 = iVar11;
    }
  }
  fVar33 = DAT_14053ad40;
  pfVar18 = (float *)(param_1 + 0xb);
  lVar14 = (longlong)iVar9;
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44(uVar43,*pfVar18 + DAT_14053ad40);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar14 * 4),0x19,0x18,param_1[10],uVar39,uVar19,
                dVar7,uVar8,0x40,0x40,0,
                iVar17 / 6 + (iVar17 >> 0x1f) +
                (int)(((longlong)iVar17 / 6 + ((longlong)iVar17 >> 0x3f) & 0xffffffffU) >> 0x1f),1,0
               );
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44((int)((ulonglong)uVar39 >> 0x20),*pfVar18 + fVar33);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar14 * 4),0x19,7,param_1[10],uVar39,uVar19,dVar7,
                uVar8,0xff,0xff,0xff,iVar17,1,0);
  uVar34 = (undefined4)((ulonglong)uVar39 >> 0x20);
  if (param_1[5] == 3) {
    uVar19 = uVar19 & 0xffff0000;
    uVar39 = CONCAT44(uVar34,*pfVar18 + fVar33);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar14 * 4),0x19,8,param_1[10],uVar39,uVar19,
                  dVar7,uVar8,0xff,0xff,0xff,iVar10,1,0);
    uVar34 = (undefined4)((ulonglong)uVar39 >> 0x20);
  }
  dVar25 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a880 * dVar6 *
                                 (double)CONCAT44(uVar38,uVar36));
  uVar19 = uVar19 & 0xffff0000;
  uVar39 = CONCAT44(uVar34,*pfVar18);
  FUN_1400c8410(DAT_140e44cd8,0x1a,7,param_1[10],uVar39,uVar19,dVar25 * _DAT_140539e28 + dVar7,dVar7
                ,0xff,0xff,0xff,0xff,1,0);
  uVar34 = (undefined4)((ulonglong)uVar39 >> 0x20);
  dVar25 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a880 * dVar6 *
                                 (double)CONCAT44(uVar38,uVar36));
  uVar19 = uVar19 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44ad0)[local_res8],0x1a,7,param_1[10],CONCAT44(uVar34,*pfVar18),uVar19,
                dVar25 * _DAT_140539e28 + dVar7,dVar7,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e449c0,0x1d,7,param_1[10],*pfVar18 + fVar30,uVar19 & 0xffff0000,dVar7,uVar8,
                0xff,0xff,0xff,0xff,1,0);
LAB_1400e0589:
  if ((param_1[0x15] == 0) && ((int)param_1[3] % 0x12 == 1)) {
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472f4);
    FUN_14018a340(DAT_140e472f4,1,1);
  }
  FUN_140002260();
  return;
}


