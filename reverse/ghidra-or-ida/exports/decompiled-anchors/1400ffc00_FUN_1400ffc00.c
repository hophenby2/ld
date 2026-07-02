// Function: FUN_1400ffc00 @ 1400ffc00
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ffc00(void)

{
  longlong lVar1;
  bool bVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  ulonglong uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  undefined4 uVar18;
  float fVar19;
  float fVar20;
  undefined1 auStack_128 [32];
  float local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  int local_b8;
  undefined4 uStack_b4;
  ulonglong local_b0;
  
  local_b0 = DAT_1407c6b00 ^ (ulonglong)auStack_128;
  if (DAT_140e418c8 == 1) {
    DAT_140e47648 = DAT_140e441b4;
LAB_1400ffc7b:
    FUN_1400d4310();
  }
  else if (DAT_140e418c8 < 0x3c) goto LAB_1400ffc7b;
  uVar13 = DAT_140e467f0;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
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
  if (bVar17) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  uVar13 = DAT_140e46034;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
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
  if (bVar17) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  DAT_140e46c88 = puVar11;
  FUN_1400d3a60();
  bVar17 = false;
  if (((0x1f < DAT_140e418c8) && (DAT_140e45fac == 0)) && (DAT_140e46014 == 0)) {
    if (DAT_140e8cf10 == 1) {
LAB_1400ffe21:
      bVar17 = true;
    }
    else if (0x13 < DAT_140e8cf10) {
      uVar9 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_1400ffe21;
    }
    if ((DAT_140e8cf14 < 1) && (bVar17)) {
      DAT_140e45274 = DAT_140e45274 + -1;
      if (DAT_140e45274 < 0) {
        DAT_140e45274 = 8;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    bVar17 = false;
    if (DAT_140e8cf14 == 1) {
LAB_1400ffeae:
      bVar2 = true;
    }
    else {
      bVar2 = bVar17;
      if (0x13 < DAT_140e8cf14) {
        uVar9 = DAT_140e8cf14 - 0x14U & 0x80000007;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
        }
        if (uVar9 == 0) goto LAB_1400ffeae;
      }
    }
    if ((DAT_140e8cf10 < 1) && (bVar2)) {
      DAT_140e45274 = DAT_140e45274 + 1;
      if (8 < DAT_140e45274) {
        DAT_140e45274 = 0;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    if (DAT_140e8cf18 == 1) {
LAB_1400fff2e:
      bVar2 = true;
    }
    else {
      bVar2 = bVar17;
      if (0x13 < DAT_140e8cf18) {
        uVar9 = DAT_140e8cf18 - 0x14U & 0x80000007;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
        }
        if (uVar9 == 0) goto LAB_1400fff2e;
      }
    }
    if (((DAT_140e8cf1c < 1) && (bVar2)) && (DAT_140e45274 < 4)) {
      if (DAT_140e45274 == 0) {
        if (DAT_140e4418c < 10) {
          DAT_140e4418c = DAT_140e4418c + 1;
          FUN_140184700(DAT_140e4418c * 0x19,DAT_140e45108);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        else {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        FUN_14018a340(uVar13,1,1);
      }
      if (DAT_140e45274 == 1) {
        if (DAT_140e44190 < 10) {
          DAT_140e44190 = DAT_140e44190 + 1;
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        else {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        FUN_14018a340(uVar13,1,1);
      }
      if (DAT_140e45274 == 2) {
        DAT_140e47648 = DAT_140e47648 + 1;
        if (3 < DAT_140e47648) {
          DAT_140e47648 = 0;
        }
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
      if (DAT_140e45274 == 3) {
        if (DAT_140e43f18 == 1) {
          DAT_140e441b8 = (uint)(DAT_140e441b8 != 1);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        else {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        FUN_14018a340(uVar13,1,1);
      }
      DAT_140e46014 = 1;
      DAT_140e467fc = 1;
    }
    if (DAT_140e8cf1c == 1) {
LAB_1401000f4:
      bVar17 = true;
    }
    else if (0x13 < DAT_140e8cf1c) {
      uVar9 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_1401000f4;
    }
    if (((DAT_140e8cf18 < 1) && (bVar17)) && (DAT_140e45274 < 4)) {
      if (DAT_140e45274 == 0) {
        if (DAT_140e4418c < 1) {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        else {
          DAT_140e4418c = DAT_140e4418c + -1;
          FUN_140184700(DAT_140e4418c * 0x19,DAT_140e45108);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        FUN_14018a340(uVar13,1,1);
      }
      if (DAT_140e45274 == 1) {
        if (DAT_140e44190 < 1) {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        else {
          DAT_140e44190 = DAT_140e44190 + -1;
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        FUN_14018a340(uVar13,1,1);
      }
      if (DAT_140e45274 == 2) {
        DAT_140e47648 = DAT_140e47648 + -1;
        if (DAT_140e47648 < 0) {
          DAT_140e47648 = 3;
        }
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
      if (DAT_140e45274 == 3) {
        if (DAT_140e43f18 == 1) {
          DAT_140e441b8 = (uint)(DAT_140e441b8 != 1);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
          uVar13 = DAT_140e47200;
        }
        else {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar13 = DAT_140e4720c;
        }
        FUN_14018a340(uVar13,1,1);
      }
      DAT_140e46014 = 1;
      DAT_140e467fc = 1;
    }
    if (((DAT_140e467c8 == 1) && (3 < DAT_140e45274)) && (DAT_140e467fc == 0)) {
      if ((DAT_140e45274 == 7) && (DAT_140e441bc == 0)) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar13 = DAT_140e4720c;
      }
      else {
        DAT_140e45fac = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        uVar13 = DAT_140e47204;
      }
      FUN_14018a340(uVar13,1,1);
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
        (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))
        )))))) {
      DAT_140e467fc = 0;
    }
  }
  uVar8 = _UNK_14053bb28;
  uVar7 = _DAT_14053bb20;
  fVar6 = DAT_14053b338;
  uVar5 = DAT_14053af4c;
  uVar4 = DAT_14053af44;
  uVar13 = DAT_14053af2c;
  fVar3 = DAT_14053af20;
  puVar11 = &DAT_140e47340;
  local_b8 = 0;
LAB_140100446:
  do {
    iVar10 = local_b8;
    uVar15 = 0x60;
    fVar19 = (float)(local_b8 * 0x32 + 0x82);
    uVar16 = 0xff;
    if (DAT_140e45274 == local_b8) {
      if (DAT_140e45fac != 0) {
        uVar9 = DAT_140e45fac + 10000 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar9) goto LAB_140100490;
      }
      uVar15 = 0xff;
    }
LAB_140100490:
    if (local_b8 == 3) {
      if (DAT_140e43f18 == 0) {
        uVar16 = 0x80;
      }
    }
    else if ((local_b8 == 7) && (uVar16 = 0xff, DAT_140e441bc == 0)) {
      uVar16 = 0x80;
    }
    uVar18 = *puVar11;
    puVar12 = (undefined4 *)_malloc_base(0x48);
    if (puVar12 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar12 = uVar18;
    *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
    puVar12[4] = fVar19;
    puVar12[1] = 100;
    puVar12[2] = 1;
    puVar12[3] = 0x44098000;
    *(undefined2 *)(puVar12 + 5) = 0;
    puVar12[10] = uVar16;
    puVar12[0xb] = uVar16;
    puVar12[0xc] = uVar16;
    puVar12[0xd] = uVar15;
    *(undefined8 *)(puVar12 + 0xe) = 1;
    *(undefined8 *)(puVar12 + 0x10) = 0;
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar12;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
    }
    uVar18 = uVar4;
    DAT_140e46c88 = puVar12;
    if (iVar10 == 0) {
      uVar14 = (longlong)DAT_140e4418c * 10;
      if (uVar14 < 10) {
LAB_1401009e9:
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = (uint)local_100._2_2_ << 0x10;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[uVar14],100,1,uVar13);
        uVar16 = DAT_140e46c58;
      }
      else {
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = (uint)local_100._2_2_ << 0x10;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar14 + (int)(uVar14 / 10) * -10],100,1,uVar13);
        uVar14 = uVar14 / 10;
        fVar20 = fVar3;
        do {
          local_c0 = 0;
          local_c8 = 1;
          local_d8 = 0xff;
          local_e0 = 0xff;
          local_e8 = 0xff;
          local_f8 = uVar7;
          uStack_f0 = uVar8;
          local_100 = local_100 & 0xffff0000;
          local_108 = fVar19;
          local_d0 = uVar15;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar14 + (int)(uVar14 / 10) * -10],100,1,fVar20);
          fVar20 = fVar20 + fVar6;
          bVar17 = 9 < uVar14;
          uVar14 = uVar14 / 10;
          iVar10 = local_b8;
          uVar16 = DAT_140e46c58;
        } while (bVar17);
      }
LAB_140100a45:
      local_c0 = 0;
      local_c8 = 1;
      local_d8 = 0xff;
      local_e0 = 0xff;
      local_e8 = 0xff;
      local_f8 = uVar7;
      uStack_f0 = uVar8;
      local_100 = local_100 & 0xffff0000;
      local_108 = fVar19;
      local_d0 = uVar15;
      FUN_1400c8410(uVar16,100,1,uVar18);
LAB_140100a89:
      local_b8 = iVar10 + 1;
      puVar11 = puVar11 + 1;
      goto LAB_140100446;
    }
    if (iVar10 == 1) {
      uVar14 = (longlong)DAT_140e44190 * 10;
      if (uVar14 < 10) goto LAB_1401009e9;
      local_c0 = 0;
      local_c8 = 1;
      local_d8 = 0xff;
      local_e0 = 0xff;
      local_e8 = 0xff;
      local_f8 = uVar7;
      uStack_f0 = uVar8;
      local_100 = (uint)local_100._2_2_ << 0x10;
      local_108 = fVar19;
      local_d0 = uVar15;
      FUN_1400c8410((&DAT_140e46c30)[(int)uVar14 + (int)(uVar14 / 10) * -10],100,1,uVar13);
      uVar14 = uVar14 / 10;
      fVar20 = fVar3;
      do {
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = local_100 & 0xffff0000;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar14 + (int)(uVar14 / 10) * -10],100,1,fVar20);
        fVar20 = fVar20 + fVar6;
        bVar17 = 9 < uVar14;
        uVar14 = uVar14 / 10;
        iVar10 = local_b8;
        uVar16 = DAT_140e46c58;
      } while (bVar17);
      goto LAB_140100a45;
    }
    if (iVar10 == 2) {
      if (DAT_140e47648 == 0) {
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = (uint)local_100._2_2_ << 0x10;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410(DAT_140e478f4,100,1,uVar5);
      }
      if (DAT_140e47648 == 1) {
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = local_100 & 0xffff0000;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410(DAT_140e478f8,100,1,uVar5);
      }
      if (DAT_140e47648 == 2) {
        local_c0 = 0;
        local_c8 = 1;
        local_d8 = 0xff;
        local_e0 = 0xff;
        local_e8 = 0xff;
        local_f8 = uVar7;
        uStack_f0 = uVar8;
        local_100 = local_100 & 0xffff0000;
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410(DAT_140e478fc,100,1,uVar5);
      }
      uVar18 = uVar5;
      uVar16 = DAT_140e47900;
      if (DAT_140e47648 == 3) goto LAB_140100a45;
      goto LAB_140100a89;
    }
    if (iVar10 == 3) {
      local_c0 = 0;
      local_c8 = 1;
      local_f8 = uVar7;
      uStack_f0 = uVar8;
      local_100 = (uint)local_100._2_2_ << 0x10;
      local_e8 = uVar16;
      local_e0 = uVar16;
      local_d8 = uVar16;
      if (DAT_140e441b8 == 1) {
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410(DAT_140e478c8,100,1,uVar5);
        local_b8 = 4;
        puVar11 = puVar11 + 1;
      }
      else {
        local_108 = fVar19;
        local_d0 = uVar15;
        FUN_1400c8410(DAT_140e478cc,100,1,uVar5);
        local_b8 = 4;
        puVar11 = puVar11 + 1;
      }
      goto LAB_140100446;
    }
    local_b8 = iVar10 + 1;
    puVar11 = puVar11 + 1;
  } while (local_b8 < 9);
  FUN_1400d9b60(0,0x70,0xff);
  uVar9 = DAT_14053ac34;
  uVar13 = DAT_14053ac80;
  lVar1 = DAT_140e47908;
  if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
    while (DAT_14053ac34 = uVar9, DAT_14053ac80 = uVar13, lVar1 != 0) {
      lVar1 = *(longlong *)(lVar1 + 0x238);
      FUN_140323ce8();
      uVar9 = DAT_14053ac34;
      uVar13 = DAT_14053ac80;
    }
    local_c8 = 5;
    local_d0 = 1;
    local_d8 = 0;
    local_e0 = 0xff;
    local_e8 = 0xff;
    uStack_f0._4_4_ = (undefined4)((ulonglong)uStack_f0 >> 0x20);
    uStack_f0 = CONCAT44(uStack_f0._4_4_,0xff);
    local_f8._4_4_ = (undefined4)((ulonglong)local_f8 >> 0x20);
    local_f8 = CONCAT44(local_f8._4_4_,uVar13);
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    local_108 = DAT_14053aecc;
    local_100 = uVar9;
    FUN_14012e070(DAT_140e45274 + 0x1f,0);
    if ((DAT_140e45274 == 3) && (DAT_140e43f18 == 0)) {
      local_c8 = 5;
      local_d0 = 1;
      local_d8 = 0;
      local_e0 = 0xff;
      local_e8 = 0xff;
      uStack_f0 = CONCAT44(uStack_f0._4_4_,0xff);
      local_f8 = CONCAT44(local_f8._4_4_,uVar13);
      local_108 = DAT_14053aee0;
      local_100 = uVar9;
      FUN_14012e070(0x30,0);
    }
  }
  if (DAT_140e45fac == 1) {
    if (DAT_140e45274 == 7) {
      puVar11 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar11,0);
        puVar11 = puVar11 + 1;
      } while ((longlong)puVar11 < 0x140e45178);
      goto LAB_140100701;
    }
  }
  else {
LAB_140100701:
    if (0x13 < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x14);
    }
    if (DAT_140e45fac == 0x32) {
      if (DAT_140e45274 == 4) {
        DAT_140e45274 = 0;
        DAT_140e45270 = 0xb;
      }
      else if (DAT_140e45274 == 5) {
        DAT_140e45274 = 0;
        DAT_140e45270 = 0xc;
      }
      else if (DAT_140e45274 == 6) {
        DAT_140e45274 = 0;
        DAT_140e46064 = 0;
        DAT_140e45270 = 0xd;
      }
      else {
        if (DAT_140e45274 == 7) {
          DAT_140e41928 = 0xffffffff;
          FUN_1400f7150();
        }
        if (DAT_140e45274 == 8) {
          DAT_140e45274 = 7;
          DAT_140e45270 = 2;
        }
      }
      if (DAT_140e47648 != DAT_140e441b4) {
        DAT_140e441b4 = DAT_140e47648;
        iVar10 = FUN_1400d0e50();
        if (iVar10 == -1) {
          MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
        }
      }
      DAT_140e418c8 = 0;
      DAT_140e45fac = 0;
      DAT_140e46014 = 0;
      fopen_s((FILE **)&local_b8,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_b4,local_b8));
      FUN_140323e90(CONCAT44(uStack_b4,local_b8));
      DAT_140e471fc = 0xb4;
    }
    if ((int)DAT_140e45fac < -0x13) {
      FUN_1400d3fd0(-0x14 - DAT_140e45fac);
    }
    if (DAT_140e45fac == 0xffffffce) {
      if (DAT_140e47648 != DAT_140e441b4) {
        DAT_140e441b4 = DAT_140e47648;
        iVar10 = FUN_1400d0e50();
        if (iVar10 == -1) {
          MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
        }
      }
      DAT_140e45270 = 2;
      DAT_140e45274 = 7;
      DAT_140e418c8 = 0;
      DAT_140e45fac = 0;
      DAT_140e46014 = 0;
      fopen_s((FILE **)&local_b8,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_b4,local_b8));
      FUN_140323e90(CONCAT44(uStack_b4,local_b8));
      DAT_140e471fc = 0xb4;
    }
    if ((int)DAT_140e45fac < 1) goto LAB_140100d85;
  }
  DAT_140e45fac = DAT_140e45fac + 1;
LAB_140100d85:
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  if (DAT_140e46014 == 1) {
    DAT_140e46014 = 0;
  }
  return;
}


