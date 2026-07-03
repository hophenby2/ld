// Function: state_11_menu_branch_part1_candidate @ 1401108b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_11_menu_branch_part1_candidate(void)

{
  longlong lVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  bool bVar8;
  float fVar9;
  double dVar10;
  float fVar11;
  
  bVar8 = false;
  if (((DAT_140e418c8 < 0x3c) && (FUN_1400d4310(), DAT_140e418c8 < 0x3c)) || (DAT_140e45fac != 0))
  goto LAB_140110cf4;
  if (DAT_140e8cf1c == 1) {
LAB_140110929:
    bVar2 = true;
  }
  else {
    bVar2 = bVar8;
    if (0x13 < DAT_140e8cf1c) {
      uVar6 = DAT_140e8cf1c - 0x14U & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      if (uVar6 == 0) goto LAB_140110929;
    }
  }
  if ((DAT_140e8cf18 < 1) && (bVar2)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = (DAT_140e41b78 == 1) + 3;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  bVar2 = false;
  if (DAT_140e8cf18 == 1) {
LAB_1401109a9:
    bVar8 = true;
  }
  else if (0x13 < DAT_140e8cf18) {
    uVar6 = DAT_140e8cf18 - 0x14U & 0x80000007;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
    }
    bVar8 = bVar2;
    if (uVar6 == 0) goto LAB_1401109a9;
  }
  if ((DAT_140e8cf1c < 1) && (bVar8)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (DAT_140e41b78 == 0) {
      if (3 < DAT_140e45274) {
LAB_1401109db:
        DAT_140e45274 = 0;
      }
    }
    else if ((DAT_140e41b78 == 1) && (4 < DAT_140e45274)) goto LAB_1401109db;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf10 == 1) {
LAB_140110a2f:
    bVar8 = true;
  }
  else {
    bVar8 = bVar2;
    if (0x13 < DAT_140e8cf10) {
      uVar6 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      if (uVar6 == 0) goto LAB_140110a2f;
    }
  }
  if ((DAT_140e8cf14 < 1) && (bVar8)) {
    if (DAT_140e45274 == 4) {
      if (DAT_140e46064 < 5) {
        DAT_140e46064 = DAT_140e46064 + 5;
      }
      else {
        DAT_140e46064 = DAT_140e46064 + -5;
      }
    }
    else {
      DAT_140e46064 = DAT_140e46064 + -1;
      if (DAT_140e46064 < 0) {
        DAT_140e46064 = 9;
      }
      else {
        for (; 4 < DAT_140e46064 % 5; DAT_140e46064 = DAT_140e46064 + -1) {
        }
      }
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 == 1) {
LAB_140110b27:
    bVar2 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar6 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
    }
    if (uVar6 == 0) goto LAB_140110b27;
  }
  if ((DAT_140e8cf10 < 1) && (bVar2)) {
    if (DAT_140e45274 == 4) {
      if (DAT_140e46064 < 5) {
        DAT_140e46064 = DAT_140e46064 + 5;
      }
      else {
        DAT_140e46064 = DAT_140e46064 + -5;
      }
    }
    else {
      do {
        DAT_140e46064 = DAT_140e46064 + 1;
      } while (4 < DAT_140e46064 % 5);
      if (9 < DAT_140e46064) {
        DAT_140e46064 = 0;
      }
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 0xffffffff;
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
LAB_140110cf4:
  dVar10 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a930 * DAT_14053a020 *
                                 DAT_140539d28);
  uVar5 = _UNK_14053bae8;
  uVar4 = _DAT_14053bae0;
  uVar3 = DAT_14053ae30;
  fVar11 = (float)(dVar10 * DAT_14053a018) + 0.0;
  FUN_1400c8410(DAT_140e41934,0x55,1,fVar11 + DAT_14053ae2c,DAT_14053ae30,0x8000,_DAT_14053bae0,
                _UNK_14053bae8,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e41934,0x55,1,DAT_14053af8c - fVar11,uVar3,0,uVar4,uVar5,0xff,0xff,0xff,0xff,
                1,0);
  uVar3 = DAT_140e41934;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46de4 = _DAT_140e46de4 + 1;
  bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
  fVar9 = fVar11 + DAT_14053ae14;
  *puVar7 = uVar3;
  puVar7[1] = 0x55;
  puVar7[2] = 1;
  puVar7[3] = 0x44200000;
  puVar7[4] = fVar9;
  *(undefined2 *)(puVar7 + 5) = 0xc000;
  *(undefined8 *)(puVar7 + 6) = 0x3fe3333333333333;
  *(undefined8 *)(puVar7 + 8) = 0x3fe3333333333333;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar8) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar7;
  }
  uVar3 = DAT_140e41934;
  DAT_140e46c88 = puVar7;
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46de4 = _DAT_140e46de4 + 1;
  fVar11 = DAT_14053ae50 - fVar11;
  bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar7 = uVar3;
  puVar7[1] = 0x55;
  puVar7[2] = 1;
  puVar7[4] = fVar11;
  puVar7[3] = 0x44200000;
  *(undefined2 *)(puVar7 + 5) = 0x4000;
  *(undefined8 *)(puVar7 + 6) = 0x3fe3333333333333;
  *(undefined8 *)(puVar7 + 8) = 0x3fe3333333333333;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar8) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
  }
  DAT_140e46c88 = puVar7;
  FUN_1400d9b60(0,0x70,0xff);
  if (DAT_140e45fac == 10) {
    DAT_140e45270 = 0x12;
    DAT_140e418c8 = 0x32;
    DAT_140e45fac = 0;
    lVar1 = DAT_140e47908;
    while (lVar1 != 0) {
      lVar1 = *(longlong *)(lVar1 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
  }
  if ((int)DAT_140e45fac < -9) {
    FUN_1400d3fd0(-10 - DAT_140e45fac);
  }
  if (DAT_140e45fac == 0xffffffce) {
    DAT_140e45270 = 2;
    DAT_140e45274 = 4;
    DAT_140e418c8 = 0;
    DAT_140e45d74 = 0;
    DAT_140e45fac = 0;
    DAT_140e46014 = 0;
    lVar1 = DAT_140e47908;
    while (lVar1 != 0) {
      lVar1 = *(longlong *)(lVar1 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
  }
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


