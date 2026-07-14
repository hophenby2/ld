// Function: FUN_14008efc0 @ 14008efc0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008efc0(undefined4 *param_1)

{
  ushort uVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  short sVar18;
  short sVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined4 uVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  float fVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  undefined4 uVar36;
  float fVar37;
  undefined4 uVar38;
  uint in_stack_fffffffffffffee8;
  undefined4 in_stack_fffffffffffffef0;
  double in_stack_fffffffffffffef8;
  
  uVar15 = DAT_140e418c8;
  dVar24 = DAT_14053a020;
  dVar23 = DAT_140539d28;
  uVar16 = (undefined2)((uint)in_stack_fffffffffffffef0 >> 0x10);
  dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053a8d8 * DAT_14053a020
                                 * DAT_140539d28);
  iVar14 = param_1[5];
  fVar35 = (float)(dVar21 * DAT_14053a018) - DAT_14053ac5c;
  if (iVar14 == 0) {
    if (param_1[3] == 0) {
      in_stack_fffffffffffffef8 = 0.0;
      in_stack_fffffffffffffee8 = DAT_14053ade0;
      stage_entity_spawn_candidate
                (0x2f,param_1[8],1,0,DAT_14053ade0,CONCAT22(uVar16,0x4000),0,0x46,1,param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar14 = param_1[5];
      uVar15 = DAT_140e418c8;
    }
    dVar21 = DAT_14053a558;
    uVar6 = param_1[3];
    if (uVar6 < 0x5a) {
      dVar22 = (double)FUN_140332d90(((double)(int)uVar6 - 0.0) * DAT_14053a558 * dVar24 * dVar23);
      param_1[10] = (float)param_1[0xc] - (float)(700 - (int)(dVar22 * DAT_14053a840));
    }
    else {
      param_1[10] = (float)param_1[0xc] - (float)((int)uVar6 >> 0x1f & 700);
      if (((int)uVar6 < 0) || (0x59 < (int)uVar6)) {
        fVar26 = (float)param_1[0xd] + DAT_140539da8;
        param_1[0xb] = (float)((int)uVar6 >> 0x1f & 1000) + (float)param_1[0xd];
        param_1[0xd] = fVar26;
        if (uVar6 == 0x78) {
          param_1[0x15] = 0;
          iVar14 = iVar14 + 1;
          *(undefined8 *)(param_1 + 0x12) = 0x3fe6666666666666;
          param_1[5] = iVar14;
          param_1[3] = 0;
        }
        goto LAB_14008f21a;
      }
    }
    dVar23 = (double)FUN_140332d90(((double)(int)uVar6 - 0.0) * dVar21 * dVar24 * dVar23);
    fVar26 = (float)param_1[0xd] + DAT_140539da8;
    param_1[0xb] = (float)(1000 - (int)(dVar23 * DAT_14053a8f8)) + (float)param_1[0xd];
    param_1[0xd] = fVar26;
  }
LAB_14008f21a:
  fVar26 = DAT_14053ad9c;
  dVar23 = DAT_14053aba0;
  fVar37 = DAT_14053ad9c;
  if (iVar14 != 1) goto LAB_14008fc65;
  iVar14 = param_1[3];
  if (iVar14 < 0x514) {
    if (iVar14 == (iVar14 / 0x14) * 0x14) {
      uVar6 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      uVar4 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
      uVar4 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 3;
      uVar6 = uVar6 * 0x800 ^ uVar6;
      uVar4 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 4;
      uVar15 = (uVar15 + 0xd05 >> 0x1e ^ uVar15 + 0xd05) * 0x6c078965 + 1;
      param_1[0xc] = (float)(((uVar4 >> 0xb ^ uVar6) >> 8 ^ uVar4 ^ uVar6) % 0xf1 + 0xf0);
      DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar15 * 0x800 ^ uVar15;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      param_1[0xd] = (float)(DAT_140e9fd1c % 0x3d + 0x14);
    }
    uVar1 = *(ushort *)(param_1 + 0x10);
    dVar24 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                   (double)((float)param_1[0xc] - (float)param_1[10]));
    uVar13 = (ushort)(int)(dVar24 * dVar23);
    iVar5 = ((int)(dVar24 * dVar23) & 0xffffU) - (uint)uVar1;
    iVar11 = iVar5 + 0x10000;
    if (-0x8001 < iVar5) {
      iVar11 = iVar5;
    }
    iVar5 = iVar11 + -0x10000;
    if (iVar11 < 0x8001) {
      iVar5 = iVar11;
    }
    if (iVar5 < 1) {
      uVar8 = uVar1;
      if ((iVar5 < 0) && (uVar8 = uVar1 - 0x200, -0x200 < iVar5)) {
        uVar8 = uVar13;
      }
    }
    else {
      uVar8 = uVar13;
      if (0x1ff < iVar5) {
        uVar8 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar8;
    if (iVar14 - 0x208U < 100) {
      dVar24 = *(double *)(param_1 + 0x12) + DAT_140539dc8;
      goto LAB_14008f45b;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x10) = 0xc000;
    dVar24 = ((double)iVar14 - _DAT_14053a980) * DAT_140539e60;
LAB_14008f45b:
    *(double *)(param_1 + 0x12) = dVar24;
  }
  dVar24 = (double)FUN_1403307c0();
  fVar32 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar32;
  dVar24 = (double)FUN_140332d90();
  fVar31 = (float)(dVar24 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar31;
  fVar37 = fVar26;
  if (iVar14 < 0x514) {
    fVar31 = fVar31 + _DAT_14053adc8 + fVar35;
    dVar24 = (double)FUN_1403300b4();
    dVar21 = (double)FUN_1403300b4();
    iVar14 = DAT_140e419b8;
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x18;
    }
    else if (DAT_140e419b8 == 1) {
      iVar11 = 0x14;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar11 = 0x12;
    }
    else if (DAT_140e419b8 == 4) {
      iVar11 = 0x10;
    }
    iVar5 = 1;
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
        iVar5 = 3;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar5 = 4;
      }
      else if (DAT_140e419b8 == 4) {
        iVar5 = 5;
      }
    }
    iVar9 = 1;
    if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
      iVar9 = 3;
    }
    else if (DAT_140e419b8 == 2) {
      iVar9 = 4;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar9 = 6;
    }
    uVar36 = (undefined4)DAT_140539f40;
    uVar38 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    uVar29 = (undefined4)DAT_14053a0b0;
    uVar30 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    uVar25 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    uVar27 = uVar29;
    uVar28 = uVar30;
    if (DAT_140e419b8 == 0) {
      uVar27 = (int)DAT_14053a040;
      uVar28 = (int)((ulonglong)DAT_14053a040 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar27 = (int)DAT_14053a088;
      uVar28 = (int)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
            (uVar27 = uVar36, uVar28 = uVar38, DAT_140e419b8 == 4)) {
      uVar27 = (int)DAT_14053a0f8;
      uVar28 = uVar25;
    }
    uVar33 = (undefined4)DAT_14053a118;
    uVar34 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    if (7 < DAT_1407c7798) {
      iVar5 = 1;
      if (DAT_140e419b8 == 0) {
        iVar5 = 3;
      }
      else if (DAT_140e419b8 == 1) {
        iVar5 = 4;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar5 = 5;
      }
      uVar27 = uVar29;
      uVar28 = uVar30;
      if (((DAT_140e419b8 != 0) &&
          (uVar27 = (int)DAT_14053a0f8, uVar28 = uVar25, DAT_140e419b8 != 1)) &&
         ((uVar27 = uVar33, uVar28 = uVar34, DAT_140e419b8 != 2 &&
          ((DAT_140e419b8 != 3 && (uVar27 = uVar36, uVar28 = uVar38, DAT_140e419b8 == 4)))))) {
        uVar27 = (int)DAT_14053a138;
        uVar28 = (int)((ulonglong)DAT_14053a138 >> 0x20);
      }
    }
    iVar10 = param_1[3];
    uVar16 = (undefined2)(int)(dVar21 * dVar23);
    if (iVar10 == 0x5a) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar16;
LAB_14008f6ea:
      if ((iVar10 + -0x5a) % iVar11 == 0) {
        sVar18 = *(short *)((longlong)param_1 + 0x42) + 13000;
        iVar14 = (iVar10 + -0x5a) % 0x140;
        sVar19 = (short)iVar14;
        if (iVar14 < 0xa0) {
          sVar18 = sVar18 + sVar19 * -0xa2;
        }
        else {
          sVar18 = sVar18 + sVar19 * 0xa2 + 0x3580;
        }
        iVar10 = 0;
        do {
          in_stack_fffffffffffffef8 = (double)CONCAT44(uVar28,uVar27);
          in_stack_fffffffffffffee8 =
               CONCAT22((short)(in_stack_fffffffffffffee8 >> 0x10),(short)iVar10 * 400 + sVar18);
          FUN_1400709b0(4,0,fVar32 - fVar26,fVar31,in_stack_fffffffffffffee8,0,
                        in_stack_fffffffffffffef8,1,iVar5,iVar5 * 0x125c + -0x125c,0);
          iVar10 = iVar10 + 1;
          iVar14 = DAT_140e419b8;
        } while (iVar10 < iVar9);
      }
    }
    else if (iVar10 - 0x5aU < 0xa0) goto LAB_14008f6ea;
    iVar10 = param_1[3];
    uVar17 = (undefined2)(int)(dVar24 * dVar23);
    if (iVar10 == 0x140) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar17;
LAB_14008f801:
      if ((iVar10 + -0x140) % iVar11 == 0) {
        iVar14 = (iVar10 + -0x140) % 0x140;
        sVar18 = (short)iVar14;
        sVar19 = *(short *)((longlong)param_1 + 0x42) + sVar18 * -0xa2 + -0x6848;
        if (iVar14 < 0xa0) {
          sVar19 = sVar18 * 0xa2 + *(short *)((longlong)param_1 + 0x42) + -13000;
        }
        iVar11 = 0;
        do {
          in_stack_fffffffffffffef8 = (double)CONCAT44(uVar28,uVar27);
          in_stack_fffffffffffffee8 =
               CONCAT22((short)(in_stack_fffffffffffffee8 >> 0x10),sVar19 + (short)iVar11 * -400);
          FUN_1400709b0(4,0,fVar32 + fVar26,fVar31,in_stack_fffffffffffffee8,0,
                        in_stack_fffffffffffffef8,1,iVar5,iVar5 * 0x125c + -0x125c,0);
          iVar11 = iVar11 + 1;
          iVar14 = DAT_140e419b8;
        } while (iVar11 < iVar9);
      }
    }
    else if (iVar10 - 0x140U < 0xa0) goto LAB_14008f801;
    iVar11 = 1;
    if (iVar14 == 0) {
      iVar11 = 0x46;
    }
    else if (iVar14 == 1) {
      iVar11 = 0x30;
    }
    else if (iVar14 == 2) {
      iVar11 = 0x26;
    }
    else if (iVar14 == 3) {
      iVar11 = 0x20;
    }
    else if (iVar14 == 4) {
      iVar11 = 0x1c;
    }
    iVar5 = 1;
    if (iVar14 == 0) {
      iVar5 = 6000;
    }
    else if (iVar14 == 1) {
      iVar5 = 4000;
    }
    else if (iVar14 == 2) {
      iVar5 = 0xc80;
    }
    else if (iVar14 == 3) {
      iVar5 = 0xaf0;
    }
    else if (iVar14 == 4) {
      iVar5 = 0xa28;
    }
    if (iVar14 == 0) {
      uVar27 = (int)DAT_14053a040;
      uVar28 = (int)((ulonglong)DAT_14053a040 >> 0x20);
    }
    else if (iVar14 == 1) {
      uVar27 = (int)DAT_14053a088;
      uVar28 = (int)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else {
      uVar27 = uVar29;
      uVar28 = uVar30;
      if (((iVar14 != 2) && (iVar14 != 3)) && (uVar27 = uVar36, uVar28 = uVar38, iVar14 == 4)) {
        uVar27 = uVar33;
        uVar28 = uVar34;
      }
    }
    iVar9 = param_1[3];
    iVar10 = (iVar9 + -0x226) / iVar11;
    iVar7 = (iVar9 + -0x226) % iVar11;
    iVar12 = iVar10 + 1;
    dVar23 = (double)CONCAT44(uVar28,uVar27);
    if (7 < DAT_1407c7798) {
      if (iVar14 != 0) {
        if (iVar14 == 1) {
          uVar29 = (int)DAT_14053a0f8;
          uVar30 = (int)((ulonglong)DAT_14053a0f8 >> 0x20);
        }
        else {
          uVar29 = uVar33;
          uVar30 = uVar34;
          if (((iVar14 != 2) && (iVar14 != 3)) && (uVar29 = uVar36, uVar30 = uVar38, iVar14 == 4)) {
            uVar29 = (int)DAT_14053a158;
            uVar30 = (int)((ulonglong)DAT_14053a158 >> 0x20);
          }
        }
      }
      dVar23 = (double)CONCAT44(uVar30,uVar29);
    }
    dVar23 = dVar23 + (double)iVar7 * DAT_140539e60;
    if ((iVar9 - 0x226U < 0x2ee) && (iVar7 == 0)) {
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar17;
      *(undefined2 *)(param_1 + 0x11) = uVar16;
    }
    else {
      fVar37 = DAT_14053ad9c;
      if (0x2ed < iVar9 - 0x226U) goto LAB_14008fb20;
    }
    uVar27 = DAT_14053ac2c;
    fVar37 = DAT_14053ad9c;
    if ((iVar9 + -0x226) % iVar11 < 0x14) {
      uVar15 = (iVar9 + -0x226) % iVar11 & 0x80000003;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xfffffffc) + 1;
      }
      if (uVar15 == 0) {
        iVar10 = iVar10 * iVar5;
        uVar28 = CONCAT22((short)(in_stack_fffffffffffffee8 >> 0x10),
                          *(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(9,0,fVar32 + fVar26,fVar31,uVar28,DAT_14053ac2c,dVar23,1,iVar12,iVar10,0);
        in_stack_fffffffffffffee8 =
             CONCAT22((short)((uint)uVar28 >> 0x10),*(undefined2 *)(param_1 + 0x11));
        FUN_1400709b0(9,0,fVar32 - fVar26,fVar31,in_stack_fffffffffffffee8,uVar27,dVar23,1,iVar12,
                      iVar10,0);
        fVar37 = DAT_14053ad9c;
        in_stack_fffffffffffffef8 = dVar23;
      }
    }
  }
LAB_14008fb20:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0x1e);
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffee8 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffef8 & 0xffffffff00000000);
    uVar27 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar2 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar2 = (undefined8 *)_malloc_base(0x60);
      if (puVar2 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar2 = 1;
      *(undefined4 *)(puVar2 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar2 + 0xc) = uVar27;
      puVar2[2] = 0x6f;
      puVar2[3] = 0;
      *(undefined4 *)(puVar2 + 4) = 0;
      *(undefined2 *)((longlong)puVar2 + 0x24) = 0;
      puVar2[5] = 0;
      puVar2[6] = 0x3ff0000000000000;
      puVar2[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar2 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar2 + 0x44) = 0xff;
      *(undefined4 *)(puVar2 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar2 + 0x4c) = 0xff;
      puVar2[10] = 0xff;
      puVar2[0xb] = 0;
      if (bVar20) {
        DAT_140e45d78 = puVar2;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar2;
      }
    }
    DAT_140e45d28 = puVar2;
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 1;
    param_1[3] = 0;
  }
LAB_14008fc65:
  if (((int)param_1[7] < 1) && (param_1[0x15] == 1)) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)(int)param_1[3] * DAT_140539ce4 + (float)param_1[0xb];
    if (param_1[3] == 0x3c) {
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  uVar27 = DAT_140e44940;
  fVar31 = DAT_14053acfc;
  fVar26 = (float)param_1[10];
  fVar32 = fVar35 + (float)param_1[0xb] + DAT_14053acfc;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar3[3] = fVar26 + fVar37;
  puVar3[4] = fVar32;
  *puVar3 = uVar27;
  puVar3[1] = 0x20;
  puVar3[2] = 7;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar20) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar3;
  }
  uVar27 = DAT_140e44940;
  fVar26 = (float)param_1[0xb];
  fVar32 = (float)param_1[10];
  DAT_140e46c88 = puVar3;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar3[4] = fVar35 + fVar26 + fVar31;
  puVar3[3] = fVar32 - fVar37;
  *puVar3 = uVar27;
  puVar3[1] = 0x20;
  puVar3[2] = 7;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  puVar3[0xe] = 1;
  puVar3[0xf] = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar20) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  uVar28 = DAT_140e4493c;
  fVar35 = (float)param_1[0xb];
  uVar27 = param_1[10];
  DAT_140e46c88 = puVar3;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar3[3] = uVar27;
  puVar3[4] = fVar35 + fVar31;
  *puVar3 = uVar28;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[1] = 0x20;
  puVar3[2] = 7;
  *(undefined2 *)(puVar3 + 5) = 0;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar20) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  DAT_140e46c88 = puVar3;
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ae48) ||
        (DAT_140e445d8 / DAT_14053ab70 + DAT_14053afb0 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b404)) || (DAT_14053afd4 < (float)param_1[0xb])) &&
     (param_1[0x15] == 0)) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
  return;
}


