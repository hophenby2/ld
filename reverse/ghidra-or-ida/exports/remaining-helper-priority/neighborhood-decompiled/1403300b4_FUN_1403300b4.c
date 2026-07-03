// Function: FUN_1403300b4 @ 1403300b4
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_1403300b4(double param_1,double param_2)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  uint uVar12;
  double dVar13;
  double dVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uVar20;
  
  uVar17 = SUB84(param_1,0);
  uVar18 = (uint)((ulonglong)param_1 >> 0x20);
  uVar16 = (uint)((ulonglong)param_2 >> 0x20);
  uVar7 = uVar16 >> 0x14 & 0x7ff;
  uVar19 = SUB84(param_2,0);
  uVar12 = uVar18 >> 0x14 & 0x7ff;
  dVar11 = ABS(param_2);
  iVar8 = uVar12 - uVar7;
  dVar10 = ABS(param_1);
  dVar13 = param_2;
  if ((0x7ff0000000000000 < (ulonglong)dVar11) ||
     (dVar13 = param_1, 0x7ff0000000000000 < (ulonglong)dVar10)) {
    dVar13 = (double)_handle_nan(dVar13);
    return dVar13;
  }
  uVar6 = 0;
  if (dVar10 == 0.0) {
    if (-1 < (longlong)param_2) {
      return param_1;
    }
LAB_140330180:
    if ((longlong)param_1 < 0) {
      uVar15 = (undefined4)DAT_140525a20;
      uVar16 = (uint)((ulonglong)DAT_140525a20 >> 0x20);
    }
    else {
      uVar15 = (undefined4)DAT_1404a7e60;
      uVar16 = (uint)((ulonglong)DAT_1404a7e60 >> 0x20);
    }
  }
  else if (dVar11 == 0.0) {
    if (-1 < (longlong)param_1) {
      _set_statfp(0x20);
      goto LAB_1403301c0;
    }
LAB_1403302bc:
    uVar15 = (undefined4)DAT_1404a7ea8;
    uVar16 = (uint)((ulonglong)DAT_1404a7ea8 >> 0x20);
  }
  else {
LAB_1403301c0:
    if ((uVar7 < 0x3fd) && (uVar12 < 0x3fd)) {
      if (((ulonglong)param_2 & 0x7ff0000000000000) == 0) {
        dVar13 = DAT_14053b0b0;
        if ((longlong)param_2 < 0) {
          dVar13 = DAT_14053a070;
        }
        dVar13 = (double)((ulonglong)param_2 | 0x4010000000000000) + dVar13;
      }
      else {
        dVar13 = (double)((longlong)param_2 + 0x4000000000000000);
      }
      if (((ulonglong)param_1 & 0x7ff0000000000000) == 0) {
        dVar14 = DAT_14053b0b0;
        if ((longlong)param_1 < 0) {
          dVar14 = DAT_14053a070;
        }
        dVar14 = (double)((ulonglong)param_1 | 0x4010000000000000) + dVar14;
      }
      else {
        dVar14 = (double)((longlong)param_1 + 0x4000000000000000);
      }
      uVar19 = SUB84(dVar13,0);
      uVar16 = (uint)((ulonglong)dVar13 >> 0x20);
      uVar17 = SUB84(dVar14,0);
      uVar18 = (uint)((ulonglong)dVar14 >> 0x20);
      iVar8 = (uVar18 >> 0x14 & 0x7ff) - (uVar16 >> 0x14 & 0x7ff);
    }
    if (iVar8 < 0x39) {
      if ((iVar8 < -0x1c) && (-1 < (longlong)param_2)) {
        if (iVar8 < -0x432) {
          if ((longlong)param_1 < 0) {
            uVar15 = (undefined4)DAT_140525a08;
            uVar16 = (uint)((ulonglong)DAT_140525a08 >> 0x20);
          }
          else {
            uVar15 = 0;
            uVar16 = 0;
          }
        }
        else {
          if (-0x3ff < iVar8) {
            return (double)CONCAT44(uVar18,uVar17) / (double)CONCAT44(uVar16,uVar19);
          }
          dVar13 = ((double)CONCAT44(uVar18,uVar17) * 1.2676506002282294e+30) /
                   (double)CONCAT44(uVar16,uVar19);
          uVar3 = (ulonglong)ABS(dVar13) >> 0x34;
          uVar16 = (uint)((ulonglong)ABS(dVar13) >> 0x34);
          if (uVar16 < 0x65) {
            if ((int)(0x65 - uVar16) < 0x37) {
              uVar6 = ((ulonglong)dVar13 & 0x1fffffffffffff | 0x10000000000000) >>
                      (100U - (char)uVar3 & 0x3f);
              uVar6 = (uVar6 >> 1) + (ulonglong)((uint)uVar6 & 1);
            }
          }
          else {
            uVar6 = uVar3 - 100 << 0x34 | (ulonglong)dVar13 & 0xfffffffffffff;
          }
          uVar16 = (uint)(uVar6 >> 0x20) | (uint)((ulonglong)dVar13 >> 0x20) & 0x80000000;
          uVar15 = (undefined4)uVar6;
          if ((uVar6 & 0x7ff0000000000000) != 0) goto LAB_1403303ee;
        }
      }
      else {
        if ((iVar8 < -0x38) && ((longlong)param_2 < 0)) goto LAB_140330180;
        if ((dVar10 != INFINITY) || (dVar11 != INFINITY)) {
          if ((longlong)param_2 < 0) {
            uVar19 = uVar19 ^ ram0x00014053bef0;
            uVar16 = uVar16 ^ _UNK_14053bef4;
          }
          if ((longlong)param_1 < 0) {
            uVar17 = uVar17 ^ ram0x00014053bef0;
            uVar18 = uVar18 ^ _UNK_14053bef4;
          }
          bVar1 = (double)CONCAT44(uVar18,uVar17) != (double)CONCAT44(uVar16,uVar19);
          bVar2 = (double)CONCAT44(uVar16,uVar19) <= (double)CONCAT44(uVar18,uVar17);
          uVar7 = uVar17;
          uVar12 = uVar18;
          if (bVar2 && bVar1) {
            uVar7 = uVar19;
            uVar12 = uVar16;
            uVar19 = uVar17;
            uVar16 = uVar18;
          }
          dVar13 = (double)CONCAT44(uVar12,uVar7) / (double)CONCAT44(uVar16,uVar19);
          if (dVar13 <= DAT_140539e38) {
            uVar15 = 0;
            uVar20 = 0;
            if (DAT_1404a7e30 <= dVar13) {
              dVar11 = dVar13 * dVar13;
              dVar10 = (double)((ulonglong)dVar13 & 0xffffffff00000000);
              dVar13 = dVar13 + (((((double)CONCAT44(uVar12,uVar7) -
                                   dVar10 * (double)((ulonglong)uVar16 << 0x20)) -
                                  ((double)CONCAT44(uVar16,uVar19) -
                                  (double)((ulonglong)uVar16 << 0x20)) * dVar10) -
                                 (dVar13 - dVar10) * (double)CONCAT44(uVar16,uVar19)) /
                                 (double)CONCAT44(uVar16,uVar19) -
                                (DAT_1405259f0 -
                                (DAT_1405259e0 -
                                (DAT_1405259d0 - (DAT_1405259c8 - dVar11 * _DAT_1405259c0) * dVar11)
                                * dVar11) * dVar11) * dVar11 * dVar13);
            }
          }
          else {
            uVar17 = (uint)(dVar13 * DAT_14053a600 + DAT_140539f00);
            uVar6 = (ulonglong)(uVar17 - 0x10);
            uVar15 = (undefined4)*(undefined8 *)(&DAT_140524aa0 + uVar6 * 8);
            uVar20 = (undefined4)((ulonglong)*(undefined8 *)(&DAT_140524aa0 + uVar6 * 8) >> 0x20);
            iVar9 = 0x3ff - (uVar16 >> 0x14 & 0x7ff);
            dVar13 = (double)uVar17 * _DAT_1404abe30;
            iVar8 = iVar9 / 2;
            lVar5 = (longlong)iVar8 << 0x34;
            lVar4 = (longlong)(iVar9 - iVar8) << 0x34;
            dVar11 = (double)(lVar5 + 0x3ff0000000000000) * (double)CONCAT44(uVar16,uVar19) *
                     (double)(lVar4 + 0x3ff0000000000000);
            dVar10 = (double)(lVar5 + 0x3ff0000000000000) * (double)CONCAT44(uVar12,uVar7) *
                     (double)(lVar4 + 0x3ff0000000000000);
            dVar13 = ((dVar10 - (double)((ulonglong)dVar11 & 0xfffffffff8000000) * dVar13) -
                     (dVar11 - (double)((ulonglong)dVar11 & 0xfffffffff8000000)) * dVar13) /
                     (dVar13 * dVar10 + dVar11);
            dVar13 = (dVar13 + *(double *)(&DAT_140525230 + uVar6 * 8)) -
                     (DAT_1405259e8 - dVar13 * dVar13 * _DAT_1405259d8) * dVar13 * dVar13 * dVar13;
          }
          dVar10 = (double)CONCAT44(uVar20,uVar15);
          if (bVar2 && bVar1) {
            dVar10 = DAT_1404a7e58 - (double)CONCAT44(uVar20,uVar15);
            dVar13 = DAT_140524a30 - dVar13;
          }
          if ((longlong)param_2 < 0) {
            dVar10 = DAT_140525a00 - dVar10;
            dVar13 = DAT_1405259b8 - dVar13;
          }
          dVar10 = dVar10 + dVar13;
          if (-1 < (longlong)param_1) {
            return dVar10;
          }
          return (double)CONCAT44((uint)((ulonglong)dVar10 >> 0x20) ^ _UNK_14053bef4,
                                  SUB84(dVar10,0) ^ ram0x00014053bef0);
        }
        if ((longlong)param_2 < 0) {
          if ((longlong)param_1 < 0) {
            uVar15 = (undefined4)DAT_140525a18;
            uVar16 = (uint)((ulonglong)DAT_140525a18 >> 0x20);
          }
          else {
            uVar15 = (undefined4)DAT_1405259f8;
            uVar16 = (uint)((ulonglong)DAT_1405259f8 >> 0x20);
          }
        }
        else if ((longlong)param_1 < 0) {
          uVar15 = (undefined4)DAT_140525a10;
          uVar16 = (uint)((ulonglong)DAT_140525a10 >> 0x20);
        }
        else {
          uVar15 = (undefined4)DAT_140524a98;
          uVar16 = (uint)((ulonglong)DAT_140524a98 >> 0x20);
        }
      }
    }
    else {
      if ((longlong)param_1 < 0) goto LAB_1403302bc;
      uVar15 = SUB84(DAT_1404a7e58,0);
      uVar16 = (uint)((ulonglong)DAT_1404a7e58 >> 0x20);
    }
  }
  _set_statfp(0x20);
LAB_1403303ee:
  return (double)CONCAT44(uVar16,uVar15);
}


