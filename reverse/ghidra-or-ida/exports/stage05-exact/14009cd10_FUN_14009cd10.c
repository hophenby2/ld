// Function: FUN_14009cd10 @ 14009cd10
// Decompile completed: true

void FUN_14009cd10(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  undefined8 *puVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint local_res8;
  undefined2 uVar24;
  uint uVar25;
  undefined8 in_stack_fffffffffffffe88;
  undefined8 uVar26;
  double dVar27;
  undefined4 uVar28;
  undefined8 in_stack_fffffffffffffe90;
  undefined4 uVar29;
  undefined8 local_138;
  undefined8 uStack_130;
  int iStack_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  
  puVar7 = DAT_140e45d80;
  iVar9 = DAT_140e44e6c;
  dVar27 = DAT_140539f40;
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  iStack_11c = 0;
  local_138 = 0;
  local_138._0_4_ = 0;
  puVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
      if (*(int *)((longlong)puVar3 + 4) == param_1[2]) {
        local_138 = *puVar3;
        uStack_130 = puVar3[1];
        iStack_11c = *(int *)((longlong)puVar3 + 0x1c);
        local_118 = puVar3[4];
        uStack_110 = puVar3[5];
      }
    }
  }
  fVar13 = (float)param_1[0xd];
  fVar14 = (float)param_1[0xc];
  fVar1 = (float)param_1[0xb];
  fVar2 = (float)param_1[10];
  uVar26 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe88 >> 0x20),0x34);
  uVar25 = 0;
  uVar24 = 0;
  iVar5 = FUN_1400c9580(param_1[3],0,7,3,0x32,0x33,uVar26);
  uVar28 = (undefined4)((ulonglong)uVar26 >> 0x20);
  local_res8 = 0;
  dVar15 = (double)FUN_1403300b4((double)((uStack_110._4_4_ + fVar13) - fVar1),
                                 SUB84((double)(((float)uStack_110 + fVar14) - fVar2),0));
  fVar13 = (float)FUN_140334430((int)(dVar15 * DAT_14053aba0),DAT_140539fc0);
  fVar14 = (float)FUN_140334430();
  if (fVar13 + fVar14 < 0.0) {
    fVar13 = (float)FUN_1403352f8();
  }
  else {
    fVar13 = SQRT(fVar13 + fVar14);
  }
  dVar15 = (double)fVar13 / DAT_14053a2d8;
  dVar16 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar16 * dVar15) + (float)param_1[10];
  dVar16 = (double)FUN_140332d90();
  param_1[0xb] = (float)(dVar16 * dVar15) + (float)param_1[0xb];
  dVar4 = DAT_14053b128;
  dVar17 = DAT_14053a798;
  dVar16 = dVar27;
  dVar15 = dVar27;
  if (param_1[5] != 0) goto LAB_14009d0cf;
  iVar10 = param_1[3];
  if (iVar10 == 0) {
    param_1[10] = (float)uStack_110 + (float)param_1[0xc];
    param_1[0xb] = uStack_110._4_4_ + (float)param_1[0xd];
LAB_14009cf92:
    uVar18 = SUB84(DAT_14053a020,0);
    uVar19 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    uVar22 = SUB84(DAT_140539d28,0);
    uVar23 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
    dVar15 = (double)FUN_140332d90(((double)iVar10 - dVar4) * dVar17 * DAT_14053a020 * DAT_140539d28
                                  );
    dVar15 = dVar15 * DAT_14053b0a0 + dVar27;
    if (0x1d < iVar10) {
LAB_14009cff1:
      dVar15 = dVar27;
    }
    uVar20 = (undefined4)DAT_140539fc8;
    uVar21 = (undefined4)((ulonglong)DAT_140539fc8 >> 0x20);
    if (-1 < iVar10) {
      if (iVar10 < 0x1e) {
        dVar16 = (double)FUN_140332d90(((double)iVar10 - dVar4) * dVar17 *
                                       (double)CONCAT44(uVar19,uVar18) *
                                       (double)CONCAT44(uVar23,uVar22));
        iVar5 = 0x32;
        dVar17 = (double)FUN_140332d90(((double)iVar10 - 0.0) * dVar17 *
                                       (double)CONCAT44(uVar19,uVar18) *
                                       (double)CONCAT44(uVar23,uVar22));
        local_res8 = 0xff - (int)(dVar17 * DAT_14053a5f8);
        dVar16 = dVar16 + dVar27;
      }
      else {
        iVar5 = 0x32;
        local_res8 = iVar10 >> 0x1f & 0xff;
        if (iVar10 == 0x1e) {
          param_1[8] = (undefined4)local_118;
          param_1[7] = iStack_11c;
          param_1[0x15] = 0;
          param_1[3] = 0;
          param_1[5] = 1;
        }
      }
      goto LAB_14009d0cf;
    }
  }
  else {
    dVar15 = 0.0;
    if (-1 < iVar10) {
      if (iVar10 < 0x1e) goto LAB_14009cf92;
      uVar18 = SUB84(DAT_14053a020,0);
      uVar19 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
      uVar22 = SUB84(DAT_140539d28,0);
      uVar23 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      goto LAB_14009cff1;
    }
    uVar20 = (undefined4)DAT_140539fc8;
    uVar21 = (undefined4)((ulonglong)DAT_140539fc8 >> 0x20);
  }
  dVar16 = (double)CONCAT44(uVar21,uVar20);
  iVar5 = 0x32;
  local_res8 = iVar10 >> 0x1f & 0xff;
LAB_14009d0cf:
  uVar18 = DAT_140e41a50;
  if (param_1[5] == 1) {
    iVar8 = 1;
    iVar10 = param_1[1];
    uVar19 = param_1[10];
    fVar13 = (float)param_1[0xb] + DAT_14053ac2c;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0x140;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x10e;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar8 = 0xf0;
    }
    dVar17 = DAT_14053a0b0;
    if (((DAT_140e419b8 != 0) && (dVar17 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
       ((dVar17 = DAT_14053a138, DAT_140e419b8 != 2 &&
        ((dVar17 = DAT_14053a178, DAT_140e419b8 != 3 && (dVar17 = dVar27, DAT_140e419b8 == 4)))))) {
      dVar17 = DAT_14053a1b8;
    }
    iVar6 = (iVar10 - DAT_1407c77a0) + 1;
    iVar11 = iVar6 * 0x14;
    if (uStack_130._4_4_ < 0x4b1) {
      if ((iVar11 <= (int)param_1[3]) && ((param_1[3] + iVar6 * -0x14) % iVar8 == 0)) {
        puVar7 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar7 = (undefined8 *)_malloc_base();
          if (puVar7 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
          *puVar7 = 1;
          *(undefined4 *)(puVar7 + 1) = 0x31;
          *(undefined4 *)((longlong)puVar7 + 0xc) = uVar18;
          puVar7[2] = 0x23;
          puVar7[3] = 0;
          *(undefined4 *)(puVar7 + 4) = 0;
          *(undefined2 *)((longlong)puVar7 + 0x24) = 0;
          puVar7[5] = 0;
          puVar7[6] = 0x4014000000000000;
          puVar7[7] = 0x4014000000000000;
          *(undefined4 *)(puVar7 + 8) = 0x28;
          *(undefined4 *)((longlong)puVar7 + 0x44) = 0xff;
          *(undefined4 *)(puVar7 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar7 + 0x4c) = 0xff;
          *(undefined4 *)(puVar7 + 10) = 0xc0;
          *(int *)((longlong)puVar7 + 0x54) = iVar10;
          puVar7[0xb] = 0;
          if (bVar12) {
            DAT_140e45d78 = puVar7;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar7;
          }
        }
        DAT_140e45d28 = puVar7;
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
        FUN_14018a340(DAT_140e472c0,1,1);
        puVar7 = DAT_140e45d80;
        iVar9 = DAT_140e44e6c;
      }
      iVar10 = 0;
      if ((iVar11 + 0x28 <= (int)param_1[3]) && ((param_1[3] - (iVar11 + 0x28)) % iVar8 == 0)) {
        uVar25 = 0;
        dVar27 = dVar17;
        FUN_14006c2f0(0x11,0xc,uVar19,fVar13,CONCAT22(uVar24,0x4000),0,dVar17,CONCAT44(uVar29,1),0);
        uVar28 = (undefined4)((ulonglong)dVar27 >> 0x20);
        if (2 < DAT_140e419b8) {
          do {
            uVar25 = 0;
            dVar27 = dVar17;
            FUN_14006c2f0(0x11,0xc,uVar19,fVar13,(short)iVar10 * 27000 + 0xb44,0,dVar17,1,0);
            uVar28 = (undefined4)((ulonglong)dVar27 >> 0x20);
            iVar10 = iVar10 + 1;
          } while (iVar10 < 2);
        }
        FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
        puVar7 = DAT_140e45d80;
        iVar9 = DAT_140e44e6c;
      }
    }
    iVar10 = param_1[3];
    if ((iVar11 + 0x1e <= iVar10) && (iVar10 < iVar11 + 0x28)) {
      uVar25 = 0;
      iVar5 = FUN_1400c9580(iVar10,iVar11 + 0x1e,5,2,0x35,0x36);
    }
    if (iVar11 + 0x28 <= (int)param_1[3]) {
      uVar25 = 0;
      iVar5 = FUN_1400c9580(param_1[3],iVar11 + 0x28,5,3,0x37,0x38,CONCAT44(uVar28,0x39));
    }
    iVar10 = param_1[7];
    if (iVar10 < iStack_11c) {
      iVar8 = param_1[2];
      puVar3 = puVar7;
      if (0 < iVar9) {
        for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
          if (*(int *)((longlong)puVar3 + 4) == iVar8) {
            *(int *)((longlong)puVar3 + 0x1c) =
                 *(int *)((longlong)puVar3 + 0x1c) - (iStack_11c - iVar10);
          }
        }
      }
    }
    iVar10 = param_1[7];
    if (iStack_11c < iVar10) {
      param_1[7] = iStack_11c;
      iVar10 = iStack_11c;
    }
    if ((iVar10 < 1) && (iVar10 = param_1[2], 0 < iVar9)) {
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)puVar7[0xc]) {
        if (*(int *)((longlong)puVar7 + 4) == iVar10) {
          *(int *)((longlong)puVar7 + 0x1c) = *(int *)((longlong)puVar7 + 0x1c) - iStack_11c;
        }
      }
    }
  }
  uVar25 = uVar25 & 0xffff0000;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x23,7,param_1[10],
                param_1[0xb],uVar25,dVar15,dVar16,0xff,0xff,0xff,0xff,1,0);
  if (local_res8 != 0) {
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)iVar5 * 4),0x23,8,param_1[10],
                  param_1[0xb],uVar25 & 0xffff0000,dVar15,dVar16,0xff,0xff,0xff,local_res8,1,0);
  }
  if (iStack_11c < 1) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
  if ((int)local_138 == 0) {
    *param_1 = 0;
  }
  return;
}


