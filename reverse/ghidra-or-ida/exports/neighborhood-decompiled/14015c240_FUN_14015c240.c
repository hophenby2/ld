// Function: FUN_14015c240 @ 14015c240
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_14015c240(longlong param_1,uint *param_2,uint param_3,uint param_4,uint param_5,int param_6,
             byte *param_7,int param_8,int param_9,uint param_10,int param_11,uint param_12,
             int param_13,int param_14)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  int iVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  char cVar20;
  char cVar21;
  byte bVar22;
  byte bVar23;
  short sVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  ulonglong uVar32;
  undefined4 *puVar33;
  uint *puVar34;
  longlong lVar35;
  longlong lVar36;
  longlong lVar37;
  ushort *puVar38;
  longlong *plVar39;
  byte bVar40;
  uint uVar41;
  byte *pbVar42;
  ulonglong uVar43;
  ulonglong uVar44;
  ulonglong uVar45;
  ushort uVar46;
  uint uVar47;
  uint uVar48;
  ulonglong uVar49;
  uint uVar50;
  char *pcVar51;
  longlong lVar52;
  longlong lVar53;
  uint uVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  byte bVar58;
  int iVar59;
  uint *puVar60;
  ulonglong uVar61;
  char *pcVar62;
  char *pcVar63;
  byte *pbVar64;
  byte *pbVar65;
  int iVar66;
  int iVar67;
  longlong lVar68;
  byte *pbVar69;
  ushort *puVar70;
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
  byte *local_128;
  byte *local_120;
  byte *local_110;
  byte *local_108;
  int local_f0;
  undefined8 local_d0;
  int local_bc;
  int local_a8;
  int local_90;
  
  uVar49 = 0;
  if ((char)param_2[2] != '\0') {
    if (*(undefined4 **)(param_2 + 0xc) == (undefined4 *)0x0) {
      plVar39 = (longlong *)(param_1 + 0x11bbe0);
      puVar60 = (uint *)*plVar39;
      uVar61 = uVar49;
      while (iVar67 = (int)uVar61, puVar60 != param_2) {
        uVar61 = (ulonglong)(iVar67 + 1);
        plVar39 = plVar39 + 1;
        puVar60 = (uint *)*plVar39;
      }
      iVar31 = *(int *)(param_1 + 0x11bbd8) + -1;
      *(int *)(param_1 + 0x11bbd8) = iVar31;
      iVar31 = iVar31 - iVar67;
      if (0 < iVar31) {
        FUN_1401ae320(param_1 + 0x11bbe0 + (longlong)iVar67 * 8,
                      param_1 + 0x11bbe0 + (longlong)(iVar67 + 1) * 8,(longlong)iVar31 << 3);
      }
    }
    else {
      **(undefined4 **)(param_2 + 0xc) = 0;
      *(undefined8 *)(*(longlong *)(param_2 + 0xc) + 8) = 0;
    }
    *(undefined1 *)(param_2 + 2) = 0;
  }
  if (param_6 == 1) {
    uVar29 = 4;
  }
  else if (param_6 == 2) {
    uVar29 = 8;
  }
  else if (param_6 == 3) {
    uVar29 = 0x10;
  }
  else {
    uVar29 = 1;
  }
  *param_2 = param_3;
  param_2[1] = param_4;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  uVar28 = *(uint *)(param_1 + 0x1217e0);
  if (uVar28 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x11dbf8) + uVar49 * 0x10) == param_3) break;
      uVar41 = (int)uVar49 + 1;
      uVar49 = (ulonglong)uVar41;
    } while (uVar41 < uVar28);
    uVar41 = (uint)uVar49;
    if ((uVar41 != uVar28) &&
       (*(ulonglong *)(param_2 + 8) = uVar49 * 0x10 + *(longlong *)(param_1 + 0x11dbf8),
       uVar41 < *(uint *)(param_1 + 0x1217e0))) {
      do {
        if (*(uint *)(*(longlong *)(param_1 + 0x11dbf8) + (ulonglong)(param_2[10] + uVar41) * 0x10)
            != param_3) break;
        uVar28 = param_2[10] + 1;
        param_2[10] = uVar28;
      } while (uVar28 + uVar41 < *(uint *)(param_1 + 0x1217e0));
    }
  }
  if ((param_5 != 0) || (param_7 == (byte *)0x0)) {
    sVar24 = (short)(((uVar29 >> 2) + param_13) / uVar29);
    *(undefined4 *)((longlong)param_2 + 10) = 0;
    *(short *)((longlong)param_2 + 0xe) = sVar24;
    param_2[4] = 0;
    if ((*(byte *)(param_1 + 0x12181c) & 1) != 0) {
      *(short *)((longlong)param_2 + 0xe) = *(short *)(param_1 + 0x121820) * 2 + sVar24;
    }
    goto LAB_14015e1a4;
  }
  *(short *)((longlong)param_2 + 10) = (short)((param_11 + (uVar29 >> 2)) / uVar29);
  *(short *)(param_2 + 4) = (short)((param_8 + -1 + uVar29) / uVar29);
  *(short *)((longlong)param_2 + 0xe) = (short)((param_13 + (uVar29 >> 2)) / uVar29);
  *(short *)(param_2 + 3) = (short)(param_12 / uVar29);
  uVar41 = param_9 + param_12 % uVar29;
  *(short *)((longlong)param_2 + 0x12) = (short)(((uVar29 - 1) + uVar41) / uVar29);
  uVar28 = *(uint *)(param_1 + 0x12181c) & 1;
  if (uVar28 == 0) {
    local_bc = 0;
    local_f0 = 0;
  }
  else {
    local_bc = *(int *)(param_1 + 0x121820);
    local_f0 = local_bc * 2;
  }
  uVar27 = *(ushort *)(param_1 + 0x1217d6);
  local_a8 = param_2[6] * (uint)uVar27;
  local_90 = param_2[7] * (uint)uVar27;
  uVar47 = (uint)uVar27;
  if (*(int *)(param_1 + 0x12211c) == 0) {
    FUN_1401ae370((longlong)(*(int *)(param_1 + 0x11dbf0) * local_90) +
                  *(longlong *)(param_1 + 0x11dbe8),0,
                  (longlong)(int)(*(int *)(param_1 + 0x11dbf0) * uVar47));
  }
  else if (((*(char *)(param_1 + 0x121cad) == '\b') || (*(int *)(param_1 + 0x1220f4) != 0)) ||
          (uVar28 != 0)) {
    FUN_140170d70(param_1 + 0x121ca8,local_a8,local_90,uVar27,uVar47);
    if ((*(byte *)(param_1 + 0x12181c) & 1) != 0) {
      FUN_140170d70(param_1 + 0x121ca8,local_a8 + *(int *)(param_1 + 0x121c70),local_90,
                    *(undefined2 *)(param_1 + 0x1217d6),*(undefined2 *)(param_1 + 0x1217d6));
    }
  }
  else {
    FUN_14017a090(param_1 + 0x121ca8,local_a8,local_90,uVar27,uVar47,0xff,0xff,0xff,0);
    if ((*(byte *)(param_1 + 0x12181c) & 1) != 0) {
      FUN_14017a090(param_1 + 0x121ca8,local_a8 + *(int *)(param_1 + 0x121c70),local_90,
                    *(undefined2 *)(param_1 + 0x1217d6),*(undefined2 *)(param_1 + 0x1217d6),0xff,
                    0xff,0xff,0);
    }
  }
  if (*(int *)(param_1 + 0x12211c) == 1) {
    local_a8 = local_a8 + 1;
    local_90 = local_90 + 1;
  }
  if ((param_6 == 4) || ((*(int *)(param_1 + 0x12211c) == 0 && (param_6 - 7U < 2)))) {
    uVar27 = (ushort)param_2[4];
    uVar49 = (ulonglong)uVar27;
    uVar25 = *(ushort *)((longlong)param_2 + 0x12);
    uVar61 = (ulonglong)uVar25;
    FUN_1401ae370(*(undefined8 *)(param_1 + 0x121c80),0,*(undefined4 *)(param_1 + 0x121c88));
    pbVar64 = *(byte **)(param_1 + 0x121c80);
    if (param_6 == 4) {
      uVar46 = uVar27 >> 1;
      uVar29 = (uint)uVar46;
      if (*(int *)(param_1 + 0x12211c) == 0) {
        if (uVar25 != 0) {
          do {
            pbVar69 = param_7;
            pbVar65 = pbVar64;
            uVar32 = (ulonglong)uVar46;
            uVar28 = 0;
            if (uVar29 != 0) {
              do {
                *pbVar65 = (&DAT_140818144)[*pbVar69 >> 4];
                pbVar65[1] = (&DAT_140818144)[*pbVar69 & 0xf];
                uVar32 = uVar32 - 1;
                pbVar69 = pbVar69 + 1;
                pbVar65 = pbVar65 + 2;
                uVar28 = uVar29;
              } while (uVar32 != 0);
            }
            if (uVar27 != (ushort)(uVar46 * 2)) {
              pbVar64[uVar28 * 2] = (&DAT_140818144)[param_7[uVar28] >> 4];
            }
            param_7 = param_7 + param_10;
            pbVar64 = pbVar64 + uVar49;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
        goto LAB_14015e09f;
      }
      if (uVar25 != 0) {
        do {
          pbVar69 = param_7;
          pbVar65 = pbVar64;
          uVar32 = (ulonglong)uVar46;
          uVar28 = 0;
          if (uVar29 != 0) {
            do {
              *pbVar65 = (&DAT_140818254)[*pbVar69 >> 4];
              pbVar65[1] = (&DAT_140818254)[*pbVar69 & 0xf];
              uVar32 = uVar32 - 1;
              pbVar69 = pbVar69 + 1;
              pbVar65 = pbVar65 + 2;
              uVar28 = uVar29;
            } while (uVar32 != 0);
          }
          if (uVar27 != (ushort)(uVar46 * 2)) {
            pbVar64[uVar28 * 2] = (&DAT_140818254)[param_7[uVar28] >> 4];
          }
          param_7 = param_7 + param_10;
          pbVar64 = pbVar64 + uVar49;
          uVar61 = uVar61 - 1;
        } while (uVar61 != 0);
      }
      param_6 = 7;
    }
    else {
      if (param_6 == 7) {
        if (uVar25 != 0) {
          do {
            if (uVar27 != 0) {
              pbVar69 = pbVar64;
              uVar32 = uVar49;
              do {
                *pbVar69 = pbVar69[(longlong)param_7 - (longlong)pbVar64] >> 2;
                pbVar69 = pbVar69 + 1;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
            param_7 = param_7 + param_10;
            pbVar64 = pbVar64 + uVar49;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
      else {
        if (param_6 != 8) goto LAB_14015e0ab;
        if (uVar25 != 0) {
          do {
            if (uVar27 != 0) {
              pbVar69 = pbVar64;
              uVar32 = uVar49;
              do {
                *pbVar69 = (&DAT_140818154)[pbVar69[(longlong)param_7 - (longlong)pbVar64]];
                pbVar69 = pbVar69 + 1;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
            param_7 = param_7 + param_10;
            pbVar64 = pbVar64 + uVar49;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
LAB_14015e09f:
      param_6 = 6;
    }
LAB_14015e0ab:
    param_7 = *(byte **)(param_1 + 0x121c80);
  }
  else if (uVar29 < 2) {
    uVar49 = (ulonglong)param_10;
  }
  else {
    uVar28 = uVar41 / uVar29;
    uVar41 = uVar41 % uVar29;
    uVar54 = (ushort)param_2[4] + 1;
    lVar68 = *(longlong *)(param_1 + 0x121c80);
    uVar55 = uVar54 & 0xfffffffe;
    uVar54 = uVar54 >> 1;
    uVar50 = uVar55 + 4;
    uVar49 = (ulonglong)uVar50;
    FUN_1401ae370(lVar68,0,(*(ushort *)((longlong)param_2 + 0x12) + 2) * uVar50);
    uVar32 = (ulonglong)param_10;
    pbVar64 = (byte *)(lVar68 + uVar49);
    uVar47 = uVar29 * param_10;
    pbVar69 = param_7 + -(ulonglong)((param_12 % uVar29) * param_10);
    uVar61 = (ulonglong)(param_10 * 2);
    param_7 = pbVar64;
    if (uVar29 == 4) {
      if ((*(int *)(param_1 + 0x12211c) == 0) || (*(int *)(param_1 + 0x1220f0) == 0x10)) {
        uVar49 = (ulonglong)uVar28;
        param_6 = 6;
        if (uVar28 != 0) {
          do {
            if (uVar54 != 0) {
              uVar44 = (ulonglong)uVar54;
              uVar43 = uVar61;
              pbVar65 = pbVar64;
              pbVar42 = pbVar69;
              do {
                iVar67 = (int)uVar43;
                uVar29 = iVar67 + (param_10 * 3 - (int)uVar61);
                uVar28 = iVar67 + (param_10 - (int)uVar61);
                *pbVar65 = (&DAT_140818044)[pbVar69[uVar43] & 0xf0] +
                           (&DAT_140818044)[pbVar69[uVar29] & 0xf0] +
                           (&DAT_140818044)[pbVar69[uVar28] & 0xf0] +
                           (&DAT_140818044)[*pbVar42 & 0xf0];
                pbVar65[1] = (&DAT_140818044)[pbVar69[uVar43] & 0xf] +
                             (&DAT_140818044)[pbVar69[uVar29] & 0xf] +
                             (&DAT_140818044)[pbVar69[uVar28] & 0xf] +
                             (&DAT_140818044)[*pbVar42 & 0xf];
                uVar44 = uVar44 - 1;
                uVar43 = (ulonglong)(iVar67 + 1);
                pbVar65 = pbVar65 + 2;
                pbVar42 = pbVar42 + 1;
              } while (uVar44 != 0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar49 = uVar49 - 1;
          } while (uVar49 != 0);
        }
        uVar49 = (ulonglong)uVar50;
        if (uVar41 != 0) {
          uVar61 = (ulonglong)uVar41;
          do {
            if (uVar54 != 0) {
              uVar43 = (ulonglong)uVar54;
              pbVar65 = pbVar64;
              pbVar42 = pbVar69;
              do {
                *pbVar65 = *pbVar65 + (&DAT_140818044)[*pbVar42 & 0xf0];
                pbVar65[1] = pbVar65[1] + (&DAT_140818044)[*pbVar42 & 0xf];
                pbVar65 = pbVar65 + 2;
                uVar43 = uVar43 - 1;
                pbVar42 = pbVar42 + 1;
              } while (uVar43 != 0);
            }
            pbVar69 = pbVar69 + uVar32;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
      else {
        uVar49 = (ulonglong)uVar28;
        param_6 = 7;
        if (uVar28 != 0) {
          do {
            if (uVar54 != 0) {
              uVar44 = (ulonglong)uVar54;
              uVar43 = uVar61;
              pbVar65 = pbVar64;
              pbVar42 = pbVar69;
              do {
                iVar67 = (int)uVar43;
                uVar29 = (param_10 - (int)uVar61) + iVar67;
                uVar28 = iVar67 + (param_10 * 3 - (int)uVar61);
                *pbVar65 = ((&DAT_140818044)[*pbVar42 & 0xf0] +
                            (&DAT_140818044)[pbVar69[uVar29] & 0xf0] +
                            (&DAT_140818044)[pbVar69[uVar43] & 0xf0] +
                           (&DAT_140818044)[pbVar69[uVar28] & 0xf0]) * '\x04';
                pbVar65[1] = ((&DAT_140818044)[*pbVar42 & 0xf] +
                              (&DAT_140818044)[pbVar69[uVar29] & 0xf] +
                              (&DAT_140818044)[pbVar69[uVar43] & 0xf] +
                             (&DAT_140818044)[pbVar69[uVar28] & 0xf]) * '\x04';
                uVar44 = uVar44 - 1;
                uVar43 = (ulonglong)(iVar67 + 1);
                pbVar65 = pbVar65 + 2;
                pbVar42 = pbVar42 + 1;
              } while (uVar44 != 0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar49 = uVar49 - 1;
          } while (uVar49 != 0);
        }
        uVar49 = (ulonglong)uVar50;
        if (uVar41 != 0) {
          uVar61 = (ulonglong)uVar41;
          do {
            if (uVar54 != 0) {
              uVar43 = (ulonglong)uVar54;
              pbVar65 = pbVar64;
              pbVar42 = pbVar69;
              do {
                *pbVar65 = *pbVar65 + (&DAT_140818044)[*pbVar42 & 0xf0] * '\x04';
                pbVar65[1] = pbVar65[1] + (&DAT_140818044)[*pbVar42 & 0xf] * '\x04';
                pbVar65 = pbVar65 + 2;
                uVar43 = uVar43 - 1;
                pbVar42 = pbVar42 + 1;
              } while (uVar43 != 0);
            }
            pbVar69 = pbVar69 + uVar32;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
    }
    else if (uVar29 == 8) {
      if ((*(int *)(param_1 + 0x12211c) == 0) || (*(int *)(param_1 + 0x1220f0) == 0x10)) {
        uVar43 = (ulonglong)uVar28;
        param_6 = 6;
        if (uVar28 != 0) {
          do {
            uVar49 = (ulonglong)uVar55;
            if (uVar55 != 0) {
              pbVar65 = pbVar64;
              uVar29 = param_10 * 6;
              do {
                uVar28 = uVar29 + param_10 * -5;
                uVar54 = uVar29 + (int)uVar61 + param_10 * -6;
                uVar48 = uVar29 + param_10 * -3;
                uVar2 = uVar29 + param_10 * -2;
                uVar3 = uVar29 - param_10;
                uVar4 = uVar29 + param_10;
                uVar44 = (ulonglong)uVar29;
                uVar29 = uVar29 + 1;
                *pbVar65 = (byte)((uint)(byte)(&DAT_140818044)[pbVar69[uVar28]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar54]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar48]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar2]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar3]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar4]] +
                                  (uint)(byte)(&DAT_140818044)[pbVar69[uVar44]] +
                                  (uint)(byte)(&DAT_140818044)
                                              [pbVar65[(longlong)pbVar69 - (longlong)pbVar64]] >> 2)
                ;
                uVar49 = uVar49 - 1;
                pbVar65 = pbVar65 + 1;
              } while (uVar49 != 0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar43 = uVar43 - 1;
          } while (uVar43 != 0);
          uVar49 = (ulonglong)(uVar55 + 4);
        }
        uVar61 = (ulonglong)uVar55;
        if (uVar41 != 0) {
          uVar43 = (ulonglong)uVar41;
          do {
            if (uVar55 != 0) {
              pbVar65 = pbVar64;
              uVar44 = uVar61;
              do {
                *pbVar65 = *pbVar65 +
                           (&DAT_140818044)[pbVar65[(longlong)pbVar69 - (longlong)pbVar64]];
                pbVar65 = pbVar65 + 1;
                uVar44 = uVar44 - 1;
              } while (uVar44 != 0);
            }
            pbVar69 = pbVar69 + uVar32;
            uVar43 = uVar43 - 1;
          } while (uVar43 != 0);
          if (uVar55 != 0) {
            do {
              *pbVar64 = *pbVar64 >> 2;
              pbVar64 = pbVar64 + 1;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      else {
        uVar43 = (ulonglong)uVar28;
        param_6 = 7;
        if (uVar28 != 0) {
          do {
            uVar49 = (ulonglong)uVar55;
            if (uVar55 != 0) {
              pbVar65 = pbVar64;
              uVar29 = param_10 * 6;
              do {
                uVar28 = param_10 * -5 + uVar29;
                uVar54 = (int)uVar61 + param_10 * -6 + uVar29;
                uVar48 = param_10 * -3 + uVar29;
                uVar2 = param_10 * -2 + uVar29;
                uVar3 = uVar29 - param_10;
                uVar4 = uVar29 + param_10;
                uVar44 = (ulonglong)uVar29;
                uVar29 = uVar29 + 1;
                *pbVar65 = (&DAT_140818044)[pbVar69[uVar28]] + (&DAT_140818044)[pbVar69[uVar54]] +
                           (&DAT_140818044)[pbVar69[uVar48]] + (&DAT_140818044)[pbVar69[uVar2]] +
                           (&DAT_140818044)[pbVar69[uVar3]] + (&DAT_140818044)[pbVar69[uVar4]] +
                           (&DAT_140818044)[pbVar69[uVar44]] +
                           (&DAT_140818044)[pbVar65[(longlong)pbVar69 - (longlong)pbVar64]];
                pbVar65 = pbVar65 + 1;
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar43 = uVar43 - 1;
          } while (uVar43 != 0);
          uVar49 = (ulonglong)(uVar55 + 4);
        }
        if (uVar41 != 0) {
          uVar61 = (ulonglong)uVar41;
          do {
            if (uVar55 != 0) {
              pbVar65 = pbVar64;
              uVar43 = (ulonglong)uVar55;
              do {
                *pbVar65 = *pbVar65 +
                           (&DAT_140818044)[pbVar65[(longlong)pbVar69 - (longlong)pbVar64]];
                pbVar65 = pbVar65 + 1;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
            pbVar69 = pbVar69 + uVar32;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
    }
    else if (uVar29 == 0x10) {
      if ((*(int *)(param_1 + 0x12211c) == 0) || (*(int *)(param_1 + 0x1220f0) == 0x10)) {
        uVar32 = (ulonglong)uVar28;
        param_6 = 6;
        if (uVar28 != 0) {
          do {
            local_110 = (byte *)(ulonglong)uVar55;
            if (uVar55 != 0) {
              uVar29 = param_10 * 0xe + 1;
              iVar67 = (int)uVar61 + param_10 * -0xe;
              local_128 = pbVar69;
              local_120 = pbVar64;
              do {
                iVar31 = (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -0xd + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + iVar67 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -0xb + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -10 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -9 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -8 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -7 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -6 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -5 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -4 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -3 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -2 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + -param_10 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + (param_10 - 1)]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -0xd + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[iVar67 + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -0xb + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -10 + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -9]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -8]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -7]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -6]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -5]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -4]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -3]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -2]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + -param_10]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 - 1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29]] +
                         (uint)(byte)(&DAT_140818044)[local_128[1]] +
                         (uint)(byte)(&DAT_140818044)[*local_128];
                bVar40 = (byte)iVar31;
                if (iVar31 == 0x100) {
                  bVar40 = 0xff;
                }
                local_128 = local_128 + 2;
                *local_120 = bVar40;
                local_120 = local_120 + 1;
                uVar29 = uVar29 + 2;
                local_110 = (byte *)((longlong)local_110 - 1);
              } while (local_110 != (byte *)0x0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar32 = uVar32 - 1;
          } while (uVar32 != 0);
          uVar49 = (ulonglong)(uVar55 + 4);
        }
        uVar61 = (ulonglong)uVar55;
        if (uVar41 != 0) {
          uVar32 = (ulonglong)uVar41;
          do {
            if (uVar55 != 0) {
              pbVar65 = pbVar64;
              uVar43 = uVar61;
              do {
                *pbVar65 = *pbVar65 +
                           (&DAT_140818044)[pbVar65[(longlong)pbVar69 - (longlong)pbVar64]];
                pbVar65 = pbVar65 + 1;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
            pbVar69 = pbVar69 + param_10;
            uVar32 = uVar32 - 1;
          } while (uVar32 != 0);
          if (uVar55 != 0) {
            do {
              *pbVar64 = *pbVar64 >> 2;
              pbVar64 = pbVar64 + 1;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      else {
        uVar32 = (ulonglong)uVar28;
        param_6 = 8;
        if (uVar28 != 0) {
          do {
            local_120 = (byte *)(ulonglong)uVar55;
            if (uVar55 != 0) {
              uVar29 = param_10 * 0xe + 1;
              iVar67 = (int)uVar61 + param_10 * -0xe;
              local_110 = pbVar64;
              local_108 = pbVar69;
              do {
                iVar31 = (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -8 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -7 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -6 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -5 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -4 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -3 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -2 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + -param_10 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + (param_10 - 1)]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -0xd + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[iVar67 + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -0xb + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[param_10 * -10 + uVar29]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -9]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -8]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -7]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -6]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -5]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -4]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -3]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -2]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + -param_10]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -0xd + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + iVar67 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -0xb + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -10 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 + param_10 * -9 + -1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29 - 1]] +
                         (uint)(byte)(&DAT_140818044)[pbVar69[uVar29]] +
                         (uint)(byte)(&DAT_140818044)[local_108[1]] +
                         (uint)(byte)(&DAT_140818044)[*local_108];
                bVar40 = (byte)iVar31;
                if (iVar31 == 0x100) {
                  bVar40 = 0xff;
                }
                local_108 = local_108 + 2;
                *local_110 = bVar40;
                local_110 = local_110 + 1;
                uVar29 = uVar29 + 2;
                local_120 = (byte *)((longlong)local_120 - 1);
              } while (local_120 != (byte *)0x0);
              uVar61 = (ulonglong)(param_10 * 2);
            }
            pbVar64 = pbVar64 + uVar50;
            pbVar69 = pbVar69 + uVar47;
            uVar32 = uVar32 - 1;
          } while (uVar32 != 0);
          uVar49 = (ulonglong)(uVar55 + 4);
        }
        if (uVar41 != 0) {
          uVar49 = (ulonglong)uVar41;
          do {
            pbVar65 = pbVar64;
            pbVar42 = pbVar69;
            uVar61 = (ulonglong)uVar55;
            if (uVar55 != 0) {
              do {
                if ((uint)(byte)(&DAT_140818044)[pbVar42[1]] +
                    (uint)(byte)(&DAT_140818044)[*pbVar42] + (uint)*pbVar65 < 0x100) {
                  *pbVar65 = (char)((uint)(byte)(&DAT_140818044)[pbVar42[1]] +
                                   (uint)(byte)(&DAT_140818044)[*pbVar42]) + *pbVar65;
                }
                else {
                  *pbVar65 = 0xff;
                }
                uVar61 = uVar61 - 1;
                pbVar65 = pbVar65 + 1;
                pbVar42 = pbVar42 + 2;
              } while (uVar61 != 0);
            }
            pbVar69 = pbVar69 + param_10;
            uVar49 = uVar49 - 1;
          } while (uVar49 != 0);
          uVar49 = (ulonglong)uVar50;
        }
      }
    }
  }
  auVar81 = _DAT_1404a8620;
  uVar29 = *(uint *)(param_1 + 0x12181c);
  if ((uVar29 & 1) == 0) {
    uVar27 = (ushort)param_2[4];
    uVar32 = (ulonglong)uVar27;
    bVar40 = 0;
    uVar25 = *(ushort *)((longlong)param_2 + 0x12);
    uVar61 = (ulonglong)uVar25;
    uVar28 = (uint)uVar27;
    if (*(int *)(param_1 + 0x12211c) == 0) {
      uVar41 = *(uint *)(param_1 + 0x11dbf0);
      pbVar64 = (byte *)((ulonglong)(uVar41 * local_90) + *(longlong *)(param_1 + 0x11dbe8));
      if (uVar29 == 0) {
        if (param_6 == 0) {
          if (uVar25 != 0) {
            do {
              FUN_1401ae2f0(pbVar64,param_7,uVar49);
              param_7 = param_7 + uVar49;
              pbVar64 = pbVar64 + uVar41;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else {
          if (param_6 != 5) {
            return 0xffffffff;
          }
          if (uVar25 != 0) {
            do {
              bVar40 = 0;
              bVar58 = 0x80;
              pbVar69 = param_7;
              pbVar65 = pbVar64;
              uVar29 = 0;
              if (uVar28 != 0) {
                do {
                  if ((uVar29 != 0) && ((uVar29 & 7) == 0)) {
                    *pbVar65 = bVar40;
                    bVar58 = 0x80;
                    pbVar65 = pbVar65 + 1;
                    bVar40 = 0;
                  }
                  bVar22 = bVar58 | bVar40;
                  if (*pbVar69 == 0) {
                    bVar22 = bVar40;
                  }
                  bVar40 = bVar22;
                  uVar29 = uVar29 + 1;
                  bVar58 = bVar58 >> 1;
                  pbVar69 = pbVar69 + 1;
                } while (uVar29 < uVar28);
              }
              param_7 = param_7 + uVar49;
              *pbVar65 = bVar40;
              pbVar64 = pbVar64 + uVar41;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      else if ((uVar29 - 2 & 0xffffffcf) == 0) {
        if (param_6 != 6) {
          return 0xffffffff;
        }
        if (uVar25 != 0) {
          uVar61 = (ulonglong)uVar25;
          do {
            if (uVar28 != 0) {
              pbVar69 = param_7;
              uVar43 = uVar32;
              do {
                if (*pbVar69 != 0) {
                  pbVar69[(longlong)pbVar64 - (longlong)param_7] = *pbVar69 - 1;
                }
                pbVar69 = pbVar69 + 1;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
            param_7 = param_7 + uVar49;
            pbVar64 = pbVar64 + uVar41;
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
    }
    else {
      uVar29 = *(uint *)(param_1 + 0x1220d8);
      uVar43 = (ulonglong)uVar29;
      uVar41 = *(uint *)(param_1 + 0x121cb8) | *(uint *)(param_1 + 0x121cbc) |
               *(uint *)(param_1 + 0x121cc0);
      puVar60 = (uint *)((longlong)(int)((uint)*(byte *)(param_1 + 0x121cac) * local_a8) +
                         (longlong)(int)(uVar29 * local_90) + *(longlong *)(param_1 + 0x1220e0));
      uVar46 = (ushort)uVar41;
      if (param_6 == 0) {
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          uVar32 = 0;
          if (*(int *)(param_1 + 0x121ccc) == 0xf) {
            if (uVar25 != 0) {
              do {
                uVar44 = uVar32;
                uVar45 = uVar32;
                puVar34 = puVar60;
                if (uVar28 != 0) {
                  do {
                    if ((uVar44 & 7) == 0) {
                      bVar40 = param_7[uVar45 >> 3];
                    }
                    uVar29 = (int)uVar44 + 1;
                    bVar58 = (char)bVar40 >> 7;
                    bVar40 = bVar40 * '\x02';
                    *(byte *)puVar34 = bVar58 & 0xf;
                    uVar44 = (ulonglong)uVar29;
                    uVar45 = uVar45 + 1;
                    puVar34 = (uint *)((longlong)puVar34 + 1);
                  } while (uVar29 < uVar28);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (uVar25 != 0) {
            do {
              uVar44 = uVar32;
              uVar45 = uVar32;
              puVar34 = puVar60;
              if (uVar28 != 0) {
                do {
                  if ((uVar44 & 7) == 0) {
                    bVar40 = param_7[uVar45 >> 3];
                  }
                  uVar29 = (int)uVar44 + 1;
                  *(char *)puVar34 = (char)bVar40 >> 7;
                  bVar40 = bVar40 * '\x02';
                  uVar44 = (ulonglong)uVar29;
                  uVar45 = uVar45 + 1;
                  puVar34 = (uint *)((longlong)puVar34 + 1);
                } while (uVar29 < uVar28);
              }
              param_7 = param_7 + uVar49;
              puVar60 = (uint *)((longlong)puVar60 + uVar43);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else if (*(int *)(param_1 + 0x1220f4) == 0) {
          if (uVar25 != 0) {
            do {
              puVar34 = puVar60;
              uVar32 = 0;
              uVar44 = 0;
              if (uVar28 != 0) {
                do {
                  if ((uVar32 & 7) == 0) {
                    bVar40 = param_7[uVar44 >> 3];
                  }
                  uVar27 = 0;
                  if ((char)bVar40 < '\0') {
                    uVar27 = (ushort)*(undefined4 *)(param_1 + 0x121cc4);
                  }
                  uVar29 = (int)uVar32 + 1;
                  *(ushort *)puVar34 = uVar27 | uVar46;
                  bVar40 = bVar40 * '\x02';
                  puVar34 = (uint *)((longlong)puVar34 + 2);
                  uVar32 = (ulonglong)uVar29;
                  uVar44 = uVar44 + 1;
                } while (uVar29 < uVar28);
              }
              param_7 = param_7 + uVar49;
              puVar60 = (uint *)((longlong)puVar60 + uVar43);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else if (uVar25 != 0) {
          do {
            uVar32 = 0;
            puVar34 = puVar60;
            uVar44 = 0;
            if (uVar28 != 0) {
              do {
                if ((uVar44 & 7) == 0) {
                  bVar40 = param_7[uVar32 >> 3];
                }
                if ((char)bVar40 < '\0') {
                  *(ushort *)puVar34 = *(ushort *)(param_1 + 0x121cc4) | uVar46;
                }
                else {
                  *(ushort *)puVar34 = 0;
                }
                uVar29 = (int)uVar44 + 1;
                bVar40 = bVar40 * '\x02';
                uVar32 = uVar32 + 1;
                puVar34 = (uint *)((longlong)puVar34 + 2);
                uVar44 = (ulonglong)uVar29;
              } while (uVar29 < uVar28);
            }
            param_7 = param_7 + uVar49;
            puVar60 = (uint *)((longlong)puVar60 + uVar43);
            uVar61 = uVar61 - 1;
          } while (uVar61 != 0);
        }
      }
      else {
        uVar47 = (uint)uVar27;
        if (param_6 == 5) {
          cVar5 = *(char *)(param_1 + 0x121cad);
          if (cVar5 == '\b') {
            uVar32 = 0;
            if (*(int *)(param_1 + 0x121ccc) == 0xf) {
              if (uVar25 != 0) {
                do {
                  auVar77 = _DAT_1404a8610;
                  if (uVar28 != 0) {
                    uVar44 = uVar32;
                    if ((0x1f < uVar28) &&
                       ((param_7 + (uVar27 - 1) < puVar60 ||
                        (uVar44 = 0, (byte *)((longlong)puVar60 + (ulonglong)(uVar27 - 1)) < param_7
                        )))) {
                      auVar78._0_12_ = ZEXT812(0);
                      auVar78._12_4_ = 0;
                      uVar44 = uVar32;
                      do {
                        pbVar64 = param_7 + uVar44;
                        uVar45 = (ulonglong)((int)uVar44 + 0x10);
                        auVar72[0] = -(*pbVar64 == 0);
                        auVar72[1] = -(pbVar64[1] == 0);
                        auVar72[2] = -(pbVar64[2] == 0);
                        auVar72[3] = -(pbVar64[3] == 0);
                        auVar72[4] = -(pbVar64[4] == 0);
                        auVar72[5] = -(pbVar64[5] == 0);
                        auVar72[6] = -(pbVar64[6] == 0);
                        auVar72[7] = -(pbVar64[7] == 0);
                        auVar72[8] = -(pbVar64[8] == 0);
                        auVar72[9] = -(pbVar64[9] == 0);
                        auVar72[10] = -(pbVar64[10] == 0);
                        auVar72[0xb] = -(pbVar64[0xb] == 0);
                        auVar72[0xc] = -(pbVar64[0xc] == 0);
                        auVar72[0xd] = -(pbVar64[0xd] == 0);
                        auVar72[0xe] = -(pbVar64[0xe] == 0);
                        auVar72[0xf] = -(pbVar64[0xf] == 0);
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar44) =
                             auVar77 & ~auVar72 & auVar81 | ~(~auVar72 & auVar81) & auVar78;
                        uVar29 = (int)uVar44 + 0x20;
                        uVar44 = (ulonglong)uVar29;
                        pbVar64 = param_7 + uVar45;
                        auVar73[0] = -(*pbVar64 == 0);
                        auVar73[1] = -(pbVar64[1] == 0);
                        auVar73[2] = -(pbVar64[2] == 0);
                        auVar73[3] = -(pbVar64[3] == 0);
                        auVar73[4] = -(pbVar64[4] == 0);
                        auVar73[5] = -(pbVar64[5] == 0);
                        auVar73[6] = -(pbVar64[6] == 0);
                        auVar73[7] = -(pbVar64[7] == 0);
                        auVar73[8] = -(pbVar64[8] == 0);
                        auVar73[9] = -(pbVar64[9] == 0);
                        auVar73[10] = -(pbVar64[10] == 0);
                        auVar73[0xb] = -(pbVar64[0xb] == 0);
                        auVar73[0xc] = -(pbVar64[0xc] == 0);
                        auVar73[0xd] = -(pbVar64[0xd] == 0);
                        auVar73[0xe] = -(pbVar64[0xe] == 0);
                        auVar73[0xf] = -(pbVar64[0xf] == 0);
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar45) =
                             auVar77 & ~auVar73 & auVar81 | ~(~auVar73 & auVar81) & auVar78;
                      } while (uVar29 < (uVar27 & 0xffffffe0));
                    }
                    if ((uint)uVar44 < uVar47) {
                      uVar45 = (ulonglong)(uVar47 - (uint)uVar44);
                      pbVar64 = (byte *)(uVar44 + (longlong)puVar60);
                      do {
                        *pbVar64 = -(pbVar64[(longlong)param_7 - (longlong)puVar60] != 0) & 0xf;
                        uVar45 = uVar45 - 1;
                        pbVar64 = pbVar64 + 1;
                      } while (uVar45 != 0);
                    }
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                auVar77 = _DAT_1404a8620;
                if (uVar47 != 0) {
                  uVar44 = uVar32;
                  if ((0x1f < uVar28) &&
                     ((param_7 + (uVar27 - 1) < puVar60 ||
                      (uVar44 = 0, (byte *)((longlong)puVar60 + (ulonglong)(uVar27 - 1)) < param_7))
                     )) {
                    auVar76._0_12_ = ZEXT812(0);
                    auVar76._12_4_ = 0;
                    uVar44 = uVar32;
                    do {
                      pbVar64 = param_7 + uVar44;
                      uVar45 = (ulonglong)((int)uVar44 + 0x10);
                      auVar74[0] = -(*pbVar64 == 0);
                      auVar74[1] = -(pbVar64[1] == 0);
                      auVar74[2] = -(pbVar64[2] == 0);
                      auVar74[3] = -(pbVar64[3] == 0);
                      auVar74[4] = -(pbVar64[4] == 0);
                      auVar74[5] = -(pbVar64[5] == 0);
                      auVar74[6] = -(pbVar64[6] == 0);
                      auVar74[7] = -(pbVar64[7] == 0);
                      auVar74[8] = -(pbVar64[8] == 0);
                      auVar74[9] = -(pbVar64[9] == 0);
                      auVar74[10] = -(pbVar64[10] == 0);
                      auVar74[0xb] = -(pbVar64[0xb] == 0);
                      auVar74[0xc] = -(pbVar64[0xc] == 0);
                      auVar74[0xd] = -(pbVar64[0xd] == 0);
                      auVar74[0xe] = -(pbVar64[0xe] == 0);
                      auVar74[0xf] = -(pbVar64[0xf] == 0);
                      *(undefined1 (*) [16])((longlong)puVar60 + uVar44) =
                           auVar77 & ~auVar74 & auVar81 | ~(~auVar74 & auVar81) & auVar76;
                      uVar29 = (int)uVar44 + 0x20;
                      uVar44 = (ulonglong)uVar29;
                      pbVar64 = param_7 + uVar45;
                      auVar75[0] = -(*pbVar64 == 0);
                      auVar75[1] = -(pbVar64[1] == 0);
                      auVar75[2] = -(pbVar64[2] == 0);
                      auVar75[3] = -(pbVar64[3] == 0);
                      auVar75[4] = -(pbVar64[4] == 0);
                      auVar75[5] = -(pbVar64[5] == 0);
                      auVar75[6] = -(pbVar64[6] == 0);
                      auVar75[7] = -(pbVar64[7] == 0);
                      auVar75[8] = -(pbVar64[8] == 0);
                      auVar75[9] = -(pbVar64[9] == 0);
                      auVar75[10] = -(pbVar64[10] == 0);
                      auVar75[0xb] = -(pbVar64[0xb] == 0);
                      auVar75[0xc] = -(pbVar64[0xc] == 0);
                      auVar75[0xd] = -(pbVar64[0xd] == 0);
                      auVar75[0xe] = -(pbVar64[0xe] == 0);
                      auVar75[0xf] = -(pbVar64[0xf] == 0);
                      *(undefined1 (*) [16])((longlong)puVar60 + uVar45) =
                           auVar77 & ~auVar75 & auVar81 | ~(~auVar75 & auVar81) & auVar76;
                    } while (uVar29 < (uVar27 & 0xffffffe0));
                  }
                  if ((uint)uVar44 < uVar28) {
                    uVar45 = (ulonglong)((uint)uVar27 - (uint)uVar44);
                    pbVar64 = (byte *)(uVar44 + (longlong)puVar60);
                    do {
                      *pbVar64 = -(pbVar64[(longlong)param_7 - (longlong)puVar60] != 0);
                      uVar45 = uVar45 - 1;
                      pbVar64 = pbVar64 + 1;
                    } while (uVar45 != 0);
                  }
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (cVar5 == '\x10') {
            uVar46 = *(ushort *)(param_1 + 0x121cc4) | uVar46;
            if (*(int *)(param_1 + 0x1220f4) == 0) {
              if (uVar25 != 0) {
                do {
                  pbVar64 = param_7;
                  puVar34 = puVar60;
                  uVar44 = uVar32;
                  if (uVar47 != 0) {
                    do {
                      uVar29 = (uint)uVar46;
                      if (*pbVar64 == 0) {
                        uVar29 = uVar41;
                      }
                      *(ushort *)puVar34 = (ushort)uVar29;
                      uVar44 = uVar44 - 1;
                      pbVar64 = pbVar64 + 1;
                      puVar34 = (uint *)((longlong)puVar34 + 2);
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                pbVar64 = param_7;
                puVar34 = puVar60;
                uVar44 = uVar32;
                if (uVar27 != 0) {
                  do {
                    uVar25 = uVar46;
                    if (*pbVar64 == 0) {
                      uVar25 = 0;
                    }
                    *(ushort *)puVar34 = uVar25;
                    uVar44 = uVar44 - 1;
                    pbVar64 = pbVar64 + 1;
                    puVar34 = (uint *)((longlong)puVar34 + 2);
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (cVar5 == ' ') {
            uVar29 = *(uint *)(param_1 + 0x121cc4) | uVar41;
            if (*(int *)(param_1 + 0x1220f4) == 0) {
              if (uVar25 != 0) {
                do {
                  pbVar64 = param_7;
                  puVar34 = puVar60;
                  uVar44 = uVar32;
                  if (uVar47 != 0) {
                    do {
                      uVar28 = uVar41;
                      if (*pbVar64 != 0) {
                        uVar28 = uVar29;
                      }
                      *puVar34 = uVar28;
                      uVar44 = uVar44 - 1;
                      pbVar64 = pbVar64 + 1;
                      puVar34 = puVar34 + 1;
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                pbVar64 = param_7;
                puVar34 = puVar60;
                uVar44 = uVar32;
                if (uVar47 != 0) {
                  do {
                    uVar28 = 0;
                    if (*pbVar64 != 0) {
                      uVar28 = uVar29;
                    }
                    *puVar34 = uVar28;
                    uVar44 = uVar44 - 1;
                    pbVar64 = pbVar64 + 1;
                    puVar34 = puVar34 + 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
        }
        else if (param_6 == 6) {
          cVar5 = *(char *)(param_1 + 0x121cad);
          if (cVar5 == '\b') {
            if (*(int *)(param_1 + 0x121ccc) == 0xf) {
              if (uVar25 != 0) {
                do {
                  cVar21 = UNK_1404a860f;
                  cVar20 = UNK_1404a860e;
                  cVar19 = UNK_1404a860d;
                  cVar18 = UNK_1404a860c;
                  cVar17 = UNK_1404a860b;
                  cVar16 = UNK_1404a860a;
                  cVar15 = UNK_1404a8609;
                  cVar14 = UNK_1404a8608;
                  cVar12 = UNK_1404a8607;
                  cVar11 = UNK_1404a8606;
                  cVar10 = UNK_1404a8605;
                  cVar9 = UNK_1404a8604;
                  cVar8 = UNK_1404a8603;
                  cVar7 = UNK_1404a8602;
                  cVar6 = UNK_1404a8601;
                  cVar5 = DAT_1404a8600;
                  if (uVar27 != 0) {
                    uVar32 = 0;
                    if ((0x1f < uVar28) &&
                       ((param_7 + (uVar27 - 1) < puVar60 ||
                        (uVar32 = 0, (byte *)((longlong)puVar60 + (ulonglong)(uVar27 - 1)) < param_7
                        )))) {
                      auVar81._0_12_ = ZEXT812(0);
                      auVar81._12_4_ = 0;
                      uVar32 = 0;
                      do {
                        pbVar64 = param_7 + uVar32;
                        uVar44 = (ulonglong)((int)uVar32 + 0x10);
                        auVar79[0] = -(*pbVar64 == 0);
                        auVar79[1] = -(pbVar64[1] == 0);
                        auVar79[2] = -(pbVar64[2] == 0);
                        auVar79[3] = -(pbVar64[3] == 0);
                        auVar79[4] = -(pbVar64[4] == 0);
                        auVar79[5] = -(pbVar64[5] == 0);
                        auVar79[6] = -(pbVar64[6] == 0);
                        auVar79[7] = -(pbVar64[7] == 0);
                        auVar79[8] = -(pbVar64[8] == 0);
                        auVar79[9] = -(pbVar64[9] == 0);
                        auVar79[10] = -(pbVar64[10] == 0);
                        auVar79[0xb] = -(pbVar64[0xb] == 0);
                        auVar79[0xc] = -(pbVar64[0xc] == 0);
                        auVar79[0xd] = -(pbVar64[0xd] == 0);
                        auVar79[0xe] = -(pbVar64[0xe] == 0);
                        auVar79[0xf] = -(pbVar64[0xf] == 0);
                        auVar76 = ~auVar79 & *(undefined1 (*) [16])((longlong)puVar60 + uVar32) |
                                  auVar81 & auVar79;
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar32) = auVar76;
                        pbVar64 = param_7 + uVar32;
                        auVar77[0] = *pbVar64 - cVar5;
                        auVar77[1] = pbVar64[1] - cVar6;
                        auVar77[2] = pbVar64[2] - cVar7;
                        auVar77[3] = pbVar64[3] - cVar8;
                        auVar77[4] = pbVar64[4] - cVar9;
                        auVar77[5] = pbVar64[5] - cVar10;
                        auVar77[6] = pbVar64[6] - cVar11;
                        auVar77[7] = pbVar64[7] - cVar12;
                        auVar77[8] = pbVar64[8] - cVar14;
                        auVar77[9] = pbVar64[9] - cVar15;
                        auVar77[10] = pbVar64[10] - cVar16;
                        auVar77[0xb] = pbVar64[0xb] - cVar17;
                        auVar77[0xc] = pbVar64[0xc] - cVar18;
                        auVar77[0xd] = pbVar64[0xd] - cVar19;
                        auVar77[0xe] = pbVar64[0xe] - cVar20;
                        auVar77[0xf] = pbVar64[0xf] - cVar21;
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar32) =
                             ~auVar79 & auVar77 | auVar79 & auVar76;
                        uVar29 = (int)uVar32 + 0x20;
                        uVar32 = (ulonglong)uVar29;
                        pbVar64 = param_7 + uVar44;
                        auVar80[0] = -(*pbVar64 == 0);
                        auVar80[1] = -(pbVar64[1] == 0);
                        auVar80[2] = -(pbVar64[2] == 0);
                        auVar80[3] = -(pbVar64[3] == 0);
                        auVar80[4] = -(pbVar64[4] == 0);
                        auVar80[5] = -(pbVar64[5] == 0);
                        auVar80[6] = -(pbVar64[6] == 0);
                        auVar80[7] = -(pbVar64[7] == 0);
                        auVar80[8] = -(pbVar64[8] == 0);
                        auVar80[9] = -(pbVar64[9] == 0);
                        auVar80[10] = -(pbVar64[10] == 0);
                        auVar80[0xb] = -(pbVar64[0xb] == 0);
                        auVar80[0xc] = -(pbVar64[0xc] == 0);
                        auVar80[0xd] = -(pbVar64[0xd] == 0);
                        auVar80[0xe] = -(pbVar64[0xe] == 0);
                        auVar80[0xf] = -(pbVar64[0xf] == 0);
                        auVar77 = auVar81 & auVar80 |
                                  ~auVar80 & *(undefined1 (*) [16])((longlong)puVar60 + uVar44);
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar44) = auVar77;
                        pbVar64 = param_7 + uVar44;
                        auVar71[0] = *pbVar64 - cVar5;
                        auVar71[1] = pbVar64[1] - cVar6;
                        auVar71[2] = pbVar64[2] - cVar7;
                        auVar71[3] = pbVar64[3] - cVar8;
                        auVar71[4] = pbVar64[4] - cVar9;
                        auVar71[5] = pbVar64[5] - cVar10;
                        auVar71[6] = pbVar64[6] - cVar11;
                        auVar71[7] = pbVar64[7] - cVar12;
                        auVar71[8] = pbVar64[8] - cVar14;
                        auVar71[9] = pbVar64[9] - cVar15;
                        auVar71[10] = pbVar64[10] - cVar16;
                        auVar71[0xb] = pbVar64[0xb] - cVar17;
                        auVar71[0xc] = pbVar64[0xc] - cVar18;
                        auVar71[0xd] = pbVar64[0xd] - cVar19;
                        auVar71[0xe] = pbVar64[0xe] - cVar20;
                        auVar71[0xf] = pbVar64[0xf] - cVar21;
                        *(undefined1 (*) [16])((longlong)puVar60 + uVar44) =
                             ~auVar80 & auVar71 | auVar80 & auVar77;
                      } while (uVar29 < (uVar27 & 0xffffffe0));
                    }
                    if ((uint)uVar32 < uVar28) {
                      pbVar64 = (byte *)(uVar32 + (longlong)puVar60);
                      uVar32 = (ulonglong)((uint)uVar27 - (uint)uVar32);
                      do {
                        if (pbVar64[(longlong)param_7 - (longlong)puVar60] == 0) {
                          *pbVar64 = 0;
                        }
                        else {
                          *pbVar64 = pbVar64[(longlong)param_7 - (longlong)puVar60] - 1;
                        }
                        pbVar64 = pbVar64 + 1;
                        uVar32 = uVar32 - 1;
                      } while (uVar32 != 0);
                    }
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                if (uVar27 != 0) {
                  puVar34 = puVar60;
                  uVar44 = uVar32;
                  do {
                    bVar40 = *(byte *)((longlong)puVar34 + ((longlong)param_7 - (longlong)puVar60));
                    if (bVar40 == 0) {
                      *(byte *)puVar34 = 0;
                    }
                    else {
                      *(byte *)puVar34 = bVar40 * '\x10' - 1;
                    }
                    puVar34 = (uint *)((longlong)puVar34 + 1);
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if ((((*(int *)(param_1 + 0x121cc4) == 0xf000) &&
                    (*(uint *)(param_1 + 0x121cb8) == 0xf00)) &&
                   (*(uint *)(param_1 + 0x121cbc) == 0xf0)) &&
                  (*(uint *)(param_1 + 0x121cc0) == 0xf)) {
            if (*(int *)(param_1 + 0x1220f4) == 0) {
              if (uVar25 != 0) {
                do {
                  uVar44 = uVar32;
                  puVar34 = puVar60;
                  pbVar64 = param_7;
                  if (uVar47 != 0) {
                    do {
                      if (*pbVar64 == 0) {
                        *(ushort *)puVar34 = 0xfff;
                      }
                      else {
                        *(ushort *)puVar34 = (ushort)*pbVar64 * 0x1000 - 1;
                      }
                      uVar44 = uVar44 - 1;
                      puVar34 = (uint *)((longlong)puVar34 + 2);
                      pbVar64 = pbVar64 + 1;
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                puVar34 = puVar60;
                pbVar64 = param_7;
                uVar44 = uVar32;
                if (uVar27 != 0) {
                  do {
                    bVar40 = *pbVar64;
                    if (bVar40 == 0x10) {
                      *(ushort *)puVar34 = 0xffff;
                    }
                    else if (bVar40 == 0) {
                      *(ushort *)puVar34 = 0;
                    }
                    else {
                      *(ushort *)puVar34 =
                           (((ushort)bVar40 << 4 | (ushort)bVar40) << 4 | (ushort)bVar40) << 4 |
                           (ushort)bVar40;
                    }
                    uVar44 = uVar44 - 1;
                    puVar34 = (uint *)((longlong)puVar34 + 2);
                    pbVar64 = pbVar64 + 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (cVar5 == '\x10') {
            if (*(int *)(param_1 + 0x1220f4) == 0) {
              if (uVar25 != 0) {
                do {
                  uVar44 = uVar32;
                  puVar34 = puVar60;
                  pbVar64 = param_7;
                  if (uVar47 != 0) {
                    do {
                      if (*pbVar64 == 0) {
                        *(ushort *)puVar34 = uVar46;
                      }
                      else {
                        *(ushort *)puVar34 =
                             ((ushort)*pbVar64 <<
                             (*(char *)(param_1 + 0x121cb7) + *(char *)(param_1 + 0x121cb3) + -4 &
                             0x1fU)) - 1 | uVar46;
                      }
                      uVar44 = uVar44 - 1;
                      puVar34 = (uint *)((longlong)puVar34 + 2);
                      pbVar64 = pbVar64 + 1;
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              cVar5 = *(char *)(param_1 + 0x121cb6);
              cVar6 = *(char *)(param_1 + 0x121cb2);
              cVar7 = *(char *)(param_1 + 0x121cb5);
              cVar8 = *(char *)(param_1 + 0x121cb1);
              cVar9 = *(char *)(param_1 + 0x121cb4);
              cVar10 = *(char *)(param_1 + 0x121cb0);
              cVar11 = *(char *)(param_1 + 0x121cb7);
              cVar12 = *(char *)(param_1 + 0x121cb3);
              do {
                pbVar64 = param_7;
                uVar44 = uVar32;
                puVar34 = puVar60;
                if (uVar27 != 0) {
                  do {
                    bVar40 = *pbVar64;
                    if (bVar40 == 0x10) {
                      *(ushort *)puVar34 = 0xffff;
                    }
                    else if (bVar40 == 0) {
                      *(ushort *)puVar34 = 0;
                    }
                    else {
                      *(ushort *)puVar34 =
                           (ushort)bVar40 << (cVar5 + -4 + cVar6 & 0x1fU) |
                           (ushort)bVar40 << (cVar7 + -4 + cVar8 & 0x1fU) |
                           (ushort)bVar40 << (cVar9 + -4 + cVar10 & 0x1fU) |
                           (ushort)bVar40 << (cVar11 + -4 + cVar12 & 0x1fU);
                    }
                    uVar44 = uVar44 - 1;
                    pbVar64 = pbVar64 + 1;
                    puVar34 = (uint *)((longlong)puVar34 + 2);
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (cVar5 == ' ') {
            if (*(int *)(param_1 + 0x1220f4) == 0) {
              if (uVar25 != 0) {
                do {
                  uVar44 = uVar32;
                  puVar34 = puVar60;
                  pbVar64 = param_7;
                  if (uVar47 != 0) {
                    do {
                      if (*pbVar64 == 0) {
                        *puVar34 = uVar41;
                      }
                      else {
                        *puVar34 = ((uint)*pbVar64 <<
                                   (*(char *)(param_1 + 0x121cb7) +
                                    *(char *)(param_1 + 0x121cb3) + -4 & 0x1fU)) - 1 | uVar41;
                      }
                      uVar44 = uVar44 - 1;
                      puVar34 = puVar34 + 1;
                      pbVar64 = pbVar64 + 1;
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              cVar5 = *(char *)(param_1 + 0x121cb6);
              cVar6 = *(char *)(param_1 + 0x121cb2);
              cVar7 = *(char *)(param_1 + 0x121cb5);
              cVar8 = *(char *)(param_1 + 0x121cb1);
              cVar9 = *(char *)(param_1 + 0x121cb4);
              cVar10 = *(char *)(param_1 + 0x121cb0);
              cVar11 = *(char *)(param_1 + 0x121cb7);
              cVar12 = *(char *)(param_1 + 0x121cb3);
              do {
                pbVar64 = param_7;
                uVar44 = uVar32;
                puVar34 = puVar60;
                if (uVar27 != 0) {
                  do {
                    bVar40 = *pbVar64;
                    if (bVar40 == 0x10) {
                      *puVar34 = 0xffffffff;
                    }
                    else if (bVar40 == 0) {
                      *puVar34 = 0;
                    }
                    else {
                      uVar29 = (uint)bVar40;
                      *puVar34 = uVar29 << (cVar5 + -4 + cVar6 & 0x1fU) |
                                 (uint)bVar40 << (cVar7 + -4 + cVar8 & 0x1fU) |
                                 uVar29 << (cVar9 + -4 + cVar10 & 0x1fU) |
                                 uVar29 << (cVar11 + -4 + cVar12 & 0x1fU);
                    }
                    uVar44 = uVar44 - 1;
                    pbVar64 = pbVar64 + 1;
                    puVar34 = puVar34 + 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
        }
        else if (param_6 == 7) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (*(int *)(param_1 + 0x121ccc) == 0xf) {
              if (uVar25 != 0) {
                do {
                  if (uVar28 != 0) {
                    puVar34 = puVar60;
                    uVar44 = uVar32;
                    do {
                      bVar40 = *(byte *)((longlong)puVar34 + ((longlong)param_7 - (longlong)puVar60)
                                        );
                      if (bVar40 < 5) {
                        *(byte *)puVar34 = 0;
                      }
                      else {
                        *(byte *)puVar34 = (bVar40 >> 2) - 1;
                      }
                      puVar34 = (uint *)((longlong)puVar34 + 1);
                      uVar44 = uVar44 - 1;
                    } while (uVar44 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + uVar43);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                if (uVar27 != 0) {
                  puVar34 = puVar60;
                  uVar44 = uVar32;
                  do {
                    bVar40 = *(byte *)((longlong)puVar34 + ((longlong)param_7 - (longlong)puVar60));
                    if (bVar40 == 0) {
                      *(byte *)puVar34 = 0;
                    }
                    else {
                      *(byte *)puVar34 = bVar40 * '\x04' - 1;
                    }
                    puVar34 = (uint *)((longlong)puVar34 + 1);
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (uVar25 != 0) {
              do {
                uVar44 = uVar32;
                puVar34 = puVar60;
                pbVar64 = param_7;
                if (uVar27 != 0) {
                  do {
                    if (*pbVar64 == 0) {
                      *puVar34 = uVar41;
                    }
                    else {
                      *puVar34 = *pbVar64 - 1 <<
                                 (*(char *)(param_1 + 0x121cb7) + *(char *)(param_1 + 0x121cb3) + -6
                                 & 0x1fU) | uVar41;
                    }
                    uVar44 = uVar44 - 1;
                    puVar34 = puVar34 + 1;
                    pbVar64 = pbVar64 + 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (uVar25 != 0) {
            cVar5 = *(char *)(param_1 + 0x121cb6);
            cVar6 = *(char *)(param_1 + 0x121cb2);
            cVar7 = *(char *)(param_1 + 0x121cb5);
            cVar8 = *(char *)(param_1 + 0x121cb1);
            cVar9 = *(char *)(param_1 + 0x121cb4);
            cVar10 = *(char *)(param_1 + 0x121cb0);
            cVar11 = *(char *)(param_1 + 0x121cb7);
            cVar12 = *(char *)(param_1 + 0x121cb3);
            do {
              pbVar64 = param_7;
              uVar44 = uVar32;
              puVar34 = puVar60;
              if (uVar27 != 0) {
                do {
                  bVar40 = *pbVar64;
                  if (bVar40 == 0x40) {
                    *puVar34 = 0xffffffff;
                  }
                  else if (bVar40 == 0) {
                    *puVar34 = 0;
                  }
                  else {
                    uVar29 = (uint)bVar40;
                    *puVar34 = uVar29 << (cVar5 + -6 + cVar6 & 0x1fU) |
                               (uint)bVar40 << (cVar7 + -6 + cVar8 & 0x1fU) |
                               uVar29 << (cVar9 + -6 + cVar10 & 0x1fU) |
                               uVar29 << (cVar11 + -6 + cVar12 & 0x1fU);
                  }
                  uVar44 = uVar44 - 1;
                  pbVar64 = pbVar64 + 1;
                  puVar34 = puVar34 + 1;
                } while (uVar44 != 0);
              }
              param_7 = param_7 + uVar49;
              puVar60 = (uint *)((longlong)puVar60 + uVar43);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else {
          if (param_6 != 8) {
            return 0xffffffff;
          }
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (*(int *)(param_1 + 0x121ccc) == 0xf) {
              if (uVar25 != 0) {
                do {
                  if (uVar28 != 0) {
                    puVar34 = puVar60;
                    uVar43 = uVar32;
                    do {
                      *(byte *)puVar34 =
                           *(byte *)(((longlong)param_7 - (longlong)puVar60) + (longlong)puVar34) >>
                           4;
                      uVar43 = uVar43 - 1;
                      puVar34 = (uint *)((longlong)puVar34 + 1);
                    } while (uVar43 != 0);
                  }
                  param_7 = param_7 + uVar49;
                  puVar60 = (uint *)((longlong)puVar60 + (ulonglong)uVar29);
                  uVar61 = uVar61 - 1;
                } while (uVar61 != 0);
              }
            }
            else if (uVar25 != 0) {
              do {
                if (uVar28 != 0) {
                  puVar34 = puVar60;
                  uVar44 = uVar32;
                  do {
                    *(byte *)puVar34 =
                         *(byte *)((longlong)puVar34 + ((longlong)param_7 - (longlong)puVar60));
                    puVar34 = (uint *)((longlong)puVar34 + 1);
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (uVar25 != 0) {
              do {
                uVar44 = uVar32;
                pbVar64 = param_7;
                puVar34 = puVar60;
                if (uVar28 != 0) {
                  do {
                    *puVar34 = (uint)*pbVar64 <<
                               (*(char *)(param_1 + 0x121cb3) + *(char *)(param_1 + 0x121cb7) + -8 &
                               0x1fU) | uVar41;
                    uVar44 = uVar44 - 1;
                    pbVar64 = pbVar64 + 1;
                    puVar34 = puVar34 + 1;
                  } while (uVar44 != 0);
                }
                param_7 = param_7 + uVar49;
                puVar60 = (uint *)((longlong)puVar60 + uVar43);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (uVar25 != 0) {
            cVar5 = *(char *)(param_1 + 0x121cb5);
            cVar6 = *(char *)(param_1 + 0x121cb1);
            cVar7 = *(char *)(param_1 + 0x121cb4);
            cVar8 = *(char *)(param_1 + 0x121cb0);
            cVar9 = *(char *)(param_1 + 0x121cb7);
            cVar10 = *(char *)(param_1 + 0x121cb3);
            cVar11 = *(char *)(param_1 + 0x121cb6);
            cVar12 = *(char *)(param_1 + 0x121cb2);
            do {
              puVar34 = puVar60;
              uVar44 = uVar32;
              pbVar64 = param_7;
              if (uVar28 != 0) {
                do {
                  uVar29 = (uint)*pbVar64;
                  *puVar34 = uVar29 << (cVar11 + -8 + cVar12 & 0x1fU) |
                             (uint)*pbVar64 << (cVar9 + -8 + cVar10 & 0x1fU) |
                             uVar29 << (cVar7 + -8 + cVar8 & 0x1fU) |
                             uVar29 << (cVar5 + -8 + cVar6 & 0x1fU);
                  uVar44 = uVar44 - 1;
                  puVar34 = puVar34 + 1;
                  pbVar64 = pbVar64 + 1;
                } while (uVar44 != 0);
              }
              param_7 = param_7 + uVar49;
              puVar60 = (uint *)((longlong)puVar60 + uVar43);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      if (param_14 != 0) {
        iVar67 = local_a8 + -1;
        iVar31 = local_90 + -1;
        local_d0 = CONCAT44(iVar31,iVar67);
        iVar56 = local_a8 + -1 + (uint)*(ushort *)(param_1 + 0x1217d6);
        iVar59 = local_90 + -1 + (uint)*(ushort *)(param_1 + 0x1217d6);
        if (*(int *)(param_1 + 0x122108) == 0) {
          *(undefined4 *)(param_1 + 0x122108) = 1;
          *(undefined8 *)(param_1 + 0x12210c) = local_d0;
          *(ulonglong *)(param_1 + 0x122114) = CONCAT44(iVar59,iVar56);
        }
        else {
          if (iVar67 < *(int *)(param_1 + 0x12210c)) {
            *(int *)(param_1 + 0x12210c) = iVar67;
          }
          if (iVar31 < *(int *)(param_1 + 0x122110)) {
            *(int *)(param_1 + 0x122110) = iVar31;
          }
          if (*(int *)(param_1 + 0x122114) < iVar56) {
            *(int *)(param_1 + 0x122114) = iVar56;
          }
          if (*(int *)(param_1 + 0x122118) < iVar59) {
            *(int *)(param_1 + 0x122118) = iVar59;
          }
        }
      }
    }
  }
  else {
    bVar40 = 0;
    uVar27 = (ushort)param_2[4];
    uVar61 = (ulonglong)uVar27;
    uVar28 = (uint)*(ushort *)((longlong)param_2 + 0x12);
    iVar67 = *(int *)(param_1 + 0x121820);
    lVar68 = (longlong)iVar67;
    iVar31 = *(int *)(param_1 + 0x121c58);
    pcVar62 = &DAT_14056c400 + (longlong)(iVar67 + -1) * 0x51;
    pcVar63 = *(char **)(param_1 + 0x121c60);
    if (*(int *)(param_1 + 0x12211c) == 0) {
      iVar56 = *(int *)(param_1 + 0x11dbf0);
      lVar35 = (longlong)iVar56;
      if (uVar29 == 1) {
        lVar52 = (longlong)((local_bc + local_90) * iVar56) + (longlong)(local_bc + local_a8) +
                 *(longlong *)(param_1 + 0x11dbe8);
        if (param_6 == 0) {
          if (iVar67 == 1) {
            if (uVar28 != 0) {
              uVar32 = (ulonglong)uVar28;
              do {
                uVar43 = 0;
                uVar44 = 0;
                if (uVar61 != 0) {
                  do {
                    iVar67 = (int)uVar44;
                    if ((uVar44 & 7) == 0) {
                      iVar31 = iVar67;
                      if (iVar67 < 0) {
                        iVar31 = iVar67 + 7;
                      }
                      bVar40 = param_7[iVar31 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      *(undefined1 *)(lVar52 + uVar43) = 1;
                      if (*(char *)(lVar52 + -1 + uVar43) != '\x01') {
                        *(undefined1 *)(lVar52 + -1 + uVar43) = 2;
                      }
                      if (*(char *)(lVar52 + 1 + uVar43) != '\x01') {
                        *(undefined1 *)(lVar52 + 1 + uVar43) = 2;
                      }
                      if (*(char *)((lVar52 - lVar35) + uVar43) != '\x01') {
                        *(undefined1 *)((lVar52 - lVar35) + uVar43) = 2;
                      }
                      if (*(char *)(lVar35 + lVar52 + uVar43) != '\x01') {
                        *(undefined1 *)(lVar35 + lVar52 + uVar43) = 2;
                      }
                    }
                    uVar43 = uVar43 + 1;
                    bVar40 = bVar40 * '\x02';
                    uVar44 = (ulonglong)(iVar67 + 1);
                  } while ((longlong)uVar43 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar52 = lVar52 + lVar35;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
          else {
            uVar32 = (ulonglong)uVar28;
            if (iVar67 < 5) {
              if (uVar28 != 0) {
                do {
                  uVar44 = 0;
                  param_5 = 0;
                  uVar43 = uVar44;
                  if (uVar61 != 0) {
                    do {
                      uVar28 = (int)uVar44 >> 0x1f & 7;
                      uVar29 = (int)uVar44 + uVar28;
                      if ((uVar29 & 7) == uVar28) {
                        bVar40 = param_7[(int)uVar29 >> 3];
                      }
                      if ((char)bVar40 < '\0') {
                        *(undefined1 *)(lVar52 + uVar43) = 1;
                        iVar31 = iVar67 + 1;
                        if (-iVar67 < iVar31) {
                          pcVar63 = pcVar62 + lVar68;
                          lVar37 = -iVar67 * iVar56 + lVar52 + uVar43;
                          uVar44 = (ulonglong)(uint)(iVar31 + iVar67);
                          lVar53 = -lVar68;
                          do {
                            for (; lVar53 < iVar31; lVar53 = lVar53 + 1) {
                              if ((pcVar63[lVar53] != '\0') &&
                                 (*(char *)(lVar53 + lVar37) != '\x01')) {
                                *(undefined1 *)(lVar53 + lVar37) = 2;
                              }
                            }
                            pcVar63 = pcVar63 + 9;
                            lVar37 = lVar37 + lVar35;
                            uVar44 = uVar44 - 1;
                            lVar53 = -lVar68;
                          } while (uVar44 != 0);
                        }
                      }
                      uVar43 = uVar43 + 1;
                      param_5 = param_5 + 1;
                      uVar44 = (ulonglong)param_5;
                      bVar40 = bVar40 * '\x02';
                    } while ((longlong)uVar43 < (longlong)uVar61);
                  }
                  param_7 = param_7 + uVar49;
                  lVar52 = lVar52 + lVar35;
                  uVar32 = uVar32 - 1;
                } while (uVar32 != 0);
              }
            }
            else if (uVar28 != 0) {
              do {
                uVar44 = 0;
                param_5 = 0;
                uVar43 = uVar44;
                if (uVar61 != 0) {
                  do {
                    uVar28 = (int)uVar44 >> 0x1f & 7;
                    uVar29 = (int)uVar44 + uVar28;
                    if ((uVar29 & 7) == uVar28) {
                      bVar40 = param_7[(int)uVar29 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      *(undefined1 *)(lVar52 + uVar43) = 1;
                      iVar59 = iVar67 + 1;
                      if (-iVar67 < iVar59) {
                        lVar37 = -iVar67 * iVar56 + lVar52 + uVar43;
                        pcVar62 = pcVar63 + lVar68;
                        uVar44 = (ulonglong)(uint)(iVar59 + iVar67);
                        lVar53 = -lVar68;
                        do {
                          for (; lVar53 < iVar59; lVar53 = lVar53 + 1) {
                            if ((pcVar62[lVar53] != '\0') && (*(char *)(lVar37 + lVar53) != '\x01'))
                            {
                              *(undefined1 *)(lVar37 + lVar53) = 2;
                            }
                          }
                          pcVar62 = pcVar62 + iVar31;
                          lVar37 = lVar37 + lVar35;
                          uVar44 = uVar44 - 1;
                          lVar53 = -lVar68;
                        } while (uVar44 != 0);
                      }
                    }
                    uVar43 = uVar43 + 1;
                    param_5 = param_5 + 1;
                    uVar44 = (ulonglong)param_5;
                    bVar40 = bVar40 * '\x02';
                  } while ((longlong)uVar43 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar52 = lVar52 + lVar35;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
        }
        else {
          if (param_6 != 5) {
            return 0xffffffff;
          }
          if (iVar67 == 1) {
            if (uVar28 != 0) {
              uVar32 = (ulonglong)uVar28;
              do {
                if (uVar61 != 0) {
                  lVar68 = 0;
                  do {
                    if (((undefined1 *)(lVar52 + lVar68))[(longlong)param_7 - lVar52] != '\0') {
                      *(undefined1 *)(lVar52 + lVar68) = 1;
                      if (*(char *)(lVar52 + -1 + lVar68) != '\x01') {
                        *(undefined1 *)(lVar52 + -1 + lVar68) = 2;
                      }
                      if (*(char *)(lVar52 + 1 + lVar68) != '\x01') {
                        *(undefined1 *)(lVar52 + 1 + lVar68) = 2;
                      }
                      if (*(char *)((lVar52 - lVar35) + lVar68) != '\x01') {
                        *(undefined1 *)((lVar52 - lVar35) + lVar68) = 2;
                      }
                      if (*(char *)(lVar35 + lVar52 + lVar68) != '\x01') {
                        *(undefined1 *)(lVar35 + lVar52 + lVar68) = 2;
                      }
                    }
                    lVar68 = lVar68 + 1;
                  } while (lVar68 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar52 = lVar52 + lVar35;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
          else {
            uVar32 = (ulonglong)uVar28;
            if (iVar67 < 5) {
              if (uVar28 != 0) {
                do {
                  lVar53 = 0;
                  if (uVar61 != 0) {
                    do {
                      if (((undefined1 *)(lVar52 + lVar53))[(longlong)param_7 - lVar52] != '\0') {
                        *(undefined1 *)(lVar52 + lVar53) = 1;
                        iVar31 = iVar67 + 1;
                        if (-iVar67 < iVar31) {
                          pcVar63 = pcVar62 + lVar68;
                          lVar36 = -iVar67 * iVar56 + lVar52 + lVar53;
                          uVar43 = (ulonglong)(uint)(iVar31 + iVar67);
                          lVar37 = -lVar68;
                          do {
                            for (; lVar37 < iVar31; lVar37 = lVar37 + 1) {
                              if ((pcVar63[lVar37] != '\0') &&
                                 (*(char *)(lVar36 + lVar37) != '\x01')) {
                                *(undefined1 *)(lVar36 + lVar37) = 2;
                              }
                            }
                            pcVar63 = pcVar63 + 9;
                            lVar36 = lVar36 + lVar35;
                            uVar43 = uVar43 - 1;
                            lVar37 = -lVar68;
                          } while (uVar43 != 0);
                        }
                      }
                      lVar53 = lVar53 + 1;
                    } while (lVar53 < (longlong)uVar61);
                  }
                  param_7 = param_7 + uVar49;
                  lVar52 = lVar52 + lVar35;
                  uVar32 = uVar32 - 1;
                } while (uVar32 != 0);
              }
            }
            else if (uVar28 != 0) {
              do {
                lVar53 = 0;
                if (uVar61 != 0) {
                  do {
                    if (((undefined1 *)(lVar52 + lVar53))[(longlong)param_7 - lVar52] != '\0') {
                      *(undefined1 *)(lVar52 + lVar53) = 1;
                      iVar59 = iVar67 + 1;
                      if (-iVar67 < iVar59) {
                        lVar36 = -iVar67 * iVar56 + lVar52 + lVar53;
                        pcVar62 = pcVar63 + lVar68;
                        uVar43 = (ulonglong)(uint)(iVar59 + iVar67);
                        lVar37 = -lVar68;
                        do {
                          for (; lVar37 < iVar59; lVar37 = lVar37 + 1) {
                            if ((pcVar62[lVar37] != '\0') && (*(char *)(lVar36 + lVar37) != '\x01'))
                            {
                              *(undefined1 *)(lVar36 + lVar37) = 2;
                            }
                          }
                          pcVar62 = pcVar62 + iVar31;
                          lVar36 = lVar36 + lVar35;
                          uVar43 = uVar43 - 1;
                          lVar37 = -lVar68;
                        } while (uVar43 != 0);
                      }
                    }
                    lVar53 = lVar53 + 1;
                  } while (lVar53 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar52 = lVar52 + lVar35;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
        }
      }
      else if (((uVar29 == 3) || (uVar29 == 0x13)) || (uVar29 == 0x23)) {
        if (param_6 != 6) {
          return 0xffffffff;
        }
        pbVar64 = (byte *)((longlong)((local_90 + local_bc) * iVar56) +
                           *(longlong *)(param_1 + 0x11dbe8) + (longlong)local_a8 +
                          (longlong)local_bc);
        if (iVar67 == 1) {
          if (uVar28 != 0) {
            uVar32 = (ulonglong)uVar28;
            do {
              if (uVar61 != 0) {
                lVar68 = 0;
                do {
                  pbVar69 = pbVar64 + lVar68;
                  if (pbVar69[(longlong)param_7 - (longlong)pbVar64] != 0) {
                    iVar67 = pbVar69[(longlong)param_7 - (longlong)pbVar64] - 1;
                    *pbVar69 = *pbVar69 | (byte)iVar67;
                    iVar67 = iVar67 * 0x10;
                    bVar40 = (byte)iVar67;
                    if ((int)(pbVar64[lVar68 - lVar35] & 0xf0) < iVar67) {
                      pbVar64[lVar68 - lVar35] = pbVar64[lVar68 - lVar35] & 0xf | bVar40;
                    }
                    if ((int)(pbVar64[lVar68 + lVar35] & 0xf0) < iVar67) {
                      pbVar64[lVar68 + lVar35] = pbVar64[lVar68 + lVar35] & 0xf | bVar40;
                    }
                    if ((int)(pbVar64[lVar68 + 1] & 0xf0) < iVar67) {
                      pbVar64[lVar68 + 1] = pbVar64[lVar68 + 1] & 0xf | bVar40;
                    }
                    if ((int)(pbVar64[lVar68 + -1] & 0xf0) < iVar67) {
                      pbVar64[lVar68 + -1] = pbVar64[lVar68 + -1] & 0xf | bVar40;
                    }
                  }
                  lVar68 = lVar68 + 1;
                } while (lVar68 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              pbVar64 = pbVar64 + lVar35;
              uVar32 = uVar32 - 1;
            } while (uVar32 != 0);
          }
        }
        else {
          uVar32 = (ulonglong)uVar28;
          if (iVar67 < 5) {
            if (uVar28 != 0) {
              lVar52 = -(longlong)pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar69 = pbVar64;
                  do {
                    if (pbVar69[(longlong)param_7 - (longlong)pbVar64] != 0) {
                      iVar31 = iVar67 + 1;
                      iVar59 = pbVar69[(longlong)param_7 - (longlong)pbVar64] - 1;
                      *pbVar69 = *pbVar69 | (byte)iVar59;
                      iVar59 = iVar59 * 0x10;
                      if (-iVar67 < iVar31) {
                        pcVar63 = pcVar62 + lVar68;
                        pbVar65 = pbVar69 + -iVar67 * iVar56 + lVar52 + (longlong)pbVar64;
                        uVar43 = (ulonglong)(uint)(iVar31 + iVar67);
                        lVar53 = -lVar68;
                        do {
                          for (; lVar53 < iVar31; lVar53 = lVar53 + 1) {
                            if ((pcVar63[lVar53] != '\0') &&
                               ((int)(pbVar65[lVar53] & 0xf0) < iVar59)) {
                              pbVar65[lVar53] = pbVar65[lVar53] & 0xf | (byte)iVar59;
                            }
                          }
                          pcVar63 = pcVar63 + 9;
                          pbVar65 = pbVar65 + lVar35;
                          uVar43 = uVar43 - 1;
                          lVar53 = -lVar68;
                        } while (uVar43 != 0);
                      }
                    }
                    pbVar69 = pbVar69 + 1;
                  } while ((longlong)(pbVar69 + lVar52) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar52 = lVar52 - lVar35;
                pbVar64 = pbVar64 + lVar35;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
          else if (uVar28 != 0) {
            lVar52 = -(longlong)pbVar64;
            do {
              if (uVar61 != 0) {
                pbVar69 = pbVar64;
                do {
                  if (pbVar69[(longlong)param_7 - (longlong)pbVar64] != 0) {
                    iVar59 = iVar67 + 1;
                    iVar57 = pbVar69[(longlong)param_7 - (longlong)pbVar64] - 1;
                    *pbVar69 = *pbVar69 | (byte)iVar57;
                    iVar57 = iVar57 * 0x10;
                    if (-iVar67 < iVar59) {
                      pbVar65 = pbVar69 + -iVar67 * iVar56 + lVar52 + (longlong)pbVar64;
                      pcVar62 = pcVar63 + lVar68;
                      uVar43 = (ulonglong)(uint)(iVar59 + iVar67);
                      lVar53 = -lVar68;
                      do {
                        for (; lVar53 < iVar59; lVar53 = lVar53 + 1) {
                          if ((pcVar62[lVar53] != '\0') && ((int)(pbVar65[lVar53] & 0xf0) < iVar57))
                          {
                            pbVar65[lVar53] = pbVar65[lVar53] & 0xf | (byte)iVar57;
                          }
                        }
                        pcVar62 = pcVar62 + iVar31;
                        pbVar65 = pbVar65 + lVar35;
                        uVar43 = uVar43 - 1;
                        lVar53 = -lVar68;
                      } while (uVar43 != 0);
                    }
                  }
                  pbVar69 = pbVar69 + 1;
                } while ((longlong)(pbVar69 + lVar52) < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              lVar52 = lVar52 - lVar35;
              pbVar64 = pbVar64 + lVar35;
              uVar32 = uVar32 - 1;
            } while (uVar32 != 0);
          }
        }
      }
    }
    else {
      iVar56 = *(int *)(param_1 + 0x1220d8);
      lVar68 = (longlong)iVar56;
      bVar40 = 0;
      pbVar64 = (byte *)((longlong)
                         (int)((uint)*(byte *)(param_1 + 0x121cac) * (local_bc + local_a8)) +
                         (longlong)((local_bc + local_90) * iVar56) +
                        *(longlong *)(param_1 + 0x1220e0));
      uVar29 = *(int *)(param_1 + 0x1220d0) / 2;
      uVar32 = (ulonglong)uVar29;
      uVar41 = *(uint *)(param_1 + 0x121cc0) | *(uint *)(param_1 + 0x121cbc) |
               *(uint *)(param_1 + 0x121cb8);
      uVar47 = *(uint *)(param_1 + 0x121cc4) | uVar41;
      uVar46 = (ushort)uVar47;
      uVar25 = (ushort)uVar41;
      if (param_6 == 0) {
        uVar43 = (ulonglong)uVar28;
        if (iVar67 == 1) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                uVar44 = 0;
                uVar45 = 0;
                if (uVar61 != 0) {
                  do {
                    iVar67 = (int)uVar44;
                    if ((uVar44 & 7) == 0) {
                      bVar40 = param_7[(longlong)iVar67 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      pbVar69[uVar45] = 1;
                      uVar47 = uVar29 + iVar67;
                      pbVar69[(ulonglong)uVar47 - lVar68] = 1;
                      pbVar69[(ulonglong)uVar47 + lVar68] = 1;
                      pbVar69[uVar45 + (uVar32 - 1)] = 1;
                      pbVar69[uVar45 + uVar32 + 1] = 1;
                      pbVar69[(ulonglong)(uVar47 - 1) - lVar68] = 1;
                      uVar41 = uVar29 + 1 + iVar67;
                      pbVar69[(ulonglong)uVar41 - lVar68] = 1;
                      pbVar69[(ulonglong)(uVar47 - 1) + lVar68] = 1;
                      pbVar69[(ulonglong)uVar41 + lVar68] = 1;
                    }
                    uVar45 = uVar45 + 1;
                    bVar40 = bVar40 * '\x02';
                    uVar44 = (ulonglong)(iVar67 + 1);
                  } while ((longlong)uVar45 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                uVar44 = 0;
                if (uVar61 != 0) {
                  uVar41 = uVar29 * 2;
                  uVar45 = uVar44;
                  do {
                    iVar67 = (int)uVar44;
                    if ((uVar44 & 7) == 0) {
                      bVar40 = param_7[(longlong)iVar67 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      (pbVar69 + uVar45 * 2)[0] = 1;
                      (pbVar69 + uVar45 * 2)[1] = 0;
                      (pbVar69 + ((ulonglong)uVar41 - lVar68))[0] = 1;
                      (pbVar69 + ((ulonglong)uVar41 - lVar68))[1] = 0;
                      (pbVar69 + (ulonglong)uVar41 + lVar68)[0] = 1;
                      (pbVar69 + (ulonglong)uVar41 + lVar68)[1] = 0;
                      (pbVar69 + (uVar45 + uVar32) * 2 + -2)[0] = 1;
                      (pbVar69 + (uVar45 + uVar32) * 2 + -2)[1] = 0;
                      (pbVar69 + (uVar45 + uVar32) * 2 + 2)[0] = 1;
                      (pbVar69 + (uVar45 + uVar32) * 2 + 2)[1] = 0;
                      uVar44 = (ulonglong)((uVar29 + iVar67) * 2 - 2);
                      (pbVar69 + (uVar44 - lVar68))[0] = 1;
                      (pbVar69 + (uVar44 - lVar68))[1] = 0;
                      (pbVar69 + ((ulonglong)(uVar41 + 2) - lVar68))[0] = 1;
                      (pbVar69 + ((ulonglong)(uVar41 + 2) - lVar68))[1] = 0;
                      (pbVar69 + uVar44 + lVar68)[0] = 1;
                      (pbVar69 + uVar44 + lVar68)[1] = 0;
                      (pbVar69 + (ulonglong)(uVar41 + 2) + lVar68)[0] = 1;
                      (pbVar69 + (ulonglong)(uVar41 + 2) + lVar68)[1] = 0;
                    }
                    uVar44 = (ulonglong)(iVar67 + 1);
                    uVar41 = uVar41 + 2;
                    uVar45 = uVar45 + 1;
                    bVar40 = bVar40 * '\x02';
                  } while ((longlong)uVar45 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (iVar67 < 5) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                iVar31 = 0;
                local_120 = (byte *)0x0;
                if (uVar61 != 0) {
                  do {
                    uVar47 = iVar31 >> 0x1f & 7;
                    uVar41 = iVar31 + uVar47;
                    if ((uVar41 & 7) == uVar47) {
                      bVar40 = param_7[(int)uVar41 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      pbVar69[(longlong)local_120] = 1;
                      iVar59 = -iVar67;
                      iVar57 = iVar67 + 1;
                      if (iVar59 < iVar57) {
                        lVar35 = (longlong)(iVar59 * iVar56);
                        uVar44 = (ulonglong)(uint)(iVar57 + iVar67);
                        iVar66 = iVar59;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                            if ((*pcVar63 != '\0') &&
                               (uVar41 = uVar29 + iVar66 + iVar31,
                               pbVar69[lVar35 + (ulonglong)uVar41] == 0)) {
                              pbVar69[lVar35 + (ulonglong)uVar41] = 1;
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar44 = uVar44 - 1;
                          iVar66 = iVar59;
                          pcVar51 = pcVar63;
                        } while (uVar44 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    iVar31 = iVar31 + 1;
                    bVar40 = bVar40 * '\x02';
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                iVar31 = 0;
                local_120 = (byte *)0x0;
                if (uVar61 != 0) {
                  do {
                    uVar47 = iVar31 >> 0x1f & 7;
                    uVar41 = iVar31 + uVar47;
                    if ((uVar41 & 7) == uVar47) {
                      bVar40 = param_7[(int)uVar41 >> 3];
                    }
                    if ((char)bVar40 < '\0') {
                      iVar57 = iVar67 + 1;
                      iVar59 = -iVar67;
                      (pbVar69 + (longlong)local_120 * 2)[0] = 1;
                      (pbVar69 + (longlong)local_120 * 2)[1] = 0;
                      if (iVar59 < iVar57) {
                        lVar35 = (longlong)(iVar59 * iVar56);
                        uVar44 = (ulonglong)(uint)(iVar57 + iVar67);
                        iVar66 = iVar59;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                            if ((*pcVar63 != '\0') &&
                               (lVar52 = (ulonglong)((uVar29 + iVar66 + iVar31) * 2) + lVar35,
                               *(short *)(pbVar69 + lVar52) == 0)) {
                              (pbVar69 + lVar52)[0] = 1;
                              (pbVar69 + lVar52)[1] = 0;
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar44 = uVar44 - 1;
                          iVar66 = iVar59;
                          pcVar51 = pcVar63;
                        } while (uVar44 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    iVar31 = iVar31 + 1;
                    bVar40 = bVar40 * '\x02';
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (*(char *)(param_1 + 0x121cad) == '\b') {
          pbVar69 = pbVar64;
          if (uVar28 != 0) {
            do {
              iVar59 = 0;
              local_110 = (byte *)0x0;
              if (uVar61 != 0) {
                do {
                  uVar47 = iVar59 >> 0x1f & 7;
                  uVar41 = iVar59 + uVar47;
                  if ((uVar41 & 7) == uVar47) {
                    bVar40 = param_7[(int)uVar41 >> 3];
                  }
                  if ((char)bVar40 < '\0') {
                    pbVar69[(longlong)local_110] = 1;
                    iVar66 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar66 < iVar57) {
                      lVar35 = (longlong)(iVar66 * iVar56);
                      uVar44 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar13 = iVar66;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar13 < iVar57; iVar13 = iVar13 + 1) {
                          if ((*pcVar62 != '\0') &&
                             (uVar41 = uVar29 + iVar13 + iVar59,
                             pbVar69[lVar35 + (ulonglong)uVar41] == 0)) {
                            pbVar69[lVar35 + (ulonglong)uVar41] = 1;
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar35 = lVar35 + lVar68;
                        uVar44 = uVar44 - 1;
                        iVar13 = iVar66;
                        pcVar51 = pcVar62;
                      } while (uVar44 != 0);
                    }
                  }
                  local_110 = (byte *)((longlong)local_110 + 1);
                  iVar59 = iVar59 + 1;
                  bVar40 = bVar40 * '\x02';
                } while ((longlong)local_110 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              uVar43 = uVar43 - 1;
              pbVar69 = pbVar69 + lVar68;
            } while (uVar43 != 0);
          }
        }
        else {
          pbVar69 = pbVar64;
          if (uVar28 != 0) {
            do {
              iVar59 = 0;
              local_110 = (byte *)0x0;
              if (uVar61 != 0) {
                do {
                  uVar47 = iVar59 >> 0x1f & 7;
                  uVar41 = iVar59 + uVar47;
                  if ((uVar41 & 7) == uVar47) {
                    bVar40 = param_7[(int)uVar41 >> 3];
                  }
                  if ((char)bVar40 < '\0') {
                    iVar57 = iVar67 + 1;
                    iVar66 = -iVar67;
                    (pbVar69 + (longlong)local_110 * 2)[0] = 1;
                    (pbVar69 + (longlong)local_110 * 2)[1] = 0;
                    if (iVar66 < iVar57) {
                      lVar35 = (longlong)(iVar66 * iVar56);
                      uVar44 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar13 = iVar66;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar13 < iVar57; iVar13 = iVar13 + 1) {
                          if ((*pcVar62 != '\0') &&
                             (iVar30 = uVar29 + iVar13 + iVar59,
                             *(short *)(pbVar69 + lVar35 + (ulonglong)(uint)(iVar30 * 2)) == 0)) {
                            (pbVar69 + lVar35 + (ulonglong)(uint)(iVar30 * 2))[0] = 1;
                            (pbVar69 + lVar35 + (ulonglong)(uint)(iVar30 * 2))[1] = 0;
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar35 = lVar35 + lVar68;
                        uVar44 = uVar44 - 1;
                        iVar13 = iVar66;
                        pcVar51 = pcVar62;
                      } while (uVar44 != 0);
                    }
                  }
                  local_110 = (byte *)((longlong)local_110 + 1);
                  iVar59 = iVar59 + 1;
                  bVar40 = bVar40 * '\x02';
                } while ((longlong)local_110 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              uVar43 = uVar43 - 1;
              pbVar69 = pbVar69 + lVar68;
            } while (uVar43 != 0);
          }
        }
        uVar29 = (uint)uVar27;
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          uVar28 = uVar28 + local_f0;
          uVar49 = (ulonglong)uVar28;
          pbVar64 = pbVar64 + (-(longlong)local_bc - (longlong)(iVar56 * local_bc));
          if (*(int *)(param_1 + 0x121ccc) == 0xf) {
            if (0 < (int)uVar28) {
              do {
                if (0 < (longlong)(int)(uVar29 + local_f0)) {
                  pbVar69 = pbVar64 + uVar32 * 2;
                  pbVar65 = pbVar64;
                  lVar35 = (longlong)(int)(uVar29 + local_f0);
                  do {
                    if (*pbVar65 == 0) {
                      *pbVar65 = 0;
                      pbVar65[uVar32] = -(*(short *)pbVar69 != 0) & 0xf;
                    }
                    else {
                      *pbVar65 = 0xf;
                      pbVar65[uVar32] = 0;
                    }
                    pbVar69 = pbVar69 + 2;
                    pbVar65 = pbVar65 + 1;
                    lVar35 = lVar35 + -1;
                  } while (lVar35 != 0);
                }
                pbVar64 = pbVar64 + lVar68;
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            do {
              if (0 < (longlong)(int)(uVar29 + local_f0)) {
                pbVar69 = pbVar64 + uVar32 * 2;
                pbVar65 = pbVar64;
                lVar35 = (longlong)(int)(uVar29 + local_f0);
                do {
                  if (*pbVar65 == 0) {
                    *pbVar65 = 0;
                    pbVar65[uVar32] = -(*(short *)pbVar69 != 0);
                  }
                  else {
                    *pbVar65 = 0xff;
                    pbVar65[uVar32] = 0;
                  }
                  pbVar69 = pbVar69 + 2;
                  pbVar65 = pbVar65 + 1;
                  lVar35 = lVar35 + -1;
                } while (lVar35 != 0);
              }
              pbVar64 = pbVar64 + lVar68;
              uVar49 = uVar49 - 1;
            } while (uVar49 != 0);
          }
        }
        else {
          puVar70 = (ushort *)
                    (pbVar64 + (-(longlong)(local_bc * 2) - (longlong)(iVar56 * local_bc)));
          uVar28 = uVar28 + local_f0;
          if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (0 < (int)uVar28) {
              uVar49 = (ulonglong)uVar28;
              do {
                puVar38 = puVar70;
                lVar35 = (longlong)(int)(uVar29 + local_f0);
                if (0 < (longlong)(int)(uVar29 + local_f0)) {
                  do {
                    if (*puVar38 == 0) {
                      *puVar38 = uVar25;
                      uVar27 = uVar25;
                      if (puVar38[uVar32] != 0) {
                        uVar27 = uVar46;
                      }
                      puVar38[uVar32] = uVar27;
                    }
                    else {
                      *puVar38 = uVar46;
                      puVar38[uVar32] = uVar25;
                    }
                    lVar35 = lVar35 + -1;
                    puVar38 = puVar38 + 1;
                  } while (lVar35 != 0);
                }
                puVar70 = (ushort *)((longlong)puVar70 + lVar68);
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar49 = (ulonglong)uVar28;
            do {
              puVar38 = puVar70;
              lVar35 = (longlong)(int)(uVar29 + local_f0);
              if (0 < (longlong)(int)(uVar29 + local_f0)) {
                do {
                  if (*puVar38 == 0) {
                    *puVar38 = 0;
                    uVar27 = 0;
                    if (puVar38[uVar32] != 0) {
                      uVar27 = uVar46;
                    }
                    puVar38[uVar32] = uVar27;
                  }
                  else {
                    *puVar38 = uVar46;
                    puVar38[uVar32] = 0;
                  }
                  lVar35 = lVar35 + -1;
                  puVar38 = puVar38 + 1;
                } while (lVar35 != 0);
              }
              puVar70 = (ushort *)((longlong)puVar70 + lVar68);
              uVar49 = uVar49 - 1;
            } while (uVar49 != 0);
          }
        }
      }
      else if (param_6 == 5) {
        if (iVar67 == 1) {
          uVar43 = (ulonglong)uVar28;
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar44 = uVar32;
                  do {
                    iVar67 = (int)uVar44;
                    if ((pbVar69 + lVar35)[(longlong)param_7 - (longlong)pbVar69] != 0) {
                      pbVar69[lVar35] = 1;
                      pbVar69[uVar44 - lVar68] = 1;
                      pbVar69[uVar44 + lVar68] = 1;
                      pbVar69[lVar35 + (uVar32 - 1)] = 1;
                      pbVar69[lVar35 + uVar32 + 1] = 1;
                      pbVar69[(ulonglong)(iVar67 - 1) - lVar68] = 1;
                      pbVar69[(ulonglong)(iVar67 + 1) - lVar68] = 1;
                      pbVar69[(ulonglong)(iVar67 - 1) + lVar68] = 1;
                      pbVar69[(ulonglong)(iVar67 + 1) + lVar68] = 1;
                    }
                    uVar44 = (ulonglong)(iVar67 + 1);
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                if (uVar61 != 0) {
                  uVar41 = uVar29 * 2;
                  lVar35 = 0;
                  uVar47 = uVar29;
                  do {
                    if (param_7[lVar35] != 0) {
                      (pbVar69 + lVar35 * 2)[0] = 1;
                      (pbVar69 + lVar35 * 2)[1] = 0;
                      uVar44 = (ulonglong)(uVar47 * 2 - 2);
                      (pbVar69 + ((ulonglong)uVar41 - lVar68))[0] = 1;
                      (pbVar69 + ((ulonglong)uVar41 - lVar68))[1] = 0;
                      (pbVar69 + (ulonglong)uVar41 + lVar68)[0] = 1;
                      (pbVar69 + (ulonglong)uVar41 + lVar68)[1] = 0;
                      (pbVar69 + (lVar35 + uVar32) * 2 + -2)[0] = 1;
                      (pbVar69 + (lVar35 + uVar32) * 2 + -2)[1] = 0;
                      (pbVar69 + (lVar35 + uVar32) * 2 + 2)[0] = 1;
                      (pbVar69 + (lVar35 + uVar32) * 2 + 2)[1] = 0;
                      (pbVar69 + (uVar44 - lVar68))[0] = 1;
                      (pbVar69 + (uVar44 - lVar68))[1] = 0;
                      (pbVar69 + ((ulonglong)(uVar41 + 2) - lVar68))[0] = 1;
                      (pbVar69 + ((ulonglong)(uVar41 + 2) - lVar68))[1] = 0;
                      (pbVar69 + uVar44 + lVar68)[0] = 1;
                      (pbVar69 + uVar44 + lVar68)[1] = 0;
                      (pbVar69 + (ulonglong)(uVar41 + 2) + lVar68)[0] = 1;
                      (pbVar69 + (ulonglong)(uVar41 + 2) + lVar68)[1] = 0;
                    }
                    uVar41 = uVar41 + 2;
                    uVar47 = uVar47 + 1;
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (iVar67 < 5) {
          uVar32 = (ulonglong)uVar28;
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (uVar28 != 0) {
              lVar35 = -(longlong)pbVar64;
              pbVar69 = pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar65 = pbVar69;
                  uVar41 = uVar29;
                  do {
                    if (pbVar65[(longlong)param_7 - (longlong)pbVar69] != 0) {
                      *pbVar65 = 1;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar52 = (longlong)(iVar31 * iVar56);
                        uVar43 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if ((*pcVar63 != '\0') &&
                               (lVar53 = (ulonglong)(uVar41 + iVar57) + lVar52, pbVar69[lVar53] == 0
                               )) {
                              pbVar69[lVar53] = 1;
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar52 = lVar52 + lVar68;
                          uVar43 = uVar43 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar43 != 0);
                      }
                    }
                    pbVar65 = pbVar65 + 1;
                    uVar41 = uVar41 + 1;
                  } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar35 = lVar35 - lVar68;
                pbVar69 = pbVar69 + lVar68;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                local_120 = (byte *)0x0;
                uVar41 = uVar29;
                if (uVar61 != 0) {
                  do {
                    if (param_7[(longlong)local_120] != 0) {
                      (pbVar69 + (longlong)local_120 * 2)[0] = 1;
                      (pbVar69 + (longlong)local_120 * 2)[1] = 0;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar35 = (longlong)(iVar31 * iVar56);
                        uVar43 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if ((*pcVar63 != '\0') &&
                               (*(short *)(pbVar69 + lVar35 + (ulonglong)((iVar57 + uVar41) * 2)) ==
                                0)) {
                              (pbVar69 + lVar35 + (ulonglong)((iVar57 + uVar41) * 2))[0] = 1;
                              (pbVar69 + lVar35 + (ulonglong)((iVar57 + uVar41) * 2))[1] = 0;
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar43 = uVar43 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar43 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    uVar41 = uVar41 + 1;
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar32 = uVar32 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar32 != 0);
            }
          }
        }
        else {
          uVar32 = (ulonglong)uVar28;
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (uVar28 != 0) {
              lVar35 = -(longlong)pbVar64;
              pbVar69 = pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar65 = pbVar69;
                  uVar41 = uVar29;
                  do {
                    if (pbVar65[(longlong)param_7 - (longlong)pbVar69] != 0) {
                      *pbVar65 = 1;
                      iVar59 = -iVar67;
                      iVar57 = iVar67 + 1;
                      if (iVar59 < iVar57) {
                        lVar52 = (longlong)(iVar59 * iVar56);
                        uVar43 = (ulonglong)(uint)(iVar57 + iVar67);
                        iVar66 = iVar59;
                        pcVar62 = pcVar63;
                        pcVar51 = pcVar63;
                        do {
                          for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                            if ((*pcVar62 != '\0') &&
                               (pbVar69[lVar52 + (ulonglong)(iVar66 + uVar41)] == 0)) {
                              pbVar69[lVar52 + (ulonglong)(iVar66 + uVar41)] = 1;
                            }
                            pcVar62 = pcVar62 + 1;
                          }
                          pcVar62 = pcVar51 + iVar31;
                          lVar52 = lVar52 + lVar68;
                          uVar43 = uVar43 - 1;
                          iVar66 = iVar59;
                          pcVar51 = pcVar62;
                        } while (uVar43 != 0);
                      }
                    }
                    pbVar65 = pbVar65 + 1;
                    uVar41 = uVar41 + 1;
                  } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar35 = lVar35 - lVar68;
                pbVar69 = pbVar69 + lVar68;
                uVar32 = uVar32 - 1;
              } while (uVar32 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                local_110 = (byte *)0x0;
                uVar41 = uVar29;
                if (uVar61 != 0) {
                  do {
                    if (param_7[(longlong)local_110] != 0) {
                      (pbVar69 + (longlong)local_110 * 2)[0] = 1;
                      (pbVar69 + (longlong)local_110 * 2)[1] = 0;
                      iVar59 = -iVar67;
                      iVar57 = iVar67 + 1;
                      if (iVar59 < iVar57) {
                        lVar35 = (longlong)(iVar59 * iVar56);
                        uVar43 = (ulonglong)(uint)(iVar57 + iVar67);
                        iVar66 = iVar59;
                        pcVar62 = pcVar63;
                        pcVar51 = pcVar63;
                        do {
                          for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                            if ((*pcVar62 != '\0') &&
                               (*(short *)(pbVar69 + lVar35 + (ulonglong)((uVar41 + iVar66) * 2)) ==
                                0)) {
                              (pbVar69 + lVar35 + (ulonglong)((uVar41 + iVar66) * 2))[0] = 1;
                              (pbVar69 + lVar35 + (ulonglong)((uVar41 + iVar66) * 2))[1] = 0;
                            }
                            pcVar62 = pcVar62 + 1;
                          }
                          pcVar62 = pcVar51 + iVar31;
                          lVar35 = lVar35 + lVar68;
                          uVar43 = uVar43 - 1;
                          iVar66 = iVar59;
                          pcVar51 = pcVar62;
                        } while (uVar43 != 0);
                      }
                    }
                    local_110 = (byte *)((longlong)local_110 + 1);
                    uVar41 = uVar41 + 1;
                  } while ((longlong)local_110 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar32 = uVar32 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar32 != 0);
            }
          }
        }
        uVar49 = (ulonglong)uVar29;
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          uVar28 = uVar28 + local_f0;
          uVar61 = (ulonglong)uVar28;
          pbVar64 = pbVar64 + (-(longlong)local_bc - (longlong)(iVar56 * local_bc));
          if (*(int *)(param_1 + 0x121ccc) == 0xf) {
            if (0 < (int)uVar28) {
              do {
                if (0 < (longlong)(int)((uint)uVar27 + local_f0)) {
                  pbVar69 = pbVar64 + uVar49;
                  lVar52 = -uVar49;
                  lVar35 = (longlong)(int)((uint)uVar27 + local_f0);
                  do {
                    if (pbVar69[lVar52] == 0) {
                      pbVar69[lVar52] = 0;
                      *pbVar69 = -(*pbVar69 != 0) & 0xf;
                    }
                    else {
                      pbVar69[lVar52] = 0xf;
                      *pbVar69 = 0;
                    }
                    pbVar69 = pbVar69 + 1;
                    lVar35 = lVar35 + -1;
                  } while (lVar35 != 0);
                }
                pbVar64 = pbVar64 + lVar68;
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            do {
              if (0 < (longlong)(int)((uint)uVar27 + local_f0)) {
                pbVar69 = pbVar64 + uVar49;
                lVar52 = -uVar49;
                lVar35 = (longlong)(int)((uint)uVar27 + local_f0);
                do {
                  if (pbVar69[lVar52] == 0) {
                    pbVar69[lVar52] = 0;
                    *pbVar69 = -(*pbVar69 != 0);
                  }
                  else {
                    pbVar69[lVar52] = 0xff;
                    *pbVar69 = 0;
                  }
                  pbVar69 = pbVar69 + 1;
                  lVar35 = lVar35 + -1;
                } while (lVar35 != 0);
              }
              pbVar64 = pbVar64 + lVar68;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else {
          puVar70 = (ushort *)
                    (pbVar64 + (-(longlong)(local_bc * 2) - (longlong)(iVar56 * local_bc)));
          uVar28 = uVar28 + local_f0;
          if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (0 < (int)uVar28) {
              uVar61 = (ulonglong)uVar28;
              do {
                puVar38 = puVar70;
                lVar35 = (longlong)(int)((uint)uVar27 + local_f0);
                if (0 < (longlong)(int)((uint)uVar27 + local_f0)) {
                  do {
                    if (*puVar38 == 0) {
                      *puVar38 = uVar25;
                      uVar26 = uVar25;
                      if (puVar38[uVar49] != 0) {
                        uVar26 = uVar46;
                      }
                      puVar38[uVar49] = uVar26;
                    }
                    else {
                      *puVar38 = uVar46;
                      puVar38[uVar49] = uVar25;
                    }
                    lVar35 = lVar35 + -1;
                    puVar38 = puVar38 + 1;
                  } while (lVar35 != 0);
                }
                puVar70 = (ushort *)((longlong)puVar70 + lVar68);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar61 = (ulonglong)uVar28;
            do {
              puVar38 = puVar70;
              lVar35 = (longlong)(int)((uint)uVar27 + local_f0);
              if (0 < (longlong)(int)((uint)uVar27 + local_f0)) {
                do {
                  if (*puVar38 == 0) {
                    *puVar38 = 0;
                    uVar25 = 0;
                    if (puVar38[uVar49] != 0) {
                      uVar25 = uVar46;
                    }
                    puVar38[uVar49] = uVar25;
                  }
                  else {
                    *puVar38 = uVar46;
                    puVar38[uVar49] = 0;
                  }
                  lVar35 = lVar35 + -1;
                  puVar38 = puVar38 + 1;
                } while (lVar35 != 0);
              }
              puVar70 = (ushort *)((longlong)puVar70 + lVar68);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      else if (param_6 == 6) {
        uVar43 = (ulonglong)uVar28;
        if (iVar67 == 1) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar41 = uVar29 * 2;
                  uVar47 = uVar29;
                  do {
                    bVar40 = (pbVar69 + lVar35)[(longlong)param_7 - (longlong)pbVar69];
                    if (bVar40 != 0) {
                      pbVar69[lVar35] = bVar40;
                      uVar55 = (uint)bVar40;
                      pbVar69[(ulonglong)uVar47 - lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + ((ulonglong)uVar41 - lVar68)))
                                  * uVar55 >> 4) + pbVar69[(ulonglong)uVar41 - lVar68];
                      lVar52 = uVar32 + lVar35;
                      pbVar69[(ulonglong)uVar47 + lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + (ulonglong)uVar41 + lVar68)) *
                                  uVar55 >> 4) + pbVar69[(ulonglong)uVar41 + lVar68];
                      pbVar69[lVar35 + (uVar32 - 1)] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + lVar52 * 2 + -2)) * uVar55 >>
                                 4) + pbVar69[lVar52 * 2 + -2];
                      pbVar69[lVar35 + uVar32 + 1] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + lVar52 * 2 + 2)) * uVar55 >> 4
                                 ) + pbVar69[lVar52 * 2 + 2];
                      uVar44 = (ulonglong)(uVar41 + 2);
                      uVar50 = uVar47 - 1;
                      uVar54 = uVar50 * 2;
                      pbVar69[(ulonglong)uVar50 - lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + ((ulonglong)uVar54 - lVar68)))
                                  * uVar55 >> 4) + pbVar69[(ulonglong)uVar54 - lVar68];
                      pbVar69[(ulonglong)(uVar47 + 1) - lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + (uVar44 - lVar68))) * uVar55
                                 >> 4) + pbVar69[uVar44 - lVar68];
                      pbVar69[(ulonglong)uVar50 + lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + (ulonglong)uVar54 + lVar68)) *
                                  uVar55 >> 4) + pbVar69[(ulonglong)uVar54 + lVar68];
                      pbVar69[(ulonglong)(uVar47 + 1) + lVar68] =
                           (char)((0x10 - (uint)*(ushort *)(pbVar69 + uVar44 + lVar68)) * uVar55 >>
                                 4) + pbVar69[uVar44 + lVar68];
                    }
                    uVar41 = uVar41 + 2;
                    uVar47 = uVar47 + 1;
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar41 = uVar29 * 2;
                  uVar44 = uVar32;
                  do {
                    bVar40 = param_7[lVar35];
                    if (bVar40 != 0) {
                      *(ushort *)(pbVar69 + lVar35 * 2) = (ushort)bVar40;
                      uVar45 = (ulonglong)(uVar41 + 2);
                      uVar50 = (uint)bVar40;
                      *(ushort *)(pbVar69 + ((ulonglong)uVar41 - lVar68)) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + ((ulonglong)uVar41 - lVar68))
                                   ) * uVar50 >> 4) +
                           *(ushort *)(pbVar69 + ((ulonglong)uVar41 - lVar68));
                      *(ushort *)(pbVar69 + (ulonglong)uVar41 + lVar68) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + (ulonglong)uVar41 + lVar68))
                                   * uVar50 >> 4) +
                           *(ushort *)(pbVar69 + (ulonglong)uVar41 + lVar68);
                      lVar52 = lVar35 + uVar32;
                      *(ushort *)(pbVar69 + lVar52 * 2 + -2) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + lVar52 * 2 + -2)) * uVar50 >>
                                  4) + *(ushort *)(pbVar69 + lVar52 * 2 + -2);
                      *(ushort *)(pbVar69 + lVar52 * 2 + 2) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + lVar52 * 2 + 2)) * uVar50 >>
                                  4) + *(ushort *)(pbVar69 + lVar52 * 2 + 2);
                      uVar47 = (int)uVar44 * 2 - 2;
                      *(ushort *)(pbVar69 + ((ulonglong)uVar47 - lVar68)) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + ((ulonglong)uVar47 - lVar68))
                                   ) * uVar50 >> 4) +
                           *(ushort *)(pbVar69 + ((ulonglong)uVar47 - lVar68));
                      uVar46 = *(ushort *)(pbVar69 + (uVar45 - lVar68));
                      *(ushort *)(pbVar69 + (uVar45 - lVar68)) =
                           (short)((0x10 - (uint)uVar46) * uVar50 >> 4) + uVar46;
                      *(ushort *)(pbVar69 + (ulonglong)uVar47 + lVar68) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + (ulonglong)uVar47 + lVar68))
                                   * uVar50 >> 4) +
                           *(ushort *)(pbVar69 + (ulonglong)uVar47 + lVar68);
                      *(ushort *)(pbVar69 + uVar45 + lVar68) =
                           (short)((0x10 - (uint)*(ushort *)(pbVar69 + uVar45 + lVar68)) * uVar50 >>
                                  4) + *(ushort *)(pbVar69 + uVar45 + lVar68);
                    }
                    uVar41 = uVar41 + 2;
                    uVar44 = (ulonglong)((int)uVar44 + 1);
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (iVar67 < 5) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (uVar28 != 0) {
              lVar35 = -(longlong)pbVar64;
              pbVar69 = pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar65 = pbVar69;
                  uVar41 = uVar29;
                  do {
                    bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                    if (bVar40 != 0) {
                      *pbVar65 = bVar40;
                      iVar59 = -iVar67;
                      iVar31 = iVar67 + 1;
                      if (iVar59 < iVar31) {
                        lVar52 = (longlong)(iVar59 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar31 + iVar67);
                        iVar57 = iVar59;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar31; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              lVar53 = (ulonglong)(uVar41 + iVar57) + lVar52;
                              pbVar69[lVar53] =
                                   (byte)((pbVar69[lVar53] - 0x10) * (0x10 - (uint)bVar40) + 0x100
                                         >> 4);
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar52 = lVar52 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar59;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    pbVar65 = pbVar65 + 1;
                    uVar41 = uVar41 + 1;
                  } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar35 = lVar35 - lVar68;
                pbVar69 = pbVar69 + lVar68;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                local_120 = (byte *)0x0;
                uVar41 = uVar29;
                if (uVar61 != 0) {
                  do {
                    bVar40 = param_7[(longlong)local_120];
                    if (bVar40 != 0) {
                      *(ushort *)(pbVar69 + (longlong)local_120 * 2) = (ushort)bVar40;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar35 = (longlong)(iVar31 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              *(ushort *)(pbVar69 + lVar35 + (ulonglong)((iVar57 + uVar41) * 2)) =
                                   (ushort)((*(ushort *)
                                              (pbVar69 + lVar35 + (ulonglong)((iVar57 + uVar41) * 2)
                                              ) - 0x10) * (0x10 - (uint)bVar40) + 0x100 >> 4);
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    uVar41 = uVar41 + 1;
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (*(char *)(param_1 + 0x121cad) == '\b') {
          if (uVar28 != 0) {
            lVar35 = -(longlong)pbVar64;
            pbVar69 = pbVar64;
            do {
              if (uVar61 != 0) {
                pbVar65 = pbVar69;
                uVar41 = uVar29;
                do {
                  bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                  if (bVar40 != 0) {
                    *pbVar65 = bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar52 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            pbVar69[lVar52 + (ulonglong)(iVar66 + uVar41)] =
                                 (byte)((pbVar69[lVar52 + (ulonglong)(iVar66 + uVar41)] - 0x10) *
                                        (0x10 - (uint)bVar40) + 0x100 >> 4);
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar52 = lVar52 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  pbVar65 = pbVar65 + 1;
                  uVar41 = uVar41 + 1;
                } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              lVar35 = lVar35 - lVar68;
              pbVar69 = pbVar69 + lVar68;
              uVar43 = uVar43 - 1;
            } while (uVar43 != 0);
          }
        }
        else {
          pbVar69 = pbVar64;
          if (uVar28 != 0) {
            do {
              local_110 = (byte *)0x0;
              uVar41 = uVar29;
              if (uVar61 != 0) {
                do {
                  bVar40 = param_7[(longlong)local_110];
                  if (bVar40 != 0) {
                    *(ushort *)(pbVar69 + (longlong)local_110 * 2) = (ushort)bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar35 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            *(short *)(pbVar69 + lVar35 + (ulonglong)((uVar41 + iVar66) * 2)) =
                                 (short)((*(ushort *)
                                           (pbVar69 + lVar35 + (ulonglong)((uVar41 + iVar66) * 2)) -
                                         0x10) * (0x10 - (uint)bVar40) + 0x100 >> 4);
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar35 = lVar35 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  local_110 = (byte *)((longlong)local_110 + 1);
                  uVar41 = uVar41 + 1;
                } while ((longlong)local_110 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              uVar43 = uVar43 - 1;
              pbVar69 = pbVar69 + lVar68;
            } while (uVar43 != 0);
          }
        }
        uVar41 = (uint)uVar27;
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          uVar28 = uVar28 + local_f0;
          pbVar64 = pbVar64 + (-(longlong)local_bc - (longlong)(iVar56 * local_bc));
          if (*(int *)(param_1 + 0x121ccc) == 0xf) {
            if (0 < (int)uVar28) {
              uVar49 = (ulonglong)uVar28;
              do {
                pbVar69 = pbVar64;
                lVar35 = (longlong)(int)(uVar41 + local_f0);
                if (0 < (longlong)(int)(uVar41 + local_f0)) {
                  do {
                    bVar40 = *pbVar69;
                    if (bVar40 == 0x10) {
                      *pbVar69 = 0xf;
LAB_140161fcb:
                      pbVar69[uVar29] = 0;
                    }
                    else {
                      if (bVar40 == 0) {
                        *pbVar69 = 0;
                      }
                      else {
                        *pbVar69 = bVar40 - 1;
                      }
                      if (pbVar69[uVar29] == 0) goto LAB_140161fcb;
                      pbVar69[uVar29] = pbVar69[uVar29] - 1;
                    }
                    lVar35 = lVar35 + -1;
                    pbVar69 = pbVar69 + 1;
                  } while (lVar35 != 0);
                }
                pbVar64 = pbVar64 + lVar68;
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar49 = (ulonglong)uVar28;
            do {
              pbVar69 = pbVar64;
              lVar35 = (longlong)(int)(uVar41 + local_f0);
              if (0 < (longlong)(int)(uVar41 + local_f0)) {
                do {
                  bVar40 = *pbVar69;
                  if (bVar40 == 0x10) {
                    *pbVar69 = 0xff;
LAB_14016202d:
                    pbVar69[uVar29] = 0;
                  }
                  else {
                    if (bVar40 == 0) {
                      *pbVar69 = 0;
                    }
                    else {
                      *pbVar69 = bVar40 * '\x10' - 1;
                    }
                    if (pbVar69[uVar29] == 0) goto LAB_14016202d;
                    pbVar69[uVar29] = pbVar69[uVar29] * '\x10' - 1;
                  }
                  lVar35 = lVar35 + -1;
                  pbVar69 = pbVar69 + 1;
                } while (lVar35 != 0);
              }
              pbVar64 = pbVar64 + lVar68;
              uVar49 = uVar49 - 1;
            } while (uVar49 != 0);
          }
        }
        else {
          bVar40 = *(char *)(param_1 + 0x121cb7) + -4 + *(char *)(param_1 + 0x121cb3);
          puVar70 = (ushort *)
                    (pbVar64 + (-(longlong)(local_bc * 2) - (longlong)(iVar56 * local_bc)));
          if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (0 < (int)(uVar28 + local_f0)) {
              uVar49 = (ulonglong)(uVar28 + local_f0);
              do {
                if (0 < (int)(uVar41 + local_f0)) {
                  uVar61 = (ulonglong)(uVar41 + local_f0);
                  puVar38 = puVar70;
                  do {
                    uVar27 = *puVar38;
                    if (uVar27 == 0x10) {
                      *puVar38 = (0x10 << (bVar40 & 0x1f)) - 1U | uVar25;
LAB_140162237:
                      puVar38[uVar29] = uVar25;
                    }
                    else {
                      if (uVar27 == 0) {
                        *puVar38 = uVar25;
                      }
                      else {
                        *puVar38 = (uVar27 << (bVar40 & 0x1f)) - 1 | uVar25;
                      }
                      if (puVar38[uVar29] == 0) goto LAB_140162237;
                      puVar38[uVar29] = (puVar38[uVar29] << (bVar40 & 0x1f)) - 1 | uVar25;
                    }
                    puVar38 = puVar38 + 1;
                    uVar61 = uVar61 - 1;
                  } while (uVar61 != 0);
                }
                puVar70 = (ushort *)((longlong)puVar70 + lVar68);
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
            }
          }
          else if (0 < (int)(uVar28 + local_f0)) {
            uVar49 = (ulonglong)(uVar28 + local_f0);
            bVar58 = *(char *)(param_1 + 0x121cb6) + -4 + *(char *)(param_1 + 0x121cb2);
            bVar22 = *(char *)(param_1 + 0x121cb5) + -4 + *(char *)(param_1 + 0x121cb1);
            bVar23 = *(char *)(param_1 + 0x121cb4) + -4 + *(char *)(param_1 + 0x121cb0);
            do {
              uVar61 = (ulonglong)uVar29;
              if (0 < (int)(uVar41 + local_f0)) {
                puVar38 = puVar70 + uVar61;
                uVar32 = (ulonglong)(uVar41 + local_f0);
                do {
                  uVar27 = puVar38[-uVar61];
                  if (uVar27 == 0x10) {
                    puVar38[-uVar61] = 0xffff;
                    *puVar38 = 0;
                  }
                  else {
                    if (uVar27 != 0) {
                      puVar38[-uVar61] =
                           uVar27 << (bVar40 & 0x1f) | uVar27 << (bVar58 & 0x1f) |
                           uVar27 << (bVar22 & 0x1f) | uVar27 << (bVar23 & 0x1f);
                    }
                    uVar27 = *puVar38;
                    if (uVar27 == 0x10) {
                      *puVar38 = 0xffff;
                    }
                    else if (uVar27 != 0) {
                      *puVar38 = uVar27 << (bVar40 & 0x1f) | uVar27 << (bVar58 & 0x1f) |
                                 uVar27 << (bVar22 & 0x1f) | uVar27 << (bVar23 & 0x1f);
                    }
                  }
                  puVar38 = puVar38 + 1;
                  uVar32 = uVar32 - 1;
                } while (uVar32 != 0);
              }
              puVar70 = (ushort *)((longlong)puVar70 + lVar68);
              uVar49 = uVar49 - 1;
            } while (uVar49 != 0);
          }
        }
      }
      else if (param_6 == 7) {
        uVar43 = (ulonglong)uVar28;
        if (iVar67 == 1) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar44 = uVar32;
                  do {
                    bVar40 = (pbVar69 + lVar35)[(longlong)param_7 - (longlong)pbVar69];
                    iVar67 = (int)uVar44;
                    if (bVar40 != 0) {
                      pbVar69[lVar35] = bVar40;
                      uVar55 = (uint)bVar40;
                      pbVar69[uVar44 - lVar68] =
                           (char)((0x40 - (uint)pbVar69[uVar44 - lVar68]) * uVar55 >> 6) +
                           pbVar69[uVar44 - lVar68];
                      lVar52 = lVar35 + uVar32;
                      pbVar69[uVar44 + lVar68] =
                           (char)((0x40 - (uint)pbVar69[uVar44 + lVar68]) * uVar55 >> 6) +
                           pbVar69[uVar44 + lVar68];
                      pbVar69[lVar52 + -1] =
                           (char)((0x40 - (uint)pbVar69[lVar52 + -1]) * uVar55 >> 6) +
                           pbVar69[lVar52 + -1];
                      pbVar69[lVar52 + 1] =
                           (char)((0x40 - (uint)pbVar69[lVar52 + 1]) * uVar55 >> 6) +
                           pbVar69[lVar52 + 1];
                      uVar50 = iVar67 - 1;
                      pbVar69[(ulonglong)uVar50 - lVar68] =
                           (char)((0x40 - (uint)pbVar69[(ulonglong)uVar50 - lVar68]) * uVar55 >> 6)
                           + pbVar69[(ulonglong)uVar50 - lVar68];
                      uVar54 = iVar67 + 1;
                      pbVar69[(ulonglong)uVar54 - lVar68] =
                           (char)((0x40 - (uint)pbVar69[(ulonglong)uVar54 - lVar68]) * uVar55 >> 6)
                           + pbVar69[(ulonglong)uVar54 - lVar68];
                      bVar40 = pbVar69[(ulonglong)uVar54 + lVar68];
                      pbVar69[(ulonglong)uVar50 + lVar68] =
                           (char)((0x40 - (uint)pbVar69[(ulonglong)uVar50 + lVar68]) * uVar55 >> 6)
                           + pbVar69[(ulonglong)uVar50 + lVar68];
                      pbVar69[(ulonglong)uVar54 + lVar68] =
                           (char)((0x40 - (uint)bVar40) * uVar55 >> 6) + bVar40;
                    }
                    uVar44 = (ulonglong)(iVar67 + 1);
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar54 = uVar29 * 4;
                  uVar50 = uVar29;
                  do {
                    uVar44 = (ulonglong)uVar54;
                    bVar40 = param_7[lVar35];
                    if (bVar40 != 0) {
                      uVar48 = (uint)bVar40;
                      *(uint *)(pbVar69 + lVar35 * 4) = uVar48;
                      lVar52 = lVar35 + uVar32;
                      *(uint *)(pbVar69 + (uVar44 - lVar68)) =
                           *(int *)(pbVar69 + (uVar44 - lVar68)) +
                           ((0x40 - *(int *)(pbVar69 + (uVar44 - lVar68))) * uVar48 >> 6);
                      uVar55 = uVar50 * 4 - 4;
                      *(uint *)(pbVar69 + uVar44 + lVar68) =
                           *(int *)(pbVar69 + uVar44 + lVar68) +
                           ((0x40 - *(int *)(pbVar69 + uVar44 + lVar68)) * uVar48 >> 6);
                      *(uint *)(pbVar69 + lVar52 * 4 + -4) =
                           *(int *)(pbVar69 + lVar52 * 4 + -4) +
                           ((0x40 - *(int *)(pbVar69 + lVar52 * 4 + -4)) * uVar48 >> 6);
                      uVar48 = (uint)bVar40;
                      *(uint *)(pbVar69 + lVar52 * 4 + 4) =
                           *(int *)(pbVar69 + lVar52 * 4 + 4) +
                           ((0x40 - *(int *)(pbVar69 + lVar52 * 4 + 4)) * uVar48 >> 6);
                      uVar44 = (ulonglong)(uVar54 + 4);
                      *(uint *)(pbVar69 + ((ulonglong)uVar55 - lVar68)) =
                           *(int *)(pbVar69 + ((ulonglong)uVar55 - lVar68)) +
                           ((0x40 - *(int *)(pbVar69 + ((ulonglong)uVar55 - lVar68))) * uVar48 >> 6)
                      ;
                      *(uint *)(pbVar69 + (uVar44 - lVar68)) =
                           *(int *)(pbVar69 + (uVar44 - lVar68)) +
                           ((0x40 - *(int *)(pbVar69 + (uVar44 - lVar68))) * uVar48 >> 6);
                      *(uint *)(pbVar69 + (ulonglong)uVar55 + lVar68) =
                           *(int *)(pbVar69 + (ulonglong)uVar55 + lVar68) +
                           ((0x40 - *(int *)(pbVar69 + (ulonglong)uVar55 + lVar68)) * uVar48 >> 6);
                      *(uint *)(pbVar69 + uVar44 + lVar68) =
                           *(int *)(pbVar69 + uVar44 + lVar68) +
                           ((0x40 - *(int *)(pbVar69 + uVar44 + lVar68)) * uVar48 >> 6);
                    }
                    uVar54 = uVar54 + 4;
                    uVar50 = uVar50 + 1;
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (iVar67 < 5) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (uVar28 != 0) {
              lVar35 = -(longlong)pbVar64;
              pbVar69 = pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar65 = pbVar69;
                  uVar50 = uVar29;
                  do {
                    bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                    if (bVar40 != 0) {
                      *pbVar65 = bVar40;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar52 = (longlong)(iVar31 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              pbVar69[lVar52 + (ulonglong)(iVar57 + uVar50)] =
                                   (char)((0x40 - (uint)pbVar69[lVar52 + (ulonglong)
                                                                         (iVar57 + uVar50)]) *
                                          (uint)bVar40 >> 6) +
                                   pbVar69[lVar52 + (ulonglong)(iVar57 + uVar50)];
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar52 = lVar52 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    pbVar65 = pbVar65 + 1;
                    uVar50 = uVar50 + 1;
                  } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar35 = lVar35 - lVar68;
                pbVar69 = pbVar69 + lVar68;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                local_120 = (byte *)0x0;
                uVar50 = uVar29;
                if (uVar61 != 0) {
                  do {
                    bVar40 = param_7[(longlong)local_120];
                    if (bVar40 != 0) {
                      *(uint *)(pbVar69 + (longlong)local_120 * 4) = (uint)bVar40;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar35 = (longlong)(iVar31 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              *(uint *)(pbVar69 + lVar35 + (ulonglong)((uVar50 + iVar57) * 4)) =
                                   *(int *)(pbVar69 + lVar35 + (ulonglong)((uVar50 + iVar57) * 4)) +
                                   ((0x40 - *(int *)(pbVar69 +
                                                    lVar35 + (ulonglong)((uVar50 + iVar57) * 4))) *
                                    (uint)bVar40 >> 6);
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    uVar50 = uVar50 + 1;
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (*(char *)(param_1 + 0x121cad) == '\b') {
          if (uVar28 != 0) {
            lVar35 = -(longlong)pbVar64;
            pbVar69 = pbVar64;
            do {
              if (uVar61 != 0) {
                pbVar65 = pbVar69;
                uVar50 = uVar29;
                do {
                  bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                  if (bVar40 != 0) {
                    *pbVar65 = bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar52 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            pbVar69[lVar52 + (ulonglong)(uVar50 + iVar66)] =
                                 (char)((0x40 - (uint)pbVar69[lVar52 + (ulonglong)(uVar50 + iVar66)]
                                        ) * (uint)bVar40 >> 6) +
                                 pbVar69[lVar52 + (ulonglong)(uVar50 + iVar66)];
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar52 = lVar52 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  pbVar65 = pbVar65 + 1;
                  uVar50 = uVar50 + 1;
                } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              lVar35 = lVar35 - lVar68;
              pbVar69 = pbVar69 + lVar68;
              uVar43 = uVar43 - 1;
            } while (uVar43 != 0);
          }
        }
        else {
          pbVar69 = pbVar64;
          if (uVar28 != 0) {
            do {
              local_110 = (byte *)0x0;
              uVar50 = uVar29;
              if (uVar61 != 0) {
                do {
                  bVar40 = param_7[(longlong)local_110];
                  if (bVar40 != 0) {
                    *(uint *)(pbVar69 + (longlong)local_110 * 4) = (uint)bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar35 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            lVar52 = (ulonglong)((iVar66 + uVar50) * 4) + lVar35;
                            *(uint *)(pbVar69 + lVar52) =
                                 *(int *)(pbVar69 + lVar52) +
                                 ((0x40 - *(int *)(pbVar69 + lVar52)) * (uint)bVar40 >> 6);
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar35 = lVar35 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  local_110 = (byte *)((longlong)local_110 + 1);
                  uVar50 = uVar50 + 1;
                } while ((longlong)local_110 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              uVar43 = uVar43 - 1;
              pbVar69 = pbVar69 + lVar68;
            } while (uVar43 != 0);
          }
        }
        uVar50 = (uint)uVar27;
        uVar49 = (ulonglong)uVar29;
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          uVar28 = uVar28 + local_f0;
          pbVar64 = pbVar64 + (-(longlong)local_bc - (longlong)(iVar56 * local_bc));
          if (*(int *)(param_1 + 0x121ccc) == 0xf) {
            if (0 < (int)uVar28) {
              uVar61 = (ulonglong)uVar28;
              do {
                pbVar69 = pbVar64;
                lVar35 = (longlong)(int)(uVar50 + local_f0);
                if (0 < (longlong)(int)(uVar50 + local_f0)) {
                  do {
                    bVar40 = *pbVar69;
                    if (bVar40 == 0x40) {
                      *pbVar69 = 0xf;
LAB_14016133b:
                      pbVar69[uVar49] = 0;
                    }
                    else {
                      if (bVar40 == 0) {
                        *pbVar69 = 0;
                      }
                      else {
                        *pbVar69 = bVar40 >> 2;
                      }
                      if (pbVar69[uVar49] == 0) goto LAB_14016133b;
                      pbVar69[uVar49] = pbVar69[uVar49] >> 2;
                    }
                    lVar35 = lVar35 + -1;
                    pbVar69 = pbVar69 + 1;
                  } while (lVar35 != 0);
                }
                pbVar64 = pbVar64 + lVar68;
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar61 = (ulonglong)uVar28;
            do {
              if (0 < (longlong)(int)(uVar50 + local_f0)) {
                pbVar69 = pbVar64 + uVar49;
                lVar35 = (longlong)(int)(uVar50 + local_f0);
                do {
                  pbVar69[-uVar49] = (&DAT_14056cb40)[pbVar69[-uVar49]];
                  *pbVar69 = (&DAT_14056cb40)[*pbVar69];
                  lVar35 = lVar35 + -1;
                  pbVar69 = pbVar69 + 1;
                } while (lVar35 != 0);
              }
              pbVar64 = pbVar64 + lVar68;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else {
          uVar28 = uVar28 + local_f0;
          puVar60 = (uint *)(pbVar64 + (-(longlong)(local_bc * 4) - (longlong)(iVar56 * local_bc)));
          if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (0 < (int)uVar28) {
              uVar49 = (ulonglong)uVar28;
              do {
                if (0 < (int)(uVar50 + local_f0)) {
                  uVar61 = (ulonglong)(uVar50 + local_f0);
                  puVar34 = puVar60;
                  do {
                    uVar28 = *puVar34;
                    if (uVar28 == 0x40) {
                      *puVar34 = uVar47;
LAB_14016156b:
                      puVar34[uVar29] = uVar41;
                    }
                    else {
                      if (uVar28 == 0) {
                        *puVar34 = uVar41;
                      }
                      else {
                        *puVar34 = (uint)(byte)(&DAT_14056cb40)[uVar28] <<
                                   (*(byte *)(param_1 + 0x121cb7) & 0x1f) | uVar41;
                      }
                      if (puVar34[uVar29] == 0) goto LAB_14016156b;
                      puVar34[uVar29] =
                           (uint)(byte)(&DAT_14056cb40)[puVar34[uVar29]] <<
                           (*(byte *)(param_1 + 0x121cb7) & 0x1f) | uVar41;
                    }
                    puVar34 = puVar34 + 1;
                    uVar61 = uVar61 - 1;
                  } while (uVar61 != 0);
                }
                puVar60 = (uint *)((longlong)puVar60 + lVar68);
                uVar49 = uVar49 - 1;
              } while (uVar49 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar49 = (ulonglong)uVar28;
            do {
              uVar61 = (ulonglong)uVar29;
              if (0 < (int)(uVar50 + local_f0)) {
                uVar32 = (ulonglong)(uVar50 + local_f0);
                puVar34 = puVar60 + uVar61;
                do {
                  uVar28 = puVar34[-uVar61];
                  if (uVar28 == 0x40) {
                    puVar34[-uVar61] = 0xffffffff;
                    *puVar34 = 0;
                  }
                  else {
                    if (uVar28 != 0) {
                      uVar41 = (uint)(byte)(&DAT_14056cb40)[uVar28];
                      puVar34[-uVar61] =
                           uVar41 << (*(byte *)(param_1 + 0x121cb7) & 0x1f) |
                           (uint)(byte)(&DAT_14056cb40)[uVar28] <<
                           (*(byte *)(param_1 + 0x121cb6) & 0x1f) |
                           uVar41 << (*(byte *)(param_1 + 0x121cb5) & 0x1f) |
                           uVar41 << (*(byte *)(param_1 + 0x121cb4) & 0x1f);
                    }
                    uVar28 = *puVar34;
                    if (uVar28 == 0x40) {
                      *puVar34 = 0xffffffff;
                    }
                    else if (uVar28 != 0) {
                      uVar41 = (uint)(byte)(&DAT_14056cb40)[uVar28];
                      *puVar34 = uVar41 << (*(byte *)(param_1 + 0x121cb7) & 0x1f) |
                                 (uint)(byte)(&DAT_14056cb40)[uVar28] <<
                                 (*(byte *)(param_1 + 0x121cb6) & 0x1f) |
                                 uVar41 << (*(byte *)(param_1 + 0x121cb5) & 0x1f) |
                                 uVar41 << (*(byte *)(param_1 + 0x121cb4) & 0x1f);
                    }
                  }
                  puVar34 = puVar34 + 1;
                  uVar32 = uVar32 - 1;
                } while (uVar32 != 0);
              }
              puVar60 = (uint *)((longlong)puVar60 + lVar68);
              uVar49 = uVar49 - 1;
            } while (uVar49 != 0);
          }
        }
      }
      else if (param_6 == 8) {
        uVar43 = (ulonglong)uVar28;
        if (iVar67 == 1) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar44 = uVar32;
                  do {
                    bVar40 = (pbVar69 + lVar35)[(longlong)param_7 - (longlong)pbVar69];
                    iVar67 = (int)uVar44;
                    if (bVar40 != 0) {
                      pbVar69[lVar35] = bVar40;
                      uVar54 = (uint)bVar40;
                      pbVar69[uVar44 - lVar68] =
                           (char)((0xff - (uint)pbVar69[uVar44 - lVar68]) * uVar54 >> 8) +
                           pbVar69[uVar44 - lVar68];
                      lVar52 = lVar35 + uVar32;
                      pbVar69[uVar44 + lVar68] =
                           (char)((0xff - (uint)pbVar69[uVar44 + lVar68]) * uVar54 >> 8) +
                           pbVar69[uVar44 + lVar68];
                      pbVar69[lVar52 + -1] =
                           (char)((0xff - (uint)pbVar69[lVar52 + -1]) * uVar54 >> 8) +
                           pbVar69[lVar52 + -1];
                      pbVar69[lVar52 + 1] =
                           (char)((0xff - (uint)pbVar69[lVar52 + 1]) * uVar54 >> 8) +
                           pbVar69[lVar52 + 1];
                      uVar47 = iVar67 - 1;
                      pbVar69[(ulonglong)uVar47 - lVar68] =
                           (char)((0xff - (uint)pbVar69[(ulonglong)uVar47 - lVar68]) * uVar54 >> 8)
                           + pbVar69[(ulonglong)uVar47 - lVar68];
                      uVar50 = iVar67 + 1;
                      pbVar69[(ulonglong)uVar50 - lVar68] =
                           (char)((0xff - (uint)pbVar69[(ulonglong)uVar50 - lVar68]) * uVar54 >> 8)
                           + pbVar69[(ulonglong)uVar50 - lVar68];
                      bVar40 = pbVar69[(ulonglong)uVar50 + lVar68];
                      pbVar69[(ulonglong)uVar47 + lVar68] =
                           (char)((0xff - (uint)pbVar69[(ulonglong)uVar47 + lVar68]) * uVar54 >> 8)
                           + pbVar69[(ulonglong)uVar47 + lVar68];
                      pbVar69[(ulonglong)uVar50 + lVar68] =
                           (char)((0xff - (uint)bVar40) * uVar54 >> 8) + bVar40;
                    }
                    uVar44 = (ulonglong)(iVar67 + 1);
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                lVar35 = 0;
                if (uVar61 != 0) {
                  uVar50 = uVar29 * 4;
                  uVar47 = uVar29;
                  do {
                    bVar40 = param_7[lVar35];
                    if (bVar40 != 0) {
                      uVar55 = (uint)bVar40;
                      *(uint *)(pbVar69 + lVar35 * 4) = uVar55;
                      lVar52 = lVar35 + uVar32;
                      *(uint *)(pbVar69 + ((ulonglong)uVar50 - lVar68)) =
                           *(int *)(pbVar69 + ((ulonglong)uVar50 - lVar68)) +
                           ((0xff - *(int *)(pbVar69 + ((ulonglong)uVar50 - lVar68))) * uVar55 >> 8)
                      ;
                      uVar54 = uVar47 * 4 - 4;
                      *(uint *)(pbVar69 + (ulonglong)uVar50 + lVar68) =
                           *(int *)(pbVar69 + (ulonglong)uVar50 + lVar68) +
                           ((0xff - *(int *)(pbVar69 + (ulonglong)uVar50 + lVar68)) * uVar55 >> 8);
                      *(uint *)(pbVar69 + lVar52 * 4 + -4) =
                           *(int *)(pbVar69 + lVar52 * 4 + -4) +
                           ((0xff - *(int *)(pbVar69 + lVar52 * 4 + -4)) * uVar55 >> 8);
                      uVar55 = (uint)bVar40;
                      *(uint *)(pbVar69 + lVar52 * 4 + 4) =
                           *(int *)(pbVar69 + lVar52 * 4 + 4) +
                           ((0xff - *(int *)(pbVar69 + lVar52 * 4 + 4)) * uVar55 >> 8);
                      *(uint *)(pbVar69 + ((ulonglong)uVar54 - lVar68)) =
                           *(int *)(pbVar69 + ((ulonglong)uVar54 - lVar68)) +
                           ((0xff - *(int *)(pbVar69 + ((ulonglong)uVar54 - lVar68))) * uVar55 >> 8)
                      ;
                      uVar44 = (ulonglong)(uVar50 + 4);
                      *(uint *)(pbVar69 + (uVar44 - lVar68)) =
                           *(int *)(pbVar69 + (uVar44 - lVar68)) +
                           ((0xff - *(int *)(pbVar69 + (uVar44 - lVar68))) * uVar55 >> 8);
                      *(uint *)(pbVar69 + (ulonglong)uVar54 + lVar68) =
                           *(int *)(pbVar69 + (ulonglong)uVar54 + lVar68) +
                           ((0xff - *(int *)(pbVar69 + (ulonglong)uVar54 + lVar68)) * uVar55 >> 8);
                      *(uint *)(pbVar69 + uVar44 + lVar68) =
                           *(int *)(pbVar69 + uVar44 + lVar68) +
                           ((0xff - *(int *)(pbVar69 + uVar44 + lVar68)) * uVar55 >> 8);
                    }
                    uVar50 = uVar50 + 4;
                    uVar47 = uVar47 + 1;
                    lVar35 = lVar35 + 1;
                  } while (lVar35 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (iVar67 < 5) {
          if (*(char *)(param_1 + 0x121cad) == '\b') {
            if (uVar28 != 0) {
              lVar35 = -(longlong)pbVar64;
              pbVar69 = pbVar64;
              do {
                if (uVar61 != 0) {
                  pbVar65 = pbVar69;
                  uVar47 = uVar29;
                  do {
                    bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                    if (bVar40 != 0) {
                      *pbVar65 = bVar40;
                      iVar59 = -iVar67;
                      iVar31 = iVar67 + 1;
                      if (iVar59 < iVar31) {
                        lVar52 = (longlong)(iVar59 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar31 + iVar67);
                        iVar57 = iVar59;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar31; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              lVar53 = (ulonglong)(uVar47 + iVar57) + lVar52;
                              pbVar69[lVar53] =
                                   (char)((0xff - (uint)pbVar69[lVar53]) * (uint)bVar40 >> 8) +
                                   pbVar69[lVar53];
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar52 = lVar52 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar59;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    pbVar65 = pbVar65 + 1;
                    uVar47 = uVar47 + 1;
                  } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                lVar35 = lVar35 - lVar68;
                pbVar69 = pbVar69 + lVar68;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
          }
          else {
            pbVar69 = pbVar64;
            if (uVar28 != 0) {
              do {
                local_120 = (byte *)0x0;
                uVar47 = uVar29;
                if (uVar61 != 0) {
                  do {
                    bVar40 = param_7[(longlong)local_120];
                    if (bVar40 != 0) {
                      *(uint *)(pbVar69 + (longlong)local_120 * 4) = (uint)bVar40;
                      iVar31 = -iVar67;
                      iVar59 = iVar67 + 1;
                      if (iVar31 < iVar59) {
                        lVar35 = (longlong)(iVar31 * iVar56);
                        uVar32 = (ulonglong)(uint)(iVar59 + iVar67);
                        iVar57 = iVar31;
                        pcVar63 = pcVar62;
                        pcVar51 = pcVar62;
                        do {
                          for (; iVar57 < iVar59; iVar57 = iVar57 + 1) {
                            if (*pcVar63 != '\0') {
                              lVar52 = (ulonglong)((uVar47 + iVar57) * 4) + lVar35;
                              *(uint *)(pbVar69 + lVar52) =
                                   *(int *)(pbVar69 + lVar52) +
                                   ((0xff - *(int *)(pbVar69 + lVar52)) * (uint)bVar40 >> 8);
                            }
                            pcVar63 = pcVar63 + 1;
                          }
                          pcVar63 = pcVar51 + 9;
                          lVar35 = lVar35 + lVar68;
                          uVar32 = uVar32 - 1;
                          iVar57 = iVar31;
                          pcVar51 = pcVar63;
                        } while (uVar32 != 0);
                      }
                    }
                    local_120 = (byte *)((longlong)local_120 + 1);
                    uVar47 = uVar47 + 1;
                  } while ((longlong)local_120 < (longlong)uVar61);
                }
                param_7 = param_7 + uVar49;
                uVar43 = uVar43 - 1;
                pbVar69 = pbVar69 + lVar68;
              } while (uVar43 != 0);
            }
          }
        }
        else if (*(char *)(param_1 + 0x121cad) == '\b') {
          if (uVar28 != 0) {
            lVar35 = -(longlong)pbVar64;
            pbVar69 = pbVar64;
            do {
              if (uVar61 != 0) {
                pbVar65 = pbVar69;
                uVar47 = uVar29;
                do {
                  bVar40 = pbVar65[(longlong)param_7 - (longlong)pbVar69];
                  if (bVar40 != 0) {
                    *pbVar65 = bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar52 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            pbVar69[lVar52 + (ulonglong)(iVar66 + uVar47)] =
                                 (char)((0xff - (uint)pbVar69[lVar52 + (ulonglong)(iVar66 + uVar47)]
                                        ) * (uint)bVar40 >> 8) +
                                 pbVar69[lVar52 + (ulonglong)(iVar66 + uVar47)];
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar52 = lVar52 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  pbVar65 = pbVar65 + 1;
                  uVar47 = uVar47 + 1;
                } while ((longlong)(pbVar65 + lVar35) < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              lVar35 = lVar35 - lVar68;
              pbVar69 = pbVar69 + lVar68;
              uVar43 = uVar43 - 1;
            } while (uVar43 != 0);
          }
        }
        else {
          pbVar69 = pbVar64;
          if (uVar28 != 0) {
            do {
              local_110 = (byte *)0x0;
              uVar47 = uVar29;
              if (uVar61 != 0) {
                do {
                  bVar40 = param_7[(longlong)local_110];
                  if (bVar40 != 0) {
                    *(uint *)(pbVar69 + (longlong)local_110 * 4) = (uint)bVar40;
                    iVar59 = -iVar67;
                    iVar57 = iVar67 + 1;
                    if (iVar59 < iVar57) {
                      lVar35 = (longlong)(iVar59 * iVar56);
                      uVar32 = (ulonglong)(uint)(iVar57 + iVar67);
                      iVar66 = iVar59;
                      pcVar62 = pcVar63;
                      pcVar51 = pcVar63;
                      do {
                        for (; iVar66 < iVar57; iVar66 = iVar66 + 1) {
                          if (*pcVar62 != '\0') {
                            *(uint *)(pbVar69 + lVar35 + (ulonglong)((iVar66 + uVar47) * 4)) =
                                 *(int *)(pbVar69 + lVar35 + (ulonglong)((iVar66 + uVar47) * 4)) +
                                 ((0xff - *(int *)(pbVar69 +
                                                  lVar35 + (ulonglong)((iVar66 + uVar47) * 4))) *
                                  (uint)bVar40 >> 8);
                          }
                          pcVar62 = pcVar62 + 1;
                        }
                        pcVar62 = pcVar51 + iVar31;
                        lVar35 = lVar35 + lVar68;
                        uVar32 = uVar32 - 1;
                        iVar66 = iVar59;
                        pcVar51 = pcVar62;
                      } while (uVar32 != 0);
                    }
                  }
                  local_110 = (byte *)((longlong)local_110 + 1);
                  uVar47 = uVar47 + 1;
                } while ((longlong)local_110 < (longlong)uVar61);
              }
              param_7 = param_7 + uVar49;
              uVar43 = uVar43 - 1;
              pbVar69 = pbVar69 + lVar68;
            } while (uVar43 != 0);
          }
        }
        uVar47 = (uint)uVar27;
        uVar49 = (ulonglong)uVar29;
        if (*(char *)(param_1 + 0x121cad) == '\b') {
          pbVar64 = pbVar64 + (-(longlong)(local_bc * 4) - (longlong)(iVar56 * local_bc));
          if ((*(int *)(param_1 + 0x121ccc) == 0xf) && (0 < (int)(uVar28 + local_f0))) {
            uVar61 = (ulonglong)(uVar28 + local_f0);
            do {
              if (0 < (longlong)(int)(uVar47 + local_f0)) {
                pbVar69 = pbVar64 + uVar49;
                lVar35 = (longlong)(int)(uVar47 + local_f0);
                do {
                  pbVar69[-uVar49] = pbVar69[-uVar49] >> 4;
                  *pbVar69 = *pbVar69 >> 4;
                  pbVar69 = pbVar69 + 1;
                  lVar35 = lVar35 + -1;
                } while (lVar35 != 0);
              }
              pbVar64 = pbVar64 + lVar68;
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
        else {
          puVar60 = (uint *)(pbVar64 + (-(longlong)(local_bc * 4) - (longlong)(iVar56 * local_bc)));
          uVar28 = uVar28 + local_f0;
          if (*(int *)(param_1 + 0x1220f4) == 0) {
            if (0 < (int)uVar28) {
              uVar61 = (ulonglong)uVar28;
              do {
                puVar34 = puVar60;
                lVar35 = (longlong)(int)(uVar47 + local_f0);
                if (0 < (longlong)(int)(uVar47 + local_f0)) {
                  do {
                    *puVar34 = *puVar34 << (*(byte *)(param_1 + 0x121cb7) & 0x1f) | uVar41;
                    puVar34[uVar49] =
                         puVar34[uVar49] << (*(byte *)(param_1 + 0x121cb7) & 0x1f) | uVar41;
                    lVar35 = lVar35 + -1;
                    puVar34 = puVar34 + 1;
                  } while (lVar35 != 0);
                }
                puVar60 = (uint *)((longlong)puVar60 + lVar68);
                uVar61 = uVar61 - 1;
              } while (uVar61 != 0);
            }
          }
          else if (0 < (int)uVar28) {
            uVar61 = (ulonglong)uVar28;
            do {
              puVar34 = puVar60;
              lVar35 = (longlong)(int)(uVar47 + local_f0);
              if (0 < (longlong)(int)(uVar47 + local_f0)) {
                do {
                  uVar29 = *puVar34;
                  puVar1 = puVar34 + 1;
                  *puVar34 = uVar29 << (*(byte *)(param_1 + 0x121cb6) & 0x1f) |
                             uVar29 << (*(byte *)(param_1 + 0x121cb4) & 0x1f) |
                             uVar29 << (*(byte *)(param_1 + 0x121cb7) & 0x1f) |
                             uVar29 << (*(byte *)(param_1 + 0x121cb5) & 0x1f);
                  uVar29 = puVar1[uVar49 - 1];
                  puVar1[uVar49 - 1] =
                       uVar29 << (*(byte *)(param_1 + 0x121cb6) & 0x1f) |
                       uVar29 << (*(byte *)(param_1 + 0x121cb4) & 0x1f) |
                       uVar29 << (*(byte *)(param_1 + 0x121cb7) & 0x1f) |
                       uVar29 << (*(byte *)(param_1 + 0x121cb5) & 0x1f);
                  lVar35 = lVar35 + -1;
                  puVar34 = puVar1;
                } while (lVar35 != 0);
              }
              puVar60 = (uint *)((longlong)puVar60 + lVar68);
              uVar61 = uVar61 - 1;
            } while (uVar61 != 0);
          }
        }
      }
      if (param_14 != 0) {
        iVar67 = local_a8 + -1;
        iVar31 = local_90 + -1;
        local_d0 = CONCAT44(iVar31,iVar67);
        iVar56 = local_a8 + -1 + (uint)*(ushort *)(param_1 + 0x1217d6);
        iVar59 = local_90 + -1 + (uint)*(ushort *)(param_1 + 0x1217d6);
        if (*(int *)(param_1 + 0x122108) == 0) {
          *(undefined4 *)(param_1 + 0x122108) = 1;
          *(undefined8 *)(param_1 + 0x12210c) = local_d0;
          *(ulonglong *)(param_1 + 0x122114) = CONCAT44(iVar59,iVar56);
        }
        else {
          if (iVar67 < *(int *)(param_1 + 0x12210c)) {
            *(int *)(param_1 + 0x12210c) = iVar67;
          }
          if (iVar31 < *(int *)(param_1 + 0x122110)) {
            *(int *)(param_1 + 0x122110) = iVar31;
          }
          if (*(int *)(param_1 + 0x122114) < iVar56) {
            *(int *)(param_1 + 0x122114) = iVar56;
          }
          if (*(int *)(param_1 + 0x122118) < iVar59) {
            *(int *)(param_1 + 0x122118) = iVar59;
          }
        }
      }
    }
  }
  sVar24 = (short)local_f0;
  *(short *)((longlong)param_2 + 0xe) = *(short *)((longlong)param_2 + 0xe) + sVar24;
  *(short *)(param_2 + 4) = (short)param_2[4] + sVar24;
  *(short *)((longlong)param_2 + 0x12) = *(short *)((longlong)param_2 + 0x12) + sVar24;
LAB_14015e1a4:
  iVar67 = 0;
  if ((param_3 < 0x10000) && (param_4 == 0)) {
    puVar33 = (undefined4 *)(param_1 + 0x1bbd8 + (ulonglong)param_3 * 0x10);
    *puVar33 = 1;
    *(uint **)(puVar33 + 2) = param_2;
    *(undefined4 **)(param_2 + 0xc) = puVar33;
  }
  else {
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    if (*(int *)(param_1 + 0x11bbd8) == 0x400) {
      plVar39 = (longlong *)(param_1 + 0x11bbe0);
      puVar60 = (uint *)*plVar39;
      while (puVar60 == param_2) {
        iVar67 = iVar67 + 1;
        plVar39 = plVar39 + 1;
        puVar60 = (uint *)*plVar39;
      }
      plVar39 = (longlong *)((longlong)iVar67 * 8 + 0x11bbe0 + param_1);
      *(undefined1 *)(*plVar39 + 8) = 0;
      iVar31 = *(int *)(param_1 + 0x11bbd8) + -1;
      *(int *)(param_1 + 0x11bbd8) = iVar31;
      iVar31 = iVar31 - iVar67;
      if (0 < iVar31) {
        FUN_1401ae320(plVar39,(longlong)(iVar67 + 1) * 8 + 0x11bbe0 + param_1,(longlong)iVar31 << 3)
        ;
      }
    }
    *(uint **)(param_1 + 0x11bbe0 + (longlong)*(int *)(param_1 + 0x11bbd8) * 8) = param_2;
    *(int *)(param_1 + 0x11bbd8) = *(int *)(param_1 + 0x11bbd8) + 1;
  }
  *(undefined2 *)(param_2 + 2) = 1;
  return 0;
}


