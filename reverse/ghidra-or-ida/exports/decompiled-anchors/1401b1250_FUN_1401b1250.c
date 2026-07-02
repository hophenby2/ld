// Function: FUN_1401b1250 @ 1401b1250
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_1401b1250(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 auStack_648 [32];
  undefined1 local_628 [1536];
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_648;
  piVar2 = (int *)FUN_1401b6390(0x10,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                                0x1075);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0xffffffffffffffff;
  }
  else {
    FUN_1401ae370(piVar2,0,0x10);
    iVar1 = FUN_1401b1ba0(param_1,piVar2 + 1,local_628,0x600);
    if (iVar1 == -1) {
      *piVar2 = 0;
      lVar3 = FUN_140139740(param_1,param_2);
    }
    else {
      *piVar2 = 1;
      lVar3 = FUN_1401b28a0((&DAT_14092df80)[piVar2[1]] + 8,local_628,param_2);
    }
    *(longlong *)(piVar2 + 2) = lVar3;
    if (lVar3 == -1) {
      if (*piVar2 != 0) {
        FUN_1401b1030(piVar2[1]);
      }
      FUN_1401b6700(piVar2);
      piVar2 = (int *)0xffffffffffffffff;
    }
  }
  return piVar2;
}


