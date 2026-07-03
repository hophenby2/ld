// Function: FUN_14006ecf0 @ 14006ecf0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14006ecf0(undefined4 *param_1)

{
  double *pdVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  ushort uVar15;
  short sVar16;
  uint uVar17;
  int iVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  float local_res8;
  float fStackX_c;
  undefined4 in_stack_ffffffffffffff08;
  undefined2 uVar28;
  uint in_stack_ffffffffffffff10;
  undefined2 uVar29;
  double in_stack_ffffffffffffff18;
  undefined8 in_stack_ffffffffffffff20;
  undefined4 uVar30;
  
  uVar28 = (undefined2)((uint)in_stack_ffffffffffffff08 >> 0x10);
  uVar30 = (undefined4)((ulonglong)in_stack_ffffffffffffff20 >> 0x20);
  dVar19 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[5]),
                                 (double)(DAT_140e445d8 - (float)param_1[4]));
  dVar7 = DAT_14053a020;
  dVar21 = DAT_140539d28;
  pdVar1 = (double *)(param_1 + 10);
  uVar6 = *(ushort *)(param_1 + 9);
  dVar22 = *pdVar1;
  uVar26 = SUB84(dVar22,0);
  uVar27 = (undefined4)((ulonglong)dVar22 >> 0x20);
  uVar17 = (uint)(dVar19 * DAT_14053aba0);
  dVar24 = (double)uVar6 * DAT_14053a020 * DAT_140539d28;
  dVar19 = (double)FUN_1403307c0(dVar24);
  local_res8 = (float)(dVar19 * dVar22) + (float)param_1[4];
  param_1[4] = local_res8;
  dVar19 = (double)FUN_140332d90(dVar24);
  fVar8 = DAT_14053ab70;
  uVar29 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
  iVar12 = param_1[3];
  fVar23 = (float)(dVar19 * dVar22) + (float)param_1[5];
  param_1[5] = fVar23;
  fVar9 = DAT_14053b33c;
  fVar2 = DAT_14053af28;
  fVar4 = DAT_14053aed4;
  fVar3 = DAT_14053ac80;
  dVar19 = DAT_14053a798;
  if (0x2a < iVar12 - 0xcU) goto LAB_14006f970;
  uVar14 = (ushort)uVar17;
  switch(iVar12) {
  case 0xc:
    iVar12 = 1;
    if (DAT_140e419b8 == 0) {
      iVar12 = 0x78;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0xa0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar12 = 200;
    }
    else if (DAT_140e419b8 == 3) {
      iVar12 = 0xfa;
    }
    else if (DAT_140e419b8 == 4) {
      iVar12 = 300;
    }
    iVar13 = param_1[1];
    uVar15 = uVar14;
    if (iVar13 < 0x3c) {
      if (iVar13 == 0) {
        uVar26 = (undefined4)DAT_14053a178;
        uVar27 = (undefined4)((ulonglong)DAT_14053a178 >> 0x20);
        *pdVar1 = 8.0;
      }
      if (_DAT_140539f88 <= (double)CONCAT44(uVar27,uVar26) &&
          (double)CONCAT44(uVar27,uVar26) != _DAT_140539f88) {
        *pdVar1 = (double)CONCAT44(uVar27,uVar26) - _DAT_140539e68;
      }
      iVar13 = (uVar17 & 0xffff) - (uint)uVar6;
      iVar12 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar12 = iVar13;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar15 = uVar6;
        if ((iVar13 < 0) && (uVar15 = uVar14, iVar13 < -0x299)) {
          uVar15 = uVar6 - 0x29a;
        }
      }
      else if (0x299 < iVar13) {
        uVar15 = uVar6 + 0x29a;
      }
    }
    else {
      if (iVar13 == 0x3c) {
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472d4);
        FUN_14018a340(DAT_140e472d4,1,1);
        uVar26 = (undefined4)*(undefined8 *)(param_1 + 0xc);
        uVar27 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0xc) >> 0x20);
      }
      uVar6 = *(ushort *)(param_1 + 9);
      iVar18 = (uVar17 & 0xffff) - (uint)uVar6;
      *pdVar1 = (double)CONCAT44(uVar27,uVar26) + DAT_140539e60;
      iVar13 = iVar18 + 0x10000;
      if (-0x8001 < iVar18) {
        iVar13 = iVar18;
      }
      iVar18 = iVar13 + -0x10000;
      if (iVar13 < 0x8001) {
        iVar18 = iVar13;
      }
      if (iVar18 < 1) {
        uVar15 = uVar6;
        if ((iVar18 < 0) && (uVar15 = uVar6 - (short)iVar12, -iVar12 < iVar18)) {
          uVar15 = uVar14;
        }
      }
      else if (iVar12 <= iVar18) {
        uVar15 = uVar6 + (short)iVar12;
      }
    }
    *(ushort *)(param_1 + 9) = uVar15;
    fVar3 = (float)param_1[4];
    fVar4 = (float)param_1[5];
    if ((((DAT_140e445d8 / fVar8 - DAT_14053ac80 <= fVar3) &&
         (fVar3 <= DAT_140e445d8 / fVar8 + DAT_14053aed4)) && (DAT_14053b33c <= fVar4)) &&
       (fVar4 <= DAT_14053af28)) {
      in_stack_ffffffffffffff18 = 0.0;
      uVar29 = 0;
      FUN_14006c2f0(4,0xf,fVar3,fVar4,CONCAT22(uVar28,uVar15),0,0,CONCAT44(uVar30,param_1[0xe]),0);
    }
    break;
  case 0xe:
    if (DAT_140e419b8 == 0) {
      iVar12 = 200;
    }
    else if (DAT_140e419b8 == 1) {
      iVar12 = 0xf0;
    }
    else if (DAT_140e419b8 == 2) {
      iVar12 = 0x10e;
    }
    else if ((DAT_140e419b8 == 3) || (iVar12 = 1, DAT_140e419b8 == 4)) {
      iVar12 = 300;
    }
    iVar13 = param_1[1];
    uVar15 = uVar6;
    if (iVar13 < 0xf0) {
      dVar22 = *(double *)(param_1 + 0xc);
      iVar18 = iVar12 + 500;
      dVar24 = (dVar22 - DAT_14053a018) * DAT_140539f00;
      dVar25 = (double)iVar13 - DAT_14053b128;
      if (0x1d < iVar13) {
        dVar20 = (double)FUN_140332d90(dVar25 * DAT_14053a798 * dVar7 * dVar21);
        iVar18 = (iVar12 - (int)(dVar20 * DAT_14053a650)) + 300;
      }
      dVar21 = (double)FUN_140332d90(dVar25 * dVar19 * dVar7 * dVar21);
      iVar13 = (uVar17 & 0xffff) - (uint)uVar6;
      iVar12 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar12 = iVar13;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      *pdVar1 = dVar21 * dVar24 + (dVar22 - dVar24);
      if (iVar13 < 1) {
        if ((iVar13 < 0) && (uVar15 = uVar6 - (short)iVar18, -iVar18 < iVar13)) {
          uVar15 = uVar14;
        }
      }
      else {
        uVar15 = uVar14;
        if (iVar18 <= iVar13) {
          uVar15 = uVar6 + (short)iVar18;
        }
      }
    }
    else {
      iVar13 = (uVar17 & 0xffff) - (uint)uVar6;
      *pdVar1 = dVar22 + DAT_140539e60;
      iVar12 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar12 = iVar13;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        if ((iVar13 < 0) && (uVar15 = uVar14, iVar13 < -199)) {
          uVar15 = uVar6 - 200;
        }
      }
      else {
        uVar15 = uVar14;
        if (199 < iVar13) {
          uVar15 = uVar6 + 200;
        }
      }
    }
    fVar4 = DAT_14053ac80;
    fVar3 = (float)param_1[5];
    *(ushort *)(param_1 + 9) = uVar15;
    if ((((DAT_140e445d8 / fVar8 - fVar4 <= local_res8) &&
         (local_res8 <= DAT_140e445d8 / fVar8 + DAT_14053aed4)) && (DAT_14053b33c <= fVar3)) &&
       (fVar3 <= DAT_14053af28)) {
      in_stack_ffffffffffffff18 = 0.0;
      in_stack_ffffffffffffff10 = 0;
      FUN_14006c2f0(5,0xf,local_res8,fVar3,CONCAT22(uVar28,uVar15),0,0,CONCAT44(uVar30,param_1[0xe])
                    ,0);
    }
    uVar29 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
    fVar3 = (float)param_1[4];
    if (((fVar3 < DAT_140e445d8 / fVar8 - DAT_14053ac58) ||
        (DAT_140e445d8 / fVar8 + DAT_14053aecc < fVar3)) ||
       (((float)param_1[5] < DAT_14053b330 || (_DAT_14053af24 < (float)param_1[5])))) {
      uVar10 = FUN_1401346a0(*(undefined8 *)(param_1 + 4),0x14);
      uVar11 = _UNK_14053bb28;
      in_stack_ffffffffffffff18 = _DAT_14053bb20;
      fVar2 = (float)param_1[5];
      fStackX_c = (float)((ulonglong)uVar10 >> 0x20);
      local_res8 = (float)uVar10;
      in_stack_ffffffffffffff10 = in_stack_ffffffffffffff10 & 0xffff0000;
      FUN_1400c8410(DAT_140e4196c,0x50,7,local_res8,fStackX_c - fVar4,in_stack_ffffffffffffff10,
                    _DAT_14053bb20,_UNK_14053bb28,0xff,0x60,0x60,0x80,1,0);
      uVar28 = (undefined2)(in_stack_ffffffffffffff10 >> 0x10);
      dVar22 = (double)FUN_1403300b4((double)(fVar2 - fStackX_c),(double)(fVar3 - local_res8));
      uVar26 = CONCAT22(uVar28,(short)(int)(dVar22 * DAT_14053aba0));
      FUN_1400c8410(DAT_140e41970,0x50,7,local_res8,fStackX_c,uVar26,in_stack_ffffffffffffff18,
                    uVar11,0xff,0x80,0x80,0x80,1,0);
      uVar29 = (undefined2)((uint)uVar26 >> 0x10);
    }
    break;
  case 0x23:
  case 0x24:
    iVar13 = 1;
    if (DAT_140e419b8 == 0) {
      iVar13 = 0xf;
    }
    else if (DAT_140e419b8 == 1) {
      iVar13 = 0xb;
    }
    else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
      iVar13 = 9;
    }
    else if (DAT_140e419b8 == 4) {
      iVar13 = 8;
    }
    dVar22 = DAT_14053a040;
    if ((((DAT_140e419b8 != 0) && (dVar22 = DAT_14053a088, DAT_140e419b8 != 1)) &&
        (dVar22 = DAT_14053a0d0, DAT_140e419b8 != 2)) &&
       ((dVar22 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar22 = DAT_140539f40, DAT_140e419b8 == 4))
       )) {
      dVar22 = DAT_14053a0f8;
    }
    uVar26 = 0x7448;
    if ((iVar12 == 0x24) && (uVar26 = 0x85dc, param_1[1] == 0)) {
      uVar11 = FUN_1401346a0(*(undefined8 *)(param_1 + 4),0xffffffe2);
      local_res8 = (float)uVar11;
      fStackX_c = (float)((ulonglong)uVar11 >> 0x20);
      param_1[4] = local_res8;
      param_1[5] = fStackX_c;
    }
    if ((-1 < (int)param_1[1]) && ((int)param_1[1] % iVar13 == 0)) {
      fVar3 = (float)param_1[5];
      if ((DAT_140e445d8 / fVar8 + 0.0 <= local_res8) &&
         (((local_res8 <= DAT_140e445d8 / fVar8 + DAT_14053aec0 && (0.0 <= fVar3)) &&
          (fVar3 <= DAT_14053af14)))) {
        uVar11 = CONCAT44(uVar30,1);
        uVar29 = 0;
        uVar27 = CONCAT22(uVar28,uVar6);
        in_stack_ffffffffffffff18 = dVar22;
        FUN_1400709b0(8,3,local_res8,fVar3,uVar27,0,dVar22,uVar11,2,uVar26,0);
        uVar28 = (undefined2)((uint)uVar27 >> 0x10);
        uVar30 = (undefined4)((ulonglong)uVar11 >> 0x20);
        if (2 < DAT_140e419b8) {
          in_stack_ffffffffffffff18 = dVar22 + DAT_140539f90;
          uVar11 = CONCAT44(uVar30,1);
          uVar29 = 0;
          uVar27 = CONCAT22(uVar28,*(undefined2 *)(param_1 + 9));
          FUN_1400709b0(8,3,param_1[4],param_1[5],uVar27,0,in_stack_ffffffffffffff18,uVar11,2,uVar26
                        ,0);
          uVar28 = (undefined2)((uint)uVar27 >> 0x10);
          uVar30 = (undefined4)((ulonglong)uVar11 >> 0x20);
        }
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e472a8);
        FUN_14018a340(DAT_140e472a8,1,1);
      }
    }
    fVar3 = (float)param_1[4];
    fVar4 = (float)param_1[5];
    if (((DAT_140e445d8 / fVar8 - DAT_14053ac80 <= fVar3) &&
        (fVar3 <= DAT_140e445d8 / fVar8 + DAT_14053aed4)) &&
       ((DAT_14053b33c <= fVar4 && (fVar4 <= DAT_14053af28)))) {
      in_stack_ffffffffffffff18 = 0.0;
      uVar29 = 0;
      FUN_14006c2f0(5,0xf,fVar3,fVar4,CONCAT22(uVar28,*(undefined2 *)(param_1 + 9)),0,0,
                    CONCAT44(uVar30,1),0);
    }
    goto LAB_14006f742;
  case 0x25:
    if (((DAT_140e445d8 / fVar8 - DAT_14053ac80 <= local_res8) &&
        (local_res8 <= DAT_140e445d8 / fVar8 + DAT_14053aed4)) &&
       ((DAT_14053b33c <= fVar23 && (fVar23 <= DAT_14053af28)))) {
      in_stack_ffffffffffffff18 = 0.0;
      uVar29 = 0;
      FUN_14006c2f0(4,0xf,local_res8,fVar23,CONCAT22(uVar28,uVar6),0,0,CONCAT44(uVar30,param_1[0xe])
                    ,0);
    }
    if (2 < DAT_140e419b8) {
      uVar6 = *(ushort *)(param_1 + 9);
      dVar22 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[5]),
                                     (double)(DAT_140e445d8 - (float)param_1[4]));
      uVar14 = (ushort)(int)(dVar22 * DAT_14053aba0);
      iVar13 = ((int)(dVar22 * DAT_14053aba0) & 0xffffU) - (uint)uVar6;
      iVar12 = iVar13 + 0x10000;
      if (-0x8001 < iVar13) {
        iVar12 = iVar13;
      }
      iVar13 = iVar12 + -0x10000;
      if (iVar12 < 0x8001) {
        iVar13 = iVar12;
      }
      if (iVar13 < 1) {
        uVar15 = uVar6;
        if ((iVar13 < 0) && (uVar15 = uVar6 - 0xa0, -0xa0 < iVar13)) {
          uVar15 = uVar14;
        }
      }
      else {
        uVar15 = uVar14;
        if (0x9f < iVar13) {
          uVar15 = uVar6 + 0xa0;
        }
      }
      *(ushort *)(param_1 + 9) = uVar15;
    }
LAB_14006f742:
    *pdVar1 = *pdVar1 + DAT_140539e60;
    break;
  case 0x26:
  case 0x27:
    sVar16 = 1;
    if (DAT_140e419b8 == 0) {
      sVar16 = 0x96;
    }
    else if (DAT_140e419b8 == 1) {
      sVar16 = 0xaa;
    }
    else if (DAT_140e419b8 == 2) {
      sVar16 = 0xb4;
    }
    else if (DAT_140e419b8 == 3) {
      sVar16 = 0xc3;
    }
    else if (DAT_140e419b8 == 4) {
      sVar16 = 0xd3;
    }
    if (iVar12 == 0x26) {
      if ((((DAT_140e445d8 / fVar8 - DAT_14053ac80 <= local_res8) &&
           (local_res8 <= DAT_140e445d8 / fVar8 + DAT_14053aed4)) && (DAT_14053b33c <= fVar23)) &&
         (fVar23 <= DAT_14053af28)) {
        uVar11 = CONCAT44(uVar30,param_1[0xe]);
        in_stack_ffffffffffffff18 = 0.0;
        uVar29 = 0;
        uVar26 = CONCAT22(uVar28,uVar6);
        FUN_14006c2f0(5,0xf,local_res8,fVar23,uVar26,0,0,uVar11,0);
        uVar28 = (undefined2)((uint)uVar26 >> 0x10);
        uVar30 = (undefined4)((ulonglong)uVar11 >> 0x20);
      }
      *(short *)(param_1 + 9) = *(short *)(param_1 + 9) - sVar16;
    }
    if (param_1[3] == 0x27) {
      fVar23 = (float)param_1[4];
      fVar5 = (float)param_1[5];
      if (((DAT_140e445d8 / fVar8 - fVar3 <= fVar23) && (fVar23 <= DAT_140e445d8 / fVar8 + fVar4))
         && ((fVar9 <= fVar5 && (fVar5 <= fVar2)))) {
        in_stack_ffffffffffffff18 = 0.0;
        uVar29 = 0;
        FUN_14006c2f0(4,0xf,fVar23,fVar5,CONCAT22(uVar28,*(undefined2 *)(param_1 + 9)),0,0,
                      CONCAT44(uVar30,param_1[0xe]),0);
      }
      *(short *)(param_1 + 9) = *(short *)(param_1 + 9) + sVar16;
    }
    *(double *)(param_1 + 10) = *(double *)(param_1 + 10) + _DAT_140539e28;
    break;
  case 0x2c:
  case 0x2d:
    sVar16 = 1;
    if (DAT_140e419b8 == 0) {
      sVar16 = 0x96;
    }
    else if (DAT_140e419b8 == 1) {
      sVar16 = 0xaa;
    }
    else if (DAT_140e419b8 == 2) {
LAB_14006f8dc:
      sVar16 = 0xb4;
    }
    else if (DAT_140e419b8 == 3) {
      sVar16 = 0xc3;
    }
    else if (DAT_140e419b8 == 4) goto LAB_14006f8dc;
    if (iVar12 == 0x2c) {
      dVar22 = dVar22 + _DAT_140539e28;
      *(ushort *)(param_1 + 9) = uVar6 - sVar16;
      *(double *)(param_1 + 10) = dVar22;
    }
    else {
      if (iVar12 == 0x2d) {
        *(ushort *)(param_1 + 9) = sVar16 + uVar6;
      }
      *(double *)(param_1 + 10) = dVar22 + _DAT_140539e28;
    }
    break;
  case 0x35:
  case 0x36:
    if ((int)param_1[1] < 0x5a) {
      if (iVar12 == 0x35) {
        sVar16 = uVar6 + 0x5a;
LAB_14006f94e:
        *(short *)(param_1 + 9) = sVar16;
      }
      else if (iVar12 == 0x36) {
        sVar16 = uVar6 - 0x5a;
        goto LAB_14006f94e;
      }
      *pdVar1 = dVar22 + _DAT_140539e28;
    }
  }
LAB_14006f970:
  FUN_140070250(param_1[2],0x50,param_1[1],param_1[4],param_1[5],
                CONCAT22(uVar29,*(undefined2 *)(param_1 + 9)),
                (ulonglong)in_stack_ffffffffffffff18 & 0xffffffff00000000);
  if ((((float)param_1[4] < DAT_140e445d8 / fVar8 - DAT_14053ade8) ||
      (DAT_140e445d8 / fVar8 + DAT_14053af60 < (float)param_1[4])) ||
     (((float)param_1[5] < DAT_14053b3e8 || (_DAT_14053afa8 < (float)param_1[5])))) {
    *param_1 = 0;
  }
  return;
}


