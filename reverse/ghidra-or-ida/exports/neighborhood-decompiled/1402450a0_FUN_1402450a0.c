// Function: FUN_1402450a0 @ 1402450a0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402450a0(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  undefined *puVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  undefined1 auStack_10b8 [32];
  int *local_1098;
  undefined4 local_1090;
  undefined4 local_1088;
  undefined4 local_1078 [176];
  undefined local_db8 [3392];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x1402450c2;
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_10b8;
  lVar13 = 0x2c;
  iVar11 = 0x2c;
  lVar16 = 0x2c0;
  lVar15 = 0;
  lVar12 = 0x30;
  do {
    if (((((DAT_14098ba90 == 0) || (uVar1 = *(uint *)(lVar13 + 0x1407cdd18), (int)uVar1 < 0)) ||
         ((uVar1 & 0x7c000000) != DAT_14098bae0)) ||
        ((DAT_14098bae8 <= (int)(uVar1 & 0x3ffff) ||
         (piVar2 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar1 & 0x3ffff) * 8), piVar2 == (int *)0x0
         )))) || (*piVar2 << 0x12 != (uVar1 & 0x3fc0000))) {
LAB_140245303:
      FUN_14023e510(&DAT_140ca5d38,1,iVar11);
      FUN_1401ae2f0((longlong)(iVar11 * (int)DAT_140ca6140) + 0x140ca6144,&DAT_140574690,
                    (longlong)((int)DAT_140ca6140 * 4));
      bVar6 = false;
      for (lVar8 = lVar13; lVar8 < lVar12; lVar8 = lVar8 + 1) {
        (&DAT_140cc3e58)[lVar8] = 1;
        if (DAT_140ca5d24 != 0) {
          if ((byte)((&DAT_140cccea0)[lVar8] - 1) < 0xfe) {
            bVar6 = true;
          }
          else {
            (&DAT_140cccea0)[lVar8] = 0;
          }
        }
      }
      if (DAT_140ca5d24 != 0) {
        puVar10 = (undefined *)0x0;
        if (!bVar6) {
          puVar10 = &DAT_140574690;
        }
        if (DAT_140ca5960 != 0) {
          if (puVar10 == (undefined *)0x0) {
            FUN_1401ae370(local_1078,0,0x1000);
            lVar14 = lVar16;
            for (lVar8 = lVar13; lVar8 < iVar11 + 4; lVar8 = lVar8 + 1) {
              if ((&DAT_140cccea0)[lVar8] != 0xff) {
                lVar9 = (ulonglong)(byte)(&DAT_140cccea0)[lVar8] * 0x140c + lVar14;
                uVar3 = *(undefined4 *)(lVar9 + 0x140ca6148);
                uVar4 = *(undefined4 *)(lVar9 + 0x140ca614c);
                uVar5 = *(undefined4 *)(lVar9 + 0x140ca6150);
                *(undefined4 *)((longlong)local_1078 + lVar14) =
                     *(undefined4 *)((longlong)&DAT_140ca6140 + lVar9 + 4);
                *(undefined4 *)((longlong)local_1078 + lVar14 + 4) = uVar3;
                *(undefined4 *)((longlong)local_1078 + lVar14 + 8) = uVar4;
                *(undefined4 *)((longlong)local_1078 + lVar14 + 0xc) = uVar5;
              }
              lVar14 = lVar14 + 0x10;
            }
            puVar10 = local_db8 + lVar15;
          }
          if (DAT_1407cd8d4 == 1) {
            FUN_140222aa0(iVar11,puVar10,4);
          }
          FUN_1401ae2f0(&DAT_140cc5d24 + lVar15,puVar10,0x40);
        }
      }
    }
    else {
      if (piVar2[6] != 0) {
        if ((piVar2[6] < 2) && (-1 < piVar2[8])) {
          iVar7 = FUN_1401afbe0();
        }
        else {
          iVar7 = FUN_1401b82b0(uVar1);
        }
        if ((iVar7 < 0) ||
           (*(longlong *)
             (DAT_14098ba98 + (ulonglong)(*(uint *)(lVar13 + 0x1407cdd18) & 0x3ffff) * 8) == 0))
        goto LAB_140245303;
      }
      local_78 = piVar2[0x80];
      local_1098 = &local_78;
      local_74 = piVar2[0x84];
      local_70 = piVar2[0x88];
      local_6c = piVar2[0x8c];
      local_68 = piVar2[0x81];
      local_64 = piVar2[0x85];
      local_60 = piVar2[0x89];
      local_5c = piVar2[0x8d];
      local_58 = piVar2[0x82];
      local_54 = piVar2[0x86];
      local_50 = piVar2[0x8a];
      local_4c = piVar2[0x8e];
      local_48 = piVar2[0x83];
      local_44 = piVar2[0x87];
      local_40 = piVar2[0x8b];
      local_3c = piVar2[0x8f];
      local_1088 = 1;
      local_1090 = 4;
      FUN_14023dd40(&DAT_140ca5d24,0,0,iVar11);
    }
    iVar11 = iVar11 + 4;
    lVar15 = lVar15 + 0x40;
    lVar12 = lVar12 + 4;
    lVar16 = lVar16 + 0x40;
    lVar13 = lVar13 + 4;
    if (0x37 < iVar11) {
      return;
    }
  } while( true );
}


