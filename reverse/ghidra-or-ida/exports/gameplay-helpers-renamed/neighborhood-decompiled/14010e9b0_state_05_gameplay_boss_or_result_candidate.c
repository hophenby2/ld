// Function: state_05_gameplay_boss_or_result_candidate @ 14010e9b0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_05_gameplay_boss_or_result_candidate(void)

{
  undefined4 uVar1;
  longlong lVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined4 uVar18;
  bool bVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined1 auStack_168 [32];
  float local_148;
  undefined4 local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_100;
  uint local_f8;
  int iStack_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b0;
  undefined4 uStack_ac;
  ulonglong local_a8;
  
  iVar9 = DAT_140e41b68;
  local_a8 = DAT_1407c6b00 ^ (ulonglong)auStack_168;
  uVar16 = 1;
  local_c0 = 5;
  local_bc = 5;
  local_b8 = 5;
  local_b0 = 1;
  local_f0 = _DAT_14053b690;
  uStack_e8 = _UNK_14053b698;
  local_d0 = _DAT_14053b6b0;
  uStack_c8 = _UNK_14053b6b8;
  local_e0 = _DAT_14053b6a0;
  uStack_d8 = _UNK_14053b6a8;
  if (DAT_140e418c8 < 0x3c) {
    transition_tile_wipe_in_candidate();
  }
  uVar13 = DAT_140e467f0;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar13;
  *(undefined8 *)(puVar11 + 1) = 10;
  *(undefined8 *)(puVar11 + 3) = 0;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  uVar13 = DAT_140e46020;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar13;
  *(undefined8 *)(puVar11 + 1) = 0x65;
  *(undefined8 *)(puVar11 + 3) = 0;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  dVar20 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a698 * DAT_14053a020 *
                                 DAT_140539d28);
  uVar13 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  fVar21 = (float)(dVar20 * DAT_14053a0f8) + DAT_14053ae7c;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46da8 = _DAT_140e46da8 + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[4] = fVar21;
  *puVar11 = uVar13;
  puVar11[1] = 0x46;
  puVar11[2] = 1;
  puVar11[3] = 0x44610000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = 0x80;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  ambient_effect_update_and_render_candidate();
  if (((DAT_140e418c8 < 0x20) || (bVar19 = false, DAT_140e45fac != 0)) || (DAT_140e46014 != 0))
  goto LAB_14010f6e3;
  if (DAT_140e8cf10 == 1) {
LAB_14010ed27:
    bVar3 = true;
  }
  else {
    bVar3 = bVar19;
    if (0x13 < DAT_140e8cf10) {
      uVar8 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
      }
      if (uVar8 == 0) goto LAB_14010ed27;
    }
  }
  if ((DAT_140e8cf14 < 1) && (bVar3)) {
    DAT_140e45274 = DAT_140e45274 - 1;
    if ((int)DAT_140e45274 < 0) {
      DAT_140e45274 = 9;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1);
    DAT_140e46014 = 1;
  }
  bVar3 = false;
  if (DAT_140e8cf14 == 1) {
LAB_14010edb4:
    bVar19 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar8 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
    }
    bVar19 = bVar3;
    if (uVar8 == 0) goto LAB_14010edb4;
  }
  if ((DAT_140e8cf10 < 1) && (bVar19)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (9 < (int)DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf18 == 1) {
LAB_14010ee34:
    bVar19 = true;
  }
  else {
    bVar19 = bVar3;
    if (0x13 < DAT_140e8cf18) {
      uVar8 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
      }
      if (uVar8 == 0) goto LAB_14010ee34;
    }
  }
  if (((DAT_140e8cf1c < 1) && (bVar19)) && ((int)DAT_140e45274 < 8)) {
    if (DAT_140e45274 == 0) {
      if (DAT_140e43ef8 < iVar9) {
        DAT_140e43ef8 = DAT_140e43ef8 + 1;
        if (DAT_140e43f08 == (&iStack_f4)[DAT_140e43ef8]) {
          DAT_140e43f08 = *(int *)((longlong)&local_f0 + (longlong)DAT_140e43ef8 * 4);
        }
LAB_14010ee8f:
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        if ((DAT_140e41b78 != 0) && (DAT_140e43ef8 < DAT_140e41b78 + 9)) {
          if (DAT_140e43ef8 < 10) {
            DAT_140e43ef8 = 10;
          }
          else {
            DAT_140e43ef8 = DAT_140e43ef8 + 1;
          }
          goto LAB_14010ee8f;
        }
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 1) {
      if ((DAT_140e43efc < DAT_140e43eac) && (DAT_140e43ef8 < 10)) {
        DAT_140e43efc = DAT_140e43efc + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 2) {
      if (DAT_140e41b74 == 1) {
        DAT_140e43f00 = (uint)(DAT_140e43f00 == 0);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 3) {
      if (DAT_140e41b6c < 0xe) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f04 = (uint)(DAT_140e43f04 == 0);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 4) {
      if (DAT_140e43f08 < *(int *)((longlong)&local_f0 + (longlong)DAT_140e43ef8 * 4)) {
        DAT_140e43f08 = DAT_140e43f08 + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 5) {
      if (DAT_140e43f0c < 3) {
        DAT_140e43f0c = DAT_140e43f0c + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 6) {
      if (DAT_140e43f10 < 0x14) {
        DAT_140e43f10 = DAT_140e43f10 + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 7) {
      if (DAT_140e43f14 < 0x14) {
        DAT_140e43f14 = DAT_140e43f14 + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
  }
  if (DAT_140e8cf1c == 1) {
LAB_14010f1eb:
    bVar3 = true;
  }
  else if (0x13 < DAT_140e8cf1c) {
    uVar8 = DAT_140e8cf1c - 0x14U & 0x80000007;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
    }
    if (uVar8 == 0) goto LAB_14010f1eb;
  }
  if (((DAT_140e8cf18 < 1) && (bVar3)) && ((int)DAT_140e45274 < 8)) {
    if (DAT_140e45274 == 0) {
      if (DAT_140e43ef8 < 2) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        iVar9 = DAT_140e41b68;
        if (DAT_140e43ef8 != 10) {
          iVar9 = DAT_140e43ef8 + -1;
        }
        DAT_140e43ef8 = iVar9;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 1) {
      if ((DAT_140e43efc < 1) || (9 < DAT_140e43ef8)) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43efc = DAT_140e43efc + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 2) {
      if (DAT_140e41b74 == 1) {
        DAT_140e43f00 = (uint)(DAT_140e43f00 == 0);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 3) {
      if (DAT_140e41b6c < 0xe) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f04 = (uint)(DAT_140e43f04 == 0);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 4) {
      if (DAT_140e43f08 < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f08 = DAT_140e43f08 + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 5) {
      if (DAT_140e43f0c < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f0c = DAT_140e43f0c + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 6) {
      if (DAT_140e43f10 < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f10 = DAT_140e43f10 + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    if (DAT_140e45274 == 7) {
      if (DAT_140e43f14 < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e43f14 = DAT_140e43f14 + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar13 = DAT_140e47200;
      }
      FUN_14018a340(uVar13,1);
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
  }
  if ((int)(&DAT_140e43ea8)[DAT_140e43ef8] < DAT_140e43efc) {
    uVar16 = (uint)(DAT_140e43ef8 == 10);
    local_b0 = uVar16;
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    if ((int)DAT_140e45274 < 8) {
      DAT_140e45274 = 8;
      DAT_140e46014 = 1;
LAB_14010f5ba:
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      uVar13 = DAT_140e47204;
    }
    else {
      if ((uVar16 != 0) || (DAT_140e45274 != 8)) {
        DAT_140e45fac = 1;
        goto LAB_14010f5ba;
      }
      FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
      uVar13 = DAT_140e4720c;
    }
    FUN_14018a340(uVar13,1);
    DAT_140e467fc = 1;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 9) {
      DAT_140e45fac = 0xffffffff;
    }
    else {
      DAT_140e45274 = 9;
      DAT_140e46014 = 1;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1);
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
LAB_14010f6e3:
  uVar7 = _UNK_14053bb28;
  uVar6 = _DAT_14053bb20;
  fVar5 = DAT_14053b338;
  fVar4 = DAT_14053aef4;
  uVar13 = DAT_14053aec0;
  fVar21 = DAT_14053aeb4;
  uVar12 = 0;
  iVar9 = *(int *)((longlong)&local_f0 + (longlong)DAT_140e43ef8 * 4);
  if (iVar9 < DAT_140e43f08) {
    DAT_140e43f08 = iVar9;
  }
  local_f8 = 0;
  uVar17 = uVar12;
LAB_14010f740:
  uVar8 = (uint)uVar12;
  uVar15 = 0xff;
  uVar18 = 0xff;
  fVar22 = (float)(int)(uVar8 * 0x2d + 0x82);
  uVar14 = 0x60;
  if (DAT_140e45274 == uVar8) {
    if (DAT_140e45fac != 0) {
      uVar10 = DAT_140e45fac & 0x80000003;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
      }
      if (1 < (int)uVar10) goto LAB_14010f783;
    }
    uVar14 = 0xff;
  }
LAB_14010f783:
  if (uVar8 == 1) {
    uVar18 = 0xff;
    if (uVar16 == 0) {
      uVar18 = 0x80;
    }
  }
  else if (uVar8 == 2) {
    if (DAT_140e41b74 == 0) {
      uVar15 = 0x80;
    }
  }
  else if (uVar8 == 3) {
    if (DAT_140e41b6c < 0xe) {
      uVar15 = 0x80;
    }
  }
  else if (uVar8 == 8) {
    uVar15 = 0xff;
    if (uVar16 == 0) {
      uVar15 = 0x80;
    }
  }
  uVar1 = (&DAT_140e477f0)[uVar17];
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar11 = uVar1;
  puVar11[4] = fVar22;
  puVar11[2] = 1;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  puVar11[1] = 100;
  puVar11[3] = 0x43d20000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = uVar15;
  puVar11[0xb] = uVar15;
  puVar11[0xc] = uVar15;
  puVar11[0xd] = uVar14;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  switch(uVar8) {
  case 0:
    uVar12 = (ulonglong)DAT_140e43ef8;
    if (9 < DAT_140e43ef8) {
LAB_14010f9e9:
      local_118 = 0xff;
      uVar18 = DAT_140e47834;
      goto LAB_14010fa15;
    }
    local_100 = 0;
    local_108 = 1;
    local_118 = 0xff;
    local_120 = 0xff;
    local_128 = 0xff;
    local_138 = uVar6;
    uStack_130 = uVar7;
    local_140 = (uint)local_140._2_2_ << 0x10;
    if (uVar12 < 10) {
LAB_14010f9e0:
      local_118 = 0xff;
      uVar18 = (&DAT_140e46c30)[uVar12];
      fVar23 = fVar21;
      goto LAB_14010fa2d;
    }
    local_148 = fVar22;
    local_110 = uVar14;
    FUN_1400c8410((&DAT_140e46c30)[DAT_140e43ef8 + (int)(uVar12 / 10) * -10],100,1,fVar21);
    uVar12 = uVar12 / 10;
    fVar23 = DAT_14053aea4;
    do {
      local_100 = 0;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = local_140 & 0xffff0000;
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar23);
      fVar23 = fVar23 + fVar5;
      bVar19 = 9 < uVar12;
      uVar12 = uVar12 / 10;
    } while (bVar19);
    local_f8 = local_f8 + 1;
    uVar12 = (ulonglong)local_f8;
    uVar17 = uVar17 + 1;
    uVar16 = local_b0;
    goto LAB_14010f740;
  case 1:
    if (9 < DAT_140e43ef8) goto LAB_14010f9e9;
    local_118 = uVar18;
    uVar18 = (&DAT_140e477f0)[DAT_140e43efc + 0xc];
    goto LAB_14010fa15;
  case 2:
    uVar10 = DAT_140e43f00;
    break;
  case 3:
    uVar10 = DAT_140e43f04;
    break;
  case 4:
    if (DAT_140e43f08 < *(int *)((longlong)&local_f0 + (longlong)DAT_140e43ef8 * 4)) {
      local_100 = 0;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = (uint)local_140._2_2_ << 0x10;
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410(DAT_140e47818,100,1,fVar4);
      local_100 = 0;
      uVar12 = (longlong)DAT_140e43f08 + 1;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = local_140 & 0xffff0000;
      if (uVar12 < 10) {
        local_148 = fVar22;
        local_110 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[uVar12],100,1,fVar4);
      }
      else {
        local_148 = fVar22;
        local_110 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar4);
        uVar12 = uVar12 / 10;
        fVar23 = DAT_14053aee4;
        do {
          local_100 = 0;
          local_108 = 1;
          local_118 = 0xff;
          local_120 = 0xff;
          local_128 = 0xff;
          local_138 = uVar6;
          uStack_130 = uVar7;
          local_140 = local_140 & 0xffff0000;
          local_148 = fVar22;
          local_110 = uVar14;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar23);
          fVar23 = fVar23 + fVar5;
          bVar19 = 9 < uVar12;
          uVar12 = uVar12 / 10;
          uVar8 = local_f8;
          uVar16 = local_b0;
        } while (bVar19);
      }
    }
    if (DAT_140e43f08 != *(int *)((longlong)&local_f0 + (longlong)DAT_140e43ef8 * 4))
    goto LAB_14010fa37;
    local_100 = 0;
    local_108 = 1;
    local_118 = 0xff;
    local_120 = 0xff;
    local_128 = 0xff;
    local_138 = uVar6;
    uStack_130 = uVar7;
    local_140 = local_140 & 0xffff0000;
    local_148 = fVar22;
    local_110 = uVar14;
    FUN_1400c8410(DAT_140e4781c,100,1,fVar4);
    local_f8 = uVar8 + 1;
    uVar12 = (ulonglong)local_f8;
    uVar17 = uVar17 + 1;
    goto LAB_14010f740;
  case 5:
    uVar12 = (ulonglong)DAT_140e43f0c;
    if (2 < DAT_140e43f0c) goto LAB_14010fe70;
    local_100 = 0;
    local_108 = 1;
    local_118 = 0xff;
    local_120 = 0xff;
    local_128 = 0xff;
    local_138 = uVar6;
    uStack_130 = uVar7;
    local_140 = (uint)local_140._2_2_ << 0x10;
    if (uVar12 < 10) goto LAB_14010f9e0;
    local_148 = fVar22;
    local_110 = uVar14;
    FUN_1400c8410((&DAT_140e46c30)[DAT_140e43f0c + (int)(uVar12 / 10) * -10],100,1,fVar21);
    uVar12 = uVar12 / 10;
    fVar23 = DAT_14053aea4;
    do {
      local_100 = 0;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = local_140 & 0xffff0000;
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar23);
      fVar23 = fVar23 + fVar5;
      bVar19 = 9 < uVar12;
      uVar12 = uVar12 / 10;
    } while (bVar19);
    local_f8 = local_f8 + 1;
    uVar12 = (ulonglong)local_f8;
    uVar17 = uVar17 + 1;
    uVar16 = local_b0;
    goto LAB_14010f740;
  case 6:
    if (0x13 < DAT_140e43f10) goto LAB_14010fe70;
    local_100 = 0;
    uVar12 = (longlong)DAT_140e43f10 * 5;
    local_108 = 1;
    local_118 = 0xff;
    local_120 = 0xff;
    local_128 = 0xff;
    local_138 = uVar6;
    uStack_130 = uVar7;
    local_140 = (uint)local_140._2_2_ << 0x10;
    if (uVar12 < 10) {
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410((&DAT_140e46c30)[(longlong)DAT_140e43f10 * 5],100,1,uVar13);
    }
    else {
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,uVar13);
      uVar12 = uVar12 / 10;
      fVar23 = fVar21;
      do {
        local_100 = 0;
        local_108 = 1;
        local_118 = 0xff;
        local_120 = 0xff;
        local_128 = 0xff;
        local_138 = uVar6;
        uStack_130 = uVar7;
        local_140 = local_140 & 0xffff0000;
        local_148 = fVar22;
        local_110 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar23);
        fVar23 = fVar23 + fVar5;
        bVar19 = 9 < uVar12;
        uVar12 = uVar12 / 10;
        uVar16 = local_b0;
        uVar8 = local_f8;
      } while (bVar19);
    }
    local_118 = 0xff;
    local_140 = local_140 >> 0x10;
    fVar23 = DAT_14053aed8;
    uVar18 = DAT_140e46c58;
    goto LAB_14010fa24;
  case 7:
    if (DAT_140e43f14 < 0x14) {
      local_100 = 0;
      uVar12 = (longlong)DAT_140e43f14 * 5;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = (uint)local_140._2_2_ << 0x10;
      if (uVar12 < 10) {
        local_148 = fVar22;
        local_110 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[(longlong)DAT_140e43f14 * 5],100,1,uVar13);
      }
      else {
        local_148 = fVar22;
        local_110 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,uVar13);
        uVar12 = uVar12 / 10;
        fVar23 = fVar21;
        do {
          local_100 = 0;
          local_108 = 1;
          local_118 = 0xff;
          local_120 = 0xff;
          local_128 = 0xff;
          local_138 = uVar6;
          uStack_130 = uVar7;
          local_140 = local_140 & 0xffff0000;
          local_148 = fVar22;
          local_110 = uVar14;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar12 + (int)(uVar12 / 10) * -10],100,1,fVar23);
          fVar23 = fVar23 + fVar5;
          bVar19 = 9 < uVar12;
          uVar12 = uVar12 / 10;
          uVar8 = local_f8;
          uVar16 = local_b0;
        } while (bVar19);
      }
      local_100 = 0;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = local_140 & 0xffff0000;
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410(DAT_140e46c58,100,1,DAT_14053aed8);
      local_f8 = uVar8 + 1;
      uVar12 = (ulonglong)local_f8;
      uVar17 = uVar17 + 1;
    }
    else {
LAB_14010fe70:
      local_100 = 0;
      local_108 = 1;
      local_118 = 0xff;
      local_120 = 0xff;
      local_128 = 0xff;
      local_138 = uVar6;
      uStack_130 = uVar7;
      local_140 = (uint)local_140._2_2_ << 0x10;
      local_148 = fVar22;
      local_110 = uVar14;
      FUN_1400c8410(DAT_140e47838,100,1,fVar4);
      local_f8 = uVar8 + 1;
      uVar12 = (ulonglong)local_f8;
      uVar17 = uVar17 + 1;
    }
    goto LAB_14010f740;
  default:
    goto switchD_14010f8a1_default;
  }
  local_118 = uVar15;
  uVar18 = DAT_140e478c8;
  if (uVar10 == 1) {
LAB_14010fa15:
    local_140 = (uint)local_140._2_2_;
    fVar23 = fVar4;
LAB_14010fa24:
    local_140 = local_140 << 0x10;
LAB_14010fa2d:
    uStack_130 = uVar7;
    local_138 = uVar6;
    local_100 = 0;
    local_108 = 1;
    local_148 = fVar22;
    local_128 = local_118;
    local_120 = local_118;
    local_110 = uVar14;
    FUN_1400c8410(uVar18,100,1,fVar23);
LAB_14010fa37:
    local_f8 = uVar8 + 1;
    uVar12 = (ulonglong)local_f8;
    uVar17 = uVar17 + 1;
  }
  else {
    local_100 = 0;
    local_108 = 1;
    local_138 = uVar6;
    uStack_130 = uVar7;
    local_140 = (uint)local_140._2_2_ << 0x10;
    local_148 = fVar22;
    local_128 = uVar15;
    local_120 = uVar15;
    local_110 = uVar14;
    FUN_1400c8410(DAT_140e478cc,100,1,fVar4);
    local_f8 = uVar8 + 1;
    uVar12 = (ulonglong)local_f8;
    uVar17 = uVar17 + 1;
  }
  goto LAB_14010f740;
switchD_14010f8a1_default:
  local_f8 = uVar8 + 1;
  uVar12 = (ulonglong)local_f8;
  uVar17 = uVar17 + 1;
  if (9 < (int)local_f8) goto code_r0x0001401101fa;
  goto LAB_14010f740;
code_r0x0001401101fa:
  FUN_1400c48f0(0x50);
  FUN_1400d9b60(1,0x70,0xff);
  uVar8 = DAT_14053ac34;
  uVar13 = DAT_14053ac80;
  lVar2 = DAT_140e47908;
  if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
    while (DAT_14053ac34 = uVar8, DAT_14053ac80 = uVar13, lVar2 != 0) {
      lVar2 = *(longlong *)(lVar2 + 0x238);
      FUN_140323ce8();
      uVar8 = DAT_14053ac34;
      uVar13 = DAT_14053ac80;
    }
    local_108 = 5;
    local_110 = 1;
    local_118 = 0;
    local_120 = 0xff;
    local_128 = 0xff;
    uStack_130._4_4_ = (undefined4)((ulonglong)uStack_130 >> 0x20);
    uStack_130 = CONCAT44(uStack_130._4_4_,0xff);
    local_138._4_4_ = (undefined4)((ulonglong)local_138 >> 0x20);
    local_138 = CONCAT44(local_138._4_4_,uVar13);
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    local_148 = DAT_14053aecc;
    local_140 = uVar8;
    FUN_14012e070(DAT_140e45274 + 0xe4,0);
    if ((DAT_140e45274 == 8) && (uVar16 == 0)) {
      local_108 = 5;
      local_110 = 1;
      local_118 = 0;
      local_120 = 0xff;
      local_128 = 0xff;
      uStack_130 = CONCAT44(uStack_130._4_4_,0xff);
      local_138 = CONCAT44(local_138._4_4_,uVar13);
      local_148 = DAT_14053aee0;
      local_140 = uVar8;
      FUN_14012e070(0xee,0);
    }
  }
  if (DAT_140e45fac == 1) {
    if (DAT_140e45274 == 8) {
      puVar11 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar11,0);
        puVar11 = puVar11 + 1;
      } while ((longlong)puVar11 < 0x140e45178);
      goto LAB_14011038e;
    }
  }
  else {
LAB_14011038e:
    if (0x13 < (int)DAT_140e45fac) {
      transition_tile_wipe_out_candidate(DAT_140e45fac - 0x14);
    }
    if (DAT_140e45fac == 0x32) {
      if (DAT_140e45274 == 8) {
        gameplay_context_init_candidate();
        DAT_140e418c8 = DAT_140e418c8 + -1;
      }
      if (DAT_140e45274 == 9) {
        DAT_140e45d74 = 0;
        DAT_140e45274 = 0;
        DAT_140e46064 = 0;
        DAT_140e418c8 = 0;
        DAT_140e46014 = 0;
        DAT_140e46bb4 = 0;
        DAT_140e46bb0 = 0;
        DAT_140e45fac = 0;
        DAT_140e45270 = 3;
      }
      fopen_s((FILE **)&local_b0,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_ac,local_b0));
      FUN_140323e90(CONCAT44(uStack_ac,local_b0));
      DAT_140e471fc = 0xb4;
    }
    if ((int)DAT_140e45fac < -0x13) {
      transition_tile_wipe_out_candidate(-0x14 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffce) {
      DAT_140e45d74 = 0;
      DAT_140e45274 = 0;
      DAT_140e46064 = 0;
      DAT_140e418c8 = 0;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      fopen_s((FILE **)&local_b0,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_ac,local_b0));
      FUN_140323e90(CONCAT44(uStack_ac,local_b0));
      DAT_140e471fc = 0xb4;
      DAT_140e45270 = 3;
    }
    if ((int)DAT_140e45fac < 1) goto LAB_140110520;
  }
  DAT_140e45fac = DAT_140e45fac + 1;
LAB_140110520:
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  if (DAT_140e46014 == 1) {
    DAT_140e46014 = 0;
  }
  return;
}


