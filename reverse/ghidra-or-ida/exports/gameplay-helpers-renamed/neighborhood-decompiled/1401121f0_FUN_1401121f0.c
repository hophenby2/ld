// Function: FUN_1401121f0 @ 1401121f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401121f0(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  
  _DAT_140e45280 = 200;
  _DAT_140e45288 = 0x2020;
  DAT_140e4528a = 0x20;
  DAT_140e45290 = FUN_14032f8bc(0);
  DAT_140e452a4 = DAT_140e45268;
  DAT_140e452a8 = DAT_140e451a4;
  DAT_140e452e8 = DAT_140e44194;
  DAT_140e452ec = DAT_140e41b70;
  DAT_140e452a0 = DAT_140e419b8;
  DAT_140e45298 = DAT_140e41928;
  DAT_140e4529c = DAT_140e41abc;
  DAT_140e452ac = DAT_140e445c0;
  DAT_140e452b0 = DAT_140e445c4;
  DAT_140e452b4 = DAT_140e445c8;
  DAT_140e452b8 = DAT_140e445cc;
  DAT_140e452bc = DAT_140e445d0;
  DAT_140e452c0 = DAT_1407c7798;
  _DAT_140e452c4 = 1;
  DAT_140e452c8 = 2;
  DAT_140e452cc = 4;
  DAT_140e452d0 = 6;
  _DAT_140e452d8 = 0;
  _DAT_140e452e0 = 0;
  DAT_140e452f0 = DAT_140e44198;
  iVar5 = DAT_140e41928;
  if (DAT_140e44198 == 0) {
    iVar3 = DAT_1407c7798;
    if (DAT_140e41928 != 0) {
      if (DAT_140e41928 != 1) goto LAB_140112301;
      iVar3 = DAT_140e41abc + 0xb;
    }
    DAT_140e452f0 = FUN_140135290(iVar3);
  }
LAB_140112301:
  DAT_140e46b28 = 0;
  DAT_140e41a38 = 1;
  puVar2 = &DAT_140e45340;
  DAT_140e41b08 = 1;
  DAT_140e41a3c = 1;
  puVar4 = (undefined8 *)&DAT_140e45cc8;
  do {
    *(undefined4 *)(puVar2 + -5) = 0;
    *(undefined4 *)(puVar2 + -1) = 0x43b40000;
    *(undefined4 *)((longlong)puVar2 + -4) = 0x44160000;
    *puVar2 = puVar2[-1];
    *(undefined4 *)((longlong)puVar2 + -0xc) = 1;
    *(undefined2 *)(puVar2 + 1) = 0xc000;
    puVar2[2] = 0;
    *(undefined2 *)((longlong)puVar2 + 0x5c) = 0xc000;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    puVar2[0xd] = 0x20;
    *(undefined4 *)(puVar2 + 0xe) = 0;
    *(undefined8 *)((longlong)puVar2 + 0x74) = 0x3c;
    *(undefined4 *)((longlong)puVar2 + 0x24) = 0x43b40000;
    *(undefined4 *)(puVar2 + 5) = 0x44160000;
    *(undefined4 *)((longlong)puVar2 + 0x44) = 0xc000c000;
    *(undefined8 *)((longlong)puVar2 + 0x4c) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x2c) = 0x43b40000;
    *(undefined4 *)(puVar2 + 6) = 0x44160000;
    *(undefined4 *)((longlong)puVar2 + 0x34) = 0x43b40000;
    *(undefined4 *)(puVar2 + 7) = 0x44160000;
    *(undefined4 *)(puVar2 + 9) = 0xc000c000;
    *(undefined8 *)((longlong)puVar2 + 0x54) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x3c) = 0x43b40000;
    *(undefined4 *)(puVar2 + 8) = 0x44160000;
    *(undefined4 *)(puVar2 + 3) = 2;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    *(undefined4 *)(puVar2 + 0x12) = 0;
    puVar2[0x13] = 0;
    puVar2[0x15] = 0;
    puVar2[0x14] = 0;
    puVar2[0x16] = 0;
    *(undefined4 *)(puVar2 + 0x17) = 0;
    *(undefined4 *)(puVar2 + 0x18) = 0;
    puVar2 = puVar2 + 0x1e;
    puVar4[-10] = 0;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  } while ((longlong)puVar2 < 0x140e45ca0);
  lVar1 = DAT_140e45278;
  if (iVar5 == 2) {
    _DAT_140e452f4 = CONCAT44(DAT_140e43efc,DAT_140e43ef8);
    _DAT_140e45304 = (undefined4)_DAT_140e43f08;
    uRam0000000140e45308 = (undefined4)((ulonglong)_DAT_140e43f08 >> 0x20);
    uRam0000000140e4530c = (undefined4)_DAT_140e43f10;
    _DAT_140e45310 = (undefined4)((ulonglong)_DAT_140e43f10 >> 0x20);
    _DAT_140e452fc = DAT_140e43f00;
    _DAT_140e45300 = DAT_140e43f04;
  }
  else {
    _DAT_140e452f4 = 1;
    _DAT_140e45300 = 0;
    _DAT_140e45304 = 0;
    uRam0000000140e45308 = 0;
    uRam0000000140e4530c = 0;
    _DAT_140e452fc = 0;
    _DAT_140e45310 = 0;
  }
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 8);
    FUN_140323ce8();
  }
  DAT_140e9fd00 = 0;
  DAT_140e45278 = 0;
  return;
}


