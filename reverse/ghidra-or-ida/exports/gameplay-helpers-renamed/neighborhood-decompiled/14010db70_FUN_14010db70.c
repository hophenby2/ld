// Function: FUN_14010db70 @ 14010db70
// Decompile completed: true

void FUN_14010db70(void)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  float *pfVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  float fVar22;
  undefined4 uVar23;
  ushort *local_res10;
  longlong local_res18;
  
  fVar9 = DAT_14053accc;
  fVar8 = DAT_14053ac80;
  dVar6 = DAT_14053a340;
  uVar13 = 0x32;
  uVar14 = 0;
  bVar5 = false;
  uVar20 = (undefined4)DAT_14053a2b0;
  uVar23 = SUB84(DAT_14053a340,0);
  if ((DAT_140e44658 == 0) && (-1 < DAT_140e45d18)) {
    FUN_140109660(0,DAT_140e445d8 + DAT_14053ac58,DAT_140e445dc - DAT_14053ac80,uVar20,0xc000,0x82,
                  DAT_14053ac80);
    FUN_140109660(0,DAT_140e445d8 - DAT_14053ac58,DAT_140e445dc - fVar8,uVar20,0xc000,0x82,fVar8);
    bVar4 = false;
    fVar22 = fVar8;
  }
  else {
    bVar4 = true;
    FUN_140109660(1,DAT_140e445d8 + DAT_14053ac58,DAT_140e445dc - DAT_14053ac80,uVar23,0xc000,0x96,
                  DAT_14053accc);
    FUN_140109660(1,DAT_140e445d8 - DAT_14053ac58,DAT_140e445dc - fVar8,uVar23,0xc000,0x96,fVar9);
    uVar20 = uVar23;
    fVar22 = fVar9;
  }
  dVar7 = DAT_14053a3a0;
  pfVar15 = (float *)&DAT_140e44608;
  local_res10 = &DAT_140e44624;
  local_res18 = 4;
  do {
    uVar3 = *local_res10;
    fVar1 = pfVar15[-1];
    dVar17 = (double)uVar3 * DAT_14053a020 * DAT_140539d28;
    dVar16 = (double)FUN_1403307c0(dVar17);
    fVar2 = *pfVar15;
    fVar19 = (float)(dVar16 * dVar6) + fVar1;
    dVar16 = (double)FUN_140332d90(dVar17);
    iVar12 = DAT_140e445d0;
    iVar11 = DAT_140e445c8;
    iVar10 = DAT_140e445c0;
    fVar18 = (float)(dVar16 * dVar6) + fVar2;
    uVar21 = (undefined4)DAT_14053a278;
    if (DAT_140e44644 == 0) {
      if ((DAT_140e445c0 == 0) && (DAT_140e445c4 == 1)) {
        if (bVar4) {
          dVar16 = (double)FUN_1403307c0(dVar17);
          fVar19 = (float)(dVar16 * dVar7) + fVar1;
          dVar17 = (double)FUN_140332d90(dVar17);
          dVar17 = dVar17 * dVar7;
          uVar13 = 0x23;
          uVar14 = 10;
          uVar21 = uVar23;
          fVar22 = fVar9;
        }
        else {
          uVar13 = 0x19;
          uVar14 = 8;
          fVar22 = fVar8;
          if ((DAT_140e445d0 - 1U & 0xfffffffd) != 0) goto LAB_14010e02f;
          dVar16 = (double)FUN_1403307c0(dVar17);
          dVar16 = dVar16 * DAT_14053a380;
          dVar17 = (double)FUN_140332d90(dVar17);
          uVar13 = 0x1e;
LAB_14010e004:
          fVar19 = (float)dVar16 + fVar1;
          uVar14 = 9;
          dVar17 = dVar17 * DAT_14053a380;
          uVar21 = (int)DAT_14053a2d8;
          fVar22 = DAT_14053acb0;
        }
LAB_14010e023:
        fVar18 = (float)dVar17 + fVar2;
LAB_14010e02f:
        bVar5 = true;
        uVar20 = uVar21;
      }
      else if (!bVar5) {
        if (bVar4) {
          dVar16 = (double)FUN_1403307c0(dVar17);
          fVar19 = (float)(dVar16 * dVar7) + fVar1;
          dVar17 = (double)FUN_140332d90(dVar17);
          uVar13 = 0x46;
          uVar14 = 4;
          fVar18 = (float)(dVar17 * dVar7) + fVar2;
          uVar20 = uVar23;
          fVar22 = fVar9;
        }
        else {
          uVar14 = 2;
          if ((DAT_140e445d0 - 1U & 0xfffffffd) == 0) {
            dVar16 = (double)FUN_1403307c0(dVar17);
            fVar19 = (float)(dVar16 * DAT_14053a380) + fVar1;
            dVar17 = (double)FUN_140332d90(dVar17);
            uVar13 = 0x3c;
            uVar14 = 3;
            uVar20 = (undefined4)DAT_14053a2d8;
            fVar18 = (float)(dVar17 * DAT_14053a380) + fVar2;
            fVar22 = DAT_14053acb0;
          }
        }
      }
    }
    else {
      if ((DAT_140e445c0 == 1) && (DAT_140e445c8 == 1)) {
        if (bVar4) {
          dVar16 = (double)FUN_1403307c0(dVar17);
          fVar19 = (float)(dVar16 * dVar7) + fVar1;
          dVar17 = (double)FUN_140332d90(dVar17);
          dVar17 = dVar17 * dVar7;
          uVar13 = 0x3f;
          uVar14 = 10;
          uVar21 = uVar23;
          fVar22 = fVar9;
          goto LAB_14010e023;
        }
        uVar13 = 0x2d;
        uVar14 = 8;
        fVar22 = fVar8;
        if (DAT_140e445d0 - 2U < 2) {
          dVar16 = (double)FUN_1403307c0(dVar17);
          dVar16 = dVar16 * DAT_14053a380;
          dVar17 = (double)FUN_140332d90(dVar17);
          uVar13 = 0x36;
          goto LAB_14010e004;
        }
        goto LAB_14010e02f;
      }
      if (bVar5) goto LAB_14010e10c;
      if (bVar4) {
        dVar16 = (double)FUN_1403307c0(dVar17);
        dVar16 = dVar16 * dVar7;
        dVar17 = (double)FUN_140332d90(dVar17);
        dVar17 = dVar17 * dVar7;
        uVar13 = 0x46;
        uVar14 = 7;
        uVar20 = uVar23;
        fVar22 = fVar9;
LAB_14010e0de:
        fVar19 = (float)dVar16 + fVar1;
        fVar18 = (float)dVar17 + fVar2;
      }
      else {
        uVar14 = 5;
        if (DAT_140e445d0 - 2U < 2) {
          dVar16 = (double)FUN_1403307c0(dVar17);
          dVar16 = dVar16 * DAT_14053a380;
          dVar17 = (double)FUN_140332d90(dVar17);
          dVar17 = dVar17 * DAT_14053a380;
          uVar13 = 0x3c;
          uVar14 = 6;
          uVar20 = (undefined4)DAT_14053a2d8;
          fVar22 = DAT_14053acb0;
          goto LAB_14010e0de;
        }
      }
      if ((iVar10 == 0) && (iVar11 == 0)) {
        if (bVar4) {
          uVar13 = 0x3f;
        }
        else {
          uVar13 = 0x2d;
          if (iVar12 - 2U < 2) {
            uVar13 = 0x36;
          }
        }
      }
    }
LAB_14010e10c:
    FUN_140109660(uVar14,fVar19,fVar18,uVar20,uVar3,uVar13,fVar22);
    pfVar15 = pfVar15 + 2;
    local_res10 = local_res10 + 1;
    local_res18 = local_res18 + -1;
    if (local_res18 == 0) {
      if (bVar4) {
        FUN_140184700(DAT_140e44190 << 4,DAT_140e47260);
        uVar20 = DAT_140e47260;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e4722c);
        uVar20 = DAT_140e4722c;
      }
      FUN_14018a340(uVar20,1,1);
      return;
    }
  } while( true );
}


