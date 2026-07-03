// Function: FUN_140093540 @ 140093540
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140093540(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffe78;
  undefined4 uVar21;
  undefined2 uVar22;
  uint in_stack_fffffffffffffe80;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined2 uVar26;
  undefined8 in_stack_fffffffffffffe90;
  undefined8 local_138;
  undefined8 uStack_130;
  int iStack_120;
  int iStack_11c;
  undefined8 local_118;
  
  dVar18 = DAT_14053a020;
  uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  uVar22 = (undefined2)((uint)in_stack_fffffffffffffe78 >> 0x10);
  local_138._0_4_ = 0;
  local_138 = 0;
  iStack_11c = 0;
  iVar9 = 0;
  if ((0 < DAT_140e44e6c) && (puVar3 = DAT_140e45d80, iVar9 = 0, DAT_140e45d80 != (undefined8 *)0x0)
     ) {
    do {
      if (*(int *)((longlong)puVar3 + 4) == param_1[2]) {
        local_138 = *puVar3;
        uStack_130 = puVar3[1];
        iStack_120 = *(int *)(puVar3 + 3);
        iStack_11c = *(int *)((longlong)puVar3 + 0x1c);
        local_118 = puVar3[4];
      }
      puVar3 = (undefined8 *)puVar3[0xc];
    } while (puVar3 != (undefined8 *)0x0);
    iVar9 = iStack_11c;
  }
  iVar10 = param_1[3];
  dVar12 = (double)FUN_140332d90(((double)iVar10 - 0.0) * _DAT_14053a730 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar24 = DAT_14053ae30;
  dVar1 = DAT_140539f40;
  uVar26 = (undefined2)(in_stack_fffffffffffffe80 >> 0x10);
  uVar11 = 0x4000;
  iVar2 = param_1[5];
  dVar12 = dVar12 * DAT_140539e60 + DAT_140539f40;
  if (iVar2 == 0) {
    uVar4 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar26 = (undefined2)(in_stack_fffffffffffffe80 >> 0x10);
    iVar7 = param_1[6];
    dVar13 = DAT_14053a018 - (double)iVar10 * DAT_140539e98;
    if (iVar7 - 0x3bU < 2) {
      param_1[8] = (undefined4)local_118;
      iVar2 = 1;
      param_1[7] = iVar9;
      param_1[5] = 1;
    }
    else {
      local_res8 = (undefined4)uVar4;
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      uStackX_c = (undefined4)((ulonglong)uVar4 >> 0x20);
      FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_fffffffffffffe80,dVar13,
                    dVar13,0xff,0xff,0xff,0xff,1,0);
      uVar26 = (undefined2)(in_stack_fffffffffffffe80 >> 0x10);
      uVar25 = (undefined4)((ulonglong)dVar13 >> 0x20);
      uVar22 = (undefined2)((uint)uStackX_c >> 0x10);
      iVar2 = param_1[5];
      uVar11 = 0x4000;
      iVar7 = param_1[6];
    }
    iVar10 = param_1[3];
    if (iVar10 == 0x14) {
      if (iVar7 == 0x39) {
        *(undefined2 *)(param_1 + 0x10) = uVar11;
      }
      else {
        uVar11 = *(undefined2 *)(param_1 + 0x10);
        if (iVar7 == 0x3a) {
          uVar11 = 0x9b58;
          if ((float)param_1[0xc] <= fVar24) {
            uVar11 = 0xe4a8;
          }
          *(undefined2 *)(param_1 + 0x10) = uVar11;
        }
      }
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar11;
      iVar2 = iVar2 + 1;
      param_1[0x15] = 0;
      *(undefined8 *)(param_1 + 0x12) = 0x4000000000000000;
      iVar10 = 0;
      param_1[3] = 0;
      param_1[5] = iVar2;
    }
  }
  if (iVar2 != 1) goto LAB_140093fec;
  sVar5 = 0;
  iVar2 = param_1[6];
  if ((iVar2 == 0x39) || ((iStack_120 == 0x39 && (iVar2 - 0x3bU < 2)))) {
    if (iVar10 < 0x78) {
      sVar5 = 0x14;
    }
    else {
      sVar5 = 0x28;
      if (iVar10 < 0xb4) {
        sVar5 = 100;
      }
    }
  }
  if (((iVar2 == 0x3a) || ((iStack_120 == 0x3a && (iVar2 - 0x3bU < 2)))) &&
     (sVar5 = 0x3c, iVar10 < 0xd2)) {
    sVar5 = -0x50;
  }
  sVar8 = -sVar5;
  if (fVar24 < (float)param_1[0xc]) {
    sVar8 = sVar5;
  }
  *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar8;
  dVar13 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar13 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar20;
  dVar13 = (double)FUN_140332d90();
  fVar24 = DAT_14053ac2c;
  fVar19 = (float)(dVar13 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar19;
  if ((((DAT_140e445d8 / DAT_14053ab70 - fVar24 <= fVar20) &&
       (fVar20 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec4)) && (DAT_14053b320 <= fVar19)) &&
     (fVar19 <= DAT_14053af1c)) {
    dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    dVar13 = dVar13 * DAT_14053aba0;
    uVar11 = (undefined2)(int)dVar13;
    if (iVar2 - 0x39U < 2) {
      iVar10 = 1;
      if (DAT_140e419b8 == 0) {
        iVar10 = 100;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 0x46;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar10 = 0x3c;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 0x28;
      }
      iVar2 = 1;
      if (DAT_140e419b8 == 0) {
        iVar2 = 5;
      }
      else if (DAT_140e419b8 == 1) {
LAB_140093978:
        iVar2 = 7;
      }
      else {
        if (DAT_140e419b8 != 2) {
          if (DAT_140e419b8 == 3) goto LAB_140093978;
          if (DAT_140e419b8 != 4) goto LAB_140093984;
        }
        iVar2 = 9;
      }
LAB_140093984:
      if ((-1 < (int)param_1[3]) && ((int)param_1[3] % iVar10 == 0)) {
        uVar4 = CONCAT44(uVar25,1);
        uVar21 = CONCAT22(uVar22,uVar11);
        fVar23 = fVar24;
        FUN_1400709b0(3,1,fVar20,fVar19,uVar21,fVar24,DAT_140539f68,uVar4,iVar2,22000,0);
        uVar26 = (undefined2)((uint)fVar23 >> 0x10);
        uVar25 = (undefined4)((ulonglong)uVar4 >> 0x20);
        uVar22 = (undefined2)((uint)uVar21 >> 0x10);
        if (2 < DAT_140e419b8) {
          uVar4 = CONCAT44(uVar25,1);
          uVar21 = CONCAT22(uVar22,uVar11);
          fVar23 = fVar24;
          FUN_1400709b0(3,1,fVar20,fVar19,uVar21,fVar24,DAT_140539ec8,uVar4,iVar2 - 1U,
                        (int)(22000 / (ulonglong)(iVar2 - 1U)) * (iVar2 + -2) & 0xffff,0);
          uVar26 = (undefined2)((uint)fVar23 >> 0x10);
          uVar25 = (undefined4)((ulonglong)uVar4 >> 0x20);
          uVar22 = (undefined2)((uint)uVar21 >> 0x10);
        }
      }
    }
    if (param_1[6] == 0x3b) {
      iVar10 = 1;
      if (DAT_140e419b8 == 0) {
        iVar10 = 0x58;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 0x37;
      }
      else if (DAT_140e419b8 == 2) {
        iVar10 = 0x2f;
      }
      else if (DAT_140e419b8 == 3) {
        iVar10 = 0x29;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 0x1f;
      }
      dVar14 = DAT_14053a088;
      if ((((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a0b0, DAT_140e419b8 != 1)) &&
          (dVar14 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
         ((dVar14 = DAT_14053a0f8, DAT_140e419b8 != 3 && (dVar14 = dVar1, DAT_140e419b8 == 4)))) {
        dVar14 = DAT_14053a160;
      }
      if ((-1 < uStack_130) && ((int)((longlong)uStack_130._4_4_ % (longlong)iVar10) == 0)) {
        uVar4 = CONCAT44(uVar25,1);
        fVar23 = fVar24;
        FUN_14006c2f0(8,(longlong)uStack_130._4_4_ % (longlong)iVar10 & 0xffffffff,fVar20,fVar19,
                      CONCAT22(uVar22,uVar11),fVar24,dVar14,uVar4,0);
        uVar26 = (undefined2)((uint)fVar23 >> 0x10);
        uVar25 = (undefined4)((ulonglong)uVar4 >> 0x20);
        if (2 < DAT_140e419b8) {
          uVar4 = CONCAT44(uVar25,1);
          FUN_14006c2f0(8,0,fVar20,fVar19,(int)dVar13 & 0xffff,fVar24,dVar14 + DAT_140539fb8,uVar4,0
                       );
          uVar26 = (undefined2)((uint)fVar24 >> 0x10);
          uVar25 = (undefined4)((ulonglong)uVar4 >> 0x20);
        }
      }
    }
  }
  if (param_1[6] - 0x39 < 2) {
    uVar6 = param_1[3] - 0x28;
    if ((uVar6 < 0x140) && (uVar6 == ((int)uVar6 / 0x28) * 0x28)) {
      uVar4 = CONCAT44(uVar25,0x28);
      uVar25 = CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42));
      stage_entity_spawn_candidate
                (0x3b,param_1[8],5,param_1[0xc],param_1[0xd],uVar25,*(undefined8 *)(param_1 + 0x12),
                 uVar4,0,param_1[1]);
      uVar26 = (undefined2)((uint)uVar25 >> 0x10);
      uVar25 = (undefined4)((ulonglong)uVar4 >> 0x20);
    }
    if (param_1[3] == 0x168) {
      uVar21 = CONCAT22(uVar26,*(undefined2 *)((longlong)param_1 + 0x42));
      stage_entity_spawn_candidate
                (0x3c,param_1[8],10,param_1[0xc],param_1[0xd],uVar21,*(undefined8 *)(param_1 + 0x12)
                 ,CONCAT44(uVar25,0x28),0,param_1[1]);
      uVar26 = (undefined2)((uint)uVar21 >> 0x10);
    }
  }
  if (param_1[6] - 0x3b < 2) {
    iVar10 = param_1[7];
    if (iVar10 < iVar9) {
      iVar2 = param_1[2];
      puVar3 = DAT_140e45d80;
      if (0 < DAT_140e44e6c) {
        for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
          if (*(int *)((longlong)puVar3 + 4) == iVar2) {
            *(int *)((longlong)puVar3 + 0x1c) = *(int *)((longlong)puVar3 + 0x1c) - (iVar9 - iVar10)
            ;
          }
        }
      }
    }
    iVar10 = param_1[7];
    if (iVar9 < iVar10) {
      param_1[7] = iVar9;
      iVar10 = iVar9;
    }
    if ((iVar10 < 1) && (iVar10 = param_1[2], puVar3 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
        if (*(int *)((longlong)puVar3 + 4) == iVar10) {
          *(int *)((longlong)puVar3 + 0x1c) = *(int *)((longlong)puVar3 + 0x1c) - iVar9;
        }
      }
    }
    if (iVar9 < 1) {
      param_1[0x15] = 1;
      param_1[3] = 100 - ((int)((uStack_130._4_4_ - param_1[3]) +
                               (uStack_130._4_4_ - param_1[3] >> 0x1f & 7U)) >> 3);
      goto LAB_140093d43;
    }
  }
  else if ((int)param_1[7] < 1) {
    param_1[0x15] = 1;
    FUN_14007b010(param_1,1000,10);
    FUN_140079e20(param_1,1);
LAB_140093d43:
    param_1[5] = param_1[5] + 1;
  }
  if (param_1[6] - 0x39 < 2) {
    sVar5 = *(short *)(param_1 + 0x10);
    dVar14 = (double)FUN_1403307c0();
    dVar13 = DAT_14053a340;
    dVar14 = dVar14 * DAT_14053a340;
    fVar24 = (float)param_1[10];
    dVar15 = (double)FUN_140332d90();
    fVar19 = (float)param_1[0xb];
    dVar16 = (double)FUN_1403307c0();
    fVar20 = (float)param_1[10];
    dVar17 = (double)FUN_140332d90();
    fVar23 = (float)param_1[0xb];
    dVar18 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053a7c0 * dVar18 *
                                   DAT_140539d28);
    sVar8 = (short)(int)(dVar18 * _DAT_14053aa40);
    uVar25 = CONCAT22(uVar26,sVar5 + sVar8 + 0x4000);
    FUN_1400c8410(DAT_140e44be4,0x1d,7,(float)dVar14 + fVar24,(float)(dVar15 * dVar13) + fVar19,
                  uVar25,dVar1,dVar12,0xff,0xff,0xff,0xff,1,0);
    uVar25 = CONCAT22((short)((uint)uVar25 >> 0x10),(*(short *)(param_1 + 0x10) - sVar8) + 0x4000);
    FUN_1400c8410(DAT_140e44be4,0x1d,7,(float)(dVar16 * dVar13) + fVar20,
                  (float)(dVar17 * dVar13) + fVar23,uVar25,dVar1,dVar12,0xff,0xff,0xff,0xff,1,1);
    uVar25 = CONCAT22((short)((uint)uVar25 >> 0x10),*(undefined2 *)(param_1 + 0x10));
    FUN_1400c8410(DAT_140e44be0,0x1d,7,param_1[10],param_1[0xb],uVar25,dVar1,dVar12,0xff,0xff,0xff,
                  0xff,1,0);
    uVar26 = (undefined2)((uint)uVar25 >> 0x10);
    FUN_140079c10(param_1,1);
  }
LAB_140093fec:
  if (((param_1[5] == 2) && (param_1[6] - 0x3b < 2)) && (param_1[3] == 100)) {
    FUN_14007b010(param_1,1000,1);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (param_1[6] == 0x3b) {
    uVar25 = CONCAT22(uVar26,*(undefined2 *)(param_1 + 0x10));
    FUN_1400c8410(DAT_140e44be8,0x1c,7,param_1[10],param_1[0xb],uVar25,dVar1,dVar12,0xff,0xff,0xff,
                  0xff,1,0);
    uVar26 = (undefined2)((uint)uVar25 >> 0x10);
  }
  if (param_1[6] == 0x3c) {
    uVar22 = *(undefined2 *)(param_1 + 0x10);
    dVar18 = (double)FUN_1403307c0();
    dVar18 = dVar18 * _DAT_14053a358;
    fVar24 = (float)param_1[10];
    dVar13 = (double)FUN_140332d90();
    FUN_1400c8410(DAT_140e44bec,0x1c,7,(float)dVar18 + fVar24,
                  (float)(dVar13 * _DAT_14053a358) + (float)param_1[0xb],CONCAT22(uVar26,uVar22),
                  dVar1,dVar12,0xff,0xff,0xff,0xff,1,0);
  }
  if ((param_1[3] == 1000) || ((param_1[6] - 0x3b < 2 && ((int)local_138 == 0)))) {
    *param_1 = 0;
  }
  return;
}


