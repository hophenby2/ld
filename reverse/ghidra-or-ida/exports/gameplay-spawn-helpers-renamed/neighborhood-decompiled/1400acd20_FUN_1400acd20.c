// Function: FUN_1400acd20 @ 1400acd20
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400acd20(undefined4 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  short sVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 local_res10;
  uint uStackX_14;
  uint in_stack_fffffffffffffee8;
  undefined4 uVar20;
  undefined4 uVar21;
  uint in_stack_fffffffffffffef0;
  double in_stack_fffffffffffffef8;
  undefined8 in_stack_ffffffffffffff00;
  double dVar22;
  
  dVar13 = DAT_14053a858;
  dVar15 = DAT_14053a020;
  dVar14 = DAT_140539d28;
  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  dVar22 = (double)(int)param_1[3];
  dVar11 = (double)FUN_140332d90((dVar22 - 0.0) * DAT_14053a858 * DAT_14053a020 * DAT_140539d28);
  dVar12 = (double)FUN_140332d90();
  fVar19 = (float)(dVar12 + dVar12) + 0.0;
  dVar13 = (double)FUN_140332d90((dVar22 - DAT_14053a2f0) * dVar13 * dVar15 * dVar14);
  fVar18 = (float)(dVar13 + dVar13) + 0.0;
  dVar13 = (double)FUN_140332d90();
  dVar13 = dVar13 * _DAT_14053a9c8;
  if (param_1[5] == 0) {
    uVar2 = FUN_1401346a0(*(undefined8 *)(param_1 + 10),0xffffffce);
    in_stack_fffffffffffffef8 = DAT_14053a070 - dVar22 * DAT_140539ec8;
    local_res10 = (undefined4)uVar2;
    in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
    uStackX_14 = (uint)((ulonglong)uVar2 >> 0x20);
    dVar22 = in_stack_fffffffffffffef8;
    FUN_1400c8410(DAT_140e41a50,0x32,8,local_res10,uStackX_14,in_stack_fffffffffffffef0,
                  in_stack_fffffffffffffef8,in_stack_fffffffffffffef8,0xff,0xff,0xff,0xff,1,0);
    uVar20 = DAT_14053b320;
    uVar21 = (undefined4)((ulonglong)dVar22 >> 0x20);
    in_stack_fffffffffffffee8 = uStackX_14;
    if (param_1[3] == 0x14) {
      uVar2 = CONCAT44(uVar21,0x3c);
      uVar21 = CONCAT22((short)(in_stack_fffffffffffffef0 >> 0x10),0xe890);
      stage_entity_spawn_candidate
                (0xa5,99999999,0,DAT_14053ac58,DAT_14053b320,uVar21,0,uVar2,0,param_1[1]);
      uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),0x3c);
      uVar21 = CONCAT22((short)((uint)uVar21 >> 0x10),0x9770);
      stage_entity_spawn_candidate(0xa5,99999999,0,DAT_14053b330,uVar20,uVar21,0,uVar2,0,param_1[1])
      ;
      uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),0x3c);
      uVar21 = CONCAT22((short)((uint)uVar21 >> 0x10),0xf448);
      stage_entity_spawn_candidate(0xa6,99999999,0x1e,DAT_14053ac2c,0,uVar21,0,uVar2,0,param_1[1]);
      uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),0x3c);
      in_stack_fffffffffffffef8 = 0.0;
      in_stack_fffffffffffffef0 = CONCAT22((short)((uint)uVar21 >> 0x10),0x8bb8);
      in_stack_fffffffffffffee8 = 0;
      stage_entity_spawn_candidate
                (0xa6,99999999,0x1e,uVar20,0,in_stack_fffffffffffffef0,0,uVar2,0,param_1[1]);
      uVar21 = (undefined4)((ulonglong)uVar2 >> 0x20);
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e472d8);
      FUN_14018a340(DAT_140e472d8,1,1);
      param_1[5] = param_1[5] + 1;
      param_1[0xd] = param_1[0xb];
      param_1[0xc] = 0x43b40000;
      param_1[3] = 0;
      param_1[0x15] = 0;
    }
  }
  uVar2 = _UNK_14053bb28;
  dVar22 = _DAT_14053bb20;
  iVar7 = param_1[5];
  if ((iVar7 == 1) || (iVar7 == 2)) {
    iVar5 = 2000;
    if (DAT_1407c7798 == 9) {
      iVar5 = 0x4b0;
    }
    iVar1 = param_1[4];
    fVar16 = DAT_14053ad1c;
    if (iVar1 < 0xc6) {
      dVar12 = (double)FUN_140332d90(((double)iVar1 - 0.0) * _DAT_14053a408 * dVar15 * dVar14);
      fVar16 = (float)(dVar12 * _DAT_14053b250) + DAT_14053aee0;
    }
    if ((float)param_1[0xe] <= DAT_14053ae30 && DAT_14053ae30 != (float)param_1[0xe]) {
      fVar16 = fVar16 * DAT_14053b044;
    }
    if (iVar5 < iVar1) {
      dVar12 = *(double *)(param_1 + 0x12) + DAT_140539e60;
      *(double *)(param_1 + 0x12) = dVar12;
      param_1[0xd] = (float)param_1[0xd] - (float)dVar12;
    }
    dVar14 = (double)FUN_140332d90(((double)iVar1 - _DAT_14053b1a8) * _DAT_14053a538 * dVar15 *
                                   dVar14);
    fVar16 = (float)(dVar14 * (double)fVar16) + (float)param_1[0xc];
    param_1[10] = fVar16;
    dVar14 = (double)FUN_140332d90();
    fVar17 = (float)(dVar14 * DAT_14053a380) + (float)param_1[0xd];
    param_1[0xb] = fVar17;
    if (iVar7 == 2) {
      dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - ((fVar17 - DAT_14053aca8) + fVar18)),
                                     (double)(DAT_140e445d8 - fVar16));
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0xb4;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 0x8c;
      }
      else if (DAT_140e419b8 == 2) {
        iVar7 = 0x82;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar7 = 0x78;
      }
      iVar5 = 1;
      if (DAT_140e419b8 == 0) {
        iVar5 = 0xb;
      }
      else if (DAT_140e419b8 == 1) {
        iVar5 = 0xf;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar5 = 0x11;
      }
      else if (DAT_140e419b8 == 4) {
        iVar5 = 0x13;
      }
      dVar15 = DAT_14053a088;
      if (((DAT_140e419b8 != 0) && (dVar15 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
         ((DAT_140e419b8 == 2 ||
          ((dVar15 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar15 = dVar22, DAT_140e419b8 == 4))))))
      {
        dVar15 = DAT_14053a0f8;
      }
      if ((0x9f < (int)param_1[3]) && ((param_1[3] + -0xa0) % iVar7 == 0)) {
        uVar6 = iVar5 - 1;
        uVar4 = (int)(0x8000 / (ulonglong)uVar6) * (iVar5 + -2) & 0xffff;
        uVar8 = (undefined2)(int)(dVar14 * DAT_14053aba0);
        uVar20 = CONCAT22((short)(in_stack_fffffffffffffee8 >> 0x10),uVar8);
        FUN_1400709b0(5,0,fVar16,fVar17,uVar20,0,dVar15,CONCAT44(uVar21,1),uVar6,uVar4,0);
        in_stack_fffffffffffffef8 = dVar15 + DAT_140539f68;
        in_stack_fffffffffffffef0 = 0;
        in_stack_fffffffffffffee8 = CONCAT22((short)((uint)uVar20 >> 0x10),uVar8);
        FUN_1400709b0(3,0,param_1[10],param_1[0xb],in_stack_fffffffffffffee8,0,
                      in_stack_fffffffffffffef8,1,iVar5,0x8000,0);
        if (2 < DAT_140e419b8) {
          uVar21 = CONCAT22((short)(in_stack_fffffffffffffee8 >> 0x10),uVar8);
          FUN_1400709b0(5,0,param_1[10],param_1[0xb],uVar21,0,dVar15 + DAT_140539fe8,1,uVar6,uVar4,0
                       );
          in_stack_fffffffffffffef8 = dVar15 + DAT_14053a048;
          in_stack_fffffffffffffef0 = 0;
          in_stack_fffffffffffffee8 = CONCAT22((short)((uint)uVar21 >> 0x10),uVar8);
          FUN_1400709b0(3,0,param_1[10],param_1[0xb],in_stack_fffffffffffffee8,0,
                        in_stack_fffffffffffffef8,1,iVar5,0x8000,0);
        }
      }
    }
    iVar7 = param_1[5];
    if ((iVar7 == 1) && ((int)param_1[7] <= (int)((double)(int)param_1[8] * DAT_140539ef8))) {
      in_stack_fffffffffffffef8 =
           (double)((ulonglong)in_stack_fffffffffffffef8 & 0xffffffff00000000);
      in_stack_fffffffffffffef0 = 0;
      in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffff0000;
      FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffee8,0,
                    in_stack_fffffffffffffef8);
      FUN_140079e20(param_1,2);
      param_1[3] = 0;
      iVar7 = 2;
      param_1[5] = 2;
    }
    if (0 < (int)param_1[7]) goto LAB_1400ad5b2;
    FUN_14007b010(param_1,0x960,0x1e);
    in_stack_fffffffffffffef0 = 0;
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffee8 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffef8 & 0xffffffff00000000);
    uVar21 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar3 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar3 = (undefined8 *)_malloc_base(0x60);
      if (puVar3 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar10 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar3 = 1;
      *(undefined4 *)(puVar3 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar3 + 0xc) = uVar21;
      puVar3[2] = 0x6f;
      puVar3[3] = 0;
      *(undefined4 *)(puVar3 + 4) = 0;
      *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
      puVar3[5] = 0;
      puVar3[6] = 0x3ff0000000000000;
      puVar3[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar3 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
      *(undefined4 *)(puVar3 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
      puVar3[10] = 0xff;
      puVar3[0xb] = 0;
      if (bVar10) {
        DAT_140e45d78 = puVar3;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar3;
      }
    }
    DAT_140e45d28 = puVar3;
    param_1[0x14] = 0xb4;
    param_1[0x15] = 1;
    param_1[3] = 0;
    param_1[5] = 3;
  }
  else {
LAB_1400ad5b2:
    if (iVar7 != 3) goto LAB_1400ad5fd;
  }
  if ((int)param_1[3] < 0x3d) {
    FUN_14007ac00(param_1);
  }
  param_1[0xb] = (float)(int)param_1[3] * DAT_140539ce4 + (float)param_1[0xb];
  if (param_1[3] == 0x3c) {
    FUN_140079e20(param_1,2);
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
LAB_1400ad5fd:
  in_stack_fffffffffffffef0 = in_stack_fffffffffffffef0 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d14,0x1f,7,param_1[10],
                (float)(dVar11 + dVar11) + 0.0 + (float)param_1[0xb],in_stack_fffffffffffffef0,
                dVar22,uVar2,0xff,0xff,0xff,0xff,1,0);
  fVar16 = DAT_14053ab70;
  sVar9 = (short)(int)dVar13;
  uVar21 = CONCAT22((short)(in_stack_fffffffffffffef0 >> 0x10),sVar9);
  FUN_1400c8410(DAT_140e44d18,0x1f,7,(float)param_1[10] + DAT_14053ab70,
                fVar19 + (float)param_1[0xb] + DAT_14053ac2c,uVar21,dVar22,uVar2,0xff,0xff,0xff,0xff
                ,1,0);
  uVar4 = CONCAT22((short)((uint)uVar21 >> 0x10),-sVar9);
  FUN_1400c8410(DAT_140e44d18,0x1f,7,(float)param_1[10] - fVar16,
                fVar19 + (float)param_1[0xb] + DAT_14053ac2c,uVar4,dVar22,uVar2,0xff,0xff,0xff,0xff,
                1,1);
  uVar4 = uVar4 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d1c,0x1f,7,param_1[10],fVar19 + (float)param_1[0xb],uVar4,dVar22,uVar2,
                0xff,0xff,0xff,0xff,1,0);
  uVar4 = uVar4 & 0xffff0000;
  FUN_1400c8410(DAT_140e44d20,0x1f,7,param_1[10],fVar18 + (float)param_1[0xb],uVar4,dVar22,uVar2,
                0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44d24,0x1f,7,param_1[10],fVar18 + (float)param_1[0xb],uVar4 & 0xffff0000,
                dVar22,uVar2,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  fVar16 = DAT_140e445d8 / fVar16;
  if ((((((float)param_1[10] < fVar16 - DAT_14053ad4c) ||
        (fVar16 + _DAT_14053af18 < (float)param_1[10])) || ((float)param_1[0xb] < DAT_14053b398)) ||
      (_DAT_14053af5c < (float)param_1[0xb])) && (param_1[5] == 3)) {
    *param_1 = 0;
    DAT_140e418cc = 0;
  }
  return;
}


