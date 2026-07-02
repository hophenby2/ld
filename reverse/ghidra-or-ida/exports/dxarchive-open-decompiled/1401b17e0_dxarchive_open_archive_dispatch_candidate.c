// Function: dxarchive_open_archive_dispatch_candidate @ 1401b17e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined *
dxarchive_open_archive_dispatch_candidate
          (undefined8 param_1,longlong param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,uint param_6,int param_7,undefined4 param_8)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  longlong *plVar13;
  undefined *puVar14;
  undefined1 auStack_9a8 [32];
  undefined4 local_988;
  undefined *local_980;
  undefined8 local_978;
  undefined4 local_968;
  undefined4 local_964;
  undefined8 local_960;
  longlong local_958;
  undefined1 local_948 [2304];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_9a8;
  local_968 = param_4;
  local_964 = param_3;
  local_960 = param_1;
  local_958 = param_2;
  FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xdab);
  if (((param_6 != 0xffffffff) && ((&DAT_14092df80)[(int)param_6] != 0)) &&
     (iVar3 = FUN_1401aeb00(param_1,(&DAT_14092df80)[(int)param_6] + 0x908), iVar3 == 0)) {
    *(int *)(&DAT_14092df80)[(int)param_6] = *(int *)(&DAT_14092df80)[(int)param_6] + 1;
    FUN_1401b6e70(&DAT_14092dd48);
    return (undefined *)(ulonglong)param_6;
  }
  uVar7 = 0xffffffff;
  puVar12 = (undefined *)0x0;
  plVar13 = &DAT_14092df80;
  iVar3 = DAT_14097604c;
  if (0 < DAT_14097604c) {
    puVar10 = &DAT_14092df80;
    puVar8 = (undefined *)0xffffffff;
    puVar11 = puVar12;
    puVar14 = puVar12;
    do {
      piVar1 = (int *)*puVar10;
      puVar9 = puVar11;
      if (piVar1 != (int *)0x0) {
        puVar14 = (undefined *)(ulonglong)((int)puVar14 + 1);
        iVar4 = FUN_1401aebd0(piVar1 + 0x242,param_1);
        puVar9 = puVar8;
        iVar3 = DAT_14097604c;
        if (iVar4 == 0) {
          *piVar1 = *piVar1 + 1;
          FUN_1401b6e70(&DAT_14092dd48);
          return puVar11;
        }
      }
      uVar7 = (uint)puVar9;
      puVar11 = (undefined *)(ulonglong)((int)puVar11 + 1);
      puVar10 = puVar10 + 1;
      puVar8 = puVar9;
    } while ((int)puVar14 < iVar3);
  }
  if (iVar3 == 0x1000) {
    FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xe7e);
    iVar3 = DAT_14097604c;
    if (0 < DAT_14097604c) {
      puVar10 = &DAT_14092df80;
      puVar8 = puVar12;
      do {
        piVar1 = (int *)*puVar10;
        if ((piVar1 != (int *)0x0) &&
           (puVar8 = (undefined *)(ulonglong)((int)puVar8 + 1), *piVar1 < 1)) {
          FUN_1401b0960(piVar1 + 2);
          FUN_1401b0960(piVar1 + 2);
          FUN_1401ae370(piVar1 + 2,0,0x900);
          FUN_1401b6700(piVar1);
          *puVar10 = 0;
          DAT_14097604c = DAT_14097604c + -1;
        }
        puVar10 = puVar10 + 1;
      } while ((int)puVar8 < iVar3);
    }
    FUN_1401b6e70(&DAT_14092dd48);
    param_1 = local_960;
    if (DAT_14097604c == 0x1000) goto LAB_1401b1b01;
  }
  uVar6 = 0;
  puVar8 = puVar12;
  lVar2 = DAT_14092df80;
  if (uVar7 == 0xffffffff) {
    while (uVar7 = uVar6, lVar2 != 0) {
      uVar6 = (int)puVar8 + 1;
      plVar13 = plVar13 + 1;
      puVar8 = (undefined *)(ulonglong)uVar6;
      lVar2 = *plVar13;
    }
  }
  FUN_1401ae370(local_948,0,0x900);
  if (local_958 == 0) {
    if (param_7 == 1) {
      if (DAT_140976008 == 1) {
        puVar12 = &DAT_14097600c;
      }
      iVar3 = FUN_1401b3750(local_948,param_1,puVar12,param_8);
      if (iVar3 < 0) {
        FUN_1401b6e70(&DAT_14092dd48);
        return (undefined *)0xffffffff;
      }
    }
    else {
      if (DAT_140976008 == 1) {
        puVar12 = &DAT_14097600c;
      }
      iVar3 = FUN_1401b3410(local_948,param_1,puVar12);
      if (iVar3 < 0) goto LAB_1401b1b01;
    }
  }
  else {
    if (DAT_140976008 == 1) {
      puVar12 = &DAT_14097600c;
    }
    local_988 = param_5;
    local_980 = puVar12;
    local_978 = param_1;
    iVar3 = FUN_1401b3b60(local_948,local_958,local_964,local_968);
    if (iVar3 < 0) {
      FUN_1401b6e70(&DAT_14092dd48);
      return (undefined *)0xffffffff;
    }
  }
  puVar5 = (undefined4 *)
           FUN_1401b6390(0xd18,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xe12);
  (&DAT_14092df80)[(int)uVar7] = (longlong)puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    FUN_1401ae2f0(puVar5 + 2,local_948,0x900);
    *puVar5 = 1;
    FUN_1401aeb80(puVar5 + 0x242,0x410,param_1);
    DAT_14097604c = DAT_14097604c + 1;
    FUN_1401b6e70(&DAT_14092dd48);
    return (undefined *)(ulonglong)uVar7;
  }
  FUN_1401b0960(local_948);
  FUN_1401b0960(local_948);
  FUN_1401ae370(local_948,0,0x900);
LAB_1401b1b01:
  FUN_1401b6e70(&DAT_14092dd48);
  return (undefined *)0xffffffff;
}


