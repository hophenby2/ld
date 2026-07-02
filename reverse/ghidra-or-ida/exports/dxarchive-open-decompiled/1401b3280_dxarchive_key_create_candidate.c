// Function: dxarchive_key_create_candidate @ 1401b3280
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dxarchive_key_create_candidate(undefined1 *param_1,ulonglong param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStack_858 [32];
  undefined1 local_838 [1024];
  undefined1 local_438 [1024];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_858;
  if (param_2 == 0) {
    param_2 = FUN_1401ba9b0(0x7ffd,param_1);
  }
  if (param_2 < 4) {
    FUN_1401ba3d0(0x7ffd,local_838,param_1);
    FUN_1401ba3d0(0x7ffd,local_838 + param_2,s_DXBDXARC_14056d890);
    param_1 = local_838;
    param_2 = FUN_1401ba9b0(0x7ffd,local_838);
  }
  if (param_2 >> 1 < 0x401) {
    puVar4 = local_438;
  }
  else {
    puVar4 = (undefined1 *)
             FUN_1401b6390(param_2 >> 1,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                           0x1c1);
  }
  uVar6 = 0;
  uVar5 = uVar6;
  uVar8 = uVar6;
  if (param_2 != 0) {
    do {
      uVar7 = (ulonglong)((int)uVar8 + 2);
      puVar4[uVar5] = param_1[uVar8];
      uVar5 = (ulonglong)((int)uVar5 + 1);
      uVar8 = uVar7;
    } while (uVar7 < param_2);
  }
  uVar2 = FUN_1401b59c0(puVar4);
  uVar8 = 1;
  uVar5 = uVar6;
  if (1 < param_2) {
    do {
      puVar1 = param_1 + uVar8;
      uVar8 = (ulonglong)((int)uVar8 + 2);
      uVar6 = (ulonglong)((int)uVar5 + 1);
      puVar4[uVar5] = *puVar1;
      uVar5 = uVar6;
    } while (uVar8 < param_2);
  }
  uVar3 = FUN_1401b59c0(puVar4,uVar6);
  *param_3 = (char)uVar2;
  param_3[1] = (char)((uint)uVar2 >> 8);
  param_3[2] = (char)((uint)uVar2 >> 0x10);
  param_3[4] = (char)uVar3;
  param_3[3] = (char)((uint)uVar2 >> 0x18);
  param_3[5] = (char)((uint)uVar3 >> 8);
  param_3[6] = (char)((uint)uVar3 >> 0x10);
  if (0x400 < param_2) {
    FUN_1401b6700(puVar4);
  }
  return;
}


