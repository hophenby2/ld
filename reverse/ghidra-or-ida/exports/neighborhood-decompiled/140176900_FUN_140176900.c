// Function: FUN_140176900 @ 140176900
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong FUN_140176900(longlong param_1,undefined8 param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  int local_b0;
  undefined4 local_a8;
  int local_a0;
  int local_98;
  undefined8 local_90;
  longlong local_88;
  undefined4 local_80;
  undefined4 local_78;
  longlong local_68;
  undefined1 local_60 [12];
  uint local_54;
  ulonglong local_40;
  
  local_40 = DAT_1407c6b00 ^ (ulonglong)auStack_d8;
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  uVar3 = (*DAT_140c2be80)(0);
  iVar2 = 0;
  if ((param_4 == (undefined4 *)0x0) ||
     ((*(byte *)((longlong)param_4 + 5) != 0x10 &&
      ((*(byte *)((longlong)param_4 + 5) < 0x19 || (*(short *)(param_1 + 0xe) == 0x18)))))) {
    if (*(ushort *)(param_1 + 0xe) < 9) {
      iVar2 = 4 << ((byte)*(ushort *)(param_1 + 0xe) & 0x1f);
    }
  }
  else {
    iVar2 = 0xc;
  }
  puVar4 = (undefined4 *)
           FUN_1401b6390((longlong)iVar2 + 0x28,
                         "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x8e3);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_1401594b0(&DAT_1404a88a0);
    (*DAT_140c2bec0)(uVar3);
    return 0;
  }
  FUN_1401ae370(puVar4,0,0x28);
  *puVar4 = 0x28;
  puVar4[1] = *(undefined4 *)(param_1 + 4);
  uVar8 = *(uint *)(param_1 + 8);
  uVar7 = (int)uVar8 >> 0x1f;
  *(undefined2 *)(puVar4 + 3) = 1;
  puVar4[2] = -((uVar8 ^ uVar7) - uVar7);
  if (param_4 == (undefined4 *)0x0) {
LAB_140176abe:
    if (*(short *)(param_1 + 0xe) == 8) {
      *(undefined2 *)((longlong)puVar4 + 0xe) = 8;
      puVar4[4] = *(undefined4 *)(param_1 + 0x10);
      FUN_1401ae2f0(puVar4 + 10,param_1 + 0x28,0x400);
    }
    else {
      puVar4[4] = 0;
      *(undefined2 *)((longlong)puVar4 + 0xe) = 0x18;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
        *(undefined2 *)(param_4 + 1) = 0x1803;
        *(undefined8 *)(param_4 + 8) = 0;
        *(undefined2 *)((longlong)param_4 + 0xe) = 0;
        *(undefined8 *)(param_4 + 6) = 0xff;
        *(undefined2 *)((longlong)param_4 + 0xb) = 0x1000;
        param_4[4] = 0xff0000;
        *(undefined2 *)(param_4 + 2) = 0x808;
        *(undefined1 *)((longlong)param_4 + 0xd) = 8;
        param_4[5] = 0xff00;
        *(undefined1 *)((longlong)param_4 + 10) = 8;
      }
    }
  }
  else {
    bVar1 = *(byte *)((longlong)param_4 + 5);
    if (bVar1 == 0x10) {
      if ((DAT_140824370 == 1) || (DAT_140824374 != 0)) goto LAB_140176abe;
    }
    else if ((bVar1 < 0x19) || (*(short *)(param_1 + 0xe) == 0x18)) {
      if (bVar1 == 0x20) {
        *(undefined2 *)((longlong)puVar4 + 0xe) = 0x18;
        *param_4 = 0;
        *(undefined2 *)(param_4 + 1) = 0x1803;
        *(undefined8 *)(param_4 + 8) = 0;
        *(undefined2 *)((longlong)param_4 + 0xe) = 0;
        *(undefined8 *)(param_4 + 6) = 0xff;
        *(undefined2 *)((longlong)param_4 + 0xb) = 0x1000;
        param_4[4] = 0xff0000;
        *(undefined2 *)(param_4 + 2) = 0x808;
        *(undefined1 *)((longlong)param_4 + 0xd) = 8;
        param_4[5] = 0xff00;
        *(undefined1 *)((longlong)param_4 + 10) = 8;
      }
      puVar4[4] = 0;
      *(ushort *)((longlong)puVar4 + 0xe) = (ushort)*(byte *)((longlong)param_4 + 5);
      goto LAB_140176b37;
    }
    puVar4[10] = param_4[4];
    puVar4[0xb] = param_4[5];
    puVar4[0xc] = param_4[6];
    puVar4[4] = 3;
    *(ushort *)((longlong)puVar4 + 0xe) = (ushort)*(byte *)((longlong)param_4 + 5);
  }
LAB_140176b37:
  local_b0 = 0;
  local_b8 = 0;
  lVar5 = (*DAT_140c2bee0)(uVar3,puVar4,0,&local_68);
  if (lVar5 == 0) {
    FUN_1401594b0(&DAT_1404a8630);
    FUN_1401b6700(puVar4);
    (*DAT_140c2bec0)(uVar3);
    lVar5 = 0;
  }
  else {
    FUN_1401b6700(puVar4);
    (*DAT_140c2be98)(lVar5,0x20,local_60);
    local_54 = local_54 + 3 + ((int)(local_54 + 3) >> 0x1f & 3U) & 0xfffffffc;
    if (local_68 == 0) {
      FUN_1401594b0(&DAT_1404a88e8);
      lVar5 = 0;
    }
    else {
      uVar6 = (*DAT_140c2beb0)(uVar3,lVar5);
      local_90 = param_2;
      local_88 = param_1;
      if (param_3 == 0) {
        local_80 = 0;
        uVar8 = (int)*(uint *)(param_1 + 8) >> 0x1f;
        local_98 = (*(uint *)(param_1 + 8) ^ uVar8) - uVar8;
        local_a0 = 0;
        local_a8 = 0;
        local_b0 = 0;
        local_b8 = CONCAT44(local_b8._4_4_,local_98);
        (*DAT_140c2bef0)(uVar3,0,0);
      }
      else {
        uVar8 = *(uint *)(param_1 + 8);
        local_78 = 0xcc0020;
        local_80 = 0;
        local_98 = (uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f);
        local_b0 = *(int *)(param_1 + 4) + -1;
        local_a0 = -*(int *)(param_1 + 4);
        local_a8 = 0;
        local_b8 = CONCAT44(local_b8._4_4_,uVar8);
        (*DAT_140c2bee8)(uVar3,0,0);
      }
      (*DAT_140c2beb0)(uVar3,uVar6);
      (*DAT_140c2bec0)(uVar3);
    }
  }
  return lVar5;
}


