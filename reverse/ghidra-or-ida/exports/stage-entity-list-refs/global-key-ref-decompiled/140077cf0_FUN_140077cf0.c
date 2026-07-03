// Function: FUN_140077cf0 @ 140077cf0
// Decompile completed: true

void FUN_140077cf0(undefined4 *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  int iVar5;
  double dVar6;
  undefined1 auVar7 [16];
  longlong lVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined2 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  undefined8 uStack_110;
  undefined8 local_f8;
  
  dVar13 = DAT_14053ac08;
  dVar12 = DAT_14053a798;
  dVar11 = DAT_14053a0f8;
  dVar10 = DAT_14053a020;
  dVar9 = DAT_140539d28;
  lVar8 = DAT_140e45d80;
  if (0 < DAT_140e44e6c) {
    for (; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x60)) {
      if (*(int *)(lVar8 + 4) == param_1[0x15]) {
        uStack_110 = *(undefined8 *)(lVar8 + 0x28);
        local_f8 = *(undefined8 *)(lVar8 + 0x40);
      }
    }
  }
  iVar19 = 0x1e;
  iVar17 = 0;
  iVar16 = 0;
  iVar18 = 0x1e;
  param_1[5] = (undefined4)uStack_110;
  param_1[6] = uStack_110._4_4_;
  *(undefined2 *)(param_1 + 9) = (undefined2)local_f8;
  do {
    dVar4 = *(double *)(param_1 + 0xc);
    dVar6 = (double)((float)dVar4 * DAT_14053ad90 * (float)iVar17 + (float)dVar4 * DAT_14053adb4);
    dVar20 = (double)FUN_1403307c0();
    fVar2 = (float)param_1[5];
    dVar21 = (double)FUN_140332d90();
    iVar15 = param_1[0x14];
    uVar14 = 0;
    iVar5 = param_1[1];
    fVar3 = (float)param_1[6];
    if (iVar16 <= iVar5) {
      if (iVar5 < iVar19 + 2) {
        if ((iVar16 != iVar18) && (iVar5 < iVar16 + 0x1e)) {
          dVar22 = (double)FUN_140332d90(((double)iVar5 - (double)iVar16) * dVar12 * dVar10 * dVar9)
          ;
          iVar15 = (int)(dVar22 * (double)iVar15);
        }
        iVar1 = iVar16 + 0x1e;
        if ((iVar16 == iVar1) || (iVar1 <= iVar5)) {
          uVar14 = 0;
          if ((iVar16 == iVar1) || (iVar1 <= iVar5)) goto LAB_140077fac;
        }
        else {
          dVar22 = (double)FUN_140332d90(((double)iVar5 - (double)iVar16) * dVar12 * dVar10 * dVar9)
          ;
          dVar4 = dVar22 * (dVar4 - dVar4 * dVar11) + dVar4 * dVar11;
        }
        dVar22 = (double)FUN_140332d90(((double)iVar5 - (double)iVar16) * dVar12 * dVar10 * dVar9);
        uVar14 = (undefined2)(int)(dVar22 * dVar13);
      }
      else if (3 < ((iVar5 - iVar16) + -0x1e) % 5) {
        iVar15 = 0;
      }
LAB_140077fac:
      auVar7._8_4_ = SUB84(dVar4,0);
      auVar7._0_8_ = dVar4;
      auVar7._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
      FUN_1400c8410(param_1[3],0x4e,8,(float)(dVar20 * dVar6) + fVar2,
                    (float)(dVar21 * dVar6) + fVar3,uVar14,auVar7,0xff,0xff,0xff,iVar15,1,0);
    }
    iVar17 = iVar17 + 1;
    iVar16 = iVar16 + 5;
    iVar19 = iVar19 + 5;
    iVar18 = iVar18 + 5;
    if (0x31 < iVar16) {
      if (param_1[1] + -0x1e == ((param_1[1] + -0x1e) / 10) * 10) {
        FUN_140184700(DAT_140e44190 << 4,DAT_140e472c8);
        FUN_14018a340(DAT_140e472c8,1,1);
      }
      if (param_1[1] == param_1[0x10]) {
        *param_1 = 0;
      }
      return;
    }
  } while( true );
}


