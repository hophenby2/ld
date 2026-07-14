// Function: FUN_140002260 @ 140002260
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002260(void)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  double dVar20;
  double dVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  double dVar24;
  double dVar25;
  longlong lStack_130;
  undefined8 local_128;
  ulonglong uStack_120;
  
  iVar16 = DAT_140e419bc;
  dVar4 = DAT_14053a5f8;
  dVar20 = DAT_14053a020;
  dVar3 = DAT_140539f40;
  iVar18 = 0;
  iVar12 = 0;
  uStack_120 = (ulonglong)(uint)uStack_120;
  lVar2 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        lStack_130 = *(longlong *)(lVar2 + 8);
        local_128 = *(undefined8 *)(lVar2 + 0x10);
        uStack_120 = *(ulonglong *)(lVar2 + 0x18);
      }
    }
  }
  iVar13 = 0x40;
  iVar15 = 0xff;
  iVar17 = 0x40;
  iVar14 = 0x40;
  dVar24 = (double)DAT_140e41b0c;
  iVar8 = (int)(uStack_120 >> 0x20);
  dVar25 = (double)iVar8 / dVar24;
  if (iVar8 == 0 || (longlong)uStack_120 < 0) {
    dVar25 = 0.0;
  }
  if (DAT_14053ad70 <= DAT_140e445dc) {
    if (DAT_140e445dc < DAT_14053adb4) {
      iVar15 = (int)(DAT_140e445dc - DAT_14053ad70) * 4 + 0x37;
    }
  }
  else {
    iVar15 = 0x37;
  }
  uVar22 = SUB84(DAT_140539d28,0);
  uVar23 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  iVar9 = (int)((ulonglong)lStack_130 >> 0x20);
  if ((DAT_140e419bc == 0) || (DAT_140e419bc == 6)) {
    dVar25 = (double)iVar9 * DAT_140539de8;
    iVar15 = 0;
    if (-1 < lStack_130) {
      if (iVar9 < 8) {
        dVar21 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053aa28 * DAT_14053a020 *
                                       DAT_140539d28);
        uVar22 = SUB84(DAT_140539d28,0);
        uVar23 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
        iVar15 = (int)(dVar21 * dVar4);
      }
      else {
        iVar15 = 0xff;
        if (0x31 < iVar9) {
          dVar25 = DAT_140539f40;
        }
      }
    }
    if (iVar16 != 0) goto LAB_140002425;
    iVar17 = 0xff;
    iVar14 = iVar17;
    iVar13 = 0;
  }
  else {
LAB_140002425:
    if (iVar16 == 1) {
      iVar17 = 0xff;
      iVar14 = (int)((dVar25 - DAT_140539f00) * DAT_14053a768);
      iVar13 = 0;
      if (dVar25 <= DAT_140539f00) {
        iVar17 = (int)(dVar25 * DAT_14053a768);
        iVar14 = iVar12;
        iVar13 = (int)(dVar4 - dVar25 * DAT_14053a768);
      }
    }
    else {
      if ((iVar16 - 2U & 0xfffffffd) == 0) {
        if (iVar9 - 0x28U < 0x1e) {
          dVar25 = ((double)iVar9 - DAT_14053a340) * _DAT_140539e10;
        }
        else {
          dVar25 = 0.0;
          if (0x45 < iVar9) {
            dVar25 = dVar3;
          }
        }
        if (iVar16 == 2) {
          iVar17 = 0xff;
          iVar14 = 0xff;
          iVar13 = iVar12;
          goto LAB_140002572;
        }
      }
      iVar7 = iVar18;
      if (iVar16 == 3) {
LAB_14000256e:
        iVar12 = iVar7;
        dVar25 = 0.0;
      }
      else if (iVar16 == 5) {
        dVar25 = (double)DAT_140e4430c / dVar24;
      }
      else if (iVar16 == -1) {
        iVar7 = 0;
        if (-1 < lStack_130) {
          if (iVar9 < 0x20) {
            dVar20 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053a778 * dVar20 *
                                           (double)CONCAT44(uVar23,uVar22));
            iVar7 = (int)(dVar20 * dVar4);
          }
          else {
            iVar15 = iVar18;
            iVar7 = 0;
            if (iVar9 < 0x40) {
              dVar20 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053a778 * dVar20 *
                                             (double)CONCAT44(uVar23,uVar22));
              iVar7 = (int)(dVar20 * dVar4);
            }
          }
        }
        goto LAB_14000256e;
      }
    }
  }
LAB_140002572:
  uVar22 = DAT_140e44598;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar22;
  *(undefined8 *)(puVar11 + 1) = 0x73;
  puVar11[3] = 0x43bd0000;
  puVar11[4] = 0x41f00000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = iVar15;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  uVar22 = DAT_140e4459c;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar22;
  *(undefined8 *)(puVar11 + 1) = 0x73;
  puVar11[3] = 0x43c90000;
  puVar11[4] = 0x41f00000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = iVar15;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar22 = DAT_140e44598;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar22;
  puVar11[2] = 5;
  puVar11[1] = 0x73;
  puVar11[3] = 0x43bd0000;
  puVar11[4] = 0x41f00000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = iVar12;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar22 = DAT_140e4459c;
  DAT_140e46c88 = puVar11;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  *puVar11 = uVar22;
  iVar16 = 0;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[1] = 0x73;
  puVar11[2] = 5;
  puVar11[3] = 0x43c90000;
  puVar11[4] = 0x41f00000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = iVar12;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  uVar23 = DAT_14053ae44;
  uVar22 = DAT_14053ac80;
  DAT_140e46c88 = puVar11;
  FUN_1400c8410(DAT_140e445a0,0x71,0,DAT_14053ae44,DAT_14053ac80,0,dVar25,dVar3,0xff,0xff,0xff,
                iVar15,1,0);
  FUN_1400c8410(DAT_140e445a4,0x72,5,uVar23,uVar22,0,dVar25,dVar3,iVar13,iVar17,iVar14,iVar15,1,0);
  iVar12 = 5;
  switch((int)uStack_120) {
  default:
    iVar12 = iVar16;
    break;
  case 0x139:
    iVar12 = 1;
    break;
  case 0x13a:
    iVar12 = 2;
    break;
  case 0x13b:
    iVar12 = 3;
    break;
  case 0x13c:
    iVar12 = 4;
    break;
  case 0x13d:
    iVar12 = 6;
    break;
  case 0x13e:
    iVar12 = 9;
    if ((local_128._4_4_ - 0x15U < 0x13) || (local_128._4_4_ == 0x3b)) {
      iVar12 = 7;
    }
    if ((0x11 < local_128._4_4_ - 0x29U) && (local_128._4_4_ != 0x3c)) break;
  case 0x145:
    iVar12 = 8;
    break;
  case 0x140:
    if (10 < local_128._4_4_) {
      iVar12 = (3 < DAT_140e419b8) + 0x11;
      break;
    }
  case 0x13f:
    iVar12 = 10;
    break;
  case 0x141:
  case 0x14c:
    iVar12 = 0x13;
    break;
  case 0x143:
    break;
  case 0x144:
    iVar12 = 7;
    break;
  case 0x146:
    iVar12 = 0xb;
    break;
  case 0x147:
    iVar12 = 0xc;
    break;
  case 0x148:
    iVar12 = 0xd;
    break;
  case 0x149:
    iVar12 = 0xe;
    break;
  case 0x14a:
    iVar12 = 0xf;
    break;
  case 0x14b:
    iVar12 = 0x10;
  }
  uVar22 = *(undefined4 *)(&DAT_140e418d0 + (longlong)iVar12 * 4);
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e5c = _DAT_140e46e5c + 1;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar11 = uVar22;
  *(undefined8 *)(puVar11 + 1) = 0x73;
  *(undefined8 *)(puVar11 + 3) = 0x43ba0000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  puVar11[0xd] = iVar15;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
  }
  dVar25 = DAT_14053b0a8;
  fVar6 = DAT_14053ae48;
  fVar5 = DAT_14053ac58;
  dVar20 = DAT_14053a018;
  iVar12 = iVar16;
  DAT_140e46c88 = puVar11;
  if (0 < DAT_140e41af8) {
    do {
      iVar18 = iVar15;
      dVar24 = dVar3;
      if (DAT_140e419bc == 0) {
        iVar18 = 0;
        if ((iVar12 <= iVar9) && (iVar18 = iVar15, iVar9 < iVar12 + 0x14)) {
          dVar21 = (double)FUN_140332d90();
          dVar24 = (double)FUN_140332d90();
          dVar24 = dVar24 * dVar25 + dVar20;
          iVar18 = (int)(dVar21 * dVar4);
        }
        if (iVar9 == iVar12 + 0x14) {
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e472b4);
          FUN_14018a340(DAT_140e472b4,1,1);
        }
      }
      uVar22 = DAT_140e445b4;
      puVar11 = (undefined4 *)_malloc_base(0x48);
      if (puVar11 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar11 = uVar22;
      puVar11[1] = 0x73;
      puVar11[2] = 1;
      puVar11[4] = 0x42940000;
      *(undefined2 *)(puVar11 + 5) = 0;
      auVar1._8_4_ = SUB84(dVar24,0);
      auVar1._0_8_ = dVar24;
      auVar1._12_4_ = (int)((ulonglong)dVar24 >> 0x20);
      *(undefined1 (*) [16])(puVar11 + 6) = auVar1;
      puVar11[10] = 0xff;
      puVar11[0xb] = 0xff;
      puVar11[0xc] = 0xff;
      puVar11[0xd] = iVar18;
      *(undefined8 *)(puVar11 + 0xe) = 1;
      *(undefined8 *)(puVar11 + 0x10) = 0;
      puVar11[3] = (float)iVar16 * fVar5 + fVar6;
      _DAT_140e46e5c = _DAT_140e46e5c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar11;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
      }
      iVar16 = iVar16 + 1;
      iVar12 = iVar12 + 6;
      DAT_140e46c88 = puVar11;
    } while (iVar16 < DAT_140e41af8);
  }
  if ((DAT_140e419bc - 1U & 0xfffffffb) == 0) {
    if (DAT_140e4430c < 6000) {
      iVar16 = DAT_140e4430c;
      iVar12 = 0xff;
      if (DAT_140e4430c < 0xff) {
        iVar12 = DAT_140e4430c;
      }
    }
    else {
      iVar16 = 5999;
      iVar12 = 0xff;
    }
    iVar18 = iVar16 % 0x3c;
    uVar22 = (&DAT_140e41980)[iVar18 / 10];
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e58 = _DAT_140e46e58 + 1;
    *puVar11 = uVar22;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar11[1] = 0x72;
    puVar11[2] = 1;
    puVar11[3] = 0x445d4000;
    puVar11[4] = 0x41a00000;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3fe3333333333333;
    *(undefined8 *)(puVar11 + 8) = 0x3fe3333333333333;
    puVar11[10] = 0xff;
    puVar11[0xb] = iVar12;
    puVar11[0xc] = iVar12;
    puVar11[0xd] = iVar15;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    uVar22 = (&DAT_140e41980)[iVar18 % 10];
    DAT_140e46c88 = puVar11;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e58 = _DAT_140e46e58 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar11 = uVar22;
    puVar11[1] = 0x72;
    puVar11[2] = 1;
    puVar11[3] = 0x445fc000;
    puVar11[4] = 0x41a00000;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3fe3333333333333;
    *(undefined8 *)(puVar11 + 8) = 0x3fe3333333333333;
    puVar11[10] = 0xff;
    puVar11[0xb] = iVar12;
    puVar11[0xc] = iVar12;
    puVar11[0xd] = iVar15;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    uVar22 = (&DAT_140e41980)[(iVar16 / 0x3c) / 10];
    DAT_140e46c88 = puVar11;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e58 = _DAT_140e46e58 + 1;
    *puVar11 = uVar22;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar11[1] = 0x72;
    puVar11[2] = 1;
    puVar11[3] = 0x44558000;
    puVar11[4] = 0x41800000;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = iVar12;
    puVar11[0xc] = iVar12;
    puVar11[0xd] = iVar15;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    uVar22 = (&DAT_140e41980)[(iVar16 / 0x3c) % 10];
    DAT_140e46c88 = puVar11;
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e58 = _DAT_140e46e58 + 1;
    bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar11 = uVar22;
    puVar11[1] = 0x72;
    puVar11[2] = 1;
    puVar11[3] = 0x44598000;
    puVar11[4] = 0x41800000;
    *(undefined2 *)(puVar11 + 5) = 0;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    puVar11[10] = 0xff;
    puVar11[0xb] = iVar12;
    puVar11[0xc] = iVar12;
    puVar11[0xd] = iVar15;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    if (bVar19) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    DAT_140e46c88 = puVar11;
    if ((DAT_140e419bc == 1) && (iVar8 < 0x1f41)) {
      uVar10 = DAT_140e418c8 & 0x8000000f;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff0) + 1;
      }
      if (uVar10 == 0) {
        FUN_140184700(DAT_140e44190 << 4,DAT_140e4730c);
        FUN_14018a340(DAT_140e4730c,1,1);
      }
    }
    if ((iVar16 - 0x168U < 0xf1) && (iVar18 == 0)) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e47310);
      FUN_14018a340(DAT_140e47310,1,1);
    }
    if ((iVar16 - 1U < 300) && (iVar18 == 0)) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47310);
      FUN_14018a340(DAT_140e47310,1,1);
    }
    DAT_140e4430c = DAT_140e4430c + -1;
  }
  return;
}


