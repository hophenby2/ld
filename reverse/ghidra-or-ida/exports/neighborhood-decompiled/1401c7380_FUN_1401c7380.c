// Function: FUN_1401c7380 @ 1401c7380
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_1401c7380(undefined8 param_1,uint param_2,longlong param_3,undefined4 *param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int *piVar6;
  longlong lVar7;
  ulonglong uVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  piVar9 = (int *)0x0;
  iVar3 = 0;
  if ((((int)(uint)DAT_140b121c0 < 0) || (((uint)DAT_140b121c0 & 0x7c000000) != 0x24000000)) ||
     (0xff < ((uint)DAT_140b121c0 & 0x3ffff))) {
LAB_1401c741d:
    piVar6 = piVar9;
  }
  else if (((&DAT_140b121c8)[(ulonglong)((uint)DAT_140b121c0 & 0x3ffff) * 0x1a] == 0) ||
          (piVar6 = &DAT_140b121c8 + (ulonglong)((uint)DAT_140b121c0 & 0x3ffff) * 0x1a,
          (&DAT_140b121cc)[(ulonglong)((uint)DAT_140b121c0 & 0x3ffff) * 0x1a] << 0x12 !=
          ((uint)DAT_140b121c0 & 0x3fc0000))) goto LAB_1401c741d;
  _DAT_140b12140 = 1;
  _DAT_140b121b4 = FUN_1401ad0e0(0);
  _DAT_140b121bc = 1;
  if (param_2 < 0x282) {
    if (param_2 == 0x281) {
      lVar5 = FUN_1401e41b0(param_1,0x281,param_3,0);
      return lVar5;
    }
    if (param_2 == 0x10d) {
      _DAT_140b0fce8 = 1;
      _DAT_140b121bc = 1;
      return 0;
    }
    if (param_2 == 0x10e) {
      FUN_1401ae370(&DAT_140b0fcf0,0,0x400);
      _DAT_140b0fce8 = _DAT_140b0fce8 & 0xffffffff00000000;
      return 0;
    }
    if (param_2 != 0x10f) {
      _DAT_140b121bc = 1;
      return 0;
    }
    lVar5 = (*DAT_140c2b550)(param_1);
    if (((ulonglong)param_4 & 8) != 0) {
      FUN_1401ae370(&DAT_140b0fcf0,0,0x400);
      (*DAT_140c2b590)(lVar5,8,&DAT_140b0fcf0,0x400);
    }
    if (((ulonglong)param_4 >> 0xb & 1) != 0) {
      FUN_1401ae370(&DAT_140b0fcf0,0,0x400);
      (*DAT_140c2b590)(lVar5,0x800,&DAT_140b0fcf0,0x400);
      piVar6 = piVar9;
      sVar1 = DAT_140b0fcf0;
      while (sVar1 != 0) {
        piVar6 = (int *)((longlong)piVar6 + 1);
        sVar1 = (&DAT_140b0fcf0)[(longlong)piVar6];
      }
      if (0 < (int)piVar6) {
        do {
          FUN_1401c9580((&DAT_140b0fcf0)[(longlong)piVar9]);
          piVar9 = (int *)((longlong)piVar9 + 1);
        } while ((longlong)piVar9 < (longlong)(int)piVar6);
      }
      FUN_1401ae370(&DAT_140b0fcf0,0,0x802);
      (*DAT_140c2b590)(lVar5,8,&DAT_140b0fcf0,0x400);
      if (DAT_140b10cf8 != 0) {
        FUN_1401b6700();
        DAT_140b10cf8 = 0;
        DAT_140b10d00 = 0;
      }
    }
    if ((char)param_4 < '\0') {
      uVar2 = (*DAT_140c2b590)(lVar5,0x80,0,0);
      uVar2 = FUN_1401c7300(&DAT_140b0fcf0,uVar2);
      _DAT_140b0fce8 = CONCAT44(uVar2,DAT_140b0fce8);
    }
    if (((ulonglong)param_4 & 0x20) != 0) {
      FUN_1401ae370(&DAT_140b10d38,0,0x1000);
      iVar3 = (*DAT_140c2b590)(lVar5,0x20,&DAT_140b10d38,0x1000);
      _DAT_140b11d38 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    }
    if (((ulonglong)param_4 & 0x10) != 0) {
      FUN_1401ae370(&DAT_140b11d3c,0,0x400);
      _DAT_140b1213c = (*DAT_140c2b590)(lVar5,0x10,&DAT_140b11d3c,0x400);
    }
  }
  else if (param_2 == 0x282) {
    if (param_3 != 3) {
      if (param_3 == 4) {
        if (DAT_140b10cf8 != 0) {
          FUN_1401b6700();
        }
        DAT_140b10cf8 = 0;
        DAT_140b10d00 = 0;
        return 0;
      }
      if (param_3 != 5) {
        if (param_3 == 8) {
          if (DAT_140b189e8 != 0) {
            _DAT_140b121bc = 1;
            return 0;
          }
          DAT_140b189e8 = 1;
          FUN_1401e41b0(param_1,0x282,8,param_4);
          lVar5 = FUN_1401ad240();
          do {
            iVar3 = FUN_1401ad850();
            if (iVar3 != 0) break;
            lVar7 = FUN_1401ad240();
            uVar8 = FUN_1401acc20(lVar7 - lVar5);
          } while (uVar8 < 2000);
          DAT_140b189e8 = 0;
          lVar5 = (*DAT_140c2b550)(param_1);
          DAT_140b10d18 = (*DAT_140c2b560)(lVar5);
          goto LAB_1401c79e3;
        }
        if (param_3 != 9) {
          lVar5 = FUN_1401e41b0(param_1,0x282,param_3,param_4);
          return lVar5;
        }
      }
    }
    if (DAT_140b189d0 != 0) {
      _DAT_140b121bc = 1;
      return 0;
    }
    lVar5 = (*DAT_140c2b550)(param_1);
    iVar3 = (*DAT_140c2b580)(lVar5,0,0,0);
    if (iVar3 != 0) {
      DAT_140b10d00 = iVar3;
      if (DAT_140b10cf8 != 0) {
        FUN_1401b6700();
      }
      DAT_140b10cf8 =
           FUN_1401b6390(iVar3,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",0x504)
      ;
      if (DAT_140b10cf8 == 0) {
        (*DAT_140c2b558)(param_1,lVar5);
        iVar3 = FUN_1401aed40(&DAT_1404ad110,iVar3);
        return (longlong)iVar3;
      }
      iVar4 = (*DAT_140c2b580)(lVar5,0,DAT_140b10cf8,iVar3);
      if (iVar4 == 0) {
        FUN_1401b6700(DAT_140b10cf8);
        DAT_140b10cf8 = 0;
        (*DAT_140c2b558)(param_1,lVar5);
        FUN_140159b70(&DAT_1404ad1b0,iVar3);
        return 0;
      }
    }
  }
  else {
    if (param_2 != 0x288) {
      _DAT_140b121bc = 1;
      return 0;
    }
    if ((piVar6 == (int *)0x0) || (param_3 != 4)) {
      FUN_1401e41b0(param_1,0x288,param_3,param_4);
      return 0;
    }
    iVar4 = piVar6[6];
    if (iVar4 == -1) {
      lVar5 = 0;
      sVar1 = **(short **)(piVar6 + 10);
      while (iVar10 = (int)lVar5, sVar1 != 0) {
        lVar5 = lVar5 + 1;
        sVar1 = (*(short **)(piVar6 + 10))[lVar5];
      }
    }
    else {
      iVar3 = piVar6[7];
      if (iVar3 < iVar4) {
        iVar10 = iVar4 - iVar3;
      }
      else {
        iVar10 = iVar3 - iVar4;
        iVar3 = iVar4;
      }
    }
    if (param_4 == (undefined4 *)0x0) {
      _DAT_140b121bc = 1;
      return (longlong)(iVar10 + 1) * 2 + 0x20;
    }
    if (iVar4 == -1) {
      FUN_1401aeb40(param_4 + 8,*(undefined8 *)(piVar6 + 10));
    }
    else {
      FUN_1401ae2f0(param_4 + 8,*(longlong *)(piVar6 + 10) + (longlong)iVar3 * 2,
                    (longlong)iVar10 * 2);
      *(undefined2 *)((longlong)iVar10 * 2 + 0x20 + (longlong)param_4) = 0;
    }
    param_4[2] = iVar10;
    param_4[3] = 0x20;
    *(undefined8 *)(param_4 + 6) = 0;
    lVar5 = (*DAT_140c2b550)(param_1);
    if (lVar5 == 0) {
      return 0;
    }
    if (piVar6[6] == -1) {
      param_4[5] = piVar6[9] * 2;
      sVar1 = **(short **)(piVar6 + 10);
      while (sVar1 != 0) {
        piVar9 = (int *)((longlong)piVar9 + 1);
        sVar1 = (*(short **)(piVar6 + 10))[(longlong)piVar9];
      }
      param_4[4] = (int)piVar9;
    }
    else {
      param_4[5] = 0;
      param_4[4] = iVar10;
    }
    (*DAT_140c2b598)(lVar5,0x20000,param_4,*param_4,0,0);
    iVar3 = (*DAT_140c2b598)(lVar5,0x10000,param_4,*param_4,0,0);
    if (iVar3 != 0) {
      if (piVar6[6] == -1) {
        uVar11 = (uint)param_4[5] >> 1;
        piVar6[6] = uVar11;
        iVar3 = param_4[4];
        piVar6[9] = uVar11;
        piVar6[7] = iVar3 + uVar11;
      }
      FUN_1401c7cd0(piVar6);
    }
  }
LAB_1401c79e3:
  (*DAT_140c2b558)(param_1,lVar5);
  return 0;
}


