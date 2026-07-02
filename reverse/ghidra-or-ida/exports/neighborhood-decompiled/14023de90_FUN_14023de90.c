// Function: FUN_14023de90 @ 14023de90
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14023de90(uint *param_1,uint param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  longlong lVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  longlong lVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  longlong lVar20;
  longlong lVar21;
  uint *puVar22;
  byte *pbVar23;
  undefined1 auStack_23b8 [32];
  uint local_2398 [4];
  uint local_2388;
  uint local_2384;
  byte local_2378 [512];
  byte local_2178 [512];
  byte local_1f78 [512];
  byte local_1d78 [512];
  byte local_1b78 [512];
  byte local_1978 [512];
  uint local_1778 [16];
  undefined4 local_1738 [64];
  undefined4 local_1638 [1024];
  byte local_638 [256];
  byte abStack_538 [256];
  byte abStack_438 [256];
  byte abStack_338 [256];
  byte abStack_238 [256];
  byte abStack_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_23b8;
  if (DAT_140ca5960 == 0) {
    uVar9 = 0xffffffff;
  }
  else {
    if (param_1[4] != param_2) {
      param_1[4] = param_2;
      uVar10 = 0;
      puVar12 = param_1;
      do {
        puVar22 = puVar12 + 1;
        uVar8 = uVar10 & 0x1f;
        uVar10 = uVar10 + 1;
        *puVar12 = (uint)((param_2 >> uVar8 & 1) != 0);
        puVar12 = puVar22;
      } while ((int)uVar10 < 4);
      FUN_1401ae370(local_638,CONCAT71((int7)((ulonglong)puVar22 >> 8),0xff));
      iVar14 = 0;
      puVar12 = param_1 + 5;
      lVar21 = 6;
      puVar22 = param_1;
      do {
        if (*puVar22 != 0) {
          lVar20 = 0;
          lVar16 = lVar21;
          puVar15 = puVar12;
          do {
            if (0 < (int)puVar15[0x100]) {
              uVar19 = (ulonglong)puVar15[0x100];
              puVar13 = puVar15;
              do {
                uVar17 = (ulonglong)(ushort)*puVar13;
                if (uVar17 < *(ushort *)((longlong)puVar13 + 2)) {
                  pbVar23 = local_638 + lVar20 + uVar17;
                  for (lVar11 = *(ushort *)((longlong)puVar13 + 2) - uVar17; lVar11 != 0;
                      lVar11 = lVar11 + -1) {
                    *pbVar23 = (byte)iVar14;
                    pbVar23 = pbVar23 + 1;
                  }
                }
                puVar13 = puVar13 + 1;
                uVar19 = uVar19 - 1;
              } while (uVar19 != 0);
            }
            puVar15 = puVar15 + 0x140c;
            lVar20 = lVar20 + 0x100;
            lVar16 = lVar16 + -1;
          } while (lVar16 != 0);
        }
        iVar14 = iVar14 + 1;
        puVar22 = puVar22 + 1;
        puVar12 = puVar12 + 0x503;
      } while (iVar14 < 4);
      lVar16 = 0;
      puVar15 = local_2398;
      puVar12 = param_1 + 0x106;
      puVar22 = param_1 + 0x9c5f;
      do {
        uVar10 = *puVar12;
        *puVar15 = 0;
        uVar8 = 0;
joined_r0x00014023dff2:
        for (; (int)uVar8 < (int)uVar10; uVar8 = uVar8 + 1) {
          if ((local_638[lVar16 + (int)uVar8] != 0xff) &&
             (*(byte *)((longlong)puVar22 + (int)uVar8 + lVar16) != local_638[lVar16 + (int)uVar8]))
          break;
        }
        if (uVar8 != uVar10) {
          uVar4 = *puVar15;
          lVar20 = (lVar16 + (int)uVar4) * 2;
          local_2378[lVar20] = (byte)uVar8;
          for (; (int)uVar8 < (int)uVar10; uVar8 = uVar8 + 1) {
            if ((local_638[lVar16 + (int)uVar8] == 0xff) ||
               (*(byte *)((longlong)puVar22 + (int)uVar8 + lVar16) == local_638[lVar16 + (int)uVar8]
               )) break;
          }
          local_2378[lVar20 + 1] = (byte)uVar8;
          *puVar15 = uVar4 + 1;
          goto joined_r0x00014023dff2;
        }
        puVar12 = puVar12 + 0x140c;
        lVar16 = lVar16 + 0x100;
        puVar15 = puVar15 + 1;
        lVar21 = lVar21 + -1;
      } while (lVar21 != 0);
      FUN_1401ae2f0(puVar22,local_638,0x600);
      if (0 < (int)local_2398[0]) {
        pbVar23 = local_2378 + 1;
        uVar19 = (ulonglong)local_2398[0];
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            lVar21 = uVar18 << 4;
            do {
              pbVar1 = local_638 + uVar17;
              uVar17 = uVar17 + 1;
              puVar2 = (undefined4 *)
                       ((ulonglong)*pbVar1 * 0x140c + lVar21 + 0x420 + (longlong)param_1);
              uVar5 = puVar2[1];
              uVar6 = puVar2[2];
              uVar7 = puVar2[3];
              *(undefined4 *)((longlong)local_1638 + lVar21) = *puVar2;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 4) = uVar5;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 8) = uVar6;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 0xc) = uVar7;
              lVar21 = lVar21 + 0x10;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_140222aa0(uVar10,local_1638 + uVar18 * 4,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 * 4 + 0x7f50,local_1638 + uVar18 * 4,
                        (longlong)(int)(bVar3 - uVar10) << 4);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      if (0 < (int)local_2398[1]) {
        pbVar23 = local_2178 + 1;
        uVar19 = (ulonglong)local_2398[1];
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            lVar21 = uVar18 << 4;
            do {
              pbVar1 = abStack_538 + uVar17;
              uVar17 = uVar17 + 1;
              puVar2 = (undefined4 *)
                       ((ulonglong)*pbVar1 * 0x140c + lVar21 + 0x5450 + (longlong)param_1);
              uVar5 = puVar2[1];
              uVar6 = puVar2[2];
              uVar7 = puVar2[3];
              *(undefined4 *)((longlong)local_1738 + lVar21) = *puVar2;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 4) = uVar5;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 8) = uVar6;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 0xc) = uVar7;
              lVar21 = lVar21 + 0x10;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_140222ac0(uVar10,local_1738 + uVar18 * 4,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 * 4 + 0x8453,local_1738 + uVar18 * 4,
                        (longlong)(int)(bVar3 - uVar10) << 4);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      if (0 < (int)local_2398[2]) {
        pbVar23 = local_1f78 + 1;
        uVar19 = (ulonglong)local_2398[2];
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            do {
              local_1778[uVar17] = param_1[(ulonglong)abStack_438[uVar17] * 0x503 + uVar17 + 0x2920]
              ;
              uVar17 = uVar17 + 1;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_140222a80(uVar10,local_1778 + uVar18,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 + 0x8956,local_1778 + uVar18,
                        (longlong)(int)(bVar3 - uVar10) << 2);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      if (0 < (int)local_2398[3]) {
        pbVar23 = local_1d78 + 1;
        uVar19 = (ulonglong)local_2398[3];
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            lVar21 = uVar18 << 4;
            do {
              pbVar1 = abStack_338 + uVar17;
              uVar17 = uVar17 + 1;
              puVar2 = (undefined4 *)
                       ((ulonglong)*pbVar1 * 0x140c + lVar21 + 0xf4b0 + (longlong)param_1);
              uVar5 = puVar2[1];
              uVar6 = puVar2[2];
              uVar7 = puVar2[3];
              *(undefined4 *)((longlong)local_1638 + lVar21) = *puVar2;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 4) = uVar5;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 8) = uVar6;
              *(undefined4 *)((longlong)local_1638 + lVar21 + 0xc) = uVar7;
              lVar21 = lVar21 + 0x10;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_1402228f0(uVar10,local_1638 + uVar18 * 4,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 * 4 + 0x8e59,local_1638 + uVar18 * 4,
                        (longlong)(int)(bVar3 - uVar10) << 4);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      if (0 < (int)local_2388) {
        pbVar23 = local_1b78 + 1;
        uVar19 = (ulonglong)local_2388;
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            lVar21 = uVar18 << 4;
            do {
              pbVar1 = abStack_238 + uVar17;
              uVar17 = uVar17 + 1;
              puVar2 = (undefined4 *)
                       ((ulonglong)*pbVar1 * 0x140c + lVar21 + 0x144e0 + (longlong)param_1);
              uVar5 = puVar2[1];
              uVar6 = puVar2[2];
              uVar7 = puVar2[3];
              *(undefined4 *)((longlong)local_1738 + lVar21) = *puVar2;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 4) = uVar5;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 8) = uVar6;
              *(undefined4 *)((longlong)local_1738 + lVar21 + 0xc) = uVar7;
              lVar21 = lVar21 + 0x10;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_140222910(uVar10,local_1738 + uVar18 * 4,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 * 4 + 0x935c,local_1738 + uVar18 * 4,
                        (longlong)(int)(bVar3 - uVar10) << 4);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      if (0 < (int)local_2384) {
        pbVar23 = local_1978 + 1;
        uVar19 = (ulonglong)local_2384;
        do {
          uVar18 = (ulonglong)pbVar23[-1];
          bVar3 = *pbVar23;
          uVar10 = (uint)pbVar23[-1];
          uVar17 = (ulonglong)uVar10;
          if (uVar18 < bVar3) {
            do {
              local_1778[uVar17] = param_1[(ulonglong)abStack_138[uVar17] * 0x503 + uVar17 + 0x6544]
              ;
              uVar17 = uVar17 + 1;
            } while ((longlong)uVar17 < (longlong)(ulonglong)bVar3);
          }
          FUN_1402228d0(uVar10,local_1778 + uVar18,bVar3 - uVar10);
          FUN_1401ae2f0(param_1 + uVar18 + 0x985f,local_1778 + uVar18,
                        (longlong)(int)(bVar3 - uVar10) << 2);
          pbVar23 = pbVar23 + 2;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
    }
    uVar9 = 0;
  }
  return uVar9;
}


