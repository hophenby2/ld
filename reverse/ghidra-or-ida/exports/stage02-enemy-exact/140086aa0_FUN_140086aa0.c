// Function: FUN_140086aa0 @ 140086aa0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140086aa0(undefined4 *param_1)

{
  float fVar1;
  undefined2 uVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float fVar16;
  undefined4 in_stack_ffffffffffffff28;
  undefined2 uVar17;
  undefined4 in_stack_ffffffffffffff30;
  ushort uVar18;
  undefined8 in_stack_ffffffffffffff40;
  ulonglong in_stack_ffffffffffffff48;
  
  dVar3 = DAT_140539f40;
  uVar18 = (ushort)((uint)in_stack_ffffffffffffff30 >> 0x10);
  uVar17 = (undefined2)((uint)in_stack_ffffffffffffff28 >> 0x10);
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  fVar15 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  param_1[0xb] = fVar15;
  dVar14 = DAT_14053a020;
  dVar10 = DAT_140539d28;
  if (param_1[5] == 0) {
    iVar4 = param_1[3];
    dVar13 = (double)iVar4 - 0.0;
    dVar9 = (double)FUN_140332d90(dVar13 * DAT_14053a930 * DAT_14053a020 * DAT_140539d28);
    dVar9 = dVar9 * _DAT_14053b050;
    if (iVar4 % 0x78 < 0xb) {
      dVar9 = (double)FUN_140332d90(dVar13 * _DAT_14053ab30 * dVar14 * dVar10);
      dVar9 = dVar9 * _DAT_140539e28;
    }
    uVar7 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
    if (0.0 <= fVar15) {
      param_1[0x15] = 0;
    }
    if (param_1[0x15] == 0) {
      fVar16 = fVar15 + DAT_14053ac80;
      fVar1 = (float)param_1[10];
      dVar10 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar16),
                                     (double)(DAT_140e445d8 - fVar1));
      iVar4 = DAT_140e418c8;
      uVar7 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
      if (fVar15 < DAT_14053ae48) {
        iVar6 = 1;
        if (DAT_140e419b8 == 0) {
          iVar6 = 0x5a;
        }
        else if (DAT_140e419b8 == 1) {
          iVar6 = 0x32;
        }
        else if (DAT_140e419b8 == 2) {
          iVar6 = 0x28;
        }
        else if (DAT_140e419b8 == 3) {
          iVar6 = 0x1e;
        }
        else if (DAT_140e419b8 == 4) {
          iVar6 = 0x14;
        }
        dVar14 = DAT_14053a088;
        if ((((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a0d0, DAT_140e419b8 != 1)) &&
            (dVar14 = DAT_14053a118, DAT_140e419b8 != 2)) &&
           ((dVar14 = DAT_14053a138, DAT_140e419b8 != 3 && (dVar14 = dVar3, DAT_140e419b8 == 4)))) {
          dVar14 = DAT_14053a178;
        }
        if (7 < DAT_1407c7798) {
          iVar6 = 1;
          if (DAT_140e419b8 == 0) {
            iVar6 = 0x3c;
          }
          else if (DAT_140e419b8 == 1) {
            iVar6 = 0x28;
          }
          else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
            iVar6 = 0x1e;
          }
          else if (DAT_140e419b8 == 4) {
            iVar6 = 0x14;
          }
          dVar14 = DAT_14053a0d0;
          if ((((DAT_140e419b8 != 0) && (dVar14 = DAT_14053a118, DAT_140e419b8 != 1)) &&
              (dVar14 = DAT_14053a138, DAT_140e419b8 != 2)) &&
             ((DAT_140e419b8 != 3 && (dVar14 = dVar3, DAT_140e419b8 == 4)))) {
            dVar14 = DAT_14053a178;
          }
        }
        if (-1 < DAT_140e418c8) {
          if (DAT_140e418c8 % iVar6 == 0) {
            *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar10 * DAT_14053aba0) + 0x400;
          }
          if (((-1 < iVar4) && (iVar4 = iVar4 % iVar6, iVar4 < 9)) &&
             (iVar4 == (iVar4 / 3 + (iVar4 >> 0x1f) +
                       (int)(((longlong)iVar4 / 3 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >> 0x1f
                            )) * 3)) {
            uVar2 = *(undefined2 *)((longlong)param_1 + 0x42);
            in_stack_ffffffffffffff48 = in_stack_ffffffffffffff48 & 0xffffffff00000000;
            uVar18 = 0;
            uVar5 = CONCAT22(uVar17,uVar2) & 0xfffff800;
            FUN_14006c2f0(1,0,fVar1,fVar16,uVar5,0,dVar14,CONCAT44(uVar8,1),
                          in_stack_ffffffffffffff48);
            uVar7 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
            if (2 < DAT_140e419b8) {
              in_stack_ffffffffffffff48 = in_stack_ffffffffffffff48 & 0xffffffff00000000;
              uVar18 = 0;
              FUN_14006c2f0(1,0,fVar1,fVar16,CONCAT22((short)(uVar5 >> 0x10),uVar2) & 0xfffff800,0,
                            dVar14 + DAT_140539fb8,1,in_stack_ffffffffffffff48);
              uVar7 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
            }
          }
        }
      }
    }
    uVar5 = (uint)uVar18 << 0x10;
    FUN_1400c8410(DAT_140e446ac,0x18,0x17,param_1[10],param_1[0xb],uVar5,dVar9 + dVar3,dVar3,
                  (ulonglong)uVar7 << 0x20,0,0,0x40,1,0);
    uVar5 = uVar5 & 0xffff0000;
    FUN_1400c8410(DAT_140e446ac,0x19,7,param_1[10],param_1[0xb],uVar5,dVar9 + dVar3,dVar3,0xff,0xff,
                  0xff,0xff,1,0);
    uVar18 = (ushort)(uVar5 >> 0x10);
    FUN_140079c10(param_1,2);
  }
  if ((int)param_1[7] < 1) {
    uVar5 = param_1[1] + DAT_140e418c8;
    uVar7 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar7 = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
    DAT_140e9fd1c = uVar7;
    uVar11 = FUN_140134db0(uVar5,dVar3,DAT_140539f68);
    uVar8 = (undefined4)uVar11;
    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar11 = FUN_140134db0(uVar5);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],(float)param_1[0xb] + DAT_14053ac2c,
                  CONCAT22(uVar18,(short)uVar7 - (short)(uVar7 / 0x10001)),dVar3,uVar11,
                  CONCAT44(uVar12,uVar8),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,1000,5);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (DAT_14053af2c <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


