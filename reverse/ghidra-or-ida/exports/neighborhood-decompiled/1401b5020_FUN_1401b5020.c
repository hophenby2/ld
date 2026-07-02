// Function: FUN_1401b5020 @ 1401b5020
// Decompile completed: true

undefined8 FUN_1401b5020(longlong *param_1,longlong param_2,int param_3)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  if (((int)param_1[8] == 1) && (*(int *)((longlong)param_1 + 0x44) != 0)) {
    while( true ) {
      if (((int)param_1[8] == 0) || (iVar4 = *(int *)((longlong)param_1 + 0x44), iVar4 == 0))
      goto LAB_1401b5314;
      if (iVar4 == 1) break;
      if (iVar4 != 2) goto LAB_1401b5314;
      iVar4 = thunk_FUN_1401b8f80(param_1[4]);
      if (iVar4 != 0) {
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[10],param_1[0xb],
                        ((*(longlong *)(param_1[1] + 0x30) - *(longlong *)(param_1[1] + 0x28)) -
                        *(longlong *)(*param_1 + 8)) + param_1[9],(longlong)param_1 + 0x29);
        }
        goto LAB_1401b5311;
      }
LAB_1401b50c5:
      FUN_1401b7120(1);
    }
    iVar4 = thunk_FUN_1401b8f80(param_1[4]);
    if (iVar4 == 0) goto LAB_1401b50c5;
    lVar5 = param_1[1];
    uVar2 = *(ulonglong *)(lVar5 + 0x38);
    lVar3 = *(longlong *)(lVar5 + 0x40);
    if (uVar2 == 0xffffffffffffffff) {
      if (lVar3 != -1) {
        bVar1 = *(byte *)(*param_1 + 0x30);
        if (bVar1 != 0xff) {
          uVar2 = *(ulonglong *)(lVar5 + 0x30);
          if ((ulonglong)bVar1 * 0x800 < uVar2) {
            if ((char)param_1[5] == '\0') {
              FUN_1401b3000(param_1[3],lVar3 + (ulonglong)bVar1 * -0x800 + uVar2,uVar2,
                            (longlong)param_1 + 0x29);
            }
            FUN_1401b5b00(param_1[3],param_1[2]);
            FUN_1401ae2f0(*(longlong *)(param_1[1] + 0x30) +
                          (ulonglong)*(byte *)(*param_1 + 0x30) * -0x400 + param_1[2],
                          (ulonglong)*(byte *)(*param_1 + 0x30) * 0x400 + param_1[2]);
            FUN_1401ae2f0((ulonglong)*(byte *)(*param_1 + 0x30) * 0x400 + param_1[2],
                          *(longlong *)(param_1[1] + 0x40) + param_1[3],
                          *(longlong *)(param_1[1] + 0x30) +
                          (ulonglong)*(byte *)(*param_1 + 0x30) * -0x800);
            goto LAB_1401b5304;
          }
        }
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[3],lVar3,*(undefined8 *)(lVar5 + 0x30),(longlong)param_1 + 0x29);
        }
        FUN_1401b5b00(param_1[3],param_1[2]);
      }
    }
    else if (lVar3 == -1) {
      if ((char)param_1[5] == '\0') {
        FUN_1401b3000(param_1[3],uVar2,*(undefined8 *)(lVar5 + 0x30),(longlong)param_1 + 0x29);
      }
      FUN_1401b2550(param_1[3],param_1[2]);
    }
    else {
      bVar1 = *(byte *)(*param_1 + 0x30);
      if (bVar1 != 0xff) {
        uVar6 = (ulonglong)bVar1 * 0x800;
        if (uVar6 < uVar2) {
          if ((char)param_1[5] == '\0') {
            FUN_1401b3000(uVar6 + param_1[3],lVar3 + (ulonglong)bVar1 * -0x800 + uVar2,
                          *(undefined8 *)(lVar5 + 0x30),(longlong)param_1 + 0x29);
          }
          FUN_1401b5b00((ulonglong)*(byte *)(*param_1 + 0x30) * 0x800 + param_1[3]);
          FUN_1401ae2f0(*(longlong *)(param_1[1] + 0x40) + *(longlong *)(param_1[1] + 0x38) +
                        param_1[3],(ulonglong)*(byte *)(*param_1 + 0x30) * 0x400 + param_1[3]);
          FUN_1401ae2f0(*(longlong *)(param_1[1] + 0x40) +
                        (ulonglong)*(byte *)(*param_1 + 0x30) * 0x800 +
                        (ulonglong)*(byte *)(*param_1 + 0x30) * -0x400 + param_1[3],param_1[3]);
          FUN_1401b2550(*(longlong *)(param_1[1] + 0x40) +
                        (ulonglong)*(byte *)(*param_1 + 0x30) * 0x400 + param_1[3],param_1[2]);
          goto LAB_1401b5304;
        }
      }
      if ((char)param_1[5] == '\0') {
        FUN_1401b3000(param_1[3],lVar3,*(undefined8 *)(lVar5 + 0x30),(longlong)param_1 + 0x29);
      }
      FUN_1401b5b00(param_1[3],*(longlong *)(param_1[1] + 0x40) + param_1[3]);
      FUN_1401b2550(*(longlong *)(param_1[1] + 0x40) + param_1[3],param_1[2]);
    }
LAB_1401b5304:
    FUN_1401b6700(param_1[3]);
    param_1[3] = 0;
LAB_1401b5311:
    *(undefined4 *)((longlong)param_1 + 0x44) = 0;
  }
LAB_1401b5314:
  lVar5 = *(longlong *)(param_1[1] + 0x30);
  if (param_3 == 1) {
    param_2 = param_2 + param_1[7];
  }
  else if (param_3 == 2) {
    param_2 = param_2 + lVar5;
  }
  *(undefined4 *)(param_1 + 6) = 0;
  if (lVar5 < param_2) {
    param_2 = lVar5;
  }
  lVar5 = 0;
  if (-1 < param_2) {
    lVar5 = param_2;
  }
  param_1[7] = lVar5;
  return 0;
}


