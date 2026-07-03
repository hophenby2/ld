// Function: state_28_29_ending_result_candidate @ 1400d9110
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_28_29_ending_result_candidate(void)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  double dVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  FILE *pFVar12;
  undefined8 uVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  ulonglong uVar17;
  int iVar18;
  uint uVar19;
  ulonglong uVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  undefined4 uVar25;
  undefined1 auStack_138 [32];
  float local_118;
  undefined2 local_110;
  undefined1 local_108 [16];
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  int local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  FILE *local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  
  dVar6 = DAT_14053a5f8;
  dVar5 = DAT_14053a020;
  dVar3 = DAT_140539f40;
  dVar23 = DAT_140539d28;
  local_b8 = DAT_1407c6b00 ^ (ulonglong)auStack_138;
  iVar18 = 0xff;
  uVar19 = 2;
  if (DAT_140e45270 == 0x28) {
    uVar19 = 4;
  }
  uVar17 = 0;
  if (DAT_140e45270 == 0x28) {
    iVar18 = (DAT_140e418c8 >> 0x1f & 0xffffff01U) + 0xff;
    if ((-1 < DAT_140e418c8) && (DAT_140e418c8 < 0x10)) {
      dVar22 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a900 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar18 = (int)(dVar22 * dVar6);
    }
    uVar15 = DAT_140e45fac;
    if (0 < (int)DAT_140e45fac) {
      iVar14 = 0xff;
      if (DAT_140e45fac < 0x1e) {
        dVar22 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - DAT_14053b128) * DAT_14053a798
                                       * dVar5 * dVar23);
        iVar14 = (int)(dVar22 * dVar6);
      }
      iVar18 = 0;
      if ((int)uVar15 < 0x1e) {
        iVar18 = iVar14;
      }
    }
  }
  else if ((DAT_140e45270 == 0x29) && (DAT_140e418c8 < 0x3c)) {
    FUN_1400d4310();
  }
  uVar11 = DAT_140e467f0;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar16 = uVar11;
  *(undefined8 *)(puVar16 + 1) = 10;
  *(undefined8 *)(puVar16 + 3) = 0;
  *(undefined2 *)(puVar16 + 5) = 0;
  *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
  puVar16[10] = 0x80;
  puVar16[0xb] = 0x80;
  puVar16[0xc] = 0x80;
  puVar16[0xd] = iVar18;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  if (bVar21) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar16;
  }
  DAT_140e46c88 = puVar16;
  if (0x27 < DAT_140e418c8) {
    if (((DAT_140e467b8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
      DAT_140e45274 = DAT_140e45274 + -1;
      if (DAT_140e45274 < 0) {
        DAT_140e45274 = uVar19 - 1;
      }
      if (DAT_140e45270 == 0x28) {
        DAT_140e441b4 = DAT_140e45274;
      }
      DAT_140e46014 = 4;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (((DAT_140e467bc == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
      DAT_140e45274 = DAT_140e45274 + 1;
      if ((int)(uVar19 - 1) < DAT_140e45274) {
        DAT_140e45274 = 0;
      }
      if (DAT_140e45270 == 0x28) {
        DAT_140e441b4 = DAT_140e45274;
      }
      DAT_140e46014 = 4;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45fac == 0)) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e45fac = 1;
      DAT_140e467fc = 1;
    }
  }
  iVar14 = DAT_140e46014;
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
    dVar23 = (double)FUN_140332d90(((double)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar5 * dVar23);
    DAT_140e46014 = iVar14 + -1;
    dVar3 = dVar3 + dVar23 * DAT_140539e60;
  }
  uVar11 = DAT_140e4787c;
  uVar25 = (undefined4)((ulonglong)dVar3 >> 0x20);
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  puVar16 = DAT_140e46c88;
  if (DAT_140e45270 == 0x28) {
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar11;
    puVar16[1] = 0x7a;
    puVar16[2] = 1;
    puVar16[3] = 0x44200000;
    puVar16[4] = 0x43160000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = iVar18;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
  }
  DAT_140e46c88 = puVar16;
  uVar11 = DAT_140e47888;
  puVar16 = DAT_140e46c88;
  if (DAT_140e45270 == 0x29) {
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar11;
    puVar16[1] = 0x7a;
    puVar16[2] = 1;
    puVar16[3] = 0x44200000;
    puVar16[4] = 0x43160000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = iVar18;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
  }
  DAT_140e46c88 = puVar16;
  uVar13 = _UNK_14053b7f8;
  pFVar12 = _DAT_14053b7f0;
  uVar11 = DAT_14053aedc;
  fVar10 = DAT_14053ae14;
  fVar9 = DAT_14053ae04;
  fVar8 = DAT_14053ad1c;
  fVar7 = DAT_14053ad10;
  uVar20 = uVar17;
  if (uVar19 != 0) {
    do {
      iVar4 = (int)uVar17;
      iVar14 = iVar4 + 0x17;
      fVar24 = (float)iVar4 * fVar8 + fVar10;
      if (DAT_140e45270 == 0x28) {
        local_c8 = pFVar12;
        uStack_c0 = uVar13;
        iVar14 = *(int *)((longlong)&local_c8 + uVar20 * 4);
        fVar24 = (float)iVar4 * fVar7 + fVar9;
      }
      uVar1 = *(undefined4 *)(&DAT_140e47840 + (longlong)iVar14 * 4);
      if (DAT_140e45274 == iVar4) {
        puVar16 = (undefined4 *)_malloc_base(0x48);
        if (puVar16 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar16[4] = fVar24;
        *puVar16 = uVar1;
        puVar16[1] = 0x7a;
        puVar16[2] = 1;
        puVar16[3] = 0x44200000;
        *(undefined2 *)(puVar16 + 5) = 0;
        auVar2._8_4_ = SUB84(dVar3,0);
        auVar2._0_8_ = dVar3;
        auVar2._12_4_ = uVar25;
        *(undefined1 (*) [16])(puVar16 + 6) = auVar2;
        puVar16[10] = 0xff;
        puVar16[0xb] = 0xff;
        puVar16[0xc] = 0xff;
        puVar16[0xd] = iVar18;
        *(undefined8 *)(puVar16 + 0xe) = 1;
        *(undefined8 *)(puVar16 + 0x10) = 0;
        _DAT_140e46e78 = _DAT_140e46e78 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar16;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
        }
        if (DAT_140e45fac != 0) {
          uVar15 = DAT_140e45fac & 0x80000003;
          if ((int)uVar15 < 0) {
            uVar15 = (uVar15 - 1 | 0xfffffffc) + 1;
          }
          if ((int)uVar15 < 2) {
            local_d0 = 0;
            local_d8 = 1;
            local_e8 = 0xff;
            local_f0 = 0xff;
            local_f8 = 0xff;
            local_108._8_4_ = SUB84(dVar3,0);
            local_108._0_8_ = dVar3;
            local_108._12_4_ = uVar25;
            local_110 = 0;
            DAT_140e46c88 = puVar16;
            local_118 = fVar24;
            local_e0 = iVar18;
            FUN_1400c8410(*(undefined4 *)(&DAT_140e47840 + (longlong)iVar14 * 4),0x7a,6,uVar11);
            puVar16 = DAT_140e46c88;
          }
        }
      }
      else {
        puVar16 = (undefined4 *)_malloc_base();
        if (puVar16 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar16[4] = fVar24;
        puVar16[2] = 1;
        *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar16 + 0xe) = 1;
        *puVar16 = uVar1;
        puVar16[1] = 0x7a;
        puVar16[3] = 0x44200000;
        *(undefined2 *)(puVar16 + 5) = 0;
        puVar16[10] = 0x80;
        puVar16[0xb] = 0x80;
        puVar16[0xc] = 0x80;
        puVar16[0xd] = iVar18;
        *(undefined8 *)(puVar16 + 0x10) = 0;
        _DAT_140e46e78 = _DAT_140e46e78 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar16;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
        }
      }
      DAT_140e46c88 = puVar16;
      uVar17 = (ulonglong)(iVar4 + 1);
      uVar20 = uVar20 + 1;
    } while ((longlong)uVar20 < (longlong)(ulonglong)uVar19);
  }
  FUN_1400d9b60(0,0x70,iVar18);
  if (0 < (int)DAT_140e45fac) {
    if (DAT_140e45270 == 0x28) {
      if (DAT_140e45fac == 0x3c) {
        DAT_140e441b4 = DAT_140e45274;
        iVar18 = load_secondary_localized_resources_candidate();
        if (iVar18 == -1) {
          MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
        }
        DAT_140e41b14 = 1;
        FUN_1400f6fb0();
        fopen_s(&local_c8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_c8);
        FUN_140323e90(local_c8);
        DAT_140e418c8 = 1;
        DAT_140e45270 = 1;
        DAT_140e471fc = 0xb4;
        return;
      }
    }
    else if (DAT_140e45270 == 0x29) {
      if (0x14 < (int)DAT_140e45fac) {
        FUN_1400d3fd0(DAT_140e45fac - 0x14);
      }
      if (DAT_140e45fac == 0x3c) {
        if (DAT_140e45274 == 0) {
          DAT_140e44198 = 0;
        }
        else if (DAT_140e45274 == 1) {
          DAT_140e44198 = 6;
        }
        FUN_1400f6fb0();
        DAT_140e45270 = 0x23;
        if (DAT_140e41928 == 0) {
          DAT_1407c7798 = DAT_140e41b58;
        }
        else if (DAT_140e41928 == 1) {
          DAT_1407c7798 = (DAT_1407c7798 == 10) + 1;
        }
        fopen_s(&local_c8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_c8);
        FUN_140323e90(local_c8);
        DAT_140e471fc = 0xb4;
      }
    }
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


