// Function: FUN_140088110 @ 140088110
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140088110(undefined4 *param_1)

{
  double dVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float in_stack_ffffffffffffff28;
  uint in_stack_ffffffffffffff30;
  undefined4 uVar18;
  undefined2 uVar19;
  double in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff40;
  ulonglong in_stack_ffffffffffffff48;
  undefined8 uVar20;
  
  uVar18 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  iVar6 = param_1[3];
  dVar11 = (double)FUN_140332d90(((double)iVar6 - 0.0) * _DAT_14053a7f0 * DAT_14053a020 *
                                 DAT_140539d28);
  uVar2 = _UNK_14053bb28;
  dVar1 = _DAT_14053bb20;
  dVar11 = dVar11 * _DAT_14053b050 + _DAT_14053bb20;
  dVar12 = (double)FUN_140332d90();
  fVar16 = DAT_14053ad40;
  iVar3 = param_1[5];
  fVar15 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar15;
  fVar17 = (float)(dVar12 + dVar12) + 0.0;
  if (iVar3 == 0) {
    if ((iVar6 == 0) && (DAT_1407c7798 == 2)) {
      DAT_1407c77a0 = DAT_1407c779c;
      uVar20 = CONCAT44((int)(in_stack_ffffffffffffff48 >> 0x20),1);
      uVar14 = CONCAT44(uVar18,0x32);
      uVar18 = CONCAT22((short)(in_stack_ffffffffffffff30 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x21,0xc80,0x20,DAT_14053ae50,fVar15 + DAT_14053ae1c,uVar18,0,uVar14,uVar20,
                 param_1[1]);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),1);
      uVar14 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),0x32);
      uVar18 = CONCAT22((short)((uint)uVar18 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x21,0xc80,0x20,DAT_14053addc,(float)param_1[0xb] + DAT_14053adf4,uVar18,0,uVar14,
                 uVar20,param_1[1]);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),1);
      uVar14 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),0x32);
      uVar18 = CONCAT22((short)((uint)uVar18 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x21,0xc80,0x20,DAT_14053aeb0,(float)param_1[0xb] + DAT_14053adbc,uVar18,0,uVar14,
                 uVar20,param_1[1]);
      uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),1);
      uVar14 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),0x32);
      uVar18 = CONCAT22((short)((uint)uVar18 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x21,0xc80,0x20,DAT_14053ad48,(float)param_1[0xb] + fVar16,uVar18,0,uVar14,uVar20,
                 param_1[1]);
      in_stack_ffffffffffffff28 = (float)param_1[0xb] + DAT_14053accc;
      in_stack_ffffffffffffff48 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),1);
      uVar14 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),0x32);
      in_stack_ffffffffffffff38 = 0.0;
      in_stack_ffffffffffffff30 = CONCAT22((short)((uint)uVar18 >> 0x10),0x4000);
      stage_entity_spawn_candidate
                (0x21,0xc80,0x20,DAT_14053aecc,in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,0
                 ,uVar14,in_stack_ffffffffffffff48,param_1[1]);
      uVar18 = (undefined4)((ulonglong)uVar14 >> 0x20);
      iVar3 = param_1[5];
      param_1[0x17] = 5;
    }
    fVar15 = (float)param_1[0xb];
    if (DAT_14053b3ac <= fVar15) {
      iVar3 = iVar3 + 1;
      param_1[3] = 0;
      param_1[5] = iVar3;
      param_1[0x15] = 0;
    }
  }
  if (iVar3 != 1) goto LAB_1400888b7;
  fVar16 = fVar15 + DAT_14053ad04 + fVar17;
  dVar12 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar16),
                                 (double)(DAT_140e445d8 - (float)param_1[10]));
  if (fVar15 < DAT_14053ae2c) {
    iVar3 = 1;
    if (DAT_140e419b8 == 0) {
      iVar3 = 0x2d;
    }
    else if (DAT_140e419b8 == 1) {
      iVar3 = 0x1e;
    }
    else if (DAT_140e419b8 == 2) {
      iVar3 = 0x14;
    }
    else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
      iVar3 = 0xf;
    }
    uVar8 = 1;
    if (DAT_140e419b8 == 0) {
      uVar8 = 7;
    }
    else if (DAT_140e419b8 == 1) {
      uVar8 = 0xb;
    }
    else if (DAT_140e419b8 == 2) {
      uVar8 = 0xf;
    }
    else if (DAT_140e419b8 == 3) {
      uVar8 = 0x13;
    }
    else if (DAT_140e419b8 == 4) {
      uVar8 = 0x15;
    }
    dVar13 = DAT_14053a0b0;
    if ((((DAT_140e419b8 != 0) && (dVar13 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
        (dVar13 = DAT_14053a138, DAT_140e419b8 != 2)) &&
       ((dVar13 = DAT_14053a158, DAT_140e419b8 != 3 && (dVar13 = dVar1, DAT_140e419b8 == 4)))) {
      dVar13 = DAT_14053a1c8;
    }
    if (7 < DAT_1407c7798) {
      iVar3 = 1;
      if (DAT_140e419b8 == 0) {
        iVar3 = 0x1e;
      }
      else if (DAT_140e419b8 == 1) {
        iVar3 = 0x14;
      }
      else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
        iVar3 = 0xf;
      }
      uVar8 = 1;
      if (DAT_140e419b8 == 0) {
        uVar8 = 9;
      }
      else if (DAT_140e419b8 == 1) {
        uVar8 = 0xd;
      }
      else if (DAT_140e419b8 == 2) {
        uVar8 = 0x11;
      }
      else if (DAT_140e419b8 == 3) {
        uVar8 = 0x13;
      }
      else if (DAT_140e419b8 == 4) {
        uVar8 = 0x15;
      }
      dVar13 = DAT_14053a0f8;
      if ((((DAT_140e419b8 != 0) && (dVar13 = DAT_14053a138, DAT_140e419b8 != 1)) &&
          (dVar13 = DAT_14053a158, DAT_140e419b8 != 2)) &&
         ((DAT_140e419b8 != 3 && (dVar13 = dVar1, DAT_140e419b8 == 4)))) {
        dVar13 = DAT_14053a1c8;
      }
    }
    uVar7 = param_1[3];
    sVar5 = (short)(int)(dVar12 * DAT_14053aba0);
    if (((int)uVar7 < 0x32) || ((int)(uVar7 - 0x32) % iVar3 != 0)) {
      if ((int)uVar7 < 0x32) goto LAB_14008872e;
    }
    else {
      *(short *)((longlong)param_1 + 0x42) = sVar5;
    }
    iVar6 = (int)(uVar7 - 0x32) % 0x78;
    if ((iVar6 < 0x3c) && (iVar6 % iVar3 == 0)) {
      in_stack_ffffffffffffff48 = CONCAT44((int)(in_stack_ffffffffffffff48 >> 0x20),uVar8);
      uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar7 = uVar7 * 0x800 ^ uVar7;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
      in_stack_ffffffffffffff28 =
           (float)CONCAT22((short)((uint)in_stack_ffffffffffffff28 >> 0x10),
                           (short)DAT_140e9fd1c + (short)((ulonglong)DAT_140e9fd1c / 0xbb9) * -0xbb9
                           + sVar5 + -0x5dc);
      in_stack_ffffffffffffff30 = DAT_14053ac2c;
      FUN_1400709b0(3,7,param_1[10],fVar16,in_stack_ffffffffffffff28,DAT_14053ac2c,dVar13,
                    CONCAT44(uVar18,1),in_stack_ffffffffffffff48,0x8000,0);
      in_stack_ffffffffffffff38 = dVar13;
    }
  }
LAB_14008872e:
  fVar16 = DAT_14053ad40;
  if ((int)param_1[7] < 1) {
    if ((((param_1[0x17] == 0) && (DAT_1407c7798 == 2)) && (DAT_140e41b00 == 0)) &&
       ((DAT_140e467e8 == 0 && (DAT_140e44038 == 0)))) {
      DAT_140e44038 = 1;
      FUN_1400b4350(1,0x15);
      save_init_or_reset_candidate();
      DAT_140e45f68 = 0x3c;
    }
    FUN_14007b010(param_1,0x708,0x1e);
    in_stack_ffffffffffffff30 = 0;
    FUN_140109660(0x19,param_1[10],param_1[0xb],0,(uint)in_stack_ffffffffffffff28 & 0xffff0000,0,
                  (ulonglong)in_stack_ffffffffffffff38 & 0xffffffff00000000);
    uVar18 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar4 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar4 = (undefined8 *)_malloc_base(0x60);
      if (puVar4 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar10 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar4 = 1;
      *(undefined4 *)(puVar4 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar4 + 0xc) = uVar18;
      puVar4[2] = 0x6f;
      puVar4[3] = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
      puVar4[5] = 0;
      puVar4[6] = 0x3ff0000000000000;
      puVar4[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar4 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
      *(undefined4 *)(puVar4 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
      puVar4[10] = 0xff;
      puVar4[0xb] = 0;
      if (bVar10) {
        DAT_140e45d78 = puVar4;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar4;
      }
    }
    DAT_140e45d28 = puVar4;
    param_1[5] = param_1[5] + 1;
    param_1[0x15] = 1;
    param_1[3] = 0;
    fVar16 = DAT_14053ad40;
  }
LAB_1400888b7:
  if (param_1[5] == 2) {
    iVar3 = param_1[3];
    dVar11 = (double)FUN_140332d90(((double)iVar3 - 0.0) * _DAT_14053aaa0 * DAT_14053a020 *
                                   DAT_140539d28);
    dVar11 = dVar11 * DAT_140539e60 + dVar1;
    if (iVar3 < 0x3d) {
      FUN_14007ac00(param_1);
    }
    uVar19 = (undefined2)(in_stack_ffffffffffffff30 >> 0x10);
    if (param_1[3] == 0x3c) {
      uVar9 = param_1[1] + DAT_140e418c8;
      uVar7 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar7 = uVar7 * 0x800 ^ uVar7;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar7 = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
      DAT_140e9fd1c = uVar7;
      in_stack_ffffffffffffff48 = FUN_140134db0(uVar9,DAT_140539f38,dVar1);
      uVar14 = FUN_140134db0(param_1[1] + DAT_140e418c8);
      in_stack_ffffffffffffff30 = CONCAT22(uVar19,(short)uVar7 - (short)(uVar7 / 0x10001));
      FUN_140070d00(0x37,DAT_140e45090,0x15,param_1[10],(float)param_1[0xb] + DAT_14053accc,
                    in_stack_ffffffffffffff30,dVar1,uVar14,in_stack_ffffffffffffff48,0x78,0xff,0xff,
                    0xff,0x80,0);
      FUN_140079e20(param_1,2);
      *param_1 = 0;
      DAT_140e418cc = 0;
    }
  }
  in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
  FUN_1400c8410(DAT_140e44924,0x18,0x17,param_1[10],(float)param_1[0xb] - DAT_14053ad48,
                in_stack_ffffffffffffff30,dVar11,DAT_140539f10,
                in_stack_ffffffffffffff48 & 0xffffffff00000000,0,0,0x40,1,0);
  in_stack_ffffffffffffff30 = in_stack_ffffffffffffff30 & 0xffff0000;
  FUN_1400c8410(DAT_140e44924,0x1a,7,param_1[10],(float)param_1[0xb] - fVar16,
                in_stack_ffffffffffffff30,dVar11,dVar1,0xff,0xff,0xff,0xff,1,0);
  FUN_1400c8410(DAT_140e44b84,0x1a,7,param_1[10],(float)param_1[0xb] + DAT_14053acbc + fVar17,
                in_stack_ffffffffffffff30 & 0xffff0000,dVar1,uVar2,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,0);
  }
  if (DAT_14053afcc <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


