// Function: FUN_140099570 @ 140099570
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140099570(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  double dVar4;
  int iVar5;
  undefined8 uVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_ffffffffffffff18;
  undefined2 uVar20;
  uint in_stack_ffffffffffffff20;
  undefined1 in_stack_ffffffffffffff28 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  
  uVar20 = (undefined2)((uint)in_stack_ffffffffffffff18 >> 0x10);
  dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xd]),
                                 (double)(DAT_140e445d8 - (float)param_1[0xc]));
  dVar13 = dVar13 * DAT_14053aba0;
  uVar9 = (ushort)(int)dVar13;
  if (param_1[5] == 0) {
    uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    uVar18 = DAT_14053b330;
    dVar16 = DAT_14053a018 - (double)(int)param_1[3] * DAT_140539e98;
    if (param_1[3] == 0) {
      auVar21._12_4_ = in_stack_ffffffffffffff28._12_4_;
      auVar21._0_8_ = in_stack_ffffffffffffff28._0_8_;
      auVar21._8_4_ = 0x14;
      auVar22._8_8_ = 0;
      auVar22._0_8_ = auVar21._8_8_;
      auVar22 = auVar22 << 0x40;
      uVar19 = CONCAT22((short)(in_stack_ffffffffffffff20 >> 0x10),0xfc18);
      stage_entity_spawn_candidate
                (0x4b,99999999,1,DAT_14053adac,DAT_14053b330,uVar19,0,auVar21._8_8_,1,param_1[1]);
      auVar23._12_4_ = auVar22._12_4_;
      auVar23._0_8_ = auVar22._0_8_;
      auVar23._8_4_ = 0x14;
      auVar24._8_8_ = 0;
      auVar24._0_8_ = auVar23._8_8_;
      auVar24 = auVar24 << 0x40;
      uVar19 = CONCAT22((short)((uint)uVar19 >> 0x10),1000);
      stage_entity_spawn_candidate
                (0x4b,99999999,1,DAT_14053b3c8,uVar18,uVar19,0,auVar23._8_8_,1,param_1[1]);
      uVar18 = DAT_14053b370;
      auVar25._12_4_ = auVar24._12_4_;
      auVar25._0_8_ = auVar24._0_8_;
      auVar25._8_4_ = 0x14;
      auVar26._8_8_ = 0;
      auVar26._0_8_ = auVar25._8_8_;
      auVar26 = auVar26 << 0x40;
      uVar19 = CONCAT22((short)((uint)uVar19 >> 0x10),0xf448);
      stage_entity_spawn_candidate
                (0x4b,99999999,1,DAT_14053ad10,DAT_14053b370,uVar19,0,auVar25._8_8_,1,param_1[1]);
      auVar27._12_4_ = auVar26._12_4_;
      auVar27._0_8_ = auVar26._0_8_;
      auVar27._8_4_ = 0x14;
      in_stack_ffffffffffffff20 = CONCAT22((short)((uint)uVar19 >> 0x10),3000);
      stage_entity_spawn_candidate
                (0x4b,99999999,1,DAT_14053b378,uVar18,in_stack_ffffffffffffff20,0,auVar27._8_8_,1,
                 param_1[1]);
    }
    uStackX_c = (undefined4)((ulonglong)uVar6 >> 0x20);
    local_res8 = (undefined4)uVar6;
    in_stack_ffffffffffffff28._8_4_ = SUB84(dVar16,0);
    in_stack_ffffffffffffff28._0_8_ = dVar16;
    in_stack_ffffffffffffff28._12_4_ = (int)((ulonglong)dVar16 >> 0x20);
    in_stack_ffffffffffffff20 = in_stack_ffffffffffffff20 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_ffffffffffffff20,
                  in_stack_ffffffffffffff28,0xff,0xff,0xff,0xff,1,0);
    uVar20 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  dVar4 = DAT_14053a020;
  dVar16 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_140099da4;
  dVar14 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a618 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar12 = (float)param_1[0xb];
  fVar11 = (float)param_1[10];
  fVar17 = (float)(dVar14 * DAT_14053a460) + (float)param_1[0xc];
  FUN_1403300b4((double)((float)param_1[0xd] - fVar12),(double)(fVar17 - fVar11));
  fVar11 = (float)FUN_140334430(fVar11 - fVar17,DAT_140539fc0);
  fVar12 = (float)FUN_140334430(fVar12 - (float)param_1[0xd]);
  if (fVar11 + fVar12 < 0.0) {
    fVar12 = (float)FUN_1403352f8();
  }
  else {
    fVar12 = SQRT(fVar11 + fVar12);
  }
  uVar2 = param_1[3];
  dVar14 = (double)FUN_140332d90(((double)(int)uVar2 - 0.0) * DAT_14053a808 * dVar4 * dVar16);
  auVar22 = _DAT_14053bb20;
  dVar14 = dVar14 * _DAT_140539e28;
  uVar18 = (undefined4)DAT_14053bb20;
  uVar19 = DAT_14053bb20._4_4_;
  dVar4 = (double)DAT_14053bb20;
  dVar15 = (double)FUN_140332d90();
  dVar16 = *(double *)(param_1 + 0x12);
  fVar11 = (float)(dVar15 + dVar15) - _DAT_14053acc0;
  if ((uVar2 < 0x79) && (DAT_140539f28 < dVar16)) {
    dVar16 = dVar16 - _DAT_140539e58;
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  *(double *)(param_1 + 0x12) = dVar16;
  iVar7 = ((int)dVar13 & 0xffffU) - (uint)uVar1;
  iVar5 = iVar7 + 0x10000;
  if (-0x8001 < iVar7) {
    iVar5 = iVar7;
  }
  iVar7 = iVar5 + -0x10000;
  if (iVar5 < 0x8001) {
    iVar7 = iVar5;
  }
  if (iVar7 < 1) {
    uVar8 = uVar1;
    if ((iVar7 < 0) && (uVar8 = uVar1 - 0x80, -0x80 < iVar7)) {
      uVar8 = uVar9;
    }
  }
  else {
    uVar8 = uVar9;
    if (0x7f < iVar7) {
      uVar8 = uVar1 + 0x80;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar8;
  if (0x121 < (int)uVar2) {
    dVar16 = dVar16 - DAT_140539e60;
    *(double *)(param_1 + 0x12) = dVar16;
  }
  dVar13 = (double)FUN_1403307c0();
  param_1[0xc] = (float)(dVar13 * dVar16) + (float)param_1[0xc];
  dVar15 = (double)FUN_140332d90();
  dVar13 = (double)fVar12 / DAT_14053a2d8;
  param_1[0xd] = (float)(dVar15 * dVar16) + (float)param_1[0xd];
  dVar16 = (double)FUN_1403307c0();
  fVar17 = (float)(dVar16 * dVar13) + (float)param_1[10];
  param_1[10] = fVar17;
  dVar16 = (double)FUN_140332d90();
  fVar12 = (float)(dVar16 * dVar13) + (float)param_1[0xb];
  param_1[0xb] = fVar12;
  if (uVar2 - 0x32 < 0xf0) {
    fVar12 = fVar12 + DAT_14053ac44 + fVar11;
    dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar12),(double)(DAT_140e445d8 - fVar17)
                                  );
    auVar28._0_8_ = in_stack_ffffffffffffff28._0_8_;
    iVar5 = 1;
    dVar13 = dVar13 * DAT_14053aba0;
    if (DAT_140e419b8 == 0) {
      iVar5 = 0x20;
    }
    else if (DAT_140e419b8 == 1) {
      iVar5 = 0x18;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar5 = 0x14;
    }
    else if (DAT_140e419b8 == 4) {
      iVar5 = 0x10;
    }
    iVar7 = 1;
    if (DAT_140e419b8 == 0) {
      iVar7 = 5;
    }
    else if (DAT_140e419b8 == 1) {
LAB_140099b60:
      iVar7 = 7;
    }
    else {
      if (DAT_140e419b8 != 2) {
        if (DAT_140e419b8 == 3) goto LAB_140099b60;
        if (DAT_140e419b8 != 4) goto LAB_140099b6c;
      }
      iVar7 = 9;
    }
LAB_140099b6c:
    if (DAT_140e419b8 == 0) {
      uVar18 = (undefined4)DAT_14053a0b0;
      uVar19 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar18 = (undefined4)DAT_14053a0d0;
      uVar19 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar18 = (undefined4)DAT_14053a0f8;
      uVar19 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (DAT_140e419b8 == 3) {
      uVar18 = (undefined4)DAT_14053a118;
      uVar19 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    }
    else if (DAT_140e419b8 == 4) {
      uVar18 = (undefined4)DAT_14053a178;
      uVar19 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    iVar10 = (int)(uVar2 - 0x32) % 0x78;
    if ((iVar10 < iVar5 * 3) && (uVar3 = (longlong)iVar10 % (longlong)iVar5, (int)uVar3 == 0)) {
      auVar28._12_4_ = in_stack_ffffffffffffff28._12_4_;
      auVar28._8_4_ = 1;
      auVar29._8_8_ = auVar28._8_8_;
      auVar29._0_8_ = CONCAT44(uVar19,uVar18);
      in_stack_ffffffffffffff20 = 0;
      FUN_1400709b0(4,uVar3 & 0xffffffff,fVar17,fVar12,CONCAT22(uVar20,(short)(int)dVar13),0,
                    CONCAT44(uVar19,uVar18),auVar29._8_8_,iVar7,17000,0);
      auVar30._0_8_ = auVar29._0_8_;
      if (2 < DAT_140e419b8) {
        auVar30._12_4_ = auVar29._12_4_;
        auVar30._8_4_ = 1;
        in_stack_ffffffffffffff20 = 0;
        FUN_1400709b0(4,0,fVar17,fVar12,(int)dVar13 & 0xffff,0,
                      (double)CONCAT44(uVar19,uVar18) + _DAT_140539f88,auVar30._8_8_,iVar7 - 1U,
                      (int)(17000 / (ulonglong)(iVar7 - 1U)) * (iVar7 + -2) & 0xffff,0);
      }
    }
  }
  in_stack_ffffffffffffff20 = in_stack_ffffffffffffff20 & 0xffff0000;
  FUN_1400c8410(DAT_140e44c1c,0x20,7,param_1[10],param_1[0xb],in_stack_ffffffffffffff20,
                dVar14 + dVar4,dVar4,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44730,0x20,7,param_1[10],fVar11 + (float)param_1[0xb],
                in_stack_ffffffffffffff20 & 0xffff0000,auVar22,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
LAB_140099da4:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


