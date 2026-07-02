// Function: FUN_1400b4c60 @ 1400b4c60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400b53a3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b4c60(void)

{
  int iVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  longlong lVar11;
  undefined4 uVar12;
  int iVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined1 auStack_148 [32];
  float local_128;
  uint local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  uint local_108;
  uint local_100;
  uint local_f8;
  int local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  FILE *local_d8;
  ulonglong local_d0;
  
  fVar19 = DAT_14053aedc;
  fVar18 = DAT_14053ae30;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  if (DAT_140e418c8 < 0x3c) {
    FUN_1400d4310();
  }
  uVar12 = DAT_140e467f0;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  uVar14 = 0;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar12;
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
  uVar12 = DAT_140e4602c;
  DAT_140e46c88 = puVar10;
  puVar10 = (undefined4 *)_malloc_base();
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar10 = uVar12;
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
  FUN_1400d3a60();
  bVar17 = false;
  uVar9 = 1;
  uVar16 = uVar14;
  fVar25 = fVar19;
  dVar22 = _UNK_14053bb28;
  dVar3 = _DAT_14053bb20;
  dVar4 = DAT_14053a890;
  dVar5 = DAT_14053a020;
  dVar6 = DAT_140539d28;
  if (((0x1f < DAT_140e418c8) && (DAT_140e45fac == 0)) && (DAT_140e46014 == 0)) {
    if (DAT_140e46064 == 0) {
      if (DAT_140e8cf10 == 1) {
LAB_1400b4e8f:
        uVar15 = 1;
      }
      else {
        uVar15 = uVar14;
        if (0x13 < DAT_140e8cf10) {
          uVar8 = DAT_140e8cf10 - 0x14U & 0x80000007;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
          }
          uVar15 = 0;
          if (uVar8 == 0) goto LAB_1400b4e8f;
        }
      }
      if (((DAT_140e8cf14 < 1) && ((int)uVar15 == 1)) && (3 < (int)DAT_140e45274)) {
        DAT_140e45274 = DAT_140e45274 - 4;
        DAT_140e467fc = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
        DAT_140e46014 = 1;
      }
      if (DAT_140e8cf14 == 1) {
LAB_1400b4f11:
        uVar15 = 1;
      }
      else {
        uVar15 = uVar14;
        if (0x13 < DAT_140e8cf14) {
          uVar8 = DAT_140e8cf14 - 0x14U & 0x80000007;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
          }
          uVar15 = 0;
          if (uVar8 == 0) goto LAB_1400b4f11;
        }
      }
      if (((DAT_140e8cf10 < 1) && ((int)uVar15 == 1)) && ((int)DAT_140e45274 < 0x10)) {
        DAT_140e45274 = DAT_140e45274 + 4;
        DAT_140e467fc = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
        DAT_140e46014 = 1;
      }
      if (DAT_140e8cf18 == 1) {
LAB_1400b4f86:
        bVar2 = true;
      }
      else {
        bVar2 = bVar17;
        if (0x13 < DAT_140e8cf18) {
          uVar8 = DAT_140e8cf18 - 0x14U & 0x80000007;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
          }
          if (uVar8 == 0) goto LAB_1400b4f86;
        }
      }
      if ((DAT_140e8cf1c < 1) && (bVar2)) {
        uVar8 = DAT_140e45274 & 0x80000003;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
        }
        if ((uVar8 == 3) || (0x12 < (int)DAT_140e45274)) {
          DAT_140e45270 = 7;
          DAT_140e418c8 = 0;
          DAT_140e46014 = 0;
          DAT_140e46bb4 = 0;
          DAT_140e46bb0 = 0;
          DAT_140e45fac = 0;
          lVar11 = DAT_140e47908;
          while (lVar11 != 0) {
            lVar11 = *(longlong *)(lVar11 + 0x238);
            FUN_140323ce8();
          }
          DAT_140e47908 = 0;
          DAT_140e9fd30 = 0;
          DAT_140e45274 = ((int)(DAT_140e45274 + ((int)DAT_140e45274 >> 0x1f & 3U)) >> 2) * 10;
        }
        else {
          DAT_140e46014 = 1;
          DAT_140e45274 = DAT_140e45274 + 1;
        }
        DAT_140e467fc = 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
      if (DAT_140e8cf1c == 1) {
LAB_1400b5097:
        bVar17 = true;
      }
      else if (0x13 < DAT_140e8cf1c) {
        uVar8 = DAT_140e8cf1c - 0x14U & 0x80000007;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
        }
        bVar17 = false;
        if (uVar8 == 0) goto LAB_1400b5097;
      }
      if ((DAT_140e8cf18 < 1) && (bVar17)) {
        uVar8 = DAT_140e45274 & 0x80000003;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
        }
        if (uVar8 == 0) {
          DAT_140e45270 = 8;
          DAT_140e418c8 = 0;
          DAT_140e46014 = 0;
          DAT_140e46bb4 = 0;
          DAT_140e46bb0 = 0;
          DAT_140e45fac = 0;
          lVar11 = DAT_140e47908;
          while (lVar11 != 0) {
            lVar11 = *(longlong *)(lVar11 + 0x238);
            FUN_140323ce8();
          }
          DAT_140e47908 = 0;
          DAT_140e9fd30 = 0;
        }
        else {
          uVar9 = DAT_140e45274 - 1;
          DAT_140e46014 = 1;
        }
        DAT_140e467fc = 1;
        DAT_140e45274 = uVar9;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        FUN_14018a340(DAT_140e47200,1,1);
      }
    }
    if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
      if (DAT_140e46064 == 0) {
        lVar11 = (longlong)(int)DAT_140e45274;
        if ((&DAT_140e43f1c)[lVar11] == 1) {
          DAT_140e46064 = 1;
          DAT_140e45fac = 1;
          if ((&DAT_140e43f80)[lVar11] == 0) {
            (&DAT_140e43f80)[lVar11] = 1;
            fopen_s(&local_d8,"save\\save.dat","wb");
            FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
            FUN_140323e90(local_d8);
            DAT_140e471fc = 0xb4;
          }
          goto LAB_1400b5228;
        }
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      else {
        DAT_140e45fac = 0xffffffff;
LAB_1400b5228:
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        uVar12 = DAT_140e47204;
      }
      FUN_14018a340(uVar12,1,1);
      DAT_140e467fc = 1;
    }
    if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
      DAT_140e45fac = 0xffffffff;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
      FUN_14018a340(DAT_140e47208,1,1);
    }
    dVar22 = _UNK_14053bb28;
    dVar3 = _DAT_14053bb20;
    dVar4 = DAT_14053a890;
    dVar5 = DAT_14053a020;
    dVar6 = DAT_140539d28;
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
  do {
    uVar8 = (uint)uVar14;
    uVar9 = (uint)(uVar14 >> 2);
    fVar23 = (float)(uVar8 & 3) * DAT_14053ade0 + DAT_14053adf4;
    fVar24 = (float)uVar9 * DAT_14053ad2c + DAT_14053ad50;
    if ((uVar9 & 1) == 1) {
      fVar23 = fVar23 + DAT_14053aca8;
    }
    iVar1 = *(int *)((longlong)&DAT_140e43f1c + uVar16);
    iVar13 = 0x60;
    if (iVar1 != 0) {
      iVar13 = 0xff;
    }
    uVar9 = -(uint)(iVar1 != 0) & 0xff;
    if ((DAT_140e46064 == 1) && (uVar8 == DAT_140e45274)) {
LAB_1400b5487:
      uVar12 = DAT_140e46800;
      if (DAT_140e45270 == 6) {
        puVar10 = (undefined4 *)_malloc_base(0x48);
        if (puVar10 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar10[3] = fVar23;
        puVar10[4] = fVar24;
        *puVar10 = uVar12;
        puVar10[1] = 100;
        puVar10[2] = 1;
        *(undefined2 *)(puVar10 + 5) = 0;
        *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
        puVar10[10] = 0xff;
        puVar10[0xb] = 0xff;
        puVar10[0xc] = 0xff;
        puVar10[0xd] = 0xff;
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
        dVar20 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053ab08 * dVar5 * dVar6
                                      );
        local_e0 = 0;
        local_e8 = 1;
        local_f0 = 0x40 - (int)(dVar20 * DAT_14053b160);
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_120 = local_120 & 0xffff0000;
        local_128 = fVar24;
        local_118 = dVar3;
        uStack_110 = dVar22;
        FUN_1400c8410(DAT_140e46800,100,6,fVar23);
        uVar9 = DAT_140e45fac;
        fVar7 = DAT_14053ae30;
        if (DAT_140e46064 == 1) {
          dVar20 = dVar3;
          if (0 < (int)DAT_140e45fac) {
            FUN_1403300b4((double)(DAT_14053ae30 - fVar24),(double)(fVar19 - fVar23));
            fVar18 = (float)FUN_140334430(fVar24 - fVar7,DAT_140539fc0);
            fVar19 = (float)FUN_140334430(fVar23 - DAT_14053aedc);
            if (fVar18 + fVar19 < 0.0) {
              fVar18 = (float)FUN_1403352f8();
            }
            else {
              fVar18 = SQRT(fVar18 + fVar19);
            }
            dVar20 = (double)((fVar18 / DAT_14053ac58) * (float)(int)uVar9);
            dVar21 = (double)FUN_1403307c0();
            fVar25 = (float)(dVar21 * dVar20) + fVar23;
            dVar21 = (double)FUN_140332d90();
            fVar18 = (float)(dVar21 * dVar20) + fVar24;
            dVar20 = (double)FUN_140332d90(((double)(int)uVar9 - 0.0) * dVar4 * dVar5 * dVar6);
            dVar20 = dVar20 * _DAT_140539f30 + DAT_140539e88;
            fVar19 = DAT_14053aedc;
          }
          if (0x7fffffff < uVar9) {
            dVar20 = (double)FUN_1403300b4((double)(fVar24 - DAT_14053ae30),
                                           (double)(fVar23 - fVar19));
            fVar18 = (float)FUN_140334430((int)(dVar20 * DAT_14053aba0) & 0xffff,DAT_140539fc0);
            fVar19 = (float)FUN_140334430();
            if (fVar18 + fVar19 < 0.0) {
              fVar18 = (float)FUN_1403352f8();
            }
            else {
              fVar18 = SQRT(fVar18 + fVar19);
            }
            dVar20 = (double)((fVar18 / DAT_14053ac58) * (float)(int)-uVar9);
            dVar21 = (double)FUN_1403307c0();
            fVar25 = (float)(dVar21 * dVar20) + DAT_14053aedc;
            dVar21 = (double)FUN_140332d90();
            fVar18 = (float)(dVar21 * dVar20) + DAT_14053ae30;
            dVar20 = (double)FUN_140332d90(((double)(int)-uVar9 - 0.0) * dVar4 * dVar5 * dVar6);
            dVar20 = dVar20 * _DAT_14053b098 + dVar3;
          }
          local_e0 = 0;
          local_e8 = 1;
          local_f0 = 0xff;
          local_f8 = 0xff;
          local_100 = 0xff;
          local_108 = 0xff;
          local_120 = local_120 & 0xffff0000;
          local_128 = fVar18;
          local_118 = dVar20;
          uStack_110 = dVar20;
          FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e46810 + uVar16),0x7e,1,fVar25);
          fVar19 = DAT_14053aedc;
        }
      }
    }
    else {
      if ((iVar1 == 1) && (*(int *)((longlong)&DAT_140e43f80 + uVar16) == 0)) {
        dVar20 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * dVar4 * dVar5 * dVar6);
        uVar9 = 0xc0 - (int)(dVar20 * DAT_14053b160);
      }
      local_e0 = 0;
      local_e8 = 1;
      local_118 = _DAT_14053baa0;
      uStack_110 = _UNK_14053baa8;
      local_120 = local_120 & 0xffff0000;
      local_128 = fVar24;
      local_108 = uVar9;
      local_100 = uVar9;
      local_f8 = uVar9;
      local_f0 = iVar13;
      FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e46810 + uVar16),100,1,fVar23);
      if (uVar8 == DAT_140e45274) goto LAB_1400b5487;
    }
    uVar14 = (ulonglong)(uVar8 + 1);
    uVar16 = uVar16 + 4;
  } while ((int)(uVar8 + 1) < 0x14);
  dVar22 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * dVar4 * dVar5 * dVar6);
  uVar12 = DAT_140e41934;
  fVar18 = (float)(dVar22 * DAT_14053a178) + 0.0 + DAT_14053afe4;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e28 = _DAT_140e46e28 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar10[3] = fVar18;
  *puVar10 = uVar12;
  puVar10[1] = 0x66;
  puVar10[2] = 1;
  puVar10[4] = 0x43b40000;
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
  dVar22 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * dVar4 * dVar5 * dVar6);
  uVar12 = DAT_140e41934;
  fVar18 = (float)(dVar22 * DAT_14053b0c8) + 0.0 + DAT_14053acfc;
  puVar10 = (undefined4 *)_malloc_base(0x48);
  if (puVar10 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e28 = _DAT_140e46e28 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar10[3] = fVar18;
  *puVar10 = uVar12;
  puVar10[1] = 0x66;
  puVar10[2] = 1;
  puVar10[4] = 0x43b40000;
  *(undefined2 *)(puVar10 + 5) = 0x8000;
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
  FUN_1400d9b60(1,0x70,0xff);
  lVar11 = DAT_140e47908;
  if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
    while (lVar11 != 0) {
      lVar11 = *(longlong *)(lVar11 + 0x238);
      FUN_140323ce8();
    }
    local_e8 = 5;
    local_f0 = 1;
    local_f8 = 0;
    local_100 = 0xff;
    local_108 = 0xff;
    uVar14 = (ulonglong)uStack_110 >> 0x20;
    uStack_110 = (double)CONCAT44((int)uVar14,0xff);
    uVar14 = (ulonglong)local_118 >> 0x20;
    local_118 = (double)CONCAT44((int)uVar14,DAT_14053ac80);
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
    local_128 = fVar19;
    local_120 = DAT_14053ac34;
    if ((&DAT_140e43f1c)[(int)DAT_140e45274] == 0) {
      FUN_14012e070(DAT_140e45274 + 300,0);
    }
    else {
      FUN_14012e070(DAT_140e45274 + 0x145,0);
    }
  }
  if (DAT_140e46064 == 1) {
    if (DAT_140e45fac == 0x14) {
      DAT_140e45fac = 0;
      goto LAB_1400b5be7;
    }
LAB_1400b5bba:
    if (DAT_140e45fac == 0xffffffec) {
      DAT_140e45fac = 0;
      DAT_140e46064 = 0;
      goto LAB_1400b5be7;
    }
  }
  else {
    if (DAT_140e46064 == 0) {
      if ((int)DAT_140e45fac < -0x13) {
        FUN_1400d3fd0(-0x14 - DAT_140e45fac);
      }
      if (DAT_140e45fac == 0xffffffce) {
        DAT_140e45270 = 2;
        DAT_140e45274 = 5;
        DAT_140e418c8 = 0;
        DAT_140e45fac = 0;
        DAT_140e46014 = 0;
        fopen_s(&local_d8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
        FUN_140323e90(local_d8);
        DAT_140e471fc = 0xb4;
      }
    }
    if (DAT_140e46064 == 1) goto LAB_1400b5bba;
  }
  if (0 < (int)DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac + 1;
  }
  if (0x7fffffff < DAT_140e45fac) {
    DAT_140e45fac = DAT_140e45fac - 1;
  }
LAB_1400b5be7:
  DAT_140e418c8 = DAT_140e418c8 + 1;
  if (DAT_140e46014 == 1) {
    DAT_140e46014 = 0;
  }
  return;
}


