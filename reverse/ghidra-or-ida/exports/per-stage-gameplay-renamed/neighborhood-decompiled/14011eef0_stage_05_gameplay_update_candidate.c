// Function: stage_05_gameplay_update_candidate @ 14011eef0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_05_gameplay_update_candidate(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  double dVar9;
  uint uVar10;
  
  uVar10 = 0;
  FUN_14012e8e0(DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar6 = (ulonglong)DAT_140e418c8;
  uVar4 = DAT_140e418c8 - 0xfa;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {
    uVar4 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x15f + 0x168,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x15e) {
    FUN_14007b710(0x46,3000,0x42e,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x17c) {
    FUN_14007b710(0x46,3000,0x366,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1c2;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x15f + 10,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x226) {
    FUN_14007b710(0x46,3000,0xfffffea2,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x244) {
    FUN_14007b710(0x46,3000,0xffffff6a,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x294;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x45,500,0x2e4,DAT_140e9fd1c % 0x97 + 0x78);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 800) {
    FUN_14007b710(7,5000,0x1cc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 900) {
    FUN_14007b710(0x47,3000,0x104,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x410;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x1f) * 0x1f)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,400,DAT_140e9fd1c % 0x97 + 0x19a,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x492;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x18) * 0x18)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,400,0xffffffec,DAT_140e9fd1c % 0x97 + 0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x4f6) {
    FUN_14007b710(0x46,3000,0x3fc,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x51e) {
    FUN_14007b710(0x46,3000,0xfffffed4,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x564;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0xe) * 0xe)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x640) {
    FUN_14007b710(0x46,0x960,0xfffffe70,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x65e) {
    FUN_14007b710(0x46,0x960,0xffffff06,0x4b);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x67c) {
    FUN_14007b710(0x46,0x960,0xffffff9c,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x6b8) {
    FUN_14007b710(0x46,0x960,0x398,0x1e);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x708) {
    FUN_14007b710(0x4a,11000,0x1cc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x7f8) {
    FUN_14007b710(0x4a,9000,0x104,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x884;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x8e8) {
    FUN_14007b710(0x4a,9000,0x19a,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x974;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0xf) * 0xf)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,300,DAT_140e9fd1c % 0x12d + 0xa0,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x9c4) {
    FUN_14007b710(0x4a,9000,0x136,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xa8c) {
    FUN_14007b710(0x29,7000,0xf0,300);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0xabe;
  if ((uVar4 < 0x32) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x1c3 + 0x104,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0xb22;
  if ((uVar4 < 0x32) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x1c3 + 10,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xb54) {
    FUN_14007b710(0x48,0x960,0x1cc,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0xbea;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,300,0xffffffec,DAT_140e9fd1c % 0x97 + 100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xc6c) {
    FUN_14007b710(0x46,0x960,0x3fc,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xc80) {
    FUN_14007b710(0x46,0x960,0xfffffed4,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xcbc) {
    FUN_14007b710(0x46,0x960,0x42e,0x14);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xcd0) {
    FUN_14007b710(0x46,0x960,0xfffffea2,0x14);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0xd7a;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x2bd + 10,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xe10) {
    FUN_14007b710(0x4d,6000,0xffffff6a,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0xf6e) {
    FUN_14007b710(0x29,7000,0x1e0,0xfa);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (int)uVar6 - 0xfd2;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x3c) * 0x3c)) {
    FUN_14007b710(0x45,300,0xb4,0xffffffec);
    FUN_14007b710(0x45,300,0x168,0xffffffec);
    FUN_14007b710(0x45,300,0x21c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1068) {
    FUN_14007b710(0x4d,6000,0x366,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1162;
  if ((uVar4 < 0x82) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x2bd + 10,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1220;
  if ((uVar4 < 0x32a) && (uVar4 == ((int)uVar4 / 0x60) * 0x60)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x45,300,0x2e4,DAT_140e9fd1c % 0xc9 + 0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1250;
  if ((uVar4 < 0x2fa) && (uVar4 == ((int)uVar4 / 0x60) * 0x60)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,300,0xffffffec,DAT_140e9fd1c % 0xc9 + 0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x12c0) {
    FUN_14007b710(0x4a,7000,0x104,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 5000) {
    FUN_14007b710(0x4a,7000,0x1cc,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x14c8) {
    FUN_14007b710(0x46,0x960,0xffffff9c,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x14e6) {
    FUN_14007b710(0x46,0x960,0xffffff06,0x4b);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1504) {
    FUN_14007b710(0x46,0x960,0xfffffe70,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x157c) {
    FUN_14007b710(0x47,0x960,0xf0,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1608;
  if (uVar4 < 0x82) {
    uVar4 = uVar4 & 0x8000001f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
    }
    if (uVar4 == 0) {
      uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar4 * 0x800 ^ uVar4;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0xb,300,DAT_140e9fd1c % 0xf1 + 0x168,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x16a8) {
    FUN_14007b710(0x48,0x960,0x1e0,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x1734;
  if (uVar4 < 0x82) {
    uVar4 = uVar4 & 0x8000001f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
    }
    if (uVar4 == 0) {
      uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      uVar4 = uVar7 * 0x800 ^ uVar7;
      DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0xb,300,DAT_140e9fd1c % 0xf1 + 0x78,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x17d4) {
    FUN_14007b710(0x47,0x960,0xf0,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6;
  if (uVar4 == 0x18ce) {
    FUN_14007b710(0x4f,60000,0x168,200);
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (uVar7 = uVar4 - 0x1900, 0x513 < uVar7)) goto LAB_1401207da;
    if (((int)uVar4 < 0x1de2) && (uVar7 == ((int)uVar7 / 0x96) * 0x96)) {
      uVar7 = ((uint)(uVar6 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar7 ^ uVar7 * 0x800;
      uVar7 = uVar7 * 0x800 ^ uVar7;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
      FUN_14007b710(0x46,2000,DAT_140e9fd1c % 0x65 - 0x15e,
                    ((DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4) % 0x65);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    uVar4 = (uint)uVar6 - 0x194b;
    if ((uVar4 < 0x497) && (uVar4 == ((int)uVar4 / 0x96) * 0x96)) {
      uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar7 ^ uVar7 * 0x800;
      uVar7 = uVar7 ^ uVar7 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar7) >> 8 ^ DAT_140e9fd18 ^ uVar7;
      FUN_14007b710(0x46,2000,DAT_140e9fd1c % 0x65 + 0x3ca,
                    ((DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4) % 0x65);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
    uVar4 = (uint)uVar6 - 0x1900;
    if ((0x513 < uVar4) || (uVar4 != ((int)uVar4 / 0x11) * 0x11)) goto LAB_1401207da;
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x45,300,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
  }
  uVar6 = (ulonglong)DAT_140e418c8;
LAB_1401207da:
  if ((int)uVar6 == 0x1e3c) {
    FUN_14007b710(0x46,0x898,0xffffff9c,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1e50) {
    FUN_14007b710(0x46,0x898,0xffffff06,0x4b);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1e64) {
    FUN_14007b710(0x46,0x898,0xfffffe70,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1eaa) {
    FUN_14007b710(0x46,0x898,0x334,0x4b);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1ebe) {
    FUN_14007b710(0x46,0x898,0x3ca,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1ed2) {
    FUN_14007b710(0x46,0x898,0x460,0x19);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 8000) {
    FUN_14007b710(0x46,0x640,0xfffffe70,100);
    FUN_14007b710(0x46,0x640,0x460,0x78);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1f72) {
    FUN_14007b710(0x46,0x640,0xffffff06,100);
    FUN_14007b710(0x46,0x640,0x3ca,0x3c);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x1fa4) {
    FUN_14007b710(0x46,0x640,0xffffff9c,100);
    FUN_14007b710(0x46,0x640,0x334,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x203a) {
    FUN_14007b710(0x47,0x960,0xf0,200);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x20d0) {
    FUN_14007b710(0x48,0x960,0x1e0,0x96);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x2166;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0xfb + 0xa0,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x21fc;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x15f + 0x136,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2260) {
    FUN_14007b710(0x4a,8000,0x136,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 9000;
  if (uVar4 < 0x8c) {
    uVar4 = uVar4 & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    if (uVar4 == 0) {
      uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar4 * 0x800 ^ uVar4;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar6 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar6 == 0x23f0) {
    FUN_14007b710(0x4d,6000,0x366,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x24ea) {
    FUN_14007b710(0x46,0x898,0xffffff06,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2508) {
    FUN_14007b710(0x46,0x898,0xfffffe70,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x254e) {
    FUN_14007b710(0x46,0x898,0x3ca,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x256c) {
    FUN_14007b710(0x46,0x898,0x460,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x25d0;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 0x11) * 0x11)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,300,0xffffffec,DAT_140e9fd1c % 0x97 + 100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x2648;
  if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,300,DAT_140e9fd1c % 0x12d + 0x104,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x26ac) {
    FUN_14007b710(0x4a,10000,0x136,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x27a6) {
    FUN_14007b710(0x4d,6000,0xffffff6a,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x28a0;
  if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x13) * 0x13)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0x45,300,0x2e4,DAT_140e9fd1c % 0x97 + 100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6 - 0x2954;
  if ((uVar4 < 0xa0) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar7 = ((uint)(uVar6 >> 0x1e) ^ (uint)uVar6) * 0x6c078965 + 1;
    uVar4 = uVar7 * 0x800 ^ uVar7;
    DAT_140e9fd10 = (uVar7 >> 0x1e ^ uVar7) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x29fe) {
    FUN_14007b710(0x46,0x898,0xfffffe70,100);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2a1c) {
    FUN_14007b710(0x46,0x898,0xffffff06,0x32);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar6 == 0x2a3a) {
    FUN_14007b710(0x46,0x898,0xffffff9c,0);
    uVar6 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar6;
  uVar7 = uVar4 - 0x2a94;
  if ((uVar7 < 200) && (uVar7 == ((int)uVar7 / 0x11) * 0x11)) {
    uVar4 = ((uint)(uVar6 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0x45,300,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec);
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == 0x2b5c) {
    FUN_14007b710(8,5000,0x104,0);
    uVar4 = DAT_140e418c8;
  }
  puVar3 = DAT_140e45d28;
  if ((uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar2 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar3 = (undefined8 *)_malloc_base(0x60);
    if (puVar3 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar8 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar3 = 1;
    *(undefined4 *)(puVar3 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar3 + 0xc) = uVar2;
    puVar3[2] = 0x6f;
    puVar3[3] = 0;
    *(undefined4 *)(puVar3 + 4) = 0;
    *(undefined2 *)((longlong)puVar3 + 0x24) = 0;
    puVar3[5] = 0;
    puVar3[6] = 0x3ff0000000000000;
    puVar3[7] = 0x3ff0000000000000;
    *(undefined4 *)(puVar3 + 8) = 300;
    *(undefined4 *)((longlong)puVar3 + 0x44) = 0xff;
    *(undefined4 *)(puVar3 + 9) = 0xff;
    *(undefined4 *)((longlong)puVar3 + 0x4c) = 0xff;
    puVar3[10] = 0xff;
    puVar3[0xb] = 0;
    if (bVar8) {
      DAT_140e45d78 = puVar3;
    }
    uVar4 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar3;
      uVar4 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar3;
  iVar1 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar1 <= (int)uVar4) &&
     ((int)uVar4 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar9 = (double)FUN_140332d90(((double)(int)uVar4 - (double)iVar1) * DAT_14053a4d8 *
                                  DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar9 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64 * _DAT_1407c777c),DAT_140e45100);
    uVar4 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar4) &&
     ((int)uVar4 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
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
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x13c,100000,0,DAT_14053ae30,DAT_14053adb4,uVar10 & 0xffff0000,DAT_140539ee0,0xaf,
                  1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 6;
  }
  return;
}


