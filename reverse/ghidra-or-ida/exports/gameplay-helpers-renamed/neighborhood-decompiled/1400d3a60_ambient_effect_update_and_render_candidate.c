// Function: ambient_effect_update_and_render_candidate @ 1400d3a60
// Decompile completed: true

void ambient_effect_update_and_render_candidate(void)

{
  undefined1 auVar1 [16];
  undefined4 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  bool bVar16;
  double dVar17;
  float fVar18;
  
  uVar9 = DAT_140e9fda8 + DAT_140e451bc;
  uVar3 = DAT_140e451bc & 0x8000000f;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
  }
  iVar8 = 0;
  if (uVar3 == 10) {
    dVar17 = (double)FUN_140134db0(DAT_140e451bc - 0x29a,DAT_140539f00,DAT_140539f40);
    uVar3 = (uVar9 + 6 >> 0x1e ^ uVar9 + 6) * 0x6c078965 + 1;
    uVar5 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    uVar5 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    uVar6 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 4;
    uVar11 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar11 >> 0x1e ^ uVar11) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar5 = uVar11 * 0x800 ^ uVar11;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
    auVar1._8_4_ = SUB84(dVar17,0);
    auVar1._0_8_ = dVar17;
    auVar1._12_4_ = (int)((ulonglong)dVar17 >> 0x20);
    FUN_140070d00(0,DAT_140e41a40,10,uVar11,
                  (float)(((uVar6 >> 0xb ^ uVar3) >> 8 ^ uVar6 ^ uVar3) % 0x1a5 + 400),0xc000,
                  dVar17 * DAT_14053a0b0,auVar1,0,0xff,0xff,0xff,0x40,0);
  }
  if ((int)DAT_140e451bc % 0x3c == 10) {
    uVar6 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 1;
    uVar13 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    uVar12 = (uVar13 >> 0x1e ^ uVar13) * 0x6c078965 + 3;
    uVar3 = uVar6 ^ uVar6 * 0x800;
    uVar11 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 4;
    uVar5 = uVar6 ^ uVar6 * 0x800;
    iVar7 = ((uVar11 >> 0xb ^ uVar3) >> 8 ^ uVar11 ^ uVar3) % 0xd + 0x18;
    DAT_140e9fd1c = (uVar11 >> 0xb ^ uVar5) >> 8 ^ uVar11 ^ uVar5;
    uVar3 = DAT_140e9fd1c / 0x10001;
    sVar14 = (short)DAT_140e9fd1c;
    DAT_140e9fd10 = uVar13;
    DAT_140e9fd14 = uVar12;
    DAT_140e9fd18 = uVar11;
    if (iVar7 != 0) {
      uVar5 = (uVar9 + 0x42 >> 0x1e ^ uVar9 + 0x42) * 0x6c078965 + 1;
      uVar9 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      uVar9 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 3;
      uVar6 = uVar6 * 0x800 ^ uVar6;
      uVar15 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 4;
      uVar9 = (uVar11 >> 0xb ^ uVar6) >> 8 ^ uVar6 ^ uVar11;
      iVar10 = DAT_140e45d1c;
      do {
        uVar2 = DAT_140e41930;
        uVar6 = uVar5 * 0x800 ^ uVar5;
        fVar18 = (float)(((uVar15 >> 0xb ^ uVar6) >> 8 ^ uVar15 ^ uVar6) % 0x2d1);
        puVar4 = DAT_140e45d28;
        DAT_140e9fd10 = uVar13;
        DAT_140e9fd14 = uVar12;
        DAT_140e9fd18 = uVar11;
        DAT_140e9fd1c = uVar9;
        if (iVar10 < 0x1000) {
          puVar4 = (undefined8 *)_malloc_base();
          if (puVar4 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar2;
          iVar10 = DAT_140e45d1c + 1;
          bVar16 = DAT_140e45d78 == (undefined8 *)0x0;
          puVar4[5] = 0x401ecccccccccccd;
          puVar4[6] = 0x3ff0000000000000;
          puVar4[7] = 0x3ff0000000000000;
          *(float *)((longlong)puVar4 + 0x14) = (float)(uVar9 % 0x501);
          *(float *)(puVar4 + 3) = fVar18;
          *(float *)((longlong)puVar4 + 0x1c) = (float)(uVar9 % 0x501);
          *(float *)(puVar4 + 4) = fVar18;
          *puVar4 = 1;
          *(undefined4 *)(puVar4 + 1) = 1;
          *(undefined4 *)(puVar4 + 2) = 0xb;
          *(short *)((longlong)puVar4 + 0x24) =
               (short)iVar8 * (short)(0x10000 / (ulonglong)(longlong)iVar7) +
               (sVar14 - (short)uVar3);
          *(undefined4 *)(puVar4 + 8) = 0;
          *(undefined4 *)((longlong)puVar4 + 0x44) = 0x90;
          *(undefined4 *)(puVar4 + 9) = 0xc5;
          *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
          puVar4[10] = 0x60;
          puVar4[0xb] = 0;
          if (bVar16) {
            DAT_140e45d78 = puVar4;
          }
          DAT_140e45d1c = iVar10;
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar4;
          }
        }
        DAT_140e45d28 = puVar4;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar7);
    }
  }
  FUN_140070e40();
  FUN_1400714d0();
  return;
}


