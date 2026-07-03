// Function: FUN_14006ce40 @ 14006ce40
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14006ce40(undefined4 *param_1)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined2 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  short sVar19;
  short sVar20;
  ulonglong uVar21;
  int iVar22;
  int iVar23;
  undefined8 uVar24;
  bool bVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined4 in_stack_fffffffffffffe38;
  undefined2 uVar47;
  undefined8 in_stack_fffffffffffffe50;
  undefined4 uVar48;
  ulonglong in_stack_fffffffffffffe58;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined8 uStack_150;
  undefined1 local_f0 [184];
  
  dVar30 = DAT_14053a020;
  uVar47 = (undefined2)((uint)in_stack_fffffffffffffe38 >> 0x10);
  uVar48 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
  iVar18 = 0;
  sVar19 = *(short *)(param_1 + 9);
  iVar23 = 0;
  iVar22 = 0;
  uVar24 = 0x50;
  dVar29 = *(double *)(param_1 + 10);
  fVar1 = (float)param_1[8];
  param_1[8] = (float)dVar29 + fVar1;
  dVar28 = (double)((float)dVar29 + fVar1);
  dVar26 = (double)FUN_1403307c0();
  fVar46 = (float)(dVar26 * dVar28) + (float)param_1[4];
  dVar26 = (double)FUN_140332d90();
  fVar44 = DAT_140e445d8;
  fVar45 = (float)(dVar26 * dVar28) + (float)param_1[5];
  dVar27 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar45));
  iVar16 = DAT_140e418c8;
  dVar31 = DAT_14053aba0;
  fVar1 = DAT_14053ab70;
  uVar3 = DAT_14053a190;
  uVar2 = DAT_14053a110;
  uVar7 = DAT_14053a0b8;
  dVar26 = DAT_140539f90;
  dVar28 = DAT_140539f68;
  uVar14 = (uint)(in_stack_fffffffffffffe58 >> 0x20);
  iVar17 = param_1[3];
  uVar15 = (undefined2)(int)(dVar27 * DAT_14053aba0);
  uVar36 = SUB84(DAT_140539f40,0);
  uVar42 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  uVar34 = (undefined4)DAT_14053a0b0;
  uVar39 = (undefined4)((ulonglong)DAT_14053a0b0 >> 0x20);
  uVar38 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
  uVar37 = (undefined4)DAT_14053a088;
  uVar43 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
  uVar35 = (undefined4)DAT_14053a070;
  uVar41 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
  uVar40 = (undefined4)((ulonglong)DAT_14053a030 >> 0x20);
  iVar6 = iVar18;
  switch(iVar17) {
  case 0x17:
    iVar6 = iVar22;
    if (param_1[1] == 0x19) {
      FUN_14006c2f0(3,1,fVar46,fVar45,CONCAT22(uVar47,uVar15),0,DAT_140539fc8,
                    CONCAT44(uVar48,param_1[0xe]),(ulonglong)uVar14 << 0x20);
    }
    break;
  case 0x18:
  case 0x19:
    iVar16 = 1;
    if (DAT_140e419b8 == 0) {
      iVar16 = 0xc;
    }
    else if (DAT_140e419b8 == 1) {
      iVar16 = 0x10;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar16 = 0x14;
    }
    uVar11 = param_1[1];
    uVar24 = 0x51;
    if (((0xf < (int)uVar11) && ((int)uVar11 < iVar16 + 0x10)) && ((uVar11 & 1) == 0)) {
      if (iVar17 == 0x18) {
        in_stack_fffffffffffffe58 = (ulonglong)uVar14 << 0x20;
        uVar7 = CONCAT44(uVar48,param_1[0xe]);
        uVar37 = CONCAT22(uVar47,sVar19 + (short)uVar11 * -200 + -0x36a0);
        FUN_14006c2f0(0xc,1,fVar46,fVar45,uVar37,0,DAT_140539f90,uVar7,in_stack_fffffffffffffe58);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        uVar11 = (uint)*(ushort *)(param_1 + 1);
      }
      if (param_1[3] == 0x19) {
        FUN_14006c2f0(0xd,1,fVar46,fVar45,
                      CONCAT22(uVar47,(short)uVar11 * 200 + *(short *)(param_1 + 9) + 0x36a0),0,
                      dVar26,CONCAT44(uVar48,param_1[0xe]),
                      in_stack_fffffffffffffe58 & 0xffffffff00000000);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    uVar37 = DAT_140e41a50;
    iVar6 = iVar22;
    if (param_1[1] == iVar16 + 0x10) {
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined4 *)(puVar9 + 8) = 0x10;
LAB_14006e5ed:
        DAT_140e45d1c = DAT_140e45d1c + 1;
        bVar25 = DAT_140e45d78 == (undefined8 *)0x0;
        *(float *)((longlong)puVar9 + 0x14) = fVar46;
        *(float *)(puVar9 + 3) = fVar45;
        *(float *)((longlong)puVar9 + 0x1c) = fVar46;
        *(float *)(puVar9 + 4) = fVar45;
        *puVar9 = 1;
        *(undefined4 *)(puVar9 + 1) = 0xc;
        *(undefined4 *)((longlong)puVar9 + 0xc) = uVar37;
        *(undefined4 *)(puVar9 + 2) = 0x3d;
        *(undefined2 *)((longlong)puVar9 + 0x24) = 0;
        puVar9[5] = 0;
        puVar9[6] = 0x3fe3333333333333;
        puVar9[7] = 0x3fe3333333333333;
        *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
        *(undefined4 *)(puVar9 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
        puVar9[10] = 0xff;
        puVar9[0xb] = 0;
        if (bVar25) {
          DAT_140e45d78 = puVar9;
        }
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar9;
        }
      }
LAB_14006e686:
      DAT_140e45d28 = puVar9;
      *param_1 = 0;
      iVar6 = iVar22;
    }
    break;
  case 0x1a:
  case 0x1b:
    iVar17 = 1;
    if (DAT_140e419b8 == 0) {
      iVar17 = 10;
    }
    else if (DAT_140e419b8 == 1) {
      iVar17 = 8;
    }
    else if (DAT_140e419b8 == 2) {
      iVar17 = 6;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar17 = 5;
    }
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
LAB_14006d21a:
        uVar34 = (undefined4)DAT_14053a0f8;
        uVar39 = (undefined4)((ulonglong)DAT_14053a0f8 >> 0x20);
      }
      else if (DAT_140e419b8 == 2) {
        uVar34 = (undefined4)DAT_14053a118;
        uVar39 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
      }
      else {
        if (DAT_140e419b8 == 3) goto LAB_14006d21a;
        uVar34 = uVar36;
        uVar39 = uVar42;
        if (DAT_140e419b8 == 4) {
          uVar34 = (undefined4)DAT_14053a138;
          uVar39 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
        }
      }
    }
    uVar24 = 0x51;
    if (((-1 < (int)param_1[1]) && ((int)param_1[1] % iVar17 == 0)) &&
       ((fVar44 / DAT_14053ab70 + 0.0 <= fVar46 &&
        (((fVar46 <= fVar44 / DAT_14053ab70 + DAT_14053aec0 && (0.0 <= fVar45)) &&
         (fVar45 <= DAT_14053af14)))))) {
      if (param_1[3] == 0x1a) {
        in_stack_fffffffffffffe58 = (ulonglong)uVar14 << 0x20;
        uVar7 = CONCAT44(uVar48,param_1[0xe]);
        uVar37 = CONCAT22(uVar47,(0x78 - *(short *)(param_1 + 1)) * 0xfa + *(short *)(param_1 + 9));
        FUN_14006c2f0(8,2,fVar46,fVar45,uVar37,0,CONCAT44(uVar39,uVar34),uVar7,
                      in_stack_fffffffffffffe58);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (2 < DAT_140e419b8) {
          in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
          uVar7 = CONCAT44(uVar48,param_1[0xe]);
          uVar37 = CONCAT22(uVar47,(0x78 - *(short *)(param_1 + 1)) * 0xfa + *(short *)(param_1 + 9)
                           );
          FUN_14006c2f0(8,2,fVar46,fVar45,uVar37,0,(double)CONCAT44(uVar39,uVar34) + dVar26,uVar7,
                        in_stack_fffffffffffffe58);
          uVar47 = (undefined2)((uint)uVar37 >> 0x10);
          uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        }
      }
      if (param_1[3] == 0x1b) {
        in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
        FUN_14006c2f0(9,2,fVar46,fVar45,
                      CONCAT22(uVar47,*(short *)(param_1 + 1) * 0xfa + *(short *)(param_1 + 9) +
                                      -30000),0,CONCAT44(uVar39,uVar34),
                      CONCAT44(uVar48,param_1[0xe]),in_stack_fffffffffffffe58);
        if (2 < DAT_140e419b8) {
          FUN_14006c2f0(9,2,fVar46,fVar45,
                        *(short *)(param_1 + 1) * 0xfa + *(short *)(param_1 + 9) + -30000,0,
                        (double)CONCAT44(uVar39,uVar34) + dVar26,param_1[0xe],
                        in_stack_fffffffffffffe58 & 0xffffffff00000000);
        }
      }
      iVar17 = DAT_140e44190 * 9;
LAB_14006e2d8:
      FUN_140184700(iVar17,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
    }
    goto LAB_14006e2f6;
  case 0x1c:
    iVar17 = 1;
    if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
      iVar17 = 0x12;
    }
    else if (DAT_140e419b8 == 2) {
      iVar17 = 0xf;
    }
    else if (DAT_140e419b8 == 3) {
      iVar17 = 0x10;
    }
    else if (DAT_140e419b8 == 4) {
      iVar17 = 0xe;
    }
    iVar16 = 1;
    if (DAT_140e419b8 == 0) {
      iVar16 = 6;
    }
    else if (DAT_140e419b8 == 1) {
      iVar16 = 7;
    }
    else if (DAT_140e419b8 == 2) {
      iVar16 = 8;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar16 = 10;
    }
    uVar34 = (int)DAT_14053a030;
    if ((((DAT_140e419b8 != 0) && (uVar34 = uVar35, uVar40 = uVar41, DAT_140e419b8 != 1)) &&
        (uVar34 = uVar37, uVar40 = uVar43, DAT_140e419b8 != 2)) &&
       ((DAT_140e419b8 != 3 && (uVar34 = uVar36, uVar40 = uVar42, DAT_140e419b8 == 4)))) {
      uVar34 = (int)DAT_14053a0d0;
      uVar40 = uVar38;
    }
    uVar24 = 0x51;
    iVar6 = param_1[1] + DAT_140e418c8;
    if (((iVar6 / 2 < 0) ||
        (iVar16 <= (int)(CONCAT44(iVar6 - (iVar6 >> 0x1f) >> 0x1f,iVar6 / 2) % (longlong)iVar17)))
       || ((fVar46 < fVar44 / DAT_14053ab70 + 0.0 ||
           (((fVar44 / DAT_14053ab70 + DAT_14053aec0 < fVar46 || (fVar45 < 0.0)) ||
            (DAT_14053af14 < fVar45)))))) goto LAB_14006e2f6;
    uVar37 = param_1[0xe];
    sVar19 = *(short *)(param_1 + 9);
    do {
      in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
      FUN_14006c2f0(9,2,fVar46,fVar45,(short)iVar18 * -0x8000 + sVar19 + -0x4000,0,
                    CONCAT44(uVar40,uVar34),uVar37,in_stack_fffffffffffffe58);
      iVar18 = iVar18 + 1;
    } while (iVar18 < 2);
    iVar6 = 1;
    break;
  case 0x1d:
  case 0x1e:
    iVar6 = 1;
    if (DAT_140e419b8 == 0) {
      iVar6 = 4;
    }
    else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
      iVar6 = 3;
    }
    else if (DAT_140e419b8 == 4) {
      iVar6 = 2;
    }
    if (DAT_140e419b8 == 0) {
      uVar37 = (int)DAT_140539ff0;
      uVar40 = (int)((ulonglong)DAT_140539ff0 >> 0x20);
    }
    else {
      uVar37 = (int)DAT_14053a030;
      if (DAT_140e419b8 != 1) {
        if (DAT_140e419b8 == 2) {
          uVar37 = (int)DAT_14053a048;
          uVar40 = (int)((ulonglong)DAT_14053a048 >> 0x20);
        }
        else {
          uVar37 = uVar35;
          uVar40 = uVar41;
          if ((DAT_140e419b8 != 3) && (uVar37 = uVar36, uVar40 = uVar42, DAT_140e419b8 == 4)) {
            uVar37 = uVar34;
            uVar40 = uVar39;
          }
        }
      }
    }
    iVar18 = param_1[1];
    uVar24 = 0x51;
    if (iVar17 == 0x1d) {
      dVar29 = (double)FUN_140332d90(((double)iVar18 - (double)(iVar18 + DAT_140e418c8 * -2)) *
                                     _DAT_14053a8e8 * dVar30 * DAT_140539d28);
      dVar29 = (double)((float)(dVar29 * (double)iVar18) + 0.0);
      dVar28 = (double)FUN_1403307c0();
      fVar46 = (float)(dVar28 * dVar29) + fVar46;
      dVar28 = (double)FUN_140332d90();
      fVar45 = (float)(dVar28 * dVar29) + fVar45;
    }
    else if (iVar17 == 0x1e) {
      dVar29 = (double)FUN_140332d90(((double)iVar18 - (double)(iVar18 + DAT_140e418c8 * -2)) *
                                     _DAT_14053a8e8 * dVar30 * DAT_140539d28);
      dVar29 = (double)((float)(dVar29 * (double)iVar18) + 0.0);
      dVar28 = (double)FUN_1403307c0();
      fVar46 = (float)(dVar28 * dVar29) + fVar46;
      dVar28 = (double)FUN_140332d90();
      fVar45 = (float)(dVar28 * dVar29) + fVar45;
    }
    fVar5 = DAT_14053af14;
    fVar4 = DAT_14053aec0;
    iVar18 = iVar18 + iVar16;
    if (((-1 < iVar18 / 2) &&
        ((int)(CONCAT44(iVar18 - (iVar18 >> 0x1f) >> 0x1f,iVar18 / 2) % (longlong)(iVar6 * 2)) == 0)
        ) && ((fVar44 / fVar1 + 0.0 <= fVar46 &&
              (((fVar46 <= fVar44 / fVar1 + DAT_14053aec0 && (0.0 <= fVar45)) &&
               (fVar45 <= DAT_14053af14)))))) {
      in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
      uVar7 = CONCAT44(uVar48,param_1[0xe]);
      uVar35 = CONCAT22(uVar47,*(short *)(param_1 + 9) + 0x4000);
      FUN_14006c2f0(0xd,2,fVar46,fVar45,uVar35,0,CONCAT44(uVar40,uVar37),uVar7,
                    in_stack_fffffffffffffe58);
      uVar47 = (undefined2)((uint)uVar35 >> 0x10);
      uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      fVar44 = DAT_140e445d8;
      iVar16 = DAT_140e418c8;
    }
    iVar17 = (param_1[1] + iVar16) / 2;
    if (((iVar6 <= iVar17) && ((iVar17 - iVar6) % (iVar6 * 2) == 0)) &&
       (((fVar44 / fVar1 + 0.0 <= fVar46 && ((fVar46 <= fVar44 / fVar1 + fVar4 && (0.0 <= fVar45))))
        && (fVar45 <= fVar5)))) {
      FUN_14006c2f0(0xd,2,fVar46,fVar45,CONCAT22(uVar47,*(short *)(param_1 + 9) + -0x4000),0,
                    CONCAT44(uVar40,uVar37),CONCAT44(uVar48,param_1[0xe]),
                    in_stack_fffffffffffffe58 & 0xffffffff00000000);
LAB_14006e2cc:
      iVar17 = DAT_140e44190 * 0xc;
      goto LAB_14006e2d8;
    }
    goto LAB_14006e2f6;
  case 0x1f:
  case 0x20:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x2c:
  case 0x2d:
  case 0x35:
  case 0x36:
  case 0x3a:
  case 0x3b:
    break;
  case 0x21:
  case 0x22:
    iVar6 = iVar22;
    if (param_1[1] == 0x24) {
      if (iVar17 == 0x21) {
        in_stack_fffffffffffffe58 = (ulonglong)uVar14 << 0x20;
        uVar7 = CONCAT44(uVar48,param_1[0xe]);
        uVar37 = CONCAT22(uVar47,sVar19 + 12000);
        FUN_14006c2f0(2,4,fVar46,fVar45,uVar37,0,*(double *)(param_1 + 0xc) + DAT_140539f68,uVar7,
                      in_stack_fffffffffffffe58);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        sVar19 = *(short *)(param_1 + 9);
      }
      if (param_1[3] == 0x22) {
        FUN_14006c2f0(2,4,fVar46,fVar45,CONCAT22(uVar47,sVar19 + -12000),0,
                      *(double *)(param_1 + 0xc) + dVar28,CONCAT44(uVar48,param_1[0xe]),
                      in_stack_fffffffffffffe58 & 0xffffffff00000000);
      }
    }
    break;
  case 0x28:
    if ((0 < DAT_140e44e6c) && (lVar8 = DAT_140e45d80, DAT_140e45d80 != 0)) {
      do {
        if (*(int *)(lVar8 + 4) == param_1[0x11]) {
          uStack_150 = *(undefined8 *)(lVar8 + 8);
        }
        lVar8 = *(longlong *)(lVar8 + 0x60);
      } while (lVar8 != 0);
      sVar19 = *(short *)(param_1 + 9);
    }
    iVar17 = (uStack_150._4_4_ + -0x3c) % 0x578;
    if ((iVar17 == 0x366) || (iVar6 = iVar22, iVar17 == 0x3fc)) {
      uVar37 = param_1[0xe];
      dVar29 = *(double *)(param_1 + 0xc) - DAT_140539f40;
      do {
        in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
        FUN_14006c2f0(8,4,fVar46,fVar45,(short)iVar18 * 18000 + sVar19 + -9000,0,dVar29,uVar37,
                      in_stack_fffffffffffffe58);
        iVar18 = iVar18 + 1;
      } while (iVar18 < 2);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      uVar24 = 0x50;
      iVar6 = iVar22;
    }
    break;
  case 0x29:
  case 0x2a:
    iVar17 = 1;
    if (DAT_140e419b8 == 0) {
      iVar17 = 8;
    }
    else if (DAT_140e419b8 == 1) {
      iVar17 = 6;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      iVar17 = 5;
    }
    if (DAT_140e419b8 == 0) {
      uVar35 = (undefined4)DAT_14053a018;
      uVar41 = (undefined4)((ulonglong)DAT_14053a018 >> 0x20);
    }
    else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
      uVar35 = (undefined4)DAT_14053a040;
      uVar41 = (undefined4)((ulonglong)DAT_14053a040 >> 0x20);
    }
    else if ((DAT_140e419b8 != 3) && (uVar35 = uVar36, uVar41 = uVar42, DAT_140e419b8 == 4)) {
      uVar35 = uVar34;
      uVar41 = uVar39;
    }
    uVar11 = param_1[1];
    if ((((-1 < (int)uVar11) && ((int)uVar11 % iVar17 == 0)) &&
        (fVar44 / DAT_14053ab70 + 0.0 <= fVar46)) &&
       (((fVar46 <= fVar44 / DAT_14053ab70 + DAT_14053aec0 && (0.0 <= fVar45)) &&
        (fVar45 <= DAT_14053af14)))) {
      if (param_1[3] == 0x29) {
        in_stack_fffffffffffffe58 = (ulonglong)uVar14 << 0x20;
        uVar7 = CONCAT44(uVar48,param_1[0xe]);
        uVar37 = CONCAT22(uVar47,(short)uVar11 * 200 + *(short *)(param_1 + 9) + -24000);
        FUN_14006c2f0(8,4,fVar46,fVar45,uVar37,0,CONCAT44(uVar41,uVar35),uVar7,
                      in_stack_fffffffffffffe58);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        uVar11 = (uint)*(ushort *)(param_1 + 1);
      }
      if (param_1[3] == 0x2a) {
        FUN_14006c2f0(9,4,fVar46,fVar45,
                      CONCAT22(uVar47,*(short *)(param_1 + 9) + (short)uVar11 * -200 + 24000),0,
                      CONCAT44(uVar41,uVar35),CONCAT44(uVar48,param_1[0xe]),
                      in_stack_fffffffffffffe58 & 0xffffffff00000000);
      }
      goto LAB_14006e2cc;
    }
    goto LAB_14006e2f6;
  case 0x2b:
    uVar37 = 1;
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
        uVar37 = 3;
      }
      else if (DAT_140e419b8 == 2) {
        uVar37 = 5;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        uVar37 = 7;
      }
    }
    if (DAT_140e419b8 == 0) {
      uVar36 = (undefined4)DAT_14053a178;
      uVar42 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
      uVar36 = (undefined4)DAT_14053a1e8;
      uVar42 = (undefined4)((ulonglong)DAT_14053a1e8 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar36 = (undefined4)DAT_14053a208;
      uVar42 = (undefined4)((ulonglong)DAT_14053a208 >> 0x20);
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      uVar36 = (undefined4)DAT_14053a218;
      uVar42 = (undefined4)((ulonglong)DAT_14053a218 >> 0x20);
    }
    uVar11 = param_1[1];
    if (uVar11 == 0) {
      param_1[6] = fVar44;
      param_1[7] = DAT_140e445dc;
      fVar44 = DAT_140e445d8;
    }
    else if (0x23 < uVar11) goto LAB_14006e2f6;
    if ((((uVar11 == ((int)uVar11 / 3 + ((int)uVar11 >> 0x1f) +
                     (int)(((longlong)(int)uVar11 / 3 + ((longlong)(int)uVar11 >> 0x3f) &
                           0xffffffffU) >> 0x1f)) * 3) && (fVar44 / fVar1 + 0.0 <= fVar46)) &&
        (fVar46 <= fVar44 / fVar1 + DAT_14053aec0)) &&
       ((0.0 <= fVar45 && (fVar45 <= DAT_14053af14)))) {
      dVar29 = (double)FUN_1403300b4((double)((float)param_1[7] - fVar45),
                                     (double)((float)param_1[6] - fVar46));
      FUN_1400709b0(0xc,4,fVar46,fVar45,CONCAT22(uVar47,(short)(int)(dVar29 * dVar31)),0,
                    CONCAT44(uVar42,uVar36),CONCAT44(uVar48,param_1[0xe]),CONCAT44(uVar14,uVar37),
                    20000,0);
      goto LAB_14006e2cc;
    }
    goto LAB_14006e2f6;
  case 0x2e:
    fVar44 = fVar44 / DAT_14053ab70;
    if ((((fVar46 < fVar44 + 0.0) || (fVar44 + DAT_14053aec0 < fVar46)) || (fVar45 < 0.0)) ||
       (DAT_14053af14 < fVar45)) {
      uVar35 = 1;
      uVar21 = 5;
      if (DAT_140e419b8 == 0) {
        uVar35 = 3;
      }
      else if (DAT_140e419b8 == 1) {
        uVar35 = 5;
      }
      else if (DAT_140e419b8 == 2) {
        uVar35 = 6;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        uVar35 = 7;
      }
      if (((DAT_140e419b8 != 0) && (uVar37 = uVar34, uVar43 = uVar39, DAT_140e419b8 != 1)) &&
         ((DAT_140e419b8 != 2 &&
          ((DAT_140e419b8 == 3 || (uVar37 = uVar36, uVar43 = uVar42, DAT_140e419b8 == 4)))))) {
        uVar37 = (int)DAT_14053a0d0;
        uVar43 = uVar38;
      }
      sVar19 = *(short *)(param_1 + 9);
      sVar10 = -0x8000 - sVar19;
      if (fVar44 + 0.0 <= fVar46) {
        sVar10 = sVar19;
      }
      if (0.0 <= fVar45) {
        sVar20 = -0x8000 - sVar19;
        if (fVar46 <= fVar44 + DAT_14053aec0) {
          sVar20 = sVar10;
        }
      }
      else {
        sVar20 = -sVar19;
      }
      if (DAT_14053af14 < fVar45) {
        sVar20 = -sVar19;
      }
      *(short *)(param_1 + 9) = sVar20;
      uVar7 = FUN_1401346a0(CONCAT44(fVar45,fVar46),0);
      local_res8 = (undefined4)uVar7;
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
      param_1[4] = local_res8;
      param_1[5] = uStackX_c;
      FUN_1400709b0(0xd,uVar21 & 0xffffffff,fVar46,fVar45,CONCAT22(uVar47,sVar20),0,
                    CONCAT44(uVar43,uVar37),CONCAT44(uVar48,param_1[0xe]),CONCAT44(uVar14,uVar35),
                    32000,0);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      *param_1 = 0;
    }
    iVar6 = 1;
    break;
  case 0x2f:
  case 0x30:
    uVar11 = param_1[1];
    uVar24 = 0x51;
    if ((uVar11 - 4 < 0x20) && ((uVar11 & 1) == 0)) {
      if (iVar17 == 0x2f) {
        in_stack_fffffffffffffe58 = (ulonglong)uVar14 << 0x20;
        uVar7 = CONCAT44(uVar48,param_1[0xe]);
        uVar37 = CONCAT22(uVar47,(short)uVar11 * 0x309 + sVar19 + 12000);
        FUN_14006c2f0(0xc,2,fVar46,fVar45,uVar37,0,DAT_14053a190,uVar7,in_stack_fffffffffffffe58);
        uVar47 = (undefined2)((uint)uVar37 >> 0x10);
        uVar48 = (undefined4)((ulonglong)uVar7 >> 0x20);
        uVar11 = (uint)*(ushort *)(param_1 + 1);
        sVar19 = *(short *)(param_1 + 9);
      }
      if (param_1[3] == 0x30) {
        FUN_14006c2f0(0xd,2,fVar46,fVar45,CONCAT22(uVar47,sVar19 + (short)uVar11 * -0x309 + -12000),
                      0,uVar3,CONCAT44(uVar48,param_1[0xe]),
                      in_stack_fffffffffffffe58 & 0xffffffff00000000);
      }
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a4);
      FUN_14018a340(DAT_140e472a4,1,1);
    }
    iVar6 = iVar22;
    if (param_1[1] == 0x24) {
LAB_14006e5a5:
      uVar37 = DAT_140e41a50;
      puVar9 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar9 = (undefined8 *)_malloc_base(0x60);
        if (puVar9 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *(undefined4 *)(puVar9 + 8) = 0x10;
        goto LAB_14006e5ed;
      }
      goto LAB_14006e686;
    }
    break;
  case 0x31:
    iVar17 = param_1[0xe];
    fVar44 = fVar44 / DAT_14053ab70;
    if (((fVar46 < fVar44 - (float)iVar17) || ((float)(iVar17 + 600) + fVar44 < fVar46)) ||
       ((fVar45 < (float)-iVar17 || (iVar6 = iVar22, (float)(iVar17 + 0x2d0) < fVar45)))) {
      sVar10 = sVar19;
      if (fVar46 < fVar44 + 0.0) {
        sVar10 = -0x8000 - sVar19;
      }
      if (0.0 <= fVar45) {
        sVar20 = -0x8000 - sVar19;
        if (fVar46 <= fVar44 + DAT_14053aec0) {
          sVar20 = sVar10;
        }
      }
      else {
        sVar20 = -sVar19;
      }
      if (DAT_14053af14 < fVar45) {
        sVar20 = -sVar19;
      }
      *(short *)(param_1 + 9) = sVar20;
      uVar7 = FUN_1401346a0(*(undefined8 *)(param_1 + 4),0);
      local_res8 = (undefined4)uVar7;
      uStackX_c = (undefined4)((ulonglong)uVar7 >> 0x20);
      param_1[4] = local_res8;
      param_1[5] = uStackX_c;
      FUN_14006c2f0(10);
      *param_1 = 0;
      iVar6 = iVar22;
    }
    break;
  case 0x32:
    iVar17 = param_1[1];
    uVar24 = 0x51;
    if ((-1 < iVar17) && (iVar17 == (iVar17 / 9) * 9)) {
      if (param_1[2] == 2) {
        uVar37 = param_1[0xe];
        iVar17 = iVar18;
        do {
          in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
          FUN_14006c2f0(8,4,fVar46,fVar45,(short)iVar17 * 0x22b8 + sVar19 + -0x115c,0,uVar2,uVar37,
                        in_stack_fffffffffffffe58);
          iVar17 = iVar17 + 1;
        } while (iVar17 < 2);
        sVar19 = *(short *)(param_1 + 9);
      }
      if (param_1[2] == 3) {
        uVar37 = param_1[0xe];
        do {
          in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
          FUN_14006c2f0(9,4,fVar46,fVar45,(short)iVar18 * 0x22b8 + sVar19 + -0x115c,0,uVar2,uVar37,
                        in_stack_fffffffffffffe58);
          iVar18 = iVar18 + 1;
        } while (iVar18 < 2);
      }
      goto LAB_14006e2cc;
    }
LAB_14006e2f6:
    iVar6 = 1;
    break;
  case 0x33:
    iVar17 = param_1[0xe];
    if ((((fVar46 < fVar44 / DAT_14053ab70 - (float)iVar17) ||
         ((float)(iVar17 + 600) + fVar44 / DAT_14053ab70 < fVar46)) || (fVar45 < (float)-iVar17)) ||
       (iVar6 = iVar22, (float)(iVar17 + 0x2d0) < fVar45)) {
      FUN_14006c2f0(param_1[2],1,fVar46,fVar45,CONCAT22(uVar47,uVar15),0,DAT_14053a070,
                    CONCAT44(uVar48,iVar17),(ulonglong)uVar14 << 0x20);
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
      FUN_14018a340(DAT_140e472a8,1,1);
      *param_1 = 0;
      iVar6 = iVar22;
    }
    break;
  case 0x34:
    iVar6 = iVar22;
    if (param_1[1] == 0x14) {
      FUN_14006c2f0(5,1,fVar46,fVar45,CONCAT22(uVar47,uVar15),0,DAT_14053a018,
                    CONCAT44(uVar48,param_1[0xe]),(ulonglong)uVar14 << 0x20);
    }
    break;
  case 0x37:
  case 0x38:
    iVar6 = iVar22;
    if ((int)param_1[1] < 0x33) {
      if (0.0 < dVar29) {
        *(double *)(param_1 + 10) = dVar29 - *(double *)(param_1 + 0xc) / DAT_14053a380;
      }
      uVar7 = DAT_14053a0a0;
      if (param_1[1] == 0x32) {
        if ((0 < DAT_140e44e6c) && (lVar8 = DAT_140e45d80, DAT_140e45d80 != 0)) {
          do {
            if (*(int *)(lVar8 + 4) == param_1[0x11]) {
              uStack_150 = *(undefined8 *)(lVar8 + 8);
            }
            lVar8 = *(longlong *)(lVar8 + 0x60);
          } while (lVar8 != 0);
          sVar19 = *(short *)(param_1 + 9);
        }
        sVar10 = (short)((ulonglong)uStack_150 >> 0x20);
        if (param_1[3] == 0x37) {
          uVar37 = param_1[0xe];
          iVar17 = iVar18;
          do {
            in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
            FUN_14006c2f0(8,2,fVar46,fVar45,(short)iVar17 * 0x5555 + sVar10 * 0x14d + sVar19,0,uVar7
                          ,uVar37,in_stack_fffffffffffffe58);
            iVar17 = iVar17 + 1;
          } while (iVar17 < 3);
          sVar19 = *(short *)(param_1 + 9);
        }
        uVar24 = 0x50;
        if (param_1[3] == 0x38) {
          uVar37 = param_1[0xe];
          do {
            in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
            FUN_14006c2f0(8,2,fVar46,fVar45,(short)iVar18 * 0x5555 + sVar19 + sVar10 * -0x14d,0,
                          uVar7,uVar37,in_stack_fffffffffffffe58);
            iVar18 = iVar18 + 1;
          } while (iVar18 < 3);
        }
        goto LAB_14006e5a5;
      }
    }
    break;
  case 0x39:
    if ((int)param_1[1] < 0x1e) {
      *(double *)(param_1 + 10) = dVar29 - *(double *)(param_1 + 0xc) / DAT_14053a2d8;
      iVar6 = iVar22;
    }
    else {
      uVar37 = param_1[0xe];
      do {
        in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
        FUN_14006c2f0(2,2,fVar46,fVar45,(short)iVar18 * 30000 + sVar19 + -15000,0,uVar7,uVar37,
                      in_stack_fffffffffffffe58);
        iVar18 = iVar18 + 1;
      } while (iVar18 < 2);
      *param_1 = 0;
      iVar6 = iVar22;
    }
    break;
  case 0x3c:
    iVar17 = param_1[1];
    uVar11 = iVar17 * 0xeac + DAT_140e418c8;
    uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    uVar12 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
    uVar11 = uVar11 * 0x800 ^ uVar11;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    dVar28 = (double)(((uVar12 >> 0xb ^ uVar11) >> 8 ^ uVar12 ^ uVar11) % 0xb);
    dVar30 = (double)FUN_1403307c0();
    dVar31 = (double)FUN_140332d90();
    uVar11 = iVar17 * 0x22b8 + iVar16;
    uVar11 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 1;
    uVar12 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 3;
    uVar11 = uVar11 * 0x800 ^ uVar11;
    uVar13 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    uVar12 = iVar17 * 0x378 + iVar16;
    uVar12 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar12 = uVar12 * 0x800 ^ uVar12;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar12) >> 8 ^ uVar12 ^ DAT_140e9fd18;
    dVar26 = (double)(((uVar13 >> 0xb ^ uVar11) >> 8 ^ uVar13 ^ uVar11) % 0x11);
    dVar27 = (double)FUN_1403307c0();
    dVar32 = (double)FUN_140332d90();
    dVar33 = (double)FUN_140134db0(iVar17 * 0x15b38 + iVar16,DAT_140539f00,DAT_140539f40);
    puVar9 = (undefined8 *)
             FUN_140134fa0(local_f0,((int)(((longlong)iVar17 / 3 + ((longlong)iVar17 >> 0x3f) &
                                           0xffffffffU) >> 0x1f) + iVar17 / 3 + (iVar17 >> 0x1f)) %
                                    7 + 1);
    uVar7 = *puVar9;
    uVar37 = *(undefined4 *)(puVar9 + 1);
    uVar24 = 0x51;
    *(double *)(param_1 + 10) = dVar29 + DAT_140539e98;
    uVar15 = 0;
    FUN_14006c2f0(4,0x11,(float)(dVar30 * dVar28) + fVar46,(float)(dVar31 * dVar28) + fVar45,
                  CONCAT22(uVar47,sVar19),0,0,CONCAT44(uVar48,1),(ulonglong)uVar14 << 0x20);
    uVar14 = param_1[1] * 0x58 + DAT_140e418c8;
    uVar11 = (uVar14 >> 0x1e ^ uVar14) * 0x6c078965 + 1;
    uVar14 = uVar11 * 0x800 ^ uVar11;
    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar14) >> 8 ^ uVar14 ^ DAT_140e9fd18;
    uStack_164 = (undefined4)((ulonglong)uVar7 >> 0x20);
    local_168 = (undefined4)uVar7;
    FUN_140070d00(4,DAT_140e41974,0x22,(float)(dVar27 * dVar26) + fVar46,
                  (float)(dVar32 * dVar26) + fVar45,
                  CONCAT22(uVar15,(short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001)),0,
                  (double)(float)dVar33,(double)(float)dVar33,0x10,local_168,uStack_164,uVar37,0xc0,
                  0);
    iVar6 = 1;
    break;
  default:
    goto switchD_14006cfc3_default;
  }
  iVar23 = iVar6;
switchD_14006cfc3_default:
  FUN_140070250(param_1[2],uVar24,param_1[1],fVar46,fVar45,*(undefined2 *)(param_1 + 9),iVar23);
  if ((((fVar46 < DAT_140e445d8 / fVar1 - DAT_14053ac80) ||
       (DAT_140e445d8 / fVar1 + DAT_14053aed4 < fVar46)) || (fVar45 < DAT_14053b33c)) ||
     (DAT_14053af28 < fVar45)) {
    *param_1 = 0;
  }
  return;
}


