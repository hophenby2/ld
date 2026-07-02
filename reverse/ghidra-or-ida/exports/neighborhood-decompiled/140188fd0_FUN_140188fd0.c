// Function: FUN_140188fd0 @ 140188fd0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140188fd0(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4,int param_5,
             undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  ushort *puVar10;
  int *piVar11;
  undefined1 auStack_5e8 [32];
  uint *local_5c8;
  longlong *local_5c0;
  int *local_5b8;
  undefined4 local_5b0;
  int local_5a8;
  uint local_5a4;
  longlong local_5a0;
  longlong local_598;
  undefined8 local_590;
  int local_588 [2];
  uint local_580;
  undefined4 uStack_57c;
  longlong local_578;
  longlong local_570;
  undefined4 local_568;
  undefined4 uStack_564;
  uint uStack_560;
  undefined4 uStack_55c;
  undefined2 local_558;
  undefined8 local_550;
  undefined8 uStack_548;
  undefined4 local_540;
  undefined4 uStack_53c;
  undefined4 uStack_538;
  undefined4 uStack_534;
  undefined4 local_530;
  undefined4 uStack_52c;
  undefined4 uStack_528;
  undefined4 uStack_524;
  longlong local_520;
  undefined4 local_518 [304];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_5e8;
  local_5a8 = -1;
  iVar4 = FUN_14019e300();
  if ((iVar4 == 0) || (10 < param_5)) {
    return 0xffffffff;
  }
  iVar4 = 0;
  local_518[0] = 0;
  local_520 = 0;
  local_5a0 = 0;
  lVar2 = *(longlong *)(DAT_1409885a0 + (ulonglong)(param_2 & 0x3ffff) * 8);
  if ((*(int *)(param_1 + 0xc) != 0) || (*(int *)(param_1 + 0x14) != 0)) {
    local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,param_7);
    iVar4 = FUN_140187ef0(param_1,0,param_3,param_4);
    if (iVar4 < 0) {
      FUN_140159c40(L"LoadSoundMemByMemImageBase Error 1");
    }
    else {
      local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,param_7);
      iVar5 = FUN_14018d4b0(param_2,param_1,iVar4,param_5);
      if (-1 < iVar5) {
        FUN_1401b7e20(iVar4,0,0);
        return 0;
      }
      FUN_140159c40(L"LoadSoundMemByMemImageBase Error %d",-iVar5);
    }
    goto LAB_1401890e5;
  }
  if (*(int *)(param_1 + 8) == 0) {
    local_578 = -1;
    local_570 = -1;
    local_520 = FUN_140139630(param_3,param_4);
    puVar7 = (undefined8 *)FUN_1401394d0();
    local_550 = *puVar7;
    uStack_548 = puVar7[1];
    local_540 = *(undefined4 *)(puVar7 + 2);
    uStack_53c = *(undefined4 *)((longlong)puVar7 + 0x14);
    uStack_538 = *(undefined4 *)(puVar7 + 3);
    uStack_534 = *(undefined4 *)((longlong)puVar7 + 0x1c);
    local_530 = *(undefined4 *)(puVar7 + 4);
    uStack_52c = *(undefined4 *)((longlong)puVar7 + 0x24);
    uStack_528 = *(undefined4 *)(puVar7 + 5);
    uStack_524 = *(undefined4 *)((longlong)puVar7 + 0x2c);
    local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,*(undefined4 *)(param_1 + 0x4c));
    iVar5 = FUN_140212920(local_518,&local_550,*(undefined4 *)(param_1 + 0x44),
                          *(undefined4 *)(param_1 + 0x48));
    if (iVar5 < 0) {
      puVar9 = &DAT_1404a9058;
    }
    else {
      iVar5 = FUN_140213010(local_518,&local_568,&local_5a0,&local_580);
      if (-1 < iVar5) {
        if (((*(longlong *)(param_1 + 0x20) == *(longlong *)(param_1 + 0x30)) &&
            (*(longlong *)(param_1 + 0x28) == *(longlong *)(param_1 + 0x38))) &&
           (*(int *)(param_1 + 0x40) == 0)) {
          FUN_140212680(local_518,&local_578,&local_570);
        }
        FUN_140213140(local_518);
        FUN_1401359b0(local_520);
        local_520 = 0;
        if ((local_578 < 0) || (local_570 < 0)) {
          if (CONCAT44(uStack_57c,local_580) / (ulonglong)uStack_560 < 0xb5) {
            local_5b8 = (int *)CONCAT44(local_5b8._4_4_,param_7);
            local_5c0 = (longlong *)CONCAT44(local_5c0._4_4_,0xffffffff);
            local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,param_2);
            iVar5 = FUN_140185c70(&local_568,local_580,0,param_5);
            if (iVar5 != -1) {
              *(undefined4 *)(lVar2 + 0x2d7c) = uStack_564;
              puVar8 = (undefined4 *)
                       FUN_1401b6390(4,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",
                                     0x12dd);
              *(undefined4 **)(lVar2 + 0x2cc8) = puVar8;
              if (puVar8 != (undefined4 *)0x0) {
                *(undefined4 *)(lVar2 + 0x17a0) = local_568;
                *(undefined4 *)(lVar2 + 0x17a4) = uStack_564;
                *(uint *)(lVar2 + 0x17a8) = uStack_560;
                *(undefined4 *)(lVar2 + 0x17ac) = uStack_55c;
                *(undefined2 *)(lVar2 + 0x17b0) = local_558;
                *(longlong *)(lVar2 + 0x2cc0) = local_5a0;
                *(uint *)(lVar2 + 0x2cb8) = local_580;
                *puVar8 = 1;
                local_5a0 = 0;
                if (0 < *(int *)(lVar2 + 0x11c)) {
                  piVar11 = (int *)(lVar2 + 0x2cd0);
                  puVar10 = (ushort *)(lVar2 + 0x1b0);
                  do {
                    uVar3 = local_580;
                    if (*piVar11 != 1) {
                      if (*(int *)(puVar10 + -0x20) == 0) {
LAB_1401894a5:
                        FUN_1401594b0(&DAT_1404a8f70);
                        iVar4 = local_5a8;
                        goto LAB_1401890e5;
                      }
                      if ((DAT_140845100 == 0) && (DAT_1408450f8 == 0)) {
                        local_5b8 = local_588;
                        local_5c0 = &local_598;
                        local_5c8 = &local_5a4;
                        iVar5 = FUN_1401a29a0(puVar10 + -0x20,0,local_580,&local_590);
                        if (iVar5 == 2) goto LAB_140189366;
                        if (iVar5 == -1) goto LAB_1401894a5;
                      }
                      else {
LAB_140189366:
                        uVar6 = uVar3 / *puVar10;
                        uVar1 = *(uint *)(puVar10 + -8);
                        local_590 = **(undefined8 **)(puVar10 + 8);
                        if (uVar1 < uVar6) {
                          local_5a4 = *puVar10 * uVar1;
                          local_598 = **(longlong **)(puVar10 + 8);
                          local_588[0] = (uVar6 - uVar1) * (uint)*puVar10;
                        }
                        else {
                          local_5a4 = uVar3;
                          local_598 = 0;
                          local_588[0] = 0;
                        }
                      }
                      FUN_1401ae2f0(local_590,*(undefined8 *)(lVar2 + 0x2cc0),local_5a4);
                      if (local_598 != 0) {
                        FUN_1401ae2f0(local_598,(ulonglong)local_5a4 + *(longlong *)(lVar2 + 0x2cc0)
                                      ,local_588[0]);
                      }
                      local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,local_588[0]);
                      iVar5 = FUN_14018ebb0((longlong)iVar4 * 0x238 + 0x170 + lVar2,local_590,
                                            local_5a4,local_598);
                      if (iVar5 != 0) {
                        FUN_1401594b0(&DAT_1404a8f98);
                        iVar4 = local_5a8;
                        goto LAB_1401890e5;
                      }
                    }
                    iVar4 = iVar4 + 1;
                    piVar11 = piVar11 + 1;
                    puVar10 = puVar10 + 0x11c;
                  } while (iVar4 < *(int *)(lVar2 + 0x11c));
                }
                goto LAB_140189444;
              }
              puVar9 = &DAT_1404a90c0;
              goto LAB_1401890db;
            }
          }
        }
        else {
          *(longlong *)(param_1 + 0x28) = local_578;
          *(longlong *)(param_1 + 0x38) = local_570;
        }
        if (local_5a0 != 0) {
          FUN_1401b6700();
          local_5a0 = 0;
        }
        *(undefined4 *)(param_1 + 8) = 2;
        goto LAB_1401891c2;
      }
      puVar9 = &DAT_1404a9088;
    }
LAB_1401890db:
    FUN_140159b70(puVar9);
    iVar4 = local_5a8;
  }
  else {
LAB_1401891c2:
    local_5b0 = param_7;
    local_5b8 = (int *)CONCAT44(local_5b8._4_4_,param_6);
    local_5c0 = (longlong *)CONCAT44(local_5c0._4_4_,*(undefined4 *)(param_1 + 8));
    local_5c8 = (uint *)CONCAT44(local_5c8._4_4_,param_2);
    iVar5 = FUN_140183620(param_1,param_3,param_4,0);
    iVar4 = local_5a8;
    if (iVar5 != -1) {
      FUN_14018d950(param_2,param_7);
LAB_140189444:
      if ((*(longlong *)(param_1 + 0x20) == *(longlong *)(param_1 + 0x30)) ||
         (*(int *)(param_1 + 0x40) != 0)) {
        if ((*(longlong *)(param_1 + 0x28) != *(longlong *)(param_1 + 0x38)) &&
           (*(int *)(param_1 + 0x40) == 0)) {
          FUN_14018bf00(*(longlong *)(param_1 + 0x28),*(longlong *)(param_1 + 0x38),param_2,param_7)
          ;
        }
      }
      else {
        FUN_14018bf70(*(longlong *)(param_1 + 0x20),*(longlong *)(param_1 + 0x30),param_2,param_7);
      }
      return 0;
    }
  }
LAB_1401890e5:
  if (local_5a0 != 0) {
    FUN_1401b6700();
  }
  if (local_520 != 0) {
    FUN_1401359b0();
  }
  if (-1 < iVar4) {
    FUN_1401b7e20(iVar4,0,0);
  }
  FUN_140213140(local_518);
  return 0xffffffff;
}


