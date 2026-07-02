// Function: dxlib_load_graph_impl_candidate @ 140155560
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
dxlib_load_graph_impl_candidate
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_478 [32];
  longlong local_458;
  int local_450;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined1 local_438 [1024];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_478;
  puVar8 = (undefined1 *)0x0;
  puVar7 = puVar8;
  local_448 = param_4;
  local_444 = param_3;
  local_440 = param_2;
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
        puVar7 = local_438;
      }
      else {
        puVar7 = (undefined1 *)
                 FUN_1401b6390(uVar1 * 2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp"
                               ,0xce2);
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
      local_458 = uVar1 * 2;
      local_450 = iVar2;
      FUN_1401c0470(param_1,uVar6 & 0xffffffff,iVar3,puVar7);
      thunk_FUN_1401c4e80(iVar4);
    }
  }
  uVar5 = FUN_140155710(puVar7,local_440,local_444,local_448);
  if (puVar8 != (undefined1 *)0x0) {
    FUN_1401b6700(puVar8);
  }
  return uVar5;
}


