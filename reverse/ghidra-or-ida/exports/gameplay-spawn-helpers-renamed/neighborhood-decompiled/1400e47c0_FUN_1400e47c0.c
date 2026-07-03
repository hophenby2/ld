// Function: FUN_1400e47c0 @ 1400e47c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400e47c0(undefined4 *param_1)

{
  float *pfVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  longlong lVar5;
  double dVar6;
  int iVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  undefined4 in_stack_fffffffffffffe88;
  undefined2 uVar27;
  undefined4 in_stack_fffffffffffffe90;
  undefined2 uVar30;
  undefined4 uVar28;
  uint uVar29;
  undefined1 in_stack_fffffffffffffe98 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  int iStack_114;
  
  dVar6 = DAT_14053a020;
  dVar18 = DAT_140539f40;
  dVar17 = DAT_140539e60;
  uVar30 = (undefined2)((uint)in_stack_fffffffffffffe90 >> 0x10);
  uVar27 = (undefined2)((uint)in_stack_fffffffffffffe88 >> 0x10);
  lVar5 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x60)) {
      if (*(int *)(lVar5 + 4) == DAT_140e44308) {
        iStack_114 = *(int *)(lVar5 + 0x14);
      }
    }
  }
  iVar7 = param_1[3];
  uVar23 = SUB84(DAT_140539f40,0);
  uVar24 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  dVar15 = DAT_140539e60;
  if ((-1 < iVar7) && (dVar15 = DAT_140539f40, iVar7 < 0x14)) {
    dVar15 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a890 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar15 = dVar15 * DAT_140539f38 + dVar17;
  }
  uVar21 = (undefined4)((ulonglong)dVar15 >> 0x20);
  uVar20 = SUB84(dVar15,0);
  puVar8 = DAT_140e45d28;
  if (param_1[5] == 0) {
    sVar11 = (short)iVar7 + 0x5a;
    pfVar1 = (float *)(param_1 + 0xc);
    if (iVar7 == 0) {
      *pfVar1 = 0.0;
    }
    else if (iVar7 == 0x14) {
      param_1[0x15] = 0;
    }
    fVar19 = (float)*(double *)(param_1 + 0x12) + *pfVar1;
    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + dVar17;
    *pfVar1 = fVar19;
    dVar17 = (double)fVar19;
    if (param_1[6] != 0xc4) {
      sVar11 = -sVar11;
    }
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + sVar11;
    dVar16 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar16 * dVar17) + (float)param_1[0xe];
    dVar16 = (double)FUN_140332d90();
    param_1[10] = fVar22;
    fVar26 = (float)(dVar16 * dVar17) + (float)param_1[0xf];
    param_1[0xb] = fVar26;
    fVar13 = DAT_140e445dc;
    fVar19 = DAT_140e445d8;
    if (0x13 < iVar7) {
      fVar25 = fVar26 + DAT_14053ac34;
      dVar17 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar25),
                                     SUB84((double)(DAT_140e445d8 - fVar22),0));
      iVar9 = 1;
      dVar17 = dVar17 * DAT_14053aba0;
      if (DAT_140e419b8 == 0) {
        iVar9 = 0x1a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 0x16;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar9 = 0x14;
      }
      iVar10 = 1;
      if (DAT_140e419b8 == 0) {
        iVar10 = 6;
      }
      else if (DAT_140e419b8 == 1) {
        iVar10 = 8;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar10 = 10;
      }
      else if (DAT_140e419b8 == 4) {
        iVar10 = 0xc;
      }
      dVar16 = DAT_14053a0b0;
      if (((DAT_140e419b8 != 0) && (dVar16 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
         ((dVar16 = DAT_14053a110, DAT_140e419b8 != 2 &&
          ((dVar16 = DAT_14053a140, DAT_140e419b8 != 3 && (dVar16 = dVar18, DAT_140e419b8 == 4))))))
      {
        dVar16 = DAT_14053a190;
      }
      if (((0x1d < iVar7) &&
          (uVar2 = (longlong)(iVar7 + -0x1e) % (longlong)iVar9, (int)uVar2 < iVar10)) &&
         ((uVar2 & 1) == 0)) {
        fVar13 = (float)FUN_140334430(fVar26 - fVar13,DAT_140539fc0);
        fVar14 = (float)FUN_140334430(fVar22 - fVar19);
        if (fVar13 + fVar14 < 0.0) {
          fVar13 = (float)FUN_1403352f8();
        }
        else {
          fVar13 = SQRT(fVar13 + fVar14);
        }
        if (((DAT_14053ad1c <= fVar13) && (fVar19 = fVar19 / DAT_14053ab70, fVar19 + 0.0 <= fVar22))
           && ((fVar22 <= fVar19 + DAT_14053aec0 && ((0.0 <= fVar26 && (fVar26 <= DAT_14053af14)))))
           ) {
          auVar31._12_4_ = in_stack_fffffffffffffe98._12_4_;
          auVar31._0_8_ = in_stack_fffffffffffffe98._0_8_;
          auVar31._8_4_ = 1;
          auVar32._8_8_ = auVar31._8_8_;
          auVar32._0_8_ = dVar16;
          uVar30 = 0;
          FUN_14006c2f0(0xd,4,fVar22,fVar25,CONCAT22(uVar27,(short)(int)dVar17),0,dVar16,
                        auVar32._8_8_,0);
          if (2 < DAT_140e419b8) {
            auVar33._12_4_ = auVar32._12_4_;
            auVar33._0_8_ = auVar32._0_8_;
            auVar33._8_4_ = 1;
            uVar30 = 0;
            FUN_14006c2f0(0xd,4,fVar22,fVar25,(int)dVar17 & 0xffff,0,dVar16 + DAT_140539fc8,
                          auVar33._8_8_,0);
          }
          FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
          FUN_14018a340(DAT_140e472a4,1,1);
        }
        uVar23 = SUB84(DAT_140539f40,0);
        uVar24 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      }
    }
    dVar17 = (double)FUN_140332d90(((double)(int)param_1[3] - _DAT_140539cc0) * _DAT_14053a9f0 *
                                   dVar6 * DAT_140539d28);
    dVar17 = dVar17 * _DAT_14053aa40;
    dVar18 = (double)FUN_1403307c0();
    fVar13 = (float)(dVar18 * DAT_14053a340) + 0.0;
    dVar18 = (double)FUN_140332d90();
    pfVar1 = (float *)(param_1 + 0xb);
    auVar3._8_4_ = uVar20;
    auVar3._0_8_ = dVar15;
    auVar3._12_4_ = uVar21;
    sVar11 = (short)(int)dVar17;
    uVar28 = CONCAT22(uVar30,sVar11);
    fVar19 = (float)(dVar18 * DAT_14053a340) + 0.0;
    FUN_1400c8410(DAT_140e44698,0x23,7,fVar13 + (float)param_1[10],fVar19 + *pfVar1,uVar28,auVar3,
                  0xff,0xff,0xff,0xff,1,0);
    auVar4._8_4_ = uVar20;
    auVar4._0_8_ = dVar15;
    auVar4._12_4_ = uVar21;
    uVar29 = CONCAT22((short)((uint)uVar28 >> 0x10),-sVar11);
    FUN_1400c8410(DAT_140e44698,0x23,7,(float)param_1[10] - fVar13,fVar19 + *pfVar1,uVar29,auVar4,
                  0xff,0xff,0xff,0xff,1,1);
    in_stack_fffffffffffffe98._8_4_ = uVar20;
    in_stack_fffffffffffffe98._0_8_ = dVar15;
    in_stack_fffffffffffffe98._12_4_ = uVar21;
    uVar29 = uVar29 & 0xffff0000;
    FUN_1400c8410(DAT_140e4468c,0x23,7,param_1[10],*pfVar1,uVar29,in_stack_fffffffffffffe98,0xff,
                  0xff,0xff,0xff,1,0);
    uVar20 = DAT_140e44698;
    uVar30 = (undefined2)(uVar29 >> 0x10);
    puVar8 = DAT_140e45d28;
    if (((param_1[5] == 0) && (0x13 < (int)param_1[3])) && ((param_1[3] & 1) == 0)) {
      fVar22 = *pfVar1;
      fVar26 = (float)param_1[10];
      iVar7 = DAT_140e45d1c;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar7 = DAT_140e45d1c + 1;
        *(float *)((longlong)puVar8 + 0x14) = fVar13 + fVar26;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)(puVar8 + 3) = fVar19 + fVar22;
        *(float *)((longlong)puVar8 + 0x1c) = fVar13 + fVar26;
        *(float *)(puVar8 + 4) = fVar19 + fVar22;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 5;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar20;
        *(undefined4 *)(puVar8 + 2) = 0x22;
        *(short *)((longlong)puVar8 + 0x24) = sVar11;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0xc;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0x60;
        puVar8[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar8;
        }
        DAT_140e45d1c = iVar7;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      uVar20 = DAT_140e44698;
      fVar22 = (float)param_1[10];
      fVar26 = (float)param_1[0xb];
      puVar8 = DAT_140e45d28;
      if (iVar7 < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar7 = DAT_140e45d1c + 1;
        *(float *)((longlong)puVar8 + 0x14) = fVar22 - fVar13;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)(puVar8 + 3) = fVar19 + fVar26;
        *(float *)((longlong)puVar8 + 0x1c) = fVar22 - fVar13;
        *(float *)(puVar8 + 4) = fVar19 + fVar26;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 7;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar20;
        *(undefined4 *)(puVar8 + 2) = 0x22;
        *(short *)((longlong)puVar8 + 0x24) = -sVar11;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0xc;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0x60;
        puVar8[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar8;
        }
        DAT_140e45d1c = iVar7;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      uVar28 = DAT_140e4468c;
      uVar20 = param_1[0xb];
      uVar21 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (iVar7 < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar12 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar21;
        *(undefined4 *)(puVar8 + 3) = uVar20;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar21;
        *(undefined4 *)(puVar8 + 4) = uVar20;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 5;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar28;
        *(undefined4 *)(puVar8 + 2) = 0x22;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0xc;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0x60;
        puVar8[0xb] = 0;
        if (bVar12) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
    }
  }
  DAT_140e45d28 = puVar8;
  fVar19 = DAT_14053ab70;
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,300,2);
    if (DAT_140e44600 == 0) {
      auVar34._12_4_ = in_stack_fffffffffffffe98._12_4_;
      auVar34._0_8_ = in_stack_fffffffffffffe98._0_8_;
      auVar34._8_4_ = 10;
      stage_entity_spawn_candidate
                (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar30,0x4000),
                 CONCAT44(uVar24,uVar23),auVar34._8_8_,1,DAT_140e44308);
    }
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (1 < iStack_114) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((float)param_1[10] < DAT_140e445d8 / fVar19 - DAT_14053adb4) ||
      (DAT_140e445d8 / fVar19 + DAT_14053af48 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3d0 || (_DAT_14053af88 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


