// Function: FUN_140187c70 @ 140187c70
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140187c70(longlong param_1,uint param_2,longlong param_3,undefined8 param_4,undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStack_5a8 [32];
  undefined4 local_588;
  uint local_580;
  ulonglong local_578;
  longlong local_568;
  ulonglong local_560;
  short local_558;
  undefined2 local_556;
  undefined4 local_554;
  ushort local_54c;
  undefined2 local_54a;
  undefined8 local_540;
  undefined8 uStack_538;
  undefined4 local_530;
  undefined4 uStack_52c;
  undefined4 uStack_528;
  undefined4 uStack_524;
  undefined4 local_520;
  undefined4 uStack_51c;
  undefined4 uStack_518;
  undefined4 uStack_514;
  longlong local_510;
  undefined1 local_508 [1216];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_5a8;
  local_568 = 0;
  iVar2 = FUN_14019e300();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_140988920 != 0) && (-1 < (int)param_2)) && ((param_2 & 0x7c000000) == DAT_140988970))
     && ((((int)(param_2 & 0x3ffff) < DAT_140988978 &&
          (piVar1 = *(int **)(DAT_140988928 + (ulonglong)(param_2 & 0x3ffff) * 8),
          piVar1 != (int *)0x0)) && (*piVar1 << 0x12 == (param_2 & 0x3fc0000))))) {
    if (param_3 == 0) {
      local_510 = FUN_140139630(param_4,param_5);
      puVar3 = (undefined8 *)FUN_1401394d0();
    }
    else {
      local_510 = thunk_FUN_1401b1540(param_3,0,1);
      if (local_510 == 0) {
        return 0xffffffff;
      }
      puVar3 = (undefined8 *)FUN_1401394c0();
    }
    local_540 = *puVar3;
    uStack_538 = puVar3[1];
    local_530 = *(undefined4 *)(puVar3 + 2);
    uStack_52c = *(undefined4 *)((longlong)puVar3 + 0x14);
    uStack_528 = *(undefined4 *)(puVar3 + 3);
    uStack_524 = *(undefined4 *)((longlong)puVar3 + 0x1c);
    local_520 = *(undefined4 *)(puVar3 + 4);
    uStack_51c = *(undefined4 *)((longlong)puVar3 + 0x24);
    uStack_518 = *(undefined4 *)(puVar3 + 5);
    uStack_514 = *(undefined4 *)((longlong)puVar3 + 0x2c);
    FUN_1401ae370(local_508,0,0x4b8);
    local_588 = *(undefined4 *)(param_1 + 0x4c);
    iVar2 = FUN_140212920(local_508,&local_540,*(undefined4 *)(param_1 + 0x44),
                          *(undefined4 *)(param_1 + 0x48));
    if (iVar2 < 0) {
      FUN_140159b70(&DAT_1404a92c8);
    }
    else {
      iVar2 = FUN_140213010(local_508,&local_558,&local_568,&local_560);
      if (iVar2 < 0) {
        FUN_140159b70(&DAT_1404a9310);
      }
      else {
        FUN_140213140(local_508);
        if (param_3 == 0) {
          FUN_1401359b0(local_510);
        }
        else {
          thunk_FUN_1401b0f70();
        }
        local_578 = local_560 / local_54c;
        local_510 = 0;
        local_580 = (uint)(local_558 == 3);
        local_588 = local_554;
        iVar2 = FUN_14018d200(param_2,0,local_556,local_54a);
        if (-1 < iVar2) {
          FUN_1401ae2f0(*(undefined8 *)(piVar1 + 0x28),local_568,local_560);
          if (local_568 != 0) {
            FUN_1401b6700();
          }
          return 0;
        }
      }
    }
    if (local_510 != 0) {
      if (param_3 == 0) {
        FUN_1401359b0();
      }
      else {
        thunk_FUN_1401b0f70();
      }
    }
    FUN_140213140(local_508);
    if (local_568 != 0) {
      FUN_1401b6700();
    }
  }
  return 0xffffffff;
}


