// Function: FUN_14005e890 @ 14005e890
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005e890(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  double dVar4;
  uint uVar5;
  undefined8 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  double dVar15;
  undefined8 uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  float fVar22;
  double dVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  uint in_stack_fffffffffffffe58;
  undefined2 uVar28;
  uint in_stack_fffffffffffffe60;
  uint uVar29;
  undefined8 in_stack_fffffffffffffe70;
  undefined4 uVar30;
  undefined4 uVar31;
  longlong local_158;
  undefined8 uStack_148;
  undefined8 local_140;
  
  dVar23 = DAT_140539f40;
  lVar11 = DAT_140e45d80;
  iVar10 = local_140._4_4_;
  uVar29 = uStack_148._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar10 = (int)((ulonglong)local_140 >> 0x20);
      uVar29 = (uint)((ulonglong)uStack_148 >> 0x20);
      if (lVar11 == 0) break;
      if (*(int *)(lVar11 + 4) == param_1[2]) {
        uStack_148 = *(undefined8 *)(lVar11 + 8);
        local_140 = *(undefined8 *)(lVar11 + 0x10);
      }
      lVar11 = *(longlong *)(lVar11 + 0x60);
    }
  }
  uStack_148._4_4_ = uVar29;
  local_140._4_4_ = iVar10;
  iVar10 = param_1[6];
  iVar8 = 0;
  fVar27 = (float)param_1[10];
  fVar26 = (float)param_1[0xb];
  lVar11 = (ulonglong)(iVar10 == 0x117) + 0x5a;
  iVar9 = 0xff;
  iVar12 = 0;
  if (iVar10 == 0x118) {
    lVar11 = 0x5c;
    local_158 = lVar11;
  }
  else {
    local_158 = (ulonglong)(iVar10 == 0x117) + 0x5a;
    if (iVar10 == 0x119) {
      lVar11 = 0x5d;
      local_158 = lVar11;
    }
  }
  if ((local_140._4_4_ == 99) && ((int)param_1[5] < 99)) {
    in_stack_fffffffffffffe70 =
         CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),param_1[0x14]);
    in_stack_fffffffffffffe58 = param_1[0xb];
    in_stack_fffffffffffffe60 = in_stack_fffffffffffffe60 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,fVar27,in_stack_fffffffffffffe58,in_stack_fffffffffffffe60,
               DAT_14053a3d8,in_stack_fffffffffffffe70,1,0);
    param_1[3] = 0;
    param_1[5] = 99;
  }
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe70 >> 0x20);
  uVar28 = (undefined2)(in_stack_fffffffffffffe58 >> 0x10);
  uVar29 = param_1[5];
  param_1[0x15] = 1;
  uVar30 = DAT_140e472fc;
  fVar25 = DAT_14053ad14;
  uVar3 = DAT_14053ac2c;
  dVar15 = DAT_14053aba0;
  dVar4 = DAT_14053a798;
  dVar18 = DAT_14053a5f8;
  dVar19 = DAT_14053a020;
  dVar17 = DAT_140539d28;
  dVar20 = dVar23;
  iVar13 = 0;
  dVar21 = dVar23;
  iVar10 = 0xff;
  if (uVar29 < 100) {
    iVar13 = iVar12;
    iVar10 = iVar9;
    switch(uVar29) {
    case 0:
      uVar3 = param_1[3];
      iVar10 = iVar8;
      if (((int)uVar3 < 0x96) || (iVar10 = 0xff, 0xb3 < (int)uVar3)) {
        iVar8 = ((int)uVar3 >> 0x1f & 0xffffff01U) + 0xff;
        if ((int)uVar3 < 0) {
          iVar13 = 0;
          if ((int)uVar3 < 0xb4) {
            iVar13 = iVar8;
          }
          goto LAB_14005eb7c;
        }
        if ((int)uVar3 < 0x96) {
          dVar17 = (double)FUN_140332d90(IMAGE_DOS_HEADER_140000000.e_magic +
                                         (&switchD_14005ea6f::switchdataD_14005fba8)
                                         [(&switchD_14005ea6f::switchdataD_14005fbbc)[(int)uVar29]],
                                         ((double)(int)uVar3 - 0.0) * _DAT_14053a478 * DAT_14053a020
                                         * DAT_140539d28);
          iVar13 = (int)(dVar17 * dVar18);
          goto LAB_14005eb7c;
        }
        if (uVar3 < 0xb4) goto LAB_14005eb35;
        iVar13 = 0;
        if ((int)uVar3 < 0xb4) {
          iVar13 = iVar8;
        }
        if (uVar3 != 0xbe) goto LAB_14005eb7c;
LAB_14005eb86:
        param_1[3] = 0;
        param_1[5] = uVar29 + 1;
      }
      else {
        dVar15 = (double)FUN_140332d90(((double)(int)uVar3 - DAT_14053a510) * DAT_14053a798 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar10 = (int)(dVar15 * dVar18);
LAB_14005eb35:
        dVar17 = (double)FUN_140332d90(((double)(int)uVar3 - DAT_14053a4a0) * dVar4 * dVar19 *
                                       dVar17);
        iVar13 = (int)(dVar17 * dVar18);
LAB_14005eb7c:
        if (local_140._4_4_ == 1) goto LAB_14005eb86;
      }
      fVar25 = DAT_14053ad40;
      if (iVar10 < 1) goto LAB_14005f7dd;
      break;
    case 1:
    case 3:
      iVar8 = param_1[3];
      if (iVar8 == 1) {
        *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
        FUN_140184700(DAT_140e44190 * 0x13,uVar30);
        FUN_14018a340(DAT_140e472fc,1,1);
        iVar8 = param_1[3];
      }
      if ((((float)param_1[0xe] < DAT_14053ae30) && (param_1[5] == 1)) ||
         ((DAT_14053ae30 <= (float)param_1[0xe] && (param_1[5] == 3)))) {
        fVar27 = (float)param_1[0xc];
        fVar25 = fVar27 + DAT_14053acbc;
      }
      else {
        fVar27 = (float)param_1[0xc];
        fVar25 = fVar27 - DAT_14053acbc;
      }
      fVar26 = (float)param_1[0xd];
      if (0.0 <= fVar26) {
        if (fVar26 < DAT_14053aec0) {
          fVar24 = fVar26 + DAT_14053ad40;
        }
        else {
          fVar24 = fVar26 + DAT_14053ae14;
        }
      }
      else {
        fVar24 = fVar26 + DAT_14053ad9c;
      }
      dVar20 = (double)FUN_140332d90();
      fVar27 = (float)(dVar20 * (double)(fVar25 - fVar27)) + fVar27;
      dVar20 = (double)FUN_140332d90();
      fVar26 = (float)(dVar20 * (double)(fVar24 - fVar26)) + fVar26;
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053b178;
      param_1[10] = fVar27;
      param_1[0xb] = (float)dVar20 + fVar26;
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053b070;
      dVar21 = (double)FUN_140332d90();
      dVar21 = dVar21 * DAT_140539ee0;
      if (iVar8 == 0x28) {
        param_1[5] = param_1[5] + 1;
        uVar30 = DAT_140e47300;
        param_1[3] = 0;
        FUN_140184700(DAT_140e44190 * 0x13,uVar30);
        FUN_14018a340(DAT_140e47300,1,1);
      }
      param_1[0x15] = 0;
      dVar20 = dVar20 + dVar23;
      dVar21 = dVar21 + dVar23;
      break;
    case 2:
    case 4:
      fVar24 = (float)param_1[0xb];
      if (fVar24 < DAT_14053ae48) {
        iVar9 = param_1[3];
        uVar29 = iVar9 - 10;
        if (param_1[6] == 0x116) {
          if (iVar9 == 10) {
            dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar24 + DAT_14053ad14)),
                                           (double)(DAT_140e445d8 - (float)param_1[10]));
            *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar20 * dVar15);
          }
          uVar28 = (undefined2)(in_stack_fffffffffffffe58 >> 0x10);
          if (uVar29 < 0x1e) {
            uVar5 = uVar29 & 0x80000003;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
            }
            if (uVar5 == 0) {
              if (uVar29 * 100 == 0x10000) {
                do {
                  in_stack_fffffffffffffe70 =
                       CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),1);
                  in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffff0000;
                  FUN_14006c2f0(0xb,1);
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 2);
              }
              else {
                do {
                  in_stack_fffffffffffffe70 =
                       CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),1);
                  in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffff0000;
                  FUN_14006c2f0(0xb,1);
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 2);
              }
              iVar8 = 0;
              if ((iVar9 + 0x6e) * 100 == 0x10000) {
                do {
                  in_stack_fffffffffffffe70 =
                       CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),1);
                  in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffff0000;
                  in_stack_fffffffffffffe60 = uVar3;
                  FUN_14006c2f0(0xb,1);
                  uVar28 = (undefined2)(in_stack_fffffffffffffe58 >> 0x10);
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 2);
              }
              else {
                do {
                  in_stack_fffffffffffffe70 =
                       CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),1);
                  in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffff0000;
                  in_stack_fffffffffffffe60 = uVar3;
                  FUN_14006c2f0(0xb,1);
                  uVar28 = (undefined2)(in_stack_fffffffffffffe58 >> 0x10);
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 2);
              }
              FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
              fVar24 = (float)param_1[0xb];
              iVar9 = param_1[3];
            }
          }
        }
        fVar2 = DAT_14053ad10;
        if (param_1[6] == 0x117) {
          fVar22 = fVar24 + DAT_14053ad10;
          fVar1 = (float)param_1[10];
          dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar22),
                                         (double)(DAT_140e445d8 - fVar1));
          uVar30 = (undefined4)((ulonglong)in_stack_fffffffffffffe70 >> 0x20);
          if (iVar9 - 10U < 0x1e) {
            uVar5 = (uStack_148._4_4_ + 0x115c >> 0x1e ^ uStack_148._4_4_ + 0x115c) * 0x6c078965 + 1
            ;
            uVar7 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
            uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 3;
            uVar5 = uVar5 * 0x800 ^ uVar5;
            uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 4;
            uVar5 = (uVar7 >> 0xb ^ uVar5) >> 8 ^ uVar7 ^ uVar5;
            uVar7 = (uStack_148._4_4_ >> 0x1e ^ uStack_148._4_4_) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar7 = uVar7 * 0x800 ^ uVar7;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            uVar7 = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
            DAT_140e9fd1c = uVar7;
            uVar16 = FUN_140134db0(uStack_148._4_4_ + 0x1bc,DAT_14053a018,DAT_14053a0f8);
            in_stack_fffffffffffffe70 = CONCAT44(uVar30,1);
            in_stack_fffffffffffffe60 = uVar3;
            FUN_14006c2f0(0xc,2,(float)(int)(uVar7 % 0x51 - 0x28) + fVar1,fVar22,
                          CONCAT22(uVar28,(short)uVar5 + (short)(uVar5 / 0x8ca1) * 0x735f + -18000 +
                                          (short)(int)(dVar20 * dVar15)),uVar3,uVar16,
                          in_stack_fffffffffffffe70,0);
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
            fVar24 = (float)param_1[0xb];
            iVar9 = param_1[3];
          }
        }
        uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe70 >> 0x20);
        iVar8 = 0;
        if (param_1[6] == 0x118) {
          FUN_1403300b4((double)(DAT_140e445dc - (fVar24 + fVar2)),
                        (double)(DAT_140e445d8 - (float)param_1[10]));
          uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe70 >> 0x20);
          uVar5 = iVar9 - 10;
          if ((uVar5 < 0x32) && (uVar5 == ((int)uVar5 / 0xf) * 0xf)) {
            do {
              in_stack_fffffffffffffe70 =
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffe70 >> 0x20),1);
              in_stack_fffffffffffffe60 = uVar3;
              FUN_14006c2f0(3,1);
              uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe70 >> 0x20);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 5);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            fVar24 = (float)param_1[0xb];
            iVar9 = param_1[3];
          }
        }
        if (param_1[6] == 0x119) {
          fVar2 = (float)param_1[10];
          if (iVar9 == 10) {
            dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar24 + fVar25)),
                                           (double)(DAT_140e445d8 - fVar2));
            *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar20 * dVar15);
          }
          else if (0x31 < iVar9 - 10U) goto LAB_14005f4cd;
          if (iVar9 + -10 == ((iVar9 + -10) / 5) * 5) {
            uVar16 = CONCAT44(uVar31,1);
            FUN_14006c2f0(4,0,fVar2 - DAT_14053ac44,fVar24 + fVar25,
                          (short)uVar29 * 0x28a + *(short *)((longlong)param_1 + 0x42) + -0x4000,0,
                          (double)(int)uVar29 * DAT_140539e90 + DAT_140539ff0,uVar16,0);
            uVar31 = (undefined4)((ulonglong)uVar16 >> 0x20);
            in_stack_fffffffffffffe60 = 0;
            FUN_14006c2f0(4,0);
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
          }
        }
      }
LAB_14005f4cd:
      dVar19 = DAT_14053a020;
      dVar17 = DAT_140539d28;
      iVar13 = 0;
      iVar8 = param_1[3];
      dVar21 = (double)FUN_140332d90();
      dVar20 = DAT_140539e60;
      dVar21 = dVar21 * _DAT_140539e28;
      if (-1 < iVar8) {
        if (iVar8 < 0x3c) {
          dVar17 = (double)FUN_140332d90(((double)iVar8 - _DAT_14053b158) * DAT_14053a628 * dVar19 *
                                         dVar17);
          dVar20 = dVar20 * dVar17 + 0.0;
        }
        else {
          dVar20 = 0.0;
        }
      }
      dVar17 = (double)FUN_140332d90();
      dVar20 = dVar17 * dVar20 + 0.0 + dVar21 + dVar23;
      dVar21 = (double)FUN_140332d90();
      dVar17 = DAT_14053b058;
      dVar21 = dVar21 * _DAT_14053b050 + dVar23;
      if (iVar8 < 0) {
        dVar19 = (double)FUN_140332d90();
        dVar19 = dVar19 * dVar17;
LAB_14005f658:
        dVar21 = dVar19 + 0.0 + dVar21;
      }
      else {
        if (iVar8 < 0x3c) {
          dVar18 = (double)FUN_140332d90();
          dVar19 = (double)FUN_140332d90();
          dVar19 = dVar19 * (dVar18 * dVar17 + 0.0);
          goto LAB_14005f658;
        }
        dVar17 = (double)FUN_140332d90();
        dVar21 = dVar17 * 0.0 + 0.0 + dVar21;
        if (iVar8 == 0x50) {
          param_1[3] = 0;
          if (param_1[5] == 4) {
            param_1[5] = 1;
          }
          else {
            param_1[5] = param_1[5] + 1;
          }
        }
      }
      param_1[0x15] = 0;
      if ((int)param_1[7] < 1) {
        if (DAT_140e44600 == 0) {
          in_stack_fffffffffffffe60 = CONCAT22((short)(in_stack_fffffffffffffe60 >> 0x10),0x4000);
          stage_entity_spawn_candidate
                    (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,in_stack_fffffffffffffe60,dVar23
                     ,CONCAT44(uVar31,10),1,DAT_140e44308);
        }
        FUN_14007b010(param_1,0x960,0xc);
        FUN_140079e20(param_1,2);
        *param_1 = 0;
      }
      break;
    case 99:
      puVar6 = DAT_140e45d28;
      if (param_1[3] == 1) {
        uVar30 = param_1[0xb];
        uVar31 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar31;
          *(undefined4 *)(puVar6 + 3) = uVar30;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar31;
          *(undefined4 *)(puVar6 + 4) = uVar30;
          *puVar6 = 1;
          puVar6[1] = 0x36;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar14) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
      DAT_140e45d28 = puVar6;
      iVar8 = param_1[3];
      if (iVar8 < 0x5a) {
        FUN_14007ac00(param_1);
        iVar8 = param_1[3];
        param_1[0xb] = (float)iVar8 * _DAT_140539ccc + (float)param_1[0xb];
      }
      puVar6 = DAT_140e45d28;
      if (iVar8 == 0x5a) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
        FUN_14018a340(DAT_140e472a0,1,1);
        uVar30 = param_1[0xb];
        uVar31 = param_1[10];
        puVar6 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar14 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar6 + 0x14) = uVar31;
          *(undefined4 *)(puVar6 + 3) = uVar30;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar31;
          *(undefined4 *)(puVar6 + 4) = uVar30;
          *puVar6 = 1;
          puVar6[1] = 0x11;
          *(undefined4 *)(puVar6 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x3ff0000000000000;
          puVar6[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar6 + 8) = 0;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          puVar6[10] = 0xff;
          puVar6[0xb] = 0;
          if (bVar14) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
      }
      DAT_140e45d28 = puVar6;
      if (99 < (int)param_1[3]) {
        iVar13 = 0;
        fVar25 = DAT_14053ad40;
        if (param_1[3] == 0x8c) {
          *param_1 = 0;
          iVar13 = 0;
          fVar25 = DAT_14053ad40;
        }
        goto LAB_14005f7dd;
      }
      dVar20 = (double)FUN_140332d90();
      dVar20 = dVar20 * _DAT_14053b068;
      dVar21 = (double)FUN_140332d90();
      dVar20 = dVar20 + dVar23;
      dVar21 = dVar21 * DAT_140539ec8 + dVar23;
    }
  }
  fVar25 = DAT_14053ad40;
  uVar29 = in_stack_fffffffffffffe60 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44910)[local_158],0x19 - (int)(fVar26 / DAT_14053b380),0xb,param_1[10],
                (float)param_1[0xb] + DAT_14053ad40,uVar29,dVar20,dVar21,0xff,0xff,0xff,iVar10,1,0);
  in_stack_fffffffffffffe60 = uVar29 & 0xffff0000;
  FUN_1400c8410(DAT_140e44a74,0x14,0xb,fVar27,fVar26 + fVar25,in_stack_fffffffffffffe60,dVar20,
                dVar23,0xff,0xff,0xff,iVar10 / 2,1,0);
  dVar23 = dVar21;
LAB_14005f7dd:
  if (0 < iVar13) {
    FUN_1400c8410((&DAT_140e44910)[lVar11],0x1e,0xc,param_1[10],(float)param_1[0xb] + fVar25,
                  in_stack_fffffffffffffe60 & 0xffff0000,dVar20,dVar23,0xff,0xff,0xff,iVar13,1,0);
  }
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if (_DAT_14053af6c <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


