// Function: FUN_1401367e0 @ 1401367e0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401367e0(short *param_1,ushort *param_2,longlong param_3,ushort *param_4)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  short *psVar4;
  short sVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  short sVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  int iVar16;
  longlong *plVar17;
  uint uVar18;
  uint uVar19;
  ulonglong uVar20;
  ushort *puVar21;
  undefined1 auStack_1898 [32];
  longlong local_1878;
  short *local_1870;
  undefined4 local_1868;
  int local_1864 [3];
  ushort local_1858 [1536];
  ushort local_c58 [1536];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_1898;
  uVar13 = 0;
  uVar18 = 0;
  local_1878 = param_3;
  local_1870 = param_1;
  if (param_4 == (ushort *)0x0) {
    if (PTR_FUN_14056c0b0 == (undefined *)0x0) {
      (*(code *)PTR_FUN_14056c0a8)(local_c58);
    }
    else {
      (*(code *)PTR_FUN_14056c0b0)(local_c58,0xc00);
    }
    param_4 = local_c58;
  }
  lVar10 = local_1878;
  if (param_1 == (short *)0x0) goto LAB_140136e13;
  local_1868 = 0;
  if (((*param_1 == 0x5c) && (param_1[1] == 0x5c)) ||
     ((uVar20 = uVar13, bVar3 = false, *param_1 == 0x2f &&
      (uVar20 = 0, bVar3 = false, param_1[1] == 0x2f)))) {
    param_2[0] = 0x5c;
    param_2[1] = 0x5c;
    uVar20 = 2;
    param_2[2] = 0;
    bVar3 = true;
  }
  uVar19 = (uint)uVar20;
  if (!bVar3) {
    if (0 < (int)DAT_14098ec00) {
      plVar17 = &DAT_14098ec10;
      uVar12 = uVar13;
      do {
        uVar18 = (uint)uVar12;
        uVar12 = 0;
        uVar13 = uVar12;
        if (*param_1 != 0) {
          do {
            cVar1 = *(char *)(uVar12 + *plVar17);
            if (cVar1 == '\0') break;
            sVar11 = param_1[uVar12];
            if ((sVar11 == 0x5c) || (sVar11 == 0x2f)) {
              sVar11 = 0x5c;
            }
            if ((cVar1 == '\\') || (sVar5 = (short)cVar1, cVar1 == '/')) {
              sVar5 = 0x5c;
            }
            if (sVar11 != sVar5) break;
            uVar12 = uVar12 + 1;
            uVar13 = (ulonglong)((int)uVar13 + 1);
          } while (param_1[uVar12] != 0);
        }
        if (*(char *)(uVar12 + *plVar17) == '\0') break;
        uVar18 = uVar18 + 1;
        uVar12 = (ulonglong)uVar18;
        plVar17 = plVar17 + 1;
      } while ((int)uVar18 < (int)DAT_14098ec00);
    }
    uVar15 = (uint)uVar13;
    uVar12 = 0;
    if ((DAT_14098ec00 == 0) || (uVar18 == DAT_14098ec00)) {
      uVar18 = 0;
      sVar11 = *param_1;
      uVar13 = uVar12;
      while (sVar11 != 0) {
        uVar18 = (uint)uVar13;
        uVar2 = param_1[uVar12];
        if ((uVar2 & 0xfc00) == 0xd800) {
          lVar10 = 2;
        }
        else {
          if ((uVar2 == 0x3a) ||
             (((0x19 < (ushort)(uVar2 - 0x61) && (0x19 < (ushort)(uVar2 - 0x41))) &&
              (9 < (ushort)(uVar2 - 0x30))))) break;
          lVar10 = 1;
        }
        uVar12 = uVar12 + lVar10;
        uVar18 = uVar18 + (int)lVar10;
        uVar13 = (ulonglong)uVar18;
        sVar11 = param_1[uVar12];
      }
      if (param_1[(int)uVar18] != 0x3a) goto LAB_140136a6d;
      uVar19 = uVar18 + 1;
      lVar10 = (longlong)(int)uVar19;
      FUN_1401ae2f0(param_2,param_1,lVar10 * 2);
      uVar13 = (ulonglong)uVar19;
      param_2[lVar10] = 0;
      if ((param_1[lVar10] == 0x5c) || (param_1[lVar10] == 0x2f)) {
        uVar19 = uVar18 + 2;
      }
    }
    else {
      if (0 < (int)uVar15) {
        do {
          param_2[uVar12] = (short)*(char *)(uVar12 + (&DAT_14098ec10)[(int)uVar18]);
          uVar12 = uVar12 + 1;
        } while ((longlong)uVar12 < (longlong)(int)uVar15);
      }
      param_2[(int)uVar15] = 0;
      uVar19 = uVar15;
    }
    bVar3 = true;
    uVar20 = uVar13;
  }
LAB_140136a6d:
  psVar4 = local_1870;
  uVar13 = 0;
  uVar12 = 0;
  if (DAT_14056db60 == 1) {
    uVar14 = 0;
    if (!bVar3) {
      if ((*local_1870 != 0x5c) && (*local_1870 != 0x2f)) goto LAB_140136ace;
      uVar20 = 2;
      *param_2 = *param_4;
      uVar19 = uVar19 + 1;
      param_2[1] = param_4[1];
      param_2[2] = 0;
      uVar14 = 1;
    }
  }
  else {
    uVar14 = uVar12;
    if (!bVar3) {
LAB_140136ace:
      FUN_1401aeb80(param_2,local_1878,param_4);
      uVar2 = *param_2;
      uVar20 = 0;
      while (uVar2 != 0) {
        uVar20 = uVar20 + 1;
        uVar2 = param_2[uVar20];
      }
      if (DAT_1408ab148 == 0) {
        FUN_1401c6d60();
      }
      iVar16 = FUN_1401c55b0(param_4,DAT_1408ab148);
      uVar14 = uVar12;
      if (iVar16 != 0) {
        if (DAT_1408ab148 == 0) {
          FUN_1401c6d60();
        }
        puVar7 = (undefined2 *)FUN_1401c5230(param_4,DAT_1408ab148,iVar16 + -1);
        if (DAT_1408ab148 == 0) {
          FUN_1401c6d60();
        }
        iVar16 = FUN_1401c4e50(puVar7,DAT_1408ab148,local_1864);
        if ((iVar16 == 0x5c) || (iVar16 == 0x2f)) {
          *puVar7 = 0;
          uVar20 = (ulonglong)((int)uVar20 - 1);
        }
      }
    }
  }
  uVar12 = 0;
  puVar21 = (ushort *)(psVar4 + (int)uVar19);
  uVar2 = psVar4[(int)uVar19];
  lVar10 = local_1878;
  if (uVar2 == 0) {
    return 0;
  }
  do {
    iVar16 = (int)uVar20;
    if ((uVar2 == 0x2f) || (uVar2 == 0x5c)) {
      if (uVar12 != 0) {
        iVar6 = FUN_1401aeb00(local_1858,&DAT_1404a75e0);
        if (iVar6 != 0) {
          iVar6 = FUN_1401aeb00(local_1858,&DAT_1404a75e4);
          if (iVar6 == 0) {
            param_2[iVar16] = 0;
            if (DAT_1408ab148 == 0) {
              FUN_1401c6d60();
            }
            iVar6 = FUN_1401c55b0(param_2,DAT_1408ab148);
            if (DAT_1408ab148 == 0) {
              FUN_1401c6d60();
            }
            iVar6 = iVar6 + -1;
            uVar8 = FUN_1401c5230(param_2,DAT_1408ab148,iVar6);
            if (DAT_1408ab148 == 0) {
              FUN_1401c6d60();
            }
            FUN_1401c4e50(uVar8,DAT_1408ab148,local_1864);
            uVar18 = iVar16 - (int)((ulonglong)(longlong)local_1864[0] >> 1);
            lVar9 = (longlong)(int)uVar18;
            uVar2 = param_2[lVar9];
            while (uVar20 = (ulonglong)uVar18, uVar2 != 0x5c) {
              uVar2 = param_2[lVar9];
              lVar10 = local_1878;
              if ((uVar2 == 0x2f) || (uVar2 == 0x3a)) break;
              param_2[lVar9] = 0;
              iVar6 = iVar6 + -1;
              if (DAT_1408ab148 == 0) {
                FUN_1401c6d60();
              }
              uVar8 = FUN_1401c5230(param_2,DAT_1408ab148,iVar6);
              if (DAT_1408ab148 == 0) {
                FUN_1401c6d60();
              }
              FUN_1401c4e50(uVar8,DAT_1408ab148,local_1864);
              uVar18 = uVar18 - (int)((ulonglong)(longlong)local_1864[0] >> 1);
              lVar9 = (longlong)(int)uVar18;
              lVar10 = local_1878;
              uVar2 = param_2[lVar9];
            }
            if (param_2[(int)uVar18] == 0x3a) {
              uVar20 = (ulonglong)(uVar18 + 1);
            }
            else {
              param_2[(int)uVar18] = 0;
            }
          }
          else {
            if ((((uVar14 == 0) && ((*psVar4 == 0x5c || (*psVar4 == 0x2f)))) || (iVar16 != 0)) &&
               (((0 < iVar16 && (param_2[iVar16 + -1] != 0x5c)) && (param_2[iVar16 + -1] != 0x2f))))
            {
              lVar9 = (longlong)iVar16;
              iVar16 = iVar16 + 1;
              param_2[lVar9] = 0x5c;
            }
            FUN_1401aeb80(param_2 + iVar16,lVar10 + (longlong)iVar16 * -2,local_1858);
            uVar18 = FUN_140139fa0(param_2);
            uVar20 = (ulonglong)uVar18;
          }
        }
        uVar12 = 0;
        uVar13 = uVar12;
      }
LAB_140136dd5:
      puVar21 = puVar21 + 1;
    }
    else {
      uVar2 = *puVar21;
      local_1858[uVar12] = uVar2;
      if ((uVar2 & 0xfc00) != 0xd800) {
        if (0xbff < uVar12 * 2 + 2) {
                    /* WARNING: Subroutine does not return */
          FUN_14031c688();
        }
        local_1858[uVar12 + 1] = 0;
        uVar12 = uVar12 + 1;
        uVar13 = (ulonglong)((int)uVar13 + 1);
        goto LAB_140136dd5;
      }
      local_1858[uVar12 + 1] = puVar21[1];
      uVar12 = uVar12 + 2;
      if (0xbff < uVar12 * 2) {
                    /* WARNING: Subroutine does not return */
        FUN_14031c688();
      }
      uVar13 = (ulonglong)((int)uVar13 + 2);
      local_1858[uVar12] = 0;
      puVar21 = puVar21 + 2;
    }
    iVar16 = (int)uVar20;
    uVar2 = *puVar21;
  } while (uVar2 != 0);
  if ((int)uVar13 == 0) {
    return 0;
  }
  if (iVar16 != 0) {
    lVar10 = (longlong)iVar16;
    iVar16 = iVar16 + 1;
    param_2[lVar10] = 0x5c;
  }
  param_4 = local_1858;
  param_2 = param_2 + iVar16;
  lVar10 = local_1878 + (longlong)iVar16 * -2;
LAB_140136e13:
  FUN_1401aeb80(param_2,lVar10,param_4);
  return 0;
}


