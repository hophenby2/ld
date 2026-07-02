// Function: FUN_1402259a0 @ 1402259a0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402259a0(void)

{
  longlong lVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_1078 [32];
  float *local_1058;
  undefined4 local_1050;
  undefined4 local_1048;
  float local_1038;
  float local_1034;
  float local_1030;
  float local_102c;
  undefined1 local_1028 [16];
  float local_1018;
  undefined4 uStack_1014;
  undefined4 uStack_1010;
  undefined4 uStack_100c;
  ulonglong local_28;
  undefined8 uStack_20;
  
  uStack_20 = 0x1402259af;
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_1078;
  pfVar4 = (float *)0x0;
  if (-1 < DAT_140d7ad24) {
    pfVar2 = (float *)&DAT_140d7b150;
    piVar5 = &DAT_140d7ad28;
    iVar6 = 0x24;
    iVar8 = 0xb;
    pfVar3 = pfVar4;
    do {
      iVar7 = (int)pfVar3;
      if (*piVar5 != 0) {
        local_1038 = DAT_140d8193c * pfVar2[-1];
        local_1034 = DAT_140d81940 * *pfVar2;
        local_1030 = DAT_140d81944 * pfVar2[1];
        local_102c = DAT_140d81948 * pfVar2[2];
        if (iVar7 < 4) {
          local_1048 = 1;
          local_1058 = &local_1038;
          local_1050 = 1;
          FUN_14023dd40(&DAT_140ca5d24,0,0,iVar6 + -0x12);
          local_1048 = 1;
          local_1058 = &local_1038;
          local_1050 = 1;
          FUN_14023dd40(&DAT_140ca5d24,3,0,iVar8);
        }
        if (iVar7 < 6) {
          local_1048 = 1;
          local_1058 = &local_1038;
          local_1050 = 1;
          FUN_14023dd40(&DAT_140ca5d24,3,0,iVar6);
        }
      }
      pfVar3 = (float *)(ulonglong)(iVar7 + 1U);
      iVar8 = iVar8 + 3;
      iVar6 = iVar6 + 7;
      piVar5 = piVar5 + 1;
      pfVar2 = pfVar2 + 0x1a;
    } while ((int)(iVar7 + 1U) <= DAT_140d7ad24);
  }
  local_1038 = DAT_140d7ad14 * DAT_140d8193c + DAT_140d8195c;
  local_1034 = DAT_140d7ad18 * DAT_140d81940 + DAT_140d81960;
  local_1030 = DAT_140d7ad1c * DAT_140d81944 + DAT_140d81964;
  local_102c = DAT_140d7ad20 * DAT_140d81948 + DAT_140d81968;
  FUN_14023e510(&DAT_140ca5d38,1,1,1);
  FUN_1401ae2f0((longlong)(int)DAT_140ca6140 + 0x140ca6144,&local_1038);
  DAT_140cc3e59 = 1;
  if (DAT_140ca5d24 != 0) {
    pfVar3 = pfVar4;
    if (0xfd < (byte)(DAT_140cccea1 - 1)) {
      DAT_140cccea1 = 0;
      pfVar3 = &local_1038;
    }
    if (DAT_140ca5960 != 0) {
      if (pfVar3 == (float *)0x0) {
        FUN_1401ae370(local_1028,0,0x1000);
        if (DAT_140cccea1 != 0xff) {
          lVar1 = (ulonglong)DAT_140cccea1 * 0x140c;
          local_1018 = *(float *)(&DAT_140ca6154 + lVar1);
          uStack_1014 = *(undefined4 *)(lVar1 + 0x140ca6158);
          uStack_1010 = *(undefined4 *)(lVar1 + 0x140ca615c);
          uStack_100c = *(undefined4 *)(lVar1 + 0x140ca6160);
        }
        pfVar3 = &local_1018;
      }
      if (DAT_1407cd8d4 == 1) {
        FUN_140222aa0(1,pfVar3);
      }
      FUN_1401ae2f0(&DAT_140cc5a74,pfVar3,0x10);
    }
  }
  FUN_14023e510(&DAT_140cb4dc8,1,1,1);
  FUN_1401ae2f0((longlong)(int)DAT_140cb51d0 + 0x140cb51d4,&local_1038);
  DAT_140cc4a59 = 1;
  if (DAT_140ca5d24 != 0) {
    if (0xfd < (byte)(DAT_140ccd1a1 - 1)) {
      DAT_140ccd1a1 = 0;
      pfVar4 = &local_1038;
    }
    if (DAT_140ca5960 != 0) {
      if (pfVar4 == (float *)0x0) {
        FUN_1401ae370(local_1028,0,0x1000);
        if (DAT_140ccd1a1 != 0xff) {
          lVar1 = (ulonglong)DAT_140ccd1a1 * 0x140c;
          local_1018 = *(float *)(&DAT_140cb51e4 + lVar1);
          uStack_1014 = *(undefined4 *)(lVar1 + 0x140cb51e8);
          uStack_1010 = *(undefined4 *)(lVar1 + 0x140cb51ec);
          uStack_100c = *(undefined4 *)(lVar1 + 0x140cb51f0);
        }
        pfVar4 = &local_1018;
      }
      if (DAT_1407cd8d4 == 1) {
        FUN_1402228f0(1,pfVar4);
      }
      FUN_1401ae2f0(&DAT_140cc9698,pfVar4,0x10);
    }
  }
  return;
}


