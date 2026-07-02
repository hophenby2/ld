// Function: FUN_14022b680 @ 14022b680
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14022b680(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined *puVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  undefined *puVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  bool bVar18;
  undefined1 auStack_5a8 [32];
  longlong *local_588;
  ulonglong local_580;
  longlong *local_578;
  undefined8 local_570;
  longlong local_568;
  longlong local_560;
  longlong local_558;
  int local_550 [2];
  longlong local_548;
  int local_540 [2];
  longlong local_538;
  undefined8 local_530;
  uint local_528;
  uint local_524;
  int local_520 [10];
  undefined4 local_4f8;
  undefined4 local_4f4;
  undefined4 uStack_4f0;
  undefined4 uStack_4ec;
  undefined4 uStack_4e8;
  undefined1 local_488 [512];
  undefined1 local_288 [592];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_5a8;
  pcVar13 = (char *)0x0;
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  iVar1 = FUN_1402202f0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_140222080();
  DAT_140d7aa6c = 0;
  iVar1 = thunk_FUN_1401ef520();
  if (iVar1 < 200) {
    _DAT_1407cd88c = 0;
  }
  iVar1 = FUN_14021f940();
  if (iVar1 < 0) {
    DAT_1407cd9c8 = 0x20;
    FUN_1401e32e0(1);
    iVar1 = FUN_14021f940();
    if (iVar1 < 0) {
      FUN_140153780(800,600);
      iVar1 = FUN_14021f940();
      if (iVar1 < 0) {
        FUN_140153780(0x400,0x300);
        iVar1 = FUN_14021f940();
        if (iVar1 < 0) {
          return 0xffffffff;
        }
      }
    }
  }
  FUN_140223510();
  DAT_140d81ac0 = 0;
  DAT_140d81ab8 = 0;
  DAT_140d81ab0 = 0;
  _DAT_140d81a9c = 0;
  DAT_140d81aa0 = 0;
  DAT_140d81ac8 = 0;
  DAT_140d81ad0 = 0;
  FUN_140221570(0,0,0,&DAT_140ca5ca8);
  FUN_1401594b0(&DAT_1404a74a0);
  iVar1 = FUN_1401a66f0();
  if ((iVar1 == 0) && (iVar1 = FUN_140143d60(), iVar1 != 0)) {
    pcVar6 = pcVar13;
    if (DAT_1407cda60 != 0) {
      pcVar6 = (char *)(ulonglong)DAT_1407cda64;
    }
    uVar4 = FUN_1402202b0(pcVar6);
    FUN_1401ae370(&local_4f8,0,0x68);
    local_4f8 = 0x68;
    FUN_1401e5720(uVar4,&local_4f8);
    _DAT_1407cda14 = local_4f4;
    _DAT_1407cda18 = uStack_4f0;
    uRam00000001407cda1c = uStack_4ec;
    uRam00000001407cda20 = uStack_4e8;
  }
  FUN_1402215c0(&DAT_140ca5a58);
  DAT_140ca5b8c = DAT_140ca5aec;
  _DAT_1407cd8d8 = 1;
  DAT_1407cd8b4 = DAT_140ca5b48;
  if (8 < DAT_140ca5b48) {
    DAT_1407cd8b4 = 8;
  }
  DAT_1407cd8e0 = 1;
  DAT_140ca5b90 = DAT_140ca5a78 >> 10 & 1;
  if (DAT_140ca5a44 == 0) {
    _DAT_140ca5d14 = (ulonglong)CONCAT14(0x1ff < DAT_140ca5b24,(uint)(0x1ff < DAT_140ca5b1c));
    _DAT_140ca5d1c = (ulonglong)CONCAT14(0x2ff < DAT_140ca5b24,(uint)(0x2ff < DAT_140ca5b1c));
    if ((0x2ff < DAT_140ca5b1c == 0) || (0x2ff >= DAT_140ca5b24)) goto LAB_14022b8f4;
  }
  else {
    _DAT_140ca5d14 = 0;
LAB_14022b8f4:
    _DAT_140ca5d1c = 0;
  }
  DAT_1407cd898 = DAT_140ca5a78 >> 0xb & 1;
  _DAT_1407cd8e8 = DAT_140ca5a78 >> 0x11 & 1;
  DAT_1407cd8bc = DAT_140ca5a94 >> 1 & 1;
  DAT_140d81980 = 0xff;
  DAT_1407cd8b0 = DAT_140ca5a94 >> 5 & 1;
  DAT_1407cd8b8 = DAT_140ca5a94 >> 8 & 1;
  DAT_140d81984 = 0xff;
  if (DAT_140ca5ab0 == 0) {
    DAT_140ca5ab0 = 0x100;
  }
  DAT_140d3ad94 = 1;
  if (DAT_140ca5ab4 == 0) {
    DAT_140ca5ab4 = 0x100;
  }
  DAT_1407cd8c0 = DAT_140ca5ab4;
  if (DAT_140ca5ab0 < DAT_140ca5ab4) {
    DAT_1407cd8c0 = DAT_140ca5ab0;
  }
  DAT_1407cd8cc = DAT_140ca5b0c;
  DAT_1407cd8d0 = DAT_140ca5b10;
  DAT_1407cd8c4 = DAT_140ca5ab0;
  DAT_1407cd8c8 = DAT_140ca5ab4;
  DAT_140ca5b94 = DAT_1407cd898;
  FUN_140220290(0,0,local_488);
  FUN_140159ab0("Driver:%s  Description:%s",local_488,local_288);
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  local_580 = CONCAT44(local_580._4_4_,DAT_1408ab148);
  local_588 = (longlong *)0x200;
  FUN_1401c0470(local_488,0xffffffff,0x7ffd,&DAT_140889d68);
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  local_580 = CONCAT44(local_580._4_4_,DAT_1408ab148);
  local_588 = (longlong *)0x200;
  FUN_1401c0470(local_288,0xffffffff,0x7ffd,&DAT_140889f68);
  pcVar6 = pcVar13;
  if (DAT_1407cda60 != 0) {
    pcVar6 = (char *)(ulonglong)DAT_1407cda64;
  }
  FUN_14021ee40(DAT_140ca5ca8,local_520);
  pcVar11 = "D3DFMT_X1R5G5B5";
  DAT_140ca5ba8 = local_520[0];
  if (local_520[0] == 0x16) {
    pcVar13 = "D3DFMT_X8R8G8B8";
  }
  else if (local_520[0] == 0x17) {
    pcVar13 = "D3DFMT_R5G6B5";
  }
  else if (local_520[0] == 0x18) {
    pcVar13 = "D3DFMT_X1R5G5B5";
  }
  else {
    FUN_140159ab0(&DAT_1404e6620);
  }
  FUN_140159ab0(&DAT_1404b1330,pcVar13);
  DAT_140ca5c78 = 0x50;
  FUN_140159ab0(&DAT_1404b1368,"D3DFMT_D16");
  iVar1 = DAT_140ca5ba8;
  local_580 = CONCAT44(local_580._4_4_,0x4d);
  local_588._0_4_ = 1;
  iVar2 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar2 == 0) {
    local_588._0_4_ = 0x4d;
    iVar1 = FUN_14021f5f0(pcVar6,1,iVar1,iVar1);
    if (iVar1 != 0) goto LAB_14022bb51;
    DAT_140ca5c7c = 0x4d;
    pcVar13 = "D3DFMT_D24X8";
  }
  else {
LAB_14022bb51:
    local_588._0_4_ = 0x47;
    iVar1 = FUN_140223630(pcVar6,1,DAT_140ca5ba8,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c7c = 0x47;
      pcVar13 = "D3DFMT_D32";
    }
    else {
      DAT_140ca5c7c = 0x50;
      pcVar13 = "D3DFMT_D16";
    }
  }
  FUN_140159ab0(&DAT_1404b13b0,pcVar13);
  iVar1 = DAT_140ca5ba8;
  local_580 = CONCAT44(local_580._4_4_,0x47);
  local_588._0_4_ = 1;
  iVar2 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar2 == 0) {
    local_588._0_4_ = 0x47;
    iVar1 = FUN_14021f5f0(pcVar6,1,iVar1,iVar1);
    if (iVar1 != 0) goto LAB_14022bc04;
    DAT_140ca5c80 = 0x47;
    pcVar13 = "D3DFMT_D32";
  }
  else {
LAB_14022bc04:
    local_588._0_4_ = 0x4d;
    iVar1 = FUN_140223630(pcVar6,1,DAT_140ca5ba8,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c80 = 0x4d;
      pcVar13 = "D3DFMT_D24X8";
    }
    else {
      local_588._0_4_ = 0x50;
      iVar1 = FUN_140223630(pcVar6,1,DAT_140ca5ba8,DAT_140ca5ba8);
      if (iVar1 == 0) {
        DAT_140ca5c80 = 0x50;
        pcVar13 = "D3DFMT_D16";
      }
    }
  }
  FUN_140159ab0(&DAT_1404b13f0,pcVar13);
  lVar16 = 3;
  local_580._0_4_ = 0x17;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0);
  if (iVar1 == 0) {
    DAT_140ca5bc4 = 0x17;
    pcVar11 = "D3DFMT_R5G6B5";
  }
  else {
    local_580._0_4_ = 0x18;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 != 0) {
      puVar14 = &DAT_1404e6690;
      goto LAB_14022da00;
    }
    DAT_140ca5bc4 = 0x18;
  }
  FUN_140159ab0(&DAT_1404b1458,pcVar11);
  local_580._0_4_ = 0x16;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5bc8 = 0x16;
    pcVar11 = "D3DFMT_X8R8G8B8";
  }
  else {
    DAT_140ca5bc8 = DAT_140ca5bc4;
  }
  FUN_140159ab0(&DAT_1404b14a0,pcVar11);
  local_580._0_4_ = 0x1a;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  pcVar13 = "D3DFMT_A8R8G8B8";
  if (iVar1 == 0) {
    DAT_140ca5bcc = 0x1a;
    pcVar11 = "D3DFMT_A4R4G4B4";
  }
  else {
    local_580._0_4_ = 0x15;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 != 0) {
      puVar14 = &DAT_1404e6700;
      goto LAB_14022da00;
    }
    DAT_140ca5bcc = 0x15;
    pcVar11 = "D3DFMT_A8R8G8B8";
  }
  FUN_140159ab0(&DAT_1404b14e8,pcVar11);
  local_580._0_4_ = 0x15;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5bd0 = 0x15;
    pcVar11 = "D3DFMT_A8R8G8B8";
  }
  else {
    local_580._0_4_ = 0x1a;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 != 0) {
      puVar14 = &DAT_1404e6750;
      goto LAB_14022da00;
    }
    DAT_140ca5bd0 = 0x1a;
    pcVar11 = "D3DFMT_A4R4G4B4";
  }
  FUN_140159ab0(&DAT_1404b1518,pcVar11);
  local_580._0_4_ = 0x19;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  pcVar11 = "D3DFMT_A1R5G5B5";
  if (iVar1 == 0) {
    DAT_140ca5bd4 = 0x19;
    pcVar8 = "D3DFMT_A1R5G5B5";
  }
  else {
    local_580._0_4_ = 0x15;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5bd4 = 0x15;
      pcVar8 = "D3DFMT_A8R8G8B8";
    }
    else {
      local_580._0_4_ = 0x1a;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 != 0) {
        puVar14 = &DAT_1404e67b0;
        goto LAB_14022da00;
      }
      DAT_140ca5bd4 = 0x1a;
      pcVar8 = "D3DFMT_A4R4G4B4";
    }
  }
  FUN_140159ab0(&DAT_1404b1548,pcVar8);
  local_580._0_4_ = 0x15;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5bd8 = 0x15;
    pcVar11 = "D3DFMT_A8R8G8B8";
  }
  else {
    local_580._0_4_ = 0x19;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5bd8 = 0x19;
    }
    else {
      local_580._0_4_ = 0x1a;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 != 0) {
        puVar14 = &DAT_1404e6810;
LAB_14022da00:
        FUN_1401594b0(puVar14);
        return 0xffffffff;
      }
      DAT_140ca5bd8 = 0x1a;
      pcVar11 = "D3DFMT_A4R4G4B4";
    }
  }
  FUN_140159ab0(&DAT_1404b1580,pcVar11);
  if (DAT_1407cd9c8 == 0x10) {
    _DAT_140ca5bb0 = DAT_140ca5bc4;
    _DAT_140ca5bb8 = DAT_140ca5bcc;
    _DAT_140ca5bbc = DAT_140ca5bd4;
  }
  else {
    _DAT_140ca5bb0 = DAT_140ca5bc8;
    _DAT_140ca5bb8 = DAT_140ca5bd0;
    _DAT_140ca5bbc = DAT_140ca5bd8;
  }
  local_580._0_4_ = 0x31545844;
  local_588._0_4_ = 3;
  _DAT_140ca5bac = _DAT_140ca5bb0;
  _DAT_140ca5bb4 = _DAT_140ca5bb8;
  _DAT_140ca5bc0 = _DAT_140ca5bbc;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  puVar14 = &DAT_1404b15d8;
  if (iVar1 == 0) {
    _DAT_140ca5bdc = 0x31545844;
    puVar9 = &DAT_1404e6868;
  }
  else {
    puVar9 = &DAT_1404b15d8;
    _DAT_140ca5bdc = DAT_140ca5bd4;
  }
  FUN_140159ab0(&DAT_1404b15e8,puVar9);
  local_580._0_4_ = 0x32545844;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5be0 = 0x32545844;
    puVar9 = &DAT_1404e6880;
  }
  else {
    puVar9 = &DAT_1404b15d8;
    _DAT_140ca5be0 = DAT_140ca5bd0;
  }
  FUN_140159ab0(&DAT_1404e6898,puVar9);
  local_580._0_4_ = 0x33545844;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5be4 = 0x33545844;
    puVar9 = &DAT_1404e68c0;
  }
  else {
    puVar9 = &DAT_1404b15d8;
    _DAT_140ca5be4 = DAT_140ca5bd0;
  }
  FUN_140159ab0(&DAT_1404b1660,puVar9);
  local_580._0_4_ = 0x34545844;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5be8 = 0x34545844;
    puVar9 = &DAT_1404e68d8;
  }
  else {
    puVar9 = &DAT_1404b15d8;
    _DAT_140ca5be8 = DAT_140ca5bd0;
  }
  FUN_140159ab0(&DAT_1404e68f0,puVar9);
  local_580._0_4_ = 0x35545844;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5bec = 0x35545844;
    puVar14 = &DAT_1404e6918;
  }
  else {
    _DAT_140ca5bec = DAT_140ca5bd0;
  }
  FUN_140159ab0(&DAT_1404b16d8,puVar14);
  local_580 = CONCAT44(local_580._4_4_,0x24);
  _DAT_140ca5bf0 = DAT_140ca5bd0;
  _DAT_140ca5bf4 = DAT_140ca5bd0;
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c0c = 0x24;
    FUN_140159ab0(&DAT_1404b1808,"D3DFMT_A16B16G16R16");
  }
  else {
    FUN_1401594b0(&DAT_1404e6950);
    _DAT_140ca5c0c = 0;
  }
  local_580 = CONCAT44(local_580._4_4_,0x71);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c10 = 0x71;
    FUN_140159ab0(&DAT_1404b18b0,"D3DFMT_A16B16G16R16F");
  }
  else {
    FUN_1401594b0(&DAT_1404e69c0);
    _DAT_140ca5c10 = 0;
  }
  local_580._0_4_ = 0x74;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c14 = 0x74;
    FUN_140159ab0(&DAT_1404b1960,"D3DFMT_A32B32G32R32F");
  }
  else {
    local_580._0_4_ = 0x71;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c14 = 0x71;
      FUN_140159ab0(&DAT_1404b1960,"D3DFMT_A16B16G16R16F");
    }
    else {
      FUN_1401594b0(&DAT_1404e6a30);
      _DAT_140ca5c14 = 0;
    }
  }
  local_580 = CONCAT44(local_580._4_4_,0x15);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c18 = 0x15;
    FUN_140159ab0(&DAT_1404b1a20,"D3DFMT_A8R8G8B8");
  }
  else {
    FUN_1401594b0(&DAT_1404e6a80);
    _DAT_140ca5c18 = 0;
  }
  local_580._0_4_ = 0x22;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c1c = 0x22;
    FUN_140159ab0(&DAT_1404b1ae0,"D3DFMT_G16R16");
  }
  else {
    local_580._0_4_ = 0x24;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c1c = 0x24;
      FUN_140159ab0(&DAT_1404b1ae0,"D3DFMT_A16B16G16R16");
    }
    else {
      FUN_1401594b0(&DAT_1404e6ae0);
      _DAT_140ca5c1c = 0;
    }
  }
  local_580._0_4_ = 0x6f;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c20 = 0x6f;
    FUN_140159ab0(&DAT_1404b1bb8,"D3DFMT_R16F");
  }
  else {
    local_580._0_4_ = 0x70;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c20 = 0x70;
      FUN_140159ab0(&DAT_1404b1bb8,"D3DFMT_G16R16F");
    }
    else {
      local_580._0_4_ = 0x71;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c20 = 0x71;
        FUN_140159ab0(&DAT_1404b1bb8,"D3DFMT_A16B16G16R16F");
      }
      else {
        local_580._0_4_ = 0x74;
        local_588._0_4_ = 3;
        iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
        if (iVar1 == 0) {
          _DAT_140ca5c20 = 0x74;
          FUN_140159ab0(&DAT_1404b1bb8,"D3DFMT_A32B32G32R32F");
        }
        else {
          FUN_1401594b0(&DAT_1404e6b50);
          _DAT_140ca5c20 = 0;
        }
      }
    }
  }
  local_580._0_4_ = 0x72;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  pcVar11 = "D3DFMT_R32F";
  if (iVar1 == 0) {
    _DAT_140ca5c24 = 0x72;
    FUN_140159ab0(&DAT_1404b1c88,"D3DFMT_R32F");
  }
  else {
    local_580._0_4_ = 0x73;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c24 = 0x73;
      FUN_140159ab0(&DAT_1404b1c88,"D3DFMT_G32R32F");
    }
    else {
      local_580._0_4_ = 0x74;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c24 = 0x74;
        FUN_140159ab0(&DAT_1404b1c88,"D3DFMT_A32B32G32R32F");
      }
      else {
        local_580._0_4_ = 0x71;
        local_588._0_4_ = 3;
        iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
        if (iVar1 == 0) {
          _DAT_140ca5c24 = 0x71;
          FUN_140159ab0(&DAT_1404b1c88,"D3DFMT_A16B16G16R16F");
        }
        else {
          FUN_1401594b0(&DAT_1404e6bd0);
          _DAT_140ca5c24 = 0;
        }
      }
    }
  }
  local_580 = CONCAT44(local_580._4_4_,0x15);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c28 = 0x15;
    FUN_140159ab0(&DAT_1404b1d20,"D3DFMT_A8B8G8R8");
  }
  else {
    FUN_1401594b0(&DAT_1404e6c40);
    _DAT_140ca5c28 = 0;
  }
  local_580._0_4_ = 0x22;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c2c = 0x22;
    FUN_140159ab0(&DAT_1404b1db0,"D3DFMT_G16R16");
  }
  else {
    local_580._0_4_ = 0x24;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c2c = 0x24;
      FUN_140159ab0(&DAT_1404b1db0,"D3DFMT_A16B16G16R16");
    }
    else {
      FUN_1401594b0(&DAT_1404e6c90);
      _DAT_140ca5c2c = 0;
    }
  }
  local_580._0_4_ = 0x70;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c30 = 0x70;
    FUN_140159ab0(&DAT_1404b1e48,"D3DFMT_G16R16F");
  }
  else {
    local_580._0_4_ = 0x71;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c30 = 0x71;
      FUN_140159ab0(&DAT_1404b1e48,"D3DFMT_A16B16G16R16F");
    }
    else {
      local_580._0_4_ = 0x74;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c30 = 0x74;
        FUN_140159ab0(&DAT_1404b1e48,"D3DFMT_A32B32G32R32F");
      }
      else {
        FUN_1401594b0(&DAT_1404e6ce0);
        _DAT_140ca5c30 = 0;
      }
    }
  }
  local_580._0_4_ = 0x73;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c34 = 0x73;
    FUN_140159ab0(&DAT_1404b1ee8,"D3DFMT_G32R32F");
  }
  else {
    local_580._0_4_ = 0x74;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c34 = 0x74;
      FUN_140159ab0(&DAT_1404b1ee8,"D3DFMT_A32B32G32R32F");
    }
    else {
      local_580._0_4_ = 0x71;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c34 = 0x71;
        FUN_140159ab0(&DAT_1404b1ee8,"D3DFMT_A16B16G16R16F");
      }
      else {
        FUN_1401594b0(&DAT_1404e6d40);
        _DAT_140ca5c34 = 0;
      }
    }
  }
  local_580._0_4_ = (DAT_140ca5ba8 != 0x17) + 0x17;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,1);
  if (iVar1 == 0) {
    bVar18 = DAT_140ca5ba8 != 0x17;
    pcVar8 = "D3DFMT_R5G5B5";
    pcVar7 = "D3DFMT_R5G6B5";
LAB_14022c9d2:
    DAT_140ca5c38 = bVar18 + 0x17;
    if (DAT_140ca5ba8 == 0x17) {
      pcVar8 = pcVar7;
    }
    if (DAT_140ca5c38 != 0) {
      FUN_140159ab0(&DAT_1404b1f78,pcVar8);
    }
  }
  else {
    local_580._0_4_ = (DAT_140ca5ba8 == 0x17) + 0x17;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,1);
    if (iVar1 == 0) {
      bVar18 = DAT_140ca5ba8 == 0x17;
      pcVar8 = "D3DFMT_R5G6B5";
      pcVar7 = "D3DFMT_R5G5B5";
      goto LAB_14022c9d2;
    }
    local_580._0_4_ = 0x16;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1);
    if (iVar1 == 0) {
      DAT_140ca5c38 = 0x16;
      FUN_140159ab0(&DAT_1404b1f78,"D3DFMT_X8R8G8B8");
    }
    else {
      FUN_1401594b0(&DAT_1404e6db0);
      DAT_140ca5c38 = 0;
    }
  }
  local_580._0_4_ = 0x16;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,1);
  if (iVar1 == 0) {
    DAT_140ca5c3c = 0x16;
    FUN_140159ab0(&DAT_1404b1ff8,"D3DFMT_X8R8G8B8");
  }
  else {
    local_580._0_4_ = 0x17;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c3c = 0x17;
      FUN_140159ab0(&DAT_1404b1ff8,"D3DFMT_R5G6B5");
    }
    else {
      local_580._0_4_ = 0x18;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        DAT_140ca5c3c = 0x18;
        FUN_140159ab0(&DAT_1404b1ff8,"D3DFMT_R5G5B5");
      }
      else {
        FUN_1401594b0(&DAT_1404e6e00);
        DAT_140ca5c3c = 0;
      }
    }
  }
  local_580._0_4_ = 0x15;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c40 = 0x15;
    FUN_140159ab0(&DAT_1404b2080,"D3DFMT_A8R8G8B8");
  }
  else {
    local_580._0_4_ = 0x1a;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c40 = 0x1a;
      FUN_140159ab0(&DAT_1404b2080,"D3DFMT_A4R4G4B4");
    }
    else {
      FUN_1401594b0(&DAT_1404e6e50);
      _DAT_140ca5c40 = 0;
    }
  }
  local_580 = CONCAT44(local_580._4_4_,0x24);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c44 = 0x24;
    FUN_140159ab0(&DAT_1404b2110,"D3DFMT_A16B16G16R16");
  }
  else {
    FUN_1401594b0(&DAT_1404e6eb0);
    _DAT_140ca5c44 = 0;
  }
  local_580 = CONCAT44(local_580._4_4_,0x71);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c48 = 0x71;
    FUN_140159ab0(&DAT_1404b21a8,"D3DFMT_A16B16G16R16F");
  }
  else {
    FUN_1401594b0(&DAT_1404e6f00);
    _DAT_140ca5c48 = 0;
  }
  local_580._0_4_ = 0x74;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c4c = 0x74;
    FUN_140159ab0(&DAT_1404b2248,"D3DFMT_A32B32G32R32F");
  }
  else {
    local_580._0_4_ = 0x71;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c4c = 0x71;
      FUN_140159ab0(&DAT_1404b2248,"D3DFMT_A16B16G16R16F");
    }
    else {
      FUN_1401594b0(&DAT_1404e6f60);
      _DAT_140ca5c4c = 0;
    }
  }
  local_580._0_4_ = 0x32;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c50 = 0x32;
    pcVar13 = "D3DFMT_L8";
LAB_14022cdc6:
    FUN_140159ab0(&DAT_1404b22e8,pcVar13);
  }
  else {
    local_580._0_4_ = 0x33;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c50 = 0x33;
      pcVar13 = "D3DFMT_A8L8";
      goto LAB_14022cdc6;
    }
    local_580._0_4_ = 0x15;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c50 = 0x15;
      goto LAB_14022cdc6;
    }
    FUN_1401594b0(&DAT_1404e6fe0);
    _DAT_140ca5c50 = 0;
  }
  local_580._0_4_ = 0x51;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5c54 = 0x51;
    FUN_140159ab0(&DAT_1404b2388,"D3DFMT_L16");
  }
  else {
    local_580._0_4_ = 0x22;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c54 = 0x22;
      FUN_140159ab0(&DAT_1404b2388,"D3DFMT_G16R16");
    }
    else {
      local_580._0_4_ = 0x24;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        DAT_140ca5c54 = 0x24;
        FUN_140159ab0(&DAT_1404b2388,"D3DFMT_A16B16G16R16");
      }
      else {
        FUN_1401594b0(&DAT_1404e7050);
        DAT_140ca5c54 = 0;
      }
    }
  }
  local_580._0_4_ = 0x6f;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5c58 = 0x6f;
    FUN_140159ab0(&DAT_1404b2430,"D3DFMT_R16F");
  }
  else {
    local_580._0_4_ = 0x70;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c58 = 0x70;
      FUN_140159ab0(&DAT_1404b2430,"D3DFMT_G16R16F");
    }
    else {
      local_580._0_4_ = 0x71;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        DAT_140ca5c58 = 0x71;
        FUN_140159ab0(&DAT_1404b2430,"D3DFMT_A16B16G16R16F");
      }
      else {
        local_580._0_4_ = 0x74;
        local_588._0_4_ = 3;
        iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
        if (iVar1 == 0) {
          DAT_140ca5c58 = 0x74;
          FUN_140159ab0(&DAT_1404b2430,"D3DFMT_A32B32G32R32F");
        }
        else {
          FUN_1401594b0(&DAT_1404e70b0);
          DAT_140ca5c58 = 0;
        }
      }
    }
  }
  local_580._0_4_ = 0x72;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    DAT_140ca5c5c = 0x72;
  }
  else {
    local_580._0_4_ = 0x73;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      DAT_140ca5c5c = 0x73;
      pcVar11 = "D3DFMT_G32R32F";
    }
    else {
      local_580._0_4_ = 0x74;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        DAT_140ca5c5c = 0x74;
        pcVar11 = "D3DFMT_A32B32G32R32F";
      }
      else {
        local_580._0_4_ = 0x71;
        local_588._0_4_ = 3;
        iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
        if (iVar1 != 0) {
          FUN_1401594b0(&DAT_1404e7110);
          DAT_140ca5c5c = 0;
          goto LAB_14022d12c;
        }
        DAT_140ca5c5c = 0x71;
        pcVar11 = "D3DFMT_A16B16G16R16F";
      }
    }
  }
  FUN_140159ab0(&DAT_1404b24e0,pcVar11);
LAB_14022d12c:
  local_580._0_4_ = 0x33;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c60 = 0x33;
    FUN_140159ab0(&DAT_1404b2588,"D3DFMT_A8L8");
  }
  else {
    local_580._0_4_ = 0x15;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c60 = 0x15;
      FUN_140159ab0(&DAT_1404b2588,"D3DFMT_A8B8G8R8");
    }
    else {
      FUN_1401594b0(&DAT_1404e7170);
      _DAT_140ca5c60 = 0;
    }
  }
  local_580._0_4_ = 0x22;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c64 = 0x22;
    FUN_140159ab0(&DAT_1404b2628,"D3DFMT_G16R16");
  }
  else {
    local_580._0_4_ = 0x24;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c64 = 0x24;
      FUN_140159ab0(&DAT_1404b2628,"D3DFMT_A16B16G16R16");
    }
    else {
      FUN_1401594b0(&DAT_1404e71d0);
      _DAT_140ca5c64 = 0;
    }
  }
  local_580._0_4_ = 0x70;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c68 = 0x70;
    FUN_140159ab0(&DAT_1404b26d0,"D3DFMT_G16R16F");
  }
  else {
    local_580._0_4_ = 0x71;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c68 = 0x71;
      FUN_140159ab0(&DAT_1404b26d0,"D3DFMT_A16B16G16R16F");
    }
    else {
      local_580._0_4_ = 0x74;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c68 = 0x74;
        FUN_140159ab0(&DAT_1404b26d0,"D3DFMT_A32B32G32R32F");
      }
      else {
        FUN_1401594b0(&DAT_1404e7230);
        _DAT_140ca5c68 = 0;
      }
    }
  }
  local_580._0_4_ = 0x73;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
  if (iVar1 == 0) {
    _DAT_140ca5c6c = 0x73;
    FUN_140159ab0(&DAT_1404b2780,"D3DFMT_G32R32F");
  }
  else {
    local_580._0_4_ = 0x74;
    local_588._0_4_ = 3;
    iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
    if (iVar1 == 0) {
      _DAT_140ca5c6c = 0x74;
      FUN_140159ab0(&DAT_1404b2780,"D3DFMT_A32B32G32R32F");
    }
    else {
      local_580._0_4_ = 0x71;
      local_588._0_4_ = 3;
      iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8);
      if (iVar1 == 0) {
        _DAT_140ca5c6c = 0x71;
        FUN_140159ab0(&DAT_1404b2780,"D3DFMT_A16B16G16R16F");
      }
      else {
        FUN_1401594b0(&DAT_1404e7290);
        _DAT_140ca5c6c = 0;
      }
    }
  }
  if (DAT_1407cd9c8 == 0x20) {
    DAT_140ca5c70 = DAT_140ca5c3c;
    DAT_140ca5c74 = DAT_140ca5bd8;
  }
  else {
    DAT_140ca5c70 = DAT_140ca5c38;
    DAT_140ca5c74 = DAT_140ca5bd4;
  }
  local_580._0_4_ = 0x15;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0x100000);
  puVar14 = &DAT_1404e72f0;
  if (iVar1 != 0) {
    puVar14 = &DAT_1404e7340;
  }
  FUN_1401594b0(puVar14);
  local_580._0_4_ = 0x16;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0x100000);
  puVar14 = &DAT_1404e7390;
  if (iVar1 != 0) {
    puVar14 = &DAT_1404e73e0;
  }
  FUN_1401594b0(puVar14);
  local_580._0_4_ = 0x17;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0x100000);
  puVar14 = &DAT_1404e7430;
  if (iVar1 != 0) {
    puVar14 = &DAT_1404e7480;
  }
  FUN_1401594b0(puVar14);
  local_580._0_4_ = 0x19;
  local_588._0_4_ = 3;
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0x100000);
  puVar14 = &DAT_1404e74d0;
  if (iVar1 != 0) {
    puVar14 = &DAT_1404e7520;
  }
  FUN_1401594b0(puVar14);
  local_580 = CONCAT44(local_580._4_4_,0x18);
  local_588 = (longlong *)CONCAT44(local_588._4_4_,3);
  iVar1 = FUN_14021f620(pcVar6,1,DAT_140ca5ba8,0x100000);
  puVar14 = &DAT_1404e7570;
  if (iVar1 != 0) {
    puVar14 = &DAT_1404e75c0;
  }
  FUN_1401594b0(puVar14);
  FUN_140159ab0(&DAT_1404e7610,DAT_1407cd8cc);
  FUN_140159ab0(&DAT_1404e7638,DAT_1407cd8d0);
  FUN_140159ab0(&DAT_1404b2888,DAT_1407cd8b4);
  FUN_140159ab0(&DAT_1404b28b0,DAT_140ca5ab0,DAT_140ca5ab4);
  puVar14 = &DAT_1404e7668;
  if (DAT_140ca5b90 != 0) {
    puVar14 = &DAT_1404e765c;
  }
  FUN_140159ab0(&DAT_1404e7678,puVar14);
  puVar14 = &DAT_1404e76b8;
  if (DAT_140ca5b94 != 0) {
    puVar14 = &DAT_1404e76a8;
  }
  FUN_140159ab0(&DAT_1404e76c8,puVar14);
  if (DAT_140ca5b88 == 0) {
    FUN_140159ab0(&DAT_1404e76e8,DAT_140ca5d10);
    FUN_140159ab0(&DAT_1404e7768,DAT_140ca5b1c);
  }
  else {
    FUN_140159ab0(&DAT_1404e76e8,DAT_140ca5b1c);
    FUN_140159ab0(&DAT_1404e7720);
  }
  FUN_140159ab0(&DAT_1404e77a0,DAT_140ca5b24);
  local_560 = 0;
  local_568 = 0;
  local_558 = 0;
  DAT_140ca5b98 = 0;
  if (DAT_1407cd88c != 0) {
    FUN_1401594b0(&DAT_1404e77d0);
    return 0;
  }
  do {
    lVar15 = -1;
    lVar17 = -1;
    for (uVar10 = 0x100; (DAT_1407cd9b8 < uVar10 || (DAT_1407cd9bc < uVar10)); uVar10 = uVar10 >> 1)
    {
    }
    local_588 = &local_558;
    local_580 = 0;
    local_558 = 0;
    iVar1 = FUN_140220c30(uVar10,uVar10,DAT_140ca5ba8,2);
    if (iVar1 == 0) {
      local_530 = 0;
      local_528 = uVar10;
      local_524 = uVar10;
      lVar5 = FUN_14023b310(DAT_140ca5ba8);
      iVar1 = FUN_140222ec0(local_558,local_540,&local_530,0x10);
      if (iVar1 == 0) {
        lVar15 = FUN_1401ad240();
        iVar1 = FUN_140222ec0(DAT_140ca5ca8,local_550,&local_530,0x10);
        if (iVar1 == 0) {
          uVar12 = 0;
          if (uVar10 != 0) {
            do {
              FUN_1401ae2f0((ulonglong)(local_540[0] * uVar12) + local_538,
                            (ulonglong)(local_550[0] * uVar12) + local_548,
                            *(byte *)(lVar5 + 4) * uVar10);
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar10);
          }
          FUN_140222f90(DAT_140ca5ca8);
          lVar17 = FUN_1401ad240();
          lVar15 = lVar17 - lVar15;
          lVar17 = FUN_1401ad240();
          local_570 = 0;
          local_578 = &local_560;
          local_580 = local_580 & 0xffffffff00000000;
          local_588 = (longlong *)((ulonglong)local_588 & 0xffffffff00000000);
          iVar1 = FUN_140220e50(uVar10,uVar10,DAT_140ca5ba8,0);
          if (iVar1 == 0) {
            local_588 = &local_568;
            local_580 = 0;
            iVar1 = FUN_140220c30(uVar10,uVar10,DAT_140ca5ba8,2);
            if (iVar1 == 0) {
              local_588 = (longlong *)((ulonglong)local_588 & 0xffffffff00000000);
              FUN_140222b60(DAT_140ca5ca8,&local_530,local_560,&local_530);
              FUN_140221600(local_560,local_568);
              iVar1 = FUN_140222ec0(local_568,local_550,0,0x10);
              if (iVar1 == 0) {
                uVar12 = 0;
                if (uVar10 != 0) {
                  do {
                    FUN_1401ae2f0((ulonglong)(local_540[0] * uVar12) + local_538,
                                  (ulonglong)(local_550[0] * uVar12) + local_548,
                                  *(byte *)(lVar5 + 4) * uVar10);
                    uVar12 = uVar12 + 1;
                  } while (uVar12 < uVar10);
                }
                FUN_140222f90(local_568);
                FUN_14021f140(local_560);
                FUN_14021f140(local_568);
                local_560 = 0;
                local_568 = 0;
                lVar5 = FUN_1401ad240();
                lVar17 = lVar5 - lVar17;
              }
            }
          }
        }
      }
    }
    if (local_568 != 0) {
      FUN_14021f140();
      local_568 = 0;
    }
    if (local_560 != 0) {
      FUN_14021f140();
      local_560 = 0;
    }
    if (local_558 != 0) {
      FUN_14021f140();
      local_558 = 0;
    }
    lVar16 = lVar16 + -1;
  } while (lVar16 != 0);
  if ((lVar17 != -1) && (lVar15 != -1)) {
    uVar3 = FUN_1401accc0(lVar17);
    uVar4 = FUN_1401accc0(lVar15);
    FUN_140159b70(&DAT_1404e7850,uVar4,uVar3);
    if (lVar17 <= lVar15) {
      FUN_1401594b0(&DAT_1404e78e8);
      return 0;
    }
    DAT_140ca5b98 = 1;
    FUN_1401594b0(&DAT_1404e78c0);
    return 0;
  }
  FUN_1401594b0(&DAT_1404e7820);
  return 0;
}


