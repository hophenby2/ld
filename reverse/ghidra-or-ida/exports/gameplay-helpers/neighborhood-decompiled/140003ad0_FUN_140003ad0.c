// Function: FUN_140003ad0 @ 140003ad0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140003ad0(longlong param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  bool bVar6;
  double dVar7;
  
  uVar4 = DAT_140e445dc;
  uVar3 = DAT_140e445d8;
  uVar2 = DAT_140e445b0;
  if (DAT_140e41928 == 0) {
    bVar1 = DAT_1407c7798 == 8 || DAT_1407c7798 == 9;
    if (DAT_140e467e8 != 0) {
      bVar6 = DAT_1407c7798 == DAT_140e467e8;
LAB_140003b5a:
      if (bVar6) {
LAB_140003b5c:
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = false;
    if ((DAT_140e41928 == 1) && (bVar1 = false, -1 < DAT_140e41abc)) {
      if (((DAT_140e44e68 == 0) && (DAT_1407c7798 == 8)) || (bVar1 = false, DAT_1407c7798 == 9)) {
        bVar1 = true;
      }
      if (DAT_140e467e8 != 0) {
        if (DAT_140e467e8 == DAT_1407c7798) goto LAB_140003b5c;
        if (DAT_140e467e8 == DAT_1407c7798 + 1) {
          bVar6 = DAT_140e41abc == 0;
          goto LAB_140003b5a;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0xc) == 1) {
    DAT_140e41a3c = 1;
    DAT_140e44654 = 0x168;
  }
  puVar5 = DAT_140e45d28;
  if ((((*(int *)(param_1 + 0xc) == 0x14a) && (0 < DAT_140e445f8)) &&
      ((bVar1 || ((DAT_140e41928 == 0 || (DAT_1407c7798 == 10)))))) &&
     ((DAT_140e41928 != 2 && ((DAT_140e44590 != 0 && (DAT_140e45d1c < 0x1000)))))) {
    puVar5 = (undefined8 *)_malloc_base(0x60);
    if (puVar5 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar6 = DAT_140e45d78 == (undefined8 *)0x0;
    *(undefined4 *)((longlong)puVar5 + 0x14) = uVar3;
    *(undefined4 *)(puVar5 + 3) = uVar4;
    *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar3;
    *(undefined4 *)(puVar5 + 4) = uVar4;
    *puVar5 = 1;
    *(undefined4 *)(puVar5 + 1) = 0x29;
    *(undefined4 *)((longlong)puVar5 + 0xc) = uVar2;
    *(undefined4 *)(puVar5 + 2) = 0x73;
    *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
    puVar5[5] = 0;
    puVar5[6] = 0x3ff0000000000000;
    puVar5[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar5 + 8) = 0x78;
    *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
    *(undefined4 *)(puVar5 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
    puVar5[10] = 0xff;
    puVar5[0xb] = 0;
    if (bVar6) {
      DAT_140e45d78 = puVar5;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar5;
    }
  }
  DAT_140e45d28 = puVar5;
  if (*(int *)(param_1 + 0xc) - 0x168U < 0x79) {
    if ((((((DAT_140e41928 == 0) || (bVar1)) || (5 < DAT_1407c7798)) ||
         ((DAT_140e41b00 != 0 || (0 < DAT_140e41abc)))) || (DAT_140e41928 == 2)) &&
       (DAT_1407c7798 != 8)) {
      dVar7 = (double)FUN_140332d90(((double)*(int *)(param_1 + 0xc) - _DAT_14053a690) *
                                    DAT_14053a4d8 * DAT_14053a020 * DAT_140539d28);
      _DAT_1407c777c = (float)(dVar7 * DAT_14053b0a0) + DAT_140539da8;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    }
    if (0x1a3 < *(int *)(param_1 + 0xc)) {
      if (DAT_140e41928 == 1) {
        if ((bVar1) || (DAT_1407c7798 == 10)) goto LAB_140003e0e;
        if (DAT_140e41b00 == 0) {
          if ((DAT_140e41abc == 0) && (DAT_1407c7798 < 6)) goto LAB_140003e0e;
        }
        else if (DAT_140e41b00 != 1) goto LAB_140003e0e;
        FUN_1400d3fd0(*(int *)(param_1 + 0xc) + -0x1a4);
      }
      if ((DAT_140e41928 == 2) && (DAT_140e41b00 == 0)) {
        FUN_1400d3fd0(*(int *)(param_1 + 0xc) + -0x1a4);
      }
    }
  }
LAB_140003e0e:
  if (*(int *)(param_1 + 0xc) == 0x1a4) {
    DAT_140e41a38 = 1;
    DAT_140e41b08 = 1;
    return;
  }
  if (*(int *)(param_1 + 0xc) == 0x1e0) {
    DAT_140e418cc = 0;
    DAT_140e41afc = 1;
  }
  return;
}


