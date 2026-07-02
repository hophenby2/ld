// Function: FUN_1401a2270 @ 1401a2270
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401a2270(longlong param_1,int param_2,uint *param_3,longlong param_4,int param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  bool bVar13;
  undefined1 auStack_148 [32];
  undefined8 *local_128;
  ulonglong local_120;
  undefined4 *local_118;
  undefined4 *local_110;
  undefined4 local_100;
  undefined8 *local_fc;
  undefined4 local_f0;
  uint local_ec;
  int local_e8;
  undefined4 *local_e0;
  undefined4 local_c8;
  undefined4 *local_c4;
  undefined4 local_b8;
  undefined4 *local_b4;
  undefined4 local_a8;
  uint uStack_a4;
  uint uStack_a0;
  undefined4 uStack_9c;
  undefined2 local_98;
  undefined8 local_90;
  undefined4 local_88;
  uint local_84;
  undefined4 local_80;
  undefined8 local_7c;
  undefined4 local_74;
  longlong local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  longlong local_58;
  ulonglong local_50;
  
  local_50 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  puVar11 = (undefined8 *)0x0;
  puVar8 = (undefined8 *)0x0;
  plVar1 = (longlong *)(param_1 + 0x118);
  *plVar1 = 0;
  plVar2 = (longlong *)(param_1 + 0x120);
  *plVar2 = 0;
  puVar7 = (undefined8 *)(param_1 + 0x128);
  *puVar7 = 0;
  *(undefined8 *)(param_1 + 0x130) = 0;
  if (param_4 == 0) {
    uVar10 = *param_3;
    uStack_a4 = param_3[1];
    uStack_a0 = param_3[2];
    uStack_9c = param_3[3];
    local_98 = (undefined2)param_3[4];
  }
  else {
    param_2 = (uint)*(ushort *)(param_4 + 0x40) * *(int *)(param_4 + 0x30);
    uVar10 = *(uint *)(param_4 + 0x34);
    uStack_a4 = *(uint *)(param_4 + 0x38);
    uStack_a0 = *(uint *)(param_4 + 0x3c);
    uStack_9c = *(uint *)(param_4 + 0x40);
    local_98 = *(undefined2 *)(param_4 + 0x44);
  }
  local_a8 = uVar10;
  if (DAT_14086f310 == 0) {
    FUN_1401ae370(&local_f0,0,0x28);
    uVar10 = 2;
    local_ec = 2;
    local_f0 = 0x28;
    if (DAT_14086f320 != 0) {
      local_ec = 8;
    }
    local_ec = local_ec | 0x180e0;
    local_e0 = &local_a8;
    local_e8 = param_2;
    iVar5 = (**(code **)(*DAT_140865b70 + 0x18))(DAT_140865b70,&local_f0,plVar1,0);
    if (iVar5 != 0) {
      FUN_1401ae370(&local_f0,0,0x28);
      local_e0 = &local_a8;
      if (DAT_14086f320 != 0) {
        uVar10 = 8;
      }
      local_f0 = 0x28;
      local_ec = uVar10 | 0xc0;
      local_e8 = param_2;
      iVar5 = (**(code **)(*DAT_140865b70 + 0x18))(DAT_140865b70,&local_f0,plVar1,0);
      if (iVar5 != 0) goto LAB_1401a26e2;
    }
LAB_1401a2600:
    uVar12 = 0;
  }
  else {
    if (param_5 == 0) {
      local_a8._2_2_ = (ushort)(uVar10 >> 0x10);
      bVar13 = local_a8._2_2_ == 1;
      if (bVar13) {
        local_a8 = CONCAT22(2,(short)uVar10);
        puVar8 = (undefined8 *)0x1;
        uStack_9c._2_2_ = (ushort)(uStack_9c >> 0x10);
        iVar5 = (int)((uint)uStack_9c._2_2_ * 2) >> 3;
        uStack_9c = CONCAT22(uStack_9c._2_2_,(short)iVar5);
        uStack_a0 = iVar5 * uStack_a4;
      }
LAB_1401a2476:
      *(uint *)(param_1 + 0x170) = local_a8 >> 0x10;
      if (param_4 == 0) {
        lVar6 = FUN_140184160(param_2,puVar8);
      }
      else {
        lVar6 = FUN_140186680(*(undefined8 *)(param_4 + 0x50));
      }
      *(longlong *)(param_1 + 0x50) = lVar6;
      if (lVar6 != 0) {
        puVar8 = operator_new(0x10);
        puVar7 = puVar11;
        if (puVar8 != (undefined8 *)0x0) {
          *puVar8 = DxLib::SOUNDBUFFER_CALLBACK::vftable;
          puVar7 = puVar8;
        }
        *(undefined8 **)(param_1 + 0x130) = puVar7;
        uVar4 = DAT_1404abe4c;
        if (puVar7 != (undefined8 *)0x0) {
          puVar7[1] = param_1;
          local_110 = (undefined4 *)0x0;
          if (DAT_140865b38 == 0) {
            if (param_5 == 0) {
              local_118 = (undefined4 *)0x0;
            }
            else {
              local_64 = DAT_140866820;
              local_58 = *plVar2;
              local_b4 = &local_68;
              local_118 = &local_b8;
              local_68 = 0x80;
              local_5c = 0x80;
              local_b8 = 2;
            }
            local_120 = *(ulonglong *)(param_1 + 0x130);
            local_128 = (undefined8 *)CONCAT44(local_128._4_4_,uVar4);
            iVar5 = (**(code **)(*DAT_140865b70 + 0x40))(DAT_140865b70,plVar1,&local_a8,0);
          }
          else {
            if (param_5 == 0) {
              local_118 = (undefined4 *)0x0;
            }
            else {
              local_7c = DAT_140866828;
              local_70 = *plVar2;
              local_c4 = &local_80;
              local_118 = &local_c8;
              local_80 = 0x80;
              local_74 = 0x80;
              local_c8 = 2;
            }
            local_120 = *(ulonglong *)(param_1 + 0x130);
            local_128 = (undefined8 *)CONCAT44(local_128._4_4_,uVar4);
            iVar5 = (**(code **)(*DAT_140865b70 + 0x28))();
          }
          if (-1 < iVar5) {
            if (param_4 != 0) {
              puVar9 = (undefined4 *)(param_4 + 8);
              do {
                FUN_14018eaa0(param_1,puVar11,*puVar9);
                uVar10 = (int)puVar11 + 1;
                puVar11 = (undefined8 *)(ulonglong)uVar10;
                puVar9 = puVar9 + 1;
              } while ((int)uVar10 < 8);
              FUN_14018e9c0(param_1,*(undefined4 *)(param_4 + 0x28));
              FUN_14018ea70(param_1,*(undefined4 *)(param_4 + 4));
            }
            goto LAB_1401a2600;
          }
        }
      }
    }
    else {
      if (DAT_140865b38 == 0) {
        if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
          (*DAT_140c2c018)(1);
        }
        local_128 = puVar7;
        iVar5 = (*DAT_140c2b900)(&DAT_1405729a8,0,1,&DAT_1405731a8);
      }
      else {
        iVar5 = (*DAT_140865b50)(puVar7);
      }
      if (-1 < iVar5) {
        local_110 = &local_100;
        local_90 = *puVar7;
        local_fc = &local_90;
        local_118 = (undefined4 *)0x0;
        local_88 = 1;
        local_84 = (uint)local_a8._2_2_;
        local_100 = 1;
        local_120 = local_120 & 0xffffffff00000000;
        local_128 = (undefined8 *)((ulonglong)local_128 & 0xffffffff00000000);
        if (DAT_140865b38 == 0) {
          iVar5 = (**(code **)(*DAT_140865b70 + 0x48))
                            (DAT_140865b70,plVar2,local_a8._2_2_,DAT_140844398);
          if (-1 < iVar5) {
            FUN_1401ae2f0(param_1 + 0x138,&DAT_140865b78,0x34);
            uVar12 = 0x34;
            goto LAB_1401a241f;
          }
        }
        else {
          iVar5 = (**(code **)(*DAT_140865b70 + 0x30))();
          if (-1 < iVar5) {
            FUN_1401ae2f0(param_1 + 0x138,&DAT_140866190,0x38);
            uVar12 = 0x38;
LAB_1401a241f:
            local_128 = (undefined8 *)((ulonglong)local_128 & 0xffffffff00000000);
            (**(code **)(*(longlong *)*plVar2 + 0x30))((longlong *)*plVar2,0,param_1 + 0x138,uVar12)
            ;
            (**(code **)(*(longlong *)*plVar2 + 0x20))((longlong *)*plVar2,0,0);
            puVar8 = puVar11;
            goto LAB_1401a2476;
          }
        }
      }
    }
LAB_1401a26e2:
    plVar3 = (longlong *)*plVar1;
    if (DAT_14086f310 == 0) {
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x10))();
        *plVar1 = 0;
      }
    }
    else {
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x90))();
        *plVar1 = 0;
      }
      if ((longlong *)*plVar2 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*plVar2 + 0x90))();
        *plVar2 = 0;
      }
      if (*(longlong *)(param_1 + 0x130) != 0) {
        thunk_FUN_140323ce8(*(longlong *)(param_1 + 0x130),0x10);
        *(undefined8 *)(param_1 + 0x130) = 0;
        return 0xffffffff;
      }
    }
    uVar12 = 0xffffffff;
  }
  return uVar12;
}


