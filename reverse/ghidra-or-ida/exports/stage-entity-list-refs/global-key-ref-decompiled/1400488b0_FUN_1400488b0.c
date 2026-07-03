// Function: FUN_1400488b0 @ 1400488b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400488b0(undefined4 *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  double dVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  ushort uVar22;
  uint uVar23;
  short *psVar24;
  short sVar25;
  short sVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  float fVar31;
  float fVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  float fVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  float fVar43;
  undefined4 uVar44;
  undefined4 in_stack_fffffffffffffe48;
  undefined2 uVar45;
  undefined4 in_stack_fffffffffffffe50;
  undefined2 uVar47;
  undefined4 uVar46;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 uStack_f0;
  undefined1 local_e0 [184];
  
  uVar47 = (undefined2)((uint)in_stack_fffffffffffffe50 >> 0x10);
  uVar45 = (undefined2)((uint)in_stack_fffffffffffffe48 >> 0x10);
  uStack_130 = 0;
  uStack_130._4_4_ = 0;
  lVar2 = DAT_140e45d80;
  iVar18 = local_138._4_4_;
  iVar11 = uStack_130._4_4_;
  iVar20 = uStack_f0._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      iVar18 = (int)((ulonglong)local_138 >> 0x20);
      iVar11 = (int)((ulonglong)uStack_130 >> 0x20);
      iVar20 = (int)((ulonglong)uStack_f0 >> 0x20);
      if (lVar2 == 0) break;
      if (*(int *)(lVar2 + 4) == DAT_140e44308) {
        local_138 = *(undefined8 *)(lVar2 + 0x10);
        uStack_130 = *(undefined8 *)(lVar2 + 0x18);
        uStack_f0 = *(undefined8 *)(lVar2 + 0x58);
      }
      lVar2 = *(longlong *)(lVar2 + 0x60);
    }
  }
  uStack_f0._4_4_ = iVar20;
  uStack_130._4_4_ = iVar11;
  local_138._4_4_ = iVar18;
  fVar32 = (float)param_1[0xb];
  fVar31 = (float)param_1[10];
  dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar32),(double)(DAT_140e445d8 - fVar31));
  fVar40 = DAT_14053b240;
  dVar3 = DAT_140539f28;
  sVar26 = 0;
  uVar37 = SUB84(DAT_14053a020,0);
  uVar41 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar42 = SUB84(DAT_140539d28,0);
  uVar44 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  uVar23 = (uint)(dVar27 * DAT_14053aba0);
  uVar22 = (ushort)uVar23;
  dVar27 = DAT_140539f40;
  dVar28 = DAT_140539f40;
  if (param_1[5] == 0) {
    uVar17 = param_1[3];
    sVar26 = 0;
    dVar35 = (*(double *)(param_1 + 0x12) -
             (*(double *)(param_1 + 0x12) / DAT_14053a3a0) * (double)(int)uVar17) + DAT_140539f00;
    if (uVar17 < 0x3c) {
      dVar27 = (double)FUN_140332d90(((double)(int)uVar17 - _DAT_140539cc0) * DAT_14053a628 *
                                     DAT_14053a020 * DAT_140539d28);
      sVar25 = -(short)(int)(dVar27 * _DAT_14053ac20);
LAB_140048a7c:
      sVar26 = sVar25;
      dVar27 = (double)FUN_140332d90();
      dVar27 = dVar27 * dVar3 + DAT_140539ec8;
    }
    else {
      dVar27 = DAT_140539ec8;
      if ((-1 < (int)uVar17) && (dVar27 = DAT_140539f40, sVar25 = 0, (int)uVar17 < 0x3c))
      goto LAB_140048a7c;
    }
    uVar5 = *(ushort *)((longlong)param_1 + 0x42);
    uVar4 = uVar22 - uVar5;
    uVar7 = (uint)uVar4;
    if (0x8000 < uVar4) {
      uVar7 = 0x10000 - uVar4;
    }
    iVar11 = (uVar23 & 0xffff) - (uint)uVar5;
    iVar20 = (int)uVar7 / 10 + 0x30;
    iVar18 = iVar11 + 0x10000;
    if (-0x8001 < iVar11) {
      iVar18 = iVar11;
    }
    iVar11 = iVar18 + -0x10000;
    if (iVar18 < 0x8001) {
      iVar11 = iVar18;
    }
    if (iVar11 < 1) {
      uVar4 = uVar5;
      if ((iVar11 < 0) && (uVar4 = uVar5 - (short)iVar20, -iVar20 < iVar11)) {
        uVar4 = uVar22;
      }
    }
    else {
      uVar4 = uVar22;
      if (iVar20 <= iVar11) {
        uVar4 = uVar5 + (short)iVar20;
      }
    }
    *(ushort *)((longlong)param_1 + 0x42) = uVar4;
    dVar28 = (double)FUN_1403307c0();
    fVar31 = (float)(dVar28 * dVar35) + fVar31;
    param_1[10] = fVar31;
    dVar29 = (double)FUN_140332d90();
    dVar28 = DAT_140539f40;
    fVar32 = (float)(dVar29 * dVar35) + fVar32;
    param_1[0xb] = fVar32;
    if (uVar17 == 0x3c) {
      param_1[3] = 0;
      *(undefined8 *)(param_1 + 0x12) = 0x3fe0000000000000;
      param_1[5] = 1;
    }
  }
  if (param_1[5] == 1) {
    uVar5 = *(ushort *)((longlong)param_1 + 0x42);
    uVar17 = (uint)uVar5;
    local_138._4_4_ = local_138._4_4_ + -0x3e;
    local_138._4_4_ =
         local_138._4_4_ +
         (local_138._4_4_ / 3 + (local_138._4_4_ >> 0x1f) +
         (int)(((longlong)local_138._4_4_ / 3 + ((longlong)local_138._4_4_ >> 0x3f) & 0xffffffffU)
              >> 0x1f)) * -3;
    dVar35 = (double)FUN_1403307c0();
    fVar40 = (float)(dVar35 * DAT_14053a278) + fVar31;
    dVar35 = (double)FUN_140332d90();
    iVar11 = 0x28;
    fVar43 = (float)(dVar35 * DAT_14053a278) + fVar32;
    dVar35 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar35 * *(double *)(param_1 + 0x12)) + fVar31;
    dVar35 = (double)FUN_140332d90();
    iVar18 = DAT_140e419b8;
    dVar29 = DAT_14053a0f8;
    param_1[0xb] = (float)(dVar35 * *(double *)(param_1 + 0x12)) + fVar32;
    dVar35 = DAT_140539f00;
    uVar37 = DAT_14053ac2c;
    if (param_1[6] == 0xbc) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 2;
      }
      else if (iVar18 == 1) {
        iVar20 = 3;
      }
      else if (iVar18 == 2) {
        iVar20 = 4;
      }
      else if (iVar18 == 3) {
        iVar20 = 5;
      }
      else if (iVar18 == 4) {
        iVar20 = 7;
      }
      iVar12 = 1;
      iVar13 = param_1[3] + -5;
      iVar20 = iVar13 / 0x12 + iVar20;
      if (iVar18 == 0) {
        iVar12 = 0x1068;
      }
      else if (iVar18 == 1) {
        iVar12 = 0xce4;
      }
      else if (iVar18 == 2) {
        iVar12 = 3000;
      }
      else if (iVar18 == 3) {
        iVar12 = 0xa8c;
      }
      else if (iVar18 == 4) {
        iVar12 = 0x960;
      }
      dVar30 = DAT_14053a088;
      if ((((iVar18 != 0) && (dVar30 = DAT_14053a0d0, iVar18 != 1)) &&
          (dVar30 = dVar29, iVar18 != 2)) &&
         ((dVar30 = DAT_14053a118, iVar18 != 3 && (dVar30 = dVar28, iVar18 == 4)))) {
        dVar30 = DAT_14053a158;
      }
      uVar4 = uVar22 - uVar5;
      iVar11 = 0x32;
      uVar7 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar7 = 0x10000 - uVar4;
      }
      dVar33 = (double)local_138._4_4_ * DAT_140539f00;
      iVar6 = (uVar23 & 0xffff) - (uint)uVar5;
      iVar15 = (int)uVar7 / 10 + 0x30;
      iVar21 = iVar6 + 0x10000;
      if (-0x8001 < iVar6) {
        iVar21 = iVar6;
      }
      iVar6 = iVar21 + -0x10000;
      if (iVar21 < 0x8001) {
        iVar6 = iVar21;
      }
      if (iVar6 < 1) {
        if (iVar6 < 0) {
          if (-iVar15 < iVar6) {
            uVar17 = uVar23 & 0xffff;
          }
          else {
            uVar17 = (uint)(ushort)(uVar5 - (short)iVar15);
          }
        }
      }
      else if (iVar6 < iVar15) {
        uVar17 = uVar23 & 0xffff;
      }
      else {
        uVar17 = (uint)(ushort)(uVar5 + (short)iVar15);
      }
      *(short *)((longlong)param_1 + 0x42) = (short)uVar17;
      uVar37 = DAT_14053ac2c;
      if ((param_1[3] - 5 < 0x2d) && (iVar13 == (iVar13 / 0x12) * 0x12)) {
        uVar42 = CONCAT22(uVar45,(short)uVar17);
        uVar41 = DAT_14053ac2c;
        FUN_1400709b0(0xc,0,fVar40,fVar43,uVar42,DAT_14053ac2c,dVar33 + dVar30,1,iVar20,
                      (iVar20 + -1) * iVar12,0);
        uVar47 = (undefined2)((uint)uVar41 >> 0x10);
        uVar45 = (undefined2)((uint)uVar42 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar18 = DAT_140e419b8;
      }
    }
    dVar30 = DAT_14053a0b0;
    if (param_1[6] == 0xbd) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 0x11;
      }
      else if (iVar18 == 1) {
LAB_140048f6b:
        iVar20 = 0x19;
      }
      else {
        if (iVar18 != 2) {
          if (iVar18 == 3) goto LAB_140048f6b;
          if (iVar18 != 4) goto LAB_140048f77;
        }
        iVar20 = 0x1d;
      }
LAB_140048f77:
      dVar33 = DAT_14053a0b0;
      if ((((iVar18 != 0) && (dVar33 = dVar29, iVar18 != 1)) &&
          (dVar33 = DAT_14053a118, iVar18 != 2)) &&
         ((dVar33 = DAT_14053a138, iVar18 != 3 && (dVar33 = dVar28, iVar18 == 4)))) {
        dVar33 = DAT_14053a178;
      }
      uVar5 = uVar22 - (short)uVar17;
      iVar11 = 0x14;
      uVar7 = (uint)uVar5;
      if (0x8000 < uVar5) {
        uVar7 = 0x10000 - uVar5;
      }
      dVar33 = (double)local_138._4_4_ * dVar35 + dVar33;
      iVar12 = (uVar23 & 0xffff) - uVar17;
      iVar21 = (int)uVar7 / 10 + 0x30;
      iVar13 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar13 = iVar12;
      }
      iVar12 = iVar13 + -0x10000;
      if (iVar13 < 0x8001) {
        iVar12 = iVar13;
      }
      if (iVar12 < 1) {
        if ((iVar12 < 0) &&
           (uVar17 = (uint)(ushort)((short)uVar17 - (short)iVar21), -iVar21 < iVar12)) {
          uVar17 = uVar23 & 0xffff;
        }
      }
      else if (iVar12 < iVar21) {
        uVar17 = uVar23 & 0xffff;
      }
      else {
        uVar17 = uVar17 + iVar21;
      }
      uVar14 = (undefined2)uVar17;
      uVar17 = uVar17 & 0xffff;
      *(undefined2 *)((longlong)param_1 + 0x42) = uVar14;
      if (param_1[3] == 5) {
        uVar42 = CONCAT22(uVar45,uVar14);
        uVar41 = uVar37;
        FUN_1400709b0(3,0,fVar40,fVar43,uVar42,uVar37,dVar33,1,iVar20,0x10000,0);
        uVar47 = (undefined2)((uint)uVar41 >> 0x10);
        uVar45 = (undefined2)((uint)uVar42 >> 0x10);
        if (2 < DAT_140e419b8) {
          uVar42 = CONCAT22(uVar45,(short)(0x10000 / (ulonglong)(uint)(iVar20 * 2)) +
                                   *(short *)((longlong)param_1 + 0x42));
          uVar41 = uVar37;
          FUN_1400709b0(3,0,fVar40,fVar43,uVar42,uVar37,dVar33 - DAT_140539f68,1,iVar20,0x10000,0);
          uVar47 = (undefined2)((uint)uVar41 >> 0x10);
          uVar45 = (undefined2)((uint)uVar42 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar18 = DAT_140e419b8;
      }
    }
    dVar28 = DAT_14053a1b8;
    if (param_1[6] == 0xbe) {
      dVar33 = DAT_14053a148;
      if ((((iVar18 != 0) && (dVar33 = DAT_14053a180, iVar18 != 1)) &&
          (dVar33 = DAT_14053a1b8, iVar18 != 2)) &&
         ((iVar18 != 3 && (dVar33 = DAT_140539f40, iVar18 == 4)))) {
        dVar33 = DAT_14053a1e8;
      }
      iVar20 = param_1[3];
      iVar11 = 0x1e;
      dVar33 = (double)local_138._4_4_ * dVar35 + dVar33;
      if (iVar20 < 5) {
        uVar5 = *(ushort *)((longlong)param_1 + 0x42);
        uVar17 = (uint)uVar5;
        uVar4 = uVar22 - uVar5;
        uVar7 = (uint)uVar4;
        if (0x8000 < uVar4) {
          uVar7 = 0x10000 - uVar4;
        }
        iVar13 = (uVar23 & 0xffff) - (uint)uVar5;
        iVar12 = (int)uVar7 / 10 + 0x30;
        iVar20 = iVar13 + 0x10000;
        if (-0x8001 < iVar13) {
          iVar20 = iVar13;
        }
        iVar13 = iVar20 + -0x10000;
        if (iVar20 < 0x8001) {
          iVar13 = iVar20;
        }
        if (iVar13 < 1) {
          if ((iVar13 < 0) && (uVar17 = (uint)(ushort)(uVar5 - (short)iVar12), -iVar12 < iVar13)) {
            uVar17 = uVar23 & 0xffff;
          }
        }
        else if (iVar13 < iVar12) {
          uVar17 = uVar23 & 0xffff;
        }
        else {
          uVar17 = (uint)(ushort)(uVar5 + (short)iVar12);
        }
        *(short *)((longlong)param_1 + 0x42) = (short)uVar17;
      }
      else if (iVar20 < 0x1e) {
        uVar7 = iVar20 - 5U & 0x80000003;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
        }
        if (uVar7 == 0) {
          uVar42 = CONCAT22(uVar45,(short)uVar17);
          uVar41 = uVar37;
          FUN_14006c2f0(7,0,fVar40,fVar43,uVar42,uVar37,dVar33,1,0);
          uVar47 = (undefined2)((uint)uVar41 >> 0x10);
          if (0 < DAT_140e419b8) {
            sVar25 = *(short *)((longlong)param_1 + 0x42);
            dVar36 = dVar33 - DAT_140539ef8;
            iVar18 = 0;
            do {
              uVar42 = CONCAT22((short)((uint)uVar42 >> 0x10),(short)iVar18 * 700 + sVar25 + -0x15e)
              ;
              uVar41 = uVar37;
              FUN_14006c2f0(7,0,fVar40,fVar43,uVar42,uVar37,dVar36,1,0);
              uVar47 = (undefined2)((uint)uVar41 >> 0x10);
              iVar18 = iVar18 + 1;
              dVar35 = DAT_140539f00;
            } while (iVar18 < 2);
          }
          uVar45 = (undefined2)((uint)uVar42 >> 0x10);
          if (2 < DAT_140e419b8) {
            sVar25 = *(short *)((longlong)param_1 + 0x42);
            iVar18 = 0;
            do {
              uVar42 = CONCAT22((short)((uint)uVar42 >> 0x10),(short)iVar18 * 0x578 + sVar25 + -700)
              ;
              uVar41 = uVar37;
              FUN_14006c2f0(7,0,fVar40,fVar43,uVar42,uVar37,dVar33 - dVar3,1,0);
              uVar47 = (undefined2)((uint)uVar41 >> 0x10);
              uVar45 = (undefined2)((uint)uVar42 >> 0x10);
              iVar18 = iVar18 + 1;
            } while (iVar18 < 2);
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
          uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
          iVar18 = DAT_140e419b8;
        }
      }
    }
    dVar36 = DAT_14053a138;
    dVar33 = DAT_14053a070;
    dVar3 = DAT_140539f40;
    if (param_1[6] == 0xbf) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 5;
      }
      else if (iVar18 == 1) {
        iVar20 = 7;
      }
      else if ((iVar18 == 2) || (iVar18 == 3)) {
        iVar20 = 9;
      }
      else if (iVar18 == 4) {
        iVar20 = 0xb;
      }
      dVar34 = DAT_14053a070;
      if ((((iVar18 != 0) && (dVar34 = dVar30, iVar18 != 1)) &&
          (dVar34 = DAT_14053a0d0, iVar18 != 2)) &&
         ((dVar34 = dVar29, iVar18 != 3 && (dVar34 = DAT_140539f40, iVar18 == 4)))) {
        dVar34 = DAT_14053a138;
      }
      uVar5 = *(ushort *)((longlong)param_1 + 0x42);
      uVar17 = (uint)uVar5;
      uVar4 = uVar22 - uVar5;
      iVar11 = 0x14;
      uVar7 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar7 = 0x10000 - uVar4;
      }
      iVar12 = (uVar23 & 0xffff) - (uint)uVar5;
      dVar34 = (double)local_138._4_4_ * dVar35 + dVar34;
      iVar21 = (int)uVar7 / 10 + 0x30;
      iVar13 = iVar12 + 0x10000;
      if (-0x8001 < iVar12) {
        iVar13 = iVar12;
      }
      iVar12 = iVar13 + -0x10000;
      if (iVar13 < 0x8001) {
        iVar12 = iVar13;
      }
      if (iVar12 < 1) {
        if ((iVar12 < 0) && (uVar17 = (uint)(ushort)(uVar5 - (short)iVar21), -iVar21 < iVar12)) {
          uVar17 = uVar23 & 0xffff;
        }
      }
      else if (iVar12 < iVar21) {
        uVar17 = uVar23 & 0xffff;
      }
      else {
        uVar17 = (uint)(ushort)(uVar5 + (short)iVar21);
      }
      *(short *)((longlong)param_1 + 0x42) = (short)uVar17;
      if (param_1[3] == 5) {
        iVar18 = iVar20 * 400 + -400;
        uVar37 = CONCAT22(uVar45,(short)uVar17);
        FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
        uVar37 = CONCAT22((short)((uint)uVar37 >> 0x10),*(short *)((longlong)param_1 + 0x42) + 8000)
        ;
        FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
        uVar47 = 0;
        uVar37 = CONCAT22((short)((uint)uVar37 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -8000
                         );
        FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
        uVar45 = (undefined2)((uint)uVar37 >> 0x10);
        if (2 < DAT_140e419b8) {
          dVar34 = dVar34 + dVar35;
          iVar18 = iVar20 * 400 + -800;
          iVar20 = iVar20 + -1;
          uVar37 = CONCAT22(uVar45,*(undefined2 *)((longlong)param_1 + 0x42));
          FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
          uVar37 = CONCAT22((short)((uint)uVar37 >> 0x10),
                            *(short *)((longlong)param_1 + 0x42) + 8000);
          FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
          uVar47 = 0;
          uVar37 = CONCAT22((short)((uint)uVar37 >> 0x10),
                            *(short *)((longlong)param_1 + 0x42) + -8000);
          FUN_1400709b0(5,0,fVar40,fVar43,uVar37,0,dVar34,1,iVar20,iVar18,0);
          uVar45 = (undefined2)((uint)uVar37 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar18 = DAT_140e419b8;
      }
    }
    if (param_1[6] == 0xc0) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 8;
      }
      else if (iVar18 == 1) {
        iVar20 = 5;
      }
      else if (((iVar18 == 2) || (iVar18 == 3)) || (iVar18 == 4)) {
        iVar20 = 4;
      }
      iVar13 = 1;
      if (iVar18 == 0) {
        iVar13 = 0x1068;
      }
      else if (iVar18 == 1) {
        iVar13 = 0xe10;
      }
      else if (iVar18 == 2) {
        iVar13 = 0xce4;
      }
      else if ((iVar18 == 3) || (iVar18 == 4)) {
        iVar13 = 3000;
      }
      iVar12 = param_1[3];
      iVar13 = (iVar12 + -5) * 700 + iVar13;
      dVar29 = DAT_14053a0d0;
      if (((iVar18 != 0) && (dVar29 = DAT_14053a100, iVar18 != 1)) &&
         ((dVar29 = DAT_14053a120, iVar18 != 2 && ((iVar18 != 3 && (dVar29 = dVar3, iVar18 == 4)))))
         ) {
        dVar29 = DAT_14053a158;
      }
      iVar11 = 0x3c;
      dVar35 = (dVar29 - ((double)iVar12 - dVar30) * _DAT_140539e28) +
               (double)local_138._4_4_ * dVar35;
      if (iVar12 < 5) {
        uVar5 = *(ushort *)((longlong)param_1 + 0x42);
        uVar4 = uVar22 - uVar5;
        uVar17 = (uint)uVar4;
        if (0x8000 < uVar4) {
          uVar17 = 0x10000 - uVar4;
        }
        iVar13 = (uVar23 & 0xffff) - (uint)uVar5;
        iVar12 = (int)uVar17 / 10 + 0x30;
        iVar20 = iVar13 + 0x10000;
        if (-0x8001 < iVar13) {
          iVar20 = iVar13;
        }
        iVar13 = iVar20 + -0x10000;
        if (iVar20 < 0x8001) {
          iVar13 = iVar20;
        }
        if (iVar13 < 1) {
          uVar4 = uVar5;
          if ((iVar13 < 0) && (uVar4 = uVar5 - (short)iVar12, -iVar12 < iVar13)) {
            uVar4 = uVar22;
          }
        }
        else {
          uVar4 = uVar22;
          if (iVar12 <= iVar13) {
            uVar4 = uVar5 + (short)iVar12;
          }
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar4;
      }
      else if ((iVar12 < 0x3c) &&
              (uVar1 = (longlong)(iVar12 + -5) % (longlong)iVar20, (int)uVar1 == 0)) {
        uVar47 = 0;
        uVar37 = CONCAT22(uVar45,*(undefined2 *)((longlong)param_1 + 0x42));
        FUN_1400709b0(0xb,uVar1 & 0xffffffff,fVar40,fVar43,uVar37,0,dVar35,1,2,iVar13,0);
        uVar45 = (undefined2)((uint)uVar37 >> 0x10);
        if (2 < DAT_140e419b8) {
          uVar47 = 0;
          uVar37 = CONCAT22(uVar45,*(undefined2 *)((longlong)param_1 + 0x42));
          FUN_1400709b0(0xb,0,fVar40,fVar43,uVar37,0,dVar35 + dVar3,1,2,iVar20 * 400 + iVar13,0);
          uVar45 = (undefined2)((uint)uVar37 >> 0x10);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar18 = DAT_140e419b8;
        goto LAB_1400498e3;
      }
      uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
    }
LAB_1400498e3:
    dVar35 = DAT_14053a190;
    if (param_1[6] == 0xc1) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 0x14;
      }
      else if (iVar18 == 1) {
        iVar20 = 0x10;
      }
      else if (iVar18 == 2) {
        iVar20 = 0xe;
      }
      else if (iVar18 == 3) {
        iVar20 = 0xc;
      }
      else if (iVar18 == 4) {
        iVar20 = 10;
      }
      iVar13 = param_1[3];
      iVar21 = 1;
      iVar12 = (iVar13 + -5) / iVar20;
      if (iVar18 == 0) {
        iVar21 = 0xce4;
      }
      else if (iVar18 == 1) {
        iVar21 = 0xa28;
      }
      else if (iVar18 == 2) {
        iVar21 = 0x8fc;
      }
      else if (iVar18 == 3) {
        iVar21 = 2000;
      }
      else if (iVar18 == 4) {
        iVar21 = 0x708;
      }
      dVar29 = DAT_14053a0d0;
      if ((((iVar18 != 0) && (dVar29 = DAT_14053a118, iVar18 != 1)) &&
          (dVar29 = dVar36, iVar18 != 2)) &&
         ((dVar29 = DAT_14053a158, iVar18 != 3 && (dVar29 = dVar3, iVar18 == 4)))) {
        dVar29 = DAT_14053a190;
      }
      uVar5 = *(ushort *)((longlong)param_1 + 0x42);
      uVar17 = (uint)uVar5;
      uVar4 = uVar22 - uVar5;
      iVar11 = 0x50;
      uVar7 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar7 = 0x10000 - uVar4;
      }
      iVar15 = (uVar23 & 0xffff) - (uint)uVar5;
      iVar16 = (int)uVar7 / 10 + 0x30;
      iVar6 = iVar15 + 0x10000;
      if (-0x8001 < iVar15) {
        iVar6 = iVar15;
      }
      iVar15 = iVar6 + -0x10000;
      if (iVar6 < 0x8001) {
        iVar15 = iVar6;
      }
      if (iVar15 < 1) {
        if ((iVar15 < 0) && (uVar17 = (uint)(ushort)(uVar5 - (short)iVar16), -iVar16 < iVar15)) {
          uVar17 = uVar23 & 0xffff;
        }
      }
      else if (iVar15 < iVar16) {
        uVar17 = uVar23 & 0xffff;
      }
      else {
        uVar17 = (uint)(ushort)(uVar5 + (short)iVar16);
      }
      *(short *)((longlong)param_1 + 0x42) = (short)uVar17;
      if ((iVar13 - 5U < 0x4b) && ((iVar13 + -5) % iVar20 == 0)) {
        uVar41 = CONCAT22(uVar45,(short)(uVar17 + 0x400 >> 0xb) * 0x800);
        uVar37 = DAT_14053ac2c;
        FUN_1400709b0(8,0,fVar40,fVar43,uVar41,DAT_14053ac2c,dVar29,1,iVar12 + 1,iVar12 * iVar21,0);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar45 = (undefined2)((uint)uVar41 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar17 = (uint)*(ushort *)((longlong)param_1 + 0x42);
        iVar18 = DAT_140e419b8;
      }
    }
    uVar5 = (ushort)uVar17;
    if (param_1[6] == 0xc2) {
      iVar20 = 1;
      if (iVar18 == 0) {
        iVar20 = 9;
      }
      else if (iVar18 == 1) {
        iVar20 = 0xd;
      }
      else if (iVar18 == 2) {
        iVar20 = 0xf;
      }
      else if (iVar18 == 3) {
        iVar20 = 0x11;
      }
      else if (iVar18 == 4) {
        iVar20 = 0x13;
      }
      if ((((iVar18 != 0) && (dVar36 = dVar35, iVar18 != 1)) &&
          (dVar36 = DAT_14053a1e8, iVar18 != 2)) &&
         ((dVar36 = DAT_14053a178, iVar18 != 3 && (dVar36 = dVar3, iVar18 == 4)))) {
        dVar36 = dVar28;
      }
      uVar4 = uVar22 - uVar5;
      iVar11 = 0x14;
      uVar7 = (uint)uVar4;
      if (0x8000 < uVar4) {
        uVar7 = 0x10000 - uVar4;
      }
      iVar13 = (uVar23 & 0xffff) - uVar17;
      iVar12 = (int)uVar7 / 10 + 0x30;
      iVar18 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar18 = iVar13;
      }
      iVar13 = iVar18 + -0x10000;
      if (iVar18 < 0x8001) {
        iVar13 = iVar18;
      }
      if (iVar13 < 1) {
        uVar4 = uVar5;
        if ((iVar13 < 0) && (uVar4 = uVar5 - (short)iVar12, -iVar12 < iVar13)) {
          uVar4 = uVar22;
        }
      }
      else {
        uVar4 = uVar22;
        if (iVar12 <= iVar13) {
          uVar4 = uVar5 + (short)iVar12;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar4;
      if (param_1[3] == 5) {
        iVar18 = iVar20 * 0x9f6 + -0x9f6;
        uVar47 = 0;
        FUN_1400709b0(2,9,fVar40,fVar43,CONCAT22(uVar45,uVar4),0,dVar36,1,iVar20,iVar18,0);
        if (2 < DAT_140e419b8) {
          uVar47 = 0;
          FUN_1400709b0(2,9,fVar40,fVar43,
                        (short)(0x10000 / (ulonglong)(uint)(iVar20 * 2)) +
                        *(short *)((longlong)param_1 + 0x42),0,dVar36 + dVar33,1,iVar20,iVar18,0);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
      }
    }
    dVar35 = DAT_14053aa88;
    fVar32 = DAT_14053a770;
    dVar3 = DAT_14053a020;
    dVar28 = DAT_140539d28;
    iVar18 = param_1[3];
    uVar19 = (undefined4)((ulonglong)DAT_14053aa88 >> 0x20);
    uVar41 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar44 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    fVar40 = DAT_14053b240;
    if ((iVar18 < 0) || (fVar40 = DAT_14053a770, 4 < iVar18)) {
      uVar38 = SUB84(DAT_14053a178,0);
      uVar39 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else {
      dVar29 = (double)FUN_140332d90(((double)iVar18 - _DAT_140539cc0) * DAT_14053aa88 *
                                     DAT_14053a020 * DAT_140539d28);
      uVar38 = SUB84(DAT_14053a178,0);
      uVar39 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
      fVar40 = (float)(dVar29 * DAT_14053a178) - fVar32;
    }
    fVar31 = DAT_14053b240;
    uVar42 = SUB84(dVar28,0);
    uVar37 = SUB84(dVar3,0);
    uVar8 = SUB84(dVar35,0);
    if (iVar18 == iVar11) {
      param_1[5] = param_1[5] + 1;
      param_1[3] = 0;
    }
  }
  else {
    uVar38 = SUB84(DAT_14053a178,0);
    uVar39 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    uVar8 = SUB84(DAT_14053aa88,0);
    uVar19 = (undefined4)((ulonglong)DAT_14053aa88 >> 0x20);
    fVar32 = DAT_14053a770;
    fVar31 = DAT_14053b240;
  }
  dVar3 = DAT_14053b138;
  dVar28 = DAT_14053a6d8;
  if (param_1[5] != 2) goto LAB_140049ff8;
  uVar23 = param_1[3];
  if (uVar23 < 0x28) {
    dVar27 = (double)FUN_140332d90(((double)(int)uVar23 - DAT_14053b138) * DAT_14053a6d8 *
                                   (double)CONCAT44(uVar41,uVar37) * (double)CONCAT44(uVar44,uVar42)
                                  );
    sVar25 = -(short)(int)(dVar27 * DAT_14053ac08);
LAB_140049f84:
    dVar27 = (double)FUN_140332d90(((double)(int)uVar23 - dVar3) * dVar28 *
                                   (double)CONCAT44(uVar41,uVar37) * (double)CONCAT44(uVar44,uVar42)
                                  );
    dVar27 = dVar27 + _DAT_140539cc0;
    if (uVar23 < 5) {
      dVar28 = (double)FUN_140332d90(((double)(int)uVar23 - _DAT_14053b0b8) *
                                     (double)CONCAT44(uVar19,uVar8) *
                                     (double)CONCAT44(uVar41,uVar37) *
                                     (double)CONCAT44(uVar44,uVar42));
      fVar31 = (float)(dVar28 * (double)CONCAT44(uVar39,uVar38)) - fVar32;
    }
  }
  else {
    if ((int)uVar23 < 0x28) {
      sVar25 = 0;
      fVar40 = fVar32;
      dVar27 = DAT_140539f40;
      sVar26 = 0;
      if ((int)uVar23 < 0) goto LAB_140049ff8;
      goto LAB_140049f84;
    }
    sVar25 = 0;
    dVar27 = 0.0;
  }
  fVar40 = fVar31;
  sVar26 = sVar25;
  if (uVar23 == 0x28) {
    *param_1 = 0;
  }
LAB_140049ff8:
  uVar38 = SUB84(dVar27,0);
  sVar25 = *(short *)((longlong)param_1 + 0x42);
  dVar28 = (double)FUN_1403307c0();
  fVar31 = (float)(dVar28 * (double)((float)dVar27 * fVar40)) + 0.0;
  dVar28 = (double)FUN_140332d90();
  iVar18 = param_1[6];
  cVar10 = (iVar18 == 0xbd) + '\x01';
  fVar32 = (float)(dVar28 * (double)((float)dVar27 * fVar40)) + 0.0;
  if (iVar18 == 0xbe) {
    cVar10 = '\x03';
  }
  else if (iVar18 == 0xbf) {
    cVar10 = '\x04';
  }
  else if (iVar18 == 0xc0) {
    cVar10 = '\x05';
  }
  else if (iVar18 == 0xc1) {
    cVar10 = '\x06';
  }
  else if (iVar18 == 0xc2) {
    cVar10 = '\a';
  }
  psVar24 = (short *)((longlong)param_1 + 0x42);
  puVar9 = (undefined8 *)FUN_140134fa0(local_e0,cVar10);
  uVar39 = *(undefined4 *)(puVar9 + 1);
  uVar8 = (undefined4)((ulonglong)*puVar9 >> 0x20);
  uVar19 = (undefined4)*puVar9;
  uVar46 = CONCAT22(uVar47,sVar26 + sVar25);
  FUN_1400c8410(DAT_140e44880,0x24,7,fVar31 + (float)param_1[10],fVar32 + (float)param_1[0xb],uVar46
                ,dVar27,uVar38,uVar19,uVar8,uVar39,0xff,1,0);
  uVar23 = CONCAT22((short)((uint)uVar46 >> 0x10),sVar26 + *psVar24 + -0x8000);
  FUN_1400c8410(DAT_140e44880,0x24,7,(float)param_1[10] - fVar31,(float)param_1[0xb] - fVar32,uVar23
                ,dVar27,uVar38,uVar19,uVar8,uVar39,0xff,1,1);
  uVar23 = uVar23 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,7,param_1[10],param_1[0xb],uVar23,dVar27,uVar38,0xff,0xff,0xff,
                0xff,1,0);
  dVar28 = (double)FUN_140332d90(((double)(int)param_1[3] - 0.0) * DAT_14053a9d8 *
                                 (double)CONCAT44(uVar41,uVar37) * (double)CONCAT44(uVar44,uVar42));
  uVar23 = uVar23 & 0xffff0000;
  FUN_1400c8410(DAT_140e4487c,0x24,8,param_1[10],param_1[0xb],uVar23,dVar27,uVar38,0xff,0xff,0xff,
                0x80 - (int)(dVar28 * DAT_14053b1c8),1,0);
  if (((*(byte *)(param_1 + 3) & 1) == 0) && (param_1[5] == 0)) {
    uVar37 = CONCAT22((short)(uVar23 >> 0x10),sVar26 + *psVar24);
    FUN_140070d00(5,DAT_140e44880,0x23,fVar31 + (float)param_1[10],fVar32 + (float)param_1[0xb],
                  uVar37,0,uVar38,uVar38,0x10,0xff,0xff,0xff,0x60,0);
    uVar23 = CONCAT22((short)((uint)uVar37 >> 0x10),sVar26 + *psVar24 + -0x8000);
    FUN_140070d00(7,DAT_140e44880,0x23,(float)param_1[10] - fVar31,(float)param_1[0xb] - fVar32,
                  uVar23,0,uVar38,uVar38,0x18,0xff,0xff,0xff,0x60,0);
    FUN_140070d00(5,DAT_140e4487c,0x23,param_1[10],param_1[0xb],uVar23 & 0xffff0000,0,uVar38,uVar38,
                  0x18,0xff,0xff,0xff,0x60,0);
  }
  if (((uStack_130._4_4_ < 1) || (DAT_140e4430c < 1)) || (uStack_f0._4_4_ == 0)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  return;
}


