// Function: FUN_14021a800 @ 14021a800
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_14021a800(int *param_1,int param_2,longlong param_3,ulonglong param_4,longlong param_5,
                   int param_6)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  ulonglong uVar9;
  int *piVar10;
  int *piVar11;
  char *pcVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar15;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar11 = param_1;
  if (param_2 == 0) {
    piVar11 = (int *)((longlong)param_1 - (ulonglong)(uint)param_1[-1]);
  }
  if (*piVar11 != 0x4d454d44) {
    FUN_140159b70(&DAT_1404b59a0);
    _DAT_00000000 = 0xffffffff;
  }
  lVar2 = *(longlong *)(piVar11 + 0x18);
  FUN_1401b6dc0(lVar2 + 0xd0,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x821);
  if (param_3 == 0) {
    FUN_1401b6e70(lVar2 + 0xd0);
    return (int *)0x0;
  }
  if (param_4 == 0) {
    param_4 = *(ulonglong *)(lVar2 + 0x40);
  }
  else if (param_4 < 0x10) {
    param_4 = 0x10;
  }
  uVar14 = param_3 + -1 + param_4;
  uVar14 = uVar14 - uVar14 % param_4;
  if (*(longlong *)(piVar11 + 0xe) == param_3) {
    *piVar11 = 0x4d454d44;
    *(byte *)((longlong)piVar11 + 0x16) = *(byte *)((longlong)piVar11 + 0x16) & 0xdf | 4;
    if (param_5 == 0) {
      pcVar12 = "NoName";
    }
    else {
      iVar5 = FUN_1401ba9b0(0x7ffd,param_5);
      iVar7 = 0;
      if (0x10 < iVar5) {
        iVar7 = iVar5 + -0x11;
      }
      pcVar12 = (char *)(iVar7 + param_5);
    }
    FUN_1401ba3d0(0x7ffd,piVar11 + 1,pcVar12);
    *(longlong *)(piVar11 + 0x18) = lVar2;
    if (param_6 < 0) {
      param_6 = 0;
    }
    *(byte *)((longlong)piVar11 + 0x16) = *(byte *)((longlong)piVar11 + 0x16) & 0xfc;
    *(short *)((longlong)piVar11 + 0x1e) = (short)param_6;
    *(byte *)((longlong)piVar11 + 0x16) =
         *(byte *)((longlong)piVar11 + 0x16) | (byte)((uint)param_6 >> 0x10);
    *(undefined1 *)((longlong)piVar11 + 0x19) = *(undefined1 *)(lVar2 + 0x4a);
    *(undefined2 *)((longlong)piVar11 + 0x1a) = *(undefined2 *)(lVar2 + 0x48);
    *(int *)(lVar2 + 0x48) = *(int *)(lVar2 + 0x48) + 1;
    uVar6 = *(uint *)(lVar2 + 0x48);
    if (0xffffff < uVar6) {
      uVar6 = 0;
    }
    *(uint *)(lVar2 + 0x48) = uVar6;
    *(undefined2 *)(piVar11 + 7) = *(undefined2 *)(lVar2 + 0x4c);
    FUN_1401b6e70(lVar2 + 0xd0);
    return param_1;
  }
  if ((*(int *)(lVar2 + 0x50) == 0) && (iVar7 = FUN_140218150(piVar11), iVar7 < 0)) {
    FUN_140159b70(&DAT_1404b5a40);
    FUN_14021a5d0(param_1);
    _DAT_00000000 = 0xffffffff;
  }
  if ((*(byte *)((longlong)piVar11 + 0x16) & 4) == 0) {
    FUN_140159b70(&DAT_1404b5ad0);
    FUN_14021a5d0(param_1);
    _DAT_00000000 = 0xffffffff;
  }
  lVar13 = *(longlong *)(piVar11 + 0xc);
  plVar1 = (longlong *)(piVar11 + 8);
  lVar3 = *plVar1;
  if (*(int *)(lVar2 + 0x50) == 0) {
    uVar9 = (longlong)piVar11 + (lVar3 - lVar13) + -0x10;
  }
  else {
    uVar9 = (*(longlong *)(piVar11 + 10) - lVar13) + lVar3;
  }
  if (uVar9 - uVar9 % param_4 < uVar14) {
    lVar4 = *(longlong *)(piVar11 + 0x12);
    if (((lVar4 != 0) && ((*(byte *)((longlong)piVar11 + 0x16) & 8) != 0)) &&
       ((*(byte *)(lVar4 + 0x16) & 4) == 0)) {
      if (*(int *)(lVar2 + 0x50) == 0) {
        uVar9 = (longlong)piVar11 + (*(longlong *)(lVar4 + 0x20) - lVar13) + lVar3 + -0x10;
      }
      else {
        uVar9 = ((*(longlong *)(lVar4 + 0x20) + *(longlong *)(piVar11 + 10)) - lVar13) + lVar3;
      }
      if (uVar14 <= uVar9 - uVar9 % param_4) goto LAB_14021ab24;
    }
    piVar8 = (int *)FUN_1402181f0(lVar2,param_3,param_4,0,param_5,CONCAT44(uVar15,param_6),0);
    if (piVar8 == (int *)0x0) {
      FUN_1401b6e70(lVar2 + 0xd0);
      return (int *)0x0;
    }
    if (*(int *)(lVar2 + 0x50) == 0) {
      lVar13 = (longlong)piVar11 + ((*plVar1 + -0x10) - lVar13);
      piVar10 = piVar8;
    }
    else {
      lVar13 = (*(longlong *)(piVar11 + 10) - lVar13) + *plVar1;
      piVar10 = *(int **)(piVar8 + 10);
    }
    FUN_1401ae2f0(piVar10,*(longlong *)(piVar11 + 0xc),lVar13);
    FUN_1402187b0(param_1,*(undefined4 *)(lVar2 + 0x50));
    param_1 = piVar8;
  }
  else {
LAB_14021ab24:
    FUN_140219fd0(lVar2,piVar11,1);
    FUN_140219850(lVar2,piVar11,lVar13,param_3,uVar14,param_4,0,param_5,param_6,0);
  }
  FUN_1401b6e70(lVar2 + 0xd0);
  return param_1;
}


