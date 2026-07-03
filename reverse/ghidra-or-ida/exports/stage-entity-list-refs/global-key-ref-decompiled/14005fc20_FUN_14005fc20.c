// Function: FUN_14005fc20 @ 14005fc20
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14005fc20(undefined4 *param_1)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  bool bVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  uint in_stack_fffffffffffffe50;
  ushort uVar31;
  undefined4 uVar30;
  undefined8 uVar32;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined1 local_f0 [184];
  
  uStack_140 = 0;
  uStack_140._4_4_ = 0;
  lVar4 = DAT_140e45d80;
  iVar15 = local_148._4_4_;
  iVar12 = uStack_140._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar15 = (int)((ulonglong)local_148 >> 0x20);
      iVar12 = (int)((ulonglong)uStack_140 >> 0x20);
      if (lVar4 == 0) break;
      if (*(int *)(lVar4 + 4) == DAT_140e44308) {
        local_148 = *(undefined8 *)(lVar4 + 0x10);
        uStack_140 = *(undefined8 *)(lVar4 + 0x18);
        local_138 = *(undefined8 *)(lVar4 + 0x20);
      }
      lVar4 = *(longlong *)(lVar4 + 0x60);
    }
  }
  uStack_140._4_4_ = iVar12;
  local_148._4_4_ = iVar15;
  pfVar1 = (float *)(param_1 + 0xb);
  pfVar2 = (float *)(param_1 + 10);
  FUN_1403300b4((double)((float)param_1[0xd] - *pfVar1),
                SUB84((double)((float)param_1[0xc] - *pfVar2),0));
  dVar22 = DAT_14053aba0;
  fVar19 = (float)FUN_140334430();
  fVar20 = (float)FUN_140334430();
  if (fVar19 + fVar20 < 0.0) {
    fVar19 = (float)FUN_1403352f8();
  }
  else {
    fVar19 = SQRT(fVar19 + fVar20);
  }
  if ((local_148._4_4_ == 100) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,*pfVar2,*pfVar1,in_stack_fffffffffffffe50,DAT_14053a4f0,
               param_1[0x14],1,0);
    param_1[5] = 99;
    DAT_140e419bc = 2;
    param_1[0x17] = 0;
  }
  uVar30 = _UNK_14053bb28;
  uVar29 = _UNK_14053bb24;
  uVar28 = _DAT_14053bb20;
  uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
  iVar15 = param_1[5];
  param_1[0x15] = 1;
  iVar12 = DAT_140e45d1c;
  dVar24 = DAT_14053a020;
  dVar26 = DAT_140539d28;
  if (iVar15 == 0) {
    uVar13 = param_1[3];
    puVar6 = (undefined8 *)FUN_140135060(local_f0,uVar13,0x14);
    dVar23 = DAT_14053a798;
    dVar24 = DAT_14053a5f8;
    dVar26 = DAT_14053a020;
    dVar22 = DAT_140539d28;
    iVar15 = 0;
    uVar32 = *puVar6;
    if (0x95 < (int)uVar13) {
      iVar15 = 0xff;
    }
    uVar3 = *(undefined4 *)(puVar6 + 1);
    if (((int)uVar13 < 0x96) || (0xb3 < (int)uVar13)) {
      iVar12 = ((int)uVar13 >> 0x1f & 0xffffff01U) + 0xff;
      if (-1 < (int)uVar13) {
        if ((int)uVar13 < 0x96) {
          dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - 0.0) * _DAT_14053a478 *
                                         DAT_14053a020 * DAT_140539d28);
          goto LAB_140061852;
        }
        if (uVar13 < 0xb4) goto LAB_140061830;
      }
    }
    else {
      dVar25 = (double)FUN_140332d90(((double)(int)uVar13 - DAT_14053a510) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar15 = (int)(dVar25 * dVar24);
LAB_140061830:
      dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - DAT_14053a4a0) * dVar23 * dVar26 *
                                     dVar22);
LAB_140061852:
      iVar12 = (int)(dVar22 * dVar24);
    }
    piVar17 = param_1 + 3;
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a88,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,
                  CONCAT44(uVar29,uVar28),uVar30,0xff,0xff,0xff,iVar15,1,0,uVar32);
    iVar15 = 0;
    if ((int)uVar13 < 0xb4) {
      iVar15 = iVar12;
    }
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a88,0x1e,8,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,
                  CONCAT44(uVar29,uVar28),uVar30,(int)uVar32,(int)((ulonglong)uVar32 >> 0x20),uVar3,
                  iVar15,1,0);
    uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
    if (*piVar17 == 0) {
      uVar30 = CONCAT22(uVar31,0x4000);
      stage_entity_spawn_candidate
                (0x11b,99999999,0,0,DAT_14053b370,uVar30,DAT_14053a1e8,100,1,param_1[1]);
      uVar31 = (ushort)((uint)uVar30 >> 0x10);
    }
    if (*piVar17 == 0xbe) {
      param_1[5] = param_1[5] + 1;
      param_1[8] = (undefined4)local_138;
      *(undefined8 *)(param_1 + 0x12) = 0x4051800000000000;
      *piVar17 = 0;
      param_1[7] = uStack_140._4_4_;
      param_1[0xc] = 0x43960000;
      param_1[0xd] = 0x430c0000;
    }
    goto LAB_140061205;
  }
  if (iVar15 == 1) {
LAB_14006135c:
    dVar26 = *(double *)(param_1 + 0x12);
    dVar24 = (double)FUN_1403307c0();
    fVar20 = (float)(dVar24 * ((double)fVar19 / dVar26)) + *pfVar2;
    *pfVar2 = fVar20;
    dVar24 = (double)FUN_140332d90();
    uVar13 = param_1[3];
    fVar19 = (float)(dVar24 * ((double)fVar19 / dVar26)) + *pfVar1;
    *pfVar1 = fVar19;
    if (uVar13 == ((int)uVar13 / 0x5a) * 0x5a) {
      uVar10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
      uVar8 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
      uVar10 = uVar10 * 0x800 ^ uVar10;
      uVar9 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 4;
      uVar8 = DAT_1407c7798 * 0x15b3 + uVar13;
      uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
      param_1[0xc] = (float)(((uVar9 >> 0xb ^ uVar10) >> 8 ^ uVar9 ^ uVar10) % 0x12d + 0xd2);
      DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar8 = uVar8 * 0x800 ^ uVar8;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ uVar8 ^ DAT_140e9fd18;
      param_1[0xd] = (float)(DAT_140e9fd1c % 0x65 + 200);
    }
    fVar19 = fVar19 - DAT_14053ad1c;
    dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),
                                   SUB84((double)(DAT_140e445d8 - fVar20),0));
    uVar32 = DAT_14053a1a8;
    iVar12 = 0xd;
    if (iVar15 != 3) {
      iVar12 = 0x1b;
    }
    uVar13 = uVar13 - 0x1e;
    iVar15 = 0;
    if ((uVar13 < 0x14a) && (iVar14 = iVar15, uVar13 == ((int)uVar13 / 0x1e) * 0x1e)) {
      do {
        in_stack_fffffffffffffe50 = 0;
        FUN_14006c2f0(3,0,fVar20,fVar19,
                      (short)iVar14 * 0x8ca + (short)(int)(dVar26 * dVar22) + -0x1194,0,uVar32,1,0);
        iVar14 = iVar14 + 1;
      } while (iVar14 < 5);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    uVar32 = DAT_14053a130;
    iVar14 = param_1[3];
    if ((iVar14 - 0x1eU < 0x14a) && ((iVar14 + -0x1e) % iVar12 == 0)) {
      do {
        in_stack_fffffffffffffe50 = 0;
        FUN_14006c2f0(4,0,fVar20,fVar19,(short)iVar15 * 0x8d3 + (short)iVar14 * 0x3c,0,uVar32,1,0);
        iVar15 = iVar15 + 1;
      } while (iVar15 < 0x1d);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a88,0x1e,7,param_1[10],*pfVar1,in_stack_fffffffffffffe50,
                  CONCAT44(uVar29,uVar28),uVar30,0xff,0xff,0xff,0xff,1,0);
    uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
    if (param_1[3] == 0x168) {
      param_1[3] = 0;
      *(undefined8 *)(param_1 + 0x12) = 0x403e000000000000;
      param_1[5] = 2;
    }
  }
  else {
    if (iVar15 != 2) {
      if (iVar15 != 3) {
        if (iVar15 != 99) goto LAB_140061205;
        iVar15 = param_1[3];
        iVar14 = 0;
        if (iVar15 < 0x5a) {
LAB_14005fef3:
          iVar16 = 0;
          if (iVar15 < 0x8c) {
            iVar16 = iVar14;
          }
          puVar6 = DAT_140e45d28;
          if (iVar15 == 1) {
            fVar20 = *pfVar1;
            fVar27 = *pfVar2;
            *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)pfVar2;
            puVar6 = DAT_140e45d28;
            if (iVar12 < 0x1000) {
              puVar6 = (undefined8 *)_malloc_base(0x60);
              if (puVar6 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
              *(float *)((longlong)puVar6 + 0x14) = fVar27;
              *(float *)(puVar6 + 3) = fVar20;
              *(float *)((longlong)puVar6 + 0x1c) = fVar27;
              *(float *)(puVar6 + 4) = fVar20;
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
              if (bVar18) {
                DAT_140e45d78 = puVar6;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar6;
              }
            }
          }
        }
        else {
          iVar14 = 0xff;
          if (iVar15 < 100) {
            dVar22 = (double)FUN_140332d90(((double)iVar15 - DAT_14053a430) * DAT_14053a9d8 *
                                           DAT_14053a020 * DAT_140539d28);
            iVar16 = (int)(dVar22 * DAT_14053a5f8);
            puVar6 = DAT_140e45d28;
          }
          else {
            if (0x8b < iVar15) goto LAB_14005fef3;
            dVar22 = (double)FUN_140332d90(((double)iVar15 - DAT_14053a3a0) * DAT_14053a6d8 *
                                           DAT_14053a020 * DAT_140539d28);
            iVar16 = 0;
            puVar6 = DAT_140e45d28;
            if (iVar15 < 0x8c) {
              iVar16 = (int)(dVar22 * DAT_14053a5f8);
            }
          }
        }
        DAT_140e45d28 = puVar6;
        iVar15 = param_1[3];
        if (iVar15 < 0x5a) {
          dVar22 = (double)FUN_140332d90(((double)iVar15 - 0.0) * _DAT_14053aac0 * dVar24 * dVar26);
          param_1[0xc] = (float)(dVar22 * DAT_14053a2d8) + (float)param_1[0xe];
          dVar22 = (double)FUN_140332d90();
          dVar26 = (double)fVar19 / DAT_14053a0b0;
          param_1[0xd] = (float)(dVar22 * DAT_14053a138) + (float)param_1[0xf];
          dVar22 = (double)FUN_1403307c0();
          *pfVar2 = (float)(dVar22 * dVar26) + *pfVar2;
          dVar22 = (double)FUN_140332d90();
          *pfVar1 = (float)(dVar22 * dVar26) + *pfVar1;
          param_1[0xf] = (float)iVar15 * _DAT_140539ccc + (float)param_1[0xf];
          FUN_14007ac00(param_1);
        }
        puVar6 = DAT_140e45d28;
        if (param_1[3] == 0x5a) {
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
          FUN_14018a340(DAT_140e472a0,1,1);
          fVar19 = *pfVar1;
          fVar20 = *pfVar2;
          puVar6 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar6 = (undefined8 *)_malloc_base(0x60);
            if (puVar6 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
            *(float *)((longlong)puVar6 + 0x14) = fVar20;
            *(float *)(puVar6 + 3) = fVar19;
            *(float *)((longlong)puVar6 + 0x1c) = fVar20;
            *(float *)(puVar6 + 4) = fVar19;
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
            if (bVar18) {
              DAT_140e45d78 = puVar6;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar6;
            }
          }
        }
        DAT_140e45d28 = puVar6;
        uVar3 = DAT_140e41ab8;
        puVar7 = (undefined4 *)_malloc_base(0x48);
        if (puVar7 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
        _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
        bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
        *puVar7 = uVar3;
        puVar7[1] = 0x4e;
        *(undefined8 *)(puVar7 + 2) = 5;
        puVar7[4] = 0;
        *(undefined2 *)(puVar7 + 5) = 0;
        *(undefined8 *)(puVar7 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
        puVar7[10] = 0xff;
        puVar7[0xb] = 0xff;
        puVar7[0xc] = 0xff;
        puVar7[0xd] = iVar16;
        *(undefined8 *)(puVar7 + 0xe) = 1;
        *(undefined8 *)(puVar7 + 0x10) = 0;
        if (bVar18) {
          DAT_140e46bf0 = puVar7;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
        }
        DAT_140e46c88 = puVar7;
        if ((int)param_1[3] < 100) {
          in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
          FUN_1400c8410(DAT_140e44a88,0x1e,7,*pfVar2,*pfVar1,in_stack_fffffffffffffe50,
                        CONCAT44(uVar29,uVar28),uVar30,0xff,0xff,0xff,0xff,1,0);
          uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
        }
        if (param_1[3] == 0x8c) {
          *param_1 = 0;
        }
        goto LAB_140061205;
      }
      goto LAB_14006135c;
    }
    dVar22 = *(double *)(param_1 + 0x12);
    dVar23 = (double)FUN_1403307c0();
    fVar27 = (float)(dVar23 * ((double)fVar19 / dVar22)) + *pfVar2;
    *pfVar2 = fVar27;
    dVar23 = (double)FUN_140332d90();
    fVar20 = DAT_14053ae74;
    uVar13 = param_1[3];
    fVar19 = (float)(dVar23 * ((double)fVar19 / dVar22)) + *pfVar1;
    *pfVar1 = fVar19;
    if (uVar13 - 500 < 0x6e) {
      dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - _DAT_14053a6c0) * _DAT_14053a508 *
                                     dVar24 * dVar26);
      fVar20 = (float)(dVar22 * _DAT_14053a718) + 0.0;
LAB_1400603c1:
      if ((int)uVar13 < 0x32) {
        fVar19 = fVar19 - DAT_14053ad1c;
        if ((int)uVar13 < 0x1e) goto LAB_14006058e;
      }
      else {
        dVar22 = (double)FUN_140332d90(((double)(int)uVar13 - DAT_14053a380) * _DAT_14053a4d0 *
                                       dVar24 * dVar26);
        fVar19 = fVar19 - DAT_14053ad1c;
        fVar21 = (float)param_1[0xd] - _DAT_140539d30;
        param_1[0xc] = (float)(dVar22 * (double)fVar20) + DAT_14053ae30;
        param_1[0xd] = fVar21;
      }
      uVar30 = DAT_140e41a50;
      if ((uVar13 < 0x24e) && (uVar13 - 0x1e == ((int)(uVar13 - 0x1e) / 0x48) * 0x48)) {
        uVar3 = param_1[1];
        puVar6 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar6 = (undefined8 *)_malloc_base(0x60);
          if (puVar6 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar6 = 1;
          *(undefined4 *)(puVar6 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar6 + 0xc) = uVar30;
          *(undefined4 *)(puVar6 + 2) = 0x23;
          *(undefined4 *)((longlong)puVar6 + 0x14) = 0x42f00000;
          *(undefined4 *)(puVar6 + 3) = 0xc28c0000;
          *(undefined4 *)((longlong)puVar6 + 0x1c) = 0x42f00000;
          *(undefined4 *)(puVar6 + 4) = 0xc28c0000;
          *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
          puVar6[5] = 0;
          puVar6[6] = 0x4008000000000000;
          puVar6[7] = 0x4008000000000000;
          *(undefined4 *)(puVar6 + 8) = 0x1e;
          *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
          *(undefined4 *)(puVar6 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
          *(undefined4 *)(puVar6 + 10) = 0xff;
          *(undefined4 *)((longlong)puVar6 + 0x54) = uVar3;
          puVar6[0xb] = 0;
          if (bVar18) {
            DAT_140e45d78 = puVar6;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar6;
          }
        }
        DAT_140e45d28 = puVar6;
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
      }
    }
    else {
      if (0x261 < (int)uVar13) {
        fVar20 = 0.0;
        goto LAB_1400603c1;
      }
      if (uVar13 != 1) goto LAB_1400603c1;
      fVar19 = fVar19 - DAT_14053ad1c;
      param_1[0xc] = 0x43b40000;
      param_1[0xd] = 0x44020000;
    }
LAB_14006058e:
    uVar5 = DAT_14053a210;
    uVar32 = DAT_14053a0f8;
    dVar22 = DAT_14053a0b0;
    if ((param_1[3] - 0x3c < 0x230) &&
       (iVar15 = param_1[3] + -0x3c, iVar15 == (iVar15 / 0x48) * 0x48)) {
      iVar15 = 0;
      iVar14 = 0;
      iVar16 = 0;
      iVar12 = 0;
      do {
        fVar20 = *pfVar1 - DAT_14053ace8;
        uVar13 = iVar12 + param_1[3];
        uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
        dVar26 = (double)iVar15 * DAT_140539f00;
        uVar10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
        uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
        uVar13 = uVar13 * 0x800 ^ uVar13;
        uVar8 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
        uVar10 = param_1[3] + iVar16;
        uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
        fVar21 = (float)(int)(((uVar8 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ uVar8) % 0x29 - 0x14) +
                 *pfVar2 + DAT_14053ad40;
        DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar10 = uVar10 * 0x800 ^ uVar10;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
        FUN_14006c2f0(3,0,fVar21,fVar20,
                      (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x3e9) * -0x3e9 + 0x3e0c,0,
                      dVar26 + DAT_14053a178,1,0);
        uVar13 = ((uint)(param_1[3] + iVar14) >> 0x1e ^ param_1[3] + iVar14) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar13 = uVar13 * 0x800 ^ uVar13;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
        FUN_14006c2f0(5,0,fVar21,fVar20,
                      (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x3e9) * -0x3e9 + 0x3e0c,0,
                      dVar26 + _DAT_14053a188,1,0);
        iVar15 = iVar15 + 1;
        iVar12 = iVar12 + 0x37;
        iVar16 = iVar16 + 0x15b3;
        iVar14 = iVar14 + 0xd903;
      } while (iVar12 < 0x672);
      fVar20 = *pfVar1 - DAT_14053ace8;
      fVar21 = *pfVar2 + DAT_14053ad40;
      uVar13 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar13 = uVar13 * 0x800 ^ uVar13;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
      uVar13 = DAT_140e9fd1c / 0x3e9;
      sVar11 = (short)DAT_140e9fd1c;
      iVar12 = 0;
      iVar15 = iVar12;
      do {
        FUN_14006c2f0(2,0,fVar21,fVar20,
                      (short)iVar15 * 0x40e + sVar11 + (short)uVar13 * -0x3e9 + -0x76b0,0,uVar5,1,0)
        ;
        iVar15 = iVar15 + 1;
        iVar14 = iVar12;
      } while (iVar15 < 0x1b);
      do {
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar14 * 3000 + 0x35c8,0,dVar22,1,0);
        iVar14 = iVar14 + 1;
        iVar15 = iVar12;
      } while (iVar14 < 0xb);
      do {
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar15 * 3000 + 0x3d98,0,uVar32,1,0);
        dVar26 = DAT_14053a138;
        iVar15 = iVar15 + 1;
      } while (iVar15 < 0xb);
      do {
        in_stack_fffffffffffffe50 = 0;
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar12 * 3000 + 0x4568,0,dVar26,1,0);
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0xb);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472cc);
      FUN_14018a340(DAT_140e472cc,1,1);
    }
    uVar30 = DAT_140e41a50;
    fVar20 = DAT_14053ad40;
    iVar15 = 0;
    if ((param_1[3] - 0x42 < 0x20c) &&
       (iVar12 = param_1[3] + -0x42, iVar12 == (iVar12 / 0x48) * 0x48)) {
      uVar3 = param_1[1];
      puVar6 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar6 = (undefined8 *)_malloc_base(0x60);
        if (puVar6 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar6 = 1;
        *(undefined4 *)(puVar6 + 1) = 0x31;
        *(undefined4 *)((longlong)puVar6 + 0xc) = uVar30;
        *(undefined4 *)(puVar6 + 2) = 0x23;
        *(undefined4 *)((longlong)puVar6 + 0x14) = 0xc2f00000;
        *(undefined4 *)(puVar6 + 3) = 0xc28c0000;
        *(undefined4 *)((longlong)puVar6 + 0x1c) = 0xc2f00000;
        *(undefined4 *)(puVar6 + 4) = 0xc28c0000;
        *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
        puVar6[5] = 0;
        puVar6[6] = 0x4008000000000000;
        puVar6[7] = 0x4008000000000000;
        *(undefined4 *)(puVar6 + 8) = 0x1e;
        *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
        *(undefined4 *)(puVar6 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
        *(undefined4 *)(puVar6 + 10) = 0xff;
        *(undefined4 *)((longlong)puVar6 + 0x54) = uVar3;
        puVar6[0xb] = 0;
        if (bVar18) {
          DAT_140e45d78 = puVar6;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar6;
        }
      }
      DAT_140e45d28 = puVar6;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
    }
    if ((param_1[3] - 0x60 < 0x20c) &&
       (iVar12 = param_1[3] + -0x60, iVar12 == (iVar12 / 0x48) * 0x48)) {
      iVar16 = 0;
      iVar12 = iVar15;
      iVar14 = iVar15;
      do {
        fVar21 = (float)param_1[0xb] - DAT_14053ace8;
        uVar13 = iVar16 + param_1[3];
        uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
        dVar26 = (double)iVar15 * DAT_140539f00;
        uVar10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
        uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 3;
        uVar13 = uVar13 * 0x800 ^ uVar13;
        uVar8 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 4;
        uVar10 = param_1[3] + iVar12;
        uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
        fVar20 = (float)(int)(((uVar8 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ uVar8) % 0x29 - 0x14) +
                 (*pfVar2 - fVar20);
        uVar13 = uVar10 * 0x800 ^ uVar10;
        DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
        FUN_14006c2f0(3,0,fVar20,fVar21,
                      (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x3e9) * -0x3e9 + 0x3e0c,0,
                      dVar26 + DAT_14053a178,1,0);
        uVar13 = ((uint)(param_1[3] + iVar14) >> 0x1e ^ param_1[3] + iVar14) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar13 = uVar13 * 0x800 ^ uVar13;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ uVar13 ^ DAT_140e9fd18;
        FUN_14006c2f0(5,0,fVar20,fVar21,
                      (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x3e9) * -0x3e9 + 0x3e0c,0,
                      dVar26 + _DAT_14053a188,1,0);
        iVar15 = iVar15 + 1;
        iVar16 = iVar16 + 0x37;
        iVar12 = iVar12 + 0x15b3;
        iVar14 = iVar14 + 0xd903;
        fVar20 = DAT_14053ad40;
      } while (iVar16 < 0x672);
      fVar20 = (float)param_1[0xb] - DAT_14053ace8;
      fVar21 = *pfVar2 - DAT_14053ad40;
      uVar10 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
      uVar13 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
      uVar13 = DAT_140e9fd1c / 0x3e9;
      sVar11 = (short)DAT_140e9fd1c;
      iVar12 = 0;
      iVar15 = iVar12;
      do {
        FUN_14006c2f0(2,0,fVar21,fVar20,
                      (short)iVar15 * 0x40e + sVar11 + (short)uVar13 * -0x3e9 + -0x76b0,0,uVar5,1,0)
        ;
        iVar15 = iVar15 + 1;
        iVar14 = iVar12;
      } while (iVar15 < 0x1b);
      do {
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar14 * 3000 + -11000,0,dVar22,1,0);
        iVar14 = iVar14 + 1;
        iVar15 = iVar12;
      } while (iVar14 < 0xb);
      do {
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar15 * 3000 + -13000,0,uVar32,1,0);
        dVar22 = DAT_14053a138;
        iVar15 = iVar15 + 1;
      } while (iVar15 < 0xb);
      do {
        in_stack_fffffffffffffe50 = 0;
        FUN_14006c2f0(4,0,fVar27,fVar19,(short)iVar12 * 3000 + -15000,0,dVar22,1,0);
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0xb);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472cc);
      FUN_14018a340(DAT_140e472cc,1,1);
      uVar28 = (undefined4)DAT_140539f40;
      uVar29 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    }
    in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffff0000;
    FUN_1400c8410(DAT_140e44a88,0x1e,7,param_1[10],param_1[0xb],in_stack_fffffffffffffe50,
                  CONCAT44(uVar29,uVar28),uVar28,0xff,0xff,0xff,0xff,1,0);
    uVar31 = (ushort)(in_stack_fffffffffffffe50 >> 0x10);
    if (param_1[3] == 0x280) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x4051800000000000;
      param_1[3] = 0x13;
    }
  }
  param_1[0x15] = 0;
LAB_140061205:
  iVar15 = DAT_140e44308;
  if (param_1[0x15] == 0) {
    iVar12 = param_1[7];
    if ((iVar12 < uStack_140._4_4_) && (lVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
        if (*(int *)(lVar4 + 4) == iVar15) {
          *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) - (uStack_140._4_4_ - iVar12);
        }
      }
    }
    iVar15 = param_1[7];
    if (uStack_140._4_4_ < iVar15) {
      param_1[7] = uStack_140._4_4_;
      iVar15 = uStack_140._4_4_;
    }
    iVar12 = DAT_140e44308;
    if ((iVar15 < 1) && (lVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
      for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
        if (*(int *)(lVar4 + 4) == iVar12) {
          *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) - uStack_140._4_4_;
        }
      }
    }
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      stage_entity_spawn_candidate
                (0x136,99999999,1,0,0,(uint)uVar31 << 0x10,CONCAT44(uVar29,uVar28),0x14,0,param_1[1]
                );
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


