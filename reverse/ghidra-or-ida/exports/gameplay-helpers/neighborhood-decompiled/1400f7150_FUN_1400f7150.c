// Function: FUN_1400f7150 @ 1400f7150
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400f7150(void)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  bool bVar8;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar4 = DAT_140e45268;
  iVar1 = DAT_140e41abc;
  DAT_140e46ae0 = 0;
  iVar6 = DAT_140e445c0;
  if (DAT_140e41928 == 0) {
    lVar2 = (longlong)DAT_1407c7798 * 3 + (longlong)DAT_140e445c0;
    DAT_140e46ae0 =
         (&DAT_140e41bd0)[lVar2 * 0x19 + (longlong)DAT_140e419b8 * 2 + (longlong)DAT_140e45268];
    if (DAT_140e41b00 == 0) {
      (&DAT_140e41b80)[lVar2 * 0x32 + (longlong)DAT_140e419b8] =
           (&DAT_140e41b80)[lVar2 * 0x32 + (longlong)DAT_140e419b8] + 1;
    }
  }
  else if (DAT_140e41928 == 1) {
    lVar7 = (longlong)DAT_140e419b8;
    lVar2 = (longlong)DAT_140e445c0;
    if (DAT_1407c7798 == 10) {
      DAT_140e46ae0 = *(undefined8 *)(&DAT_140e43360 + (lVar2 * 0x19 + (longlong)DAT_140e45268) * 8)
      ;
      if (DAT_140e41b00 == 0) {
        *(int *)(&DAT_140e432f8 + lVar2 * 200) = *(int *)(&DAT_140e432f8 + lVar2 * 200) + 1;
      }
    }
    else {
      lVar2 = (longlong)(DAT_140e41abc + 0xb) * 3 + lVar2;
      DAT_140e46ae0 = (&DAT_140e41bd0)[lVar2 * 0x19 + lVar7 * 2 + (longlong)DAT_140e45268];
      if (DAT_140e41b00 == 0) {
        (&DAT_140e41b80)[lVar2 * 0x32 + lVar7] = (&DAT_140e41b80)[lVar2 * 0x32 + lVar7] + 1;
      }
    }
    if (iVar1 == 3) {
      DAT_140e46bb8 =
           *(undefined4 *)
            (&DAT_140e43cf0 + ((longlong)iVar4 + ((longlong)iVar6 * 0x19 + lVar7) * 2) * 4);
    }
  }
  FUN_1400f6c40();
  if (DAT_140e45270 != 0x2a) {
    puVar3 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar3,0);
      puVar3 = puVar3 + 1;
    } while ((longlong)puVar3 < 0x140e45178);
  }
  iVar1 = DAT_140e41b00;
  iVar5 = 1;
  iVar6 = 1;
  DAT_140e418c8 = DAT_140e46a1c;
  DAT_140e45d74 = DAT_140e46a1c;
  iVar4 = DAT_140e41928;
  if (DAT_140e41928 == 1) {
    if (DAT_140e41abc < 0) {
      DAT_1407c7798 = 10;
      bVar8 = DAT_140e41abc == 3;
      DAT_140e419b8 = 2;
    }
    else {
      if (DAT_140e41b00 == 0) {
        DAT_1407c7798 = 1;
      }
      if (DAT_140e41abc == 1) {
        DAT_140e418c8 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x14a;
        DAT_140e45d74 = DAT_140e418c8;
        goto LAB_1400f7409;
      }
LAB_1400f73f5:
      bVar8 = DAT_140e41abc == 3;
    }
LAB_1400f7407:
    if (bVar8) goto LAB_1400f740c;
  }
  else {
    if (DAT_140e41928 == 2) {
      if (DAT_140e41b00 == 0) {
        local_28 = DAT_140e43ef8;
        uStack_24 = DAT_140e43efc;
        uStack_20 = DAT_140e43f00;
        iStack_1c = DAT_140e43f04;
        local_18 = DAT_140e43f08;
        uStack_14 = DAT_140e43f0c;
        uStack_10 = DAT_140e43f10;
        uStack_c = DAT_140e43f14;
        FUN_1401105c0(&local_28);
        iVar6 = iVar5;
      }
      else {
        local_28 = _DAT_140e452f4;
        uStack_24 = uRam0000000140e452f8;
        uStack_20 = _DAT_140e452fc;
        iStack_1c = _DAT_140e45300;
        local_18 = _DAT_140e45304;
        uStack_14 = uRam0000000140e45308;
        uStack_10 = uRam0000000140e4530c;
        uStack_c = _DAT_140e45310;
        FUN_1401105c0(&local_28);
        iVar6 = iVar5;
      }
LAB_1400f7400:
      bVar8 = DAT_140e43f04 == iVar6;
      goto LAB_1400f7407;
    }
    if (DAT_140e41928 == -1) {
      DAT_140e445d0 = 0;
      _DAT_140e445c0 = 0;
      _DAT_140e445c8 = 0;
      DAT_1407c7798 = 0;
      DAT_140e419b8 = 0;
      DAT_140e46804 = 0;
      DAT_140e9fd0c = 0;
      DAT_140e418c8 = 0;
      DAT_140e45d74 = 0;
    }
    else {
      if (DAT_140e41928 == 1) goto LAB_1400f73f5;
      iVar6 = 1;
      if (DAT_140e41928 == 2) goto LAB_1400f7400;
    }
  }
LAB_1400f7409:
  iVar6 = 0;
LAB_1400f740c:
  DAT_140e451a4 = iVar6;
  if (iVar1 == 0) {
    FUN_1401121f0();
    iVar4 = DAT_140e41928;
  }
  else {
    DAT_140e46b28 = 0;
  }
  if (DAT_140e45270 != 0x2a) {
    DAT_140e45270 = (iVar4 == -1) + 0x14;
  }
  return;
}


