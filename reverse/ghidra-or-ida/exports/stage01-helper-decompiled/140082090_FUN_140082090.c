// Function: FUN_140082090 @ 140082090
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140082090(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  short sVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 in_stack_fffffffffffffe98;
  undefined2 uVar29;
  undefined4 in_stack_fffffffffffffea0;
  undefined4 uVar30;
  undefined2 uVar31;
  undefined8 local_128;
  undefined8 uStack_110;
  undefined8 uStack_100;
  ushort uVar5;
  
  uVar29 = (undefined2)((uint)in_stack_fffffffffffffe98 >> 0x10);
  uVar31 = (undefined2)((uint)in_stack_fffffffffffffea0 >> 0x10);
  local_128._0_4_ = 0;
  iVar15 = 0;
  local_128 = 0;
  uStack_110 = 0;
  uStack_110._4_4_ = iVar15;
  if ((0 < DAT_140e44e6c) && (puVar7 = DAT_140e45d80, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar7 + 4) == param_1[2]) {
        local_128 = *puVar7;
        uStack_110 = puVar7[3];
        uStack_100 = puVar7[5];
      }
      puVar7 = (undefined8 *)puVar7[0xc];
    } while (puVar7 != (undefined8 *)0x0);
  }
  fVar25 = (float)param_1[0xb];
  fVar26 = (float)param_1[10];
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                 SUB84((double)(DAT_140e445d8 - fVar26),0));
  dVar19 = dVar19 * DAT_14053aba0;
  fVar18 = (float)param_1[0xd];
  fVar17 = (float)param_1[0xc];
  FUN_1403300b4((double)((uStack_100._4_4_ + fVar18) - fVar25),
                SUB84((double)(((float)uStack_100 + fVar17) - fVar26),0));
  dVar21 = DAT_14053a020;
  fVar17 = (float)FUN_140334430(fVar26 - ((float)uStack_100 + fVar17),DAT_140539fc0);
  fVar18 = (float)FUN_140334430(fVar25 - (uStack_100._4_4_ + fVar18));
  if (fVar17 + fVar18 < 0.0) {
    fVar18 = (float)FUN_1403352f8();
  }
  else {
    fVar18 = SQRT(fVar17 + fVar18);
  }
  dVar22 = (double)fVar18 / DAT_14053a278;
  dVar20 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar20 * dVar22) + fVar26;
  dVar20 = (double)FUN_140332d90();
  param_1[0xb] = (float)(dVar20 * dVar22) + fVar25;
  dVar20 = DAT_14053a4d8;
  if (param_1[5] != 0) {
    if (param_1[5] != 1) {
LAB_140082d52:
      uVar27 = SUB84(DAT_140539f40,0);
      uVar28 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      goto LAB_140082888;
    }
LAB_1400823ba:
    uVar2 = param_1[3];
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar13 = uVar1;
    if ((int)uVar2 < 300) {
      dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_100._4_4_),
                                     SUB84((double)(DAT_140e445d8 - (float)uStack_100),0));
      uVar4 = (ushort)(int)(dVar21 * DAT_14053aba0);
      iVar9 = ((int)(dVar21 * DAT_14053aba0) & 0xffffU) - (uint)uVar1;
      iVar15 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar15 = iVar9;
      }
      iVar9 = iVar15 + -0x10000;
      if (iVar15 < 0x8001) {
        iVar9 = iVar15;
      }
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar13 = uVar1 - 0x20, -0x20 < iVar9)) {
          uVar13 = uVar4;
        }
        *(ushort *)(param_1 + 0x10) = uVar13;
      }
      else {
        uVar13 = uVar4;
        if (0x1f < iVar9) {
          uVar13 = uVar1 + 0x20;
        }
        *(ushort *)(param_1 + 0x10) = uVar13;
      }
    }
    else {
      uVar5 = (ushort)(int)dVar19;
      uVar4 = uVar5 - uVar1;
      uVar10 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar10 = 0x10000 - uVar4;
      }
      iVar9 = ((int)dVar19 & 0xffffU) - (uint)uVar1;
      iVar14 = (int)uVar10 / 0x14 + 1;
      iVar15 = iVar9 + 0x10000;
      if (-0x8001 < iVar9) {
        iVar15 = iVar9;
      }
      iVar9 = iVar15 + -0x10000;
      if (iVar15 < 0x8001) {
        iVar9 = iVar15;
      }
      if (iVar9 < 1) {
        if ((iVar9 < 0) && (uVar13 = uVar1 - (short)iVar14, -iVar14 < iVar9)) {
          uVar13 = uVar5;
        }
      }
      else {
        uVar13 = uVar5;
        if (iVar14 <= iVar9) {
          uVar13 = uVar1 + (short)iVar14;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar13;
      if (899 < (int)uVar2) {
        uVar27 = SUB84(DAT_140539f40,0);
        uVar28 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
        goto LAB_140082888;
      }
    }
    dVar21 = (double)FUN_1403307c0();
    fVar25 = (float)(dVar21 * DAT_14053a3d0) + (float)param_1[10];
    dVar21 = (double)FUN_140332d90();
    uVar3 = DAT_14053ac2c;
    iVar15 = 1;
    fVar26 = (float)(dVar21 * DAT_14053a3d0) + (float)param_1[0xb];
    if (DAT_140e419b8 == 0) {
      iVar15 = 0x3c;
    }
    else if (DAT_140e419b8 == 1) {
      iVar15 = 0x20;
    }
    else if (DAT_140e419b8 == 2) {
      iVar15 = 0x18;
    }
    else if (DAT_140e419b8 == 3) {
      iVar15 = 0x14;
    }
    else if (DAT_140e419b8 == 4) {
      iVar15 = 0x10;
    }
    uVar27 = SUB84(DAT_140539f40,0);
    uVar28 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    uVar23 = SUB84(DAT_14053a0b0,0);
    uVar24 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    dVar21 = DAT_14053a040;
    if ((((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a088, DAT_140e419b8 != 1)) &&
        (dVar21 = DAT_14053a0b0, DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 != 3 && (dVar21 = DAT_140539f40, DAT_140e419b8 == 4)))) {
      dVar21 = DAT_14053a118;
    }
    iVar9 = 1;
    if (DAT_140e419b8 == 0) {
      iVar9 = 100;
    }
    else if (DAT_140e419b8 == 1) {
      iVar9 = 0x50;
    }
    else if (DAT_140e419b8 == 2) {
      iVar9 = 0x46;
    }
    else if (DAT_140e419b8 == 3) {
      iVar9 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar9 = 0x32;
    }
    iVar14 = 1;
    if ((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) {
      if (DAT_140e419b8 == 2) {
        iVar14 = 2;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar14 = 3;
      }
    }
    if (DAT_140e419b8 == 0) {
      uVar23 = (undefined4)DAT_14053a018;
      uVar24 = (undefined4)((ulonglong)DAT_14053a018 >> 0x20);
    }
    else if (DAT_140e419b8 != 1) {
      if (DAT_140e419b8 == 2) {
        uVar23 = (undefined4)DAT_14053a0f8;
        uVar24 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 3) {
        uVar23 = (undefined4)DAT_14053a138;
        uVar24 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
      else {
        uVar23 = uVar27;
        uVar24 = uVar28;
        if (DAT_140e419b8 == 4) {
          uVar23 = (undefined4)DAT_14053a190;
          uVar24 = (undefined4)((ulonglong)DAT_14053a190 >> 0x20);
        }
      }
    }
    if ((uVar2 < 300) && ((int)uVar2 % iVar15 == 0)) {
      sVar6 = FUN_140134d00(uVar2,uVar2 * -0x10,uVar2 << 4);
      sVar6 = uVar13 + sVar6;
      FUN_14006c2f0(7,0,fVar25,fVar26,CONCAT22(uVar29,sVar6),uVar3,dVar21,1,0);
      uVar30 = uVar3;
      FUN_14006c2f0(7,0,fVar25,fVar26,sVar6,uVar3,dVar21 + DAT_140539ee0,1,0);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
      if (2 < DAT_140e419b8) {
        FUN_14006c2f0(7,0,fVar25,fVar26,sVar6,uVar3,dVar21 + DAT_140539fc8,1,0);
        uVar30 = uVar3;
        FUN_14006c2f0(7,0,fVar25,fVar26,sVar6,uVar3,dVar21 + _DAT_140539fe0,1,0);
        uVar31 = (undefined2)((uint)uVar30 >> 0x10);
      }
    }
    dVar21 = DAT_140539ef8;
    iVar15 = 0;
    iVar12 = 0;
    if (((param_1[3] - 0x186 < 0x1fe) && (iVar11 = (param_1[3] + -0x186) % iVar9, iVar11 < 0x19)) &&
       (iVar11 == (iVar11 / 3 + (iVar11 >> 0x1f) +
                  (int)(((longlong)iVar11 / 3 + ((longlong)iVar11 >> 0x3f) & 0xffffffffU) >> 0x1f))
                  * 3)) {
      dVar19 = (double)((int)(uVar2 - 0x186) % iVar9) * DAT_140539ec8;
      do {
        uVar30 = uVar3;
        FUN_1400709b0(9,0,fVar25,fVar26,*(undefined2 *)(param_1 + 0x10),uVar3,
                      (dVar19 + (double)CONCAT44(uVar24,uVar23)) - (double)iVar12 * dVar21,1,2,
                      iVar15,0);
        uVar31 = (undefined2)((uint)uVar30 >> 0x10);
        iVar12 = iVar12 + 1;
        iVar15 = iVar15 + 1000;
      } while (iVar12 < iVar14);
    }
    goto LAB_140082888;
  }
  iVar9 = param_1[3];
  fVar25 = (float)param_1[0xe];
  if (iVar9 == 0) {
    param_1[10] = (float)uStack_100;
    param_1[0xb] = uStack_100._4_4_;
LAB_1400822d2:
    uVar27 = SUB84(DAT_140539d28,0);
    uVar28 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    dVar19 = (double)FUN_140332d90(((double)iVar9 - 0.0) * dVar20 * dVar21 * DAT_140539d28);
    iVar12 = (int)(float)param_1[0xf];
    param_1[0xc] = (float)(int)(dVar19 * (double)(int)fVar25);
  }
  else {
    iVar14 = iVar15;
    if ((-1 < iVar9) && (iVar14 = (int)fVar25, iVar9 < 0x78)) goto LAB_1400822d2;
    iVar12 = (int)(float)param_1[0xf];
    if (iVar9 >= 0) {
      iVar15 = iVar12;
    }
    param_1[0xc] = (float)iVar14;
    if ((iVar9 < 0) || (0x77 < iVar9)) {
      param_1[0xd] = (float)iVar15;
      if (iVar9 != 0x78) goto LAB_140082d52;
      param_1[0x15] = 0;
      param_1[3] = 0;
      param_1[5] = 1;
      goto LAB_1400823ba;
    }
    uVar27 = SUB84(DAT_140539d28,0);
    uVar28 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  }
  dVar21 = (double)FUN_140332d90(((double)iVar9 - 0.0) * dVar20 * dVar21 *
                                 (double)CONCAT44(uVar28,uVar27));
  uVar27 = SUB84(DAT_140539f40,0);
  uVar28 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  param_1[0xd] = (float)(int)(dVar21 * (double)iVar12);
LAB_140082888:
  dVar21 = (double)FUN_1403307c0();
  dVar21 = dVar21 * DAT_14053a2d8;
  fVar25 = (float)param_1[10];
  dVar19 = (double)FUN_140332d90();
  dVar19 = dVar19 * DAT_14053a2d8;
  fVar26 = (float)param_1[0xb];
  dVar20 = (double)FUN_1403307c0();
  fVar17 = (float)(dVar20 * _DAT_14053a4a8) + (float)param_1[10];
  dVar20 = (double)FUN_140332d90();
  uVar3 = DAT_140e44b54;
  sVar6 = *(short *)(param_1 + 3);
  fVar18 = (float)(dVar20 * _DAT_14053a4a8) + (float)param_1[0xb];
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  puVar8[3] = fVar17;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[4] = fVar18;
  *puVar8 = uVar3;
  puVar8[1] = 0x23;
  puVar8[2] = 7;
  *(short *)(puVar8 + 5) = sVar6 * 2000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar8;
  }
  uVar3 = DAT_140e44b54;
  sVar6 = *(short *)(param_1 + 3);
  DAT_140e46c88 = puVar8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar8 = uVar3;
  puVar8[1] = 0x23;
  puVar8[2] = 7;
  puVar8[3] = fVar17;
  puVar8[4] = fVar18;
  *(short *)(puVar8 + 5) = sVar6 * 2000 + 0x5555;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  uVar3 = DAT_140e44b54;
  sVar6 = *(short *)(param_1 + 3);
  DAT_140e46c88 = puVar8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar8 = uVar3;
  puVar8[1] = 0x23;
  puVar8[2] = 7;
  puVar8[3] = fVar17;
  puVar8[4] = fVar18;
  *(short *)(puVar8 + 5) = sVar6 * 2000 + -0x5556;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  uVar3 = DAT_140e44b50;
  uVar29 = *(undefined2 *)(param_1 + 0x10);
  DAT_140e46c88 = puVar8;
  puVar8 = (undefined4 *)_malloc_base(0x48);
  if (puVar8 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46d10 = DAT_140e46d10 + 1;
  bVar16 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar8[3] = (float)dVar21 + fVar25;
  puVar8[4] = (float)dVar19 + fVar26;
  *puVar8 = uVar3;
  puVar8[1] = 0x20;
  puVar8[2] = 7;
  *(undefined2 *)(puVar8 + 5) = uVar29;
  *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
  puVar8[10] = 0xff;
  puVar8[0xb] = 0xff;
  puVar8[0xc] = 0xff;
  puVar8[0xd] = 0xff;
  *(undefined8 *)(puVar8 + 0xe) = 1;
  *(undefined8 *)(puVar8 + 0x10) = 0;
  if (bVar16) {
    DAT_140e46bf0 = puVar8;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
  }
  DAT_140e46c88 = puVar8;
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x4b0,10);
    FUN_140079e20(param_1,1);
    stage_entity_spawn_candidate
              (0x153,(int)param_1[8] / 2,1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar31,0x4000),
               CONCAT44(uVar28,uVar27),10,1,param_1[2]);
    iVar15 = param_1[2];
    puVar7 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)puVar7[0xc]) {
        if (*(int *)((longlong)puVar7 + 4) == iVar15) {
          *(int *)((longlong)puVar7 + 0x5c) = *(int *)((longlong)puVar7 + 0x5c) + -1;
        }
      }
    }
    *param_1 = 0;
  }
  if (uStack_110._4_4_ < 1) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((int)local_128 == 0) {
    *param_1 = 0;
  }
  return;
}


