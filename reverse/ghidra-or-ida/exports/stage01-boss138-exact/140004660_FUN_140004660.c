// Function: FUN_140004660 @ 140004660
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140004660(undefined4 *param_1)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  int *piVar14;
  undefined4 uVar15;
  int *piVar16;
  undefined8 uVar17;
  short sVar18;
  uint uVar19;
  undefined4 uVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  undefined8 uVar26;
  double dVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  float fVar32;
  int local_res10;
  undefined8 in_stack_fffffffffffffec8;
  ulonglong in_stack_fffffffffffffed0;
  ulonglong uVar33;
  undefined8 in_stack_fffffffffffffed8;
  undefined8 in_stack_fffffffffffffee0;
  undefined4 uVar35;
  undefined8 uVar34;
  undefined4 uVar36;
  undefined8 local_e8;
  undefined1 local_d8 [160];
  
  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
  uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  dVar22 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar27 = DAT_14053aba0;
  dVar25 = DAT_14053a4f0;
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  iVar9 = 0;
  iVar10 = 0;
  iVar4 = 0;
  local_res10 = 0;
  uVar19 = (uint)(dVar22 * DAT_14053aba0);
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    uVar34 = CONCAT44(uVar35,param_1[0x14]);
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffffffff0000;
    in_stack_fffffffffffffec8 = CONCAT44(uVar31,param_1[0xb]);
    dVar22 = dVar25;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
               dVar25,uVar34,1,0);
    uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
    uVar35 = (undefined4)((ulonglong)uVar34 >> 0x20);
    if (DAT_140e41af8 == 1) {
      param_1[5] = 6;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      param_1[5] = 4;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 3) {
      param_1[5] = 2;
      DAT_140e419bc = 2;
      param_1[0x14] = 0xf0;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar34 = _UNK_14053bb28;
  dVar23 = _DAT_14053bb20;
  dVar24 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar12 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar7 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 4;
    uVar8 = DAT_1407c7798 * 0x6f + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar7 >> 0xb ^ uVar12) >> 8 ^ uVar7 ^ uVar12) % 0x12d + 0xd2);
    uVar12 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  uVar3 = (ushort)uVar19;
  switch(param_1[5]) {
  case 0:
    uVar19 = param_1[3];
    iVar9 = iVar4;
    if (uVar19 < 0xb4) {
      dVar25 = (double)FUN_140332d90(((double)(int)uVar19 - 0.0) * DAT_14053a438 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar25 = dVar25 * _DAT_14053b260;
      puVar6 = (undefined8 *)FUN_140135060(local_d8,uVar19,0x14);
      fVar28 = (float)(-600 - (int)dVar25);
      uVar36 = *(undefined4 *)(puVar6 + 1);
      local_e8 = *puVar6;
LAB_140004a23:
      if ((int)uVar19 < 0xf0) {
        iVar10 = iVar9;
      }
      iVar4 = iVar10;
      if (uVar19 == 0) {
        in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
        uVar17 = CONCAT44(uVar31,DAT_14053adbc);
        stage_entity_spawn_candidate
                  (0x12,99999999,0,0,uVar17,in_stack_fffffffffffffed0,dVar23,CONCAT44(uVar35,100),1,
                   param_1[1]);
        uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
        FUN_14018a340(DAT_140e472d8,1,1);
      }
    }
    else {
      fVar28 = (float)(int)((int)uVar19 >> 0x1f & 0xfffffda8);
      puVar6 = (undefined8 *)FUN_140135060(local_d8,uVar19,0x14);
      local_e8 = *puVar6;
      uVar36 = *(undefined4 *)(puVar6 + 1);
      if ((int)uVar19 < 0xb4) goto LAB_140004a23;
      iVar9 = 0xff;
      if ((int)uVar19 < 0xbe) {
        dVar25 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a548) * DAT_14053a9d8 *
                                       dVar24 * dVar22);
        iVar4 = (int)(dVar25 * DAT_14053a5f8);
      }
      else {
        if (0xef < uVar19) goto LAB_140004a23;
        dVar25 = (double)FUN_140332d90(((double)(int)uVar19 - dVar25) * DAT_14053a670 * dVar24 *
                                       dVar22);
        if ((int)uVar19 < 0xf0) {
          iVar4 = (int)(dVar25 * DAT_14053a5f8);
        }
      }
    }
    if (param_1[3] == 0xb4) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar10 = param_1[3];
    if (iVar10 < 0xbf) {
      dVar25 = (double)FUN_140332d90(((double)iVar10 - _DAT_14053b158) * DAT_14053a628 * dVar24 *
                                     dVar22);
      iVar9 = (int)(float)param_1[0xd];
      fVar28 = (float)(dVar25 * (double)fVar28) + (float)param_1[0xc];
      param_1[10] = fVar28;
      if (iVar10 < 0) {
        iVar9 = 600;
      }
      else if (iVar10 < 0xb4) {
        dVar25 = (double)FUN_140332d90();
        iVar9 = (int)(dVar25 * (double)(iVar9 + -600)) + 600;
      }
      uVar17 = 8;
      fVar29 = (float)iVar9;
    }
    else {
      uVar17 = 7;
      fVar29 = (float)param_1[0xb] + DAT_140539ce4;
      fVar28 = (float)param_1[10];
      uVar36 = 0xff;
      local_e8._4_4_ = 0xff;
      local_e8._0_4_ = 0xff;
    }
    param_1[0xb] = fVar29;
    FUN_1400c8410(DAT_140e44910,0x1e,uVar17,fVar28,CONCAT44(uVar31,fVar29),
                  in_stack_fffffffffffffed0 & 0xffffffffffff0000,dVar23,uVar34,(undefined4)local_e8,
                  local_e8._4_4_,uVar36,0xff,1,0);
    uVar31 = DAT_140e41ab8;
    puVar5 = (undefined4 *)_malloc_base(0x48);
    if (puVar5 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46df0 = _DAT_140e46df0 + 1;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar5 = uVar31;
    *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
    puVar5[1] = 0x58;
    *(undefined8 *)(puVar5 + 2) = 5;
    puVar5[4] = 0;
    *(undefined2 *)(puVar5 + 5) = 0;
    puVar5[10] = 0xff;
    puVar5[0xb] = 0xff;
    puVar5[0xc] = 0xff;
    puVar5[0xd] = iVar4;
    *(undefined8 *)(puVar5 + 0xe) = 1;
    *(undefined8 *)(puVar5 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar5;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
    }
    DAT_140e46c88 = puVar5;
    if (param_1[3] == 0xf0) {
      param_1[5] = param_1[5] + 1;
      DAT_140e41b0c = 60000;
      param_1[7] = 60000;
      param_1[0x15] = 0;
      param_1[3] = 0;
      DAT_140e4430c = 0x708;
      DAT_140e4192c = 0;
      DAT_140e419bc = 1;
    }
    break;
  case 1:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar10 = (uVar19 & 0xffff) - (uint)uVar1;
    iVar4 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar4 = iVar10;
    }
    iVar10 = iVar4 + -0x10000;
    if (iVar4 < 0x8001) {
      iVar10 = iVar4;
    }
    if (iVar10 < 1) {
      uVar11 = uVar1;
      if ((iVar10 < 0) && (uVar11 = uVar1 - 0x200, -0x200 < iVar10)) {
        uVar11 = uVar3;
      }
    }
    else {
      uVar11 = uVar3;
      if (0x1ff < iVar10) {
        uVar11 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
    dVar25 = (double)FUN_1403307c0();
    fVar30 = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar30;
    dVar25 = (double)FUN_140332d90();
    uVar34 = _UNK_14053bb28;
    dVar22 = _DAT_14053bb20;
    fVar29 = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar29;
    iVar4 = DAT_140e419b8;
    fVar28 = DAT_14053ace8;
    dVar25 = DAT_14053a118;
    if (0x27 < (int)param_1[3]) {
      iVar10 = 1;
      uVar19 = (param_1[3] + -0x28) % 0x2d0;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar10 = 7;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar10 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 4;
      }
      uVar31 = SUB84(DAT_14053a1b8,0);
      uVar36 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
      dVar24 = DAT_14053a070;
      if ((((DAT_140e419b8 != 0) && (dVar24 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
          (dVar24 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((dVar24 = DAT_14053a158, DAT_140e419b8 != 3 && (dVar24 = dVar22, DAT_140e419b8 == 4)))) {
        dVar24 = DAT_14053a1b8;
      }
      if ((-1 < (int)uVar19) && (uVar19 == ((int)uVar19 / 0x3c) * 0x3c)) {
        dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar29 + DAT_14053ace8)),
                                       (double)(DAT_140e445d8 - fVar30));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar23 * dVar27);
      }
      uVar15 = DAT_14053ac2c;
      if ((uVar19 < 0x3c) && ((int)uVar19 % 0x3c < 0x1e)) {
        uVar12 = (int)uVar19 % 0x3c & 0x80000003;
        if ((int)uVar12 < 0) {
          uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
        }
        if (uVar12 != 0) goto LAB_140004fe6;
LAB_140005068:
        uVar17 = CONCAT44(uVar35,1);
        in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),DAT_14053ac2c)
        ;
        FUN_14006c2f0(0xb,0,fVar30,fVar29 + fVar28,*(undefined2 *)((longlong)param_1 + 0x42),
                      in_stack_fffffffffffffed0,dVar24,uVar17,0);
        uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        if (2 < DAT_140e419b8) {
          fVar29 = (float)param_1[0xb];
          sVar18 = *(short *)((longlong)param_1 + 0x42);
          uVar31 = param_1[10];
          do {
            uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),1);
            in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),uVar15);
            FUN_14006c2f0(0xb,0,uVar31,fVar29 + fVar28,(short)iVar9 * 3000 + sVar18 + -0x5dc,
                          in_stack_fffffffffffffed0,dVar24 - dVar22,uVar17,0);
            uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
            iVar9 = iVar9 + 1;
          } while (iVar9 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar31 = SUB84(DAT_14053a1b8,0);
        uVar36 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
        iVar4 = DAT_140e419b8;
      }
      else {
LAB_140004fe6:
        if ((uVar19 - 0xf0 < 0x78) && (uVar12 = (int)(uVar19 - 0xf0) % 0x3c, (int)uVar12 < 0x1e)) {
          uVar12 = uVar12 & 0x80000003;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
          }
          if (uVar12 == 0) goto LAB_140005068;
        }
        if ((uVar19 - 600 < 0x78) && (uVar12 = (int)(uVar19 - 600) % 0x3c, (int)uVar12 < 0x1e)) {
          uVar12 = uVar12 & 0x80000003;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
          }
          if (uVar12 == 0) goto LAB_140005068;
        }
      }
      if ((((((uVar19 - 10 < 0x32) && (iVar9 = (int)(uVar19 - 10) % 0x3c, iVar9 < 0x1e)) &&
            (iVar9 % iVar10 == 0)) ||
           (((uVar19 - 0xfa < 0x6e && (iVar9 = (int)(uVar19 - 0xfa) % 0x3c, iVar9 < 0x1e)) &&
            (iVar9 % iVar10 == 0)))) ||
          (((uVar19 - 0x262 < 0x6e && (iVar9 = (int)(uVar19 - 0x262) % 0x3c, iVar9 < 0x1e)) &&
           (iVar9 % iVar10 == 0)))) && (0 < iVar4)) {
        iVar10 = ((int)(uVar19 - 10) % 0x3c) * 800;
        uVar17 = CONCAT44(uVar35,1);
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        FUN_1400709b0(1,0,param_1[10],(float)param_1[0xb] + fVar28,
                      *(undefined2 *)((longlong)param_1 + 0x42),in_stack_fffffffffffffed0,
                      dVar24 - DAT_140539ef8,uVar17,2,iVar10 + 0x4b0,0);
        uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        iVar4 = DAT_140e419b8;
        if (2 < DAT_140e419b8) {
          uVar17 = CONCAT44(uVar35,1);
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          FUN_1400709b0(1,0,param_1[10],(float)param_1[0xb] + fVar28,
                        *(undefined2 *)((longlong)param_1 + 0x42),in_stack_fffffffffffffed0,
                        dVar24 - DAT_140539fa8,uVar17,2,iVar10 + 2000,0);
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          iVar4 = DAT_140e419b8;
        }
      }
      fVar29 = DAT_14053ad14;
      fVar28 = DAT_14053aa20;
      iVar10 = 1;
      if (iVar4 == 0) {
        iVar10 = 0x14;
      }
      else if (iVar4 == 1) {
        iVar10 = 0xe;
      }
      else if (((iVar4 == 2) || (iVar4 == 3)) || (iVar4 == 4)) {
        iVar10 = 10;
      }
      uVar15 = 1;
      if (iVar4 == 0) {
        uVar15 = 3;
      }
      else if (iVar4 == 1) {
        uVar15 = 5;
      }
      else if ((iVar4 == 2) || (iVar4 == 3)) {
        uVar15 = 7;
      }
      else if (iVar4 == 4) {
        uVar15 = 8;
      }
      dVar27 = DAT_14053a040;
      if (((iVar4 != 0) && (dVar27 = DAT_14053a088, iVar4 != 1)) &&
         ((dVar27 = dVar25, iVar4 != 2 &&
          ((dVar27 = DAT_14053a138, iVar4 != 3 && (dVar27 = dVar22, iVar4 == 4)))))) {
        dVar27 = (double)CONCAT44(uVar36,uVar31);
      }
      fVar30 = (float)param_1[0xb];
      fVar32 = (float)param_1[10];
      if (uVar19 == 0x3c) {
        dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar30 - DAT_14053aa20)),
                                       (double)(DAT_140e445d8 - (fVar32 + DAT_14053ad14)));
        *(short *)(param_1 + 0x11) = (short)(int)(dVar25 * DAT_14053aba0);
LAB_140005440:
        dVar25 = DAT_140539fc8;
        if ((int)(uVar19 - 0x3c) % iVar10 == 0) {
          uVar12 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar12 = uVar12 * 0x800 ^ uVar12;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
          uVar17 = CONCAT44(uVar35,1);
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          FUN_1400709b0(4,0,fVar32 + fVar29,fVar30 - fVar28,
                        (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x1771) * -0x1771 +
                        *(short *)(param_1 + 0x11) + -3000,in_stack_fffffffffffffed0,dVar27,uVar17,
                        uVar15,12000,0);
          dVar25 = DAT_140539fc8;
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          if (2 < DAT_140e419b8) {
            uVar12 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar12 = uVar12 * 0x800 ^ uVar12;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
            uVar17 = CONCAT44(uVar35,1);
            in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
            FUN_1400709b0(0,0,(float)param_1[10] + fVar29,(float)param_1[0xb] - fVar28,
                          (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x1771) * -0x1771 +
                          *(short *)(param_1 + 0x11) + -3000,in_stack_fffffffffffffed0,
                          dVar27 - DAT_140539fc8,uVar17,uVar15,12000,0);
            uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          fVar30 = (float)param_1[0xb];
          fVar32 = (float)param_1[10];
          iVar4 = DAT_140e419b8;
        }
      }
      else {
        dVar25 = DAT_140539fc8;
        if ((0x3b < (int)uVar19) && ((int)uVar19 < 100)) goto LAB_140005440;
      }
      if (uVar19 == 0x7d) {
        dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar30 - fVar28)),
                                       (double)(DAT_140e445d8 - (fVar32 - fVar29)));
        *(short *)(param_1 + 0x11) = (short)(int)(dVar24 * DAT_14053aba0);
LAB_1400056f8:
        if ((int)(uVar19 - 0x7d) % iVar10 == 0) {
          uVar17 = CONCAT44(uVar35,1);
          uVar12 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar12 = uVar12 * 0x800 ^ uVar12;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
          FUN_1400709b0(4,0,fVar32 - fVar29,fVar30 - fVar28,
                        (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0x1771) * -0x1771
                        + *(short *)(param_1 + 0x11) + -3000,in_stack_fffffffffffffed0,dVar27,uVar17
                        ,uVar15,12000,0);
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          if (2 < DAT_140e419b8) {
            uVar17 = CONCAT44(uVar35,1);
            uVar7 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
            in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
            uVar12 = uVar7 * 0x800 ^ uVar7;
            DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
            FUN_1400709b0(0,0,(float)param_1[10] - fVar29,(float)param_1[0xb] - fVar28,
                          (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x1771) * -0x1771 +
                          *(short *)(param_1 + 0x11) + -3000,in_stack_fffffffffffffed0,
                          dVar27 - dVar25,uVar17,uVar15,12000,0);
            uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar4 = DAT_140e419b8;
        }
      }
      else if (uVar19 - 0x7d < 0x28) goto LAB_1400056f8;
      dVar27 = DAT_140539f68;
      dVar25 = DAT_140539dc8;
      iVar10 = 1;
      if (iVar4 == 0) {
        iVar10 = 6;
      }
      else if (iVar4 == 1) {
        iVar10 = 4;
      }
      else if ((iVar4 == 2) || (iVar4 == 3)) {
        iVar10 = 3;
      }
      else if (iVar4 == 4) {
        iVar10 = 2;
      }
      iVar9 = 1;
      if (iVar4 == 0) {
        iVar9 = 3;
      }
      else if (iVar4 == 1) {
        iVar9 = 5;
      }
      else if (iVar4 == 2) {
        iVar9 = 7;
      }
      else if (iVar4 == 3) {
        iVar9 = 9;
      }
      else if (iVar4 == 4) {
        iVar9 = 0xb;
      }
      sVar18 = 1;
      if (iVar4 == 0) {
        sVar18 = 1000;
      }
      else if (iVar4 == 1) {
        sVar18 = 0x578;
      }
      else if ((iVar4 == 2) || (iVar4 == 3)) {
        sVar18 = 0x80c;
      }
      else if (iVar4 == 4) {
        sVar18 = 0xb54;
      }
      dVar24 = DAT_14053a040;
      if ((((iVar4 != 0) && (dVar24 = DAT_14053a0d0, iVar4 != 1)) &&
          (dVar24 = DAT_14053a0f8, iVar4 != 2)) && ((iVar4 != 3 && (dVar24 = dVar22, iVar4 == 4))))
      {
        dVar24 = DAT_14053a158;
      }
      if ((uVar19 - 0x168 < 0x50) &&
         (uVar33 = (longlong)(int)(uVar19 - 0x168) % (longlong)iVar10, (int)uVar33 == 0)) {
        sVar13 = sVar18 * (short)uVar19 + 0x6000;
        iVar4 = iVar9 * 400 + -400;
        uVar17 = CONCAT44(uVar35,1);
        dVar23 = ((double)(int)uVar19 - _DAT_14053a690) * DAT_140539dc8 + dVar24;
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        FUN_1400709b0(4,uVar33 & 0xffffffff,(float)param_1[10] + fVar29,(float)param_1[0xb] - fVar28
                      ,sVar13,in_stack_fffffffffffffed0,dVar23,uVar17,iVar9,iVar4,0);
        uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        if (2 < DAT_140e419b8) {
          uVar17 = CONCAT44(uVar35,1);
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          FUN_1400709b0(4,0,(float)param_1[10] + fVar29,(float)param_1[0xb] - fVar28,sVar13,
                        in_stack_fffffffffffffed0,dVar23 + dVar27,uVar17,iVar9,iVar4,0);
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      if ((uVar19 - 0x1d6 < 0x5a) &&
         (uVar33 = (longlong)(int)(uVar19 - 0x1d6) % (longlong)iVar10, (int)uVar33 == 0)) {
        sVar18 = -0x6000 - sVar18 * (short)uVar19;
        iVar4 = iVar9 * 400 + -400;
        dVar24 = ((double)(int)uVar19 - _DAT_14053a728) * dVar25 + dVar24;
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        FUN_1400709b0(4,uVar33 & 0xffffffff,(float)param_1[10] - fVar29,(float)param_1[0xb] - fVar28
                      ,sVar18,in_stack_fffffffffffffed0,dVar24,CONCAT44(uVar35,1),iVar9,iVar4,0);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          FUN_1400709b0(4,0,(float)param_1[10] - fVar29,(float)param_1[0xb] - fVar28,sVar18,
                        in_stack_fffffffffffffed0,dVar24 + dVar27,1,iVar9,iVar4,0);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    FUN_1400c8410(DAT_140e44910,0x1e,7,param_1[10],param_1[0xb],
                  in_stack_fffffffffffffed0 & 0xffffffffffff0000,dVar22,uVar34,0xff,0xff,0xff,0xff,1
                  ,0);
    break;
  case 2:
    iVar4 = param_1[3];
    iVar9 = iVar10;
    if (iVar4 < 0x78) {
LAB_140005d90:
      iVar10 = 0;
      if (iVar4 < 0xdc) {
        iVar10 = iVar9;
      }
      puVar6 = DAT_140e45d28;
      if (iVar4 == 1) {
        uVar31 = param_1[0xb];
        uVar35 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar35;
          *(undefined4 *)(puVar6 + 3) = uVar31;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar35;
          *(undefined4 *)(puVar6 + 4) = uVar31;
          *puVar6 = 1;
          puVar6[1] = 0x36;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar21) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
    }
    else {
      iVar9 = 0xff;
      if (iVar4 < 0x82) {
        dVar25 = (double)FUN_140332d90(((double)iVar4 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar10 = (int)(dVar25 * DAT_14053a5f8);
        puVar6 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar4) goto LAB_140005d90;
        dVar25 = (double)FUN_140332d90(((double)iVar4 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar6 = DAT_140e45d28;
        if (iVar4 < 0xdc) {
          iVar10 = (int)(dVar25 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar6;
    iVar4 = param_1[3];
    if (iVar4 < 0x78) {
      FUN_14007ac00(param_1);
      iVar4 = param_1[3];
      param_1[0xb] = (float)iVar4 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar6 = DAT_140e45d28;
    if (iVar4 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar31 = param_1[0xb];
      uVar35 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar35;
        *(undefined4 *)(puVar6 + 3) = uVar31;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar35;
        *(undefined4 *)(puVar6 + 4) = uVar31;
        *puVar6 = 1;
        puVar6[1] = 0x11;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    if (0xdb < (int)param_1[3]) {
      FUN_140001900(param_1[3],0xdc,0);
    }
    uVar31 = DAT_140e41ab8;
    puVar5 = (undefined4 *)_malloc_base(0x48);
    if (puVar5 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    *puVar5 = uVar31;
    bVar21 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar5[1] = 0x4e;
    *(undefined8 *)(puVar5 + 2) = 5;
    puVar5[4] = 0;
    *(undefined2 *)(puVar5 + 5) = 0;
    *(undefined8 *)(puVar5 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar5 + 8) = 0x3ff0000000000000;
    puVar5[10] = 0xff;
    puVar5[0xb] = 0xff;
    puVar5[0xc] = 0xff;
    puVar5[0xd] = iVar10;
    *(undefined8 *)(puVar5 + 0xe) = 1;
    *(undefined8 *)(puVar5 + 0x10) = 0;
    if (bVar21) {
      DAT_140e46bf0 = puVar5;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar5;
    }
    iVar4 = param_1[3];
    DAT_140e46c88 = puVar5;
    if (iVar4 < 0x82) {
      FUN_1400c8410(DAT_140e44910,0x1e,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffed0 & 0xffffffffffff0000,_DAT_14053bb20,_UNK_14053bb28,
                    0xff,0xff,0xff,0xff,1,0);
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar9 = (uVar19 & 0xffff) - (uint)uVar1;
      iVar10 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar10 = iVar9;
      }
      iVar9 = iVar10 + -0x10000;
      if (iVar10 < 0x8001) {
        iVar9 = iVar10;
      }
      if (iVar9 < 1) {
        uVar11 = uVar1;
        if ((iVar9 < 0) && (uVar11 = uVar1 - 0x200, -0x200 < iVar9)) {
          uVar11 = uVar3;
        }
      }
      else {
        uVar11 = uVar3;
        if (0x1ff < iVar9) {
          uVar11 = uVar1 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar11;
      dVar25 = (double)FUN_1403307c0();
      uVar31 = (undefined4)(in_stack_fffffffffffffed0 >> 0x20);
      param_1[10] = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar25 = (double)FUN_140332d90();
      uVar33 = CONCAT44(uVar31,1);
      uVar31 = 0;
      param_1[0xb] = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar4 = FUN_1400c9580(iVar4,0,7,3,0,uVar33,CONCAT44(uVar36,2));
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4),0x1e,7,param_1[10],
                    CONCAT44(uVar31,param_1[0xb]),uVar33 & 0xffffffffffff0000,_DAT_14053bb20,
                    _UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[3] == 0x17c) {
      *(undefined8 *)(param_1 + 0x14) = 0x50;
      param_1[3] = 0;
      if (param_1[5] == 2) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 55000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 3:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar10 = (uVar19 & 0xffff) - (uint)uVar1;
    iVar4 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar4 = iVar10;
    }
    iVar10 = iVar4 + -0x10000;
    if (iVar4 < 0x8001) {
      iVar10 = iVar4;
    }
    if (iVar10 < 1) {
      uVar11 = uVar1;
      if ((iVar10 < 0) && (uVar11 = uVar1 - 0x200, -0x200 < iVar10)) {
        uVar11 = uVar3;
      }
    }
    else {
      uVar11 = uVar3;
      if (0x1ff < iVar10) {
        uVar11 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
    dVar25 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar27 = (double)FUN_140332d90();
    uVar34 = _UNK_14053bb28;
    dVar25 = _DAT_14053bb20;
    uVar31 = DAT_14053b33c;
    piVar14 = param_1 + 3;
    param_1[0xb] = (float)(dVar27 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (*piVar14 == 1) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),uVar31);
      dVar27 = dVar25;
      stage_entity_spawn_candidate
                (0x15,6000,10,DAT_14053adb4,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      param_1[0x17] = param_1[0x17] + 1;
      DAT_1407c77a0 = DAT_1407c779c;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    if (*piVar14 == 0xb) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),uVar31);
      dVar27 = dVar25;
      stage_entity_spawn_candidate
                (0x15,6000,10,DAT_14053b3d0,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      param_1[0x17] = param_1[0x17] + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar31 = DAT_14053b3a0;
    if (*piVar14 == 0x15) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),DAT_14053b3a0);
      dVar27 = dVar25;
      stage_entity_spawn_candidate
                (0x15,6000,10,DAT_14053ad2c,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      param_1[0x17] = param_1[0x17] + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    if (param_1[3] == 0x1f) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),uVar31);
      dVar27 = dVar25;
      stage_entity_spawn_candidate
                (0x15,6000,10,DAT_14053b388,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      param_1[0x17] = param_1[0x17] + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
    if (0xb3 < (int)param_1[3]) {
      iVar4 = 1;
      if (DAT_140e419b8 == 0) {
        iVar4 = 0x10;
      }
      else if (DAT_140e419b8 == 1) {
        iVar4 = 0xc;
      }
      else if (DAT_140e419b8 == 2) {
        iVar4 = 8;
      }
      else if (DAT_140e419b8 == 3) {
        iVar4 = 7;
      }
      else if (DAT_140e419b8 == 4) {
        iVar4 = 6;
      }
      uVar15 = 1;
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          uVar15 = 3;
        }
        else if (DAT_140e419b8 == 2) {
          uVar15 = 4;
        }
        else if (DAT_140e419b8 == 3) {
          uVar15 = 5;
        }
        else if (DAT_140e419b8 == 4) {
          uVar15 = 7;
        }
      }
      uVar20 = 1;
      if (DAT_140e419b8 == 0) {
        uVar20 = 0;
      }
      else if (DAT_140e419b8 == 1) {
        uVar20 = 7000;
      }
      else if (DAT_140e419b8 == 2) {
        uVar20 = 10000;
      }
      else if (DAT_140e419b8 == 3) {
        uVar20 = 12000;
      }
      else if (DAT_140e419b8 == 4) {
        uVar20 = 16000;
      }
      sVar18 = 1;
      if (DAT_140e419b8 == 0) {
        sVar18 = 0xb4;
      }
      else if (DAT_140e419b8 == 1) {
        sVar18 = 0xf0;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        sVar18 = 300;
      }
      else if (DAT_140e419b8 == 4) {
        sVar18 = 0x15e;
      }
      dVar27 = DAT_14053a040;
      if ((((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a070, DAT_140e419b8 != 1)) &&
          (dVar27 = DAT_14053a088, DAT_140e419b8 != 2)) &&
         ((dVar27 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar27 = dVar25, DAT_140e419b8 == 4)))) {
        dVar27 = DAT_14053a140;
      }
      if ((((int)param_1[0x17] < 1) && (dVar27 = dVar27 * DAT_140539f90, DAT_140e41b00 == 0)) &&
         ((DAT_140e467e8 == 0 && (DAT_140e44034 == 0)))) {
        DAT_140e44034 = 1;
        FUN_1400b4350(1,0x14);
        save_init_or_reset_candidate();
        DAT_140e45f68 = 0x3c;
      }
      iVar10 = param_1[3];
      if ((0xb3 < iVar10) &&
         (uVar33 = (longlong)(iVar10 + -0xb4) % (longlong)iVar4, (int)uVar33 == 0)) {
        uVar17 = CONCAT44(uVar35,1);
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        in_stack_fffffffffffffec8 =
             CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),
                      ((short)iVar10 + -0xb4) * sVar18 + -0x2000);
        dVar22 = dVar27;
        FUN_1400709b0(4,uVar33 & 0xffffffff,param_1[10],param_1[0xb],in_stack_fffffffffffffec8,
                      in_stack_fffffffffffffed0,dVar27,uVar17,uVar15,uVar20,0);
        uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
        uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        if ((int)param_1[0x17] < 1) {
          dVar22 = dVar27 + dVar25;
          uVar17 = CONCAT44(uVar35,1);
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          in_stack_fffffffffffffec8 =
               CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),
                        (*(short *)(param_1 + 3) + -0xb4) * sVar18 + 0x2000);
          FUN_1400709b0(5,0,param_1[10],param_1[0xb],in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,dVar22,uVar17,uVar15,uVar20,0);
          uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
      iVar10 = param_1[3];
      if ((0x117 < iVar10) && ((iVar10 + -0x118) % iVar4 == 0)) {
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        uVar17 = CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),
                          (0x118 - (short)iVar10) * sVar18 + -0x6000);
        dVar22 = dVar27;
        FUN_1400709b0(4,0,param_1[10],param_1[0xb],uVar17,in_stack_fffffffffffffed0,dVar27,
                      CONCAT44(uVar35,1),uVar15,uVar20,0);
        uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
        if ((int)param_1[0x17] < 1) {
          dVar27 = dVar27 + dVar25;
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          uVar17 = CONCAT62((int6)((ulonglong)uVar17 >> 0x10),
                            (0x118 - *(short *)(param_1 + 3)) * sVar18 + 0x6000);
          FUN_1400709b0(5,0,param_1[10],param_1[0xb],uVar17,in_stack_fffffffffffffed0,dVar27,1,
                        uVar15,uVar20,0);
          uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
          uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    if ((int)param_1[3] < 0x46) {
      local_res10 = 0;
    }
    else {
      uVar17 = CONCAT44(uVar36,2);
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),1);
      uVar31 = 0;
      local_res10 = FUN_1400c9580(param_1[3],0x46,7,3,0,in_stack_fffffffffffffed0,uVar17);
      uVar36 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    if ((int)param_1[3] < 10) {
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),4);
      uVar17 = CONCAT44(uVar31,3);
      local_res10 = FUN_1400c9580(param_1[3],0,5,2,uVar17,in_stack_fffffffffffffed0);
      uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    if (param_1[3] - 10 < 0x32) {
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),6);
      uVar17 = CONCAT44(uVar31,5);
      local_res10 = FUN_1400c9580(param_1[3],10,5,3,uVar17,in_stack_fffffffffffffed0,
                                  CONCAT44(uVar36,7));
      uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    if (param_1[3] - 0x3c < 10) {
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),3);
      uVar17 = CONCAT44(uVar31,4);
      local_res10 = FUN_1400c9580(param_1[3],0x3c,5,2,uVar17,in_stack_fffffffffffffed0);
      uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    goto LAB_1400072ad;
  case 4:
    iVar4 = param_1[3];
    dVar25 = (double)FUN_140332d90(((double)iVar4 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar31 = (undefined4)(in_stack_fffffffffffffed0 >> 0x20);
    dVar25 = dVar25 * _DAT_14053b070 + DAT_140539f40;
    puVar6 = DAT_140e45d28;
    if (iVar4 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar36 = param_1[0xb];
      uVar35 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar35;
        *(undefined4 *)(puVar6 + 3) = uVar36;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar35;
        *(undefined4 *)(puVar6 + 4) = uVar36;
        *puVar6 = 1;
        puVar6[1] = 0x36;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    piVar14 = param_1 + 3;
    if (*piVar14 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar33 = CONCAT44(uVar31,9);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar4 = FUN_1400c9580(*piVar14,0,5,2,8,uVar33);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar33 & 0xffffffffffff0000,dVar25,dVar25,0xff,0xff,0xff,0xff,1,0);
    if (*piVar14 == 0xb4) {
      iVar4 = param_1[5];
      param_1[0x15] = 0;
      *piVar14 = 0;
      if (iVar4 == 4) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 60000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar4 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 5:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar10 = (uVar19 & 0xffff) - (uint)uVar1;
    iVar4 = iVar10 + 0x10000;
    if (-0x8001 < iVar10) {
      iVar4 = iVar10;
    }
    iVar10 = iVar4 + -0x10000;
    if (iVar4 < 0x8001) {
      iVar10 = iVar4;
    }
    if (iVar10 < 1) {
      uVar11 = uVar1;
      if ((iVar10 < 0) && (uVar11 = uVar1 - 0x200, -0x200 < iVar10)) {
        uVar11 = uVar3;
      }
    }
    else {
      uVar11 = uVar3;
      if (0x1ff < iVar10) {
        uVar11 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
    dVar25 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar25 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar22 = (double)FUN_140332d90();
    uVar34 = _UNK_14053bb28;
    dVar25 = _DAT_14053bb20;
    uVar31 = DAT_14053b33c;
    uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
    param_1[0xb] = (float)(dVar22 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (param_1[3] == 1) {
      uVar36 = param_1[1];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        puVar6[1] = 0x2d;
        puVar6[2] = 0x3c;
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0x3ff0000000000000;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x3c;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar36;
        puVar6[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 = CONCAT44(uVar15,uVar31);
      dVar22 = dVar25;
      stage_entity_spawn_candidate
                (0x16,12000,10,DAT_14053adb4,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      param_1[0x17] = param_1[0x17] + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    piVar16 = param_1 + 0x17;
    piVar14 = param_1 + 3;
    if (*piVar14 == 0xb) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),uVar31);
      dVar22 = dVar25;
      stage_entity_spawn_candidate
                (0x16,12000,10,DAT_14053b3d0,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      *piVar16 = *piVar16 + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar31 = DAT_14053b3b0;
    if (*piVar14 == 0x15) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),DAT_14053b3b0);
      dVar22 = dVar25;
      stage_entity_spawn_candidate
                (0x17,7000,10,DAT_14053ad1c,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      *piVar16 = *piVar16 + 1;
      DAT_1407c77a0 = DAT_1407c779c;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    if (*piVar14 == 0x1f) {
      uVar17 = CONCAT44(uVar35,0x32);
      in_stack_fffffffffffffed0 = CONCAT62((int6)(in_stack_fffffffffffffed0 >> 0x10),0x4000);
      in_stack_fffffffffffffec8 =
           CONCAT44((int)((ulonglong)in_stack_fffffffffffffec8 >> 0x20),uVar31);
      dVar22 = dVar25;
      stage_entity_spawn_candidate
                (0x17,7000,10,DAT_14053b380,in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                 dVar25,uVar17,1,0);
      uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
      uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
      *piVar16 = *piVar16 + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    uVar31 = DAT_140e41a50;
    if (*piVar14 == 0x78) {
      uVar15 = param_1[1];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base();
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        *(undefined4 *)(puVar6 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar31;
        puVar6[2] = 0x23;
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x4014000000000000;
        puVar6[7] = 0x4014000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x28;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar15;
        puVar6[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
    }
    uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
    uVar19 = param_1[3];
    if (0x9f < (int)uVar19) {
      fVar28 = (float)param_1[0xb];
      fVar29 = (float)param_1[10];
      dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar28 - DAT_14053ac60)),
                                     (double)(DAT_140e445d8 - fVar29));
      iVar4 = 4 - param_1[0x17];
      uVar15 = 1;
      sVar18 = (short)(int)(dVar22 * dVar27);
      if (DAT_140e419b8 == 0) {
        uVar15 = 7;
      }
      else if (DAT_140e419b8 == 1) {
        uVar15 = 9;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar15 = 0xb;
      }
      else if (DAT_140e419b8 == 4) {
        uVar15 = 0xd;
      }
      dVar27 = DAT_14053a088;
      if ((((DAT_140e419b8 != 0) && (dVar27 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
          (dVar27 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar27 = dVar25, DAT_140e419b8 == 4)))) {
        dVar27 = DAT_14053a158;
      }
      dVar27 = (double)iVar4 * DAT_140539f00 + dVar27;
      if (param_1[0x17] == 0) {
        uVar12 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar12 = uVar12 * 0x800 ^ uVar12;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ DAT_140e9fd18 ^ uVar12;
        sVar18 = sVar18 + (short)DAT_140e9fd1c +
                          (short)((ulonglong)DAT_140e9fd1c / 0x1771) * -0x1771 + -3000;
        if ((0xa9 < (int)uVar19) &&
           (uVar33 = (longlong)(int)(uVar19 - 0xaa) % 0x14, (int)uVar33 == 0)) {
          uVar17 = CONCAT44(uVar35,1);
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          in_stack_fffffffffffffec8 =
               CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),sVar18);
          dVar22 = dVar27;
          FUN_1400709b0(3,uVar33 & 0xffffffff,fVar29,fVar28,in_stack_fffffffffffffec8,
                        in_stack_fffffffffffffed0,dVar27,uVar17,uVar15,0x8000,0);
          uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
          uVar35 = (undefined4)((ulonglong)uVar17 >> 0x20);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        if (((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e44034 == 0)) {
          DAT_140e44034 = 1;
          FUN_1400b4350(1,0x14);
          save_init_or_reset_candidate();
          DAT_140e45f68 = 0x3c;
        }
      }
      uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
      if ((0x9f < (int)param_1[3]) &&
         (uVar33 = (longlong)(param_1[3] + -0xa0) % (longlong)((5 - iVar4) * 0x14), (int)uVar33 == 0
         )) {
        in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
        uVar17 = CONCAT62((int6)((ulonglong)in_stack_fffffffffffffec8 >> 0x10),sVar18);
        dVar22 = dVar27;
        FUN_1400709b0(2,uVar33 & 0xffffffff,param_1[10],param_1[0xb],uVar17,
                      in_stack_fffffffffffffed0,dVar27,CONCAT44(uVar35,1),uVar15,0x8000,0);
        uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar36 = (undefined4)((ulonglong)dVar22 >> 0x20);
        if (2 < DAT_140e419b8) {
          dVar27 = dVar27 + DAT_140539fb8;
          in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffffffff00000000;
          uVar17 = CONCAT62((int6)((ulonglong)uVar17 >> 0x10),sVar18);
          FUN_1400709b0(2,0,param_1[10],param_1[0xb],uVar17,in_stack_fffffffffffffed0,dVar27,1,
                        uVar15,0x8000,0);
          uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
          uVar36 = (undefined4)((ulonglong)dVar27 >> 0x20);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    if ((int)param_1[3] < 0x50) {
      uVar17 = CONCAT44(uVar36,2);
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),1);
      uVar31 = 0;
      local_res10 = FUN_1400c9580(param_1[3],0,7,3,0,in_stack_fffffffffffffed0,uVar17);
      uVar36 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    if (param_1[3] - 0x50 < 10) {
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),4);
      uVar17 = CONCAT44(uVar31,3);
      local_res10 = FUN_1400c9580(param_1[3],0x50,5,2,uVar17,in_stack_fffffffffffffed0);
      uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
    if (0x59 < (int)param_1[3]) {
      in_stack_fffffffffffffed0 = CONCAT44((int)(in_stack_fffffffffffffed0 >> 0x20),6);
      uVar17 = CONCAT44(uVar31,5);
      local_res10 = FUN_1400c9580(param_1[3],0x5a,5,3,uVar17,in_stack_fffffffffffffed0,
                                  CONCAT44(uVar36,7));
      uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
    }
LAB_1400072ad:
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10 * 4),0x1e,7,param_1[10],
                  CONCAT44(uVar31,param_1[0xb]),in_stack_fffffffffffffed0 & 0xffffffffffff0000,
                  dVar25,uVar34,0xff,0xff,0xff,0xff,1,0);
    break;
  case 6:
    FUN_140003ad0(param_1);
    uVar34 = _UNK_14053bb28;
    dVar25 = _DAT_14053bb20;
    uVar36 = (undefined4)(in_stack_fffffffffffffed0 >> 0x20);
    iVar4 = param_1[3];
    if (iVar4 < 0xf0) {
      iVar10 = DAT_1407c7798 + 3;
      iVar9 = DAT_1407c7798 * 10;
      if (iVar4 - 0x3cU < 0xb4) {
        uVar33 = 0;
        uVar17 = CONCAT44(uVar31,0xf0);
        uVar26 = FUN_1401349e0(iVar4,0x3c,0x4c,0xe0,uVar17,0,_DAT_14053bb20);
        uVar31 = DAT_14053accc;
        uVar33 = uVar33 & 0xffffffffffff0000;
        uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),DAT_14053accc);
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,uVar17,uVar33,dVar25,uVar26,0xff,0xff,0xff,
                      0xff,1,0);
        uVar33 = uVar33 & 0xffffffffffff0000;
        uVar17 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),uVar31);
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar10 * 4),0x6e,1,DAT_14053ae44,
                      uVar17,uVar33,uVar26,uVar26,0xff,0xff,0xff,0xff,1,0);
        uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar36 = (undefined4)(uVar33 >> 0x20);
        if (iVar4 == 0x4c) {
          FUN_14012e070(iVar9 + 99,4);
        }
        else {
          lVar2 = DAT_140e47908;
          if (iVar4 == 0xe0) {
            while (lVar2 != 0) {
              lVar2 = *(longlong *)(lVar2 + 0x238);
              FUN_140323ce8();
              uVar31 = (undefined4)((ulonglong)uVar17 >> 0x20);
              uVar36 = (undefined4)(uVar33 >> 0x20);
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar33 = CONCAT44(uVar36,9);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar4 = FUN_1400c9580(param_1[3],0,5,2,CONCAT44(uVar31,8),uVar33);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar33 & 0xffffffffffff0000,dVar25,uVar34,0xff,0xff,0xff,0xff,1,0);
    }
    puVar6 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar31 = param_1[0xb];
      uVar36 = param_1[10];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar6 + 0x14) = uVar36;
        *(undefined4 *)(puVar6 + 3) = uVar31;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar36;
        *(undefined4 *)(puVar6 + 4) = uVar31;
        *puVar6 = 1;
        puVar6[1] = 0x10;
        *(undefined4 *)(puVar6 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x3ff0000000000000;
        puVar6[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar6 + 8) = 0;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        puVar6[10] = 0xff;
        puVar6[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
    }
    DAT_140e45d28 = puVar6;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


