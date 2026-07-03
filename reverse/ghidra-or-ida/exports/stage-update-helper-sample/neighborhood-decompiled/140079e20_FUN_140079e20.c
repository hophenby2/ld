// Function: FUN_140079e20 @ 140079e20
// Decompile completed: true

void FUN_140079e20(longlong param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  double dVar16;
  double dVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float fVar21;
  int local_res18;
  uint local_res20;
  uint local_f8;
  ulonglong local_f0;
  
  iVar2 = *(int *)(param_1 + 0x50);
  uVar5 = FUN_140134d00(*(int *)(param_1 + 4) * 0x6f + DAT_140e418c8,
                        (int)((iVar2 >> 0x1f & 3U) + iVar2) >> 2,iVar2 / 3);
  local_f0 = (ulonglong)uVar5;
  iVar2 = iVar2 + 0x3c;
  uVar9 = *(int *)(param_1 + 4) * 0x29a + DAT_140e418c8;
  local_res20 = uVar9;
  if (param_2 == 0) {
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47290);
    FUN_14018a340(DAT_140e47290,1,1);
    uVar4 = DAT_14053a1b8;
    uVar3 = DAT_140539f40;
    if (0 < (int)uVar5) {
      local_f8 = 0;
      local_res18 = 0;
      do {
        uVar12 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
        uVar8 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
        uVar11 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
        uVar5 = uVar12 * 0x800 ^ uVar12;
        uVar10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 4;
        DAT_140e9fd1c = (uVar10 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ uVar10;
        DAT_140e9fd10 = uVar8;
        DAT_140e9fd14 = uVar11;
        DAT_140e9fd18 = uVar10;
        iVar6 = FUN_140134d00(uVar9,0,iVar2);
        dVar16 = (double)FUN_1403307c0();
        fVar1 = *(float *)(param_1 + 0x28);
        dVar17 = (double)FUN_140332d90();
        uVar12 = uVar12 * 0x800 ^ uVar12;
        uVar5 = (uVar10 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ uVar10;
        fVar21 = (float)(dVar17 * (double)iVar6) + *(float *)(param_1 + 0x2c);
        DAT_140e9fd10 = uVar8;
        DAT_140e9fd14 = uVar11;
        DAT_140e9fd18 = uVar10;
        DAT_140e9fd1c = uVar5;
        uVar18 = FUN_140134db0(uVar9);
        uVar14 = (undefined4)uVar18;
        uVar15 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(uVar9);
        FUN_140070d00(0x2a,DAT_140e41a54,0x3e,(float)(dVar16 * (double)iVar6) + fVar1,fVar21,
                      (short)uVar5 - (short)(uVar5 / 0x10001),uVar3,uVar18,CONCAT44(uVar15,uVar14),
                      0x18,0xff,0xff,0xff,0xff,0);
        iVar6 = DAT_140e418c8;
        uVar5 = ((uint)(local_res18 + DAT_140e418c8) >> 0x1e ^ local_res18 + DAT_140e418c8) *
                0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        DAT_140e9fd1c = uVar5;
        uVar18 = FUN_140134db0(local_res20,DAT_140e9fd18,uVar3);
        uVar14 = (undefined4)uVar18;
        uVar19 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(local_res20);
        uVar15 = (undefined4)uVar18;
        uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(local_f8 + iVar6,DAT_14053a0f8,uVar4);
        FUN_140070d00(0x2c,DAT_140e44ea8,0x3e,*(undefined4 *)(param_1 + 0x28),
                      *(undefined4 *)(param_1 + 0x2c),(short)uVar5 - (short)(uVar5 / 0x10001),uVar18
                      ,CONCAT44(uVar20,uVar15),CONCAT44(uVar19,uVar14),0,0xff,0xff,0xff,0xc0,0);
        uVar9 = uVar9 + 1;
        local_res18 = local_res18 + 0xb;
        local_res20 = local_res20 + 0x457;
        local_f8 = local_f8 + 0x22b;
        local_f0 = local_f0 - 1;
      } while (local_f0 != 0);
    }
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
        return;
      }
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar4 = DAT_140539fd8;
      uVar3 = DAT_140539f40;
      if (0 < (int)uVar5) {
        local_res18 = 0;
        local_f8 = uVar9;
        do {
          uVar12 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
          uVar8 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
          uVar11 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
          uVar5 = uVar12 ^ uVar12 * 0x800;
          uVar10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 4;
          DAT_140e9fd1c = (uVar10 >> 0xb ^ uVar5) >> 8 ^ uVar10 ^ uVar5;
          DAT_140e9fd10 = uVar8;
          DAT_140e9fd14 = uVar11;
          DAT_140e9fd18 = uVar10;
          iVar6 = FUN_140134d00(uVar9,0,iVar2);
          dVar16 = (double)FUN_1403307c0();
          fVar1 = *(float *)(param_1 + 0x28);
          dVar17 = (double)FUN_140332d90();
          uVar12 = uVar12 * 0x800 ^ uVar12;
          uVar12 = (uVar10 >> 0xb ^ uVar12) >> 8 ^ uVar10 ^ uVar12;
          fVar21 = (float)(dVar17 * (double)iVar6) + *(float *)(param_1 + 0x2c);
          DAT_140e9fd10 = uVar8;
          DAT_140e9fd14 = uVar11;
          DAT_140e9fd18 = uVar10;
          DAT_140e9fd1c = uVar12;
          uVar18 = FUN_140134db0(uVar9);
          uVar14 = (undefined4)uVar18;
          uVar15 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uVar18 = FUN_140134db0(uVar9);
          FUN_140070d00(0x2a,DAT_140e41a54,0x3e,(float)(dVar16 * (double)iVar6) + fVar1,fVar21,
                        (short)uVar12 - (short)(uVar12 / 0x10001),uVar3,uVar18,
                        CONCAT44(uVar15,uVar14),0x18,0xff,0xff,0xff,0xff,0);
          uVar5 = ((uint)(DAT_140e418c8 + local_res18) >> 0x1e ^ DAT_140e418c8 + local_res18) *
                  0x6c078965 + 1;
          DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar5 = uVar5 * 0x800 ^ uVar5;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
          DAT_140e9fd1c = uVar5;
          uVar18 = FUN_140134db0(local_res20,DAT_140e9fd18,uVar4);
          uVar14 = (undefined4)uVar18;
          uVar19 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uVar18 = FUN_140134db0(local_res20);
          uVar15 = (undefined4)uVar18;
          uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uVar18 = FUN_140134db0(local_f8,DAT_14053a248,DAT_14053a2b8);
          FUN_140070d00(0x2c,DAT_140e44ea8,0x3e,*(undefined4 *)(param_1 + 0x28),
                        *(undefined4 *)(param_1 + 0x2c),(short)uVar5 - (short)(uVar5 / 0x10001),
                        uVar18,CONCAT44(uVar20,uVar15),CONCAT44(uVar19,uVar14),0,0xff,0xff,0xff,0xc0
                        ,0);
          uVar9 = uVar9 + 1;
          local_res18 = local_res18 + 0x21;
          local_res20 = local_res20 + 0xd05;
          local_f8 = local_f8 + 0x14d;
          local_f0 = local_f0 - 1;
        } while (local_f0 != 0);
      }
      uVar19 = DAT_140e45060;
      uVar14 = *(undefined4 *)(param_1 + 0x2c);
      uVar15 = *(undefined4 *)(param_1 + 0x28);
      if (0xfff < DAT_140e45d1c) {
        return;
      }
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar7 + 0x14) = uVar15;
      *(undefined4 *)(puVar7 + 3) = uVar14;
      *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar15;
      *(undefined4 *)(puVar7 + 4) = uVar14;
      *puVar7 = 1;
      *(undefined4 *)(puVar7 + 1) = 0x13;
      *(undefined4 *)((longlong)puVar7 + 0xc) = uVar19;
      *(undefined4 *)(puVar7 + 2) = 0x5b;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0;
      puVar7[6] = 0;
      puVar7[7] = 0;
      *(undefined4 *)(puVar7 + 8) = 0;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0;
      if (bVar13) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 == (undefined8 *)0x0) {
        DAT_140e45d28 = puVar7;
        return;
      }
      *(undefined8 **)((longlong)DAT_140e45d28 + 0x58) = puVar7;
      DAT_140e45d28 = puVar7;
      return;
    }
    FUN_140184700(DAT_140e44190 * 0x16,DAT_140e47294);
    FUN_14018a340(DAT_140e47294,1,1);
    uVar4 = DAT_140539f90;
    uVar3 = DAT_140539f40;
    if (0 < (int)uVar5) {
      local_f8 = 0;
      local_res18 = 0;
      do {
        uVar11 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
        uVar10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
        uVar8 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
        uVar5 = uVar11 ^ uVar11 * 0x800;
        uVar12 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 4;
        DAT_140e9fd1c = (uVar5 ^ uVar12 >> 0xb) >> 8 ^ uVar5 ^ uVar12;
        DAT_140e9fd10 = uVar10;
        DAT_140e9fd14 = uVar8;
        DAT_140e9fd18 = uVar12;
        iVar6 = FUN_140134d00(uVar9,0,iVar2);
        dVar16 = (double)FUN_1403307c0();
        fVar1 = *(float *)(param_1 + 0x28);
        dVar17 = (double)FUN_140332d90();
        uVar11 = uVar11 ^ uVar11 * 0x800;
        uVar5 = (uVar11 ^ uVar12 >> 0xb) >> 8 ^ uVar11 ^ uVar12;
        fVar21 = (float)(dVar17 * (double)iVar6) + *(float *)(param_1 + 0x2c);
        DAT_140e9fd10 = uVar10;
        DAT_140e9fd14 = uVar8;
        DAT_140e9fd18 = uVar12;
        DAT_140e9fd1c = uVar5;
        uVar18 = FUN_140134db0(uVar9);
        uVar14 = (undefined4)uVar18;
        uVar15 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(uVar9);
        FUN_140070d00(0x2a,DAT_140e41a54,0x3e,(float)(dVar16 * (double)iVar6) + fVar1,fVar21,
                      (short)uVar5 - (short)(uVar5 / 0x10001),uVar3,uVar18,CONCAT44(uVar15,uVar14),
                      0x18,0xff,0xff,0xff,0xff,0);
        iVar6 = DAT_140e418c8;
        uVar5 = ((uint)(local_res18 + DAT_140e418c8) >> 0x1e ^ local_res18 + DAT_140e418c8) *
                0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
        DAT_140e9fd1c = uVar5;
        uVar18 = FUN_140134db0(local_res20,DAT_140e9fd18,uVar4);
        uVar14 = (undefined4)uVar18;
        uVar19 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(local_res20);
        uVar15 = (undefined4)uVar18;
        uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar18 = FUN_140134db0(iVar6 + local_f8,DAT_14053a1e8,DAT_14053a240);
        FUN_140070d00(0x2c,DAT_140e44ea8,0x3e,*(undefined4 *)(param_1 + 0x28),
                      *(undefined4 *)(param_1 + 0x2c),(short)uVar5 - (short)(uVar5 / 0x10001),uVar18
                      ,CONCAT44(uVar20,uVar15),CONCAT44(uVar19,uVar14),0,0xff,0xff,0xff,0xc0,0);
        uVar9 = uVar9 + 1;
        local_res18 = local_res18 + 0x16;
        local_res20 = local_res20 + 0x8ae;
        local_f8 = local_f8 + 0xde;
        local_f0 = local_f0 - 1;
      } while (local_f0 != 0);
    }
  }
  if (-1 < DAT_140e45d18) {
    dVar16 = (double)*(int *)(param_1 + 0x50) * DAT_140539e38;
    FUN_140070d00(0xc,DAT_140e41a50,0x3d,*(undefined4 *)(param_1 + 0x28),
                  *(undefined4 *)(param_1 + 0x2c),0,0,dVar16,dVar16,0x18,0xff,0xff,0xff,0x60,0);
  }
  return;
}


