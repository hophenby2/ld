// Function: FUN_1400c9c90 @ 1400c9c90
// Decompile completed: true

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_1400c9c90(int param_1,undefined4 param_2,uint param_3,float param_4,undefined4 param_5,
                  double param_6,undefined8 param_7)

{
  int iVar1;
  double dVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  ulonglong in_stack_ffffffffffffff00;
  double dVar13;
  uint6 uVar14;
  
  uVar3 = param_7;
  dVar2 = param_6;
  fVar12 = (float)param_6 * DAT_14053acb0;
  fVar11 = (float)param_6 * DAT_14053ac48;
  param_6._4_4_ = fVar12;
  param_6._0_4_ = fVar11;
  if ((int)param_3 < 0xe10) {
    if ((int)param_3 < 0x3c) goto LAB_1400ca3dc;
LAB_1400ca020:
    uVar4 = (int)param_3 / 0x3c;
    uVar7 = (ulonglong)(int)uVar4;
    param_3 = (int)param_3 % 0x3c;
    if (param_1 != 0) {
      if (param_1 != 1) goto LAB_1400ca3dc;
      goto LAB_1400ca130;
    }
LAB_1400ca04a:
    fVar12 = DAT_14053aa20;
    dVar13 = dVar2;
    FUN_1400c95e0(0,param_2,uVar7,fVar11 * DAT_14053aa20 + param_4,param_5,dVar2,uVar3,0xff,0,0);
    if ((int)uVar4 < 10) {
      dVar13 = (double)((ulonglong)dVar13 & 0xffffffffffff0000);
      FUN_1400c8410(DAT_140e41980,param_2,1,fVar11 * DAT_14053a770 + param_4,param_5,dVar13,dVar2,
                    uVar3,0xff,0xff,0xff,0xff,1,0);
    }
    fVar12 = fVar11 * DAT_14053ab70 + param_4 + fVar12;
    uVar5 = DAT_140e419a8;
  }
  else {
    uVar4 = param_3 / 0xe10;
    param_3 = param_3 % 0xe10;
    if (99 < uVar4) {
      uVar4 = 99;
    }
    uVar7 = (ulonglong)(int)uVar4;
    if (param_1 == 0) {
      dVar13 = dVar2;
      FUN_1400c95e0(0,param_2,uVar7,fVar11 + fVar11 + param_4,param_5,dVar2,param_7,0xff,0,0);
      FUN_1400c8410(DAT_140e419b4,param_2,1,fVar11 * DAT_14053a2e8 + param_4,param_5,
                    (ulonglong)dVar13 & 0xffffffffffff0000,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
      uVar4 = param_3 / 0x3c;
      uVar7 = (ulonglong)(int)uVar4;
      param_3 = param_3 % 0x3c;
      goto LAB_1400ca04a;
    }
    if (param_1 != 1) goto LAB_1400ca020;
    fVar9 = fVar12 + fVar12 + param_4;
    uVar6 = in_stack_ffffffffffffff00 & 0xffffffffffff0000;
    if (uVar7 < 10) {
      FUN_1400c8410((&DAT_140e46bf8)[uVar7],param_2,1,fVar9,param_5,uVar6,dVar2,param_7,0xff,0xff,
                    0xff,0xff,1,0);
    }
    else {
      FUN_1400c8410((&DAT_140e46bf8)[(int)(uVar4 + (int)(uVar7 / 10) * -10)],param_2,1,fVar9,param_5
                    ,uVar6,dVar2,param_7,0xff,0xff,0xff,0xff,1,0);
      uVar7 = uVar7 / 10;
      do {
        fVar9 = fVar9 - fVar12;
        uVar6 = uVar6 & 0xffffffffffff0000;
        FUN_1400c8410((&DAT_140e46bf8)[(int)uVar7 + (int)(uVar7 / 10) * -10],param_2,1,fVar9,param_5
                      ,uVar6,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
        bVar8 = 9 < uVar7;
        uVar7 = uVar7 / 10;
      } while (bVar8);
    }
    in_stack_ffffffffffffff00 = uVar6 & 0xffffffffffff0000;
    FUN_1400c8410(DAT_140e46c2c,param_2,1,fVar12 * DAT_14053a2e8 + param_4,param_5,
                  in_stack_ffffffffffffff00,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
    uVar4 = param_3 / 0x3c;
    uVar7 = (ulonglong)(int)uVar4;
    param_3 = param_3 % 0x3c;
LAB_1400ca130:
    fVar9 = *(float *)((longlong)&param_6 + (longlong)param_1 * 4);
    fVar10 = fVar9 * DAT_14053aa20 + param_4;
    uVar14 = (uint6)(in_stack_ffffffffffffff00 >> 0x10);
    uVar6 = uVar7;
    if (uVar7 == 0) {
LAB_1400ca290:
      dVar13 = (double)((ulonglong)uVar14 << 0x10);
      FUN_1400c8410((&DAT_140e46bf8)[uVar7],param_2,1,fVar10,param_5,dVar13,dVar2,uVar3,0xff,0xff,
                    0xff,0xff,1,0);
    }
    else {
      do {
        uVar6 = uVar6 / 10;
      } while (uVar6 != 0);
      if (uVar7 < 10) goto LAB_1400ca290;
      dVar13 = (double)((ulonglong)uVar14 << 0x10);
      FUN_1400c8410((&DAT_140e46bf8)[(int)uVar7 + (int)(uVar7 / 10) * -10],param_2,1,fVar10,param_5,
                    dVar13,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
      uVar7 = uVar7 / 10;
      do {
        fVar10 = fVar10 - fVar12;
        dVar13 = (double)((ulonglong)dVar13 & 0xffffffffffff0000);
        FUN_1400c8410((&DAT_140e46bf8)[(int)uVar7 + (int)(uVar7 / 10) * -10],param_2,1,fVar10,
                      param_5,dVar13,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
        bVar8 = 9 < uVar7;
        uVar7 = uVar7 / 10;
      } while (bVar8);
    }
    if ((int)uVar4 < 10) {
      dVar13 = (double)((ulonglong)dVar13 & 0xffffffffffff0000);
      FUN_1400c8410(DAT_140e46bf8,param_2,1,fVar9 * DAT_14053a770 + param_4,param_5,dVar13,dVar2,
                    uVar3,0xff,0xff,0xff,0xff,1,0);
    }
    fVar12 = fVar9 * DAT_14053ab70 + param_4 + DAT_14053aa20;
    uVar5 = DAT_140e46c20;
  }
  in_stack_ffffffffffffff00 = (ulonglong)dVar13 & 0xffffffffffff0000;
  FUN_1400c8410(uVar5,param_2,1,fVar12,param_5,in_stack_ffffffffffffff00,dVar2,uVar3,0xff,0xff,0xff,
                0xff,1,0);
LAB_1400ca3dc:
  iVar1 = (int)((double)(int)param_3 * DAT_140539fb0);
  if (99 < (int)((double)(int)param_3 * DAT_140539fb0)) {
    iVar1 = 99;
  }
  uVar14 = (uint6)(in_stack_ffffffffffffff00 >> 0x10);
  if (param_1 == 0) {
    if (iVar1 < 10) {
      FUN_1400c8410(DAT_140e41980,param_2,1,fVar11 * DAT_14053abf8 + param_4,param_5,
                    (ulonglong)uVar14 << 0x10,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
    }
    FUN_1400c95e0(0,param_2,(longlong)iVar1,param_6._0_4_ * DAT_14053ac18 + param_4,param_5,dVar2,
                  uVar3,0xff,0,0);
  }
  else {
    uVar7 = (ulonglong)iVar1;
    if (param_1 == 1) {
      if (iVar1 < 10) {
        in_stack_ffffffffffffff00 = (ulonglong)uVar14 << 0x10;
        FUN_1400c8410(DAT_140e46bf8,param_2,1,param_6._4_4_ * DAT_14053abf8 + param_4,param_5,
                      in_stack_ffffffffffffff00,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
      }
      param_4 = param_6._4_4_ * DAT_14053ac18 + param_4;
      uVar6 = in_stack_ffffffffffffff00 & 0xffffffffffff0000;
      fVar11 = (float)dVar2 * DAT_14053acb0;
      if (uVar7 < 10) {
        FUN_1400c8410((&DAT_140e46bf8)[uVar7],param_2,1,param_4,param_5,uVar6,dVar2,uVar3,0xff,0xff,
                      0xff,0xff,1,0);
      }
      else {
        FUN_1400c8410((&DAT_140e46bf8)[iVar1 + (int)(uVar7 / 10) * -10],param_2,1,param_4,param_5,
                      uVar6,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
        uVar7 = uVar7 / 10;
        do {
          param_4 = param_4 - fVar11;
          uVar6 = uVar6 & 0xffffffffffff0000;
          FUN_1400c8410((&DAT_140e46bf8)[(int)uVar7 + (int)(uVar7 / 10) * -10],param_2,1,param_4,
                        param_5,uVar6,dVar2,uVar3,0xff,0xff,0xff,0xff,1,0);
          bVar8 = 9 < uVar7;
          uVar7 = uVar7 / 10;
        } while (bVar8);
      }
    }
  }
  return;
}


