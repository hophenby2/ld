// Function: dxlib_load_sound_candidate @ 1401885b0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 dxlib_load_sound_candidate(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_488 [32];
  longlong local_468;
  int local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined1 local_448 [1024];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_488;
  puVar8 = (undefined1 *)0x0;
  puVar7 = puVar8;
  local_458 = param_3;
  local_454 = param_2;
  if (param_1 != (undefined1 *)0x0) {
    if (DAT_1408ab144 == 0) {
      FUN_1401c6d60();
    }
    iVar2 = DAT_1408ab144;
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    puVar7 = param_1;
    if (iVar2 != DAT_1408ab148) {
      if (DAT_1408ab144 == 0) {
        FUN_1401c6d60();
      }
      uVar6 = FUN_1401ba9b0(DAT_1408ab144,param_1);
      uVar1 = uVar6 + 0x10;
      if (uVar1 < 0x201) {
        puVar7 = local_448;
      }
      else {
        puVar7 = (undefined1 *)
                 FUN_1401b6390(uVar1 * 2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",
                               0x1187);
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
      local_468 = uVar1 * 2;
      local_460 = iVar2;
      FUN_1401c0470(param_1,uVar6 & 0xffffffff,iVar3,puVar7);
      thunk_FUN_1401c4e80(iVar4);
    }
  }
  uVar5 = FUN_140188df0(puVar7,local_454,local_458);
  if (puVar8 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar8);
  }
  return uVar5;
}


