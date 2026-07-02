// Function: FUN_1401b4e70 @ 1401b4e70
// Decompile completed: true

ulonglong FUN_1401b4e70(longlong *param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  if (((int)param_1[8] == 1) && (*(int *)((longlong)param_1 + 0x44) != 0)) {
    iVar3 = FUN_1401b4200();
    while (iVar3 == 0) {
      FUN_1401b7120(1);
      iVar3 = FUN_1401b4200(param_1);
    }
  }
  lVar4 = *param_1;
  lVar1 = *(longlong *)(param_1[1] + 0x30);
  lVar5 = *(longlong *)(param_1[1] + 0x28);
  if ((int)param_1[6] != 1) {
    lVar2 = param_1[7];
    if (lVar1 != lVar2) {
      uVar6 = lVar1 - lVar2;
      if (param_3 < (ulonglong)(lVar1 - lVar2)) {
        uVar6 = param_3;
      }
      if (param_1[2] == 0) {
        if (*(int *)(lVar4 + 0x8d0) == 1) {
          FUN_1401ae2f0(param_2,*(longlong *)(lVar4 + 0x50) + lVar2 + *(longlong *)(lVar4 + 8) +
                                lVar5,uVar6);
          if ((*(int *)(*param_1 + 0x8e4) != 0) && ((char)param_1[5] == '\0')) {
            FUN_1401b3000(param_2,uVar6,param_1[7] + lVar1,(longlong)param_1 + 0x29);
          }
        }
        else {
          lVar5 = lVar2 + *(longlong *)(lVar4 + 8) + lVar5;
          param_1[9] = lVar5;
          lVar4 = FUN_140139990(param_1[4]);
          if (lVar4 != lVar5) {
            FUN_140139920(param_1[4],lVar5,0);
          }
          if ((int)param_1[8] == 0) {
            lVar4 = 0;
            if ((char)param_1[5] == '\0') {
              lVar4 = (longlong)param_1 + 0x29;
            }
            FUN_1401b31d0(param_2,uVar6,param_1[4],lVar4,param_1[7] + lVar1);
          }
          else {
            FUN_1401398a0(param_2,uVar6,1,param_1[4]);
            param_1[0xb] = (longlong)(int)uVar6;
            param_1[10] = param_2;
            *(undefined4 *)((longlong)param_1 + 0x44) = 2;
          }
        }
      }
      else {
        FUN_1401ae2f0(param_2,param_1[2] + lVar2,uVar6);
      }
      param_1[7] = param_1[7] + (longlong)(int)uVar6;
      *(undefined4 *)(param_1 + 6) = 0;
      return uVar6 & 0xffffffff;
    }
    *(undefined4 *)(param_1 + 6) = 1;
  }
  return 0;
}


