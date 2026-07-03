// Function: FUN_140013c00 @ 140013c00
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140013c00(undefined4 *param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  double dVar8;
  double dVar9;
  undefined1 auVar10 [16];
  longlong lVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  short sVar21;
  int iVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  double dVar29;
  double dVar30;
  float fVar31;
  float fVar32;
  undefined4 uVar33;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar34;
  uint in_stack_fffffffffffffe70;
  undefined1 in_stack_fffffffffffffe78 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined8 in_stack_fffffffffffffe88;
  undefined8 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined8 uStack_130;
  undefined8 uStack_120;
  undefined8 uStack_110;
  
  uVar43 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
  uVar34 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  uStack_120 = 0;
  uStack_120._4_4_ = 0;
  lVar11 = DAT_140e45d80;
  iVar16 = uStack_130._4_4_;
  iVar14 = uStack_120._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar16 = (int)((ulonglong)uStack_130 >> 0x20);
      iVar14 = (int)((ulonglong)uStack_120 >> 0x20);
      if (lVar11 == 0) break;
      if (*(int *)(lVar11 + 4) == DAT_140e44308) {
        uStack_130 = *(undefined8 *)(lVar11 + 8);
        uStack_120 = *(undefined8 *)(lVar11 + 0x18);
        uStack_110 = *(undefined8 *)(lVar11 + 0x28);
      }
      lVar11 = *(longlong *)(lVar11 + 0x60);
    }
  }
  uStack_120._4_4_ = iVar14;
  uStack_130._4_4_ = iVar16;
  fVar24 = (float)param_1[0xd];
  fVar32 = (float)param_1[0xb];
  fVar23 = (float)param_1[0xc];
  fVar31 = (float)param_1[10];
  dVar30 = (double)FUN_1403300b4(SUB84((double)((uStack_110._4_4_ + fVar24) - fVar32),0),
                                 SUB84((double)(((float)uStack_110 + fVar23) - fVar31),0));
  dVar1 = DAT_14053a020;
  dVar29 = DAT_140539d28;
  dVar30 = (double)((int)(dVar30 * DAT_14053aba0) & 0xffff) * DAT_14053a020 * DAT_140539d28;
  fVar23 = (float)FUN_140334430(fVar31 - ((float)uStack_110 + fVar23),DAT_140539fc0);
  fVar24 = (float)FUN_140334430(fVar32 - (uStack_110._4_4_ + fVar24));
  fVar23 = fVar23 + fVar24;
  if (fVar23 < 0.0) {
    fVar23 = (float)FUN_1403352f8(fVar23);
  }
  else {
    fVar23 = SQRT(fVar23);
  }
  uVar28 = SUB84(dVar30,0);
  dVar8 = (double)fVar23 / DAT_14053a1e8;
  dVar30 = (double)FUN_1403307c0(uVar28);
  fVar31 = (float)(dVar30 * dVar8) + fVar31;
  param_1[10] = fVar31;
  dVar30 = (double)FUN_140332d90(uVar28);
  fVar32 = (float)(dVar30 * dVar8) + fVar32;
  param_1[0xb] = fVar32;
  if (param_1[5] == 0) {
    iVar16 = param_1[3];
    if (iVar16 == 0) {
      param_1[0xb] = uStack_110._4_4_;
      param_1[10] = (float)uStack_110;
      fVar31 = (float)uStack_110;
      fVar32 = uStack_110._4_4_;
    }
    dVar9 = (double)iVar16 - 0.0;
    uVar28 = SUB84(dVar9 * DAT_14053a6d8 * dVar1 * dVar29,0);
    dVar30 = (double)FUN_140332d90(uVar28);
    param_1[0xc] = (float)(dVar30 * (double)(float)param_1[0xe]) + 0.0;
    dVar8 = (double)FUN_140332d90(uVar28);
    dVar30 = DAT_140539f40;
    uVar28 = SUB84(DAT_140539f40,0);
    uVar33 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    param_1[0xd] = (float)(dVar8 * (double)(float)param_1[0xf]) + 0.0;
    if (iVar16 < 0) {
      dVar29 = 0.0;
      dVar30 = 0.0;
      goto LAB_140014582;
    }
    if (iVar16 < 10) {
      dVar30 = (double)FUN_140332d90(SUB84(dVar9 * DAT_14053a9d8 * dVar1 * dVar29,0));
      dVar30 = dVar30 + 0.0;
      dVar29 = 0.0;
      goto LAB_140014582;
    }
    if (iVar16 < 0x28) {
      dVar29 = (double)FUN_140332d90(SUB84(((double)iVar16 - DAT_14053a1e8) * DAT_14053a798 * dVar1
                                           * dVar29,0));
      dVar29 = dVar29 + 0.0;
      goto LAB_140014582;
    }
    if (iVar16 == 0x28) {
      param_1[0x15] = 0;
      param_1[3] = 0;
      param_1[5] = 1;
      goto LAB_140013f33;
    }
  }
  else {
    uVar28 = SUB84(DAT_140539f40,0);
    uVar33 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    dVar30 = DAT_140539f40;
    if (param_1[5] == 1) {
LAB_140013f33:
      iVar16 = DAT_140e419b8;
      uVar19 = param_1[1] - DAT_1407c77a0;
      if (0x4f < uStack_130._4_4_) {
        uVar15 = (uStack_130._4_4_ + -0x50) % 0x17c;
        if ((int)uVar15 < 0xc9) {
          uVar26 = 1;
          if (DAT_140e419b8 == 0) {
            uVar26 = 0xf;
          }
          else if (DAT_140e419b8 == 1) {
            uVar26 = 0x17;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            uVar26 = 0x1b;
          }
          else if (DAT_140e419b8 == 4) {
            uVar26 = 0x19;
          }
          iVar14 = 1;
          if (DAT_140e419b8 == 0) {
            iVar14 = 6;
          }
          else if (DAT_140e419b8 == 1) {
            iVar14 = 9;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            iVar14 = 0xc;
          }
          sVar21 = 1;
          iVar14 = iVar14 + uVar19 * 0x38;
          if (DAT_140e419b8 == 0) {
            sVar21 = 0x32;
          }
          else if (DAT_140e419b8 == 1) {
            sVar21 = 0x46;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            sVar21 = 0x50;
          }
          else if (DAT_140e419b8 == 4) {
            sVar21 = 0x78;
          }
          sVar21 = sVar21 + (short)uVar19 * 10;
          if (DAT_140e419b8 == 0) {
            uVar25 = (undefined4)DAT_14053a088;
            uVar27 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
          }
          else if (DAT_140e419b8 == 1) {
            uVar25 = (undefined4)DAT_14053a110;
            uVar27 = (undefined4)((ulonglong)DAT_14053a110 >> 0x20);
          }
          else if (DAT_140e419b8 == 2) {
            uVar25 = (undefined4)DAT_14053a158;
            uVar27 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
          }
          else if (DAT_140e419b8 == 3) {
            uVar25 = (undefined4)DAT_14053a178;
            uVar27 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
          }
          else {
            uVar25 = uVar28;
            uVar27 = uVar33;
            if (DAT_140e419b8 == 4) {
              uVar25 = (undefined4)DAT_14053a1b8;
              uVar27 = (undefined4)((ulonglong)DAT_14053a1b8 >> 0x20);
            }
          }
          dVar29 = (double)(int)uVar19 * DAT_140539f10 + (double)CONCAT44(uVar27,uVar25);
          uVar12 = uVar19 & 0x80000001;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
          }
          if (uVar12 == 1) {
            sVar21 = -sVar21;
          }
          if (uVar15 == uVar19 * 0x32) {
            dVar1 = (double)FUN_1403300b4(SUB84((double)(DAT_140e445dc - fVar32),0),
                                          SUB84((double)(DAT_140e445d8 - fVar31),0));
            *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar1 * DAT_14053aba0);
LAB_140014123:
            if ((((int)uVar15 < iVar14) || (iVar14 == 0)) &&
               (iVar14 = uVar15 + uVar19 * -0x32,
               iVar14 == (iVar14 / 3 + (iVar14 >> 0x1f) +
                         (int)(((longlong)iVar14 / 3 + ((longlong)iVar14 >> 0x3f) & 0xffffffffU) >>
                              0x1f)) * 3)) {
              if ((((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= (float)param_1[10]) &&
                   ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
                  (0.0 <= (float)param_1[0xb])) && ((float)param_1[0xb] <= DAT_14053af14)) {
                uVar42 = CONCAT44(uVar43,uVar26);
                auVar35._12_4_ = in_stack_fffffffffffffe78._12_4_;
                auVar35._0_8_ = in_stack_fffffffffffffe78._0_8_;
                auVar35._8_4_ = 1;
                in_stack_fffffffffffffe78._8_8_ = auVar35._8_8_;
                in_stack_fffffffffffffe78._0_8_ = dVar29;
                in_stack_fffffffffffffe70 = 0;
                uVar25 = CONCAT22(uVar34,*(undefined2 *)((longlong)param_1 + 0x42));
                FUN_1400709b0(4,0,fVar31,fVar32,uVar25,0,dVar29,in_stack_fffffffffffffe78._8_8_,
                              uVar42,0x10000,0);
                uVar43 = (undefined4)((ulonglong)uVar42 >> 0x20);
                uVar34 = (undefined2)((uint)uVar25 >> 0x10);
                if (2 < DAT_140e419b8) {
                  uVar42 = CONCAT44(uVar43,uVar26);
                  auVar36._12_4_ = in_stack_fffffffffffffe78._12_4_;
                  auVar36._0_8_ = in_stack_fffffffffffffe78._0_8_;
                  auVar36._8_4_ = 1;
                  in_stack_fffffffffffffe78._8_8_ = auVar36._8_8_;
                  in_stack_fffffffffffffe78._0_8_ = dVar29 + DAT_140539f68;
                  in_stack_fffffffffffffe70 = 0;
                  uVar26 = CONCAT22(uVar34,*(undefined2 *)((longlong)param_1 + 0x42));
                  FUN_1400709b0(4,0,fVar31,fVar32,uVar26,0,dVar29 + DAT_140539f68,
                                in_stack_fffffffffffffe78._8_8_,uVar42,0x10000,0);
                  uVar43 = (undefined4)((ulonglong)uVar42 >> 0x20);
                  uVar34 = (undefined2)((uint)uVar26 >> 0x10);
                }
              }
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
              iVar16 = DAT_140e419b8;
            }
          }
          else if ((int)(uVar19 * 0x32) <= (int)uVar15) goto LAB_140014123;
          *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar21;
          if ((int)uVar15 < 200) goto LAB_140014558;
        }
        iVar14 = 1;
        if (iVar16 == 0) {
          iVar14 = 0x20;
        }
        else if (iVar16 == 1) {
          iVar14 = 0x12;
        }
        else if ((iVar16 == 2) || (iVar16 == 3)) {
          iVar14 = 0x10;
        }
        else if (iVar16 == 4) {
          iVar14 = 10;
        }
        iVar22 = 1;
        iVar18 = iVar14 * uVar19 + 200;
        if (iVar16 == 0) {
          iVar22 = 0x17;
        }
        else if (iVar16 == 1) {
          iVar22 = 0x1f;
        }
        else if (((iVar16 == 2) || (iVar16 == 3)) || (iVar16 == 4)) {
          iVar22 = 0x23;
        }
        iVar22 = iVar22 + uVar19 * 2;
        if (iVar16 == 0) {
          uVar26 = (undefined4)DAT_14053a048;
          uVar25 = (undefined4)((ulonglong)DAT_14053a048 >> 0x20);
        }
        else if (iVar16 == 1) {
          uVar26 = (undefined4)DAT_14053a0b0;
          uVar25 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
        }
        else if ((iVar16 == 2) || (iVar16 == 3)) {
          uVar26 = (undefined4)DAT_14053a0d0;
          uVar25 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
        }
        else {
          uVar26 = uVar28;
          uVar25 = uVar33;
          if (iVar16 == 4) {
            uVar26 = (undefined4)DAT_14053a118;
            uVar25 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
          }
        }
        dVar29 = (double)(int)uVar19 * DAT_140539ee0 + (double)CONCAT44(uVar25,uVar26);
        if (((iVar18 <= (int)uVar15) && ((int)uVar15 < 0x14a)) &&
           ((int)(uVar15 - iVar18) % (iVar14 * 5) == 0)) {
          if (((DAT_140e445d8 / DAT_14053ab70 + 0.0 <= (float)param_1[10]) &&
              ((float)param_1[10] <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aec0)) &&
             ((0.0 <= (float)param_1[0xb] && ((float)param_1[0xb] <= DAT_14053af14)))) {
            uVar42 = CONCAT44(uVar43,iVar22);
            auVar37._12_4_ = in_stack_fffffffffffffe78._12_4_;
            auVar37._0_8_ = in_stack_fffffffffffffe78._0_8_;
            auVar37._8_4_ = 1;
            auVar38._8_8_ = auVar37._8_8_;
            auVar38._0_8_ = dVar29;
            in_stack_fffffffffffffe70 = 0;
            uVar15 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 1;
            uVar12 = (uVar15 >> 0x1e ^ uVar15) * 0x6c078965 + 2;
            uVar20 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
            uVar19 = uVar15 * 0x800 ^ uVar15;
            uVar17 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 4;
            DAT_140e9fd1c = (uVar17 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ uVar17;
            DAT_140e9fd10 = uVar12;
            DAT_140e9fd14 = uVar20;
            DAT_140e9fd18 = uVar17;
            FUN_1400709b0(3,0,fVar31,fVar32,
                          CONCAT22(uVar34,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),0
                          ,dVar29,auVar38._8_8_,uVar42,0x10000,0);
            uVar43 = (undefined4)((ulonglong)uVar42 >> 0x20);
            if (2 < DAT_140e419b8) {
              uVar42 = CONCAT44(uVar43,iVar22);
              uVar15 = uVar15 * 0x800 ^ uVar15;
              auVar39._12_4_ = auVar38._12_4_;
              auVar39._0_8_ = auVar38._0_8_;
              auVar39._8_4_ = 1;
              in_stack_fffffffffffffe70 = 0;
              DAT_140e9fd1c = (uVar17 >> 0xb ^ uVar15) >> 8 ^ uVar15 ^ uVar17;
              DAT_140e9fd10 = uVar12;
              DAT_140e9fd14 = uVar20;
              DAT_140e9fd18 = uVar17;
              FUN_1400709b0(3,0,fVar31,fVar32,
                            (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001),0,
                            dVar29 + (double)CONCAT44(uVar33,uVar28),auVar39._8_8_,uVar42,0x10000,0)
              ;
              uVar43 = (undefined4)((ulonglong)uVar42 >> 0x20);
            }
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
LAB_140014558:
      FUN_140079c10(param_1,2);
    }
  }
  dVar29 = (double)CONCAT44(uVar33,uVar28);
LAB_140014582:
  uVar27 = (undefined4)((ulonglong)dVar29 >> 0x20);
  uVar25 = SUB84(dVar29,0);
  uVar42 = CONCAT44(uVar43,0xff);
  auVar2._8_4_ = uVar25;
  auVar2._0_8_ = dVar29;
  auVar2._12_4_ = uVar27;
  in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e446d8,0x23,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe70,auVar2,
                uVar42,0xff,0xff,0xff,1,0);
  uVar42 = CONCAT44((int)((ulonglong)uVar42 >> 0x20),0xff);
  auVar40._8_8_ = dVar30;
  auVar40._0_8_ = dVar30;
  in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e446d4,0x23,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe70,dVar30,
                dVar30,uVar42,0xff,0xff,0xff,1,0);
  uVar26 = DAT_140e446dc;
  fVar24 = DAT_14053ac80;
  uVar44 = (undefined4)((ulonglong)uVar42 >> 0x20);
  uVar34 = *(undefined2 *)(param_1 + 0x11);
  fVar32 = (float)param_1[0xb] - DAT_14053ac80;
  uVar43 = param_1[10];
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  puVar13[3] = uVar43;
  puVar13[4] = fVar32;
  *puVar13 = uVar26;
  puVar13[1] = 0x23;
  puVar13[2] = 7;
  *(undefined2 *)(puVar13 + 5) = uVar34;
  auVar3._8_4_ = uVar25;
  auVar3._0_8_ = dVar29;
  auVar3._12_4_ = uVar27;
  *(undefined1 (*) [16])(puVar13 + 6) = auVar3;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = 0xff;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar13;
  }
  uVar26 = DAT_140e446dc;
  fVar32 = (float)param_1[0xb];
  sVar21 = *(short *)(param_1 + 0x11);
  uVar43 = param_1[10];
  DAT_140e46c88 = puVar13;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar13 = uVar26;
  puVar13[1] = 0x23;
  puVar13[2] = 7;
  puVar13[3] = uVar43;
  puVar13[4] = fVar32 - fVar24;
  *(short *)(puVar13 + 5) = sVar21 + 0x3333;
  auVar4._8_4_ = uVar25;
  auVar4._0_8_ = dVar29;
  auVar4._12_4_ = uVar27;
  *(undefined1 (*) [16])(puVar13 + 6) = auVar4;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = 0xff;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  uVar26 = DAT_140e446dc;
  fVar32 = (float)param_1[0xb];
  sVar21 = *(short *)(param_1 + 0x11);
  uVar43 = param_1[10];
  DAT_140e46c88 = puVar13;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar13 = uVar26;
  puVar13[1] = 0x23;
  puVar13[2] = 7;
  puVar13[3] = uVar43;
  puVar13[4] = fVar32 - fVar24;
  *(short *)(puVar13 + 5) = sVar21 + 0x6666;
  auVar5._8_4_ = uVar25;
  auVar5._0_8_ = dVar29;
  auVar5._12_4_ = uVar27;
  *(undefined1 (*) [16])(puVar13 + 6) = auVar5;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = 0xff;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  uVar26 = DAT_140e446dc;
  sVar21 = *(short *)(param_1 + 0x11);
  fVar32 = (float)param_1[0xb];
  uVar43 = param_1[10];
  DAT_140e46c88 = puVar13;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  *puVar13 = uVar26;
  puVar13[1] = 0x23;
  puVar13[2] = 7;
  puVar13[3] = uVar43;
  puVar13[4] = fVar32 - fVar24;
  *(short *)(puVar13 + 5) = sVar21 + -0x6667;
  auVar6._8_4_ = uVar25;
  auVar6._0_8_ = dVar29;
  auVar6._12_4_ = uVar27;
  *(undefined1 (*) [16])(puVar13 + 6) = auVar6;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = 0xff;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  uVar26 = DAT_140e446dc;
  fVar32 = (float)param_1[0xb];
  sVar21 = *(short *)(param_1 + 0x11);
  uVar43 = param_1[10];
  DAT_140e46c88 = puVar13;
  puVar13 = (undefined4 *)_malloc_base(0x48);
  if (puVar13 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  uVar34 = (undefined2)(in_stack_fffffffffffffe70 >> 0x10);
  *puVar13 = uVar26;
  puVar13[1] = 0x23;
  puVar13[2] = 7;
  puVar13[3] = uVar43;
  puVar13[4] = fVar32 - fVar24;
  *(short *)(puVar13 + 5) = sVar21 + -0x3334;
  auVar7._8_4_ = uVar25;
  auVar7._0_8_ = dVar29;
  auVar7._12_4_ = uVar27;
  *(undefined1 (*) [16])(puVar13 + 6) = auVar7;
  puVar13[10] = 0xff;
  puVar13[0xb] = 0xff;
  puVar13[0xc] = 0xff;
  puVar13[0xd] = 0xff;
  *(undefined8 *)(puVar13 + 0xe) = 1;
  *(undefined8 *)(puVar13 + 0x10) = 0;
  _DAT_140e46d1c = _DAT_140e46d1c + 1;
  if (DAT_140e46bf0 == (undefined4 *)0x0) {
    DAT_140e46bf0 = puVar13;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar13;
  }
  DAT_140e46c88 = puVar13;
  if ((param_1[5] == 0) && ((*(byte *)(param_1 + 3) & 1) == 0)) {
    auVar10._8_8_ = 0;
    auVar10._0_8_ = dVar30;
    auVar40 = auVar10 << 0x40;
    in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
    FUN_140070d00(5,DAT_140e446d4,0x22,param_1[10],param_1[0xb],in_stack_fffffffffffffe70,0,dVar30,
                  dVar30,0x18,0xff,0xff,0xff,0x60,0);
    uVar34 = (undefined2)(in_stack_fffffffffffffe70 >> 0x10);
    uVar44 = (undefined4)((ulonglong)dVar30 >> 0x20);
  }
  *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 2000;
  if ((int)param_1[7] < 1) {
    DAT_140e44ac8 = DAT_140e44ac8 + 1;
    FUN_14007b010(param_1,0x708,5);
    FUN_140079e20(param_1,0);
    auVar41._12_4_ = auVar40._12_4_;
    auVar41._0_8_ = auVar40._0_8_;
    auVar41._8_4_ = 10;
    stage_entity_spawn_candidate
              (0x153,(int)param_1[8] / 2,1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar34,0x4000),
               CONCAT44(uVar33,uVar28),auVar41._8_8_,CONCAT44(uVar44,1),DAT_140e44308);
    iVar16 = DAT_140e44308;
    lVar11 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x60)) {
        if (*(int *)(lVar11 + 4) == iVar16) {
          *(int *)(lVar11 + 0x5c) = *(int *)(lVar11 + 0x5c) + -1;
        }
      }
    }
    *param_1 = 0;
  }
  if ((uStack_120._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  return;
}


