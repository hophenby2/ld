// Function: FUN_14045bd50 @ 14045bd50
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14045bd50(longlong param_1,longlong param_2,int param_3,int param_4,undefined8 param_5,
                  float param_6,float param_7,uint param_8,int param_9,int param_10,
                  longlong param_11)

{
  byte bVar1;
  ulonglong uVar2;
  byte *pbVar3;
  uint *puVar4;
  ushort *puVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  ushort uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  int iVar20;
  ulonglong uVar21;
  longlong lVar22;
  uint *puVar23;
  byte bVar24;
  ushort uVar25;
  uint uVar26;
  ulonglong uVar27;
  longlong lVar28;
  byte *pbVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  ulonglong uVar33;
  int iVar34;
  int iVar35;
  ulonglong uVar36;
  longlong lVar37;
  uint uVar38;
  ulonglong uVar39;
  uint uVar40;
  int iVar41;
  ulonglong uVar42;
  int iVar43;
  uint uVar44;
  ulonglong uVar45;
  bool bVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  undefined1 auStack_1e8 [32];
  longlong local_1c8;
  int local_1b8;
  uint local_1b4;
  int local_1b0;
  undefined4 local_1ac;
  int local_1a8;
  int local_1a4;
  ulonglong local_1a0;
  uint local_198;
  ulonglong local_190;
  undefined4 *local_188;
  undefined4 *local_180;
  undefined4 *local_178;
  int local_170;
  longlong local_168;
  undefined *local_160;
  undefined8 local_158;
  int local_150;
  int local_14c;
  longlong local_148;
  longlong local_140;
  undefined4 *local_138;
  longlong local_130;
  undefined8 local_128;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  float local_108;
  float local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  ulonglong local_a0;
  
  local_a0 = DAT_1407c6b00 ^ (ulonglong)auStack_1e8;
  uVar2 = 0;
  lVar22 = *(longlong *)(param_2 + 0x20);
  lVar19 = *(longlong *)(param_1 + 0x20);
  local_148 = param_11;
  local_1b4 = 0;
  uVar8 = 0;
  if (*(int *)(lVar22 + 0x20) != 0) {
    uVar8 = param_8;
  }
  local_130 = 0;
  if (*(int *)(lVar22 + 0x28) != *(int *)(lVar19 + 0x28)) {
    return;
  }
  if (*(int *)(lVar19 + 0x2c) == 1) {
    return;
  }
  if (*(int *)(lVar19 + 0x34) == 1) {
    return;
  }
  local_1ac = uVar8;
  local_1a4 = param_3;
  local_168 = param_2;
  local_140 = param_1;
  local_190._0_4_ = param_4;
  FUN_1401ae590(lVar22,&local_104,&local_108);
  fVar47 = DAT_1405305e8;
  local_198 = (uint)(local_104 * DAT_1405305e8);
  local_1a8 = (int)(local_108 * DAT_1405305e8);
  FUN_1401ae590();
  local_138 = (undefined4 *)(ulonglong)*(uint *)(param_2 + 4);
  local_1a0 = (ulonglong)*(uint *)(param_2 + 8);
  param_3 = param_3 * 0x40000;
  param_4 = param_4 * 0x40000;
  fVar52 = (float)(int)(local_108 * fVar47);
  fVar49 = (float)(int)(local_104 * fVar47);
  fVar48 = (float)*(uint *)(param_2 + 4) * param_6 * DAT_140539d20;
  fVar47 = (float)local_1a0 * param_7 * DAT_140539d20;
  fVar51 = fVar52 * fVar48;
  fVar50 = fVar49 * fVar47;
  fVar47 = fVar52 * fVar47;
  fVar49 = fVar49 * fVar48;
  iVar30 = param_3 - (int)(fVar51 - fVar50);
  iVar34 = param_4 - (int)(fVar47 + fVar49);
  iVar41 = param_3 - (int)(fVar50 + fVar51);
  local_128 = CONCAT44(iVar41,iVar30);
  local_150 = (int)(fVar47 + fVar49) + param_4;
  local_120 = (int)(fVar51 - fVar50) + param_3;
  iVar43 = (int)(fVar47 - fVar49) + param_4;
  local_158 = CONCAT44(iVar43,iVar34);
  local_11c = (int)(fVar51 - (float)((uint)fVar50 ^ DAT_14053bf00)) + param_3;
  local_14c = (int)(fVar49 - fVar47) + param_4;
  uVar44 = iVar41 >> 0x1f;
  uVar9 = iVar43 >> 0x1f;
  uVar17 = iVar30 >> 0x1f;
  uVar40 = iVar34 >> 0x1f;
  uVar18 = local_11c >> 0x1f;
  uVar26 = local_14c >> 0x1f;
  uVar38 = local_120 >> 0x1f;
  uVar32 = local_150 >> 0x1f;
  if (param_9 == 0) {
    if (param_10 == 0) {
      uVar10 = 1;
      local_1b8 = (int)(fVar52 / param_6);
      iVar30 = (int)((float)(int)local_198 / param_7);
      uVar21 = uVar2;
      uVar27 = uVar2;
      uVar11 = uVar2;
      uVar33 = uVar2;
      uVar36 = uVar2;
      uVar39 = uVar2;
      uVar42 = uVar2;
      uVar45 = uVar2;
      do {
        iVar34 = *(int *)((longlong)&local_158 + uVar2 + 4);
        if (*(int *)((longlong)&local_158 + uVar36) < iVar34) {
          uVar36 = uVar2 + 4;
          uVar39 = uVar10;
        }
        if (iVar34 < *(int *)((longlong)&local_158 + uVar11)) {
          uVar11 = uVar2 + 4;
          uVar21 = uVar10;
        }
        iVar34 = *(int *)((longlong)&local_128 + uVar2 + 4);
        if (*(int *)((longlong)&local_128 + uVar33) < iVar34) {
          uVar33 = uVar2 + 4;
          uVar42 = uVar10;
        }
        if (iVar34 < *(int *)((longlong)&local_128 + uVar27)) {
          uVar27 = uVar2 + 4;
          uVar45 = uVar10;
        }
        uVar8 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar8;
        uVar2 = uVar2 + 4;
      } while ((int)uVar8 < 4);
      lVar22 = (longlong)(int)uVar39;
      iVar34 = *(int *)((longlong)&local_128 + (longlong)(int)uVar45 * 4);
      local_118 = ((int)(iVar34 + (iVar34 >> 0x1f & 0x3ffffU)) >> 0x12) + -2;
      iVar34 = *(int *)((longlong)&local_158 + (longlong)(int)uVar21 * 4);
      local_114 = ((int)(iVar34 + (iVar34 >> 0x1f & 0x3ffffU)) >> 0x12) + -2;
      iVar34 = *(int *)((longlong)&local_128 + (longlong)(int)uVar42 * 4);
      local_110 = ((int)(iVar34 + (iVar34 >> 0x1f & 0x3ffffU)) >> 0x12) + 4;
      iVar34 = *(int *)((longlong)&local_158 + lVar22 * 4);
      local_10c = ((int)(iVar34 + (iVar34 >> 0x1f & 0x3ffffU)) >> 0x12) + 4;
      local_170 = iVar30;
      local_160 = (undefined *)lVar22;
      FUN_14016c6a0(&local_118,&DAT_140c28a74);
      iVar34 = local_114;
      if ((local_118 != local_110) && (local_114 != local_10c)) {
        iVar16 = local_114 - (int)local_190;
        iVar35 = (local_118 - local_1a4) * local_1a8;
        iVar31 = (local_118 - local_1a4) * local_198;
        *(int *)((longlong)&local_158 + lVar22 * 4) = local_10c << 0x12;
        uVar8 = (int)((ulonglong)local_138 >> 1) * 0x40000;
        *(int *)((longlong)&local_158 + (longlong)(int)uVar21 * 4) = iVar34 * 0x40000;
        local_138 = (undefined4 *)(ulonglong)uVar8;
        iVar41 = *(int *)((longlong)&local_158 + (longlong)local_160 * 4);
        iVar43 = iVar41 + iVar34 * -0x40000;
        iVar20 = ((uint)local_1a0 >> 1) * 0x40000;
        uVar38 = (int)((float)(int)(iVar35 - iVar16 * local_198) / param_6) + uVar8;
        local_190._0_4_ = ((int)((iVar41 >> 0x1f & 0x3ffffU) + iVar41) >> 0x12) - (int)local_190;
        iVar41 = (int)(iVar43 + (iVar43 >> 0x1f & 0x3ffffU)) >> 0x12;
        uVar44 = (int)((float)(iVar16 * local_1a8 + iVar31) / param_7) + iVar20;
        if (iVar41 != 0) {
          local_1a4 = (int)(((int)((float)(int)(iVar35 - (int)local_190 * local_198) / param_6) -
                            uVar38) + uVar8) / iVar41;
          local_1a8 = (int)(((int)((float)((int)local_190 * local_1a8 + iVar31) / param_7) - uVar44)
                           + iVar20) / iVar41;
          local_128 = *(longlong *)(local_168 + 0x10);
          local_158 = *(longlong *)(local_168 + 0x20);
          local_190 = CONCAT44(local_190._4_4_,*(uint *)(local_158 + 0xc));
          local_1b0 = *(int *)(*(longlong *)(local_140 + 0x20) + 0xc);
          puVar23 = (uint *)((longlong)
                             (int)((uint)*(byte *)(*(longlong *)
                                                    (*(longlong *)(local_140 + 0x20) + 0x18) + 4) *
                                  local_118) + (ulonglong)(uint)(local_1b0 * iVar34) +
                            *(longlong *)(local_140 + 0x10));
          if (param_11 != 0) {
            local_130 = *(longlong *)(param_11 + 0x10);
            local_1b4 = *(uint *)(*(longlong *)(param_11 + 0x20) + 0xc);
          }
          uVar36 = (ulonglong)(int)DAT_140c28a88;
          lVar22 = *(longlong *)(local_158 + 0x48);
          local_198 = *(uint *)(local_158 + 0x24);
          local_160 = &DAT_140ba8d70 + uVar36 * 0x800;
          local_138 = &DAT_140b68970 + uVar36 * 0x100;
          local_188 = &DAT_140b68970 + (ulonglong)(DAT_140c28a8c >> 8 & 0xff) * 0x100;
          local_178 = &DAT_140b68970 + (ulonglong)(DAT_140c28a8c >> 0x10 & 0xff) * 0x100;
          local_180 = &DAT_140b68970 + (ulonglong)(DAT_140c28a8c & 0xff) * 0x100;
          local_1a0 = local_1a0 & 0xffffffff;
          uVar2 = 0;
          iVar34 = (int)(fVar52 / param_6);
          if (local_1a0 != 0) {
            local_190 = (ulonglong)*(uint *)(local_158 + 0xc);
            uVar11 = uVar2;
            lVar19 = local_128;
            do {
              (&DAT_140e318b0)[uVar11] = lVar19;
              uVar11 = uVar11 + 1;
              lVar19 = lVar19 + local_190;
              iVar34 = local_1b8;
            } while (uVar11 < local_1a0);
          }
          if ((param_11 != 0) && (uVar8 = *(uint *)(param_11 + 8), (ulonglong)uVar8 != 0)) {
            lVar19 = local_130;
            do {
              (&DAT_140e398b0)[uVar2] = lVar19;
              uVar2 = uVar2 + 1;
              lVar19 = lVar19 + (ulonglong)local_1b4;
              iVar30 = local_170;
            } while (uVar2 < uVar8);
          }
          if (*(int *)(local_158 + 0x2c) == 1) {
            iVar41 = 4;
            if (*(int *)(local_158 + 0x28) == 0) {
              iVar41 = 2;
            }
            FUN_1401ae2f0(&DAT_140e314b0,lVar22,(longlong)(iVar41 * *(int *)(local_158 + 0x30)));
            uVar36 = (ulonglong)DAT_140c28a88;
          }
          uVar9 = local_198;
          local_110 = local_110 - local_118;
          local_10c = local_10c - local_114;
          uVar17 = *(int *)(local_168 + 8) << 0x12;
          uVar40 = *(int *)(local_168 + 4) << 0x12;
          local_1a4 = local_1a4 - local_110 * iVar34;
          local_1a8 = local_1a8 - local_110 * iVar30;
          uVar8 = local_1b0 -
                  (uint)*(byte *)(*(longlong *)(*(longlong *)(local_140 + 0x20) + 0x18) + 4) *
                  local_110;
          lVar19 = *(longlong *)(local_168 + 0x20);
          iVar41 = (int)uVar36;
          if (*(int *)(lVar19 + 0x28) == 0) {
            if (*(int *)(lVar19 + 0x2c) == 1) {
              switch(DAT_140c28a84) {
              case 1:
                if (iVar41 != 0xff) {
                  if (iVar41 == 0) {
                    return;
                  }
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = *(byte *)((longlong)
                                                 ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (bVar24 != local_198) {
                                uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(local_188[uVar7 >> 5 & 0x3f] -
                                                     (uVar6 >> 5 & 0x3f)) * 4) + (uVar6 >> 5 & 0x3f)
                                     ) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)
                                                     ) * 4) + (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)
                                               (int)(local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) * 4)
                                     + (uVar6 & 0x1f);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)
                                                 ) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                            4) + (uVar7 >> 0xb)) * 0x800 |
                                 *(short *)(local_160 +
                                           (longlong)(int)(local_180[uVar6 & 0x1f] - (uVar7 & 0x1f))
                                           * 4) + (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uVar7 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4)
                                   + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uint)(uVar7 >> 0xb) - (uint)(uVar6 >> 0xb)) * 4
                                              ) + (uVar6 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)(int)((uVar7 & 0x1f) - (uVar6 & 0x1f)) * 4) +
                                   (uVar6 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)
                                                       ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                       0x3ffffU)) >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          *(ushort *)puVar23 =
                               (*(short *)(local_160 +
                                          (longlong)(int)((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f))
                                          * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                               (*(short *)(local_160 +
                                          (longlong)
                                          (int)((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4) +
                               (uVar7 >> 0xb)) * 0x800 |
                               *(short *)(local_160 +
                                         (longlong)(int)((uVar6 & 0x1f) - (uVar7 & 0x1f)) * 4) +
                               (uVar7 & 0x1f);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              uVar26 = (uint)uVar6;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              *(ushort *)puVar23 =
                                   (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                   (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar26 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                   (ushort)((local_180[uVar7 & 0x1f] - (uVar26 & 0x1f)) *
                                            (uint)bVar24 * DAT_140c28a88 + uVar26 * 0x10000 >> 0x10)
                                   & 0x1f;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar26 & 0xfffff800) * 0x20
                                       >> 5) & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24 *
                                        DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  iVar41 = local_110;
                  if (local_1ac != 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          iVar30 = local_170;
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            uVar26 = uVar6 & 0x1f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 *
                                          DAT_140c28a88 + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) &
                                 0x7e0 | (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) *
                                                  (uint)bVar24 * DAT_140c28a88 +
                                                  (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                                 (ushort)(((uVar7 & 0x1f) - uVar26) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar26 * 0x10000 >> 0x10);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  do {
                    do {
                      if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                        uVar9 = uVar44;
                        if ((int)uVar44 < 0) {
                          uVar9 = uVar44 + 0x3ffff;
                        }
                        uVar18 = uVar38;
                        if ((int)uVar38 < 0) {
                          uVar18 = uVar38 + 0x3ffff;
                        }
                        uVar26 = (uint)(ushort)*puVar23;
                        uVar7 = *(ushort *)
                                 (lVar22 + (ulonglong)
                                           *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                    (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                        bVar24 = (&DAT_140c28970)
                                 [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                        uVar9 = (ushort)*puVar23 & 0x1f;
                        *(ushort *)puVar23 =
                             (ushort)(((uVar7 & 0x7e0) - (uVar26 & 0x7e0)) * (uint)bVar24 *
                                      DAT_140c28a88 + (uVar26 & 0xffffffe0) * 0x10000 >> 0x10) &
                             0x7e0 | (ushort)(((uVar7 & 0xf800) - (uVar26 & 0xf800)) * (uint)bVar24
                                              * DAT_140c28a88 + (uVar26 & 0xfffff800) * 0x10000 >>
                                             0x10) & 0xf800 |
                             (ushort)(((uVar7 & 0x1f) - uVar9) * (uint)bVar24 * DAT_140c28a88 +
                                      uVar9 * 0x10000 >> 0x10);
                      }
                      uVar38 = uVar38 + iVar34;
                      uVar44 = uVar44 + iVar30;
                      puVar23 = (uint *)((longlong)puVar23 + 2);
                      iVar41 = iVar41 + -1;
                    } while (iVar41 != 0);
                    uVar38 = uVar38 + local_1a4;
                    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                    uVar44 = uVar44 + local_1a8;
                    local_10c = local_10c + -1;
                    iVar41 = local_110;
                  } while (local_10c != 0);
                  return;
                }
              case 0:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            *(ushort *)puVar23 =
                                 *(ushort *)
                                  (lVar22 + (ulonglong)
                                            *(byte *)((&DAT_140e318b0)[(int)uVar9 >> 0x12] +
                                                     (longlong)((int)uVar18 >> 0x12)) * 2);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              *(ushort *)puVar23 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (*(ushort *)(local_188 + (uVar7 >> 5 & 0x3f)) |
                                 *(short *)(local_178 + (uVar7 >> 0xb)) << 6) << 5 |
                                 *(ushort *)(local_180 + (uVar7 & 0x1f));
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              *(ushort *)puVar23 =
                                   (*(ushort *)(local_188 + (uVar7 >> 5 & 0x3f)) |
                                   *(short *)(local_178 + (uVar7 >> 0xb)) << 6) << 5 |
                                   *(ushort *)(local_180 + (uVar7 & 0x1f));
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7 << 8;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24 +
                                        (uVar26 & 0xfff80000) >> 8) & 0xf800 |
                               (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 +
                                        (uVar26 & 0xffffe000) >> 8) & 0x7e0 |
                               (ushort)(((uVar6 & 0x1f) - (uVar7 & 0x1f)) * (uint)bVar24 +
                                        (uVar26 & 0x1f00) >> 8);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            uVar26 = (uint)uVar6 << 8;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar24 +
                                          (uVar26 & 0xfff80000) >> 8) & 0xf800 |
                                 (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 +
                                          (uVar26 & 0xffffe000) >> 8) & 0x7e0 |
                                 (ushort)(((uVar7 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar24 +
                                          (uVar26 & 0x1f00) >> 8);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_178 + (uVar6 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar24 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar7 & 0x1f)) * (uint)bVar24 +
                                        (uVar7 & 0x1f) * 0x100 >> 8);
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                          (uint)bVar24 + (uVar6 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                                 ((*(short *)(local_178 + (uVar7 >> 0xb)) - (uVar6 >> 0xb)) *
                                  (ushort)bVar24 + (uVar6 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                 (ushort)((local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) * (uint)bVar24
                                          + (uVar6 & 0x1f) * 0x100 >> 8);
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 2:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       (lVar22 + (ulonglong)
                                                 *(byte *)((longlong)
                                                           ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                           0x3ffffU)) >> 0x12) +
                                                          (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2)
                              ;
                              uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                      *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(local_138 + (uVar7 & 0x1f));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = *(byte *)((longlong)
                                                 ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (bVar24 != local_198) {
                                uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                                uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                        *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                        *(short *)(local_138 + (uVar7 & 0x1f));
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       (lVar22 + (ulonglong)
                                                 *(byte *)((longlong)
                                                           ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                           0x3ffffU)) >> 0x12) +
                                                          (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2)
                              ;
                              uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                      *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) * 0x40)
                                      * 0x20 + *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f])
                              ;
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = *(byte *)((longlong)
                                                 ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (bVar24 != local_198) {
                                uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                                uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f])
                                        + *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) *
                                          0x40) * 0x20 +
                                        *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f]);
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    bVar46 = local_1ac == 0;
                    iVar41 = local_110;
                    local_1ac = local_110;
                    if (bVar46) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            uVar2 = (ulonglong)
                                    (byte)(&DAT_140c28970)
                                          [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                    (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar7 = (*(short *)(local_138 +
                                               (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)) * 0x40
                                    + *(short *)(local_138 +
                                                (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd))) * 0x20
                                    + *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                            uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 =
                                 (short)uVar9 - (short)(uVar9 >> 5) |
                                 ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            iVar30 = local_170;
                            iVar34 = local_1b8;
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar2 = (ulonglong)
                                      (byte)(&DAT_140c28970)
                                            [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar7 = (*(short *)(local_138 +
                                                 (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)) *
                                       0x40 + *(short *)(local_138 +
                                                        (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd))
                                      ) * 0x20 +
                                      *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          local_1ac = local_1ac + -1;
                        } while (local_1ac != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1ac = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar7 = (*(short *)(local_138 +
                                               (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8)) +
                                    *(short *)(local_138 +
                                              (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) * 0x40)
                                    * 0x20 + *(short *)(local_138 +
                                                       (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8)
                                                       );
                            uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 =
                                 (short)uVar9 - (short)(uVar9 >> 5) |
                                 ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar7 = (*(short *)(local_138 +
                                                 (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8))
                                      + *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) *
                                        0x40) * 0x20 +
                                      *(short *)(local_138 +
                                                (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 3:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                               *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                              *(short *)(local_138 + (uVar7 & 0x1f))) & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                                 *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20
                                                + *(short *)(local_138 + (uVar7 & 0x1f))) &
                                       0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 +
                                                          (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                               *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb])
                                               * 0x40) * 0x20 +
                                              *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f]))
                                     & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                                 *(short *)(local_138 +
                                                           (uint)local_178[uVar7 >> 0xb]) * 0x40) *
                                                 0x20 + *(short *)(local_138 +
                                                                  (uint)local_180[uVar7 & 0x1f])) &
                                       0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          uVar2 = (ulonglong)
                                  (byte)(&DAT_140c28970)
                                        [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                  (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                   ((ushort)((*(short *)(local_138 +
                                                        (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13
                                                        )) * 0x40 +
                                             *(short *)(local_138 +
                                                       (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd)))
                                             * 0x20 + *(short *)(local_138 +
                                                                ((uVar7 & 0x1f) * uVar2 >> 8))) &
                                   0xf7def7df);
                          uVar9 = uVar18 & 0x8210820;
                          *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          iVar30 = local_170;
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar2 = (ulonglong)
                                    (byte)(&DAT_140c28970)
                                          [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                    (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 +
                                                          (((ulonglong)uVar7 & 0xf800) * uVar2 >>
                                                          0x13)) * 0x40 +
                                               *(short *)(local_138 +
                                                         (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd)
                                                         )) * 0x20 +
                                              *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8)))
                                     & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                   ((ushort)((*(short *)(local_138 +
                                                        (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24
                                                        >> 8)) +
                                             *(short *)(local_138 +
                                                       (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)
                                                       ) * 0x40) * 0x20 +
                                            *(short *)(local_138 +
                                                      (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8))
                                            ) & 0xf7def7df);
                          uVar9 = uVar18 & 0x8210820;
                          *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 +
                                                          (local_188[uVar7 >> 5 & 0x3f] *
                                                           (uint)bVar24 >> 8)) +
                                               *(short *)(local_138 +
                                                         (local_178[uVar7 >> 0xb] * (uint)bVar24 >>
                                                         8)) * 0x40) * 0x20 +
                                              *(short *)(local_138 +
                                                        (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8
                                                        ))) & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 4:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (ushort)((uVar6 & 0xf800) * (uVar7 & 0xf800) >> 0x10) & 0xf800 |
                                 (ushort)((uVar6 & 0x7e0) * (uVar7 & 0x7e0) >> 0xb) & 0x7e0 |
                                 (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) >> 5);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (ushort)((uVar7 & 0xf800) * (uVar6 & 0xf800) >> 0x10) & 0xf800 |
                                   (ushort)((uVar7 & 0x7e0) * (uVar6 & 0x7e0) >> 0xb) & 0x7e0 |
                                   (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) >> 5);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) >> 1) &
                                 0x7e0 | *(short *)(local_178 + (uVar6 >> 0xb)) *
                                         (uVar7 >> 5 & 0x7c0) & 0xf800 |
                                 (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5);
                            iVar30 = local_170;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) >> 1)
                                   & 0x7e0 | *(short *)(local_178 + (uVar7 >> 0xb)) *
                                             (uVar6 >> 5 & 0x7c0) & 0xf800 |
                                   (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5);
                              iVar30 = local_170;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          uVar6 = (ushort)*puVar23;
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((uVar7 >> 5 & 0x3f) * (uVar6 >> 5 & 0x3f) * (uint)bVar24 >>
                                       9) & 0x7e0 |
                               (ushort)((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) * (uint)bVar24
                                       >> 2) & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) * (uint)bVar24 >> 0xd);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          iVar30 = local_170;
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar6 = (ushort)*puVar23;
                            *(ushort *)puVar23 =
                                 (ushort)((uVar7 >> 5 & 0x3f) * (uVar6 >> 5 & 0x3f) * (uint)bVar24
                                         >> 9) & 0x7e0 |
                                 (ushort)((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) * (uint)bVar24
                                         >> 2) & 0xf800 |
                                 (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) * (uint)bVar24 >> 0xd);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) *
                                        (uint)bVar24 >> 9) & 0x7e0 |
                               (ushort)(local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) *
                                        (uint)bVar24 >> 2) & 0xf800 |
                               (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) * (uint)bVar24 >>
                                       0xd);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) *
                                          (uint)bVar24 >> 9) & 0x7e0 |
                                 (ushort)(local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) *
                                          (uint)bVar24 >> 2) & 0xf800 |
                                 (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) * (uint)bVar24 >>
                                         0xd);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 10:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*(ushort *)
                                      (lVar22 + (ulonglong)
                                                *(byte *)((longlong)
                                                          ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                          0x3ffffU)) >> 0x12) +
                                                         (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4) +
                                 (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4)
                                 + (uVar7 >> 0xb)) * 0x800 |
                                 *(short *)(local_160 +
                                           (longlong)(int)((uVar6 & 0x1f) - (uVar7 & 0x1f)) * 4) +
                                 (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = (ushort)*puVar23;
                              uVar6 = ~*(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4)
                                   + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4
                                              ) + (uVar7 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)(int)((uVar6 & 0x1f) - (uVar7 & 0x1f)) * 4) +
                                   (uVar7 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*(ushort *)
                                      (lVar22 + (ulonglong)
                                                *(byte *)((longlong)
                                                          ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                          0x3ffffU)) >> 0x12) +
                                                         (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)
                                                 ) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                            4) + (uVar7 >> 0xb)) * 0x800 |
                                 *(short *)(local_160 +
                                           (longlong)(int)(local_180[uVar6 & 0x1f] - (uVar7 & 0x1f))
                                           * 4) + (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = (ushort)*puVar23;
                              uVar6 = ~*(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(local_188[uVar6 >> 5 & 0x3f] -
                                                   (uVar7 >> 5 & 0x3f)) * 4) + (uVar7 >> 5 & 0x3f))
                                   * 0x20 | (*(short *)(local_160 +
                                                       (longlong)
                                                       (int)(local_178[uVar6 >> 0xb] -
                                                            (uint)(uVar7 >> 0xb)) * 4) +
                                            (uVar7 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)(local_180[uVar6 & 0x1f] - (uVar7 & 0x1f)) * 4) +
                                   (uVar7 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar26 = (uint)(ushort)*puVar23;
                          uVar7 = ~*(ushort *)
                                    (lVar22 + (ulonglong)
                                              *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          uVar9 = (ushort)*puVar23 & 0x1f;
                          *(ushort *)puVar23 =
                               (ushort)(((uVar7 & 0x7e0) - (uVar26 & 0x7e0)) * (uint)bVar24 *
                                        DAT_140c28a88 + (uVar26 & 0xffffffe0) * 0x10000 >> 0x10) &
                               0x7e0 | (ushort)(((uVar7 & 0xf800) - (uVar26 & 0xf800)) *
                                                (uint)bVar24 * DAT_140c28a88 +
                                                (uVar26 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                               (ushort)(((uVar7 & 0x1f) - uVar9) * (uint)bVar24 * DAT_140c28a88 +
                                        uVar9 * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar26 = uVar7 & 0x1f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 *
                                          DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x10000 >> 0x10) &
                                 0x7e0 | (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) *
                                                  (uint)bVar24 * DAT_140c28a88 +
                                                  (uVar7 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                                 (ushort)(((uVar6 & 0x1f) - uVar26) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar26 * 0x10000 >> 0x10);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          uVar6 = ~*(ushort *)
                                    (lVar22 + (ulonglong)
                                              *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar26 & 0xfffff800) * 0x20
                                       >> 5) & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24 *
                                        DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = (ushort)*puVar23;
                            uVar26 = (uint)uVar7;
                            uVar6 = ~*(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar26 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24
                                          * DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 0xb:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            uVar9 = uVar7 >> 5 & 0x3f;
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(((uVar6 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) * 4) +
                                 (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) >> 5)
                                                 - (uint)(uVar7 >> 0xb)) * 4) + (uVar7 >> 0xb)) *
                                 0x800 | *(short *)(local_160 +
                                                   (longlong)
                                                   (int)(((uVar6 & 0x1f) * (uVar7 & 0x1f) >> 5) -
                                                        (uVar7 & 0x1f)) * 4) + (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              uVar9 = uVar6 >> 5 & 0x3f;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(((uVar7 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) * 4)
                                   + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) >>
                                                    5) - (uint)(uVar6 >> 0xb)) * 4) + (uVar6 >> 0xb)
                                   ) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)(((uVar7 & 0x1f) * (uVar6 & 0x1f) >> 5) -
                                                  (uVar6 & 0x1f)) * 4) + (uVar6 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = uVar7 >> 5 & 0x3f;
                            uVar6 = *(ushort *)
                                     (lVar22 + (ulonglong)
                                               *(byte *)((longlong)
                                                         ((int)(uVar38 + ((int)uVar38 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12) +
                                                        (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((local_188[uVar6 >> 5 & 0x3f] * uVar18 >> 6) -
                                                 uVar18) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                  5) - (uint)(uVar7 >> 0xb)) * 4) + (uVar7 >> 0xb))
                                 * 0x800 | *(short *)(local_160 +
                                                     (longlong)
                                                     (int)((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f)
                                                           >> 5) - (uVar7 & 0x1f)) * 4) +
                                           (uVar7 & 0x1f);
                            iVar30 = local_170;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                              uVar6 = (ushort)*puVar23;
                              uVar9 = uVar6 >> 5 & 0x3f;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_188[uVar7 >> 5 & 0x3f] * uVar9 >> 6) -
                                                   uVar9) * 4) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb)
                                                    >> 5) - (uint)(uVar6 >> 0xb)) * 4) +
                                   (uVar6 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                                  (uVar6 & 0x1f)) * 4) + (uVar6 & 0x1f);
                              iVar30 = local_170;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar32 = (uint)uVar7;
                          uVar26 = uVar7 >> 5 & 0x3f;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          uVar9 = uVar32 & 0x1f;
                          *(ushort *)puVar23 =
                               (ushort)((int)((((uVar6 >> 5 & 0x3f) * uVar26 >> 6) - uVar26) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                             (uVar32 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                               (ushort)((int)((((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) >> 5) -
                                              (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                             (uVar32 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                               (ushort)((((uVar6 & 0x1f) * uVar9 >> 5) - uVar9) * (uint)bVar24 *
                                        DAT_140c28a88 + uVar9 * 0x10000 >> 0x10);
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar9 = uVar6 >> 5 & 0x3f;
                            uVar18 = uVar6 & 0x1f;
                            *(ushort *)puVar23 =
                                 (ushort)((int)((((uVar7 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) *
                                                (uint)bVar24 * DAT_140c28a88 +
                                               (uVar6 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                                 (ushort)((int)((((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) >> 5)
                                                - (uint)(uVar6 >> 0xb)) * (uint)bVar24 *
                                                DAT_140c28a88 + (uVar6 & 0xfffff800) * 0x20) >> 5) &
                                 0xf800 | (ushort)((((uVar7 & 0x1f) * uVar18 >> 5) - uVar18) *
                                                   (uint)bVar24 * DAT_140c28a88 + uVar18 * 0x10000
                                                  >> 0x10);
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar32 = (uint)uVar7;
                          uVar26 = uVar7 >> 5 & 0x3f;
                          uVar6 = *(ushort *)
                                   (lVar22 + (ulonglong)
                                             *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]) * 2);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(((local_188[uVar6 >> 5 & 0x3f] * uVar26 >> 6) - uVar26) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar32 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)(((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                        (uVar32 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)(((local_180[uVar6 & 0x1f] * (uVar32 & 0x1f) >> 5) -
                                        (uVar32 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                        uVar32 * 0x10000 >> 0x10) & 0x1f;
                          iVar30 = local_170;
                          iVar34 = local_1b8;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (bVar24 != local_198) {
                            uVar7 = *(ushort *)(lVar22 + (ulonglong)bVar24 * 2);
                            uVar6 = (ushort)*puVar23;
                            uVar32 = (uint)uVar6;
                            uVar26 = uVar6 >> 5 & 0x3f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((local_188[uVar7 >> 5 & 0x3f] * uVar26 >> 6) - uVar26) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar32 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)(((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) >> 5) -
                                          (uint)(uVar6 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar32 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)(((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                          (uVar6 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar32 * 0x10000 >> 0x10) & 0x1f;
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
              }
            }
            else {
              switch(DAT_140c28a84) {
              case 1:
                if (iVar41 != 0xff) {
                  if (iVar41 == 0) {
                    return;
                  }
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                        iVar41 = local_110;
                        if (local_1ac != 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                uVar7 = *(ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                if (uVar7 != local_198) {
                                  uVar6 = (ushort)*puVar23;
                                  *(ushort *)puVar23 =
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)(local_188[uVar7 >> 5 & 0x3f] -
                                                       (uVar6 >> 5 & 0x3f)) * 4) +
                                       (uVar6 >> 5 & 0x3f)) * 0x20 |
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)(local_178[uVar7 >> 0xb] -
                                                       (uint)(uVar6 >> 0xb)) * 4) + (uVar6 >> 0xb))
                                       * 0x800 | *(short *)(local_160 +
                                                           (longlong)
                                                           (int)(local_180[uVar7 & 0x1f] -
                                                                (uVar6 & 0x1f)) * 4) +
                                                 (uVar6 & 0x1f);
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                          return;
                        }
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = (ushort)*puVar23;
                              uVar6 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(local_188[uVar6 >> 5 & 0x3f] -
                                                   (uVar7 >> 5 & 0x3f)) * 4) + (uVar7 >> 5 & 0x3f))
                                   * 0x20 | (*(short *)(local_160 +
                                                       (longlong)
                                                       (int)(local_178[uVar6 >> 0xb] -
                                                            (uint)(uVar7 >> 0xb)) * 4) +
                                            (uVar7 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)(local_180[uVar6 & 0x1f] - (uVar7 & 0x1f)) * 4) +
                                   (uVar7 & 0x1f);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  uVar7 = *puVar5;
                                  uVar6 = (ushort)*puVar23;
                                  *(ushort *)puVar23 =
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)(local_188[uVar7 >> 5 & 0x3f] -
                                                       (uVar6 >> 5 & 0x3f)) * 4) +
                                       (uVar6 >> 5 & 0x3f)) * 0x20 |
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)(local_178[uVar7 >> 0xb] -
                                                       (uint)(uVar6 >> 0xb)) * 4) + (uVar6 >> 0xb))
                                       * 0x800 | *(short *)(local_160 +
                                                           (longlong)
                                                           (int)(local_180[uVar7 & 0x1f] -
                                                                (uVar6 & 0x1f)) * 4) +
                                                 (uVar6 & 0x1f);
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar6 = (ushort)*puVar23;
                                  uVar9 = (uint)uVar6;
                                  *(ushort *)puVar23 =
                                       (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f))
                                                * (uint)bVar24 * DAT_140c28a88 +
                                                (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                       (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                                (uint)bVar24 * DAT_140c28a88 +
                                                (uVar9 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                       (ushort)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                                (uint)bVar24 * DAT_140c28a88 + uVar9 * 0x10000 >>
                                               0x10) & 0x1f;
                                }
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = (uint)uVar7;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar6 = *puVar5;
                            bVar24 = (byte)puVar5[1];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar18 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_180[uVar6 & 0x1f] - (uVar18 & 0x1f)) * (uint)bVar24
                                          * DAT_140c28a88 + uVar18 * 0x10000 >> 0x10) & 0x1f;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uVar7 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4
                                                ) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uint)(uVar7 >> 0xb) - (uint)(uVar6 >> 0xb)) *
                                                4) + (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)(int)((uVar7 & 0x1f) - (uVar6 & 0x1f)) * 4)
                                     + (uVar6 & 0x1f);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4) +
                                 (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4)
                                 + (uVar7 >> 0xb)) * 0x800 |
                                 *(short *)(local_160 +
                                           (longlong)(int)((uVar6 & 0x1f) - (uVar7 & 0x1f)) * 4) +
                                 (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uVar7 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4
                                                ) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uint)(uVar7 >> 0xb) - (uint)(uVar6 >> 0xb)) *
                                                4) + (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)(int)((uVar7 & 0x1f) - (uVar6 & 0x1f)) * 4)
                                     + (uVar6 & 0x1f);
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar9 = (uint)(ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (ushort)(((uVar7 & 0xf800) - (uVar9 & 0xf800)) * (uint)bVar24 *
                                              DAT_140c28a88 +
                                              ((ushort)*puVar23 & 0xfffff800) * 0x10000 >> 0x10) &
                                     0xf800 | (ushort)(((uVar7 & 0x7e0) - (uVar9 & 0x7e0)) *
                                                       (uint)bVar24 * DAT_140c28a88 +
                                                       (uVar9 & 0xffffffe0) * 0x10000 >> 0x10) &
                                              0x7e0 |
                                     (ushort)(((uVar7 & 0x1f) - (uVar9 & 0x1f)) * (uint)bVar24 *
                                              DAT_140c28a88 + (uVar9 & 0x1f) * 0x10000 >> 0x10);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)
                                    (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) << 2
                                    ) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar7 = (ushort)*puVar23;
                          uVar9 = uVar7 & 0x1f;
                          uVar6 = *puVar5;
                          bVar24 = (byte)puVar5[1];
                          *(ushort *)puVar23 =
                               (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24 *
                                        DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x10000 >> 0x10) &
                               0xf800 | (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24
                                                 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x10000 >>
                                                0x10) & 0x7e0 |
                               (ushort)(((uVar6 & 0x1f) - uVar9) * (uint)bVar24 * DAT_140c28a88 +
                                        uVar9 * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar6 = (ushort)*puVar23;
                                uVar26 = (uint)uVar6;
                                bVar24 = (&DAT_140c28970)
                                         [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                   (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                *(ushort *)puVar23 =
                                     (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                     (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar26 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                     (ushort)((local_180[uVar7 & 0x1f] - (uVar26 & 0x1f)) *
                                              (uint)bVar24 * DAT_140c28a88 + uVar26 * 0x10000 >>
                                             0x10) & 0x1f;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar26 = (uint)uVar7;
                            uVar6 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar26 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24
                                          * DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6;
                                bVar24 = (&DAT_140c28970)[*pbVar3];
                                *(ushort *)puVar23 =
                                     (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                     (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar9 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                     (ushort)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                              (uint)bVar24 * DAT_140c28a88 + uVar9 * 0x10000 >> 0x10
                                             ) & 0x1f;
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6;
                                bVar1 = (&DAT_140c28970)[*pbVar3];
                                *(ushort *)puVar23 =
                                     (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                              (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                              (uVar6 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                     (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                              (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                              (uVar9 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                                     (byte)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                            (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                            uVar9 * 0x1000000 >> 0x18) & 0x1f;
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar6 = *puVar5;
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          bVar1 = (byte)puVar5[1];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar1 * (uint)bVar24 * DAT_140c28a88 +
                                        (uVar7 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar1 * (uint)bVar24 * DAT_140c28a88 +
                                        (uVar26 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                               (byte)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar1 *
                                      (uint)bVar24 * DAT_140c28a88 + uVar26 * 0x1000000 >> 0x18) &
                               0x1f;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                    bVar46 = local_1ac != 0;
                    iVar41 = local_110;
                    local_1ac = local_110;
                    if (bVar46) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar26 = (uint)uVar7;
                            iVar30 = local_170;
                            if (uVar26 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar32 = uVar6 & 0x1f;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar30 = (int)uVar36;
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 *
                                            iVar30 + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0
                                   | (ushort)(((uVar26 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar24
                                              * iVar30 + (uVar6 & 0xfffff800) * 0x10000 >> 0x10) &
                                     0xf800 |
                                   (ushort)(((uVar26 & 0x1f) - uVar32) * (uint)bVar24 * iVar30 +
                                            uVar32 * 0x10000 >> 0x10);
                              uVar36 = (ulonglong)DAT_140c28a88;
                              iVar30 = local_170;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          local_1ac = local_1ac + -1;
                        } while (local_1ac != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1ac = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar26 = uVar7 & 0x1f;
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 *
                                        DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x10000 >> 0x10) &
                               0x7e0 | (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24
                                                * DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x10000 >>
                                               0x10) & 0xf800 |
                               (ushort)(((uVar6 & 0x1f) - uVar26) * (uint)bVar24 * DAT_140c28a88 +
                                        uVar26 * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  iVar41 = local_110;
                  if (local_1ac != 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)puVar5[1];
                          if (bVar24 != 0) {
                            uVar7 = (ushort)*puVar23;
                            uVar9 = (uint)uVar7;
                            if (bVar24 == 0xff) {
                              uVar7 = *puVar5;
                              bVar24 = (&DAT_140c28970)[*pbVar3];
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar7 & 0x7e0) - (uVar9 & 0x7e0)) * (uint)bVar24 *
                                            DAT_140c28a88 + (uVar9 & 0xffffffe0) * 0x10000 >> 0x10)
                                   & 0x7e0 | (ushort)(((uVar7 & 0xf800) - (uVar9 & 0xf800)) *
                                                      (uint)bVar24 * DAT_140c28a88 +
                                                      (uVar9 & 0xfffff800) * 0x10000 >> 0x10) &
                                             0xf800 |
                                   (ushort)(((uVar7 & 0x1f) - (uVar9 & 0x1f)) * (uint)bVar24 *
                                            DAT_140c28a88 + (uVar9 & 0x1f) * 0x10000 >> 0x10);
                            }
                            else {
                              uVar6 = *puVar5;
                              bVar1 = (&DAT_140c28970)[*pbVar3];
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) *
                                            (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                            (uVar9 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                   (ushort)(((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) *
                                            (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                            (uVar9 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                                   (ushort)(byte)(((uVar6 & 0x1f) - (uVar9 & 0x1f)) * (uint)bVar24 *
                                                  (uint)bVar1 * DAT_140c28a88 +
                                                  (uVar9 & 0x1f) * 0x1000000 >> 0x18);
                            }
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  do {
                    do {
                      if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                        uVar9 = uVar44;
                        if ((int)uVar44 < 0) {
                          uVar9 = uVar44 + 0x3ffff;
                        }
                        uVar18 = uVar38;
                        if ((int)uVar38 < 0) {
                          uVar18 = uVar38 + 0x3ffff;
                        }
                        puVar5 = (ushort *)
                                 ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                        uVar7 = (ushort)*puVar23;
                        uVar6 = *puVar5;
                        bVar24 = (&DAT_140c28970)
                                 [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                        bVar1 = (byte)puVar5[1];
                        *(ushort *)puVar23 =
                             (ushort)(((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * (uint)bVar1 *
                                      (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x80000
                                     >> 0x13) & 0x7e0 |
                             (ushort)(((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * (uint)bVar1 *
                                      (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x2000
                                     >> 0xd) & 0xf800 |
                             (ushort)(byte)(((uVar6 & 0x1f) - (uVar7 & 0x1f)) * (uint)bVar1 *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar7 & 0x1f) * 0x1000000 >> 0x18);
                      }
                      uVar38 = uVar38 + iVar34;
                      uVar44 = uVar44 + iVar30;
                      puVar23 = (uint *)((longlong)puVar23 + 2);
                      iVar41 = iVar41 + -1;
                    } while (iVar41 != 0);
                    uVar38 = uVar38 + local_1a4;
                    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                    uVar44 = uVar44 + local_1a8;
                    local_10c = local_10c + -1;
                    iVar41 = local_110;
                  } while (local_10c != 0);
                  return;
                }
              case 0:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = (ushort)*puVar23;
                              uVar9 = uVar7 & 0x1f;
                              uVar6 = *puVar5;
                              bVar24 = (byte)puVar5[1];
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24 +
                                            (uVar7 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                                   (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 +
                                            (uVar7 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                                   (ushort)(((uVar6 & 0x1f) - uVar9) * (uint)bVar24 + uVar9 * 0x100
                                           >> 8);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  *(ushort *)puVar23 = *puVar5;
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar9 = (uint)(ushort)*puVar23;
                                  uVar18 = (ushort)*puVar23 & 0x1f;
                                  *(ushort *)puVar23 =
                                       (ushort)(((uVar7 & 0xf800) - (uVar9 & 0xf800)) * (uint)bVar24
                                                + (uVar9 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                                       (ushort)(((uVar7 & 0x7e0) - (uVar9 & 0x7e0)) * (uint)bVar24 +
                                                (uVar9 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                                       (ushort)(((uVar7 & 0x1f) - uVar18) * (uint)bVar24 +
                                                uVar18 * 0x100 >> 8);
                                }
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              *(ushort *)puVar23 =
                                   *(ushort *)
                                    ((longlong)
                                     (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                     ) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                *(ushort *)puVar23 = uVar7;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = uVar7 & 0x1f;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar6 = *puVar5;
                            bVar24 = (byte)puVar5[1];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar24 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                                 ((*(short *)(local_178 + (uVar6 >> 0xb)) - (uVar7 >> 0xb)) *
                                  (ushort)bVar24 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                 (ushort)((local_180[uVar6 & 0x1f] - uVar18) * (uint)bVar24 +
                                          uVar18 * 0x100 >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                *(ushort *)puVar23 =
                                     (*(ushort *)(local_188 + (uVar7 >> 5 & 0x3f)) |
                                     *(short *)(local_178 + (uVar7 >> 0xb)) << 6) << 5 |
                                     *(ushort *)(local_180 + (uVar7 & 0x1f));
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                              (uint)bVar24 + (uVar6 & 0xffffffe0) * 8 >> 3) & 0x7e0
                                     | ((*(short *)(local_178 + (uVar7 >> 0xb)) - (uVar6 >> 0xb)) *
                                        (ushort)bVar24 + (uVar6 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                     (ushort)((local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) *
                                              (uint)bVar24 + (uVar6 & 0x1f) * 0x100 >> 8);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(ushort *)puVar23 =
                                 (*(ushort *)(local_188 + (uVar7 >> 5 & 0x3f)) |
                                 *(short *)(local_178 + (uVar7 >> 0xb)) << 6) << 5 |
                                 *(ushort *)(local_180 + (uVar7 & 0x1f));
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              *(ushort *)puVar23 =
                                   (*(ushort *)(local_188 + (uVar7 >> 5 & 0x3f)) |
                                   *(short *)(local_178 + (uVar7 >> 0xb)) << 6) << 5 |
                                   *(ushort *)(local_180 + (uVar7 & 0x1f));
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar26 = (uint)uVar7 << 0x10;
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar6 = *puVar5;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            bVar1 = (byte)puVar5[1];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar1 *
                                          (uint)bVar24 + (uVar26 & 0xf8000000) >> 0x10) & 0xf800 |
                                 (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar1 *
                                          (uint)bVar24 + (uVar26 & 0xffe00000) >> 0x10) & 0x7e0 |
                                 (ushort)(((uVar6 & 0x1f) - (uVar7 & 0x1f)) * (uint)bVar1 *
                                          (uint)bVar24 + (uVar26 & 0x1f0000) >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6 << 8;
                                bVar24 = (&DAT_140c28970)[*pbVar3];
                                *(ushort *)puVar23 =
                                     (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar24 +
                                              (uVar9 & 0xfff80000) >> 8) & 0xf800 |
                                     (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 +
                                              (uVar9 & 0xffffe000) >> 8) & 0x7e0 |
                                     (ushort)(((uVar7 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar24 +
                                              (uVar9 & 0x1f00) >> 8);
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6 << 0x10;
                                bVar1 = (&DAT_140c28970)[*pbVar3];
                                *(ushort *)puVar23 =
                                     (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar24 *
                                              (uint)bVar1 + (uVar9 & 0xf8000000) >> 0x10) & 0xf800 |
                                     (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 *
                                              (uint)bVar1 + (uVar9 & 0xffe00000) >> 0x10) & 0x7e0 |
                                     (ushort)(((uVar7 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar24 *
                                              (uint)bVar1 + (uVar9 & 0x1f0000) >> 0x10);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar26 = (uint)uVar7 << 8;
                            uVar6 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24 +
                                          (uVar26 & 0xfff80000) >> 8) & 0xf800 |
                                 (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 +
                                          (uVar26 & 0xffffe000) >> 8) & 0x7e0 |
                                 (ushort)(((uVar6 & 0x1f) - (uVar7 & 0x1f)) * (uint)bVar24 +
                                          (uVar26 & 0x1f00) >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar26 = (uint)uVar6 << 8;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar24 +
                                            (uVar26 & 0xfff80000) >> 8) & 0xf800 |
                                   (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 +
                                            (uVar26 & 0xffffe000) >> 8) & 0x7e0 |
                                   (ushort)(((uVar7 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar24 +
                                            (uVar26 & 0x1f00) >> 8);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          uVar6 = *puVar5;
                          bVar24 = (byte)puVar5[1];
                          bVar1 = (&DAT_140c28970)
                                  [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 * (uint)bVar1 + (uVar26 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar24 * (uint)bVar1 + (uVar26 & 0xfffff800) * 0x20 >>
                                       5) & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24 *
                                        (uint)bVar1 + (uVar26 & 0x1f) * 0x10000 >> 0x10);
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)puVar5[1];
                          if (bVar24 != 0) {
                            uVar7 = *puVar5;
                            bVar1 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 == 0xff) {
                              uVar6 = (ushort)*puVar23;
                              bVar24 = (&DAT_140c28970)[bVar1];
                              *(ushort *)puVar23 =
                                   (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                            (uint)bVar24 + (uVar6 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                                   ((*(short *)(local_178 + (uVar7 >> 0xb)) - (uVar6 >> 0xb)) *
                                    (ushort)bVar24 + (uVar6 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                   (ushort)((local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) *
                                            (uint)bVar24 + (uVar6 & 0x1f) * 0x100 >> 8);
                            }
                            else {
                              uVar6 = (ushort)*puVar23;
                              uVar9 = (uint)uVar6;
                              bVar1 = (&DAT_140c28970)[bVar1];
                              *(ushort *)puVar23 =
                                   (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                            (uint)bVar24 * (uint)bVar1 +
                                            (uVar9 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                   (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                            (uint)bVar24 * (uint)bVar1 + (uVar9 & 0xfffff800) * 0x20
                                           >> 5) & 0xf800 |
                                   (ushort)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                            (uint)bVar24 * (uint)bVar1 + (uVar9 & 0x1f) * 0x10000 >>
                                           0x10);
                              iVar30 = local_170;
                            }
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_178 + (uVar6 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar24 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar7 & 0x1f)) * (uint)bVar24 +
                                        (uVar7 & 0x1f) * 0x100 >> 8);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (uVar7 != local_198) {
                            uVar6 = (ushort)*puVar23;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                          (uint)bVar24 + (uVar6 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                                 ((*(short *)(local_178 + (uVar7 >> 0xb)) - (uVar6 >> 0xb)) *
                                  (ushort)bVar24 + (uVar6 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                 (ushort)((local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) * (uint)bVar24
                                          + (uVar6 & 0x1f) * 0x100 >> 8);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 2:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar5 = (ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                uVar7 = *puVar5;
                                uVar2 = (ulonglong)(byte)puVar5[1];
                                uVar7 = (*(short *)(local_138 +
                                                   (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)) *
                                         0x40 + *(short *)(local_138 +
                                                          (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd
                                                          ))) * 0x20 +
                                        *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar5 = (ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                bVar24 = (byte)puVar5[1];
                                if (bVar24 != 0) {
                                  if (bVar24 == 0xff) {
                                    uVar7 = *puVar5;
                                    uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                            *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                            *(short *)(local_138 + (uVar7 & 0x1f));
                                  }
                                  else {
                                    uVar7 = *puVar5;
                                    uVar2 = (ulonglong)bVar24;
                                    uVar7 = (*(short *)(local_138 +
                                                       (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)
                                                       ) * 0x40 +
                                            *(short *)(local_138 +
                                                      (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd)))
                                            * 0x20 + *(short *)(local_138 +
                                                               ((uVar7 & 0x1f) * uVar2 >> 8));
                                  }
                                  uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                  uVar9 = uVar18 & 0x8210820;
                                  *(ushort *)puVar23 =
                                       (short)uVar9 - (short)(uVar9 >> 5) |
                                       ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                      else {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                uVar7 = *(ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                        *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                        *(short *)(local_138 + (uVar7 & 0x1f));
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                uVar7 = *(ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                if (uVar7 != local_198) {
                                  uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                          *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                          *(short *)(local_138 + (uVar7 & 0x1f));
                                  uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                  uVar9 = uVar18 & 0x8210820;
                                  *(ushort *)puVar23 =
                                       (short)uVar9 - (short)(uVar9 >> 5) |
                                       ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                    }
                    else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = *puVar5;
                              uVar2 = (ulonglong)(byte)puVar5[1];
                              uVar7 = (*(short *)(local_138 +
                                                 (uint)local_178[((ulonglong)uVar7 & 0xf800) * uVar2
                                                                 >> 0x13]) * 0x40 +
                                      *(short *)(local_138 +
                                                (uint)local_188[((ulonglong)uVar7 & 0x7e0) * uVar2
                                                                >> 0xd])) * 0x20 +
                                      *(short *)(local_138 +
                                                (uint)local_180[(uVar7 & 0x1f) * uVar2 >> 8]);
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  uVar7 = *puVar5;
                                  uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f]
                                                     ) +
                                          *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) *
                                          0x40) * 0x20 +
                                          *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f]);
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar2 = (ulonglong)bVar24;
                                  uVar7 = (*(short *)(local_138 +
                                                     (uint)local_178[((ulonglong)uVar7 & 0xf800) *
                                                                     uVar2 >> 0x13]) * 0x40 +
                                          *(short *)(local_138 +
                                                    (uint)local_188[((ulonglong)uVar7 & 0x7e0) *
                                                                    uVar2 >> 0xd])) * 0x20 +
                                          *(short *)(local_138 +
                                                    (uint)local_180[(uVar7 & 0x1f) * uVar2 >> 8]);
                                }
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                      *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) * 0x40)
                                      * 0x20 + *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f])
                              ;
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f])
                                        + *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) *
                                          0x40) * 0x20 +
                                        *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f]);
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = *puVar5;
                              uVar36 = (ulonglong)
                                       (byte)(&DAT_140c28970)
                                             [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                       (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar2 = (ulonglong)(byte)puVar5[1];
                              uVar7 = (*(short *)(local_138 +
                                                 (((ulonglong)uVar7 & 0xf800) * uVar36 * uVar2 >>
                                                 0x1b)) * 0x40 +
                                      *(short *)(local_138 +
                                                (((ulonglong)uVar7 & 0x7e0) * uVar36 * uVar2 >> 0x15
                                                ))) * 0x20 +
                                      *(short *)(local_138 +
                                                ((uVar7 & 0x1f) * uVar36 * uVar2 >> 0x10));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if ((char)puVar5[1] != '\0') {
                                uVar2 = (ulonglong)
                                        (byte)(&DAT_140c28970)
                                              [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                if ((char)puVar5[1] == -1) {
                                  uVar7 = *puVar5;
                                  uVar7 = (*(short *)(local_138 +
                                                     (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13))
                                           * 0x40 + *(short *)(local_138 +
                                                              (((ulonglong)uVar7 & 0x7e0) * uVar2 >>
                                                              0xd))) * 0x20 +
                                          *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar36 = (ulonglong)(byte)puVar5[1];
                                  uVar7 = (*(short *)(local_138 +
                                                     (((ulonglong)uVar7 & 0xf800) * uVar2 * uVar36
                                                     >> 0x1b)) * 0x40 +
                                          *(short *)(local_138 +
                                                    (((ulonglong)uVar7 & 0x7e0) * uVar2 * uVar36 >>
                                                    0x15))) * 0x20 +
                                          *(short *)(local_138 +
                                                    ((uVar7 & 0x1f) * uVar2 * uVar36 >> 0x10));
                                }
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      bVar46 = local_1ac == 0;
                      iVar41 = local_110;
                      local_1ac = local_110;
                      if (bVar46) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              uVar2 = (ulonglong)
                                      (byte)(&DAT_140c28970)
                                            [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar7 = *(ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = (*(short *)(local_138 +
                                                 (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)) *
                                       0x40 + *(short *)(local_138 +
                                                        (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd))
                                      ) * 0x20 +
                                      *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              iVar30 = local_170;
                              iVar34 = local_1b8;
                              if (uVar7 != local_198) {
                                uVar2 = (ulonglong)
                                        (byte)(&DAT_140c28970)
                                              [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                uVar7 = (*(short *)(local_138 +
                                                   (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)) *
                                         0x40 + *(short *)(local_138 +
                                                          (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd
                                                          ))) * 0x20 +
                                        *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                                uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) |
                                     ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            local_1ac = local_1ac + -1;
                          } while (local_1ac != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          local_1ac = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            uVar7 = *puVar5;
                            bVar1 = (&DAT_140c28970)
                                    [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar7 = (*(short *)(local_138 +
                                               (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 *
                                                (uint)bVar1 >> 0x10)) +
                                    *(short *)(local_138 +
                                              (local_178[uVar7 >> 0xb] * (uint)bVar24 * (uint)bVar1
                                              >> 0x10)) * 0x40) * 0x20 +
                                    *(short *)(local_138 +
                                              (local_180[uVar7 & 0x1f] * (uint)bVar24 * (uint)bVar1
                                              >> 0x10));
                            uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 =
                                 (short)uVar9 - (short)(uVar9 >> 5) |
                                 ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                bVar24 = (&DAT_140c28970)[*pbVar3];
                                uVar7 = (*(short *)(local_138 +
                                                   (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8
                                                   )) +
                                        *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) *
                                        0x40) * 0x20 +
                                        *(short *)(local_138 +
                                                  (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8));
                              }
                              else {
                                uVar7 = *puVar5;
                                bVar1 = (&DAT_140c28970)[*pbVar3];
                                uVar7 = (*(short *)(local_138 +
                                                   (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 *
                                                    (uint)bVar1 >> 0x10)) +
                                        *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 *
                                                   (uint)bVar1 >> 0x10)) * 0x40) * 0x20 +
                                        *(short *)(local_138 +
                                                  (local_180[uVar7 & 0x1f] * (uint)bVar24 *
                                                   (uint)bVar1 >> 0x10));
                              }
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar7 = (*(short *)(local_138 +
                                               (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8)) +
                                    *(short *)(local_138 +
                                              (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) * 0x40)
                                    * 0x20 + *(short *)(local_138 +
                                                       (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8)
                                                       );
                            uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 =
                                 (short)uVar9 - (short)(uVar9 >> 5) |
                                 ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar7 = (*(short *)(local_138 +
                                                 (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8))
                                      + *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) *
                                        0x40) * 0x20 +
                                      *(short *)(local_138 +
                                                (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8));
                              uVar18 = ((ushort)*puVar23 & 0xf7def7df) + (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) |
                                   ((ushort)*puVar23 | uVar7) & 0x820 | (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 3:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar5 = (ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                uVar7 = *puVar5;
                                uVar2 = (ulonglong)(byte)puVar5[1];
                                uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                         ((ushort)((*(short *)(local_138 +
                                                              (((ulonglong)uVar7 & 0xf800) * uVar2
                                                              >> 0x13)) * 0x40 +
                                                   *(short *)(local_138 +
                                                             (((ulonglong)uVar7 & 0x7e0) * uVar2 >>
                                                             0xd))) * 0x20 +
                                                  *(short *)(local_138 +
                                                            ((uVar7 & 0x1f) * uVar2 >> 8))) &
                                         0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar5 = (ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                bVar24 = (byte)puVar5[1];
                                if (bVar24 != 0) {
                                  if (bVar24 == 0xff) {
                                    uVar7 = *puVar5;
                                    uVar7 = (*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                            *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) * 0x20 +
                                            *(short *)(local_138 + (uVar7 & 0x1f));
                                  }
                                  else {
                                    uVar7 = *puVar5;
                                    uVar2 = (ulonglong)bVar24;
                                    uVar7 = (*(short *)(local_138 +
                                                       (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13)
                                                       ) * 0x40 +
                                            *(short *)(local_138 +
                                                      (((ulonglong)uVar7 & 0x7e0) * uVar2 >> 0xd)))
                                            * 0x20 + *(short *)(local_138 +
                                                               ((uVar7 & 0x1f) * uVar2 >> 8));
                                  }
                                  uVar18 = ((ushort)*puVar23 | 0x8210820) - (uVar7 & 0xf7def7df);
                                  uVar9 = uVar18 & 0x8210820;
                                  *(ushort *)puVar23 =
                                       (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                      else {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                uVar7 = *(ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                         ((ushort)((*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40 +
                                                   *(short *)(local_138 + (uVar7 >> 5 & 0x3f))) *
                                                   0x20 + *(short *)(local_138 + (uVar7 & 0x1f))) &
                                         0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                uVar7 = *(ushort *)
                                         ((longlong)
                                          (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ) * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                if (uVar7 != local_198) {
                                  uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                           ((ushort)((*(short *)(local_138 + (uVar7 >> 0xb)) * 0x40
                                                     + *(short *)(local_138 + (uVar7 >> 5 & 0x3f)))
                                                     * 0x20 + *(short *)(local_138 + (uVar7 & 0x1f))
                                                    ) & 0xf7def7df);
                                  uVar9 = uVar18 & 0x8210820;
                                  *(ushort *)puVar23 =
                                       (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = (uint *)((longlong)puVar23 + 2);
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                    }
                    else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = *puVar5;
                              uVar2 = (ulonglong)(byte)puVar5[1];
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (uint)local_178[((ulonglong)uVar7 &
                                                                            0xf800) * uVar2 >> 0x13]
                                                            ) * 0x40 +
                                                 *(short *)(local_138 +
                                                           (uint)local_188[((ulonglong)uVar7 & 0x7e0
                                                                           ) * uVar2 >> 0xd])) *
                                                 0x20 + *(short *)(local_138 +
                                                                  (uint)local_180[(uVar7 & 0x1f) *
                                                                                  uVar2 >> 8])) &
                                       0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  uVar7 = *puVar5;
                                  uVar7 = (*(short *)(local_138 + (uint)local_188[uVar7 >> 5 & 0x3f]
                                                     ) +
                                          *(short *)(local_138 + (uint)local_178[uVar7 >> 0xb]) *
                                          0x40) * 0x20 +
                                          *(short *)(local_138 + (uint)local_180[uVar7 & 0x1f]);
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar2 = (ulonglong)bVar24;
                                  uVar7 = (*(short *)(local_138 +
                                                     (uint)local_178[((ulonglong)uVar7 & 0xf800) *
                                                                     uVar2 >> 0x13]) * 0x40 +
                                          *(short *)(local_138 +
                                                    (uint)local_188[((ulonglong)uVar7 & 0x7e0) *
                                                                    uVar2 >> 0xd])) * 0x20 +
                                          *(short *)(local_138 +
                                                    (uint)local_180[(uVar7 & 0x1f) * uVar2 >> 8]);
                                }
                                uVar18 = ((ushort)*puVar23 | 0x8210820) - (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                                 *(short *)(local_138 +
                                                           (uint)local_178[uVar7 >> 0xb]) * 0x40) *
                                                 0x20 + *(short *)(local_138 +
                                                                  (uint)local_180[uVar7 & 0x1f])) &
                                       0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                         ((ushort)((*(short *)(local_138 +
                                                              (uint)local_188[uVar7 >> 5 & 0x3f]) +
                                                   *(short *)(local_138 +
                                                             (uint)local_178[uVar7 >> 0xb]) * 0x40)
                                                   * 0x20 + *(short *)(local_138 +
                                                                      (uint)local_180[uVar7 & 0x1f])
                                                  ) & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = *puVar5;
                              uVar36 = (ulonglong)
                                       (byte)(&DAT_140c28970)
                                             [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                       (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar2 = (ulonglong)(byte)puVar5[1];
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (((ulonglong)uVar7 & 0xf800) * uVar36 *
                                                             uVar2 >> 0x1b)) * 0x40 +
                                                 *(short *)(local_138 +
                                                           (((ulonglong)uVar7 & 0x7e0) * uVar36 *
                                                            uVar2 >> 0x15))) * 0x20 +
                                                *(short *)(local_138 +
                                                          ((uVar7 & 0x1f) * uVar36 * uVar2 >> 0x10))
                                                ) & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if ((char)puVar5[1] != '\0') {
                                uVar2 = (ulonglong)
                                        (byte)(&DAT_140c28970)
                                              [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                if ((char)puVar5[1] == -1) {
                                  uVar7 = *puVar5;
                                  uVar7 = (*(short *)(local_138 +
                                                     (((ulonglong)uVar7 & 0xf800) * uVar2 >> 0x13))
                                           * 0x40 + *(short *)(local_138 +
                                                              (((ulonglong)uVar7 & 0x7e0) * uVar2 >>
                                                              0xd))) * 0x20 +
                                          *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8));
                                }
                                else {
                                  uVar7 = *puVar5;
                                  uVar36 = (ulonglong)(byte)puVar5[1];
                                  uVar7 = (*(short *)(local_138 +
                                                     (((ulonglong)uVar7 & 0xf800) * uVar2 * uVar36
                                                     >> 0x1b)) * 0x40 +
                                          *(short *)(local_138 +
                                                    (((ulonglong)uVar7 & 0x7e0) * uVar2 * uVar36 >>
                                                    0x15))) * 0x20 +
                                          *(short *)(local_138 +
                                                    ((uVar7 & 0x1f) * uVar2 * uVar36 >> 0x10));
                                }
                                uVar18 = ((ushort)*puVar23 | 0x8210820) - (uVar7 & 0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      local_1b8 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              uVar2 = (ulonglong)
                                      (byte)(&DAT_140c28970)
                                            [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                      (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar7 = *(ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (((ulonglong)uVar7 & 0xf800) * uVar2 >>
                                                            0x13)) * 0x40 +
                                                 *(short *)(local_138 +
                                                           (((ulonglong)uVar7 & 0x7e0) * uVar2 >>
                                                           0xd))) * 0x20 +
                                                *(short *)(local_138 + ((uVar7 & 0x1f) * uVar2 >> 8)
                                                          )) & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                       (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              iVar30 = local_170;
                              if (uVar7 != local_198) {
                                uVar2 = (ulonglong)
                                        (byte)(&DAT_140c28970)
                                              [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                        (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                         ((ushort)((*(short *)(local_138 +
                                                              (((ulonglong)uVar7 & 0xf800) * uVar2
                                                              >> 0x13)) * 0x40 +
                                                   *(short *)(local_138 +
                                                             (((ulonglong)uVar7 & 0x7e0) * uVar2 >>
                                                             0xd))) * 0x20 +
                                                  *(short *)(local_138 +
                                                            ((uVar7 & 0x1f) * uVar2 >> 8))) &
                                         0xf7def7df);
                                uVar9 = uVar18 & 0x8210820;
                                *(ushort *)puVar23 =
                                     (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            local_1b8 = local_1b8 + -1;
                          } while (local_1b8 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          local_1b8 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar7 = *puVar5;
                            bVar24 = (byte)puVar5[1];
                            bVar1 = (&DAT_140c28970)
                                    [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 +
                                                          (local_188[uVar7 >> 5 & 0x3f] *
                                                           (uint)bVar24 * (uint)bVar1 >> 0x10)) +
                                               *(short *)(local_138 +
                                                         (local_178[uVar7 >> 0xb] * (uint)bVar24 *
                                                          (uint)bVar1 >> 0x10)) * 0x40) * 0x20 +
                                              *(short *)(local_138 +
                                                        (local_180[uVar7 & 0x1f] * (uint)bVar24 *
                                                         (uint)bVar1 >> 0x10))) & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                bVar24 = (&DAT_140c28970)[*pbVar3];
                                uVar7 = (*(short *)(local_138 +
                                                   (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 >> 8
                                                   )) +
                                        *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 >> 8)) *
                                        0x40) * 0x20 +
                                        *(short *)(local_138 +
                                                  (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8));
                              }
                              else {
                                uVar7 = *puVar5;
                                bVar1 = (&DAT_140c28970)[*pbVar3];
                                uVar7 = (*(short *)(local_138 +
                                                   (local_188[uVar7 >> 5 & 0x3f] * (uint)bVar24 *
                                                    (uint)bVar1 >> 0x10)) +
                                        *(short *)(local_138 +
                                                  (local_178[uVar7 >> 0xb] * (uint)bVar24 *
                                                   (uint)bVar1 >> 0x10)) * 0x40) * 0x20 +
                                        *(short *)(local_138 +
                                                  (local_180[uVar7 & 0x1f] * (uint)bVar24 *
                                                   (uint)bVar1 >> 0x10));
                              }
                              uVar18 = ((ushort)*puVar23 | 0x8210820) - (uVar7 & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                     ((ushort)((*(short *)(local_138 +
                                                          (local_188[uVar7 >> 5 & 0x3f] *
                                                           (uint)bVar24 >> 8)) +
                                               *(short *)(local_138 +
                                                         (local_178[uVar7 >> 0xb] * (uint)bVar24 >>
                                                         8)) * 0x40) * 0x20 +
                                              *(short *)(local_138 +
                                                        (local_180[uVar7 & 0x1f] * (uint)bVar24 >> 8
                                                        ))) & 0xf7def7df);
                            uVar9 = uVar18 & 0x8210820;
                            *(ushort *)puVar23 = (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18
                            ;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              uVar18 = ((ushort)*puVar23 | 0x8210820) -
                                       ((ushort)((*(short *)(local_138 +
                                                            (local_188[uVar7 >> 5 & 0x3f] *
                                                             (uint)bVar24 >> 8)) +
                                                 *(short *)(local_138 +
                                                           (local_178[uVar7 >> 0xb] * (uint)bVar24
                                                           >> 8)) * 0x40) * 0x20 +
                                                *(short *)(local_138 +
                                                          (local_180[uVar7 & 0x1f] * (uint)bVar24 >>
                                                          8))) & 0xf7def7df);
                              uVar9 = uVar18 & 0x8210820;
                              *(ushort *)puVar23 =
                                   (short)uVar9 - (short)(uVar9 >> 5) & (ushort)uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 4:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = (ushort)*puVar23;
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              uVar6 = *puVar5;
                              *(ushort *)puVar23 =
                                   (ushort)((uVar7 >> 5 & 0x3f) * (uVar6 >> 5 & 0x3f) * (uint)bVar24
                                           >> 9) & 0x7e0 |
                                   (ushort)((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) *
                                            (uint)bVar24 >> 2) & 0xf800 |
                                   (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) * (uint)bVar24 >> 0xd);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (ushort)((uVar6 & 0xf800) * (uVar7 & 0xf800) >> 0x10) & 0xf800
                                     | (ushort)((uVar6 & 0x7e0) * (uVar7 & 0x7e0) >> 0xb) & 0x7e0 |
                                     (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) >> 5);
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (ushort)((uVar6 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) *
                                              (uint)bVar24 >> 9) & 0x7e0 |
                                     (ushort)((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                              (uint)bVar24 >> 2) & 0xf800 |
                                     (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) * (uint)bVar24 >> 0xd)
                                ;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = (ushort)*puVar23;
                              uVar6 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(ushort *)puVar23 =
                                   (ushort)((uVar7 & 0xf800) * (uVar6 & 0xf800) >> 0x10) & 0xf800 |
                                   (ushort)((uVar7 & 0x7e0) * (uVar6 & 0x7e0) >> 0xb) & 0x7e0 |
                                   (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) >> 5);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (ushort)((uVar6 & 0xf800) * (uVar7 & 0xf800) >> 0x10) & 0xf800
                                     | (ushort)((uVar6 & 0x7e0) * (uVar7 & 0x7e0) >> 0xb) & 0x7e0 |
                                     (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) >> 5);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar6 = *puVar5;
                            bVar24 = (byte)puVar5[1];
                            *(ushort *)puVar23 =
                                 (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) *
                                          (uint)bVar24 >> 9) & 0x7e0 |
                                 (ushort)(local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) *
                                          (uint)bVar24 >> 2) & 0xf800 |
                                 (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) * (uint)bVar24 >>
                                         0xd);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 == 0xff) {
                              uVar7 = *puVar5;
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) >> 1)
                                   & 0x7e0 | *(short *)(local_178 + (uVar7 >> 0xb)) *
                                             (uVar6 >> 5 & 0x7c0) & 0xf800 |
                                   (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5);
                            }
                            else {
                              uVar7 = *puVar5;
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) *
                                            (uint)bVar24 >> 9) & 0x7e0 |
                                   (ushort)(local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) *
                                            (uint)bVar24 >> 2) & 0xf800 |
                                   (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) * (uint)bVar24
                                           >> 0xd);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(ushort *)puVar23 =
                                 (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) >> 1) &
                                 0x7e0 | *(short *)(local_178 + (uVar6 >> 0xb)) *
                                         (uVar7 >> 5 & 0x7c0) & 0xf800 |
                                 (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              *(ushort *)puVar23 =
                                   (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) >> 1)
                                   & 0x7e0 | *(short *)(local_178 + (uVar7 >> 0xb)) *
                                             (uVar6 >> 5 & 0x7c0) & 0xf800 |
                                   (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            bVar1 = (byte)puVar5[1];
                            uVar6 = *puVar5;
                            *(ushort *)puVar23 =
                                 (ushort)((uVar7 >> 5 & 0x3f) * (uVar6 >> 5 & 0x3f) * (uint)bVar1 *
                                          (uint)bVar24 >> 0x11) & 0x7e0 |
                                 (ushort)((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) * (uint)bVar1
                                          * (uint)bVar24 >> 10) & 0xf800 |
                                 (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) * (uint)bVar1 *
                                          (uint)bVar24 >> 0x15);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            bVar1 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 == 0xff) {
                              bVar24 = (&DAT_140c28970)[bVar1];
                              uVar7 = *puVar5;
                              uVar6 = (ushort)*puVar23;
                              uVar7 = (ushort)((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                               (uint)bVar24 >> 2) & 0xf800 |
                                      (ushort)((uVar6 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) *
                                               (uint)bVar24 >> 9) & 0x7e0 |
                                      (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) * (uint)bVar24 >> 0xd
                                              );
                            }
                            else {
                              uVar7 = *puVar5;
                              uVar6 = (ushort)*puVar23;
                              bVar1 = (&DAT_140c28970)[bVar1];
                              uVar7 = (ushort)((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                               (uint)bVar24 * (uint)bVar1 >> 10) & 0xf800 |
                                      (ushort)((uVar6 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) *
                                               (uint)bVar24 * (uint)bVar1 >> 0x11) & 0x7e0 |
                                      (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) * (uint)bVar24 *
                                               (uint)bVar1 >> 0x15);
                            }
                            *(ushort *)puVar23 = uVar7;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((uVar7 >> 5 & 0x3f) * (uVar6 >> 5 & 0x3f) * (uint)bVar24
                                         >> 9) & 0x7e0 |
                                 (ushort)((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) * (uint)bVar24
                                         >> 2) & 0xf800 |
                                 (ushort)((uVar7 & 0x1f) * (uVar6 & 0x1f) * (uint)bVar24 >> 0xd);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              *(ushort *)puVar23 =
                                   (ushort)((uVar6 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) * (uint)bVar24
                                           >> 9) & 0x7e0 |
                                   (ushort)((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                            (uint)bVar24 >> 2) & 0xf800 |
                                   (ushort)((uVar6 & 0x1f) * (uVar7 & 0x1f) * (uint)bVar24 >> 0xd);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar6 = *puVar5;
                          bVar24 = (byte)puVar5[1];
                          bVar1 = (&DAT_140c28970)
                                  [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) *
                                        (uint)bVar24 * (uint)bVar1 >> 0x11) & 0x7e0 |
                               (ushort)(local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) *
                                        (uint)bVar24 * (uint)bVar1 >> 10) & 0xf800 |
                               (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) * (uint)bVar24 *
                                        (uint)bVar1 >> 0x15);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)puVar5[1];
                          if (bVar24 == 0xff) {
                            uVar7 = *puVar5;
                            bVar24 = (&DAT_140c28970)[*pbVar3];
                            uVar6 = (ushort)*puVar23;
                            uVar25 = (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) *
                                              (uint)bVar24 >> 9);
                            uVar15 = (ushort)(local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) *
                                              (uint)bVar24 >> 2);
                            uVar7 = (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) * (uint)bVar24
                                            >> 0xd);
                          }
                          else {
                            uVar7 = *puVar5;
                            bVar1 = (&DAT_140c28970)[*pbVar3];
                            uVar6 = (ushort)*puVar23;
                            uVar25 = (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) *
                                              (uint)bVar24 * (uint)bVar1 >> 0x11);
                            uVar15 = (ushort)(local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) *
                                              (uint)bVar24 * (uint)bVar1 >> 10);
                            uVar7 = (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) * (uint)bVar24
                                             * (uint)bVar1 >> 0x15);
                          }
                          *(ushort *)puVar23 = uVar25 & 0x7e0 | uVar15 & 0xf800 | uVar7;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar6 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(local_188[uVar6 >> 5 & 0x3f] * (uVar7 >> 5 & 0x3f) *
                                        (uint)bVar24 >> 9) & 0x7e0 |
                               (ushort)(local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) *
                                        (uint)bVar24 >> 2) & 0xf800 |
                               (ushort)(local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) * (uint)bVar24 >>
                                       0xd);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (uVar7 != local_198) {
                            uVar6 = (ushort)*puVar23;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(local_188[uVar7 >> 5 & 0x3f] * (uVar6 >> 5 & 0x3f) *
                                          (uint)bVar24 >> 9) & 0x7e0 |
                                 (ushort)(local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) *
                                          (uint)bVar24 >> 2) & 0xf800 |
                                 (ushort)(local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) * (uint)bVar24 >>
                                         0xd);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 10:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = (ushort)*puVar23;
                              uVar9 = uVar7 & 0x1f;
                              bVar24 = (byte)puVar5[1];
                              uVar6 = ~*puVar5;
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) * (uint)bVar24 *
                                            DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x10000 >> 0x10)
                                   & 0xf800 |
                                   (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 *
                                            DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x10000 >> 0x10)
                                   & 0x7e0 | (ushort)(((uVar6 & 0x1f) - uVar9) * (uint)bVar24 *
                                                      DAT_140c28a88 + uVar9 * 0x10000 >> 0x10);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 != 0) {
                                uVar7 = ~*puVar5;
                                if (bVar24 == 0xff) {
                                  uVar6 = (ushort)*puVar23;
                                  *(ushort *)puVar23 =
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)((uVar7 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) *
                                                  4) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                       (*(short *)(local_160 +
                                                  (longlong)
                                                  (int)((uint)(uVar7 >> 0xb) - (uint)(uVar6 >> 0xb))
                                                  * 4) + (uVar6 >> 0xb)) * 0x800 |
                                       *(short *)(local_160 +
                                                 (longlong)(int)((uVar7 & 0x1f) - (uVar6 & 0x1f)) *
                                                 4) + (uVar6 & 0x1f);
                                }
                                else {
                                  uVar9 = (uint)(ushort)*puVar23;
                                  *(ushort *)puVar23 =
                                       (ushort)(((uVar7 & 0xf800) - (uVar9 & 0xf800)) * (uint)bVar24
                                                * DAT_140c28a88 +
                                                ((ushort)*puVar23 & 0xfffff800) * 0x10000 >> 0x10) &
                                       0xf800 | (ushort)(((uVar7 & 0x7e0) - (uVar9 & 0x7e0)) *
                                                         (uint)bVar24 * DAT_140c28a88 +
                                                         (uVar9 & 0xffffffe0) * 0x10000 >> 0x10) &
                                                0x7e0 |
                                       (ushort)(((uVar7 & 0x1f) - (uVar9 & 0x1f)) * (uint)bVar24 *
                                                DAT_140c28a88 + (uVar9 & 0x1f) * 0x10000 >> 0x10);
                                }
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = (ushort)*puVar23;
                              uVar6 = ~*(ushort *)
                                        ((longlong)
                                         (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                         * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4)
                                   + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4
                                              ) + (uVar7 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)(int)((uVar6 & 0x1f) - (uVar7 & 0x1f)) * 4) +
                                   (uVar7 & 0x1f);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar6 = (ushort)*puVar23;
                                uVar7 = ~uVar7;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uVar7 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4
                                                ) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)((uint)(uVar7 >> 0xb) - (uint)(uVar6 >> 0xb)) *
                                                4) + (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)(int)((uVar7 & 0x1f) - (uVar6 & 0x1f)) * 4)
                                     + (uVar6 & 0x1f);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = (uint)uVar7;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            uVar6 = ~*puVar5;
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar18 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_180[uVar6 & 0x1f] - (uVar18 & 0x1f)) * (uint)bVar24
                                          * DAT_140c28a88 + uVar18 * 0x10000 >> 0x10) & 0x1f;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              uVar7 = ~*puVar5;
                              if (bVar24 == 0xff) {
                                uVar6 = (ushort)*puVar23;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(local_188[uVar7 >> 5 & 0x3f] -
                                                     (uVar6 >> 5 & 0x3f)) * 4) + (uVar6 >> 5 & 0x3f)
                                     ) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)
                                                     ) * 4) + (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)
                                               (int)(local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) * 4)
                                     + (uVar6 & 0x1f);
                              }
                              else {
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6;
                                *(ushort *)puVar23 =
                                     (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                     (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                              (uint)bVar24 * DAT_140c28a88 +
                                              (uVar9 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                     (ushort)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                              (uint)bVar24 * DAT_140c28a88 + uVar9 * 0x10000 >> 0x10
                                             ) & 0x1f;
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*(ushort *)
                                      ((longlong)
                                       (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                       2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)
                                                 ) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)(local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                            4) + (uVar7 >> 0xb)) * 0x800 |
                                 *(short *)(local_160 +
                                           (longlong)(int)(local_180[uVar6 & 0x1f] - (uVar7 & 0x1f))
                                           * 4) + (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar7 = ~uVar7;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(local_188[uVar7 >> 5 & 0x3f] -
                                                   (uVar6 >> 5 & 0x3f)) * 4) + (uVar6 >> 5 & 0x3f))
                                   * 0x20 | (*(short *)(local_160 +
                                                       (longlong)
                                                       (int)(local_178[uVar7 >> 0xb] -
                                                            (uint)(uVar6 >> 0xb)) * 4) +
                                            (uVar6 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)(local_180[uVar7 & 0x1f] - (uVar6 & 0x1f)) * 4) +
                                   (uVar6 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*puVar5;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            bVar1 = (byte)puVar5[1];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * (uint)bVar1
                                          * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                 (ushort)(((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) *
                                          (uint)bVar1 * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                                 (ushort)(byte)(((uVar6 & 0x1f) - (uVar7 & 0x1f)) * (uint)bVar1 *
                                                (uint)bVar24 * DAT_140c28a88 +
                                                (uVar7 & 0x1f) * 0x1000000 >> 0x18);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 != 0) {
                              uVar7 = (ushort)*puVar23;
                              uVar26 = (uint)uVar7;
                              uVar6 = ~*puVar5;
                              bVar1 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                              if (bVar24 == 0xff) {
                                bVar24 = (&DAT_140c28970)[bVar1];
                                uVar9 = (uint)uVar7;
                                *(ushort *)puVar23 =
                                     (ushort)(((uVar6 & 0x7e0) - (uVar26 & 0x7e0)) * (uint)bVar24 *
                                              DAT_140c28a88 + (uVar9 & 0xffffffe0) * 0x10000 >> 0x10
                                             ) & 0x7e0 |
                                     (ushort)(((uVar6 & 0xf800) - (uVar9 & 0xf800)) * (uint)bVar24 *
                                              DAT_140c28a88 + (uVar9 & 0xfffff800) * 0x10000 >> 0x10
                                             ) & 0xf800 |
                                     (ushort)(((uVar6 & 0x1f) - (uVar26 & 0x1f)) * (uint)bVar24 *
                                              DAT_140c28a88 + (uVar26 & 0x1f) * 0x10000 >> 0x10);
                              }
                              else {
                                bVar1 = (&DAT_140c28970)[bVar1];
                                *(ushort *)puVar23 =
                                     (ushort)(((uVar6 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) *
                                              (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                              (uVar26 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                     (ushort)(((uint)(uVar6 >> 0xb) - (uint)(uVar7 >> 0xb)) *
                                              (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                              (uVar26 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                                     (ushort)(byte)(((uVar6 & 0x1f) - (uVar26 & 0x1f)) *
                                                    (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                                    (uVar26 & 0x1f) * 0x1000000 >> 0x18);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar6 = ~*(ushort *)
                                      ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                      (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar26 = uVar7 & 0x1f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((uVar6 & 0x7e0) - (uVar7 & 0x7e0)) * (uint)bVar24 *
                                          DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x10000 >> 0x10) &
                                 0x7e0 | (ushort)(((uVar6 & 0xf800) - (uVar7 & 0xf800)) *
                                                  (uint)bVar24 * DAT_140c28a88 +
                                                  (uVar7 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                                 (ushort)(((uVar6 & 0x1f) - uVar26) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar26 * 0x10000 >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar7 = ~uVar7;
                              uVar26 = uVar6 & 0x1f;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              *(ushort *)puVar23 =
                                   (ushort)(((uVar7 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar24 *
                                            DAT_140c28a88 + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10)
                                   & 0x7e0 | (ushort)(((uVar7 & 0xf800) - (uVar6 & 0xf800)) *
                                                      (uint)bVar24 * DAT_140c28a88 +
                                                      (uVar6 & 0xfffff800) * 0x10000 >> 0x10) &
                                             0xf800 |
                                   (ushort)(((uVar7 & 0x1f) - uVar26) * (uint)bVar24 * DAT_140c28a88
                                            + uVar26 * 0x10000 >> 0x10);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          bVar24 = (byte)puVar5[1];
                          uVar6 = ~*puVar5;
                          bVar1 = (&DAT_140c28970)
                                  [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                        (uVar7 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                        (uVar26 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                               (byte)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24 *
                                      (uint)bVar1 * DAT_140c28a88 + uVar26 * 0x1000000 >> 0x18) &
                               0x1f;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)puVar5[1];
                          if (bVar24 != 0) {
                            uVar7 = ~*puVar5;
                            bVar1 = *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 == 0xff) {
                              bVar24 = (&DAT_140c28970)[bVar1];
                              uVar6 = (ushort)*puVar23;
                              uVar9 = (uint)uVar6;
                              *(ushort *)puVar23 =
                                   (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                   (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar9 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                   (ushort)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) *
                                            (uint)bVar24 * DAT_140c28a88 + uVar9 * 0x10000 >> 0x10)
                                   & 0x1f;
                            }
                            else {
                              uVar6 = (ushort)*puVar23;
                              uVar9 = (uint)uVar6;
                              bVar1 = (&DAT_140c28970)[bVar1];
                              *(ushort *)puVar23 =
                                   (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                            (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                            (uVar6 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                   (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                            (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                            (uVar9 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                                   (byte)((local_180[uVar7 & 0x1f] - (uVar9 & 0x1f)) * (uint)bVar24
                                          * (uint)bVar1 * DAT_140c28a88 + uVar9 * 0x1000000 >> 0x18)
                                   & 0x1f;
                            }
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = (uint)uVar7;
                          uVar6 = ~*(ushort *)
                                    ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                    (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)((local_188[uVar6 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)((local_178[uVar6 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar26 & 0xfffff800) * 0x20
                                       >> 5) & 0xf800 |
                               (ushort)((local_180[uVar6 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24 *
                                        DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (uVar7 != local_198) {
                            uVar7 = ~uVar7;
                            uVar6 = (ushort)*puVar23;
                            uVar26 = (uint)uVar6;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((local_188[uVar7 >> 5 & 0x3f] - (uVar6 >> 5 & 0x3f)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar6 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)((local_178[uVar7 >> 0xb] - (uint)(uVar6 >> 0xb)) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar26 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_180[uVar7 & 0x1f] - (uVar26 & 0x1f)) * (uint)bVar24
                                          * DAT_140c28a88 + uVar26 * 0x10000 >> 0x10) & 0x1f;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 0xb:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar7 = (ushort)*puVar23;
                              uVar9 = (uint)uVar7;
                              bVar24 = (byte)puVar5[1];
                              uVar6 = *puVar5;
                              uVar18 = uVar9 & 0x1f;
                              *(ushort *)puVar23 =
                                   (ushort)((((uVar7 & 0xf800) * (uVar6 & 0xf800) >> 0x1b) -
                                            (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                            (uVar9 & 0x7fff800) * 0x20 >> 5) & 0xf800 |
                                   (ushort)((((uVar6 & 0x7e0) * (uVar9 & 0x7e0) >> 0xb) -
                                            (uVar9 & 0x7e0)) * (uint)bVar24 * DAT_140c28a88 +
                                            (uVar9 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                                   (ushort)((((uVar6 & 0x1f) * uVar18 >> 5) - uVar18) * (uint)bVar24
                                            * DAT_140c28a88 + uVar18 * 0x10000 >> 0x10);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar5 = (ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (byte)puVar5[1];
                              if (bVar24 == 0xff) {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = uVar6 >> 5 & 0x3f;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(((uVar7 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) *
                                                4) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb)
                                                      >> 5) - (uint)(uVar6 >> 0xb)) * 4) +
                                     (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)
                                               (int)(((uVar7 & 0x1f) * (uVar6 & 0x1f) >> 5) -
                                                    (uVar6 & 0x1f)) * 4) + (uVar6 & 0x1f);
                              }
                              else {
                                uVar7 = *puVar5;
                                uVar6 = (ushort)*puVar23;
                                uVar9 = (uint)uVar6;
                                uVar18 = uVar9 & 0x1f;
                                *(ushort *)puVar23 =
                                     (ushort)((((uVar6 & 0xf800) * (uVar7 & 0xf800) >> 0x1b) -
                                              (uint)(uVar6 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                              (uVar9 & 0x7fff800) * 0x20 >> 5) & 0xf800 |
                                     (ushort)((((uVar7 & 0x7e0) * (uVar9 & 0x7e0) >> 0xb) -
                                              (uVar9 & 0x7e0)) * (uint)bVar24 * DAT_140c28a88 +
                                              (uVar9 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                                     (ushort)((((uVar7 & 0x1f) * uVar18 >> 5) - uVar18) *
                                              (uint)bVar24 * DAT_140c28a88 + uVar18 * 0x10000 >>
                                             0x10);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = (ushort)*puVar23;
                              uVar18 = uVar7 >> 5 & 0x3f;
                              uVar6 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(((uVar6 >> 5 & 0x3f) * uVar18 >> 6) - uVar18) *
                                              4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)(((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) >>
                                                    5) - (uint)(uVar7 >> 0xb)) * 4) + (uVar7 >> 0xb)
                                   ) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)(((uVar6 & 0x1f) * (uVar7 & 0x1f) >> 5) -
                                                  (uVar7 & 0x1f)) * 4) + (uVar7 & 0x1f);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar7 = *(ushort *)
                                       ((longlong)
                                        (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12)
                                        * 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar7 != local_198) {
                                uVar6 = (ushort)*puVar23;
                                uVar9 = uVar6 >> 5 & 0x3f;
                                *(ushort *)puVar23 =
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(((uVar7 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) *
                                                4) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                     (*(short *)(local_160 +
                                                (longlong)
                                                (int)(((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb)
                                                      >> 5) - (uint)(uVar6 >> 0xb)) * 4) +
                                     (uVar6 >> 0xb)) * 0x800 |
                                     *(short *)(local_160 +
                                               (longlong)
                                               (int)(((uVar7 & 0x1f) * (uVar6 & 0x1f) >> 5) -
                                                    (uVar6 & 0x1f)) * 4) + (uVar6 & 0x1f);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = (uint *)((longlong)puVar23 + 2);
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar9 = uVar7 >> 5 & 0x3f;
                            bVar24 = (byte)puVar5[1];
                            uVar6 = *puVar5;
                            *(ushort *)puVar23 =
                                 (ushort)(((local_188[uVar6 >> 5 & 0x3f] * uVar9 >> 6) - uVar9) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)(((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                          (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar7 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)(((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                          (uVar7 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                          (uint)uVar7 * 0x10000 >> 0x10) & 0x1f;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = (uint)uVar7;
                            puVar5 = (ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) <<
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)puVar5[1];
                            if (bVar24 == 0xff) {
                              uVar6 = *puVar5;
                              uVar9 = uVar7 >> 5 & 0x3f;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_188[uVar6 >> 5 & 0x3f] * uVar9 >> 6) -
                                                   uVar9) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb)
                                                    >> 5) - (uint)(uVar7 >> 0xb)) * 4) +
                                   (uVar7 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                                  (uVar7 & 0x1f)) * 4) + (uVar7 & 0x1f);
                            }
                            else {
                              uVar6 = *puVar5;
                              uVar9 = uVar7 >> 5 & 0x3f;
                              *(ushort *)puVar23 =
                                   (ushort)(((local_188[uVar6 >> 5 & 0x3f] * uVar9 >> 6) - uVar9) *
                                            (uint)bVar24 * DAT_140c28a88 +
                                            (uVar18 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                   (ushort)(((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                            (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                            (uVar18 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                   (ushort)(((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                            (uVar7 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                            uVar18 * 0x10000 >> 0x10) & 0x1f;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar18 = uVar7 >> 5 & 0x3f;
                            uVar6 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(ushort *)puVar23 =
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((local_188[uVar6 >> 5 & 0x3f] * uVar18 >> 6) -
                                                 uVar18) * 4) + (uVar7 >> 5 & 0x3f)) * 0x20 |
                                 (*(short *)(local_160 +
                                            (longlong)
                                            (int)((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                  5) - (uint)(uVar7 >> 0xb)) * 4) + (uVar7 >> 0xb))
                                 * 0x800 | *(short *)(local_160 +
                                                     (longlong)
                                                     (int)((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f)
                                                           >> 5) - (uVar7 & 0x1f)) * 4) +
                                           (uVar7 & 0x1f);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)
                                      (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                      2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar9 = uVar6 >> 5 & 0x3f;
                              *(ushort *)puVar23 =
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_188[uVar7 >> 5 & 0x3f] * uVar9 >> 6) -
                                                   uVar9) * 4) + (uVar6 >> 5 & 0x3f)) * 0x20 |
                                   (*(short *)(local_160 +
                                              (longlong)
                                              (int)((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb)
                                                    >> 5) - (uint)(uVar6 >> 0xb)) * 4) +
                                   (uVar6 >> 0xb)) * 0x800 |
                                   *(short *)(local_160 +
                                             (longlong)
                                             (int)((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                                  (uVar6 & 0x1f)) * 4) + (uVar6 & 0x1f);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar7 = (ushort)*puVar23;
                            uVar6 = *puVar5;
                            uVar26 = uVar7 >> 5 & 0x3f;
                            bVar24 = (byte)puVar5[1];
                            bVar1 = (&DAT_140c28970)
                                    [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            uVar9 = uVar7 & 0x1f;
                            *(ushort *)puVar23 =
                                 (ushort)((int)((((uVar6 >> 5 & 0x3f) * uVar26 >> 6) - uVar26) *
                                                (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                               (uVar7 & 0x7e0) * 0x80000) >> 0x13) & 0x7e0 |
                                 (ushort)((int)((((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) >> 5)
                                                - (uint)(uVar7 >> 0xb)) * (uint)bVar24 * (uint)bVar1
                                                * DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x2000) >>
                                         0xd) & 0xf800 |
                                 (short)(char)((((uVar6 & 0x1f) * uVar9 >> 5) - uVar9) *
                                               (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                               uVar9 * 0x1000000 >> 0x18);
                            iVar30 = local_170;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar5 = (ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            uVar7 = (ushort)*puVar23;
                            uVar18 = (uint)uVar7;
                            bVar24 = (byte)puVar5[1];
                            uVar9 = uVar7 >> 5 & 0x3f;
                            if (bVar24 == 0xff) {
                              uVar6 = *puVar5;
                              uVar26 = uVar18 & 0x1f;
                              bVar24 = (&DAT_140c28970)[*pbVar3];
                              uVar7 = (ushort)((int)((((uVar6 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) *
                                                     (uint)bVar24 * DAT_140c28a88 +
                                                    (uVar18 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                                      (ushort)((int)((((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb)
                                                      >> 5) - (uint)(uVar7 >> 0xb)) * (uint)bVar24 *
                                                     DAT_140c28a88 + (uVar18 & 0xfffff800) * 0x20)
                                              >> 5) & 0xf800 |
                                      (ushort)((((uVar6 & 0x1f) * uVar26 >> 5) - uVar26) *
                                               (uint)bVar24 * DAT_140c28a88 + uVar26 * 0x10000 >>
                                              0x10);
                            }
                            else {
                              uVar6 = *puVar5;
                              bVar1 = (&DAT_140c28970)[*pbVar3];
                              uVar26 = uVar18 & 0x1f;
                              uVar7 = (ushort)((int)((((uVar6 >> 5 & 0x3f) * uVar9 >> 6) - uVar9) *
                                                     (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                                    (uVar18 & 0x7e0) * 0x80000) >> 0x13) & 0x7e0 |
                                      (ushort)((int)((((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb)
                                                      >> 5) - (uint)(uVar7 >> 0xb)) * (uint)bVar24 *
                                                     (uint)bVar1 * DAT_140c28a88 +
                                                    (uVar18 & 0xfffff800) * 0x2000) >> 0xd) & 0xf800
                                      | (short)(char)((((uVar6 & 0x1f) * uVar26 >> 5) - uVar26) *
                                                      (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                                      uVar26 * 0x1000000 >> 0x18);
                              iVar30 = local_170;
                            }
                            *(ushort *)puVar23 = uVar7;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_170 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = (ushort)*puVar23;
                            uVar32 = uVar7 & 0x1f;
                            uVar6 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            uVar26 = uVar7 >> 5 & 0x3f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)((int)((((uVar6 >> 5 & 0x3f) * uVar26 >> 6) - uVar26) *
                                                (uint)bVar24 * DAT_140c28a88 +
                                               (uVar7 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                                 (ushort)((int)((((uint)(uVar6 >> 0xb) * (uint)(uVar7 >> 0xb) >> 5)
                                                - (uint)(uVar7 >> 0xb)) * (uint)bVar24 *
                                                DAT_140c28a88 + (uVar7 & 0xfffff800) * 0x20) >> 5) &
                                 0xf800 | (ushort)((((uVar6 & 0x1f) * uVar32 >> 5) - uVar32) *
                                                   (uint)bVar24 * DAT_140c28a88 + uVar32 * 0x10000
                                                  >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar7 = *(ushort *)
                                     ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                     (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (uVar7 != local_198) {
                              uVar6 = (ushort)*puVar23;
                              uVar26 = uVar6 >> 5 & 0x3f;
                              uVar32 = uVar6 & 0x1f;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              *(ushort *)puVar23 =
                                   (ushort)((int)((((uVar7 >> 5 & 0x3f) * uVar26 >> 6) - uVar26) *
                                                  (uint)bVar24 * DAT_140c28a88 +
                                                 (uVar6 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                                   (ushort)((int)((((uint)(uVar7 >> 0xb) * (uint)(uVar6 >> 0xb) >> 5
                                                   ) - (uint)(uVar6 >> 0xb)) * (uint)bVar24 *
                                                  DAT_140c28a88 + (uVar6 & 0xfffff800) * 0x20) >> 5)
                                   & 0xf800 |
                                   (ushort)((((uVar7 & 0x1f) * uVar32 >> 5) - uVar32) * (uint)bVar24
                                            * DAT_140c28a88 + uVar32 * 0x10000 >> 0x10);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = (uint *)((longlong)puVar23 + 2);
                          local_170 = local_170 + -1;
                        } while (local_170 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_170 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar32 = (uint)uVar7;
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          uVar26 = uVar7 >> 5 & 0x3f;
                          bVar24 = (byte)puVar5[1];
                          uVar6 = *puVar5;
                          bVar1 = (&DAT_140c28970)
                                  [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(((local_188[uVar6 >> 5 & 0x3f] * uVar26 >> 6) - uVar26) *
                                        (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                        (uVar32 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                               (ushort)(((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * (uint)bVar24 * (uint)bVar1 *
                                        DAT_140c28a88 + (uVar32 & 0xfffff800) * 0x2000 >> 0xd) &
                               0xf800 | (byte)(((local_180[uVar6 & 0x1f] * (uVar32 & 0x1f) >> 5) -
                                               (uVar32 & 0x1f)) * (uint)bVar24 * (uint)bVar1 *
                                               DAT_140c28a88 + uVar32 * 0x1000000 >> 0x18) & 0x1f;
                          iVar30 = local_170;
                          iVar34 = local_1b8;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar5 = (ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 4) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)puVar5[1];
                          if (bVar24 == 0xff) {
                            uVar7 = *puVar5;
                            uVar6 = (ushort)*puVar23;
                            uVar18 = (uint)uVar6;
                            uVar9 = uVar6 >> 5 & 0x3f;
                            bVar24 = (&DAT_140c28970)[*pbVar3];
                            *(ushort *)puVar23 =
                                 (ushort)(((local_188[uVar7 >> 5 & 0x3f] * uVar9 >> 6) - uVar9) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar18 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)(((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) >> 5) -
                                          (uint)(uVar6 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar18 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)(((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                          (uVar6 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar18 * 0x10000 >> 0x10) & 0x1f;
                          }
                          else {
                            uVar7 = *puVar5;
                            uVar6 = (ushort)*puVar23;
                            uVar18 = (uint)uVar6;
                            uVar9 = uVar6 >> 5 & 0x3f;
                            bVar1 = (&DAT_140c28970)[*pbVar3];
                            *(ushort *)puVar23 =
                                 (ushort)(((local_188[uVar7 >> 5 & 0x3f] * uVar9 >> 6) - uVar9) *
                                          (uint)bVar24 * (uint)bVar1 * DAT_140c28a88 +
                                          (uVar18 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                 (ushort)(((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) >> 5) -
                                          (uint)(uVar6 >> 0xb)) * (uint)bVar24 * (uint)bVar1 *
                                          DAT_140c28a88 + (uVar18 & 0xfffff800) * 0x2000 >> 0xd) &
                                 0xf800 | (byte)(((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                                 (uVar6 & 0x1f)) * (uint)bVar24 * (uint)bVar1 *
                                                 DAT_140c28a88 + uVar18 * 0x1000000 >> 0x18) & 0x1f;
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = (ushort)*puVar23;
                          uVar26 = uVar7 >> 5 & 0x3f;
                          uVar6 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                          *(ushort *)puVar23 =
                               (ushort)(((local_188[uVar6 >> 5 & 0x3f] * uVar26 >> 6) - uVar26) *
                                        (uint)bVar24 * DAT_140c28a88 + (uVar7 & 0xffffffe0) * 0x800
                                       >> 0xb) & 0x7e0 |
                               (ushort)(((local_178[uVar6 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                        (uVar7 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)(((local_180[uVar6 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                        (uVar7 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                        (uint)uVar7 * 0x10000 >> 0x10) & 0x1f;
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          uVar7 = *(ushort *)
                                   ((longlong)(((int)uVar18 >> 0x12) * 2) +
                                   (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          if (uVar7 != local_198) {
                            uVar6 = (ushort)*puVar23;
                            uVar32 = (uint)uVar6;
                            uVar26 = uVar6 >> 5 & 0x3f;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            *(ushort *)puVar23 =
                                 (ushort)(((local_188[uVar7 >> 5 & 0x3f] * uVar26 >> 6) - uVar26) *
                                          (uint)bVar24 * DAT_140c28a88 +
                                          (uVar32 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                                 (ushort)(((local_178[uVar7 >> 0xb] * (uint)(uVar6 >> 0xb) >> 5) -
                                          (uint)(uVar6 >> 0xb)) * (uint)bVar24 * DAT_140c28a88 +
                                          (uVar32 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)(((local_180[uVar7 & 0x1f] * (uVar6 & 0x1f) >> 5) -
                                          (uVar6 & 0x1f)) * (uint)bVar24 * DAT_140c28a88 +
                                          uVar32 * 0x10000 >> 0x10) & 0x1f;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = (uint *)((longlong)puVar23 + 2);
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
              }
            }
          }
          else {
            if (*(int *)(lVar19 + 0x28) != 1) {
              return;
            }
            if (*(int *)(lVar19 + 0x2c) == 1) {
              switch(DAT_140c28a84) {
              case 1:
                if (iVar41 != 0xff) {
                  if (iVar41 == 0) {
                    return;
                  }
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                                0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*pbVar3 != local_198) {
                                *(byte *)puVar23 =
                                     (byte)((local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] -
                                            (uint)(byte)*puVar23) * (int)uVar36 +
                                            (uint)(byte)*puVar23 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4
                                                                )] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4
                                                                )] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] -
                                        (uint)(byte)*puVar23) * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) -
                                          (uint)(byte)*puVar23) * (int)uVar36 +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)
                                            ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                            0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) -
                                      (uint)(byte)*puVar23) * (int)uVar36 +
                                      (uint)(byte)*puVar23 * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          uVar36 = (ulonglong)DAT_140c28a88;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            lVar28 = (longlong)((int)uVar18 >> 0x12);
                            lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                            lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                            iVar30 = local_170;
                            if (*(byte *)(lVar28 + lVar19) != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                        *(byte *)(lVar28 + lVar19) *
                                                                        4)] - (uint)(byte)*puVar23)
                                          * (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)]
                                          * (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((local_188[*(byte *)(lVar22 + 1 +
                                                              (ulonglong)*(byte *)(lVar28 + lVar19)
                                                              * 4)] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                          DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((local_178[*(byte *)(lVar22 + 2 +
                                                              (ulonglong)*(byte *)(lVar28 + lVar19)
                                                              * 4)] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                          DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                    *(byte *)(lVar28 + lVar19) * 4)]
                                      - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((local_188[*(byte *)(lVar22 + 1 +
                                                          (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                                ] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((local_178[*(byte *)(lVar22 + 2 +
                                                          (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                                ] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  iVar41 = local_110;
                  if (local_1ac != 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(lVar22 + (ulonglong)
                                                                  *(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(lVar22 + 1 +
                                                        (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(lVar22 + 2 +
                                                        (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            uVar36 = (ulonglong)DAT_140c28a88;
                            iVar34 = local_1b8;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  do {
                    do {
                      if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                        uVar9 = uVar44;
                        if ((int)uVar44 < 0) {
                          uVar9 = uVar44 + 0x3ffff;
                        }
                        uVar18 = uVar38;
                        if ((int)uVar38 < 0) {
                          uVar18 = uVar38 + 0x3ffff;
                        }
                        lVar28 = (longlong)((int)uVar18 >> 0x12);
                        lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                        lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                        *(byte *)puVar23 =
                             (byte)(((uint)*(byte *)(lVar22 + (ulonglong)*(byte *)(lVar28 + lVar19)
                                                              * 4) - (uint)(byte)*puVar23) *
                                    (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                    (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                        *(byte *)((longlong)puVar23 + 1) =
                             (byte)(((uint)*(byte *)(lVar22 + 1 +
                                                    (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                    (uint)*(byte *)((longlong)puVar23 + 1)) *
                                    (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                    DAT_140c28a88 + (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000
                                   >> 0x10);
                        *(byte *)((longlong)puVar23 + 2) =
                             (byte)(((uint)*(byte *)(lVar22 + 2 +
                                                    (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                    (uint)*(byte *)((longlong)puVar23 + 2)) *
                                    (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                    DAT_140c28a88 + (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000
                                   >> 0x10);
                        uVar36 = (ulonglong)DAT_140c28a88;
                        iVar30 = local_170;
                      }
                      uVar38 = uVar38 + iVar34;
                      uVar44 = uVar44 + iVar30;
                      puVar23 = puVar23 + 1;
                      iVar41 = iVar41 + -1;
                    } while (iVar41 != 0);
                    uVar38 = uVar38 + local_1a4;
                    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                    uVar44 = uVar44 + local_1a8;
                    local_10c = local_10c + -1;
                    iVar41 = local_110;
                  } while (local_10c != 0);
                  return;
                }
              case 0:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            *puVar23 = *(uint *)(lVar22 + (ulonglong)
                                                          *(byte *)((&DAT_140e318b0)
                                                                    [(int)uVar9 >> 0x12] +
                                                                   (longlong)((int)uVar18 >> 0x12))
                                                          * 4);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (bVar24 != local_198) {
                              *puVar23 = *(uint *)(lVar22 + (ulonglong)bVar24 * 4);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 *(byte *)(local_180 + *(byte *)(lVar22 + (ulonglong)*pbVar3 * 4));
                            *(byte *)((longlong)puVar23 + 1) =
                                 *(byte *)(local_188 +
                                          *(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4));
                            *(byte *)((longlong)puVar23 + 2) =
                                 *(byte *)(local_178 +
                                          *(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4));
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   *(byte *)(local_180 + *(byte *)(lVar22 + (ulonglong)*pbVar3 * 4))
                              ;
                              *(byte *)((longlong)puVar23 + 1) =
                                   *(byte *)(local_188 +
                                            *(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4));
                              *(byte *)((longlong)puVar23 + 2) =
                                   *(byte *)(local_178 +
                                            *(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4));
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)(((uint)*(byte *)(lVar22 + (ulonglong)
                                                                *(byte *)(lVar28 + lVar19) * 4) -
                                      (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)(byte)*puVar23 * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)*(byte *)(lVar22 + 1 +
                                                      (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)*(byte *)(lVar22 + 2 +
                                                      (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(lVar22 + (ulonglong)
                                                                  *(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(lVar22 + 1 +
                                                        (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(lVar22 + 2 +
                                                        (ulonglong)*(byte *)(lVar28 + lVar19) * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                    *(byte *)(lVar28 + lVar19) * 4)]
                                      - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)(byte)*puVar23 * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((local_188[*(byte *)(lVar22 + 1 +
                                                          (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                                ] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((local_178[*(byte *)(lVar22 + 2 +
                                                          (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                                ] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                      *(byte *)(lVar28 + lVar19) * 4
                                                            )] - (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[*(byte *)(lVar22 + 1 +
                                                            (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                            4)] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[*(byte *)(lVar22 + 2 +
                                                            (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                            4)] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 2:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar2 = (ulonglong)
                                      *(byte *)((longlong)
                                                ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                                0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)
                                             (local_138 + *(byte *)(lVar22 + 1 + uVar2 * 4)),
                                            *(undefined1 *)
                                             (local_138 + *(byte *)(lVar22 + uVar2 * 4)));
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)
                                             (local_138 + *(byte *)(lVar22 + 2 + uVar2 * 4)),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = *(byte *)((longlong)
                                                 ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar9 = (uint)bVar24;
                              if (uVar9 != local_198) {
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)
                                               (local_138 +
                                               *(byte *)(lVar22 + 1 + (ulonglong)uVar9 * 4)),
                                              *(undefined1 *)
                                               (local_138 +
                                               *(byte *)(lVar22 + (ulonglong)bVar24 * 4)));
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)
                                               (local_138 +
                                               *(byte *)(lVar22 + 2 + (ulonglong)uVar9 * 4)),
                                              (undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar2 = (ulonglong)
                                      *(byte *)((longlong)
                                                ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                                0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)
                                             (local_138 +
                                             (uint)local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)]),
                                            *(undefined1 *)
                                             (local_138 +
                                             (uint)local_180[*(byte *)(lVar22 + uVar2 * 4)]));
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)
                                             (local_138 +
                                             (uint)local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)]),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = *(byte *)((longlong)
                                                 ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              uVar9 = (uint)bVar24;
                              if (uVar9 != local_198) {
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_188[*(byte *)(lVar22 + 1 +
                                                                        (ulonglong)uVar9 * 4)]),
                                              *(undefined1 *)
                                               (local_138 +
                                               (uint)local_180[*(byte *)(lVar22 + (ulonglong)bVar24
                                                                                  * 4)]));
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_178[*(byte *)(lVar22 + 2 +
                                                                        (ulonglong)uVar9 * 4)]),
                                              (undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar2 = (ulonglong)
                                    *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)((uint)*(byte *)(lVar22 + 1 + uVar2 * 4) *
                                                 (uint)bVar24 * iVar43 >> 0x10),
                                          (char)((uint)*(byte *)(lVar22 + uVar2 * 4) * (uint)bVar24
                                                 * iVar43 >> 0x10));
                            local_1ac._0_3_ =
                                 CONCAT12((char)((uint)*(byte *)(lVar22 + 2 + uVar2 * 4) *
                                                 (uint)bVar24 * iVar43 >> 0x10),
                                          (undefined2)local_1ac);
                            local_1ac = (uint)(uint3)local_1ac;
                            uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                       uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar26 = (uint)*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                    (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            iVar30 = local_170;
                            if (uVar26 != local_198) {
                              uVar2 = (ulonglong)uVar26;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar30 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)((uint)*(byte *)(lVar22 + 1 + uVar2 * 4) *
                                                   (uint)bVar24 * iVar30 >> 0x10),
                                            (char)((uint)*(byte *)(lVar22 + uVar2 * 4) *
                                                   (uint)bVar24 * iVar30 >> 0x10));
                              local_1ac._0_3_ =
                                   CONCAT12((char)((uint)*(byte *)(lVar22 + 2 + uVar2 * 4) *
                                                   (uint)bVar24 * iVar30 >> 0x10),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                              iVar30 = local_170;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar2 = (ulonglong)
                                    *(byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar43 >> 0x10),
                                          (char)(local_180[*(byte *)(lVar22 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar43 >> 0x10));
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar43 >> 0x10),
                                          (undefined2)local_1ac);
                            local_1ac = (uint)(uint3)local_1ac;
                            uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                       uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            uVar26 = (uint)*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                    (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            iVar30 = local_170;
                            if (uVar26 != local_198) {
                              uVar2 = (ulonglong)uVar26;
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar30 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)(local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)] *
                                                   (uint)bVar24 * iVar30 >> 0x10),
                                            (char)(local_180[*(byte *)(lVar22 + uVar2 * 4)] *
                                                   (uint)bVar24 * iVar30 >> 0x10));
                              local_1ac._0_3_ =
                                   CONCAT12((char)(local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)] *
                                                   (uint)bVar24 * iVar30 >> 0x10),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                              iVar30 = local_170;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 3:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar2 = (ulonglong)
                                    *(byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            local_1ac._0_2_ =
                                 CONCAT11(*(undefined1 *)
                                           (local_138 + *(byte *)(lVar22 + 1 + uVar2 * 4)),
                                          *(undefined1 *)(local_138 + *(byte *)(lVar22 + uVar2 * 4))
                                         );
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12(*(undefined1 *)
                                           (local_138 + *(byte *)(lVar22 + 2 + uVar2 * 4)),
                                          (undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            uVar18 = (uint)bVar24;
                            if (uVar18 != local_198) {
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)
                                             (local_138 +
                                             *(byte *)(lVar22 + 1 + (ulonglong)uVar18 * 4)),
                                            *(undefined1 *)
                                             (local_138 + *(byte *)(lVar22 + (ulonglong)bVar24 * 4))
                                           );
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)
                                             (local_138 +
                                             *(byte *)(lVar22 + 2 + (ulonglong)uVar18 * 4)),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar2 = (ulonglong)
                                    *(byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            local_1ac._0_2_ =
                                 CONCAT11(*(undefined1 *)
                                           (local_138 +
                                           (uint)local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)]),
                                          *(undefined1 *)
                                           (local_138 +
                                           (uint)local_180[*(byte *)(lVar22 + uVar2 * 4)]));
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12(*(undefined1 *)
                                           (local_138 +
                                           (uint)local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)]),
                                          (undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            bVar24 = *(byte *)((longlong)
                                               ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) + (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            uVar18 = (uint)bVar24;
                            if (uVar18 != local_198) {
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)
                                             (local_138 +
                                             (uint)local_188[*(byte *)(lVar22 + 1 +
                                                                      (ulonglong)uVar18 * 4)]),
                                            *(undefined1 *)
                                             (local_138 +
                                             (uint)local_180[*(byte *)(lVar22 + (ulonglong)bVar24 *
                                                                                4)]));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)
                                             (local_138 +
                                             (uint)local_178[*(byte *)(lVar22 + 2 +
                                                                      (ulonglong)uVar18 * 4)]),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        uVar9 = local_1ac;
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          uVar2 = (ulonglong)
                                  *(byte *)((longlong)((int)uVar26 >> 0x12) +
                                           (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                          iVar43 = (int)uVar36;
                          local_1ac._0_2_ =
                               CONCAT11((char)((uint)*(byte *)(lVar22 + 1 + uVar2 * 4) *
                                               (uint)bVar24 * iVar43 >> 0x10),
                                        (char)((uint)*(byte *)(lVar22 + uVar2 * 4) * (uint)bVar24 *
                                               iVar43 >> 0x10));
                          local_1ac._3_1_ = SUB41(uVar9,3);
                          local_1ac._0_3_ =
                               CONCAT12((char)((uint)*(byte *)(lVar22 + 2 + uVar2 * 4) *
                                               (uint)bVar24 * iVar43 >> 0x10),(undefined2)local_1ac)
                          ;
                          uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                          uVar9 = uVar18 & 0x1010100;
                          *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        uVar9 = local_1ac;
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          uVar32 = (uint)*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                  (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                          iVar30 = local_170;
                          if (uVar32 != local_198) {
                            uVar2 = (ulonglong)uVar32;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                            iVar30 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)((uint)*(byte *)(lVar22 + 1 + uVar2 * 4) *
                                                 (uint)bVar24 * iVar30 >> 0x10),
                                          (char)((uint)*(byte *)(lVar22 + uVar2 * 4) * (uint)bVar24
                                                 * iVar30 >> 0x10));
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12((char)((uint)*(byte *)(lVar22 + 2 + uVar2 * 4) *
                                                 (uint)bVar24 * iVar30 >> 0x10),
                                          (undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            iVar30 = local_170;
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        uVar9 = local_1ac;
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          uVar2 = (ulonglong)
                                  *(byte *)((longlong)((int)uVar26 >> 0x12) +
                                           (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                          bVar24 = (&DAT_140c28970)
                                   [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                          iVar43 = (int)uVar36;
                          local_1ac._0_2_ =
                               CONCAT11((char)(local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)] *
                                               (uint)bVar24 * iVar43 >> 0x10),
                                        (char)(local_180[*(byte *)(lVar22 + uVar2 * 4)] *
                                               (uint)bVar24 * iVar43 >> 0x10));
                          local_1ac._3_1_ = SUB41(uVar9,3);
                          local_1ac._0_3_ =
                               CONCAT12((char)(local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)] *
                                               (uint)bVar24 * iVar43 >> 0x10),(undefined2)local_1ac)
                          ;
                          uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                          uVar9 = uVar18 & 0x1010100;
                          *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        uVar9 = local_1ac;
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          uVar32 = (uint)*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                  (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                          iVar30 = local_170;
                          if (uVar32 != local_198) {
                            uVar2 = (ulonglong)uVar32;
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                            iVar30 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[*(byte *)(lVar22 + 1 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar30 >> 0x10),
                                          (char)(local_180[*(byte *)(lVar22 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar30 >> 0x10));
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[*(byte *)(lVar22 + 2 + uVar2 * 4)] *
                                                 (uint)bVar24 * iVar30 >> 0x10),
                                          (undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            iVar30 = local_170;
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 4:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) *
                                        (uint)(byte)*puVar23 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) *
                                          (uint)(byte)*puVar23 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] *
                                        (uint)(byte)*puVar23 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] *
                                          (uint)(byte)*puVar23 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)]
                                          * (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)]
                                          * (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)((uint)*(byte *)(lVar22 + (ulonglong)*(byte *)(lVar28 + lVar19)
                                                               * 4) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)(byte)*puVar23 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((uint)*(byte *)(lVar22 + 1 +
                                                     (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((uint)*(byte *)(lVar22 + 2 +
                                                     (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)((uint)*(byte *)(lVar22 + (ulonglong)
                                                                 *(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (uint)(byte)*puVar23 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((uint)*(byte *)(lVar22 + 1 +
                                                       (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((uint)*(byte *)(lVar22 + 2 +
                                                       (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                            iVar30 = local_170;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)(local_180[*(byte *)(lVar22 + (ulonglong)
                                                                   *(byte *)(lVar28 + lVar19) * 4)]
                                      * (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)(byte)*puVar23 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(local_188[*(byte *)(lVar22 + 1 +
                                                         (ulonglong)*(byte *)(lVar28 + lVar19) * 4)]
                                      * (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(local_178[*(byte *)(lVar22 + 2 +
                                                         (ulonglong)*(byte *)(lVar28 + lVar19) * 4)]
                                      * (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          iVar43 = (int)uVar9 >> 0x12;
                          uVar9 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar9 = uVar38 + 0x3ffff;
                          }
                          lVar37 = (longlong)((int)uVar9 >> 0x12);
                          lVar19 = (&DAT_140e398b0)[iVar43];
                          iVar30 = local_170;
                          if (*(byte *)(lVar37 + (&DAT_140e318b0)[iVar43]) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)(local_180[*(byte *)(lVar22 + (ulonglong)
                                                                     *(byte *)(lVar37 + (&
                                                  DAT_140e318b0)[iVar43]) * 4)] *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar37 + lVar19)] *
                                        (uint)(byte)*puVar23 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[*(byte *)(lVar22 + 1 +
                                                           (ulonglong)
                                                           *(byte *)(lVar37 + (&DAT_140e318b0)
                                                                              [iVar43]) * 4)] *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar37 + lVar19)] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[*(byte *)(lVar22 + 2 +
                                                           (ulonglong)
                                                           *(byte *)(lVar37 + (&DAT_140e318b0)
                                                                              [iVar43]) * 4)] *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar37 + lVar19)] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 10:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) -
                                        (uint)(byte)*puVar23) * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)
                                        - (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)
                                        - (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(((uint)(byte)~*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) -
                                          (uint)(byte)*puVar23) * (int)uVar36 +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~*(byte *)(lVar22 + 1 +
                                                                 (ulonglong)*pbVar3 * 4) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)(byte)~*(byte *)(lVar22 + 2 +
                                                                 (ulonglong)*pbVar3 * 4) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 +
                                                        (byte)~*(byte *)(lVar22 + (ulonglong)*pbVar3
                                                                                  * 4)) -
                                        (uint)(byte)*puVar23) * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 +
                                                        (byte)~*(byte *)(lVar22 + 1 +
                                                                        (ulonglong)*pbVar3 * 4)) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 +
                                                        (byte)~*(byte *)(lVar22 + 2 +
                                                                        (ulonglong)*pbVar3 * 4)) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(((uint)*(byte *)(local_180 +
                                                          (byte)~*(byte *)(lVar22 + (ulonglong)
                                                                                    *pbVar3 * 4)) -
                                          (uint)(byte)*puVar23) * (int)uVar36 +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)(local_188 +
                                                          (byte)~*(byte *)(lVar22 + 1 +
                                                                          (ulonglong)*pbVar3 * 4)) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)(local_178 +
                                                          (byte)~*(byte *)(lVar22 + 2 +
                                                                          (ulonglong)*pbVar3 * 4)) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)(((uint)(byte)~*(byte *)(lVar22 + (ulonglong)
                                                                       *(byte *)(lVar28 + lVar19) *
                                                                       4) - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)(byte)~*(byte *)(lVar22 + 1 +
                                                             (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                             4) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)(byte)~*(byte *)(lVar22 + 2 +
                                                             (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                             4) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + (ulonglong)
                                                                         *(byte *)(lVar28 + lVar19)
                                                                         * 4) - (uint)(byte)*puVar23
                                        ) * (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)]
                                        * (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + 1 +
                                                               (ulonglong)*(byte *)(lVar28 + lVar19)
                                                               * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)(byte)~*(byte *)(lVar22 + 2 +
                                                               (ulonglong)*(byte *)(lVar28 + lVar19)
                                                               * 4) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_198 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)(((uint)*(byte *)(local_180 +
                                                      (byte)~*(byte *)(lVar22 + (ulonglong)
                                                                                *(byte *)(lVar28 + 
                                                  lVar19) * 4)) - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)*(byte *)(local_188 +
                                                      (byte)~*(byte *)(lVar22 + 1 +
                                                                      (ulonglong)
                                                                      *(byte *)(lVar28 + lVar19) * 4
                                                                      )) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)*(byte *)(local_178 +
                                                      (byte)~*(byte *)(lVar22 + 2 +
                                                                      (ulonglong)
                                                                      *(byte *)(lVar28 + lVar19) * 4
                                                                      )) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          iVar30 = local_170;
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar26 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar18 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar18 >> 0x12];
                          iVar30 = local_170;
                          if (*(byte *)(lVar28 + lVar19) != uVar9) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 +
                                                        (byte)~*(byte *)(lVar22 + (ulonglong)
                                                                                  *(byte *)(lVar28 +
                                                                                           lVar19) *
                                                                                  4)) -
                                        (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 +
                                                        (byte)~*(byte *)(lVar22 + 1 +
                                                                        (ulonglong)
                                                                        *(byte *)(lVar28 + lVar19) *
                                                                        4)) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 +
                                                        (byte)~*(byte *)(lVar22 + 2 +
                                                                        (ulonglong)
                                                                        *(byte *)(lVar28 + lVar19) *
                                                                        4)) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            iVar34 = local_1b8;
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_198 = local_198 + -1;
                      } while (local_198 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_198 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 0xb:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) *
                                          (uint)bVar24 >> 8) - (uint)bVar24) * (int)uVar36 +
                                        (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) *
                                          (uint)bVar24 >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                        (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) *
                                          (uint)bVar24 >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                        (uint)bVar24 * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)((((uint)*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4) *
                                            (uint)bVar24 >> 8) - (uint)bVar24) * (int)uVar36 +
                                          (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4) *
                                            (uint)bVar24 >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                          (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((((uint)*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4) *
                                            (uint)bVar24 >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                          (uint)bVar24 * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] *
                                          (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) * (int)uVar36 +
                                        (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)]
                                          * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                        DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)]
                                          * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                        DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              ((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                              0x12) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*pbVar3 != local_198) {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)(((local_180[*(byte *)(lVar22 + (ulonglong)*pbVar3 * 4)] *
                                            (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) * (int)uVar36
                                          + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((local_188[*(byte *)(lVar22 + 1 + (ulonglong)*pbVar3 * 4)
                                                     ] * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((local_178[*(byte *)(lVar22 + 2 + (ulonglong)*pbVar3 * 4)
                                                     ] * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = (byte)*puVar23;
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)((((uint)*(byte *)(lVar22 + (ulonglong)
                                                                 *(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)bVar24 >> 8) - (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 1);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((((uint)*(byte *)(lVar22 + 1 +
                                                       (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)bVar24 >> 8) - (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 2);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((((uint)*(byte *)(lVar22 + 2 +
                                                       (ulonglong)*(byte *)(lVar28 + lVar19) * 4) *
                                        (uint)bVar24 >> 8) - (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          if (*(byte *)(lVar28 + lVar19) != local_198) {
                            bVar24 = (byte)*puVar23;
                            *(byte *)puVar23 =
                                 (byte)((((uint)*(byte *)(lVar22 + (ulonglong)
                                                                   *(byte *)(lVar28 + lVar19) * 4) *
                                          (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((((uint)*(byte *)(lVar22 + 1 +
                                                         (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                          * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((((uint)*(byte *)(lVar22 + 2 +
                                                         (ulonglong)*(byte *)(lVar28 + lVar19) * 4)
                                          * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_198 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = (byte)*puVar23;
                          lVar28 = (longlong)((int)uVar18 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar9 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar9 >> 0x12];
                          *(byte *)puVar23 =
                               (byte)(((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                     *(byte *)(lVar28 + lVar19) * 4)
                                                 ] * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 1);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((local_188[*(byte *)(lVar22 + 1 +
                                                           (ulonglong)*(byte *)(lVar28 + lVar19) * 4
                                                           )] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 2);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((local_178[*(byte *)(lVar22 + 2 +
                                                           (ulonglong)*(byte *)(lVar28 + lVar19) * 4
                                                           )] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) *
                                      (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          iVar30 = local_170;
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar18 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar18 = uVar44 + 0x3ffff;
                          }
                          uVar26 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar26 = uVar38 + 0x3ffff;
                          }
                          lVar28 = (longlong)((int)uVar26 >> 0x12);
                          lVar19 = (&DAT_140e318b0)[(int)uVar18 >> 0x12];
                          lVar37 = (&DAT_140e398b0)[(int)uVar18 >> 0x12];
                          iVar30 = local_170;
                          if (*(byte *)(lVar28 + lVar19) != uVar9) {
                            bVar24 = (byte)*puVar23;
                            *(byte *)puVar23 =
                                 (byte)(((local_180[*(byte *)(lVar22 + (ulonglong)
                                                                       *(byte *)(lVar28 + lVar19) *
                                                                       4)] * (uint)bVar24 >> 8 &
                                         0xff) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[*(byte *)(lVar22 + 1 +
                                                             (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                             4)] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[*(byte *)(lVar22 + 2 +
                                                             (ulonglong)*(byte *)(lVar28 + lVar19) *
                                                             4)] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*(byte *)(lVar28 + lVar37)] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                            iVar34 = local_1b8;
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_198 = local_198 + -1;
                      } while (local_198 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_198 = local_110;
                    } while (local_10c != 0);
                  }
                }
              }
            }
            else {
              switch(DAT_140c28a84) {
              case 1:
                if (iVar41 != 0xff) {
                  if (iVar41 == 0) {
                    return;
                  }
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                        iVar41 = local_110;
                        if (local_1ac != 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar4 = (uint *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                if (*puVar4 != local_198) {
                                  *(byte *)puVar23 =
                                       (byte)((local_180[(byte)*puVar4] - (uint)(byte)*puVar23) *
                                              (int)uVar36 + (uint)(byte)*puVar23 * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 1) =
                                       (byte)((local_188[*(byte *)((longlong)puVar4 + 1)] -
                                              (uint)*(byte *)((longlong)puVar23 + 1)) *
                                              DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 2) =
                                       (byte)((local_178[*(byte *)((longlong)puVar4 + 2)] -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                                  uVar36 = (ulonglong)DAT_140c28a88;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                          return;
                        }
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) * (int)uVar36
                                          + (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((local_188[pbVar3[1]] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((local_178[pbVar3[2]] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = pbVar3[3];
                              if (bVar24 != 0) {
                                bVar1 = (byte)*puVar23;
                                if (bVar24 == 0xff) {
                                  *(byte *)puVar23 =
                                       (byte)((local_180[*pbVar3] - (uint)bVar1) * (int)uVar36 +
                                              (uint)bVar1 * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 1) =
                                       (byte)((local_188[pbVar3[1]] -
                                              (uint)*(byte *)((longlong)puVar23 + 1)) *
                                              DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 2) =
                                       (byte)((local_178[pbVar3[2]] -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                                }
                                else {
                                  *(byte *)puVar23 =
                                       (byte)((local_180[*pbVar3] - (uint)bVar1) * (uint)bVar24 *
                                              (int)uVar36 + (uint)bVar1 * 0x10000 >> 0x10);
                                  *(byte *)((longlong)puVar23 + 1) =
                                       (byte)((local_188[pbVar3[1]] -
                                              (uint)*(byte *)((longlong)puVar23 + 1)) *
                                              (uint)pbVar3[3] * DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >>
                                             0x10);
                                  *(byte *)((longlong)puVar23 + 2) =
                                       (byte)((local_178[pbVar3[2]] -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              (uint)pbVar3[3] * DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >>
                                             0x10);
                                }
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                        (uint)pbVar3[3] * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[pbVar3[1]] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[pbVar3[2]] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                      iVar41 = local_110;
                      if (local_1ac != 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                *(byte *)puVar23 =
                                     (byte)(((uint)(byte)*puVar4 - (uint)(byte)*puVar23) *
                                            (int)uVar36 + (uint)(byte)*puVar23 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)*(byte *)((longlong)puVar4 + 1) -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)*(byte *)((longlong)puVar4 + 2) -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((uint)*pbVar3 - (uint)(byte)*puVar23) * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = pbVar3[3];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                *(byte *)puVar23 =
                                     (byte)(((uint)*pbVar3 - (uint)(byte)*puVar23) * (int)uVar36 +
                                            (uint)(byte)*puVar23 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)(((uint)*pbVar3 - (uint)(byte)*puVar23) * (uint)bVar24 *
                                            (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)pbVar3[3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10
                                           );
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)pbVar3[3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10
                                           );
                              }
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)
                                            (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                             0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((uint)*pbVar3 - (uint)(byte)*puVar23) * (uint)pbVar3[3] *
                                      (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)pbVar3[3] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)pbVar3[3] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          uVar36 = (ulonglong)DAT_140c28a88;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                      bVar46 = local_1ac != 0;
                      iVar41 = local_110;
                      local_1ac = local_110;
                      if (bVar46) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                              iVar30 = local_170;
                              if (*puVar4 != local_198) {
                                *(byte *)puVar23 =
                                     (byte)((local_180[(byte)*puVar4] - (uint)(byte)*puVar23) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar3] * (int)uVar36 +
                                            (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((local_188[*(byte *)((longlong)puVar4 + 1)] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10
                                           );
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((local_178[*(byte *)((longlong)puVar4 + 2)] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10
                                           );
                                uVar36 = (ulonglong)DAT_140c28a88;
                                iVar34 = local_1b8;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            local_1ac = local_1ac + -1;
                          } while (local_1ac != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          local_1ac = local_110;
                        } while (local_10c != 0);
                        return;
                      }
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[pbVar3[1]] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[pbVar3[2]] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            uVar36 = (ulonglong)DAT_140c28a88;
                            iVar30 = local_170;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] != 0) {
                              bVar24 = (byte)*puVar23;
                              if (pbVar3[3] == 0xff) {
                                *(byte *)puVar23 =
                                     (byte)((local_180[*pbVar3] - (uint)bVar24) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * (int)uVar36 +
                                            (uint)bVar24 * 0x10000 >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((local_188[pbVar3[1]] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10
                                           );
                                bVar24 = (byte)((local_178[pbVar3[2]] -
                                                (uint)*(byte *)((longlong)puVar23 + 2)) *
                                                (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                                DAT_140c28a88 +
                                                (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >>
                                               0x10);
                                iVar30 = local_170;
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)((local_180[*pbVar3] - (uint)bVar24) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                            * (int)uVar36 + (uint)bVar24 * 0x1000000 >> 0x18);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((local_188[pbVar3[1]] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                            * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >>
                                           0x18);
                                bVar24 = (byte)((local_178[pbVar3[2]] -
                                                (uint)*(byte *)((longlong)puVar23 + 2)) *
                                                (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                                (uint)pbVar3[3] * DAT_140c28a88 +
                                                (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000
                                               >> 0x18);
                                iVar34 = local_1b8;
                              }
                              *(byte *)((longlong)puVar23 + 2) = bVar24;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                      (int)uVar36 + (uint)(byte)*puVar23 * 0x1000000 >> 0x18);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((local_188[pbVar3[1]] - (uint)*(byte *)((longlong)puVar23 + 1)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((local_178[pbVar3[2]] - (uint)*(byte *)((longlong)puVar23 + 2)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18);
                          uVar36 = (ulonglong)DAT_140c28a88;
                          iVar30 = local_170;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) != 1) {
                    iVar41 = local_110;
                    if (local_1ac != 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          ((uint)(byte)*puVar4 - (uint)(byte)*puVar23) * (int)uVar36
                                          + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)((longlong)puVar4 + 1) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)((longlong)puVar4 + 2) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                      return;
                    }
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      ((uint)*pbVar3 - (uint)(byte)*puVar23) * (int)uVar36 +
                                      (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          uVar36 = (ulonglong)DAT_140c28a88;
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  iVar41 = local_110;
                  if (local_1ac != 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          bVar24 = pbVar3[3];
                          if (bVar24 != 0) {
                            bVar1 = (byte)*puVar23;
                            if (bVar24 == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          ((uint)*pbVar3 - (uint)bVar1) * (int)uVar36 +
                                          (uint)bVar1 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1))
                                          * (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2))
                                          * (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          ((uint)*pbVar3 - (uint)bVar1) * (uint)bVar24 * (int)uVar36
                                          + (uint)bVar1 * 0x1000000 >> 0x18);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1))
                                          * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18
                                         );
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2))
                                          * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18
                                         );
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                    return;
                  }
                  do {
                    do {
                      if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                        uVar9 = uVar44;
                        if ((int)uVar44 < 0) {
                          uVar9 = uVar44 + 0x3ffff;
                        }
                        uVar18 = uVar38;
                        if ((int)uVar38 < 0) {
                          uVar18 = uVar38 + 0x3ffff;
                        }
                        pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                          (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                        pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                         (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                        *(byte *)puVar23 =
                             (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                    ((uint)*pbVar3 - (uint)(byte)*puVar23) * (uint)pbVar3[3] *
                                    (int)uVar36 + (uint)(byte)*puVar23 * 0x1000000 >> 0x18);
                        *(byte *)((longlong)puVar23 + 1) =
                             (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                    (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                    DAT_140c28a88 +
                                    (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18);
                        *(byte *)((longlong)puVar23 + 2) =
                             (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                    (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                    DAT_140c28a88 +
                                    (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18);
                        uVar36 = (ulonglong)DAT_140c28a88;
                      }
                      uVar38 = uVar38 + iVar34;
                      uVar44 = uVar44 + iVar30;
                      puVar23 = puVar23 + 1;
                      iVar41 = iVar41 + -1;
                    } while (iVar41 != 0);
                    uVar38 = uVar38 + local_1a4;
                    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                    uVar44 = uVar44 + local_1a8;
                    local_10c = local_10c + -1;
                    iVar41 = local_110;
                  } while (local_10c != 0);
                  return;
                }
              case 0:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)(((uint)*pbVar3 - (uint)(byte)*puVar23) * (uint)pbVar3[3] +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1))
                                          * (uint)pbVar3[3] +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2))
                                          * (uint)pbVar3[3] +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = *(byte *)((longlong)puVar4 + 3);
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  *puVar23 = *puVar4;
                                }
                                else {
                                  *(byte *)puVar23 =
                                       (byte)(((uint)(byte)*puVar4 - (uint)(byte)*puVar23) *
                                              (uint)bVar24 + (uint)(byte)*puVar23 * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 1) =
                                       (byte)(((uint)*(byte *)((longlong)puVar4 + 1) -
                                              (uint)*(byte *)((longlong)puVar23 + 1)) *
                                              (uint)*(byte *)((longlong)puVar4 + 3) +
                                              (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                  *(byte *)((longlong)puVar23 + 2) =
                                       (byte)(((uint)*(byte *)((longlong)puVar4 + 2) -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              (uint)*(byte *)((longlong)puVar4 + 3) +
                                              (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                                }
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              *puVar23 = *(uint *)((longlong)
                                                   (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)
                                                          ) >> 0x12) << 2) +
                                                  (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar9 = *(uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (uVar9 != local_198) {
                                *puVar23 = uVar9;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                        (uint)pbVar3[3] + (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[pbVar3[1]] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * (uint)pbVar3[3] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[pbVar3[2]] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * (uint)pbVar3[3] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = pbVar3[3];
                            if (bVar24 != 0) {
                              if (bVar24 == 0xff) {
                                *(byte *)puVar23 = *(byte *)(local_180 + *pbVar3);
                                *(byte *)((longlong)puVar23 + 1) = *(byte *)(local_188 + pbVar3[1]);
                                *(byte *)((longlong)puVar23 + 2) = *(byte *)(local_178 + pbVar3[2]);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                            (uint)bVar24 + (uint)(byte)*puVar23 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((local_188[pbVar3[1]] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)pbVar3[3] +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((local_178[pbVar3[2]] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)pbVar3[3] +
                                            (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 = *(byte *)(local_180 + *pbVar3);
                            *(byte *)((longlong)puVar23 + 1) = *(byte *)(local_188 + pbVar3[1]);
                            *(byte *)((longlong)puVar23 + 2) = *(byte *)(local_178 + pbVar3[2]);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 = *(byte *)(local_180 + (byte)*puVar4);
                              *(byte *)((longlong)puVar23 + 1) =
                                   *(byte *)(local_188 + *(byte *)((longlong)puVar4 + 1));
                              *(byte *)((longlong)puVar23 + 2) =
                                   *(byte *)(local_178 + *(byte *)((longlong)puVar4 + 2));
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        ((uint)*pbVar3 - (uint)(byte)*puVar23) * (uint)pbVar3[3] +
                                        (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            bVar24 = pbVar3[3];
                            if (bVar24 != 0) {
                              bVar1 = (byte)*puVar23;
                              iVar43 = (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                       ((uint)*pbVar3 - (uint)bVar1);
                              if (bVar24 == 0xff) {
                                *(byte *)puVar23 = (byte)(iVar43 + (uint)bVar1 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                            (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)(iVar43 * (uint)bVar24 + (uint)bVar1 * 0x10000 >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >>
                                           0x10);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3]
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >>
                                           0x10);
                              }
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        ((uint)*pbVar3 - (uint)(byte)*puVar23) +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)pbVar3[1] - (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)pbVar3[2] - (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          ((uint)(byte)*puVar4 - (uint)(byte)*puVar23) +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)((longlong)puVar4 + 1) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)((longlong)puVar4 + 2) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                      (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((local_188[pbVar3[1]] - (uint)*(byte *)((longlong)puVar23 + 1)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((local_178[pbVar3[2]] - (uint)*(byte *)((longlong)puVar23 + 2)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          bVar24 = pbVar3[3];
                          if (bVar24 != 0) {
                            bVar1 = (byte)*puVar23;
                            if (bVar24 == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)((local_180[*pbVar3] - (uint)bVar1) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                          (uint)bVar1 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((local_188[pbVar3[1]] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((local_178[pbVar3[2]] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)((local_180[*pbVar3] - (uint)bVar1) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)bVar24 +
                                          (uint)bVar1 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((local_188[pbVar3[1]] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((local_178[pbVar3[2]] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                              iVar30 = local_170;
                            }
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((local_180[*pbVar3] - (uint)(byte)*puVar23) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                      (uint)(byte)*puVar23 * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)((local_188[pbVar3[1]] - (uint)*(byte *)((longlong)puVar23 + 1)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)((local_178[pbVar3[2]] - (uint)*(byte *)((longlong)puVar23 + 2)
                                      ) * (uint)(byte)(&DAT_140c28970)[*pbVar29] +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          if (*puVar4 != local_198) {
                            *(byte *)puVar23 =
                                 (byte)((local_180[(byte)*puVar4] - (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((local_188[*(byte *)((longlong)puVar4 + 1)] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((local_178[*(byte *)((longlong)puVar4 + 2)] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 2:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                bVar24 = pbVar3[3];
                                iVar43 = (int)uVar36;
                                local_1ac._0_2_ =
                                     CONCAT11((char)((uint)pbVar3[1] * iVar43 * (uint)bVar24 >> 0x10
                                                    ),(char)((uint)*pbVar3 * iVar43 * (uint)bVar24
                                                            >> 0x10));
                                local_1ac._0_3_ =
                                     CONCAT12((char)((uint)pbVar3[2] * iVar43 * (uint)bVar24 >> 0x10
                                                    ),(undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                bVar24 = pbVar3[3];
                                if (bVar24 != 0) {
                                  if (bVar24 == 0xff) {
                                    local_1ac._0_2_ =
                                         CONCAT11(*(undefined1 *)(local_138 + pbVar3[1]),
                                                  *(undefined1 *)(local_138 + *pbVar3));
                                    local_1ac._0_3_ =
                                         CONCAT12(*(undefined1 *)(local_138 + pbVar3[2]),
                                                  (undefined2)local_1ac);
                                  }
                                  else {
                                    iVar43 = (int)uVar36;
                                    local_1ac._0_2_ =
                                         CONCAT11((char)((uint)pbVar3[1] * iVar43 * (uint)bVar24 >>
                                                        0x10),
                                                  (char)((uint)*pbVar3 * iVar43 * (uint)bVar24 >>
                                                        0x10));
                                    local_1ac._0_3_ =
                                         CONCAT12((char)((uint)pbVar3[2] * iVar43 * (uint)bVar24 >>
                                                        0x10),(undefined2)local_1ac);
                                  }
                                  local_1ac = (uint)(uint3)local_1ac;
                                  uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                  uVar9 = uVar18 & 0x1010100;
                                  *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100
                                             | uVar18;
                                  uVar36 = (ulonglong)DAT_140c28a88;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                      else {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)(local_138 + pbVar3[1]),
                                              *(undefined1 *)(local_138 + *pbVar3));
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)(local_138 + pbVar3[2]),
                                              (undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                puVar4 = (uint *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                if (*puVar4 != local_198) {
                                  local_1ac._0_2_ =
                                       CONCAT11(*(undefined1 *)
                                                 (local_138 + *(byte *)((longlong)puVar4 + 1)),
                                                *(undefined1 *)(local_138 + (byte)*puVar4));
                                  local_1ac._0_3_ =
                                       CONCAT12(*(undefined1 *)
                                                 (local_138 + *(byte *)((longlong)puVar4 + 2)),
                                                (undefined2)local_1ac);
                                  local_1ac = (uint)(uint3)local_1ac;
                                  uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                  uVar9 = uVar18 & 0x1010100;
                                  *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100
                                             | uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                    }
                    else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = pbVar3[3];
                              iVar43 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)(local_188[pbVar3[1]] * iVar43 * (uint)bVar24 >>
                                                  0x10),
                                            (char)(local_180[*pbVar3] * iVar43 * (uint)bVar24 >>
                                                  0x10));
                              local_1ac._0_3_ =
                                   CONCAT12((char)(local_178[pbVar3[2]] * iVar43 * (uint)bVar24 >>
                                                  0x10),(undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = pbVar3[3];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  local_1ac._0_2_ =
                                       CONCAT11(*(undefined1 *)
                                                 (local_138 + (uint)local_188[pbVar3[1]]),
                                                *(undefined1 *)
                                                 (local_138 + (uint)local_180[*pbVar3]));
                                  local_1ac._0_3_ =
                                       CONCAT12(*(undefined1 *)
                                                 (local_138 + (uint)local_178[pbVar3[2]]),
                                                (undefined2)local_1ac);
                                }
                                else {
                                  iVar43 = (int)uVar36;
                                  local_1ac._0_2_ =
                                       CONCAT11((char)(local_188[pbVar3[1]] * iVar43 * (uint)bVar24
                                                      >> 0x10),
                                                (char)(local_180[*pbVar3] * iVar43 * (uint)bVar24 >>
                                                      0x10));
                                  local_1ac._0_3_ =
                                       CONCAT12((char)(local_178[pbVar3[2]] * iVar43 * (uint)bVar24
                                                      >> 0x10),(undefined2)local_1ac);
                                }
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_138 + (uint)local_188[pbVar3[1]]),
                                            *(undefined1 *)(local_138 + (uint)local_180[*pbVar3]));
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_138 + (uint)local_178[pbVar3[2]]),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_188[*(byte *)((longlong)puVar4 + 1)]),
                                              *(undefined1 *)
                                               (local_138 + (uint)local_180[(byte)*puVar4]));
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_178[*(byte *)((longlong)puVar4 + 2)]),
                                              (undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              iVar43 = (uint)(byte)(&DAT_140c28970)
                                                   [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12])]
                                       * (uint)pbVar3[3];
                              iVar16 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)((uint)pbVar3[1] * iVar43 * iVar16 >> 0x18),
                                            (char)((uint)*pbVar3 * iVar43 * iVar16 >> 0x18));
                              local_1ac._0_3_ =
                                   CONCAT12((char)((uint)pbVar3[2] * iVar43 * iVar16 >> 0x18),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = pbVar3[3];
                              if (bVar24 != 0) {
                                uVar9 = (uint)(byte)(&DAT_140c28970)
                                                    [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12])]
                                ;
                                iVar43 = (int)uVar36;
                                if (bVar24 == 0xff) {
                                  local_1ac._0_2_ =
                                       CONCAT11((char)(pbVar3[1] * uVar9 * iVar43 >> 0x10),
                                                (char)(*pbVar3 * uVar9 * iVar43 >> 0x10));
                                  uVar12 = (undefined1)(pbVar3[2] * uVar9 * iVar43 >> 0x10);
                                }
                                else {
                                  iVar16 = uVar9 * bVar24;
                                  local_1ac._0_2_ =
                                       CONCAT11((char)((uint)pbVar3[1] * iVar16 * iVar43 >> 0x18),
                                                (char)((uint)*pbVar3 * iVar16 * iVar43 >> 0x18));
                                  uVar12 = (undefined1)((uint)pbVar3[2] * iVar16 * iVar43 >> 0x18);
                                }
                                local_1ac._0_3_ = CONCAT12(uVar12,(undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar43 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)((uint)pbVar3[1] * (uint)bVar24 * iVar43 >> 0x10),
                                            (char)((uint)*pbVar3 * (uint)bVar24 * iVar43 >> 0x10));
                              local_1ac._0_3_ =
                                   CONCAT12((char)((uint)pbVar3[2] * (uint)bVar24 * iVar43 >> 0x10),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              uVar18 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar18 = uVar38 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                bVar24 = (&DAT_140c28970)
                                         [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                   (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                                iVar43 = (int)uVar36;
                                local_1ac._0_2_ =
                                     CONCAT11((char)((uint)*(byte *)((longlong)puVar4 + 1) *
                                                     (uint)bVar24 * iVar43 >> 0x10),
                                              (char)((uint)(byte)*puVar4 * (uint)bVar24 * iVar43 >>
                                                    0x10));
                                local_1ac._0_3_ =
                                     CONCAT12((char)((uint)*(byte *)((longlong)puVar4 + 2) *
                                                     (uint)bVar24 * iVar43 >> 0x10),
                                              (undefined2)local_1ac);
                                local_1ac = (uint)(uint3)local_1ac;
                                uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                           uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = pbVar3[3];
                            bVar1 = (&DAT_140c28970)
                                    [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[pbVar3[1]] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18),
                                          (char)(local_180[*pbVar3] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18));
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[pbVar3[2]] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18),(undefined2)local_1ac);
                            local_1ac = (uint)(uint3)local_1ac;
                            uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                       uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = pbVar3[3];
                            if (bVar24 != 0) {
                              bVar1 = (&DAT_140c28970)
                                      [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar16 = (int)uVar36;
                              iVar43 = local_180[*pbVar3] * (uint)bVar1 * iVar16;
                              uVar9 = (uint)bVar1;
                              if (bVar24 == 0xff) {
                                uVar12 = (undefined1)((uint)iVar43 >> 0x10);
                                uVar13 = (undefined1)(local_188[pbVar3[1]] * uVar9 * iVar16 >> 0x10)
                                ;
                                uVar14 = (undefined1)(local_178[pbVar3[2]] * uVar9 * iVar16 >> 0x10)
                                ;
                              }
                              else {
                                uVar12 = (undefined1)(iVar43 * (uint)bVar24 >> 0x18);
                                uVar13 = (undefined1)
                                         (local_188[pbVar3[1]] * (uint)bVar1 * iVar16 * (uint)bVar24
                                         >> 0x18);
                                uVar14 = (undefined1)
                                         (local_178[pbVar3[2]] * uVar9 * iVar16 * (uint)bVar24 >>
                                         0x18);
                              }
                              local_1ac._0_2_ = CONCAT11(uVar13,uVar12);
                              local_1ac._0_3_ = CONCAT12(uVar14,(undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[pbVar3[1]] * (uint)bVar24 * iVar43 >>
                                                0x10),
                                          (char)(local_180[*pbVar3] * (uint)bVar24 * iVar43 >> 0x10)
                                         );
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[pbVar3[2]] * (uint)bVar24 * iVar43 >>
                                                0x10),(undefined2)local_1ac);
                            local_1ac = (uint)(uint3)local_1ac;
                            uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                       uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar18 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar9 >> 0x12])];
                              iVar41 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)(local_188[*(byte *)((longlong)puVar4 + 1)] *
                                                   (uint)bVar24 * iVar41 >> 0x10),
                                            (char)(local_180[(byte)*puVar4] * (uint)bVar24 * iVar41
                                                  >> 0x10));
                              local_1ac._0_3_ =
                                   CONCAT12((char)(local_178[*(byte *)((longlong)puVar4 + 2)] *
                                                   (uint)bVar24 * iVar41 >> 0x10),
                                            (undefined2)local_1ac);
                              local_1ac = (uint)(uint3)local_1ac;
                              uVar18 = (*puVar23 & 0xfefeff) + (local_1ac & 0xfefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) | (*puVar23 | local_1ac) & 0x10100 |
                                         uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 3:
                if (iVar41 != 0) {
                  if (local_148 == 0) {
                    if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                      if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              uVar9 = local_1ac;
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar18 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar18 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                                bVar24 = pbVar3[3];
                                iVar43 = (int)uVar36;
                                local_1ac._0_2_ =
                                     CONCAT11((char)((uint)pbVar3[1] * iVar43 * (uint)bVar24 >> 0x10
                                                    ),(char)((uint)*pbVar3 * iVar43 * (uint)bVar24
                                                            >> 0x10));
                                local_1ac._3_1_ = SUB41(uVar9,3);
                                local_1ac._0_3_ =
                                     CONCAT12((char)((uint)pbVar3[2] * iVar43 * (uint)bVar24 >> 0x10
                                                    ),(undefined2)local_1ac);
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar9 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar9 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                                bVar24 = pbVar3[3];
                                if (bVar24 != 0) {
                                  if (bVar24 == 0xff) {
                                    local_1ac._0_2_ =
                                         CONCAT11(*(undefined1 *)(local_138 + pbVar3[1]),
                                                  *(undefined1 *)(local_138 + *pbVar3));
                                    local_1ac._0_3_ =
                                         CONCAT12(*(undefined1 *)(local_138 + pbVar3[2]),
                                                  (undefined2)local_1ac);
                                  }
                                  else {
                                    iVar43 = (int)uVar36;
                                    local_1ac._0_2_ =
                                         CONCAT11((char)((uint)pbVar3[1] * iVar43 * (uint)bVar24 >>
                                                        0x10),
                                                  (char)((uint)*pbVar3 * iVar43 * (uint)bVar24 >>
                                                        0x10));
                                    local_1ac._0_3_ =
                                         CONCAT12((char)((uint)pbVar3[2] * iVar43 * (uint)bVar24 >>
                                                        0x10),(undefined2)local_1ac);
                                  }
                                  uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                  uVar9 = uVar18 & 0x1010100;
                                  *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                  uVar36 = (ulonglong)DAT_140c28a88;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                      else {
                        iVar41 = local_110;
                        if (local_1ac == 0) {
                          do {
                            do {
                              uVar9 = local_1ac;
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar18 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar18 = uVar44 + 0x3ffff;
                                }
                                pbVar3 = (byte *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)(local_138 + pbVar3[1]),
                                              *(undefined1 *)(local_138 + *pbVar3));
                                local_1ac._3_1_ = SUB41(uVar9,3);
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)(local_138 + pbVar3[2]),
                                              (undefined2)local_1ac);
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                        else {
                          do {
                            do {
                              uVar9 = local_1ac;
                              if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                                uVar18 = uVar44;
                                if ((int)uVar44 < 0) {
                                  uVar18 = uVar44 + 0x3ffff;
                                }
                                puVar4 = (uint *)((longlong)
                                                  (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                   >> 0x12) << 2) +
                                                 (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                                if (*puVar4 != local_198) {
                                  local_1ac._0_2_ =
                                       CONCAT11(*(undefined1 *)
                                                 (local_138 + *(byte *)((longlong)puVar4 + 1)),
                                                *(undefined1 *)(local_138 + (byte)*puVar4));
                                  local_1ac._3_1_ = SUB41(uVar9,3);
                                  local_1ac._0_3_ =
                                       CONCAT12(*(undefined1 *)
                                                 (local_138 + *(byte *)((longlong)puVar4 + 2)),
                                                (undefined2)local_1ac);
                                  uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                  uVar9 = uVar18 & 0x1010100;
                                  *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                }
                              }
                              uVar38 = uVar38 + iVar34;
                              uVar44 = uVar44 + iVar30;
                              puVar23 = puVar23 + 1;
                              iVar41 = iVar41 + -1;
                            } while (iVar41 != 0);
                            uVar38 = uVar38 + local_1a4;
                            puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                            uVar44 = uVar44 + local_1a8;
                            local_10c = local_10c + -1;
                            iVar41 = local_110;
                          } while (local_10c != 0);
                        }
                      }
                    }
                    else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              bVar24 = pbVar3[3];
                              iVar43 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)(local_188[pbVar3[1]] * iVar43 * (uint)bVar24 >>
                                                  0x10),
                                            (char)(local_180[*pbVar3] * iVar43 * (uint)bVar24 >>
                                                  0x10));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12((char)(local_178[pbVar3[2]] * iVar43 * (uint)bVar24 >>
                                                  0x10),(undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              bVar24 = pbVar3[3];
                              if (bVar24 != 0) {
                                if (bVar24 == 0xff) {
                                  local_1ac._0_2_ =
                                       CONCAT11(*(undefined1 *)
                                                 (local_138 + (uint)local_188[pbVar3[1]]),
                                                *(undefined1 *)
                                                 (local_138 + (uint)local_180[*pbVar3]));
                                  local_1ac._0_3_ =
                                       CONCAT12(*(undefined1 *)
                                                 (local_138 + (uint)local_178[pbVar3[2]]),
                                                (undefined2)local_1ac);
                                }
                                else {
                                  iVar43 = (int)uVar36;
                                  local_1ac._0_2_ =
                                       CONCAT11((char)(local_188[pbVar3[1]] * iVar43 * (uint)bVar24
                                                      >> 0x10),
                                                (char)(local_180[*pbVar3] * iVar43 * (uint)bVar24 >>
                                                      0x10));
                                  local_1ac._0_3_ =
                                       CONCAT12((char)(local_178[pbVar3[2]] * iVar43 * (uint)bVar24
                                                      >> 0x10),(undefined2)local_1ac);
                                }
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              local_1ac._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_138 + (uint)local_188[pbVar3[1]]),
                                            *(undefined1 *)(local_138 + (uint)local_180[*pbVar3]));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_138 + (uint)local_178[pbVar3[2]]),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              if (*puVar4 != local_198) {
                                local_1ac._0_2_ =
                                     CONCAT11(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_188[*(byte *)((longlong)puVar4 + 1)]),
                                              *(undefined1 *)
                                               (local_138 + (uint)local_180[(byte)*puVar4]));
                                local_1ac._3_1_ = SUB41(uVar9,3);
                                local_1ac._0_3_ =
                                     CONCAT12(*(undefined1 *)
                                               (local_138 +
                                               (uint)local_178[*(byte *)((longlong)puVar4 + 2)]),
                                              (undefined2)local_1ac);
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              uVar26 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar26 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              iVar43 = (uint)(byte)(&DAT_140c28970)
                                                   [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                             (&DAT_140e398b0)[(int)uVar18 >> 0x12])]
                                       * (uint)pbVar3[3];
                              iVar16 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)((uint)pbVar3[1] * iVar43 * iVar16 >> 0x18),
                                            (char)((uint)*pbVar3 * iVar43 * iVar16 >> 0x18));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12((char)((uint)pbVar3[2] * iVar43 * iVar16 >> 0x18),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              uVar26 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar26 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              bVar24 = pbVar3[3];
                              if (bVar24 != 0) {
                                uVar18 = (uint)(byte)(&DAT_140c28970)
                                                     [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                               (&DAT_140e398b0)[(int)uVar18 >> 0x12]
                                                               )];
                                iVar43 = (int)uVar36;
                                if (bVar24 == 0xff) {
                                  local_1ac._0_2_ =
                                       CONCAT11((char)(pbVar3[1] * uVar18 * iVar43 >> 0x10),
                                                (char)(*pbVar3 * uVar18 * iVar43 >> 0x10));
                                  uVar12 = (undefined1)(pbVar3[2] * uVar18 * iVar43 >> 0x10);
                                }
                                else {
                                  iVar16 = uVar18 * bVar24;
                                  local_1ac._0_2_ =
                                       CONCAT11((char)((uint)pbVar3[1] * iVar16 * iVar43 >> 0x18),
                                                (char)((uint)*pbVar3 * iVar16 * iVar43 >> 0x18));
                                  uVar12 = (undefined1)((uint)pbVar3[2] * iVar16 * iVar43 >> 0x18);
                                }
                                local_1ac._3_1_ = SUB41(uVar9,3);
                                local_1ac._0_3_ = CONCAT12(uVar12,(undefined2)local_1ac);
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              uVar26 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar26 = uVar38 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                              iVar43 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)((uint)pbVar3[1] * (uint)bVar24 * iVar43 >> 0x10),
                                            (char)((uint)*pbVar3 * (uint)bVar24 * iVar43 >> 0x10));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12((char)((uint)pbVar3[2] * (uint)bVar24 * iVar43 >> 0x10),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            uVar9 = local_1ac;
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar18 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar18 = uVar44 + 0x3ffff;
                              }
                              uVar26 = uVar38;
                              if ((int)uVar38 < 0) {
                                uVar26 = uVar38 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                               (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                              if (*puVar4 != local_198) {
                                bVar24 = (&DAT_140c28970)
                                         [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                   (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                                iVar43 = (int)uVar36;
                                local_1ac._0_2_ =
                                     CONCAT11((char)((uint)*(byte *)((longlong)puVar4 + 1) *
                                                     (uint)bVar24 * iVar43 >> 0x10),
                                              (char)((uint)(byte)*puVar4 * (uint)bVar24 * iVar43 >>
                                                    0x10));
                                local_1ac._3_1_ = SUB41(uVar9,3);
                                local_1ac._0_3_ =
                                     CONCAT12((char)((uint)*(byte *)((longlong)puVar4 + 2) *
                                                     (uint)bVar24 * iVar43 >> 0x10),
                                              (undefined2)local_1ac);
                                uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                                uVar9 = uVar18 & 0x1010100;
                                *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                                uVar36 = (ulonglong)DAT_140c28a88;
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar26 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar26 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            bVar24 = pbVar3[3];
                            bVar1 = (&DAT_140c28970)
                                    [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[pbVar3[1]] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18),
                                          (char)(local_180[*pbVar3] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18));
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[pbVar3[2]] * (uint)bVar1 * iVar43 *
                                                 (uint)bVar24 >> 0x18),(undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar26 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar26 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            bVar24 = pbVar3[3];
                            if (bVar24 != 0) {
                              bVar1 = (&DAT_140c28970)
                                      [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                              iVar16 = (int)uVar36;
                              iVar43 = local_180[*pbVar3] * (uint)bVar1 * iVar16;
                              uVar18 = (uint)bVar1;
                              if (bVar24 == 0xff) {
                                uVar14 = (undefined1)((uint)iVar43 >> 0x10);
                                uVar13 = (undefined1)
                                         (local_188[pbVar3[1]] * uVar18 * iVar16 >> 0x10);
                                uVar12 = (undefined1)
                                         (local_178[pbVar3[2]] * uVar18 * iVar16 >> 0x10);
                              }
                              else {
                                uVar14 = (undefined1)(iVar43 * (uint)bVar24 >> 0x18);
                                uVar13 = (undefined1)
                                         (local_188[pbVar3[1]] * (uint)bVar1 * iVar16 * (uint)bVar24
                                         >> 0x18);
                                uVar12 = (undefined1)
                                         (local_178[pbVar3[2]] * uVar18 * iVar16 * (uint)bVar24 >>
                                         0x18);
                              }
                              local_1ac._0_2_ = CONCAT11(uVar13,uVar14);
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ = CONCAT12(uVar12,(undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar26 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar26 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            bVar24 = (&DAT_140c28970)
                                     [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                               (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                            iVar43 = (int)uVar36;
                            local_1ac._0_2_ =
                                 CONCAT11((char)(local_188[pbVar3[1]] * (uint)bVar24 * iVar43 >>
                                                0x10),
                                          (char)(local_180[*pbVar3] * (uint)bVar24 * iVar43 >> 0x10)
                                         );
                            local_1ac._3_1_ = SUB41(uVar9,3);
                            local_1ac._0_3_ =
                                 CONCAT12((char)(local_178[pbVar3[2]] * (uint)bVar24 * iVar43 >>
                                                0x10),(undefined2)local_1ac);
                            uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                            uVar9 = uVar18 & 0x1010100;
                            *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                            uVar36 = (ulonglong)DAT_140c28a88;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          uVar9 = local_1ac;
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar18 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar18 = uVar44 + 0x3ffff;
                            }
                            uVar26 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar26 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar26 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar18 >> 0x12]);
                            if (*puVar4 != local_198) {
                              bVar24 = (&DAT_140c28970)
                                       [*(byte *)((longlong)((int)uVar26 >> 0x12) +
                                                 (&DAT_140e398b0)[(int)uVar18 >> 0x12])];
                              iVar41 = (int)uVar36;
                              local_1ac._0_2_ =
                                   CONCAT11((char)(local_188[*(byte *)((longlong)puVar4 + 1)] *
                                                   (uint)bVar24 * iVar41 >> 0x10),
                                            (char)(local_180[(byte)*puVar4] * (uint)bVar24 * iVar41
                                                  >> 0x10));
                              local_1ac._3_1_ = SUB41(uVar9,3);
                              local_1ac._0_3_ =
                                   CONCAT12((char)(local_178[*(byte *)((longlong)puVar4 + 2)] *
                                                   (uint)bVar24 * iVar41 >> 0x10),
                                            (undefined2)local_1ac);
                              uVar18 = (*puVar23 | 0x1010100) - (local_1ac & 0xfefefeff);
                              uVar9 = uVar18 & 0x1010100;
                              *puVar23 = uVar9 - (uVar9 >> 8) & uVar18;
                              uVar36 = (ulonglong)DAT_140c28a88;
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                break;
              case 4:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)((uint)pbVar3[3] * (uint)*pbVar3 * (uint)(byte)*puVar23 >>
                                         0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)pbVar3[1] * (uint)pbVar3[3] *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((uint)pbVar3[2] * (uint)pbVar3[3] *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (pbVar3[3] == 0xff) {
                                *(byte *)puVar23 = (byte)((uint)*pbVar3 * (uint)(byte)*puVar23 >> 8)
                                ;
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((uint)pbVar3[1] * (uint)*(byte *)((longlong)puVar23 + 1)
                                           >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((uint)pbVar3[2] * (uint)*(byte *)((longlong)puVar23 + 2)
                                           >> 8);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)((uint)pbVar3[3] * (uint)*pbVar3 * (uint)(byte)*puVar23
                                           >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((uint)pbVar3[1] * (uint)pbVar3[3] *
                                            (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((uint)pbVar3[2] * (uint)pbVar3[3] *
                                            (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 = (byte)((uint)*pbVar3 * (uint)(byte)*puVar23 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)pbVar3[1] * (uint)*(byte *)((longlong)puVar23 + 1)
                                         >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((uint)pbVar3[2] * (uint)*(byte *)((longlong)puVar23 + 2)
                                         >> 8);
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                *(byte *)puVar23 =
                                     (byte)((uint)(byte)*puVar4 * (uint)(byte)*puVar23 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((uint)*(byte *)((longlong)puVar4 + 1) *
                                            (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((uint)*(byte *)((longlong)puVar4 + 2) *
                                            (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                              }
                            }
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(local_180[*pbVar3] * (uint)pbVar3[3] * (uint)(byte)*puVar23
                                       >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[pbVar3[1]] * (uint)pbVar3[3] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[pbVar3[2]] * (uint)pbVar3[3] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)(local_180[*pbVar3] * (uint)(byte)*puVar23 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(local_188[pbVar3[1]] *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(local_178[pbVar3[2]] *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)(local_180[*pbVar3] * (uint)pbVar3[3] *
                                          (uint)(byte)*puVar23 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(local_188[pbVar3[1]] * (uint)pbVar3[3] *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(local_178[pbVar3[2]] * (uint)pbVar3[3] *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(local_180[*pbVar3] * (uint)(byte)*puVar23 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[pbVar3[1]] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[pbVar3[2]] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(local_180[(byte)*puVar4] * (uint)(byte)*puVar23 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(local_188[*(byte *)((longlong)puVar4 + 1)] *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(local_178[*(byte *)((longlong)puVar4 + 2)] *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 8);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        (uint)*pbVar3 * (uint)(byte)*puVar23 >> 0x18);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[1] *
                                        (uint)pbVar3[3] * (uint)*(byte *)((longlong)puVar23 + 1) >>
                                       0x18);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[2] *
                                        (uint)pbVar3[3] * (uint)*(byte *)((longlong)puVar23 + 2) >>
                                       0x18);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)*pbVar3 *
                                          (uint)(byte)*puVar23 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[1] *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                              bVar24 = (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                              (uint)pbVar3[2] *
                                              (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                          (uint)*pbVar3 * (uint)(byte)*puVar23 >> 0x18);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[1] *
                                          (uint)pbVar3[3] * (uint)*(byte *)((longlong)puVar23 + 1)
                                         >> 0x18);
                              bVar24 = (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                              (uint)pbVar3[2] * (uint)pbVar3[3] *
                                              (uint)*(byte *)((longlong)puVar23 + 2) >> 0x18);
                            }
                            *(byte *)((longlong)puVar23 + 2) = bVar24;
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)*pbVar3 *
                                        (uint)(byte)*puVar23 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[1] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[2] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          (uint)(byte)*puVar4 * (uint)(byte)*puVar23 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          (uint)*(byte *)((longlong)puVar4 + 1) *
                                          (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          (uint)*(byte *)((longlong)puVar4 + 2) *
                                          (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                            }
                          }
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * local_180[*pbVar3] *
                                      (uint)pbVar3[3] * (uint)(byte)*puVar23 >> 0x18);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(local_188[pbVar3[1]] * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (uint)pbVar3[3] * (uint)*(byte *)((longlong)puVar23 + 1) >>
                                     0x18);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(local_178[pbVar3[2]] * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (uint)pbVar3[3] * (uint)*(byte *)((longlong)puVar23 + 2) >>
                                     0x18);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          if (pbVar3[3] == 0xff) {
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * local_180[*pbVar3]
                                        * (uint)(byte)*puVar23 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[pbVar3[1]] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[pbVar3[2]] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                          }
                          else {
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * local_180[*pbVar3]
                                        * (uint)pbVar3[3] * (uint)(byte)*puVar23 >> 0x18);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[pbVar3[1]] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x18);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[pbVar3[2]] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x18);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] * local_180[*pbVar3] *
                                      (uint)(byte)*puVar23 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(local_188[pbVar3[1]] * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(local_178[pbVar3[2]] * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          if (*puVar4 != local_198) {
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                        local_180[(byte)*puVar4] * (uint)(byte)*puVar23 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(local_188[*(byte *)((longlong)puVar4 + 1)] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                        (uint)*(byte *)((longlong)puVar23 + 1) >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(local_178[*(byte *)((longlong)puVar4 + 2)] *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                        (uint)*(byte *)((longlong)puVar23 + 2) >> 0x10);
                          }
                        }
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 10:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)(((uint)(byte)~*pbVar3 - (uint)(byte)*puVar23) *
                                          (uint)pbVar3[3] * (int)uVar36 +
                                          (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~pbVar3[1] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)(byte)~pbVar3[2] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = (byte)*puVar23;
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (pbVar3[3] == 0xff) {
                                *(byte *)puVar23 =
                                     (byte)(((uint)(byte)~*pbVar3 - (uint)bVar24) * (int)uVar36 +
                                            (uint)bVar24 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)(byte)~pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)(byte)~pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)(((uint)(byte)~*pbVar3 - (uint)bVar24) * (uint)pbVar3[3]
                                            * (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)(byte)~pbVar3[1] -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) *
                                            (uint)pbVar3[3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10
                                           );
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)(byte)~pbVar3[2] -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) *
                                            (uint)pbVar3[3] * DAT_140c28a88 +
                                            (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10
                                           );
                              }
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)(((uint)(byte)~*pbVar3 - (uint)(byte)*puVar23) *
                                          (int)uVar36 + (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~pbVar3[1] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)(byte)~pbVar3[2] -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                *(byte *)puVar23 =
                                     (byte)(((uint)(byte)~(byte)*puVar4 - (uint)(byte)*puVar23) *
                                            (int)uVar36 + (uint)(byte)*puVar23 * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)(((uint)(byte)~*(byte *)((longlong)puVar4 + 1) -
                                            (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)(((uint)(byte)~*(byte *)((longlong)puVar4 + 2) -
                                            (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88
                                            + (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                              }
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                        (uint)(byte)*puVar23) * (uint)pbVar3[3] * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                          (uint)bVar24) * (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                          (uint)bVar24) * (uint)pbVar3[3] * (int)uVar36 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * (uint)pbVar3[3]
                                          * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                        (uint)(byte)*puVar23) * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)(((uint)*(byte *)(local_180 + (byte)~(byte)*puVar4) -
                                          (uint)(byte)*puVar23) * (int)uVar36 +
                                          (uint)(byte)*puVar23 * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)*(byte *)(local_188 +
                                                          (byte)~*(byte *)((longlong)puVar4 + 1)) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x100 >> 8);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)*(byte *)(local_178 +
                                                          (byte)~*(byte *)((longlong)puVar4 + 2)) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    local_1b8 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        ((uint)(byte)~*pbVar3 - (uint)(byte)*puVar23) *
                                        (uint)pbVar3[3] * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x1000000 >> 0x18);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)(byte)~pbVar3[1] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)(byte)~pbVar3[2] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          ((uint)(byte)~*pbVar3 - (uint)bVar24) * (int)uVar36 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~pbVar3[1] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              bVar24 = (byte)(((uint)(byte)~pbVar3[2] -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88
                                              + (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >>
                                             0x10);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          ((uint)(byte)~*pbVar3 - (uint)bVar24) * (uint)pbVar3[3] *
                                          (int)uVar36 + (uint)bVar24 * 0x1000000 >> 0x18);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~pbVar3[1] -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                          DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18
                                         );
                              bVar24 = (byte)(((uint)(byte)~pbVar3[2] -
                                              (uint)*(byte *)((longlong)puVar23 + 2)) *
                                              (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                              (uint)pbVar3[3] * DAT_140c28a88 +
                                              (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >>
                                             0x18);
                            }
                            *(byte *)((longlong)puVar23 + 2) = bVar24;
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          local_1b8 = local_1b8 + -1;
                        } while (local_1b8 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        local_1b8 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)((uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        ((uint)(byte)~*pbVar3 - (uint)(byte)*puVar23) * (int)uVar36
                                        + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)(byte)~pbVar3[1] -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)(byte)~pbVar3[2] -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              *(byte *)puVar23 =
                                   (byte)((uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                          ((uint)(byte)~(byte)*puVar4 - (uint)(byte)*puVar23) *
                                          (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((uint)(byte)~*(byte *)((longlong)puVar4 + 1) -
                                          (uint)*(byte *)((longlong)puVar23 + 1)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((uint)(byte)~*(byte *)((longlong)puVar4 + 2) -
                                          (uint)*(byte *)((longlong)puVar23 + 2)) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                      (uint)(byte)*puVar23) * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (uint)pbVar3[3] * (int)uVar36 +
                                      (uint)(byte)*puVar23 * 0x1000000 >> 0x18);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                      DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18);
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          bVar24 = (byte)*puVar23;
                          if (pbVar3[3] == 0xff) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) - (uint)bVar24)
                                        * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (int)uVar36 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                          else {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) - (uint)bVar24)
                                        * (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        (int)uVar36 + (uint)bVar24 * 0x1000000 >> 0x18);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x1000000 >> 0x18);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x1000000 >> 0x18);
                            iVar30 = local_170;
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((uint)*(byte *)(local_180 + (byte)~*pbVar3) -
                                      (uint)(byte)*puVar23) * (uint)(byte)(&DAT_140c28970)[*pbVar29]
                                      * (int)uVar36 + (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((uint)*(byte *)(local_188 + (byte)~pbVar3[1]) -
                                      (uint)*(byte *)((longlong)puVar23 + 1)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((uint)*(byte *)(local_178 + (byte)~pbVar3[2]) -
                                      (uint)*(byte *)((longlong)puVar23 + 2)) *
                                      (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                      (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          if (*puVar4 != local_198) {
                            *(byte *)puVar23 =
                                 (byte)(((uint)*(byte *)(local_180 + (byte)~(byte)*puVar4) -
                                        (uint)(byte)*puVar23) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] * (int)uVar36 +
                                        (uint)(byte)*puVar23 * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((uint)*(byte *)(local_188 +
                                                        (byte)~*(byte *)((longlong)puVar4 + 1)) -
                                        (uint)*(byte *)((longlong)puVar23 + 1)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 1) * 0x10000 >> 0x10);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((uint)*(byte *)(local_178 +
                                                        (byte)~*(byte *)((longlong)puVar4 + 2)) -
                                        (uint)*(byte *)((longlong)puVar23 + 2)) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                        (uint)*(byte *)((longlong)puVar23 + 2) * 0x10000 >> 0x10);
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                break;
              case 0xb:
                if (local_148 == 0) {
                  if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                    if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = (byte)*puVar23;
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)((((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (uint)pbVar3[3] * (int)uVar36 + (uint)bVar24 * 0x10000 >>
                                         0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x10000
                                         >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x10000
                                         >> 0x10);
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = (byte)*puVar23;
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              iVar43 = ((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24;
                              if (pbVar3[3] == 0xff) {
                                *(byte *)puVar23 =
                                     (byte)(iVar43 * (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                                bVar24 = *(byte *)((longlong)puVar23 + 1);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                            DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                                bVar24 = *(byte *)((longlong)puVar23 + 2);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                            DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                              }
                              else {
                                *(byte *)puVar23 =
                                     (byte)(iVar43 * (uint)pbVar3[3] * (int)uVar36 +
                                            (uint)bVar24 * 0x10000 >> 0x10);
                                bVar24 = *(byte *)((longlong)puVar23 + 1);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                            (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x10000
                                           >> 0x10);
                                bVar24 = *(byte *)((longlong)puVar23 + 2);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                            (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x10000
                                           >> 0x10);
                              }
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                    else {
                      iVar41 = local_110;
                      if (local_1ac == 0) {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              bVar24 = (byte)*puVar23;
                              pbVar3 = (byte *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              *(byte *)puVar23 =
                                   (byte)((((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                      else {
                        do {
                          do {
                            if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                              uVar9 = uVar44;
                              if ((int)uVar44 < 0) {
                                uVar9 = uVar44 + 0x3ffff;
                              }
                              puVar4 = (uint *)((longlong)
                                                (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU))
                                                 >> 0x12) << 2) +
                                               (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                              if (*puVar4 != local_198) {
                                bVar24 = (byte)*puVar23;
                                *(byte *)puVar23 =
                                     (byte)((((uint)(byte)*puVar4 * (uint)bVar24 >> 8) -
                                            (uint)bVar24) * (int)uVar36 + (uint)bVar24 * 0x100 >> 8)
                                ;
                                bVar24 = *(byte *)((longlong)puVar23 + 1);
                                *(byte *)((longlong)puVar23 + 1) =
                                     (byte)((((uint)*(byte *)((longlong)puVar4 + 1) * (uint)bVar24
                                             >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                            (uint)bVar24 * 0x100 >> 8);
                                bVar24 = *(byte *)((longlong)puVar23 + 2);
                                *(byte *)((longlong)puVar23 + 2) =
                                     (byte)((((uint)*(byte *)((longlong)puVar4 + 2) * (uint)bVar24
                                             >> 8) - (uint)bVar24) * DAT_140c28a88 +
                                            (uint)bVar24 * 0x100 >> 8);
                              }
                            }
                            uVar36 = (ulonglong)DAT_140c28a88;
                            uVar38 = uVar38 + iVar34;
                            uVar44 = uVar44 + iVar30;
                            puVar23 = puVar23 + 1;
                            iVar41 = iVar41 + -1;
                          } while (iVar41 != 0);
                          uVar38 = uVar38 + local_1a4;
                          puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                          uVar44 = uVar44 + local_1a8;
                          local_10c = local_10c + -1;
                          iVar41 = local_110;
                        } while (local_10c != 0);
                      }
                    }
                  }
                  else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)pbVar3[3] * (int)uVar36 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)pbVar3[3] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)pbVar3[3] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (pbVar3[3] == 0xff) {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8)
                              ;
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8)
                              ;
                            }
                            else {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * (uint)pbVar3[3] * (int)uVar36 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * (uint)pbVar3[3] * DAT_140c28a88 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * (uint)pbVar3[3] * DAT_140c28a88 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            bVar24 = (byte)*puVar23;
                            pbVar3 = (byte *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            *(byte *)puVar23 =
                                 (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)
                                              (((int)(uVar38 + ((int)uVar38 >> 0x1f & 0x3ffffU)) >>
                                               0x12) << 2) + (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)(((local_180[(byte)*puVar4] * (uint)bVar24 >> 8 & 0xff) -
                                          (uint)bVar24) * (int)uVar36 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)(((local_188[*(byte *)((longlong)puVar4 + 1)] *
                                            (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)(((local_178[*(byte *)((longlong)puVar4 + 2)] *
                                            (uint)bVar24 >> 8 & 0xff) - (uint)bVar24) *
                                          DAT_140c28a88 + (uint)bVar24 * 0x100 >> 8);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
                  if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)*puVar23;
                            *(byte *)puVar23 =
                                 (byte)((((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        (int)uVar36 + (uint)bVar24 * 0x1000000 >> 0x18);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x1000000 >> 0x18);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x1000000 >> 0x18);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)*puVar23;
                            iVar43 = ((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24;
                            if (pbVar3[3] == 0xff) {
                              *(byte *)puVar23 =
                                   (byte)(iVar43 * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              bVar24 = (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24)
                                              * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                              DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                            }
                            else {
                              *(byte *)puVar23 =
                                   (byte)(iVar43 * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                          (uint)pbVar3[3] * (int)uVar36 + (uint)bVar24 * 0x1000000
                                         >> 0x18);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar29] * (uint)pbVar3[3] *
                                          DAT_140c28a88 + (uint)bVar24 * 0x1000000 >> 0x18);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              bVar24 = (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24)
                                              * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                              (uint)pbVar3[3] * DAT_140c28a88 +
                                              (uint)bVar24 * 0x1000000 >> 0x18);
                              iVar30 = local_170;
                            }
                            *(byte *)((longlong)puVar23 + 2) = bVar24;
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                  else {
                    iVar41 = local_110;
                    if (local_1ac == 0) {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                              (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            bVar24 = (byte)*puVar23;
                            *(byte *)puVar23 =
                                 (byte)((((uint)*pbVar3 * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * (int)uVar36 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)((((uint)pbVar3[1] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)((((uint)pbVar3[2] * (uint)bVar24 >> 8) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar29] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                    else {
                      do {
                        do {
                          if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                            uVar9 = uVar44;
                            if ((int)uVar44 < 0) {
                              uVar9 = uVar44 + 0x3ffff;
                            }
                            uVar18 = uVar38;
                            if ((int)uVar38 < 0) {
                              uVar18 = uVar38 + 0x3ffff;
                            }
                            puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                             (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                            pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                             (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                            if (*puVar4 != local_198) {
                              bVar24 = (byte)*puVar23;
                              *(byte *)puVar23 =
                                   (byte)((((uint)(byte)*puVar4 * (uint)bVar24 >> 8) - (uint)bVar24)
                                          * (uint)(byte)(&DAT_140c28970)[*pbVar3] * (int)uVar36 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 1);
                              *(byte *)((longlong)puVar23 + 1) =
                                   (byte)((((uint)*(byte *)((longlong)puVar4 + 1) * (uint)bVar24 >>
                                           8) - (uint)bVar24) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                              bVar24 = *(byte *)((longlong)puVar23 + 2);
                              *(byte *)((longlong)puVar23 + 2) =
                                   (byte)((((uint)*(byte *)((longlong)puVar4 + 2) * (uint)bVar24 >>
                                           8) - (uint)bVar24) *
                                          (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                          (uint)bVar24 * 0x10000 >> 0x10);
                            }
                          }
                          uVar36 = (ulonglong)DAT_140c28a88;
                          uVar38 = uVar38 + iVar34;
                          uVar44 = uVar44 + iVar30;
                          puVar23 = puVar23 + 1;
                          iVar41 = iVar41 + -1;
                        } while (iVar41 != 0);
                        uVar38 = uVar38 + local_1a4;
                        puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                        uVar44 = uVar44 + local_1a8;
                        local_10c = local_10c + -1;
                        iVar41 = local_110;
                      } while (local_10c != 0);
                    }
                  }
                }
                else if (*(int *)(*(longlong *)(local_168 + 0x20) + 0x34) == 1) {
                  iVar41 = local_110;
                  local_1b8 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = (byte)*puVar23;
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      (uint)pbVar3[3] * (int)uVar36 + (uint)bVar24 * 0x1000000 >>
                                     0x18);
                          bVar24 = *(byte *)((longlong)puVar23 + 1);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x1000000 >>
                                     0x18);
                          bVar24 = *(byte *)((longlong)puVar23 + 2);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x1000000 >>
                                     0x18);
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = (byte)*puVar23;
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          iVar41 = (local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) - (uint)bVar24;
                          if (pbVar3[3] == 0xff) {
                            *(byte *)puVar23 =
                                 (byte)(iVar41 * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          }
                          else {
                            *(byte *)puVar23 =
                                 (byte)(iVar41 * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (uint)pbVar3[3] * (int)uVar36 + (uint)bVar24 * 0x1000000 >>
                                       0x18);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x1000000
                                       >> 0x18);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                        (uint)pbVar3[3] * DAT_140c28a88 + (uint)bVar24 * 0x1000000
                                       >> 0x18);
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        local_1b8 = local_1b8 + -1;
                      } while (local_1b8 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      local_1b8 = local_110;
                    } while (local_10c != 0);
                  }
                }
                else {
                  iVar41 = local_110;
                  if (local_1ac == 0) {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          bVar24 = (byte)*puVar23;
                          pbVar3 = (byte *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar29 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                            (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          *(byte *)puVar23 =
                               (byte)(((local_180[*pbVar3] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 1);
                          *(byte *)((longlong)puVar23 + 1) =
                               (byte)(((local_188[pbVar3[1]] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                          bVar24 = *(byte *)((longlong)puVar23 + 2);
                          *(byte *)((longlong)puVar23 + 2) =
                               (byte)(((local_178[pbVar3[2]] * (uint)bVar24 >> 8 & 0xff) -
                                      (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar29] *
                                      DAT_140c28a88 + (uint)bVar24 * 0x10000 >> 0x10);
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                  else {
                    do {
                      do {
                        if ((uVar38 < uVar40) && (uVar44 < uVar17)) {
                          uVar9 = uVar44;
                          if ((int)uVar44 < 0) {
                            uVar9 = uVar44 + 0x3ffff;
                          }
                          uVar18 = uVar38;
                          if ((int)uVar38 < 0) {
                            uVar18 = uVar38 + 0x3ffff;
                          }
                          puVar4 = (uint *)((longlong)(((int)uVar18 >> 0x12) * 4) +
                                           (&DAT_140e318b0)[(int)uVar9 >> 0x12]);
                          pbVar3 = (byte *)((longlong)((int)uVar18 >> 0x12) +
                                           (&DAT_140e398b0)[(int)uVar9 >> 0x12]);
                          if (*puVar4 != local_198) {
                            bVar24 = (byte)*puVar23;
                            *(byte *)puVar23 =
                                 (byte)(((local_180[(byte)*puVar4] * (uint)bVar24 >> 8 & 0xff) -
                                        (uint)bVar24) * (uint)(byte)(&DAT_140c28970)[*pbVar3] *
                                        (int)uVar36 + (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 1);
                            *(byte *)((longlong)puVar23 + 1) =
                                 (byte)(((local_188[*(byte *)((longlong)puVar4 + 1)] * (uint)bVar24
                                          >> 8 & 0xff) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                            bVar24 = *(byte *)((longlong)puVar23 + 2);
                            *(byte *)((longlong)puVar23 + 2) =
                                 (byte)(((local_178[*(byte *)((longlong)puVar4 + 2)] * (uint)bVar24
                                          >> 8 & 0xff) - (uint)bVar24) *
                                        (uint)(byte)(&DAT_140c28970)[*pbVar3] * DAT_140c28a88 +
                                        (uint)bVar24 * 0x10000 >> 0x10);
                          }
                        }
                        uVar36 = (ulonglong)DAT_140c28a88;
                        uVar38 = uVar38 + iVar34;
                        uVar44 = uVar44 + iVar30;
                        puVar23 = puVar23 + 1;
                        iVar41 = iVar41 + -1;
                      } while (iVar41 != 0);
                      uVar38 = uVar38 + local_1a4;
                      puVar23 = (uint *)((longlong)puVar23 + (ulonglong)uVar8);
                      uVar44 = uVar44 + local_1a8;
                      local_10c = local_10c + -1;
                      iVar41 = local_110;
                    } while (local_10c != 0);
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      local_1c8 = param_11;
      local_c0 = (int)(iVar41 + (uVar44 & 0x3ffff)) >> 0x12;
      local_bc = (int)(iVar43 + (uVar9 & 0x3ffff)) >> 0x12;
      local_b8 = (int)(local_120 + (uVar38 & 0x3ffff)) >> 0x12;
      local_b4 = (int)(local_150 + (uVar32 & 0x3ffff)) >> 0x12;
      local_b0 = (int)(iVar30 + (uVar17 & 0x3ffff)) >> 0x12;
      local_ac = (int)(iVar34 + (uVar40 & 0x3ffff)) >> 0x12;
      local_a8 = (int)(local_11c + (uVar18 & 0x3ffff)) >> 0x12;
      local_a4 = (int)(local_14c + (uVar26 & 0x3ffff)) >> 0x12;
      FUN_140478f80(local_140,param_2,&local_c0,uVar8);
    }
  }
  else if (param_10 == 0) {
    local_1c8 = param_11;
    local_e0 = (int)(local_11c + (uVar18 & 0x3ffff)) >> 0x12;
    local_dc = (int)(local_14c + (uVar26 & 0x3ffff)) >> 0x12;
    local_d8 = (int)(iVar30 + (uVar17 & 0x3ffff)) >> 0x12;
    local_d4 = (int)(iVar34 + (uVar40 & 0x3ffff)) >> 0x12;
    local_d0 = (int)(local_120 + (uVar38 & 0x3ffff)) >> 0x12;
    local_cc = (int)(local_150 + (uVar32 & 0x3ffff)) >> 0x12;
    local_c8 = (int)(iVar41 + (uVar44 & 0x3ffff)) >> 0x12;
    local_c4 = (int)(iVar43 + (uVar9 & 0x3ffff)) >> 0x12;
    FUN_140478f80(local_140,param_2,&local_e0,uVar8);
  }
  else {
    local_1c8 = param_11;
    local_100 = (int)(local_120 + (uVar38 & 0x3ffff)) >> 0x12;
    local_fc = (int)(local_150 + (uVar32 & 0x3ffff)) >> 0x12;
    local_f8 = (int)(iVar41 + (uVar44 & 0x3ffff)) >> 0x12;
    local_f4 = (int)(iVar43 + (uVar9 & 0x3ffff)) >> 0x12;
    local_f0 = (int)(local_11c + (uVar18 & 0x3ffff)) >> 0x12;
    local_ec = (int)(local_14c + (uVar26 & 0x3ffff)) >> 0x12;
    local_e8 = (int)(iVar30 + (uVar17 & 0x3ffff)) >> 0x12;
    local_e4 = (int)(iVar34 + (uVar40 & 0x3ffff)) >> 0x12;
    FUN_140478f80(local_140,param_2,&local_100,uVar8);
  }
  return;
}


