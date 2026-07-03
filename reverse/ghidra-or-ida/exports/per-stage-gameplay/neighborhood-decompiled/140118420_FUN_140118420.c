// Function: FUN_140118420 @ 140118420
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140118420(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  bool bVar8;
  double dVar9;
  uint uVar10;
  
  uVar10 = 0;
  iVar3 = DAT_140e445c0 + 100;
  if (DAT_140e451a4 != 0) {
    iVar3 = DAT_140e445c0 + 0x127;
  }
  FUN_14012e8e0(iVar3,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  if (DAT_140e418c8 == 200) {
    FUN_14007b710(10,0x960,0x1e0,0x96);
  }
  if (DAT_140e418c8 == 0x104) {
    FUN_14007b710(10,0x960,0xf0,200);
  }
  if (DAT_140e418c8 == 0x15e) {
    FUN_14007b710(10,2000,0x208,100);
  }
  if (DAT_140e418c8 == 0x16d) {
    FUN_14007b710(10,2000,0x168,100);
  }
  if (DAT_140e418c8 == 0x17c) {
    FUN_14007b710(10,2000,200,100);
  }
  uVar7 = (ulonglong)DAT_140e418c8;
  uVar4 = DAT_140e418c8 - 600;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0x12d + 0x3c,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 700) {
    FUN_14007b710(6,5000,0x1cc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 900) {
    FUN_14007b710(0xe,10000,0x118,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x44c) {
    FUN_14007b710(0xe,10000,0x1cc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x514;
  if ((uVar4 < 0x96) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x60e;
  if ((uVar4 < 300) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0xd,700,0x2e4,DAT_140e9fd1c % 0x65 + 0xfa);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x78a;
  if ((uVar4 < 0x78) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,500,0xffffffec,DAT_140e9fd1c % 0xc9 + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x834;
  if ((uVar4 < 0x50) && (uVar4 == ((int)uVar4 / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x898) {
    FUN_14007b710(0xf,8000,0x348,0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x8ca;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xd,700,0xffffffec,DAT_140e9fd1c % 0x65 + 0xfa);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x9f6;
  if ((uVar4 < 100) && (uVar4 == ((int)uVar4 / 10) * 10)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7;
  if (uVar4 == 0xabe) {
    FUN_14007b710(0x10,40000,0x168,0x50);
    DAT_140e418cc = 1;
LAB_140118dba:
    uVar7 = (ulonglong)DAT_140e418c8;
LAB_140118dc1:
    if ((int)uVar7 < 0xed8) goto LAB_140118eb4;
  }
  else {
    if ((DAT_140e418cc != 0) || ((int)uVar4 < 0xaf0)) goto LAB_140118dc1;
    if ((int)uVar4 < 0xed8) {
      if ((((int)uVar4 < 0xdde) && (iVar3 = (int)(uVar4 - 0xaf0) % 0x96, iVar3 < 100)) &&
         (iVar3 == (iVar3 / 0xc) * 0xc)) {
        uVar4 = ((uint)(uVar7 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar4 = uVar4 * 0x800 ^ uVar4;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
        FUN_14007b710(0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
        uVar7 = (ulonglong)DAT_140e418c8;
      }
      if ((int)uVar7 == 0xe10) {
        FUN_14007b710(0xe,7000,0x168,0);
        goto LAB_140118dba;
      }
      goto LAB_140118dc1;
    }
  }
  uVar4 = (uint)uVar7;
  if (((int)uVar4 < 0xf78) && (uVar4 - 0xed8 == ((int)(uVar4 - 0xed8) / 0x14) * 0x14)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xb,500,0x2e4,DAT_140e9fd1c % 0xc9 + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
LAB_140118eb4:
  uVar4 = (uint)uVar7 - 0xf3c;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xd,500,0xffffffec,DAT_140e9fd1c % 0x65 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x1068) {
    FUN_14007b710(0xe,7000,0x1cc,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x1108) {
    FUN_14007b710(0xf,8000,0xffffff88,100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7 - 0x1194;
  if ((uVar4 < 200) && (uVar4 = (int)uVar4 % 0x96, (int)uVar4 < 100)) {
    uVar4 = uVar4 & 0x8000000f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
    }
    if (uVar4 == 0) {
      uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar4 = uVar4 * 0x800 ^ uVar4;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
      FUN_14007b710(0xc,400,DAT_140e9fd1c % 0x191 + 0xa0,0xffffffec);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar4 = (uint)uVar7 - 0x122a;
  if ((uVar4 < 200) && (uVar4 == ((int)uVar4 / 0x1e) * 0x1e)) {
    uVar4 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar4 >> 0x1e ^ uVar4) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar4 = uVar4 * 0x800 ^ uVar4;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ uVar4 ^ DAT_140e9fd18;
    FUN_14007b710(0xd,500,0xffffffec,DAT_140e9fd1c % 0x65 + 0xfa);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar4 = (uint)uVar7;
  uVar5 = uVar4 - 0x1324;
  if ((uVar5 < 0x96) && (uVar5 == ((int)uVar5 / 0x14) * 0x14)) {
    uVar5 = ((uint)(uVar7 >> 0x1e) ^ uVar4) * 0x6c078965 + 1;
    uVar4 = uVar5 * 0x800 ^ uVar5;
    DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar4) >> 8 ^ DAT_140e9fd18 ^ uVar4;
    FUN_14007b710(0xb,400,DAT_140e9fd1c % 0xc9 + 0x168,0xffffffec);
    uVar4 = DAT_140e418c8;
  }
  if (uVar4 == 0x13ec) {
    FUN_14007b710(8,5000,0x104,0);
    uVar4 = DAT_140e418c8;
  }
  puVar2 = DAT_140e45d28;
  if ((uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
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
    uVar4 = DAT_140e418c8;
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar2;
      uVar4 = DAT_140e418c8;
    }
  }
  DAT_140e45d28 = puVar2;
  iVar3 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar3 <= (int)uVar4) &&
     ((int)uVar4 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar9 = (double)FUN_140332d90(((double)(int)uVar4 - (double)iVar3) * DAT_14053a4d8 *
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
    uVar4 = DAT_140e418c8;
    if (DAT_140e45270 != 0x2a) {
      puVar6 = &DAT_140e45100;
      do {
        FUN_14018f230(*puVar6,0);
        puVar6 = puVar6 + 1;
      } while ((longlong)puVar6 < 0x140e45178);
      _DAT_1407c777c = 1.0;
      FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e4513c);
      FUN_14018a340(DAT_140e4513c,3,1);
      DAT_140e45100 = DAT_140e4513c;
      uVar4 = DAT_140e418c8;
    }
  }
  if (uVar4 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    FUN_140078a00(0x138,100000,0,DAT_14053ae30,DAT_14053adb4,uVar10 & 0xffff0000,DAT_140539ee0,0xa0,
                  1,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 3;
  }
  return;
}


