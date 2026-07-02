// Function: FUN_140211c40 @ 140211c40
// Decompile completed: true

void FUN_140211c40(void)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  longlong lVar5;
  uint *puVar6;
  longlong lVar7;
  longlong lVar8;
  
  if (DAT_140ca59d8 != 0) {
    puVar6 = &DAT_1407cdd44;
    lVar7 = 0;
    lVar2 = *(longlong *)(DAT_140c3e340 + 0x10);
    lVar8 = 3;
    lVar5 = lVar2;
    do {
      if (DAT_14098ba90 == 0) {
LAB_140211df2:
        FUN_1401ae2f0(lVar5,&DAT_14056f5c0,0x40);
      }
      else {
        uVar1 = *puVar6;
        if (((((int)uVar1 < 0) || ((uVar1 & 0x7c000000) != DAT_14098bae0)) ||
            (DAT_14098bae8 <= (int)(uVar1 & 0x3ffff))) ||
           ((piVar3 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar1 & 0x3ffff) * 8),
            piVar3 == (int *)0x0 || (*piVar3 << 0x12 != (uVar1 & 0x3fc0000))))) goto LAB_140211df2;
        if (piVar3[6] != 0) {
          if ((piVar3[6] < 2) && (-1 < piVar3[8])) {
            iVar4 = FUN_1401afbe0();
          }
          else {
            iVar4 = FUN_1401b82b0(uVar1);
          }
          if ((iVar4 < 0) ||
             (*(longlong *)(DAT_14098ba98 + (ulonglong)(*puVar6 & 0x3ffff) * 8) == 0))
          goto LAB_140211df2;
        }
        *(int *)(lVar7 + lVar2) = piVar3[0x80];
        *(int *)(lVar7 + 4 + lVar2) = piVar3[0x84];
        *(int *)(lVar7 + 8 + lVar2) = piVar3[0x88];
        *(int *)(lVar2 + 0xc + lVar7) = piVar3[0x8c];
        *(int *)(lVar2 + 0x10 + lVar7) = piVar3[0x81];
        *(int *)(lVar2 + 0x14 + lVar7) = piVar3[0x85];
        *(int *)(lVar2 + 0x18 + lVar7) = piVar3[0x89];
        *(int *)(lVar2 + 0x1c + lVar7) = piVar3[0x8d];
        *(int *)(lVar2 + 0x20 + lVar7) = piVar3[0x82];
        *(int *)(lVar2 + 0x24 + lVar7) = piVar3[0x86];
        *(int *)(lVar2 + 0x28 + lVar7) = piVar3[0x8a];
        *(int *)(lVar2 + 0x2c + lVar7) = piVar3[0x8e];
        *(int *)(lVar2 + 0x30 + lVar7) = piVar3[0x83];
        *(int *)(lVar2 + 0x34 + lVar7) = piVar3[0x87];
        *(int *)(lVar2 + 0x38 + lVar7) = piVar3[0x8b];
        *(int *)(lVar2 + 0x3c + lVar7) = piVar3[0x8f];
      }
      lVar5 = lVar5 + 0x40;
      puVar6 = puVar6 + 1;
      lVar7 = lVar7 + 0x40;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    *(undefined4 *)(DAT_140c3e340 + 0x18) = 1;
  }
  return;
}


