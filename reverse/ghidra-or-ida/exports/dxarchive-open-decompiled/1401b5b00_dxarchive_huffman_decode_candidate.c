// Function: dxarchive_huffman_decode_candidate @ 1401b5b00
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong dxarchive_huffman_decode_candidate(byte *param_1,longlong param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  undefined8 *puVar7;
  longlong lVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  ushort uVar17;
  int iVar18;
  int iVar19;
  ulonglong uVar20;
  longlong lVar21;
  longlong lVar22;
  longlong lVar23;
  int iVar24;
  int iVar25;
  ushort *puVar26;
  char cVar27;
  uint uVar28;
  int iVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  undefined1 *puVar32;
  byte bVar33;
  uint uVar34;
  longlong lVar35;
  ulonglong uVar36;
  longlong lVar37;
  longlong lVar38;
  byte *pbVar39;
  short sVar40;
  int iVar41;
  int *piVar42;
  uint *puVar43;
  longlong *plVar44;
  longlong lVar45;
  longlong lVar46;
  int iVar47;
  ulonglong uVar48;
  undefined1 auStack_8a58 [32];
  undefined4 local_8a38;
  undefined4 local_8a34;
  undefined4 local_8a30;
  undefined4 local_8a2c;
  undefined4 local_8a28;
  ulonglong local_8a18;
  byte *local_8a10;
  longlong local_8a08;
  longlong local_8a00;
  ushort local_89f8 [256];
  uint local_87f8 [512];
  ulonglong local_7ff8;
  int local_7ff0;
  undefined1 local_7feb [31];
  byte abStack_7fcc [4];
  int local_7fc8;
  undefined8 local_7fc4 [2041];
  longlong local_3ff8 [2040];
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x1401b5b2a;
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_8a58;
  bVar33 = *param_1;
  local_8a08 = 0;
  local_8a00 = param_2;
  local_8a10 = param_1;
  uVar48 = 0;
  local_8a18 = 0;
  bVar33 = (bVar33 >> 2 & 0x20 | bVar33 >> 2 & 0x10 | bVar33 >> 2 & 8 | bVar33 >> 2 & 4 |
            bVar33 >> 2 & 2 | bVar33 >> 2 & 1) + 1;
  local_8a28 = 6;
  local_8a28._0_1_ = '\x06';
  uVar28 = 0;
  iVar6 = 6;
  if (bVar33 != 0) {
    do {
      bVar9 = 7 - (char)local_8a28;
      local_8a28 = local_8a28 + 1;
      uVar48 = uVar48 | (ulonglong)(param_1[local_8a08] >> (bVar9 & 0x3f) & 1) <<
                        ((bVar33 - (char)uVar28) - 1 & 0x3f);
      if (local_8a28 == 8) {
        local_8a08 = local_8a08 + 1;
        local_8a28 = 0;
      }
      uVar28 = uVar28 + 1;
    } while (uVar28 < bVar33);
    local_8a18 = uVar48;
    iVar6 = local_8a28;
  }
  pbVar39 = param_1 + local_8a08;
  bVar33 = 7 - (char)local_8a28;
  local_8a28 = iVar6 + 1;
  if (iVar6 + 1 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar1 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar9 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar2 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar10 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar3 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar11 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar4 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar12 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar5 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar13 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  bVar33 = ((*pbVar39 >> (bVar33 & 0x3f) & 1) << 5 | (*pbVar1 >> (bVar9 & 0x3f) & 1) << 4 |
            (*pbVar2 >> (bVar10 & 0x3f) & 1) << 3 | (*pbVar3 >> (bVar11 & 0x3f) & 1) << 2 |
            (*pbVar4 >> (bVar12 & 0x3f) & 1) * '\x02' | *pbVar5 >> (bVar13 & 0x3f) & 1) + 1;
  uVar48 = (ulonglong)bVar33;
  if (bVar33 != 0) {
    do {
      local_8a28 = local_8a28 + 1;
      if (local_8a28 == 8) {
        local_8a08 = local_8a08 + 1;
        local_8a28 = 0;
      }
      uVar48 = uVar48 - 1;
    } while (uVar48 != 0);
  }
  pbVar39 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar33 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar1 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  bVar9 = 7 - (char)local_8a28;
  local_8a28 = iVar6;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  pbVar2 = param_1 + local_8a08;
  iVar6 = local_8a28 + 1;
  if (iVar6 == 8) {
    local_8a08 = local_8a08 + 1;
    iVar6 = 0;
  }
  cVar27 = ((*pbVar39 >> (bVar33 & 0x3f) & 1) << 2 | (*pbVar1 >> (bVar9 & 0x3f) & 1) * '\x02' |
           *pbVar2 >> (7U - (char)local_8a28 & 0x3f) & 1) + 1;
  local_8a28 = iVar6 + 1;
  bVar33 = cVar27 * '\x02';
  if (local_8a28 == 8) {
    local_8a08 = local_8a08 + 1;
    local_8a28 = 0;
  }
  uVar48 = 0;
  local_89f8[0] = 0;
  uVar28 = 0;
  if (cVar27 != '\0') {
    do {
      bVar9 = 7 - (char)local_8a28;
      local_8a28 = local_8a28 + 1;
      uVar48 = uVar48 | (ulonglong)(param_1[local_8a08] >> (bVar9 & 0x3f) & 1) <<
                        ((bVar33 - (char)uVar28) - 1 & 0x3f);
      local_89f8[0] = (ushort)uVar48;
      if (local_8a28 == 8) {
        local_8a08 = local_8a08 + 1;
        local_8a28 = 0;
      }
      uVar28 = uVar28 + 1;
    } while (uVar28 < bVar33);
  }
  puVar26 = local_89f8;
  lVar21 = 0xff;
  do {
    pbVar39 = param_1 + local_8a08;
    iVar6 = local_8a28 + 1;
    bVar33 = 7 - (char)local_8a28;
    local_8a28 = iVar6;
    if (iVar6 == 8) {
      local_8a08 = local_8a08 + 1;
      local_8a28 = 0;
    }
    pbVar1 = param_1 + local_8a08;
    iVar6 = local_8a28 + 1;
    bVar9 = 7 - (char)local_8a28;
    local_8a28 = iVar6;
    if (iVar6 == 8) {
      local_8a08 = local_8a08 + 1;
      local_8a28 = 0;
    }
    pbVar2 = param_1 + local_8a08;
    iVar6 = local_8a28 + 1;
    bVar10 = 7 - (char)local_8a28;
    local_8a28 = iVar6;
    if (iVar6 == 8) {
      local_8a08 = local_8a08 + 1;
      local_8a28 = 0;
    }
    pbVar3 = param_1 + local_8a08;
    cVar27 = ((*pbVar39 >> (bVar33 & 0x3f) & 1) << 2 | (*pbVar1 >> (bVar9 & 0x3f) & 1) * '\x02' |
             *pbVar2 >> (bVar10 & 0x3f) & 1) + 1;
    iVar6 = local_8a28 + 1;
    bVar9 = 7 - (char)local_8a28;
    bVar33 = cVar27 * '\x02';
    local_8a28 = iVar6;
    if (iVar6 == 8) {
      local_8a08 = local_8a08 + 1;
      local_8a28 = 0;
    }
    uVar48 = 0;
    sVar40 = 0;
    uVar28 = 0;
    if (cVar27 != '\0') {
      do {
        bVar10 = 7 - (char)local_8a28;
        local_8a28 = local_8a28 + 1;
        uVar48 = uVar48 | (ulonglong)(param_1[local_8a08] >> (bVar10 & 0x3f) & 1) <<
                          ((bVar33 - (char)uVar28) - 1 & 0x3f);
        sVar40 = (short)uVar48;
        if (local_8a28 == 8) {
          local_8a08 = local_8a08 + 1;
          local_8a28 = 0;
        }
        uVar28 = uVar28 + 1;
      } while (uVar28 < bVar33);
    }
    if ((*pbVar3 >> (bVar9 & 0x3f) & 1) == 1) {
      uVar17 = *puVar26 - sVar40;
    }
    else {
      uVar17 = sVar40 + *puVar26;
    }
    puVar26 = puVar26 + 1;
    *puVar26 = uVar17;
    lVar21 = lVar21 + -1;
  } while (lVar21 != 0);
  local_8a08 = (ulonglong)(local_8a28 != 0) + local_8a08;
  if (param_2 != 0) {
    lVar21 = 0;
    puVar7 = local_7fc4;
    iVar6 = 0x100;
    do {
      if (lVar21 < 0x100) {
        uVar48 = (ulonglong)local_89f8[lVar21];
      }
      else {
        uVar48 = 0;
      }
      *(ulonglong *)((longlong)puVar7 + -0x34) = uVar48;
      lVar21 = lVar21 + 1;
      *puVar7 = 0xffffffffffffffff;
      *(undefined4 *)((longlong)puVar7 + -4) = 0xffffffff;
      puVar7 = puVar7 + 8;
    } while (lVar21 < 0x1ff);
    iVar47 = 0x100;
    plVar44 = local_3ff8;
    do {
      lVar22 = -1;
      iVar19 = -1;
      iVar24 = -1;
      lVar21 = -1;
      iVar29 = 0;
      lVar35 = 0;
      iVar41 = 0;
      if (0 < iVar47) {
        lVar8 = 0;
        lVar16 = lVar21;
        lVar23 = lVar22;
        lVar37 = -0x40;
        lVar45 = -0x40;
        iVar18 = iVar19;
        iVar25 = -1;
        do {
          lVar21 = lVar16;
          lVar22 = lVar23;
          lVar38 = lVar37;
          lVar46 = lVar45;
          iVar19 = iVar18;
          iVar24 = iVar25;
          if ((((*(int *)((longlong)&local_7fc8 + lVar8) == -1) &&
               (iVar41 = iVar41 + 1, lVar21 = lVar23, lVar22 = lVar35, lVar38 = lVar45,
               lVar46 = lVar8, iVar19 = iVar29, iVar24 = iVar18, iVar18 != -1)) &&
              (*(ulonglong *)((longlong)&local_7ff8 + lVar45) <=
               *(ulonglong *)((longlong)&local_7ff8 + lVar8))) &&
             ((lVar16 == -1 ||
              (lVar21 = lVar16, lVar22 = lVar23, lVar38 = lVar37, lVar46 = lVar45, iVar19 = iVar18,
              iVar24 = iVar25,
              *(ulonglong *)((longlong)&local_7ff8 + lVar8) <
              *(ulonglong *)((longlong)&local_7ff8 + lVar37))))) {
            lVar21 = lVar35;
            lVar22 = lVar23;
            lVar38 = lVar8;
            lVar46 = lVar45;
            iVar19 = iVar18;
            iVar24 = iVar29;
          }
          iVar29 = iVar29 + 1;
          lVar35 = lVar35 + 1;
          lVar8 = lVar8 + 0x40;
          lVar16 = lVar21;
          lVar23 = lVar22;
          lVar37 = lVar38;
          lVar45 = lVar46;
          iVar18 = iVar19;
          iVar25 = iVar24;
        } while (iVar41 < iVar47);
      }
      *(undefined4 *)(plVar44 + 6) = 0xffffffff;
      iVar47 = iVar47 + -1;
      *plVar44 = (&local_7ff8)[lVar21 * 8] + (&local_7ff8)[lVar22 * 8];
      *(int *)((longlong)plVar44 + 0x34) = iVar19;
      *(int *)(plVar44 + 7) = iVar24;
      plVar44 = plVar44 + 8;
      pbVar39 = abStack_7fcc + lVar22 * 0x40;
      pbVar39[0] = 0;
      pbVar39[1] = 0;
      pbVar39[2] = 0;
      pbVar39[3] = 0;
      pbVar39 = abStack_7fcc + lVar21 * 0x40;
      pbVar39[0] = 1;
      pbVar39[1] = 0;
      pbVar39[2] = 0;
      pbVar39[3] = 0;
      (&local_7fc8)[lVar22 * 0x10] = iVar6;
      (&local_7fc8)[lVar21 * 0x10] = iVar6;
      iVar6 = iVar6 + 1;
    } while (1 < iVar47);
    uVar28 = 0;
    uVar20 = 0;
    piVar42 = &local_7ff0;
    uVar48 = uVar20;
    do {
      *piVar42 = 0;
      iVar6 = piVar42[10];
      local_8a38 = local_8a38 & 0xffffff00;
      iVar47 = (int)uVar48;
      uVar31 = uVar20;
      uVar36 = uVar20;
      while (iVar6 != -1) {
        uVar30 = uVar31;
        uVar14 = (uint)uVar36;
        if ((uint)uVar36 == 8) {
          uVar30 = uVar31 + 1;
          if (0x1f < uVar30) {
                    /* WARNING: Subroutine does not return */
            FUN_14031c688();
          }
          *(undefined1 *)((longlong)&local_8a38 + uVar31 + 1) = 0;
          uVar14 = uVar28;
        }
        uVar36 = (ulonglong)(uVar14 + 1);
        cVar27 = *(char *)((longlong)&local_8a38 + uVar30);
        bVar33 = abStack_7fcc[(longlong)(int)uVar48 * 0x40];
        *piVar42 = *piVar42 + 1;
        uVar48 = (ulonglong)(&local_7fc8)[(longlong)(int)uVar48 * 0x10];
        *(byte *)((longlong)&local_8a38 + uVar30) = bVar33 | cVar27 * '\x02';
        uVar31 = uVar30;
        iVar6 = (&local_7fc8)[uVar48 * 0x10];
      }
      pbVar39 = (byte *)(piVar42 + 1);
      *pbVar39 = 0;
      uVar14 = uVar28;
      while (-1 < (longlong)uVar31) {
        if (uVar14 == 8) {
          pbVar39 = pbVar39 + 1;
          *pbVar39 = 0;
          uVar14 = uVar28;
        }
        bVar33 = *(byte *)((longlong)&local_8a38 + uVar31);
        *(byte *)((longlong)&local_8a38 + uVar31) = bVar33 >> 1;
        *pbVar39 = *pbVar39 | (bVar33 & 1) << ((byte)uVar14 & 0x1f);
        uVar34 = (int)uVar36 - 1;
        uVar36 = (ulonglong)uVar34;
        if (uVar34 == 0) {
          uVar31 = uVar31 - 1;
          uVar36 = 8;
        }
        uVar14 = uVar14 + 1;
      }
      uVar14 = iVar47 + 1;
      uVar48 = (ulonglong)uVar14;
      piVar42 = piVar42 + 0x10;
    } while ((int)uVar14 < 0x1fe);
    local_8a38 = 0x30001;
    uVar14 = (uint)local_8a28 >> 0x10;
    local_8a28 = CONCAT22((short)uVar14,0x1ff);
    puVar43 = local_87f8;
    local_8a34 = 0xf0007;
    local_8a30 = 0x3f001f;
    local_8a2c = 0xff007f;
    uVar48 = uVar20;
    do {
      *puVar43 = 0xffffffff;
      puVar32 = local_7feb;
      uVar14 = uVar28;
      do {
        if ((*(int *)(puVar32 + -5) < 10) &&
           (uVar17 = *(ushort *)
                      ((longlong)&local_8a38 + (longlong)(*(int *)(puVar32 + -5) + -1) * 2),
           ((uint)uVar17 & (uint)uVar48) == (uint)(CONCAT11(*puVar32,puVar32[-1]) & uVar17))) {
          *puVar43 = uVar14;
          break;
        }
        uVar14 = uVar14 + 1;
        puVar32 = puVar32 + 0x40;
      } while ((int)uVar14 < 0x1fe);
      uVar14 = (uint)uVar48 + 1;
      uVar48 = (ulonglong)uVar14;
      puVar43 = puVar43 + 1;
    } while ((int)uVar14 < 0x200);
    param_1 = param_1 + local_8a08;
    uVar14 = (uint)*param_1;
    if (local_8a18 != 0) {
      uVar48 = uVar20;
      uVar34 = uVar28;
      do {
        if (uVar20 < local_8a18 - 0x11) {
          if (uVar34 == 8) {
            uVar14 = (uint)param_1[uVar48 + 1];
            uVar48 = uVar48 + 1;
            uVar34 = uVar28;
          }
          uVar14 = ((uint)param_1[uVar48 + 1] << (8U - (char)uVar34 & 0x1f) | uVar14) & 0x1ff;
          uVar15 = local_87f8[uVar14];
          uVar31 = (ulonglong)(int)uVar15;
          uVar34 = uVar34 + (&local_7ff0)[uVar31 * 0x10];
          if (0xf < (int)uVar34) {
            lVar21 = uVar48 + 2;
            uVar48 = uVar48 + 2;
            uVar34 = uVar34 - 0x10;
            uVar14 = (uint)(param_1[lVar21] >> ((byte)uVar34 & 0x1f));
            goto joined_r0x0001401b6302;
          }
          if (7 < (int)uVar34) {
            lVar21 = uVar48 + 1;
            uVar48 = uVar48 + 1;
            uVar34 = uVar34 - 8;
            uVar14 = (uint)(param_1[lVar21] >> ((byte)uVar34 & 0x1f));
            goto joined_r0x0001401b6302;
          }
          uVar14 = (int)uVar14 >> ((byte)(&local_7ff0)[uVar31 * 0x10] & 0x1f);
          goto joined_r0x0001401b6302;
        }
        uVar31 = 0x1fe;
        do {
          if (uVar34 == 8) {
            uVar14 = (uint)param_1[uVar48 + 1];
            uVar48 = uVar48 + 1;
            uVar34 = uVar28;
          }
          uVar15 = uVar14 & 1;
          uVar14 = (int)uVar14 >> 1;
          uVar34 = uVar34 + 1;
          uVar15 = *(uint *)((longlong)local_7fc4 +
                            ((longlong)(int)uVar31 * 0x10 + (ulonglong)uVar15) * 4);
          uVar31 = (ulonglong)uVar15;
joined_r0x0001401b6302:
        } while (0xff < (int)uVar15);
        *(char *)(param_2 + uVar20) = (char)uVar31;
        uVar20 = uVar20 + 1;
      } while (uVar20 < local_8a18);
    }
  }
  return local_8a18;
}


