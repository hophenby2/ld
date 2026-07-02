// Function: dxarchive_keyconv_file_read_candidate @ 1401b31d0
// Decompile completed: true

void dxarchive_keyconv_file_read_candidate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               longlong param_5)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if ((param_4 != 0) && (lVar2 = param_5, param_5 == -1)) {
    lVar2 = FUN_140139990(param_3);
  }
  FUN_1401398a0(param_1,param_2,1,param_3);
  iVar1 = thunk_FUN_1401b8f80(param_3);
  while (iVar1 == 0) {
    FUN_1401b7120(1);
    iVar1 = thunk_FUN_1401b8f80(param_3);
  }
  if (param_4 != 0) {
    dxarchive_xor_keyconv_candidate(param_1,param_2,lVar2,param_4);
  }
  return;
}


