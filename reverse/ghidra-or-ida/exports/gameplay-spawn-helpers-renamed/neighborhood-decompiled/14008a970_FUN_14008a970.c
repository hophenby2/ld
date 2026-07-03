// Function: FUN_14008a970 @ 14008a970
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008a970(undefined4 *param_1)

{
  undefined4 uVar1;
  double dVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  bool bVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  double dVar18;
  float fVar19;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined2 uVar22;
  float in_stack_ffffffffffffff10;
  ushort uVar24;
  undefined4 uVar23;
  undefined8 in_stack_ffffffffffffff20;
  
  uVar22 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff20 >> 0x20);
  dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  dVar14 = dVar14 * DAT_14053aba0;
  dVar15 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xc] - (float)param_1[10]));
  uVar20 = DAT_14053b378;
  dVar2 = DAT_14053a018;
  dVar16 = DAT_140539e98;
  uVar24 = (ushort)((uint)in_stack_ffffffffffffff10 >> 0x10);
  dVar15 = dVar15 * DAT_14053aba0;
  uVar12 = (ushort)(int)dVar15;
  iVar10 = DAT_140e419b8;
  if (param_1[5] == 0) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar1 = DAT_14053b380;
    local_res8 = (undefined4)uVar7;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    dVar18 = dVar2 - (double)(int)param_1[3] * dVar16;
    if (param_1[3] == 0) {
      uVar23 = DAT_14053af54;
      if ((float)param_1[0xe] <= DAT_14053ae30 && DAT_14053ae30 != (float)param_1[0xe]) {
        uVar23 = DAT_14053b380;
      }
      param_1[10] = uVar23;
      param_1[0xb] = uVar1;
      uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10));
      local_res8 = (undefined4)uVar7;
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    }
    in_stack_ffffffffffffff10 = (float)((uint)uVar24 << 0x10);
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff10,dVar18,dVar18,
                  0xff,0xff,0xff,0xff,1,0);
    uVar22 = (undefined2)((uint)uStackX_c >> 0x10);
    uVar23 = (undefined4)((ulonglong)dVar18 >> 0x20);
    iVar10 = DAT_140e419b8;
    if (param_1[3] == 0x14) {
      uVar7 = CONCAT44(uVar23,0x14);
      uVar23 = CONCAT22((short)((uint)in_stack_ffffffffffffff10 >> 0x10),0xfc18);
      stage_entity_spawn_candidate(0x28,99999999,1,DAT_14053acbc,uVar20,uVar23,0,uVar7,1,param_1[1])
      ;
      uVar21 = DAT_14053b358;
      uVar7 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),0x14);
      in_stack_ffffffffffffff10 = (float)CONCAT22((short)((uint)uVar23 >> 0x10),1000);
      stage_entity_spawn_candidate
                (0x28,99999999,1,DAT_14053b358,uVar20,in_stack_ffffffffffffff10,0,uVar7,1,param_1[1]
                );
      uVar22 = (undefined2)((uint)uVar20 >> 0x10);
      uVar23 = (undefined4)((ulonglong)uVar7 >> 0x20);
      if (0 < DAT_140e419b8) {
        uVar7 = CONCAT44(uVar23,0x14);
        uVar20 = CONCAT22((short)((uint)in_stack_ffffffffffffff10 >> 0x10),0xf448);
        stage_entity_spawn_candidate
                  (0x28,99999999,1,DAT_14053ad1c,uVar21,uVar20,0,uVar7,1,param_1[1]);
        uVar7 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),0x14);
        in_stack_ffffffffffffff10 = (float)CONCAT22((short)((uint)uVar20 >> 0x10),3000);
        stage_entity_spawn_candidate
                  (0x28,99999999,1,uVar1,uVar21,in_stack_ffffffffffffff10,0,uVar7,1,param_1[1]);
        uVar22 = (undefined2)((uint)uVar21 >> 0x10);
        uVar23 = (undefined4)((ulonglong)uVar7 >> 0x20);
      }
      iVar10 = DAT_140e419b8;
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4027000000000000;
      *(ushort *)(param_1 + 0x10) = uVar12;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] == 1) {
    uVar6 = param_1[3];
    dVar18 = (double)FUN_140332d90(((double)(int)uVar6 - 0.0) * DAT_14053a998 * DAT_14053a020 *
                                   DAT_140539d28);
    fVar19 = (float)(dVar18 * DAT_14053a0b0) + 0.0;
    if ((int)uVar6 < 0xf0) {
      if ((0x3b < (int)uVar6) && (uVar6 - 0x3c == ((int)(uVar6 - 0x3c) / 0x32) * 0x32)) {
        uVar4 = uVar6 * param_1[1] * 0x14d;
        uVar4 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar4 = uVar4 * 0x800 ^ uVar4;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
        param_1[0xc] = (float)(DAT_140e9fd1c % 0x1e1 + 0x78);
        uVar4 = uVar6;
        if (uVar6 != uVar6 + 100) {
          uVar4 = uVar6 * param_1[1] * 0xd05;
          uVar4 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar4 = uVar4 * 0x800 ^ uVar4;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
          uVar4 = DAT_140e9fd1c % 0x65 + uVar6;
        }
        param_1[0xd] = (float)(int)uVar4;
      }
      dVar18 = *(double *)(param_1 + 0x12);
      if ((uVar6 < 0x3d) && (DAT_140539ff0 < dVar18)) {
        dVar18 = dVar18 - dVar16;
      }
    }
    else {
      dVar18 = *(double *)(param_1 + 0x12) + DAT_140539e60;
      param_1[0xd] = 0xc3fa0000;
    }
    uVar24 = *(ushort *)(param_1 + 0x10);
    *(double *)(param_1 + 0x12) = dVar18;
    dVar16 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar16 * dVar18) + (float)param_1[10];
    dVar16 = (double)FUN_140332d90();
    iVar5 = ((int)dVar15 & 0xffffU) - (uint)uVar24;
    iVar9 = iVar5 + 0x10000;
    if (-0x8001 < iVar5) {
      iVar9 = iVar5;
    }
    fVar17 = (float)(dVar16 * dVar18) + (float)param_1[0xb];
    iVar5 = iVar9 + -0x10000;
    if (iVar9 < 0x8001) {
      iVar5 = iVar9;
    }
    param_1[0xb] = fVar17;
    uVar7 = _UNK_14053bb28;
    dVar16 = _DAT_14053bb20;
    fVar3 = DAT_14053ac2c;
    if (iVar5 < 1) {
      uVar11 = uVar24;
      if ((iVar5 < 0) && (uVar11 = uVar12, iVar5 < -0x1ff)) {
        uVar11 = uVar24 - 0x200;
      }
    }
    else {
      uVar11 = uVar12;
      if (0x1ff < iVar5) {
        uVar11 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar11;
    if (uVar6 - 0x3c < 0xb4) {
      iVar9 = 1;
      if (iVar10 == 0) {
        iVar9 = 0xa0;
      }
      else if (iVar10 == 1) {
        iVar9 = 0x78;
      }
      else if (((iVar10 == 2) || (iVar10 == 3)) || (iVar10 == 4)) {
        iVar9 = 0x5a;
      }
      iVar5 = 1;
      if (iVar10 == 0) {
        iVar5 = 3;
      }
      else if (iVar10 == 1) {
        iVar5 = 5;
      }
      else if ((iVar10 == 2) || (iVar10 == 3)) {
        iVar5 = 7;
      }
      else if (iVar10 == 4) {
        iVar5 = 9;
      }
      dVar15 = DAT_14053a088;
      if (((iVar10 != 0) && (dVar15 = DAT_14053a118, iVar10 != 1)) &&
         ((dVar15 = DAT_14053a158, iVar10 != 2 &&
          ((dVar15 = DAT_14053a178, iVar10 != 3 && (dVar15 = DAT_14053a1c8, iVar10 != 4)))))) {
        dVar15 = dVar16;
      }
      if (((int)(uVar6 - 0x3c) % iVar9 == 0) ||
         (((2 < iVar10 && (0x53 < (int)uVar6)) && ((int)(uVar6 - 0x54) % iVar9 == 0)))) {
        FUN_1400709b0(2,9,param_1[10],fVar17,CONCAT22(uVar22,(short)(int)dVar14),fVar3,
                      dVar15 + dVar2,CONCAT44(uVar23,1),iVar5 - 1U,
                      (int)(20000 / (ulonglong)(iVar5 - 1U)) * (iVar5 + -2) & 0xffff,0);
        in_stack_ffffffffffffff10 = fVar3;
        FUN_1400709b0(3,0,param_1[10],param_1[0xb],(int)dVar14 & 0xffff,fVar3,dVar15,1,iVar5,20000,0
                     );
      }
    }
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      uVar6 = (uint)in_stack_ffffffffffffff10 & 0xffff0000;
      FUN_1400c8410(DAT_140e44ba0,0x22,7,(float)param_1[10] + DAT_14053ace8,
                    (fVar19 + (float)param_1[0xb]) - fVar3,uVar6,dVar16,uVar7,0xff,0xff,0xff,0xff,1,
                    0);
      in_stack_ffffffffffffff10 = (float)(uVar6 & 0xffff0000);
      FUN_1400c8410(DAT_140e44ba0,0x22,7,(float)param_1[10] - DAT_14053ace8,
                    (fVar19 + (float)param_1[0xb]) - fVar3,in_stack_ffffffffffffff10,dVar16,uVar7,
                    0xff,0xff,0xff,0xff,1,1);
    }
    FUN_1400c8410(DAT_140e44b9c,0x22,7,param_1[10],param_1[0xb],
                  (uint)in_stack_ffffffffffffff10 & 0xffff0000,dVar16,uVar7,0xff,0xff,0xff,0xff,1,0)
    ;
    uVar20 = DAT_140e44b9c;
    uVar6 = param_1[3] & 0x80000003;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
    }
    puVar8 = DAT_140e45d28;
    if (uVar6 == 0) {
      uVar23 = param_1[0xb];
      uVar1 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar1;
        *(undefined4 *)(puVar8 + 3) = uVar23;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar1;
        *(undefined4 *)(puVar8 + 4) = uVar23;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 5;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar20;
        *(undefined4 *)(puVar8 + 2) = 0x21;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0x18;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0x40;
        puVar8[0xb] = 0;
        if (bVar13) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
    }
    DAT_140e45d28 = puVar8;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
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


