// Function: FUN_1401160b0 @ 1401160b0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401160b0(void)

{
  undefined1 uVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  int iVar15;
  longlong lVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  int local_res8;
  undefined8 in_stack_fffffffffffffec8;
  undefined8 uVar21;
  undefined1 local_b8 [3];
  undefined1 uStack_b5;
  undefined1 uStack_b4;
  undefined1 uStack_b3;
  undefined1 uStack_b2;
  undefined1 uStack_b1;
  undefined1 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  
  uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  FUN_14017a940(0xff,0xff,0xff);
  fVar2 = DAT_14053ad80;
  lVar8 = (longlong)(int)DAT_140e47434;
  lVar14 = (&DAT_140e8cf98)[lVar8 * 0x153];
  local_res8 = (&DAT_140e8cf80)[lVar8 * 0x2a6] + -1;
  iVar6 = (&DAT_140e8cf84)[lVar8 * 0x2a6];
  iVar15 = iVar6;
  if (9 < iVar6) {
    iVar15 = 9;
  }
  fVar20 = (float)(int)(DAT_140e47434 * 0x19 + 0x5a);
  fVar18 = DAT_14053adb4;
  fVar19 = DAT_14053ad80;
  if (DAT_140e418c8 < 0x20) {
    dVar17 = (double)FUN_140332d90();
    fVar19 = (float)(dVar17 * (double)(float)((uint)(fVar20 - fVar2) ^ DAT_14053bf00)) + fVar20;
    dVar17 = (double)FUN_140332d90();
    fVar18 = (float)(dVar17 * _DAT_14053b290) + DAT_14053afb0;
  }
  if (DAT_140e45fac < 0) {
    dVar17 = (double)FUN_140332d90();
    fVar19 = (float)(dVar17 * (double)(fVar20 - fVar2)) + fVar2;
    dVar17 = (double)FUN_140332d90();
    fVar18 = (float)(dVar17 * _DAT_14053b290) + DAT_14053adb4;
  }
  if ((&DAT_140e8cf58)[lVar8 * 0x2a6] == 1) {
    local_res8 = iVar6 + -1;
    if ((&DAT_140e8cfa4)[(longlong)(int)DAT_140e47434 * 0x2a6] == 1) {
      local_res8 = 9;
    }
    else if ((&DAT_140e8cfa4)[(longlong)(int)DAT_140e47434 * 0x2a6] == 2) {
      local_res8 = 10;
    }
    if ((&DAT_140e8cf80)[(longlong)(int)DAT_140e47434 * 0x2a6] == 10) {
      local_res8 = 0xb;
    }
  }
  if ((&DAT_140e8cf68)[(longlong)(int)DAT_140e47434 * 0x2a6] == 1) {
    lVar14 = (longlong)(int)(&DAT_140e8cfa0)[(longlong)(int)DAT_140e47434 * 0x2a6];
  }
  uVar21 = (&DAT_140e8cf50)[(longlong)(int)DAT_140e47434 * 0x153];
  FUN_140116940((&DAT_140e9fd40)[(int)DAT_140e47434],DAT_140e47434 + 1,DAT_14053ade0,fVar19,
                CONCAT44(uVar4,0xff),uVar21,&DAT_140e8cf48 + (longlong)(int)DAT_140e47434 * 0xa98,
                (&DAT_140e8cf58)[lVar8 * 0x2a6],
                (&DAT_140e8cf5c)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf6c)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf70)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf74)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf78)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf7c)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf60)[(longlong)(int)DAT_140e47434 * 0x2a6],
                (&DAT_140e8cf64)[(longlong)(int)DAT_140e47434 * 0x2a6],lVar14,local_res8,
                (&DAT_140e8cf68)[(longlong)(int)DAT_140e47434 * 0x2a6]);
  dVar17 = DAT_140539fb0;
  if (DAT_140e45fac < 0x40) {
    uVar10 = (ulonglong)(int)DAT_140e47434;
    iVar6 = 8;
    if (DAT_140e467e8 != 0) {
      iVar6 = DAT_140e467e8;
    }
    if (8 < (int)(&DAT_140e8cf84)[uVar10 * 0x2a6]) {
      iVar6 = 9;
    }
    if ((&DAT_140e8cf80)[uVar10 * 0x2a6] == 10) {
      uVar21 = (&DAT_140e8cf98)[uVar10 * 0x153];
      uVar4 = FUN_14017a940(0xff,0xff,0xff);
      if ((0 < DAT_140e45fac) &&
         (DAT_140e45fac ==
          (DAT_140e45fac / 3 + (DAT_140e45fac >> 0x1f) +
          (int)(((longlong)DAT_140e45fac / 3 + ((longlong)DAT_140e45fac >> 0x3f) & 0xffffffffU) >>
               0x1f)) * 3)) {
        uVar4 = FUN_14017a940(0x80,0x80,0x80);
      }
      FUN_14015b020(0x1e0,(int)(fVar18 + DAT_14053aca8),uVar4,DAT_140e46bec,"Stage Ex : %12lld",
                    uVar21);
    }
    else {
      iVar11 = 1;
      if (0 < (longlong)iVar6) {
        lVar16 = (longlong)iVar15;
        lVar8 = 1;
        iVar15 = 0x28;
        do {
          uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
          iVar9 = (int)uVar10;
          lVar5 = (longlong)iVar9;
          iVar13 = 0;
          if ((((&DAT_140e8cf58)[lVar5 * 0x2a6] & 0xfffffffd) == 0) &&
             (iVar13 = 0, (&DAT_140e8cf80)[lVar5 * 0x2a6] == iVar11)) {
            iVar13 = 1;
          }
          if (((&DAT_140e8cf58)[lVar5 * 0x2a6] == 1) && (lVar8 <= lVar16)) {
            lVar14 = (longlong)iVar9;
            if ((&DAT_140e8cf68)[lVar5 * 0x2a6] == 0) {
              if (lVar8 < lVar16) {
                lVar14 = *(longlong *)(&DAT_140e8d938 + (lVar14 * 0x153 + lVar8) * 8);
              }
              else {
                lVar14 = (&DAT_140e8cf98)[lVar14 * 0x153];
              }
            }
            else if (lVar8 < lVar16) {
              lVar14 = *(longlong *)(&DAT_140e8d988 + (lVar14 * 0x153 + lVar8) * 8);
            }
            else {
              lVar14 = (longlong)(int)(&DAT_140e8cfa0)[lVar14 * 0x2a6];
            }
            iVar7 = -1;
            if (iVar11 - 2U < 2) {
              iVar7 = 0;
            }
            if (iVar11 - 4U < 2) {
              iVar7 = 1;
            }
            if (iVar11 == 6) {
LAB_14011654c:
              lVar5 = -1;
              if (iVar11 - 2U < 2) {
                lVar5 = 0;
              }
              if (iVar11 - 4U < 2) {
                lVar5 = 1;
              }
              if (iVar11 - 6U < 2) {
LAB_14011656f:
                lVar5 = 2;
              }
              if ((*(int *)(&DAT_140e8cf88 + ((longlong)iVar9 * 0x2a6 + lVar5) * 4) != iVar11) &&
                 ((&DAT_140e8cf5c)[(longlong)iVar9 * 0x2a6] == 0)) goto LAB_1401165a4;
            }
            else {
              if (iVar11 == 7) goto LAB_14011656f;
              if (iVar7 != -1) goto LAB_14011654c;
            }
            iVar13 = 1;
          }
LAB_1401165a4:
          uVar3 = FUN_14017a940(0xff,0xff,0xff);
          if ((DAT_1407c7798 != iVar11) ||
             ((0 < DAT_140e45fac &&
              (DAT_140e45fac ==
               (DAT_140e45fac / 3 + (DAT_140e45fac >> 0x1f) +
               (int)(((longlong)DAT_140e45fac / 3 + ((longlong)DAT_140e45fac >> 0x3f) & 0xffffffffU)
                    >> 0x1f)) * 3)))) {
            uVar3 = FUN_14017a940(0x80,0x80,0x80);
          }
          if (iVar13 == 1) {
            if ((&DAT_140e8cf68)[(longlong)(int)DAT_140e47434 * 0x2a6] == 0) {
              uVar21 = CONCAT44(uVar4,iVar11);
              FUN_14015b020(0x1e0,(int)((float)iVar15 + fVar18),uVar3,DAT_140e46bec,
                            "Stage %d : %12lld",uVar21,lVar14);
            }
            else {
              iVar13 = (int)lVar14;
              local_b0 = DAT_140539cb8;
              local_a8 = 0x33323130;
              local_a4 = 0x37363534;
              local_a0 = 0x3938;
              if (iVar13 < 0xe10) {
                local_b8 = (undefined1  [3])0x3a3030;
                if (0x3b < iVar13) goto LAB_140116718;
                _local_b8 = 0x30303a3030;
              }
              else {
                uVar12 = iVar13 / 0xe10;
                iVar13 = iVar13 % 0xe10;
                if ((int)uVar12 < 100) {
                  if (9 < (int)uVar12) goto LAB_1401166c4;
                  uVar1 = 0x30;
                }
                else {
                  uVar12 = 99;
LAB_1401166c4:
                  uVar1 = *(undefined1 *)((longlong)&local_a8 + (ulonglong)uVar12 / 10);
                }
                local_b8._0_2_ =
                     CONCAT11(*(undefined1 *)((longlong)&local_a8 + (longlong)((int)uVar12 % 10)),
                              uVar1);
                local_b8 = (undefined1  [3])CONCAT12(0x3a,local_b8._0_2_);
LAB_140116718:
                iVar9 = iVar13 / 0x3c;
                iVar13 = iVar13 % 0x3c;
                if (iVar9 < 10) {
                  _local_b8 = CONCAT13(0x30,local_b8);
                }
                else {
                  _local_b8 = CONCAT13(*(undefined1 *)((longlong)&local_a8 + (longlong)(iVar9 / 10))
                                       ,local_b8);
                }
                _local_b8 = CONCAT14(*(undefined1 *)((longlong)&local_a8 + (longlong)(iVar9 % 10)),
                                     _local_b8);
              }
              _local_b8 = CONCAT15(0x2e,_local_b8);
              uVar12 = (uint)((double)iVar13 * dVar17);
              if ((int)uVar12 < 100) {
                if (9 < (int)uVar12) goto LAB_1401167b7;
                _local_b8 = CONCAT16(0x30,_local_b8);
              }
              else {
                uVar12 = 99;
LAB_1401167b7:
                _local_b8 = CONCAT16(*(undefined1 *)((longlong)&local_a8 + (ulonglong)uVar12 / 10),
                                     _local_b8);
              }
              _local_b8 = CONCAT17(*(undefined1 *)
                                    ((longlong)&local_a8 + (longlong)((int)uVar12 % 10)),_local_b8);
              uVar21 = CONCAT44(uVar4,iVar11);
              FUN_14015b020(0x1e0,(int)((float)iVar15 + fVar18),uVar3,DAT_140e46bec,"Stage %d : %s",
                            uVar21,local_b8);
            }
          }
          else {
            uVar21 = CONCAT44(uVar4,iVar11);
            FUN_14015b020(0x1e0,(int)((float)iVar15 + fVar18),uVar3,DAT_140e46bec,
                          "Stage %d : ------------",uVar21);
          }
          iVar11 = iVar11 + 1;
          iVar15 = iVar15 + 0x28;
          lVar8 = lVar8 + 1;
          if (iVar6 < lVar8) {
            return;
          }
          uVar10 = (ulonglong)DAT_140e47434;
        } while( true );
      }
    }
  }
  return;
}


