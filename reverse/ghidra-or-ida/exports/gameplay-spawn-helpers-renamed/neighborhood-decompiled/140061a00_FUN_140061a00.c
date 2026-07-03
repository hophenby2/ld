// Function: FUN_140061a00 @ 140061a00
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140061a00(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 in_stack_fffffffffffffeb0;
  undefined4 uVar17;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_e0;
  undefined1 local_a0 [120];
  
  uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffeb0 >> 0x20);
  local_108 = 0;
  local_108._0_4_ = 0;
  if ((0 < DAT_140e44e6c) &&
     (puVar7 = DAT_140e45d80, local_108._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar7 + 4) == param_1[2]) {
        local_108 = *puVar7;
        uStack_100 = puVar7[1];
        local_f8 = puVar7[2];
        uStack_e0 = puVar7[5];
      }
      puVar7 = (undefined8 *)puVar7[0xc];
    } while (puVar7 != (undefined8 *)0x0);
  }
  uStack_e0._4_4_ = uStack_e0._4_4_ + (float)param_1[0xd];
  uStack_e0._0_4_ = (float)uStack_e0 + (float)param_1[0xc];
  FUN_1403300b4((double)(uStack_e0._4_4_ - (float)param_1[0xb]),
                SUB84((double)((float)uStack_e0 - (float)param_1[10]),0));
  fVar12 = (float)FUN_140334430((float)param_1[10] - (float)uStack_e0,DAT_140539fc0);
  fVar13 = (float)FUN_140334430((float)param_1[0xb] - uStack_e0._4_4_);
  if (fVar12 + fVar13 < 0.0) {
    fVar12 = (float)FUN_1403352f8();
  }
  else {
    fVar12 = SQRT(fVar12 + fVar13);
  }
  uVar11 = param_1[3];
  puVar7 = (undefined8 *)FUN_140135060(local_a0,uVar11,0x14);
  uVar6 = _UNK_14053bb28;
  uVar5 = _DAT_14053bb20;
  fVar13 = DAT_14053ac58;
  dVar16 = DAT_14053a020;
  dVar15 = DAT_140539d28;
  iVar9 = 0;
  uVar1 = *puVar7;
  uVar2 = *(undefined4 *)(puVar7 + 1);
  if (local_f8._4_4_ == 0) {
    param_1[10] = (float)uStack_e0;
    dVar3 = DAT_14053a5f8;
    if (0x95 < (int)uVar11) {
      iVar9 = 0xff;
    }
    param_1[0xb] = uStack_e0._4_4_;
    dVar4 = DAT_14053a798;
    if (((int)uVar11 < 0x96) || (0xb3 < (int)uVar11)) {
      iVar8 = ((int)uVar11 >> 0x1f & 0xffffff01U) + 0xff;
      if ((int)uVar11 < 0) {
        iVar10 = 0;
        if ((int)uVar11 < 0xb4) {
          iVar10 = iVar8;
        }
      }
      else {
        if ((int)uVar11 < 0x96) {
          dVar15 = (double)FUN_140332d90(((double)(int)uVar11 - 0.0) * _DAT_14053a478 * dVar16 *
                                         dVar15);
          iVar8 = (int)(dVar15 * dVar3);
        }
        else if (uVar11 < 0xb4) goto LAB_140061cd4;
        iVar10 = 0;
        if ((int)uVar11 < 0xb4) {
          iVar10 = iVar8;
        }
        if ((uVar11 == 0) && (param_1[6] == 0x11b)) {
          stage_entity_spawn_candidate
                    (0x11c,99999999,0,0,DAT_14053acfc,0x4000,DAT_14053a1e8,CONCAT44(uVar17,100),1,
                     param_1[1]);
        }
      }
    }
    else {
      dVar14 = (double)FUN_140332d90(((double)(int)uVar11 - DAT_14053a510) * DAT_14053a798 * dVar16
                                     * dVar15);
      iVar9 = (int)(dVar14 * dVar3);
LAB_140061cd4:
      dVar15 = (double)FUN_140332d90(((double)(int)uVar11 - DAT_14053a4a0) * dVar4 * dVar16 * dVar15
                                    );
      iVar10 = 0;
      if ((int)uVar11 < 0xb4) {
        iVar10 = (int)(dVar15 * dVar3);
      }
    }
    if (uStack_100._4_4_ == 0xbe) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
    if (0 < iVar9) goto LAB_140061dd2;
  }
  else {
    dVar15 = *(double *)(param_1 + 0x12);
    dVar16 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar16 * ((double)fVar12 / dVar15)) + (float)param_1[10];
    dVar16 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar16 * ((double)fVar12 / dVar15)) + (float)param_1[0xb];
    if (local_f8._4_4_ == 99) {
      iVar8 = param_1[5];
      if (iVar8 < 99) {
        param_1[5] = 99;
        param_1[3] = 0;
        uVar11 = 0;
        goto LAB_140061db5;
      }
    }
    else {
LAB_140061db5:
      iVar8 = param_1[5];
    }
    iVar9 = 0xff;
    iVar10 = 0;
    if ((iVar8 == 99) &&
       (*(undefined8 *)(param_1 + 0x12) = 0x4000000000000000, iVar9 = 0xff, iVar10 = 0,
       99 < (int)uVar11)) goto LAB_140062014;
LAB_140061dd2:
    if (param_1[6] == 0x11b) {
      FUN_1400c8410(DAT_140e44a8c,0x1d,7,param_1[10],param_1[0xb],0,uVar5,uVar6,0xff,0xff,0xff,iVar9
                    ,1,0);
    }
    if (param_1[6] == 0x11c) {
      FUN_1400c8410(DAT_140e44a90,0x1c,7,(float)param_1[10] + fVar13,param_1[0xb],0,uVar5,uVar6,0xff
                    ,0xff,0xff,iVar9,1,0);
      FUN_1400c8410(DAT_140e44a90,0x1c,7,(float)param_1[10] - fVar13,param_1[0xb],0,uVar5,uVar6,0xff
                    ,0xff,0xff,iVar9,1,1);
    }
  }
  if (0 < iVar10) {
    uStack_114 = (undefined4)((ulonglong)uVar1 >> 0x20);
    local_118 = (undefined4)uVar1;
    if (param_1[6] == 0x11b) {
      FUN_1400c8410(DAT_140e44a8c,0x1d,8,param_1[10],param_1[0xb],0,uVar5,uVar6,local_118,uStack_114
                    ,uVar2,iVar10,1,0);
    }
    if (param_1[6] == 0x11c) {
      FUN_1400c8410(DAT_140e44a90,0x1c,8,(float)param_1[10] + fVar13,param_1[0xb],0,uVar5,uVar6,
                    local_118,uStack_114,uVar2,iVar10,1,0);
      FUN_1400c8410(DAT_140e44a90,0x1c,8,(float)param_1[10] - fVar13,param_1[0xb],0,uVar5,uVar6,
                    local_118,uStack_114,uVar2,iVar10,1,1);
    }
  }
LAB_140062014:
  if ((int)local_108 == 0) {
    *param_1 = 0;
  }
  return;
}


