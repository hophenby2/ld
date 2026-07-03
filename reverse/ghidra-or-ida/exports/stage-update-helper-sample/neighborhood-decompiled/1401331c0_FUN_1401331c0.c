// Function: FUN_1401331c0 @ 1401331c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401331c0(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  uint uVar13;
  short sVar14;
  bool bVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 local_res8;
  undefined4 uStackX_c;
  uint in_stack_fffffffffffffef0;
  undefined1 in_stack_fffffffffffffef8 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  
  dVar5 = DAT_14053a018;
  iVar11 = 0;
  if (((param_1[0x15] == 1) && (iVar10 = param_1[3], iVar10 < 0x15)) && (0 < (int)param_1[7])) {
    uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    local_res8 = (undefined4)uVar7;
    dVar18 = dVar5 - (double)iVar10 * DAT_140539e98;
    uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
    in_stack_fffffffffffffef8._8_4_ = SUB84(dVar18,0);
    in_stack_fffffffffffffef8._0_8_ = dVar18;
    in_stack_fffffffffffffef8._12_4_ = (int)((ulonglong)dVar18 >> 0x20);
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res8,uStackX_c,in_stack_fffffffffffffef0,
                  in_stack_fffffffffffffef8,0xff,0xff,0xff,0xff,1,0);
    if (param_1[3] == 0x14) {
      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_1 + 10);
      *(undefined8 *)(param_1 + 0x12) = 0x4020000000000000;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  dVar19 = DAT_14053a020;
  dVar18 = DAT_140539d28;
  if (param_1[0x15] == 0) {
    iVar10 = param_1[3];
    dVar16 = (double)FUN_140332d90(((double)iVar10 - 0.0) * _DAT_14053a7e8 * DAT_14053a020 *
                                   DAT_140539d28);
    uVar7 = _UNK_14053bb28;
    dVar6 = _DAT_14053bb20;
    dVar16 = dVar16 * _DAT_140539e28 + _DAT_14053bb20;
    if ((iVar10 < 0x5a) && (0.0 < *(double *)(param_1 + 0x12))) {
      dVar3 = *(double *)(param_1 + 0x12) - DAT_140539e60;
      *(double *)(param_1 + 0x12) = dVar3;
      dVar17 = (double)FUN_1403307c0();
      param_1[0xc] = (float)(dVar17 * dVar3) + (float)param_1[0xc];
      dVar17 = (double)FUN_140332d90();
      param_1[0xd] = (float)(dVar17 * dVar3) + (float)param_1[0xd];
    }
    dVar18 = (double)FUN_140332d90(((double)iVar10 - 0.0) * _DAT_14053a868 * dVar19 * dVar18);
    fVar21 = (float)(dVar18 * dVar5) + 0.0 + (float)param_1[0xc];
    param_1[10] = fVar21;
    dVar18 = (double)FUN_140332d90();
    dVar5 = DAT_14053a0f8;
    fVar20 = (float)(dVar18 * DAT_14053a0f8) + 0.0 + (float)param_1[0xd];
    param_1[0xb] = fVar20;
    dVar18 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar20),
                                   SUB84((double)(DAT_140e445d8 - fVar21),0));
    dVar18 = dVar18 * DAT_14053aba0;
    dVar19 = (double)FUN_1403307c0();
    fVar22 = (float)(dVar19 * DAT_14053a278) + fVar21;
    dVar19 = (double)FUN_140332d90();
    fVar1 = DAT_14053ac58;
    uVar4 = DAT_140539ff0;
    fVar20 = (float)(dVar19 * DAT_14053a278) + fVar20;
    sVar12 = (short)(int)dVar18;
    if (((param_1[6] == 3) && (0x31 < iVar10)) &&
       (iVar10 + -0x32 == ((iVar10 + -0x32) / 0x78) * 0x78)) {
      fVar21 = fVar20 + DAT_14053ac58;
      iVar10 = iVar11;
      do {
        auVar23._12_4_ = in_stack_fffffffffffffef8._12_4_;
        auVar23._0_8_ = in_stack_fffffffffffffef8._0_8_;
        auVar23._8_4_ = 1;
        in_stack_fffffffffffffef8._8_8_ = auVar23._8_8_;
        in_stack_fffffffffffffef8._0_8_ = uVar4;
        in_stack_fffffffffffffef0 = 0;
        FUN_14006c2f0(5,0,fVar22,fVar21,(short)iVar10 * 0x666 + sVar12,0,uVar4,
                      in_stack_fffffffffffffef8._8_8_,0);
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0x28);
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      fVar21 = (float)param_1[10];
    }
    if (((param_1[6] == 5) && (uVar13 = param_1[3], 0x31 < (int)uVar13)) &&
       (uVar13 - 0x32 == ((int)(uVar13 - 0x32) / 10) * 10)) {
      iVar10 = iVar11;
      if (uVar13 == 0x32) {
        do {
          auVar24._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar24._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar24._8_4_ = 1;
          in_stack_fffffffffffffef8._8_8_ = auVar24._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar5;
          in_stack_fffffffffffffef0 = 0;
          FUN_14006c2f0(9,1,fVar22,fVar20 + fVar1,(short)iVar10 * 0x2b1 + sVar12 + -10000,0,dVar5,
                        in_stack_fffffffffffffef8._8_8_,0);
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x1e);
      }
      else {
        uVar13 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar13 = uVar13 * 0x800 ^ uVar13;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar13) >> 8 ^ DAT_140e9fd18 ^ uVar13;
        uVar13 = DAT_140e9fd1c / 0x1f41;
        sVar14 = (short)DAT_140e9fd1c;
        do {
          auVar25._12_4_ = in_stack_fffffffffffffef8._12_4_;
          auVar25._0_8_ = in_stack_fffffffffffffef8._0_8_;
          auVar25._8_4_ = 1;
          in_stack_fffffffffffffef8._8_8_ = auVar25._8_8_;
          in_stack_fffffffffffffef8._0_8_ = dVar5;
          in_stack_fffffffffffffef0 = 0;
          FUN_14006c2f0(9,1,fVar22,fVar20 + fVar1,
                        (short)iVar10 * 0x2b1 + sVar14 + (short)uVar13 * -0x1f41 + sVar12 + -14000,0
                        ,dVar5,in_stack_fffffffffffffef8._8_8_,0);
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x1e);
      }
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
      fVar21 = (float)param_1[10];
    }
    if (((param_1[6] - 2 & 0xfffffffc) != 0) || (uVar9 = DAT_140e44ad0, param_1[6] == 4)) {
      uVar9 = DAT_140e44ad8;
    }
    FUN_1400c8410(uVar9,0x22,7,fVar21,param_1[0xb],in_stack_fffffffffffffef0 & 0xffff0000,dVar16,
                  dVar6,0xff,0xff,0xff,0xff,1,0);
    fVar21 = DAT_14053ad04;
    do {
      uVar9 = DAT_140e44ad4;
      sVar12 = (short)iVar11 * 0x3333 + *(short *)(param_1 + 3) * 0x400;
      if (((param_1[6] - 2 & 0xfffffffc) == 0) && (param_1[6] != 4)) {
        fVar1 = (float)param_1[0xb];
        uVar2 = param_1[10];
        puVar8 = (undefined4 *)_malloc_base(0x48);
        if (puVar8 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        puVar8[3] = uVar2;
        puVar8[4] = fVar1 - fVar21;
        *puVar8 = uVar9;
        puVar8[1] = 0x23;
        puVar8[2] = 7;
        *(short *)(puVar8 + 5) = sVar12;
        *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0xff;
        puVar8[0xc] = 0xff;
        puVar8[0xd] = 0xff;
        *(undefined8 *)(puVar8 + 0xe) = 1;
        *(undefined8 *)(puVar8 + 0x10) = 0;
        _DAT_140e46d1c = _DAT_140e46d1c + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar8;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
        }
      }
      else {
        FUN_1400c8410(DAT_140e44adc,0x23,7,param_1[10],(float)param_1[0xb] - fVar21,sVar12,dVar6,
                      uVar7,0xff,0xff,0xff,0xff,1,0);
        puVar8 = DAT_140e46c88;
      }
      DAT_140e46c88 = puVar8;
      uVar9 = DAT_140e44ae0;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 5);
    puVar8 = DAT_140e46c88;
    if (param_1[6] == 2) {
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar8[3] = fVar22;
      puVar8[4] = fVar20;
      *puVar8 = uVar9;
      puVar8[1] = 0x23;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar15) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
    }
    DAT_140e46c88 = puVar8;
    uVar9 = DAT_140e44ae4;
    puVar8 = DAT_140e46c88;
    if (param_1[6] == 3) {
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar8[3] = fVar22;
      puVar8[4] = fVar20;
      *puVar8 = uVar9;
      puVar8[1] = 0x23;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar15) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
    }
    DAT_140e46c88 = puVar8;
    uVar9 = DAT_140e44aec;
    puVar8 = DAT_140e46c88;
    if (param_1[6] == 4) {
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar8[3] = fVar22;
      puVar8[4] = fVar20;
      *puVar8 = uVar9;
      puVar8[1] = 0x23;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar15) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
    }
    DAT_140e46c88 = puVar8;
    uVar9 = DAT_140e44ae8;
    puVar8 = DAT_140e46c88;
    if (param_1[6] == 5) {
      puVar8 = (undefined4 *)_malloc_base(0x48);
      if (puVar8 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      _DAT_140e46d1c = _DAT_140e46d1c + 1;
      bVar15 = DAT_140e46bf0 == (undefined4 *)0x0;
      puVar8[3] = fVar22;
      puVar8[4] = fVar20;
      *puVar8 = uVar9;
      puVar8[1] = 0x23;
      puVar8[2] = 7;
      *(undefined2 *)(puVar8 + 5) = 0;
      *(undefined8 *)(puVar8 + 6) = 0x3ff0000000000000;
      *(undefined8 *)(puVar8 + 8) = 0x3ff0000000000000;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0xff;
      puVar8[0xc] = 0xff;
      puVar8[0xd] = 0xff;
      *(undefined8 *)(puVar8 + 0xe) = 1;
      *(undefined8 *)(puVar8 + 0x10) = 0;
      if (bVar15) {
        DAT_140e46bf0 = puVar8;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar8;
      }
    }
    DAT_140e46c88 = puVar8;
    if (param_1[6] != 5) {
      FUN_140079c10(param_1,1);
    }
    if (param_1[6] == 5) {
      param_1[7] = 99999999;
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_140079e20(param_1,1);
    DAT_140e9fd0c = DAT_140e9fd0c + 1;
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


