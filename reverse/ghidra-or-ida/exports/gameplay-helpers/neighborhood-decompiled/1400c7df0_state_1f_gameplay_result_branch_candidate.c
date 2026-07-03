// Function: state_1f_gameplay_result_branch_candidate @ 1400c7df0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_1f_gameplay_result_branch_candidate(void)

{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  undefined1 auStack_f8 [32];
  float local_d8;
  undefined2 local_d0;
  undefined1 local_c8 [16];
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  int local_a0;
  undefined4 local_98;
  undefined4 local_90;
  FILE *local_88;
  ulonglong local_80;
  
  uVar6 = DAT_140e418c8;
  uVar5 = _UNK_14053bb2c;
  uVar4 = _UNK_14053bb28;
  uVar3 = _UNK_14053bb24;
  uVar2 = _DAT_14053bb20;
  dVar13 = DAT_14053a600;
  dVar1 = DAT_14053a020;
  dVar14 = DAT_140539d28;
  local_80 = DAT_1407c6b00 ^ (ulonglong)auStack_f8;
  uVar10 = (int)DAT_140e418c8 >> 0x1f;
  iVar9 = (uVar10 & 0xffffff01) + 0xff;
  if (DAT_140e418c8 < 0x40) {
    dVar12 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a600 *
                                   DAT_14053a020 * DAT_140539d28);
    iVar9 = (int)(dVar12 * DAT_14053a5f8);
LAB_1400c7eb8:
    uVar15 = 0;
    uVar16 = 0;
LAB_1400c7ebb:
    uVar10 = uVar10 & 0xfffffd80;
    dVar12 = (double)CONCAT44(uVar16,uVar15);
    if ((-1 < (int)uVar6) && (dVar12 = (double)CONCAT44(uVar16,uVar15), (int)uVar6 < 0x40)) {
      dVar13 = (double)FUN_140332d90(((double)(int)uVar6 - 0.0) * dVar13 * dVar1 * dVar14);
      uVar10 = -(int)(dVar13 * _DAT_14053b268) - 0x280;
      dVar12 = (double)CONCAT44(uVar16,uVar15);
    }
  }
  else {
    if ((int)DAT_140e418c8 < 0x78) goto LAB_1400c7eb8;
    uVar15 = _DAT_14053bb20;
    uVar16 = _UNK_14053bb24;
    if (0x8b < (int)DAT_140e418c8) goto LAB_1400c7ebb;
    dVar12 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a4a0) * DAT_14053a890 *
                                   DAT_14053a020 * DAT_140539d28);
    uVar10 = uVar10 & 0xfffffd80;
    dVar12 = dVar12 + 0.0;
  }
  uVar7 = uVar6 & 0x8000000f;
  if ((int)uVar7 < 0) {
    uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
  }
  dVar13 = (double)FUN_140332d90(((double)(int)uVar7 - 0.0) * DAT_14053aa28 * dVar1 * dVar14);
  fVar17 = (float)(dVar13 * (double)(int)uVar10) + 0.0;
  if ((0x3f < (int)uVar6) && (0xa9 < (int)uVar6 % 0xb4)) {
    dVar14 = (double)FUN_140332d90(((double)((int)uVar6 % 10) - 0.0) * DAT_14053aa88 * dVar1 *
                                   dVar14);
    fVar17 = (float)(dVar14 * DAT_14053b0d8) + 0.0;
  }
  FUN_1400c2860();
  uVar15 = DAT_140e468dc;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e48 = _DAT_140e46e48 + 1;
  *puVar8 = uVar15;
  bVar11 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar8 + 1) = 0x6e;
  *(undefined8 *)(puVar8 + 3) = 0x43aa0000;
  *(undefined2 *)(puVar8 + 5) = 0;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = iVar9;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar11) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar8;
  }
  uVar15 = DAT_14053aedc;
  local_d8 = fVar17 + DAT_14053ae30;
  local_90 = 0;
  local_98 = 1;
  local_a8 = 0xff;
  local_b0 = 0xff;
  local_b8 = 0xff;
  local_c8._4_4_ = uVar3;
  local_c8._0_4_ = uVar2;
  local_c8._8_4_ = uVar4;
  local_c8._12_4_ = uVar5;
  local_d0 = 0;
  DAT_140e46c88 = puVar8;
  local_a0 = iVar9;
  FUN_1400c8410((&DAT_140e468c8)[DAT_140e445c0 + 7],0x6e,1,DAT_14053aedc);
  local_90 = 0;
  local_98 = 1;
  local_a8 = 0xff;
  local_b0 = 0xff;
  local_b8 = 0xff;
  local_c8._8_4_ = SUB84(dVar12,0);
  local_c8._0_8_ = dVar12;
  local_c8._12_4_ = (int)((ulonglong)dVar12 >> 0x20);
  local_d0 = 0;
  local_d8 = (float)DAT_14053adbc;
  local_a0 = iVar9;
  FUN_1400c8410(DAT_140e468e0,0x6e,1,uVar15);
  if (0x1b7 < (int)DAT_140e418c8) {
    FUN_1400d3fd0(DAT_140e418c8 - 0x1b8);
  }
  if (DAT_140e418c8 != 0x1e0) {
    DAT_140e418c8 = DAT_140e418c8 + 1;
    return;
  }
  puVar8 = &DAT_140e45100;
  do {
    FUN_14018f230(*puVar8,0);
    puVar8 = puVar8 + 1;
  } while ((longlong)puVar8 < 0x140e45178);
  FUN_1400f6fb0();
  if ((DAT_140e41b18 == 0) && (5 < DAT_140e44198)) {
    if (DAT_140e41928 == 0) {
      iVar9 = (&DAT_140e41bbc)
              [((longlong)DAT_1407c7798 * 3 + (longlong)DAT_140e445c0) * 0x32 +
               (longlong)DAT_140e419b8];
    }
    else {
      if (DAT_140e41928 != 1) goto LAB_1400c81f3;
      iVar9 = (&DAT_140e41bbc)
              [((longlong)(DAT_140e41abc + 0xb) * 3 + (longlong)DAT_140e445c0) * 0x32 +
               (longlong)DAT_140e419b8];
    }
    if (2 < iVar9) {
      DAT_140e418c8 = DAT_140e418c8 + 1;
      DAT_140e41b18 = 1;
      DAT_140e45270 = 0x29;
      return;
    }
  }
LAB_1400c81f3:
  if (DAT_140e451a4 == 0) {
    DAT_140e45270 = 0x23;
  }
  else {
    DAT_140e45270 = 4;
    DAT_140e45274 = 0;
    DAT_140e418c8 = 0;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    if (DAT_140e41928 == 0) {
      DAT_1407c7798 = DAT_140e41b58;
    }
    else if (DAT_140e41928 == 1) {
      DAT_1407c7798 = DAT_140e41b5c;
    }
    else if (DAT_140e41928 == 2) {
      DAT_140e45270 = 5;
    }
    DAT_140e419b8 = DAT_140e41b60;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45108);
    FUN_14018a340(DAT_140e45108,3,1);
    fopen_s(&local_88,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_88);
    FUN_140323e90(local_88);
    DAT_140e471fc = 0xb4;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


