// Function: FUN_1400dcd10 @ 1400dcd10
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400dcd10(undefined4 *param_1)

{
  int *piVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined4 *puVar14;
  longlong lVar15;
  undefined4 uVar16;
  int iVar17;
  float *pfVar18;
  uint uVar19;
  bool bVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 uVar28;
  undefined2 uVar29;
  uint uVar30;
  undefined2 uVar31;
  ulonglong uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  
  uVar44 = 0x51;
  uVar43 = 0x50;
  uVar42 = 0x52;
  uVar41 = 0x53;
  uVar40 = 0x54;
  uVar39 = 0x55;
  uVar38 = 0x56;
  uVar37 = 0x57;
  uVar36 = 0x56;
  uVar35 = 0x57;
  uVar34 = 0x55;
  uVar33 = 0x54;
  uVar32 = 0x53;
  dVar23 = 4.05133829589822e-322;
  uVar30 = 0;
  uVar29 = 0;
  iVar8 = FUN_1400c9580(DAT_140e418c8,0,5,0x10,0x50,0x51,0x52,0x53,0x54,0x55,0x57,0x56,0x57,0x56,
                        0x55,0x54,0x53,0x52,0x50,0x51);
  uVar31 = (undefined2)(uVar30 >> 0x10);
  iVar9 = 0;
  iVar10 = 0x7f;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    uVar34 = 0;
    uVar33 = 1;
    uVar32 = (ulonglong)(uint)param_1[0x14];
    uVar28 = param_1[0xb];
    uVar30 = uVar30 & 0xffff0000;
    dVar23 = DAT_14053a4f0;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],uVar28,uVar30,DAT_14053a4f0,uVar32,1,0);
    uVar29 = (undefined2)((uint)uVar28 >> 0x10);
    uVar31 = (undefined2)(uVar30 >> 0x10);
    if (DAT_140e41af8 == 1) {
      param_1[5] = 3;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539d28;
  dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a498 * DAT_14053a020
                                 * DAT_140539d28);
  uVar7 = _UNK_14053bb28;
  dVar6 = _DAT_14053bb20;
  dVar4 = DAT_14053a5f8;
  uVar28 = SUB84(DAT_14053a1e8,0);
  iVar11 = param_1[5];
  fVar27 = (float)(dVar21 * DAT_14053a1e8) + 0.0 + DAT_140e45d24 + (float)param_1[0xc];
  param_1[10] = fVar27;
  if (iVar11 == 0) {
    iVar9 = 0;
    if (param_1[3] == 0) {
      stage_entity_spawn_candidate
                (0x79,99999999,0,0,DAT_14053ad50,CONCAT22(uVar31,0x4000),dVar6,0x46,1,0);
      uVar33 = DAT_14053ad2c;
      stage_entity_spawn_candidate
                (0x7a,20000,0x3c,DAT_14053ada8,DAT_14053ad2c,0x4000,dVar6,0x2d,1,0);
      stage_entity_spawn_candidate(0x7a,20000,0x3c,DAT_14053b3c4,uVar33,0x4000,dVar6,0x2d,1,0);
      uVar28 = DAT_14053b36c;
      stage_entity_spawn_candidate(0x7c,10000,0x1e,uVar33,DAT_14053b36c,0x4000,dVar6,0x28,1,0);
      uVar34 = 0;
      uVar33 = 1;
      uVar32 = 0x28;
      dVar23 = dVar6;
      stage_entity_spawn_candidate(0x7c,10000,0x1e,DAT_14053b388,uVar28,0x4000,dVar6,0x28,1,0);
      uVar28 = DAT_140e472d8;
      param_1[0x17] = 4;
      FUN_140184700(DAT_140e44190 * 0x19,uVar28);
      FUN_14018a340(DAT_140e472d8,1,1);
      iVar9 = param_1[5];
    }
    uVar30 = param_1[3];
    if (uVar30 < 0x78) {
      dVar21 = (double)FUN_140332d90(((double)(int)uVar30 - 0.0) * DAT_14053a4d8 * dVar3 * dVar2);
      param_1[0xb] = (float)(900 - (int)(dVar21 * DAT_14053a888));
      puVar14 = DAT_140e46c88;
    }
    else {
      param_1[0xb] = (float)(((int)uVar30 >> 0x1f & 800U) + 100);
      puVar14 = DAT_140e46c88;
      if (uVar30 == 0x82) {
        param_1[0x15] = 0;
        param_1[5] = iVar9 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 80000;
        DAT_140e4430c = 0x834;
        DAT_140e4192c = 0;
        param_1[7] = 80000;
        DAT_140e419bc = 1;
        puVar14 = DAT_140e46c88;
      }
    }
  }
  else if (iVar11 == 1) {
    uVar30 = param_1[3];
    dVar21 = (double)FUN_140332d90(((double)(int)uVar30 - _DAT_14053b1f8) * _DAT_14053a3e0 * dVar3 *
                                   dVar2);
    fVar25 = (float)(dVar21 * DAT_14053b120) + DAT_14053ad48;
    param_1[0xb] = fVar25;
    fVar26 = DAT_14053aca4;
    iVar9 = (int)uVar30 % 0x578;
    iVar10 = 0x7f;
    if (iVar9 < 600) {
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 0x12;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0xc;
      }
      else if (DAT_140e419b8 == 2) {
        iVar11 = 10;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar11 = 8;
      }
      iVar17 = iVar9 % 0xa4;
      if (((iVar9 - 10U < 0x37a) && (iVar9 = (int)(iVar9 - 10U) % 0xa4, iVar9 < 0x3c)) &&
         (iVar9 % iVar11 == 0)) {
        uVar19 = (uVar30 >> 0x1e ^ uVar30) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar19;
        dVar23 = (double)FUN_140134db0(uVar30,DAT_14053a0b0,uVar28);
        uVar34 = 0;
        uVar33 = 1;
        uVar32 = 0x14;
        stage_entity_spawn_candidate
                  (0x7e,500,3,fVar27,fVar25 + DAT_14053aca4,
                   CONCAT22(uVar31,(short)((ulonglong)uVar19 / 0x8001) * 0x7fff + (short)uVar19),
                   dVar23,0x14,1,0);
      }
      if (iVar17 < 10) {
        iVar10 = FUN_1400c9580(iVar17,0,5,2,0x80,0x81);
      }
      else if (iVar17 < 0x3c) {
        iVar10 = 0x81;
      }
      else if (iVar17 < 0x46) {
        iVar10 = FUN_1400c9580(iVar17,0x3c,5,2,0x80,0x7f);
      }
    }
    else if (799 < iVar9) {
      fVar27 = (float)param_1[10];
      fVar25 = fVar25 + DAT_14053aca4;
      dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                     (double)(DAT_140e445d8 - fVar27));
      uVar28 = DAT_14053ac2c;
      uVar16 = 1;
      dVar21 = dVar21 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        uVar16 = 7;
      }
      else if (DAT_140e419b8 == 1) {
        uVar16 = 9;
      }
      else if (DAT_140e419b8 == 2) {
        uVar16 = 0xb;
      }
      else if (DAT_140e419b8 == 3) {
        uVar16 = 0xd;
      }
      else if (DAT_140e419b8 == 4) {
        uVar16 = 0xf;
      }
      dVar22 = DAT_14053a030;
      if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a040, DAT_140e419b8 != 1)) &&
          (dVar22 = DAT_14053a070, DAT_140e419b8 != 2)) &&
         ((dVar22 = DAT_14053a088, DAT_140e419b8 != 3 && (dVar22 = dVar6, DAT_140e419b8 == 4)))) {
        dVar22 = DAT_14053a0d0;
      }
      dVar22 = ((double)iVar9 - DAT_14053a888) * _DAT_140539d70 + dVar22;
      iVar11 = (iVar9 + -0x30c) % 0x52;
      if ((iVar9 < 0x550) && (iVar9 + -800 == ((iVar9 + -800) / 0x52) * 0x52)) {
        uVar35 = 0;
        uVar34 = 0x8000;
        uVar32 = 1;
        dVar23 = dVar22;
        uVar33 = uVar16;
        FUN_1400709b0(3,0,fVar27,fVar25,CONCAT22(uVar29,(short)(int)dVar21),DAT_14053ac2c,dVar22,1,
                      uVar16,0x8000,0);
        if (2 < DAT_140e419b8) {
          dVar23 = dVar22 + dVar6;
          uVar35 = 0;
          uVar34 = 0x8000;
          uVar32 = 1;
          FUN_1400709b0(3,0,param_1[10],(float)param_1[0xb] + fVar26,(int)dVar21 & 0xffff,uVar28,
                        dVar23,1,uVar16,0x8000,0);
          uVar33 = uVar16;
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
      iVar10 = 0x7f;
      if (iVar9 < 0x53c) {
        if (iVar11 < 10) {
          iVar10 = FUN_1400c9580(iVar11,0,5,2,0x80,0x81);
        }
        else if (iVar11 < 0x28) {
          iVar10 = 0x81;
        }
        else if (iVar11 < 0x32) {
          iVar10 = FUN_1400c9580(iVar11,0x28,5,2,0x80,0x7f);
        }
      }
    }
    puVar14 = DAT_140e46c88;
    if ((int)param_1[0x17] < 1) {
      param_1[5] = param_1[5] + 1;
      puVar14 = DAT_140e46c88;
    }
  }
  else if (iVar11 == 2) {
    iVar10 = param_1[3];
    dVar21 = (double)FUN_140332d90(((double)iVar10 - _DAT_14053b1f8) * _DAT_14053a3e0 * dVar3 *
                                   dVar2);
    fVar26 = DAT_14053aca4;
    fVar25 = (float)(dVar21 * DAT_14053b120) + DAT_14053ad48;
    param_1[0xb] = fVar25;
    dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar25 + fVar26)),
                                   (double)(DAT_140e445d8 - fVar27));
    iVar9 = 1;
    dVar21 = dVar21 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar9 = 0x12;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0xc;
    }
    else if (DAT_140e419b8 == 2) {
      iVar9 = 10;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar9 = 8;
    }
    uVar16 = 1;
    if (DAT_140e419b8 == 0) {
      uVar16 = 7;
    }
    else if (DAT_140e419b8 == 1) {
      uVar16 = 9;
    }
    else if (DAT_140e419b8 == 2) {
      uVar16 = 0xb;
    }
    else if (DAT_140e419b8 == 3) {
      uVar16 = 0xd;
    }
    else if (DAT_140e419b8 == 4) {
      uVar16 = 0xf;
    }
    dVar22 = DAT_14053a0b8;
    if (((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
       ((dVar22 = DAT_14053a0f8, DAT_140e419b8 != 2 &&
        ((dVar22 = DAT_14053a118, DAT_140e419b8 != 3 && (dVar22 = dVar6, DAT_140e419b8 == 4)))))) {
      dVar22 = DAT_14053a158;
    }
    if (((9 < iVar10) && (iVar10 = (iVar10 + -10) % 0x54, iVar10 < 0x3c)) && (iVar10 % iVar9 == 0))
    {
      uVar30 = param_1[3];
      uVar19 = (uVar30 >> 0x1e ^ uVar30) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      DAT_140e9fd1c = uVar19;
      dVar23 = (double)FUN_140134db0(uVar30,DAT_14053a0b0,uVar28);
      uVar34 = 0;
      fVar25 = fVar25 + fVar26;
      uVar33 = 1;
      uVar32 = 0x14;
      stage_entity_spawn_candidate
                (0x7e,500,0,fVar27,fVar25,
                 CONCAT22(uVar31,(short)((ulonglong)uVar19 / 0x8001) * 0x7fff + (short)uVar19),
                 dVar23,0x14,1,0);
      uVar29 = (undefined2)((uint)fVar25 >> 0x10);
    }
    uVar28 = DAT_14053ac2c;
    iVar10 = param_1[3];
    if ((-1 < iVar10) && (iVar10 == (iVar10 / 0x29) * 0x29)) {
      uVar35 = 0;
      uVar34 = 0x8000;
      uVar32 = 1;
      dVar23 = dVar22;
      uVar33 = uVar16;
      FUN_1400709b0(3,0,param_1[10],(float)param_1[0xb] + fVar26,CONCAT22(uVar29,(short)(int)dVar21)
                    ,DAT_14053ac2c,dVar22,1,uVar16,0x8000,0);
      if (2 < DAT_140e419b8) {
        dVar23 = dVar22 + dVar6;
        uVar35 = 0;
        uVar34 = 0x8000;
        uVar32 = 1;
        FUN_1400709b0(3,0,param_1[10],(float)param_1[0xb] + fVar26,(int)dVar21 & 0xffff,uVar28,
                      dVar23,1,uVar16,0x8000,0);
        uVar33 = uVar16;
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    iVar10 = 0x81;
    puVar14 = DAT_140e46c88;
  }
  else {
    puVar14 = DAT_140e46c88;
    if (iVar11 == 3) {
      iVar10 = param_1[3];
      piVar1 = param_1 + 3;
      if (0x3b < iVar10) {
        iVar9 = 0xff;
      }
      if (0x3b < iVar10) {
        if (iVar10 < 0x46) {
          dVar21 = ((double)iVar10 - DAT_14053a3a0) * DAT_14053a9d8;
        }
        else {
          if (0x77 < iVar10) goto LAB_1400dcfdf;
          dVar21 = ((double)iVar10 - DAT_14053a278) * DAT_14053a670;
        }
        dVar21 = (double)FUN_140332d90(dVar21 * dVar3 * dVar2);
        iVar9 = (int)(dVar21 * dVar4);
      }
LAB_1400dcfdf:
      iVar11 = 0;
      if (iVar10 < 0x78) {
        iVar11 = iVar9;
      }
      iVar8 = FUN_1400c9580(iVar10,0,5,2,0x58,0x59,dVar23,uVar32,uVar33,uVar34,uVar35,uVar36,uVar37,
                            uVar38,uVar39,uVar40,uVar41,uVar42,uVar43,uVar44);
      dVar23 = 6.37344683135208e-322;
      iVar10 = FUN_1400c9580(*piVar1,0,3,3,0x7f,0x80,0x81);
      iVar9 = *piVar1;
      if (iVar9 < 0x3c) {
        FUN_14007ac00(param_1);
        iVar9 = *piVar1;
        param_1[0xb] = (float)iVar9 * DAT_140539ce4 + (float)param_1[0xb];
      }
      puVar13 = DAT_140e45d28;
      if (iVar9 == 0x3c) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar28 = param_1[0xb];
        uVar16 = param_1[10];
        puVar13 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar13 = (undefined8 *)_malloc_base(0x60);
          if (puVar13 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar13 + 0x14) = uVar16;
          *(undefined4 *)(puVar13 + 3) = uVar28;
          *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar16;
          *(undefined4 *)(puVar13 + 4) = uVar28;
          *puVar13 = 1;
          puVar13[1] = 0x11;
          *(undefined4 *)(puVar13 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
          puVar13[5] = 0;
          puVar13[6] = 0x3ff0000000000000;
          puVar13[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar13 + 8) = 0;
          *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
          *(undefined4 *)(puVar13 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
          puVar13[10] = 0xff;
          puVar13[0xb] = 0;
          if (bVar20) {
            DAT_140e45d78 = puVar13;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar13;
          }
        }
      }
      DAT_140e45d28 = puVar13;
      if (param_1[3] == 0x78) {
        DAT_140e418cc = 0;
        *param_1 = 0;
      }
      uVar28 = DAT_140e41ab8;
      puVar14 = (undefined4 *)_malloc_base(0x48);
      if (puVar14 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
      bVar20 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar14 = uVar28;
      puVar14[1] = 0x4e;
      *(undefined8 *)(puVar14 + 2) = 5;
      puVar14[4] = 0;
      *(undefined2 *)(puVar14 + 5) = 0;
      *(undefined8 *)(puVar14 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar14 + 8) = 0x3ff0000000000000;
      puVar14[10] = 0xff;
      puVar14[0xb] = 0xff;
      puVar14[0xc] = 0xff;
      puVar14[0xd] = iVar11;
      *(undefined8 *)(puVar14 + 0xe) = 1;
      *(undefined8 *)(puVar14 + 0x10) = 0;
      if (bVar20) {
        DAT_140e46bf0 = puVar14;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar14;
      }
    }
  }
  DAT_140e46c88 = puVar14;
  iVar9 = 0xff;
  if ((param_1[5] == 3) && (0x45 < (int)param_1[3])) goto LAB_1400de86f;
  uVar30 = 0;
  iVar11 = FUN_1400c9580(DAT_140e418c8,0,3,2,0x62,99,dVar23,uVar32,uVar33,uVar34,uVar35,uVar36,
                         uVar37,uVar38,uVar39,uVar40,uVar41,uVar42,uVar43,uVar44);
  fVar5 = DAT_14053ae14;
  fVar25 = DAT_14053ad80;
  pfVar18 = (float *)(param_1 + 0xb);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar11],0x19,7,(float)param_1[10] + DAT_14053ad80,
                (float)param_1[0xb] + DAT_14053ae14,uVar30,dVar6,uVar7,0xff,0xff,0xff,0xff,1,0);
  fVar26 = DAT_14053ad10;
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar11],0x19,7,(float)param_1[10] + DAT_14053ad10,*pfVar18 + fVar5,
                uVar30,dVar6,uVar7,0xff,0xff,0xff,0xff,1,0);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar11],0x19,7,(float)param_1[10] - fVar25,*pfVar18 + fVar5,uVar30,
                dVar6,uVar7,0xff,0xff,0xff,0xff,1,0);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar11],0x19,7,(float)param_1[10] - fVar26,*pfVar18 + fVar5,uVar30,
                dVar6,uVar7,0xff,0xff,0xff,0xff,1,0);
  uVar33 = DAT_140e41960;
  fVar27 = *pfVar18;
  fVar24 = ((float)param_1[10] + fVar25) - DAT_140e45d24;
  iVar11 = DAT_140e45d1c;
  puVar13 = DAT_140e45d28;
  if (DAT_140e45d1c < 0x1000) {
    puVar13 = (undefined8 *)_malloc_base(0x60);
    if (puVar13 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar11 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar13 + 0x14) = fVar24;
    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar13 + 3) = fVar27 + fVar5;
    *(float *)((longlong)puVar13 + 0x1c) = fVar24;
    *(float *)(puVar13 + 4) = fVar27 + fVar5;
    *puVar13 = 1;
    *(undefined4 *)(puVar13 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar13 + 0xc) = uVar33;
    *(undefined4 *)(puVar13 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
    puVar13[5] = 0;
    puVar13[6] = 0x3ffe666666666666;
    puVar13[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar13 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
    *(undefined4 *)(puVar13 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
    puVar13[10] = 0x40;
    puVar13[0xb] = 0;
    if (bVar20) {
      DAT_140e45d78 = puVar13;
    }
    DAT_140e45d1c = iVar11;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar13;
    }
  }
  DAT_140e45d28 = puVar13;
  uVar33 = DAT_140e41960;
  fVar27 = (float)param_1[0xb];
  fVar24 = ((float)param_1[10] + fVar26) - DAT_140e45d24;
  puVar13 = DAT_140e45d28;
  if (iVar11 < 0x1000) {
    puVar13 = (undefined8 *)_malloc_base(0x60);
    if (puVar13 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar11 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar13 + 0x14) = fVar24;
    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar13 + 3) = fVar27 + fVar5;
    *(float *)((longlong)puVar13 + 0x1c) = fVar24;
    *(float *)(puVar13 + 4) = fVar27 + fVar5;
    *puVar13 = 1;
    *(undefined4 *)(puVar13 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar13 + 0xc) = uVar33;
    *(undefined4 *)(puVar13 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
    puVar13[5] = 0;
    puVar13[6] = 0x3ffe666666666666;
    puVar13[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar13 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
    *(undefined4 *)(puVar13 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
    puVar13[10] = 0x40;
    puVar13[0xb] = 0;
    if (bVar20) {
      DAT_140e45d78 = puVar13;
    }
    DAT_140e45d1c = iVar11;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar13;
    }
  }
  DAT_140e45d28 = puVar13;
  uVar33 = DAT_140e41960;
  fVar27 = (float)param_1[0xb];
  fVar25 = ((float)param_1[10] - fVar25) - DAT_140e45d24;
  puVar13 = DAT_140e45d28;
  if (iVar11 < 0x1000) {
    puVar13 = (undefined8 *)_malloc_base(0x60);
    if (puVar13 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(float *)((longlong)puVar13 + 0x14) = fVar25;
    puVar13[6] = 0x3ffe666666666666;
    puVar13[7] = 0x3ffe666666666666;
    iVar11 = DAT_140e45d1c + 1;
    *(float *)(puVar13 + 3) = fVar27 + fVar5;
    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar13 + 0x1c) = fVar25;
    *(float *)(puVar13 + 4) = fVar27 + fVar5;
    *puVar13 = 1;
    *(undefined4 *)(puVar13 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar13 + 0xc) = uVar33;
    *(undefined4 *)(puVar13 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
    puVar13[5] = 0;
    *(undefined4 *)(puVar13 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
    *(undefined4 *)(puVar13 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
    puVar13[10] = 0x40;
    puVar13[0xb] = 0;
    if (bVar20) {
      DAT_140e45d78 = puVar13;
    }
    DAT_140e45d1c = iVar11;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar13;
    }
  }
  DAT_140e45d28 = puVar13;
  uVar33 = DAT_140e41960;
  fVar27 = (float)param_1[0xb];
  fVar26 = ((float)param_1[10] - fVar26) - DAT_140e45d24;
  puVar13 = DAT_140e45d28;
  if (iVar11 < 0x1000) {
    puVar13 = (undefined8 *)_malloc_base(0x60);
    if (puVar13 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar20 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)((longlong)puVar13 + 0x14) = fVar26;
    *(float *)(puVar13 + 3) = fVar27 + fVar5;
    *(float *)((longlong)puVar13 + 0x1c) = fVar26;
    *(float *)(puVar13 + 4) = fVar27 + fVar5;
    *puVar13 = 1;
    *(undefined4 *)(puVar13 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar13 + 0xc) = uVar33;
    *(undefined4 *)(puVar13 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar13 + 0x24) = 0;
    puVar13[5] = 0;
    puVar13[6] = 0x3ffe666666666666;
    puVar13[7] = 0x3ffe666666666666;
    *(undefined4 *)(puVar13 + 8) = 0x1e;
    *(undefined4 *)((longlong)puVar13 + 0x44) = 0xff;
    *(undefined4 *)(puVar13 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar13 + 0x4c) = 0xff;
    puVar13[10] = 0x40;
    puVar13[0xb] = 0;
    if (bVar20) {
      DAT_140e45d78 = puVar13;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar13;
    }
  }
  DAT_140e45d28 = puVar13;
  fVar27 = DAT_14053ad5c;
  pfVar18 = (float *)(param_1 + 0xb);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(DAT_140e449c4,0x19,7,param_1[10],*pfVar18 + DAT_14053ad5c,uVar30,dVar6,uVar7,0xff,
                0xff,0xff,0xff,1,0);
  uVar19 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
  DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  uVar19 = uVar19 * 0x800 ^ uVar19;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
  if (DAT_140e9fd1c % 5 != 0) {
    uVar30 = uVar30 & 0xffff0000;
    FUN_1400c8410(DAT_140e449c8,0x19,7,param_1[10],*pfVar18 + fVar27,uVar30,dVar6,uVar7,0xff,0xff,
                  0xff,0xff,1,0);
  }
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(DAT_140e449b8,0x19,7,param_1[10],*pfVar18 + fVar27,uVar30,dVar6,uVar7,0xff,0xff,0xff
                ,0xff,1,0);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(DAT_140e449d0,0x17,7,param_1[10],*pfVar18 + DAT_14053ad84,uVar30,dVar6,uVar7,0,0,
                0x20,0x40,1,0);
  dVar21 = DAT_14053a890;
  dVar23 = DAT_14053a1e8;
  iVar11 = 0xff;
  if (param_1[5] == 3) {
    iVar17 = param_1[3];
    iVar11 = 0xff;
    if (iVar17 - 0x1eU < 0x14) {
      dVar22 = (double)FUN_140332d90(((double)iVar17 - DAT_14053a1e8) * DAT_14053a890 * dVar3 *
                                     dVar2);
      iVar11 = (int)(dVar22 * dVar4);
    }
    iVar9 = 0;
    if (iVar17 < 0x32) {
      iVar9 = iVar11;
    }
    iVar12 = (iVar17 >> 0x1f & 0xffffff01U) + 0xff;
    if (-1 < iVar17) {
      if (iVar17 < 0x1e) {
        dVar21 = ((double)iVar17 - 0.0) * DAT_14053a798;
      }
      else {
        if (0x31 < iVar17) goto LAB_1400de57f;
        dVar21 = ((double)iVar17 - dVar23) * dVar21;
      }
      dVar23 = (double)FUN_140332d90(dVar21 * dVar3 * dVar2);
      iVar12 = (int)(dVar23 * dVar4);
    }
LAB_1400de57f:
    iVar11 = 0;
    if (iVar17 < 0x32) {
      iVar11 = iVar12;
    }
  }
  fVar26 = DAT_14053ad40;
  pfVar18 = (float *)(param_1 + 0xb);
  lVar15 = (longlong)iVar8;
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar15 * 4),0x19,0x18,param_1[10],
                *pfVar18 + DAT_14053ad40,uVar30,dVar6,uVar7,0x40,0x40,0,
                iVar9 / 6 + (iVar9 >> 0x1f) +
                (int)(((longlong)iVar9 / 6 + ((longlong)iVar9 >> 0x3f) & 0xffffffffU) >> 0x1f),1,0);
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar15 * 4),0x19,7,param_1[10],*pfVar18 + fVar26,
                uVar30,dVar6,uVar7,0xff,0xff,0xff,iVar9,1,0);
  if (param_1[5] == 3) {
    uVar30 = uVar30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + lVar15 * 4),0x19,8,param_1[10],*pfVar18 + fVar26,
                  uVar30,dVar6,uVar7,0xff,0xff,0xff,iVar11,1,0);
  }
  dVar23 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a880 * dVar3 * dVar2
                                );
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410(DAT_140e44cc8,0x1a,7,param_1[10],*pfVar18,uVar30,dVar23 * _DAT_140539e28 + dVar6,
                dVar6,0xff,0xff,0xff,0xff,1,0);
  dVar23 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * _DAT_14053a880 * dVar3 * dVar2
                                );
  uVar30 = uVar30 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44ad0)[iVar10],0x1a,7,param_1[10],*pfVar18,uVar30,
                dVar23 * _DAT_140539e28 + dVar6,dVar6,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e449c0,0x1d,7,param_1[10],*pfVar18 + fVar27,uVar30 & 0xffff0000,dVar6,uVar7,
                0xff,0xff,0xff,0xff,1,0);
LAB_1400de86f:
  if ((param_1[0x15] == 0) && ((int)param_1[3] % 0x12 == 1)) {
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472f4);
    FUN_14018a340(DAT_140e472f4,1,1);
  }
  FUN_140002260();
  return;
}


