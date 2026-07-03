// Function: FUN_140011a80 @ 140011a80
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140011a80(undefined4 *param_1)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  float fVar15;
  undefined4 uVar16;
  float fVar17;
  undefined4 in_stack_fffffffffffffec8;
  undefined2 uVar18;
  uint in_stack_fffffffffffffed0;
  ulonglong uVar19;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_c0;
  
  uVar18 = (undefined2)((uint)in_stack_fffffffffffffec8 >> 0x10);
  lVar4 = DAT_140e45d80;
  iVar7 = local_d8._4_4_;
  iVar6 = uStack_e0._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar7 = (int)((ulonglong)local_d8 >> 0x20);
      iVar6 = (int)((ulonglong)uStack_e0 >> 0x20);
      if (lVar4 == 0) break;
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        uStack_e0 = *(undefined8 *)(lVar4 + 8);
        local_d8 = *(undefined8 *)(lVar4 + 0x10);
        uStack_c0 = *(undefined8 *)(lVar4 + 0x28);
      }
      lVar4 = *(longlong *)(lVar4 + 0x60);
    }
  }
  uStack_e0._4_4_ = iVar6;
  local_d8._4_4_ = iVar7;
  fVar17 = uStack_c0._4_4_ + (float)param_1[0xd];
  fVar15 = (float)param_1[0xc];
  uStack_c0._0_4_ = fVar15 + (float)uStack_c0;
  dVar1 = (double)FUN_1403300b4(SUB84((double)(fVar17 - (float)param_1[0xb]),0),
                                SUB84((double)((float)uStack_c0 - (float)param_1[10]),0));
  dVar1 = dVar1 * DAT_14053aba0;
  fVar11 = (float)FUN_140334430((float)param_1[10] - (float)uStack_c0,DAT_140539fc0);
  fVar12 = (float)FUN_140334430((float)param_1[0xb] - fVar17);
  fVar11 = fVar11 + fVar12;
  if (fVar11 < 0.0) {
    fVar11 = (float)FUN_1403352f8(fVar11);
  }
  else {
    fVar11 = SQRT(fVar11);
  }
  dVar2 = (double)fVar11 / DAT_14053a0b0;
  bVar3 = fVar15 < 0.0;
  uVar16 = SUB84((double)((int)dVar1 & 0xffff) * DAT_14053a020 * DAT_140539d28,0);
  dVar1 = (double)FUN_1403307c0(uVar16);
  fVar12 = (float)(dVar1 * dVar2) + (float)param_1[10];
  param_1[10] = fVar12;
  dVar1 = (double)FUN_140332d90(uVar16);
  uVar5 = _UNK_14053bb28;
  uVar10 = _UNK_14053bb24;
  uVar16 = _DAT_14053bb20;
  fVar15 = (float)(dVar1 * dVar2) + (float)param_1[0xb];
  param_1[0xb] = fVar15;
  if (param_1[5] == 0) {
    if (param_1[3] == 0) {
      param_1[10] = (float)uStack_c0;
      param_1[0xb] = fVar17;
      fVar15 = fVar17;
      fVar12 = (float)uStack_c0;
    }
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffff0000;
    FUN_1400c8410(DAT_140e44948,0x1f,7,fVar12,fVar15,in_stack_fffffffffffffed0,
                  CONCAT44(uVar10,uVar16),uVar5,0xff,0xff,0xff,0xff,1,bVar3);
    uVar18 = (undefined2)((uint)fVar15 >> 0x10);
    if (local_d8._4_4_ == 1) {
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  iVar7 = param_1[5];
  if (iVar7 == 1) {
    iVar7 = 1;
    if (DAT_140e419b8 == 0) {
      iVar7 = 100;
    }
    else if (DAT_140e419b8 == 1) {
      iVar7 = 0x3c;
    }
    else if (DAT_140e419b8 == 2) {
      iVar7 = 0x28;
    }
    else if (DAT_140e419b8 == 3) {
      iVar7 = 0x24;
    }
    else if (DAT_140e419b8 == 4) {
      iVar7 = 0x1e;
    }
    uVar9 = 1;
    if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) && (DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 == 3 || (uVar9 = 1, DAT_140e419b8 == 4)))) {
      uVar9 = 2;
    }
    if (DAT_140e419b8 == 0) {
      uVar13 = SUB84(DAT_14053a0b0,0);
      uVar14 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar13 = (undefined4)DAT_14053a0f8;
      uVar14 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar13 = (undefined4)DAT_14053a138;
      uVar14 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar13 = (undefined4)DAT_14053a178;
      uVar14 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else {
      uVar13 = uVar16;
      uVar14 = uVar10;
      if (DAT_140e419b8 == 4) {
        uVar13 = (undefined4)DAT_14053a1b8;
        uVar14 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
      }
    }
    if ((9 < (int)param_1[3]) && (uVar8 = (param_1[3] + -10) % iVar7, (int)uVar8 < 0x14)) {
      uVar8 = uVar8 & 0x80000003;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
      }
      if (uVar8 == 0) {
        in_stack_fffffffffffffed0 = 0;
        FUN_1400709b0(3,0,param_1[10],(float)param_1[0xb] + DAT_14053acd8,CONCAT22(uVar18,0x4000),0,
                      CONCAT44(uVar14,uVar13),1,uVar9,3000,0);
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffff0000;
    FUN_1400c8410(DAT_140e44948,0x1f,7,param_1[10],param_1[0xb],in_stack_fffffffffffffed0,
                  CONCAT44(uVar10,uVar16),uVar5,0xff,0xff,0xff,0xff,1,bVar3);
    FUN_140079c10(param_1,1);
    uVar18 = (undefined2)(in_stack_fffffffffffffed0 >> 0x10);
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,0x708,8);
      FUN_140079e20(param_1,2);
      uVar19 = CONCAT44(uVar10,uVar16);
      uVar8 = DAT_14053b380;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar18,0x4000),uVar19,10,1,
                 DAT_140e44308);
      iVar7 = DAT_140e44308;
      lVar4 = DAT_140e45d80;
      if (0 < DAT_140e44e6c) {
        for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
          if (*(int *)(lVar4 + 4) == iVar7) {
            *(int *)(lVar4 + 0x5c) = *(int *)(lVar4 + 0x5c) + -1;
          }
        }
      }
      in_stack_fffffffffffffed0 = 0;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar8 & 0xffff0000,0,uVar19 & 0xffffffff00000000
                   );
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 1;
    }
    iVar7 = param_1[5];
    if (local_d8._4_4_ == 2) {
      FUN_140079e20(param_1,2);
      param_1[5] = param_1[5] + 1;
      iVar7 = param_1[5];
      param_1[0x15] = 1;
    }
  }
  if (iVar7 == 2) {
    in_stack_fffffffffffffed0 = in_stack_fffffffffffffed0 & 0xffff0000;
    FUN_1400c8410(DAT_140e44950,0x1f,7,param_1[10],param_1[0xb],in_stack_fffffffffffffed0,
                  CONCAT44(uVar10,uVar16),uVar5,0xff,0xff,0xff,0xff,1,bVar3);
  }
  uVar8 = param_1[3] & 0x80000003;
  if ((int)uVar8 < 0) {
    uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
  }
  uVar16 = 0;
  if ((int)uVar8 < 2) {
    uVar16 = 0xff;
  }
  uVar10 = 0x80;
  if ((int)uVar8 < 2) {
    uVar10 = 0xff;
  }
  if (bVar3) {
    fVar15 = (float)param_1[10] + DAT_14053ad04;
  }
  else {
    fVar15 = (float)param_1[10] - DAT_14053ad04;
  }
  FUN_1400c8410(DAT_140e41930,0x1e,7,fVar15,(float)param_1[0xb] - DAT_14053adec,
                in_stack_fffffffffffffed0 & 0xffff0000,CONCAT44(_UNK_14053bb54,_DAT_14053bb50),
                _UNK_14053bb58,0xff,uVar10,uVar16,0xc0,1,0);
  if (((local_d8._4_4_ == 2) && (uStack_e0._4_4_ == 0x82)) || (2 < local_d8._4_4_)) {
    *param_1 = 0;
  }
  return;
}


