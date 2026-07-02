// Function: FUN_140105910 @ 140105910
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140105910(void)

{
  undefined4 uVar1;
  bool bVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int *piVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  undefined1 auStack_148 [32];
  float local_128;
  undefined2 local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_b8;
  undefined4 uStack_b4;
  ulonglong local_b0;
  
  local_b0 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  local_d8 = _DAT_14053b680;
  uStack_d0 = _UNK_14053b688;
  local_c8 = 5;
  local_c4 = 6;
  local_c0 = 8;
  FUN_140106880(0xff);
  bVar17 = false;
  if ((DAT_140e45fac != 0) || (DAT_140e46014 != 0)) goto LAB_140105f96;
  if (DAT_140e8cf10 == 1) {
LAB_1401059f4:
    bVar17 = true;
  }
  else if (0x13 < DAT_140e8cf10) {
    uVar9 = DAT_140e8cf10 - 0x14U & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    if (uVar9 == 0) goto LAB_1401059f4;
  }
  if ((DAT_140e8cf14 < 1) && (bVar17)) {
    DAT_140e45274 = DAT_140e45274 + -1;
    if (DAT_140e45274 < 0) {
      DAT_140e45274 = 6;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  bVar17 = false;
  if (DAT_140e8cf14 == 1) {
LAB_140105a81:
    bVar2 = true;
  }
  else {
    bVar2 = bVar17;
    if (0x13 < DAT_140e8cf14) {
      uVar9 = DAT_140e8cf14 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_140105a81;
    }
  }
  if ((DAT_140e8cf10 < 1) && (bVar2)) {
    DAT_140e45274 = DAT_140e45274 + 1;
    if (6 < DAT_140e45274) {
      DAT_140e45274 = 0;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
    FUN_14018a340(DAT_140e47200,1,1);
    DAT_140e46014 = 1;
  }
  if (DAT_140e8cf18 == 1) {
LAB_140105b01:
    bVar2 = true;
  }
  else {
    bVar2 = bVar17;
    if (0x13 < DAT_140e8cf18) {
      uVar9 = DAT_140e8cf18 - 0x14U & 0x80000007;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
      }
      if (uVar9 == 0) goto LAB_140105b01;
    }
  }
  if (((DAT_140e8cf1c < 1) && (bVar2)) && (DAT_140e45274 < 4)) {
    if (DAT_140e45274 == 0) {
      if (DAT_140e4418c < 10) {
        DAT_140e4418c = DAT_140e4418c + 1;
        FUN_140184700(DAT_140e4418c * 0x19,DAT_140e45108);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      FUN_14018a340(uVar12,1,1);
    }
    if (DAT_140e45274 == 1) {
      if (DAT_140e44190 < 10) {
        DAT_140e44190 = DAT_140e44190 + 1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      FUN_14018a340(uVar12,1,1);
    }
    if (DAT_140e45274 == 2) {
      DAT_140e47648 = DAT_140e47648 + 1;
      if (3 < DAT_140e47648) {
        DAT_140e47648 = 0;
      }
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (DAT_140e45274 == 3) {
      if (DAT_140e43f18 == 1) {
        DAT_140e441b8 = (uint)(DAT_140e441b8 != 1);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      FUN_14018a340(uVar12,1,1);
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
  }
  if (DAT_140e8cf1c == 1) {
LAB_140105cc2:
    bVar17 = true;
  }
  else if (0x13 < DAT_140e8cf1c) {
    uVar9 = DAT_140e8cf1c - 0x14U & 0x80000007;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffff8) + 1;
    }
    if (uVar9 == 0) goto LAB_140105cc2;
  }
  if (((DAT_140e8cf18 < 1) && (bVar17)) && (DAT_140e45274 < 4)) {
    if (DAT_140e45274 == 0) {
      if (DAT_140e4418c < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      else {
        DAT_140e4418c = DAT_140e4418c + -1;
        FUN_140184700(DAT_140e4418c * 0x19,DAT_140e45108);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      FUN_14018a340(uVar12,1,1);
    }
    if (DAT_140e45274 == 1) {
      if (DAT_140e44190 < 1) {
        FUN_140184700(DAT_140e44190 * 0x14,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      else {
        DAT_140e44190 = DAT_140e44190 + -1;
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      FUN_14018a340(uVar12,1,1);
    }
    if (DAT_140e45274 == 2) {
      DAT_140e47648 = DAT_140e47648 + -1;
      if (DAT_140e47648 < 0) {
        DAT_140e47648 = 3;
      }
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
      FUN_14018a340(DAT_140e47200,1,1);
    }
    if (DAT_140e45274 == 3) {
      if (DAT_140e43f18 == 1) {
        DAT_140e441b8 = (uint)(DAT_140e441b8 != 1);
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47200);
        uVar12 = DAT_140e47200;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4720c);
        uVar12 = DAT_140e4720c;
      }
      FUN_14018a340(uVar12,1,1);
    }
    DAT_140e46014 = 1;
    DAT_140e467fc = 1;
  }
  if (((DAT_140e467c8 == 1) && (3 < DAT_140e45274)) && (DAT_140e467fc == 0)) {
    DAT_140e45fac = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47204);
    FUN_14018a340(DAT_140e47204,1,1);
    DAT_140e467fc = 1;
  }
  if (((int)DAT_140e467cc == 1) && (DAT_140e467fc == 0)) {
    if (DAT_140e45274 == 6) {
      DAT_140e45fac = 0xffffffff;
    }
    else {
      DAT_140e45274 = 6;
    }
    DAT_140e467fc = 1;
    FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47208);
    FUN_14018a340(DAT_140e47208,1,1);
  }
  if ((DAT_140e467e4 != 1) &&
     (DAT_140e467e0 != 1 &&
      (DAT_140e467dc != 1 &&
      (DAT_140e467d8 != 1 &&
      (DAT_140e467d4 != 1 &&
      (DAT_140e467cc._4_4_ != 1 &&
      ((int)DAT_140e467cc != 1 &&
      (DAT_140e467c8 != 1 &&
      (DAT_140e467c4 != 1 && (DAT_140e467c0 != 1 && (DAT_140e467bc != 1 && DAT_140e467b8 != 1)))))))
      )))) {
    DAT_140e467fc = 0;
  }
LAB_140105f96:
  uVar8 = _UNK_14053bb28;
  uVar7 = _DAT_14053bb20;
  fVar6 = DAT_14053b338;
  uVar5 = DAT_14053af38;
  uVar4 = DAT_14053af30;
  uVar12 = DAT_14053af1c;
  fVar3 = DAT_14053af08;
  piVar16 = (int *)&local_d8;
  local_b8 = 0;
LAB_140105fe1:
  do {
    iVar10 = local_b8;
    uVar15 = 0x60;
    fVar18 = (float)((local_b8 + 3) * 0x32);
    if (DAT_140e45274 == local_b8) {
      if (DAT_140e45fac != 0) {
        uVar9 = DAT_140e45fac + 10000 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if (1 < (int)uVar9) goto LAB_140106029;
      }
      uVar15 = 0xff;
    }
LAB_140106029:
    uVar14 = 0xff;
    if (local_b8 == 3) {
      uVar14 = 0xff;
      if (DAT_140e43f18 == 0) {
        uVar14 = 0x80;
      }
    }
    uVar1 = (&DAT_140e47340)[*piVar16];
    puVar11 = (undefined4 *)_malloc_base(0x48);
    if (puVar11 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar11[4] = fVar18;
    *(undefined8 *)(puVar11 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar11 + 8) = 0x3ff0000000000000;
    *puVar11 = uVar1;
    puVar11[1] = 0x7a;
    puVar11[2] = 1;
    puVar11[3] = 0x44020000;
    *(undefined2 *)(puVar11 + 5) = 0;
    puVar11[10] = uVar14;
    puVar11[0xb] = uVar14;
    puVar11[0xc] = uVar14;
    puVar11[0xd] = uVar15;
    *(undefined8 *)(puVar11 + 0xe) = 1;
    *(undefined8 *)(puVar11 + 0x10) = 0;
    _DAT_140e46e78 = _DAT_140e46e78 + 1;
    if (DAT_140e46bf0 == (undefined4 *)0x0) {
      DAT_140e46bf0 = puVar11;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar11;
    }
    DAT_140e46c88 = puVar11;
    if (iVar10 == 0) {
      uVar13 = (longlong)DAT_140e4418c * 10;
      if (uVar13 < 10) {
LAB_1401064b0:
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[uVar13],0x7a,1,uVar12);
      }
      else {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar13 + (int)(uVar13 / 10) * -10],0x7a,1,uVar12);
        uVar13 = uVar13 / 10;
        fVar19 = fVar3;
        do {
          local_e0 = 0;
          local_e8 = 1;
          local_f8 = 0xff;
          local_100 = 0xff;
          local_108 = 0xff;
          local_118 = uVar7;
          uStack_110 = uVar8;
          local_120 = 0;
          local_128 = fVar18;
          local_f0 = uVar15;
          FUN_1400c8410((&DAT_140e46c30)[(int)uVar13 + (int)(uVar13 / 10) * -10],0x7a,1,fVar19);
          fVar19 = fVar19 + fVar6;
          bVar17 = 9 < uVar13;
          uVar13 = uVar13 / 10;
          iVar10 = local_b8;
        } while (bVar17);
      }
LAB_140106507:
      local_e0 = 0;
      local_e8 = 1;
      local_f8 = 0xff;
      local_100 = 0xff;
      local_108 = 0xff;
      local_118 = uVar7;
      uStack_110 = uVar8;
      local_120 = 0;
      local_128 = fVar18;
      local_f0 = uVar15;
      FUN_1400c8410(DAT_140e46c58,0x7a,1,uVar4);
      local_b8 = iVar10 + 1;
      piVar16 = piVar16 + 1;
      goto LAB_140105fe1;
    }
    if (iVar10 == 1) {
      uVar13 = (longlong)DAT_140e44190 * 10;
      if (uVar13 < 10) goto LAB_1401064b0;
      local_e0 = 0;
      local_e8 = 1;
      local_f8 = 0xff;
      local_100 = 0xff;
      local_108 = 0xff;
      local_118 = uVar7;
      uStack_110 = uVar8;
      local_120 = 0;
      local_128 = fVar18;
      local_f0 = uVar15;
      FUN_1400c8410((&DAT_140e46c30)[(int)uVar13 + (int)(uVar13 / 10) * -10],0x7a,1,uVar12);
      uVar13 = uVar13 / 10;
      fVar19 = fVar3;
      do {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410((&DAT_140e46c30)[(int)uVar13 + (int)(uVar13 / 10) * -10],0x7a,1,fVar19);
        fVar19 = fVar19 + fVar6;
        bVar17 = 9 < uVar13;
        uVar13 = uVar13 / 10;
        iVar10 = local_b8;
      } while (bVar17);
      goto LAB_140106507;
    }
    if (iVar10 == 2) {
      if (DAT_140e47648 == 0) {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e478f4,0x7a,1,uVar5);
      }
      if (DAT_140e47648 == 1) {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e478f8,0x7a,1,uVar5);
      }
      if (DAT_140e47648 == 2) {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e478fc,0x7a,1,uVar5);
      }
      if (DAT_140e47648 == 3) {
        local_e0 = 0;
        local_e8 = 1;
        local_f8 = 0xff;
        local_100 = 0xff;
        local_108 = 0xff;
        local_118 = uVar7;
        uStack_110 = uVar8;
        local_120 = 0;
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e47900,0x7a,1,uVar5);
      }
      local_b8 = 3;
      piVar16 = piVar16 + 1;
    }
    else if (iVar10 == 3) {
      local_e0 = 0;
      local_e8 = 1;
      local_118 = uVar7;
      uStack_110 = uVar8;
      local_120 = 0;
      local_108 = uVar14;
      local_100 = uVar14;
      local_f8 = uVar14;
      if (DAT_140e441b8 == 1) {
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e478c8,0x7a,1,uVar5);
        local_b8 = 4;
        piVar16 = piVar16 + 1;
      }
      else {
        local_128 = fVar18;
        local_f0 = uVar15;
        FUN_1400c8410(DAT_140e478cc,0x7a,1,uVar5);
        local_b8 = 4;
        piVar16 = piVar16 + 1;
      }
    }
    else {
      piVar16 = piVar16 + 1;
      local_b8 = iVar10 + 1;
      if (6 < iVar10 + 1) {
        FUN_1400d9b60(0,0x70,0xff);
        if (DAT_140e45fac == 0x32) {
          if (DAT_140e47648 != DAT_140e441b4) {
            DAT_140e441b4 = DAT_140e47648;
            iVar10 = FUN_1400d0e50();
            if (iVar10 == -1) {
              MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
            }
          }
          if (DAT_140e45274 == 4) {
            DAT_140e45274 = 0;
            DAT_140e45270 = 0x19;
            DAT_140e45fac = 0;
          }
          else if (DAT_140e45274 == 5) {
            DAT_140e45274 = 0;
            DAT_140e46064 = 0;
            DAT_140e45270 = 0x1a;
            DAT_140e45fac = 0;
          }
          else {
            if (DAT_140e45274 == 6) {
              DAT_140e45274 = 2;
              if (DAT_140e41928 == -1) {
                DAT_140e45270 = 0x16;
              }
              else {
                DAT_140e45270 = 0x26;
                if (DAT_140e41b00 == 0) {
                  DAT_140e45270 = 0x17;
                }
              }
              fopen_s((FILE **)&local_b8,"save\\save.dat","wb");
              FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_b4,local_b8));
              FUN_140323e90(CONCAT44(uStack_b4,local_b8));
              DAT_140e471fc = 0xb4;
            }
            DAT_140e45fac = 0;
          }
        }
        else if (DAT_140e45fac == 0xffffffce) {
          if (DAT_140e47648 != DAT_140e441b4) {
            DAT_140e441b4 = DAT_140e47648;
            iVar10 = FUN_1400d0e50();
            if (iVar10 == -1) {
              MessageBoxA((HWND)0x0,"Failed to load file.","error",0);
            }
          }
          DAT_140e45274 = 2;
          DAT_140e45270 = (DAT_140e41928 != -1) + 0x16;
          fopen_s((FILE **)&local_b8,"save\\save.dat","wb");
          FUN_140327c78(&DAT_140e41b10,0x2730,1,CONCAT44(uStack_b4,local_b8));
          FUN_140323e90(CONCAT44(uStack_b4,local_b8));
          DAT_140e471fc = 0xb4;
          DAT_140e45fac = 0;
        }
        else {
          if (0 < (int)DAT_140e45fac) {
            DAT_140e45fac = DAT_140e45fac + 1;
          }
          if (0x7fffffff < DAT_140e45fac) {
            DAT_140e45fac = DAT_140e45fac - 1;
          }
          if (DAT_140e46014 != 1) {
            return;
          }
        }
        DAT_140e46014 = 0;
        return;
      }
    }
  } while( true );
}


