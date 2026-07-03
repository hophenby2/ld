// Function: FUN_1400b1db0 @ 1400b1db0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400b1db0(undefined4 *param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  ushort uVar13;
  ushort uVar14;
  int iVar15;
  bool bVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff18;
  undefined4 uVar23;
  undefined2 uVar24;
  float in_stack_ffffffffffffff20;
  ushort uVar25;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 uVar26;
  
  uVar24 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  uVar26 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);
  dVar17 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 (double)((float)param_1[0xc] - (float)param_1[10]));
  fVar6 = DAT_14053ace8;
  dVar3 = DAT_14053aba0;
  dVar18 = DAT_140539e98;
  uVar25 = (ushort)((uint)in_stack_ffffffffffffff20 >> 0x10);
  dVar17 = dVar17 * DAT_14053aba0;
  uVar13 = (ushort)(int)dVar17;
  if (param_1[5] == 0) {
    uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar26 = DAT_14053b380;
    local_res8 = (undefined4)uVar11;
    uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
    dVar20 = DAT_14053a018 - (double)(int)param_1[3] * dVar18;
    if (param_1[3] == 0) {
      uVar23 = DAT_14053af54;
      if ((float)param_1[0xe] <= DAT_14053ae30 && DAT_14053ae30 != (float)param_1[0xe]) {
        uVar23 = DAT_14053b380;
      }
      param_1[10] = uVar23;
      param_1[0xb] = uVar26;
      uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 10));
      local_res8 = (undefined4)uVar11;
      uStackX_c = (undefined4)((ulonglong)uVar11 >> 0x20);
    }
    in_stack_ffffffffffffff20 = (float)((uint)uVar25 << 0x10);
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff20,dVar20,dVar20,
                  0xff,0xff,0xff,0xff,1,0);
    uVar23 = DAT_14053b34c;
    uVar24 = (undefined2)((uint)uStackX_c >> 0x10);
    uVar26 = (undefined4)((ulonglong)dVar20 >> 0x20);
    if (param_1[3] == 0x14) {
      uVar11 = CONCAT44(uVar26,0x14);
      uVar10 = (uint)in_stack_ffffffffffffff20 & 0xffff0000;
      stage_entity_spawn_candidate
                (0x101,99999999,1,fVar6,DAT_14053b34c,uVar10,0,uVar11,1,param_1[1]);
      uVar11 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),0x14);
      in_stack_ffffffffffffff20 = (float)(uVar10 & 0xffff0000);
      stage_entity_spawn_candidate
                (0x101,99999999,1,DAT_14053b36c,uVar23,in_stack_ffffffffffffff20,0,uVar11,1,
                 param_1[1]);
      uVar24 = (undefined2)((uint)uVar23 >> 0x10);
      uVar26 = (undefined4)((ulonglong)uVar11 >> 0x20);
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4027000000000000;
      *(ushort *)(param_1 + 0x10) = uVar13;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_1400b269f;
  uVar10 = param_1[3];
  dVar20 = (double)FUN_140332d90(((double)(int)uVar10 - 0.0) * DAT_14053a998 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar22 = (float)(dVar20 * DAT_14053a0b0) + 0.0;
  if ((int)uVar10 < 0xf0) {
    if ((0x45 < (int)uVar10) && (uVar10 - 0x46 == ((int)(uVar10 - 0x46) / 0x32) * 0x32)) {
      uVar8 = uVar10 * param_1[1] * 999;
      uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar8 = uVar8 * 0x800 ^ uVar8;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
      param_1[0xc] = (float)(DAT_140e9fd1c % 0x1e1 + 0x78);
      uVar8 = uVar10;
      if (uVar10 != uVar10 + 100) {
        uVar8 = uVar10 * param_1[1] * 9999;
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
    if ((uVar10 < 0x3d) && (DAT_140539ff0 < dVar20)) {
      dVar20 = dVar20 - dVar18;
    }
  }
  else {
    dVar20 = *(double *)(param_1 + 0x12) + DAT_140539e60;
    param_1[0xd] = 0xc3fa0000;
  }
  uVar25 = *(ushort *)(param_1 + 0x10);
  *(double *)(param_1 + 0x12) = dVar20;
  dVar18 = (double)FUN_1403307c0();
  fVar21 = (float)(dVar18 * dVar20) + (float)param_1[10];
  param_1[10] = fVar21;
  dVar18 = (double)FUN_140332d90();
  iVar9 = ((int)dVar17 & 0xffffU) - (uint)uVar25;
  iVar15 = iVar9 + 0x10000;
  if (-0x8001 < iVar9) {
    iVar15 = iVar9;
  }
  fVar19 = (float)(dVar18 * dVar20) + (float)param_1[0xb];
  iVar9 = iVar15 + -0x10000;
  if (iVar15 < 0x8001) {
    iVar9 = iVar15;
  }
  param_1[0xb] = fVar19;
  fVar4 = DAT_14053ac2c;
  if (iVar9 < 1) {
    uVar14 = uVar25;
    if ((iVar9 < 0) && (uVar14 = uVar13, iVar9 < -0x1ff)) {
      uVar14 = uVar25 - 0x200;
    }
  }
  else {
    uVar14 = uVar13;
    if (0x1ff < iVar9) {
      uVar14 = uVar25 + 0x200;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar14;
  if ((0x45 < (int)uVar10) && ((int)uVar10 < 0xf0)) {
    puVar1 = (undefined2 *)((longlong)param_1 + 0x42);
    iVar15 = (int)(uVar10 - 0x46) % 0x3c;
    dVar18 = (double)iVar15 * DAT_140539e50 + DAT_14053a140;
    if (iVar15 == 0) {
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),
                                     (double)(DAT_140e445d8 - fVar21));
      *puVar1 = (short)(int)(dVar17 * dVar3);
    }
    else if ((0x27 < iVar15) || (iVar15 != (iVar15 / 5) * 5)) goto LAB_1400b2417;
    fVar5 = DAT_14053ac48;
    FUN_14006c2f0(7,0,fVar21 + DAT_14053ac48,fVar19 + DAT_14053ac48,CONCAT22(uVar24,*puVar1),fVar4,
                  dVar18,CONCAT44(uVar26,1),0);
    in_stack_ffffffffffffff20 = fVar4;
    FUN_14006c2f0(7,0,(float)param_1[10] - fVar5,(float)param_1[0xb] + fVar5,*puVar1,fVar4,dVar18,1,
                  0);
    fVar19 = (float)param_1[0xb];
    fVar21 = (float)param_1[10];
  }
LAB_1400b2417:
  uVar7 = _UNK_14053bb28;
  uVar11 = _DAT_14053bb20;
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    uVar10 = (uint)in_stack_ffffffffffffff20 & 0xffff0000;
    FUN_1400c8410(DAT_140e44e0c,0x22,7,fVar21 + fVar6,(fVar19 + fVar22) - fVar4,uVar10,
                  _DAT_14053bb20,_UNK_14053bb28,0xff,0xff,0xff,0xff,1,0);
    in_stack_ffffffffffffff20 = (float)(uVar10 & 0xffff0000);
    FUN_1400c8410(DAT_140e44e0c,0x22,7,(float)param_1[10] - fVar6,
                  (fVar22 + (float)param_1[0xb]) - fVar4,in_stack_ffffffffffffff20,uVar11,uVar7,0xff
                  ,0xff,0xff,0xff,1,1);
  }
  FUN_1400c8410(DAT_140e44e08,0x22,7,param_1[10],param_1[0xb],
                (uint)in_stack_ffffffffffffff20 & 0xffff0000,uVar11,uVar7,0xff,0xff,0xff,0xff,1,0);
  uVar26 = DAT_140e44e08;
  uVar10 = param_1[3] & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  puVar12 = DAT_140e45d28;
  if (uVar10 == 0) {
    uVar23 = param_1[0xb];
    uVar2 = param_1[10];
    if (DAT_140e45d1c < 0x1000) {
      puVar12 = (undefined8 *)_malloc_base(0x60);
      if (puVar12 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar12 + 0x14) = uVar2;
      *(undefined4 *)(puVar12 + 3) = uVar23;
      *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar2;
      *(undefined4 *)(puVar12 + 4) = uVar23;
      *puVar12 = 1;
      *(undefined4 *)(puVar12 + 1) = 5;
      *(undefined4 *)((longlong)puVar12 + 0xc) = uVar26;
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
LAB_1400b269f:
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


