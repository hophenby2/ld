// Function: FUN_140052fb0 @ 140052fb0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140052fb0(undefined4 *param_1)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  bool bVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  ushort uVar16;
  int iVar17;
  float *pfVar18;
  float *pfVar19;
  byte bVar20;
  uint *puVar21;
  int *piVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined4 uVar33;
  float fVar34;
  float fVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  int local_res10;
  int local_res18;
  undefined8 in_stack_fffffffffffffec0;
  uint6 uVar40;
  undefined4 uVar42;
  undefined6 uVar41;
  ulonglong uVar39;
  undefined8 in_stack_fffffffffffffec8;
  undefined8 in_stack_fffffffffffffed0;
  
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  uVar42 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  dVar26 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar31 = DAT_14053aba0;
  dVar29 = DAT_140539f40;
  uVar37 = SUB84(DAT_140539f40,0);
  uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  dVar28 = (double)CONCAT44(uVar42,0x92);
  dVar32 = (double)CONCAT44(uVar36,0x93);
  iVar24 = 0;
  iVar13 = 0;
  uVar39 = CONCAT44(uVar33,0x92);
  local_res18 = 0xff;
  local_res10 = 0;
  bVar4 = true;
  uVar15 = (uint)(dVar26 * DAT_14053aba0);
  iVar7 = FUN_1400c9580(param_1[3],0,5,4,0x91,uVar39,dVar32,dVar28);
  iVar12 = 0x8c;
  if ((DAT_140e419bc != 1) || ((0 < (int)param_1[7] && (0 < DAT_140e4430c)))) goto LAB_1400532dc;
  switch(DAT_140e41af8) {
  case 1:
    param_1[5] = 200;
    DAT_140e419bc = -1;
    break;
  case 2:
    param_1[5] = 0x96;
    DAT_140e419bc = 3;
    break;
  case 3:
    param_1[5] = 0x8c;
    DAT_140e419bc = 3;
    goto switchD_140053108_default;
  case 4:
    param_1[5] = 0x82;
    DAT_140e419bc = 3;
    break;
  case 5:
    param_1[5] = 0x78;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 6:
    param_1[5] = 0x6e;
    DAT_140e419bc = 3;
    break;
  case 7:
    param_1[5] = 100;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 8:
    param_1[5] = 0x5a;
    DAT_140e419bc = 3;
    break;
  case 9:
    param_1[5] = 0x50;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 10:
    param_1[5] = 0x46;
    DAT_140e419bc = 3;
    break;
  case 0xb:
    param_1[5] = 0x3c;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 0xc:
    param_1[5] = 0x32;
    DAT_140e419bc = 3;
    break;
  case 0xd:
    param_1[5] = 0x28;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 0xe:
    param_1[5] = 0x1e;
    DAT_140e419bc = 3;
    break;
  case 0xf:
    param_1[5] = 0x14;
    DAT_140e419bc = 2;
    goto switchD_140053108_default;
  case 0x10:
    param_1[5] = 10;
    DAT_140e419bc = 3;
    break;
  default:
    goto switchD_140053108_default;
  }
  FUN_1400031d0(param_1);
  dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),param_1[0x14]);
  uVar39 = uVar39 & 0xffffffffffff0000;
  dVar32 = DAT_14053a4f0;
  stage_entity_spawn_candidate(0x137,99999999,0);
switchD_140053108_default:
  DAT_140e41af8 = DAT_140e41af8 + -1;
  param_1[3] = 0;
  param_1[0x17] = 0;
LAB_1400532dc:
  puVar21 = param_1 + 3;
  pfVar19 = (float *)(param_1 + 10);
  pfVar18 = (float *)(param_1 + 0xb);
  param_1[0x15] = 1;
  dVar5 = DAT_14053a020;
  dVar26 = DAT_140539d28;
  uVar16 = (ushort)uVar15;
  uVar36 = DAT_14053b320;
  iVar17 = 0;
  iVar23 = 0;
  uVar33 = DAT_14053ae30;
  switch(param_1[5]) {
  case 0:
    iVar12 = param_1[3];
    if (iVar12 < 0) {
      iVar24 = 0xff;
    }
    else if (iVar12 < 100) {
      dVar32 = (double)FUN_140332d90(((double)iVar12 - DAT_14053b1b0) * DAT_14053a530 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar24 = (int)(dVar32 * DAT_14053a5f8);
    }
    else {
      iVar24 = 0;
      FUN_140001900(iVar12,100,0xb);
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar23 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar23 + 0x10000;
    if (-0x8001 < iVar23) {
      iVar12 = iVar23;
    }
    iVar23 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar23 = iVar12;
    }
    if (iVar23 < 1) {
      uVar14 = uVar1;
      if ((iVar23 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar23)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar23) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar32 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90();
    uVar33 = DAT_140e41ab8;
    param_1[0xb] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    puVar8 = (undefined4 *)_malloc_base(0x48);
    if (puVar8 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar25 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar8 = uVar33;
    puVar8[1] = 0x4e;
    *(undefined8 *)(puVar8 + 2) = 5;
    puVar8[4] = 0;
    *(undefined2 *)(puVar8 + 5) = 0;
    *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
    puVar8[10] = 0xff;
    puVar8[0xb] = 0xff;
    puVar8[0xc] = 0xff;
    puVar8[0xd] = iVar24;
    *(undefined8 *)(puVar8 + 0xe) = 1;
    *(undefined8 *)(puVar8 + 0x10) = 0;
    if (bVar25) {
      DAT_140e46bf0 = puVar8;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
    }
    uVar36 = DAT_14053b320;
    uVar33 = DAT_14053ae30;
    local_res18 = 0xff;
    iVar17 = 0;
    iVar23 = iVar13;
    DAT_140e46c88 = puVar8;
    if (param_1[3] == 0x104) {
      param_1[5] = param_1[5] + 1;
      DAT_140e41b0c = 75000;
      param_1[7] = 75000;
      param_1[3] = 0;
      DAT_140e4430c = 0x960;
      DAT_140e4192c = 0;
      DAT_140e419bc = 1;
    }
    break;
  case 1:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar28 = (double)FUN_1403307c0();
    fVar35 = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar35;
    dVar28 = (double)FUN_140332d90();
    iVar12 = param_1[3];
    param_1[0xb] = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    fVar34 = DAT_14053ac2c;
    uVar36 = DAT_14053b320;
    if (0x1d < iVar12) {
      dVar28 = (double)(iVar12 + -0x1e) * _DAT_140539d78 + DAT_14053a070;
      iVar13 = (iVar12 + -0x1e) % 0x78;
      if (0x17b < iVar12) {
        iVar13 = (iVar12 + -0x136) % 0x5a;
      }
      iVar23 = 0x5a;
      if (iVar12 < 0x17c) {
        iVar23 = 0x78;
      }
      iVar17 = 0x136;
      if (iVar12 < 0x17c) {
        iVar17 = 0x1e;
      }
      if (iVar17 <= iVar12) {
        uVar3 = (longlong)(iVar12 - iVar17) % (longlong)(iVar23 * 2);
        iVar12 = (int)uVar3;
        if ((iVar12 < 0x48) && (iVar12 == (iVar12 / 5) * 5)) {
          FUN_1403300b4(uVar3 & 0xffffffff,
                        (double)(fVar35 - (DAT_14053af14 - (float)iVar13 * DAT_14053ac2c)));
          uVar36 = DAT_14053b320;
          uVar39 = uVar39 & 0xffffffffffff0000;
          dVar32 = dVar28;
          stage_entity_spawn_candidate(0x105,10,0);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      if (iVar23 + iVar17 <= (int)param_1[3]) {
        uVar3 = (longlong)(param_1[3] - (iVar23 + iVar17)) % (longlong)(iVar23 * 2);
        iVar12 = (int)uVar3;
        if ((iVar12 < 0x48) && (iVar12 == (iVar12 / 5) * 5)) {
          FUN_1403300b4(uVar3 & 0xffffffff,(double)((float)param_1[10] - (float)iVar13 * fVar34));
          uVar39 = uVar39 & 0xffffffffffff0000;
          stage_entity_spawn_candidate(0x105,10,0);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          dVar32 = dVar28;
        }
      }
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39,dVar32);
    }
    if (0x1d < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x1e,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    uVar33 = DAT_14053ae30;
    local_res18 = 0xff;
    param_1[0x15] = 0;
    iVar17 = 0;
    iVar23 = iVar24;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
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
  case 0x3b:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
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
  case 199:
    iVar17 = 0;
    iVar23 = iVar24;
    break;
  case 10:
  case 0x1e:
  case 0x32:
  case 0x46:
  case 0x5a:
  case 0x6e:
  case 0x82:
  case 0x96:
    iVar7 = param_1[3];
    FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a558 * DAT_14053a020 * DAT_140539d28);
    uVar33 = (undefined4)(uVar39 >> 0x20);
    puVar9 = DAT_140e45d28;
    if (iVar7 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar36 = param_1[0xb];
      uVar42 = param_1[10];
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        puVar9[6] = 0x3ff0000000000000;
        puVar9[7] = 0x3ff0000000000000;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        puVar9[10] = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x14) = uVar42;
        *(undefined4 *)(puVar9 + 3) = uVar36;
        *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar42;
        *(undefined4 *)(puVar9 + 4) = uVar36;
        *puVar9 = 1;
        puVar9[1] = 0x36;
        *(undefined4 *)(puVar9 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        *(undefined4 *)(puVar9 + 8) = 0;
        puVar9[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
    }
    DAT_140e45d28 = puVar9;
    piVar22 = param_1 + 3;
    if (*piVar22 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar39 = CONCAT44(uVar33,0x9f);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar7 = FUN_1400c9580(*piVar22,0,5,2,0x9e,uVar39);
    if (*piVar22 == 0xb4) {
      iVar12 = param_1[5];
      *piVar22 = 0;
      DAT_140e419bc = 2;
      if (iVar12 == 10) {
        DAT_140e4430c = 0x960;
        DAT_140e41b0c = 70000;
        DAT_140e4192c = 0;
        iVar24 = 70000;
      }
      else if (iVar12 == 0x1e) {
        DAT_140e4430c = 0x960;
        DAT_140e41b0c = 50000;
        DAT_140e4192c = 0;
        iVar24 = 50000;
      }
      else if (iVar12 == 0x32) {
        DAT_140e4430c = 0x960;
        DAT_140e41b0c = 50000;
        DAT_140e4192c = 0;
        iVar24 = 50000;
      }
      else if (iVar12 == 0x46) {
        DAT_140e41b0c = 100000;
LAB_14005577c:
        DAT_140e4430c = 0xce4;
        DAT_140e4192c = 0;
        iVar24 = DAT_140e41b0c;
      }
      else if (iVar12 == 0x5a) {
        DAT_140e4430c = 0x960;
        DAT_140e41b0c = 80000;
        DAT_140e4192c = 0;
        iVar24 = 80000;
      }
      else if (iVar12 == 0x6e) {
        DAT_140e4430c = 0x960;
        DAT_140e41b0c = 75000;
        DAT_140e4192c = 0;
        iVar24 = 75000;
      }
      else {
        if (iVar12 == 0x82) {
          DAT_140e41b0c = 0x1f400;
          goto LAB_14005577c;
        }
        iVar24 = DAT_140e41b0c;
        if (iVar12 == 0x96) {
          DAT_140e4430c = 6000;
          DAT_140e41b0c = 270000;
          *(undefined8 *)(param_1 + 0x12) = 0x3fc999999999999a;
          DAT_140e4192c = 0;
          DAT_140e419bc = 1;
          iVar24 = 270000;
        }
      }
      param_1[7] = iVar24;
      param_1[5] = iVar12 + 1;
    }
    local_res18 = 0xff;
    uVar36 = DAT_14053b320;
    iVar17 = 0;
    iVar23 = iVar13;
    uVar33 = DAT_14053ae30;
    break;
  case 0xb:
  case 0x1f:
  case 0x33:
  case 0x47:
  case 0x5b:
  case 0x6f:
    uVar10 = *puVar21;
    if ((int)uVar10 < 0xdc) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar12 = (uVar15 & 0xffff) - (uint)uVar1;
      if (iVar12 < -0x8000) {
        iVar12 = iVar12 + 0x10000;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar14 = uVar1;
        if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
          uVar14 = uVar16;
        }
      }
      else {
        uVar14 = uVar16;
        if (0x1ff < iVar13) {
          uVar14 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar31 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar31 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    else {
      bVar4 = false;
    }
    dVar31 = DAT_14053a5f8;
    iVar23 = 0;
    iVar12 = 0xff;
    if (uVar10 - 200 < 0x14) {
      dVar27 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a548) * DAT_14053a890 * dVar5 *
                                     dVar26);
      iVar12 = (int)(dVar27 * dVar31);
    }
    local_res10 = 0;
    local_res18 = iVar23;
    if ((int)uVar10 < 0xdc) {
      local_res18 = iVar12;
    }
    iVar12 = local_res10;
    if ((int)uVar10 < 0xb4) {
LAB_140055a0f:
      local_res10 = iVar23;
      if ((int)uVar10 < 0xdc) {
        local_res10 = iVar12;
      }
      if (((int)uVar10 < 0x1e) || (iVar23 = 0xff, 0xb3 < (int)uVar10)) {
        puVar9 = DAT_140e45d28;
        if ((uVar10 == 1) && (uVar33 = param_1[1], DAT_140e45d1c < 0x1000)) {
          puVar9 = (undefined8 *)_malloc_base(0x60);
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar9 = 1;
          puVar9[1] = 0x2f;
          puVar9[2] = 0x3c;
          puVar9[3] = 0;
          *(undefined4 *)(puVar9 + 4) = 0;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          puVar9[5] = 0x3ff0000000000000;
          puVar9[6] = 0x3ff0000000000000;
          puVar9[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar9 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)(puVar9 + 9) = 0x40;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          *(undefined4 *)(puVar9 + 10) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x54) = uVar33;
          puVar9[0xb] = 0;
          if (bVar25) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
      }
      else {
        dVar26 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a2d8) * _DAT_14053a478 *
                                       dVar5 * dVar26);
        iVar23 = (int)(dVar26 * dVar31);
        puVar9 = DAT_140e45d28;
      }
    }
    else {
      iVar12 = 0xff;
      if ((int)uVar10 < 200) {
        dVar26 = (double)FUN_140332d90();
        if ((int)uVar10 < 0xdc) {
          local_res10 = (int)(dVar26 * dVar31);
        }
        puVar9 = DAT_140e45d28;
        if (0x1d < (int)uVar10) {
          iVar23 = 0xff;
        }
      }
      else {
        if (0xdb < (int)uVar10) goto LAB_140055a0f;
        dVar26 = (double)FUN_140332d90();
        if ((int)uVar10 < 0xdc) {
          local_res10 = (int)(dVar26 * dVar31);
        }
        puVar9 = DAT_140e45d28;
        if (0x1d < (int)uVar10) {
          iVar23 = 0xff;
        }
      }
    }
    DAT_140e45d28 = puVar9;
    if (param_1[3] == 0x1e) {
      if (param_1[5] == 0xb) {
        dVar28 = 7.4109846876187e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x111,99999999,0);
      }
      if (param_1[5] == 0x1f) {
        dVar28 = 4.94065645841247e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x112,99999999,0);
      }
      if (param_1[5] == 0x33) {
        dVar28 = 3.95252516672997e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x113,99999999,0);
      }
      if (param_1[5] == 0x47) {
        dVar28 = 7.4109846876187e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x115,99999999,0);
      }
      if (param_1[5] == 0x5b) {
        dVar28 = 8.39911597930119e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x11a,99999999,0);
      }
      if (param_1[5] == 0x6f) {
        dVar28 = 7.4109846876187e-322;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
        stage_entity_spawn_candidate(0x11d,99999999,0);
        dVar32 = dVar29;
      }
    }
    if (param_1[3] == 0xb4) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar12 = param_1[3];
    if (iVar12 == 0xdc) {
      DAT_140e419bc = 1;
    }
    else if (iVar12 - 0x1eU < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(iVar12,0x1e,5,2,0x94,uVar39,dVar32,dVar28);
    }
    uVar36 = DAT_14053b320;
    iVar17 = local_res10;
    uVar33 = DAT_14053ae30;
    if (param_1[3] - 0x28 < 0xb5) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x28,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
      uVar36 = DAT_14053b320;
      uVar33 = DAT_14053ae30;
    }
    break;
  case 0x14:
  case 0x28:
  case 0x3c:
  case 0x50:
  case 100:
  case 0x78:
  case 0x8c:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar32 = (double)FUN_1403307c0();
    *pfVar19 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar19;
    dVar31 = (double)FUN_140332d90();
    dVar29 = DAT_14053a890;
    dVar28 = DAT_14053a5f8;
    dVar32 = DAT_14053a510;
    uVar15 = *puVar21;
    iVar12 = 0;
    *pfVar18 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + *pfVar18;
    iVar13 = 0xff;
    if (((int)uVar15 < 0x96) || (iVar12 = 0xff, 0xa9 < (int)uVar15)) {
      local_res18 = iVar12;
      if (0x95 < (int)uVar15) {
        if ((int)uVar15 < 0xaa) goto LAB_140056152;
        goto LAB_140056182;
      }
    }
    else {
      dVar31 = (double)FUN_140332d90(((double)(int)uVar15 - dVar32) * dVar29 * dVar5 * dVar26);
      local_res18 = (int)(dVar31 * dVar28);
LAB_140056152:
      dVar31 = (double)FUN_140332d90(((double)(int)uVar15 - dVar32) * dVar29 * dVar5 * dVar26);
      iVar12 = (int)(dVar31 * dVar28);
      if (0xa9 < (int)uVar15) {
LAB_140056182:
        if (uVar15 < 0xbe) {
          dVar32 = (double)FUN_140332d90(((double)(int)uVar15 - dVar32) * dVar29 * dVar5 * dVar26);
          iVar12 = (int)(dVar32 * dVar28);
        }
      }
    }
    iVar17 = 0;
    if ((int)uVar15 < 0xbe) {
      iVar17 = iVar12;
    }
    if (uVar15 < 0x3c) {
      dVar32 = (double)FUN_140332d90(((double)(int)uVar15 - _DAT_14053b158) * DAT_14053a628 * dVar5
                                     * dVar26);
      iVar13 = (int)(dVar32 * dVar28);
    }
    iVar23 = 0;
    if ((int)uVar15 < 0x3c) {
      iVar23 = iVar13;
    }
    if (uVar15 == 0x96) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    uVar36 = DAT_14053b320;
    uVar33 = DAT_14053ae30;
    if (param_1[3] == 200) {
      iVar12 = param_1[5];
      param_1[3] = 0;
      if (iVar12 == 0x14) {
        DAT_140e41b0c = 65000;
        goto LAB_140056270;
      }
      if (iVar12 == 0x28) {
        DAT_140e41b0c = 75000;
        goto LAB_140056293;
      }
      if (iVar12 == 0x3c) {
        DAT_140e41b0c = 60000;
LAB_140056270:
        DAT_140e4430c = 0x834;
        DAT_140e4192c = 0;
        iVar13 = DAT_140e41b0c;
      }
      else {
        if (iVar12 == 0x50) {
          DAT_140e41b0c = 45000;
          goto LAB_140056270;
        }
        if (iVar12 == 100) {
          DAT_140e41b0c = 65000;
LAB_140056293:
          DAT_140e4430c = 0x960;
          DAT_140e4192c = 0;
          iVar13 = DAT_140e41b0c;
        }
        else {
          if (iVar12 == 0x78) {
            DAT_140e41b0c = 85000;
            goto LAB_140056293;
          }
          iVar13 = DAT_140e41b0c;
          if (iVar12 == 0x8c) {
            DAT_140e4430c = 0x1518;
            DAT_140e41b0c = 32000;
            *(undefined8 *)(param_1 + 0x12) = 0x3fb999999999999a;
            DAT_140e4192c = 0;
            iVar13 = 32000;
          }
        }
      }
      param_1[7] = iVar13;
      DAT_140e419bc = (iVar12 == 0x8c) + 1;
      param_1[5] = iVar12 + 1;
      uVar36 = DAT_14053b320;
      uVar33 = DAT_14053ae30;
    }
    break;
  case 0x15:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar28 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar28 = (double)FUN_140332d90();
    uVar15 = param_1[3];
    param_1[0xb] = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar36 = DAT_14053b320;
    if (0x1d < (int)uVar15) {
      iVar12 = uVar15 - 0x1e;
      dVar29 = (double)iVar12 * _DAT_140539d80 + DAT_14053a0f8;
      dVar28 = (double)(int)(uVar15 - 0xd2) * _DAT_140539d70 + DAT_14053a0b0;
      if (iVar12 % 0x96 == 0) {
        uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar15 = uVar15 * 0x800 ^ uVar15;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
        param_1[0xc] = (float)(int)(DAT_140e9fd1c % 0x51 - 0x28);
      }
      uVar36 = DAT_14053b320;
      iVar12 = iVar12 % 300;
      if ((iVar12 < 0x5a) && (iVar12 == (iVar12 / 0xe) * 0xe)) {
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),7000);
        dVar32 = dVar29;
        stage_entity_spawn_candidate(0x106,10,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      if (((0xb3 < (int)param_1[3]) && (iVar12 = (param_1[3] + -0xb4) % 300, iVar12 < 0x5a)) &&
         (iVar12 == (iVar12 / 0xe) * 0xe)) {
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x64a8);
        stage_entity_spawn_candidate(0x106,10,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        dVar32 = dVar29;
      }
      uVar33 = DAT_140e41a50;
      if (param_1[3] == 0xb4) {
        uVar42 = param_1[1];
        puVar9 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar9 = (undefined8 *)_malloc_base();
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
          puVar9[6] = 0x4014000000000000;
          puVar9[7] = 0x4014000000000000;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)(puVar9 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          *(undefined4 *)(puVar9 + 10) = 0xff;
          *puVar9 = 1;
          *(undefined4 *)(puVar9 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar9 + 0xc) = uVar33;
          puVar9[2] = 0x23;
          puVar9[3] = 0;
          *(undefined4 *)(puVar9 + 4) = 0;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          puVar9[5] = 0;
          *(undefined4 *)(puVar9 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar9 + 0x54) = uVar42;
          puVar9[0xb] = 0;
          if (bVar25) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
        DAT_140e45d28 = puVar9;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
      }
      if ((0xd1 < (int)param_1[3]) && (iVar12 = param_1[3] + -0xd2, iVar12 == (iVar12 / 100) * 100))
      {
        fVar34 = (float)param_1[10];
        FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),(double)(DAT_140e445d8 - fVar34)
                     );
        iVar13 = 0;
        iVar12 = iVar13;
        do {
          uVar39 = uVar39 & 0xffffffff00000000;
          FUN_14006c2f0(3,0,fVar34);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 7);
        dVar28 = dVar28 - DAT_140539f90;
        uVar33 = param_1[10];
        do {
          uVar39 = uVar39 & 0xffffffff00000000;
          dVar32 = dVar28;
          FUN_14006c2f0(3,0,uVar33);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0x14);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39,dVar32);
    }
    if (0x1d < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x1e,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    uVar33 = DAT_14053ae30;
    param_1[0x15] = 0;
    iVar17 = 0;
    iVar23 = iVar24;
    break;
  case 0x29:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar29 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar29 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar33 = DAT_14053b320;
    fVar34 = DAT_14053ac2c;
    if (0x1d < (int)param_1[3]) {
      iVar12 = param_1[3] + -0x1e;
      dVar29 = (double)iVar12 * DAT_140539d60 + DAT_14053a018;
      dVar26 = (double)iVar12 * _DAT_140539d78 + DAT_14053a110;
      iVar13 = iVar12 % 100;
      iVar12 = iVar12 % 300;
      if ((iVar12 < 0x3c) && (iVar12 == (iVar12 / 5) * 5)) {
        dVar28 = 9.88131291682493e-323;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),(short)iVar13 * 0x96 + 500);
        dVar32 = dVar29;
        stage_entity_spawn_candidate
                  (0x107,10,0,DAT_14053af14 - (float)iVar13 * DAT_14053ac2c,DAT_14053b320,uVar39,
                   dVar29,0x14,1,param_1[1]);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      if (((0x81 < (int)param_1[3]) && (iVar12 = (param_1[3] + -0x82) % 300, iVar12 < 0x3c)) &&
         (iVar12 == (iVar12 / 5) * 5)) {
        dVar28 = 9.88131291682493e-323;
        uVar39 = CONCAT62((int6)(uVar39 >> 0x10),(short)iVar13 * -0x96 + 0x7e0c);
        dVar32 = dVar29;
        stage_entity_spawn_candidate
                  (0x107,10,0,(float)iVar13 * fVar34 + DAT_14053accc + DAT_14053ac60,uVar33,uVar39,
                   dVar29,0x14,1,param_1[1]);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      if (((0xe5 < (int)param_1[3]) && (iVar12 = (param_1[3] + -0xe6) % 300, iVar12 < 0x3c)) &&
         (iVar12 == (iVar12 / 7) * 7)) {
        uVar40 = (uint6)(uVar39 >> 0x10);
        stage_entity_spawn_candidate(0x107,10,0);
        dVar28 = 9.88131291682493e-323;
        uVar39 = (ulonglong)uVar40 << 0x10;
        stage_entity_spawn_candidate(0x107,10,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        dVar32 = dVar29;
      }
      iVar12 = param_1[3];
      if (iVar12 < 0x118) {
LAB_14005450b:
        uVar37 = SUB84(DAT_140539f40,0);
        uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
      else {
        if (iVar12 + -0x118 == ((iVar12 + -0x118) / 100) * 100) {
          dVar29 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                         (double)(DAT_140e445d8 - (float)param_1[10]));
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar29 * dVar31);
          uVar15 = (iVar12 + -0x118) % 100;
        }
        else if ((iVar12 < 0x118) || (uVar15 = (iVar12 + -0x118) % 100, 0x1f < (int)uVar15))
        goto LAB_14005450b;
        uVar15 = uVar15 & 0x80000003;
        if ((int)uVar15 < 0) {
          uVar15 = (uVar15 - 1 | 0xfffffffc) + 1;
        }
        if (uVar15 == 0) {
          dVar28 = 4.94065645841247e-324;
          uVar39 = uVar39 & 0xffffffff00000000;
          FUN_1400709b0(3,0,param_1[10]);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          dVar32 = dVar26;
        }
LAB_140054500:
        uVar37 = SUB84(DAT_140539f40,0);
        uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
    }
    goto LAB_14005451b;
  case 0x3d:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar24 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar24 + 0x10000;
    if (-0x8001 < iVar24) {
      iVar12 = iVar24;
    }
    iVar24 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar24 = iVar12;
    }
    if (iVar24 < 1) {
      uVar14 = uVar1;
      if ((iVar24 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar24)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar24) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar32 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90();
    iVar12 = param_1[3];
    param_1[0xb] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (0x1d < iVar12) {
      iVar24 = 0x1ae;
      if (iVar12 < 0x1ae) {
        iVar24 = 0x1e;
      }
      iVar23 = 0x4b;
      if (iVar12 < 0x1ae) {
        iVar23 = 100;
      }
      dVar32 = (double)(iVar12 + -0x1e) * _DAT_140539d70 + DAT_14053a0b0;
      if ((iVar24 <= iVar12) && ((iVar12 - iVar24) % (iVar23 * 2) == 0)) {
        iVar12 = 0;
        do {
          uVar10 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar15 = uVar10 * 0x800 ^ uVar10;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
          uVar39 = CONCAT62((int6)(uVar39 >> 0x10),
                            ((short)iVar12 * 0x1111 - (short)(DAT_140e9fd1c / 0x10001)) +
                            (short)DAT_140e9fd1c);
          stage_entity_spawn_candidate
                    (0x10c,10,0,uVar10,param_1[0xb],uVar39,dVar32,0x14,1,param_1[1]);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xf);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      if ((iVar23 + iVar24 <= (int)param_1[3]) &&
         ((param_1[3] - (iVar23 + iVar24)) % (iVar23 * 2) == 0)) {
        iVar12 = 0;
        do {
          uVar10 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar15 = uVar10 * 0x800 ^ uVar10;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
          uVar39 = CONCAT62((int6)(uVar39 >> 0x10),
                            ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) +
                            (short)iVar12 * 0x1111);
          stage_entity_spawn_candidate
                    (0x10d,10,0,uVar10,param_1[0xb],uVar39,dVar32,0x14,1,param_1[1]);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xf);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39);
    }
    if (0x1d < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x1e,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    uVar33 = DAT_14053ae30;
    local_res18 = 0xff;
    param_1[0x15] = 0;
    uVar36 = DAT_14053b320;
    iVar17 = 0;
    iVar23 = iVar13;
    break;
  case 0x51:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar29 = (double)FUN_1403307c0();
    fVar35 = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar35;
    dVar29 = (double)FUN_140332d90();
    iVar12 = param_1[3];
    fVar34 = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar34;
    if (0x1d < iVar12) {
      dVar29 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34),
                                     (double)(DAT_140e445d8 - fVar35));
      uVar15 = (uint)(dVar29 * dVar31);
      dVar31 = (double)(int)(iVar12 - 0x1eU) * _DAT_140539d68;
      dVar29 = dVar31 + DAT_140539fc8;
      dVar31 = dVar31 + DAT_14053a120;
      uVar16 = (ushort)uVar15;
      if (iVar12 == 0x1e) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar16;
      }
      uVar10 = iVar12 - 0x1eU & 0x80000003;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
      }
      if (uVar10 == 0) {
        dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x14);
        uVar39 = uVar39 & 0xffffffffffff0000;
        stage_entity_spawn_candidate(0x10e,10,0);
        uVar1 = *(ushort *)((longlong)param_1 + 0x42);
        iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
        iVar12 = iVar13 + 0x10000;
        if (-0x8001 < iVar13) {
          iVar12 = iVar13;
        }
        iVar13 = iVar12 + -0x10000;
        if (iVar12 < 0x8001) {
          iVar13 = iVar12;
        }
        if (iVar13 < 1) {
          uVar14 = uVar1;
          if ((iVar13 < 0) && (uVar14 = uVar1 - 0x78, -0x78 < iVar13)) {
            uVar14 = uVar16;
          }
        }
        else {
          uVar14 = uVar16;
          if (0x77 < iVar13) {
            uVar14 = uVar1 + 0x78;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar14;
        dVar32 = dVar29;
      }
      iVar12 = 0;
      if ((0x95 < (int)param_1[3]) && (iVar13 = param_1[3] + -0x96, iVar13 == (iVar13 / 100) * 100))
      {
        uVar33 = param_1[10];
        iVar13 = iVar12;
        do {
          dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),1);
          uVar39 = uVar39 & 0xffffffff00000000;
          FUN_14006c2f0(3,0,uVar33);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0xf);
        dVar31 = dVar31 - DAT_140539fa8;
        uVar33 = param_1[10];
        do {
          dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),1);
          uVar39 = uVar39 & 0xffffffff00000000;
          dVar32 = dVar31;
          FUN_14006c2f0(3,0,uVar33);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xf);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39,dVar32,dVar28);
    }
    iVar12 = param_1[3];
    if (0x1d < iVar12) {
      uVar36 = (undefined4)((ulonglong)dVar28 >> 0x20);
      uVar33 = (undefined4)((ulonglong)dVar32 >> 0x20);
      uVar42 = (undefined4)(uVar39 >> 0x20);
LAB_140054d61:
      uVar39 = CONCAT44(uVar42,0x97);
      iVar7 = FUN_1400c9580(iVar12,0x1e,5,6,0x96,uVar39,CONCAT44(uVar33,0x98),CONCAT44(uVar36,0x99),
                            0x98,0x97);
    }
    goto LAB_1400545a7;
  case 0x65:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar29 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar29 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar33 = DAT_140e41a50;
    if (param_1[3] == 0xf) {
      uVar36 = param_1[1];
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base();
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        puVar9[6] = 0x4014000000000000;
        puVar9[7] = 0x4014000000000000;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        *(undefined4 *)(puVar9 + 10) = 0xff;
        *puVar9 = 1;
        *(undefined4 *)(puVar9 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar9 + 0xc) = uVar33;
        puVar9[2] = 0x23;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        *(undefined4 *)(puVar9 + 8) = 0x1e;
        *(undefined4 *)((longlong)puVar9 + 0x54) = uVar36;
        puVar9[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
      DAT_140e45d28 = puVar9;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
    }
    fVar35 = DAT_140e445dc;
    fVar34 = DAT_140e445d8;
    iVar12 = param_1[3];
    if (0x1d < iVar12) {
      FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                    (double)(DAT_140e445d8 - (float)param_1[10]));
      dVar31 = DAT_14053a548;
      dVar29 = DAT_14053a248;
      iVar12 = iVar12 + -0x1e;
      iVar13 = 0;
      bVar25 = 0x173 < iVar12 % 0x2e8;
      if (iVar12 == (iVar12 / 0x174) * 0x174) {
        FUN_1403307c0();
        FUN_140332d90();
        dVar28 = 9.88131291682493e-323;
        uVar39 = uVar39 & 0xffffffffffff0000;
        dVar32 = dVar29;
        stage_entity_spawn_candidate(bVar25 + 0x108,10,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        fVar35 = DAT_140e445dc;
        fVar34 = DAT_140e445d8;
      }
      if ((0xd7 < (int)param_1[3]) &&
         (iVar12 = param_1[3] + -0xd8, iVar12 == (iVar12 / 0x174) * 0x174)) {
        dVar32 = (double)FUN_1403307c0();
        dVar28 = (double)FUN_140332d90();
        FUN_1401346a0(CONCAT44((float)(dVar28 * dVar31) + fVar35 + DAT_14053ad40,
                               (float)(dVar32 * dVar31) + fVar34),0xb4);
        dVar28 = 9.88131291682493e-323;
        uVar39 = uVar39 & 0xffffffffffff0000;
        stage_entity_spawn_candidate(bVar25 + 0x108,10,0);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        dVar32 = dVar29;
      }
      dVar29 = DAT_14053a030;
      if ((int)param_1[3] < 0x2d) {
        uVar37 = SUB84(DAT_140539f40,0);
        uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
      else {
        iVar12 = param_1[3] + -0x2d;
        if (iVar12 != (iVar12 / 0x5d) * 0x5d) goto LAB_140054500;
        uVar37 = param_1[10];
        do {
          dVar28 = 4.94065645841247e-324;
          uVar39 = uVar39 & 0xffffffff00000000;
          dVar32 = dVar29;
          FUN_14006c2f0(2,0,uVar37);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0x15);
        uVar37 = SUB84(DAT_140539f40,0);
        uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
    }
LAB_14005451b:
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39,dVar32,dVar28);
    }
    if (0x1d < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x1e,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    goto LAB_1400545a7;
  case 0x79:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar23 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar13 = iVar23 + 0x10000;
    if (-0x8001 < iVar23) {
      iVar13 = iVar23;
    }
    iVar23 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar23 = iVar13;
    }
    if (iVar23 < 1) {
      uVar14 = uVar1;
      if ((iVar23 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar23)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar23) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar29 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar29 = (double)FUN_140332d90();
    uVar33 = (undefined4)((ulonglong)dVar32 >> 0x20);
    uVar36 = (undefined4)((ulonglong)dVar28 >> 0x20);
    param_1[0xb] = (float)(dVar29 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (0x1d < (int)param_1[3]) {
      bVar20 = 0;
      iVar13 = 0x1e;
      dVar31 = (double)(param_1[3] + -0x1e) * _DAT_140539e00 + _DAT_14053a2d0;
      dVar29 = DAT_14053a340;
      if (dVar31 <= DAT_14053a340) {
        dVar29 = dVar31;
      }
      do {
        iVar23 = iVar12;
        if (iVar12 < 0x50) {
          iVar23 = 0x50;
        }
        if (param_1[3] == iVar13) {
          dVar28 = (double)CONCAT44((int)((ulonglong)dVar28 >> 0x20),0x14);
          uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0xc000);
          dVar32 = dVar29;
          stage_entity_spawn_candidate(bVar20 + 0x10f,99999999,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8);
        }
        uVar33 = (undefined4)((ulonglong)dVar32 >> 0x20);
        uVar36 = (undefined4)((ulonglong)dVar28 >> 0x20);
        iVar13 = iVar13 + iVar23;
        bVar20 = bVar20 + 1;
        iVar12 = iVar12 + -10;
      } while (-0xa0 < iVar12);
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39);
    }
    iVar12 = param_1[3];
    if (0x1d < iVar12) {
      uVar42 = (undefined4)(uVar39 >> 0x20);
      goto LAB_140054d61;
    }
LAB_1400545a7:
    uVar33 = DAT_14053ae30;
    param_1[0x15] = 0;
    uVar36 = DAT_14053b320;
    iVar17 = 0;
    iVar23 = iVar24;
    break;
  case 0x83:
    uVar10 = *puVar21;
    if ((int)uVar10 < 0x118) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar12 = (uVar15 & 0xffff) - (uint)uVar1;
      if (iVar12 < -0x8000) {
        iVar12 = iVar12 + 0x10000;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar14 = uVar1;
        if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
          uVar14 = uVar16;
        }
      }
      else {
        uVar14 = uVar16;
        if (0x1ff < iVar13) {
          uVar14 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar31 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar31 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    else {
      bVar4 = false;
    }
    dVar31 = DAT_14053a5f8;
    iVar23 = 0;
    iVar12 = 0xff;
    if (uVar10 - 0x104 < 0x14) {
      dVar27 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a5e8) * DAT_14053a890 * dVar5 *
                                     dVar26);
      iVar12 = (int)(dVar27 * dVar31);
    }
    iVar13 = 0;
    local_res18 = iVar23;
    if ((int)uVar10 < 0x118) {
      local_res18 = iVar12;
    }
    iVar17 = iVar23;
    if ((int)uVar10 < 0xf0) {
LAB_140056512:
      if ((int)uVar10 < 0x118) {
        iVar17 = iVar13;
      }
      if (((int)uVar10 < 0x1e) || (iVar23 = 0xff, 0xb3 < (int)uVar10)) {
        puVar9 = DAT_140e45d28;
        if ((uVar10 == 1) && (uVar33 = param_1[1], DAT_140e45d1c < 0x1000)) {
          puVar9 = (undefined8 *)_malloc_base(0x60);
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
          puVar9[5] = 0x3ff0000000000000;
          puVar9[6] = 0x3ff0000000000000;
          puVar9[7] = 0x3ff0000000000000;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          *(undefined4 *)(puVar9 + 10) = 0xff;
          *puVar9 = 1;
          puVar9[1] = 0x2f;
          puVar9[2] = 0x3c;
          puVar9[3] = 0;
          *(undefined4 *)(puVar9 + 4) = 0;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          *(undefined4 *)(puVar9 + 8) = 0x1e;
          *(undefined4 *)(puVar9 + 9) = 0x40;
          *(undefined4 *)((longlong)puVar9 + 0x54) = uVar33;
          puVar9[0xb] = 0;
          if (bVar25) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
      }
      else {
        dVar26 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a2d8) * _DAT_14053a478 *
                                       dVar5 * dVar26);
        iVar23 = (int)(dVar26 * dVar31);
        puVar9 = DAT_140e45d28;
      }
    }
    else {
      iVar13 = 0xff;
      if ((int)uVar10 < 0x104) {
        dVar26 = (double)FUN_140332d90();
        if ((int)uVar10 < 0x118) {
          iVar17 = (int)(dVar26 * dVar31);
        }
        puVar9 = DAT_140e45d28;
        if (0x1d < (int)uVar10) {
          iVar23 = 0xff;
        }
      }
      else {
        if (0x117 < (int)uVar10) goto LAB_140056512;
        dVar26 = (double)FUN_140332d90();
        if ((int)uVar10 < 0x118) {
          iVar17 = (int)(dVar26 * dVar31);
        }
        puVar9 = DAT_140e45d28;
        if (0x1d < (int)uVar10) {
          iVar23 = 0xff;
        }
      }
    }
    DAT_140e45d28 = puVar9;
    if (param_1[3] == 0x1e) {
      uVar41 = (undefined6)(uVar39 >> 0x10);
      stage_entity_spawn_candidate(0x125,99999999,0);
      dVar28 = 7.4109846876187e-322;
      uVar39 = CONCAT62(uVar41,0x4000);
      stage_entity_spawn_candidate(0x126,99999999,0);
      dVar32 = dVar29;
    }
    iVar12 = param_1[3];
    if (iVar12 == 0x118) {
      DAT_140e419bc = 1;
    }
    else if (iVar12 - 0x1eU < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(iVar12,0x1e,5,2,0x94,uVar39,dVar32,dVar28);
    }
    uVar36 = DAT_14053b320;
    uVar33 = DAT_14053ae30;
    if (param_1[3] - 0x28 < 0xf1) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x28,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
      uVar36 = DAT_14053b320;
      uVar33 = DAT_14053ae30;
    }
    break;
  case 0x8d:
    uVar10 = *puVar21;
    if ((int)uVar10 < 0x10e) {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar12 = (uVar15 & 0xffff) - (uint)uVar1;
      if (iVar12 < -0x8000) {
        iVar12 = iVar12 + 0x10000;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar14 = uVar1;
        if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
          uVar14 = uVar16;
        }
      }
      else {
        uVar14 = uVar16;
        if (0x1ff < iVar13) {
          uVar14 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar14;
      dVar28 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar28 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar28 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    else {
      bVar4 = false;
    }
    dVar28 = DAT_14053a5f8;
    iVar23 = 0;
    iVar12 = 0xff;
    if (uVar10 - 0x10e < 0x14) {
      dVar31 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a5f0) * DAT_14053a890 * dVar5 *
                                     dVar26);
      iVar12 = (int)(dVar31 * dVar28);
    }
    iVar13 = 0;
    local_res18 = iVar23;
    if ((int)uVar10 < 0x122) {
      local_res18 = iVar12;
    }
    iVar17 = iVar23;
    if ((int)uVar10 < 0xfa) {
LAB_140056971:
      if ((int)uVar10 < 0x122) {
        iVar17 = iVar13;
      }
      if (((int)uVar10 < 0x1e) || (iVar23 = 0xff, 0x10d < (int)uVar10)) {
        if (uVar10 != 1) goto LAB_1400569c9;
      }
      else {
LAB_140056992:
        dVar31 = (double)FUN_140332d90(((double)(int)uVar10 - DAT_14053a2d8) * _DAT_14053a3c8 *
                                       dVar5 * dVar26);
        iVar23 = (int)(dVar31 * dVar28);
LAB_1400569c9:
        if ((uVar10 != 0x32) && (puVar9 = DAT_140e45d28, uVar10 != 100)) goto LAB_140056aa4;
      }
      uVar33 = param_1[1];
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        puVar9[5] = 0x3ff0000000000000;
        puVar9[6] = 0x3ff0000000000000;
        puVar9[7] = 0x3ff0000000000000;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        *(undefined4 *)(puVar9 + 10) = 0xff;
        *puVar9 = 1;
        puVar9[1] = 0x2f;
        puVar9[2] = 0x3c;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        *(undefined4 *)(puVar9 + 8) = 0x1e;
        *(undefined4 *)(puVar9 + 9) = 0x40;
        *(undefined4 *)((longlong)puVar9 + 0x54) = uVar33;
        puVar9[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
    }
    else {
      iVar13 = 0xff;
      if ((int)uVar10 < 0x10e) {
        dVar31 = (double)FUN_140332d90();
        if ((int)uVar10 < 0x122) {
          iVar17 = (int)(dVar31 * dVar28);
        }
        goto LAB_140056992;
      }
      if (0x121 < (int)uVar10) goto LAB_140056971;
      dVar31 = (double)FUN_140332d90();
      if ((int)uVar10 < 0x122) {
        iVar17 = (int)(dVar31 * dVar28);
      }
      puVar9 = DAT_140e45d28;
      if (0x1d < (int)uVar10) {
        iVar23 = 0xff;
      }
    }
LAB_140056aa4:
    DAT_140e45d28 = puVar9;
    uVar33 = DAT_14053ae30;
    if (param_1[3] == 0x1e) {
      uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
      dVar32 = dVar29;
      stage_entity_spawn_candidate(0x127,99999999,0);
    }
    uVar15 = param_1[3];
    if ((uVar15 < 0xd2) && ((uVar15 & 1) == 0)) {
      uVar10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      uVar39 = CONCAT62((int6)(uVar39 >> 0x10),
                        (short)(DAT_140e9fd1c / 0xd2f1) * 0x2d0f + (short)DAT_140e9fd1c + 0x5688);
      stage_entity_spawn_candidate(0x128,99999999,0,uVar10,0,uVar39,dVar29,0x14,1,param_1[1]);
      dVar32 = dVar29;
    }
    if (param_1[3] == 0x10e) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar12 = param_1[3];
    if (iVar12 == 0x136) {
      DAT_140e419bc = 1;
LAB_140056c48:
      if (iVar12 - 0x1eU < 10) {
        uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
        iVar7 = FUN_1400c9580(iVar12,0x1e,5,2,0x94,uVar39,dVar32);
      }
    }
    else {
      if (iVar12 != 0xd20) goto LAB_140056c48;
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3fb999999999999a;
      param_1[3] = 0;
    }
    uVar36 = DAT_14053b320;
    if (0x27 < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x28,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
      uVar36 = DAT_14053b320;
    }
    break;
  case 0x8e:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar12 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar7 = iVar12 + 0x10000;
    if (-0x8001 < iVar12) {
      iVar7 = iVar12;
    }
    iVar12 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar12 = iVar7;
    }
    if (iVar12 < 1) {
      uVar14 = uVar1;
      if ((iVar12 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar12)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar12) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar29 = (double)FUN_1403307c0();
    uVar33 = (undefined4)(uVar39 >> 0x20);
    uVar36 = (undefined4)((ulonglong)dVar32 >> 0x20);
    uVar42 = (undefined4)((ulonglong)dVar28 >> 0x20);
    *pfVar19 = (float)(dVar29 * *(double *)(param_1 + 0x12)) + *pfVar19;
    dVar32 = (double)FUN_140332d90();
    uVar15 = *puVar21;
    iVar7 = 0xff;
    *pfVar18 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar18;
    if (uVar15 - 0xf0 < 0x3c) {
      dVar32 = (double)FUN_140332d90(((double)(int)uVar15 - DAT_14053a548) * DAT_14053a628 * dVar5 *
                                     dVar26);
      iVar7 = (int)(dVar32 * DAT_14053a5f8);
    }
    local_res18 = 0;
    uVar39 = CONCAT44(uVar33,0x9b);
    iVar23 = iVar24;
    if ((int)uVar15 < 300) {
      iVar23 = iVar7;
    }
    if (0x28 < (int)uVar15) {
      local_res18 = 0xff;
    }
    iVar7 = FUN_1400c9580(uVar15,0,5,4,0x9a,uVar39,CONCAT44(uVar36,0x9c),CONCAT44(uVar42,0x9d));
    uVar36 = DAT_14053b320;
    iVar17 = 0;
    uVar33 = DAT_14053ae30;
    if (299 < (int)param_1[3]) {
      param_1[0x15] = 0;
      uVar36 = DAT_14053b320;
      uVar33 = DAT_14053ae30;
    }
    break;
  case 0x97:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar31 = (double)FUN_1403307c0();
    *pfVar19 = (float)(dVar31 * *(double *)(param_1 + 0x12)) + *pfVar19;
    dVar30 = (double)FUN_140332d90();
    dVar6 = DAT_14053a890;
    dVar27 = DAT_14053a5f8;
    dVar31 = DAT_14053a5e8;
    uVar15 = *puVar21;
    *pfVar18 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + *pfVar18;
    if (uVar15 - 0x104 < 0x14) {
      dVar30 = (double)FUN_140332d90(((double)(int)uVar15 - dVar31) * dVar6 * dVar5 * dVar26);
      iVar12 = 0xff;
      local_res18 = (int)(dVar30 * dVar27);
    }
    else if ((int)uVar15 < 0x118) {
      local_res18 = 0xff;
      if ((int)uVar15 < 0xf0) {
        iVar12 = 0;
      }
      else {
        iVar12 = 0xff;
        if ((int)uVar15 < 0x104) {
          dVar30 = (double)FUN_140332d90(((double)(int)uVar15 - dVar31) * dVar6 * dVar5 * dVar26);
          iVar12 = (int)(dVar30 * dVar27);
        }
      }
    }
    else {
      local_res18 = 0;
      iVar12 = 0xff;
    }
    iVar23 = 0;
    if (uVar15 - 0x104 < 0x14) {
      dVar31 = (double)FUN_140332d90(((double)(int)uVar15 - dVar31) * dVar6 * dVar5 * dVar26);
      iVar12 = (int)(dVar31 * dVar27);
    }
    iVar17 = iVar23;
    if ((int)uVar15 < 0x118) {
      iVar17 = iVar12;
    }
    if (((int)uVar15 < 0x1e) || (iVar23 = 0xff, 0xb3 < (int)uVar15)) {
      puVar9 = DAT_140e45d28;
      if ((uVar15 == 1) && (uVar33 = param_1[1], DAT_140e45d1c < 0x1000)) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar9 = 1;
        puVar9[1] = 0x2f;
        puVar9[2] = 0x3c;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0x3ff0000000000000;
        puVar9[6] = 0x3ff0000000000000;
        puVar9[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar9 + 8) = 0x1e;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0x40;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        *(undefined4 *)(puVar9 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x54) = uVar33;
        puVar9[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
    }
    else {
      dVar31 = (double)FUN_140332d90();
      iVar23 = (int)(dVar31 * dVar27);
      puVar9 = DAT_140e45d28;
    }
    DAT_140e45d28 = puVar9;
    if (param_1[3] == 0x1e) {
      dVar28 = 1.13635098543487e-321;
      uVar39 = CONCAT62((int6)(uVar39 >> 0x10),0x4000);
      stage_entity_spawn_candidate(0x12d,99999999,0);
      dVar32 = dVar29;
    }
    iVar12 = param_1[3];
    if (iVar12 == 0x118) {
      DAT_140e419bc = 1;
    }
    else if (iVar12 - 0x1eU < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(iVar12,0x1e,5,2,0x94,uVar39,dVar32,dVar28);
    }
    if (param_1[3] - 0x28 < 0xf1) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x28,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    if (((int)param_1[7] < (int)(DAT_140e41b0c + (DAT_140e41b0c >> 0x1f & 3U)) >> 2) ||
       (uVar36 = DAT_14053b320, uVar33 = DAT_14053ae30, DAT_140e4430c < 0x5dc)) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
      uVar36 = DAT_14053b320;
      uVar33 = DAT_14053ae30;
    }
    break;
  case 0x98:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar12 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar7 = iVar12 + 0x10000;
    if (-0x8001 < iVar12) {
      iVar7 = iVar12;
    }
    iVar12 = iVar7 + -0x10000;
    if (iVar7 < 0x8001) {
      iVar12 = iVar7;
    }
    if (iVar12 < 1) {
      uVar14 = uVar1;
      if ((iVar12 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar12)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar12) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar32 = (double)FUN_1403307c0();
    uVar33 = (undefined4)(uVar39 >> 0x20);
    *pfVar19 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar19;
    dVar32 = (double)FUN_140332d90();
    uVar39 = CONCAT44(uVar33,0x9f);
    *pfVar18 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar18;
    iVar7 = FUN_1400c9580(*puVar21,0,5,2,0x9e,uVar39);
    uVar36 = DAT_14053b320;
    uVar33 = DAT_14053ae30;
    local_res18 = 0xff;
    iVar23 = 0xff;
    if (*puVar21 == 0x96) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd999999999999a;
      param_1[3] = 0;
      local_res18 = 0xff;
      iVar17 = 0;
    }
    else {
      iVar17 = 0;
    }
    break;
  case 0x99:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar13 = (uVar15 & 0xffff) - (uint)uVar1;
    iVar12 = iVar13 + 0x10000;
    if (-0x8001 < iVar13) {
      iVar12 = iVar13;
    }
    iVar13 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar13 = iVar12;
    }
    if (iVar13 < 1) {
      uVar14 = uVar1;
      if ((iVar13 < 0) && (uVar14 = uVar1 - 0x200, -0x200 < iVar13)) {
        uVar14 = uVar16;
      }
    }
    else {
      uVar14 = uVar16;
      if (0x1ff < iVar13) {
        uVar14 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar32 = (double)FUN_1403307c0();
    *pfVar19 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar19;
    dVar32 = (double)FUN_140332d90();
    *pfVar18 = (float)(dVar32 * *(double *)(param_1 + 0x12)) + *pfVar18;
    puVar9 = DAT_140e45d28;
    if ((*puVar21 == 1) && (uVar33 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar9 = 1;
      puVar9[1] = 0x2f;
      puVar9[2] = 0x3c;
      puVar9[3] = 0;
      *(undefined4 *)(puVar9 + 4) = 0;
      *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
      puVar9[5] = 0x3ff0000000000000;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x1e;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0x40;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      *(undefined4 *)(puVar9 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x54) = uVar33;
      puVar9[0xb] = 0;
      if (bVar25) {
        DAT_140e45d78 = puVar9;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
    DAT_140e45d28 = puVar9;
    uVar15 = param_1[3];
    if ((0x1d < (int)uVar15) && (uVar15 - 0x1e == ((int)(uVar15 - 0x1e) / 0x168) * 0x168)) {
      uVar10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ DAT_140e9fd18;
      uVar39 = CONCAT62((int6)(uVar39 >> 0x10),
                        (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x134,10,0,uVar10,0,uVar39,0,0x28,1,param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    uVar15 = param_1[3];
    if ((0xd1 < (int)uVar15) && (uVar15 - 0xd2 == ((int)(uVar15 - 0xd2) / 0x168) * 0x168)) {
      uVar10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      uVar39 = CONCAT62((int6)(uVar39 >> 0x10),
                        (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x135,10,0,uVar10,0,uVar39,0,0x28,1,param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if (param_1[3] - 0x14 < 10) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x95);
      iVar7 = FUN_1400c9580(param_1[3],0x14,5,2,0x94,uVar39);
    }
    if (0x1d < (int)param_1[3]) {
      uVar39 = CONCAT44((int)(uVar39 >> 0x20),0x97);
      iVar7 = FUN_1400c9580(param_1[3],0x1e,5,6,0x96,uVar39,0x98,0x99,0x98,0x97);
    }
    uVar33 = DAT_14053ae30;
    local_res18 = 0xff;
    param_1[0x15] = 0;
    uVar36 = DAT_14053b320;
    iVar17 = local_res10;
    iVar23 = 0xff;
    break;
  case 200:
    FUN_140003ad0(param_1);
    uVar15 = *puVar21;
    if (uVar15 < 0x3c) {
      dVar31 = (double)FUN_140332d90(((double)(int)uVar15 - _DAT_14053b158) * DAT_14053a628 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar24 = (int)(dVar31 * DAT_14053a5f8);
LAB_1400578a2:
      uVar33 = (undefined4)(uVar39 >> 0x20);
      iVar7 = DAT_1407c7798 + 3;
      iVar12 = DAT_1407c7798 * 10;
      if (uVar15 - 0x3c < 0xb4) {
        uVar39 = 0;
        dVar32 = (double)FUN_1401349e0(uVar15,0x3c,0x4c,0xe0,0xf0,0,dVar29);
        uVar39 = uVar39 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1);
        uVar39 = uVar39 & 0xffffffffffff0000;
        dVar28 = dVar32;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar7 * 4),0x6e,1);
        uVar33 = (undefined4)(uVar39 >> 0x20);
        if (uVar15 == 0x4c) {
          dVar28 = 1.25986739689518e-321;
          dVar32 = (double)(ulonglong)DAT_14053ac80;
          FUN_14012e070(iVar12 + 99,4);
        }
        else {
          lVar2 = DAT_140e47908;
          if (uVar15 == 0xe0) {
            while (uVar33 = (undefined4)(uVar39 >> 0x20), lVar2 != 0) {
              lVar2 = *(longlong *)(lVar2 + 0x238);
              FUN_140323ce8();
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar39 = CONCAT44(uVar33,0x9f);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar7 = FUN_1400c9580(param_1[3],0,5,2,0x9e,uVar39,dVar32,dVar28);
      local_res18 = 0xff;
      puVar9 = DAT_140e45d28;
    }
    else {
      local_res18 = 0;
      if ((int)uVar15 < 0x3c) {
        iVar24 = 0xff;
      }
      if ((int)uVar15 < 0xf0) goto LAB_1400578a2;
      puVar9 = DAT_140e45d28;
      if (uVar15 == 0xf0) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar33 = param_1[0xb];
        uVar36 = param_1[10];
        puVar9 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar9 = (undefined8 *)_malloc_base(0x60);
          if (puVar9 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar9 + 0x14) = uVar36;
          *(undefined4 *)(puVar9 + 3) = uVar33;
          *(undefined4 *)((longlong)puVar9 + 0x1c) = uVar36;
          *(undefined4 *)(puVar9 + 4) = uVar33;
          *puVar9 = 1;
          puVar9[1] = 0x10;
          *(undefined4 *)(puVar9 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
          puVar9[5] = 0;
          puVar9[6] = 0x3ff0000000000000;
          puVar9[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar9 + 8) = 0;
          *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
          *(undefined4 *)(puVar9 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
          puVar9[10] = 0xff;
          puVar9[0xb] = 0;
          if (bVar25) {
            DAT_140e45d78 = puVar9;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar9;
          }
        }
      }
    }
    DAT_140e45d28 = puVar9;
    uVar36 = DAT_14053b320;
    uVar33 = DAT_14053ae30;
    iVar17 = local_res10;
    iVar23 = iVar24;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
      iVar17 = 0;
    }
  }
  uVar15 = DAT_140e418c8;
  if ((DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) && (bVar4)) {
    uVar15 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
    uVar11 = DAT_1407c7798 * 0x457 + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar10 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ uVar10) % 0x12d + 0xd2);
    uVar15 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar10 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0xb4);
  }
  if (param_1[5] == 0x99) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) goto LAB_140057c73;
      stage_entity_spawn_candidate
                (0xc3,99999999,1,uVar15,0,uVar39 & 0xffffffffffff0000,CONCAT44(uVar38,uVar37),0x14,0
                 ,DAT_140e44308);
      param_1[0x17] = 1;
    }
    else if (param_1[0x17] != 1) goto LAB_140057c73;
    param_1[0x15] = 1;
    if (DAT_140e44654 < 0x3d) {
      param_1[0x17] = 0;
      param_1[0x15] = 0;
    }
  }
LAB_140057c73:
  if (0 < local_res18) {
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar7 * 4),0x1e,7);
    if (0 < iVar17) {
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar7 * 4),0x1e,8);
    }
  }
  if (0 < iVar23) {
    FUN_1400c2670(3,DAT_140e45190,4,0xe,uVar33,0xff,0xff,0xff,iVar23,DAT_14053b2f8);
    FUN_1400c2670(4,DAT_140e45194,5,0xf,uVar33,0x80,0x80,0x80,iVar23 / 2,uVar36);
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


