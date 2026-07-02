// Function: FUN_140104d80 @ 140104d80
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140104d80(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  double dVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  bool bVar13;
  double dVar14;
  float fVar15;
  undefined4 uVar16;
  undefined1 auStack_e8 [32];
  float local_c8;
  undefined2 local_c0;
  undefined1 local_b8 [16];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_80;
  FILE *local_78;
  ulonglong local_70;
  
  dVar3 = DAT_140539f40;
  local_70 = DAT_1407c6b00 ^ (ulonglong)auStack_e8;
  FUN_140106880(0xff);
  iVar12 = 0;
  bVar4 = false;
  if (DAT_140e8cf10 == 1) {
LAB_140104e07:
    bVar13 = true;
  }
  else {
    bVar13 = bVar4;
    if (0x13 < DAT_140e8cf10) {
      uVar9 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_140104e07;
    }
  }
  if (((DAT_140e8cf14 < 1) && (bVar13)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 1;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  bVar13 = false;
  if (DAT_140e8cf14 == 1) {
LAB_140104ea3:
    bVar13 = true;
  }
  else if (0x13 < DAT_140e8cf14) {
    uVar9 = DAT_140e8cf14 - 0x14U & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    if (uVar9 == 0) goto LAB_140104ea3;
  }
  if (((DAT_140e8cf10 < 1) && (bVar13)) && (DAT_140e45fac == 0)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (1 < DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e46014 = 4;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e467fc = 1;
    DAT_140e45fac = 1;
  }
  if ((((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
    DAT_140e45fac = 1;
    DAT_140e45274 = 1;
    DAT_140e467fc = 1;
  }
  iVar8 = DAT_140e46014;
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
    dVar14 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * DAT_14053a020 *
                                   DAT_140539d28);
    DAT_140e46014 = iVar8 + -1;
    dVar3 = dVar3 + dVar14 * DAT_140539e60;
  }
  uVar7 = DAT_140e4788c;
  uVar16 = (undefined4)((ulonglong)dVar3 >> 0x20);
  if (0 < (int)uVar9) {
    DAT_140e45fac = uVar9 + 1;
  }
  puVar10 = DAT_140e46c88;
  if (DAT_140e45270 == 0x1b) {
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar7;
    puVar10[1] = 0x7a;
    puVar10[2] = 1;
    puVar10[3] = 0x44200000;
    puVar10[4] = 0x43480000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  uVar7 = DAT_140e47890;
  puVar10 = DAT_140e46c88;
  if (DAT_140e45270 == 0x1c) {
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar7;
    puVar10[1] = 0x7a;
    puVar10[2] = 1;
    puVar10[3] = 0x44200000;
    puVar10[4] = 0x43480000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  uVar7 = DAT_140e47894;
  puVar10 = DAT_140e46c88;
  if (DAT_140e45270 == 0x1d) {
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar7;
    puVar10[1] = 0x7a;
    puVar10[2] = 1;
    puVar10[3] = 0x44200000;
    puVar10[4] = 0x43480000;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = 0xff;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar13) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
  }
  DAT_140e46c88 = puVar10;
  uVar7 = DAT_14053aedc;
  fVar6 = DAT_14053ae14;
  fVar5 = DAT_14053ad10;
  puVar10 = &DAT_140e4789c;
  do {
    uVar1 = *puVar10;
    fVar15 = (float)iVar12 * fVar5 + fVar6;
    if (DAT_140e45274 == iVar12) {
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar11[4] = fVar15;
      *puVar11 = uVar1;
      puVar11[1] = 0x7a;
      puVar11[2] = 1;
      puVar11[3] = 0x44200000;
      *(undefined2 *)(puVar11 + 5) = 0;
      auVar2._8_4_ = SUB84(dVar3,0);
      auVar2._0_8_ = dVar3;
      auVar2._12_4_ = uVar16;
      *(undefined1 (*) [16])(puVar11 + 6) = auVar2;
      puVar11[10] = 0xff;
      puVar11[0xb] = 0xff;
      puVar11[0xc] = 0xff;
      puVar11[0xd] = 0xff;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
      if (DAT_140e45fac != 0) {
        uVar9 = DAT_140e45fac & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if ((int)uVar9 < 2) {
          local_80 = 0;
          local_88 = 1;
          local_90 = 0xff;
          local_98 = 0xff;
          local_a0 = 0xff;
          local_a8 = 0xff;
          local_b8._8_4_ = SUB84(dVar3,0);
          local_b8._0_8_ = dVar3;
          local_b8._12_4_ = uVar16;
          local_c0 = 0;
          DAT_140e46c88 = puVar11;
          local_c8 = fVar15;
          FUN_1400c8410(*puVar10,0x7a,6,uVar7);
          puVar11 = DAT_140e46c88;
        }
      }
    }
    else {
      puVar11 = (undefined4 *)_malloc_base();
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar11[4] = fVar15;
      *puVar11 = uVar1;
      puVar11[1] = 0x7a;
      puVar11[2] = 1;
      puVar11[3] = 0x44200000;
      *(undefined2 *)(puVar11 + 5) = 0;
      *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
      puVar11[10] = 0x80;
      puVar11[0xb] = 0x80;
      puVar11[0xc] = 0x80;
      puVar11[0xd] = 0xff;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
    }
    DAT_140e46c88 = puVar11;
    iVar12 = iVar12 + 1;
    puVar10 = puVar10 + 1;
  } while (iVar12 < 2);
  FUN_1400d9b60(0,0x70,0xff);
  if ((int)DAT_140e45fac < 1) {
    return;
  }
  if (DAT_140e45274 != 0) goto LAB_140105657;
  if (DAT_140e45270 == 0x1b) {
    if (0x13 < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x14);
    }
    if (DAT_140e45fac == 0x3c) {
      fopen_s(&local_78,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_78);
      FUN_140323e90(local_78);
      DAT_140e471fc = 0xb4;
      FUN_1400f7150();
    }
  }
  fVar5 = DAT_14053ac64;
  puVar10 = &DAT_140e45100;
  if (DAT_140e45270 == 0x1c) {
    if (0x13 < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x14);
    }
    if (DAT_140e45fac == 0x3c) {
      if ((DAT_140e451a4 == 1) ||
         ((bVar13 = true, DAT_140e452c0 == DAT_1407c7798 &&
          (bVar13 = true, DAT_140e418c8 < DAT_140e45d74 + 0xf0)))) {
        bVar13 = bVar4;
      }
      puVar11 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar11,0);
        puVar11 = puVar11 + 1;
      } while ((longlong)puVar11 < 0x140e45178);
      FUN_1400f6fb0();
      if (DAT_140e41928 == -1) {
        _DAT_1407c777c = 1.0;
        FUN_140184700((int)((float)DAT_140e4418c * fVar5),DAT_140e45108);
        FUN_14018a340(DAT_140e45108,3,1);
        DAT_140e45270 = 2;
        goto LAB_140105657;
      }
      if (bVar13) {
        DAT_140e45270 = 0x23;
        goto LAB_140105657;
      }
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
      FUN_140184700((int)((float)DAT_140e4418c * fVar5 * _DAT_1407c777c),DAT_140e45108);
      FUN_14018a340(DAT_140e45108,3,1);
      fopen_s(&local_78,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_78);
      FUN_140323e90(local_78);
      DAT_140e471fc = 0xb4;
    }
  }
  if (DAT_140e45270 == 0x1d) {
    if (0x13 < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x14);
    }
    if (DAT_140e45fac == 0x3c) {
      FUN_1400f6fb0();
      DAT_140e418c8 = 0;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      DAT_140e41928 = 0;
      DAT_1407c7798 = 1;
      do {
        FUN_14018f230(*puVar10,0);
        puVar10 = puVar10 + 1;
      } while ((longlong)puVar10 < 0x140e45178);
      _DAT_1407c777c = 1.0;
      FUN_140184700((int)((float)DAT_140e4418c * fVar5),DAT_140e45108);
      FUN_14018a340(DAT_140e45108,3,1);
      if (DAT_140e441bc == 0) {
        DAT_140e441bc = 1;
        DAT_140e445c0 = 0;
        _DAT_140e445c4 = _DAT_140e41b28;
        _DAT_140e445cc = _DAT_140e41b30;
        DAT_140e45270 = 3;
        DAT_140e45274 = 0;
        DAT_140e46064 = 0;
        return;
      }
      DAT_140e45270 = 10;
      DAT_140e45274 = 7;
      return;
    }
  }
LAB_140105657:
  if ((DAT_140e45274 == 1) && (DAT_140e45fac == 0x1e)) {
    if ((DAT_140e45270 - 0x1bU & 0xfffffffd) == 0) {
      DAT_140e45274 = 1;
    }
    if (DAT_140e45270 == 0x1c) {
      DAT_140e45274 = 3;
    }
    DAT_140e45fac = 0;
    DAT_140e46014 = 0;
    DAT_140e45270 = (DAT_140e41928 != -1) + 0x16;
  }
  return;
}


