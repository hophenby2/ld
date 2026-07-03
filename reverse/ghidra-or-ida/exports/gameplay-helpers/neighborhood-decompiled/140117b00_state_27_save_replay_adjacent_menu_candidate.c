// Function: state_27_save_replay_adjacent_menu_candidate @ 140117b00
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_27_save_replay_adjacent_menu_candidate(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  bool bVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  longlong lVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  undefined4 uVar20;
  int local_res8;
  
  dVar6 = DAT_14053a020;
  dVar4 = DAT_140539f40;
  dVar18 = DAT_140539d28;
  iVar15 = 0xff;
  if (DAT_140e46a20 < 0x1e) {
    dVar17 = (double)FUN_140332d90(((double)DAT_140e46a20 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                   DAT_140539d28);
    iVar15 = (int)(dVar17 * DAT_14053a5f8);
  }
  FUN_140106880(iVar15);
  iVar14 = 0;
  bVar16 = false;
  if (DAT_140e8cf10 == 1) {
LAB_140117bcd:
    bVar5 = true;
  }
  else {
    bVar5 = bVar16;
    if (0x13 < DAT_140e8cf10) {
      uVar11 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
      }
      if (uVar11 == 0) goto LAB_140117bcd;
    }
  }
  if (((DAT_140e8cf14 < 1) && (bVar5)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 1;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 != 1) {
    if (DAT_140e8cf14 < 0x14) goto LAB_140117c6d;
    uVar11 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar11 < 0) {
      uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
    }
    if (uVar11 != 0) goto LAB_140117c6d;
  }
  bVar16 = true;
LAB_140117c6d:
  if (((DAT_140e8cf10 < 1) && (bVar16)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (1 < DAT_140e45274) {
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
  iVar10 = DAT_140e46014;
  uVar11 = DAT_140e45fac;
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
    dVar18 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar6 * dVar18);
    DAT_140e46014 = iVar10 + -1;
    dVar4 = dVar4 + dVar18 * DAT_140539e60;
  }
  uVar9 = DAT_140e4786c;
  uVar20 = (undefined4)((ulonglong)dVar4 >> 0x20);
  if (0 < (int)uVar11) {
    DAT_140e45fac = uVar11 + 1;
  }
  puVar12 = (undefined4 *)_malloc_base(0x48);
  if (puVar12 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e78 = _DAT_140e46e78 + 1;
  bVar16 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar12 = uVar9;
  puVar12[1] = 0x7a;
  puVar12[2] = 1;
  puVar12[3] = 0x44200000;
  puVar12[4] = 0x43480000;
  *(undefined2 *)(puVar12 + 5) = 0;
  *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
  puVar12[10] = 0xff;
  puVar12[0xb] = 0xff;
  puVar12[0xc] = 0xff;
  puVar12[0xd] = iVar15;
  *(undefined8 *)(puVar12 + 0xe) = 1;
  *(undefined8 *)(puVar12 + 0x10) = 0;
  if (bVar16) {
    DAT_140e46bf0 = puVar12;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar12;
  }
  uVar9 = DAT_14053aedc;
  fVar8 = DAT_14053ae14;
  fVar7 = DAT_14053ad10;
  lVar13 = (longlong)local_res8;
  DAT_140e46c88 = puVar12;
  do {
    fVar19 = (float)iVar14 * fVar7 + fVar8;
    if (iVar14 == 0) {
      lVar13 = 0xd;
    }
    else if (iVar14 == 1) {
      lVar13 = 6;
    }
    uVar1 = *(undefined4 *)(&DAT_140e47840 + lVar13 * 4);
    if (DAT_140e45274 == iVar14) {
      puVar12 = (undefined4 *)_malloc_base(0x48);
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar12[4] = fVar19;
      *puVar12 = uVar1;
      puVar12[1] = 0x7a;
      puVar12[2] = 1;
      puVar12[3] = 0x44200000;
      *(undefined2 *)(puVar12 + 5) = 0;
      auVar2._8_4_ = SUB84(dVar4,0);
      auVar2._0_8_ = dVar4;
      auVar2._12_4_ = uVar20;
      *(undefined1 (*) [16])(puVar12 + 6) = auVar2;
      puVar12[10] = 0xff;
      puVar12[0xb] = 0xff;
      puVar12[0xc] = 0xff;
      puVar12[0xd] = iVar15;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
      if (DAT_140e45fac != 0) {
        uVar11 = DAT_140e45fac & 0x80000003;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
        }
        if ((int)uVar11 < 2) {
          auVar3._8_4_ = SUB84(dVar4,0);
          auVar3._0_8_ = dVar4;
          auVar3._12_4_ = uVar20;
          DAT_140e46c88 = puVar12;
          FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + lVar13 * 4),0x7a,6,uVar9,fVar19,0,auVar3,
                        0xff,0xff,0xff,iVar15,1,0);
          puVar12 = DAT_140e46c88;
        }
      }
    }
    else {
      puVar12 = (undefined4 *)_malloc_base();
      if (puVar12 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar12[4] = fVar19;
      *puVar12 = uVar1;
      puVar12[1] = 0x7a;
      puVar12[2] = 1;
      puVar12[3] = 0x44200000;
      *(undefined2 *)(puVar12 + 5) = 0;
      *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar12 + 8) = 0x3ff0000000000000;
      puVar12[10] = 0x80;
      puVar12[0xb] = 0x80;
      puVar12[0xc] = 0x80;
      puVar12[0xd] = iVar15;
      *(undefined8 *)(puVar12 + 0xe) = 1;
      *(undefined8 *)(puVar12 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar12;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
      }
    }
    DAT_140e46c88 = puVar12;
    iVar14 = iVar14 + 1;
  } while (iVar14 < 2);
  FUN_1400d9b60(0,0x70,0xff);
  if (0 < (int)DAT_140e45fac) {
    if (DAT_140e45274 == 0) {
      if (0x13 < (int)DAT_140e45fac) {
        FUN_1400d3fd0(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        FUN_1400f7150();
        FUN_140118290(DAT_140e9fd24 + -1);
      }
    }
    if (DAT_140e45274 == 1) {
      if (0x13 < (int)DAT_140e45fac) {
        FUN_1400d3fd0(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        FUN_1400f6fb0();
        replay_handler_candidate_B();
        puVar12 = &DAT_140e45100;
        do {
          FUN_14018f230(*puVar12,0);
          puVar12 = puVar12 + 1;
        } while ((longlong)puVar12 < 0x140e45178);
        FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45108);
        FUN_14018a340(DAT_140e45108,3,1);
        DAT_140e45270 = 0xe;
      }
    }
  }
  return;
}


