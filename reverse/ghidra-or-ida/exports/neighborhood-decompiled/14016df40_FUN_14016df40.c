// Function: FUN_14016df40 @ 14016df40
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14016df40(undefined8 *param_1,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  uint *puVar9;
  uint *puVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined1 *puVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  byte *pbVar18;
  undefined8 uVar19;
  uint *puVar20;
  int iVar21;
  ushort uVar22;
  int iVar23;
  uint *puVar24;
  bool bVar25;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined4 local_150;
  undefined4 local_148;
  undefined4 local_140;
  int local_138;
  uint *local_130;
  longlong local_128;
  undefined4 local_120;
  uint *local_118;
  uint local_110;
  uint *local_108;
  uint local_100;
  uint *local_f8;
  longlong local_f0;
  uint *local_e8;
  undefined4 *local_e0 [2];
  uint local_d0;
  uint local_cc;
  undefined8 local_c0;
  undefined1 local_b8 [4];
  int local_b4;
  uint local_b0;
  ushort local_aa;
  int local_a8;
  undefined1 local_88 [10];
  undefined4 local_7e;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined8 local_6c;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_178;
  uVar19 = param_1[6];
  lVar8 = 0;
  local_118 = (uint *)0x0;
  puVar9 = (uint *)0x0;
  local_f0 = 0;
  local_f8 = (uint *)0x0;
  puVar20 = (uint *)0x0;
  local_110 = param_3;
  local_e0[0] = param_2;
  (*(code *)param_1[1])(uVar19,0,2);
  local_e8 = (uint *)(*(code *)*param_1)(uVar19);
  (*(code *)param_1[1])(uVar19,0,0);
  lVar7 = (*(code *)param_1[2])(local_88,0xe,1,uVar19);
  if (((lVar7 == 0) || (iVar3 = FUN_1401ae2b0(local_88,&DAT_1404a86a0,2), iVar3 != 0)) ||
     (lVar7 = (*(code *)param_1[2])(local_b8,0x2c,1,uVar19), lVar7 == 0)) goto LAB_14016f274;
  if (local_aa < 9) {
    lVar8 = FUN_1401b6560(0x42c,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xb8a);
    if (lVar8 == 0) goto LAB_14016f356;
    FUN_1401ae2f0(lVar8,local_b8,0x2c);
    uVar13 = 1;
    lVar7 = (longlong)((1 << ((byte)local_aa & 0x1f)) + -1) << 2;
LAB_14016e0ee:
    lVar7 = (*(code *)param_1[2])(lVar8 + 0x2c,uVar13,lVar7,uVar19);
    if (lVar7 != 0) goto LAB_14016e101;
    puVar9 = (uint *)0x0;
    puVar20 = (uint *)0x0;
    puVar24 = (uint *)0x0;
  }
  else {
    if (((local_aa - 0x10 & 0xffef) == 0) || (local_a8 == 3)) {
      lVar8 = FUN_1401b6560(0x34,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xb97)
      ;
      if (lVar8 == 0) goto LAB_14016f356;
      FUN_1401ae2f0(lVar8,local_b8,0x2c);
      if (local_a8 == 3) {
        uVar13 = 8;
        lVar7 = 1;
        goto LAB_14016e0ee;
      }
    }
    else {
      lVar8 = FUN_1401b6560(0x2c,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xba6)
      ;
      if (lVar8 == 0) {
LAB_14016f356:
        puVar9 = (uint *)0x0;
        lVar8 = 0;
        goto LAB_14016f274;
      }
      FUN_1401ae2f0(lVar8,local_b8,0x2c);
    }
LAB_14016e101:
    (*(code *)param_1[1])(uVar19,local_7e,0);
    uVar12 = (int)((uint)local_aa * local_b4) >> 0x1f & 7;
    uVar4 = (uint)local_aa * local_b4 + uVar12;
    iVar15 = (int)uVar4 >> 3;
    iVar3 = iVar15 + 1;
    if ((uVar4 & 7) == uVar12) {
      iVar3 = iVar15;
    }
    uVar4 = (iVar3 + 3 >> 0x1f & 3U) + iVar3 + 3 & 0xfffffffc;
    local_100 = ((local_b0 ^ (int)local_b0 >> 0x1f) - ((int)local_b0 >> 0x1f)) * uVar4;
    puVar9 = puVar20;
    puVar24 = puVar20;
    if (local_110 == 0) {
      lVar7 = (*(code *)*param_1)(uVar19);
      local_e8 = (uint *)((longlong)local_e8 - lVar7);
      puVar9 = (uint *)FUN_1401b6390(local_e8,
                                     "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                     0xbbd);
      local_118 = puVar9;
      if ((puVar9 == (uint *)0x0) ||
         (lVar7 = (*(code *)param_1[2])(puVar9,1,local_e8,uVar19), lVar7 == 0)) goto LAB_14016f24e;
    }
    iVar3 = *(int *)(lVar8 + 0x10);
    if (iVar3 == 1) {
      if (local_110 != 0) {
LAB_14016e2d9:
        puVar9 = (uint *)0x0;
        if (local_110 == 0) {
          puVar9 = puVar20;
        }
        *(uint **)(param_2 + 0x10e) = puVar9;
        param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
        uVar12 = *(uint *)(lVar8 + 8);
        param_2[0x10c] = uVar4;
        uVar4 = (int)uVar12 >> 0x1f;
        param_2[0x10b] = (uVar12 ^ uVar4) - uVar4;
        *param_2 = 0;
        *(undefined2 *)((longlong)param_2 + 0xe) = 0;
        *(undefined2 *)(param_2 + 1) = 0x801;
        param_2[9] = 0xff;
        param_2[8] = 0xff000000;
        *(undefined8 *)(param_2 + 6) = 0xff;
        *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
        param_2[4] = 0xff0000;
        *(undefined2 *)(param_2 + 2) = 0x808;
        *(undefined1 *)((longlong)param_2 + 0xd) = 8;
        param_2[5] = 0xff00;
        *(undefined1 *)((longlong)param_2 + 10) = 8;
        FUN_1401ae2f0(param_2 + 10,lVar8 + 0x28,0x400);
        puVar14 = (undefined1 *)((longlong)param_2 + 0x2b);
        lVar7 = 0x100;
        do {
          *puVar14 = 0;
          puVar14 = puVar14 + 4;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        FUN_1401b6700(lVar8);
        return 0;
      }
      puVar9 = (uint *)FUN_1401b6390((longlong)(int)local_100,
                                     "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                     0xbcc);
      if (puVar9 != (uint *)0x0) {
        local_e8 = puVar9;
        FUN_1401ae370(puVar9,0);
        puVar20 = local_118;
        puVar24 = puVar9;
        uVar12 = uVar4;
        if (-1 < *(int *)(lVar8 + 8)) {
          puVar9 = (uint *)((longlong)(int)((*(int *)(lVar8 + 8) + -1) * uVar4) + (longlong)puVar9);
          puVar24 = puVar9;
          uVar12 = -uVar4;
        }
        while( true ) {
          while( true ) {
            for (; (byte)*puVar20 != 0; puVar20 = (uint *)((longlong)puVar20 + 2)) {
              FUN_1401ae370(puVar9,*(byte *)((longlong)puVar20 + 1));
              puVar9 = (uint *)((longlong)puVar9 + (ulonglong)(byte)*puVar20);
            }
            bVar1 = *(byte *)((longlong)puVar20 + 1);
            if (bVar1 != 0) break;
            puVar9 = (uint *)((longlong)puVar24 + (longlong)(int)uVar12);
            puVar20 = (uint *)((longlong)puVar20 + 2);
            puVar24 = puVar9;
          }
          if (bVar1 == 1) break;
          if (bVar1 == 2) {
            puVar24 = (uint *)((longlong)puVar24 +
                              (longlong)(int)((int)(char)*(byte *)((longlong)puVar20 + 3) * uVar12))
            ;
            puVar9 = (uint *)((longlong)(char)*(byte *)((longlong)puVar20 + 2) + (longlong)puVar24);
            puVar20 = puVar20 + 1;
          }
          else {
            FUN_1401ae2f0(puVar9,(byte *)((longlong)puVar20 + 2));
            puVar9 = (uint *)((longlong)puVar9 + (ulonglong)*(byte *)((longlong)puVar20 + 1));
            puVar20 = (uint *)(((ulonglong)
                                ((longlong)puVar20 + (ulonglong)*(byte *)((longlong)puVar20 + 1) + 1
                                ) & 0xfffffffffffffffe) + 2);
          }
        }
        FUN_1401b6700(local_118);
        puVar20 = local_e8;
        goto LAB_14016e2d9;
      }
      local_e8 = (uint *)0x0;
      puVar9 = local_118;
    }
    else {
      if (iVar3 != 2) {
        if (iVar3 == 0) {
          if (*(short *)(lVar8 + 0xe) == 1) {
            iVar3 = *(int *)(lVar8 + 4);
            uVar12 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
            iVar15 = (*(uint *)(lVar8 + 8) ^ uVar12) - uVar12;
            uVar12 = (iVar3 + 3 >> 0x1f & 3U) + iVar3 + 3 & 0xfffffffc;
            puVar20 = local_118;
            local_100 = uVar12;
            if (local_110 != 0) {
LAB_14016e7f2:
              *(uint **)(param_2 + 0x10e) = puVar20;
              param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
              uVar4 = *(uint *)(lVar8 + 8);
              param_2[0x10c] = local_100;
              uVar12 = (int)uVar4 >> 0x1f;
              param_2[0x10b] = (uVar4 ^ uVar12) - uVar12;
              *param_2 = 0;
              *(undefined2 *)(param_2 + 1) = 0x801;
              param_2[8] = 0xff000000;
              *(undefined2 *)((longlong)param_2 + 0xe) = 0;
              *(undefined8 *)(param_2 + 6) = 0xff;
              *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
              param_2[4] = 0xff0000;
              *(undefined2 *)(param_2 + 2) = 0x808;
              *(undefined1 *)((longlong)param_2 + 0xd) = 8;
              param_2[5] = 0xff00;
              *(undefined1 *)((longlong)param_2 + 10) = 8;
              param_2[9] = 0xf;
              FUN_1401ae2f0(param_2 + 10,lVar8 + 0x28,8);
              *(undefined1 *)((longlong)param_2 + 0x2b) = 0;
              *(undefined1 *)((longlong)param_2 + 0x2f) = 0;
              FUN_1401b6700(lVar8);
              return 0;
            }
            puVar20 = (uint *)FUN_1401b6390((longlong)(int)(uVar12 * iVar15),
                                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                            ,0xcb0);
            puVar9 = local_118;
            if (puVar20 != (uint *)0x0) {
              iVar6 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
              iVar21 = iVar3 + iVar6 * -8;
              if (*(int *)(lVar8 + 8) < 1) {
                iVar23 = uVar4 - iVar6;
              }
              else {
                iVar23 = -(uVar4 + iVar6);
                puVar9 = (uint *)((longlong)(int)((iVar15 + -1) * uVar4) + (longlong)local_118);
              }
              iVar16 = iVar6;
              puVar24 = puVar20;
              do {
                for (; iVar16 != 0; iVar16 = iVar16 + -1) {
                  *(byte *)puVar24 = (byte)*puVar9 >> 7;
                  *(byte *)((longlong)puVar24 + 1) = (byte)*puVar9 >> 6 & 1;
                  *(byte *)((longlong)puVar24 + 2) = (byte)*puVar9 >> 5 & 1;
                  *(byte *)((longlong)puVar24 + 3) = (byte)*puVar9 >> 4 & 1;
                  *(byte *)(puVar24 + 1) = (byte)*puVar9 >> 3 & 1;
                  *(byte *)((longlong)puVar24 + 5) = (byte)*puVar9 >> 2 & 1;
                  *(byte *)((longlong)puVar24 + 6) = (byte)*puVar9 >> 1 & 1;
                  uVar4 = *puVar9;
                  puVar9 = (uint *)((longlong)puVar9 + 1);
                  *(byte *)((longlong)puVar24 + 7) = (byte)uVar4 & 1;
                  puVar24 = puVar24 + 2;
                }
                if (iVar21 != 0) {
                  *(byte *)puVar24 = (byte)*puVar9 >> 7;
                  puVar10 = (uint *)((longlong)puVar24 + 1);
                  for (iVar16 = iVar21 + -1; puVar24 = puVar10, iVar16 != 0; iVar16 = iVar16 + -8) {
                    *(byte *)puVar10 = (byte)*puVar9 >> 6 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 1);
                    if (iVar16 == 1) break;
                    *(byte *)puVar24 = (byte)*puVar9 >> 5 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 2);
                    if (iVar16 == 2) break;
                    *(byte *)puVar24 = (byte)*puVar9 >> 4 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 3);
                    if (iVar16 == 3) break;
                    *(byte *)puVar24 = (byte)*puVar9 >> 3 & 1;
                    puVar24 = puVar10 + 1;
                    if (iVar16 == 4) break;
                    *(byte *)puVar24 = (byte)*puVar9 >> 2 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 5);
                    if (iVar16 == 5) break;
                    *(byte *)puVar24 = (byte)*puVar9 >> 1 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 6);
                    if (iVar16 == 6) break;
                    uVar4 = *puVar9;
                    puVar9 = (uint *)((longlong)puVar9 + 1);
                    *(byte *)puVar24 = (byte)uVar4 & 1;
                    puVar24 = (uint *)((longlong)puVar10 + 7);
                    if (iVar16 == 7) break;
                    *(byte *)puVar24 = *(byte *)puVar9 >> 7;
                    puVar10 = puVar10 + 2;
                  }
                }
                puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uVar12 - iVar3));
                puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar23);
                iVar15 = iVar15 + -1;
                iVar16 = iVar6;
              } while (iVar15 != 0);
              FUN_1401b6700(local_118);
              goto LAB_14016e7f2;
            }
LAB_14016f221:
            puVar20 = local_f8;
            puVar24 = (uint *)0x0;
            goto LAB_14016f24e;
          }
          if (*(short *)(lVar8 + 0xe) == 4) {
            iVar3 = *(int *)(lVar8 + 4);
            uVar12 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
            iVar15 = (*(uint *)(lVar8 + 8) ^ uVar12) - uVar12;
            uVar12 = iVar3 + 3 + (iVar3 + 3 >> 0x1f & 3U) & 0xfffffffc;
            bVar25 = local_110 != 0;
            puVar20 = puVar9;
            local_110 = uVar12;
            if (bVar25) {
LAB_14016e9fc:
              *(uint **)(param_2 + 0x10e) = puVar20;
              param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
              uVar4 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
              param_2[0x10b] = (*(uint *)(lVar8 + 8) ^ uVar4) - uVar4;
              param_2[0x10c] = local_110;
              *param_2 = 0;
              *(undefined2 *)(param_2 + 1) = 0x801;
              param_2[8] = 0xff000000;
              *(undefined2 *)((longlong)param_2 + 0xe) = 0;
              *(undefined8 *)(param_2 + 6) = 0xff;
              *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
              param_2[4] = 0xff0000;
              *(undefined2 *)(param_2 + 2) = 0x808;
              *(undefined1 *)((longlong)param_2 + 0xd) = 8;
              param_2[5] = 0xff00;
              *(undefined1 *)((longlong)param_2 + 10) = 8;
              param_2[9] = 0xf;
              FUN_1401ae2f0(param_2 + 10,lVar8 + 0x28,0x40);
              puVar14 = (undefined1 *)((longlong)param_2 + 0x2b);
              lVar7 = 0x10;
              do {
                *puVar14 = 0;
                puVar14 = puVar14 + 4;
                lVar7 = lVar7 + -1;
              } while (lVar7 != 0);
              FUN_1401b6700(lVar8);
              return 0;
            }
            puVar20 = (uint *)FUN_1401b6390((longlong)(int)(uVar12 * iVar15),
                                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                            ,0xd2a);
            if (puVar20 != (uint *)0x0) {
              iVar6 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
              iVar21 = iVar3 + iVar6 * -8;
              if (0 < *(int *)(lVar8 + 8)) {
                puVar9 = (uint *)((longlong)(int)((iVar15 + -1) * uVar4) + (longlong)local_118);
                uVar4 = -uVar4;
              }
              local_e8 = (uint *)(longlong)(int)(local_110 - iVar3);
              iVar23 = iVar6;
              puVar24 = puVar20;
              do {
                for (; iVar23 != 0; iVar23 = iVar23 + -1) {
                  uVar12 = *puVar9 >> 4 & 0xf0f0f0f;
                  *(byte *)puVar24 = (byte)uVar12;
                  *(byte *)((longlong)puVar24 + 2) = (byte)(uVar12 >> 8);
                  *(byte *)(puVar24 + 1) = (byte)(uVar12 >> 0x10);
                  *(byte *)((longlong)puVar24 + 6) = (byte)(uVar12 >> 0x18);
                  uVar12 = *puVar9;
                  puVar9 = puVar9 + 1;
                  uVar12 = uVar12 & 0xf0f0f0f;
                  *(byte *)((longlong)puVar24 + 1) = (byte)uVar12;
                  *(byte *)((longlong)puVar24 + 3) = (byte)(uVar12 >> 8);
                  *(byte *)((longlong)puVar24 + 5) = (byte)(uVar12 >> 0x10);
                  *(byte *)((longlong)puVar24 + 7) = (byte)(uVar12 >> 0x18);
                  puVar24 = puVar24 + 2;
                }
                if (iVar21 != 0) {
                  *(byte *)puVar24 = (byte)*puVar9 >> 4;
                  puVar10 = (uint *)((longlong)puVar24 + 1);
                  for (iVar23 = iVar21 + -1; puVar24 = puVar10, iVar23 != 0; iVar23 = iVar23 + -2) {
                    uVar12 = *puVar9;
                    puVar9 = (uint *)((longlong)puVar9 + 1);
                    *(byte *)puVar10 = (byte)uVar12 & 0xf;
                    puVar24 = (uint *)((longlong)puVar10 + 1);
                    if (iVar23 == 1) break;
                    *(byte *)puVar24 = *(byte *)puVar9 >> 4;
                    puVar10 = (uint *)((longlong)puVar10 + 2);
                  }
                }
                puVar24 = (uint *)((longlong)puVar24 + (longlong)local_e8);
                puVar9 = (uint *)((longlong)puVar9 + (longlong)(int)(uVar4 - iVar3 / 2));
                iVar15 = iVar15 + -1;
                iVar23 = iVar6;
              } while (iVar15 != 0);
              FUN_1401b6700(local_118);
              goto LAB_14016e9fc;
            }
            puVar20 = local_f8;
            puVar24 = (uint *)0x0;
            goto LAB_14016f24e;
          }
          if (((*(short *)(lVar8 + 0xe) - 8U & 0xffe7) != 0) || (*(short *)(lVar8 + 0xe) == 0x10))
          goto LAB_14016ed53;
          if (local_110 == 0) {
            uVar12 = *(uint *)(lVar8 + 8);
            uVar11 = (ulonglong)uVar12;
            if (0 < (int)uVar12) {
              puVar20 = (uint *)FUN_1401b6390((longlong)(int)(uVar12 * uVar4),
                                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                             );
              local_108 = puVar20;
              if (puVar20 == (uint *)0x0) goto LAB_14016f221;
              pbVar18 = (byte *)((longlong)(int)((uVar12 - 1) * uVar4) + (longlong)local_118);
              if (0 < (int)uVar12) {
                do {
                  FUN_1401ae2f0(puVar20,pbVar18);
                  pbVar18 = pbVar18 + -(longlong)(int)uVar4;
                  puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar4);
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
              }
              FUN_1401b6700();
              puVar9 = local_108;
            }
          }
          *(uint **)(param_2 + 0x10e) = puVar9;
          param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
          uVar12 = *(uint *)(lVar8 + 8);
          uVar5 = (int)uVar12 >> 0x1f;
          param_2[0x10c] = uVar4;
          param_2[0x10b] = (uVar12 ^ uVar5) - uVar5;
          if (*(short *)(lVar8 + 0xe) == 8) {
            *(undefined1 *)((longlong)param_2 + 0xd) = 8;
            *(undefined1 *)((longlong)param_2 + 10) = 8;
            *param_2 = 0;
            *(undefined2 *)(param_2 + 1) = 0x801;
            param_2[9] = 0xff;
            param_2[8] = 0xff000000;
            *(undefined2 *)((longlong)param_2 + 0xe) = 0;
            *(undefined8 *)(param_2 + 6) = 0xff;
            *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
            param_2[4] = 0xff0000;
            *(undefined2 *)(param_2 + 2) = 0x808;
            param_2[5] = 0xff00;
            uVar19 = 0x40;
            if (*(short *)(lVar8 + 0xe) == 8) {
              uVar19 = 0x400;
            }
            FUN_1401ae2f0(param_2 + 10,lVar8 + 0x28,uVar19);
            puVar14 = (undefined1 *)((longlong)param_2 + 0x2b);
            lVar7 = 0x100;
            do {
              *puVar14 = 0;
              puVar14 = puVar14 + 4;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            FUN_1401b6700(lVar8);
            return 0;
          }
          if (*(short *)(lVar8 + 0xe) == 0x18) {
            *(undefined8 *)(param_2 + 8) = 0;
            *(undefined2 *)((longlong)param_2 + 0xe) = 0;
            goto LAB_14016f311;
          }
          if (DAT_14082436c != 0) {
            uVar12 = param_2[0x10b] * *(int *)(lVar8 + 4);
            uVar4 = 0;
            if (uVar12 != 0) {
              pbVar18 = (byte *)((longlong)puVar9 + 3);
              do {
                if (*pbVar18 != 0) break;
                uVar4 = uVar4 + 1;
                pbVar18 = pbVar18 + 4;
              } while (uVar4 < uVar12);
            }
            *param_2 = 0;
            param_2[4] = 0xff0000;
            *(undefined2 *)(param_2 + 2) = 0x808;
            *(undefined1 *)((longlong)param_2 + 0xd) = 8;
            param_2[5] = 0xff00;
            *(undefined1 *)((longlong)param_2 + 10) = 8;
            if (uVar4 == uVar12) {
              param_2[9] = 0;
              param_2[1] = 0x8182004;
              param_2[8] = 0xff000000;
              *(undefined2 *)((longlong)param_2 + 0xe) = 0;
              *(undefined8 *)(param_2 + 6) = 0xff;
              *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
              FUN_1401b6700(lVar8);
              return 0;
            }
            param_2[1] = 0x2004;
            *(undefined8 *)(param_2 + 8) = 0;
            *(undefined2 *)((longlong)param_2 + 0xe) = 0x1800;
            param_2[7] = 0xff000000;
            *(undefined2 *)((longlong)param_2 + 0xb) = 0x1008;
            param_2[6] = 0xff;
            FUN_1401b6700(lVar8);
            return 0;
          }
          param_2[1] = 0x2004;
          *(undefined8 *)(param_2 + 8) = 0;
          *(undefined2 *)((longlong)param_2 + 0xe) = 0x1800;
          param_2[7] = 0xff000000;
          *(undefined2 *)((longlong)param_2 + 0xb) = 0x1008;
          param_2[4] = 0xff0000;
          *(undefined2 *)(param_2 + 2) = 0x808;
          *(undefined1 *)((longlong)param_2 + 0xd) = 8;
          param_2[5] = 0xff00;
          param_2[6] = 0xff;
          *(undefined1 *)((longlong)param_2 + 10) = 8;
        }
        else {
LAB_14016ed53:
          if ((local_aa - 0x10 & 0xffef) == 0) {
            if (local_a8 == 3) {
              iVar3 = *(int *)(lVar8 + 0x28);
              if (((iVar3 == -0x1000000) && (*(int *)(lVar8 + 0x2c) == 0xff0000)) &&
                 (*(int *)(lVar8 + 0x30) == 0xff00)) {
                iVar3 = 0x378;
              }
              else if (((iVar3 == 0xff0000) && (*(int *)(lVar8 + 0x2c) == 0xff00)) &&
                      (*(int *)(lVar8 + 0x30) == 0xff)) {
                iVar3 = 0x760;
              }
              else {
                if (((iVar3 != 0xf800) || (*(int *)(lVar8 + 0x2c) != 0x7e0)) ||
                   (*(int *)(lVar8 + 0x30) != 0x1f)) {
                  if ((iVar3 == 0x7c0) && (*(int *)(lVar8 + 0x2c) == 0x3e0)) {
                    bVar25 = *(int *)(lVar8 + 0x30) == 0x1f;
                    goto LAB_14016ee16;
                  }
                  goto LAB_14016f063;
                }
                iVar3 = 0x235;
              }
LAB_14016ee22:
              if ((local_110 == 0) &&
                 (uVar12 = *(uint *)(lVar8 + 8), local_100 = uVar12, 0 < (int)uVar12)) {
                puVar20 = (uint *)FUN_1401b6390((longlong)(int)(uVar12 * uVar4),
                                                "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                               );
                local_108 = puVar20;
                if (puVar20 == (uint *)0x0) goto LAB_14016f221;
                pbVar18 = (byte *)((longlong)(int)((uVar12 - 1) * uVar4) + (longlong)local_118);
                if (0 < (int)uVar12) {
                  uVar11 = (ulonglong)local_100;
                  do {
                    FUN_1401ae2f0(puVar20,pbVar18);
                    pbVar18 = pbVar18 + -(longlong)(int)uVar4;
                    puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar4);
                    uVar11 = uVar11 - 1;
                    param_2 = local_e0[0];
                  } while (uVar11 != 0);
                }
                FUN_1401b6700(local_118);
                puVar9 = local_108;
              }
              *(uint **)(param_2 + 0x10e) = puVar9;
              param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
              uVar12 = *(uint *)(lVar8 + 8);
              param_2[0x10c] = uVar4;
              uVar4 = (int)uVar12 >> 0x1f;
              param_2[0x10b] = (uVar12 ^ uVar4) - uVar4;
              *param_2 = 0;
              param_2[1] = 0x8182004;
              param_2[9] = 0;
              param_2[8] = 0xff000000;
              *(undefined2 *)((longlong)param_2 + 0xe) = 0;
              *(undefined8 *)(param_2 + 6) = 0xff;
              *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
              param_2[4] = 0xff0000;
              *(undefined2 *)(param_2 + 2) = 0x808;
              *(undefined1 *)((longlong)param_2 + 0xd) = 8;
              param_2[5] = 0xff00;
              *(undefined1 *)((longlong)param_2 + 10) = 8;
              if (iVar3 == 0x22b) {
                param_2[1] = 0x10f1002;
                param_2[8] = 0x8000;
                *(undefined2 *)(param_2 + 3) = 0x50a;
                param_2[4] = 0x7c00;
                *(undefined2 *)(param_2 + 2) = 0x505;
                param_2[5] = 0x3e0;
                *(undefined1 *)((longlong)param_2 + 0xe) = 0;
                param_2[6] = 0x1f;
                *(undefined1 *)((longlong)param_2 + 10) = 5;
                FUN_1401b6700(lVar8);
                return 0;
              }
              if (iVar3 == 0x235) {
                param_2[1] = 0x1002;
                param_2[8] = 0;
                *(undefined2 *)(param_2 + 3) = 0x50b;
                param_2[4] = 0xf800;
                *(undefined2 *)(param_2 + 2) = 0x605;
                param_2[5] = 0x7e0;
                *(undefined1 *)((longlong)param_2 + 0xe) = 0;
                param_2[6] = 0x1f;
                *(undefined1 *)((longlong)param_2 + 10) = 5;
                FUN_1401b6700(lVar8);
                return 0;
              }
              if (iVar3 == 0x378) {
                param_2[1] = 0x8002004;
                param_2[8] = 0xff;
                *(undefined2 *)(param_2 + 3) = 0x1018;
                param_2[4] = 0xff000000;
                *(undefined2 *)(param_2 + 2) = 0x808;
                param_2[5] = 0xff0000;
                *(undefined1 *)((longlong)param_2 + 0xe) = 8;
                param_2[6] = 0xff00;
                *(undefined1 *)((longlong)param_2 + 10) = 8;
                FUN_1401b6700(lVar8);
                return 0;
              }
              if (iVar3 == 0x760) {
                param_2[1] = 0x8182004;
                param_2[8] = 0xff000000;
                *(undefined2 *)(param_2 + 3) = 0x810;
                param_2[4] = 0xff0000;
                *(undefined2 *)(param_2 + 2) = 0x808;
                param_2[5] = 0xff00;
                *(undefined1 *)((longlong)param_2 + 0xe) = 0;
                param_2[6] = 0xff;
                *(undefined1 *)((longlong)param_2 + 10) = 8;
                FUN_1401b6700(lVar8);
                return 0;
              }
              goto LAB_14016f347;
            }
            if (local_aa == 0x10) {
              bVar25 = local_a8 == 0;
LAB_14016ee16:
              if (bVar25) {
                iVar3 = 0x22b;
                goto LAB_14016ee22;
              }
            }
          }
LAB_14016f063:
          if (local_110 == 0) {
            if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
              (*DAT_140c2c018)(1);
            }
            lVar7 = (*DAT_140c2be80)(0);
            local_f0 = lVar7;
            FUN_1401ae370(&local_78,0,0x28);
            local_74 = *(undefined4 *)(lVar8 + 4);
            uVar4 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
            local_150 = 0;
            local_78 = 0x28;
            local_70 = -((*(uint *)(lVar8 + 8) ^ uVar4) - uVar4);
            local_6c = 0x180001;
            local_158 = 0;
            puVar20 = (uint *)(*DAT_140c2bee0)(lVar7,&local_78,0,local_e0);
            if ((puVar20 == (uint *)0x0) || (local_e0[0] == (undefined4 *)0x0)) {
              FUN_1401594b0(&DAT_1404a8630);
              puVar24 = (uint *)0x0;
            }
            else {
              (*DAT_140c2be98)(puVar20,0x20);
              local_cc = local_cc + 3 + ((int)(local_cc + 3) >> 0x1f & 3U) & 0xfffffffc;
              iVar3 = (local_d0 ^ (int)local_d0 >> 0x1f) - ((int)local_d0 >> 0x1f);
              uVar19 = (*DAT_140c2beb0)(lVar7,puVar20);
              puVar9 = local_118;
              local_120 = 0;
              uVar4 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
              local_130 = local_118;
              local_138 = (*(uint *)(lVar8 + 8) ^ uVar4) - uVar4;
              local_140 = 0;
              local_148 = 0;
              local_150 = 0;
              local_158 = CONCAT44(local_158._4_4_,local_138);
              local_128 = lVar8;
              (*DAT_140c2bef0)(lVar7,0,0,*(undefined4 *)(lVar8 + 4));
              (*DAT_140c2beb0)(lVar7,uVar19);
              (*DAT_140c2bec0)(lVar7);
              local_f0 = 0;
              FUN_1401b6700(puVar9);
              puVar9 = (uint *)FUN_1401b6390((longlong)(int)(local_cc * iVar3),
                                             "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                             ,0xec2);
              if (puVar9 != (uint *)0x0) {
                FUN_1401ae2f0(puVar9,local_c0,(longlong)(int)(local_cc * iVar3));
                (*DAT_140c2beb8)(puVar20);
                param_2[0x10c] = local_cc;
                goto LAB_14016f2e3;
              }
              FUN_1401594b0(&DAT_1404a8650);
              puVar9 = (uint *)0x0;
              puVar24 = (uint *)0x0;
            }
            goto LAB_14016f24e;
          }
          param_2[0x10c] = 0;
LAB_14016f2e3:
          *(uint **)(param_2 + 0x10e) = puVar9;
          param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
          uVar4 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
          param_2[0x10b] = (*(uint *)(lVar8 + 8) ^ uVar4) - uVar4;
          *(undefined8 *)(param_2 + 8) = 0;
          *(undefined2 *)((longlong)param_2 + 0xe) = 0;
LAB_14016f311:
          *(undefined1 *)((longlong)param_2 + 10) = 8;
          param_2[5] = 0xff00;
          *(undefined1 *)((longlong)param_2 + 0xd) = 8;
          *(undefined2 *)(param_2 + 2) = 0x808;
          param_2[4] = 0xff0000;
          *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
          *(undefined8 *)(param_2 + 6) = 0xff;
          *(undefined2 *)(param_2 + 1) = 0x1803;
        }
        *param_2 = 0;
LAB_14016f347:
        FUN_1401b6700(lVar8);
        return 0;
      }
      iVar3 = *(int *)(lVar8 + 4) + 3;
      uVar4 = (int)*(uint *)(lVar8 + 8) >> 0x1f;
      uVar12 = (iVar3 >> 0x1f & 3U) + iVar3 & 0xfffffffc;
      puVar10 = puVar20;
      if (local_110 != 0) {
LAB_14016e52c:
        *(uint **)(param_2 + 0x10e) = puVar10;
        param_2[0x10a] = *(undefined4 *)(lVar8 + 4);
        uVar4 = *(uint *)(lVar8 + 8);
        param_2[0x10c] = uVar12;
        uVar12 = (int)uVar4 >> 0x1f;
        param_2[0x10b] = (uVar4 ^ uVar12) - uVar12;
        *param_2 = 0;
        *(undefined2 *)(param_2 + 1) = 0x801;
        param_2[9] = 0xff;
        param_2[8] = 0xff000000;
        *(undefined2 *)((longlong)param_2 + 0xe) = 0;
        *(undefined8 *)(param_2 + 6) = 0xff;
        *(undefined2 *)((longlong)param_2 + 0xb) = 0x1000;
        param_2[4] = 0xff0000;
        *(undefined2 *)(param_2 + 2) = 0x808;
        *(undefined1 *)((longlong)param_2 + 0xd) = 8;
        param_2[5] = 0xff00;
        *(undefined1 *)((longlong)param_2 + 10) = 8;
        FUN_1401ae2f0(param_2 + 10,lVar8 + 0x28,0x40);
        puVar14 = (undefined1 *)((longlong)param_2 + 0x2b);
        lVar7 = 0x10;
        do {
          *puVar14 = 0;
          puVar14 = puVar14 + 4;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        FUN_1401b6700(lVar8);
        return 0;
      }
      lVar7 = (longlong)(int)(((*(uint *)(lVar8 + 8) ^ uVar4) - uVar4) * uVar12);
      puVar10 = (uint *)FUN_1401b6390(lVar7,
                                      "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                      0xc2f);
      puVar9 = local_118;
      puVar20 = local_f8;
      puVar24 = local_f8;
      if (puVar10 != (uint *)0x0) {
        FUN_1401ae370(puVar10,0,lVar7);
        puVar9 = local_118;
        puVar20 = puVar10;
        puVar24 = puVar10;
        uVar4 = uVar12;
        if (-1 < *(int *)(lVar8 + 8)) {
          puVar20 = (uint *)((longlong)(int)((*(int *)(lVar8 + 8) + -1) * uVar12) +
                            (longlong)puVar10);
          puVar24 = puVar20;
          uVar4 = -uVar12;
        }
LAB_14016e415:
        while( true ) {
          for (; bVar1 = (byte)*puVar9, bVar1 != 0; puVar9 = (uint *)((longlong)puVar9 + 2)) {
            uVar22 = CONCAT11(*(byte *)((longlong)puVar9 + 1),*(byte *)((longlong)puVar9 + 1) >> 4)
                     & 0xfff;
            uVar5 = (uint)(bVar1 >> 1);
            if (uVar5 != 0) {
              puVar17 = puVar20;
              for (uVar11 = (ulonglong)uVar5; uVar11 != 0; uVar11 = uVar11 - 1) {
                *(ushort *)puVar17 = uVar22;
                puVar17 = (uint *)((longlong)puVar17 + 2);
              }
              puVar20 = (uint *)((longlong)puVar20 + (ulonglong)uVar5 * 2);
            }
            if ((bVar1 & 1) == 0) goto LAB_14016e519;
            *(byte *)puVar20 = (byte)uVar22;
            puVar20 = (uint *)((longlong)puVar20 + 1);
          }
          bVar1 = *(byte *)((longlong)puVar9 + 1);
          if (bVar1 != 0) break;
          puVar20 = (uint *)((longlong)puVar24 + (longlong)(int)uVar4);
          puVar24 = puVar20;
LAB_14016e519:
          puVar9 = (uint *)((longlong)puVar9 + 2);
        }
        if (bVar1 != 1) {
          if (bVar1 == 2) {
            pbVar18 = (byte *)((longlong)puVar9 + 2);
            puVar24 = (uint *)((longlong)puVar24 +
                              (longlong)(int)((int)(char)*(byte *)((longlong)puVar9 + 3) * uVar4));
            puVar9 = puVar9 + 1;
            puVar20 = (uint *)((longlong)(char)*pbVar18 + (longlong)puVar24);
          }
          else {
            pbVar18 = (byte *)((longlong)puVar9 + 2);
            if (bVar1 >> 1 != 0) {
              uVar11 = (ulonglong)(uint)(bVar1 >> 1);
              do {
                *(byte *)puVar20 = *pbVar18 >> 4;
                bVar2 = *pbVar18;
                pbVar18 = pbVar18 + 1;
                *(byte *)((longlong)puVar20 + 1) = bVar2 & 0xf;
                puVar20 = (uint *)((longlong)puVar20 + 2);
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
            }
            if ((bVar1 & 1) != 0) {
              bVar1 = *pbVar18;
              pbVar18 = pbVar18 + 1;
              *(byte *)puVar20 = bVar1 >> 4;
              puVar20 = (uint *)((longlong)puVar20 + 1);
            }
            puVar9 = (uint *)((ulonglong)(pbVar18 + 1) & 0xfffffffffffffffe);
          }
          goto LAB_14016e415;
        }
        FUN_1401b6700(local_118);
        goto LAB_14016e52c;
      }
    }
  }
LAB_14016f24e:
  FUN_1401b6700(lVar8);
  if (puVar9 != (uint *)0x0) {
    FUN_1401b6700(puVar9);
  }
  puVar9 = puVar20;
  lVar8 = local_f0;
  if (puVar24 != (uint *)0x0) {
    FUN_1401b6700(puVar24);
    lVar8 = local_f0;
  }
LAB_14016f274:
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  if (puVar9 != (uint *)0x0) {
    (*DAT_140c2beb8)(puVar9);
  }
  if (lVar8 != 0) {
    (*DAT_140c2bec0)(lVar8);
  }
  return 0xffffffff;
}


