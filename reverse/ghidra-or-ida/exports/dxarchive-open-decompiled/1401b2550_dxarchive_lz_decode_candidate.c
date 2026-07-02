// Function: dxarchive_lz_decode_candidate @ 1401b2550
// Decompile completed: true

undefined4 dxarchive_lz_decode_candidate(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  ushort *puVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  
  uVar11 = 0;
  bVar1 = *(byte *)(param_1 + 2);
  uVar3 = *param_1;
  if (param_2 != (byte *)0x0) {
    iVar4 = param_1[1] + -9;
    puVar5 = (ushort *)((longlong)param_1 + 9);
joined_r0x0001401b25c7:
    while (iVar4 != 0) {
      if ((byte)*puVar5 == bVar1) {
        bVar2 = *(byte *)((longlong)puVar5 + 1);
        uVar7 = (uint)bVar2;
        if (bVar2 != bVar1) {
          if (bVar1 < bVar2) {
            uVar7 = bVar2 - 1;
          }
          puVar9 = puVar5 + 1;
          uVar8 = uVar7 >> 3;
          iVar10 = iVar4 + -2;
          if ((uVar7 & 4) != 0) {
            uVar6 = *puVar9;
            puVar9 = (ushort *)((longlong)puVar5 + 3);
            uVar8 = uVar8 | (uint)(byte)uVar6 << 5;
            iVar10 = iVar4 + -3;
          }
          uVar8 = uVar8 + 4;
          uVar7 = uVar7 & 3;
          if (uVar7 == 0) {
            uVar11 = (uint)(byte)*puVar9;
            puVar9 = (ushort *)((longlong)puVar9 + 1);
            iVar10 = iVar10 + -1;
          }
          else if (uVar7 == 1) {
            uVar6 = *puVar9;
            puVar9 = puVar9 + 1;
            uVar11 = (uint)uVar6;
            iVar10 = iVar10 + -2;
          }
          else if (uVar7 == 2) {
            uVar11 = (uint)(byte)puVar9[1] << 0x10 | (uint)*(byte *)((longlong)puVar9 + 1) << 8 |
                     (uint)(byte)*puVar9;
            puVar9 = (ushort *)((longlong)puVar9 + 3);
            iVar10 = iVar10 + -3;
          }
          uVar11 = uVar11 + 1;
          uVar7 = uVar11;
          iVar4 = iVar10;
          puVar5 = puVar9;
          if (uVar11 < uVar8) goto code_r0x0001401b2698;
          goto LAB_1401b26ce;
        }
        *param_2 = bVar1;
        param_2 = param_2 + 1;
        iVar4 = iVar4 + -2;
        puVar5 = puVar5 + 1;
      }
      else {
        *param_2 = (byte)*puVar5;
        param_2 = param_2 + 1;
        iVar4 = iVar4 + -1;
        puVar5 = (ushort *)((longlong)puVar5 + 1);
      }
    }
  }
  return uVar3;
code_r0x0001401b2698:
  if (uVar11 < uVar8) {
    do {
      FUN_1401ae2f0(param_2,(longlong)param_2 - (ulonglong)uVar7,uVar7);
      uVar8 = uVar8 - uVar7;
      param_2 = param_2 + uVar7;
      uVar7 = uVar7 * 2;
    } while (uVar7 < uVar8);
  }
  if (uVar8 != 0) {
LAB_1401b26ce:
    FUN_1401ae2f0(param_2,(longlong)param_2 - (ulonglong)uVar7,uVar8);
    param_2 = param_2 + uVar8;
  }
  goto joined_r0x0001401b25c7;
}


