// Function: FUN_14005dd50 @ 14005dd50
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005dd50(undefined4 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined8 *puVar14;
  undefined2 uVar15;
  int iVar16;
  short sVar17;
  int iVar18;
  int iVar19;
  longlong lVar20;
  bool bVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  int iVar26;
  float fVar27;
  float fVar28;
  short local_res8 [4];
  undefined2 uVar29;
  undefined4 uVar30;
  undefined2 uVar31;
  undefined8 in_stack_fffffffffffffe00;
  undefined4 uVar32;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined4 local_1a8;
  undefined4 uStack_18c;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined4 local_168;
  undefined4 local_158;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  
  uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffe00 >> 0x20);
  local_1a8 = 0;
  uStack_18c = 0;
  if ((DAT_140e44e6c < 1) || (DAT_140e45d80 == 0)) {
    iVar26 = 0;
  }
  else {
    iVar26 = 0;
    lVar20 = DAT_140e45d80;
    do {
      if (*(int *)(lVar20 + 4) == param_1[2]) {
        local_188 = *(undefined8 *)(lVar20 + 0x20);
        uStack_180 = *(undefined8 *)(lVar20 + 0x28);
        iVar26 = *(int *)(lVar20 + 0x1c);
        local_168 = *(undefined4 *)(lVar20 + 0x40);
        local_158 = *(undefined4 *)(lVar20 + 0x50);
      }
      lVar20 = *(longlong *)(lVar20 + 0x60);
      param_3 = local_158;
      param_4 = local_168;
    } while (lVar20 != 0);
  }
  iVar18 = param_1[1] - DAT_1407c77a0;
  fVar28 = (float)param_1[0xd];
  fVar27 = (float)param_1[0xb];
  fVar1 = (float)param_1[0xc];
  fVar2 = (float)param_1[10];
  local_1c8 = _DAT_14053bfa0;
  uStack_1c0 = _UNK_14053bfa8;
  uVar31 = 0;
  local_1b8 = _DAT_14053bf50;
  uStack_1b0 = _UNK_14053bf58;
  uVar29 = 0;
  local_140 = _DAT_14053b540;
  uStack_138 = _UNK_14053b548;
  local_130 = _DAT_14053bfc0;
  uStack_128 = _UNK_14053bfc8;
  iVar11 = FUN_1400c9580(DAT_140e418c8,0,param_3,param_4,0xa6,0xa7,0xa8);
  fVar22 = (float)FUN_140334430(fVar2 - fVar1);
  fVar23 = (float)FUN_140334430(fVar27 - fVar28);
  if (fVar22 + fVar23 < 0.0) {
    fVar22 = (float)FUN_1403352f8();
  }
  else {
    fVar22 = SQRT(fVar22 + fVar23);
  }
  dVar7 = DAT_14053a0b0;
  dVar25 = (double)fVar22 / DAT_14053a0b0;
  *(double *)(param_1 + 0x12) = dVar25;
  FUN_1403300b4((double)(fVar28 - fVar27),(double)(fVar1 - fVar2));
  dVar24 = (double)FUN_1403307c0();
  fVar28 = (float)(dVar24 * dVar25) + (float)param_1[10];
  param_1[10] = fVar28;
  dVar24 = (double)FUN_140332d90();
  uVar4 = *(ushort *)(param_1 + 0x10);
  uVar5 = *(ushort *)((longlong)param_1 + 0x42);
  uVar10 = uVar4 - uVar5;
  uVar13 = (uint)uVar10;
  if (0x8000 < uVar10) {
    uVar13 = 0x10000 - uVar10;
  }
  iVar16 = (uint)uVar5 - (uint)uVar4;
  fVar27 = (float)(dVar24 * dVar25) + (float)param_1[0xb];
  iVar19 = (int)uVar13 / 10 + 0x80;
  param_1[0xb] = fVar27;
  iVar12 = iVar16 + 0x10000;
  if (-0x8001 < iVar16) {
    iVar12 = iVar16;
  }
  iVar16 = iVar12 + -0x10000;
  if (iVar12 < 0x8001) {
    iVar16 = iVar12;
  }
  if (iVar16 < 1) {
    uVar10 = uVar4;
    if ((iVar16 < 0) && (uVar10 = uVar4 - (short)iVar19, -iVar19 < iVar16)) {
      uVar10 = uVar5;
    }
  }
  else {
    uVar10 = uVar5;
    if (iVar19 <= iVar16) {
      uVar10 = uVar4 + (short)iVar19;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar10;
  dVar25 = (double)FUN_1403307c0();
  fVar22 = (float)(dVar25 * DAT_14053a240) + fVar28;
  dVar25 = (double)FUN_140332d90();
  fVar2 = uStack_180._4_4_;
  fVar1 = (float)uStack_180;
  fVar23 = (float)(dVar25 * DAT_14053a240) + fVar27;
  if (param_1[5] == 0) {
    if (param_1[3] == 0) {
      param_1[10] = (float)uStack_180;
      param_1[0xb] = uStack_180._4_4_;
      fVar27 = uStack_180._4_4_;
      fVar28 = (float)uStack_180;
    }
    fVar3 = *(float *)((longlong)&local_1c8 + (longlong)iVar18 * 8 + 4);
    param_1[0xc] = (float)uStack_180 + *(float *)(&local_1c8 + iVar18);
    param_1[0xd] = uStack_180._4_4_ + fVar3;
    if (param_1[3] != 0x28) goto LAB_14005e2ec;
    param_1[3] = 0;
    param_1[5] = 1;
  }
  else if (param_1[5] != 1) goto LAB_14005e2ec;
  dVar25 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar27),(double)(DAT_140e445d8 - fVar28));
  uVar9 = _UNK_14053c598;
  uVar8 = _DAT_14053c590;
  lVar20 = (longlong)iVar18;
  uVar15 = (undefined2)(int)(dVar25 * DAT_14053aba0);
  if ((int)param_1[3] < 0x28) {
    fVar28 = *(float *)(&local_1c8 + lVar20);
    fVar27 = *(float *)((longlong)&local_1c8 + lVar20 * 8 + 4);
    *(undefined2 *)((longlong)param_1 + 0x42) = uVar15;
    param_1[0xc] = fVar1 + fVar28;
    param_1[0xd] = fVar2 + fVar27;
  }
  else {
    iVar18 = (param_1[3] + -0x28) % 0x4b0;
    if (iVar18 < 0x1a4) {
      fVar28 = *(float *)(&local_1c8 + lVar20);
      fVar27 = *(float *)((longlong)&local_1c8 + lVar20 * 8 + 4);
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar15;
      param_1[0xc] = fVar1 + fVar28;
      param_1[0xd] = fVar2 + fVar27;
      if ((0x17b < iVar18 - 0x14U) ||
         ((iVar18 = (int)(iVar18 - 0x14U) % 0x23, 0x13 < iVar18 ||
          (dVar25 = DAT_14053a178, iVar18 != (iVar18 / 5) * 5)))) goto LAB_14005e2ec;
    }
    else {
      fVar28 = *(float *)((longlong)&local_140 + lVar20 * 8 + 4);
      local_res8[0] = -0x8000;
      local_res8[1] = 0;
      local_res8[2] = -0x8000;
      local_res8[3] = 0;
      sVar17 = local_res8[lVar20];
      param_1[0xc] = fVar1 + *(float *)(&local_140 + lVar20);
      param_1[0xd] = fVar2 + fVar28;
      local_1c8 = uVar8;
      uStack_1c0 = uVar9;
      if (0x1c1 < iVar18) {
        sVar17 = sVar17 + *(short *)((longlong)&local_1c8 + lVar20 * 4) * ((short)iVar18 + -0x1c2);
      }
      uVar13 = iVar18 - 0x1c2;
      *(short *)((longlong)param_1 + 0x42) = sVar17;
      if ((0x2c5 < uVar13) ||
         (dVar25 = dVar7,
         uVar13 != ((int)uVar13 / 3 + ((int)uVar13 >> 0x1f) +
                   (int)(((longlong)(int)uVar13 / 3 + ((longlong)(int)uVar13 >> 0x3f) & 0xffffffffU)
                        >> 0x1f)) * 3)) goto LAB_14005e2ec;
    }
    uVar30 = DAT_14053ac2c;
    FUN_14006c2f0(10,1,fVar22,fVar23,CONCAT22(uVar29,uVar10),DAT_14053ac2c,dVar25,CONCAT44(uVar32,1)
                  ,0);
    uVar31 = (undefined2)((uint)uVar30 >> 0x10);
    FUN_140184700(DAT_140e44190 * 9,DAT_140e472a8);
    FUN_14018a340(DAT_140e472a8,1,1);
  }
LAB_14005e2ec:
  FUN_1400c8410((&DAT_140e44660)[iVar11],0x1c,7,param_1[10],param_1[0xb],
                CONCAT22(uVar31,*(undefined2 *)(param_1 + 0x10)),_DAT_14053bb20,_UNK_14053bb28,0xff,
                0xff,0xff,0xff,1,0);
  puVar14 = DAT_140e45d28;
  if (dVar7 <= *(double *)(param_1 + 0x12)) {
    uVar13 = DAT_140e418c8 & 0x80000001;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffffe) + 1;
    }
    if (uVar13 == 0) {
      uVar29 = *(undefined2 *)(param_1 + 0x10);
      uVar32 = param_1[0xb];
      uVar30 = param_1[10];
      uVar6 = (&DAT_140e44660)[iVar11];
      if (DAT_140e45d1c < 0x1000) {
        puVar14 = (undefined8 *)_malloc_base(0x60);
        if (puVar14 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar21 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar14 + 0x14) = uVar30;
        *(undefined4 *)(puVar14 + 3) = uVar32;
        *(undefined4 *)((longlong)puVar14 + 0x1c) = uVar30;
        *(undefined4 *)(puVar14 + 4) = uVar32;
        *puVar14 = 1;
        *(undefined4 *)(puVar14 + 1) = 5;
        *(undefined4 *)((longlong)puVar14 + 0xc) = uVar6;
        *(undefined4 *)(puVar14 + 2) = 0x1b;
        *(undefined2 *)((longlong)puVar14 + 0x24) = uVar29;
        puVar14[5] = 0;
        puVar14[6] = 0x3ff0000000000000;
        puVar14[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar14 + 8) = 0x10;
        *(undefined4 *)((longlong)puVar14 + 0x44) = 0xff;
        *(undefined4 *)(puVar14 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar14 + 0x4c) = 0xff;
        puVar14[10] = 0x60;
        puVar14[0xb] = 0;
        if (bVar21) {
          DAT_140e45d78 = puVar14;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar14;
        }
      }
    }
  }
  DAT_140e45d28 = puVar14;
  if ((iVar26 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


