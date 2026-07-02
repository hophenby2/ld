// Function: FUN_140244bb0 @ 140244bb0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140244bb0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  longlong lVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 auStack_1098 [32];
  undefined4 local_1078 [72];
  int local_f58 [952];
  int local_78 [15];
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_1098;
  piVar10 = &DAT_1405746e4;
  lVar14 = 3;
  iVar7 = DAT_1407d6ac4;
  if (3 < DAT_1407d6ac4) {
    iVar7 = 3;
  }
  piVar12 = (int *)0x0;
  lVar13 = (longlong)iVar7;
  lVar9 = 0x7c;
  piVar11 = piVar12;
  do {
    iVar7 = piVar10[2];
    local_78[(longlong)*piVar10 + (longlong)piVar10[-1] * 4] = 0x3f800000;
    iVar1 = piVar10[4];
    local_78[(longlong)iVar7 + (longlong)piVar10[1] * 4] = 0x3f800000;
    local_78[(longlong)iVar1 + (longlong)piVar10[3] * 4] = 0x3f800000;
    if (((((DAT_14098ba90 == 0) || (uVar2 = *(uint *)(&DAT_1407cdcc8 + lVar9), (int)uVar2 < 0)) ||
         ((uVar2 & 0x7c000000) != DAT_14098bae0)) ||
        ((DAT_14098bae8 <= (int)(uVar2 & 0x3ffff) ||
         (piVar8 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar2 & 0x3ffff) * 8), piVar8 == (int *)0x0
         )))) || (*piVar8 << 0x12 != (uVar2 & 0x3fc0000))) {
LAB_140244eaa:
      iVar7 = piVar10[-2];
      local_78[(longlong)piVar10[-4] + (longlong)piVar10[-5] * 4] = 0x3f800000;
      local_78[(longlong)iVar7 + (longlong)piVar10[-3] * 4] = 0;
    }
    else {
      if (piVar8[6] != 0) {
        if ((piVar8[6] < 2) && (-1 < piVar8[8])) {
          iVar7 = FUN_1401afbe0();
        }
        else {
          iVar7 = FUN_1401b82b0(uVar2);
        }
        if ((iVar7 < 0) ||
           (*(longlong *)
             (DAT_14098ba98 + (ulonglong)(*(uint *)(&DAT_1407cdcc8 + lVar9) & 0x3ffff) * 8) == 0))
        goto LAB_140244eaa;
      }
      iVar7 = piVar10[-3];
      local_78[(longlong)piVar10[-4] + (longlong)piVar10[-5] * 4] = piVar8[0x90];
      local_78[(longlong)piVar10[-2] + (longlong)iVar7 * 4] = piVar8[0x92];
      piVar8 = piVar12;
      if (3 < lVar13) {
        do {
          if (*(int *)(lVar9 + (&DAT_1407ceab8)[(int)(&DAT_1407d6acc)[(longlong)piVar8]]) == 0) {
            local_78[(longlong)(int)(&DAT_1405746e4)[((longlong)piVar11 + (longlong)piVar8) * 2] +
                     (longlong)(int)(&DAT_1405746e0)[((longlong)piVar11 + (longlong)piVar8) * 2] * 4
                    ] = 0;
          }
          if (*(int *)(lVar9 + (&DAT_1407ceab8)[(int)(&DAT_1407d6ad0)[(longlong)piVar8]]) == 0) {
            local_78[(longlong)(int)(&DAT_1405746ec)[((longlong)piVar11 + (longlong)piVar8) * 2] +
                     (longlong)(int)(&DAT_1405746e8)[((longlong)piVar11 + (longlong)piVar8) * 2] * 4
                    ] = 0;
          }
          if (*(int *)(lVar9 + (&DAT_1407ceab8)[(int)(&DAT_1407d6ad4)[(longlong)piVar8]]) == 0) {
            local_78[(longlong)(int)(&DAT_1405746f4)[((longlong)piVar11 + (longlong)piVar8) * 2] +
                     (longlong)(int)(&DAT_1405746f0)[((longlong)piVar11 + (longlong)piVar8) * 2] * 4
                    ] = 0;
          }
          if (*(int *)(lVar9 + (&DAT_1407ceab8)[(int)(&DAT_1407d6ad8)[(longlong)piVar8]]) == 0) {
            local_78[(longlong)(int)(&DAT_1405746fc)[((longlong)piVar11 + (longlong)piVar8) * 2] +
                     (longlong)(int)(&DAT_1405746f8)[((longlong)piVar11 + (longlong)piVar8) * 2] * 4
                    ] = 0;
          }
          piVar8 = piVar8 + 1;
        } while ((longlong)piVar8 < lVar13 + -3);
      }
      for (; (longlong)piVar8 < lVar13; piVar8 = (int *)((longlong)piVar8 + 1)) {
        if (*(int *)(lVar9 + (&DAT_1407ceab8)[(int)(&DAT_1407d6acc)[(longlong)piVar8]]) == 0) {
          local_78[(longlong)(int)(&DAT_1405746e4)[((longlong)piVar11 + (longlong)piVar8) * 2] +
                   (longlong)(int)(&DAT_1405746e0)[((longlong)piVar11 + (longlong)piVar8) * 2] * 4]
               = 0;
        }
      }
    }
    lVar9 = lVar9 + 4;
    piVar11 = (int *)((longlong)piVar11 + 5);
    piVar10 = piVar10 + 10;
    lVar14 = lVar14 + -1;
    if (lVar14 == 0) {
      local_3c = DAT_140539da8;
      if (DAT_140d3ade0 == 0) {
        local_3c = 0;
      }
      FUN_14023e510(&DAT_140cb4dc8,1,0x12,4);
      FUN_1401ae2f0((longlong)((int)DAT_140cb51d0 * 0x12) + 0x140cb51d4,local_78,
                    (longlong)((int)DAT_140cb51d0 * 4));
      bVar6 = false;
      lVar14 = 0x12;
      do {
        (&DAT_140cc4a58)[lVar14] = 1;
        if (DAT_140ca5d24 != 0) {
          if ((byte)((&DAT_140ccd1a0)[lVar14] - 1) < 0xfe) {
            bVar6 = true;
          }
          else {
            (&DAT_140ccd1a0)[lVar14] = 0;
          }
        }
        lVar14 = lVar14 + 1;
      } while (lVar14 < 0x16);
      if (DAT_140ca5d24 != 0) {
        piVar10 = local_78;
        if (bVar6) {
          piVar10 = piVar12;
        }
        if (DAT_140ca5960 != 0) {
          if (piVar10 == (int *)0x0) {
            FUN_1401ae370(local_1078,0,0x1000);
            lVar14 = 0x120;
            lVar9 = 0x12;
            do {
              if ((&DAT_140ccd1a0)[lVar9] != 0xff) {
                lVar13 = (ulonglong)(byte)(&DAT_140ccd1a0)[lVar9] * 0x140c + lVar14;
                uVar3 = *(undefined4 *)(lVar13 + 0x140cb51d8);
                uVar4 = *(undefined4 *)(lVar13 + 0x140cb51dc);
                uVar5 = *(undefined4 *)(lVar13 + 0x140cb51e0);
                *(undefined4 *)((longlong)local_1078 + lVar14) =
                     *(undefined4 *)((longlong)&DAT_140cb51d0 + lVar13 + 4);
                *(undefined4 *)((longlong)local_1078 + lVar14 + 4) = uVar3;
                *(undefined4 *)((longlong)local_1078 + lVar14 + 8) = uVar4;
                *(undefined4 *)((longlong)local_1078 + lVar14 + 0xc) = uVar5;
              }
              lVar9 = lVar9 + 1;
              lVar14 = lVar14 + 0x10;
            } while (lVar14 < 0x160);
            piVar10 = local_f58;
          }
          if (DAT_1407cd8d4 == 1) {
            FUN_1402228f0(0x12,piVar10);
          }
          FUN_1401ae2f0(&DAT_140cc97a8,piVar10,0x40);
        }
      }
      return;
    }
  } while( true );
}


