// Function: state_07_gallery_detail_candidate @ 1400b5c70
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400b6c4e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_07_gallery_detail_candidate(void)

{
  int *piVar1;
  bool bVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  longlong lVar12;
  ulonglong uVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  int iVar20;
  ulonglong uVar21;
  bool bVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined1 auStack_158 [32];
  float local_138;
  uint local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  uint local_118;
  uint local_110;
  uint local_108;
  int local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  float local_e8;
  FILE *local_e0;
  ulonglong local_d8;
  
  dVar24 = DAT_14053a628;
  dVar8 = DAT_14053a020;
  dVar7 = DAT_140539d28;
  local_d8 = DAT_1407c6b00 ^ (ulonglong)auStack_158;
  local_e8 = 0.0;
  if (DAT_140e418c8 < 0x3c) {
    dVar23 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                   DAT_140539d28);
    local_e8 = (float)(dVar23 * _DAT_14053b2b8) + DAT_14053b00c;
  }
  if (0 < (int)DAT_140e45fac) {
    dVar24 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * dVar24 * dVar8 * dVar7);
    local_e8 = (float)(dVar24 * DAT_14053a970) + 0.0;
  }
  fVar35 = local_e8;
  uVar38 = DAT_140e467f0;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  uVar18 = 0;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar38;
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
  if (bVar22) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  uVar38 = DAT_140e4602c;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar38;
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
  if (bVar22) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  ambient_effect_update_and_render_candidate();
  bVar22 = false;
  if (((DAT_140e418c8 < 0x3c) || (DAT_140e45fac != 0)) || (DAT_140e46014 != 0)) goto LAB_1400b6366;
  if (DAT_140e46064 == 0) {
    if (DAT_140e8cf10 == 1) {
LAB_1400b5f38:
      bVar2 = true;
    }
    else {
      bVar2 = bVar22;
      if (0x13 < DAT_140e8cf10) {
        uVar10 = DAT_140e8cf10 - 0x14U & 0x80000007;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
        }
        if (uVar10 == 0) goto LAB_1400b5f38;
      }
    }
    if (((DAT_140e8cf14 < 1) && (bVar2)) && (9 < (int)DAT_140e45274)) {
      DAT_140e45274 = DAT_140e45274 - 10;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    bVar2 = false;
    if (DAT_140e8cf14 == 1) {
LAB_1400b5fb2:
      bVar22 = true;
    }
    else if (0x13 < DAT_140e8cf14) {
      uVar10 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
      }
      bVar22 = bVar2;
      if (uVar10 == 0) goto LAB_1400b5fb2;
    }
    if (((DAT_140e8cf10 < 1) && (bVar22)) && ((int)DAT_140e45274 < 0x28)) {
      DAT_140e45274 = DAT_140e45274 + 10;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    if (DAT_140e8cf18 == 1) {
LAB_1400b6024:
      bVar22 = true;
    }
    else {
      bVar22 = bVar2;
      if (0x13 < DAT_140e8cf18) {
        uVar10 = DAT_140e8cf18 - 0x14U & 0x80000007;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
        }
        if (uVar10 == 0) goto LAB_1400b6024;
      }
    }
    if (((DAT_140e8cf1c < 1) && (bVar22)) && ((int)DAT_140e45274 % 10 != 9)) {
      DAT_140e45274 = DAT_140e45274 + 1;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    if (DAT_140e8cf1c == 1) {
LAB_1400b60be:
      bVar2 = true;
    }
    else if (0x13 < DAT_140e8cf1c) {
      uVar10 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
      }
      if (uVar10 == 0) goto LAB_1400b60be;
    }
    if ((DAT_140e8cf18 < 1) && (bVar2)) {
      if (DAT_140e45274 == ((int)DAT_140e45274 / 10) * 10) {
        DAT_140e45274 = ((int)DAT_140e45274 / 10) * 4 + 3;
        if (0x13 < (int)DAT_140e45274) {
          DAT_140e45274 = 0x13;
        }
        DAT_140e46064 = 0;
        lVar12 = DAT_140e47908;
        while (lVar12 != 0) {
          lVar12 = *(longlong *)(lVar12 + 0x238);
          FUN_140323ce8();
        }
        DAT_140e45fac = DAT_140e45fac + 1;
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
      }
      else {
        DAT_140e45274 = DAT_140e45274 - 1;
        DAT_140e46014 = 1;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 0xffffffff;
    fopen_s(&local_e0,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_e0);
    FUN_140323e90(local_e0);
    DAT_140e471fc = 0xb4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
  }
  if ((((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45274 == 0x31)) &&
     (DAT_140e440a4._4_4_ == 1)) {
    DAT_140e418c8 = 0;
    DAT_140e45274 = 0;
    DAT_140e45270 = 0x30;
    DAT_140e467fc = 1;
    lVar12 = DAT_140e45d78;
    while (lVar12 != 0) {
      lVar12 = *(longlong *)(lVar12 + 0x58);
      FUN_140323ce8();
    }
    DAT_140e45d78 = 0;
    DAT_140e45d28 = 0;
    DAT_140e45d1c = 0;
    lVar12 = DAT_140e47908;
    while (lVar12 != 0) {
      lVar12 = *(longlong *)(lVar12 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
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
LAB_1400b6366:
  lVar12 = (longlong)(int)DAT_140e45274;
  uVar13 = uVar18;
  uVar21 = uVar18;
  uVar3 = _UNK_14053bb28;
  dVar24 = _DAT_14053bb20;
  iVar14 = _UNK_14053b63c;
  iVar17 = _UNK_14053b638;
  iVar4 = _UNK_14053b634;
  iVar5 = _DAT_14053b630;
  fVar6 = DAT_14053ad70;
  dVar23 = DAT_14053a8f8;
  if (((&DAT_140e43fe4)[lVar12] == 1) && ((&DAT_140e440ac)[lVar12] == 0)) {
    (&DAT_140e440ac)[lVar12] = 1;
    uVar3 = _UNK_14053bb28;
    dVar24 = _DAT_14053bb20;
    iVar14 = _UNK_14053b63c;
    iVar17 = _UNK_14053b638;
    iVar4 = _UNK_14053b634;
    iVar5 = _DAT_14053b630;
    fVar6 = DAT_14053ad70;
    dVar23 = DAT_14053a8f8;
  }
  do {
    uVar10 = (uint)uVar13;
    iVar27 = (int)(uVar13 / 10);
    fVar35 = (float)(int)(uVar10 + iVar27 * -10) * DAT_14053ad2c + fVar6 + fVar35;
    fVar37 = (float)iVar27 * DAT_14053ad2c + DAT_14053ad50;
    if ((uVar13 / 10 & 1) == 0) {
      fVar35 = fVar35 + DAT_14053aca8;
    }
    iVar27 = *(int *)((longlong)&DAT_140e43fe4 + uVar21);
    iVar20 = 0x65 - (uint)(iVar27 != 0);
    iVar28 = 0x60;
    if (iVar27 != 0) {
      iVar28 = 0xff;
    }
    uVar16 = -(uint)(iVar27 != 0) & 0xff;
    dVar25 = dVar24;
    if ((uVar10 == DAT_140e45274) && (DAT_140e45fac == 0)) {
      dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053aa88 * dVar8 * dVar7);
      dVar25 = dVar25 * DAT_140539e60 + _DAT_140539f60;
    }
    iVar29 = DAT_140e451bc;
    if ((iVar27 == 1) && (*(int *)((longlong)&DAT_140e440ac + uVar21) == 0)) {
      dVar26 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053a890 * dVar8 * dVar7);
      uVar16 = 0xc0 - (int)(dVar26 * DAT_14053b160);
    }
    dVar26 = (double)FUN_140332d90(((double)iVar29 - (double)(int)uVar18) * _DAT_14053a760 * dVar8 *
                                   dVar7);
    local_f0 = 0;
    local_f8 = 1;
    local_130 = CONCAT22(local_130._2_2_,(short)(int)(dVar26 * dVar23));
    local_138 = fVar37;
    local_128 = dVar25;
    uStack_120 = dVar25;
    local_118 = uVar16;
    local_110 = uVar16;
    local_108 = uVar16;
    local_100 = iVar28;
    FUN_1400c8410(*(undefined4 *)
                   (&DAT_140e46050 + (longlong)*(int *)((longlong)&DAT_140538a10 + uVar21) * 4),
                  iVar20,1,fVar35);
    if ((uVar10 == DAT_140e45274) && (DAT_140e45fac == 0)) {
      dVar26 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * _DAT_14053aa30 * dVar8 * dVar7)
      ;
      local_f0 = 0;
      local_f8 = 1;
      local_100 = 0x40 - (int)(dVar26 * DAT_14053b160);
      local_108 = 0xff;
      local_110 = 0xff;
      local_118 = 0xff;
      local_130 = local_130 & 0xffff0000;
      local_138 = fVar37;
      local_128 = dVar25;
      uStack_120 = dVar25;
      FUN_1400c8410(DAT_140e46060,iVar20,6,fVar35);
    }
    uVar19 = 0;
    if (*(int *)((longlong)&DAT_140e43fe4 + uVar21) == 0) {
      switch(uVar10) {
      case 0x1e:
        dVar25 = (double)DAT_140e44174 / DAT_14053a278;
        break;
      case 0x1f:
        dVar25 = (double)DAT_140e44174 / DAT_14053a598;
        break;
      case 0x20:
        dVar25 = (double)DAT_140e44178 / DAT_14053a278;
        break;
      case 0x21:
        dVar25 = (double)DAT_140e44178 / DAT_14053a598;
        break;
      case 0x22:
        dVar25 = (double)DAT_140e4417c / dVar23;
        break;
      case 0x23:
        dVar25 = (double)DAT_140e4417c / _DAT_14053ab98;
        break;
      case 0x24:
        dVar25 = (double)DAT_140e44180 / DAT_14053a650;
        break;
      case 0x25:
        dVar25 = (double)DAT_140e44180 / DAT_14053aa78;
        break;
      case 0x26:
        dVar25 = (double)DAT_140e44184 / DAT_14053a758;
        break;
      case 0x27:
        dVar25 = (double)DAT_140e44184 / _DAT_14053abe0;
        break;
      case 0x28:
        dVar25 = (double)DAT_140e44188 / DAT_14053a2d8;
        break;
      case 0x29:
        dVar25 = (double)DAT_140e44188 / DAT_14053a650;
        break;
      default:
        goto switchD_1400b664e_caseD_2a;
      case 0x2b:
        if ((longlong)DAT_140e43ef0 < 0) {
          dVar25 = (double)DAT_140e43ef0 / _DAT_14053ab98;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ef0 / _DAT_14053ab98;
        }
        break;
      case 0x2c:
        if ((longlong)DAT_140e43ef0 < 0) {
          dVar25 = (double)DAT_140e43ef0 / _DAT_14053ac00;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ef0 / _DAT_14053ac00;
        }
        break;
      case 0x2d:
        if ((longlong)DAT_140e43ef0 < 0) {
          dVar25 = (double)DAT_140e43ef0 / _DAT_14053ac10;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ef0 / _DAT_14053ac10;
        }
        break;
      case 0x2e:
        if ((longlong)DAT_140e43ee8 < 0) {
          dVar25 = (double)DAT_140e43ee8 / _DAT_14053ac50;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ee8 / _DAT_14053ac50;
        }
        break;
      case 0x2f:
        if ((longlong)DAT_140e43ee8 < 0) {
          dVar25 = (double)DAT_140e43ee8 / _DAT_14053ac68;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ee8 / _DAT_14053ac68;
        }
        break;
      case 0x30:
        if ((longlong)DAT_140e43ee8 < 0) {
          dVar25 = (double)DAT_140e43ee8 / _DAT_14053ac88;
        }
        else {
          dVar25 = (double)(longlong)DAT_140e43ee8 / _DAT_14053ac88;
        }
        break;
      case 0x31:
        iVar27 = 0;
        iVar28 = 0;
        iVar29 = 0;
        iVar30 = 0;
        iVar31 = 0;
        iVar32 = 0;
        iVar33 = 0;
        iVar34 = 0;
        uVar13 = uVar19;
        do {
          iVar27 = iVar27 + (uint)((&DAT_140e43fe4)[uVar13] == iVar5);
          iVar28 = iVar28 + (uint)((&DAT_140e43fe8)[uVar13] == iVar4);
          iVar29 = iVar29 + (uint)((&DAT_140e43fec)[uVar13] == iVar17);
          iVar30 = iVar30 + (uint)((&DAT_140e43ff0)[uVar13] == iVar14);
          lVar12 = uVar13 * 4;
          piVar15 = &DAT_140e43ff4 + uVar13;
          piVar1 = &DAT_140e43ff8 + uVar13;
          uVar13 = uVar13 + 8;
          iVar31 = iVar31 + (uint)(*piVar15 == iVar5);
          iVar32 = iVar32 + (uint)(*piVar1 == iVar4);
          iVar33 = iVar33 + (uint)(*(int *)(lVar12 + 0x140e43ffc) == iVar17);
          iVar34 = iVar34 + (uint)(*(int *)(lVar12 + 0x140e44000) == iVar14);
        } while ((longlong)uVar13 < 0x30);
        iVar27 = iVar27 + iVar31 + iVar29 + iVar33 + iVar28 + iVar32 + iVar30 + iVar34;
        if ((longlong)uVar13 < 0x31) {
          piVar15 = &DAT_140e43fe4 + uVar13;
          do {
            iVar28 = iVar27 + 1;
            if (*piVar15 != 1) {
              iVar28 = iVar27;
            }
            iVar27 = iVar28;
            piVar15 = piVar15 + 1;
          } while ((longlong)piVar15 < 0x140e440a8);
        }
        dVar25 = (double)iVar27 / _DAT_14053a370;
      }
      dVar25 = dVar25 / DAT_14053a018;
      if (dVar25 <= dVar24) {
        local_f0 = 0;
        local_f8 = 1;
        local_100 = 0xff;
        local_108 = 0xff;
        local_110 = 0xff;
        local_118 = 0xff;
        local_130 = local_130 & 0xffff0000;
        local_138 = fVar37;
        local_128 = dVar24;
        uStack_120 = (double)uVar3;
        FUN_1400c8410(DAT_140e45da0,iVar20,1,fVar35);
        local_138 = fVar37 - DAT_14053aa20;
        local_f0 = 0;
        local_f8 = 1;
        local_100 = 0xff;
        local_108 = 0x80;
        local_110 = 0xff;
        local_118 = 0x80;
        local_130 = local_130 & 0xffff0000;
        local_128 = dVar25;
        uStack_120 = dVar24;
        FUN_1400c8410(DAT_140e45d8c,iVar20,0,fVar35 - DAT_14053aca8);
      }
    }
switchD_1400b664e_caseD_2a:
    uVar16 = (int)uVar18 + 0xb;
    uVar18 = (ulonglong)uVar16;
    uVar13 = (ulonglong)(uVar10 + 1);
    uVar21 = uVar21 + 4;
    fVar35 = local_e8;
    if (0x225 < (int)uVar16) {
      uVar38 = SUB84(DAT_14053a890,0);
      uVar39 = (undefined4)((ulonglong)DAT_14053a890 >> 0x20);
      puVar11 = DAT_140e46c88;
      if ((0x3b < DAT_140e418c8) && (DAT_140e45fac == 0)) {
        dVar24 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053a890 * dVar8 * dVar7
                                      );
        uVar9 = DAT_140e41934;
        fVar35 = (float)(dVar24 * DAT_14053b0c8) + 0.0 + DAT_14053accc;
        puVar11 = (undefined4 *)_malloc_base(0x48);
        if (puVar11 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        _DAT_140e46e28 = _DAT_140e46e28 + 1;
        bVar22 = DAT_140e46bf0 == (undefined4 *)0x0;
        puVar11[3] = fVar35;
        *puVar11 = uVar9;
        puVar11[1] = 0x66;
        puVar11[2] = 1;
        puVar11[4] = 0x43b40000;
        *(undefined2 *)(puVar11 + 5) = 0x8000;
        *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
        puVar11[10] = 0xff;
        puVar11[0xb] = 0xff;
        puVar11[0xc] = 0xff;
        puVar11[0xd] = 0xff;
        *(undefined8 *)(puVar11 + 0xe) = 1;
        *(undefined8 *)(puVar11 + 0x10) = 0;
        if (bVar22) {
          DAT_140e46bf0 = puVar11;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
        }
      }
      DAT_140e46c88 = puVar11;
      FUN_1400d9b60(1,0x70,0xff);
      dVar25 = _UNK_14053baa8;
      dVar23 = _DAT_14053baa0;
      fVar6 = DAT_14053adf4;
      fVar35 = DAT_14053ade0;
      dVar24 = DAT_14053ab08;
      uVar18 = uVar19;
      if ((DAT_140e418c8 < 0x3c) || (0 < (int)DAT_140e45fac)) {
        do {
          uVar16 = (uint)uVar18;
          uVar10 = (uint)(uVar18 >> 2);
          fVar36 = (float)uVar10 * DAT_14053ad2c + DAT_14053ad50;
          fVar37 = ((float)(uVar16 & 3) * fVar35 + fVar6 + local_e8) - DAT_14053b00c;
          if ((uVar10 & 1) == 1) {
            fVar37 = fVar37 + DAT_14053aca8;
          }
          iVar14 = *(int *)((longlong)&DAT_140e43f1c + uVar19);
          iVar17 = 0x60;
          if (iVar14 != 0) {
            iVar17 = 0xff;
          }
          uVar10 = -(uint)(iVar14 != 0) & 0xff;
          if ((iVar14 == 1) && (*(int *)((longlong)&DAT_140e43f80 + uVar19) == 0)) {
            dVar26 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) *
                                           (double)CONCAT44(uVar39,uVar38) * dVar8 * dVar7);
            uVar38 = SUB84(DAT_14053b160,0);
            uVar39 = (undefined4)((ulonglong)DAT_14053b160 >> 0x20);
            uVar10 = 0xc0 - (int)(dVar26 * DAT_14053b160);
          }
          else {
            uVar38 = SUB84(DAT_14053b160,0);
            uVar39 = (undefined4)((ulonglong)DAT_14053b160 >> 0x20);
          }
          local_f0 = 0;
          local_f8 = 1;
          local_128 = dVar23;
          uStack_120 = dVar25;
          local_130 = local_130 & 0xffff0000;
          local_138 = fVar36;
          local_118 = uVar10;
          local_110 = uVar10;
          local_108 = uVar10;
          local_100 = iVar17;
          FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e46810 + uVar19),100,1,fVar37);
          uVar9 = DAT_140e46800;
          puVar11 = DAT_140e46c88;
          if ((uVar16 == DAT_140e45274) && (0 < (int)DAT_140e45fac)) {
            puVar11 = (undefined4 *)_malloc_base(0x48);
            if (puVar11 == (undefined4 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            puVar11[3] = fVar37;
            *(undefined2 *)(puVar11 + 5) = 0;
            *(undefined8 *)(puVar11 + 0x10) = 0;
            puVar11[4] = fVar36;
            *puVar11 = uVar9;
            puVar11[1] = 100;
            puVar11[2] = 1;
            *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
            *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
            puVar11[10] = 0xff;
            puVar11[0xb] = 0xff;
            puVar11[0xc] = 0xff;
            puVar11[0xd] = 0xff;
            *(undefined8 *)(puVar11 + 0xe) = 1;
            _DAT_140e46e20 = _DAT_140e46e20 + 1;
            if (DAT_140e46bf0 == (undefined4 *)0x0) {
              DAT_140e46bf0 = puVar11;
            }
            if (DAT_140e46c88 != (undefined4 *)0x0) {
              *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
            }
            DAT_140e46c88 = puVar11;
            dVar26 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * dVar24 * dVar8 * dVar7);
            uVar9 = DAT_140e46800;
            puVar11 = (undefined4 *)_malloc_base(0x48);
            if (puVar11 == (undefined4 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            puVar11[0xd] = 0x40 - (int)(dVar26 * (double)CONCAT44(uVar39,uVar38));
            *(undefined8 *)(puVar11 + 0x10) = 0;
            puVar11[3] = fVar37;
            puVar11[4] = fVar36;
            *puVar11 = uVar9;
            puVar11[1] = 100;
            puVar11[2] = 6;
            *(undefined2 *)(puVar11 + 5) = 0;
            *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
            *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
            puVar11[10] = 0xff;
            puVar11[0xb] = 0xff;
            puVar11[0xc] = 0xff;
            *(undefined8 *)(puVar11 + 0xe) = 1;
            _DAT_140e46e20 = _DAT_140e46e20 + 1;
            if (DAT_140e46bf0 == (undefined4 *)0x0) {
              DAT_140e46bf0 = puVar11;
            }
            if (DAT_140e46c88 != (undefined4 *)0x0) {
              *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
            }
          }
          DAT_140e46c88 = puVar11;
          uVar38 = SUB84(DAT_14053a890,0);
          uVar39 = (undefined4)((ulonglong)DAT_14053a890 >> 0x20);
          uVar18 = (ulonglong)(uVar16 + 1);
          uVar19 = uVar19 + 4;
        } while ((int)(uVar16 + 1) < 0x14);
      }
      fVar35 = DAT_14053aedc;
      uVar38 = DAT_14053ac80;
      uVar10 = DAT_14053ac34;
      if (((DAT_140e418c8 == 0x3c) || (DAT_140e46014 == 1)) &&
         (lVar12 = DAT_140e47908, DAT_140e45fac == 0)) {
        while (lVar12 != 0) {
          lVar12 = *(longlong *)(lVar12 + 0x238);
          FUN_140323ce8();
        }
        local_f8 = 5;
        local_100 = 1;
        local_108 = 0;
        local_110 = 0xff;
        local_118 = 0xff;
        uStack_120._4_4_ = (undefined4)((ulonglong)uStack_120 >> 0x20);
        uStack_120 = (double)CONCAT44(uStack_120._4_4_,0xff);
        local_128._4_4_ = (undefined4)((ulonglong)local_128 >> 0x20);
        local_128 = (double)CONCAT44(local_128._4_4_,uVar38);
        local_130 = uVar10;
        local_138 = fVar35;
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
        if ((&DAT_140e43fe4)[(int)DAT_140e45274] == 0) {
          FUN_14012e070(DAT_140e45274 + 0x15e);
        }
        else {
          FUN_14012e070(DAT_140e45274 + 400);
        }
      }
      if (DAT_140e45fac == 0x3c) {
        DAT_140e45270 = 6;
        DAT_140e418c8 = 0;
        DAT_140e46014 = 0;
        DAT_140e46bb4 = 0;
        DAT_140e46bb0 = 0;
        DAT_140e45fac = 0;
        lVar12 = DAT_140e47908;
        while (lVar12 != 0) {
          lVar12 = *(longlong *)(lVar12 + 0x238);
          FUN_140323ce8();
        }
        local_f8 = 5;
        local_100 = 1;
        local_108 = 0;
        local_110 = 0xff;
        local_118 = 0xff;
        uStack_120._4_4_ = (undefined4)((ulonglong)uStack_120 >> 0x20);
        uStack_120 = (double)CONCAT44(uStack_120._4_4_,0xff);
        local_128._4_4_ = (undefined4)((ulonglong)local_128 >> 0x20);
        local_128 = (double)CONCAT44(local_128._4_4_,uVar38);
        local_130 = uVar10;
        local_138 = fVar35;
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
        DAT_140e418c8 = 0x3c;
        if ((&DAT_140e43f1c)[(int)DAT_140e45274] == 0) {
          iVar14 = DAT_140e45274 + 300;
        }
        else {
          iVar14 = DAT_140e45274 + 0x145;
        }
        FUN_14012e070(iVar14);
      }
      if ((int)DAT_140e45fac < -0x13) {
        transition_tile_wipe_out_candidate(-0x14 - DAT_140e45fac);
      }
      if (DAT_140e45fac == 0xffffffce) {
        DAT_140e45270 = 2;
        DAT_140e45274 = 5;
        DAT_140e418c8 = 0;
        DAT_140e45fac = 0;
        DAT_140e46014 = 0;
        fopen_s(&local_e0,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_e0);
        FUN_140323e90(local_e0);
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
        DAT_140e46014 = 0;
      }
      return;
    }
  } while( true );
}


