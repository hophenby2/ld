// Function: FUN_1401b1ba0 @ 1401b1ba0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401b1ba0(undefined8 param_1,int *param_2,longlong param_3,ulonglong param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_3cb8 [32];
  ulonglong local_3c98;
  int local_3c90;
  undefined4 local_3c88;
  undefined4 local_3c80;
  ulonglong local_3c78;
  int *local_3c70;
  int local_3c68;
  int local_3c64;
  int local_3c60 [2];
  undefined1 local_3c58 [3072];
  undefined1 local_3058 [3072];
  undefined1 local_2458 [3072];
  undefined1 local_1858 [3072];
  undefined1 local_c58 [3072];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_3cb8;
  local_3c64 = 0;
  local_3c78 = param_4;
  local_3c70 = param_2;
  FUN_1401b6dc0(&DAT_14092dd48,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xce8);
  if (DAT_14092df78 == 0) {
    FUN_1401367e0(param_1,local_3c58,0xc00,0);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    puVar8 = local_3c58;
  }
  else {
    FUN_1401367e0(param_1,local_3c58,0xc00,0);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    FUN_1401ba3d0(DAT_1408ab148,local_1858,local_3c58);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    puVar8 = local_1858;
  }
  FUN_1401bb1c0(DAT_1408ab148,puVar8);
  if ((DAT_140976c58 != 0) && (iVar1 = FUN_1401ae2b0(local_3c58,&DAT_140976058), iVar1 == 0)) {
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar1 = FUN_1401c4e50(local_3c58 + DAT_140976c58,DAT_1408ab148,&local_3c64);
    if ((iVar1 == 0x5c) || (iVar1 == 0x2f)) {
      local_3c80 = 0;
      local_3c88 = 0;
      local_3c90 = DAT_140976054;
      local_3c98 = local_3c98 & 0xffffffff00000000;
      iVar2 = FUN_1401b17e0(&DAT_140976058,0,0xffffffff,0);
      if (iVar2 == -1) {
LAB_1401b22b5:
        FUN_1401b6e70(&DAT_14092dd48);
        return 0xffffffff;
      }
      if (DAT_14092df78 == 0) {
        puVar8 = local_3c58 + (DAT_140976c58 + local_3c64);
      }
      else {
        puVar8 = local_1858 + (DAT_140976c58 + local_3c64);
      }
      goto LAB_1401b2259;
    }
  }
  puVar8 = local_3c58;
  local_3c60[0] = 0;
  iVar1 = 0;
LAB_1401b1d72:
  iVar2 = 0;
  if (((longlong)puVar8 - (longlong)local_3c58 & 0xfffffffffffffffeU) == 0) {
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar3 = FUN_1401c4e50(local_3c58,DAT_1408ab148,&local_3c68);
    iVar4 = iVar2;
    if (iVar3 != 0) {
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = FUN_1401c4e50(local_3c58 + local_3c68,DAT_1408ab148,local_3c60);
    }
    if ((iVar3 == 0x5c) && (iVar4 == 0x5c)) {
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(0x5c,DAT_1408ab148,local_2458 + iVar1,0xc00 - (longlong)iVar1);
      iVar1 = iVar1 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(0x5c,DAT_1408ab148,local_2458 + iVar1,0xc00 - (longlong)iVar1);
      iVar1 = iVar1 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      thunk_FUN_1401c5940(0,DAT_1408ab148,local_2458 + iVar1,0xc00 - (longlong)iVar1);
      puVar8 = puVar8 + (longlong)local_3c68 + (longlong)local_3c60[0];
    }
  }
  do {
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar4 = FUN_1401c4e50(puVar8,DAT_1408ab148,&local_3c68);
    puVar8 = puVar8 + local_3c68;
    if (puVar8 + -(longlong)local_3c68 != local_3c58) {
      if (iVar4 == 0) goto LAB_1401b22b5;
      if ((iVar4 == 0x2f) || (iVar4 == 0x5c)) break;
    }
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar3 = thunk_FUN_1401c5940(iVar4,DAT_1408ab148,local_2458 + iVar1,0xc00 - (longlong)iVar1);
    iVar1 = iVar1 + iVar3;
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar4 = thunk_FUN_1401c5940(iVar4,DAT_1408ab148,local_c58 + iVar2,0xc00 - (longlong)iVar2);
    iVar2 = iVar2 + iVar4;
  } while( true );
  if (iVar2 == 0) goto LAB_1401b22b5;
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  lVar6 = (longlong)iVar1;
  lVar7 = 0xc00 - lVar6;
  thunk_FUN_1401c5940(0,DAT_1408ab148,local_2458 + lVar6,lVar7);
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  thunk_FUN_1401c5940(0,DAT_1408ab148,local_c58 + iVar2,0xc00 - (longlong)iVar2);
  FUN_1401ae2f0(local_3058,local_2458,lVar6);
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  iVar2 = thunk_FUN_1401c5940(0x2e,DAT_1408ab148,local_3058 + lVar6,lVar7);
  iVar2 = iVar1 + iVar2;
  if (DAT_140976000 == 0) {
    if (DAT_14092df78 == 0) {
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(0x44,DAT_1408ab148,local_3058 + iVar2,0xc00 - (longlong)iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(0x58,DAT_1408ab148,local_3058 + iVar2,0xc00 - (longlong)iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      uVar5 = 0x41;
    }
    else {
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(100,DAT_1408ab148,local_3058 + iVar2,0xc00 - (longlong)iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar4 = thunk_FUN_1401c5940(0x78,DAT_1408ab148,local_3058 + iVar2,0xc00 - (longlong)iVar2);
      iVar2 = iVar2 + iVar4;
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      uVar5 = 0x61;
    }
    iVar4 = thunk_FUN_1401c5940(uVar5,DAT_1408ab148,local_3058 + iVar2,0xc00 - (longlong)iVar2);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    thunk_FUN_1401c5940(0,DAT_1408ab148,local_3058 + (iVar2 + iVar4),
                        0xc00 - (longlong)(iVar2 + iVar4));
  }
  else {
    FUN_1401aeb80(local_3058 + iVar2,0xc00 - (longlong)iVar2,&DAT_140975f80);
  }
  local_3c80 = 0;
  local_3c88 = 0;
  local_3c90 = -1;
  local_3c98 = local_3c98 & 0xffffffff00000000;
  iVar2 = FUN_1401b17e0(local_3058,0,0xffffffff,0);
  if (iVar2 != -1) goto LAB_1401b2211;
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  iVar2 = thunk_FUN_1401c5940(0x5c,DAT_1408ab148,local_2458 + lVar6,lVar7);
  iVar1 = iVar1 + iVar2;
  goto LAB_1401b1d72;
LAB_1401b2211:
  FUN_1401aeb80(&DAT_140976058,0xc00,local_3058);
  param_4 = local_3c78;
  DAT_140976054 = iVar2;
  DAT_140976c58 = iVar1;
  if (DAT_14092df78 != 0) {
    puVar8 = local_1858 + ((longlong)puVar8 - (longlong)local_3c58 >> 1) * 2;
  }
LAB_1401b2259:
  *local_3c70 = iVar2;
  if (param_3 != 0) {
    iVar1 = *(int *)((&DAT_14092df80)[iVar2] + 0x48);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    local_3c98 = param_4;
    local_3c90 = iVar1;
    FUN_1401c0470(puVar8,0xffffffff,DAT_1408ab148,param_3);
  }
  FUN_1401b6e70(&DAT_14092dd48);
  return 0;
}


