// Function: FUN_140041e90 @ 140041e90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140041e90(undefined4 *param_1)

{
  float fVar1;
  byte bVar2;
  longlong lVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 uVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  short sVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  undefined4 in_stack_fffffffffffffe68;
  undefined2 uVar28;
  undefined4 uVar27;
  uint in_stack_fffffffffffffe70;
  undefined8 in_stack_fffffffffffffe80;
  undefined8 uVar29;
  longlong lStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 uStack_f0;
  
  dVar4 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  iVar12 = 0;
  uStack_130 = 0;
  uStack_130._4_4_ = 0;
  lVar3 = DAT_140e45d80;
  fVar1 = uStack_110._4_4_;
  iVar16 = local_138._4_4_;
  iVar17 = uStack_f0._4_4_;
  iVar13 = uStack_130._4_4_;
  if (0 < DAT_140e44e6c) {
    while( true ) {
      fVar1 = (float)((ulonglong)uStack_110 >> 0x20);
      iVar16 = (int)((ulonglong)local_138 >> 0x20);
      iVar17 = (int)((ulonglong)uStack_f0 >> 0x20);
      iVar13 = (int)((ulonglong)uStack_130 >> 0x20);
      if (lVar3 == 0) break;
      if (*(int *)(lVar3 + 4) == DAT_140e44308) {
        local_138 = *(undefined8 *)(lVar3 + 0x10);
        uStack_130 = *(undefined8 *)(lVar3 + 0x18);
        lStack_140 = *(longlong *)(lVar3 + 8);
        local_118 = *(undefined8 *)(lVar3 + 0x30);
        uStack_110 = *(undefined8 *)(lVar3 + 0x38);
        uStack_f0 = *(undefined8 *)(lVar3 + 0x58);
      }
      lVar3 = *(longlong *)(lVar3 + 0x60);
    }
  }
  uStack_130._4_4_ = iVar13;
  uStack_f0._4_4_ = iVar17;
  local_138._4_4_ = iVar16;
  uStack_110._4_4_ = fVar1;
  fVar1 = (float)param_1[0xe];
  fVar25 = local_118._4_4_ + uStack_110._4_4_ + (float)param_1[0xf];
  local_118._0_4_ = fVar1 + (float)local_118;
  param_1[0xd] = fVar25;
  param_1[0xc] = (float)local_118;
  dVar19 = (double)FUN_140332d90();
  fVar26 = (float)(dVar19 * DAT_14053a018) + (fVar25 - _DAT_14053ad28);
  dVar20 = (double)FUN_140332d90();
  uVar8 = _UNK_14053bb28;
  dVar7 = _DAT_14053bb20;
  dVar19 = DAT_14053a0f8;
  fVar23 = fVar25 - DAT_14053adcc;
  dVar20 = dVar20 * DAT_14053a0f8;
  param_1[10] = (float)local_118;
  param_1[0xb] = fVar26;
  if (param_1[5] == 0) {
    if (fVar25 < DAT_14053b390) goto LAB_140042a1d;
    param_1[5] = 1;
    param_1[3] = 0;
  }
  else if (param_1[5] != 1) goto LAB_140042a1d;
  dVar21 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar26),
                                 (double)(DAT_140e445d8 - (float)local_118));
  uVar28 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
  uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffe80 >> 0x20);
  dVar21 = dVar21 * DAT_14053aba0;
  iVar16 = (int)((ulonglong)lStack_140 >> 0x20);
  if (local_138._4_4_ == 1) {
    iVar17 = (iVar16 + -0x1e) % 0x708;
    if (param_1[0x15] == 1) {
      param_1[0x15] = 0;
    }
    uVar14 = DAT_14053ac80;
    dVar6 = DAT_14053a0d0;
    dVar5 = DAT_14053a0a0;
    sVar9 = (short)(int)dVar21;
    if (iVar17 < 0x280) {
      uVar15 = 1;
      if (DAT_140e419b8 == 0) {
        uVar15 = 4;
      }
      else if (DAT_140e419b8 == 1) {
        uVar15 = 6;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar15 = 8;
      }
      else if (DAT_140e419b8 == 4) {
        uVar15 = 10;
      }
      sVar18 = 1;
      if (DAT_140e419b8 == 0) {
        sVar18 = 200;
      }
      else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
        sVar18 = 0xf0;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        sVar18 = 300;
      }
      dVar21 = DAT_14053a0a0;
      if ((((DAT_140e419b8 != 0) && (dVar21 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
          (dVar21 = dVar19, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar21 = dVar7, DAT_140e419b8 == 4)))) {
        dVar21 = DAT_14053a138;
      }
      bVar2 = 0;
      iVar13 = 0;
      dVar24 = (double)iVar17 * DAT_140539da0;
      do {
        if (iVar17 == iVar12) {
          *(short *)((longlong)param_1 + 0x42) = sVar9;
LAB_140042225:
          iVar10 = iVar12 + 0x14 + iVar13;
          if ((iVar17 < iVar10) || (iVar10 == 0)) {
            uVar11 = iVar17 - iVar12 & 0x80000003;
            if ((int)uVar11 < 0) {
              uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
            }
            if (uVar11 == 0) {
              if (uStack_f0._4_4_ < 2) {
LAB_140042276:
                in_stack_fffffffffffffe80 =
                     CONCAT44((int)((ulonglong)in_stack_fffffffffffffe80 >> 0x20),1);
                in_stack_fffffffffffffe68 =
                     CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),
                              *(undefined2 *)((longlong)param_1 + 0x42));
                in_stack_fffffffffffffe70 = uVar14;
                FUN_1400709b0(0xd,0,param_1[10],param_1[0xb],in_stack_fffffffffffffe68,uVar14,
                              dVar24 + dVar21,in_stack_fffffffffffffe80,uVar15,30000,0);
                FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
                FUN_14018a340(DAT_140e472a4,1,1);
                if (bVar2 == 0) {
                  *(short *)((longlong)param_1 + 0x42) =
                       *(short *)((longlong)param_1 + 0x42) + sVar18;
                }
                else {
                  *(short *)((longlong)param_1 + 0x42) =
                       *(short *)((longlong)param_1 + 0x42) - sVar18;
                }
              }
              else if (fVar1 < 0.0) {
                if ((bool)(bVar2 & 1)) goto LAB_140042276;
              }
              else if (bVar2 == 0) goto LAB_140042276;
            }
          }
        }
        else if (iVar12 <= iVar17) goto LAB_140042225;
        uVar28 = (undefined2)((uint)in_stack_fffffffffffffe68 >> 0x10);
        uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffe80 >> 0x20);
        bVar2 = bVar2 + 1;
        iVar12 = iVar12 + 0x38 + iVar13;
        iVar13 = iVar13 + 4;
      } while (iVar13 < 0x24);
    }
    if (iVar17 - 0x2a8U < 0x118) {
      iVar13 = 1;
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        iVar13 = 0x96;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar13 = 100;
      }
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 7;
      }
      else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
        iVar12 = 0xb;
      }
      else if (DAT_140e419b8 == 3) {
        iVar12 = 0xd;
      }
      else if (DAT_140e419b8 == 4) {
        iVar12 = 0xf;
      }
      uVar14 = (int)(iVar17 - 0x2a8U) % iVar13;
      dVar21 = DAT_14053a078;
      if (((DAT_140e419b8 != 0) && (dVar21 = dVar5, DAT_140e419b8 != 1)) &&
         ((dVar21 = dVar6, DAT_140e419b8 != 2 &&
          ((DAT_140e419b8 != 3 && (dVar21 = dVar7, DAT_140e419b8 == 4)))))) {
        dVar21 = dVar19;
      }
      dVar19 = (((double)iVar17 - _DAT_14053a828) * _DAT_140539dc0 + dVar21) -
               (double)(int)uVar14 * DAT_140539e20;
      if (uStack_f0._4_4_ < 2) {
        iVar12 = iVar12 + 2;
      }
      if ((int)uVar14 < 0x30) {
        uVar11 = uVar14 & 0x8000000f;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffff0) + 1;
        }
        if (uVar11 == 0) {
          iVar10 = iVar12 * 400 + -400;
          iVar13 = iVar10;
          if ((-1 < (int)uVar14) && (iVar13 = 0x8000, (int)uVar14 < 0x28)) {
            dVar21 = (double)FUN_140332d90(DAT_140e419b8,
                                           ((double)(int)uVar14 - 0.0) * DAT_14053a6d8 * dVar4 *
                                           dVar22);
            iVar13 = (int)(dVar21 * (double)(0x8000 - iVar10)) + iVar10;
          }
          uVar14 = DAT_14053ac2c;
          uVar29 = CONCAT44(uVar27,1);
          uVar27 = CONCAT22(uVar28,sVar9);
          in_stack_fffffffffffffe70 = DAT_14053ac2c;
          FUN_1400709b0(2,0,param_1[10],param_1[0xb],uVar27,DAT_14053ac2c,dVar19,uVar29,iVar12,
                        iVar13,0);
          uVar28 = (undefined2)((uint)uVar27 >> 0x10);
          uVar27 = (undefined4)((ulonglong)uVar29 >> 0x20);
          if ((2 < DAT_140e419b8) && (iVar17 + -0x2a8 == ((iVar17 + -0x2a8) / 100) * 100)) {
            uVar29 = CONCAT44(uVar27,1);
            uVar27 = CONCAT22(uVar28,sVar9);
            FUN_1400709b0(2,0,param_1[10],param_1[0xb],uVar27,uVar14,dVar19 + dVar7,uVar29,
                          iVar12 + -2,(iVar13 / (iVar12 + -2)) * (iVar12 + -3) & 0xffff,0);
            uVar28 = (undefined2)((uint)uVar27 >> 0x10);
            uVar27 = (undefined4)((ulonglong)uVar29 >> 0x20);
            in_stack_fffffffffffffe70 = uVar14;
          }
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
    if (iVar17 - 1000U < 0x2e4) {
      iVar13 = 1;
      if (DAT_140e419b8 == 0) {
        iVar13 = 0xa0;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0x78;
      }
      else if (DAT_140e419b8 == 2) {
        iVar13 = 100;
      }
      else if (DAT_140e419b8 == 3) {
        iVar13 = 0x55;
      }
      else if (DAT_140e419b8 == 4) {
        iVar13 = 0x48;
      }
      iVar12 = 1;
      if (DAT_140e419b8 == 0) {
        iVar12 = 8;
      }
      else if (DAT_140e419b8 == 1) {
        iVar12 = 0xc;
      }
      else if (DAT_140e419b8 == 2) {
        iVar12 = 0xe;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar12 = 0x10;
      }
      uVar14 = (int)(iVar17 - 1000U) % iVar13;
      if ((int)uVar14 < 0x28) {
        uVar11 = uVar14 & 0x80000007;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
        }
        if (uVar11 == 0) {
          in_stack_fffffffffffffe70 = 0;
          FUN_1400709b0(2,9,param_1[10],param_1[0xb],CONCAT22(uVar28,sVar9 + -0x8000),0,
                        (double)(int)uVar14 * DAT_140539ee0 + DAT_14053a070,CONCAT44(uVar27,1),
                        iVar12,iVar12 * 0xd05 + -0xd05,0);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
      }
    }
  }
  in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d5c,0x1f,7,param_1[0xc],param_1[0xd],in_stack_fffffffffffffe70,dVar7,uVar8
                ,0xff,0xff,0xff,0xff,1,0);
  in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d60,0x1f,7,param_1[0xc],fVar26,in_stack_fffffffffffffe70,dVar7,uVar8,0xff,
                0xff,0xff,0xff,1,0);
  dVar19 = DAT_14053a578;
  if (iVar16 < 0x18) {
    iVar17 = 0xc0;
    if (lStack_140 < 0) {
      iVar17 = 0;
    }
    else {
      if (iVar16 < 4) {
        dVar21 = (double)FUN_140332d90(((double)iVar16 - 0.0) * DAT_14053aad0 * dVar4 * dVar22);
        iVar17 = (int)(dVar21 * dVar19);
      }
      if (-1 < lStack_140) {
        dVar22 = (double)FUN_140332d90(((double)iVar16 - _DAT_14053b118) * DAT_14053a830 * dVar4 *
                                       dVar22);
        iVar17 = (int)(dVar22 * dVar19);
      }
    }
    in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
    FUN_1400c8410(DAT_140e44d60,0x1f,8,param_1[0xc],fVar26,in_stack_fffffffffffffe70,dVar7,uVar8,
                  0xff,0xff,0xff,iVar17,1,0);
  }
  in_stack_fffffffffffffe70 = in_stack_fffffffffffffe70 & 0xffff0000;
  uVar29 = uVar8;
  FUN_1400c8410(DAT_140e44d64,0x1f,7,param_1[0xc],(float)dVar20 + fVar23,in_stack_fffffffffffffe70,
                dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  uVar27 = (undefined4)((ulonglong)uVar29 >> 0x20);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  uVar28 = (undefined2)(in_stack_fffffffffffffe70 >> 0x10);
  if ((((int)param_1[7] < 1) || (uStack_130._4_4_ < 0xc351)) || (9 < local_138._4_4_)) {
    param_1[0x14] = 0x78;
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,4000,0x1e);
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar28,0x4000),dVar7,
                 CONCAT44(uVar27,10),1,DAT_140e44308);
      iVar16 = DAT_140e44308;
      lVar3 = DAT_140e45d80;
      if (0 < DAT_140e44e6c) {
        for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
          if (*(int *)(lVar3 + 4) == iVar16) {
            *(int *)(lVar3 + 0x5c) = *(int *)(lVar3 + 0x5c) + -1;
          }
        }
      }
      in_stack_fffffffffffffe70 = 0;
      FUN_140109660(0x19);
    }
    FUN_140079e20(param_1,2);
    param_1[5] = param_1[5] + 1;
    param_1[3] = 0;
    param_1[0x15] = 1;
  }
LAB_140042a1d:
  if (param_1[5] == 2) {
    FUN_1400c8410(DAT_140e44d74,0x1f,7,param_1[0xc],param_1[0xd],
                  in_stack_fffffffffffffe70 & 0xffff0000,dVar7,uVar8,0xff,0xff,0xff,0xff,1,0);
  }
  if ((_DAT_14053af88 <= (float)param_1[0xb]) || (0x13 < local_138._4_4_)) {
    *param_1 = 0;
  }
  return;
}


