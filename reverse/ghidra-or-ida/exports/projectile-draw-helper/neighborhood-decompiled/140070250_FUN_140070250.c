// Function: FUN_140070250 @ 140070250
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140070250(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  short param_6,int param_7)

{
  double dVar1;
  double dVar2;
  double dVar3;
  short sVar4;
  double dVar5;
  double dVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  short sVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  bool bVar13;
  undefined8 in_stack_ffffffffffffff18;
  
  dVar6 = DAT_14053a020;
  dVar5 = DAT_140539d28;
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  dVar3 = (double)param_3 - 0.0;
  dVar1 = (double)FUN_140332d90(SUB84(dVar3 * _DAT_14053ab18 * DAT_14053a020 * DAT_140539d28,0));
  dVar2 = dVar1 * DAT_140539e60 + DAT_140539f58;
  dVar1 = (double)FUN_140332d90(SUB84(((double)param_3 - DAT_14053a0f8) * _DAT_14053ab18 * dVar6 *
                                      dVar5,0));
  uVar8 = DAT_140e451d4;
  uVar7 = DAT_140e451d0;
  dVar1 = dVar1 * DAT_140539ec8 + DAT_140539f58;
  sVar4 = (short)param_3;
  uVar11 = DAT_140e451c0;
  puVar9 = DAT_140e45d28;
  switch(param_1) {
  case 1:
    uVar11 = DAT_140e451c4;
  case 0:
    param_6 = sVar4 * 2000;
    dVar1 = dVar2;
    break;
  case 2:
    param_6 = sVar4 * 999;
    uVar11 = DAT_140e451c8;
    dVar1 = dVar2;
    break;
  case 3:
    param_6 = sVar4 * 999;
    uVar11 = DAT_140e451cc;
    dVar1 = dVar2;
    break;
  case 4:
    param_6 = sVar4 * 0x682;
    uVar11 = uVar7;
    dVar1 = dVar2;
    break;
  case 5:
    param_6 = sVar4 * 0x682;
    uVar11 = uVar8;
    dVar1 = dVar2;
    break;
  case 6:
    uVar11 = DAT_140e451d8;
    dVar2 = DAT_140539f40;
    break;
  case 7:
    uVar11 = DAT_140e451dc;
    dVar2 = DAT_140539f40;
    break;
  case 8:
    uVar11 = DAT_140e451e0;
    dVar2 = DAT_140539f40;
    break;
  case 9:
    uVar11 = DAT_140e451e4;
    dVar2 = DAT_140539f40;
    break;
  case 10:
    uVar11 = DAT_140e45210;
    break;
  case 0xb:
    uVar11 = DAT_140e45214;
    break;
  case 0xc:
    uVar11 = DAT_140e45218;
    break;
  case 0xd:
    uVar11 = DAT_140e4521c;
    break;
  case 0xe:
    param_6 = sVar4 * 999;
    uVar11 = DAT_140e45220;
    dVar1 = dVar2;
    break;
  case 0xf:
    param_6 = sVar4 * 999;
    uVar11 = DAT_140e45224;
    dVar1 = dVar2;
    break;
  case 0x10:
    uVar11 = DAT_140e45228;
    dVar2 = DAT_140539f40;
    break;
  case 0x11:
    dVar3 = (double)FUN_140332d90(SUB84(dVar3 * _DAT_14053aac0 * dVar6 * dVar5,0));
    FUN_1400c8410(DAT_140e4194c,param_2 + -1,7,param_4,param_5,param_6,DAT_140539f40,
                  dVar3 * DAT_140539ef8 + DAT_140539f10,CONCAT44(uVar12,0xff),0xff,0xff,0xc0,1,0);
    uVar11 = uVar7;
    puVar9 = DAT_140e45d28;
    param_6 = sVar4 * 0x682;
    break;
  case 0x12:
    dVar3 = (double)FUN_140332d90(SUB84(dVar3 * _DAT_14053aac0 * dVar6 * dVar5,0));
    FUN_1400c8410(DAT_140e4194c,param_2 + -1,7,param_4,param_5,param_6,DAT_140539f40,
                  dVar3 * DAT_140539ef8 + DAT_140539f10,CONCAT44(uVar12,0xff),0xff,0xff,0xc0,1,0);
    uVar11 = uVar8;
    puVar9 = DAT_140e45d28;
    param_6 = sVar4 * 0x682;
    break;
  case 0x13:
    sVar10 = sVar4 * -0x457;
    FUN_1400c8410(DAT_140e44834,0x23,7,param_4,param_5,sVar10,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  CONCAT44(uVar12,0xff),0xff,0xff,0xff,1,0);
    uVar12 = DAT_140e44834;
    uVar11 = uVar8;
    puVar9 = DAT_140e45d28;
    param_6 = sVar4 * 0x682;
    if (0xfff < DAT_140e45d1c) break;
    puVar9 = (undefined8 *)_malloc_base(0x60);
    if (puVar9 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(undefined4 *)(puVar9 + 1) = 5;
    goto LAB_1400707a4;
  case 0x14:
    sVar10 = sVar4 * 0x457;
    FUN_1400c8410(DAT_140e44838,0x23,7,param_4,param_5,sVar10,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  CONCAT44(uVar12,0xff),0xff,0xff,0xff,1,1);
    uVar12 = DAT_140e44838;
    uVar11 = uVar7;
    puVar9 = DAT_140e45d28;
    param_6 = sVar4 * 0x682;
    if (0xfff < DAT_140e45d1c) break;
    puVar9 = (undefined8 *)_malloc_base(0x60);
    if (puVar9 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(undefined4 *)(puVar9 + 1) = 7;
LAB_1400707a4:
    param_6 = sVar4 * 0x682;
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar13 = DAT_140e45d78 == (undefined8 *)0x0;
    *(undefined4 *)(puVar9 + 4) = param_5;
    *(undefined4 *)((longlong)puVar9 + 0x1c) = param_4;
    *(undefined4 *)(puVar9 + 3) = param_5;
    *(undefined4 *)((longlong)puVar9 + 0x14) = param_4;
    puVar9[0xb] = 0;
    puVar9[10] = 0x60;
    *(undefined4 *)((longlong)puVar9 + 0x4c) = 0xff;
    *(undefined4 *)(puVar9 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar9 + 0x44) = 0xff;
    *(undefined4 *)(puVar9 + 8) = 0x10;
    puVar9[7] = 0x3ff0000000000000;
    puVar9[6] = 0x3ff0000000000000;
    puVar9[5] = 0;
    *(short *)((longlong)puVar9 + 0x24) = sVar10;
    *(undefined4 *)(puVar9 + 2) = 0x22;
    *(undefined4 *)((longlong)puVar9 + 0xc) = uVar12;
    *puVar9 = 1;
    if (bVar13) {
      DAT_140e45d78 = puVar9;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar9;
    }
  }
  DAT_140e45d28 = puVar9;
  FUN_1400c8410(uVar11,param_2,7,param_4,param_5,param_6,dVar2,dVar1,0xff,0xff,0xff,0xff,1,0);
  if (param_7 == 1) {
    FUN_140070d00(5,uVar11,param_2 + -2,param_4,param_5,param_6,0,dVar2,dVar1,0xc,0xff,0xff,0xff,
                  0x40,0);
  }
  return;
}


