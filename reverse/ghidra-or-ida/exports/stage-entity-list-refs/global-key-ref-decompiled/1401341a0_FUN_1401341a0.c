// Function: FUN_1401341a0 @ 1401341a0
// Decompile completed: true

undefined4 FUN_1401341a0(undefined8 param_1,undefined8 param_2,int param_3)

{
  float fVar1;
  longlong lVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 in_XMM0 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  float fVar16;
  float fVar17;
  undefined1 in_XMM1 [16];
  
  lVar2 = DAT_140e45d80;
  fVar11 = DAT_14053b02c;
  uVar7 = 0;
  fVar8 = in_XMM0._0_4_;
  fVar16 = in_XMM1._0_4_;
  iVar6 = FUN_1401340e0();
  fVar4 = DAT_140e445d8;
  fVar3 = DAT_14053ab70;
  uVar5 = 0;
  if (iVar6 != 0) {
    for (; uVar7 = uVar5, lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x60)) {
      auVar12._4_12_ = in_XMM0._4_12_;
      if (param_3 == 0) {
LAB_14013428e:
        fVar17 = *(float *)(lVar2 + 0x28);
        fVar1 = *(float *)(lVar2 + 0x2c);
        auVar12._0_4_ = fVar8 - fVar17;
        iVar6 = *(int *)(lVar2 + 0x50);
        fVar9 = (float)FUN_140334430(auVar12._0_8_);
        auVar13._4_12_ = in_XMM1._4_12_;
        auVar13._0_4_ = fVar16 - fVar1;
        fVar10 = (float)FUN_140334430(auVar13._0_8_);
        if (fVar9 + fVar10 < 0.0) {
          fVar9 = (float)FUN_1403352f8();
        }
        else {
          fVar9 = SQRT(fVar9 + fVar10);
        }
        if (((fVar9 - (float)iVar6 < fVar11) && (*(int *)(lVar2 + 0x54) == 0)) &&
           (*(int *)(lVar2 + 0x58) == 1)) {
          if (((fVar4 / fVar3 - (float)(iVar6 + 100) <= fVar17) &&
              (fVar17 <= (float)(iVar6 + 700) + fVar4 / fVar3)) &&
             (((float)-(iVar6 + 100) <= fVar1 && (fVar1 <= (float)(iVar6 + 0x334))))) {
            auVar14._0_4_ = fVar8 - fVar17;
            auVar14._4_12_ = auVar12._4_12_;
            fVar11 = (float)FUN_140334430(auVar14._0_8_);
            auVar15._0_4_ = fVar16 - fVar1;
            auVar15._4_12_ = auVar13._4_12_;
            fVar17 = (float)FUN_140334430(auVar15._0_8_);
            if (fVar11 + fVar17 < 0.0) {
              fVar11 = (float)FUN_1403352f8();
            }
            else {
              fVar11 = SQRT(fVar11 + fVar17);
            }
            uVar7 = *(undefined4 *)(lVar2 + 4);
            fVar11 = fVar11 - (float)iVar6;
          }
        }
      }
      else if ((param_3 == 1) &&
              (*(float *)(lVar2 + 0x2c) <= fVar16 && fVar16 != *(float *)(lVar2 + 0x2c))) {
        fVar17 = (float)(*(int *)(lVar2 + 0x50) + 0xb4);
        if ((*(float *)(lVar2 + 0x28) < fVar17 + fVar8) &&
           (fVar8 - fVar17 < *(float *)(lVar2 + 0x28))) goto LAB_14013428e;
      }
      uVar5 = uVar7;
    }
  }
  return uVar7;
}


