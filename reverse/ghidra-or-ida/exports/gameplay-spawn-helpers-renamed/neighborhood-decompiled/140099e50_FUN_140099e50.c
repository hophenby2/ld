// Function: FUN_140099e50 @ 140099e50
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140099e50(undefined4 *param_1)

{
  undefined8 uVar1;
  double dVar2;
  int iVar3;
  longlong lVar4;
  undefined2 uVar5;
  short sVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  float fVar18;
  undefined2 uVar19;
  undefined4 in_stack_fffffffffffffef0;
  undefined2 uVar21;
  undefined4 uVar20;
  
  dVar2 = DAT_14053a020;
  uVar1 = DAT_140539f40;
  dVar10 = DAT_140539d28;
  uVar21 = (undefined2)((uint)in_stack_fffffffffffffef0 >> 0x10);
  uVar15 = (undefined4)DAT_140539f40;
  uVar16 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
  sVar6 = (short)DAT_140e418c8 * -0x8ae + *(short *)(param_1 + 1) * -0x4a56;
  if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
    iVar3 = 0;
    uVar14 = (undefined4)DAT_140539f28;
    uVar12 = (undefined4)((ulonglong)DAT_140539f28 >> 0x20);
  }
  else {
    iVar3 = 0;
    uVar14 = uVar15;
    uVar12 = uVar16;
    if (DAT_140e419b8 != 2) {
      iVar3 = DAT_140e419b8 + -3;
    }
  }
  dVar11 = (double)CONCAT44(uVar12,uVar14);
  dVar9 = (double)FUN_1403307c0(iVar3);
  param_1[10] = (float)(dVar9 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
  dVar9 = (double)FUN_140332d90();
  param_1[0xb] = (float)(dVar9 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb];
  if (param_1[5] == 0) {
    iVar3 = param_1[3];
    if (iVar3 < 0) {
      dVar11 = 0.0;
    }
    else if (iVar3 < 0x14) {
      dVar10 = (double)FUN_140332d90(((double)iVar3 - 0.0) * DAT_14053a890 * dVar2 * dVar10);
      dVar11 = dVar10 * ((double)CONCAT44(uVar12,uVar14) - 0.0) + 0.0;
    }
    else if (iVar3 == 0x14) {
      dVar10 = (double)CONCAT44(uVar12,uVar14) * DAT_14053a3f8;
      param_1[0x15] = 0;
      param_1[3] = 0;
      param_1[5] = 1;
      param_1[0x14] = (int)dVar10;
      goto LAB_140099fc7;
    }
  }
  else {
    dVar11 = (double)CONCAT44(uVar12,uVar14);
    if (param_1[5] == 1) {
LAB_140099fc7:
      dVar11 = (double)CONCAT44(uVar12,uVar14);
      FUN_140079c10(param_1,1);
    }
  }
  uVar12 = SUB84(dVar11,0);
  uVar20 = CONCAT22(uVar21,sVar6);
  FUN_1400c8410(DAT_140e44c20,0x4e,7,param_1[10],param_1[0xb],uVar20,dVar11,uVar12,0xff,0xff,0xff,
                0xff,1,0);
  uVar14 = param_1[0xb];
  uVar20 = CONCAT22((short)((uint)uVar20 >> 0x10),sVar6);
  FUN_140070d00(5,DAT_140e44c20,0x4d,param_1[10],uVar14,uVar20,0,uVar12,uVar12,0xc,0xff,0xff,0xff,
                0x30,0);
  fVar18 = DAT_140e445d8;
  uVar21 = (undefined2)((uint)uVar20 >> 0x10);
  if (0 < (int)param_1[7]) goto LAB_14009a3f4;
  fVar13 = (float)param_1[0xb];
  fVar7 = (float)FUN_140334430((float)param_1[10] - DAT_140e445d8);
  fVar17 = DAT_140e445dc;
  fVar8 = (float)FUN_140334430(fVar13 - DAT_140e445dc);
  if (fVar7 + fVar8 < 0.0) {
    fVar7 = (float)FUN_1403352f8();
  }
  else {
    fVar7 = SQRT(fVar7 + fVar8);
  }
  dVar2 = DAT_14053aba0;
  dVar10 = DAT_140539fc8;
  if ((((float)(param_1[0x14] + 0x1e) <= fVar7) && (fVar13 < DAT_14053ae90)) && (fVar13 < fVar17)) {
    if (DAT_140e419b8 == 0) {
      uVar15 = (undefined4)DAT_14053a088;
      uVar16 = (undefined4)((ulonglong)DAT_14053a088 >> 0x20);
    }
    else if (DAT_140e419b8 == 1) {
LAB_14009a1b5:
      uVar15 = (undefined4)DAT_14053a0d0;
      uVar16 = (undefined4)((ulonglong)DAT_14053a0d0 >> 0x20);
    }
    else if (DAT_140e419b8 == 2) {
      uVar15 = (undefined4)DAT_14053a118;
      uVar16 = (undefined4)((ulonglong)DAT_14053a118 >> 0x20);
    }
    else {
      if (DAT_140e419b8 == 3) goto LAB_14009a1b5;
      if (DAT_140e419b8 == 4) {
        uVar15 = (undefined4)DAT_14053a138;
        uVar16 = (undefined4)((ulonglong)DAT_14053a138 >> 0x20);
      }
    }
    lVar4 = 1;
    if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
      lVar4 = 0xf;
    }
    else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
      lVar4 = 0x13;
    }
    do {
      uVar19 = (undefined2)((uint)uVar14 >> 0x10);
      iVar3 = param_1[0x14];
      dVar11 = (double)FUN_1403307c0();
      fVar7 = (float)(dVar11 * (double)(iVar3 + -0xf)) + (float)param_1[10];
      dVar11 = (double)FUN_140332d90();
      fVar13 = (float)(dVar11 * (double)(iVar3 + -0xf)) + (float)param_1[0xb];
      dVar11 = (double)FUN_1403300b4((double)(fVar17 - fVar13),(double)(fVar18 - fVar7));
      uVar21 = 0;
      uVar5 = (undefined2)(int)(dVar11 * dVar2);
      uVar14 = CONCAT22(uVar19,uVar5);
      FUN_14006c2f0(0xd,2,fVar7,fVar13,uVar14,0,CONCAT44(uVar16,uVar15),1,0);
      if (2 < DAT_140e419b8) {
        uVar21 = 0;
        uVar14 = CONCAT22((short)((uint)uVar14 >> 0x10),uVar5);
        FUN_14006c2f0(0xd,2,fVar7,fVar13,uVar14,0,(double)CONCAT44(uVar16,uVar15) + dVar10,1,0);
      }
      lVar4 = lVar4 + -1;
      fVar17 = DAT_140e445dc;
      fVar18 = DAT_140e445d8;
    } while (lVar4 != 0);
  }
  param_1[0x14] = (int)((double)(int)param_1[0x14] * DAT_140539f10);
  FUN_14007b010(param_1,300,1);
  stage_entity_spawn_candidate
            (0x153,param_1[8],1,DAT_14053b380,DAT_14053b380,CONCAT22(uVar21,0x4000),uVar1,10,1,
             param_1[2]);
  FUN_140079e20(param_1,0);
  *param_1 = 0;
LAB_14009a3f4:
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad4c) ||
       (DAT_140e445d8 / DAT_14053ab70 + _DAT_14053af18 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b398)) || (_DAT_14053af5c < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


