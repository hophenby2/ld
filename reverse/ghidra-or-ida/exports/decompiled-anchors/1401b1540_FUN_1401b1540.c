// Function: FUN_1401b1540 @ 1401b1540
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_1401b1540(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_668 [32];
  undefined1 local_648 [1536];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_668;
  if (DAT_14092dd40 == 0) {
    FUN_1401b1420();
  }
  FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xf3a);
  if (DAT_140976050 == 0x8000) {
    FUN_1401b6e70(&DAT_14092dd48);
    FUN_1401594b0(&DAT_1404acd50);
    return 0;
  }
  uVar5 = 0;
  if (DAT_140935f80 != 0) {
    plVar2 = &DAT_140935f80;
    uVar5 = 0;
    do {
      uVar5 = uVar5 + 1;
      plVar2 = plVar2 + 1;
    } while (*plVar2 != 0);
  }
  puVar3 = (undefined4 *)
           FUN_1401b6390(0x78,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xf4c);
  (&DAT_140935f80)[(int)uVar5] = (longlong)puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    FUN_1401b6e70(&DAT_14092dd48);
    FUN_1401594b0(&DAT_1404acd80);
    return 0;
  }
  if (DAT_140976004 == 0) {
    iVar1 = FUN_1401b1ba0(param_1,puVar3 + 4,local_648,0x600);
    if (iVar1 == 0) {
      iVar1 = FUN_1401b44e0(puVar3 + 6,(&DAT_14092df80)[(uint)puVar3[4]] + 8,local_648,param_4);
      if (-1 < iVar1) goto LAB_1401b17b1;
      FUN_1401b1030(puVar3[4]);
    }
    *puVar3 = 0;
    lVar4 = FUN_140139800(param_1,param_2,1,param_4);
    *(longlong *)(puVar3 + 2) = lVar4;
    if (lVar4 == 0) {
LAB_1401b16d1:
      if ((&DAT_140935f80)[(int)uVar5] != 0) {
        FUN_1401b6700();
      }
      (&DAT_140935f80)[(int)uVar5] = 0;
      FUN_1401b6e70(&DAT_14092dd48);
      return 0;
    }
  }
  else {
    lVar4 = FUN_140139800(param_1,param_2,1,param_4);
    *(longlong *)(puVar3 + 2) = lVar4;
    if (lVar4 != 0) {
      *puVar3 = 0;
      goto LAB_1401b17b7;
    }
    iVar1 = FUN_1401b1ba0(param_1,puVar3 + 4,local_648,0x600);
    if (iVar1 != 0) goto LAB_1401b16d1;
    iVar1 = FUN_1401b44e0(puVar3 + 6,(&DAT_14092df80)[(uint)puVar3[4]] + 8,local_648,param_4);
    if (iVar1 < 0) {
      FUN_1401b1030(puVar3[4]);
      goto LAB_1401b16d1;
    }
LAB_1401b17b1:
    *puVar3 = 1;
  }
LAB_1401b17b7:
  DAT_140976050 = DAT_140976050 + 1;
  FUN_1401b6e70(&DAT_14092dd48);
  return uVar5 | 0xf0000000;
}


