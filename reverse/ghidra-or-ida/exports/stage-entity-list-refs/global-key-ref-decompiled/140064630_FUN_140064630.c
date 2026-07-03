// Function: FUN_140064630 @ 140064630
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140064630(undefined4 *param_1)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  longlong lVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined4 *puVar16;
  ushort uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  ushort uVar21;
  uint uVar22;
  int iVar23;
  longlong lVar24;
  uint uVar25;
  int *piVar26;
  ushort uVar27;
  int iVar28;
  bool bVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  double dVar36;
  float fVar37;
  longlong local_res20;
  uint in_stack_fffffffffffffe30;
  undefined8 in_stack_fffffffffffffe40;
  undefined4 uVar38;
  undefined8 uVar39;
  int local_178 [8];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined1 local_100 [192];
  
  lVar24 = DAT_140e45d80;
  iVar23 = DAT_140e44e6c;
  iVar28 = DAT_140e44308;
  uVar38 = (undefined4)((ulonglong)in_stack_fffffffffffffe40 >> 0x20);
  iVar13 = 0;
  uStack_150 = (ulonglong)(uint)uStack_150;
  lVar5 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x60)) {
      if (*(int *)(lVar5 + 4) == DAT_140e44308) {
        local_158 = *(undefined8 *)(lVar5 + 0x10);
        uStack_150 = *(ulonglong *)(lVar5 + 0x18);
        local_148 = *(undefined8 *)(lVar5 + 0x20);
        uStack_140 = *(undefined8 *)(lVar5 + 0x28);
      }
    }
  }
  dVar30 = (double)FUN_1403300b4((double)((float)param_1[0xd] - (float)param_1[0xb]),
                                 SUB84((double)((float)param_1[0xc] - (float)param_1[10]),0));
  dVar31 = DAT_14053aba0;
  iVar3 = param_1[6];
  dVar30 = dVar30 * DAT_14053aba0;
  if (((int)((ulonglong)local_158 >> 0x20) == 0x8c) && ((int)param_1[5] < 99)) {
    FUN_1400031d0(param_1);
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    stage_entity_spawn_candidate
              (0x137,99999999,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe30,DAT_14053a4f0,
               CONCAT44(uVar38,param_1[0x14]),1,0);
    lVar24 = DAT_140e45d80;
    iVar23 = DAT_140e44e6c;
    iVar28 = DAT_140e44308;
    param_1[5] = 99;
    DAT_140e419bc = 3;
    param_1[0x17] = 0;
  }
  if (DAT_140e418c8 == ((int)DAT_140e418c8 / 0x32) * 0x32) {
    if (param_1[6] == 0x125) {
      uVar22 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
      uVar18 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 2;
      uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 3;
      uVar22 = uVar22 * 0x800 ^ uVar22;
      uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 4;
      uVar19 = DAT_1407c7798 * 0x1e61 + DAT_140e418c8;
      uVar25 = (uVar19 >> 0x1e ^ uVar19) * 0x6c078965 + 1;
      uVar19 = uVar25 * 0x800 ^ uVar25;
      param_1[0xc] = (float)(((uVar18 >> 0xb ^ uVar22) >> 8 ^ uVar18 ^ uVar22) % 0x65 + 0x1cc);
      DAT_140e9fd10 = (uVar25 >> 0x1e ^ uVar25) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar22 = uVar18 >> 0xb ^ uVar19;
      DAT_140e9fd18 = uVar18;
    }
    else {
      if (param_1[6] != 0x126) goto LAB_140064a0e;
      uVar22 = DAT_1407c7798 * 0x4d + DAT_140e418c8;
      uVar22 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 1;
      uVar18 = (uVar22 >> 0x1e ^ uVar22) * 0x6c078965 + 2;
      uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 3;
      uVar22 = uVar22 * 0x800 ^ uVar22;
      uVar19 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 4;
      uVar18 = DAT_1407c7798 * 0x309 + DAT_140e418c8;
      uVar18 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
      param_1[0xc] = (float)(((uVar19 >> 0xb ^ uVar22) >> 8 ^ uVar22 ^ uVar19) % 0x65 + 0xa0);
      DAT_140e9fd10 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar18 = uVar18 * 0x800 ^ uVar18;
      uVar19 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar22 = uVar19 >> 0xb ^ uVar18;
      DAT_140e9fd18 = uVar19;
    }
    DAT_140e9fd1c = uVar22 >> 8 ^ uVar18 ^ uVar19;
    param_1[0xd] = (float)(DAT_140e9fd1c % 0x65 + 200);
  }
LAB_140064a0e:
  uVar11 = _UNK_14053bb28;
  uVar10 = _DAT_14053bb20;
  iVar20 = param_1[5];
  param_1[0x15] = 1;
  dVar7 = DAT_14053a020;
  if (iVar20 != 0) {
    if (iVar20 == 1) {
      uVar27 = *(ushort *)(param_1 + 0x10);
      iVar20 = ((int)dVar30 & 0xffffU) - (uint)uVar27;
      iVar13 = iVar20 + 0x10000;
      if (-0x8001 < iVar20) {
        iVar13 = iVar20;
      }
      iVar20 = iVar13 + -0x10000;
      if (iVar13 < 0x8001) {
        iVar20 = iVar13;
      }
      uVar17 = (ushort)(int)dVar30;
      if (iVar20 < 1) {
        uVar21 = uVar27;
        if ((iVar20 < 0) && (uVar21 = uVar27 - 0x200, -0x200 < iVar20)) {
          uVar21 = uVar17;
        }
      }
      else {
        uVar21 = uVar17;
        if (0x1ff < iVar20) {
          uVar21 = uVar27 + 0x200;
        }
      }
      *(ushort *)(param_1 + 0x10) = uVar21;
      dVar30 = (double)FUN_1403307c0();
      fVar35 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
      param_1[10] = fVar35;
      dVar30 = (double)FUN_140332d90();
      iVar13 = param_1[3];
      fVar37 = (float)(dVar30 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
      param_1[0xb] = fVar37;
      fVar12 = DAT_140e445dc;
      if (9 < iVar13) {
        fVar33 = fVar35 - DAT_14053ad0c;
        fVar34 = fVar37 - DAT_14053ad40;
        dVar30 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar34));
        iVar28 = (iVar13 + -10) % 0x708;
        if (param_1[6] == 0x126) {
          fVar33 = fVar35 + DAT_14053acfc;
          fVar34 = fVar37 - _DAT_14053ad44;
          dVar30 = (double)FUN_1403300b4((double)(fVar12 - fVar34));
        }
        uVar22 = DAT_14053ac2c;
        dVar32 = DAT_14053a0f8;
        dVar6 = DAT_140539ee0;
        uVar27 = (ushort)(int)(dVar30 * dVar31);
        local_178[0] = 0;
        piVar26 = local_178;
        local_178[1] = 0x1a4;
        local_178[2] = 0x366;
        local_res20 = 3;
        do {
          uVar38 = DAT_140e41a50;
          iVar23 = *piVar26;
          dVar36 = (double)((iVar28 - iVar23) + -0x1e) * dVar6 + dVar32;
          if (iVar28 == iVar23) {
            iVar13 = DAT_140e45d1c;
            puVar15 = DAT_140e45d28;
            if ((param_1[6] == 0x125) && (uVar1 = param_1[1], DAT_140e45d1c < 0x1000)) {
              puVar15 = (undefined8 *)_malloc_base(0x60);
              if (puVar15 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              *puVar15 = 1;
              *(undefined2 *)((longlong)puVar15 + 0x24) = 0;
              puVar15[5] = 0;
              puVar15[0xb] = 0;
              iVar13 = DAT_140e45d1c + 1;
              *(undefined4 *)(puVar15 + 1) = 0x31;
              bVar29 = DAT_140e45d78 == (undefined8 *)0x0;
              *(undefined4 *)((longlong)puVar15 + 0xc) = uVar38;
              *(undefined4 *)(puVar15 + 2) = 0x23;
              *(undefined4 *)((longlong)puVar15 + 0x14) = 0xc2b00000;
              *(undefined4 *)(puVar15 + 3) = 0xc2f00000;
              *(undefined4 *)((longlong)puVar15 + 0x1c) = 0xc2b00000;
              *(undefined4 *)(puVar15 + 4) = 0xc2f00000;
              puVar15[6] = 0x4014000000000000;
              puVar15[7] = 0x4014000000000000;
              *(undefined4 *)(puVar15 + 8) = 0x1e;
              *(undefined4 *)((longlong)puVar15 + 0x44) = 0xff;
              *(undefined4 *)(puVar15 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar15 + 0x4c) = 0xff;
              *(undefined4 *)(puVar15 + 10) = 0xff;
              *(undefined4 *)((longlong)puVar15 + 0x54) = uVar1;
              if (bVar29) {
                DAT_140e45d78 = puVar15;
              }
              DAT_140e45d1c = iVar13;
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar15;
              }
            }
            DAT_140e45d28 = puVar15;
            uVar38 = DAT_140e41a50;
            puVar15 = DAT_140e45d28;
            if ((param_1[6] == 0x126) && (uVar1 = param_1[1], iVar13 < 0x1000)) {
              puVar15 = (undefined8 *)_malloc_base(0x60);
              if (puVar15 == (undefined8 *)0x0) {
                MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
              }
              DAT_140e45d1c = DAT_140e45d1c + 1;
              bVar29 = DAT_140e45d78 == (undefined8 *)0x0;
              *puVar15 = 1;
              *(undefined4 *)(puVar15 + 1) = 0x31;
              *(undefined4 *)((longlong)puVar15 + 0xc) = uVar38;
              *(undefined4 *)(puVar15 + 2) = 0x23;
              *(undefined4 *)((longlong)puVar15 + 0x14) = 0x42a00000;
              *(undefined4 *)(puVar15 + 3) = 0xc2f40000;
              *(undefined4 *)((longlong)puVar15 + 0x1c) = 0x42a00000;
              *(undefined4 *)(puVar15 + 4) = 0xc2f40000;
              *(undefined2 *)((longlong)puVar15 + 0x24) = 0;
              puVar15[5] = 0;
              puVar15[6] = 0x4014000000000000;
              puVar15[7] = 0x4014000000000000;
              *(undefined4 *)(puVar15 + 8) = 0x1e;
              *(undefined4 *)((longlong)puVar15 + 0x44) = 0xff;
              *(undefined4 *)(puVar15 + 9) = 0xff;
              *(undefined4 *)((longlong)puVar15 + 0x4c) = 0xff;
              *(undefined4 *)(puVar15 + 10) = 0xff;
              *(undefined4 *)((longlong)puVar15 + 0x54) = uVar1;
              puVar15[0xb] = 0;
              if (bVar29) {
                DAT_140e45d78 = puVar15;
              }
              if (DAT_140e45d28 != (undefined8 *)0x0) {
                DAT_140e45d28[0xb] = puVar15;
              }
            }
            DAT_140e45d28 = puVar15;
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472c0);
            FUN_14018a340(DAT_140e472c0,1,1);
          }
          iVar13 = iVar23 + 0x1e;
          if (iVar28 == iVar13) {
            *(ushort *)((longlong)param_1 + 0x42) = uVar27;
LAB_140065281:
            if ((iVar28 < iVar23 + 0x46) || (iVar23 == -0x46)) {
              uVar18 = iVar28 - iVar13 & 0x80000003;
              if ((int)uVar18 < 0) {
                uVar18 = (uVar18 - 1 | 0xfffffffc) + 1;
              }
              if (uVar18 == 0) {
                sVar2 = *(short *)((longlong)param_1 + 0x42);
                iVar23 = 0;
                if (param_1[6] == 0x125) {
                  do {
                    in_stack_fffffffffffffe30 = uVar22;
                    FUN_14006c2f0(0xb,0,fVar33,fVar34,(short)iVar23 * 0x5dc + sVar2 + -3000,uVar22,
                                  dVar36,1,0);
                    iVar23 = iVar23 + 1;
                  } while (iVar23 < 5);
                }
                else {
                  do {
                    in_stack_fffffffffffffe30 = uVar22;
                    FUN_14006c2f0(10,0,fVar33,fVar34,(short)iVar23 * 0x5dc + sVar2 + -3000,uVar22,
                                  dVar36,1,0);
                    iVar23 = iVar23 + 1;
                  } while (iVar23 < 5);
                }
                uVar17 = *(ushort *)((longlong)param_1 + 0x42);
                iVar13 = ((int)(dVar30 * dVar31) & 0xffffU) - (uint)uVar17;
                iVar23 = iVar13 + 0x10000;
                if (-0x8001 < iVar13) {
                  iVar23 = iVar13;
                }
                iVar13 = iVar23 + -0x10000;
                if (iVar23 < 0x8001) {
                  iVar13 = iVar23;
                }
                if (iVar13 < 1) {
                  uVar21 = uVar17;
                  if ((iVar13 < 0) && (uVar21 = uVar17 - 0x140, -0x140 < iVar13)) {
                    uVar21 = uVar27;
                  }
                }
                else {
                  uVar21 = uVar27;
                  if (0x13f < iVar13) {
                    uVar21 = uVar17 + 0x140;
                  }
                }
                *(ushort *)((longlong)param_1 + 0x42) = uVar21;
                FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
                FUN_14018a340(DAT_140e472a4,1,1);
              }
            }
          }
          else if (iVar13 <= iVar28) goto LAB_140065281;
          dVar9 = DAT_14053a670;
          dVar8 = DAT_14053a3a0;
          dVar36 = DAT_140539d28;
          piVar26 = piVar26 + 1;
          local_res20 = local_res20 + -1;
        } while (local_res20 != 0);
        iVar23 = iVar28 + -0x3c;
        dVar31 = (double)iVar23 * _DAT_140539de0 + DAT_14053a070;
        if (((param_1[6] == 0x125) && (iVar28 - 0x3cU < 0x168)) &&
           (iVar23 == (iVar23 / 0x1c) * 0x1c)) {
          dVar30 = (double)FUN_140332d90(((double)(int)param_1[3] - DAT_14053a3a0) * DAT_14053a670 *
                                         dVar7 * DAT_140539d28);
          dVar30 = dVar30 * _DAT_14053ab88;
          iVar23 = 0;
          do {
            in_stack_fffffffffffffe30 = uVar22;
            FUN_14006c2f0(3,0,fVar33,fVar34,
                          (short)iVar23 * 2000 + (short)(int)dVar30 + uVar27 + -12000,uVar22,dVar31,
                          1,0);
            iVar23 = iVar23 + 1;
          } while (iVar23 < 0xd);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        iVar23 = 0;
        if (((param_1[6] == 0x126) && (uVar18 = iVar28 - 0x4a, uVar18 < 0x15a)) &&
           (uVar18 == ((int)uVar18 / 0x1c) * 0x1c)) {
          dVar30 = (double)FUN_140332d90(((double)(int)param_1[3] - dVar8) * dVar9 * dVar7 * dVar36)
          ;
          dVar30 = dVar30 * _DAT_14053b300;
          iVar13 = iVar23;
          do {
            in_stack_fffffffffffffe30 = uVar22;
            FUN_14006c2f0(2,0,fVar33,fVar34,
                          (short)iVar13 * 2000 + (short)(int)dVar30 + uVar27 + -12000,uVar22,dVar31,
                          1,0);
            iVar13 = iVar13 + 1;
          } while (iVar13 < 0xd);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        if (param_1[6] == 0x125) {
          iVar13 = iVar28 + -0x1e0;
          dVar31 = (double)iVar13 * _DAT_140539db0 + DAT_14053a090;
          if ((iVar28 - 0x1e0U < 0x186) && (iVar20 = iVar23, iVar13 == (iVar13 / 0x24) * 0x24)) {
            do {
              FUN_14006c2f0(5,0,fVar33,fVar34,(short)iVar20 * 400 + uVar27 + -2000,0,dVar31,1,0);
              iVar20 = iVar20 + 1;
              iVar13 = iVar23;
            } while (iVar20 < 0xb);
            do {
              FUN_14006c2f0(5,0,fVar33,fVar34,(short)((iVar13 + 0xfU & 0xffff) * 400) + uVar27,0,
                            dVar31,1,0);
              iVar13 = iVar13 + 1;
            } while (iVar13 < 0xb);
            do {
              in_stack_fffffffffffffe30 = 0;
              FUN_14006c2f0(5,0,fVar33,fVar34,(short)iVar23 * 400 + uVar27 + -10000,0,dVar31,1,0);
              iVar23 = iVar23 + 1;
            } while (iVar23 < 0xb);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
            FUN_14018a340(DAT_140e472a8,1,1);
          }
        }
        if (param_1[6] == 0x126) {
          iVar23 = iVar28 + -0x1e0;
          dVar31 = (double)FUN_140332d90(((double)iVar28 - _DAT_14053a738) * DAT_14053a930 * dVar7 *
                                         dVar36);
          dVar31 = dVar31 * DAT_140539f28;
          dVar30 = (double)iVar23 * _DAT_140539dd0 + DAT_14053a0b0;
          if (iVar28 == 0x1e0) {
            *(ushort *)((longlong)param_1 + 0x42) = uVar27;
            uVar17 = uVar27;
          }
          else {
            uVar17 = *(ushort *)((longlong)param_1 + 0x42);
            if ((iVar28 < 0x1e0) || (0x365 < iVar28)) goto LAB_140065928;
          }
          if (iVar23 == (iVar23 / 6 + (iVar23 >> 0x1f) +
                        (int)(((longlong)iVar23 / 6 + ((longlong)iVar23 >> 0x3f) & 0xffffffffU) >>
                             0x1f)) * 6) {
            iVar23 = 0;
            do {
              in_stack_fffffffffffffe30 = 0;
              FUN_14006c2f0(8,0,fVar33,fVar34,
                            (short)iVar23 * 0x2492 + (short)iVar28 * 0xf0 + uVar17 + 0x3e00,0,
                            dVar31 + 0.0 + dVar30,1,0);
              iVar23 = iVar23 + 1;
            } while (iVar23 < 7);
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
LAB_140065928:
        iVar23 = 0;
        uVar18 = iVar28 - 0x3a2;
        sVar4 = (short)((int)(uVar18 + ((int)uVar18 >> 0x1f & 0xfU)) >> 4);
        sVar2 = -0x3c - sVar4;
        if (param_1[6] != 0x125) {
          sVar2 = sVar4 + 0x3c;
        }
        dVar31 = (double)(int)uVar18 * DAT_140539dc8 + DAT_14053a0d0;
        if (iVar28 == 0x3a2) {
          *(ushort *)((longlong)param_1 + 0x42) = uVar27;
        }
        else {
          uVar27 = *(ushort *)((longlong)param_1 + 0x42);
        }
        if ((param_1[6] == 0x125) && (iVar28 - 0x3a2U < 0x35c)) {
          uVar18 = uVar18 & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          if (((int)uVar18 < 0x12) &&
             (iVar13 = iVar23,
             uVar18 == ((int)uVar18 / 3 + ((int)uVar18 >> 0x1f) +
                       (int)(((longlong)(int)uVar18 / 3 + ((longlong)(int)uVar18 >> 0x3f) &
                             0xffffffffU) >> 0x1f)) * 3)) {
            do {
              in_stack_fffffffffffffe30 = uVar22;
              FUN_14006c2f0(0xb,0,fVar33,fVar34,(short)iVar13 * 0x13b1 + uVar27,uVar22,dVar31,1,0);
              iVar13 = iVar13 + 1;
            } while (iVar13 < 0xd);
            FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            uVar27 = *(ushort *)((longlong)param_1 + 0x42);
          }
        }
        if ((param_1[6] == 0x126) && (iVar28 - 0x3b2U < 0x34c)) {
          uVar18 = iVar28 - 0x3b2U & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          if (((int)uVar18 < 0x12) &&
             (uVar18 == ((int)uVar18 / 3 + ((int)uVar18 >> 0x1f) +
                        (int)(((longlong)(int)uVar18 / 3 + ((longlong)(int)uVar18 >> 0x3f) &
                              0xffffffffU) >> 0x1f)) * 3)) {
            do {
              in_stack_fffffffffffffe30 = uVar22;
              FUN_14006c2f0(10,0,fVar33,fVar34,(short)iVar23 * 0x13b1 + uVar27,uVar22,dVar31,1,0);
              iVar23 = iVar23 + 1;
            } while (iVar23 < 0xd);
            FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar2;
        lVar24 = DAT_140e45d80;
        iVar28 = DAT_140e44308;
        iVar23 = DAT_140e44e6c;
      }
      iVar13 = param_1[7];
      if ((iVar13 < uStack_150._4_4_) && (lVar5 = lVar24, 0 < iVar23)) {
        for (; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x60)) {
          if (*(int *)(lVar5 + 4) == iVar28) {
            *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) - (uStack_150._4_4_ - iVar13);
          }
        }
      }
      iVar13 = param_1[7];
      if (uStack_150._4_4_ < iVar13) {
        param_1[7] = uStack_150._4_4_;
        iVar13 = uStack_150._4_4_;
      }
      if ((iVar13 < 1) && (0 < iVar23)) {
        for (; lVar24 != 0; lVar24 = *(longlong *)(lVar24 + 0x60)) {
          if (*(int *)(lVar24 + 4) == iVar28) {
            *(int *)(lVar24 + 0x1c) = *(int *)(lVar24 + 0x1c) - uStack_150._4_4_;
          }
        }
      }
      lVar24 = 0x14c;
      if (iVar3 != 0x126) {
        lVar24 = 0x148;
      }
      in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
      FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,7,param_1[10],
                    param_1[0xb],in_stack_fffffffffffffe30,uVar10,uVar11,0xff,0xff,0xff,0xff,1,0);
      param_1[0x15] = 0;
      goto LAB_140066267;
    }
    if (iVar20 != 99) goto LAB_140066267;
    iVar28 = param_1[3];
    if (0x59 < iVar28) {
      iVar13 = 0xff;
    }
    iVar23 = 0;
    if (iVar28 < 0x5a) {
LAB_140064b1e:
      if (iVar28 < 0x8c) {
        iVar23 = iVar13;
      }
      puVar15 = DAT_140e45d28;
      if (iVar28 == 1) {
        uVar38 = param_1[0xb];
        uVar1 = param_1[10];
        if (DAT_140e45d1c < 0x1000) {
          puVar15 = (undefined8 *)_malloc_base(0x60);
          if (puVar15 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar29 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar15 + 0x14) = uVar1;
          *(undefined4 *)(puVar15 + 3) = uVar38;
          *(undefined4 *)((longlong)puVar15 + 0x1c) = uVar1;
          *(undefined4 *)(puVar15 + 4) = uVar38;
          *puVar15 = 1;
          puVar15[1] = 0x36;
          *(undefined4 *)(puVar15 + 2) = 0x28;
          *(undefined2 *)((longlong)puVar15 + 0x24) = 0;
          puVar15[5] = 0;
          puVar15[6] = 0x3ff0000000000000;
          puVar15[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar15 + 8) = 0;
          *(undefined4 *)((longlong)puVar15 + 0x44) = 0xff;
          *(undefined4 *)(puVar15 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar15 + 0x4c) = 0xff;
          puVar15[10] = 0xff;
          puVar15[0xb] = 0;
          if (bVar29) {
            DAT_140e45d78 = puVar15;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar15;
          }
        }
      }
    }
    else if (iVar28 < 100) {
      dVar31 = (double)FUN_140332d90(((double)iVar28 - DAT_14053a430) * DAT_14053a9d8 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar23 = (int)(dVar31 * DAT_14053a5f8);
      puVar15 = DAT_140e45d28;
    }
    else {
      if (0x8b < iVar28) goto LAB_140064b1e;
      dVar31 = (double)FUN_140332d90(((double)iVar28 - DAT_14053a3a0) * DAT_14053a6d8 *
                                     DAT_14053a020 * DAT_140539d28);
      puVar15 = DAT_140e45d28;
      if (iVar28 < 0x8c) {
        iVar23 = (int)(dVar31 * DAT_14053a5f8);
      }
    }
    DAT_140e45d28 = puVar15;
    iVar28 = param_1[3];
    if (iVar28 < 0x5a) {
      FUN_14007ac00(param_1);
      iVar28 = param_1[3];
      param_1[0xb] = (float)iVar28 * _DAT_140539ccc + (float)param_1[0xb];
    }
    puVar15 = DAT_140e45d28;
    if (iVar28 == 0x5a) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a0);
      FUN_14018a340(DAT_140e472a0,1,1);
      uVar38 = param_1[0xb];
      uVar1 = param_1[10];
      puVar15 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar15 = (undefined8 *)_malloc_base(0x60);
        if (puVar15 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar29 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar15 + 0x14) = uVar1;
        *(undefined4 *)(puVar15 + 3) = uVar38;
        *(undefined4 *)((longlong)puVar15 + 0x1c) = uVar1;
        *(undefined4 *)(puVar15 + 4) = uVar38;
        *puVar15 = 1;
        puVar15[1] = 0x11;
        *(undefined4 *)(puVar15 + 2) = 0x28;
        *(undefined2 *)((longlong)puVar15 + 0x24) = 0;
        puVar15[5] = 0;
        puVar15[6] = 0x3ff0000000000000;
        puVar15[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar15 + 8) = 0;
        *(undefined4 *)((longlong)puVar15 + 0x44) = 0xff;
        *(undefined4 *)(puVar15 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar15 + 0x4c) = 0xff;
        puVar15[10] = 0xff;
        puVar15[0xb] = 0;
        if (bVar29) {
          DAT_140e45d78 = puVar15;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar15;
        }
      }
    }
    DAT_140e45d28 = puVar15;
    uVar38 = DAT_140e41ab8;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    _DAT_140e46dc8 = _DAT_140e46dc8 + 1;
    bVar29 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar38;
    puVar16[1] = 0x4e;
    *(undefined8 *)(puVar16 + 2) = 5;
    puVar16[4] = 0;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = iVar23;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar29) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    DAT_140e46c88 = puVar16;
    if ((int)param_1[3] < 100) {
      lVar24 = 0x14c;
      if (iVar3 != 0x126) {
        lVar24 = 0x148;
      }
      in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
      FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,7,param_1[10],
                    param_1[0xb],in_stack_fffffffffffffe30,uVar10,uVar11,0xff,0xff,0xff,0xff,1,0);
    }
    if (param_1[3] == 0x8c) {
      *param_1 = 0;
    }
    goto LAB_140066267;
  }
  iVar28 = param_1[3];
  puVar15 = (undefined8 *)FUN_140135060(local_100,iVar28,0x14);
  dVar6 = DAT_14053a798;
  dVar7 = DAT_14053a5f8;
  dVar30 = DAT_14053a020;
  dVar31 = DAT_140539d28;
  uVar39 = *puVar15;
  uVar38 = *(undefined4 *)(puVar15 + 1);
  iVar23 = 0xff;
  if (iVar28 < 0x96) {
    if (iVar28 < 0x5a) {
      iVar13 = 0;
      iVar14 = (iVar28 >> 0x1f & 0xffffff01U) + 0xff;
      if (-1 < iVar28) {
        dVar32 = (double)FUN_140332d90(((double)iVar28 - 0.0) * DAT_14053a558 * DAT_14053a020 *
                                       DAT_140539d28);
        iVar14 = (int)(dVar32 * dVar7);
      }
      iVar20 = iVar13;
      if (iVar28 < 0x78) {
        iVar20 = iVar14;
      }
    }
    else {
      dVar32 = (double)FUN_140332d90(((double)iVar28 - DAT_14053a430) * DAT_14053a798 *
                                     DAT_14053a020 * DAT_140539d28);
      iVar13 = (int)(dVar32 * dVar7);
      if (iVar28 < 0x78) {
        dVar32 = (double)FUN_140332d90(((double)iVar28 - DAT_14053a3a0) * dVar6 * dVar30 * dVar31);
        iVar20 = 0;
        if (iVar28 < 0x78) {
          iVar20 = (int)(dVar32 * dVar7);
        }
        if (iVar28 == 0x5a) {
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
          FUN_14018a340(DAT_140e472bc,1,1);
        }
      }
      else {
        iVar20 = 0;
      }
    }
    lVar24 = 0x13c;
    if (iVar3 != 0x126) {
      lVar24 = 0x138;
    }
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,7,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,0xff,0xff,0xff,iVar13,1,0,uVar39);
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,8,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,(int)uVar39,
                  (int)((ulonglong)uVar39 >> 0x20),uVar38,iVar20,1,0);
  }
  uVar22 = param_1[3];
  if (uVar22 - 0x78 < 0x5a) {
    iVar28 = 0;
    if ((int)uVar22 < 0x96) {
LAB_140065e6f:
      iVar13 = 0;
      if ((int)uVar22 < 0xd2) {
        iVar13 = iVar28;
      }
      iVar20 = 0;
      if (0x77 < (int)uVar22) {
        iVar20 = 0xff;
        if (0x95 < (int)uVar22) {
          if (uVar22 < 0xb4) goto LAB_140066013;
          goto LAB_140066040;
        }
        dVar32 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a4a0) * dVar6 * dVar30 *
                                       dVar31);
        iVar20 = (int)(dVar32 * dVar7);
      }
      iVar28 = 0;
      if ((int)uVar22 < 0xb4) {
        iVar28 = iVar20;
      }
    }
    else if ((int)uVar22 < 0xb4) {
      dVar32 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a510) * dVar6 * dVar30 * dVar31
                                    );
      iVar13 = (int)(dVar32 * dVar7);
LAB_140066013:
      dVar32 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a4a0) * dVar6 * dVar30 * dVar31
                                    );
      iVar20 = (int)(dVar32 * dVar7);
LAB_140066040:
      iVar28 = 0;
      if ((int)uVar22 < 0xb4) {
        iVar28 = iVar20;
      }
      if (uVar22 == 0x96) {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
      }
    }
    else {
      iVar28 = 0xff;
      if (0xd1 < (int)uVar22) goto LAB_140065e6f;
      dVar32 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a510) * dVar6 * dVar30 * dVar31
                                    );
      iVar28 = 0;
      iVar13 = (int)(dVar32 * dVar7);
    }
    lVar24 = 0x144;
    if (iVar3 != 0x126) {
      lVar24 = 0x140;
    }
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,7,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,0xff,0xff,0xff,iVar13,1,0);
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,8,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,(int)uVar39,
                  (int)((ulonglong)uVar39 >> 0x20),uVar38,iVar28,1,0);
  }
  uVar22 = param_1[3];
  if (0xb3 < (int)uVar22) {
    if ((int)uVar22 < 0xd2) {
      iVar23 = 0;
      dVar31 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a548) * dVar6 * dVar30 * dVar31
                                    );
LAB_14006612e:
      iVar28 = (int)(dVar31 * dVar7);
    }
    else {
      if ((int)uVar22 < 0xf0) {
        dVar32 = (double)FUN_140332d90(((double)(int)uVar22 - _DAT_14053a5b0) * dVar6 * dVar30 *
                                       dVar31);
        iVar23 = (int)(dVar32 * dVar7);
LAB_14006610b:
        dVar31 = (double)FUN_140332d90(((double)(int)uVar22 - DAT_14053a548) * dVar6 * dVar30 *
                                       dVar31);
        goto LAB_14006612e;
      }
      iVar28 = 0xff;
      if (uVar22 < 0xf0) goto LAB_14006610b;
    }
    iVar13 = 0;
    if (uVar22 < 0xf0) {
      iVar13 = iVar28;
    }
    if (uVar22 == 0xd2) {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
      FUN_14018a340(DAT_140e472bc,1,1);
    }
    lVar24 = 0x14c;
    if (iVar3 != 0x126) {
      lVar24 = 0x148;
    }
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,7,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,0xff,0xff,0xff,iVar23,1,0);
    in_stack_fffffffffffffe30 = in_stack_fffffffffffffe30 & 0xffff0000;
    FUN_1400c8410(*(undefined4 *)((longlong)&DAT_140e44910 + lVar24),0x1e,8,param_1[10],param_1[0xb]
                  ,in_stack_fffffffffffffe30,uVar10,uVar11,(int)uVar39,
                  (int)((ulonglong)uVar39 >> 0x20),uVar38,iVar13,1,0);
  }
  if (param_1[3] == 0xfa) {
    param_1[5] = param_1[5] + 1;
    param_1[8] = (undefined4)local_148;
    param_1[7] = uStack_150._4_4_;
    *(undefined8 *)(param_1 + 0x12) = 0x3fd3333333333333;
    param_1[3] = 0;
  }
LAB_140066267:
  if (param_1[0x15] == 0) {
    if (param_1[0x17] == 0) {
      if (DAT_140e44600 + 100U < 0x65) {
        return;
      }
      stage_entity_spawn_candidate
                (0x136,99999999,1,0,0,in_stack_fffffffffffffe30 & 0xffff0000,uVar10,0x14,0,
                 param_1[1]);
      param_1[0x17] = 1;
    }
    else if (param_1[0x17] != 1) {
      return;
    }
    param_1[0x15] = 1;
    if (DAT_140e44654 < 0x3d) {
      param_1[0x17] = 0;
      param_1[0x15] = 0;
    }
  }
  return;
}


