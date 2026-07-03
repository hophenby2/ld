// Function: FUN_1400270f0 @ 1400270f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400270f0(undefined4 *param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  short sVar16;
  short sVar17;
  ushort uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  bool bVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  double dVar27;
  double dVar28;
  undefined8 uVar29;
  undefined4 uVar34;
  undefined4 uVar35;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  float fVar36;
  double dVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 local_res20;
  undefined4 uStackX_24;
  uint in_stack_fffffffffffffe48;
  undefined4 in_stack_fffffffffffffe50;
  undefined2 uVar41;
  double in_stack_fffffffffffffe58;
  undefined8 in_stack_fffffffffffffe60;
  ulonglong in_stack_fffffffffffffe68;
  ulonglong uVar42;
  undefined4 uVar43;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined8 local_140;
  undefined8 uStack_128;
  undefined8 uStack_f8;
  
  dVar32 = DAT_14053a020;
  lVar2 = DAT_140e45d80;
  iVar21 = local_140._4_4_;
  iVar14 = uStack_f8._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar21 = (int)((ulonglong)local_140 >> 0x20);
      iVar14 = (int)((ulonglong)uStack_f8 >> 0x20);
      if (lVar2 == 0) break;
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        local_140 = *(undefined8 *)(lVar2 + 0x10);
        uStack_128 = *(undefined8 *)(lVar2 + 0x28);
        uStack_f8 = *(undefined8 *)(lVar2 + 0x58);
      }
      lVar2 = *(longlong *)(lVar2 + 0x60);
    }
  }
  uStack_f8._4_4_ = iVar14;
  local_140._4_4_ = iVar21;
  iVar21 = param_1[6];
  iVar20 = 0;
  iVar14 = (iVar21 == 0x67) + 0x68;
  if (iVar21 == 0x68) {
    iVar14 = 0x6a;
  }
  else if (iVar21 == 0x69) {
    iVar14 = 0x6b;
  }
  else if (iVar21 == 0x6a) {
    iVar14 = 0x6c;
  }
  iVar22 = param_1[5];
  uVar38 = SUB84(DAT_140539d28,0);
  uVar25 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  param_1[0xd] = uStack_128._4_4_ - DAT_14053accc;
  param_1[0xc] = (float)uStack_128;
  if (iVar22 == 0) {
    iVar15 = param_1[3];
    if (iVar15 == 0) {
      param_1[0xe] = 0x44750000;
      *(undefined2 *)(param_1 + 0x10) = 0;
      if (iVar21 == 0x67) {
        fVar24 = (float)param_1[0xe];
        *(undefined2 *)(param_1 + 0x10) = 0xda0a;
      }
      else {
        if (iVar21 != 0x6a) goto LAB_140027294;
        fVar24 = (float)param_1[0xe];
        *(undefined2 *)(param_1 + 0x10) = 0xa5f6;
      }
LAB_1400272aa:
      if (DAT_14053ad9c < fVar24) {
        fVar24 = fVar24 - DAT_14053aca8;
      }
    }
    else {
LAB_140027294:
      fVar24 = (float)param_1[0xe];
      if ((-1 < iVar15) && (iVar15 < 0x1f)) goto LAB_1400272aa;
    }
    param_1[0xe] = fVar24;
    dVar27 = (double)FUN_1403307c0();
    dVar28 = (double)FUN_140332d90();
    param_1[10] = (float)(dVar27 * (double)fVar24) + (float)uStack_128;
    param_1[0xb] = (float)(dVar28 * (double)fVar24) + uStack_128._4_4_;
    uVar3 = DAT_14053a2b8;
    uVar6 = DAT_140539fd8;
    uVar5 = DAT_140539f58;
    if (iVar15 == 0x14) {
      iVar21 = 0;
      iVar22 = 0;
      uVar38 = (undefined4)DAT_14053a248;
      do {
        iVar15 = DAT_140e418c8;
        uVar41 = (undefined2)((uint)in_stack_fffffffffffffe50 >> 0x10);
        iVar13 = DAT_140e418c8 + iVar20;
        uVar19 = ((uint)(iVar22 + DAT_140e418c8) >> 0x1e ^ iVar22 + DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar19 = uVar19 * 0x800 ^ uVar19;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar19 = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
        DAT_140e9fd1c = uVar19;
        uVar29 = FUN_140134db0(iVar13,(int)uVar5,(int)uVar6);
        uVar25 = (undefined4)uVar29;
        uVar34 = (undefined4)((ulonglong)uVar29 >> 0x20);
        uVar29 = FUN_140134db0(iVar13);
        uVar26 = (undefined4)uVar29;
        uVar35 = (undefined4)((ulonglong)uVar29 >> 0x20);
        in_stack_fffffffffffffe58 = (double)FUN_140134db0(iVar21 + iVar15,uVar38,(int)uVar3);
        in_stack_fffffffffffffe68 = CONCAT44(uVar34,uVar25);
        in_stack_fffffffffffffe60 = CONCAT44(uVar35,uVar26);
        in_stack_fffffffffffffe48 = param_1[0xb];
        in_stack_fffffffffffffe50 = CONCAT22(uVar41,(short)uVar19 - (short)(uVar19 / 0x10001));
        FUN_140070d00(0x2c,DAT_140e44ea8,0x48,param_1[10],in_stack_fffffffffffffe48,
                      in_stack_fffffffffffffe50,in_stack_fffffffffffffe58,in_stack_fffffffffffffe60,
                      in_stack_fffffffffffffe68,0,0xff,0xff,0xff,0xc0,0);
        iVar22 = iVar22 + 0x37;
        iVar20 = iVar20 + 0x15b3;
        iVar21 = iVar21 + 0x22b;
      } while (iVar22 < 0x14a);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472e8);
      FUN_14018a340(DAT_140e472e8,1,1);
      iVar22 = param_1[5];
      uVar38 = SUB84(DAT_140539d28,0);
      uVar25 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    }
    if (local_140._4_4_ == 1) {
      iVar22 = iVar22 + 1;
      param_1[8] = 33000;
      param_1[5] = iVar22;
      param_1[7] = 33000;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  dVar27 = DAT_140539f40;
  uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  uVar43 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
  uVar26 = SUB84(DAT_140539f40,0);
  uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  if (iVar22 != 1) goto LAB_14002863e;
  uStack_f8._4_4_ = 5 - uStack_f8._4_4_;
  dVar30 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  dVar30 = dVar30 * DAT_14053aba0;
  iVar20 = (8 - uStack_f8._4_4_) * 0x4b;
  dVar28 = (double)FUN_1403307c0();
  uStack_128._0_4_ = (float)(dVar28 * DAT_14053a548) + (float)uStack_128;
  dVar31 = (double)FUN_140332d90();
  uVar26 = DAT_14053ac2c;
  dVar33 = DAT_14053a0b0;
  dVar31 = dVar31 * DAT_14053a548;
  param_1[10] = (float)uStack_128;
  dVar28 = DAT_14053a070;
  param_1[0xb] = (float)dVar31 + uStack_128._4_4_;
  iVar21 = DAT_140e419b8;
  sVar16 = (short)(int)dVar30;
  if (param_1[6] == 0x66) {
    iVar22 = 1;
    uVar42 = (longlong)(param_1[3] + -0x78) % (longlong)iVar20;
    if (DAT_140e419b8 == 0) {
      iVar22 = 0x18;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      iVar22 = 0x15;
    }
    iVar15 = 1;
    if (DAT_140e419b8 == 0) {
      iVar15 = 9;
    }
    else if (DAT_140e419b8 == 1) {
      iVar15 = 0xf;
    }
    else if (DAT_140e419b8 == 2) {
      iVar15 = 0x12;
    }
    else if (DAT_140e419b8 == 3) {
      iVar15 = 0x15;
    }
    else if (DAT_140e419b8 == 4) {
      iVar15 = 0x18;
    }
    sVar12 = 1;
    if (DAT_140e419b8 == 0) {
      sVar12 = 200;
    }
    else if (DAT_140e419b8 == 1) {
      sVar12 = 0xa0;
    }
    else if (DAT_140e419b8 == 2) {
      sVar12 = 0x8c;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      sVar12 = 0x82;
    }
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 2;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 3;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 4;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar13 = 5;
    }
    iVar13 = iVar13 + uStack_f8._4_4_;
    dVar30 = DAT_14053a030;
    if ((((DAT_140e419b8 != 0) && (dVar30 = dVar28, DAT_140e419b8 != 1)) &&
        (dVar30 = DAT_14053a088, DAT_140e419b8 != 2)) &&
       ((dVar30 = dVar33, DAT_140e419b8 != 3 && (dVar30 = dVar27, DAT_140e419b8 == 4)))) {
      dVar30 = DAT_14053a0f8;
    }
    uVar19 = (uint)uVar42;
    iVar9 = (int)((longlong)((ulonglong)(uint)((int)uVar19 >> 0x1f) << 0x20 | uVar42 & 0xffffffff) %
                 (longlong)iVar22);
    dVar30 = (double)iVar9 * DAT_140539e98 + dVar30 + (double)uStack_f8._4_4_ * DAT_140539f00;
    if (uVar19 == 0) {
      *(short *)((longlong)param_1 + 0x42) = sVar16 + -0x4000;
    }
    sVar17 = sVar12 + *(short *)((longlong)param_1 + 0x42);
    if (0x95 < (int)uVar19) {
      sVar17 = *(short *)((longlong)param_1 + 0x42) - sVar12;
    }
    *(short *)((longlong)param_1 + 0x42) = sVar17;
    if (uStack_f8._4_4_ == 4) {
      iVar13 = iVar13 + -1;
    }
    if (((uVar19 < 300) && (iVar9 < iVar15)) &&
       (iVar22 = (int)((longlong)
                       ((ulonglong)(uint)((int)uVar19 >> 0x1f) << 0x20 | uVar42 & 0xffffffff) %
                      (longlong)iVar22),
       iVar22 == (iVar22 / 3 + (iVar22 >> 0x1f) +
                 (int)(((longlong)iVar22 / 3 + ((longlong)iVar22 >> 0x3f) & 0xffffffffU) >> 0x1f)) *
                 3)) {
      in_stack_fffffffffffffe68 = CONCAT44((int)(in_stack_fffffffffffffe68 >> 0x20),iVar13);
      in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
      in_stack_fffffffffffffe48 = CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),sVar17);
      in_stack_fffffffffffffe58 = dVar30;
      FUN_1400709b0(10,0,(float)uStack_128,param_1[0xb],in_stack_fffffffffffffe48,uVar26,dVar30,
                    in_stack_fffffffffffffe60,in_stack_fffffffffffffe68,0x10000,0);
      if (uStack_f8._4_4_ == 4) {
        in_stack_fffffffffffffe68 = CONCAT44((int)(in_stack_fffffffffffffe68 >> 0x20),iVar13);
        in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
        in_stack_fffffffffffffe48 =
             CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                      (short)(0x10000 / (longlong)(iVar13 * 2)) +
                      *(short *)((longlong)param_1 + 0x42));
        FUN_1400709b0(0xb,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe48,uVar26,dVar30,
                      in_stack_fffffffffffffe60,in_stack_fffffffffffffe68,0x10000,0);
        in_stack_fffffffffffffe58 = dVar30;
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar21 = DAT_140e419b8;
    }
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + 0x42;
  }
  if (param_1[6] == 0x67) {
    iVar14 = 1;
    uVar42 = (longlong)(param_1[3] + -0xf0) % (longlong)iVar20;
    if (iVar21 == 0) {
      iVar14 = 0x46;
    }
    else if (iVar21 == 1) {
      iVar14 = 0x29;
    }
    else if (iVar21 == 2) {
      iVar14 = 0x23;
    }
    else if (iVar21 == 3) {
      iVar14 = 0x21;
    }
    else if (iVar21 == 4) {
      iVar14 = 0x1e;
    }
    iVar22 = 1;
    if (iVar21 == 0) {
      iVar22 = 3;
    }
    else if (iVar21 == 1) {
      iVar22 = 5;
    }
    else if (iVar21 == 2) {
      iVar22 = 7;
    }
    else if (iVar21 == 3) {
      iVar22 = 9;
    }
    else if (iVar21 == 4) {
      iVar22 = 0xb;
    }
    iVar22 = iVar22 + uStack_f8._4_4_ * 2;
    iVar15 = 1;
    if (iVar21 == 0) {
      iVar15 = 5000;
    }
    else if (iVar21 == 1) {
      iVar15 = 0xed8;
    }
    else if (iVar21 == 2) {
      iVar15 = 0xce4;
    }
    else if (iVar21 == 3) {
      iVar15 = 3000;
    }
    else if (iVar21 == 4) {
      iVar15 = 0xa8c;
    }
    dVar30 = DAT_14053a018;
    if ((((iVar21 != 0) && (dVar30 = DAT_14053a048, iVar21 != 1)) && (dVar30 = dVar28, iVar21 != 2))
       && ((dVar30 = DAT_14053a078, iVar21 != 3 && (dVar30 = dVar27, iVar21 == 4)))) {
      dVar30 = DAT_14053a0a0;
    }
    uVar11 = (uint)uVar42;
    dVar27 = (double)(int)uVar11 * _DAT_140539d98 + dVar30 + (double)uStack_f8._4_4_ * DAT_140539ec8
    ;
    dVar32 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * _DAT_14053a780 * dVar32 *
                                   (double)CONCAT44(uVar25,uVar38));
    uVar41 = (undefined2)(in_stack_fffffffffffffe48 >> 0x10);
    uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
    uVar25 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
    uVar1 = *(ushort *)(param_1 + 0x10);
    uVar18 = (short)(int)(dVar32 * _DAT_14053aad8) + sVar16;
    uVar4 = uVar1 - uVar18;
    *(ushort *)((longlong)param_1 + 0x42) = uVar18;
    uVar19 = (uint)uVar4;
    if (0x8000 < uVar4) {
      uVar19 = 0x10000 - uVar4;
    }
    iVar9 = (uint)uVar18 - (uint)uVar1;
    iVar10 = (int)uVar19 / 0x14 + 0x30;
    iVar13 = iVar9 + 0x10000;
    if (-0x8001 < iVar9) {
      iVar13 = iVar9;
    }
    iVar9 = iVar13 + -0x10000;
    if (iVar13 < 0x8001) {
      iVar9 = iVar13;
    }
    if (iVar9 < 1) {
      uVar4 = uVar1;
      if ((iVar9 < 0) && (uVar4 = uVar1 - (short)iVar10, -iVar10 < iVar9)) {
        uVar4 = uVar18;
      }
    }
    else {
      uVar4 = uVar18;
      if (iVar10 <= iVar9) {
        uVar4 = uVar1 + (short)iVar10;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar4;
    if ((uVar11 < 300) &&
       ((int)((longlong)((ulonglong)(uint)((int)uVar11 >> 0x1f) << 0x20 | uVar42 & 0xffffffff) %
             (longlong)(iVar14 + uStack_f8._4_4_ * -4)) == 0)) {
      dVar32 = (double)FUN_1403307c0();
      dVar32 = dVar32 * DAT_14053a3d0;
      fVar24 = (float)param_1[10];
      dVar33 = (double)FUN_140332d90();
      in_stack_fffffffffffffe68 = CONCAT44(uVar25,iVar22);
      in_stack_fffffffffffffe60 = CONCAT44(uVar38,1);
      in_stack_fffffffffffffe48 = CONCAT22(uVar41,uVar4);
      FUN_1400709b0(3,0,(float)dVar32 + fVar24,(float)(dVar33 * DAT_14053a3d0) + (float)param_1[0xb]
                    ,in_stack_fffffffffffffe48,uVar26,dVar27,in_stack_fffffffffffffe60,
                    in_stack_fffffffffffffe68,(iVar22 + -1) * iVar15,0);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar21 = DAT_140e419b8;
      dVar33 = DAT_14053a0b0;
      in_stack_fffffffffffffe58 = dVar27;
    }
    iVar14 = 0x69;
  }
  dVar31 = DAT_14053a390;
  dVar30 = DAT_14053a040;
  dVar27 = DAT_14053a010;
  dVar32 = DAT_140539f68;
  uVar38 = SUB84(DAT_14053a060,0);
  uVar25 = (undefined4)((ulonglong)DAT_14053a060 >> 0x20);
  if (param_1[6] == 0x68) {
    iVar14 = 1;
    uVar42 = (longlong)(param_1[3] + -0x168) % (longlong)iVar20;
    if (iVar21 == 0) {
      iVar14 = 0x10;
    }
    else if (iVar21 == 1) {
      iVar14 = 10;
    }
    else if ((iVar21 == 2) || (iVar21 == 3)) {
      iVar14 = 8;
    }
    else if (iVar21 == 4) {
      iVar14 = 7;
    }
    dVar37 = DAT_14053a010;
    if ((((iVar21 != 0) && (dVar37 = DAT_14053a040, iVar21 != 1)) &&
        (dVar37 = DAT_14053a060, iVar21 != 2)) &&
       ((dVar37 = dVar28, iVar21 != 3 && (dVar37 = DAT_140539f40, iVar21 == 4)))) {
      dVar37 = dVar33;
    }
    sVar16 = 1;
    dVar37 = (double)uStack_f8._4_4_ * DAT_140539ef8 + dVar37;
    if (iVar21 == 0) {
      sVar16 = 0x82;
    }
    else if (iVar21 == 1) {
      sVar16 = 0xaa;
    }
    else if (iVar21 == 2) {
      sVar16 = 0xbe;
    }
    else if (iVar21 == 3) {
      sVar16 = 200;
    }
    else if (iVar21 == 4) {
      sVar16 = 0xf0;
    }
    uVar19 = (uint)uVar42;
    if ((uVar19 < 300) &&
       ((int)((longlong)((ulonglong)(uint)((int)uVar19 >> 0x1f) << 0x20 | uVar42 & 0xffffffff) %
             (longlong)(iVar14 - uStack_f8._4_4_)) == 0)) {
      iVar21 = 0;
      do {
        uVar41 = (undefined2)(in_stack_fffffffffffffe48 >> 0x10);
        uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
        sVar12 = *(short *)(param_1 + 0x10);
        sVar17 = (short)iVar21 * 0x4000;
        dVar28 = (double)FUN_1403307c0();
        fVar36 = (float)(dVar28 * dVar31) + (float)param_1[10];
        dVar28 = (double)FUN_140332d90();
        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
        in_stack_fffffffffffffe60 = CONCAT44(uVar38,1);
        in_stack_fffffffffffffe48 =
             CONCAT22(uVar41,sVar16 * *(short *)(param_1 + 3) + sVar17 + sVar12);
        fVar24 = (float)(dVar28 * dVar31) + (float)param_1[0xb];
        in_stack_fffffffffffffe58 = dVar37;
        FUN_14006c2f0(7,0,fVar36,fVar24,in_stack_fffffffffffffe48,uVar26,dVar37,
                      in_stack_fffffffffffffe60,in_stack_fffffffffffffe68);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
          in_stack_fffffffffffffe58 = dVar37 + dVar32;
          in_stack_fffffffffffffe60 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
          in_stack_fffffffffffffe48 =
               CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                        sVar16 * *(short *)(param_1 + 3) + *(short *)(param_1 + 0x10) + sVar17);
          FUN_14006c2f0(7,0,fVar36,fVar24,in_stack_fffffffffffffe48,uVar26,in_stack_fffffffffffffe58
                        ,in_stack_fffffffffffffe60,in_stack_fffffffffffffe68);
        }
        if (uStack_f8._4_4_ == 4) {
          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
          in_stack_fffffffffffffe60 =
               CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
          in_stack_fffffffffffffe48 =
               CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                        sVar16 * *(short *)(param_1 + 3) + *(short *)(param_1 + 0x10) + sVar17 +
                        0x1a04);
          in_stack_fffffffffffffe58 = dVar37;
          FUN_14006c2f0(7,0,fVar36,fVar24,in_stack_fffffffffffffe48,uVar26,dVar37,
                        in_stack_fffffffffffffe60,in_stack_fffffffffffffe68);
          if (2 < DAT_140e419b8) {
            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
            in_stack_fffffffffffffe58 = dVar37 + dVar32;
            in_stack_fffffffffffffe60 =
                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
            in_stack_fffffffffffffe48 =
                 CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                          sVar16 * *(short *)(param_1 + 3) + *(short *)(param_1 + 0x10) + sVar17 +
                          0x1a04);
            FUN_14006c2f0(7,0,fVar36,fVar24,in_stack_fffffffffffffe48,uVar26,
                          in_stack_fffffffffffffe58,in_stack_fffffffffffffe60,
                          in_stack_fffffffffffffe68);
          }
        }
        iVar21 = iVar21 + 1;
      } while (iVar21 < 4);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      uVar38 = SUB84(DAT_14053a060,0);
      uVar25 = (undefined4)((ulonglong)DAT_14053a060 >> 0x20);
      iVar21 = DAT_140e419b8;
      dVar28 = DAT_14053a070;
    }
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + 99;
    iVar14 = 0x6a;
  }
  dVar31 = DAT_14053aa50;
  dVar33 = DAT_14053a020;
  dVar32 = DAT_140539ef8;
  uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
  uVar43 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
  uVar39 = SUB84(DAT_14053a6e8,0);
  uVar40 = (undefined4)((ulonglong)DAT_14053a6e8 >> 0x20);
  if (param_1[6] == 0x69) {
    uVar42 = (longlong)(param_1[3] + -0x1e0) % (longlong)iVar20;
    iVar14 = 1;
    if (iVar21 == 0) {
      iVar14 = 0x11;
    }
    else if (iVar21 == 1) {
      iVar14 = 0xb;
    }
    else if ((iVar21 == 2) || (iVar21 == 3)) {
      iVar14 = 10;
    }
    else if (iVar21 == 4) {
      iVar14 = 9;
    }
    iVar22 = 1;
    if (iVar21 != 0) {
      if (iVar21 == 1) {
        iVar22 = 2;
      }
      else if (iVar21 == 2) {
        iVar22 = 3;
      }
      else if (iVar21 == 3) {
        iVar22 = 4;
      }
      else if (iVar21 == 4) {
        iVar22 = 5;
      }
    }
    if ((iVar21 != 0) && (dVar27 = dVar30, iVar21 != 1)) {
      if (iVar21 == 2) {
        dVar27 = (double)CONCAT44(uVar25,uVar38);
      }
      else {
        dVar27 = dVar28;
        if ((iVar21 != 3) && (dVar27 = DAT_140539f40, iVar21 == 4)) {
          dVar27 = DAT_14053a0b0;
        }
      }
    }
    sVar16 = 1;
    dVar28 = (double)uStack_f8._4_4_ * DAT_140539ef8;
    if (iVar21 == 0) {
      sVar16 = 0x96;
    }
    else if (iVar21 == 1) {
      sVar16 = 0xf0;
    }
    else if (iVar21 == 2) {
      sVar16 = 0x10e;
    }
    else if (iVar21 == 3) {
      sVar16 = 300;
    }
    else if (iVar21 == 4) {
      sVar16 = 0x154;
    }
    if (uStack_f8._4_4_ == 4) {
      iVar22 = iVar22 + 2;
    }
    dVar30 = (double)FUN_140332d90(((double)(int)param_1[3] - _DAT_140539cc0) * DAT_14053a6e8 *
                                   DAT_14053a020 * DAT_140539d28);
    uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
    uVar43 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
    *(short *)(param_1 + 0x10) = (short)(int)(dVar30 * dVar31);
    uVar19 = DAT_14053ac60;
    uVar11 = (uint)uVar42;
    if ((uVar11 < 300) &&
       ((int)((longlong)((ulonglong)(uint)((int)uVar11 >> 0x1f) << 0x20 | uVar42 & 0xffffffff) %
             (longlong)(iVar14 - uStack_f8._4_4_)) == 0)) {
      uVar5 = FUN_140133f30();
      uVar6 = FUN_140133f30();
      uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
      uVar43 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
      iVar21 = 0;
      if (iVar22 != 0) {
        uStackX_24 = (undefined4)((ulonglong)uVar5 >> 0x20);
        local_res20 = (undefined4)uVar5;
        uStack_154 = (undefined4)((ulonglong)uVar6 >> 0x20);
        local_158 = (undefined4)uVar6;
        do {
          uVar42 = in_stack_fffffffffffffe68 & 0xffffffff00000000;
          uVar5 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe60 >> 0x20),1);
          sVar12 = (short)iVar21 * 0xd05;
          in_stack_fffffffffffffe58 = (double)iVar21 * dVar32 + dVar28 + dVar27;
          uVar38 = CONCAT22((short)(uVar19 >> 0x10),
                            sVar16 * *(short *)(param_1 + 3) + sVar12 + -0x8000);
          FUN_14006c2f0(4,0,local_res20,uStackX_24,uVar38,0,in_stack_fffffffffffffe58,uVar5,uVar42);
          in_stack_fffffffffffffe68 = uVar42 & 0xffffffff00000000;
          in_stack_fffffffffffffe60 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),1);
          uVar19 = CONCAT22((short)((uint)uVar38 >> 0x10),sVar16 * *(short *)(param_1 + 3) + sVar12)
          ;
          FUN_14006c2f0(4,0,local_158,uStack_154,uVar19,0,in_stack_fffffffffffffe58,
                        in_stack_fffffffffffffe60,in_stack_fffffffffffffe68);
          uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe60 >> 0x20);
          uVar43 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);
          iVar21 = iVar21 + 1;
        } while (iVar21 < iVar22);
        uVar39 = SUB84(DAT_14053a6e8,0);
        uVar40 = (undefined4)((ulonglong)DAT_14053a6e8 >> 0x20);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      iVar21 = DAT_140e419b8;
      in_stack_fffffffffffffe48 = uVar19;
    }
    iVar14 = 0x6b;
  }
  dVar32 = DAT_140539d28;
  if (param_1[6] != 0x6a) {
    uVar26 = SUB84(DAT_140539f40,0);
    uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    goto LAB_14002863e;
  }
  dVar27 = (double)FUN_1403307c0();
  fVar36 = (float)(dVar27 * DAT_14053a3f8) + (float)param_1[10];
  dVar27 = (double)FUN_140332d90();
  fVar24 = (float)(dVar27 * DAT_14053a3f8) + (float)param_1[0xb];
  dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar24),
                                 SUB84((double)(DAT_140e445d8 - fVar36),0));
  iVar14 = 1;
  dVar27 = dVar27 * DAT_14053aba0;
  uVar42 = (longlong)(int)param_1[3] % (longlong)iVar20;
  if (iVar21 == 0) {
    iVar14 = 0x5a;
  }
  else if (iVar21 == 1) {
    iVar14 = 0x3c;
  }
  else if (iVar21 == 2) {
    iVar14 = 0x37;
  }
  else if ((iVar21 == 3) || (iVar21 == 4)) {
    iVar14 = 0x32;
  }
  iVar20 = 1;
  if ((iVar21 == 0) || (iVar21 == 1)) {
    iVar20 = 0x10;
  }
  else if (iVar21 == 2) {
    iVar20 = 0x14;
  }
  else if (iVar21 == 3) {
    iVar20 = 0x18;
  }
  else if (iVar21 == 4) {
    iVar20 = 0x1c;
  }
  uVar26 = SUB84(DAT_140539f40,0);
  uVar34 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  dVar28 = DAT_14053a0b0;
  if ((((iVar21 != 0) && (dVar28 = DAT_14053a0f8, iVar21 != 1)) &&
      (dVar28 = DAT_14053a118, iVar21 != 2)) &&
     ((dVar28 = DAT_14053a138, iVar21 != 3 && (dVar28 = DAT_140539f40, iVar21 == 4)))) {
    dVar28 = DAT_14053a1b8;
  }
  dVar28 = (double)uStack_f8._4_4_ * DAT_140539f18 + dVar28;
  dVar32 = (double)FUN_140332d90(((double)(int)param_1[3] - _DAT_140539cc0) *
                                 (double)CONCAT44(uVar40,uVar39) * dVar33 * dVar32);
  *(short *)(param_1 + 0x10) = (short)(int)(dVar32 * dVar31) + -0x5a0a;
  uVar19 = (uint)uVar42;
  if (uVar19 < 300) {
    uVar11 = (int)uVar19 >> 0x1f;
    if ((int)((longlong)((ulonglong)uVar11 << 0x20 | uVar42 & 0xffffffff) % (longlong)iVar14) == 0)
    {
      *(short *)((longlong)param_1 + 0x42) = (short)(int)dVar27;
    }
    else if (299 < uVar19) goto LAB_140028619;
    uVar38 = DAT_14053ac2c;
    uVar19 = (uint)((longlong)((ulonglong)uVar11 << 0x20 | uVar42 & 0xffffffff) % (longlong)iVar14);
    if ((int)uVar19 < iVar20 + uStack_f8._4_4_ * 4) {
      uVar19 = uVar19 & 0x80000003;
      if ((int)uVar19 < 0) {
        uVar19 = (uVar19 - 1 | 0xfffffffc) + 1;
      }
      if (uVar19 == 0) {
        iVar21 = (int)((longlong)((ulonglong)uVar11 << 0x20 | uVar42 & 0xffffffff) %
                      (longlong)iVar14);
        iVar21 = (int)(iVar21 + (iVar21 >> 0x1f & 3U)) >> 2;
        iVar14 = iVar21 * (uStack_f8._4_4_ * 0x28 + 300);
        iVar21 = iVar21 + 1;
        uVar6 = CONCAT44(uVar43,iVar21);
        uVar5 = CONCAT44(uVar35,1);
        in_stack_fffffffffffffe48 =
             CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                      *(undefined2 *)((longlong)param_1 + 0x42));
        in_stack_fffffffffffffe58 = dVar28;
        FUN_1400709b0(9,0,fVar36,fVar24,in_stack_fffffffffffffe48,DAT_14053ac2c,dVar28,uVar5,uVar6,
                      iVar14,0);
        uVar35 = (undefined4)((ulonglong)uVar5 >> 0x20);
        uVar43 = (undefined4)((ulonglong)uVar6 >> 0x20);
        if (uStack_f8._4_4_ == 4) {
          uVar6 = CONCAT44(uVar43,iVar21);
          uVar5 = CONCAT44(uVar35,1);
          uVar25 = CONCAT22((short)(in_stack_fffffffffffffe48 >> 0x10),
                            *(short *)((longlong)param_1 + 0x42) + 7000);
          FUN_1400709b0(9,0,fVar36,fVar24,uVar25,uVar38,dVar28,uVar5,uVar6,iVar14,0);
          uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),iVar21);
          uVar5 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),1);
          in_stack_fffffffffffffe48 =
               CONCAT22((short)((uint)uVar25 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -7000);
          FUN_1400709b0(9,0,fVar36,fVar24,in_stack_fffffffffffffe48,uVar38,dVar28,uVar5,uVar6,iVar14
                        ,0);
          uVar35 = (undefined4)((ulonglong)uVar5 >> 0x20);
          uVar43 = (undefined4)((ulonglong)uVar6 >> 0x20);
          in_stack_fffffffffffffe58 = dVar28;
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
  }
LAB_140028619:
  iVar14 = 0x6c;
LAB_14002863e:
  uVar41 = *(undefined2 *)(param_1 + 0x10);
  uVar38 = param_1[0xb];
  uVar25 = param_1[10];
  uVar39 = (&DAT_140e44ad0)[iVar14];
  puVar7 = (undefined4 *)_malloc_base(0x48);
  if (puVar7 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  bVar23 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar7[3] = uVar25;
  puVar7[4] = uVar38;
  *puVar7 = uVar39;
  puVar7[1] = 0x23;
  puVar7[2] = 7;
  *(undefined2 *)(puVar7 + 5) = uVar41;
  *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
  puVar7[10] = 0xff;
  puVar7[0xb] = 0xff;
  puVar7[0xc] = 0xff;
  puVar7[0xd] = 0xff;
  *(undefined8 *)(puVar7 + 0xe) = 1;
  *(undefined8 *)(puVar7 + 0x10) = 0;
  if (bVar23) {
    DAT_140e46bf0 = puVar7;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar7;
  }
  puVar8 = DAT_140e45d28;
  DAT_140e46c88 = puVar7;
  if ((param_1[5] == 0) && ((int)param_1[3] < 0x14)) {
    uVar41 = *(undefined2 *)(param_1 + 0x10);
    uVar38 = param_1[0xb];
    uVar25 = param_1[10];
    uVar39 = (&DAT_140e44ad0)[iVar14];
    if (DAT_140e45d1c < 0x1000) {
      puVar8 = (undefined8 *)_malloc_base(0x60);
      if (puVar8 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar23 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)((longlong)puVar8 + 0x14) = uVar25;
      *(undefined4 *)(puVar8 + 3) = uVar38;
      *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar25;
      *(undefined4 *)(puVar8 + 4) = uVar38;
      *puVar8 = 1;
      *(undefined4 *)(puVar8 + 1) = 5;
      *(undefined4 *)((longlong)puVar8 + 0xc) = uVar39;
      *(undefined4 *)(puVar8 + 2) = 0x24;
      *(undefined2 *)((longlong)puVar8 + 0x24) = uVar41;
      puVar8[5] = 0;
      puVar8[6] = 0x3ff0000000000000;
      puVar8[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar8 + 8) = 0x14;
      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
      *(undefined4 *)(puVar8 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
      puVar8[10] = 0x60;
      puVar8[0xb] = 0;
      if (bVar23) {
        DAT_140e45d78 = puVar8;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar8;
      }
    }
  }
  DAT_140e45d28 = puVar8;
  if (param_1[0x15] == 0) {
    in_stack_fffffffffffffe48 = DAT_14053b370;
    FUN_140079c10(param_1,1);
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,3000,0x12);
    uVar41 = 0;
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffe48 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffe58 & 0xffffffff00000000);
    stage_entity_spawn_candidate
              (0x153,20000,1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar41,0x4000),
               CONCAT44(uVar34,uVar26),CONCAT44(uVar35,10),CONCAT44(uVar43,1),DAT_140e44308);
    iVar21 = DAT_140e44308;
    lVar2 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
        if (*(int *)(lVar2 + 4) == iVar21) {
          *(int *)(lVar2 + 0x5c) = *(int *)(lVar2 + 0x5c) + -1;
        }
      }
    }
    FUN_140079e20(param_1,2);
    *param_1 = 0;
  }
  if (((param_1[5] == 1) && (DAT_140e4430c < 1)) || (1 < local_140._4_4_)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


