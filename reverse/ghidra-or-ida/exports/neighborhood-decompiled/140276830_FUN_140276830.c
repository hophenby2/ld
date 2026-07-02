// Function: FUN_140276830 @ 140276830
// Decompile completed: true

undefined8 *
FUN_140276830(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,longlong param_6,undefined4 param_7)

{
  undefined1 auVar1 [16];
  int iVar2;
  __uint64 _Var3;
  void *pvVar4;
  ulonglong uVar5;
  
  *param_1 = D_INonDelegatingUnknown::vftable;
  LOCK();
  DAT_140e2f588 = DAT_140e2f588 + 1;
  UNLOCK();
  param_1[1] = param_1;
  *(undefined4 *)(param_1 + 2) = 0;
  param_1[3] = D_IPin::vftable;
  param_1[4] = D_IQualityControl::vftable;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined4 *)(param_1 + 7) = param_7;
  param_1[8] = param_4;
  *(undefined2 *)(param_1 + 9) = 0;
  *(undefined1 *)((longlong)param_1 + 0x4a) = 0;
  param_1[10] = param_3;
  param_1[0xb] = 0;
  *(undefined4 *)(param_1 + 0xc) = 1;
  FUN_1401ae370(param_1 + 0xd,0,0x58,param_4,0xfffffffffffffffe);
  *(undefined4 *)(param_1 + 0x12) = 1;
  *(undefined4 *)(param_1 + 0x11) = 1;
  param_1[0x18] = 0;
  param_1[0x19] = 0x7fffffffffffffff;
  param_1[0x1a] = 0x3ff0000000000000;
  if (DAT_140c2b470 == 0) {
    FUN_1401e6080();
    if (DAT_140c2c018 != (code *)0x0) {
      (*DAT_140c2c018)(1);
    }
  }
  if (param_6 != 0) {
    iVar2 = FUN_1401eb240(param_6);
    uVar5 = CONCAT44(0,iVar2 + 1);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar5;
    _Var3 = SUB168(ZEXT816(2) * auVar1,0);
    if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
      _Var3 = 0xffffffffffffffff;
    }
    pvVar4 = operator_new(_Var3);
    param_1[5] = pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_1401ae2f0(pvVar4,param_6,uVar5 * 2);
    }
  }
  return param_1;
}


