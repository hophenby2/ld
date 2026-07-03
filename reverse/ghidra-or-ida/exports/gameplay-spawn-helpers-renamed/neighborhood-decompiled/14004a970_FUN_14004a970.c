// Function: FUN_14004a970 @ 14004a970
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14004a970(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 extraout_EAX;
  int iVar9;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined8 *puVar10;
  int iVar11;
  int iVar12;
  undefined8 uVar13;
  int iVar14;
  float *pfVar15;
  int *piVar16;
  uint *puVar17;
  int *piVar18;
  uint uVar19;
  float *pfVar20;
  short *psVar21;
  short *psVar22;
  int iVar23;
  bool bVar24;
  float fVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  undefined8 uVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  int local_res8;
  float local_res10;
  float fStackX_14;
  undefined8 in_stack_fffffffffffffe48;
  longlong lVar34;
  uint6 uVar36;
  undefined6 uVar37;
  ulonglong uVar35;
  undefined8 in_stack_fffffffffffffe50;
  ulonglong uVar38;
  undefined8 in_stack_fffffffffffffe58;
  ulonglong uVar39;
  undefined8 in_stack_fffffffffffffe60;
  double dVar40;
  double in_stack_fffffffffffffe68;
  undefined8 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uStack_154;
  undefined4 local_148;
  int local_144;
  double local_138;
  undefined8 local_128;
  undefined4 local_120;
  undefined *local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 local_f4;
  
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe48 >> 0x20);
  uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
  uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  dVar26 = (double)FUN_1403300b4((double)(DAT_140e4490c - *(float *)(param_1 + 0x2c)),
                                 SUB84((double)(DAT_140e44908 - *(float *)(param_1 + 0x28)),0));
  dVar29 = DAT_14053aba0;
  dVar33 = DAT_140539f40;
  dVar40 = (double)CONCAT44(uVar46,0x74);
  local_144 = 0;
  dVar32 = (double)CONCAT44(uVar45,0x75);
  dVar28 = (double)CONCAT44(uVar44,0x74);
  uVar19 = (uint)(dVar26 * DAT_14053aba0);
  local_148 = 0xff;
  dVar26 = (double)CONCAT44(uVar43,0x73);
  local_138 = DAT_140539f40;
  local_res8 = FUN_1400c9580(*(undefined4 *)(param_1 + 0xc),0,5,4,dVar26,dVar28,dVar32,dVar40);
  fVar1 = DAT_14053aa20;
  fVar25 = *(float *)(param_1 + 0x28);
  dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc -
                                         (*(float *)(param_1 + 0x2c) + DAT_14053aa20)),
                                 SUB84((double)(DAT_140e445d8 - fVar25),0));
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
  uVar7 = (uint)(dVar27 * dVar29);
  if ((DAT_140e419bc == 1) && ((*(int *)(param_1 + 0x1c) < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
    dVar40 = (double)(ulonglong)*(uint *)(param_1 + 0x50);
    dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
    dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),*(undefined4 *)(param_1 + 0x2c));
    dVar32 = DAT_14053a4f0;
    stage_entity_spawn_candidate(0x137,99999999,0);
    if (DAT_140e41af8 == 1) {
      FUN_1400f7530();
      _DAT_1407c777c = 0;
      uVar43 = 199;
      if (DAT_140e419b8 < 4) {
        uVar43 = 99;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar43;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      uVar43 = 0xa0;
      if (DAT_140e419b8 < 4) {
        uVar43 = 0x3c;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar43;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 3) {
      FUN_1400f7530();
      _DAT_1407c777c = 0;
      *(undefined4 *)(param_1 + 0x50) = 200;
      *(undefined4 *)(param_1 + 0x14) = 10;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 4) {
      *(undefined4 *)(param_1 + 0x50) = 200;
      *(undefined4 *)(param_1 + 0x14) = 5;
      DAT_140e419bc = 2;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (DAT_140e418c8 == (DAT_140e418c8 / 0x32) * 0x32) {
    FUN_140134c50();
    uVar8 = FUN_140134cb0();
    DAT_140e44908 = (float)(uVar8 % 0x12d + 0xd2);
    FUN_140134c50(DAT_1407c7798 * 999 + DAT_140e418c8);
    uVar8 = FUN_140134cb0();
    DAT_140e4490c = (float)(uVar8 % 0x65 + 0x96);
    if ((*(int *)(param_1 + 0x14) == 0x19) || (*(int *)(param_1 + 0x14) == 0x70)) {
      FUN_140134c50(DAT_1407c7798 * 999 + DAT_140e418c8);
      uVar8 = FUN_140134cb0();
      DAT_140e4490c = (float)(uVar8 % 0x65 + 200);
    }
  }
  uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
  pfVar20 = (float *)(param_1 + 0x2c);
  puVar17 = (uint *)(param_1 + 0xc);
  pfVar15 = (float *)(param_1 + 0x28);
  uVar44 = (undefined4)((ulonglong)dVar32 >> 0x20);
  uVar8 = (uint)((ulonglong)dVar28 >> 0x20);
  uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
  sVar5 = (short)uVar7;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    uVar38 = (ulonglong)uVar8 << 0x20;
    uVar35 = CONCAT44(uVar43,0xf0);
    FUN_1401348b0(*(undefined4 *)(param_1 + 0xc),0xb4,0xbe,0xbe,uVar35,uVar38,CONCAT44(uVar44,0xff))
    ;
    if (*(int *)(param_1 + 0xc) == 0) {
      FUN_1400f74e0(0x36,0xff);
    }
    if (*(int *)(param_1 + 0xc) == 0x50) {
      FUN_1400f74e0(0x3a,0xff);
    }
    if (*(int *)(param_1 + 0xc) == 0xb4) {
      FUN_1400f74e0(0x2f,0xff);
    }
    in_stack_fffffffffffffe68 = (double)CONCAT44(uVar45,0xff);
    dVar28 = (double)(uVar38 & 0xffffffffffff0000);
    dVar26 = (double)(uVar35 & 0xffffffff00000000);
    dVar32 = dVar33;
    dVar40 = dVar33;
    FUN_1400c8410(DAT_140e41ab8,0x58,5);
    if (*(int *)(param_1 + 0xc) == 0xf0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
LAB_14004ae40:
      FUN_1400031b0(100000,0x960);
LAB_14004ae4f:
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      DAT_140e419bc = 1;
LAB_14004ae5c:
      *(int *)(param_1 + 0x1c) = DAT_140e41b0c;
    }
    break;
  case 1:
    iVar14 = *(int *)(param_1 + 0xc);
    dVar29 = (double)FUN_140332d90(((double)iVar14 - 0.0) * _DAT_14053a6f0 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    *(float *)(param_1 + 0x28) = (float)(dVar29 * DAT_14053a1e8) + *(float *)(param_1 + 0x38);
    dVar29 = (double)FUN_140332d90();
    *(float *)(param_1 + 0x2c) = (float)(dVar29 * DAT_14053a1e8) + *(float *)(param_1 + 0x3c);
    dVar29 = DAT_140539f00;
    if (9 < iVar14) {
      uVar7 = (iVar14 + -10) % 0x640;
      sVar5 = (short)uVar7;
      if ((int)uVar7 < 0x30c) {
        dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x28);
        uVar43 = FUN_140134e80(0x5a,0x46,0x3c,0x30,dVar26);
        iVar14 = FUN_140070be0(uVar7,0,0x30c,uVar43);
        uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        if (iVar14 == 1) {
          FUN_140134d00(*(undefined4 *)(param_1 + 0xc),0x1e,0x50);
          uVar44 = (undefined4)((ulonglong)dVar26 >> 0x20);
          FUN_140134d00(*(undefined4 *)(param_1 + 0xc),0,0x10000);
          uVar30 = FUN_140133e80();
          fStackX_14 = (float)((ulonglong)uVar30 >> 0x20);
          local_res10 = (float)uVar30;
          sVar4 = FUN_140134080(local_res10 + *(float *)(param_1 + 0x28),
                                fStackX_14 + *(float *)(param_1 + 0x2c),DAT_140e445d8);
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),sVar4 + -0x8000);
          dVar26 = (double)CONCAT44(uVar44,fStackX_14);
          stage_entity_spawn_candidate(0xce,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
        iVar14 = FUN_140070be0(uVar7,0x5a,0x14a,0x1e,dVar26,dVar28,dVar32,dVar40);
        uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        if (iVar14 == 1) {
          FUN_140133e80();
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),sVar5 * -0x32 + -0x16fc);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),extraout_var);
          stage_entity_spawn_candidate(0xcf,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
        iVar14 = FUN_140070be0(uVar7,0x168,600,0x1e,dVar26,dVar28,dVar32,dVar40);
        uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        if (iVar14 == 1) {
          iVar14 = (uVar7 & 0xffff) * 0x96;
          FUN_140133e80(iVar14,0,-0x6d10 - (short)iVar14);
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),sVar5 * 0x32 + 0x6240);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),extraout_var_00);
          stage_entity_spawn_candidate(0xd0,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
      }
      uVar43 = DAT_14053b380;
      if (uVar7 - 0x32a < 300) {
        sVar4 = FUN_140134080();
        FUN_140133e80();
        sVar5 = sVar5 * 0x37 + 0x4b88;
        if (uVar7 == 0x32a) {
          in_stack_fffffffffffffe68 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),0x4000);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),uVar43);
          stage_entity_spawn_candidate(0xd3,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
        iVar14 = FUN_140070be0(uVar7,0x348,0x456,0x28,dVar26,dVar28,dVar32,dVar40);
        if (iVar14 == 1) {
          in_stack_fffffffffffffe68 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),sVar4 + sVar5 + -24000);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),extraout_var_01);
          stage_entity_spawn_candidate(0xd1,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
        iVar14 = FUN_140070be0(uVar7,0x352,0x456,0x28,dVar26,dVar28,dVar32,dVar40);
        if (iVar14 == 1) {
          in_stack_fffffffffffffe68 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),(sVar4 - sVar5) + 24000);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),extraout_var_01);
          stage_entity_spawn_candidate(0xd2,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
      }
      dVar29 = DAT_140539f00;
      if (uVar7 == 0x4d8) {
        uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        uVar37 = (undefined6)((ulonglong)dVar28 >> 0x10);
        uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
        stage_entity_spawn_candidate(0xd4,99999999,0);
        in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,1);
        dVar40 = 1.48219693752374e-322;
        dVar32 = 0.0;
        dVar28 = (double)CONCAT62(uVar37,0xc000);
        dVar26 = (double)CONCAT44(uVar43,DAT_14053b330);
        stage_entity_spawn_candidate(0xd5,99999999,0);
        FUN_1400f74e0(0x2f,0xc0);
        dVar29 = DAT_140539f00;
      }
    }
    goto LAB_14004ae87;
  case 2:
  case 3:
  case 4:
  case 7:
  case 8:
  case 9:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
    uVar43 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    dVar29 = DAT_140539f00;
    goto switchD_14004ad5e_default;
  case 5:
    if (*(int *)(param_1 + 0xc) == 1) {
      dVar32 = 0.0;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)CONCAT44(uVar43,*(undefined4 *)(param_1 + 0x2c));
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x36,0,0x28,0x1e,dVar26,dVar28,0,dVar33,dVar33,0,0xff,0xff,0xff,0xff,0);
    }
    uVar7 = (uint)((ulonglong)dVar26 >> 0x20);
    if ((int)*puVar17 < 0x78) {
      FUN_14007ac00(param_1);
    }
    uVar43 = DAT_14053ac2c;
    piVar16 = (int *)(param_1 + 0xc);
    if ((int)*puVar17 < 0x78) {
      uVar35 = (ulonglong)dVar32 & 0xffffffff00000000;
      uVar30 = CONCAT44((int)((ulonglong)dVar28 >> 0x20),DAT_14053ac2c);
      lVar34 = (ulonglong)uVar7 << 0x20;
      FUN_140134b10(*puVar17,0,0xb4,0,lVar34,uVar30,uVar35);
      uVar45 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar7 = (uint)((ulonglong)lVar34 >> 0x20);
      uVar44 = FUN_140134840(*piVar16,0,0xd);
      dVar32 = (double)(uVar35 & 0xffffffff00000000);
      dVar28 = (double)CONCAT44(uVar45,uVar43);
      uVar35 = (ulonglong)uVar7 << 0x20;
      *(undefined4 *)(param_1 + 0x28) = uVar44;
      FUN_140134b10(*piVar16,0,0xb4,0,uVar35,dVar28,dVar32);
      iVar14 = *piVar16;
      uVar30 = 7;
      dVar26 = (double)(uVar35 & 0xffffffff00000000);
    }
    else {
      uVar44 = FUN_140134840(DAT_140e418c8,0,0x97);
      iVar14 = DAT_140e418c8;
      uVar30 = 0x7f;
      *(undefined4 *)(param_1 + 0x28) = uVar44;
      dVar26 = (double)CONCAT44(uVar7,uVar43);
    }
    uVar43 = FUN_140134840(iVar14,0,uVar30);
    *(undefined4 *)(param_1 + 0x2c) = uVar43;
    if (*piVar16 == 0x96) {
      *(undefined8 *)(param_1 + 0x50) = 0x8c;
      *piVar16 = 0;
      if (*(int *)(param_1 + 0x14) == 5) goto LAB_14004ae40;
      goto LAB_14004ae4f;
    }
    break;
  case 6:
    dVar27 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a6f0 * DAT_14053a020 *
                                   DAT_140539d28);
    *(float *)(param_1 + 0x28) = (float)(dVar27 * DAT_14053a1e8) + *(float *)(param_1 + 0x38);
    dVar27 = (double)FUN_140332d90();
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    *(float *)(param_1 + 0x2c) = (float)(dVar27 * DAT_14053a1e8) + *(float *)(param_1 + 0x3c);
    if (9 < (int)*puVar17) {
      local_res10 = 0.0;
      fStackX_14 = 0.0;
      iVar14 = (int)(*puVar17 - 10) % 0x640;
      if (iVar14 == 0) {
        psVar21 = (short *)&local_108;
        uVar7 = 0;
        local_f4 = 0x8000;
        local_108 = _DAT_14053ba50;
        uStack_100 = _UNK_14053ba58;
        local_f8 = 3000;
        do {
          uVar19 = (uint)((ulonglong)dVar26 >> 0x20);
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140133e80();
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          uVar30 = 0xd6;
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),
                                    (short)uVar7 * 0x2aaa + *psVar21);
          dVar26 = (double)((ulonglong)uVar19 << 0x20);
          if ((uVar7 & 1) != 0) {
            uVar30 = 0xd7;
          }
          stage_entity_spawn_candidate(uVar30,99999999,0);
          uVar7 = uVar7 + 1;
          psVar21 = psVar21 + 2;
        } while ((int)uVar7 < 6);
        FUN_1400f74e0(0x2f,0xff);
      }
      else if (iVar14 == 0x78) {
        iVar14 = 0;
        do {
          uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
          uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc -
                                                 (fStackX_14 + *(float *)(param_1 + 0x2c))),
                                         SUB84((double)(DAT_140e445d8 -
                                                       (local_res10 + *(float *)(param_1 + 0x28))),0
                                              ));
          uVar30 = FUN_140133e80();
          local_res10 = (float)uVar30;
          fStackX_14 = (float)((ulonglong)uVar30 >> 0x20);
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),
                                    (short)(int)(dVar26 * dVar29) + -0x8000);
          dVar26 = (double)CONCAT44(uVar43,fStackX_14);
          stage_entity_spawn_candidate(0xd8,99999999,0);
          iVar14 = iVar14 + 1;
        } while (iVar14 < 6);
        FUN_1400f74e0(0x2f,0xff);
      }
      else if (0x30b < iVar14) {
        iVar11 = 1;
        if (DAT_140e419b8 == 0) {
          iVar11 = 0x3c;
        }
        else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
                (DAT_140e419b8 == 4)) {
          iVar11 = 0x28;
        }
        iVar12 = 1;
        if (DAT_140e419b8 == 0) {
          iVar12 = 10;
        }
        else if (DAT_140e419b8 == 1) {
LAB_14004b928:
          iVar12 = 8;
        }
        else {
          if (DAT_140e419b8 != 2) {
            if (DAT_140e419b8 == 3) goto LAB_14004b928;
            if (DAT_140e419b8 != 4) goto LAB_14004b936;
          }
          iVar12 = 7;
        }
LAB_14004b936:
        if ((iVar14 < 0x370) && ((iVar14 + -0x30c) % iVar11 == 0)) {
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          uVar7 = FUN_140134cb0();
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          uVar19 = FUN_140134cb0();
          uVar30 = FUN_140133e80(uVar19 % 0x51,0,uVar7 % 0x10001 & 0xffff);
          fStackX_14 = (float)((ulonglong)uVar30 >> 0x20);
          local_res10 = (float)uVar30;
          dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc -
                                                 (fStackX_14 + *(float *)(param_1 + 0x2c))),
                                         SUB84((double)(DAT_140e445d8 -
                                                       (local_res10 + *(float *)(param_1 + 0x28))),0
                                              ));
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),
                                    (short)(int)(dVar26 * dVar29) + -0x8000);
          dVar26 = (double)CONCAT44(uVar43,fStackX_14);
          stage_entity_spawn_candidate(0xce,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
        uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
        uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        if ((iVar14 - 0x398U < 0x26c) && ((int)(iVar14 - 0x398U) % iVar12 == 0)) {
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          FUN_140134cb0();
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          FUN_140134cb0();
          uVar30 = FUN_140133e80();
          fVar3 = DAT_140e445dc;
          fVar2 = DAT_140e445d8;
          fStackX_14 = (float)((ulonglong)uVar30 >> 0x20);
          local_res10 = (float)uVar30;
          fVar25 = *(float *)(param_1 + 0x2c);
          fVar1 = *(float *)(param_1 + 0x28);
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          uVar7 = FUN_140134cb0();
          dVar26 = (double)FUN_1403300b4((double)(fVar3 - (fStackX_14 + fVar25)),
                                         SUB84((double)(fVar2 - (local_res10 + fVar1)),0));
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,1);
          dVar40 = 1.48219693752374e-322;
          dVar32 = 0.0;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),
                                    (short)(int)(dVar26 * dVar29) +
                                    (short)uVar7 + (short)((ulonglong)uVar7 / 0x4651) * -0x4651 +
                                    -9000);
          dVar26 = (double)CONCAT44(uVar43,fStackX_14);
          stage_entity_spawn_candidate(0xd9,99999999,0);
          FUN_1400f74e0(0x2f,0xc0);
        }
      }
    }
    break;
  case 10:
    uVar39 = CONCAT44(uVar44,0xff);
    uVar38 = (ulonglong)uVar8 << 0x20;
    uVar35 = CONCAT44(uVar43,0x17c);
    FUN_1401348b0(*puVar17,0xf0,0xfa,0xfa,uVar35,uVar38,uVar39);
    iVar14 = 0xb9;
    if (3 < DAT_140e419b8) {
      iVar14 = 0xbb;
    }
    if (*puVar17 == 1) {
      uVar39 = 0;
      uVar38 = uVar38 & 0xffffffffffff0000;
      uVar35 = uVar35 & 0xffffffff00000000;
      dVar40 = dVar33;
      dVar32 = dVar33;
      FUN_140070d00(0x36,0,0x28);
      uVar45 = (undefined4)((ulonglong)dVar32 >> 0x20);
    }
    piVar16 = (int *)(param_1 + 0xc);
    if ((int)*puVar17 < 0x78) {
      FUN_14007ac00(param_1);
    }
    uVar44 = DAT_14053ac80;
    uVar43 = DAT_14053ac48;
    if (*piVar16 == 0x3c) {
      dVar40 = 1.25986739689518e-321;
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),DAT_14053ac80);
      uVar38 = CONCAT44((int)(uVar38 >> 0x20),DAT_14053ac48);
      uVar35 = CONCAT44((int)(uVar35 >> 0x20),DAT_14053adf4);
      FUN_14012e070(iVar14,3,0);
    }
    if (*piVar16 == 0x78) {
      dVar40 = 1.25986739689518e-321;
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),uVar44);
      uVar38 = CONCAT44((int)(uVar38 >> 0x20),uVar43);
      uVar35 = CONCAT44((int)(uVar35 >> 0x20),DAT_14053ae1c);
      FUN_14012e070(iVar14 + 1,3,0);
    }
    uVar7 = (uint)(uVar35 >> 0x20);
    piVar18 = (int *)(param_1 + 0xc);
    if (*piVar16 == 0xf0) {
      FUN_1400f74e0(0x28,0xff);
      uVar39 = 0;
      uVar38 = uVar38 & 0xffffffffffff0000;
      uVar35 = (ulonglong)uVar7 << 0x20;
      dVar40 = dVar33;
      dVar32 = dVar33;
      FUN_140070d00(0x11,0,0x28);
      uVar45 = (undefined4)((ulonglong)dVar32 >> 0x20);
      FUN_14012e890();
    }
    uVar43 = DAT_14053ac2c;
    if (*piVar18 < 0xf0) {
      uVar39 = uVar39 & 0xffffffff00000000;
      uVar30 = CONCAT44((int)(uVar38 >> 0x20),DAT_14053ac2c);
      uVar35 = uVar35 & 0xffffffff00000000;
      FUN_140134b10(*piVar18,0,0xf0,0,uVar35,uVar30,uVar39,dVar40);
      uVar46 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar7 = (uint)(uVar35 >> 0x20);
      uVar44 = FUN_140134840(DAT_140e418c8,0,0xd);
      uVar38 = CONCAT44(uVar46,uVar43);
      uVar35 = (ulonglong)uVar7 << 0x20;
      *(undefined4 *)(param_1 + 0x28) = uVar44;
      FUN_140134b10(*piVar18,0,0xf0,0,uVar35,uVar38,uVar39 & 0xffffffff00000000);
      uVar35 = uVar35 & 0xffffffff00000000;
      uVar43 = FUN_140134840(DAT_140e418c8,0,7);
      *(undefined4 *)(param_1 + 0x2c) = uVar43;
    }
    if (*piVar18 == 0x140) {
      _DAT_1407c777c = 0x3f800000;
      FUN_1400f7460(0x12,1,1);
      DAT_140e45100 = DAT_140e45148;
    }
    if (0x17b < *piVar18) {
      uVar30 = 8;
      if (3 < DAT_140e419b8) {
        uVar30 = 9;
      }
      FUN_140001900(*piVar18,0x17c,uVar30);
    }
    if (0xf9 < *(int *)(param_1 + 0xc)) {
      uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x200);
      *(undefined2 *)(param_1 + 0x40) = uVar6;
      uVar43 = FUN_140133de0();
      *(undefined4 *)(param_1 + 0x28) = uVar43;
      uVar43 = FUN_140133e30();
      *(undefined4 *)(param_1 + 0x2c) = uVar43;
    }
    in_stack_fffffffffffffe68 = (double)CONCAT44(uVar45,0xff);
    dVar28 = (double)(uVar38 & 0xffffffffffff0000);
    dVar26 = (double)(uVar35 & 0xffffffff00000000);
    dVar32 = dVar33;
    dVar40 = dVar33;
    FUN_1400c8410(DAT_140e41ab8,0x4e,5);
    if (*(int *)(param_1 + 0xc) == 0x21c) {
      iVar14 = *(int *)(param_1 + 0x14);
      *(undefined8 *)(param_1 + 0x50) = 0x50;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      if (iVar14 == 10) {
        FUN_1400031b0(200000,0x1518);
        iVar14 = *(int *)(param_1 + 0x14);
      }
      DAT_140e419bc = 1;
      if (DAT_140e419b8 < 4) {
        *(int *)(param_1 + 0x14) = iVar14 + 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 0x6f;
        FUN_1400031b0(180000,0x1518);
      }
      goto LAB_14004ae5c;
    }
  default:
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    uVar43 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    dVar29 = DAT_140539f00;
    goto switchD_14004ad5e_default;
  case 0xb:
  case 0x1b:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar29 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    if (*puVar17 == 1) {
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar32 = dVar33;
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x30,0,0x3c);
    }
    iVar14 = 1;
    if (DAT_140e419b8 == 0) {
      iVar14 = 0x13;
    }
    else if (DAT_140e419b8 == 1) {
      iVar14 = 0xf;
    }
    else if (DAT_140e419b8 == 2) {
      iVar14 = 0xd;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar14 = 0xb;
    }
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0xb;
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      iVar11 = 9;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar11 = 7;
    }
    iVar12 = 1;
    if (DAT_140e419b8 == 0) {
      iVar12 = 0x12;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0xc;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar12 = 10;
    }
    iVar23 = 1;
    if (DAT_140e419b8 == 0) {
      iVar23 = 5;
    }
    else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) ||
            ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
      iVar23 = 7;
    }
    dVar27 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
       ((DAT_140e419b8 == 2 || ((DAT_140e419b8 == 3 || (dVar27 = dVar33, DAT_140e419b8 == 4)))))) {
      dVar27 = DAT_14053a0f8;
    }
    dVar27 = (double)(*(int *)(param_1 + 0xc) + -0x46) * _DAT_140539d80 + dVar27;
    if (*(int *)(param_1 + 0x14) == 0xb) {
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar28 = _DAT_14053bb70;
      dVar32 = _UNK_14053bb78;
      uVar30 = FUN_1401349e0(*(int *)(param_1 + 0xc),0x3c,0xf0,0,dVar26,_DAT_14053bb70,
                             _UNK_14053bb78,dVar40);
      *(undefined8 *)(param_1 + 0x48) = uVar30;
    }
    uVar19 = (uint)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    uVar7 = *(int *)(param_1 + 0xc) - 0x46;
    if ((uVar7 < 0x316) && (uVar35 = (longlong)(int)uVar7 % (longlong)iVar14, (int)uVar35 == 0)) {
      uVar30 = CONCAT44((int)((ulonglong)dVar26 >> 0x20),3000);
      FUN_1401347d0(*(int *)(param_1 + 0xc),uVar35 & 0xffffffff,0x4d,20000,uVar30,dVar28,dVar32);
      uVar35 = (ulonglong)dVar28 & 0xffffffff00000000;
      uVar36 = (uint6)((ulonglong)uVar30 >> 0x10);
      FUN_1400709b0(0xc,0,fVar25);
      in_stack_fffffffffffffe68 = (double)((ulonglong)uVar19 << 0x20);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)(uVar35 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)uVar36 << 0x10);
      dVar32 = dVar27;
      FUN_1400709b0(0xc,0,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    uVar43 = DAT_14053ac2c;
    if ((*(int *)(param_1 + 0xc) - 0xbeU < 0x29e) &&
       (uVar35 = (longlong)(*(int *)(param_1 + 0xc) + -0xbe) % (longlong)iVar11, (int)uVar35 == 0))
    {
      dVar32 = dVar27 + dVar33;
      in_stack_fffffffffffffe68 =
           (double)((ulonglong)in_stack_fffffffffffffe68 & 0xffffffff00000000);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),DAT_14053ac2c);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
      FUN_1400709b0(3,uVar35 & 0xffffffff,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    uVar7 = *(int *)(param_1 + 0xc) - 0x14a;
    if ((uVar7 < 0x212) && ((int)uVar7 % (iVar12 * 6) == 0)) {
      *(short *)(param_1 + 0x42) = sVar5;
LAB_14004c47c:
      dVar29 = DAT_140539f00;
      uVar35 = (longlong)(int)uVar7 % (longlong)(iVar12 * 6);
      iVar14 = (int)uVar35;
      if ((iVar14 < iVar12 * 4) &&
         (uVar35 = (longlong)((ulonglong)(uint)(iVar14 >> 0x1f) << 0x20 | uVar35 & 0xffffffff) %
                   (longlong)(iVar12 * 2), (int)uVar35 == 0)) {
        dVar32 = dVar27 + DAT_140539f00;
        in_stack_fffffffffffffe68 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),iVar23);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),uVar43);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
        FUN_1400709b0(9,uVar35 & 0xffffffff,fVar25);
        FUN_1400f74e0(0x29,0xc0);
      }
    }
    else {
      dVar29 = DAT_140539f00;
      if (uVar7 < 0x212) goto LAB_14004c47c;
    }
    uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    iVar14 = *(int *)(param_1 + 0xc);
    if ((iVar12 + 0x14a <= iVar14) && (iVar14 < 0x35c)) {
      uVar35 = (longlong)(iVar14 - (iVar12 + 0x14a)) % (longlong)(iVar12 * 6);
      iVar14 = (int)uVar35;
      if ((iVar14 < iVar12 * 4) &&
         ((int)((longlong)((ulonglong)(uint)(iVar14 >> 0x1f) << 0x20 | uVar35 & 0xffffffff) %
               (longlong)(iVar12 * 2)) == 0)) {
        FUN_1401340c0(24000,iVar23 + -1,iVar23 + -2);
        dVar32 = dVar27 + dVar29;
        in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,iVar23 + -1);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),uVar43);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
        FUN_1400709b0(9,0,fVar25);
        FUN_1400f74e0(0x29,0xc0);
      }
    }
    if (*(int *)(param_1 + 0xc) - 0x3cU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x3c,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (*(int *)(param_1 + 0xc) - 0x46U < 0x316) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x46,5,3,dVar26,dVar28,dVar32);
    }
    if (*(int *)(param_1 + 0xc) - 0x35cU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x35c,5,2,dVar26,dVar28,dVar32);
    }
    if (*(int *)(param_1 + 0xc) == 900) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0xc;
    }
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    *(undefined4 *)(param_1 + 0x54) = 0;
    goto LAB_14004ae87;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    if (*puVar17 == 1) {
      *(undefined4 *)(param_1 + 0x54) = 1;
      switch(*(undefined4 *)(param_1 + 0x14)) {
      case 0xc:
      case 0x15:
        *(undefined4 *)(param_1 + 0x30) = 0x43e88000;
        *(undefined4 *)(param_1 + 0x34) = 0x43b90000;
        break;
      case 0xd:
      case 0x14:
        *(undefined4 *)(param_1 + 0x30) = 0x43480000;
        *(undefined4 *)(param_1 + 0x34) = 0x43480000;
        break;
      case 0xe:
      case 0x13:
        *(undefined4 *)(param_1 + 0x30) = 0x44020000;
        *(undefined4 *)(param_1 + 0x34) = 0x43480000;
        break;
      case 0xf:
      case 0x12:
        *(undefined4 *)(param_1 + 0x30) = 0x437f0000;
        *(undefined4 *)(param_1 + 0x34) = 0x43b90000;
        break;
      case 0x10:
      case 0x16:
        *(undefined4 *)(param_1 + 0x30) = 0x43b40000;
        *(undefined4 *)(param_1 + 0x34) = 0x42c80000;
      }
    }
    else if (*puVar17 == 8) {
      dVar27 = (double)FUN_1403300b4((double)(*(float *)(param_1 + 0x34) - *pfVar20),
                                     SUB84((double)(*(float *)(param_1 + 0x30) - *pfVar15),0));
      *(short *)(param_1 + 0x42) = (short)(int)(dVar27 * dVar29);
      FUN_1400f74e0(0x2f);
    }
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar28 >> 0x20);
    uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (*puVar17 == 0x10) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    iVar14 = 0x14;
    if (4 < *(int *)(param_1 + 0x14) - 0x12U) {
      iVar14 = 0x1e;
    }
    if (*puVar17 == 0x14) {
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x15;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0x1b;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar11 = 0x1f;
      }
      dVar32 = DAT_14053a0f8;
      if (DAT_140e419b8 == 0) {
LAB_14004c800:
        if (2 < DAT_140e419b8) {
LAB_14004c809:
          uVar41 = CONCAT44(uVar45,iVar11);
          uVar13 = CONCAT44(uVar44,DAT_14053b33c);
          uVar30 = CONCAT62((int6)((ulonglong)dVar26 >> 0x10),
                            (short)(0x10000 / (ulonglong)(uint)(iVar11 * 2)));
          FUN_1400709b0(5,0,*(undefined4 *)(param_1 + 0x28),0x1e,uVar30,uVar13,DAT_14053a070,1,
                        uVar41,0x10000,0);
          uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
          uVar44 = (undefined4)((ulonglong)uVar13 >> 0x20);
          uVar45 = (undefined4)((ulonglong)uVar41 >> 0x20);
        }
      }
      else {
        dVar32 = DAT_14053a138;
        if ((DAT_140e419b8 != 1) && (dVar32 = DAT_14053a178, DAT_140e419b8 != 2)) {
          if (DAT_140e419b8 != 3) {
            dVar32 = dVar33;
            if (DAT_140e419b8 == 4) {
              dVar32 = DAT_14053a178;
            }
            goto LAB_14004c800;
          }
          goto LAB_14004c809;
        }
      }
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar45,iVar11);
      dVar40 = 4.94065645841247e-324;
      FUN_1400709b0(3,0,*(undefined4 *)(param_1 + 0x28));
      FUN_1400f74e0(0x29,0xc0);
    }
    uVar35 = (ulonglong)dVar32 & 0xffffffff00000000;
    uVar38 = CONCAT44(uVar44,0xff);
    uVar30 = CONCAT44(uVar43,0x10);
    local_148 = FUN_1401348b0(*(undefined4 *)(param_1 + 0xc),0,8,8,uVar30,uVar38,uVar35,dVar40);
    dVar32 = (double)CONCAT44((int)(uVar35 >> 0x20),0xff);
    uVar38 = uVar38 & 0xffffffff00000000;
    uVar35 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),0x18);
    local_144 = FUN_1401348b0(*(undefined4 *)(param_1 + 0xc),8,0x10,0x10,uVar35,uVar38,dVar32);
    uVar43 = (undefined4)(uVar38 >> 0x20);
    if (*(int *)(param_1 + 0xc) < 8) {
      uVar43 = 0;
      uVar35 = CONCAT44((int)(uVar35 >> 0x20),8);
      dVar32 = dVar33;
      local_138 = (double)FUN_1401349e0(*(int *)(param_1 + 0xc),0,0,0,uVar35,0,dVar33);
    }
    uVar44 = (undefined4)(uVar35 >> 0x20);
    if (*(int *)(param_1 + 0xc) - 8U < 8) {
      uVar43 = 0;
      uVar35 = uVar35 & 0xffffffff00000000;
      dVar32 = dVar33;
      local_138 = (double)FUN_1401349e0(*(int *)(param_1 + 0xc),8,0x10,0,uVar35,0,dVar33);
      dVar32 = (double)((ulonglong)dVar32 & 0xffffffff00000000);
      uVar30 = CONCAT44(uVar43,DAT_14053b370);
      uVar35 = uVar35 & 0xffffffff00000000;
      FUN_140134b10(*(undefined4 *)(param_1 + 0xc),8,0x10,0,uVar35,uVar30,dVar32);
      uVar44 = (undefined4)(uVar35 >> 0x20);
      uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
      FUN_140133e80();
      *(undefined4 *)(param_1 + 0x28) = extraout_EAX;
      *(undefined4 *)(param_1 + 0x2c) = extraout_var_02;
    }
    dVar28 = (double)CONCAT44(uVar43,0x7c);
    dVar26 = (double)CONCAT44(uVar44,0x7b);
    local_res8 = FUN_1400c9580(*(undefined4 *)(param_1 + 0xc),0,5,2,dVar26,dVar28);
    if ((*(int *)(param_1 + 0xc) < 8) &&
       ((*(int *)(param_1 + 0x14) == 0xc || (*(int *)(param_1 + 0x14) == 0x12)))) {
      dVar40 = 5.73116149175846e-322;
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x75);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x74);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x73);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0,5,4,dVar26,dVar28,dVar32,0x74);
    }
    if ((7 < *(int *)(param_1 + 0xc)) &&
       ((*(int *)(param_1 + 0x14) == 0x10 || (*(int *)(param_1 + 0x14) == 0x16)))) {
      dVar40 = 5.73116149175846e-322;
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x75);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x74);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x73);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0,5,4,dVar26,dVar28,dVar32,0x74);
    }
    iVar11 = *(int *)(param_1 + 0xc);
    if (*(int *)(param_1 + 0xc) == iVar14) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(undefined8 *)(param_1 + 0x48) = 0x3fe0000000000000;
      *(undefined4 *)(param_1 + 0xc) = 0;
      iVar11 = 0;
    }
    *(uint *)(param_1 + 0x54) = (uint)(iVar11 < 0x10);
    break;
  case 0x11:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar29 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    if (*puVar17 == 0x1e) {
      uVar30 = CONCAT44((int)((ulonglong)dVar26 >> 0x20),0xf);
      iVar14 = FUN_140134e80(9,0xb,0xd,0xf,uVar30);
      uVar44 = DAT_14053ac2c;
      uVar45 = (undefined4)((ulonglong)dVar28 >> 0x20);
      uVar36 = (uint6)((ulonglong)uVar30 >> 0x10);
      FUN_1400709b0(3,0x2b,fVar25);
      FUN_1401340c0(0x10000,iVar14 * 2,1);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,iVar14);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)CONCAT44(uVar45,uVar44);
      dVar26 = (double)((ulonglong)uVar36 << 0x10);
      dVar32 = DAT_14053a1e8;
      FUN_1400709b0(3,0x2b,fVar25);
      FUN_1400f74e0(0x29,0xff);
    }
    if ((int)*puVar17 < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*puVar17,0,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (*puVar17 - 10 < 100) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*puVar17,10,5,3,dVar26,dVar28,dVar32);
    }
    iVar14 = *(int *)(param_1 + 0xc);
    if (iVar14 - 0x6eU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(iVar14,0x6e,5,2,dVar26,dVar28,dVar32);
    }
    bVar24 = *(int *)(param_1 + 0xc) == 0x8c;
    goto LAB_14004cd11;
  case 0x17:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar29 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    iVar14 = FUN_140134e80(0xf,0xc,9,7,CONCAT44(uVar43,7));
    iVar11 = FUN_140134e80(9,0xd,0xd,0xd,0xd);
    iVar11 = iVar11 + (int)(*puVar17 - 0x32) / (iVar14 * 2);
    iVar12 = FUN_140134e80(0x18,0x12,0x10,0xe,0xe);
    iVar23 = FUN_140134e80(0x12,0x14,0x16,0x16,0x16);
    dVar26 = DAT_14053a138;
    dVar27 = (double)FUN_140134ed0(DAT_14053a0d0,SUB84(DAT_14053a0f8,0),DAT_14053a118,DAT_14053a138,
                                   DAT_14053a138);
    iVar9 = FUN_140070be0(*puVar17,0x32,0xe6,iVar14 * 2);
    dVar29 = DAT_140539e20;
    if (iVar9 == 1) {
      *(short *)(param_1 + 0x42) = sVar5;
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),iVar11);
      dVar40 = 4.94065645841247e-324;
      dVar32 = (double)(int)(*puVar17 - 0x32) * dVar29 + dVar27;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
      dVar26 = (double)CONCAT62((int6)((ulonglong)dVar26 >> 0x10),sVar5);
      FUN_1400709b0(0xc,0,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
    }
    iVar14 = FUN_140070be0(*puVar17,iVar14 + 0x32,0xe6,iVar14 * 2,dVar26,dVar28,dVar32,dVar40);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar14 == 1) {
      dVar32 = (double)(int)(*puVar17 - 0x32) * dVar29 + dVar27;
      sVar4 = FUN_1401340c0(0x10000,iVar11 * 2,1);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,iVar11);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
      dVar26 = (double)CONCAT62((int6)((ulonglong)dVar26 >> 0x10),sVar4 + *(short *)(param_1 + 0x42)
                               );
      FUN_1400709b0(0xd,0,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
    }
    iVar14 = *(int *)(param_1 + 0xc);
    if (iVar14 == 0xf0) {
      *(short *)(param_1 + 0x42) = sVar5;
    }
    iVar14 = FUN_140070be0(iVar14,0xf0,0x1a4,iVar12 * 2,dVar26,dVar28,dVar32,dVar40);
    dVar29 = DAT_14053a0b0;
    if (iVar14 == 1) {
      dVar32 = dVar27 + DAT_14053a0b0;
      uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
      uVar35 = (ulonglong)dVar28 & 0xffffffff00000000;
      uVar37 = (undefined6)((ulonglong)dVar26 >> 0x10);
      FUN_1400709b0(5,0,fVar25);
      uVar35 = uVar35 & 0xffffffff00000000;
      FUN_1400709b0(5,0,fVar25);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,iVar23);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)(uVar35 & 0xffffffff00000000);
      dVar26 = (double)CONCAT62(uVar37,*(short *)(param_1 + 0x42) + 500);
      FUN_1400709b0(5,0,fVar25);
      FUN_1400f74e0(0x29,0xff);
    }
    piVar16 = (int *)(param_1 + 0xc);
    iVar14 = FUN_140070be0(*(int *)(param_1 + 0xc),iVar12 + 0xf0,0x1a4,iVar12 * 2,dVar26,dVar28,
                           dVar32,dVar40);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar14 == 1) {
      iVar14 = iVar23 * 2;
      dVar32 = dVar27 + dVar29;
      FUN_1401340c0(0x10000,iVar14,1);
      uVar35 = (ulonglong)dVar28 & 0xffffffff00000000;
      uVar36 = (uint6)((ulonglong)dVar26 >> 0x10);
      FUN_1400709b0(4,0,fVar25);
      FUN_1401340c0(0x10000,iVar14,1);
      uVar35 = uVar35 & 0xffffffff00000000;
      FUN_1400709b0(4,0,fVar25);
      FUN_1401340c0(0x10000,iVar14,1);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,iVar23);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)(uVar35 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)uVar36 << 0x10);
      FUN_1400709b0(4,0,fVar25);
      FUN_1400f74e0(0x29,0xff);
    }
    if (*piVar16 < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*piVar16,0,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (*piVar16 - 10U < 0x19a) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*piVar16,10,5,3,dVar26,dVar28,dVar32);
    }
    if (*piVar16 - 0x1a4U < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(*piVar16,0x1a4,5,2,dVar26,dVar28,dVar32);
    }
    bVar24 = *(int *)(param_1 + 0xc) == 0x1b8;
    goto LAB_14004cd11;
  case 0x18:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    FUN_140134e80(3,5,6,7,CONCAT44(uVar43,7));
    FUN_140134e80(0x457,800,0x294,0x302,0x302);
    uVar35 = DAT_14053a158;
    dVar27 = (double)FUN_140134ed0(DAT_14053a0f8,SUB84(DAT_14053a138,0));
    dVar29 = DAT_140539f00;
    iVar14 = 0x1e;
    if ((int)*puVar17 < 0xdc) {
      iVar14 = 0x32;
    }
    uVar35 = uVar35 & 0xffffffff00000000;
    dVar28 = DAT_140539f00;
    dVar32 = DAT_14053a018;
    uVar30 = FUN_1401349e0(*puVar17,0,0x78,0,uVar35,DAT_140539f00,DAT_14053a018);
    uVar43 = (undefined4)(uVar35 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar28 >> 0x20);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    iVar11 = FUN_140070be0(*puVar17,0x14,0xdc,iVar14);
    if ((iVar11 == 1) || (iVar11 = FUN_140070be0(*puVar17,0xdc,0x154,iVar14), iVar11 != 0)) {
      *(short *)(param_1 + 0x42) = sVar5;
    }
    iVar11 = iVar14 * 2;
    uVar13 = CONCAT44(uVar44,3);
    uVar30 = CONCAT44(uVar43,0x28);
    iVar12 = FUN_140070c10(*puVar17,0x14,0xdc,iVar11,uVar30,uVar13);
    uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
    uVar44 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar7 = (uint)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar12 == 1) {
LAB_14004d4d0:
      in_stack_fffffffffffffe68 = (double)((ulonglong)uVar7 << 0x20);
      dVar40 = 4.94065645841247e-324;
      *(short *)(param_1 + 0x42) = sVar5;
      dVar32 = dVar27;
      FUN_1400709b0(2,0x2c,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
    }
    else {
      uVar13 = CONCAT44(uVar44,3);
      uVar30 = CONCAT44(uVar43,0x19);
      iVar12 = FUN_140070c10(*puVar17,0xdc,0x154,iVar11,uVar30,uVar13);
      uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
      uVar44 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar7 = (uint)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
      if (iVar12 == 1) goto LAB_14004d4d0;
    }
    dVar28 = (double)CONCAT44(uVar44,3);
    dVar26 = (double)CONCAT44(uVar43,0x28);
    iVar12 = FUN_140070c10(*(undefined4 *)(param_1 + 0xc),iVar14 + 0x14,0xdc,iVar11,dVar26,dVar28,
                           dVar32,dVar40);
    uVar7 = (uint)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar12 == 1) {
LAB_14004d5a0:
      *(short *)(param_1 + 0x42) = sVar5;
      in_stack_fffffffffffffe68 = (double)((ulonglong)uVar7 << 0x20);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
      FUN_1400709b0(3,0x2d,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
      dVar32 = dVar27;
    }
    else {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),3);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x19);
      iVar14 = FUN_140070c10(*(undefined4 *)(param_1 + 0xc),iVar14 + 0xdc,0x154,iVar11,dVar26,dVar28
                             ,dVar32);
      uVar7 = (uint)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
      if (iVar14 == 1) goto LAB_14004d5a0;
    }
    piVar16 = (int *)(param_1 + 0xc);
    if (*piVar16 < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*piVar16,0,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (9 < *piVar16) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*piVar16,10,5,3,dVar26,dVar28,dVar32);
    }
    bVar24 = *piVar16 == 0x15e;
    goto LAB_14004d695;
  case 0x19:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    uVar30 = CONCAT44(uVar43,6);
    uVar43 = FUN_140134e80(8,7,7,6,uVar30);
    uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),0x6f1);
    sVar5 = FUN_140134e80(0x6f1,0x6f1,0x6f1,0x6f1,uVar30);
    uVar35 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),10);
    uVar44 = FUN_140134e80(10,10,10,10,uVar35);
    dVar29 = DAT_140539f00;
    uVar35 = uVar35 & 0xffffffff00000000;
    dVar32 = DAT_14053a018;
    dVar28 = DAT_140539f00;
    uVar30 = FUN_1401349e0(*puVar17,0,0x3c,0,uVar35,DAT_14053a018,DAT_140539f00);
    psVar21 = (short *)(param_1 + 0x42);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    if (*puVar17 == 0x1e) {
      sVar4 = FUN_140134080();
      *psVar21 = sVar4;
    }
    iVar14 = FUN_140070be0(*puVar17,0x1e,0x2d0,uVar43);
    dVar26 = DAT_14053a0f8;
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
      dVar40 = 4.94065645841247e-324;
      dVar32 = (double)((ulonglong)dVar32 & 0xffffffff00000000);
      uVar35 = CONCAT62((int6)(uVar35 >> 0x10),*psVar21);
      dVar28 = DAT_14053a0f8;
      FUN_1400709b0(4,0x2e,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    piVar16 = (int *)(param_1 + 0xc);
    iVar14 = FUN_140070be0(*piVar16,0x334,900,uVar44,uVar35,dVar32,dVar28,dVar40);
    uVar43 = (undefined4)(uVar35 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar32 >> 0x20);
    uVar45 = (undefined4)((ulonglong)dVar28 >> 0x20);
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),3);
      dVar40 = 4.94065645841247e-324;
      FUN_1400709b0(4,0x2e,fVar25);
      uVar45 = (undefined4)((ulonglong)dVar26 >> 0x20);
      FUN_1400f74e0(0x29,0xc0);
    }
    if (*piVar16 < 800) {
      sVar5 = 0xe6;
    }
    dVar32 = (double)CONCAT44(uVar45,0x7a);
    dVar28 = (double)CONCAT44(uVar44,0x79);
    *psVar21 = *psVar21 + sVar5;
    dVar26 = (double)CONCAT44(uVar43,0x78);
    local_res8 = FUN_1400c9580(*piVar16,0,5,3,dVar26,dVar28,dVar32,dVar40);
    if (*piVar16 != 0x460) goto LAB_14004d69d;
    *piVar16 = 0;
    goto LAB_14004d69a;
  case 0x1a:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    uVar43 = FUN_140134e80(10,8,8,7,CONCAT44(uVar43,7));
    iVar14 = FUN_140134e80(6,10,0xc,0xc,0xc);
    dVar32 = DAT_14053a178;
    dVar27 = (double)FUN_140134ed0(DAT_14053a110,SUB84(DAT_14053a138,0),DAT_14053a158,DAT_14053a178,
                                   DAT_14053a178);
    dVar29 = DAT_140539f00;
    dVar26 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x47e);
    dVar28 = DAT_14053a018;
    dVar32 = DAT_140539f00;
    uVar30 = FUN_1401349e0(*puVar17,0,0,0,dVar26,DAT_14053a018,DAT_140539f00);
    psVar21 = (short *)(param_1 + 0x42);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    if (*puVar17 == 1) {
      *psVar21 = sVar5;
      *(short *)(param_1 + 0x44) = sVar5;
    }
    iVar11 = FUN_140070be0(*puVar17,1,0x96,uVar43);
    dVar31 = DAT_140539f90;
    uVar44 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar11 == 1) {
      uVar38 = CONCAT44((int)((ulonglong)dVar28 >> 0x20),0xffff);
      uVar35 = (ulonglong)dVar26 & 0xffffffff00000000;
      FUN_1401348b0(*puVar17,0,0x96,0,uVar35,uVar38,0x10000 / (longlong)iVar14 & 0xffffffff);
      uVar38 = uVar38 & 0xffffffff00000000;
      uVar37 = (undefined6)(uVar35 >> 0x10);
      FUN_1400709b0(4,0,fVar25);
      dVar32 = dVar27 - dVar31;
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar44,2);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)(uVar38 & 0xffffffff00000000);
      dVar26 = (double)CONCAT62(uVar37,*(short *)(param_1 + 0x44));
      FUN_1400709b0(1,0,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    iVar11 = FUN_140070be0(*(int *)(param_1 + 0xc),0x96,0x460,uVar43,dVar26,dVar28,dVar32,dVar40);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar11 == 1) {
      FUN_1401340c0(0x10000,iVar14 * 2,1);
      uVar35 = (ulonglong)dVar28 & 0xffffffff00000000;
      uVar36 = (uint6)((ulonglong)dVar26 >> 0x10);
      FUN_1400709b0(4,0,fVar25);
      FUN_1401340c0(0x10000,iVar14 * 2,1);
      dVar32 = dVar27 - dVar31;
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,iVar14);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)(uVar35 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)uVar36 << 0x10);
      FUN_1400709b0(1,0,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    psVar22 = (short *)(param_1 + 0x44);
    iVar14 = *(int *)(param_1 + 0xc);
    if ((iVar14 < 0xb4) || (*psVar21 = *psVar21 + (short)((iVar14 + -0xb4) / 2), iVar14 < 0xdc)) {
      if (iVar14 < 0x96) {
        uVar13 = CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x40);
        uVar30 = CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x500);
        uVar35 = (ulonglong)dVar26 & 0xffffffff00000000;
        uVar43 = FUN_1401348b0(iVar14,0,0x96,0,uVar35,uVar30,uVar13,dVar40);
        uVar44 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar45 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar6 = FUN_140134640(uVar7 & 0xffff,*(undefined2 *)(param_1 + 0x42),uVar43);
        *(undefined2 *)(param_1 + 0x42) = uVar6;
        dVar32 = (double)CONCAT44(uVar45,0x40);
        dVar28 = (double)CONCAT44(uVar44,0x500);
        dVar26 = (double)(uVar35 & 0xffffffff00000000);
        uVar43 = FUN_1401348b0(*(undefined4 *)(param_1 + 0xc),0,0x96,0,dVar26,dVar28,dVar32);
        sVar5 = FUN_140134640(uVar7 & 0xffff,*psVar22,uVar43);
        *psVar22 = sVar5;
      }
    }
    else {
      *psVar22 = *psVar22 - (short)((iVar14 + -0xdc) / 2);
    }
    if (*(int *)(param_1 + 0xc) < 0x460) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0,5,3,dVar26,dVar28,dVar32);
    }
    iVar14 = *(int *)(param_1 + 0xc);
    if (iVar14 - 0x460U < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(iVar14,0x460,5,2,dVar26,dVar28,dVar32);
    }
    bVar24 = *(int *)(param_1 + 0xc) == 0x47e;
LAB_14004d695:
    if (bVar24) {
      *(undefined4 *)(param_1 + 0xc) = 0;
LAB_14004d69a:
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
    goto LAB_14004d69d;
  case 0x3c:
  case 0xa0:
    if (*puVar17 == 0) {
      FUN_1400f74e0(0x26,0xff);
      dVar32 = 0.0;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x36,0,0x28);
      *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)pfVar15;
      *(undefined8 *)(param_1 + 0x48) = 0x3fd3333333333333;
    }
    piVar16 = (int *)(param_1 + 0xc);
    if ((int)*puVar17 < 0x32) {
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),DAT_14053acfc);
      FUN_140134840(*puVar17,0,0x6c);
      sVar5 = FUN_140134d00(DAT_140e418c8 - *puVar17,0xffffeea4,0x115c);
      uVar30 = FUN_140133e80(0x4000,*(undefined4 *)(param_1 + 0x34),sVar5 + -0x4000);
      local_res10 = (float)uVar30;
      fStackX_14 = (float)((ulonglong)uVar30 >> 0x20);
      *pfVar15 = local_res10;
      *(float *)(param_1 + 0x2c) = fStackX_14;
    }
    else {
      uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
      *(undefined2 *)(param_1 + 0x40) = uVar6;
      fVar25 = (float)FUN_140133de0();
      *pfVar15 = fVar25;
      fVar25 = (float)FUN_140133e30();
      *pfVar20 = fVar25;
    }
    if (*piVar16 < 0x6e) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x80);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x7f);
      local_res8 = FUN_1400c9580(*piVar16,0,5,2,dVar26,dVar28);
    }
    if (*piVar16 - 0x6eU < 0xb) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x7d);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x7e);
      local_res8 = FUN_1400c9580(*piVar16,0x6e,5,2,dVar26,dVar28);
    }
    if (0x77 < *piVar16) {
      dVar40 = 5.73116149175846e-322;
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x75);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x74);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x73);
      local_res8 = FUN_1400c9580(*piVar16,0,5,4,dVar26,dVar28,dVar32,0x74);
    }
    if (*(int *)(param_1 + 0xc) == 0x96) {
      *(int *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      if (*(int *)(param_1 + 0x14) == 0x3c) {
        FUN_1400031b0(150000,6000);
      }
      if (*(int *)(param_1 + 0x14) == 0xa0) {
        FUN_1400031b0(180000,0x1e00);
      }
      iVar14 = DAT_140e41b0c;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x1c) = iVar14;
      DAT_140e419bc = 1;
    }
    break;
  case 0x3d:
  case 0x3e:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar29 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    if ((*puVar17 < 0x3d) && ((0x1000000040000002U >> ((longlong)(int)*puVar17 & 0x3fU) & 1) != 0))
    {
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar32 = dVar33;
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x30,0,0x3c);
    }
    dVar31 = DAT_14053b1f0;
    dVar27 = DAT_14053a598;
    uVar7 = *puVar17;
    dVar29 = DAT_140539f00;
    if (99 < (int)uVar7) {
      iVar11 = (int)(uVar7 - 0x154) % 0x168;
      iVar14 = (int)(uVar7 - 100) % 0x168;
      if (iVar14 == 0) {
        iVar12 = 0;
        do {
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          uVar7 = FUN_140134cb0();
          if ((uVar7 & 1) == 0) {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xda;
            FUN_140134cb0();
            dVar32 = dVar27;
          }
          else {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdb;
            FUN_140134cb0();
            dVar32 = dVar31;
          }
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),(short)iVar12 * 0x4000);
          dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
          stage_entity_spawn_candidate(uVar30,99999999,0);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 4);
        FUN_1400f74e0(0x2f,0xff);
      }
      if ((*(int *)(param_1 + 0x14) == 0x3e) && (iVar14 == 0xb4)) {
        iVar12 = 0;
        do {
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
          uVar7 = FUN_140134cb0();
          if ((uVar7 & 1) == 0) {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdc;
            FUN_140134cb0();
            dVar32 = dVar27;
          }
          else {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdd;
            FUN_140134cb0();
            dVar32 = dVar31;
          }
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),(short)iVar12 * 0x4000);
          dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
          stage_entity_spawn_candidate(uVar30,99999999,0);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 4);
        FUN_1400f74e0(0x2f,0xff);
      }
      dVar29 = DAT_140539f00;
      if (*(int *)(param_1 + 0x14) == 0x3d) {
        if (0x153 < *(int *)(param_1 + 0xc)) {
          iVar12 = 1;
          if (DAT_140e419b8 == 0) {
            iVar12 = 0x10;
          }
          else if (DAT_140e419b8 == 1) {
            iVar12 = 10;
          }
          else if (DAT_140e419b8 == 2) {
            iVar12 = 8;
          }
          else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
            iVar12 = 6;
          }
          dVar29 = DAT_14053a0d0;
          if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) &&
              (dVar29 = DAT_14053a118, DAT_140e419b8 != 2)) &&
             ((DAT_140e419b8 == 3 || (dVar29 = dVar33, DAT_140e419b8 == 4)))) {
            dVar29 = DAT_14053a138;
          }
          if ((0x1e - iVar11) * 10 != (iVar11 + -0x1e) * 10) {
            FUN_140134c50(*(int *)(param_1 + 0xc));
            FUN_140134cb0();
          }
          if (iVar11 == 0) {
            dVar32 = 0.0;
            dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
            dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),fVar1);
            dVar40 = _DAT_14053bbb0;
            in_stack_fffffffffffffe68 = _UNK_14053bbb8;
            FUN_140070d00(0x31,DAT_140e41a50,0x23);
            FUN_1400f74e0(0x30,0xff);
          }
          else {
            if (iVar11 == 0x1e) {
              *(short *)(param_1 + 0x42) = sVar5;
            }
            else if (99 < iVar11 - 0x1eU) goto LAB_14004f85b;
            if ((iVar11 + -0x1e) % (iVar12 * 2) == 0) {
              in_stack_fffffffffffffe68 =
                   (double)((ulonglong)in_stack_fffffffffffffe68 & 0xffffffff00000000);
              dVar40 = 4.94065645841247e-324;
              dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
              dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
              dVar32 = dVar29;
              FUN_1400709b0(2,1,fVar25);
              FUN_1400f74e0(0x2a,0xc0);
            }
          }
LAB_14004f85b:
          if (((iVar12 + 0x1e <= iVar11) && (iVar11 < 0x82)) &&
             ((iVar11 - (iVar12 + 0x1e)) % (iVar12 * 2) == 0)) {
            in_stack_fffffffffffffe68 =
                 (double)((ulonglong)in_stack_fffffffffffffe68 & 0xffffffff00000000);
            dVar40 = 4.94065645841247e-324;
            dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
            dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
            FUN_1400709b0(2,1,fVar25);
            FUN_1400f74e0(0x2a,0xc0);
            dVar32 = dVar29;
          }
        }
        dVar29 = DAT_140539f00;
        if (((*(int *)(param_1 + 0x14) == 0x3d) &&
            (*(int *)(param_1 + 0x1c) < (int)((double)DAT_140e41b0c * DAT_140539f00))) &&
           (iVar14 == 0xaa)) {
          *(undefined4 *)(param_1 + 0x14) = 0x3e;
        }
      }
    }
    if (*(int *)(param_1 + 0xc) - 0x5aU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x5a,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (99 < *(int *)(param_1 + 0xc)) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),100,5,3,dVar26,dVar28,dVar32);
    }
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    goto LAB_14004ae87;
  case 99:
  case 199:
    FUN_140003e60(param_1);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    if ((int)*puVar17 < 0xf0) {
      FUN_14007ac00(param_1);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x80);
      dVar26 = (double)CONCAT44(uVar43,0x7f);
      *pfVar20 = *pfVar20 + DAT_140539cec;
      local_res8 = FUN_1400c9580(*puVar17,0,5,2,dVar26,dVar28);
    }
    else {
      local_148 = 0;
    }
    uVar7 = (uint)((ulonglong)dVar26 >> 0x20);
    if (*puVar17 == 0xf0) {
      FUN_1400f74e0(0x28,0xff);
      dVar32 = 0.0;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)((ulonglong)uVar7 << 0x20);
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x10,0,0x28);
    }
    break;
  case 0x6f:
  case 0x75:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    if (*puVar17 == 1) {
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x30,0,0x3c);
    }
    dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
    dVar31 = (double)(int)(*puVar17 - 0x46) * DAT_140539d60 + _DAT_14053a1e0;
    dVar28 = _DAT_14053bb40;
    dVar32 = _UNK_14053bb48;
    uVar30 = FUN_1401349e0(*puVar17,0x3c,0x1e0,0,dVar26,_DAT_14053bb40,_UNK_14053bb48,dVar40);
    dVar27 = DAT_14053a020;
    dVar29 = DAT_140539d28;
    uVar7 = *puVar17;
    uVar43 = SUB84(DAT_14053a020,0);
    uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    dVar29 = (double)FUN_140332d90(((double)(int)uVar7 - _DAT_14053b168) * _DAT_14053a498 * dVar27 *
                                   dVar29);
    sVar5 = (short)(int)(dVar29 * DAT_14053ac08) + 0x4000;
    *(short *)(param_1 + 0x42) = sVar5;
    dVar29 = (double)FUN_140332d90();
    uVar7 = uVar7 - 0x46;
    *(short *)(param_1 + 0x44) = (short)(int)(dVar29 * DAT_14053ac08) + -0x8000;
    if ((uVar7 < 0xf0) && (uVar7 = (int)uVar7 % 0x28, (int)uVar7 < 0x14)) {
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        in_stack_fffffffffffffe68 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0xb);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
        dVar26 = (double)CONCAT62((int6)((ulonglong)dVar26 >> 0x10),sVar5);
        dVar32 = dVar31;
        FUN_1400709b0(0xd,0,fVar25);
        FUN_1400f74e0(0x29,0xc0);
      }
    }
    uVar7 = *(int *)(param_1 + 0xc) - 0x5a;
    if ((uVar7 < 0xdc) && (uVar7 = (int)uVar7 % 0x28, (int)uVar7 < 0x14)) {
      uVar7 = uVar7 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        in_stack_fffffffffffffe68 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0xb);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
        dVar32 = dVar31;
        FUN_1400709b0(0xc,0,fVar25);
        FUN_1400f74e0(0x29,0xc0);
      }
    }
    uVar7 = *(int *)(param_1 + 0xc) - 0x136;
    if (uVar7 < 0x19a) {
      uVar7 = uVar7 & 0x80000007;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
      }
      if (uVar7 == 0) {
        in_stack_fffffffffffffe68 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0x16);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
        dVar32 = dVar31;
        FUN_1400709b0(0xd,0,fVar25);
        FUN_1400f74e0(0x29,0xc0);
      }
    }
    uVar7 = *(int *)(param_1 + 0xc) - 0x13a;
    if (uVar7 < 0x196) {
      uVar7 = uVar7 & 0x80000007;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
      }
      if (uVar7 == 0) {
        in_stack_fffffffffffffe68 =
             (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0x16);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
        FUN_1400709b0(0xc,0,fVar25);
        FUN_1400f74e0(0x29,0xc0);
        dVar32 = dVar31;
      }
    }
    dVar29 = DAT_14053a1e8;
    if (*(int *)(param_1 + 0xc) == 0x2d0) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0x16);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
      dVar32 = DAT_14053a1e8;
      FUN_1400709b0(2,0x2f,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
    }
    if (*(int *)(param_1 + 0xc) == 800) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0x16);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
      FUN_1400709b0(3,0x30,fVar25);
      FUN_1400f74e0(0x2a,0xc0);
      dVar32 = dVar29;
    }
    if (*(int *)(param_1 + 0xc) - 0x3cU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x3c,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (*(int *)(param_1 + 0xc) - 0x46U < 0x316) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x46,5,3,dVar26,dVar28,dVar32);
    }
    if (*(int *)(param_1 + 0xc) - 0x35cU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x35c,5,2,dVar26,dVar28,dVar32);
    }
    if (*(int *)(param_1 + 0xc) == 900) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0x70;
    }
    dVar29 = DAT_140539f00;
    *(undefined4 *)(param_1 + 0x54) = 0;
    goto switchD_14004ad5e_default;
  case 0x70:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar28 = (double)FUN_140332d90();
    dVar32 = DAT_140539fc8;
    dVar29 = DAT_140539f00;
    dVar26 = (double)CONCAT44(uVar43,0x3c);
    *pfVar20 = (float)(dVar28 * *(double *)(param_1 + 0x48)) + *pfVar20;
    dVar28 = dVar29;
    uVar30 = FUN_1401349e0(*puVar17,0,0,0,dVar26,dVar29,dVar32);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    if (*puVar17 == 0x14) {
      uVar6 = FUN_140134080();
      *(undefined2 *)(param_1 + 0x42) = uVar6;
    }
    iVar14 = FUN_140070be0(*puVar17,0x14,500,2);
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
      dVar40 = 4.94065645841247e-324;
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),DAT_14053ac2c);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
      dVar32 = DAT_14053a160;
      FUN_1400709b0(0xb,0x31,fVar25);
      FUN_1400f74e0(0x29,0x80);
    }
    piVar16 = (int *)(param_1 + 0xc);
    iVar14 = *piVar16;
    if (iVar14 < 0x10e) {
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 0x280;
      if (iVar14 < 10) {
        dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
        dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
        local_res8 = FUN_1400c9580(iVar14,0,5,2,dVar26,dVar28,dVar32,dVar40);
      }
    }
    else {
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + -0x280;
    }
    if (9 < *piVar16) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*piVar16,10,5,3,dVar26,dVar28,dVar32);
    }
    if (*piVar16 == 0x244) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      goto LAB_14004d69a;
    }
    goto LAB_14004d69d;
  case 0x71:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    uVar30 = DAT_140539fe8;
    dVar29 = DAT_140539f00;
    uVar35 = (ulonglong)dVar26 & 0xffffffff00000000;
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    dVar32 = dVar29;
    uVar13 = FUN_1401349e0(*puVar17,0,0xb4,0,uVar35,dVar29,uVar30);
    *(undefined8 *)(param_1 + 0x48) = uVar13;
    if (*puVar17 == 0x14) {
      sVar5 = FUN_140134080();
      *(short *)(param_1 + 0x42) = sVar5 + -0x4000;
    }
    iVar14 = FUN_140070be0(*puVar17,0x14,0x21c,6);
    uVar13 = DAT_14053a228;
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
      dVar40 = 4.94065645841247e-324;
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),DAT_14053ac2c);
      uVar35 = CONCAT62((int6)(uVar35 >> 0x10),*(short *)(param_1 + 0x42));
      uVar30 = DAT_14053a228;
      FUN_1400709b0(2,0x32,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    piVar16 = (int *)(param_1 + 0xc);
    if (*piVar16 == 0x99) {
      sVar5 = FUN_140134080();
      *(short *)(param_1 + 0x44) = sVar5 + 0x4000;
    }
    iVar14 = FUN_140070be0(*piVar16,0x99,0x21c,6,uVar35,dVar32,uVar30);
    uVar43 = (undefined4)(uVar35 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar32 >> 0x20);
    uVar45 = (undefined4)((ulonglong)uVar30 >> 0x20);
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),1);
      dVar40 = 4.94065645841247e-324;
      FUN_1400709b0(3,0x32,fVar25);
      uVar45 = (undefined4)((ulonglong)uVar13 >> 0x20);
      FUN_1400f74e0(0x29,0xc0);
    }
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 0x29a;
    dVar32 = (double)CONCAT44(uVar45,0x7a);
    *(short *)(param_1 + 0x44) = *(short *)(param_1 + 0x44) + -0x29a;
    dVar28 = (double)CONCAT44(uVar44,0x79);
    dVar26 = (double)CONCAT44(uVar43,0x78);
    local_res8 = FUN_1400c9580(*piVar16,0,5,3,dVar26,dVar28,dVar32,dVar40);
    if (*piVar16 == 600) {
      *piVar16 = 0;
      goto LAB_14004d69a;
    }
LAB_14004d69d:
    uVar45 = SUB84(DAT_140539d28,0);
    uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    *(undefined4 *)(param_1 + 0x54) = 0;
    goto LAB_14004ae87;
  case 0x72:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar28 >> 0x20);
    uVar45 = (undefined4)((ulonglong)dVar32 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    uVar30 = 0x10;
    if ((int)*puVar17 < 0xbe) {
      uVar30 = 0x20;
    }
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    iVar14 = FUN_140070be0(*puVar17,10,500,uVar30);
    uVar46 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar14 == 1) {
      FUN_140134d00(*puVar17,0,0x10000);
      dVar32 = DAT_14053a0f8;
      FUN_1400709b0(3,0x2c,fVar25);
      FUN_140134d00(*puVar17,0,0x10000);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar46,0x15);
      dVar40 = 4.94065645841247e-324;
      FUN_1400709b0(2,0x2d,fVar25);
      uVar45 = (undefined4)((ulonglong)dVar32 >> 0x20);
      FUN_1400f74e0(0x29,0xc0);
    }
    dVar32 = (double)CONCAT44(uVar45,0x7a);
    dVar28 = (double)CONCAT44(uVar44,0x79);
    dVar26 = (double)CONCAT44(uVar43,0x78);
    local_res8 = FUN_1400c9580(*puVar17,0,5,3,dVar26,dVar28,dVar32,dVar40);
    if (*puVar17 == 0x230) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *puVar17 = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      break;
    }
    goto LAB_14004cd19;
  case 0x73:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300,0x1e,dVar26,dVar28,
                          dVar32);
    uVar43 = (undefined4)((ulonglong)dVar26 >> 0x20);
    uVar44 = (undefined4)((ulonglong)dVar28 >> 0x20);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar29 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    sVar5 = FUN_140134080();
    uVar7 = *puVar17;
    dVar29 = (double)(int)uVar7 * DAT_140539dc8 + DAT_14053a1d0;
    iVar14 = FUN_140070be0(uVar7,10,0x226,0x1e);
    if (iVar14 == 1) {
      *(short *)(param_1 + 0x42) = sVar5;
    }
    uVar13 = CONCAT44(uVar44,3);
    uVar30 = CONCAT44(uVar43,0x18);
    iVar14 = FUN_140070c10(*puVar17,10,0x226,0x3c,uVar30,uVar13);
    uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
    uVar44 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if (iVar14 == 1) {
      uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
      FUN_1400709b0(0xb,0,fVar25);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar45,6);
      dVar40 = 4.94065645841247e-324;
      dVar32 = dVar29;
      FUN_1400709b0(0xb,0,fVar25);
      FUN_1400f74e0(0x29,0xc0);
    }
    piVar16 = (int *)(param_1 + 0xc);
    uVar35 = CONCAT44(uVar44,3);
    uVar30 = CONCAT44(uVar43,0x18);
    iVar14 = FUN_140070c10(*piVar16,0x28,0x226,0x3c,uVar30,uVar35,dVar32,dVar40);
    uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
    if (iVar14 == 1) {
      FUN_1401340c0(0x8000,5,4);
      uVar35 = uVar35 & 0xffffffff00000000;
      uVar37 = (undefined6)((ulonglong)uVar30 >> 0x10);
      FUN_1400709b0(0xb,0,fVar25);
      FUN_1401340c0(0x8000,5,4);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,5);
      dVar40 = 4.94065645841247e-324;
      uVar35 = uVar35 & 0xffffffff00000000;
      uVar30 = CONCAT62(uVar37,*(short *)(param_1 + 0x42) +
                               ((short)(uVar7 - 10) + (short)((int)(uVar7 - 10) / 0x1e) * -0x1e) *
                               -0x3c);
      FUN_1400709b0(0xb,0,fVar25);
      FUN_1400f74e0(0x29,0xc0);
      dVar32 = dVar29;
    }
    iVar14 = FUN_140070be0(*piVar16,0x46,0x226,0x3c,uVar30,uVar35,dVar32,dVar40);
    if (iVar14 == 1) {
      in_stack_fffffffffffffe68 =
           (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0xd);
      dVar40 = 4.94065645841247e-324;
      uVar35 = uVar35 & 0xffffffff00000000;
      uVar30 = CONCAT62((int6)((ulonglong)uVar30 >> 0x10),sVar5 + -0x8000);
      dVar32 = DAT_14053a110;
      FUN_1400709b0(0xc,0x33,fVar25);
    }
    iVar14 = FUN_140070be0(*piVar16,0x82,0x226,0x1e,uVar30,uVar35,dVar32,dVar40);
    uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
    uVar44 = (undefined4)(uVar35 >> 0x20);
    uVar45 = (undefined4)((ulonglong)dVar32 >> 0x20);
    if (iVar14 == 1) {
      uVar45 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
      FUN_1400709b0(5,0,fVar25);
      in_stack_fffffffffffffe68 = (double)CONCAT44(uVar45,0x11);
      dVar40 = 4.94065645841247e-324;
      uVar30 = DAT_14053a190;
      FUN_1400709b0(5,0,fVar25);
      uVar45 = (undefined4)((ulonglong)uVar30 >> 0x20);
      FUN_1400f74e0(0x2a,0x80);
    }
    dVar32 = (double)CONCAT44(uVar45,0x7a);
    dVar28 = (double)CONCAT44(uVar44,0x79);
    dVar26 = (double)CONCAT44(uVar43,0x78);
    local_res8 = FUN_1400c9580(*piVar16,0,5,3,dVar26,dVar28,dVar32,dVar40);
    bVar24 = *piVar16 == 600;
LAB_14004cd11:
    if (bVar24) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
LAB_14004cd19:
    *(undefined4 *)(param_1 + 0x54) = 0;
    break;
  case 0x74:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300,0x1e,dVar26,dVar28,
                          dVar32);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar32 = (double)FUN_140332d90();
    *pfVar20 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar20;
    dVar28 = (double)CONCAT44(_UNK_14053ba94,_DAT_14053ba90);
    dVar32 = (double)CONCAT44(_UNK_14053ba9c,_UNK_14053ba98);
    dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
    uVar30 = FUN_1401349e0(*puVar17,600,0x47e,0,dVar26,dVar28,dVar32);
    uVar7 = *puVar17;
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    iVar14 = (0xb3 < (int)uVar7) + 3;
    if (0x167 < (int)uVar7) {
      iVar14 = 5;
    }
    if (599 < (int)uVar7) {
      iVar14 = 6;
    }
    dVar29 = (double)(int)uVar7 * _DAT_140539d68 + DAT_14053a018;
    if ((int)uVar7 < 0x348) {
      if (uVar7 == 10) {
        *(undefined2 *)(param_1 + 0x42) = 0;
      }
    }
    else {
      iVar14 = 7;
    }
    iVar11 = FUN_140070be0(uVar7,10,0x460,2);
    if (iVar11 == 1) {
      iVar11 = 0;
      do {
        uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
        dVar32 = (double)iVar11 + (double)iVar11 + dVar29;
        uVar35 = (ulonglong)dVar28 & 0xffffffff00000000;
        uVar36 = (uint6)((ulonglong)dVar26 >> 0x10);
        FUN_1400709b0(5,0,fVar25);
        in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
        dVar40 = 4.94065645841247e-324;
        dVar28 = (double)(uVar35 & 0xffffffff00000000);
        dVar26 = (double)((ulonglong)uVar36 << 0x10);
        FUN_1400709b0(4,0,fVar25);
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar14);
      FUN_1400f74e0(0x29,0xc0);
    }
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + (short)uVar7 + 999;
    if (*(int *)(param_1 + 0xc) < 0x460) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0,5,3,dVar26,dVar28,dVar32,dVar40);
    }
    if (*(int *)(param_1 + 0xc) - 0x460U < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x76);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x77);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x460,5,2,dVar26,dVar28,dVar32);
    }
    if (*(int *)(param_1 + 0xc) != 0x47e) goto LAB_14004cd19;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    break;
  case 0xa1:
    uVar6 = FUN_140134640(uVar19 & 0xffff,*(undefined2 *)(param_1 + 0x40),0x300,0x1e,dVar26,dVar28,
                          dVar32);
    *(undefined2 *)(param_1 + 0x40) = uVar6;
    dVar32 = (double)FUN_1403307c0();
    *pfVar15 = (float)(dVar32 * *(double *)(param_1 + 0x48)) + *pfVar15;
    dVar29 = (double)FUN_140332d90();
    dVar32 = _UNK_14053bb68;
    dVar28 = _DAT_14053bb60;
    iVar14 = 0;
    dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
    *pfVar20 = (float)(dVar29 * *(double *)(param_1 + 0x48)) + *pfVar20;
    uVar30 = FUN_1401349e0(*puVar17,0,300,0,dVar26,dVar28,dVar32);
    *(undefined8 *)(param_1 + 0x48) = uVar30;
    if ((*puVar17 < 0x3d) && ((0x1000000040000002U >> ((longlong)(int)*puVar17 & 0x3fU) & 1) != 0))
    {
      dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
      dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
      dVar32 = dVar33;
      dVar40 = dVar33;
      in_stack_fffffffffffffe68 = dVar33;
      FUN_140070d00(0x30,0,0x3c);
    }
    dVar27 = DAT_14053b1f0;
    dVar29 = DAT_14053a598;
    uVar7 = *puVar17;
    if (99 < (int)uVar7) {
      iVar12 = (int)(uVar7 - 600) % 600;
      iVar23 = (int)(uVar7 - 100) % 600;
      iVar11 = iVar14;
      if ((iVar23 == 0) || (iVar23 == 300)) {
        do {
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140134c50(DAT_140e418c8);
          uVar7 = FUN_140134cb0();
          if ((uVar7 & 1) == 0) {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xda;
            FUN_140134cb0();
            dVar32 = dVar29;
          }
          else {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdb;
            FUN_140134cb0();
            dVar32 = dVar27;
          }
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),(short)iVar11 * 0x2492);
          dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
          stage_entity_spawn_candidate(uVar30,99999999,0);
          iVar11 = iVar11 + 1;
        } while (iVar11 < 7);
        FUN_1400f74e0(0x2f);
      }
      if (iVar23 == 0x96) {
        do {
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140134c50(DAT_140e418c8);
          uVar7 = FUN_140134cb0();
          if ((uVar7 & 1) == 0) {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdc;
            FUN_140134cb0();
            dVar32 = dVar29;
          }
          else {
            FUN_140134c50(*(undefined4 *)(param_1 + 0xc));
            uVar30 = 0xdd;
            FUN_140134cb0();
            dVar32 = dVar27;
          }
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,1);
          dVar40 = 1.48219693752374e-322;
          dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),(short)iVar14 * 0x2492);
          dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
          stage_entity_spawn_candidate(uVar30,99999999,0);
          iVar14 = iVar14 + 1;
        } while (iVar14 < 7);
        FUN_1400f74e0(0x2f);
      }
      if (299 < *(int *)(param_1 + 0xc)) {
        if (iVar12 * -0x1b != iVar12 * 0x1b) {
          FUN_140134c50();
          FUN_140134cb0();
        }
        if (iVar12 == 0) {
          dVar32 = 0.0;
          dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
          dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),fVar1);
          dVar40 = _DAT_14053bbb0;
          in_stack_fffffffffffffe68 = _UNK_14053bbb8;
          FUN_140070d00(0x31,DAT_140e41a50,0x23);
          uVar13 = 0xff;
          uVar30 = 0x30;
        }
        else {
          if (iVar12 != 0x1e) {
            if (iVar12 - 0x1eU < 0x78) {
              uVar7 = iVar12 - 0x1eU & 0x80000007;
              if ((int)uVar7 < 0) {
                uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
              }
              if (uVar7 == 0) goto LAB_14004fe02;
            }
            goto LAB_14004fe63;
          }
          *(short *)(param_1 + 0x42) = sVar5;
LAB_14004fe02:
          in_stack_fffffffffffffe68 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),0x28);
          dVar40 = 4.94065645841247e-324;
          dVar28 = (double)((ulonglong)dVar28 & 0xffffffff00000000);
          dVar26 = (double)((ulonglong)dVar26 & 0xffffffffffff0000);
          dVar32 = DAT_14053a1a8;
          FUN_1400709b0(4,1,fVar25);
          uVar13 = 0xc0;
          uVar30 = 0x2a;
        }
        FUN_1400f74e0(uVar30,uVar13);
      }
    }
LAB_14004fe63:
    if (*(int *)(param_1 + 0xc) - 0x5aU < 10) {
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x77);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x76);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),0x5a,5,2,dVar26,dVar28,dVar32,dVar40);
    }
    if (99 < *(int *)(param_1 + 0xc)) {
      dVar32 = (double)CONCAT44((int)((ulonglong)dVar32 >> 0x20),0x7a);
      dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x79);
      dVar26 = (double)CONCAT44((int)((ulonglong)dVar26 >> 0x20),0x78);
      local_res8 = FUN_1400c9580(*(int *)(param_1 + 0xc),100,5,3,dVar26,dVar28,dVar32,dVar40);
    }
  }
  uVar45 = SUB84(DAT_140539d28,0);
  uVar46 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar29 = DAT_140539f00;
LAB_14004ae87:
  uVar43 = SUB84(DAT_14053a020,0);
  uVar44 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
switchD_14004ad5e_default:
  iVar14 = *(int *)(param_1 + 0x14);
  if (((((0xb < iVar14 - 99U) && (iVar14 != 0x3c)) && (10 < iVar14)) && (iVar14 < 0xa0)) ||
     (iVar14 - 0xa0U < 0x27)) {
    if (*(int *)(param_1 + 0x5c) == 0) {
      if (100 < DAT_140e44600 + 100U) {
        in_stack_fffffffffffffe68 =
             (double)((ulonglong)in_stack_fffffffffffffe68 & 0xffffffff00000000);
        dVar40 = 9.88131291682493e-323;
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
        dVar26 = (double)((ulonglong)dVar26 & 0xffffffff00000000);
        dVar32 = dVar33;
        stage_entity_spawn_candidate(0xc3,99999999,1);
        *(undefined4 *)(param_1 + 0x5c) = 1;
LAB_14005006f:
        *(undefined4 *)(param_1 + 0x54) = 1;
        if (DAT_140e44654 < 0x3d) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
          *(undefined4 *)(param_1 + 0x54) = 0;
        }
      }
    }
    else if (*(int *)(param_1 + 0x5c) == 1) goto LAB_14005006f;
  }
  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
  uVar47 = (undefined4)((ulonglong)dVar26 >> 0x20);
  iVar14 = *(int *)(param_1 + 0x14);
  if ((iVar14 < 0x3c) || (iVar14 - 0x6fU < 0x31)) {
    iVar11 = (DAT_140e418c8 + -0x46) % 0x78;
    if (iVar11 < 0x15) {
      FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053a9d8 * (double)CONCAT44(uVar44,uVar43) *
                    (double)CONCAT44(uVar46,uVar45));
    }
    uVar7 = (uint)((ulonglong)dVar26 >> 0x20);
    if ((iVar14 == 0xb) || (iVar14 == 0x6f)) {
      *(float *)(param_1 + 0x3c) =
           (float)*(int *)(param_1 + 0xc) * DAT_140539cd0 + *(float *)(param_1 + 0x3c);
    }
    uVar43 = DAT_14053af48;
    dVar27 = DAT_140539ec8;
    dVar31 = dVar33;
    if (iVar14 == 0) {
      if (*(int *)(param_1 + 0xc) < 0xbe) {
        uVar38 = (ulonglong)dVar32 & 0xffffffff00000000;
        uVar30 = CONCAT44((int)((ulonglong)dVar28 >> 0x20),DAT_14053af48);
        uVar35 = (ulonglong)dVar26 & 0xffffffff00000000;
        FUN_140134b10(*(int *)(param_1 + 0xc),0,0xb4,0,uVar35,uVar30,uVar38);
        uVar44 = (undefined4)((ulonglong)uVar30 >> 0x20);
        FUN_140133e80();
        uVar35 = uVar35 & 0xffffffff00000000;
        FUN_140134b10(*(undefined4 *)(param_1 + 0xc),0,0xb4,0,uVar35,CONCAT44(uVar44,uVar43),
                      uVar38 & 0xffffffff00000000);
        FUN_140133e80();
        uVar38 = 0;
        uVar35 = uVar35 & 0xffffffff00000000;
        dVar31 = (double)FUN_1401349e0(*(undefined4 *)(param_1 + 0xc),0,0x1e,0,uVar35,0,dVar33);
        uVar44 = (undefined4)(uVar35 >> 0x20);
        puVar10 = (undefined8 *)FUN_140135060(&local_118,*(undefined4 *)(param_1 + 0xc),0x14);
        uVar30 = *puVar10;
        uVar43 = *(undefined4 *)(puVar10 + 1);
        uVar38 = uVar38 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e44a08,0x1e,8);
        uStack_154 = (undefined4)((ulonglong)uVar30 >> 0x20);
        uVar47 = 0;
        uVar46 = 1;
        uVar45 = 0xff;
        uVar13 = CONCAT44(uVar42,(int)uVar30);
        uVar38 = uVar38 & 0xffffffffffff0000;
        dVar32 = dVar33;
        FUN_1400c8410(DAT_140e44a08,0x1e,8);
        uVar38 = uVar38 & 0xffffffff00000000;
        uVar30 = CONCAT44(uVar44,0x3c);
        FUN_1401348b0(*(undefined4 *)(param_1 + 0xc),0,0,0,uVar30,uVar38,0xff,dVar32,uVar13,
                      uStack_154,uVar43,uVar45,uVar46,uVar47);
        uVar42 = (undefined4)((ulonglong)uVar13 >> 0x20);
        dVar28 = (double)(uVar38 & 0xffffffffffff0000);
        uVar7 = (uint)((ulonglong)uVar30 >> 0x20);
        FUN_1400c8410(DAT_140e44a04,0x19,8);
      }
      else {
LAB_1400503d6:
        if (*(int *)(param_1 + 0x54) == 0) {
          if (iVar14 < 5) {
            iVar14 = *(int *)(param_1 + 0xc);
            if (-1 < iVar14) {
              iVar11 = (iVar14 / 0x32) * 0x32;
LAB_14005042e:
              if (iVar14 == iVar11) {
                FUN_140134c50(DAT_140e418c8);
                FUN_140134cb0();
                FUN_140134c50(DAT_140e418c8);
                uVar19 = FUN_140134cb0();
                iVar14 = uVar19 % 0x8001 - 0x4000;
                FUN_140133e80((uVar19 / 0x8001) * 0x8001,*(float *)(param_1 + 0x2c) + DAT_14053ace8,
                              CONCAT22((short)((uint)iVar14 >> 0x10),(short)iVar14 + -0x4000));
                FUN_140134c50(DAT_140e418c8);
                uVar19 = FUN_140134cb0();
                dVar40 = 1.97626258336499e-322;
                dVar28 = (double)CONCAT62((int6)((ulonglong)dVar28 >> 0x10),
                                          (short)uVar19 - (short)(uVar19 / 0x10001));
                stage_entity_spawn_candidate(0xcd,99999999,0);
                dVar32 = dVar27;
              }
            }
          }
          else if ((5 < iVar14) && (iVar14 = *(int *)(param_1 + 0xc), -1 < iVar14)) {
            iVar11 = (iVar14 / 0x19) * 0x19;
            goto LAB_14005042e;
          }
        }
        if (9 < *(int *)(param_1 + 0x14)) {
          local_118 = &DAT_ff000000ff;
          local_128 = 0xff;
          local_120 = 0;
          local_110 = 0xff;
          uVar35 = CONCAT44(uVar7,0xfa);
          FUN_140134f10(&local_108,&local_118,&local_128,*(undefined4 *)(param_1 + 0xc),uVar35,
                        dVar28,dVar32,dVar40);
          uVar35 = uVar35 & 0xffffffff00000000;
          dVar28 = dVar33;
          FUN_1401349e0(*(undefined4 *)(param_1 + 0xc),0,0xf0,0,uVar35,dVar33,dVar29);
          uVar7 = (uint)(uVar35 >> 0x20);
        }
        dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
        FUN_1400c8410(DAT_140e44a08,0x1e,7);
      }
    }
    else if ((iVar14 < 10) || ((iVar14 == 10 && (*(int *)(param_1 + 0xc) < 0xfa))))
    goto LAB_1400503d6;
    iVar14 = 0;
    iVar11 = 0x14;
    uVar48 = 0;
    uVar46 = 1;
    uVar45 = 0xff;
    uVar44 = 0xff;
    uVar43 = 0xff;
    in_stack_fffffffffffffe68 = (double)CONCAT44(uVar42,0xff);
    dVar28 = (double)((ulonglong)dVar28 & 0xffffffffffff0000);
    lVar34 = (ulonglong)uVar7 << 0x20;
    FUN_1400c8410(DAT_140e44a04,0x12,7);
    uVar47 = (undefined4)((ulonglong)lVar34 >> 0x20);
    if (*(int *)(param_1 + 0x14) == 0) {
      if (0x3b < *(int *)(param_1 + 0xc)) {
        dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),DAT_14053acc8);
        lVar34 = CONCAT44(uVar47,0x50);
        FUN_140134b10(*(undefined4 *)(param_1 + 0xc),0,0,0x3c,lVar34,dVar28,
                      (ulonglong)dVar33 & 0xffffffff00000000,dVar31,in_stack_fffffffffffffe68,uVar43
                      ,uVar44,uVar45,uVar46,uVar48);
        dVar32 = DAT_14053a900;
LAB_140050750:
        do {
          uVar7 = (uint)((ulonglong)lVar34 >> 0x20);
          uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
          FUN_140133e80();
          iVar12 = (DAT_140e418c8 - iVar14) % 0x78;
          if (iVar12 < 0x21) {
            FUN_140332d90(((double)iVar12 - _DAT_140539cc0) * dVar32 * DAT_14053a020 * DAT_140539d28
                         );
          }
          uVar30 = CONCAT62((int6)((ulonglong)dVar28 >> 0x10),0x9770);
          FUN_1400c8410(DAT_140e44888,iVar11,7);
          FUN_140133e80();
          iVar12 = (DAT_140e418c8 - iVar14) % 0x78;
          if (iVar12 < 0x21) {
            FUN_140332d90(((double)iVar12 - _DAT_140539cc0) * dVar32 * DAT_14053a020 * DAT_140539d28
                         );
          }
          uVar30 = CONCAT62((int6)((ulonglong)uVar30 >> 0x10),0xe890);
          FUN_1400c8410(DAT_140e44888,iVar11,7);
          FUN_140133e80();
          iVar12 = (DAT_140e418c8 - iVar14) % 0x78;
          if (iVar12 < 0x21) {
            FUN_140332d90(((double)iVar12 - 0.0) * dVar32 * DAT_14053a020 * DAT_140539d28);
          }
          uVar30 = CONCAT62((int6)((ulonglong)uVar30 >> 0x10),0x6890);
          FUN_1400c8410(DAT_140e4488c,0xf,7);
          FUN_140133e80();
          iVar12 = (DAT_140e418c8 - iVar14) % 0x78;
          if (iVar12 < 0x21) {
            FUN_140332d90(((double)iVar12 - 0.0) * dVar32 * DAT_14053a020 * DAT_140539d28);
          }
          in_stack_fffffffffffffe68 = (double)CONCAT44(uVar43,0xff);
          dVar28 = (double)CONCAT62((int6)((ulonglong)uVar30 >> 0x10),6000);
          lVar34 = (ulonglong)uVar7 << 0x20;
          FUN_1400c8410(DAT_140e4488c,0xf,7);
          uVar47 = (undefined4)((ulonglong)lVar34 >> 0x20);
          iVar11 = iVar11 + -1;
          iVar14 = iVar14 + 10;
        } while (0xe < iVar11);
      }
    }
    else {
      dVar32 = DAT_14053a900;
      if (0 < *(int *)(param_1 + 0x14)) goto LAB_140050750;
    }
  }
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);
  if (*(int *)(param_1 + 0x14) == 10) {
    if (*(int *)(param_1 + 0xc) < 0xfa) goto LAB_140050e90;
  }
  else if (*(int *)(param_1 + 0x14) < 0xb) goto LAB_140050e90;
  dVar32 = (double)FUN_140332d90();
  dVar32 = dVar32 * DAT_14053aa78;
  dVar33 = (double)FUN_140332d90();
  fVar1 = DAT_14053ac5c;
  fVar25 = DAT_14053ac58;
  dVar33 = dVar33 * DAT_140539ee0 + DAT_140539f18;
  uVar44 = DAT_140e44514;
  if (3 < DAT_140e419b8) {
    local_res8 = local_res8 + 0xf;
    uVar44 = DAT_140e44550;
  }
  uVar41 = CONCAT44(uVar43,0xff);
  sVar5 = (short)(int)dVar32;
  uVar13 = CONCAT62((int6)((ulonglong)dVar28 >> 0x10),sVar5);
  uVar30 = CONCAT44(uVar47,*(float *)(param_1 + 0x2c) - DAT_14053ac58);
  FUN_1400c8410(uVar44,0x22,7,*(float *)(param_1 + 0x28) + DAT_14053ac5c,uVar30,uVar13,dVar33,
                local_138,uVar41,0xff,0xff,local_148,1,0);
  uVar41 = CONCAT44((int)((ulonglong)uVar41 >> 0x20),0xff);
  uVar13 = CONCAT62((int6)((ulonglong)uVar13 >> 0x10),-sVar5);
  uVar30 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),*(float *)(param_1 + 0x2c) - fVar25);
  FUN_1400c8410(uVar44,0x22,7,*(float *)(param_1 + 0x28) - fVar1,uVar30,uVar13,dVar33,local_138,
                uVar41,0xff,0xff,local_148,1,1);
  uVar45 = (undefined4)((ulonglong)uVar41 >> 0x20);
  uVar37 = (undefined6)((ulonglong)uVar13 >> 0x10);
  uVar43 = (undefined4)((ulonglong)uVar30 >> 0x20);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res8 * 4),0x23,7);
  if (0 < local_144) {
    FUN_1400c8410(uVar44,0x22,8,*(float *)(param_1 + 0x28) + fVar1,
                  CONCAT44(uVar43,*(float *)(param_1 + 0x2c) - fVar25),CONCAT62(uVar37,sVar5),dVar33
                  ,local_138,CONCAT44(uVar45,0xff),0xff,0xff,local_144,1,0);
    FUN_1400c8410(uVar44,0x22,8,*(float *)(param_1 + 0x28) - fVar1,
                  *(float *)(param_1 + 0x2c) - fVar25,-sVar5,dVar33,local_138,0xff,0xff,0xff,
                  local_144,1,1);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res8 * 4),0x23,8);
  }
LAB_140050e90:
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


