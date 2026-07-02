// Function: FUN_1401b5360 @ 1401b5360
// Decompile completed: true

longlong FUN_1401b5360(longlong *param_1)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  
  if (((int)param_1[8] != 1) || (*(int *)((longlong)param_1 + 0x44) == 0)) {
    return param_1[7];
  }
  do {
    if (((int)param_1[8] == 0) || (iVar5 = *(int *)((longlong)param_1 + 0x44), iVar5 == 0))
    goto LAB_1401b53d7;
    if (iVar5 == 1) {
      iVar5 = thunk_FUN_1401b8f80(param_1[4]);
      if (iVar5 != 0) {
        lVar2 = param_1[1];
        uVar3 = *(ulonglong *)(lVar2 + 0x38);
        lVar4 = *(longlong *)(lVar2 + 0x40);
        if (uVar3 == 0xffffffffffffffff) {
          if (lVar4 != -1) {
            bVar1 = *(byte *)(*param_1 + 0x30);
            if (bVar1 != 0xff) {
              uVar3 = *(ulonglong *)(lVar2 + 0x30);
              if ((ulonglong)bVar1 * 0x800 < uVar3) {
                if ((char)param_1[5] == '\0') {
                  FUN_1401b3000(param_1[3],lVar4 + (ulonglong)bVar1 * -0x800 + uVar3,uVar3,
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
                goto LAB_1401b5629;
              }
            }
            if ((char)param_1[5] == '\0') {
              FUN_1401b3000(param_1[3],lVar4,*(undefined8 *)(lVar2 + 0x30),(longlong)param_1 + 0x29)
              ;
            }
            FUN_1401b5b00(param_1[3],param_1[2]);
          }
        }
        else if (lVar4 == -1) {
          if ((char)param_1[5] == '\0') {
            FUN_1401b3000(param_1[3],uVar3,*(undefined8 *)(lVar2 + 0x30),(longlong)param_1 + 0x29);
          }
          FUN_1401b2550(param_1[3],param_1[2]);
        }
        else {
          bVar1 = *(byte *)(*param_1 + 0x30);
          if (bVar1 != 0xff) {
            uVar6 = (ulonglong)bVar1 * 0x800;
            if (uVar6 < uVar3) {
              if ((char)param_1[5] == '\0') {
                FUN_1401b3000(uVar6 + param_1[3],lVar4 + (ulonglong)bVar1 * -0x800 + uVar3,
                              *(undefined8 *)(lVar2 + 0x30),(longlong)param_1 + 0x29);
              }
              FUN_1401b5b00((ulonglong)*(byte *)(*param_1 + 0x30) * 0x800 + param_1[3]);
              FUN_1401ae2f0(*(longlong *)(param_1[1] + 0x40) + *(longlong *)(param_1[1] + 0x38) +
                            param_1[3],param_1[3] + (ulonglong)*(byte *)(*param_1 + 0x30) * 0x400);
              FUN_1401ae2f0(*(longlong *)(param_1[1] + 0x40) +
                            (ulonglong)*(byte *)(*param_1 + 0x30) * 0x800 +
                            (ulonglong)*(byte *)(*param_1 + 0x30) * -0x400 + param_1[3],param_1[3]);
              FUN_1401b2550(*(longlong *)(param_1[1] + 0x40) +
                            (ulonglong)*(byte *)(*param_1 + 0x30) * 0x400 + param_1[3],param_1[2]);
              goto LAB_1401b5629;
            }
          }
          if ((char)param_1[5] == '\0') {
            FUN_1401b3000(param_1[3],lVar4,*(undefined8 *)(lVar2 + 0x30),(longlong)param_1 + 0x29);
          }
          FUN_1401b5b00(param_1[3],*(longlong *)(param_1[1] + 0x40) + param_1[3]);
          FUN_1401b2550(*(longlong *)(param_1[1] + 0x40) + param_1[3],param_1[2]);
        }
LAB_1401b5629:
        FUN_1401b6700(param_1[3]);
        param_1[3] = 0;
        *(undefined4 *)((longlong)param_1 + 0x44) = 0;
        return param_1[7];
      }
    }
    else {
      if (iVar5 != 2) goto LAB_1401b53d7;
      iVar5 = thunk_FUN_1401b8f80(param_1[4]);
      if (iVar5 != 0) {
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[10],param_1[0xb],
                        ((*(longlong *)(param_1[1] + 0x30) - *(longlong *)(param_1[1] + 0x28)) -
                        *(longlong *)(*param_1 + 8)) + param_1[9],(longlong)param_1 + 0x29);
        }
        *(undefined4 *)((longlong)param_1 + 0x44) = 0;
LAB_1401b53d7:
        return param_1[7];
      }
    }
    FUN_1401b7120(1);
  } while( true );
}


