// Function: stage_04_gameplay_update_candidate @ 14011cdd0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_04_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  bool bVar8;
  double dVar9;
  uint uVar10;
  
  uVar10 = 0;
  FUN_14012e8e0(DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar7 = (ulonglong)DAT_140e418c8;
  uVar3 = DAT_140e418c8 - 0x96;
  if ((uVar3 < 0x15e) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar6 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar6 * 0x800 ^ uVar6;
    uVar6 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (uVar6 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar6 ^ DAT_140e9fd18;
    FUN_14007b710(0x37,500,DAT_140e9fd1c % 0x191 + 0xa0,
                  ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 700;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 800) {
    FUN_14007b710(0x38,5000,0x1e0,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 900;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 1000) {
    FUN_14007b710(0x38,5000,0xf0,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x44c;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,400);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (int)uVar7 - 0x4d8;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,400);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (uint)uVar7 - 0x4d8;
  if (uVar3 < 0x50) {
    uVar3 = uVar3 & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    if (uVar3 == 0) {
      uVar6 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar6 * 0x800 ^ uVar6;
      uVar6 = uVar6 ^ uVar6 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (uVar6 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar6 ^ DAT_140e9fd18;
      FUN_14007b710(0x37,500,DAT_140e9fd1c % 0x191 + 0xa0,
                    ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x578) {
    FUN_14007b710(7,5000,0x1cc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x60e) {
    FUN_14007b710(0x3d,9000,0xffffff38,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x6d6;
  if ((uVar3 < 0x226) && (uVar3 == ((int)uVar3 / 0x78) * 0x78)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x712;
  if ((uVar3 < 0x1ea) && (uVar3 == ((int)uVar3 / 0x78) * 0x78)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    FUN_14007b710(0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x708) {
    FUN_14007b710(0x38,4000,500,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x76c) {
    FUN_14007b710(0x38,4000,0xdc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x834) {
    FUN_14007b710(0x3d,7000,0x398,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x8fc) {
    FUN_14007b710(0x38,0x1194,0xf0,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x960) {
    FUN_14007b710(0x38,0x1194,0x1e0,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x99c;
  if (uVar3 < 0x50) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,0x78);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0xa5a) {
    FUN_14007b710(0x3a,10000,0xffffffb0,200);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xb22) {
    FUN_14007b710(0x39,8000,0x262,0xffffffb0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xbea) {
    FUN_14007b710(0x39,8000,0x6e,0xffffffb0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xcb2) {
    FUN_14007b710(0x3a,8000,800,200);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0xaf0;
  if (((uVar3 < 600) && (iVar4 = (int)uVar3 % 200, iVar4 < 0x3c)) &&
     (iVar4 == (iVar4 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0xb54;
  if (((uVar3 < 500) && (iVar4 = (int)uVar3 % 200, iVar4 < 0x3c)) &&
     (iVar4 == (iVar4 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0xf1 + 0x78,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0xd34;
  if ((uVar3 < 0x46) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0xd3e;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  iVar4 = (int)uVar7;
  if (iVar4 == 0xe10) {
    FUN_14007b710(0x3f,48000,0x167,0);
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (999 < iVar4 - 0xe74U)) goto LAB_14011d9fc;
    if (iVar4 < 0x1158) {
      uVar3 = iVar4 - 0xe74U & 0x80000007;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
      }
      if (uVar3 != 0) goto LAB_14011d99f;
    }
    else {
LAB_14011d99f:
      if (0x95 < iVar4 - 0x1194U) goto LAB_14011d9fc;
      uVar3 = iVar4 - 0x1194U & 0x80000007;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
      }
      if (uVar3 != 0) goto LAB_14011d9fc;
    }
    FUN_14007b710(0x35,200,0x2e4,0x8c);
    FUN_14007b710(0x35,200,0xffffffec,0x8c);
  }
  uVar7 = (ulonglong)DAT_140e418c8;
LAB_14011d9fc:
  if ((int)uVar7 == 0x125c) {
    FUN_14007b710(0x3d,9000,0xffffff38,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x12f2;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 5000;
  if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
    uVar6 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar6 ^ uVar6 * 0x800;
    uVar6 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (uVar6 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar6 ^ DAT_140e9fd18;
    FUN_14007b710(0x37,500,DAT_140e9fd1c % 0x1e1 + 0x78,
                  ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x157c) {
    FUN_14007b710(0x38,6000,0x1cc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x15ae) {
    FUN_14007b710(0x38,6000,0x104,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x1644;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,400);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x16a8) {
    FUN_14007b710(0x38,5000,0x1fe,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x16f8;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,400);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x175c) {
    FUN_14007b710(0x38,5000,0xd2,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x17ac;
  if (uVar3 < 0x6e) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (int)uVar7 - 0x1824;
  if (uVar3 < 0x6e) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (int)uVar7 - 0x189c;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,0x15e);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x1900) {
    FUN_14007b710(0x38,4000,0x1e0,0);
    FUN_14007b710(0x38,4000,0xf0,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if (((int)uVar7 == 0x1964) || ((int)uVar7 == 0x1bbc)) {
    FUN_14007b710(0x39,6000,0x6e,0xffffffb0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if (((int)uVar7 == 0x19fa) || ((int)uVar7 == 0x1c52)) {
    FUN_14007b710(0x39,6000,0x262,0xffffffb0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if (((int)uVar7 == 0x1a90) || ((int)uVar7 == 0x1ce8)) {
    FUN_14007b710(0x3a,6000,0xffffffb0,200);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if (((int)uVar7 == 0x1b26) || ((int)uVar7 == 0x1d7e)) {
    FUN_14007b710(0x3a,6000,800,200);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x1996;
  if ((uVar3 < 0x47e) && (uVar3 == ((int)uVar3 / 0x4b) * 0x4b)) {
    uVar6 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar6 * 0x800 ^ uVar6;
    uVar6 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (uVar6 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar6 ^ DAT_140e9fd18;
    FUN_14007b710(0x37,500,DAT_140e9fd1c % 0x1e1 + 0x78,
                  ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x97 + 400);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x1e78;
  if (uVar3 < 0x3c) {
    uVar3 = uVar3 & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    if (uVar3 == 0) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      FUN_14007b710(0x36,400,0xffffffec,DAT_140e9fd1c % 0xc9 + 300);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (uint)uVar7 - 0x1eb4;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x1f18;
  if (uVar3 < 0x3c) {
    uVar3 = uVar3 & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    if (uVar3 == 0) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      FUN_14007b710(0x36,400,0x2e4,DAT_140e9fd1c % 0xc9 + 300);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (uint)uVar7 - 0x1f54;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,0x2e4,DAT_140e9fd1c % 0x97 + 0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2008) {
    FUN_14007b710(0x38,5000,0xdc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x203a) {
    FUN_14007b710(0x38,5000,500,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x20d0;
  if (uVar3 < 0x96) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,200,0x2e4,0x96);
      FUN_14007b710(0x35,200,0xffffffec,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x2198) {
    FUN_14007b710(0x3d,7000,0x398,0x78);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x21e8;
  if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,0xffffffec,DAT_140e9fd1c % 0x97 + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2260) {
    FUN_14007b710(0x3d,7000,0xffffff38,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x22b0;
  if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,0x2e4,DAT_140e9fd1c % 0x97 + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 9000) {
    FUN_14007b710(0x3d,7000,0x398,0xb4);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x238c) {
    FUN_14007b710(0x38,5000,200,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x23dc;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0x2e4,0xb4);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x2454) {
    FUN_14007b710(0x3d,7000,0x398,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x24a4;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      FUN_14007b710(0x35,0xfa,0xffffffec,0x15e);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar7 == 0x251c) {
    FUN_14007b710(0x3d,7000,0xffffff38,0x78);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2580) {
    FUN_14007b710(0x39,6000,0x262,0xffffffb0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x25d0;
  if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2648) {
    FUN_14007b710(0x3f,44000,0x169,0);
    uVar7 = (ulonglong)DAT_140e418c8;
    DAT_140e418cc = 1;
  }
  uVar3 = (uint)uVar7 - 0x28a0;
  if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {
    uVar6 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    uVar3 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7;
  if ((((DAT_140e418cc == 0) && (uVar3 - 0x25e4 < 0x3e9)) && (uVar6 = uVar3 - 0x2648, uVar6 < 0x385)
      ) && (uVar6 == ((int)uVar6 / 100) * 100)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    FUN_14007b710(0x38,5000,DAT_140e9fd1c % 0x169 + 0xb4,0);
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == 0x2a30) {
    FUN_14007b710(0x38,4000,0x1e0,0);
    FUN_14007b710(0x38,4000,0xf0,0);
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 - 0x2a94 < 0x5a) {
    uVar6 = uVar3 - 0x2a94 & 0x80000007;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
    }
    if (uVar6 == 0) {
      FUN_14007b710(0x35,200,0x2e4,0x78);
      uVar3 = DAT_140e418c8;
    }
  }
  if (uVar3 - 0x2aee < 0x5a) {
    uVar6 = uVar3 - 0x2aee & 0x80000007;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
    }
    if (uVar6 == 0) {
      FUN_14007b710(0x35,200,0xffffffec,0x96);
      uVar3 = DAT_140e418c8;
    }
  }
  if (uVar3 == 0x2b5c) {
    FUN_14007b710(8,5000,0x104,0);
    uVar3 = DAT_140e418c8;
  }
  puVar2 = DAT_140e45d28;
  if ((uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar1 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar2 = (undefined8 *)_malloc_base(0x60);
    if (puVar2 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar8 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar2 = 1;
    *(undefined4 *)(puVar2 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar2 + 0xc) = uVar1;
    puVar2[2] = 0x6f;
    puVar2[3] = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    *(undefined2 *)((longlong)puVar2 + 0x24) = 0;
    puVar2[5] = 0;
    puVar2[6] = 0x3ff0000000000000;
    puVar2[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar2 + 8) = 300;
    *(undefined4 *)((longlong)puVar2 + 0x44) = 0xff;
    *(undefined4 *)(puVar2 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar2 + 0x4c) = 0xff;
    puVar2[10] = 0xff;
    puVar2[0xb] = 0;
    if (bVar8) {
      DAT_140e45d78 = puVar2;
    }
    uVar3 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar2;
      uVar3 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar2;
  iVar4 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar4 <= (int)uVar3) &&
     ((int)uVar3 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar9 = (double)FUN_140332d90(((double)(int)uVar3 - (double)iVar4) * DAT_14053a4d8 *
                                  DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar9 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    uVar3 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar3) &&
     ((int)uVar3 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    FUN_140079b00();
    FUN_14006c420();
    puVar5 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar5,0);
      puVar5 = puVar5 + 1;
    } while ((longlong)puVar5 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e45140);
    FUN_14018a340(DAT_140e45140,3,1);
    DAT_140e45100 = DAT_140e45140;
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x13b,100000,0,DAT_14053ae30,DAT_14053ad40,uVar10 & 0xffff0000,DAT_140539ee0,200,1
                  ,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 4;
  }
  return;
}


