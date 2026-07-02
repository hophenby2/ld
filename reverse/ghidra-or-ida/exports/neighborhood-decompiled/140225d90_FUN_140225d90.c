// Function: FUN_140225d90 @ 140225d90
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140225d90(longlong param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  float fVar6;
  undefined2 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  longlong lVar15;
  ulonglong *puVar16;
  int *piVar17;
  undefined8 *puVar18;
  uint *puVar19;
  longlong lVar20;
  uint *puVar21;
  ulonglong *puVar22;
  ulonglong uVar23;
  undefined8 uVar24;
  longlong lVar25;
  uint uVar26;
  ulonglong uVar27;
  ulonglong *puVar28;
  ulonglong *puVar29;
  uint uVar30;
  undefined1 auStack_1588 [32];
  undefined *local_1568;
  undefined4 local_1560;
  undefined4 local_1558;
  uint local_1548;
  int local_1544;
  int local_1540;
  ulonglong *local_1538;
  longlong local_1530;
  int local_1528;
  undefined8 local_1518;
  undefined8 local_1510;
  int local_1508;
  uint local_1504;
  int local_1500;
  int local_14fc;
  int local_14f8;
  int local_14f4;
  int local_14f0;
  int local_14ec;
  uint local_14e0 [2];
  undefined4 uStack_14d8;
  undefined4 auStack_14d4 [2];
  undefined4 uStack_14cc;
  undefined4 uStack_14c8;
  undefined4 uStack_14b8;
  undefined4 local_14b0;
  undefined4 uStack_14ac;
  undefined4 uStack_14a8;
  undefined4 local_1490;
  undefined4 uStack_148c;
  undefined4 uStack_1488;
  undefined8 local_13d8;
  undefined1 local_12d8 [80];
  undefined4 local_1288;
  undefined4 uStack_1284;
  undefined4 uStack_1280;
  undefined4 uStack_127c;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  ulonglong local_2c8 [18];
  short local_232;
  ulonglong local_48;
  
  fVar6 = DAT_14053adec;
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_1588;
  local_1538 = (ulonglong *)0x0;
  local_2c8[0] = 0;
  local_2c8[1] = 0;
  local_2c8[2] = 0;
  local_2c8[3] = 0;
  local_2c8[4] = 0;
  local_2c8[5] = 0;
  local_2c8[6] = 0;
  local_2c8[7] = 0;
  local_2c8[8] = 0;
  local_2c8[9] = 0;
  local_2c8[10] = 0;
  local_2c8[0xb] = 0;
  local_2c8[0xc] = 0;
  local_2c8[0xd] = 0;
  local_2c8[0xe] = 0;
  local_2c8[0xf] = 0;
  local_1530 = 0;
  local_1528 = 0;
  local_2d8 = 0;
  uStack_2d0 = 0;
  if (DAT_140ca5960 == 0) {
    return 0xffffffff;
  }
  if (((DAT_1407cd8d4 == 0) || (DAT_140ca5a30 != 0)) || (iVar12 = 1, param_4 == 0)) {
    iVar12 = 0;
  }
  puVar14 = auStack_14d4;
  lVar15 = 0x10;
  if (DAT_140d3ae10 != 0) {
    iVar12 = 0;
  }
  do {
    *puVar14 = 0;
    puVar14 = puVar14 + 8;
    lVar15 = lVar15 + -1;
  } while (lVar15 != 0);
  uVar26 = 2;
  local_1508 = 0;
  local_14f4 = -1;
  local_14f0 = -1;
  local_14ec = -1;
  local_1540 = 0;
  local_1544 = iVar12;
  if (param_1 != 0) {
    uVar26 = *(uint *)(param_1 + 0x30);
    uVar27 = (ulonglong)uVar26;
    local_1548 = uVar26;
    FUN_1401ae2f0(&local_1518,param_1,0x38);
    puVar28 = (ulonglong *)(param_1 + 0x38);
    local_1540 = param_2;
    local_1538 = puVar28;
    if (param_3 == 0) {
      if (uVar26 != 0) {
        puVar16 = local_2c8;
        uVar23 = uVar27;
        do {
          uVar2 = *puVar28;
          puVar28 = puVar28 + 4;
          *puVar16 = uVar2;
          puVar16 = puVar16 + 1;
          uVar23 = uVar23 - 1;
        } while (uVar23 != 0);
      }
    }
    else if (uVar26 != 0) {
      puVar16 = local_2c8;
      uVar27 = (ulonglong)uVar26;
      do {
        if ((((DAT_140987e88 == 0) || ((*puVar28 & 0x80000000) != 0)) ||
            ((uVar26 = (uint)*puVar28,
             (ulonglong)(uVar26 & 0x7c000000) != (longlong)(int)DAT_140987ed8 ||
             (((longlong)DAT_140987ee0 <= (longlong)(ulonglong)(uVar26 & 0x3ffff) ||
              (piVar17 = *(int **)(DAT_140987e90 + (ulonglong)(uVar26 & 0x3ffff) * 8),
              piVar17 == (int *)0x0)))))) ||
           ((longlong)(*piVar17 << 0x12) != (ulonglong)(uVar26 & 0x3fc0000))) {
LAB_140225ffa:
          if (((DAT_14098ba90 == 0) ||
              ((((*puVar28 & 0x80000000) != 0 ||
                (uVar26 = (uint)*puVar28,
                (ulonglong)(uVar26 & 0x7c000000) != (longlong)(int)DAT_14098bae0)) ||
               ((longlong)DAT_14098bae8 <= (longlong)(ulonglong)(uVar26 & 0x3ffff))))) ||
             ((piVar17 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar26 & 0x3ffff) * 8),
              piVar17 == (int *)0x0 ||
              ((longlong)(*piVar17 << 0x12) != (ulonglong)(uVar26 & 0x3fc0000))))) {
LAB_1402260ad:
            *puVar16 = 0;
          }
          else {
            if (piVar17[6] != 0) {
              if ((piVar17[6] < 2) && (-1 < piVar17[8])) {
                iVar8 = FUN_1401afbe0();
              }
              else {
                iVar8 = FUN_1401b82b0((uint)*puVar28);
              }
              if ((iVar8 < 0) ||
                 (*(longlong *)(DAT_14098ba98 + (ulonglong)((uint)*puVar28 & 0x3ffff) * 8) == 0))
              goto LAB_1402260ad;
            }
            *puVar16 = **(ulonglong **)(piVar17 + 0x128);
          }
        }
        else {
          if (piVar17[6] != 0) {
            if ((piVar17[6] < 2) && (-1 < piVar17[8])) {
              iVar8 = FUN_1401afbe0();
            }
            else {
              iVar8 = FUN_1401b82b0((uint)*puVar28);
            }
            if ((iVar8 < 0) ||
               (*(longlong *)(DAT_140987e90 + (ulonglong)((uint)*puVar28 & 0x3ffff) * 8) == 0))
            goto LAB_140225ffa;
          }
          *puVar16 = *(ulonglong *)**(undefined8 **)(piVar17 + 0x5c);
        }
        puVar28 = puVar28 + 4;
        puVar16 = puVar16 + 1;
        uVar27 = uVar27 - 1;
      } while (uVar27 != 0);
      uVar27 = (ulonglong)local_1548;
    }
    goto LAB_1402260d1;
  }
  if ((DAT_140d3ae18 == 0) && (DAT_140d3adc8 == 0)) {
    if (DAT_140d3adcc == 0) {
      return 0xffffffff;
    }
    if (DAT_140d3adcc == 1) {
      if (DAT_140d3ae10 == 0) {
        FUN_1402229e0(0,DAT_140d3ae08);
        FUN_1402229e0(0x101,DAT_140d3ae08);
        DAT_140d7aab0 = DAT_140d3ae08;
      }
      else {
        if (iVar12 != 0) {
LAB_140226216:
          FUN_1402229e0(0,DAT_140d3ae08);
          FUN_1402229e0(0x101,DAT_140d3ae08);
          DAT_140d7aab0 = DAT_140d3ae08;
          FUN_1402229e0(1,DAT_140d3ae10);
          FUN_1402229e0(0x102,DAT_140d3ae10);
          _DAT_140d3adc8 = _DAT_140d3adc8 & 0xffffffff;
          DAT_140d3ad94 = 1;
          DAT_140d7aad0 = DAT_140d3ae10;
          return 0;
        }
        if (DAT_140d3ade8 == 0) {
          FUN_1402229e0(0,DAT_140d3ae10);
          FUN_1402229e0(0x101,DAT_140d3ae10);
          DAT_140d7aab0 = DAT_140d3ae10;
          FUN_1402229e0(1,DAT_140d3ae08);
          FUN_1402229e0(0x102,DAT_140d3ae08);
          DAT_140d7aad0 = DAT_140d3ae08;
          FUN_1402229e0(3);
          FUN_1402229e0(0x104,DAT_140d3ae08);
          _DAT_140d3adc8 = _DAT_140d3adc8 & 0xffffffff;
          DAT_140d3ad94 = 1;
          _DAT_140d7ab10 = DAT_140d3ae08;
          return 0;
        }
        if (DAT_140d3ade8 == 1) {
          FUN_1402229e0(0,DAT_140d3ae10);
          FUN_1402229e0(0x101,DAT_140d3ae10);
          DAT_140d7aab0 = DAT_140d3ae10;
          if (DAT_140d3ad98 != 1) {
            FUN_1402229e0(1,DAT_140d3ae08);
            FUN_1402229e0(0x102,DAT_140d3ae08);
            _DAT_140d3adc8 = _DAT_140d3adc8 & 0xffffffff;
            DAT_140d3ad94 = 1;
            DAT_140d7aad0 = DAT_140d3ae08;
            return 0;
          }
          FUN_1402229e0(2,DAT_140d3ae08);
          FUN_1402229e0(0x103,DAT_140d3ae08);
          DAT_140d7aaf0 = DAT_140d3ae08;
        }
        else if (DAT_140d3ade8 == 2) goto LAB_140226216;
      }
      _DAT_140d3adc8 = _DAT_140d3adc8 & 0xffffffff;
      DAT_140d3ad94 = 1;
      return 0;
    }
  }
  uVar9 = 1;
  _DAT_140d3adc8 = 0;
  DAT_140d3ad94 = 1;
  iVar8 = DAT_140d3ada8;
  if (DAT_140d3ada8 == 0) {
    if (DAT_1407cdce4 != 0) {
      iVar8 = 0xe;
    }
    if (DAT_140d3ae08 == 0) goto LAB_140226558;
    if (DAT_140d3ae10 == 0) {
joined_r0x00014022654a:
      if (DAT_140d3ad98 != 1) goto LAB_140226558;
    }
    else if (DAT_140d3ade8 == 0) {
LAB_140226488:
      if (DAT_140d3ad9c != 1) goto joined_r0x00014022654a;
    }
    else if (DAT_140d3ade8 != 1) {
      if (DAT_140d3ade8 != 2) goto LAB_140226558;
      goto LAB_140226488;
    }
    iVar8 = 1;
LAB_140226497:
    lVar15 = (longlong)iVar8 * 0x2c;
    local_14fc = *(int *)(&DAT_1404e59d4 + lVar15);
    local_1500 = *(int *)(&DAT_1404e59d0 + lVar15);
    local_14f8 = *(int *)(&DAT_1404e59d8 + lVar15);
    local_14f0 = *(int *)(&DAT_1404e59e0 + lVar15);
    local_14f4 = *(int *)(&DAT_1404e59dc + lVar15);
    local_14ec = *(int *)(&DAT_1404e59e4 + lVar15);
    iVar13 = *(int *)(&DAT_1404e59ec + lVar15);
  }
  else {
    if ((DAT_140d3ada8 == 3) && (DAT_140ca5b94 != 0)) {
      iVar8 = 0x10;
      goto LAB_140226497;
    }
LAB_140226558:
    if (iVar8 != 0x20) goto LAB_140226497;
    local_14fc = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adb4 * 4);
    local_1500 = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adb0 * 4);
    local_14f8 = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adb8 * 4);
    local_14f0 = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adc0 * 4);
    local_14f4 = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adbc * 4);
    local_14ec = *(int *)(&DAT_1404e6058 + (longlong)DAT_140d3adc4 * 4);
    iVar13 = DAT_140d3adac;
  }
  local_1510 = CONCAT44(iVar13,(int)local_1510);
  lVar15 = (longlong)iVar8 * 0x2c;
  local_1504 = 0xffffffff;
  local_1508 = *(int *)(&DAT_1404e59f0 + lVar15);
  if (DAT_140d3ae08 != 0) {
    uVar11 = 0;
    uVar30 = DAT_140d3ade8 + 1;
    if (DAT_140d3ae10 == 0) {
      uVar30 = uVar11;
    }
    if ((DAT_140d3ad98 == 0) && (DAT_140d3ad9c == 0)) {
      if (DAT_140d82034 == 0) goto LAB_14022688b;
      if (uVar30 == 0) goto LAB_140226880;
LAB_140226893:
      lVar15 = (longlong)*(int *)(&UNK_1404e59e8 + lVar15);
      if (iVar12 == 0) {
        local_1538 = (ulonglong *)local_14e0;
        lVar20 = 4;
        puVar28 = (ulonglong *)
                  (&DAT_1404bb930 +
                  (((longlong)DAT_140d3addc +
                   ((longlong)DAT_140d3add8 + ((longlong)(int)uVar30 + lVar15 * 4) * 2) * 2) * 3 +
                  (ulonglong)uVar11) * 0x200);
        puVar16 = (ulonglong *)local_14e0;
        do {
          uVar27 = puVar28[1];
          uVar23 = puVar28[2];
          uVar2 = puVar28[3];
          *puVar16 = *puVar28;
          puVar16[1] = uVar27;
          uVar27 = puVar28[4];
          uVar4 = puVar28[5];
          puVar16[2] = uVar23;
          puVar16[3] = uVar2;
          uVar23 = puVar28[6];
          uVar2 = puVar28[7];
          puVar16[4] = uVar27;
          puVar16[5] = uVar4;
          uVar27 = puVar28[8];
          uVar4 = puVar28[9];
          puVar16[6] = uVar23;
          puVar16[7] = uVar2;
          uVar23 = puVar28[10];
          uVar2 = puVar28[0xb];
          puVar16[8] = uVar27;
          puVar16[9] = uVar4;
          uVar4 = puVar28[0xc];
          uVar10 = *(undefined4 *)((longlong)puVar28 + 100);
          uVar5 = puVar28[0xd];
          uVar3 = *(undefined4 *)((longlong)puVar28 + 0x6c);
          puVar16[10] = uVar23;
          puVar16[0xb] = uVar2;
          uVar27 = puVar28[0xe];
          uVar23 = puVar28[0xf];
          *(int *)(puVar16 + 0xc) = (int)uVar4;
          *(undefined4 *)((longlong)puVar16 + 100) = uVar10;
          *(int *)(puVar16 + 0xd) = (int)uVar5;
          *(undefined4 *)((longlong)puVar16 + 0x6c) = uVar3;
          puVar16[0xe] = uVar27;
          puVar16[0xf] = uVar23;
          lVar20 = lVar20 + -1;
          puVar28 = puVar28 + 0x10;
          puVar16 = puVar16 + 0x10;
          uVar9 = local_14e0[0];
        } while (lVar20 != 0);
      }
      else {
        local_2c8[0] = DAT_140d3ae08;
        local_2c8[2] = 0;
        local_2c8[1] = DAT_140d3ae10;
        uVar9 = uVar26;
      }
      local_2c8[2] = 0;
      DAT_140d7aa60 = 2;
      DAT_140d3ae20 = *(undefined8 *)(&DAT_140d3ae38 + (longlong)DAT_140d7aa58 * 0x18);
      if (DAT_140d3ade8 == 0) {
        lVar20 = 0;
        DAT_140d7aa70 = 0;
        if (((DAT_140d3ad9c == 1) || (iVar13 == 1)) || (DAT_140d3ad98 == 1)) {
          local_1518 = 1;
          iVar8 = 5;
        }
        else {
          local_1518 = (ulonglong)DAT_140d7aa7c << 0x20;
          iVar8 = DAT_140d7aa80;
        }
        local_1510 = CONCAT44(iVar13,iVar8);
        local_1504 = DAT_140d3adec << 0x18 | 0xffffff;
        if (iVar12 == 0) {
          local_2c8[0] = DAT_140d3ae10;
          local_2c8[1] = DAT_140d3ae08;
          local_2c8[2] = 0;
          uVar26 = DAT_140d7aa60;
          if (DAT_140d3add4 != 0) {
            uStack_14cc = uStack_14cc & 0xffff;
            uStack_14c8 = 0x2ffff;
            uStack_14ac = CONCAT22(1,(undefined2)uStack_14ac);
            uStack_14a8 = 0x2ffff;
            if (uVar9 == 3) {
              uStack_148c = CONCAT22(1,(undefined2)uStack_148c);
              uStack_1488 = 0x2ffff;
            }
          }
        }
        else {
          if (uVar11 == 0) {
            lVar20 = 0x10;
          }
          local_1530 = *(longlong *)
                        (&DAT_140ccd6d8 +
                        ((ulonglong)(DAT_140d3add4 != 0) + lVar15 * 2) * 0x20 + lVar20);
LAB_140226a44:
          DAT_140d7aa70 = 0;
          uVar26 = DAT_140d7aa60;
        }
      }
      else if (DAT_140d3ade8 == 1) {
        DAT_140d7aa70 = (uint)(DAT_140d3adf0 == 0xff);
        if (iVar12 == 0) {
          local_2c8[0] = DAT_140d3ae10;
          if (DAT_140d3ad98 == 1) {
            local_2c8[1] = 0;
            local_2c8[2] = DAT_140d3ae08;
          }
          else {
            local_2c8[1] = DAT_140d3ae08;
          }
        }
        else {
          local_1528 = 1;
          lVar20 = 0;
          if (uVar11 == 0) {
            lVar20 = 0x10;
          }
          local_1530 = *(longlong *)
                        (&DAT_140ccd898 +
                        ((ulonglong)(DAT_140d3add4 != 0) + lVar15 * 2) * 0x20 + lVar20);
        }
        uStack_2d0 = 0;
        local_2d8 = 0;
        if (DAT_140d3adf4 < 2) {
          local_1518 = CONCAT44(DAT_140d3adf0,1);
          local_1510 = 7;
          if (iVar12 == 0) {
            local_1504 = 0xffffff;
          }
          else {
            uStack_2d0 = (ulonglong)DAT_140539da8;
          }
          if (((DAT_140d3ad98 != 0) || (DAT_140d3ad9c != 0)) && (DAT_140d3adf0 == 0)) {
            local_1518 = 0x100000001;
          }
LAB_140226f62:
          if (iVar12 != 0) goto LAB_140226a4f;
        }
        else {
          local_1518 = (ulonglong)DAT_140d7aa7c << 0x20;
          local_1510 = CONCAT44(1,DAT_140d7aa80);
          if (DAT_140d3adf4 < 0x41) {
            uStack_14ac = CONCAT22(uStack_14ac._2_2_,6);
            iVar8 = -((DAT_140d3adf0 * 0x500) / 0xff);
            iVar13 = iVar8 + 0x500;
            uVar30 = DAT_14053a770;
            if (iVar13 < 0x400) {
              iVar13 = iVar13 * 0xff;
              uVar11 = ((int)(iVar13 + (iVar13 >> 0x1f & 0x3ffU)) >> 10) * -0x1000000 - 0x1000000;
              local_1504 = uVar11 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,10);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 >> 0x18) / _DAT_1404ad224;
LAB_140226f5a:
                uStack_2d0 = CONCAT44(uStack_2d0._4_4_,uVar30);
                goto LAB_140226f62;
              }
            }
            else {
              iVar8 = (iVar8 + 0x100) * 0x40;
              uVar11 = (int)((iVar8 >> 0x1f & 0xffU) + iVar8) >> 8;
              local_1504 = uVar11 << 0x18 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,7);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 & 0xff) / DAT_14053adec;
                goto LAB_140226f5a;
              }
            }
          }
          else if (DAT_140d3adf4 < 0x81) {
            uStack_14ac = CONCAT22(uStack_14ac._2_2_,5);
            iVar8 = -((DAT_140d3adf0 * 0x300) / 0xff);
            iVar13 = iVar8 + 0x300;
            uVar30 = DAT_140539fc0;
            if (iVar13 < 0x200) {
              iVar13 = iVar13 * 0xff;
              uVar11 = ((int)(iVar13 + (iVar13 >> 0x1f & 0x1ffU)) >> 9) * -0x1000000 - 0x1000000;
              local_1504 = uVar11 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,10);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 >> 0x18) / _DAT_1404ad224;
                goto LAB_140226f5a;
              }
            }
            else {
              iVar8 = (iVar8 + 0x100) * 0x80;
              uVar11 = (int)((iVar8 >> 0x1f & 0xffU) + iVar8) >> 8;
              local_1504 = uVar11 << 0x18 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,7);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 & 0xff) / DAT_14053adec;
                goto LAB_140226f5a;
              }
            }
          }
          else {
            uStack_14ac = CONCAT22(uStack_14ac._2_2_,4);
            iVar8 = -((DAT_140d3adf0 * 0x200) / 0xff);
            iVar13 = iVar8 + 0x200;
            uVar30 = DAT_140539da8;
            if (iVar13 < 0x100) {
              iVar13 = iVar13 * 0xff;
              uVar11 = ((int)(iVar13 + (iVar13 >> 0x1f & 0xffU)) >> 8) * -0x1000000 - 0x1000000;
              local_1504 = uVar11 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,10);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 >> 0x18) / _DAT_1404ad224;
                goto LAB_140226f5a;
              }
            }
            else {
              iVar8 = (iVar8 + 0x100) * 0xff;
              uVar11 = (int)((iVar8 >> 0x1f & 0xffU) + iVar8) >> 8;
              local_1504 = uVar11 << 0x18 | 0xffffff;
              uStack_14cc = CONCAT22(uStack_14cc._2_2_,7);
              if (iVar12 != 0) {
                uStack_2d0._4_4_ = (float)(uVar11 & 0xff) / DAT_14053adec;
                goto LAB_140226f5a;
              }
            }
          }
        }
        if (DAT_140d3add4 != 0) {
          lVar15 = (ulonglong)((DAT_140d3ad98 == 1) + 1) * 0x20;
          sVar1 = *(short *)((longlong)&uStack_14cc + lVar15 + 2);
          if (sVar1 == 2) {
            if (*(short *)((longlong)&uStack_14c8 + lVar15 + 2) == 2) {
              *(undefined2 *)((longlong)&uStack_14cc + lVar15 + 2) = 1;
              uVar26 = DAT_140d7aa60;
            }
            else {
LAB_140226fcd:
              uVar26 = DAT_140d7aa60;
              if ((ushort)(*(short *)((longlong)&uStack_14c8 + lVar15 + 2) - 4U) < 3) {
                *(undefined2 *)((longlong)&uStack_14c8 + lVar15 + 2) = 3;
              }
            }
          }
          else if (sVar1 == 0x12) {
            uVar26 = DAT_140d7aa60;
            if (*(short *)((longlong)&uStack_14c8 + lVar15 + 2) == 2) {
              *(undefined2 *)((longlong)&uStack_14cc + lVar15 + 2) = 0x11;
            }
          }
          else {
            uVar26 = DAT_140d7aa60;
            if (sVar1 == 2) goto LAB_140226fcd;
          }
        }
      }
      else if (DAT_140d3ade8 == 2) {
        lVar20 = 0;
        DAT_140d7aa70 = 0;
        if (iVar13 == 1) {
          local_1518 = 1;
          iVar8 = 5;
        }
        else {
          local_1518 = (ulonglong)DAT_140d7aa7c << 0x20;
          iVar8 = DAT_140d7aa80;
        }
        local_1510 = CONCAT44(iVar13,iVar8);
        if (iVar12 != 0) {
          if (uVar11 == 0) {
            lVar20 = 0x10;
          }
          local_1530 = *(longlong *)
                        (&DAT_140ccda58 +
                        ((ulonglong)(DAT_140d3add4 != 0) + lVar15 * 2) * 0x20 + lVar20);
          goto LAB_140226a44;
        }
        local_2c8[0] = DAT_140d3ae08;
        local_2c8[1] = DAT_140d3ae10;
        local_2c8[2] = 0;
        if (DAT_140d3add4 != 0) {
          uStack_14cc = uStack_14cc & 0xffff;
          uVar26 = DAT_140d7aa60;
        }
      }
    }
    else {
LAB_140226880:
      uVar11 = 2 - (DAT_140d3ad98 != 0);
LAB_14022688b:
      if (uVar30 != 0) goto LAB_140226893;
      DAT_140d7aa70 = 0;
      DAT_140d7aa60 = 1;
      DAT_140d3ae20 = (&DAT_140d3ae30)[(longlong)DAT_140d7aa58 * 3];
      if (iVar12 == 0) {
        local_1538 = (ulonglong *)
                     (&DAT_1404bb930 +
                     (((longlong)DAT_140d3addc +
                      ((longlong)DAT_140d3add8 + (longlong)*(int *)(&UNK_1404e59e8 + lVar15) * 8) *
                      2) * 3 + (ulonglong)uVar11) * 0x200);
        uVar9 = (uint)*local_1538;
        if (DAT_140d3add4 != 0) {
          FUN_1401ae2f0(local_2c8 + 0x10,local_1538);
          if (local_232 == 2) {
            local_232 = 3;
          }
          else if (local_232 == 0x12) {
            local_232 = 0x13;
          }
          local_1538 = local_2c8 + 0x10;
        }
      }
      else {
        lVar20 = 0;
        if (uVar11 == 0) {
          lVar20 = 0x10;
        }
        local_1530 = *(longlong *)
                      ((longlong)&DAT_140ccd518 +
                      ((ulonglong)(DAT_140d3add4 != 0) +
                      (longlong)*(int *)(&UNK_1404e59e8 + lVar15) * 2) * 0x20 + lVar20);
      }
      uVar26 = DAT_140d7aa60;
      local_2c8[0] = DAT_140d3ae08;
      if (DAT_140d3ad9c == 1) {
        local_1510 = CONCAT44(local_1510._4_4_,5);
        local_1518 = 0x1000000001;
      }
      else if ((local_1510._4_4_ == 1) && (*(int *)(&UNK_1404e59f8 + lVar15) == 1)) {
        local_1518 = 1;
        local_1510 = 0x100000005;
      }
      else {
        local_1510 = CONCAT44(local_1510._4_4_,DAT_140d7aa80);
        local_1518 = (ulonglong)DAT_140d7aa7c << 0x20;
      }
    }
    goto LAB_140226a4f;
  }
  piVar17 = (int *)0x0;
  DAT_140d7aa70 = 0;
  if (iVar12 != 0) {
    local_1530 = (&DAT_140ccd4a8)[(longlong)*(int *)(&UNK_1404e59e8 + lVar15) * 2];
    uVar9 = 0;
    goto LAB_14022681c;
  }
  if (iVar8 == 3) {
    local_1538 = (ulonglong *)&DAT_1404bb730;
    goto LAB_14022681c;
  }
  uStack_14d8 = 0;
  uStack_14b8 = 0;
  local_14b0 = 0;
  uStack_14ac = 1;
  uStack_14a8 = 0x10000;
  switch(*(undefined4 *)(&UNK_1404e59e8 + lVar15)) {
  case 0:
    uStack_14c8 = 0x30000;
    break;
  case 1:
    uStack_14c8 = 0xc0003;
    break;
  case 2:
    uStack_14cc = 0x100003;
    uStack_14c8 = 0x20000;
    goto LAB_140226808;
  case 3:
    if (((DAT_140987e88 != 0) && (uVar26 = FUN_14014e6d0(), (uVar26 & 0x80000000) == 0)) &&
       ((uVar26 = FUN_14014e6d0(), (uVar26 & 0x7c000000) == DAT_140987ed8 &&
        (uVar26 = FUN_14014e6d0(), (int)(uVar26 & 0x3ffff) < DAT_140987ee0)))) {
      uVar26 = FUN_14014e6d0();
      piVar17 = *(int **)(DAT_140987e90 + (ulonglong)(uVar26 & 0x3ffff) * 8);
      if (((piVar17 != (int *)0x0) &&
          (uVar26 = FUN_14014e6d0(), *piVar17 << 0x12 == (uVar26 & 0x3fc0000))) && (piVar17[6] != 0)
         ) {
        if ((piVar17[6] < 2) && (-1 < piVar17[8])) {
          iVar8 = FUN_1401afbe0();
        }
        else {
          uVar10 = FUN_14014e6d0();
          iVar8 = FUN_1401b82b0(uVar10);
        }
        if (-1 < iVar8) {
          FUN_14014e6d0();
        }
      }
    }
    FUN_140223970();
    local_2c8[0] = **(ulonglong **)(*(longlong *)(piVar17 + 0x28) + 0x50);
    goto LAB_1402267f3;
  case 4:
    uStack_14c8 = 0x40020;
    break;
  case 5:
    uStack_14cc = 0x100003;
    uStack_14c8 = 0x40020;
    goto LAB_140226808;
  case 6:
    if (((DAT_140987e88 != 0) && (uVar9 = FUN_14014e6d0(), (uVar9 & 0x80000000) == 0)) &&
       ((uVar9 = FUN_14014e6d0(), (uVar9 & 0x7c000000) == DAT_140987ed8 &&
        (uVar9 = FUN_14014e6d0(), (int)(uVar9 & 0x3ffff) < DAT_140987ee0)))) {
      uVar9 = FUN_14014e6d0();
      piVar17 = *(int **)(DAT_140987e90 + (ulonglong)(uVar9 & 0x3ffff) * 8);
      if (((piVar17 != (int *)0x0) &&
          (uVar9 = FUN_14014e6d0(), *piVar17 << 0x12 == (uVar9 & 0x3fc0000))) && (piVar17[6] != 0))
      {
        if ((piVar17[6] < 2) && (-1 < piVar17[8])) {
          iVar8 = FUN_1401afbe0();
        }
        else {
          uVar10 = FUN_14014e6d0();
          iVar8 = FUN_1401b82b0(uVar10);
        }
        if (-1 < iVar8) {
          FUN_14014e6d0();
        }
      }
    }
    FUN_140223970();
    local_2c8[0] = **(ulonglong **)(*(longlong *)(piVar17 + 0x28) + 0x50);
    local_14b0 = 1;
    uStack_148c = 1;
    uStack_14ac = 0x10002;
    uStack_14a8 = 0x40020;
    local_1490 = 0;
    uStack_1488 = 0x10000;
    uVar9 = uVar26;
LAB_1402267f3:
    uStack_14c8 = 0x60002;
    break;
  default:
    goto switchD_14022661e_default;
  }
  uStack_14cc = 3;
LAB_140226808:
  auStack_14d4[1] = 0;
switchD_14022661e_default:
  local_1538 = (ulonglong *)local_14e0;
LAB_14022681c:
  local_1510 = CONCAT44(local_1510._4_4_,DAT_140d7aa80);
  DAT_140d7aa60 = 0;
  local_1518 = (ulonglong)DAT_140d7aa7c << 0x20;
  DAT_140d3ae20 = *(undefined8 *)(&DAT_140d3ae28 + (longlong)DAT_140d7aa58 * 0x18);
  uVar26 = DAT_140d7aa60;
LAB_140226a4f:
  DAT_140d7aa60 = uVar26;
  iVar8 = DAT_140d3ae18;
  DAT_140d3ae18 = 1;
  if (uVar9 != DAT_140d7aaa8) {
    DAT_140d7aaa8 = uVar9;
    FUN_1402288b0(DAT_140d7acb8);
    FUN_140229b10(DAT_140d81988,0xffffffff);
  }
  local_1548 = uVar9 + 1;
  if (0xf < uVar9) {
    local_1548 = uVar9;
  }
  if (DAT_140d3ada0 != -1) {
    local_1510 = CONCAT44(local_1510._4_4_,DAT_140d3ada0);
    local_1518 = CONCAT44(DAT_140d3ada4,1);
  }
  DAT_140d3ae18 = iVar8;
  if (0 < DAT_1407cdd50) {
    uVar26 = 8;
    lVar20 = 0;
    puVar28 = local_2c8 + 8;
    lVar15 = (longlong)&local_13d8 + 4;
    lVar25 = 3;
    do {
      *(undefined8 *)(lVar15 + -4) = 0;
      if (((DAT_14098ba90 == 0) ||
          (uVar9 = *(uint *)((longlong)&DAT_1407cdd44 + lVar20), (int)uVar9 < 0)) ||
         (((uVar9 & 0x7c000000) != DAT_14098bae0 ||
          (((DAT_14098bae8 <= (int)(uVar9 & 0x3ffff) ||
            (piVar17 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar9 & 0x3ffff) * 8),
            piVar17 == (int *)0x0)) || (*piVar17 << 0x12 != (uVar9 & 0x3fc0000))))))) {
LAB_1402272b4:
        *puVar28 = 0;
        uVar9 = local_1548;
      }
      else {
        if (piVar17[6] != 0) {
          if ((piVar17[6] < 2) && (-1 < piVar17[8])) {
            iVar12 = FUN_1401afbe0();
          }
          else {
            iVar12 = FUN_1401b82b0(uVar9);
          }
          if ((iVar12 < 0) ||
             (*(longlong *)
               (DAT_14098ba98 +
               (ulonglong)(*(uint *)((longlong)&DAT_1407cdd44 + lVar20) & 0x3ffff) * 8) == 0))
          goto LAB_1402272b4;
        }
        *puVar28 = **(ulonglong **)(piVar17 + 0x128);
        FUN_14022a4f0(3,uVar26);
        FUN_14022a6c0(3,uVar26);
        FUN_14022a840(3,uVar26);
        if ((DAT_140ca5960 != 0) && (uVar26 < 0x10)) {
          DAT_140d7acb8 = 3;
          DAT_140d3ad94 = 1;
          if (*(int *)((longlong)&DAT_140d81a2c + lVar20) != 2) {
            FUN_140222970(uVar26,6,2);
            *(undefined4 *)((longlong)&DAT_140d81a2c + lVar20) = 2;
          }
        }
        FUN_140229ec0(uVar26,0x10);
        if ((DAT_140ca5960 != 0) && (uVar26 < 0x10)) {
          DAT_140d7acb8 = 3;
          DAT_140d3ad94 = 1;
          if (*(int *)((longlong)&DAT_140d81a6c + lVar20) != 2) {
            FUN_140222970(uVar26,7);
            *(undefined4 *)((longlong)&DAT_140d81a6c + lVar20) = 2;
          }
        }
        uVar9 = uVar26 + 1;
        if (uVar26 + 1 <= local_1548) {
          uVar9 = local_1548;
        }
      }
      local_1548 = uVar9;
      uVar26 = uVar26 + 1;
      lVar15 = lVar15 + 0x20;
      puVar28 = puVar28 + 1;
      lVar20 = lVar20 + 4;
      lVar25 = lVar25 + -1;
      iVar12 = local_1544;
    } while (lVar25 != 0);
  }
  uVar27 = (ulonglong)local_1548;
  if (DAT_140d3add0 != 0) {
    local_1508 = 1;
    local_14f4 = 1;
    local_14ec = 1;
    local_14f0 = 2;
  }
LAB_1402260d1:
  puVar28 = local_1538;
  iVar8 = local_1540;
  if (DAT_140d3ae18 == 1) {
    FUN_140222930(0x19);
    DAT_140d7aa80 = (int)local_1510;
    FUN_140222930(0x18,local_1518._4_4_);
    DAT_140d7aa7c = local_1518._4_4_;
    FUN_140222930(0xf,local_1518 & 0xffffffff);
    DAT_140d7aa78 = (int)local_1518;
    FUN_140222930(0x1b,local_1510._4_4_);
    iVar13 = local_1544;
    DAT_140d7aa84 = local_1510._4_4_;
    if (local_1544 == 0) {
      FUN_140222930(0x3c,local_1504);
    }
    DAT_140d7aa8c = local_1504;
    if (local_1528 == 0) {
      _DAT_140d7acbc = (float)(local_1504 & 0xff) / fVar6;
      _DAT_140d7acc0 = (float)(local_1504 >> 8 & 0xff) / fVar6;
      _DAT_140d7acc4 = (float)(local_1504 >> 0x10 & 0xff) / fVar6;
      _DAT_140d7acc8 = (float)(local_1504 >> 0x18) / fVar6;
    }
    else {
      _DAT_140d7acbc = (float)local_2d8;
      _DAT_140d7acc0 = local_2d8._4_4_;
      _DAT_140d7acc4 = (float)uStack_2d0;
      _DAT_140d7acc8 = uStack_2d0._4_4_;
    }
    local_1558 = 1;
    local_1560 = 1;
    local_1568 = &DAT_140d7acbc;
    FUN_14023dd40(&DAT_140ca5d24,3,0);
    if (local_1500 == -1) {
      if (1 < DAT_140d7aa90) {
        FUN_140222930(0x13);
      }
    }
    else {
      FUN_140222930(0x13);
      DAT_140d7aa90 = local_1500;
    }
    if (local_14fc == -1) {
      if (1 < DAT_140d7aa94) {
        FUN_140222930(0x14);
      }
    }
    else {
      FUN_140222930(0x14);
      DAT_140d7aa94 = local_14fc;
    }
    if (local_14f8 == -1) {
      if (1 < DAT_140d7aa98) {
        FUN_140222930(0xab);
      }
    }
    else {
      FUN_140222930(0xab);
      DAT_140d7aa98 = local_14f8;
    }
    FUN_140222930(0xce,local_1508);
    DAT_140d7aa88 = local_1508;
    if (local_14f4 == -1) {
      if (1 < DAT_140d7aa9c) {
        FUN_140222930(0xcf);
      }
    }
    else {
      FUN_140222930(0xcf);
      DAT_140d7aa9c = local_14f4;
    }
    if (local_14f0 == -1) {
      if (1 < DAT_140d7aaa0) {
        FUN_140222930(0xd0);
      }
    }
    else {
      FUN_140222930(0xd0);
      DAT_140d7aaa0 = local_14f0;
    }
    if (local_14ec == -1) {
      if (1 < DAT_140d7aaa4) {
        FUN_140222930(0xd1);
      }
    }
    else {
      FUN_140222930(0xd1);
      DAT_140d7aaa4 = local_14ec;
    }
    puVar19 = &DAT_140d7aabc;
    if (iVar13 != 0) {
      puVar28 = (ulonglong *)0x0;
    }
    uVar26 = 0;
    puVar21 = (uint *)((longlong)puVar28 + 0xc);
    puVar28 = local_2c8;
    do {
      if (uVar26 < (uint)uVar27) {
        uVar27 = *puVar28;
        FUN_1402229e0(uVar26);
        *(ulonglong *)(puVar19 + -3) = uVar27;
        if (uVar26 < 4) {
          FUN_1402229e0(uVar26 + 0x101);
        }
        if (((iVar12 == 0) && (puVar21[-1] != 0xffffffff)) && (uVar26 < DAT_140ca5b8c)) {
          FUN_140222a00(uVar26);
          puVar19[-1] = puVar21[-1];
        }
        uVar27 = (ulonglong)local_1548;
      }
      else {
        FUN_1402229e0(uVar26);
        puVar19[-3] = 0;
        puVar19[-2] = 0;
        if (uVar26 < 4) {
          FUN_1402229e0(uVar26 + 0x101);
        }
        if ((iVar12 == 0) && (uVar26 < DAT_140ca5b8c)) {
          FUN_140222a00(uVar26,0xb,0);
          puVar19[-1] = 0;
        }
      }
      if (iVar8 == 0) {
        if (iVar12 == 0) {
          if (((DAT_140d3ae18 != 0) || (DAT_140d81ab0 != 0)) && (DAT_140ca5960 != 0)) {
            if ((DAT_140d3ae18 != 0) || (DAT_140d81ab0 != 0)) {
              FUN_1402228b0(0);
              DAT_140d81ab0 = 0;
            }
            DAT_140d81aac = 0;
            DAT_140d3ad94 = 1;
          }
          if ((uVar26 < (uint)uVar27) && (uVar26 < DAT_140ca5b8c)) {
            if ((DAT_140ca5b90 != 0) && (*puVar21 != 0xffffffff)) {
              uVar24 = 1;
              if (*puVar21 != 0) {
                uVar24 = 5;
              }
              FUN_140222a00(uVar26,0x1c,uVar24);
              *puVar19 = *puVar21;
            }
            if ((short)puVar21[2] != -1) {
              FUN_140222a00(uVar26,4,(int)(short)puVar21[2]);
              *(short *)(puVar19 + 2) = (short)puVar21[2];
            }
            if ((short)puVar21[1] != -1) {
              FUN_140222a00(uVar26,5,(int)(short)puVar21[1]);
              *(short *)(puVar19 + 1) = (short)puVar21[1];
            }
            if (*(short *)((longlong)puVar21 + 6) != -1) {
              FUN_140222a00(uVar26,6,(int)*(short *)((longlong)puVar21 + 6));
              *(undefined2 *)((longlong)puVar19 + 6) = *(undefined2 *)((longlong)puVar21 + 6);
            }
            if (*(short *)((longlong)puVar21 + 0xe) != -1) {
              FUN_140222a00(uVar26,1,(int)*(short *)((longlong)puVar21 + 0xe));
              *(undefined2 *)((longlong)puVar19 + 0xe) = *(undefined2 *)((longlong)puVar21 + 0xe);
            }
            if (*(short *)((longlong)puVar21 + 10) != -1) {
              FUN_140222a00(uVar26,2,(int)*(short *)((longlong)puVar21 + 10));
              *(undefined2 *)((longlong)puVar19 + 10) = *(undefined2 *)((longlong)puVar21 + 10);
            }
            if ((short)puVar21[3] == -1) goto LAB_1402278f8;
            FUN_140222a00(uVar26,3,(int)(short)puVar21[3]);
            uVar7 = (undefined2)puVar21[3];
          }
          else {
            if (DAT_140ca5b90 != 0) {
              FUN_140222a00(uVar26,0x1c,1);
              *puVar19 = 0;
            }
            FUN_140222a00(uVar26,4,1);
            *(undefined2 *)(puVar19 + 2) = 1;
            FUN_140222a00(uVar26,5,0);
            *(undefined2 *)(puVar19 + 1) = 0;
            FUN_140222a00(uVar26,6,0);
            *(undefined2 *)((longlong)puVar19 + 6) = 0;
            FUN_140222a00(uVar26,1,1);
            *(undefined2 *)((longlong)puVar19 + 0xe) = 1;
            FUN_140222a00(uVar26,2,0);
            *(undefined2 *)((longlong)puVar19 + 10) = 0;
            FUN_140222a00(uVar26,3,0);
            uVar7 = 0;
          }
          *(undefined2 *)(puVar19 + 3) = uVar7;
        }
        else if ((uVar26 == 0) &&
                (((DAT_140d81ab0 != local_1530 || (DAT_140d3ae18 != 0)) && (DAT_140ca5960 != 0)))) {
          FUN_1402228b0(local_1530);
          DAT_140d81ab0 = local_1530;
          DAT_140d81aac = 1;
        }
      }
LAB_1402278f8:
      uVar26 = uVar26 + 1;
      puVar28 = puVar28 + 1;
      puVar21 = puVar21 + 8;
      puVar19 = puVar19 + 8;
    } while (uVar26 < 0x10);
  }
  else {
    if ((int)local_1510 != DAT_140d7aa80) {
      FUN_140222930(0x19);
      DAT_140d7aa80 = (int)local_1510;
    }
    if (local_1518._4_4_ != DAT_140d7aa7c) {
      FUN_140222930(0x18);
      DAT_140d7aa7c = local_1518._4_4_;
    }
    if ((int)local_1518 != DAT_140d7aa78) {
      FUN_140222930(0xf);
      DAT_140d7aa78 = (int)local_1518;
    }
    if (local_1510._4_4_ != DAT_140d7aa84) {
      FUN_140222930(0x1b);
      DAT_140d7aa84 = local_1510._4_4_;
    }
    iVar8 = local_1544;
    if (local_1504 != DAT_140d7aa8c) {
      if (local_1544 == 0) {
        FUN_140222930(0x3c,local_1504);
      }
      DAT_140d7aa8c = local_1504;
    }
    if (local_1528 == 0) {
      local_2d8 = CONCAT44((float)(local_1504 >> 8 & 0xff) / fVar6,
                           (float)(local_1504 & 0xff) / fVar6);
      uStack_2d0 = CONCAT44((float)(local_1504 >> 0x18) / fVar6,
                            (float)(local_1504 >> 0x10 & 0xff) / fVar6);
    }
    iVar13 = FUN_1401ae2b0(&DAT_140d7acbc,&local_2d8,0x10);
    if (iVar13 != 0) {
      FUN_1401ae2f0(&DAT_140d7acbc,&local_2d8,0x10);
      FUN_14023e510(&DAT_140cb4dc8,1,5,1);
      FUN_1401ae2f0((longlong)((int)DAT_140cb51d0 * 5) + 0x140cb51d4,&local_2d8,
                    (longlong)(int)DAT_140cb51d0);
      DAT_140cc4a5d = 1;
      if (DAT_140ca5d24 != 0) {
        puVar18 = &local_2d8;
        if ((byte)(DAT_140ccd1a5 - 1) < 0xfe) {
          puVar18 = (undefined8 *)0x0;
        }
        else {
          DAT_140ccd1a5 = 0;
        }
        if (DAT_140ca5960 != 0) {
          if (puVar18 == (undefined8 *)0x0) {
            FUN_1401ae370(local_12d8,0,0x1000);
            if (DAT_140ccd1a5 != 0xff) {
              lVar15 = (ulonglong)DAT_140ccd1a5 * 0x140c;
              local_1288 = *(undefined4 *)(&DAT_140cb5224 + lVar15);
              uStack_1284 = *(undefined4 *)(lVar15 + 0x140cb5228);
              uStack_1280 = *(undefined4 *)(lVar15 + 0x140cb522c);
              uStack_127c = *(undefined4 *)(lVar15 + 0x140cb5230);
            }
            puVar18 = (undefined8 *)&local_1288;
          }
          if (DAT_1407cd8d4 == 1) {
            FUN_1402228f0(5,puVar18);
          }
          FUN_1401ae2f0(&DAT_140cc96d8,puVar18,0x10);
        }
      }
    }
    puVar16 = (ulonglong *)0x0;
    if ((local_1500 != -1) && (local_1500 != DAT_140d7aa90)) {
      FUN_140222930(0x13);
      DAT_140d7aa90 = local_1500;
    }
    if ((local_14fc != -1) && (local_14fc != DAT_140d7aa94)) {
      FUN_140222930(0x14);
      DAT_140d7aa94 = local_14fc;
    }
    if ((local_14f8 != -1) && (local_14f8 != DAT_140d7aa98)) {
      FUN_140222930(0xab);
      DAT_140d7aa98 = local_14f8;
    }
    if (local_1508 != DAT_140d7aa88) {
      FUN_140222930(0xce);
      DAT_140d7aa88 = local_1508;
    }
    if ((local_14f4 != -1) && (local_14f4 != DAT_140d7aa9c)) {
      FUN_140222930(0xcf);
      DAT_140d7aa9c = local_14f4;
    }
    if ((local_14f0 != -1) && (local_14f0 != DAT_140d7aaa0)) {
      FUN_140222930(0xd0);
      DAT_140d7aaa0 = local_14f0;
    }
    if ((local_14ec != -1) && (local_14ec != DAT_140d7aaa4)) {
      FUN_140222930(0xd1);
      DAT_140d7aaa4 = local_14ec;
    }
    puVar22 = &DAT_140d7aab0;
    if (iVar8 != 0) {
      puVar28 = puVar16;
    }
    uVar26 = 2;
    if (DAT_1407cdd50 != 0) {
      uVar26 = (uint)uVar27;
    }
    if ((uint)uVar27 != 0) {
      puVar28 = puVar28 + 1;
      puVar29 = local_2c8;
      do {
        uVar9 = (uint)puVar16;
        if (((uVar26 <= uVar9) &&
            ((iVar12 != 0 || ((uVar9 != 0 && (*(short *)((longlong)puVar28 + -0x14) == 1)))))) &&
           (local_1540 == 0)) break;
        uVar27 = *puVar29;
        if (uVar27 != *puVar22) {
          FUN_1402229e0(puVar16,uVar27);
          *puVar22 = uVar27;
          if (uVar9 < 4) {
            FUN_1402229e0(uVar9 + 0x101,uVar27);
          }
        }
        if ((((iVar12 == 0) && ((uint)*puVar28 != 0xffffffff)) &&
            ((uint)*puVar28 != (uint)puVar22[1])) && (uVar9 < DAT_140ca5b8c)) {
          FUN_140222a00(puVar16,0xb);
          *(uint *)(puVar22 + 1) = (uint)*puVar28;
        }
        lVar15 = local_1530;
        if (local_1540 == 0) {
          if (iVar12 == 0) {
            if (((DAT_140d3ae18 != 0) || (DAT_140d81ab0 != 0)) && (DAT_140ca5960 != 0)) {
              if ((DAT_140d3ae18 != 0) || (DAT_140d81ab0 != 0)) {
                FUN_1402228b0(0);
                DAT_140d81ab0 = 0;
              }
              DAT_140d81aac = 0;
              DAT_140d3ad94 = 1;
            }
            if (uVar9 < DAT_140ca5b8c) {
              if (((DAT_140ca5b90 != 0) &&
                  (uVar30 = *(uint *)((longlong)puVar28 + 4), uVar30 != 0xffffffff)) &&
                 (uVar30 != *(uint *)((longlong)puVar22 + 0xc))) {
                uVar24 = 1;
                if (uVar30 != 0) {
                  uVar24 = 5;
                }
                FUN_140222a00(puVar16,0x1c,uVar24);
                *(uint *)((longlong)puVar22 + 0xc) = *(uint *)((longlong)puVar28 + 4);
              }
              sVar1 = *(short *)((longlong)puVar28 + 0xc);
              if ((sVar1 != -1) && (sVar1 != *(short *)((longlong)puVar22 + 0x14))) {
                FUN_140222a00(puVar16,4,(int)sVar1);
                *(undefined2 *)((longlong)puVar22 + 0x14) = *(undefined2 *)((longlong)puVar28 + 0xc)
                ;
              }
              sVar1 = (short)puVar28[1];
              if ((sVar1 != -1) && (sVar1 != (short)puVar22[2])) {
                FUN_140222a00(puVar16,5,(int)sVar1);
                *(short *)(puVar22 + 2) = (short)puVar28[1];
              }
              sVar1 = *(short *)((longlong)puVar28 + 10);
              if ((sVar1 != -1) && (sVar1 != *(short *)((longlong)puVar22 + 0x12))) {
                FUN_140222a00(puVar16,6,(int)sVar1);
                *(undefined2 *)((longlong)puVar22 + 0x12) = *(undefined2 *)((longlong)puVar28 + 10);
              }
              sVar1 = *(short *)((longlong)puVar28 + 0x12);
              if ((sVar1 != -1) && (sVar1 != *(short *)((longlong)puVar22 + 0x1a))) {
                FUN_140222a00(puVar16,1,(int)sVar1);
                *(undefined2 *)((longlong)puVar22 + 0x1a) =
                     *(undefined2 *)((longlong)puVar28 + 0x12);
              }
              sVar1 = *(short *)((longlong)puVar28 + 0xe);
              if ((sVar1 != -1) && (sVar1 != *(short *)((longlong)puVar22 + 0x16))) {
                FUN_140222a00(puVar16,2,(int)sVar1);
                *(undefined2 *)((longlong)puVar22 + 0x16) = *(undefined2 *)((longlong)puVar28 + 0xe)
                ;
              }
              sVar1 = (short)puVar28[2];
              if ((sVar1 != -1) && (sVar1 != (short)puVar22[3])) {
                FUN_140222a00(puVar16,3,(int)sVar1);
                *(short *)(puVar22 + 3) = (short)puVar28[2];
              }
            }
          }
          else if ((uVar9 == 0) &&
                  (((DAT_140d81ab0 != local_1530 || (DAT_140d3ae18 != 0)) && (DAT_140ca5960 != 0))))
          {
            FUN_1402228b0(local_1530);
            DAT_140d81ab0 = lVar15;
            DAT_140d81aac = 1;
          }
        }
        puVar16 = (ulonglong *)(ulonglong)(uVar9 + 1);
        puVar29 = puVar29 + 1;
        puVar22 = puVar22 + 4;
        puVar28 = puVar28 + 4;
      } while (uVar9 + 1 < local_1548);
      if (0xf < (uint)puVar16) {
        return 0;
      }
    }
    do {
      uVar26 = (uint)puVar16;
      if (*puVar22 != 0) {
        FUN_1402229e0(puVar16,0);
        *puVar22 = 0;
      }
      if (uVar26 < 4) {
        FUN_1402229e0(uVar26 + 0x101,0);
      }
      puVar16 = (ulonglong *)(ulonglong)(uVar26 + 1);
      puVar22 = puVar22 + 4;
    } while (uVar26 + 1 < 0x10);
  }
  return 0;
}


