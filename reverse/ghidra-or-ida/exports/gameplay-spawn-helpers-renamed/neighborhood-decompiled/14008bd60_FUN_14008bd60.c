// Function: FUN_14008bd60 @ 14008bd60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008bd60(undefined4 *param_1)

{
  short *psVar1;
  int iVar2;
  undefined8 *puVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  ushort uVar13;
  ushort uVar14;
  short sVar15;
  int iVar16;
  ushort uVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  float fVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 local_res8;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar32;
  float in_stack_fffffffffffffe70;
  float fVar33;
  undefined2 uVar34;
  undefined1 in_stack_fffffffffffffe78 [16];
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
  undefined4 uVar51;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 uStack_120;
  
  uVar32 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  local_148 = 0;
  local_148._0_4_ = 0;
  uStack_130 = 0;
  uStack_130._4_4_ = 0;
  puVar3 = DAT_140e45d80;
  iVar9 = uStack_140._4_4_;
  iVar8 = local_138._4_4_;
  iVar12 = uStack_130._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar9 = (int)((ulonglong)uStack_140 >> 0x20);
      iVar8 = (int)((ulonglong)local_138 >> 0x20);
      iVar12 = (int)((ulonglong)uStack_130 >> 0x20);
      if (puVar3 == (undefined8 *)0x0) break;
      if (*(int *)((longlong)puVar3 + 4) == param_1[2]) {
        local_148 = *puVar3;
        uStack_140 = puVar3[1];
        local_138 = puVar3[2];
        uStack_130 = puVar3[3];
        uStack_120 = puVar3[5];
      }
      puVar3 = (undefined8 *)puVar3[0xc];
    }
  }
  uStack_130._4_4_ = iVar12;
  local_138._4_4_ = iVar8;
  uStack_140._4_4_ = iVar9;
  fVar18 = (float)param_1[0xc];
  fVar33 = (float)param_1[0xb];
  fVar19 = (float)param_1[0xd];
  fVar27 = (float)param_1[10];
  FUN_1403300b4((double)((uStack_120._4_4_ + fVar19) - fVar33),
                SUB84((double)(((float)uStack_120 + fVar18) - fVar27),0));
  dVar24 = DAT_14053aba0;
  dVar21 = DAT_14053a020;
  fVar18 = (float)FUN_140334430(fVar27 - ((float)uStack_120 + fVar18),DAT_140539fc0);
  fVar19 = (float)FUN_140334430(fVar33 - (uStack_120._4_4_ + fVar19));
  if (fVar18 + fVar19 < 0.0) {
    fVar18 = (float)FUN_1403352f8();
  }
  else {
    fVar18 = SQRT(fVar18 + fVar19);
  }
  dVar25 = (double)fVar18 * DAT_140539e80;
  dVar20 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar20 * dVar25) + fVar27;
  dVar20 = (double)FUN_140332d90();
  uVar17 = (ushort)((uint)in_stack_fffffffffffffe70 >> 0x10);
  iVar9 = param_1[3];
  param_1[0xb] = (float)(dVar20 * dVar25) + fVar33;
  if (iVar9 == 0) {
    param_1[10] = (float)uStack_120;
    param_1[0xb] = uStack_120._4_4_;
  }
  auVar49 = _DAT_14053bb20;
  fVar18 = DAT_14053ac2c;
  dVar22 = DAT_14053a178;
  dVar23 = DAT_14053a118;
  dVar25 = DAT_140539d28;
  dVar20 = (double)DAT_14053bb20;
  uVar29 = (undefined4)DAT_14053bb20;
  uVar30 = DAT_14053bb20._4_4_;
  local_res8 = 9;
  if (param_1[6] == 0x28) {
    dVar21 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053aa28 * dVar21 * DAT_140539d28);
    dVar21 = dVar21 * DAT_140539e60 + dVar20;
    if ((99 < iVar9) && (uStack_140._4_4_ < 0xf0)) {
      iVar8 = 1;
      if (DAT_140e419b8 == 0) {
        iVar8 = 0xa0;
      }
      else if (DAT_140e419b8 == 1) {
        iVar8 = 0x78;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar8 = 0x5a;
      }
      dVar26 = DAT_14053a0b0;
      if (((DAT_140e419b8 != 0) && (dVar26 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
         ((dVar26 = dVar23, DAT_140e419b8 != 2 &&
          ((DAT_140e419b8 != 3 && (dVar26 = dVar20, DAT_140e419b8 == 4)))))) {
        dVar26 = dVar22;
      }
      psVar1 = (short *)((longlong)param_1 + 0x42);
      iVar8 = (iVar9 + -100) % iVar8;
      dVar26 = (double)iVar8 * DAT_140539e50 + dVar26;
      if (iVar8 == 0) {
        dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_120._4_4_),
                                       SUB84((double)(DAT_140e445d8 - (float)uStack_120),0));
        *psVar1 = (short)(int)(dVar22 * dVar24);
      }
      else {
        dVar22 = DAT_14053a178;
        if ((0x27 < iVar8) || (iVar8 != (iVar8 / 5) * 5)) goto LAB_14008c15e;
      }
      auVar35._12_4_ = in_stack_fffffffffffffe78._12_4_;
      auVar35._0_8_ = in_stack_fffffffffffffe78._0_8_;
      auVar35._8_4_ = 1;
      auVar36._8_8_ = auVar35._8_8_;
      auVar36._0_8_ = dVar26;
      fVar33 = fVar18;
      FUN_14006c2f0(9,0,param_1[10],param_1[0xb],
                    CONCAT22(uVar32,*psVar1 + *(short *)(param_1 + 0x10)),fVar18,dVar26,
                    auVar36._8_8_,0);
      uVar17 = (ushort)((uint)fVar33 >> 0x10);
      auVar37._0_8_ = auVar36._0_8_;
      dVar22 = DAT_14053a178;
      if (2 < DAT_140e419b8) {
        auVar37._12_4_ = auVar36._12_4_;
        auVar37._8_4_ = 1;
        fVar33 = fVar18;
        FUN_14006c2f0(9,0,param_1[10],param_1[0xb],*psVar1 + *(short *)(param_1 + 0x10),fVar18,
                      dVar26 + DAT_140539fc8,auVar37._8_8_,0);
        uVar17 = (ushort)((uint)fVar33 >> 0x10);
        dVar22 = DAT_14053a178;
      }
    }
LAB_14008c15e:
    uVar51 = param_1[0xb];
    in_stack_fffffffffffffe78._8_8_ = dVar21;
    in_stack_fffffffffffffe78._0_8_ = dVar20;
    in_stack_fffffffffffffe70 = (float)((uint)uVar17 << 0x10);
    FUN_1400c8410(DAT_140e446cc,0x22,7,param_1[10],uVar51,in_stack_fffffffffffffe70,dVar20,dVar21,
                  0xff,0xff,0xff,0xff,1,0);
    uVar32 = (undefined2)((uint)uVar51 >> 0x10);
  }
  dVar21 = DAT_14053a138;
  uVar34 = (undefined2)((uint)in_stack_fffffffffffffe70 >> 0x10);
  if (param_1[6] == 0x2a) {
    if ((0x4a < (int)param_1[3]) && (uStack_140._4_4_ < 0xf0)) {
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 0x5a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 0x3c;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar9 = 0x32;
      }
      else if (DAT_140e419b8 == 4) {
        iVar9 = 0x28;
      }
      dVar26 = DAT_14053a0d8;
      if ((((DAT_140e419b8 != 0) && (dVar26 = dVar23, DAT_140e419b8 != 1)) &&
          (dVar26 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((dVar26 = dVar23, DAT_140e419b8 != 3 && (dVar26 = dVar20, DAT_140e419b8 == 4)))) {
        dVar26 = dVar22;
      }
      iVar9 = (param_1[3] + -0x4b) % iVar9;
      dVar26 = (double)iVar9 * DAT_140539e50 + dVar26;
      if (iVar9 == 0) {
        dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_120._4_4_),
                                       SUB84((double)(DAT_140e445d8 - (float)uStack_120),0));
        *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar23 * dVar24);
      }
      else if ((0x1d < iVar9) || (iVar9 != (iVar9 / 5) * 5)) goto LAB_14008c378;
      auVar38._12_4_ = in_stack_fffffffffffffe78._12_4_;
      auVar38._0_8_ = in_stack_fffffffffffffe78._0_8_;
      auVar38._8_4_ = 1;
      auVar39._8_8_ = auVar38._8_8_;
      auVar39._0_8_ = dVar26;
      fVar33 = fVar18;
      FUN_14006c2f0(7,0,param_1[10],param_1[0xb],
                    CONCAT22(uVar32,*(short *)((longlong)param_1 + 0x42) +
                                    *(short *)(param_1 + 0x10)),fVar18,dVar26,auVar39._8_8_,0);
      uVar34 = (undefined2)((uint)fVar33 >> 0x10);
      if (2 < DAT_140e419b8) {
        auVar40._12_4_ = auVar39._12_4_;
        auVar40._0_8_ = auVar39._0_8_;
        auVar40._8_4_ = 1;
        fVar33 = fVar18;
        FUN_14006c2f0(7,0,param_1[10],param_1[0xb],
                      *(short *)((longlong)param_1 + 0x42) + *(short *)(param_1 + 0x10),fVar18,
                      dVar26 + DAT_140539ff0,auVar40._8_8_,0);
        uVar34 = (undefined2)((uint)fVar33 >> 0x10);
      }
    }
LAB_14008c378:
    in_stack_fffffffffffffe70 = (float)CONCAT22(uVar34,*(short *)(param_1 + 3) * 0x14d);
    in_stack_fffffffffffffe78 = auVar49;
    FUN_1400c8410(DAT_140e446d0,0x22,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe70,auVar49,
                  0xff,0xff,0xff,0xff,1,0);
  }
  if (param_1[6] == 0x4b) {
    iVar9 = param_1[3];
    dVar24 = (double)FUN_140332d90(((double)iVar9 - 0.0) * DAT_14053ab78 * DAT_14053a020 * dVar25);
    fVar33 = DAT_140e445d8;
    iVar8 = 1;
    fVar19 = (float)(dVar24 + dVar24) + 0.0;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x28;
    }
    else if (DAT_140e419b8 == 2) {
      iVar8 = 0x22;
    }
    else if (DAT_140e419b8 == 3) {
      iVar8 = 0x1e;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x19;
    }
    iVar12 = (param_1[1] - param_1[2]) * iVar8 + 0x2c;
    if (((iVar12 <= iVar9) && (local_138._4_4_ == 1)) && (uStack_140._4_4_ < 0x122)) {
      fVar27 = (float)param_1[0xb];
      fVar28 = (float)param_1[10];
      dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar27 + DAT_14053ac80)),
                                     SUB84((double)(DAT_140e445d8 - fVar28),0));
      if ((((iVar9 - iVar12) % (iVar8 * 5) == 0) && (fVar33 / DAT_14053ab70 + fVar18 <= fVar28)) &&
         ((fVar28 <= fVar33 / DAT_14053ab70 + DAT_14053aebc &&
          ((fVar18 <= fVar27 && (fVar27 <= DAT_14053af0c)))))) {
        auVar41._12_4_ = in_stack_fffffffffffffe78._12_4_;
        auVar41._0_8_ = in_stack_fffffffffffffe78._0_8_;
        auVar41._8_4_ = 0x50;
        in_stack_fffffffffffffe70 =
             (float)CONCAT22((short)((uint)in_stack_fffffffffffffe70 >> 0x10),
                             (short)(int)(dVar24 * DAT_14053aba0));
        stage_entity_spawn_candidate
                  (0x4c,400,4,fVar28,fVar27,in_stack_fffffffffffffe70,DAT_14053a048,auVar41._8_8_,1,
                   param_1[2]);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    uVar11 = (uint)in_stack_fffffffffffffe70 & 0xffff0000;
    FUN_1400c8410(DAT_140e44738,0x22,7,param_1[10],fVar19 + (float)param_1[0xb],uVar11,auVar49,0xff,
                  0xff,0xff,0xff,1,0);
    in_stack_fffffffffffffe70 = (float)(uVar11 & 0xffff0000);
    in_stack_fffffffffffffe78 = auVar49;
    FUN_1400c8410(DAT_140e44734,0x22,7,param_1[10],(float)param_1[0xb] - fVar19,
                  in_stack_fffffffffffffe70,auVar49,0xff,0xff,0xff,0xff,1,0);
  }
  fVar19 = DAT_140e445dc;
  fVar33 = DAT_140e445d8;
  if ((param_1[6] - 0x9d < 7) && ((0x49U >> (param_1[6] - 0x9d & 0x1f) & 1) != 0)) {
    dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                   SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
    dVar24 = dVar24 * DAT_14053aba0;
    dVar25 = (double)FUN_1403300b4((double)(fVar19 - uStack_120._4_4_),
                                   SUB84((double)(fVar33 - (float)uStack_120),0));
    dVar25 = dVar25 * DAT_14053aba0;
    uVar51 = 0x5e;
    auVar42._12_4_ = in_stack_fffffffffffffe78._12_4_;
    auVar42._0_8_ = in_stack_fffffffffffffe78._0_8_;
    auVar42._8_4_ = 0x5d;
    in_stack_fffffffffffffe78._4_12_ = auVar42._4_12_;
    in_stack_fffffffffffffe78._0_4_ = 0x5c;
    in_stack_fffffffffffffe70 = 0.0;
    iVar8 = FUN_1400c9580(DAT_140e44acc,0,6,5,0x5a,0x5b,in_stack_fffffffffffffe78,0x5e);
    iVar9 = param_1[6];
    uVar17 = (ushort)(int)dVar24;
    sVar5 = (short)(int)dVar25;
    if (iVar9 == 0x9d) {
      uVar13 = *(ushort *)(param_1 + 0x10);
      uVar4 = uVar17 - uVar13;
      uVar11 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar11 = 0x10000 - uVar4;
      }
      iVar12 = ((int)dVar24 & 0xffffU) - (uint)uVar13;
      iVar16 = (int)uVar11 / 10 + 0x30;
      iVar9 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar9 = iVar12;
      }
      iVar12 = iVar9 + -0x10000;
      if (iVar9 < 0x8001) {
        iVar12 = iVar9;
      }
      if (iVar12 < 1) {
        uVar14 = uVar13;
        if ((iVar12 < 0) && (uVar14 = uVar13 - (short)iVar16, -iVar16 < iVar12)) {
          uVar14 = uVar17;
        }
      }
      else {
        uVar14 = uVar17;
        if (iVar16 <= iVar12) {
LAB_14008c859:
          uVar14 = uVar13 + (short)iVar16;
        }
      }
LAB_14008c871:
      *(ushort *)(param_1 + 0x10) = uVar14;
    }
    else if ((iVar9 == 0xa0) || (iVar9 == 0xa3)) {
      uVar13 = *(ushort *)(param_1 + 0x10);
      uVar4 = (*(short *)(param_1 + 0x11) - uVar13) + sVar5;
      uVar11 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar11 = 0x10000 - uVar4;
      }
      uVar4 = *(short *)(param_1 + 0x11) + sVar5;
      iVar12 = (uint)uVar4 - (uint)uVar13;
      iVar16 = (int)uVar11 / 10 + 0x30;
      iVar9 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar9 = iVar12;
      }
      iVar12 = iVar9 + -0x10000;
      if (iVar9 < 0x8001) {
        iVar12 = iVar9;
      }
      if (iVar12 < 1) {
        uVar14 = uVar13;
        if ((iVar12 < 0) && (uVar14 = uVar13 - (short)iVar16, -iVar16 < iVar12)) {
          uVar14 = uVar4;
        }
      }
      else {
        uVar14 = uVar4;
        if (iVar16 <= iVar12) goto LAB_14008c859;
      }
      goto LAB_14008c871;
    }
    iVar9 = param_1[3];
    if (0x3b < iVar9) {
      fVar33 = (float)param_1[10];
      dVar25 = (double)FUN_1403307c0();
      dVar25 = dVar25 * DAT_14053a240;
      fVar19 = (float)param_1[0xb];
      dVar23 = (double)FUN_140332d90();
      dVar24 = DAT_14053a178;
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 0x5a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 0x4b;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar12 = 0x3c;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 0x32;
      }
      iVar16 = 1;
      if (DAT_140e419b8 == 0) {
        iVar16 = 0x19;
      }
      else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
              (DAT_140e419b8 == 4)) {
        iVar16 = 0x28;
      }
      if (((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a178, DAT_140e419b8 != 1)) &&
         ((dVar21 = DAT_14053a1b8, DAT_140e419b8 != 2 &&
          ((dVar21 = DAT_14053a178, DAT_140e419b8 != 3 && (dVar21 = dVar20, DAT_140e419b8 == 4))))))
      {
        dVar21 = DAT_14053a1c8;
      }
      iVar2 = param_1[6];
      iVar10 = (iVar9 + -0x3c) % iVar12;
      dVar21 = (double)iVar10 * DAT_140539e50 + dVar21;
      if (iVar2 == 0xa0) {
        dVar25 = (double)FUN_1403307c0();
        dVar23 = (double)FUN_140332d90();
        uVar31 = 9;
        fVar27 = (float)(dVar25 * dVar24) + fVar33;
        fVar28 = (float)(dVar23 * dVar24) + fVar19;
      }
      else {
        uVar31 = 7;
        local_res8 = 7;
        fVar27 = (float)dVar25 + fVar33;
        fVar28 = (float)(dVar23 * DAT_14053a240) + fVar19;
        if (iVar2 == 0xa3) {
          local_res8 = 7;
          fVar27 = fVar33;
          fVar28 = fVar19;
        }
      }
      if ((iVar9 < 0x118) && (iVar10 == 0)) {
        local_res8 = uVar31;
        if (iVar2 == 0x9d) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar17;
        }
        else if ((iVar2 == 0xa0) || (iVar2 == 0xa3)) {
          *(short *)((longlong)param_1 + 0x42) = sVar5 + *(short *)(param_1 + 0x11);
        }
      }
      iVar9 = param_1[3];
      if ((iVar9 - 0x3cU < 0xdc) && ((iVar9 + -0x3c) % iVar12 < iVar16)) {
        uVar11 = (iVar9 + -0x3c) % iVar12 & 0x80000003;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
        }
        if (uVar11 == 0) {
          uVar51 = 0;
          auVar43._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar43._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar43._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar43._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar21;
          in_stack_fffffffffffffe70 = fVar18;
          FUN_14006c2f0(uVar31,0,fVar27,fVar28,*(undefined2 *)((longlong)param_1 + 0x42),fVar18,
                        dVar21,in_stack_fffffffffffffe78._8_8_,0);
          if (2 < DAT_140e419b8) {
            uVar51 = 0;
            auVar44._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar44._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar44._8_4_ = 1;
            in_stack_fffffffffffffe78._8_8_ = auVar44._8_8_;
            in_stack_fffffffffffffe78._0_8_ = dVar21 + DAT_140539ff0;
            in_stack_fffffffffffffe70 = fVar18;
            FUN_14006c2f0(local_res8,0,fVar27,fVar28,*(undefined2 *)((longlong)param_1 + 0x42),
                          fVar18,dVar21 + DAT_140539ff0,in_stack_fffffffffffffe78._8_8_,0);
          }
        }
      }
    }
    if (param_1[6] == 0x9d) {
      uVar51 = 0xff;
      in_stack_fffffffffffffe70 =
           (float)CONCAT22((short)((uint)in_stack_fffffffffffffe70 >> 0x10),
                           *(undefined2 *)(param_1 + 0x10));
      in_stack_fffffffffffffe78 = auVar49;
      FUN_1400c8410((&DAT_140e44e70)[iVar8],0x22,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffe70,auVar49,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[6] == 0xa0) {
      auVar45._12_4_ = in_stack_fffffffffffffe78._12_4_;
      auVar45._0_8_ = in_stack_fffffffffffffe78._0_8_;
      auVar45._8_4_ = 0x85;
      auVar46._4_12_ = auVar45._4_12_;
      auVar46._0_4_ = 0x86;
      uVar32 = 0;
      iVar9 = FUN_1400c9580(DAT_140e44acc,0,6,4,0x84,0x85,auVar46,uVar51);
      in_stack_fffffffffffffe70 = (float)CONCAT22(uVar32,*(undefined2 *)(param_1 + 0x10));
      in_stack_fffffffffffffe78 = auVar49;
      FUN_1400c8410((&DAT_140e44660)[iVar9],0x22,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffe70,auVar49,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[6] == 0xa3) {
      auVar47._12_4_ = in_stack_fffffffffffffe78._12_4_;
      auVar47._0_8_ = in_stack_fffffffffffffe78._0_8_;
      auVar47._8_4_ = 0x65;
      auVar48._4_12_ = auVar47._4_12_;
      auVar48._0_4_ = 100;
      uVar32 = 0;
      iVar9 = FUN_1400c9580(DAT_140e44acc,0,6,5,0x62,99,auVar48,0x66);
      in_stack_fffffffffffffe70 = (float)CONCAT22(uVar32,*(short *)(param_1 + 0x10) + -0x8000);
      FUN_1400c8410((&DAT_140e44e70)[iVar9],0x22,7,param_1[10],param_1[0xb],
                    in_stack_fffffffffffffe70,auVar49,0xff,0xff,0xff,0xff,1,0);
      in_stack_fffffffffffffe78 = auVar49;
    }
  }
  if (param_1[6] != 0xff) {
    uVar51 = SUB84(DAT_140539d28,0);
    uVar31 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    dVar21 = DAT_14053a020;
    goto LAB_14008cf53;
  }
  in_stack_fffffffffffffe70 = 0.0;
  uVar32 = 0;
  iVar8 = FUN_1400c9580(param_1[3],0,0xf,2,0xa0,0xa1);
  dVar21 = DAT_14053a020;
  iVar9 = param_1[3];
  uVar51 = SUB84(DAT_140539d28,0);
  uVar31 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar24 = (double)FUN_140332d90(((double)iVar9 - 0.0) * _DAT_14053aa30 * DAT_14053a020 *
                                 DAT_140539d28);
  if ((0x4a < iVar9) && (uStack_140._4_4_ < 0xf0)) {
    iVar9 = (iVar9 + -0x4b) % 0x3c;
    dVar25 = (double)iVar9 * DAT_140539e50 + DAT_14053a158;
    if (iVar9 == 0) {
      dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_120._4_4_),
                                     SUB84((double)(DAT_140e445d8 - (float)uStack_120),0));
      *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar23 * DAT_14053aba0);
    }
    else if ((0x27 < iVar9) || (iVar9 != (iVar9 / 5) * 5)) goto LAB_14008ced4;
    auVar49._12_4_ = in_stack_fffffffffffffe78._12_4_;
    auVar49._0_8_ = in_stack_fffffffffffffe78._0_8_;
    auVar49._8_4_ = 1;
    FUN_14006c2f0(7,0,param_1[10],param_1[0xb],
                  CONCAT22(uVar32,*(short *)(param_1 + 0x10) + *(short *)((longlong)param_1 + 0x42))
                  ,fVar18,dVar25,auVar49._8_8_,0);
    in_stack_fffffffffffffe70 = fVar18;
  }
LAB_14008ced4:
  in_stack_fffffffffffffe78._8_8_ = dVar20;
  in_stack_fffffffffffffe78._0_8_ = dVar24 + 0.0;
  in_stack_fffffffffffffe70 = (float)((uint)in_stack_fffffffffffffe70 & 0xffff0000);
  FUN_1400c8410((&DAT_140e44660)[iVar8],0x22,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe70,
                dVar24 + 0.0,dVar20,0xff,0xff,0xff,0xff,1,0);
LAB_14008cf53:
  if (param_1[6] == 0x101) {
    iVar9 = param_1[3];
    if (iVar9 % 0x32 < 0xb) {
      dVar21 = (double)FUN_140332d90(((double)(iVar9 % 0x32) - 0.0) * DAT_14053aa88 * dVar21 *
                                     (double)CONCAT44(uVar31,uVar51));
      dVar20 = dVar21 * DAT_14053b0a0 + dVar20;
    }
    if ((0x45 < iVar9) && (uStack_140._4_4_ < 0xf0)) {
      dVar24 = (double)FUN_1403300b4((double)(DAT_140e445dc - uStack_120._4_4_),
                                     SUB84((double)(DAT_140e445d8 - (float)uStack_120),0));
      dVar21 = DAT_14053a0f8;
      iVar8 = (iVar9 + -0x46) % 0x78;
      sVar5 = (short)iVar8 * -400;
      sVar6 = (short)iVar8 * 400;
      if (iVar8 < 0x3c) {
        sVar7 = sVar6 + -12000;
      }
      else {
        sVar7 = sVar5 + -0x7360;
      }
      sVar15 = (short)(int)(dVar24 * DAT_14053aba0);
      sVar7 = sVar7 + sVar15;
      if ((float)param_1[0xc] <= 0.0 && (float)param_1[0xc] != 0.0) {
        sVar7 = sVar5 + sVar15 + 12000;
        if (0x3b < iVar8) {
          sVar7 = sVar6 + sVar15 + 0x7360;
        }
      }
      if (iVar9 + -0x46 == ((iVar9 + -0x46) / 0xe) * 0xe) {
        uVar29 = param_1[0xb];
        iVar9 = 0;
        uVar30 = param_1[10];
        do {
          auVar50._12_4_ = in_stack_fffffffffffffe78._12_4_;
          auVar50._0_8_ = in_stack_fffffffffffffe78._0_8_;
          auVar50._8_4_ = 1;
          in_stack_fffffffffffffe78._8_8_ = auVar50._8_8_;
          in_stack_fffffffffffffe78._0_8_ = dVar21;
          in_stack_fffffffffffffe70 = 0.0;
          FUN_14006c2f0(4,0,uVar30,uVar29,(short)iVar9 * 0x1c2 + sVar7 + -900,0,dVar21,
                        in_stack_fffffffffffffe78._8_8_,0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 5);
        uVar29 = (undefined4)DAT_140539f40;
        uVar30 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
    }
    FUN_1400c8410(DAT_140e448e8,0x22,7,param_1[10],param_1[0xb],
                  (uint)in_stack_fffffffffffffe70 & 0xffff0000,CONCAT44(uVar30,uVar29),dVar20,0xff,
                  0xff,0xff,0xff,1,0);
  }
  if (uStack_130._4_4_ < 1) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((int)local_148 == 0) {
    *param_1 = 0;
  }
  return;
}


