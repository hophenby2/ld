// Function: FUN_14008d230 @ 14008d230
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14008d230(undefined4 *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  double dVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  short sVar12;
  uint uVar13;
  undefined2 uVar14;
  int iVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  uint in_stack_fffffffffffffeb8;
  uint in_stack_fffffffffffffec0;
  float fVar30;
  undefined2 uVar32;
  undefined4 uVar31;
  double in_stack_fffffffffffffec8;
  undefined8 in_stack_fffffffffffffed0;
  double dVar33;
  undefined8 uVar34;
  undefined4 local_f8;
  uint uStack_f4;
  
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  dVar3 = DAT_14053aba0;
  dVar21 = DAT_14053a9f8;
  dVar23 = DAT_14053a020;
  dVar22 = DAT_140539d28;
  uVar13 = param_1[3];
  dVar19 = dVar19 * DAT_14053aba0;
  dVar33 = (double)(int)uVar13;
  uVar10 = (ushort)(int)dVar19;
  dVar20 = (double)FUN_140332d90((dVar33 - 0.0) * DAT_14053a9f8 * DAT_14053a020 * DAT_140539d28);
  fVar17 = (float)(dVar20 + dVar20) + 0.0;
  dVar20 = (double)FUN_140332d90((dVar33 - DAT_14053a1b8) * dVar21 * dVar23 * dVar22);
  fVar24 = (float)(dVar20 + dVar20) + 0.0;
  dVar21 = (double)FUN_140332d90((dVar33 - DAT_14053a268) * dVar21 * dVar23 * dVar22);
  fVar18 = (float)(dVar21 + dVar21) + 0.0;
  dVar20 = (double)FUN_140332d90();
  dVar21 = DAT_14053a070;
  dVar20 = dVar20 * _DAT_14053aab0;
  dVar22 = (double)FUN_140332d90((dVar33 - DAT_14053a070) * DAT_14053ab68 * dVar23 * dVar22);
  uVar32 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
  dVar22 = dVar22 * _DAT_14053aab0;
  if (param_1[5] == 0) {
    uVar4 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    in_stack_fffffffffffffec8 = dVar21 - dVar33 * DAT_140539ec8;
    local_f8 = (undefined4)uVar4;
    in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffff0000;
    uStack_f4 = (uint)((ulonglong)uVar4 >> 0x20);
    dVar33 = in_stack_fffffffffffffec8;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_f8,uStack_f4,in_stack_fffffffffffffec0,
                  in_stack_fffffffffffffec8,in_stack_fffffffffffffec8,0xff,0xff,0xff,0xff,1,0);
    uVar32 = (undefined2)(in_stack_fffffffffffffec0 >> 0x10);
    uVar31 = (undefined4)((ulonglong)dVar33 >> 0x20);
    uVar13 = param_1[3];
    in_stack_fffffffffffffeb8 = uStack_f4;
    if (param_1[3] == 0x14) {
      param_1[5] = param_1[5] + 1;
      *(undefined8 *)(param_1 + 0x12) = 0x401c000000000000;
      param_1[0x15] = 0;
      param_1[3] = 0;
      uVar13 = 0;
    }
  }
  uVar4 = _UNK_14053bb28;
  dVar33 = _DAT_14053bb20;
  if (param_1[5] == 1) {
    if ((int)uVar13 < 300) {
      dVar23 = *(double *)(param_1 + 0x12);
      if ((uVar13 < 0x79) && (DAT_140539f28 < dVar23)) {
        dVar23 = dVar23 - DAT_140539e60;
      }
      uVar1 = *(ushort *)(param_1 + 0x10);
      iVar6 = ((int)dVar19 & 0xffffU) - (uint)uVar1;
      *(double *)(param_1 + 0x12) = dVar23;
      iVar7 = iVar6 + 0x10000;
      if (-0x8001 < iVar6) {
        iVar7 = iVar6;
      }
      iVar6 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar6 = iVar7;
      }
      if (iVar6 < 1) {
        uVar8 = uVar1;
        if ((iVar6 < 0) && (uVar8 = uVar1 - 0x40, -0x40 < iVar6)) {
          uVar8 = uVar10;
        }
      }
      else {
        uVar8 = uVar10;
        if (0x3f < iVar6) {
          uVar8 = uVar1 + 0x40;
        }
      }
    }
    else {
      uVar8 = *(ushort *)(param_1 + 0x10);
      iVar6 = -(uint)uVar8 + 0xc000;
      iVar7 = -(uint)uVar8 + 0x1c000;
      if (-0x8001 < iVar6) {
        iVar7 = iVar6;
      }
      iVar6 = iVar7 + -0x10000;
      if (iVar7 < 0x8001) {
        iVar6 = iVar7;
      }
      if (iVar6 < 1) {
        if ((iVar6 < 0) && (uVar8 = uVar8 - 0xa0, -0xa0 < iVar6)) {
          uVar8 = 0xc000;
        }
      }
      else if (iVar6 < 0xa0) {
        uVar8 = 0xc000;
      }
      else {
        uVar8 = uVar8 + 0xa0;
      }
      *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + DAT_140539e60;
    }
    *(ushort *)(param_1 + 0x10) = uVar8;
    dVar23 = (double)FUN_1403307c0();
    fVar28 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar28;
    dVar23 = (double)FUN_140332d90();
    iVar7 = param_1[3];
    fVar26 = (float)(dVar23 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
    param_1[0xb] = fVar26;
    if (iVar7 - 0x28U < 0x104) {
      fVar27 = (fVar26 - DAT_14053ac9c) + fVar17;
      fVar29 = fVar26 + DAT_14053ad5c + fVar18;
      dVar23 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar27),
                                     (double)(DAT_140e445d8 - fVar28));
      fVar26 = DAT_14053ac2c;
      iVar6 = 1;
      if (DAT_140e419b8 == 0) {
        iVar6 = 0x12;
      }
      else if (DAT_140e419b8 == 1) {
        iVar6 = 0xe;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar6 = 0xc;
      }
      else if (DAT_140e419b8 == 4) {
        iVar6 = 10;
      }
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 2;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 3;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar9 = 5;
      }
      else if (DAT_140e419b8 == 4) {
        iVar9 = 7;
      }
      dVar19 = DAT_14053a088;
      if ((((DAT_140e419b8 != 0) && (dVar19 = DAT_14053a0e8, DAT_140e419b8 != 1)) &&
          (dVar19 = DAT_14053a118, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar19 = dVar33, DAT_140e419b8 == 4)))) {
        dVar19 = DAT_14053a178;
      }
      iVar15 = 1;
      if (DAT_140e419b8 == 0) {
        iVar15 = 0x37;
      }
      else if (DAT_140e419b8 == 1) {
        iVar15 = 0x28;
      }
      else if (DAT_140e419b8 == 2) {
        iVar15 = 0x20;
      }
      else if (DAT_140e419b8 == 3) {
        iVar15 = 0x1a;
      }
      else if (DAT_140e419b8 == 4) {
        iVar15 = 0x14;
      }
      iVar11 = 1;
      if (DAT_140e419b8 == 0) {
        iVar11 = 7;
      }
      else if (DAT_140e419b8 == 1) {
        iVar11 = 0xd;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar11 = 0xf;
      }
      else if (DAT_140e419b8 == 4) {
        iVar11 = 0x11;
      }
      dVar25 = ((double)iVar7 - DAT_14053a340) * _DAT_140539d98;
      if (DAT_140e419b8 == 0) {
        dVar25 = dVar25 + dVar21;
      }
      else if (DAT_140e419b8 == 1) {
        dVar25 = dVar25 + DAT_14053a088;
      }
      else if (DAT_140e419b8 == 2) {
        dVar25 = dVar25 + DAT_14053a0b0;
      }
      else if (DAT_140e419b8 == 3) {
        dVar25 = dVar25 + DAT_14053a0d0;
      }
      else if (DAT_140e419b8 == 4) {
        dVar25 = dVar25 + DAT_14053a138;
      }
      else {
        dVar25 = dVar25 + dVar33;
      }
      if ((iVar7 + -0x28) % iVar6 == 0) {
        iVar7 = (iVar7 + -0x28) % 0xf4;
        sVar12 = (short)iVar7;
        if (iVar7 < 0x7a) {
          sVar12 = sVar12 * 0xc4 + 0x1120;
        }
        else {
          sVar12 = sVar12 * -0xc4 + -0x3410;
        }
        iVar7 = iVar9 * 0xc80 + -0xc80;
        uVar34 = CONCAT44(uVar31,1);
        in_stack_fffffffffffffeb8 = CONCAT22((short)(in_stack_fffffffffffffeb8 >> 0x10),sVar12);
        fVar30 = DAT_14053ac2c;
        in_stack_fffffffffffffec8 = dVar19;
        FUN_1400709b0(9,0,fVar28,fVar29,in_stack_fffffffffffffeb8,DAT_14053ac2c,dVar19,uVar34,iVar9,
                      iVar7,0);
        uVar32 = (undefined2)((uint)fVar30 >> 0x10);
        uVar31 = (undefined4)((ulonglong)uVar34 >> 0x20);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffec8 = dVar19 + dVar33;
          uVar34 = CONCAT44(uVar31,1);
          in_stack_fffffffffffffeb8 = CONCAT22((short)(in_stack_fffffffffffffeb8 >> 0x10),sVar12);
          FUN_1400709b0(9,0,fVar28,fVar29,in_stack_fffffffffffffeb8,fVar26,in_stack_fffffffffffffec8
                        ,uVar34,iVar9,iVar7,0);
          uVar32 = (undefined2)((uint)fVar26 >> 0x10);
          uVar31 = (undefined4)((ulonglong)uVar34 >> 0x20);
        }
      }
      uVar14 = (undefined2)(int)(dVar23 * dVar3);
      if ((param_1[3] - 0x32 < 0xfa) &&
         (uVar2 = (longlong)(param_1[3] + -0x32) % (longlong)(iVar15 * 2), (int)uVar2 == 0)) {
        uVar34 = CONCAT44(uVar31,1);
        uVar32 = 0;
        in_stack_fffffffffffffeb8 = CONCAT22((short)(in_stack_fffffffffffffeb8 >> 0x10),uVar14);
        in_stack_fffffffffffffec8 = dVar25;
        FUN_1400709b0(4,uVar2 & 0xffffffff,fVar28,fVar27,in_stack_fffffffffffffeb8,0,dVar25,uVar34,
                      iVar11,0x8000,0);
        uVar31 = (undefined4)((ulonglong)uVar34 >> 0x20);
      }
      iVar7 = param_1[3];
      if (((iVar15 + 0x32 <= iVar7) && (iVar7 < 300)) &&
         ((iVar7 - (iVar15 + 0x32)) % (iVar15 * 2) == 0)) {
        uVar32 = 0;
        in_stack_fffffffffffffeb8 = CONCAT22((short)(in_stack_fffffffffffffeb8 >> 0x10),uVar14);
        FUN_1400709b0(4,0,fVar28,fVar27,in_stack_fffffffffffffeb8,0,dVar25,CONCAT44(uVar31,1),
                      iVar11 - 1U,(int)(0x8000 / (ulonglong)(iVar11 - 1U)) * (iVar11 + -2) & 0xffff,
                      0);
        in_stack_fffffffffffffec8 = dVar25;
      }
    }
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,1000,0x10);
      uVar32 = 0;
      FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffeb8 & 0xffff0000,0,
                    (ulonglong)in_stack_fffffffffffffec8 & 0xffffffff00000000);
      uVar31 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar5 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar5 = (undefined8 *)_malloc_base(0x60);
        if (puVar5 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar5 = 1;
        *(undefined4 *)(puVar5 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar5 + 0xc) = uVar31;
        puVar5[2] = 0x6f;
        puVar5[3] = 0;
        *(undefined4 *)(puVar5 + 4) = 0;
        *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x3ff0000000000000;
        puVar5[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar5 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
        *(undefined4 *)(puVar5 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
        puVar5[10] = 0xff;
        puVar5[0xb] = 0;
        if (bVar16) {
          DAT_140e45d78 = puVar5;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar5;
        }
      }
      DAT_140e45d28 = puVar5;
      param_1[5] = param_1[5] + 1;
      param_1[0x15] = 1;
      param_1[3] = 0;
    }
  }
  fVar26 = DAT_14053ac2c;
  if (param_1[5] == 2) {
    if ((int)param_1[3] < 0x3d) {
      FUN_14007ac00(param_1);
    }
    param_1[0xb] = (float)(int)param_1[3] * DAT_140539ce4 + (float)param_1[0xb];
    if (param_1[3] == 0x3c) {
      FUN_140079e20(param_1,2);
      *param_1 = 0;
    }
  }
  sVar12 = (short)(int)dVar22;
  uVar31 = CONCAT22(uVar32,sVar12);
  FUN_1400c8410(DAT_140e44938,0x1e,7,(float)param_1[10] + fVar26,
                ((float)param_1[0xb] - DAT_14053aca8) + fVar24,uVar31,dVar33,uVar4,0xff,0xff,0xff,
                0xff,1,0);
  uVar31 = CONCAT22((short)((uint)uVar31 >> 0x10),-sVar12);
  FUN_1400c8410(DAT_140e44938,0x1e,7,(float)param_1[10] + fVar26,
                ((float)param_1[0xb] - DAT_14053aca8) + fVar24,uVar31,dVar33,uVar4,0xff,0xff,0xff,
                0xff,1,1);
  sVar12 = (short)(int)dVar20;
  uVar31 = CONCAT22((short)((uint)uVar31 >> 0x10),sVar12);
  FUN_1400c8410(DAT_140e44934,0x1e,7,(float)param_1[10] + fVar26,
                ((float)param_1[0xb] - DAT_14053acb0) + fVar24,uVar31,dVar33,uVar4,0xff,0xff,0xff,
                0xff,1,0);
  uVar13 = CONCAT22((short)((uint)uVar31 >> 0x10),-sVar12);
  FUN_1400c8410(DAT_140e44934,0x1e,7,(float)param_1[10] + fVar26,
                ((float)param_1[0xb] - DAT_14053acb0) + fVar24,uVar13,dVar33,uVar4,0xff,0xff,0xff,
                0xff,1,1);
  uVar13 = uVar13 & 0xffff0000;
  FUN_1400c8410(DAT_140e44bb4,0x1e,7,param_1[10],(float)param_1[0xb] + DAT_14053acbc + fVar18,uVar13
                ,dVar33,uVar4,0xff,0xff,0xff,0xff,1,0);
  uVar13 = uVar13 & 0xffff0000;
  FUN_1400c8410(DAT_140e44bb0,0x1e,7,param_1[10],fVar24 + (float)param_1[0xb],uVar13,dVar33,uVar4,
                0xff,0xff,0xff,0xff,1,1);
  FUN_1400c8410(DAT_140e44bac,0x1e,7,param_1[10],((float)param_1[0xb] - DAT_14053ace8) + fVar17,
                uVar13 & 0xffff0000,dVar33,uVar4,0xff,0xff,0xff,0xff,1,0);
  FUN_140079c10(param_1,1);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  if ((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053adb4) ||
      (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af48 < (float)param_1[10])) ||
     (((float)param_1[0xb] < DAT_14053b3d0 || (_DAT_14053af88 < (float)param_1[0xb])))) {
    *param_1 = 0;
  }
  return;
}


