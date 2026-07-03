// Function: stage_09_gameplay_update_candidate @ 140128940
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage_09_gameplay_update_candidate(void)

{
  float fVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  bool bVar8;
  double dVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  
  uVar12 = 0;
  uVar10 = 0xe6;
  stage_intro_banner_event_candidate
            (DAT_140e445c0 + (DAT_1407c7798 + 9) * 10,DAT_140e445c0,DAT_140e418c8,0x32,0xe6,0);
  uVar7 = (ulonglong)DAT_140e418c8;
  uVar3 = DAT_140e418c8 - 0x10e;
  if ((uVar3 < 0x10e) && (uVar3 == ((int)uVar3 / 0x3c) * 0x3c)) {
    dVar9 = (double)FUN_140332d90(((double)(int)DAT_140e418c8 - DAT_14053a5f0) * DAT_14053a890 *
                                  DAT_14053a020 * DAT_140539d28);
    iVar4 = -(int)(dVar9 * _DAT_14053b148);
    stage_spawn_dispatch_candidate(0x74,700,iVar4 + 0x82,0x334);
    stage_spawn_dispatch_candidate(0x74,700,iVar4 + 0x104,0x334);
    stage_spawn_dispatch_candidate(0x74,700,iVar4 + 0x186,0x334);
    stage_spawn_dispatch_candidate(0x74,700,iVar4 + 0x208,0x334);
    stage_spawn_dispatch_candidate(0x74,700,iVar4 + 0x28a,0x334);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 700) {
    stage_spawn_dispatch_candidate(0x26,3000,0x230,0xffffffec);
    stage_spawn_dispatch_candidate(0x26,3000,0xa0,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 800) {
    stage_spawn_dispatch_candidate(0x26,3000,0x168,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0x398;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    stage_spawn_dispatch_candidate(0x19,700,(int)uVar7 * 4 + -0xdc0,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x438;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xd,400,0xffffffec,DAT_140e9fd1c % 0x12d + 0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x43d;
  if ((uVar3 < 0x73) && (uVar3 == ((int)uVar3 / 10) * 10)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    stage_spawn_dispatch_candidate(0xd,400,0x2e4,DAT_140e9fd1c % 0x12d + 0x96);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x4b0) {
    stage_spawn_dispatch_candidate(7,5000,0x104,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  fVar1 = DAT_14053ae30;
  uVar11 = DAT_14053adb4;
  uVar3 = (uint)uVar7;
  if (uVar3 == 0x546) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    uVar10 = DAT_14053adb4;
    stage_entity_spawn_candidate(0x146,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_140129019:
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (uVar3 - 0x640 < 2000)) {
    iVar4 = (int)(uVar3 - 0x640) % 0x78;
    if ((iVar4 < 0x60) && (iVar4 == (iVar4 / 0x18) * 0x18)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x668;
    if ((uVar3 < 0x6e0) && (uVar3 == ((int)uVar3 / 100) * 100)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      stage_spawn_dispatch_candidate(0xe,3000,DAT_140e9fd1c % 0x1b9 + 0x8c,0);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0xdac) {
      stage_spawn_dispatch_candidate(0x38,3000,0x208,0);
      stage_spawn_dispatch_candidate(0x38,3000,0xb4,0);
      goto LAB_140129019;
    }
  }
  if ((int)uVar7 == 0xe4c) {
    stage_spawn_dispatch_candidate(0x46,2000,0x460,100,uVar10,uVar12);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xe74) {
    stage_spawn_dispatch_candidate(0x46,2000,0x3ca,0x4b,uVar10);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xe92) {
    stage_spawn_dispatch_candidate(0x46,2000,0x334,0x32);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xec4) {
    stage_spawn_dispatch_candidate(0x46,2000,0xfffffe70,0x50);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xee2) {
    stage_spawn_dispatch_candidate(0x46,2000,0xffffff06,0x37);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0xf00) {
    stage_spawn_dispatch_candidate(0x46,2000,0xffffff9c,0x1e);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (int)uVar7 - 0xf8c;
  if ((uVar3 < 0x78) && (uVar3 == ((int)uVar3 / 0x28) * 0x28)) {
    stage_spawn_dispatch_candidate(0x19,500,0x6e,0xffffffec);
    stage_spawn_dispatch_candidate(0x19,500,0xd2,0xffffffec);
    stage_spawn_dispatch_candidate(0x19,500,0x136,0xffffffec);
    stage_spawn_dispatch_candidate(0x19,500,0x19a,0xffffffec);
    stage_spawn_dispatch_candidate(0x19,500,0x1fe,0xffffffec);
    stage_spawn_dispatch_candidate(0x19,500,0x262,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7;
  if (uVar3 == 0x1004) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    uVar10 = DAT_14053ae00;
    stage_entity_spawn_candidate(0x147,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_14012953a:
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (uVar5 = uVar3 - 0x10cc, uVar5 < 0x6a4)) {
    if (((int)uVar3 < 0x15e0) && (uVar5 == ((int)uVar5 / 0x50) * 0x50)) {
      uVar5 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar5 * 0x800 ^ uVar5;
      uVar5 = uVar5 ^ uVar5 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0x57,0x708,DAT_140e9fd1c % 0x97 + 0x262,
                 ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x65 - 200);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x10ea;
    if ((uVar3 < 0x4f6) && (uVar3 == ((int)uVar3 / 0x50) * 0x50)) {
      uVar5 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar5 * 0x800 ^ uVar5;
      uVar5 = uVar5 ^ uVar5 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ DAT_140e9fd18 ^ uVar5;
      stage_spawn_dispatch_candidate
                (0x58,0x708,DAT_140e9fd1c % 0x97 - 0x28,
                 ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3) % 0x65 - 200);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x1644) {
      stage_spawn_dispatch_candidate(0x2b,12000,0x168,0);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (int)uVar7 - 0x16a8;
    if ((uVar3 < 0x96) && (uVar3 == ((int)uVar3 / 0x32) * 0x32)) {
      stage_spawn_dispatch_candidate(0xb,400,0x6e,0xffffffec);
      stage_spawn_dispatch_candidate(0xb,400,0x262,0xffffffec);
      goto LAB_14012953a;
    }
  }
  uVar3 = (uint)uVar7 - 0x1798;
  if (((uVar3 < 0xa0) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&
     (iVar4 == (iVar4 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
    stage_spawn_dispatch_candidate(0xb,0x168,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec,uVar10,uVar12);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x179d;
  if (((uVar3 < 0x9b) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&
     (iVar4 == (iVar4 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xb,0x168,0x2e4,DAT_140e9fd1c % 0xfb + 100,uVar10);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x17a2;
  if (((uVar3 < 0x96) && (iVar4 = (int)uVar3 % 0x78, iVar4 < 0x60)) &&
     (iVar4 == (iVar4 / 0xf) * 0xf)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0xb,0x168,0xffffffec,DAT_140e9fd1c % 0xfb + 100);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  iVar4 = (int)uVar7;
  if (iVar4 == 0x1838) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    uVar10 = uVar11;
    stage_entity_spawn_candidate(0x148,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_140129ae3:
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (iVar4 - 0x1900U < 2000)) {
    if (iVar4 < 0x1bee) {
      uVar3 = iVar4 - 0x1900U & 0x80000007;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
      }
      if (uVar3 != 0) goto LAB_14012991b;
LAB_14012995f:
      stage_spawn_dispatch_candidate(0x35,0x96,0x2e4,100);
      stage_spawn_dispatch_candidate(0x35,0x96,0xffffffec,0xa0);
      stage_spawn_dispatch_candidate(0x35,0x96,0x2e4,0xdc);
      stage_spawn_dispatch_candidate(0x35,0x96,0xffffffec,0x118);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    else {
LAB_14012991b:
      if (iVar4 - 0x1c52U < 200) {
        uVar3 = iVar4 - 0x1c52U & 0x80000007;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
        }
        if (uVar3 == 0) goto LAB_14012995f;
      }
      if (iVar4 - 0x1d7eU < 200) {
        uVar3 = iVar4 - 0x1d7eU & 0x80000007;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
        }
        if (uVar3 == 0) goto LAB_14012995f;
      }
    }
    if ((int)uVar7 == 0x1e78) {
      stage_spawn_dispatch_candidate(0x47,2000,0x1fe,0xfa);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x1ec8) {
      stage_spawn_dispatch_candidate(0x48,2000,0xd2,0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x1fd6) {
      stage_spawn_dispatch_candidate(0x58,0x640,0x104,0xffffff9c);
      stage_spawn_dispatch_candidate(0x58,0x640,0x6e,0xffffff6a);
      stage_spawn_dispatch_candidate(0x58,0x640,0xffffffd8,0xffffff38);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x203a) {
      stage_spawn_dispatch_candidate(0x57,0x640,0x1cc,0xffffff38);
      stage_spawn_dispatch_candidate(0x57,0x640,0x262,0xffffff6a);
      stage_spawn_dispatch_candidate(0x57,0x640,0x2f8,0xffffff9c);
      goto LAB_140129ae3;
    }
  }
  if ((int)uVar7 == 0x20d0) {
    stage_spawn_dispatch_candidate(8,5000,0x1cc,0,uVar10,uVar12);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2166) {
    stage_spawn_dispatch_candidate(0x4d,6000,0xffffff6a,0,uVar10);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x2210;
  if ((uVar3 < 0xe6) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x36,0x15e,0x2e4,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x221a;
  if ((uVar3 < 0xdc) && (uVar3 == ((int)uVar3 / 0x14) * 0x14)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x36,0x15e,0xffffffec,DAT_140e9fd1c % 0xc9 + 300);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7;
  if (uVar3 == 9000) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    uVar10 = uVar11;
    stage_entity_spawn_candidate(0x149,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_14012a2bd:
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (uVar5 = uVar3 - 0x23f0, uVar5 < 2000)) {
    if (((int)uVar3 < 0x27c4) && (uVar5 == ((int)uVar5 / 0x18) * 0x18)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xb,400,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x2800;
    if ((uVar3 < 0xf0) && (uVar3 == ((int)uVar3 / 10) * 10)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      stage_spawn_dispatch_candidate(0xd,400,0xffffffec,DAT_140e9fd1c % 0x12d + 0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x2805;
    if ((uVar3 < 0xeb) && (uVar3 == ((int)uVar3 / 10) * 10)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate(0xd,400,0x2e4,DAT_140e9fd1c % 0x12d + 0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x2968) {
      stage_spawn_dispatch_candidate(0x39,7000,0x262,0xffffffb0);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x2990;
    if (uVar3 < 0x6e) {
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
        stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0xf1 + 0x50,0xffffffec);
        uVar7 = (ulonglong)DAT_140e418c8;
      }
    }
    if ((int)uVar7 == 0x29cc) {
      stage_spawn_dispatch_candidate(0x3a,7000,0xffffffb0,200);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x2a30) {
      stage_spawn_dispatch_candidate(0x39,7000,0x6e,0xffffffb0);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x2a58;
    if (uVar3 < 0x6e) {
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
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
        stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0xf1 + 400,0xffffffec);
        uVar7 = (ulonglong)DAT_140e418c8;
      }
    }
    if ((int)uVar7 == 0x2a94) {
      stage_spawn_dispatch_candidate(0x3a,7000,800,200);
      goto LAB_14012a2bd;
    }
  }
  if ((int)uVar7 == 0x2bf2) {
    stage_spawn_dispatch_candidate(0x76,12000,0xe6,0x348,uVar10,uVar12);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x2c1a) {
    stage_spawn_dispatch_candidate(0x76,12000,0x1ea,0x348,uVar10);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7 - 0x2da0;
  if ((uVar3 < 0xb4) && (uVar3 == ((int)uVar3 / 5) * 5)) {
    uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar3 = uVar3 * 0x800 ^ uVar3;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
    stage_spawn_dispatch_candidate(0x44,0xfa,DAT_140e9fd1c % 0x259 + 0x3c,0xffffffec);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7;
  if (uVar3 == 0x2e54) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate(0x14a,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
LAB_14012a88a:
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  else {
    uVar11 = uVar10;
    if ((DAT_140e418cc == 0) && (uVar5 = uVar3 - 12000, uVar5 < 0x6a4)) {
      if (((int)uVar3 < 0x3340) && (uVar5 == ((int)uVar5 / 0x12) * 0x12)) {
        uVar3 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar3 = uVar3 * 0x800 ^ uVar3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
        stage_spawn_dispatch_candidate(0xb,300,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
        uVar7 = (ulonglong)DAT_140e418c8;
        uVar11 = uVar10;
      }
      uVar3 = (uint)uVar7 - 12000;
      if ((uVar3 < 0x460) && (uVar3 == ((int)uVar3 / 0x18) * 0x18)) {
        uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar3 = uVar3 * 0x800 ^ uVar3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
        stage_spawn_dispatch_candidate(0x19,500,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
        uVar7 = (ulonglong)DAT_140e418c8;
      }
      uVar3 = (uint)uVar7 - 0x3390;
      if ((uVar3 < 300) && (uVar3 == ((int)uVar3 / 100) * 100)) {
        uVar5 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar3 = uVar5 * 0x800 ^ uVar5;
        uVar5 = uVar5 * 0x800 ^ uVar5;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (uVar5 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar5 ^ DAT_140e9fd18;
        stage_spawn_dispatch_candidate
                  (0x9b,5000,DAT_140e9fd1c % 0x65 + 0x1cc,
                   ((uVar3 ^ DAT_140e9fd18 >> 0xb) >> 8 ^ uVar3 ^ DAT_140e9fd18) % 0x65 + 0x96);
        uVar7 = (ulonglong)DAT_140e418c8;
      }
      uVar3 = (uint)uVar7 - 0x33e0;
      if (((uVar3 < 0x168) && (iVar4 = (int)uVar3 % 0x96, iVar4 < 0x3c)) &&
         (iVar4 == (iVar4 / 0xf) * 0xf)) {
        uVar3 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        uVar3 = uVar3 * 0x800 ^ uVar3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
        stage_spawn_dispatch_candidate(0x45,400,DAT_140e9fd1c % 0x1e1 + 0x78,0xffffffec);
        goto LAB_14012a88a;
      }
    }
  }
  if ((int)uVar7 == 0x3584) {
    stage_spawn_dispatch_candidate(0x1b,0x1130,0x168,0,uVar11,uVar12);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x35b6) {
    stage_spawn_dispatch_candidate(0x1b,0x1130,0x1fe,0,uVar11);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  if ((int)uVar7 == 0x35e8) {
    stage_spawn_dispatch_candidate(0x1b,0x1130,0xd2,0);
    uVar7 = (ulonglong)DAT_140e418c8;
  }
  uVar3 = (uint)uVar7;
  if (uVar3 == 0x364c) {
    uVar12 = uVar12 & 0xffff0000;
    DAT_140e44308 = DAT_1407c779c;
    uVar11 = DAT_14053ade0;
    stage_entity_spawn_candidate(0x14b,100000,0);
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 1;
    DAT_140e418cc = 1;
  }
  else {
    if ((DAT_140e418cc != 0) || (uVar5 = uVar3 - 0x3714, 1999 < uVar5)) goto LAB_14012ad20;
    if (((int)uVar3 < 0x3bc4) && (uVar5 == ((int)uVar5 / 0x13) * 0x13)) {
      uVar3 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar3 >> 0x1e ^ uVar3) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar3 * 0x800 ^ uVar3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      stage_spawn_dispatch_candidate(0x1a,400,DAT_140e9fd1c % 0x231 + 0x50,0xffffffec);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x3714;
    if ((uVar3 < 0x4b0) && (uVar3 == ((int)uVar3 / 0x1e) * 0x1e)) {
      uVar5 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      uVar3 = uVar5 * 0x800 ^ uVar5;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3;
      stage_spawn_dispatch_candidate(0x25,600,DAT_140e9fd1c % 0x1f5 + 0x6e,0xffffffec);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    uVar3 = (uint)uVar7 - 0x3c28;
    if ((uVar3 < 400) && (uVar3 == ((int)uVar3 / 100) * 100)) {
      uVar5 = ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965 + 1;
      DAT_140e9fd10 = (uVar5 >> 0x1e ^ uVar5) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      uVar3 = uVar5 ^ uVar5 * 0x800;
      uVar5 = uVar5 ^ uVar5 * 0x800;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar5) >> 8 ^ uVar5 ^ DAT_140e9fd18;
      stage_spawn_dispatch_candidate
                (0xa1,5000,DAT_140e9fd1c % 0x65 + 0xa0,
                 ((DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ DAT_140e9fd18 ^ uVar3) % 0x65 + 0x96);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 == 0x3e1c) {
      iVar4 = 0x3c;
      do {
        stage_spawn_dispatch_candidate(0x44,0xfa,iVar4,0xffffffec);
        iVar4 = iVar4 + 0x3c;
      } while (iVar4 < 0x2d0);
      uVar7 = (ulonglong)DAT_140e418c8;
    }
    if ((int)uVar7 != 0x3e44) goto LAB_14012ad20;
    stage_spawn_dispatch_candidate(0xf,5000,0xffffff88,0x96);
    stage_spawn_dispatch_candidate(0xf,5000,0x348,0x96);
  }
  uVar7 = (ulonglong)DAT_140e418c8;
LAB_14012ad20:
  uVar3 = (uint)uVar7;
  if (uVar3 == 0x3ee4) {
    stage_spawn_dispatch_candidate(0xa4,50000,0xffffff9c,0xb4,uVar11,uVar12);
    DAT_140e418cc = 1;
    uVar3 = DAT_140e418c8;
  }
  else if ((DAT_140e418cc == 0) && (uVar12 = uVar3 - 0x3f48, uVar12 < 0x44c)) {
    if (((int)uVar3 < 0x4290) && (uVar12 == ((int)uVar12 / 10) * 10)) {
      uVar12 = ((uint)(uVar7 >> 0x1e) ^ uVar3) * 0x6c078965 + 1;
      uVar3 = uVar12 * 0x800 ^ uVar12;
      DAT_140e9fd10 = (uVar12 >> 0x1e ^ uVar12) * 0x6c078965 + 2;
      DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
      DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
      DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar3) >> 8 ^ uVar3 ^ DAT_140e9fd18;
      uVar11 = DAT_14053b320;
      stage_entity_spawn_candidate
                (0xad,300,5,(float)(int)(DAT_140e9fd1c % 0x259 - 300) + fVar1,DAT_14053b320,0x4000,
                 DAT_140539f40,0x28,1,0);
      uVar3 = DAT_140e418c8;
    }
    if (uVar3 == 0x42cc) {
      stage_spawn_dispatch_candidate(0x9e,5000,0x1cc,0xfa,uVar11);
      uVar3 = DAT_140e418c8;
    }
    if (uVar3 == 0x42fe) {
      stage_spawn_dispatch_candidate(0x9e,5000,0x104,0xb4);
      uVar3 = DAT_140e418c8;
    }
  }
  if (uVar3 == 0x4394) {
    stage_spawn_dispatch_candidate(8,5000,0x1cc,0,uVar11);
    uVar3 = DAT_140e418c8;
  }
  puVar2 = DAT_140e45d28;
  if ((uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) - 300U) &&
     (uVar10 = *(undefined4 *)(&DAT_140e419d4 + (longlong)(DAT_140e445c0 * 10) * 4),
     DAT_140e45d1c < 0x1000)) {
    puVar2 = (undefined8 *)_malloc_base(0x60);
    if (puVar2 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    DAT_140e45d1c = DAT_140e45d1c + 1;
    bVar8 = DAT_140e45d78 == (undefined8 *)0x0;
    *puVar2 = 1;
    *(undefined4 *)(puVar2 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar2 + 0xc) = uVar10;
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
  fVar1 = DAT_14053ac64;
  iVar4 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x168;
  if ((iVar4 <= (int)uVar3) &&
     ((int)uVar3 < *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0xf0)) {
    dVar9 = (double)FUN_140332d90(((double)(int)uVar3 - (double)iVar4) * DAT_14053a4d8 *
                                  DAT_14053a020 * DAT_140539d28);
    _DAT_1407c777c = (float)(dVar9 * DAT_14053b0a0) + DAT_140539da8;
    FUN_140184700((int)((float)DAT_140e4418c * fVar1 * _DAT_1407c777c),DAT_140e45100);
    uVar3 = DAT_140e418c8;
  }
  if ((*(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -300 <= (int)uVar3) &&
     ((int)uVar3 <= *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4))) {
    FUN_140001060();
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(uint *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4)) {
    DAT_140e418cc = 0;
    stage_entity_flush_effects_candidate();
    stage_pending_effect_flush_candidate();
    puVar6 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar6,0);
      puVar6 = puVar6 + 1;
    } while ((longlong)puVar6 < 0x140e45178);
    _DAT_1407c777c = 1.0;
    FUN_140184700((int)((float)DAT_140e4418c * fVar1),DAT_140e45144);
    FUN_14018a340(DAT_140e45144,3,1);
    DAT_140e45100 = DAT_140e45144;
    uVar3 = DAT_140e418c8;
  }
  if (uVar3 == *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + 0x3cU) {
    DAT_140e44308 = DAT_1407c779c;
    stage_entity_spawn_candidate(0x140,100000,0);
    DAT_140e418cc = 1;
    DAT_140e419bc = 0;
    DAT_140e41b0c = 100000;
    DAT_140e4192c = 0;
    DAT_140e41af8 = 4;
  }
  return;
}


