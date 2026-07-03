// Function: main_state_dispatcher_candidate @ 1400f5ef0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main_state_dispatcher_candidate(void)

{
  double dVar1;
  undefined4 uVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  errno_t eVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  int *piVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined4 *puVar17;
  longlong lVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  undefined4 uVar22;
  undefined1 auStack_108 [32];
  undefined1 *local_e8;
  undefined4 local_e0;
  undefined1 local_d8 [16];
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  int local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  int local_98;
  undefined4 uStack_94;
  undefined1 local_90 [32];
  ulonglong local_70;
  
  local_70 = DAT_1407c6b00 ^ (ulonglong)auStack_108;
  uVar12 = 0;
  local_98 = 0;
  if (DAT_140e468f4 == 0) {
LAB_1400f5fa5:
    if ((DAT_140e474e8 == 0) || (local_98 = 1, DAT_140e474e8 == 5)) {
      FUN_14013a330(0);
      uVar2 = DAT_140e41ab8;
      local_98 = 1;
      if (DAT_140e46a20 == 0) {
        puVar9 = (undefined4 *)_malloc_base(0x48);
        if (puVar9 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e46c90 = DAT_140e46c90 + 1;
        bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar9 = uVar2;
        *(undefined8 *)(puVar9 + 1) = 0;
        *(undefined8 *)(puVar9 + 3) = 0;
        *(undefined2 *)(puVar9 + 5) = 0;
        *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar9 + 10) = 0;
        puVar9[0xc] = 0;
        *(undefined8 *)(puVar9 + 0xd) = 0xff;
        puVar9[0xf] = 0;
        *(undefined8 *)(puVar9 + 0x10) = 0;
        if (bVar19) {
          DAT_140e46bf0 = puVar9;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
        }
        local_98 = 1;
        DAT_140e46c88 = puVar9;
      }
    }
  }
  else {
    if (DAT_140e468f4 == 1) {
      uVar5 = DAT_140e451bc & 0x80000001;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
      }
      bVar19 = uVar5 == 0;
LAB_1400f5f9a:
      if (bVar19) goto LAB_1400f5fa5;
    }
    else if (DAT_140e468f4 == 2) {
      bVar19 = DAT_140e451bc ==
               ((int)DAT_140e451bc / 3 + ((int)DAT_140e451bc >> 0x1f) +
               (int)((ulonglong)
                     ((longlong)(int)DAT_140e451bc / 3 + ((longlong)(int)DAT_140e451bc >> 0x3f)) >>
                    0x1f)) * 3;
      goto LAB_1400f5f9a;
    }
    if (0 < DAT_140e474e8) goto LAB_1400f5fa5;
  }
  uVar5 = FUN_14019d970(1);
  uVar13 = uVar12;
  uVar15 = uVar12;
  uVar16 = uVar12;
  do {
    *(undefined4 *)((longlong)&DAT_140e467b8 + uVar13) = 0;
    if (((*(uint *)((longlong)&DAT_140e44200 + uVar13) & uVar5) != 0) ||
       (iVar6 = FUN_14019d900(*(undefined4 *)((longlong)&DAT_140e441d0 + uVar13)), iVar6 != 0)) {
      *(undefined4 *)((longlong)&DAT_140e467b8 + uVar13) = 1;
      iVar6 = FUN_14019d900(*(undefined4 *)((longlong)&DAT_140e441d0 + uVar13));
      if (iVar6 != 0) {
        uVar16 = 1;
      }
      if ((*(uint *)((longlong)&DAT_140e44200 + uVar13) & uVar5) != 0) {
        uVar15 = 1;
      }
    }
    iVar6 = local_98;
    if (*(int *)((longlong)&DAT_140e467b8 + uVar13) == 1) {
      *(int *)((longlong)&DAT_140e8cf10 + uVar13) = *(int *)((longlong)&DAT_140e8cf10 + uVar13) + 1;
    }
    else {
      *(undefined4 *)((longlong)&DAT_140e8cf10 + uVar13) = 0;
    }
    uVar13 = uVar13 + 4;
  } while ((longlong)uVar13 < 0x30);
  if ((int)uVar16 == 1) {
    DAT_140e441cc = 5;
  }
  lVar18 = 4;
  if ((int)uVar15 == 1) {
    iVar7 = FUN_14019dbb0(1);
    if ((iVar7 == 1) || (iVar7 = FUN_14019dbb0(1), iVar7 == 2)) {
      DAT_140e441cc = 2;
    }
    else {
      iVar7 = FUN_14019dbb0(1);
      if ((iVar7 == 4) || (iVar7 = FUN_14019dbb0(1), iVar7 == 5)) {
        DAT_140e441cc = 4;
      }
      else {
        iVar7 = FUN_14019dbb0(1);
        DAT_140e441cc = 0;
        if (iVar7 == 8) {
          DAT_140e441cc = 3;
        }
      }
    }
    puVar10 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc760);
    cVar4 = (**(code **)(*(longlong *)*puVar10 + 0x110))();
    if (cVar4 == '\x01') {
      DAT_140e441cc = 1;
    }
  }
  uVar2 = DAT_140e47088;
  dVar1 = DAT_14053a020;
  dVar21 = DAT_140539d28;
  switch(DAT_140e45270) {
  case 0:
    state_00_pre_title_init_candidate();
    break;
  case 1:
    state_01_opening_attract_candidate();
    break;
  case 2:
    state_02_title_main_menu_candidate();
    break;
  case 3:
    state_03_stage_start_init_candidate();
    break;
  case 4:
    state_04_gameplay_update_candidate();
    break;
  case 5:
    state_05_gameplay_boss_or_result_candidate();
    break;
  case 6:
    state_06_gallery_list_candidate();
    break;
  case 7:
    state_07_gallery_detail_candidate();
    break;
  case 8:
    state_08_gallery_unlock_or_achievement_candidate();
    break;
  case 9:
    state_09_menu_branch_candidate();
    break;
  case 10:
    state_0a_options_menu_candidate();
    break;
  case 0xb:
    state_0b_options_submenu_a_candidate();
    break;
  case 0xc:
  case 0x19:
    state_0c_config_menu_candidate();
    break;
  case 0xd:
  case 0x1a:
    state_0d_key_config_menu_candidate();
    break;
  case 0xe:
    state_0e_replay_list_menu_candidate();
    break;
  case 0xf:
    state_0f_replay_load_select_candidate();
    break;
  case 0x10:
  case 0x23:
    state_10_23_result_continue_candidate();
    break;
  case 0x11:
    state_11_menu_branch_part1_candidate();
    state_11_13_menu_branch_shared_candidate();
    break;
  case 0x12:
    iVar7 = 0;
    puVar9 = (undefined4 *)_malloc_base(0x48);
    if (puVar9 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e24 = _DAT_140e46e24 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar9 = uVar2;
    puVar9[1] = 0x65;
    puVar9[2] = 1;
    puVar9[3] = 0x44200000;
    puVar9[4] = 0x43b40000;
    *(undefined2 *)(puVar9 + 5) = 0;
    *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
    puVar9[10] = 0xff;
    puVar9[0xb] = 0xff;
    puVar9[0xc] = 0xff;
    puVar9[0xd] = 0xff;
    *(undefined8 *)(puVar9 + 0xe) = 1;
    *(undefined8 *)(puVar9 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar9;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar9;
    }
    DAT_140e46c88 = puVar9;
    if (DAT_140e418c8 == 0x3c) {
      iVar7 = FUN_14012db60();
    }
    if ((DAT_140e418c8 < 0x46) || (DAT_140e45fac != 0)) {
LAB_1400f65b8:
      if ((int)DAT_140e45fac < -9) {
        FUN_1400d3fd0(-10 - DAT_140e45fac);
      }
      uVar5 = DAT_140e45fac;
      if (DAT_140e45fac == 0xffffffce) {
        DAT_140e45270 = 2;
        DAT_140e45274 = 3;
        DAT_140e418c8 = 0;
        DAT_140e45d74 = 0;
        DAT_140e45fac = 0;
        DAT_140e46014 = 0;
        lVar11 = DAT_140e47908;
        if (DAT_140e47908 != 0) {
          do {
            lVar11 = *(longlong *)(lVar11 + 0x238);
            FUN_140323ce8();
          } while (lVar11 != 0);
          uVar12 = (ulonglong)DAT_140e45fac;
        }
        uVar5 = (uint)uVar12;
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
      }
      if (0 < (int)uVar5) {
        DAT_140e45fac = uVar5 + 1;
        uVar5 = DAT_140e45fac;
      }
      if (0x7fffffff < uVar5) goto LAB_1400f664c;
    }
    else {
      if (iVar7 == 0) {
        DAT_140e45270 = 0x13;
        lVar11 = DAT_140e47908;
        while (lVar11 != 0) {
          lVar11 = *(longlong *)(lVar11 + 0x238);
          FUN_140323ce8();
        }
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
        goto LAB_1400f65b8;
      }
      MessageBoxA((HWND)0x0,"Failed to load the Steam leaderboard.","errer",0);
      uVar5 = 0xffffffff;
LAB_1400f664c:
      DAT_140e45fac = uVar5 - 1;
    }
    DAT_140e418c8 = DAT_140e418c8 + 1;
    state_11_13_menu_branch_shared_candidate();
    break;
  case 0x13:
    state_13_menu_branch_part1_candidate();
    state_11_13_menu_branch_shared_candidate();
    break;
  case 0x14:
  case 0x15:
  case 0x2a:
    state_14_replay_demo_gameplay_update_candidate();
    break;
  case 0x16:
  case 0x17:
    state_16_17_save_select_candidate();
    break;
  case 0x18:
    state_18_save_select_candidate();
    break;
  case 0x1b:
  case 0x1c:
  case 0x1d:
    state_1b_stage_result_transition_panel_candidate();
    break;
  case 0x1e:
    state_14_replay_demo_gameplay_update_candidate();
    dVar20 = (double)FUN_140332d90(((double)DAT_140e468bc - 0.0) * DAT_14053a438 * dVar1 * dVar21);
    _DAT_1407c777c = (float)(dVar20 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    if (((DAT_140e41928 == 2) && (DAT_140e41b00 == 0)) && (0x77 < DAT_140e468bc)) {
      FUN_1400d3fd0(DAT_140e468bc + -0x78);
    }
    if (DAT_140e468bc == 0xb4) {
      puVar9 = &DAT_140e45100;
      puVar17 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar17,0);
        puVar17 = puVar17 + 1;
      } while ((longlong)puVar17 < 0x140e45178);
      _DAT_1407c777c = 1.0;
      if (DAT_140e41b00 == 0) {
        if (DAT_140e41928 == 2) {
          do {
            FUN_14018f230(*puVar9,0);
            puVar9 = puVar9 + 1;
          } while ((longlong)puVar9 < 0x140e45178);
          FUN_1400f6fb0();
          DAT_140e468bc = DAT_140e468bc + 1;
          DAT_140e45270 = 0x23;
        }
        else {
          FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e45110);
          FUN_14018a340(DAT_140e45110,1,1);
          DAT_140e468bc = DAT_140e468bc + 1;
          DAT_140e45270 = 0x1f;
          DAT_140e418c8 = 0;
        }
        break;
      }
      FUN_140118220();
    }
    DAT_140e468bc = DAT_140e468bc + 1;
    break;
  case 0x1f:
    state_1f_gameplay_result_branch_candidate();
    break;
  case 0x20:
    state_20_gameplay_result_branch_candidate();
    break;
  case 0x22:
    state_22_gameplay_result_branch_candidate();
    break;
  case 0x24:
    state_24_result_continue_submenu_candidate();
    break;
  case 0x25:
    state_25_replay_save_name_entry_candidate();
    break;
  case 0x26:
    state_26_save_replay_adjacent_menu_candidate();
    break;
  case 0x27:
    state_27_save_replay_adjacent_menu_candidate();
    break;
  case 0x28:
  case 0x29:
    state_28_29_ending_result_candidate();
    break;
  case 0x2c:
    state_2c_auto_gameplay_branch_candidate();
    break;
  case 0x2d:
  case 0x2e:
    state_2d_2e_system_menu_branch_candidate();
    break;
  case 0x2f:
    state_2f_system_menu_branch_candidate();
    break;
  case 0x30:
    state_30_gameplay_clear_fail_transition_candidate();
  }
  if (((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e4745c == 0)) {
    FUN_1400b7210();
  }
  FUN_1400b43f0();
  piVar3 = DAT_140e46878;
  if (DAT_140e46068 != (int *)0x0) {
    iVar7 = *DAT_140e46068;
    piVar3 = DAT_140e46068;
    while (iVar7 == 0) {
      DAT_140e46068 = *(int **)(piVar3 + 4);
      FUN_140323ce8(piVar3);
      DAT_140e467ec = DAT_140e467ec + -1;
      if (DAT_140e46068 == (int *)0x0) {
        DAT_140e46878 = (int *)0x0;
        piVar3 = DAT_140e46878;
        goto LAB_1400f6757;
      }
      piVar3 = DAT_140e46068;
      iVar7 = *DAT_140e46068;
    }
    lVar11 = *(longlong *)(piVar3 + 4);
    DAT_140e46068 = piVar3;
    while (lVar11 != 0) {
      piVar14 = *(int **)(piVar3 + 4);
      if (*piVar14 == 0) {
        *(undefined8 *)(piVar3 + 4) = *(undefined8 *)(piVar14 + 4);
        FUN_140323ce8();
        DAT_140e467ec = DAT_140e467ec + -1;
        piVar14 = piVar3;
      }
      piVar3 = piVar14;
      lVar11 = *(longlong *)(piVar14 + 4);
    }
  }
LAB_1400f6757:
  DAT_140e46878 = piVar3;
  if (DAT_140e471fc < 1) goto LAB_1400f68de;
  iVar7 = 0xb4 - DAT_140e471fc;
  if (iVar7 < 0) {
LAB_1400f67d4:
    dVar20 = 0.0;
  }
  else {
    if (iVar7 < 0x14) {
      dVar20 = (double)iVar7 - 0.0;
    }
    else {
      dVar20 = DAT_140539f40;
      if (iVar7 < 0xa0) goto LAB_1400f67d8;
      if (0xb3 < iVar7) goto LAB_1400f67d4;
      dVar20 = (double)iVar7 - DAT_14053a4f0;
    }
    dVar20 = (double)FUN_140332d90(dVar20 * DAT_14053a890 * dVar1 * dVar21);
    dVar20 = dVar20 + 0.0;
  }
LAB_1400f67d8:
  uVar5 = DAT_140e451bc;
  uVar22 = (undefined4)((ulonglong)dVar20 >> 0x20);
  dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e451bc - 0.0) * DAT_14053a798 * dVar1 * dVar21
                                );
  uVar2 = DAT_14053aef4;
  local_a0 = 0;
  local_a8 = 1;
  iVar7 = 0xc0 - (int)(dVar21 * DAT_14053b160);
  local_b8 = 0xff;
  local_c0 = 0xff;
  local_e0._0_2_ = (short)uVar5 * 0x29a;
  local_c8 = 0xff;
  local_d8._8_4_ = SUB84(dVar20,0);
  local_d8._0_8_ = dVar20;
  local_d8._12_4_ = uVar22;
  local_e8._0_4_ = DAT_14053aef4;
  local_b0 = iVar7;
  FUN_1400c8410(DAT_140e41940,0x7f,1,DAT_14053aff8);
  local_a0 = 0;
  local_a8 = 1;
  local_b8 = 0xff;
  local_c0 = 0xff;
  local_c8 = 0xff;
  local_e0 = (uint)local_e0._2_2_ << 0x10;
  local_e8 = (undefined1 *)CONCAT44(local_e8._4_4_,uVar2);
  local_b0 = iVar7;
  FUN_1400c8410(DAT_140e4193c,0x7f,1,DAT_14053aff8);
  DAT_140e471fc = DAT_140e471fc + -1;
LAB_1400f68de:
  if (((iVar6 == 1) && ((DAT_140e474e8 == 0 || (DAT_140e474e8 == 5)))) || (DAT_140e46a20 != 0)) {
    FUN_14013db30(0,0,DAT_140e470cc,0);
    FUN_1400c8530(DAT_140e46bf0,&DAT_140e46c90);
    if (DAT_140e46a20 == 1) {
      local_e0 = 1;
      local_e8 = (undefined1 *)CONCAT44(local_e8._4_4_,DAT_140e470cc);
      FUN_140142960(0,0,0x500,0x2d0);
    }
  }
  puVar9 = DAT_140e46bf0;
  if (0 < DAT_140e46a20) {
    DAT_140e46a20 = DAT_140e46a20 + 1;
  }
  while (puVar9 != (undefined4 *)0x0) {
    puVar9 = *(undefined4 **)(puVar9 + 0x10);
    FUN_140323ce8();
  }
  DAT_140e46bf0 = (undefined4 *)0x0;
  DAT_140e46c88 = (undefined4 *)0x0;
  puVar10 = (undefined8 *)&DAT_140e46c90;
  do {
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    puVar10[3] = 0;
    puVar10[4] = 0;
    puVar10[5] = 0;
    puVar10[6] = 0;
    puVar10[7] = 0;
    puVar10[8] = 0;
    puVar10[9] = 0;
    puVar10[10] = 0;
    puVar10[0xb] = 0;
    puVar10[0xc] = 0;
    puVar10[0xd] = 0;
    puVar10[0xe] = 0;
    puVar10[0xf] = 0;
    lVar18 = lVar18 + -1;
    puVar10 = puVar10 + 0x10;
  } while (lVar18 != 0);
  if (DAT_140e9fd08 == 1) {
    iVar6 = FUN_14019d900(2);
    if ((iVar6 == 1) && (DAT_140e47904 == 0)) {
      eVar8 = fopen_s((FILE **)&local_98,"snap\\ss.dat","rb");
      if (eVar8 == 0) {
        FUN_1400f5e70(CONCAT44(uStack_94,local_98),&DAT_140536fb0,&DAT_140e477ec);
      }
      else {
        fopen_s((FILE **)&local_98,"snap\\ss.dat","wb");
        FUN_140070c50(CONCAT44(uStack_94,local_98),&DAT_14053940c);
      }
      FUN_140323e90(CONCAT44(uStack_94,local_98));
      FUN_140070ca0(local_90,0x20,"snap\\SS%d.png",DAT_140e477ec);
      DAT_140e477ec = DAT_140e477ec + 1;
      local_e8 = local_90;
      local_e0 = 0;
      FUN_140156090(0,0,0x500,0x2d0);
      DAT_140e47904 = 1;
      fopen_s((FILE **)&local_98,"snap\\ss.dat","wb");
      if (CONCAT44(uStack_94,local_98) == 0) {
        MessageBoxA((HWND)0x0,"Cannot find snap folder.","errer",0);
      }
      else {
        FUN_140070c50(CONCAT44(uStack_94,local_98),&DAT_140536fb0,DAT_140e477ec);
        FUN_140323e90(CONCAT44(uStack_94,local_98));
      }
    }
    iVar6 = FUN_14019d900(2);
    DAT_140e451bc = DAT_140e451bc + 1;
    if (iVar6 == 0) {
      DAT_140e47904 = 0;
    }
  }
  else {
    DAT_140e451bc = DAT_140e451bc + 1;
  }
  return;
}


