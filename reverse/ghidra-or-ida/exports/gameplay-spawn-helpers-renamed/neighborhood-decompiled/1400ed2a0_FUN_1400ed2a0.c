// Function: FUN_1400ed2a0 @ 1400ed2a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ed2a0(undefined4 *param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  undefined8 uVar4;
  short sVar5;
  ushort uVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  ulonglong in_stack_ffffffffffffff28;
  undefined4 uVar21;
  uint in_stack_ffffffffffffff30;
  undefined4 uVar22;
  undefined2 uVar23;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 uVar25;
  undefined8 uVar24;
  
  uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  dVar18 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar18 = dVar18 * DAT_14053aba0;
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  uVar23 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
  uVar22 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
  dVar19 = dVar19 * DAT_14053aba0;
  iVar16 = 0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    uVar24 = CONCAT44(uVar25,param_1[0x14]);
    in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
    in_stack_ffffffffffffff28 = CONCAT44(uVar22,param_1[0xb]);
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,
               DAT_14053a4f0,uVar24,1,0);
    uVar23 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
    uVar25 = (undefined4)((ulonglong)uVar24 >> 0x20);
    if (DAT_140e41928 == 0) {
      uVar15 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar15 * 0x800 ^ uVar15;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      in_stack_ffffffffffffff28 = DAT_14053a070;
      uVar22 = DAT_14053ac80;
      FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                    DAT_14053a070,DAT_14053ac80);
      uVar23 = (undefined2)((uint)uVar22 >> 0x10);
    }
    if (DAT_140e41af8 == 1) {
      param_1[0x14] = 0xf0;
      param_1[5] = 2;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar4 = _UNK_14053bb28;
  uVar24 = _DAT_14053bb20;
  uVar22 = DAT_14053acf0;
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539d28;
  uVar21 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar15 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar9 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
    uVar10 = DAT_1407c7798 * 0xde + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar9 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ uVar9) % 0x12d + 0xd2);
    uVar15 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar15 = uVar15 * 0x800 ^ uVar15;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x8c);
  }
  iVar11 = param_1[5];
  sVar5 = (short)(int)dVar19;
  if (iVar11 == 0) {
    if (param_1[3] == 0) {
      uVar15 = CONCAT22(uVar23,0x8000);
      in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
      stage_entity_spawn_candidate
                (0xc9,99999999,0,DAT_14053acf0,in_stack_ffffffffffffff28,uVar15,_DAT_14053bb20,
                 CONCAT44(uVar25,0x28),1,param_1[1]);
      uVar15 = uVar15 & 0xffff0000;
      in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
      stage_entity_spawn_candidate
                (0xca,99999999,0,uVar22,in_stack_ffffffffffffff28,uVar15,uVar24,0x28,1,param_1[1]);
      uVar21 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
      uVar23 = (undefined2)(uVar15 >> 0x10);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
    }
    iVar16 = param_1[3];
    fVar20 = DAT_14053ae88;
    if (-1 < iVar16) {
      if (iVar16 < 0x96) {
        dVar18 = (double)FUN_140332d90(((double)iVar16 - _DAT_14053b1d8) * _DAT_14053a478 * dVar3 *
                                       dVar2);
        fVar20 = (float)(dVar18 * DAT_14053a758) + 0.0;
      }
      else {
        fVar20 = 0.0;
      }
    }
    dVar18 = (double)FUN_140332d90(((double)iVar16 - 0.0) * _DAT_14053a6f8 * dVar3 * dVar2);
    iVar11 = (int)(float)param_1[0xd];
    param_1[10] = (float)(dVar18 * (double)fVar20) + (float)param_1[0xc];
    if (iVar16 < 0) {
      iVar11 = 1000;
    }
    else if (iVar16 < 0x96) {
      dVar18 = (double)FUN_140332d90();
      iVar11 = (int)(dVar18 * (double)(iVar11 + -1000)) + 1000;
    }
    uVar13 = *(ushort *)((longlong)param_1 + 0x42);
    param_1[0xb] = (float)iVar11;
    uVar15 = ((iVar16 % 0x708) / 0x1e & 0xffffU) * 0x444;
    uVar6 = (ushort)uVar15;
    iVar11 = (uVar15 & 0xffff) - (uint)uVar13;
    iVar16 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar16 = iVar11;
    }
    iVar11 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar11 = iVar16;
    }
    if (iVar11 < 1) {
      uVar14 = uVar13;
      if ((iVar11 < 0) && (uVar14 = uVar13 - 0xb6, -0xb6 < iVar11)) {
        uVar14 = uVar6;
      }
    }
    else {
      uVar14 = uVar6;
      if (0xb5 < iVar11) {
        uVar14 = uVar13 + 0xb6;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar14;
    uVar13 = *(ushort *)(param_1 + 0x11);
    uVar6 = (sVar5 - uVar13) + 0xc000;
    uVar15 = (uint)uVar6;
    if (0x8000 < uVar6) {
      uVar15 = 0x10000 - uVar6;
    }
    uVar6 = sVar5 + 0xc000;
    iVar11 = (uint)uVar6 - (uint)uVar13;
    iVar12 = (int)uVar15 / 0x14 + 0x30;
    iVar16 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar16 = iVar11;
    }
    iVar11 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar11 = iVar16;
    }
    if (iVar11 < 1) {
      uVar14 = uVar13;
      if ((iVar11 < 0) && (uVar14 = uVar13 - (short)iVar12, -iVar12 < iVar11)) {
        uVar14 = uVar6;
      }
    }
    else {
      uVar14 = uVar6;
      if (iVar12 <= iVar11) {
        uVar14 = uVar13 + (short)iVar12;
      }
    }
    *(ushort *)(param_1 + 0x11) = uVar14;
    if (param_1[3] == 0x96) {
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
      DAT_140e41b0c = 80000;
      DAT_140e4430c = 0x708;
      DAT_140e4192c = 0;
      param_1[7] = 80000;
      DAT_140e419bc = 1;
    }
    goto LAB_1400edf18;
  }
  if (iVar11 == 1) {
    uVar13 = *(ushort *)(param_1 + 0x10);
    iVar11 = ((int)dVar18 & 0xffffU) - (uint)uVar13;
    iVar16 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar16 = iVar11;
    }
    iVar11 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar11 = iVar16;
    }
    uVar6 = (ushort)(int)dVar18;
    if (iVar11 < 1) {
      uVar14 = uVar13;
      if ((iVar11 < 0) && (uVar14 = uVar13 - 0x200, -0x200 < iVar11)) {
        uVar14 = uVar6;
      }
    }
    else {
      uVar14 = uVar6;
      if (0x1ff < iVar11) {
        uVar14 = uVar13 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    dVar18 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar18 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar18 = (double)FUN_140332d90();
    iVar16 = param_1[3];
    uVar13 = *(ushort *)((longlong)param_1 + 0x42);
    param_1[0xb] = (float)(dVar18 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar15 = ((iVar16 % 0x708) / 0x1e & 0xffffU) * 0x444;
    uVar6 = (ushort)uVar15;
    iVar12 = (uVar15 & 0xffff) - (uint)uVar13;
    iVar11 = iVar12 + 0x10000;
    if (-0x8001 < iVar12) {
      iVar11 = iVar12;
    }
    iVar12 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar12 = iVar11;
    }
    if (iVar12 < 1) {
      uVar14 = uVar13;
      if ((iVar12 < 0) && (uVar14 = uVar13 - 0xb6, -0xb6 < iVar12)) {
        uVar14 = uVar6;
      }
    }
    else {
      uVar14 = uVar6;
      if (0xb5 < iVar12) {
        uVar14 = uVar13 + 0xb6;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar14;
    if (iVar16 == (iVar16 / 0x1e) * 0x1e) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472ec);
      FUN_14018a340(DAT_140e472ec,1,1);
    }
    uVar13 = *(ushort *)(param_1 + 0x11);
    uVar6 = (sVar5 - uVar13) + 0xc000;
    uVar15 = (uint)uVar6;
    if (0x8000 < uVar6) {
      uVar15 = 0x10000 - uVar6;
    }
    uVar6 = sVar5 + 0xc000;
    iVar11 = (uint)uVar6 - (uint)uVar13;
    iVar12 = (int)uVar15 / 0x14 + 0x30;
    iVar16 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar16 = iVar11;
    }
    iVar11 = iVar16 + -0x10000;
    if (iVar16 < 0x8001) {
      iVar11 = iVar16;
    }
    if (iVar11 < 1) {
      if ((iVar11 < 0) && (uVar13 = uVar13 - (short)iVar12, -iVar12 < iVar11)) {
        uVar13 = uVar6;
      }
      *(ushort *)(param_1 + 0x11) = uVar13;
    }
    else if (iVar11 < iVar12) {
      *(ushort *)(param_1 + 0x11) = uVar6;
    }
    else {
      *(ushort *)(param_1 + 0x11) = uVar13 + (short)iVar12;
    }
    goto LAB_1400edf18;
  }
  if (iVar11 != 2) goto LAB_1400edf18;
  iVar11 = param_1[3];
  iVar12 = iVar16;
  if (iVar11 < 0x5a) {
LAB_1400ed718:
    if (iVar11 < 0x96) {
      iVar16 = iVar12;
    }
    puVar7 = DAT_140e45d28;
    if (iVar11 == 1) {
      uVar22 = param_1[0xb];
      uVar25 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar17 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar25;
        *(undefined4 *)(puVar7 + 3) = uVar22;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar25;
        *(undefined4 *)(puVar7 + 4) = uVar22;
        *puVar7 = 1;
        puVar7[1] = 0x36;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0;
        if (bVar17) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
    }
  }
  else {
    iVar12 = 0xff;
    if (iVar11 < 100) {
      dVar18 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar16 = (int)(dVar18 * DAT_14053a5f8);
      puVar7 = DAT_140e45d28;
    }
    else {
      if (0x95 < iVar11) goto LAB_1400ed718;
      dVar18 = (double)FUN_140332d90(((double)iVar11 - DAT_14053a380) * DAT_14053a670 *
                                     DAT_14053a020 * DAT_140539d28);
      puVar7 = DAT_140e45d28;
      if (iVar11 < 0x96) {
        iVar16 = (int)(dVar18 * DAT_14053a5f8);
      }
    }
  }
  DAT_140e45d28 = puVar7;
  iVar11 = param_1[3];
  if (iVar11 < 0x5a) {
    FUN_14007ac00(param_1);
    iVar11 = param_1[3];
    *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + -0x682;
    *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x682;
    param_1[0xb] = (float)iVar11 * _DAT_140539ccc + (float)param_1[0xb];
  }
  if (iVar11 == 0x5a) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
    FUN_14018a340(DAT_140e472a0,1,1);
    uVar22 = param_1[0xb];
    uVar25 = param_1[10];
    puVar7 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar17 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar7 + 0x14) = uVar25;
      *(undefined4 *)(puVar7 + 3) = uVar22;
      *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar25;
      *(undefined4 *)(puVar7 + 4) = uVar22;
      *puVar7 = 1;
      puVar7[1] = 0x11;
      *(undefined4 *)(puVar7 + 2) = 0x28;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0;
      puVar7[6] = 0x3ff0000000000000;
      puVar7[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar7 + 8) = 0;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0;
      if (bVar17) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
    }
    DAT_140e45d28 = puVar7;
    DAT_140e46a08 = DAT_140e418c8;
  }
  uVar22 = DAT_140e41ab8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
  bVar17 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar8 = uVar22;
  puVar8[1] = 0x4e;
  *(undefined8 *)(puVar8 + 2) = 5;
  puVar8[4] = 0;
  *(undefined2 *)(puVar8 + 5) = 0;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = iVar16;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar17) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  DAT_140e46c88 = puVar8;
  if (param_1[3] == 0x96) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
LAB_1400edf18:
  if (((int)param_1[5] < 2) || ((param_1[5] == 2 && ((int)param_1[3] < 100)))) {
    fVar20 = (float)param_1[10];
    dVar18 = (double)FUN_1403307c0();
    dVar18 = dVar18 * DAT_14053a430;
    fVar1 = (float)param_1[0xb];
    dVar19 = (double)FUN_140332d90();
    dVar19 = dVar19 * DAT_14053a430;
    FUN_1400c8410(DAT_140e449a0,0x19,7,fVar20,CONCAT44(uVar21,fVar1),
                  CONCAT22(uVar23,(short)DAT_140e418c8 * -0xb6),uVar24,uVar4,0xff,0xff,0xff,0xff,1,0
                 );
    FUN_1400c8410(DAT_140e449a0,0x19,7,param_1[10],param_1[0xb],(short)DAT_140e418c8 * 0xb6,uVar24,
                  uVar4,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e449a4,0x19,7,param_1[10],param_1[0xb],
                  *(undefined2 *)((longlong)param_1 + 0x42),uVar24,uVar4,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e449ac,0x19,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x11),
                  uVar24,uVar4,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e449a8,0x1b,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x11),
                  uVar24,uVar4,0xff,0xff,0xff,0xff,1,0);
    FUN_1400c8410(DAT_140e44c6c,0x1b,7,(float)dVar18 + fVar20,(float)dVar19 + fVar1,
                  *(undefined2 *)(param_1 + 0x11),uVar24,uVar4,0xff,0xff,0xff,0xff,1,0);
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


