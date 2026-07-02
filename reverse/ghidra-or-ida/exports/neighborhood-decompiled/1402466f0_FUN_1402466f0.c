// Function: FUN_1402466f0 @ 1402466f0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_1402466f0(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_e8 [32];
  uint *local_c8;
  longlong *local_c0;
  longlong **local_b8;
  longlong *local_a8;
  longlong *local_a0;
  longlong local_98;
  undefined8 local_90;
  uint local_88;
  uint local_84 [3];
  ulonglong local_78;
  longlong local_70;
  longlong local_68;
  undefined2 local_60 [4];
  ulonglong local_58;
  undefined1 local_48 [16];
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_e8;
  local_84[0] = 0;
  local_a8 = (longlong *)0x0;
  local_a0 = (longlong *)0x0;
  local_88 = 0;
  local_90 = 0;
  if (*(int *)(param_1 + 0xb6) == *(int *)(param_1 + 0xb2)) {
    do {
      do {
        if (local_a8 != (longlong *)0x0) {
          (**(code **)(*local_a8 + 0x10))();
          local_a8 = (longlong *)0x0;
        }
        local_b8 = &local_a8;
        local_c0 = &local_68;
        local_c8 = local_84;
        iVar2 = (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x48))
                          (*(longlong **)(param_1 + 0x7a),0xfffffffd,0,0);
        if (iVar2 != 0) {
          if (*(longlong **)(param_1 + 0x7a) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x10))();
            *(undefined8 *)(param_1 + 0x7a) = 0;
          }
          if (*(longlong **)(param_1 + 0x82) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(param_1 + 0x82) + 0x10))();
            *(undefined8 *)(param_1 + 0x82) = 0;
          }
          if (*(longlong **)(param_1 + 0x8a) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(param_1 + 0x8a) + 0x10))();
            *(undefined8 *)(param_1 + 0x8a) = 0;
          }
          if (*(longlong **)(param_1 + 0x92) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(param_1 + 0x92) + 0x10))();
            *(undefined8 *)(param_1 + 0x92) = 0;
          }
          (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),0,2);
          uVar3 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x40));
          (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x40),0,0);
          lVar4 = FUN_140280220(param_1 + 0x10,uVar3);
          *(longlong *)(param_1 + 0x92) = lVar4;
          if (lVar4 == 0) goto LAB_140246aff;
          FUN_14027f8d0(lVar4);
          iVar2 = (*DAT_140c2bfe0)(*(undefined8 *)(param_1 + 0x92),0,param_1 + 0x7a);
          if (iVar2 != 0) goto LAB_140246aff;
          (*DAT_140c2bfa8)(param_1 + 0x8a);
          (**(code **)(**(longlong **)(param_1 + 0x8a) + 0xc0))
                    (*(longlong **)(param_1 + 0x8a),&DAT_140572aa8,&DAT_140572a08);
          (**(code **)(**(longlong **)(param_1 + 0x8a) + 0xc0))
                    (*(longlong **)(param_1 + 0x8a),&DAT_140572ab8,&DAT_140572c08);
          iVar2 = (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x38))
                            (*(longlong **)(param_1 + 0x7a),0xfffffffd,0);
          if (((iVar2 != 0) ||
              (iVar2 = (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x30))
                                 (*(longlong **)(param_1 + 0x7a),0xfffffffd,param_1 + 0x82),
              iVar2 != 0)) ||
             (iVar2 = (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x20))
                                (*(longlong **)(param_1 + 0x7a),0xfffffffd,1), iVar2 != 0))
          goto LAB_140246aff;
          local_98 = 0;
          local_84[1] = 0;
          iVar2 = (*DAT_140c2bfb0)(*(undefined8 *)(param_1 + 0x82),&local_98,local_84 + 1);
          if (iVar2 != 0) goto LAB_140246aff;
          if (local_98 != 0) {
            (*DAT_140c2b910)();
            local_98 = 0;
          }
          FUN_1401ae370(local_60,0,0x18);
          local_60[0] = 0x14;
          local_58 = (((ulonglong)(*(longlong *)(param_1 + 0x4a0) + *(longlong *)(param_1 + 0x490))
                      / (ulonglong)*(ushort *)(param_1 + 0x74)) * 10000000) /
                     (ulonglong)*(uint *)(param_1 + 0x6c);
          (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x40))
                    (*(longlong **)(param_1 + 0x7a),&DAT_140ca5418);
          local_b8 = &local_a8;
          local_c0 = &local_68;
          local_c8 = local_84;
          iVar2 = (**(code **)(**(longlong **)(param_1 + 0x7a) + 0x48))
                            (*(longlong **)(param_1 + 0x7a),0xfffffffd);
          if (iVar2 != 0) goto LAB_140246aff;
        }
      } while ((local_84[0] & 0x20) != 0);
      if (((local_84[0] & 2) != 0) || (local_a8 == (longlong *)0x0)) goto LAB_140246aff;
      local_70 = local_68;
      local_78 = (ulonglong)*(uint *)(param_1 + 0x70);
      FUN_1401ae3b0(&local_70,&local_78,local_48);
      local_78 = 10000000;
      FUN_1401adf90(local_48,&local_78);
    } while (local_70 < *(longlong *)(param_1 + 0x4a0));
    iVar2 = (**(code **)(*local_a8 + 0x148))(local_a8,&local_a0);
    if (((iVar2 == 0) &&
        (iVar2 = (**(code **)(*local_a0 + 0x18))(local_a0,&local_90,0,&local_88), iVar2 == 0)) &&
       (local_88 != 0)) {
      if (*(uint *)(param_1 + 0xa2) < local_88) {
        FUN_1401b6700(*(undefined8 *)(param_1 + 0xaa));
        *(undefined8 *)(param_1 + 0xaa) = 0;
        *(uint *)(param_1 + 0xa2) = local_88 + 0x1000;
        lVar4 = FUN_1401b6390(local_88 + 0x1000,
                              "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                              ,0x6ce);
        *(longlong *)(param_1 + 0xaa) = lVar4;
        if (lVar4 == 0) goto LAB_140246aff;
      }
      FUN_1401ae2f0(*(undefined8 *)(param_1 + 0xaa),local_90,local_88);
      *(undefined4 *)(param_1 + 0xb2) = 0;
      *(uint *)(param_1 + 0xb6) = local_88;
      iVar2 = (**(code **)(*local_a0 + 0x20))();
      if (iVar2 == 0) goto LAB_140246b2c;
    }
LAB_140246aff:
    if (local_a0 != (longlong *)0x0) {
      (**(code **)(*local_a0 + 0x10))(local_a0);
      local_a0 = (longlong *)0x0;
    }
    if (local_a8 != (longlong *)0x0) {
      (**(code **)(*local_a8 + 0x10))();
    }
    uVar3 = 0xffffffff;
  }
  else {
LAB_140246b2c:
    uVar1 = *(ushort *)(param_1 + 0x74);
    uVar5 = *(int *)(param_1 + 0xb6) - *(uint *)(param_1 + 0xb2);
    if (*(uint *)(param_1 + 0x488) < uVar5) {
      uVar5 = *(uint *)(param_1 + 0x488);
    }
    uVar5 = (((uVar1 - 1) + uVar5) / (uint)uVar1) * (uint)uVar1;
    FUN_1401ae2f0(*(undefined8 *)(param_1 + 0x480),
                  (ulonglong)*(uint *)(param_1 + 0xb2) + *(longlong *)(param_1 + 0xaa),uVar5);
    *(int *)(param_1 + 0xb2) = *(int *)(param_1 + 0xb2) + uVar5;
    *(ulonglong *)(param_1 + 0x490) = (ulonglong)uVar5;
    if (local_a0 != (longlong *)0x0) {
      (**(code **)(*local_a0 + 0x10))();
      local_a0 = (longlong *)0x0;
    }
    if (local_a8 != (longlong *)0x0) {
      (**(code **)(*local_a8 + 0x10))();
    }
    uVar3 = 0;
  }
  return uVar3;
}


