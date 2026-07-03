// Function: FUN_140334430 @ 140334430
// Decompile completed: true

/* WARNING: Removing unreachable block (ram,0x0001403348af) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140334430(undefined8 param_1,double param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [60];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  ulonglong uVar15;
  undefined1 in_ZMM0 [64];
  undefined4 uVar22;
  undefined1 auVar19 [64];
  undefined1 auVar20 [64];
  undefined1 auVar21 [64];
  float fVar23;
  undefined8 uVar24;
  double dVar25;
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 in_ZMM1 [64];
  double dVar29;
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 in_ZMM3 [64];
  undefined1 auVar36 [64];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  double dVar40;
  undefined1 auVar41 [16];
  double dVar42;
  
  fVar14 = in_ZMM0._0_4_;
  auVar21._16_48_ = in_ZMM0._16_48_;
  if (DAT_140e309d0 != 0) {
    auVar39 = vpunpckldq_avx(in_ZMM1._0_16_,in_ZMM0._0_16_);
    auVar32 = (undefined1  [16])0x0;
    auVar28 = (undefined1  [16])0x0;
    fVar23 = auVar39._0_4_;
    fVar10 = ABS(fVar23);
    fVar11 = ABS(fVar14);
    uVar24 = auVar39._0_8_;
    if ((uint)fVar10 < 0x7f800000) {
      if ((uint)fVar10 < 0x3f800001) {
        if (fVar10 == 0.0) {
          if ((uint)fVar11 < 0x7f800001) {
            return 0x3f800000;
          }
          if (0x7fbfffff < (uint)fVar11) {
            return 0x3f800000;
          }
          uVar15 = FUN_1403407c4(fVar11,(uint)fVar11 | 0x400000,(uint)fVar11 | 0x400000,
                                 DAT_140527748);
          return uVar15;
        }
        if (fVar23 == 1.0) {
          if ((uint)fVar11 < 0x7f800001) {
            return in_ZMM0._0_8_;
          }
          uVar15 = FUN_1403407c4(fVar11,(uint)fVar14 | 0x400000,(uint)fVar14 | 0x400000,
                                 DAT_140527748);
          return uVar15;
        }
      }
      if ((uint)fVar11 < 0x7f800000) {
        auVar39 = vcvtps2pd_avx(auVar39);
        auVar21 = ZEXT1664(auVar39);
        if ((int)fVar14 < 0x3f880000) {
          auVar28 = auVar32;
          if ((int)fVar14 < 1) {
            if (fVar11 == 0.0) {
              fVar10 = fVar23;
              if ((int)fVar23 < 0) {
                fVar10 = INFINITY;
              }
              fVar11 = 0.0;
              if ((int)fVar23 < 0) {
                fVar11 = INFINITY;
              }
              uVar12 = 0;
              if (0 < (int)fVar23) {
                fVar10 = 0.0;
              }
              if (((uint)fVar23 & 0x7f800000) < 0x4b000001) {
                uVar12 = vstmxcsr_avx();
                vldmxcsr_avx(uVar12 | 0x1f80);
                vldmxcsr_avx(uVar12);
                uVar12 = 0;
                if ((float)(int)ROUND(fVar23) == fVar23) {
                  if (((int)ROUND(fVar23) & 1U) == 0) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = (uint)fVar14 & 0x80000000;
                  }
                }
              }
              uVar12 = uVar12 | (uint)fVar10;
              if (fVar11 == 0.0) {
                return (ulonglong)uVar12;
              }
              uVar15 = FUN_1403407c4(uVar12,uVar24,uVar12,DAT_140527744);
              return uVar15;
            }
            if (((uint)fVar23 & 0x7f800000) < 0x4b000001) {
              uVar12 = vstmxcsr_avx();
              vldmxcsr_avx(uVar12 | 0x1f80);
              vldmxcsr_avx(uVar12);
              if ((float)(int)ROUND(fVar23) != fVar23) {
                uVar15 = FUN_1403407c4(fVar11,0xffc00000,0xffc00000,DAT_140527754);
                return uVar15;
              }
              if (((int)ROUND(fVar23) & 1U) != 0) {
                auVar28 = ZEXT416(DAT_1405277ac);
              }
            }
          }
          auVar32 = vpshufd_avx(auVar39,0xee);
          dVar25 = auVar32._0_8_ - DAT_14052779c;
          param_2 = ABS(dVar25);
          if ((ulonglong)param_2 < (ulonglong)DAT_140527794) {
            vpshufd_avx(auVar28,0x44);
            dVar40 = dVar25 / (dVar25 + DAT_1405277a4);
            dVar29 = dVar40 + dVar40;
            dVar42 = dVar29 * dVar29;
            auVar39._8_8_ = 0;
            auVar39._0_8_ = dVar42;
            auVar39 = vpshufd_avx(auVar39,0x44);
            auVar28._8_8_ = 0;
            auVar28._0_8_ = dVar42 * dVar42 * dVar29 * dVar42;
            auVar32._8_8_ = 0;
            auVar32._0_8_ = dVar29 * dVar42;
            auVar28 = vunpcklpd_avx(auVar32,auVar28);
            auVar31._0_8_ = auVar28._0_8_ * (auVar39._0_8_ * _DAT_1405277c0 + _DAT_1405277d0);
            auVar31._8_8_ = auVar28._8_8_ * (auVar39._8_8_ * _UNK_1405277c8 + _UNK_1405277d8);
            auVar39 = vpshufd_avx(auVar31,0xee);
            auVar41._8_8_ = 0;
            auVar41._0_8_ = dVar40 * dVar25;
            auVar28 = vpshufd_avx(auVar41,0xee);
            uVar15 = auVar28._0_8_;
            dVar25 = dVar25 + ((auVar39._0_8_ + auVar31._0_8_) - dVar40 * dVar25);
            goto LAB_14033452e;
          }
        }
        auVar32 = vpshufd_avx(auVar39,0xee);
        auVar32 = vpand_avx(auVar32,_DAT_140527820);
        uVar12 = (auVar32._4_4_ >> 0xc) + (uint)((auVar32._0_8_ >> 0x2b & 1) != 0);
        auVar8._8_8_ = _UNK_140527808;
        auVar8._0_8_ = DAT_140527800;
        auVar31 = vpor_avx(auVar32,auVar8);
        auVar32 = vpshufd_avx(auVar31,0xee);
        auVar32 = vpsrlq_avx(auVar32,0x34);
        auVar9._8_8_ = _UNK_140527818;
        auVar9._0_8_ = _DAT_140527810;
        auVar32 = vpsubq_avx(auVar32,auVar9);
        auVar32 = vcvtdq2pd_avx(auVar32);
        dVar25 = ((double)((ulonglong)(uVar12 | 0x3fe00) << 0x2c) - auVar31._0_8_) *
                 *(double *)(&DAT_14052b550 + (ulonglong)uVar12 * 8);
        auVar26._8_8_ = 0;
        auVar26._0_8_ = dVar25;
        auVar38._8_8_ = 0;
        auVar38._0_8_ = DAT_140527764;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = DAT_140527800;
        auVar31 = vfmadd213sd_fma(auVar38,auVar26,auVar1);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = DAT_14052779c;
        auVar27._8_8_ = 0;
        auVar27._0_8_ = dVar25;
        auVar31 = vfmadd213sd_fma(auVar31,auVar27,auVar2);
        dVar25 = dVar25 * auVar31._0_8_;
        dVar29 = auVar39._0_8_ *
                 ((auVar32._0_8_ * DAT_14052776c +
                  *(double *)(&DAT_140527830 + (ulonglong)uVar12 * 8)) - dVar25);
        if (DAT_140527774 < dVar29) {
          auVar39 = vorps_avx(ZEXT416(0x7f800000),auVar28);
          uVar15 = FUN_1403407c4(&DAT_140527830,0x7f800000,auVar39._0_8_,DAT_140527760);
          return uVar15;
        }
        if (DAT_14052777c < dVar29) {
          auVar33._0_8_ = dVar29 * _DAT_1405277f0;
          auVar33._8_8_ = _UNK_1405277f8 * 0.0;
          auVar32 = vcvtpd2dq_avx(auVar33);
          auVar39 = vcvtdq2pd_avx(auVar32);
          auVar3._8_8_ = 0;
          auVar3._0_8_ = DAT_140527784;
          auVar16._8_8_ = 0;
          auVar16._0_8_ = dVar29;
          auVar31 = vfnmadd231sd_fma(auVar16,auVar39,auVar3);
          auVar34._8_8_ = 0;
          auVar34._0_8_ = DAT_14052778c;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = DAT_140527800;
          auVar39 = vfmadd213sd_fma(auVar34,auVar31,auVar4);
          auVar5._8_8_ = 0;
          auVar5._0_8_ = DAT_14052779c;
          auVar39 = vfmadd213sd_fma(auVar39,auVar31,auVar5);
          auVar35._8_8_ = 0;
          auVar35._0_8_ = *(ulonglong *)(&DAT_140529f20 + (ulonglong)(auVar32._0_4_ & 0x3f) * 8);
          auVar17._8_8_ = 0;
          auVar17._0_8_ = auVar31._0_8_ * auVar39._0_8_;
          auVar31 = vfmadd213sd_fma(auVar17,auVar35,auVar35);
          auVar39 = vpsrad_avx(auVar32,6);
          auVar39 = vpsllq_avx(auVar39,0x34);
          auVar39 = vpaddq_avx(auVar39,auVar31);
          auVar18._0_4_ = (float)auVar39._0_8_;
          auVar18._4_12_ = auVar31._4_12_;
          auVar39 = vorps_avx(auVar18,auVar28);
          return auVar39._0_8_;
        }
        auVar39 = vorps_avx((undefined1  [16])0x0,auVar28);
        uVar15 = FUN_1403407c4(&DAT_140527830,dVar25,auVar39._0_8_,DAT_140527758);
        return uVar15;
      }
      if (fVar10 == 0.0) {
        return 0x3f800000;
      }
      if (fVar14 == INFINITY) {
        if (-1 < (int)fVar23) {
          return 0x7f800000;
        }
        return 0;
      }
      if (fVar14 == -INFINITY) {
        uVar12 = 0;
        fVar14 = fVar23;
        if ((int)fVar23 < 0) {
          fVar14 = 0.0;
        }
        if (0 < (int)fVar23) {
          fVar14 = INFINITY;
        }
        if (((uint)fVar23 & 0x7f800000) < 0x4b000001) {
          uVar12 = vstmxcsr_avx();
          vldmxcsr_avx(uVar12 | 0x1f80);
          vldmxcsr_avx(uVar12);
          uVar12 = 0;
          if (((float)(int)ROUND(fVar23) == fVar23) &&
             (uVar12 = 0x80000000, ((int)ROUND(fVar23) & 1U) == 0)) {
            uVar12 = 0;
          }
        }
        return (ulonglong)(uVar12 | (uint)fVar14);
      }
    }
    else {
      if (0x7f800000 < (uint)fVar10) {
        if (0x7f800000 < (uint)fVar11) {
          if (fVar14 != -NAN) {
            uVar15 = FUN_1403407c4((uint)fVar14 | 0x400000,uVar24,(uint)fVar14 | 0x400000,
                                   DAT_140527750);
            return uVar15;
          }
          uVar15 = FUN_1403407c4(0x7fc00000,uVar24,(uint)fVar23 | 0x400000,DAT_140527750);
          return uVar15;
        }
        if (fVar14 == 1.0) {
          if (0x7fbfffff < (uint)fVar10) {
            return 0x3f800000;
          }
          uVar15 = FUN_1403407c4(0x3f800000,0x3f800000,0x3f800000,DAT_14052774c);
          return uVar15;
        }
        uVar15 = FUN_1403407c4(uVar24,uVar24,(uint)fVar23 | 0x400000,DAT_14052774c);
        return uVar15;
      }
      if ((uint)fVar11 < 0x7f800001) {
        if (fVar11 == 1.0) {
          return 0x3f800000;
        }
        if (-1 < (int)fVar23) {
          if (0x3f7fffff < (uint)fVar11) {
            return 0x7f800000;
          }
          return 0;
        }
        uVar12 = 0;
        if ((uint)fVar11 < 0x3f800000) {
          uVar12 = 0x7f800000;
        }
        return (ulonglong)uVar12;
      }
    }
    uVar15 = FUN_1403407c4((uint)fVar14 | 0x400000,uVar24,(uint)fVar14 | 0x400000,DAT_140527748);
    return uVar15;
  }
  fVar23 = in_ZMM1._0_4_;
  uVar24 = CONCAT44(fVar14,fVar23);
  uVar15 = 0;
  fVar10 = ABS(fVar23);
  fVar11 = ABS(fVar14);
  if (0x7f7fffff < (uint)fVar10) {
    if (0x7f800000 < (uint)fVar10) {
      if (0x7f800000 < (uint)fVar11) {
        if (fVar14 != -NAN) {
          uVar15 = FUN_1403407c4((uint)fVar14 | 0x400000,uVar24,param_3,DAT_140527750);
          return uVar15;
        }
        uVar15 = FUN_1403407c4(0x7fc00000,uVar24,param_3,DAT_140527750);
        return uVar15;
      }
      if (fVar14 == 1.0) {
        if (0x7fbfffff < (uint)fVar10) {
          return 0x3f800000;
        }
        uVar15 = FUN_1403407c4(0x3f800000,0x3f800000,param_3,DAT_14052774c);
        return uVar15;
      }
      uVar15 = FUN_1403407c4(fVar11,uVar24,param_3,DAT_14052774c);
      return uVar15;
    }
    if ((uint)fVar11 < 0x7f800001) {
      if (fVar11 == 1.0) {
        return 0x3f800000;
      }
      if ((int)fVar23 < 0) {
        if (fVar11 != 0.0) {
          uVar12 = 0;
          if ((uint)fVar11 < 0x3f800000) {
            uVar12 = 0x7f800000;
          }
          return (ulonglong)uVar12;
        }
      }
      else if ((uint)fVar11 < 0x3f800000) {
        return 0;
      }
      return 0x7f800000;
    }
LAB_140334a50:
    uVar15 = FUN_1403407c4((uint)fVar14 | 0x400000,uVar24,param_3,DAT_140527748);
    return uVar15;
  }
  if ((uint)fVar10 < 0x3f800001) {
    if (fVar10 == 0.0) {
      if ((uint)fVar11 < 0x7f800001) {
        return 0x3f800000;
      }
      if (0x7fbfffff < (uint)fVar11) {
        return 0x3f800000;
      }
      uVar15 = FUN_1403407c4(fVar11,(uint)fVar11 | 0x400000,param_3,DAT_140527748);
      return uVar15;
    }
    param_2 = (double)(in_ZMM1._0_8_ & 0xffffffff);
    if (fVar23 == 1.0) {
      if ((uint)ABS(fVar14) < 0x7f800001) {
        return in_ZMM0._0_8_;
      }
      uVar15 = FUN_1403407c4(fVar11,(uint)fVar14 | 0x400000,param_3,DAT_140527748);
      return uVar15;
    }
  }
  if (0x7f7fffff < (uint)fVar11) {
    if (fVar10 == 0.0) {
      return 0x3f800000;
    }
    if (fVar14 == INFINITY) {
      if (-1 < (int)fVar23) {
        return 0x7f800000;
      }
      return 0;
    }
    if (fVar14 == -INFINITY) {
      uVar12 = 0;
      fVar14 = fVar23;
      if ((int)fVar23 < 0) {
        fVar14 = 0.0;
      }
      if (0 < (int)fVar23) {
        fVar14 = INFINITY;
      }
      if (((uint)fVar23 & 0x7f800000) < 0x4b000001) {
        uVar12 = 0;
        if (((float)(int)ROUND(fVar23) == fVar23) &&
           (uVar12 = 0x80000000, ((int)ROUND(fVar23) & 1U) == 0)) {
          uVar12 = 0;
        }
      }
      return (ulonglong)(uVar12 | (uint)fVar14);
    }
    goto LAB_140334a50;
  }
  auVar21._0_8_ = (double)fVar23;
  auVar21._8_8_ = (double)fVar14;
  uVar22 = (undefined4)((ulonglong)auVar21._8_8_ >> 0x20);
  if ((int)fVar14 < 0x3f880000) {
    if ((int)fVar14 < 1) {
      if (fVar11 == 0.0) {
        fVar10 = fVar23;
        if ((int)fVar23 < 0) {
          fVar10 = INFINITY;
        }
        fVar11 = 0.0;
        if ((int)fVar23 < 0) {
          fVar11 = INFINITY;
        }
        uVar12 = 0;
        if (0 < (int)fVar23) {
          fVar10 = 0.0;
        }
        uVar13 = (uint)fVar23 & 0x7f800000;
        if (uVar13 < 0x4b000001) {
          uVar13 = (uint)ROUND(fVar23);
          uVar12 = 0;
          if ((float)(int)uVar13 == fVar23) {
            uVar12 = uVar13 & 1;
            uVar13 = uVar13 >> 1 | (uint)((float)(int)uVar13 < fVar23) << 0x1f;
            if (uVar12 == 0) {
              uVar12 = 0;
            }
            else {
              uVar12 = (uint)fVar14 & 0x80000000;
            }
          }
        }
        uVar15 = (ulonglong)(uVar12 | (uint)fVar10);
        if (fVar11 != 0.0) {
          uVar15 = FUN_1403407c4(uVar12 | (uint)fVar10,uVar24,uVar13,DAT_140527744);
        }
        return uVar15;
      }
      if (((uint)fVar23 & 0x7f800000) < 0x4b000001) {
        if ((float)(int)ROUND(fVar23) != fVar23) {
          uVar15 = FUN_1403407c4(fVar11,0xffc00000,param_3,DAT_140527754);
          return uVar15;
        }
        if (((int)ROUND(fVar23) & 1U) != 0) {
          uVar15 = (ulonglong)DAT_1405277ac;
        }
      }
    }
    auVar36._8_4_ = SUB84(auVar21._8_8_,0);
    auVar36._0_8_ = auVar21._8_8_;
    auVar36._16_48_ = in_ZMM3._16_48_;
    auVar36._12_4_ = uVar22;
    in_ZMM3._8_56_ = auVar36._8_56_;
    in_ZMM3._0_8_ = auVar21._8_8_ - DAT_14052779c;
    param_2 = ABS(in_ZMM3._0_8_);
    if ((ulonglong)param_2 < (ulonglong)DAT_140527794) {
      dVar42 = in_ZMM3._0_8_ / (in_ZMM3._0_8_ + DAT_1405277a4);
      dVar29 = dVar42 + dVar42;
      dVar25 = dVar29 * dVar29;
      auVar37._8_4_ = SUB84(dVar25,0);
      auVar37._0_8_ = dVar25;
      auVar37._12_4_ = (int)((ulonglong)dVar25 >> 0x20);
      dVar25 = in_ZMM3._0_8_ +
               ((dVar29 * dVar25 * (dVar25 * _DAT_1405277c0 + _DAT_1405277d0) +
                dVar25 * dVar25 * dVar29 * dVar25 *
                (auVar37._8_8_ * _UNK_1405277c8 + _UNK_1405277d8)) - dVar42 * in_ZMM3._0_8_);
      goto LAB_14033452e;
    }
  }
  auVar30._8_4_ = SUB84(auVar21._8_8_,0);
  auVar30._0_8_ = auVar21._8_8_;
  auVar30._12_4_ = uVar22;
  auVar30 = auVar30 & _DAT_140527820;
  uVar12 = (auVar30._4_4_ >> 0xc) + (uint)((auVar30._0_8_ >> 0x2b & 1) != 0);
  auVar7._8_8_ = _UNK_140527808;
  auVar7._0_8_ = DAT_140527800;
  auVar6._4_56_ = in_ZMM3._8_56_;
  auVar6._0_4_ = SUB164(auVar30 | auVar7,0xc);
  dVar25 = ((double)((ulonglong)(uVar12 | 0x3fe00) << 0x2c) - SUB168(auVar30 | auVar7,0)) *
           *(double *)(&DAT_14052b550 + (ulonglong)uVar12 * 8);
  dVar25 = ((double)(int)(((auVar6._0_8_ & 0xffffffff) >> 0x14) - _DAT_140527810) * DAT_14052776c +
           *(double *)(&DAT_140527830 + (ulonglong)uVar12 * 8)) -
           (dVar25 * dVar25 * (DAT_140527764 * dVar25 + DAT_140527800) + dVar25);
LAB_14033452e:
  auVar19._8_56_ = auVar21._8_56_;
  dVar25 = auVar21._0_8_ * dVar25;
  if (DAT_140527774 < dVar25) {
    uVar15 = FUN_1403407c4(dVar25,0x7f800000,param_3,DAT_140527760);
    return uVar15;
  }
  if (DAT_14052777c < dVar25) {
    uVar12 = (uint)(dVar25 * _DAT_1405277f0);
    dVar25 = dVar25 - (double)(int)uVar12 * DAT_140527784;
    auVar19._0_8_ =
         (dVar25 * dVar25 * (DAT_14052778c * dVar25 + DAT_140527800) + dVar25) *
         *(double *)(&DAT_140529f20 + (ulonglong)(uVar12 & 0x3f) * 8) +
         *(double *)(&DAT_140529f20 + (ulonglong)(uVar12 & 0x3f) * 8);
    auVar20._4_60_ = auVar19._4_60_;
    auVar20._0_4_ =
         (float)(double)(((ulonglong)(uint)((int)uVar12 >> 6) << 0x34) + (longlong)auVar19._0_8_);
    return auVar20._0_8_ | uVar15;
  }
  uVar15 = FUN_1403407c4(dVar25,param_2,param_3,DAT_140527758);
  return uVar15;
}


