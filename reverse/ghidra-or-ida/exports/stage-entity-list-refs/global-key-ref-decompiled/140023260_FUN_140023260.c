// Function: FUN_140023260 @ 140023260
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140023260(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  ushort uVar24;
  int iVar25;
  undefined4 *puVar26;
  undefined8 *puVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  undefined4 uVar33;
  undefined8 uVar34;
  ushort uVar35;
  uint uVar36;
  undefined8 uVar37;
  short sVar38;
  int *piVar39;
  ushort uVar40;
  short *psVar41;
  uint uVar42;
  bool bVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  undefined8 uVar49;
  double dVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  undefined4 uVar55;
  undefined4 uVar56;
  int local_res8;
  double local_res10;
  double local_res18;
  undefined4 in_stack_fffffffffffffeb8;
  undefined2 uVar57;
  ulonglong in_stack_fffffffffffffec0;
  uint uVar59;
  ulonglong uVar58;
  undefined1 in_stack_fffffffffffffec8 [16];
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
  undefined1 auVar100 [16];
  undefined1 auVar101 [16];
  undefined1 auVar104 [12];
  undefined1 auVar102 [16];
  undefined1 auVar103 [16];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  
  dVar44 = (double)FUN_1403300b4((double)(DAT_140e4490c - (float)param_1[0xb]),
                                 (double)(DAT_140e44908 - (float)param_1[10]));
  uVar42 = (uint)(dVar44 * DAT_14053aba0);
  dVar45 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]));
  auVar4 = _DAT_14053bb20;
  uVar55 = (undefined4)DAT_14053bb20;
  uVar56 = DAT_14053bb20._4_4_;
  dVar45 = dVar45 * DAT_14053aba0;
  iVar25 = 0;
  iVar32 = 0xff;
  dVar44 = (double)DAT_14053bb20;
  local_res8 = 0xff;
  if ((DAT_140e419bc == 1) && (((int)param_1[7] < 1 || (DAT_140e4430c < 1)))) {
    FUN_1400031d0(param_1);
    auVar60._12_4_ = in_stack_fffffffffffffec8._12_4_;
    auVar60._0_8_ = in_stack_fffffffffffffec8._0_8_;
    auVar60._8_4_ = param_1[0x14];
    in_stack_fffffffffffffec8._8_8_ = auVar60._8_8_;
    in_stack_fffffffffffffec8._0_8_ = DAT_14053a4f0;
    in_stack_fffffffffffffeb8 = param_1[0xb];
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffffffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,
               DAT_14053a4f0,in_stack_fffffffffffffec8._8_8_,1,0);
    if (DAT_140e41af8 == 1) {
      param_1[5] = 10;
      DAT_140e419bc = -1;
    }
    else if (DAT_140e41af8 == 2) {
      param_1[5] = 8;
      DAT_140e419bc = 2;
    }
    else if (DAT_140e41af8 == 3) {
      param_1[5] = 6;
      DAT_140e419bc = 2;
    }
    else {
      if (DAT_140e41af8 == 4) {
        param_1[5] = 4;
      }
      else {
        if (DAT_140e41af8 != 5) goto LAB_14002342f;
        param_1[5] = 2;
      }
      DAT_140e419bc = 2;
      param_1[0x14] = 0xf0;
    }
LAB_14002342f:
    DAT_140e41af8 = DAT_140e41af8 + -1;
    param_1[0x17] = 0;
  }
  dVar50 = DAT_14053a020;
  dVar47 = DAT_140539d28;
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    uVar36 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    uVar28 = (uVar36 >> 0x1e ^ uVar36) * 0x6c078965 + 2;
    uVar28 = (uVar28 >> 0x1e ^ uVar28) * 0x6c078965 + 3;
    uVar36 = uVar36 * 0x800 ^ uVar36;
    uVar28 = (uVar28 >> 0x1e ^ uVar28) * 0x6c078965 + 4;
    uVar29 = DAT_1407c7798 * 0xde + DAT_140e418c8;
    DAT_140e44908 = (float)(((uVar28 >> 0xb ^ uVar36) >> 8 ^ uVar36 ^ uVar28) % 0x12d + 0xd2);
    uVar36 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar36 >> 0x1e ^ uVar36) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar36 = uVar36 * 0x800 ^ uVar36;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar36) >> 8 ^ uVar36 ^ DAT_140e9fd18;
    DAT_140e4490c = (float)(DAT_140e9fd1c % 0x65 + 0x8c);
  }
  sVar38 = (short)(int)dVar45;
  uVar35 = (ushort)uVar42;
  dVar45 = DAT_14053a430;
  local_res18 = dVar44;
  switch(param_1[5]) {
  case 0:
    if (param_1[3] == 0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    dVar45 = DAT_14053a3a0;
    iVar25 = param_1[3];
    if (iVar25 < 0x3c) {
      local_res10 = DAT_140539ef8;
LAB_1400236bf:
      local_res18 = 0.0;
LAB_1400236cb:
      local_res8 = (iVar25 >> 0x1f & 0xffffff01U) + 0xff;
      if ((iVar25 < 0) || (0x3b < iVar25)) {
        if (iVar25 == 0x3c) {
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
          FUN_14018a340(DAT_140e472d8,1,1);
        }
      }
      else {
        dVar46 = (double)FUN_140332d90(((double)iVar25 - 0.0) * DAT_14053a628 * dVar50 * dVar47);
        local_res8 = (int)(dVar46 * DAT_14053a5f8);
      }
    }
    else {
      if (iVar25 < 0xb4) {
        dVar46 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a3a0) * DAT_14053a4d8 * dVar50 *
                                       dVar47);
        local_res10 = dVar46 * DAT_140539f10 + DAT_140539ef8;
        goto LAB_1400236bf;
      }
      local_res10 = dVar44;
      if (iVar25 < 0xdc) goto LAB_1400236bf;
      if (0xef < iVar25) goto LAB_1400236cb;
      local_res18 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a5c0) * DAT_14053a890 * dVar50
                                          * dVar47);
      local_res18 = local_res18 + 0.0;
      local_res8 = (iVar25 >> 0x1f & 0xffffff01U) + 0xff;
    }
    iVar25 = param_1[3];
    if (iVar25 - 0x3cU < 100) {
      dVar46 = (double)FUN_140332d90();
      fVar52 = DAT_14053ae30 - (float)param_1[0xc];
      fVar54 = (float)param_1[0xc];
      dVar48 = (double)FUN_140332d90();
      param_1[0xb] = (float)(dVar48 * (double)(DAT_14053ade0 - (float)param_1[0xd])) +
                     (float)param_1[0xd];
      dVar45 = (double)FUN_140332d90(((double)iVar25 - dVar45) * DAT_14053a670 * dVar50 * dVar47);
      dVar50 = (double)((float)(dVar45 * DAT_14053a510) + 0.0);
      dVar45 = (double)FUN_1403307c0();
      dVar47 = (double)FUN_140332d90();
      param_1[10] = (float)(dVar45 * dVar50) + (float)(dVar46 * (double)fVar52) + fVar54;
      param_1[0xb] = (float)(dVar47 * dVar50) + (float)param_1[0xb];
    }
    if (0x9f < iVar25) {
      param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    }
    uVar37 = _UNK_14053b648;
    uVar49 = _DAT_14053b640;
    fVar54 = DAT_14053acf0;
    dVar50 = DAT_14053a278;
    dVar47 = DAT_14053a218;
    dVar45 = DAT_140539f68;
    psVar41 = (short *)&local_f8;
    iVar32 = 0;
    do {
      local_e8 = 0;
      local_f8 = uVar49;
      uStack_f0 = uVar37;
      iVar31 = (iVar32 + 0xf) * 10;
      if (iVar25 == iVar31) {
        if (iVar32 == 0) {
          uVar34 = 0x6a;
        }
        else if (iVar32 == 1) {
          uVar34 = 0x69;
        }
        else if (iVar32 == 2) {
          uVar34 = 0x68;
        }
        else if (iVar32 == 3) {
          uVar34 = 0x67;
        }
        else {
          if (iVar32 != 4) goto LAB_1400239f8;
          uVar34 = 0x66;
        }
        auVar61._12_4_ = in_stack_fffffffffffffec8._12_4_;
        auVar61._0_8_ = in_stack_fffffffffffffec8._0_8_;
        auVar61._8_4_ = 0x3c;
        in_stack_fffffffffffffec8._8_8_ = auVar61._8_8_;
        in_stack_fffffffffffffec8._0_8_ = dVar44;
        in_stack_fffffffffffffec0 =
             CONCAT62((int6)(in_stack_fffffffffffffec0 >> 0x10),*psVar41 * 0x3333 + 0x4000);
        stage_entity_spawn_candidate
                  (uVar34,99999999,0x42,fVar54,0,in_stack_fffffffffffffec0,dVar44,
                   in_stack_fffffffffffffec8._8_8_,1,param_1[1]);
      }
LAB_1400239f8:
      iVar25 = param_1[3];
      if ((iVar31 + 0x14 <= iVar25) && (iVar25 <= iVar31 + 0x1e)) {
        dVar46 = dVar47 - ((double)iVar25 - ((double)iVar31 + dVar50)) * dVar45;
        dVar48 = (double)FUN_1403307c0();
        param_1[10] = (float)(dVar48 * dVar46) + (float)param_1[10];
        dVar48 = (double)FUN_140332d90();
        param_1[0xb] = (float)(dVar48 * dVar46) + (float)param_1[0xb];
      }
      iVar32 = iVar32 + 1;
      psVar41 = psVar41 + 2;
    } while (iVar32 < 5);
    if (iVar25 == 0xdc) {
      auVar62._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar62._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar62._8_4_ = 0x28;
      auVar63._8_8_ = auVar62._8_8_;
      auVar63._0_8_ = dVar44;
      uVar58 = CONCAT62((int6)(in_stack_fffffffffffffec0 >> 0x10),0x8000);
      stage_entity_spawn_candidate(100,99999999,0,fVar54,0,uVar58,dVar44,auVar63._8_8_,1,param_1[1])
      ;
      auVar64._12_4_ = auVar63._12_4_;
      auVar64._0_8_ = auVar63._0_8_;
      auVar64._8_4_ = 0x28;
      stage_entity_spawn_candidate
                (0x65,99999999,0,fVar54,0,uVar58 & 0xffffffffffff0000,dVar44,auVar64._8_8_,1,
                 param_1[1]);
    }
    dVar45 = DAT_14053a430;
    uVar55 = SUB84(local_res10,0);
    uVar56 = (undefined4)((ulonglong)local_res10 >> 0x20);
    if (param_1[3] == 0xf0) {
      param_1[5] = param_1[5] + 1;
      DAT_140e4430c = 0xe10;
      param_1[3] = 0;
      param_1[0x17] = 5;
      DAT_140e41b0c = 100000;
      DAT_140e4192c = 0;
      param_1[7] = 100000;
      DAT_140e419bc = 1;
    }
    goto LAB_140023d82;
  case 1:
    uVar24 = *(ushort *)(param_1 + 0x10);
    iVar32 = (uVar42 & 0xffff) - (uint)uVar24;
    iVar25 = iVar32 + 0x10000;
    if (-0x8001 < iVar32) {
      iVar25 = iVar32;
    }
    iVar32 = iVar25 + -0x10000;
    if (iVar25 < 0x8001) {
      iVar32 = iVar25;
    }
    if (iVar32 < 1) {
      uVar40 = uVar24;
      if ((iVar32 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar32)) {
        uVar40 = uVar35;
      }
    }
    else {
      uVar40 = uVar35;
      if (0x1ff < iVar32) {
        uVar40 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar40;
    dVar44 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar44 = (double)FUN_140332d90();
    iVar25 = param_1[3];
    param_1[0xb] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if ((int)param_1[0x17] < 2) {
      iVar32 = iVar25 % 0x28;
      if (0x1b < iVar32) {
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + 0x5b;
      }
      iVar31 = (iVar25 / 0xa0) * 0xa0;
    }
    else {
      iVar32 = iVar25 % 0x3c;
      if (0x2f < iVar32) {
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + 0x5b;
      }
      iVar31 = (iVar25 / 0xf0) * 0xf0;
    }
    if (iVar25 == iVar31) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + 1;
    }
    if (iVar32 == 0) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472ec);
      FUN_14018a340(DAT_140e472ec,1,1);
    }
    dVar44 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a698 * dVar50 * dVar47
                                  );
    dVar45 = DAT_14053a430;
    *(short *)(param_1 + 0x11) = (short)(int)(dVar44 * _DAT_14053a9e8);
  default:
switchD_1400235fd_default:
    local_res8 = 0xff;
    goto LAB_140023d82;
  case 2:
    iVar25 = param_1[3];
    iVar32 = 0;
    if (iVar25 < 0x5a) {
LAB_1400240e9:
      iVar31 = 0;
      if (iVar25 < 0xb4) {
        iVar31 = iVar32;
      }
      puVar27 = DAT_140e45d28;
      if (iVar25 == 1) {
        uVar33 = param_1[0xb];
        uVar2 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar27 = (undefined8 *)_malloc_base();
          if (puVar27 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar27 + 0x14) = uVar2;
          *(undefined4 *)(puVar27 + 3) = uVar33;
          *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar2;
          *(undefined4 *)(puVar27 + 4) = uVar33;
          *puVar27 = 1;
          puVar27[1] = 0x36;
          *(undefined4 *)(puVar27 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
          puVar27[5] = 0;
          puVar27[6] = 0x3ff0000000000000;
          puVar27[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar27 + 8) = 0;
          *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
          *(undefined4 *)(puVar27 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
          puVar27[10] = 0xff;
          puVar27[0xb] = 0;
          if (bVar43) {
            DAT_140e45d78 = puVar27;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar27;
          }
        }
      }
    }
    else {
      iVar32 = 0xff;
      if (iVar25 < 100) {
        dVar45 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a430) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar27 = DAT_140e45d28;
        iVar31 = (int)(dVar45 * DAT_14053a5f8);
      }
      else {
        if (0xb3 < iVar25) goto LAB_1400240e9;
        dVar45 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a278) * DAT_14053a5a0 *
                                       DAT_14053a020 * DAT_140539d28);
        puVar27 = DAT_140e45d28;
        iVar31 = 0;
        if (iVar25 < 0xb4) {
          iVar31 = (int)(dVar45 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar27;
    iVar25 = param_1[3];
    if (iVar25 < 0x5a) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + -0x682;
      *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x682;
      param_1[0xb] = (float)iVar25 * DAT_140539cc8 + (float)param_1[0xb];
      FUN_14007ac00();
    }
    puVar27 = DAT_140e45d28;
    if (param_1[3] == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar33 = param_1[0xb];
      uVar2 = param_1[10];
      puVar27 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar27 = (undefined8 *)_malloc_base();
        if (puVar27 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar27 + 0x14) = uVar2;
        *(undefined4 *)(puVar27 + 3) = uVar33;
        *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar2;
        *(undefined4 *)(puVar27 + 4) = uVar33;
        *puVar27 = 1;
        puVar27[1] = 0x11;
        *(undefined4 *)(puVar27 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
        puVar27[5] = 0;
        puVar27[6] = 0x3ff0000000000000;
        puVar27[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar27 + 8) = 0;
        *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
        *(undefined4 *)(puVar27 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
        puVar27[10] = 0xff;
        puVar27[0xb] = 0;
        if (bVar43) {
          DAT_140e45d78 = puVar27;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar27;
        }
      }
    }
    DAT_140e45d28 = puVar27;
    iVar25 = param_1[3];
    if (iVar25 == 100) {
      *(undefined2 *)((longlong)param_1 + 0x42) = 0;
      *(undefined8 *)(param_1 + 0x12) = 0x3ff999999999999a;
LAB_140024333:
      uVar24 = *(ushort *)(param_1 + 0x10);
      iVar30 = (uVar42 & 0xffff) - (uint)uVar24;
      iVar32 = iVar30 + 0x10000;
      if (-0x8001 < iVar30) {
        iVar32 = iVar30;
      }
      iVar30 = iVar32 + -0x10000;
      if (iVar32 < 0x8001) {
        iVar30 = iVar32;
      }
      if (iVar30 < 1) {
        uVar40 = uVar24;
        if ((iVar30 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar30)) {
          uVar40 = uVar35;
        }
      }
      else {
        uVar40 = uVar35;
        if (0x1ff < iVar30) {
          uVar40 = uVar24 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar40;
      dVar45 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar48 = (double)FUN_140332d90();
      dVar45 = *(double *)(param_1 + 0x12);
      fVar54 = (float)param_1[0xb];
      dVar46 = dVar44;
      if ((99 < iVar25) && (dVar46 = 0.0, iVar25 < 0xf0)) {
        dVar47 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a460) * _DAT_14053a490 * dVar50 *
                                       dVar47);
        dVar46 = dVar47 * DAT_14053b0a0 + dVar44;
      }
      param_1[0xb] = ((float)(dVar48 * dVar45) + fVar54) - (float)dVar46;
    }
    else if (99 < iVar25) goto LAB_140024333;
    if (0x95 < iVar25) {
      uVar35 = *(ushort *)(param_1 + 0x11);
      uVar24 = (sVar38 - uVar35) + 0xc000;
      uVar42 = (uint)uVar24;
      if (0x8000 < uVar24) {
        uVar42 = 0x10000 - uVar24;
      }
      uVar24 = sVar38 + 0xc000;
      iVar32 = (uint)uVar24 - (uint)uVar35;
      iVar30 = (int)uVar42 / 0x14 + 0x30;
      iVar25 = iVar32 + 0x10000;
      if (-0x8001 < iVar32) {
        iVar25 = iVar32;
      }
      iVar32 = iVar25 + -0x10000;
      if (iVar25 < 0x8001) {
        iVar32 = iVar25;
      }
      if (iVar32 < 1) {
        uVar40 = uVar35;
        if ((iVar32 < 0) && (uVar40 = uVar35 - (short)iVar30, -iVar30 < iVar32)) {
          uVar40 = uVar24;
        }
      }
      else {
        uVar40 = uVar24;
        if (iVar30 <= iVar32) {
          uVar40 = uVar35 + (short)iVar30;
        }
      }
      *(ushort *)(param_1 + 0x11) = uVar40;
    }
    uVar33 = DAT_140e41ab8;
    puVar26 = (undefined4 *)_malloc_base(0x48);
    if (puVar26 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar43 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar26 = uVar33;
    puVar26[1] = 0x4e;
    *(undefined8 *)(puVar26 + 2) = 5;
    puVar26[4] = 0;
    *(undefined2 *)(puVar26 + 5) = 0;
    *(undefined8 *)(puVar26 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar26 + 8) = 0x3ff0000000000000;
    puVar26[10] = 0xff;
    puVar26[0xb] = 0xff;
    puVar26[0xc] = 0xff;
    puVar26[0xd] = iVar31;
    *(undefined8 *)(puVar26 + 0xe) = 1;
    *(undefined8 *)(puVar26 + 0x10) = 0;
    if (bVar43) {
      DAT_140e46bf0 = puVar26;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar26;
    }
    DAT_140e46c88 = puVar26;
    if (param_1[3] == 0xb4) {
      *(undefined8 *)(param_1 + 0x14) = 0xaf;
      param_1[3] = 0;
      if (param_1[5] == 2) {
        DAT_140e4430c = 0x834;
        DAT_140e41b0c = 86000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
    }
    break;
  case 3:
    uVar24 = *(ushort *)(param_1 + 0x10);
    iVar32 = (uVar42 & 0xffff) - (uint)uVar24;
    iVar25 = iVar32 + 0x10000;
    if (-0x8001 < iVar32) {
      iVar25 = iVar32;
    }
    iVar32 = iVar25 + -0x10000;
    if (iVar25 < 0x8001) {
      iVar32 = iVar25;
    }
    if (iVar32 < 1) {
      uVar40 = uVar24;
      if ((iVar32 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar32)) {
        uVar40 = uVar35;
      }
    }
    else {
      uVar40 = uVar35;
      if (0x1ff < iVar32) {
        uVar40 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar40;
    dVar45 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar45 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if (param_1[3] == 0x1e) {
      auVar68._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar68._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar68._8_4_ = 0x28;
      stage_entity_spawn_candidate
                (0x6b,99999999,0,DAT_14053ad10,0,0x4000,dVar44,auVar68._8_8_,1,param_1[1]);
    }
    iVar25 = param_1[3];
    uVar35 = *(ushort *)((longlong)param_1 + 0x42);
    uVar42 = ((iVar25 % 0x708) / 0x1e & 0xffffU) * 0x444;
    uVar24 = (ushort)uVar42;
    iVar31 = (uVar42 & 0xffff) - (uint)uVar35;
    iVar32 = iVar31 + 0x10000;
    if (-0x8001 < iVar31) {
      iVar32 = iVar31;
    }
    iVar31 = iVar32 + -0x10000;
    if (iVar32 < 0x8001) {
      iVar31 = iVar32;
    }
    if (iVar31 < 1) {
      uVar40 = uVar35;
      if ((iVar31 < 0) && (uVar40 = uVar35 - 0xb6, -0xb6 < iVar31)) {
        uVar40 = uVar24;
      }
    }
    else {
      uVar40 = uVar24;
      if (0xb5 < iVar31) {
        uVar40 = uVar35 + 0xb6;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar40;
    if (iVar25 == (iVar25 / 0x1e) * 0x1e) {
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472ec);
      FUN_14018a340(DAT_140e472ec,1,1);
    }
    dVar45 = DAT_14053a430;
    uVar35 = *(ushort *)(param_1 + 0x11);
    uVar24 = (sVar38 - uVar35) + 0xc000;
    uVar42 = (uint)uVar24;
    if (0x8000 < uVar24) {
      uVar42 = 0x10000 - uVar24;
    }
    uVar24 = sVar38 + 0xc000;
    iVar32 = (uint)uVar24 - (uint)uVar35;
    iVar31 = (int)uVar42 / 0x14 + 0x30;
    iVar25 = iVar32 + 0x10000;
    if (-0x8001 < iVar32) {
      iVar25 = iVar32;
    }
    iVar32 = iVar25 + -0x10000;
    if (iVar25 < 0x8001) {
      iVar32 = iVar25;
    }
    if (iVar32 < 1) {
      uVar40 = uVar35;
      if ((iVar32 < 0) && (uVar40 = uVar35 - (short)iVar31, -iVar31 < iVar32)) {
        uVar40 = uVar24;
      }
    }
    else {
      uVar40 = uVar24;
      if (iVar31 <= iVar32) {
        uVar40 = uVar35 + (short)iVar31;
      }
    }
    *(ushort *)(param_1 + 0x11) = uVar40;
    goto switchD_1400235fd_default;
  case 4:
    iVar25 = param_1[3];
    iVar32 = 0;
    if (iVar25 < 0x78) {
LAB_140024919:
      iVar31 = 0;
      if (iVar25 < 0xdc) {
        iVar31 = iVar32;
      }
      puVar27 = DAT_140e45d28;
      if (iVar25 == 1) {
        uVar33 = param_1[0xb];
        uVar2 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar27 = (undefined8 *)_malloc_base(0x60);
          if (puVar27 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar27 + 0x14) = uVar2;
          *(undefined4 *)(puVar27 + 3) = uVar33;
          *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar2;
          *(undefined4 *)(puVar27 + 4) = uVar33;
          *puVar27 = 1;
          puVar27[1] = 0x36;
          *(undefined4 *)(puVar27 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
          puVar27[5] = 0;
          puVar27[6] = 0x3ff0000000000000;
          puVar27[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar27 + 8) = 0;
          *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
          *(undefined4 *)(puVar27 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
          puVar27[10] = 0xff;
          puVar27[0xb] = 0;
          if (bVar43) {
            DAT_140e45d78 = puVar27;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar27;
          }
        }
      }
    }
    else {
      iVar32 = 0xff;
      if (iVar25 < 0x82) {
        dVar44 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a4a0) * DAT_14053a9d8 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar31 = (int)(dVar44 * DAT_14053a5f8);
        puVar27 = DAT_140e45d28;
      }
      else {
        if (0xdb < iVar25) goto LAB_140024919;
        dVar44 = (double)FUN_140332d90(((double)iVar25 - DAT_14053a340) * DAT_14053a558 *
                                       DAT_14053a020 * DAT_140539d28);
        iVar31 = 0;
        puVar27 = DAT_140e45d28;
        if (iVar25 < 0xdc) {
          iVar31 = (int)(dVar44 * DAT_14053a5f8);
        }
      }
    }
    DAT_140e45d28 = puVar27;
    uVar33 = (undefined4)(in_stack_fffffffffffffec0 >> 0x20);
    iVar25 = param_1[3];
    if (iVar25 < 0x78) {
      FUN_14007ac00(param_1);
      iVar25 = param_1[3];
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + -0x682;
      *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + 0x682;
      param_1[0xb] = (float)iVar25 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar27 = DAT_140e45d28;
    if (iVar25 == 0x78) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar2 = param_1[0xb];
      uVar1 = param_1[10];
      puVar27 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar27 = (undefined8 *)_malloc_base(0x60);
        if (puVar27 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar27 + 0x14) = uVar1;
        *(undefined4 *)(puVar27 + 3) = uVar2;
        *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar1;
        *(undefined4 *)(puVar27 + 4) = uVar2;
        *puVar27 = 1;
        puVar27[1] = 0x11;
        *(undefined4 *)(puVar27 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
        puVar27[5] = 0;
        puVar27[6] = 0x3ff0000000000000;
        puVar27[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar27 + 8) = 0;
        *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
        *(undefined4 *)(puVar27 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
        puVar27[10] = 0xff;
        puVar27[0xb] = 0;
        if (bVar43) {
          DAT_140e45d78 = puVar27;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar27;
        }
      }
    }
    DAT_140e45d28 = puVar27;
    iVar25 = param_1[3];
    if (0xdb < iVar25) {
      FUN_140001900(iVar25,0xdc,5);
    }
    iVar25 = param_1[3];
    if (iVar25 == 0x82) {
      fVar54 = (float)param_1[0xb] - DAT_14053acf0;
      *(undefined8 *)(param_1 + 0x12) = 0x3fe3333333333333;
      param_1[0xb] = fVar54;
LAB_140024b78:
      uVar24 = *(ushort *)(param_1 + 0x10);
      iVar30 = (uVar42 & 0xffff) - (uint)uVar24;
      iVar32 = iVar30 + 0x10000;
      if (-0x8001 < iVar30) {
        iVar32 = iVar30;
      }
      iVar30 = iVar32 + -0x10000;
      if (iVar32 < 0x8001) {
        iVar30 = iVar32;
      }
      if (iVar30 < 1) {
        uVar40 = uVar24;
        if ((iVar30 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar30)) {
          uVar40 = uVar35;
        }
      }
      else {
        uVar40 = uVar35;
        if (0x1ff < iVar30) {
          uVar40 = uVar24 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar40;
      dVar44 = (double)FUN_1403307c0();
      param_1[10] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      dVar44 = (double)FUN_140332d90();
      auVar69._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar69._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar69._8_4_ = 0x47;
      auVar70._4_12_ = auVar69._4_12_;
      auVar70._0_4_ = 0x48;
      uVar58 = CONCAT44(uVar33,0x47);
      param_1[0xb] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      iVar25 = FUN_1400c9580(iVar25,0,6,4,0x46,uVar58,auVar70);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar25 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar58 & 0xffffffffffff0000,auVar4,0xff,0xff,0xff,0xff,1,0);
    }
    else if (0x81 < iVar25) goto LAB_140024b78;
    uVar33 = DAT_140e41ab8;
    puVar26 = (undefined4 *)_malloc_base(0x48);
    if (puVar26 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    puVar26[0xd] = iVar31;
    bVar43 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar26 = uVar33;
    puVar26[1] = 0x4e;
    *(undefined8 *)(puVar26 + 2) = 5;
    puVar26[4] = 0;
    *(undefined2 *)(puVar26 + 5) = 0;
    *(undefined8 *)(puVar26 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar26 + 8) = 0x3ff0000000000000;
    puVar26[10] = 0xff;
    puVar26[0xb] = 0xff;
    puVar26[0xc] = 0xff;
    *(undefined8 *)(puVar26 + 0xe) = 1;
    *(undefined8 *)(puVar26 + 0x10) = 0;
    if (bVar43) {
      DAT_140e46bf0 = puVar26;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar26;
    }
    DAT_140e46c88 = puVar26;
    if (param_1[3] == 0x17c) {
      *(undefined8 *)(param_1 + 0x14) = 0x50;
      param_1[3] = 0;
      dVar45 = DAT_14053a430;
      if (param_1[5] == 4) {
        DAT_140e4430c = 0x708;
        DAT_140e41b0c = 68000;
        DAT_140e4192c = 0;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = param_1[5] + 1;
      DAT_140e419bc = 1;
    }
    else {
      local_res8 = 0xff;
      dVar45 = DAT_14053a430;
    }
    goto LAB_140023d82;
  case 5:
    uVar24 = *(ushort *)(param_1 + 0x10);
    iVar32 = (uVar42 & 0xffff) - (uint)uVar24;
    iVar25 = iVar32 + 0x10000;
    if (-0x8001 < iVar32) {
      iVar25 = iVar32;
    }
    iVar32 = iVar25 + -0x10000;
    if (iVar25 < 0x8001) {
      iVar32 = iVar25;
    }
    if (iVar32 < 1) {
      uVar40 = uVar24;
      if ((iVar32 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar32)) {
        uVar40 = uVar35;
      }
    }
    else {
      uVar40 = uVar35;
      if (0x1ff < iVar32) {
        uVar40 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar40;
    dVar45 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar45 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    uVar33 = DAT_14053b390;
    if (param_1[3] == 10) {
      DAT_1407c77a0 = DAT_1407c779c;
      auVar71._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar71._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar71._8_4_ = 0x28;
      auVar72._8_8_ = auVar71._8_8_;
      auVar72._0_8_ = dVar44;
      uVar49 = CONCAT62((int6)(in_stack_fffffffffffffec0 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x6e,99999999,0,DAT_14053ad1c,DAT_14053b390,uVar49,dVar44,auVar72._8_8_,1,
                 param_1[1]);
      auVar73._12_4_ = auVar72._12_4_;
      auVar73._0_8_ = auVar72._0_8_;
      auVar73._8_4_ = 0x28;
      auVar74._8_8_ = auVar73._8_8_;
      auVar74._0_8_ = dVar44;
      uVar49 = CONCAT62((int6)((ulonglong)uVar49 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x6e,99999999,0,DAT_14053b380,uVar33,uVar49,dVar44,auVar74._8_8_,1,param_1[1]);
      uVar33 = DAT_14053b36c;
      auVar75._12_4_ = auVar74._12_4_;
      auVar75._0_8_ = auVar74._0_8_;
      auVar75._8_4_ = 0x28;
      auVar76._8_8_ = auVar75._8_8_;
      auVar76._0_8_ = dVar44;
      uVar49 = CONCAT62((int6)((ulonglong)uVar49 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x6e,99999999,0,DAT_14053adbc,DAT_14053b36c,uVar49,dVar44,auVar76._8_8_,1,
                 param_1[1]);
      auVar77._12_4_ = auVar76._12_4_;
      auVar77._0_8_ = auVar76._0_8_;
      auVar77._8_4_ = 0x28;
      in_stack_fffffffffffffec8._8_8_ = auVar77._8_8_;
      in_stack_fffffffffffffec8._0_8_ = dVar44;
      in_stack_fffffffffffffec0 = CONCAT62((int6)((ulonglong)uVar49 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x6e,99999999,0,DAT_14053b3d8,uVar33,in_stack_fffffffffffffec0,dVar44,
                 in_stack_fffffffffffffec8._8_8_,1,param_1[1]);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    if ((int)param_1[3] < 10) {
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4a);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],0,5,2,0x49,in_stack_fffffffffffffec0);
    }
    else {
      local_res10._0_4_ = 0x46;
    }
    if (param_1[3] - 10 < 0x28) {
      in_stack_fffffffffffffec8._0_4_ = 0x4d;
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4c);
      local_res10._0_4_ =
           FUN_1400c9580(param_1[3],10,5,3,0x4b,in_stack_fffffffffffffec0,in_stack_fffffffffffffec8)
      ;
    }
    iVar25 = param_1[3];
    if (iVar25 - 0x32U < 10) {
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x49);
      local_res10._0_4_ = FUN_1400c9580(iVar25,0x32,5,2,0x4a,in_stack_fffffffffffffec0);
    }
    iVar25 = param_1[3];
    if (0x3b < iVar25) {
      auVar78._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar78._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar78._8_4_ = 0x47;
      auVar79._4_12_ = auVar78._4_12_;
      auVar79._0_4_ = 0x48;
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x47);
      local_res10._0_4_ = FUN_1400c9580(iVar25,0x3c,6,4,0x46,in_stack_fffffffffffffec0,auVar79);
    }
    goto LAB_1400250d1;
  case 6:
  case 8:
    iVar25 = param_1[3];
    dVar45 = (double)FUN_140332d90(((double)iVar25 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar33 = (undefined4)(in_stack_fffffffffffffec0 >> 0x20);
    dVar44 = dVar45 * _DAT_14053b070 + dVar44;
    puVar27 = DAT_140e45d28;
    if (iVar25 == 1) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47298);
      FUN_14018a340(DAT_140e47298,1,1);
      uVar2 = param_1[0xb];
      uVar1 = param_1[10];
      puVar27 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar27 = (undefined8 *)_malloc_base(0x60);
        if (puVar27 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar27 + 0x14) = uVar1;
        *(undefined4 *)(puVar27 + 3) = uVar2;
        *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar1;
        *(undefined4 *)(puVar27 + 4) = uVar2;
        *puVar27 = 1;
        puVar27[1] = 0x36;
        *(undefined4 *)(puVar27 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
        puVar27[5] = 0;
        puVar27[6] = 0x3ff0000000000000;
        puVar27[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar27 + 8) = 0;
        *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
        *(undefined4 *)(puVar27 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
        puVar27[10] = 0xff;
        puVar27[0xb] = 0;
        if (bVar43) {
          DAT_140e45d78 = puVar27;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar27;
        }
      }
    }
    DAT_140e45d28 = puVar27;
    piVar39 = param_1 + 3;
    if (*piVar39 < 0x5a) {
      FUN_14007ac00(param_1);
    }
    uVar58 = CONCAT44(uVar33,0x4f);
    param_1[0xb] = (float)param_1[0xb] + DAT_140539ce4;
    iVar25 = FUN_1400c9580(*piVar39,0,5,2,0x4e,uVar58);
    auVar4._8_4_ = SUB84(dVar44,0);
    auVar4._0_8_ = dVar44;
    auVar4._12_4_ = (int)((ulonglong)dVar44 >> 0x20);
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar25 * 4),0x1e,7,param_1[10],
                  param_1[0xb],uVar58 & 0xffffffffffff0000,auVar4,0xff,0xff,0xff,0xff,1,0);
    if (*piVar39 == 0xb4) {
      iVar25 = param_1[5];
      param_1[0x15] = 0;
      *piVar39 = 0;
      dVar45 = DAT_14053a430;
      if (iVar25 == 6) {
        DAT_140e41b0c = 70000;
LAB_140026673:
        DAT_140e4430c = 0x834;
        DAT_140e4192c = 0;
      }
      else if (iVar25 == 8) {
        DAT_140e41b0c = 80000;
        goto LAB_140026673;
      }
      param_1[7] = DAT_140e41b0c;
      param_1[5] = iVar25 + 1;
      DAT_140e419bc = 1;
      local_res8 = iVar32;
      goto LAB_140023d82;
    }
    break;
  case 7:
    uVar24 = *(ushort *)(param_1 + 0x10);
    iVar31 = (uVar42 & 0xffff) - (uint)uVar24;
    iVar32 = iVar31 + 0x10000;
    if (-0x8001 < iVar31) {
      iVar32 = iVar31;
    }
    iVar31 = iVar32 + -0x10000;
    if (iVar32 < 0x8001) {
      iVar31 = iVar32;
    }
    if (iVar31 < 1) {
      uVar40 = uVar24;
      if ((iVar31 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar31)) {
        uVar40 = uVar35;
      }
    }
    else {
      uVar40 = uVar35;
      if (0x1ff < iVar31) {
        uVar40 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar40;
    dVar45 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar45 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar45 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    if ((int)param_1[3] < 0x78) {
      uVar58 = 1;
      if (DAT_140e419b8 == 0) {
        uVar58 = 0x11;
      }
      else if (DAT_140e419b8 == 1) {
        uVar58 = 0x15;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar58 = 0x19;
      }
      else if (DAT_140e419b8 == 4) {
        uVar58 = 0x1b;
      }
      iVar32 = 10;
      do {
        if (param_1[3] == iVar32) {
          auVar80._12_4_ = in_stack_fffffffffffffec8._12_4_;
          auVar80._0_8_ = in_stack_fffffffffffffec8._0_8_;
          auVar80._8_4_ = 0x28;
          in_stack_fffffffffffffec8._8_8_ = auVar80._8_8_;
          in_stack_fffffffffffffec8._0_8_ = dVar44;
          in_stack_fffffffffffffec0 =
               CONCAT62((int6)(in_stack_fffffffffffffec0 >> 0x10),
                        (short)(0x10000 / uVar58) * (short)iVar25 + -0x4000);
          stage_entity_spawn_candidate
                    (0x6f,99999999,0,0,0,in_stack_fffffffffffffec0,dVar44,
                     in_stack_fffffffffffffec8._8_8_,1,param_1[1]);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8);
        }
        iVar25 = iVar25 + 1;
        iVar32 = iVar32 + (int)(100 / uVar58);
      } while (iVar25 < (int)uVar58);
    }
    if ((int)param_1[3] < 10) {
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4a);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],0,5,2,0x49,in_stack_fffffffffffffec0);
    }
    else {
      local_res10._0_4_ = 0x46;
    }
    if (param_1[3] - 10 < 100) {
      in_stack_fffffffffffffec8._0_4_ = 0x4d;
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4c);
      local_res10._0_4_ =
           FUN_1400c9580(param_1[3],10,5,3,0x4b,in_stack_fffffffffffffec0,in_stack_fffffffffffffec8)
      ;
    }
    if (param_1[3] - 0x6e < 10) {
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x49);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],0x6e,5,2,0x4a,in_stack_fffffffffffffec0);
    }
    if (0x77 < (int)param_1[3]) {
      auVar81._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar81._0_8_ = in_stack_fffffffffffffec8._0_8_;
      auVar81._8_4_ = 0x47;
      auVar82._4_12_ = auVar81._4_12_;
      auVar82._0_4_ = 0x48;
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x47);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],0x78,6,4,0x46,in_stack_fffffffffffffec0,auVar82);
    }
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10._0_4_ * 4),0x1e,7,
                  param_1[10],param_1[0xb],in_stack_fffffffffffffec0 & 0xffffffffffff0000,auVar4,
                  0xff,0xff,0xff,0xff,1,0);
    break;
  case 9:
    uVar24 = *(ushort *)(param_1 + 0x10);
    iVar32 = (uVar42 & 0xffff) - (uint)uVar24;
    iVar25 = iVar32 + 0x10000;
    if (-0x8001 < iVar32) {
      iVar25 = iVar32;
    }
    iVar32 = iVar25 + -0x10000;
    if (iVar25 < 0x8001) {
      iVar32 = iVar25;
    }
    if (iVar32 < 1) {
      uVar40 = uVar24;
      if ((iVar32 < 0) && (uVar40 = uVar24 - 0x200, -0x200 < iVar32)) {
        uVar40 = uVar35;
      }
    }
    else {
      uVar40 = uVar35;
      if (0x1ff < iVar32) {
        uVar40 = uVar24 + 0x200;
      }
    }
    *(ushort *)(param_1 + 0x10) = uVar40;
    dVar44 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar44 = (double)FUN_140332d90();
    param_1[0xb] = (float)(dVar44 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    puVar27 = DAT_140e45d28;
    if ((param_1[3] == 1) && (uVar33 = param_1[1], DAT_140e45d1c < 0x1000)) {
      puVar27 = (undefined8 *)_malloc_base(0x60);
      if (puVar27 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar27 = 1;
      puVar27[1] = 0x2d;
      puVar27[2] = 0x28;
      puVar27[3] = 0;
      *(undefined4 *)(puVar27 + 4) = 0;
      *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
      puVar27[5] = 0x3ff0000000000000;
      puVar27[6] = 0x3ff0000000000000;
      puVar27[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar27 + 8) = 0x3c;
      *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
      *(undefined4 *)(puVar27 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
      *(undefined4 *)(puVar27 + 10) = 0xff;
      *(undefined4 *)((longlong)puVar27 + 0x54) = uVar33;
      puVar27[0xb] = 0;
      if (bVar43) {
        DAT_140e45d78 = puVar27;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar27;
      }
    }
    DAT_140e45d28 = puVar27;
    fVar52 = DAT_14053ad00;
    fVar54 = DAT_14053ac98;
    iVar25 = 0;
    uVar42 = 1;
    if (DAT_140e419b8 == 0) {
      uVar42 = 0x78;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      uVar42 = 100;
    }
    uVar36 = 1;
    if (DAT_140e419b8 == 0) {
      uVar36 = 0xf;
    }
    else if (DAT_140e419b8 == 1) {
      uVar36 = 0x13;
    }
    else if (DAT_140e419b8 == 2) {
      uVar36 = 0x15;
    }
    else if (DAT_140e419b8 == 3) {
      uVar36 = 0xc;
    }
    else if (DAT_140e419b8 == 4) {
      uVar36 = 9;
    }
    uVar28 = param_1[3];
    if ((int)((uVar42 + 0xc) * 5) <= (int)uVar28) {
      uVar42 = uVar42 >> 1;
    }
    if ((0x3b < (int)uVar28) && ((int)(uVar28 - 0x3c) % (int)uVar42 == 0)) {
      uVar29 = (uVar42 + 0xc) * 5;
      auVar84._12_4_ = in_stack_fffffffffffffec8._12_4_;
      auVar84._0_8_ = in_stack_fffffffffffffec8._0_8_;
      uVar59 = (uint)(in_stack_fffffffffffffec0 >> 0x20);
      uVar57 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
      if ((((int)uVar28 < (int)uVar29) &&
          (iVar32 = uVar28 - 0x3c, uVar28 = param_1[3], iVar32 % (int)(uVar42 * 2) == 0)) ||
         ((uVar29 <= uVar28 &&
          (uVar29 = (uVar28 ^ uVar28 >> 0x1e) * 0x6c078965 + 1,
          uVar42 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 2,
          uVar42 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 3,
          uVar42 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 4,
          (((uVar42 >> 0xb ^ uVar29) >> 8 ^ uVar29 ^ uVar42) & 1) == 0)))) {
        fVar51 = (float)param_1[0xb] - DAT_14053ad00;
        fVar53 = (float)param_1[10] - DAT_14053ac98;
        uVar42 = (uVar28 >> 0x1e ^ uVar28) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar42 = uVar42 * 0x800 ^ uVar42;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
        sVar38 = (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001);
        if (uVar36 == 1) {
          auVar84._8_4_ = 1;
          auVar6._8_8_ = 0;
          auVar6._0_8_ = auVar84._8_8_;
          in_stack_fffffffffffffec8 = auVar6 << 0x40;
          in_stack_fffffffffffffec0 = (ulonglong)uVar59 << 0x20;
          in_stack_fffffffffffffeb8 = CONCAT22(uVar57,sVar38);
          FUN_14006c2f0(2,0x1f,fVar53,fVar51,in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,0,
                        auVar84._8_8_,0);
        }
        else {
          iVar32 = iVar25;
          do {
            auVar83._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar83._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar83._8_4_ = 1;
            auVar5._8_8_ = 0;
            auVar5._0_8_ = auVar83._8_8_;
            in_stack_fffffffffffffec8 = auVar5 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                          (short)iVar32 * (short)(0x10000 / uVar36) + sVar38);
            FUN_14006c2f0(2,0x1f,fVar53,fVar51,in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,0
                          ,auVar83._8_8_,0);
            iVar32 = iVar32 + 1;
          } while (iVar32 < (int)uVar36);
        }
        if (2 < DAT_140e419b8) {
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + -0x4b0;
          if (uVar36 == 1) {
            auVar86._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar86._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar86._8_4_ = 1;
            auVar8._8_8_ = 0;
            auVar8._0_8_ = auVar86._8_8_;
            in_stack_fffffffffffffec8 = auVar8 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                          in_stack_fffffffffffffec0,0,auVar86._8_8_,0);
          }
          else {
            do {
              auVar85._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar85._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar85._8_4_ = 1;
              auVar7._8_8_ = 0;
              auVar7._0_8_ = auVar85._8_8_;
              in_stack_fffffffffffffec8 = auVar7 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)iVar25 * (short)(0x10000 / uVar36) + sVar38);
              FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar85._8_8_,0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + -0x960;
          if (uVar36 == 1) {
            auVar88._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar88._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar88._8_4_ = 1;
            auVar10._8_8_ = 0;
            auVar10._0_8_ = auVar88._8_8_;
            in_stack_fffffffffffffec8 = auVar10 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                          in_stack_fffffffffffffec0,0,auVar88._8_8_,0);
          }
          else {
            iVar25 = 0;
            do {
              auVar87._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar87._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar87._8_4_ = 1;
              auVar9._8_8_ = 0;
              auVar9._0_8_ = auVar87._8_8_;
              in_stack_fffffffffffffec8 = auVar9 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)iVar25 * (short)(0x10000 / uVar36) + sVar38);
              FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar87._8_8_,0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
        }
        iVar25 = 0;
        if (3 < DAT_140e419b8) {
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + -0xe10;
          if (uVar36 == 1) {
            auVar90._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar90._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar90._8_4_ = 1;
            auVar12._8_8_ = 0;
            auVar12._0_8_ = auVar90._8_8_;
            in_stack_fffffffffffffec8 = auVar12 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            uVar33 = CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,uVar33,in_stack_fffffffffffffec0,0,
                          auVar90._8_8_,0);
            uVar57 = (undefined2)((uint)uVar33 >> 0x10);
          }
          else {
            do {
              auVar89._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar89._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar89._8_4_ = 1;
              auVar11._8_8_ = 0;
              auVar11._0_8_ = auVar89._8_8_;
              in_stack_fffffffffffffec8 = auVar11 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)iVar25 * (short)(0x10000 / uVar36) + sVar38);
              FUN_14006c2f0(2,0x1f,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar89._8_8_,0);
              uVar57 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
          uVar29 = (uint)(in_stack_fffffffffffffec0 >> 0x20);
          iVar25 = 0;
          fVar52 = (float)param_1[0xb] - fVar52;
          fVar54 = (float)param_1[10] - fVar54;
          uVar28 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          uVar42 = uVar28 * 0x800 ^ uVar28;
          DAT_140e9fd10 = (uVar28 >> 0x1e ^ uVar28) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ DAT_140e9fd18 ^ uVar42;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + -0x12c0;
          if (uVar36 == 1) {
            uVar37 = 0x1f;
            uVar49 = 2;
            goto LAB_140026394;
          }
          do {
            auVar91._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar91._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar91._8_4_ = 1;
            auVar13._8_8_ = 0;
            auVar13._0_8_ = auVar91._8_8_;
            in_stack_fffffffffffffec8 = auVar13 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            FUN_14006c2f0(2,0x1f,fVar54,fVar52,(short)(0x10000 / uVar36) * (short)iVar25 + sVar38,
                          in_stack_fffffffffffffec0,0,auVar91._8_8_,0);
            iVar25 = iVar25 + 1;
          } while (iVar25 < (int)uVar36);
        }
      }
      else {
        fVar51 = (float)param_1[0xb] - DAT_14053ad00;
        fVar53 = (float)param_1[10] - DAT_14053ac98;
        uVar42 = (uVar28 ^ uVar28 >> 0x1e) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar42 = uVar42 * 0x800 ^ uVar42;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
        sVar38 = (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001);
        if (uVar36 == 1) {
          auVar93._8_4_ = 1;
          auVar93._0_8_ = auVar84._0_8_;
          auVar93._12_4_ = auVar84._12_4_;
          auVar15._8_8_ = 0;
          auVar15._0_8_ = auVar93._8_8_;
          in_stack_fffffffffffffec8 = auVar15 << 0x40;
          in_stack_fffffffffffffec0 = (ulonglong)uVar59 << 0x20;
          in_stack_fffffffffffffeb8 = CONCAT22(uVar57,sVar38);
          FUN_14006c2f0(3,0x20,fVar53,fVar51,in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,0,
                        auVar93._8_8_,0);
        }
        else {
          iVar32 = iVar25;
          do {
            auVar92._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar92._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar92._8_4_ = 1;
            auVar14._8_8_ = 0;
            auVar14._0_8_ = auVar92._8_8_;
            in_stack_fffffffffffffec8 = auVar14 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                          (short)iVar32 * (short)(0x10000 / uVar36) + sVar38);
            FUN_14006c2f0(3,0x20,fVar53,fVar51,in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,0
                          ,auVar92._8_8_,0);
            iVar32 = iVar32 + 1;
          } while (iVar32 < (int)uVar36);
        }
        if (2 < DAT_140e419b8) {
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + 0x4b0;
          if (uVar36 == 1) {
            auVar95._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar95._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar95._8_4_ = 1;
            auVar17._8_8_ = 0;
            auVar17._0_8_ = auVar95._8_8_;
            in_stack_fffffffffffffec8 = auVar17 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                          in_stack_fffffffffffffec0,0,auVar95._8_8_,0);
          }
          else {
            do {
              auVar94._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar94._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar94._8_4_ = 1;
              auVar16._8_8_ = 0;
              auVar16._0_8_ = auVar94._8_8_;
              in_stack_fffffffffffffec8 = auVar16 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)(0x10000 / uVar36) * (short)iVar25 + sVar38);
              FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar94._8_8_,0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + 0x960;
          if (uVar36 == 1) {
            auVar97._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar97._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar97._8_4_ = 1;
            auVar19._8_8_ = 0;
            auVar19._0_8_ = auVar97._8_8_;
            in_stack_fffffffffffffec8 = auVar19 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            in_stack_fffffffffffffeb8 =
                 CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                          in_stack_fffffffffffffec0,0,auVar97._8_8_,0);
          }
          else {
            iVar25 = 0;
            do {
              auVar96._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar96._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar96._8_4_ = 1;
              auVar18._8_8_ = 0;
              auVar18._0_8_ = auVar96._8_8_;
              in_stack_fffffffffffffec8 = auVar18 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)iVar25 * (short)(0x10000 / uVar36) + sVar38);
              FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar96._8_8_,0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
        }
        iVar25 = 0;
        if (3 < DAT_140e419b8) {
          fVar51 = (float)param_1[0xb];
          fVar53 = (float)param_1[10];
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + 0xe10;
          if (uVar36 == 1) {
            auVar99._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar99._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar99._8_4_ = 1;
            auVar21._8_8_ = 0;
            auVar21._0_8_ = auVar99._8_8_;
            in_stack_fffffffffffffec8 = auVar21 << 0x40;
            in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
            uVar33 = CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),sVar38);
            FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,uVar33,in_stack_fffffffffffffec0,0,
                          auVar99._8_8_,0);
            uVar57 = (undefined2)((uint)uVar33 >> 0x10);
          }
          else {
            do {
              auVar98._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar98._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar98._8_4_ = 1;
              auVar20._8_8_ = 0;
              auVar20._0_8_ = auVar98._8_8_;
              in_stack_fffffffffffffec8 = auVar20 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              in_stack_fffffffffffffeb8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffeb8 >> 0x10),
                            (short)iVar25 * (short)(0x10000 / uVar36) + sVar38);
              FUN_14006c2f0(3,0x20,fVar53 - fVar54,fVar51 - fVar52,in_stack_fffffffffffffeb8,
                            in_stack_fffffffffffffec0,0,auVar98._8_8_,0);
              uVar57 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
          uVar29 = (uint)(in_stack_fffffffffffffec0 >> 0x20);
          iVar25 = 0;
          fVar52 = (float)param_1[0xb] - fVar52;
          fVar54 = (float)param_1[10] - fVar54;
          uVar42 = ((uint)param_1[3] >> 0x1e ^ param_1[3]) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar42 >> 0x1e ^ uVar42) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar42 = uVar42 * 0x800 ^ uVar42;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar42) >> 8 ^ uVar42 ^ DAT_140e9fd18;
          sVar38 = ((short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)) + 0x12c0;
          if (uVar36 == 1) {
            uVar37 = 0x20;
            uVar49 = 3;
LAB_140026394:
            auVar101._12_4_ = in_stack_fffffffffffffec8._12_4_;
            auVar101._0_8_ = in_stack_fffffffffffffec8._0_8_;
            auVar101._8_4_ = 1;
            auVar23._8_8_ = 0;
            auVar23._0_8_ = auVar101._8_8_;
            in_stack_fffffffffffffec8 = auVar23 << 0x40;
            in_stack_fffffffffffffec0 = (ulonglong)uVar29 << 0x20;
            FUN_14006c2f0(uVar49,uVar37,fVar54,fVar52,CONCAT22(uVar57,sVar38),
                          in_stack_fffffffffffffec0,0,auVar101._8_8_,0);
          }
          else {
            do {
              auVar100._12_4_ = in_stack_fffffffffffffec8._12_4_;
              auVar100._0_8_ = in_stack_fffffffffffffec8._0_8_;
              auVar100._8_4_ = 1;
              auVar22._8_8_ = 0;
              auVar22._0_8_ = auVar100._8_8_;
              in_stack_fffffffffffffec8 = auVar22 << 0x40;
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffff00000000;
              FUN_14006c2f0(3,0x20,fVar54,fVar52,(short)iVar25 * (short)(0x10000 / uVar36) + sVar38,
                            in_stack_fffffffffffffec0,0,auVar100._8_8_,0);
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)uVar36);
          }
        }
      }
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    auVar104 = in_stack_fffffffffffffec8._4_12_;
    if ((int)param_1[3] < 10) {
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4a);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],0,5,2,0x49,in_stack_fffffffffffffec0);
      auVar104 = in_stack_fffffffffffffec8._4_12_;
    }
    else {
      local_res10._0_4_ = 0x46;
    }
    if (9 < (int)param_1[3]) {
      auVar102._4_12_ = auVar104;
      auVar102._0_4_ = 0x4d;
      in_stack_fffffffffffffec0 = CONCAT44((int)(in_stack_fffffffffffffec0 >> 0x20),0x4c);
      local_res10._0_4_ = FUN_1400c9580(param_1[3],10,5,3,0x4b,in_stack_fffffffffffffec0,auVar102);
    }
LAB_1400250d1:
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res10._0_4_ * 4),0x1e,7,
                  param_1[10],param_1[0xb],in_stack_fffffffffffffec0 & 0xffffffffffff0000,auVar4,
                  0xff,0xff,0xff,0xff,1,0);
    break;
  case 10:
    FUN_140003ad0(param_1);
    uVar33 = (undefined4)(in_stack_fffffffffffffec0 >> 0x20);
    iVar25 = param_1[3];
    if (iVar25 < 0xf0) {
      iVar31 = DAT_1407c7798 + 3;
      iVar30 = DAT_1407c7798 * 10;
      if (iVar25 - 0x3cU < 0xb4) {
        uVar58 = 0;
        uVar49 = FUN_1401349e0(iVar25,0x3c,0x4c,0xe0,0xf0,0,dVar44);
        uVar33 = DAT_14053accc;
        uVar58 = uVar58 & 0xffffffffffff0000;
        FUN_1400c8410(DAT_140e47544,0x6e,1,DAT_14053aedc,DAT_14053accc,uVar58,dVar44,uVar49,0xff,
                      0xff,0xff,0xff,1,0);
        uVar58 = uVar58 & 0xffffffffffff0000;
        FUN_1400c8410(*(undefined4 *)(&DAT_140e474f0 + (longlong)iVar31 * 4),0x6e,1,DAT_14053ae44,
                      uVar33,uVar58,uVar49,uVar49,0xff,0xff,0xff,0xff,1,0);
        uVar33 = (undefined4)(uVar58 >> 0x20);
        if (iVar25 == 0x4c) {
          FUN_14012e070(iVar30 + 99,4);
        }
        else {
          lVar3 = DAT_140e47908;
          if (iVar25 == 0xe0) {
            while (uVar33 = (undefined4)(uVar58 >> 0x20), lVar3 != 0) {
              lVar3 = *(longlong *)(lVar3 + 0x238);
              FUN_140323ce8();
            }
            DAT_140e47908 = 0;
            DAT_140e9fd30 = 0;
          }
        }
      }
      FUN_14007ac00(param_1);
      uVar58 = CONCAT44(uVar33,0x4f);
      param_1[0xb] = (float)param_1[0xb] + DAT_140539cec;
      iVar25 = FUN_1400c9580(param_1[3],0,5,2,0x4e,uVar58);
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar25 * 4),0x1e,7,param_1[10],
                    param_1[0xb],uVar58 & 0xffffffffffff0000,auVar4,0xff,0xff,0xff,0xff,1,0);
    }
    puVar27 = DAT_140e45d28;
    if (param_1[3] == 0xf0) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar33 = param_1[0xb];
      uVar2 = param_1[10];
      puVar27 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar27 = (undefined8 *)_malloc_base(0x60);
        if (puVar27 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar43 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar27 + 0x14) = uVar2;
        *(undefined4 *)(puVar27 + 3) = uVar33;
        *(undefined4 *)((longlong)puVar27 + 0x1c) = uVar2;
        *(undefined4 *)(puVar27 + 4) = uVar33;
        *puVar27 = 1;
        puVar27[1] = 0x10;
        *(undefined4 *)(puVar27 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar27 + 0x24) = 0;
        puVar27[5] = 0;
        puVar27[6] = 0x3ff0000000000000;
        puVar27[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar27 + 8) = 0;
        *(undefined4 *)((longlong)puVar27 + 0x44) = 0xff;
        *(undefined4 *)(puVar27 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar27 + 0x4c) = 0xff;
        puVar27[10] = 0xff;
        puVar27[0xb] = 0;
        if (bVar43) {
          DAT_140e45d78 = puVar27;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar27;
        }
      }
    }
    DAT_140e45d28 = puVar27;
    dVar45 = DAT_14053a430;
    local_res8 = iVar32;
    if (param_1[3] == 0x1e0) {
      *param_1 = 0;
    }
    goto LAB_140023d82;
  }
  dVar45 = DAT_14053a430;
  local_res8 = 0xff;
LAB_140023d82:
  if (((int)param_1[5] < 4) || ((param_1[5] == 4 && ((int)param_1[3] < 0x82)))) {
    fVar54 = (float)param_1[10];
    dVar44 = (double)(float)((double)CONCAT44(uVar56,uVar55) * dVar45);
    dVar45 = (double)FUN_1403307c0();
    fVar52 = (float)param_1[0xb];
    dVar47 = (double)FUN_140332d90();
    FUN_1400c8410(DAT_140e449a0,0x1e,7,fVar54,fVar52,(short)DAT_140e418c8 * -0xb6,local_res18,
                  local_res18,0xff,0xff,0xff,local_res8,1,0);
    FUN_1400c8410(DAT_140e449a0,0x1e,7,param_1[10],param_1[0xb],(short)DAT_140e418c8 * 0xb6,
                  local_res18,local_res18,0xff,0xff,0xff,local_res8,1,0);
    auVar65._4_4_ = uVar56;
    auVar65._0_4_ = uVar55;
    auVar65._8_4_ = uVar55;
    auVar65._12_4_ = uVar56;
    FUN_1400c8410(DAT_140e449a4,0x1e,7,param_1[10],param_1[0xb],
                  *(undefined2 *)((longlong)param_1 + 0x42),auVar65,0xff,0xff,0xff,local_res8,1,0);
    auVar66._4_4_ = uVar56;
    auVar66._0_4_ = uVar55;
    auVar66._8_4_ = uVar55;
    auVar66._12_4_ = uVar56;
    FUN_1400c8410(DAT_140e449ac,0x1e,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x11),
                  auVar66,0xff,0xff,0xff,local_res8,1,0);
    auVar67._4_4_ = uVar56;
    auVar67._0_4_ = uVar55;
    auVar67._8_4_ = uVar55;
    auVar67._12_4_ = uVar56;
    FUN_1400c8410(DAT_140e449a8,0x20,7,param_1[10],param_1[0xb],*(undefined2 *)(param_1 + 0x11),
                  auVar67,0xff,0xff,0xff,local_res8,1,0);
    uVar33 = DAT_140e44c6c;
    if (((int)param_1[5] < 3) && ((param_1[5] != 2 || ((int)param_1[3] < 0x65)))) {
      uVar33 = DAT_140e44c68;
    }
    auVar103._4_4_ = uVar56;
    auVar103._0_4_ = uVar55;
    auVar103._8_4_ = uVar55;
    auVar103._12_4_ = uVar56;
    FUN_1400c8410(uVar33,0x20,7,(float)(dVar45 * dVar44) + fVar54,(float)(dVar47 * dVar44) + fVar52,
                  *(undefined2 *)(param_1 + 0x11),auVar103,0xff,0xff,0xff,local_res8,1,0);
  }
  FUN_140004140(param_1);
  FUN_140002260();
  return;
}


