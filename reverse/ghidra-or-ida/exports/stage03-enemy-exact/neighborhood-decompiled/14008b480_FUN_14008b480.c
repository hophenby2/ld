// Function: FUN_14008b480 @ 14008b480
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008b480(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  double dVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  int iVar13;
  ushort uVar14;
  ushort uVar15;
  bool bVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  fVar21 = (float)param_1[10];
  dVar17 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xc] - fVar21));
  fVar6 = DAT_14053ace8;
  dVar4 = DAT_14053a018;
  dVar18 = DAT_140539e98;
  dVar17 = dVar17 * DAT_14053aba0;
  uVar14 = (ushort)(int)dVar17;
  if (param_1[5] == 0) {
    uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar5 = DAT_14053b380;
    local_res8 = (undefined4)uVar11;
    uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
    dVar20 = dVar4 - (double)(int)param_1[3] * dVar18;
    if (param_1[3] == 0) {
      uVar1 = DAT_14053af54;
      if (fVar21 < DAT_14053ae30) {
        uVar1 = DAT_14053b380;
      }
      param_1[10] = uVar1;
      param_1[0xb] = uVar5;
      uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10));
      local_res8 = (undefined4)uVar11;
      uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
    }
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,0,dVar20,dVar20,0xff,0xff,0xff,0xff,1,0)
    ;
    uVar5 = DAT_14053acfc;
    if (param_1[3] == 0x14) {
      stage_entity_spawn_candidate
                (0x2a,99999999,1,DAT_14053ac80,DAT_14053acfc,200,0,0x14,1,param_1[1]);
      stage_entity_spawn_candidate(0x2a,99999999,1,DAT_14053b33c,uVar5,0xff38,0,0x14,1,param_1[1]);
      uVar5 = DAT_14053aca8;
      if (0 < DAT_140e419b8) {
        stage_entity_spawn_candidate(0x2a,99999999,1,fVar6,DAT_14053aca8,0,0,0x14,1,param_1[1]);
        stage_entity_spawn_candidate(0x2a,99999999,1,DAT_14053b36c,uVar5,0,0,0x14,1,param_1[1]);
      }
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4028000000000000;
      *(ushort *)(param_1 + 0x10) = uVar14;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] == 1) {
    uVar10 = param_1[3];
    dVar20 = (double)FUN_140332d90(((double)(int)uVar10 - 0.0) * DAT_14053a998 * DAT_14053a020 *
                                   DAT_140539d28);
    fVar21 = (float)(dVar20 * DAT_14053a0b0) + 0.0;
    if ((int)uVar10 < 0xf0) {
      if ((0x3b < (int)uVar10) && (uVar10 - 0x3c == ((int)(uVar10 - 0x3c) / 0x32) * 0x32)) {
        uVar8 = uVar10 * param_1[1] * 0x14d;
        uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar8 = uVar8 * 0x800 ^ uVar8;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
        param_1[0xc] = (float)(DAT_140e9fd1c % 0x1e1 + 0x78);
        uVar8 = uVar10;
        if (uVar10 != uVar10 + 100) {
          uVar8 = uVar10 * param_1[1] * 0xd05;
          uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar8 = uVar8 * 0x800 ^ uVar8;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
          uVar8 = DAT_140e9fd1c % 0x65 + uVar10;
        }
        param_1[0xd] = (float)(int)uVar8;
      }
      dVar20 = *(double *)(param_1 + 0x12);
      if ((uVar10 < 0x3d) && (dVar4 < dVar20)) {
        dVar20 = dVar20 - dVar18;
      }
    }
    else {
      dVar20 = *(double *)(param_1 + 0x12) + DAT_140539e60;
      param_1[0xd] = 0xc3fa0000;
    }
    uVar3 = *(ushort *)(param_1 + 0x10);
    *(double *)(param_1 + 0x12) = dVar20;
    dVar18 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar18 * dVar20) + (float)param_1[10];
    param_1[10] = fVar22;
    dVar18 = (double)FUN_140332d90();
    iVar9 = ((int)dVar17 & 0xffffU) - (uint)uVar3;
    iVar13 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar13 = iVar9;
    }
    fVar19 = (float)(dVar18 * dVar20) + (float)param_1[0xb];
    iVar9 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar9 = iVar13;
    }
    param_1[0xb] = fVar19;
    uVar7 = _UNK_14053bb28;
    uVar11 = _DAT_14053bb20;
    if (iVar9 < 1) {
      uVar15 = uVar3;
      if ((iVar9 < 0) && (uVar15 = uVar14, iVar9 < -0x1ff)) {
        uVar15 = uVar3 - 0x200;
      }
    }
    else {
      uVar15 = uVar14;
      if (0x1ff < iVar9) {
        uVar15 = uVar3 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    if ((uVar10 & 1) == 0) {
      FUN_1400c8410(DAT_140e44ba8,0x22,7,fVar22 + fVar6,fVar19 + fVar21,0,uVar11,uVar7,0xff,0xff,
                    0xff,0xff,1,0);
      FUN_1400c8410(DAT_140e44ba8,0x22,7,(float)param_1[10] - fVar6,fVar21 + (float)param_1[0xb],0,
                    uVar11,uVar7,0xff,0xff,0xff,0xff,1,1);
    }
    FUN_1400c8410(DAT_140e44ba4,0x22,7,param_1[10],param_1[0xb],0,uVar11,uVar7,0xff,0xff,0xff,0xff,1
                  ,0);
    uVar5 = DAT_140e44ba4;
    uVar10 = param_1[3] & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    puVar12 = DAT_140e45d28;
    if (uVar10 == 0) {
      uVar1 = param_1[0xb];
      uVar2 = param_1[10];
      if (DAT_140e45d1c < 0x1000) {
        puVar12 = (undefined8 *)_malloc_base(0x60);
        if (puVar12 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar12 + 0x14) = uVar2;
        *(undefined4 *)(puVar12 + 3) = uVar1;
        *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar2;
        *(undefined4 *)(puVar12 + 4) = uVar1;
        *puVar12 = 1;
        *(undefined4 *)(puVar12 + 1) = 5;
        *(undefined4 *)((longlong)puVar12 + 0xc) = uVar5;
        *(undefined4 *)(puVar12 + 2) = 0x21;
        *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
        puVar12[5] = 0;
        puVar12[6] = 0x3ff0000000000000;
        puVar12[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar12 + 8) = 0x18;
        *(undefined4 *)((longlong)puVar12 + 0x44) = 0xff;
        *(undefined4 *)(puVar12 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar12 + 0x4c) = 0xff;
        puVar12[10] = 0x40;
        puVar12[0xb] = 0;
        if (bVar16) {
          DAT_140e45d78 = puVar12;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar12;
        }
      }
    }
    DAT_140e45d28 = puVar12;
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


