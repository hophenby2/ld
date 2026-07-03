// Function: FUN_140032740 @ 140032740
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140032740(undefined4 *param_1)

{
  longlong lVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  undefined8 uVar18;
  double dVar19;
  double dVar20;
  undefined4 uVar21;
  float fVar22;
  float fVar23;
  uint in_stack_fffffffffffffeb0;
  uint uVar24;
  undefined8 in_stack_fffffffffffffec0;
  undefined4 uVar26;
  undefined8 uVar25;
  undefined8 uStack_100;
  int iStack_f4;
  int iStack_ec;
  undefined8 uStack_e0;
  
  lVar5 = DAT_140e45d80;
  iVar14 = DAT_140e44e6c;
  iVar7 = DAT_140e44308;
  uVar26 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);
  uVar8 = (undefined2)(in_stack_fffffffffffffeb0 >> 0x10);
  iStack_ec = 0;
  iVar16 = 0;
  lVar1 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_ec = iVar16, lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
      if (*(int *)(lVar1 + 4) == DAT_140e44308) {
        uStack_100 = *(undefined8 *)(lVar1 + 8);
        iStack_f4 = *(int *)(lVar1 + 0x14);
        iStack_ec = *(int *)(lVar1 + 0x1c);
        uStack_e0 = *(undefined8 *)(lVar1 + 0x28);
      }
      iVar16 = iStack_ec;
    }
  }
  iVar16 = param_1[6];
  uStack_e0._0_4_ = (float)uStack_e0 + (float)param_1[0xc];
  uVar3 = 0x82;
  if (iVar16 != 0x86) {
    uVar3 = 0x7e;
  }
  iVar12 = 1;
  iVar4 = 1;
  param_1[10] = (float)uStack_e0;
  param_1[0xb] = uStack_e0._4_4_ + (float)param_1[0xd];
  fVar2 = DAT_14053aca4;
  iVar13 = 1;
  if (iStack_f4 == 1) {
    iVar6 = uStack_100._4_4_ % 0xa28;
    iVar15 = 0x834;
    if (iVar16 != 0x86) {
      iVar15 = 0x79e;
    }
    iVar11 = 0x1e0;
    if (iVar16 != 0x86) {
      iVar11 = 0x3c;
    }
    iVar4 = iVar12;
    if ((iVar11 <= iVar6) && (iVar6 < 600)) {
      if (DAT_140e419b8 == 0) {
        iVar13 = 0x14;
      }
      else if (DAT_140e419b8 == 1) {
        iVar13 = 0x10;
      }
      else if (DAT_140e419b8 == 2) {
        iVar13 = 0xe;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar13 = 0xc;
      }
      if (iVar16 == 0x86) {
        if (DAT_140e419b8 == 0) {
          iVar13 = 0x12;
        }
        else if (DAT_140e419b8 == 1) {
          iVar13 = 0xe;
        }
        else if (DAT_140e419b8 == 2) {
          iVar13 = 0xc;
        }
        else if ((DAT_140e419b8 == 3) || (iVar13 = 1, DAT_140e419b8 == 4)) {
          iVar13 = 9;
        }
      }
      if (iVar6 < iVar11 + 0x78) {
        if ((iVar6 - iVar11) % iVar13 == 0) {
          uVar21 = (undefined4)DAT_14053a070;
          if (iVar16 == 0x85) {
            uVar24 = param_1[3];
            uVar9 = (uVar24 >> 0x1e ^ uVar24) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar9 = uVar9 * 0x800 ^ uVar9;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            uVar9 = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
            DAT_140e9fd1c = uVar9;
            uVar18 = FUN_140134db0(uVar24,uVar21,DAT_14053a138);
            uVar25 = CONCAT44(uVar26,0x14);
            in_stack_fffffffffffffeb0 =
                 CONCAT22(uVar8,(short)((ulonglong)uVar9 / 0x8001) * 0x7fff + (short)uVar9);
            stage_entity_spawn_candidate
                      (0x8b,900,5,(float)uStack_e0,(float)param_1[0xb] + fVar2,
                       in_stack_fffffffffffffeb0,uVar18,uVar25,1,0);
            uVar26 = (undefined4)((ulonglong)uVar25 >> 0x20);
          }
          uVar8 = (undefined2)(in_stack_fffffffffffffeb0 >> 0x10);
          if (param_1[6] == 0x86) {
            uVar24 = param_1[3];
            uVar10 = (uVar24 >> 0x1e ^ uVar24) * 0x6c078965 + 1;
            uVar9 = uVar10 * 0x800 ^ uVar10;
            DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            uVar9 = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
            DAT_140e9fd1c = uVar9;
            uVar18 = FUN_140134db0(uVar24,uVar21,DAT_14053a218);
            uVar25 = CONCAT44(uVar26,0x14);
            in_stack_fffffffffffffeb0 =
                 CONCAT22(uVar8,(short)((ulonglong)uVar9 / 0x8001) * 0x7fff + (short)uVar9);
            stage_entity_spawn_candidate
                      (0x8c,900,5,param_1[10],(float)param_1[0xb] + fVar2,in_stack_fffffffffffffeb0,
                       uVar18,uVar25,1,0);
            uVar26 = (undefined4)((ulonglong)uVar25 >> 0x20);
          }
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472a8);
          FUN_14018a340(DAT_140e472a8,1,1);
          lVar5 = DAT_140e45d80;
          iVar7 = DAT_140e44308;
          iVar14 = DAT_140e44e6c;
        }
        iVar4 = 3;
      }
      else {
        iVar13 = 0x262;
        if (iVar16 != 0x86) {
          iVar13 = 0xbe;
        }
        if (iVar6 < iVar13) {
          in_stack_fffffffffffffeb0 = 0;
          uVar18 = 0x276;
          if (iVar16 != 0x86) {
            uVar18 = 0xd2;
          }
          iVar4 = FUN_1400c9580(iVar6,uVar18,5,2,2,1);
        }
      }
    }
    if ((iVar15 <= iVar6) && (iVar6 < 0x992)) {
      fVar22 = (float)param_1[0xb];
      fVar23 = (float)param_1[10];
      dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (fVar22 + fVar2)),
                                     SUB84((double)(DAT_140e445d8 - fVar23),0));
      uVar18 = DAT_14053a0b0;
      iVar16 = (iVar6 - iVar15) % 300;
      if ((iVar15 + 0x14 <= iVar6) &&
         (iVar6 = iVar6 - (iVar15 + 0x14), iVar6 == (iVar6 / 300) * 300)) {
        uVar8 = (undefined2)(int)(dVar19 * DAT_14053aba0);
        if (param_1[6] == 0x85) {
          uVar25 = CONCAT44(uVar26,0x14);
          in_stack_fffffffffffffeb0 = CONCAT22((short)(in_stack_fffffffffffffeb0 >> 0x10),uVar8);
          stage_entity_spawn_candidate
                    (0x8d,0xe10,0xc,fVar23,fVar22 + fVar2,in_stack_fffffffffffffeb0,DAT_14053a0b0,
                     uVar25,1,0);
          uVar26 = (undefined4)((ulonglong)uVar25 >> 0x20);
          fVar22 = (float)param_1[0xb];
          fVar23 = (float)param_1[10];
        }
        if (param_1[6] == 0x86) {
          in_stack_fffffffffffffeb0 = CONCAT22((short)(in_stack_fffffffffffffeb0 >> 0x10),uVar8);
          stage_entity_spawn_candidate
                    (0x8e,0xe10,0xc,fVar23,fVar22 + fVar2,in_stack_fffffffffffffeb0,uVar18,
                     CONCAT44(uVar26,0x14),1,0);
        }
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472bc);
        FUN_14018a340(DAT_140e472bc,1,1);
        lVar5 = DAT_140e45d80;
        iVar7 = DAT_140e44308;
        iVar14 = DAT_140e44e6c;
      }
      if (iVar16 < 10) {
        in_stack_fffffffffffffeb0 = 0;
        iVar4 = FUN_1400c9580(iVar16,0,5,2,2,3);
      }
      else if (iVar16 < 0x3c) {
        iVar4 = 3;
      }
      else if (iVar16 < 0x46) {
        in_stack_fffffffffffffeb0 = 0;
        iVar4 = FUN_1400c9580(iVar16,0x3c,5,2,2,1);
      }
    }
    if (uStack_100._4_4_ == 1) {
      param_1[8] = DAT_140e41b0c;
      param_1[7] = iStack_ec;
      param_1[0x15] = 0;
    }
    iVar16 = param_1[7];
    if ((iVar16 < iStack_ec) && (lVar1 = lVar5, 0 < iVar14)) {
      for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x60)) {
        if (*(int *)(lVar1 + 4) == iVar7) {
          *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) - (iStack_ec - iVar16);
        }
      }
    }
    iVar16 = param_1[7];
    if (iStack_ec < iVar16) {
      param_1[7] = iStack_ec;
      iVar16 = iStack_ec;
    }
    if ((iVar16 < 1) && (0 < iVar14)) {
      for (; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x60)) {
        if (*(int *)(lVar5 + 4) == iVar7) {
          *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) - iStack_ec;
        }
      }
    }
  }
  dVar20 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a880 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar19 = DAT_140539f40;
  uVar24 = in_stack_fffffffffffffeb0 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44ad0)[uVar3],0x1d,7,param_1[10],param_1[0xb],uVar24,
                dVar20 * _DAT_140539e28 + DAT_140539f40,DAT_140539f40,0xff,0xff,0xff,0xff,1,0);
  dVar20 = (double)FUN_140332d90(((double)DAT_140e418c8 - 0.0) * _DAT_14053a880 * DAT_14053a020 *
                                 DAT_140539d28);
  FUN_1400c8410((&DAT_140e44ad0)[(int)(uVar3 + iVar4)],0x1d,7,param_1[10],param_1[0xb],
                uVar24 & 0xffff0000,dVar20 * _DAT_140539e28 + dVar19,dVar19,0xff,0xff,0xff,0xff,1,0)
  ;
  bVar17 = SBORROW4(iStack_f4,10);
  if (iStack_f4 == 10) {
    param_1[0x15] = 1;
    if (uStack_100._4_4_ == 100) goto LAB_140033054;
    bVar17 = false;
  }
  if (bVar17 != iStack_f4 + -10 < 0) {
    return;
  }
LAB_140033054:
  *param_1 = 0;
  return;
}


