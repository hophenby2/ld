// Function: state_16_17_save_select_candidate @ 140104200
// Decompile completed: true

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_16_17_save_select_candidate(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  double dVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  longlong lVar16;
  int iVar17;
  int iVar18;
  longlong lVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  
  dVar22 = DAT_14053a798;
  dVar23 = DAT_14053a5f8;
  dVar8 = DAT_14053a020;
  dVar7 = DAT_140539f40;
  dVar24 = DAT_140539d28;
  iVar18 = 0xff;
  if (DAT_140e46a20 < 0x1e) {
    dVar21 = (double)FUN_140332d90(((double)DAT_140e46a20 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                   DAT_140539d28);
    iVar18 = (int)(dVar21 * dVar23);
  }
  uVar12 = DAT_140e45fac;
  iVar15 = 0;
  iVar17 = 0;
  if (DAT_140e45274 == 0) {
    if ((int)DAT_140e45fac < 1) {
LAB_14010430e:
      if ((int)uVar12 < 0x1e) goto LAB_140104316;
    }
    else if ((int)DAT_140e45fac < 0x1e) {
      dVar22 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * dVar22 * dVar8 * dVar24);
      iVar18 = 0xff - (int)(dVar22 * dVar23);
      goto LAB_14010430e;
    }
    iVar18 = iVar17;
  }
LAB_140104316:
  FUN_140106880(iVar18);
  if (DAT_140e8cf10 == 1) {
LAB_14010434c:
    iVar14 = 1;
  }
  else {
    iVar14 = iVar17;
    if (0x13 < DAT_140e8cf10) {
      uVar12 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar12 < 0) {
        uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;
      }
      if (uVar12 == 0) goto LAB_14010434c;
    }
  }
  if (((DAT_140e8cf14 < 1) && (iVar14 == 1)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 3;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 == 1) {
LAB_1401043e4:
    iVar17 = 1;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar12 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;
    }
    if (uVar12 == 0) goto LAB_1401043e4;
  }
  if (((DAT_140e8cf10 < 1) && (iVar17 == 1)) && (DAT_140e45fac == 0)) {
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
  iVar17 = DAT_140e46014;
  uVar12 = DAT_140e45fac;
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
  dVar23 = dVar7;
  if (0 < DAT_140e46014) {
    dVar23 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar8 * dVar24);
    DAT_140e46014 = iVar17 + -1;
    dVar23 = dVar23 * DAT_140539e60 + dVar7;
  }
  uVar26 = (undefined4)((ulonglong)dVar23 >> 0x20);
  if (0 < (int)uVar12) {
    DAT_140e45fac = uVar12 + 1;
  }
  uVar1 = *(undefined4 *)(&DAT_140e47840 + (longlong)DAT_140e445c0 * 4);
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e78 = _DAT_140e46e78 + 1;
  bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar13 = uVar1;
  puVar13[1] = 0x7a;
  puVar13[2] = 1;
  puVar13[3] = 0x44200000;
  puVar13[4] = 0x42c80000;
  *(undefined2 *)(puVar13 + 5) = 0;
  *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = iVar18;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  if (bVar20) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar13;
  }
  uVar1 = DAT_14053aedc;
  fVar10 = DAT_14053adb4;
  fVar9 = DAT_14053ad10;
  lVar19 = 3;
  DAT_140e46c88 = puVar13;
  do {
    fVar25 = (float)iVar15 * fVar9 + fVar10;
    lVar16 = lVar19;
    if ((DAT_140e45270 == 0x16) && (iVar15 == 1)) {
      lVar16 = 0xe;
    }
    uVar27 = *(undefined4 *)(&DAT_140e47840 + lVar16 * 4);
    if (DAT_140e45274 == iVar15) {
      puVar13 = (undefined4 *)_malloc_base(0x48);
      if (puVar13 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar13[4] = fVar25;
      *puVar13 = uVar27;
      puVar13[1] = 0x7a;
      puVar13[2] = 1;
      puVar13[3] = 0x44200000;
      *(undefined2 *)(puVar13 + 5) = 0;
      auVar2._8_4_ = SUB84(dVar23,0);
      auVar2._0_8_ = dVar23;
      auVar2._12_4_ = uVar26;
      *(undefined1 (*) [16])(puVar13 + 6) = auVar2;
      puVar13[10] = 0xff;
      puVar13[0xb] = 0xff;
      puVar13[0xc] = 0xff;
      puVar13[0xd] = iVar18;
      *(undefined8 *)(puVar13 + 0xe) = 1;
      *(undefined8 *)(puVar13 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar13;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
      }
      if (DAT_140e45fac != 0) {
        uVar12 = DAT_140e45fac & 0x80000003;
        if ((int)uVar12 < 0) {
          uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
        }
        if ((int)uVar12 < 2) {
          auVar3._8_4_ = SUB84(dVar23,0);
          auVar3._0_8_ = dVar23;
          auVar3._12_4_ = uVar26;
          DAT_140e46c88 = puVar13;
          FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + lVar16 * 4),0x7a,6,uVar1,fVar25,0,auVar3,
                        0xff,0xff,0xff,iVar18,1,0);
          puVar13 = DAT_140e46c88;
        }
      }
    }
    else {
      puVar13 = (undefined4 *)_malloc_base();
      if (puVar13 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar13 = uVar27;
      *(undefined8 *)(puVar13 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
      puVar13[4] = fVar25;
      puVar13[1] = 0x7a;
      puVar13[2] = 1;
      puVar13[3] = 0x44200000;
      *(undefined2 *)(puVar13 + 5) = 0;
      puVar13[10] = 0x80;
      puVar13[0xb] = 0x80;
      puVar13[0xc] = 0x80;
      puVar13[0xd] = iVar18;
      *(undefined8 *)(puVar13 + 0xe) = 1;
      *(undefined8 *)(puVar13 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar13;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
      }
    }
    DAT_140e46c88 = puVar13;
    iVar15 = iVar15 + 1;
    lVar19 = lVar19 + 1;
  } while (iVar15 < 4);
  FUN_1400d9b60(0,0x70,0xff);
  uVar12 = DAT_140e45fac;
  if ((int)DAT_140e45fac < 1) {
    return;
  }
  if (DAT_140e45270 == 0x17) {
    if (DAT_140e45274 != 0) {
      if (DAT_140e45274 == 1) {
        if (DAT_140e45fac == 0x1e) {
          DAT_140e45270 = 0x1b;
          DAT_140e45274 = 1;
          DAT_140e45fac = 0;
          return;
        }
        return;
      }
      uVar26 = 0x17;
      if (DAT_140e45274 == 2) {
        if (DAT_140e45fac == 0x1e) {
          DAT_140e45270 = 0x18;
          DAT_140e45274 = 0;
          DAT_140e45fac = 0;
          DAT_140e47648 = DAT_140e441b4;
          return;
        }
        return;
      }
      goto joined_r0x000140104c64;
    }
    puVar13 = DAT_140e46c88;
    if (DAT_140e45fac - 0x1e < 0xb4) {
      iVar18 = (int)(DAT_140e45fac - 0x1e) % 0x3c;
      dVar23 = DAT_14053a460 - (double)iVar18 * DAT_140539fb0;
      if (iVar18 < 8) {
        dVar24 = (double)FUN_140332d90(0,((double)iVar18 - 0.0) * DAT_14053aa28 * dVar8 * dVar24);
        dVar7 = dVar7 + dVar24 * DAT_140539ec8;
      }
      uVar27 = (undefined4)((ulonglong)dVar7 >> 0x20);
      uVar26 = SUB84(dVar7,0);
      if (iVar18 == 0) {
        FUN_140184700(DAT_140e44190 << 4,DAT_140e47310);
        FUN_14018a340(DAT_140e47310,1,1);
        uVar12 = DAT_140e45fac;
      }
      uVar11 = DAT_14053ade8;
      if ((int)uVar12 < 0x1e) {
LAB_140104a64:
        if (0x59 < (int)uVar12) goto LAB_140104a69;
LAB_140104aca:
        if (0x95 < (int)uVar12) goto LAB_140104ad2;
      }
      else {
        if ((int)uVar12 < 0x5a) {
          auVar4._8_4_ = uVar26;
          auVar4._0_8_ = dVar7;
          auVar4._12_4_ = uVar27;
          FUN_1400c8410(DAT_140e478b8,0x6e,1,uVar1,DAT_14053ade8,0,auVar4,0xff,0xff,0xff,0xff,1,0);
          uVar12 = DAT_140e45fac;
          goto LAB_140104a64;
        }
LAB_140104a69:
        if ((int)uVar12 < 0x96) {
          auVar5._8_4_ = uVar26;
          auVar5._0_8_ = dVar7;
          auVar5._12_4_ = uVar27;
          FUN_1400c8410(DAT_140e478bc,0x6e,1,uVar1,uVar11,0,auVar5,0xff,0xff,0xff,0xff,1,0);
          uVar12 = DAT_140e45fac;
          goto LAB_140104aca;
        }
LAB_140104ad2:
        auVar6._8_4_ = uVar26;
        auVar6._0_8_ = dVar7;
        auVar6._12_4_ = uVar27;
        FUN_1400c8410(DAT_140e478c0,0x6e,1,uVar1,uVar11,0,auVar6,0xff,0xff,0xff,0xff,1,0);
      }
      uVar26 = DAT_140e478c4;
      puVar13 = (undefined4 *)_malloc_base(0x48);
      if (puVar13 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e48 = _DAT_140e46e48 + 1;
      bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(double *)(puVar13 + 6) = dVar23;
      *puVar13 = uVar26;
      puVar13[1] = 0x6e;
      puVar13[2] = 0x15;
      puVar13[3] = 0x44200000;
      puVar13[4] = 0x437a0000;
      *(undefined2 *)(puVar13 + 5) = 0;
      *(undefined8 *)(puVar13 + 8) = 0x3ff0000000000000;
      puVar13[10] = 0xff;
      puVar13[0xb] = 0xff;
      puVar13[0xc] = 0xff;
      puVar13[0xd] = 0xff;
      *(undefined8 *)(puVar13 + 0xe) = 1;
      *(undefined8 *)(puVar13 + 0x10) = 0;
      if (bVar20) {
        DAT_140e46bf0 = puVar13;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
      }
    }
    DAT_140e46c88 = puVar13;
    if (DAT_140e45fac == 0xd2) {
      DAT_140e46a20 = 0;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
      FUN_14018a340(DAT_140e45100,3,0);
      DAT_140e45270 = 0x14;
      DAT_140e467fc = 0;
      return;
    }
  }
  if (DAT_140e45270 != 0x16) {
    return;
  }
  if (DAT_140e45274 == 0) {
    if (DAT_140e45fac == 0x1e) {
      DAT_140e46a20 = 0;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
      FUN_14018a340(DAT_140e45100,3,0);
      DAT_140e45270 = 0x15;
      DAT_140e467fc = 0;
      return;
    }
    return;
  }
  if (DAT_140e45274 == 1) {
    if (DAT_140e45fac == 0x1e) {
      DAT_140e45270 = 0x1d;
      DAT_140e45274 = 1;
      DAT_140e45fac = 0;
      return;
    }
    return;
  }
  uVar26 = 0x16;
  if (DAT_140e45274 == 2) {
    if (DAT_140e45fac == 0x1e) {
      DAT_140e45270 = 0x18;
      DAT_140e45274 = 0;
      DAT_140e45fac = 0;
      return;
    }
    return;
  }
joined_r0x000140104c64:
  DAT_140e45270 = uVar26;
  if ((DAT_140e45274 == 3) && (DAT_140e45fac == 0x1e)) {
    DAT_140e45270 = 0x1c;
    DAT_140e45274 = 1;
    DAT_140e45fac = 0;
  }
  return;
}


