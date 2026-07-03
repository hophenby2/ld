// Function: state_2c_auto_gameplay_branch_candidate @ 1400fcd20
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_2c_auto_gameplay_branch_candidate(void)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined8 uVar18;
  longlong lVar19;
  uint uVar20;
  int iVar21;
  int iVar23;
  uint uVar24;
  ulonglong uVar25;
  int iVar26;
  int iVar27;
  ulonglong uVar28;
  undefined4 *puVar29;
  bool bVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  undefined4 uVar35;
  undefined1 auStack_1f8 [32];
  float local_1d8;
  undefined4 local_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 local_1b0;
  undefined4 local_1a8;
  int local_1a0;
  undefined4 local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_178 [4];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined4 local_158;
  undefined4 local_154;
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
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  FILE *local_d8;
  ulonglong local_d0;
  ulonglong uVar22;
  
  uVar35 = DAT_140e45f70;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_1f8;
  local_148 = _DAT_14053b460;
  uStack_140 = _UNK_14053b468;
  local_138 = _DAT_14053b4f0;
  uStack_130 = _UNK_14053b4f8;
  local_128 = _DAT_14053b770;
  uStack_120 = _UNK_14053b778;
  local_118 = _DAT_14053b670;
  uStack_110 = _UNK_14053b678;
  local_108 = _DAT_14053b660;
  uStack_100 = _UNK_14053b668;
  local_f8 = _DAT_14053b740;
  uStack_f0 = _UNK_14053b748;
  local_e8 = 0xb;
  local_e4 = 2;
  local_e0 = 0xffffffff;
  puVar16 = (undefined4 *)_malloc_base(0x48);
  if (puVar16 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46c94 = DAT_140e46c94 + 1;
  uVar22 = 0;
  iVar21 = 0;
  bVar30 = DAT_140e46bf0 == (undefined4 *)0x0;
  *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
  *puVar16 = uVar35;
  puVar16[10] = 0xff;
  puVar16[0xb] = 0xff;
  puVar16[0xc] = 0xff;
  puVar16[0xd] = 0xff;
  *(undefined8 *)(puVar16 + 1) = 1;
  *(undefined8 *)(puVar16 + 3) = 0;
  *(undefined2 *)(puVar16 + 5) = 0;
  *(undefined8 *)(puVar16 + 0xe) = 1;
  *(undefined8 *)(puVar16 + 0x10) = 0;
  if (bVar30) {
    DAT_140e46bf0 = puVar16;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar16;
  }
  puVar29 = &DAT_140e45100;
  DAT_140e46c88 = puVar16;
  if (DAT_140e418c8 == 1) {
    puVar16 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar16,0);
      puVar16 = puVar16 + 1;
    } while ((longlong)puVar16 < 0x140e45178);
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e4515c);
    FUN_14018a340(DAT_140e4515c,1,1);
    DAT_140e45100 = DAT_140e4515c;
    if ((((DAT_140e41b00 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e445c0 < 0x14)) &&
       ((&DAT_140e43f1c)[DAT_140e445c0] == 0)) {
      (&DAT_140e43f1c)[DAT_140e445c0] = 1;
      FUN_1400b4350(0);
      save_init_or_reset_candidate();
    }
  }
  if ((int)DAT_140e418c8 < 0x28) {
    transition_tile_wipe_in_candidate();
  }
  local_1d0 = 0xff;
  local_1d8 = 5.04467e-43;
  FUN_1400fe870(*(undefined4 *)(&DAT_140e45f74 + (longlong)(DAT_140e445c0 * 3) * 4),0,800,0x280);
  local_1d0 = 0xff;
  local_1d8 = 5.04467e-43;
  FUN_1400fe870(*(undefined4 *)(&DAT_140e45f78 + (longlong)(DAT_140e445c0 * 3) * 4),800,0x640,0x280)
  ;
  local_1d0 = 0xff;
  local_1d8 = 5.04467e-43;
  FUN_1400fe870(*(undefined4 *)(&DAT_140e45f7c + (longlong)(DAT_140e445c0 * 3) * 4),0x640,0x960,
                0x280);
  iVar14 = DAT_14053aed4;
  uVar15 = DAT_14053ac9c;
  uVar35 = DAT_14053ac34;
  uVar25 = uVar22;
  uVar28 = uVar22;
  uVar24 = DAT_140e418c8;
  iVar27 = DAT_140e445c0;
  do {
    iVar23 = ((int)(uVar28 / 3) + (int)uVar22) * 0x32;
    iVar26 = (int)uVar28;
    if (*(int *)((longlong)&local_148 + (uVar25 + (longlong)iVar27 * 9) * 4) == -1) {
      if (uVar24 == iVar23 + 0x3cU) {
        local_198 = 5;
        local_1a0 = 1;
        local_1a8 = 1;
        local_1b0 = 0xff;
        local_1b8 = 0xff;
        uStack_1c0._0_4_ = 0xff;
        local_1c8._0_4_ = uVar15;
        local_1d0 = uVar35;
        local_1d8 = (float)iVar14;
        FUN_14012e070(iVar26 + iVar27 * 9 + 0xfa,0);
        uVar24 = DAT_140e418c8;
        iVar27 = DAT_140e445c0;
      }
      lVar19 = DAT_140e47908;
      if (uVar24 == iVar23 + 0x122U) {
        while (lVar19 != 0) {
          lVar19 = *(longlong *)(lVar19 + 0x238);
          FUN_140323ce8();
          uVar24 = DAT_140e418c8;
          iVar27 = DAT_140e445c0;
        }
        DAT_140e47908 = 0;
        DAT_140e9fd30 = 0;
      }
    }
    iVar1 = *(int *)((longlong)&local_148 + (uVar25 + (longlong)iVar27 * 9) * 4);
    if (((iVar1 != -1) && (iVar23 + 0x28 <= (int)uVar24)) && ((int)uVar24 < iVar23 + 0x122)) {
      local_1d0 = 0;
      local_1d8 = (float)(iVar23 + 0x122);
      FUN_14012e8e0(iVar26 + iVar27 * 9 + 0xfa,iVar1,uVar24,iVar23 + 0x28);
      uVar24 = DAT_140e418c8;
      iVar27 = DAT_140e445c0;
    }
    uVar28 = (ulonglong)(iVar26 + 1);
    uVar20 = (int)uVar22 + 5;
    uVar22 = (ulonglong)uVar20;
    uVar25 = uVar25 + 1;
  } while ((int)uVar20 < 0x2d);
  local_1d8 = (float)DAT_14053ae1c;
  FUN_1400fe940(0,0x97e,0x140);
  local_1d8 = (float)DAT_14053ae3c;
  FUN_1400fe940(1,0x992,0x140);
  local_1d0 = 0x80;
  local_1d8 = 6.30584e-43;
  FUN_1400fe870(*(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4),0x960,0xaf0,
                0x186);
  uVar8 = DAT_14053ae04;
  local_1d8 = (float)DAT_14053ae04;
  FUN_1400fe940(2,0xb0e,0x140);
  uVar10 = DAT_14053ae30;
  local_1d8 = (float)DAT_14053ae30;
  FUN_1400fe940(3,0xb18,0x140);
  uVar11 = DAT_14053ae48;
  local_1d8 = (float)DAT_14053ae48;
  FUN_1400fe940(4,0xb22,0x140);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442b8,0xaf0,0xc80,0x348);
  uVar15 = DAT_14053ad70;
  local_1d8 = (float)DAT_14053ad70;
  FUN_1400fe940(5,0xc9e,0x140);
  uVar7 = DAT_14053ade8;
  local_1d8 = (float)DAT_14053ade8;
  FUN_1400fe940(6,0xca8,0x140);
  uVar9 = DAT_14053ae24;
  local_1d8 = (float)DAT_14053ae24;
  FUN_1400fe940(7,0xcb2,0x140);
  local_1d8 = (float)uVar10;
  FUN_1400fe940(8,0xcbc,0x140);
  uVar13 = DAT_14053ae70;
  local_1d8 = (float)DAT_14053ae70;
  FUN_1400fe940(9,0xcc6,0x140);
  local_1d8 = (float)DAT_14053ae98;
  FUN_1400fe940(10,0xcd0,0x140);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442bc,0xc80,0xe10,0x186);
  local_1d8 = (float)DAT_14053acbc;
  FUN_1400fe940(0xb,0xe2e,300);
  uVar35 = DAT_14053ad50;
  local_1d8 = (float)DAT_14053ad50;
  FUN_1400fe940(0xc,0xe33,300);
  uVar5 = DAT_14053ad80;
  local_1d8 = (float)DAT_14053ad80;
  FUN_1400fe940(0xd,0xe38,300);
  uVar6 = DAT_14053ade0;
  local_1d8 = (float)DAT_14053ade0;
  FUN_1400fe940(0xe,0xe3d,300);
  local_1d8 = (float)uVar8;
  FUN_1400fe940(0xf,0xe42,300);
  local_1d8 = (float)DAT_14053ae1c;
  FUN_1400fe940(0x10,0xe47,300);
  local_1d8 = (float)uVar10;
  FUN_1400fe940(0x11,0xe4c,300);
  uVar12 = DAT_14053ae5c;
  local_1d8 = (float)uVar11;
  FUN_1400fe940(0x12,0xe51,300);
  local_1d8 = (float)uVar12;
  FUN_1400fe940(0x13,0xe56,300);
  uVar11 = DAT_14053ae7c;
  local_1d8 = (float)DAT_14053ae7c;
  FUN_1400fe940(0x14,0xe5b,300);
  local_1d8 = (float)DAT_14053ae90;
  FUN_1400fe940(0x15,0xe60,300);
  local_1d8 = (float)DAT_14053aea8;
  FUN_1400fe940(0x16,0xe65,300);
  local_1d8 = (float)DAT_14053aecc;
  FUN_1400fe940(0x24,0xea6,0xf0);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442c0,0xe10,4000,0x37a);
  local_1d8 = (float)uVar35;
  FUN_1400fe940(0xc,0xfbe,300);
  local_1d8 = (float)uVar5;
  FUN_1400fe940(0xd,0xfc3,300);
  local_1d8 = (float)uVar6;
  FUN_1400fe940(0x17,0xfc8,300);
  local_1d8 = (float)uVar8;
  FUN_1400fe940(0x18,0xfcd,300);
  local_1d8 = (float)DAT_14053ae1c;
  FUN_1400fe940(0x19,0xfd2,300);
  local_1d8 = (float)uVar10;
  FUN_1400fe940(0x1a,0xfd7,300);
  uVar5 = DAT_14053ae48;
  local_1d8 = (float)DAT_14053ae48;
  FUN_1400fe940(0x1b,0xfdc,300);
  local_1d8 = (float)DAT_14053ae5c;
  FUN_1400fe940(0x1c,0xfe1,300);
  local_1d8 = (float)uVar11;
  FUN_1400fe940(0x38,0xfe6,300);
  local_1d8 = (float)DAT_14053aeb8;
  FUN_1400fe940(0x24,0x1036,0xf0);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442c4,4000,0x1130,0x186);
  uVar6 = DAT_14053ae5c;
  local_1d8 = (float)uVar15;
  FUN_1400fe940(0x1d,0x114e,300);
  uVar35 = DAT_14053ad9c;
  local_1d8 = (float)DAT_14053ad9c;
  FUN_1400fe940(0x1e,0x1158,300);
  local_1d8 = (float)uVar8;
  FUN_1400fe940(0x1f,0x1162,300);
  local_1d8 = (float)DAT_14053ae1c;
  FUN_1400fe940(0x20,0x116c,300);
  local_1d8 = (float)uVar10;
  FUN_1400fe940(0x21,0x1176,300);
  local_1d8 = (float)uVar5;
  FUN_1400fe940(0x22,0x1180,300);
  local_1d8 = (float)uVar6;
  FUN_1400fe940(0x23,0x118a,300);
  uVar10 = DAT_14053aea0;
  local_1d8 = (float)DAT_14053aea0;
  FUN_1400fe940(0x24,0x11c6,0xf0);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442c8,0x1130,0x12c0,0x37a);
  local_1d8 = (float)uVar15;
  FUN_1400fe940(0x25,0x12de,300);
  local_1d8 = (float)uVar7;
  FUN_1400fe940(0x26,0x12e8,300);
  local_1d8 = (float)uVar8;
  FUN_1400fe940(0x27,0x12f2,300);
  local_1d8 = (float)uVar9;
  FUN_1400fe940(0x28,0x12fc,300);
  uVar5 = DAT_14053ae50;
  local_1d8 = (float)DAT_14053ae50;
  FUN_1400fe940(0x29,0x1306,300);
  local_1d8 = (float)uVar13;
  FUN_1400fe940(0x2a,0x1310,300);
  uVar6 = DAT_14053ae88;
  local_1d8 = (float)DAT_14053ae88;
  FUN_1400fe940(0x2b,0x131a,300);
  local_1d8 = (float)DAT_14053aebc;
  FUN_1400fe940(0x2c,0x1356,0xf0);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442cc,0x12c0,0x1450,0x186);
  local_1d8 = (float)uVar15;
  FUN_1400fe940(0x39,0x146e,300);
  local_1d8 = (float)DAT_14053adb4;
  FUN_1400fe940(0x3a,0x1478,300);
  local_1d8 = (float)DAT_14053ae14;
  FUN_1400fe940(0x3b,0x1482,300);
  uVar15 = DAT_14053ae2c;
  local_1d8 = (float)DAT_14053ae2c;
  FUN_1400fe940(0x3c,0x148c,300);
  local_1d8 = (float)uVar13;
  FUN_1400fe940(0x3f,0x1496,0x140);
  local_1d8 = (float)uVar6;
  FUN_1400fe940(0x40,0x14a0,0x140);
  local_1d8 = (float)DAT_14053aea4;
  FUN_1400fe940(0x41,0x14aa,0x140);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442d0,0x1450,0x15e0,0x37a);
  local_1d8 = (float)uVar7;
  FUN_1400fe940(0x2d,0x15fe,300);
  local_1d8 = (float)uVar15;
  FUN_1400fe940(0x3d,0x1608,300);
  local_1d8 = (float)DAT_14053ae48;
  FUN_1400fe940(0x3e,0x1612,300);
  local_1d0 = 0x80;
  local_1d8 = 5.60519e-43;
  FUN_1400fe870(DAT_140e442d4,0x15e0,6000,0x186);
  local_1d8 = (float)DAT_14053ad1c;
  FUN_1400fe940(0x2d,0x178e,0x140);
  local_1d8 = (float)uVar35;
  FUN_1400fe940(0x2e,0x1793,0x140);
  local_1d8 = (float)DAT_14053adbc;
  FUN_1400fe940(0x2f,0x1798,0x140);
  local_1d8 = (float)DAT_14053adf4;
  FUN_1400fe940(0x30,0x179d,0x140);
  local_1d8 = (float)DAT_14053ae28;
  FUN_1400fe940(0x31,0x17a2,0x140);
  local_1d8 = (float)DAT_14053ae38;
  FUN_1400fe940(0x32,0x17a7,0x140);
  local_1d8 = (float)uVar5;
  FUN_1400fe940(0x33,0x17ac,0x140);
  local_1d8 = (float)DAT_14053ae74;
  FUN_1400fe940(0x34,0x17b1,0x140);
  local_1d8 = (float)uVar10;
  FUN_1400fe940(0x35,0x17b6,0x140);
  local_1d8 = (float)DAT_14053aeb0;
  FUN_1400fe940(0x36,0x17bb,0x140);
  local_1d8 = (float)DAT_14053ae1c;
  FUN_1400fe940(0x37,0x191e,0x140);
  if ((DAT_140e44e68 == 1) || (DAT_1407c7798 == 9)) {
    local_1c8._0_4_ = 0x80;
    local_1d0 = 0;
    local_1d8 = 9.52883e-42;
    uVar15 = FUN_1401348b0(DAT_140e418c8,6000,0x1798,0x1a68);
    uVar35 = DAT_140e442d8;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    bVar30 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar35;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[1] = 100;
    puVar16[2] = 1;
    puVar16[3] = 0x445e8000;
    puVar16[4] = 0x43c80000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[0xd] = uVar15;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar30) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
  }
  else {
    local_1c8._0_4_ = 0x20;
    local_1d0 = 0;
    local_1d8 = 9.52883e-42;
    uVar15 = FUN_1401348b0(DAT_140e418c8,6000,0x1798,0x1a68);
    uVar35 = DAT_140e442d8;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46e20 = _DAT_140e46e20 + 1;
    bVar30 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar35;
    puVar16[1] = 100;
    puVar16[2] = 1;
    puVar16[3] = 0x445e8000;
    puVar16[4] = 0x43c80000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 10) = 0;
    puVar16[0xc] = 0;
    puVar16[0xd] = uVar15;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar30) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
  }
  DAT_140e46c88 = puVar16;
  if (0x1b7f < (int)DAT_140e418c8) {
    uVar18 = 0x118;
    if (DAT_140e41928 == 0) {
      if (DAT_1407c7798 == 8) {
        if (DAT_140e419b8 == 3) {
          uVar18 = 0x119;
        }
        else if (DAT_140e419b8 == 4) {
          uVar18 = 0x11a;
        }
      }
      else if (DAT_1407c7798 == 9) {
        uVar18 = 0x118;
        if (DAT_140e419b8 < 3) {
          uVar18 = 0x11b;
        }
        if (DAT_140e419b8 == 3) {
          uVar18 = 0x11c;
        }
        else if (DAT_140e419b8 == 4) {
          uVar18 = 0x11d;
        }
      }
    }
    else if (DAT_140e41928 == 1) {
      if (DAT_140e44e68 == 0) {
        uVar18 = 0x118;
        if (DAT_140e419b8 < 3) {
          uVar18 = 0x11e;
        }
        if (DAT_140e419b8 == 3) {
          uVar18 = 0x11f;
        }
        else if (DAT_140e419b8 == 4) {
          uVar18 = 0x120;
        }
      }
      else if (DAT_140e44e68 == 1) {
        uVar18 = 0x118;
        if (DAT_140e419b8 < 3) {
          uVar18 = 0x121;
        }
        if (DAT_140e419b8 == 3) {
          uVar18 = 0x122;
        }
        else if (((DAT_140e419b8 == 4) && (uVar18 = 0x123, DAT_140e41abc == 2)) &&
                (uVar18 = 0x123, DAT_140e45268 == 1)) {
          uVar18 = 0x124;
        }
      }
      if (DAT_140e451a4 == 1) {
        uVar18 = 0x125;
      }
    }
    local_1d0 = 0;
    local_1d8 = 0.004723787;
    FUN_14012e8e0(uVar18,3,DAT_140e418c8,0x1b80);
  }
  local_1d0 = 0xff;
  local_1d8 = 5.04467e-43;
  FUN_1400fe870((&DAT_140e45f70)[DAT_140e445c0 + 10],0x1a90,1000000,0x280);
  uVar24 = DAT_140e418c8;
  dVar4 = DAT_14053ab58;
  dVar32 = DAT_14053a778;
  dVar3 = DAT_14053a0b0;
  dVar2 = DAT_14053a020;
  dVar33 = DAT_140539f40;
  dVar34 = DAT_140539d28;
  uVar35 = SUB84(DAT_140539f40,0);
  if (0x1b07 < (int)DAT_140e418c8) {
    if (0x1b07 < (int)DAT_140e418c8) {
      iVar21 = 0xff;
    }
    local_158 = 0x43c80000;
    local_154 = 0x435c0000;
    local_178[0] = 0xfffffb50;
    local_178[1] = 0x4b0;
    local_178[2] = 0xfffffb50;
    local_168 = _DAT_14053bd00;
    uStack_160 = _UNK_14053bd08;
    if ((int)DAT_140e418c8 < 0x1b28) {
      dVar31 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053ab58) * DAT_14053a778 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar21 = (int)(dVar31 * DAT_14053a5f8);
LAB_1400fe1c1:
      dVar32 = (double)FUN_140332d90(((double)(int)uVar24 - _DAT_14053ab48) * dVar32 * dVar2 *
                                     dVar34);
      dVar31 = dVar32 + dVar32 + dVar33;
      if (0x1b27 < (int)uVar24) {
LAB_1400fe1f8:
        dVar31 = dVar33;
      }
    }
    else {
      dVar31 = DAT_14053a018;
      if (0x1b07 < (int)DAT_140e418c8) {
        if ((int)DAT_140e418c8 < 0x1b28) goto LAB_1400fe1c1;
        goto LAB_1400fe1f8;
      }
    }
    lVar19 = (longlong)DAT_140e445c0;
    dVar33 = (double)FUN_140332d90(((double)(int)uVar24 - dVar4) * DAT_14053a698 * dVar2 * dVar34);
    local_190 = 0;
    local_198 = 1;
    local_1a8 = 0xff;
    local_1b0 = 0xff;
    local_1b8 = 0xff;
    local_1d0 = CONCAT22(local_1d0._2_2_,*(undefined2 *)(local_178 + lVar19));
    local_1d8 = (float)(dVar33 * dVar3) + 0.0 + *(float *)((longlong)&local_168 + lVar19 * 8 + 4);
    local_1a0 = iVar21;
    uStack_1c0 = dVar31;
    local_1c8 = dVar31;
    FUN_1400c8410(DAT_140e450a0,0x65,1);
  }
  iVar21 = DAT_140e451bc;
  uVar24 = DAT_140e418c8 & 0x80000007;
  if ((int)uVar24 < 0) {
    uVar24 = (uVar24 - 1 | 0xfffffff8) + 1;
  }
  if (uVar24 == 0) {
    dVar33 = (double)FUN_140134db0(DAT_140e451bc + -0x29a,DAT_140539f00,uVar35);
    uStack_1c0._0_4_ = SUB84(dVar33,0);
    uStack_1c0._4_4_ = (undefined4)((ulonglong)dVar33 >> 0x20);
    local_1c8 = dVar33 * dVar3;
    uVar24 = (iVar21 + 6U >> 0x1e ^ iVar21 + 6U) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar24 >> 0x1e ^ uVar24) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar24 = uVar24 * 0x800 ^ uVar24;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar24) >> 8 ^ uVar24 ^ DAT_140e9fd18;
    local_188 = 0;
    local_190 = 0x40;
    local_198 = 0xff;
    local_1a0 = 0xff;
    local_1a8 = 0xff;
    local_1b0 = 0;
    local_1d0 = CONCAT22(local_1d0._2_2_,0xc000);
    local_1d8 = (float)(DAT_140e9fd1c % 0x1a5 + 400);
    local_1b8 = (undefined4)uStack_1c0;
    uStack_1b4 = uStack_1c0._4_4_;
    FUN_140070d00(0,DAT_140e41a40,5);
  }
  FUN_140070e40();
  FUN_1400714d0();
  iVar21 = DAT_140e445c0;
  uVar24 = DAT_140e418c8;
  if (DAT_140e45fac == 0) {
    if (((int)DAT_140e418c8 < 0x1c20) && ((&DAT_140e441c0)[DAT_140e445c0] != 1)) goto LAB_1400fe7fa;
    dVar33 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - _DAT_14053ab60) * DAT_14053a798 *
                                   dVar2 * dVar34);
    iVar27 = 0x80 - (int)(dVar33 * DAT_14053b1c8);
    puVar16 = DAT_140e46c88;
    if (0x1c1f < (int)uVar24) {
      uVar35 = (&DAT_140e45f70)[iVar21 + 10];
      puVar16 = (undefined4 *)_malloc_base(0x48);
      if (puVar16 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46e20 = _DAT_140e46e20 + 1;
      bVar30 = DAT_140e46bf0 == (undefined4 *)0x0;
      *puVar16 = uVar35;
      *(undefined8 *)(puVar16 + 1) = 100;
      *(undefined8 *)(puVar16 + 3) = 0;
      *(undefined2 *)(puVar16 + 5) = 0;
      *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
      puVar16[10] = 0xff;
      puVar16[0xb] = 0xff;
      puVar16[0xc] = 0xff;
      puVar16[0xd] = 0xff;
      *(undefined8 *)(puVar16 + 0xe) = 1;
      *(undefined8 *)(puVar16 + 0x10) = 0;
      if (bVar30) {
        DAT_140e46bf0 = puVar16;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
      }
    }
    DAT_140e46c88 = puVar16;
    FUN_1400d9b60(6,0x7c,iVar27);
    if ((&DAT_140e441c0)[DAT_140e445c0] == 1) {
      FUN_1400d9b60(5,0x7c,iVar27);
    }
    if ((DAT_140e467c8 == 1) && (0x3b < (int)DAT_140e418c8)) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      FUN_14018a340(DAT_140e47204,1,1);
      DAT_140e45fac = DAT_140e45fac + 1;
      if ((&DAT_140e441c0)[DAT_140e445c0] == 0) {
        (&DAT_140e441c0)[DAT_140e445c0] = 1;
        fopen_s(&local_d8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_d8);
        FUN_140323e90(local_d8);
        DAT_140e471fc = 0xb4;
      }
    }
  }
  if (0 < DAT_140e45fac) {
    dVar34 = (double)FUN_140332d90(((double)DAT_140e45fac - 0.0) * DAT_14053a4d8 * dVar2 * dVar34);
    _DAT_1407c777c = (float)(dVar34 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    if (0x4f < DAT_140e45fac) {
      transition_tile_wipe_out_candidate(DAT_140e45fac + -0x50);
    }
    if (DAT_140e45fac < 0x78) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    else {
      FUN_1400f6fb0();
      DAT_140e418c8 = 0;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      lVar19 = DAT_140e45d78;
      while (lVar19 != 0) {
        lVar19 = *(longlong *)(lVar19 + 0x58);
        FUN_140323ce8();
      }
      DAT_140e45d78 = 0;
      DAT_140e45d28 = 0;
      DAT_140e45d1c = 0;
      lVar19 = DAT_140e47908;
      while (lVar19 != 0) {
        lVar19 = *(longlong *)(lVar19 + 0x238);
        FUN_140323ce8();
      }
      DAT_140e47908 = 0;
      DAT_140e9fd30 = 0;
      do {
        FUN_14018f230(*puVar29,0);
        puVar29 = puVar29 + 1;
      } while ((longlong)puVar29 < 0x140e45178);
      piVar17 = &DAT_140e46b04;
      DAT_140e473d4 = 1;
      do {
        if (*piVar17 == 1) {
          if (DAT_140e473d4 == 0) goto LAB_1400fe7c4;
          DAT_140e45270 = 0x2d;
          goto LAB_1400fe7fa;
        }
        DAT_140e473d4 = DAT_140e473d4 + 1;
        piVar17 = piVar17 + 1;
      } while ((longlong)piVar17 < 0x140e46b24);
      DAT_140e473d4 = 0;
LAB_1400fe7c4:
      iVar21 = result_route_predicate_candidate();
      DAT_140e45270 = 0x23;
      if (iVar21 != 0) {
        DAT_140e45270 = 0x10;
      }
    }
  }
LAB_1400fe7fa:
  DAT_140e418c8 = DAT_140e418c8 + 1;
  return;
}


