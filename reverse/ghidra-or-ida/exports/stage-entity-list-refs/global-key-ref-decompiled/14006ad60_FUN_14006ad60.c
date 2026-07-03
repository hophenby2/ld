// Function: FUN_14006ad60 @ 14006ad60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14006ad60(undefined4 *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  longlong lVar9;
  double dVar10;
  double dVar11;
  undefined8 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined8 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  short sVar22;
  int iVar23;
  bool bVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  uint in_stack_fffffffffffffe78;
  uint in_stack_fffffffffffffe80;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined2 uVar31;
  undefined1 in_stack_fffffffffffffe88 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined8 uVar41;
  int iStack_114;
  int iStack_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined1 local_c0 [152];
  
  uVar12 = _UNK_14053bb28;
  dVar11 = _DAT_14053bb20;
  dVar10 = DAT_14053a020;
  dVar26 = DAT_140539d28;
  iVar21 = 0;
  iStack_10c = 0;
  iVar13 = 0;
  iVar15 = 0;
  lVar9 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_10c = iVar15, lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == DAT_140e44308) {
        iStack_114 = *(int *)(lVar9 + 0x14);
        iStack_10c = *(int *)(lVar9 + 0x1c);
        local_108 = *(undefined8 *)(lVar9 + 0x20);
        uStack_100 = *(undefined8 *)(lVar9 + 0x28);
      }
      iVar15 = iStack_10c;
    }
  }
  dVar25 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * DAT_14053a698 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar25 = dVar25 * DAT_14053a950;
  if ((iStack_114 == 0x98) && ((int)param_1[5] < 99)) {
    FUN_140079e20(param_1,2);
    if (DAT_140e4430c < 0x5dc) {
      stage_pending_effect_flush_candidate();
      if (DAT_140e44654 < 100) {
        DAT_140e44654 = 100;
      }
    }
    else {
      auVar32._12_4_ = 0;
      auVar32._0_12_ = in_stack_fffffffffffffe88._4_12_;
      auVar32 = auVar32 << 0x20;
      in_stack_fffffffffffffe80 = 0;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,in_stack_fffffffffffffe78 & 0xffff0000,0,auVar32
                   );
      auVar33._12_4_ = auVar32._12_4_;
      auVar33._0_8_ = auVar32._0_8_;
      auVar33._8_4_ = param_1[0x14];
      in_stack_fffffffffffffe88._8_8_ = auVar33._8_8_;
      in_stack_fffffffffffffe88._0_8_ = DAT_14053a4f0;
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      stage_entity_spawn_candidate
                (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,DAT_14053a4f0,
                 in_stack_fffffffffffffe88._8_8_,1,0);
    }
    param_1[3] = 0;
    param_1[5] = 99;
    param_1[0x17] = 0;
  }
  uVar31 = (undefined2)(in_stack_fffffffffffffe80 >> 0x10);
  iVar15 = param_1[5];
  param_1[10] = (undefined4)uStack_100;
  param_1[0x15] = 1;
  param_1[0xb] = uStack_100._4_4_ + DAT_14053accc;
  uVar29 = DAT_14053b394;
  dVar28 = DAT_14053b188;
  dVar27 = DAT_14053a558;
  if (iVar15 == 0) {
    iVar13 = param_1[3];
    puVar16 = (undefined8 *)FUN_140135060(local_c0,iVar13,0x14);
    dVar27 = DAT_14053a798;
    dVar25 = DAT_14053a5f8;
    uVar41 = *puVar16;
    uVar29 = *(undefined4 *)(puVar16 + 1);
    iVar15 = 0;
    if (iVar13 < 0x96) {
      if (iVar13 < 0x5a) {
        iVar14 = (iVar13 >> 0x1f & 0xffffff01U) + 0xff;
        if (-1 < iVar13) {
          dVar28 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a558 * dVar10 * dVar26);
          iVar14 = (int)(dVar28 * dVar25);
        }
        iVar23 = iVar15;
        iVar18 = iVar21;
        if (iVar13 < 0x78) {
          iVar18 = iVar14;
        }
      }
      else {
        dVar28 = (double)FUN_140332d90(((double)iVar13 - DAT_14053a430) * DAT_14053a798 * dVar10 *
                                       dVar26);
        iVar23 = (int)(dVar28 * dVar25);
        iVar18 = 0;
        if (iVar13 < 0x78) {
          dVar28 = (double)FUN_140332d90(((double)iVar13 - DAT_14053a3a0) * dVar27 * dVar10 * dVar26
                                        );
          if (iVar13 < 0x78) {
            iVar21 = (int)(dVar28 * dVar25);
          }
          iVar18 = iVar21;
          if (iVar13 == 0x5a) {
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
            FUN_14018a340(DAT_140e472bc,1,1);
          }
        }
      }
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44aac,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,0xff,0xff,0xff,iVar23,1,0,uVar41);
      in_stack_fffffffffffffe88._8_8_ = uVar12;
      in_stack_fffffffffffffe88._0_8_ = dVar11;
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44aac,0x1e,8,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,(int)uVar41,(int)((ulonglong)uVar41 >> 0x20),uVar29,iVar18,1,0);
    }
    uVar19 = param_1[3];
    if (uVar19 - 0x78 < 0x5a) {
      if ((int)uVar19 < 0x96) {
LAB_14006be2b:
        iVar21 = 0;
        if ((int)uVar19 < 0xd2) {
          iVar21 = iVar15;
        }
        iVar15 = 0;
        if (0x77 < (int)uVar19) {
          iVar15 = 0xff;
          if (0x95 < (int)uVar19) {
            if (uVar19 < 0xb4) goto LAB_14006bffb;
            goto LAB_14006c026;
          }
          dVar28 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a4a0) * dVar27 * dVar10 *
                                         dVar26);
          iVar15 = (int)(dVar28 * dVar25);
        }
        iVar13 = 0;
        if ((int)uVar19 < 0xb4) {
          iVar13 = iVar15;
        }
      }
      else if ((int)uVar19 < 0xb4) {
        dVar28 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a510) * dVar27 * dVar10 *
                                       dVar26);
        iVar21 = (int)(dVar28 * dVar25);
LAB_14006bffb:
        dVar28 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a4a0) * dVar27 * dVar10 *
                                       dVar26);
        iVar15 = (int)(dVar28 * dVar25);
LAB_14006c026:
        iVar13 = 0;
        if ((int)uVar19 < 0xb4) {
          iVar13 = iVar15;
        }
        if (uVar19 == 0x96) {
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
          FUN_14018a340(DAT_140e472bc,1,1);
        }
      }
      else {
        iVar15 = 0xff;
        if (0xd1 < (int)uVar19) goto LAB_14006be2b;
        dVar28 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a510) * dVar27 * dVar10 *
                                       dVar26);
        iVar13 = 0;
        iVar21 = (int)(dVar28 * dVar25);
      }
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44ab0,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,0xff,0xff,0xff,iVar21,1,0);
      in_stack_fffffffffffffe88._8_8_ = uVar12;
      in_stack_fffffffffffffe88._0_8_ = dVar11;
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44ab0,0x1e,8,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,(int)uVar41,(int)((ulonglong)uVar41 >> 0x20),uVar29,iVar13,1,0);
    }
    uVar19 = param_1[3];
    if (0xb3 < (int)uVar19) {
      if ((int)uVar19 < 0xd2) {
        dVar26 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a548) * dVar27 * dVar10 *
                                       dVar26);
        iVar21 = 0;
LAB_14006c0cb:
        iVar15 = (int)(dVar26 * dVar25);
      }
      else {
        if ((int)uVar19 < 0xf0) {
          dVar28 = (double)FUN_140332d90(((double)(int)uVar19 - _DAT_14053a5b0) * dVar27 * dVar10 *
                                         dVar26);
          iVar13 = (int)(dVar28 * dVar25);
LAB_14006c0a8:
          iVar21 = iVar13;
          dVar26 = (double)FUN_140332d90(((double)(int)uVar19 - DAT_14053a548) * dVar27 * dVar10 *
                                         dVar26);
          goto LAB_14006c0cb;
        }
        iVar15 = 0xff;
        iVar21 = 0xff;
        iVar13 = 0xff;
        if (uVar19 < 0xf0) goto LAB_14006c0a8;
      }
      iVar13 = 0;
      if (uVar19 < 0xf0) {
        iVar13 = iVar15;
      }
      if (uVar19 == 0xd2) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44ab4,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,0xff,0xff,0xff,iVar21,1,0);
      in_stack_fffffffffffffe88._8_8_ = uVar12;
      in_stack_fffffffffffffe88._0_8_ = dVar11;
      in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
      FUN_1400c8410(DAT_140e44ab4,0x1e,8,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,dVar11,
                    uVar12,(int)uVar41,(int)((ulonglong)uVar41 >> 0x20),uVar29,iVar13,1,0);
    }
    if (param_1[3] == 0xfa) {
      param_1[5] = param_1[5] + 1;
      param_1[8] = (undefined4)local_108;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
      param_1[3] = 0;
      param_1[7] = iStack_10c;
    }
    goto LAB_14006c1e1;
  }
  if (((iVar15 != 1) && (iVar15 != 2)) && (iVar15 != 3)) {
    if (iVar15 != 99) goto LAB_14006c1e1;
    iVar15 = param_1[3];
    if (iVar15 < 0x5a) {
LAB_14006b173:
      iVar21 = 0;
      if (iVar15 < 0x8c) {
        iVar21 = iVar13;
      }
      dVar25 = dVar11;
      if (iVar15 < 0) goto LAB_14006b1d2;
      if (0x59 < iVar15) goto LAB_14006b031;
      dVar25 = (double)FUN_140332d90(((double)iVar15 - DAT_14053b188) * DAT_14053a558 * dVar10 *
                                     dVar26);
      dVar25 = dVar25 * DAT_140539f10 + DAT_140539ef8;
LAB_14006b04c:
      dVar26 = (double)FUN_140332d90(((double)iVar15 - dVar28) * dVar27 * dVar10 * dVar26);
      sVar22 = 0x115c - (short)(int)(dVar26 * _DAT_14053aaf0);
      puVar16 = DAT_140e45d28;
      if ((iVar15 == 1) && (uVar29 = param_1[0xb], DAT_140e45d1c < 0x1000)) {
        puVar16 = (undefined8 *)_malloc_base(0x60);
        if (puVar16 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar24 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar16 + 0x14) = (undefined4)uStack_100;
        *(undefined4 *)(puVar16 + 3) = uVar29;
        *(undefined4 *)((longlong)puVar16 + 0x1c) = (undefined4)uStack_100;
        *(undefined4 *)(puVar16 + 4) = uVar29;
        *puVar16 = 1;
        puVar16[1] = 0x36;
        *(undefined4 *)(puVar16 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar16 + 0x24) = 0;
        puVar16[5] = 0;
        puVar16[6] = 0x3ff0000000000000;
        puVar16[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar16 + 8) = 0;
        *(undefined4 *)((longlong)puVar16 + 0x44) = 0xff;
        *(undefined4 *)(puVar16 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar16 + 0x4c) = 0xff;
        puVar16[10] = 0xff;
        puVar16[0xb] = 0;
        if (bVar24) {
          DAT_140e45d78 = puVar16;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar16;
        }
      }
    }
    else {
      iVar13 = 0xff;
      if (iVar15 < 100) {
        dVar25 = ((double)iVar15 - DAT_14053a430) * DAT_14053a9d8;
      }
      else {
        if (0x8b < iVar15) goto LAB_14006b173;
        dVar25 = ((double)iVar15 - DAT_14053a3a0) * DAT_14053a6d8;
      }
      dVar25 = (double)FUN_140332d90(dVar25 * dVar10 * dVar26);
      if (iVar15 < 0x8c) {
        iVar21 = (int)(dVar25 * DAT_14053a5f8);
      }
LAB_14006b031:
      dVar25 = DAT_140539ef8;
      if (iVar15 < 0) {
LAB_14006b1d2:
        sVar22 = 0;
        puVar16 = DAT_140e45d28;
      }
      else {
        if (iVar15 < 0x5a) goto LAB_14006b04c;
        sVar22 = 0x115c;
        puVar16 = DAT_140e45d28;
      }
    }
    DAT_140e45d28 = puVar16;
    iVar13 = param_1[3];
    if (iVar13 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar13 = param_1[3];
    }
    puVar16 = DAT_140e45d28;
    if (iVar13 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar29 = param_1[0xb];
      uVar30 = param_1[10];
      puVar16 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar16 = (undefined8 *)_malloc_base(0x60);
        if (puVar16 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar24 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar16 + 0x14) = uVar30;
        *(undefined4 *)(puVar16 + 3) = uVar29;
        *(undefined4 *)((longlong)puVar16 + 0x1c) = uVar30;
        *(undefined4 *)(puVar16 + 4) = uVar29;
        *puVar16 = 1;
        puVar16[1] = 0x11;
        *(undefined4 *)(puVar16 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar16 + 0x24) = 0;
        puVar16[5] = 0;
        puVar16[6] = 0x3ff0000000000000;
        puVar16[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar16 + 8) = 0;
        *(undefined4 *)((longlong)puVar16 + 0x44) = 0xff;
        *(undefined4 *)(puVar16 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar16 + 0x4c) = 0xff;
        puVar16[10] = 0xff;
        puVar16[0xb] = 0;
        if (bVar24) {
          DAT_140e45d78 = puVar16;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar16;
        }
      }
    }
    DAT_140e45d28 = puVar16;
    uVar29 = DAT_140e41ab8;
    puVar17 = (undefined4 *)_malloc_base(0x48);
    if (puVar17 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar24 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar17 = uVar29;
    puVar17[1] = 0x4e;
    *(undefined8 *)(puVar17 + 2) = 5;
    puVar17[4] = 0;
    *(undefined2 *)(puVar17 + 5) = 0;
    *(undefined8 *)(puVar17 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar17 + 8) = 0x3ff0000000000000;
    puVar17[10] = 0xff;
    puVar17[0xb] = 0xff;
    puVar17[0xc] = 0xff;
    puVar17[0xd] = iVar21;
    *(undefined8 *)(puVar17 + 0xe) = 1;
    *(undefined8 *)(puVar17 + 0x10) = 0;
    if (bVar24) {
      DAT_140e46bf0 = puVar17;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar17;
    }
    DAT_140e46c88 = puVar17;
    if ((int)param_1[3] < 100) {
      uVar29 = CONCAT22((short)(in_stack_fffffffffffffe80 >> 0x10),sVar22);
      FUN_1400c8410(DAT_140e44ab8,0x1e,0xb,param_1[10],(float)param_1[0xb] + DAT_14053ae14,uVar29,
                    dVar11,dVar25,0xff,0xff,0xff,0xff,1,0);
      in_stack_fffffffffffffe88._8_8_ = dVar25;
      in_stack_fffffffffffffe88._0_8_ = dVar11;
      in_stack_fffffffffffffe80 = CONCAT22((short)((uint)uVar29 >> 0x10),sVar22);
      FUN_1400c8410(DAT_140e44ab4,0x1e,0xb,param_1[10],(float)param_1[0xb] + DAT_14053ae14,
                    in_stack_fffffffffffffe80,dVar11,dVar25,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[3] == 0x8c) {
      *param_1 = 0;
    }
    goto LAB_14006c1e1;
  }
  uVar19 = param_1[3];
  if ((9 < (int)uVar19) && (uVar19 - 10 == ((int)(uVar19 - 10) / 0x168) * 0x168)) {
    if (iVar15 == 1) {
      uVar19 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      auVar34._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar34._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar34._8_4_ = 0x28;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = auVar34._8_8_;
      in_stack_fffffffffffffe88 = auVar2 << 0x40;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x12e,10,0,0,DAT_14053b394,uVar30,0,auVar34._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
      uVar19 = param_1[3];
    }
    if (param_1[5] == 2) {
      uVar19 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      auVar35._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar35._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar35._8_4_ = 0x28;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = auVar35._8_8_;
      in_stack_fffffffffffffe88 = auVar3 << 0x40;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x130,10,0,0,uVar29,uVar30,0,auVar35._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
      uVar19 = param_1[3];
    }
    if (param_1[5] == 3) {
      uVar19 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ DAT_140e9fd18 ^ uVar19;
      auVar36._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar36._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar36._8_4_ = 0x28;
      auVar4._8_8_ = 0;
      auVar4._0_8_ = auVar36._8_8_;
      in_stack_fffffffffffffe88 = auVar4 << 0x40;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x132,10,0,0,uVar29,uVar30,0,auVar36._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
    }
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
    FUN_14018a340(DAT_140e472bc,1,1);
  }
  uVar19 = param_1[3];
  if ((0xbd < (int)uVar19) && (uVar19 - 0xbe == ((int)(uVar19 - 0xbe) / 0x168) * 0x168)) {
    if (param_1[5] == 1) {
      uVar19 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      auVar37._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar37._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar37._8_4_ = 0x28;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = auVar37._8_8_;
      in_stack_fffffffffffffe88 = auVar5 << 0x40;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x12f,10,0,0,uVar29,uVar30,0,auVar37._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
    }
    if (param_1[5] == 2) {
      uVar19 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar19 = uVar19 * 0x800 ^ uVar19;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      auVar38._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar38._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar38._8_4_ = 0x28;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = auVar38._8_8_;
      in_stack_fffffffffffffe88 = auVar6 << 0x40;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x131,10,0,0,uVar29,uVar30,0,auVar38._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
    }
    if (param_1[5] == 3) {
      uVar20 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
      uVar19 = uVar20 * 0x800 ^ uVar20;
      DAT_140e9fd10 = (uVar20 >> 0x1e ^ uVar20) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar19) >> 8 ^ uVar19 ^ DAT_140e9fd18;
      auVar39._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar39._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar39._8_4_ = 0x28;
      uVar30 = CONCAT22(uVar31,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001));
      stage_entity_spawn_candidate(0x133,10,0,0,uVar29,uVar30,0,auVar39._8_8_,1,param_1[1]);
      uVar31 = (undefined2)((uint)uVar30 >> 0x10);
    }
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
    FUN_14018a340(DAT_140e472bc,1,1);
  }
  iVar21 = DAT_140e44308;
  iVar13 = param_1[7];
  if ((iVar13 < iStack_10c) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == iVar21) {
        *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - (iStack_10c - iVar13);
      }
    }
  }
  iVar13 = param_1[7];
  if (iStack_10c < iVar13) {
    param_1[7] = iStack_10c;
    iVar13 = iStack_10c;
  }
  iVar21 = DAT_140e44308;
  if ((iVar13 < 1) && (lVar9 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x60)) {
      if (*(int *)(lVar9 + 4) == iVar21) {
        *(int *)(lVar9 + 0x1c) = *(int *)(lVar9 + 0x1c) - iStack_10c;
      }
    }
  }
  dVar27 = dVar11;
  if (param_1[5] == 1) {
    iVar13 = param_1[3];
    if (iVar13 < 0) {
      dVar27 = 0.0;
    }
    else if (iVar13 < 0x28) {
      dVar27 = (double)FUN_140332d90(((double)iVar13 - 0.0) * DAT_14053a6d8 * dVar10 * dVar26);
      dVar27 = dVar27 + 0.0;
    }
  }
  auVar1._8_4_ = SUB84(dVar27,0);
  auVar1._0_8_ = dVar27;
  auVar1._12_4_ = (int)((ulonglong)dVar27 >> 0x20);
  in_stack_fffffffffffffe80 = CONCAT22(uVar31,(short)(int)dVar25);
  FUN_1400c8410(DAT_140e44ab8,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe80,auVar1,0xff,
                0xff,0xff,0xff,1,0);
  uVar19 = param_1[0xb];
  in_stack_fffffffffffffe88._8_8_ = uVar12;
  in_stack_fffffffffffffe88._0_8_ = dVar11;
  in_stack_fffffffffffffe80 = in_stack_fffffffffffffe80 & 0xffff0000;
  FUN_1400c8410(DAT_140e44ab4,0x1e,7,param_1[10],uVar19,in_stack_fffffffffffffe80,dVar11,uVar12,0xff
                ,0xff,0xff,0xff,1,0);
  iVar13 = param_1[5];
  if (iVar13 == 1) {
    if ((int)param_1[7] < ((int)(DAT_140e41b0c + (DAT_140e41b0c >> 0x1f & 3U)) >> 2) * 3) {
      FUN_140079e20(param_1,2);
      auVar7._12_4_ = 0;
      auVar7._0_12_ = in_stack_fffffffffffffe88._4_12_;
      in_stack_fffffffffffffe88 = auVar7 << 0x20;
      in_stack_fffffffffffffe80 = 0;
      uVar19 = uVar19 & 0xffff0000;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar19,0,in_stack_fffffffffffffe88);
      iVar13 = param_1[5] + 1;
      param_1[3] = 0;
      param_1[5] = iVar13;
      goto LAB_14006bbcd;
    }
  }
  else {
LAB_14006bbcd:
    if ((iVar13 == 2) &&
       ((int)param_1[7] < ((int)(DAT_140e41b0c + (DAT_140e41b0c >> 0x1f & 3U)) >> 2) * 2)) {
      FUN_140079e20(param_1,2);
      auVar8._12_4_ = 0;
      auVar8._0_12_ = in_stack_fffffffffffffe88._4_12_;
      in_stack_fffffffffffffe88 = auVar8 << 0x20;
      in_stack_fffffffffffffe80 = 0;
      FUN_140109660(0x19,param_1[10],param_1[0xb],0,uVar19 & 0xffff0000,0,in_stack_fffffffffffffe88)
      ;
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  param_1[0x15] = 0;
LAB_14006c1e1:
  if (param_1[0x15] == 0) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      auVar40._12_4_ = in_stack_fffffffffffffe88._12_4_;
      auVar40._0_8_ = in_stack_fffffffffffffe88._0_8_;
      auVar40._8_4_ = 0x14;
      stage_entity_spawn_candidate
                (0x136,99999999,1,0,0,in_stack_fffffffffffffe80 & 0xffff0000,dVar11,auVar40._8_8_,0,
                 param_1[1]);
      param_1[0x17] = 1;
    }
    else if (param_1[0x17] != 1) {
      return;
    }
    param_1[0x15] = 1;
    if (DAT_140e44654 < 0x3d) {
      param_1[0x17] = 0;
      param_1[0x15] = 0;
    }
  }
  return;
}


