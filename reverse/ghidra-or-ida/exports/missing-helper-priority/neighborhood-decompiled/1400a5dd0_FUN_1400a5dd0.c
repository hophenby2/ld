// Function: FUN_1400a5dd0 @ 1400a5dd0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400a5dd0(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  ulonglong uVar5;
  ushort uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined4 uVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  float fVar33;
  float fVar34;
  undefined4 uVar35;
  float fVar36;
  undefined4 uVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffea8;
  undefined2 uVar42;
  uint in_stack_fffffffffffffeb0;
  undefined1 in_stack_fffffffffffffeb8 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  ulonglong in_stack_fffffffffffffec8;
  ulonglong uVar55;
  undefined8 uVar56;
  ulonglong uVar57;
  
  uVar42 = (undefined2)(in_stack_fffffffffffffeb0 >> 0x10);
  uVar24 = (undefined4)(in_stack_fffffffffffffec8 >> 0x20);
  iVar12 = 0;
  if (param_1[5] == 0) {
    uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    in_stack_fffffffffffffec8 = CONCAT44(uVar24,0xff);
    local_res8 = (undefined4)uVar8;
    dVar26 = DAT_14053a070 - (double)(int)param_1[3] * DAT_140539ec8;
    uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
    in_stack_fffffffffffffeb8._8_4_ = SUB84(dVar26,0);
    in_stack_fffffffffffffeb8._0_8_ = dVar26;
    in_stack_fffffffffffffeb8._12_4_ = (int)((ulonglong)dVar26 >> 0x20);
    uVar17 = in_stack_fffffffffffffeb0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,uVar17,in_stack_fffffffffffffeb8,
                  in_stack_fffffffffffffec8,0xff,0xff,0xff,1,0);
    uVar42 = (undefined2)(uVar17 >> 0x10);
    in_stack_fffffffffffffea8 = uStackX_c;
    if (param_1[3] == 0x14) {
      uVar8 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffec);
      param_1[5] = param_1[5] + 1;
      local_res8 = (undefined4)uVar8;
      uStackX_c = (undefined4)((ulonglong)uVar8 >> 0x20);
      param_1[10] = local_res8;
      param_1[0xb] = uStackX_c;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  dVar27 = DAT_14053a020;
  dVar26 = DAT_140539d28;
  if (param_1[5] != 1) goto LAB_1400a7591;
  iVar11 = param_1[3];
  dVar25 = (double)FUN_140332d90(((double)iVar11 - 0.0) * DAT_14053ab78 * DAT_14053a020 *
                                 DAT_140539d28);
  fVar20 = (float)(dVar25 + dVar25) + 0.0;
  dVar26 = (double)FUN_140332d90(((double)iVar11 - DAT_140539fc8) * DAT_14053ab78 * dVar27 * dVar26)
  ;
  fVar38 = (float)(dVar26 + dVar26) + 0.0;
  dVar26 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((float)param_1[0xb] + DAT_14053ac5c)),
                                 SUB84((double)(DAT_140e445d8 - (float)param_1[10]),0));
  uVar17 = (uint)(dVar26 * DAT_14053aba0);
  if ((ushort)((ushort)uVar17 + 0xe890) < 0xa890) {
    if (0x688f < (ushort)uVar17) {
      uVar17 = 0x6890;
    }
  }
  else {
    uVar17 = 6000;
  }
  fVar30 = (float)param_1[0xd];
  fVar34 = DAT_140e45d24 + (float)param_1[0xc];
  iVar13 = (int)fVar30;
  param_1[10] = fVar34;
  uVar16 = (ushort)uVar17;
  iVar14 = iVar13;
  if ((iVar11 < 0) || (iVar14 = iVar13 + -0x2ee, 0x77 < iVar11)) {
    if (iVar11 < 0x1a4) goto LAB_1400a6185;
    if (iVar11 < 600) {
      dVar26 = (double)FUN_140332d90();
      dVar26 = dVar26 * _DAT_14053a860;
      param_1[0xd] = fVar30 + DAT_140539cf0;
      fVar33 = (float)(iVar13 - (int)dVar26);
      param_1[0xb] = fVar33;
    }
    else {
      fVar30 = fVar30 + DAT_140539cf0;
      fVar33 = (float)iVar13;
      fVar21 = (float)(iVar11 + -600) * DAT_140539cd8;
      param_1[0xb] = fVar33;
      param_1[0xd] = fVar21 + fVar30;
    }
  }
  else {
    dVar26 = (double)FUN_140332d90();
    iVar14 = iVar13 - (int)(dVar26 * _DAT_14053a860);
LAB_1400a6185:
    fVar33 = (float)iVar14;
    param_1[0xd] = fVar30 + DAT_140539cf0;
    param_1[0xb] = fVar33;
    if (iVar11 < 0x46) {
      uVar1 = *(ushort *)((longlong)param_1 + 0x42);
      uVar6 = uVar16 - uVar1;
      uVar18 = (uint)uVar6;
      if (0x8000 < uVar6) {
        uVar18 = 0x10000 - uVar6;
      }
      iVar13 = (uVar17 & 0xffff) - (uint)uVar1;
      iVar15 = (int)uVar18 / 0x14 + 0x30;
      iVar14 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar14 = iVar13;
      }
      iVar13 = iVar14 + -0x10000;
      if (iVar14 < 0x8001) {
        iVar13 = iVar14;
      }
      if (iVar13 < 1) {
        uVar6 = uVar1;
        if ((iVar13 < 0) && (uVar6 = uVar1 - (short)iVar15, -iVar15 < iVar13)) {
          uVar6 = uVar16;
        }
      }
      else {
        uVar6 = uVar16;
        if (iVar15 <= iVar13) {
          uVar6 = uVar1 + (short)iVar15;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar6;
    }
  }
  sVar10 = *(short *)((longlong)param_1 + 0x42);
  dVar26 = (double)FUN_1403307c0();
  fVar36 = fVar33 + fVar38;
  fVar40 = (float)(dVar26 * _DAT_14053b158) + fVar34;
  dVar26 = (double)FUN_140332d90();
  fVar39 = (float)(dVar26 * _DAT_14053b158) + fVar36;
  dVar27 = (double)FUN_1403307c0();
  dVar26 = DAT_14053a418;
  fVar21 = (float)(dVar27 * DAT_14053a418) + fVar40;
  dVar27 = (double)FUN_140332d90();
  fVar22 = (float)(dVar27 * dVar26) + fVar39;
  dVar27 = (double)FUN_1403307c0();
  fVar23 = (float)(dVar27 * dVar26) + fVar40;
  dVar27 = (double)FUN_140332d90();
  fVar30 = DAT_14053ac2c;
  uVar24 = (undefined4)(in_stack_fffffffffffffec8 >> 0x20);
  fVar41 = (float)(dVar27 * dVar26) + fVar39;
  if ((iVar11 - 0x46U < 0x212) && (fVar33 < DAT_14053ae30)) {
    dVar26 = (double)FUN_1403307c0();
    fVar34 = (float)(dVar26 * _DAT_14053a420) + fVar34;
    dVar26 = (double)FUN_140332d90();
    uVar24 = (undefined4)(in_stack_fffffffffffffec8 >> 0x20);
    uVar42 = (undefined2)((uint)in_stack_fffffffffffffea8 >> 0x10);
    uVar35 = SUB84(DAT_14053a138,0);
    uVar57 = (ulonglong)DAT_14053a138 >> 0x20;
    uVar28 = SUB84(DAT_14053a0f8,0);
    uVar29 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    fVar36 = (float)(dVar26 * _DAT_14053a420) + fVar36;
    uVar37 = SUB84(DAT_14053a1b8,0);
    uVar5 = (ulonglong)DAT_14053a1b8 >> 0x20;
    uVar18 = (iVar11 + -0x46) % 0xa4;
    if (uVar18 < 0x20) {
      uVar7 = uVar18 & 0x80000003;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
      }
      if (uVar7 == 0) {
        dVar26 = DAT_14053a0f8;
        if (DAT_140e419b8 == 0) {
LAB_1400a645e:
          if (1 < DAT_140e419b8) {
LAB_1400a6463:
            dVar27 = dVar26 - DAT_140539fa8;
            iVar11 = iVar12;
            do {
              in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffff00000000;
              auVar43._12_4_ = in_stack_fffffffffffffeb8._12_4_;
              auVar43._0_8_ = in_stack_fffffffffffffeb8._0_8_;
              auVar43._8_4_ = 1;
              in_stack_fffffffffffffeb8._8_8_ = auVar43._8_8_;
              in_stack_fffffffffffffeb8._0_8_ = dVar27;
              in_stack_fffffffffffffea8 =
                   CONCAT22((short)((uint)in_stack_fffffffffffffea8 >> 0x10),
                            (short)iVar11 * 3000 + sVar10 + -0x5dc);
              FUN_14006c2f0(10,0,fVar34,fVar36,in_stack_fffffffffffffea8,fVar30,dVar27,
                            in_stack_fffffffffffffeb8._8_8_,in_stack_fffffffffffffec8);
              iVar11 = iVar11 + 1;
            } while (iVar11 < 2);
          }
        }
        else {
          dVar26 = DAT_14053a138;
          if (DAT_140e419b8 != 1) {
            dVar26 = DAT_14053a178;
            if ((DAT_140e419b8 != 2) && (dVar26 = DAT_14053a1b8, DAT_140e419b8 != 3)) {
              dVar26 = DAT_140539f40;
              if (DAT_140e419b8 == 4) {
                dVar26 = DAT_14053a208;
              }
              goto LAB_1400a645e;
            }
            goto LAB_1400a6463;
          }
        }
        sVar10 = *(short *)((longlong)param_1 + 0x42);
        dVar27 = dVar26 - DAT_140539f28;
        do {
          in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffff00000000;
          auVar44._12_4_ = in_stack_fffffffffffffeb8._12_4_;
          auVar44._0_8_ = in_stack_fffffffffffffeb8._0_8_;
          auVar44._8_4_ = 1;
          in_stack_fffffffffffffeb8._8_8_ = auVar44._8_8_;
          in_stack_fffffffffffffeb8._0_8_ = dVar27;
          in_stack_fffffffffffffea8 =
               CONCAT22((short)((uint)in_stack_fffffffffffffea8 >> 0x10),
                        (short)iVar12 * 0x5dc + sVar10 + -0x2ee);
          FUN_14006c2f0(10,0,fVar34,fVar36,in_stack_fffffffffffffea8,fVar30,dVar27,
                        in_stack_fffffffffffffeb8._8_8_,in_stack_fffffffffffffec8);
          iVar12 = iVar12 + 1;
        } while (iVar12 < 2);
        uVar55 = in_stack_fffffffffffffec8 & 0xffffffff00000000;
        auVar45._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar45._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar45._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar45._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = dVar26;
        uVar28 = CONCAT22((short)((uint)in_stack_fffffffffffffea8 >> 0x10),
                          *(undefined2 *)((longlong)param_1 + 0x42));
        FUN_14006c2f0(10,0,fVar34,fVar36,uVar28,fVar30,dVar26,in_stack_fffffffffffffeb8._8_8_,uVar55
                     );
        uVar24 = (undefined4)(uVar55 >> 0x20);
        uVar42 = (undefined2)((uint)uVar28 >> 0x10);
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
        FUN_14018a340(DAT_140e472a4,1,1);
        uVar28 = SUB84(DAT_14053a0f8,0);
        uVar29 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
    }
    iVar12 = DAT_140e419b8;
    dVar26 = DAT_140539f40;
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x1e;
    }
    else if ((((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) ||
            (DAT_140e419b8 == 4)) {
      iVar11 = 0x14;
    }
    iVar14 = 1;
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
        iVar14 = 2;
      }
      else if (DAT_140e419b8 == 2) {
        iVar14 = 3;
      }
      else if (DAT_140e419b8 == 3) {
        iVar14 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar14 = 7;
      }
    }
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 8000;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0x12c0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar13 = 4000;
    }
    else if (DAT_140e419b8 == 3) {
      iVar13 = 0xc80;
    }
    else if (DAT_140e419b8 == 4) {
      iVar13 = 0xa8c;
    }
    uVar31 = (undefined4)DAT_14053a1e8;
    uVar32 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
    iVar13 = (iVar14 + -1) * iVar13;
    if ((DAT_140e419b8 != 0) && (uVar28 = uVar35, uVar29 = (int)uVar57, DAT_140e419b8 != 1)) {
      if (DAT_140e419b8 == 2) {
        uVar28 = SUB84(DAT_14053a178,0);
        uVar29 = (int)((ulonglong)DAT_14053a178 >> 0x20);
      }
      else {
        uVar28 = uVar37;
        uVar29 = (int)uVar5;
        if ((DAT_140e419b8 != 3) &&
           (uVar28 = SUB84(DAT_140539f40,0), uVar29 = (int)((ulonglong)DAT_140539f40 >> 0x20),
           DAT_140e419b8 == 4)) {
          uVar28 = uVar31;
          uVar29 = uVar32;
        }
      }
    }
    if (uVar18 == 0x14) {
      *(short *)(param_1 + 0x11) = (short)(iVar13 / 2);
LAB_1400a66b6:
      iVar15 = (int)(uVar18 - 0x14) % iVar11;
      if ((iVar15 < 0xc) &&
         (iVar15 == (iVar15 / 3 + (iVar15 >> 0x1f) +
                    (int)(((longlong)iVar15 / 3 + ((longlong)iVar15 >> 0x3f) & 0xffffffffU) >> 0x1f)
                    ) * 3)) {
        uVar8 = CONCAT44(uVar24,iVar14);
        auVar46._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar46._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar46._8_4_ = 1;
        auVar47._8_8_ = auVar46._8_8_;
        auVar47._0_8_ = CONCAT44(uVar29,uVar28);
        uVar24 = CONCAT22(uVar42,*(short *)((longlong)param_1 + 0x42) - *(short *)(param_1 + 0x11));
        FUN_1400709b0(7,0,fVar21,fVar22,uVar24,fVar30,CONCAT44(uVar29,uVar28),auVar47._8_8_,uVar8,
                      iVar13,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),iVar14);
        auVar48._12_4_ = auVar47._12_4_;
        auVar48._0_8_ = auVar47._0_8_;
        auVar48._8_4_ = 1;
        in_stack_fffffffffffffeb8._8_8_ = auVar48._8_8_;
        in_stack_fffffffffffffeb8._0_8_ = CONCAT44(uVar29,uVar28);
        uVar35 = CONCAT22((short)((uint)uVar24 >> 0x10),
                          *(short *)((longlong)param_1 + 0x42) + *(short *)(param_1 + 0x11));
        FUN_1400709b0(7,0,fVar23,fVar41,uVar35,fVar30,CONCAT44(uVar29,uVar28),
                      in_stack_fffffffffffffeb8._8_8_,uVar8,iVar13,0);
        fVar34 = DAT_14053ac58;
        uVar24 = (undefined4)((ulonglong)uVar8 >> 0x20);
        uVar42 = (undefined2)((uint)uVar35 >> 0x10);
        iVar12 = DAT_140e419b8;
        dVar26 = DAT_140539f40;
        if ((uVar18 - 0x14 < 0x3c) &&
           (uVar57 = (longlong)(int)(uVar18 - 0x14) % (longlong)iVar11, (int)uVar57 == 0)) {
          uVar8 = CONCAT44(uVar24,iVar14);
          auVar49._12_4_ = in_stack_fffffffffffffeb8._12_4_;
          auVar49._0_8_ = in_stack_fffffffffffffeb8._0_8_;
          auVar49._8_4_ = 1;
          auVar50._8_8_ = auVar49._8_8_;
          auVar50._0_8_ = CONCAT44(uVar29,uVar28);
          uVar24 = CONCAT22(uVar42,*(short *)((longlong)param_1 + 0x42) - *(short *)(param_1 + 0x11)
                           );
          FUN_1400709b0(0xf,uVar57 & 0xffffffff,fVar21,fVar22,uVar24,DAT_14053ac58,
                        CONCAT44(uVar29,uVar28),auVar50._8_8_,uVar8,iVar13,0);
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),iVar14);
          auVar51._12_4_ = auVar50._12_4_;
          auVar51._0_8_ = auVar50._0_8_;
          auVar51._8_4_ = 1;
          in_stack_fffffffffffffeb8._8_8_ = auVar51._8_8_;
          in_stack_fffffffffffffeb8._0_8_ = CONCAT44(uVar29,uVar28);
          uVar35 = CONCAT22((short)((uint)uVar24 >> 0x10),
                            *(short *)((longlong)param_1 + 0x42) + *(short *)(param_1 + 0x11));
          FUN_1400709b0(0xf,0,fVar23,fVar41,uVar35,fVar34,CONCAT44(uVar29,uVar28),
                        in_stack_fffffffffffffeb8._8_8_,uVar8,iVar13,0);
          uVar24 = (undefined4)((ulonglong)uVar8 >> 0x20);
          uVar42 = (undefined2)((uint)uVar35 >> 0x10);
          iVar12 = DAT_140e419b8;
          dVar26 = DAT_140539f40;
        }
      }
    }
    else if (uVar18 - 0x14 < 0x3c) goto LAB_1400a66b6;
    if ((uVar18 - 0x23 < 0x23) && ((int)(uVar18 - 0x23) % iVar11 == 0)) {
      sVar10 = 1;
      if (iVar12 == 0) {
        sVar10 = 5000;
      }
      else if (iVar12 == 1) {
        sVar10 = 3000;
      }
      else if (iVar12 == 2) {
        sVar10 = 0xa8c;
      }
      else if (iVar12 == 3) {
        sVar10 = 0x960;
      }
      else if (iVar12 == 4) {
        sVar10 = 2000;
      }
      *(short *)(param_1 + 0x11) = *(short *)(param_1 + 0x11) + sVar10;
    }
    dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar39),
                                   SUB84((double)(DAT_140e445d8 - fVar40),0));
    dVar27 = dVar27 * DAT_14053aba0;
    iVar11 = 1;
    if (iVar12 == 0) {
      iVar11 = 0x24;
    }
    else if (iVar12 == 1) {
      iVar11 = 0x14;
    }
    else if ((iVar12 == 2) || (iVar12 == 3)) {
      iVar11 = 0x12;
    }
    else if (iVar12 == 4) {
      iVar11 = 0x10;
    }
    uVar28 = 1;
    if (iVar12 == 0) {
      uVar28 = 5;
    }
    else if (iVar12 == 1) {
LAB_1400a691c:
      uVar28 = 9;
    }
    else {
      if (iVar12 != 2) {
        if (iVar12 == 3) goto LAB_1400a691c;
        if (iVar12 != 4) goto LAB_1400a6928;
      }
      uVar28 = 0xb;
    }
LAB_1400a6928:
    if (iVar12 == 0) {
      uVar31 = SUB84(DAT_14053a0f8,0);
      uVar32 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
    }
    else if (iVar12 == 1) {
      uVar31 = SUB84(DAT_14053a178,0);
      uVar32 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else if (((iVar12 != 2) && (iVar12 != 3)) &&
            (uVar31 = SUB84(dVar26,0), uVar32 = (int)((ulonglong)dVar26 >> 0x20), iVar12 == 4)) {
      uVar31 = (undefined4)DAT_14053a218;
      uVar32 = (undefined4)((ulonglong)DAT_14053a218 >> 0x20);
    }
    if (uVar18 - 0x32 < 0x32) {
      if ((int)(uVar18 - 0x32) % iVar11 == 0) {
        uVar8 = CONCAT44(uVar24,uVar28);
        auVar52._12_4_ = in_stack_fffffffffffffeb8._12_4_;
        auVar52._0_8_ = in_stack_fffffffffffffeb8._0_8_;
        auVar52._8_4_ = 1;
        auVar53._8_8_ = auVar52._8_8_;
        auVar53._0_8_ = CONCAT44(uVar32,uVar31);
        FUN_1400709b0(2,7,fVar40,fVar39,CONCAT22(uVar42,(short)(int)dVar27),fVar30,
                      CONCAT44(uVar32,uVar31),auVar53._8_8_,uVar8,27000,0);
        uVar24 = (undefined4)((ulonglong)uVar8 >> 0x20);
        if (2 < DAT_140e419b8) {
          uVar8 = CONCAT44(uVar24,uVar28);
          auVar54._12_4_ = auVar53._12_4_;
          auVar54._0_8_ = auVar53._0_8_;
          auVar54._8_4_ = 1;
          FUN_1400709b0(2,7,fVar40,fVar39,(int)dVar27 & 0xffff,fVar30,
                        (double)CONCAT44(uVar32,uVar31) + DAT_140539f90,auVar54._8_8_,uVar8,27000,0)
          ;
          uVar24 = (undefined4)((ulonglong)uVar8 >> 0x20);
        }
      }
    }
    else if (99 < (int)uVar18) {
      uVar1 = *(ushort *)((longlong)param_1 + 0x42);
      uVar6 = uVar16 - uVar1;
      uVar18 = (uint)uVar6;
      if (0x8000 < uVar6) {
        uVar18 = 0x10000 - uVar6;
      }
      iVar11 = (uVar17 & 0xffff) - (uint)uVar1;
      iVar14 = (int)uVar18 / 0x14 + 0x30;
      iVar12 = iVar11 + 0x10000;
      if (-0x8001 < iVar11) {
        iVar12 = iVar11;
      }
      iVar11 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar11 = iVar12;
      }
      if (iVar11 < 1) {
        uVar6 = uVar1;
        if ((iVar11 < 0) && (uVar6 = uVar1 - (short)iVar14, -iVar14 < iVar11)) {
          uVar6 = uVar16;
        }
      }
      else {
        uVar6 = uVar16;
        if (iVar14 <= iVar11) {
          uVar6 = uVar1 + (short)iVar14;
        }
      }
      *(ushort *)((longlong)param_1 + 0x42) = uVar6;
    }
  }
  uVar8 = _UNK_14053bb28;
  dVar27 = _DAT_14053bb20;
  dVar26 = _DAT_14053bb20;
  if (DAT_140e418c8 % 0x29 < 9) {
    dVar26 = (double)FUN_140332d90(((double)(DAT_140e418c8 % 0x29) - 0.0) * DAT_14053aad0 *
                                   DAT_14053a020 * DAT_140539d28);
    dVar26 = dVar26 * DAT_140539e60 + dVar27;
  }
  uVar29 = (undefined4)((ulonglong)dVar26 >> 0x20);
  uVar28 = SUB84(dVar26,0);
  uVar17 = 0;
  iVar12 = FUN_1400c9580(param_1[3],0,5,2,0x5e,0x5f);
  fVar33 = DAT_14053ad10;
  fVar34 = DAT_14053acf0;
  uVar56 = CONCAT44(uVar24,0xff);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar12],0x1a,7,(float)param_1[10] + DAT_14053acf0,
                (float)param_1[0xb] + DAT_14053ad10,uVar17,dVar27,uVar8,uVar56,0xff,0xff,0xff,1,0);
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar12],0x1a,7,(float)param_1[10] - fVar34,
                (float)param_1[0xb] + fVar33,uVar17,dVar27,uVar8,uVar56,0xff,0xff,0xff,1,0);
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410(DAT_140e44ca8,0x1a,7,param_1[10],(float)param_1[0xb] + DAT_14053aa20 + fVar20,uVar17
                ,dVar27,uVar8,uVar56,0xff,0xff,0xff,1,0);
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410(DAT_140e44cac,0x1a,7,(float)param_1[10] + fVar34,
                (float)param_1[0xb] + fVar30 + fVar20,uVar17,dVar27,uVar8,uVar56,0xff,0xff,0xff,1,0)
  ;
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410(DAT_140e44cac,0x1a,7,(float)param_1[10] - fVar34,
                (float)param_1[0xb] + fVar30 + fVar20,uVar17,dVar27,uVar8,uVar56,0xff,0xff,0xff,1,0)
  ;
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  uVar24 = CONCAT22((short)(uVar17 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -0x4000);
  FUN_1400c8410(DAT_140e44cb0,0x1b,7,param_1[10],fVar38 + (float)param_1[0xb],uVar24,dVar27,uVar8,
                uVar56,0xff,0xff,0xff,1,0);
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  auVar2._8_4_ = uVar28;
  auVar2._0_8_ = dVar26;
  auVar2._12_4_ = uVar29;
  uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -0x4000);
  FUN_1400c8410(DAT_140e44cb4,0x1b,7,fVar40,fVar39,uVar24,auVar2,uVar56,0xff,0xff,0xff,1,0);
  uVar56 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  auVar3._8_4_ = uVar28;
  auVar3._0_8_ = dVar26;
  auVar3._12_4_ = uVar29;
  uVar24 = CONCAT22((short)((uint)uVar24 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -0x4000);
  FUN_1400c8410(DAT_140e44cb8,0x1b,7,fVar21,fVar22,uVar24,auVar3,uVar56,0xff,0xff,0xff,1,0);
  uVar57 = CONCAT44((int)((ulonglong)uVar56 >> 0x20),0xff);
  auVar4._8_4_ = uVar28;
  auVar4._0_8_ = dVar26;
  auVar4._12_4_ = uVar29;
  uVar17 = CONCAT22((short)((uint)uVar24 >> 0x10),*(short *)((longlong)param_1 + 0x42) + -0x4000);
  FUN_1400c8410(DAT_140e44cb8,0x1b,7,fVar23,fVar41,uVar17,auVar4,uVar57,0xff,0xff,0xff,1,1);
  uVar17 = uVar17 & 0xffff0000;
  FUN_1400c8410(DAT_140e44ca8,0x17,7,param_1[10],(float)param_1[0xb] + DAT_14053ac58 + fVar20,uVar17
                ,dVar27,uVar8,uVar57 & 0xffffffff00000000,0,0x20,0x40,1,0);
  uVar24 = DAT_140e4195c;
  uVar42 = (undefined2)(uVar17 >> 0x10);
  fVar20 = (float)param_1[0xb];
  fVar38 = ((float)param_1[10] + fVar34) - DAT_140e45d24;
  puVar9 = DAT_140e45d28;
  iVar12 = DAT_140e45d1c;
  if (DAT_140e45d1c < 0x1000) {
    puVar9 = (undefined8 *)_malloc_base(0x60);
    if (puVar9 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar12 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar9 + 0x14) = fVar38;
    bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar9 + 3) = fVar20 + fVar33;
    *(float *)((longlong)puVar9 + 0x1c) = fVar38;
    *(float *)(puVar9 + 4) = fVar20 + fVar33;
    *puVar9 = 1;
    *(undefined4 *)(puVar9 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar9 + 0xc) = uVar24;
    *(undefined4 *)(puVar9 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
    puVar9[5] = 0;
    puVar9[6] = 0x3ff0000000000000;
    puVar9[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar9 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
    *(undefined4 *)(puVar9 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
    puVar9[10] = 0x80;
    puVar9[0xb] = 0;
    if (bVar19) {
      DAT_140e45d78 = puVar9;
    }
    DAT_140e45d1c = iVar12;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar9;
    }
  }
  DAT_140e45d28 = puVar9;
  uVar24 = DAT_140e4195c;
  fVar20 = (float)param_1[0xb];
  fVar38 = ((float)param_1[10] - fVar34) - DAT_140e45d24;
  puVar9 = DAT_140e45d28;
  if (iVar12 < 0x1000) {
    puVar9 = (undefined8 *)_malloc_base(0x60);
    if (puVar9 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    iVar12 = DAT_140e45d1c + 1;
    *(float *)((longlong)puVar9 + 0x14) = fVar38;
    bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
    *(float *)(puVar9 + 3) = fVar20 + fVar33;
    *(float *)((longlong)puVar9 + 0x1c) = fVar38;
    *(float *)(puVar9 + 4) = fVar20 + fVar33;
    *puVar9 = 1;
    *(undefined4 *)(puVar9 + 1) = 0x39;
    *(undefined4 *)((longlong)puVar9 + 0xc) = uVar24;
    *(undefined4 *)(puVar9 + 2) = 0x16;
    *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
    puVar9[5] = 0;
    puVar9[6] = 0x3ff0000000000000;
    puVar9[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar9 + 8) = 0x18;
    *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
    *(undefined4 *)(puVar9 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
    puVar9[10] = 0x80;
    puVar9[0xb] = 0;
    if (bVar19) {
      DAT_140e45d78 = puVar9;
    }
    DAT_140e45d1c = iVar12;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar9;
    }
  }
  DAT_140e45d28 = puVar9;
  uVar24 = DAT_140e41a50;
  puVar9 = DAT_140e45d28;
  if (DAT_140e418c8 == (DAT_140e418c8 / 0x29) * 0x29) {
    uVar28 = param_1[1];
    fVar20 = (float)param_1[0xb];
    fVar38 = (float)param_1[10];
    if (iVar12 < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar12 = DAT_140e45d1c + 1;
      *(float *)((longlong)puVar9 + 0x14) = fVar40 - fVar38;
      bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar9 + 3) = fVar39 - fVar20;
      *(float *)((longlong)puVar9 + 0x1c) = fVar40 - fVar38;
      *(float *)(puVar9 + 4) = fVar39 - fVar20;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 0x25;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar24;
      *(undefined4 *)(puVar9 + 2) = 0x1e;
      *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff8000000000000;
      puVar9[7] = 0x3ff8000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      *(undefined4 *)(puVar9 + 10) = 0x80;
      *(undefined4 *)((longlong)puVar9 + 0x54) = uVar28;
      puVar9[0xb] = 0;
      if (bVar19) {
        DAT_140e45d78 = puVar9;
      }
      DAT_140e45d1c = iVar12;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
    DAT_140e45d28 = puVar9;
    uVar28 = DAT_140e41a50;
    uVar24 = param_1[1];
    fVar20 = (float)param_1[0xb];
    fVar38 = (float)param_1[10];
    puVar9 = DAT_140e45d28;
    if (iVar12 < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar12 = DAT_140e45d1c + 1;
      *(float *)((longlong)puVar9 + 0x14) = fVar21 - fVar38;
      bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)(puVar9 + 3) = fVar22 - fVar20;
      *(float *)((longlong)puVar9 + 0x1c) = fVar21 - fVar38;
      *(float *)(puVar9 + 4) = fVar22 - fVar20;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 0x25;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar28;
      *(undefined4 *)(puVar9 + 2) = 0x1e;
      *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff8000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      *(undefined4 *)(puVar9 + 10) = 0x80;
      *(undefined4 *)((longlong)puVar9 + 0x54) = uVar24;
      puVar9[0xb] = 0;
      if (bVar19) {
        DAT_140e45d78 = puVar9;
      }
      DAT_140e45d1c = iVar12;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
    DAT_140e45d28 = puVar9;
    uVar28 = DAT_140e41a50;
    uVar24 = param_1[1];
    fVar20 = (float)param_1[0xb];
    fVar38 = (float)param_1[10];
    puVar9 = DAT_140e45d28;
    if (iVar12 < 0x1000) {
      puVar9 = (undefined8 *)_malloc_base(0x60);
      if (puVar9 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar19 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar9 + 0x14) = fVar23 - fVar38;
      *(float *)(puVar9 + 3) = fVar41 - fVar20;
      *(float *)((longlong)puVar9 + 0x1c) = fVar23 - fVar38;
      *(float *)(puVar9 + 4) = fVar41 - fVar20;
      *puVar9 = 1;
      *(undefined4 *)(puVar9 + 1) = 0x25;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar28;
      *(undefined4 *)(puVar9 + 2) = 0x1e;
      *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
      puVar9[5] = 0;
      puVar9[6] = 0x3ff0000000000000;
      puVar9[7] = 0x3ff8000000000000;
      *(undefined4 *)(puVar9 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
      *(undefined4 *)(puVar9 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
      *(undefined4 *)(puVar9 + 10) = 0x80;
      *(undefined4 *)((longlong)puVar9 + 0x54) = uVar24;
      puVar9[0xb] = 0;
      if (bVar19) {
        DAT_140e45d78 = puVar9;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar9;
      }
    }
  }
  DAT_140e45d28 = puVar9;
  FUN_140079c10(param_1,1);
  if ((int)param_1[3] % 0xe == 1) {
    FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472f0);
    FUN_14018a340(DAT_140e472f0,1,1);
  }
LAB_1400a7591:
  if ((int)param_1[7] < 1) {
    uVar18 = param_1[1] + DAT_140e418c8;
    uVar17 = (uVar18 >> 0x1e ^ uVar18) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar17 >> 0x1e ^ uVar17) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar17 = uVar17 * 0x800 ^ uVar17;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar17 = (DAT_140e9fd18 >> 0xb ^ uVar17) >> 8 ^ uVar17 ^ DAT_140e9fd18;
    DAT_140e9fd1c = uVar17;
    uVar8 = FUN_140134db0(uVar18,(int)DAT_140539f18,DAT_140539f28);
    uVar24 = (undefined4)uVar8;
    uVar28 = (undefined4)((ulonglong)uVar8 >> 0x20);
    uVar8 = FUN_140134db0(param_1[1] + DAT_140e418c8);
    FUN_140070d00(0x38,DAT_140e45090,0x15,(float)param_1[10] - DAT_140e45d24,param_1[0xb],
                  CONCAT22(uVar42,(short)uVar17 - (short)(uVar17 / 0x10001)),DAT_140539f40,uVar8,
                  CONCAT44(uVar28,uVar24),0x78,0xff,0xff,0xff,0xc0,0);
    FUN_14007b010(param_1,800,0x18);
    FUN_140079e20(param_1,2);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3bc || (DAT_14053af80 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


