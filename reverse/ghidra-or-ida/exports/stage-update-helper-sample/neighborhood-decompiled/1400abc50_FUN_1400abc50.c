// Function: FUN_1400abc50 @ 1400abc50
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400abc50(undefined4 *param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined8 uVar9;
  ushort uVar10;
  ushort uVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  float fVar19;
  undefined4 local_res8;
  undefined4 uStackX_c;
  ulonglong in_stack_ffffffffffffff08;
  undefined4 uVar21;
  undefined8 uVar20;
  undefined4 uVar22;
  undefined4 in_stack_ffffffffffffff10;
  ushort uVar26;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined2 uVar27;
  undefined8 in_stack_ffffffffffffff18;
  undefined8 in_stack_ffffffffffffff20;
  double dVar28;
  undefined8 uVar29;
  
  uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  uVar24 = (undefined4)((ulonglong)in_stack_ffffffffffffff20 >> 0x20);
  uVar26 = (ushort)((uint)in_stack_ffffffffffffff10 >> 0x10);
  pfVar1 = (float *)(param_1 + 10);
  fVar19 = *pfVar1;
  dVar13 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xc] - fVar19));
  uVar22 = DAT_14053b378;
  dVar15 = DAT_14053aba0;
  dVar14 = DAT_140539e98;
  uVar21 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
  dVar13 = dVar13 * DAT_14053aba0;
  uVar11 = (ushort)(int)dVar13;
  if (param_1[5] == 0) {
    uVar6 = FUN_1401346a0(*(undefined8 *)pfVar1,0xffffffce);
    fVar16 = DAT_14053b380;
    local_res8 = (undefined4)uVar6;
    uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
    dVar18 = DAT_14053a018 - (double)(int)param_1[3] * dVar14;
    if (param_1[3] == 0) {
      fVar17 = DAT_14053af54;
      if (fVar19 < DAT_14053ae30) {
        fVar17 = DAT_14053b380;
      }
      *pfVar1 = fVar17;
      param_1[0xb] = fVar16;
      uVar6 = FUN_1401346a0(*(undefined8 *)pfVar1);
      local_res8 = (undefined4)uVar6;
      uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
    }
    uVar5 = (uint)uVar26 << 0x10;
    in_stack_ffffffffffffff08 = CONCAT44(uVar21,uStackX_c);
    dVar28 = dVar18;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,in_stack_ffffffffffffff08,uVar5,dVar18,dVar18,0xff
                  ,0xff,0xff,0xff,1,0);
    uVar21 = DAT_14053b34c;
    uVar23 = (undefined4)((ulonglong)dVar18 >> 0x20);
    uVar24 = (undefined4)((ulonglong)dVar28 >> 0x20);
    uVar27 = (undefined2)(uVar5 >> 0x10);
    if (param_1[3] == 0x14) {
      if (param_1[6] - 0x9b < 2) {
        uVar9 = CONCAT44(uVar24,0x14);
        uVar5 = uVar5 & 0xffff0000;
        uVar6 = CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),DAT_14053b34c);
        stage_entity_spawn_candidate(0x9d,99999999,1,DAT_14053acfc,uVar6,uVar5,0,uVar9,1,param_1[1])
        ;
        uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        uVar5 = uVar5 & 0xffff0000;
        in_stack_ffffffffffffff08 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),uVar21);
        stage_entity_spawn_candidate
                  (0x9d,99999999,1,DAT_14053b370,in_stack_ffffffffffffff08,uVar5,0,uVar9,1,
                   param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        uVar5 = uVar5 & 0xffff0000;
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0x9d,99999999,1,DAT_14053ad80,in_stack_ffffffffffffff08,uVar5,0,uVar6,1,
                   param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),0x14);
        uVar23 = 0;
        uVar5 = uVar5 & 0xffff0000;
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0x9d,99999999,1,DAT_14053b3b0,in_stack_ffffffffffffff08,uVar5,0,uVar6,1,
                   param_1[1]);
        uVar24 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar27 = (undefined2)(uVar5 >> 0x10);
        *(undefined8 *)(param_1 + 0x12) = 0x4026cccccccccccd;
      }
      uVar25 = DAT_14053b358;
      if ((param_1[6] == 0x9e) || (param_1[6] == 0x9f)) {
        uVar9 = CONCAT44(uVar24,0x14);
        uVar23 = CONCAT22(uVar27,200);
        uVar6 = CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),DAT_14053b358);
        stage_entity_spawn_candidate
                  (0xa0,99999999,1,DAT_14053acc8,uVar6,uVar23,0,uVar9,1,param_1[1]);
        uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        uVar23 = CONCAT22((short)((uint)uVar23 >> 0x10),0xff38);
        in_stack_ffffffffffffff08 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),uVar25);
        stage_entity_spawn_candidate
                  (0xa0,99999999,1,DAT_14053b35c,in_stack_ffffffffffffff08,uVar23,0,uVar9,1,
                   param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        uVar24 = CONCAT22((short)((uint)uVar23 >> 0x10),500);
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0xa0,99999999,1,DAT_14053ad1c,in_stack_ffffffffffffff08,uVar24,0,uVar6,1,
                   param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),0x14);
        uVar23 = 0;
        uVar25 = CONCAT22((short)((uint)uVar24 >> 0x10),0xfe0c);
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0xa0,99999999,1,fVar16,in_stack_ffffffffffffff08,uVar25,0,uVar6,1,param_1[1]);
        uVar24 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar27 = (undefined2)((uint)uVar25 >> 0x10);
        *(undefined8 *)(param_1 + 0x12) = 0x4028666666666666;
      }
      if (param_1[6] - 0xa1 < 2) {
        uVar9 = CONCAT44(uVar24,0x14);
        uVar6 = CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),uVar21);
        stage_entity_spawn_candidate
                  (0xa3,99999999,1,DAT_14053ad10,uVar6,CONCAT22(uVar27,0xfda8),0,uVar9,1,param_1[1])
        ;
        uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        in_stack_ffffffffffffff08 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),uVar21);
        stage_entity_spawn_candidate
                  (0xa3,99999999,1,uVar22,in_stack_ffffffffffffff08,600,0,uVar9,1,param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x14);
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0xa3,99999999,1,DAT_14053ad9c,in_stack_ffffffffffffff08,0xfb50,0,uVar6,1,
                   param_1[1]);
        uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),0x14);
        uVar23 = 0;
        in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffff00000000;
        stage_entity_spawn_candidate
                  (0xa3,99999999,1,DAT_14053b3bc,in_stack_ffffffffffffff08,0x4b0,0,uVar6,1,
                   param_1[1]);
        uVar24 = (undefined4)((ulonglong)uVar6 >> 0x20);
        *(undefined8 *)(param_1 + 0x12) = 0x402799999999999a;
      }
      if ((param_1[6] - 0x9c < 7) && ((0x49U >> (param_1[6] - 0x9c & 0x1f) & 1) != 0)) {
        DAT_140e45da4 = 1;
      }
      param_1[5] = param_1[5] + 1;
      uVar22 = DAT_140e472bc;
      *(ushort *)(param_1 + 0x10) = uVar11;
      param_1[0x15] = 0;
      param_1[3] = 0;
      FUN_140184700(DAT_140e44190 * 0x19,uVar22);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
  }
  if (param_1[5] != 1) goto LAB_1400acae1;
  uVar5 = param_1[3];
  if ((int)uVar5 < 0x118) {
    if ((0x3b < (int)uVar5) && (uVar5 - 0x3c == ((int)(uVar5 - 0x3c) / 0x32) * 0x32)) {
      uVar3 = uVar5 * param_1[1] * 0x378;
      uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      param_1[0xc] = (float)(DAT_140e9fd1c % 0x1e1 + 0x78);
      uVar3 = uVar5;
      if (uVar5 != uVar5 + 100) {
        uVar3 = uVar5 * param_1[1] * 0x22b8;
        uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar3 = uVar3 * 0x800 ^ uVar3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
        uVar3 = DAT_140e9fd1c % 0x65 + uVar5;
      }
      param_1[0xd] = (float)(int)uVar3;
    }
    iVar8 = param_1[6];
    if ((iVar8 == 0x9b) || (iVar8 == 0x9c)) {
      dVar18 = *(double *)(param_1 + 0x12);
      if ((uVar5 < 0x3d) && (DAT_140539fe8 < dVar18)) {
        dVar18 = dVar18 - dVar14;
      }
      uVar5 = param_1[3];
      *(double *)(param_1 + 0x12) = dVar18;
    }
    else {
      dVar18 = *(double *)(param_1 + 0x12);
    }
    if ((iVar8 == 0x9e) || (iVar8 == 0x9f)) {
      if ((uVar5 < 0x3d) && (DAT_14053a030 < dVar18)) {
        dVar18 = dVar18 - dVar14;
      }
      *(double *)(param_1 + 0x12) = dVar18;
    }
    if ((param_1[6] == 0xa1) || (param_1[6] == 0xa2)) {
      if ((uVar5 < 0x3d) && (DAT_14053a010 < dVar18)) {
        dVar18 = dVar18 - dVar14;
      }
      *(double *)(param_1 + 0x12) = dVar18;
    }
  }
  else {
    dVar18 = *(double *)(param_1 + 0x12) + DAT_140539e60;
    param_1[0xd] = 0xc3fa0000;
    *(double *)(param_1 + 0x12) = dVar18;
  }
  uVar26 = *(ushort *)(param_1 + 0x10);
  dVar14 = (double)FUN_1403307c0();
  fVar19 = (float)(dVar14 * dVar18) + (float)param_1[10];
  param_1[10] = fVar19;
  dVar14 = (double)FUN_140332d90();
  uVar22 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
  iVar4 = ((int)dVar13 & 0xffffU) - (uint)uVar26;
  iVar8 = iVar4 + 0x10000;
  if (-0x8001 < iVar4) {
    iVar8 = iVar4;
  }
  fVar16 = (float)(dVar14 * dVar18) + (float)param_1[0xb];
  iVar4 = iVar8 + -0x10000;
  if (iVar8 < 0x8001) {
    iVar4 = iVar8;
  }
  param_1[0xb] = fVar16;
  uVar6 = _UNK_14053bb28;
  dVar14 = _DAT_14053bb20;
  if (iVar4 < 1) {
    uVar10 = uVar26;
    if ((iVar4 < 0) && (uVar10 = uVar11, iVar4 < -0x27f)) {
      uVar10 = uVar26 - 0x280;
    }
  }
  else {
    uVar10 = uVar11;
    if (0x27f < iVar4) {
      uVar10 = uVar26 + 0x280;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  if (0x3b < (int)param_1[3]) {
    uVar9 = 7;
    iVar8 = 1;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x5a;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x4b;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x32;
    }
    iVar4 = 1;
    if (DAT_140e419b8 == 0) {
      iVar4 = 0x19;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      iVar4 = 0x28;
    }
    dVar13 = DAT_14053a138;
    if (((DAT_140e419b8 != 0) && (dVar13 = DAT_14053a178, DAT_140e419b8 != 1)) &&
       ((dVar13 = DAT_14053a1b8, DAT_140e419b8 != 2 &&
        ((dVar13 = DAT_14053a190, DAT_140e419b8 != 3 && (dVar13 = dVar14, DAT_140e419b8 == 4)))))) {
      dVar13 = DAT_14053a1c8;
    }
    uVar5 = param_1[3];
    iVar2 = param_1[6];
    dVar13 = (double)((int)(uVar5 - 0x3c) % iVar8) * DAT_140539e50 + dVar13;
    if (iVar2 == 0x9e) {
      fVar16 = (float)param_1[0xb];
LAB_1400ac6a9:
      uVar9 = 9;
      fVar17 = fVar16;
    }
    else {
      fVar17 = fVar16 + DAT_14053ac34;
      if (iVar2 == 0x9f) {
        fVar19 = (float)param_1[10];
        goto LAB_1400ac6a9;
      }
    }
    if ((iVar2 == 0xa1) || (iVar2 == 0xa2)) {
      fVar17 = fVar16 + DAT_14053ac48;
    }
    if ((uVar5 < 0x118) && ((int)(uVar5 - 0x3c) % iVar8 == 0)) {
      dVar18 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar16),
                                     (double)(DAT_140e445d8 - fVar19));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar18 * dVar15);
    }
    uVar21 = DAT_14053ac2c;
    uVar22 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);
    iVar2 = param_1[3];
    if (((iVar2 - 0x3cU < 0xdc) && ((iVar2 + -0x3c) % iVar8 < iVar4)) &&
       (iVar8 = (iVar2 + -0x3c) % iVar8, iVar8 == (iVar8 / 5) * 5)) {
      uVar29 = CONCAT44(uVar24,1);
      uVar20 = CONCAT62((int6)(in_stack_ffffffffffffff08 >> 0x10),
                        *(undefined2 *)((longlong)param_1 + 0x42));
      dVar15 = dVar13;
      FUN_14006c2f0(uVar9,0,fVar19,fVar17,uVar20,DAT_14053ac2c,dVar13,uVar29,0);
      uVar22 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar23 = (undefined4)((ulonglong)dVar15 >> 0x20);
      uVar24 = (undefined4)((ulonglong)uVar29 >> 0x20);
      if (2 < DAT_140e419b8) {
        dVar13 = dVar13 + DAT_140539fc8;
        uVar29 = CONCAT44(uVar24,1);
        uVar20 = CONCAT62((int6)((ulonglong)uVar20 >> 0x10),
                          *(undefined2 *)((longlong)param_1 + 0x42));
        FUN_14006c2f0(uVar9,0,fVar19,fVar17,uVar20,uVar21,dVar13,uVar29,0);
        uVar22 = (undefined4)((ulonglong)uVar20 >> 0x20);
        uVar23 = (undefined4)((ulonglong)dVar13 >> 0x20);
        uVar24 = (undefined4)((ulonglong)uVar29 >> 0x20);
      }
    }
  }
  uVar29 = CONCAT44(uVar24,0x97);
  uVar20 = CONCAT44(uVar23,0x98);
  uVar5 = 0;
  uVar9 = CONCAT44(uVar22,0x96);
  iVar8 = FUN_1400c9580(param_1[3],0,5,4,uVar9,0x97,uVar20,uVar29);
  uVar22 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar23 = (undefined4)((ulonglong)uVar29 >> 0x20);
  if (param_1[6] - 0x9e < 2) {
    uVar29 = CONCAT44(uVar23,0x9a);
    uVar20 = CONCAT44(uVar21,0x9b);
    uVar5 = 0;
    uVar9 = CONCAT44(uVar22,0x99);
    iVar8 = FUN_1400c9580(param_1[3],0,5,4,uVar9,0x9a,uVar20,uVar29);
    uVar22 = (undefined4)((ulonglong)uVar9 >> 0x20);
    uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar23 = (undefined4)((ulonglong)uVar29 >> 0x20);
  }
  if (param_1[6] - 0xa1 < 2) {
    uVar5 = 0;
    uVar9 = CONCAT44(uVar22,0x9c);
    iVar8 = FUN_1400c9580(param_1[3],0,5,4,uVar9,0x9d,CONCAT44(uVar21,0x9e),CONCAT44(uVar23,0x9d));
    uVar22 = (undefined4)((ulonglong)uVar9 >> 0x20);
  }
  uVar5 = uVar5 & 0xffff0000;
  uVar9 = CONCAT44(uVar22,param_1[0xb]);
  FUN_1400c8410((&DAT_140e44ad0)[iVar8],0x22,7,param_1[10],uVar9,uVar5,dVar14,uVar6,0xff,0xff,0xff,
                0xff,1,0);
  uVar22 = (undefined4)((ulonglong)uVar9 >> 0x20);
  if ((param_1[6] - 0x9c < 7) && ((0x49U >> (param_1[6] - 0x9c & 0x1f) & 1) != 0)) {
    dVar15 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                   DAT_140539d28);
    FUN_1400c8410((&DAT_140e44ad0)[iVar8],0x22,8,param_1[10],CONCAT44(uVar22,param_1[0xb]),
                  uVar5 & 0xffff0000,dVar14,uVar6,0xff,0xff,0xff,
                  0x80 - (int)(dVar15 * DAT_14053b1c8),1,0);
  }
  uVar5 = param_1[3] & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  puVar7 = DAT_140e45d28;
  if (uVar5 == 0) {
    uVar22 = param_1[0xb];
    uVar21 = param_1[10];
    uVar23 = (&DAT_140e44ad0)[iVar8];
    if (DAT_140e45d1c < 0x1000) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar7 + 0x14) = uVar21;
      *(undefined4 *)(puVar7 + 3) = uVar22;
      *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar21;
      *(undefined4 *)(puVar7 + 4) = uVar22;
      *puVar7 = 1;
      *(undefined4 *)(puVar7 + 1) = 5;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar23;
      *(undefined4 *)(puVar7 + 2) = 0x21;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0;
      puVar7[6] = 0x3ff0000000000000;
      puVar7[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar7 + 8) = 0x18;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      puVar7[10] = 0x40;
      puVar7[0xb] = 0;
      if (bVar12) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
    }
  }
  DAT_140e45d28 = puVar7;
  FUN_140079c10(param_1,1);
  if (DAT_140e44600 != 0) {
    DAT_140e45da4 = 0;
  }
LAB_1400acae1:
  if ((int)param_1[7] < 1) {
    if (((DAT_140e44600 == 0) && (param_1[6] - 0x9c < 7)) &&
       ((0x49U >> (param_1[6] - 0x9c & 0x1f) & 1) != 0)) {
      uVar5 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      FUN_1400ca6d0(7,param_1[10],param_1[0xb],
                    CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                             (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x4001) * -0x4001 +
                             0x2000),DAT_14053a070,DAT_14053ac80);
      if (((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e44050 == 0)) {
        DAT_140e44050 = 1;
        FUN_1400b4350(1,0x1b);
        save_init_or_reset_candidate();
        DAT_140e45f68 = 0x3c;
      }
    }
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      (((float)param_1[0xb] < DAT_14053b398 || (_DAT_14053af5c < (float)param_1[0xb])))) &&
     (0xef < (int)param_1[3])) {
    *param_1 = 0;
  }
  return;
}


