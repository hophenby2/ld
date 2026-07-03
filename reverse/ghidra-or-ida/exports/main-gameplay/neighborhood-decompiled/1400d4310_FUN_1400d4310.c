// Function: FUN_1400d4310 @ 1400d4310
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d4310(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  
  fVar5 = DAT_14053ad40;
  fVar4 = DAT_14053accc;
  dVar3 = DAT_14053a998;
  dVar2 = DAT_14053a020;
  dVar1 = DAT_140539d28;
  iVar10 = 0;
  iVar11 = iVar10;
  do {
    iVar9 = iVar11 + 0xc;
    iVar13 = iVar11;
    iVar12 = iVar10;
    do {
      iVar7 = iVar10;
      if (iVar13 != iVar9) {
        if (param_1 < iVar9 + -0xc) {
          iVar7 = 0;
          if (iVar9 <= param_1) goto LAB_1400d441b;
        }
        else if (param_1 < iVar9) {
          dVar14 = (double)FUN_140332d90(((double)param_1 - (double)(iVar9 + -0x18)) * dVar3 * dVar2
                                         * dVar1);
          iVar7 = -0xb4 - (int)(dVar14 * _DAT_14053b1e8);
        }
        else {
LAB_1400d441b:
          iVar7 = -0xb4;
        }
      }
      dVar14 = DAT_140539f40;
      if (iVar9 + -0xc != iVar9) {
        if (param_1 < iVar9 + -0xc) {
          if (iVar9 <= param_1) goto LAB_1400d4489;
        }
        else if (param_1 < iVar9) {
          dVar14 = (double)FUN_140332d90(((double)param_1 - (double)(iVar9 + -0x18)) * dVar3 * dVar2
                                         * dVar1);
          dVar14 = dVar14 + 0.0;
        }
        else {
LAB_1400d4489:
          dVar14 = 0.0;
        }
      }
      uVar8 = DAT_140e41a44;
      if ((iVar12 + iVar11 & 1U) != 0) {
        uVar8 = DAT_140e41a48;
      }
      puVar6 = (undefined4 *)_malloc_base(0x48);
      if (puVar6 == (undefined4 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *puVar6 = uVar8;
      puVar6[1] = 0x7d;
      puVar6[2] = 1;
      puVar6[3] = (float)iVar11 * fVar5;
      puVar6[4] = (float)iVar12 * fVar5 + fVar4 + (float)iVar7;
      *(undefined2 *)(puVar6 + 5) = 0;
      *(double *)(puVar6 + 6) = dVar14;
      *(undefined8 *)(puVar6 + 8) = 0x3ff0000000000000;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0xff;
      puVar6[0xc] = 0xff;
      puVar6[0xd] = 0xff;
      *(undefined8 *)(puVar6 + 0xe) = 1;
      *(undefined8 *)(puVar6 + 0x10) = 0;
      _DAT_140e46e84 = _DAT_140e46e84 + 1;
      if (DAT_140e46bf0 == (undefined4 *)0x0) {
        DAT_140e46bf0 = puVar6;
      }
      if (DAT_140e46c88 != (undefined4 *)0x0) {
        *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar6;
      }
      iVar12 = iVar12 + 1;
      iVar9 = iVar9 + 3;
      iVar13 = iVar13 + 3;
      DAT_140e46c88 = puVar6;
    } while (iVar12 < 6);
    iVar11 = iVar11 + 1;
    if (0xb < iVar11) {
      if ((param_1 < 0x1c) &&
         (param_1 ==
          (param_1 / 3 + (param_1 >> 0x1f) +
          (int)(((longlong)param_1 / 3 + ((longlong)param_1 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 3))
      {
        FUN_140184700(DAT_140e44190 * 0xc,DAT_140e47210);
        FUN_14018a340(DAT_140e47210,1,1);
      }
      return;
    }
  } while( true );
}


