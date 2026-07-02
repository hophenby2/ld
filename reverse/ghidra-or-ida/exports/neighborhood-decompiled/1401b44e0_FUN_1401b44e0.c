// Function: FUN_1401b44e0 @ 1401b44e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401b44e0(longlong *param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 auStack_878 [32];
  longlong local_858;
  undefined8 local_848 [2];
  undefined1 local_838 [2048];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_878;
  if (*(int *)(param_2 + 0x8f0) == 1) {
    iVar3 = FUN_1401b08d0(param_2);
    while (iVar3 == 0) {
      FUN_1401b7120(0);
      iVar3 = FUN_1401b08d0();
    }
  }
  lVar7 = 0;
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined4 *)((longlong)param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 8) = param_4;
  lVar4 = FUN_1401b2ce0(param_2,param_3,local_848);
  if (lVar4 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x8d0) == 0) {
    lVar5 = FUN_140139800(param_2 + 0x80,0,1,0);
    param_1[4] = lVar5;
    if (lVar5 == 0) {
      return 0xffffffff;
    }
  }
  param_1[1] = lVar4;
  cVar1 = *(char *)(param_2 + 0x880);
  *(char *)(param_1 + 5) = cVar1;
  if (cVar1 == '\0') {
    uVar6 = FUN_1401b0cd0(param_2,local_848[0],lVar4,local_838);
    FUN_1401b3280(local_838,uVar6,(longlong)param_1 + 0x29);
  }
  if ((*(longlong *)(lVar4 + 0x38) != -1) || (*(longlong *)(lVar4 + 0x40) != -1)) {
    lVar5 = FUN_1401b6390(*(undefined8 *)(lVar4 + 0x30),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x86b);
    param_1[2] = lVar5;
    if (lVar5 == 0) goto LAB_1401b4e2a;
  }
  lVar5 = *(longlong *)(lVar4 + 0x38);
  if (lVar5 == -1) {
    if (*(longlong *)(lVar4 + 0x40) == -1) {
      return 0;
    }
    if (*(int *)(param_2 + 0x8d0) == 1) {
      if (*(int *)(param_2 + 0x8e4) == 0) {
        FUN_1401b5b00(*(longlong *)(param_2 + 8) + *(longlong *)(param_2 + 0x50) +
                      *(longlong *)(lVar4 + 0x28),param_1[2]);
        if (*(byte *)(param_2 + 0x30) == 0xff) {
          return 0;
        }
        uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
        if (*(ulonglong *)(lVar4 + 0x30) <= uVar9 << 0xb) {
          return 0;
        }
        FUN_1401ae320(param_1[2] + uVar9 * -0x400 + *(ulonglong *)(lVar4 + 0x30),
                      uVar9 * 0x400 + param_1[2]);
        FUN_1401ae2f0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + param_1[2],
                      *(longlong *)(lVar4 + 0x40) + *(longlong *)(param_2 + 8) +
                      *(longlong *)(param_2 + 0x50) + *(longlong *)(lVar4 + 0x28),
                      *(longlong *)(lVar4 + 0x30) + (ulonglong)*(byte *)(param_2 + 0x30) * -0x800);
        return 0;
      }
      lVar7 = FUN_1401b6390(*(longlong *)(lVar4 + 0x40),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x963);
      param_1[3] = lVar7;
      if (lVar7 != 0) {
        FUN_1401ae2f0(lVar7,*(longlong *)(param_2 + 8) + *(longlong *)(param_2 + 0x50) +
                            *(longlong *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x40));
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[3],*(undefined8 *)(lVar4 + 0x40),*(undefined8 *)(lVar4 + 0x30),
                        (longlong)param_1 + 0x29);
        }
        FUN_1401b5b00(param_1[3],param_1[2]);
        if (*(byte *)(param_2 + 0x30) != 0xff) {
          uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
          if (uVar9 << 0xb < *(ulonglong *)(lVar4 + 0x30)) {
            FUN_1401ae320(param_1[2] + uVar9 * -0x400 + *(ulonglong *)(lVar4 + 0x30),
                          uVar9 * 0x400 + param_1[2]);
            FUN_1401ae2f0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + param_1[2],
                          *(longlong *)(lVar4 + 0x40) + *(longlong *)(param_2 + 8) +
                          *(longlong *)(param_2 + 0x50) + *(longlong *)(lVar4 + 0x28),
                          *(longlong *)(lVar4 + 0x30) +
                          (ulonglong)*(byte *)(param_2 + 0x30) * -0x800);
            if ((char)param_1[5] == '\0') {
              FUN_1401b3000((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + param_1[2],
                            *(longlong *)(lVar4 + 0x30) +
                            (ulonglong)*(byte *)(param_2 + 0x30) * -0x800,
                            *(longlong *)(lVar4 + 0x40) + *(longlong *)(lVar4 + 0x30),
                            (longlong)param_1 + 0x29);
              FUN_1401b6700(param_1[3]);
              param_1[3] = 0;
              return 0;
            }
          }
        }
LAB_1401b4e19:
        FUN_1401b6700(param_1[3]);
        param_1[3] = 0;
        return 0;
      }
      goto LAB_1401b4e2a;
    }
    lVar5 = *(longlong *)(param_2 + 8) + *(longlong *)(lVar4 + 0x28);
    param_1[9] = lVar5;
    FUN_140139920(param_1[4],lVar5,0);
    if ((int)param_1[8] != 1) {
      lVar5 = FUN_1401b6390(*(undefined8 *)(lVar4 + 0x40),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x9c4);
      param_1[3] = lVar5;
      if (lVar5 != 0) {
        lVar8 = lVar7;
        if ((char)param_1[5] == '\0') {
          lVar8 = (longlong)param_1 + 0x29;
        }
        local_858 = *(longlong *)(lVar4 + 0x30);
        FUN_1401b31d0(lVar5,*(undefined8 *)(lVar4 + 0x40),param_1[4],lVar8);
        FUN_1401b5b00(param_1[3],param_1[2]);
        if (*(byte *)(param_2 + 0x30) != 0xff) {
          uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
          if (uVar9 << 0xb < *(ulonglong *)(lVar4 + 0x30)) {
            FUN_1401ae320(param_1[2] + uVar9 * -0x400 + *(ulonglong *)(lVar4 + 0x30),
                          uVar9 * 0x400 + param_1[2]);
            local_858 = *(longlong *)(lVar4 + 0x40) + *(longlong *)(lVar4 + 0x30);
            if ((char)param_1[5] == '\0') {
              lVar7 = (longlong)param_1 + 0x29;
            }
            FUN_1401b31d0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + param_1[2],
                          *(longlong *)(lVar4 + 0x30) +
                          (ulonglong)*(byte *)(param_2 + 0x30) * -0x800,param_1[4],lVar7);
          }
        }
        goto LAB_1401b4e19;
      }
      goto LAB_1401b4e2a;
    }
    bVar2 = *(byte *)(param_2 + 0x30);
    if (bVar2 != 0xff) {
      if ((ulonglong)bVar2 * 0x800 < *(ulonglong *)(lVar4 + 0x30)) {
        lVar7 = FUN_1401b6390(*(longlong *)(lVar4 + 0x40) + (ulonglong)bVar2 * -0x800 +
                              *(ulonglong *)(lVar4 + 0x30),
                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x9aa);
        param_1[3] = lVar7;
        if (lVar7 == 0) goto LAB_1401b4e2a;
        lVar4 = *(longlong *)(lVar4 + 0x40) + (ulonglong)*(byte *)(param_2 + 0x30) * -0x800 +
                *(longlong *)(lVar4 + 0x30);
        goto LAB_1401b4d31;
      }
    }
    lVar7 = FUN_1401b6390(*(undefined8 *)(lVar4 + 0x40),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x9b6);
    param_1[3] = lVar7;
    if (lVar7 != 0) {
      lVar4 = *(longlong *)(lVar4 + 0x40);
LAB_1401b4d31:
      FUN_1401398a0(lVar7,lVar4,1,param_1[4]);
      *(undefined4 *)((longlong)param_1 + 0x44) = 1;
      return 0;
    }
  }
  else {
    if (*(longlong *)(lVar4 + 0x40) != -1) {
      if (*(int *)(param_2 + 0x8d0) == 1) {
        if (*(int *)(param_2 + 0x8e4) == 0) {
          lVar7 = FUN_1401b6390(lVar5,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                                0x8a8);
          param_1[3] = lVar7;
          if (lVar7 != 0) {
            FUN_1401b5b00(*(longlong *)(param_2 + 8) + *(longlong *)(param_2 + 0x50) +
                          *(longlong *)(lVar4 + 0x28),lVar7);
            if (*(byte *)(param_2 + 0x30) != 0xff) {
              uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
              if (uVar9 << 0xb < *(ulonglong *)(lVar4 + 0x38)) {
                FUN_1401ae320(param_1[3] + uVar9 * -0x400 + *(ulonglong *)(lVar4 + 0x38),
                              uVar9 * 0x400 + param_1[3]);
                FUN_1401ae2f0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + param_1[3],
                              *(longlong *)(lVar4 + 0x40) + *(longlong *)(param_2 + 8) +
                              *(longlong *)(param_2 + 0x50) + *(longlong *)(lVar4 + 0x28),
                              *(longlong *)(lVar4 + 0x38) +
                              (ulonglong)*(byte *)(param_2 + 0x30) * -0x800);
              }
            }
            FUN_1401b2550(param_1[3],param_1[2]);
            FUN_1401b6700(param_1[3]);
            param_1[3] = 0;
            return 0;
          }
          goto LAB_1401b4e2a;
        }
        lVar7 = FUN_1401b6390(lVar5 + *(longlong *)(lVar4 + 0x40),
                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x87e);
        param_1[3] = lVar7;
        if (lVar7 == 0) goto LAB_1401b4e2a;
        FUN_1401ae2f0(lVar7,*(longlong *)(param_2 + 8) + *(longlong *)(param_2 + 0x50) +
                            *(longlong *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x40));
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[3],*(undefined8 *)(lVar4 + 0x40),*(undefined8 *)(lVar4 + 0x30),
                        (longlong)param_1 + 0x29);
        }
        FUN_1401b5b00(param_1[3],param_1[3] + *(longlong *)(lVar4 + 0x40));
        if (*(byte *)(param_2 + 0x30) != 0xff) {
          uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
          if (uVar9 << 0xb < *(ulonglong *)(lVar4 + 0x38)) {
            FUN_1401ae320(*(longlong *)(lVar4 + 0x40) + uVar9 * -0x400 + param_1[3] +
                          *(ulonglong *)(lVar4 + 0x38),
                          uVar9 * 0x400 + *(longlong *)(lVar4 + 0x40) + param_1[3]);
            FUN_1401ae2f0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + *(longlong *)(lVar4 + 0x40)
                          + param_1[3],
                          *(longlong *)(param_2 + 8) + *(longlong *)(lVar4 + 0x40) +
                          *(longlong *)(param_2 + 0x50) + *(longlong *)(lVar4 + 0x28),
                          *(longlong *)(lVar4 + 0x38) +
                          (ulonglong)*(byte *)(param_2 + 0x30) * -0x800);
            if ((char)param_1[5] == '\0') {
              FUN_1401b3000((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 +
                            *(longlong *)(lVar4 + 0x40) + param_1[3],
                            *(longlong *)(lVar4 + 0x38) +
                            (ulonglong)*(byte *)(param_2 + 0x30) * -0x800,
                            *(longlong *)(lVar4 + 0x30) + *(longlong *)(lVar4 + 0x40),
                            (longlong)param_1 + 0x29);
            }
          }
        }
      }
      else {
        lVar5 = *(longlong *)(param_2 + 8) + *(longlong *)(lVar4 + 0x28);
        param_1[9] = lVar5;
        FUN_140139920(param_1[4],lVar5,0);
        if ((int)param_1[8] == 1) {
          bVar2 = *(byte *)(param_2 + 0x30);
          if (bVar2 != 0xff) {
            if ((ulonglong)bVar2 << 0xb < *(ulonglong *)(lVar4 + 0x38)) {
              lVar8 = FUN_1401b6390((ulonglong)bVar2 * 0xc00 + *(longlong *)(lVar4 + 0x40) +
                                    *(ulonglong *)(lVar4 + 0x38),
                                    "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",
                                    0x8d8);
              param_1[3] = lVar8;
              if (lVar8 != 0) {
                lVar5 = *(longlong *)(lVar4 + 0x40) + (ulonglong)*(byte *)(param_2 + 0x30) * -0x800
                        + *(longlong *)(lVar4 + 0x38);
                lVar8 = (ulonglong)*(byte *)(param_2 + 0x30) * 0x800 + lVar8;
                goto LAB_1401b48cc;
              }
              goto LAB_1401b4e2a;
            }
          }
          lVar8 = FUN_1401b6390(*(longlong *)(lVar4 + 0x40) + *(longlong *)(lVar4 + 0x38),
                                "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x8e4);
          param_1[3] = lVar8;
          if (lVar8 != 0) {
            lVar5 = *(longlong *)(lVar4 + 0x40);
LAB_1401b48cc:
            FUN_1401398a0(lVar8,lVar5,1,param_1[4]);
            *(undefined4 *)((longlong)param_1 + 0x44) = 1;
            return 0;
          }
          goto LAB_1401b4e2a;
        }
        lVar5 = FUN_1401b6390(*(longlong *)(lVar4 + 0x40) + *(longlong *)(lVar4 + 0x38),
                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x8f2);
        param_1[3] = lVar5;
        if (lVar5 == 0) goto LAB_1401b4e2a;
        lVar8 = lVar7;
        if ((char)param_1[5] == '\0') {
          lVar8 = (longlong)param_1 + 0x29;
        }
        local_858 = *(longlong *)(lVar4 + 0x30);
        FUN_1401b31d0(lVar5,*(undefined8 *)(lVar4 + 0x40),param_1[4],lVar8);
        FUN_1401b5b00(param_1[3],param_1[3] + *(longlong *)(lVar4 + 0x40));
        if (*(byte *)(param_2 + 0x30) != 0xff) {
          uVar9 = (ulonglong)*(byte *)(param_2 + 0x30);
          if (uVar9 << 0xb < *(ulonglong *)(lVar4 + 0x38)) {
            FUN_1401ae320(*(longlong *)(lVar4 + 0x40) + uVar9 * -0x400 + param_1[3] +
                          *(ulonglong *)(lVar4 + 0x38),
                          uVar9 * 0x400 + *(longlong *)(lVar4 + 0x40) + param_1[3]);
            local_858 = *(longlong *)(lVar4 + 0x30) + *(longlong *)(lVar4 + 0x40);
            if ((char)param_1[5] == '\0') {
              lVar7 = (longlong)param_1 + 0x29;
            }
            FUN_1401b31d0((ulonglong)*(byte *)(param_2 + 0x30) * 0x400 + *(longlong *)(lVar4 + 0x40)
                          + param_1[3],
                          *(longlong *)(lVar4 + 0x38) +
                          (ulonglong)*(byte *)(param_2 + 0x30) * -0x800,param_1[4],lVar7);
          }
        }
      }
      lVar7 = *(longlong *)(lVar4 + 0x40) + param_1[3];
LAB_1401b474e:
      FUN_1401b2550(lVar7,param_1[2]);
      FUN_1401b6700(param_1[3]);
      param_1[3] = 0;
      return 0;
    }
    if (*(int *)(param_2 + 0x8d0) == 1) {
      if (*(int *)(param_2 + 0x8e4) == 0) {
        FUN_1401b2550(*(longlong *)(param_2 + 0x50) + *(longlong *)(param_2 + 8) +
                      *(longlong *)(lVar4 + 0x28),param_1[2]);
        return 0;
      }
      lVar7 = FUN_1401b6390(lVar5,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x91f)
      ;
      param_1[3] = lVar7;
      if (lVar7 != 0) {
        FUN_1401ae2f0(lVar7,*(longlong *)(param_2 + 0x50) + *(longlong *)(param_2 + 8) +
                            *(longlong *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x38));
        if ((char)param_1[5] == '\0') {
          FUN_1401b3000(param_1[3],*(undefined8 *)(lVar4 + 0x38),*(undefined8 *)(lVar4 + 0x30),
                        (longlong)param_1 + 0x29);
        }
        lVar7 = param_1[3];
        goto LAB_1401b474e;
      }
    }
    else {
      lVar5 = FUN_1401b6390(lVar5,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x939)
      ;
      param_1[3] = lVar5;
      if (lVar5 != 0) {
        lVar5 = *(longlong *)(param_2 + 8) + *(longlong *)(lVar4 + 0x28);
        param_1[9] = lVar5;
        FUN_140139920(param_1[4],lVar5,0);
        lVar5 = *(longlong *)(lVar4 + 0x38);
        lVar8 = param_1[3];
        if ((int)param_1[8] == 1) goto LAB_1401b48cc;
        if ((char)param_1[5] == '\0') {
          lVar7 = (longlong)param_1 + 0x29;
        }
        local_858 = *(longlong *)(lVar4 + 0x30);
        FUN_1401b31d0(lVar8,lVar5,param_1[4],lVar7);
        lVar7 = param_1[3];
        goto LAB_1401b474e;
      }
    }
  }
LAB_1401b4e2a:
  if (param_1[2] != 0) {
    FUN_1401b6700();
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    FUN_1401b6700();
    param_1[3] = 0;
  }
  return 0xffffffff;
}


