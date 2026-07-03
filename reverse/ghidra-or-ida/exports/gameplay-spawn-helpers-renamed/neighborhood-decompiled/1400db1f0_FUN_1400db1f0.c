// Function: FUN_1400db1f0 @ 1400db1f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400db1f0(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  int *piVar13;
  uint uVar14;
  bool bVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  ulonglong in_stack_ffffffffffffff28;
  undefined4 uVar22;
  undefined8 uVar21;
  uint in_stack_ffffffffffffff30;
  undefined8 in_stack_ffffffffffffff38;
  undefined8 uVar23;
  undefined4 uVar24;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 uVar25;
  
  uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  dVar16 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  uVar22 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
  dVar16 = dVar16 * DAT_14053aba0;
  iVar4 = 0;
  uVar10 = 0;
  iVar5 = 0;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
    in_stack_ffffffffffffff28 = CONCAT44(uVar22,param_1[0xb]);
    in_stack_ffffffffffffff38 = DAT_14053a4f0;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,
               DAT_14053a4f0,CONCAT44(uVar25,param_1[0x14]),1,0);
    if (DAT_140e45da4 == 1) {
      uVar14 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar14 = uVar14 * 0x800 ^ uVar14;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
      in_stack_ffffffffffffff28 = DAT_14053a070;
      in_stack_ffffffffffffff30 = DAT_14053ac80;
      FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c +
                             (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                    DAT_14053a070,DAT_14053ac80);
      if (((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e44048 == 0)) {
        DAT_140e44048 = 1;
        FUN_1400b4350(1,0x19);
        save_init_or_reset_candidate();
        DAT_140e45f68 = 0x3c;
      }
    }
    if (DAT_140e41af8 == 1) {
      param_1[5] = 5;
      DAT_140e419bc = -1;
    }
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  uVar22 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar14 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar8 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
    uVar14 = uVar14 * 0x800 ^ uVar14;
    uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 4;
    uVar9 = DAT_1407c7798 * 0x6f + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar8 >> 0xb ^ uVar14) >> 8 ^ uVar8 ^ uVar14) % 0x12d + 0xd2);
    uVar14 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar14 = uVar14 * 0x800 ^ uVar14;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ DAT_140e9fd18 ^ uVar14;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  switch(param_1[5]) {
  case 0:
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    dVar18 = DAT_14053a020;
    dVar16 = DAT_140539d28;
    iVar4 = param_1[3];
    if (iVar4 < 0x6f) {
      uVar10 = iVar4 >> 0x1f & 0xfffffe0c;
      if ((-1 < iVar4) && (iVar4 < 0x6e)) {
        dVar17 = (double)FUN_140332d90(((double)iVar4 - 0.0) * _DAT_14053a508 * DAT_14053a020 *
                                       DAT_140539d28);
        uVar10 = -(int)(dVar17 * _DAT_14053b238) - 500;
      }
      param_1[10] = (float)(int)uVar10 + (float)param_1[0xc];
      dVar16 = (double)FUN_140332d90(((double)iVar4 - 0.0) * _DAT_14053a648 * dVar18 * dVar16);
      param_1[0xb] = (float)(dVar16 * DAT_14053a460) + 0.0 + (float)param_1[0xd];
      iVar5 = 0;
      if (iVar4 < 0x6e) {
        uVar23 = CONCAT44(uVar25,0x3e);
        in_stack_ffffffffffffff30 = 0;
        uVar21 = CONCAT44(uVar22,0x3c);
        iVar5 = FUN_1400c9580(iVar4,0,5,3,uVar21,0x3d,uVar23);
        uVar22 = (undefined4)((ulonglong)uVar21 >> 0x20);
        uVar25 = (undefined4)((ulonglong)uVar23 >> 0x20);
      }
    }
    if (0x6d < (int)param_1[3]) {
      in_stack_ffffffffffffff30 = 0;
      uVar21 = CONCAT44(uVar22,0x3f);
      iVar5 = FUN_1400c9580(param_1[3],0x6e,5,3,uVar21,0x40,CONCAT44(uVar25,0x41));
      uVar22 = (undefined4)((ulonglong)uVar21 >> 0x20);
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  CONCAT44(uVar22,param_1[0xb]),in_stack_ffffffffffffff30 & 0xffff0000,
                  _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x78) {
      param_1[5] = param_1[5] + 1;
      DAT_140e45da4 = 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
      DAT_140e41b0c = 50000;
      DAT_140e4430c = 0x690;
      DAT_140e4192c = 0;
      param_1[7] = 50000;
      DAT_140e419bc = 1;
      goto LAB_1400dc153;
    }
    break;
  case 1:
  case 3:
    uVar1 = *(ushort *)(param_1 + 0x10);
    iVar11 = ((int)dVar16 & 0xffffU) - (uint)uVar1;
    iVar5 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar11 = iVar5;
    }
    uVar2 = (ushort)(int)dVar16;
    if (iVar11 < 1) {
      uVar12 = uVar1;
      if ((iVar11 < 0) && (uVar12 = uVar1 - 0x200, -0x200 < iVar11)) {
        uVar12 = uVar2;
      }
    }
    else {
      uVar12 = uVar2;
      if (0x1ff < iVar11) {
        uVar12 = uVar1 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar12;
    dVar16 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar16 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar16 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar16 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar22 = DAT_14053ad1c;
    uVar21 = DAT_14053a678;
    iVar5 = iVar4;
    if (param_1[3] == 1) {
      do {
        in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
        in_stack_ffffffffffffff38 = uVar21;
        stage_entity_spawn_candidate
                  (0x61,99999999,10,uVar22,in_stack_ffffffffffffff28,
                   (short)iVar5 * -0x8000 + -0x4000,uVar21,0x14,1,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    uVar21 = DAT_14053b218;
    uVar22 = DAT_14053ad70;
    uVar25 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
    uVar24 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
    if (param_1[3] == 10) {
      uVar14 = 1;
      if (DAT_140e419b8 == 0) {
        uVar14 = 4;
      }
      else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) ||
              ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
        uVar14 = 8;
      }
      iVar5 = iVar4;
      if ((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) {
        if (DAT_140e419b8 == 2) {
          uVar10 = 4;
        }
        else if ((DAT_140e419b8 == 3) || (uVar10 = 1, DAT_140e419b8 == 4)) {
          uVar10 = 8;
        }
      }
      do {
        if (param_1[5] == 1) {
          in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
          in_stack_ffffffffffffff38 = uVar21;
          stage_entity_spawn_candidate
                    (0x62,99999999,10,uVar22,in_stack_ffffffffffffff28,
                     (short)(0x10000 / uVar14) * (short)iVar5 + -0x4000,uVar21,0x14,1,0);
        }
        if (param_1[5] == 3) {
          in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
          in_stack_ffffffffffffff38 = uVar21;
          stage_entity_spawn_candidate
                    (99,99999999,10,uVar22,in_stack_ffffffffffffff28,
                     (short)(0x10000 / uVar14) * (short)iVar5 + -0x4000,uVar21,0x14,1,0);
        }
        uVar3 = DAT_14053adb4;
        uVar23 = DAT_14053a5c0;
        uVar25 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
        uVar24 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar14);
      if (uVar10 != 0) {
        do {
          if (param_1[5] == 1) {
            in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
            in_stack_ffffffffffffff38 = uVar23;
            stage_entity_spawn_candidate
                      (99,99999999,10,uVar3,in_stack_ffffffffffffff28,
                       (short)(0x10000 / (ulonglong)uVar10) * (short)iVar4 + 0x1000,uVar23,0x14,1,0)
            ;
          }
          if (param_1[5] == 3) {
            in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;
            in_stack_ffffffffffffff38 = uVar23;
            stage_entity_spawn_candidate
                      (0x62,99999999,10,uVar3,in_stack_ffffffffffffff28,
                       (short)(0x10000 / (ulonglong)uVar10) * (short)iVar4 + 0x1000,uVar23,0x14,1,0)
            ;
          }
          uVar25 = (undefined4)(in_stack_ffffffffffffff28 >> 0x20);
          uVar24 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)uVar10);
      }
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    iVar5 = FUN_1400c9580(param_1[3],0,7,3,CONCAT44(uVar25,0x41),0x42,CONCAT44(uVar24,0x43));
    uVar22 = param_1[0xb];
    uVar25 = param_1[10];
    uVar24 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4);
    puVar6 = (undefined4 *)_malloc_base(0x48);
    if (puVar6 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e46d08 = DAT_140e46d08 + 1;
    bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar6[3] = uVar25;
    puVar6[4] = uVar22;
    *puVar6 = uVar24;
    puVar6[1] = 0x1e;
    puVar6[2] = 7;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined8 *)(puVar6 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
    puVar6[10] = 0xff;
    puVar6[0xb] = 0xff;
    puVar6[0xc] = 0xff;
    puVar6[0xd] = 0xff;
    *(undefined8 *)(puVar6 + 0xe) = 1;
    *(undefined8 *)(puVar6 + 0x10) = 0;
    if (bVar15) {
      DAT_140e46bf0 = puVar6;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
    }
    DAT_140e46c88 = puVar6;
    if (param_1[3] == 0x28a) {
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 1;
      param_1[3] = 0;
    }
    break;
  case 2:
  case 4:
    if (param_1[3] == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
      if (param_1[5] == 2) {
        param_1[0xe] = 0x435c0000;
        param_1[0xf] = 0x43160000;
      }
      else if (param_1[5] == 4) {
        param_1[0xe] = 0x43e10000;
        param_1[0xf] = 0x43520000;
      }
    }
    uVar10 = DAT_140e418c8;
    piVar13 = param_1 + 5;
    uVar24 = param_1[3];
    dVar16 = (double)FUN_140332d90();
    fVar20 = (float)(dVar16 * (double)((float)param_1[0xe] - (float)param_1[0xc])) +
             (float)param_1[0xc];
    dVar16 = (double)FUN_140332d90();
    param_1[10] = fVar20;
    uVar14 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    fVar19 = (float)(dVar16 * (double)((float)param_1[0xf] - (float)param_1[0xd])) +
             (float)param_1[0xd];
    uVar14 = uVar14 * 0x800 ^ uVar14;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
    dVar16 = (double)FUN_140332d90();
    iVar5 = FUN_140134d00(uVar10,0,(int)(dVar16 * DAT_14053a650));
    dVar16 = (double)FUN_1403307c0();
    dVar18 = (double)FUN_140332d90();
    uVar10 = 0;
    param_1[0xb] = fVar19;
    fVar19 = (float)(dVar18 * (double)iVar5) + fVar19;
    iVar4 = FUN_1400c9580(uVar24,0,7,3,CONCAT44(uVar22,0x41),0x42,CONCAT44(uVar25,0x43));
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar4 * 4),0x1e,7,
                  (float)(dVar16 * (double)iVar5) + fVar20,fVar19,uVar10 & 0xffff0000,_DAT_14053bb20
                  ,_UNK_14053bb28,0xff,0xff,0xff,0xc0,1,0);
    if (param_1[3] == 0x50) {
      param_1[0x15] = 0;
      param_1[3] = 0;
      if (*piVar13 == 4) {
        *piVar13 = 1;
      }
      else {
        *piVar13 = *piVar13 + 1;
      }
    }
    break;
  case 5:
    iVar5 = param_1[3];
    if (iVar5 < 0x78) {
      FUN_14007ac00(param_1);
      uVar10 = 0;
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,CONCAT44(uVar22,0x44),0x45);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar10 & 0xffff0000,_DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,
                    0xff,1,0);
      iVar5 = param_1[3];
    }
    if (iVar5 == 0x78) {
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
        bVar15 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar25;
        *(undefined4 *)(puVar7 + 3) = uVar22;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar25;
        *(undefined4 *)(puVar7 + 4) = uVar22;
        *puVar7 = 1;
        puVar7[1] = 0x10;
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
        if (bVar15) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
      DAT_140e45d28 = puVar7;
      DAT_140e418cc = 0;
      *param_1 = 0;
    }
  }
  if (DAT_140e4430c < 0x348) {
    DAT_140e45da4 = 0;
  }
LAB_1400dc153:
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


