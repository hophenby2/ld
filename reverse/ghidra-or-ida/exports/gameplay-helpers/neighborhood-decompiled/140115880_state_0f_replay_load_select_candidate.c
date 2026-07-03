// Function: state_0f_replay_load_select_candidate @ 140115880
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_0f_replay_load_select_candidate(void)

{
  undefined8 uVar1;
  uint uVar2;
  errno_t eVar3;
  undefined4 *puVar4;
  size_t sVar5;
  int iVar6;
  undefined4 uVar7;
  longlong lVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  bool bVar13;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  FILE *local_50;
  undefined8 local_48;
  char local_40 [32];
  ulonglong local_20;
  
  uVar7 = DAT_140e46024;
  local_20 = DAT_1407c6b00 ^ (ulonglong)auStack_78;
  iVar10 = (&DAT_140e8cf84)[(longlong)DAT_140e47434 * 0x2a6];
  if (9 < (int)(&DAT_140e8cf84)[(longlong)DAT_140e47434 * 0x2a6]) {
    iVar10 = 9;
  }
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e24 = _DAT_140e46e24 + 1;
  lVar12 = 0;
  bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar4 = uVar7;
  *(undefined8 *)(puVar4 + 1) = 0x65;
  *(undefined8 *)(puVar4 + 3) = 0;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
  puVar4[10] = 0xff;
  puVar4[0xb] = 0xff;
  puVar4[0xc] = 0xff;
  puVar4[0xd] = 0xff;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar13) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar4;
  }
  uVar7 = DAT_140e467f0;
  DAT_140e46c88 = puVar4;
  puVar4 = (undefined4 *)_malloc_base(0x48);
  if (puVar4 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar13 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar4 = uVar7;
  *(undefined8 *)(puVar4 + 1) = 10;
  *(undefined8 *)(puVar4 + 3) = 0;
  *(undefined2 *)(puVar4 + 5) = 0;
  *(undefined8 *)(puVar4 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar4 + 8) = 0x3ff0000000000000;
  puVar4[10] = 0xff;
  puVar4[0xb] = 0xff;
  puVar4[0xc] = 0xff;
  puVar4[0xd] = 0xff;
  *(undefined8 *)(puVar4 + 0xe) = 1;
  *(undefined8 *)(puVar4 + 0x10) = 0;
  if (bVar13) {
    DAT_140e46bf0 = puVar4;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar4;
  }
  DAT_140e46c88 = puVar4;
  FUN_1400d9b60(0,0x70,0xff);
  FUN_1400d3a60();
  bVar13 = false;
  if ((DAT_140e418c8 < 0x20) || (DAT_140e45fac != 0)) goto LAB_140115fea;
  lVar11 = (longlong)DAT_140e47434;
  if (((&DAT_140e8cf58)[lVar11 * 0x2a6] == 1) && ((&DAT_140e8cf80)[lVar11 * 0x2a6] != 10)) {
    if (DAT_140e8cf10 == 1) {
LAB_140115a9e:
      bVar13 = true;
    }
    else if (0x13 < DAT_140e8cf10) {
      uVar2 = DAT_140e8cf10 - 0x14U & 0x80000007;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
      }
      if (uVar2 == 0) goto LAB_140115a9e;
    }
    if ((DAT_140e8cf14 < 1) && (bVar13)) {
      if (DAT_1407c7798 < 2) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar7 = DAT_140e4720c;
      }
      else {
        iVar9 = DAT_1407c7798;
        do {
          DAT_1407c7798 = iVar9 + -1;
          if ((&DAT_140e8cf5c)[lVar11 * 0x2a6] != 0) break;
          if ((DAT_1407c7798 == 2) || (iVar6 = -1, DAT_1407c7798 == 3)) {
            iVar6 = 0;
          }
          if (iVar9 - 5U < 2) {
            iVar6 = 1;
          }
          if ((1 < iVar9 - 7U) && (iVar6 == -1)) break;
          lVar8 = -1;
          if (iVar9 - 3U < 2) {
            lVar8 = lVar12;
          }
          if (iVar9 - 5U < 2) {
            lVar8 = 1;
          }
          if (iVar9 - 7U < 2) {
            lVar8 = 2;
          }
          iVar9 = DAT_1407c7798;
        } while (*(int *)(&DAT_140e8cf88 + (lVar11 * 0x2a6 + lVar8) * 4) != DAT_1407c7798);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar7 = DAT_140e47200;
      }
      FUN_14018a340(uVar7,1,1);
      DAT_140e467fc = 1;
    }
    if (DAT_140e8cf14 == 1) {
LAB_140115bb6:
      lVar11 = 1;
    }
    else {
      lVar11 = lVar12;
      if (0x13 < DAT_140e8cf14) {
        uVar2 = DAT_140e8cf14 - 0x14U & 0x80000007;
        if ((int)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
        }
        lVar11 = 0;
        if (uVar2 == 0) goto LAB_140115bb6;
      }
    }
    if ((DAT_140e8cf10 < 1) && ((int)lVar11 == 1)) {
      if (DAT_1407c7798 < iVar10) {
        iVar10 = DAT_1407c7798;
        do {
          DAT_1407c7798 = iVar10 + 1;
          if ((&DAT_140e8cf5c)[(longlong)DAT_140e47434 * 0x2a6] != 0) break;
          if ((DAT_1407c7798 == 2) || (iVar9 = -1, DAT_1407c7798 == 3)) {
            iVar9 = 0;
          }
          if (iVar10 - 3U < 2) {
            iVar9 = 1;
          }
          if ((1 < iVar10 - 5U) && (iVar9 == -1)) break;
          lVar11 = -1;
          if (iVar10 - 1U < 2) {
            lVar11 = lVar12;
          }
          if (iVar10 - 3U < 2) {
            lVar11 = 1;
          }
          if (iVar10 - 5U < 2) {
            lVar11 = 2;
          }
          iVar10 = DAT_1407c7798;
        } while (*(int *)(&DAT_140e8cf88 + ((longlong)DAT_140e47434 * 0x2a6 + lVar11) * 4) !=
                 DAT_1407c7798);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar7 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar7 = DAT_140e4720c;
      }
      FUN_14018a340(uVar7,1,1);
      DAT_140e467fc = 1;
    }
  }
  if (((&DAT_140e8cf58)[(longlong)DAT_140e47434 * 0x2a6] == 0) &&
     (((DAT_140e467b8 == 1 || (DAT_140e467bc == 1)) && (DAT_140e467fc == 0)))) {
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
    FUN_14018a340(DAT_140e4720c,1,1);
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 1;
    DAT_140e467fc = 1;
    fopen_s(&local_50,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_50);
    FUN_140323e90(local_50);
    iVar10 = DAT_140e47434;
    DAT_140e471fc = 0xb4;
    FUN_1401121f0();
    DAT_140e41b00 = 1;
    FUN_140070ca0(local_40,0x20,"replay\\LD_replay%02d.dat",iVar10 + 1);
    eVar3 = fopen_s(&local_50,local_40,"rb");
    if (eVar3 == 0) {
      fread(&DAT_140e45280,0xa98,1,local_50);
      do {
        sVar5 = fread(&local_48,8,1,local_50);
        uVar1 = local_48;
        local_58 = local_48;
        puVar4 = (undefined4 *)_malloc_base(0x10);
        if (puVar4 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        bVar13 = DAT_140e45278 == (undefined4 *)0x0;
        *(undefined2 *)(puVar4 + 1) = local_58._4_2_;
        *puVar4 = (int)uVar1;
        *(undefined8 *)(puVar4 + 2) = 0;
        if (bVar13) {
          DAT_140e45278 = puVar4;
        }
        if (DAT_140e9fd00 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e9fd00 + 2) = puVar4;
        }
        DAT_140e9fd00 = puVar4;
      } while (sVar5 != 0);
      DAT_140e41abc = DAT_140e4529c;
      DAT_140e451a4 = DAT_140e452a8;
      DAT_140e419b8 = DAT_140e452a0;
      DAT_140e45268 = DAT_140e452a4;
      DAT_140e445c0 = DAT_140e452ac;
      DAT_140e41928 = DAT_140e45298;
      DAT_140e445c4 = DAT_140e452b0;
      DAT_140e445c8 = DAT_140e452b4;
      DAT_140e445cc = DAT_140e452b8;
      DAT_140e445d0 = DAT_140e452bc;
      if (DAT_140e45298 == 0) {
        DAT_1407c7798 = DAT_140e452c0;
      }
      else if ((DAT_140e45298 == 1) && (DAT_140e452c0 == 10)) {
        DAT_1407c7798 = 10;
      }
      FUN_140323e90(local_50);
    }
    else {
      MessageBoxA((HWND)0x0,"Replay data not found.","error",0);
    }
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 0xffffffff;
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
  }
  if ((DAT_140e467e4 != 1) &&
     (DAT_140e467e0 != 1 &&
      (DAT_140e467dc != 1 &&
      (DAT_140e467d8 != 1 &&
      (DAT_140e467d4 != 1 &&
      (DAT_140e467cc._4_4_ != 1 &&
      ((int)DAT_140e467cc != 1 &&
      (DAT_140e467c8 != 1 &&
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_140115fea:
  if (0x1e < (int)DAT_140e45fac) {
    FUN_1400d3fd0(DAT_140e45fac - 0x1e);
  }
  if (DAT_140e45fac == 0x51) {
    FUN_1400f7150();
    if (DAT_140e41928 == 1) {
      DAT_140e9fd24 = DAT_1407c7798;
    }
    FUN_140118290(DAT_140e9fd24 + -1);
    DAT_140e418c8 = DAT_140e418c8 + -1;
  }
  if (DAT_140e45fac == 0xffffffe0) {
    DAT_140e45270 = 0xe;
    DAT_140e45fac = 0;
    DAT_140e418c8 = 0x3d;
    DAT_140e46014 = 0;
  }
  else {
    if (0 < (int)DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac + 1;
    }
    if (0x7fffffff < DAT_140e45fac) {
      DAT_140e45fac = DAT_140e45fac - 1;
    }
    DAT_140e418c8 = DAT_140e418c8 + 1;
  }
  return;
}


