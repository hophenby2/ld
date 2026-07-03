// Function: FUN_1400b14d0 @ 1400b14d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b14d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  double dVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  int iVar12;
  ushort uVar13;
  ushort uVar14;
  bool bVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  fVar20 = (float)param_1[10];
  dVar16 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xc] - fVar20));
  dVar4 = DAT_14053a018;
  dVar17 = DAT_140539e98;
  dVar16 = dVar16 * DAT_14053aba0;
  uVar13 = (ushort)(int)dVar16;
  if (param_1[5] == 0) {
    uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar5 = DAT_14053b380;
    local_res8 = (undefined4)uVar10;
    uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    dVar19 = dVar4 - (double)(int)param_1[3] * dVar17;
    if (param_1[3] == 0) {
      uVar1 = DAT_14053af54;
      if (fVar20 < DAT_14053ae30) {
        uVar1 = DAT_14053b380;
      }
      param_1[10] = uVar1;
      param_1[0xb] = uVar5;
      uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 10));
      local_res8 = (undefined4)uVar10;
      uStackX_c = (undefined4)((ulonglong)uVar10 >> 0x20);
    }
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,0,dVar19,dVar19,0xff,0xff,0xff,0xff,1,0)
    ;
    uVar1 = DAT_14053b358;
    if (param_1[3] == 0x14) {
      stage_entity_spawn_candidate
                (0xff,99999999,1,DAT_14053acbc,DAT_14053b358,0,0,0x14,1,param_1[1]);
      stage_entity_spawn_candidate(0xff,99999999,1,uVar1,uVar1,0,0,0x14,1,param_1[1]);
      uVar1 = DAT_14053b330;
      stage_entity_spawn_candidate
                (0xff,99999999,1,DAT_14053ad1c,DAT_14053b330,0x1130,0,0x14,1,param_1[1]);
      stage_entity_spawn_candidate(0xff,99999999,1,uVar5,uVar1,0xeed0,0,0x14,1,param_1[1]);
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4027000000000000;
      *(ushort *)(param_1 + 0x10) = uVar13;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] == 1) {
    uVar9 = param_1[3];
    dVar19 = (double)FUN_140332d90(((double)(int)uVar9 - 0.0) * DAT_14053a998 * DAT_14053a020 *
                                   DAT_140539d28);
    fVar20 = (float)(dVar19 * DAT_14053a0b0) + 0.0;
    if ((int)uVar9 < 0xf0) {
      if ((0x3b < (int)uVar9) && (uVar9 - 0x3c == ((int)(uVar9 - 0x3c) / 0x32) * 0x32)) {
        uVar7 = uVar9 * param_1[1] * 0x378;
        uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
        param_1[0xc] = (float)(DAT_140e9fd1c % 0x1e1 + 0x78);
        uVar7 = uVar9;
        if (uVar9 != uVar9 + 100) {
          uVar7 = uVar9 * param_1[1] * 0x22b8;
          uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar7 = uVar7 * 0x800 ^ uVar7;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
          uVar7 = DAT_140e9fd1c % 0x65 + uVar9;
        }
        param_1[0xd] = (float)(int)uVar7;
      }
      dVar19 = *(double *)(param_1 + 0x12);
      if ((uVar9 < 0x3d) && (dVar4 < dVar19)) {
        dVar19 = dVar19 - dVar17;
      }
    }
    else {
      dVar19 = *(double *)(param_1 + 0x12) + DAT_140539e60;
      param_1[0xd] = 0xc3fa0000;
    }
    uVar3 = *(ushort *)(param_1 + 0x10);
    *(double *)(param_1 + 0x12) = dVar19;
    dVar17 = (double)FUN_1403307c0();
    fVar21 = (float)(dVar17 * dVar19) + (float)param_1[10];
    param_1[10] = fVar21;
    dVar17 = (double)FUN_140332d90();
    iVar8 = ((int)dVar16 & 0xffffU) - (uint)uVar3;
    iVar12 = iVar8 + 0x10000;
    if (-0x8001 < iVar8) {
      iVar12 = iVar8;
    }
    fVar18 = (float)(dVar17 * dVar19) + (float)param_1[0xb];
    iVar8 = iVar12 + -0x10000;
    if (iVar12 < 0x8001) {
      iVar8 = iVar12;
    }
    param_1[0xb] = fVar18;
    uVar6 = _UNK_14053bb28;
    uVar10 = _DAT_14053bb20;
    if (iVar8 < 1) {
      uVar14 = uVar3;
      if ((iVar8 < 0) && (uVar14 = uVar13, iVar8 < -0x1ff)) {
        uVar14 = uVar3 - 0x200;
      }
    }
    else {
      uVar14 = uVar13;
      if (0x1ff < iVar8) {
        uVar14 = uVar3 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar14;
    if ((uVar9 & 1) == 0) {
      FUN_1400c8410(DAT_140e44e04,0x22,7,fVar21 + DAT_14053ace8,fVar18 + fVar20,0,uVar10,uVar6,0xff,
                    0xff,0xff,0xff,1,0);
      FUN_1400c8410(DAT_140e44e04,0x22,7,(float)param_1[10] - DAT_14053ace8,
                    fVar20 + (float)param_1[0xb],0,uVar10,uVar6,0xff,0xff,0xff,0xff,1,1);
    }
    FUN_1400c8410(DAT_140e44e00,0x22,7,param_1[10],param_1[0xb],0,uVar10,uVar6,0xff,0xff,0xff,0xff,1
                  ,0);
    uVar5 = DAT_140e44e00;
    uVar9 = param_1[3] & 0x80000003;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
    }
    puVar11 = DAT_140e45d28;
    if (uVar9 == 0) {
      uVar1 = param_1[0xb];
      uVar2 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar11 = (undefined8 *)_malloc_base(0x60);
        if (puVar11 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar15 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar11 + 0x14) = uVar2;
        *(undefined4 *)(puVar11 + 3) = uVar1;
        *(undefined4 *)((longlong)puVar11 + 0x1c) = uVar2;
        *(undefined4 *)(puVar11 + 4) = uVar1;
        *puVar11 = 1;
        *(undefined4 *)(puVar11 + 1) = 5;
        *(undefined4 *)((longlong)puVar11 + 0xc) = uVar5;
        *(undefined4 *)(puVar11 + 2) = 0x21;
        *(undefined2 *)((longlong)puVar11 + 0x24) = 0;
        puVar11[5] = 0;
        puVar11[6] = 0x3ff0000000000000;
        puVar11[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar11 + 8) = 0x18;
        *(undefined4 *)((longlong)puVar11 + 0x44) = 0xff;
        *(undefined4 *)(puVar11 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar11 + 0x4c) = 0xff;
        puVar11[10] = 0x40;
        puVar11[0xb] = 0;
        if (bVar15) {
          DAT_140e45d78 = puVar11;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar11;
        }
      }
    }
    DAT_140e45d28 = puVar11;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
        (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
       ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) &&
     (0xef < (int)param_1[3])) {
    *param_1 = 0;
  }
  return;
}


