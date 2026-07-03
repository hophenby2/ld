// Function: FUN_14007ac00 @ 14007ac00
// Decompile completed: true

void FUN_14007ac00(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  float fVar15;
  double dVar16;
  float fVar17;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  if (uVar3 == ((int)uVar3 / 3 + ((int)uVar3 >> 0x1f) +
               (int)(((longlong)(int)uVar3 / 3 + ((longlong)(int)uVar3 >> 0x3f) & 0xffffffffU) >>
                    0x1f)) * 3) {
    uVar6 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 1;
    uVar5 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    uVar7 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 3;
    uVar1 = uVar6 * 0x800 ^ uVar6;
    uVar4 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 4;
    DAT_140e9fd1c = (uVar4 >> 0xb ^ uVar1) >> 8 ^ uVar4 ^ uVar1;
    dVar16 = (double)(DAT_140e9fd1c - DAT_140e9fd1c / 0x10001 & 0xffff) * DAT_14053a020 *
             DAT_140539d28;
    DAT_140e9fd10 = uVar5;
    DAT_140e9fd14 = uVar7;
    DAT_140e9fd18 = uVar4;
    iVar2 = FUN_140134d00(uVar3,0,*(int *)(param_1 + 0x50) + 0x32);
    dVar10 = (double)FUN_1403307c0(dVar16);
    fVar17 = (float)(dVar10 * (double)iVar2) + *(float *)(param_1 + 0x28);
    dVar10 = (double)FUN_140332d90(dVar16);
    uVar6 = uVar6 * 0x800 ^ uVar6;
    fVar15 = (float)(dVar10 * (double)iVar2) + *(float *)(param_1 + 0x2c);
    uVar6 = (uVar4 >> 0xb ^ uVar6) >> 8 ^ uVar4 ^ uVar6;
    DAT_140e9fd10 = uVar5;
    DAT_140e9fd14 = uVar7;
    DAT_140e9fd18 = uVar4;
    DAT_140e9fd1c = uVar6;
    uVar11 = FUN_140134db0(DAT_140e418c8);
    uVar8 = (undefined4)uVar11;
    uVar9 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar12 = FUN_140134db0(DAT_140e418c8);
    uVar11 = 0x2a;
    if (DAT_140e418cc != 0) {
      uVar11 = 0x2b;
    }
    FUN_140070d00(uVar11,DAT_140e41a54,0x3e,fVar17,fVar15,(short)uVar6 - (short)(uVar6 / 0x10001),
                  DAT_140539f40,uVar12,CONCAT44(uVar9,uVar8),0x18,0xff,0xff,0xff,0xff,0);
    uVar3 = *(int *)(param_1 + 0xc) * 0x37;
    iVar2 = *(int *)(param_1 + 0xc) * 0x15b3;
    uVar3 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    uVar3 = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    DAT_140e9fd1c = uVar3;
    uVar11 = FUN_140134db0(iVar2,DAT_140539f28,DAT_140539fa8);
    uVar8 = (undefined4)uVar11;
    uVar13 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar11 = FUN_140134db0(iVar2);
    uVar9 = (undefined4)uVar11;
    uVar14 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar11 = FUN_140134db0(DAT_140e418c8 * 0x22b,DAT_14053a238,DAT_14053a290);
    FUN_140070d00(0x2c,DAT_140e44ea8,0x48,fVar17,fVar15,(short)uVar3 - (short)(uVar3 / 0x10001),
                  uVar11,CONCAT44(uVar14,uVar9),CONCAT44(uVar13,uVar8),0,0xff,0xff,0xff,0xc0,0);
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == (iVar2 / 6 + (iVar2 >> 0x1f) +
               (int)(((longlong)iVar2 / 6 + ((longlong)iVar2 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 6)
  {
    FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4729c);
    FUN_14018a340(DAT_140e4729c,1,1);
  }
  return;
}


