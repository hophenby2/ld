// Function: stage_10_gameplay_update_candidate @ 14012b260
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_10_gameplay_update_candidate(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  uVar4 = (ulonglong)DAT_140e418c8;
  if (DAT_140e418c8 == 1) {
    DAT_140e418cc = DAT_140e418c8;
  }
  if ((DAT_140e418c8 == 0x32) &&
     (uVar1 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar2 = (undefined8 *)_malloc_base(0x60);
    if (puVar2 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
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
    if (bVar7) {
      DAT_140e45d78 = puVar2;
    }
    if (DAT_140e45d28 != (undefined8 *)0x0) {
      DAT_140e45d28[0xb] = puVar2;
    }
    uVar4 = (ulonglong)DAT_140e418c8;
    DAT_140e45d28 = puVar2;
  }
  if ((int)uVar4 - 0x32U < 0x12d) {
    FUN_140001060(0x32);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x140) {
    _DAT_1407c777c = 0x3f800000;
    FUN_140184700((int)((float)DAT_140e4418c * DAT_14053ac64),DAT_140e45138);
    FUN_14018a340(DAT_140e45138,3,1);
    uVar4 = (ulonglong)DAT_140e418c8;
    DAT_140e45100 = DAT_140e45138;
  }
  iVar5 = (int)uVar4;
  if (iVar5 == 0x15e) {
    DAT_140e418cc = 0;
  }
  if ((iVar5 == 0x4c4) || ((0x4c4 < DAT_140e45d74 && (iVar5 == DAT_140e45d74 + 1)))) {
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate(0x14c,100000,0,DAT_14053ae30,DAT_14053b42c,0,0,200,1,0);
    uVar4 = (ulonglong)DAT_140e418c8;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 3;
    DAT_140e418cc = 0;
  }
  uVar3 = (int)uVar4 - 400;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x1e0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x196;
  if ((uVar3 < 0x72) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xf0,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x21c;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xd) * 0xd)) {
    iVar5 = (int)uVar3 % 100;
    if (iVar5 < 0x32) {
      iVar5 = 0x3d - iVar5;
    }
    else {
      iVar5 = iVar5 + -0x27;
    }
    stage_spawn_dispatch_candidate(0xfc,800,iVar5 * 10,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 700;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,0x96);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x316;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xffffffec,0xf0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x370;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,0x140);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x3d4;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    stage_spawn_dispatch_candidate(0xfb,400,DAT_140e9fd1c % 0x231 + 0x50,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x44c) {
    stage_spawn_dispatch_candidate(6,5000,0x1cc,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x4e2;
  if ((uVar3 < 0x1c2) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x578;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xb4,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x5dc;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,200);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x640;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xffffffec,0x168);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x6a4;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x21c,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 2000;
  if ((uVar3 < 1000) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xbea) {
    stage_spawn_dispatch_candidate(0x103,4000,0x2c6,0xffffff38);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xc30) {
    stage_spawn_dispatch_candidate(0x103,4000,0x35c,0xffffff6a);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0xcb2;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,0x96);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0xd02;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xffffffec,0xf0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xd7a) {
    stage_spawn_dispatch_candidate(0x104,4000,0xffffffd8,0xffffff38);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0xdd4) {
    stage_spawn_dispatch_candidate(0xfe,7000,0x21c,200);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x10fe;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x11e4;
  if (uVar3 < 100) {
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    if (uVar3 == 0) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
  if ((int)uVar4 == 0x12c0) {
    stage_spawn_dispatch_candidate(0x102,7000,0x1e0,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x1324;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x1cc,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 5000;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfd,1000,DAT_140e9fd1c % 0x191 + 0xd2,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x1400;
  if ((uVar3 < 0x50) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0xc9 + 0x6e,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x146e) {
    stage_spawn_dispatch_candidate(0x100,6000,0xb4,300);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x14c8) {
    stage_spawn_dispatch_candidate(0x100,6000,0x21c,200);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x159a) {
    stage_spawn_dispatch_candidate(0xfd,1000,0x78,0);
    stage_spawn_dispatch_candidate(0xfd,1000,0x10e,0);
    stage_spawn_dispatch_candidate(0xfd,1000,0x1c2,0);
    stage_spawn_dispatch_candidate(0xfd,1000,600,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 0) {
    uVar3 = (uint)uVar4 - 0x16a8;
    if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x17d + 0x50,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar4 - 0x16a8;
    if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfc,800,DAT_140e9fd1c % 0x191 + 0xd2,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
  uVar3 = (int)uVar4 - 0x19dc;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x1a4,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1a18) {
    stage_spawn_dispatch_candidate(0x102,7000,0x168,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x1a7c;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,300,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x1af4;
  if ((uVar3 < 800) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0xffffffec);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 7000) {
    stage_spawn_dispatch_candidate(0xfe,0x157c,0xb4,0xfa);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1bbc) {
    stage_spawn_dispatch_candidate(0xfe,0x157c,0xb4,200);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1c20) {
    stage_spawn_dispatch_candidate(0xfe,0x157c,0xb4,0x96);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1d1a) {
    stage_spawn_dispatch_candidate(0x102,5000,0x208,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1d7e) {
    stage_spawn_dispatch_candidate(0x102,5000,200,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x1de2) {
    stage_spawn_dispatch_candidate(0x102,5000,0x168,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 1) {
    uVar3 = (uint)uVar4 - 8000;
    if ((699 < uVar3) || (uVar3 != ((int)uVar3 / 0x1e) * 0x1e)) goto LAB_14012c7c3;
    uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if (DAT_140e418cc == 0) {
    uVar3 = (uint)uVar4 - 8000;
    if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x12) * 0x12)) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar4 - 8000;
    if ((uVar3 < 700) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {
      uVar6 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
      uVar3 = uVar6 * 0x800 ^ uVar6;
      DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfd,1000,DAT_140e9fd1c % 0x191 + 0x6e,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
  }
LAB_14012c7c3:
  uVar3 = (uint)uVar4 - 0x2292;
  if ((uVar3 < 100) && (uVar3 == ((int)uVar3 / 0xf) * 0xf)) {
    uVar6 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    uVar3 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfc,800,DAT_140e9fd1c % 0x1f5 + 0x6e,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 9000) {
    stage_spawn_dispatch_candidate(0x104,4000,0x3c,0xffffff9c);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x235a) {
    stage_spawn_dispatch_candidate(0x104,4000,0xffffffa6,0xffffff6a);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x238c) {
    stage_spawn_dispatch_candidate(0x104,4000,0xffffff10,0xffffff38);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x2454;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,0x168);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x2490;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xffffffec,0xf0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x24cc;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0x2e4,0xa0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar4 - 0x2508;
  if ((uVar3 < 0x3c) && (uVar3 == ((int)uVar3 / 0xc) * 0xc)) {
    stage_spawn_dispatch_candidate(0xfa,300,0xffffffec,300);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x2544) {
    stage_spawn_dispatch_candidate(0x100,6000,0xb4,0xfa);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x26ac) {
    stage_spawn_dispatch_candidate(0x100,6000,0x21c,0x96);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4 - 0x25bc;
  if ((uVar3 < 0x348) && (uVar3 == ((int)uVar3 / 0x1c) * 0x1c)) {
    uVar6 = ((uint)(uVar4 >> 0x1e) ^ (uint)uVar4) * 0x6c078965 + 1;
    uVar3 = uVar6 * 0x800 ^ uVar6;
    DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x17d + 0x104,0);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar4 == 0x28a0) {
    stage_spawn_dispatch_candidate(0x103,4000,0x35c,0xffffff88);
    uVar4 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar4;
  if (DAT_140e418cc == 0) {
    uVar6 = uVar3 - 0x2a30;
    if ((uVar6 < 200) && (uVar6 == ((int)uVar6 / 7) * 7)) {
      uVar3 = ((uint)(uVar4 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0);
      uVar4 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar4;
    uVar6 = uVar3 - 11000;
    if ((uVar6 < 400) && (uVar6 == ((int)uVar6 / 0xf) * 0xf)) {
      uVar6 = ((uint)(uVar4 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      uVar3 = uVar6 * 0x800 ^ uVar6;
      DAT_140e9fd10 = (uVar6 >> 0x1e ^ uVar6) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xfb,300,DAT_140e9fd1c % 0x231 + 0x50,0);
      uVar3 = DAT_140e418c8;
    }
    if (uVar3 == 0x2b5c) {
      stage_spawn_dispatch_candidate(0x102,5000,0xf0,0);
      uVar3 = DAT_140e418c8;
    }
    if (uVar3 == 0x2c24) {
      stage_spawn_dispatch_candidate(0x102,5000,0x1e0,0);
      uVar3 = DAT_140e418c8;
    }
  }
  if (((uVar3 == 0x2cd8) || (uVar3 == 0x2d14)) || (uVar3 == 0x2d50)) {
    stage_spawn_dispatch_candidate(0xfc,800,0x3c,0);
    stage_spawn_dispatch_candidate(0xfc,800,0xb4,0);
    stage_spawn_dispatch_candidate(0xfc,800,300,0);
    stage_spawn_dispatch_candidate(0xfc,800,0x1a4,0);
    stage_spawn_dispatch_candidate(0xfc,800,0x21c,0);
    stage_spawn_dispatch_candidate(0xfc,800,0x294,0);
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == 0x2db4) {
    stage_spawn_dispatch_candidate(7,5000,0x104,0);
  }
  return;
}


