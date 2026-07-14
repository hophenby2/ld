// Function: FUN_140087750 @ 140087750
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140087750(undefined4 *param_1)

{
  float fVar1;
  ulonglong uVar2;
  double dVar3;
  undefined8 *puVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  bool bVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  float fVar17;
  double dVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  uint in_stack_fffffffffffffed8;
  uint in_stack_fffffffffffffee0;
  undefined2 uVar25;
  double in_stack_fffffffffffffee8;
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar26;
  ulonglong in_stack_fffffffffffffef8;
  undefined8 uVar27;
  
  uVar26 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
  iVar7 = param_1[3];
  uVar12 = SUB84(DAT_14053a020,0);
  uVar16 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar20 = SUB84(DAT_140539d28,0);
  uVar21 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  dVar13 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053a988 * DAT_14053a020 *
                                 DAT_140539d28);
  dVar3 = DAT_140539f40;
  uVar22 = SUB84(DAT_140539f40,0);
  uVar2 = (ulonglong)DAT_140539f40 >> 0x20;
  dVar13 = dVar13 * _DAT_14053b050 + DAT_140539f40;
  fVar17 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar17;
  if (param_1[5] == 0) {
    if (fVar17 < DAT_14053b380) goto LAB_140087e21;
    param_1[5] = 1;
    param_1[3] = 0;
  }
  else {
    if (param_1[5] != 1) goto LAB_140087e21;
    if (iVar7 == 0x32) {
      param_1[0x15] = 0;
    }
  }
  fVar1 = (float)param_1[10];
  if ((((DAT_140e445d8 / DAT_14053ab70 - DAT_14053acbc <= fVar1) &&
       (fVar1 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aee0)) && (DAT_14053b358 <= fVar17)) &&
     (fVar17 <= _DAT_14053af34)) {
    fVar23 = fVar17 + DAT_14053ace8;
    fVar24 = fVar17 - DAT_14053acc8;
    dVar14 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar23),(double)(DAT_140e445d8 - fVar1))
    ;
    uVar5 = DAT_14053ac2c;
    if (fVar17 < DAT_14053ae2c) {
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0x32;
      }
      else if (((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) || (DAT_140e419b8 == 3)) {
        iVar7 = 0x1e;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 0x14;
      }
      uVar12 = 1;
      if (DAT_140e419b8 != 0) {
        if (DAT_140e419b8 == 1) {
          uVar12 = 3;
        }
        else if (((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) || (DAT_140e419b8 == 4)) {
          uVar12 = 5;
        }
      }
      uVar16 = SUB84(DAT_14053a070,0);
      uVar19 = (undefined4)((ulonglong)DAT_14053a070 >> 0x20);
      if ((DAT_140e419b8 == 0) || (DAT_140e419b8 == 1)) {
        uVar16 = (undefined4)DAT_14053a018;
        uVar19 = (undefined4)((ulonglong)DAT_14053a018 >> 0x20);
      }
      else if (((DAT_140e419b8 != 2) && (DAT_140e419b8 != 3)) &&
              (uVar16 = uVar22, uVar19 = (int)uVar2, DAT_140e419b8 == 4)) {
        uVar16 = SUB84(DAT_14053a0b0,0);
        uVar19 = (int)((ulonglong)DAT_14053a0b0 >> 0x20);
      }
      uVar22 = 1;
      if (DAT_140e419b8 == 0) {
        uVar22 = 6;
      }
      else if (DAT_140e419b8 == 1) {
        uVar22 = 0xc;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        uVar22 = 0xe;
      }
      else if (DAT_140e419b8 == 4) {
        uVar22 = 0x10;
      }
      iVar9 = 1;
      if (DAT_140e419b8 == 0) {
        iVar9 = 0x5a;
      }
      else if (DAT_140e419b8 == 1) {
        iVar9 = 0x48;
      }
      else if (DAT_140e419b8 == 2) {
        iVar9 = 0x3c;
      }
      else if ((DAT_140e419b8 == 3) || (DAT_140e419b8 == 4)) {
        iVar9 = 0x32;
      }
      dVar18 = DAT_14053a070;
      if ((((DAT_140e419b8 != 0) && (DAT_140e419b8 != 1)) &&
          (dVar18 = DAT_14053a088, DAT_140e419b8 != 2)) &&
         ((dVar18 = DAT_14053a0b0, DAT_140e419b8 != 3 && (dVar18 = dVar3, DAT_140e419b8 == 4)))) {
        dVar18 = DAT_14053a138;
      }
      sVar10 = 1;
      sVar6 = -1;
      if (DAT_140e419b8 == 0) {
        sVar10 = 0x12;
        sVar6 = -0x12;
      }
      else if ((DAT_140e419b8 == 1) || (DAT_140e419b8 == 2)) {
        sVar10 = 0x19;
        sVar6 = -0x19;
      }
      else if (DAT_140e419b8 == 3) {
        sVar10 = 0x24;
        sVar6 = -0x24;
      }
      else if (DAT_140e419b8 == 4) {
        sVar10 = 0x2a;
        sVar6 = -0x2a;
      }
      if (DAT_14053ae30 <= fVar1) {
        sVar6 = sVar10;
      }
      if ((0x31 < (int)param_1[3]) && ((param_1[3] + -0x32) % iVar7 == 0)) {
        in_stack_fffffffffffffef8 = CONCAT44((int)(in_stack_fffffffffffffef8 >> 0x20),uVar12);
        uVar15 = CONCAT44(uVar26,1);
        in_stack_fffffffffffffee8 = (double)CONCAT44(uVar19,uVar16);
        sVar10 = (short)(int)(dVar14 * DAT_14053aba0);
        in_stack_fffffffffffffed8 = CONCAT22((short)(in_stack_fffffffffffffed8 >> 0x10),sVar10);
        in_stack_fffffffffffffee0 = DAT_14053ac2c;
        FUN_1400709b0(3,1,fVar1,fVar23,in_stack_fffffffffffffed8,DAT_14053ac2c,
                      in_stack_fffffffffffffee8,uVar15,in_stack_fffffffffffffef8,18000,0);
        uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
        if (2 < DAT_140e419b8) {
          uVar27 = CONCAT44((int)(in_stack_fffffffffffffef8 >> 0x20),uVar12);
          uVar15 = CONCAT44(uVar26,1);
          uVar20 = CONCAT22((short)(in_stack_fffffffffffffed8 >> 0x10),sVar10 + 800);
          FUN_1400709b0(3,1,fVar1,fVar23,uVar20,uVar5,CONCAT44(uVar19,uVar16),uVar15,uVar27,18000,0)
          ;
          in_stack_fffffffffffffef8 = CONCAT44((int)((ulonglong)uVar27 >> 0x20),uVar12);
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),1);
          in_stack_fffffffffffffee8 = (double)CONCAT44(uVar19,uVar16);
          in_stack_fffffffffffffed8 = CONCAT22((short)((uint)uVar20 >> 0x10),sVar10 + -800);
          FUN_1400709b0(3,1,fVar1,fVar23,in_stack_fffffffffffffed8,uVar5,in_stack_fffffffffffffee8,
                        uVar15,in_stack_fffffffffffffef8,18000,0);
          uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
          in_stack_fffffffffffffee0 = uVar5;
        }
        uVar20 = SUB84(DAT_140539d28,0);
        uVar21 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
      }
      iVar7 = param_1[3];
      if ((0x3b < iVar7) && (uVar5 = (iVar7 + -0x3c) % iVar9, (int)uVar5 < 0x20)) {
        uVar5 = uVar5 & 0x80000007;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
        }
        if (uVar5 == 0) {
          uVar15 = CONCAT44((int)(in_stack_fffffffffffffef8 >> 0x20),uVar22);
          uVar12 = CONCAT22((short)(in_stack_fffffffffffffed8 >> 0x10),sVar6 * (short)iVar7);
          FUN_1400709b0(4,0,fVar1,fVar24,uVar12,0,dVar18,CONCAT44(uVar26,1),uVar15,0x10000,0);
          in_stack_fffffffffffffef8 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),uVar22);
          in_stack_fffffffffffffee0 = 0;
          in_stack_fffffffffffffed8 =
               CONCAT22((short)((uint)uVar12 >> 0x10),sVar6 * *(short *)(param_1 + 3) + 800);
          FUN_1400709b0(4,0,fVar1,fVar24,in_stack_fffffffffffffed8,0,dVar18,1,
                        in_stack_fffffffffffffef8,0x10000,0);
          in_stack_fffffffffffffee8 = dVar18;
        }
      }
      uVar12 = SUB84(DAT_14053a020,0);
      uVar16 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
    }
  }
  if ((int)param_1[7] < 1) {
    FUN_14007b010(param_1,0x708,0xc);
    in_stack_fffffffffffffee0 = 0;
    FUN_140109660(0x18,param_1[10],param_1[0xb],0,in_stack_fffffffffffffed8 & 0xffff0000,0,
                  (ulonglong)in_stack_fffffffffffffee8 & 0xffffffff00000000);
    uVar22 = *(undefined4 *)(&DAT_140e419c4 + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar4 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar4 = (undefined8 *)_malloc_base(0x60);
      if (puVar4 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar11 = DAT_140e45d78 == (undefined8 *)0x0;
      *puVar4 = 1;
      *(undefined4 *)(puVar4 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar4 + 0xc) = uVar22;
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
      if (bVar11) {
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
  }
LAB_140087e21:
  if (param_1[5] == 2) {
    iVar7 = param_1[3];
    dVar13 = (double)FUN_140332d90(((double)iVar7 - 0.0) * DAT_14053ab68 *
                                   (double)CONCAT44(uVar16,uVar12) * (double)CONCAT44(uVar21,uVar20)
                                  );
    dVar13 = dVar13 * DAT_140539e98 + dVar3;
    if (iVar7 < 0x3d) {
      FUN_14007ac00(param_1);
    }
    uVar25 = (undefined2)(in_stack_fffffffffffffee0 >> 0x10);
    if (param_1[3] == 0x3c) {
      uVar8 = param_1[1] + DAT_140e418c8;
      uVar5 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar5 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      DAT_140e9fd1c = uVar5;
      uVar15 = FUN_140134db0(uVar8,dVar3,DAT_140539f58);
      uVar12 = (undefined4)uVar15;
      uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);
      uVar15 = FUN_140134db0(param_1[1] + DAT_140e418c8);
      in_stack_fffffffffffffef8 = CONCAT44(uVar16,uVar12);
      in_stack_fffffffffffffee0 = CONCAT22(uVar25,(short)uVar5 - (short)(uVar5 / 0x10001));
      FUN_140070d00(0x37,DAT_140e41a88,0x15,param_1[10],(float)param_1[0xb] + DAT_14053ac80,
                    in_stack_fffffffffffffee0,dVar3,uVar15,in_stack_fffffffffffffef8,0x78,0xff,0xff,
                    0xff,0x80,0);
      FUN_140079e20(param_1,2);
      *param_1 = 0;
    }
  }
  in_stack_fffffffffffffee0 = in_stack_fffffffffffffee0 & 0xffff0000;
  FUN_1400c8410(DAT_140e44b7c,0x18,0x17,param_1[10],param_1[0xb],in_stack_fffffffffffffee0,dVar13,
                dVar3,in_stack_fffffffffffffef8 & 0xffffffff00000000,0,0,0x40,1,0);
  FUN_1400c8410(DAT_140e44b7c,0x1a,7,param_1[10],param_1[0xb],in_stack_fffffffffffffee0 & 0xffff0000
                ,dVar13,dVar3,0xff,0xff,0xff,0xff,1,0);
  if (param_1[0x15] == 0) {
    FUN_140079c10(param_1,1);
  }
  if (DAT_14053af54 <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


