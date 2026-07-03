// Function: FUN_140332d90 @ 140332d90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_140332d90(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  ulonglong uVar15;
  double dVar16;
  uint uVar17;
  uint uVar18;
  double dVar19;
  double extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_01;
  undefined1 auVar20 [16];
  undefined1 in_ZMM0 [64];
  undefined1 extraout_var_00 [56];
  double dVar23;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 in_ZMM1 [64];
  double dVar27;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  double dVar34;
  double dVar35;
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined8 extraout_XMM0_Qa_00;
  undefined1 auVar21 [64];
  undefined1 auVar22 [64];
  undefined1 extraout_var [56];
  
  dVar19 = in_ZMM0._0_8_;
  if (DAT_140e309d0 == 0) {
    dVar16 = ABS(dVar19);
    if ((ulonglong)dVar16 < (ulonglong)DAT_1405272c8) {
      if ((longlong)dVar16 <= DAT_1405272b8) {
        return dVar19;
      }
      dVar16 = dVar19 * dVar19;
      dVar19 = dVar19 + dVar19 * dVar16 *
                        (((DAT_140529bd0 * dVar16 + DAT_140529bc0) * dVar16 + DAT_140529bb0) *
                         dVar16 * dVar16 * dVar16 +
                        (DAT_140529ba0 * dVar16 + DAT_140529b90) * dVar16 + DAT_140529b80);
    }
    else {
      if ((ulonglong)dVar16 < (ulonglong)DAT_1405272d0) {
        uVar18 = (uint)(dVar16 * _DAT_1405272a0 + DAT_1405272a8);
        dVar27 = (double)(int)uVar18;
        dVar34 = dVar16 - DAT_140527210 * dVar27;
        dVar23 = DAT_140527220 * dVar27;
        dVar19 = dVar34 - dVar23;
        dVar35 = dVar34;
        if (0xf < (longlong)(((ulonglong)dVar16 >> 0x34) - ((ulonglong)ABS(dVar19) >> 0x34))) {
          dVar35 = dVar34 - DAT_140527230 * dVar27;
          dVar23 = DAT_140527240 * dVar27 - ((dVar34 - dVar35) - DAT_140527230 * dVar27);
          dVar19 = dVar35 - dVar23;
        }
        dVar23 = (dVar35 - dVar19) - dVar23;
      }
      else {
        if ((ulonglong)DAT_1405272e0 <= (ulonglong)dVar16) {
          dVar19 = (double)FUN_1403403b0();
          return dVar19;
        }
        uVar18 = FUN_14033fdd0();
        dVar23 = in_ZMM1._0_8_;
        dVar19 = extraout_XMM0_Qa;
      }
      dVar16 = dVar19 * dVar19;
      if ((uVar18 & 1) == 0) {
        dVar19 = dVar23 + (dVar19 * dVar16 *
                           (((DAT_140529bd0 * dVar16 + DAT_140529bc0) * dVar16 + DAT_140529bb0) *
                            dVar16 * dVar16 * dVar16 +
                           (DAT_140529ba0 * dVar16 + DAT_140529b90) * dVar16 + DAT_140529b80) -
                          dVar16 * DAT_1405272a8 * dVar23) + dVar19;
      }
      else {
        dVar19 = (((DAT_140529b40 * dVar16 + DAT_140529b30) * dVar16 + DAT_140529b20 +
                  ((DAT_140529b70 * dVar16 + DAT_140529b60) * dVar16 + DAT_140529b50) *
                  dVar16 * dVar16 * dVar16) * dVar16 * dVar16 +
                 ((((DAT_1405272a8 * dVar16 - DAT_140527250) + DAT_140527250) -
                  dVar16 * DAT_1405272a8) - dVar23 * dVar19)) -
                 (dVar16 * DAT_1405272a8 - DAT_140527250);
      }
      uVar17 = in_ZMM0._4_4_ >> 0x1f;
      if ((uVar18 >> 1 & uVar17) == 0 && (~(uVar18 >> 1) & ~uVar17 & 1) == 0) {
        dVar19 = 0.0 - dVar19;
      }
    }
    return dVar19;
  }
  dVar16 = ABS(dVar19);
  if ((ulonglong)DAT_1405272c8 <= (ulonglong)dVar16) {
    if ((ulonglong)dVar16 < (ulonglong)DAT_1405272e0) {
      if ((ulonglong)dVar16 < (ulonglong)DAT_1405272d8) {
        uVar18 = FUN_140340310(dVar16);
        auVar25 = in_ZMM1._0_16_;
        auVar21._8_56_ = extraout_var;
        auVar21._0_8_ = extraout_XMM0_Qa_00;
        auVar20 = auVar21._0_16_;
      }
      else {
        uVar18 = FUN_140340120();
        auVar25 = in_ZMM1._0_16_;
        auVar22._8_56_ = extraout_var_00;
        auVar22._0_8_ = extraout_XMM0_Qa_01;
        auVar20 = auVar22._0_16_;
      }
      dVar16 = auVar20._0_8_;
      dVar23 = dVar16 * dVar16;
      auVar32._8_8_ = 0;
      auVar32._0_8_ = dVar23;
      if ((uVar18 & 1) == 0) {
        auVar39._8_8_ = 0;
        auVar39._0_8_ = DAT_140529bd0;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = DAT_140529bc0;
        auVar20 = vfmadd213sd_fma(auVar39,auVar32,auVar7);
        auVar8._8_8_ = 0;
        auVar8._0_8_ = DAT_140529bb0;
        auVar33._8_8_ = 0;
        auVar33._0_8_ = dVar23;
        auVar20 = vfmadd213sd_fma(auVar20,auVar33,auVar8);
        auVar9._8_8_ = 0;
        auVar9._0_8_ = DAT_140529ba0;
        auVar20 = vfmadd213sd_fma(auVar20,auVar33,auVar9);
        auVar10._8_8_ = 0;
        auVar10._0_8_ = DAT_140529b90;
        auVar20 = vfmadd213sd_fma(auVar20,auVar33,auVar10);
        auVar11._8_8_ = 0;
        auVar11._0_8_ = DAT_140529b80;
        auVar28._8_8_ = 0;
        auVar28._0_8_ =
             dVar23 * (auVar25._0_8_ * DAT_1405272a8 - dVar16 * dVar23 * auVar20._0_8_) -
             auVar25._0_8_;
        auVar37._8_8_ = 0;
        auVar37._0_8_ = dVar16 * dVar23;
        auVar20 = vfnmadd231sd_fma(auVar28,auVar37,auVar11);
        dVar16 = dVar16 - auVar20._0_8_;
      }
      else {
        dVar16 = DAT_140527250 - dVar23 * DAT_1405272a8;
        auVar40._8_8_ = 0;
        auVar40._0_8_ = DAT_140529b70;
        auVar29._8_8_ = 0;
        auVar29._0_8_ = (DAT_140527250 - dVar16) - dVar23 * DAT_1405272a8;
        auVar29 = vfnmadd231sd_fma(auVar29,auVar20,auVar25);
        auVar20._8_8_ = 0;
        auVar20._0_8_ = DAT_140529b60;
        auVar20 = vfmadd213sd_fma(auVar40,auVar32,auVar20);
        auVar25._8_8_ = 0;
        auVar25._0_8_ = DAT_140529b50;
        auVar20 = vfmadd213sd_fma(auVar20,auVar32,auVar25);
        auVar12._8_8_ = 0;
        auVar12._0_8_ = DAT_140529b40;
        auVar20 = vfmadd213sd_fma(auVar20,auVar32,auVar12);
        auVar13._8_8_ = 0;
        auVar13._0_8_ = DAT_140529b30;
        auVar20 = vfmadd213sd_fma(auVar20,auVar32,auVar13);
        auVar14._8_8_ = 0;
        auVar14._0_8_ = DAT_140529b20;
        auVar20 = vfmadd213sd_fma(auVar20,auVar32,auVar14);
        auVar26._8_8_ = 0;
        auVar26._0_8_ = dVar23 * dVar23;
        auVar20 = vfmadd213sd_fma(auVar20,auVar26,auVar29);
        dVar16 = auVar20._0_8_ + dVar16;
      }
      uVar15 = 0;
      if ((uVar18 >> 1 & 1) != 0) {
        uVar15 = DAT_140527260;
      }
      return (double)((ulonglong)dVar16 ^ uVar15 ^ (ulonglong)dVar19 & DAT_140527260);
    }
    dVar19 = (double)FUN_1403403b0();
    return dVar19;
  }
  if ((longlong)dVar16 < DAT_1405272c0) {
    if ((longlong)dVar16 < DAT_1405272b8) {
      return dVar19;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = DAT_1405272b0;
    auVar24._8_8_ = 0;
    auVar24._0_8_ = dVar19 * dVar19 * dVar19;
    auVar20 = vfnmadd231sd_fma(in_ZMM0._0_16_,auVar24,auVar1);
    return auVar20._0_8_;
  }
  auVar38._8_8_ = 0;
  auVar38._0_8_ = DAT_140529bd0;
  dVar16 = dVar19 * dVar19;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = DAT_140529bc0;
  auVar30._8_8_ = 0;
  auVar30._0_8_ = dVar16;
  auVar20 = vfmadd213sd_fma(auVar38,auVar30,auVar2);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = DAT_140529bb0;
  auVar20 = vfmadd213sd_fma(auVar20,auVar30,auVar3);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = DAT_140529ba0;
  auVar31._8_8_ = 0;
  auVar31._0_8_ = dVar16;
  auVar20 = vfmadd213sd_fma(auVar20,auVar31,auVar4);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = DAT_140529b90;
  auVar20 = vfmadd213sd_fma(auVar20,auVar31,auVar5);
  auVar6._8_8_ = 0;
  auVar6._0_8_ = DAT_140529b80;
  auVar20 = vfmadd213sd_fma(auVar20,auVar31,auVar6);
  auVar36._8_8_ = 0;
  auVar36._0_8_ = dVar19 * dVar16;
  auVar20 = vfmadd231sd_fma(in_ZMM0._0_16_,auVar36,auVar20);
  return auVar20._0_8_;
}


