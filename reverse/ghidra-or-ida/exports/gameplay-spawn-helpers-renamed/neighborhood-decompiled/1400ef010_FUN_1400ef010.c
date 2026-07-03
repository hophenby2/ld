// Function: FUN_1400ef010 @ 1400ef010
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ef010(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  longlong lVar13;
  int iVar14;
  short sVar15;
  int *piVar16;
  uint uVar17;
  ushort uVar18;
  ushort uVar19;
  bool bVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 in_stack_fffffffffffffec8;
  undefined2 uVar36;
  uint in_stack_fffffffffffffed0;
  undefined4 uVar37;
  undefined2 uVar38;
  undefined8 in_stack_fffffffffffffee0;
  
  iVar8 = DAT_140e418c8;
  uVar36 = (undefined2)((uint)in_stack_fffffffffffffec8 >> 0x10);
  fVar23 = (float)param_1[0xc];
  dVar26 = (double)DAT_140e418c8;
  dVar24 = (double)FUN_140332d90((dVar26 - 0.0) * DAT_14053a7f8 * DAT_14053a020 * DAT_140539d28);
  dVar24 = dVar24 * DAT_14053a268;
  FUN_140332d90((dVar26 - 0.0) * _DAT_14053a6a8 * DAT_14053a020 * DAT_140539d28);
  dVar26 = DAT_14053a1e8;
  fVar30 = (float)param_1[0xb];
  fVar29 = (float)param_1[10];
  FUN_1403300b4();
  fVar21 = (float)FUN_140334430(fVar29 - ((float)dVar24 + fVar23));
  fVar22 = (float)FUN_140334430();
  if (fVar21 + fVar22 < 0.0) {
    fVar21 = (float)FUN_1403352f8();
  }
  else {
    fVar21 = SQRT(fVar21 + fVar22);
  }
  dVar24 = DAT_14053a0b0;
  if (param_1[5] == 6) {
    dVar25 = (double)FUN_140332d90();
    FUN_1403300b4();
    fVar23 = (float)FUN_140334430(fVar29 - ((float)(dVar25 * dVar26) + fVar23));
    fVar21 = (float)FUN_140334430();
    if (fVar23 + fVar21 < 0.0) {
      fVar21 = (float)FUN_1403352f8();
    }
    else {
      fVar21 = SQRT(fVar23 + fVar21);
    }
LAB_1400ef243:
    uVar34 = SUB84(DAT_14053a020,0);
    uVar35 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar31 = SUB84(DAT_140539d28,0);
    uVar32 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    dVar26 = (double)FUN_1403307c0();
    fVar29 = (float)(dVar26 * ((double)fVar21 / dVar24)) + fVar29;
    param_1[10] = fVar29;
    dVar26 = (double)FUN_140332d90();
    fVar30 = (float)(dVar26 * ((double)fVar21 / dVar24)) + fVar30;
    param_1[0xb] = fVar30;
  }
  else {
    if (param_1[5] != 7) goto LAB_1400ef243;
    uVar34 = SUB84(DAT_14053a020,0);
    uVar35 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar31 = SUB84(DAT_140539d28,0);
    uVar32 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  }
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  iVar9 = 0;
  iVar12 = 0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffee0 = CONCAT44(uVar33,param_1[0x14]);
    uVar33 = param_1[0xb];
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],uVar33,in_stack_fffffffffffffed0,DAT_14053a4f0,
               in_stack_fffffffffffffee0,1,0);
    uVar36 = (undefined2)((uint)uVar33 >> 0x10);
    if (DAT_140e41af8 == 1) {
      puVar10 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar10,0);
        uVar36 = (undefined2)((uint)uVar33 >> 0x10);
        puVar10 = puVar10 + 1;
      } while ((longlong)puVar10 < 0x140e45178);
      _DAT_1407c777c = 0;
      param_1[5] = 7;
      DAT_140e419bc = -1;
LAB_1400ef3d1:
      param_1[0x14] = 0xfa;
    }
    else {
      if (DAT_140e41af8 == 2) {
        param_1[5] = 5;
        DAT_140e419bc = 2;
        goto LAB_1400ef3d1;
      }
      if (DAT_140e41af8 == 3) {
        param_1[5] = 3;
        DAT_140e419bc = 2;
        goto LAB_1400ef3d1;
      }
    }
    iVar8 = DAT_140e418c8;
    fVar29 = (float)param_1[10];
    DAT_140e41af8 = DAT_140e41af8 + -1;
    fVar30 = (float)param_1[0xb];
    param_1[0x17] = 0;
  }
  uVar38 = (undefined2)(in_stack_fffffffffffffed0 >> 0x10);
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  piVar16 = param_1 + 3;
  if (*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) <= DAT_140e45d74) {
    *piVar16 = 0xf0;
    param_1[5] = 7;
    param_1[0x14] = 0xfa;
    DAT_140e419bc = -1;
  }
  fVar23 = DAT_140e445d8;
  uVar11 = param_1[5];
  lVar13 = 0x3f;
  if (7 < uVar11) goto LAB_1400f0da4;
  switch(uVar11) {
  default:
    if ((uVar11 == 0) && (param_1[3] == 0)) {
      uVar31 = CONCAT22(uVar38,0x4000);
      stage_entity_spawn_candidate
                (0xde,99999999,0,0,DAT_14053ae88,uVar31,DAT_140539f40,CONCAT44(uVar33,300),1,
                 param_1[1]);
      uVar38 = (undefined2)((uint)uVar31 >> 0x10);
      iVar8 = DAT_140e418c8;
    }
    dVar24 = DAT_14053b258;
    fVar29 = DAT_14053aec0;
    fVar23 = DAT_14053ae30;
    dVar26 = DAT_140539d28;
    uVar31 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    if (iVar8 < 0x4b0) {
LAB_1400ef583:
      uVar32 = SUB84(dVar26,0);
      if (2999 < iVar8) goto LAB_1400ef591;
LAB_1400ef605:
      if (0x125b < iVar8) goto LAB_1400ef60d;
LAB_1400ef675:
      if (0x19c7 < iVar8) goto LAB_1400ef681;
LAB_1400ef735:
      if (0x2133 < iVar8) goto LAB_1400ef73d;
LAB_1400ef7a8:
      if (0x238b < iVar8) goto LAB_1400ef7b0;
LAB_1400ef81d:
      if (0x2c23 < iVar8) goto LAB_1400ef825;
LAB_1400ef892:
      if (11999 < iVar8) goto LAB_1400ef89a;
    }
    else {
      if (iVar8 < 3000) {
        dVar25 = (double)FUN_140332d90();
        dVar27 = (double)FUN_140332d90();
        dVar27 = dVar27 * DAT_14053a888;
        param_1[0xc] = (float)(dVar25 * 0.0) + fVar23;
        param_1[0xd] = (float)dVar27 - _DAT_14053b030;
        goto LAB_1400ef583;
      }
LAB_1400ef591:
      uVar32 = SUB84(DAT_140539d28,0);
      uVar31 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      if (iVar8 < 0x125c) {
        dVar26 = (double)FUN_140332d90();
        dVar25 = (double)FUN_140332d90();
        dVar25 = dVar25 * _DAT_14053a8a0;
        param_1[0xc] = (float)(dVar26 * 0.0) + fVar23;
        param_1[0xd] = (float)dVar25 - _DAT_14053b020;
        goto LAB_1400ef605;
      }
LAB_1400ef60d:
      if (iVar8 < 0x19c8) {
        dVar26 = (double)FUN_140332d90();
        dVar25 = (double)FUN_140332d90();
        dVar25 = dVar25 * DAT_14053a460;
        param_1[0xc] = (float)(dVar26 * dVar24) + fVar23;
        param_1[0xd] = (float)dVar25 - DAT_14053af28;
        goto LAB_1400ef675;
      }
LAB_1400ef681:
      if (iVar8 < 0x2134) {
        dVar26 = (double)FUN_140332d90();
        fVar21 = (float)(dVar26 * _DAT_14053a940) - DAT_14053adb4;
        dVar26 = (double)FUN_140332d90(((double)iVar8 - _DAT_14053ab38) * _DAT_14053a260 *
                                       (double)CONCAT44(uVar35,uVar34) *
                                       (double)CONCAT44(uVar31,uVar32));
        fVar30 = ((float)(dVar26 * _DAT_14053b1d8) - fVar29) - _DAT_14053b41c;
        dVar26 = (double)FUN_140332d90();
        param_1[0xc] = fVar21;
        param_1[0xd] = (float)((double)fVar30 * dVar26) - DAT_14053aee0;
        goto LAB_1400ef735;
      }
LAB_1400ef73d:
      if (iVar8 < 0x238c) {
        dVar26 = (double)FUN_140332d90();
        fVar30 = (float)(dVar26 * dVar24) + _DAT_14053af88;
        dVar26 = (double)FUN_140332d90();
        dVar26 = dVar26 * DAT_14053b1b0;
        param_1[0xc] = fVar30;
        param_1[0xd] = (float)dVar26 - fVar29;
        goto LAB_1400ef7a8;
      }
LAB_1400ef7b0:
      if (iVar8 < 0x2c24) {
        dVar26 = (double)FUN_140332d90();
        dVar24 = (double)FUN_140332d90();
        dVar24 = dVar24 * _DAT_14053a708;
        param_1[0xc] = (float)(dVar26 * 0.0) + fVar23;
        param_1[0xd] = (float)dVar24 - DAT_14053af04;
        goto LAB_1400ef81d;
      }
LAB_1400ef825:
      if (iVar8 < 12000) {
        dVar26 = (double)FUN_140332d90();
        dVar24 = (double)FUN_140332d90();
        dVar24 = dVar24 * DAT_14053a6d0;
        param_1[0xc] = (float)(dVar26 * 0.0) + fVar23;
        param_1[0xd] = (float)dVar24 - DAT_14053ade8;
        goto LAB_1400ef892;
      }
LAB_1400ef89a:
      param_1[0xc] = 0x43b40000;
      param_1[0xd] = 0x43160000;
    }
    iVar12 = param_1[5];
    if ((iVar12 == 0) && (param_1[3] == 0)) {
      *(undefined8 *)(param_1 + 10) = *(undefined8 *)(param_1 + 0xc);
LAB_1400ef8cc:
      if ((0x2e7b < iVar8) && (iVar8 < 0x2e87)) {
        iVar12 = iVar12 + 1;
        param_1[3] = 0;
        param_1[5] = iVar12;
        DAT_140e41b0c = 55000;
        param_1[7] = 55000;
        DAT_140e419bc = 0;
        DAT_140e4430c = 0x5dc;
        DAT_140e4192c = 0;
        DAT_140e418cc = 1;
      }
    }
    else if (iVar12 == 0) goto LAB_1400ef8cc;
    if (iVar8 == 12000) {
      param_1[0x15] = 0;
      param_1[5] = iVar12 + 1;
      param_1[3] = 0;
      DAT_140e419bc = 1;
    }
    break;
  case 2:
    iVar12 = *piVar16;
    if (0x27 < iVar12) {
      fVar30 = fVar30 + DAT_14053ad14;
      fVar21 = fVar29 + _DAT_14053ace4;
      fVar29 = fVar29 - _DAT_14053ace4;
      dVar27 = (double)FUN_1403300b4(IMAGE_DOS_HEADER_140000000.e_magic +
                                     (&switchD_1400ef468::switchdataD_1400f1228)[(int)uVar11],
                                     (double)(DAT_140e445d8 - fVar21));
      dVar25 = DAT_14053aba0;
      uVar32 = SUB84(DAT_14053aba0,0);
      uVar33 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
      dVar27 = dVar27 * DAT_14053aba0;
      dVar28 = (double)FUN_1403300b4();
      uVar31 = DAT_14053ac2c;
      dVar24 = DAT_14053a080;
      dVar26 = DAT_140539f80;
      uVar11 = (iVar12 + -0x28) % 0x35c;
      if (uVar11 < 400) {
        uVar18 = (ushort)(int)dVar27;
        uVar19 = (ushort)(int)(dVar28 * dVar25);
        if (uVar11 == ((int)uVar11 / 100) * 100) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar18;
          *(ushort *)(param_1 + 0x11) = uVar19;
          iVar8 = iVar9;
          do {
            iVar12 = iVar9;
            do {
              FUN_14006c2f0(10,0x35,fVar21,fVar30,
                            (short)iVar12 * 5000 + uVar18 + (short)iVar8 * -0xaf0 + -0x53fc,0,
                            dVar24 - (double)iVar8 * dVar26,1,0);
              iVar12 = iVar12 + 1;
            } while (iVar12 < 8);
            iVar12 = iVar9;
            do {
              uVar38 = 0;
              FUN_14006c2f0(10,0x36,fVar29,fVar30,
                            (short)iVar12 * 0xdf3 + (short)iVar8 * 0xaf0 + uVar19 + -0x2134,0,
                            dVar24 - (double)iVar8 * dVar26,1,0);
              iVar12 = iVar12 + 1;
            } while (iVar12 < 8);
            iVar8 = iVar8 + 1;
          } while (iVar8 < 4);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          uVar32 = SUB84(DAT_14053aba0,0);
          uVar33 = (undefined4)((ulonglong)DAT_14053aba0 >> 0x20);
          iVar8 = DAT_140e418c8;
          fVar23 = DAT_140e445d8;
        }
        else if (0x1d < (int)uVar11 % 100) goto LAB_1400efd85;
        uVar1 = DAT_14053a178;
        if ((int)uVar11 % 100 == (((int)uVar11 % 100) / 5) * 5) {
          FUN_14006c2f0(0xb,0,fVar21,fVar30,*(undefined2 *)((longlong)param_1 + 0x42),uVar31,
                        DAT_14053a178,1,0);
          uVar37 = uVar31;
          FUN_14006c2f0(0xb,0,fVar29,fVar30,*(undefined2 *)(param_1 + 0x11),uVar31,uVar1,1,0);
          uVar38 = (undefined2)((uint)uVar37 >> 0x10);
          uVar6 = *(ushort *)((longlong)param_1 + 0x42);
          iVar12 = ((int)dVar27 & 0xffffU) - (uint)uVar6;
          iVar8 = iVar12 + 0x10000;
          if (-0x8001 < iVar12) {
            iVar8 = iVar12;
          }
          iVar12 = iVar8 + -0x10000;
          if (iVar8 < 0x8001) {
            iVar12 = iVar8;
          }
          if (iVar12 < 1) {
            uVar5 = uVar6;
            if ((iVar12 < 0) && (uVar5 = uVar6 - 500, -500 < iVar12)) {
              uVar5 = uVar18;
            }
          }
          else {
            uVar5 = uVar18;
            if (499 < iVar12) {
              uVar5 = uVar6 + 500;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar5;
          uVar18 = *(ushort *)(param_1 + 0x11);
          iVar12 = ((int)(dVar28 * dVar25) & 0xffffU) - (uint)uVar18;
          iVar8 = iVar12 + 0x10000;
          if (-0x8001 < iVar12) {
            iVar8 = iVar12;
          }
          iVar12 = iVar8 + -0x10000;
          if (iVar8 < 0x8001) {
            iVar12 = iVar8;
          }
          if (iVar12 < 1) {
            uVar6 = uVar18;
            if ((iVar12 < 0) && (uVar6 = uVar18 - 500, -500 < iVar12)) {
              uVar6 = uVar19;
            }
          }
          else {
            uVar6 = uVar19;
            if (499 < iVar12) {
              uVar6 = uVar18 + 500;
            }
          }
          *(ushort *)(param_1 + 0x11) = uVar6;
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar8 = DAT_140e418c8;
          fVar23 = DAT_140e445d8;
        }
      }
LAB_1400efd85:
      dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - _DAT_14053b40c),
                                     (double)(fVar23 - (float)param_1[10]));
      uVar1 = DAT_14053a140;
      sVar7 = (short)(int)(dVar26 * (double)CONCAT44(uVar33,uVar32));
      if (((uVar11 - 400 < 400) && (iVar12 = (int)(uVar11 - 400) % 200, iVar12 < 0x3c)) &&
         (iVar12 == (iVar12 / 0xc) * 0xc)) {
        uVar17 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar17 = uVar17 * 0x800 ^ uVar17;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ DAT_140e9fd18 ^ uVar17;
        uVar17 = DAT_140e9fd1c / 0x7d1;
        sVar15 = (short)DAT_140e9fd1c;
        iVar8 = iVar9;
        do {
          uVar32 = uVar31;
          FUN_14006c2f0(3,8,fVar21,fVar30,
                        (short)iVar8 * 0x505 + sVar15 + (short)uVar17 * -0x7d1 + sVar7 + 0x18f0,
                        uVar31,uVar1,1,0);
          uVar38 = (undefined2)((uint)uVar32 >> 0x10);
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0xf);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar8 = DAT_140e418c8;
      }
      if (((uVar11 - 500 < 300) && (iVar12 = (int)(uVar11 - 500) % 200, iVar12 < 0x3c)) &&
         (iVar12 == (iVar12 / 0xc) * 0xc)) {
        uVar17 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
        uVar11 = uVar17 * 0x800 ^ uVar17;
        DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar11) >> 8 ^ DAT_140e9fd18 ^ uVar11;
        uVar11 = DAT_140e9fd1c / 0x7d1;
        sVar15 = (short)DAT_140e9fd1c;
        do {
          uVar32 = uVar31;
          FUN_14006c2f0(2,8,fVar29,fVar30,
                        (short)iVar9 * 0x505 + ((short)uVar11 * 0x7d1 - sVar15) + sVar7 + -0x5f40,
                        uVar31,uVar1,1,0);
          uVar38 = (undefined2)((uint)uVar32 >> 0x10);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 0xf);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar8 = DAT_140e418c8;
      }
    }
    lVar13 = 0x3f;
    break;
  case 3:
  case 5:
    if ((*piVar16 == 1) && (DAT_140e45d1c < 0x1000)) {
      puVar3 = (undefined8 *)_malloc_base(0x60);
      if (puVar3 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar3 + 0x14) = fVar29;
      *(float *)(puVar3 + 3) = fVar30;
      *(float *)((longlong)puVar3 + 0x1c) = fVar29;
      *(float *)(puVar3 + 4) = fVar30;
      *puVar3 = 1;
      puVar3[1] = 0x36;
      *(undefined4 *)(puVar3 + 2) = 0x28;
      *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
      puVar3[5] = 0;
      puVar3[6] = 0x3ff0000000000000;
      puVar3[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar3 + 8) = 0;
      *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
      *(undefined4 *)(puVar3 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
      puVar3[10] = 0xff;
      puVar3[0xb] = 0;
      if (bVar20) {
        DAT_140e45d78 = puVar3;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar3;
      }
      uVar11 = param_1[5];
      iVar8 = DAT_140e418c8;
      DAT_140e45d28 = puVar3;
    }
    piVar16 = param_1 + 3;
    iVar12 = *piVar16;
    if (iVar12 < 0x78) {
      FUN_14007ac00(param_1);
      uVar11 = param_1[5];
      iVar12 = *piVar16;
      iVar8 = DAT_140e418c8;
    }
    if (iVar12 == 0x78) {
      *(undefined8 *)(param_1 + 0x14) = 200;
      *piVar16 = 0;
      if (uVar11 == 3) {
        DAT_140e4430c = 0x5dc;
        DAT_140e41b0c = 55000;
        DAT_140e4192c = 0;
      }
      else if (uVar11 == 5) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 66000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = uVar11 + 1;
      DAT_140e419bc = 1;
    }
    lVar13 = 0x42;
    break;
  case 4:
    iVar12 = *piVar16;
    if (0x1d < iVar12) {
      fVar22 = fVar30 + _DAT_14053ad78;
      fVar30 = fVar30 + DAT_14053ad14;
      fVar21 = fVar29 + _DAT_14053ace4;
      fVar23 = fVar29 - _DAT_14053ace4;
      dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar22),
                                     (double)(DAT_140e445d8 - fVar29));
      uVar31 = DAT_140e41a50;
      dVar26 = dVar26 * DAT_14053aba0;
      iVar14 = iVar12 + -0x1e;
      if (iVar14 == (iVar14 / 0x96) * 0x96) {
        uVar32 = param_1[1];
        puVar3 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar3 = (undefined8 *)_malloc_base(0x60);
          if (puVar3 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar3 = 1;
          *(undefined4 *)(puVar3 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar3 + 0xc) = uVar31;
          puVar3[2] = 0x23;
          puVar3[3] = 0x431b0000;
          *(undefined4 *)(puVar3 + 4) = 0x431b0000;
          *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
          puVar3[5] = 0;
          puVar3[6] = 0x4014000000000000;
          puVar3[7] = 0x4014000000000000;
          *(undefined4 *)(puVar3 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
          *(undefined4 *)(puVar3 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
          *(undefined4 *)(puVar3 + 10) = 0x80;
          *(undefined4 *)((longlong)puVar3 + 0x54) = uVar32;
          puVar3[0xb] = 0;
          if (bVar20) {
            DAT_140e45d78 = puVar3;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar3;
          }
        }
        DAT_140e45d28 = puVar3;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
        iVar8 = DAT_140e418c8;
      }
      uVar19 = (ushort)(int)dVar26;
      if ((0x1d < iVar14) && (iVar12 + -0x3c == ((iVar12 + -0x3c) / 0x96) * 0x96)) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar19;
      }
      uVar31 = DAT_14053ac2c;
      uVar1 = DAT_14053a1b8;
      if (((0x1d < iVar14) && (iVar4 = (iVar12 + -0x3c) % 0x96, iVar4 < 0x28)) &&
         (iVar4 == (iVar4 / 0xd) * 0xd)) {
        sVar7 = *(short *)((longlong)param_1 + 0x42);
        iVar8 = iVar9;
        do {
          FUN_14006c2f0(0xd,0,fVar29,fVar22,(short)iVar8 * 2000 + sVar7 + -1000,uVar31,uVar1,1,0);
          uVar2 = DAT_14053a178;
          iVar8 = iVar8 + 1;
        } while (iVar8 < 2);
        sVar7 = *(short *)((longlong)param_1 + 0x42);
        iVar8 = iVar9;
        do {
          uVar32 = uVar31;
          FUN_14006c2f0(0xd,0,fVar29,fVar22,(short)iVar8 * 2000 + sVar7 + -2000,uVar31,uVar2,1,0);
          uVar38 = (undefined2)((uint)uVar32 >> 0x10);
          iVar8 = iVar8 + 1;
        } while (iVar8 < 3);
        uVar18 = *(ushort *)((longlong)param_1 + 0x42);
        iVar4 = ((int)dVar26 & 0xffffU) - (uint)uVar18;
        iVar8 = iVar4 + 0x10000;
        if (-0x8001 < iVar4) {
          iVar8 = iVar4;
        }
        iVar4 = iVar8 + -0x10000;
        if (iVar8 < 0x8001) {
          iVar4 = iVar8;
        }
        if (iVar4 < 1) {
          uVar6 = uVar18;
          if ((iVar4 < 0) && (uVar6 = uVar18 - 0x4b0, -0x4b0 < iVar4)) {
            uVar6 = uVar19;
          }
        }
        else {
          uVar6 = uVar19;
          if (0x4af < iVar4) {
            uVar6 = uVar18 + 0x4b0;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar6;
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        iVar8 = DAT_140e418c8;
      }
      if (((99 < iVar14) && (iVar4 = (iVar12 + -0x82) % 0x21c, iVar4 < 0xfa)) &&
         (iVar4 == (iVar4 / 6 + (iVar4 >> 0x1f) +
                   (int)(((longlong)iVar4 / 6 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                   6)) {
        sVar7 = *(short *)(param_1 + 3);
        iVar8 = iVar9;
        do {
          uVar32 = uVar31;
          FUN_14006c2f0(2,0x37,fVar23,fVar30,(short)iVar8 * -0x8000 + sVar7 * 0x164,uVar31,dVar24,1,
                        0);
          uVar38 = (undefined2)((uint)uVar32 >> 0x10);
          iVar8 = iVar8 + 1;
        } while (iVar8 < 2);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar8 = DAT_140e418c8;
      }
      if (((0x171 < iVar14) && (iVar12 = (iVar12 + -400) % 0x21c, iVar12 < 0xfa)) &&
         (iVar12 == (iVar12 / 6 + (iVar12 >> 0x1f) +
                    (int)(((longlong)iVar12 / 6 + ((longlong)iVar12 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 6)) {
        sVar7 = *(short *)(param_1 + 3);
        do {
          uVar32 = uVar31;
          FUN_14006c2f0(2,0x37,fVar21,fVar30,(short)iVar9 * -0x8000 + sVar7 * -0x164,uVar31,dVar24,1
                        ,0);
          uVar38 = (undefined2)((uint)uVar32 >> 0x10);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 2);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        iVar8 = DAT_140e418c8;
      }
    }
    lVar13 = 0x40;
    break;
  case 6:
    if ((0 < *piVar16) && (iVar12 = *piVar16 + -1, iVar12 == (iVar12 / 5) * 5)) {
      dVar26 = (double)FUN_140332d90();
      fVar30 = fVar30 + DAT_14053ad5c;
      fVar23 = (float)(dVar26 * _DAT_14053a320) + fVar29;
      dVar26 = (double)FUN_140332d90();
      fVar29 = (float)(dVar26 * _DAT_14053a320) + fVar29;
      dVar26 = (double)FUN_140332d90();
      sVar7 = (short)(int)(dVar26 * _DAT_14053abc8) + -0x4000;
      dVar26 = (double)FUN_140332d90();
      uVar31 = DAT_14053ac2c;
      uVar1 = DAT_14053a138;
      sVar15 = (short)(int)(dVar26 * _DAT_14053abc8) + -0x4000;
      FUN_14006c2f0(0xd,0xb,fVar23,fVar30,CONCAT22(uVar36,sVar7),DAT_14053ac2c,DAT_14053a138,
                    CONCAT44(uVar33,1),0);
      uVar2 = DAT_14053a208;
      FUN_14006c2f0(0xd,0xb,fVar23,fVar30,sVar7,uVar31,DAT_14053a208,1,0);
      FUN_14006c2f0(0xd,0xb,fVar29,fVar30,sVar15,uVar31,uVar1,1,0);
      FUN_14006c2f0(0xd,0xb,fVar29,fVar30,sVar15,uVar31,uVar2,1,0);
      uVar38 = (undefined2)((uint)uVar31 >> 0x10);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      iVar8 = DAT_140e418c8;
    }
    lVar13 = 0x41;
    break;
  case 7:
    iVar8 = *piVar16;
    if ((iVar8 < 0x96) || (iVar12 = 0xff, 0x9f < iVar8)) {
      puVar3 = DAT_140e45d28;
      if ((iVar8 == 1) && (DAT_140e45d1c < 0x1000)) {
        puVar3 = (undefined8 *)_malloc_base(0x60);
        if (puVar3 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)((longlong)puVar3 + 0x14) = fVar29;
        *(float *)(puVar3 + 3) = fVar30;
        *(float *)((longlong)puVar3 + 0x1c) = fVar29;
        *(float *)(puVar3 + 4) = fVar30;
        *puVar3 = 1;
        puVar3[1] = 0x36;
        *(undefined4 *)(puVar3 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
        puVar3[5] = 0;
        puVar3[6] = 0x3ff0000000000000;
        puVar3[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar3 + 8) = 0;
        *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
        *(undefined4 *)(puVar3 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
        puVar3[10] = 0xff;
        puVar3[0xb] = 0;
        if (bVar20) {
          DAT_140e45d78 = puVar3;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar3;
        }
      }
    }
    else {
      dVar26 = (double)FUN_140332d90(((double)iVar8 - DAT_14053a510) * DAT_14053a9d8 *
                                     (double)CONCAT44(uVar35,uVar34) *
                                     (double)CONCAT44(uVar32,uVar31));
      iVar12 = (int)(dVar26 * DAT_14053a5f8);
      puVar3 = DAT_140e45d28;
    }
    DAT_140e45d28 = puVar3;
    iVar8 = param_1[3];
    if (iVar8 < 0x96) {
      FUN_14007ac00(param_1);
      iVar8 = param_1[3];
      param_1[0xb] = (float)iVar8 * DAT_140539cc8 + (float)param_1[0xb];
    }
    uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
    if (iVar8 == 0x96) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar31 = param_1[0xb];
      uVar32 = param_1[10];
      puVar3 = DAT_140e45d28;
      lVar13 = DAT_140e47908;
      if (DAT_140e45d1c < 0x1000) {
        puVar3 = (undefined8 *)_malloc_base(0x60);
        if (puVar3 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar3 + 0x14) = uVar32;
        *(undefined4 *)(puVar3 + 3) = uVar31;
        *(undefined4 *)((longlong)puVar3 + 0x1c) = uVar32;
        *(undefined4 *)(puVar3 + 4) = uVar31;
        *puVar3 = 1;
        puVar3[1] = 0x11;
        *(undefined4 *)(puVar3 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
        puVar3[5] = 0;
        puVar3[6] = 0x3ff0000000000000;
        puVar3[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar3 + 8) = 0;
        *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
        *(undefined4 *)(puVar3 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
        puVar3[10] = 0xff;
        puVar3[0xb] = 0;
        if (bVar20) {
          DAT_140e45d78 = puVar3;
        }
        lVar13 = DAT_140e47908;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar3;
          lVar13 = DAT_140e47908;
        }
      }
      while (DAT_140e45d28 = puVar3,
            uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20), lVar13 != 0) {
        lVar13 = *(longlong *)(lVar13 + 0x238);
        FUN_140323ce8();
        puVar3 = DAT_140e45d28;
      }
      DAT_140e47908 = 0;
      DAT_140e9fd30 = 0;
    }
    uVar32 = DAT_140e41ab8;
    puVar10 = (undefined4 *)_malloc_base(0x48);
    if (puVar10 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    uVar38 = (undefined2)(in_stack_fffffffffffffed0 >> 0x10);
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar10 = uVar32;
    puVar10[1] = 0x4e;
    *(undefined8 *)(puVar10 + 2) = 5;
    puVar10[4] = 0;
    *(undefined2 *)(puVar10 + 5) = 0;
    *(undefined8 *)(puVar10 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar10 + 8) = 0x3ff0000000000000;
    puVar10[10] = 0xff;
    puVar10[0xb] = 0xff;
    puVar10[0xc] = 0xff;
    puVar10[0xd] = iVar12;
    *(undefined8 *)(puVar10 + 0xe) = 1;
    *(undefined8 *)(puVar10 + 0x10) = 0;
    if (bVar20) {
      DAT_140e46bf0 = puVar10;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar10;
    }
    lVar13 = 0x42;
    iVar8 = DAT_140e418c8;
    DAT_140e46c88 = puVar10;
    if (param_1[3] == 0xf0) {
      _DAT_1407c777c = 0x3f800000;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e4514c);
      FUN_14018a340(DAT_140e4514c,3,1);
      DAT_140e45100 = DAT_140e4514c;
      in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffff0000;
      DAT_140e44308 = DAT_1407c779c;
      stage_entity_spawn_candidate
                (0x141,100000,0,DAT_14053ae30,DAT_14053ae1c,in_stack_fffffffffffffed0,DAT_140539ef8,
                 CONCAT44(uVar31,0x50),1,0);
      uVar38 = (undefined2)(in_stack_fffffffffffffed0 >> 0x10);
      DAT_140e418cc = 1;
      DAT_140e419bc = 0;
      DAT_140e41b0c = 100000;
      DAT_140e4192c = 0;
      DAT_140e41af8 = 0x10;
      *param_1 = 0;
      iVar8 = DAT_140e418c8;
    }
  }
LAB_1400f0da4:
  dVar24 = DAT_14053a7f8;
  dVar26 = DAT_140539d28;
  if (0 < (int)param_1[5]) {
    DAT_140e418cc = 1;
  }
  dVar25 = (double)FUN_140332d90();
  dVar25 = dVar25 * DAT_14053a840;
  dVar26 = (double)FUN_140332d90(((double)iVar8 - DAT_14053a248) * dVar24 *
                                 (double)CONCAT44(uVar35,uVar34) * dVar26);
  sVar7 = (short)(int)(dVar26 * _DAT_14053a9d0);
  dVar26 = (double)FUN_1403307c0();
  fVar29 = (float)(dVar26 * DAT_14053a598) + DAT_14053ad70;
  dVar26 = (double)FUN_140332d90();
  uVar2 = _UNK_14053bb28;
  uVar1 = _DAT_14053bb20;
  uVar31 = CONCAT22(uVar38,sVar7 + 0x2000);
  fVar23 = (float)(dVar26 * DAT_14053a598) - DAT_14053ad40;
  FUN_1400c8410(DAT_140e44a28,0x11,7,fVar29 + (float)param_1[10],fVar23 + (float)param_1[0xb],uVar31
                ,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
  uVar11 = CONCAT22((short)((uint)uVar31 >> 0x10),-0x2000 - sVar7);
  FUN_1400c8410(DAT_140e44a28,0x11,7,(float)param_1[10] - fVar29,fVar23 + (float)param_1[0xb],uVar11
                ,uVar1,uVar2,0xff,0xff,0xff,0xff,1,1);
  uVar11 = uVar11 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44910)[lVar13],0x19,7,param_1[10],param_1[0xb],uVar11,uVar1,uVar2,0xff,
                0xff,0xff,0xff,1,0);
  sVar7 = (short)(int)dVar25;
  uVar31 = CONCAT22((short)(uVar11 >> 0x10),sVar7 + 0x3da8);
  FUN_1400c8410(DAT_140e44a1c,0x19,7,(float)param_1[10] + _DAT_14053ad6c,
                (float)param_1[0xb] - DAT_14053ace8,uVar31,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  uVar11 = CONCAT22((short)((uint)uVar31 >> 0x10),-0x3da8 - sVar7);
  FUN_1400c8410(DAT_140e44a1c,0x19,7,(float)param_1[10] - _DAT_14053ad6c,
                (float)param_1[0xb] - DAT_14053ace8,uVar11,uVar1,uVar2,0xff,0xff,0xff,0xff,1,1);
  dVar26 = (double)FUN_140332d90();
  uVar11 = uVar11 & 0xffff0000;
  FUN_1400c8410(DAT_140e44a20,0x19,7,param_1[10],
                (float)(dVar26 + dVar26) + 0.0 + (float)param_1[0xb],uVar11,uVar1,uVar2,0xff,0xff,
                0xff,0xff,1,0);
  dVar26 = (double)FUN_140332d90();
  FUN_1400c8410(DAT_140e44a24,0x19,7,param_1[10],
                ((float)(dVar26 + dVar26) - DAT_14053ad1c) + (float)param_1[0xb],uVar11 & 0xffff0000
                ,uVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  if (0 < (int)param_1[5]) {
    FUN_140004140(param_1);
    FUN_140002260();
  }
  return;
}


