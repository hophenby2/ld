// Function: FUN_140106be0 @ 140106be0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140106be0(void)

{
  ulonglong uVar1;
  double dVar2;
  short sVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  double dVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  FILE *pFVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined8 *puVar20;
  uint uVar21;
  int iVar22;
  longlong lVar23;
  int iVar24;
  uint uVar25;
  bool bVar26;
  float fVar27;
  float fVar28;
  double dVar29;
  double dVar30;
  undefined8 uVar31;
  double dVar32;
  float fVar33;
  double dVar34;
  undefined1 auVar35 [16];
  float fVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined1 auStack_198 [32];
  ulonglong local_178;
  undefined4 local_170;
  undefined1 local_168 [8];
  double dStack_160;
  undefined8 local_158;
  undefined4 local_150;
  undefined4 local_148;
  int local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined8 local_118 [4];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  ulonglong local_d0;
  
  iVar22 = DAT_140e445fc;
  dVar11 = DAT_14053a020;
  dVar32 = DAT_140539d28;
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_198;
  local_118[0] = _DAT_14053bb80;
  local_118[1] = _UNK_14053bb88;
  local_f8 = _DAT_14053bb90;
  uStack_f0 = _UNK_14053bb98;
  local_118[2] = _DAT_14053bba0;
  local_118[3] = _UNK_14053bba8;
  iVar24 = DAT_140e44194;
  iVar18 = DAT_140e41b70;
  if (DAT_140e41b00 == 1) {
    iVar24 = DAT_140e452e8;
    iVar18 = DAT_140e452ec;
  }
  if (DAT_140e467b8 == 1) {
    DAT_140e445e8 = -0x4000;
  }
  if (DAT_140e467bc == 1) {
    DAT_140e445e8 = 0x4000;
  }
  iVar19 = 0;
  if (DAT_140e467c0 == 1) {
    DAT_140e445e8 = 0;
  }
  if (DAT_140e467c4 == 1) {
    DAT_140e445e8 = -0x8000;
  }
  if (DAT_140e467c0 == 1) {
    if (DAT_140e467bc == 1) {
      DAT_140e445e8 = 0x2000;
      goto LAB_140106d40;
    }
LAB_140106d52:
    if (DAT_140e467c4 != 1) goto LAB_140106d6c;
LAB_140106d58:
    if (DAT_140e467b8 == 1) {
      DAT_140e445e8 = -0x6000;
LAB_140106d72:
      if (DAT_140e467c0 == 1) {
        DAT_140e445e8 = -0x2000;
      }
    }
  }
  else {
    if (DAT_140e467bc != 1) goto LAB_140106d52;
LAB_140106d40:
    if (DAT_140e467c4 == 1) {
      DAT_140e445e8 = 0x6000;
      goto LAB_140106d58;
    }
LAB_140106d6c:
    if (DAT_140e467b8 == 1) goto LAB_140106d72;
  }
  uVar21 = 0;
  if (iVar24 == 1) {
    if (DAT_140e467dc == 0) {
      DAT_140e44644 = 0;
      bVar26 = (int)DAT_140e44648 < 0;
      if (!bVar26) goto LAB_140106e7b;
      DAT_140e44648 = 1;
LAB_140106e7d:
      DAT_140e44648 = DAT_140e44648 + 1;
    }
    else {
      DAT_140e44644 = 1;
      if (0 < (int)DAT_140e44648) goto LAB_140106e72;
    }
LAB_140106e87:
    if ((int)DAT_140e44648 < 0) goto LAB_140106e89;
  }
  else {
    if (DAT_140e44650 != 0) {
      DAT_140e44650 = DAT_140e44650 + 1;
    }
    if (DAT_140e467cc._4_4_ == 1) {
      if (DAT_140e44650 == 0) {
        DAT_140e44650 = 1;
      }
      else if (DAT_140e44650 != 1) {
        if ((0xb < DAT_140e44650) && (DAT_140e44644 = 1, 0 < (int)DAT_140e44648)) {
          DAT_140e44648 = 0xffffffff;
        }
        goto LAB_140106e63;
      }
      if (DAT_140e467d8 == 1) {
        DAT_140e44650 = 8;
      }
    }
    else {
      DAT_140e44644 = 0;
      if (((int)DAT_140e44648 < 0) && (DAT_140e467dc == 0)) {
        DAT_140e44648 = 1;
      }
      if (DAT_140e44650 != 0) {
        DAT_140e44650 = 0;
      }
    }
LAB_140106e63:
    if (DAT_140e467dc != 1) {
      bVar26 = (int)DAT_140e44648 < 0;
LAB_140106e7b:
      if (DAT_140e44648 == 0 || bVar26) goto LAB_140106e87;
      goto LAB_140106e7d;
    }
    DAT_140e44644 = DAT_140e467dc;
    if ((int)DAT_140e44648 < 1) goto LAB_140106e87;
LAB_140106e72:
    DAT_140e44648 = 0xffffffff;
LAB_140106e89:
    DAT_140e44648 = DAT_140e44648 - 1;
  }
  if ((((DAT_140e467c0 == 1) && (DAT_140e467bc == 1)) && (DAT_140e467c4 == 1)) &&
     (DAT_140e467b8 == 1)) {
LAB_140106ecf:
    if (DAT_140e44644 == 0) {
      uVar37 = (undefined4)local_118[(longlong)DAT_140e445c0 * 2];
      uVar38 = (undefined4)((ulonglong)local_118[(longlong)DAT_140e445c0 * 2] >> 0x20);
    }
    else {
      uVar37 = (undefined4)local_118[(longlong)DAT_140e445c0 * 2 + 1];
      uVar38 = (undefined4)((ulonglong)local_118[(longlong)DAT_140e445c0 * 2 + 1] >> 0x20);
    }
    DAT_140e445f0 = (double)CONCAT44(uVar38,uVar37);
  }
  else {
    uVar37 = 0;
    uVar38 = 0;
    DAT_140e445f0 = 0.0;
    if (((DAT_140e467c0 == 1) || (DAT_140e467bc == 1)) ||
       ((DAT_140e467c4 == 1 || (DAT_140e467b8 == 1)))) goto LAB_140106ecf;
  }
  if (((DAT_140e445e8 + 0xc000U & 0x7fff) == 0) || ((double)CONCAT44(uVar38,uVar37) == 0.0)) {
    if ((int)DAT_140e4464c < 0) {
      DAT_140e4464c = DAT_140e4464c + 1;
    }
    else if (0 < (int)DAT_140e4464c) {
      DAT_140e4464c = DAT_140e4464c - 1;
    }
  }
  else if ((ushort)(DAT_140e445e8 + 0xc000U) < 0x8001) {
    if ((ushort)(DAT_140e445e8 + 0xbfffU) < 0x7fff) {
      if (0 < (int)DAT_140e4464c) {
        DAT_140e4464c = uVar21;
      }
      DAT_140e4464c = DAT_140e4464c - 1;
      if ((int)DAT_140e4464c < -0xb) {
        DAT_140e4464c = 0xfffffff4;
      }
    }
  }
  else {
    if ((int)DAT_140e4464c < 0) {
      DAT_140e4464c = uVar21;
    }
    DAT_140e4464c = DAT_140e4464c + 1;
    if (0xb < (int)DAT_140e4464c) {
      DAT_140e4464c = 0xc;
    }
  }
  if (0xb4 < DAT_140e445fc) {
    uVar37 = 0;
    uVar38 = 0;
    DAT_140e445f0 = 0.0;
  }
  dVar29 = (double)FUN_1403307c0();
  fVar36 = DAT_140e445d8 + (float)(dVar29 * (double)CONCAT44(uVar38,uVar37) * DAT_140539f68);
  dVar29 = (double)FUN_140332d90();
  _DAT_140e445d8 =
       (FILE *)CONCAT44(DAT_140e445dc + (float)(dVar29 * (double)CONCAT44(uVar38,uVar37)),fVar36);
  _DAT_140e445d8 = (FILE *)FUN_1401346a0(_DAT_140e445d8,4);
  uVar12 = _UNK_14053bb28;
  dVar29 = _DAT_14053bb20;
  fVar28 = DAT_14053aec0;
  fVar36 = DAT_14053ae30;
  local_e8._0_4_ = SUB84(_DAT_140e445d8,0);
  fVar14 = (float)local_e8;
  local_e8._4_4_ = (float)((ulonglong)_DAT_140e445d8 >> 0x20);
  fVar15 = local_e8._4_4_;
  pFVar16 = _DAT_140e445d8;
  if (iVar22 - 0xb5U < 0x28) {
    fVar27 = DAT_14053aec0 - local_e8._4_4_;
    fVar33 = DAT_14053ae30 - (float)local_e8;
    local_e8 = _DAT_140e445d8;
    FUN_1403300b4((double)fVar27,(double)fVar33);
    fVar36 = (float)FUN_140334430(fVar14 - fVar36);
    fVar28 = (float)FUN_140334430(fVar15 - fVar28);
    if (fVar36 + fVar28 < 0.0) {
      fVar36 = (float)FUN_1403352f8();
    }
    else {
      fVar36 = SQRT(fVar36 + fVar28);
    }
    dVar2 = (double)fVar36 / DAT_14053a1e8 + dVar29;
    dVar30 = (double)FUN_1403307c0();
    _DAT_140e445d8 = (FILE *)CONCAT44(DAT_140e445dc,(float)(dVar30 * dVar2) + fVar14);
    dVar30 = (double)FUN_140332d90();
    _DAT_140e445d8 = (FILE *)CONCAT44((float)(dVar30 * dVar2) + fVar15,DAT_140e445d8);
    pFVar16 = local_e8;
  }
  local_e8 = pFVar16;
  FUN_14010cc90();
  if (DAT_140e445fc < 0xb4) {
    if (DAT_140e44600 < 1) {
      if (DAT_140e41b08 == 0) {
        if (iVar24 == 1) {
          if ((DAT_140e467cc._4_4_ == 1) || (DAT_140e467d8 == 1)) {
            DAT_140e44640 = DAT_140e44640 + 1;
          }
          if ((DAT_140e467cc._4_4_ == 0) && (DAT_140e467d8 == 0)) {
            if (DAT_140e44640 % 5 == 4) goto LAB_140107272;
            if (DAT_140e44640 != 0) {
              DAT_140e44640 = DAT_140e44640 + 1;
            }
          }
        }
        else {
          if (DAT_140e44640 != 0) {
            DAT_140e44640 = DAT_140e44640 + 1;
          }
          if (((DAT_140e467cc._4_4_ == 1) || (DAT_140e467d8 == 1)) && (DAT_140e44640 == 0)) {
            DAT_140e44640 = 1;
          }
          if (((DAT_140e467cc._4_4_ == 0) && (DAT_140e467d8 == 0)) && (0x10 < DAT_140e44640)) {
LAB_140107272:
            DAT_140e44640 = 0;
          }
        }
        if (DAT_140e44640 % 5 == 1) {
          FUN_14010db70();
        }
      }
      goto LAB_1401072b3;
    }
LAB_1401072ca:
    DAT_140e44640 = 0;
  }
  else {
LAB_1401072b3:
    if (((0 < DAT_140e44600) || (0xb3 < DAT_140e445fc)) || (DAT_140e41b08 == 1)) goto LAB_1401072ca;
  }
  if (((DAT_140e445c0 == 0) && (DAT_140e445c8 == 0)) &&
     ((0x7fffffff < DAT_140e44648 && (DAT_140e44640 == 1)))) {
    DAT_140e44648 = 0xffffffff;
  }
  if (DAT_140e467d4 == 1) {
    if (DAT_140e44600 != 0) goto LAB_140107a60;
    if ((((DAT_140e45d34 != 0) || ((49999 < DAT_140e45d18 && (iVar18 == 1)))) &&
        (DAT_140e41a3c == 0)) &&
       ((0x8b < DAT_140e445fc - 0x78U && ((-1 < DAT_140e45d18 || (0x116 < DAT_140e44654 - 1)))))) {
      if ((iVar18 == 0) || ((iVar18 == 1 && (DAT_140e45d18 < 50000)))) {
        local_118[0] = _DAT_14053c5a0;
        local_118[1] = _UNK_14053c5a8;
        local_e8 = _DAT_14053b890;
        uStack_e0 = _UNK_14053b898;
        local_118[2] = 0xfffffef2ffffff2e;
        local_d8 = 300;
        local_d4 = 0x168;
        if (DAT_140e445c0 == 0) {
          if (DAT_140e445cc == 0) {
            auVar35._12_4_ = 0;
            auVar35._0_12_ = stack0xfffffffffffffe9c;
            _local_168 = auVar35 << 0x20;
            local_170 = 0;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0xb);
          }
          if (DAT_140e445cc == 1) {
            local_168._0_4_ = DAT_14053acb0;
            local_170 = 0;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0xe);
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47258);
            FUN_14018a340(DAT_140e47258,1,1);
          }
        }
        if (DAT_140e445c0 == 1) {
          if (DAT_140e445cc == 0) {
            auVar5._12_4_ = 0;
            auVar5._0_12_ = stack0xfffffffffffffe9c;
            _local_168 = auVar5 << 0x20;
            local_170 = 0;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0xf);
          }
          if (DAT_140e445cc == 1) {
            auVar6._12_4_ = 0;
            auVar6._0_12_ = stack0xfffffffffffffe9c;
            _local_168 = auVar6 << 0x20;
            local_170 = 0;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0x11);
          }
        }
        if (DAT_140e445c0 == 2) {
          if (DAT_140e445cc == 0) {
            auVar7._12_4_ = 0;
            auVar7._0_12_ = stack0xfffffffffffffe9c;
            _local_168 = auVar7 << 0x20;
            local_170 = 0;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0x12);
          }
          if (DAT_140e445cc == 1) {
            auVar8._12_4_ = 0;
            auVar8._0_12_ = stack0xfffffffffffffe9c;
            _local_168 = auVar8 << 0x20;
            local_170 = 0xf;
            local_178 = CONCAT62(local_178._2_6_,0xc000);
            FUN_140109660(0x15);
          }
        }
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4724c);
        FUN_14018a340(DAT_140e4724c,1,1);
        if (DAT_140e4192c == 0) {
          DAT_140e4192c = 1;
        }
        if (DAT_140e41b00 == 0) {
          DAT_140e44174 = DAT_140e44174 + 1;
        }
        if (DAT_140e445fc < 0x104) {
          uVar37 = *(undefined4 *)(&DAT_140e419cc + (longlong)(DAT_140e445c0 * 10) * 4);
          puVar20 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar20 = (undefined8 *)_malloc_base(0x60);
            if (puVar20 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
            *puVar20 = 1;
            *(undefined4 *)(puVar20 + 1) = 0x16;
            *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
            puVar20[2] = 0x6f;
            puVar20[3] = 0;
            *(undefined4 *)(puVar20 + 4) = 0;
            *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
            puVar20[5] = 0;
            puVar20[6] = 0x3ff0000000000000;
            puVar20[7] = 0x3ff0000000000000;
            *(undefined4 *)(puVar20 + 8) = 0xb4;
            *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
            *(undefined4 *)(puVar20 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
            puVar20[10] = 0xff;
            puVar20[0xb] = 0;
            if (bVar26) {
              DAT_140e45d78 = puVar20;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar20;
            }
          }
        }
        else {
          uVar38 = DAT_140e445dc;
          uVar37 = DAT_140e445d8;
          puVar20 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar20 = (undefined8 *)_malloc_base(0x60);
            if (puVar20 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
            *(undefined4 *)((longlong)puVar20 + 0x14) = uVar37;
            *(undefined4 *)(puVar20 + 3) = uVar38;
            *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar37;
            *(undefined4 *)(puVar20 + 4) = uVar38;
            *puVar20 = 1;
            puVar20[1] = 0x36;
            *(undefined4 *)(puVar20 + 2) = 0x28;
            *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
            puVar20[5] = 0;
            puVar20[6] = 0x3ff0000000000000;
            puVar20[7] = 0x3ff0000000000000;
            *(undefined4 *)(puVar20 + 8) = 0;
            *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
            *(undefined4 *)(puVar20 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
            puVar20[10] = 0xff;
            puVar20[0xb] = 0;
            if (bVar26) {
              DAT_140e45d78 = puVar20;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar20;
            }
          }
          DAT_140e45d28 = puVar20;
          uVar37 = *(undefined4 *)(&DAT_140e419dc + (longlong)(DAT_140e445c0 * 10) * 4);
          puVar20 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar20 = (undefined8 *)_malloc_base(0x60);
            if (puVar20 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
            *puVar20 = 1;
            *(undefined4 *)(puVar20 + 1) = 0x16;
            *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
            puVar20[2] = 0x6f;
            puVar20[3] = 0;
            *(undefined4 *)(puVar20 + 4) = 0;
            *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
            puVar20[5] = 0;
            puVar20[6] = 0x3ff0000000000000;
            puVar20[7] = 0x3ff0000000000000;
            *(undefined4 *)(puVar20 + 8) = 0xb4;
            *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
            *(undefined4 *)(puVar20 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
            puVar20[10] = 0xff;
            puVar20[0xb] = 0;
            if (bVar26) {
              DAT_140e45d78 = puVar20;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar20;
            }
          }
          DAT_140e45d28 = puVar20;
          _DAT_140e477e8 = _DAT_140e477e8 + 1;
          puVar20 = DAT_140e45d28;
        }
        DAT_140e45d28 = puVar20;
        DAT_140e45d34 = DAT_140e45d34 - 1;
        DAT_140e445fc = 0;
        DAT_140e45d88 = DAT_140e45d88 - *(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4);
        lVar23 = (longlong)DAT_140e445cc + (longlong)DAT_140e445c0 * 2;
        DAT_140e44600 = *(int *)((longlong)local_118 + lVar23 * 4);
        DAT_140e44654 = *(uint *)((longlong)&local_e8 + lVar23 * 4);
      }
      else {
        auVar4._12_4_ = 0;
        auVar4._0_12_ = stack0xfffffffffffffe9c;
        _local_168 = auVar4 << 0x20;
        local_170 = 0;
        local_178 = (ulonglong)local_178._2_6_ << 0x10;
        DAT_140e45d18 = -600;
        FUN_140109660(0x18);
        uVar37 = *(undefined4 *)(&DAT_140e419d8 + (longlong)(DAT_140e445c0 * 10) * 4);
        puVar20 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar20 = (undefined8 *)_malloc_base(0x60);
          if (puVar20 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar20 = 1;
          *(undefined4 *)(puVar20 + 1) = 0x16;
          *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
          puVar20[2] = 0x6f;
          puVar20[3] = 0;
          *(undefined4 *)(puVar20 + 4) = 0;
          *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
          puVar20[5] = 0;
          puVar20[6] = 0x3ff0000000000000;
          puVar20[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar20 + 8) = 0x78;
          *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
          *(undefined4 *)(puVar20 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
          puVar20[10] = 0xff;
          puVar20[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar20;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar20;
          }
        }
        DAT_140e45d28 = puVar20;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47280);
        FUN_14018a340(DAT_140e47280,1,1);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47284);
        FUN_14018a340(DAT_140e47284,1,1);
        DAT_140e445fc = 0;
        if ((int)DAT_140e44654 < 0x96) {
          DAT_140e44654 = 0x96;
        }
        else if (0x117 < (int)DAT_140e44654) {
          DAT_140e44654 = 0x118;
        }
        if (DAT_140e41b00 == 0) {
          DAT_140e44178 = DAT_140e44178 + 1;
        }
        DAT_140e467f4 = DAT_140e467f4 + 1;
      }
      goto LAB_140107a5b;
    }
  }
  else {
LAB_140107a5b:
    if (DAT_140e44600 != 0) {
LAB_140107a60:
      DAT_140e44600 = DAT_140e44600 + 1;
    }
    if (0xb3 < DAT_140e44600) {
      DAT_140e44600 = -0x1e;
    }
  }
  fVar36 = DAT_14053acfc;
  dVar2 = DAT_14053a7c8;
  if ((DAT_140e445c0 == 1) && (DAT_140e445cc == 1)) {
    if (0 < DAT_140e44658) {
      local_130 = 0;
      local_138 = 1;
      local_140 = 0xff;
      local_148 = 0x40;
      local_150 = 0x40;
      local_158 = CONCAT44(local_158._4_4_,0xff);
      dStack_160 = dVar29;
      local_168 = (undefined1  [8])((double)DAT_140e44658 / DAT_14053a7c8);
      local_170 = local_170 & 0xffff0000;
      local_178 = CONCAT44(local_178._4_4_,DAT_140e445dc + DAT_14053acfc);
      FUN_1400c8410(DAT_140e45d8c,0x50,7,(ulonglong)_DAT_140e445d8 & 0xffffffff);
      DAT_140e44658 = DAT_140e44658 + -1;
    }
    if (DAT_140e44658 < 0) {
      DAT_140e44658 = 0;
    }
  }
  if ((DAT_140e445dc <= DAT_14053ae14) && (lVar23 = DAT_140e46e90, DAT_140e445fc < 0xb4)) {
    for (; lVar23 != 0; lVar23 = *(longlong *)(lVar23 + 0x28)) {
      if ((0x1f < *(int *)(lVar23 + 4)) && (1 < *(int *)(lVar23 + 8) - 6U)) {
        *(undefined4 *)(lVar23 + 0x24) = 1;
      }
    }
  }
  if (DAT_140e445fc == 0x104) {
    if ((DAT_140e45d34 == 0) || (DAT_140e445d0 == 3)) {
      uVar38 = DAT_140e445dc;
      uVar37 = DAT_140e445d8;
      puVar20 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar20 + 0x14) = uVar37;
        *(undefined4 *)(puVar20 + 3) = uVar38;
        *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar37;
        *(undefined4 *)(puVar20 + 4) = uVar38;
        *puVar20 = 1;
        puVar20[1] = 0x10;
        *(undefined4 *)(puVar20 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xff;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
      DAT_140e45d28 = puVar20;
      uVar21 = DAT_14053ac80;
      uVar1 = DAT_14053a040;
      if (DAT_140e445f8 == 0) {
LAB_1401082c5:
        iVar22 = DAT_140e41abc;
        if (DAT_140e41b00 == 0) {
          lVar23 = (longlong)DAT_1407c7798;
          if (DAT_140e41928 == 0) {
            (&DAT_140e41bbc)[lVar23 * 0x96 + (longlong)DAT_140e419b8] =
                 (&DAT_140e41bbc)[lVar23 * 0x96 + (longlong)DAT_140e419b8] + 1;
LAB_14010833e:
            *(int *)(&DAT_140e41c84 + (lVar23 * 0x96 + (longlong)DAT_140e419b8) * 4) =
                 *(int *)(&DAT_140e41c84 + (lVar23 * 0x96 + (longlong)DAT_140e419b8) * 4) + 1;
          }
          else {
            if (DAT_140e41928 == 1) {
              if (DAT_140e41abc != 3) {
                (&DAT_140e41bbc)[(longlong)(DAT_140e41abc + 0xb) * 0x96 + (longlong)DAT_140e419b8] =
                     (&DAT_140e41bbc)
                     [(longlong)(DAT_140e41abc + 0xb) * 0x96 + (longlong)DAT_140e419b8] + 1;
LAB_14010835d:
                if (iVar22 != 3) {
                  *(int *)(&DAT_140e41c84 +
                          ((longlong)(iVar22 + 0xb) * 0x96 + (longlong)DAT_140e419b8) * 4) =
                       *(int *)(&DAT_140e41c84 +
                               ((longlong)(iVar22 + 0xb) * 0x96 + (longlong)DAT_140e419b8) * 4) + 1;
LAB_1401083a7:
                  if (iVar22 != 3) {
                    *(int *)(&DAT_140e41d4c +
                            ((longlong)(iVar22 + 0xb) * 0x96 + (longlong)DAT_140e419b8) * 4) =
                         *(int *)(&DAT_140e41d4c +
                                 ((longlong)(iVar22 + 0xb) * 0x96 + (longlong)DAT_140e419b8) * 4) +
                         1;
                  }
                }
              }
              goto LAB_1401083cc;
            }
            if (DAT_140e41928 == 0) goto LAB_14010833e;
            if (DAT_140e41928 == 1) goto LAB_14010835d;
            if (DAT_140e41928 != 0) {
              if (DAT_140e41928 != 1) goto LAB_1401083cc;
              goto LAB_1401083a7;
            }
          }
          *(int *)(&DAT_140e41d4c + (lVar23 * 0x96 + (longlong)DAT_140e419b8) * 4) =
               *(int *)(&DAT_140e41d4c + (lVar23 * 0x96 + (longlong)DAT_140e419b8) * 4) + 1;
        }
LAB_1401083cc:
        fopen_s((FILE **)&local_e8,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_e8);
        FUN_140323e90(local_e8);
        DAT_140e471fc = 0xb4;
        uVar37 = *(undefined4 *)(&DAT_140e419e4 + (longlong)(DAT_140e445c0 * 10) * 4);
        puVar20 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar20 = (undefined8 *)_malloc_base(0x60);
          if (puVar20 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar20 = 1;
          *(undefined4 *)(puVar20 + 1) = 0x16;
          *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
          puVar20[2] = 0x6f;
          puVar20[3] = 0;
          *(undefined4 *)(puVar20 + 4) = 0;
          *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
          puVar20[5] = 0;
          puVar20[6] = 0x3ff0000000000000;
          puVar20[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar20 + 8) = 1000;
          *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
          *(undefined4 *)(puVar20 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
          puVar20[10] = 0xff;
          puVar20[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar20;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar20;
          }
        }
        DAT_140e45d28 = puVar20;
        DAT_140e468bc = DAT_140e468bc + 1;
        DAT_140e445d4 = 0;
        DAT_140e45274 = 0;
        DAT_140e46014 = 0;
        DAT_140e45fac = 0;
        DAT_140e45270 = 0x1e;
      }
      else {
        if (DAT_140e45270 == 0x14) {
          local_170 = DAT_14053ac80;
          local_178 = DAT_14053a040;
          uVar17 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar17 = uVar17 * 0x800 ^ uVar17;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ uVar17 ^ DAT_140e9fd18;
          FUN_1400ca6d0(6,(ulonglong)DAT_140e9fd1c / 0x4001,DAT_140e445dc,
                        CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                 (short)DAT_140e9fd1c +
                                 (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + -0x6000));
          if (1 < DAT_140e477e4) {
            local_170 = uVar21;
            local_178 = uVar1;
            uVar17 = (DAT_140e418c8 + 10 >> 0x1e ^ DAT_140e418c8 + 10) * 0x6c078965 + 1;
            uVar21 = uVar17 * 0x800 ^ uVar17;
            DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ uVar21 ^ DAT_140e9fd18;
            FUN_1400ca6d0(6,(ulonglong)DAT_140e9fd1c / 0x4001,DAT_140e445dc,
                          CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                   (short)DAT_140e9fd1c +
                                   (short)((ulonglong)DAT_140e9fd1c / 0x4001) * -0x4001 + -0x6000));
          }
        }
        uVar37 = *(undefined4 *)(&DAT_140e419e0 + (longlong)(DAT_140e445c0 * 10) * 4);
        puVar20 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar20 = (undefined8 *)_malloc_base(0x60);
          if (puVar20 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar20 = 1;
          *(undefined4 *)(puVar20 + 1) = 0x16;
          *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
          puVar20[2] = 0x6f;
          puVar20[3] = 0;
          *(undefined4 *)(puVar20 + 4) = 0;
          *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
          puVar20[5] = 0;
          puVar20[6] = 0x3ff0000000000000;
          puVar20[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar20 + 8) = 0x78;
          *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
          *(undefined4 *)(puVar20 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
          puVar20[10] = 0xff;
          puVar20[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar20;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar20;
          }
        }
        DAT_140e45d28 = puVar20;
        if (DAT_140e445f8 == 0) goto LAB_1401082c5;
        FUN_14006c420();
        DAT_140e445f8 = DAT_140e445f8 + -1;
      }
      if ((((DAT_140e45d34 == 3) && (DAT_140e41b00 == 0)) && (DAT_140e467e8 == 0)) &&
         (DAT_140e44054 == 0)) {
        DAT_140e44054 = 1;
        FUN_1400b4350(1,0x1c);
        FUN_1400d0a30();
        DAT_140e45f68 = 0x3c;
      }
      DAT_140e477e4 = DAT_140e477e4 + 1;
      DAT_140e44658 = 0;
      puVar20 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar20 = 1;
        puVar20[1] = 0x1f;
        puVar20[2] = 1;
        puVar20[3] = 0;
        *(undefined4 *)(puVar20 + 4) = 0;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0x50;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xff;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
    }
    else {
      local_118[0] = _DAT_14053bdf0;
      local_118[1] = _UNK_14053bdf8;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4727c);
      FUN_14018a340(DAT_140e4727c,1,1);
      uVar13 = DAT_140e45060;
      uVar38 = DAT_140e445dc;
      uVar37 = DAT_140e445d8;
      puVar20 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar20 + 0x14) = uVar37;
        *(undefined4 *)(puVar20 + 3) = uVar38;
        *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar37;
        *(undefined4 *)(puVar20 + 4) = uVar38;
        *puVar20 = 1;
        *(undefined4 *)(puVar20 + 1) = 0x13;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar13;
        *(undefined4 *)(puVar20 + 2) = 0x5b;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0;
        puVar20[7] = 0;
        *(undefined4 *)(puVar20 + 8) = 0;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xff;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
      DAT_140e45d28 = puVar20;
      if (DAT_140e445d0 == 0) {
        local_168._0_4_ = DAT_14053ade0;
        local_170 = 0;
        local_178 = (ulonglong)local_178._2_6_ << 0x10;
        FUN_140109660(0x16);
        uVar21 = DAT_140e45d88 - *(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4);
        DAT_140e45d34 = DAT_140e45d34 - 1;
      }
      else {
        local_168._0_4_ = *(undefined4 *)((longlong)local_118 + (longlong)(int)DAT_140e45d34 * 4);
        local_170 = 0;
        local_178 = (ulonglong)local_178._2_6_ << 0x10;
        FUN_140109660(0x16);
        DAT_140e45d34 = uVar21;
      }
      uVar37 = *(undefined4 *)(&DAT_140e419d0 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar20 = DAT_140e45d28;
      DAT_140e45d88 = uVar21;
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar22 = DAT_140e45d1c + 1;
        *puVar20 = 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar20 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
        puVar20[2] = 0x6f;
        puVar20[3] = 0;
        *(undefined4 *)(puVar20 + 4) = 0;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xff;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        DAT_140e45d1c = iVar22;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
        if (iVar22 < 0x1000) {
          DAT_140e45d28 = puVar20;
          puVar20 = (undefined8 *)_malloc_base(0x60);
          if (puVar20 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar20 = 1;
          puVar20[1] = 0x1e;
          puVar20[2] = 1;
          puVar20[3] = 0;
          *(undefined4 *)(puVar20 + 4) = 0;
          *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
          puVar20[5] = 0;
          puVar20[6] = 0x3ff0000000000000;
          puVar20[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar20 + 8) = 0x60;
          *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
          *(undefined4 *)(puVar20 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
          puVar20[10] = 0xff;
          puVar20[0xb] = 0;
          if (bVar26) {
            DAT_140e45d78 = puVar20;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar20;
          }
        }
      }
      DAT_140e45d28 = puVar20;
      DAT_140e445fc = 0;
      DAT_140e44600 = -0x78;
      puVar20 = DAT_140e45d28;
      if ((int)DAT_140e44654 < 0x96) {
        DAT_140e44654 = 0x96;
      }
    }
    DAT_140e45d28 = puVar20;
    DAT_140e46b24 = DAT_140e46b24 + 1;
    DAT_140e4192c = -1;
  }
  if (0 < DAT_140e445fc) {
    DAT_140e445fc = DAT_140e445fc + -1;
  }
  if (DAT_140e45270 == 0x15) {
    DAT_140e445f8 = 2;
  }
  FUN_14010e250();
  uVar37 = DAT_140e41950;
  if (DAT_140e45d18 < 50000) {
LAB_140108a88:
    uVar21 = DAT_140e418c8;
    if (DAT_140e45d18 < 0) {
      if (DAT_140e46b2c == 0) {
        DAT_140e45d18 = DAT_140e45d18 + 1;
      }
      uVar17 = DAT_140e44acc & 0x8000000f;
      if ((int)uVar17 < 0) {
        uVar17 = (uVar17 - 1 | 0xfffffff0) + 1;
      }
      if ((uVar17 == 0) && (DAT_140e45d18 < -0x3c)) {
        uVar25 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar17 = uVar25 ^ uVar25 * 0x800;
        uVar25 = uVar25 ^ uVar25 * 0x800;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar25 = (uVar25 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar25 ^ DAT_140e9fd18;
        auVar35 = ZEXT416((uint)(float)(((uVar17 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar17 ^
                                        DAT_140e9fd18) % 0x2d1));
        DAT_140e9fd1c = uVar25;
        uVar31 = FUN_140134db0(DAT_140e418c8,DAT_140539f90,DAT_14053a018);
        uVar37 = (undefined4)uVar31;
        uVar38 = (undefined4)((ulonglong)uVar31 >> 0x20);
        dStack_160 = (double)FUN_140134db0(uVar21);
        local_128 = 0;
        local_130 = 0x60;
        local_138 = 0xff;
        local_140 = 0xff;
        local_148 = 0xff;
        local_150 = 0x168;
        local_158 = CONCAT44(uVar38,uVar37);
        local_168 = (undefined1  [8])DAT_14053a218;
        local_170 = CONCAT22(local_170._2_2_,
                             (short)uVar25 + (short)(uVar25 / 0x7d1) * -0x7d1 + -0x43e8);
        local_178 = CONCAT44(local_178._4_4_,DAT_14053afd4);
        FUN_140070d00(0x18,DAT_140e41a40,0x16,auVar35._0_8_);
      }
      if (DAT_140e45d18 == 0) {
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47288);
        FUN_14018a340(DAT_140e47288,1,1);
        auVar10._12_4_ = 0;
        auVar10._0_12_ = stack0xfffffffffffffe9c;
        _local_168 = auVar10 << 0x20;
        local_170 = 0;
        local_178 = local_178 & 0xffffffffffff0000;
        FUN_140109660(0x18);
      }
    }
  }
  else {
    if (iVar18 == 0) {
      auVar9._12_4_ = 0;
      auVar9._0_12_ = stack0xfffffffffffffe9c;
      _local_168 = auVar9 << 0x20;
      local_170 = 0;
      local_178 = local_178 & 0xffffffffffff0000;
      DAT_140e45d18 = -600;
      FUN_140109660(0x18);
      uVar37 = DAT_140e41950;
      fVar28 = DAT_140e445dc;
      uVar38 = DAT_140e445d8;
      iVar22 = DAT_140e45d1c;
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar22 = DAT_140e45d1c + 1;
        *(undefined4 *)((longlong)puVar20 + 0x14) = uVar38;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)(puVar20 + 3) = fVar28;
        *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar38;
        *(float *)(puVar20 + 4) = fVar28;
        *puVar20 = 1;
        *(undefined4 *)(puVar20 + 1) = 0x15;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
        *(undefined4 *)(puVar20 + 2) = 0x4a;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xc0;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        DAT_140e45d1c = iVar22;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
        uVar38 = DAT_140e445d8;
        DAT_140e45d28 = puVar20;
      }
      uVar37 = DAT_140e46b84;
      fVar28 = DAT_140e445dc - DAT_14053ad40;
      uVar21 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar21 = uVar21 * 0x800 ^ uVar21;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ DAT_140e9fd18 ^ uVar21;
      uVar1 = (ulonglong)DAT_140e9fd1c;
      sVar3 = (short)DAT_140e9fd1c;
      puVar20 = DAT_140e45d28;
      if (iVar22 < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined4 *)((longlong)puVar20 + 0x14) = uVar38;
        iVar22 = DAT_140e45d1c + 1;
        *(float *)(puVar20 + 3) = fVar28;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar38;
        *(float *)(puVar20 + 4) = fVar28;
        *puVar20 = 1;
        *(undefined4 *)(puVar20 + 1) = 0x17;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
        *(undefined4 *)(puVar20 + 2) = 0x4b;
        *(short *)((longlong)puVar20 + 0x24) = sVar3 + (short)(uVar1 / 0x2ee1) * -0x2ee1 + -0x5770;
        puVar20[5] = 0x3ff0000000000000;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0x80;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        DAT_140e45d1c = iVar22;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
      DAT_140e45d28 = puVar20;
      uVar37 = *(undefined4 *)(&DAT_140e419d8 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar20 = DAT_140e45d28;
      if (iVar22 < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar20 = 1;
        *(undefined4 *)(puVar20 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
        puVar20[2] = 0x6f;
        puVar20[3] = 0;
        *(undefined4 *)(puVar20 + 4) = 0;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0xff;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
      DAT_140e45d28 = puVar20;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47280);
      FUN_14018a340(DAT_140e47280,1,1);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47284);
      FUN_14018a340(DAT_140e47284,1,1);
      if ((int)DAT_140e44654 < 0x96) {
        DAT_140e44654 = 0x96;
      }
      if (DAT_140e41b00 == 0) {
        DAT_140e44178 = DAT_140e44178 + 1;
      }
      DAT_140e467f4 = DAT_140e467f4 + 1;
      goto LAB_140108a88;
    }
    if (0x98967e < DAT_140e45d18) goto LAB_140108a88;
    fVar28 = DAT_140e445dc;
    uVar38 = DAT_140e445d8;
    iVar22 = DAT_140e45d1c;
    if (DAT_140e45d1c < 0x1000) {
      puVar20 = (undefined8 *)_malloc_base(0x60);
      if (puVar20 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar22 = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar20 + 0x14) = uVar38;
      bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar20 + 3) = fVar28;
      *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar38;
      *(float *)(puVar20 + 4) = fVar28;
      *puVar20 = 1;
      *(undefined4 *)(puVar20 + 1) = 0x15;
      *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
      *(undefined4 *)(puVar20 + 2) = 0x4a;
      *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
      puVar20[5] = 0;
      puVar20[6] = 0x3ff0000000000000;
      puVar20[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar20 + 8) = 0;
      *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
      *(undefined4 *)(puVar20 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
      puVar20[10] = 0xc0;
      puVar20[0xb] = 0;
      if (bVar26) {
        DAT_140e45d78 = puVar20;
      }
      DAT_140e45d1c = iVar22;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar20;
      }
      uVar38 = DAT_140e445d8;
      DAT_140e45d28 = puVar20;
    }
    uVar37 = DAT_140e46b84;
    fVar28 = DAT_140e445dc - DAT_14053ad40;
    uVar21 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar21 >> 0x1e ^ uVar21) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar21 = uVar21 * 0x800 ^ uVar21;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar21) >> 8 ^ DAT_140e9fd18 ^ uVar21;
    uVar1 = (ulonglong)DAT_140e9fd1c;
    sVar3 = (short)DAT_140e9fd1c;
    puVar20 = DAT_140e45d28;
    if (iVar22 < 0x1000) {
      puVar20 = (undefined8 *)_malloc_base(0x60);
      if (puVar20 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      *(undefined4 *)((longlong)puVar20 + 0x14) = uVar38;
      bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar20 + 3) = fVar28;
      *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar38;
      *(float *)(puVar20 + 4) = fVar28;
      *puVar20 = 1;
      *(undefined4 *)(puVar20 + 1) = 0x17;
      *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
      *(undefined4 *)(puVar20 + 2) = 0x4b;
      *(short *)((longlong)puVar20 + 0x24) = sVar3 + (short)(uVar1 / 0x2ee1) * -0x2ee1 + -0x5770;
      puVar20[5] = 0x3ff0000000000000;
      puVar20[6] = 0x3ff0000000000000;
      puVar20[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar20 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
      *(undefined4 *)(puVar20 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
      puVar20[10] = 0x80;
      puVar20[0xb] = 0;
      if (bVar26) {
        DAT_140e45d78 = puVar20;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar20;
      }
    }
    DAT_140e45d28 = puVar20;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4728c);
    FUN_14018a340(DAT_140e4728c,1,1);
    DAT_140e45d18 = 9999999;
  }
  iVar22 = DAT_140e45d20;
  iVar24 = DAT_140e45d18;
  if ((0 < DAT_140e45d20) && ((iVar18 = FUN_1401340e0(), 0 < iVar18 || (DAT_140e46c5c != 0)))) {
    iVar22 = iVar22 + -1;
    DAT_140e45d20 = iVar22;
  }
  if (iVar22 < 0) {
    DAT_140e45d20 = 0;
LAB_140108f90:
    if (iVar24 - 1U < 49999) {
      dVar34 = dVar29 - (double)(DAT_1407c7798 / 2) * DAT_140539e60;
      dVar30 = DAT_140539f10;
      if (DAT_140539f10 <= dVar34) {
        dVar30 = dVar34;
      }
      DAT_140e45d18 = iVar24 + (int)(dVar30 * _DAT_14053b148);
      if (DAT_140e45d18 < 0) {
        DAT_140e45d18 = 0;
      }
    }
  }
  else if (iVar22 == 0) goto LAB_140108f90;
  if (DAT_140e445fc - 0xb4U < 0x50) goto LAB_1401095d7;
  iVar22 = DAT_140e445c0 * 0x1e;
  if ((int)DAT_140e418c8 < 0x3c) {
    dVar30 = 0.0;
  }
  else {
    dVar30 = dVar29;
    if ((int)DAT_140e418c8 < 0x5a) {
      dVar30 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a3a0) * DAT_14053a798 *
                                     dVar11 * dVar32);
      dVar30 = dVar30 + 0.0;
    }
  }
  if (DAT_140e4464c == 0) {
    local_170 = iVar22 + 1;
    dStack_160._0_4_ = local_170;
    local_168._0_4_ = iVar22 + 2;
    local_178 = CONCAT44(local_178._4_4_,iVar22);
    iVar19 = FUN_1400c9580(DAT_140e44acc,0,7,4);
  }
  if (0 < (int)DAT_140e4464c) {
    if ((int)DAT_140e4464c < 0xc) {
      local_168._0_4_ = iVar22 + 5;
      local_170 = iVar22 + 4;
      local_178 = CONCAT44(local_178._4_4_,iVar22 + 3);
      iVar19 = FUN_1400c9580(DAT_140e4464c,0,6,3);
    }
    else {
      local_170 = iVar22 + 6;
      local_168._0_4_ = iVar22 + 7;
      local_178 = CONCAT44(local_178._4_4_,iVar22 + 5);
      iVar19 = FUN_1400c9580(DAT_140e44acc,0xc,7,3);
    }
  }
  if (0x7fffffff < DAT_140e4464c) {
    if ((int)DAT_140e4464c < -0xb) {
      local_170 = iVar22 + 0xb;
      local_168._0_4_ = iVar22 + 0xc;
      local_178 = CONCAT44(local_178._4_4_,iVar22 + 10);
      iVar19 = FUN_1400c9580(DAT_140e44acc,0xc,7,3);
    }
    else {
      local_168._0_4_ = iVar22 + 10;
      local_170 = iVar22 + 9;
      local_178 = CONCAT44(local_178._4_4_,iVar22 + 8);
      iVar19 = FUN_1400c9580(-DAT_140e4464c,0,6,3);
    }
  }
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_158._0_4_ = 0xff;
  dStack_160 = (double)uVar12;
  local_168 = (undefined1  [8])dVar29;
  lVar23 = (longlong)iVar19;
  local_170._0_2_ = 0;
  local_178._0_4_ = DAT_140e445dc;
  FUN_1400c8410((&DAT_140e44e70)[lVar23],0x28,7,(ulonglong)_DAT_140e445d8 & 0xffffffff);
  puVar20 = (undefined8 *)FUN_140135060(local_118,DAT_140e44acc,0x14);
  local_e8 = (FILE *)*puVar20;
  uVar37 = *(undefined4 *)(puVar20 + 1);
  uVar38 = (float)local_e8;
  if (DAT_140e45d18 < 0) {
    local_178._0_4_ = DAT_140e445dc + fVar36;
    local_130 = 0;
    local_138 = 1;
    local_140 = 0xff;
    local_150 = (undefined4)((ulonglong)local_e8 >> 0x20);
    local_158._0_4_ = (float)local_e8;
    dStack_160 = dVar29;
    local_168 = (undefined1  [8])((double)-DAT_140e45d18 / dVar2);
    local_170._0_2_ = 0;
    local_148 = uVar37;
    FUN_1400c8410(DAT_140e45d8c,0x50,7,(ulonglong)_DAT_140e445d8 & 0xffffffff);
    if (-1 < DAT_140e45d18) goto LAB_140109297;
LAB_1401092a3:
    dVar32 = (double)FUN_140332d90(((double)(int)DAT_140e44acc - 0.0) * _DAT_14053aa30 * dVar11 *
                                   dVar32);
    local_130 = 0;
    local_138 = 1;
    local_140 = 0x60 - (int)(dVar32 * DAT_14053b1a0);
    local_150 = local_e8._4_4_;
    local_158._0_4_ = uVar38;
    dStack_160 = (double)uVar12;
    local_168 = (undefined1  [8])dVar29;
    local_170._0_2_ = 0;
    local_178._0_4_ = DAT_140e445dc;
    local_148 = uVar37;
    FUN_1400c8410((&DAT_140e44e70)[lVar23],0x28,8,(ulonglong)_DAT_140e445d8 & 0xffffffff);
  }
  else {
LAB_140109297:
    if (49999 < DAT_140e45d18) goto LAB_1401092a3;
  }
  if (DAT_140e44654 != 0) {
    uVar21 = DAT_140e44acc & 0x80000001;
    if ((int)uVar21 < 0) {
      uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
    }
    if (uVar21 == 0) {
      local_130 = 0;
      local_138 = 1;
      local_140 = 0xff;
      local_148 = 0xff;
      local_150 = 0xff;
      local_158._0_4_ = 0xff;
      dStack_160 = (double)uVar12;
      local_168 = (undefined1  [8])dVar29;
      local_170._0_2_ = 0;
      local_178._0_4_ = DAT_140e445dc;
      FUN_1400c8410(*(undefined4 *)(&DAT_140e44eac + lVar23 * 4),0x28,7,
                    (ulonglong)_DAT_140e445d8 & 0xffffffff);
    }
  }
  puVar20 = DAT_140e45d28;
  if ((DAT_140e445f0 != 0.0) && (DAT_140e44644 == 0)) {
    uVar21 = DAT_140e44acc & 0x80000001;
    if ((int)uVar21 < 0) {
      uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
    }
    if (uVar21 == 0) {
      uVar13 = DAT_140e445dc;
      uVar38 = DAT_140e445d8;
      uVar37 = (&DAT_140e44e70)[lVar23];
      if (DAT_140e45d1c < 0x1000) {
        puVar20 = (undefined8 *)_malloc_base(0x60);
        if (puVar20 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar26 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar20 + 0x14) = uVar38;
        *(undefined4 *)(puVar20 + 3) = uVar13;
        *(undefined4 *)((longlong)puVar20 + 0x1c) = uVar38;
        *(undefined4 *)(puVar20 + 4) = uVar13;
        *puVar20 = 1;
        *(undefined4 *)(puVar20 + 1) = 5;
        *(undefined4 *)((longlong)puVar20 + 0xc) = uVar37;
        *(undefined4 *)(puVar20 + 2) = 0x27;
        *(undefined2 *)((longlong)puVar20 + 0x24) = 0;
        puVar20[5] = 0;
        puVar20[6] = 0x3ff0000000000000;
        puVar20[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar20 + 8) = 0x18;
        *(undefined4 *)((longlong)puVar20 + 0x44) = 0xff;
        *(undefined4 *)(puVar20 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar20 + 0x4c) = 0xff;
        puVar20[10] = 0x60;
        puVar20[0xb] = 0;
        if (bVar26) {
          DAT_140e45d78 = puVar20;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar20;
        }
      }
    }
  }
  DAT_140e45d28 = puVar20;
  local_130 = 0;
  local_138 = 1;
  local_140 = 0xff;
  local_148 = 0xff;
  local_150 = 0xff;
  local_170._0_2_ = (short)DAT_140e44acc * 0x3c0;
  local_158._0_4_ = 0xff;
  dStack_160._0_4_ = SUB84(dVar30,0);
  local_168 = (undefined1  [8])dVar30;
  dStack_160._4_4_ = (int)((ulonglong)dVar30 >> 0x20);
  local_178._0_4_ = DAT_140e445dc;
  FUN_1400c8410(DAT_140e44ea4,0x5a,7,(ulonglong)_DAT_140e445d8 & 0xffffffff);
  if (0x103 < DAT_140e445fc) {
    local_130 = 0;
    local_138 = 1;
    local_140 = 0xff;
    local_148 = 0;
    local_150 = 0;
    local_158 = CONCAT44(local_158._4_4_,0xff);
    dStack_160 = ((double)DAT_140e445fc - _DAT_14053a610) * DAT_140539ee0;
    local_168 = (undefined1  [8])dStack_160;
    local_170 = (uint)local_170._2_2_ << 0x10;
    local_178 = CONCAT44(local_178._4_4_,DAT_140e445dc);
    FUN_1400c8410(DAT_140e41a50,0x28,7,(ulonglong)_DAT_140e445d8 & 0xffffffff);
  }
LAB_1401095d7:
  if (0 < (int)DAT_140e44654) {
    DAT_140e44654 = DAT_140e44654 - 1;
  }
  if (0x7fffffff < DAT_140e44654) {
    DAT_140e44654 = 0;
  }
  return;
}


