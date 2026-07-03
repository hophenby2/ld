// Function: state_08_gallery_unlock_or_achievement_candidate @ 1400b8890
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400bc3d1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_08_gallery_unlock_or_achievement_candidate(void)

{
  undefined4 uVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  FILE *pFVar13;
  uint uVar14;
  int iVar15;
  ulonglong uVar16;
  short sVar17;
  undefined4 uVar18;
  ulonglong uVar19;
  longlong lVar20;
  int *piVar21;
  bool bVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  float fVar33;
  undefined1 auStack_338 [32];
  undefined8 local_318;
  uint local_310;
  undefined8 local_308;
  undefined8 uStack_300;
  uint local_2f8;
  uint local_2f0;
  uint local_2e8;
  undefined4 local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d0;
  undefined4 local_2c8;
  undefined4 local_2c0;
  undefined4 local_2b8;
  undefined4 local_2b0;
  undefined4 local_2a8;
  undefined4 local_2a0;
  float local_298;
  int local_288 [83];
  undefined8 local_13c;
  FILE *local_e8;
  int local_e0;
  undefined4 uStack_dc;
  ulonglong local_d8;
  
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_338;
  uVar14 = 10;
  iVar15 = 1;
  fVar33 = 0.0;
  local_298 = 0.0;
LAB_1400b8930:
  do {
    iVar7 = FUN_1401351a0(iVar15,0xffffffff);
    if (0 < iVar7) {
      switch(iVar15) {
      case 1:
        uVar14 = 0xb;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 2:
        uVar14 = 0x16;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 3:
        uVar14 = 0x20;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 4:
        uVar14 = 0x29;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 5:
        uVar14 = 0x33;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 6:
        uVar14 = 0x3d;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 7:
        uVar14 = 0x49;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 8:
        uVar14 = 0x52;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 9:
        uVar14 = 0x54;
        iVar15 = iVar15 + 1;
        goto LAB_1400b8930;
      case 10:
        uVar14 = 0x67;
        goto LAB_1400b89bc;
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < 0xb);
LAB_1400b89bc:
  uVar19 = 0;
  iVar7 = 0;
  iVar15 = 3;
  uVar16 = uVar19;
  do {
    if ((longlong)(int)uVar14 < (longlong)uVar16) {
LAB_1400b89ea:
      iVar9 = iVar7;
    }
    else {
      iVar8 = FUN_1401351a0(1,0xffffffff);
      iVar9 = 1;
      if (iVar8 < 1) goto LAB_1400b89ea;
    }
    local_288[uVar16] = iVar9;
    if (iVar15 + -3 < (int)uVar14) {
      iVar8 = FUN_1401351a0(1,0xffffffff);
      iVar9 = 1;
      if (iVar8 < 1) goto LAB_1400b8a0d;
    }
    else {
LAB_1400b8a0d:
      iVar9 = iVar7;
    }
    local_288[uVar16 + 1] = iVar9;
    if ((int)uVar14 < iVar15 + -1) {
LAB_1400b8a30:
      iVar9 = iVar7;
    }
    else {
      iVar8 = FUN_1401351a0(1,0xffffffff);
      iVar9 = 1;
      if (iVar8 < 1) goto LAB_1400b8a30;
    }
    local_288[uVar16 + 2] = iVar9;
    if ((int)uVar14 < iVar15) {
LAB_1400b8a50:
      iVar9 = iVar7;
    }
    else {
      iVar8 = FUN_1401351a0(1,0xffffffff);
      iVar9 = 1;
      if (iVar8 < 1) goto LAB_1400b8a50;
    }
    local_288[uVar16 + 3] = iVar9;
    if (iVar15 < (int)uVar14) {
      iVar8 = FUN_1401351a0(1,0xffffffff);
      iVar9 = 1;
      if (iVar8 < 1) goto LAB_1400b8a70;
    }
    else {
LAB_1400b8a70:
      iVar9 = iVar7;
    }
    local_288[uVar16 + 4] = iVar9;
    iVar9 = 0;
    if ((int)uVar14 < iVar15 + 2) {
LAB_1400b8a93:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8a93;
    }
    local_288[uVar16 + 5] = iVar8;
    if ((int)uVar14 < iVar15 + 3) {
LAB_1400b8ab6:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8ab6;
    }
    local_288[uVar16 + 6] = iVar8;
    if ((int)uVar14 < iVar15 + 4) {
LAB_1400b8ad9:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8ad9;
    }
    local_288[uVar16 + 7] = iVar8;
    if ((int)uVar14 < iVar15 + 5) {
LAB_1400b8afc:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8afc;
    }
    local_288[uVar16 + 8] = iVar8;
    if ((int)uVar14 < iVar15 + 6) {
LAB_1400b8b1f:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8b1f;
    }
    local_288[uVar16 + 9] = iVar8;
    if ((int)uVar14 < iVar15 + 7) {
LAB_1400b8b42:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8b42;
    }
    local_288[uVar16 + 10] = iVar8;
    if ((int)uVar14 < iVar15 + 8) {
LAB_1400b8b65:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8b65;
    }
    local_288[uVar16 + 0xb] = iVar8;
    if ((int)uVar14 < iVar15 + 9) {
LAB_1400b8b88:
      iVar8 = iVar9;
    }
    else {
      iVar10 = FUN_1401351a0(1,0xffffffff);
      iVar8 = 1;
      if (iVar10 < 1) goto LAB_1400b8b88;
    }
    dVar27 = DAT_14053a628;
    dVar26 = DAT_14053a020;
    dVar25 = DAT_140539d28;
    local_288[uVar16 + 0xc] = iVar8;
    iVar15 = iVar15 + 0xd;
    uVar16 = uVar16 + 0xd;
  } while ((longlong)uVar16 < 0x68);
  if (DAT_140e41b68 < 9) {
    local_13c = 0;
  }
  else {
    local_13c = 0x100000001;
    if (uVar14 < 0x54) {
      uVar14 = 0x54;
    }
  }
  uVar31 = SUB84(DAT_140539d28,0);
  uVar32 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  if (DAT_140e418c8 < 0x3c) {
    dVar24 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                   DAT_140539d28);
    fVar33 = (float)(dVar24 * DAT_14053a970) - DAT_14053b00c;
    local_298 = fVar33;
  }
  if (0 < (int)DAT_140e45fac) {
    dVar25 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * dVar27 * dVar26 * dVar25);
    fVar33 = (float)(dVar25 * _DAT_14053b2b8) + 0.0;
    local_298 = fVar33;
  }
  uVar18 = DAT_140e467f0;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar18;
  *(undefined8 *)(puVar12 + 1) = 10;
  *(undefined8 *)(puVar12 + 3) = 0;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar12;
  }
  uVar18 = DAT_140e4602c;
  DAT_140e46c88 = puVar12;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar18;
  *(undefined8 *)(puVar12 + 1) = 0x65;
  *(undefined8 *)(puVar12 + 3) = 0;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  DAT_140e46c88 = puVar12;
  FUN_1400d3a60();
  if ((DAT_140e418c8 < 0x3c) || (DAT_140e45fac != 0)) goto LAB_1400b90a8;
  if (uVar14 != 0) {
    bVar22 = false;
    if (DAT_140e8cf10 == 1) {
LAB_1400b8e10:
      bVar2 = true;
    }
    else {
      bVar2 = bVar22;
      if (0x13 < DAT_140e8cf10) {
        uVar11 = DAT_140e8cf10 - 0x14U & 0x80000007;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
        }
        if (uVar11 == 0) goto LAB_1400b8e10;
      }
    }
    if ((DAT_140e8cf14 < 1) && (bVar2)) {
      uVar11 = uVar14;
      if (1 < (int)DAT_140e45274) {
        uVar11 = DAT_140e45274 - 1;
      }
      DAT_140e46014 = 1;
      DAT_140e45274 = uVar11;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e467fc = 1;
    }
    if (DAT_140e8cf14 == 1) {
LAB_1400b8e99:
      bVar22 = true;
    }
    else if (0x13 < DAT_140e8cf14) {
      uVar11 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
      }
      if (uVar11 == 0) goto LAB_1400b8e99;
    }
    if ((DAT_140e8cf10 < 1) && (bVar22)) {
      if ((int)DAT_140e45274 < (int)uVar14) {
        DAT_140e45274 = DAT_140e45274 + 1;
      }
      else {
        DAT_140e45274 = 1;
      }
      DAT_140e46014 = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e467fc = 1;
    }
  }
  if ((DAT_140e467c0 == 1) && (DAT_140e467fc == 0)) {
    DAT_140e467fc = 0;
    lVar20 = DAT_140e47908;
    while (lVar20 != 0) {
      lVar20 = *(longlong *)(lVar20 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    DAT_140e45274 = 0;
    DAT_140e46064 = 0;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e45fac = DAT_140e45fac + 1;
    DAT_140e46014 = 0;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 0xffffffff;
    fopen_s((FILE **)&local_e0,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_dc,local_e0));
    FUN_140323e90(CONCAT44(uStack_dc,local_e0));
    DAT_140e471fc = 0xb4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
  }
  if ((DAT_140e467e4 != 1) &&
     (DAT_140e467e0 != 1 &&
      (DAT_140e467dc != 1 &&
      (DAT_140e467d8 != 1 &&
      (DAT_140e467d4 != 1 &&
      (DAT_140e467cc._4_4_ != 1 &&
      ((int)DAT_140e467cc != 1 &&
      (DAT_140e467c8 != 1 &&
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_1400b90a8:
  uVar18 = DAT_140e4604c;
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar12[3] = fVar33;
  *puVar12 = uVar18;
  *(undefined8 *)(puVar12 + 1) = 0x65;
  puVar12[4] = 0;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = 0xff;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar22) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
  }
  fVar4 = DAT_14053ad10;
  fVar3 = DAT_14053acbc;
  fVar30 = fVar33 + DAT_14053adb4;
  local_e0 = DAT_140e45274 - (int)(DAT_140e45274 - 1) % 10;
  pFVar13 = (FILE *)(longlong)(int)uVar14;
  lVar20 = (longlong)local_e0;
  local_e8 = pFVar13;
  iVar15 = local_e0 * 4;
  piVar21 = local_288 + lVar20;
  DAT_140e46c88 = puVar12;
  uVar14 = DAT_140e45274;
  do {
    iVar7 = (int)uVar19;
    uVar18 = 0xff;
    if (uVar14 != local_e0 + iVar7) {
      uVar18 = 0x80;
    }
    fVar28 = (float)iVar7 * fVar3 + fVar4;
    puVar12 = DAT_140e46c88;
    if (lVar20 <= (longlong)pFVar13) {
      if (*piVar21 == 0) {
        uVar1 = *(undefined4 *)(&DAT_140e46070 + (longlong)DAT_140e441b4 * 4);
        puVar12 = (undefined4 *)_malloc_base(0x48);
        if (puVar12 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar12[3] = fVar30;
        *(undefined2 *)(puVar12 + 5) = 0;
        *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 0x10) = 0;
        puVar12[4] = fVar28;
        *puVar12 = uVar1;
        *(undefined8 *)(puVar12 + 1) = 0x66;
        puVar12[10] = uVar18;
        puVar12[0xb] = uVar18;
        puVar12[0xc] = uVar18;
        puVar12[0xd] = 0xff;
        *(undefined8 *)(puVar12 + 0xe) = 1;
      }
      else {
        uVar1 = *(undefined4 *)(&DAT_140e46070 + (longlong)(DAT_140e441b4 + iVar15) * 4);
        puVar12 = (undefined4 *)_malloc_base(0x48);
        if (puVar12 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar12[3] = fVar30;
        *(undefined2 *)(puVar12 + 5) = 0;
        *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 0x10) = 0;
        puVar12[4] = fVar28;
        *puVar12 = uVar1;
        *(undefined8 *)(puVar12 + 1) = 0x66;
        puVar12[10] = uVar18;
        puVar12[0xb] = uVar18;
        puVar12[0xc] = uVar18;
        puVar12[0xd] = 0xff;
        *(undefined8 *)(puVar12 + 0xe) = 1;
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar12;
      }
      pFVar13 = local_e8;
      uVar14 = DAT_140e45274;
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
        uVar14 = DAT_140e45274;
      }
    }
    DAT_140e46c88 = puVar12;
    uVar18 = DAT_140e45db0;
    uVar19 = (ulonglong)(iVar7 + 1U);
    iVar15 = iVar15 + 4;
    lVar20 = lVar20 + 1;
    piVar21 = piVar21 + 1;
  } while ((int)(iVar7 + 1U) < 10);
  if (local_288[(int)uVar14] == 1) {
    uVar31 = (&DAT_140e45db0)[(int)uVar14];
    puVar12 = (undefined4 *)_malloc_base();
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    fVar3 = DAT_14053af50;
    _DAT_140e46e28 = _DAT_140e46e28 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar12 = uVar31;
    puVar12[1] = 0x66;
    puVar12[2] = 1;
    puVar12[4] = 0x43aa0000;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[3] = fVar33 + fVar3;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = 0xff;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
    fVar30 = DAT_14053af84;
    fVar4 = DAT_14053af10;
    if (DAT_140e45274 == 0xb) {
      local_308 = CONCAT44(local_308._4_4_,2);
      local_310 = 1;
      local_318 = 0;
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,7);
      local_310 = 6;
      local_318 = CONCAT44(local_318._4_4_,5);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 9;
      local_318 = CONCAT44(local_318._4_4_,8);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[3] = fVar33 + fVar3;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x16) {
      local_308 = CONCAT44(local_308._4_4_,0xc);
      local_310 = 0xb;
      local_318 = CONCAT44(local_318._4_4_,10);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x11);
      local_310 = 0x10;
      local_318 = CONCAT44(local_318._4_4_,0xf);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x13;
      local_318 = CONCAT44(local_318._4_4_,0x12);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar3;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x20) {
      local_308 = CONCAT44(local_308._4_4_,0x16);
      local_310 = 0x15;
      local_318 = CONCAT44(local_318._4_4_,0x14);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x18;
      local_318 = CONCAT44(local_318._4_4_,0x17);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x29) {
      local_308 = CONCAT44(local_308._4_4_,0x1b);
      local_310 = 0x1a;
      local_318 = CONCAT44(local_318._4_4_,0x19);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x20);
      local_310 = 0x1f;
      local_318 = CONCAT44(local_318._4_4_,0x1e);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x25);
      local_310 = 0x24;
      local_318 = CONCAT44(local_318._4_4_,0x23);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x27;
      local_318 = CONCAT44(local_318._4_4_,0x26);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x32) {
      uStack_300 = CONCAT44(uStack_300._4_4_,0x29);
      local_308 = CONCAT44(local_308._4_4_,0x2a);
      local_310 = 0x29;
      local_318 = CONCAT44(local_318._4_4_,0x28);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uStack_300 = CONCAT44(uStack_300._4_4_,0x2e);
      local_308 = CONCAT44(local_308._4_4_,0x2f);
      local_310 = 0x2e;
      local_318 = CONCAT44(local_318._4_4_,0x2d);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x31;
      local_318 = CONCAT44(local_318._4_4_,0x30);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar3;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x33) {
      local_308 = CONCAT44(local_308._4_4_,0x34);
      local_318 = CONCAT44(local_318._4_4_,0x32);
      local_310 = DAT_140e45274;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x39);
      local_310 = 0x38;
      local_318 = CONCAT44(local_318._4_4_,0x37);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x3b) {
      local_308 = CONCAT44(local_308._4_4_,0x3e);
      local_310 = 0x3d;
      local_318 = CONCAT44(local_318._4_4_,0x3c);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x43);
      local_310 = 0x42;
      local_318 = CONCAT44(local_318._4_4_,0x41);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,7,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x45;
      local_318 = CONCAT44(local_318._4_4_,0x44);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar3;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x3d) {
      uStack_300 = CONCAT44(uStack_300._4_4_,0x47);
      local_308 = CONCAT44(local_308._4_4_,0x48);
      local_310 = 0x47;
      local_318 = CONCAT44(local_318._4_4_,0x46);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,6,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x4d);
      local_310 = 0x4c;
      local_318 = CONCAT44(local_318._4_4_,0x4b);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x4f;
      local_318 = CONCAT44(local_318._4_4_,0x4e);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar3;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x48) {
      local_2a0 = 0x51;
      local_2a8 = 0x50;
      local_2b0 = 0x52;
      local_2b8 = 0x53;
      local_2c0 = 0x54;
      local_2c8 = 0x55;
      local_2d0 = 0x56;
      local_2d8 = 0x57;
      local_2e0 = 0x56;
      local_2e8 = 0x57;
      local_2f0 = 0x55;
      local_2f8 = 0x54;
      uStack_300 = CONCAT44(uStack_300._4_4_,0x53);
      local_308 = CONCAT44(local_308._4_4_,0x52);
      local_310 = 0x51;
      local_318 = CONCAT44(local_318._4_4_,0x50);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,0x10);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x59;
      local_318 = CONCAT44(local_318._4_4_,0x58);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x49) {
      local_2a0 = 0x61;
      local_2a8 = 0x60;
      local_2b0 = 0x61;
      local_2b8 = 0x5f;
      local_2c0 = 0x5e;
      local_2c8 = 0x5d;
      local_2d0 = 0x5c;
      local_2d8 = 0x5b;
      local_2e0 = 0x5a;
      local_2e8 = 0x5b;
      local_2f0 = 0x5a;
      local_2f8 = 0x5c;
      uStack_300 = CONCAT44(uStack_300._4_4_,0x5d);
      local_308 = CONCAT44(local_308._4_4_,0x5e);
      local_310 = 0x5f;
      local_318 = CONCAT44(local_318._4_4_,0x60);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,0x10);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 99;
      local_318 = CONCAT44(local_318._4_4_,0x62);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    fVar29 = DAT_14053af98;
    fVar28 = DAT_14053aef8;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x52) {
      dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a798 * dVar26 *
                                     DAT_140539d28);
      uVar31 = DAT_140e443fc;
      dVar25 = dVar25 * _DAT_14053aa18;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      fVar23 = fVar33 + DAT_14053af00;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43110000;
      puVar12[3] = fVar23;
      sVar17 = (short)(int)dVar25;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e443fc;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      fVar23 = fVar33 + DAT_14053aef0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[2] = 1;
      puVar12[3] = fVar23;
      puVar12[4] = 0x43110000;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e443f8;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43200000;
      puVar12[3] = fVar33 + fVar28;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uStack_300 = CONCAT44(uStack_300._4_4_,0x6f);
      local_308 = CONCAT44(local_308._4_4_,0x70);
      local_310 = 0x6f;
      local_318 = CONCAT44(local_318._4_4_,0x6e);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,6,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[3] = fVar33 + fVar28;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43200000;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e443fc;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      fVar23 = fVar33 + _DAT_14053af9c;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43110000;
      puVar12[3] = fVar23;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e443fc;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      fVar23 = fVar33 + _DAT_14053af90;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43110000;
      puVar12[3] = fVar23;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e443f8;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43200000;
      puVar12[3] = fVar33 + fVar29;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x72;
      local_318 = CONCAT44(local_318._4_4_,0x71);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[3] = fVar33 + fVar29;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43200000;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uStack_300 = CONCAT44(uStack_300._4_4_,0x65);
      local_308 = CONCAT44(local_308._4_4_,0x66);
      local_310 = 0x65;
      local_318 = CONCAT44(local_318._4_4_,100);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,6,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x6b);
      local_310 = 0x6a;
      local_318 = CONCAT44(local_318._4_4_,0x69);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43aa0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x6d;
      local_318 = CONCAT44(local_318._4_4_,0x6c);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x44020000;
      puVar12[3] = fVar33 + fVar3;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x54) {
      dVar25 = (double)FUN_140332d90();
      dVar25 = dVar25 * DAT_14053aa78;
      dVar26 = (double)FUN_140332d90();
      uVar31 = DAT_140e44514;
      dVar26 = dVar26 * DAT_140539ee0 + DAT_140539f18;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      fVar3 = DAT_14053ac5c;
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x435c0000;
      sVar17 = (short)(int)dVar25;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[3] = fVar33 + fVar28 + fVar3;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[1] = 0x66;
      puVar12[3] = (fVar33 + fVar28) - fVar3;
      puVar12[2] = 1;
      puVar12[4] = 0x435c0000;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uStack_300 = CONCAT44(uStack_300._4_4_,0x74);
      local_308 = CONCAT44(local_308._4_4_,0x75);
      local_310 = 0x74;
      local_318 = CONCAT44(local_318._4_4_,0x73);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar28;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x435c0000;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[3] = fVar33 + fVar29 + fVar3;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[1] = 0x66;
      puVar12[3] = (fVar33 + fVar29) - fVar3;
      puVar12[2] = 1;
      puVar12[4] = 0x435c0000;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_308 = CONCAT44(local_308._4_4_,0x7a);
      local_310 = 0x79;
      local_318 = CONCAT44(local_318._4_4_,0x78);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,3);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar29;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43d20000;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[3] = fVar33 + fVar28 + fVar3;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar12[2] = 1;
      puVar12[4] = 0x43d20000;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[3] = (fVar33 + fVar28) - fVar3;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x7c;
      local_318 = CONCAT44(local_318._4_4_,0x7b);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar28;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43d20000;
      *(short *)(puVar12 + 5) = sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[3] = fVar33 + fVar29 + fVar3;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uVar31 = DAT_140e44514;
      DAT_140e46c88 = puVar12;
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar12 + 6) = dVar26;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43d20000;
      *(short *)(puVar12 + 5) = -sVar17;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[3] = (fVar33 + fVar29) - fVar3;
      puVar12[0xd] = 0xff;
      puVar12[0xe] = 1;
      puVar12[0xf] = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x80;
      local_318 = CONCAT44(local_318._4_4_,0x7f);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar29;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    puVar12 = DAT_140e46c88;
    if (DAT_140e45274 == 0x67) {
      uStack_300 = CONCAT44(uStack_300._4_4_,0x92);
      local_308 = CONCAT44(local_308._4_4_,0x93);
      local_310 = 0x92;
      local_318 = CONCAT44(local_318._4_4_,0x91);
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_2f0 = 0x97;
      local_2f8 = 0x98;
      uStack_300 = CONCAT44(uStack_300._4_4_,0x99);
      local_308 = CONCAT44(local_308._4_4_,0x98);
      local_310 = 0x97;
      local_318 = CONCAT44(local_318._4_4_,0x96);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,6);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43700000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      uStack_300 = CONCAT44(uStack_300._4_4_,0x9d);
      local_308 = CONCAT44(local_308._4_4_,0x9c);
      local_310 = 0x9b;
      local_318 = CONCAT44(local_318._4_4_,0x9a);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,4);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar4;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      local_310 = 0x9f;
      local_318 = CONCAT44(local_318._4_4_,0x9e);
      DAT_140e46c88 = puVar12;
      iVar15 = FUN_1400c9580(DAT_140e418c8,0,5,2);
      uVar31 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar15 * 4);
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e28 = _DAT_140e46e28 + 1;
      bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar12 = uVar31;
      puVar12[1] = 0x66;
      puVar12[2] = 1;
      puVar12[4] = 0x43dc0000;
      puVar12[3] = fVar33 + fVar30;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = 0xff;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      if (bVar22) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    uVar31 = SUB84(DAT_140539d28,0);
    uVar32 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    puVar12 = DAT_140e46c88;
  }
  else {
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e28 = _DAT_140e46e28 + 1;
    *puVar12 = uVar18;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar12[1] = 0x66;
    puVar12[2] = 1;
    fVar33 = fVar33 + DAT_14053af50;
    puVar12[4] = 0x43aa0000;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[3] = fVar33;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = 0xff;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
  }
  DAT_140e46c88 = puVar12;
  dVar25 = DAT_14053a890;
  uVar16 = 0;
  puVar12 = DAT_140e46c88;
  if ((0x3b < DAT_140e418c8) && (DAT_140e45fac == 0)) {
    dVar26 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053a890 * DAT_14053a020 *
                                   (double)CONCAT44(uVar32,uVar31));
    uVar31 = DAT_140e41934;
    dVar26 = dVar26 * DAT_14053a178;
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    fVar33 = (float)dVar26 + 0.0 + DAT_14053afe4;
    _DAT_140e46e28 = _DAT_140e46e28 + 1;
    bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar12 = uVar31;
    puVar12[1] = 0x66;
    puVar12[3] = fVar33;
    puVar12[2] = 1;
    puVar12[4] = 0x43b40000;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[10] = 0xff;
    puVar12[0xb] = 0xff;
    puVar12[0xc] = 0xff;
    puVar12[0xd] = 0xff;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    if (bVar22) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
  }
  DAT_140e46c88 = puVar12;
  FUN_1400d9b60(1,0x70,0xff);
  uVar6 = _UNK_14053baa8;
  uVar5 = _DAT_14053baa0;
  dVar26 = DAT_14053b160;
  fVar28 = DAT_14053adf4;
  fVar30 = DAT_14053ade0;
  fVar4 = DAT_14053ad50;
  fVar3 = DAT_14053ad2c;
  fVar33 = DAT_14053aca8;
  uVar19 = uVar16;
  if ((DAT_140e418c8 < 0x3c) || (0 < (int)DAT_140e45fac)) {
    do {
      uVar11 = (uint)uVar16;
      uVar14 = (uint)(uVar16 >> 2);
      fVar23 = (float)uVar14 * fVar3 + fVar4;
      fVar29 = (float)(uVar11 & 3) * fVar30 + fVar28 + local_298 + DAT_14053b00c;
      if ((uVar14 & 1) == 1) {
        fVar29 = fVar29 + fVar33;
      }
      iVar15 = *(int *)((longlong)&DAT_140e43f1c + uVar19);
      uVar31 = 0x60;
      if (iVar15 != 0) {
        uVar31 = 0xff;
      }
      uVar14 = -(uint)(iVar15 != 0) & 0xff;
      if ((iVar15 == 1) && (*(int *)((longlong)&DAT_140e43f80 + uVar19) == 0)) {
        dVar27 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * dVar25 * DAT_14053a020 *
                                       DAT_140539d28);
        uVar14 = 0xc0 - (int)(dVar27 * dVar26);
      }
      local_2d0 = 0;
      local_2d8 = 1;
      local_308 = uVar5;
      uStack_300 = uVar6;
      local_310 = local_310 & 0xffff0000;
      local_318 = CONCAT44(local_318._4_4_,fVar23);
      local_2f8 = uVar14;
      local_2f0 = uVar14;
      local_2e8 = uVar14;
      local_2e0 = uVar31;
      FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e46810 + uVar19),100,1,fVar29);
      uVar31 = DAT_140e46800;
      puVar12 = DAT_140e46c88;
      if ((uVar11 == DAT_140e45274) && (0 < (int)DAT_140e45fac)) {
        puVar12 = (undefined4 *)_malloc_base(0x48);
        if (puVar12 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar12[3] = fVar29;
        *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
        puVar12[4] = fVar23;
        *puVar12 = uVar31;
        puVar12[1] = 100;
        puVar12[2] = 1;
        *(undefined2 *)(puVar12 + 5) = 0;
        puVar12[10] = 0xff;
        puVar12[0xb] = 0xff;
        puVar12[0xc] = 0xff;
        puVar12[0xd] = 0xff;
        *(undefined8 *)(puVar12 + 0xe) = 1;
        *(undefined8 *)(puVar12 + 0x10) = 0;
        _DAT_140e46e20 = _DAT_140e46e20 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar12;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
        }
        DAT_140e46c88 = puVar12;
        dVar27 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053ab08 * DAT_14053a020
                                       * DAT_140539d28);
        uVar31 = DAT_140e46800;
        puVar12 = (undefined4 *)_malloc_base(0x48);
        if (puVar12 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar12 = uVar31;
        puVar12[3] = fVar29;
        puVar12[10] = 0xff;
        puVar12[0xb] = 0xff;
        puVar12[0xc] = 0xff;
        puVar12[4] = fVar23;
        puVar12[1] = 100;
        puVar12[2] = 6;
        *(undefined2 *)(puVar12 + 5) = 0;
        *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
        puVar12[0xd] = 0x40 - (int)(dVar27 * dVar26);
        *(undefined8 *)(puVar12 + 0xe) = 1;
        *(undefined8 *)(puVar12 + 0x10) = 0;
        _DAT_140e46e20 = _DAT_140e46e20 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar12;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
        }
      }
      DAT_140e46c88 = puVar12;
      uVar16 = (ulonglong)(uVar11 + 1);
      uVar19 = uVar19 + 4;
    } while ((int)(uVar11 + 1) < 0x14);
  }
  uVar32 = DAT_14053aedc;
  uVar31 = DAT_14053ac80;
  uVar14 = DAT_14053ac34;
  if (((DAT_140e418c8 == 0x3c) || (DAT_140e46014 == 1)) &&
     (lVar20 = DAT_140e47908, DAT_140e45fac == 0)) {
    while (lVar20 != 0) {
      lVar20 = *(longlong *)(lVar20 + 0x238);
      FUN_140323ce8();
    }
    local_2d8 = 5;
    local_2e0 = 0;
    local_2e8 = 0;
    local_2f0 = 0xff;
    local_2f8 = 0xff;
    uStack_300._4_4_ = (undefined4)((ulonglong)uStack_300 >> 0x20);
    uStack_300 = CONCAT44(uStack_300._4_4_,0xff);
    local_308._4_4_ = (undefined4)((ulonglong)local_308 >> 0x20);
    local_308 = CONCAT44(local_308._4_4_,uVar31);
    local_310 = uVar14;
    local_318._4_4_ = (undefined4)((ulonglong)local_318 >> 0x20);
    local_318 = CONCAT44(local_318._4_4_,uVar32);
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    if (local_288[(int)DAT_140e45274] == 1) {
      iVar15 = DAT_140e45274 + 0x1c2;
    }
    else {
      iVar15 = 0x1c2;
    }
    FUN_14012e070(iVar15);
  }
  if (DAT_140e45fac == 0x3c) {
    local_2d8 = 5;
    local_2e0 = 1;
    local_2e8 = 0;
    local_2f0 = 0xff;
    local_2f8 = 0xff;
    uStack_300 = CONCAT44(uStack_300._4_4_,0xff);
    local_308 = CONCAT44(local_308._4_4_,uVar31);
    local_310 = uVar14;
    local_318 = CONCAT44(local_318._4_4_,uVar32);
    DAT_140e45270 = 6;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    DAT_140e418c8 = 0x3c;
    if ((&DAT_140e43f1c)[(int)DAT_140e45274] == 0) {
      iVar15 = DAT_140e45274 + 0x15f;
    }
    else {
      iVar15 = DAT_140e45274 + 0x178;
    }
    FUN_14012e070(iVar15);
  }
  if ((int)DAT_140e45fac < -0x13) {
    FUN_1400d3fd0(-0x14 - DAT_140e45fac);
  }
  if (DAT_140e45fac == 0xffffffce) {
    DAT_140e45270 = 2;
    DAT_140e45274 = 5;
    DAT_140e418c8 = 0;
    DAT_140e45fac = 0;
    DAT_140e46014 = 0;
    fopen_s(&local_e8,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_e8);
    FUN_140323e90(local_e8);
    DAT_140e471fc = 0xb4;
  }
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  if (DAT_140e46014 == 1) {
    DAT_140e46014 = 1;
  }
  return;
}


