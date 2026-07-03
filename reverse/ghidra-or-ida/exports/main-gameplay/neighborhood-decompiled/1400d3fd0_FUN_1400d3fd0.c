// Function: FUN_1400d3fd0 @ 1400d3fd0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d3fd0(int param_1)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  
  fVar6 = DAT_14053ad40;
  fVar5 = DAT_14053accc;
  dVar4 = DAT_14053a998;
  dVar3 = DAT_14053a020;
  dVar2 = DAT_140539d28;
  iVar12 = 0;
  iVar11 = iVar12;
  do {
    iVar14 = iVar11 + 0xc;
    iVar10 = iVar11;
    iVar13 = iVar12;
    do {
      iVar8 = iVar12;
      if (((iVar10 != iVar14) && (iVar8 = 0xb4, iVar10 <= param_1)) &&
         (iVar8 = iVar12, param_1 < iVar10 + 0xc)) {
        dVar15 = (double)FUN_140332d90(((double)param_1 - (double)iVar10) * dVar4 * dVar3 * dVar2);
        iVar8 = 0xb4 - (int)(dVar15 * DAT_14053a548);
      }
      dVar15 = DAT_140539f40;
      if (iVar10 != iVar10 + 0xc) {
        if (param_1 < iVar10) {
          dVar15 = 0.0;
        }
        else if (param_1 < iVar10 + 0xc) {
          dVar15 = (double)FUN_140332d90(((double)param_1 - (double)iVar10) * dVar4 * dVar3 * dVar2)
          ;
          dVar15 = dVar15 + 0.0;
        }
      }
      uVar9 = DAT_140e41a44;
      if ((iVar13 + iVar11 & 1U) != 0) {
        uVar9 = DAT_140e41a48;
      }
      puVar7 = (undefined4 *)_malloc_base(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar7 = uVar9;
      puVar7[1] = 0x7d;
      puVar7[2] = 1;
      puVar7[3] = (float)iVar11 * fVar6;
      puVar7[4] = (float)iVar13 * fVar6 + fVar5 + (float)iVar8;
      *(undefined2 *)(puVar7 + 5) = 0;
      *(double *)(puVar7 + 6) = dVar15;
      *(undefined8 *)(puVar7 + 8) = 0x3ff0000000000000;
      puVar7[10] = 0xff;
      puVar7[0xb] = 0xff;
      puVar7[0xc] = 0xff;
      puVar7[0xd] = 0xff;
      *(undefined8 *)(puVar7 + 0xe) = 1;
      *(undefined8 *)(puVar7 + 0x10) = 0;
      _DAT_140e46e84 = _DAT_140e46e84 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar7;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar7;
      }
      iVar13 = iVar13 + 1;
      iVar10 = iVar10 + 3;
      iVar14 = iVar14 + 3;
      DAT_140e46c88 = puVar7;
    } while (iVar13 < 6);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0xc);
  if (param_1 < 0x1c) {
    if (param_1 ==
        (param_1 / 3 + (param_1 >> 0x1f) +
        (int)(((longlong)param_1 / 3 + ((longlong)param_1 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 3) {
      FUN_140184700(DAT_140e44190 * 0xc,DAT_140e47210);
      FUN_14018a340(DAT_140e47210,1,1);
    }
  }
  else {
    lVar1 = DAT_140e47908;
    if (param_1 == 0x27) {
      while (lVar1 != 0) {
        lVar1 = *(longlong *)(lVar1 + 0x238);
        FUN_140323ce8();
      }
      DAT_140e47908 = 0;
      DAT_140e9fd30 = 0;
    }
  }
  return;
}


