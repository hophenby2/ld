// Function: FUN_14006c620 @ 14006c620
// Decompile completed: true

void FUN_14006c620(undefined4 *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  double *pdVar9;
  undefined8 uVar10;
  bool bVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 in_stack_ffffffffffffff48;
  undefined2 uVar21;
  ulonglong in_stack_ffffffffffffff58;
  
  uVar21 = (undefined2)((uint)in_stack_ffffffffffffff48 >> 0x10);
  uVar10 = 0x50;
  pdVar9 = (double *)(param_1 + 10);
  dVar14 = *pdVar9;
  uVar18 = SUB84(dVar14,0);
  uVar19 = (undefined4)((ulonglong)dVar14 >> 0x20);
  fVar16 = (float)param_1[8];
  param_1[8] = (float)dVar14 + fVar16;
  dVar13 = (double)((float)dVar14 + fVar16);
  dVar12 = (double)FUN_1403307c0();
  fVar20 = (float)(dVar12 * dVar13) + (float)param_1[4];
  dVar12 = (double)FUN_140332d90();
  uVar6 = DAT_140e41a50;
  fVar5 = DAT_14053b33c;
  fVar4 = DAT_14053af28;
  fVar3 = DAT_14053aed4;
  fVar2 = DAT_14053ac80;
  fVar16 = DAT_14053ab70;
  fVar17 = (float)(dVar12 * dVar13) + (float)param_1[5];
  puVar8 = DAT_140e45d28;
  switch(param_1[3]) {
  case 1:
    dVar13 = DAT_140539e30;
    if (DAT_140e419b8 != 0) {
      if (DAT_140e419b8 == 1) {
        *pdVar9 = dVar14 + DAT_140539e40;
        break;
      }
      if (DAT_140e419b8 == 2) {
        *pdVar9 = dVar14 + DAT_140539e50;
        break;
      }
      if ((DAT_140e419b8 == 3) || (dVar13 = DAT_140539f40, DAT_140e419b8 == 4)) {
        *pdVar9 = dVar14 + DAT_140539e60;
        break;
      }
    }
    *pdVar9 = dVar14 + dVar13;
    break;
  case 2:
    if (param_1[1] == 0) {
      uVar18 = SUB84(DAT_140539e60,0);
      uVar19 = (undefined4)((ulonglong)DAT_140539e60 >> 0x20);
    }
    else if (0x1e < (int)param_1[1]) break;
    *pdVar9 = *(double *)(param_1 + 0xc) / DAT_14053a2d8 + (double)CONCAT44(uVar19,uVar18);
    break;
  case 3:
    if (param_1[1] == 0) {
      uVar10 = 0x4f;
      *pdVar9 = 0.1;
      break;
    }
    uVar7 = param_1[1] - 0x1e;
    goto LAB_14006c7fc;
  case 4:
    if (param_1[1] == 0) {
      uVar10 = 0x4f;
      *pdVar9 = 0.1;
      break;
    }
    uVar7 = param_1[1] - 0xc;
LAB_14006c7fc:
    if (uVar7 < 0x3d) {
      *pdVar9 = *(double *)(param_1 + 0xc) / DAT_14053a3a0 + dVar14;
    }
LAB_14006c817:
    uVar10 = 0x4f;
    break;
  case 5:
    if (param_1[1] == 0) {
      uVar10 = 0x4f;
      *pdVar9 = *(double *)(param_1 + 0xc) * DAT_140539f00;
      break;
    }
    if (param_1[1] - 0x3c < 0x3d) {
      uVar10 = 0x4f;
      *pdVar9 = *(double *)(param_1 + 0xc) / DAT_14053a4a0 + dVar14;
      break;
    }
    goto LAB_14006c817;
  case 6:
    if (param_1[1] == 0) {
      *(double *)(param_1 + 0xc) = dVar14 / DAT_14053a0b0;
    }
    else if (0x1e < (int)param_1[1]) break;
    if (*(double *)(param_1 + 0xc) < dVar14) {
      *pdVar9 = dVar14 - *(double *)(param_1 + 0xc) / DAT_14053a0f8;
    }
    break;
  case 7:
    if ((int)param_1[1] < 0x28) {
      *pdVar9 = dVar14 - *(double *)(param_1 + 0xc) / DAT_14053a340;
      break;
    }
    if (99 < (int)param_1[1]) break;
    goto LAB_14006c905;
  case 9:
    if ((int)param_1[1] < 0x1e) {
      *pdVar9 = dVar14 - *(double *)(param_1 + 0xc) / DAT_14053a2d8;
    }
    else {
      if (param_1[1] == 0x1e) {
        param_1[4] = fVar20;
        param_1[5] = fVar17;
        dVar13 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar17),
                                       (double)(DAT_140e445d8 - fVar20));
        dVar13 = dVar13 * DAT_14053aba0;
        param_1[8] = 0;
        *(short *)(param_1 + 9) = (short)(int)dVar13;
      }
      pdVar9 = (double *)(param_1 + 10);
      dVar13 = DAT_140539e88;
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          *pdVar9 = dVar14 + DAT_140539e98;
          break;
        }
        if (DAT_140e419b8 == 2) {
          *pdVar9 = dVar14 + DAT_140539eb0;
          break;
        }
        if ((DAT_140e419b8 == 3) || (dVar13 = DAT_140539f40, DAT_140e419b8 == 4)) {
          *pdVar9 = dVar14 + DAT_140539ec8;
          break;
        }
      }
      *(double *)(param_1 + 10) = dVar14 + dVar13;
    }
    break;
  case 10:
    iVar1 = param_1[1];
    if (iVar1 < 0x28) {
      *pdVar9 = *(double *)(param_1 + 0xc) * DAT_140539fb8 -
                ((*(double *)(param_1 + 0xc) * DAT_140539fb8) / DAT_14053a340) * (double)iVar1;
      break;
    }
    if (iVar1 == 0x28) {
      param_1[4] = fVar20;
      param_1[5] = fVar17;
      dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[7]),
                                     (double)(DAT_140e445d8 - (float)param_1[6]));
      dVar14 = dVar14 * DAT_14053aba0;
      uVar18 = 0;
      uVar19 = 0;
      param_1[8] = 0;
      *(short *)(param_1 + 9) = (short)(int)dVar14;
    }
    else if (0x3b < iVar1 - 0x28U) break;
LAB_14006c905:
    *pdVar9 = *(double *)(param_1 + 0xc) / DAT_14053a3a0 + (double)CONCAT44(uVar19,uVar18);
    break;
  case 0xb:
    if ((int)param_1[1] < 0x32) {
      *pdVar9 = dVar14 - *(double *)(param_1 + 0xc) / DAT_14053a380;
    }
    else {
      if (param_1[1] == 0x32) {
        fVar15 = (float)param_1[7] - DAT_14053adb4;
        param_1[4] = fVar20;
        param_1[5] = fVar17;
        dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar15),
                                       (double)(DAT_140e445d8 - (float)param_1[6]));
        dVar14 = dVar14 * DAT_14053aba0;
        uVar18 = 0;
        uVar19 = 0;
        param_1[8] = 0;
        *pdVar9 = 0.0;
        *(short *)(param_1 + 9) = (short)(int)dVar14;
      }
      *pdVar9 = (double)CONCAT44(uVar19,uVar18) + DAT_140539e40;
    }
    break;
  case 0xd:
    if (0x17 < (int)param_1[1]) {
      dVar13 = DAT_140539e98;
      if ((((DAT_140e419b8 != 0) && (dVar13 = DAT_140539ea8, DAT_140e419b8 != 1)) &&
          (dVar13 = DAT_140539eb8, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 == 3 || (dVar13 = DAT_140539f40, DAT_140e419b8 == 4)))) {
        dVar13 = DAT_140539ec8;
      }
      *pdVar9 = dVar14 + dVar13;
    }
    fVar15 = DAT_140e445d8 / fVar16;
    if (((fVar15 - fVar2 <= fVar20) && (fVar20 <= fVar15 + fVar3)) &&
       ((fVar5 <= fVar17 && (fVar17 <= fVar4)))) {
      in_stack_ffffffffffffff58 = 0;
      FUN_14006c2f0(4,0xf,fVar20,fVar17,CONCAT22(uVar21,*(undefined2 *)(param_1 + 9)),0,0,
                    param_1[0xe],0);
    }
    break;
  case 0xf:
    if (param_1[1] != 0x14) break;
    goto LAB_14006cd48;
  case 0x10:
    if (param_1[1] != 0x28) break;
    goto LAB_14006cd48;
  case 0x11:
    if (param_1[1] != 10) break;
    goto LAB_14006cd48;
  case 0x12:
    if (param_1[1] != 0x3c) break;
    if (DAT_140e45d1c < 0x1000) {
      puVar8 = (undefined8 *)_malloc_base(0x60);
      if (puVar8 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar11 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar8 + 0x14) = fVar20;
      *(float *)(puVar8 + 3) = fVar17;
      *(float *)((longlong)puVar8 + 0x1c) = fVar20;
      *(float *)(puVar8 + 4) = fVar17;
      *puVar8 = 1;
      *(undefined4 *)(puVar8 + 1) = 0xc;
      *(undefined4 *)((longlong)puVar8 + 0xc) = uVar6;
      *(undefined4 *)(puVar8 + 2) = 0x3d;
      *(undefined2 *)((longlong)puVar8 + 0x24) = 0;
      puVar8[5] = 0;
      puVar8[6] = 0x3fe3333333333333;
      puVar8[7] = 0x3fe3333333333333;
      *(undefined4 *)(puVar8 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar8 + 0x44) = 0xff;
      *(undefined4 *)(puVar8 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar8 + 0x4c) = 0xff;
      puVar8[10] = 0xff;
      puVar8[0xb] = 0;
      if (bVar11) {
        DAT_140e45d78 = puVar8;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar8;
      }
    }
LAB_14006cd48:
    DAT_140e45d28 = puVar8;
    *param_1 = 0;
  }
  FUN_140070250(param_1[2],uVar10,param_1[1],fVar20,fVar17,*(undefined2 *)(param_1 + 9),
                in_stack_ffffffffffffff58 & 0xffffffff00000000);
  fVar16 = DAT_140e445d8 / fVar16;
  if ((((fVar20 < fVar16 - fVar2) || (fVar16 + fVar3 < fVar20)) || (fVar17 < fVar5)) ||
     (fVar4 < fVar17)) {
    *param_1 = 0;
  }
  return;
}


