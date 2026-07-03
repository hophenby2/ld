// Function: FUN_1403316f0 @ 1403316f0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1403316f0(double param_1,double param_2)

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
  undefined8 uVar13;
  undefined4 uVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  uint uVar26;
  int iVar27;
  ulonglong uVar28;
  double dVar29;
  ulonglong uVar30;
  longlong lVar31;
  double dVar32;
  double dVar33;
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 in_ZMM0 [64];
  double dVar43;
  double dVar44;
  double dVar45;
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  double dVar51;
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  uint uVar59;
  undefined1 auVar60 [16];
  double dVar61;
  undefined1 auVar62 [16];
  double local_88;
  undefined8 uStack_80;
  
  auVar52 = in_ZMM0._0_16_;
  dVar43 = in_ZMM0._0_8_;
  if (DAT_140e309d0 != 0) {
    if ((DAT_140525ed8 & (ulonglong)param_2) == 0) {
      dVar51 = 0.0;
      if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) {
        dVar51 = dVar43;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
        return;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51 & _DAT_140525f00) != 0) {
        return;
      }
      goto LAB_140332c80;
    }
    if (param_2 == DAT_140525ec8) {
      dVar51 = 0.0;
      if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) {
        dVar51 = dVar43;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
        return;
      }
      goto LAB_140332c80;
    }
    local_88 = DAT_140525ed0;
    if ((double)((ulonglong)DAT_140525ea0 & (ulonglong)dVar43) != DAT_140525ea0) {
      if (dVar43 == DAT_140525ec8) {
        dVar51 = 0.0;
        if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
          dVar51 = param_2;
        }
        if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
          return;
        }
        if ((DAT_140525ee0 & (ulonglong)dVar51 & _DAT_140525f00) != 0) {
          return;
        }
        goto LAB_140332cd0;
      }
      if (dVar43 != DAT_140525ed0) {
        if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_140332b20;
        if (DAT_140525e90 < (longlong)(DAT_140525eb0 & (ulonglong)param_2)) goto LAB_140332a00;
        if ((longlong)(DAT_140525eb0 & (ulonglong)param_2) < DAT_140525e98) {
          return;
        }
LAB_1403323e6:
        auVar57 = vpsrlq_avx(auVar52,0x34);
        uVar28 = auVar52._0_8_;
        auVar16._8_8_ = _UNK_140525fe8;
        auVar16._0_8_ = _DAT_140525fe0;
        auVar57 = vpsubq_avx(auVar57,auVar16);
        auVar57 = vcvtdq2pd_avx(auVar57);
        auVar52 = vpand_avx(auVar52,_DAT_140525fd0);
        if (auVar57._0_8_ == DAT_1405260c0) {
          auVar17._8_8_ = _UNK_140526038;
          auVar17._0_8_ = DAT_140526030;
          auVar52 = vpor_avx(auVar52,auVar17);
          auVar55._8_8_ = 0;
          auVar55._0_8_ = auVar52._0_8_ - DAT_140526030;
          auVar52 = vpand_avx(auVar55,_DAT_140525fd0);
          uVar28 = auVar52._0_8_;
          auVar57 = vpsrlq_avx(auVar55,0x34);
          auVar18._4_12_ = _UNK_1405260d4;
          auVar18._0_4_ = _DAT_1405260d0;
          auVar57 = vpsubd_avx(auVar57,auVar18);
          auVar57 = vcvtdq2pd_avx(auVar57);
        }
        uVar28 = (uVar28 & _DAT_140525f48) + (uVar28 & _DAT_140525f50) * 2;
        uVar30 = uVar28 >> 0x2c;
        auVar52 = vpor_avx(auVar52,_DAT_140526040);
        auVar46._8_8_ = 0;
        auVar46._0_8_ = uVar28;
        auVar42 = vpor_avx(auVar46,_DAT_140526040);
        dVar61 = auVar42._0_8_ - auVar52._0_8_;
        dVar45 = dVar61 * *(double *)(&DAT_140526100 + uVar30 * 8);
        dVar61 = dVar61 * *(double *)(&DAT_140526910 + uVar30 * 8);
        dVar51 = dVar45 + dVar61;
        auVar47._8_8_ = 0;
        auVar47._0_8_ = dVar51;
        auVar48._8_8_ = 0;
        auVar48._0_8_ = DAT_1405260b0;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = DAT_1405260a0;
        auVar52 = vfmadd213sd_fma(auVar48,auVar47,auVar1);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = DAT_140526090;
        auVar52 = vfmadd213sd_fma(auVar52,auVar47,auVar2);
        auVar3._8_8_ = 0;
        auVar3._0_8_ = DAT_140526080;
        auVar52 = vfmadd213sd_fma(auVar52,auVar47,auVar3);
        auVar4._8_8_ = 0;
        auVar4._0_8_ = DAT_140526070;
        auVar52 = vfmadd213sd_fma(auVar52,auVar47,auVar4);
        auVar5._8_8_ = 0;
        auVar5._0_8_ = DAT_140526060;
        auVar52 = vfmadd213sd_fma(auVar52,auVar47,auVar5);
        auVar34._8_8_ = 0;
        auVar34._0_8_ = dVar51 * dVar51;
        auVar58._8_8_ = 0;
        auVar58._0_8_ = (dVar45 - dVar51) + dVar61;
        auVar52 = vfmadd213sd_fma(auVar52,auVar34,auVar58);
        auVar60._8_8_ = 0;
        auVar60._0_8_ = DAT_140526010;
        auVar52 = vfmsub213sd_fma(auVar60,auVar57,auVar52);
        auVar35._8_8_ = 0;
        auVar35._0_8_ = *(ulonglong *)(&DAT_14052bd70 + uVar30 * 8);
        dVar45 = auVar52._0_8_ + *(double *)(&DAT_14052c580 + uVar30 * 8);
        dVar29 = dVar45 - dVar51;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = DAT_140526000;
        auVar57 = vfmadd231sd_fma(auVar35,auVar57,auVar6);
        dVar61 = auVar57._0_8_ + dVar29;
        auVar36._8_8_ = 0;
        auVar36._0_8_ = dVar61;
        auVar15._8_8_ = _UNK_140525f68;
        auVar15._0_8_ = _DAT_140525f60;
        auVar52 = vandpd_avx(auVar36,auVar15);
        dVar44 = (double)((ulonglong)param_2 & _DAT_140525f60);
        dVar32 = auVar52._0_8_;
        dVar51 = (auVar57._0_8_ - dVar61) + dVar29 + (dVar45 - (dVar51 + dVar29)) +
                 (dVar61 - dVar32);
        dVar51 = (param_2 - dVar44) * dVar51 + (param_2 - dVar44) * dVar32 + dVar51 * dVar44;
        dVar45 = dVar32 * dVar44 + dVar51;
        auVar49._8_8_ = 0;
        auVar49._0_8_ = dVar45;
        dVar61 = dVar45 * DAT_140527190;
        if (dVar61 <= DAT_140527170) {
          if (dVar61 < DAT_140527180) {
            local_88 = (double)(DAT_140527140 | (ulonglong)local_88);
            goto LAB_140332c30;
          }
          auVar62._8_8_ = 0;
          auVar62._0_8_ = dVar61;
          auVar57 = vcvtpd2dq_avx(auVar62);
          auVar52 = vcvtdq2pd_avx(auVar57);
          auVar7._8_8_ = 0;
          auVar7._0_8_ = DAT_1405271a0;
          auVar42 = vfnmadd231sd_fma(auVar49,auVar52,auVar7);
          uVar59 = auVar57._0_4_ & 0x3f;
          uVar28 = (ulonglong)uVar59;
          uVar26 = (int)(auVar57._0_4_ - uVar59) >> 6;
          dVar51 = auVar42._0_8_ + auVar52._0_8_ * DAT_1405271b0 +
                   (dVar32 * dVar44 - dVar45) + dVar51;
          auVar37._8_8_ = 0;
          auVar37._0_8_ = DAT_1405271c0;
          auVar8._8_8_ = 0;
          auVar8._0_8_ = DAT_1405271d0;
          auVar53._8_8_ = 0;
          auVar53._0_8_ = dVar51;
          auVar52 = vfmadd213sd_fma(auVar37,auVar53,auVar8);
          auVar9._8_8_ = 0;
          auVar9._0_8_ = DAT_1405271e0;
          auVar52 = vfmadd213sd_fma(auVar52,auVar53,auVar9);
          uVar59 = 0;
          if ((int)uVar26 <= (int)DAT_140527120) {
            uVar59 = uVar26;
          }
          auVar10._8_8_ = 0;
          auVar10._0_8_ = DAT_1405271f0;
          auVar54._8_8_ = 0;
          auVar54._0_8_ = dVar51;
          auVar52 = vfmadd213sd_fma(auVar52,auVar54,auVar10);
          auVar11._8_8_ = 0;
          auVar11._0_8_ = DAT_140527200;
          auVar52 = vfmadd213sd_fma(auVar52,auVar54,auVar11);
          dVar61 = (double)((ulonglong)uVar26 + 0x3ff << 0x34);
          auVar12._8_8_ = 0;
          auVar12._0_8_ = DAT_140526030;
          auVar52 = vfmadd213sd_fma(auVar52,auVar54,auVar12);
          dVar51 = auVar52._0_8_ * dVar51;
          dVar51 = dVar51 * *(double *)(&DAT_14052a120 + uVar28 * 8) +
                   dVar51 * *(double *)(&DAT_14052a320 + uVar28 * 8) +
                   *(double *)(&DAT_14052a320 + uVar28 * 8) +
                   *(double *)(&DAT_14052a120 + uVar28 * 8);
          auVar50._8_8_ = 0;
          auVar50._0_8_ = dVar51;
          if (dVar61 != DAT_140525fb0) {
            if (uVar59 == 0) {
              auVar19._8_8_ = uStack_80;
              auVar19._0_8_ = local_88;
              auVar38._8_8_ = 0;
              auVar38._0_8_ = dVar51 * dVar61;
              vorpd_avx(auVar38,auVar19);
              return;
            }
            uVar26 = 0;
            if (DAT_140526030 <= dVar51) {
              uVar26 = uVar59;
            }
            if (uVar26 == DAT_140527120) {
              auVar21._8_8_ = uStack_80;
              auVar21._0_8_ = local_88;
              auVar39._8_8_ = 0;
              auVar39._0_8_ = dVar51 * dVar61;
              vorpd_avx(auVar39,auVar21);
              return;
            }
            if (DAT_140527160 < (longlong)dVar45) {
              auVar41._8_8_ = 0;
              auVar41._0_8_ = DAT_140527150;
              auVar23._8_8_ = uStack_80;
              auVar23._0_8_ = local_88;
              auVar52 = vorpd_avx(auVar41,auVar23);
              uVar13 = auVar52._0_8_;
            }
            else {
              iVar27 = uVar59 + 0x432;
              if (iVar27 < 0) {
                iVar27 = 0;
              }
              auVar22._8_8_ = uStack_80;
              auVar22._0_8_ = local_88;
              auVar40._8_8_ = 0;
              auVar40._0_8_ = dVar51 * (double)(1L << ((byte)iVar27 & 0x3f));
              auVar52 = vorpd_avx(auVar40,auVar22);
              uVar13 = auVar52._0_8_;
            }
            FUN_140340690(dVar43,param_2,uVar13,DAT_140525e7c);
            return;
          }
          if (dVar51 < DAT_140526030) {
            auVar52 = vorpd_avx(auVar50,_DAT_140527130);
            auVar20._8_8_ = uStack_80;
            auVar20._0_8_ = local_88;
            vorpd_avx(auVar52,auVar20);
            return;
          }
        }
        local_88 = (double)((ulonglong)DAT_140525fb0 | (ulonglong)local_88);
LAB_140332c30:
        uVar14 = DAT_140525e78;
        if ((DAT_140525ed8 & (ulonglong)local_88) != 0) {
          uVar14 = DAT_140525e80;
        }
        FUN_140340690(dVar43,param_2,local_88,uVar14);
        return;
      }
      goto LAB_140332a50;
    }
    if (DAT_140525e90 < (longlong)(DAT_140525eb0 & (ulonglong)param_2)) {
LAB_140332a00:
      if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_140332b20;
      if ((DAT_140525ed8 & (ulonglong)dVar43) == 0) goto LAB_140332a50;
      if (dVar43 != DAT_140525f08) {
        if ((longlong)((ulonglong)dVar43 & DAT_140525ed8) < (longlong)DAT_140525ec8) {
          local_88 = 0.0;
          if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) != 0) {
            local_88 = DAT_140525ec0;
          }
        }
        else {
          local_88 = 0.0;
          if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) == 0) {
            local_88 = DAT_140525ec0;
          }
        }
        dVar51 = 0.0;
        if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
          dVar51 = param_2;
        }
        if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
          if (dVar51 != 0.0) {
            return;
          }
          goto LAB_140332c30;
        }
        goto LAB_140332cd0;
      }
LAB_140332960:
      dVar51 = 0.0;
      if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
        dVar51 = param_2;
      }
    }
    else {
      uVar28 = DAT_140525ed8 & (ulonglong)param_2;
      lVar31 = (uVar28 >> (SUB81(DAT_140525f18,0) & 0x3f)) - _DAT_140525f20;
      if (lVar31 < 0) {
LAB_1403329b0:
        if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_140332b20;
        if (dVar43 != DAT_140525f10) {
          FUN_140340690(dVar43,param_2,DAT_140525ef0,DAT_140525e74);
          return;
        }
      }
      else {
        if (lVar31 <= DAT_140525f30) {
          if ((DAT_140525f38 >> ((byte)lVar31 & 0x3f) & uVar28) != 0) goto LAB_1403329b0;
          if ((DAT_140525f40 >> ((byte)lVar31 & 0x3f) & uVar28) != 0) {
            local_88 = DAT_140525ea0;
          }
        }
        if (dVar43 != DAT_140525f10) {
          if (dVar43 == DAT_140525f08) goto LAB_140332960;
          if ((DAT_140525eb0 & (ulonglong)dVar43) != DAT_140525eb0) {
            auVar52._8_8_ = 0;
            auVar52._0_8_ = DAT_140525ed8 & (ulonglong)dVar43;
            goto LAB_1403323e6;
          }
LAB_140332b20:
          dVar51 = 0.0;
          if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) == 0) {
            dVar51 = DAT_140525ec0;
          }
          if ((DAT_140525ee0 & (ulonglong)dVar43) != 0) {
LAB_140332c80:
            dVar45 = (double)((ulonglong)dVar43 | _DAT_140525f00);
            dVar51 = 0.0;
            if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
              dVar51 = param_2;
            }
            if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
              FUN_140340690(dVar43,param_2,dVar45,DAT_140525e68);
            }
            else {
              dVar51 = param_2;
              if (dVar45 != DAT_140525ee8) {
                dVar61 = param_2;
                if (param_2 == DAT_140525ee8) {
                  dVar61 = dVar45;
                }
                if (((ulonglong)dVar61 & (ulonglong)DAT_140525ea0) != 0) {
                  dVar61 = dVar45;
                }
                dVar51 = dVar45;
                if (((ulonglong)dVar45 & (ulonglong)DAT_140525ea0) != 0) {
                  dVar51 = dVar61;
                }
              }
              FUN_140340690(dVar43,param_2,(ulonglong)dVar51 | _DAT_140525f00,DAT_140525e70);
            }
            return;
          }
          dVar45 = 0.0;
          if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
            dVar45 = param_2;
          }
          if ((DAT_140525ee0 & (ulonglong)dVar45) == 0) {
            auVar57._8_8_ = uStack_80;
            auVar57._0_8_ = local_88;
            auVar42._8_8_ = 0;
            auVar42._0_8_ = dVar51;
            vorpd_avx(auVar42,auVar57);
            return;
          }
          goto LAB_140332cd0;
        }
      }
LAB_140332a50:
      if ((DAT_140525eb0 & (ulonglong)param_2) != DAT_140525eb0) {
        if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) == 0) {
          auVar24._8_8_ = uStack_80;
          auVar24._0_8_ = local_88;
          vorpd_avx(ZEXT816(0),auVar24);
          return;
        }
        auVar25._8_8_ = uStack_80;
        auVar25._0_8_ = local_88;
        auVar56._8_8_ = 0;
        auVar56._0_8_ = DAT_140525ec0;
        auVar52 = vorpd_avx(auVar56,auVar25);
        FUN_140340690(dVar43,param_2,auVar52._0_8_,DAT_140525e64);
        return;
      }
      if (param_2 == DAT_140525eb8) {
        return;
      }
      dVar51 = param_2;
      if (param_2 == DAT_140525ec0) {
        return;
      }
    }
    if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
      return;
    }
LAB_140332cd0:
    FUN_140340690(dVar43,param_2,(ulonglong)param_2 | _DAT_140525f00,DAT_140525e6c);
    return;
  }
  if ((DAT_140525ed8 & (ulonglong)param_2) == 0) {
    dVar51 = 0.0;
    if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) {
      dVar51 = dVar43;
    }
    if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
      return;
    }
    if ((DAT_140525ee0 & (ulonglong)dVar51 & _DAT_140525f00) != 0) {
      return;
    }
    goto LAB_140332c80;
  }
  if (param_2 == DAT_140525ec8) {
    dVar51 = 0.0;
    if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) {
      dVar51 = dVar43;
    }
    if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
      return;
    }
    goto LAB_140332230;
  }
  local_88 = DAT_140525ed0;
  if ((double)((ulonglong)DAT_140525ea0 & (ulonglong)dVar43) != DAT_140525ea0) {
    if (dVar43 == DAT_140525ec8) {
      dVar51 = 0.0;
      if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
        dVar51 = param_2;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
        return;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51 & _DAT_140525f00) != 0) {
        return;
      }
      goto LAB_140332280;
    }
    if (dVar43 != DAT_140525ed0) {
      if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_1403320c0;
      if (DAT_140525e90 < (longlong)(DAT_140525eb0 & (ulonglong)param_2)) goto LAB_140331fc0;
      dVar45 = dVar43;
      if ((longlong)(DAT_140525eb0 & (ulonglong)param_2) < DAT_140525e98) {
        return;
      }
LAB_1403317d5:
      dVar61 = (double)(int)(((ulonglong)dVar45 >> 0x34) - _DAT_140525fe0);
      dVar51 = (double)((ulonglong)dVar45 & (ulonglong)DAT_140525fd0);
      dVar43 = dVar45;
      if (dVar61 == DAT_1405260c0) {
        dVar51 = (double)((ulonglong)dVar51 | (ulonglong)DAT_140526030) - DAT_140526030;
        dVar43 = (double)((ulonglong)dVar51 & (ulonglong)DAT_140525fd0);
        dVar61 = (double)(int)((uint)((ulonglong)dVar51 >> 0x34) - _DAT_1405260d0);
        dVar51 = dVar43;
      }
      uVar28 = ((ulonglong)dVar43 & _DAT_140525f48) + ((ulonglong)dVar43 & _DAT_140525f50) * 2;
      dVar29 = (double)(uVar28 >> 0x2c);
      dVar51 = (double)((ulonglong)dVar51 | (ulonglong)DAT_140526040);
      dVar43 = (double)(uVar28 | (ulonglong)DAT_140526040);
      if ((double)((ulonglong)(dVar45 - DAT_140526030) & _DAT_1405260f0) < _DAT_1405260e0) {
        dVar51 = dVar43 - dVar51;
        dVar33 = (double)((ulonglong)
                          (dVar51 * (*(double *)(&DAT_140526100 + (longlong)dVar29 * 8) +
                                    *(double *)(&DAT_140526910 + (longlong)dVar29 * 8))) &
                         _DAT_140525f60);
        dVar44 = (dVar51 - dVar33 * dVar43) *
                 (*(double *)(&DAT_140526100 + (longlong)dVar29 * 8) +
                 *(double *)(&DAT_140526910 + (longlong)dVar29 * 8));
        dVar32 = dVar44 + dVar33;
        dVar43 = dVar32 * dVar32;
        dVar51 = dVar33 * dVar33 * DAT_140526060;
        dVar45 = dVar33 + dVar51;
        dVar51 = (DAT_140526010 * dVar61 + *(double *)(&DAT_14052c580 + (longlong)dVar29 * 8)) -
                 ((DAT_140526080 * dVar32 + DAT_140526070) * dVar32 * dVar43 +
                  ((DAT_1405260b0 * dVar32 + DAT_1405260a0) * dVar32 + DAT_140526090) * dVar32 *
                  dVar43 * dVar43 + (dVar33 - dVar45) + dVar51 +
                 dVar33 * dVar44 + dVar44 * dVar44 * DAT_140526060 + dVar44);
        dVar44 = dVar51 - dVar45;
        dVar43 = *(double *)(&DAT_14052bd70 + (longlong)dVar29 * 8) + DAT_140526000 * dVar61;
      }
      else {
        dVar43 = dVar43 - dVar51;
        dVar44 = dVar43 * *(double *)(&DAT_140526100 + (longlong)dVar29 * 8);
        dVar43 = dVar43 * *(double *)(&DAT_140526910 + (longlong)dVar29 * 8);
        dVar45 = dVar44 + dVar43;
        dVar51 = dVar45 * dVar45;
        dVar51 = *(double *)(&DAT_14052c580 + (longlong)dVar29 * 8) +
                 (DAT_140526010 * dVar61 -
                 ((DAT_140526070 * dVar45 + DAT_140526060) * dVar51 +
                  ((DAT_1405260a0 * dVar45 + DAT_140526090) * dVar45 + DAT_140526080) *
                  dVar51 * dVar51 + dVar43 + (dVar44 - dVar45)));
        dVar44 = dVar51 - dVar45;
        dVar43 = *(double *)(&DAT_14052bd70 + (longlong)dVar29 * 8) + DAT_140526000 * dVar61;
      }
      dVar32 = dVar43 + dVar44;
      dVar33 = (double)((ulonglong)dVar32 & _DAT_140525f60);
      dVar61 = (double)((ulonglong)param_2 & _DAT_140525f60);
      dVar43 = (dVar43 - dVar32) + dVar44 + (dVar51 - (dVar45 + dVar44)) + (dVar32 - dVar33);
      dVar51 = (param_2 - dVar61) * dVar43 + (param_2 - dVar61) * dVar33 + dVar43 * dVar61;
      dVar43 = dVar33 * dVar61 + dVar51;
      dVar45 = DAT_140527190 * dVar43;
      param_2 = dVar29;
      if (dVar45 <= DAT_140527170) {
        if (dVar45 < DAT_140527180) {
          local_88 = (double)(DAT_140527140 | (ulonglong)local_88);
          goto LAB_1403321e0;
        }
        uVar59 = (uint)dVar45;
        uVar28 = (ulonglong)(uVar59 & 0x3f);
        uVar26 = (int)(uVar59 - (uVar59 & 0x3f)) >> 6;
        dVar45 = (dVar43 - DAT_1405271a0 * (double)(int)uVar59) +
                 (double)(int)uVar59 * DAT_1405271b0 + (dVar33 * dVar61 - dVar43) + dVar51;
        dVar51 = dVar45 * dVar45 * dVar45;
        dVar51 = (DAT_140527200 * dVar45 + DAT_140526030) * dVar45 +
                 (DAT_1405271e0 * dVar45 + DAT_1405271f0) * dVar51 +
                 (DAT_1405271c0 * dVar45 + DAT_1405271d0) * dVar45 * dVar45 * dVar51;
        uVar59 = 0;
        if ((int)uVar26 <= (int)DAT_140527120) {
          uVar59 = uVar26;
        }
        param_1 = (double)((ulonglong)uVar26 + 0x3ff << 0x34);
        dVar51 = *(double *)(&DAT_14052a120 + uVar28 * 8) * dVar51 +
                 *(double *)(&DAT_14052a320 + uVar28 * 8) * dVar51 +
                 *(double *)(&DAT_14052a320 + uVar28 * 8) + *(double *)(&DAT_14052a120 + uVar28 * 8)
        ;
        if (param_1 != DAT_140525fb0) {
          if (uVar59 == 0) {
            return;
          }
          dVar45 = (double)(ulonglong)uVar59;
          uVar26 = 0;
          if (DAT_140526030 <= dVar51) {
            uVar26 = uVar59;
          }
          if (uVar26 == DAT_140527120) {
            return;
          }
          dVar61 = DAT_140527150;
          if ((longlong)dVar43 <= DAT_140527160) {
            iVar27 = uVar59 + 0x432;
            if (iVar27 < 0) {
              iVar27 = 0;
            }
            dVar45 = (double)(1L << ((byte)iVar27 & 0x3f));
            dVar61 = dVar51 * dVar45;
          }
          FUN_140340690(dVar45,dVar43,(ulonglong)dVar61 | (ulonglong)local_88,DAT_140525e7c);
          return;
        }
        if (dVar51 < DAT_140526030) {
          return;
        }
      }
      local_88 = (double)((ulonglong)DAT_140525fb0 | (ulonglong)local_88);
LAB_1403321e0:
      uVar14 = DAT_140525e78;
      if ((DAT_140525ed8 & (ulonglong)local_88) != 0) {
        uVar14 = DAT_140525e80;
      }
      FUN_140340690(param_1,dVar43,param_2,uVar14);
      return;
    }
    goto LAB_140332010;
  }
  if (DAT_140525e90 < (longlong)(DAT_140525eb0 & (ulonglong)param_2)) {
LAB_140331fc0:
    if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_1403320c0;
    if ((DAT_140525ed8 & (ulonglong)dVar43) == 0) goto LAB_140332010;
    if (dVar43 != DAT_140525f08) {
      if ((longlong)((ulonglong)dVar43 & DAT_140525ed8) < (longlong)DAT_140525ec8) {
        local_88 = 0.0;
        if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) != 0) {
          local_88 = DAT_140525ec0;
        }
      }
      else {
        local_88 = 0.0;
        if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) == 0) {
          local_88 = DAT_140525ec0;
        }
      }
      dVar51 = 0.0;
      if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
        dVar51 = param_2;
      }
      if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
        if (dVar51 != 0.0) {
          return;
        }
        goto LAB_1403321e0;
      }
      goto LAB_140332280;
    }
LAB_140331f20:
    dVar43 = (double)((ulonglong)DAT_140525ec8 | (ulonglong)local_88);
    dVar51 = 0.0;
    if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
      dVar51 = param_2;
    }
  }
  else {
    uVar28 = DAT_140525ed8 & (ulonglong)param_2;
    param_1 = (double)((uVar28 >> (SUB81(DAT_140525f18,0) & 0x3f)) - _DAT_140525f20);
    dVar51 = DAT_140525f18;
    if ((longlong)param_1 < 0) {
LAB_140331f70:
      param_1 = dVar51;
      if ((DAT_140525eb0 & (ulonglong)dVar43) == DAT_140525eb0) goto LAB_1403320c0;
      if (dVar43 != DAT_140525f10) {
        FUN_140340690(param_1,dVar43,param_2,DAT_140525e74);
        return;
      }
    }
    else {
      dVar45 = (double)(DAT_140525ed8 & (ulonglong)dVar43);
      if ((longlong)param_1 <= DAT_140525f30) {
        dVar51 = param_1;
        if ((DAT_140525f38 >> (SUB81(param_1,0) & 0x3f) & uVar28) != 0) goto LAB_140331f70;
        if ((DAT_140525f40 >> (SUB81(param_1,0) & 0x3f) & uVar28) != 0) {
          local_88 = DAT_140525ea0;
        }
      }
      if (dVar43 != DAT_140525f10) {
        if (dVar43 == DAT_140525f08) goto LAB_140331f20;
        if ((DAT_140525eb0 & (ulonglong)dVar43) != DAT_140525eb0) goto LAB_1403317d5;
LAB_1403320c0:
        if ((DAT_140525ee0 & (ulonglong)dVar43) != 0) {
LAB_140332230:
          dVar51 = 0.0;
          if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
            dVar51 = param_2;
          }
          if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
            FUN_140340690(param_1,dVar43,param_2,DAT_140525e68);
            return;
          }
          FUN_140340690(param_1,dVar43,param_2,DAT_140525e70);
          return;
        }
        dVar51 = 0.0;
        if ((DAT_140525eb0 & (ulonglong)param_2) == DAT_140525eb0) {
          dVar51 = param_2;
        }
        goto joined_r0x0001403320a5;
      }
    }
LAB_140332010:
    if ((DAT_140525eb0 & (ulonglong)param_2) != DAT_140525eb0) {
      if (((ulonglong)DAT_140525ea0 & (ulonglong)param_2) == 0) {
        return;
      }
LAB_140332050:
      FUN_140340690(param_1,dVar43,param_2,DAT_140525e64);
      return;
    }
    dVar51 = param_2;
    if (param_2 == DAT_140525eb8) goto LAB_140332050;
  }
joined_r0x0001403320a5:
  if ((DAT_140525ee0 & (ulonglong)dVar51) == 0) {
    return;
  }
LAB_140332280:
  FUN_140340690(param_1,dVar43,param_2,DAT_140525e6c);
  return;
}


