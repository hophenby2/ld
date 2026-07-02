// Function: FUN_1401361f0 @ 1401361f0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1401361f0(char *param_1,byte *param_2,longlong param_3,byte *param_4)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  char cVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  longlong lVar15;
  longlong *plVar16;
  int iVar17;
  int iVar18;
  longlong lVar19;
  undefined1 auStack_18a8 [32];
  undefined8 local_1888;
  int local_1880;
  char *local_1878;
  longlong local_1870;
  int local_1868 [4];
  byte local_1858 [3072];
  undefined1 local_c58 [3072];
  ulonglong local_58;
  
  local_58 = DAT_1407c6b00 ^ (ulonglong)auStack_18a8;
  iVar5 = 0;
  local_1878 = param_1;
  local_1870 = param_3;
  if (param_4 == (byte *)0x0) {
    if (PTR_FUN_14056c0b0 == (undefined *)0x0) {
      (*(code *)PTR_FUN_14056c0a8)(local_c58);
    }
    else {
      (*(code *)PTR_FUN_14056c0b0)();
    }
    if (DAT_1408ab144 == 0) {
      FUN_1401c6d60();
    }
    iVar18 = DAT_1408ab144;
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    local_1880 = iVar18;
    local_1888 = 0x600;
    FUN_1401c0470(local_c58,0xffffffff,DAT_1408ab148,local_1858 + 0x600);
    param_4 = local_1858 + 0x600;
  }
  if (local_1878 == (char *)0x0) {
    FUN_1401ae7d0(param_2,local_1870,param_4);
    return 0;
  }
  iVar18 = 0;
  iVar13 = 0;
  if (((*local_1878 == '\\') && (local_1878[1] == '\\')) ||
     ((*local_1878 == '/' && (local_1878[1] == '/')))) {
    param_2[0] = 0x5c;
    param_2[1] = 0;
    iVar18 = 2;
    iVar5 = 1;
  }
  iVar14 = iVar5;
  if (iVar5 == 0) {
    iVar17 = 0;
    if (0 < DAT_14098ec00) {
      plVar16 = &DAT_14098ec10;
      do {
        iVar14 = 0;
        lVar15 = 0;
        if (*local_1878 != '\0') {
          pcVar12 = local_1878;
          do {
            cVar4 = pcVar12[*plVar16 - (longlong)local_1878];
            if (cVar4 == '\0') break;
            cVar9 = *pcVar12;
            if ((cVar9 == '\\') || (cVar9 == '/')) {
              cVar9 = '\\';
            }
            if ((cVar4 == '\\') || (cVar4 == '/')) {
              cVar4 = '\\';
            }
            if (cVar9 != cVar4) break;
            pcVar12 = pcVar12 + 1;
            iVar14 = iVar14 + 1;
            lVar15 = lVar15 + 1;
          } while (*pcVar12 != '\0');
        }
        if (*(char *)(lVar15 + *plVar16) == '\0') break;
        iVar17 = iVar17 + 1;
        plVar16 = plVar16 + 1;
      } while (iVar17 < DAT_14098ec00);
    }
    if ((DAT_14098ec00 == 0) || (iVar17 == DAT_14098ec00)) {
      iVar17 = 0;
      if (*local_1878 != '\0') {
        lVar15 = 0;
        do {
          bVar1 = local_1878[lVar15];
          if ((byte)((bVar1 ^ 0x20) + 0x5f) < 0x3c) {
            lVar19 = 2;
          }
          else {
            if ((0x19 < (byte)(bVar1 + 0x9f)) &&
               ((0x2a < (byte)(bVar1 - 0x30) ||
                ((0x7fffffe03ffU >> ((ulonglong)(byte)(bVar1 - 0x30) & 0x3f) & 1) == 0)))) break;
            lVar19 = 1;
          }
          lVar15 = lVar15 + lVar19;
          iVar17 = iVar17 + (int)lVar19;
        } while (local_1878[lVar15] != '\0');
      }
      iVar14 = 0;
      if (local_1878[iVar17] != ':') goto LAB_140136472;
      iVar14 = iVar17 + 1;
      lVar15 = (longlong)iVar14;
      FUN_1401ae2f0(param_2,local_1878,lVar15);
      param_2[lVar15] = 0;
      if ((local_1878[lVar15] == '\\') || (iVar18 = iVar14, local_1878[iVar14] == '/')) {
        iVar18 = iVar17 + 2;
      }
    }
    else {
      FUN_1401ae2f0(param_2,local_1878,(longlong)iVar14);
      param_2[iVar14] = 0;
      iVar18 = iVar14;
    }
    iVar5 = 1;
  }
LAB_140136472:
  bVar3 = false;
  if (DAT_14056db60 == 1) {
    bVar2 = false;
    if (iVar5 != 0) goto LAB_140136552;
    if ((*local_1878 == '\\') || (*local_1878 == '/')) {
      iVar14 = 2;
      *param_2 = *param_4;
      iVar18 = iVar18 + 1;
      param_2[1] = param_4[1];
      param_2[2] = 0;
      bVar2 = true;
      goto LAB_140136552;
    }
  }
  else {
    bVar2 = bVar3;
    if (iVar5 != 0) goto LAB_140136552;
  }
  FUN_1401ae7d0(param_2,local_1870,param_4);
  iVar14 = FUN_1401ae820(param_2);
  if (DAT_1408ab148 == 0) {
    FUN_1401c6d60();
  }
  iVar5 = FUN_1401c55b0(param_4,DAT_1408ab148);
  bVar2 = false;
  if (iVar5 != 0) {
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    puVar6 = (undefined1 *)FUN_1401c5230(param_4,DAT_1408ab148,iVar5 + -1);
    if (DAT_1408ab148 == 0) {
      FUN_1401c6d60();
    }
    iVar5 = FUN_1401c4e50(puVar6,DAT_1408ab148,local_1868);
    if ((iVar5 == 0x5c) || (bVar2 = bVar3, iVar5 == 0x2f)) {
      *puVar6 = 0;
      iVar14 = iVar14 + -1;
      bVar2 = bVar3;
    }
  }
LAB_140136552:
  lVar15 = local_1870;
  pcVar12 = local_1878;
  lVar19 = (longlong)iVar18;
  cVar4 = local_1878[lVar19];
  if (cVar4 != '\0') {
    uVar10 = 0;
    do {
      if ((cVar4 == '/') || (cVar4 == '\\')) {
        uVar11 = uVar10;
        if (uVar10 != 0) {
          iVar5 = FUN_1401ae750(local_1858,&DAT_1404a75d8);
          if (iVar5 != 0) {
            iVar5 = FUN_1401ae750(local_1858,&DAT_1404a75dc);
            if (iVar5 == 0) {
              param_2[iVar14] = 0;
              if (DAT_1408ab148 == 0) {
                FUN_1401c6d60();
              }
              iVar5 = FUN_1401c55b0(param_2,DAT_1408ab148);
              if (DAT_1408ab148 == 0) {
                FUN_1401c6d60();
              }
              iVar5 = iVar5 + -1;
              uVar7 = FUN_1401c5230(param_2,DAT_1408ab148,iVar5);
              if (DAT_1408ab148 == 0) {
                FUN_1401c6d60();
              }
              FUN_1401c4e50(uVar7,DAT_1408ab148,local_1868);
              iVar14 = iVar14 - local_1868[0];
              lVar8 = (longlong)iVar14;
              bVar1 = param_2[lVar8];
              while (bVar1 != 0x5c) {
                bVar1 = param_2[lVar8];
                if ((bVar1 == 0x2f) || (bVar1 == 0x3a)) break;
                param_2[lVar8] = 0;
                iVar5 = iVar5 + -1;
                if (DAT_1408ab148 == 0) {
                  FUN_1401c6d60();
                }
                uVar7 = FUN_1401c5230(param_2,DAT_1408ab148,iVar5);
                if (DAT_1408ab148 == 0) {
                  FUN_1401c6d60();
                }
                FUN_1401c4e50(uVar7,DAT_1408ab148,local_1868);
                iVar14 = iVar14 - local_1868[0];
                lVar8 = (longlong)iVar14;
                bVar1 = param_2[lVar8];
              }
              if (param_2[iVar14] == 0x3a) {
                iVar14 = iVar14 + 1;
              }
              else {
                param_2[iVar14] = 0;
              }
            }
            else {
              if (((!bVar2) && ((*pcVar12 == '\\' || (*pcVar12 == '/')))) || (iVar14 != 0)) {
                lVar8 = (longlong)iVar14;
                iVar14 = iVar14 + 1;
                param_2[lVar8] = 0x5c;
              }
              FUN_1401ae7d0(param_2 + iVar14,lVar15 - iVar14,local_1858);
              iVar14 = FUN_1401ae820();
            }
          }
          iVar13 = 0;
          uVar11 = 0;
        }
LAB_140136751:
        lVar19 = lVar19 + 1;
      }
      else {
        bVar1 = pcVar12[lVar19];
        local_1858[uVar10] = bVar1;
        if (0x3b < (byte)((bVar1 ^ 0x20) + 0x5f)) {
          if (0x5ff < uVar10 + 1) {
                    /* WARNING: Subroutine does not return */
            FUN_14031c688();
          }
          local_1858[uVar10 + 1] = 0;
          iVar13 = iVar13 + 1;
          uVar11 = uVar10 + 1;
          goto LAB_140136751;
        }
        local_1858[uVar10 + 1] = pcVar12[lVar19 + 1];
        uVar11 = uVar10 + 2;
        if (0x5ff < uVar11) {
                    /* WARNING: Subroutine does not return */
          FUN_14031c688();
        }
        iVar13 = iVar13 + 2;
        local_1858[uVar10 + 2] = 0;
        lVar19 = lVar19 + 2;
      }
      cVar4 = pcVar12[lVar19];
      uVar10 = uVar11;
    } while (cVar4 != '\0');
    if (iVar13 != 0) {
      if (iVar14 != 0) {
        lVar19 = (longlong)iVar14;
        iVar14 = iVar14 + 1;
        param_2[lVar19] = 0x5c;
      }
      FUN_1401ae7d0(param_2 + iVar14,lVar15 - iVar14,local_1858);
      FUN_1401ae820(param_2);
    }
  }
  return 0;
}


