// Function: stage_07_gameplay_update_candidate @ 140123620
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_07_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  float fVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  bool bVar10;
  double dVar11;
  uint uVar12;
  
  uVar12 = 0;
  FUN_14012e8e0(DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar9 = (ulonglong)DAT_140e418c8;
  uVar7 = DAT_140e418c8 - 0x10e;
  if ((uVar7 < 0x82) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {
    FUN_14007b710(0x74,0x4b0,(int)(uVar7 * 6) % 0x168 + 0xb4,0x334);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 500) {
    FUN_14007b710(0x71,0x1130,0x1e0,200);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x244) {
    FUN_14007b710(0x71,0x1130,0xd2,0x10e);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0x2ee;
  if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x23) * 0x23)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,700,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0x366;
  if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x23) * 0x23)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,700,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (int)uVar9 - 0x3ac;
  if ((uVar7 < 0x82) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {
    FUN_14007b710(0x74,0x4b0,(int)(uVar7 * 6) % 0x168 + 0xb4,0x334);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0x49c;
  if ((uVar7 < 0x5a) && (uVar7 == ((int)uVar7 / 0x19) * 0x19)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
    FUN_14007b710(0x70,0x4b0,DAT_140e9fd1c % 0x259 + 0x3c,0x30c);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x514) {
    FUN_14007b710(7,5000,0x168,0);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x5b4) {
    FUN_14007b710(0x73,7000,0xf0,0);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x6a4) {
    FUN_14007b710(0x73,6000,0x1e0,0);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (int)uVar9 - 0x60e;
  if ((uVar7 < 200) && (uVar7 == ((int)uVar7 / 0x2b) * 0x2b)) {
    FUN_14007b710(0x74,0x4b0,0x21c - (int)(uVar7 * 3) % 0x168,0x334);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x758) {
    FUN_14007b710(0x72,0xce4,0x1fe,0xfa);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x794) {
    FUN_14007b710(0x72,0xce4,0x168,200);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 2000) {
    FUN_14007b710(0x72,0xce4,0xd2,0x96);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (int)uVar9 - 0x834;
  if ((uVar7 < 0x8c) && (uVar7 == ((int)uVar7 / 0x13) * 0x13)) {
    FUN_14007b710(0x74,1000,0x21c - (((int)uVar9 + -0x60e) * 6) % 0x168,0x334);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x960) {
    FUN_14007b710(0x26,5000,0x208,0xffffffec);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x9c4) {
    FUN_14007b710(0x26,5000,200,0xffffffec);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0xa14;
  if ((uVar7 < 0x3c) && (uVar7 == ((int)uVar7 / 0xc) * 0xc)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
    FUN_14007b710(0x70,0x4b0,DAT_140e9fd1c % 0x259 + 0x3c,0x30c);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0xaf0) {
    FUN_14007b710(0x76,18000,0x1ea,0x348);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0xb86;
  if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,500,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0xc80;
  if ((uVar7 < 0xa0) && (uVar7 == ((int)uVar7 / 0x28) * 0x28)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,0x4b0,DAT_140e9fd1c % 0xfb + 0xa0,0x30c);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0xd0c;
  if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
    FUN_14007b710(0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0xd5c) {
    FUN_14007b710(0x76,15000,0xe6,0x348);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0xd84) {
    FUN_14007b710(0x75,0x960,0x1ae,0x302);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0xdfc) {
    FUN_14007b710(0x75,0x960,0x212,0x366);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0xeec;
  if ((uVar7 < 0xaa) && (uVar7 == ((int)uVar7 / 10) * 10)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar1 = DAT_14053af80;
  uVar2 = DAT_140539ee0;
  iVar5 = (int)uVar9;
  if (iVar5 == 0xfb4) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x144,100000,0,DAT_14053ae30,DAT_14053af80,uVar12,DAT_140539ee0,0x32,1,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_1401244ac:
    uVar9 = (ulonglong)DAT_140e418c8;
LAB_1401244b3:
    if (0x18ff < (int)uVar9) goto LAB_1401244bc;
  }
  else {
    if ((DAT_140e418cc != 0) || (iVar5 < 0x1068)) goto LAB_1401244b3;
    if (iVar5 < 0x1900) {
      if ((iVar5 < 0x17d4) && (iVar5 + -0x1068 == ((iVar5 + -0x1068) / 400) * 400)) {
        FUN_14007b710(0x72,0xaf0,0xe6,0xfa);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (int)uVar9 - 0x10a4;
      if ((uVar7 < 0x730) && (uVar7 == ((int)uVar7 / 400) * 400)) {
        FUN_14007b710(0x72,0xaf0,0x1ea,200);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (int)uVar9 - 0x1130;
      if ((uVar7 < 0x6a4) && (uVar7 == ((int)uVar7 / 400) * 400)) {
        FUN_14007b710(0x71,0xaf0,0x1ea,0xfa);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (int)uVar9 - 0x116c;
      if ((uVar7 < 0x668) && (uVar7 == ((int)uVar7 / 400) * 400)) {
        FUN_14007b710(0x71,0xaf0,0xe6,200);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (uint)uVar9 - 0x1068;
      if ((uVar7 < 0x76c) && (uVar7 == ((int)uVar7 / 0x32) * 0x32)) {
        uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
        FUN_14007b710(0xb,500,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 0x184c) {
        FUN_14007b710(0x73,9000,0x19a,0);
        goto LAB_1401244ac;
      }
      goto LAB_1401244b3;
    }
LAB_1401244bc:
    iVar5 = (int)uVar9;
    if ((iVar5 < 0x1996) && (iVar5 + -0x1900 == ((iVar5 + -0x1900) / 0x13) * 0x13)) {
      FUN_14007b710(0x74,1000,((iVar5 + -0x1900) * 5) % 0x168 + 0xb4,0x334);
      uVar9 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar7 = (uint)uVar9 - 0x1a04;
  if ((uVar7 < 0x50) && (uVar7 == ((int)uVar7 / 0x14) * 0x14)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,0x4b0,DAT_140e9fd1c % 0x17d + 0xaa,0xffffffc4);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x1a5e) {
    FUN_14007b710(0x77,18000,0xf0,0x398);
    uVar9 = (ulonglong)DAT_140e418c8;
    DAT_140e418cc = 1;
  }
  uVar7 = (uint)uVar9 - 0x1bbc;
  if ((uVar7 < 0xfa) && (uVar7 == ((int)uVar7 / 0x48) * 0x48)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x25,700,DAT_140e9fd1c % 0xb5 + 0x1a4,0xffffffec);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (int)uVar9 - 0x1cfc;
  if ((uVar7 < 0xb4) && (uVar7 == ((int)uVar7 / 0x27) * 0x27)) {
    FUN_14007b710(0x74,1000,(int)(uVar7 * 2) % 200 + 0x186,0x334);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if (((DAT_140e418cc == 0) && (uVar7 = (int)uVar9 - 0x1c20, uVar7 < 600)) &&
     (uVar7 == ((int)uVar7 / 0x78) * 0x78)) {
    FUN_14007b710(0x72,0xaf0,0xf0);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  uVar7 = (uint)uVar9 - 0x1eaa;
  if ((uVar7 < 100) && (uVar7 == ((int)uVar7 / 0x15) * 0x15)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,1000,DAT_140e9fd1c % 0x191 + 0xa0,0x30c);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  iVar5 = (int)uVar9;
  if (iVar5 == 8000) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x145,100000,0,DAT_14053ae30,uVar1,uVar12,uVar2,0x32,1,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_140124c2b:
    uVar9 = (ulonglong)DAT_140e418c8;
LAB_140124c32:
    if ((int)uVar9 < 0x28a0) goto LAB_140124d2e;
  }
  else {
    if ((DAT_140e418cc != 0) || (iVar5 < 0x2008)) goto LAB_140124c32;
    if (iVar5 < 0x28a0) {
      if ((iVar5 < 0x25e4) && (iVar5 + -0x2008 == ((iVar5 + -0x2008) / 0x96) * 0x96)) {
        dVar11 = (double)FUN_140332d90(((double)iVar5 - _DAT_14053ab80) * _DAT_14053a478 *
                                       DAT_14053a020 * DAT_140539d28);
        FUN_14007b710(0x73,6000,0x168 - (int)(dVar11 * DAT_14053a548),0);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      uVar7 = (uint)uVar9 - 0x2008;
      if ((uVar7 < 0x60e) && (uVar7 == ((int)uVar7 / 0x2c) * 0x2c)) {
        uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar7 = uVar7 * 0x800 ^ uVar7;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
        FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 0x2648) {
        FUN_14007b710(0x76,15000,0x168,0x348);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 0x2670) {
        FUN_14007b710(0x75,0x960,0x1cc,1000);
        FUN_14007b710(0x75,0x960,0x104,1000);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 10000) {
        FUN_14007b710(0x75,0x960,0x21c,0x366);
        FUN_14007b710(0x75,0x960,0xb4,0x366);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 0x2814) {
        FUN_14007b710(0x70,0x4b0,0x1b8,0x30c);
        FUN_14007b710(0x70,0x4b0,0x118,0x30c);
        uVar9 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar9 == 0x283c) {
        FUN_14007b710(0x70,0x4b0,0x208,0x30c);
        FUN_14007b710(0x70,0x4b0,200,0x30c);
        goto LAB_140124c2b;
      }
      goto LAB_140124c32;
    }
  }
  uVar7 = (uint)uVar9;
  if (((int)uVar7 < 0x2968) && (uVar7 - 0x28a0 == ((int)(uVar7 - 0x28a0) / 10) * 10)) {
    uVar8 = ((uint)(uVar9 >> 0x1e) ^ uVar7) * 0x6c078965 + 1;
    uVar7 = uVar8 * 0x800 ^ uVar8;
    DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
LAB_140124d2e:
  if ((int)uVar9 == 0x2968) {
    FUN_14007b710(0x77,18000,0x1e0,0x398);
    uVar9 = (ulonglong)DAT_140e418c8;
    DAT_140e418cc = 1;
  }
  uVar7 = (uint)uVar9 - 0x29fe;
  if (((uVar7 < 0x1c2) && (iVar5 = (int)uVar7 % 0x10e, iVar5 < 0x3c)) &&
     (iVar5 == (iVar5 / 0x1e) * 0x1e)) {
    uVar7 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar7 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0x70,700,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar9 == 0x2c24) {
    FUN_14007b710(0x76,15000,0xe6,0x348);
    uVar9 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 0) {
    uVar7 = (uint)uVar9 - 0x2cba;
    if ((uVar7 < 0x78) && (uVar7 == ((int)uVar7 / 0x1e) * 0x1e)) {
      uVar8 = ((uint)(uVar9 >> 0x1e) ^ (uint)uVar9) * 0x6c078965 + 1;
      uVar7 = uVar8 * 0x800 ^ uVar8;
      DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
      FUN_14007b710(0x70,700,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
      uVar9 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar7 = (uint)uVar9;
  uVar8 = uVar7 - 0x2db4;
  if ((uVar8 < 100) && (uVar8 == ((int)uVar8 / 10) * 10)) {
    uVar8 = ((uint)(uVar9 >> 0x1e) ^ uVar7) * 0x6c078965 + 1;
    uVar7 = uVar8 * 0x800 ^ uVar8;
    DAT_140e9fd10 = (uVar8 >> 0x1e ^ uVar8) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ uVar7 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
    uVar7 = DAT_140e418c8;
  }
  if (uVar7 == 0x2e18) {
    FUN_14007b710(8,5000,0x1cc,0);
    uVar7 = DAT_140e418c8;
  }
  puVar4 = DAT_140e45d28;
  if ((uVar7 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar1 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar4 = (undefined8 *)_malloc_base(0x60);
    if (puVar4 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar10 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar4 = 1;
    *(undefined4 *)(puVar4 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
    puVar4[2] = 0x6f;
    puVar4[3] = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
    puVar4[5] = 0;
    puVar4[6] = 0x3ff0000000000000;
    puVar4[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar4 + 8) = 300;
    *(undefined4 *)((longlong)puVar4 + 0x44) = 0xff;
    *(undefined4 *)(puVar4 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar4 + 0x4c) = 0xff;
    puVar4[10] = 0xff;
    puVar4[0xb] = 0;
    if (bVar10) {
      DAT_140e45d78 = puVar4;
    }
    uVar7 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar4;
      uVar7 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar4;
  fVar3 = DAT_14053ac64;
  iVar5 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar5 <= (int)uVar7) &&
     ((int)uVar7 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar11 = (double)FUN_140332d90(((double)(int)uVar7 - (double)iVar5) * DAT_14053a4d8 *
                                   DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar11 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * fVar3 * _DAT_1407c777c),DAT_140e45100);
    uVar7 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar7) &&
     ((int)uVar7 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar7 = DAT_140e418c8;
  }
  if (uVar7 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    FUN_140079b00();
    FUN_14006c420();
    puVar6 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar6,0);
      puVar6 = puVar6 + 1;
    } while ((longlong)puVar6 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * fVar3),DAT_140e45140);
    FUN_14018a340(DAT_140e45140,3,1);
    DAT_140e45100 = DAT_140e45140;
    uVar7 = DAT_140e418c8;
  }
  if (uVar7 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x13e,100000,0,DAT_14053ae30,DAT_14053ade8,uVar12 & 0xffff0000,DAT_140539ec8,0xd2,
                  1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 5;
  }
  return;
}


