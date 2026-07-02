// Function: FUN_140212a60 @ 140212a60
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140212a60(longlong param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  short *psVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  short *psVar13;
  undefined1 auStack_68 [32];
  int local_48;
  uint uStack_44;
  ulonglong local_40;
  undefined1 local_38 [4];
  undefined1 local_34;
  ulonglong local_30;
  
  local_30 = DAT_1407c6b00 ^ (ulonglong)auStack_68;
  *(undefined8 *)(param_1 + 0x92) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x7a) = 0;
  *(undefined8 *)(param_1 + 0x9a) = 0xffffffffffffffff;
  local_40 = 0;
  bVar2 = false;
  psVar13 = (short *)0x0;
  (**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40));
  if (local_48 != 0x46464952) {
    psVar6 = (short *)0x0;
    if (local_48 != 0x34364652) goto LAB_140212fc3;
    bVar2 = true;
  }
  local_34 = 0;
  (**(code **)(param_1 + 0x20))(local_38,4,1,*(undefined8 *)(param_1 + 0x40));
  iVar3 = FUN_1401ae750(local_38,&DAT_1404a91d0);
  psVar6 = psVar13;
  if (iVar3 != 0) goto LAB_140212fc3;
  uVar5 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40));
  if (bVar2) {
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
    while ((iVar3 == 0 &&
           ((**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40)),
           local_48 != 0x34367364))) {
      (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),(uStack_44 & 1) + uStack_44,1);
      iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
    }
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
    if (iVar3 != 0) goto LAB_140212fc3;
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),8,1);
    (**(code **)(param_1 + 0x20))(&local_40,8,1,*(undefined8 *)(param_1 + 0x40));
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),0xc,1);
  }
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  while ((iVar3 == 0 &&
         ((**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40)),
         local_48 != 0x20746d66))) {
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),(uStack_44 & 1) + uStack_44,1);
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  }
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  if ((iVar3 != 0) ||
     (psVar6 = (short *)FUN_1401b6390(uStack_44,
                                      "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp"
                                      ,0x20c), psVar6 == (short *)0x0)) goto LAB_140212fc3;
  iVar3 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40));
  *(longlong *)(param_1 + 0x48) = (longlong)iVar3;
  *(longlong *)(param_1 + 0x50) = (longlong)(int)uStack_44;
  FUN_1401ae370(param_1 + 0x7a,0,0x400);
  *(undefined8 *)(param_1 + 0x92) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x9a) = 0xffffffffffffffff;
  FUN_1401ae370(param_1 + 0x68,0,0x12);
  (**(code **)(param_1 + 0x20))(psVar6,uStack_44,1,*(undefined8 *)(param_1 + 0x40));
  if (*psVar6 == 1) {
    uVar12 = 0x12;
    if (uStack_44 < 0x13) {
      uVar12 = uStack_44;
    }
    FUN_1401ae2f0(param_1 + 0x68,psVar6,uVar12);
    if (uStack_44 != 0x10) goto LAB_140212d20;
    *(ushort *)(param_1 + 0x76) = (ushort)psVar6[6] / (ushort)psVar6[1] << 3;
    *(undefined2 *)(param_1 + 0x78) = 0;
LAB_140212d25:
    uVar12 = uStack_44;
  }
  else {
    if (*psVar6 != 3) goto LAB_140212fc3;
    uVar12 = *(uint *)(psVar6 + 2);
    *(uint *)(param_1 + 0x6c) = uVar12;
    uVar1 = psVar6[1];
    *(ushort *)(param_1 + 0x6a) = uVar1;
    *(undefined2 *)(param_1 + 0x76) = 0x10;
    *(undefined2 *)(param_1 + 0x68) = 1;
    uVar4 = (int)((uint)uVar1 * 0x10) >> 3;
    *(short *)(param_1 + 0x74) = (short)uVar4;
    *(uint *)(param_1 + 0x70) = (uVar4 & 0xffff) * uVar12;
    *(ulonglong *)(param_1 + 0x8a) = (ulonglong)uVar12;
    uVar12 = *(uint *)(psVar6 + 4);
    *(ulonglong *)(param_1 + 0x82) = (ulonglong)uVar12;
    lVar7 = FUN_1401b6390((ulonglong)uVar12,
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",0x233);
    *(longlong *)(param_1 + 0x7a) = lVar7;
    if (lVar7 == 0) goto LAB_140212fc3;
LAB_140212d20:
    uVar12 = 0x12;
    if (uStack_44 < 0x13) goto LAB_140212d25;
  }
  FUN_1401ae2f0(param_1 + 0xa2,psVar6,uVar12);
  FUN_1401b6700(psVar6);
  psVar6 = (short *)0x0;
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  while ((iVar3 == 0 &&
         ((**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40)),
         local_48 != 0x61746164))) {
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),(uStack_44 & 1) + uStack_44,1);
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  }
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  if (iVar3 != 0) {
LAB_140212fc3:
    if (*(longlong *)(param_1 + 0x7a) != 0) {
      FUN_1401b6700();
      *(undefined8 *)(param_1 + 0x7a) = 0;
    }
    if (psVar6 != (short *)0x0) {
      FUN_1401b6700(psVar6);
    }
    return 0xffffffff;
  }
  uVar8 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40));
  *(undefined8 *)(param_1 + 0x58) = uVar8;
  if (bVar2) {
    uVar9 = (ulonglong)*(ushort *)(param_1 + 0x74);
    uVar11 = local_40 % uVar9;
    uVar9 = (local_40 / uVar9) * uVar9;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x74);
    uVar11 = (ulonglong)uStack_44 % (ulonglong)uVar1;
    uVar9 = (ulonglong)((uStack_44 / uVar1) * (uint)uVar1);
  }
  *(ulonglong *)(param_1 + 0x60) = uVar9;
  *(ulonglong *)(param_1 + 0x488) = (ulonglong)*(uint *)(param_1 + 0x70);
  lVar7 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40),uVar11);
  (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),(uStack_44 & 1) + uStack_44,1);
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  while (iVar3 == 0) {
    (**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40));
    if (local_48 == 0x6c706d73) goto LAB_140212f56;
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
    if (iVar3 != 0) break;
    if ((bVar2) && (local_48 == 0x61746164)) {
      uVar11 = ((uint)local_40 & 1) + local_40;
    }
    else {
      uVar11 = (ulonglong)((uStack_44 & 1) + uStack_44);
    }
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),uVar11,1);
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  }
  (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),uVar5,0);
  iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  while ((iVar3 == 0 &&
         (lVar10 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40)), lVar10 < lVar7)))
  {
    (**(code **)(param_1 + 0x20))(&local_48,8,1,*(undefined8 *)(param_1 + 0x40));
    if (local_48 == 0x6c706d73) goto LAB_140212f56;
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
    if (iVar3 != 0) break;
    if ((bVar2) && (local_48 == 0x61746164)) {
      uVar11 = ((uint)local_40 & 1) + local_40;
    }
    else {
      uVar11 = (ulonglong)((uStack_44 & 1) + uStack_44);
    }
    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),uVar11,1);
    iVar3 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x40));
  }
LAB_140212fac:
  (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x58),0);
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
LAB_140212f56:
  lVar7 = FUN_1401b6390(uStack_44,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",
                        0x295);
  if (lVar7 == 0) goto LAB_140212fc3;
  (**(code **)(param_1 + 0x20))(lVar7,uStack_44,1,*(undefined8 *)(param_1 + 0x40));
  if (0x17 < (ulonglong)uStack_44 - 0x24) {
    *(ulonglong *)(param_1 + 0x92) = (ulonglong)*(uint *)(lVar7 + 0x2c);
    *(ulonglong *)(param_1 + 0x9a) = (ulonglong)*(uint *)(lVar7 + 0x30);
  }
  FUN_1401b6700(lVar7);
  goto LAB_140212fac;
}


