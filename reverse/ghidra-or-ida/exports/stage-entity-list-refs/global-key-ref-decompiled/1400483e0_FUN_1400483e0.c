// Function: FUN_1400483e0 @ 1400483e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400483e0(undefined4 *param_1)

{
  ushort uVar1;
  double dVar2;
  ushort uVar3;
  int iVar5;
  undefined8 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  float fVar12;
  undefined4 in_stack_fffffffffffffee8;
  undefined2 uVar13;
  undefined4 in_stack_fffffffffffffef0;
  undefined2 uVar14;
  ulonglong uVar15;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 uStack_90;
  undefined8 local_78;
  undefined4 uStack_64;
  ushort uVar4;
  
  uVar14 = (undefined2)((uint)in_stack_fffffffffffffef0 >> 0x10);
  uVar13 = (undefined2)((uint)in_stack_fffffffffffffee8 >> 0x10);
  iVar10 = 0;
  local_b8 = 0;
  local_b8._0_4_ = 0;
  if ((0 < DAT_140e44e6c) &&
     (puVar6 = DAT_140e45d80, local_b8._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar6 + 4) == param_1[2]) {
        local_b8 = *puVar6;
        uStack_b0 = puVar6[1];
        uStack_64 = *(undefined4 *)((longlong)puVar6 + 0x54);
        uStack_90 = puVar6[5];
        local_78 = puVar6[8];
      }
      puVar6 = (undefined8 *)puVar6[0xc];
    } while (puVar6 != (undefined8 *)0x0);
  }
  param_1[0x15] = uStack_64;
  uVar11 = SUB84((double)(ushort)((short)local_78 + *(short *)(param_1 + 0x11)) * DAT_14053a020 *
                 DAT_140539d28,0);
  dVar2 = (double)FUN_1403307c0(uVar11);
  fVar12 = (float)(dVar2 * _DAT_14053a540) + (float)uStack_90;
  dVar2 = (double)FUN_140332d90(uVar11);
  dVar2 = dVar2 * _DAT_14053a540;
  param_1[10] = fVar12;
  uStack_90._4_4_ = (float)dVar2 + uStack_90._4_4_;
  param_1[0xb] = uStack_90._4_4_;
  uStack_b0._4_4_ = uStack_b0._4_4_ % 300;
  dVar2 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - uStack_90._4_4_),0),
                                SUB84((double)(DAT_140e445d8 - fVar12),0));
  dVar2 = dVar2 * DAT_14053aba0;
  if (uStack_b0._4_4_ == 1) {
    uVar11 = CONCAT22(uVar14,*(undefined2 *)(param_1 + 0x10));
    FUN_140070d00(0x41,DAT_140e41a90,0x50,fVar12,uStack_90._4_4_,uVar11,0,_DAT_14053bae0,
                  _UNK_14053bae8,100,0xff,0xff,0xff,0x80,param_1[1]);
    uVar14 = (undefined2)((uint)uVar11 >> 0x10);
    uVar13 = (undefined2)((uint)uStack_90._4_4_ >> 0x10);
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
    FUN_14018a340(DAT_140e472c0,1,1);
    *(short *)(param_1 + 0x10) = (short)local_78;
  }
  else if (0x31 < uStack_b0._4_4_) goto LAB_14004867e;
  uVar1 = *(ushort *)(param_1 + 0x10);
  uVar4 = (ushort)(int)dVar2;
  uVar3 = uVar4 - uVar1;
  uVar7 = (uint)uVar3;
  if (0x8000 < uVar3) {
    uVar7 = 0x10000 - uVar3;
  }
  iVar8 = ((int)dVar2 & 0xffffU) - (uint)uVar1;
  iVar9 = (int)uVar7 / 0x14 + 0x30;
  iVar5 = iVar8 + 0x10000;
  if (-0x8001 < iVar8) {
    iVar5 = iVar8;
  }
  iVar8 = iVar5 + -0x10000;
  if (iVar5 < 0x8001) {
    iVar8 = iVar5;
  }
  if (iVar8 < 1) {
    uVar3 = uVar1;
    if ((iVar8 < 0) && (uVar3 = uVar1 - (short)iVar9, -iVar9 < iVar8)) {
      uVar3 = uVar4;
    }
  }
  else {
    uVar3 = uVar4;
    if (iVar9 <= iVar8) {
      uVar3 = uVar1 + (short)iVar9;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar3;
LAB_14004867e:
  if ((uStack_b0._4_4_ - 100U < 200) &&
     (iVar5 = uStack_b0._4_4_ + -100,
     iVar5 == (iVar5 / 3 + (iVar5 >> 0x1f) +
              (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 3))
  {
    iVar5 = 0;
    if (0x9f < uStack_b0._4_4_) {
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          iVar10 = 0x1e;
        }
        else if (DAT_140e419b8 == 2) {
          iVar10 = 0x32;
        }
        else if (DAT_140e419b8 == 3) {
          iVar10 = 0x50;
        }
        else {
          iVar10 = 1;
          if (DAT_140e419b8 == 4) {
            iVar10 = 100;
          }
        }
      }
      iVar5 = (uStack_b0._4_4_ + -0xa0) * iVar10;
    }
    uVar11 = DAT_14053ac2c;
    FUN_1400709b0(3,0,param_1[10],param_1[0xb],CONCAT22(uVar13,*(undefined2 *)(param_1 + 0x10)),
                  DAT_14053ac2c,DAT_14053a218,1,4,iVar5,0);
    uVar14 = (undefined2)((uint)uVar11 >> 0x10);
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
    FUN_14018a340(DAT_140e472a4,1,1);
  }
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    param_1[0x14] = 0x50;
    FUN_140079e20(param_1,2);
    FUN_14007b010(param_1,4000,0x19);
    uVar7 = DAT_14053b380;
    uVar15 = DAT_140539f40;
    stage_entity_spawn_candidate
              (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar14,0x4000),DAT_140539f40,
               10,1,DAT_140e44308);
    iVar10 = param_1[2];
    puVar6 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)puVar6[0xc]) {
        if (*(int *)((longlong)puVar6 + 4) == iVar10) {
          *(int *)((longlong)puVar6 + 0x5c) = *(int *)((longlong)puVar6 + 0x5c) + -1;
        }
      }
    }
    FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar7 & 0xffff0000,0,uVar15 & 0xffffffff00000000);
    *param_1 = 0;
  }
  if ((int)local_b8 == 0) {
    *param_1 = 0;
  }
  return;
}


