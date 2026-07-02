// Function: FUN_14016c190 @ 14016c190
// Decompile completed: true

undefined8
FUN_14016c190(undefined8 param_1,uint param_2,char *param_3,int param_4,int param_5,
             undefined4 param_6)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  ulonglong uVar13;
  
  piVar12 = (int *)0x0;
  piVar10 = (int *)0x0;
  piVar11 = piVar12;
  if (((((DAT_140989740 != 0) && (piVar11 = piVar10, -1 < (int)param_2)) &&
       ((param_2 & 0x7c000000) == DAT_140989790)) &&
      (((int)(param_2 & 0x3ffff) < DAT_140989798 &&
       (piVar11 = *(int **)(DAT_140989748 + (ulonglong)(param_2 & 0x3ffff) * 8),
       piVar11 != (int *)0x0)))) &&
     ((*piVar11 << 0x12 == (param_2 & 0x3fc0000) && (piVar11[6] != 0)))) {
    if ((piVar11[6] < 2) && (-1 < piVar11[8])) {
      FUN_1401afbe0();
    }
    else {
      FUN_1401b82b0(param_2);
    }
  }
  iVar4 = 0;
  if (-1 < param_5) {
    iVar4 = param_5;
  }
  if ((((*param_3 != 'F') || (param_3[1] != 'N')) || (param_3[2] != 'T')) ||
     ((param_3[3] != 'F' || (1 < *(ushort *)(param_3 + 4))))) goto LAB_14016c65a;
  piVar11[0x24] = 1;
  iVar2 = FUN_1401b2550(param_3 + 0x18,0);
  iVar7 = *(int *)(param_3 + 0xc) + 0x80018 + *(int *)(param_3 + 0x14) * 8 + iVar2 + param_4;
  iVar8 = iVar7 + 0x2c;
  if (*(short *)(param_3 + 4) != 0) {
    iVar8 = iVar7;
  }
  lVar5 = FUN_1401b6390((longlong)iVar8,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                        0x1b56);
  *(longlong *)(piVar11 + 0x26) = lVar5;
  if (lVar5 == 0) goto LAB_14016c65a;
  lVar6 = lVar5 + param_4;
  *(longlong *)(piVar11 + 0x2a) = lVar6;
  lVar6 = lVar6 + 0x18 + (longlong)iVar2;
  *(longlong *)(piVar11 + 0x32) = lVar6;
  if (*(short *)(param_3 + 4) == 0) {
    *(longlong *)(piVar11 + 0x32) = lVar6 + 0x2c;
  }
  *(longlong *)(piVar11 + 0x34) = *(longlong *)(piVar11 + 0x32) + 0x80000;
  *(ulonglong *)(piVar11 + 0x36) =
       *(longlong *)(piVar11 + 0x32) + 0x80000 + (ulonglong)*(uint *)(param_3 + 0x14) * 8;
  FUN_1401ae2f0(lVar5,param_3,(longlong)param_4);
  piVar11[0x28] = param_4;
  FUN_1401b2550(*(longlong *)(piVar11 + 0x26) + 0x18,*(longlong *)(piVar11 + 0x2a) + 0x18);
  FUN_1401ae2f0(*(undefined8 *)(piVar11 + 0x2a),*(undefined8 *)(piVar11 + 0x26),0x18);
  if (*(short *)(param_3 + 4) == 0) {
    FUN_1401ae320(*(longlong *)(piVar11 + 0x2a) + 0x158,*(longlong *)(piVar11 + 0x2a) + 300,
                  (longlong)iVar2 + -0x114);
    FUN_1401ae370(*(longlong *)(piVar11 + 0x2a) + 300,0,0x2c);
  }
  lVar5 = *(longlong *)(piVar11 + 0x2a);
  piVar11[0x476fe] = 0;
  piVar11[0x476ff] = 0;
  *(longlong *)(piVar11 + 0x2c) = lVar5 + 0x19c;
  if (*(int *)(lVar5 + 300) != 0) {
    *(ulonglong *)(piVar11 + 0x476fe) = (ulonglong)*(uint *)(lVar5 + 0x10) * 0x20 + lVar5 + 0x19c;
  }
  *(ulonglong *)(piVar11 + 0x2e) = (ulonglong)*(uint *)(lVar5 + 8) + *(longlong *)(piVar11 + 0x26);
  cVar1 = *(char *)(lVar5 + 0x158);
  if (cVar1 == '\0') {
    piVar11[0x30] = 0;
    uVar3 = (uint)(0 < iVar4);
LAB_14016c440:
    piVar11[0x48607] = uVar3;
  }
  else {
    if (cVar1 == '\x01') {
      piVar11[0x30] = 4;
      uVar3 = (0 < iVar4) + 0x12;
      goto LAB_14016c440;
    }
    if (cVar1 == '\x02') {
      piVar11[0x30] = 8;
      uVar3 = (0 < iVar4) + 0x22;
      goto LAB_14016c440;
    }
  }
  FUN_1401ae370(*(undefined8 *)(piVar11 + 0x32),0,0x80000);
  puVar9 = *(uint **)(piVar11 + 0x2c);
  piVar10 = piVar12;
  if (*(int *)(*(longlong *)(piVar11 + 0x2a) + 0x10) != 0) {
    do {
      if (*puVar9 < 0x10000) {
        *(uint **)(*(longlong *)(piVar11 + 0x32) + (ulonglong)*puVar9 * 8) = puVar9;
      }
      else {
        *(uint **)((longlong)piVar12 + *(longlong *)(piVar11 + 0x34)) = puVar9;
        piVar12 = piVar12 + 2;
      }
      uVar3 = (int)piVar10 + 1;
      puVar9 = puVar9 + 8;
      piVar10 = (int *)(ulonglong)uVar3;
    } while (uVar3 < *(uint *)(*(longlong *)(piVar11 + 0x2a) + 0x10));
  }
  FUN_1401ae2f0(piVar11 + 0x485f3,*(longlong *)(piVar11 + 0x2a) + 0x118,0x40);
  piVar11[0x48608] = iVar4;
  piVar11[0x48604] = 0;
  piVar11[0x48605] = 0;
  piVar11[0x48606] = 0;
  piVar11[0x48603] = -1;
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  FUN_1401c0470(*(longlong *)(piVar11 + 0x2a) + 0x18,0xffffffff,0x4b0,piVar11 + 0x48573,0x200,
                DAT_1408ab148);
  if (DAT_1408ab144 == 0) {
    FUN_1401c6d60();
  }
  iVar8 = DAT_1408ab144;
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  uVar13 = 0;
  FUN_1401c0470(piVar11 + 0x48573,0xffffffff,DAT_1408ab148,piVar11 + 0x48533,0x100,iVar8);
  piVar11[0x22] = 0;
  piVar11[0x23] = 0;
  if (4 < iVar4) {
    iVar8 = iVar4 * 2 + 1;
    iVar8 = FUN_1401777b0(iVar8,iVar8,piVar11 + 0x4860a,0);
    if (iVar8 < 0) {
      return 0xffffffff;
    }
    FUN_1401ae370(piVar11 + 0x48614,0,0x400);
    *(undefined2 *)((longlong)piVar11 + 0x121855) = 0xffff;
    *(undefined1 *)(piVar11 + 0x48615) = 0xff;
    *(undefined1 *)((longlong)piVar11 + 0x121857) = 0;
    FUN_140179f30(piVar11 + 0x4860a,0,0,0,uVar13 & 0xffffffff00000000);
    FUN_140177d30(piVar11 + 0x4860a,iVar4,iVar4,iVar4,0xff,0xff,0xff,0,1);
  }
  iVar4 = FUN_1401f0fe0(param_1,piVar11,0);
  if ((iVar4 == 0) && (iVar4 = FUN_14016d480(param_1,piVar11,param_6), -1 < iVar4)) {
    return 0;
  }
LAB_14016c65a:
  FUN_1401f0f90(piVar11);
  if (*(longlong *)(piVar11 + 0x26) != 0) {
    FUN_1401b6700();
    piVar11[0x26] = 0;
    piVar11[0x27] = 0;
  }
  return 0xffffffff;
}


