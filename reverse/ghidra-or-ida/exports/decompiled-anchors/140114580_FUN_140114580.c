// Function: FUN_140114580 @ 140114580
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140114580(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong lVar6;
  bool bVar7;
  bool bVar8;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  char local_88 [8];
  char acStack_80 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  FILE *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  uVar5 = DAT_140e46024;
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_118;
  local_50 = _DAT_14053b7c0;
  uStack_48 = _UNK_14053b7c8;
  local_30 = 10;
  local_40 = _DAT_14053b6f0;
  uStack_38 = _UNK_14053b6f8;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46e20 = _DAT_140e46e20 + 1;
  bVar7 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar3 = uVar5;
  *(undefined8 *)(puVar3 + 1) = 100;
  *(undefined8 *)(puVar3 + 3) = 0;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar7) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)((longlong)DAT_140e46c88 + 0x40) = puVar3;
  }
  uVar5 = DAT_140e467f0;
  DAT_140e46c88 = puVar3;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar7 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar3 = uVar5;
  *(undefined8 *)(puVar3 + 1) = 10;
  *(undefined8 *)(puVar3 + 3) = 0;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0xff;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar7) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  uVar5 = *(undefined4 *)(&DAT_140e44240 + (longlong)(DAT_140e445c0 * 10) * 4);
  DAT_140e46c88 = puVar3;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cb8 = _DAT_140e46cb8 + 1;
  bVar7 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar3 = uVar5;
  puVar3[1] = 10;
  puVar3[2] = 1;
  puVar3[3] = 0x44200000;
  puVar3[4] = 0x43c30000;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  puVar3[10] = 0xff;
  puVar3[0xb] = 0xff;
  puVar3[0xc] = 0xff;
  puVar3[0xd] = 0x80;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar7) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  uVar5 = DAT_140e41ab8;
  DAT_140e46c88 = puVar3;
  puVar3 = (undefined4 *)_malloc_base(0x48);
  if (puVar3 == (undefined4 *)0x0) {
    MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
  }
  _DAT_140e46cbc = _DAT_140e46cbc + 1;
  bVar8 = DAT_140e46bf0 == (undefined4 *)0x0;
  *puVar3 = uVar5;
  *(undefined8 *)(puVar3 + 1) = 0xb;
  *(undefined8 *)(puVar3 + 3) = 0;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined8 *)(puVar3 + 6) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 8) = 0x3ff0000000000000;
  *(undefined8 *)(puVar3 + 10) = 0;
  bVar7 = false;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0x80;
  *(undefined8 *)(puVar3 + 0xe) = 1;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  if (bVar8) {
    DAT_140e46bf0 = puVar3;
  }
  if (DAT_140e46c88 != (undefined4 *)0x0) {
    *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar3;
  }
  DAT_140e46c88 = puVar3;
  FUN_1400d9b60(0,0x70,0xff);
  if (DAT_140e45fac != 0) goto LAB_140114b68;
  if (DAT_140e8cf10 == 1) {
LAB_1401148b4:
    bVar7 = true;
  }
  else if (0x13 < DAT_140e8cf10) {
    uVar4 = DAT_140e8cf10 - 0x14U & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    if (uVar4 == 0) goto LAB_1401148b4;
  }
  if (((DAT_140e8cf14 < 1) && (bVar7)) && (lVar6 = (longlong)DAT_140e9fd28, DAT_140e9fd28 < 3)) {
    iVar2 = (&DAT_140e44230)[lVar6];
    (&DAT_140e44230)[lVar6] = iVar2 + 1;
    if (0x27 < iVar2 + 1) {
      (&DAT_140e44230)[lVar6] = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if (DAT_140e8cf14 == 1) {
LAB_140114958:
    bVar7 = true;
  }
  else {
    bVar7 = false;
    if (0x13 < DAT_140e8cf14) {
      uVar4 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
      }
      bVar7 = false;
      if (uVar4 == 0) goto LAB_140114958;
    }
  }
  if (((DAT_140e8cf10 < 1) && (bVar7)) && (DAT_140e9fd28 < 3)) {
    lVar6 = (longlong)DAT_140e9fd28;
    piVar1 = &DAT_140e44230 + lVar6;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      (&DAT_140e44230)[lVar6] = 0x27;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
  }
  if ((DAT_140e467c8 == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e9fd28 < 3) {
      if ((((DAT_140e44230 == 0) && (DAT_140e44234 == 0)) && (DAT_140e44238 == 0)) &&
         (DAT_140e9fd28 == 2)) {
        lVar6 = (longlong)DAT_140e445c0;
        DAT_140e44230 = *(int *)((longlong)&local_50 + lVar6 * 0xc);
        DAT_140e44234 = *(int *)((longlong)&local_50 + lVar6 * 0xc + 4);
        DAT_140e44238 = *(int *)((longlong)&uStack_48 + lVar6 * 0xc);
      }
      DAT_140e9fd28 = DAT_140e9fd28 + 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
      uVar5 = DAT_140e47204;
    }
    else {
      DAT_140e45fac = 1;
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47278);
      uVar5 = DAT_140e47278;
    }
    FUN_14018a340(uVar5,1,1);
    DAT_140e467fc = 1;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e9fd28 == 0) {
      DAT_140e45fac = 0xffffffff;
    }
    else {
      DAT_140e9fd28 = DAT_140e9fd28 + -1;
    }
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
LAB_140114b68:
  puVar3 = DAT_140e45278;
  if (DAT_140e45fac == 1) {
    DAT_140e418c8 = 0x20;
    DAT_140e45fac = 0;
    if (DAT_140e47604 == 0) {
      _DAT_140e452d8 = DAT_140e44590;
      _DAT_140e452e0 = DAT_140e451b0;
      _DAT_140e452c4 = DAT_1407c7798;
      _DAT_140e452e4 = DAT_140e4680c;
      local_88[0] = s_DABCDEFGHIJKLMNOP_14053bedf[1];
      local_88[1] = s_DABCDEFGHIJKLMNOP_14053bedf[2];
      local_88[2] = s_DABCDEFGHIJKLMNOP_14053bedf[3];
      local_88[3] = s_DABCDEFGHIJKLMNOP_14053bedf[4];
      local_88[4] = s_DABCDEFGHIJKLMNOP_14053bedf[5];
      local_88[5] = s_DABCDEFGHIJKLMNOP_14053bedf[6];
      local_88[6] = s_DABCDEFGHIJKLMNOP_14053bedf[7];
      local_88[7] = s_DABCDEFGHIJKLMNOP_14053bedf[8];
      acStack_80[0] = s_DABCDEFGHIJKLMNOP_14053bedf[9];
      acStack_80[1] = s_DABCDEFGHIJKLMNOP_14053bedf[10];
      acStack_80[2] = s_DABCDEFGHIJKLMNOP_14053bedf[0xb];
      acStack_80[3] = s_DABCDEFGHIJKLMNOP_14053bedf[0xc];
      acStack_80[4] = s_DABCDEFGHIJKLMNOP_14053bedf[0xd];
      acStack_80[5] = s_DABCDEFGHIJKLMNOP_14053bedf[0xe];
      acStack_80[6] = s_DABCDEFGHIJKLMNOP_14053bedf[0xf];
      acStack_80[7] = s_DABCDEFGHIJKLMNOP_14053bedf[0x10];
      local_68 = 0x30393837;
      local_78 = _DAT_14053ba70;
      uStack_70 = _UNK_14053ba78;
      local_64 = 0x202d262e;
      DAT_140e45288 = local_88[DAT_140e44230];
      DAT_140e45289 = local_88[DAT_140e44234];
      DAT_140e4528a = local_88[DAT_140e44238];
      FUN_140070ca0(&local_50,0x20,"replay\\LD_replay%02d.dat",DAT_140e47434 + 1);
      fopen_s(&local_60,(char *)&local_50,"wb");
      FUN_140327c78(&DAT_140e45280,0xa98,1,local_60);
      FUN_140323e90(local_60);
      fopen_s(&local_60,(char *)&local_50,"ab");
      for (; puVar3 != (undefined4 *)0x0; puVar3 = *(undefined4 **)(puVar3 + 2)) {
        local_58._0_4_ = *puVar3;
        local_58._4_2_ = *(undefined2 *)(puVar3 + 1);
        FUN_140327c78(&local_58,8,1,local_60);
      }
    }
    else {
      FUN_140070ca0(&local_50,0x20,"media\\demo\\LD_demo%02d.txt",DAT_140e47434 + 1);
      fopen_s(&local_60,(char *)&local_50,"w");
      local_98 = DAT_140e452f0;
      local_a0 = DAT_140e452e8;
      local_a8 = DAT_140e452a8;
      local_b0 = DAT_140e452a4;
      local_b8 = DAT_140e452ec;
      local_c0 = DAT_140e452bc;
      local_c8 = DAT_140e452b8;
      local_d0 = DAT_140e452b4;
      local_d8 = DAT_140e452b0;
      local_e0 = DAT_140e452ac;
      local_e8 = DAT_140e452c0;
      local_f0 = DAT_140e452a0;
      local_f8 = DAT_140e4529c;
      FUN_140070c50(local_60,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",DAT_140e45284,
                    DAT_140e45298);
      for (; puVar3 != (undefined4 *)0x0; puVar3 = *(undefined4 **)(puVar3 + 2)) {
        FUN_140070c50(local_60,"%d,%d\n",*puVar3,(int)*(short *)(puVar3 + 1));
      }
    }
    FUN_140323e90(local_60);
    FUN_1401171d0();
    fopen_s((FILE **)&local_58,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,
                  CONCAT26(local_58._6_2_,CONCAT24(local_58._4_2_,(undefined4)local_58)));
    FUN_140323e90(CONCAT26(local_58._6_2_,CONCAT24(local_58._4_2_,(undefined4)local_58)));
    DAT_140e471fc = 0xb4;
    DAT_140e45270 = 0x24;
  }
  if (DAT_140e45fac == 0xffffffff) {
    DAT_140e45fac = 0;
    DAT_140e418c8 = 0x21;
    DAT_140e45270 = 0x24;
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


