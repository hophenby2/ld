// Function: FUN_14016b4c0 @ 14016b4c0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14016b4c0(void)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  longlong lVar12;
  undefined1 auStack_2b8 [32];
  uint local_298;
  undefined4 local_290;
  uint local_288;
  uint local_280;
  uint local_278;
  undefined4 local_270;
  undefined4 local_268;
  uint local_264;
  uint local_260;
  undefined4 local_25c;
  int local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_2b8;
  if (DAT_140989740 == 0) {
    return 0xffffffff;
  }
  uVar10 = (ulonglong)DAT_1409897a0;
  if (DAT_1409897a0 <= DAT_1409897a4) {
    lVar12 = uVar10 * 8;
    do {
      lVar4 = *(longlong *)(lVar12 + DAT_140989748);
      if (lVar4 != 0) {
        local_25c = *(undefined4 *)(lVar4 + 0x121810);
        uVar11 = *(undefined4 *)(lVar4 + 0x121818);
        uVar9 = *(uint *)(lVar4 + 0x121820);
        local_258 = *(int *)(lVar4 + 0x121814);
        local_254 = *(undefined4 *)(lVar4 + 0x12180c);
        local_268 = uVar11;
        if (*(int *)(lVar4 + 0x90) == 0) {
          FUN_1401aeb80(local_238,0x200,lVar4 + 0x1215cc);
          uVar1 = *(undefined2 *)(lVar4 + 0x1217ce);
          uVar2 = *(ushort *)(lVar4 + 0x1217cc);
          uVar3 = *(undefined4 *)(lVar4 + 0x12181c);
          local_260 = (uint)*(ushort *)(lVar4 + 0x1217d8);
          uVar8 = *(undefined4 *)(lVar4 + 4);
          local_264 = (uint)*(byte *)(lVar4 + 0x1217d4);
          FUN_1401b7e20(uVar8,0,0);
          local_248 = DAT_140818030;
          local_24c = DAT_140818028;
          local_250 = DAT_140818024;
          local_244 = DAT_140818034;
          local_240 = DAT_140818038;
          if ((DAT_14088a630 == 0) && (DAT_14088d698 == 0)) {
            FUN_1401a4ab0();
          }
          iVar5 = FUN_1401b71a0(8,0,uVar8);
          uVar11 = local_268;
          if (iVar5 != -1) {
            local_270 = 0;
            local_278 = local_264;
            local_288 = local_260;
            local_298 = (uint)uVar2;
            local_290 = uVar3;
            local_280 = uVar9;
            iVar6 = FUN_14015a960(&local_250,iVar5,local_238,uVar1);
            uVar11 = local_268;
            if (iVar6 < 0) {
              FUN_1401b7e20(iVar5,0,0);
              uVar11 = local_268;
            }
          }
        }
        else {
          lVar7 = FUN_1401b6390((longlong)*(int *)(lVar4 + 0xa0),
                                "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x6b0);
          if (lVar7 == 0) {
            FUN_140159b70(&DAT_1404a8030);
            goto LAB_14016b7d4;
          }
          FUN_1401ae2f0(lVar7,*(undefined8 *)(lVar4 + 0x98),(longlong)*(int *)(lVar4 + 0xa0));
          uVar3 = *(undefined4 *)(lVar4 + 0xa0);
          uVar8 = *(undefined4 *)(lVar4 + 4);
          FUN_1401b7e20(uVar8,0,0);
          local_248 = DAT_140818030;
          local_24c = DAT_140818028;
          local_250 = DAT_140818024;
          local_244 = DAT_140818034;
          local_240 = DAT_140818038;
          if ((DAT_14088a630 == 0) && (DAT_14088d698 == 0)) {
            FUN_1401a4ab0();
          }
          iVar5 = FUN_1401b71a0(8,0,uVar8);
          if (iVar5 != -1) {
            local_290 = 0;
            local_298 = uVar9;
            iVar6 = FUN_14016c190(&local_250,iVar5,lVar7,uVar3);
            if (iVar6 < 0) {
              FUN_1401b7e20(iVar5,0,0);
            }
          }
          FUN_1401b6700(lVar7);
        }
        FUN_14016d350(local_25c,uVar8);
        if (local_258 != 0) {
          FUN_14016d0b0(uVar11,uVar8);
        }
        FUN_14016cfc0(local_254,uVar8);
      }
LAB_14016b7d4:
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      lVar12 = lVar12 + 8;
    } while ((int)uVar9 <= DAT_1409897a4);
  }
  return 0;
}


