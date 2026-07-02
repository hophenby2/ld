// Function: FUN_140349890 @ 140349890
// Decompile completed: true

void FUN_140349890(longlong param_1,longlong param_2,int *param_3,int param_4,longlong param_5)

{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  longlong lVar17;
  uint *puVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  ulonglong uVar22;
  ushort uVar23;
  ushort uVar24;
  uint uVar25;
  int iVar26;
  ulonglong uVar27;
  int iVar28;
  uint uVar29;
  longlong lVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  byte *pbVar34;
  undefined8 local_res10;
  int local_res18;
  int local_e8;
  uint *local_e0;
  int local_cc;
  int local_c8;
  int local_c4;
  byte *local_c0;
  ulonglong local_b0;
  ulonglong local_90;
  undefined8 local_68;
  int iStack_60;
  int iStack_5c;
  uint *local_58;
  ulonglong local_50;
  
  lVar5 = *(longlong *)(param_2 + 0x20);
  local_90 = 0;
  local_c0 = (byte *)0x0;
  iVar9 = *param_3;
  iVar21 = 0;
  if (*(int *)(lVar5 + 0x20) != 0) {
    iVar21 = param_4;
  }
  iVar19 = param_3[2];
  if (iVar19 < iVar9) {
    lVar17 = -1;
    iStack_60 = iVar9;
    iVar9 = iVar19;
  }
  else {
    lVar17 = 1;
    iStack_60 = iVar19;
  }
  iVar19 = param_3[3];
  iVar10 = param_3[1];
  if (iVar19 < iVar10) {
    lVar30 = -1;
    iStack_5c = iVar10;
    iVar10 = iVar19;
  }
  else {
    lVar30 = 1;
    iStack_5c = iVar19;
  }
  iVar19 = iStack_5c - iVar10;
  uVar6 = iStack_60 - iVar9;
  if (uVar6 == 0) {
    return;
  }
  if (iVar19 == 0) {
    return;
  }
  uVar20 = *(uint *)(param_2 + 4);
  local_68._0_4_ = iVar9;
  local_68._4_4_ = iVar10;
  if ((((uVar6 == uVar20) && (iVar19 == *(int *)(param_2 + 8))) && (lVar17 == 1)) && (lVar30 == 1))
  {
    FUN_14036baf0(param_1,param_2,iVar9,iVar10,iVar21,param_5);
    return;
  }
  uVar7 = (uVar6 * 0x10000) / uVar20;
  uVar6 = *(uint *)(param_2 + 8);
  uVar8 = (uint)(iVar19 * 0x10000) / uVar6;
  FUN_14016c6a0(&local_68,&DAT_140c28a74);
  iVar19 = iStack_60 - (int)local_68;
  local_e8 = iStack_5c - local_68._4_4_;
  iVar9 = ((int)local_68 - iVar9) * 0x10000;
  uVar25 = iVar9 / (int)uVar7;
  iVar10 = (local_68._4_4_ - iVar10) * 0x10000;
  iVar28 = iVar10 / (int)uVar8;
  iVar11 = uVar7 - iVar9 % (int)uVar7;
  iVar9 = uVar8 - iVar10 % (int)uVar8;
  if (iVar19 == 0) {
    return;
  }
  if (local_e8 == 0) {
    return;
  }
  if (lVar17 == 1) {
    bVar3 = *(byte *)(*(longlong *)(lVar5 + 0x18) + 4);
    uVar32 = (ulonglong)bVar3;
    uVar12 = bVar3 * uVar25;
  }
  else {
    uVar12 = (uint)*(byte *)(*(longlong *)(lVar5 + 0x18) + 4);
    uVar32 = ~(ulonglong)uVar12 + 1;
    uVar12 = ((uVar20 - uVar25) + -1) * uVar12;
  }
  if (lVar30 == 1) {
    local_b0 = (ulonglong)*(uint *)(lVar5 + 0xc);
    uVar15 = *(uint *)(lVar5 + 0xc) * iVar28;
  }
  else {
    uVar15 = ((uVar6 - iVar28) + -1) * *(uint *)(lVar5 + 0xc);
    local_b0 = ~(ulonglong)*(uint *)(lVar5 + 0xc) + 1;
  }
  puVar16 = (uint *)((ulonglong)uVar15 + (ulonglong)uVar12 + *(longlong *)(param_2 + 0x10));
  if (param_5 != 0) {
    if (lVar17 == 1) {
      lVar17 = 1;
    }
    else {
      lVar17 = -1;
      uVar25 = (uVar20 - uVar25) - 1;
    }
    if (lVar30 == 1) {
      uVar6 = *(uint *)(*(longlong *)(param_5 + 0x20) + 0xc);
      local_90 = (ulonglong)uVar6;
      uVar6 = uVar6 * iVar28;
    }
    else {
      uVar20 = *(uint *)(*(longlong *)(param_5 + 0x20) + 0xc);
      uVar6 = ((uVar6 - iVar28) + -1) * uVar20;
      local_90 = ~(ulonglong)uVar20 + 1;
    }
    local_c0 = (byte *)((ulonglong)uVar6 + *(longlong *)(param_5 + 0x10) + (ulonglong)uVar25);
  }
  uVar6 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0xc);
  uVar22 = (ulonglong)uVar6;
  puVar18 = (uint *)((ulonglong)
                     ((uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18) + 4) *
                     (int)local_68) + (ulonglong)(uVar6 * local_68._4_4_) +
                    *(longlong *)(param_1 + 0x10));
  local_58 = puVar18;
  local_50 = uVar32;
  if (*(int *)(lVar5 + 0x2c) == 1) {
    iVar10 = 4;
    if (*(int *)(lVar5 + 0x28) == 0) {
      iVar10 = 2;
    }
    FUN_1401ae2f0(&DAT_140e310b0,*(undefined8 *)(lVar5 + 0x48),
                  (longlong)(iVar10 * *(int *)(lVar5 + 0x30)));
  }
  uVar33 = (ulonglong)(int)DAT_140c28a88;
  uVar12 = DAT_140c28a8c >> 0x10 & 0xff;
  uVar25 = DAT_140c28a8c >> 8 & 0xff;
  uVar6 = *(uint *)(*(longlong *)(param_2 + 0x20) + 0x24);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x48);
  uVar20 = DAT_140c28a8c & 0xff;
  iVar10 = *(int *)(*(longlong *)(param_2 + 0x20) + 0x28);
  local_res18 = iVar9;
  local_c8 = iVar11;
  local_cc = iVar11;
  local_e0 = (uint *)local_c0;
  local_c4 = iVar19;
  if (iVar10 == 0) {
    lVar30 = *(longlong *)(param_2 + 0x20);
    if (*(int *)(lVar30 + 0x2c) == 1) {
      switch(DAT_140c28a84) {
      case 1:
        if (DAT_140c28a88 != 0xff) {
          if (DAT_140c28a88 == 0) {
            return;
          }
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
              iVar28 = iVar19;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 == 0) {
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar18;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                    local_c4 = local_c4 + -1;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar25 * 0x100 +
                                           (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f))
                                    * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                         (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                         (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                        (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                    if (local_c4 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                        iVar10 = iVar10 + uVar7) {
                      puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar14 + uVar22);
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  local_c4 = iVar19;
                  iVar10 = iVar11;
                  puVar14 = puVar18;
                  puVar13 = puVar16;
                } while (local_e8 != 0);
                return;
              }
LAB_14035a1e0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035a320;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar25 * 0x100 +
                                           (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f))
                                    * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                         (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                         (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                        (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035a320;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 == 0) {
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4 +
                                  uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * 4
                                  + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                       *(short *)(&DAT_140ba8d70 +
                                 (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                 uVar33 * 0x800) + (uVar23 & 0x1f);
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
              return;
            }
LAB_140359f00:
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar28 = iVar28 + -1;
                  if (iVar28 == 0) goto LAB_14035a020;
                  local_cc = local_cc + -0x10000;
                  iVar9 = iVar28;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar18;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                  *(ushort *)puVar18 =
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4 +
                                  uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * 4
                                  + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                       *(short *)(&DAT_140ba8d70 +
                                 (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                 uVar33 * 0x800) + (uVar23 & 0x1f);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar28 = iVar9 + -1;
                  if (iVar28 == 0) goto LAB_14035a020;
                  local_cc = local_cc + -0x10000;
                  iVar9 = iVar28;
                } while (0 < local_cc);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
            if (iVar21 == 0) {
              while( true ) {
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar14 = puVar16;
                while( true ) {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10) &
                       0x1f;
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                }
                puVar18 = (uint *)((longlong)puVar18 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
              }
              return;
            }
LAB_140359b20:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140359c9e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar15 = (uint)uVar23;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 + uVar15 * 0x10000 >> 0x10)
                       & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140359c9e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          if (iVar21 == 0) {
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar16;
              while( true ) {
                uVar6 = (uint)(ushort)*puVar13;
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar13 =
                     (ushort)(((uVar23 & 0x7e0) - ((ushort)*puVar13 & 0x7e0)) * (uint)bVar3 * iVar21
                              + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                     (ushort)(((uVar23 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                     (ushort)(((uVar23 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0x1f) * 0x10000 >> 0x10);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
            return;
          }
LAB_1403597a0:
          local_e0 = (uint *)local_c0;
          puVar13 = puVar18;
          puVar14 = puVar16;
          iVar9 = iVar19;
          local_c8 = iVar11;
          do {
            if ((byte)*puVar14 == uVar6) {
              do {
                puVar13 = (uint *)((longlong)puVar13 + 2);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) goto LAB_1403598fe;
                local_c8 = local_c8 + -0x10000;
              } while (0 < local_c8);
            }
            else {
              do {
                uVar20 = (uint)(ushort)*puVar13;
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                *(ushort *)puVar13 =
                     (ushort)(((uVar23 & 0x7e0) - ((ushort)*puVar13 & 0x7e0)) * (uint)bVar3 * iVar21
                              + (uVar20 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                     (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 * iVar21 +
                              (uVar20 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                     (ushort)(((uVar23 & 0x1f) - (uVar20 & 0x1f)) * (uint)bVar3 * iVar21 +
                              (uVar20 & 0x1f) * 0x10000 >> 0x10);
                puVar13 = (uint *)((longlong)puVar13 + 2);
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) goto LAB_1403598fe;
                local_c8 = local_c8 + -0x10000;
              } while (0 < local_c8);
            }
            do {
              puVar14 = (uint *)((longlong)puVar14 + uVar32);
              local_e0 = (uint *)((longlong)local_e0 + lVar17);
              local_c8 = local_c8 + uVar7;
            } while (local_c8 < 1);
          } while( true );
        }
      case 0:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14035ac10:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035ac7d;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(ushort *)puVar18 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035ac7d;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                *(ushort *)puVar18 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14035ad80:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035ae2f;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(ushort *)
                           (&DAT_140b68970 +
                           (ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)) |
                         *(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) << 6) <<
                         5 | *(ushort *)
                              (&DAT_140b68970 +
                              (ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035ae2f;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                *(ushort *)puVar18 =
                     (*(ushort *)
                       (&DAT_140b68970 + (ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)
                       ) | *(short *)(&DAT_140b68970 +
                                     (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) << 6)
                     << 5 | *(ushort *)
                             (&DAT_140b68970 +
                             (ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (iVar21 != 0) {
LAB_14035a510:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035a64f;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar20 = (uint)uVar23 << 8;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar13 =
                       (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 +
                                (uVar20 & 0xfff80000) >> 8) & 0xf800 |
                       (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 +
                                (uVar20 & 0xffffe000) >> 8) & 0x7e0 |
                       (ushort)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar3 +
                                (uVar20 & 0x1f00) >> 8);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035a64f;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar6 = (uint)uVar23 << 8;
              uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 +
                            (uVar6 & 0xfff80000) >> 8) & 0xf800 |
                   (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 +
                            (uVar6 & 0xffffe000) >> 8) & 0x7e0 |
                   (ushort)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar3 + (uVar6 & 0x1f00) >>
                           8);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        else {
          if (iVar21 != 0) {
LAB_14035a860:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar13 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035a9ce;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar18;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar18 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3
                               ) & 0x7e0 |
                       ((*(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                        (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035a9ce;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar13 = (uint *)((longlong)puVar13 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3) &
                   0x7e0 | ((*(short *)(&DAT_140b68970 +
                                       (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                            (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800
                   | (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        break;
      case 2:
        if (DAT_140c28a88 != 0) {
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_14035b6d1:
                do {
                  if ((byte)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_14035b7c2;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                      uVar23 = (*(short *)(&DAT_140b68970 +
                                          uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) * 0x40 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                      uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                      uVar25 = uVar20 & 0x8210820;
                      *(ushort *)puVar18 =
                           (short)uVar25 - (short)(uVar25 >> 5) |
                           ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar20;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_14035b7c2;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  uVar23 = (*(short *)(&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb))
                            * 0x40 + *(short *)(&DAT_140b68970 +
                                               uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) *
                           0x20 + *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                  uVar6 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar20 = uVar6 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (short)uVar20 - (short)(uVar20 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                       (ushort)uVar6;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_14035b953:
                do {
                  if ((byte)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_14035ba60;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                      uVar23 = (*(short *)(&DAT_140b68970 +
                                          uVar33 * 0x100 +
                                          (ulonglong)
                                          (uint)(&DAT_140b68970)
                                                [(ulonglong)uVar25 * 0x100 +
                                                 (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 +
                                         (ulonglong)
                                         (uint)(&DAT_140b68970)
                                               [(ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 +
                                         (ulonglong)
                                         (uint)(&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar23 & 0x1f)]);
                      uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                      uVar29 = uVar15 & 0x8210820;
                      *(ushort *)puVar18 =
                           (short)uVar29 - (short)(uVar29 >> 5) |
                           ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar15;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_14035ba60;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  uVar23 = (*(short *)(&DAT_140b68970 +
                                      uVar33 * 0x100 +
                                      (ulonglong)
                                      (uint)(&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)])
                           * 0x40) * 0x20 +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)])
                  ;
                  uVar6 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar15 = uVar6 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (short)uVar15 - (short)(uVar15 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                       (ushort)uVar6;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035afa0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035b0ed;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                    uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar25 = uVar20 & 0x8210820;
                    *(ushort *)puVar18 =
                         (short)uVar25 - (short)(uVar25 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820
                         | (ushort)uVar20;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035b0ed;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                uVar23 = (*(short *)(&DAT_140b68970 +
                                    uVar33 * 0x100 + (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)
                                    ) * 0x40 +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 + (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)))
                         * 0x20 + *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                uVar6 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                uVar20 = uVar6 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (short)uVar20 - (short)(uVar20 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                     (ushort)uVar6;
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            if (iVar21 != 0) {
LAB_14035b310:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              local_cc = iVar11;
              do {
                if ((byte)*puVar14 == uVar6) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035b47b;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (ulonglong)
                                        ((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >> 8)) +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                        (uint)bVar3 >> 8)) * 0x40) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                        (uint)bVar3 >> 8));
                    uVar15 = ((ushort)*puVar13 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar29 = uVar15 & 0x8210820;
                    *(ushort *)puVar13 =
                         (short)uVar29 - (short)(uVar29 >> 5) | ((ushort)*puVar13 | uVar23) & 0x820
                         | (ushort)uVar15;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035b47b;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                uVar23 = (*(short *)(&DAT_140b68970 +
                                    uVar33 * 0x100 +
                                    (ulonglong)
                                    ((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                     (uint)bVar3 >> 8)) +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                    (uint)bVar3 >> 8)) * 0x40) * 0x20 +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                    (uint)bVar3 >> 8));
                uVar6 = ((ushort)*puVar14 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                uVar15 = uVar6 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (short)uVar15 - (short)(uVar15 >> 5) | ((ushort)*puVar14 | uVar23) & 0x820 |
                     (ushort)uVar6;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
        }
        break;
      case 3:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14035c2d0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035c3a0;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    uVar25 = ((ushort)*puVar18 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                                        0x40 + *(short *)(&DAT_140b68970 +
                                                         uVar33 * 0x100 +
                                                         (ulonglong)(uVar23 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f))) &
                             0xf7def7df);
                    uVar20 = uVar25 & 0x8210820;
                    *(ushort *)puVar18 = (short)uVar20 - (short)(uVar20 >> 5) & (ushort)uVar25;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035c3a0;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                uVar20 = ((ushort)*puVar18 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) * 0x40 +
                                   *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) *
                                   0x20 + *(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f))) &
                         0xf7def7df);
                uVar6 = uVar20 & 0x8210820;
                *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14035c510:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035c602;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    uVar29 = ((ushort)*puVar18 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  (uint)(&DAT_140b68970)
                                                        [(ulonglong)uVar25 * 0x100 +
                                                         (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                       *(short *)(&DAT_140b68970 +
                                                 uVar33 * 0x100 +
                                                 (ulonglong)
                                                 (uint)(&DAT_140b68970)
                                                       [(ulonglong)uVar12 * 0x100 +
                                                        (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20
                                      + *(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  (uint)(&DAT_140b68970)
                                                        [(ulonglong)uVar20 * 0x100 +
                                                         (ulonglong)(uVar23 & 0x1f)])) & 0xf7def7df)
                    ;
                    uVar15 = uVar29 & 0x8210820;
                    *(ushort *)puVar18 = (short)uVar15 - (short)(uVar15 >> 5) & (ushort)uVar29;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035c602;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                uVar15 = ((ushort)*puVar18 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              (uint)(&DAT_140b68970)
                                                    [(ulonglong)uVar25 * 0x100 +
                                                     (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                   *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (ulonglong)
                                             (uint)(&DAT_140b68970)
                                                   [(ulonglong)uVar12 * 0x100 +
                                                    (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20 +
                                  *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            (uint)(&DAT_140b68970)
                                                  [(ulonglong)uVar20 * 0x100 +
                                                   (ulonglong)(uVar23 & 0x1f)])) & 0xf7def7df);
                uVar6 = uVar15 & 0x8210820;
                iVar9 = iVar9 + -1;
                *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                if (iVar9 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          iVar9 = iVar19;
          iVar10 = iVar11;
          puVar14 = puVar18;
          puVar13 = puVar16;
          if (iVar21 != 0) {
LAB_14035bc3d:
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035bd58;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                  uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                  uVar25 = ((ushort)*puVar18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) *
                                      0x40 + *(short *)(&DAT_140b68970 +
                                                       uVar33 * 0x100 +
                                                       (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)
                                                       )) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8))) &
                           0xf7def7df);
                  uVar20 = uVar25 & 0x8210820;
                  *(ushort *)puVar18 = (short)uVar20 - (short)(uVar20 >> 5) & (ushort)uVar25;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035bd58;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = (uint *)((longlong)puVar18 + 2);
              uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
              uVar20 = ((ushort)*puVar18 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40
                                 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))) * 0x20
                                + *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8))) &
                       0xf7def7df);
              uVar6 = uVar20 & 0x8210820;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
              if (local_c4 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1; iVar10 = iVar10 + uVar7
                  ) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar14 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
          } while (local_e8 != 0);
        }
        else {
          if (iVar21 != 0) {
LAB_14035bf50:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_cc = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035c09b;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  uVar29 = ((ushort)*puVar13 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                ((&DAT_140b68970)
                                                 [(ulonglong)uVar25 * 0x100 +
                                                  (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >>
                                                8)) +
                                     *(short *)(&DAT_140b68970 +
                                               uVar33 * 0x100 +
                                               (ulonglong)
                                               ((&DAT_140b68970)
                                                [(ulonglong)uVar12 * 0x100 +
                                                 (ulonglong)(uVar23 >> 0xb)] * (uint)bVar3 >> 8)) *
                                     0x40) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              ((&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar23 & 0x1f)] * (uint)bVar3 >> 8))) &
                           0xf7def7df);
                  uVar15 = uVar29 & 0x8210820;
                  *(ushort *)puVar13 = (short)uVar15 - (short)(uVar15 >> 5) & (ushort)uVar29;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035c09b;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              uVar15 = ((ushort)*puVar14 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            ((&DAT_140b68970)
                                             [(ulonglong)uVar25 * 0x100 +
                                              (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >> 8))
                                 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (ulonglong)
                                             ((&DAT_140b68970)
                                              [(ulonglong)uVar12 * 0x100 +
                                               (ulonglong)(uVar23 >> 0xb)] * (uint)bVar3 >> 8)) *
                                   0x40) * 0x20 +
                                *(short *)(&DAT_140b68970 +
                                          uVar33 * 0x100 +
                                          (ulonglong)
                                          ((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)]
                                           * (uint)bVar3 >> 8))) & 0xf7def7df);
              uVar6 = uVar15 & 0x8210820;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        break;
      case 4:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14035ce31:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035cf00;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (ushort)((uVar24 & 0x7e0) * (uVar23 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((uVar24 & 0xf800) * (uVar23 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035cf00;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                iVar9 = iVar9 + -1;
                *(ushort *)puVar18 =
                     (ushort)((uVar24 & 0x7e0) * (uVar23 & 0x7e0) >> 0xb) & 0x7e0 |
                     (ushort)((uVar24 & 0xf800) * (uVar23 & 0xf800) >> 0x10) & 0xf800 |
                     (ushort)((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5);
                if (iVar9 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035d061:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035d160;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (ushort)((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                  (uVar23 >> 5 & 0x3f) >> 1) & 0x7e0 |
                         *(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) *
                         (uVar23 >> 5 & 0x7c0) & 0xf800 |
                         (ushort)((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                  (uVar23 & 0x1f) >> 5);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035d160;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                              (uVar23 >> 5 & 0x3f) >> 1) & 0x7e0 |
                     *(short *)(&DAT_140b68970 +
                               (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) *
                     (uVar23 >> 5 & 0x7c0) & 0xf800 |
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                              (uVar23 & 0x1f) >> 5);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (iVar21 != 0) {
LAB_14035c7b0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
            iVar9 = iVar19;
            local_cc = iVar11;
            do {
              if ((byte)*puVar13 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035c8da;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar18;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar18 =
                       (ushort)((uVar24 >> 5 & 0x3f) * (uVar23 >> 5 & 0x3f) * (uint)bVar3 >> 9) &
                       0x7e0 | (ushort)((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) * (uint)bVar3
                                       >> 2) & 0xf800 |
                       (ushort)((uVar24 & 0x1f) * (uVar23 & 0x1f) * (uint)bVar3 >> 0xd);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035c8da;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              do {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar23 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              uVar24 = (ushort)*puVar14;
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0
                   | (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) &
                     0xf800 | (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        else {
          if (iVar21 != 0) {
LAB_14035cac0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar13 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035cc0e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar18;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar18 =
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                (uVar23 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                (uint)(uVar23 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                (uVar23 & 0x1f) * (uint)bVar3 >> 0xd);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035cc0e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                            (uVar23 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                            * (uint)(uVar23 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                            * (uVar23 & 0x1f) * (uint)bVar3 >> 0xd);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        break;
      case 10:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035e940:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035ea70;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4
                                    + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035ea70;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4 +
                                uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * 4 +
                                uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                     *(short *)(&DAT_140ba8d70 +
                               (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                               uVar33 * 0x800) + (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035ec40:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035ed90;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar25 * 0x100 +
                                           (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f))
                                    * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                         (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                         (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                        (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035ed90;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)((&DAT_140b68970)
                                      [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)]
                                     - (uVar23 >> 5 & 0x3f)) * 4 + uVar33 * 0x800) +
                     (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)((&DAT_140b68970)
                                      [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                     (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) + (uVar23 >> 0xb))
                     * 0x800 | *(short *)(&DAT_140ba8d70 +
                                         (longlong)
                                         (int)((&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar24 & 0x1f)] - (uVar23 & 0x1f)) * 4 +
                                         uVar33 * 0x800) + (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (iVar21 != 0) {
LAB_14035e1a0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035e30e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar20 = uVar23 & 0x1f;
                  uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                       (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                       (ushort)(((uVar24 & 0x1f) - uVar20) * (uint)bVar3 * iVar21 + uVar20 * 0x10000
                               >> 0x10);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035e30e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar6 = uVar23 & 0x1f;
              uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * iVar21 +
                            (uVar23 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                   (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 * iVar21 +
                            (uVar23 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                   (ushort)(((uVar24 & 0x1f) - uVar6) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >>
                           0x10);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        else {
          if (iVar21 != 0) {
LAB_14035e540:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035e6ce;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar15 = (uint)uVar23;
                  uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 + uVar15 * 0x10000 >> 0x10)
                       & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035e6ce;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar6 = (uint)uVar23;
              uVar24 = ~*(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                            (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                            (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                            (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                            (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10) & 0x1f
              ;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        break;
      case 0xb:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035db10:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14035dc54;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar20 = uVar23 >> 5 & 0x3f;
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)(((uVar24 >> 5 & 0x3f) * uVar20 >> 6) - uVar20) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)(((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                         (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                         (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)(((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f))
                                   * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14035dc54;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar6 = uVar23 >> 5 & 0x3f;
                uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)(int)(((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6) * 4 +
                                uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)(((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                     (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) + (uVar23 >> 0xb))
                     * 0x800 | *(short *)(&DAT_140ba8d70 +
                                         (longlong)
                                         (int)(((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5) -
                                              (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) +
                               (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14035de30:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035df96;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar15 = uVar23 >> 5 & 0x3f;
                    uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar16 * 2);
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)(((&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar15 >> 6) - uVar15
                                         ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)(((&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           * (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)(((&DAT_140b68970)
                                          [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                          (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035df96;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + local_50);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar6 = uVar23 >> 5 & 0x3f;
                uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar13 * 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)(((&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)]
                                       * uVar6 >> 6) - uVar6) * 4 + uVar33 * 0x800) +
                     (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)(((&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                       (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * 4 +
                                uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                     *(short *)(&DAT_140ba8d70 +
                               (longlong)
                               (int)(((&DAT_140b68970)
                                      [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                      (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800)
                     + (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + local_50);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (iVar21 != 0) {
LAB_14035d300:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035d48c;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar20 = uVar23 >> 5 & 0x3f;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  uVar25 = uVar23 & 0x1f;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar20 >> 6) - uVar20) * (uint)bVar3
                                      * iVar21 + (uVar23 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                       (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                      (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                     (uVar23 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                       (ushort)((((uVar24 & 0x1f) * uVar25 >> 5) - uVar25) * (uint)bVar3 * iVar21 +
                                uVar25 * 0x10000 >> 0x10);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035d48c;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar6 = uVar23 >> 5 & 0x3f;
              uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
              uVar20 = uVar23 & 0x1f;
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6) * (uint)bVar3 *
                                  iVar21 + (uVar23 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                   (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                  (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                 (uVar23 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                   (ushort)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar3 * iVar21 +
                            uVar20 * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + local_50);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        else {
          if (iVar21 != 0) {
LAB_14035d6e0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035d88c;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar29 = (uint)uVar23;
                  uVar15 = uVar23 >> 5 & 0x3f;
                  uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                  uVar15 >> 6) - uVar15) * (uint)bVar3 * iVar21 +
                                (uVar29 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                  (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3
                                * iVar21 + (uVar29 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                  (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * (uint)bVar3 * iVar21 +
                                uVar29 * 0x10000 >> 0x10) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035d88c;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar15 = (uint)uVar23;
              uVar6 = uVar23 >> 5 & 0x3f;
              uVar24 = *(ushort *)(lVar5 + (ulonglong)(byte)*puVar14 * 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar6
                             >> 6) - uVar6) * (uint)bVar3 * iVar21 + (uVar15 & 0xffffffe0) * 0x800
                           >> 0xb) & 0x7e0 |
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                              (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3 *
                            iVar21 + (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                              (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * (uint)bVar3 * iVar21 +
                            uVar15 * 0x10000 >> 0x10) & 0x1f;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + local_50);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
      }
    }
    else {
      switch(DAT_140c28a84) {
      case 1:
        if (DAT_140c28a88 != 0xff) {
          if (DAT_140c28a88 == 0) {
            return;
          }
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
              if (*(int *)(lVar30 + 0x34) != 1) {
                iVar28 = iVar19;
                iVar10 = iVar11;
                iVar9 = iVar19;
                puVar14 = puVar18;
                puVar13 = puVar16;
                if (iVar21 == 0) {
                  do {
                    while( true ) {
                      uVar23 = (ushort)*puVar18;
                      puVar2 = (uint *)((longlong)puVar18 + 2);
                      uVar24 = (ushort)*puVar13;
                      local_c4 = local_c4 + -1;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f)
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           - (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                           (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                                          - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f)
                      ;
                      if (local_c4 == 0) break;
                      for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                          iVar10 = iVar10 + uVar7) {
                        puVar13 = (uint *)((longlong)puVar13 + uVar32);
                      }
                    }
                    puVar18 = (uint *)((longlong)puVar14 + uVar22);
                    for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                        local_res18 = local_res18 + uVar8) {
                      puVar16 = (uint *)((longlong)puVar16 + local_b0);
                    }
                    local_e8 = local_e8 + -1;
                    local_c4 = iVar19;
                    iVar10 = iVar11;
                    puVar14 = puVar18;
                    puVar13 = puVar16;
                  } while (local_e8 != 0);
                  return;
                }
LAB_140360be1:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_140360d00;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f)
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           - (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                           (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                                          - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f)
                      ;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_140360d00;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              uVar27 = uVar33;
              iVar10 = iVar19;
              iVar9 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 == 0) {
                while( true ) {
                  while( true ) {
                    uVar23 = (ushort)*puVar18;
                    uVar6 = (uint)uVar23;
                    uVar24 = (ushort)*puVar16;
                    bVar3 = *(byte *)((longlong)puVar16 + 2);
                    iVar9 = (int)uVar33;
                    *(ushort *)puVar18 =
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                  (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar9 +
                                  (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                  (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                                  (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                  (uVar6 & 0x1f)) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >> 0x10) &
                         0x1f;
                    if (local_c4 + -1 == 0) break;
                    for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    local_c4 = local_c4 + -1;
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c4 = iVar19;
                  iVar28 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                }
                return;
              }
LAB_1403607be:
              do {
                if (*(byte *)((longlong)puVar16 + 2) == 0) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140360a0c;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_cc);
                }
                else {
                  iVar10 = iVar9;
                  if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f)
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           - (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                           (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                                          - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f)
                      ;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar9 + -1;
                      if (iVar10 == 0) goto LAB_1403609ff;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                    uVar27 = (ulonglong)DAT_140c28a88;
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar6 = (uint)uVar23;
                      uVar24 = (ushort)*puVar16;
                      bVar3 = *(byte *)((longlong)puVar16 + 2);
                      iVar9 = (int)uVar27;
                      *(ushort *)puVar18 =
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                    (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar9 +
                                    (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                    (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                                    (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                    (uVar6 & 0x1f)) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >> 0x10)
                           & 0x1f;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403609ff;
                      uVar27 = (ulonglong)DAT_140c28a88;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            if (*(int *)(lVar30 + 0x34) != 1) {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 == 0) {
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar18;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar24 = (ushort)*puVar13;
                    local_c4 = local_c4 + -1;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4
                                    + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    if (local_c4 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                        iVar10 = iVar10 + uVar7) {
                      puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar14 + uVar22);
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  local_c4 = iVar19;
                  iVar10 = iVar11;
                  puVar14 = puVar18;
                  puVar13 = puVar16;
                } while (local_e8 != 0);
                return;
              }
LAB_140360501:
              do {
                if ((ushort)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_140360610;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = (ushort)*puVar16;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4
                                    + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_140360610;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            uVar27 = uVar33;
            iVar10 = iVar19;
            iVar9 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  uVar20 = (uint)(ushort)*puVar18;
                  uVar23 = (ushort)*puVar16;
                  bVar3 = *(byte *)((longlong)puVar16 + 2);
                  uVar6 = (ushort)*puVar18 & 0x1f;
                  iVar9 = (int)uVar33;
                  *(ushort *)puVar18 =
                       (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 * iVar9 +
                                (uVar20 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                       (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 * iVar9 +
                                (uVar20 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                       (ushort)(((uVar23 & 0x1f) - uVar6) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >>
                               0x10);
                  if (local_c4 + -1 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  local_c4 = local_c4 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_c4 = iVar19;
                iVar28 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
              return;
            }
LAB_14036012c:
            do {
              if (*(byte *)((longlong)puVar16 + 2) == 0) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14036034c;
                  local_cc = local_cc + -0x10000;
                  iVar9 = iVar10;
                } while (0 < local_cc);
              }
              else {
                iVar10 = iVar9;
                if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = (ushort)*puVar16;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4
                                    + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar9 + -1;
                    if (iVar10 == 0) goto LAB_14036033f;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_cc);
                  uVar27 = (ulonglong)DAT_140c28a88;
                }
                else {
                  do {
                    uVar20 = (uint)(ushort)*puVar18;
                    uVar23 = (ushort)*puVar16;
                    bVar3 = *(byte *)((longlong)puVar16 + 2);
                    uVar6 = (ushort)*puVar18 & 0x1f;
                    iVar9 = (int)uVar27;
                    *(ushort *)puVar18 =
                         (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 * iVar9 +
                                  (uVar20 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 * iVar9 +
                                  (uVar20 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar23 & 0x1f) - uVar6) * (uint)bVar3 * iVar9 + uVar6 * 0x10000
                                 >> 0x10);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14036033f;
                    uVar27 = (ulonglong)DAT_140c28a88;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_cc);
                }
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
            if (*(int *)(lVar30 + 0x34) != 1) {
              if (iVar21 == 0) {
                while( true ) {
                  local_e0 = (uint *)local_c0;
                  puVar13 = puVar18;
                  local_c4 = iVar19;
                  iVar9 = iVar11;
                  puVar14 = puVar16;
                  while( true ) {
                    uVar23 = (ushort)*puVar13;
                    uVar6 = (uint)uVar23;
                    uVar24 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    local_c4 = local_c4 + -1;
                    *(ushort *)puVar13 =
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                  (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                  (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                  (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                  (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                  (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10)
                         & 0x1f;
                    if (local_c4 == 0) break;
                    iVar9 = iVar9 + -0x10000;
                    if (iVar9 < 1) {
                      do {
                        puVar14 = (uint *)((longlong)puVar14 + uVar32);
                        local_e0 = (uint *)((longlong)local_e0 + lVar17);
                        iVar9 = iVar9 + uVar7;
                      } while (iVar9 < 1);
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar13 = (uint *)((longlong)puVar13 + 2);
                    }
                    else {
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar13 = (uint *)((longlong)puVar13 + 2);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar18 + uVar22);
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                    local_c0 = local_c0 + local_90;
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                }
                return;
              }
LAB_14035fd50:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              local_cc = iVar11;
              do {
                if ((ushort)*puVar14 == uVar6) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035fec8;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar15 = (uint)uVar23;
                    uVar24 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                  (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                  (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                  (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                  (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                  (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 + uVar15 * 0x10000 >> 0x10
                                 ) & 0x1f;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035fec8;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            if (iVar21 == 0) {
              while( true ) {
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar14 = puVar16;
                while( true ) {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar6 & 0x1f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                              uVar6 * 0x1000000 >> 0x18) & 0x1f;
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                }
                puVar18 = (uint *)((longlong)puVar18 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
              }
              return;
            }
LAB_14035f840:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_c8 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035faef;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10) &
                       0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035fadb;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar6 & 0x1f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                              uVar6 * 0x1000000 >> 0x18) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035fadb;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 == 0) {
              while( true ) {
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar14 = puVar16;
                while( true ) {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar13 =
                       (ushort)(((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * (uint)bVar4 *
                                (uint)bVar3 * iVar21 + (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) &
                       0x7e0 | (ushort)(((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                        (uint)bVar4 * (uint)bVar3 * iVar21 +
                                        (uVar23 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                       (ushort)(byte)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar4 *
                                      (uint)bVar3 * iVar21 + (uVar23 & 0x1f) * 0x1000000 >> 0x18);
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                  }
                }
                puVar18 = (uint *)((longlong)puVar18 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
              }
              return;
            }
LAB_14035efd0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_c8 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035f265;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar6 = (uint)(ushort)*puVar13;
                  uVar23 = (ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar13 & 0xf800)) * (uint)bVar3 *
                                iVar21 + (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                       (ushort)(((uVar23 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                       (ushort)(((uVar23 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 +
                                (uVar6 & 0x1f) * 0x10000 >> 0x10);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035f24b;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * (uint)bVar4 *
                                (uint)bVar3 * iVar21 + (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) &
                       0x7e0 | (ushort)(((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                        (uint)bVar4 * (uint)bVar3 * iVar21 +
                                        (uVar23 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                       (ushort)(byte)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar4 *
                                      (uint)bVar3 * iVar21 + (uVar23 & 0x1f) * 0x1000000 >> 0x18);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14035f24b;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          if (iVar21 == 0) {
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              while( true ) {
                uVar6 = (uint)(ushort)*puVar14;
                uVar23 = (ushort)*puVar13;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar14 & 0xf800)) * (uint)bVar3 *
                              iVar21 + (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                     (ushort)(((uVar23 & 0x7e0) - (uVar6 & 0x7e0)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                     (ushort)(((uVar23 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0x1f) * 0x10000 >> 0x10);
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar14 = (uint *)((longlong)puVar14 + 2);
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
            return;
          }
LAB_14035f4a2:
          local_e0 = (uint *)local_c0;
          puVar13 = puVar18;
          puVar14 = puVar16;
          iVar9 = iVar19;
          local_cc = iVar11;
          do {
            if ((ushort)*puVar14 == uVar6) {
              do {
                puVar13 = (uint *)((longlong)puVar13 + 2);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) goto LAB_14035f5fb;
                local_cc = local_cc + -0x10000;
              } while (0 < local_cc);
            }
            else {
              do {
                uVar20 = (uint)(ushort)*puVar13;
                uVar23 = (ushort)*puVar14;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                *(ushort *)puVar13 =
                     (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar13 & 0xf800)) * (uint)bVar3 *
                              iVar21 + (uVar20 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                     (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 * iVar21 +
                              (uVar20 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                     (ushort)(((uVar23 & 0x1f) - (uVar20 & 0x1f)) * (uint)bVar3 * iVar21 +
                              (uVar20 & 0x1f) * 0x10000 >> 0x10);
                puVar13 = (uint *)((longlong)puVar13 + 2);
                iVar9 = iVar9 + -1;
                uVar33 = (ulonglong)DAT_140c28a88;
                if (iVar9 == 0) goto LAB_14035f5fb;
                local_cc = local_cc + -0x10000;
              } while (0 < local_cc);
            }
            do {
              puVar14 = (uint *)((longlong)puVar14 + uVar32);
              local_e0 = (uint *)((longlong)local_e0 + lVar17);
              local_cc = local_cc + uVar7;
            } while (local_cc < 1);
          } while( true );
        }
      case 0:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              iVar28 = iVar19;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_140361edd:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_140362020;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < local_cc);
                  }
                  else if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      *(ushort *)puVar18 = (ushort)*puVar16;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_140362020;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < local_cc);
                  }
                  else {
                    do {
                      uVar20 = (uint)(ushort)*puVar18;
                      bVar3 = *(byte *)((longlong)puVar16 + 2);
                      uVar23 = (ushort)*puVar16;
                      uVar6 = (ushort)*puVar18 & 0x1f;
                      *(ushort *)puVar18 =
                           (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 +
                                    (uVar20 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                           (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 +
                                    (uVar20 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                           (ushort)(((uVar23 & 0x1f) - uVar6) * (uint)bVar3 + uVar6 * 0x100 >> 8);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_140362020;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < local_cc);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar20 = (uint)(ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar23 = (ushort)*puVar13;
                  bVar3 = *(byte *)((longlong)puVar13 + 2);
                  uVar6 = (ushort)*puVar18 & 0x1f;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 +
                                (uVar20 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                       (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 +
                                (uVar20 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                       (ushort)(((uVar23 & 0x1f) - uVar6) * (uint)bVar3 + uVar6 * 0x100 >> 8);
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403621b0:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036221d;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      *(ushort *)puVar18 = (ushort)*puVar16;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036221d;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  *(ushort *)puVar18 = (ushort)*puVar16;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14036232b:
              do {
                if (*(byte *)((longlong)puVar16 + 2) == 0) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_1403624ef;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                else if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar16;
                    *(ushort *)puVar18 =
                         (*(ushort *)
                           (&DAT_140b68970 +
                           (ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)) |
                         *(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) << 6) <<
                         5 | *(ushort *)
                              (&DAT_140b68970 +
                              (ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_1403624ef;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = (ushort)*puVar16;
                    bVar3 = *(byte *)((longlong)puVar16 + 2);
                    *(ushort *)puVar18 =
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                  (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >>
                                 3) & 0x7e0 |
                         ((*(short *)(&DAT_140b68970 +
                                     (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                          (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800 |
                         (ushort)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                  (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_1403624ef;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = (ushort)*puVar13;
                bVar3 = *(byte *)((longlong)puVar13 + 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                              (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3)
                     & 0x7e0 | ((*(short *)(&DAT_140b68970 +
                                           (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                                (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 &
                               0xf800 |
                     (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_1403626b0:
              do {
                if ((ushort)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140362760;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar16;
                    *(ushort *)puVar18 =
                         (*(ushort *)
                           (&DAT_140b68970 +
                           (ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)) |
                         *(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) << 6) <<
                         5 | *(ushort *)
                              (&DAT_140b68970 +
                              (ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140362760;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar16;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                *(ushort *)puVar18 =
                     (*(ushort *)
                       (&DAT_140b68970 + (ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)
                       ) | *(short *)(&DAT_140b68970 +
                                     (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) << 6)
                     << 5 | *(ushort *)
                             (&DAT_140b68970 +
                             (ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_140360ef0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_c8 = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036112b;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar20 = (uint)(ushort)*puVar13;
                    uVar23 = (ushort)*puVar14;
                    uVar6 = uVar20 << 8;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    *(ushort *)puVar13 =
                         (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar13 & 0xf800)) * (uint)bVar3 +
                                  (uVar6 & 0xfff80000) >> 8) & 0xf800 |
                         (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 +
                                  (uVar6 & 0xffffe000) >> 8) & 0x7e0 |
                         (ushort)(((uVar23 & 0x1f) - (uVar20 & 0x1f)) * (uint)bVar3 +
                                  (uVar6 & 0x1f00) >> 8);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036112b;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    uVar6 = (uint)uVar23 << 0x10;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    bVar4 = *(byte *)((longlong)puVar14 + 2);
                    *(ushort *)puVar13 =
                         (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 *
                                  (uint)bVar4 + (uVar6 & 0xf8000000) >> 0x10) & 0xf800 |
                         (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * (uint)bVar4
                                  + (uVar6 & 0xffe00000) >> 0x10) & 0x7e0 |
                         (ushort)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar3 * (uint)bVar4 +
                                  (uVar6 & 0x1f0000) >> 0x10);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036112b;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar14;
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar24 = (ushort)*puVar13;
                uVar6 = (uint)uVar23 << 0x10;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                bVar4 = *(byte *)((longlong)puVar13 + 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 * (uint)bVar4 +
                              (uVar6 & 0xf8000000) >> 0x10) & 0xf800 |
                     (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * (uint)bVar4 +
                              (uVar6 & 0xffe00000) >> 0x10) & 0x7e0 |
                     (ushort)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar3 * (uint)bVar4 +
                              (uVar6 & 0x1f0000) >> 0x10);
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
          else {
            if (iVar21 != 0) {
LAB_140361340:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
              iVar9 = iVar19;
              local_cc = iVar11;
              do {
                if ((ushort)*puVar13 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036147a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar25 = (uint)(ushort)*puVar18;
                    uVar23 = (ushort)*puVar13;
                    uVar20 = uVar25 << 8;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    *(ushort *)puVar18 =
                         (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar18 & 0xf800)) * (uint)bVar3 +
                                  (uVar20 & 0xfff80000) >> 8) & 0xf800 |
                         (ushort)(((uVar23 & 0x7e0) - (uVar25 & 0x7e0)) * (uint)bVar3 +
                                  (uVar20 & 0xffffe000) >> 8) & 0x7e0 |
                         (ushort)(((uVar23 & 0x1f) - (uVar25 & 0x1f)) * (uint)bVar3 +
                                  (uVar20 & 0x1f00) >> 8);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036147a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                uVar20 = (uint)(ushort)*puVar14;
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar23 = (ushort)*puVar13;
                uVar6 = uVar20 << 8;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (ushort)(((uVar23 & 0xf800) - ((ushort)*puVar14 & 0xf800)) * (uint)bVar3 +
                              (uVar6 & 0xfff80000) >> 8) & 0xf800 |
                     (ushort)(((uVar23 & 0x7e0) - (uVar20 & 0x7e0)) * (uint)bVar3 +
                              (uVar6 & 0xffffe000) >> 8) & 0x7e0 |
                     (ushort)(((uVar23 & 0x1f) - (uVar20 & 0x1f)) * (uint)bVar3 + (uVar6 & 0x1f00)
                             >> 8);
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
        }
        else if (*(int *)(lVar30 + 0x34) == 1) {
          if (iVar21 != 0) {
LAB_140361690:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar11;
            local_c8 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  local_c8 = local_c8 + -1;
                  if (local_c8 == 0) goto LAB_140361916;
                  iVar9 = iVar9 + -0x10000;
                } while (0 < iVar9);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3
                               ) & 0x7e0 |
                       ((*(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                        (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  local_c8 = local_c8 + -1;
                  if (local_c8 == 0) goto LAB_140361916;
                  iVar9 = iVar9 + -0x10000;
                } while (0 < iVar9);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 +
                                (uVar23 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar23 & 0x1f)) * (uint)bVar4 * (uint)bVar3 +
                                (uVar23 & 0x1f) * 0x10000 >> 0x10);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  local_c8 = local_c8 + -1;
                  if (local_c8 == 0) goto LAB_140361916;
                  iVar9 = iVar9 + -0x10000;
                } while (0 < iVar9);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                iVar9 = iVar9 + uVar7;
              } while (iVar9 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar24 = (ushort)*puVar13;
              bVar3 = *(byte *)((longlong)puVar13 + 2);
              bVar4 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 +
                            (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                            (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 +
                            (uVar23 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                            (uVar23 & 0x1f)) * (uint)bVar4 * (uint)bVar3 + (uVar23 & 0x1f) * 0x10000
                           >> 0x10);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        else {
          if (iVar21 != 0) {
LAB_140361b20:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((ushort)*puVar13 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140361c8e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar18;
                  uVar24 = (ushort)*puVar13;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar18 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3
                               ) & 0x7e0 |
                       ((*(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                        (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140361c8e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              uVar24 = (ushort)*puVar13;
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar3 + (uVar23 & 0xffffffe0) * 8 >> 3) &
                   0x7e0 | ((*(short *)(&DAT_140b68970 +
                                       (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)) -
                            (uVar23 >> 0xb)) * (ushort)bVar3 + (uVar23 >> 3 & 0x1f00)) * 8 & 0xf800
                   | (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar23 & 0x1f)) * (uint)bVar3 + (uVar23 & 0x1f) * 0x100 >> 8);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        break;
      case 2:
        if (DAT_140c28a88 != 0) {
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              if (*(int *)(lVar30 + 0x34) == 1) {
                iVar10 = iVar19;
                iVar28 = iVar11;
                iVar9 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_1403638e0:
                  do {
                    if (*(byte *)((longlong)puVar16 + 2) == 0) {
                      do {
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140363abb;
                        iVar28 = iVar28 + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < iVar28);
                    }
                    else {
                      iVar10 = iVar9;
                      if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                        do {
                          uVar23 = (ushort)*puVar16;
                          uVar23 = (*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) * 0x40 +
                                   *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) *
                                   0x20 + *(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                          uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                          uVar6 = uVar20 & 0x8210820;
                          *(ushort *)puVar18 =
                               (short)uVar6 - (short)(uVar6 >> 5) |
                               ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar20;
                          puVar18 = (uint *)((longlong)puVar18 + 2);
                          iVar10 = iVar9 + -1;
                          if (iVar10 == 0) goto LAB_140363abb;
                          iVar28 = iVar28 + -0x10000;
                          iVar9 = iVar10;
                        } while (0 < iVar28);
                      }
                      else {
                        do {
                          uVar23 = (ushort)*puVar16;
                          uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                          uVar23 = (*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) *
                                    0x40 + *(short *)(&DAT_140b68970 +
                                                     uVar33 * 0x100 +
                                                     (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)))
                                   * 0x20 + *(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 +
                                                      ((uVar23 & 0x1f) * uVar27 >> 8));
                          uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                          uVar6 = uVar20 & 0x8210820;
                          *(ushort *)puVar18 =
                               (short)uVar6 - (short)(uVar6 >> 5) |
                               ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar20;
                          puVar18 = (uint *)((longlong)puVar18 + 2);
                          iVar10 = iVar10 + -1;
                          if (iVar10 == 0) goto LAB_140363abb;
                          iVar28 = iVar28 + -0x10000;
                          iVar9 = iVar10;
                        } while (0 < iVar28);
                      }
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar28 = iVar28 + uVar7;
                    } while (iVar28 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar16;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                    uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar6 = uVar20 & 0x8210820;
                    iVar9 = iVar9 + -1;
                    *(ushort *)puVar18 =
                         (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                         (ushort)uVar20;
                    if (iVar9 == 0) break;
                    for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1;
                        iVar28 = iVar28 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar28 = iVar11;
                  iVar9 = iVar19;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
              else {
                iVar28 = iVar19;
                iVar10 = iVar11;
                iVar9 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_140363c70:
                  do {
                    if ((ushort)*puVar16 == uVar6) {
                      do {
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar28 = iVar28 + -1;
                        if (iVar28 == 0) goto LAB_140363d5f;
                        iVar10 = iVar10 + -0x10000;
                        iVar9 = iVar28;
                      } while (0 < iVar10);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar23 = (*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) * 0x40 +
                                 *(short *)(&DAT_140b68970 +
                                           uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) * 0x20
                                 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f));
                        uVar25 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                        uVar20 = uVar25 & 0x8210820;
                        *(ushort *)puVar18 =
                             (short)uVar20 - (short)(uVar20 >> 5) |
                             ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar25;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar28 = iVar9 + -1;
                        if (iVar28 == 0) goto LAB_140363d5f;
                        iVar10 = iVar10 + -0x10000;
                        iVar9 = iVar28;
                      } while (0 < iVar10);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar10 = iVar10 + uVar7;
                    } while (iVar10 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar16;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f))) * 0x20 +
                             *(short *)(&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f)
                                       );
                    uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar6 = uVar20 & 0x8210820;
                    iVar9 = iVar9 + -1;
                    *(ushort *)puVar18 =
                         (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                         (ushort)uVar20;
                    if (iVar9 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                        iVar10 = iVar10 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar10 = iVar11;
                  iVar9 = iVar19;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
            }
            else if (*(int *)(lVar30 + 0x34) == 1) {
              iVar10 = iVar19;
              iVar28 = iVar11;
              iVar9 = iVar19;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140363ef0:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140364104;
                      iVar28 = iVar28 + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < iVar28);
                  }
                  else {
                    iVar10 = iVar9;
                    if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar23 = (*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            (uint)(&DAT_140b68970)
                                                  [(ulonglong)uVar25 * 0x100 +
                                                   (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                 *(short *)(&DAT_140b68970 +
                                           uVar33 * 0x100 +
                                           (ulonglong)
                                           (uint)(&DAT_140b68970)
                                                 [(ulonglong)uVar12 * 0x100 +
                                                  (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20 +
                                 *(short *)(&DAT_140b68970 +
                                           uVar33 * 0x100 +
                                           (ulonglong)
                                           (uint)(&DAT_140b68970)
                                                 [(ulonglong)uVar20 * 0x100 +
                                                  (ulonglong)(uVar23 & 0x1f)]);
                        uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                        uVar6 = uVar15 & 0x8210820;
                        *(ushort *)puVar18 =
                             (short)uVar6 - (short)(uVar6 >> 5) |
                             ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar15;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar9 + -1;
                        if (iVar10 == 0) goto LAB_140364104;
                        iVar28 = iVar28 + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < iVar28);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                        uVar23 = (*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            (uint)(&DAT_140b68970)
                                                  [(ulonglong)uVar12 * 0x100 +
                                                   (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)])
                                  * 0x40 + *(short *)(&DAT_140b68970 +
                                                     uVar33 * 0x100 +
                                                     (ulonglong)
                                                     (uint)(&DAT_140b68970)
                                                           [(ulonglong)uVar25 * 0x100 +
                                                            (((ulonglong)uVar23 & 0x7e0) * uVar27 >>
                                                            0xd)])) * 0x20 +
                                 *(short *)(&DAT_140b68970 +
                                           uVar33 * 0x100 +
                                           (ulonglong)
                                           (uint)(&DAT_140b68970)
                                                 [(ulonglong)uVar20 * 0x100 +
                                                  ((uVar23 & 0x1f) * uVar27 >> 8)]);
                        uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                        uVar6 = uVar15 & 0x8210820;
                        *(ushort *)puVar18 =
                             (short)uVar6 - (short)(uVar6 >> 5) |
                             ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar15;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140364104;
                        iVar28 = iVar28 + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < iVar28);
                    }
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar28 = iVar28 + uVar7;
                  } while (iVar28 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar16;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                  uVar23 = (*(short *)(&DAT_140b68970 +
                                      uVar33 * 0x100 +
                                      (ulonglong)
                                      (uint)(&DAT_140b68970)
                                            [(ulonglong)uVar12 * 0x100 +
                                             (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)]) *
                            0x40 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (ulonglong)
                                             (uint)(&DAT_140b68970)
                                                   [(ulonglong)uVar25 * 0x100 +
                                                    (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)]))
                           * 0x20 + *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              (uint)(&DAT_140b68970)
                                                    [(ulonglong)uVar20 * 0x100 +
                                                     ((uVar23 & 0x1f) * uVar27 >> 8)]);
                  uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar6 = uVar15 & 0x8210820;
                  iVar9 = iVar9 + -1;
                  *(ushort *)puVar18 =
                       (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                       (ushort)uVar15;
                  if (iVar9 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1;
                      iVar28 = iVar28 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar28 = iVar11;
                iVar9 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403642d0:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_1403643cf;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar23 = (*(short *)(&DAT_140b68970 +
                                          uVar33 * 0x100 +
                                          (ulonglong)
                                          (uint)(&DAT_140b68970)
                                                [(ulonglong)uVar25 * 0x100 +
                                                 (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 +
                                         (ulonglong)
                                         (uint)(&DAT_140b68970)
                                               [(ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 +
                                         (ulonglong)
                                         (uint)(&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar23 & 0x1f)]);
                      uVar29 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                      uVar15 = uVar29 & 0x8210820;
                      *(ushort *)puVar18 =
                           (short)uVar15 - (short)(uVar15 >> 5) |
                           ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar29;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_1403643cf;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar16;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar23 = (*(short *)(&DAT_140b68970 +
                                      uVar33 * 0x100 +
                                      (ulonglong)
                                      (uint)(&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)])
                           * 0x40) * 0x20 +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)])
                  ;
                  uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar6 = uVar15 & 0x8210820;
                  iVar9 = iVar9 + -1;
                  *(ushort *)puVar18 =
                       (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                       (ushort)uVar15;
                  if (iVar9 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar11;
                iVar9 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              if (iVar21 != 0) {
LAB_1403628d0:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar21 = iVar19;
                local_cc = iVar11;
                iVar9 = iVar19;
                do {
                  if (*(byte *)((longlong)puVar14 + 2) == 0) {
                    do {
                      puVar13 = (uint *)((longlong)puVar13 + 2);
                      iVar21 = iVar21 + -1;
                      if (iVar21 == 0) goto LAB_140362b17;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar21;
                    } while (0 < local_cc);
                  }
                  else {
                    iVar21 = iVar9;
                    if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                      do {
                        uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                        uVar23 = (ushort)*puVar14;
                        uVar23 = (*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40
                                 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))) * 0x20
                                 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                        uVar20 = ((ushort)*puVar13 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar13 =
                             (short)uVar6 - (short)(uVar6 >> 5) |
                             ((ushort)*puVar13 | uVar23) & 0x820 | (ushort)uVar20;
                        puVar13 = (uint *)((longlong)puVar13 + 2);
                        iVar21 = iVar21 + -1;
                        if (iVar21 == 0) goto LAB_140362b17;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar21;
                      } while (0 < local_cc);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar14;
                        uVar27 = (ulonglong)*(byte *)((longlong)puVar14 + 2);
                        uVar31 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                        uVar23 = (*(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (((ulonglong)uVar23 & 0xf800) * uVar27 * uVar31 >> 0x1b)
                                            ) * 0x40 +
                                 *(short *)(&DAT_140b68970 +
                                           uVar33 * 0x100 +
                                           (((ulonglong)uVar23 & 0x7e0) * uVar27 * uVar31 >> 0x15)))
                                 * 0x20 + *(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    ((uVar23 & 0x1f) * uVar27 * uVar31 >> 0x10));
                        uVar20 = ((ushort)*puVar13 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar13 =
                             (short)uVar6 - (short)(uVar6 >> 5) |
                             ((ushort)*puVar13 | uVar23) & 0x820 | (ushort)uVar20;
                        puVar13 = (uint *)((longlong)puVar13 + 2);
                        iVar21 = iVar21 + -1;
                        if (iVar21 == 0) goto LAB_140362b17;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar21;
                      } while (0 < local_cc);
                    }
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              do {
                local_e0 = (uint *)local_c0;
                puVar14 = puVar18;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar16;
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar14 + 2);
                  uVar23 = (ushort)*puVar13;
                  uVar27 = (ulonglong)*(byte *)((longlong)puVar13 + 2);
                  uVar31 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                  uVar23 = (*(short *)(&DAT_140b68970 +
                                      uVar33 * 0x100 +
                                      (((ulonglong)uVar23 & 0xf800) * uVar27 * uVar31 >> 0x1b)) *
                            0x40 + *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (((ulonglong)uVar23 & 0x7e0) * uVar27 * uVar31 >> 0x15)
                                             )) * 0x20 +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 * uVar31 >> 0x10));
                  uVar20 = ((ushort)*puVar14 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar6 = uVar20 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar14 =
                       (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar14 | uVar23) & 0x820 |
                       (ushort)uVar20;
                  if (local_c4 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  }
                }
                puVar18 = (uint *)((longlong)puVar18 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
              } while (local_e8 != 0);
            }
            else {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_140362d40:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140362e78;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                      uVar23 = (ushort)*puVar16;
                      uVar23 = (*(short *)(&DAT_140b68970 +
                                          uVar33 * 0x100 +
                                          (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 +
                                         (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))) * 0x20 +
                               *(short *)(&DAT_140b68970 +
                                         uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                      uVar25 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                      uVar20 = uVar25 & 0x8210820;
                      *(ushort *)puVar18 =
                           (short)uVar20 - (short)(uVar20 >> 5) |
                           ((ushort)*puVar18 | uVar23) & 0x820 | (ushort)uVar25;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140362e78;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                  uVar23 = (ushort)*puVar13;
                  uVar23 = (*(short *)(&DAT_140b68970 +
                                      uVar33 * 0x100 +
                                      (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) * 0x40 +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 + (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd))
                           ) * 0x20 +
                           *(short *)(&DAT_140b68970 +
                                     uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8));
                  uVar20 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                  uVar6 = uVar20 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                       (ushort)uVar20;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_140363090:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_cc = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140363318;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (ulonglong)
                                        ((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >> 8)) +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                        (uint)bVar3 >> 8)) * 0x40) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                        (uint)bVar3 >> 8));
                    uVar15 = ((ushort)*puVar13 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar6 = uVar15 & 0x8210820;
                    *(ushort *)puVar13 =
                         (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar13 | uVar23) & 0x820 |
                         (ushort)uVar15;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140363318;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar14;
                    bVar3 = *(byte *)((longlong)puVar14 + 2);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (ulonglong)
                                        ((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar4 *
                                         (uint)bVar3 >> 0x10)) +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                        (uint)bVar4 * (uint)bVar3 >> 0x10)) * 0x40) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                        (uint)bVar4 * (uint)bVar3 >> 0x10));
                    uVar15 = ((ushort)*puVar13 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar6 = uVar15 & 0x8210820;
                    *(ushort *)puVar13 =
                         (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar13 | uVar23) & 0x820 |
                         (ushort)uVar15;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140363318;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar23 = (ushort)*puVar13;
                bVar3 = *(byte *)((longlong)puVar13 + 2);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                uVar23 = (*(short *)(&DAT_140b68970 +
                                    uVar33 * 0x100 +
                                    (ulonglong)
                                    ((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                     (uint)bVar4 * (uint)bVar3 >> 0x10)) +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                    (uint)bVar4 * (uint)bVar3 >> 0x10)) * 0x40) * 0x20 +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                    (uint)bVar4 * (uint)bVar3 >> 0x10));
                uVar15 = ((ushort)*puVar14 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                uVar6 = uVar15 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar14 | uVar23) & 0x820 |
                     (ushort)uVar15;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
          else {
            iVar9 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_140363540:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              do {
                if ((ushort)*puVar13 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036369a;
                    iVar21 = iVar21 + -0x10000;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar23 = (*(short *)(&DAT_140b68970 +
                                        uVar33 * 0x100 +
                                        (ulonglong)
                                        ((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >> 8)) +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                        (uint)bVar3 >> 8)) * 0x40) * 0x20 +
                             *(short *)(&DAT_140b68970 +
                                       uVar33 * 0x100 +
                                       (ulonglong)
                                       ((&DAT_140b68970)
                                        [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                        (uint)bVar3 >> 8));
                    uVar29 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                    uVar15 = uVar29 & 0x8210820;
                    *(ushort *)puVar18 =
                         (short)uVar15 - (short)(uVar15 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820
                         | (ushort)uVar29;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036369a;
                    iVar21 = iVar21 + -0x10000;
                  } while (0 < iVar21);
                }
                do {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = (ushort)*puVar13;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                uVar23 = (*(short *)(&DAT_140b68970 +
                                    uVar33 * 0x100 +
                                    (ulonglong)
                                    ((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                     (uint)bVar3 >> 8)) +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                    (uint)bVar3 >> 8)) * 0x40) * 0x20 +
                         *(short *)(&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   ((&DAT_140b68970)
                                    [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                    (uint)bVar3 >> 8));
                uVar15 = ((ushort)*puVar18 & 0xf7def7df) + (uVar23 & 0xf7def7df);
                uVar6 = uVar15 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar18 | uVar23) & 0x820 |
                     (ushort)uVar15;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        break;
      case 3:
        if (DAT_140c28a88 != 0) {
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              if (*(int *)(lVar30 + 0x34) == 1) {
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_1403654a0:
                  do {
                    if (*(byte *)((longlong)puVar16 + 2) == 0) {
                      do {
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140365635;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    else if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar20 = ((ushort)*puVar18 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                                            0x40 + *(short *)(&DAT_140b68970 +
                                                             uVar33 * 0x100 +
                                                             (ulonglong)(uVar23 >> 5 & 0x3f))) *
                                           0x20 + *(short *)(&DAT_140b68970 +
                                                            uVar33 * 0x100 +
                                                            (ulonglong)(uVar23 & 0x1f))) &
                                 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140365635;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                        uVar20 = ((ushort)*puVar18 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 +
                                                      (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13
                                                      )) * 0x40 +
                                           *(short *)(&DAT_140b68970 +
                                                     uVar33 * 0x100 +
                                                     (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)))
                                           * 0x20 + *(short *)(&DAT_140b68970 +
                                                              uVar33 * 0x100 +
                                                              ((uVar23 & 0x1f) * uVar27 >> 8))) &
                                 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140365635;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar16;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                    uVar20 = ((ushort)*puVar18 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) *
                                        0x40 + *(short *)(&DAT_140b68970 +
                                                         uVar33 * 0x100 +
                                                         (((ulonglong)uVar23 & 0x7e0) * uVar27 >>
                                                         0xd))) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8))) &
                             0xf7def7df);
                    uVar6 = uVar20 & 0x8210820;
                    *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) break;
                    for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1;
                        iVar9 = iVar9 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar10 = iVar19;
                  iVar9 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
              else {
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_1403657c0:
                  do {
                    if ((ushort)*puVar16 == uVar6) {
                      do {
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140365890;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar16;
                        uVar25 = ((ushort)*puVar18 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                                            0x40 + *(short *)(&DAT_140b68970 +
                                                             uVar33 * 0x100 +
                                                             (ulonglong)(uVar23 >> 5 & 0x3f))) *
                                           0x20 + *(short *)(&DAT_140b68970 +
                                                            uVar33 * 0x100 +
                                                            (ulonglong)(uVar23 & 0x1f))) &
                                 0xf7def7df);
                        uVar20 = uVar25 & 0x8210820;
                        *(ushort *)puVar18 = (short)uVar20 - (short)(uVar20 >> 5) & (ushort)uVar25;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140365890;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    uVar23 = (ushort)*puVar16;
                    puVar2 = (uint *)((longlong)puVar18 + 2);
                    uVar20 = ((ushort)*puVar18 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                                        0x40 + *(short *)(&DAT_140b68970 +
                                                         uVar33 * 0x100 +
                                                         (ulonglong)(uVar23 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 + (ulonglong)(uVar23 & 0x1f))) &
                             0xf7def7df);
                    uVar6 = uVar20 & 0x8210820;
                    *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) break;
                    for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1;
                        iVar9 = iVar9 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar10 = iVar19;
                  iVar9 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
            }
            else if (*(int *)(lVar30 + 0x34) == 1) {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140365a00:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_140365bf4;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar15 = ((ushort)*puVar18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    (ulonglong)
                                                    (uint)(&DAT_140b68970)
                                                          [(ulonglong)uVar25 * 0x100 +
                                                           (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                         *(short *)(&DAT_140b68970 +
                                                   uVar33 * 0x100 +
                                                   (ulonglong)
                                                   (uint)(&DAT_140b68970)
                                                         [(ulonglong)uVar12 * 0x100 +
                                                          (ulonglong)(uVar23 >> 0xb)]) * 0x40) *
                                         0x20 + *(short *)(&DAT_140b68970 +
                                                          uVar33 * 0x100 +
                                                          (ulonglong)
                                                          (uint)(&DAT_140b68970)
                                                                [(ulonglong)uVar20 * 0x100 +
                                                                 (ulonglong)(uVar23 & 0x1f)])) &
                               0xf7def7df);
                      uVar6 = uVar15 & 0x8210820;
                      *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_140365bf4;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                      uVar15 = ((ushort)*puVar18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    (ulonglong)
                                                    (uint)(&DAT_140b68970)
                                                          [(ulonglong)uVar12 * 0x100 +
                                                           (((ulonglong)uVar23 & 0xf800) * uVar27 >>
                                                           0x13)]) * 0x40 +
                                         *(short *)(&DAT_140b68970 +
                                                   uVar33 * 0x100 +
                                                   (ulonglong)
                                                   (uint)(&DAT_140b68970)
                                                         [(ulonglong)uVar25 * 0x100 +
                                                          (((ulonglong)uVar23 & 0x7e0) * uVar27 >>
                                                          0xd)])) * 0x20 +
                                        *(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  (uint)(&DAT_140b68970)
                                                        [(ulonglong)uVar20 * 0x100 +
                                                         ((uVar23 & 0x1f) * uVar27 >> 8)])) &
                               0xf7def7df);
                      uVar6 = uVar15 & 0x8210820;
                      *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_140365bf4;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar16;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar27 = (ulonglong)*(byte *)((longlong)puVar16 + 2);
                  uVar15 = ((ushort)*puVar18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                (uint)(&DAT_140b68970)
                                                      [(ulonglong)uVar12 * 0x100 +
                                                       (((ulonglong)uVar23 & 0xf800) * uVar27 >>
                                                       0x13)]) * 0x40 +
                                     *(short *)(&DAT_140b68970 +
                                               uVar33 * 0x100 +
                                               (ulonglong)
                                               (uint)(&DAT_140b68970)
                                                     [(ulonglong)uVar25 * 0x100 +
                                                      (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)]
                                               )) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              (uint)(&DAT_140b68970)
                                                    [(ulonglong)uVar20 * 0x100 +
                                                     ((uVar23 & 0x1f) * uVar27 >> 8)])) & 0xf7def7df
                           );
                  uVar6 = uVar15 & 0x8210820;
                  iVar9 = iVar9 + -1;
                  *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                  if (iVar9 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar11;
                iVar9 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140365da0:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140365e8f;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar29 = ((ushort)*puVar18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    (ulonglong)
                                                    (uint)(&DAT_140b68970)
                                                          [(ulonglong)uVar25 * 0x100 +
                                                           (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                         *(short *)(&DAT_140b68970 +
                                                   uVar33 * 0x100 +
                                                   (ulonglong)
                                                   (uint)(&DAT_140b68970)
                                                         [(ulonglong)uVar12 * 0x100 +
                                                          (ulonglong)(uVar23 >> 0xb)]) * 0x40) *
                                         0x20 + *(short *)(&DAT_140b68970 +
                                                          uVar33 * 0x100 +
                                                          (ulonglong)
                                                          (uint)(&DAT_140b68970)
                                                                [(ulonglong)uVar20 * 0x100 +
                                                                 (ulonglong)(uVar23 & 0x1f)])) &
                               0xf7def7df);
                      uVar15 = uVar29 & 0x8210820;
                      *(ushort *)puVar18 = (short)uVar15 - (short)(uVar15 >> 5) & (ushort)uVar29;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140365e8f;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar16;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar15 = ((ushort)*puVar18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                (uint)(&DAT_140b68970)
                                                      [(ulonglong)uVar25 * 0x100 +
                                                       (ulonglong)(uVar23 >> 5 & 0x3f)]) +
                                     *(short *)(&DAT_140b68970 +
                                               uVar33 * 0x100 +
                                               (ulonglong)
                                               (uint)(&DAT_140b68970)
                                                     [(ulonglong)uVar12 * 0x100 +
                                                      (ulonglong)(uVar23 >> 0xb)]) * 0x40) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              (uint)(&DAT_140b68970)
                                                    [(ulonglong)uVar20 * 0x100 +
                                                     (ulonglong)(uVar23 & 0x1f)])) & 0xf7def7df);
                  uVar6 = uVar15 & 0x8210820;
                  *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              if (iVar21 != 0) {
LAB_140364590:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar21 = iVar19;
                local_cc = iVar11;
                iVar9 = iVar19;
                do {
                  if (*(byte *)((longlong)puVar14 + 2) == 0) {
                    do {
                      puVar13 = (uint *)((longlong)puVar13 + 2);
                      iVar21 = iVar21 + -1;
                      if (iVar21 == 0) goto LAB_140364798;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar21;
                    } while (0 < local_cc);
                  }
                  else {
                    iVar21 = iVar9;
                    if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                      do {
                        uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                        uVar23 = (ushort)*puVar14;
                        uVar20 = ((ushort)*puVar13 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 +
                                                      (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13
                                                      )) * 0x40 +
                                           *(short *)(&DAT_140b68970 +
                                                     uVar33 * 0x100 +
                                                     (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)))
                                           * 0x20 + *(short *)(&DAT_140b68970 +
                                                              uVar33 * 0x100 +
                                                              ((uVar23 & 0x1f) * uVar27 >> 8))) &
                                 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar13 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                        puVar13 = (uint *)((longlong)puVar13 + 2);
                        iVar21 = iVar21 + -1;
                        if (iVar21 == 0) goto LAB_140364798;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar21;
                      } while (0 < local_cc);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar14;
                        uVar27 = (ulonglong)*(byte *)((longlong)puVar14 + 2);
                        uVar31 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                        uVar20 = ((ushort)*puVar13 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_140b68970 +
                                                      uVar33 * 0x100 +
                                                      (((ulonglong)uVar23 & 0xf800) * uVar27 *
                                                       uVar31 >> 0x1b)) * 0x40 +
                                           *(short *)(&DAT_140b68970 +
                                                     uVar33 * 0x100 +
                                                     (((ulonglong)uVar23 & 0x7e0) * uVar27 * uVar31
                                                     >> 0x15))) * 0x20 +
                                          *(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    ((uVar23 & 0x1f) * uVar27 * uVar31 >> 0x10))) &
                                 0xf7def7df);
                        uVar6 = uVar20 & 0x8210820;
                        *(ushort *)puVar13 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                        puVar13 = (uint *)((longlong)puVar13 + 2);
                        iVar21 = iVar21 + -1;
                        if (iVar21 == 0) goto LAB_140364798;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar21;
                      } while (0 < local_cc);
                    }
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              do {
                local_e0 = (uint *)local_c0;
                puVar14 = puVar18;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar16;
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar14 + 2);
                  uVar23 = (ushort)*puVar13;
                  uVar27 = (ulonglong)*(byte *)((longlong)puVar13 + 2);
                  uVar31 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                  uVar20 = ((ushort)*puVar14 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (((ulonglong)uVar23 & 0xf800) * uVar27 * uVar31 >>
                                                0x1b)) * 0x40 +
                                     *(short *)(&DAT_140b68970 +
                                               uVar33 * 0x100 +
                                               (((ulonglong)uVar23 & 0x7e0) * uVar27 * uVar31 >>
                                               0x15))) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              ((uVar23 & 0x1f) * uVar27 * uVar31 >> 0x10))) &
                           0xf7def7df);
                  uVar6 = uVar20 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar14 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                  if (local_c4 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  }
                }
                puVar18 = (uint *)((longlong)puVar18 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
              } while (local_e8 != 0);
            }
            else {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_1403649a0:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140364ac8;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                      uVar23 = (ushort)*puVar16;
                      uVar25 = ((ushort)*puVar18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_140b68970 +
                                                    uVar33 * 0x100 +
                                                    (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13))
                                          * 0x40 + *(short *)(&DAT_140b68970 +
                                                             uVar33 * 0x100 +
                                                             (((ulonglong)uVar23 & 0x7e0) * uVar27
                                                             >> 0xd))) * 0x20 +
                                        *(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8)))
                               & 0xf7def7df);
                      uVar20 = uVar25 & 0x8210820;
                      *(ushort *)puVar18 = (short)uVar20 - (short)(uVar20 >> 5) & (ushort)uVar25;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140364ac8;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar27 = (ulonglong)(byte)(&DAT_140c28970)[(byte)*local_e0];
                  uVar23 = (ushort)*puVar13;
                  uVar20 = ((ushort)*puVar18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (((ulonglong)uVar23 & 0xf800) * uVar27 >> 0x13)) *
                                      0x40 + *(short *)(&DAT_140b68970 +
                                                       uVar33 * 0x100 +
                                                       (((ulonglong)uVar23 & 0x7e0) * uVar27 >> 0xd)
                                                       )) * 0x20 +
                                    *(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 + ((uVar23 & 0x1f) * uVar27 >> 8))) &
                           0xf7def7df);
                  uVar6 = uVar20 & 0x8210820;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar20;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_140364cb0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_cc = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140364f08;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar15 = ((ushort)*puVar13 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  ((&DAT_140b68970)
                                                   [(ulonglong)uVar25 * 0x100 +
                                                    (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3
                                                  >> 8)) +
                                       *(short *)(&DAT_140b68970 +
                                                 uVar33 * 0x100 +
                                                 (ulonglong)
                                                 ((&DAT_140b68970)
                                                  [(ulonglong)uVar12 * 0x100 +
                                                   (ulonglong)(uVar23 >> 0xb)] * (uint)bVar3 >> 8))
                                       * 0x40) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                ((&DAT_140b68970)
                                                 [(ulonglong)uVar20 * 0x100 +
                                                  (ulonglong)(uVar23 & 0x1f)] * (uint)bVar3 >> 8)))
                             & 0xf7def7df);
                    uVar6 = uVar15 & 0x8210820;
                    *(ushort *)puVar13 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140364f08;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar14;
                    bVar3 = *(byte *)((longlong)puVar14 + 2);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar15 = ((ushort)*puVar13 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  ((&DAT_140b68970)
                                                   [(ulonglong)uVar25 * 0x100 +
                                                    (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar4 *
                                                   (uint)bVar3 >> 0x10)) +
                                       *(short *)(&DAT_140b68970 +
                                                 uVar33 * 0x100 +
                                                 (ulonglong)
                                                 ((&DAT_140b68970)
                                                  [(ulonglong)uVar12 * 0x100 +
                                                   (ulonglong)(uVar23 >> 0xb)] * (uint)bVar4 *
                                                  (uint)bVar3 >> 0x10)) * 0x40) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                ((&DAT_140b68970)
                                                 [(ulonglong)uVar20 * 0x100 +
                                                  (ulonglong)(uVar23 & 0x1f)] * (uint)bVar4 *
                                                 (uint)bVar3 >> 0x10))) & 0xf7def7df);
                    uVar6 = uVar15 & 0x8210820;
                    *(ushort *)puVar13 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140364f08;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar23 = (ushort)*puVar13;
                bVar3 = *(byte *)((longlong)puVar13 + 2);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                uVar15 = ((ushort)*puVar14 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              ((&DAT_140b68970)
                                               [(ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar4 *
                                               (uint)bVar3 >> 0x10)) +
                                   *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (ulonglong)
                                             ((&DAT_140b68970)
                                              [(ulonglong)uVar12 * 0x100 +
                                               (ulonglong)(uVar23 >> 0xb)] * (uint)bVar4 *
                                              (uint)bVar3 >> 0x10)) * 0x40) * 0x20 +
                                  *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            ((&DAT_140b68970)
                                             [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)
                                             ] * (uint)bVar4 * (uint)bVar3 >> 0x10))) & 0xf7def7df);
                uVar6 = uVar15 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
          else {
            iVar9 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_140365120:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              do {
                if ((ushort)*puVar13 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140365268;
                    iVar21 = iVar21 + -0x10000;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar29 = ((ushort)*puVar18 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_140b68970 +
                                                  uVar33 * 0x100 +
                                                  (ulonglong)
                                                  ((&DAT_140b68970)
                                                   [(ulonglong)uVar25 * 0x100 +
                                                    (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3
                                                  >> 8)) +
                                       *(short *)(&DAT_140b68970 +
                                                 uVar33 * 0x100 +
                                                 (ulonglong)
                                                 ((&DAT_140b68970)
                                                  [(ulonglong)uVar12 * 0x100 +
                                                   (ulonglong)(uVar23 >> 0xb)] * (uint)bVar3 >> 8))
                                       * 0x40) * 0x20 +
                                      *(short *)(&DAT_140b68970 +
                                                uVar33 * 0x100 +
                                                (ulonglong)
                                                ((&DAT_140b68970)
                                                 [(ulonglong)uVar20 * 0x100 +
                                                  (ulonglong)(uVar23 & 0x1f)] * (uint)bVar3 >> 8)))
                             & 0xf7def7df);
                    uVar15 = uVar29 & 0x8210820;
                    *(ushort *)puVar18 = (short)uVar15 - (short)(uVar15 >> 5) & (ushort)uVar29;
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140365268;
                    iVar21 = iVar21 + -0x10000;
                  } while (0 < iVar21);
                }
                do {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar23 = (ushort)*puVar13;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                uVar15 = ((ushort)*puVar18 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_140b68970 +
                                              uVar33 * 0x100 +
                                              (ulonglong)
                                              ((&DAT_140b68970)
                                               [(ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(uVar23 >> 5 & 0x3f)] * (uint)bVar3 >> 8)
                                              ) +
                                   *(short *)(&DAT_140b68970 +
                                             uVar33 * 0x100 +
                                             (ulonglong)
                                             ((&DAT_140b68970)
                                              [(ulonglong)uVar12 * 0x100 +
                                               (ulonglong)(uVar23 >> 0xb)] * (uint)bVar3 >> 8)) *
                                   0x40) * 0x20 +
                                  *(short *)(&DAT_140b68970 +
                                            uVar33 * 0x100 +
                                            (ulonglong)
                                            ((&DAT_140b68970)
                                             [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)
                                             ] * (uint)bVar3 >> 8))) & 0xf7def7df);
                uVar6 = uVar15 & 0x8210820;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 = (short)uVar6 - (short)(uVar6 >> 5) & (ushort)uVar15;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        break;
      case 4:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              iVar10 = iVar19;
              iVar9 = iVar19;
              iVar28 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_140366eda:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036704f;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                  else {
                    iVar10 = iVar9;
                    if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                      do {
                        uVar23 = (ushort)*puVar18;
                        uVar24 = (ushort)*puVar16;
                        *(ushort *)puVar18 =
                             (ushort)((uVar23 & 0xf800) * (uVar24 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar23 & 0x7e0) * (uVar24 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) >> 5);
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar9 + -1;
                        if (iVar10 == 0) goto LAB_14036704f;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar18;
                        uVar24 = (ushort)*puVar16;
                        bVar3 = *(byte *)((longlong)puVar16 + 2);
                        *(ushort *)puVar18 =
                             (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9
                                     ) & 0x7e0 |
                             (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3 >>
                                     2) & 0xf800 |
                             (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_14036704f;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                    }
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar24 = (ushort)*puVar13;
                  bVar3 = *(byte *)((longlong)puVar13 + 2);
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) &
                       0x7e0 | (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3
                                       >> 2) & 0xf800 |
                       (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                  if (local_c4 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1;
                      iVar28 = iVar28 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar28 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403671c0:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140367280;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      *(ushort *)puVar18 =
                           (ushort)((uVar23 & 0xf800) * (uVar24 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar23 & 0x7e0) * (uVar24 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) >> 5);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140367280;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar24 = (ushort)*puVar16;
                  *(ushort *)puVar18 =
                       (ushort)((uVar23 & 0xf800) * (uVar24 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar23 & 0x7e0) * (uVar24 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) >> 5);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            iVar10 = iVar19;
            iVar9 = iVar19;
            iVar28 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_1403673df:
              do {
                if (*(byte *)((longlong)puVar16 + 2) == 0) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_1403675a4;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_cc);
                }
                else {
                  iVar10 = iVar9;
                  if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar24 = (ushort)*puVar18;
                      *(ushort *)puVar18 =
                           (ushort)((&DAT_140b68970)
                                    [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                    (uVar24 >> 5 & 0x3f) >> 1) & 0x7e0 |
                           *(short *)(&DAT_140b68970 +
                                     (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                           (uVar24 >> 5 & 0x7c0) & 0xf800 |
                           (ushort)((&DAT_140b68970)
                                    [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                    (uVar24 & 0x1f) >> 5);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar9 + -1;
                      if (iVar10 == 0) goto LAB_1403675a4;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar16;
                      uVar24 = (ushort)*puVar18;
                      bVar3 = *(byte *)((longlong)puVar16 + 2);
                      *(ushort *)puVar18 =
                           (ushort)((&DAT_140b68970)
                                    [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                    (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                           (ushort)((&DAT_140b68970)
                                    [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                    (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                           (ushort)((&DAT_140b68970)
                                    [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                    (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403675a4;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar13;
                uVar24 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                bVar3 = *(byte *)((longlong)puVar13 + 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                              (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                              (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                              (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                if (local_c4 == 0) break;
                for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1;
                    iVar28 = iVar28 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar28 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_140367751:
              do {
                if ((ushort)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_140367850;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar16;
                    uVar24 = (ushort)*puVar18;
                    *(ushort *)puVar18 =
                         (ushort)((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                  (uVar24 >> 5 & 0x3f) >> 1) & 0x7e0 |
                         *(short *)(&DAT_140b68970 +
                                   (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                         (uVar24 >> 5 & 0x7c0) & 0xf800 |
                         (ushort)((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                  (uVar24 & 0x1f) >> 5);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_140367850;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_cc);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar13;
                uVar24 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                              (uVar24 >> 5 & 0x3f) >> 1) & 0x7e0 |
                     *(short *)(&DAT_140b68970 +
                               (ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)) *
                     (uVar24 >> 5 & 0x7c0) & 0xf800 |
                     (ushort)((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                              (uVar24 & 0x1f) >> 5);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_140366033:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_cc = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036622a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    *(ushort *)puVar13 =
                         (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) &
                         0x7e0 | (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) *
                                          (uint)bVar3 >> 2) & 0xf800 |
                         (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036622a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    bVar4 = *(byte *)((longlong)puVar14 + 2);
                    *(ushort *)puVar13 =
                         (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 *
                                  (uint)bVar4 >> 0x11) & 0x7e0 |
                         (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3 *
                                  (uint)bVar4 >> 10) & 0xf800 |
                         (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 * (uint)bVar4 >>
                                 0x15);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036622a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar14;
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar24 = (ushort)*puVar13;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                bVar4 = *(byte *)((longlong)puVar13 + 2);
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 *
                              (uint)bVar4 >> 0x11) & 0x7e0 |
                     (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3 *
                              (uint)bVar4 >> 10) & 0xf800 |
                     (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 * (uint)bVar4 >> 0x15)
                ;
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
          else {
            if (iVar21 != 0) {
LAB_140366420:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar16;
              iVar9 = iVar19;
              local_cc = iVar11;
              do {
                if ((ushort)*puVar13 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036653a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = (ushort)*puVar13;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    *(ushort *)puVar18 =
                         (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) &
                         0x7e0 | (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) *
                                          (uint)bVar3 >> 2) & 0xf800 |
                         (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036653a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            do {
              local_e0 = (uint *)local_c0;
              puVar14 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar14;
                puVar2 = (uint *)((longlong)puVar14 + 2);
                uVar24 = (ushort)*puVar13;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                local_c4 = local_c4 + -1;
                *(ushort *)puVar14 =
                     (ushort)((uVar23 >> 5 & 0x3f) * (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) &
                     0x7e0 | (ushort)((uint)(uVar23 >> 0xb) * (uint)(uVar24 >> 0xb) * (uint)bVar3 >>
                                     2) & 0xf800 |
                     (ushort)((uVar23 & 0x1f) * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                if (local_c4 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
            } while (local_e8 != 0);
          }
        }
        else if (*(int *)(lVar30 + 0x34) == 1) {
          if (iVar21 != 0) {
LAB_140366730:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_c8 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036696b;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar23 = (ushort)*puVar14;
                  uVar24 = (ushort)*puVar13;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar13 =
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036696b;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar14;
                  uVar24 = (ushort)*puVar13;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar13 =
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                (uVar24 >> 5 & 0x3f) * (uint)bVar4 * (uint)bVar3 >> 0x11) & 0x7e0 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                (uint)(uVar24 >> 0xb) * (uint)bVar4 * (uint)bVar3 >> 10) & 0xf800 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                (uVar24 & 0x1f) * (uint)bVar4 * (uint)bVar3 >> 0x15);
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036696b;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar24 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              bVar3 = *(byte *)((longlong)puVar13 + 2);
              bVar4 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                            (uVar24 >> 5 & 0x3f) * (uint)bVar4 * (uint)bVar3 >> 0x11) & 0x7e0 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)]
                            * (uint)(uVar24 >> 0xb) * (uint)bVar4 * (uint)bVar3 >> 10) & 0xf800 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)]
                            * (uVar24 & 0x1f) * (uint)bVar4 * (uint)bVar3 >> 0x15);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        else {
          if (iVar21 != 0) {
LAB_140366b80:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
            iVar9 = iVar19;
            local_cc = iVar11;
            do {
              if ((ushort)*puVar13 == uVar6) {
                do {
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140366cba;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar18;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  *(ushort *)puVar18 =
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                                (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)] *
                                (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                       (ushort)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)] *
                                (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140366cba;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              do {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          do {
            local_e0 = (uint *)local_c0;
            puVar14 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar24 = (ushort)*puVar14;
              puVar2 = (uint *)((longlong)puVar14 + 2);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              local_c4 = local_c4 + -1;
              *(ushort *)puVar14 =
                   (ushort)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar23 >> 5 & 0x3f)] *
                            (uVar24 >> 5 & 0x3f) * (uint)bVar3 >> 9) & 0x7e0 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar23 >> 0xb)]
                            * (uint)(uVar24 >> 0xb) * (uint)bVar3 >> 2) & 0xf800 |
                   (ushort)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar23 & 0x1f)]
                            * (uVar24 & 0x1f) * (uint)bVar3 >> 0xd);
              if (local_c4 == 0) break;
              for (iVar9 = iVar9 + -0x10000; puVar14 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
          } while (local_e8 != 0);
        }
        break;
      case 10:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              uVar27 = uVar33;
              iVar10 = iVar19;
              iVar9 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_14036ac5c:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036ae7c;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                  else {
                    iVar10 = iVar9;
                    if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                      do {
                        uVar23 = (ushort)*puVar18;
                        uVar24 = ~(ushort)*puVar16;
                        *(ushort *)puVar18 =
                             (*(short *)(&DAT_140ba8d70 +
                                        (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f))
                                        * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                             (*(short *)(&DAT_140ba8d70 +
                                        (longlong)
                                        (int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * 4 +
                                        uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                             *(short *)(&DAT_140ba8d70 +
                                       (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                       uVar33 * 0x800) + (uVar23 & 0x1f);
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar9 + -1;
                        if (iVar10 == 0) goto LAB_14036ae6f;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                      uVar27 = (ulonglong)DAT_140c28a88;
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar18;
                        bVar3 = *(byte *)((longlong)puVar16 + 2);
                        uVar24 = ~(ushort)*puVar16;
                        uVar6 = uVar23 & 0x1f;
                        iVar9 = (int)uVar27;
                        *(ushort *)puVar18 =
                             (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 * iVar9
                                      + (uVar23 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                             (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * iVar9 +
                                      (uVar23 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar24 & 0x1f) - uVar6) * (uint)bVar3 * iVar9 +
                                      uVar6 * 0x10000 >> 0x10);
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_14036ae6f;
                        uVar27 = (ulonglong)DAT_140c28a88;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                    }
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  bVar3 = *(byte *)((longlong)puVar16 + 2);
                  uVar24 = ~(ushort)*puVar16;
                  uVar6 = uVar23 & 0x1f;
                  iVar9 = (int)uVar33;
                  *(ushort *)puVar18 =
                       (ushort)(((uVar24 & 0xf800) - (uVar23 & 0xf800)) * (uint)bVar3 * iVar9 +
                                (uVar23 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                       (ushort)(((uVar24 & 0x7e0) - (uVar23 & 0x7e0)) * (uint)bVar3 * iVar9 +
                                (uVar23 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                       (ushort)(((uVar24 & 0x1f) - uVar6) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >>
                               0x10);
                  if (local_c4 + -1 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  local_c4 = local_c4 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_c4 = iVar19;
                iVar28 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar28 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_14036b041:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_14036b160;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = ~(ushort)*puVar16;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) *
                                      4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb))
                                      * 4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                     uVar33 * 0x800) + (uVar23 & 0x1f);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_14036b160;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar24 = ~(ushort)*puVar13;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * 4 +
                                  uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * 4
                                  + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                       *(short *)(&DAT_140ba8d70 +
                                 (longlong)(int)((uVar24 & 0x1f) - (uVar23 & 0x1f)) * 4 +
                                 uVar33 * 0x800) + (uVar23 & 0x1f);
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            uVar27 = uVar33;
            iVar10 = iVar19;
            iVar9 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14036b30e:
              do {
                if (*(byte *)((longlong)puVar16 + 2) == 0) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14036b55c;
                    local_cc = local_cc + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_cc);
                }
                else {
                  iVar10 = iVar9;
                  if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = ~(ushort)*puVar16;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar25 * 0x100 +
                                             (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f)
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)((&DAT_140b68970)
                                            [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           - (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                           (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                                          - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f)
                      ;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar9 + -1;
                      if (iVar10 == 0) goto LAB_14036b54f;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                    uVar27 = (ulonglong)DAT_140c28a88;
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar6 = (uint)uVar23;
                      bVar3 = *(byte *)((longlong)puVar16 + 2);
                      uVar24 = ~(ushort)*puVar16;
                      iVar9 = (int)uVar27;
                      *(ushort *)puVar18 =
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                    (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar9 +
                                    (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                    (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                                    (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                    (uVar6 & 0x1f)) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >> 0x10)
                           & 0x1f;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036b54f;
                      uVar27 = (ulonglong)DAT_140c28a88;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                uVar6 = (uint)uVar23;
                bVar3 = *(byte *)((longlong)puVar16 + 2);
                uVar24 = ~(ushort)*puVar16;
                iVar9 = (int)uVar33;
                *(ushort *)puVar18 =
                     (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                              (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar9 +
                              (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                     (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                              (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                              (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                     (ushort)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar6 & 0x1f)) * (uint)bVar3 * iVar9 + uVar6 * 0x10000 >> 0x10) &
                     0x1f;
                if (local_c4 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = (uint *)((longlong)puVar18 + 2);
                local_c4 = local_c4 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_c4 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar28 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_14036b733:
              do {
                if ((ushort)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14036b860;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = ~(ushort)*puVar16;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar25 * 0x100 +
                                           (ulonglong)(uVar24 >> 5 & 0x3f)] - (uVar23 >> 5 & 0x3f))
                                    * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)((&DAT_140b68970)
                                          [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                         (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                         (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                        (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_14036b860;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = ~(ushort)*puVar13;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)((&DAT_140b68970)
                                      [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)]
                                     - (uVar23 >> 5 & 0x3f)) * 4 + uVar33 * 0x800) +
                     (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)((&DAT_140b68970)
                                      [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                     (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) + (uVar23 >> 0xb))
                     * 0x800 | *(short *)(&DAT_140ba8d70 +
                                         (longlong)
                                         (int)((&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar24 & 0x1f)] - (uVar23 & 0x1f)) * 4 +
                                         uVar33 * 0x800) + (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_140369b00:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_c8 = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140369d7f;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar6 = (uint)(ushort)*puVar13;
                    uVar23 = ~(ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)(((uVar23 & 0x7e0) - ((ushort)*puVar13 & 0x7e0)) * (uint)bVar3 *
                                  iVar21 + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar23 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar3 * iVar21 +
                                  (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar23 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 +
                                  (uVar6 & 0x1f) * 0x10000 >> 0x10);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140369d6b;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = ~(ushort)*puVar14;
                    bVar3 = *(byte *)((longlong)puVar14 + 2);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)(((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * (uint)bVar4 *
                                  (uint)bVar3 * iVar21 + (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) &
                         0x7e0 | (ushort)(((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) *
                                          (uint)bVar4 * (uint)bVar3 * iVar21 +
                                          (uVar23 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (ushort)(byte)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar4 *
                                        (uint)bVar3 * iVar21 + (uVar23 & 0x1f) * 0x1000000 >> 0x18);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140369d6b;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar13;
                uVar24 = ~(ushort)*puVar14;
                bVar3 = *(byte *)((longlong)puVar14 + 2);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar13 =
                     (ushort)(((uVar24 >> 5 & 0x3f) - (uVar23 >> 5 & 0x3f)) * (uint)bVar4 *
                              (uint)bVar3 * iVar21 + (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) &
                     0x7e0 | (ushort)(((uint)(uVar24 >> 0xb) - (uint)(uVar23 >> 0xb)) * (uint)bVar4
                                      * (uint)bVar3 * iVar21 + (uVar23 & 0xfffff800) * 0x2000 >> 0xd
                                     ) & 0xf800 |
                     (ushort)(byte)(((uVar24 & 0x1f) - (uVar23 & 0x1f)) * (uint)bVar4 * (uint)bVar3
                                    * iVar21 + (uVar23 & 0x1f) * 0x1000000 >> 0x18);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
          }
          else {
            if (iVar21 != 0) {
LAB_140369fc0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              local_cc = iVar11;
              do {
                if ((ushort)*puVar14 == uVar6) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036a11a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                else {
                  do {
                    uVar20 = (uint)(ushort)*puVar13;
                    uVar23 = ~(ushort)*puVar14;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)(((uVar23 & 0x7e0) - ((ushort)*puVar13 & 0x7e0)) * (uint)bVar3 *
                                  iVar21 + (uVar20 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar23 & 0xf800) - (uVar20 & 0xf800)) * (uint)bVar3 * iVar21 +
                                  (uVar20 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar23 & 0x1f) - (uVar20 & 0x1f)) * (uint)bVar3 * iVar21 +
                                  (uVar20 & 0x1f) * 0x10000 >> 0x10);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036a11a;
                    local_cc = local_cc + -0x10000;
                  } while (0 < local_cc);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
              } while( true );
            }
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar16;
              while( true ) {
                uVar6 = (uint)(ushort)*puVar13;
                uVar23 = ~(ushort)*puVar14;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar13 =
                     (ushort)(((uVar23 & 0x7e0) - ((ushort)*puVar13 & 0x7e0)) * (uint)bVar3 * iVar21
                              + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                     (ushort)(((uVar23 & 0xf800) - (uVar6 & 0xf800)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                     (ushort)(((uVar23 & 0x1f) - (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 +
                              (uVar6 & 0x1f) * 0x10000 >> 0x10);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
          }
        }
        else if (*(int *)(lVar30 + 0x34) == 1) {
          if (iVar21 != 0) {
LAB_14036a350:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_c8 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036a61f;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = ~(ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10) &
                       0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036a60b;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar6 = (uint)uVar23;
                  uVar24 = ~(ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar6 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                              (uVar6 & 0x1f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                              uVar6 * 0x1000000 >> 0x18) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036a60b;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar6 = (uint)uVar23;
              bVar3 = *(byte *)((longlong)puVar14 + 2);
              uVar24 = ~(ushort)*puVar14;
              bVar4 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                            (uVar23 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                            (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                            (uVar6 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                   (byte)(((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                          - (uVar6 & 0x1f)) * (uint)bVar4 * (uint)bVar3 * iVar21 + uVar6 * 0x1000000
                         >> 0x18) & 0x1f;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        else {
          if (iVar21 != 0) {
LAB_14036a880:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_cc = iVar11;
            do {
              if ((ushort)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036a9fa;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar15 = (uint)uVar23;
                  uVar24 = ~(ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                                (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                                (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                                (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 + uVar15 * 0x10000 >> 0x10)
                       & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036a9fa;
                  local_cc = local_cc + -0x10000;
                } while (0 < local_cc);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_cc = local_cc + uVar7;
              } while (local_cc < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar6 = (uint)uVar23;
              uVar24 = ~(ushort)*puVar14;
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] -
                            (uVar23 >> 5 & 0x3f)) * (uint)bVar3 * iVar21 +
                            (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] -
                            (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                            (uVar6 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                   (ushort)(((&DAT_140b68970)
                             [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] -
                            (uVar6 & 0x1f)) * (uint)bVar3 * iVar21 + uVar6 * 0x10000 >> 0x10) & 0x1f
              ;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        break;
      case 0xb:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar30 + 0x34) == 1) {
              uVar27 = uVar33;
              iVar10 = iVar19;
              iVar9 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140368c0d:
                do {
                  if (*(byte *)((longlong)puVar16 + 2) == 0) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140368e5c;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_cc);
                  }
                  else {
                    iVar10 = iVar9;
                    if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                      do {
                        uVar23 = (ushort)*puVar18;
                        uVar24 = (ushort)*puVar16;
                        uVar6 = uVar23 >> 5 & 0x3f;
                        *(ushort *)puVar18 =
                             (*(short *)(&DAT_140ba8d70 +
                                        (longlong)(int)(((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6)
                                        * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                             (*(short *)(&DAT_140ba8d70 +
                                        (longlong)
                                        (int)(((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                             (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                             (uVar23 >> 0xb)) * 0x800 |
                             *(short *)(&DAT_140ba8d70 +
                                       (longlong)
                                       (int)(((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5) -
                                            (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f)
                        ;
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar9 + -1;
                        if (iVar10 == 0) goto LAB_140368e50;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                      uVar27 = (ulonglong)DAT_140c28a88;
                    }
                    else {
                      do {
                        uVar23 = (ushort)*puVar18;
                        uVar6 = (uint)uVar23;
                        uVar24 = (ushort)*puVar16;
                        bVar3 = *(byte *)((longlong)puVar16 + 2);
                        uVar20 = uVar6 & 0x1f;
                        iVar9 = (int)uVar27;
                        *(ushort *)puVar18 =
                             (ushort)((((uVar23 & 0xf800) * (uVar24 & 0xf800) >> 0x1b) -
                                      (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                                      (uVar6 & 0x7fff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((((uVar24 & 0x7e0) * (uVar6 & 0x7e0) >> 0xb) - (uVar6 & 0x7e0)
                                      ) * (uint)bVar3 * iVar9 + (uVar6 & 0xffffffe0) * 0x10000 >>
                                     0x10) & 0x7e0 |
                             (ushort)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar3 *
                                      iVar9 + uVar20 * 0x10000 >> 0x10);
                        puVar18 = (uint *)((longlong)puVar18 + 2);
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140368e50;
                        uVar27 = (ulonglong)DAT_140c28a88;
                        local_cc = local_cc + -0x10000;
                        iVar9 = iVar10;
                      } while (0 < local_cc);
                    }
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  uVar6 = (uint)uVar23;
                  uVar24 = (ushort)*puVar16;
                  bVar3 = *(byte *)((longlong)puVar16 + 2);
                  uVar20 = uVar6 & 0x1f;
                  iVar9 = (int)uVar33;
                  *(ushort *)puVar18 =
                       (ushort)((((uVar23 & 0xf800) * (uVar24 & 0xf800) >> 0x1b) -
                                (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar9 +
                                (uVar6 & 0x7fff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)((((uVar24 & 0x7e0) * (uVar6 & 0x7e0) >> 0xb) - (uVar6 & 0x7e0)) *
                                (uint)bVar3 * iVar9 + (uVar6 & 0xffffffe0) * 0x10000 >> 0x10) &
                       0x7e0 | (ushort)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar3 *
                                        iVar9 + uVar20 * 0x10000 >> 0x10);
                  if (local_c4 + -1 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                  local_c4 = local_c4 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_c4 = iVar19;
                iVar28 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar28 = iVar19;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
              if (iVar21 != 0) {
LAB_140369033:
                do {
                  if ((ushort)*puVar16 == uVar6) {
                    do {
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_140369170;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < local_cc);
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      uVar20 = uVar23 >> 5 & 0x3f;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)(int)(((uVar24 >> 5 & 0x3f) * uVar20 >> 6) - uVar20)
                                      * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)(((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                           (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                           (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)(((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5) -
                                          (uVar23 & 0x1f)) * 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar28 = iVar9 + -1;
                      if (iVar28 == 0) goto LAB_140369170;
                      local_cc = local_cc + -0x10000;
                      iVar9 = iVar28;
                    } while (0 < local_cc);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                } while( true );
              }
              do {
                while( true ) {
                  uVar23 = (ushort)*puVar18;
                  puVar2 = (uint *)((longlong)puVar18 + 2);
                  uVar24 = (ushort)*puVar13;
                  uVar6 = uVar23 >> 5 & 0x3f;
                  local_c4 = local_c4 + -1;
                  *(ushort *)puVar18 =
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)(int)(((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6) * 4 +
                                  uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                       (*(short *)(&DAT_140ba8d70 +
                                  (longlong)
                                  (int)(((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                       (uint)(uVar23 >> 0xb)) * 4 + uVar33 * 0x800) +
                       (uVar23 >> 0xb)) * 0x800 |
                       *(short *)(&DAT_140ba8d70 +
                                 (longlong)
                                 (int)(((uVar24 & 0x1f) * (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) *
                                 4 + uVar33 * 0x800) + (uVar23 & 0x1f);
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar13 = (uint *)((longlong)puVar13 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar14 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar14 = puVar18;
                puVar13 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar30 + 0x34) == 1) {
            uVar27 = uVar33;
            iVar10 = iVar19;
            iVar9 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14036931c:
              do {
                if (*(byte *)((longlong)puVar16 + 2) == 0) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14036959e;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < local_c8);
                }
                else {
                  iVar10 = iVar9;
                  if (*(byte *)((longlong)puVar16 + 2) == 0xff) {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      uVar6 = uVar23 >> 5 & 0x3f;
                      *(ushort *)puVar18 =
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)(((&DAT_140b68970)
                                             [(ulonglong)uVar25 * 0x100 +
                                              (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar6 >> 6) - uVar6
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                           (*(short *)(&DAT_140ba8d70 +
                                      (longlong)
                                      (int)(((&DAT_140b68970)
                                             [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)
                                             ] * (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)
                                           ) * 4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                           *(short *)(&DAT_140ba8d70 +
                                     (longlong)
                                     (int)(((&DAT_140b68970)
                                            [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                                            * (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * 4 +
                                     uVar33 * 0x800) + (uVar23 & 0x1f);
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar9 + -1;
                      if (iVar10 == 0) goto LAB_14036958f;
                      local_c8 = local_c8 + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_c8);
                    uVar27 = (ulonglong)DAT_140c28a88;
                  }
                  else {
                    do {
                      uVar23 = (ushort)*puVar18;
                      uVar24 = (ushort)*puVar16;
                      bVar3 = *(byte *)((longlong)puVar16 + 2);
                      uVar6 = uVar23 >> 5 & 0x3f;
                      iVar9 = (int)uVar27;
                      *(ushort *)puVar18 =
                           (ushort)((((&DAT_140b68970)
                                      [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)]
                                      * uVar6 >> 6) - uVar6) * (uint)bVar3 * iVar9 +
                                    (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)((((&DAT_140b68970)
                                      [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                      (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) *
                                    (uint)bVar3 * iVar9 + (uVar23 & 0xfffff800) * 0x20 >> 5) &
                           0xf800 | (ushort)((((&DAT_140b68970)
                                               [(ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(uVar24 & 0x1f)] * (uVar23 & 0x1f) >> 5)
                                             - (uVar23 & 0x1f)) * (uint)bVar3 * iVar9 +
                                             (uint)uVar23 * 0x10000 >> 0x10) & 0x1f;
                      puVar18 = (uint *)((longlong)puVar18 + 2);
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14036958f;
                      uVar27 = (ulonglong)DAT_140c28a88;
                      local_c8 = local_c8 + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < local_c8);
                  }
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                uVar24 = (ushort)*puVar14;
                bVar3 = *(byte *)((longlong)puVar14 + 2);
                uVar6 = uVar23 >> 5 & 0x3f;
                iVar9 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (ushort)((((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                uVar6 >> 6) - uVar6) * (uint)bVar3 * iVar9 +
                              (uVar23 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                     (ushort)((((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3 *
                              iVar9 + (uVar23 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                     (ushort)((((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * (uint)bVar3 * iVar9 +
                              (uint)uVar23 * 0x10000 >> 0x10) & 0x1f;
                if (local_c4 == 0) break;
                iVar28 = iVar28 + -0x10000;
                if (iVar28 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    iVar28 = iVar28 + uVar7;
                  } while (iVar28 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = (uint *)((longlong)puVar18 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_c4 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar28 = iVar19;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar13 = puVar16;
            if (iVar21 != 0) {
LAB_1403697a1:
              do {
                if ((ushort)*puVar16 == uVar6) {
                  do {
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_1403698f4;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar18;
                    uVar24 = (ushort)*puVar16;
                    uVar15 = uVar23 >> 5 & 0x3f;
                    *(ushort *)puVar18 =
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)(((&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar15 >> 6) - uVar15
                                         ) * 4 + uVar33 * 0x800) + (uVar23 >> 5 & 0x3f)) * 0x20 |
                         (*(short *)(&DAT_140ba8d70 +
                                    (longlong)
                                    (int)(((&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)]
                                           * (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) *
                                    4 + uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                         *(short *)(&DAT_140ba8d70 +
                                   (longlong)
                                   (int)(((&DAT_140b68970)
                                          [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                          (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * 4 +
                                   uVar33 * 0x800) + (uVar23 & 0x1f);
                    puVar18 = (uint *)((longlong)puVar18 + 2);
                    iVar28 = iVar9 + -1;
                    if (iVar28 == 0) goto LAB_1403698f4;
                    local_c8 = local_c8 + -0x10000;
                    iVar9 = iVar28;
                  } while (0 < local_c8);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            do {
              while( true ) {
                uVar23 = (ushort)*puVar18;
                puVar2 = (uint *)((longlong)puVar18 + 2);
                uVar24 = (ushort)*puVar13;
                uVar6 = uVar23 >> 5 & 0x3f;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar18 =
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)(((&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)]
                                       * uVar6 >> 6) - uVar6) * 4 + uVar33 * 0x800) +
                     (uVar23 >> 5 & 0x3f)) * 0x20 |
                     (*(short *)(&DAT_140ba8d70 +
                                (longlong)
                                (int)(((&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                       (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * 4 +
                                uVar33 * 0x800) + (uVar23 >> 0xb)) * 0x800 |
                     *(short *)(&DAT_140ba8d70 +
                               (longlong)
                               (int)(((&DAT_140b68970)
                                      [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                      (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * 4 + uVar33 * 0x800)
                     + (uVar23 & 0x1f);
                if (local_c4 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar13 = (uint *)((longlong)puVar13 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar14 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              local_c4 = iVar19;
              iVar10 = iVar11;
              puVar14 = puVar18;
              puVar13 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar30 + 0x34) == 1) {
            if (iVar21 != 0) {
LAB_1403679f0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              local_c8 = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 2) == 0) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140367cae;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    uVar20 = uVar23 >> 5 & 0x3f;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar6 = uVar23 & 0x1f;
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar20 >> 6) - uVar20) *
                                        (uint)bVar3 * iVar21 + (uVar23 & 0x7e0) * 0x800) >> 0xb) &
                         0x7e0 | (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5
                                                 ) - (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                               (uVar23 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                         (ushort)((((uVar24 & 0x1f) * uVar6 >> 5) - uVar6) * (uint)bVar3 * iVar21 +
                                  uVar6 * 0x10000 >> 0x10);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140367ca3;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    bVar3 = *(byte *)((longlong)puVar14 + 2);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    uVar20 = uVar23 & 0x1f;
                    uVar6 = uVar23 >> 5 & 0x3f;
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6) * (uint)bVar4
                                        * (uint)bVar3 * iVar21 + (uVar23 & 0x7e0) * 0x80000) >> 0x13
                                 ) & 0x7e0 |
                         (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                        (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 * iVar21
                                       + (uVar23 & 0xfffff800) * 0x2000) >> 0xd) & 0xf800 |
                         (short)(char)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar4 *
                                       (uint)bVar3 * iVar21 + uVar20 * 0x1000000 >> 0x18);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140367ca3;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + local_50);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar13;
                uVar24 = (ushort)*puVar14;
                bVar3 = *(byte *)((longlong)puVar14 + 2);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                uVar20 = uVar23 & 0x1f;
                uVar6 = uVar23 >> 5 & 0x3f;
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar13 =
                     (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar6 >> 6) - uVar6) * (uint)bVar4 *
                                    (uint)bVar3 * iVar21 + (uVar23 & 0x7e0) * 0x80000) >> 0x13) &
                     0x7e0 | (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                            (uint)(uVar23 >> 0xb)) * (uint)bVar4 * (uint)bVar3 *
                                            iVar21 + (uVar23 & 0xfffff800) * 0x2000) >> 0xd) &
                             0xf800 |
                     (short)(char)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar4 *
                                   (uint)bVar3 * iVar21 + uVar20 * 0x1000000 >> 0x18);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + local_50);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
          }
          else {
            if (iVar21 != 0) {
LAB_140367ef0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              local_c8 = iVar11;
              do {
                if ((ushort)*puVar14 == uVar6) {
                  do {
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036806c;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                else {
                  do {
                    uVar23 = (ushort)*puVar13;
                    uVar24 = (ushort)*puVar14;
                    uVar25 = uVar23 >> 5 & 0x3f;
                    uVar20 = uVar23 & 0x1f;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    *(ushort *)puVar13 =
                         (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar25 >> 6) - uVar25) *
                                        (uint)bVar3 * iVar21 + (uVar23 & 0x7e0) * 0x800) >> 0xb) &
                         0x7e0 | (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5
                                                 ) - (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                               (uVar23 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                         (ushort)((((uVar24 & 0x1f) * uVar20 >> 5) - uVar20) * (uint)bVar3 * iVar21
                                  + uVar20 * 0x10000 >> 0x10);
                    puVar13 = (uint *)((longlong)puVar13 + 2);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14036806c;
                    local_c8 = local_c8 + -0x10000;
                  } while (0 < local_c8);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_c8 = local_c8 + uVar7;
                } while (local_c8 < 1);
              } while( true );
            }
            while( true ) {
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              local_c4 = iVar19;
              iVar9 = iVar11;
              puVar14 = puVar16;
              while( true ) {
                uVar23 = (ushort)*puVar13;
                uVar24 = (ushort)*puVar14;
                uVar20 = uVar23 >> 5 & 0x3f;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                uVar6 = uVar23 & 0x1f;
                iVar21 = (int)uVar33;
                local_c4 = local_c4 + -1;
                *(ushort *)puVar13 =
                     (ushort)((int)((((uVar24 >> 5 & 0x3f) * uVar20 >> 6) - uVar20) * (uint)bVar3 *
                                    iVar21 + (uVar23 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                     (ushort)((int)((((uint)(uVar24 >> 0xb) * (uint)(uVar23 >> 0xb) >> 5) -
                                    (uint)(uVar23 >> 0xb)) * (uint)bVar3 * iVar21 +
                                   (uVar23 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                     (ushort)((((uVar24 & 0x1f) * uVar6 >> 5) - uVar6) * (uint)bVar3 * iVar21 +
                              uVar6 * 0x10000 >> 0x10);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                }
              }
              puVar18 = (uint *)((longlong)puVar18 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
            }
          }
        }
        else if (*(int *)(lVar30 + 0x34) == 1) {
          if (iVar21 != 0) {
LAB_1403682b0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_c8 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 2) == 0) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_1403685a5;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else if (*(byte *)((longlong)puVar14 + 2) == 0xff) {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar15 = (uint)uVar23;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  uVar6 = uVar23 >> 5 & 0x3f;
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                  uVar6 >> 6) - uVar6) * (uint)bVar3 * iVar21 +
                                (uVar15 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                  (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3
                                * iVar21 + (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                  (uVar15 & 0x1f) >> 5) - (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 +
                                uVar15 * 0x10000 >> 0x10) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140368593;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar24 = (ushort)*puVar14;
                  bVar3 = *(byte *)((longlong)puVar14 + 2);
                  bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                  uVar15 = (uint)uVar23;
                  uVar6 = uVar23 >> 5 & 0x3f;
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                  uVar6 >> 6) - uVar6) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                                (uVar15 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                  (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar4
                                * (uint)bVar3 * iVar21 + (uVar15 & 0xfffff800) * 0x2000 >> 0xd) &
                       0xf800 | (byte)((((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                         (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * (uint)bVar4 *
                                       (uint)bVar3 * iVar21 + uVar15 * 0x1000000 >> 0x18) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_140368593;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar24 = (ushort)*puVar14;
              bVar3 = *(byte *)((longlong)puVar14 + 2);
              bVar4 = (&DAT_140c28970)[(byte)*local_e0];
              uVar15 = (uint)uVar23;
              uVar6 = uVar23 >> 5 & 0x3f;
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar6
                             >> 6) - uVar6) * (uint)bVar4 * (uint)bVar3 * iVar21 +
                            (uVar15 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                              (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar4 *
                            (uint)bVar3 * iVar21 + (uVar15 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                   (byte)((((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)]
                            * (uVar23 & 0x1f) >> 5) - (uVar23 & 0x1f)) * (uint)bVar4 * (uint)bVar3 *
                          iVar21 + uVar15 * 0x1000000 >> 0x18) & 0x1f;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + local_50);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
        else {
          if (iVar21 != 0) {
LAB_140368810:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar9 = iVar19;
            local_c8 = iVar11;
            do {
              if ((ushort)*puVar14 == uVar6) {
                do {
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036899e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  uVar23 = (ushort)*puVar13;
                  uVar29 = (uint)uVar23;
                  uVar24 = (ushort)*puVar14;
                  uVar15 = uVar23 >> 5 & 0x3f;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  *(ushort *)puVar13 =
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] *
                                  uVar15 >> 6) - uVar15) * (uint)bVar3 * iVar21 +
                                (uVar29 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                                  (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3
                                * iVar21 + (uVar29 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                       (ushort)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                                  (uVar29 & 0x1f) >> 5) - (uVar29 & 0x1f)) * (uint)bVar3 * iVar21 +
                                uVar29 * 0x10000 >> 0x10) & 0x1f;
                  puVar13 = (uint *)((longlong)puVar13 + 2);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14036899e;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar14 = puVar16;
            while( true ) {
              uVar23 = (ushort)*puVar13;
              uVar15 = (uint)uVar23;
              uVar24 = (ushort)*puVar14;
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              uVar6 = uVar23 >> 5 & 0x3f;
              iVar21 = (int)uVar33;
              local_c4 = local_c4 + -1;
              *(ushort *)puVar13 =
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 + (ulonglong)(uVar24 >> 5 & 0x3f)] * uVar6
                             >> 6) - uVar6) * (uint)bVar3 * iVar21 + (uVar15 & 0xffffffe0) * 0x800
                           >> 0xb) & 0x7e0 |
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 + (ulonglong)(uVar24 >> 0xb)] *
                              (uint)(uVar23 >> 0xb) >> 5) - (uint)(uVar23 >> 0xb)) * (uint)bVar3 *
                            iVar21 + (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                   (ushort)((((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(uVar24 & 0x1f)] *
                              (uVar15 & 0x1f) >> 5) - (uVar15 & 0x1f)) * (uint)bVar3 * iVar21 +
                            uVar15 * 0x10000 >> 0x10) & 0x1f;
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar13 = (uint *)((longlong)puVar13 + 2);
              }
            }
            puVar18 = (uint *)((longlong)puVar18 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
          }
        }
      }
    }
  }
  else {
    if (iVar10 != 1) {
      return;
    }
    local_cc = iVar19;
    local_res10 = param_2;
    if (*(int *)(*(longlong *)(param_2 + 0x20) + 0x2c) == 1) {
      local_res18 = iVar19;
      local_e0 = puVar16;
      switch(DAT_140c28a84) {
      case 1:
        if (DAT_140c28a88 != 0xff) {
          if (DAT_140c28a88 == 0) {
            return;
          }
          if (param_5 != 0) {
            if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
              iVar10 = iVar11;
              puVar13 = puVar18;
              local_res18 = iVar9;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
              if (iVar21 == 0) {
                while( true ) {
                  while( true ) {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)(byte)*puVar18) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                                (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    local_c4 = local_c4 + -1;
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    if (local_c4 == 0) break;
                    iVar10 = iVar10 + -0x10000;
                    if (iVar10 < 1) {
                      do {
                        puVar14 = (uint *)((longlong)puVar14 + uVar32);
                        local_e0 = (uint *)((longlong)local_e0 + lVar17);
                        iVar10 = iVar10 + uVar7;
                      } while (iVar10 < 1);
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                    else {
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                    local_c0 = local_c0 + local_90;
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c4 = iVar19;
                  iVar10 = iVar11;
                  puVar13 = puVar18;
                  local_e0 = (uint *)local_c0;
                  puVar14 = puVar16;
                }
                return;
              }
LAB_14034a000:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar10 = iVar19;
              local_res18 = iVar11;
              iVar21 = iVar19;
              do {
                if ((byte)*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034a178;
                    local_res18 = local_res18 + -0x10000;
                    iVar21 = iVar10;
                  } while (0 < local_res18);
                }
                else {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)(byte)*puVar13) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                                (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4)] -
                                (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar21 + -1;
                    if (iVar10 == 0) goto LAB_14034a178;
                    local_res18 = local_res18 + -0x10000;
                    iVar21 = iVar10;
                  } while (0 < local_res18);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_res18 = local_res18 + uVar7;
                } while (local_res18 < 1);
              } while( true );
            }
            iVar10 = iVar11;
            puVar13 = puVar18;
            local_res18 = iVar9;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  local_c4 = local_c4 + -1;
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  if (local_c4 == 0) break;
                  iVar10 = iVar10 + -0x10000;
                  if (iVar10 < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar10 = iVar10 + uVar7;
                    } while (iVar10 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_c4 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar14 = puVar16;
              }
              return;
            }
LAB_140349cc3:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_140349e18;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              else {
                do {
                  *(byte *)puVar13 =
                       (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (int)uVar33 + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar13 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar13 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  if (iVar21 == 0) goto LAB_140349e18;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + local_50);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
            iVar10 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >>
                             8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  if (iVar10 + -1 == 0) break;
                  for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar10 = iVar19;
                iVar28 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
              return;
            }
LAB_14034a5d0:
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034a6c0;
                  iVar28 = iVar28 + -0x10000;
                } while (0 < iVar28);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >>
                             8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  puVar18 = puVar18 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034a6c0;
                  iVar28 = iVar28 + -0x10000;
                } while (0 < iVar28);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                iVar28 = iVar28 + uVar7;
              } while (iVar28 < 1);
            } while( true );
          }
          iVar10 = iVar19;
          iVar28 = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 == 0) {
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >> 8)
                ;
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                if (iVar10 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar10 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
            return;
          }
LAB_14034a3a0:
          do {
            if ((byte)*puVar16 == uVar6) {
              do {
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) goto LAB_14034a480;
                iVar28 = iVar28 + -0x10000;
              } while (0 < iVar28);
            }
            else {
              do {
                *(byte *)puVar18 =
                     (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >> 8)
                ;
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                puVar18 = puVar18 + 1;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) goto LAB_14034a480;
                iVar28 = iVar28 + -0x10000;
              } while (0 < iVar28);
            }
            do {
              puVar16 = (uint *)((longlong)puVar16 + uVar32);
              iVar28 = iVar28 + uVar7;
            } while (iVar28 < 1);
          } while( true );
        }
      case 0:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_res18 = iVar9;
            if (iVar21 != 0) {
LAB_14034aeb0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034af1d;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *puVar18 = *(uint *)(lVar5 + (ulonglong)(byte)*puVar16 * 4);
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034af1d;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *puVar18 = *(uint *)(lVar5 + (ulonglong)(byte)*puVar16 * 4);
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_res18 = iVar9;
            if (iVar21 != 0) {
LAB_14034b000:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034b0a0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar20 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4));
                    *(byte *)((longlong)puVar18 + 1) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4));
                    *(byte *)((longlong)puVar18 + 2) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4));
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034b0a0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar20 * 0x100 +
                              (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4));
                *(byte *)((longlong)puVar18 + 1) =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar25 * 0x100 +
                              (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4));
                *(byte *)((longlong)puVar18 + 2) =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar12 * 0x100 +
                              (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4));
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          iVar10 = iVar11;
          puVar14 = puVar18;
          puVar2 = (uint *)local_c0;
          puVar13 = puVar16;
          if (iVar21 != 0) {
LAB_14034a850:
            local_68 = local_c0;
            puVar16 = local_e0;
            iVar10 = iVar19;
            iVar28 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034a977;
                  iVar28 = iVar28 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < iVar28);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) -
                              (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[*local_68] +
                              (uint)(byte)*puVar18 * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[*local_68] +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[*local_68] +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar21 + -1;
                  if (iVar10 == 0) goto LAB_14034a977;
                  iVar28 = iVar28 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < iVar28);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_68 = local_68 + lVar17;
                iVar28 = iVar28 + uVar7;
              } while (iVar28 < 1);
            } while( true );
          }
          do {
            while( true ) {
              local_e0 = puVar2;
              puVar1 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)(((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar13 * 4) -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)(byte)*puVar18 * 0x100 >> 8);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar13 * 4) -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
              local_res18 = local_res18 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar13 * 4) -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
              if (local_res18 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar1, puVar2 = local_e0, iVar10 < 1;
                  iVar10 = iVar10 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar14 + uVar22);
            for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            local_res18 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar2 = (uint *)local_c0;
            puVar13 = puVar16;
          } while (local_e8 != 0);
        }
        else {
          iVar10 = iVar11;
          puVar14 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar13 = puVar16;
          if (iVar21 != 0) {
LAB_14034ab60:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar10 = iVar19;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034acb8;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              else {
                do {
                  *(byte *)puVar13 =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)] -
                              (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              + (uint)(byte)*puVar13 * 0x100 >> 8);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4)] -
                              (uint)*(byte *)((longlong)puVar13 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                              (uint)*(byte *)((longlong)puVar13 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 +
                                (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4)] -
                              (uint)*(byte *)((longlong)puVar13 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                              (uint)*(byte *)((longlong)puVar13 + 2) * 0x100 >> 8);
                  puVar13 = puVar13 + 1;
                  iVar10 = iVar21 + -1;
                  if (iVar10 == 0) goto LAB_14034acb8;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar20 * 0x100 +
                            (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar13 * 4)] -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)(byte)*puVar18 * 0x100 >> 8);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar25 * 0x100 +
                            (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar13 * 4)] -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar12 * 0x100 +
                            (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar13 * 4)] -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
              if (local_c4 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1; iVar10 = iVar10 + uVar7
                  ) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar14 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar13 = puVar16;
          } while (local_e8 != 0);
        }
        break;
      case 2:
        if (DAT_140c28a88 != 0) {
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              iVar28 = iVar19;
              iVar10 = iVar11;
              local_res18 = iVar9;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_14034b842:
                do {
                  if ((byte)*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_14034b920;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)));
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)),
                                    (undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar25 = uVar20 & 0x1010100;
                      *puVar18 = uVar25 - (uVar25 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                 uVar20;
                      puVar18 = puVar18 + 1;
                      iVar28 = local_cc + -1;
                      if (iVar28 == 0) goto LAB_14034b920;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                  local_res10._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)
                                 ),*(undefined1 *)
                                    (&DAT_140b68970 +
                                    uVar33 * 0x100 +
                                    (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)));
                  local_res10._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)
                                 ),(undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar6 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar20 = uVar6 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar20 - (uVar20 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar6;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar11;
                local_c4 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar28 = iVar19;
              iVar10 = iVar11;
              local_res18 = iVar9;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_14034ba81:
                do {
                  if ((byte)*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar28 = iVar28 + -1;
                      if (iVar28 == 0) goto LAB_14034bb70;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar28;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)(lVar17 + 1)]),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 +
                                            (ulonglong)
                                            *(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)]));
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)(lVar17 + 2)]),
                                    (undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar29 = uVar15 & 0x1010100;
                      *puVar18 = uVar29 - (uVar29 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                 uVar15;
                      puVar18 = puVar18 + 1;
                      iVar28 = local_cc + -1;
                      if (iVar28 == 0) goto LAB_14034bb70;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar28;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                  local_res10._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)
                                       ]),
                                *(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 +
                                        (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)]
                                 ));
                  local_res10._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)
                                       ]),(undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar6 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar15 = uVar6 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar15 - (uVar15 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar6;
                  if (local_c4 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                      iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar11;
                local_c4 = iVar19;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            local_res18 = iVar9;
            local_cc = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034b1e0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar11;
              local_cc = iVar19;
              do {
                if ((byte)*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    local_cc = local_cc + -1;
                    if (local_cc == 0) goto LAB_14034b308;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((uint)pbVar34[1] * (uint)bVar3 * iVar21 >> 0x10),
                                  (char)((uint)*pbVar34 * (uint)bVar3 * iVar21 >> 0x10));
                    local_res10._0_3_ =
                         CONCAT12((char)((uint)pbVar34[2] * (uint)bVar3 * iVar21 >> 0x10),
                                  (undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar20 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar25 = uVar20 & 0x1010100;
                    *puVar13 = uVar25 - (uVar25 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                               uVar20;
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_cc = local_cc + -1;
                    if (local_cc == 0) goto LAB_14034b308;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((uint)pbVar34[1] * (uint)bVar3 * iVar9 >> 0x10),
                              (char)((uint)*pbVar34 * (uint)bVar3 * iVar9 >> 0x10));
                local_res10._0_3_ =
                     CONCAT12((char)((uint)pbVar34[2] * (uint)bVar3 * iVar9 >> 0x10),
                              (undefined2)local_res10);
                local_res10._0_4_ = (uint)(uint3)local_res10;
                uVar6 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                uVar20 = uVar6 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar20 - (uVar20 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 | uVar6
                ;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
          else {
            local_res18 = iVar9;
            local_cc = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034b4f2:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar11;
              local_cc = iVar19;
              do {
                if ((byte)*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    local_cc = local_cc + -1;
                    if (local_cc == 0) goto LAB_14034b638;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar21 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 + (ulonglong)pbVar34[1]] *
                                         (uint)bVar3 * iVar21 >> 0x10),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)*pbVar34] *
                                         (uint)bVar3 * iVar21 >> 0x10));
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 + (ulonglong)pbVar34[2]] *
                                         (uint)bVar3 * iVar21 >> 0x10),(undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar15 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar29 = uVar15 & 0x1010100;
                    *puVar13 = uVar29 - (uVar29 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                               uVar15;
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    local_cc = local_cc + -1;
                    if (local_cc == 0) goto LAB_14034b638;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)pbVar34[1]] *
                                     (uint)bVar3 * iVar9 >> 0x10),
                              (char)((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)*pbVar34] * (uint)bVar3
                                     * iVar9 >> 0x10));
                local_res10._0_3_ =
                     CONCAT12((char)((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 + (ulonglong)pbVar34[2]] *
                                     (uint)bVar3 * iVar9 >> 0x10),(undefined2)local_res10);
                local_res10._0_4_ = (uint)(uint3)local_res10;
                uVar6 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                uVar15 = uVar6 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar15 - (uVar15 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 | uVar6
                ;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
        }
        break;
      case 3:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034c340:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034c400;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    lVar30 = local_res10;
                    lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                    local_res10._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)),
                                  *(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)));
                    local_res10._3_5_ = SUB85(lVar30,3);
                    local_res10._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)),
                                  (undefined2)local_res10);
                    uVar25 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar20 = uVar25 & 0x1010100;
                    *puVar18 = uVar20 - (uVar20 >> 8) & uVar25;
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034c400;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                lVar30 = local_res10;
                puVar2 = puVar18 + 1;
                lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                local_res10._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)),
                              *(undefined1 *)
                               (&DAT_140b68970 +
                               uVar33 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)));
                local_res10._3_5_ = SUB85(lVar30,3);
                local_res10._0_3_ =
                     CONCAT12(*(undefined1 *)
                               (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)),
                              (undefined2)local_res10);
                uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                uVar6 = uVar20 & 0x1010100;
                *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034c540:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034c620;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    lVar30 = local_res10;
                    lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                    local_res10._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   (uint)(&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)(lVar17 + 1)]),
                                  *(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   (uint)(&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 +
                                          (ulonglong)
                                          *(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)]));
                    local_res10._3_5_ = SUB85(lVar30,3);
                    local_res10._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 +
                                   (ulonglong)
                                   (uint)(&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)(lVar17 + 2)]),(undefined2)local_res10
                                 );
                    uVar29 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar15 = uVar29 & 0x1010100;
                    *puVar18 = uVar15 - (uVar15 >> 8) & uVar29;
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034c620;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                lVar30 = local_res10;
                puVar2 = puVar18 + 1;
                lVar17 = lVar5 + (ulonglong)(byte)*puVar16 * 4;
                local_res10._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_140b68970 +
                               uVar33 * 0x100 +
                               (ulonglong)
                               (uint)(&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)(lVar17 + 1)])
                              ,*(undefined1 *)
                                (&DAT_140b68970 +
                                uVar33 * 0x100 +
                                (ulonglong)
                                (uint)(&DAT_140b68970)
                                      [(ulonglong)uVar20 * 0x100 +
                                       (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)])
                             );
                local_res10._3_5_ = SUB85(lVar30,3);
                local_res10._0_3_ =
                     CONCAT12(*(undefined1 *)
                               (&DAT_140b68970 +
                               uVar33 * 0x100 +
                               (ulonglong)
                               (uint)(&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)(lVar17 + 2)])
                              ,(undefined2)local_res10);
                uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                uVar6 = uVar15 & 0x1010100;
                *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          local_e0 = (uint *)local_c0;
          local_cc = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034bd0d:
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  local_res18 = local_res18 + -1;
                  if (local_res18 == 0) goto LAB_14034be18;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              else {
                do {
                  lVar30 = local_res10;
                  pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((uint)pbVar34[1] * (uint)bVar3 * iVar21 >> 0x10),
                                (char)((uint)*pbVar34 * (uint)bVar3 * iVar21 >> 0x10));
                  local_res10._3_5_ = SUB85(lVar30,3);
                  local_res10._0_3_ =
                       CONCAT12((char)((uint)pbVar34[2] * (uint)bVar3 * iVar21 >> 0x10),
                                (undefined2)local_res10);
                  uVar25 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar20 = uVar25 & 0x1010100;
                  *puVar18 = uVar20 - (uVar20 >> 8) & uVar25;
                  puVar18 = puVar18 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_res18 = local_res18 + -1;
                  if (local_res18 == 0) goto LAB_14034be18;
                  local_c8 = local_c8 + -0x10000;
                } while (0 < local_c8);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              local_res18 = iVar9;
              lVar30 = local_res10;
              pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar9 = (int)uVar33;
              local_res10._0_2_ =
                   CONCAT11((char)((uint)pbVar34[1] * (uint)bVar3 * iVar9 >> 0x10),
                            (char)((uint)*pbVar34 * (uint)bVar3 * iVar9 >> 0x10));
              local_res10._3_5_ = SUB85(lVar30,3);
              local_res10._0_3_ =
                   CONCAT12((char)((uint)pbVar34[2] * (uint)bVar3 * iVar9 >> 0x10),
                            (undefined2)local_res10);
              uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
              uVar6 = uVar20 & 0x1010100;
              local_c4 = local_c4 + -1;
              *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
              if (local_c4 == 0) break;
              local_cc = local_cc + -0x10000;
              iVar9 = local_res18;
              if (local_cc < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (iVar9 = local_res18 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_cc = iVar11;
            local_c4 = iVar19;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        else {
          local_cc = iVar11;
          puVar13 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034bff3:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            local_c8 = iVar11;
            local_res18 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034c138;
                  local_c8 = local_c8 + -0x10000;
                  local_res18 = iVar21;
                } while (0 < local_c8);
              }
              else {
                do {
                  lVar30 = local_res10;
                  pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 + (ulonglong)pbVar34[1]] *
                                       (uint)bVar3 * iVar21 >> 0x10),
                                (char)((&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 + (ulonglong)*pbVar34] *
                                       (uint)bVar3 * iVar21 >> 0x10));
                  local_res10._3_5_ = SUB85(lVar30,3);
                  local_res10._0_3_ =
                       CONCAT12((char)((&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 + (ulonglong)pbVar34[2]] *
                                       (uint)bVar3 * iVar21 >> 0x10),(undefined2)local_res10);
                  uVar29 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar15 = uVar29 & 0x1010100;
                  *puVar13 = uVar15 - (uVar15 >> 8) & uVar29;
                  puVar13 = puVar13 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar21 = local_res18 + -1;
                  if (iVar21 == 0) goto LAB_14034c138;
                  local_c8 = local_c8 + -0x10000;
                  local_res18 = iVar21;
                } while (0 < local_c8);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_c8 = local_c8 + uVar7;
              } while (local_c8 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              lVar30 = local_res10;
              pbVar34 = (byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4);
              bVar3 = (&DAT_140c28970)[(byte)*local_e0];
              iVar9 = (int)uVar33;
              local_res10._0_2_ =
                   CONCAT11((char)((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 + (ulonglong)pbVar34[1]] * (uint)bVar3
                                   * iVar9 >> 0x10),
                            (char)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)*pbVar34]
                                   * (uint)bVar3 * iVar9 >> 0x10));
              local_res10._3_5_ = SUB85(lVar30,3);
              local_res10._0_3_ =
                   CONCAT12((char)((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 + (ulonglong)pbVar34[2]] * (uint)bVar3
                                   * iVar9 >> 0x10),(undefined2)local_res10);
              uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
              uVar6 = uVar15 & 0x1010100;
              local_c4 = local_c4 + -1;
              *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
              if (local_c4 == 0) break;
              local_cc = local_cc + -0x10000;
              if (local_cc < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  local_cc = local_cc + uVar7;
                } while (local_cc < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_cc = iVar11;
            local_c4 = iVar19;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        break;
      case 4:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034cd70:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034ce20;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) *
                                (uint)(byte)*puVar18 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034ce20;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) *
                            (uint)(byte)*puVar18 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                            (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                            (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar28 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034cf40:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034d000;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] *
                                (uint)(byte)*puVar18 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                    puVar18 = puVar18 + 1;
                    iVar28 = iVar28 + -1;
                    if (iVar28 == 0) goto LAB_14034d000;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar20 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] *
                            (uint)(byte)*puVar18 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] *
                            (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] *
                            (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                iVar28 = iVar28 + -1;
                if (iVar28 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar28 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          pbVar34 = local_c0;
          iVar26 = iVar19;
          iVar28 = iVar11;
          local_e0 = (uint *)local_c0;
          iVar10 = iVar19;
          puVar13 = puVar16;
          puVar14 = puVar18;
          if (iVar21 != 0) {
LAB_14034c7b0:
            do {
              local_e0 = puVar13;
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar26 = iVar26 + -1;
                  if (iVar26 == 0) goto LAB_14034c8a3;
                  iVar28 = iVar28 + -0x10000;
                  iVar10 = iVar26;
                } while (0 < iVar28);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] * (uint)(byte)*puVar18 >> 0x10)
                  ;
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                  puVar18 = puVar18 + 1;
                  iVar26 = iVar10 + -1;
                  if (iVar26 == 0) goto LAB_14034c8a3;
                  iVar28 = iVar28 + -0x10000;
                  iVar10 = iVar26;
                } while (0 < iVar28);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar28 = iVar28 + uVar7;
                puVar13 = local_e0;
              } while (iVar28 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (uint)(byte)*puVar18 >>
                         0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
              iVar10 = iVar10 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
              if (iVar10 == 0) break;
              for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1; iVar28 = iVar28 + uVar7
                  ) {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar14 + uVar22);
            local_e0 = (uint *)local_c0;
            puVar16 = puVar13;
            for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_e0 = (uint *)((longlong)local_e0 + local_90);
            }
            local_e8 = local_e8 + -1;
            iVar28 = iVar11;
            iVar10 = iVar19;
            local_c0 = (byte *)local_e0;
            puVar14 = puVar18;
            puVar13 = puVar16;
          } while (local_e8 != 0);
        }
        else {
          iVar10 = iVar11;
          puVar14 = puVar18;
          puVar2 = (uint *)local_c0;
          puVar13 = puVar16;
          if (iVar21 != 0) {
LAB_14034ca50:
            local_68 = local_c0;
            puVar16 = local_e0;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034cb77;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)(byte)(&DAT_140c28970)[*local_68] * (uint)(byte)*puVar18 >> 0x10
                             );
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)(byte)(&DAT_140c28970)[*local_68] *
                              (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)(byte)(&DAT_140c28970)[*local_68] *
                              (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                  puVar18 = puVar18 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034cb77;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_68 = local_68 + lVar17;
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          do {
            while( true ) {
              local_e0 = puVar2;
              puVar1 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)((&DAT_140b68970)
                          [(ulonglong)uVar20 * 0x100 +
                           (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar13 * 4)] *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (uint)(byte)*puVar18 >>
                         0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((&DAT_140b68970)
                          [(ulonglong)uVar25 * 0x100 +
                           (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar13 * 4)] *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
              local_res18 = local_res18 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((&DAT_140b68970)
                          [(ulonglong)uVar12 * 0x100 +
                           (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar13 * 4)] *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
              if (local_res18 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar1, puVar2 = local_e0, iVar10 < 1;
                  iVar10 = iVar10 + uVar7) {
                puVar13 = (uint *)((longlong)puVar13 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar14 + uVar22);
            for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            local_res18 = iVar19;
            iVar10 = iVar11;
            puVar14 = puVar18;
            puVar2 = (uint *)local_c0;
            puVar13 = puVar16;
          } while (local_e8 != 0);
        }
        break;
      case 10:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar10 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034e560:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034e650;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)(byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) -
                                (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                               >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)(byte)~*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)(byte)~*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034e650;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)(((uint)(byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >> 8)
                ;
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)(byte)~*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)(byte)~*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                if (iVar10 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar10 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar10 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034e7b0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034e8c0;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)
                                                (byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 *
                                                                         4)) - (uint)(byte)*puVar18)
                                * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)
                                                (byte)~*(byte *)(lVar5 + 1 +
                                                                (ulonglong)(byte)*puVar16 * 4)) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)
                                                (byte)~*(byte *)(lVar5 + 2 +
                                                                (ulonglong)(byte)*puVar16 * 4)) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034e8c0;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar20 * 0x100 +
                                            (ulonglong)
                                            (byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4))
                            - (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >>
                           8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar25 * 0x100 +
                                            (ulonglong)
                                            (byte)~*(byte *)(lVar5 + 1 +
                                                            (ulonglong)(byte)*puVar16 * 4)) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar12 * 0x100 +
                                            (ulonglong)
                                            (byte)~*(byte *)(lVar5 + 2 +
                                                            (ulonglong)(byte)*puVar16 * 4)) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                if (iVar10 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar10 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          iVar10 = iVar11;
          puVar13 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034de20:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar10 = iVar19;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034df98;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              else {
                do {
                  *(byte *)puVar13 =
                       (byte)(((uint)(byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (int)uVar33 + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)(((uint)(byte)~*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar13 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)(((uint)(byte)~*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) -
                              (uint)*(byte *)((longlong)puVar13 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar21 + -1;
                  if (iVar10 == 0) goto LAB_14034df98;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              *(byte *)puVar18 =
                   (byte)(((uint)(byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((uint)(byte)~*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((uint)(byte)~*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar10 = iVar10 + -0x10000;
              if (iVar10 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        else {
          iVar10 = iVar11;
          puVar13 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034e1b3:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034e338;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              else {
                do {
                  *(byte *)puVar13 =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar20 * 0x100 +
                                              (ulonglong)
                                              (byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4
                                                              )) - (uint)(byte)*puVar13) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                              (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar25 * 0x100 +
                                              (ulonglong)
                                              (byte)~*(byte *)(lVar5 + 1 +
                                                              (ulonglong)(byte)*puVar14 * 4)) -
                              (uint)*(byte *)((longlong)puVar13 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar12 * 0x100 +
                                              (ulonglong)
                                              (byte)~*(byte *)(lVar5 + 2 +
                                                              (ulonglong)(byte)*puVar14 * 4)) -
                              (uint)*(byte *)((longlong)puVar13 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  if (iVar21 == 0) goto LAB_14034e338;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              *(byte *)puVar18 =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar20 * 0x100 +
                                          (ulonglong)
                                          (byte)~*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)) -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar25 * 0x100 +
                                          (ulonglong)
                                          (byte)~*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4
                                                          )) -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar12 * 0x100 +
                                          (ulonglong)
                                          (byte)~*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4
                                                          )) -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar10 = iVar10 + -0x10000;
              if (iVar10 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        break;
      case 0xb:
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            iVar10 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034d8e0:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034d9e0;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) *
                                  (uint)bVar3 >> 8) - (uint)bVar3) * (int)uVar33 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                                  (uint)bVar3 >> 8) - (uint)bVar3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                                  (uint)bVar3 >> 8) - (uint)bVar3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034d9e0;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4) * (uint)bVar3
                             >> 8) - (uint)bVar3) * (int)uVar33 + (uint)bVar3 * 0x100 >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4) *
                              (uint)bVar3 >> 8) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100
                           >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4) *
                              (uint)bVar3 >> 8) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100
                           >> 8);
                if (iVar10 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar10 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar10 = iVar19;
            iVar28 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_14034db50:
              do {
                if ((byte)*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034dc70;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 +
                                   (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * (int)uVar33 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)]
                                  * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)]
                                  * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14034dc70;
                    iVar28 = iVar28 + -0x10000;
                  } while (0 < iVar28);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * (int)uVar33 +
                            (uint)bVar3 * 0x100 >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * DAT_140c28a88 +
                            (uint)bVar3 * 0x100 >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 +
                               (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar16 * 4)] *
                              (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * DAT_140c28a88 +
                            (uint)bVar3 * 0x100 >> 8);
                if (iVar10 + -1 == 0) break;
                for (iVar28 = iVar28 + -0x10000; iVar28 < 1; iVar28 = iVar28 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar10 = iVar19;
              iVar28 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          iVar10 = iVar11;
          puVar13 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034d160:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar10 = iVar19;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034d2e8;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              else {
                do {
                  bVar3 = (byte)*puVar13;
                  *(byte *)puVar13 =
                       (byte)((((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) * (uint)bVar3
                               >> 8) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (int)uVar33 + (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 1);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)((((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) *
                                (uint)bVar3 >> 8) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 2);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)((((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) *
                                (uint)bVar3 >> 8) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar21 + -1;
                  if (iVar10 == 0) goto LAB_14034d2e8;
                  local_res18 = local_res18 + -0x10000;
                  iVar21 = iVar10;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              bVar3 = (byte)*puVar18;
              *(byte *)puVar18 =
                   (byte)((((uint)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4) * (uint)bVar3 >>
                           8) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (int)uVar33 + (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 1);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((((uint)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4) * (uint)bVar3
                           >> 8) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 2);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((((uint)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4) * (uint)bVar3
                           >> 8) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar10 = iVar10 + -0x10000;
              if (iVar10 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        else {
          iVar10 = iVar11;
          puVar13 = puVar18;
          local_res18 = iVar9;
          local_e0 = (uint *)local_c0;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_14034d513:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            local_res18 = iVar11;
            iVar21 = iVar19;
            do {
              if ((byte)*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034d6a8;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              else {
                do {
                  bVar3 = (byte)*puVar13;
                  *(byte *)puVar13 =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)] *
                                (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 1);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4)] *
                                (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 2);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4)] *
                                (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  if (iVar21 == 0) goto LAB_14034d6a8;
                  local_res18 = local_res18 + -0x10000;
                } while (0 < local_res18);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                local_res18 = local_res18 + uVar7;
              } while (local_res18 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              bVar3 = (byte)*puVar18;
              *(byte *)puVar18 =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar20 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + (ulonglong)(byte)*puVar14 * 4)] *
                            (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 1);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + 1 + (ulonglong)(byte)*puVar14 * 4)] *
                            (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 2);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 +
                             (ulonglong)*(byte *)(lVar5 + 2 + (ulonglong)(byte)*puVar14 * 4)] *
                            (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar10 = iVar10 + -0x10000;
              if (iVar10 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
      }
    }
    else {
      switch(DAT_140c28a84) {
      case 1:
        if (DAT_140c28a88 != 0xff) {
          if (DAT_140c28a88 == 0) {
            return;
          }
          lVar5 = *(longlong *)(param_2 + 0x20);
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
              if (*(int *)(lVar5 + 0x34) != 1) {
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 == 0) {
                  while( true ) {
                    while( true ) {
                      *(byte *)puVar18 =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                  (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                                 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 +
                                    (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 +
                                    (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                      if (iVar9 + -1 == 0) break;
                      for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                        puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      }
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                    }
                    puVar18 = (uint *)((longlong)puVar13 + uVar22);
                    puVar16 = puVar14;
                    for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                        local_res18 = local_res18 + uVar8) {
                      puVar16 = (uint *)((longlong)puVar16 + local_b0);
                    }
                    local_e8 = local_e8 + -1;
                    if (local_e8 == 0) break;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar19;
                    iVar10 = iVar11;
                    puVar13 = puVar18;
                    puVar14 = puVar16;
                  }
                  return;
                }
LAB_1403501b0:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140350285;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      *(byte *)puVar18 =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                  (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                                 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar25 * 0x100 +
                                    (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((&DAT_140b68970)
                                   [(ulonglong)uVar12 * 0x100 +
                                    (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140350285;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 == 0) {
                while( true ) {
                  while( true ) {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    if (iVar9 + -1 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar19;
                  iVar10 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                }
                return;
              }
LAB_14034fe90:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035002c;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                               >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140350025;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140350025;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            if (*(int *)(lVar5 + 0x34) != 1) {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 == 0) {
                while( true ) {
                  while( true ) {
                    *(byte *)puVar18 =
                         (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    if (iVar9 + -1 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar19;
                  iVar10 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                }
                return;
              }
LAB_14034fc80:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14034fd40;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14034fd40;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
              return;
            }
LAB_14034f980:
            do {
              if (*(byte *)((longlong)puVar16 + 3) == 0) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14034fb07;
                  iVar10 = iVar10 + -0x10000;
                } while (0 < iVar10);
              }
              else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                do {
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14034fb00;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar10 + -0x10000;
                } while (0 < iVar10);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_14034fb00;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar10 + -0x10000;
                } while (0 < iVar10);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          if ((DAT_140c28a8c & 0xffffff) != 0xffffff) {
            if (*(int *)(lVar5 + 0x34) != 1) {
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 == 0) {
                while( true ) {
                  while( true ) {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] -
                                (uint)(byte)*puVar18) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                                (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    local_c4 = local_c4 + -1;
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    if (local_c4 == 0) break;
                    iVar9 = iVar9 + -0x10000;
                    if (iVar9 < 1) {
                      do {
                        puVar14 = (uint *)((longlong)puVar14 + uVar32);
                        local_e0 = (uint *)((longlong)local_e0 + lVar17);
                        iVar9 = iVar9 + uVar7;
                      } while (iVar9 < 1);
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                    else {
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                    local_c0 = local_c0 + local_90;
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  local_c4 = iVar19;
                  iVar9 = iVar11;
                  puVar13 = puVar18;
                  local_e0 = (uint *)local_c0;
                  puVar14 = puVar16;
                }
                return;
              }
LAB_14034f630:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar21 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              do {
                if (*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_14034f778;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] -
                                (uint)(byte)*puVar13) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                                (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 1)] -
                                (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 2)] -
                                (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar9 + -1;
                    if (iVar21 == 0) goto LAB_14034f778;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] -
                              (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x1000000 >> 0x18);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 +
                                (ulonglong)*(byte *)((longlong)puVar14 + 1)] -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x1000000 >> 0x18);
                  local_c4 = local_c4 + -1;
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 +
                                (ulonglong)*(byte *)((longlong)puVar14 + 2)] -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x1000000 >> 0x18);
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_c4 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar14 = puVar16;
              }
              return;
            }
LAB_14034f1b0:
            local_68 = local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 3) == 0) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_14034f40e;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              else {
                iVar21 = iVar9;
                if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] -
                                (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (int)uVar33 + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 1)] -
                                (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 2)] -
                                (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar9 + -1;
                    if (iVar21 == 0) goto LAB_14034f407;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] -
                                (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                                (uint)(byte)*puVar13 * 0x1000000 >> 0x18);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 1)] -
                                (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar14 + 2)] -
                                (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x1000000 >> 0x18);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_14034f407;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_68 = local_68 + lVar17;
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          if (*(int *)(lVar5 + 0x34) != 1) {
            pbVar34 = local_c0;
            iVar10 = iVar19;
            iVar28 = iVar11;
            iVar9 = iVar19;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 == 0) {
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              ((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  iVar9 = iVar9 + -1;
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              ((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  if (iVar9 == 0) break;
                  iVar28 = iVar28 + -0x10000;
                  if (iVar28 < 1) {
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar28 = iVar28 + uVar7;
                    } while (iVar28 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                local_e0 = (uint *)local_c0;
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_e0 = (uint *)((longlong)local_e0 + local_90);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar28 = iVar11;
                iVar9 = iVar19;
                local_c0 = (byte *)local_e0;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
              return;
            }
LAB_14034eeb0:
            do {
              if (*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034efb3;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  puVar18 = puVar18 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar10 = iVar9 + -1;
                  if (iVar10 == 0) goto LAB_14034efb3;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar28 = iVar28 + uVar7;
              } while (iVar28 < 1);
            } while( true );
          }
          pbVar34 = local_c0;
          iVar10 = iVar19;
          iVar28 = iVar11;
          iVar9 = iVar19;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 == 0) {
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                            (uint)(byte)*puVar18 * 0x1000000 >> 0x18);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)*(byte *)((longlong)puVar16 + 1) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x1000000 >> 0x18);
                iVar9 = iVar9 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)*(byte *)((longlong)puVar16 + 2) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x1000000 >> 0x18);
                if (iVar9 == 0) break;
                iVar28 = iVar28 + -0x10000;
                if (iVar28 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar28 = iVar28 + uVar7;
                  } while (iVar28 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_e0 = (uint *)local_c0;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_e0 = (uint *)((longlong)local_e0 + local_90);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar28 = iVar11;
              iVar9 = iVar19;
              local_c0 = (byte *)local_e0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
            return;
          }
LAB_14034eab0:
          do {
            if (*(byte *)((longlong)puVar16 + 3) == 0) {
              do {
                puVar18 = puVar18 + 1;
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) goto LAB_14034ecaa;
                iVar28 = iVar28 + -0x10000;
                iVar9 = iVar10;
              } while (0 < iVar28);
            }
            else {
              iVar10 = iVar9;
              if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                do {
                  *(byte *)puVar18 =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034eca3;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x1000000 >> 0x18);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x1000000 >> 0x18);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              ((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x1000000 >> 0x18);
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_14034eca3;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
            }
            do {
              puVar16 = (uint *)((longlong)puVar16 + uVar32);
              pbVar34 = pbVar34 + lVar17;
              iVar28 = iVar28 + uVar7;
            } while (iVar28 < 1);
          } while( true );
        }
      case 0:
        lVar5 = *(longlong *)(param_2 + 0x20);
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403510e0:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403511d0;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      *puVar18 = *puVar16;
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403511d0;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      *(byte *)puVar18 =
                           (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) +
                                  (uint)(byte)*puVar18 * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403511d0;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                              (uint)*(byte *)((longlong)puVar16 + 3) + (uint)(byte)*puVar18 * 0x100
                             >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140351320:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14035137d;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      *puVar18 = *puVar16;
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_14035137d;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  *puVar18 = *puVar16;
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140351480:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_1403515ad;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16);
                    *(byte *)((longlong)puVar18 + 1) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1));
                    *(byte *)((longlong)puVar18 + 2) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2));
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_1403515ad;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_1403515ad;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)(((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]
                            - (uint)(byte)*puVar18) * (uint)*(byte *)((longlong)puVar16 + 3) +
                            (uint)(byte)*puVar18 * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((&DAT_140b68970)
                             [(ulonglong)uVar25 * 0x100 +
                              (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                            (uint)*(byte *)((longlong)puVar18 + 1)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((&DAT_140b68970)
                             [(ulonglong)uVar12 * 0x100 +
                              (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                            (uint)*(byte *)((longlong)puVar18 + 2)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140351720:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035179d;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16);
                    *(byte *)((longlong)puVar18 + 1) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1));
                    *(byte *)((longlong)puVar18 + 2) =
                         *(byte *)(&DAT_140b68970 +
                                  (ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2));
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035179d;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16);
                *(byte *)((longlong)puVar18 + 1) =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar25 * 0x100 +
                              (ulonglong)*(byte *)((longlong)puVar16 + 1));
                *(byte *)((longlong)puVar18 + 2) =
                     *(byte *)(&DAT_140b68970 +
                              (ulonglong)uVar12 * 0x100 +
                              (ulonglong)*(byte *)((longlong)puVar16 + 2));
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar5 + 0x34) == 1) {
            pbVar34 = local_c0;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140350420:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403505c3;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 1) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 2) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403505c3;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 1) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 2) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403505c3;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) *
                            (uint)*(byte *)((longlong)puVar16 + 3) + (uint)(byte)*puVar18 * 0x10000
                           >> 0x10);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)*(byte *)((longlong)puVar16 + 1) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                iVar9 = iVar9 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)*(byte *)((longlong)puVar16 + 2) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                if (iVar9 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c0 = local_c0 + lVar17;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_c0 = pbVar34;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar11;
              iVar9 = iVar19;
              pbVar34 = local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            pbVar34 = local_c0;
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140350790:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140350873;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 1) -
                                (uint)*(byte *)((longlong)puVar18 + 1)) +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                ((uint)*(byte *)((longlong)puVar16 + 2) -
                                (uint)*(byte *)((longlong)puVar18 + 2)) +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140350873;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)(byte)*puVar16 - (uint)(byte)*puVar18) +
                            (uint)(byte)*puVar18 * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)*(byte *)((longlong)puVar16 + 1) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                iVar9 = iVar9 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            ((uint)*(byte *)((longlong)puVar16 + 2) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                if (iVar9 == 0) break;
                for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1;
                    iVar10 = iVar10 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c0 = local_c0 + lVar17;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_c0 = pbVar34;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar11;
              iVar9 = iVar19;
              pbVar34 = local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if (*(int *)(lVar5 + 0x34) == 1) {
          pbVar34 = local_c0;
          iVar10 = iVar19;
          iVar28 = iVar11;
          iVar9 = iVar19;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140350a30:
            do {
              if (*(byte *)((longlong)puVar16 + 3) == 0) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_140350c13;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
              else {
                iVar10 = iVar9;
                if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                                (uint)(byte)*puVar18 * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar9 + -1;
                    if (iVar10 == 0) goto LAB_140350c13;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                                (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar25 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                                (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((&DAT_140b68970)
                                 [(ulonglong)uVar12 * 0x100 +
                                  (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                                (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140350c13;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar28 = iVar28 + uVar7;
              } while (iVar28 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)(((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar16 + 3) + (uint)(byte)*puVar18 * 0x10000 >>
                         0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)]
                          - (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar16 + 3) +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
              iVar9 = iVar9 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)]
                          - (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar16 + 3) +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
              if (iVar9 == 0) break;
              for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1; iVar28 = iVar28 + uVar7
                  ) {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            local_e0 = (uint *)local_c0;
            puVar16 = puVar14;
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_e0 = (uint *)((longlong)local_e0 + local_90);
            }
            local_e8 = local_e8 + -1;
            iVar28 = iVar11;
            iVar9 = iVar19;
            local_c0 = (byte *)local_e0;
            puVar13 = puVar18;
            puVar14 = puVar16;
          } while (local_e8 != 0);
        }
        else {
          pbVar34 = local_c0;
          iVar28 = iVar19;
          iVar10 = iVar11;
          iVar9 = iVar19;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140350e00:
            do {
              if (*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar28 = iVar28 + -1;
                  if (iVar28 == 0) goto LAB_140350f03;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar28;
                } while (0 < iVar10);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                              (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                              (uint)(byte)*puVar18 * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar25 * 0x100 +
                                (ulonglong)*(byte *)((longlong)puVar16 + 1)] -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((&DAT_140b68970)
                               [(ulonglong)uVar12 * 0x100 +
                                (ulonglong)*(byte *)((longlong)puVar16 + 2)] -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  puVar18 = puVar18 + 1;
                  iVar28 = iVar9 + -1;
                  if (iVar28 == 0) goto LAB_140350f03;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar28;
                } while (0 < iVar10);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)(((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] -
                          (uint)(byte)*puVar18) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)(byte)*puVar18 * 0x100 >> 8);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)]
                          - (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
              iVar9 = iVar9 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((&DAT_140b68970)
                           [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)]
                          - (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
              if (iVar9 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1; iVar10 = iVar10 + uVar7
                  ) {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            local_e0 = (uint *)local_c0;
            puVar16 = puVar14;
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_e0 = (uint *)((longlong)local_e0 + local_90);
            }
            local_e8 = local_e8 + -1;
            iVar10 = iVar11;
            iVar9 = iVar19;
            local_c0 = (byte *)local_e0;
            puVar13 = puVar18;
            puVar14 = puVar16;
          } while (local_e8 != 0);
        }
        break;
      case 2:
        if (DAT_140c28a88 != 0) {
          lVar5 = *(longlong *)(param_2 + 0x20);
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              if (*(int *)(lVar5 + 0x34) == 1) {
                uVar27 = uVar33;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_1403527a0:
                  do {
                    if (*(byte *)((longlong)puVar16 + 3) == 0) {
                      do {
                        puVar18 = puVar18 + 1;
                        iVar9 = iVar9 + -1;
                        if (iVar9 == 0) goto LAB_140352936;
                        iVar10 = iVar10 + -0x10000;
                        local_cc = iVar9;
                      } while (0 < iVar10);
                    }
                    else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                      do {
                        local_res10._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1))
                                      ,*(undefined1 *)
                                        (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16
                                        ));
                        local_res10._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2))
                                      ,(undefined2)local_res10);
                        local_res10._0_4_ = (uint)(uint3)local_res10;
                        uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                        uVar6 = uVar20 & 0x1010100;
                        *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                   uVar20;
                        puVar18 = puVar18 + 1;
                        iVar9 = local_cc + -1;
                        if (iVar9 == 0) goto LAB_14035292f;
                        iVar10 = iVar10 + -0x10000;
                        local_cc = iVar9;
                      } while (0 < iVar10);
                      uVar27 = (ulonglong)DAT_140c28a88;
                    }
                    else {
                      do {
                        bVar3 = *(byte *)((longlong)puVar16 + 3);
                        iVar9 = (int)uVar27;
                        local_res10._0_2_ =
                             CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 *
                                             iVar9 >> 0x10),
                                      (char)((uint)(byte)*puVar16 * (uint)bVar3 * iVar9 >> 0x10));
                        local_res10._0_3_ =
                             CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 *
                                             iVar9 >> 0x10),(undefined2)local_res10);
                        local_res10._0_4_ = (uint)(uint3)local_res10;
                        uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                        uVar6 = uVar20 & 0x1010100;
                        *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                   uVar20;
                        puVar18 = puVar18 + 1;
                        iVar9 = local_cc + -1;
                        if (iVar9 == 0) goto LAB_14035292f;
                        uVar27 = (ulonglong)DAT_140c28a88;
                        iVar10 = iVar10 + -0x10000;
                        local_cc = iVar9;
                      } while (0 < iVar10);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar10 = iVar10 + uVar7;
                    } while (iVar10 < 1);
                  } while( true );
                }
                while( true ) {
                  while( true ) {
                    bVar3 = *(byte *)((longlong)puVar16 + 3);
                    iVar21 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 *
                                         iVar21 >> 0x10),
                                  (char)((uint)(byte)*puVar16 * (uint)bVar3 * iVar21 >> 0x10));
                    local_res10._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 *
                                         iVar21 >> 0x10),(undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar6 = uVar20 & 0x1010100;
                    *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                               uVar20;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) break;
                    iVar10 = iVar10 + -0x10000;
                    if (iVar10 < 1) {
                      do {
                        puVar16 = (uint *)((longlong)puVar16 + uVar32);
                        iVar10 = iVar10 + uVar7;
                      } while (iVar10 < 1);
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                    else {
                      uVar33 = (ulonglong)DAT_140c28a88;
                      puVar18 = puVar18 + 1;
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar19;
                  iVar10 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                }
              }
              else {
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_140352ab0:
                  do {
                    if (*puVar16 == uVar6) {
                      do {
                        puVar18 = puVar18 + 1;
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140352b65;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    else {
                      do {
                        local_res10._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1))
                                      ,*(undefined1 *)
                                        (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16
                                        ));
                        local_res10._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2))
                                      ,(undefined2)local_res10);
                        local_res10._0_4_ = (uint)(uint3)local_res10;
                        uVar25 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                        uVar20 = uVar25 & 0x1010100;
                        *puVar18 = uVar20 - (uVar20 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100
                                   | uVar25;
                        puVar18 = puVar18 + 1;
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_140352b65;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    puVar2 = puVar18 + 1;
                    local_res10._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)),
                                  *(undefined1 *)
                                   (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16));
                    local_res10._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)),
                                  (undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar6 = uVar20 & 0x1010100;
                    *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                               uVar20;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) break;
                    for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1;
                        iVar9 = iVar9 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar10 = iVar19;
                  iVar9 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
            }
            else if (*(int *)(lVar5 + 0x34) == 1) {
              uVar27 = uVar33;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140352cc0:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140352e98;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar10);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]))
                      ;
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                    (undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar6 = uVar15 & 0x1010100;
                      *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                 uVar15;
                      puVar18 = puVar18 + 1;
                      iVar9 = local_cc + -1;
                      if (iVar9 == 0) goto LAB_140352e85;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar10);
                    uVar27 = (ulonglong)DAT_140c28a88;
                  }
                  else {
                    do {
                      bVar3 = *(byte *)((longlong)puVar16 + 3);
                      iVar9 = (int)uVar27;
                      local_res10._0_2_ =
                           CONCAT11((char)((&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                           (uint)bVar3 * iVar9 >> 0x10),
                                    (char)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                           (uint)bVar3 * iVar9 >> 0x10));
                      local_res10._0_3_ =
                           CONCAT12((char)((&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                           (uint)bVar3 * iVar9 >> 0x10),(undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar6 = uVar15 & 0x1010100;
                      *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                 uVar15;
                      puVar18 = puVar18 + 1;
                      iVar9 = local_cc + -1;
                      if (iVar9 == 0) goto LAB_140352e85;
                      uVar27 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  bVar3 = *(byte *)((longlong)puVar16 + 3);
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 *
                                       iVar21 >> 0x10),
                                (char)((&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                       (uint)bVar3 * iVar21 >> 0x10));
                  local_res10._0_3_ =
                       CONCAT12((char)((&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 *
                                       iVar21 >> 0x10),(undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar6 = uVar15 & 0x1010100;
                  *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar15;
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140353030:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140353103;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]))
                      ;
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                    (undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar29 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar15 = uVar29 & 0x1010100;
                      *puVar18 = uVar15 - (uVar15 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                                 uVar29;
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140353103;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  local_res10._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                *(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]));
                  local_res10._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                (undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar6 = uVar15 & 0x1010100;
                  *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar15;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              local_cc = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403518f0:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar9 = iVar19;
                iVar21 = iVar11;
                local_cc = iVar19;
                do {
                  if (*(byte *)((longlong)puVar14 + 3) == 0) {
                    do {
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140351ae6;
                      iVar21 = iVar21 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar21);
                  }
                  else if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                    do {
                      bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                      iVar9 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * (uint)bVar3 *
                                           iVar9 >> 0x10),
                                    (char)((uint)(byte)*puVar14 * (uint)bVar3 * iVar9 >> 0x10));
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * (uint)bVar3 *
                                           iVar9 >> 0x10),(undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar20 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar6 = uVar20 & 0x1010100;
                      *puVar13 = uVar6 - (uVar6 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                                 uVar20;
                      puVar13 = puVar13 + 1;
                      iVar9 = local_cc + -1;
                      if (iVar9 == 0) goto LAB_140351ad8;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar21 = iVar21 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar21);
                  }
                  else {
                    do {
                      iVar9 = (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                              (uint)*(byte *)((longlong)puVar14 + 3);
                      iVar10 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * iVar9 * iVar10
                                          >> 0x18),
                                    (char)((uint)(byte)*puVar14 * iVar9 * iVar10 >> 0x18));
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * iVar9 * iVar10
                                          >> 0x18),(undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar20 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar6 = uVar20 & 0x1010100;
                      *puVar13 = uVar6 - (uVar6 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                                 uVar20;
                      puVar13 = puVar13 + 1;
                      iVar9 = local_cc + -1;
                      if (iVar9 == 0) goto LAB_140351ad8;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar21 = iVar21 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar21);
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar21 = iVar21 + uVar7;
                  } while (iVar21 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  iVar9 = (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3);
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * iVar9 * iVar21 >>
                                      0x18),(char)((uint)(byte)*puVar14 * iVar9 * iVar21 >> 0x18));
                  local_res10._0_3_ =
                       CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * iVar9 * iVar21 >>
                                      0x18),(undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar6 = uVar20 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar20;
                  if (local_c4 == 0) break;
                  local_cc = local_cc + -0x10000;
                  if (local_cc < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      local_cc = local_cc + uVar7;
                    } while (local_cc < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_cc = iVar11;
                local_c4 = iVar19;
                puVar13 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar14 = puVar16;
              }
            }
            else {
              local_cc = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140351cd0:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar9 = iVar19;
                iVar21 = iVar11;
                local_cc = iVar19;
                do {
                  if (*puVar14 == uVar6) {
                    do {
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140351de8;
                      iVar21 = iVar21 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar21);
                  }
                  else {
                    do {
                      bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                      iVar9 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * (uint)bVar3 *
                                           iVar9 >> 0x10),
                                    (char)((uint)(byte)*puVar14 * (uint)bVar3 * iVar9 >> 0x10));
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * (uint)bVar3 *
                                           iVar9 >> 0x10),(undefined2)local_res10);
                      local_res10._0_4_ = (uint)(uint3)local_res10;
                      uVar25 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                      uVar20 = uVar25 & 0x1010100;
                      *puVar13 = uVar20 - (uVar20 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                                 uVar25;
                      puVar13 = puVar13 + 1;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar9 = local_cc + -1;
                      if (iVar9 == 0) goto LAB_140351de8;
                      iVar21 = iVar21 + -0x10000;
                      local_cc = iVar9;
                    } while (0 < iVar21);
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar21 = iVar21 + uVar7;
                  } while (iVar21 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar9 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * (uint)bVar3 * iVar9
                                      >> 0x10),
                                (char)((uint)(byte)*puVar14 * (uint)bVar3 * iVar9 >> 0x10));
                  local_res10._0_3_ =
                       CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * (uint)bVar3 * iVar9
                                      >> 0x10),(undefined2)local_res10);
                  local_res10._0_4_ = (uint)(uint3)local_res10;
                  uVar20 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                  uVar6 = uVar20 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 |
                             uVar20;
                  if (local_c4 == 0) break;
                  local_cc = local_cc + -0x10000;
                  if (local_cc < 1) {
                    do {
                      puVar14 = (uint *)((longlong)puVar14 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      local_cc = local_cc + uVar7;
                    } while (local_cc < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_c0 = local_c0 + local_90;
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                local_cc = iVar11;
                local_c4 = iVar19;
                puVar13 = puVar18;
                local_e0 = (uint *)local_c0;
                puVar14 = puVar16;
              }
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            local_cc = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140351fd0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              local_cc = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 3) == 0) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_14035221e;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                else if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                  do {
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3
                                         * iVar9 >> 0x10),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar3 * iVar9 >> 0x10));
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3
                                         * iVar9 >> 0x10),(undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar15 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar6 = uVar15 & 0x1010100;
                    *puVar13 = uVar6 - (uVar6 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                               uVar15;
                    puVar13 = puVar13 + 1;
                    iVar9 = local_cc + -1;
                    if (iVar9 == 0) goto LAB_140352208;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    bVar3 = *(byte *)((longlong)puVar14 + 3);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar4
                                         * (uint)bVar3 * iVar9 >> 0x18),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar4 * (uint)bVar3 * iVar9 >> 0x18));
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar4
                                         * (uint)bVar3 * iVar9 >> 0x18),(undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar15 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar6 = uVar15 & 0x1010100;
                    *puVar13 = uVar6 - (uVar6 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                               uVar15;
                    puVar13 = puVar13 + 1;
                    iVar9 = local_cc + -1;
                    if (iVar9 == 0) goto LAB_140352208;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = *(byte *)((longlong)puVar14 + 3);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar4 *
                                     (uint)bVar3 * iVar9 >> 0x18),
                              (char)((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                     (uint)bVar4 * (uint)bVar3 * iVar9 >> 0x18));
                local_res10._0_3_ =
                     CONCAT12((char)((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar4 *
                                     (uint)bVar3 * iVar9 >> 0x18),(undefined2)local_res10);
                local_res10._0_4_ = (uint)(uint3)local_res10;
                uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                uVar6 = uVar15 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 | uVar15;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
          else {
            local_cc = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140352430:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              local_c8 = iVar19;
              do {
                if (*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140352578;
                    iVar21 = iVar21 + -0x10000;
                    local_c8 = iVar9;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3
                                         * iVar9 >> 0x10),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar3 * iVar9 >> 0x10));
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3
                                         * iVar9 >> 0x10),(undefined2)local_res10);
                    local_res10._0_4_ = (uint)(uint3)local_res10;
                    uVar29 = (*puVar13 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                    uVar15 = uVar29 & 0x1010100;
                    *puVar13 = uVar15 - (uVar15 >> 8) | (*puVar13 | (uint)local_res10) & 0x10100 |
                               uVar29;
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = local_c8 + -1;
                    if (iVar9 == 0) goto LAB_140352578;
                    iVar21 = iVar21 + -0x10000;
                    local_c8 = iVar9;
                  } while (0 < iVar21);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3 *
                                     iVar9 >> 0x10),
                              (char)((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                     (uint)bVar3 * iVar9 >> 0x10));
                local_res10._0_3_ =
                     CONCAT12((char)((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3 *
                                     iVar9 >> 0x10),(undefined2)local_res10);
                local_res10._0_4_ = (uint)(uint3)local_res10;
                uVar15 = (*puVar18 & 0xfefeff) + ((uint)local_res10 & 0xfefeff);
                uVar6 = uVar15 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar6 - (uVar6 >> 8) | (*puVar18 | (uint)local_res10) & 0x10100 | uVar15;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
        }
        break;
      case 3:
        if (DAT_140c28a88 != 0) {
          lVar5 = *(longlong *)(param_2 + 0x20);
          if (param_5 == 0) {
            if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
              if (*(int *)(lVar5 + 0x34) == 1) {
                uVar27 = uVar33;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_140354010:
                  do {
                    if (*(byte *)((longlong)puVar16 + 3) == 0) {
                      do {
                        puVar18 = puVar18 + 1;
                        iVar9 = iVar9 + -1;
                        if (iVar9 == 0) goto LAB_140354167;
                        iVar10 = iVar10 + -0x10000;
                      } while (0 < iVar10);
                    }
                    else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                      do {
                        lVar5 = local_res10;
                        local_res10._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1))
                                      ,*(undefined1 *)
                                        (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16
                                        ));
                        local_res10._3_5_ = SUB85(lVar5,3);
                        local_res10._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2))
                                      ,(undefined2)local_res10);
                        uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                        uVar6 = uVar20 & 0x1010100;
                        *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                        puVar18 = puVar18 + 1;
                        iVar9 = iVar9 + -1;
                        if (iVar9 == 0) goto LAB_140354160;
                        iVar10 = iVar10 + -0x10000;
                      } while (0 < iVar10);
                      uVar27 = (ulonglong)DAT_140c28a88;
                    }
                    else {
                      do {
                        lVar5 = local_res10;
                        bVar3 = *(byte *)((longlong)puVar16 + 3);
                        iVar21 = (int)uVar27;
                        local_res10._0_2_ =
                             CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 *
                                             iVar21 >> 0x10),
                                      (char)((uint)(byte)*puVar16 * (uint)bVar3 * iVar21 >> 0x10));
                        local_res10._3_5_ = SUB85(lVar5,3);
                        local_res10._0_3_ =
                             CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 *
                                             iVar21 >> 0x10),(undefined2)local_res10);
                        uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                        uVar6 = uVar20 & 0x1010100;
                        *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                        puVar18 = puVar18 + 1;
                        iVar9 = iVar9 + -1;
                        if (iVar9 == 0) goto LAB_140354160;
                        uVar27 = (ulonglong)DAT_140c28a88;
                        iVar10 = iVar10 + -0x10000;
                      } while (0 < iVar10);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar10 = iVar10 + uVar7;
                    } while (iVar10 < 1);
                  } while( true );
                }
                while( true ) {
                  while( true ) {
                    lVar5 = local_res10;
                    bVar3 = *(byte *)((longlong)puVar16 + 3);
                    iVar21 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 *
                                         iVar21 >> 0x10),
                                  (char)((uint)(byte)*puVar16 * (uint)bVar3 * iVar21 >> 0x10));
                    local_res10._3_5_ = SUB85(lVar5,3);
                    local_res10._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 *
                                         iVar21 >> 0x10),(undefined2)local_res10);
                    uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar6 = uVar20 & 0x1010100;
                    *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                    if (iVar9 + -1 == 0) break;
                    for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  if (local_e8 == 0) break;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar9 = iVar19;
                  iVar10 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                }
              }
              else {
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
                if (iVar21 != 0) {
LAB_1403542e0:
                  do {
                    if (*puVar16 == uVar6) {
                      do {
                        puVar18 = puVar18 + 1;
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_1403543a0;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    else {
                      do {
                        lVar5 = local_res10;
                        local_res10._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1))
                                      ,*(undefined1 *)
                                        (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16
                                        ));
                        local_res10._3_5_ = SUB85(lVar5,3);
                        local_res10._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_140b68970 +
                                       uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2))
                                      ,(undefined2)local_res10);
                        uVar25 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                        uVar20 = uVar25 & 0x1010100;
                        *puVar18 = uVar20 - (uVar20 >> 8) & uVar25;
                        puVar18 = puVar18 + 1;
                        iVar10 = iVar10 + -1;
                        if (iVar10 == 0) goto LAB_1403543a0;
                        iVar9 = iVar9 + -0x10000;
                      } while (0 < iVar9);
                    }
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                  } while( true );
                }
                do {
                  while( true ) {
                    lVar5 = local_res10;
                    puVar2 = puVar18 + 1;
                    local_res10._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)),
                                  *(undefined1 *)
                                   (&DAT_140b68970 + uVar33 * 0x100 + (ulonglong)(byte)*puVar16));
                    local_res10._3_5_ = SUB85(lVar5,3);
                    local_res10._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_140b68970 +
                                   uVar33 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)),
                                  (undefined2)local_res10);
                    uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar6 = uVar20 & 0x1010100;
                    *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) break;
                    for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1;
                        iVar9 = iVar9 + uVar7) {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    }
                  }
                  puVar18 = (uint *)((longlong)puVar13 + uVar22);
                  puVar16 = puVar14;
                  for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                      local_res18 = local_res18 + uVar8) {
                    puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  }
                  local_e8 = local_e8 + -1;
                  iVar10 = iVar19;
                  iVar9 = iVar11;
                  puVar13 = puVar18;
                  puVar14 = puVar16;
                } while (local_e8 != 0);
              }
            }
            else if (*(int *)(lVar5 + 0x34) == 1) {
              uVar27 = uVar33;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403544f0:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140354684;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      lVar5 = local_res10;
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]))
                      ;
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                    (undefined2)local_res10);
                      uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar6 = uVar15 & 0x1010100;
                      *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140354675;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                    uVar27 = (ulonglong)DAT_140c28a88;
                  }
                  else {
                    do {
                      lVar5 = local_res10;
                      bVar3 = *(byte *)((longlong)puVar16 + 3);
                      iVar21 = (int)uVar27;
                      local_res10._0_2_ =
                           CONCAT11((char)((&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                           (uint)bVar3 * iVar21 >> 0x10),
                                    (char)((&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                           (uint)bVar3 * iVar21 >> 0x10));
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12((char)((&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                           (uint)bVar3 * iVar21 >> 0x10),(undefined2)local_res10);
                      uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar6 = uVar15 & 0x1010100;
                      *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140354675;
                      uVar27 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  lVar5 = local_res10;
                  bVar3 = *(byte *)((longlong)puVar16 + 3);
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 *
                                       iVar21 >> 0x10),
                                (char)((&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                       (uint)bVar3 * iVar21 >> 0x10));
                  local_res10._3_5_ = SUB85(lVar5,3);
                  local_res10._0_3_ =
                       CONCAT12((char)((&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 *
                                       iVar21 >> 0x10),(undefined2)local_res10);
                  uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar6 = uVar15 & 0x1010100;
                  *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) break;
                  iVar10 = iVar10 + -0x10000;
                  if (iVar10 < 1) {
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      iVar10 = iVar10 + uVar7;
                    } while (iVar10 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140354820:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403548e0;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      lVar5 = local_res10;
                      local_res10._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar25 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                    *(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]))
                      ;
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_140b68970 +
                                     uVar33 * 0x100 +
                                     (ulonglong)
                                     (uint)(&DAT_140b68970)
                                           [(ulonglong)uVar12 * 0x100 +
                                            (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                    (undefined2)local_res10);
                      uVar29 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar15 = uVar29 & 0x1010100;
                      *puVar18 = uVar15 - (uVar15 >> 8) & uVar29;
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_1403548e0;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  lVar5 = local_res10;
                  puVar2 = puVar18 + 1;
                  local_res10._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar25 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 1)]),
                                *(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]));
                  local_res10._3_5_ = SUB85(lVar5,3);
                  local_res10._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_140b68970 +
                                 uVar33 * 0x100 +
                                 (ulonglong)
                                 (uint)(&DAT_140b68970)
                                       [(ulonglong)uVar12 * 0x100 +
                                        (ulonglong)*(byte *)((longlong)puVar16 + 2)]),
                                (undefined2)local_res10);
                  uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar6 = uVar15 & 0x1010100;
                  *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403532b0:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar9 = iVar19;
                iVar21 = iVar11;
                do {
                  if (*(byte *)((longlong)puVar14 + 3) == 0) {
                    do {
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_14035345f;
                      iVar21 = iVar21 + -0x10000;
                    } while (0 < iVar21);
                  }
                  else if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                    do {
                      lVar5 = local_res10;
                      bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                      iVar10 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * (uint)bVar3 *
                                           iVar10 >> 0x10),
                                    (char)((uint)(byte)*puVar14 * (uint)bVar3 * iVar10 >> 0x10));
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * (uint)bVar3 *
                                           iVar10 >> 0x10),(undefined2)local_res10);
                      uVar20 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar6 = uVar20 & 0x1010100;
                      *puVar13 = uVar6 - (uVar6 >> 8) & uVar20;
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140353458;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar21 = iVar21 + -0x10000;
                    } while (0 < iVar21);
                  }
                  else {
                    do {
                      lVar5 = local_res10;
                      iVar10 = (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                               (uint)*(byte *)((longlong)puVar14 + 3);
                      iVar28 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * iVar10 * iVar28
                                          >> 0x18),
                                    (char)((uint)(byte)*puVar14 * iVar10 * iVar28 >> 0x18));
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * iVar10 * iVar28
                                          >> 0x18),(undefined2)local_res10);
                      uVar20 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar6 = uVar20 & 0x1010100;
                      *puVar13 = uVar6 - (uVar6 >> 8) & uVar20;
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140353458;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar21 = iVar21 + -0x10000;
                    } while (0 < iVar21);
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar21 = iVar21 + uVar7;
                  } while (iVar21 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  lVar5 = local_res10;
                  iVar21 = (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                           (uint)*(byte *)((longlong)puVar16 + 3);
                  iVar10 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * iVar21 * iVar10 >>
                                      0x18),(char)((uint)(byte)*puVar16 * iVar21 * iVar10 >> 0x18));
                  local_res10._3_5_ = SUB85(lVar5,3);
                  local_res10._0_3_ =
                       CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * iVar21 * iVar10 >>
                                      0x18),(undefined2)local_res10);
                  uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar6 = uVar20 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                local_e0 = (uint *)local_c0;
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_e0 = (uint *)((longlong)local_e0 + local_90);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar11;
                local_c4 = iVar19;
                local_c0 = (byte *)local_e0;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140353630:
                local_e0 = (uint *)local_c0;
                puVar13 = puVar18;
                puVar14 = puVar16;
                iVar9 = iVar19;
                iVar21 = iVar11;
                do {
                  if (*puVar14 == uVar6) {
                    do {
                      puVar13 = puVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140353728;
                      iVar21 = iVar21 + -0x10000;
                    } while (0 < iVar21);
                  }
                  else {
                    do {
                      lVar5 = local_res10;
                      bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                      iVar10 = (int)uVar33;
                      local_res10._0_2_ =
                           CONCAT11((char)((uint)*(byte *)((longlong)puVar14 + 1) * (uint)bVar3 *
                                           iVar10 >> 0x10),
                                    (char)((uint)(byte)*puVar14 * (uint)bVar3 * iVar10 >> 0x10));
                      local_res10._3_5_ = SUB85(lVar5,3);
                      local_res10._0_3_ =
                           CONCAT12((char)((uint)*(byte *)((longlong)puVar14 + 2) * (uint)bVar3 *
                                           iVar10 >> 0x10),(undefined2)local_res10);
                      uVar25 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                      uVar20 = uVar25 & 0x1010100;
                      *puVar13 = uVar20 - (uVar20 >> 8) & uVar25;
                      puVar13 = puVar13 + 1;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140353728;
                      iVar21 = iVar21 + -0x10000;
                    } while (0 < iVar21);
                  }
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar21 = iVar21 + uVar7;
                  } while (iVar21 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  lVar5 = local_res10;
                  bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                  iVar21 = (int)uVar33;
                  local_res10._0_2_ =
                       CONCAT11((char)((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 * iVar21
                                      >> 0x10),
                                (char)((uint)(byte)*puVar16 * (uint)bVar3 * iVar21 >> 0x10));
                  local_res10._3_5_ = SUB85(lVar5,3);
                  local_res10._0_3_ =
                       CONCAT12((char)((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 * iVar21
                                      >> 0x10),(undefined2)local_res10);
                  uVar20 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                  uVar6 = uVar20 & 0x1010100;
                  local_c4 = local_c4 + -1;
                  *puVar18 = uVar6 - (uVar6 >> 8) & uVar20;
                  if (local_c4 == 0) break;
                  iVar9 = iVar9 + -0x10000;
                  if (iVar9 < 1) {
                    do {
                      puVar16 = (uint *)((longlong)puVar16 + uVar32);
                      local_e0 = (uint *)((longlong)local_e0 + lVar17);
                      iVar9 = iVar9 + uVar7;
                    } while (iVar9 < 1);
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                  else {
                    uVar33 = (ulonglong)DAT_140c28a88;
                    puVar18 = puVar18 + 1;
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                local_e0 = (uint *)local_c0;
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                  local_e0 = (uint *)((longlong)local_e0 + local_90);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar11;
                local_c4 = iVar19;
                local_c0 = (byte *)local_e0;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            local_cc = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140353900:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              local_cc = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 3) == 0) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140353b07;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                else if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                  do {
                    lVar5 = local_res10;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3
                                         * iVar9 >> 0x10),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar3 * iVar9 >> 0x10));
                    local_res10._3_5_ = SUB85(lVar5,3);
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3
                                         * iVar9 >> 0x10),(undefined2)local_res10);
                    uVar15 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar6 = uVar15 & 0x1010100;
                    *puVar13 = uVar6 - (uVar6 >> 8) & uVar15;
                    puVar13 = puVar13 + 1;
                    iVar9 = local_cc + -1;
                    if (iVar9 == 0) goto LAB_140353afc;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    lVar5 = local_res10;
                    bVar3 = *(byte *)((longlong)puVar14 + 3);
                    bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar4
                                         * (uint)bVar3 * iVar9 >> 0x18),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar4 * (uint)bVar3 * iVar9 >> 0x18));
                    local_res10._3_5_ = SUB85(lVar5,3);
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar4
                                         * (uint)bVar3 * iVar9 >> 0x18),(undefined2)local_res10);
                    uVar15 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar6 = uVar15 & 0x1010100;
                    *puVar13 = uVar6 - (uVar6 >> 8) & uVar15;
                    puVar13 = puVar13 + 1;
                    iVar9 = local_cc + -1;
                    if (iVar9 == 0) goto LAB_140353afc;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar21 + -0x10000;
                    local_cc = iVar9;
                  } while (0 < iVar21);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                lVar5 = local_res10;
                bVar3 = *(byte *)((longlong)puVar14 + 3);
                bVar4 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar4 *
                                     (uint)bVar3 * iVar9 >> 0x18),
                              (char)((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                     (uint)bVar4 * (uint)bVar3 * iVar9 >> 0x18));
                local_res10._3_5_ = SUB85(lVar5,3);
                local_res10._0_3_ =
                     CONCAT12((char)((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar4 *
                                     (uint)bVar3 * iVar9 >> 0x18),(undefined2)local_res10);
                uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                uVar6 = uVar15 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
          else {
            local_cc = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140353cf0:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar9 = iVar19;
              iVar21 = iVar11;
              local_c8 = iVar19;
              do {
                if (*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_140353e18;
                    iVar21 = iVar21 + -0x10000;
                    local_c8 = iVar9;
                  } while (0 < iVar21);
                }
                else {
                  do {
                    lVar5 = local_res10;
                    bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                    iVar9 = (int)uVar33;
                    local_res10._0_2_ =
                         CONCAT11((char)((&DAT_140b68970)
                                         [(ulonglong)uVar25 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3
                                         * iVar9 >> 0x10),
                                  (char)((&DAT_140b68970)
                                         [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                         (uint)bVar3 * iVar9 >> 0x10));
                    local_res10._3_5_ = SUB85(lVar5,3);
                    local_res10._0_3_ =
                         CONCAT12((char)((&DAT_140b68970)
                                         [(ulonglong)uVar12 * 0x100 +
                                          (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3
                                         * iVar9 >> 0x10),(undefined2)local_res10);
                    uVar29 = (*puVar13 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                    uVar15 = uVar29 & 0x1010100;
                    *puVar13 = uVar15 - (uVar15 >> 8) & uVar29;
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = local_c8 + -1;
                    if (iVar9 == 0) goto LAB_140353e18;
                    iVar21 = iVar21 + -0x10000;
                    local_c8 = iVar9;
                  } while (0 < iVar21);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar21 = iVar21 + uVar7;
                } while (iVar21 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                lVar5 = local_res10;
                bVar3 = (&DAT_140c28970)[(byte)*local_e0];
                iVar9 = (int)uVar33;
                local_res10._0_2_ =
                     CONCAT11((char)((&DAT_140b68970)
                                     [(ulonglong)uVar25 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3 *
                                     iVar9 >> 0x10),
                              (char)((&DAT_140b68970)
                                     [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                     (uint)bVar3 * iVar9 >> 0x10));
                local_res10._3_5_ = SUB85(lVar5,3);
                local_res10._0_3_ =
                     CONCAT12((char)((&DAT_140b68970)
                                     [(ulonglong)uVar12 * 0x100 +
                                      (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3 *
                                     iVar9 >> 0x10),(undefined2)local_res10);
                uVar15 = (*puVar18 | 0x1010100) - ((uint)local_res10 & 0xfefefeff);
                uVar6 = uVar15 & 0x1010100;
                local_c4 = local_c4 + -1;
                *puVar18 = uVar6 - (uVar6 >> 8) & uVar15;
                if (local_c4 == 0) break;
                local_cc = local_cc + -0x10000;
                if (local_cc < 1) {
                  do {
                    puVar14 = (uint *)((longlong)puVar14 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    local_cc = local_cc + uVar7;
                  } while (local_cc < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_cc = iVar11;
              local_c4 = iVar19;
              puVar13 = puVar18;
              local_e0 = (uint *)local_c0;
              puVar14 = puVar16;
            }
          }
        }
        break;
      case 4:
        lVar5 = *(longlong *)(param_2 + 0x20);
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140355670:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140355780;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      *(byte *)puVar18 = (byte)((uint)(byte)*puVar16 * (uint)(byte)*puVar18 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((uint)*(byte *)((longlong)puVar16 + 1) *
                                  (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((uint)*(byte *)((longlong)puVar18 + 2) *
                                  (uint)*(byte *)((longlong)puVar16 + 2) >> 8);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140355780;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      *(byte *)puVar18 =
                           (byte)((uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar16 *
                                  (uint)(byte)*puVar18 >> 0x10);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((uint)*(byte *)((longlong)puVar16 + 3) *
                                  (uint)*(byte *)((longlong)puVar16 + 1) *
                                  (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((uint)*(byte *)((longlong)puVar16 + 3) *
                                  (uint)*(byte *)((longlong)puVar18 + 2) *
                                  (uint)*(byte *)((longlong)puVar16 + 2) >> 0x10);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140355780;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  *(byte *)puVar18 =
                       (byte)((uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar16 *
                              (uint)(byte)*puVar18 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)*(byte *)((longlong)puVar16 + 3) *
                              (uint)*(byte *)((longlong)puVar16 + 1) *
                              (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)*(byte *)((longlong)puVar16 + 3) *
                              (uint)*(byte *)((longlong)puVar18 + 2) *
                              (uint)*(byte *)((longlong)puVar16 + 2) >> 0x10);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
            else {
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_1403558c0:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140355960;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  else {
                    do {
                      *(byte *)puVar18 = (byte)((uint)(byte)*puVar16 * (uint)(byte)*puVar18 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((uint)*(byte *)((longlong)puVar16 + 1) *
                                  (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((uint)*(byte *)((longlong)puVar18 + 2) *
                                  (uint)*(byte *)((longlong)puVar16 + 2) >> 8);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140355960;
                      iVar9 = iVar9 + -0x10000;
                    } while (0 < iVar9);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                } while( true );
              }
              do {
                while( true ) {
                  puVar2 = puVar18 + 1;
                  *(byte *)puVar18 = (byte)((uint)(byte)*puVar16 * (uint)(byte)*puVar18 >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)*(byte *)((longlong)puVar16 + 1) *
                              (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)*(byte *)((longlong)puVar18 + 2) *
                              (uint)*(byte *)((longlong)puVar16 + 2) >> 8);
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) break;
                  for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7)
                  {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                iVar10 = iVar19;
                iVar9 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              } while (local_e8 != 0);
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140355a80:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355ba5;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                (uint)(byte)*puVar18 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355ba5;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar18 >>
                               0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355ba5;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]
                            * (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar18 >> 0x10)
                ;
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)
                            ] * (uint)*(byte *)((longlong)puVar16 + 3) *
                            (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)
                            ] * (uint)*(byte *)((longlong)puVar16 + 3) *
                            (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140355cf0:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355d95;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                (uint)(byte)*puVar18 >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355d95;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16]
                            * (uint)(byte)*puVar18 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)
                            ] * (uint)*(byte *)((longlong)puVar18 + 1) >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)
                            ] * (uint)*(byte *)((longlong)puVar18 + 2) >> 8);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar5 + 0x34) == 1) {
            pbVar34 = local_c0;
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140354a80:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140354c13;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] * (uint)(byte)*puVar16 *
                                (uint)(byte)*puVar18 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 1) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar18 + 2) *
                                (uint)*(byte *)((longlong)puVar16 + 2) >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140354c13;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar16 *
                                (uint)(byte)*puVar18 >> 0x18);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar16 + 1) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x18);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar18 + 2) *
                                (uint)*(byte *)((longlong)puVar16 + 2) >> 0x18);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140354c13;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar16 *
                            (uint)(byte)*puVar18 >> 0x18);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) *
                            (uint)*(byte *)((longlong)puVar16 + 1) *
                            (uint)*(byte *)((longlong)puVar18 + 1) >> 0x18);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) *
                            (uint)*(byte *)((longlong)puVar18 + 2) *
                            (uint)*(byte *)((longlong)puVar16 + 2) >> 0x18);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c0 = local_c0 + lVar17;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_c0 = pbVar34;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              pbVar34 = local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
          else {
            pbVar34 = local_c0;
            iVar10 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140354dd0:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140354ea3;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] * (uint)(byte)*puVar16 *
                                (uint)(byte)*puVar18 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 1) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar18 + 2) *
                                (uint)*(byte *)((longlong)puVar16 + 2) >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140354ea3;
                    iVar9 = iVar9 + -0x10000;
                  } while (0 < iVar9);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
              } while( true );
            }
            do {
              while( true ) {
                puVar2 = puVar18 + 1;
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] * (uint)(byte)*puVar16 *
                            (uint)(byte)*puVar18 >> 0x10);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            (uint)*(byte *)((longlong)puVar16 + 1) *
                            (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[*local_c0] *
                            (uint)*(byte *)((longlong)puVar18 + 2) *
                            (uint)*(byte *)((longlong)puVar16 + 2) >> 0x10);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) break;
                for (iVar9 = iVar9 + -0x10000; puVar18 = puVar2, iVar9 < 1; iVar9 = iVar9 + uVar7) {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  local_c0 = local_c0 + lVar17;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_c0 = pbVar34;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_c0 = local_c0 + local_90;
              }
              local_e8 = local_e8 + -1;
              iVar10 = iVar19;
              iVar9 = iVar11;
              pbVar34 = local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            } while (local_e8 != 0);
          }
        }
        else if (*(int *)(lVar5 + 0x34) == 1) {
          pbVar34 = local_c0;
          iVar10 = iVar19;
          iVar28 = iVar11;
          iVar9 = iVar19;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140355040:
            do {
              if (*(byte *)((longlong)puVar16 + 3) == 0) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar10 = iVar10 + -1;
                  if (iVar10 == 0) goto LAB_140355203;
                  iVar28 = iVar28 + -0x10000;
                  iVar9 = iVar10;
                } while (0 < iVar28);
              }
              else {
                iVar10 = iVar9;
                if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] * (uint)(byte)*puVar18 >>
                               0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar9 + -1;
                    if (iVar10 == 0) goto LAB_140355203;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar18 >>
                               0x18);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar18 + 1) >> 0x18);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                (&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                                (uint)*(byte *)((longlong)puVar16 + 3) *
                                (uint)*(byte *)((longlong)puVar18 + 2) >> 0x18);
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140355203;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar28 = iVar28 + uVar7;
              } while (iVar28 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar16 + 3) * (uint)(byte)*puVar18 >> 0x18);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (&DAT_140b68970)
                          [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)]
                          * (uint)*(byte *)((longlong)puVar16 + 3) *
                          (uint)*(byte *)((longlong)puVar18 + 1) >> 0x18);
              iVar9 = iVar9 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (&DAT_140b68970)
                          [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)]
                          * (uint)*(byte *)((longlong)puVar16 + 3) *
                          (uint)*(byte *)((longlong)puVar18 + 2) >> 0x18);
              if (iVar9 == 0) break;
              for (iVar28 = iVar28 + -0x10000; puVar18 = puVar2, iVar28 < 1; iVar28 = iVar28 + uVar7
                  ) {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            local_e0 = (uint *)local_c0;
            puVar16 = puVar14;
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_e0 = (uint *)((longlong)local_e0 + local_90);
            }
            local_e8 = local_e8 + -1;
            iVar28 = iVar11;
            iVar9 = iVar19;
            local_c0 = (byte *)local_e0;
            puVar13 = puVar18;
            puVar14 = puVar16;
          } while (local_e8 != 0);
        }
        else {
          pbVar34 = local_c0;
          iVar28 = iVar19;
          iVar10 = iVar11;
          iVar9 = iVar19;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_1403553d0:
            do {
              if (*puVar16 == uVar6) {
                do {
                  puVar18 = puVar18 + 1;
                  iVar28 = iVar28 + -1;
                  if (iVar28 == 0) goto LAB_1403554b3;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar28;
                } while (0 < iVar10);
              }
              else {
                do {
                  *(byte *)puVar18 =
                       (byte)((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                              (uint)(byte)(&DAT_140c28970)[*pbVar34] * (uint)(byte)*puVar18 >> 0x10)
                  ;
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              (&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 1)] *
                              (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((uint)(byte)(&DAT_140c28970)[*pbVar34] *
                              (&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 2)] *
                              (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
                  puVar18 = puVar18 + 1;
                  iVar28 = iVar9 + -1;
                  if (iVar28 == 0) goto LAB_1403554b3;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar28;
                } while (0 < iVar10);
              }
              do {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                pbVar34 = pbVar34 + lVar17;
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          do {
            while( true ) {
              puVar2 = puVar18 + 1;
              *(byte *)puVar18 =
                   (byte)((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (uint)(byte)*puVar18 >>
                         0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (&DAT_140b68970)
                          [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 1)]
                          * (uint)*(byte *)((longlong)puVar18 + 1) >> 0x10);
              iVar9 = iVar9 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (&DAT_140b68970)
                          [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar16 + 2)]
                          * (uint)*(byte *)((longlong)puVar18 + 2) >> 0x10);
              if (iVar9 == 0) break;
              for (iVar10 = iVar10 + -0x10000; puVar18 = puVar2, iVar10 < 1; iVar10 = iVar10 + uVar7
                  ) {
                puVar16 = (uint *)((longlong)puVar16 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            local_e0 = (uint *)local_c0;
            puVar16 = puVar14;
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_e0 = (uint *)((longlong)local_e0 + local_90);
            }
            local_e8 = local_e8 + -1;
            iVar10 = iVar11;
            iVar9 = iVar19;
            local_c0 = (byte *)local_e0;
            puVar13 = puVar18;
            puVar14 = puVar16;
          } while (local_e8 != 0);
        }
        break;
      case 10:
        lVar5 = *(longlong *)(param_2 + 0x20);
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140358b70:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140358d17;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      *(byte *)puVar18 =
                           (byte)(((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33
                                  + (uint)(byte)*puVar18 * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140358d10;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      *(byte *)puVar18 =
                           (byte)(((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                                  (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140358d10;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140358eb0:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140358f90;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      *(byte *)puVar18 =
                           (byte)(((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33
                                  + (uint)(byte)*puVar18 * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                                  (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                                  (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140358f90;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  *(byte *)puVar18 =
                       (byte)(((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                              (uint)(byte)*puVar18 * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                              (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)(((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                              (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140359100:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403592db;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(byte)~(byte)*puVar16) -
                                (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                               >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 1))
                                - (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 2))
                                - (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403592d0;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(byte)~(byte)*puVar16) -
                                (uint)(byte)*puVar18) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                (int)uVar33 + (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 1))
                                - (uint)*(byte *)((longlong)puVar18 + 1)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 2))
                                - (uint)*(byte *)((longlong)puVar18 + 2)) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403592d0;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar20 * 0x100 +
                                            (ulonglong)(byte)~(byte)*puVar16) - (uint)(byte)*puVar18
                            ) * (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                            (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar25 * 0x100 +
                                            (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 1)) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar12 * 0x100 +
                                            (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 2)) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) break;
                iVar10 = iVar10 + -0x10000;
                if (iVar10 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_1403594a0:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403595a0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar18 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(byte)~(byte)*puVar16) -
                                (uint)(byte)*puVar18) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100
                               >> 8);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 1))
                                - (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 2))
                                - (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403595a0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar20 * 0x100 +
                                            (ulonglong)(byte)~(byte)*puVar16) - (uint)(byte)*puVar18
                            ) * (int)uVar33 + (uint)(byte)*puVar18 * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar25 * 0x100 +
                                            (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 1)) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x100 >> 8);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                            (ulonglong)uVar12 * 0x100 +
                                            (ulonglong)(byte)~*(byte *)((longlong)puVar16 + 2)) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x100 >> 8);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) break;
                iVar10 = iVar10 + -0x10000;
                if (iVar10 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar5 + 0x34) == 1) {
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140357b82:
              local_68 = local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar21 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              do {
                if (*(byte *)((longlong)puVar14 + 3) == 0) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_140357dde;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  iVar21 = iVar9;
                  if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                    do {
                      *(byte *)puVar13 =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~(byte)*puVar14 - (uint)(byte)*puVar13) * (int)uVar33
                                  + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                      *(byte *)((longlong)puVar13 + 1) =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~*(byte *)((longlong)puVar14 + 1) -
                                  (uint)*(byte *)((longlong)puVar13 + 1)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                      *(byte *)((longlong)puVar13 + 2) =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~*(byte *)((longlong)puVar14 + 2) -
                                  (uint)*(byte *)((longlong)puVar13 + 2)) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                      puVar13 = puVar13 + 1;
                      iVar21 = iVar9 + -1;
                      if (iVar21 == 0) goto LAB_140357dd7;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar21;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      *(byte *)puVar13 =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~(byte)*puVar14 - (uint)(byte)*puVar13) *
                                  (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                                  (uint)(byte)*puVar13 * 0x1000000 >> 0x18);
                      *(byte *)((longlong)puVar13 + 1) =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~*(byte *)((longlong)puVar14 + 1) -
                                  (uint)*(byte *)((longlong)puVar13 + 1)) *
                                  (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar13 + 1) * 0x1000000 >> 0x18);
                      *(byte *)((longlong)puVar13 + 2) =
                           (byte)((uint)(byte)(&DAT_140c28970)[*local_68] *
                                  ((uint)(byte)~*(byte *)((longlong)puVar14 + 2) -
                                  (uint)*(byte *)((longlong)puVar13 + 2)) *
                                  (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                  (uint)*(byte *)((longlong)puVar13 + 2) * 0x1000000 >> 0x18);
                      puVar13 = puVar13 + 1;
                      iVar21 = iVar21 + -1;
                      if (iVar21 == 0) goto LAB_140357dd7;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                      iVar9 = iVar21;
                    } while (0 < iVar10);
                  }
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_68 = local_68 + lVar17;
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                            (uint)(byte)*puVar18 * 0x1000000 >> 0x18);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x1000000 >> 0x18);
                local_c4 = local_c4 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x1000000 >> 0x18);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_e0 = (uint *)local_c0;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_e0 = (uint *)((longlong)local_e0 + local_90);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_c4 = iVar19;
              iVar9 = iVar11;
              local_c0 = (byte *)local_e0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar9 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140358000:
              local_e0 = (uint *)local_c0;
              puVar13 = puVar18;
              puVar14 = puVar16;
              iVar21 = iVar19;
              iVar10 = iVar11;
              iVar9 = iVar19;
              do {
                if (*puVar14 == uVar6) {
                  do {
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_14035813a;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar13 =
                         (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                                ((uint)(byte)~(byte)*puVar14 - (uint)(byte)*puVar13) * (int)uVar33 +
                                (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                                ((uint)(byte)~*(byte *)((longlong)puVar14 + 1) -
                                (uint)*(byte *)((longlong)puVar13 + 1)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                                ((uint)(byte)~*(byte *)((longlong)puVar14 + 2) -
                                (uint)*(byte *)((longlong)puVar13 + 2)) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar21 = iVar9 + -1;
                    if (iVar21 == 0) goto LAB_14035813a;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                *(byte *)puVar18 =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~(byte)*puVar16 - (uint)(byte)*puVar18) * (int)uVar33 +
                            (uint)(byte)*puVar18 * 0x10000 >> 0x10);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~*(byte *)((longlong)puVar16 + 1) -
                            (uint)*(byte *)((longlong)puVar18 + 1)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
                local_c4 = local_c4 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            ((uint)(byte)~*(byte *)((longlong)puVar16 + 2) -
                            (uint)*(byte *)((longlong)puVar18 + 2)) * DAT_140c28a88 +
                            (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
                if (local_c4 == 0) break;
                iVar9 = iVar9 + -0x10000;
                if (iVar9 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar9 = iVar9 + uVar7;
                  } while (iVar9 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_e0 = (uint *)local_c0;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_e0 = (uint *)((longlong)local_e0 + local_90);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              local_c4 = iVar19;
              iVar9 = iVar11;
              local_c0 = (byte *)local_e0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if (*(int *)(lVar5 + 0x34) == 1) {
          iVar9 = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140358350:
            local_68 = local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 3) == 0) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_1403585c2;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              else {
                iVar21 = iVar9;
                if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(byte)~(byte)*puVar14) -
                                (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (int)uVar33 + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 1))
                                - (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 2))
                                - (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_1403585b7;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    *(byte *)puVar13 =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar20 * 0x100 +
                                                (ulonglong)(byte)~(byte)*puVar14) -
                                (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                                (uint)(byte)*puVar13 * 0x1000000 >> 0x18);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar25 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 1))
                                - (uint)*(byte *)((longlong)puVar13 + 1)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                                (ulonglong)uVar12 * 0x100 +
                                                (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 2))
                                - (uint)*(byte *)((longlong)puVar13 + 2)) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)*(byte *)((longlong)puVar13 + 2) * 0x1000000 >> 0x18);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_1403585b7;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_68 = local_68 + lVar17;
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              *(byte *)puVar18 =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar20 * 0x100 +
                                          (ulonglong)(byte)~(byte)*puVar14) - (uint)(byte)*puVar18)
                          * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                          (uint)(byte)*puVar18 * 0x1000000 >> 0x18);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 1)) -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x1000000 >> 0x18);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar12 * 0x100 +
                                          (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 2)) -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x1000000 >> 0x18);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        else {
          iVar9 = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_1403587f0:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            do {
              if (*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_140358948;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              else {
                do {
                  *(byte *)puVar13 =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar20 * 0x100 +
                                              (ulonglong)(byte)~(byte)*puVar14) -
                              (uint)(byte)*puVar13) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * (int)uVar33 + (uint)(byte)*puVar13 * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar25 * 0x100 +
                                              (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 1)) -
                              (uint)*(byte *)((longlong)puVar13 + 1)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 1) * 0x10000 >> 0x10);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                              (ulonglong)uVar12 * 0x100 +
                                              (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 2)) -
                              (uint)*(byte *)((longlong)puVar13 + 2)) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                              (uint)*(byte *)((longlong)puVar13 + 2) * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar21 = iVar9 + -1;
                  if (iVar21 == 0) goto LAB_140358948;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              *(byte *)puVar18 =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar20 * 0x100 +
                                          (ulonglong)(byte)~(byte)*puVar14) - (uint)(byte)*puVar18)
                          * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                          (uint)(byte)*puVar18 * 0x10000 >> 0x10);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar25 * 0x100 +
                                          (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 1)) -
                          (uint)*(byte *)((longlong)puVar18 + 1)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 1) * 0x10000 >> 0x10);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)(((uint)*(byte *)(&DAT_140b68970 +
                                          (ulonglong)uVar12 * 0x100 +
                                          (ulonglong)(byte)~*(byte *)((longlong)puVar14 + 2)) -
                          (uint)*(byte *)((longlong)puVar18 + 2)) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)*(byte *)((longlong)puVar18 + 2) * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        break;
      case 0xb:
        lVar5 = *(longlong *)(param_2 + 0x20);
        if (param_5 == 0) {
          if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
            if (*(int *)(lVar5 + 0x34) == 1) {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140356f10:
                do {
                  if (*(byte *)((longlong)puVar16 + 3) == 0) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_1403570d7;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      bVar3 = (byte)*puVar18;
                      *(byte *)puVar18 =
                           (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                  (int)uVar33 + (uint)bVar3 * 0x100 >> 8);
                      bVar3 = *(byte *)((longlong)puVar18 + 1);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                      bVar3 = *(byte *)((longlong)puVar18 + 2);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_1403570d0;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      bVar3 = (byte)*puVar18;
                      *(byte *)puVar18 =
                           (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                                  (uint)bVar3 * 0x10000 >> 0x10);
                      bVar3 = *(byte *)((longlong)puVar18 + 1);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                  DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                      bVar3 = *(byte *)((longlong)puVar18 + 2);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                  DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_1403570d0;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  bVar3 = (byte)*puVar18;
                  *(byte *)puVar18 =
                       (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                              (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar18 + 1);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                              (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88
                              + (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar18 + 2);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                              (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88
                              + (uint)bVar3 * 0x10000 >> 0x10);
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
            else {
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
              if (iVar21 != 0) {
LAB_140357270:
                do {
                  if (*puVar16 == uVar6) {
                    do {
                      puVar18 = puVar18 + 1;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140357360;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  else {
                    do {
                      bVar3 = (byte)*puVar18;
                      *(byte *)puVar18 =
                           (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                  (int)uVar33 + (uint)bVar3 * 0x100 >> 8);
                      bVar3 = *(byte *)((longlong)puVar18 + 1);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                      bVar3 = *(byte *)((longlong)puVar18 + 2);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                      puVar18 = puVar18 + 1;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar9 = iVar9 + -1;
                      if (iVar9 == 0) goto LAB_140357360;
                      iVar10 = iVar10 + -0x10000;
                    } while (0 < iVar10);
                  }
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                } while( true );
              }
              while( true ) {
                while( true ) {
                  bVar3 = (byte)*puVar18;
                  *(byte *)puVar18 =
                       (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                              (int)uVar33 + (uint)bVar3 * 0x100 >> 8);
                  bVar3 = *(byte *)((longlong)puVar18 + 1);
                  *(byte *)((longlong)puVar18 + 1) =
                       (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                              (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                  bVar3 = *(byte *)((longlong)puVar18 + 2);
                  *(byte *)((longlong)puVar18 + 2) =
                       (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                              (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                  if (iVar9 + -1 == 0) break;
                  for (iVar10 = iVar10 + -0x10000; iVar10 < 1; iVar10 = iVar10 + uVar7) {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  }
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar18 = (uint *)((longlong)puVar13 + uVar22);
                puVar16 = puVar14;
                for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                    local_res18 = local_res18 + uVar8) {
                  puVar16 = (uint *)((longlong)puVar16 + local_b0);
                }
                local_e8 = local_e8 + -1;
                if (local_e8 == 0) break;
                uVar33 = (ulonglong)DAT_140c28a88;
                iVar9 = iVar19;
                iVar10 = iVar11;
                puVar13 = puVar18;
                puVar14 = puVar16;
              }
            }
          }
          else if (*(int *)(lVar5 + 0x34) == 1) {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_1403574e0:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403576d4;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * (int)uVar33 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403576c9;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                                (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                                (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403576c9;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] * (uint)bVar3
                              >> 8 & 0xff) - (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                            (int)uVar33 + (uint)bVar3 * 0x10000 >> 0x10);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 >> 8 &
                             0xff) - (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                            DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 >> 8 &
                             0xff) - (uint)bVar3) * (uint)*(byte *)((longlong)puVar16 + 3) *
                            DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) break;
                iVar10 = iVar10 + -0x10000;
                if (iVar10 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            iVar9 = iVar19;
            iVar10 = iVar11;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_1403578b0:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403579b0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) * (int)uVar33 +
                                (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_1403579b0;
                    iVar10 = iVar10 + -0x10000;
                  } while (0 < iVar10);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  iVar10 = iVar10 + uVar7;
                } while (iVar10 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar16] * (uint)bVar3
                              >> 8 & 0xff) - (uint)bVar3) * (int)uVar33 + (uint)bVar3 * 0x100 >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar25 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 1)] * (uint)bVar3 >> 8 &
                             0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((&DAT_140b68970)
                              [(ulonglong)uVar12 * 0x100 +
                               (ulonglong)*(byte *)((longlong)puVar16 + 2)] * (uint)bVar3 >> 8 &
                             0xff) - (uint)bVar3) * DAT_140c28a88 + (uint)bVar3 * 0x100 >> 8);
                iVar9 = iVar9 + -1;
                if (iVar9 == 0) break;
                iVar10 = iVar10 + -0x10000;
                if (iVar10 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    iVar10 = iVar10 + uVar7;
                  } while (iVar10 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar9 = iVar19;
              iVar10 = iVar11;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if ((DAT_140c28a8c & 0xffffff) == 0xffffff) {
          if (*(int *)(lVar5 + 0x34) == 1) {
            pbVar34 = local_c0;
            iVar10 = iVar19;
            iVar28 = iVar11;
            iVar9 = iVar19;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140355f10:
              do {
                if (*(byte *)((longlong)puVar16 + 3) == 0) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_14035615a;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
                else {
                  iVar10 = iVar9;
                  if (*(byte *)((longlong)puVar16 + 3) == 0xff) {
                    do {
                      bVar3 = (byte)*puVar18;
                      *(byte *)puVar18 =
                           (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                  (uint)(byte)(&DAT_140c28970)[*pbVar34] * (int)uVar33 +
                                  (uint)bVar3 * 0x10000 >> 0x10);
                      bVar3 = *(byte *)((longlong)puVar18 + 1);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                  DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                      bVar3 = *(byte *)((longlong)puVar18 + 2);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                  DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar9 + -1;
                      if (iVar10 == 0) goto LAB_140356153;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar28 = iVar28 + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < iVar28);
                  }
                  else {
                    do {
                      bVar3 = (byte)*puVar18;
                      *(byte *)puVar18 =
                           (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                  (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                                  (uint)bVar3 * 0x1000000 >> 0x18);
                      bVar3 = *(byte *)((longlong)puVar18 + 1);
                      *(byte *)((longlong)puVar18 + 1) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                  (uint)bVar3 * 0x1000000 >> 0x18);
                      bVar3 = *(byte *)((longlong)puVar18 + 2);
                      *(byte *)((longlong)puVar18 + 2) =
                           (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                  (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                  (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                                  (uint)bVar3 * 0x1000000 >> 0x18);
                      puVar18 = puVar18 + 1;
                      iVar10 = iVar10 + -1;
                      if (iVar10 == 0) goto LAB_140356153;
                      uVar33 = (ulonglong)DAT_140c28a88;
                      iVar28 = iVar28 + -0x10000;
                      iVar9 = iVar10;
                    } while (0 < iVar28);
                  }
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                            (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) * (int)uVar33 +
                            (uint)bVar3 * 0x1000000 >> 0x18);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                            (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)bVar3 * 0x1000000 >> 0x18);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                iVar9 = iVar9 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                            (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            (uint)*(byte *)((longlong)puVar16 + 3) * DAT_140c28a88 +
                            (uint)bVar3 * 0x1000000 >> 0x18);
                if (iVar9 == 0) break;
                iVar28 = iVar28 + -0x10000;
                if (iVar28 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar28 = iVar28 + uVar7;
                  } while (iVar28 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_e0 = (uint *)local_c0;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_e0 = (uint *)((longlong)local_e0 + local_90);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar28 = iVar11;
              iVar9 = iVar19;
              local_c0 = (byte *)local_e0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
          else {
            pbVar34 = local_c0;
            iVar10 = iVar19;
            iVar28 = iVar11;
            iVar9 = iVar19;
            puVar13 = puVar18;
            puVar14 = puVar16;
            if (iVar21 != 0) {
LAB_140356370:
              do {
                if (*puVar16 == uVar6) {
                  do {
                    puVar18 = puVar18 + 1;
                    iVar10 = iVar10 + -1;
                    if (iVar10 == 0) goto LAB_140356493;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar18;
                    *(byte *)puVar18 =
                         (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                                (uint)(byte)(&DAT_140c28970)[*pbVar34] * (int)uVar33 +
                                (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar18 + 1);
                    *(byte *)((longlong)puVar18 + 1) =
                         (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                                (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar18 + 2);
                    *(byte *)((longlong)puVar18 + 2) =
                         (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                                (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*pbVar34] *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    puVar18 = puVar18 + 1;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar9 + -1;
                    if (iVar10 == 0) goto LAB_140356493;
                    iVar28 = iVar28 + -0x10000;
                    iVar9 = iVar10;
                  } while (0 < iVar28);
                }
                do {
                  puVar16 = (uint *)((longlong)puVar16 + uVar32);
                  pbVar34 = pbVar34 + lVar17;
                  iVar28 = iVar28 + uVar7;
                } while (iVar28 < 1);
              } while( true );
            }
            while( true ) {
              while( true ) {
                bVar3 = (byte)*puVar18;
                *(byte *)puVar18 =
                     (byte)((((uint)(byte)*puVar16 * (uint)bVar3 >> 8) - (uint)bVar3) *
                            (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                            (uint)bVar3 * 0x10000 >> 0x10);
                bVar3 = *(byte *)((longlong)puVar18 + 1);
                *(byte *)((longlong)puVar18 + 1) =
                     (byte)((((uint)*(byte *)((longlong)puVar16 + 1) * (uint)bVar3 >> 8) -
                            (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                bVar3 = *(byte *)((longlong)puVar18 + 2);
                iVar9 = iVar9 + -1;
                *(byte *)((longlong)puVar18 + 2) =
                     (byte)((((uint)*(byte *)((longlong)puVar16 + 2) * (uint)bVar3 >> 8) -
                            (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                            DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                if (iVar9 == 0) break;
                iVar28 = iVar28 + -0x10000;
                if (iVar28 < 1) {
                  do {
                    puVar16 = (uint *)((longlong)puVar16 + uVar32);
                    local_e0 = (uint *)((longlong)local_e0 + lVar17);
                    iVar28 = iVar28 + uVar7;
                  } while (iVar28 < 1);
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
                else {
                  uVar33 = (ulonglong)DAT_140c28a88;
                  puVar18 = puVar18 + 1;
                }
              }
              puVar18 = (uint *)((longlong)puVar13 + uVar22);
              local_e0 = (uint *)local_c0;
              puVar16 = puVar14;
              for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                  local_res18 = local_res18 + uVar8) {
                puVar16 = (uint *)((longlong)puVar16 + local_b0);
                local_e0 = (uint *)((longlong)local_e0 + local_90);
              }
              local_e8 = local_e8 + -1;
              if (local_e8 == 0) break;
              uVar33 = (ulonglong)DAT_140c28a88;
              iVar28 = iVar11;
              iVar9 = iVar19;
              local_c0 = (byte *)local_e0;
              puVar13 = puVar18;
              puVar14 = puVar16;
            }
          }
        }
        else if (*(int *)(lVar5 + 0x34) == 1) {
          iVar9 = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140356692:
            local_68 = local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            do {
              if (*(byte *)((longlong)puVar14 + 3) == 0) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_140356932;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              else {
                iVar21 = iVar9;
                if (*(byte *)((longlong)puVar14 + 3) == 0xff) {
                  do {
                    bVar3 = (byte)*puVar13;
                    *(byte *)puVar13 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] * (int)uVar33 +
                                (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar13 + 1);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    bVar3 = *(byte *)((longlong)puVar13 + 2);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar9 + -1;
                    if (iVar21 == 0) goto LAB_140356927;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
                else {
                  do {
                    bVar3 = (byte)*puVar13;
                    *(byte *)puVar13 =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                  (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                                (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                                (uint)bVar3 * 0x1000000 >> 0x18);
                    bVar3 = *(byte *)((longlong)puVar13 + 1);
                    *(byte *)((longlong)puVar13 + 1) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar25 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x1000000 >> 0x18);
                    bVar3 = *(byte *)((longlong)puVar13 + 2);
                    *(byte *)((longlong)puVar13 + 2) =
                         (byte)((((&DAT_140b68970)
                                  [(ulonglong)uVar12 * 0x100 +
                                   (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3 >> 8 &
                                 0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[*local_68] *
                                (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                                (uint)bVar3 * 0x1000000 >> 0x18);
                    puVar13 = puVar13 + 1;
                    iVar21 = iVar21 + -1;
                    if (iVar21 == 0) goto LAB_140356927;
                    uVar33 = (ulonglong)DAT_140c28a88;
                    iVar10 = iVar10 + -0x10000;
                    iVar9 = iVar21;
                  } while (0 < iVar10);
                }
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_68 = local_68 + lVar17;
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              bVar3 = (byte)*puVar18;
              *(byte *)puVar18 =
                   (byte)((((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14]
                            * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * (int)uVar33 +
                          (uint)bVar3 * 0x1000000 >> 0x18);
              bVar3 = *(byte *)((longlong)puVar18 + 1);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar14 + 1)
                            ] * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                          (uint)bVar3 * 0x1000000 >> 0x18);
              bVar3 = *(byte *)((longlong)puVar18 + 2);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar14 + 2)
                            ] * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] *
                          (uint)*(byte *)((longlong)puVar14 + 3) * DAT_140c28a88 +
                          (uint)bVar3 * 0x1000000 >> 0x18);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
        else {
          iVar9 = iVar11;
          puVar13 = puVar18;
          puVar14 = puVar16;
          if (iVar21 != 0) {
LAB_140356b70:
            local_e0 = (uint *)local_c0;
            puVar13 = puVar18;
            puVar14 = puVar16;
            iVar21 = iVar19;
            iVar10 = iVar11;
            iVar9 = iVar19;
            do {
              if (*puVar14 == uVar6) {
                do {
                  puVar13 = puVar13 + 1;
                  iVar21 = iVar21 + -1;
                  if (iVar21 == 0) goto LAB_140356cd8;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              else {
                do {
                  bVar3 = (byte)*puVar13;
                  *(byte *)puVar13 =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14] *
                                (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                              (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                              (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 1);
                  *(byte *)((longlong)puVar13 + 1) =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar25 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar14 + 1)] * (uint)bVar3 >> 8 &
                               0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                  bVar3 = *(byte *)((longlong)puVar13 + 2);
                  *(byte *)((longlong)puVar13 + 2) =
                       (byte)((((&DAT_140b68970)
                                [(ulonglong)uVar12 * 0x100 +
                                 (ulonglong)*(byte *)((longlong)puVar14 + 2)] * (uint)bVar3 >> 8 &
                               0xff) - (uint)bVar3) * (uint)(byte)(&DAT_140c28970)[(byte)*local_e0]
                              * DAT_140c28a88 + (uint)bVar3 * 0x10000 >> 0x10);
                  puVar13 = puVar13 + 1;
                  uVar33 = (ulonglong)DAT_140c28a88;
                  iVar21 = iVar9 + -1;
                  if (iVar21 == 0) goto LAB_140356cd8;
                  iVar10 = iVar10 + -0x10000;
                  iVar9 = iVar21;
                } while (0 < iVar10);
              }
              do {
                puVar14 = (uint *)((longlong)puVar14 + uVar32);
                local_e0 = (uint *)((longlong)local_e0 + lVar17);
                iVar10 = iVar10 + uVar7;
              } while (iVar10 < 1);
            } while( true );
          }
          while( true ) {
            while( true ) {
              bVar3 = (byte)*puVar18;
              *(byte *)puVar18 =
                   (byte)((((&DAT_140b68970)[(ulonglong)uVar20 * 0x100 + (ulonglong)(byte)*puVar14]
                            * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * (int)uVar33 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 1);
              *(byte *)((longlong)puVar18 + 1) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar25 * 0x100 + (ulonglong)*(byte *)((longlong)puVar14 + 1)
                            ] * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              bVar3 = *(byte *)((longlong)puVar18 + 2);
              local_c4 = local_c4 + -1;
              *(byte *)((longlong)puVar18 + 2) =
                   (byte)((((&DAT_140b68970)
                            [(ulonglong)uVar12 * 0x100 + (ulonglong)*(byte *)((longlong)puVar14 + 2)
                            ] * (uint)bVar3 >> 8 & 0xff) - (uint)bVar3) *
                          (uint)(byte)(&DAT_140c28970)[(byte)*local_e0] * DAT_140c28a88 +
                          (uint)bVar3 * 0x10000 >> 0x10);
              if (local_c4 == 0) break;
              iVar9 = iVar9 + -0x10000;
              if (iVar9 < 1) {
                do {
                  puVar14 = (uint *)((longlong)puVar14 + uVar32);
                  local_e0 = (uint *)((longlong)local_e0 + lVar17);
                  iVar9 = iVar9 + uVar7;
                } while (iVar9 < 1);
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
              else {
                uVar33 = (ulonglong)DAT_140c28a88;
                puVar18 = puVar18 + 1;
              }
            }
            puVar18 = (uint *)((longlong)puVar13 + uVar22);
            for (local_res18 = local_res18 + -0x10000; local_res18 < 1;
                local_res18 = local_res18 + uVar8) {
              puVar16 = (uint *)((longlong)puVar16 + local_b0);
              local_c0 = local_c0 + local_90;
            }
            local_e8 = local_e8 + -1;
            if (local_e8 == 0) break;
            uVar33 = (ulonglong)DAT_140c28a88;
            local_c4 = iVar19;
            iVar9 = iVar11;
            puVar13 = puVar18;
            local_e0 = (uint *)local_c0;
            puVar14 = puVar16;
          }
        }
      }
    }
  }
  return;
LAB_1403579b0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403578b0;
LAB_1403576c9:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_1403576d4:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403574e0;
LAB_140357360:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140357270;
LAB_1403570d0:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_1403570d7:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140356f10;
LAB_140356cd8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140356b70;
LAB_140356927:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140356932:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140356692;
LAB_140356493:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140356370;
LAB_140356153:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035615a:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140355f10;
LAB_1403595a0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403594a0;
LAB_1403592d0:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_1403592db:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140359100;
LAB_140358f90:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140358eb0;
LAB_140358d10:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140358d17:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140358b70;
LAB_140358948:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403587f0;
LAB_1403585b7:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_1403585c2:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140358350;
LAB_14035813a:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140358000;
LAB_140357dd7:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140357dde:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140357b82;
LAB_140355d95:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140355cf0;
LAB_140355ba5:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140355a80;
LAB_140355960:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403558c0;
LAB_140355780:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140355670;
LAB_1403554b3:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403553d0;
LAB_140355203:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140355040;
LAB_140354ea3:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140354dd0;
LAB_140354c13:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140354a80;
LAB_1403548e0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140354820;
LAB_140354675:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140354684:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403544f0;
LAB_1403543a0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403542e0;
LAB_140354160:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140354167:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140354010;
LAB_140353e18:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140353cf0;
LAB_140353afc:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140353b07:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140353900;
LAB_140353728:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140353630;
LAB_140353458:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035345f:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403532b0;
LAB_140352578:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140352430;
LAB_140352208:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035221e:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140351fd0;
LAB_140351de8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140351cd0;
LAB_140351ad8:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140351ae6:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403518f0;
LAB_140353103:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140353030;
LAB_140352e85:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140352e98:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  local_cc = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140352cc0;
LAB_140352b65:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140352ab0;
LAB_14035292f:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140352936:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  local_cc = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403527a0;
LAB_140350285:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403501b0;
LAB_140350025:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035002c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034fe90;
LAB_14034fd40:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034fc80;
LAB_14034fb00:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14034fb07:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034f980;
LAB_14034f778:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034f630;
LAB_14034f407:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14034f40e:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034f1b0;
LAB_14034efb3:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034eeb0;
LAB_14034eca3:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14034ecaa:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034eab0;
LAB_14035179d:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140351720;
LAB_1403515ad:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140351480;
LAB_14035137d:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140351320;
LAB_1403511d0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403510e0;
LAB_140350f03:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140350e00;
LAB_140350c13:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140350a30;
LAB_140350873:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140350790;
LAB_1403505c3:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar9 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140350420;
LAB_14034d6a8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034d513;
LAB_14034d2e8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034d160;
LAB_14034dc70:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034db50;
LAB_14034d9e0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034d8e0;
LAB_14034e338:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034e1b3;
LAB_14034df98:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034de20;
LAB_14034e8c0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034e7b0;
LAB_14034e650:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034e560;
LAB_14034d000:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034cf40;
LAB_14034ce20:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034cd70;
LAB_14034cb77:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    local_e0 = (uint *)((longlong)local_e0 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034ca50;
LAB_14034c8a3:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  puVar16 = local_e0;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  pbVar34 = local_c0;
  iVar26 = iVar19;
  iVar28 = iVar11;
  iVar10 = iVar19;
  local_58 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034c7b0;
LAB_14034c138:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034bff3;
LAB_14034be18:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  local_e0 = (uint *)local_c0;
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_e0 = (uint *)((longlong)local_e0 + local_90);
  }
  local_e8 = local_e8 + -1;
  local_c8 = iVar11;
  local_res18 = iVar19;
  local_c0 = (byte *)local_e0;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034bd0d;
LAB_14034c620:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034c540;
LAB_14034c400:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034c340;
LAB_14034b638:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034b4f2;
LAB_14034b308:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034b1e0;
LAB_14034bb70:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  local_cc = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034ba81;
LAB_14034b920:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  local_cc = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034b842;
LAB_14034a178:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034a000;
LAB_140349e18:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140349cc3;
LAB_14034a6c0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034a5d0;
LAB_14034a480:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034a3a0;
LAB_14034acb8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034ab60;
LAB_14034a977:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    local_e0 = (uint *)((longlong)local_e0 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034a850;
LAB_14034b0a0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034b000;
LAB_14034af1d:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (iVar9 = iVar9 + -0x10000; iVar9 < 1; iVar9 = iVar9 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14034aeb0;
LAB_14036899e:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140368810;
LAB_140368593:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_1403685a5:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403682b0;
LAB_14036806c:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140367ef0;
LAB_140367ca3:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140367cae:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403679f0;
LAB_1403698f4:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_c8 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403697a1;
LAB_14036958f:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_14036959e:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_c8 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036931c;
LAB_140369170:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140369033;
LAB_140368e50:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140368e5c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140368c0d;
LAB_14036a9fa:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036a880;
LAB_14036a60b:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14036a61f:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036a350;
LAB_14036a11a:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140369fc0;
LAB_140369d6b:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_140369d7f:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140369b00;
LAB_14036b860:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036b733;
LAB_14036b54f:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_14036b55c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036b30e;
LAB_14036b160:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036b041;
LAB_14036ae6f:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_14036ae7c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036ac5c;
LAB_140366cba:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140366b80;
LAB_14036696b:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140366730;
LAB_14036653a:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140366420;
LAB_14036622a:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140366033;
LAB_140367850:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140367751;
LAB_1403675a4:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403673df;
LAB_14036704f:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140366eda;
LAB_140367280:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403671c0;
LAB_140365268:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140365120;
LAB_140364f08:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140364cb0;
LAB_140364ac8:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  local_e0 = (uint *)local_c0;
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_e0 = (uint *)((longlong)local_e0 + local_90);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  local_c0 = (byte *)local_e0;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403649a0;
LAB_140364798:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140364590;
LAB_140365e8f:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140365da0;
LAB_140365bf4:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140365a00;
LAB_140365890:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403657c0;
LAB_140365635:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403654a0;
LAB_14036369a:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140363540;
LAB_140363318:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140363090;
LAB_140362e78:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  local_e0 = (uint *)local_c0;
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_e0 = (uint *)((longlong)local_e0 + local_90);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  local_c0 = (byte *)local_e0;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140362d40;
LAB_140362b17:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403628d0;
LAB_1403643cf:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403642d0;
LAB_140364104:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140363ef0;
LAB_140363d5f:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140363c70;
LAB_140363abb:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar28 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403638e0;
LAB_140360d00:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140360be1;
LAB_1403609ff:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_140360a0c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403607be;
LAB_140360610:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140360501;
LAB_14036033f:
  uVar27 = (ulonglong)DAT_140c28a88;
LAB_14036034c:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036012c;
LAB_14035fec8:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035fd50;
LAB_14035fadb:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035faef:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035f840;
LAB_14035f24b:
  uVar33 = (ulonglong)DAT_140c28a88;
LAB_14035f265:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035efd0;
LAB_14035f5fb:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035f4a2;
LAB_140361c8e:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140361b20;
LAB_140361916:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140361690;
LAB_14036147a:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140361340;
LAB_14036112b:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140360ef0;
LAB_1403624ef:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_c8 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14036232b;
LAB_140362760:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403626b0;
LAB_140362020:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140361edd;
LAB_14036221d:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403621b0;
LAB_14035df96:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  local_c8 = iVar11;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035de30;
LAB_14035dc54:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_c8 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035db10;
LAB_14035d88c:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035d6e0;
LAB_14035d48c:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035d300;
LAB_14035ed90:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035ec40;
LAB_14035ea70:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035e940;
LAB_14035e6ce:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035e540;
LAB_14035e30e:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035e1a0;
LAB_14035cc0e:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035cac0;
LAB_14035c8da:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035c7b0;
LAB_14035d160:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_c8 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035d061;
LAB_14035cf00:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035ce31;
LAB_14035c09b:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035bf50;
LAB_14035bd58:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  local_e0 = (uint *)local_c0;
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_e0 = (uint *)((longlong)local_e0 + local_90);
  }
  local_e8 = local_e8 + -1;
  local_cc = iVar11;
  iVar9 = iVar19;
  local_c0 = (byte *)local_e0;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035bc3d;
LAB_14035c602:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035c510;
LAB_14035c3a0:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035c2d0;
LAB_14035ba60:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035b953;
LAB_14035b7c2:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  iVar10 = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035b6d1;
LAB_14035b47b:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035b310;
LAB_14035b0ed:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  local_e0 = (uint *)local_c0;
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_e0 = (uint *)((longlong)local_e0 + local_90);
  }
  local_e8 = local_e8 + -1;
  iVar9 = iVar19;
  iVar10 = iVar11;
  local_c0 = (byte *)local_e0;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035afa0;
LAB_14035a320:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035a1e0;
LAB_14035a020:
  puVar18 = (uint *)((longlong)puVar14 + uVar22);
  puVar16 = puVar13;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar28 = iVar19;
  local_cc = iVar11;
  iVar9 = iVar19;
  puVar14 = puVar18;
  puVar13 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140359f00;
LAB_140359c9e:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_140359b20;
LAB_1403598fe:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_1403597a0;
LAB_14035a9ce:
  puVar18 = (uint *)((longlong)local_58 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  local_58 = puVar18;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035a860;
LAB_14035a64f:
  puVar18 = (uint *)((longlong)puVar18 + uVar22);
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
    local_c0 = local_c0 + local_90;
  }
  local_e8 = local_e8 + -1;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035a510;
LAB_14035ae2f:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035ad80;
LAB_14035ac7d:
  puVar18 = (uint *)((longlong)puVar13 + uVar22);
  puVar16 = puVar14;
  for (local_res18 = local_res18 + -0x10000; local_res18 < 1; local_res18 = local_res18 + uVar8) {
    puVar16 = (uint *)((longlong)puVar16 + local_b0);
  }
  local_e8 = local_e8 + -1;
  iVar10 = iVar19;
  iVar9 = iVar11;
  puVar13 = puVar18;
  puVar14 = puVar16;
  if (local_e8 == 0) {
    return;
  }
  goto LAB_14035ac10;
}


