// Function: FUN_1400941d0 @ 1400941d0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400941d0(undefined4 *param_1)

{
  ulonglong uVar1;
  double dVar2;
  bool bVar3;
  undefined1 auVar4 [16];
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  undefined8 uVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffef8;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined2 uVar25;
  uint in_stack_ffffffffffffff00;
  uint uVar26;
  undefined4 uVar27;
  undefined2 uVar28;
  undefined1 in_stack_ffffffffffffff08 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  
  fVar5 = DAT_14053ae30;
  dVar14 = DAT_14053a070;
  uVar28 = (undefined2)(in_stack_ffffffffffffff00 >> 0x10);
  uVar25 = (undefined2)((uint)in_stack_fffffffffffffef8 >> 0x10);
  uVar17 = SUB84(DAT_14053a070,0);
  uVar18 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
  bVar3 = (float)param_1[0xc] <= DAT_14053ae30 && DAT_14053ae30 != (float)param_1[0xc];
  if (param_1[5] == 0) {
    uVar9 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar9;
    dVar14 = dVar14 - (double)(int)param_1[3] * DAT_140539ec8;
    uStackX_c = (undefined4)((ulonglong)uVar9 >> 0x20);
    in_stack_ffffffffffffff08._8_4_ = SUB84(dVar14,0);
    in_stack_ffffffffffffff08._0_8_ = dVar14;
    in_stack_ffffffffffffff08._12_4_ = (int)((ulonglong)dVar14 >> 0x20);
    uVar26 = in_stack_ffffffffffffff00 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar26,in_stack_ffffffffffffff08,0xff,
                  0xff,0xff,0xff,1,0);
    uVar28 = (undefined2)(uVar26 >> 0x10);
    uVar25 = (undefined2)((uint)uStackX_c >> 0x10);
    if (param_1[3] == 0) {
      auVar29._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar29._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar29._8_4_ = 0x28;
      auVar30._8_8_ = 0;
      auVar30._0_8_ = auVar29._8_8_;
      auVar30 = auVar30 << 0x40;
      uVar23 = CONCAT22(uVar28,0xc000);
      stage_entity_spawn_candidate
                (0x3e,99999999,1,DAT_14053b3a8,DAT_14053b370,uVar23,0,auVar29._8_8_,1,param_1[1]);
      auVar31._12_4_ = auVar30._12_4_;
      auVar31._0_8_ = auVar30._0_8_;
      auVar31._8_4_ = 0x28;
      auVar32._8_8_ = 0;
      auVar32._0_8_ = auVar31._8_8_;
      auVar32 = auVar32 << 0x40;
      uVar23 = CONCAT22((short)((uint)uVar23 >> 0x10),0xc000);
      stage_entity_spawn_candidate
                (0x3e,99999999,1,DAT_14053b37c,DAT_14053b384,uVar23,0,auVar31._8_8_,1,param_1[1]);
      auVar33._12_4_ = auVar32._12_4_;
      auVar33._0_8_ = auVar32._0_8_;
      auVar33._8_4_ = 0x28;
      auVar4._8_8_ = 0;
      auVar4._0_8_ = auVar33._8_8_;
      in_stack_ffffffffffffff08 = auVar4 << 0x40;
      uVar27 = CONCAT22((short)((uint)uVar23 >> 0x10),0xc000);
      uVar23 = DAT_14053b388;
      stage_entity_spawn_candidate
                (0x3e,99999999,1,DAT_14053ad30,DAT_14053b388,uVar27,0,auVar33._8_8_,1,param_1[1]);
      uVar28 = (undefined2)((uint)uVar27 >> 0x10);
      uVar25 = (undefined2)((uint)uVar23 >> 0x10);
    }
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0x12) = 0x4004000000000000;
      uVar8 = 0x7830;
      if ((float)param_1[10] <= fVar5) {
        uVar8 = 2000;
      }
      *(undefined2 *)(param_1 + 0x10) = uVar8;
      uVar9 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffff38);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar9;
      uStackX_c = (undefined4)((ulonglong)uVar9 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[0x15] = 0;
      param_1[3] = 0;
    }
  }
  if (param_1[5] != 1) goto LAB_140094b0e;
  dVar14 = (double)FUN_1403307c0();
  fVar22 = (float)(dVar14 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  param_1[10] = fVar22;
  dVar14 = (double)FUN_140332d90();
  iVar11 = DAT_140e419b8;
  fVar16 = DAT_14053ad9c;
  iVar13 = 1;
  fVar19 = fVar22 - DAT_14053ad9c;
  fVar21 = (float)(dVar14 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  param_1[0xb] = fVar21;
  fVar20 = DAT_140e445d8;
  uVar7 = _UNK_14053bb2c;
  uVar6 = _UNK_14053bb28;
  uVar27 = _UNK_14053bb24;
  uVar23 = _DAT_14053bb20;
  fVar21 = fVar21 + DAT_14053ac98;
  if (iVar11 == 0) {
    iVar13 = 100;
  }
  else if (iVar11 == 1) {
    iVar13 = 0x50;
  }
  else if (iVar11 == 2) {
LAB_14009450b:
    iVar13 = 0x32;
  }
  else if (iVar11 == 3) {
    iVar13 = 0x3c;
  }
  else if (iVar11 == 4) goto LAB_14009450b;
  if (iVar11 == 0) {
    uVar17 = (undefined4)DAT_14053a030;
    uVar18 = (undefined4)((ulonglong)DAT_14053a030 >> 0x20);
  }
  else if (iVar11 == 1) {
    uVar17 = (undefined4)DAT_14053a048;
    uVar18 = (undefined4)((ulonglong)DAT_14053a048 >> 0x20);
  }
  else if (iVar11 != 2) {
    if (iVar11 == 3) {
      uVar17 = (undefined4)DAT_14053a0b0;
      uVar18 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
    }
    else {
      uVar17 = _DAT_14053bb20;
      uVar18 = _UNK_14053bb24;
      if (iVar11 == 4) {
        uVar17 = (undefined4)DAT_14053a118;
        uVar18 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
    }
  }
  iVar12 = 1;
  if (iVar11 == 0) {
    iVar12 = 5;
  }
  else if (iVar11 == 1) {
    iVar12 = 7;
  }
  else if (((iVar11 == 2) || (iVar11 == 3)) || (iVar11 == 4)) {
    iVar12 = 9;
  }
  if (bVar3) {
    fVar19 = fVar22 + fVar16;
  }
  dVar15 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar21),
                                 SUB84((double)(DAT_140e445d8 - fVar19),0));
  dVar14 = DAT_140539f68;
  dVar15 = dVar15 * DAT_14053aba0;
  if (((fVar20 / DAT_14053ab70 + 0.0 <= fVar19) &&
      (fVar19 <= fVar20 / DAT_14053ab70 + DAT_14053aec0)) &&
     ((0.0 <= fVar21 && (fVar21 <= DAT_14053af14)))) {
    iVar11 = iVar12 * 0x168 + -0x168;
    sVar10 = (short)(int)dVar15;
    if ((0x1f < (int)param_1[3]) &&
       (uVar1 = (longlong)(param_1[3] + -0x20) % (longlong)(iVar13 * 2), (int)uVar1 == 0)) {
      auVar34._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar34._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar34._8_4_ = 1;
      auVar35._8_8_ = auVar34._8_8_;
      auVar35._0_8_ = CONCAT44(uVar18,uVar17);
      uVar24 = CONCAT22(uVar25,sVar10);
      FUN_1400709b0(5,uVar1 & 0xffffffff,fVar19,fVar21,uVar24,0,CONCAT44(uVar18,uVar17),
                    auVar35._8_8_,iVar12,iVar11,0);
      auVar36._12_4_ = auVar35._12_4_;
      auVar36._0_8_ = auVar35._0_8_;
      auVar36._8_4_ = 1;
      auVar37._8_8_ = auVar36._8_8_;
      auVar37._0_8_ = CONCAT44(uVar18,uVar17);
      uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),sVar10 + 7000);
      FUN_1400709b0(5,0,fVar19,fVar21,uVar24,0,CONCAT44(uVar18,uVar17),auVar37._8_8_,iVar12,iVar11,0
                   );
      auVar38._12_4_ = auVar37._12_4_;
      auVar38._0_8_ = auVar37._0_8_;
      auVar38._8_4_ = 1;
      in_stack_ffffffffffffff08._8_8_ = auVar38._8_8_;
      in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar18,uVar17);
      uVar28 = 0;
      uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),sVar10 + -7000);
      FUN_1400709b0(5,0,fVar19,fVar21,uVar24,0,CONCAT44(uVar18,uVar17),
                    in_stack_ffffffffffffff08._8_8_,iVar12,iVar11,0);
      uVar25 = (undefined2)((uint)uVar24 >> 0x10);
      if (2 < DAT_140e419b8) {
        dVar2 = (double)CONCAT44(uVar18,uVar17) - dVar14;
        auVar39._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar39._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar39._8_4_ = 1;
        auVar40._8_8_ = auVar39._8_8_;
        auVar40._0_8_ = dVar2;
        uVar24 = CONCAT22(uVar25,sVar10 + 0xdac);
        FUN_1400709b0(5,0,fVar19,fVar21,uVar24,0,dVar2,auVar40._8_8_,iVar12,iVar11,0);
        auVar41._12_4_ = auVar40._12_4_;
        auVar41._0_8_ = auVar40._0_8_;
        auVar41._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar41._8_8_;
        in_stack_ffffffffffffff08._0_8_ = dVar2;
        uVar28 = 0;
        uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),sVar10 + -0xdac);
        FUN_1400709b0(5,0,fVar19,fVar21,uVar24,0,dVar2,in_stack_ffffffffffffff08._8_8_,iVar12,iVar11
                      ,0);
        uVar25 = (undefined2)((uint)uVar24 >> 0x10);
      }
    }
    if ((iVar13 + 0x20 <= (int)param_1[3]) &&
       (uVar1 = (longlong)(param_1[3] - (iVar13 + 0x20)) % (longlong)(iVar13 * 2), (int)uVar1 == 0))
    {
      auVar42._12_4_ = in_stack_ffffffffffffff08._12_4_;
      auVar42._0_8_ = in_stack_ffffffffffffff08._0_8_;
      auVar42._8_4_ = 1;
      auVar43._8_8_ = auVar42._8_8_;
      auVar43._0_8_ = CONCAT44(uVar18,uVar17);
      FUN_1400709b0(5,uVar1 & 0xffffffff,fVar19,fVar21,CONCAT22(uVar25,sVar10 + 0xdac),0,
                    CONCAT44(uVar18,uVar17),auVar43._8_8_,iVar12,iVar11,0);
      auVar44._12_4_ = auVar43._12_4_;
      auVar44._0_8_ = auVar43._0_8_;
      auVar44._8_4_ = 1;
      in_stack_ffffffffffffff08._8_8_ = auVar44._8_8_;
      in_stack_ffffffffffffff08._0_8_ = CONCAT44(uVar18,uVar17);
      uVar28 = 0;
      FUN_1400709b0(5,0,fVar19,fVar21,sVar10 + -0xdac,0,CONCAT44(uVar18,uVar17),
                    in_stack_ffffffffffffff08._8_8_,iVar12,iVar11,0);
      if (2 < DAT_140e419b8) {
        dVar14 = (double)CONCAT44(uVar18,uVar17) - dVar14;
        auVar45._12_4_ = in_stack_ffffffffffffff08._12_4_;
        auVar45._0_8_ = in_stack_ffffffffffffff08._0_8_;
        auVar45._8_4_ = 1;
        auVar46._8_8_ = auVar45._8_8_;
        auVar46._0_8_ = dVar14;
        FUN_1400709b0(5,0,fVar19,fVar21,(int)dVar15 & 0xffff,0,dVar14,auVar46._8_8_,iVar12,iVar11,0)
        ;
        auVar47._12_4_ = auVar46._12_4_;
        auVar47._0_8_ = auVar46._0_8_;
        auVar47._8_4_ = 1;
        auVar48._8_8_ = auVar47._8_8_;
        auVar48._0_8_ = dVar14;
        FUN_1400709b0(5,0,fVar19,fVar21,sVar10 + 7000,0,dVar14,auVar48._8_8_,iVar12,iVar11,0);
        auVar49._12_4_ = auVar48._12_4_;
        auVar49._0_8_ = auVar48._0_8_;
        auVar49._8_4_ = 1;
        in_stack_ffffffffffffff08._8_8_ = auVar49._8_8_;
        in_stack_ffffffffffffff08._0_8_ = dVar14;
        uVar28 = 0;
        FUN_1400709b0(5,0,fVar19,fVar21,sVar10 + -7000,0,dVar14,in_stack_ffffffffffffff08._8_8_,
                      iVar12,iVar11,0);
      }
    }
  }
  dVar14 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053aaa0 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar14 = dVar14 + 0.0;
  fVar16 = (float)param_1[10] + DAT_14053adb8;
  fVar20 = (float)param_1[0xb] + DAT_14053ac34;
  if (bVar3) {
    fVar16 = (float)param_1[10] - DAT_14053adb8;
  }
  auVar50._0_8_ = in_stack_ffffffffffffff08._0_8_;
  auVar50._8_4_ = uVar23;
  auVar50._12_4_ = uVar27;
  auVar51._8_8_ = auVar50._8_8_;
  auVar51._0_8_ = dVar14;
  uVar17 = CONCAT22(uVar28,0xc000);
  FUN_1400c8410(DAT_140e44bf4,0x1e,7,fVar16,fVar20,uVar17,dVar14,auVar51._8_8_,0xff,0xff,0xff,0xff,1
                ,1);
  auVar52._0_8_ = auVar51._0_8_;
  auVar52._8_4_ = uVar23;
  auVar52._12_4_ = uVar27;
  uVar26 = CONCAT22((short)((uint)uVar17 >> 0x10),0xc000);
  FUN_1400c8410(DAT_140e44bf4,0x1e,7,fVar16,fVar20,uVar26,
                CONCAT44((uint)((ulonglong)dVar14 >> 0x20) ^ _UNK_14053bef4,
                         SUB84(dVar14,0) ^ ram0x00014053bef0),auVar52._8_8_,0xff,0xff,0xff,0xff,1,1)
  ;
  auVar53._4_4_ = uVar27;
  auVar53._0_4_ = uVar23;
  auVar53._8_4_ = uVar6;
  auVar53._12_4_ = uVar7;
  FUN_1400c8410(DAT_140e44954,0x1e,7,param_1[10],param_1[0xb],uVar26 & 0xffff0000,auVar53,0xff,0xff,
                0xff,0xff,1,bVar3);
  FUN_140079c10(param_1,0);
LAB_140094b0e:
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,500,8);
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - fVar5) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053afa0 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b400)) || (DAT_14053afcc < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


