// Function: FUN_140080fb0 @ 140080fb0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140080fb0(undefined4 *param_1)

{
  int iVar1;
  short sVar2;
  double dVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  undefined2 uVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  undefined4 uVar26;
  float fVar27;
  float fVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  float fVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  float in_stack_fffffffffffffed8;
  uint in_stack_fffffffffffffee0;
  undefined4 uVar39;
  undefined4 uVar40;
  double in_stack_fffffffffffffee8;
  
  uVar15 = DAT_140e418c8;
  dVar23 = DAT_14053a8d8;
  dVar24 = DAT_14053a020;
  dVar25 = DAT_140539d28;
  dVar22 = (double)(int)DAT_140e418c8;
  dVar21 = (double)FUN_140332d90();
  dVar3 = DAT_14053a018;
  uVar33 = SUB84(DAT_14053a018,0);
  uVar34 = (undefined4)((ulonglong)DAT_14053a018 >> 0x20);
  fVar18 = (float)(dVar21 * DAT_14053a018) - DAT_14053ac5c;
  dVar21 = (double)FUN_140332d90((dVar22 - _DAT_14053a280) * dVar23 * dVar24 * dVar25);
  dVar22 = (double)FUN_140332d90((dVar22 - _DAT_14053a348) * dVar23 * dVar24 * dVar25);
  dVar23 = (double)FUN_140332d90();
  uVar37 = SUB84(DAT_14053a070,0);
  uVar38 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
  fVar27 = (float)(dVar23 * DAT_14053a070) + 0.0;
  dVar23 = (double)FUN_140332d90();
  uVar40 = DAT_14053b3b0;
  fVar36 = DAT_14053aca8;
  dVar23 = dVar23 * _DAT_14053aa40;
  iVar11 = param_1[5];
  if (iVar11 == 0) {
    if (param_1[3] == 0) {
      uVar39 = CONCAT22((short)(in_stack_fffffffffffffee0 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x11,7000,0x28,DAT_14053ad80,DAT_14053aca8,uVar39,0,0x3c,1,param_1[1]);
      in_stack_fffffffffffffee8 = 0.0;
      in_stack_fffffffffffffee0 = CONCAT22((short)((uint)uVar39 >> 0x10),0x4000);
      in_stack_fffffffffffffed8 = fVar36;
      stage_entity_spawn_candidate
                (0x11,7000,0x28,uVar40,fVar36,in_stack_fffffffffffffee0,0,0x3c,1,param_1[1]);
      fVar28 = DAT_14053b330;
      if (DAT_1407c7798 == 1) {
        uVar40 = CONCAT22((short)(in_stack_fffffffffffffee0 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x11,7000,0x28,DAT_14053ae00,DAT_14053b330,uVar40,0,0x3c,1,param_1[1]);
        in_stack_fffffffffffffee8 = 0.0;
        in_stack_fffffffffffffee0 = CONCAT22((short)((uint)uVar40 >> 0x10),0x4000);
        stage_entity_spawn_candidate
                  (0x11,7000,0x28,DAT_14053b3f4,fVar28,in_stack_fffffffffffffee0,0,0x3c,1,param_1[1]
                  );
        in_stack_fffffffffffffed8 = fVar28;
      }
      uVar40 = DAT_140e472bc;
      param_1[0x17] = 4;
      FUN_140184700(DAT_140e44190 * 0x19,uVar40);
      FUN_14018a340(DAT_140e472bc,1,1);
      iVar11 = param_1[5];
      uVar15 = DAT_140e418c8;
    }
    iVar12 = param_1[3];
    if (iVar12 < 0) {
      fVar28 = (float)param_1[0xd];
      fVar19 = fVar28 + DAT_14053afb0;
    }
    else {
      if (0x59 < iVar12) {
        fVar28 = (float)param_1[0xd] + DAT_140539da8;
        param_1[0xb] = (float)param_1[0xd] + 0.0;
        param_1[0xd] = fVar28;
        if (iVar12 == 0x78) {
          param_1[0x15] = 0;
          iVar11 = iVar11 + 1;
          *(undefined8 *)(param_1 + 0x12) = 0x3fe6666666666666;
          param_1[5] = iVar11;
          param_1[3] = 0;
        }
        goto LAB_140081391;
      }
      dVar25 = (double)FUN_140332d90(((double)iVar12 - 0.0) * DAT_14053a558 * dVar24 * dVar25);
      fVar28 = (float)param_1[0xd];
      fVar19 = (float)(1000 - (int)(dVar25 * DAT_14053a8f8)) + fVar28;
    }
    fVar28 = fVar28 + DAT_140539da8;
    param_1[0xb] = fVar19;
    param_1[0xd] = fVar28;
  }
LAB_140081391:
  uVar4 = _UNK_14053bb28;
  uVar39 = _UNK_14053bb24;
  uVar40 = _DAT_14053bb20;
  dVar25 = DAT_14053aba0;
  if (iVar11 != 1) goto LAB_140081c27;
  iVar11 = param_1[3];
  if (iVar11 < 900) {
    if (iVar11 == (iVar11 / 0x14) * 0x14) {
      uVar9 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
      uVar6 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
      uVar6 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 3;
      uVar9 = uVar9 * 0x800 ^ uVar9;
      uVar6 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 4;
      uVar15 = (uVar15 + 0x457 >> 0x1e ^ uVar15 + 0x457) * 0x6c078965 + 1;
      param_1[0xc] = (float)(((uVar6 >> 0xb ^ uVar9) >> 8 ^ uVar9 ^ uVar6) % 0x141 + 200);
      DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar15 = uVar15 * 0x800 ^ uVar15;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar15) >> 8 ^ DAT_140e9fd18 ^ uVar15;
      param_1[0xd] = (float)(DAT_140e9fd1c % 0x29 + 0xb4);
    }
    uVar8 = *(ushort *)(param_1 + 0x10);
    dVar24 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                   (double)((float)param_1[0xc] - (float)param_1[10]));
    uVar14 = (ushort)(int)(dVar24 * dVar25);
    iVar7 = ((int)(dVar24 * dVar25) & 0xffffU) - (uint)uVar8;
    iVar12 = iVar7 + 0x10000;
    if (-0x8001 < iVar7) {
      iVar12 = iVar7;
    }
    iVar7 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar7 = iVar12;
    }
    if (iVar7 < 1) {
      uVar10 = uVar8;
      if ((iVar7 < 0) && (uVar10 = uVar8 - 0x200, -0x200 < iVar7)) {
        uVar10 = uVar14;
      }
    }
    else {
      uVar10 = uVar14;
      if (0x1ff < iVar7) {
        uVar10 = uVar8 + 0x200;
      }
    }
  }
  else {
    *(double *)(param_1 + 0x12) = ((double)iVar11 - _DAT_14053a8b8) * DAT_140539e60;
    uVar10 = 0xc000;
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  dVar25 = (double)FUN_1403307c0();
  fVar19 = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar19;
  dVar25 = (double)FUN_140332d90();
  fVar28 = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar28;
  if (iVar11 < 900) {
    fVar35 = (fVar28 + fVar18) - DAT_14053ac9c;
    dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar28),(double)(DAT_140e445d8 - fVar19)
                                  );
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x78;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      iVar11 = 0x3c;
    }
    iVar12 = 1;
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
        iVar12 = 3;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar12 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 7;
      }
    }
    uVar29 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    uVar30 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    uVar20 = (undefined4)DAT_14053a0b0;
    uVar26 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    uVar31 = uVar33;
    uVar32 = uVar34;
    if (((DAT_140e419b8 != 0) && (uVar31 = uVar37, uVar32 = uVar38, DAT_140e419b8 != 1)) &&
       ((uVar31 = uVar20, uVar32 = uVar26, DAT_140e419b8 != 2 &&
        ((uVar31 = (int)DAT_14053a0f8, uVar32 = uVar30, DAT_140e419b8 != 3 &&
         (uVar31 = uVar40, uVar32 = uVar39, DAT_140e419b8 == 4)))))) {
      uVar31 = (int)DAT_14053a138;
      uVar32 = uVar29;
    }
    iVar7 = 1;
    if (DAT_140e419b8 == 0) {
      iVar7 = 100;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 0x50;
    }
    else if (DAT_140e419b8 == 2) {
      iVar7 = 0x46;
    }
    else if (DAT_140e419b8 == 3) {
      iVar7 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar7 = 0x32;
    }
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 5;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 7;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar13 = 9;
    }
    else if (DAT_140e419b8 == 4) {
      iVar13 = 0xb;
    }
    if ((((DAT_140e419b8 != 0) && (uVar33 = uVar37, uVar34 = uVar38, DAT_140e419b8 != 1)) &&
        (uVar33 = uVar20, uVar34 = uVar26, DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 != 3 && (uVar33 = uVar40, uVar34 = uVar39, DAT_140e419b8 == 4)))) {
      uVar33 = (int)DAT_14053a118;
      uVar34 = (int)((ulonglong)DAT_14053a118 >> 0x20);
    }
    if (7 < DAT_1407c7798) {
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 3;
      }
      else if (DAT_140e419b8 == 1) {
LAB_1400817d8:
        iVar12 = 5;
      }
      else {
        if (DAT_140e419b8 != 2) {
          if (DAT_140e419b8 == 3) goto LAB_1400817d8;
          if (DAT_140e419b8 != 4) goto LAB_1400817e4;
        }
        iVar12 = 7;
      }
LAB_1400817e4:
      if (DAT_140e419b8 == 0) {
        uVar31 = (int)DAT_14053a088;
        uVar32 = (int)((ulonglong)DAT_14053a088 >> 0x20);
      }
      else if (DAT_140e419b8 == 1) {
        uVar31 = (int)DAT_14053a0d0;
        uVar32 = (int)((ulonglong)DAT_14053a0d0 >> 0x20);
      }
      else {
        uVar31 = (int)DAT_14053a0f8;
        uVar32 = uVar30;
        if ((DAT_140e419b8 != 2) &&
           ((DAT_140e419b8 == 3 || (uVar31 = uVar40, uVar32 = uVar39, DAT_140e419b8 == 4)))) {
          uVar31 = (int)DAT_14053a138;
          uVar32 = uVar29;
        }
      }
    }
    iVar1 = param_1[3];
    uVar15 = iVar1 - 0x1e;
    uVar16 = (undefined2)(int)(dVar25 * DAT_14053aba0);
    if (uVar15 < 0x10e) {
      if ((int)uVar15 % iVar11 == 0) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar16;
      }
      else if ((0x10d < uVar15) || (0x13 < (int)uVar15 % iVar11)) goto LAB_1400819d8;
      dVar25 = DAT_140539dc8;
      iVar11 = (int)uVar15 % iVar11;
      if (iVar11 == (iVar11 / 3 + (iVar11 >> 0x1f) +
                    (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3) {
        if (0xef < iVar1) {
          iVar12 = iVar12 + 2;
        }
        in_stack_fffffffffffffee8 = (double)iVar1 * DAT_140539dc8 + (double)CONCAT44(uVar32,uVar31);
        in_stack_fffffffffffffee0 = 0;
        in_stack_fffffffffffffed8 =
             (float)CONCAT22((short)((uint)in_stack_fffffffffffffed8 >> 0x10),
                             *(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(0,0,fVar19,fVar35,in_stack_fffffffffffffed8,0,in_stack_fffffffffffffee8,1,
                      iVar12,18000,0);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffee8 =
               ((double)(int)param_1[3] * dVar25 + (double)CONCAT44(uVar32,uVar31)) - DAT_140539fe8;
          in_stack_fffffffffffffee0 = 0;
          in_stack_fffffffffffffed8 =
               (float)CONCAT22((short)((uint)in_stack_fffffffffffffed8 >> 0x10),
                               *(undefined2 *)((longlong)param_1 + 0x42));
          FUN_1400709b0(0,0,fVar19,fVar35,in_stack_fffffffffffffed8,0,in_stack_fffffffffffffee8,1,
                        iVar12 - 1U,(int)(18000 / (ulonglong)(iVar12 - 1U)) * (iVar12 + -2) & 0xffff
                        ,0);
        }
        uVar10 = *(ushort *)((longlong)param_1 + 0x42);
        dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar35),
                                       (double)(DAT_140e445d8 - fVar19));
        uVar8 = (ushort)(int)(dVar25 * DAT_14053aba0);
        iVar12 = ((int)(dVar25 * DAT_14053aba0) & 0xffffU) - (uint)uVar10;
        iVar11 = iVar12 + 0x10000;
        if (-0x8001 < iVar12) {
          iVar11 = iVar12;
        }
        iVar12 = iVar11 + -0x10000;
        if (iVar11 < 0x8001) {
          iVar12 = iVar11;
        }
        if (iVar12 < 1) {
          uVar14 = uVar10;
          if ((iVar12 < 0) && (uVar14 = uVar10 - 0x40, -0x40 < iVar12)) {
            uVar14 = uVar8;
          }
        }
        else {
          uVar14 = uVar8;
          if (0x3f < iVar12) {
            uVar14 = uVar10 + 0x40;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar14;
      }
    }
LAB_1400819d8:
    dVar24 = DAT_14053a6e0;
    dVar25 = DAT_140539da0;
    iVar11 = param_1[3];
    fVar36 = DAT_14053aca8;
    if ((iVar11 - 0x1a4U < 0x1e0) && ((iVar11 + -0x1a4) % iVar7 == 0)) {
      iVar13 = iVar13 + ((iVar11 + -0x1a4) / iVar7) * 2;
      in_stack_fffffffffffffee8 =
           ((double)iVar11 - DAT_14053a6e0) * DAT_140539da0 + (double)CONCAT44(uVar34,uVar33);
      in_stack_fffffffffffffee0 = 0;
      in_stack_fffffffffffffed8 =
           (float)CONCAT22((short)((uint)in_stack_fffffffffffffed8 >> 0x10),uVar16);
      FUN_1400709b0(2,0,fVar19,fVar35,in_stack_fffffffffffffed8,0,in_stack_fffffffffffffee8,1,iVar13
                    ,0x8000,0);
      fVar36 = DAT_14053aca8;
      if (2 < DAT_140e419b8) {
        in_stack_fffffffffffffee8 =
             ((double)(int)param_1[3] - dVar24) * dVar25 + (double)CONCAT44(uVar34,uVar33) +
             DAT_140539fc8;
        in_stack_fffffffffffffee0 = 0;
        in_stack_fffffffffffffed8 =
             (float)CONCAT22((short)((uint)in_stack_fffffffffffffed8 >> 0x10),uVar16);
        FUN_1400709b0(2,0,fVar19,fVar35,in_stack_fffffffffffffed8,0,in_stack_fffffffffffffee8,1,
                      iVar13,0x8000,0);
        fVar36 = DAT_14053aca8;
      }
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0x1e);
    in_stack_fffffffffffffee0 = 0;
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,(uint)in_stack_fffffffffffffed8 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffee8 & 0xffffffff00000000);
    uVar33 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar5 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar5 = (undefined8 *)_malloc_base(0x60);
      if (puVar5 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar17 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar5 = 1;
      *(undefined4 *)(puVar5 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar5 + 0xc) = uVar33;
      puVar5[2] = 0x6f;
      puVar5[3] = 0;
      *(undefined4 *)(puVar5 + 4) = 0;
      *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
      puVar5[5] = 0;
      puVar5[6] = 0x3ff0000000000000;
      puVar5[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar5 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
      *(undefined4 *)(puVar5 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
      puVar5[10] = 0xff;
      puVar5[0xb] = 0;
      if (bVar17) {
        DAT_140e45d78 = puVar5;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar5;
      }
    }
    DAT_140e45d28 = puVar5;
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 1;
    param_1[3] = 0;
  }
LAB_140081c27:
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
  fVar28 = DAT_14053ad1c;
  in_stack_fffffffffffffee0 = in_stack_fffffffffffffee0 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b44,0x20,7,param_1[10],
                (float)(dVar22 * dVar3) + 0.0 + (float)param_1[0xb] + DAT_14053ad1c,
                in_stack_fffffffffffffee0,CONCAT44(uVar39,uVar40),uVar4,0xff,0xff,0xff,0xff,1,0);
  in_stack_fffffffffffffee0 = in_stack_fffffffffffffee0 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b40,0x20,7,param_1[10],
                (float)(dVar21 * dVar3) + 0.0 + (float)param_1[0xb] + DAT_14053acbc,
                in_stack_fffffffffffffee0,CONCAT44(uVar39,uVar40),uVar4,0xff,0xff,0xff,0xff,1,0);
  sVar2 = (short)(int)dVar23;
  uVar33 = CONCAT22((short)(in_stack_fffffffffffffee0 >> 0x10),sVar2 + 10000);
  FUN_1400c8410(DAT_140e44b3c,0x20,7,(float)param_1[10] + fVar36,
                (fVar18 + (float)param_1[0xb]) - fVar28,uVar33,CONCAT44(uVar39,uVar40),uVar4,0xff,
                0xff,0xff,0xff,1,0);
  uVar15 = CONCAT22((short)((uint)uVar33 >> 0x10),-10000 - sVar2);
  FUN_1400c8410(DAT_140e44b3c,0x20,7,(float)param_1[10] - fVar36,
                (fVar18 + (float)param_1[0xb]) - fVar28,uVar15,CONCAT44(uVar39,uVar40),uVar4,0xff,
                0xff,0xff,0xff,1,1);
  uVar15 = uVar15 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b38,0x20,7,param_1[10],(fVar18 + (float)param_1[0xb]) - DAT_14053ace8,
                uVar15,CONCAT44(uVar39,uVar40),uVar4,0xff,0xff,0xff,0xff,1,0);
  uVar15 = CONCAT22((short)(uVar15 >> 0x10),4000);
  FUN_1400c8410(DAT_140e44b48,0x20,7,(float)param_1[10] - _DAT_14053ad24,
                (fVar27 + (float)param_1[0xb]) - fVar36,uVar15,CONCAT44(uVar39,uVar40),uVar4,0xff,
                0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44b4c,0x20,7,(float)param_1[10] + DAT_14053ad10,
                fVar27 + (float)param_1[0xb] + fVar36,uVar15 & 0xffff0000,CONCAT44(uVar39,uVar40),
                uVar4,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ae14) ||
        (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af80 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b3f8)) || (DAT_14053afbc < (float)param_1[0xb])) &&
     (param_1[0x15] == 0)) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
  return;
}


