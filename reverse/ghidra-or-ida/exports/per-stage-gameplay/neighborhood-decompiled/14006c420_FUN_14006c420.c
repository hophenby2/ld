// Function: FUN_14006c420 @ 14006c420
// Decompile completed: true

void FUN_14006c420(void)

{
  longlong lVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  float fVar11;
  
  dVar4 = DAT_14053a020;
  dVar3 = DAT_140539d28;
  lVar2 = DAT_140e45260;
  while (lVar2 != 0) {
    fVar10 = *(float *)(lVar2 + 0x20);
    dVar9 = (double)*(ushort *)(lVar2 + 0x24) * dVar4 * dVar3;
    dVar8 = (double)FUN_1403307c0(dVar9);
    fVar11 = (float)(dVar8 * (double)fVar10) + *(float *)(lVar2 + 0x10);
    dVar9 = (double)FUN_140332d90(dVar9);
    uVar5 = DAT_140e41a50;
    fVar10 = (float)(dVar9 * (double)fVar10) + *(float *)(lVar2 + 0x14);
    puVar6 = DAT_140e45d28;
    if (DAT_140e45d1c < 0x1000) {
      puVar6 = (undefined8 *)_malloc_base(0x60);
      if (puVar6 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      DAT_140e45d1c = DAT_140e45d1c + 1;
      bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
      *(float *)((longlong)puVar6 + 0x14) = fVar11;
      *(float *)(puVar6 + 3) = fVar10;
      *(float *)((longlong)puVar6 + 0x1c) = fVar11;
      *(float *)(puVar6 + 4) = fVar10;
      *puVar6 = 1;
      *(undefined4 *)(puVar6 + 1) = 0xc;
      *(undefined4 *)((longlong)puVar6 + 0xc) = uVar5;
      *(undefined4 *)(puVar6 + 2) = 0x3d;
      *(undefined2 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[5] = 0;
      puVar6[6] = 0x3fe3333333333333;
      puVar6[7] = 0x3fe3333333333333;
      *(undefined4 *)(puVar6 + 8) = 0x10;
      *(undefined4 *)((longlong)puVar6 + 0x44) = 0xff;
      *(undefined4 *)(puVar6 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = 0xff;
      puVar6[10] = 0xff;
      puVar6[0xb] = 0;
      if (bVar7) {
        DAT_140e45d78 = puVar6;
      }
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar6;
      }
    }
    DAT_140e45d28 = puVar6;
    lVar1 = *(longlong *)(lVar2 + 0x48);
    FUN_140323ce8(lVar2);
    lVar2 = lVar1;
  }
  DAT_140e45260 = 0;
  DAT_140e451a8 = 0;
  DAT_140e451b4 = 0;
  return;
}


