// Function: state_0c_config_menu_candidate @ 1401019e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_0c_config_menu_candidate(void)

{
  bool bVar1;
  undefined4 uVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  longlong lVar13;
  ulonglong uVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  undefined1 auStack_f8 [32];
  float local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_90;
  uint local_88;
  undefined4 uStack_84;
  ulonglong local_80;
  
  local_80 = DAT_1407c6b00 ^ (ulonglong)auStack_f8;
  uVar11 = 0;
  if (DAT_140e45270 == 0xc) {
    if (DAT_140e418c8 < 0x3c) {
      transition_tile_wipe_in_candidate();
    }
    uVar2 = DAT_140e467f0;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
    bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar2;
    *(undefined8 *)(puVar9 + 1) = 10;
    *(undefined8 *)(puVar9 + 3) = 0;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar15) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    uVar2 = DAT_140e4603c;
    DAT_140e46c88 = puVar9;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e24 = _DAT_140e46e24 + 1;
    bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar2;
    *(undefined8 *)(puVar9 + 1) = 0x65;
    *(undefined8 *)(puVar9 + 3) = 0;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar15) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    ambient_effect_update_and_render_candidate();
  }
  if (DAT_140e45270 == 0x19) {
    FUN_140106880(0xff);
  }
  bVar15 = false;
  if (((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) || (DAT_140e46014 != 0)) goto LAB_140102127;
  if (DAT_140e8cf10 == 1) {
LAB_140101bff:
    bVar1 = true;
  }
  else {
    bVar1 = bVar15;
    if (0x13 < DAT_140e8cf10) {
      uVar6 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      if (uVar6 == 0) goto LAB_140101bff;
    }
  }
  if ((DAT_140e8cf14 < 1) && (bVar1)) {
    DAT_140e45274 = DAT_140e45274 - 1;
    if ((int)DAT_140e45274 < 0) {
      DAT_140e45274 = 8;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf14 == 1) {
LAB_140101c88:
    bVar15 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar6 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
    }
    bVar15 = false;
    if (uVar6 == 0) goto LAB_140101c88;
  }
  if ((DAT_140e8cf10 < 1) && (bVar15)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (8 < (int)DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf18 == 1) {
LAB_140101d07:
    uVar14 = 1;
  }
  else {
    uVar14 = uVar11;
    if (0x13 < DAT_140e8cf18) {
      uVar6 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      uVar14 = 0;
      if (uVar6 == 0) goto LAB_140101d07;
    }
  }
  if (((DAT_140e8cf1c < 1) && ((int)uVar14 == 1)) && ((int)DAT_140e45274 < 7)) {
    if (DAT_140e45274 == 0) {
      DAT_140e418c4 = 1;
      DAT_140e468f0 = (uint)(DAT_140e468f0 != 1);
    }
    else if (DAT_140e45274 == 1) {
      iVar7 = DAT_140e468f4 + 1;
      _DAT_140e468f4 = CONCAT44(DAT_140e468f8,iVar7);
      if (2 < iVar7) {
        _DAT_140e468f4 = (ulonglong)DAT_140e468f8 << 0x20;
      }
    }
    else if (DAT_140e45274 == 2) {
      _DAT_140e468f4 = (ulonglong)CONCAT14(DAT_140e468f8 != 1,DAT_140e468f4);
    }
    else if (DAT_140e45274 == 3) {
      _DAT_140e468fc = CONCAT44(DAT_140e46900,(uint)(DAT_140e468fc != 1));
    }
    else if (DAT_140e45274 == 4) {
      _DAT_140e468fc = (ulonglong)CONCAT14(DAT_140e46900 != 1,DAT_140e468fc);
    }
    else if (DAT_140e45274 == 5) {
      DAT_140e46904 = (uint)(DAT_140e46904 != 1);
    }
    else if ((DAT_140e45274 == 6) && (DAT_140e46908 = DAT_140e46908 + 1, 3 < DAT_140e46908)) {
      DAT_140e46908 = 0;
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf1c == 1) {
LAB_140101e7a:
    uVar14 = 1;
  }
  else {
    uVar14 = uVar11;
    if (0x13 < DAT_140e8cf1c) {
      uVar6 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      uVar14 = 0;
      if (uVar6 == 0) goto LAB_140101e7a;
    }
  }
  if (((DAT_140e8cf18 < 1) && ((int)uVar14 == 1)) && ((int)DAT_140e45274 < 7)) {
    if (DAT_140e45274 == 0) {
      DAT_140e418c4 = 1;
      DAT_140e468f0 = (uint)(DAT_140e468f0 != 1);
    }
    else if (DAT_140e45274 == 1) {
      iVar7 = DAT_140e468f4 + -1;
      _DAT_140e468f4 = CONCAT44(DAT_140e468f8,iVar7);
      if (iVar7 < 0) {
        _DAT_140e468f4 = CONCAT44(DAT_140e468f8,2);
      }
    }
    else if (DAT_140e45274 == 2) {
      _DAT_140e468f4 = (ulonglong)CONCAT14(DAT_140e468f8 != 1,DAT_140e468f4);
    }
    else if (DAT_140e45274 == 3) {
      _DAT_140e468fc = CONCAT44(DAT_140e46900,(uint)(DAT_140e468fc != 1));
    }
    else if (DAT_140e45274 == 4) {
      _DAT_140e468fc = (ulonglong)CONCAT14(DAT_140e46900 != 1,DAT_140e468fc);
    }
    else if (DAT_140e45274 == 5) {
      DAT_140e46904 = (uint)(DAT_140e46904 != 1);
    }
    else if ((DAT_140e45274 == 6) && (DAT_140e46908 = DAT_140e46908 + -1, DAT_140e46908 < 0)) {
      DAT_140e46908 = 3;
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (((DAT_140e467c8 == 1) && (6 < (int)DAT_140e45274)) && (DAT_140e467fc == 0)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    if (DAT_140e45274 == 7) {
      _DAT_140e468f4 = _DAT_14053b610;
      _DAT_140e468fc = _UNK_14053b618;
      DAT_140e46904 = 0;
    }
    if (DAT_140e45274 == 8) {
      DAT_140e45fac = 1;
    }
    DAT_140e467fc = 1;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 8) {
      DAT_140e45fac = 0xffffffff;
    }
    else {
      DAT_140e45274 = 8;
      DAT_140e46014 = 1;
    }
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
LAB_140102127:
  uVar5 = _UNK_14053bb28;
  uVar4 = _DAT_14053bb20;
  fVar3 = DAT_14053b338;
  uVar2 = DAT_14053af4c;
  local_88 = 0;
  uVar14 = uVar11;
LAB_140102160:
  do {
    uVar6 = (uint)uVar11;
    uVar12 = 0x60;
    lVar13 = uVar14 + 0xc;
    if (uVar6 == 7) {
      lVar13 = 9;
    }
    if (uVar14 == 8) {
      lVar13 = 8;
    }
    fVar16 = (float)(int)((uVar6 + 3) * 0x32);
    if (DAT_140e45274 == uVar6) {
      if (DAT_140e45fac != 0) {
        uVar8 = DAT_140e45fac + 10000 & 0x80000003;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar8) goto LAB_1401021b4;
      }
      uVar12 = 0xff;
    }
LAB_1401021b4:
    uVar10 = (&DAT_140e47340)[lVar13];
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar9[4] = fVar16;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    *puVar9 = uVar10;
    puVar9[1] = 0x7a;
    puVar9[2] = 1;
    puVar9[3] = 0x44098000;
    *(undefined2 *)(puVar9 + 5) = 0;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = uVar12;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    switch(uVar6) {
    case 0:
      uVar8 = DAT_140e468f0;
      break;
    case 1:
      if (DAT_140e468f4 == 0) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = local_d0 & 0xffff0000;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e46c30,0x7a,1,DAT_14053af1c);
        fVar17 = DAT_14053af08;
        uVar6 = 6;
        do {
          local_90 = 0;
          local_98 = 1;
          local_a8 = 0xff;
          local_b0 = 0xff;
          local_b8 = 0xff;
          local_c8 = uVar4;
          uStack_c0 = uVar5;
          local_d0 = local_d0 & 0xffff0000;
          local_d8 = fVar16;
          local_a0 = uVar12;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar6],0x7a,1,fVar17);
          fVar17 = fVar17 + fVar3;
          bVar15 = 9 < uVar6;
          uVar6 = 0;
        } while (bVar15);
        uVar6 = local_88;
      }
      iVar7 = DAT_140e468f4;
      if (DAT_140e468f4 == 1) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = local_d0 & 0xffff0000;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e46c30,0x7a,1,DAT_14053af1c);
        fVar17 = DAT_14053af08;
        uVar6 = 3;
        do {
          local_90 = 0;
          local_98 = 1;
          local_a8 = 0xff;
          local_b0 = 0xff;
          local_b8 = 0xff;
          local_c8 = uVar4;
          uStack_c0 = uVar5;
          local_d0 = local_d0 & 0xffff0000;
          local_d8 = fVar16;
          local_a0 = uVar12;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar6],0x7a,1,fVar17);
          fVar17 = fVar17 + fVar3;
          bVar15 = 9 < uVar6;
          uVar6 = 0;
        } while (bVar15);
        iVar7 = DAT_140e468f4;
        uVar6 = local_88;
      }
      if (iVar7 == 2) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = local_d0 & 0xffff0000;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e46c30,0x7a,1,DAT_14053af1c);
        fVar17 = DAT_14053af08;
        uVar8 = 2;
        do {
          local_90 = 0;
          local_98 = 1;
          local_a8 = 0xff;
          local_b0 = 0xff;
          local_b8 = 0xff;
          local_c8 = uVar4;
          uStack_c0 = uVar5;
          local_d0 = local_d0 & 0xffff0000;
          local_d8 = fVar16;
          local_a0 = uVar12;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar8],0x7a,1,fVar17);
          fVar17 = fVar17 + fVar3;
          bVar15 = 9 < uVar8;
          uVar6 = local_88;
          uVar8 = 0;
        } while (bVar15);
      }
      goto LAB_1401022da;
    case 2:
      uVar8 = DAT_140e468f8;
      break;
    case 3:
      uVar8 = DAT_140e468fc;
      break;
    case 4:
      uVar8 = DAT_140e46900;
      break;
    case 5:
      local_d0 = (uint)local_d0._2_2_ << 0x10;
      uVar10 = DAT_140e478e8;
      if (DAT_140e46904 == 1) {
        uVar10 = DAT_140e478ec;
      }
      goto LAB_1401022d5;
    case 6:
      if (DAT_140e46908 == 0) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = (uint)local_d0._2_2_ << 0x10;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e478d0,0x7a,1,uVar2);
      }
      if (DAT_140e46908 == 1) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = local_d0 & 0xffff0000;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e478dc,0x7a,1,uVar2);
      }
      if (DAT_140e46908 == 2) {
        local_90 = 0;
        local_98 = 1;
        local_a8 = 0xff;
        local_b0 = 0xff;
        local_b8 = 0xff;
        local_c8 = uVar4;
        uStack_c0 = uVar5;
        local_d0 = local_d0 & 0xffff0000;
        local_d8 = fVar16;
        local_a0 = uVar12;
        FUN_1400c8410(DAT_140e478e0,0x7a,1,uVar2);
      }
      uVar10 = DAT_140e478e4;
      if (DAT_140e46908 != 3) goto switchD_14010227b_default;
      goto LAB_140102292;
    default:
      goto switchD_14010227b_default;
    }
    uVar10 = DAT_140e478c8;
    if (uVar8 != 1) {
      uVar10 = DAT_140e478cc;
    }
LAB_140102292:
    local_d0 = local_d0 & 0xffff0000;
LAB_1401022d5:
    uStack_c0 = uVar5;
    local_c8 = uVar4;
    local_90 = 0;
    local_98 = 1;
    local_a8 = 0xff;
    local_b0 = 0xff;
    local_b8 = 0xff;
    local_d8 = fVar16;
    local_a0 = uVar12;
    FUN_1400c8410(uVar10,0x7a,1,uVar2);
LAB_1401022da:
    local_88 = uVar6 + 1;
    uVar11 = (ulonglong)local_88;
    uVar14 = uVar14 + 1;
  } while( true );
switchD_14010227b_default:
  local_88 = uVar6 + 1;
  uVar11 = (ulonglong)local_88;
  uVar14 = uVar14 + 1;
  if (8 < (int)local_88) {
    FUN_1400d9b60(0,0x70,0xff);
    if (DAT_140e45270 == 0xc) {
      lVar13 = DAT_140e47908;
      if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
        while (lVar13 != 0) {
          lVar13 = *(longlong *)(lVar13 + 0x238);
          FUN_140323ce8();
        }
        local_98 = 5;
        local_a0 = 1;
        local_a8 = 0;
        local_b0 = 0xff;
        local_b8 = 0xff;
        uVar11 = (ulonglong)uStack_c0 >> 0x20;
        uStack_c0 = CONCAT44((int)uVar11,0xff);
        uVar11 = (ulonglong)local_c8 >> 0x20;
        local_c8 = CONCAT44((int)uVar11,DAT_14053ac80);
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
        local_d8 = DAT_14053aecc;
        local_d0 = DAT_14053ac34;
        FUN_14012e070(DAT_140e45274 + 0xef,0);
      }
      if (0x13 < (int)DAT_140e45fac) {
        transition_tile_wipe_out_candidate(DAT_140e45fac - 0x14);
      }
    }
    if (DAT_140e45fac == 0x32) {
      if (DAT_140e45274 == 8) {
        if (DAT_140e45270 == 0xc) {
          DAT_140e45270 = 10;
          DAT_140e45274 = 5;
          DAT_140e418c8 = 0;
        }
        else if (DAT_140e45270 == 0x19) {
          DAT_140e45270 = 0x18;
          DAT_140e45274 = 4;
        }
      }
      DAT_140e45fac = 0;
      DAT_140e46014 = 0;
      fopen_s((FILE **)&local_88,"save\\config.dat","wb");
      FUN_140327c78(&DAT_140e468f0,0x1c,1,CONCAT44(uStack_84,local_88));
      FUN_140323e90(CONCAT44(uStack_84,local_88));
      DAT_140e471fc = 0xb4;
    }
    if (((int)DAT_140e45fac < -0x13) && (DAT_140e45270 == 0xc)) {
      transition_tile_wipe_out_candidate(-0x14 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffce) {
      if (DAT_140e45270 == 0xc) {
        DAT_140e45270 = 10;
        DAT_140e45274 = 5;
        DAT_140e418c8 = 0;
      }
      else if (DAT_140e45270 == 0x19) {
        DAT_140e45270 = 0x18;
        DAT_140e45274 = 4;
      }
      DAT_140e45fac = 0;
      DAT_140e46014 = 0;
      fopen_s((FILE **)&local_88,"save\\config.dat","wb");
      FUN_140327c78(&DAT_140e468f0,0x1c,1,CONCAT44(uStack_84,local_88));
      FUN_140323e90(CONCAT44(uStack_84,local_88));
      DAT_140e471fc = 0xb4;
    }
    if (0 < (int)DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    if (0x7fffffff < DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac - 1;
    }
    if (DAT_140e46014 == 1) {
      DAT_140e46014 = 0;
    }
    if (DAT_140e45270 == 0xc) {
      DAT_140e418c8 = DAT_140e418c8 + 1;
    }
    return;
  }
  goto LAB_140102160;
}


