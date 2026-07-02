// Function: FUN_14019e850 @ 14019e850
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14019e850(void)

{
  double dVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  HKEY pHVar9;
  HMODULE hModule;
  FARPROC pFVar10;
  wchar_t *pwVar11;
  undefined *puVar12;
  short sVar13;
  undefined4 *puVar14;
  longlong lVar15;
  undefined *puVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  longlong *plVar19;
  ulonglong uVar20;
  HKEY *ppHVar21;
  undefined *puVar22;
  ulonglong uVar23;
  uint uVar24;
  undefined1 auStack_1d88 [32];
  HKEY *local_1d68;
  longlong *local_1d60;
  undefined4 *local_1d58;
  undefined4 *local_1d50;
  uint local_1d34;
  wchar_t *local_1d30;
  longlong local_1d28;
  HKEY local_1d20 [5];
  longlong *local_1cf8;
  HKEY local_1cf0;
  HKEY local_1ce8;
  HKEY local_1ce0;
  HKEY local_1cd8;
  longlong *local_1cd0;
  undefined8 local_1cc8;
  longlong local_1cc0;
  undefined4 local_1cb8;
  uint local_1cb4;
  int local_1cb0;
  undefined4 *local_1ca8;
  undefined4 local_1c88;
  uint local_1c84;
  uint local_1c80;
  uint local_1c7c;
  uint local_1c44;
  uint local_1c40;
  undefined4 local_1c28;
  undefined4 local_1c24;
  int local_1c18;
  undefined4 local_1be8 [6];
  int local_1bd0;
  undefined1 local_1bb4 [268];
  undefined4 local_1aa8;
  undefined4 local_1aa4;
  undefined4 local_1aa0;
  uint local_1a9c;
  int local_1a98;
  undefined4 local_1a94;
  double local_1a88;
  undefined4 local_1a80;
  undefined4 local_1a7c;
  undefined4 local_1a78;
  undefined4 local_1a74;
  undefined4 local_1a70;
  uint local_1a6c;
  undefined2 local_1a60;
  short local_1a5e;
  uint local_1a5c;
  int local_1a58;
  ushort local_1a54;
  short local_1a52;
  undefined4 local_1a48;
  undefined4 local_1a44;
  undefined4 local_1a40;
  undefined4 local_1a3c;
  undefined4 local_1a34;
  undefined1 local_1a20 [16];
  undefined4 local_1a10;
  uint local_1a0c;
  undefined1 local_19e8 [512];
  undefined1 local_17e8 [518];
  ushort local_15e2;
  undefined4 local_15e0;
  undefined2 local_15d6;
  uint local_15d0;
  byte local_15b8 [592];
  undefined1 local_1368 [256];
  undefined2 local_1268;
  HKEY local_1258 [64];
  HKEY local_1058 [64];
  HKEY local_e58 [64];
  HKEY local_c58 [128];
  undefined1 local_858 [2048];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_1d88;
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  fVar2 = DAT_14053afb0;
  dVar1 = DAT_1404abe38;
  if (DAT_140865b70 != (longlong *)0x0) {
    return 0xffffffff;
  }
  uVar23 = 0;
LAB_14019e91d:
  do {
    lVar15 = 2;
    plVar19 = &DAT_14086f298;
    if (DAT_14084509c != 0) {
      if ((DAT_14084509c < 1) || (2 < DAT_14084509c)) goto LAB_1401a033d;
      DAT_14086f310 = 0;
      FUN_1401594b0(&DAT_1404ab758);
      local_1d68 = (HKEY *)&DAT_140865b28;
      iVar3 = (*DAT_140c2b900)(&DAT_140572538,0,3,&DAT_140572588);
      if (iVar3 < 0) {
        FUN_1401594b0(&DAT_1404ab790);
        FUN_1401594b0(&DAT_1404ab7e0);
        DAT_14084509c = 0;
      }
      else {
        local_1d68 = (HKEY *)&DAT_140865b30;
        iVar3 = (*DAT_140c2b900)(&DAT_140572528,0,3,&DAT_140572598);
        if (-1 < iVar3) {
          local_1d68 = (HKEY *)&local_1cf8;
          iVar3 = (*DAT_140c2b900)(&DAT_140572518,0,1,&DAT_140572578);
          if (iVar3 < 0) {
            FUN_1401594b0(&DAT_1404ab868);
            FUN_14018ff70();
            return 0xffffffff;
          }
          iVar3 = (**(code **)*local_1cf8)(local_1cf8,&DAT_1405725a8,&local_1cd0);
          if (iVar3 < 0) {
            (**(code **)(*local_1cf8 + 0x10))();
            FUN_1401594b0(&DAT_1404ab8a8);
            FUN_14018ff70();
            return 0xffffffff;
          }
          FUN_1401ae370(local_1be8,0,0x134);
          local_1be8[0] = 0x134;
          iVar3 = (**(code **)(*local_1cd0 + 0x18))(local_1cd0,0,local_1be8);
          uVar8 = uVar23;
          while (iVar3 != 1) {
            FUN_1401aeb80(local_1368,0x106,local_1bb4);
            pwVar11 = L"Input port";
            local_1268 = 0;
            if (local_1bd0 == 1) {
              pwVar11 = L"Output port";
            }
            FUN_140159c40(L"%s  Device%d:%s ",pwVar11,uVar8,local_1368);
            uVar8 = (ulonglong)((int)uVar8 + 1);
            iVar3 = (**(code **)(*local_1cd0 + 0x18))(local_1cd0,uVar8,local_1be8);
          }
          (**(code **)(*local_1cd0 + 0x10))();
          (**(code **)(*local_1cf8 + 0x10))();
          FUN_1401ae370(&local_1a48,0,0x28);
          local_1d50 = &local_1a48;
          uVar5 = 1;
          if (DAT_14084509c == 2) {
            uVar5 = 8;
          }
          local_1a48 = 0x28;
          local_1a44 = 1;
          local_1a40 = 5;
          local_1a34 = 0xac44;
          local_1a3c = 0x3f;
          DAT_140865b70 = (longlong *)0x0;
          local_1cf8 = (longlong *)0x0;
          local_1d58 = (undefined4 *)CONCAT44(local_1d58._4_4_,0x3f);
          local_1d60 = (longlong *)CONCAT44(local_1d60._4_4_,0x40);
          local_1d68 = (HKEY *)CONCAT44(local_1d68._4_4_,uVar5);
          iVar3 = (**(code **)(*DAT_140865b30 + 0x160))(DAT_140865b30,&local_1cf8,&DAT_140865b70,0);
          if (iVar3 != 0) {
            FUN_1401594b0(&DAT_1404ab940);
            FUN_14018ff70();
            return 0xffffffff;
          }
          (**(code **)(*DAT_140865b30 + 0x108))(DAT_140865b30,&DAT_1405724d8,&DAT_1408450a4,4);
          goto LAB_1401a033d;
        }
        if (DAT_140865b28 != (longlong *)0x0) {
          (**(code **)(*DAT_140865b28 + 0x10))();
          DAT_140865b28 = (longlong *)0x0;
        }
        FUN_1401594b0(&DAT_1404ab810);
        DAT_14084509c = 0;
      }
      goto LAB_14019e91d;
    }
    if (DAT_14086f318 == 0) {
      if (DAT_14086f31c == 0) {
        if (DAT_14086f314 == 0) break;
        if (DAT_14086f310 == 0) {
          FUN_1401594b0(&DAT_1404ab5b0);
          FUN_1401594b0(&DAT_1404ab5e0);
          local_1d68 = (HKEY *)&DAT_140865b70;
          iVar3 = (*DAT_140c2b900)(&DAT_140572508,0,0x17,&DAT_140572558);
          if (iVar3 < 0) {
            DAT_140865b70 = (longlong *)0x0;
            FUN_1401594b0(&DAT_1404ab628);
            return 0xffffffff;
          }
          FUN_1401594b0(&DAT_1404a74a0);
          FUN_1401594b0(&DAT_1404ab4e0);
          iVar3 = (**(code **)(*DAT_140865b70 + 0x50))(DAT_140865b70,0);
          if (iVar3 < 0) {
            FUN_1401594b0(&DAT_1404ab3f8);
            FUN_140159ab0(&DAT_1404ab410,iVar3);
            (**(code **)(*DAT_140865b70 + 0x10))();
            DAT_140865b70 = (longlong *)0x0;
            return 0xffffffff;
          }
          FUN_1401594b0(&DAT_1404a74a0);
          lVar15 = *DAT_140865b70;
          uVar6 = (*DAT_140c2b9e0)();
          iVar3 = (**(code **)(lVar15 + 0x30))(DAT_140865b70,uVar6,2);
          if (iVar3 == 0) {
            FUN_1401ae370(&local_1a10,0,0x28);
            local_1a10 = 0x28;
            local_1a0c = -(uint)(DAT_14086f320 != 0) & 8 | 1;
            iVar3 = (**(code **)(*DAT_140865b70 + 0x18))(DAT_140865b70,&local_1a10,&DAT_14086f300,0)
            ;
            if (iVar3 == 0) {
              FUN_1401ae370(&local_1c88,0,0x60);
              local_1c88 = 0x60;
              (**(code **)(*DAT_140865b70 + 0x20))(DAT_140865b70,&local_1c88);
              local_1a5e = ((local_1c84 & 2) != 0) + 1;
              local_1a5c = 0xac44;
              if (local_1c7c < 0xac44) {
                local_1a5c = local_1c7c;
              }
              sVar13 = ((local_1c84 & 8) != 0) + 1;
              FUN_1401ae370(&local_1a60,0,0x12);
              local_1a52 = sVar13 * 8;
              local_1a60 = 1;
              local_1a54 = sVar13 * local_1a5e;
              local_1a58 = local_1a54 * local_1a5c;
              iVar3 = (**(code **)(*DAT_14086f300 + 0x70))(DAT_14086f300,&local_1a60);
              if (iVar3 != 0) {
                FUN_1401594b0(&DAT_1404ab700);
              }
              goto LAB_1401a033d;
            }
            puVar16 = &DAT_1404ab6b0;
          }
          else {
            puVar16 = &DAT_1404ab668;
          }
          FUN_1401594b0(puVar16);
          (**(code **)(*DAT_140865b70 + 0x10))();
          DAT_140865b70 = (longlong *)0x0;
          return 0xffffffff;
        }
        local_1d30 = L"X3DAudio1_7.dll";
        local_1d28 = 0;
        local_1d20[2] = (HKEY)0x0;
        local_1d20[3] = (HKEY)0x0;
        local_1d20[0] = (HKEY)&DAT_140572798;
        local_1d20[1] = (HKEY)&DAT_1405727a8;
        FUN_1401594b0(&DAT_1404ab2c8);
        FUN_14015a010();
        DAT_140865b38 = LoadLibraryW(L"XAudio2_8.dll");
        if (DAT_140865b38 == (HMODULE)0x0) {
          FUN_1401594b0(&DAT_1404ab488);
          pHVar9 = (HKEY)&DAT_140572798;
          uVar8 = uVar23;
          uVar20 = uVar23;
          do {
            uVar24 = (uint)uVar20;
            local_1d68 = (HKEY *)&DAT_140865b70;
            iVar3 = (*DAT_140c2b900)(pHVar9,0,0x17,&DAT_1405727b8);
            if (-1 < iVar3) break;
            uVar8 = uVar8 + 1;
            uVar24 = uVar24 + 1;
            uVar20 = (ulonglong)uVar24;
            pHVar9 = local_1d20[uVar8 * 2];
          } while (pHVar9 != (HKEY)0x0);
          if (local_1d20[uVar8 * 2] != (HKEY)0x0) {
            FUN_140159b70(&DAT_1404ab4c8,7 - uVar24);
            FUN_1401594b0(&DAT_1404ab4e0);
            iVar3 = (**(code **)(*DAT_140865b70 + 0x28))(DAT_140865b70,0,0xffffffff);
            if (-1 < iVar3) {
              FUN_1401594b0(&DAT_1404a74a0);
              FUN_1401594b0(&DAT_1404ab510);
              pwVar11 = L"X3DAudio1_7.dll";
              uVar8 = uVar23;
LAB_14019fd42:
              DAT_140865b58 = LoadLibraryW(pwVar11);
              if (DAT_140865b58 == (HMODULE)0x0) goto code_r0x00014019fd57;
              FUN_1401594b0(&DAT_1404a74a0);
              DAT_140865b60 = GetProcAddress(DAT_140865b58,"X3DAudioInitialize");
              DAT_140865b68 = GetProcAddress(DAT_140865b58,"X3DAudioCalculate");
              local_1d58 = (undefined4 *)0x0;
              local_1d60 = (longlong *)((ulonglong)local_1d60 & 0xffffffff00000000);
              local_1d68 = (HKEY *)((ulonglong)local_1d68 & 0xffffffff00000000);
              iVar3 = (**(code **)(*DAT_140865b70 + 0x50))
                                (DAT_140865b70,&DAT_140866820,0,DAT_140844398);
              if (-1 < iVar3) {
                lVar15 = 0x1e;
                uVar8 = uVar23;
                do {
                  FUN_14019e4f0(&DAT_1404a95c0 + uVar8,&DAT_140865b78 + uVar8);
                  uVar8 = uVar8 + 0x34;
                  lVar15 = lVar15 + -1;
                } while (lVar15 != 0);
                DAT_1408450fc = 1;
                goto LAB_1401a033d;
              }
              FUN_1401594b0(&DAT_1404ab440);
              if (DAT_140865b58 != (HMODULE)0x0) {
                FreeLibrary(DAT_140865b58);
                DAT_140865b60 = (FARPROC)0x0;
                DAT_140865b68 = (FARPROC)0x0;
                DAT_140865b58 = (HMODULE)0x0;
              }
              goto LAB_14019fe1f;
            }
            FUN_1401594b0(&DAT_1404ab3f8);
            FUN_140159ab0(&DAT_1404ab410,iVar3);
            goto LAB_14019fe1f;
          }
          DAT_140865b70 = (longlong *)0x0;
          FUN_1401594b0(&DAT_1404ab578);
          DAT_14086f310 = 0;
        }
        else {
          FUN_1401594b0(&DAT_1404ab310);
          DAT_140865b40 = GetProcAddress(DAT_140865b38,"XAudio2Create");
          _DAT_140865b48 = GetProcAddress(DAT_140865b38,"CreateAudioVolumeMeter");
          DAT_140865b50 = GetProcAddress(DAT_140865b38,"CreateAudioReverb");
          DAT_140865b60 = GetProcAddress(DAT_140865b38,"X3DAudioInitialize");
          DAT_140865b68 = GetProcAddress(DAT_140865b38,"X3DAudioCalculate");
          FUN_1401594b0(&DAT_1404ab3b0);
          uVar8 = (*DAT_140865b40)(&DAT_140865b70,0,0xffffffff);
          if ((int)uVar8 < 0) {
            FUN_1401594b0(&DAT_1404ab3f8);
            FUN_140159ab0(&DAT_1404ab410,uVar8 & 0xffffffff);
            (**(code **)(*DAT_140865b70 + 0x10))();
            DAT_140865b70 = (longlong *)0x0;
            DAT_14086f310 = 0;
          }
          else {
            FUN_1401594b0(&DAT_1404ab420);
            local_1d50 = (undefined4 *)CONCAT44(local_1d50._4_4_,6);
            local_1d58 = (undefined4 *)0x0;
            local_1d60 = (longlong *)0x0;
            local_1d68 = (HKEY *)((ulonglong)local_1d68 & 0xffffffff00000000);
            iVar3 = (**(code **)(*DAT_140865b70 + 0x38))
                              (DAT_140865b70,&DAT_140866828,0,DAT_140844398);
            if (-1 < iVar3) {
              puVar16 = &DAT_1404a95c0;
              lVar15 = 0x1e;
              puVar22 = &DAT_140866190;
              do {
                FUN_14019e340(puVar16,puVar22);
                puVar22 = puVar22 + 0x38;
                puVar16 = puVar16 + 0x34;
                lVar15 = lVar15 + -1;
              } while (lVar15 != 0);
              DAT_1408450fc = 1;
              goto LAB_1401a033d;
            }
            FUN_1401594b0(&DAT_1404ab440);
            (**(code **)(*DAT_140865b70 + 0x10))();
            DAT_140865b70 = (longlong *)0x0;
            DAT_14086f310 = 0;
          }
        }
      }
      else {
        DAT_1408450f8 = 1;
        FUN_1401594b0(&DAT_1404ab160);
        FUN_14015a010();
        DAT_14086f2f8 = 0;
        FUN_1401ae370(&local_1aa0,0,0x12);
        local_1aa0 = 0x20001;
        local_1a94 = 0x100004;
        local_1a9c = 0xac44;
        if (DAT_14086f27c != 0) {
          local_1a9c = DAT_14086f284;
        }
        local_1a98 = local_1a9c * 4;
        if ((DAT_14086f27c == 0) || ((int)DAT_14086f280 < 1)) {
          DAT_14086f288 = local_1a9c / 0x1e;
        }
        else {
          DAT_14086f288 = DAT_14086f280;
        }
        FUN_1401ae370(&DAT_1408668ac,0,0x28);
        DAT_1408668b0 = local_1a9c;
        _DAT_1408668b8 = local_1a94;
        _DAT_1408668b4 = local_1a98;
        _DAT_1408668ac = 0x2fffe;
        DAT_1408668bc = 0x16;
        _DAT_1408668be = local_1a94._2_2_;
        _DAT_1408450b8 = 0x16;
        DAT_1408450bc = (uint)local_1a94._2_2_;
        _DAT_1408450a8 = 0x2fffe;
        DAT_1408450ac = local_1a9c;
        iRam00000001408450b0 = local_1a98;
        uRam00000001408450b4 = local_1a94;
        _DAT_1408668c0 = 3;
        _DAT_1408668c4 = _DAT_140574188;
        _DAT_1408668cc = uRam0000000140574190;
        _DAT_1408450c0 = 0;
        FUN_140159b70(&DAT_1404aa2c8,2);
        FUN_140159b70(&DAT_1404aa2f0,_DAT_1408668b8 >> 0x10);
        FUN_140159b70(&DAT_1404aa318,_DAT_1408668be);
        FUN_140159b70(&DAT_1404aa340,DAT_1408668b0);
        puVar16 = &DAT_1404aa368;
        if (DAT_1408450c0 == 0) {
          puVar16 = &DAT_1404aa398;
        }
        FUN_140159b70(puVar16);
        FUN_140159b70(&DAT_1404aa140,(double)(((float)DAT_14086f288 / (float)local_1a9c) * fVar2));
        iVar3 = FUN_14018d180(_DAT_1408450c0 & 0xffffffff,DAT_14086f288);
        if (iVar3 < 0) {
          FUN_14015a020();
          FUN_1401594b0(&DAT_1404aa6c0);
          DAT_14086f31c = 0;
          DAT_1408450f8 = 0;
        }
        else {
          local_1d60 = (longlong *)CONCAT44(local_1d60._4_4_,0x30000);
          local_1d68 = (HKEY *)0x0;
          iVar3 = (*DAT_140c2b5f0)(&DAT_14086f290,0xffffffff,&local_1aa0,FUN_1401a3f60);
          if (iVar3 == 0) {
            puVar14 = &DAT_14086f2b4;
            do {
              FUN_1401ae370(plVar19,0,0x30);
              iVar3 = (local_1a94 & 0xffff) * DAT_14086f288;
              plVar19 = plVar19 + 6;
              *puVar14 = 1;
              puVar14[-5] = iVar3;
              lVar15 = lVar15 + -1;
              puVar14 = puVar14 + 0xc;
            } while (lVar15 != 0);
            DAT_14086f298 =
                 FUN_1401b6390(DAT_14086f2a0 * 2,
                               "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundWin.cpp",
                               0x7fc);
            DAT_14086f2c8 = (ulonglong)DAT_14086f2a0 + DAT_14086f298;
            uVar8 = uVar23;
            if (DAT_14086f298 == 0) {
              FUN_14015a020();
              FUN_1401594b0(&DAT_1404ab1c0);
              (*DAT_140c2b618)(DAT_14086f290);
              (*DAT_140c2b5f8)(DAT_14086f290);
              DAT_14086f290 = 0;
              DAT_14086f31c = 0;
              DAT_1408450f8 = 0;
            }
            else {
              do {
                iVar4 = (int)uVar8;
                iVar3 = (*DAT_140c2b600)(DAT_14086f290,&DAT_14086f298 + (longlong)iVar4 * 6,0x30);
                if (iVar3 != 0) {
                  FUN_14015a020();
                  FUN_1401594b0(&DAT_1404ab200);
                  (*DAT_140c2b618)(DAT_14086f290);
                  if (iVar4 == 1) {
                    (*DAT_140c2b608)(DAT_14086f290,&DAT_14086f298,0x30);
                  }
                  (*DAT_140c2b5f8)(DAT_14086f290);
                  DAT_14086f290 = 0;
                  FUN_1401b6700(DAT_14086f298);
                  DAT_14086f298 = 0;
                  DAT_14086f2c8 = 0;
                  DAT_14086f31c = 0;
                  DAT_1408450f8 = 0;
                  goto LAB_14019e91d;
                }
                uVar8 = (ulonglong)(iVar4 + 1U);
              } while ((int)(iVar4 + 1U) < 2);
              plVar19 = &DAT_14086f298;
              uVar8 = uVar23;
              while( true ) {
                iVar3 = (int)uVar8;
                if (1 < iVar3) {
                  FUN_14015a020();
                  FUN_1401594b0(&DAT_1404ab270);
                  DAT_140865b70 = (longlong *)0x1;
                  goto LAB_1401a033d;
                }
                FUN_140190e20(*plVar19,(ulonglong)(_DAT_1408668b8 >> 0x13) + *plVar19,
                              _DAT_1408668b8 & 0xffff,DAT_14086f288);
                iVar4 = (*DAT_140c2b610)(DAT_14086f290,&DAT_14086f298 + (longlong)iVar3 * 6,0x30);
                if (iVar4 != 0) break;
                uVar8 = (ulonglong)(iVar3 + 1);
                plVar19 = plVar19 + 6;
              }
              FUN_14015a020();
              FUN_1401594b0(&DAT_1404ab240);
              (*DAT_140c2b618)(DAT_14086f290);
              (*DAT_140c2b608)(DAT_14086f290,&DAT_14086f298,0x30);
              (*DAT_140c2b608)(DAT_14086f290,&DAT_14086f2c8,0x30);
              (*DAT_140c2b5f8)(DAT_14086f290);
              DAT_14086f290 = 0;
              FUN_1401b6700(DAT_14086f298);
              DAT_14086f298 = 0;
              DAT_14086f2c8 = 0;
              DAT_14086f31c = 0;
              DAT_1408450f8 = 0;
            }
          }
          else {
            FUN_14015a020();
            FUN_1401594b0(&DAT_1404ab190);
            DAT_14086f31c = 0;
            DAT_1408450f8 = 0;
          }
        }
      }
      goto LAB_14019e91d;
    }
    DAT_1408450f8 = 1;
    FUN_1401594b0(&DAT_1404aa810);
    if ((((DAT_140c2bdb8 == 0) || (DAT_140c2bf20 == 0)) || (DAT_140c2bf30 == 0)) ||
       (((DAT_140c2bf40 == 0 || (DAT_140c2bf50 == 0)) ||
        ((DAT_140c2b808 == 0 || ((DAT_140c2b820 == (code *)0x0 || (DAT_140c2b930 == (code *)0x0)))))
        ))) {
      FUN_14015a020();
      puVar16 = &DAT_1404aa830;
    }
    else {
      FUN_14015a010();
      local_1ce0 = (HKEY)0x0;
      FUN_140159b70(&DAT_1404aa870);
      iVar3 = FUN_1401e9230(0xffffffff80000002,L"software\\asio",&local_1ce0);
      uVar8 = uVar23;
      while ((iVar3 == 0 && (DAT_140866950 < 0x20))) {
        if ((int)uVar8 == 0) {
          FUN_140159b70(&DAT_1404aa8b8);
        }
        iVar3 = FUN_1401e8e70(local_1ce0,uVar8,local_1058,0x100);
        local_1d34 = (int)uVar8 + 1;
        uVar20 = (ulonglong)local_1d34;
        if (iVar3 != 0) break;
        local_1ce8 = (HKEY)0x0;
        FUN_140159b70(&DAT_1404aa8e8,uVar8,local_1058);
        local_1d68 = &local_1ce8;
        iVar3 = FUN_1401e9040(local_1ce0,local_1058,0,0x20019);
        if (iVar3 != 0) break;
        FUN_140159b70(&DAT_1404aa930,uVar8);
        local_1d60 = (longlong *)&local_1aa4;
        local_1d68 = local_1258;
        local_1aa8 = 1;
        local_1aa4 = 0x100;
        iVar3 = FUN_1401e9400(local_1ce8,L"clsid",0,&local_1aa8);
        if (iVar3 == 0) {
          local_1cf0 = (HKEY)0x0;
          uVar6 = FUN_1401ba9b0(0x4b0,local_1258);
          FUN_1401e33c0(local_1258,uVar6);
          FUN_140159b70(&DAT_1404aa988,uVar8,local_1258);
          iVar3 = FUN_1401e9230(0xffffffff80000000,L"clsid",&local_1cf0);
          uVar17 = uVar23;
          uVar18 = uVar23;
          if (iVar3 == 0) {
            do {
              do {
                if ((int)uVar17 != 0) goto LAB_14019eebe;
                iVar3 = FUN_1401e8e70(local_1cf0,uVar18,local_858,0x400);
                uVar18 = (ulonglong)((int)uVar18 + 1);
                if (iVar3 != 0) goto LAB_14019eebe;
                uVar6 = FUN_1401ba9b0(0x4b0,local_858);
                FUN_1401e33c0(local_858,uVar6);
                iVar4 = FUN_1401ba140(0x4b0,local_858,local_1258);
              } while (iVar4 != 0);
              local_1cd8 = (HKEY)0x0;
              FUN_140159b70(&DAT_1404aa9c0,uVar8);
              local_1d68 = &local_1cd8;
              iVar3 = FUN_1401e9040(local_1cf0,local_858,0,0x20019);
              if (iVar3 != 0) break;
              local_1d20[4] = (HKEY)0x0;
              FUN_140159b70(&DAT_1404aaa00,uVar8);
              local_1d68 = local_1d20 + 4;
              iVar3 = FUN_1401e9040(local_1cd8,L"InprocServer32",0,0x20019);
              if (iVar3 == 0) {
                FUN_140159b70(&DAT_1404aaa70,uVar8);
                local_1d60 = (longlong *)&local_1aa4;
                local_1d68 = local_c58;
                local_1aa8 = 1;
                local_1aa4 = 0x200;
                iVar3 = FUN_1401e9400(local_1d20[4],0,0,&local_1aa8);
                if (iVar3 == 0) {
                  FUN_140159b70(&DAT_1404aaab8,uVar8,local_c58);
                  lVar15 = FUN_1401e4b30(local_c58,local_15b8);
                  if (lVar15 == -1) {
                    puVar16 = &DAT_1404aaba0;
LAB_14019ee9a:
                    FUN_140159b70(puVar16,uVar8);
                  }
                  else {
                    (*DAT_140c2b820)(lVar15);
                    if ((local_15b8[0] & 0x10) == 0) {
                      FUN_140159b70(&DAT_1404aab00,uVar8);
                      iVar3 = (*DAT_140c2b930)(local_1258,local_1a20);
                      if (iVar3 == 0) {
                        FUN_1401ae2f0(&DAT_14086edd8 + (longlong)DAT_140866950 * 0x10,local_1a20,
                                      0x10);
                        local_1d60 = (longlong *)&local_1aa4;
                        local_1d68 = local_e58;
                        local_1aa8 = 1;
                        local_1aa4 = 0x100;
                        iVar3 = FUN_1401e9400(local_1ce8,L"description",0,&local_1aa8);
                        ppHVar21 = local_e58;
                        if (iVar3 != 0) {
                          ppHVar21 = local_1058;
                        }
                        FUN_1401ba3d0(0x4b0,&DAT_14086a958 + (longlong)DAT_140866950 * 0x200,
                                      ppHVar21);
                        DAT_140866950 = DAT_140866950 + 1;
                        puVar16 = &DAT_1404aab60;
                        goto LAB_14019ee9a;
                      }
                    }
                  }
                }
                RegCloseKey(local_1d20[4]);
              }
              RegCloseKey(local_1cd8);
              uVar17 = 1;
            } while (iVar3 == 0);
LAB_14019eebe:
            RegCloseKey(local_1cf0);
            uVar20 = (ulonglong)local_1d34;
          }
        }
        RegCloseKey(local_1ce8);
        uVar8 = uVar20;
      }
      if (local_1ce0 != (HKEY)0x0) {
        RegCloseKey(local_1ce0);
      }
      FUN_140159b70(&DAT_1404aabf0);
      if (DAT_140866950 == 0) {
        FUN_14015a020();
        puVar16 = &DAT_1404aac18;
      }
      else {
        if (DAT_140866954 < 0) {
          DAT_140866954 = 0;
        }
        else if (DAT_140866950 <= DAT_140866954) {
          DAT_140866954 = DAT_140866950 + -1;
        }
        FUN_140159b70(&DAT_1404aac48);
        local_1d68 = (HKEY *)(&DAT_14086efd8 + DAT_140866954);
        iVar3 = (*DAT_140c2b900)(&DAT_14086edd8 + (longlong)DAT_140866954 * 0x10,0,1,
                                 &DAT_14086edd8 + (longlong)DAT_140866954 * 0x10);
        if (-1 < iVar3) {
          FUN_140159b70(&DAT_1404aac98);
          FUN_140159b70(&DAT_1404aacc0);
          plVar19 = (longlong *)(&DAT_14086efd8)[DAT_140866954];
          lVar15 = *plVar19;
          uVar6 = FUN_1401a6400();
          iVar3 = (**(code **)(lVar15 + 0x18))(plVar19,uVar6);
          if (iVar3 == 0) {
            (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
            (&DAT_14086efd8)[DAT_140866954] = 0;
            FUN_14015a020();
            puVar16 = &DAT_1404aacd8;
          }
          else {
            FUN_140159b70(&DAT_1404aad00);
            FUN_140159b70(&DAT_1404aad20);
            local_1d68 = (HKEY *)&DAT_14086f0e8;
            iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x58))
                              ((longlong *)(&DAT_14086efd8)[DAT_140866954],&DAT_14086f0d8,
                               &DAT_14086f0dc,&DAT_14086f0e0);
            if (iVar3 == 0) {
              if ((DAT_14086f270 == 0) || (DAT_14086f274 < 0)) {
                DAT_14086f0e4 = DAT_14086f0e0;
              }
              else {
                DAT_14086f0e4 = DAT_14086f274;
                if (DAT_14086f274 < DAT_14086f0d8) {
                  DAT_14086f0e4 = DAT_14086f0d8;
                }
                else if (DAT_14086f274 < DAT_14086f0dc) {
                  DAT_14086f0e4 = DAT_14086f0dc;
                }
              }
              FUN_140159b70(&DAT_1404aad88);
              FUN_140159b70(&DAT_1404aadb8,DAT_14086f0d8);
              FUN_140159b70(&DAT_1404aade0,DAT_14086f0dc);
              FUN_140159b70(&DAT_1404aae08,DAT_14086f0e0);
              FUN_140159b70(&DAT_1404aae30,DAT_14086f0e8);
              FUN_140159b70(&DAT_1404aae58,DAT_14086f0e4);
              FUN_1401ae370(&DAT_14086f0f0,0,0x180);
              _DAT_14086f0f0 = 0;
              _DAT_14086f108 = 0;
              _DAT_14086f10c = 1;
              FUN_140159b70(&DAT_1404aae80);
              local_1c28 = DAT_14086f0f4;
              local_1c24 = DAT_14086f0f0;
              iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x90))
                                ((longlong *)(&DAT_14086efd8)[DAT_140866954],&local_1c28);
              if (iVar3 == 0) {
                FUN_140159b70(&DAT_1404aaed8);
                FUN_140159b70(&DAT_1404aaf08,
                              (&PTR_u_ASIOSTInt16MSB_14056ce80)[(longlong)local_1c18 * 3]);
                local_1a88 = dVar1;
                if (DAT_14086f270 != 0) {
                  local_1a88 = (double)DAT_14086f278;
                }
                FUN_140159b70(&DAT_1404aaf28,(int)local_1a88);
                iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x70))
                                  ((longlong *)(&DAT_14086efd8)[DAT_140866954],SUB84(local_1a88,0));
                puVar16 = &DAT_1404aaf60;
                if (iVar3 == 0) {
                  puVar16 = &DAT_1404aaf90;
                }
                FUN_140159b70(puVar16);
                FUN_140159b70(&DAT_1404aafc0);
                iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x68))
                                  ((longlong *)(&DAT_14086efd8)[DAT_140866954],&local_1a88);
                if (iVar3 == 0) {
                  FUN_140159b70(&DAT_1404ab018);
                  FUN_140159b70(&DAT_1404ab048,local_1a88);
                  lVar15 = (longlong)local_1c18;
                  FUN_1401ae370(&DAT_1408668ac,0,0x28);
                  DAT_1408450ac = (uint)local_1a88;
                  _DAT_1408668ac = 0x2fffe;
                  DAT_1408668bc = 0x16;
                  _DAT_1408668c0 = 3;
                  _DAT_1408450b8 = 0x16;
                  _DAT_1408668be = *(ushort *)(&DAT_14056ce8a + lVar15 * 0x18);
                  iRam00000001408450b0 =
                       (int)((uint)*(ushort *)(&DAT_14056ce88 + lVar15 * 0x18) * 2) >> 3;
                  _DAT_1408668b8 =
                       CONCAT22(*(ushort *)(&DAT_14056ce88 + lVar15 * 0x18),
                                (short)iRam00000001408450b0);
                  iRam00000001408450b0 = iRam00000001408450b0 * DAT_1408450ac;
                  puVar7 = (undefined8 *)&DAT_140574188;
                  if (*(int *)(&DAT_14056ce8c + lVar15 * 0x18) != 0) {
                    puVar7 = (undefined8 *)&DAT_140574198;
                  }
                  DAT_1408450bc = (uint)_DAT_1408668be;
                  _DAT_1408450a8 = 0x2fffe;
                  uRam00000001408450b4 = _DAT_1408668b8;
                  _DAT_1408668c4 = *puVar7;
                  _DAT_1408668cc = puVar7[1];
                  _DAT_1408450c0 =
                       CONCAT44(*(undefined4 *)(&DAT_14056ce90 + lVar15 * 0x18),
                                *(int *)(&DAT_14056ce8c + lVar15 * 0x18));
                  DAT_1408668b0 = DAT_1408450ac;
                  _DAT_1408668b4 = iRam00000001408450b0;
                  FUN_140159b70(&DAT_1404ab068);
                  _DAT_140889728 = FUN_14019e210;
                  _DAT_140889740 = 0;
                  _DAT_140889730 = &LAB_14019e280;
                  local_1d68 = (HKEY *)&DAT_140889728;
                  _DAT_140889738 = FUN_140139620;
                  iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x98))
                                    ((longlong *)(&DAT_14086efd8)[DAT_140866954],&DAT_14086f0f0,2,
                                     DAT_14086f0e4);
                  if (iVar3 == 0) {
                    FUN_140159b70(&DAT_1404ab0b8);
                    iVar3 = FUN_14018d180(_DAT_1408450c0 & 0xffffffff,DAT_14086f0e4);
                    if (iVar3 < 0) {
                      (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0xa0))();
                      (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
                      (&DAT_14086efd8)[DAT_140866954] = 0;
                      FUN_14015a020();
                      puVar16 = &DAT_1404aa6c0;
                    }
                    else {
                      DAT_140865b70 = (longlong *)0x1;
                      FUN_140159b70(&DAT_1404ab0e0);
                      iVar3 = (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x38))();
                      if (iVar3 == 0) {
                        FUN_14015a020();
                        FUN_1401594b0(&DAT_1404ab138);
                        goto LAB_1401a033d;
                      }
                      (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0xa0))();
                      (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
                      (&DAT_14086efd8)[DAT_140866954] = 0;
                      FUN_14015a020();
                      puVar16 = &DAT_1404ab108;
                    }
                  }
                  else {
                    (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
                    (&DAT_14086efd8)[DAT_140866954] = 0;
                    FUN_14015a020();
                    puVar16 = &DAT_1404ab088;
                  }
                }
                else {
                  (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
                  (&DAT_14086efd8)[DAT_140866954] = 0;
                  FUN_14015a020();
                  puVar16 = &DAT_1404aafe8;
                }
              }
              else {
                (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
                (&DAT_14086efd8)[DAT_140866954] = 0;
                FUN_14015a020();
                puVar16 = &DAT_1404aaea8;
              }
            }
            else {
              (**(code **)(*(longlong *)(&DAT_14086efd8)[DAT_140866954] + 0x10))();
              (&DAT_14086efd8)[DAT_140866954] = 0;
              FUN_14015a020();
              puVar16 = &DAT_1404aad48;
            }
          }
          FUN_1401594b0(puVar16);
          DAT_14086f318 = 0;
          DAT_1408450f8 = 0;
          goto LAB_14019e91d;
        }
        FUN_14015a020();
        puVar16 = &DAT_1404aac68;
      }
    }
    FUN_1401594b0(puVar16);
    DAT_14086f318 = 0;
    DAT_1408450f8 = 0;
  } while( true );
  iVar3 = FUN_1401a0a20();
  if (-1 < iVar3) goto code_r0x00014019fa90;
  goto LAB_14019e91d;
code_r0x00014019fd57:
  pwVar11 = (wchar_t *)(&local_1d28)[uVar8];
  uVar8 = uVar8 + 1;
  if (pwVar11 == (LPCWSTR)0x0) goto code_r0x00014019fd64;
  goto LAB_14019fd42;
code_r0x00014019fd64:
  FUN_1401594b0(&DAT_1404ab540);
LAB_14019fe1f:
  (**(code **)(*DAT_140865b70 + 0x10))();
  DAT_140865b70 = (longlong *)0x0;
  DAT_14086f310 = 0;
  goto LAB_14019e91d;
code_r0x00014019fa90:
  DAT_140865b70 = (longlong *)0x1;
LAB_1401a033d:
  uVar24 = 2;
  lVar15 = 0x10;
  if (((DAT_14086f31c != 0) || (DAT_14086f318 != 0)) || (DAT_14086f314 == 0)) goto LAB_1401a0861;
  if (DAT_14086f310 != 0) {
    if (DAT_140865b38 == (HMODULE)0x0) {
      (**(code **)(*DAT_140865b70 + 0x20))(DAT_140865b70,0,local_19e8);
      FUN_14015a010();
      FUN_140159c40(L"Device Name : %s",local_17e8);
      FUN_140159b70(&DAT_1404ab9c0,local_15e2);
      FUN_140159b70(&DAT_1404ab9d8,local_15d6);
      FUN_140159b70(&DAT_1404ab9f0,local_15e0);
      FUN_14015a020();
      DAT_140844394 = (uint)local_15e2;
      DAT_14086683c = local_15d0;
    }
    else {
      (**(code **)(*DAT_140866828 + 0x98))(DAT_140866828,&DAT_14086683c);
      uVar24 = 1;
      DAT_140844394 = 0;
      do {
        if ((DAT_14086683c & uVar24) != 0) {
          DAT_140844394 = (int)uVar23 + 1;
          uVar23 = (ulonglong)DAT_140844394;
        }
        uVar24 = uVar24 << 1 | (uint)((int)uVar24 < 0);
        if ((DAT_14086683c & uVar24) != 0) {
          DAT_140844394 = (int)uVar23 + 1;
          uVar23 = (ulonglong)DAT_140844394;
        }
        uVar24 = uVar24 << 1 | (uint)((int)uVar24 < 0);
        lVar15 = lVar15 + -1;
      } while (lVar15 != 0);
    }
    (*DAT_140865b60)((ulonglong)DAT_14086683c,DAT_1404abe48,&DAT_140866840);
    goto LAB_1401a0861;
  }
  FUN_1401ae370(&local_1a78,0,0x12);
  local_1a78 = 0x10001;
  local_1a74 = 0x5622;
  local_1a6c = 0x100002;
  local_1a70 = 0xac44;
  FUN_1401ae370(&local_1cb8,0,0x28);
  local_1cb8 = 0x28;
  local_1cb4 = uVar24;
  if (DAT_14086f320 != 0) {
    local_1cb4 = 8;
  }
  local_1cb4 = local_1cb4 | 0x180e0;
  local_1cb0 = (local_1a6c & 0xffff) * 9000;
  local_1ca8 = &local_1a78;
  iVar3 = (**(code **)(*DAT_140865b70 + 0x18))(DAT_140865b70,&local_1cb8,&DAT_14086f308,0);
  if (iVar3 == 0) {
LAB_1401a0593:
    local_1d58 = &local_1a7c;
    local_1d50 = (undefined4 *)((ulonglong)local_1d50 & 0xffffffff00000000);
    local_1d60 = &local_1cc0;
    local_1d68 = (HKEY *)&local_1a80;
    iVar3 = (**(code **)(*DAT_14086f308 + 0x58))(DAT_14086f308,0,local_1cb0,&local_1cc8);
    if (iVar3 != 0) {
      FUN_1401594b0(&DAT_1404aba38);
      (**(code **)(*DAT_14086f308 + 0x10))();
      DAT_14086f308 = (longlong *)0x0;
    }
    FUN_1401ae370(local_1cc8,0,local_1a80);
    if (local_1cc0 != 0) {
      FUN_1401ae370(local_1cc0,0,local_1a7c);
    }
    local_1d68 = (HKEY *)CONCAT44(local_1d68._4_4_,local_1a7c);
    (**(code **)(*DAT_14086f308 + 0x98))(DAT_14086f308,local_1cc8,local_1a80,local_1cc0);
    (**(code **)(*DAT_14086f308 + 0x60))(DAT_14086f308,0,0,1);
  }
  else {
    FUN_1401ae370(&local_1cb8,0,0x28);
    local_1cb8 = 0x28;
    if (DAT_14086f320 != 0) {
      uVar24 = 8;
    }
    local_1cb0 = (local_1a6c & 0xffff) * 9000;
    local_1ca8 = &local_1a78;
    local_1cb4 = uVar24 | 0xc0;
    iVar3 = (**(code **)(*DAT_140865b70 + 0x18))(DAT_140865b70,&local_1cb8,&DAT_14086f308,0);
    if (iVar3 == 0) goto LAB_1401a0593;
    FUN_1401594b0(&DAT_1404aba10);
    DAT_14086f308 = (longlong *)0x0;
  }
  if (DAT_140865b70 != (longlong *)0x0) {
    FUN_14015a010();
    FUN_1401ae370(&local_1c88,0,0x60);
    local_1c88 = 0x60;
    (**(code **)(*DAT_140865b70 + 0x20))(DAT_140865b70,&local_1c88);
    FUN_1401594b0(&DAT_1404aba60);
    FUN_14015a010();
    hModule = LoadLibraryA("DSound.DLL");
    if (hModule == (HMODULE)0x0) {
      FUN_1401594b0(&DAT_1404abaa0);
      FUN_14015a020();
      FUN_14015a020();
    }
    else {
      pFVar10 = GetProcAddress(hModule,"DirectSoundEnumerateW");
      if (pFVar10 == (FARPROC)0x0) {
        FreeLibrary(hModule);
        FUN_1401594b0(&DAT_1404abaf0);
        FUN_14015a020();
        FUN_14015a020();
      }
      else {
        (*pFVar10)(FUN_14019e310,0);
        FUN_14015a020();
        FUN_140159b70(&DAT_1404abb40,(double)local_1c7c / DAT_14053a8f8,
                      (double)local_1c80 / DAT_14053a8f8);
        FUN_140159b70(&DAT_1404abba0,(double)local_1c44 * _DAT_1404abe30,
                      (double)local_1c40 * _DAT_1404abe30);
        FUN_1401594b0(&DAT_1404abbf0);
        puVar16 = &DAT_1404abc14;
        puVar22 = &DAT_1404abc14;
        if ((local_1c84 & 4) != 0) {
          puVar22 = &DAT_1404abc0c;
        }
        puVar12 = &DAT_1404abc14;
        if ((local_1c84 & 8) != 0) {
          puVar12 = &DAT_1404abc0c;
        }
        FUN_140159c40(L"  Primary    16bit = %s  8bit = %s ",puVar12,puVar22);
        puVar12 = &DAT_1404abc14;
        puVar22 = &DAT_1404abc14;
        if ((local_1c84 & 0x400) != 0) {
          puVar12 = &DAT_1404abc0c;
        }
        if ((local_1c84 & 0x800) != 0) {
          puVar22 = &DAT_1404abc0c;
        }
        FUN_140159c40(L"  Secondary  16bit = %s  8bit = %s \n",puVar22,puVar12);
        FUN_1401594b0(&DAT_1404abcc0);
        puVar12 = &DAT_1404abc14;
        puVar22 = &DAT_1404abc14;
        if ((local_1c84 & 2) != 0) {
          puVar12 = &DAT_1404abc0c;
        }
        if ((local_1c84 & 1) != 0) {
          puVar22 = &DAT_1404abc0c;
        }
        FUN_140159c40(L"  Primary    MONO = %s   STEREO = %s ",puVar22,puVar12);
        puVar22 = &DAT_1404abc14;
        if ((local_1c84 & 0x200) != 0) {
          puVar22 = &DAT_1404abc0c;
        }
        if ((local_1c84 & 0x100) != 0) {
          puVar16 = &DAT_1404abc0c;
        }
        FUN_140159c40(L"  Secondary  MONO = %s   STEREO = %s \n",puVar16,puVar22);
        FUN_14015a020();
        FreeLibrary(hModule);
      }
    }
  }
LAB_1401a0861:
  _DAT_1408668a4 = &DAT_140866854;
  _DAT_14086689c = 0;
  uRam0000000140866894 = 0;
  _DAT_14086688c = 0;
  _DAT_140866888 = 0;
  _DAT_140866884 = DAT_140539da8;
  uRam000000014086687c = _UNK_1404abe58;
  _DAT_140866874 = _DAT_1404abe50;
  uRam000000014086686c = _UNK_1404a9bf0;
  _DAT_140866864 = _DAT_1404a9be8;
  uRam000000014086685c = _UNK_1404a9be0;
  _DAT_140866854 = _DAT_1404a9bd8;
  return 0;
}


