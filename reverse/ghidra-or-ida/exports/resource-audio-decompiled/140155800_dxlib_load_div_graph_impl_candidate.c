// Function: dxlib_load_div_graph_impl_candidate @ 140155800
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
dxlib_load_div_graph_impl_candidate
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
          int param_6,undefined8 param_7,undefined4 param_8,undefined4 param_9,int param_10,
          int param_11)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_4e8 [32];
  ulonglong local_4c8;
  int local_4c0;
  float local_4b8;
  int local_4b0;
  float local_4a8;
  undefined8 local_4a0;
  undefined4 local_498;
  undefined4 local_490;
  int local_488;
  float local_480;
  int local_478;
  float local_470;
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  undefined8 local_458;
  undefined1 local_448 [1024];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_4e8;
  puVar7 = (undefined1 *)0x0;
  local_458 = param_7;
  puVar8 = (undefined1 *)0x0;
  local_468 = param_4;
  local_464 = param_3;
  local_460 = param_2;
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
                 FUN_1401b6390(uVar1 * 2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp"
                               ,0xd5e);
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
      local_4c8 = uVar1 * 2;
      local_4c0 = iVar2;
      FUN_1401c0470(param_1,uVar6 & 0xffffffff,iVar3,puVar8);
      thunk_FUN_1401c4e80(iVar4);
    }
  }
  local_470 = (float)param_11;
  local_480 = (float)param_10;
  local_478 = param_11;
  local_488 = param_10;
  local_490 = param_9;
  local_498 = param_8;
  local_4a0 = local_458;
  local_4a8 = (float)param_6;
  local_4b0 = param_6;
  local_4b8 = (float)param_5;
  local_4c0 = param_5;
  local_4c8 = local_4c8 & 0xffffffff00000000;
  uVar5 = FUN_140155a60(puVar8,local_460,local_464,local_468);
  if (puVar7 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar7);
  }
  return uVar5;
}


