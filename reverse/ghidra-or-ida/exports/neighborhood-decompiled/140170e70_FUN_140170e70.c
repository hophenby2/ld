// Function: FUN_140170e70 @ 140170e70
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_140170e70(longlong param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  byte bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  int local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  longlong local_a0;
  undefined1 local_98 [8];
  uint local_90;
  uint local_8c;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined8 local_6c;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_108;
  local_a8 = param_2;
  FUN_1401ae370(param_3,0,0x448);
  param_3[0x10a] = *(undefined4 *)(param_1 + 4);
  uVar10 = (int)*(uint *)(param_1 + 8) >> 0x1f;
  param_3[0x10b] = (*(uint *)(param_1 + 8) ^ uVar10) - uVar10;
  if ((((-1 < *(int *)(param_1 + 8)) ||
       (sVar2 = *(short *)(param_1 + 0xe), (sVar2 - 0x10U & 0xffe7) != 0)) || (sVar2 == 0x28)) ||
     ((iVar4 = *(int *)(param_1 + 0x10), iVar4 != 0 && (iVar4 != 3)))) {
    if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
      (*DAT_140c2c018)(1);
    }
    uVar14 = (*DAT_140c2be80)(0);
    FUN_1401ae370(&local_78,0,0x28);
    local_74 = *(undefined4 *)(param_1 + 4);
    uVar10 = (int)*(uint *)(param_1 + 8) >> 0x1f;
    iVar4 = 0;
    local_e0 = 0;
    local_78 = 0x28;
    local_70 = -((*(uint *)(param_1 + 8) ^ uVar10) - uVar10);
    local_6c = 0x180001;
    local_e8 = 0;
    lVar6 = (*DAT_140c2bee0)(uVar14,&local_78,0,&local_a0);
    if ((lVar6 != 0) && (local_a0 != 0)) {
      (*DAT_140c2be98)(lVar6,0x20,local_98);
      uVar10 = local_8c & 0x80000003;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
      }
      if (uVar10 != 0) {
        iVar4 = 4 - uVar10;
      }
      local_8c = local_8c + iVar4;
      iVar4 = (local_90 ^ (int)local_90 >> 0x1f) - ((int)local_90 >> 0x1f);
      uVar7 = (*DAT_140c2beb0)(uVar14,lVar6);
      local_b0 = 0;
      uVar10 = (int)*(uint *)(param_1 + 8) >> 0x1f;
      local_c0 = local_a8;
      local_c8 = (*(uint *)(param_1 + 8) ^ uVar10) - uVar10;
      local_d0 = 0;
      local_d8 = 0;
      local_e0 = 0;
      local_e8 = CONCAT44(local_e8._4_4_,local_c8);
      local_b8 = param_1;
      (*DAT_140c2bef0)(uVar14,0,0,*(undefined4 *)(param_1 + 4));
      (*DAT_140c2beb0)(uVar14,uVar7);
      (*DAT_140c2bec0)(uVar14);
      lVar8 = FUN_1401b6390((longlong)(int)(iVar4 * local_8c),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x9f0);
      *(longlong *)(param_3 + 0x10e) = lVar8;
      if (lVar8 == 0) {
        FUN_1401594b0(&DAT_1404a8650);
        return -1;
      }
      FUN_1401ae2f0(lVar8,local_80,(longlong)(int)(iVar4 * local_8c));
      (*DAT_140c2beb8)(lVar6);
      *param_3 = 0;
      *(undefined2 *)(param_3 + 1) = 0x1803;
      *(undefined8 *)(param_3 + 8) = 0;
      *(undefined2 *)((longlong)param_3 + 0xe) = 0;
      *(undefined8 *)(param_3 + 6) = 0xff;
      *(undefined2 *)((longlong)param_3 + 0xb) = 0x1000;
      param_3[4] = 0xff0000;
      *(undefined2 *)(param_3 + 2) = 0x808;
      *(undefined1 *)((longlong)param_3 + 0xd) = 8;
      param_3[5] = 0xff00;
      *(undefined1 *)((longlong)param_3 + 10) = 8;
      param_3[0x10c] = local_8c;
      return 1;
    }
    FUN_1401594b0(&DAT_1404a8630);
    (*DAT_140c2bec0)(uVar14);
    return -1;
  }
  if (iVar4 == 3) {
    bVar3 = *(byte *)(param_1 + 0xe);
    *(byte *)((longlong)param_3 + 5) = bVar3;
    bVar3 = bVar3 >> 3;
    *(byte *)(param_3 + 1) = bVar3;
    uVar11 = (uint)bVar3 * param_3[0x10a];
    param_3[0x10c] = uVar11;
    uVar10 = uVar11 & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    uVar13 = 0;
    if (uVar10 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 4 - uVar10;
    }
    uVar12 = 1;
    param_3[0x10c] = iVar4 + uVar11;
    uVar11 = 1;
    uVar10 = 1;
    iVar4 = 0;
    do {
      if ((uVar10 & *(uint *)(param_1 + 0x28)) != 0) break;
      iVar4 = iVar4 + 1;
      uVar10 = uVar10 * 2;
    } while (iVar4 < 0x20);
    *(char *)(param_3 + 3) = (char)iVar4;
    cVar9 = '\0';
    if (iVar4 < 0x20) {
      cVar9 = '\0';
      do {
        if ((uVar10 & *(uint *)(param_1 + 0x28)) == 0) break;
        iVar4 = iVar4 + 1;
        cVar9 = cVar9 + '\x01';
        uVar10 = uVar10 * 2;
      } while (iVar4 < 0x20);
    }
    *(char *)(param_3 + 2) = cVar9;
    param_3[4] = *(undefined4 *)(param_1 + 0x28);
    iVar4 = 0;
    do {
      if ((uVar11 & *(uint *)(param_1 + 0x2c)) != 0) break;
      iVar4 = iVar4 + 1;
      uVar11 = uVar11 * 2;
    } while (iVar4 < 0x20);
    *(char *)((longlong)param_3 + 0xd) = (char)iVar4;
    cVar9 = '\0';
    if (iVar4 < 0x20) {
      cVar9 = '\0';
      do {
        if ((uVar11 & *(uint *)(param_1 + 0x2c)) == 0) break;
        iVar4 = iVar4 + 1;
        cVar9 = cVar9 + '\x01';
        uVar11 = uVar11 * 2;
      } while (iVar4 < 0x20);
    }
    *(char *)((longlong)param_3 + 9) = cVar9;
    param_3[5] = *(undefined4 *)(param_1 + 0x2c);
    iVar4 = 0;
    do {
      if ((uVar12 & *(uint *)(param_1 + 0x30)) != 0) break;
      iVar4 = iVar4 + 1;
      uVar12 = uVar12 * 2;
    } while (iVar4 < 0x20);
    *(char *)((longlong)param_3 + 0xe) = (char)iVar4;
    bVar3 = 0;
    if (iVar4 < 0x20) {
      bVar3 = 0;
      do {
        if ((uVar12 & *(uint *)(param_1 + 0x30)) == 0) break;
        iVar4 = iVar4 + 1;
        bVar3 = bVar3 + 1;
        uVar12 = uVar12 * 2;
      } while (iVar4 < 0x20);
    }
    bVar1 = *(byte *)((longlong)param_3 + 5);
    *(byte *)((longlong)param_3 + 10) = bVar3;
    param_3[6] = *(undefined4 *)(param_1 + 0x30);
    *(undefined1 *)((longlong)param_3 + 0xb) = 0;
    *(undefined1 *)((longlong)param_3 + 0xf) = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    if ((uint)bVar3 + (uint)*(byte *)((longlong)param_3 + 9) + (uint)*(byte *)(param_3 + 2) !=
        (uint)bVar1) {
      if (bVar1 != 0) {
        uVar5 = (ulonglong)bVar1;
        do {
          uVar13 = uVar13 * 2 | 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        param_3[8] = uVar13;
      }
      param_3[8] = param_3[8] & ~(param_3[6] | param_3[5] | param_3[4]);
    }
    if (param_4 != 1) goto LAB_1401711b1;
    uVar14 = 0xa45;
    goto LAB_14017107f;
  }
  if (iVar4 != 0) {
    return -1;
  }
  if ((sVar2 - 0x10U & 0xfff7) != 0) {
    return -1;
  }
  bVar3 = *(byte *)(param_1 + 0xe);
  *(byte *)((longlong)param_3 + 5) = bVar3;
  bVar3 = bVar3 >> 3;
  *(byte *)(param_3 + 1) = bVar3;
  uVar11 = (uint)bVar3 * param_3[0x10a];
  param_3[0x10c] = uVar11;
  uVar10 = uVar11 & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  if (uVar10 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 4 - uVar10;
  }
  param_3[0x10c] = iVar4 + uVar11;
  if (*(short *)(param_1 + 0xe) == 0x10) {
    *(undefined2 *)(param_3 + 2) = 0x505;
    *(undefined2 *)(param_3 + 3) = 0x50a;
    param_3[4] = 0x7c00;
    param_3[5] = 0x3e0;
    *(undefined1 *)((longlong)param_3 + 10) = 5;
    param_3[6] = 0x1f;
LAB_14017118a:
    *(undefined1 *)((longlong)param_3 + 0xe) = 0;
  }
  else if (*(short *)(param_1 + 0xe) == 0x18) {
    *(undefined2 *)(param_3 + 2) = 0x808;
    *(undefined2 *)(param_3 + 3) = 0x810;
    param_3[4] = 0xff0000;
    param_3[5] = 0xff00;
    *(undefined1 *)((longlong)param_3 + 10) = 8;
    param_3[6] = 0xff;
    goto LAB_14017118a;
  }
  *(undefined1 *)((longlong)param_3 + 0xb) = 0;
  *(undefined1 *)((longlong)param_3 + 0xf) = 0;
  param_3[7] = 0;
  FUN_1401830a0(param_3);
  if (param_4 != 1) {
LAB_1401711b1:
    *(undefined8 *)(param_3 + 0x10e) = param_2;
    return param_4;
  }
  uVar14 = 0xa7a;
LAB_14017107f:
  lVar6 = FUN_1401b6390((longlong)(int)(param_3[0x10b] * param_3[0x10c]),
                        "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",uVar14);
  *(longlong *)(param_3 + 0x10e) = lVar6;
  if (lVar6 == 0) {
    return -1;
  }
  FUN_1401ae2f0(lVar6,param_2,(longlong)(int)(param_3[0x10b] * param_3[0x10c]));
  return param_4;
}


