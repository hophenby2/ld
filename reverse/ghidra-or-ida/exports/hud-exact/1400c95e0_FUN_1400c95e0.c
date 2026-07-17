// Function: FUN_1400c95e0 @ 1400c95e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c95e0(int param_1,int param_2,ulonglong param_3,float param_4,undefined4 param_5,
                  double param_6,undefined8 param_7,undefined4 param_8,int param_9,int param_10)

{
  ulonglong uVar1;
  double dVar2;
  longlong lVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int local_res8;
  undefined1 local_b8 [8] [16];

  dVar2 = DAT_14053ae68;
  fVar13 = (float)param_6;
  iVar5 = 0;
  lVar3 = 0;
  local_res8 = 0;
  uVar7 = 0;
  local_b8[0] = _DAT_14053bc20;
  fVar14 = fVar13 * DAT_14053aa20;
  iVar8 = iVar5;
  uVar1 = param_3;
  uVar9 = param_3;
  if (0 < param_10) {
    do {
      dVar10 = (double)FUN_1403316f0(lVar3,(double)iVar8);
      lVar3 = 0;
      if ((dVar2 <= dVar10) && (dVar10 = dVar10 - dVar2, dVar10 < dVar2)) {
        lVar3 = -0x8000000000000000;
      }
      iVar8 = iVar8 + 1;
      lVar3 = (longlong)dVar10 + lVar3;
      uVar7 = uVar7 + lVar3 * 9;
    } while (iVar8 < param_10);
    if (uVar7 < param_3) {
      uVar1 = uVar7;
      uVar9 = uVar7;
    }
  }
  for (; uVar1 != 0; uVar1 = uVar1 / 10) {
    iVar5 = iVar5 + 1;
  }
  fVar12 = fVar13 * *(float *)(local_b8[0] + (longlong)param_1 * 4);
  fVar11 = param_4;
  if (param_9 == 1) {
    fVar11 = (float)(iVar5 + -1) * fVar12 * DAT_140539d20 + param_4;
    if ((param_1 == 1) && (3 < iVar5)) {
      fVar11 = fVar11 + (float)(iVar5 / 3 + (iVar5 >> 0x1f) +
                               (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU)
                                    >> 0x1f)) * fVar14 * DAT_140539d20;
    }
    if (9 < param_3) goto LAB_1400c9819;
  }
  else {
LAB_1400c9819:
    param_4 = fVar11;
    if (9 < param_3) {
      if (((0 < param_10) && (param_1 == 1)) && (uVar7 < param_3)) {
        FUN_1400c8410(DAT_140e419ac,param_2,1,fVar13 * DAT_14053ac48 + fVar11,param_5,0,param_6,
                      param_7,0xff,0xff,0xff,param_8,1,0);
      }
      do {
        iVar5 = (int)uVar9 + (int)(uVar9 / 10) * -10;
        if ((param_1 == 0) || (param_1 == 1)) {
LAB_1400c9a2a:
          uVar6 = (&DAT_140e41980)[iVar5];
          puVar4 = (undefined4 *)_malloc_base(0x48);
          if (puVar4 == (undefined4 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          *puVar4 = uVar6;
          puVar4[3] = fVar11;
          puVar4[4] = param_5;
          *(double *)(puVar4 + 6) = param_6;
          *(undefined8 *)(puVar4 + 8) = param_7;
          puVar4[1] = param_2;
          puVar4[2] = 1;
          *(undefined2 *)(puVar4 + 5) = 0;
          puVar4[10] = 0xff;
          puVar4[0xb] = 0xff;
          puVar4[0xc] = 0xff;
          puVar4[0xd] = param_8;
          *(undefined8 *)(puVar4 + 0xe) = 1;
          *(undefined8 *)(puVar4 + 0x10) = 0;
          (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
          if (DAT_140e46bf0 == (undefined4 *)0x0) {
            DAT_140e46bf0 = puVar4;
          }
          if (DAT_140e46c88 != (undefined4 *)0x0) {
            *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
          }
          DAT_140e46c88 = puVar4;
          if ((param_1 != 1) ||
             (local_res8 +
              (local_res8 / 3 + (local_res8 >> 0x1f) +
              (int)(((longlong)local_res8 / 3 + ((longlong)local_res8 >> 0x3f) & 0xffffffffU) >>
                   0x1f)) * -3 != 2)) goto LAB_1400c99a7;
          if (uVar9 < 10) {
            return;
          }
          fVar11 = (fVar11 - fVar12) - fVar14;
          FUN_1400c8410(DAT_140e419a8,param_2,1,fVar12 + fVar11,param_5,0,param_6,param_7,0xff,0xff,
                        0xff,param_8,1,0);
        }
        else {
          if (param_1 == 2) {
            uVar6 = (&DAT_140e46c30)[iVar5];
          }
          else {
            if (param_1 != 3) goto LAB_1400c9a2a;
            uVar6 = (&DAT_140e46bf8)[iVar5];
          }
          FUN_1400c8410(uVar6,param_2,1,fVar11,param_5,0,param_6,param_7,0xff,0xff,0xff,param_8,1,0)
          ;
LAB_1400c99a7:
          fVar11 = fVar11 - fVar12;
          if (uVar9 < 10) {
            return;
          }
        }
        local_res8 = local_res8 + 1;
        uVar9 = uVar9 / 10;
      } while( true );
    }
  }
  if ((param_1 != 0) && (param_1 != 1)) {
    if (param_1 == 2) {
      uVar6 = (&DAT_140e46c30)[param_3];
      goto LAB_1400c9c32;
    }
    if (param_1 == 3) {
      uVar6 = (&DAT_140e46bf8)[param_3];
      goto LAB_1400c9c32;
    }
  }
  uVar6 = (&DAT_140e41980)[param_3];
LAB_1400c9c32:
  FUN_1400c8410(uVar6,param_2,1,param_4,param_5,0,param_6,param_7,0xff,0xff,0xff,param_8,1,0);
  return;
}
