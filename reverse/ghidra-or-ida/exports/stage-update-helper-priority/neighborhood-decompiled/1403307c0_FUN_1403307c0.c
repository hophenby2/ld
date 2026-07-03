// Function: FUN_1403307c0 @ 1403307c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_1403307c0(void)

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
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  ulonglong uVar21;
  double dVar22;
  uint uVar23;
  double dVar24;
  double extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_01;
  undefined1 auVar25 [16];
  undefined1 in_ZMM0 [64];
  undefined1 extraout_var_00 [56];
  double dVar28;
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 in_ZMM1 [64];
  double dVar31;
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  double dVar40;
  double dVar41;
  undefined1 auVar42 [16];
  undefined8 extraout_XMM0_Qa_00;
  undefined1 auVar26 [64];
  undefined1 auVar27 [64];
  undefined1 extraout_var [56];
  
  dVar24 = in_ZMM0._0_8_;
  if (DAT_140e309d0 != 0) {
    uVar21 = (ulonglong)dVar24 & _DAT_140525af0;
    if ((longlong)DAT_140525ad8 < (longlong)uVar21) {
      if ((double)((ulonglong)dVar24 & (ulonglong)DAT_140525af8) != DAT_140525af8) {
        if (uVar21 < DAT_140525ae8) {
          uVar23 = FUN_140340310(uVar21);
          auVar42 = in_ZMM1._0_16_;
          auVar26._8_56_ = extraout_var;
          auVar26._0_8_ = extraout_XMM0_Qa_00;
          auVar25 = auVar26._0_16_;
        }
        else {
          uVar23 = FUN_140340120();
          auVar42 = in_ZMM1._0_16_;
          auVar27._8_56_ = extraout_var_00;
          auVar27._0_8_ = extraout_XMM0_Qa_01;
          auVar25 = auVar27._0_16_;
        }
        dVar24 = auVar25._0_8_;
        if ((uVar23 & 1) == 0) {
          dVar24 = dVar24 * dVar24;
          dVar22 = DAT_140525a70 - dVar24 * DAT_140525ab8;
          auVar18._8_8_ = _UNK_140529b68;
          auVar18._0_8_ = DAT_140529b60;
          auVar32._8_8_ = 0;
          auVar32._0_8_ = (DAT_140525a70 - dVar22) - dVar24 * DAT_140525ab8;
          auVar42 = vfnmadd231sd_fma(auVar32,auVar25,auVar42);
          auVar9._8_8_ = 0;
          auVar9._0_8_ = DAT_140529b70;
          auVar37._8_8_ = 0;
          auVar37._0_8_ = dVar24;
          auVar25 = vfmadd231sd_fma(auVar18,auVar37,auVar9);
          auVar10._8_8_ = 0;
          auVar10._0_8_ = DAT_140529b50;
          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar10);
          auVar11._8_8_ = 0;
          auVar11._0_8_ = DAT_140529b40;
          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar11);
          auVar12._8_8_ = 0;
          auVar12._0_8_ = DAT_140529b30;
          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar12);
          auVar13._8_8_ = 0;
          auVar13._0_8_ = DAT_140529b20;
          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar13);
          auVar30._8_8_ = 0;
          auVar30._0_8_ = dVar24 * dVar24;
          auVar25 = vfmadd213sd_fma(auVar25,auVar30,auVar42);
          dVar22 = auVar25._0_8_ + dVar22;
        }
        else {
          auVar20._8_8_ = _UNK_140529bc8;
          auVar20._0_8_ = DAT_140529bc0;
          dVar22 = dVar24 * dVar24;
          auVar25._8_8_ = 0;
          auVar25._0_8_ = DAT_140529bd0;
          auVar38._8_8_ = 0;
          auVar38._0_8_ = dVar22;
          auVar25 = vfmadd231sd_fma(auVar20,auVar38,auVar25);
          auVar14._8_8_ = 0;
          auVar14._0_8_ = DAT_140529bb0;
          auVar25 = vfmadd213sd_fma(auVar25,auVar38,auVar14);
          auVar15._8_8_ = 0;
          auVar15._0_8_ = DAT_140529ba0;
          auVar39._8_8_ = 0;
          auVar39._0_8_ = dVar22;
          auVar25 = vfmadd213sd_fma(auVar25,auVar39,auVar15);
          auVar16._8_8_ = 0;
          auVar16._0_8_ = DAT_140529b90;
          auVar25 = vfmadd213sd_fma(auVar25,auVar39,auVar16);
          auVar17._8_8_ = 0;
          auVar17._0_8_ = DAT_140529b80;
          auVar33._8_8_ = 0;
          auVar33._0_8_ =
               dVar22 * (auVar42._0_8_ * DAT_140525ab8 - dVar24 * dVar22 * auVar25._0_8_) -
               auVar42._0_8_;
          auVar42._8_8_ = 0;
          auVar42._0_8_ = dVar24 * dVar22;
          auVar25 = vfnmadd231sd_fma(auVar33,auVar42,auVar17);
          dVar22 = dVar24 - auVar25._0_8_;
        }
        uVar21 = 0;
        if ((uVar23 + 1 & 2) != 0) {
          uVar21 = DAT_140525a80;
        }
        return (double)((ulonglong)dVar22 ^ uVar21);
      }
      dVar24 = (double)FUN_140340388();
      return dVar24;
    }
    if ((longlong)uVar21 < (longlong)DAT_140525ad0) {
      if ((longlong)uVar21 < (longlong)DAT_140525ac8) {
        return DAT_140525a70;
      }
      auVar1._8_8_ = 0;
      auVar1._0_8_ = DAT_140525a70;
      auVar29._8_8_ = 0;
      auVar29._0_8_ = dVar24 * DAT_140525ab8;
      auVar25 = vfnmadd213sd_fma(in_ZMM0._0_16_,auVar29,auVar1);
      return auVar25._0_8_;
    }
    dVar24 = dVar24 * dVar24;
    auVar19._8_8_ = _UNK_140529b78;
    auVar19._0_8_ = DAT_140529b70;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = DAT_140529b60;
    auVar34._8_8_ = 0;
    auVar34._0_8_ = dVar24;
    auVar25 = vfmadd213sd_fma(auVar19,auVar34,auVar2);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = DAT_140529b50;
    auVar25 = vfmadd213sd_fma(auVar25,auVar34,auVar3);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = DAT_140529b40;
    auVar35._8_8_ = 0;
    auVar35._0_8_ = dVar24;
    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar4);
    auVar5._8_8_ = 0;
    auVar5._0_8_ = DAT_140529b30;
    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar5);
    auVar6._8_8_ = 0;
    auVar6._0_8_ = DAT_140529b20;
    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar6);
    auVar7._8_8_ = 0;
    auVar7._0_8_ = DAT_140525ab8;
    auVar25 = vfmsub213sd_fma(auVar25,auVar35,auVar7);
    auVar8._8_8_ = 0;
    auVar8._0_8_ = DAT_140525a70;
    auVar36._8_8_ = 0;
    auVar36._0_8_ = dVar24;
    auVar25 = vfmadd213sd_fma(auVar25,auVar36,auVar8);
    return auVar25._0_8_;
  }
  dVar22 = ABS(dVar24);
  if ((ulonglong)DAT_140525ad8 <= (ulonglong)dVar22) {
    if ((ulonglong)dVar22 < (ulonglong)DAT_140525ae0) {
      uVar23 = (uint)(dVar22 * _DAT_140525ab0 + DAT_140525ab8);
      dVar31 = (double)(int)uVar23;
      dVar40 = dVar22 - DAT_140525a30 * dVar31;
      dVar28 = DAT_140525a40 * dVar31;
      dVar24 = dVar40 - dVar28;
      dVar41 = dVar40;
      if (0xf < (longlong)(((ulonglong)dVar22 >> 0x34) - ((ulonglong)ABS(dVar24) >> 0x34))) {
        dVar41 = dVar40 - DAT_140525a50 * dVar31;
        dVar28 = DAT_140525a60 * dVar31 - ((dVar40 - dVar41) - DAT_140525a50 * dVar31);
        dVar24 = dVar41 - dVar28;
      }
      dVar28 = (dVar41 - dVar24) - dVar28;
    }
    else {
      if ((ulonglong)DAT_140525af8 <= (ulonglong)dVar22) {
        dVar24 = (double)FUN_140340388();
        return dVar24;
      }
      uVar23 = FUN_14033fdd0();
      dVar28 = in_ZMM1._0_8_;
      dVar24 = extraout_XMM0_Qa;
    }
    dVar22 = dVar24 * dVar24;
    if ((uVar23 & 1) == 0) {
      dVar24 = (((DAT_140529b40 * dVar22 + DAT_140529b30) * dVar22 + DAT_140529b20 +
                ((DAT_140529b70 * dVar22 + DAT_140529b60) * dVar22 + DAT_140529b50) *
                dVar22 * dVar22 * dVar22) * dVar22 * dVar22 +
               ((((DAT_140525ab8 * dVar22 - DAT_140525a70) + DAT_140525a70) - dVar22 * DAT_140525ab8
                ) - dVar28 * dVar24)) - (dVar22 * DAT_140525ab8 - DAT_140525a70);
    }
    else {
      dVar24 = dVar28 + (dVar24 * dVar22 *
                         (((DAT_140529bd0 * dVar22 + DAT_140529bc0) * dVar22 + DAT_140529bb0) *
                          dVar22 * dVar22 * dVar22 +
                         (DAT_140529ba0 * dVar22 + DAT_140529b90) * dVar22 + DAT_140529b80) -
                        dVar22 * DAT_140525ab8 * dVar28) + dVar24;
    }
    if ((uVar23 + 1 & 2) != 0) {
      dVar24 = 0.0 - dVar24;
    }
    return dVar24;
  }
  if ((ulonglong)DAT_140525ad0 <= (ulonglong)dVar22) {
    dVar24 = dVar24 * dVar24;
    dVar28 = dVar24 * dVar24;
    dVar22 = dVar24 * _DAT_140525ac0 + DAT_140525a70;
    return (DAT_140525a70 - dVar22) + dVar24 * _DAT_140525ac0 +
           (DAT_140529b30 * dVar24 + DAT_140529b20) * dVar28 +
           (DAT_140529b50 * dVar24 + DAT_140529b40) * dVar28 * dVar28 +
           dVar28 * dVar28 * dVar28 * (DAT_140529b70 * dVar24 + DAT_140529b60) + dVar22;
  }
  if ((ulonglong)DAT_140525ac8 <= (ulonglong)dVar22) {
    return DAT_140525a70 - dVar24 * dVar24 * DAT_140525ab8;
  }
  return DAT_140525a70;
}


