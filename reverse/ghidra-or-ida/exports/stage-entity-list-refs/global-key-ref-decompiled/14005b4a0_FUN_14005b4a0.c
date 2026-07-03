// Function: FUN_14005b4a0 @ 14005b4a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005b4a0(undefined4 *param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  double dVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  short sVar17;
  undefined2 uVar18;
  bool bVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  double dVar30;
  float fVar31;
  float fVar32;
  int local_res8;
  uint local_res10;
  undefined4 in_stack_fffffffffffffe38;
  undefined2 uVar33;
  uint in_stack_fffffffffffffe40;
  undefined8 in_stack_fffffffffffffe50;
  undefined8 uVar34;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined1 local_f8 [184];
  
  uStack_148 = 0;
  uStack_148._4_4_ = 0;
  lVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        local_150 = *(undefined8 *)(lVar4 + 0x10);
        uStack_148 = *(undefined8 *)(lVar4 + 0x18);
        local_140 = *(undefined8 *)(lVar4 + 0x20);
      }
    }
  }
  fVar21 = (float)param_1[0xd];
  fVar20 = (float)param_1[0xc];
  fVar31 = (float)param_1[0xb];
  fVar32 = (float)param_1[10];
  FUN_1403300b4((double)(fVar21 - fVar31),SUB84((double)(fVar20 - fVar32),0));
  dVar22 = DAT_14053aba0;
  fVar20 = (float)FUN_140334430(fVar32 - fVar20,DAT_140539fc0);
  fVar21 = (float)FUN_140334430(fVar31 - fVar21);
  if (fVar20 + fVar21 < 0.0) {
    fVar21 = (float)FUN_1403352f8();
  }
  else {
    fVar21 = SQRT(fVar20 + fVar21);
  }
  puVar1 = param_1 + 3;
  puVar7 = (undefined8 *)FUN_140135060(local_f8,param_1[3],0x14);
  uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
  local_res8 = 0;
  uVar2 = *puVar7;
  uVar3 = *(undefined4 *)(puVar7 + 1);
  local_res10 = 0x54;
  if ((local_150._4_4_ == 0x28) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffe50 = CONCAT44(uVar28,param_1[0x14]);
    in_stack_fffffffffffffe38 = param_1[0xb];
    in_stack_fffffffffffffe40 = in_stack_fffffffffffffe40 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_fffffffffffffe38,in_stack_fffffffffffffe40,
               DAT_14053a4f0,in_stack_fffffffffffffe50,1,0);
    fVar31 = (float)param_1[0xb];
    fVar32 = (float)param_1[10];
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  uVar6 = _UNK_14053bb28;
  dVar5 = _DAT_14053bb20;
  dVar24 = DAT_14053a430;
  dVar26 = DAT_14053a020;
  dVar27 = DAT_140539d28;
  iVar9 = param_1[5];
  uVar28 = SUB84(DAT_14053a430,0);
  uVar29 = (undefined4)((ulonglong)DAT_14053a430 >> 0x20);
  param_1[0x15] = 1;
  iVar10 = DAT_140e45d1c;
  dVar25 = DAT_14053a798;
  dVar23 = DAT_14053a5f8;
  if (iVar9 == 0) {
    uVar16 = *puVar1;
    iVar9 = 0;
    if (0x95 < (int)uVar16) {
      iVar9 = 0xff;
    }
    if (((int)uVar16 < 0x96) || (0xb3 < (int)uVar16)) {
      iVar10 = ((int)uVar16 >> 0x1f & 0xffffff01U) + 0xff;
      if (-1 < (int)uVar16) {
        if (0x95 < (int)uVar16) goto LAB_14005c659;
        dVar27 = (double)FUN_140332d90(((double)(int)uVar16 - 0.0) * _DAT_14053a478 * dVar26 *
                                       dVar27);
        goto LAB_14005c688;
      }
    }
    else {
      dVar24 = (double)FUN_140332d90(((double)(int)uVar16 - DAT_14053a510) * DAT_14053a798 * dVar26
                                     * dVar27);
      iVar10 = ((int)uVar16 >> 0x1f & 0xffffff01U) + 0xff;
      iVar9 = (int)(dVar24 * dVar23);
LAB_14005c659:
      if (uVar16 < 0xb4) {
        dVar27 = (double)FUN_140332d90(((double)(int)uVar16 - DAT_14053a4a0) * dVar25 * dVar26 *
                                       dVar27);
LAB_14005c688:
        iVar10 = (int)(dVar27 * dVar23);
      }
    }
    local_res8 = 0;
    if ((int)uVar16 < 0xb4) {
      local_res8 = iVar10;
    }
    dVar27 = (double)FUN_1403300b4((double)(DAT_14053b380 - fVar31),
                                   SUB84((double)(DAT_14053ad40 - fVar32),0));
    uVar28 = SUB84(DAT_14053a430,0);
    uVar29 = (undefined4)((ulonglong)DAT_14053a430 >> 0x20);
    uVar11 = 0x54;
    *(short *)(param_1 + 0x10) = (short)(int)(dVar27 * dVar22) + -0x8000;
    if (uVar16 == 0xbe) {
      param_1[5] = param_1[5] + 1;
      param_1[8] = (undefined4)local_140;
      *(undefined8 *)(param_1 + 0x12) = 0x403e000000000000;
      param_1[3] = 0;
      param_1[7] = uStack_148._4_4_;
    }
  }
  else {
    if (iVar9 == 1) {
      dVar24 = *(double *)(param_1 + 0x12);
      dVar23 = (double)FUN_1403307c0();
      fVar32 = (float)(dVar23 * ((double)fVar21 / dVar24)) + fVar32;
      param_1[10] = fVar32;
      dVar23 = (double)FUN_140332d90();
      fVar20 = DAT_14053ad40 - fVar32;
      fVar31 = (float)(dVar23 * ((double)fVar21 / dVar24)) + fVar31;
      fVar21 = DAT_14053b380 - fVar31;
      param_1[0xb] = fVar31;
      dVar24 = (double)FUN_1403300b4((double)fVar21,SUB84((double)fVar20,0));
      *(short *)(param_1 + 0x10) = (short)(int)(dVar24 * dVar22) + -0x8000;
      dVar24 = (double)FUN_1403307c0();
      fVar32 = (float)(dVar24 * _DAT_14053a4f8) + fVar32;
      dVar24 = (double)FUN_140332d90();
      fVar31 = (float)(dVar24 * _DAT_14053a4f8) + fVar31;
      dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar31),
                                     SUB84((double)(DAT_140e445d8 - fVar32),0));
      dVar23 = DAT_14053a0b0;
      uVar12 = (int)*puVar1 % 0x44c;
      uVar16 = uVar12 - 0x5a;
      dVar30 = (double)(int)uVar16 * DAT_140539d90;
      dVar24 = (double)(int)uVar16 * _DAT_140539dd0 + DAT_14053a018;
      sVar17 = (short)(int)(dVar25 * dVar22);
      if (uVar12 == 1) {
        param_1[0xc] = 0x44070000;
        param_1[0xd] = 0x43a50000;
        *(undefined8 *)(param_1 + 0x12) = 0x4024000000000000;
      }
      else {
        if (uVar12 == 0x28) {
          uVar15 = 0;
          param_1[0xc] = 0x42f00000;
          param_1[0xd] = 0x43700000;
          *(undefined8 *)(param_1 + 0x12) = 0x4034000000000000;
        }
        else {
          if (uVar12 == 0x6e) {
            param_1[0xc] = 0x43fa0000;
            param_1[0xd] = 0x433e0000;
          }
          else if (uVar12 == 0xb4) {
            param_1[0xc] = 0x43160000;
            param_1[0xd] = 0x43200000;
          }
          else {
            if (uVar12 != 0xfa) {
              if ((0x117 < uVar12 - 0x28) ||
                 (uVar15 = (int)(uVar12 - 0x28) % 0x46, 0x23 < (int)uVar15)) goto LAB_14005bcff;
              goto LAB_14005c11f;
            }
            param_1[0xc] = 0x43be0000;
            param_1[0xd] = 0x42700000;
          }
          uVar15 = uVar12 - 0x28;
        }
LAB_14005c11f:
        if ((uVar15 & 1) == 0) {
          uVar34 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe50 >> 0x20),1);
          dVar22 = (double)((int)(uVar12 - 0x28) % 0x46) * DAT_140539ee0;
          uVar28 = CONCAT22((short)((uint)in_stack_fffffffffffffe38 >> 0x10),sVar17);
          FUN_14006c2f0(0xd,4,fVar32,fVar31,uVar28,0,dVar22 + dVar23,uVar34,0);
          uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),1);
          uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),sVar17);
          FUN_14006c2f0(0xd,4,fVar32,fVar31,uVar28,0,dVar22 + DAT_14053a138,uVar34,0);
          uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),1);
          uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),sVar17);
          FUN_14006c2f0(0xd,4,fVar32,fVar31,uVar28,0,dVar22 + DAT_14053a1b8,uVar34,0);
          uVar34 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),1);
          uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),sVar17);
          FUN_14006c2f0(0xd,4,fVar32,fVar31,uVar28,0,dVar22 + DAT_14053a208,uVar34,0);
          in_stack_fffffffffffffe50 = CONCAT44((int)((ulonglong)uVar34 >> 0x20),1);
          in_stack_fffffffffffffe40 = 0;
          in_stack_fffffffffffffe38 = CONCAT22((short)((uint)uVar28 >> 0x10),sVar17);
          FUN_14006c2f0(0xd,4,fVar32,fVar31,in_stack_fffffffffffffe38,0,dVar22 + DAT_14053a228,
                        in_stack_fffffffffffffe50,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
LAB_14005bcff:
      if ((uVar16 < 0xe6) && (uVar16 == ((int)uVar16 / 0x46) * 0x46)) {
        uVar16 = (*puVar1 >> 0x1e ^ *puVar1) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar16 = uVar16 * 0x800 ^ uVar16;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar16) >> 8 ^ uVar16 ^ DAT_140e9fd18;
        uVar16 = DAT_140e9fd1c / 0x10001;
        sVar13 = (short)DAT_140e9fd1c;
        iVar9 = 0;
        do {
          in_stack_fffffffffffffe50 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe50 >> 0x20),1);
          in_stack_fffffffffffffe38 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe38 >> 0x10),
                        (short)iVar9 * 0xa3d + (sVar13 - (short)uVar16));
          FUN_14006c2f0(10,0,fVar32,fVar31,in_stack_fffffffffffffe38,0,dVar24,
                        in_stack_fffffffffffffe50,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 0x19);
        iVar9 = 0;
        do {
          in_stack_fffffffffffffe50 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe50 >> 0x20),1);
          in_stack_fffffffffffffe40 = 0;
          in_stack_fffffffffffffe38 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe38 >> 0x10),
                        (short)iVar9 * 0xa3d + sVar17);
          FUN_14006c2f0(10,0,fVar32,fVar31,in_stack_fffffffffffffe38,0,dVar30 + dVar5 + dVar24,
                        in_stack_fffffffffffffe50,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 0x19);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      dVar22 = DAT_140539da0;
      uVar33 = (undefined2)((uint)in_stack_fffffffffffffe38 >> 0x10);
      uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
      dVar23 = (double)(int)(uVar12 - 0x15e) * DAT_140539da0 + dVar23;
      if (uVar12 == 0x15e) {
        *(undefined8 *)(param_1 + 0x12) = 0x4014000000000000;
LAB_14005bed2:
        uVar16 = uVar12 - 0x168;
        if ((uVar16 < 0xf0) && (uVar16 == ((int)uVar16 / 0x14) * 0x14)) goto LAB_14005befd;
      }
      else {
        uVar16 = uVar12 - 0x168;
        if ((0xef < uVar16) || (uVar16 != ((int)uVar16 / 0x14) * 0x14)) goto LAB_14005bed2;
        uVar15 = (*puVar1 >> 0x1e ^ *puVar1) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar16 = uVar15 * 0x800 ^ uVar15;
        uVar15 = uVar15 ^ uVar15 * 0x800;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar15 = (uVar15 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar15 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar15;
        param_1[0xc] = (float)(((uVar16 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar16 ^ DAT_140e9fd18) %
                               0x169 + 0xa0);
        param_1[0xd] = (float)(uVar15 % 0xdd + 0x50);
LAB_14005befd:
        iVar10 = 0;
        iVar9 = iVar10;
        do {
          in_stack_fffffffffffffe50 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe50 >> 0x20),1);
          in_stack_fffffffffffffe38 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe38 >> 0x10),
                        (short)iVar9 * 0x29a + sVar17 + -2000);
          FUN_14006c2f0(0xd,1,fVar32,fVar31,in_stack_fffffffffffffe38,0,dVar23,
                        in_stack_fffffffffffffe50,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 7);
        do {
          in_stack_fffffffffffffe50 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe50 >> 0x20),1);
          in_stack_fffffffffffffe40 = 0;
          in_stack_fffffffffffffe38 =
               CONCAT22((short)((uint)in_stack_fffffffffffffe38 >> 0x10),
                        (short)iVar10 * 0x29a + sVar17 + -2000);
          FUN_14006c2f0(0xd,1,fVar32,fVar31,in_stack_fffffffffffffe38,0,dVar23 + dVar5,
                        in_stack_fffffffffffffe50,0);
          uVar33 = (undefined2)((uint)in_stack_fffffffffffffe38 >> 0x10);
          uVar28 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
          iVar10 = iVar10 + 1;
        } while (iVar10 < 7);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
      dVar22 = (double)(int)(uVar12 - 0x280) * dVar22 + DAT_14053a048;
      if (uVar12 == 600) {
        *(undefined8 *)(param_1 + 0x12) = 0x4024000000000000;
LAB_14005c3e7:
        dVar27 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053a8b0 * dVar26 *
                                       dVar27);
        param_1[0xc] = (float)(dVar27 * DAT_14053a510) + DAT_14053ae1c;
        dVar27 = (double)FUN_140332d90();
        param_1[0xd] = (float)(dVar27 * DAT_14053a460) + DAT_14053ad5c;
        if (uVar12 - 0x280 < 0x1a4) {
          in_stack_fffffffffffffe40 = 0;
          FUN_14006c2f0(0xd,3,fVar32,fVar31,CONCAT22(uVar33,*(short *)(param_1 + 3) * 0x960),0,
                        dVar22,CONCAT44(uVar28,1),0);
          if ((uVar12 & 1) == 0) {
            in_stack_fffffffffffffe40 = 0;
            FUN_14006c2f0(0xc,3,fVar32,fVar31,*(short *)(param_1 + 3) * -1000,0,
                          dVar22 + DAT_140539f68,1,0);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      else if (599 < (int)uVar12) goto LAB_14005c3e7;
      iVar10 = DAT_140e44308;
      iVar9 = param_1[7];
      if ((iVar9 < uStack_148._4_4_) && (lVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
        for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
          if (*(int *)(lVar4 + 4) == iVar10) {
            *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) - (uStack_148._4_4_ - iVar9);
          }
        }
      }
      iVar9 = param_1[7];
      if (uStack_148._4_4_ < iVar9) {
        param_1[7] = uStack_148._4_4_;
        iVar9 = uStack_148._4_4_;
      }
      iVar10 = DAT_140e44308;
      if ((iVar9 < 1) && (lVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
        for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
          if (*(int *)(lVar4 + 4) == iVar10) {
            *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) - uStack_148._4_4_;
          }
        }
      }
      uVar28 = SUB84(DAT_14053a430,0);
      uVar29 = (undefined4)((ulonglong)DAT_14053a430 >> 0x20);
      param_1[0x15] = 0;
    }
    else if (iVar9 == 99) {
      uVar16 = *puVar1;
      local_res8 = 0;
      iVar9 = local_res8;
      iVar14 = local_res8;
      if ((int)uVar16 < 0x5a) {
LAB_14005b7b0:
        if ((int)uVar16 < 0x8c) {
          iVar14 = iVar9;
        }
        puVar7 = DAT_140e45d28;
        if ((uVar16 == 1) &&
           (*(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(param_1 + 10), puVar7 = DAT_140e45d28,
           iVar10 < 0x1000)) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)((longlong)puVar7 + 0x14) = fVar32;
          *(float *)(puVar7 + 3) = fVar31;
          *(float *)((longlong)puVar7 + 0x1c) = fVar32;
          *(float *)(puVar7 + 4) = fVar31;
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
          if (bVar19) {
            DAT_140e45d78 = puVar7;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar7;
          }
        }
      }
      else if ((int)uVar16 < 100) {
        dVar22 = (double)FUN_140332d90(((double)(int)uVar16 - dVar24) * DAT_14053a9d8 * dVar26 *
                                       dVar27);
        iVar14 = (int)(dVar22 * DAT_14053a5f8);
        puVar7 = DAT_140e45d28;
      }
      else {
        iVar9 = 0xff;
        if (0x8b < (int)uVar16) goto LAB_14005b7b0;
        dVar22 = (double)FUN_140332d90(((double)(int)uVar16 - DAT_14053a3a0) * DAT_14053a6d8 *
                                       dVar26 * dVar27);
        puVar7 = DAT_140e45d28;
        if ((int)uVar16 < 0x8c) {
          iVar14 = (int)(dVar22 * DAT_14053a5f8);
        }
      }
      DAT_140e45d28 = puVar7;
      uVar16 = *puVar1;
      if ((int)uVar16 < 0x5a) {
        FUN_14007ac00(param_1);
        uVar16 = *puVar1;
        dVar22 = (double)FUN_140332d90(((double)(int)uVar16 - 0.0) * _DAT_14053ab90 * dVar26 *
                                       dVar27);
        param_1[0xc] = (float)(dVar22 * DAT_14053a2a8) + (float)param_1[0xe];
        dVar22 = (double)FUN_140332d90();
        dVar27 = (double)fVar21 / DAT_14053a0b0;
        param_1[0xd] = (float)(dVar22 * DAT_14053a2a8) + (float)param_1[0xf] +
                       (float)(int)uVar16 * DAT_140539d20;
        dVar22 = (double)FUN_1403307c0();
        param_1[10] = (float)(dVar22 * dVar27) + (float)param_1[10];
        dVar22 = (double)FUN_140332d90();
        param_1[0xb] = (float)(dVar22 * dVar27) + (float)param_1[0xb];
      }
      puVar7 = DAT_140e45d28;
      if (uVar16 == 0x5a) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar28 = param_1[0xb];
        uVar29 = param_1[10];
        puVar7 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar7 + 0x14) = uVar29;
          *(undefined4 *)(puVar7 + 3) = uVar28;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar29;
          *(undefined4 *)(puVar7 + 4) = uVar28;
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
          if (bVar19) {
            DAT_140e45d78 = puVar7;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar7;
          }
        }
      }
      DAT_140e45d28 = puVar7;
      uVar28 = DAT_140e41ab8;
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
      bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar8 = uVar28;
      puVar8[1] = 0x4e;
      *(undefined8 *)(puVar8 + 2) = 5;
      puVar8[4] = 0;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = iVar14;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar19) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
      uVar28 = SUB84(DAT_14053a430,0);
      uVar29 = (undefined4)((ulonglong)DAT_14053a430 >> 0x20);
      iVar9 = 0xff;
      if (99 < (int)*puVar1) {
        iVar9 = 0;
      }
      local_res10 = 0x57;
      if (99 < (int)*puVar1) {
        local_res10 = 0x54;
      }
      uVar11 = (ulonglong)local_res10;
      DAT_140e46c88 = puVar8;
      if (*puVar1 == 0x8c) {
        *param_1 = 0;
        local_res8 = 0;
      }
      goto LAB_14005c77b;
    }
    iVar9 = 0xff;
    uVar11 = 0x54;
  }
LAB_14005c77b:
  uVar33 = (undefined2)(in_stack_fffffffffffffe40 >> 0x10);
  if (param_1[0x15] == 0) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) goto LAB_14005c7fd;
      in_stack_fffffffffffffe40 = in_stack_fffffffffffffe40 & 0xffff0000;
      stage_entity_spawn_candidate
                (0xc3,99999999,1,0,0,in_stack_fffffffffffffe40,dVar5,0x14,0,param_1[1]);
      uVar33 = (undefined2)(in_stack_fffffffffffffe40 >> 0x10);
      param_1[0x17] = 1;
    }
    else if (param_1[0x17] != 1) goto LAB_14005c7fd;
    param_1[0x15] = 1;
    if (DAT_140e44654 < 0x3d) {
      param_1[0x17] = 0;
      param_1[0x15] = 0;
    }
  }
LAB_14005c7fd:
  dVar22 = (double)FUN_1403307c0();
  fVar31 = (float)(dVar22 * (double)CONCAT44(uVar29,uVar28)) + (float)param_1[10];
  dVar22 = (double)FUN_140332d90();
  fVar32 = (float)(dVar22 * (double)CONCAT44(uVar29,uVar28)) + (float)param_1[0xb];
  dVar22 = (double)FUN_1403300b4((double)(DAT_14053b3d0 - fVar32),SUB84((double)(0.0 - fVar31),0));
  dVar22 = dVar22 * DAT_14053aba0;
  dVar27 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar27 * DAT_14053a5f0) + fVar31;
  dVar27 = (double)FUN_140332d90();
  fVar21 = (float)(dVar27 * DAT_14053a5f0) + fVar32;
  dVar27 = (double)FUN_1403300b4((double)(DAT_14053b3ac - fVar21),
                                 SUB84((double)(DAT_14053aec0 - fVar20),0));
  dVar27 = dVar27 * DAT_14053aba0;
  dVar26 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar26 * _DAT_14053a580) + fVar20;
  dVar26 = (double)FUN_140332d90();
  fVar21 = (float)(dVar26 * _DAT_14053a580) + fVar21;
  uVar18 = (undefined2)(int)dVar27;
  if (0 < iVar9) {
    uVar28 = CONCAT22(uVar33,uVar18);
    FUN_1400c8410(DAT_140e44a68,0x1e,7,fVar20,fVar21,uVar28,dVar5,uVar6,0xff,0xff,0xff,iVar9,1,0);
    uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),(short)(int)dVar22);
    FUN_1400c8410(DAT_140e44a64,0x1e,7,fVar31,fVar32,uVar28,dVar5,uVar6,0xff,0xff,0xff,iVar9,1,0);
    uVar28 = CONCAT22((short)((uint)uVar28 >> 0x10),*(undefined2 *)(param_1 + 0x10));
    FUN_1400c8410((&DAT_140e44910)[uVar11],0x1e,7,param_1[10],param_1[0xb],uVar28,dVar5,uVar6,0xff,
                  0xff,0xff,iVar9,1,0);
    uVar33 = (undefined2)((uint)uVar28 >> 0x10);
    if (param_1[5] == 99) {
      uVar28 = CONCAT22(uVar33,*(short *)(param_1 + 3) * 0x115c + *(short *)(param_1 + 0x10));
      FUN_1400c8410(DAT_140e44a70,0x1e,7,param_1[10],
                    ((float)(int)param_1[3] * DAT_140539ce4 + DAT_140539da8) *
                    (float)(int)param_1[3] + (float)param_1[0xf],uVar28,dVar5,uVar6,0xff,0xff,0xff,
                    iVar9,1,0);
      uVar33 = (undefined2)((uint)uVar28 >> 0x10);
    }
  }
  if (0 < local_res8) {
    uStack_16c = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_170 = (undefined4)uVar2;
    FUN_1400c8410(DAT_140e44a68,0x1e,8,fVar20,fVar21,CONCAT22(uVar33,uVar18),dVar5,uVar6,local_170,
                  uStack_16c,uVar3,local_res8,1,0);
    FUN_1400c8410(DAT_140e44a64,0x1e,8,fVar31,fVar32,(int)dVar22 & 0xffff,dVar5,uVar6,local_170,
                  uStack_16c,uVar3,local_res8,1,0);
    FUN_1400c8410((&DAT_140e44910)[local_res10],0x1e,8,param_1[10],param_1[0xb],
                  *(undefined2 *)(param_1 + 0x10),dVar5,uVar6,local_170,uStack_16c,uVar3,local_res8,
                  1,0);
  }
  return;
}


