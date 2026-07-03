// Function: game_startup_init_candidate @ 1400f4f70
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 game_startup_init_candidate(void)

{
  ulonglong *puVar1;
  int iVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  double dVar10;
  char cVar11;
  uint uVar12;
  errno_t eVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  longlong lVar18;
  ulonglong *puVar19;
  undefined8 *puVar20;
  longlong *plVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  longlong lVar25;
  undefined8 uVar26;
  int iVar27;
  undefined8 uVar28;
  char *pcVar29;
  int *piVar30;
  int iVar31;
  bool bVar32;
  double dVar33;
  double dVar34;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  longlong local_e8;
  undefined8 local_e0;
  int local_d8;
  int local_d4;
  int local_d0 [2];
  undefined8 local_c8;
  undefined8 local_c0;
  ulonglong local_b8;
  
  local_b8 = DAT_1407c6b00 ^ (ulonglong)auStack_138;
  FUN_1401ad140(0);
  iVar31 = 0;
  lVar18 = FUN_1401ad140(0);
  local_c8 = 0;
  local_c0 = 0;
  local_e8 = lVar18;
  cVar11 = SteamAPI_RestartAppIfNecessary(0x1c7fdc);
  if (cVar11 != '\0') {
LAB_1400f4fe8:
    MessageBoxA((HWND)0x0,"Failed to initialize SteamAPI.","errer",0);
    return 1;
  }
  cVar11 = SteamAPI_Init();
  if (cVar11 == '\0') {
    FUN_1400f4ee0(
                 "Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed).\n"
                 );
    goto LAB_1400f4fe8;
  }
  puVar19 = operator_new(0x78);
  *puVar19 = 0;
  puVar19[1] = 0;
  puVar19[2] = 0;
  puVar19[3] = 0;
  puVar19[4] = 0;
  puVar19[5] = 0;
  puVar19[6] = 0;
  puVar19[7] = 0;
  puVar19[8] = 0;
  puVar19[9] = 0;
  puVar19[10] = 0;
  puVar19[0xb] = 0;
  puVar19[0xc] = 0;
  puVar19[0xd] = 0;
  puVar19[0xe] = 0;
  *(undefined1 *)(puVar19 + 4) = 0;
  puVar19[3] = (ulonglong)CCallback<CSteamAchievements,UserStatsReceived_t,0>::vftable;
  puVar19[6] = (ulonglong)FUN_14012cf80;
  *(undefined4 *)((longlong)puVar19 + 0x24) = 0;
  puVar19[5] = (ulonglong)puVar19;
  SteamAPI_RegisterCallback(puVar19 + 3,0x44d);
  *(undefined1 *)(puVar19 + 8) = 0;
  puVar19[7] = (ulonglong)CCallback<CSteamAchievements,UserStatsStored_t,0>::vftable;
  puVar19[10] = (ulonglong)FUN_14012d100;
  *(undefined4 *)((longlong)puVar19 + 0x44) = 0;
  puVar19[9] = (ulonglong)puVar19;
  SteamAPI_RegisterCallback(puVar19 + 7,0x44e);
  *(undefined1 *)(puVar19 + 0xc) = 0;
  puVar19[0xb] = (ulonglong)CCallback<CSteamAchievements,UserAchievementStored_t,0>::vftable;
  puVar19[0xe] = (ulonglong)&LAB_14012d170;
  *(undefined4 *)((longlong)puVar19 + 100) = 0;
  puVar19[0xd] = (ulonglong)puVar19;
  SteamAPI_RegisterCallback(puVar19 + 0xb,0x44f);
  puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc760);
  uVar12 = (**(code **)(*(longlong *)*puVar20 + 0x48))();
  *(undefined4 *)(puVar19 + 2) = 0x32;
  *puVar19 = (ulonglong)uVar12;
  puVar19[1] = (ulonglong)&DAT_1407c77b0;
  plVar21 = (longlong *)SteamInternal_ContextInit(&PTR_FUN_1407cc790);
  if ((*plVar21 != 0) &&
     (plVar21 = (longlong *)SteamInternal_ContextInit(&PTR_FUN_1407cc778), *plVar21 != 0)) {
    puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc778);
    cVar11 = (**(code **)(*(longlong *)*puVar20 + 8))();
    if (cVar11 != '\0') {
      puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc790);
      (*(code *)**(undefined8 **)*puVar20)();
    }
  }
  DAT_140e9fda0 = puVar19;
  FUN_1401a9580("NowLoading...");
  eVar13 = fopen_s((FILE **)&local_e0,"save\\save.dat","rb");
  if (eVar13 == 0) {
    fread(&DAT_140e41b10,0x2730,1,(FILE *)CONCAT44(local_e0._4_4_,(int)local_e0));
    FUN_140323e90(CONCAT44(local_e0._4_4_,(int)local_e0));
    if ((DAT_140e41b10 != 200) &&
       (((99 < DAT_140e41b10 || (FUN_1400d0aa0(), 99 < DAT_140e41b10)) && (DAT_140e41b10 < 200)))) {
      DAT_140e43f58 = DAT_140e43f74;
      DAT_140e43f5c = DAT_140e43f78;
      DAT_140e43f68 = DAT_140e43f7c;
      _DAT_140e43fb8 = 0;
      _DAT_140e43fc0 = 0;
      uRam0000000140e43fc8 = 0;
      DAT_140e43f54 = 0;
      _DAT_140e43f60 = 0;
      DAT_140e41b10 = 200;
    }
  }
  else {
    fopen_s((FILE **)&local_e0,"save\\save.dat","wb");
    FUN_1400d0aa0();
    FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(local_e0._4_4_,(int)local_e0));
    FUN_140323e90(CONCAT44(local_e0._4_4_,(int)local_e0));
  }
  eVar13 = fopen_s((FILE **)&local_e0,"save\\config.dat","rb");
  if (eVar13 == 0) {
    fread(&DAT_140e468f0,0x1c,1,(FILE *)CONCAT44(local_e0._4_4_,(int)local_e0));
  }
  else {
    fopen_s((FILE **)&local_e0,"save\\config.dat","wb");
    _DAT_140e46900 = 1;
    _DAT_140e468f0 = _DAT_14053b4e0;
    _DAT_140e468f8 = _UNK_14053b4e8;
    DAT_140e46908 = 0;
    FUN_140327c78(&DAT_140e468f0,0x1c,1,CONCAT44(local_e0._4_4_,(int)local_e0));
  }
  FUN_140323e90(CONCAT44(local_e0._4_4_,(int)local_e0));
  if (DAT_140e41b10 != 200) {
    FUN_1400d0aa0();
  }
  if (DAT_140e46908 == 1) {
    uVar28 = 0;
    uVar26 = 1;
  }
  else if (DAT_140e46908 == 2) {
    uVar28 = 1;
    uVar26 = 1;
  }
  else {
    if (DAT_140e46908 != 3) goto LAB_1400f5373;
    uVar28 = 1;
    uVar26 = 0;
  }
  FUN_1401a2030(uVar26,uVar28,0xffffffff,0xac44);
LAB_1400f5373:
  FUN_14015a140(0);
  local_f0 = 0;
  local_f8 = 0;
  local_100 = 0;
  local_108 = 0;
  local_110 = 0;
  local_118 = 0;
  FUN_1401a6170(&local_d4,&local_d8,0,0);
  FUN_1401a3fe0(1);
  FUN_140157620(local_d4,local_d8,0x20,0x3c);
  FUN_1401a9cb0(0,0);
  FUN_1401a9c00(0x500,0x2d0);
  FUN_1401a98f0((local_d4 + -0x500) / 2,
                (int)((local_d8 + -0x2d0 >> 0x1f & 3U) + local_d8 + -0x2d0) >> 2);
  FUN_1401589c0(_DAT_140e468f8 & 0xffffffff);
  FUN_1401adf50(0xfde9);
  iVar14 = FUN_14019d470();
  if (iVar14 != -1) {
    FUN_1401a9400(FUN_1400f4f40,0);
    uVar15 = FUN_140155d40(0x500,0x2d0,0);
    FUN_1401a9420(1);
    FUN_140156d60(0xfffffffe);
    FUN_14013a330(0);
    dxarchive_set_key_candidate("VanillaFever11");
    FUN_1401aeeb0(1);
    DAT_140e41ab8 = dxlib_load_graph_candidate("media\\system\\WhiteBack.png",0);
    if (((DAT_140e41ab8 != -1) &&
        (DAT_140e46ecc = dxlib_load_graph_candidate("media\\system\\starting.png",0),
        DAT_140e46ecc != -1)) &&
       ((DAT_140e470c8 = dxlib_load_graph_candidate("media\\system\\NowLoading.png",0),
        DAT_140e470c8 != -1 && (iVar14 = load_primary_resources_candidate(), iVar14 != -1)))) {
      iVar16 = FUN_14019d4b0();
      dVar10 = DAT_14053b1a0;
      dVar8 = DAT_14053a9d8;
      dVar7 = DAT_14053a798;
      dVar6 = DAT_14053a2d8;
      dVar5 = DAT_14053a1e8;
      dVar4 = DAT_14053a020;
      dVar34 = DAT_140539d28;
      iVar14 = iVar31;
      while ((iVar16 == 0 && (iVar16 = FUN_1401afad0(), 0 < iVar16))) {
        FUN_14013db30(0,0,DAT_140e46ecc,0);
        dVar33 = (double)FUN_140332d90(((double)iVar14 - dVar5) * dVar8 * dVar4 * dVar34);
        FUN_140156bc0(1,0xa0 - (int)(dVar33 * dVar10));
        iVar16 = 0x280;
        if (iVar14 % 0x3c < 0x3d) {
          dVar33 = (double)FUN_140332d90(((double)(iVar14 % 0x3c) - 0.0) * dVar7 * dVar4 * dVar34);
          iVar16 = 0x280 - (int)(dVar33 * dVar6);
        }
        if (iVar14 % 0xf0 < 0x78) {
          iVar22 = (2 - iVar14 / 0xf0) * 0xf0 + iVar14;
        }
        else {
          iVar22 = (iVar14 / 0xf0 + 3) * 0xf0 - iVar14;
        }
        FUN_14013db30(iVar22,iVar16,DAT_140e470c8,1);
        FUN_140156bc0();
        thunk_FUN_140153110();
        iVar14 = iVar14 + 1;
        iVar16 = FUN_14019d4b0();
      }
      FUN_1401aeeb0(0);
      FUN_1401a9580("LIKE DREAMER");
      if (DAT_140e468f0 == 1) {
        DAT_140e418c4 = 1;
      }
      lVar25 = 4;
      puVar20 = (undefined8 *)&DAT_140e46c90;
      do {
        *puVar20 = 0;
        puVar20[1] = 0;
        puVar20[2] = 0;
        puVar20[3] = 0;
        puVar20[4] = 0;
        puVar20[5] = 0;
        puVar20[6] = 0;
        puVar20[7] = 0;
        puVar20[8] = 0;
        puVar20[9] = 0;
        puVar20[10] = 0;
        puVar20[0xb] = 0;
        puVar20[0xc] = 0;
        puVar20[0xd] = 0;
        puVar20[0xe] = 0;
        puVar20[0xf] = 0;
        lVar25 = lVar25 + -1;
        puVar20 = puVar20 + 0x10;
      } while (lVar25 != 0);
      thunk_FUN_1401a65a0(&local_c8,(longlong)&local_c8 + 4);
      _DAT_140e418c0 = FUN_1401ad0e0(0);
      _DAT_140e418c0 = _DAT_140e418c0 & 0x7fffffff;
      iVar14 = FUN_1401ad0e0(0);
      dVar34 = (double)iVar14;
      iVar16 = FUN_14019d4b0();
      fVar9 = DAT_14053afb0;
      dVar4 = DAT_14053a250;
      fVar3 = DAT_140539cd0;
      iVar14 = iVar31;
      do {
        lVar25 = DAT_140e46ea0;
        if (iVar16 != 0) {
          while (lVar25 != 0) {
            lVar25 = *(longlong *)(lVar25 + 0x38);
            FUN_140323ce8();
          }
          DAT_140e46ea0 = 0;
          DAT_140e9fd38 = 0;
          DAT_140e4764c = 0;
          lVar18 = DAT_140e46e90;
          while (lVar18 != 0) {
            lVar18 = *(longlong *)(lVar18 + 0x28);
            FUN_140323ce8();
          }
          DAT_140e46e90 = 0;
          DAT_140e46e98 = 0;
          DAT_140e46c5c = 0;
          stage_entity_flush_effects_candidate();
          stage_pending_effect_flush_candidate();
          lVar18 = DAT_140e45d78;
          while (lVar18 != 0) {
            lVar18 = *(longlong *)(lVar18 + 0x58);
            FUN_140323ce8();
          }
          DAT_140e45d78 = 0;
          DAT_140e45d28 = 0;
          DAT_140e45d1c = 0;
          lVar18 = DAT_140e45278;
          while (lVar18 != 0) {
            lVar18 = *(longlong *)(lVar18 + 8);
            FUN_140323ce8();
          }
          DAT_140e45278 = 0;
          DAT_140e9fd00 = 0;
          FUN_14019d3b0();
          SteamAPI_Shutdown();
          puVar19 = DAT_140e9fda0;
          if (DAT_140e9fda0 != (ulonglong *)0x0) {
            puVar1 = DAT_140e9fda0 + 0xc;
            DAT_140e9fda0[0xb] = (ulonglong)CCallbackImpl<152>::vftable;
            if ((*puVar1 & 1) != 0) {
              SteamAPI_UnregisterCallback();
            }
            puVar19[7] = (ulonglong)CCallbackImpl<16>::vftable;
            if ((puVar19[8] & 1) != 0) {
              SteamAPI_UnregisterCallback();
            }
            puVar19[3] = (ulonglong)CCallbackImpl<24>::vftable;
            if ((puVar19[4] & 1) != 0) {
              SteamAPI_UnregisterCallback();
            }
            thunk_FUN_140323ce8(puVar19,0x78);
          }
          return 0;
        }
        uVar12 = FUN_14019d970(1);
        iVar16 = FUN_14019d900(0x3e);
        if ((iVar16 == 1) && (DAT_140e418c4 == 0)) {
          bVar32 = DAT_140e468f0 != 1;
          _DAT_140e468f0 = CONCAT44(DAT_140e468f4,(uint)bVar32);
          DAT_140e418c4 = 1;
          uVar23 = (uint)bVar32;
LAB_1400f57df:
          if (uVar23 == 0) {
            FUN_1401aa890(0,1);
            FUN_1401a98f0((local_d4 + -0x500) / 2,
                          (int)((local_d8 + -0x2d0 >> 0x1f & 3U) + local_d8 + -0x2d0) >> 2);
            iVar16 = 0x2d0;
            iVar22 = 0x500;
          }
          else {
            FUN_1401a66b0(&local_e0,0,local_d0,0);
            FUN_1401aa890(3,1);
            FUN_1401a98f0(-(int)local_e0,-local_d0[0]);
            iVar16 = local_d8;
            iVar22 = local_d4;
          }
          FUN_1401a9c00(iVar22,iVar16);
        }
        else {
          uVar23 = DAT_140e468f0;
          if (DAT_140e418c4 == 1) goto LAB_1400f57df;
        }
        iVar16 = FUN_14019d900(0x3e);
        if (iVar16 != 1) {
          DAT_140e418c4 = 0;
        }
        DAT_140e474e8 = 0;
        do {
          FUN_140156d60(uVar15);
          main_state_dispatcher_candidate();
          FUN_140156d60(0xfffffffe);
          if ((((DAT_140e41b00 != 1) || (DAT_140e45270 != 0x14)) ||
              (((DAT_140e44210 & uVar12) == 0 &&
               (iVar16 = FUN_14019d900(DAT_140e441e0), iVar16 == 0)))) &&
             (((DAT_140e45270 != 0x2c || ((&DAT_140e441c0)[DAT_140e445c0] != 1)) ||
              (((DAT_140e44214 & uVar12) == 0 &&
               (iVar16 = FUN_14019d900(DAT_140e441e4), iVar16 == 0)))))) break;
          DAT_140e474e8 = DAT_140e474e8 + 1;
        } while (DAT_140e474e8 != 6);
        iVar22 = local_d4;
        iVar16 = local_d8;
        if (DAT_140e468f0 == 0) {
          FUN_140156d20(1);
          FUN_14013db30(0,0,uVar15);
        }
        else {
          iVar2 = (local_d8 * 0x500) / 0x2d0;
          if (iVar2 < local_d4) {
            uVar17 = FUN_14017a940(0,0,0);
            local_108._0_4_ = 1;
            local_110._0_4_ = 1;
            local_118._0_4_ = uVar17;
            FUN_14013ac60(0,0,(local_d4 - iVar2) / 2,local_d8);
            uVar17 = FUN_14017a940(0,0,0);
            local_118 = CONCAT44(local_118._4_4_,uVar17);
            iVar24 = local_d4 - (local_d4 - iVar2) / 2;
            iVar27 = 0;
            iVar22 = iVar2;
LAB_1400f5a6e:
            local_108 = CONCAT44(local_108._4_4_,1);
            local_110 = CONCAT44(local_110._4_4_,1);
            FUN_14013ac60(iVar24,iVar27,local_d4,local_d8);
          }
          else {
            iVar16 = (local_d4 * 0x2d0) / 0x500;
            if (iVar16 != local_d8) {
              uVar17 = FUN_14017a940(0,0,0);
              local_108._0_4_ = 1;
              local_110._0_4_ = 1;
              local_118._0_4_ = uVar17;
              FUN_14013ac60(0,0,local_d4,(local_d8 - iVar16) / 2);
              uVar17 = FUN_14017a940(0,0,0);
              local_118 = CONCAT44(local_118._4_4_,uVar17);
              iVar27 = local_d8 - (local_d8 - iVar16) / 2;
              iVar24 = 0;
              goto LAB_1400f5a6e;
            }
          }
          FUN_140156d20(1);
          local_110 = local_110 & 0xffffffff00000000;
          local_118 = CONCAT44(local_118._4_4_,uVar15);
          iVar22 = (local_d4 - iVar22) / 2;
          FUN_14013cea0(iVar22,(local_d8 - iVar16) / 2,local_d4 - iVar22);
        }
        thunk_FUN_140153110();
        thunk_FUN_1401a65a0(&local_c0);
        if ((int)local_c8 == (int)local_c0) {
          if (local_c8._4_4_ != local_c0._4_4_) goto LAB_1400f5b07;
          iVar14 = iVar14 + 1;
          if (iVar14 == 0x3c) {
            uVar26 = 0;
            goto LAB_1400f5b1e;
          }
        }
        else {
LAB_1400f5b07:
          thunk_FUN_1401a65a0(&local_c8);
          uVar26 = 1;
          iVar14 = 0;
LAB_1400f5b1e:
          FUN_1401a9790(uVar26);
        }
        dVar34 = dVar34 + dVar4;
        iVar16 = FUN_1401ad0e0(0);
        if ((double)iVar16 < dVar34) {
          iVar16 = FUN_1401ad0e0(0);
          FUN_1401aeec0((int)dVar34 - iVar16);
        }
        lVar25 = FUN_1401ad140(0);
        iVar31 = iVar31 + 1;
        if (1000000 < lVar25 - lVar18) {
          DAT_140e468c4 = iVar31;
          local_e8 = lVar25;
          iVar31 = 0;
        }
        uVar12 = FUN_1401ad0e0(0);
        uVar12 = uVar12 & 0x7fffffff;
        _DAT_1407c7778 = (float)(int)(uVar12 - _DAT_140e418c0) / fVar9;
        if (fVar3 < _DAT_1407c7778) {
          _DAT_1407c7778 = 0.03;
        }
        _DAT_140e418c0 = uVar12;
        if ((DAT_140e45f68 != 0) || (DAT_140e451bc < 0x3c)) {
          if (DAT_140e9fda0 != (ulonglong *)0x0) {
            piVar30 = &DAT_140e43fe4;
            lVar18 = 0x32;
            pcVar29 = "ACH_00";
            do {
              if ((*piVar30 == 1) && (*(char *)((longlong)DAT_140e9fda0 + 0x14) != '\0')) {
                puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc790);
                (**(code **)(*(longlong *)*puVar20 + 0x38))((longlong *)*puVar20,pcVar29);
                puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc790);
                (**(code **)(*(longlong *)*puVar20 + 0x50))();
              }
              puVar20 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1407cc790);
              (**(code **)(*(longlong *)*puVar20 + 0x68))((longlong *)*puVar20,pcVar29,0);
              pcVar29 = pcVar29 + 10;
              piVar30 = piVar30 + 1;
              lVar18 = lVar18 + -1;
            } while (lVar18 != 0);
          }
          SteamAPI_RunCallbacks();
          if (0 < DAT_140e45f68) {
            DAT_140e45f68 = DAT_140e45f68 + -1;
          }
          if (DAT_140e45f68 < 0) {
            DAT_140e45f68 = 0;
          }
        }
        iVar16 = FUN_14019d4b0();
        lVar18 = local_e8;
      } while( true );
    }
    MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
  }
  return 0xffffffff;
}


