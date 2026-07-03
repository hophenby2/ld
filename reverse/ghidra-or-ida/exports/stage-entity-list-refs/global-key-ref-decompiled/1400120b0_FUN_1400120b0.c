// Function: FUN_1400120b0 @ 1400120b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400120b0(undefined4 *param_1)

{
  float fVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  ushort uVar15;
  uint uVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  int local_res8;
  undefined4 in_stack_fffffffffffffea8;
  undefined2 uVar25;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 in_stack_fffffffffffffeb0;
  undefined4 uVar26;
  undefined2 uVar27;
  undefined8 in_stack_fffffffffffffec0;
  undefined8 uVar28;
  int iStack_f4;
  int iStack_ec;
  undefined8 uStack_e0;
  
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffeb0 >> 0x10);
  uVar25 = (undefined2)((uint)in_stack_fffffffffffffea8 >> 0x10);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  local_res8 = 0;
  iStack_ec = 0;
  if ((0 < DAT_140e44e6c) && (lVar6 = DAT_140e45d80, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar6 + 4) == DAT_140e44308) {
        iStack_f4 = *(int *)(lVar6 + 0x14);
        iStack_ec = *(int *)(lVar6 + 0x1c);
        uStack_e0 = *(undefined8 *)(lVar6 + 0x28);
      }
      lVar6 = *(longlong *)(lVar6 + 0x60);
    } while (lVar6 != 0);
    local_res8 = iStack_ec;
  }
  uVar11 = *(ushort *)(param_1 + 0x10);
  dVar18 = (double)FUN_1403307c0();
  fVar22 = (float)(dVar18 * DAT_14053a3d0) + (float)param_1[10];
  dVar18 = (double)FUN_140332d90();
  fVar21 = (float)(dVar18 * DAT_14053a3d0) + (float)param_1[0xb];
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar3 = _UNK_14053bb28;
  dVar18 = _DAT_14053bb20;
  uVar26 = DAT_14053ac2c;
  uVar16 = (uint)(dVar19 * DAT_14053aba0);
  param_1[0xb] = uStack_e0._4_4_ + (float)param_1[0xd];
  param_1[10] = (float)uStack_e0 + (float)param_1[0xc];
  uVar15 = (ushort)uVar16;
  if (param_1[5] == 0) {
    if (iStack_f4 == 1) {
      param_1[3] = 0;
      param_1[5] = 1;
      goto LAB_1400122a8;
    }
    if (iStack_f4 != 2) goto LAB_1400122a3;
    param_1[3] = 0;
    param_1[5] = 2;
    iVar9 = DAT_140e419b8;
  }
  else {
LAB_1400122a3:
    iVar9 = DAT_140e419b8;
    if (param_1[5] == 1) {
LAB_1400122a8:
      iVar9 = DAT_140e419b8;
      iVar17 = (int)param_1[3] % 1000;
      if (iVar17 < 400) {
        iVar13 = 1;
        if (DAT_140e419b8 == 0) {
          iVar13 = 100;
        }
        else if (DAT_140e419b8 == 1) {
          iVar13 = 0x32;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          iVar13 = 0x28;
        }
        else if (DAT_140e419b8 == 4) {
          iVar13 = 0x1e;
        }
        uVar10 = 1;
        if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) && (DAT_140e419b8 != 2)) &&
           ((DAT_140e419b8 == 3 || (DAT_140e419b8 == 4)))) {
          uVar10 = 3;
        }
        dVar19 = DAT_14053a088;
        if (((DAT_140e419b8 != 0) && (dVar19 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
           ((dVar19 = DAT_14053a0f8, DAT_140e419b8 != 2 &&
            ((dVar19 = DAT_14053a118, DAT_140e419b8 != 3 && (dVar19 = dVar18, DAT_140e419b8 == 4))))
           )) {
          dVar19 = DAT_14053a158;
        }
        uVar4 = uVar15 - uVar11;
        uVar8 = (uint)uVar4;
        if (0x8000 < uVar4) {
          uVar8 = 0x10000 - uVar4;
        }
        iVar7 = (uVar16 & 0xffff) - (uint)uVar11;
        iVar12 = (int)uVar8 / 10 + 0x30;
        iVar5 = iVar7 + 0x10000;
        if (-0x8001 < iVar7) {
          iVar5 = iVar7;
        }
        iVar7 = iVar5 + -0x10000;
        if (iVar5 < 0x8001) {
          iVar7 = iVar5;
        }
        if (iVar7 < 1) {
          uVar4 = uVar11;
          if ((iVar7 < 0) && (uVar4 = uVar11 - (short)iVar12, -iVar12 < iVar7)) {
            uVar4 = uVar15;
          }
        }
        else {
          uVar4 = uVar15;
          if (iVar12 <= iVar7) {
            uVar4 = uVar11 + (short)iVar12;
          }
        }
        *(ushort *)(param_1 + 0x10) = uVar4;
        if ((0x1d < iVar17) &&
           (uVar2 = (longlong)(iVar17 + -0x1e) % (longlong)iVar13, (int)uVar2 == 0)) {
          uVar28 = CONCAT44(uVar23,1);
          uVar23 = CONCAT22(uVar25,uVar4);
          FUN_1400709b0(7,uVar2 & 0xffffffff,fVar22,fVar21,uVar23,uVar26,dVar19,uVar28,uVar10,0x960,
                        0);
          uVar28 = CONCAT44((int)((ulonglong)uVar28 >> 0x20),1);
          uVar24 = CONCAT22((short)((uint)uVar23 >> 0x10),*(undefined2 *)(param_1 + 0x10));
          uVar23 = uVar26;
          FUN_1400709b0(7,0,fVar22,fVar21,uVar24,uVar26,dVar19 + DAT_140539ee0,uVar28,uVar10,0x960,0
                       );
          uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          uVar25 = (undefined2)((uint)uVar24 >> 0x10);
          uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar9 = DAT_140e419b8;
        }
      }
      else if (iVar17 < 700) {
        iVar13 = 1;
        if (DAT_140e419b8 == 0) {
          iVar13 = 4;
        }
        else if (DAT_140e419b8 == 1) {
          iVar13 = 3;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar13 = 2;
        }
        iVar5 = 1;
        if (DAT_140e419b8 != 0) {
          if (DAT_140e419b8 == 1) {
            iVar5 = 2;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            iVar5 = 3;
          }
          else if (DAT_140e419b8 == 4) {
            iVar5 = 4;
          }
        }
        sVar14 = 1;
        if (DAT_140e419b8 == 0) {
          sVar14 = 700;
        }
        else if (DAT_140e419b8 == 1) {
          sVar14 = 0x2ee;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          sVar14 = 800;
        }
        dVar19 = DAT_140539fc8;
        if ((((DAT_140e419b8 != 0) && (dVar19 = DAT_14053a018, DAT_140e419b8 != 1)) &&
            (dVar19 = DAT_14053a070, DAT_140e419b8 != 2)) &&
           ((dVar19 = DAT_14053a018, DAT_140e419b8 != 3 && (dVar19 = dVar18, DAT_140e419b8 == 4))))
        {
          dVar19 = DAT_14053a040;
        }
        if (iVar17 < 0x1af) {
          uVar11 = *(ushort *)(param_1 + 0x10);
          if ((float)param_1[0xc] <= 0.0) {
            uVar4 = 0x6000;
            iVar7 = -(uint)uVar11;
            iVar12 = iVar7 + 0x6000;
            iVar7 = iVar7 + 0x16000;
            if (-0x8001 < iVar12) {
              iVar7 = iVar12;
            }
            iVar12 = iVar7 + -0x10000;
            if (iVar7 < 0x8001) {
              iVar12 = iVar7;
            }
            if (iVar12 < 1) goto LAB_140012651;
            if (1099 < iVar12) goto LAB_14001264b;
            uVar11 = 0x6000;
          }
          else {
            uVar4 = 0xe000;
            iVar7 = -(uint)uVar11;
            iVar12 = iVar7 + 0xe000;
            iVar7 = iVar7 + 0x1e000;
            if (-0x8001 < iVar12) {
              iVar7 = iVar12;
            }
            iVar12 = iVar7 + -0x10000;
            if (iVar7 < 0x8001) {
              iVar12 = iVar7;
            }
            if (iVar12 < 1) {
LAB_140012651:
              if ((iVar12 < 0) && (uVar11 = uVar11 - 0x44c, -0x44c < iVar12)) {
                uVar11 = uVar4;
              }
            }
            else if (iVar12 < 0x44c) {
              uVar11 = 0xe000;
            }
            else {
LAB_14001264b:
              uVar11 = uVar11 + 0x44c;
            }
          }
        }
        else if (iVar17 < 0x23a) {
          uVar11 = sVar14 + uVar11;
        }
        else {
          uVar11 = uVar11 - sVar14;
        }
        *(ushort *)(param_1 + 0x10) = uVar11;
        if ((iVar17 - 0x1aeU < 0x10e) && ((int)(iVar17 - 0x1aeU) % iVar13 == 0)) {
          iVar9 = iVar5 * 0x22b8 + -0x22b8;
          uVar28 = CONCAT44(uVar23,1);
          uVar10 = CONCAT22(uVar25,uVar11);
          uVar23 = uVar26;
          FUN_1400709b0(0xd,1,fVar22,fVar21,uVar10,uVar26,dVar19,uVar28,iVar5,iVar9,0);
          uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          uVar25 = (undefined2)((uint)uVar10 >> 0x10);
          uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
          if (2 < DAT_140e419b8) {
            uVar28 = CONCAT44(uVar23,1);
            uVar10 = CONCAT22(uVar25,*(undefined2 *)(param_1 + 0x10));
            uVar23 = uVar26;
            FUN_1400709b0(0xd,1,fVar22,fVar21,uVar10,uVar26,dVar19 + DAT_140539f90,uVar28,iVar5,
                          iVar9,0);
            uVar27 = (undefined2)((uint)uVar23 >> 0x10);
            uVar25 = (undefined2)((uint)uVar10 >> 0x10);
            uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar9 = DAT_140e419b8;
        }
      }
      else {
        iVar13 = 1;
        if (DAT_140e419b8 == 0) {
          iVar13 = 0x50;
        }
        else if (DAT_140e419b8 == 1) {
          iVar13 = 0x2d;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          iVar13 = 0x28;
        }
        uVar10 = 1;
        if (DAT_140e419b8 == 0) {
          uVar10 = 3;
        }
        else if (DAT_140e419b8 == 1) {
          uVar10 = 5;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          uVar10 = 7;
        }
        else if (DAT_140e419b8 == 4) {
          uVar10 = 9;
        }
        sVar14 = 1;
        if (DAT_140e419b8 == 0) {
          sVar14 = 4;
        }
        else if (DAT_140e419b8 == 1) {
          sVar14 = 6;
        }
        else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
          sVar14 = 8;
        }
        iVar5 = (iVar17 + -0x2da) / iVar13;
        sVar14 = (short)iVar5 * sVar14 + 0x1e;
        dVar19 = DAT_14053a070;
        if ((((DAT_140e419b8 != 0) && (dVar19 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
            (dVar19 = DAT_14053a138, DAT_140e419b8 != 2)) &&
           ((DAT_140e419b8 != 3 && (dVar19 = dVar18, DAT_140e419b8 == 4)))) {
          dVar19 = DAT_14053a178;
        }
        iVar7 = (iVar17 + -0x2da) % iVar13;
        dVar19 = (double)iVar5 * DAT_140539f00 + dVar19 + (double)iVar7 * DAT_140539e60;
        if (iVar17 < 0x2db) {
          uVar11 = *(ushort *)(param_1 + 0x10);
          iVar12 = (uVar16 & 0xffff) - (uint)uVar11;
          iVar5 = iVar12 + 0x10000;
          if (-0x8001 < iVar12) {
            iVar5 = iVar12;
          }
          iVar12 = iVar5 + -0x10000;
          if (iVar5 < 0x8001) {
            iVar12 = iVar5;
          }
          if (iVar12 < 1) {
            uVar4 = uVar11;
            if ((iVar12 < 0) && (uVar4 = uVar11 - 0x44c, -0x44c < iVar12)) {
              uVar4 = uVar15;
            }
          }
          else {
            uVar4 = uVar15;
            if (1099 < iVar12) {
              uVar4 = uVar11 + 0x44c;
            }
          }
          *(ushort *)(param_1 + 0x10) = uVar4;
        }
        if ((iVar17 - 0x2daU < 0x10e) && (iVar7 == 0)) {
          dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar21),
                                         SUB84((double)(DAT_140e445d8 - fVar22),0));
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar20 * DAT_14053aba0);
LAB_14001296f:
          uVar8 = (iVar17 + -0x2da) % iVar13 & 0x80000003;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
          }
          if (uVar8 != 0) goto LAB_140012a5b;
          uVar28 = CONCAT44(uVar23,1);
          uVar24 = CONCAT22(uVar25,*(undefined2 *)((longlong)param_1 + 0x42));
          uVar23 = uVar26;
          FUN_1400709b0(6,0,fVar22,fVar21,uVar24,uVar26,dVar19,uVar28,uVar10,22000,0);
          uVar27 = (undefined2)((uint)uVar23 >> 0x10);
          uVar25 = (undefined2)((uint)uVar24 >> 0x10);
          uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
          if (2 < DAT_140e419b8) {
            uVar28 = CONCAT44(uVar23,1);
            uVar24 = CONCAT22(uVar25,*(undefined2 *)((longlong)param_1 + 0x42));
            uVar23 = uVar26;
            FUN_1400709b0(6,0,fVar22,fVar21,uVar24,uVar26,dVar19 + DAT_140539fa8,uVar28,uVar10,22000
                          ,0);
            uVar27 = (undefined2)((uint)uVar23 >> 0x10);
            uVar25 = (undefined2)((uint)uVar24 >> 0x10);
            uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          iVar9 = DAT_140e419b8;
        }
        else {
          if ((iVar17 - 0x2daU < 0x10e) && ((iVar17 + -0x2da) % iVar13 < 0x28)) goto LAB_14001296f;
LAB_140012a5b:
          if (iVar17 < 0x2da) goto LAB_140012a94;
        }
        if (iVar13 <= (iVar17 + -0x2da) % (iVar13 * 2)) {
          sVar14 = -sVar14;
        }
        *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar14;
      }
LAB_140012a94:
      if (iStack_f4 == 2) {
        param_1[5] = param_1[5] + 1;
        param_1[3] = 0;
      }
    }
  }
  if (param_1[5] == 2) {
    if (iStack_f4 != 3) goto LAB_140012cf0;
    param_1[3] = 0;
    param_1[5] = 3;
  }
  else if (param_1[5] != 3) goto LAB_140012cf0;
  iVar13 = 0x2b2;
  iVar17 = (int)param_1[3] % 0x4b0;
  if (0x2b1 < iVar17) {
    iVar5 = 1;
    if (iVar9 == 0) {
      iVar5 = 0x8c;
    }
    else if (iVar9 == 1) {
      iVar5 = 100;
    }
    else if ((iVar9 == 2) || (iVar9 == 3)) {
      iVar5 = 0x5a;
    }
    else if (iVar9 == 4) {
      iVar5 = 0x46;
    }
    uVar10 = 1;
    if (iVar9 == 0) {
      uVar10 = 3;
    }
    else if (iVar9 == 1) {
      uVar10 = 5;
    }
    else if (((iVar9 == 2) || (iVar9 == 3)) || (iVar9 == 4)) {
      uVar10 = 7;
    }
    dVar19 = DAT_14053a160;
    if (((iVar9 != 0) && (dVar19 = DAT_14053a190, iVar9 != 1)) &&
       ((iVar9 == 2 || ((iVar9 == 3 || (dVar19 = dVar18, iVar9 == 4)))))) {
      dVar19 = DAT_14053a1b8;
    }
    fVar1 = (float)param_1[0xc];
    if ((((0.0 <= fVar1) || (iVar13 = iVar5 + 0x2b2, iVar13 <= iVar17)) && (iVar17 < 0x460)) &&
       ((iVar17 - iVar13) % (iVar5 * 2) == 0)) {
      FUN_1400709b0((0.0 <= fVar1) + '\x02',(fVar1 < 0.0) + '\x1a',fVar22,fVar21,
                    CONCAT22(uVar25,uVar15),uVar26,dVar19,CONCAT44(uVar23,1),uVar10,20000,0);
      uVar27 = (undefined2)((uint)uVar26 >> 0x10);
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
  }
  uVar11 = *(ushort *)(param_1 + 0x10);
  uVar4 = uVar15 - uVar11;
  uVar8 = (uint)uVar4;
  if (0x8000 < uVar4) {
    uVar8 = 0x10000 - uVar4;
  }
  iVar17 = (uVar16 & 0xffff) - (uint)uVar11;
  iVar13 = (int)uVar8 / 10 + 0x30;
  iVar9 = iVar17 + 0x10000;
  if (-0x8001 < iVar17) {
    iVar9 = iVar17;
  }
  iVar17 = iVar9 + -0x10000;
  if (iVar9 < 0x8001) {
    iVar17 = iVar9;
  }
  if (iVar17 < 1) {
    uVar4 = uVar11;
    if ((iVar17 < 0) && (uVar4 = uVar11 - (short)iVar13, -iVar13 < iVar17)) {
      uVar4 = uVar15;
    }
  }
  else {
    uVar4 = uVar15;
    if (iVar13 <= iVar17) {
      uVar4 = uVar11 + (short)iVar13;
    }
  }
  *(ushort *)(param_1 + 0x10) = uVar4;
  if ((local_res8 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
LAB_140012cf0:
  FUN_1400c8410(DAT_140e44bc8,0x21,7,param_1[10],param_1[0xb],
                CONCAT22(uVar27,*(undefined2 *)(param_1 + 0x10)),dVar18,uVar3,0xff,0xff,0xff,0xff,1,
                0);
  if (4 < iStack_f4) {
    *param_1 = 0;
  }
  return;
}


