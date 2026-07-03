// Function: FUN_140037b30 @ 140037b30
// Decompile completed: true

void FUN_140037b30(undefined4 *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  double dVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  undefined4 uVar12;
  float fVar13;
  float local_res8;
  float fStackX_c;
  undefined4 in_stack_fffffffffffffeb8;
  undefined2 uVar14;
  int iStack_d0;
  int iStack_cc;
  
  dVar5 = DAT_140539f40;
  uVar14 = (undefined2)((uint)in_stack_fffffffffffffeb8 >> 0x10);
  iStack_cc = 0;
  iVar2 = 0;
  lVar4 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; iStack_cc = iVar2, lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x60)) {
      if (*(int *)(lVar4 + 4) == param_1[2]) {
        iStack_d0 = *(int *)(lVar4 + 0x18);
        iStack_cc = *(int *)(lVar4 + 0x1c);
      }
      iVar2 = iStack_cc;
    }
  }
  dVar8 = DAT_140539f40;
  if (param_1[5] == 0) {
    iVar2 = param_1[6];
    if (iVar2 - 0x93U < 2) {
      iVar3 = param_1[3];
      if (iVar3 < 0) {
        dVar8 = 0.0;
      }
      else if (iVar3 < 10) {
        dVar8 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a9d8 * DAT_14053a020 *
                                      DAT_140539d28);
        dVar8 = dVar8 + 0.0;
      }
    }
    dVar10 = *(double *)(param_1 + 0x12);
    dVar9 = (double)FUN_1403307c0();
    fVar13 = (float)(dVar9 * dVar10) + (float)param_1[10];
    param_1[10] = fVar13;
    dVar9 = (double)FUN_140332d90();
    *(double *)(param_1 + 0x12) = dVar10 + DAT_140539e60;
    fVar11 = (float)(dVar9 * dVar10) + (float)param_1[0xb];
    param_1[0xb] = fVar11;
    if ((iVar2 == 0x94) &&
       ((((fVar13 < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ac80 ||
          (DAT_140e445d8 / DAT_14053ab70 + DAT_14053aed4 < fVar13)) || (fVar11 < DAT_14053b33c)) ||
        (DAT_14053af28 < fVar11)))) {
      uVar6 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffe2);
      fStackX_c = (float)((ulonglong)uVar6 >> 0x20);
      local_res8 = (float)uVar6;
      param_1[0xb] = fStackX_c;
      param_1[10] = local_res8;
      dVar10 = (double)FUN_1403300b4((double)(DAT_140e445dc - fStackX_c),
                                     SUB84((double)(DAT_140e445d8 - local_res8),0));
      iVar2 = DAT_140e419b8;
      uVar7 = (undefined2)(int)(dVar10 * DAT_14053aba0);
      *(undefined2 *)(param_1 + 0x10) = uVar7;
      dVar10 = DAT_140539fc8;
      if (((iVar2 != 0) && (dVar10 = DAT_14053a018, iVar2 != 1)) &&
         ((dVar10 = DAT_14053a070, iVar2 != 2 && ((iVar2 != 3 && (dVar10 = dVar5, iVar2 == 4)))))) {
        dVar10 = DAT_14053a0b0;
      }
      FUN_14006c2f0(0x14,0x25,local_res8,fStackX_c,CONCAT22(uVar14,uVar7),0,dVar10,1,0);
      *param_1 = 0;
    }
  }
  uVar12 = SUB84(dVar8,0);
  pfVar1 = (float *)(param_1 + 10);
  if (param_1[6] == 0x94) {
    if (iStack_d0 == 0x83) {
      FUN_1400c8410(DAT_140e44834,0x22,7,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * -0x457,dVar8
                    ,uVar12,0xff,0xff,0xff,0xdc,1,0);
    }
    if (iStack_d0 == 0x84) {
      FUN_1400c8410(DAT_140e44838,0x22,7,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * 0x457,dVar8,
                    uVar12,0xff,0xff,0xff,0xdc,1,1);
    }
  }
  else {
    if (iStack_d0 == 0x83) {
      FUN_1400c8410(DAT_140e44834,0x23,7,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * -0x457,dVar8
                    ,uVar12,0xff,0xff,0xff,0xff,1,0);
      FUN_140070d00(5,DAT_140e44834,0x22,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * -0x457,0,
                    uVar12,uVar12,0x10,0xff,0xff,0xff,0x60,0);
    }
    if (iStack_d0 == 0x84) {
      FUN_1400c8410(DAT_140e44838,0x23,7,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * 0x457,dVar8,
                    uVar12,0xff,0xff,0xff,0xff,1,1);
      FUN_140070d00(7,DAT_140e44838,0x22,*pfVar1,param_1[0xb],*(short *)(param_1 + 3) * 0x457,0,
                    uVar12,uVar12,0x10,0xff,0xff,0xff,0x60,0);
    }
  }
  if ((iStack_cc < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if ((((*pfVar1 < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < *pfVar1)) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


