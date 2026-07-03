// Function: FUN_1400fe940 @ 1400fe940
// Decompile completed: true

void FUN_1400fe940(int param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  uint uVar7;
  undefined1 in_stack_ffffffffffffff98 [16];
  undefined1 auVar8 [16];
  
  iVar2 = DAT_140e418c8;
  iVar4 = (int)param_2;
  if (DAT_140e418c8 < iVar4) {
    return;
  }
  param_3 = iVar4 + param_3;
  if (param_3 <= DAT_140e418c8) {
    return;
  }
  iVar5 = iVar4 + 0x20;
  auVar8._4_12_ = in_stack_ffffffffffffff98._4_12_;
  auVar8._0_4_ = 0xff;
  uVar7 = 0;
  uVar3 = FUN_1401348b0(DAT_140e418c8,param_2,iVar5,param_3 + -0x20,param_3,0,auVar8);
  dVar6 = DAT_14053a018;
  if (iVar4 != iVar5) {
    if (iVar2 < iVar4) {
      if (iVar2 < iVar5) goto LAB_1400fea0c;
    }
    else if (iVar2 < iVar5) {
      dVar6 = (double)FUN_140332d90(SUB84(((double)iVar2 - (double)(iVar4 * 2 - iVar5)) *
                                          DAT_14053a778 * DAT_14053a020 * DAT_140539d28,0));
      dVar6 = dVar6 + dVar6 + DAT_140539f40;
      goto LAB_1400fea0c;
    }
    dVar6 = DAT_140539f40;
  }
LAB_1400fea0c:
  auVar1._8_4_ = SUB84(dVar6,0);
  auVar1._0_8_ = dVar6;
  auVar1._12_4_ = (int)((ulonglong)dVar6 >> 0x20);
  FUN_1400c8410(*(undefined4 *)(&DAT_140e476d0 + (longlong)param_1 * 4),0x65,1,param_4,param_5,
                uVar7 & 0xffff0000,auVar1,0xff,0xff,0xff,uVar3,1,0);
  return;
}


