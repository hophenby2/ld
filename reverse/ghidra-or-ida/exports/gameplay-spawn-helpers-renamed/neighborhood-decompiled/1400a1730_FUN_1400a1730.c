// Function: FUN_1400a1730 @ 1400a1730
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a1730(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  float fVar13;
  float in_stack_ffffffffffffff28;
  undefined4 in_stack_ffffffffffffff30;
  undefined2 uVar14;
  ulonglong in_stack_ffffffffffffff38;
  
  dVar1 = DAT_140539f40;
  uVar14 = (undefined2)((uint)in_stack_ffffffffffffff30 >> 0x10);
  iVar5 = 0;
  iVar2 = param_1[5];
  fVar13 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar13;
  if ((iVar2 != 0) || (fVar13 < DAT_14053b380)) {
LAB_1400a17cb:
    if (iVar2 != 1) goto LAB_1400a1a32;
  }
  else {
    bVar8 = DAT_1407c7798 != 8;
    iVar2 = 1;
    param_1[5] = 1;
    param_1[3] = 0;
    if (bVar8) goto LAB_1400a17cb;
    DAT_140e418cc = 1;
  }
  iVar2 = 1;
  if (param_1[3] == 0x50) {
    param_1[0x15] = 0;
  }
  else {
    uVar9 = param_1[10];
    fVar13 = fVar13 + DAT_14053ac9c;
    if (param_1[3] == 0x5a) {
      uVar6 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        uVar6 = 5;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar6 = 7;
      }
      else if (DAT_140e419b8 == 4) {
        uVar6 = 9;
      }
      do {
        in_stack_ffffffffffffff38 = 0;
        in_stack_ffffffffffffff30 =
             CONCAT22((short)((uint)in_stack_ffffffffffffff30 >> 0x10),
                      (short)iVar5 * (short)(0x10000 / (ulonglong)uVar6) + -0x4000);
        in_stack_ffffffffffffff28 = fVar13;
        stage_entity_spawn_candidate
                  (0x60,99999999,1,uVar9,fVar13,in_stack_ffffffffffffff30,0,0x19,1,param_1[1]);
        uVar14 = (undefined2)((uint)in_stack_ffffffffffffff30 >> 0x10);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar6);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
      iVar2 = param_1[5];
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0x1e);
    uVar14 = 0;
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,(uint)in_stack_ffffffffffffff28 & 0xffff0000,0,
                  in_stack_ffffffffffffff38 & 0xffffffff00000000);
    uVar9 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar3 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar3 = (undefined8 *)_malloc_base(0x60);
      if (puVar3 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar8 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar3 = 1;
      *(undefined4 *)(puVar3 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar3 + 0xc) = uVar9;
      puVar3[2] = 0x6f;
      puVar3[3] = 0;
      *(undefined4 *)(puVar3 + 4) = 0;
      *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
      puVar3[5] = 0;
      puVar3[6] = 0x3ff0000000000000;
      puVar3[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar3 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
      *(undefined4 *)(puVar3 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
      puVar3[10] = 0xff;
      puVar3[0xb] = 0;
      if (bVar8) {
        DAT_140e45d78 = puVar3;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar3;
      }
    }
    DAT_140e45d28 = puVar3;
    iVar2 = param_1[5] + 1;
    param_1[0x15] = 1;
    param_1[5] = iVar2;
    param_1[3] = 0;
  }
LAB_1400a1a32:
  dVar10 = dVar1;
  if (iVar2 == 2) {
    iVar2 = param_1[3];
    dVar10 = (double)FUN_140332d90(((double)iVar2 - 0.0) * DAT_14053ab08 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar10 = dVar10 * DAT_140539e60 + dVar1;
    if (iVar2 < 0x3d) {
      FUN_14007ac00(param_1);
    }
    if (param_1[3] == 0x3c) {
      uVar7 = param_1[1] + DAT_140e418c8;
      uVar6 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar6 = uVar6 * 0x800 ^ uVar6;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar6 = (DAT_140e9fd18 >> 0xb ^ uVar6) >> 8 ^ DAT_140e9fd18 ^ uVar6;
      DAT_140e9fd1c = uVar6;
      uVar11 = FUN_140134db0(uVar7,DAT_140539f28,DAT_140539f38);
      uVar9 = (undefined4)uVar11;
      uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar11 = FUN_140134db0(param_1[1] + DAT_140e418c8);
      FUN_140070d00(0x37,DAT_140e45090,0x15,param_1[10],param_1[0xb],
                    CONCAT22(uVar14,(short)uVar6 - (short)(uVar6 / 0x10001)),dVar1,uVar11,
                    CONCAT44(uVar12,uVar9),0x78,0xff,0xff,0xff,0x80,0);
      FUN_140079e20(param_1,2);
      bVar8 = DAT_1407c7798 == 8;
      *param_1 = 0;
      if (bVar8) {
        DAT_140e418cc = 0;
      }
    }
  }
  uVar12 = DAT_140e4499c;
  fVar13 = (float)param_1[0xb] - _DAT_14053ad8c;
  uVar9 = param_1[10];
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46cf0 = DAT_140e46cf0 + 1;
  bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar4[3] = uVar9;
  puVar4[4] = fVar13;
  *(double *)(puVar4 + 6) = dVar10;
  *puVar4 = uVar12;
  puVar4[1] = 0x18;
  puVar4[2] = 0x17;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 8) = 0x3ff8000000000000;
  *(undefined8 *)(puVar4 + 10) = 0;
  puVar4[0xc] = 0;
  puVar4[0xd] = 0x40;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar8) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar4;
  }
  uVar12 = DAT_140e4499c;
  fVar13 = (float)param_1[0xb] + DAT_14053ad50;
  uVar9 = param_1[10];
  DAT_140e46c88 = puVar4;
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46cf8 = DAT_140e46cf8 + 1;
  bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar4[3] = uVar9;
  puVar4[4] = fVar13;
  *(double *)(puVar4 + 6) = dVar10;
  *puVar4 = uVar12;
  *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
  puVar4[1] = 0x1a;
  puVar4[2] = 0xb;
  *(undefined2 *)(puVar4 + 5) = 0;
  puVar4[10] = 0xff;
  puVar4[0xb] = 0xff;
  puVar4[0xc] = 0xff;
  puVar4[0xd] = 0xff;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar8) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
  }
  DAT_140e46c88 = puVar4;
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if ((_DAT_14053afa0 <= (float)param_1[0xb]) && (bVar8 = DAT_1407c7798 == 8, *param_1 = 0, bVar8))
  {
    DAT_140e418cc = 0;
  }
  return;
}


