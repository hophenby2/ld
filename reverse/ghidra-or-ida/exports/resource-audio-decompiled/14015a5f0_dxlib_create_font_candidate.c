// Function: dxlib_create_font_candidate @ 14015a5f0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
dxlib_create_font_candidate
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_498 [32];
  longlong local_478;
  int local_470;
  undefined4 local_468;
  undefined4 local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined1 local_448 [1024];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_498;
  puVar7 = (undefined1 *)0x0;
  puVar8 = puVar7;
  local_458 = param_4;
  local_454 = param_3;
  local_450 = param_2;
  if (param_1 != (undefined1 *)0x0) {
    if (DAT_1408ab144 == 0) {
      FUN_1401c6d60();
    }
    iVar2 = DAT_1408ab144;
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    puVar8 = param_1;
    if (iVar2 != DAT_1408ab148) {
      if (DAT_1408ab144 == 0) {
        FUN_1401c6d60();
      }
      uVar6 = FUN_1401ba9b0(DAT_1408ab144,param_1);
      uVar1 = uVar6 + 0x10;
      if (uVar1 < 0x201) {
        puVar8 = local_448;
      }
      else {
        puVar7 = (undefined1 *)
                 FUN_1401b6390(uVar1 * 2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                               0x1d35);
        puVar8 = puVar7;
        if (puVar7 == (undefined1 *)0x0) {
          return 0xffffffff;
        }
      }
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar2 = DAT_1408ab148;
      if (DAT_1408ab144 == 0) {
        FUN_1401c6d60();
      }
      iVar3 = DAT_1408ab144;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = DAT_1408ab148;
      local_478 = uVar1 * 2;
      local_470 = iVar2;
      FUN_1401c0470(param_1,uVar6 & 0xffffffff,iVar3,puVar8);
      thunk_FUN_1401c4e80(iVar4);
    }
  }
  local_460 = param_8;
  local_468 = param_7;
  local_470 = param_6;
  local_478 = CONCAT44(local_478._4_4_,param_5);
  uVar5 = FUN_14015af50(puVar8,local_450,local_454,local_458);
  if (puVar7 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar7);
  }
  return uVar5;
}


