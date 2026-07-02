// Function: FUN_1401b04e0 @ 1401b04e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_1401b04e0(longlong param_1,longlong param_2,char param_3,longlong param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_4a8 [32];
  undefined8 local_488;
  undefined4 local_480;
  char local_478;
  longlong local_470;
  int local_468 [2];
  longlong local_460;
  longlong local_458;
  int local_450;
  undefined1 local_44c [4];
  undefined1 local_448 [1024];
  undefined2 local_48;
  ushort local_46;
  undefined1 local_38 [16];
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_4a8;
  local_478 = param_3;
  local_470 = param_4;
  local_460 = param_2;
  if (*(int *)(param_1 + 0x8f0) == 1) {
    iVar1 = FUN_1401b08d0();
    while (iVar1 == 0) {
      FUN_1401b7120(0);
      iVar1 = FUN_1401b08d0();
    }
  }
  iVar1 = FUN_1401ba2a0(*(undefined4 *)(param_1 + 0x40),param_2,&DAT_14056d880);
  if (iVar1 != 0) {
    iVar1 = FUN_1401ba2a0(*(undefined4 *)(param_1 + 0x40),param_2,&DAT_14056d888);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_1401ba2a0(*(undefined4 *)(param_1 + 0x40),param_2,&DAT_14056d88c), iVar1 == 0))
    {
      *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_1 + 0x68);
      return 0;
    }
    iVar1 = FUN_1401ba2a0(*(undefined4 *)(param_1 + 0x40),param_2,&DAT_14056d884);
    local_458 = *(longlong *)(param_1 + 0x78);
    if (iVar1 != 0) {
      lVar4 = FUN_1401b9ff0(*(undefined4 *)(param_1 + 0x40),param_2,0x5c);
      if ((lVar4 == 0) &&
         (lVar4 = FUN_1401b9ff0(*(undefined4 *)(param_1 + 0x40),param_2,0x2f), lVar4 == 0)) {
        FUN_1401b0a70(param_1,local_448,param_2,0);
        iVar1 = FUN_1401b07d0(param_1,local_448);
        if (iVar1 < 0) {
LAB_1401b0782:
          if (param_4 != 0) {
            FUN_1401ae2f0(param_4,local_448,(ulonglong)local_46 << 2);
            *(undefined2 *)(param_4 + 0x400) = local_48;
            *(ushort *)(param_4 + 0x402) = local_46;
          }
          return 0xffffffff;
        }
      }
      else {
        iVar1 = 0;
        while( true ) {
          FUN_1401b0a70(param_1,local_448,iVar1 + param_2,local_468);
          iVar3 = local_468[0];
          iVar1 = iVar1 + local_468[0];
          iVar2 = FUN_1401c4e50(iVar1 + param_2,*(undefined4 *)(param_1 + 0x40),&local_450);
          if ((iVar3 == 0) && ((iVar2 == 0x5c || (iVar2 == 0x2f)))) {
            local_480 = *(undefined4 *)(param_1 + 0x40);
            local_488 = 0x10;
            FUN_1401c0470(&DAT_14056d888,0xffffffff,0x7ffd,local_38);
            FUN_1401b04e0(param_1,local_38,0,0);
          }
          else {
            iVar3 = FUN_1401b07d0(param_1,local_448);
            if (iVar3 < 0) {
              param_4 = local_470;
              if (local_478 == '\x01') {
                *(longlong *)(param_1 + 0x78) = local_458;
              }
              goto LAB_1401b0782;
            }
          }
          param_4 = local_470;
          if ((iVar2 == 0) ||
             (((iVar3 = FUN_1401c4e50((local_450 + iVar1) + local_460,
                                      *(undefined4 *)(param_1 + 0x40),local_44c), iVar2 == 0x5c ||
               (iVar2 == 0x2f)) && (param_4 = local_470, iVar3 == 0)))) break;
          iVar1 = iVar1 + local_450;
          param_2 = local_460;
        }
      }
      if (param_4 != 0) {
        FUN_1401ae2f0(param_4,local_448,(ulonglong)local_46 << 2);
        *(undefined2 *)(param_4 + 0x400) = local_48;
        *(ushort *)(param_4 + 0x402) = local_46;
      }
      return 0;
    }
    if (*(longlong *)(local_458 + 8) == -1) {
      return 0xffffffff;
    }
    *(longlong *)(param_1 + 0x78) = *(longlong *)(local_458 + 8) + *(longlong *)(param_1 + 0x68);
  }
  return 0;
}


