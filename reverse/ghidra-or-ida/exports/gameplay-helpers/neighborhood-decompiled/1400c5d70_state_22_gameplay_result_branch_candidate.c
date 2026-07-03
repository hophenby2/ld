// Function: state_22_gameplay_result_branch_candidate @ 1400c5d70
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_22_gameplay_result_branch_candidate(void)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  ulonglong uVar15;
  int iVar16;
  int iVar17;
  longlong lVar18;
  bool bVar19;
  float fVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  undefined4 uVar24;
  float fVar25;
  undefined4 uVar26;
  float fVar27;
  int local_res8;
  int local_res10;
  int local_res18;
  uint local_res20;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  double local_260;
  double local_258;
  undefined8 local_250;
  longlong local_248;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  
  uVar10 = DAT_140e46bb0;
  dVar5 = DAT_14053a020;
  dVar4 = DAT_140539f40;
  dVar23 = DAT_140539d28;
  uVar13 = 0xff;
  uVar14 = 3;
  iVar17 = 0xff;
  local_1a8 = _DAT_14053b880;
  uStack_1a0 = _UNK_14053b888;
  local_188 = _DAT_14053b8c0;
  uStack_180 = _UNK_14053b8c8;
  local_168 = _DAT_14053b860;
  uStack_160 = _UNK_14053b868;
  local_148 = _DAT_14053b8f0;
  uStack_140 = _UNK_14053b8f8;
  local_228 = 0;
  uStack_220 = 0;
  local_208 = _DAT_14053b590;
  uStack_200 = _UNK_14053b598;
  local_1e8 = _DAT_14053b5b0;
  uStack_1e0 = _UNK_14053b5b8;
  local_1c8 = _DAT_14053b5e0;
  uStack_1c0 = _UNK_14053b5e8;
  local_178 = _DAT_14053b870;
  uStack_170 = _UNK_14053b878;
  local_158 = _DAT_14053b900;
  uStack_150 = _UNK_14053b908;
  local_218 = _DAT_14053b580;
  uStack_210 = _UNK_14053b588;
  local_1f8 = _DAT_14053b5a0;
  uStack_1f0 = _UNK_14053b5a8;
  uVar15 = 2;
  local_f8 = 0xff;
  local_1b8 = 0x46185800;
  local_res10 = 2;
  local_res18 = 3;
  local_250 = DAT_140539f40;
  local_260 = 0.0;
  local_258 = 0.0;
  local_198 = _DAT_14053b920;
  uStack_190 = _UNK_14053b928;
  local_138 = _DAT_14053b920;
  uStack_130 = _UNK_14053b928;
  local_128 = _DAT_14053b920;
  uStack_120 = _UNK_14053b928;
  local_118 = _DAT_14053b920;
  uStack_110 = _UNK_14053b928;
  local_108 = _DAT_14053b920;
  uStack_100 = _UNK_14053b928;
  local_1d8 = _DAT_14053b5c0;
  uStack_1d0 = _UNK_14053b5c8;
  dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e46bb0 - 0.0) * DAT_14053a930 * DAT_14053a020
                                 * DAT_140539d28);
  iVar16 = DAT_1407c7798;
  local_res20 = 0;
  fVar20 = (float)(dVar21 * DAT_14053a018) + 0.0;
  if ((DAT_1407c7798 == 2) || (local_248 = 0, local_res8 = DAT_140e452c8, DAT_1407c7798 == 3)) {
    uVar14 = 5;
    uVar15 = 4;
    local_res10 = 4;
    local_res18 = 5;
    local_res20 = 1;
    local_248 = 1;
    local_res8 = DAT_140e452cc;
  }
  if ((DAT_1407c7798 == 4) || (DAT_1407c7798 == 5)) {
    uVar14 = 7;
    uVar15 = 6;
    local_res10 = 6;
    local_res18 = 7;
    local_res20 = 2;
    local_res8 = DAT_140e452d0;
    local_248 = 2;
  }
  if (DAT_1407c7798 - 6U < 2) {
    uVar15 = 8;
    local_res10 = 8;
    local_res8 = 8;
    uVar14 = 8;
    local_res18 = 8;
  }
  if (DAT_1407c7798 == 8) {
    uVar15 = 9;
    local_res10 = 9;
    local_res8 = 9;
    uVar14 = 9;
    local_res18 = 9;
  }
  if (uVar10 == 0) {
    DAT_140e46950 = *(float *)(&local_228 + local_res8);
    DAT_140e46954 = *(float *)((longlong)&local_228 + (longlong)local_res8 * 8 + 4);
    _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
LAB_1400c6081:
    local_250 = (double)FUN_140332d90();
    local_250 = local_250 + 0.0;
    dVar21 = (double)FUN_140332d90();
    iVar17 = (int)(dVar21 * DAT_14053a5f8);
  }
  else if ((int)uVar10 < 0x1e) goto LAB_1400c6081;
  uVar10 = DAT_140e46bb4;
  uVar9 = DAT_140e46014;
  dVar6 = DAT_14053ab78;
  dVar22 = DAT_140539f00;
  dVar21 = DAT_140539ef8;
  if (DAT_140e45274 == 0) {
    uVar24 = SUB84(DAT_140539f00,0);
    uVar26 = (undefined4)((ulonglong)DAT_140539f00 >> 0x20);
    if (DAT_140e46014 - 1 < 4) {
      dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e46014 - 0.0) * DAT_14053ab78 * dVar5 *
                                     dVar23);
      local_260 = dVar21 * dVar22 + 0.0;
    }
    uVar10 = uVar9;
    if (uVar9 + 4 < 4) {
LAB_1400c618d:
      dVar21 = (double)FUN_140332d90(((double)(int)-uVar10 - 0.0) * dVar6 * dVar5 * dVar23);
      local_258 = dVar21 * (double)CONCAT44(uVar26,uVar24) + 0.0;
    }
  }
  else if (DAT_140e45274 == 1) {
    uVar24 = SUB84(DAT_140539ef8,0);
    uVar26 = (undefined4)((ulonglong)DAT_140539ef8 >> 0x20);
    if (0 < (int)DAT_140e46bb4) {
      dVar22 = (double)FUN_140332d90(((double)(int)DAT_140e46bb4 - 0.0) * DAT_14053ab78 * dVar5 *
                                     dVar23);
      local_260 = dVar22 * dVar21 + 0.0;
    }
    if (0x7fffffff < uVar10) goto LAB_1400c618d;
  }
  fVar8 = DAT_140e46a14;
  fVar7 = DAT_140e46a10;
  if (0 < (int)uVar9) {
    dVar21 = (double)FUN_140332d90();
    fVar25 = *(float *)(&local_228 + local_res8);
    dVar22 = (double)FUN_140332d90();
    DAT_140e46954 =
         (float)(dVar22 * (double)(*(float *)((longlong)&local_228 + (longlong)local_res8 * 8 + 4) -
                                  fVar8)) + fVar8;
    DAT_140e46950 = (float)(dVar21 * (double)(fVar25 - fVar7)) + fVar7;
  }
  if (0x7fffffff < uVar9) {
    dVar21 = (double)FUN_140332d90();
    fVar25 = *(float *)(&local_228 + local_res8);
    dVar22 = (double)FUN_140332d90();
    DAT_140e46954 =
         (float)(dVar22 * (double)(*(float *)((longlong)&local_228 + (longlong)local_res8 * 8 + 4) -
                                  fVar8)) + fVar8;
    DAT_140e46950 = (float)(dVar21 * (double)(fVar25 - fVar7)) + fVar7;
  }
  FUN_1400be7a0(iVar16);
  FUN_1400c2860();
  uVar24 = DAT_140e4601c;
  puVar11 = (undefined4 *)_malloc_base(0x48);
  if (puVar11 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e0c = _DAT_140e46e0c + 1;
  *puVar11 = uVar24;
  bVar19 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar11[0xd] = iVar17;
  *(undefined8 *)(puVar11 + 1) = 0x5f;
  *(undefined8 *)(puVar11 + 3) = 0x43aa0000;
  *(undefined2 *)(puVar11 + 5) = 0;
  *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
  puVar11[10] = 0xff;
  puVar11[0xb] = 0xff;
  puVar11[0xc] = 0xff;
  *(undefined8 *)(puVar11 + 0xe) = 1;
  *(undefined8 *)(puVar11 + 0x10) = 0;
  if (bVar19) {
    DAT_140e46bf0 = puVar11;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar11;
  }
  fVar8 = DAT_14053ade0;
  fVar7 = DAT_14053acbc;
  DAT_140e46c88 = puVar11;
  if (uVar15 <= uVar14) {
    lVar18 = uVar15 * 4 + -4;
    iVar16 = local_res10 * 0x28;
    puVar11 = (undefined4 *)((longlong)&local_1a8 + uVar15 * 0xc + 4);
    do {
      fVar25 = (*(float *)(&local_228 + uVar15) + DAT_14053aedc) - DAT_140e46950;
      dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e46bb0 - (double)iVar16) * DAT_14053a698 *
                                     dVar5 * dVar23);
      fVar27 = (float)(dVar21 * DAT_14053a0b0) + 0.0 +
               ((*(float *)((longlong)&local_228 + uVar15 * 8 + 4) + DAT_14053ae38) - DAT_140e46954)
      ;
      if ((_DAT_14053b418 <= fVar25) && (fVar25 <= DAT_14053b028)) {
        auVar28._8_4_ = (undefined4)local_250;
        auVar28._0_8_ = local_250;
        auVar28._12_4_ = local_250._4_4_;
        FUN_1400c8410(DAT_140e46910,0x4b,1,fVar25,fVar27,0,auVar28,0x80,0x80,0x80,0xff,1,0);
        iVar17 = 0;
        auVar29._8_4_ = (undefined4)local_250;
        auVar29._0_8_ = local_250;
        auVar29._12_4_ = local_250._4_4_;
        FUN_1400c8410(DAT_140e46914,0x4b,6,fVar25,fVar27,0,auVar29,puVar11[-1],*puVar11,puVar11[1],
                      0xc0,1,0);
        do {
          while( true ) {
            while( true ) {
              iVar3 = (iVar17 + 6) * 5;
              dVar21 = dVar4;
              if (iVar3 != iVar3 + 0xc) {
                if ((int)DAT_140e46bb0 < iVar3) {
                  dVar21 = 0.0;
                }
                else if ((int)DAT_140e46bb0 < iVar3 + 0xc) {
                  dVar21 = (double)FUN_140332d90(((double)(int)DAT_140e46bb0 - (double)iVar3) *
                                                 DAT_14053a998 * dVar5 * dVar23);
                  dVar21 = dVar21 + 0.0;
                }
              }
              if (iVar17 != 0) break;
              uVar24 = *(undefined4 *)(&DAT_140e46918 + lVar18);
              puVar12 = (undefined4 *)_malloc_base(0x48);
              if (puVar12 == (undefined4 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              *puVar12 = uVar24;
              puVar12[3] = fVar25;
              *(double *)(puVar12 + 8) = dVar21;
              puVar12[1] = 0x4b;
              puVar12[2] = 1;
              *(undefined2 *)(puVar12 + 5) = 0;
              *(undefined8 *)(puVar12 + 6) = 0x3ff0000000000000;
              puVar12[4] = fVar27 - fVar8;
              puVar12[10] = 0xff;
              puVar12[0xb] = 0xff;
              puVar12[0xc] = 0xff;
              puVar12[0xd] = 0xff;
              *(undefined8 *)(puVar12 + 0xe) = 1;
              *(undefined8 *)(puVar12 + 0x10) = 0;
              _DAT_140e46dbc = _DAT_140e46dbc + 1;
              if (DAT_140e46bf0 == (undefined4 *)0x0) {
                DAT_140e46bf0 = puVar12;
              }
              if (DAT_140e46c88 != (undefined4 *)0x0) {
                *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar12;
              }
              iVar17 = 1;
              DAT_140e46c88 = puVar12;
            }
            if ((iVar17 != 1) || (9 < DAT_1407c7798)) break;
            FUN_1400c8410(*(undefined4 *)(&DAT_140e46880 + lVar18),0x4b,1,fVar25,fVar27 - fVar7,0,
                          dVar4,dVar21,0xff,0xff,0xff,0xff,1,0);
            iVar17 = 2;
          }
          iVar17 = iVar17 + 1;
        } while (iVar17 < 8);
      }
      iVar16 = iVar16 + 0x28;
      uVar15 = uVar15 + 1;
      puVar11 = puVar11 + 3;
      lVar18 = lVar18 + 4;
    } while ((longlong)uVar15 <= (longlong)(ulonglong)uVar14);
  }
  fVar8 = DAT_14053aedc;
  fVar7 = DAT_14053ae38;
  uVar24 = 0xc0;
  if (DAT_140e45274 == 0) {
    if (local_res8 < local_res18) {
      local_260 = local_260 + dVar4;
      auVar2._8_4_ = SUB84(local_260,0);
      auVar2._0_8_ = local_260;
      auVar2._12_4_ = (int)((ulonglong)local_260 >> 0x20);
      FUN_1400c8410(DAT_140e41934,0x55,1,fVar20 + _DAT_14053af74,DAT_14053ae38,0,auVar2,0xff,0xff,
                    0xff,0xff,1,0);
    }
    if (local_res10 < local_res8) {
      FUN_1400c8410(DAT_140e41934,0x55,1,DAT_14053ae48 - fVar20,fVar7,0x8000,local_258 + dVar4,
                    local_258 + dVar4,0xff,0xff,0xff,0xff,1,0);
    }
  }
  FUN_1400d9b60(0,0x70,0xff);
  dVar21 = DAT_140539f28;
  if (DAT_140e45274 == 0) {
    uVar13 = 0x80;
    if (DAT_140e45fac < 0x80000000) {
      dVar22 = local_250 * DAT_140539f28;
    }
    else {
      dVar23 = (double)FUN_140332d90(((double)(int)-DAT_140e45fac - 0.0) * DAT_14053a9d8 * dVar5 *
                                     dVar23);
      dVar23 = dVar23 * _DAT_14053b068;
      uVar24 = 0xc0;
      uVar13 = 0x80;
LAB_1400c6922:
      dVar22 = dVar23 + dVar4;
    }
  }
  else if (DAT_140e45274 == 1) {
    uVar10 = DAT_140e46bb0 & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    uVar24 = 0xc0;
    if (1 < (int)uVar10) {
      uVar24 = 0xff;
    }
    dVar22 = dVar4;
    if (0 < (int)DAT_140e45fac) {
      dVar23 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * DAT_14053a9d8 * dVar5 *
                                     dVar23);
      dVar22 = dVar23 * DAT_140539ec8 + dVar21;
    }
  }
  else {
    dVar22 = DAT_140539f28;
    if (DAT_140e45274 == 2) {
      uVar24 = 0xff;
      dVar22 = dVar4;
      if ((int)DAT_140e45fac < 0x11) {
        dVar23 = (double)FUN_140332d90(((double)(int)DAT_140e45fac - 0.0) * DAT_14053aa28 * dVar5 *
                                       dVar23);
        dVar23 = dVar23 * DAT_140539ec8;
        uVar24 = 0xff;
        uVar13 = 0xff;
        goto LAB_1400c6922;
      }
    }
  }
  FUN_1400c8410(DAT_140e46a98,0x6e,1,fVar8,DAT_14053aeac,0,dVar22,dVar22,uVar24,uVar24,uVar24,uVar13
                ,1,0);
  uVar13 = DAT_140e47200;
  if (((0x3b < (int)DAT_140e46bb0) && (DAT_140e45fac == 0)) && (DAT_140e46958 == 0)) {
    if (((DAT_140e467c0 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45274 == 0)) {
      if (((&DAT_140e452c8)[local_res20] < local_res18) && (local_res10 != local_res18)) {
        iVar16 = DAT_140e44190 * 0x19;
        _DAT_140e46a10 = CONCAT44(DAT_140e46954,DAT_140e46950);
        (&DAT_140e452c8)[local_res20] = (&DAT_140e452c8)[local_res20] + 1;
        DAT_140e46014 = 1;
        FUN_140184700(iVar16,uVar13);
        FUN_14018a340(DAT_140e47200,1,1);
        DAT_140e467fc = 1;
      }
    }
    fVar7 = DAT_140e46954;
    fVar20 = DAT_140e46950;
    if ((((DAT_140e467c4 == 1) && (DAT_140e467fc == 0)) && (DAT_140e45274 == 0)) &&
       ((local_res10 < (&DAT_140e452c8)[local_res20] && (local_res10 != local_res18)))) {
      iVar16 = DAT_140e44190 * 0x19;
      (&DAT_140e452c8)[local_res20] = (&DAT_140e452c8)[local_res20] + -1;
      _DAT_140e46a10 = CONCAT44(fVar7,fVar20);
      DAT_140e46014 = 0xffffffff;
      FUN_140184700(iVar16,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
      DAT_140e467fc = 1;
    }
    if (((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) && (DAT_140e46014 == 0)) {
      if (DAT_140e45274 == 1) {
        puVar11 = &DAT_140e45100;
        do {
          FUN_14018f230(*puVar11,0);
          puVar11 = puVar11 + 1;
        } while ((longlong)puVar11 < 0x140e45178);
        _DAT_1407c777c = 0x3f800000;
      }
      DAT_140e45274 = DAT_140e45274 + 1;
      DAT_140e45fac = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e467fc = 1;
    }
    if ((((int)DAT_140e467cc == 1) && (DAT_140e46014 == 0)) && (DAT_140e45274 == 1)) {
      DAT_140e45274 = 0;
      DAT_140e45fac = 0xffffffff;
      DAT_140e467fc = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
      FUN_14018a340(DAT_140e47208,1,1);
    }
    if ((DAT_140e467e4 != 1) &&
       (DAT_140e467e0 != 1 &&
        (DAT_140e467dc != 1 &&
        (DAT_140e467d8 != 1 &&
        (DAT_140e467d4 != 1 &&
        (DAT_140e467cc._4_4_ != 1 &&
        ((int)DAT_140e467cc != 1 &&
        (DAT_140e467c8 != 1 &&
        (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))
        )))))) {
      DAT_140e467fc = 0;
    }
  }
  if (((0 < (int)DAT_140e46014) && (DAT_140e46014 = DAT_140e46014 + 1, DAT_140e46014 == 0x1e)) ||
     ((0x7fffffff < DAT_140e46014 &&
      (DAT_140e46014 = DAT_140e46014 - 1, DAT_140e46014 == 0xffffffe2)))) {
    DAT_140e46014 = 0;
  }
  if (0 < (int)DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 - 1;
  }
  if (0x7fffffff < DAT_140e46bb4) {
    DAT_140e46bb4 = DAT_140e46bb4 + 1;
  }
  if (DAT_140e45274 == 2) {
    if (0x3b < (int)DAT_140e45fac) {
      FUN_1400d3fd0(DAT_140e45fac - 0x3c);
    }
    lVar18 = DAT_140e45d78;
    if (DAT_140e45fac == 100) {
      while (lVar18 != 0) {
        lVar1 = *(longlong *)(lVar18 + 0x58);
        FUN_140323ce8(lVar18);
        lVar18 = lVar1;
      }
      DAT_140e45d78 = 0;
      DAT_140e45d28 = 0;
      DAT_140e45d1c = 0;
      DAT_1407c7798 = (&DAT_140e452c8)[local_248];
      _DAT_140e46a28 = 0;
      _DAT_140e46a30 = 0;
      _DAT_140e46a38 = 0;
      DAT_140e45270 = 0x14;
      DAT_140e418c8 = 0;
    }
LAB_1400c6d76:
    if (DAT_140e45fac != 0xfffffff6) {
      if (0 < (int)DAT_140e45fac) {
        DAT_140e45fac = DAT_140e45fac + 1;
      }
      DAT_140e418c8 = DAT_140e418c8 + 1;
      if (0x7fffffff < DAT_140e45fac) {
        DAT_140e45fac = DAT_140e45fac - 1;
      }
      goto LAB_1400c6db4;
    }
  }
  else if (DAT_140e45fac != 10) goto LAB_1400c6d76;
  DAT_140e418c8 = DAT_140e418c8 + 1;
  DAT_140e45fac = 0;
LAB_1400c6db4:
  DAT_140e46bb0 = DAT_140e46bb0 + 1;
  return;
}


