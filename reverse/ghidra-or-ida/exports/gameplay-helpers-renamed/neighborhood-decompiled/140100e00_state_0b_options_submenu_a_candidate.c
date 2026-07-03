// Function: state_0b_options_submenu_a_candidate @ 140100e00
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_0b_options_submenu_a_candidate(void)

{
  longlong lVar1;
  bool bVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  FILE *pFVar13;
  undefined4 uVar14;
  int iVar15;
  FILE *pFVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  undefined1 auStack_118 [32];
  float local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  FILE *local_a8;
  ulonglong local_a0;
  
  local_a0 = DAT_1407c6b00 ^ (ulonglong)auStack_118;
  if (DAT_140e418c8 < 0x3c) {
    transition_tile_wipe_in_candidate();
  }
  uVar3 = DAT_140e467f0;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  iVar15 = 0;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar3;
  *(undefined8 *)(puVar10 + 1) = 10;
  *(undefined8 *)(puVar10 + 3) = 0;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar17) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar10;
  }
  uVar3 = DAT_140e46038;
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar3;
  *(undefined8 *)(puVar10 + 1) = 0x65;
  *(undefined8 *)(puVar10 + 3) = 0;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = 0xff;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar17) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
  }
  DAT_140e46c88 = puVar10;
  ambient_effect_update_and_render_candidate();
  bVar17 = false;
  if (((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) || (DAT_140e46014 != 0)) goto LAB_1401013da;
  if (DAT_140e8cf10 == 1) {
LAB_140101006:
    bVar2 = true;
  }
  else {
    bVar2 = bVar17;
    if (0x13 < DAT_140e8cf10) {
      uVar9 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_140101006;
    }
  }
  if ((DAT_140e8cf14 < 1) && (bVar2)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 3;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf14 == 1) {
LAB_140101093:
    bVar17 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar9 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    bVar17 = false;
    if (uVar9 == 0) goto LAB_140101093;
  }
  if ((DAT_140e8cf10 < 1) && (bVar17)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (3 < DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf18 == 1) {
LAB_140101113:
    bVar17 = true;
  }
  else {
    bVar17 = false;
    if (0x13 < DAT_140e8cf18) {
      uVar9 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      bVar17 = false;
      if (uVar9 == 0) goto LAB_140101113;
    }
  }
  if (((DAT_140e8cf1c < 1) && (bVar17)) && (DAT_140e45274 < 2)) {
    if (DAT_140e45274 == 0) {
      DAT_140e44194 = (uint)(DAT_140e44194 != 1);
    }
    else if (DAT_140e45274 == 1) {
      if (DAT_140e44198 < 6) {
        DAT_140e44198 = DAT_140e44198 + 1;
      }
      else {
        DAT_140e44198 = 0;
      }
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf1c == 1) {
LAB_1401011d6:
    bVar17 = true;
  }
  else {
    bVar17 = false;
    if (0x13 < DAT_140e8cf1c) {
      uVar9 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      bVar17 = false;
      if (uVar9 == 0) goto LAB_1401011d6;
    }
  }
  if (((DAT_140e8cf18 < 1) && (bVar17)) && (DAT_140e45274 < 2)) {
    if (DAT_140e45274 == 0) {
      DAT_140e44194 = (uint)(DAT_140e44194 != 1);
    }
    else if (DAT_140e45274 == 1) {
      if (DAT_140e44198 < 1) {
        DAT_140e44198 = 6;
      }
      else {
        DAT_140e44198 = DAT_140e44198 + -1;
      }
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (((DAT_140e467c8 == 1) && (1 < DAT_140e45274)) && (DAT_140e467fc == 0)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    if (DAT_140e45274 == 2) {
      DAT_140e44194 = 1;
      DAT_140e467fc = 1;
      DAT_140e44198 = 6;
    }
    else {
      if (DAT_140e45274 == 3) {
        DAT_140e45fac = 1;
      }
      DAT_140e467fc = 1;
    }
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 3) {
      DAT_140e45fac = 0xffffffff;
    }
    else {
      DAT_140e45274 = 3;
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
LAB_1401013da:
  uVar8 = _UNK_14053bb28;
  uVar7 = _DAT_14053bb20;
  fVar6 = DAT_14053b338;
  uVar5 = DAT_14053af4c;
  uVar3 = DAT_14053af08;
  fVar4 = DAT_14053aef4;
  pFVar16 = (FILE *)0xa;
LAB_14010141a:
  do {
    uVar14 = 0x60;
    fVar19 = (float)(iVar15 * 0x32 + 0xb4);
    if (iVar15 == 2) {
      pFVar13 = (FILE *)0x9;
    }
    else {
      pFVar13 = pFVar16;
      if (iVar15 == 3) {
        pFVar13 = (FILE *)0x8;
      }
    }
    if (DAT_140e45274 == iVar15) {
      if (DAT_140e45fac != 0) {
        uVar9 = DAT_140e45fac + 10000 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar9) goto LAB_14010147a;
      }
      uVar14 = 0xff;
    }
LAB_14010147a:
    uVar12 = (&DAT_140e47340)[(longlong)pFVar13];
    local_a8 = pFVar16;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar10 = uVar12;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[4] = fVar19;
    puVar10[1] = 100;
    puVar10[2] = 1;
    puVar10[3] = 0x44098000;
    *(undefined2 *)(puVar10 + 5) = 0;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = uVar14;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
    DAT_140e46c88 = puVar10;
    if (iVar15 == 0) {
      uVar12 = DAT_140e478d8;
      if (DAT_140e44194 == 1) {
        uVar12 = DAT_140e478d4;
      }
LAB_140101981:
      local_b0 = 0;
      local_b8 = 1;
      local_c8 = 0xff;
      local_d0 = 0xff;
      local_d8 = 0xff;
      local_e8 = uVar7;
      uStack_e0 = uVar8;
      local_f0 = (uint)local_f0._2_2_ << 0x10;
      local_f8 = fVar19;
      local_c0 = uVar14;
      FUN_1400c8410(uVar12,100,1,uVar5);
      iVar15 = iVar15 + 1;
      pFVar16 = (FILE *)((longlong)&pFVar16->_ptr + 1);
      goto LAB_14010141a;
    }
    if (iVar15 == 1) {
      uVar11 = (ulonglong)DAT_140e44198;
      uVar12 = DAT_140e478d0;
      if ((DAT_140e44198 == 0) || (uVar12 = DAT_140e478cc, DAT_140e44198 == 6)) goto LAB_140101981;
      local_b0 = 0;
      local_b8 = 1;
      local_c8 = 0xff;
      local_d0 = 0xff;
      local_d8 = 0xff;
      local_e8 = uVar7;
      uStack_e0 = uVar8;
      local_f0 = (uint)local_f0._2_2_ << 0x10;
      if (uVar11 < 10) {
        local_f8 = fVar19;
        local_c0 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[uVar11],100,1,uVar3);
        iVar15 = 2;
        pFVar16 = (FILE *)((longlong)&pFVar16->_ptr + 1);
      }
      else {
        local_f8 = fVar19;
        local_c0 = uVar14;
        FUN_1400c8410((&DAT_140e46c30)[DAT_140e44198 + (int)(uVar11 / 10) * -10],100,1,uVar3);
        uVar11 = uVar11 / 10;
        fVar18 = fVar4;
        do {
          local_b0 = 0;
          local_b8 = 1;
          local_c8 = 0xff;
          local_d0 = 0xff;
          local_d8 = 0xff;
          local_e8 = uVar7;
          uStack_e0 = uVar8;
          local_f0 = local_f0 & 0xffff0000;
          local_f8 = fVar19;
          local_c0 = uVar14;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar11 + (int)(uVar11 / 10) * -10],100,1,fVar18);
          fVar18 = fVar18 + fVar6;
          bVar17 = 9 < uVar11;
          uVar11 = uVar11 / 10;
        } while (bVar17);
        iVar15 = 2;
        pFVar16 = (FILE *)((longlong)&local_a8->_ptr + 1);
      }
    }
    else {
      pFVar16 = (FILE *)((longlong)&pFVar16->_ptr + 1);
      iVar15 = iVar15 + 1;
      if (3 < iVar15) {
        local_a8 = pFVar16;
        FUN_1400d9b60(0,0x70,0xff);
        uVar9 = DAT_14053ac34;
        uVar3 = DAT_14053ac80;
        lVar1 = DAT_140e47908;
        if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
          while (DAT_14053ac34 = uVar9, DAT_14053ac80 = uVar3, lVar1 != 0) {
            lVar1 = *(longlong *)(lVar1 + 0x238);
            FUN_140323ce8();
            uVar9 = DAT_14053ac34;
            uVar3 = DAT_14053ac80;
          }
          local_b8 = 5;
          local_c0 = 1;
          local_c8 = 0;
          local_d0 = 0xff;
          local_d8 = 0xff;
          uStack_e0._4_4_ = (undefined4)((ulonglong)uStack_e0 >> 0x20);
          uStack_e0 = CONCAT44(uStack_e0._4_4_,0xff);
          local_e8._4_4_ = (undefined4)((ulonglong)local_e8 >> 0x20);
          local_e8 = CONCAT44(local_e8._4_4_,uVar3);
          DAT_140e47908 = 0;
          DAT_140e9fd30 = 0;
          local_f8 = DAT_14053aecc;
          local_f0 = uVar9;
          FUN_14012e070(DAT_140e45274 + 0x28,0);
          if ((DAT_140e441b4 == 1) && (DAT_140e45274 == 0)) {
            local_b8 = 5;
            local_c0 = 1;
            local_c8 = 0;
            local_d0 = 0xff;
            local_d8 = 0xff;
            uStack_e0 = CONCAT44(uStack_e0._4_4_,0xff);
            local_e8 = CONCAT44(local_e8._4_4_,uVar3);
            local_f8 = fVar4;
            local_f0 = uVar9;
            FUN_14012e070(0x2c,0);
          }
        }
        if (0x13 < (int)DAT_140e45fac) {
          transition_tile_wipe_out_candidate(DAT_140e45fac - 0x14);
        }
        if (DAT_140e45fac == 0x32) {
          if (DAT_140e45274 == 3) {
            DAT_140e45274 = 4;
            DAT_140e45270 = 10;
          }
          DAT_140e418c8 = 0;
          DAT_140e45fac = 0;
          DAT_140e46014 = 0;
          fopen_s(&local_a8,"save\\save.dat","wb");
          FUN_140327c78(&DAT_140e41b10,0x2730,1,local_a8);
          FUN_140323e90(local_a8);
          DAT_140e471fc = 0xb4;
        }
        if ((int)DAT_140e45fac < -0x13) {
          transition_tile_wipe_out_candidate(-0x14 - DAT_140e45fac);
        }
        if (DAT_140e45fac == 0xffffffce) {
          DAT_140e45270 = 10;
          DAT_140e45274 = 4;
          DAT_140e418c8 = 0;
          DAT_140e45fac = 0;
          DAT_140e46014 = 0;
          fopen_s(&local_a8,"save\\save.dat","wb");
          FUN_140327c78(&DAT_140e41b10,0x2730,1,local_a8);
          FUN_140323e90(local_a8);
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
    }
  } while( true );
}


