// Function: FUN_1401ec930 @ 1401ec930
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401ec930(longlong param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined1 uVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  uint uVar22;
  undefined1 uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  ulonglong uVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  uint uVar30;
  undefined4 *puVar31;
  ulonglong uVar32;
  longlong lVar33;
  uint uVar34;
  uint uVar35;
  int iVar36;
  byte *pbVar37;
  ulonglong uVar38;
  undefined1 *puVar39;
  byte *pbVar40;
  ulonglong uVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  undefined1 auStack_658 [32];
  uint *local_638;
  longlong *local_630;
  longlong **local_628;
  undefined4 local_620;
  undefined4 local_618;
  undefined4 local_610;
  uint local_608;
  undefined8 local_600;
  ulonglong local_5f8;
  longlong local_5f0;
  longlong local_5e8;
  longlong local_5e0;
  longlong local_5d8;
  longlong *local_5d0;
  longlong *local_5c8;
  undefined4 *local_5c0;
  undefined4 local_5b8;
  undefined1 local_5b4;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined8 local_180;
  uint local_168 [2];
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_154;
  uint local_150 [2];
  undefined8 local_148;
  longlong local_140;
  longlong local_138;
  undefined1 local_130 [8];
  undefined1 local_128 [12];
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_98 [16];
  ulonglong local_88;
  
  local_88 = DAT_1407c6b00 ^ (ulonglong)auStack_658;
  local_5f8 = CONCAT44(local_5f8._4_4_,param_4);
  local_600 = CONCAT44(local_600._4_4_,param_2);
  local_168[0] = 0;
  local_5d0 = (longlong *)0x0;
  local_5c8 = (longlong *)0x0;
  if ((((param_3 == 0) || (*(int *)(param_1 + 0x6c0) != 0)) || (*(int *)(param_1 + 0x6bc) == 1)) &&
     ((param_2 == 0 || (*(int *)(param_1 + 0x6b8) != 0)))) {
    return 0;
  }
  local_608 = param_3;
  if (*(int *)(param_1 + 0x628) < *(int *)(param_1 + 0x658)) {
    do {
      do {
        if (local_5d0 != (longlong *)0x0) {
          (**(code **)(*local_5d0 + 0x10))();
          local_5d0 = (longlong *)0x0;
        }
        local_628 = &local_5d0;
        local_630 = &local_138;
        local_638 = local_168;
        iVar10 = (**(code **)(**(longlong **)(param_1 + 0x5f0) + 0x48))
                           (*(longlong **)(param_1 + 0x5f0),0xfffffffc,0,0);
        if (iVar10 != 0) goto LAB_1401ece3e;
      } while ((local_168[0] & 0x20) != 0);
      if (((local_168[0] & 2) != 0) || (local_5d0 == (longlong *)0x0)) goto LAB_1401ece3e;
      local_140 = ((longlong)
                   (*(longlong *)(param_1 + 0x6f0) +
                   (ulonglong)((uint)(*(longlong *)(param_1 + 0x6f0) >> 0x3f) & 3)) >> 2) +
                  local_138;
      local_148 = SUB168((ZEXT416(*(uint *)(param_1 + 0x610)) << 0xc) /
                         ZEXT416(*(uint *)(param_1 + 0x614)),0);
      FUN_1401ae3b0(&local_140,&local_148,local_98);
      local_148 = 0x989680000;
      FUN_1401adf90(local_98,&local_148);
      *(longlong *)(param_1 + 0x620) = local_138;
      *(int *)(param_1 + 0x628) = (int)local_140;
    } while ((int)local_140 < *(int *)(param_1 + 0x658));
    iVar10 = (**(code **)(*local_5d0 + 0x140))(local_5d0,0,&local_5c8);
    if ((iVar10 == 0) &&
       (iVar10 = (**(code **)(*local_5c8 + 0x18))(local_5c8,&local_5c0,local_130,local_150),
       iVar10 == 0)) {
      uVar25 = *(uint *)(param_1 + 0x608);
      uVar35 = *(uint *)(param_1 + 0x60c);
      uVar34 = uVar25 >> 1;
      uVar30 = uVar35 >> 1;
      uVar24 = uVar25 + 0xf & 0xfffffff0;
      uVar32 = (ulonglong)uVar24;
      uVar14 = (uVar35 + 0x1f & 0xffffffe0) * uVar24;
      uVar22 = uVar34 + 7 & 0xfffffff8;
      uVar18 = (uVar30 + 0xf & 0xfffffff0) * uVar22;
      uVar41 = (ulonglong)uVar18;
      uVar38 = (ulonglong)uVar22;
      if (local_150[0] < uVar14 + uVar18 * 2) {
        uVar14 = (uVar35 + 0xf & 0xfffffff0) * uVar24;
        uVar22 = (uVar30 + 7 & 0xfffffff8) * uVar22;
        uVar41 = (ulonglong)uVar22;
        if (local_150[0] < uVar14 + uVar22 * 2) {
          uVar14 = uVar25 + 7 & 0xfffffff8;
          uVar32 = (ulonglong)uVar14;
          uVar22 = uVar34 + 3 & 0xfffffffc;
          uVar14 = (uVar35 + 7 & 0xfffffff8) * uVar14;
          uVar18 = (uVar30 + 3 & 0xfffffffc) * uVar22;
          uVar41 = (ulonglong)uVar18;
          uVar38 = (ulonglong)uVar22;
          if (local_150[0] < uVar14 + uVar18 * 2) {
            uVar14 = uVar25 + 3 & 0xfffffffc;
            uVar32 = (ulonglong)uVar14;
            uVar22 = uVar34 + 1 & 0xfffffffe;
            uVar14 = (uVar35 + 3 & 0xfffffffc) * uVar14;
            uVar18 = (uVar30 + 1 & 0xfffffffe) * uVar22;
            uVar41 = (ulonglong)uVar18;
            uVar38 = (ulonglong)uVar22;
            if (local_150[0] < uVar14 + uVar18 * 2) {
              uVar14 = uVar25 + 1 & 0xfffffffe;
              uVar32 = (ulonglong)uVar14;
              uVar14 = (uVar35 + 1 & 0xfffffffe) * uVar14;
              uVar41 = (ulonglong)(uVar30 * uVar34);
              uVar38 = (ulonglong)uVar34;
              if (local_150[0] < uVar14 + uVar30 * uVar34 * 2) {
                (**(code **)(*local_5c8 + 0x20))();
                goto LAB_1401ece3e;
              }
            }
          }
        }
      }
      puVar21 = (undefined1 *)((ulonglong)uVar14 + (longlong)local_5c0);
      if ((int)uVar32 == *(int *)(param_1 + 0x6a8)) {
        FUN_1401ae2f0(*(undefined8 *)(param_1 + 0x690),local_5c0,*(int *)(param_1 + 0x6a8) * uVar35)
        ;
      }
      else {
        uVar25 = *(uint *)(param_1 + 0x6a0);
        uVar35 = 0;
        puVar31 = *(undefined4 **)(param_1 + 0x690);
        uVar14 = uVar25 + (uVar25 >> 2) * -4;
        if (*(int *)(param_1 + 0x6a4) != 0) {
          do {
            puVar16 = puVar31;
            puVar19 = local_5c0;
            if (uVar25 >> 2 != 0) {
              uVar27 = (ulonglong)(uVar25 >> 2);
              do {
                uVar11 = *puVar19;
                puVar19 = puVar19 + 1;
                *puVar16 = uVar11;
                puVar16 = puVar16 + 1;
                uVar27 = uVar27 - 1;
              } while (uVar27 != 0);
            }
            if (uVar14 != 0) {
              lVar33 = (longlong)puVar19 - (longlong)puVar16;
              uVar27 = (ulonglong)uVar14;
              do {
                *(undefined1 *)puVar16 = *(undefined1 *)(lVar33 + (longlong)puVar16);
                puVar16 = (undefined4 *)((longlong)puVar16 + 1);
                uVar27 = uVar27 - 1;
              } while (uVar27 != 0);
            }
            uVar35 = uVar35 + 1;
            puVar31 = (undefined4 *)((longlong)puVar31 + (ulonglong)*(uint *)(param_1 + 0x6a8));
            local_5c0 = (undefined4 *)((longlong)local_5c0 + uVar32);
          } while (uVar35 < *(uint *)(param_1 + 0x6a4));
        }
      }
      uVar25 = *(uint *)(param_1 + 0x6ac);
      uVar35 = 0;
      puVar39 = *(undefined1 **)(param_1 + 0x698);
      if (*(int *)(param_1 + 0x6b0) != 0) {
        do {
          puVar29 = puVar21 + uVar41;
          puVar17 = puVar39;
          puVar20 = puVar29;
          puVar28 = puVar21;
          if (uVar25 >> 3 != 0) {
            uVar32 = (ulonglong)(uVar25 >> 3);
            do {
              uVar23 = *puVar28;
              puVar28 = puVar28 + 8;
              *puVar17 = uVar23;
              puVar17[1] = *puVar20;
              puVar17[2] = puVar20[(longlong)(puVar21 + (1 - (longlong)puVar29))];
              puVar17[3] = puVar20[1];
              puVar17[4] = puVar20[(longlong)(puVar21 + (2 - (longlong)puVar29))];
              puVar17[5] = puVar20[2];
              puVar17[6] = puVar20[(longlong)(puVar21 + (3 - (longlong)puVar29))];
              puVar17[7] = puVar20[3];
              puVar17[8] = puVar20[(longlong)(puVar21 + (4 - (longlong)puVar29))];
              puVar17[9] = puVar20[4];
              puVar17[10] = puVar20[(longlong)(puVar21 + (5 - (longlong)puVar29))];
              puVar17[0xb] = puVar20[5];
              puVar17[0xc] = puVar20[(longlong)(puVar21 + (6 - (longlong)puVar29))];
              puVar17[0xd] = puVar20[6];
              puVar17[0xe] = puVar20[(longlong)(puVar21 + (7 - (longlong)puVar29))];
              puVar1 = puVar20 + 7;
              puVar20 = puVar20 + 8;
              puVar17[0xf] = *puVar1;
              puVar17 = puVar17 + 0x10;
              uVar32 = uVar32 - 1;
            } while (uVar32 != 0);
          }
          if ((uVar25 & 7) != 0) {
            uVar32 = (ulonglong)(uVar25 & 7);
            puVar29 = puVar28;
            do {
              uVar23 = *puVar29;
              puVar29 = puVar29 + 1;
              *puVar17 = uVar23;
              puVar17[1] = puVar29[(longlong)(puVar20 + (-1 - (longlong)puVar28))];
              uVar32 = uVar32 - 1;
              puVar17 = puVar17 + 2;
            } while (uVar32 != 0);
          }
          uVar35 = uVar35 + 1;
          puVar39 = puVar39 + *(uint *)(param_1 + 0x6b4);
          puVar21 = puVar21 + uVar38;
        } while (uVar35 < *(uint *)(param_1 + 0x6b0));
      }
      iVar10 = (**(code **)(*local_5c8 + 0x20))();
      if (iVar10 == 0) {
        param_2 = (int)local_600;
        param_4 = (undefined4)local_5f8;
        goto LAB_1401ecea7;
      }
    }
LAB_1401ece3e:
    if (local_5c8 != (longlong *)0x0) {
      (**(code **)(*local_5c8 + 0x10))(local_5c8);
      local_5c8 = (longlong *)0x0;
    }
    if (local_5d0 != (longlong *)0x0) {
      (**(code **)(*local_5d0 + 0x10))();
    }
    uVar12 = 0xffffffff;
  }
  else {
LAB_1401ecea7:
    uVar25 = 0;
    if (((local_608 != 0) && (*(int *)(param_1 + 0x6bc) == 0)) &&
       (iVar10 = thunk_FUN_1401ef520(), 199 < iVar10)) {
      if (*(int *)(param_1 + 0x5a0) == -1) {
        FUN_14014e950(local_128);
        FUN_14014eb90(local_128,0x20,0);
        local_628 = (longlong **)((ulonglong)local_628 & 0xffffffff00000000);
        local_630 = (longlong *)((ulonglong)local_630 & 0xffffffff00000000);
        local_638 = (uint *)((ulonglong)local_638 & 0xffffffff00000000);
        local_11c = 1;
        local_118 = 8;
        local_620 = param_4;
        uVar11 = FUN_140150020(local_128,*(undefined4 *)(param_1 + 0x6a0),
                               *(undefined4 *)(param_1 + 0x6a4),0);
        *(undefined4 *)(param_1 + 0x5a0) = uVar11;
        FUN_1401b7da0(uVar11,param_1 + 0x5a0);
      }
      if (*(int *)(param_1 + 0x5a4) == -1) {
        FUN_14014e950(local_128);
        FUN_14014eb90(local_128,0x20,0);
        local_628 = (longlong **)((ulonglong)local_628 & 0xffffffff00000000);
        local_630 = (longlong *)((ulonglong)local_630 & 0xffffffff00000000);
        local_638 = (uint *)((ulonglong)local_638 & 0xffffffff00000000);
        local_11c = 2;
        local_118 = 8;
        local_620 = param_4;
        uVar11 = FUN_140150020(local_128,*(undefined4 *)(param_1 + 0x6ac),
                               *(undefined4 *)(param_1 + 0x6b0),0);
        *(undefined4 *)(param_1 + 0x5a4) = uVar11;
        FUN_1401b7da0(uVar11,param_1 + 0x5a4);
      }
      FUN_1401ae370(&local_5b8,0,0x448);
      local_190 = *(undefined4 *)(param_1 + 0x6a0);
      local_18c = *(undefined4 *)(param_1 + 0x6a4);
      local_188 = *(undefined4 *)(param_1 + 0x6a8);
      local_618 = 0;
      local_180 = *(undefined8 *)(param_1 + 0x690);
      local_620 = 0;
      local_638 = &local_5b8;
      local_628 = (longlong **)((ulonglong)local_628 & 0xffffffff00000000);
      local_630 = (longlong *)0x0;
      local_5b8._0_2_ = 0x100;
      local_5b4 = 1;
      local_5b8._2_1_ = 8;
      local_160 = 0;
      local_610 = param_4;
      local_158 = local_190;
      local_154 = local_18c;
      FUN_1401483b0(&local_160,0,0,*(undefined4 *)(param_1 + 0x5a0));
      local_190 = *(undefined4 *)(param_1 + 0x6ac);
      local_18c = *(undefined4 *)(param_1 + 0x6b0);
      local_188 = *(undefined4 *)(param_1 + 0x6b4);
      local_618 = 0;
      local_180 = *(undefined8 *)(param_1 + 0x698);
      local_620 = 0;
      local_638 = &local_5b8;
      local_628 = (longlong **)((ulonglong)local_628 & 0xffffffff00000000);
      local_630 = (longlong *)0x0;
      local_5b8._0_2_ = 0x200;
      local_5b4 = 2;
      local_5b8._2_1_ = 8;
      local_160 = 0;
      local_610 = param_4;
      local_158 = local_190;
      local_154 = local_18c;
      FUN_1401483b0(&local_160,0,0,*(undefined4 *)(param_1 + 0x5a4));
      *(undefined4 *)(param_1 + 0x6c0) = 1;
    }
    fVar9 = DAT_1404af7e4;
    fVar8 = DAT_1404af7e0;
    fVar7 = DAT_1404af7dc;
    fVar6 = DAT_1404af7d8;
    fVar5 = DAT_1404af7d4;
    if ((param_2 != 0) && (*(int *)(param_1 + 0x6b8) == 0)) {
      uVar35 = *(uint *)(param_1 + 0x6a0);
      puVar21 = *(undefined1 **)(param_1 + 0x580);
      pbVar40 = *(byte **)(param_1 + 0x690);
      pbVar37 = *(byte **)(param_1 + 0x698);
      if ((uVar35 == *(int *)(param_1 + 0x6ac) * 2) &&
         (*(uint *)(param_1 + 0x6a4) == *(int *)(param_1 + 0x6b0) * 2)) {
        lVar33 = (longlong)*(int *)(param_1 + 0x578);
        local_608 = uVar35 >> 1;
        uVar25 = *(uint *)(param_1 + 0x6a4) >> 1;
        if (uVar25 != 0) {
          local_5e8 = (longlong)(int)((*(int *)(param_1 + 0x578) + uVar35 * -2) * 2);
          local_5d8 = (longlong)(*(int *)(param_1 + 0x6b4) + *(int *)(param_1 + 0x6ac) * -2);
          local_5e0 = (longlong)(int)(*(int *)(param_1 + 0x6a8) * 2 - uVar35);
          uVar38 = (ulonglong)uVar25;
          do {
            uVar41 = (ulonglong)local_608;
            if (local_608 != 0) {
              do {
                iVar10 = (&DAT_1408238e0)[*pbVar37];
                iVar2 = (&DAT_140822ce0)[pbVar37[1]];
                iVar36 = (&DAT_1408230e0)[*pbVar37] + (&DAT_1408234e0)[pbVar37[1]];
                iVar15 = (&DAT_140823ce0)[*pbVar40];
                iVar26 = (&DAT_140823ce0)[pbVar40[1]];
                iVar3 = (&DAT_140823ce0)[pbVar40[*(uint *)(param_1 + 0x6a8)]];
                iVar4 = (&DAT_140823ce0)[pbVar40[*(uint *)(param_1 + 0x6a8) + 1]];
                puVar21[2] = *(undefined1 *)
                              ((longlong)&DAT_1408227e0 +
                              (longlong)((iVar15 + iVar2 >> 0xe) + 0x200));
                puVar21[1] = *(undefined1 *)
                              ((longlong)&DAT_1408227e0 +
                              (longlong)((iVar15 + iVar36 >> 0xe) + 0x200));
                *puVar21 = *(undefined1 *)
                            ((longlong)&DAT_1408227e0 + (longlong)((iVar15 + iVar10 >> 0xe) + 0x200)
                            );
                puVar21[3] = 0xff;
                puVar21[6] = *(undefined1 *)
                              ((longlong)&DAT_1408227e0 +
                              (longlong)((iVar26 + iVar2 >> 0xe) + 0x200));
                puVar21[5] = *(undefined1 *)
                              ((longlong)&DAT_1408227e0 +
                              (longlong)((iVar26 + iVar36 >> 0xe) + 0x200));
                puVar21[4] = *(undefined1 *)
                              ((longlong)&DAT_1408227e0 +
                              (longlong)((iVar26 + iVar10 >> 0xe) + 0x200));
                puVar21[7] = 0xff;
                puVar21[lVar33 + 2] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar3 + iVar2 >> 0xe) + 0x200));
                puVar21[lVar33 + 1] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar3 + iVar36 >> 0xe) + 0x200));
                puVar21[lVar33] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar3 + iVar10 >> 0xe) + 0x200));
                puVar21[lVar33 + 3] = 0xff;
                pbVar40 = pbVar40 + 2;
                pbVar37 = pbVar37 + 2;
                puVar21[lVar33 + 6] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar4 + iVar2 >> 0xe) + 0x200));
                puVar21[lVar33 + 5] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar4 + iVar36 >> 0xe) + 0x200));
                puVar21[lVar33 + 4] =
                     *(undefined1 *)
                      ((longlong)&DAT_1408227e0 + (longlong)((iVar4 + iVar10 >> 0xe) + 0x200));
                puVar21[lVar33 + 7] = 0xff;
                puVar21 = puVar21 + 8;
                uVar41 = uVar41 - 1;
                local_5f8 = (ulonglong)local_608;
              } while (uVar41 != 0);
            }
            puVar21 = puVar21 + local_5e8;
            pbVar40 = pbVar40 + local_5e0;
            pbVar37 = pbVar37 + local_5d8;
            uVar38 = uVar38 - 1;
          } while (uVar38 != 0);
          local_600 = 0;
          local_5f0 = lVar33;
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x6a8);
        iVar2 = *(int *)(param_1 + 0x578);
        if (*(int *)(param_1 + 0x6a4) != 0) {
          uVar14 = uVar25;
          do {
            if (*(int *)(param_1 + 0x6a0) != 0) {
              uVar18 = uVar25;
              do {
                pbVar37 = (byte *)((longlong)(((int)uVar18 / 2) * 2) +
                                   (ulonglong)(uint)(((int)uVar14 / 2) * *(int *)(param_1 + 0x6b4))
                                  + *(longlong *)(param_1 + 0x698));
                fVar43 = (float)(int)(pbVar37[1] - 0x80);
                fVar44 = (float)(int)(*pbVar40 - 0x10) * fVar7;
                fVar42 = (float)(int)(*pbVar37 - 0x80);
                iVar26 = (int)(fVar43 * fVar8 + fVar44);
                iVar15 = (int)(fVar42 * fVar9 + fVar44);
                uVar22 = (uint)((fVar44 - fVar42 * fVar5) - fVar43 * fVar6);
                uVar13 = 0;
                uVar23 = uVar13;
                if ((-1 < iVar26) && (uVar23 = (char)iVar26, 0xff < iVar26)) {
                  uVar23 = 0xff;
                }
                uVar24 = uVar25;
                if ((-1 < (int)uVar22) && (uVar24 = uVar22, 0xff < (int)uVar22)) {
                  uVar24 = 0xff;
                }
                if ((-1 < iVar15) && (uVar13 = (undefined1)iVar15, 0xff < iVar15)) {
                  uVar13 = 0xff;
                }
                puVar21[2] = uVar23;
                uVar18 = uVar18 + 1;
                puVar21[1] = (char)uVar24;
                pbVar40 = pbVar40 + 1;
                *puVar21 = uVar13;
                puVar21[3] = 0xff;
                puVar21 = puVar21 + 4;
              } while (uVar18 < *(uint *)(param_1 + 0x6a0));
            }
            uVar14 = uVar14 + 1;
            puVar21 = puVar21 + (int)(iVar2 + uVar35 * -4);
            pbVar40 = pbVar40 + (int)(iVar10 - uVar35);
          } while (uVar14 < *(uint *)(param_1 + 0x6a4));
        }
      }
      *(undefined4 *)(param_1 + 0x6b8) = 1;
    }
    if (local_5d0 != (longlong *)0x0) {
      (**(code **)(*local_5d0 + 0x10))();
      local_5d0 = (longlong *)0x0;
    }
    if (local_5c8 != (longlong *)0x0) {
      (**(code **)(*local_5c8 + 0x10))();
    }
    uVar12 = 0;
  }
  return uVar12;
}


