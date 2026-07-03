// Function: FUN_140022120 @ 140022120
// Decompile completed: true

void FUN_140022120(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  longlong lVar3;
  short sVar4;
  double dVar5;
  undefined4 uVar6;
  ushort uVar7;
  int iVar8;
  undefined8 *puVar9;
  uint uVar10;
  int iVar11;
  short sVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  short sVar16;
  ushort uVar17;
  int iVar18;
  ushort uVar19;
  short sVar20;
  int iVar21;
  bool bVar22;
  float fVar23;
  float fVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  float fVar31;
  int local_res8;
  uint local_res10;
  undefined4 uVar32;
  undefined2 uVar33;
  float fVar34;
  double dVar35;
  undefined8 in_stack_fffffffffffffe80;
  undefined8 uVar36;
  short local_148;
  int iStack_124;
  undefined8 local_120;
  undefined8 uStack_118;
  
  dVar5 = DAT_140539f40;
  uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffe80 >> 0x20);
  iStack_124 = 0;
  iVar8 = 0;
  lVar3 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_124 = iVar8, lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == param_1[2]) {
        iStack_124 = *(int *)(lVar3 + 0x1c);
        local_120 = *(undefined8 *)(lVar3 + 0x20);
        uStack_118 = *(undefined8 *)(lVar3 + 0x28);
      }
      iVar8 = iStack_124;
    }
  }
  fVar23 = (float)param_1[0xd];
  fVar24 = (float)param_1[0xc];
  fVar1 = (float)param_1[0xb];
  fVar31 = (float)param_1[10];
  dVar35 = 2.56914135837448e-322;
  fVar34 = 0.0;
  uVar33 = 0;
  local_res8 = FUN_1400c9580(param_1[3],0,7,3,0x32,0x33,0x34);
  local_res10 = 0;
  dVar25 = (double)FUN_1403300b4((double)((uStack_118._4_4_ + fVar23) - fVar1),
                                 SUB84((double)(((float)uStack_118 + fVar24) - fVar31),0));
  dVar29 = DAT_14053a020;
  dVar28 = DAT_140539d28;
  fVar23 = (float)FUN_140334430((int)(dVar25 * DAT_14053aba0),DAT_140539fc0);
  fVar24 = (float)FUN_140334430();
  if (fVar23 + fVar24 < 0.0) {
    fVar23 = (float)FUN_1403352f8();
  }
  else {
    fVar23 = SQRT(fVar23 + fVar24);
  }
  dVar25 = (double)fVar23 / DAT_14053a2d8;
  dVar26 = (double)FUN_1403307c0();
  param_1[10] = (float)(dVar26 * dVar25) + (float)param_1[10];
  dVar26 = (double)FUN_140332d90();
  param_1[0xb] = (float)(dVar26 * dVar25) + (float)param_1[0xb];
  dVar27 = DAT_14053b128;
  dVar26 = DAT_14053a798;
  dVar30 = dVar5;
  dVar25 = dVar5;
  if (param_1[5] == 0) {
    iVar8 = param_1[3];
    if (iVar8 == 0) {
      param_1[10] = (float)uStack_118 + (float)param_1[0xc];
      param_1[0xb] = uStack_118._4_4_ + (float)param_1[0xd];
LAB_14002239a:
      dVar25 = (double)FUN_140332d90(((double)iVar8 - dVar27) * dVar26 * dVar29 * dVar28);
      dVar25 = dVar25 * DAT_14053b0a0 + dVar5;
      if (0x1d < iVar8) {
LAB_1400223d1:
        dVar25 = dVar5;
      }
      if (-1 < iVar8) {
        if (iVar8 < 0x1e) {
          dVar27 = (double)FUN_140332d90(((double)iVar8 - dVar27) * dVar26 * dVar29 * dVar28);
          local_res8 = 0x32;
          dVar28 = (double)FUN_140332d90(((double)iVar8 - 0.0) * dVar26 * dVar29 * dVar28);
          local_res10 = 0xff - (int)(dVar28 * DAT_14053a5f8);
          dVar30 = dVar27 + dVar5;
        }
        else {
          local_res10 = iVar8 >> 0x1f & 0xff;
          local_res8 = 0x32;
          if (iVar8 == 0x1e) {
            param_1[8] = (undefined4)local_120;
            param_1[7] = iStack_124;
            param_1[0x15] = 0;
            param_1[3] = 0;
            param_1[5] = 1;
            local_res8 = 0x32;
          }
        }
        goto LAB_1400224e8;
      }
    }
    else {
      dVar25 = 0.0;
      if (-1 < iVar8) {
        if (iVar8 < 0x1e) goto LAB_14002239a;
        goto LAB_1400223d1;
      }
    }
    local_res10 = iVar8 >> 0x1f & 0xff;
    local_res8 = 0x32;
    dVar30 = DAT_140539fc8;
  }
LAB_1400224e8:
  fVar24 = DAT_140e445dc;
  fVar23 = DAT_140e445d8;
  if (param_1[5] != 1) goto LAB_14002311c;
  iVar8 = param_1[1];
  fVar31 = (float)param_1[0xb] + DAT_14053ac2c;
  fVar1 = (float)param_1[10];
  iVar14 = iVar8 - DAT_1407c77a0;
  iVar15 = (int)param_1[3] % 0x4b0;
  dVar28 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar31),
                                 SUB84((double)(DAT_140e445d8 - fVar1),0));
  dVar28 = dVar28 * DAT_14053aba0;
  dVar29 = (double)FUN_1403300b4((double)(fVar24 - uStack_118._4_4_),
                                 SUB84((double)(fVar23 - (float)uStack_118),0));
  uVar6 = DAT_140e41a50;
  uVar19 = (ushort)(int)(dVar29 * DAT_14053aba0);
  if (iVar15 < 0x168) {
    iVar21 = 1;
    if (DAT_140e419b8 == 0) {
      iVar21 = 0x53;
    }
    else if (DAT_140e419b8 == 1) {
      iVar21 = 0x3d;
    }
    else if (DAT_140e419b8 == 2) {
      iVar21 = 0x2f;
    }
    else if (DAT_140e419b8 == 3) {
      iVar21 = 0x29;
    }
    else if (DAT_140e419b8 == 4) {
      iVar21 = 0x24;
    }
    iVar18 = 1;
    if (DAT_140e419b8 == 0) {
      iVar18 = 0xf;
    }
    else if (DAT_140e419b8 == 1) {
      iVar18 = 7;
    }
    else if (DAT_140e419b8 == 2) {
      iVar18 = 5;
    }
    else if (DAT_140e419b8 == 3) {
      iVar18 = 4;
    }
    else if (DAT_140e419b8 == 4) {
      iVar18 = 3;
    }
    iVar11 = 1;
    if (DAT_140e419b8 == 0) {
      iVar11 = 0x12;
    }
    else if (DAT_140e419b8 == 1) {
      iVar11 = 8;
    }
    else if (DAT_140e419b8 == 2) {
      iVar11 = 6;
    }
    else if (DAT_140e419b8 == 3) {
      iVar11 = 4;
    }
    else if (DAT_140e419b8 == 4) {
      iVar11 = 3;
    }
    dVar29 = DAT_14053a070;
    if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) &&
        (dVar29 = DAT_14053a088, DAT_140e419b8 != 2)) &&
       ((dVar29 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar29 = dVar5, DAT_140e419b8 == 4)))) {
      dVar29 = DAT_14053a110;
    }
    if (iVar15 == 0) {
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base();
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar9 + 0xc) = uVar6;
        puVar9[6] = 0x4014000000000000;
        puVar9[7] = 0x4014000000000000;
        *(int *)((longlong)puVar9 + 0x54) = iVar8;
        *puVar9 = 1;
        *(undefined4 *)(puVar9 + 1) = 0x31;
        puVar9[2] = 0x23;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        *(undefined4 *)(puVar9 + 8) = 0x28;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        *(undefined4 *)(puVar9 + 10) = 0xc0;
        puVar9[0xb] = 0;
        if (bVar22) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
      DAT_140e45d28 = puVar9;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
LAB_1400227eb:
      fVar23 = DAT_14053ac2c;
      if (iVar15 - 0x28U < 0xa0) goto LAB_140022800;
    }
    else {
      if ((0x9f < iVar15 - 0x28U) || ((int)(iVar15 - 0x28U) % iVar21 != 0)) goto LAB_1400227eb;
      *(ushort *)((longlong)param_1 + 0x42) = uVar19;
LAB_140022800:
      fVar23 = DAT_14053ac2c;
      if ((iVar15 + -0x28) % iVar18 == 0) {
        iVar21 = iVar21 * 2;
        lVar3 = (longlong)(iVar15 + -0x28) % (longlong)iVar21;
        sVar16 = (short)lVar3;
        iVar8 = iVar21 >> 1;
        iVar18 = (int)lVar3;
        sVar12 = sVar16;
        if (iVar8 <= iVar18) {
          sVar12 = (short)iVar21 - sVar16;
        }
        sVar12 = (short)(28000 / (ulonglong)(longlong)iVar8) * sVar12 +
                 *(short *)((longlong)param_1 + 0x42) + -14000;
        if ((float)param_1[0xc] <= 0.0 && (float)param_1[0xc] != 0.0) {
          if (iVar8 <= iVar18) {
            sVar16 = (short)iVar21 - sVar16;
          }
          sVar12 = (short)(-28000 / iVar8) * sVar16 + *(short *)((longlong)param_1 + 0x42) + 14000;
        }
        uVar36 = CONCAT44(uVar32,1);
        uVar32 = CONCAT22(uVar33,sVar12);
        fVar34 = DAT_14053ac2c;
        dVar35 = dVar29;
        FUN_14006c2f0(0x11,0xd,fVar1,fVar31,uVar32,DAT_14053ac2c,dVar29,uVar36,0);
        uVar33 = (undefined2)((uint)uVar32 >> 0x10);
        uVar32 = (undefined4)((ulonglong)uVar36 >> 0x20);
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
      }
    }
    if ((iVar15 - 0xd2U < 0x82) && ((int)(iVar15 - 0xd2U) % iVar11 == 0)) {
      uVar10 = param_1[3] + iVar14;
      uVar10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar10 >> 0x1e ^ uVar10) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar10 = uVar10 * 0x800 ^ uVar10;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar10) >> 8 ^ uVar10 ^ DAT_140e9fd18;
      local_148 = (short)(int)dVar28;
      FUN_14006c2f0(0x11,0xd,fVar1,fVar31,
                    CONCAT22(uVar33,(short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x6d61) * -0x6d61
                                    + local_148 + -14000),fVar23,dVar29,CONCAT44(uVar32,1),0);
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472d4);
      FUN_14018a340(DAT_140e472d4,1,1);
      fVar34 = fVar23;
      dVar35 = dVar29;
    }
    if (0x1d < iVar15) {
      if (0x27 < iVar15) goto LAB_140022f87;
      fVar34 = 0.0;
      local_res8 = FUN_1400c9580(iVar15,0x1e,5,2,0x35,0x36);
    }
  }
  else {
    iVar8 = 1;
    if (DAT_140e419b8 == 0) {
      iVar8 = 0xa0;
    }
    else if (DAT_140e419b8 == 1) {
      iVar8 = 0x87;
    }
    else if (DAT_140e419b8 == 2) {
      iVar8 = 0x50;
    }
    else if (DAT_140e419b8 == 3) {
      iVar8 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar8 = 0x28;
    }
    iVar14 = 1;
    if (DAT_140e419b8 == 0) {
      iVar14 = 0x5a;
    }
    else if (DAT_140e419b8 == 1) {
      iVar14 = 0x4b;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar14 = 0x3c;
    }
    else if (DAT_140e419b8 == 4) {
      iVar14 = 0x28;
    }
    sVar12 = -1;
    sVar20 = 1;
    sVar16 = -1;
    if (DAT_140e419b8 == 0) {
      sVar20 = 0x28;
      sVar16 = -0x28;
    }
    else if (DAT_140e419b8 == 1) {
      sVar20 = 0x3c;
      sVar16 = -0x3c;
    }
    else if (DAT_140e419b8 == 2) {
      sVar20 = 100;
      sVar16 = -100;
    }
    else if (DAT_140e419b8 == 3) {
      sVar20 = 0x78;
      sVar16 = -0x78;
    }
    else if (DAT_140e419b8 == 4) {
      sVar20 = 0xb4;
      sVar16 = -0xb4;
    }
    sVar13 = 1;
    if (DAT_140e419b8 == 0) {
      sVar13 = 0xc;
      sVar12 = -0xc;
    }
    else if (DAT_140e419b8 == 1) {
      sVar13 = 0xf;
      sVar12 = -0xf;
    }
    else if (DAT_140e419b8 == 2) {
      sVar13 = 10;
      sVar12 = -10;
    }
    else if (DAT_140e419b8 == 3) {
      sVar13 = 5;
      sVar12 = -5;
    }
    else if (DAT_140e419b8 == 4) {
      sVar13 = 3;
      sVar12 = -3;
    }
    sVar4 = (short)((iVar15 + -0x230) / iVar8);
    sVar20 = sVar4 * sVar13 + sVar20;
    if (0x4000 < *(ushort *)(param_1 + 0x11)) {
      sVar20 = sVar4 * sVar12 + sVar16;
    }
    if (iVar15 == 0x17c) {
      uVar2 = param_1[1];
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)
                 _malloc_base(0x60,(longlong)(iVar15 + -0x230) % (longlong)iVar8 & 0xffffffff);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar22 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar9 + 0xc) = uVar6;
        puVar9[6] = 0x4014000000000000;
        puVar9[7] = 0x4014000000000000;
        *puVar9 = 1;
        *(undefined4 *)(puVar9 + 1) = 0x31;
        puVar9[2] = 0x23;
        puVar9[3] = 0;
        *(undefined4 *)(puVar9 + 4) = 0;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        *(undefined4 *)(puVar9 + 8) = 0x28;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        *(undefined4 *)(puVar9 + 10) = 0xc0;
        *(undefined4 *)((longlong)puVar9 + 0x54) = uVar2;
        puVar9[0xb] = 0;
        if (bVar22) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
      DAT_140e45d28 = puVar9;
      FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472c0);
      FUN_14018a340(DAT_140e472c0,1,1);
LAB_140022e1c:
      iVar21 = iVar8 * 3 + 0x230;
      if (((iVar21 <= iVar15) && (iVar15 < 0x4a6)) && ((iVar15 - iVar21) % (iVar8 * 4) < iVar14))
      goto LAB_140022e47;
    }
    else {
      if (iVar15 == 0x1b8) {
        *(ushort *)((longlong)param_1 + 0x42) = uVar19;
        uVar17 = uVar19;
        if (0x8000 < uVar19) {
          uVar17 = uVar19 + 0x8000;
          *(ushort *)((longlong)param_1 + 0x42) = uVar17;
        }
        *(ushort *)(param_1 + 0x11) = uVar17;
        goto LAB_140022e1c;
      }
      if (iVar15 - 0x1ccU < 0x65) {
        uVar17 = *(ushort *)((longlong)param_1 + 0x42);
        uVar7 = 0x4000 - uVar17;
        uVar10 = (uint)uVar7;
        if (0x8000 < uVar7) {
          uVar10 = 0x10000 - uVar7;
        }
        iVar11 = -(uint)uVar17 + 0x4000;
        iVar21 = (int)uVar10 / 0x78;
        iVar18 = -(uint)uVar17 + 0x14000;
        if (-0x8001 < iVar11) {
          iVar18 = iVar11;
        }
        iVar11 = iVar18 + -0x10000;
        if (iVar18 < 0x8001) {
          iVar11 = iVar18;
        }
        if (iVar11 < 1) {
          if ((iVar11 < 0) && (uVar17 = uVar17 - (short)iVar21, -iVar21 < iVar11)) {
            uVar17 = 0x4000;
          }
        }
        else if (iVar11 < iVar21) {
          uVar17 = 0x4000;
        }
        else {
          uVar17 = uVar17 + (short)iVar21;
        }
        *(ushort *)((longlong)param_1 + 0x42) = uVar17;
      }
      if ((0x275 < iVar15 - 0x230U) || (iVar14 <= (iVar15 + -0x230) % (iVar8 * 4)))
      goto LAB_140022e1c;
LAB_140022e47:
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) + sVar20;
    }
    if ((((iVar8 + 0x230 <= iVar15) && (iVar15 < 0x4a6)) &&
        ((iVar15 - (iVar8 + 0x230)) % (iVar8 * 4) < iVar14)) ||
       (((iVar21 = iVar8 * 2 + 0x230, iVar21 <= iVar15 && (iVar15 < 0x4a6)) &&
        ((iVar15 - iVar21) % (iVar8 * 4) < iVar14)))) {
      *(short *)((longlong)param_1 + 0x42) = *(short *)((longlong)param_1 + 0x42) - sVar20;
    }
    uVar10 = iVar15 - 0x1b8;
    if ((uVar10 < 0x2ee) &&
       (uVar10 == ((int)uVar10 / 3 + ((int)uVar10 >> 0x1f) +
                  (int)(((longlong)(int)uVar10 / 3 + ((longlong)(int)uVar10 >> 0x3f) & 0xffffffffU)
                       >> 0x1f)) * 3)) {
      iVar8 = 27000;
      if (iVar15 < 500) {
        iVar8 = (0x221 - iVar15) * 600;
      }
      sVar16 = *(short *)((longlong)param_1 + 0x42);
      uVar19 = uVar19 - sVar16;
      uVar10 = (uint)uVar19;
      if (0x8000 < uVar19) {
        uVar10 = 0x10000 - uVar19;
      }
      if (0x4000 < (int)uVar10) {
        sVar16 = sVar16 + -0x8000;
      }
      fVar34 = DAT_14053ac2c;
      dVar35 = DAT_14053a238;
      FUN_1400709b0(6,0,fVar1,fVar31,CONCAT22(uVar33,sVar16),DAT_14053ac2c,DAT_14053a238,
                    CONCAT44(uVar32,1),5,iVar8,0);
      FUN_140184700(DAT_140e44190 << 4,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    if (iVar15 - 0x1aeU < 0x2f9) {
LAB_140022f87:
      dVar35 = 2.81617418129511e-322;
      fVar34 = 0.0;
      local_res8 = FUN_1400c9580(iVar15,0x28,5,3,0x37,0x38,0x39);
    }
  }
  if (iVar15 - 0x168U < 10) {
    fVar34 = 0.0;
    local_res8 = FUN_1400c9580(iVar15,0x168,5,2,0x36,0x35,dVar35);
  }
  if (iVar15 - 0x1a4U < 10) {
    fVar34 = 0.0;
    local_res8 = FUN_1400c9580(iVar15,0x1a4,5,2,0x35,0x36,dVar35);
  }
  if (iVar15 - 0x4a7U < 10) {
    fVar34 = 0.0;
    local_res8 = FUN_1400c9580(iVar15,0x4a7,5,2,0x36,0x35);
  }
  iVar8 = param_1[7];
  if (iVar8 < iStack_124) {
    iVar14 = param_1[2];
    lVar3 = DAT_140e45d80;
    if (0 < DAT_140e44e6c) {
      for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
        if (*(int *)(lVar3 + 4) == iVar14) {
          *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) - (iStack_124 - iVar8);
        }
      }
    }
  }
  iVar8 = param_1[7];
  if (iStack_124 < iVar8) {
    param_1[7] = iStack_124;
    iVar8 = iStack_124;
  }
  if ((iVar8 < 1) && (iVar8 = param_1[2], lVar3 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      if (*(int *)(lVar3 + 4) == iVar8) {
        *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) - iStack_124;
      }
    }
  }
  if ((iStack_124 < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,1);
    *param_1 = 0;
  }
LAB_14002311c:
  uVar10 = (uint)fVar34 & 0xffff0000;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res8 * 4),0x23,7,param_1[10],
                param_1[0xb],uVar10,dVar25,dVar30,0xff,0xff,0xff,0xff,1,0);
  if (local_res10 != 0) {
    FUN_1400c8410(*(undefined4 *)(&DAT_140e44310 + (longlong)local_res8 * 4),0x23,8,param_1[10],
                  param_1[0xb],uVar10 & 0xffff0000,dVar25,dVar30,0xff,0xff,0xff,local_res10,1,0);
  }
  return;
}


