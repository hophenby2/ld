// Function: FUN_140038190 @ 140038190
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140038190(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  ushort uVar13;
  ushort uVar14;
  ushort uVar15;
  uint uVar16;
  undefined8 uVar17;
  uint uVar18;
  short sVar19;
  int *piVar20;
  int iVar21;
  undefined8 uVar22;
  uint uVar23;
  ushort uVar24;
  uint uVar25;
  bool bVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  undefined4 uVar37;
  undefined4 local_res8;
  int local_res10;
  int local_res18;
  int local_res20;
  double in_stack_fffffffffffffeb8;
  undefined4 uVar41;
  ulonglong uVar38;
  undefined6 uVar40;
  undefined8 uVar39;
  uint in_stack_fffffffffffffec0;
  undefined2 uVar42;
  undefined8 in_stack_fffffffffffffec8;
  undefined8 in_stack_fffffffffffffed0;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  int local_f8;
  
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  fVar34 = (float)param_1[10];
  fVar36 = (float)param_1[0xb];
  dVar27 = (double)FUN_1403300b4((double)(DAT_140e4490c - fVar36),(double)(DAT_140e44908 - fVar34));
  fVar33 = DAT_140e445dc;
  fVar1 = DAT_140e445d8;
  dVar32 = DAT_14053aba0;
  fVar36 = fVar36 - _DAT_14053ad60;
  uVar18 = (uint)(dVar27 * DAT_14053aba0);
  dVar28 = (double)FUN_1403300b4();
  dVar29 = (double)FUN_1403300b4();
  dVar27 = (double)FUN_1403300b4((double)(fVar33 - fVar36),(double)(fVar1 - fVar34));
  dVar31 = DAT_14053a4f0;
  uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
  uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  iVar11 = 100;
  iVar5 = 100;
  uVar25 = (uint)(dVar27 * dVar32);
  dVar27 = DAT_14053a070;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    uVar45 = 0;
    uVar43 = 1;
    in_stack_fffffffffffffed0 = CONCAT44(uVar46,param_1[0x14]);
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffff0000;
    in_stack_fffffffffffffeb8 =
         (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20),param_1[0xb]);
    dVar30 = dVar31;
    stage_entity_spawn_candidate(0x137,99999999,0);
    uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
    switch(DAT_140e41af8) {
    case 1:
      if ((int)param_1[5] < 0x3c) {
        DAT_140e44e68 = FUN_1400c7d40();
        uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
        if (DAT_140e44e68 == 0) {
          param_1[5] = 0x3c;
        }
        else if (DAT_140e44e68 == 1) {
          param_1[5] = 99;
          puVar7 = &DAT_140e45100;
          do {
            FUN_14018f230(*puVar7,0);
            uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
            puVar7 = puVar7 + 1;
          } while ((longlong)puVar7 < 0x140e45178);
          goto LAB_1400385bb;
        }
      }
      else {
        puVar7 = &DAT_140e45100;
        do {
          FUN_14018f230(*puVar7,0);
          uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
          puVar7 = puVar7 + 1;
        } while ((longlong)puVar7 < 0x140e45178);
        param_1[5] = 0x46;
LAB_1400385bb:
        _DAT_1407c777c = 0;
      }
      DAT_140e419bc = -1;
      break;
    case 2:
      param_1[5] = 0x32;
      DAT_140e419bc = 2;
      break;
    case 3:
      param_1[5] = 0x28;
      DAT_140e419bc = 2;
      break;
    case 4:
      param_1[5] = 0x1e;
      DAT_140e419bc = 2;
      break;
    case 5:
      bVar26 = DAT_140e41928 != 1;
      param_1[0x14] = 0xa0;
      param_1[5] = 0x14;
      dVar27 = DAT_14053a070;
      DAT_140e419bc = 2;
      if ((bVar26) || (DAT_140e41abc != 1)) break;
      uVar16 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar16 = uVar16 * 0x800 ^ uVar16;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar16) >> 8 ^ uVar16 ^ DAT_140e9fd18;
      in_stack_fffffffffffffeb8 = DAT_14053a070;
      uVar46 = DAT_14053ac80;
      FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,DAT_140e9fd10,
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                    DAT_14053a070,DAT_14053ac80,dVar30,in_stack_fffffffffffffed0,uVar43,uVar45);
      uVar43 = (undefined4)((ulonglong)dVar30 >> 0x20);
      uVar42 = (undefined2)((uint)uVar46 >> 0x10);
      goto switchD_1400383ac_default;
    case 6:
      puVar7 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar7,0);
        uVar42 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
        puVar7 = puVar7 + 1;
      } while ((longlong)puVar7 < 0x140e45178);
      param_1[0x14] = 0xa0;
      param_1[5] = 10;
      _DAT_1407c777c = 0;
      DAT_140e419bc = 2;
    }
    uVar43 = (undefined4)((ulonglong)dVar30 >> 0x20);
    dVar27 = DAT_14053a070;
switchD_1400383ac_default:
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar2 = DAT_14053a020;
  dVar30 = DAT_140539d28;
  uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  uVar16 = DAT_140e418c8;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar16 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar8 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
    uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
    uVar16 = uVar16 * 0x800 ^ uVar16;
    uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 4;
    DAT_140e44908 = (float)(((uVar8 >> 0xb ^ uVar16) >> 8 ^ uVar8 ^ uVar16) % 0x12d + 0xd2);
    uVar16 = DAT_1407c7798 * 0xde + DAT_140e418c8;
    uVar23 = DAT_140e418c8 + DAT_1407c7798 * 0xde;
    uVar16 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar8 = uVar16 * 0x800 ^ uVar16;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
    iVar9 = param_1[5];
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
    if (iVar9 == 0xb) {
      uVar8 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 1;
      uVar23 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 3;
      uVar8 = uVar8 * 0x800 ^ uVar8;
      uVar23 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (uVar23 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ uVar23;
      iVar9 = DAT_140e9fd1c % 0x65 + 0xb4;
    }
    else {
      if ((iVar9 < 0x33) || (0x3b < iVar9)) {
        if ((0x3c < iVar9) && (iVar9 < 0x46)) {
          uVar16 = DAT_1407c7798 * 0xde + DAT_140e418c8;
          uVar16 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar16 * 0x800 ^ uVar16;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
          DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 200);
        }
        goto LAB_140038801;
      }
      uVar8 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 1;
      uVar23 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 3;
      uVar8 = uVar8 * 0x800 ^ uVar8;
      uVar23 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (uVar23 >> 0xb ^ uVar8) >> 8 ^ uVar23 ^ uVar8;
      iVar9 = DAT_140e9fd1c % 0x65 + 0x82;
    }
    DAT_140e4490c = (float)iVar9;
  }
LAB_140038801:
  uVar45 = SUB84(DAT_14053a020,0);
  uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar24 = (ushort)uVar25;
  uVar3 = (undefined2)(int)(dVar28 * dVar32);
  switch(param_1[5]) {
  case 0:
    dVar31 = DAT_14053a020;
    dVar27 = DAT_140539d28;
    if (param_1[3] == 0) {
      uVar17 = CONCAT44(uVar46,0x28);
      uVar43 = CONCAT22(uVar42,0xc000);
      uVar22 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20),DAT_14053b360);
      param_1[0xf] = 0x43700000;
      stage_entity_spawn_candidate(0xa8,99999999,0,uVar16,uVar22,uVar43,0,uVar17,1,0);
      uVar46 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar42 = (undefined2)((uint)uVar43 >> 0x10);
      uVar45 = (undefined4)((ulonglong)uVar22 >> 0x20);
      stage_entity_spawn_candidate(0xa8,99999999,0);
      stage_entity_spawn_candidate(0xa7,99999999,0);
      uVar43 = DAT_14053b378;
      stage_entity_spawn_candidate(0xa7,99999999,0);
      stage_entity_spawn_candidate(0xab,4000,0x18);
      stage_entity_spawn_candidate(0xab,4000,0x18);
      stage_entity_spawn_candidate(0xab,4000,0x18);
      stage_entity_spawn_candidate(0xab,4000,0x18);
      DAT_1407c77a0 = DAT_1407c779c;
      stage_entity_spawn_candidate(0xac,25000,0x78);
      in_stack_fffffffffffffeb8 = (double)CONCAT44(uVar45,uVar43);
      stage_entity_spawn_candidate(0xac,25000,0x78);
      dVar31 = DAT_14053a020;
      dVar27 = DAT_140539d28;
      param_1[0x17] = 2;
    }
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    uVar18 = param_1[3];
    iVar5 = ((int)uVar18 >> 0x1f & 0xfffffb5aU) + 0xbe;
    if ((-1 < (int)uVar18) && ((int)uVar18 < 0x4b0)) {
      dVar27 = (double)FUN_140332d90(((double)(int)uVar18 - 0.0) * _DAT_14053a230 * dVar31 * dVar27)
      ;
      iVar5 = -1000 - (int)(dVar27 * _DAT_14053b2a8);
    }
    uVar25 = uVar18 - 0x1e;
    param_1[0xd] = (float)iVar5;
    if (((uVar25 < 0x14a) && (uVar25 == ((int)uVar25 / 0xc) * 0xc)) ||
       ((uVar25 = uVar18 - 0x1cc, uVar25 < 200 && (uVar25 == ((int)uVar25 / 0x18) * 0x18)))) {
LAB_140038d73:
      uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar18 = uVar18 * 0x800 ^ uVar18;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ DAT_140e9fd18 ^ uVar18;
      stage_entity_spawn_candidate
                (0xad,300,5,(float)(int)(DAT_140e9fd1c % 0x259 - 300) + DAT_14053ae30,
                 CONCAT44(uVar43,DAT_14053b320),CONCAT22(uVar42,0x4000),
                 CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),CONCAT44(uVar46,0x28),1,0);
    }
    else if (uVar18 - 0x2d0 < 0xb4) {
      uVar25 = uVar18 - 0x2d0 & 0x80000007;
      if ((int)uVar25 < 0) {
        uVar25 = (uVar25 - 1 | 0xfffffff8) + 1;
      }
      if (uVar25 == 0) goto LAB_140038d73;
    }
    fVar34 = DAT_14053ac2c;
    uVar37 = DAT_140539f40._4_4_;
    uVar47 = (undefined4)DAT_140539f40;
    dVar27 = DAT_140539d28;
    uVar45 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    puVar7 = DAT_140e46c88;
    if (param_1[3] == 0x4b0) {
      param_1[0x15] = 0;
      param_1[3] = 0;
      param_1[7] = 0x23668;
      param_1[5] = param_1[5] + 1;
      DAT_140e41b0c = 0x23668;
      DAT_140e4430c = 0xce4;
      DAT_140e4192c = 0;
      DAT_140e419bc = 1;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 1:
    iVar5 = (param_1[3] + -0x1e) % 0x708;
    if (iVar5 < 0x280) {
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x78;
      }
      else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
              (DAT_140e419b8 == 4)) {
        iVar11 = 0x50;
      }
      uVar43 = 1;
      if (DAT_140e419b8 == 0) {
        uVar43 = 5;
      }
      else if (DAT_140e419b8 == 1) {
LAB_140038f76:
        uVar43 = 7;
      }
      else {
        if (DAT_140e419b8 != 2) {
          if (DAT_140e419b8 == 3) goto LAB_140038f76;
          if (DAT_140e419b8 != 4) goto LAB_140038f82;
        }
        uVar43 = 9;
      }
LAB_140038f82:
      if (((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a088, DAT_140e419b8 != 1)) &&
         ((dVar27 = DAT_14053a0b0, DAT_140e419b8 != 2 &&
          ((dVar27 = DAT_14053a088, DAT_140e419b8 != 3 &&
           (dVar27 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),
           DAT_140e419b8 == 4)))))) {
        dVar27 = DAT_14053a0d0;
      }
      if ((iVar5 - 0x1eU < 0x276) &&
         (uVar38 = (longlong)(int)(iVar5 - 0x1eU) % (longlong)iVar11, (int)uVar38 == 0)) {
        uVar22 = CONCAT44(uVar46,1);
        FUN_1400709b0(0xc,uVar38 & 0xffffffff,DAT_140e419b8,uVar16,uVar3,0,
                      (double)iVar5 * DAT_140539d90 + dVar27,uVar22,uVar43,16000,0);
        uVar46 = (undefined4)((ulonglong)uVar22 >> 0x20);
        FUN_1400709b0(0xc,0);
        if (2 < DAT_140e419b8) {
          FUN_1400709b0(0xc,0);
          FUN_1400709b0(0xc,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      if ((iVar5 - 0x32U < 0x24e) && ((int)(iVar5 - 0x32U) % iVar11 == 0)) {
        FUN_1400709b0(0xc,0);
        FUN_1400709b0(0xc,0);
        if (2 < DAT_140e419b8) {
          FUN_1400709b0(0xc,0);
          FUN_1400709b0(0xc,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    iVar11 = DAT_140e419b8;
    if (iVar5 - 0x2e4U < 0xdc) {
      iVar9 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar9 = 0x2f8;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar9 = 0x2e4;
      }
      iVar4 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar4 = 0x96;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar4 = 100;
      }
      dVar27 = DAT_14053a138;
      if ((((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a178, DAT_140e419b8 != 1)) &&
          (DAT_140e419b8 != 2)) &&
         ((dVar27 = DAT_14053a1b8, DAT_140e419b8 != 3 &&
          (dVar27 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),
          DAT_140e419b8 == 4)))) {
        dVar27 = DAT_14053a200;
      }
      if (iVar9 <= iVar5) {
        if ((iVar5 < 0x3d4) && ((iVar5 - iVar9) % iVar4 == 0)) {
          *(undefined2 *)((longlong)param_1 + 0x42) = uVar3;
          *(short *)(param_1 + 0x11) = (short)(int)(dVar29 * dVar32);
          uVar18 = (iVar5 - iVar9) % iVar4;
        }
        else if ((iVar5 < iVar9) ||
                ((0x3d3 < iVar5 || (uVar18 = (iVar5 - iVar9) % iVar4, 0x1d < (int)uVar18))))
        goto LAB_14003955c;
        uVar18 = uVar18 & 0x80000003;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xfffffffc) + 1;
        }
        if (uVar18 == 0) {
          FUN_14006c2f0(9,0,iVar11,iVar4,*(undefined2 *)((longlong)param_1 + 0x42),DAT_14053ac2c,
                        dVar27,CONCAT44(uVar46,1),0);
          FUN_14006c2f0(9,0);
          if (0 < DAT_140e419b8) {
            FUN_1400709b0(9,0);
            FUN_1400709b0(9,0);
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar11 = DAT_140e419b8;
        }
      }
    }
LAB_14003955c:
    if (iVar5 - 1000U < 0x2f8) {
      iVar9 = 1;
      if ((((iVar11 == 0) || (iVar11 == 1)) || (iVar11 == 2)) || ((iVar11 == 3 || (iVar11 == 4)))) {
        iVar9 = 0x20;
      }
      iVar4 = 1;
      if (iVar11 == 0) {
        iVar4 = 0x14;
      }
      else if (iVar11 == 1) {
        iVar4 = 0x19;
      }
      else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
        iVar4 = 0x1e;
      }
      iVar9 = (iVar5 + -1000) % iVar9;
      if ((iVar9 < iVar4) && (iVar9 == (iVar9 / 5) * 5)) {
        FUN_1400709b0(9,0);
        FUN_1400709b0(9,0);
        if (2 < DAT_140e419b8) {
          FUN_1400709b0(9,0);
          FUN_1400709b0(9,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    if (param_1[0x17] == 0) {
      if ((int)param_1[7] < 0xc351) goto LAB_140039841;
    }
    else {
      fVar34 = DAT_14053ac2c;
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      puVar6 = DAT_140e45d28;
      if (50000 < (int)param_1[7]) goto LAB_14003989f;
LAB_140039841:
      FUN_140109660(0x18);
      FUN_140079e20(param_1,2);
    }
    param_1[5] = param_1[5] + 1;
    fVar34 = DAT_14053ac2c;
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    puVar6 = DAT_140e45d28;
    goto LAB_14003989f;
  case 2:
    iVar5 = 1;
    if (DAT_140e419b8 == 0) {
      iVar5 = 0xa0;
    }
    else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) ||
            ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
      iVar5 = 0x78;
    }
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0xd;
    }
    else if (DAT_140e419b8 == 1) {
      iVar11 = 0x11;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar11 = 0x13;
    }
    else if (DAT_140e419b8 == 4) {
      iVar11 = 0x15;
    }
    if ((-1 < (int)param_1[3]) && ((int)param_1[3] % (iVar5 * 2) == 0)) {
      iVar9 = 0;
      do {
        stage_entity_spawn_candidate(0xae,600,5);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar11);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if ((iVar5 <= (int)param_1[3]) && ((param_1[3] - iVar5) % (iVar5 * 2) == 0)) {
      iVar9 = 0;
      do {
        stage_entity_spawn_candidate(0xaf,600,5);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar11);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar11 = param_1[3];
    if ((((0x45 < iVar11) && ((iVar11 + -0x46) % (iVar5 * 2) == 0)) ||
        ((iVar5 + 0x5a <= iVar11 && ((iVar11 - (iVar5 + 0x5a)) % (iVar5 * 2) == 0)))) &&
       (FUN_1400709b0(2), 2 < DAT_140e419b8)) {
      FUN_1400709b0(2,0);
    }
    iVar11 = param_1[3];
    if ((((0x59 < iVar11) && ((iVar11 + -0x5a) % (iVar5 * 2) == 0)) ||
        ((fVar34 = DAT_14053ac2c, uVar47 = (undefined4)DAT_140539f40, uVar37 = DAT_140539f40._4_4_,
         puVar6 = DAT_140e45d28, iVar5 + 0x46 <= iVar11 &&
         ((iVar11 - (iVar5 + 0x46)) % (iVar5 * 2) == 0)))) &&
       (FUN_1400709b0(2), fVar34 = DAT_14053ac2c, uVar47 = (undefined4)DAT_140539f40,
       uVar37 = DAT_140539f40._4_4_, puVar6 = DAT_140e45d28, 2 < DAT_140e419b8)) {
      FUN_1400709b0(2,0);
      fVar34 = DAT_14053ac2c;
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      puVar6 = DAT_140e45d28;
    }
    goto LAB_14003989f;
  default:
    fVar34 = DAT_14053ac2c;
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    break;
  case 10:
    iVar5 = param_1[3];
    iVar11 = 0;
    if (iVar5 < 0x6e) {
LAB_140039fbd:
      iVar9 = 0;
      if (iVar5 < 200) {
        iVar9 = iVar11;
      }
      puVar6 = DAT_140e45d28;
      if (iVar5 == 1) {
        uVar43 = param_1[0xb];
        uVar46 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          puVar6[1] = 0x36;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
          *(undefined4 *)(puVar6 + 3) = uVar43;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
          *(undefined4 *)(puVar6 + 4) = uVar43;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
    }
    else {
      iVar11 = 0xff;
      if (iVar5 < 0x78) {
        dVar27 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a480) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar9 = (int)(dVar27 * DAT_14053a5f8);
        puVar6 = DAT_140e45d28;
      }
      else {
        if (199 < iVar5) goto LAB_140039fbd;
        dVar27 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a340) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar9 = 0;
        puVar6 = DAT_140e45d28;
        if (iVar5 < 200) {
          iVar9 = (int)(dVar27 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar6;
    iVar5 = param_1[3];
    if (iVar5 < 0x78) {
      FUN_14007ac00(param_1);
      iVar5 = param_1[3];
    }
    puVar6 = DAT_140e45d28;
    if (iVar5 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar43 = param_1[0xb];
      uVar46 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x11;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
        *(undefined4 *)(puVar6 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
        *(undefined4 *)(puVar6 + 4) = uVar43;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    uVar43 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x4e;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar9;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar43 = DAT_140e45144;
    fVar34 = DAT_14053ac2c;
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    puVar6 = DAT_140e45d28;
    DAT_140e46c88 = puVar7;
    if (param_1[3] == 200) {
      *(undefined8 *)(param_1 + 0x14) = 0x82;
      param_1[3] = 0;
      _DAT_1407c777c = 0x3f800000;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),uVar43);
      FUN_14018a340(DAT_140e45144,3,1);
      DAT_140e45100 = DAT_140e45144;
      if (param_1[5] == 10) {
        DAT_140e4430c = 0xa8c;
        DAT_140e41b0c = 0x19a28;
        DAT_140e4192c = 0;
      }
      DAT_1407c77a0 = DAT_1407c779c;
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
      fVar34 = DAT_14053ac2c;
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      puVar6 = DAT_140e45d28;
    }
    goto LAB_14003989f;
  case 0xb:
    uVar13 = *(ushort *)(param_1 + 0x10);
    uVar16 = (uint)uVar13;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar13;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar16 = (uint)(ushort)(uVar13 - 0x200), -0x200 < iVar11)) {
        uVar16 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar16 = uVar18 & 0xffff;
    }
    else {
      uVar16 = (uint)(ushort)(uVar13 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar16;
    dVar27 = (double)FUN_1403307c0((double)uVar16 * DAT_14053a020 * dVar30);
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90((double)uVar16 * DAT_14053a020 * DAT_140539d28);
    iVar5 = DAT_140e419b8;
    dVar31 = DAT_14053a0f8;
    dVar27 = DAT_14053a088;
    param_1[0xb] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar18 = (param_1[3] + -0x3c) % 0x640;
    if ((int)uVar18 < 0x140) {
      if (uVar18 == 0) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar24;
LAB_14003a2db:
        FUN_1400709b0(0xb,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
        uVar13 = *(ushort *)((longlong)param_1 + 0x42);
        iVar9 = (uVar25 & 0xffff) - (uint)uVar13;
        iVar11 = iVar9 + 0x10000;
        if (-0x8001 < iVar9) {
          iVar11 = iVar9;
        }
        iVar9 = iVar11 + -0x10000;
        if (iVar11 < 0x8001) {
          iVar9 = iVar11;
        }
        if (iVar9 < 1) {
          uVar15 = uVar13;
          if ((iVar9 < 0) && (uVar15 = uVar13 - 200, -200 < iVar9)) {
            uVar15 = uVar24;
          }
        }
        else {
          uVar15 = uVar24;
          if (199 < iVar9) {
            uVar15 = uVar13 + 200;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar15;
LAB_14003a3d0:
        if (uVar18 - 0x3c < 0x34) {
          uVar16 = uVar18 - 0x3c & 0x80000003;
          if ((int)uVar16 < 0) {
            uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
          }
          if (uVar16 == 0) goto LAB_14003a3f5;
        }
        if (uVar18 != 0x8c) goto LAB_14003a4f5;
        *(ushort *)((longlong)param_1 + 0x42) = uVar24;
LAB_14003a520:
        FUN_1400709b0(0xb,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
        uVar13 = *(ushort *)((longlong)param_1 + 0x42);
        iVar9 = (uVar25 & 0xffff) - (uint)uVar13;
        iVar11 = iVar9 + 0x10000;
        if (-0x8001 < iVar9) {
          iVar11 = iVar9;
        }
        iVar9 = iVar11 + -0x10000;
        if (iVar11 < 0x8001) {
          iVar9 = iVar11;
        }
        if (iVar9 < 1) {
          uVar15 = uVar13;
          if ((iVar9 < 0) && (uVar15 = uVar13 - 200, -200 < iVar9)) {
            uVar15 = uVar24;
          }
        }
        else {
          uVar15 = uVar24;
          if (199 < iVar9) {
            uVar15 = uVar13 + 200;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar15;
LAB_14003a62d:
        if (0xef < (int)uVar18) {
          uVar16 = uVar18 - 0xf0 & 0x80000003;
          if ((int)uVar16 < 0) {
            uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
          }
          if (uVar16 == 0) goto LAB_14003a64f;
        }
      }
      else {
        if (uVar18 < 0x20) {
          uVar16 = uVar18 & 0x80000003;
          if ((int)uVar16 < 0) {
            uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
          }
          if (uVar16 == 0) goto LAB_14003a2db;
        }
        if (uVar18 != 0x3c) goto LAB_14003a3d0;
        *(ushort *)((longlong)param_1 + 0x42) = uVar24;
LAB_14003a3f5:
        FUN_1400709b0(0xb,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
        uVar13 = *(ushort *)((longlong)param_1 + 0x42);
        iVar9 = (uVar25 & 0xffff) - (uint)uVar13;
        iVar11 = iVar9 + 0x10000;
        if (-0x8001 < iVar9) {
          iVar11 = iVar9;
        }
        iVar9 = iVar11 + -0x10000;
        if (iVar11 < 0x8001) {
          iVar9 = iVar11;
        }
        if (iVar9 < 1) {
          uVar15 = uVar13;
          if ((iVar9 < 0) && (uVar15 = uVar13 - 200, -200 < iVar9)) {
            uVar15 = uVar24;
          }
        }
        else {
          uVar15 = uVar24;
          if (199 < iVar9) {
            uVar15 = uVar13 + 200;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar15;
LAB_14003a4f5:
        if (uVar18 - 0x8c < 0x48) {
          uVar16 = uVar18 - 0x8c & 0x80000003;
          if ((int)uVar16 < 0) {
            uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
          }
          if (uVar16 == 0) goto LAB_14003a520;
        }
        if (uVar18 != 0xf0) goto LAB_14003a62d;
        *(ushort *)((longlong)param_1 + 0x42) = uVar24;
LAB_14003a64f:
        FUN_1400709b0(0xb,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
        uVar13 = *(ushort *)((longlong)param_1 + 0x42);
        iVar9 = (uVar25 & 0xffff) - (uint)uVar13;
        iVar11 = iVar9 + 0x10000;
        if (-0x8001 < iVar9) {
          iVar11 = iVar9;
        }
        iVar9 = iVar11 + -0x10000;
        if (iVar11 < 0x8001) {
          iVar9 = iVar11;
        }
        if (iVar9 < 1) {
          if ((iVar9 < 0) && (uVar13 = uVar13 - 200, -200 < iVar9)) {
            uVar13 = uVar24;
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar13;
        }
        else if (iVar9 < 200) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar24;
        }
        else {
          *(ushort *)((longlong)param_1 + 0x42) = uVar13 + 200;
        }
      }
      iVar11 = 1;
      if ((iVar5 == 0) || (iVar5 == 1)) {
LAB_14003a797:
        iVar11 = 0xe;
      }
      else if (iVar5 == 2) {
        iVar11 = 0xc;
      }
      else if ((iVar5 == 3) || (iVar5 == 4)) goto LAB_14003a797;
      iVar9 = 1;
      if (iVar5 == 0) {
        iVar9 = 4;
      }
      else if ((iVar5 == 1) || (iVar5 == 2)) {
        iVar9 = 5;
      }
      else if ((iVar5 == 3) || (iVar5 == 4)) {
        iVar9 = 7;
      }
      if ((uVar18 - 0x14 < 0x118) && ((int)(uVar18 - 0x14) % iVar11 < iVar9)) {
        FUN_140332d90(((double)(int)uVar18 - _DAT_140539cc0) * _DAT_14053a468 * DAT_14053a020 *
                      DAT_140539d28);
        FUN_1400709b0(8,0);
        FUN_1400709b0(8,0);
        if (2 < DAT_140e419b8) {
          FUN_1400709b0(8,0);
          FUN_1400709b0(8,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
      }
    }
    dVar32 = DAT_14053a0d0;
    if (uVar18 - 0x17c < 0x105) {
      iVar11 = 1;
      if (iVar5 == 0) {
        iVar11 = 0x5a;
      }
      else if (iVar5 == 1) {
LAB_14003aa5a:
        iVar11 = 0x3c;
      }
      else {
        if (iVar5 != 2) {
          if (iVar5 == 3) goto LAB_14003aa5a;
          if (iVar5 != 4) goto LAB_14003aa68;
        }
        iVar11 = 0x32;
      }
LAB_14003aa68:
      dVar28 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
      if (((int)uVar18 < 0x280) && ((int)(uVar18 - 0x17c) % iVar11 == 0)) {
        FUN_1400709b0(3);
        FUN_1400709b0(3);
        FUN_1400709b0(3);
        if (2 < DAT_140e419b8) {
          FUN_1400709b0(3,0);
          FUN_1400709b0(3,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar5 = DAT_140e419b8;
        goto LAB_14003ad1a;
      }
    }
    else {
LAB_14003ad1a:
      dVar28 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
    }
    uVar25 = uVar18 - 700;
    if (uVar25 < 0x105) {
      iVar11 = 1;
      if (iVar5 == 0) {
        iVar11 = 0xc;
      }
      else if (iVar5 == 1) {
        iVar11 = 8;
      }
      else if (iVar5 == 2) {
        iVar11 = 6;
      }
      else if (iVar5 == 3) {
        iVar11 = 5;
      }
      else if (iVar5 == 4) {
        iVar11 = 4;
      }
      iVar9 = (int)uVar25 / (iVar11 * 2);
      iVar4 = 1;
      if (iVar5 == 0) {
        iVar4 = 0x1900;
      }
      else if (iVar5 == 1) {
        iVar4 = 0x16a8;
      }
      else if (iVar5 == 2) {
        iVar4 = 0x1518;
      }
      else if (iVar5 == 3) {
        iVar4 = 5000;
      }
      else if (iVar5 == 4) {
        iVar4 = 0x1194;
      }
      iVar4 = iVar4 + (700 - uVar18) * 10;
      if (((iVar5 != 0) && (dVar27 = dVar32, iVar5 != 1)) &&
         ((iVar5 == 2 || ((iVar5 == 3 || (dVar27 = dVar28, iVar5 == 4)))))) {
        dVar27 = dVar31;
      }
      if (((int)uVar18 < 0x3c0) &&
         (uVar38 = (longlong)(int)uVar25 % (longlong)(iVar11 * 2), (int)uVar38 == 0)) {
        FUN_1400709b0(0xd,uVar38 & 0xffffffff,iVar4,uVar25,uVar3,DAT_14053ac2c,
                      ((double)(int)uVar18 - DAT_14053a840) * _DAT_140539e08 + dVar27,
                      CONCAT44(uVar46,1),iVar9 + 1,iVar9 * iVar4,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar5 = DAT_140e419b8;
      }
      fVar34 = DAT_14053ac2c;
      if ((iVar11 + 700 <= (int)uVar18) && ((int)uVar18 < 0x3c0)) {
        uVar47 = (undefined4)DAT_140539f40;
        uVar37 = DAT_140539f40._4_4_;
        puVar6 = DAT_140e45d28;
        if ((int)(uVar18 - (iVar11 + 700)) % (iVar11 * 2) == 0) {
          FUN_1400709b0(0xc);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          uVar47 = (undefined4)DAT_140539f40;
          uVar37 = DAT_140539f40._4_4_;
          puVar6 = DAT_140e45d28;
        }
        goto LAB_14003989f;
      }
    }
    fVar34 = DAT_14053ac2c;
    if (uVar18 == 0x3c0) {
      local_res20 = 1;
      if ((iVar5 == 0) || (iVar5 == 1)) {
        local_res20 = 5;
      }
      else if (((iVar5 == 2) || (iVar5 == 3)) || (iVar5 == 4)) {
        local_res20 = 7;
      }
      local_res10 = 1;
      if (iVar5 == 0) {
        local_res10 = 2;
      }
      else if (iVar5 == 1) {
        local_res10 = 3;
      }
      else if ((iVar5 == 2) || (iVar5 == 3)) {
        local_res10 = 4;
      }
      else if (iVar5 == 4) {
        local_res10 = 5;
      }
      local_f8 = 0;
      do {
        iVar5 = 0;
        do {
          FUN_1400709b0(4,0);
          FUN_1400709b0(4,0);
          if (2 < DAT_140e419b8) {
            FUN_1400709b0(4,0);
            FUN_1400709b0(4,0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_res10);
        local_f8 = local_f8 + 1;
      } while (local_f8 < local_res20);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      puVar6 = DAT_140e45d28;
    }
    else {
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      puVar6 = DAT_140e45d28;
      if (0x423 < (int)uVar18) {
        iVar11 = 1;
        if (iVar5 == 0) {
          iVar11 = 6;
        }
        else if (((iVar5 == 1) || (iVar5 == 2)) || (iVar5 == 3)) {
          iVar11 = 4;
        }
        else if (iVar5 == 4) {
          iVar11 = 3;
        }
        uVar45 = SUB84(DAT_14053a020,0);
        uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
        FUN_140332d90(((double)(int)uVar18 - _DAT_14053a910) * DAT_14053a670 * DAT_14053a020 *
                      DAT_140539d28);
        uVar37 = DAT_140539f40._4_4_;
        uVar47 = (undefined4)DAT_140539f40;
        fVar34 = DAT_14053ac2c;
        dVar27 = DAT_140539d28;
        puVar7 = DAT_140e46c88;
        if (((int)uVar18 < 0x60e) && ((int)(uVar18 - 0x424) % (iVar11 * 2) == 0)) {
          FUN_1400709b0(4);
          FUN_1400709b0(4,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          fVar34 = DAT_14053ac2c;
          dVar27 = DAT_140539d28;
          puVar7 = DAT_140e46c88;
        }
        break;
      }
    }
    goto LAB_14003989f;
  case 0x14:
    iVar5 = param_1[3];
    iVar11 = 0;
    if (iVar5 < 0x78) {
LAB_14003b54e:
      iVar9 = 0;
      if (iVar5 < 0xdc) {
        iVar9 = iVar11;
      }
      puVar6 = DAT_140e45d28;
      if (iVar5 == 1) {
        uVar45 = param_1[0xb];
        uVar44 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          puVar6[1] = 0x36;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar44;
          *(undefined4 *)(puVar6 + 3) = uVar45;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar44;
          *(undefined4 *)(puVar6 + 4) = uVar45;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
      DAT_140e45d28 = puVar6;
      uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
      uVar45 = SUB84(DAT_14053a020,0);
      uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    }
    else {
      iVar11 = 0xff;
      if (iVar5 < 0x82) {
        dVar27 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
        iVar9 = (int)(dVar27 * DAT_14053a5f8);
      }
      else {
        if (0xdb < iVar5) goto LAB_14003b54e;
        dVar27 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        uVar41 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
        iVar9 = 0;
        if (iVar5 < 0xdc) {
          iVar9 = (int)(dVar27 * DAT_14053a5f8);
        }
      }
    }
    piVar20 = param_1 + 3;
    iVar5 = *piVar20;
    if (iVar5 < 0x78) {
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)*piVar20 * DAT_140539cc8 + (float)param_1[0xb];
      iVar5 = *piVar20;
    }
    puVar6 = DAT_140e45d28;
    if (iVar5 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar47 = param_1[0xb];
      uVar37 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x11;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar37;
        *(undefined4 *)(puVar6 + 3) = uVar47;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar37;
        *(undefined4 *)(puVar6 + 4) = uVar47;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    iVar5 = param_1[3];
    if (0xdb < iVar5) {
      FUN_140001900(iVar5,0xdc,7);
    }
    iVar5 = param_1[3];
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    if (0x81 < iVar5) {
      uVar24 = *(ushort *)(param_1 + 0x10);
      uVar25 = (uint)uVar24;
      iVar4 = (uVar18 & 0xffff) - (uint)uVar24;
      iVar11 = iVar4 + 0x10000;
      if (-0x8001 < iVar4) {
        iVar11 = iVar4;
      }
      iVar4 = iVar11 + -0x10000;
      if (iVar11 < 0x8001) {
        iVar4 = iVar11;
      }
      if (iVar4 < 1) {
        if ((iVar4 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar4)) {
          uVar25 = uVar18 & 0xffff;
        }
      }
      else if (iVar4 < 0x200) {
        uVar25 = uVar18 & 0xffff;
      }
      else {
        uVar25 = (uint)(ushort)(uVar24 + 0x200);
      }
      *(short *)(param_1 + 0x10) = (short)uVar25;
      dVar27 = (double)FUN_1403307c0((double)uVar25 * (double)CONCAT44(uVar44,uVar45) *
                                     DAT_140539d28);
      param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar27 = (double)FUN_140332d90((double)uVar25 * (double)CONCAT44(uVar44,uVar45) *
                                     DAT_140539d28);
      param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar5 = FUN_1400c9580(iVar5,0,6,4,CONCAT44(uVar41,0x6e),0x6f,CONCAT44(uVar43,0x70),
                            CONCAT44(uVar46,0x6f));
      uVar37 = _UNK_14053bb24;
      uVar47 = _DAT_14053bb20;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    }
    uVar43 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x4e;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar9;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    if (param_1[3] == 0x17c) {
      DAT_140e46c88 = puVar7;
      *(undefined8 *)(param_1 + 0x14) = 0x50;
      param_1[3] = 0;
      iVar5 = param_1[5];
      if (iVar5 == 0x14) {
        DAT_140e4192c = 0;
        DAT_140e41b0c = 80000;
        DAT_140e4430c = 0x960;
      }
LAB_14003b9e1:
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar5 + 1;
      DAT_140e419bc = 1;
      fVar34 = DAT_14053ac2c;
      dVar27 = DAT_140539d28;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x15:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar11)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar31 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    dVar27 = DAT_140539d28;
    fVar36 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar36;
    dVar31 = (double)FUN_140332d90((double)uVar25 * dVar2 * dVar27);
    fVar34 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar34;
    if ((param_1[3] == 1) && (uVar43 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      puVar6[1] = 0x30;
      puVar6[2] = 0x3c;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 4) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0x3c;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      *(undefined4 *)(puVar6 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x54) = uVar43;
      puVar6[0xb] = 0;
      if (bVar26) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
      fVar34 = (float)param_1[0xb];
      fVar36 = (float)param_1[10];
      DAT_140e45d28 = puVar6;
    }
    iVar5 = 0;
    if (0x3b < (int)param_1[3]) {
      iVar9 = (param_1[3] + -0x3c) % 0x578;
      FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_140539cc0) * DAT_14053a798 * dVar2 * dVar27);
      dVar31 = (double)FUN_1403307c0();
      dVar27 = DAT_14053a3d0;
      fVar34 = fVar34 - DAT_14053ac44;
      dVar31 = dVar31 * DAT_14053a3d0;
      fVar35 = fVar36 + DAT_14053ac2c;
      dVar28 = (double)FUN_140332d90();
      dVar29 = (double)FUN_1403307c0();
      fVar36 = fVar36 - DAT_14053ac2c;
      dVar30 = (double)FUN_140332d90();
      fVar33 = DAT_140e445dc;
      fVar1 = DAT_140e445d8;
      dVar31 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((float)(dVar28 * dVar27) + fVar34)),
                                     (double)(DAT_140e445d8 - ((float)dVar31 + fVar35)));
      uVar25 = (uint)(dVar31 * dVar32);
      dVar30 = (double)FUN_1403300b4((double)(fVar33 - ((float)(dVar30 * dVar27) + fVar34)),
                                     (double)(fVar1 - ((float)(dVar29 * dVar27) + fVar36)));
      iVar11 = DAT_140e419b8;
      dVar29 = DAT_14053a938;
      dVar28 = DAT_14053a530;
      dVar31 = DAT_14053a178;
      dVar27 = DAT_14053a138;
      uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
      uVar18 = (uint)(dVar30 * dVar32);
      uVar13 = (ushort)uVar25;
      uVar24 = (ushort)uVar18;
      if (iVar9 < 800) {
        iVar11 = 1;
        if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
          iVar11 = 7;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar11 = 9;
        }
        dVar27 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        if (iVar9 == 0) {
          do {
            in_stack_fffffffffffffed0 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffed0 >> 0x20),0x2d);
            stage_entity_spawn_candidate(0xb2,0x640,5);
            uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar11);
LAB_14003c023:
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
          FUN_14018a340(DAT_140e472bc,1,1);
LAB_14003c050:
          dVar27 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        }
        else {
          if (iVar9 == 0xb4) {
            do {
              in_stack_fffffffffffffed0 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffed0 >> 0x20),0x2d);
              stage_entity_spawn_candidate(0xb1,0x640,5);
              uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar11);
            goto LAB_14003c023;
          }
          if (iVar9 == 0x168) {
            do {
              in_stack_fffffffffffffed0 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffed0 >> 0x20),0x2d);
              stage_entity_spawn_candidate(0xb0,0x640,5);
              uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar11);
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
            FUN_14018a340(DAT_140e472bc,1,1);
            goto LAB_14003c050;
          }
          if (iVar9 == 0x21c) {
            do {
              in_stack_fffffffffffffed0 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffed0 >> 0x20),0x2d);
              stage_entity_spawn_candidate(0xb3,0x640,5);
              uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar11);
            goto LAB_14003c023;
          }
        }
        iVar5 = 1;
        if (DAT_140e419b8 == 0) {
          iVar5 = 0x50;
        }
        else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
          iVar5 = 100;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar5 = 0x78;
        }
        iVar11 = 1;
        if (DAT_140e419b8 == 0) {
          iVar11 = 3;
        }
        else if (DAT_140e419b8 == 1) {
          iVar11 = 5;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar11 = 7;
        }
        else if (DAT_140e419b8 == 4) {
          iVar11 = 9;
        }
        dVar31 = DAT_14053a0b0;
        if ((((DAT_140e419b8 != 0) && (dVar31 = DAT_14053a118, DAT_140e419b8 != 1)) &&
            (dVar31 = DAT_14053a138, DAT_140e419b8 != 2)) &&
           ((DAT_140e419b8 != 3 && (dVar31 = dVar27, DAT_140e419b8 == 4)))) {
          dVar31 = DAT_14053a178;
        }
        iVar21 = (iVar9 + -100) % 0xb4;
        iVar4 = (6 - (iVar9 + -100) / 0xb4) * 5000;
        dVar31 = (double)iVar21 * DAT_140539e98 + dVar31;
        if (iVar9 < 0x280) {
          if (99 < iVar9) goto LAB_14003c186;
        }
        else {
          iVar4 = iVar11 * 0x280 + -0x280;
LAB_14003c186:
          if (iVar21 == 0) {
            *(ushort *)((longlong)param_1 + 0x42) = uVar13;
            *(ushort *)(param_1 + 0x11) = uVar24;
          }
        }
        if ((699 < iVar9 - 100U) || (uVar16 = (iVar9 + -100) % 0xb4, iVar5 <= (int)uVar16))
        goto LAB_14003cd13;
        uVar16 = uVar16 & 0x80000003;
        if ((int)uVar16 < 0) {
          uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;
        }
        if (uVar16 == 0) {
          FUN_1400709b0(2,0,iVar21,uVar18,*(undefined2 *)((longlong)param_1 + 0x42),0,dVar31,
                        CONCAT44(uVar43,1),iVar11,iVar4,0);
          uVar46 = 0;
          uVar22 = 1;
          uVar43 = 0;
          uVar38 = (ulonglong)*(ushort *)(param_1 + 0x11);
          FUN_1400709b0(2,0);
          uVar15 = *(ushort *)((longlong)param_1 + 0x42);
          iVar9 = (uVar25 & 0xffff) - (uint)uVar15;
          iVar5 = iVar9 + 0x10000;
          if (-0x8001 < iVar9) {
            iVar5 = iVar9;
          }
          iVar9 = iVar5 + -0x10000;
          if (iVar5 < 0x8001) {
            iVar9 = iVar5;
          }
          if (iVar9 < 1) {
            uVar14 = uVar15;
            if ((iVar9 < 0) && (uVar14 = uVar15 - 0x78, -0x78 < iVar9)) {
              uVar14 = uVar13;
            }
          }
          else {
            uVar14 = uVar13;
            if (0x77 < iVar9) {
              uVar14 = uVar15 + 0x78;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar14;
          uVar13 = *(ushort *)(param_1 + 0x11);
          iVar9 = (uVar18 & 0xffff) - (uint)uVar13;
          iVar5 = iVar9 + 0x10000;
          if (-0x8001 < iVar9) {
            iVar5 = iVar9;
          }
          iVar9 = iVar5 + -0x10000;
          if (iVar5 < 0x8001) {
            iVar9 = iVar5;
          }
          if (iVar9 < 1) {
            uVar15 = uVar13;
            if ((iVar9 < 0) && (uVar15 = uVar13 - 0x78, -0x78 < iVar9)) {
              uVar15 = uVar24;
            }
          }
          else {
            uVar15 = uVar24;
            if (0x77 < iVar9) {
              uVar15 = uVar13 + 0x78;
            }
          }
          *(ushort *)(param_1 + 0x11) = uVar15;
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8,uVar18,0x8000,uVar38,uVar43,dVar31,uVar22
                        ,iVar11,iVar4,uVar46);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      else {
        if (1099 < iVar9) {
          local_res18 = 1;
          if (DAT_140e419b8 == 0) {
            local_res18 = 0xc80;
          }
          else if (DAT_140e419b8 == 1) {
            local_res18 = 0x9c4;
          }
          else if (DAT_140e419b8 == 2) {
            local_res18 = 2000;
          }
          else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
            local_res18 = 0x5dc;
          }
          uVar43 = SUB84(DAT_14053a178,0);
          uVar46 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
          dVar32 = DAT_14053a240;
          if (iVar9 < 0x4b0) {
            dVar32 = (double)FUN_140332d90(((double)iVar9 - DAT_14053a938) * DAT_14053a530 *
                                           DAT_14053a020 * DAT_140539d28);
            dVar32 = dVar32 * dVar27 + dVar31;
          }
          local_f8 = 1;
          if (iVar11 == 0) {
            local_f8 = 0x46;
          }
          else if ((((iVar11 == 1) || (iVar11 == 2)) || (iVar11 == 3)) || (iVar11 == 4)) {
            local_f8 = 0x32;
          }
          local_res20 = 1;
          if (iVar11 == 0) {
            local_res20 = 3;
          }
          else if (iVar11 == 1) {
            local_res20 = 5;
          }
          else if (iVar11 == 2) {
            local_res20 = 7;
          }
          else if (iVar11 == 3) {
            local_res20 = 9;
          }
          else if (iVar11 == 4) {
            local_res20 = 0xb;
          }
          if (iVar11 == 0) {
            uVar43 = SUB84(DAT_14053a0b0,0);
            uVar46 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
          }
          else if (iVar11 == 1) {
            uVar43 = SUB84(DAT_14053a0f8,0);
            uVar46 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
          }
          else if (iVar11 == 2) {
            uVar43 = SUB84(dVar27,0);
            uVar46 = (undefined4)((ulonglong)dVar27 >> 0x20);
          }
          else if ((iVar11 != 3) &&
                  (uVar43 = (undefined4)DAT_140539f40, uVar46 = DAT_140539f40._4_4_, iVar11 == 4)) {
            uVar43 = SUB84(DAT_14053a1b8,0);
            uVar46 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
          }
          if (iVar9 == 0x44c) {
            *(ushort *)((longlong)param_1 + 0x42) = uVar13;
            *(ushort *)(param_1 + 0x11) = uVar24;
LAB_14003c7fe:
            fVar34 = DAT_14053ac2c;
            iVar5 = 0;
            do {
              uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
              iVar11 = local_res18;
              if (iVar9 < 0x578) {
                dVar27 = (double)FUN_140332d90();
                iVar11 = (int)(dVar27 * (double)(local_res18 + -20000)) + 20000;
              }
              iVar5 = iVar5 + 1;
              iVar11 = iVar5 * iVar11;
              uVar40 = (undefined6)((ulonglong)in_stack_fffffffffffffeb8 >> 0x10);
              FUN_1400709b0(7,0);
              uVar47 = 0;
              uVar44 = 2;
              in_stack_fffffffffffffed0 = CONCAT44(uVar45,1);
              in_stack_fffffffffffffeb8 = (double)CONCAT62(uVar40,*(undefined2 *)(param_1 + 0x11));
              fVar36 = fVar34;
              dVar30 = dVar32;
              FUN_1400709b0(7);
              dVar31 = DAT_14053a568;
              dVar27 = DAT_14053a020;
            } while (iVar5 < 3);
            iVar5 = 200;
            if (1099 < iVar9) {
              iVar5 = 10;
            }
            iVar4 = iVar5;
            if (iVar9 < 0x4b0) {
              dVar32 = (double)FUN_140332d90(((double)iVar9 - dVar29) * dVar28 * DAT_14053a020 *
                                             DAT_140539d28);
              iVar4 = 200 - (int)(dVar32 * dVar31);
            }
            uVar15 = *(ushort *)((longlong)param_1 + 0x42);
            iVar10 = (uVar25 & 0xffff) - (uint)uVar15;
            iVar21 = iVar10 + 0x10000;
            if (-0x8001 < iVar10) {
              iVar21 = iVar10;
            }
            iVar10 = iVar21 + -0x10000;
            if (iVar21 < 0x8001) {
              iVar10 = iVar21;
            }
            if (iVar10 < 1) {
              if (iVar10 < 0) {
                if (-iVar4 < iVar10) {
                  *(ushort *)((longlong)param_1 + 0x42) = uVar13;
                  goto LAB_14003c9cc;
                }
                uVar15 = uVar15 - (short)iVar4;
              }
LAB_14003c9c8:
              *(ushort *)((longlong)param_1 + 0x42) = uVar15;
            }
            else {
              if (iVar4 <= iVar10) {
                uVar15 = uVar15 + (short)iVar4;
                goto LAB_14003c9c8;
              }
              *(ushort *)((longlong)param_1 + 0x42) = uVar13;
            }
LAB_14003c9cc:
            if (iVar9 < 0x4b0) {
              dVar27 = (double)FUN_140332d90(((double)iVar9 - dVar29) * dVar28 * dVar27 *
                                             DAT_140539d28,uVar15,iVar4,uVar25,
                                             in_stack_fffffffffffffeb8,fVar36,dVar30,
                                             in_stack_fffffffffffffed0,uVar44,iVar11,uVar47);
              iVar5 = 200 - (int)(dVar27 * dVar31);
            }
            uVar15 = *(ushort *)(param_1 + 0x11);
            iVar4 = (uVar18 & 0xffff) - (uint)uVar15;
            iVar11 = iVar4 + 0x10000;
            if (-0x8001 < iVar4) {
              iVar11 = iVar4;
            }
            iVar4 = iVar11 + -0x10000;
            if (iVar11 < 0x8001) {
              iVar4 = iVar11;
            }
            if (iVar4 < 1) {
              uVar14 = uVar15;
              if ((iVar4 < 0) && (uVar14 = uVar15 - (short)iVar5, -iVar5 < iVar4)) {
                uVar14 = uVar24;
              }
            }
            else {
              uVar14 = uVar24;
              if (iVar5 <= iVar4) {
                uVar14 = uVar15 + (short)iVar5;
              }
            }
            *(ushort *)(param_1 + 0x11) = uVar14;
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar11 = DAT_140e419b8;
          }
          else {
            fVar34 = DAT_14053ac2c;
            if ((iVar9 < 0x578) &&
               (iVar5 = iVar9 + -0x44c,
               iVar5 == (iVar5 / 3 + (iVar5 >> 0x1f) +
                        (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >>
                             0x1f)) * 3)) goto LAB_14003c7fe;
          }
          iVar4 = 0x488;
          iVar5 = 0;
          local_res18 = 0;
          while( true ) {
            iVar21 = 1;
            if (iVar11 == 0) {
              iVar21 = 2;
            }
            else if ((((iVar11 == 1) || (iVar11 == 2)) || (iVar11 == 3)) || (iVar11 == 4)) {
              iVar21 = 3;
            }
            if (iVar21 <= local_res18) break;
            iVar21 = iVar4 + 0xc + iVar5;
            if (((iVar4 <= iVar9) && ((iVar9 < iVar21 || (iVar21 == 0)))) &&
               (iVar9 - iVar4 == ((iVar9 - iVar4) / 0xc) * 0xc)) {
              FUN_1400709b0(0xc,0,local_res18,0,uVar13,fVar34,CONCAT44(uVar46,uVar43),1,local_res20,
                            24000,0);
              FUN_1400709b0(0xc,0);
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
              FUN_14018a340(DAT_140e472a8,1,1);
              iVar11 = DAT_140e419b8;
            }
            iVar21 = iVar4 + 0xc + iVar5;
            if (((iVar4 + 6 <= iVar9) && ((iVar9 < iVar21 || (iVar21 == 0)))) &&
               (iVar21 = iVar9 - (iVar4 + 6), iVar21 == (iVar21 / 0xc) * 0xc)) {
              FUN_1400709b0(0xc,0,local_res18,0,uVar13,fVar34,CONCAT44(uVar46,uVar43),1,
                            local_res20 - 1U,
                            (int)(24000 / (ulonglong)(local_res20 - 1U)) * (local_res20 + -2) &
                            0xffff,0);
              FUN_1400709b0(0xc,0);
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
              FUN_14018a340(DAT_140e472a8,1,1);
              iVar11 = DAT_140e419b8;
            }
            local_res18 = local_res18 + 1;
            iVar4 = iVar4 + iVar5 + local_f8;
            iVar5 = iVar5 + 0xc;
          }
LAB_14003cd13:
          uVar45 = SUB84(DAT_14053a020,0);
          uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
          goto LAB_14003cd1f;
        }
        iVar5 = 1;
        if (DAT_140e419b8 == 0) {
          iVar5 = 5;
        }
        else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
          iVar5 = 4;
        }
        else if (DAT_140e419b8 == 4) {
          iVar5 = 3;
        }
        iVar11 = 1;
        if (DAT_140e419b8 == 0) {
          iVar11 = 3;
        }
        else if (DAT_140e419b8 == 1) {
          iVar11 = 4;
        }
        else if (DAT_140e419b8 == 2) {
          iVar11 = 5;
        }
        else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
          iVar11 = 7;
        }
        if (iVar9 == 0x334) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar13;
LAB_14003c41d:
          if ((iVar9 + -0x334) % iVar5 == 0) {
            iVar4 = 0;
            do {
              FUN_14006c2f0(5,0x28);
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar11);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        else if (iVar9 - 0x334U < 0x28) goto LAB_14003c41d;
        iVar4 = 0;
        if (iVar9 == 0x3ca) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar24;
LAB_14003c518:
          if ((iVar9 + -0x3ca) % iVar5 == 0) {
            do {
              FUN_14006c2f0(5,0x28);
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar11);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            uVar45 = SUB84(DAT_14053a020,0);
            uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
            goto LAB_14003cd1f;
          }
        }
        else if (iVar9 - 0x3caU < 0x28) goto LAB_14003c518;
      }
      uVar45 = SUB84(DAT_14053a020,0);
      uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    }
LAB_14003cd1f:
    iVar5 = FUN_1400c9580(param_1[3],0,6,4,0x6e,0x6f,0x70,0x6f);
    uVar43 = param_1[0xb];
    uVar46 = param_1[10];
    uVar47 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4);
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar47;
    puVar7[1] = 0x1e;
    puVar7[2] = 7;
    puVar7[3] = uVar46;
    puVar7[4] = uVar43;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    fVar34 = DAT_14053ac2c;
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    dVar27 = DAT_140539d28;
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      fVar34 = DAT_14053ac2c;
      uVar47 = (undefined4)DAT_140539f40;
      uVar37 = DAT_140539f40._4_4_;
      dVar27 = DAT_140539d28;
    }
    break;
  case 0x1e:
    iVar11 = param_1[3];
    iVar9 = 0;
    if (iVar11 < 0x6e) {
LAB_14003cee4:
      iVar4 = 0;
      if (iVar11 < 200) {
        iVar4 = iVar9;
      }
      puVar6 = DAT_140e45d28;
      if (iVar11 == 1) {
        uVar45 = param_1[0xb];
        uVar44 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          puVar6[1] = 0x36;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar44;
          *(undefined4 *)(puVar6 + 3) = uVar45;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar44;
          *(undefined4 *)(puVar6 + 4) = uVar45;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
      DAT_140e45d28 = puVar6;
      uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
      uVar45 = SUB84(DAT_14053a020,0);
      uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    }
    else {
      iVar9 = 0xff;
      if (iVar11 < 0x78) {
        dVar27 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a480) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
        iVar4 = (int)(dVar27 * DAT_14053a5f8);
      }
      else {
        if (199 < iVar11) goto LAB_14003cee4;
        dVar27 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a340) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
        iVar4 = 0;
        if (iVar11 < 200) {
          iVar4 = (int)(dVar27 * DAT_14053a5f8);
        }
      }
    }
    piVar20 = param_1 + 3;
    iVar11 = *piVar20;
    if (iVar11 < 0x6e) {
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)*piVar20 * DAT_140539cc8 + (float)param_1[0xb];
      iVar11 = *piVar20;
    }
    puVar6 = DAT_140e45d28;
    if (iVar11 == 0x6e) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar37 = param_1[0xb];
      uVar41 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x11;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar41;
        *(undefined4 *)(puVar6 + 3) = uVar37;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar41;
        *(undefined4 *)(puVar6 + 4) = uVar37;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    iVar11 = param_1[3];
    if (iVar11 < 0x78) {
      uVar22 = CONCAT44(uVar47,0x71);
      iVar5 = FUN_1400c9580(iVar11,0,5,2,uVar22,0x72);
      uVar47 = (undefined4)((ulonglong)uVar22 >> 0x20);
    }
    iVar11 = param_1[3];
    if (0x77 < iVar11) {
      uVar24 = *(ushort *)(param_1 + 0x10);
      uVar25 = (uint)uVar24;
      iVar9 = (uVar18 & 0xffff) - (uint)uVar24;
      iVar5 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar5 = iVar9;
      }
      iVar9 = iVar5 + -0x10000;
      if (iVar5 < 0x8001) {
        iVar9 = iVar5;
      }
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar9)) {
          uVar25 = uVar18 & 0xffff;
        }
      }
      else if (iVar9 < 0x200) {
        uVar25 = uVar18 & 0xffff;
      }
      else {
        uVar25 = (uint)(ushort)(uVar24 + 0x200);
      }
      *(short *)(param_1 + 0x10) = (short)uVar25;
      dVar27 = (double)FUN_1403307c0((double)uVar25 * (double)CONCAT44(uVar44,uVar45) *
                                     DAT_140539d28);
      param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar27 = (double)FUN_140332d90((double)uVar25 * (double)CONCAT44(uVar44,uVar45) *
                                     DAT_140539d28);
      param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar5 = FUN_1400c9580(iVar11,0,6,4,CONCAT44(uVar47,100),0x65,CONCAT44(uVar43,0x66),
                            CONCAT44(uVar46,0x65));
    }
    uVar37 = _UNK_14053bb24;
    uVar47 = _DAT_14053bb20;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    uVar43 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x4e;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar4;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    if (param_1[3] == 200) {
      DAT_140e46c88 = puVar7;
      param_1[0x15] = 0;
      param_1[3] = 0;
      iVar5 = param_1[5];
      if (iVar5 == 0x1e) {
        DAT_140e4192c = 0;
        DAT_140e41b0c = 40000;
        DAT_140e4430c = 0x5dc;
      }
      goto LAB_14003b9e1;
    }
    break;
  case 0x1f:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar9 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar5 = iVar9;
    }
    iVar9 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar9 = iVar5;
    }
    if (iVar9 < 1) {
      if ((iVar9 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar9)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar9 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar27 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90((double)uVar25 * dVar2 * DAT_140539d28);
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (param_1[3] == 10) {
      uVar22 = DAT_14053a700;
      stage_entity_spawn_candidate(0xb4,99999999,1);
      uVar43 = (undefined4)((ulonglong)uVar22 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if (param_1[3] == 100) {
      uVar22 = DAT_14053a7a8;
      stage_entity_spawn_candidate(0xb5,99999999,1);
      uVar43 = (undefined4)((ulonglong)uVar22 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if ((int)param_1[3] < 10) {
      uVar22 = CONCAT44(uVar47,0x67);
      iVar11 = FUN_1400c9580(param_1[3],0,5,2,uVar22,0x68);
      uVar47 = (undefined4)((ulonglong)uVar22 >> 0x20);
    }
    piVar20 = param_1 + 3;
    if (*piVar20 - 10U < 100) {
      uVar17 = CONCAT44(uVar43,0x6b);
      uVar22 = CONCAT44(uVar47,0x69);
      iVar11 = FUN_1400c9580(*piVar20,10,5,3,uVar22,0x6a,uVar17);
      uVar43 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar47 = (undefined4)((ulonglong)uVar22 >> 0x20);
    }
    if (*piVar20 - 0x6eU < 10) {
      uVar22 = CONCAT44(uVar47,0x68);
      iVar11 = FUN_1400c9580(*piVar20,0x6e,5,2,uVar22,0x67);
      uVar47 = (undefined4)((ulonglong)uVar22 >> 0x20);
    }
    if (0x77 < *piVar20) {
      iVar11 = FUN_1400c9580(*piVar20,0x78,6,4,CONCAT44(uVar47,100),0x65,CONCAT44(uVar43,0x66),
                             CONCAT44(uVar46,0x65));
    }
    lVar12 = (longlong)iVar11;
    goto LAB_14003d61f;
  case 0x28:
  case 0x32:
    iVar5 = param_1[3];
    FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a558 * DAT_14053a020 * DAT_140539d28);
    uVar37 = DAT_140539f40._4_4_;
    uVar47 = (undefined4)DAT_140539f40;
    puVar6 = DAT_140e45d28;
    if (iVar5 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar43 = param_1[0xb];
      uVar46 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x36;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
        *(undefined4 *)(puVar6 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
        *(undefined4 *)(puVar6 + 4) = uVar43;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    piVar20 = param_1 + 3;
    if (*piVar20 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar5 = FUN_1400c9580(*piVar20,0,5,2,0x6c,0x6d);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    if (*piVar20 == 0xb4) {
      *piVar20 = 0;
      iVar5 = param_1[5];
      if (iVar5 == 0x28) {
        DAT_140e4192c = 0;
        DAT_140e41b0c = 80000;
        DAT_140e4430c = 0x960;
        param_1[0x15] = 0;
        iVar11 = 80000;
      }
      else {
        iVar11 = DAT_140e41b0c;
        if (iVar5 == 0x32) {
          DAT_140e4430c = 0xce4;
          DAT_140e41b0c = 0x24220;
          DAT_140e4192c = 0;
          iVar11 = 0x24220;
        }
      }
      param_1[7] = iVar11;
      param_1[5] = iVar5 + 1;
      DAT_140e419bc = 1;
      fVar34 = DAT_14053ac2c;
      dVar27 = DAT_140539d28;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x29:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar11)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar27 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar31 = (double)FUN_140332d90((double)uVar25 * dVar2 * DAT_140539d28);
    uVar22 = CONCAT44(uVar46,0x65);
    dVar27 = (double)CONCAT44(uVar43,0x66);
    uVar38 = CONCAT44(uVar47,100);
    param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar5 = (int)param_1[3] % 0x640;
    iVar11 = FUN_1400c9580(param_1[3],0,6,4,uVar38,0x65,dVar27,uVar22);
    uVar43 = DAT_140e41a50;
    if (iVar5 < 0x41a) {
      uVar18 = iVar5 - 1;
      iVar9 = iVar5 % 0x15e;
      if ((uVar18 < 899) && (uVar18 == ((int)uVar18 / 0x15e) * 0x15e)) {
        uVar46 = param_1[1];
        puVar6 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base();
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar43;
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
          *(undefined4 *)((longlong)puVar6 + 0x54) = uVar46;
          puVar6[0xb] = 0;
          if (bVar26) {
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
      dVar31 = DAT_14053a178;
      uVar43 = (undefined4)((ulonglong)dVar27 >> 0x20);
      if (iVar5 - 0x28U < 0x28) {
        uVar18 = iVar5 - 0x28U & 0x80000007;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xfffffff8) + 1;
        }
        if (uVar18 == 0) {
          uVar38 = CONCAT44((int)(uVar38 >> 0x20),param_1[0xb]);
          stage_entity_spawn_candidate
                    (0xb6,2000,7,0xc90,uVar38,(short)iVar9 * 0x226 + -0xc90,DAT_14053a178,0x2d,1,0);
          uVar38 = uVar38 & 0xffffffff00000000;
          stage_entity_spawn_candidate(0xb6,2000,7);
          uVar43 = (undefined4)((ulonglong)dVar31 >> 0x20);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
          FUN_14018a340(DAT_140e472bc,1,1);
        }
      }
      dVar27 = DAT_14053a218;
      uVar46 = (undefined4)(uVar38 >> 0x20);
      if (iVar5 - 0x186U < 0x28) {
        iVar5 = iVar5 + -0x186;
        if (iVar5 == (iVar5 / 6 + (iVar5 >> 0x1f) +
                     (int)(((longlong)iVar5 / 6 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >> 0x1f))
                     * 6) {
          uVar22 = CONCAT44(uVar46,param_1[0xb]);
          stage_entity_spawn_candidate
                    (0xb6,0x5dc,7,0xc90,uVar22,(short)iVar9 * 0x226 + -0xc90,DAT_14053a218,0x2d,1,0)
          ;
          uVar46 = (undefined4)((ulonglong)uVar22 >> 0x20);
          stage_entity_spawn_candidate(0xb6,0x5dc,7);
          uVar43 = (undefined4)((ulonglong)dVar27 >> 0x20);
LAB_14003dc6a:
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
          FUN_14018a340(DAT_140e472bc,1,1);
        }
      }
      else if (699 < iVar5) {
        uVar18 = iVar9 - 0x28;
        iVar5 = ((int)uVar18 / 0x28) * -4 + 0xb;
        dVar27 = DAT_14053a218 - (double)((int)uVar18 / 0x28) * DAT_14053a0b0;
        if ((uVar18 < 0x3c) && ((int)uVar18 % 0x28 == 0)) {
          iVar4 = 0;
          if (0 < iVar5) {
            do {
              uVar25 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
              DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
              DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
              uVar18 = uVar25 * 0x800 ^ uVar25;
              DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
              DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ uVar18 ^ DAT_140e9fd18;
              uVar38 = CONCAT44((int)(uVar38 >> 0x20),param_1[0xb]);
              dVar31 = dVar27;
              stage_entity_spawn_candidate
                        (0xb6,1000,7,uVar25,uVar38,
                         ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) +
                         (short)iVar4 * (short)(0x10000 / (longlong)iVar5),dVar27,0x2d,1,0);
              uVar43 = (undefined4)((ulonglong)dVar31 >> 0x20);
              uVar46 = (undefined4)(uVar38 >> 0x20);
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar5);
          }
          goto LAB_14003dc6a;
        }
      }
      if (iVar9 < 10) {
        iVar11 = FUN_1400c9580(iVar9,0,5,2,CONCAT44(uVar46,0x67),0x68);
LAB_14003dcc1:
        lVar12 = (longlong)iVar11;
      }
      else if (iVar9 < 0x5a) {
        iVar5 = FUN_1400c9580(iVar9,10,5,3,CONCAT44(uVar46,0x69),0x6a,CONCAT44(uVar43,0x6b));
        lVar12 = (longlong)iVar5;
      }
      else {
        if (99 < iVar9) goto LAB_14003dcc1;
        iVar5 = FUN_1400c9580(iVar9,0x5a,5,2,CONCAT44(uVar46,0x68),0x67);
        lVar12 = (longlong)iVar5;
      }
    }
    else {
      if (iVar5 < 0x438) goto LAB_14003dcc1;
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 9;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 6;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar9 = 5;
      }
      if ((iVar5 == 0x438) && (uVar43 = param_1[1], DAT_140e45d1c < 0x1000)) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x30;
        puVar6[2] = 0x3c;
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0x3ff0000000000000;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x3c;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar43;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      else {
        puVar6 = DAT_140e45d28;
        if ((iVar5 - 0x474U < 0x168) && ((int)(iVar5 - 0x474U) % iVar9 == 0)) {
          uVar22 = 0x28;
          uVar25 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar18 = uVar25 * 0x800 ^ uVar25;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar18) >> 8 ^ uVar18 ^ DAT_140e9fd18;
          dVar27 = DAT_14053a1b8;
          stage_entity_spawn_candidate
                    (0xb7,500,5,uVar25,param_1[0xb],
                     (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x3201) * -0x3201 +
                     -0x5900,DAT_14053a1b8,0x28,1,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          puVar6 = DAT_140e45d28;
        }
      }
      DAT_140e45d28 = puVar6;
      if (iVar5 < 0x442) {
        uVar43 = 0x68;
        uVar17 = 0x438;
        uVar39 = 0x67;
      }
      else {
        if (iVar5 < 0x60e) {
          iVar5 = FUN_1400c9580(iVar5,0x442,5,3,0x69,0x6a,0x6b,uVar22);
          lVar12 = (longlong)iVar5;
          goto LAB_14003d61f;
        }
        if (0x617 < iVar5) goto LAB_14003dcc1;
        uVar43 = 0x67;
        uVar17 = 0x60e;
        uVar39 = 0x68;
      }
      iVar5 = FUN_1400c9580(iVar5,uVar17,5,2,uVar39,uVar43,dVar27,uVar22);
      lVar12 = (longlong)iVar5;
    }
LAB_14003d61f:
    uVar22 = 0x1e;
LAB_14003d624:
    uVar37 = _UNK_14053bb24;
    uVar47 = _DAT_14053bb20;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar12 * 4),uVar22,7);
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    break;
  case 0x33:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar11)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar32 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    dVar27 = DAT_140539d28;
    fVar34 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar34;
    dVar28 = (double)FUN_140332d90((double)uVar25 * dVar2 * dVar27);
    dVar32 = DAT_14053a430;
    fVar36 = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar36;
    iVar5 = param_1[3];
    iVar11 = 0;
    if (iVar5 < 0x8c) {
LAB_14003e1c1:
      iVar9 = 0;
      if (iVar5 < 0xd2) {
        iVar9 = iVar11;
      }
      if ((iVar5 == 1) && (uVar43 = param_1[1], DAT_140e45d1c < 0x1000)) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x30;
        puVar6[2] = 0x3c;
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0x3ff0000000000000;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x3c;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar43;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
        fVar34 = (float)param_1[10];
        fVar36 = (float)param_1[0xb];
        DAT_140e45d28 = puVar6;
      }
    }
    else {
      iVar11 = 0xff;
      if (iVar5 < 0x96) {
        dVar27 = (double)FUN_140332d90(((double)iVar5 - dVar31) * DAT_14053a9d8 * dVar2 * dVar27);
        iVar9 = (int)(dVar27 * DAT_14053a5f8);
      }
      else {
        if (0xd1 < iVar5) goto LAB_14003e1c1;
        dVar27 = (double)FUN_140332d90(((double)iVar5 - dVar32) * DAT_14053a628 * dVar2 * dVar27);
        iVar9 = 0;
        if (iVar5 < 0xd2) {
          iVar9 = (int)(dVar27 * DAT_14053a5f8);
        }
      }
    }
    uVar37 = DAT_140539f40._4_4_;
    uVar47 = (undefined4)DAT_140539f40;
    if (param_1[3] == 0x3c) {
      stage_entity_spawn_candidate(0xb8,99999999,1);
      fVar34 = (float)param_1[10];
      fVar36 = (float)param_1[0xb];
    }
    dVar27 = DAT_14053a218;
    dVar31 = DAT_140539f68;
    iVar5 = param_1[3];
    if (iVar5 - 0x5aU < 0xb) {
      dVar28 = DAT_14053a218 - ((double)iVar5 - dVar32) * DAT_140539f68;
      dVar32 = (double)FUN_1403307c0(DAT_14053a098);
      uVar22 = DAT_14053a098;
      fVar34 = (float)(dVar32 * dVar28) + fVar34;
      param_1[10] = fVar34;
      dVar32 = (double)FUN_140332d90(uVar22);
      fVar36 = (float)(dVar32 * dVar28) + fVar36;
      param_1[0xb] = fVar36;
    }
    if (iVar5 - 0x6eU < 0xb) {
      dVar27 = dVar27 - ((double)iVar5 - DAT_14053a480) * dVar31;
      dVar31 = (double)FUN_1403307c0(DAT_140539f98);
      uVar22 = DAT_140539f98;
      param_1[10] = (float)(dVar31 * dVar27) + fVar34;
      dVar31 = (double)FUN_140332d90(uVar22);
      param_1[0xb] = (float)(dVar31 * dVar27) + fVar36;
    }
    if (iVar5 == 0x8c) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    uVar43 = DAT_140e41ab8;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x58;
    *(undefined8 *)(puVar7 + 2) = 5;
    puVar7[4] = 0;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = iVar9;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46df0 = _DAT_140e46df0 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    if ((int)param_1[3] < 10) {
      FUN_1400c9580(param_1[3],0,5,2,0x67,0x68);
    }
    if (param_1[3] - 10 < 0xaa) {
      FUN_1400c9580(param_1[3],10,5,3,0x69,0x6a,0x6b);
    }
    if (0xb3 < (int)param_1[3]) {
      FUN_1400c9580(param_1[3],0xb4,6,4,100,0x65,0x66,0x65);
    }
    iVar5 = FUN_1400c9580(param_1[3],0,6,4,100,0x65,0x66,0x65);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x23,7);
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    if (param_1[3] == 0xd2) {
      param_1[3] = 0;
      param_1[5] = param_1[5] + 1;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x34:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar11)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar27 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    uVar47 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90((double)uVar25 * dVar2 * DAT_140539d28);
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    iVar5 = FUN_1400c9580(param_1[3],0,6,4,CONCAT44(uVar47,100),0x65,CONCAT44(uVar43,0x66),
                          CONCAT44(uVar46,0x65));
    lVar12 = (longlong)iVar5;
    uVar22 = 0x23;
    goto LAB_14003d624;
  case 0x3c:
    puVar6 = DAT_140e45d28;
    if (param_1[3] == 1) {
      uVar43 = param_1[0xb];
      uVar46 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x36;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
        *(undefined4 *)(puVar6 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
        *(undefined4 *)(puVar6 + 4) = uVar43;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    piVar20 = param_1 + 3;
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    if (*piVar20 < 0xb4) {
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)*piVar20 * DAT_140539cc8 + (float)param_1[0xb];
      iVar5 = FUN_1400c9580(*piVar20,0,5,2,CONCAT44(uVar43,0x6c),0x6d);
      uVar37 = _UNK_14053bb24;
      uVar47 = _DAT_14053bb20;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    }
    puVar6 = DAT_140e45d28;
    if (*piVar20 == 0xb4) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar43 = param_1[0xb];
      uVar46 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x10;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
        *(undefined4 *)(puVar6 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
        *(undefined4 *)(puVar6 + 4) = uVar43;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    uVar45 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    puVar7 = DAT_140e46c88;
    if (param_1[3] == 300) {
      param_1[10] = 0x43b40000;
      param_1[0xb] = 0x43480000;
      param_1[7] = 150000;
      param_1[3] = 0;
      param_1[5] = param_1[5] + 1;
      DAT_140e41b0c = 150000;
      DAT_140e4430c = 0x12c0;
      DAT_140e4192c = 0;
      DAT_140e41af8 = 1;
      DAT_140e419bc = 0;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x3d:
    puVar6 = DAT_140e45d28;
    if ((param_1[3] == 1) && (uVar43 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      puVar6[1] = 0x2d;
      puVar6[2] = 0x3c;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 4) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0x3c;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      *(undefined4 *)(puVar6 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x54) = uVar43;
      puVar6[0xb] = 0;
      if (bVar26) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    piVar20 = param_1 + 3;
    if (*piVar20 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    uVar45 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    if (100 < *piVar20) {
      FUN_140332d90();
      FUN_140332d90();
      FUN_1400c8410(DAT_140e444a0,0x1e,7);
    }
    fVar34 = DAT_14053ac2c;
    uVar37 = DAT_140539f40._4_4_;
    uVar47 = (undefined4)DAT_140539f40;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    if (*piVar20 == 0x78) {
      param_1[0x15] = 0;
      param_1[0x17] = 1;
      *piVar20 = 0;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
    uVar24 = *(ushort *)(param_1 + 0x10);
    uVar25 = (uint)uVar24;
    iVar11 = (uVar18 & 0xffff) - (uint)uVar24;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar25 = (uint)(ushort)(uVar24 - 0x200), -0x200 < iVar11)) {
        uVar25 = uVar18 & 0xffff;
      }
    }
    else if (iVar11 < 0x200) {
      uVar25 = uVar18 & 0xffff;
    }
    else {
      uVar25 = (uint)(ushort)(uVar24 + 0x200);
    }
    *(short *)(param_1 + 0x10) = (short)uVar25;
    dVar27 = (double)FUN_1403307c0((double)uVar25 * dVar2 * dVar30);
    param_1[10] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90((double)uVar25 * dVar2 * DAT_140539d28);
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    puVar6 = DAT_140e45d28;
    if ((((uint)param_1[3] < 0x3d) &&
        ((0x1000000040000002U >> ((longlong)(int)param_1[3] & 0x3fU) & 1) != 0)) &&
       (uVar43 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar6 = 1;
      puVar6[1] = 0x30;
      puVar6[2] = 0x3c;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 4) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0x3ff0000000000000;
      puVar6[6] = 0x3ff0000000000000;
      puVar6[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar6 + 8) = 0x1e;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      *(undefined4 *)(puVar6 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x54) = uVar43;
      puVar6[0xb] = 0;
      if (bVar26) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    iVar11 = param_1[5] + -0x3e;
    iVar5 = 1;
    iVar11 = iVar11 + (iVar11 / 3 + (iVar11 >> 0x1f) +
                      (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * -3;
    if (DAT_140e419b8 == 0) {
      iVar5 = 0x32;
    }
    else if (DAT_140e419b8 == 1) {
      iVar5 = 0x24;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar5 = 0x20;
    }
    else if (DAT_140e419b8 == 4) {
      iVar5 = 0x1c;
    }
    uVar22 = 2;
    if (iVar11 == 1) {
      if (DAT_140e419b8 == 0) {
        iVar5 = 0x28;
LAB_14003f1a3:
        uVar22 = 4;
      }
      else if (DAT_140e419b8 == 1) {
        iVar5 = 0x1c;
        uVar22 = 4;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar5 = 0x19;
        uVar22 = 4;
      }
      else {
        iVar5 = 1;
        if (DAT_140e419b8 != 4) goto LAB_14003f1a3;
        iVar5 = 0x15;
        uVar22 = 4;
      }
    }
    else if (iVar11 == 2) {
      iVar5 = 1;
      if (DAT_140e419b8 == 0) {
        iVar5 = 0x1e;
      }
      else if (DAT_140e419b8 == 1) {
        iVar5 = 0x14;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar5 = 0x12;
      }
      else if (DAT_140e419b8 == 4) {
        iVar5 = 0x10;
      }
      uVar22 = 6;
    }
    uVar18 = param_1[3];
    if ((99 < (int)uVar18) &&
       (uVar38 = (longlong)(int)(uVar18 - 100) % (longlong)iVar5, (int)uVar38 == 0)) {
      uVar43 = FUN_140134d00(uVar18,uVar38 & 0xffffffff,uVar22);
      switch(uVar43) {
      case 0:
        local_res8 = 0xbc;
        break;
      case 1:
        local_res8 = 0xbd;
        break;
      case 2:
        local_res8 = 0xbe;
        break;
      case 3:
        local_res8 = 0xbf;
        break;
      case 4:
        local_res8 = 0xc0;
        break;
      case 5:
        local_res8 = 0xc1;
        break;
      case 6:
        local_res8 = 0xc2;
        break;
      default:
        local_res8 = SUB84(param_1,0);
      }
      uVar25 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar25 = uVar25 * 0x800 ^ uVar25;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar25) >> 8 ^ uVar25 ^ DAT_140e9fd18;
      FUN_140134db0(uVar18,DAT_14053a018,DAT_14053a138);
      stage_entity_spawn_candidate(local_res8,99999999,1);
      param_1[0x17] = param_1[0x17] + 1;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    if ((int)param_1[3] < 0x5a) {
      iVar5 = FUN_1400c9580(param_1[3],0,6,4,100,0x65,0x66,0x65);
    }
    else {
      iVar5 = 100;
    }
    if (param_1[3] - 0x5a < 10) {
      iVar5 = FUN_1400c9580(param_1[3],0x5a,5,2,0x67,0x68);
    }
    if (99 < (int)param_1[3]) {
      iVar5 = FUN_1400c9580(param_1[3],100,5,3,0x69,0x6a,0x6b);
    }
    uVar37 = _UNK_14053bb24;
    uVar47 = _DAT_14053bb20;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    if (param_1[0x15] == 1) {
      uVar18 = DAT_140e44acc & 0x80000001;
      if ((int)uVar18 < 0) {
        uVar18 = (uVar18 - 1 | 0xfffffffe) + 1;
      }
      if (uVar18 == 0) {
        FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,8);
      }
    }
    iVar5 = param_1[5];
    if ((iVar5 == 0x3e) &&
       ((int)param_1[7] <
        (DAT_140e41b0c / 3 + (DAT_140e41b0c >> 0x1f) +
        (int)((ulonglong)((longlong)DAT_140e41b0c / 3 + ((longlong)DAT_140e41b0c >> 0x3f)) >> 0x1f))
        * 2)) {
      FUN_140079e20(param_1,2);
      FUN_140109660(0x19);
      param_1[0x17] = 0;
      iVar5 = param_1[5] + 1;
      param_1[5] = iVar5;
    }
    if ((iVar5 == 0x3f) &&
       ((int)param_1[7] <
        DAT_140e41b0c / 3 + (DAT_140e41b0c >> 0x1f) +
        (int)((ulonglong)((longlong)DAT_140e41b0c / 3 + ((longlong)DAT_140e41b0c >> 0x3f)) >> 0x1f))
       ) {
      FUN_140079e20(param_1,2);
      FUN_140109660(0x19);
      param_1[0x17] = 0;
      iVar5 = param_1[5] + 1;
      param_1[5] = iVar5;
    }
    if (((iVar5 == 0x3e) || (iVar5 == 0x3f)) && (DAT_140e4430c < 0x5dc)) {
      FUN_140079e20(param_1,2);
      stage_pending_effect_flush_candidate();
      if (DAT_140e44654 < 100) {
        DAT_140e44654 = 100;
      }
      iVar5 = 0x40;
      param_1[5] = 0x40;
LAB_14003f62a:
      if ((0 < DAT_140e44600) || (DAT_140e44600 < -100)) {
        stage_entity_spawn_candidate(0xc3,99999999,1);
        iVar5 = param_1[5] + 3;
        param_1[5] = iVar5;
        param_1[0x15] = 1;
      }
    }
    else if (iVar5 - 0x3eU < 3) goto LAB_14003f62a;
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    if ((iVar5 - 0x41U < 3) && (DAT_140e44654 < 0x3d)) {
      param_1[5] = iVar5 + -3;
      param_1[0x15] = 0;
      puVar7 = DAT_140e46c88;
    }
    break;
  case 0x46:
    FUN_140003e60(param_1);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    if ((int)param_1[3] < 0xf0) {
      FUN_14007ac00(param_1);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,CONCAT44(uVar43,0x6c),0x6d);
      uVar37 = _UNK_14053bb24;
      uVar47 = _DAT_14053bb20;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
    }
    fVar34 = DAT_14053ac2c;
    puVar6 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar43 = param_1[0xb];
      uVar46 = param_1[10];
      fVar34 = DAT_14053ac2c;
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x10;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar46;
        *(undefined4 *)(puVar6 + 3) = uVar43;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar46;
        *(undefined4 *)(puVar6 + 4) = uVar43;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar6;
        }
        fVar34 = DAT_14053ac2c;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
          fVar34 = DAT_14053ac2c;
        }
      }
    }
LAB_14003989f:
    DAT_140e45d28 = puVar6;
    uVar45 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    dVar27 = DAT_140539d28;
    puVar7 = DAT_140e46c88;
    break;
  case 99:
    FUN_140003ad0(param_1);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    iVar5 = param_1[3];
    uVar47 = (undefined4)DAT_140539f40;
    uVar37 = DAT_140539f40._4_4_;
    if (iVar5 < 300) {
      if (iVar5 < 0x10e) {
        if (iVar5 < 0xf0) {
          FUN_14007ac00(param_1);
          param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
        }
        else {
          FUN_140332d90(((double)iVar5 - DAT_14053a5e8) * DAT_14053a798 * dVar2 * DAT_140539d28);
        }
      }
      else {
        FUN_140332d90(((double)iVar5 - DAT_14053a5e8) * DAT_14053a798 * dVar2 * DAT_140539d28);
        FUN_140332d90(((double)iVar5 - DAT_14053a5e8) * DAT_14053a798 * DAT_14053a020 *
                      DAT_140539d28);
      }
      if (param_1[3] == 0xf0) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,CONCAT44(uVar43,0x6c),0x6d);
      uVar37 = _UNK_14053bb24;
      uVar47 = _DAT_14053bb20;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,8);
    }
    fVar34 = DAT_14053ac2c;
    dVar27 = DAT_140539d28;
    uVar45 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    puVar7 = DAT_140e46c88;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
      puVar7 = DAT_140e46c88;
    }
  }
  DAT_140e46c88 = puVar7;
  iVar5 = param_1[5];
  if ((iVar5 < 0x14) || ((puVar7 = DAT_140e46c88, iVar5 == 0x14 && ((int)param_1[3] < 0x82)))) {
    fVar36 = (float)param_1[0xd];
    fVar1 = (float)param_1[0xf];
    fVar35 = fVar36 + fVar1;
    dVar31 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a3a0) * DAT_14053a698 *
                                   (double)CONCAT44(uVar44,uVar45) * dVar27);
    dVar27 = DAT_140539d28;
    fVar33 = (float)(dVar31 * DAT_14053a018) + (fVar35 - _DAT_14053add8);
    if (iVar5 < 0xb) {
      dVar31 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar31 * DAT_14053a018) + fVar36;
      if ((9 < iVar5) && (0x77 < (int)param_1[3])) goto LAB_14003fc02;
    }
    else {
LAB_14003fc02:
      fVar33 = fVar35 - _DAT_14053add0;
    }
    if (10 < iVar5) {
      param_1[0xf] = (float)(int)param_1[3] * DAT_140539cc8 + fVar1;
    }
    uVar43 = DAT_140e450f0;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x14;
    puVar7[2] = 7;
    puVar7[3] = 0x43b40000;
    puVar7[4] = fVar35;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar43 = DAT_140e449f0;
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x1e;
    puVar7[2] = 7;
    puVar7[3] = 0x43b40000;
    puVar7[4] = fVar33;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    uVar41 = DAT_140e449e8;
    uVar43 = param_1[0xb];
    uVar46 = param_1[10];
    DAT_140e46c88 = puVar7;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar41;
    puVar7[1] = 0x1e;
    puVar7[2] = 7;
    puVar7[3] = uVar46;
    puVar7[4] = uVar43;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
    DAT_140e46c88 = puVar7;
    if ((param_1[5] == 1) && (iVar5 = param_1[3], iVar5 < 0x18)) {
      if (-1 < iVar5) {
        FUN_140332d90(((double)iVar5 - _DAT_14053b118) * DAT_14053a830 *
                      (double)CONCAT44(uVar44,uVar45) * dVar27);
      }
      FUN_1400c8410(DAT_140e449e8,0x1e,8);
    }
    uVar43 = DAT_140e449ec;
    puVar7 = (undefined4 *)_malloc_base(0x48);
    if (puVar7 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar7 = uVar43;
    puVar7[1] = 0x1e;
    puVar7[2] = 7;
    puVar7[3] = 0x43b40000;
    puVar7[4] = fVar33;
    *(undefined2 *)(puVar7 + 5) = 0;
    *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
    puVar7[10] = 0xff;
    puVar7[0xb] = 0xff;
    puVar7[0xc] = 0xff;
    puVar7[0xd] = 0xff;
    *(undefined8 *)(puVar7 + 0xe) = 1;
    *(undefined8 *)(puVar7 + 0x10) = 0;
    DAT_140e46d08 = DAT_140e46d08 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar7;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
    }
  }
  DAT_140e46c88 = puVar7;
  iVar5 = param_1[5];
  if (8 < iVar5 - 0x15U) {
    puVar7 = DAT_140e46c88;
    if (iVar5 == 0x14) {
      if ((int)param_1[3] < 0x82) goto LAB_14004060c;
    }
    else if ((iVar5 != 0x1e) || (0x81 < (int)param_1[3])) goto LAB_14004060c;
  }
  dVar32 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a798 *
                                 (double)CONCAT44(uVar44,uVar45) * DAT_140539d28);
  dVar31 = DAT_14053abc0;
  dVar32 = dVar32 * _DAT_14053aa18;
  dVar28 = (double)FUN_140332d90();
  uVar43 = DAT_140e41968;
  fVar1 = DAT_14053ac9c;
  fVar36 = DAT_14053ac58;
  dVar27 = DAT_140539e60;
  fVar33 = (float)param_1[0xb] + DAT_14053ac9c;
  fVar35 = (float)param_1[10] + DAT_14053ac58;
  dVar28 = dVar28 * DAT_140539e60;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 8;
  puVar7[3] = fVar35;
  puVar7[4] = fVar33;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(double *)(puVar7 + 8) = dVar28 + (double)CONCAT44(uVar37,uVar47);
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xe1;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  DAT_140e46c88 = puVar7;
  dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_140539cc0) * dVar31 *
                                 (double)CONCAT44(uVar44,uVar45) * DAT_140539d28);
  uVar43 = DAT_140e41968;
  fVar33 = (float)param_1[0xb];
  fVar35 = (float)param_1[10];
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 8;
  puVar7[3] = fVar35 - fVar36;
  puVar7[4] = fVar33 + fVar1;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(double *)(puVar7 + 8) = dVar28 * dVar27 + (double)CONCAT44(uVar37,uVar47);
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xe1;
  puVar7[0xe] = 1;
  puVar7[0xf] = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  DAT_140e46c88 = puVar7;
  dVar28 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_140539cc0) * dVar31 *
                                 (double)CONCAT44(uVar44,uVar45) * DAT_140539d28);
  uVar43 = DAT_140e41968;
  fVar1 = DAT_14053acb4;
  fVar36 = DAT_14053ac5c;
  fVar33 = (float)param_1[0xb] + DAT_14053acb4;
  fVar35 = (float)param_1[10] + DAT_14053ac5c;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 8;
  puVar7[3] = fVar35;
  puVar7[4] = fVar33;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(double *)(puVar7 + 8) = dVar28 * dVar27 + (double)CONCAT44(uVar37,uVar47);
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xe1;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  DAT_140e46c88 = puVar7;
  dVar31 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_140539cc0) * dVar31 *
                                 (double)CONCAT44(uVar44,uVar45) * DAT_140539d28);
  uVar43 = DAT_140e41968;
  fVar33 = (float)param_1[0xb];
  fVar35 = (float)param_1[10];
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 8;
  puVar7[3] = fVar35 - fVar36;
  puVar7[4] = fVar33 + fVar1;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(double *)(puVar7 + 8) = dVar31 * dVar27 + (double)CONCAT44(uVar37,uVar47);
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xe1;
  puVar7[0xe] = 1;
  puVar7[0xf] = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  uVar43 = DAT_140e443fc;
  fVar1 = DAT_14053ac44;
  fVar36 = (float)param_1[10];
  fVar33 = (float)param_1[0xb] - DAT_14053ac44;
  DAT_140e46c88 = puVar7;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 7;
  puVar7[3] = fVar36 + fVar34;
  puVar7[4] = fVar33;
  sVar19 = (short)(int)dVar32;
  *(short *)(puVar7 + 5) = sVar19;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  uVar43 = DAT_140e443fc;
  fVar36 = (float)param_1[0xb];
  fVar33 = (float)param_1[10];
  DAT_140e46c88 = puVar7;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar43;
  puVar7[1] = 0x1d;
  puVar7[2] = 7;
  puVar7[3] = fVar33 - fVar34;
  puVar7[4] = fVar36 - fVar1;
  *(short *)(puVar7 + 5) = -sVar19;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  puVar7[0xe] = 1;
  puVar7[0xf] = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  uVar45 = DAT_140e443f8;
  uVar43 = param_1[0xb];
  uVar46 = param_1[10];
  DAT_140e46c88 = puVar7;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar7 = uVar45;
  puVar7[1] = 0x1d;
  puVar7[2] = 7;
  puVar7[3] = uVar46;
  puVar7[4] = uVar43;
  *(undefined2 *)(puVar7 + 5) = 0;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  _DAT_140e46d04 = _DAT_140e46d04 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
LAB_14004060c:
  DAT_140e46c88 = puVar7;
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


