// Function: dxarchive_xor_keyconv_candidate @ 1401b3000
// Decompile completed: true

void dxarchive_xor_keyconv_candidate(uint *param_1,ulonglong param_2,longlong param_3,uint *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = (int)param_3 + (int)(param_3 / 7) * -7;
  if ((longlong)param_2 < 0x100000000) {
    if (6 < (uint)param_2) {
      if (iVar9 != 0) {
        lVar6 = (longlong)iVar9 - (longlong)param_1;
        do {
          param_2 = (ulonglong)((int)param_2 - 1);
          *(byte *)param_1 =
               (byte)*param_1 ^ ((byte *)(lVar6 + (longlong)param_1))[(longlong)param_4];
          param_1 = (uint *)((longlong)param_1 + 1);
        } while ((longlong)(lVar6 + (longlong)param_1) < 7);
        iVar9 = 0;
      }
      uVar8 = (uint)param_2;
      if (6 < uVar8) {
        bVar1 = *(byte *)((longlong)param_4 + 6);
        iVar3 = (int)((param_2 & 0xffffffff) * 0x24924925 >> 0x20);
        uVar2 = param_4[1];
        uVar5 = (uVar8 - iVar3 >> 1) + iVar3 >> 2;
        param_2 = (ulonglong)(uVar8 + uVar5 * -7);
        uVar8 = *param_4;
        do {
          *param_1 = *param_1 ^ uVar8;
          *(ushort *)(param_1 + 1) = (ushort)param_1[1] ^ (ushort)uVar2;
          *(byte *)((longlong)param_1 + 6) = *(byte *)((longlong)param_1 + 6) ^ bVar1;
          param_1 = (uint *)((longlong)param_1 + 7);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
    if ((int)param_2 != 0) {
      lVar6 = (longlong)iVar9;
      do {
        lVar7 = lVar6 + 1;
        *(byte *)param_1 = (byte)*param_1 ^ *(byte *)(lVar6 + (longlong)param_4);
        param_1 = (uint *)((longlong)param_1 + 1);
        lVar6 = 0;
        if (lVar7 != 7) {
          lVar6 = lVar7;
        }
        uVar8 = (int)param_2 - 1;
        param_2 = (ulonglong)uVar8;
      } while (uVar8 != 0);
      return;
    }
  }
  else {
    if (6 < (longlong)param_2) {
      if (iVar9 != 0) {
        lVar6 = (longlong)iVar9 - (longlong)param_1;
        do {
          param_2 = param_2 - 1;
          *(byte *)param_1 =
               (byte)*param_1 ^ ((byte *)(lVar6 + (longlong)param_1))[(longlong)param_4];
          param_1 = (uint *)((longlong)param_1 + 1);
        } while ((longlong)(lVar6 + (longlong)param_1) < 7);
        iVar9 = 0;
      }
      if (6 < (longlong)param_2) {
        bVar1 = *(byte *)((longlong)param_4 + 6);
        uVar4 = (longlong)param_2 / 7;
        uVar8 = *param_4;
        param_2 = param_2 - (uint)((int)uVar4 * 7);
        uVar2 = param_4[1];
        do {
          *param_1 = *param_1 ^ uVar8;
          *(ushort *)(param_1 + 1) = (ushort)param_1[1] ^ (ushort)uVar2;
          *(byte *)((longlong)param_1 + 6) = *(byte *)((longlong)param_1 + 6) ^ bVar1;
          param_1 = (uint *)((longlong)param_1 + 7);
          uVar5 = (int)uVar4 - 1;
          uVar4 = (ulonglong)uVar5;
        } while (uVar5 != 0);
      }
    }
    if (0 < (longlong)param_2) {
      lVar6 = (longlong)iVar9;
      do {
        lVar7 = lVar6 + 1;
        *(byte *)param_1 = (byte)*param_1 ^ *(byte *)(lVar6 + (longlong)param_4);
        param_1 = (uint *)((longlong)param_1 + 1);
        param_2 = param_2 - 1;
        lVar6 = 0;
        if (lVar7 != 7) {
          lVar6 = lVar7;
        }
      } while (0 < (longlong)param_2);
    }
  }
  return;
}


