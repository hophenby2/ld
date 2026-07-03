// Function: state_14_replay_demo_gameplay_update_candidate @ 1400bca30
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_14_replay_demo_gameplay_update_candidate(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  double dVar5;
  float fVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  char cVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  longlong lVar16;
  int *piVar17;
  ulonglong uVar18;
  undefined8 *puVar19;
  undefined4 *puVar20;
  ulonglong uVar21;
  longlong lVar22;
  ulonglong uVar23;
  short sVar24;
  int *piVar25;
  uint uVar26;
  undefined4 *puVar27;
  bool bVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  float fVar33;
  undefined8 in_stack_fffffffffffffee8;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined4 uVar36;
  uint in_stack_fffffffffffffef0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [16];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  
  fVar6 = DAT_14053ac64;
  puVar27 = &DAT_140e45100;
  local_c8 = _DAT_14053b6e0;
  uStack_c0 = _UNK_14053b6e8;
  local_98 = 5;
  local_b8 = _DAT_14053b750;
  local_94 = 5;
  local_a8 = _DAT_14053b6d0;
  uStack_a0 = _UNK_14053b6d8;
  local_90 = 5;
  if ((((DAT_140e418c8 == DAT_140e45d74 + 1U) &&
       (lVar16 = (longlong)(int)DAT_1407c7798,
       (int)DAT_140e418c8 < *(int *)(&UNK_140538ad8 + lVar16 * 4))) &&
      ((DAT_140e41928 != 1 || (DAT_140e41abc != 1)))) && (DAT_140e45270 != 0x2a)) {
    if (DAT_140e45d74 == 0) {
      if (DAT_1407c7798 == 10) {
        _DAT_1407c777c = 0.0;
      }
      else {
        iVar12 = *(int *)((longlong)&local_c8 + lVar16 * 4);
        _DAT_1407c777c = 1.0;
        FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),(&DAT_140e45100)[iVar12]);
        FUN_14018a340((&DAT_140e45100)[iVar12],3,1);
      }
    }
    else {
      uVar36 = *(undefined4 *)((longlong)&local_c8 + lVar16 * 4);
      _DAT_1407c777c = 0.0;
      if (DAT_1407c7798 == 10) {
        FUN_1401107d0(uVar36,(longlong)DAT_14053b750,300);
      }
      else {
        FUN_1401107d0(uVar36,(longlong)DAT_14053b750,0);
      }
    }
    DAT_140e45100 =
         (&DAT_140e45100)[*(int *)((longlong)&local_c8 + (longlong)(int)DAT_1407c7798 * 4)];
  }
  dVar5 = DAT_14053a020;
  dVar32 = DAT_140539d28;
  if ((((DAT_140e45d74 != 0) && (DAT_140e45d74 + 1 <= (int)DAT_140e418c8)) &&
      ((int)DAT_140e418c8 < DAT_140e45d74 + 0x3c)) &&
     ((int)DAT_140e418c8 < *(int *)(&UNK_140538ad8 + (longlong)(int)DAT_1407c7798 * 4))) {
    dVar29 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - (double)DAT_140e45d74) *
                                   DAT_14053a628 * DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)dVar29 + 0.0;
    FUN_140184700((int)((float)DAT_140e4418c * fVar6 * _DAT_1407c777c),DAT_140e45100);
  }
  uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  if (DAT_140e41b00 == 0) {
    piVar17 = (int *)_malloc_base(0x10);
    if (piVar17 == (int *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    bVar28 = DAT_140e467b8 == 1;
    *piVar17 = DAT_140e45284;
    *(undefined2 *)(piVar17 + 1) = 0;
    if (bVar28) {
      *(undefined2 *)(piVar17 + 1) = 1;
    }
    uVar11 = (ushort)bVar28;
    if (DAT_140e467bc == 1) {
      uVar11 = uVar11 | 2;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467c0 == 1) {
      uVar11 = uVar11 | 4;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467c4 == 1) {
      uVar11 = uVar11 | 8;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    iVar12 = DAT_140e467c8;
    if (DAT_140e467c8 == 1) {
      uVar11 = uVar11 | 0x10;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if ((int)DAT_140e467cc == 1) {
      uVar11 = uVar11 | 0x20;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467cc._4_4_ == 1) {
      uVar11 = uVar11 | 0x40;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467d4 == 1) {
      uVar11 = uVar11 | 0x80;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467d8 == 1) {
      uVar11 = uVar11 | 0x100;
      *(ushort *)(piVar17 + 1) = uVar11;
    }
    if (DAT_140e467dc == 1) {
      *(ushort *)(piVar17 + 1) = uVar11 | 0x200;
    }
    DAT_140e45284 = DAT_140e45284 + 1;
    piVar17[2] = 0;
    piVar17[3] = 0;
    if (DAT_140e45278 == (int *)0x0) {
      DAT_140e45278 = piVar17;
    }
    if (DAT_140e9fd00 != (int *)0x0) {
      *(int **)(DAT_140e9fd00 + 2) = piVar17;
    }
LAB_1400bcf20:
    DAT_140e9fd00 = piVar17;
    if (DAT_140e45270 == 0x2a) {
      if (DAT_140e45284 < 0x960) {
        if ((iVar12 == 1) && (DAT_140e46b28 < DAT_140e45284 + -0x78)) {
          DAT_140e45284 = DAT_140e46b28 + 0x3c;
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47204);
          FUN_14018a340(DAT_140e47204,1,1);
        }
        if (DAT_140e45284 + -0x3c <= DAT_140e46b28) {
          transition_tile_wipe_out_candidate((DAT_140e46b28 - DAT_140e45284) + 0x3c);
        }
        bVar28 = SBORROW4(DAT_140e46b28,DAT_140e45284);
        iVar12 = DAT_140e46b28 - DAT_140e45284;
      }
      else {
        if ((iVar12 == 1) && (DAT_140e46b28 < 0x8e8)) {
          DAT_140e45284 = DAT_140e46b28 + 0x3c;
          FUN_140184700(DAT_140e44190 * 0x14,DAT_140e47204);
          FUN_14018a340(DAT_140e47204,1,1);
        }
        if (0x923 < DAT_140e46b28) {
          transition_tile_wipe_out_candidate(DAT_140e46b28 + -0x924);
        }
        bVar28 = SBORROW4(DAT_140e46b28,0x960);
        iVar12 = DAT_140e46b28 + -0x960;
      }
      if (bVar28 == iVar12 < 0) {
        FUN_1400f6fb0();
        DAT_140e45270 = 2;
        goto LAB_1400bd02b;
      }
    }
  }
  else {
    piVar17 = DAT_140e45278;
    if (DAT_140e46b28 < DAT_140e45284) {
      for (; piVar17 != (int *)0x0; piVar17 = *(int **)(piVar17 + 2)) {
        if (DAT_140e46b28 == *piVar17) {
          uVar11 = *(ushort *)(piVar17 + 1);
          DAT_140e467b8 = (uint)((uVar11 & 1) != 0);
          DAT_140e467bc = (uint)((uVar11 & 2) != 0);
          DAT_140e467c0 = (uint)((uVar11 & 4) != 0);
          DAT_140e467c4 = (uint)((uVar11 & 8) != 0);
          DAT_140e467cc._4_4_ = (uint)((uVar11 & 0x40) != 0);
          DAT_140e467d4 = (uint)((char)uVar11 < '\0');
          DAT_140e467d8 = (uint)((uVar11 >> 8 & 1) != 0);
          DAT_140e467dc = 0;
          if ((uVar11 >> 9 & 1) != 0) {
            DAT_140e467dc = 1;
          }
          break;
        }
      }
      DAT_140e46b28 = DAT_140e46b28 + 1;
      iVar12 = DAT_140e467c8;
      piVar17 = DAT_140e9fd00;
      goto LAB_1400bcf20;
    }
    puVar20 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar20,0);
      uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
      puVar20 = puVar20 + 1;
    } while ((longlong)puVar20 < 0x140e45178);
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
    FUN_14018a340(DAT_140e4721c,1,1);
    DAT_140e46a20 = 1;
    DAT_140e46014 = 0;
    DAT_140e45fac = 0;
    DAT_140e467fc = 1;
    DAT_140e45270 = 0x27;
    DAT_140e41a38 = 1;
LAB_1400bd02b:
    DAT_140e45274 = 0;
  }
  uVar26 = DAT_140e418c8;
  uVar23 = 0;
  DAT_1407c77a4 = 1;
  if (DAT_140e451a4 == 1) {
    if ((((0xe6 < (int)DAT_140e418c8) && (DAT_140e45d74 + 10 <= (int)DAT_140e418c8)) &&
        ((int)DAT_140e418c8 < *(int *)(&UNK_140538ad8 + (longlong)(int)DAT_1407c7798 * 4) + -0x168))
       && (DAT_140e418cc == 0)) {
      piVar25 = DAT_140e45d80;
      piVar17 = DAT_140e45d80;
      uVar21 = uVar23;
      iVar12 = FUN_1401340e0();
      if ((iVar12 == 0) || (piVar25 == (int *)0x0)) {
LAB_1400bd0ce:
        DAT_1407c77a4 = 4;
      }
      else {
        do {
          if ((*piVar17 == 1) && (piVar17[0x15] == 0)) {
            uVar21 = (ulonglong)(uint)((int)uVar21 + piVar17[0x14]);
          }
          piVar17 = *(int **)(piVar17 + 0x18);
        } while (piVar17 != (int *)0x0);
        if ((int)uVar21 == 0) goto LAB_1400bd0ce;
      }
      if ((iVar12 == 0) || (piVar17 = piVar25, uVar21 = uVar23, piVar25 == (int *)0x0)) {
LAB_1400bd134:
        if (iVar12 == 0) goto LAB_1400bd18a;
      }
      else {
        do {
          if ((*piVar17 == 1) && (piVar17[0x15] == 0)) {
            uVar21 = (ulonglong)(uint)((int)uVar21 + piVar17[0x14]);
          }
          piVar17 = *(int **)(piVar17 + 0x18);
        } while (piVar17 != (int *)0x0);
        piVar17 = piVar25;
        uVar18 = uVar23;
        if ((int)uVar21 < 1) goto LAB_1400bd134;
        do {
          if ((*piVar17 == 1) && (piVar17[0x15] == 0)) {
            uVar18 = (ulonglong)(uint)((int)uVar18 + piVar17[0x14]);
          }
          piVar1 = piVar17 + 0x18;
          piVar17 = *(int **)piVar1;
        } while (*(int **)piVar1 != (int *)0x0);
        if (0x45 < (int)uVar18) goto LAB_1400bd134;
        DAT_1407c77a4 = 3;
      }
      piVar17 = piVar25;
      uVar21 = uVar23;
      if (piVar25 != (int *)0x0) {
        do {
          if ((*piVar17 == 1) && (piVar17[0x15] == 0)) {
            uVar21 = (ulonglong)(uint)((int)uVar21 + piVar17[0x14]);
          }
          piVar17 = *(int **)(piVar17 + 0x18);
        } while (piVar17 != (int *)0x0);
        uVar18 = uVar23;
        if (0x45 < (int)uVar21) {
          do {
            if ((*piVar25 == 1) && (piVar25[0x15] == 0)) {
              uVar18 = (ulonglong)(uint)((int)uVar18 + piVar25[0x14]);
            }
            piVar25 = *(int **)(piVar25 + 0x18);
          } while (piVar25 != (int *)0x0);
          if ((int)uVar18 < 0x8c) {
            DAT_1407c77a4 = 2;
          }
        }
      }
    }
LAB_1400bd18a:
    DAT_140e451b0 = DAT_140e451b0 + 1;
  }
  if (((DAT_140e46be8 == 1) && (uVar26 == DAT_140e45d74 + 0x3cU)) && (DAT_1407c7798 != 0)) {
    FUN_1400c6e10();
    uVar26 = DAT_140e418c8;
  }
  uVar8 = DAT_140e41a74;
  if (uVar26 == DAT_140e45d74 + 1U) {
    DAT_140e41b08 = 0;
    DAT_140e41a3c = 0;
    iVar12 = DAT_140e45d1c;
    puVar19 = DAT_140e45d28;
    if (((0 < DAT_140e45d34) && (DAT_140e445d0 != 3)) && (DAT_140e45d1c < 0x1000)) {
      puVar19 = (undefined8 *)_malloc_base(0x60);
      if (puVar19 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar12 = DAT_140e45d1c + 1;
      *puVar19 = 1;
      bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)(puVar19 + 1) = 0x14;
      *(undefined4 *)((longlong)puVar19 + 0xc) = uVar8;
      puVar19[2] = 0x27;
      puVar19[3] = 0;
      *(undefined4 *)(puVar19 + 4) = 0;
      *(undefined2 *)((longlong)puVar19 + 0x24) = 0;
      puVar19[5] = 0;
      puVar19[6] = 0x3ff0000000000000;
      puVar19[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar19 + 8) = 0;
      *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
      *(undefined4 *)(puVar19 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
      puVar19[10] = 0xff;
      puVar19[0xb] = 0;
      if (bVar28) {
        DAT_140e45d78 = puVar19;
      }
      uVar26 = DAT_140e418c8;
      DAT_140e45d1c = iVar12;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar19;
        uVar26 = DAT_140e418c8;
      }
    }
    DAT_140e45d28 = puVar19;
    fVar33 = DAT_140e445dc;
    fVar6 = DAT_140e445d8;
    uVar8 = DAT_140e41950;
    puVar19 = DAT_140e45d28;
    if ((49999 < DAT_140e45d18) && (iVar12 < 0x1000)) {
      puVar19 = (undefined8 *)_malloc_base(0x60);
      if (puVar19 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar19 + 0x14) = fVar6;
      *(float *)(puVar19 + 3) = fVar33;
      *(float *)((longlong)puVar19 + 0x1c) = fVar6;
      *(float *)(puVar19 + 4) = fVar33;
      *puVar19 = 1;
      *(undefined4 *)(puVar19 + 1) = 0x15;
      *(undefined4 *)((longlong)puVar19 + 0xc) = uVar8;
      *(undefined4 *)(puVar19 + 2) = 0x4a;
      *(undefined2 *)((longlong)puVar19 + 0x24) = 0;
      puVar19[5] = 0;
      puVar19[6] = 0x3ff0000000000000;
      puVar19[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar19 + 8) = 0;
      *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
      *(undefined4 *)(puVar19 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
      puVar19[10] = 0xc0;
      puVar19[0xb] = 0;
      if (bVar28) {
        DAT_140e45d78 = puVar19;
      }
      uVar26 = DAT_140e418c8;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar19;
        uVar26 = DAT_140e418c8;
      }
    }
    DAT_140e45d28 = puVar19;
    uVar7 = DAT_14053ac80;
    uVar35 = DAT_14053a070;
    if ((DAT_140e41928 != 1) || (DAT_140e41abc != 1)) goto LAB_1400bd625;
    uVar13 = DAT_1407c7798 & 0x80000001;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffffe) + 1;
    }
    if (uVar13 != 1) goto LAB_1400bd625;
    uVar26 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar26 = uVar26 * 0x800 ^ uVar26;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar26) >> 8 ^ DAT_140e9fd18 ^ uVar26;
    uVar34 = DAT_14053a070;
    in_stack_fffffffffffffef0 = DAT_14053ac80;
    FUN_1400ca6d0(6,(ulonglong)DAT_140e9fd1c / 0x4001,0,
                  CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                           (short)DAT_140e9fd1c +
                           (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),
                  DAT_14053a070,DAT_14053ac80);
    iVar12 = DAT_140e445c0;
    uVar36 = (undefined4)((ulonglong)uVar34 >> 0x20);
    uVar21 = (ulonglong)DAT_140e419b8;
    uVar26 = DAT_140e418c8;
    if (((DAT_1407c7798 == 1) &&
        (iVar14 = FUN_140135290(DAT_140e41abc + 0xb,DAT_140e445c0,uVar21), uVar26 = DAT_140e418c8,
        iVar14 != 0)) && (uVar18 = uVar23, 0 < iVar14)) {
      do {
        uVar26 = DAT_140e418c8 + 0x29a + (int)uVar18;
        uVar26 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar26 = uVar26 * 0x800 ^ uVar26;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar26) >> 8 ^ DAT_140e9fd18 ^ uVar26;
        uVar34 = uVar35;
        in_stack_fffffffffffffef0 = uVar7;
        FUN_1400ca6d0(7,(ulonglong)DAT_140e9fd1c / 0x4001,0,
                      CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                               (short)DAT_140e9fd1c +
                               (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + 0x2000),uVar35
                      ,uVar7);
        iVar12 = DAT_140e445c0;
        uVar36 = (undefined4)((ulonglong)uVar34 >> 0x20);
        uVar13 = (int)uVar18 + 1;
        uVar21 = (ulonglong)DAT_140e419b8;
        iVar14 = FUN_140135290(DAT_140e41abc + 0xb,DAT_140e445c0,uVar21);
        uVar18 = (ulonglong)uVar13;
        uVar26 = DAT_140e418c8;
      } while ((int)uVar13 < iVar14);
    }
  }
  else {
LAB_1400bd625:
    uVar21 = (ulonglong)DAT_140e419b8;
    iVar12 = DAT_140e445c0;
  }
  if ((int)uVar26 < DAT_140e45d74 + 0x3c) {
    transition_tile_wipe_in_candidate(uVar26 - DAT_140e45d74);
    uVar21 = (ulonglong)DAT_140e419b8;
    uVar26 = DAT_140e418c8;
    iVar12 = DAT_140e445c0;
  }
  dVar29 = DAT_140539f40;
  if ((DAT_140e45d74 + 0x3c <= (int)uVar26) && ((int)uVar26 <= DAT_140e45d74 + 0x42)) {
    DAT_140e41a38 = 0;
  }
  if ((((int)uVar26 < DAT_140e45d74 + 0xb4) && (DAT_1407c7798 == DAT_140e452c0)) &&
     ((DAT_140e45d74 == 0 && (DAT_140e41928 != -1)))) {
    if ((int)uVar26 < 0x1e) {
      dVar30 = 0.0;
    }
    else {
      dVar30 = DAT_140539f40;
      if ((int)uVar26 < 0x28) {
        dVar30 = (double)FUN_140332d90(((double)(int)uVar26 - DAT_14053a2d8) * DAT_14053a9d8 * dVar5
                                       * dVar32);
        dVar30 = dVar30 + 0.0;
      }
    }
    dVar31 = (double)FUN_140332d90(((double)(int)uVar26 - 0.0) * DAT_14053abd8 * dVar5 * dVar32);
    iVar12 = 0xc0 - (int)(dVar31 * DAT_14053b160);
    if ((int)uVar26 < 0xa0) {
      if (0xb3 < (int)uVar26) goto LAB_1400bd7a3;
    }
    else if ((int)uVar26 < 0xb4) {
      dVar31 = (double)FUN_140332d90((DAT_14053ac08 / 80.0) * ((double)(int)uVar26 - 140.0) * dVar5
                                     * dVar32);
      iVar12 = (int)(dVar31 * (double)iVar12);
    }
    else {
LAB_1400bd7a3:
      iVar12 = 0;
    }
    if (DAT_1407c7798 != 10) {
      in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
      uVar35 = CONCAT44(uVar36,DAT_14053ae14);
      FUN_1400c8410(DAT_140e450b0,0x5a,1,DAT_14053aedc,uVar35,in_stack_fffffffffffffef0,
                    DAT_140539f50,dVar30,0xff,0xff,0xff,iVar12,1,0);
      uVar36 = (undefined4)((ulonglong)uVar35 >> 0x20);
    }
    FUN_1400c8410(DAT_140e450b4,0x5a,7,DAT_140e445d8,CONCAT44(uVar36,DAT_140e445dc),
                  in_stack_fffffffffffffef0 & 0xffff0000,dVar29,dVar30,0xff,0xff,0xff,iVar12,1,0);
    uVar21 = (ulonglong)DAT_140e419b8;
    uVar26 = DAT_140e418c8;
    iVar12 = DAT_140e445c0;
  }
  if ((((int)uVar26 < 0xf0) ||
      (*(int *)(&UNK_140538ad8 + (longlong)(int)DAT_1407c7798 * 4) + -0x14a <= (int)uVar26)) &&
     ((((int)uVar26 < *(int *)(&UNK_140538ad8 + (longlong)(int)DAT_1407c7798 * 4) ||
       (iVar14 = FUN_1401340e0(), iVar14 == 0)) && (DAT_140e451b4 == 0)))) {
    iVar14 = FUN_1401340e0();
    DAT_140e46b2c = 1;
    if (iVar14 != 0) goto LAB_1400bd8e3;
  }
  else {
LAB_1400bd8e3:
    DAT_140e46b2c = 0;
  }
  uVar18 = DAT_140e44590;
  iVar14 = (int)uVar21;
  if (DAT_140e44640 == 0) {
    if (DAT_140e451a4 == 0) {
      uVar26 = uVar26 & 0x80000001;
      if ((int)uVar26 < 0) {
        uVar26 = (uVar26 - 1 | 0xfffffffe) + 1;
      }
    }
    else {
      if (DAT_140e451a4 != 1) goto LAB_1400bd93c;
      uVar26 = DAT_140e451b0 & 0x80000001;
      if ((int)uVar26 < 0) {
        uVar26 = (uVar26 - 1 | 0xfffffffe) + 1;
      }
    }
    if (0 < (int)uVar26) {
      DAT_140e46b2c = 1;
    }
  }
LAB_1400bd93c:
  if ((DAT_140e46ae0 < DAT_140e44590) && (DAT_140e41b00 == 0)) {
    if (DAT_140e41928 == 0) {
      iVar15 = FUN_140135290(DAT_1407c7798,iVar12,uVar21 & 0xffffffff);
    }
    else {
      if (DAT_140e41928 != 1) goto LAB_1400bda37;
      iVar15 = FUN_140135290(DAT_140e41abc + 0xb,iVar12,uVar21 & 0xffffffff);
    }
    if (iVar15 == 0) {
      DAT_140e46ae0 = uVar18;
      if (DAT_140e41928 == 0) {
        lVar16 = (longlong)(int)DAT_1407c7798 * 3 + (longlong)iVar12;
      }
      else {
        if (DAT_140e41928 != 1) goto LAB_1400bda37;
        if (DAT_1407c7798 == 10) {
          *(ulonglong *)
           (&DAT_140e43340 +
           ((longlong)iVar12 * 0x19 + (longlong)iVar14 * 2 + (longlong)DAT_140e45268) * 8) = uVar18;
          goto LAB_1400bda50;
        }
        lVar16 = (longlong)(DAT_140e41abc + 0xb) * 3 + (longlong)iVar12;
      }
      (&DAT_140e41bd0)[lVar16 * 0x19 + (longlong)iVar14 * 2 + (longlong)DAT_140e45268] = uVar18;
    }
LAB_1400bda50:
    if (DAT_140e43ee8 < uVar18) {
      DAT_140e43ee8 = uVar18;
    }
    if (DAT_140e43ef0 < DAT_1407c77a8) {
      DAT_140e43ef0 = DAT_1407c77a8;
    }
  }
  else {
LAB_1400bda37:
    if (((DAT_140e41928 != -1) && (DAT_140e41928 != 2)) && (DAT_140e41b00 == 0)) goto LAB_1400bda50;
  }
  FUN_1400be7a0(DAT_1407c7798);
  FUN_1400c2860();
  dVar30 = DAT_14053b1c8;
  dVar29 = DAT_14053a798;
  if (DAT_140e41b00 == 1) {
    if (DAT_140e45270 == 0x14) {
      dVar31 = (double)FUN_140332d90(((double)DAT_140e44acc - 0.0) * DAT_14053a798 * dVar5 * dVar32)
      ;
      uVar36 = DAT_140e46b78;
      puVar20 = (undefined4 *)_malloc_base(0x48);
      if (puVar20 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e4c = _DAT_140e46e4c + 1;
      bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar20 = uVar36;
      puVar20[1] = 0x6f;
      puVar20[2] = 1;
      puVar20[3] = 0x44520000;
      puVar20[4] = 0x442f0000;
      *(undefined2 *)(puVar20 + 5) = 0;
      *(undefined8 *)(puVar20 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar20 + 8) = 0x3ff0000000000000;
      puVar20[10] = 0xff;
      puVar20[0xb] = 0xff;
      puVar20[0xc] = 0xff;
      puVar20[0xd] = 0x80 - (int)(dVar31 * dVar30);
      *(undefined8 *)(puVar20 + 0xe) = 1;
      *(undefined8 *)(puVar20 + 0x10) = 0;
      if (bVar28) {
        DAT_140e46bf0 = puVar20;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar20;
      }
      DAT_140e46c88 = puVar20;
      FUN_1400d9b60(4,0x70,0xff);
    }
    if (DAT_140e45270 == 0x2a) {
      dVar32 = (double)FUN_140332d90(((double)DAT_140e44acc - 0.0) * dVar29 * dVar5 * dVar32);
      uVar36 = DAT_140e450b8;
      puVar20 = (undefined4 *)_malloc_base(0x48);
      if (puVar20 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e4c = _DAT_140e46e4c + 1;
      bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar20 = uVar36;
      puVar20[1] = 0x6f;
      puVar20[2] = 1;
      puVar20[3] = 0x44200000;
      puVar20[4] = 0x43b40000;
      *(undefined2 *)(puVar20 + 5) = 0;
      *(undefined8 *)(puVar20 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar20 + 8) = 0x3ff0000000000000;
      puVar20[10] = 0xff;
      puVar20[0xb] = 0xff;
      puVar20[0xc] = 0xff;
      puVar20[0xd] = 0x80 - (int)(dVar32 * dVar30);
      *(undefined8 *)(puVar20 + 0xe) = 1;
      *(undefined8 *)(puVar20 + 0x10) = 0;
      if (bVar28) {
        DAT_140e46bf0 = puVar20;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar20;
      }
      DAT_140e46c88 = puVar20;
      FUN_1400d9b60(8,0x70,0xff);
    }
  }
  if (0 < DAT_1407c77a4) {
    do {
      switch(DAT_1407c7798) {
      case 0:
        stage_00_gameplay_update_candidate();
        break;
      default:
        stage_01_gameplay_update_candidate();
        break;
      case 2:
        stage_02_gameplay_update_candidate();
        break;
      case 3:
        stage_03_gameplay_update_candidate();
        break;
      case 4:
        stage_04_gameplay_update_candidate();
        break;
      case 5:
        stage_05_gameplay_update_candidate();
        break;
      case 6:
        stage_06_gameplay_update_candidate();
        break;
      case 7:
        stage_07_gameplay_update_candidate();
        break;
      case 8:
        stage_08_gameplay_update_candidate();
        break;
      case 9:
        stage_09_gameplay_update_candidate();
        break;
      case 10:
        stage_10_gameplay_update_candidate();
      }
      if ((1 < DAT_1407c77a4) && ((int)uVar23 < DAT_1407c77a4 + -1)) {
        DAT_140e418c8 = DAT_140e418c8 + 1;
      }
      uVar26 = (int)uVar23 + 1;
      uVar23 = (ulonglong)uVar26;
    } while ((int)uVar26 < DAT_1407c77a4);
  }
  uVar35 = _DAT_140e445c8;
  if (((DAT_140e418c8 == DAT_140e45d74 + 1U) && (DAT_140e41928 == 1)) &&
     ((DAT_1407c7798 != 10 && (DAT_140e41b00 == 0)))) {
    uVar34 = CONCAT44(DAT_140e445c4,DAT_140e445c0);
    uVar2 = CONCAT44(DAT_140e445d4,DAT_140e445d0);
    uVar3 = CONCAT44(DAT_140e445dc,DAT_140e445d8);
    lVar16 = (longlong)(int)(DAT_1407c7798 - 1);
    lVar22 = lVar16 * 0xf0;
    (&DAT_140e45318)[lVar16 * 0x3c] = DAT_140e45284;
    *(undefined8 *)(&DAT_140e45320 + lVar22) = uVar34;
    *(undefined8 *)(lVar22 + 0x140e45328) = uVar35;
    uVar9 = _DAT_140e445e8;
    uVar34 = _DAT_140e445e0;
    *(undefined8 *)(&DAT_140e45330 + lVar22) = uVar2;
    (&DAT_140e45338)[lVar16 * 0x1e] = uVar3;
    uVar2 = DAT_140e445f0;
    uVar35 = CONCAT44(DAT_140e445fc,DAT_140e445f8);
    (&DAT_140e45340)[lVar16 * 0x1e] = uVar34;
    *(undefined8 *)(&DAT_140e45348 + lVar16 * 0x78) = uVar9;
    uVar3 = _DAT_140e44608;
    uVar34 = _DAT_140e44600;
    (&DAT_140e45350)[lVar16 * 0x1e] = uVar2;
    *(undefined8 *)(&DAT_140e45358 + lVar16 * 0x3c) = uVar35;
    uVar2 = _DAT_140e44618;
    uVar35 = _DAT_140e44610;
    *(undefined8 *)(&DAT_140e45360 + lVar22) = uVar34;
    *(undefined8 *)(&DAT_140e45368 + lVar16 * 0x3c) = uVar3;
    uVar3 = _DAT_140e44628;
    uVar34 = _DAT_140e44620;
    *(undefined8 *)(&DAT_140e45370 + lVar16 * 0x3c) = uVar35;
    *(undefined8 *)(&DAT_140e45378 + lVar16 * 0x3c) = uVar2;
    uVar9 = uRam0000000140e44638;
    uVar2 = _DAT_140e44630;
    *(undefined8 *)(&DAT_140e45380 + lVar16 * 0x3c) = uVar34;
    *(undefined8 *)(&DAT_140e45388 + lVar16 * 0x3c) = uVar3;
    uVar34 = _DAT_140e44648;
    uVar35 = CONCAT44(DAT_140e44644,DAT_140e44640);
    *(undefined8 *)((longlong)&DAT_140e4538c + lVar22 + 4) = uVar2;
    *(undefined8 *)((longlong)&DAT_140e45394 + lVar22 + 4) = uVar9;
    auVar4._4_4_ = DAT_140e44654;
    auVar4._0_4_ = DAT_140e44650;
    auVar4._8_8_ = _DAT_140e44658;
    (&DAT_140e453c0)[lVar16 * 0x3c] = DAT_140e46808;
    (&DAT_140e453c4)[lVar16 * 0x3c] = DAT_140e45d34;
    (&DAT_140e453c8)[lVar16 * 0x3c] = DAT_140e45d88;
    (&DAT_140e453cc)[lVar16 * 0x3c] = DAT_140e45d18;
    (&DAT_140e453d0)[lVar16 * 0x3c] = DAT_140e45d20;
    (&DAT_140e453d8)[lVar16 * 0x1e] = DAT_140e44590;
    (&DAT_140e453e0)[lVar16 * 0x1e] = DAT_1407c77a8;
    (&DAT_140e453e8)[lVar16 * 0x3c] = DAT_140e451b0;
    (&DAT_140e453ec)[lVar16 * 0x3c] = DAT_1407c779c;
    (&DAT_140e453f0)[lVar16 * 0x3c] = DAT_140e46b24;
    (&DAT_140e453f4)[lVar16 * 0x3c] = DAT_140e477e4;
    (&DAT_140e453f8)[lVar16 * 0x3c] = DAT_140e46bbc;
    (&DAT_140e453fc)[lVar16 * 0x3c] = DAT_140e44e68;
    iVar12 = DAT_140e45268;
    *(undefined8 *)(&DAT_140e453a0 + lVar16 * 0x3c) = uVar35;
    (&DAT_140e453a8)[lVar16 * 0x1e] = uVar34;
    (&DAT_140e45400)[lVar16 * 0x3c] = iVar12;
    *(undefined1 (*) [16])(&DAT_140e453b0 + lVar16 * 0x3c) = auVar4;
  }
  if (DAT_140e445d4 == 1) {
    player_update_input_movement_candidate();
  }
  FUN_140109780();
  FUN_140078b70();
  FUN_1400ca7b0();
  FUN_140070e40();
  uVar36 = DAT_140e451a0;
  for (piVar17 = DAT_140e45260; DAT_140e451a0 = uVar36, piVar17 != (int *)0x0;
      piVar17 = *(int **)(piVar17 + 0x12)) {
    switch(piVar17[3]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 0xb:
    case 0xd:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x16:
      FUN_14006c620(piVar17);
      break;
    case 8:
      FUN_14006faa0(piVar17);
      break;
    case 0xc:
    case 0xe:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x2c:
    case 0x2d:
    case 0x35:
    case 0x36:
      FUN_14006ecf0(piVar17);
      break;
    case 0x13:
    case 0x15:
      if (piVar17[1] == 0) {
        piVar17[0xf] = 1;
        piVar17[0x10] = 0;
      }
      else {
        bVar28 = piVar17[1] == 1;
LAB_1400bdfad:
        if (bVar28) goto switchD_1400bdf4d_default;
      }
      break;
    case 0x14:
      if (piVar17[1] != 0) {
        bVar28 = piVar17[1] == 3;
        goto LAB_1400bdfad;
      }
      piVar17[0xf] = 1;
      piVar17[0x10] = 0;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x21:
    case 0x22:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3c:
      FUN_14006ce40(piVar17);
      break;
    case 0x1f:
    case 0x20:
      FUN_14006fcd0(piVar17);
      break;
    case 0x3a:
    case 0x3b:
      FUN_14006ffc0(piVar17);
      break;
    default:
switchD_1400bdf4d_default:
      *piVar17 = 0;
    }
    piVar17[1] = piVar17[1] + 1;
    uVar36 = DAT_140e451a0;
  }
  if (0x3b < (int)DAT_140e418c8) {
    if (DAT_140e451a4 == 0) {
      if (DAT_140e418c8 != ((int)DAT_140e418c8 / 0x3c) * 0x3c) goto LAB_1400be029;
    }
    else if ((DAT_140e451a4 != 1) || (DAT_140e451b0 != ((int)DAT_140e451b0 / 0x3c) * 0x3c))
    goto LAB_1400be029;
    DAT_140e451a0 = 0;
    DAT_140e451b8 = uVar36;
  }
LAB_1400be029:
  FUN_1400cd750();
  piVar17 = DAT_140e9fd38;
  if (DAT_140e46ea0 != (int *)0x0) {
    iVar12 = *DAT_140e46ea0;
    piVar17 = DAT_140e46ea0;
    while (iVar12 == 0) {
      DAT_140e46ea0 = *(int **)(piVar17 + 0xe);
      FUN_140323ce8(piVar17);
      DAT_140e4764c = DAT_140e4764c + -1;
      if (DAT_140e46ea0 == (int *)0x0) {
        DAT_140e9fd38 = (int *)0x0;
        piVar17 = DAT_140e9fd38;
        goto LAB_1400be0a9;
      }
      piVar17 = DAT_140e46ea0;
      iVar12 = *DAT_140e46ea0;
    }
    lVar16 = *(longlong *)(piVar17 + 0xe);
    DAT_140e46ea0 = piVar17;
    while (lVar16 != 0) {
      piVar25 = *(int **)(piVar17 + 0xe);
      if (*piVar25 == 0) {
        *(undefined8 *)(piVar17 + 0xe) = *(undefined8 *)(piVar25 + 0xe);
        FUN_140323ce8();
        DAT_140e4764c = DAT_140e4764c + -1;
        piVar25 = piVar17;
      }
      piVar17 = piVar25;
      lVar16 = *(longlong *)(piVar25 + 0xe);
    }
  }
LAB_1400be0a9:
  DAT_140e9fd38 = piVar17;
  piVar17 = DAT_140e46e98;
  if (DAT_140e46e90 != (int *)0x0) {
    iVar12 = *DAT_140e46e90;
    piVar17 = DAT_140e46e90;
    while (iVar12 == 0) {
      DAT_140e46e90 = *(int **)(piVar17 + 10);
      FUN_140323ce8(piVar17);
      DAT_140e46c5c = DAT_140e46c5c + -1;
      if (DAT_140e46e90 == (int *)0x0) {
        DAT_140e46e98 = (int *)0x0;
        piVar17 = DAT_140e46e98;
        goto LAB_1400be129;
      }
      piVar17 = DAT_140e46e90;
      iVar12 = *DAT_140e46e90;
    }
    lVar16 = *(longlong *)(piVar17 + 10);
    DAT_140e46e90 = piVar17;
    while (lVar16 != 0) {
      piVar25 = *(int **)(piVar17 + 10);
      if (*piVar25 == 0) {
        *(undefined8 *)(piVar17 + 10) = *(undefined8 *)(piVar25 + 10);
        FUN_140323ce8();
        DAT_140e46c5c = DAT_140e46c5c + -1;
        piVar25 = piVar17;
      }
      piVar17 = piVar25;
      lVar16 = *(longlong *)(piVar25 + 10);
    }
  }
LAB_1400be129:
  DAT_140e46e98 = piVar17;
  piVar17 = DAT_140e45d90;
  if (DAT_140e45d80 != (int *)0x0) {
    iVar12 = *DAT_140e45d80;
    piVar17 = DAT_140e45d80;
    while (iVar12 == 0) {
      DAT_140e45d80 = *(int **)(piVar17 + 0x18);
      FUN_140323ce8(piVar17);
      DAT_140e44e6c = DAT_140e44e6c + -1;
      if (DAT_140e45d80 == (int *)0x0) {
        DAT_140e45d90 = (int *)0x0;
        piVar17 = DAT_140e45d90;
        goto LAB_1400be1a9;
      }
      piVar17 = DAT_140e45d80;
      iVar12 = *DAT_140e45d80;
    }
    lVar16 = *(longlong *)(piVar17 + 0x18);
    DAT_140e45d80 = piVar17;
    while (lVar16 != 0) {
      piVar25 = *(int **)(piVar17 + 0x18);
      if (*piVar25 == 0) {
        *(undefined8 *)(piVar17 + 0x18) = *(undefined8 *)(piVar25 + 0x18);
        FUN_140323ce8();
        DAT_140e44e6c = DAT_140e44e6c + -1;
        piVar25 = piVar17;
      }
      piVar17 = piVar25;
      lVar16 = *(longlong *)(piVar25 + 0x18);
    }
  }
LAB_1400be1a9:
  DAT_140e45d90 = piVar17;
  piVar17 = DAT_140e451a8;
  if (DAT_140e45260 != (int *)0x0) {
    iVar12 = *DAT_140e45260;
    piVar17 = DAT_140e45260;
    while (iVar12 == 0) {
      DAT_140e45260 = *(int **)(piVar17 + 0x12);
      FUN_140323ce8(piVar17);
      DAT_140e451b4 = DAT_140e451b4 + -1;
      if (DAT_140e45260 == (int *)0x0) {
        DAT_140e451a8 = (int *)0x0;
        piVar17 = DAT_140e451a8;
        goto LAB_1400be229;
      }
      piVar17 = DAT_140e45260;
      iVar12 = *DAT_140e45260;
    }
    lVar16 = *(longlong *)(piVar17 + 0x12);
    DAT_140e45260 = piVar17;
    while (lVar16 != 0) {
      piVar25 = *(int **)(piVar17 + 0x12);
      if (*piVar25 == 0) {
        *(undefined8 *)(piVar17 + 0x12) = *(undefined8 *)(piVar25 + 0x12);
        FUN_140323ce8();
        DAT_140e451b4 = DAT_140e451b4 + -1;
        piVar25 = piVar17;
      }
      piVar17 = piVar25;
      lVar16 = *(longlong *)(piVar25 + 0x12);
    }
  }
LAB_1400be229:
  DAT_140e451a8 = piVar17;
  FUN_1400714d0();
  cVar10 = FUN_1400cbd30();
  if (((cVar10 == '\x01') && (DAT_140e44654 == 0)) && (DAT_140e4690c == 0)) {
    DAT_140e445fc = 0x118;
    DAT_140e44654 = 300;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47220);
    FUN_14018a340(DAT_140e47220,1,1);
  }
  if (((DAT_140e4690c == 1) && (DAT_140e44654 == 0)) && (cVar10 = FUN_1400cbd30(), cVar10 == '\x01')
     ) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47220);
    FUN_14018a340(DAT_140e47220,1,1);
    DAT_140e46b24 = DAT_140e46b24 + 1;
  }
  if ((*(ulonglong *)
        (&DAT_140538b10 + ((longlong)(int)DAT_140e419b8 * 5 + (longlong)DAT_140e46808) * 8) <=
       DAT_140e44590) && (DAT_140e46808 < 5)) {
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47228);
    FUN_14018a340(DAT_140e47228,1,1);
    uVar36 = DAT_140e46b7c;
    fVar6 = DAT_140e445d8;
    fVar33 = DAT_140e445dc - DAT_14053ad40;
    uVar26 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar26 >> 0x1e ^ uVar26) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar26 = uVar26 * 0x800 ^ uVar26;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar26) >> 8 ^ DAT_140e9fd18 ^ uVar26;
    uVar23 = (ulonglong)DAT_140e9fd1c;
    sVar24 = (short)DAT_140e9fd1c;
    iVar12 = DAT_140e45d1c;
    puVar19 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar19 = (undefined8 *)_malloc_base(0x60);
      if (puVar19 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar12 = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar19 + 0xc) = uVar36;
      bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar19 + 0x14) = fVar6;
      *(float *)(puVar19 + 3) = fVar33;
      *(float *)((longlong)puVar19 + 0x1c) = fVar6;
      *(float *)(puVar19 + 4) = fVar33;
      *puVar19 = 1;
      *(undefined4 *)(puVar19 + 1) = 0x17;
      *(undefined4 *)(puVar19 + 2) = 0x4b;
      *(short *)((longlong)puVar19 + 0x24) = sVar24 + (short)(uVar23 / 0x2ee1) * -0x2ee1 + -0x5770;
      puVar19[5] = 0x3ff0000000000000;
      puVar19[6] = 0x3ff0000000000000;
      puVar19[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar19 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
      *(undefined4 *)(puVar19 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
      puVar19[10] = 0x80;
      puVar19[0xb] = 0;
      if (bVar28) {
        DAT_140e45d78 = puVar19;
      }
      DAT_140e45d1c = iVar12;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar19;
      }
    }
    DAT_140e45d28 = puVar19;
    uVar36 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar19 = DAT_140e45d28;
    if (iVar12 < 0x1000) {
      puVar19 = (undefined8 *)_malloc_base(0x60);
      if (puVar19 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar19 = 1;
      *(undefined4 *)(puVar19 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar19 + 0xc) = uVar36;
      puVar19[2] = 0x6f;
      puVar19[3] = 0;
      *(undefined4 *)(puVar19 + 4) = 0;
      *(undefined2 *)((longlong)puVar19 + 0x24) = 0;
      puVar19[5] = 0;
      puVar19[6] = 0x3ff0000000000000;
      puVar19[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar19 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar19 + 0x44) = 0xff;
      *(undefined4 *)(puVar19 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar19 + 0x4c) = 0xff;
      puVar19[10] = 0xff;
      puVar19[0xb] = 0;
      if (bVar28) {
        DAT_140e45d78 = puVar19;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar19;
      }
    }
    DAT_140e45d28 = puVar19;
    if (DAT_140e445f8 < 9) {
      DAT_140e445f8 = DAT_140e445f8 + 1;
    }
    DAT_140e46808 = DAT_140e46808 + 1;
  }
  if ((((DAT_140e467e0 == 1) && (DAT_140e41a38 == 0)) && (DAT_140e445d4 == 1)) &&
     (DAT_140e45270 != 0x2a)) {
    DAT_140e46a20 = 1;
    do {
      FUN_14018f230(*puVar27,0);
      puVar27 = puVar27 + 1;
    } while ((longlong)puVar27 < 0x140e45178);
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
    FUN_14018a340(DAT_140e4721c,1,1);
    DAT_140e45274 = 0;
    DAT_140e46014 = 0;
    DAT_140e45fac = 0;
    DAT_140e467fc = 1;
    if (DAT_140e45270 == 0x15) {
      DAT_140e45270 = 0x16;
    }
    else {
      DAT_140e45270 = 0x26;
      if (DAT_140e41b00 == 0) {
        DAT_140e45270 = 0x17;
      }
    }
  }
  DAT_140e45d30 = DAT_14053ae28 - DAT_140e445d8 / DAT_14053ab70;
  if (DAT_140e41afc == 1) {
    FUN_1400c6e10();
    DAT_140e41afc = 0;
  }
  DAT_140e418c8 = DAT_140e418c8 + 1;
  DAT_140e44acc = DAT_140e44acc + 1;
  return;
}


