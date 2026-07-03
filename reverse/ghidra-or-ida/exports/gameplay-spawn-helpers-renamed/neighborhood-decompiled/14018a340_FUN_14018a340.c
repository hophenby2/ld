// Function: FUN_14018a340 @ 14018a340
// Decompile completed: true

undefined8 FUN_14018a340(uint param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = FUN_14019e300();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  if ((DAT_14088a630 == 0) && (DAT_14088d698 == 0)) {
    FUN_1401a4ab0();
  }
  if ((((DAT_140988598 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_1409885e8))
     && ((int)(param_1 & 0x3ffff) < DAT_1409885f0)) {
    lVar1 = (ulonglong)(param_1 & 0x3ffff) * 8;
    piVar2 = *(int **)(lVar1 + DAT_1409885a0);
    if ((piVar2 != (int *)0x0) && (*piVar2 << 0x12 == (param_1 & 0x3fc0000))) {
      if (piVar2[6] != 0) {
        if ((piVar2[6] < 2) && (-1 < piVar2[8])) {
          iVar3 = FUN_1401afbe0();
        }
        else {
          iVar3 = FUN_1401b82b0(param_1);
        }
        if (iVar3 < 0) {
          return 0xffffffff;
        }
        if (*(longlong *)(lVar1 + DAT_1409885a0) == 0) {
          return 0xffffffff;
        }
      }
      if (piVar2[0x5ed] == 1) {
        uVar4 = FUN_14018a5a0(param_1,param_2,param_3);
        return uVar4;
      }
      iVar3 = FUN_14019c8c0(piVar2,param_3);
      if (iVar3 != 1) {
        iVar3 = FUN_14018e080(piVar2 + (longlong)piVar2[0xb3e] * 0x8e + 0x5c,param_2 == 3);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
        if (piVar2[0x28] != 0) {
          FUN_1401b6dc0(&DAT_140844e60,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",
                        0x14c0);
          if (piVar2[0x29] == 0) {
            piVar2[0x29] = 1;
            FUN_1401b7400(&DAT_140844e20,piVar2 + 0x2a,param_1,piVar2);
          }
          FUN_1401b6e70(&DAT_140844e60);
        }
        FUN_1401b6dc0(&DAT_140844900,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x14cd
                     );
        if (piVar2[0x32] == 0) {
          piVar2[0x32] = 1;
          FUN_1401b7400(&DAT_1408448c0,piVar2 + 0x34,param_1,piVar2);
        }
        FUN_1401b6e70(&DAT_140844900);
        if (param_2 == 0) {
          iVar3 = FUN_1401ad850();
          while ((iVar3 == 0 && (iVar3 = FUN_140184a00(param_1), iVar3 == 1))) {
            FUN_1401b7120(1);
            iVar3 = FUN_1401ad850();
          }
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}


