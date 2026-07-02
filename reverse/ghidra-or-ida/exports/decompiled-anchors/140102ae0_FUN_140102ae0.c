// Function: FUN_140102ae0 @ 140102ae0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140102ae0(void)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  uint *puVar18;
  undefined4 uVar19;
  longlong lVar20;
  ulonglong uVar21;
  FILE *pFVar22;
  bool bVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  undefined1 auStack_358 [32];
  float local_338;
  uint local_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined4 local_318;
  undefined4 local_310;
  undefined4 local_308;
  int local_300;
  undefined4 local_2f8;
  undefined4 local_2f0;
  uint local_2e8;
  int local_2e4;
  uint local_2d8 [128];
  FILE *local_d8;
  ulonglong local_d0;
  
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_358;
  uVar12 = FUN_14019d970(1);
  local_2d8[0x1c] = 0xe;
  local_2d8[0x1e] = 0x1c;
  local_2d8[0x1d] = 0xf;
  local_2d8[0x1f] = 0x2a;
  local_2d8[0x20] = 0x36;
  local_2d8[0x21] = 0x1d;
  local_2d8[0x22] = 0x9d;
  local_2d8[0x23] = 1;
  local_2d8[0x24] = 0x39;
  local_2d8[0x25] = 0xc9;
  local_2d8[0x26] = 0xd1;
  local_2d8[0x27] = 0xcf;
  local_2d8[0x28] = 199;
  local_2d8[0x29] = 0xcb;
  local_2d8[0x2a] = 200;
  local_2d8[0x2b] = 0xcd;
  local_2d8[0x2c] = 0xd0;
  local_2d8[0x2d] = 0xd2;
  local_2d8[0x2e] = 0xd3;
  local_2d8[0x2f] = 0xc;
  local_2d8[0x30] = 0x7d;
  local_2d8[0x31] = 0x90;
  local_2d8[0x32] = 0x34;
  local_2d8[0x33] = 0x35;
  local_2d8[0x34] = 0x38;
  local_2d8[0x35] = 0xb8;
  local_2d8[0x36] = 0x46;
  local_2d8[0x37] = 0x27;
  local_2d8[0x38] = 0x92;
  local_2d8[0x39] = 0x1a;
  local_2d8[0x3a] = 0x1b;
  local_2d8[0x3b] = 0x91;
  local_2d8[0x3c] = 0x2b;
  local_2d8[0x3d] = 0x33;
  local_2d8[0x3e] = 0x3a;
  local_2d8[0x3f] = 0xc5;
  local_2d8[0x40] = 0x52;
  local_2d8[0x41] = 0x4f;
  local_2d8[0x42] = 0x50;
  local_2d8[0x43] = 0x51;
  local_2d8[0x44] = 0x4b;
  local_2d8[0x45] = 0x4c;
  local_2d8[0x46] = 0x4d;
  local_2d8[0x47] = 0x47;
  local_2d8[0x48] = 0x48;
  local_2d8[0x49] = 0x49;
  local_2d8[0x4a] = 0x37;
  local_2d8[0x4b] = 0x4e;
  local_2d8[0x4c] = 0x4a;
  local_2d8[0x4d] = 0x53;
  local_2d8[0x4e] = 0xb5;
  local_2d8[0x4f] = 0x9c;
  local_2d8[0x50] = 0x3b;
  local_2d8[0x51] = 0x3c;
  local_2d8[0x52] = 0x3d;
  local_2d8[0x53] = 0x3e;
  local_2d8[0x54] = 0x3f;
  local_2d8[0x55] = 0x40;
  local_2d8[0x56] = 0x41;
  local_2d8[0x57] = 0x42;
  local_2d8[0x58] = 0x43;
  local_2d8[0x59] = 0x44;
  local_2d8[0x5a] = 0x57;
  local_2d8[0x5b] = 0x58;
  local_2d8[0x5c] = 0x1e;
  local_2d8[0x5d] = 0x30;
  local_2d8[0x5e] = 0x2e;
  local_2d8[0x5f] = 0x20;
  local_2d8[0x60] = 0x12;
  local_2d8[0x61] = 0x21;
  local_2d8[0x62] = 0x22;
  local_2d8[99] = 0x23;
  local_2d8[100] = 0x17;
  local_2d8[0x65] = 0x24;
  local_2d8[0x66] = 0x25;
  local_2d8[0x67] = 0x26;
  local_2d8[0x68] = 0x32;
  local_2d8[0x69] = 0x31;
  local_2d8[0x6a] = 0x18;
  local_2d8[0x6b] = 0x19;
  local_2d8[0x6c] = 0x10;
  local_2d8[0x6d] = 0x13;
  local_2d8[0x6e] = 0x1f;
  local_2d8[0x6f] = 0x14;
  local_2d8[0x70] = 0x16;
  local_2d8[0x71] = 0x2f;
  local_2d8[0x72] = 0x11;
  local_2d8[0x73] = 0x2d;
  local_2d8[0x74] = 0x15;
  local_2d8[0x75] = 0x2c;
  local_2d8[0x76] = 0xb;
  local_2d8[0x77] = 2;
  local_2d8[0x78] = 3;
  local_2d8[0x79] = 4;
  local_2d8[0x7a] = 5;
  local_2d8[0x7b] = 6;
  local_2d8[0x7c] = 7;
  local_2d8[0x7d] = 8;
  local_2d8[0x7e] = 9;
  local_2d8[0x7f] = 10;
  local_2d8[0] = 0x10;
  local_2d8[1] = 0x20;
  local_2d8[2] = 0x40;
  local_2d8[3] = 0x80;
  local_2d8[4] = 0x100;
  local_2d8[5] = 0x200;
  local_2d8[6] = 0x400;
  local_2d8[7] = 0x800;
  local_2d8[8] = 0x1000;
  local_2d8[9] = 0x2000;
  local_2d8[10] = 0x4000;
  local_2d8[0xb] = 0x8000;
  local_2d8[0xc] = 0x10000;
  local_2d8[0xd] = 0x20000;
  local_2d8[0xe] = 0x40000;
  local_2d8[0xf] = 0x80000;
  local_2d8[0x10] = 0x100000;
  local_2d8[0x11] = 0x200000;
  local_2d8[0x12] = 0x400000;
  local_2d8[0x13] = 0x800000;
  local_2d8[0x14] = 0x1000000;
  local_2d8[0x15] = 0x2000000;
  local_2d8[0x16] = 0x4000000;
  local_2d8[0x17] = 0x8000000;
  local_2d8[0x18] = 0x10000000;
  local_2d8[0x19] = 0x20000000;
  local_2d8[0x1a] = 0x40000000;
  local_2d8[0x1b] = 0x80000000;
  if (DAT_140e45270 == 0xd) {
    if (DAT_140e418c8 < 0x3c) {
      FUN_1400d4310();
    }
    uVar17 = DAT_140e467f0;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar17;
    *(undefined8 *)(puVar16 + 1) = 10;
    *(undefined8 *)(puVar16 + 3) = 0;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = 0xff;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    uVar17 = DAT_140e46040;
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e24 = _DAT_140e46e24 + 1;
    *puVar16 = uVar17;
    bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
    *(undefined8 *)(puVar16 + 1) = 0x65;
    *(undefined8 *)(puVar16 + 3) = 0;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = 0xff;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar23) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    DAT_140e46c88 = puVar16;
    FUN_1400d3a60();
  }
  bVar23 = false;
  if (DAT_140e45270 == 0x1a) {
    FUN_140106880(0xff);
  }
  if (((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) || (DAT_140e46014 != 0)) goto LAB_14010377c;
  if (DAT_140e46064 == 0) {
    bVar3 = false;
    if (DAT_140e8cf10 == 1) {
LAB_140103191:
      bVar3 = true;
    }
    else if (0x13 < DAT_140e8cf10) {
      uVar13 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar13 < 0) {
        uVar13 = (uVar13 - 1 | 0xfffffff8) + 1;
      }
      if (uVar13 == 0) goto LAB_140103191;
    }
    if ((DAT_140e8cf14 < 1) && (bVar3)) {
      DAT_140e45274 = DAT_140e45274 - 1;
      if ((int)DAT_140e45274 < 0) {
        DAT_140e45274 = 0xc;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    if (DAT_140e8cf14 == 1) {
LAB_14010321d:
      bVar23 = true;
    }
    else if (0x13 < DAT_140e8cf14) {
      uVar13 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar13 < 0) {
        uVar13 = (uVar13 - 1 | 0xfffffff8) + 1;
      }
      if (uVar13 == 0) goto LAB_14010321d;
    }
    if ((DAT_140e8cf10 < 1) && (bVar23)) {
      DAT_140e45274 = DAT_140e45274 + 1;
      if (0xc < (int)DAT_140e45274) {
        DAT_140e45274 = 0;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e46014 = 1;
    }
    if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
      if ((int)DAT_140e45274 < 0xb) {
        if (((int)DAT_140e441cc < 5) && ((int)DAT_140e45274 < 4)) {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
          uVar17 = DAT_140e4720c;
        }
        else {
          DAT_140e46064 = 1;
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
          uVar17 = DAT_140e47204;
        }
        FUN_14018a340(uVar17,1,1);
      }
      if (10 < (int)DAT_140e45274) {
        if (DAT_140e45274 == 0xb) {
          if ((int)DAT_140e441cc < 5) {
            _DAT_140e44200 = _DAT_14053b650;
            uRam0000000140e44208 = _UNK_14053b658;
            if ((DAT_140e441cc < 3) || (DAT_140e441cc == 5)) {
              _DAT_140e44210 = _DAT_14053b810;
              _DAT_140e44218 = _UNK_14053b818;
              DAT_140e44220 = 0x20;
              DAT_140e44224 = 0x200;
              DAT_140e44228 = 0x800;
            }
            if (DAT_140e441cc == 3) {
              _DAT_140e44210 = _DAT_14053b810;
              _DAT_140e44218 = _UNK_14053b818;
              DAT_140e44220 = 0x20;
              DAT_140e44224 = 0x200;
              DAT_140e44228 = 0x2000;
            }
            else {
              if (DAT_140e441cc != 4) goto LAB_1401033bc;
              _DAT_140e44210 = _DAT_14053b780;
              _DAT_140e44218 = _UNK_14053b788;
              DAT_140e44220 = 0x40;
              DAT_140e44224 = 0x200;
              DAT_140e44228 = 0x2000;
            }
          }
          else {
LAB_1401033bc:
            if (DAT_140e441cc == 5) {
              _DAT_140e441d0 = _DAT_14053b8e0;
              _DAT_140e441d8 = _UNK_14053b8e8;
              _DAT_140e441e0 = _DAT_14053b800;
              _DAT_140e441e8 = _UNK_14053b808;
              DAT_140e441f0 = 0x2e;
              DAT_140e441f4 = 0x2a;
              DAT_140e441f8 = 1;
            }
          }
        }
        if (DAT_140e45274 == 0xc) {
          DAT_140e45fac = 1;
        }
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
        FUN_14018a340(DAT_140e47204,1,1);
      }
      DAT_140e467fc = 1;
    }
    if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
      if (DAT_140e45274 == 0xc) {
        DAT_140e45fac = 1;
      }
      else {
        DAT_140e45274 = 0xc;
        DAT_140e46014 = 1;
      }
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
      FUN_14018a340(DAT_140e47208,1,1);
    }
  }
  if ((((int)DAT_140e45274 < 0xb) && (DAT_140e46064 == 1)) && (DAT_140e467fc == 0)) {
    if ((int)DAT_140e441cc < 5) {
      lVar20 = 0x1c;
      puVar18 = local_2d8;
      do {
        uVar17 = DAT_140e47204;
        uVar13 = *puVar18;
        if (((uVar12 & uVar13) != 0) && ((uVar12 & 0xf) == 0)) {
          uVar1 = (&DAT_140e44200)[(int)DAT_140e45274];
          if (DAT_140e45274 == 4 || DAT_140e45274 == 5) {
            if (DAT_140e44210 == uVar13) {
              _DAT_140e44210 = CONCAT44(DAT_140e44214,uVar1);
            }
            if (DAT_140e44214 == uVar13) {
              _DAT_140e44210 = CONCAT44(uVar1,DAT_140e44210);
            }
          }
          if (5 < (int)DAT_140e45274) {
            if (DAT_140e44218 == uVar13) {
              _DAT_140e44218 = CONCAT44(DAT_140e4421c,uVar1);
            }
            if (DAT_140e4421c == uVar13) {
              _DAT_140e44218 = CONCAT44(uVar1,DAT_140e44218);
            }
            if (DAT_140e44220 == uVar13) {
              DAT_140e44220 = uVar1;
            }
            if (DAT_140e44224 == uVar13) {
              DAT_140e44224 = uVar1;
            }
            if (DAT_140e44228 == uVar13) {
              DAT_140e44228 = uVar1;
            }
          }
          (&DAT_140e44200)[(int)DAT_140e45274] = uVar13;
          DAT_140e46064 = 0;
          DAT_140e467fc = 1;
          FUN_140184700(DAT_140e44190 * 0x19,uVar17);
          FUN_14018a340(DAT_140e47204,1,1);
        }
        puVar18 = puVar18 + 1;
        lVar20 = lVar20 + -1;
      } while (lVar20 != 0);
    }
    if (DAT_140e441cc == 5) {
      puVar18 = local_2d8 + 0x1c;
      lVar20 = 100;
      do {
        uVar12 = *puVar18;
        iVar14 = FUN_14019d900(uVar12);
        if (iVar14 == 1) {
          uVar13 = (&DAT_140e441d0)[(int)DAT_140e45274];
          if ((int)DAT_140e45274 < 4) {
            if (DAT_140e441d0 == uVar12) {
              _DAT_140e441d0 = CONCAT44(DAT_140e441d4,uVar13);
            }
            if (DAT_140e441d4 == uVar12) {
              _DAT_140e441d0 = CONCAT44(uVar13,DAT_140e441d0);
            }
            if (DAT_140e441d8 == uVar12) {
              _DAT_140e441d8 = CONCAT44(DAT_140e441dc,uVar13);
            }
            if (DAT_140e441dc == uVar12) {
              _DAT_140e441d8 = CONCAT44(uVar13,DAT_140e441d8);
            }
          }
          if (DAT_140e45274 == 4 || DAT_140e45274 == 5) {
            if (DAT_140e441e0 == uVar12) {
              _DAT_140e441e0 = CONCAT44(DAT_140e441e4,uVar13);
            }
            if (DAT_140e441e4 == uVar12) {
              _DAT_140e441e0 = CONCAT44(uVar13,DAT_140e441e0);
            }
          }
          if (5 < (int)DAT_140e45274) {
            if (DAT_140e441e8 == uVar12) {
              _DAT_140e441e8 = CONCAT44(DAT_140e441ec,uVar13);
            }
            if (DAT_140e441ec == uVar12) {
              _DAT_140e441e8 = CONCAT44(uVar13,DAT_140e441e8);
            }
            if (DAT_140e441f0 == uVar12) {
              DAT_140e441f0 = uVar13;
            }
            if (DAT_140e441f4 == uVar12) {
              DAT_140e441f4 = uVar13;
            }
            if (DAT_140e441f8 == uVar12) {
              DAT_140e441f8 = uVar13;
            }
          }
          (&DAT_140e441d0)[(int)DAT_140e45274] = uVar12;
          DAT_140e46064 = 0;
          DAT_140e46014 = 8;
          DAT_140e467fc = 1;
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
          FUN_14018a340(DAT_140e47204,1,1);
        }
        puVar18 = puVar18 + 1;
        lVar20 = lVar20 + -1;
      } while (lVar20 != 0);
    }
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
LAB_14010377c:
  uVar11 = _UNK_14053bb28;
  uVar10 = _DAT_14053bb20;
  fVar9 = DAT_14053b338;
  fVar8 = DAT_14053af40;
  uVar7 = DAT_14053af2c;
  fVar6 = DAT_14053aee8;
  uVar17 = DAT_14053aea8;
  fVar5 = DAT_14053ad20;
  fVar4 = DAT_14053acac;
  local_2e8 = 0;
  local_d8 = (FILE *)0x0;
  do {
    pFVar22 = local_d8;
    uVar12 = local_2e8;
    uVar15 = DAT_140e473e0;
    iVar14 = 0x60;
    local_2e4 = 0x60;
    fVar26 = (float)(int)local_2e8 * fVar4 + fVar5;
    if (DAT_140e45274 == local_2e8) {
      if (DAT_140e45fac != 0) {
        uVar13 = DAT_140e45fac + 10000U & 0x80000003;
        if ((int)uVar13 < 0) {
          uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar13) goto LAB_140103834;
      }
      iVar14 = 0xff;
      local_2e4 = 0xff;
    }
LAB_140103834:
    uVar19 = 0xff;
    if ((int)DAT_140e441cc < 5) {
      uVar19 = 0xff;
      if (local_2e8 < 4) {
        uVar19 = 0x80;
      }
    }
    puVar16 = DAT_140e46c88;
    if (local_2e8 == 0) {
      puVar16 = (undefined4 *)_malloc_base(0x48);
      if (puVar16 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar16 = uVar15;
      puVar16[1] = 0x7a;
      puVar16[2] = 1;
      fVar25 = fVar26 - DAT_14053aca8;
      puVar16[3] = 0x440c0000;
      *(undefined2 *)(puVar16 + 5) = 0;
      *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
      puVar16[4] = fVar25;
      puVar16[10] = 0xff;
      puVar16[0xb] = 0xff;
      puVar16[0xc] = 0xff;
      puVar16[0xd] = 0xff;
      *(undefined8 *)(puVar16 + 0xe) = 1;
      *(undefined8 *)(puVar16 + 0x10) = 0;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar16;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
      }
      uVar15 = (&DAT_140e473e0)[(int)(DAT_140e441cc + 1)];
      DAT_140e46c88 = puVar16;
      puVar16 = (undefined4 *)_malloc_base(0x48);
      if (puVar16 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar16 = uVar15;
      puVar16[4] = fVar25;
      *(undefined2 *)(puVar16 + 5) = 0;
      *(undefined8 *)(puVar16 + 0x10) = 0;
      puVar16[1] = 0x7a;
      puVar16[2] = 1;
      puVar16[3] = 0x443e0000;
      *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
      puVar16[10] = 0xff;
      puVar16[0xb] = 0xff;
      puVar16[0xc] = 0xff;
      puVar16[0xd] = 0xff;
      *(undefined8 *)(puVar16 + 0xe) = 1;
      _DAT_140e46e78 = _DAT_140e46e78 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar16;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
      }
    }
    DAT_140e46c88 = puVar16;
    if (pFVar22 < (FILE *)0xb) {
      local_2f0 = 0;
      local_2f8 = 1;
      local_328 = uVar10;
      uStack_320 = uVar11;
      local_330 = local_330 & 0xffff0000;
      local_338 = fVar26;
      local_318 = uVar19;
      local_310 = uVar19;
      local_308 = uVar19;
      local_300 = iVar14;
      FUN_1400c8410((&DAT_140e473fc)[(longlong)pFVar22],0x7a,1,uVar17);
      if (((DAT_140e46064 == 0) || (DAT_140e45274 != uVar12)) &&
         ((3 < uVar12 || (DAT_140e441cc == 5)))) {
        if (DAT_140e441cc == 0) {
          local_2f0 = 0;
          local_2f8 = 1;
          local_300 = 0xff;
          local_328 = uVar10;
          uStack_320 = uVar11;
          local_330 = local_330 & 0xffff0000;
          local_338 = fVar26;
          local_318 = uVar19;
          local_310 = uVar19;
          local_308 = uVar19;
          FUN_1400c8410(DAT_140e4742c,0x7a,1,uVar7);
          iVar2 = (&DAT_140e44200)[(longlong)pFVar22];
          uVar13 = (uint)(iVar2 == 0x10);
          if (iVar2 == 0x20) {
            uVar13 = 2;
LAB_140103ac7:
            if (iVar2 == 0x4000000) {
              uVar13 = 0x17;
            }
            else {
LAB_140103ae2:
              if (iVar2 == 0x8000000) {
                uVar13 = 0x18;
              }
              else {
LAB_140103afe:
                if (iVar2 == 0x10000000) {
                  uVar13 = 0x19;
                }
                else {
LAB_140103b18:
                  if (iVar2 == 0x20000000) {
                    uVar13 = 0x1a;
                  }
                  else {
LAB_140103b32:
                    if (iVar2 != 0x40000000) goto LAB_140103b50;
                    uVar13 = 0x1b;
                  }
                }
              }
            }
          }
          else {
            if (iVar2 == 0x40) {
              uVar13 = 3;
              goto LAB_140103ae2;
            }
            if (iVar2 == 0x80) {
              uVar13 = 4;
              goto LAB_140103afe;
            }
            if (iVar2 == 0x100) {
              uVar13 = 5;
              goto LAB_140103b18;
            }
            if (iVar2 == 0x200) {
              uVar13 = 6;
              goto LAB_140103b32;
            }
            if (iVar2 != 0x400) {
              if (iVar2 == 0x800) {
                uVar13 = 8;
              }
              else if (iVar2 == 0x1000) {
                uVar13 = 9;
              }
              else if (iVar2 == 0x2000) {
                uVar13 = 10;
              }
              else if (iVar2 == 0x4000) {
                uVar13 = 0xb;
              }
              else if (iVar2 == 0x8000) {
                uVar13 = 0xc;
              }
              else if (iVar2 == 0x10000) {
                uVar13 = 0xd;
              }
              else if (iVar2 == 0x20000) {
                uVar13 = 0xe;
              }
              else if (iVar2 == 0x40000) {
                uVar13 = 0xf;
              }
              else if (iVar2 == 0x80000) {
                uVar13 = 0x10;
              }
              else if (iVar2 == 0x100000) {
                uVar13 = 0x11;
              }
              else if (iVar2 == 0x200000) {
                uVar13 = 0x12;
              }
              else if (iVar2 == 0x400000) {
                uVar13 = 0x13;
              }
              else if (iVar2 == 0x800000) {
                uVar13 = 0x14;
              }
              else if (iVar2 == 0x1000000) {
                uVar13 = 0x15;
              }
              else {
                if (iVar2 != 0x2000000) goto LAB_140103ac7;
                uVar13 = 0x16;
              }
              goto LAB_140103b5d;
            }
            uVar13 = 7;
LAB_140103b50:
            if (iVar2 == -0x80000000) {
              uVar13 = 0x1c;
            }
          }
LAB_140103b5d:
          uVar21 = (ulonglong)(int)uVar13;
          if (9 < uVar21) {
            local_2f0 = 0;
            local_2f8 = 1;
            local_300 = 0xff;
            local_308 = 0xff;
            local_310 = 0xff;
            local_318 = 0xff;
            local_328 = uVar10;
            uStack_320 = uVar11;
            local_330 = local_330 & 0xffff0000;
            local_338 = fVar26;
            FUN_1400c8410((&DAT_140e46c30)[(int)(uVar13 + (int)(uVar21 / 10) * -10)],0x7a,1,fVar8);
            uVar21 = uVar21 / 10;
            fVar25 = DAT_14053af30;
            do {
              local_2f0 = 0;
              local_2f8 = 1;
              local_300 = 0xff;
              local_308 = 0xff;
              local_310 = 0xff;
              local_318 = 0xff;
              local_328 = uVar10;
              uStack_320 = uVar11;
              local_330 = local_330 & 0xffff0000;
              local_338 = fVar26;
              FUN_1400c8410((&DAT_140e46c30)[(int)uVar21],0x7a,1,fVar25);
              fVar25 = fVar25 + fVar9;
              bVar23 = 9 < uVar21;
              uVar21 = 0;
              pFVar22 = local_d8;
              iVar14 = local_2e4;
              uVar12 = local_2e8;
            } while (bVar23);
            goto LAB_140103e19;
          }
          uVar15 = (&DAT_140e46c30)[uVar21];
          local_308 = 0xff;
          fVar25 = fVar8;
        }
        else {
          uVar15 = FUN_1400dacb0(uVar12);
          fVar25 = fVar6;
          local_308 = uVar19;
        }
        local_2f0 = 0;
        local_2f8 = 1;
        local_300 = 0xff;
        local_328 = uVar10;
        uStack_320 = uVar11;
        local_330 = local_330 & 0xffff0000;
        local_338 = fVar26;
        local_318 = local_308;
        local_310 = local_308;
        FUN_1400c8410(uVar15,0x7a,1,fVar25);
      }
LAB_140103e19:
      if ((DAT_140e46064 == 1) && (DAT_140e45274 == uVar12)) {
        dVar24 = (double)FUN_140332d90(((double)DAT_140e451bc - 0.0) * DAT_14053a930 * DAT_14053a020
                                       * DAT_140539d28);
        local_2f0 = 0;
        local_2f8 = 1;
        local_300 = 0x80 - (int)(dVar24 * DAT_14053b1c8);
        local_328 = uVar10;
        uStack_320 = uVar11;
        local_330 = local_330 & 0xffff0000;
        local_338 = fVar26;
        local_318 = uVar19;
        local_310 = uVar19;
        local_308 = uVar19;
        FUN_1400c8410(DAT_140e47430,0x7a,1,uVar7);
      }
    }
    if (uVar12 == 0xb) {
      local_2f0 = 0;
      local_2f8 = 1;
      local_328 = uVar10;
      uStack_320 = uVar11;
      local_330 = local_330 & 0xffff0000;
      local_338 = fVar26;
      local_318 = uVar19;
      local_310 = uVar19;
      local_308 = uVar19;
      local_300 = iVar14;
      FUN_1400c8410(DAT_140e47428,0x7a,1,uVar17);
    }
    if (pFVar22 == (FILE *)0xc) {
      local_2f0 = 0;
      local_2f8 = 1;
      local_328 = uVar10;
      uStack_320 = uVar11;
      local_330 = local_330 & 0xffff0000;
      local_338 = fVar26;
      local_318 = uVar19;
      local_310 = uVar19;
      local_308 = uVar19;
      local_300 = iVar14;
      FUN_1400c8410(DAT_140e47360,0x7a,1,uVar17);
      goto LAB_140103f65;
    }
    local_2e8 = uVar12 + 1;
    local_d8 = (FILE *)((longlong)&pFVar22->_ptr + 1);
    if (0xc < (longlong)local_d8) {
LAB_140103f65:
      if (DAT_140e46064 == 0) {
        FUN_1400d9b60(0,0x70,0xff);
      }
      if (DAT_140e46064 == 1) {
        FUN_1400d9b60(2,0x70,0xff);
      }
      if (DAT_140e45270 == 0xd) {
        lVar20 = DAT_140e47908;
        if ((DAT_140e418c8 == 1) || (DAT_140e46014 == 1)) {
          while (lVar20 != 0) {
            lVar20 = *(longlong *)(lVar20 + 0x238);
            FUN_140323ce8();
          }
          local_2f8 = 5;
          local_300 = 1;
          local_308 = 0;
          local_310 = 0xff;
          local_318 = 0xff;
          uVar21 = (ulonglong)uStack_320 >> 0x20;
          uStack_320 = CONCAT44((int)uVar21,0xff);
          uVar21 = (ulonglong)local_328 >> 0x20;
          local_328 = CONCAT44((int)uVar21,DAT_14053ac80);
          local_338 = fVar6;
          DAT_140e47908 = 0;
          DAT_140e9fd30 = 0;
          local_330 = DAT_14053ac34;
          FUN_14012e070(DAT_140e45274 + 0xd6,0);
        }
        if (0x13 < DAT_140e45fac) {
          FUN_1400d3fd0(DAT_140e45fac + -0x14);
        }
        if (DAT_140e45fac == 0x32) {
          DAT_140e45274 = 6;
          DAT_140e418c8 = 0;
          DAT_140e45fac = 0;
          DAT_140e46014 = 0;
          DAT_140e45270 = 10;
          fopen_s(&local_d8,"save\\save.dat","wb");
          FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
          FUN_140323e90(local_d8);
          DAT_140e471fc = 0xb4;
        }
      }
      if ((DAT_140e45270 == 0x1a) && (DAT_140e45fac == 0x32)) {
        DAT_140e45274 = 5;
        DAT_140e45fac = 0;
        DAT_140e46014 = 0;
        DAT_140e45270 = 0x18;
        fopen_s(&local_d8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
        FUN_140323e90(local_d8);
        DAT_140e471fc = 0xb4;
      }
      if (0 < DAT_140e45fac) {
        DAT_140e45fac = DAT_140e45fac + 1;
      }
      if (0 < DAT_140e46014) {
        DAT_140e46014 = DAT_140e46014 + -1;
      }
      if (DAT_140e45270 == 0xd) {
        DAT_140e418c8 = DAT_140e418c8 + 1;
      }
      return;
    }
  } while( true );
}


