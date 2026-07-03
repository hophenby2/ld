// Function: state_01_opening_attract_candidate @ 1400f7570
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_01_opening_attract_candidate(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  double dVar5;
  float fVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  longlong lVar15;
  undefined8 *puVar16;
  int iVar17;
  int iVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  undefined4 *puVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  undefined4 uVar31;
  int iVar32;
  undefined4 *puVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  int *piVar36;
  bool bVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  double dVar41;
  double dVar42;
  double dVar43;
  double dVar44;
  float fVar45;
  float fVar46;
  double dVar47;
  double dVar48;
  float fVar49;
  uint local_res8;
  uint local_res10;
  undefined4 *local_res20;
  uint in_stack_fffffffffffffe90;
  ushort uVar50;
  undefined1 in_stack_fffffffffffffea0 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  uint uStack_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  
  uVar20 = 0;
  local_118 = _DAT_14053b980;
  uStack_110 = _UNK_14053b988;
  local_108 = 0xc80;
  local_104 = 4000;
  local_res8 = (uint)(799 < (int)DAT_140e418c8);
  uVar25 = DAT_140e418c8 - 800;
  if ((int)DAT_140e418c8 < 800) {
    uVar25 = DAT_140e418c8;
  }
  if (0x577 < (int)DAT_140e418c8) {
    uVar25 = DAT_140e418c8 - 0x578;
    local_res8 = local_res8 + 1;
  }
  if (1999 < (int)DAT_140e418c8) {
    uVar25 = DAT_140e418c8 - 2000;
    local_res8 = local_res8 + 1;
  }
  if (0xa27 < (int)DAT_140e418c8) {
    local_res8 = local_res8 + 1;
    uVar25 = DAT_140e418c8 - 0xa28;
  }
  if (0xc7f < (int)DAT_140e418c8) {
    local_res8 = local_res8 + 1;
    uVar25 = DAT_140e418c8 - 0xc80;
  }
  puVar24 = &DAT_140e45100;
  if (DAT_140e418c8 == 1) {
    puVar33 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar33,0);
      puVar33 = puVar33 + 1;
    } while ((longlong)puVar33 < 0x140e45178);
  }
  fVar46 = DAT_14053ac64;
  if (DAT_140e418c8 == 0xb4) {
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e45104);
    FUN_14018a340(DAT_140e45104,3,1);
    DAT_140e45100 = DAT_140e45104;
  }
  if (DAT_140e45fac == 0) {
    if ((DAT_140e467c8 == 1) && ((int)DAT_140e418c8 < 0xeec)) {
      do {
        FUN_14018f230(*puVar24,0);
        puVar24 = puVar24 + 1;
      } while ((longlong)puVar24 < 0x140e45178);
      FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    if (DAT_140e418c8 == 0xf6e) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
  }
  uVar13 = DAT_140e474c8;
  uVar12 = DAT_140e474bc;
  uVar11 = DAT_140e474a8;
  uVar10 = DAT_140e47498;
  uVar2 = DAT_140e47490;
  uVar1 = DAT_140e47480;
  uVar31 = DAT_140e41ab8;
  dVar5 = DAT_14053a020;
  dVar44 = DAT_140539d28;
  if (5 < local_res8) {
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar1;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    goto LAB_1400fa99d;
  }
  uVar14 = (int)uVar25 >> 0x1f;
  switch(local_res8) {
  case 0:
    puVar24 = DAT_140e46c88;
    if ((int)uVar25 < 0x20) {
      puVar24 = (undefined4 *)_malloc_base(0x48);
      if (puVar24 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e70 = _DAT_140e46e70 + 1;
      *puVar24 = uVar31;
      *(undefined8 *)(puVar24 + 1) = 0x78;
      bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
      *(undefined8 *)(puVar24 + 3) = 0;
      *(undefined2 *)(puVar24 + 5) = 0;
      *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
      *(undefined8 *)(puVar24 + 10) = 0;
      puVar24[0xc] = 0;
      puVar24[0xd] = uVar25 * -8 + 0xff;
      *(undefined8 *)(puVar24 + 0xe) = 1;
      *(undefined8 *)(puVar24 + 0x10) = 0;
      if (bVar37) {
        DAT_140e46bf0 = puVar24;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
      }
    }
    DAT_140e46c88 = puVar24;
    uVar31 = DAT_140e47480;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar31;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    dVar43 = DAT_140539f40;
    DAT_140e46c88 = puVar24;
    if ((int)uVar25 < 0xf0) {
      iVar28 = 0xff;
      if (uVar25 - 0xb4 < 0x3c) {
        dVar40 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a4a0) * DAT_14053a628 * dVar5
                                       * dVar44);
        iVar28 = (int)(dVar40 * DAT_14053a5f8);
      }
      uVar31 = DAT_140e41ab8;
      puVar24 = (undefined4 *)_malloc_base(0x48);
      if (puVar24 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46ce0 = _DAT_140e46ce0 + 1;
      bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar24 = uVar31;
      *(undefined8 *)(puVar24 + 1) = 0x14;
      *(undefined8 *)(puVar24 + 3) = 0;
      *(undefined2 *)(puVar24 + 5) = 0;
      *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
      puVar24[10] = 0xff;
      puVar24[0xb] = 0x80;
      puVar24[0xc] = 0x40;
      puVar24[0xd] = iVar28;
      *(undefined8 *)(puVar24 + 0xe) = 1;
      *(undefined8 *)(puVar24 + 0x10) = 0;
      if (bVar37) {
        DAT_140e46bf0 = puVar24;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
      }
      uVar30 = uVar20;
      DAT_140e46c88 = puVar24;
      do {
        uVar23 = (uint)uVar30;
        uVar14 = uVar23 * 8 + 0x1e;
        if (((int)uVar14 <= (int)uVar25) && ((int)uVar25 < (int)(uVar23 * 8 + 0x28))) {
          FUN_140332d90(((double)(int)uVar25 - (double)(int)uVar14) * DAT_14053a9d8 * dVar5 * dVar44
                       );
        }
        if (uVar23 < 7) {
          FUN_1403307c0();
          FUN_140332d90();
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
          FUN_1400c8410(DAT_140e41930,0x15,1);
          if ((uVar25 == uVar14) && (DAT_140e45fac == 0)) {
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e4731c);
            FUN_14018a340(DAT_140e4731c,1,1);
          }
        }
        else if (uVar23 == 7) {
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
          FUN_1400c8410(DAT_140e41a78,0x15,1);
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
          FUN_1400c8410(DAT_140e41a7c,0x15,1);
          if ((uVar25 == 0x56) && (DAT_140e45fac == 0)) {
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47320);
            FUN_14018a340(DAT_140e47320,1,1);
            break;
          }
        }
        uVar30 = (ulonglong)(uVar23 + 1);
      } while ((int)(uVar23 + 1) < 8);
    }
    dVar40 = DAT_14053a9d8;
    piVar36 = &DAT_140e46c98;
    puVar24 = &DAT_140e47484;
    dVar47 = (double)(int)uVar25;
    uVar30 = uVar20;
LAB_1400f7ceb:
    do {
      iVar32 = (int)uVar30;
      iVar28 = iVar32 * 0x14;
      iVar22 = 0x168;
      iVar18 = (int)uVar20;
      iVar17 = iVar18 + 200;
      if (((iVar17 != iVar28 + 0x104) && (iVar22 = 0x438, iVar17 <= (int)uVar25)) &&
         (iVar22 = 0x168, (int)uVar25 < iVar28 + 0x104)) {
        dVar39 = (double)FUN_140332d90((dVar47 - (double)iVar17) * DAT_14053a628 * dVar5 * dVar44);
        iVar22 = 0x438 - (int)(dVar39 * DAT_14053a848);
      }
      dVar39 = (double)FUN_140332d90((dVar47 - (double)(iVar32 * 0x24 + 200)) * DAT_14053a798 *
                                     dVar5 * dVar44);
      fVar46 = (float)(dVar39 * DAT_14053a1e8) + DAT_14053ac2c;
      if (iVar32 < 3) {
        uVar31 = *puVar24;
        puVar33 = (undefined4 *)_malloc_base(0x48);
        if (puVar33 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar33 = uVar31;
        puVar33[4] = fVar46 + (float)iVar22;
        puVar33[1] = iVar32 * 3 + 2;
        puVar33[2] = 1;
        puVar33[3] = 0x44200000;
        *(undefined2 *)(puVar33 + 5) = 0;
        *(undefined8 *)(puVar33 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar33 + 8) = 0x3ff0000000000000;
        puVar33[10] = 0xff;
        puVar33[0xb] = 0xff;
        puVar33[0xc] = 0xff;
        puVar33[0xd] = 0xff;
        *(undefined8 *)(puVar33 + 0xe) = 1;
        *(undefined8 *)(puVar33 + 0x10) = 0;
        *piVar36 = *piVar36 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar33;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar33;
        }
      }
      else {
        if ((iVar28 + 0x122 <= (int)uVar25) && ((int)uVar25 < iVar28 + 300)) {
          FUN_140332d90((dVar47 - (double)(iVar28 + 0x122)) * dVar40 * dVar5 * dVar44);
        }
        uVar50 = (ushort)(in_stack_fffffffffffffe90 >> 0x10);
        if (iVar32 == 3) {
          in_stack_fffffffffffffe90 = (uint)uVar50 << 0x10;
          FUN_1400c8410(DAT_140e4507c,0xb,1);
          uVar30 = 4;
          puVar24 = puVar24 + 1;
          piVar36 = piVar36 + 3;
          uVar20 = (ulonglong)(iVar18 + 0x14);
          goto LAB_1400f7ceb;
        }
        puVar33 = DAT_140e46c88;
        if (iVar32 == 4) {
          FUN_1400c8410(DAT_140e45080,0xe,1);
          break;
        }
      }
      DAT_140e46c88 = puVar33;
      uVar50 = (ushort)(in_stack_fffffffffffffe90 >> 0x10);
      uVar30 = (ulonglong)(iVar32 + 1U);
      puVar24 = puVar24 + 1;
      piVar36 = piVar36 + 3;
      uVar20 = (ulonglong)(iVar18 + 0x14);
    } while ((int)(iVar32 + 1U) < 5);
    if (0xef < (int)uVar25) {
      uVar23 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar14 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
      uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
      uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
      uVar23 = ((uVar14 >> 0xb ^ uVar23) >> 8 ^ uVar23 ^ uVar14) & 1;
      uVar14 = (DAT_140e418c8 + 0x457 >> 0x1e ^ DAT_140e418c8 + 0x457) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar14 = uVar14 * 0x800 ^ uVar14;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
      uVar14 = DAT_140e9fd1c & 1;
      puVar16 = DAT_140e45d28;
      if ((int)uVar25 % 0x14 == 0) {
        uVar21 = (DAT_140e418c8 + 0xde >> 0x1e ^ DAT_140e418c8 + 0xde) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar21 = uVar21 * 0x800 ^ uVar21;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ uVar21 ^ DAT_140e9fd18;
        if (uVar23 == 0) {
          fVar46 = DAT_14053b33c;
          fVar45 = (float)(DAT_140e9fd1c % 0x321 + 0x1e0);
        }
        else {
          fVar46 = (float)(DAT_140e9fd1c % 0x1e1);
          fVar45 = DAT_14053b010;
        }
        uVar31 = (&DAT_140e451c8)[uVar14];
        if (DAT_140e45d1c < 0x1000) {
          puVar16 = (undefined8 *)_malloc_base(0x60);
          if (puVar16 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          *(undefined4 *)(puVar16 + 2) = 4;
          *(undefined2 *)((longlong)puVar16 + 0x24) = 0x6710;
          puVar16[10] = 0xff;
LAB_1400f8374:
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar37 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)(puVar16 + 4) = fVar46;
          *(float *)((longlong)puVar16 + 0x1c) = fVar45;
          *(float *)(puVar16 + 3) = fVar46;
          *(float *)((longlong)puVar16 + 0x14) = fVar45;
          puVar16[0xb] = 0;
          *(undefined4 *)((longlong)puVar16 + 0x4c) = 0xff;
          *(undefined4 *)(puVar16 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar16 + 0x44) = 0xff;
          *(undefined4 *)(puVar16 + 8) = 0;
          puVar16[7] = 0x3ff0000000000000;
          puVar16[6] = 0x3ff0000000000000;
          puVar16[5] = 0x403e000000000000;
          *(undefined4 *)((longlong)puVar16 + 0xc) = uVar31;
          *(undefined4 *)(puVar16 + 1) = 2;
          *puVar16 = 1;
          if (bVar37) {
            DAT_140e45d78 = puVar16;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar16;
          }
        }
      }
      else if ((int)uVar25 % 0x14 == 10) {
        uVar21 = (DAT_140e418c8 + 0xde >> 0x1e ^ DAT_140e418c8 + 0xde) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar21 = uVar21 * 0x800 ^ uVar21;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar26 = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8;
        if (uVar23 == 0) {
          DAT_140e9fd1c = uVar26 ^ uVar21 ^ DAT_140e9fd18;
          fVar46 = DAT_14053af28;
          fVar45 = (float)(DAT_140e9fd1c % 0x321);
        }
        else {
          DAT_140e9fd1c = uVar26 ^ DAT_140e9fd18 ^ uVar21;
          fVar46 = (float)(DAT_140e9fd1c % 0x1e1 + 0xf0);
          fVar45 = DAT_14053b33c;
        }
        uVar31 = (&DAT_140e451c8)[uVar14];
        if (DAT_140e45d1c < 0x1000) {
          puVar16 = (undefined8 *)_malloc_base(0x60);
          if (puVar16 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          *(undefined4 *)(puVar16 + 2) = 7;
          *(undefined2 *)((longlong)puVar16 + 0x24) = 0xe710;
          puVar16[10] = 0x40;
          goto LAB_1400f8374;
        }
      }
      DAT_140e45d28 = puVar16;
      uVar14 = uVar25 & 0x8000000f;
      if ((int)uVar14 < 0) {
        uVar14 = (uVar14 - 1 | 0xfffffff0) + 1;
      }
      if (uVar14 == 0) {
        dVar43 = (double)FUN_140134db0(DAT_140e451bc + -0x29a,DAT_140539f00,dVar43);
        uVar23 = (DAT_140e418c8 + 0x6f >> 0x1e ^ DAT_140e418c8 + 0x6f) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar14 = uVar23 * 0x800 ^ uVar23;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
        auVar4._8_4_ = SUB84(dVar43,0);
        auVar4._0_8_ = dVar43;
        auVar4._12_4_ = (int)((ulonglong)dVar43 >> 0x20);
        FUN_140070d00(0,DAT_140e41a40,1,uVar23,(float)(DAT_140e9fd1c % 0x1a5 + 400),
                      CONCAT22(uVar50,0xc000),dVar43 * DAT_14053a0b0,auVar4,0,0xff,0xff,0xff,0x80,0)
        ;
      }
    }
    dVar43 = DAT_140539e90;
    if (uVar25 == 0xf0) {
      FUN_14012e070(0xcd,2);
LAB_1400f86f9:
      dVar40 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a5e8) * DAT_14053a890 * dVar5 *
                                     dVar44);
      dVar43 = dVar43 * dVar40 + 0.0;
      puVar16 = DAT_140e45d28;
    }
    else {
      lVar15 = DAT_140e47908;
      if (uVar25 == 500) {
        while (lVar15 != 0) {
          lVar15 = *(longlong *)(lVar15 + 0x238);
          FUN_140323ce8();
        }
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
        FUN_14012e070(0xce,2);
        puVar16 = DAT_140e45d28;
      }
      else {
        puVar16 = DAT_140e45d28;
        if ((int)uVar25 < 0xf0) {
          dVar43 = 0.0;
        }
        else if ((int)uVar25 < 0x104) goto LAB_1400f86f9;
      }
    }
    break;
  case 1:
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar2;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    DAT_140e46c88 = puVar24;
    dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - 0.0) * DAT_14053a698 * dVar5 * dVar44);
    uVar31 = DAT_140e47494;
    uVar30 = (longlong)(int)uVar25 * 0x2e7 + 0x37f4;
    uVar19 = (longlong)(int)uVar25 * 0x2219 + 0xfb44;
    fVar46 = (float)(dVar43 * DAT_14053a1e8) + DAT_14053ae30;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c98 = DAT_140e46c98 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar24[4] = fVar46;
    *puVar24 = uVar31;
    puVar24[1] = 2;
    puVar24[2] = 1;
    puVar24[3] = 0x44200000;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x3ff3333333333333;
    *(undefined8 *)(puVar24 + 8) = 0x3ff3333333333333;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    uVar31 = DAT_140e46b34;
    if (DAT_140e46904 != 0) {
      uVar31 = DAT_140e46ba8;
    }
    DAT_140e46c88 = puVar24;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    puVar24[0xd] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[10] = 0xff;
    *(undefined8 *)(puVar24 + 8) = 0x4000000000000000;
    *(undefined8 *)(puVar24 + 6) = 0x4000000000000000;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[4] = 0x43480000;
    puVar24[3] = 0x43520000;
    puVar24[2] = 1;
    puVar24[1] = 0x6f;
    *puVar24 = uVar31;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    dVar43 = DAT_14053ae68;
    fVar46 = DAT_14053ae48;
    uVar34 = uVar20;
    uVar35 = uVar20;
    DAT_140e46c88 = puVar24;
    do {
      dVar40 = (double)FUN_1403316f0();
      uVar9 = _UNK_14053bb58;
      uVar8 = _DAT_14053bb50;
      fVar7 = DAT_14053b344;
      fVar6 = DAT_14053b320;
      uVar31 = DAT_14053adb4;
      fVar45 = DAT_14053ac94;
      lVar15 = 0;
      if ((dVar43 <= dVar40) && (dVar40 = dVar40 - dVar43, dVar40 < dVar43)) {
        lVar15 = -0x8000000000000000;
      }
      uVar14 = (int)uVar34 + 1;
      uVar34 = (ulonglong)uVar14;
      uVar35 = ((longlong)dVar40 + lVar15) * 9 + uVar35;
    } while ((int)uVar14 < 0xc);
    uVar34 = uVar19;
    if (uVar35 < uVar19) {
      uVar34 = uVar35;
    }
    auVar51._12_4_ = in_stack_fffffffffffffea0._12_4_;
    auVar51._0_8_ = in_stack_fffffffffffffea0._0_8_;
    uVar50 = (ushort)(in_stack_fffffffffffffe90 >> 0x10);
    if (9 < uVar19) {
      uVar29 = uVar20;
      if (uVar35 < uVar19) {
        auVar51._8_4_ = 0xff;
        in_stack_fffffffffffffea0._8_8_ = auVar51._8_8_;
        in_stack_fffffffffffffea0._0_8_ = _UNK_14053bb58;
        in_stack_fffffffffffffe90 = (uint)uVar50 << 0x10;
        FUN_1400c8410(DAT_140e419ac,0x6f,1);
        uVar29 = 0;
      }
      do {
        uVar1 = (&DAT_140e41980)[(int)uVar34 + (int)(uVar34 / 10) * -10];
        puVar24 = (undefined4 *)_malloc_base(0x48);
        if (puVar24 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar24[3] = fVar46;
        *puVar24 = uVar1;
        puVar24[1] = 0x6f;
        puVar24[2] = 1;
        puVar24[4] = 0x43480000;
        *(undefined2 *)(puVar24 + 5) = 0;
        *(undefined8 *)(puVar24 + 6) = 0x4000000000000000;
        *(undefined8 *)(puVar24 + 8) = 0x4000000000000000;
        puVar24[10] = 0xff;
        puVar24[0xb] = 0xff;
        puVar24[0xc] = 0xff;
        puVar24[0xd] = 0xff;
        *(undefined8 *)(puVar24 + 0xe) = 1;
        *(undefined8 *)(puVar24 + 0x10) = 0;
        _DAT_140e46e4c = _DAT_140e46e4c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar24;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
        }
        iVar28 = (int)uVar29;
        fVar46 = fVar46 + fVar7;
        fVar49 = DAT_14053ae48;
        DAT_140e46c88 = puVar24;
        if (iVar28 + (iVar28 / 3 + (iVar28 >> 0x1f) +
                     (int)(((longlong)iVar28 / 3 + ((longlong)iVar28 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * -3 == 2) {
          if (uVar34 < 10) goto LAB_1400f8da8;
          fVar46 = fVar46 + fVar6;
          auVar52._12_4_ = in_stack_fffffffffffffea0._12_4_;
          auVar52._0_8_ = in_stack_fffffffffffffea0._0_8_;
          auVar52._8_4_ = 0xff;
          in_stack_fffffffffffffea0._8_8_ = auVar52._8_8_;
          in_stack_fffffffffffffea0._0_8_ = uVar9;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
          FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar46 + fVar45,uVar31,in_stack_fffffffffffffe90,uVar8,
                        uVar9,in_stack_fffffffffffffea0._8_8_,0xff,0xff,0xff,1,0);
        }
        else if (uVar34 < 10) goto LAB_1400f8da8;
        uVar34 = uVar34 / 10;
        uVar29 = (ulonglong)(iVar28 + 1);
      } while( true );
    }
    auVar53._8_4_ = 0xff;
    auVar53._0_8_ = auVar51._0_8_;
    auVar53._12_4_ = auVar51._12_4_;
    in_stack_fffffffffffffea0._8_8_ = auVar53._8_8_;
    in_stack_fffffffffffffea0._0_8_ = _UNK_14053bb58;
    in_stack_fffffffffffffe90 = (uint)uVar50 << 0x10;
    FUN_1400c8410((&DAT_140e41980)[uVar19],0x6f,1);
    fVar49 = fVar46;
LAB_1400f8da8:
    uVar31 = DAT_140e46b38;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e4c = _DAT_140e46e4c + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar31;
    puVar24[1] = 0x6f;
    puVar24[2] = 1;
    puVar24[3] = 0x446d8000;
    puVar24[4] = 0x43c80000;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x4000000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x4000000000000000;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    fVar46 = DAT_14053afe4;
    uVar35 = uVar20;
    uVar19 = uVar20;
    DAT_140e46c88 = puVar24;
    do {
      dVar40 = (double)FUN_1403316f0();
      lVar15 = 0;
      if ((dVar43 <= dVar40) && (dVar40 = dVar40 - dVar43, dVar40 < dVar43)) {
        lVar15 = -0x8000000000000000;
      }
      uVar14 = (int)uVar35 + 1;
      uVar35 = (ulonglong)uVar14;
      uVar19 = ((longlong)dVar40 + lVar15) * 9 + uVar19;
    } while ((int)uVar14 < 0xc);
    uVar35 = uVar30;
    if (uVar19 < uVar30) {
      uVar35 = uVar19;
    }
    auVar54._12_4_ = in_stack_fffffffffffffea0._12_4_;
    auVar54._0_8_ = in_stack_fffffffffffffea0._0_8_;
    uVar50 = (ushort)(in_stack_fffffffffffffe90 >> 0x10);
    if (9 < uVar30) {
      if (uVar19 < uVar30) {
        auVar54._8_4_ = 0xff;
        in_stack_fffffffffffffea0._8_8_ = auVar54._8_8_;
        in_stack_fffffffffffffea0._0_8_ = uVar8;
        in_stack_fffffffffffffe90 = (uint)uVar50 << 0x10;
        FUN_1400c8410(DAT_140e419ac,0x6f,1);
        uVar20 = 0;
      }
      do {
        uVar31 = (&DAT_140e41980)[(int)uVar35 + (int)(uVar35 / 10) * -10];
        puVar24 = (undefined4 *)_malloc_base(0x48);
        if (puVar24 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        uVar50 = (ushort)(in_stack_fffffffffffffe90 >> 0x10);
        puVar24[3] = fVar46;
        *puVar24 = uVar31;
        puVar24[1] = 0x6f;
        puVar24[2] = 1;
        puVar24[4] = 0x43c80000;
        *(undefined2 *)(puVar24 + 5) = 0;
        *(undefined8 *)(puVar24 + 6) = 0x4000000000000000;
        *(undefined8 *)(puVar24 + 8) = 0x4000000000000000;
        puVar24[10] = 0xff;
        puVar24[0xb] = 0xff;
        puVar24[0xc] = 0xff;
        puVar24[0xd] = 0xff;
        *(undefined8 *)(puVar24 + 0xe) = 1;
        *(undefined8 *)(puVar24 + 0x10) = 0;
        _DAT_140e46e4c = _DAT_140e46e4c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar24;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
        }
        iVar28 = (int)uVar20;
        fVar46 = fVar46 + fVar7;
        DAT_140e46c88 = puVar24;
        if (iVar28 + (iVar28 / 3 + (iVar28 >> 0x1f) +
                     (int)(((longlong)iVar28 / 3 + ((longlong)iVar28 >> 0x3f) & 0xffffffffU) >> 0x1f
                          )) * -3 == 2) {
          if (uVar35 < 10) goto LAB_1400f9125;
          fVar46 = fVar46 + fVar6;
          auVar55._12_4_ = in_stack_fffffffffffffea0._12_4_;
          auVar55._0_8_ = in_stack_fffffffffffffea0._0_8_;
          auVar55._8_4_ = 0xff;
          in_stack_fffffffffffffea0._8_8_ = auVar55._8_8_;
          in_stack_fffffffffffffea0._0_8_ = uVar8;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffff0000;
          FUN_1400c8410(DAT_140e419a8,0x6f,1,fVar46 + fVar45,fVar49,in_stack_fffffffffffffe90,uVar8,
                        uVar8,in_stack_fffffffffffffea0._8_8_,0xff,0xff,0xff,1,0);
        }
        else if (uVar35 < 10) goto LAB_1400f9125;
        uVar35 = uVar35 / 10;
        uVar20 = (ulonglong)(iVar28 + 1);
      } while( true );
    }
    FUN_1400c8410((&DAT_140e41980)[uVar30],0x6f,1);
LAB_1400f9125:
    if (uVar25 == ((int)uVar25 / 10) * 10) {
      dVar43 = (double)FUN_140134db0(DAT_140e451bc + -0x29a,DAT_140539f00,DAT_140539f40);
      uVar23 = (DAT_140e418c8 + 0x6f >> 0x1e ^ DAT_140e418c8 + 0x6f) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar14 = uVar23 * 0x800 ^ uVar23;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
      auVar3._8_4_ = SUB84(dVar43,0);
      auVar3._0_8_ = dVar43;
      auVar3._12_4_ = (int)((ulonglong)dVar43 >> 0x20);
      FUN_140070d00(0,DAT_140e41a40,10,uVar23,(float)(DAT_140e9fd1c % 0x1a5 + 400),
                    CONCAT22(uVar50,0xc000),dVar43 * DAT_14053a178,auVar3,0,0xff,0xff,0xff,0x80,0);
    }
    dVar43 = DAT_140539e90;
    if (uVar25 == 0x1e) {
      FUN_14012e070(0xcf,2);
LAB_1400f9381:
      dVar40 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a2d8) * DAT_14053a890 * dVar5 *
                                     dVar44);
      dVar43 = dVar43 * dVar40 + 0.0;
      puVar16 = DAT_140e45d28;
    }
    else {
      puVar16 = DAT_140e45d28;
      if ((int)uVar25 < 0x1e) {
        dVar43 = 0.0;
      }
      else if ((int)uVar25 < 0x32) goto LAB_1400f9381;
    }
    break;
  case 2:
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar10;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    dVar47 = DAT_14053a9d8;
    dVar40 = DAT_14053a4d8;
    dVar43 = DAT_140539f40;
    puVar16 = &local_100;
    iVar28 = 0x78;
    uVar23 = 0;
    uVar30 = uVar20;
    uVar14 = uVar25;
    DAT_140e46c88 = puVar24;
    do {
      iVar32 = 0x17c;
      if ((int)uVar20 == iVar28) {
LAB_1400f951a:
        fVar46 = (float)iVar32;
        if ((int)uVar25 < iVar28) {
          dVar39 = 0.0;
        }
        else {
          dVar39 = dVar43;
          if ((int)uVar25 < iVar28 + 10) {
            dVar39 = (double)FUN_140332d90(((double)(int)uVar25 - (double)iVar28) * dVar47 * dVar5 *
                                           dVar44);
            dVar39 = dVar39 + 0.0;
          }
        }
      }
      else {
        iVar32 = 0x438;
        if (((int)uVar25 < iVar28 + -0x78) || (iVar32 = 0x17c, iVar28 <= (int)uVar25))
        goto LAB_1400f951a;
        dVar39 = (double)FUN_140332d90(((double)(int)uVar25 - (double)(iVar28 + -0x78)) * dVar40 *
                                       dVar5 * dVar44);
        fVar46 = (float)(0x438 - (int)(dVar39 * DAT_14053a840));
        dVar39 = 0.0;
      }
      local_100 = _DAT_14053bce0;
      uStack_f8 = _UNK_14053bce8;
      local_f0 = 0x44200000;
      local_ec = 0x42c80000;
      if ((int)uVar14 % 0x32 < 10) {
        dVar38 = (double)FUN_140332d90(((double)((int)uVar14 % 0x32) - 0.0) * DAT_14053aa88 * dVar5
                                       * dVar44);
        fVar46 = fVar46 + (float)(dVar38 * DAT_14053b0d8) + 0.0;
      }
      uVar31 = *(undefined4 *)((longlong)&DAT_140e4749c + uVar30);
      puVar24 = (undefined4 *)_malloc_base(0x48);
      if (puVar24 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar24 = uVar31;
      puVar24[4] = fVar46;
      puVar24[1] = 2;
      puVar24[2] = 1;
      puVar24[3] = 0x44200000;
      *(undefined2 *)(puVar24 + 5) = 0;
      *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
      puVar24[10] = 0xff;
      puVar24[0xb] = 0xff;
      puVar24[0xc] = 0xff;
      puVar24[0xd] = 0xff;
      *(undefined8 *)(puVar24 + 0xe) = 1;
      *(undefined8 *)(puVar24 + 0x10) = 0;
      DAT_140e46c98 = DAT_140e46c98 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar24;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
      }
      uVar31 = *(undefined4 *)((longlong)puVar16 + 4);
      uVar2 = *(undefined4 *)((longlong)&DAT_140e45084 + uVar30);
      uVar1 = *(undefined4 *)puVar16;
      DAT_140e46c88 = puVar24;
      puVar24 = (undefined4 *)_malloc_base(0x48);
      if (puVar24 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar24 = uVar2;
      puVar24[3] = uVar1;
      puVar24[4] = uVar31;
      *(double *)(puVar24 + 8) = dVar39;
      puVar24[1] = 3;
      puVar24[2] = 1;
      *(undefined2 *)(puVar24 + 5) = 0;
      *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
      puVar24[10] = 0xff;
      puVar24[0xb] = 0xff;
      puVar24[0xc] = 0xff;
      puVar24[0xd] = 0xff;
      *(undefined8 *)(puVar24 + 0xe) = 1;
      *(undefined8 *)(puVar24 + 0x10) = 0;
      _DAT_140e46c9c = _DAT_140e46c9c + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar24;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
      }
      dVar39 = DAT_140539e90;
      iVar28 = iVar28 + 0x14;
      uVar23 = uVar23 + 0x14;
      uVar20 = (ulonglong)uVar23;
      uVar30 = uVar30 + 4;
      uVar14 = uVar14 + 0xc;
      puVar16 = puVar16 + 1;
      DAT_140e46c88 = puVar24;
    } while (iVar28 < 0xb4);
    if (uVar25 == 0x1e) {
      FUN_14012e070(0xd0,2);
    }
    else {
LAB_1400f9838:
      dVar43 = 0.0;
      puVar16 = DAT_140e45d28;
      if (((int)uVar25 < 0x1e) ||
         (dVar43 = DAT_140539e90, dVar39 = DAT_140539e90, 0x31 < (int)uVar25)) break;
    }
    goto LAB_1400f984c;
  case 3:
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar11;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    DAT_140e46c88 = puVar24;
    if (uVar25 < 0x3c) {
      dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - 0.0) * DAT_14053a628 * dVar5 * dVar44);
      fVar46 = (float)(0x500 - (int)(dVar43 * _DAT_14053a7e0));
    }
    else {
      fVar46 = (float)((uVar14 & 0x280) + 0x280);
      if (0x3b < (int)uVar25) {
        if ((int)uVar25 < 0x50) {
          FUN_140332d90(((double)(int)uVar25 - DAT_14053a3a0) * DAT_14053a890 * dVar5 * dVar44);
        }
        else if ((int)uVar25 < 100) {
          FUN_140332d90(((double)(int)uVar25 - DAT_14053a3a0) * DAT_14053a890 * dVar5 * dVar44);
        }
      }
    }
    uVar31 = DAT_140e474b8;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar24[3] = fVar46;
    *puVar24 = uVar31;
    puVar24[1] = 10;
    puVar24[2] = 1;
    puVar24[4] = 0x43b40000;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    DAT_140e46c88 = puVar24;
    if (0x3b < (int)uVar25) {
      FUN_1400c8410(DAT_140e41944,10,1);
    }
    dVar47 = DAT_14053a840;
    dVar40 = DAT_14053a4d8;
    dVar43 = DAT_14053a1e8;
    puVar24 = &DAT_140e474ac;
    do {
      iVar17 = (int)uVar20;
      iVar18 = 0x17c;
      iVar28 = iVar17 * 0x3c + 0x5a;
      iVar32 = iVar17 * 0x3c + 0xd2;
      if (((iVar28 != iVar32) && (iVar18 = 0x438, iVar28 <= (int)uVar25)) &&
         (iVar18 = 0x17c, (int)uVar25 < iVar32)) {
        dVar39 = (double)FUN_140332d90(((double)(int)uVar25 - (double)iVar28) * dVar40 * dVar5 *
                                       dVar44);
        iVar18 = 0x438 - (int)(dVar39 * dVar47);
      }
      fVar46 = (float)iVar18;
      if (iVar17 == 0) {
        dVar39 = (double)FUN_140332d90();
        dVar39 = dVar39 * dVar43;
LAB_1400f9c61:
        fVar46 = fVar46 + (float)dVar39 + 0.0;
      }
      else if (iVar17 != 0) {
        dVar39 = (double)FUN_140332d90(((double)((int)(iVar17 * 0x10 + uVar25) % 10) - 0.0) *
                                       DAT_14053aa88 * dVar5 * dVar44);
        dVar39 = dVar39 * _DAT_14053b100;
        goto LAB_1400f9c61;
      }
      uVar31 = *puVar24;
      puVar33 = (undefined4 *)_malloc_base(0x48);
      if (puVar33 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar33[4] = fVar46;
      *puVar33 = uVar31;
      puVar33[1] = 2;
      puVar33[2] = 1;
      puVar33[3] = 0x44200000;
      *(undefined2 *)(puVar33 + 5) = 0;
      *(undefined8 *)(puVar33 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar33 + 8) = 0x3ff0000000000000;
      puVar33[10] = 0xff;
      puVar33[0xb] = 0xff;
      puVar33[0xc] = 0xff;
      puVar33[0xd] = 0xff;
      *(undefined8 *)(puVar33 + 0xe) = 1;
      *(undefined8 *)(puVar33 + 0x10) = 0;
      DAT_140e46c98 = DAT_140e46c98 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar33;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar33;
      }
      dVar39 = DAT_140539e90;
      uVar20 = (ulonglong)(iVar17 + 1U);
      puVar24 = puVar24 + 1;
      DAT_140e46c88 = puVar33;
    } while ((int)(iVar17 + 1U) < 3);
    if (uVar25 != 0x1e) goto LAB_1400f9838;
    FUN_14012e070(0xd1,2);
LAB_1400f984c:
    dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a2d8) * DAT_14053a890 * dVar5 *
                                   dVar44);
    dVar43 = dVar39 * dVar43 + 0.0;
    puVar16 = DAT_140e45d28;
    break;
  case 4:
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar12;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    iVar28 = -0x17c;
    DAT_140e46c88 = puVar24;
    if (((int)uVar25 < 0x3c) || (iVar28 = 0x154, 0xb3 < (int)uVar25)) {
      uVar23 = uVar14 & 0xfffffd80;
      fVar46 = (float)iVar28;
      if (-1 < (int)uVar25) goto LAB_1400f9ee2;
    }
    else {
      dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a3a0) * DAT_14053a4d8 * dVar5 *
                                     dVar44);
      fVar46 = (float)(-0x17c - (int)(dVar43 * _DAT_14053b288));
LAB_1400f9ee2:
      uVar23 = uVar14 & 0xfffffd80;
      if ((int)uVar25 < 0x40) {
        dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - 0.0) * DAT_14053a600 * dVar5 * dVar44)
        ;
        uVar23 = -(int)(dVar43 * _DAT_14053b268) - 0x280;
      }
    }
    uVar14 = uVar25 & 0x8000000f;
    if ((int)uVar14 < 0) {
      uVar14 = (uVar14 - 1 | 0xfffffff0) + 1;
    }
    dVar43 = (double)FUN_140332d90(((double)(int)uVar14 - 0.0) * DAT_14053aa28 * dVar5 * dVar44);
    fVar45 = (float)(dVar43 * (double)(int)uVar23) + 0.0;
    if ((0x3f < (int)uVar25) && (0x6d < (int)uVar25 % 0x78)) {
      dVar43 = (double)FUN_140332d90(((double)((int)uVar25 % 10) - 0.0) * DAT_14053aa88 * dVar5 *
                                     dVar44);
      fVar45 = (float)(dVar43 * DAT_14053b0d8) + 0.0;
    }
    uVar31 = DAT_140e474c0;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c98 = DAT_140e46c98 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar24[4] = fVar46;
    *puVar24 = uVar31;
    puVar24[1] = 2;
    puVar24[2] = 1;
    puVar24[3] = 0x44200000;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    uVar31 = DAT_140e474c4;
    DAT_140e46c88 = puVar24;
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    fVar45 = fVar45 + DAT_14053ae30;
    DAT_140e46c98 = DAT_140e46c98 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar31;
    puVar24[1] = 2;
    fVar45 = fVar45 + DAT_14053accc;
    puVar24[2] = 1;
    puVar24[3] = 0x44188000;
    *(undefined2 *)(puVar24 + 5) = 0;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    puVar24[4] = fVar45;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    dVar43 = DAT_140539e90;
    DAT_140e46c88 = puVar24;
    if ((int)uVar25 < 0x3c) {
      if (uVar25 != 0x1e) goto LAB_1400fa4ea;
      FUN_14012e070(0xd2,2);
LAB_1400fa4fd:
      dVar40 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a2d8) * DAT_14053a890 * dVar5 *
                                     dVar44);
      dVar43 = dVar43 * dVar40 + 0.0;
      puVar16 = DAT_140e45d28;
    }
    else {
      if (uVar25 == ((int)uVar25 / 5) * 5) {
        uVar27 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        uVar14 = (uVar27 >> 0x1e ^ uVar27) * 0x6c078965 + 2;
        uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
        uVar26 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
        uVar21 = (DAT_140e418c8 + 0x457 >> 0x1e ^ DAT_140e418c8 + 0x457) * 0x6c078965 + 1;
        uVar14 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
        uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 3;
        uVar14 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 4;
        uVar23 = (DAT_140e418c8 + 0xde >> 0x1e ^ DAT_140e418c8 + 0xde) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar23 = uVar23 * 0x800 ^ uVar23;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar23) >> 8 ^ DAT_140e9fd18 ^ uVar23;
        fVar46 = DAT_14053b33c;
        fVar45 = (float)(DAT_140e9fd1c % 0x321 + 0x1e0);
        if ((((uVar26 >> 0xb ^ uVar27) >> 8 ^ uVar26 ^ uVar27) & 1) != 0) {
          uVar23 = (DAT_140e418c8 + 0xde >> 0x1e ^ DAT_140e418c8 + 0xde) * 0x6c078965 + 1;
          uVar26 = (uVar23 >> 0x1e ^ uVar23) * 0x6c078965 + 2;
          DAT_140e9fd14 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 3;
          uVar23 = uVar23 * 0x800 ^ uVar23;
          uVar26 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (uVar26 >> 0xb ^ uVar23) >> 8 ^ uVar26 ^ uVar23;
          fVar46 = (float)(DAT_140e9fd1c % 0x1e1);
          fVar45 = DAT_14053b010;
        }
        uVar31 = (&DAT_140e451c8)[((uVar14 >> 0xb ^ uVar21) >> 8 ^ uVar14 ^ uVar21) & 1];
        if (DAT_140e45d1c < 0x1000) {
          puVar16 = (undefined8 *)_malloc_base(0x60);
          if (puVar16 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar37 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)((longlong)puVar16 + 0x14) = fVar45;
          *(float *)(puVar16 + 3) = fVar46;
          *(float *)((longlong)puVar16 + 0x1c) = fVar45;
          *(float *)(puVar16 + 4) = fVar46;
          *puVar16 = 1;
          *(undefined4 *)(puVar16 + 1) = 2;
          *(undefined4 *)((longlong)puVar16 + 0xc) = uVar31;
          *(undefined4 *)(puVar16 + 2) = 4;
          *(undefined2 *)((longlong)puVar16 + 0x24) = 0x6710;
          puVar16[5] = 0x4044000000000000;
          puVar16[6] = 0x3ff0000000000000;
          puVar16[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar16 + 8) = 0;
          *(undefined4 *)((longlong)puVar16 + 0x44) = 0xff;
          *(undefined4 *)(puVar16 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar16 + 0x4c) = 0xff;
          puVar16[10] = 0xff;
          puVar16[0xb] = 0;
          if (bVar37) {
            DAT_140e45d78 = puVar16;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar16;
          }
          break;
        }
      }
LAB_1400fa4ea:
      puVar16 = DAT_140e45d28;
      if ((int)uVar25 < 0x1e) {
        dVar43 = 0.0;
      }
      else if ((int)uVar25 < 0x32) goto LAB_1400fa4fd;
    }
    break;
  case 5:
    puVar24 = (undefined4 *)_malloc_base(0x48);
    if (puVar24 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46c94 = DAT_140e46c94 + 1;
    bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar24 = uVar13;
    *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar24 + 1) = 1;
    *(undefined8 *)(puVar24 + 3) = 0;
    *(undefined2 *)(puVar24 + 5) = 0;
    puVar24[10] = 0xff;
    puVar24[0xb] = 0xff;
    puVar24[0xc] = 0xff;
    puVar24[0xd] = 0xff;
    *(undefined8 *)(puVar24 + 0xe) = 1;
    *(undefined8 *)(puVar24 + 0x10) = 0;
    if (bVar37) {
      DAT_140e46bf0 = puVar24;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    }
    dVar38 = DAT_14053a848;
    dVar39 = DAT_14053a840;
    dVar47 = DAT_14053a798;
    dVar40 = DAT_14053a6d8;
    dVar43 = DAT_14053a0b0;
    iVar32 = 200;
    iVar28 = 0x17c;
    local_res20 = &DAT_140e474cc;
    dVar48 = (double)(int)uVar25;
    local_res10 = 0;
    uVar30 = uVar20;
    DAT_140e46c88 = puVar24;
    do {
      uVar14 = (uint)uVar20;
      iVar18 = 0x17c;
      if (((iVar32 != iVar32 + 0x28) && (iVar18 = 0x438, iVar32 <= (int)uVar25)) &&
         (iVar18 = 0x17c, (int)uVar25 < iVar32 + 0x28)) {
        dVar41 = (double)FUN_140332d90((dVar48 - (double)iVar32) * dVar40 * dVar5 * dVar44);
        iVar18 = 0x438 - (int)(dVar41 * dVar39);
        uVar14 = local_res10;
      }
      fVar46 = (float)iVar18;
      if ((int)uVar30 < 2) {
        dVar41 = (double)FUN_140332d90((dVar48 - (double)(int)uVar14) * dVar47 * dVar5 * dVar44);
        iVar18 = 0x438;
        if (iVar32 <= (int)uVar25) {
          iVar18 = 0x168;
        }
        if ((iVar32 <= (int)uVar25) && ((int)uVar25 < iVar28)) {
          dVar42 = (double)FUN_140332d90((dVar48 - (double)iVar32) * DAT_14053a438 * dVar5 * dVar44)
          ;
          iVar18 = 0x438 - (int)(dVar42 * dVar38);
        }
        fVar46 = (float)iVar18 + (float)(dVar41 * dVar43) + 0.0;
      }
      uVar31 = *local_res20;
      puVar24 = (undefined4 *)_malloc_base(0x48);
      if (puVar24 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar24 = uVar31;
      puVar24[4] = fVar46;
      puVar24[1] = 2;
      puVar24[2] = 1;
      puVar24[3] = 0x44200000;
      *(undefined2 *)(puVar24 + 5) = 0;
      *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar24 + 8) = 0x3ff0000000000000;
      puVar24[10] = 0xff;
      puVar24[0xb] = 0xff;
      puVar24[0xc] = 0xff;
      puVar24[0xd] = 0xff;
      *(undefined8 *)(puVar24 + 0xe) = 1;
      *(undefined8 *)(puVar24 + 0x10) = 0;
      DAT_140e46c98 = DAT_140e46c98 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar24;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
      }
      dVar41 = DAT_140539e90;
      uVar30 = (ulonglong)((int)uVar30 + 1);
      local_res10 = local_res10 + 0x28;
      uVar20 = (ulonglong)local_res10;
      iVar32 = iVar32 + -0x28;
      local_res20 = local_res20 + 1;
      iVar28 = iVar28 + -0x28;
      DAT_140e46c88 = puVar24;
    } while (0xb4 < iVar28);
    if (uVar25 == 0x1e) {
      FUN_14012e070(0xd3,2);
LAB_1400fa8c3:
      dVar43 = (double)FUN_140332d90(((double)(int)uVar25 - DAT_14053a2d8) * DAT_14053a890 * dVar5 *
                                     dVar44);
      dVar43 = dVar41 * dVar43 + 0.0;
      puVar16 = DAT_140e45d28;
    }
    else {
      puVar16 = DAT_140e45d28;
      if ((int)uVar25 < 0x1e) {
        dVar43 = 0.0;
      }
      else {
        dVar43 = DAT_140539e90;
        if ((int)uVar25 < 0x32) goto LAB_1400fa8c3;
      }
    }
  }
  DAT_140e45d28 = puVar16;
  uVar31 = DAT_140e41ab8;
  puVar24 = (undefined4 *)_malloc_base(0x48);
  if (puVar24 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e6c = _DAT_140e46e6c + 1;
  bVar37 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(double *)(puVar24 + 8) = dVar43;
  *(undefined8 *)(puVar24 + 0x10) = 0;
  *(undefined8 *)(puVar24 + 0xe) = 1;
  puVar24[0xd] = 0xa0;
  puVar24[0xc] = 0x80;
  puVar24[0xb] = 0x40;
  puVar24[10] = 0x40;
  *(undefined8 *)(puVar24 + 6) = 0x3ff0000000000000;
  *(undefined2 *)(puVar24 + 5) = 0;
  puVar24[4] = 0x44218000;
  puVar24[3] = 0x44200000;
  puVar24[2] = 1;
  puVar24[1] = 0x77;
  *puVar24 = uVar31;
  if (bVar37) {
    DAT_140e46bf0 = puVar24;
  }
  fVar46 = DAT_14053ac64;
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar24;
    fVar46 = DAT_14053ac64;
  }
LAB_1400fa99d:
  DAT_140e46c88 = puVar24;
  if (((int)uVar25 < 0x28) && (799 < (int)DAT_140e418c8)) {
    FUN_1400d4310(uVar25);
  }
  iVar28 = *(int *)((longlong)&local_118 + (ulonglong)local_res8 * 4);
  if ((iVar28 + -0x28 <= (int)DAT_140e418c8) && ((int)DAT_140e418c8 < 0xc81)) {
    FUN_1400d3fd0((DAT_140e418c8 - iVar28) + 0x28);
  }
  if ((DAT_140e418c8 == (&uStack_11c)[local_res8]) &&
     (puVar16 = DAT_140e45d78, 799 < (int)DAT_140e418c8)) {
    while (puVar16 != (undefined8 *)0x0) {
      puVar16 = (undefined8 *)puVar16[0xb];
      FUN_140323ce8();
    }
    DAT_140e45d78 = (undefined8 *)0x0;
    DAT_140e45d28 = (undefined8 *)0x0;
    DAT_140e45d1c = 0;
    lVar15 = DAT_140e47908;
    while (lVar15 != 0) {
      lVar15 = *(longlong *)(lVar15 + 0x238);
      FUN_140323ce8();
    }
    DAT_140e47908 = 0;
    DAT_140e9fd30 = 0;
  }
  FUN_140070e40();
  FUN_1400714d0();
  if (0xeeb < (int)DAT_140e418c8) {
    dVar44 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_14053aab8) * DAT_14053a438 *
                                   dVar5 * dVar44);
    _DAT_1407c777c = (float)(dVar44 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * fVar46 * _DAT_1407c777c),DAT_140e45100);
  }
  if (0 < DAT_140e45fac) {
    FUN_1400d3fd0();
  }
  if (DAT_140e45fac != 0x32) {
    if (0 < DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    DAT_140e418c8 = DAT_140e418c8 + 1;
    return;
  }
  DAT_140e45fac = 0x32;
  puVar16 = DAT_140e45d78;
  while (puVar16 != (undefined8 *)0x0) {
    puVar16 = (undefined8 *)puVar16[0xb];
    FUN_140323ce8();
  }
  DAT_140e45d78 = (undefined8 *)0x0;
  DAT_140e45d28 = (undefined8 *)0x0;
  DAT_140e45d1c = 0;
  lVar15 = DAT_140e47908;
  while (lVar15 != 0) {
    lVar15 = *(longlong *)(lVar15 + 0x238);
    FUN_140323ce8();
  }
  DAT_140e47908 = 0;
  DAT_140e9fd30 = 0;
  DAT_140e45fac = 0;
  DAT_140e45274 = 0;
  DAT_140e418c8 = 1;
  DAT_140e474e4 = 1;
  DAT_140e45270 = 2;
  return;
}


