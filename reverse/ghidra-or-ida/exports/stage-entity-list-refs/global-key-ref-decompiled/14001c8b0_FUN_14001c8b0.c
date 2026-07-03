// Function: FUN_14001c8b0 @ 14001c8b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14001c8b0(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  longlong lVar3;
  short sVar4;
  int iVar5;
  float *pfVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  ulonglong uVar17;
  short sVar18;
  ushort uVar19;
  uint uVar20;
  ulonglong uVar21;
  undefined4 *puVar22;
  undefined2 uVar23;
  int iVar24;
  uint uVar25;
  int *piVar26;
  ulonglong uVar27;
  bool bVar28;
  float fVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  undefined8 uVar35;
  double dVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  double dVar40;
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  float fVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  longlong local_res18;
  int local_res20;
  float in_stack_fffffffffffffe88;
  undefined2 uVar50;
  ulonglong in_stack_fffffffffffffe90;
  undefined4 uVar51;
  undefined4 uVar52;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar93 [16];
  undefined1 auVar94 [16];
  undefined1 auVar95 [16];
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined1 auVar99 [16];
  float local_120 [5];
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  
  dVar30 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  dVar36 = DAT_14053aba0;
  uVar25 = 0;
  iVar5 = 0x28;
  uVar20 = (uint)(dVar30 * DAT_14053aba0);
  if ((DAT_140e419bc != 1) || ((0 < (int)param_1[7] && (0 < DAT_140e4430c)))) goto LAB_14001ca84;
  if ((DAT_140e41af8 == 1) &&
     ((((DAT_140e4192c == 0 && (DAT_140e41b00 == 0)) && (DAT_140e467e8 == 0)) &&
      (DAT_140e44044 == 0)))) {
    DAT_140e44044 = 1;
    FUN_1400b4350(1,0x18);
    save_init_or_reset_candidate();
    DAT_140e45f68 = 0x3c;
  }
  FUN_1400031d0(param_1);
  auVar53._12_4_ = in_stack_fffffffffffffe98._12_4_;
  auVar53._0_8_ = in_stack_fffffffffffffe98._0_8_;
  auVar53._8_4_ = param_1[0x14];
  in_stack_fffffffffffffe98._8_8_ = auVar53._8_8_;
  in_stack_fffffffffffffe98._0_8_ = (double)DAT_14053a4f0;
  in_stack_fffffffffffffe88 = (float)param_1[0xb];
  in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffffffff0000;
  stage_entity_spawn_candidate
            (0x137,99999999,0,param_1[10],in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,
             DAT_14053a4f0,in_stack_fffffffffffffe98._8_8_,1,0);
  DAT_140e41af8 = DAT_140e41af8 + -1;
  switch(DAT_140e41af8) {
  case 0:
    param_1[5] = 0xe;
    DAT_140e419bc = -1;
    goto switchD_14001ca1f_default;
  case 1:
    param_1[5] = 10;
    DAT_140e419bc = 2;
    goto switchD_14001ca1f_default;
  case 2:
    param_1[5] = 8;
    break;
  case 3:
    param_1[5] = 6;
    break;
  case 4:
    param_1[5] = 4;
    break;
  case 5:
    param_1[5] = 2;
    break;
  default:
    goto switchD_14001ca1f_default;
  }
  DAT_140e419bc = 2;
  param_1[0x14] = 200;
switchD_14001ca1f_default:
  param_1[0x17] = 0;
LAB_14001ca84:
  fVar29 = DAT_14053ae60;
  fVar38 = DAT_14053ad2c;
  dVar31 = DAT_14053a020;
  dVar30 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar16 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
    uVar16 = uVar16 * 0x800 ^ uVar16;
    uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
    uVar11 = DAT_1407c7798 * 0x6f + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar10 >> 0xb ^ uVar16) >> 8 ^ uVar16 ^ uVar10) % 0x12d + 0xd2);
    uVar16 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar16 >> 0x1e ^ uVar16) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar16 = uVar16 * 0x800 ^ uVar16;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar16) >> 8 ^ DAT_140e9fd18 ^ uVar16;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x96);
  }
  iVar14 = param_1[5];
  uVar46 = SUB84(DAT_14053a020,0);
  uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar48 = SUB84(DAT_140539d28,0);
  uVar49 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  iVar24 = 0;
  uVar19 = (ushort)uVar20;
  uVar44 = (undefined4)DAT_140539f40;
  uVar45 = DAT_140539f40._4_4_;
  switch(iVar14) {
  case 0:
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472dc);
      FUN_14018a340(DAT_140e472dc,1,1);
      iVar14 = param_1[5];
    }
    uVar45 = DAT_140539f40._4_4_;
    uVar44 = (undefined4)DAT_140539f40;
    iVar5 = param_1[3];
    if (iVar5 < 0xc9) {
      iVar14 = (int)(float)param_1[0xd];
      if (iVar5 < 0) {
        iVar14 = 0xaf0;
      }
      else if (iVar5 < 200) {
        dVar36 = (double)FUN_140332d90(((double)iVar5 - 0.0) * _DAT_14053a400 * dVar31 * dVar30);
        iVar14 = (int)(dVar36 * (double)(iVar14 + -0xaf0)) + 0xaf0;
      }
      param_1[0xb] = (float)iVar14;
      uVar44 = (undefined4)DAT_140539f40;
      uVar45 = DAT_140539f40._4_4_;
    }
    else {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
      if (iVar5 == 0xf0) {
        param_1[0x15] = 0;
        param_1[5] = iVar14 + 1;
        param_1[3] = 0;
        DAT_140e41b0c = 60000;
        DAT_140e4430c = 0x5dc;
        DAT_140e4192c = 0;
        param_1[7] = 60000;
        DAT_140e419bc = 1;
      }
    }
    break;
  case 1:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90();
    uVar44 = DAT_14053ac2c;
    dVar34 = DAT_14053a1e8;
    dVar31 = DAT_14053a190;
    dVar30 = DAT_14053a148;
    dVar36 = DAT_14053a0f8;
    pfVar6 = local_120;
    param_1[0xb] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    do {
      uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
      fVar38 = (float)param_1[10];
      fVar29 = (float)param_1[0xb];
      local_120[0] = fVar38 - DAT_14053ad14;
      local_120[1] = fVar29 + DAT_14053acfc;
      local_120[2] = fVar38 + DAT_14053ad10;
      local_120[4] = fVar38 - DAT_140539fc0;
      local_120[3] = fVar29 + DAT_14053ac9c;
      local_10c = fVar29 - DAT_14053ad2c;
      in_stack_fffffffffffffe88 = pfVar6[1];
      fVar38 = *pfVar6;
      dVar33 = (double)FUN_1403300b4((double)(DAT_140e445dc - in_stack_fffffffffffffe88),
                                     (double)(DAT_140e445d8 - fVar38));
      iVar5 = param_1[3];
      dVar33 = dVar33 * DAT_14053aba0;
      iVar14 = (iVar5 + -0x1e) % 0x2b2;
      dVar32 = DAT_140539e60;
      auVar55 = in_stack_fffffffffffffe98;
      if ((-1 < iVar5) && (dVar32 = DAT_140539f18, iVar5 < 0x1e)) {
        dVar32 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                       DAT_140539d28);
        dVar32 = dVar32 * DAT_140539f10 + DAT_140539e60;
        auVar55 = in_stack_fffffffffffffe98;
      }
      dVar40 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053ab68 * DAT_14053a020 *
                                     DAT_140539d28);
      iVar5 = DAT_140e419b8;
      iVar12 = uVar25 * 0x28;
      iVar24 = 1;
      in_stack_fffffffffffffe98._0_8_ = dVar40 * DAT_140539ec8 + _DAT_140539cc0 + dVar32;
      in_stack_fffffffffffffe98._8_8_ = in_stack_fffffffffffffe98._0_8_;
      if (DAT_140e419b8 == 0) {
        iVar24 = 7;
      }
      else if (DAT_140e419b8 == 1) {
        iVar24 = 0xb;
      }
      else if (DAT_140e419b8 == 2) {
LAB_14001d008:
        iVar24 = 0x11;
      }
      else if (DAT_140e419b8 == 3) {
        iVar24 = 0xf;
      }
      else if (DAT_140e419b8 == 4) goto LAB_14001d008;
      sVar18 = 1;
      if (DAT_140e419b8 == 0) {
        sVar18 = 0x14a;
      }
      else if (DAT_140e419b8 == 1) {
        sVar18 = 0x172;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        sVar18 = 400;
      }
      else if (DAT_140e419b8 == 4) {
        sVar18 = 0x230;
      }
      dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
      sVar18 = (short)uVar25 * 0x1e + sVar18;
      dVar40 = DAT_14053a0e0;
      if ((((DAT_140e419b8 != 0) && (dVar40 = DAT_14053a138, DAT_140e419b8 != 1)) &&
          (dVar40 = DAT_14053a158, DAT_140e419b8 != 2)) &&
         ((dVar40 = DAT_14053a178, DAT_140e419b8 != 3 && (dVar40 = dVar32, DAT_140e419b8 == 4)))) {
        dVar40 = DAT_14053a1c8;
      }
      dVar40 = ((double)iVar14 - (double)iVar12) * _DAT_140539e08 + dVar40 +
               (double)(int)uVar25 * DAT_140539f28;
      uVar23 = (undefined2)(int)dVar33;
      if (uVar25 == 1) {
        sVar18 = -sVar18;
      }
      else if ((uVar25 == 0) && (iVar14 == 0)) {
        *(undefined2 *)((longlong)param_1 + 0x42) = uVar23;
      }
      if ((iVar12 <= iVar14) && (iVar14 < iVar12 + 0x24)) {
        uVar20 = iVar14 + uVar25 * -0x28 & 0x80000003;
        if ((int)uVar20 < 0) {
          uVar20 = (uVar20 - 1 | 0xfffffffc) + 1;
        }
        if (uVar20 == 0) {
          auVar54._12_4_ = auVar55._12_4_;
          auVar54._0_8_ = auVar55._0_8_;
          auVar54._8_4_ = 1;
          auVar55._8_8_ = auVar54._8_8_;
          auVar55._0_8_ = dVar40;
          in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),uVar44);
          uVar45 = CONCAT22(uVar50,*(undefined2 *)((longlong)param_1 + 0x42));
          FUN_1400709b0(3,0,fVar38,in_stack_fffffffffffffe88,uVar45,in_stack_fffffffffffffe90,dVar40
                        ,auVar55._8_8_,iVar24,0x10000,0);
          uVar50 = (undefined2)((uint)uVar45 >> 0x10);
          if (2 < DAT_140e419b8) {
            auVar56._12_4_ = auVar55._12_4_;
            auVar56._0_8_ = auVar55._0_8_;
            auVar56._8_4_ = 1;
            auVar55._8_8_ = auVar56._8_8_;
            auVar55._0_8_ = dVar40 - DAT_140539f90;
            in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),uVar44);
            uVar45 = CONCAT22(uVar50,((short)(0x10000 / (ulonglong)(uint)(iVar24 * 2)) - sVar18) +
                                     *(short *)((longlong)param_1 + 0x42));
            FUN_1400709b0(5,0,fVar38,in_stack_fffffffffffffe88,uVar45,in_stack_fffffffffffffe90,
                          dVar40 - DAT_140539f90,auVar55._8_8_,iVar24,0x10000,0);
            uVar50 = (undefined2)((uint)uVar45 >> 0x10);
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar18;
          dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
          iVar5 = DAT_140e419b8;
        }
      }
      iVar12 = 1;
      iVar24 = (uVar25 + 1) * 0xa0;
      if (iVar5 == 0) {
        iVar12 = 0x15;
      }
      else if (iVar5 == 1) {
        iVar12 = 0xe;
      }
      else if (iVar5 == 2) {
        iVar12 = 0xc;
      }
      else if (iVar5 == 3) {
        iVar12 = 0xb;
      }
      else if (iVar5 == 4) {
        iVar12 = 10;
      }
      uVar45 = 1;
      if (iVar5 == 0) {
        uVar45 = 3;
      }
      else if (iVar5 == 1) {
LAB_14001d2dc:
        uVar45 = 5;
      }
      else {
        if (iVar5 != 2) {
          if (iVar5 == 3) goto LAB_14001d2dc;
          if (iVar5 != 4) goto LAB_14001d2e8;
        }
        uVar45 = 7;
      }
LAB_14001d2e8:
      iVar13 = (iVar24 - iVar14) * 0x91;
      dVar33 = dVar36;
      if ((((iVar5 != 0) && (dVar33 = dVar30, iVar5 != 1)) && (dVar33 = dVar31, iVar5 != 2)) &&
         ((iVar5 != 3 && (dVar33 = dVar32, iVar5 == 4)))) {
        dVar33 = dVar34;
      }
      dVar33 = (double)(int)uVar25 + dVar33;
      if (iVar14 == iVar24) {
        if ((uVar25 & 1) == 0) {
          *(undefined2 *)((longlong)param_1 + 0x42) = uVar23;
        }
        else {
          *(undefined2 *)(param_1 + 0x11) = uVar23;
        }
LAB_14001d35d:
        if ((iVar14 < iVar24 + 0xb4) && ((int)(iVar14 + (uVar25 + 1) * -0xa0) % iVar12 == 0)) {
          uVar23 = *(undefined2 *)((longlong)param_1 + 0x42);
          if ((uVar25 & 1) != 0) {
            uVar23 = *(undefined2 *)(param_1 + 0x11);
          }
          auVar57._12_4_ = auVar55._12_4_;
          auVar57._0_8_ = auVar55._0_8_;
          auVar57._8_4_ = 1;
          auVar58._8_8_ = auVar57._8_8_;
          auVar58._0_8_ = dVar33;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
          FUN_1400709b0(0xd,0,fVar38,in_stack_fffffffffffffe88,CONCAT22(uVar50,uVar23),
                        in_stack_fffffffffffffe90,dVar33,auVar58._8_8_,uVar45,iVar13 + 27000,0);
          if (2 < DAT_140e419b8) {
            auVar59._12_4_ = auVar58._12_4_;
            auVar59._0_8_ = auVar58._0_8_;
            auVar59._8_4_ = 1;
            in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
            FUN_1400709b0(0xd,0,fVar38,in_stack_fffffffffffffe88,uVar23,in_stack_fffffffffffffe90,
                          dVar33 - DAT_140539fc8,auVar59._8_8_,uVar45,iVar13 + 29000,0);
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
      else if (iVar24 <= iVar14) goto LAB_14001d35d;
      in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffffffff0000;
      FUN_1400c8410(DAT_140e44740,0x19,8,fVar38,in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,
                    in_stack_fffffffffffffe98,0xff,0xff,0xff,0xc0,1,0);
      uVar25 = uVar25 + 1;
      pfVar6 = pfVar6 + 2;
    } while ((int)uVar25 < 3);
    uVar46 = SUB84(DAT_14053a020,0);
    uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar48 = SUB84(DAT_140539d28,0);
    uVar49 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    uVar44 = (undefined4)DAT_140539f40;
    uVar45 = DAT_140539f40._4_4_;
    fVar38 = DAT_14053ad2c;
    fVar29 = DAT_14053ae60;
    break;
  case 2:
  case 4:
  case 6:
    iVar5 = param_1[3];
    iVar14 = 0;
    if (iVar5 < 0x5a) {
LAB_14001eea0:
      if (iVar5 < 0xb4) {
        iVar14 = iVar24;
      }
      puVar7 = DAT_140e45d28;
      if (iVar5 == 1) {
        uVar44 = param_1[0xb];
        uVar45 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar7 + 0x14) = uVar45;
          *(undefined4 *)(puVar7 + 3) = uVar44;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar45;
          *(undefined4 *)(puVar7 + 4) = uVar44;
          *puVar7 = 1;
          puVar7[1] = 0x36;
          *(undefined4 *)(puVar7 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
          puVar7[5] = 0;
          puVar7[6] = 0x3ff0000000000000;
          puVar7[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar7 + 8) = 0;
          *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
          *(undefined4 *)(puVar7 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
          puVar7[10] = 0xff;
          puVar7[0xb] = 0;
          if (bVar28) {
            DAT_140e45d78 = puVar7;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar7;
          }
        }
      }
    }
    else {
      iVar24 = 0xff;
      if (iVar5 < 100) {
        dVar36 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar14 = (int)(dVar36 * DAT_14053a5f8);
        puVar7 = DAT_140e45d28;
      }
      else {
        if (0xb3 < iVar5) goto LAB_14001eea0;
        dVar36 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a278) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar7 = DAT_140e45d28;
        if (iVar5 < 0xb4) {
          iVar14 = (int)(dVar36 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar7;
    iVar5 = param_1[3];
    if (iVar5 < 0x5a) {
      param_1[0xb] = (float)iVar5 * _DAT_140539ce0 + (float)param_1[0xb];
      FUN_14007ac00(param_1);
    }
    else {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar24 = (uVar20 & 0xffff) - (uint)uVar2;
      iVar5 = iVar24 + 0x10000;
      if (-0x8001 < iVar24) {
        iVar5 = iVar24;
      }
      iVar24 = iVar5 + -0x10000;
      if (iVar5 < 0x8001) {
        iVar24 = iVar5;
      }
      if (iVar24 < 1) {
        uVar15 = uVar2;
        if ((iVar24 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar24)) {
          uVar15 = uVar19;
        }
      }
      else {
        uVar15 = uVar19;
        if (0x1ff < iVar24) {
          uVar15 = uVar2 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar15;
      dVar36 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar36 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    }
    puVar7 = DAT_140e45d28;
    if (param_1[3] == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar44 = param_1[0xb];
      uVar45 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar45;
        *(undefined4 *)(puVar7 + 3) = uVar44;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar45;
        *(undefined4 *)(puVar7 + 4) = uVar44;
        *puVar7 = 1;
        puVar7[1] = 0x11;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
    }
    DAT_140e45d28 = puVar7;
    iVar5 = param_1[3];
    if (99 < iVar5) {
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar12 = (uVar20 & 0xffff) - (uint)uVar2;
      iVar24 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar24 = iVar12;
      }
      iVar12 = iVar24 + -0x10000;
      if (iVar24 < 0x8001) {
        iVar12 = iVar24;
      }
      if (iVar12 < 1) {
        uVar15 = uVar2;
        if ((iVar12 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar12)) {
          uVar15 = uVar19;
        }
      }
      else {
        uVar15 = uVar19;
        if (0x1ff < iVar12) {
          uVar15 = uVar2 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar15;
      dVar36 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar34 = (double)FUN_140332d90();
      dVar36 = *(double *)(param_1 + 0x12);
      dVar32 = 0.0;
      fVar39 = (float)param_1[0xb];
      if (iVar5 < 0xf0) {
        dVar30 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a460) * _DAT_14053a490 * dVar31 *
                                       dVar30);
        dVar32 = dVar30 * DAT_14053b0a0 +
                 (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
      }
      fVar39 = ((float)(dVar34 * dVar36) + fVar39) - (float)dVar32;
      param_1[0xb] = fVar39;
      if (iVar5 == 100) {
        param_1[0xb] = fVar39 - fVar29;
      }
    }
    uVar44 = DAT_140e41ab8;
    puVar22 = (undefined4 *)_malloc_base(0x48);
    if (puVar22 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar22 = uVar44;
    puVar22[1] = 0x4e;
    *(undefined8 *)(puVar22 + 2) = 5;
    puVar22[4] = 0;
    *(undefined2 *)(puVar22 + 5) = 0;
    *(undefined8 *)(puVar22 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar22 + 8) = 0x3ff0000000000000;
    puVar22[10] = 0xff;
    puVar22[0xb] = 0xff;
    puVar22[0xc] = 0xff;
    puVar22[0xd] = iVar14;
    *(undefined8 *)(puVar22 + 0xe) = 1;
    *(undefined8 *)(puVar22 + 0x10) = 0;
    if (bVar28) {
      DAT_140e46bf0 = puVar22;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar22;
    }
    uVar44 = (undefined4)DAT_140539f40;
    uVar45 = DAT_140539f40._4_4_;
    DAT_140e46c88 = puVar22;
    if (param_1[3] == 0xb4) {
      iVar5 = param_1[5];
      *(undefined8 *)(param_1 + 0x14) = 0xaf;
      param_1[3] = 0;
      if ((iVar5 - 2U & 0xfffffffd) == 0) {
        DAT_140e41b0c = 55000;
        DAT_140e4430c = 0x5dc;
LAB_14001f384:
        DAT_140e4192c = 0;
      }
      else if (iVar5 == 6) {
        DAT_140e41b0c = 70000;
        DAT_140e4430c = 0x708;
        goto LAB_14001f384;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar5 + 1;
      DAT_140e419bc = 1;
      uVar44 = (undefined4)DAT_140539f40;
      uVar45 = DAT_140539f40._4_4_;
    }
    break;
  case 3:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar31 = (double)FUN_140332d90();
    fVar29 = DAT_14053ad74;
    fVar38 = DAT_14053accc;
    dVar30 = DAT_14053a1b8;
    dVar36 = DAT_14053a138;
    pfVar6 = local_120;
    iVar5 = 0;
    local_res20 = -0x3c;
    param_1[0xb] = (float)(dVar31 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    do {
      fVar39 = (float)param_1[10];
      fVar37 = (float)param_1[0xb];
      local_104 = fVar37;
      local_120[0] = fVar39 + fVar38;
      local_120[2] = fVar39 - DAT_14053ace0;
      local_120[1] = fVar37 + DAT_14053ad10;
      local_120[4] = fVar39 + fVar29;
      local_120[3] = fVar37 - fVar38;
      local_108 = fVar39 - fVar29;
      local_10c = fVar37 + DAT_14053aa20;
      fVar43 = pfVar6[1];
      fVar38 = *pfVar6;
      dVar34 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar43),
                                     (double)(DAT_140e445d8 - fVar38));
      dVar34 = dVar34 * DAT_14053aba0;
      iVar14 = param_1[3];
      dVar31 = DAT_140539e60;
      if ((-1 < iVar14) && (dVar31 = DAT_140539f18, iVar14 < 0x1e)) {
        dVar31 = (double)FUN_140332d90(((double)iVar14 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                       (double)CONCAT44(uVar49,uVar48));
        dVar31 = dVar31 * DAT_140539f10 + DAT_140539e60;
      }
      dVar32 = (double)FUN_140332d90(((double)iVar14 - 0.0) * DAT_14053ab68 * DAT_14053a020 *
                                     (double)CONCAT44(uVar49,uVar48));
      uVar44 = DAT_140e41a50;
      uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
      dVar31 = dVar32 * DAT_140539ec8 + _DAT_140539cc0 + dVar31;
      if ((9 < iVar14) && (1 < (int)uVar25)) {
        iVar14 = (iVar14 + -10) % 0xf0;
        dVar32 = DAT_14053a0b0;
        if ((DAT_140e419b8 != 0) &&
           ((((dVar32 = DAT_14053a0f8, DAT_140e419b8 != 1 && (dVar32 = dVar36, DAT_140e419b8 != 2))
             && (dVar32 = DAT_14053a178, DAT_140e419b8 != 3)) &&
            (dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),
            DAT_140e419b8 == 4)))) {
          dVar32 = dVar30;
        }
        sVar18 = -0x8000;
        if (uVar25 != 3) {
          sVar18 = 0;
        }
        if (iVar14 == local_res20 + -0x3c) {
          uVar45 = param_1[1];
          puVar7 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar7 = (undefined8 *)_malloc_base();
            if (puVar7 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
            puVar7[6] = 0x4014000000000000;
            puVar7[7] = 0x4014000000000000;
            *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
            *(undefined4 *)(puVar7 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
            *(float *)((longlong)puVar7 + 0x14) = fVar38 - fVar39;
            *(float *)(puVar7 + 3) = fVar43 - fVar37;
            *(float *)((longlong)puVar7 + 0x1c) = fVar38 - fVar39;
            *(float *)(puVar7 + 4) = fVar43 - fVar37;
            *puVar7 = 1;
            *(undefined4 *)(puVar7 + 1) = 0x31;
            *(undefined4 *)((longlong)puVar7 + 0xc) = uVar44;
            *(undefined4 *)(puVar7 + 2) = 0x23;
            *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
            puVar7[5] = 0;
            *(undefined4 *)(puVar7 + 8) = 0x28;
            *(undefined4 *)(puVar7 + 10) = 0x80;
            *(undefined4 *)((longlong)puVar7 + 0x54) = uVar45;
            puVar7[0xb] = 0;
            if (bVar28) {
              DAT_140e45d78 = puVar7;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar7;
            }
          }
          DAT_140e45d28 = puVar7;
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
          FUN_14018a340(DAT_140e472c0,1,1);
        }
        if (iVar14 == local_res20 + -0x14) {
          auVar60._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar60._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar60._8_4_ = 1;
          in_stack_fffffffffffffe98._8_8_ = auVar60._8_8_;
          in_stack_fffffffffffffe98._0_8_ = dVar32;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
          in_stack_fffffffffffffe88 =
               (float)CONCAT22((short)((uint)in_stack_fffffffffffffe88 >> 0x10),sVar18);
          FUN_14006c2f0(0x11,0xc,fVar38,fVar43,in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,
                        dVar32,in_stack_fffffffffffffe98._8_8_,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
        uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
        if ((2 < DAT_140e419b8) && (iVar14 == local_res20)) {
          iVar14 = 0;
          do {
            auVar61._12_4_ = in_stack_fffffffffffffe98._12_4_;
            auVar61._0_8_ = in_stack_fffffffffffffe98._0_8_;
            auVar61._8_4_ = 1;
            in_stack_fffffffffffffe98._8_8_ = auVar61._8_8_;
            in_stack_fffffffffffffe98._0_8_ = dVar32;
            in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
            in_stack_fffffffffffffe88 =
                 (float)CONCAT22((short)((uint)in_stack_fffffffffffffe88 >> 0x10),
                                 (short)iVar14 * 0x1a0a + sVar18 + -0xd05);
            FUN_14006c2f0(0x11,0xc,fVar38,fVar43,in_stack_fffffffffffffe88,in_stack_fffffffffffffe90
                          ,dVar32,in_stack_fffffffffffffe98._8_8_,0);
            uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
            iVar14 = iVar14 + 1;
          } while (iVar14 < 2);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      if ((0xef < (int)param_1[3]) && ((int)uVar25 < 2)) {
        iVar14 = 1;
        iVar24 = (param_1[3] + -0xf0) % 0x1fe;
        if (DAT_140e419b8 == 0) {
          iVar14 = 0x29;
        }
        else if (DAT_140e419b8 == 1) {
          iVar14 = 0x1b;
        }
        else if (DAT_140e419b8 == 2) {
          iVar14 = 0x13;
        }
        else if (DAT_140e419b8 == 3) {
          iVar14 = 0xf;
        }
        else if (DAT_140e419b8 == 4) {
          iVar14 = 0xc;
        }
        iVar12 = 1;
        if (DAT_140e419b8 == 0) {
          iVar12 = 6000;
        }
        else if (DAT_140e419b8 == 1) {
          iVar12 = 4000;
        }
        else if (DAT_140e419b8 == 2) {
          iVar12 = 0xce4;
        }
        else if (DAT_140e419b8 == 3) {
          iVar12 = 3000;
        }
        else if (DAT_140e419b8 == 4) {
          iVar12 = 0xa8c;
        }
        dVar32 = DAT_14053a080;
        if ((((DAT_140e419b8 != 0) && (dVar32 = DAT_14053a0e0, DAT_140e419b8 != 1)) &&
            (dVar32 = DAT_14053a100, DAT_140e419b8 != 2)) &&
           ((dVar32 = dVar36, DAT_140e419b8 != 3 &&
            (dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),
            DAT_140e419b8 == 4)))) {
          dVar32 = dVar30;
        }
        uVar19 = (ushort)(int)dVar34;
        if (iVar24 == iVar5) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar19;
        }
        else if (iVar24 < iVar5) goto LAB_14001dc66;
        if (((iVar24 < iVar5 + 0xd2) || (iVar5 == -0xd2)) && ((iVar24 - iVar5) % iVar14 == 0)) {
          iVar14 = (iVar24 - iVar5) / iVar14;
          auVar62._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar62._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar62._8_4_ = 1;
          in_stack_fffffffffffffe90 =
               CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),DAT_14053ac2c);
          FUN_1400709b0(3,0,fVar38,fVar43,CONCAT22(uVar50,*(undefined2 *)((longlong)param_1 + 0x42))
                        ,in_stack_fffffffffffffe90,dVar32,auVar62._8_8_,iVar14 + 1,iVar14 * iVar12,0
                       );
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          uVar2 = *(ushort *)((longlong)param_1 + 0x42);
          iVar24 = ((int)dVar34 & 0xffffU) - (uint)uVar2;
          iVar14 = iVar24 + 0x10000;
          if (-0x8001 < iVar24) {
            iVar14 = iVar24;
          }
          iVar24 = iVar14 + -0x10000;
          if (iVar14 < 0x8001) {
            iVar24 = iVar14;
          }
          if (iVar24 < 1) {
            uVar15 = uVar2;
            if ((iVar24 < 0) && (uVar15 = uVar2 - 0x1bc, -0x1bc < iVar24)) {
              uVar15 = uVar19;
            }
          }
          else {
            uVar15 = uVar19;
            if (0x1bb < iVar24) {
              uVar15 = uVar2 + 0x1bc;
            }
          }
          *(ushort *)((longlong)param_1 + 0x42) = uVar15;
        }
      }
LAB_14001dc66:
      in_stack_fffffffffffffe98._8_4_ = SUB84(dVar31,0);
      in_stack_fffffffffffffe98._0_8_ = dVar31;
      in_stack_fffffffffffffe98._12_4_ = (int)((ulonglong)dVar31 >> 0x20);
      in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffffffff0000;
      FUN_1400c8410(DAT_140e44740,0x1c,8,fVar38,fVar43,in_stack_fffffffffffffe90,
                    in_stack_fffffffffffffe98,0xff,0xff,0xff,0xc0,1,0);
      uVar25 = uVar25 + 1;
      local_res20 = local_res20 + 0x3c;
      uVar48 = SUB84(DAT_140539d28,0);
      uVar49 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      pfVar6 = pfVar6 + 2;
      iVar5 = iVar5 + 0xd2;
      fVar29 = DAT_14053ad74;
      fVar38 = DAT_14053accc;
      in_stack_fffffffffffffe88 = fVar43;
    } while (local_res20 < 0xb4);
    goto LAB_14001dd04;
  case 5:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar32 = (double)FUN_140332d90();
    uVar44 = DAT_14053ac2c;
    dVar34 = DAT_14053a158;
    dVar31 = DAT_14053a0f8;
    dVar30 = DAT_14053a0c0;
    dVar36 = DAT_14053a070;
    pfVar6 = local_120;
    param_1[0xb] = (float)(dVar32 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    do {
      uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
      fVar38 = (float)param_1[10];
      fVar29 = (float)param_1[0xb];
      local_120[0] = fVar38 + DAT_14053ad10;
      local_120[1] = fVar29 + DAT_14053ac80;
      local_120[3] = fVar29 + DAT_14053ac80;
      local_120[2] = fVar38 - DAT_14053ad14;
      local_120[4] = fVar38 - DAT_140539fc0;
      local_108 = fVar38 - DAT_140539fc0;
      local_10c = fVar29 + DAT_14053ad1c;
      local_104 = fVar29 - DAT_14053acc8;
      in_stack_fffffffffffffe88 = pfVar6[1];
      fVar38 = *pfVar6;
      dVar33 = (double)FUN_1403300b4((double)(DAT_140e445dc - in_stack_fffffffffffffe88),
                                     (double)(DAT_140e445d8 - fVar38));
      dVar33 = dVar33 * DAT_14053aba0;
      iVar5 = param_1[3];
      dVar32 = DAT_140539e60;
      auVar64 = in_stack_fffffffffffffe98;
      if ((-1 < iVar5) && (dVar32 = DAT_140539f18, iVar5 < 0x1e)) {
        dVar32 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a798 * DAT_14053a020 *
                                       DAT_140539d28);
        dVar32 = dVar32 * DAT_140539f10 + DAT_140539e60;
        auVar64 = in_stack_fffffffffffffe98;
      }
      dVar40 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053ab68 * DAT_14053a020 *
                                     DAT_140539d28);
      in_stack_fffffffffffffe98._0_8_ = dVar40 * DAT_140539ec8 + _DAT_140539cc0 + dVar32;
      in_stack_fffffffffffffe98._8_8_ = in_stack_fffffffffffffe98._0_8_;
      if ((iVar5 < 0x1e) || (1 < uVar25)) {
LAB_14001e181:
        dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
      }
      else {
        iVar5 = 1;
        if (DAT_140e419b8 == 0) {
          iVar5 = 0x16;
        }
        else if (DAT_140e419b8 == 1) {
          iVar5 = 0x10;
        }
        else if (DAT_140e419b8 == 2) {
          iVar5 = 0xc;
        }
        else if (DAT_140e419b8 == 3) {
          iVar5 = 0xd;
        }
        else if (DAT_140e419b8 == 4) {
          iVar5 = 0xb;
        }
        uVar45 = 1;
        if (DAT_140e419b8 == 0) {
          uVar45 = 5;
        }
        else if (DAT_140e419b8 == 1) {
          uVar45 = 7;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar45 = 8;
        }
        else if (DAT_140e419b8 == 4) {
          uVar45 = 9;
        }
        sVar18 = 1;
        if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
          sVar18 = -0x28;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          sVar18 = -0x32;
        }
        dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        dVar40 = DAT_14053a0b8;
        if (((DAT_140e419b8 != 0) && (dVar40 = DAT_14053a118, DAT_140e419b8 != 1)) &&
           ((dVar40 = DAT_14053a160, DAT_140e419b8 != 2 &&
            ((dVar40 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar40 = dVar32, DAT_140e419b8 == 4))))
           )) {
          dVar40 = DAT_14053a190;
        }
        if (uVar25 == 1) {
          uVar20 = param_1[3];
          sVar18 = -sVar18;
          uVar16 = uVar20;
        }
        else {
          uVar20 = param_1[3];
          uVar16 = uVar20 & 0xffff;
        }
        uVar17 = (longlong)(int)(uVar20 - 0x1e) % (longlong)iVar5;
        if ((int)uVar17 == 0) {
          auVar63._12_4_ = auVar64._12_4_;
          auVar63._0_8_ = auVar64._0_8_;
          auVar63._8_4_ = 1;
          auVar64._8_8_ = auVar63._8_8_;
          auVar64._0_8_ = dVar40;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
          uVar46 = CONCAT22(uVar50,sVar18 * (short)uVar16 + 0x4000);
          FUN_1400709b0(0xd,uVar17 & 0xffffffff,fVar38,in_stack_fffffffffffffe88,uVar46,
                        in_stack_fffffffffffffe90,dVar40,auVar64._8_8_,uVar45,0x10000,0);
          uVar50 = (undefined2)((uint)uVar46 >> 0x10);
          if (2 < DAT_140e419b8) {
            auVar65._12_4_ = auVar64._12_4_;
            auVar65._0_8_ = auVar64._0_8_;
            auVar65._8_4_ = 1;
            auVar64._8_8_ = auVar65._8_8_;
            auVar64._0_8_ = dVar40 + DAT_140539fc8;
            in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
            uVar46 = CONCAT22(uVar50,sVar18 * *(short *)(param_1 + 3) + 0x4000);
            FUN_1400709b0(0xd,0,fVar38,in_stack_fffffffffffffe88,uVar46,in_stack_fffffffffffffe90,
                          dVar40 + DAT_140539fc8,auVar64._8_8_,uVar45,0x10000,0);
            uVar50 = (undefined2)((uint)uVar46 >> 0x10);
          }
          FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          goto LAB_14001e181;
        }
      }
      if ((0x77 < (int)param_1[3]) && (1 < uVar25)) {
        iVar5 = 1;
        if (DAT_140e419b8 == 0) {
          iVar5 = 0x46;
        }
        else if (DAT_140e419b8 == 1) {
          iVar5 = 0x2d;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar5 = 0x24;
        }
        iVar14 = 1;
        if (DAT_140e419b8 == 0) {
          iVar14 = 3;
        }
        else if (DAT_140e419b8 == 1) {
          iVar14 = 5;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar14 = 7;
        }
        else if (DAT_140e419b8 == 4) {
          iVar14 = 9;
        }
        uVar45 = 1;
        if (DAT_140e419b8 == 0) {
          uVar45 = 8;
        }
        else if (DAT_140e419b8 == 1) {
          uVar45 = 0xc;
        }
        else if (DAT_140e419b8 == 2) {
          uVar45 = 0x10;
        }
        else if (DAT_140e419b8 == 3) {
          uVar45 = 0x12;
        }
        else if (DAT_140e419b8 == 4) {
          uVar45 = 0x14;
        }
        dVar40 = dVar36;
        if (((DAT_140e419b8 != 0) && (dVar40 = dVar30, DAT_140e419b8 != 1)) &&
           ((dVar40 = dVar31, DAT_140e419b8 != 2 &&
            ((DAT_140e419b8 != 3 && (dVar40 = dVar32, DAT_140e419b8 == 4)))))) {
          dVar40 = dVar34;
        }
        uVar23 = (undefined2)(int)dVar33;
        if (((param_1[3] + -0x78) % (iVar5 * 3) == 0) && (uVar25 == 2)) {
          auVar66._12_4_ = auVar64._12_4_;
          auVar66._0_8_ = auVar64._0_8_;
          auVar66._8_4_ = 1;
          auVar64._8_8_ = auVar66._8_8_;
          auVar64._0_8_ = dVar40;
          in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),uVar44);
          uVar46 = CONCAT22(uVar50,uVar23);
          FUN_1400709b0(2,0,fVar38,in_stack_fffffffffffffe88,uVar46,in_stack_fffffffffffffe90,dVar40
                        ,auVar64._8_8_,iVar14,iVar14 * 700 + -700,0);
          uVar50 = (undefined2)((uint)uVar46 >> 0x10);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        }
        if (((iVar5 + 0x78 <= (int)param_1[3]) &&
            (uVar17 = (longlong)(param_1[3] - (iVar5 + 0x78)) % (longlong)(iVar5 * 3),
            (int)uVar17 == 0)) && (uVar25 == 3)) {
          auVar67._12_4_ = auVar64._12_4_;
          auVar67._0_8_ = auVar64._0_8_;
          auVar67._8_4_ = 1;
          in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),uVar44);
          FUN_1400709b0(2,uVar17 & 0xffffffff,fVar38,in_stack_fffffffffffffe88,
                        CONCAT22(uVar50,uVar23),in_stack_fffffffffffffe90,dVar40 + dVar32,
                        auVar67._8_8_,uVar45,0x8000,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
        }
      }
      in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffffffff0000;
      FUN_1400c8410(DAT_140e44740,0x1f,8,fVar38,in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,
                    in_stack_fffffffffffffe98,0xff,0xff,0xff,0xc0,1,0);
      uVar25 = uVar25 + 1;
      pfVar6 = pfVar6 + 2;
    } while ((int)uVar25 < 4);
    goto LAB_14001dd04;
  case 7:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar30 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar34 = (double)FUN_140332d90();
    fVar38 = DAT_14053ad7c;
    uVar44 = DAT_14053ac2c;
    dVar31 = DAT_14053a140;
    dVar30 = DAT_14053a0f8;
    auVar41._8_8_ = 0;
    auVar41._0_8_ = DAT_140539f18;
    local_res18 = 0;
    param_1[0xb] = (float)(dVar34 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    do {
      uVar50 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
      iVar14 = 0;
      fVar29 = (float)param_1[10];
      fVar39 = (float)param_1[0xb];
      local_120[0] = fVar29 + DAT_14053ad10;
      local_120[1] = fVar39 - DAT_14053ac58;
      local_120[3] = fVar39 - DAT_14053ac58;
      local_120[4] = fVar29 + fVar38;
      local_120[2] = fVar29 - DAT_14053ad14;
      local_108 = fVar29 - fVar38;
      local_100 = fVar29 + fVar38;
      local_f8 = fVar29 - fVar38;
      local_10c = fVar39 + DAT_14053acbc;
      local_104 = fVar39 + DAT_14053acbc;
      local_fc = fVar39 - DAT_14053ad1c;
      local_f4 = fVar39 - DAT_14053ad1c;
      in_stack_fffffffffffffe88 = local_120[local_res18 * 2 + 1];
      fVar38 = local_120[local_res18 * 2];
      dVar32 = (double)FUN_1403300b4((double)(DAT_140e445dc - in_stack_fffffffffffffe88),
                                     (double)(DAT_140e445d8 - fVar38));
      iVar5 = param_1[3];
      iVar24 = (iVar5 + -0x1e) % 0x370;
      dVar34 = DAT_140539e60;
      if ((-1 < iVar5) && (dVar34 = auVar41._0_8_, iVar5 < 0x1e)) {
        dVar34 = (double)FUN_140332d90(((double)iVar5 - _DAT_140539cc0) * DAT_14053a798 *
                                       (double)CONCAT44(uVar47,uVar46) * DAT_140539d28);
        dVar34 = dVar34 * DAT_140539f10 + DAT_140539e60;
      }
      dVar33 = (double)FUN_140332d90(((double)iVar5 - _DAT_140539cc0) * DAT_14053ab68 *
                                     (double)CONCAT44(uVar47,uVar46) * DAT_140539d28);
      iVar12 = DAT_140e419b8;
      dVar34 = dVar33 * DAT_140539ec8 + _DAT_140539cc0 + dVar34;
      if ((iVar5 < 0x1e) || (1 < uVar25)) {
LAB_14001e896:
        dVar33 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        iVar12 = DAT_140e419b8;
      }
      else {
        auVar68._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar68._0_8_ = in_stack_fffffffffffffe98._0_8_;
        uVar20 = (uint)(in_stack_fffffffffffffe90 >> 0x20);
        if (iVar24 < 0x1a5) {
          iVar5 = 1;
          if (DAT_140e419b8 == 0) {
            iVar5 = 0x13;
          }
          else if (DAT_140e419b8 == 1) {
            iVar5 = 0xf;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            iVar5 = 0x10;
          }
          iVar14 = 1;
          if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
            iVar14 = 8;
          }
          else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
            iVar14 = 10;
          }
          uVar45 = 1;
          if (DAT_140e419b8 == 0) {
            uVar45 = 2;
          }
          else if (DAT_140e419b8 == 1) {
            uVar45 = 3;
          }
          else if (DAT_140e419b8 == 2) {
            uVar45 = 4;
          }
          else if (DAT_140e419b8 == 3) {
            uVar45 = 6;
          }
          else if (DAT_140e419b8 == 4) {
            uVar45 = 8;
          }
          dVar32 = DAT_14053a088;
          if ((((DAT_140e419b8 != 0) && (dVar32 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
              (dVar32 = dVar30, DAT_140e419b8 != 2)) &&
             ((dVar32 = dVar31, DAT_140e419b8 != 3 &&
              (dVar32 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40),
              DAT_140e419b8 == 4)))) {
            dVar32 = DAT_14053a198;
          }
          if (((-1 < iVar24) && ((int)((longlong)iVar24 % (longlong)iVar5) < iVar14)) &&
             (((longlong)iVar24 % (longlong)iVar5 & 1U) == 0)) {
            iVar5 = (iVar24 + 0x32) % 0x1e0;
            sVar4 = (short)iVar5 * -0xf8;
            sVar9 = (short)iVar5 * 0xf8;
            sVar18 = sVar9;
            if (0xef < iVar5) {
              sVar18 = sVar4 + -0x2f00;
            }
            if (uVar25 == 1) {
              sVar18 = sVar4 + -0x8000;
              if (0xef < iVar5) {
                sVar18 = sVar9 + -0x5100;
              }
            }
            auVar68._8_4_ = 1;
            in_stack_fffffffffffffe98._8_8_ = auVar68._8_8_;
            in_stack_fffffffffffffe98._0_8_ = dVar32;
            in_stack_fffffffffffffe90 = (ulonglong)uVar20 << 0x20;
            uVar46 = CONCAT22(uVar50,sVar18);
            FUN_1400709b0(3,0,fVar38,in_stack_fffffffffffffe88,uVar46,in_stack_fffffffffffffe90,
                          dVar32,in_stack_fffffffffffffe98._8_8_,uVar45,0x10000,0);
            uVar50 = (undefined2)((uint)uVar46 >> 0x10);
            iVar5 = DAT_140e44190 << 4;
LAB_14001e871:
            FUN_140184700(iVar5,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
          goto LAB_14001e896;
        }
        if (iVar24 < 0x244) goto LAB_14001e896;
        iVar5 = 1;
        if (DAT_140e419b8 == 0) {
          iVar5 = 0x44;
        }
        else if (DAT_140e419b8 == 1) {
          iVar5 = 0x33;
        }
        else if (DAT_140e419b8 == 2) {
          iVar5 = 0x2c;
        }
        else if (DAT_140e419b8 == 3) {
          iVar5 = 0x27;
        }
        else if (DAT_140e419b8 == 4) {
          iVar5 = 0x21;
        }
        iVar13 = 1;
        if (DAT_140e419b8 == 0) {
          iVar13 = 0xe;
        }
        else if (DAT_140e419b8 == 1) {
          iVar13 = 0x14;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar13 = 0x18;
        }
        dVar33 = (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
        dVar40 = dVar31;
        if (((DAT_140e419b8 != 0) && (dVar40 = DAT_14053a190, DAT_140e419b8 != 1)) &&
           ((dVar40 = DAT_14053a1c8, DAT_140e419b8 != 2 &&
            ((dVar40 = DAT_14053a1e8, DAT_140e419b8 != 3 && (dVar40 = dVar33, DAT_140e419b8 == 4))))
           )) {
          dVar40 = DAT_14053a208;
        }
        if (iVar24 < 0x32a) {
          if ((iVar24 + -0x244) % iVar5 == 0) {
            uVar23 = (undefined2)(int)(dVar32 * dVar36);
            if (uVar25 == 0) {
              *(undefined2 *)((longlong)param_1 + 0x42) = uVar23;
            }
            else if (uVar25 == 1) {
              *(undefined2 *)(param_1 + 0x11) = uVar23;
            }
          }
          iVar5 = (iVar24 + -0x244) % iVar5;
          if ((iVar5 < iVar13) &&
             (iVar5 == (iVar5 / 3 + (iVar5 >> 0x1f) +
                       (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >> 0x1f
                            )) * 3)) {
            sVar18 = *(short *)((longlong)param_1 + 0x42);
            if (uVar25 == 1) {
              sVar18 = *(short *)(param_1 + 0x11);
            }
            auVar69._8_4_ = 1;
            auVar69._0_8_ = auVar68._0_8_;
            auVar69._12_4_ = auVar68._12_4_;
            in_stack_fffffffffffffe98._8_8_ = auVar69._8_8_;
            in_stack_fffffffffffffe98._0_8_ = dVar40;
            in_stack_fffffffffffffe90 = CONCAT44(uVar20,uVar44);
            uVar45 = CONCAT22(uVar50,sVar18);
            FUN_14006c2f0(7,0,fVar38,in_stack_fffffffffffffe88,uVar45,in_stack_fffffffffffffe90,
                          dVar40,in_stack_fffffffffffffe98._8_8_,0);
            uVar50 = (undefined2)((uint)uVar45 >> 0x10);
            if (2 < DAT_140e419b8) {
              dVar40 = dVar40 - auVar41._0_8_;
              do {
                auVar70._12_4_ = in_stack_fffffffffffffe98._12_4_;
                auVar70._0_8_ = in_stack_fffffffffffffe98._0_8_;
                auVar70._8_4_ = 1;
                in_stack_fffffffffffffe98._8_8_ = auVar70._8_8_;
                in_stack_fffffffffffffe98._0_8_ = dVar40;
                in_stack_fffffffffffffe90 =
                     CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),uVar44);
                uVar45 = CONCAT22((short)((uint)uVar45 >> 0x10),
                                  (short)iVar14 * 0x546 + sVar18 + -0x2a3);
                FUN_14006c2f0(7,0,fVar38,in_stack_fffffffffffffe88,uVar45,in_stack_fffffffffffffe90,
                              dVar40,in_stack_fffffffffffffe98._8_8_,0);
                uVar50 = (undefined2)((uint)uVar45 >> 0x10);
                iVar14 = iVar14 + 1;
              } while (iVar14 < 2);
            }
            iVar5 = DAT_140e44190 * 0x13;
            goto LAB_14001e871;
          }
        }
      }
      uVar45 = DAT_140e41a50;
      if ((0x1d5 < (int)param_1[3]) && (1 < uVar25)) {
        iVar5 = 1;
        if (iVar12 == 0) {
          iVar5 = 0x47;
        }
        else if (iVar12 == 1) {
          iVar5 = 0x2b;
        }
        else if (iVar12 == 2) {
          iVar5 = 0x1f;
        }
        else if (iVar12 == 3) {
          iVar5 = 0x1b;
        }
        else if (iVar12 == 4) {
          iVar5 = 0x18;
        }
        iVar14 = (uVar25 - 2) * iVar5;
        iVar13 = iVar14 + 0x1b8;
        dVar32 = DAT_14053a0b0;
        if ((((iVar12 != 0) && (dVar32 = dVar30, iVar12 != 1)) &&
            (dVar32 = DAT_14053a138, iVar12 != 2)) &&
           ((dVar32 = DAT_14053a178, iVar12 != 3 && (dVar32 = dVar33, iVar12 == 4)))) {
          dVar32 = DAT_14053a1b8;
        }
        if (((iVar13 <= iVar24) && (iVar24 < 800)) && ((iVar24 - iVar13) % (iVar5 * 4) == 0)) {
          fVar29 = (float)param_1[0xb];
          uVar46 = param_1[1];
          fVar39 = (float)param_1[10];
          puVar7 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar7 = (undefined8 *)_malloc_base();
            if (puVar7 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
            puVar7[6] = 0x4014000000000000;
            puVar7[7] = 0x4014000000000000;
            *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
            *(undefined4 *)(puVar7 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
            *(float *)((longlong)puVar7 + 0x14) = fVar38 - fVar39;
            *(float *)(puVar7 + 3) = in_stack_fffffffffffffe88 - fVar29;
            *(float *)((longlong)puVar7 + 0x1c) = fVar38 - fVar39;
            *(float *)(puVar7 + 4) = in_stack_fffffffffffffe88 - fVar29;
            *puVar7 = 1;
            *(undefined4 *)(puVar7 + 1) = 0x31;
            *(undefined4 *)((longlong)puVar7 + 0xc) = uVar45;
            *(undefined4 *)(puVar7 + 2) = 0x23;
            *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
            puVar7[5] = 0;
            *(undefined4 *)(puVar7 + 8) = 0x28;
            *(undefined4 *)(puVar7 + 10) = 0x80;
            *(undefined4 *)((longlong)puVar7 + 0x54) = uVar46;
            puVar7[0xb] = 0;
            if (bVar28) {
              DAT_140e45d78 = puVar7;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar7;
            }
          }
          DAT_140e45d28 = puVar7;
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
          FUN_14018a340(DAT_140e472c0,1,1);
          auVar41._8_8_ = 0;
          auVar41._0_8_ = DAT_140539f18;
        }
        iVar14 = iVar14 + 0x1e0;
        dVar36 = DAT_14053aba0;
        if (((iVar14 <= iVar24) && (iVar24 < 0x348)) && ((iVar24 - iVar14) % (iVar5 * 4) == 0)) {
          auVar71._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar71._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar71._8_4_ = 1;
          in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffff00000000;
          FUN_14006c2f0(0x11,0xc,fVar38,in_stack_fffffffffffffe88,
                        CONCAT22(uVar50,(short)uVar25 << 0xf),in_stack_fffffffffffffe90,dVar32,
                        auVar71._8_8_,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          dVar36 = DAT_14053aba0;
        }
      }
      in_stack_fffffffffffffe98._8_4_ = SUB84(dVar34,0);
      in_stack_fffffffffffffe98._0_8_ = dVar34;
      in_stack_fffffffffffffe98._12_4_ = (int)((ulonglong)dVar34 >> 0x20);
      in_stack_fffffffffffffe90 = in_stack_fffffffffffffe90 & 0xffffffffffff0000;
      FUN_1400c8410(DAT_140e44740,0x22,8,fVar38,in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,
                    in_stack_fffffffffffffe98,0xff,0xff,0xff,0xc0,1,0);
      uVar25 = uVar25 + 1;
      local_res18 = local_res18 + 1;
      uVar46 = SUB84(DAT_14053a020,0);
      uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
      fVar38 = DAT_14053ad7c;
    } while ((int)uVar25 < 6);
LAB_14001dd04:
    uVar46 = SUB84(DAT_14053a020,0);
    uVar47 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar48 = SUB84(DAT_140539d28,0);
    uVar49 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    uVar44 = (undefined4)DAT_140539f40;
    uVar45 = DAT_140539f40._4_4_;
    fVar38 = DAT_14053ad2c;
    fVar29 = DAT_14053ae60;
    break;
  case 8:
    iVar14 = param_1[3];
    iVar12 = iVar24;
    if (iVar14 < 0x78) {
LAB_14001f45b:
      iVar24 = 0;
      if (iVar14 < 0xdc) {
        iVar24 = iVar12;
      }
      puVar7 = DAT_140e45d28;
      if (iVar14 == 1) {
        uVar44 = param_1[0xb];
        uVar45 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base(0x60);
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar7 + 0x14) = uVar45;
          *(undefined4 *)(puVar7 + 3) = uVar44;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar45;
          *(undefined4 *)(puVar7 + 4) = uVar44;
          *puVar7 = 1;
          puVar7[1] = 0x36;
          *(undefined4 *)(puVar7 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
          puVar7[5] = 0;
          puVar7[6] = 0x3ff0000000000000;
          puVar7[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar7 + 8) = 0;
          *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
          *(undefined4 *)(puVar7 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
          puVar7[10] = 0xff;
          puVar7[0xb] = 0;
          if (bVar28) {
            DAT_140e45d78 = puVar7;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar7;
          }
        }
      }
    }
    else {
      iVar12 = 0xff;
      if (iVar14 < 0x82) {
        dVar36 = (double)FUN_140332d90(((double)iVar14 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar24 = (int)(dVar36 * DAT_14053a5f8);
        puVar7 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar14) goto LAB_14001f45b;
        dVar36 = (double)FUN_140332d90(((double)iVar14 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar7 = DAT_140e45d28;
        if (iVar14 < 0xdc) {
          iVar24 = (int)(dVar36 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar7;
    iVar14 = param_1[3];
    if (iVar14 < 0x78) {
      FUN_14007ac00(param_1);
      iVar14 = param_1[3];
      param_1[0xb] = (float)iVar14 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar7 = DAT_140e45d28;
    if (iVar14 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar44 = param_1[0xb];
      uVar45 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        puVar7[10] = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar45;
        *(undefined4 *)(puVar7 + 3) = uVar44;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar45;
        *(undefined4 *)(puVar7 + 4) = uVar44;
        *puVar7 = 1;
        puVar7[1] = 0x11;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        *(undefined4 *)(puVar7 + 8) = 0;
        puVar7[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
    }
    DAT_140e45d28 = puVar7;
    iVar14 = param_1[3];
    if (0xdb < iVar14) {
      FUN_140001900(iVar14,0xdc,4);
    }
    iVar14 = param_1[3];
    if (iVar14 == 0x82) {
      param_1[0xb] = (float)param_1[0xb] - DAT_14053aca8;
LAB_14001f6b3:
      uVar2 = *(ushort *)(param_1 + 0x10);
      iVar13 = (uVar20 & 0xffff) - (uint)uVar2;
      iVar12 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar12 = iVar13;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar15 = uVar2;
        if ((iVar13 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar13)) {
          uVar15 = uVar19;
        }
      }
      else {
        uVar15 = uVar19;
        if (0x1ff < iVar13) {
          uVar15 = uVar2 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar15;
      dVar36 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar36 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      if (iVar14 < 0xd2) {
        auVar72._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar72._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar72._8_4_ = 0x29;
        in_stack_fffffffffffffe98._4_12_ = auVar72._4_12_;
        in_stack_fffffffffffffe98._0_4_ = 0x2a;
        in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),0x29);
        iVar5 = FUN_1400c9580(iVar14,0,7,4,0x28,in_stack_fffffffffffffe90,in_stack_fffffffffffffe98)
        ;
      }
      if (param_1[3] - 0xd2 < 10) {
        in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),0x2c);
        iVar5 = FUN_1400c9580(param_1[3],0xd2,5,2,0x2b,in_stack_fffffffffffffe90);
      }
      if (0xdb < (int)param_1[3]) {
        auVar73._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar73._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar73._8_4_ = 0x2e;
        auVar74._4_12_ = auVar73._4_12_;
        auVar74._0_4_ = 0x2f;
        in_stack_fffffffffffffe90 = CONCAT44((int)(in_stack_fffffffffffffe90 >> 0x20),0x2e);
        iVar5 = FUN_1400c9580(param_1[3],0xdc,5,4,0x2d,in_stack_fffffffffffffe90,auVar74);
      }
      uVar35 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
      in_stack_fffffffffffffe98._8_8_ = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
      in_stack_fffffffffffffe98._0_8_ = (double)uVar35;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                    param_1[0xb],in_stack_fffffffffffffe90 & 0xffffffffffff0000,uVar35,
                    CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),0xff,0xff,0xff,0xff,1,0);
    }
    else {
      if (0x81 < iVar14) goto LAB_14001f6b3;
      uVar35 = CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
    }
    uVar44 = DAT_140e41ab8;
    puVar22 = (undefined4 *)_malloc_base(0x48);
    if (puVar22 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar22 = uVar44;
    puVar22[1] = 0x4e;
    *(undefined8 *)(puVar22 + 2) = 5;
    puVar22[4] = 0;
    *(undefined2 *)(puVar22 + 5) = 0;
    *(undefined8 *)(puVar22 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar22 + 8) = 0x3ff0000000000000;
    puVar22[10] = 0xff;
    puVar22[0xb] = 0xff;
    puVar22[0xc] = 0xff;
    puVar22[0xd] = iVar24;
    *(undefined8 *)(puVar22 + 0xe) = 1;
    *(undefined8 *)(puVar22 + 0x10) = 0;
    if (bVar28) {
      DAT_140e46bf0 = puVar22;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar22;
    }
    DAT_140e46c88 = puVar22;
    if (param_1[3] == 0xd2) {
      auVar75._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar75._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar75._8_4_ = 0x28;
      in_stack_fffffffffffffe98._8_8_ = auVar75._8_8_;
      in_stack_fffffffffffffe98._0_8_ = (double)uVar35;
      stage_entity_spawn_candidate
                (0x54,99999999,0,0,0,0x4000,uVar35,in_stack_fffffffffffffe98._8_8_,1,param_1[1]);
    }
    uVar44 = (undefined4)DAT_140539f40;
    uVar45 = DAT_140539f40._4_4_;
    if (param_1[3] == 0x17c) {
      *(undefined8 *)(param_1 + 0x14) = 0x50;
      param_1[3] = 0;
      if (param_1[5] == 8) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 45000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
      uVar44 = (undefined4)DAT_140539f40;
      uVar45 = DAT_140539f40._4_4_;
    }
    break;
  case 9:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    fVar43 = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar43;
    dVar36 = (double)FUN_140332d90();
    uVar44 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    fVar37 = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar37;
    fVar39 = DAT_14053ac58;
    dVar36 = DAT_14053a0f8;
    if (9 < (int)param_1[3]) {
      iVar5 = 1;
      uVar20 = (param_1[3] + -10) % 700;
      if (DAT_140e419b8 == 0) {
        iVar5 = 0x3c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar5 = 0x28;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar5 = 0x24;
      }
      else if (DAT_140e419b8 == 4) {
        iVar5 = 0x1e;
      }
      if ((uVar20 < 0x168) && ((int)uVar20 % iVar5 == 0)) {
        auVar76._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar76._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar76._8_4_ = 0x19;
        auVar77._8_8_ = auVar76._8_8_;
        auVar77._0_8_ = DAT_14053a0f8;
        uVar35 = CONCAT62((int6)(in_stack_fffffffffffffe90 >> 0x10),0xc4b0);
        stage_entity_spawn_candidate
                  (0x55,10,2,fVar43,fVar37 - DAT_14053ac58,uVar35,DAT_14053a0f8,auVar77._8_8_,1,
                   param_1[1]);
        auVar78._12_4_ = auVar77._12_4_;
        auVar78._0_8_ = auVar77._0_8_;
        auVar78._8_4_ = 0x19;
        auVar79._8_8_ = auVar78._8_8_;
        auVar79._0_8_ = dVar36;
        uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0xc960);
        stage_entity_spawn_candidate
                  (0x55,10,2,param_1[10],(float)param_1[0xb] - fVar39,uVar35,dVar36,auVar79._8_8_,1,
                   param_1[1]);
        auVar80._12_4_ = auVar79._12_4_;
        auVar80._0_8_ = auVar79._0_8_;
        auVar80._8_4_ = 0x19;
        auVar81._8_8_ = auVar80._8_8_;
        auVar81._0_8_ = dVar36;
        uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0xce10);
        stage_entity_spawn_candidate
                  (0x55,10,2,param_1[10],(float)param_1[0xb] - fVar39,uVar35,dVar36,auVar81._8_8_,1,
                   param_1[1]);
        auVar82._12_4_ = auVar81._12_4_;
        auVar82._0_8_ = auVar81._0_8_;
        auVar82._8_4_ = 0x19;
        auVar83._8_8_ = auVar82._8_8_;
        auVar83._0_8_ = dVar36;
        uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0xbb50);
        stage_entity_spawn_candidate
                  (0x55,10,2,param_1[10],(float)param_1[0xb] - fVar39,uVar35,dVar36,auVar83._8_8_,1,
                   param_1[1]);
        auVar84._12_4_ = auVar83._12_4_;
        auVar84._0_8_ = auVar83._0_8_;
        auVar84._8_4_ = 0x19;
        auVar85._8_8_ = auVar84._8_8_;
        auVar85._0_8_ = dVar36;
        uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0xb6a0);
        stage_entity_spawn_candidate
                  (0x55,10,2,param_1[10],(float)param_1[0xb] - fVar39,uVar35,dVar36,auVar85._8_8_,1,
                   param_1[1]);
        auVar86._12_4_ = auVar85._12_4_;
        auVar86._0_8_ = auVar85._0_8_;
        auVar86._8_4_ = 0x19;
        in_stack_fffffffffffffe98._8_8_ = auVar86._8_8_;
        in_stack_fffffffffffffe98._0_8_ = dVar36;
        uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0xb1f0);
        stage_entity_spawn_candidate
                  (0x55,10,2,param_1[10],(float)param_1[0xb] - fVar39,uVar35,dVar36,
                   in_stack_fffffffffffffe98._8_8_,1,param_1[1]);
        uVar44 = (undefined4)((ulonglong)uVar35 >> 0x20);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    auVar87._12_4_ = in_stack_fffffffffffffe98._12_4_;
    auVar87._0_8_ = in_stack_fffffffffffffe98._0_8_;
    auVar87._8_4_ = 0x2e;
    auVar88._4_12_ = auVar87._4_12_;
    auVar88._0_4_ = 0x2f;
    uVar17 = CONCAT44(uVar44,0x2e);
    iVar5 = FUN_1400c9580(param_1[3],0,5,4,0x2d,uVar17,auVar88);
    uVar45 = _UNK_14053bb24;
    uVar44 = _DAT_14053bb20;
    in_stack_fffffffffffffe98._4_4_ = _UNK_14053bb24;
    in_stack_fffffffffffffe98._0_4_ = _DAT_14053bb20;
    in_stack_fffffffffffffe98._8_4_ = _UNK_14053bb28;
    in_stack_fffffffffffffe98._12_4_ = _UNK_14053bb2c;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar17 & 0xffffffffffff0000,in_stack_fffffffffffffe98,0xff,0xff,0xff,
                  0xff,1,0);
    break;
  case 10:
    iVar5 = param_1[3];
    dVar36 = (double)FUN_140332d90(((double)iVar5 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar45 = DAT_140539f40._4_4_;
    uVar44 = (undefined4)DAT_140539f40;
    uVar52 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    dVar36 = dVar36 * _DAT_14053b070 +
             (double)CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
    puVar7 = DAT_140e45d28;
    if (iVar5 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar51 = param_1[0xb];
      uVar1 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar1;
        *(undefined4 *)(puVar7 + 3) = uVar51;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar1;
        *(undefined4 *)(puVar7 + 4) = uVar51;
        *puVar7 = 1;
        puVar7[1] = 0x36;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
    }
    DAT_140e45d28 = puVar7;
    piVar26 = param_1 + 3;
    if (*piVar26 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar17 = CONCAT44(uVar52,0x31);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar5 = FUN_1400c9580(*piVar26,0,5,2,0x30,uVar17);
    in_stack_fffffffffffffe98._8_8_ = dVar36;
    in_stack_fffffffffffffe98._0_8_ = dVar36;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar17 & 0xffffffffffff0000,dVar36,dVar36,0xff,0xff,0xff,0xff,1,0);
    if (*piVar26 == 0xb4) {
      iVar5 = param_1[5];
      param_1[0x15] = 0;
      *piVar26 = 0;
      if (iVar5 == 10) {
        DAT_140e4430c = 0x834;
        DAT_140e41b0c = 80000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar5 + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 0xb:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar36 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    puVar7 = DAT_140e45d28;
    if ((param_1[3] == 1) && (uVar44 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar7 = (undefined8 *)_malloc_base(0x60);
      if (puVar7 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar7 = 1;
      puVar7[1] = 0x2d;
      puVar7[2] = 0x3c;
      puVar7[3] = 0;
      *(undefined4 *)(puVar7 + 4) = 0;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
      puVar7[5] = 0x3ff0000000000000;
      puVar7[6] = 0x3ff0000000000000;
      puVar7[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar7 + 8) = 0x3c;
      *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
      *(undefined4 *)(puVar7 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
      *(undefined4 *)(puVar7 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar7 + 0x54) = uVar44;
      puVar7[0xb] = 0;
      if (bVar28) {
        DAT_140e45d78 = puVar7;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar7;
      }
    }
    DAT_140e45d28 = puVar7;
    uVar52 = DAT_14053b33c;
    uVar45 = DAT_140539f40._4_4_;
    uVar44 = (undefined4)DAT_140539f40;
    uVar51 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    piVar26 = param_1 + 3;
    if (*piVar26 == 0x3c) {
      auVar89._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar89._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar89._8_4_ = 0x28;
      auVar90._8_8_ = auVar89._8_8_;
      auVar90._0_8_ = CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40);
      uVar35 = CONCAT62((int6)(in_stack_fffffffffffffe90 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x56,99999999,1,DAT_14053ad10,DAT_14053b33c,uVar35,auVar90._0_8_,auVar90._8_8_,1,
                 param_1[1]);
      DAT_1407c77a0 = DAT_1407c779c;
      auVar91._12_4_ = auVar90._12_4_;
      auVar91._0_8_ = auVar90._0_8_;
      auVar91._8_4_ = 0x28;
      in_stack_fffffffffffffe98._8_8_ = auVar91._8_8_;
      in_stack_fffffffffffffe98._0_8_ = (double)CONCAT44(uVar45,uVar44);
      uVar35 = CONCAT62((int6)((ulonglong)uVar35 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x56,99999999,1,DAT_14053b378,uVar52,uVar35,in_stack_fffffffffffffe98._0_8_,
                 in_stack_fffffffffffffe98._8_8_,1,param_1[1]);
      uVar51 = (undefined4)((ulonglong)uVar35 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    auVar92._12_4_ = in_stack_fffffffffffffe98._12_4_;
    auVar92._0_8_ = in_stack_fffffffffffffe98._0_8_;
    auVar92._8_4_ = 0x2e;
    auVar93._4_12_ = auVar92._4_12_;
    auVar93._0_4_ = 0x2f;
    uVar17 = CONCAT44(uVar51,0x2e);
    iVar5 = FUN_1400c9580(*piVar26,0,5,4,0x2d,uVar17,auVar93);
    in_stack_fffffffffffffe98._4_4_ = uVar45;
    in_stack_fffffffffffffe98._0_4_ = uVar44;
    in_stack_fffffffffffffe98._8_4_ = uVar44;
    in_stack_fffffffffffffe98._12_4_ = uVar45;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar17 & 0xffffffffffff0000,in_stack_fffffffffffffe98,0xff,0xff,0xff,
                  0xff,1,0);
    if (*piVar26 == 0x1c2) {
      param_1[5] = param_1[5] + 1;
      *piVar26 = 0;
    }
    break;
  case 0xc:
    iVar5 = param_1[3];
    if (iVar5 == 1) {
      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
      fVar39 = DAT_140e445d8;
      fVar43 = DAT_14053ae8c;
      param_1[0xe] = DAT_140e445d8;
      fVar37 = DAT_140e445dc - DAT_14053ae1c;
      param_1[0xf] = fVar37;
      if (fVar43 < fVar39) {
        param_1[0xe] = 0x43ff0000;
        fVar39 = fVar43;
      }
      if (fVar39 < DAT_14053adbc) {
        param_1[0xe] = 0x43520000;
      }
      fVar39 = DAT_14053ae2c;
      if (DAT_14053ae2c < fVar37) {
        param_1[0xf] = 350.0;
        fVar37 = fVar39;
      }
      if (fVar37 < DAT_14053adb4) {
        param_1[0xf] = 0x43480000;
      }
    }
    dVar36 = (double)FUN_140332d90();
    uVar44 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    fVar39 = (float)param_1[0xe];
    fVar37 = (float)param_1[0xc];
    fVar43 = (float)param_1[0xc];
    dVar30 = (double)FUN_140332d90();
    auVar94._12_4_ = in_stack_fffffffffffffe98._12_4_;
    auVar94._0_8_ = in_stack_fffffffffffffe98._0_8_;
    auVar94._8_4_ = 0x2e;
    auVar95._4_12_ = auVar94._4_12_;
    auVar95._0_4_ = 0x2f;
    uVar17 = CONCAT44(uVar44,0x2e);
    param_1[10] = (float)(dVar36 * (double)(fVar39 - fVar37)) + fVar43;
    param_1[0xb] = (float)(dVar30 * (double)((float)param_1[0xf] - (float)param_1[0xd])) +
                   (float)param_1[0xd];
    iVar5 = FUN_1400c9580(iVar5,0,5,4,0x2d,uVar17,auVar95);
    uVar45 = _UNK_14053bb24;
    uVar44 = _DAT_14053bb20;
    in_stack_fffffffffffffe98._4_4_ = _UNK_14053bb24;
    in_stack_fffffffffffffe98._0_4_ = _DAT_14053bb20;
    in_stack_fffffffffffffe98._8_4_ = _UNK_14053bb28;
    in_stack_fffffffffffffe98._12_4_ = _UNK_14053bb2c;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar17 & 0xffffffffffff0000,in_stack_fffffffffffffe98,0xff,0xff,0xff,
                  0xff,1,0);
    if (param_1[3] == 0x3c) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x3fb999999999999a;
      param_1[3] = 0;
    }
    break;
  case 0xd:
    uVar2 = *(ushort *)(param_1 + 0x10);
    iVar14 = (uVar20 & 0xffff) - (uint)uVar2;
    iVar5 = iVar14 + 0x10000;
    if (-0x8001 < iVar14) {
      iVar5 = iVar14;
    }
    iVar14 = iVar5 + -0x10000;
    if (iVar5 < 0x8001) {
      iVar14 = iVar5;
    }
    if (iVar14 < 1) {
      uVar15 = uVar2;
      if ((iVar14 < 0) && (uVar15 = uVar2 - 0x200, -0x200 < iVar14)) {
        uVar15 = uVar19;
      }
    }
    else {
      uVar15 = uVar19;
      if (0x1ff < iVar14) {
        uVar15 = uVar2 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar15;
    dVar36 = (double)FUN_1403307c0();
    uVar44 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    param_1[10] = (float)(dVar36 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar34 = (double)FUN_140332d90();
    dVar36 = *(double *)(param_1 + 0x12);
    iVar5 = param_1[3];
    fVar39 = (float)param_1[0xb];
    if ((iVar5 < 0x28) || ((0x4f < iVar5 && (0x77 < iVar5)))) {
      dVar30 = 0.0;
    }
    else {
      dVar30 = (double)FUN_140332d90(((double)iVar5 - DAT_14053a340) * DAT_14053a6d8 * dVar31 *
                                     dVar30);
      dVar30 = dVar30 * DAT_140539fe8 + _DAT_140539cc0;
    }
    auVar96._12_4_ = in_stack_fffffffffffffe98._12_4_;
    auVar96._0_8_ = in_stack_fffffffffffffe98._0_8_;
    auVar96._8_4_ = 0x2e;
    auVar97._4_12_ = auVar96._4_12_;
    auVar97._0_4_ = 0x2f;
    uVar17 = CONCAT44(uVar44,0x2e);
    param_1[0xb] = ((float)(dVar34 * dVar36) + fVar39) - (float)dVar30;
    iVar5 = FUN_1400c9580(iVar5,0,5,4,0x2d,uVar17,auVar97);
    uVar45 = _UNK_14053bb24;
    uVar44 = _DAT_14053bb20;
    in_stack_fffffffffffffe98._4_4_ = _UNK_14053bb24;
    in_stack_fffffffffffffe98._0_4_ = _DAT_14053bb20;
    in_stack_fffffffffffffe98._8_4_ = _UNK_14053bb28;
    in_stack_fffffffffffffe98._12_4_ = _UNK_14053bb2c;
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar17 & 0xffffffffffff0000,in_stack_fffffffffffffe98,0xff,0xff,0xff,
                  0xff,1,0);
    if (param_1[3] == 0x30c) {
      param_1[3] = 0x5a;
      *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
      param_1[5] = 0xb;
    }
    break;
  case 0xe:
    FUN_140003ad0(param_1);
    uVar45 = DAT_140539f40._4_4_;
    uVar44 = (undefined4)DAT_140539f40;
    uVar52 = (undefined4)(in_stack_fffffffffffffe90 >> 0x20);
    iVar5 = param_1[3];
    if (iVar5 < 0xf0) {
      iVar14 = DAT_1407c7798 + 3;
      iVar24 = DAT_1407c7798 * 10;
      if (iVar5 - 0x3cU < 0xb4) {
        uVar17 = 0;
        uVar35 = FUN_1401349e0(iVar5,0x3c,0x4c,0xe0,0xf0,0,
                               CONCAT44(DAT_140539f40._4_4_,(undefined4)DAT_140539f40));
        fVar39 = DAT_14053accc;
        auVar42._8_8_ = uVar35;
        auVar42._0_8_ = uVar35;
        uVar17 = uVar17 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,DAT_14053accc,uVar17,
                      CONCAT44(uVar45,uVar44),uVar35,0xff,0xff,0xff,0xff,1,0);
        uVar17 = uVar17 & 0xffffffffffff0000;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar14 * 4),0x6e,1,DAT_14053ae44,
                      fVar39,uVar17,auVar42,0xff,0xff,0xff,0xff,1,0);
        uVar52 = (undefined4)(uVar17 >> 0x20);
        if (iVar5 == 0x4c) {
          FUN_14012e070(iVar24 + 99,4);
        }
        else {
          lVar3 = DAT_140e47908;
          if (iVar5 == 0xe0) {
            while (lVar3 != 0) {
              lVar3 = *(longlong *)(lVar3 + 0x238);
              FUN_140323ce8();
              uVar52 = (undefined4)(uVar17 >> 0x20);
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar17 = CONCAT44(uVar52,0x31);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar5 = FUN_1400c9580(param_1[3],0,5,2,0x30,uVar17);
      in_stack_fffffffffffffe98._4_4_ = uVar45;
      in_stack_fffffffffffffe98._0_4_ = uVar44;
      in_stack_fffffffffffffe98._8_4_ = uVar44;
      in_stack_fffffffffffffe98._12_4_ = uVar45;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar17 & 0xffffffffffff0000,in_stack_fffffffffffffe98,0xff,0xff,
                    0xff,0xff,1,0);
    }
    puVar7 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar52 = param_1[0xb];
      uVar51 = param_1[10];
      puVar7 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar7 = (undefined8 *)_malloc_base(0x60);
        if (puVar7 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar28 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar7 + 0x14) = uVar51;
        *(undefined4 *)(puVar7 + 3) = uVar52;
        *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar51;
        *(undefined4 *)(puVar7 + 4) = uVar52;
        *puVar7 = 1;
        puVar7[1] = 0x10;
        *(undefined4 *)(puVar7 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
        puVar7[5] = 0;
        puVar7[6] = 0x3ff0000000000000;
        puVar7[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar7 + 8) = 0;
        *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
        *(undefined4 *)(puVar7 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0;
        if (bVar28) {
          DAT_140e45d78 = puVar7;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar7;
        }
      }
    }
    DAT_140e45d28 = puVar7;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
  }
  uVar21 = 0;
  iVar5 = param_1[5];
  uVar17 = uVar21;
  if (iVar5 < 8) {
    if (iVar5 != 2) goto LAB_14001cd33;
    if (99 < (int)param_1[3]) goto LAB_14001cd48;
LAB_140020ad2:
    if (iVar5 == 6) {
      if ((int)param_1[3] < 100) goto LAB_140020adc;
LAB_140020ae5:
      if ((iVar5 != 6) || ((int)param_1[3] < 100)) goto LAB_140020aef;
    }
    else {
LAB_140020aef:
      if (iVar5 < 7) goto LAB_140020afa;
    }
    uVar17 = 3;
  }
  else {
    if ((iVar5 != 8) || (0x81 < (int)param_1[3])) goto LAB_140020e4a;
LAB_14001cd33:
    if ((iVar5 == 3) || ((iVar5 == 4 && ((int)param_1[3] < 100)))) {
LAB_14001cd48:
      uVar17 = 1;
    }
    if (iVar5 != 4) {
      if (iVar5 != 5) goto LAB_140020ad2;
LAB_140020adc:
      uVar17 = 2;
      goto LAB_140020ae5;
    }
    if (99 < (int)param_1[3]) goto LAB_140020adc;
  }
LAB_140020afa:
  piVar26 = &DAT_140e46cf8;
  puVar22 = &DAT_140e44988;
  uVar27 = uVar21;
  do {
    uVar52 = DAT_140e44984;
    iVar5 = (int)uVar21;
    fVar39 = (((float)(int)uVar17 * fVar29 + (float)param_1[0xb]) - (float)iVar5 * fVar29) - fVar38;
    if (uVar17 <= uVar27) {
      uVar51 = param_1[10];
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      *puVar8 = uVar52;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      puVar8[3] = uVar51;
      puVar8[4] = fVar39;
      puVar8[1] = (iVar5 + 8) * 3;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      piVar26[-2] = piVar26[-2] + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
      uVar51 = *puVar22;
      uVar52 = param_1[10];
      DAT_140e46c88 = puVar8;
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      puVar8[1] = iVar5 * 3 + 0x1a;
      puVar8[3] = uVar52;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      puVar8[4] = fVar39;
      *puVar8 = uVar51;
      puVar8[2] = 7;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *piVar26 = *piVar26 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
      DAT_140e46c88 = puVar8;
      if (iVar5 == 3) {
        auVar98._12_4_ = in_stack_fffffffffffffe98._12_4_;
        auVar98._0_8_ = in_stack_fffffffffffffe98._0_8_;
        auVar98._8_4_ = 0x29;
        auVar99._4_12_ = auVar98._4_12_;
        auVar99._0_4_ = 0x2a;
        iVar5 = FUN_1400c9580(param_1[3],0,7,4,0x28,0x29,auVar99);
        uVar52 = param_1[10];
        uVar51 = *(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4);
        puVar22 = (undefined4 *)_malloc_base(0x48);
        if (puVar22 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar22[3] = uVar52;
        *puVar22 = uVar51;
        puVar22[1] = 0x22;
        fVar29 = fVar39 + DAT_14053ace8;
        puVar22[2] = 7;
        *(undefined2 *)(puVar22 + 5) = 0;
        *(undefined8 *)(puVar22 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar22 + 8) = 0x3ff0000000000000;
        puVar22[4] = fVar29;
        puVar22[10] = 0xff;
        puVar22[0xb] = 0xff;
        puVar22[0xc] = 0xff;
        puVar22[0xd] = 0xff;
        *(undefined8 *)(puVar22 + 0xe) = 1;
        *(undefined8 *)(puVar22 + 0x10) = 0;
        _DAT_140e46d18 = _DAT_140e46d18 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar22;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar22;
        }
        uVar51 = DAT_140e44998;
        uVar52 = param_1[10];
        DAT_140e46c88 = puVar22;
        puVar8 = (undefined4 *)_malloc_base(0x48);
        if (puVar8 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        fVar39 = fVar39 - _DAT_14053ae40;
        puVar8[3] = uVar52;
        *puVar8 = uVar51;
        puVar8[1] = 0x24;
        puVar8[2] = 7;
        puVar8[4] = fVar39;
        *(undefined2 *)(puVar8 + 5) = 0;
        *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0xff;
        puVar8[0xc] = 0xff;
        puVar8[0xd] = 0xff;
        *(undefined8 *)(puVar8 + 0xe) = 1;
        *(undefined8 *)(puVar8 + 0x10) = 0;
        _DAT_140e46d20 = _DAT_140e46d20 + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar8;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
        }
        break;
      }
    }
    uVar21 = (ulonglong)(iVar5 + 1U);
    uVar27 = uVar27 + 1;
    puVar22 = puVar22 + 1;
    piVar26 = piVar26 + 3;
    puVar8 = DAT_140e46c88;
  } while ((int)(iVar5 + 1U) < 4);
  DAT_140e46c88 = puVar8;
  dVar36 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - 0.0) * DAT_14053abc0 *
                                 (double)CONCAT44(uVar47,uVar46) * (double)CONCAT44(uVar49,uVar48));
  uVar47 = DAT_140e4509c;
  fVar29 = (float)param_1[0xb];
  dVar36 = dVar36 * DAT_140539e60;
  uVar46 = param_1[10];
  puVar22 = (undefined4 *)_malloc_base(0x48);
  if (puVar22 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cec = _DAT_140e46cec + 1;
  bVar28 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar22[3] = uVar46;
  puVar22[4] = fVar29 + fVar38;
  *(double *)(puVar22 + 8) = dVar36 + (double)CONCAT44(uVar45,uVar44);
  *puVar22 = uVar47;
  puVar22[1] = 0x17;
  puVar22[2] = 8;
  *(undefined2 *)(puVar22 + 5) = 0;
  *(undefined8 *)(puVar22 + 6) = 0x3ff0000000000000;
  puVar22[10] = 0xff;
  puVar22[0xb] = 0xff;
  puVar22[0xc] = 0xff;
  puVar22[0xd] = 0xe1;
  *(undefined8 *)(puVar22 + 0xe) = 1;
  *(undefined8 *)(puVar22 + 0x10) = 0;
  if (bVar28) {
    DAT_140e46bf0 = puVar22;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar22;
  }
  DAT_140e46c88 = puVar22;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x12) * 0x12) {
    FUN_140184700(DAT_140e44190 << 4,DAT_140e472f8);
    FUN_14018a340(DAT_140e472f8,1,1);
  }
LAB_140020e4a:
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


