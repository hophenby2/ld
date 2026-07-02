// Function: FUN_140212310 @ 140212310
// Decompile completed: true

undefined8 FUN_140212310(longlong *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  if ((int)param_1[1] == iVar1) {
    *(undefined4 *)(param_1 + 1) = 0;
  }
  if (*(int *)((longlong)param_1 + 0xc) == iVar1) {
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  }
  if (iVar1 < (int)param_1[2] + param_2) {
    lVar3 = *param_1;
    iVar5 = param_2 + 1000 + ((int)param_1[2] * 3) / 2;
    *(int *)((longlong)param_1 + 0x14) = iVar5;
    lVar4 = FUN_1401b6390((longlong)iVar5,
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxRingBuffer.cpp",0xa5);
    *param_1 = lVar4;
    if (lVar4 == 0) {
      FUN_1401b6700(lVar3);
      FUN_1401ae370(param_1,0,0x18);
      FUN_140159b70(&DAT_1404b38d0,*(undefined4 *)((longlong)param_1 + 0x14));
      return 0xffffffff;
    }
    iVar5 = (int)param_1[2];
    if (iVar5 != 0) {
      iVar2 = (int)param_1[1];
      if (iVar1 < iVar5 + iVar2) {
        FUN_1401ae2f0(lVar4,iVar2 + lVar3,(longlong)(iVar1 - iVar2));
        iVar5 = ((int)param_1[2] - iVar1) + (int)param_1[1];
        lVar4 = (longlong)(iVar1 - (int)param_1[1]) + *param_1;
        lVar6 = lVar3;
      }
      else {
        lVar6 = iVar2 + lVar3;
      }
      FUN_1401ae2f0(lVar4,lVar6,(longlong)iVar5);
    }
    *(int *)((longlong)param_1 + 0xc) = (int)param_1[2];
    *(undefined4 *)(param_1 + 1) = 0;
    FUN_1401b6700(lVar3);
  }
  return 0;
}


