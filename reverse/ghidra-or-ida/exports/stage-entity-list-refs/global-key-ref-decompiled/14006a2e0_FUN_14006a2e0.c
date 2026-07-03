// Function: FUN_14006a2e0 @ 14006a2e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14006a2e0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  float fStack_c0;
  float fStack_bc;
  undefined1 local_80 [120];
  
  dVar11 = DAT_14053a020;
  dVar4 = DAT_140539d28;
  lVar5 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x60)) {
      if (*(int *)(lVar5 + 4) == param_1[2]) {
        fStack_c0 = *(float *)(lVar5 + 0x28);
        fStack_bc = *(float *)(lVar5 + 0x2c);
      }
    }
  }
  iVar1 = param_1[6];
  if (iVar1 == 0x128) {
    iVar1 = param_1[3];
    fVar12 = DAT_14053aec0;
    if ((-1 < iVar1) && (fVar12 = 0.0, iVar1 < 0x3c)) {
      dVar3 = (double)FUN_140332d90(SUB84(((double)iVar1 - 0.0) * DAT_14053a628 * DAT_14053a020 *
                                          DAT_140539d28,0));
      fVar12 = (float)(dVar3 * _DAT_14053b260) + DAT_14053aec0;
    }
    uVar14 = SUB84((double)*(ushort *)(param_1 + 0x10) * dVar11 * dVar4,0);
    dVar3 = (double)FUN_1403307c0(uVar14);
    dVar10 = (double)FUN_140332d90(uVar14);
    param_1[10] = (float)(dVar3 * (double)fVar12) + fStack_c0;
    param_1[0xb] = (float)(dVar10 * (double)fVar12) + fStack_bc;
    if (iVar1 != 0x3c) goto LAB_14006a5ba;
  }
  else if (iVar1 == 0x129) {
    uVar14 = SUB84((double)*(ushort *)(param_1 + 0x10) * DAT_14053a020 * DAT_140539d28,0);
    dVar3 = (double)FUN_1403307c0(uVar14);
    fVar13 = (float)(dVar3 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    param_1[10] = fVar13;
    dVar3 = (double)FUN_140332d90(uVar14);
    fVar12 = ((float)(dVar3 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb]) -
             (float)(int)param_1[3] * DAT_140539cec;
    param_1[0xb] = fVar12;
    if (((DAT_140e445d8 / DAT_14053ab70 - DAT_14053acbc <= fVar13) &&
        (fVar13 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aee0)) &&
       ((DAT_14053b358 <= fVar12 && (fVar12 <= _DAT_14053af34)))) goto LAB_14006a5ba;
  }
  else {
    if (iVar1 != 0x12a) goto LAB_14006a5ba;
    dVar3 = *(double *)(param_1 + 0x12);
    uVar14 = SUB84((double)*(ushort *)(param_1 + 0x10) * DAT_14053a020 * DAT_140539d28,0);
    dVar10 = (double)FUN_1403307c0(uVar14);
    fVar13 = (float)(dVar10 * dVar3) + (float)param_1[10];
    param_1[10] = fVar13;
    dVar10 = (double)FUN_140332d90(uVar14);
    *(double *)(param_1 + 0x12) = dVar3 + DAT_140539ee0;
    fVar12 = (float)(dVar10 * dVar3) + (float)param_1[0xb];
    param_1[0xb] = fVar12;
    if ((((DAT_140e445d8 / DAT_14053ab70 - DAT_14053acbc <= fVar13) &&
         (fVar13 <= DAT_140e445d8 / DAT_14053ab70 + DAT_14053aee0)) && (DAT_14053b358 <= fVar12)) &&
       (fVar12 <= _DAT_14053af34)) goto LAB_14006a5ba;
  }
  *param_1 = 0;
LAB_14006a5ba:
  iVar1 = param_1[3];
  iVar2 = param_1[1];
  uVar7 = iVar1 * 0x22b8 + iVar2;
  uVar7 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
  uVar8 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
  uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 3;
  uVar7 = uVar7 * 0x800 ^ uVar7;
  uVar9 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 4;
  uVar8 = iVar1 * 0x378 + iVar2;
  uVar8 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 1;
  DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  uVar8 = uVar8 * 0x800 ^ uVar8;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar8) >> 8 ^ DAT_140e9fd18 ^ uVar8;
  dVar3 = (double)(((uVar9 >> 0xb ^ uVar7) >> 8 ^ uVar9 ^ uVar7) % 0x11);
  uVar14 = SUB84((double)(DAT_140e9fd1c - DAT_140e9fd1c / 0x10001 & 0xffff) * dVar11 * dVar4,0);
  dVar4 = (double)FUN_1403307c0(uVar14);
  fVar12 = (float)param_1[10];
  dVar11 = (double)FUN_140332d90(uVar14);
  fVar13 = (float)(dVar11 * dVar3) + (float)param_1[0xb];
  dVar11 = (double)FUN_140134db0(iVar1 * 0x15b38 + iVar2,DAT_140539f00,DAT_140539f40);
  dVar10 = (double)(float)dVar11;
  dVar11 = dVar10;
  puVar6 = (undefined8 *)
           FUN_140134fa0(local_80,((int)(((longlong)iVar1 / 3 + ((longlong)iVar1 >> 0x3f) &
                                         0xffffffffU) >> 0x1f) + iVar1 / 3 + (iVar1 >> 0x1f)) % 7 +
                                  1);
  uVar7 = iVar1 * 0x58 + iVar2;
  uVar8 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 1;
  uVar7 = uVar8 * 0x800 ^ uVar8;
  DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
  DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
  DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
  DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
  FUN_140070d00(4,DAT_140e41974,0x22,(float)(dVar4 * dVar3) + fVar12,fVar13,
                (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001),0,dVar10,dVar11,0x10,
                (int)*puVar6,(int)((ulonglong)*puVar6 >> 0x20),*(undefined4 *)(puVar6 + 1),0xc0,0);
  return;
}


