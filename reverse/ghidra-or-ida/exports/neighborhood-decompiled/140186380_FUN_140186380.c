// Function: FUN_140186380 @ 140186380
// Decompile completed: true

undefined8
FUN_140186380(longlong *param_1,ulonglong *param_2,longlong param_3,int param_4,undefined8 param_5,
             ulonglong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = (longlong)param_4;
  uVar2 = param_6 + 0x1c + lVar3;
  if (uVar2 < 0x100000000) {
    lVar1 = FUN_1401b6390(uVar2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x4f46);
    if (lVar1 != 0) {
      FUN_1401ae2f0(lVar1,&DAT_1404a91c8,4);
      *(int *)(lVar1 + 4) = (int)uVar2 + -8;
      FUN_1401ae2f0(lVar1 + 8,&DAT_1404a91d0,4);
      FUN_1401ae2f0(lVar1 + 0xc,&DAT_1404a91d8,4);
      *(int *)(lVar1 + 0x10) = param_4;
      FUN_1401ae2f0(lVar1 + 0x14,param_3,lVar3);
      lVar3 = lVar1 + 0x14 + lVar3;
      FUN_1401ae2f0(lVar3,&DAT_1404a91e0,4);
      *(int *)(lVar3 + 4) = (int)param_6;
      FUN_1401ae2f0(lVar3 + 8,param_5,param_6);
      *param_1 = lVar1;
      *param_2 = uVar2;
      return 0;
    }
  }
  else {
    uVar2 = param_6 + 0x40 + lVar3;
    lVar1 = FUN_1401b6390(uVar2,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x4f1b);
    if (lVar1 != 0) {
      FUN_1401ae2f0(lVar1,&DAT_1404a9358,4);
      *(undefined4 *)(lVar1 + 4) = 0xffffffff;
      FUN_1401ae2f0(lVar1 + 8,&DAT_1404a91d0,4);
      FUN_1401ae2f0(lVar1 + 0xc,&DAT_1404a9360,4);
      *(undefined4 *)(lVar1 + 0x10) = 0x1c;
      *(ulonglong *)(lVar1 + 0x14) = uVar2 - 8;
      *(ulonglong *)(lVar1 + 0x1c) = param_6;
      *(ulonglong *)(lVar1 + 0x24) = param_6 / *(ushort *)(param_3 + 0xc);
      *(undefined4 *)(lVar1 + 0x2c) = 0;
      FUN_1401ae2f0(lVar1 + 0x30,&DAT_1404a91d8,4);
      *(int *)(lVar1 + 0x34) = param_4;
      FUN_1401ae2f0(lVar1 + 0x38,param_3,lVar3);
      lVar3 = lVar1 + 0x38 + lVar3;
      FUN_1401ae2f0(lVar3,&DAT_1404a91e0,4);
      *(undefined4 *)(lVar3 + 4) = 0xffffffff;
      FUN_1401ae2f0(lVar3 + 8,param_5,param_6);
      *param_1 = lVar1;
      *param_2 = uVar2;
      return 0;
    }
  }
  FUN_1401594b0(&DAT_1404a9368);
  return 0xffffffff;
}


