// Function: state_26_save_replay_adjacent_menu_candidate @ 1401172c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_26_save_replay_adjacent_menu_candidate(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  longlong lVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  undefined4 uVar21;
  int local_res8;
  
  dVar18 = DAT_14053a798;
  dVar5 = DAT_14053a5f8;
  dVar19 = DAT_14053a020;
  dVar4 = DAT_140539f40;
  iVar14 = 0xff;
  if (DAT_140e46a20 < 0x1e) {
    dVar17 = (double)FUN_140332d90(((double)DAT_140e46a20 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                   DAT_140539d28);
    iVar14 = (int)(dVar17 * dVar5);
  }
  uVar9 = DAT_140e45fac;
  iVar13 = 0;
  iVar15 = 0;
  if (DAT_140e45274 == 0) {
    if ((int)DAT_140e45fac < 1) {
LAB_1401173a9:
      if ((int)uVar9 < 0x1e) goto LAB_1401173b1;
    }
    else if ((int)DAT_140e45fac < 0x1e) {
      dVar18 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * dVar18 * dVar19 *
                                     DAT_140539d28);
      iVar14 = 0xff - (int)(dVar18 * dVar5);
      goto LAB_1401173a9;
    }
    iVar14 = iVar15;
  }
LAB_1401173b1:
  FUN_140106880(iVar14);
  if (DAT_140e8cf10 == 1) {
LAB_1401173e7:
    iVar11 = 1;
  }
  else {
    iVar11 = iVar15;
    if (0x13 < DAT_140e8cf10) {
      uVar9 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_1401173e7;
    }
  }
  if (((DAT_140e8cf14 < 1) && (iVar11 == 1)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 3;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 != 1) {
    if (DAT_140e8cf14 < 0x14) goto LAB_14011748a;
    uVar9 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    if (uVar9 != 0) goto LAB_14011748a;
  }
  iVar15 = 1;
LAB_14011748a:
  if (((DAT_140e8cf10 < 1) && (iVar15 == 1)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (3 < DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (((DAT_140e467c8 == 1) || (DAT_140e467e0 == 1)) &&
     ((DAT_140e467fc == 0 && (DAT_140e45fac == 0)))) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
  }
  iVar15 = DAT_140e46014;
  uVar9 = DAT_140e45fac;
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
  if (0 < DAT_140e46014) {
    dVar19 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar19 *
                                   DAT_140539d28);
    DAT_140e46014 = iVar15 + -1;
    dVar4 = dVar4 + dVar19 * DAT_140539e60;
  }
  uVar8 = DAT_140e47868;
  uVar21 = (undefined4)((ulonglong)dVar4 >> 0x20);
  if (0 < (int)uVar9) {
    DAT_140e45fac = uVar9 + 1;
  }
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e78 = _DAT_140e46e78 + 1;
  bVar16 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar8;
  puVar10[1] = 0x7a;
  puVar10[2] = 1;
  puVar10[3] = 0x44200000;
  puVar10[4] = 0x42c80000;
  *(undefined2 *)(puVar10 + 5) = 0;
  *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
  puVar10[10] = 0xff;
  puVar10[0xb] = 0xff;
  puVar10[0xc] = 0xff;
  puVar10[0xd] = iVar14;
  *(undefined8 *)(puVar10 + 0xe) = 1;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  if (bVar16) {
    DAT_140e46bf0 = puVar10;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar10;
  }
  uVar8 = DAT_14053aedc;
  fVar7 = DAT_14053adb4;
  fVar6 = DAT_14053ad10;
  lVar12 = (longlong)local_res8;
  DAT_140e46c88 = puVar10;
  do {
    fVar20 = (float)iVar13 * fVar6 + fVar7;
    if (iVar13 == 0) {
      lVar12 = 0xc;
    }
    else if (iVar13 == 1) {
      lVar12 = 0xd;
    }
    else if (iVar13 == 2) {
      lVar12 = 5;
    }
    else if (iVar13 == 3) {
      lVar12 = 6;
    }
    uVar1 = *(undefined4 *)(&DAT_140e47840 + lVar12 * 4);
    if (DAT_140e45274 == iVar13) {
      puVar10 = (undefined4 *)_malloc_base(0x48);
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar10[4] = fVar20;
      *puVar10 = uVar1;
      puVar10[1] = 0x7a;
      puVar10[2] = 1;
      puVar10[3] = 0x44200000;
      *(undefined2 *)(puVar10 + 5) = 0;
      auVar2._8_4_ = SUB84(dVar4,0);
      auVar2._0_8_ = dVar4;
      auVar2._12_4_ = uVar21;
      *(undefined1 (*) [16])(puVar10 + 6) = auVar2;
      puVar10[10] = 0xff;
      puVar10[0xb] = 0xff;
      puVar10[0xc] = 0xff;
      puVar10[0xd] = iVar14;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar10;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
      if (DAT_140e45fac != 0) {
        uVar9 = DAT_140e45fac & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if ((int)uVar9 < 2) {
          auVar3._8_4_ = SUB84(dVar4,0);
          auVar3._0_8_ = dVar4;
          auVar3._12_4_ = uVar21;
          DAT_140e46c88 = puVar10;
          FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + lVar12 * 4),0x7a,6,uVar8,fVar20,0,auVar3,
                        0xff,0xff,0xff,iVar14,1,0);
          puVar10 = DAT_140e46c88;
        }
      }
    }
    else {
      puVar10 = (undefined4 *)_malloc_base();
      if (puVar10 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar10[4] = fVar20;
      *puVar10 = uVar1;
      puVar10[1] = 0x7a;
      puVar10[2] = 1;
      puVar10[3] = 0x44200000;
      *(undefined2 *)(puVar10 + 5) = 0;
      *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
      puVar10[10] = 0x80;
      puVar10[0xb] = 0x80;
      puVar10[0xc] = 0x80;
      puVar10[0xd] = iVar14;
      *(undefined8 *)(puVar10 + 0xe) = 1;
      *(undefined8 *)(puVar10 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar10;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
      }
    }
    DAT_140e46c88 = puVar10;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 4);
  FUN_1400d9b60(0,0x70,0xff);
  fVar6 = DAT_14053ac64;
  if (0 < (int)DAT_140e45fac) {
    if (DAT_140e45274 == 0) {
      if (DAT_140e45fac != 0x14) {
        return;
      }
      DAT_140e46a20 = 0;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
      FUN_14018a340(DAT_140e45100,3,0);
      DAT_140e467fc = 0;
      DAT_140e45270 = 0x14;
    }
    if (DAT_140e45274 == 1) {
      if (0x13 < (int)DAT_140e45fac) {
        transition_tile_wipe_out_candidate(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        gameplay_context_init_candidate();
        FUN_140118290(DAT_140e9fd24 + -1);
      }
    }
    if (DAT_140e45274 == 2) {
      if (DAT_140e45fac == 0x1e) {
        DAT_140e45270 = 0x18;
        DAT_140e45274 = 0;
        DAT_140e45fac = 0;
      }
    }
    else if (DAT_140e45274 == 3) {
      if (0x13 < (int)DAT_140e45fac) {
        transition_tile_wipe_out_candidate(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        FUN_1400f6fb0();
        replay_handler_candidate_B();
        puVar10 = &DAT_140e45100;
        do {
          FUN_14018f230(*puVar10,0);
          puVar10 = puVar10 + 1;
        } while ((longlong)puVar10 < 0x140e45178);
        FUN_140184700((int)((float)DAT_140e4418c * fVar6 * _DAT_1407c777c),DAT_140e45108);
        FUN_14018a340(DAT_140e45108,3,1);
        DAT_140e45270 = 0xe;
      }
    }
  }
  return;
}


