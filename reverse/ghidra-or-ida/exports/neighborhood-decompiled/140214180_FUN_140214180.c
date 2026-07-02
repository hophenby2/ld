// Function: FUN_140214180 @ 140214180
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140214180(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  HMODULE pHVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined *puVar12;
  longlong lVar13;
  wchar_t *lpLibFileName;
  longlong lVar14;
  undefined1 auStack_23a8 [32];
  undefined8 *local_2388;
  undefined4 local_2378;
  undefined4 local_2374;
  undefined4 local_2370;
  undefined4 local_236c;
  wchar_t *local_2368;
  wchar_t *local_2360 [3];
  undefined4 local_2348;
  undefined8 local_2344;
  undefined4 local_233c;
  undefined4 local_2338;
  undefined1 local_2328 [92];
  undefined4 local_22cc;
  uint local_22a8;
  undefined1 local_2048 [8192];
  ulonglong local_48;
  
  iVar6 = DAT_140889614;
  iVar5 = DAT_140889610;
  uVar4 = DAT_1408895e4;
  uVar3 = DAT_1408895e0;
  uVar2 = DAT_1408895d8;
  iVar1 = DAT_1408895d4;
  iVar9 = DAT_1408895d0;
  uVar10 = DAT_140877de0;
  iVar8 = DAT_14087006c;
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_23a8;
  if (DAT_1408895e8 != (longlong *)0x0) {
    return 0;
  }
  if (DAT_140ca5410 != 0) {
    return 0;
  }
  local_236c = DAT_14086ff60;
  local_2378 = DAT_14086ff64;
  local_2374 = DAT_140877dd8;
  DAT_140ca5410 = 1;
  local_2370 = DAT_140877ddc;
  FUN_1401ae2f0(local_2048,&DAT_140870070,0x2000);
  FUN_1401ae370(&DAT_14086ff60,0,0x197c0);
  DAT_14086ff64 = local_2378;
  DAT_140877dd8 = local_2374;
  DAT_140877ddc = local_2370;
  DAT_14086ff60 = local_236c;
  DAT_14087006c = iVar8;
  DAT_140877de0 = uVar10;
  DAT_1408895d0 = iVar9;
  DAT_1408895d4 = iVar1;
  DAT_1408895d8 = uVar2;
  DAT_1408895e0 = uVar3;
  DAT_1408895e4 = uVar4;
  DAT_140889610 = iVar5;
  DAT_140889614 = iVar6;
  FUN_1401ae2f0(&DAT_140870070,local_2048,0x2000);
  DAT_1408895dc = 1;
  if (DAT_1408895d0 == 0) {
    local_2360[2] = (wchar_t *)0x0;
    local_2360[0] = L"xinput1_3.dll";
    lpLibFileName = L"xinput1_4.dll";
    local_2368 = L"xinput1_4.dll";
    local_2360[1] = L"xinput9_1_0.dll";
    FUN_1401594b0(&DAT_1404b4b40);
    lVar14 = 0;
    pHVar7 = DAT_1408895b8;
    do {
      DAT_1408895b8 = pHVar7;
      DAT_1408895b8 = LoadLibraryW(lpLibFileName);
      if (DAT_1408895b8 != (HMODULE)0x0) {
        FUN_1401594b0(&DAT_1404a74a0);
        DAT_1408895c0 = GetProcAddress(DAT_1408895b8,"XInputGetState");
        DAT_1408895c8 = GetProcAddress(DAT_1408895b8,"XInputSetState");
        goto LAB_140214412;
      }
      lpLibFileName = local_2360[lVar14];
      lVar14 = lVar14 + 1;
      pHVar7 = (HMODULE)0x0;
    } while (lpLibFileName != (LPCWSTR)0x0);
    FUN_1401594b0(&DAT_1404b4b70);
  }
LAB_140214412:
  if (DAT_1408895d4 == 0) {
    FUN_1401594b0(&DAT_1404b4bb8);
    FUN_14015a010();
    if (DAT_1408895dc != 0) {
LAB_140214509:
      if (DAT_1408895e8 == (longlong *)0x0) goto LAB_140214516;
LAB_1402145cb:
      FUN_1401ad850();
      FUN_14019ddc0();
      DAT_1408895f8 = (longlong *)0x0;
      FUN_1401594b0(&DAT_1404b4cf8);
      if (DAT_1408895dc == 1) {
        iVar8 = (**(code **)(*DAT_1408895e8 + 0x18))(DAT_1408895e8,&DAT_140573f28,&DAT_1408895f8,0);
      }
      else {
        local_2388 = (undefined8 *)0x0;
        iVar8 = (**(code **)(*DAT_1408895e8 + 0x48))
                          (DAT_1408895e8,&DAT_140573f28,&DAT_140574008,&DAT_1408895f8);
      }
      if (iVar8 == 0) {
        iVar8 = (**(code **)(*DAT_1408895f8 + 0x58))(DAT_1408895f8,&DAT_140571290);
        if (iVar8 != 0) {
          (**(code **)(*DAT_1408895f8 + 0x10))();
          DAT_1408895f8 = (longlong *)0x0;
          goto LAB_140214844;
        }
        lVar14 = *DAT_1408895f8;
        uVar10 = FUN_1401a6400();
        iVar8 = (**(code **)(lVar14 + 0x68))(DAT_1408895f8,uVar10,10);
        if (iVar8 != 0) {
          (**(code **)(*DAT_1408895f8 + 0x10))();
          DAT_1408895f8 = (longlong *)0x0;
          goto LAB_140214844;
        }
        FUN_1401594b0(&DAT_1404b4c40);
        if (DAT_1408895f8 == (longlong *)0x0) goto LAB_140214844;
      }
      else {
        DAT_1408895f8 = (longlong *)0x0;
LAB_140214844:
        FUN_1401594b0(&DAT_1404b4d18);
      }
      DAT_14086ff68 = (*DAT_140c2b5c8)();
      DAT_140889600 = (longlong *)0x0;
      if (DAT_140889614 == 0) {
        FUN_1401594b0(&DAT_1404b4d40);
        if (DAT_1408895dc == 1) {
          iVar8 = (**(code **)(*DAT_1408895e8 + 0x18))
                            (DAT_1408895e8,&DAT_140573f18,&DAT_140889600,0);
        }
        else {
          local_2388 = (undefined8 *)0x0;
          iVar8 = (**(code **)(*DAT_1408895e8 + 0x48))
                            (DAT_1408895e8,&DAT_140573f18,&DAT_140574008,&DAT_140889600);
        }
        if (iVar8 == 0) {
          iVar8 = (**(code **)(*DAT_140889600 + 0x58))(DAT_140889600,&DAT_140570e10);
          if (iVar8 == 0) {
            lVar14 = *DAT_140889600;
            if (DAT_140889610 == 0) {
LAB_14021492b:
              uVar10 = FUN_1401a6400();
              iVar8 = (**(code **)(lVar14 + 0x68))(DAT_140889600,uVar10,10);
              if (iVar8 != 0) {
                (**(code **)(*DAT_140889600 + 0x10))();
                DAT_140889600 = (longlong *)0x0;
                goto LAB_140214a47;
              }
            }
            else {
              uVar10 = FUN_1401a6400();
              iVar8 = (**(code **)(lVar14 + 0x68))(DAT_140889600,uVar10,5);
              if (iVar8 != 0) {
                lVar14 = *DAT_140889600;
                goto LAB_14021492b;
              }
            }
            local_2348 = 0x14;
            local_2344 = 0x10;
            local_233c = 0;
            local_2338 = 100;
            iVar8 = (**(code **)(*DAT_140889600 + 0x30))(DAT_140889600,1,&local_2348);
            if (iVar8 != 0) {
              FUN_1401594b0(&DAT_1404b4d68);
            }
            uVar10 = (*DAT_140c2b650)(0,1,0);
            uVar11 = (**(code **)(*DAT_140889600 + 0x60))(DAT_140889600,uVar10);
            if ((uVar11 & 0xfffffffd) == 0) {
              DAT_140889608 = uVar10;
              iVar8 = (**(code **)(*DAT_140889600 + 0x38))();
              if ((iVar8 == 0) || (iVar8 = (**(code **)(*DAT_140889600 + 0x38))(), iVar8 == 0)) {
                FUN_1401594b0(&DAT_1404b4c40);
                goto LAB_140214a3e;
              }
              (**(code **)(*DAT_140889600 + 0x10))();
              DAT_140889600 = (longlong *)0x0;
            }
            else {
              FUN_1401594b0(&DAT_1404b4d98);
              (**(code **)(*DAT_140889600 + 0x10))();
              DAT_140889600 = (longlong *)0x0;
            }
          }
          else {
            (**(code **)(*DAT_140889600 + 0x10))();
            DAT_140889600 = (longlong *)0x0;
          }
LAB_140214a47:
          FUN_1401594b0(&DAT_1404b4dd0);
        }
        else {
LAB_140214a3e:
          if (DAT_140889600 == (longlong *)0x0) goto LAB_140214a47;
        }
        DAT_14086ff68 = (*DAT_140c2b5c8)();
      }
      FUN_14015a020();
      puVar12 = &DAT_1404b4e00;
      goto LAB_140214a97;
    }
    FUN_1401594b0(&DAT_1404b4be0);
    local_2388 = &DAT_1408895e8;
    iVar8 = (*DAT_140c2b900)(&DAT_140573ee8,0,1,&DAT_140574048);
    if (iVar8 < 0) {
      FUN_1401594b0(&DAT_1404b4c50);
      FUN_140159b70(&DAT_1404b4c60,iVar8);
      goto LAB_140214509;
    }
    FUN_1401594b0(&DAT_1404a74a0);
    FUN_14015a010();
    FUN_1401594b0(&DAT_1404b4c10);
    lVar14 = *DAT_1408895e8;
    uVar10 = FUN_1401e5560(0);
    iVar8 = (**(code **)(lVar14 + 0x38))(DAT_1408895e8,uVar10,0x700);
    if (-1 < iVar8) {
      FUN_1401594b0(&DAT_1404b4c40);
      FUN_14015a020();
      goto LAB_140214509;
    }
    FUN_1401594b0(&DAT_1404b4c30);
    (**(code **)(*DAT_1408895e8 + 0x10))();
    DAT_1408895e8 = (longlong *)0x0;
LAB_140214516:
    FUN_1401594b0(&DAT_1404b4c80);
    local_2388 = &DAT_1408895e8;
    iVar8 = (*DAT_140c2b900)(&DAT_140573f08,0,1,&DAT_140574038);
    if (iVar8 < 0) {
      FUN_1401594b0(&DAT_1404b4cb8);
    }
    else {
      FUN_1401594b0(&DAT_1404a74a0);
      FUN_14015a010();
      FUN_1401594b0(&DAT_1404b4c10);
      lVar14 = *DAT_1408895e8;
      uVar10 = FUN_1401e5560(0);
      iVar8 = (**(code **)(lVar14 + 0x38))(DAT_1408895e8,uVar10,0x800);
      if (-1 < iVar8) {
        FUN_1401594b0(&DAT_1404b4c40);
        DAT_1408895dc = 1;
        FUN_14015a020();
        goto LAB_1402145cb;
      }
      FUN_1401594b0(&DAT_1404b4c30);
      (**(code **)(*DAT_1408895e8 + 0x10))();
      DAT_1408895e8 = (longlong *)0x0;
    }
    FUN_1401594b0(&DAT_1404b4cc8);
    FUN_14015a020();
    if (DAT_1408895e8 != (longlong *)0x0) {
      (**(code **)(*DAT_1408895e8 + 0x10))();
    }
    DAT_1408895e8 = (longlong *)0x0;
    DAT_1408895d4 = 1;
  }
  FUN_14015a010();
  FUN_1401ad850();
  FUN_14019ddc0();
  iVar8 = 0;
  do {
    FUN_1401ae370(local_2328,0,0x2d8);
    iVar9 = (*DAT_140c2b5e0)(iVar8,local_2328,0x2d8);
    if (iVar9 != 0) break;
    FUN_1401ae370(&DAT_140872ad8 + (longlong)DAT_140872ad4 * 0x530,0,0x530);
    (&DAT_140872bb0)[(longlong)DAT_140872ad4 * 0x14c] = 0xffffffff;
    if (((local_22a8 & 1) == 0) || (iVar9 = 1, (local_22a8 & 2) == 0)) {
      iVar9 = 0;
    }
    iVar8 = iVar8 + 1;
    *(int *)(&DAT_140872bd0 + (longlong)DAT_140872ad4 * 0x530) = iVar9;
    *(uint *)(&DAT_140872bd4 + (longlong)DAT_140872ad4 * 0x530) = local_22a8;
    (&DAT_140872b34)[(longlong)DAT_140872ad4 * 0x14c] = DAT_140877ddc;
    (&DAT_140872b38)[(longlong)DAT_140872ad4 * 0xa6] = DAT_140877de0;
    (&DAT_140872b40)[(longlong)DAT_140872ad4 * 0x14c] = local_22cc;
    DAT_140872ad4 = DAT_140872ad4 + 1;
  } while (iVar8 < 0x10);
  FUN_140159b70(&DAT_1404b4e40,DAT_140872ad4);
  FUN_14015a020();
  puVar12 = &DAT_1404b4e60;
  DAT_1408895e8 = (longlong *)0xffffffff;
LAB_140214a97:
  FUN_1401594b0(puVar12);
  if (DAT_14087006c == 0) {
    DAT_14087006c = 1;
    lVar14 = 0x140870074;
    do {
      lVar13 = 0x20;
      do {
        *(undefined8 *)(lVar14 + -4) = 0xffffffffffffffff;
        lVar14 = lVar14 + 0x10;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
    } while (lVar14 < 0x140872074);
    DAT_140870070._0_4_ = 0x50;
    DAT_140870070._4_4_ = 0xd0;
    DAT_140870080._0_4_ = 0x4b;
    DAT_140870080._4_4_ = 0xcb;
    DAT_140870090._0_4_ = 0x4d;
    DAT_140870090._4_4_ = 0xcd;
    _DAT_1408700a0 = 0x48;
    _DAT_1408700a4 = 200;
    _DAT_1408700b0 = 0x2c;
    _DAT_1408700c0 = 0x2d;
    _DAT_1408700d0 = 0x2e;
    _DAT_1408700e0 = 0x1e;
    _DAT_1408700f0 = 0x1f;
    _DAT_140870100 = 0x20;
    _DAT_140870110 = 0x10;
    _DAT_140870120 = 0x11;
    _DAT_140870130 = 1;
    _DAT_140870140 = 0x39;
  }
  DAT_140ca5410 = 0;
  return 0;
}


