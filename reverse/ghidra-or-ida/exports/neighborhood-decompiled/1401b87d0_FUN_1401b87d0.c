// Function: FUN_1401b87d0 @ 1401b87d0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401b87d0(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = DAT_1407c6b00 ^ (ulonglong)auStack_78;
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
LAB_1401b8820:
  while( true ) {
    if (*(longlong *)(param_1 + 0xc58) == 0) goto LAB_1401b88f8;
    iVar2 = (*DAT_140c2b6b0)();
    if ((iVar2 != 0x102) || (lVar5 = *(longlong *)(param_1 + 0x10), lVar5 == 0)) break;
    if (*(longlong *)(param_1 + 0xc68) != 0x20000) {
      uVar3 = *(longlong *)(param_1 + 0xc60) + *(longlong *)(param_1 + 0xc68);
      if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
        (*DAT_140c2c018)(1);
      }
      local_38 = (undefined4)(uVar3 >> 0x20);
      iVar2 = (*DAT_140c2b7f8)(lVar5,uVar3 & 0xffffffff,&local_38,0);
      if (iVar2 == -1) {
        (*DAT_140c2b8e8)();
      }
      local_58 = 0;
      (*DAT_140c2b7f0)(*(undefined8 *)(param_1 + 0x10),
                       *(longlong *)(param_1 + 0xc58) + *(longlong *)(param_1 + 0xc68),
                       0x20000 - *(int *)(param_1 + 0xc68));
      *(longlong *)(param_1 + 0xc68) = *(longlong *)(param_1 + 0xc68) + (ulonglong)local_34;
    }
  }
  goto LAB_1401b8912;
LAB_1401b88f8:
  iVar2 = (*DAT_140c2b6b0)(*(undefined8 *)(param_1 + 0x18),0xffffffff);
  if ((iVar2 != 0x102) || (*(longlong *)(param_1 + 0x10) == 0)) {
LAB_1401b8912:
    (*DAT_140c2b660)(*(undefined8 *)(param_1 + 0x18));
    (*DAT_140c2b660)(*(undefined8 *)(param_1 + 0x20));
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar2 == 0) {
      local_48 = 0;
      local_50 = 0x80;
      local_58 = CONCAT44(local_58._4_4_,3);
      lVar5 = FUN_1401e3960(param_1 + 0x34,0x80000000,1);
      *(longlong *)(param_1 + 0x10) = lVar5;
      if (lVar5 == -1) {
        *(undefined4 *)(param_1 + 0x30) = 1;
        goto LAB_1401b8b94;
      }
    }
    else {
      if (iVar2 == 1) {
        (*DAT_140c2b798)(*(undefined8 *)(param_1 + 0x10));
        *(undefined8 *)(param_1 + 0x10) = 0;
        (*DAT_140c2b658)(*(undefined8 *)(param_1 + 0x20));
        goto LAB_1401b8820;
      }
      if (iVar2 == 2) {
        if (((*(longlong *)(param_1 + 0xc58) != 0) &&
            (*(longlong *)(param_1 + 0xc40) == *(longlong *)(param_1 + 0xc60))) &&
           (uVar3 = *(ulonglong *)(param_1 + 0xc68), uVar3 != 0)) {
          uVar4 = *(uint *)(param_1 + 0xc48);
          if (uVar3 < uVar4) {
            uVar4 = (uint)uVar3;
          }
          uVar3 = (ulonglong)uVar4;
          FUN_1401ae2f0(*(undefined8 *)(param_1 + 0xc38),*(longlong *)(param_1 + 0xc58),uVar4);
          *(longlong *)(param_1 + 0xc38) = *(longlong *)(param_1 + 0xc38) + uVar3;
          *(longlong *)(param_1 + 0xc40) = *(longlong *)(param_1 + 0xc40) + uVar3;
          *(int *)(param_1 + 0xc48) = *(int *)(param_1 + 0xc48) - uVar4;
          *(longlong *)(param_1 + 0xc60) = *(longlong *)(param_1 + 0xc60) + uVar3;
          lVar5 = *(longlong *)(param_1 + 0xc68) - uVar3;
          *(longlong *)(param_1 + 0xc68) = lVar5;
          if (lVar5 != 0) {
            FUN_1401ae320();
          }
        }
        if (*(int *)(param_1 + 0xc48) != 0) {
          uVar3 = *(ulonglong *)(param_1 + 0xc40);
          uVar1 = *(undefined8 *)(param_1 + 0x10);
          if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
            (*DAT_140c2c018)(1);
          }
          local_2c = (undefined4)(uVar3 >> 0x20);
          iVar2 = (*DAT_140c2b7f8)(uVar1,uVar3 & 0xffffffff,&local_2c,0);
          if (iVar2 == -1) {
            (*DAT_140c2b8e8)();
          }
          local_58 = 0;
          (*DAT_140c2b7f0)(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0xc38),
                           *(undefined4 *)(param_1 + 0xc48));
          if (*(longlong *)(param_1 + 0xc58) != 0) {
            *(ulonglong *)(param_1 + 0xc60) =
                 (ulonglong)*(uint *)(param_1 + 0xc48) + *(longlong *)(param_1 + 0xc40);
            *(undefined8 *)(param_1 + 0xc68) = 0;
            (*DAT_140c2b658)(*(undefined8 *)(param_1 + 0x20));
            goto LAB_1401b8820;
          }
        }
      }
      else if (iVar2 == 3) {
        uVar3 = *(ulonglong *)(param_1 + 0xc50);
        uVar1 = *(undefined8 *)(param_1 + 0x10);
        if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
          (*DAT_140c2c018)(1);
        }
        local_30 = (undefined4)(uVar3 >> 0x20);
        iVar2 = (*DAT_140c2b7f8)(uVar1,uVar3 & 0xffffffff,&local_30);
        if (iVar2 == -1) {
          (*DAT_140c2b8e8)();
        }
        if (*(longlong *)(param_1 + 0xc58) != 0) {
          *(ulonglong *)(param_1 + 0xc60) = (ulonglong)*(uint *)(param_1 + 0xc50);
          *(undefined8 *)(param_1 + 0xc68) = 0;
          (*DAT_140c2b658)(*(undefined8 *)(param_1 + 0x20));
          goto LAB_1401b8820;
        }
      }
      else if (iVar2 == 4) {
        if (*(longlong *)(param_1 + 0x10) != 0) {
          (*DAT_140c2b798)();
        }
        *(undefined8 *)(param_1 + 0x10) = 0;
LAB_1401b8b94:
        (*DAT_140c2b658)(*(undefined8 *)(param_1 + 0x20));
        *(undefined4 *)(param_1 + 0x2c) = 1;
        (*DAT_140c2b680)(1);
        return 0;
      }
    }
    (*DAT_140c2b658)(*(undefined8 *)(param_1 + 0x20));
  }
  goto LAB_1401b8820;
}


