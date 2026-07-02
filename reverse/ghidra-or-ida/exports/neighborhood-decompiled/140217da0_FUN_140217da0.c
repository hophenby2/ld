// Function: FUN_140217da0 @ 140217da0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140217da0(int *param_1,longlong param_2,ulonglong param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined4 *puVar8;
  longlong *plVar9;
  undefined1 auStack_88 [32];
  undefined1 local_68 [32];
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_88;
  piVar1 = param_1 + 0x34;
  FUN_1401b6dc0(piVar1,"..\\..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x55f);
  if (param_2 == 0) {
    if (*param_1 == 0) goto LAB_140217e31;
    uVar6 = 0x100000;
    if (0xfffff < param_3) {
      uVar6 = param_3;
    }
    uVar6 = uVar6 + 0x1f & 0xfffffffffffffff0;
    if ((param_1[0x14] != 0) || (0x13f < uVar6)) {
      FUN_1401ae370(local_68,0,0x20);
      iVar3 = (**(code **)(param_1 + 6))(param_1[4],local_68,uVar6);
      if (iVar3 < 0) {
        FUN_140159b70(&DAT_1404b5550);
        goto LAB_140217e31;
      }
      param_3 = (**(code **)(param_1 + 10))(param_1[4],local_68);
      param_2 = (**(code **)(param_1 + 8))(param_1[4],local_68);
      plVar9 = (longlong *)(param_2 + 0xfU & 0xfffffffffffffff0);
      uVar6 = (param_3 + param_2 & 0xfffffffffffffff0) - (longlong)plVar9;
      bVar2 = true;
LAB_140217ec6:
      plVar7 = plVar9;
      if (param_1[0x14] != 0) {
        plVar7 = *(longlong **)(param_1 + 0x20);
        if (plVar7 == (longlong *)0x0) goto LAB_140217e31;
        param_1[0x1d] = param_1[0x1d] + 1;
        if (plVar7[8] == 0) {
          *(longlong *)(param_1 + 0x20) = plVar7[9];
        }
        else {
          *(longlong *)(plVar7[8] + 0x48) = plVar7[9];
        }
        if (plVar7[9] != 0) {
          *(longlong *)(plVar7[9] + 0x40) = plVar7[8];
        }
        plVar7[8] = 0;
        plVar7[9] = 0;
      }
      FUN_1401ae370(plVar7,0,0x78);
      if (bVar2) {
        *(uint *)(plVar7 + 10) = *(uint *)(plVar7 + 10) | 1;
        FUN_1401ae2f0((longlong)plVar7 + 0x54,local_68,0x20);
      }
      *plVar7 = param_2;
      plVar7[1] = param_3;
      plVar7[2] = (longlong)plVar9;
      plVar7[3] = uVar6;
      if (param_1[0x14] == 0) {
        plVar9 = plVar7 + 0xf;
      }
      uVar6 = (longlong)plVar9 + 0xfU & 0xfffffffffffffff0;
      plVar7[4] = uVar6;
      plVar7[5] = (param_3 - uVar6) + param_2 & 0xfffffffffffffff0;
      plVar7[9] = *(longlong *)(param_1 + 0x22);
      *(longlong **)(param_1 + 0x22) = plVar7;
      if (plVar7[9] != 0) {
        *(longlong **)(plVar7[9] + 0x40) = plVar7;
      }
      if (param_1[0x14] == 0) {
        puVar8 = (undefined4 *)plVar7[4];
LAB_140217ffe:
        *puVar8 = 0x4d454d44;
        *(undefined1 *)((longlong)puVar8 + 0x16) = 0;
        iVar3 = FUN_1401ba9b0(0x7ffd,&DAT_1404b54ac);
        uVar5 = 0;
        if (0x10 < iVar3) {
          uVar5 = iVar3 - 0x11;
        }
        FUN_1401ba3d0(0x7ffd,puVar8 + 1,&DAT_1404b54ac + (int)uVar5);
        *(byte *)((longlong)puVar8 + 0x16) = *(byte *)((longlong)puVar8 + 0x16) & 0xfc;
        *(undefined2 *)((longlong)puVar8 + 0x1e) = 0;
        *(int **)(puVar8 + 0x18) = param_1;
        *(undefined1 *)((longlong)puVar8 + 0x19) = *(undefined1 *)((longlong)param_1 + 0x4a);
        *(short *)((longlong)puVar8 + 0x1a) = (short)param_1[0x12];
        param_1[0x12] = param_1[0x12] + 1;
        uVar5 = param_1[0x12];
        if (0xffffff < (uint)param_1[0x12]) {
          uVar5 = 0;
        }
        param_1[0x12] = uVar5;
        *(short *)(puVar8 + 7) = (short)param_1[0x13];
        if (param_1[0x14] != 0) {
          *(longlong *)(puVar8 + 10) = plVar7[4];
        }
        *(longlong *)(puVar8 + 8) = plVar7[5];
        *(longlong **)(puVar8 + 0x1a) = plVar7;
        plVar7[7] = (longlong)puVar8;
        if (param_1[0x14] == 0) {
          FUN_1402181b0(puVar8);
        }
        *(undefined8 *)(puVar8 + 0x12) = *(undefined8 *)(param_1 + 0x28);
        *(undefined8 *)(puVar8 + 0x10) = 0;
        *(undefined4 **)(param_1 + 0x28) = puVar8;
        if (*(longlong *)(puVar8 + 0x12) == 0) {
          *(undefined4 **)(param_1 + 0x2a) = puVar8;
        }
        else {
          *(undefined4 **)(*(longlong *)(puVar8 + 0x12) + 0x40) = puVar8;
        }
        param_1[0x24] = param_1[0x24] + 1;
        *(longlong *)(param_1 + 0x26) = *(longlong *)(param_1 + 0x26) + *(longlong *)(puVar8 + 8);
        if (param_1[0xe] == 0) {
          *(undefined8 *)(puVar8 + 0x14) = 0;
          *(undefined8 *)(puVar8 + 0x16) = *(undefined8 *)(param_1 + 0x2102);
          *(undefined4 **)(param_1 + 0x2102) = puVar8;
          if (*(longlong *)(puVar8 + 0x16) == 0) {
            *(undefined4 **)(param_1 + 0x2104) = puVar8;
            FUN_1401b6e70(piVar1);
            return 0;
          }
          *(undefined4 **)(*(longlong *)(puVar8 + 0x16) + 0x50) = puVar8;
          FUN_1401b6e70(piVar1);
          return 0;
        }
        if (param_1[0xe] == 1) {
          FUN_140219720(param_1,puVar8);
        }
        FUN_1401b6e70(piVar1);
        return 0;
      }
      puVar8 = *(undefined4 **)(param_1 + 0x1a);
      if (puVar8 != (undefined4 *)0x0) {
        FUN_14021a380(param_1,puVar8);
        goto LAB_140217ffe;
      }
      goto LAB_140217e31;
    }
    puVar4 = &DAT_1404b54f0;
  }
  else {
    if (param_3 == 0) goto LAB_140217e31;
    plVar9 = (longlong *)(param_2 + 0xfU & 0xfffffffffffffff0);
    uVar6 = (param_3 + param_2 & 0xfffffffffffffff0) - (longlong)plVar9;
    bVar2 = false;
    if ((param_1[0x14] != 0) || (bVar2 = false, 0x13f < uVar6)) goto LAB_140217ec6;
    puVar4 = &DAT_1404b5580;
  }
  FUN_140159b70(puVar4,uVar6,0x140);
LAB_140217e31:
  FUN_1401b6e70(piVar1);
  return 0xffffffff;
}


