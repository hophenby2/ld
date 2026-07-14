// Function: FUN_1400870a0 @ 1400870a0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400870a0(undefined4 *param_1)

{
  float fVar1;
  short sVar2;
  double dVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_XMM0_Da;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  float fVar14;
  double dVar15;
  float fVar16;
  undefined4 in_stack_ffffffffffffff30;
  ushort uVar18;
  uint uVar17;
  ulonglong in_stack_ffffffffffffff48;
  longlong lVar19;
  undefined8 uVar20;
  
  uVar12 = _UNK_14053bb28;
  dVar3 = _DAT_14053bb20;
  uVar18 = (ushort)((uint)in_stack_ffffffffffffff30 >> 0x10);
  fVar14 = (float)DAT_1407c77a4 + (float)param_1[0xb];
  uVar9 = SUB84(_DAT_14053bb20,0);
  param_1[0xb] = fVar14;
  if (param_1[5] != 0) goto LAB_1400875c4;
  iVar6 = param_1[3];
  dVar10 = (double)FUN_140332d90(((double)iVar6 - 0.0) * _DAT_14053aa60 * DAT_14053a020 *
                                 DAT_140539d28);
  uVar5 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
  dVar10 = dVar10 * _DAT_14053b050 + dVar3;
  if (0.0 <= fVar14) {
    param_1[0x15] = 0;
  }
  if (param_1[0x15] == 0) {
    fVar16 = fVar14 - DAT_14053accc;
    fVar1 = (float)param_1[10];
    dVar11 = (double)FUN_1403300b4((double)(DAT_140e445dc - fVar16),(double)(DAT_140e445d8 - fVar1))
    ;
    iVar8 = DAT_140e419b8;
    uVar5 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
    if (fVar14 < DAT_14053ae48) {
      iVar7 = 1;
      if (DAT_140e419b8 == 0) {
        iVar7 = 0x8c;
      }
      else if (DAT_140e419b8 == 1) {
        iVar7 = 100;
      }
      else if ((DAT_140e419b8 == 2) || (DAT_140e419b8 == 3)) {
        iVar7 = 0x50;
      }
      else if (DAT_140e419b8 == 4) {
        iVar7 = 0x32;
      }
      dVar15 = DAT_14053a0b0;
      if ((((DAT_140e419b8 != 0) && (dVar15 = DAT_14053a0f8, DAT_140e419b8 != 1)) &&
          (dVar15 = DAT_14053a138, DAT_140e419b8 != 2)) &&
         ((dVar15 = DAT_14053a190, DAT_140e419b8 != 3 && (dVar15 = dVar3, DAT_140e419b8 == 4)))) {
        dVar15 = DAT_14053a1c8;
      }
      if (((7 < DAT_1407c7798) && (dVar15 = DAT_14053a0d0, DAT_140e419b8 != 0)) &&
         ((dVar15 = DAT_14053a118, DAT_140e419b8 != 1 &&
          (((dVar15 = DAT_14053a158, DAT_140e419b8 != 2 &&
            (dVar15 = DAT_14053a190, DAT_140e419b8 != 3)) && (dVar15 = dVar3, DAT_140e419b8 == 4))))
         )) {
        dVar15 = DAT_14053a1c8;
      }
      if (0x4f < iVar6) {
        if ((iVar6 + -0x50) % iVar7 == 0) {
          *(short *)((longlong)param_1 + 0x42) = (short)(int)(dVar11 * DAT_14053aba0);
          iVar6 = (iVar6 + -0x50) % iVar7;
        }
        else if ((iVar6 < 0x50) || (iVar6 = (iVar6 + -0x50) % iVar7, 0x2f < iVar6))
        goto LAB_14008732b;
        if (iVar6 == (iVar6 / 0xc) * 0xc) {
          in_stack_ffffffffffffff48 = in_stack_ffffffffffffff48 & 0xffffffff00000000;
          uVar18 = 0;
          FUN_14006c2f0(0xc,0,fVar1,fVar16,*(undefined2 *)((longlong)param_1 + 0x42),0,dVar15,1,
                        in_stack_ffffffffffffff48);
          iVar8 = DAT_140e419b8;
        }
      }
LAB_14008732b:
      uVar5 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
      if (((2 < iVar8) && (0x55 < (int)param_1[3])) &&
         ((iVar7 = (param_1[3] + -0x56) % iVar7, iVar7 < 0x24 && (iVar7 == (iVar7 / 0xc) * 0xc)))) {
        sVar2 = *(short *)((longlong)param_1 + 0x42);
        iVar6 = 0;
        do {
          in_stack_ffffffffffffff48 = in_stack_ffffffffffffff48 & 0xffffffff00000000;
          uVar18 = 0;
          FUN_14006c2f0(0xc,0,fVar1,fVar16,(short)iVar6 * 0x4b0 + sVar2 + -600,0,dVar15,1,
                        in_stack_ffffffffffffff48);
          uVar5 = (uint)(in_stack_ffffffffffffff48 >> 0x20);
          iVar6 = iVar6 + 1;
        } while (iVar6 < 2);
      }
    }
  }
  fVar14 = DAT_14053acbc;
  uVar4 = param_1[1] & 0x80000003;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
  }
  lVar19 = (ulonglong)uVar5 << 0x20;
  uVar17 = (uint)uVar18 << 0x10;
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44b6c + (longlong)(int)uVar4 * 4),0x18,0x17,param_1[10],
                (float)param_1[0xb] - DAT_14053acbc,uVar17,dVar10,dVar3,lVar19,0,0,0x40,1,0);
  uVar5 = param_1[1] & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  uVar20 = CONCAT44((int)((ulonglong)lVar19 >> 0x20),0xff);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e44b6c + (longlong)(int)uVar5 * 4),0x19,7,param_1[10],
                (float)param_1[0xb] - fVar14,uVar17 & 0xffff0000,dVar10,dVar3,uVar20,0xff,0xff,0xff,
                1,0);
  uVar13 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar5 = 0;
  iVar6 = FUN_1400c9580((float)param_1[0xb] - DAT_14053accc,0,3,3,0x14,0x15,0x16);
  uVar5 = uVar5 & 0xffff0000;
  FUN_1400c8410((&DAT_140e44660)[iVar6],0x19,7,param_1[10],extraout_XMM0_Da,uVar5,dVar3,uVar12,
                CONCAT44(uVar13,0xff),0xff,0xff,0xff,1,0);
  uVar18 = (ushort)(uVar5 >> 0x10);
  FUN_140079c10(param_1,2);
LAB_1400875c4:
  if ((int)param_1[7] < 1) {
    uVar4 = DAT_140e418c8 + param_1[1];
    uVar5 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar5 = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    DAT_140e9fd1c = uVar5;
    uVar12 = FUN_140134db0(uVar4,DAT_140539f28,uVar9);
    uVar9 = (undefined4)uVar12;
    uVar13 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar12 = FUN_140134db0(uVar4);
    FUN_140070d00(0x37,DAT_140e41948,0x15,param_1[10],(float)param_1[0xb] + DAT_14053ac58,
                  CONCAT22(uVar18,(short)uVar5 - (short)(uVar5 / 0x10001)),dVar3,uVar12,
                  CONCAT44(uVar13,uVar9),0x78,0xff,0xff,0xff,0x80,0);
    FUN_14007b010(param_1,1000,5);
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (DAT_14053af2c <= (float)param_1[0xb]) {
    *param_1 = 0;
  }
  return;
}


