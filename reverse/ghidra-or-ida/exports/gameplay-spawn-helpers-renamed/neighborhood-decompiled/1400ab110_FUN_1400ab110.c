// Function: FUN_1400ab110 @ 1400ab110
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400ab110(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;
  double dVar3;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  undefined2 uVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  bool bVar18;
  float fVar19;
  double dVar20;
  undefined4 uVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float local_e8 [5];
  float local_d4;
  
  uVar17 = 0;
  pfVar14 = (float *)(param_1 + 0xb);
  fVar19 = (float)DAT_1407c77a4 + *pfVar14;
  iVar7 = param_1[5];
  *pfVar14 = fVar19;
  if ((iVar7 == 0) && (DAT_14053b3a0 <= fVar19)) {
    stage_entity_spawn_candidate(0x151,99999999,1,0,DAT_14053ad40,0xfda8,0,0x78,1,param_1[1]);
    param_1[5] = param_1[5] + 1;
    iVar7 = param_1[5];
    fVar19 = *pfVar14;
    param_1[3] = 0;
    param_1[0x15] = 0;
  }
  uVar2 = DAT_14053ac2c;
  dVar6 = DAT_140539f68;
  dVar5 = DAT_140539f40;
  dVar3 = DAT_140539eb8;
  if (iVar7 == 1) {
    if ((int)param_1[3] < 400) {
      local_e8[4] = (float)param_1[10];
      uVar24 = SUB84(DAT_140539f40,0);
      uVar26 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
      uVar25 = (undefined4)DAT_14053a118;
      uVar27 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      pfVar14 = local_e8;
      local_e8[0] = local_e8[4] - _DAT_14053ad08;
      local_e8[1] = fVar19 + DAT_14053ad70;
      uVar28 = (undefined4)DAT_14053a158;
      uVar29 = (undefined4)((ulonglong)DAT_14053a158 >> 0x20);
      uVar30 = (undefined4)DAT_14053a160;
      uVar4 = (ulonglong)DAT_14053a160 >> 0x20;
      local_e8[2] = local_e8[4] + DAT_14053ad10;
      local_e8[3] = fVar19 + DAT_14053ad1c;
      iVar15 = (param_1[3] + -0x28) % 200;
      local_d4 = fVar19 + DAT_14053aa20;
      iVar7 = DAT_140e419b8;
      do {
        fVar19 = pfVar14[1];
        fVar22 = *pfVar14;
        dVar20 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar19),
                                       (double)(DAT_140e445d8 - fVar22));
        uVar13 = (undefined2)(int)(dVar20 * DAT_14053aba0);
        if (uVar17 < 2) {
          iVar16 = uVar17 * 0x32;
          uVar11 = 1;
          if (iVar7 == 0) {
            uVar11 = 0xf;
          }
          else if (iVar7 == 1) {
            uVar11 = 0x18;
          }
          else if (((iVar7 == 2) || (iVar7 == 3)) || (iVar7 == 4)) {
            uVar11 = 0x1b;
          }
          iVar12 = iVar15 + uVar17 * -0x32;
          iVar10 = (int)(30000 / uVar11) * iVar12;
          if (iVar7 == 0) {
            uVar21 = (int)DAT_14053a0d0;
            uVar23 = (int)((ulonglong)DAT_14053a0d0 >> 0x20);
          }
          else {
            uVar21 = uVar25;
            uVar23 = uVar27;
            if (((iVar7 != 1) && (uVar21 = uVar28, uVar23 = uVar29, iVar7 != 2)) &&
               ((uVar21 = uVar25, uVar23 = uVar27, iVar7 != 3 &&
                (uVar21 = uVar24, uVar23 = uVar26, iVar7 == 4)))) {
              uVar21 = uVar30;
              uVar23 = (int)uVar4;
            }
          }
          dVar20 = DAT_140539e70;
          if (((iVar7 != 0) && (dVar20 = DAT_140539ea0, iVar7 != 1)) &&
             ((iVar7 == 2 || ((iVar7 == 3 || (dVar20 = dVar5, iVar7 == 4)))))) {
            dVar20 = dVar3;
          }
          dVar20 = (double)CONCAT44(uVar23,uVar21) - ((double)iVar15 - (double)iVar16) * dVar20;
          if (iVar15 == iVar16) {
            *(undefined2 *)((longlong)param_1 + 0x42) = uVar13;
LAB_1400ab43d:
            iVar12 = iVar12 % 200;
            if ((iVar12 < (int)uVar11) &&
               (iVar12 == (iVar12 / 3 + (iVar12 >> 0x1f) +
                          (int)(((longlong)iVar12 / 3 + ((longlong)iVar12 >> 0x3f) & 0xffffffffU) >>
                               0x1f)) * 3)) {
              FUN_1400709b0(3,0,fVar22,fVar19,*(undefined2 *)((longlong)param_1 + 0x42),uVar2,dVar20
                            ,1,2,iVar10,0);
              if (2 < DAT_140e419b8) {
                FUN_1400709b0(3,0,fVar22,fVar19,*(undefined2 *)((longlong)param_1 + 0x42),uVar2,
                              dVar20 + DAT_140539fe8,1,2,iVar10,0);
              }
              FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
              FUN_14018a340(DAT_140e472a4,1,1);
              iVar7 = DAT_140e419b8;
            }
          }
          else if (iVar16 <= iVar15) goto LAB_1400ab43d;
          if (((iVar16 + 1 <= iVar15) &&
              (iVar16 = (iVar15 - (iVar16 + 1)) % 200, iVar16 < (int)uVar11)) &&
             (iVar16 == (iVar16 / 3 + (iVar16 >> 0x1f) +
                        (int)(((longlong)iVar16 / 3 + ((longlong)iVar16 >> 0x3f) & 0xffffffffU) >>
                             0x1f)) * 3)) {
            FUN_1400709b0(5,0,fVar22,fVar19,*(undefined2 *)((longlong)param_1 + 0x42),uVar2,
                          dVar20 - dVar6,1,2,iVar10,0);
            if (2 < DAT_140e419b8) {
              FUN_1400709b0(5,0,fVar22,fVar19,*(undefined2 *)((longlong)param_1 + 0x42),uVar2,
                            dVar20 + dVar6,1,2,iVar10,0);
            }
            FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
            iVar7 = DAT_140e419b8;
          }
        }
        else if (uVar17 == 2) {
          if ((iVar7 != 0) && (uVar25 = uVar28, uVar27 = uVar29, iVar7 != 1)) {
            if ((iVar7 == 2) || (iVar7 == 3)) {
              uVar25 = (int)DAT_14053a190;
              uVar27 = (int)((ulonglong)DAT_14053a190 >> 0x20);
            }
            else {
              uVar25 = uVar24;
              uVar27 = uVar26;
              if (iVar7 == 4) {
                uVar25 = (int)DAT_14053a210;
                uVar27 = (int)((ulonglong)DAT_14053a210 >> 0x20);
              }
            }
          }
          if (iVar15 == 0x6e) {
            *(undefined2 *)((longlong)param_1 + 0x42) = uVar13;
            iVar7 = 0;
          }
          else if ((iVar15 < 0x6e) || (iVar7 = (iVar15 + -0x6e) % 200, 0x27 < iVar7)) break;
          iVar15 = 0;
          if (iVar7 == (iVar7 / 5) * 5) {
            sVar1 = *(short *)((longlong)param_1 + 0x42);
            iVar7 = iVar15;
            do {
              FUN_14006c2f0(10,0,fVar22,fVar19,(short)iVar7 * 900 + sVar1 + -900,uVar2,
                            CONCAT44(uVar27,uVar25),1,0);
              iVar7 = iVar7 + 1;
            } while (iVar7 < 3);
            if (2 < DAT_140e419b8) {
              dVar3 = (double)CONCAT44(uVar27,uVar25) - DAT_140539f28;
              sVar1 = *(short *)((longlong)param_1 + 0x42);
              do {
                FUN_14006c2f0(10,0,fVar22,fVar19,(short)iVar15 * 0xce4 + sVar1 + -0x672,uVar2,dVar3,
                              1,0);
                iVar15 = iVar15 + 1;
              } while (iVar15 < 2);
            }
            FUN_140184700(DAT_140e44190 * 0x13,DAT_140e472a4);
            FUN_14018a340(DAT_140e472a4,1,1);
          }
          break;
        }
        uVar17 = uVar17 + 1;
        pfVar14 = pfVar14 + 2;
      } while ((int)uVar17 < 3);
      iVar7 = param_1[5];
    }
    if ((int)param_1[7] < 1) {
      FUN_14007b010(param_1,0x708,0x1e);
      FUN_140109660(0x18);
      uVar2 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar2;
        puVar8[2] = 0x6f;
        puVar8[3] = 0;
        *(undefined4 *)(puVar8 + 4) = 0;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar18) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      iVar7 = param_1[5] + 1;
      param_1[5] = iVar7;
      param_1[0x15] = 1;
      param_1[3] = 0;
    }
  }
  fVar19 = DAT_14053acbc;
  if ((iVar7 == 2) && ((int)param_1[3] < 0x3d)) {
    FUN_14007ac00(param_1);
    uVar2 = DAT_140e449e4;
    if (param_1[3] == 0x3c) {
      fVar22 = (float)param_1[0xb] + fVar19;
      uVar25 = param_1[10];
      puVar8 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar8 = (undefined8 *)_malloc_base(0x60);
        if (puVar8 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar18 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)((longlong)puVar8 + 0x14) = uVar25;
        *(float *)(puVar8 + 3) = fVar22;
        *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar25;
        *(float *)(puVar8 + 4) = fVar22;
        *puVar8 = 1;
        *(undefined4 *)(puVar8 + 1) = 0x37;
        *(undefined4 *)((longlong)puVar8 + 0xc) = uVar2;
        *(undefined4 *)(puVar8 + 2) = 0x1c;
        *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
        puVar8[5] = 0x3ff0000000000000;
        puVar8[6] = 0x3ff0000000000000;
        puVar8[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar8 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
        *(undefined4 *)(puVar8 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
        puVar8[10] = 0xff;
        puVar8[0xb] = 0;
        if (bVar18) {
          DAT_140e45d78 = puVar8;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar8;
        }
      }
      DAT_140e45d28 = puVar8;
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  uVar25 = DAT_140e449e0;
  fVar22 = (float)param_1[0xb];
  uVar2 = param_1[10];
  puVar9 = (undefined4 *)_malloc_base(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  DAT_140e46cf8 = DAT_140e46cf8 + 1;
  bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
  puVar9[3] = uVar2;
  puVar9[4] = fVar22 + fVar19;
  *puVar9 = uVar25;
  *(undefined8 *)(puVar9 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar9 + 8) = 0x3ff0000000000000;
  puVar9[1] = 0x1a;
  puVar9[2] = 7;
  *(undefined2 *)(puVar9 + 5) = 0;
  puVar9[10] = 0xff;
  puVar9[0xb] = 0xff;
  puVar9[0xc] = 0xff;
  puVar9[0xd] = 0xff;
  *(undefined8 *)(puVar9 + 0xe) = 1;
  *(undefined8 *)(puVar9 + 0x10) = 0;
  if (bVar18) {
    DAT_140e46bf0 = puVar9;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar9;
  }
  DAT_140e46c88 = puVar9;
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if (DAT_14053afbc <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


