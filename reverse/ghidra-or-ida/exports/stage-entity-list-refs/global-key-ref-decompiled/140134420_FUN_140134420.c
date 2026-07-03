// Function: FUN_140134420 @ 140134420
// Decompile completed: true

ulonglong FUN_140134420(undefined8 param_1,undefined8 param_2,ushort param_3)

{
  float fVar1;
  float fVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  ulonglong uVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  undefined4 in_XMM0_Dc;
  undefined4 in_XMM0_Dd;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 in_XMM1 [16];
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  
  lVar3 = DAT_140e45d80;
  fVar5 = DAT_140e445d8;
  fVar17 = DAT_14053b438;
  fVar15 = DAT_14053b02c;
  uVar14 = (undefined4)((ulonglong)param_1 >> 0x20);
  auVar11._0_4_ = (float)param_1;
  uVar7 = (ulonglong)param_3;
  iVar6 = FUN_1401340e0();
  fVar4 = DAT_14053ab70;
  fVar16 = fVar5;
  if (iVar6 == 0) {
    uVar7 = uVar7 & 0xffff;
  }
  else {
    for (; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x60)) {
      fVar1 = *(float *)(lVar3 + 0x28);
      auVar11._4_4_ = uVar14;
      auVar11._8_4_ = in_XMM0_Dc;
      auVar11._12_4_ = in_XMM0_Dd;
      fVar2 = *(float *)(lVar3 + 0x2c);
      auVar12._4_12_ = auVar11._4_12_;
      auVar12._0_4_ = auVar11._0_4_ - fVar1;
      iVar6 = *(int *)(lVar3 + 0x50);
      fVar8 = (float)FUN_140334430(auVar12._0_8_);
      auVar13._4_12_ = in_XMM1._4_12_;
      auVar13._0_4_ = in_XMM1._0_4_ - fVar2;
      fVar9 = (float)FUN_140334430(auVar13._0_8_);
      if (fVar8 + fVar9 < 0.0) {
        fVar8 = (float)FUN_1403352f8();
      }
      else {
        fVar8 = SQRT(fVar8 + fVar9);
      }
      if (((fVar8 - (float)iVar6 < fVar15) && (*(int *)(lVar3 + 0x54) == 0)) &&
         (*(int *)(lVar3 + 0x58) == 1)) {
        fVar9 = fVar5 / fVar4;
        if (((fVar9 - (float)(iVar6 + 100) <= fVar1) && (fVar1 <= (float)(iVar6 + 700) + fVar9)) &&
           (((float)-(iVar6 + 100) <= fVar2 && (fVar2 <= (float)(iVar6 + 0x334))))) {
          fVar15 = fVar8 - (float)iVar6;
          fVar16 = fVar1;
          fVar17 = fVar2;
        }
      }
      uVar14 = 0;
      in_XMM0_Dc = 0;
      in_XMM0_Dd = 0;
    }
    dVar10 = (double)FUN_1403300b4((double)(fVar17 - in_XMM1._0_4_),(double)(fVar16 - auVar11._0_4_)
                                  );
    uVar7 = (ulonglong)(uint)(int)(dVar10 * DAT_14053aba0);
  }
  return uVar7;
}


