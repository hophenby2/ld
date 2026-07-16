// Function: FUN_1400c8530 @ 1400c8530
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c8530(void)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int iVar14;
  ulonglong uVar15;
  undefined4 *puVar16;
  ulonglong uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  double dVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  float fVar35;
  undefined1 auStack_148 [32];
  undefined *local_128;
  ulonglong uStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_f8;
  double local_e8;
  undefined4 *local_e0;
  int local_d8;
  int local_d4;
  ulonglong local_d0;
  
  local_d0 = DAT_1407c6b00 ^ (ulonglong)auStack_148;
  uVar30 = (undefined4)DAT_14053a020;
  uVar32 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
  uVar15 = 0;
  uVar33 = (undefined4)DAT_140539d28;
  uVar34 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
  uVar7 = (undefined4)DAT_140539f18;
  uVar29 = (undefined4)((ulonglong)DAT_140539f18 >> 0x20);
  local_e0 = DAT_140e46bf0;
  puVar13 = DAT_140e46bf0;
  puVar16 = DAT_140e46bf0;
  uVar17 = uVar15;
  do {
    iVar11 = 0;
    piVar5 = DAT_140e9fd30;
    if ((uVar15 == 0x78) && (DAT_140e46a20 < 2)) {
      switch(DAT_140e45270) {
      case 0xe:
      case 0x24:
        FUN_140115680();
        break;
      case 0xf:
        FUN_1401160b0();
        break;
      case 0x10:
      case 0x23:
        FUN_140113450();
        break;
      case 0x13:
        iVar10 = iVar11;
        if (0 < DAT_140e9d18c) {
          do {
            FUN_140111cb0();
            if (9 < iVar10 + 1) break;
            iVar11 = iVar11 + 1;
            iVar10 = iVar10 + 1;
          } while (iVar11 < DAT_140e9d18c);
        }
        break;
      case 0x25:
        FUN_140114e90();
      }
      FUN_14012e1c0();
      piVar5 = DAT_140e9fd30;
      if (DAT_140e47908 != (int *)0x0) {
        iVar11 = *DAT_140e47908;
        piVar5 = DAT_140e47908;
        while (iVar11 == 0) {
          DAT_140e47908 = *(int **)(piVar5 + 0x8e);
          FUN_140323ce8(piVar5);
          if (DAT_140e47908 == (int *)0x0) {
            DAT_140e9fd30 = (int *)0x0;
            piVar5 = DAT_140e9fd30;
            goto LAB_1400c870f;
          }
          piVar5 = DAT_140e47908;
          iVar11 = *DAT_140e47908;
        }
        lVar2 = *(longlong *)(piVar5 + 0x8e);
        DAT_140e47908 = piVar5;
        while (lVar2 != 0) {
          piVar12 = *(int **)(piVar5 + 0x8e);
          if (*piVar12 == 0) {
            *(undefined8 *)(piVar5 + 0x8e) = *(undefined8 *)(piVar12 + 0x8e);
            FUN_140323ce8();
            piVar12 = piVar5;
          }
          piVar5 = piVar12;
          lVar2 = *(longlong *)(piVar12 + 0x8e);
        }
      }
    }
LAB_1400c870f:
    DAT_140e9fd30 = piVar5;
    puVar4 = puVar13;
    puVar6 = puVar16;
    if ((&DAT_140e46c90)[uVar15] != 0) {
      while (puVar13 = puVar6, bVar3 = puVar16 != (undefined4 *)0x0, puVar16 = puVar13, bVar3) {
        if (puVar4[1] != (int)uVar17) goto LAB_1400c9445;
        FUN_140156bc0(1,puVar4[0xd]);
        FUN_140156c60(puVar4[10],puVar4[0xb],puVar4[0xc]);
        FUN_140142af0(*puVar4,&local_d8,&local_d4);
        uVar1 = puVar4[2];
        if (0x19 < uVar1) goto LAB_1400c9427;
        switch(uVar1) {
        case 1:
          local_f8 = 0;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          local_128 = *(undefined **)(puVar4 + 6);
          uStack_120 = *(ulonglong *)(puVar4 + 8);
          FUN_1401415a0((int)(float)puVar4[3],(int)(float)puVar4[4],local_d8 / 2,local_d4 / 2);
          break;
        case 2:
          local_f8 = 0;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          local_128 = *(undefined **)(puVar4 + 6);
          uStack_120 = *(ulonglong *)(puVar4 + 8);
          FUN_1401415a0((int)(float)puVar4[3],(int)(float)puVar4[4],local_d8 / 2,local_d4);
          break;
        case 3:
          local_f8 = 0;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          local_128 = *(undefined **)(puVar4 + 6);
          uStack_120 = *(ulonglong *)(puVar4 + 8);
          FUN_1401415a0((int)(float)puVar4[3],(int)(float)puVar4[4],local_d8 / 2,0);
          break;
        case 4:
          local_f8 = 0;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          local_128 = *(undefined **)(puVar4 + 6);
          uStack_120 = *(ulonglong *)(puVar4 + 8);
          FUN_1401415a0((int)(float)puVar4[3],(int)(float)puVar4[4],0,local_d4 / 2);
          break;
        case 5:
          FUN_140156bc0(2,puVar4[0xd]);
        case 0:
          fVar27 = (float)puVar4[3];
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          goto LAB_1400c87bb;
        case 6:
          FUN_140156bc0(2,puVar4[0xd]);
          iVar14 = (int)(float)puVar4[3];
          iVar11 = local_d4 / 2;
          iVar10 = local_d8 / 2;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          goto LAB_1400c87c1;
        case 7:
          goto switchD_1400c8780_caseD_7;
        case 8:
          uVar9 = 2;
          goto LAB_1400c89de;
        case 9:
          fVar27 = DAT_140e45d30 + (float)puVar4[3];
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
LAB_1400c87bb:
          iVar14 = (int)fVar27;
          iVar11 = 0;
          iVar10 = 0;
          goto LAB_1400c87c1;
        case 10:
          FUN_140156bc0(2,puVar4[0xd]);
          iVar10 = local_d8 / 2;
          iVar11 = 0;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          iVar14 = (int)(DAT_140e45d30 + (float)puVar4[3]);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          goto LAB_1400c87c1;
        case 0xc:
          FUN_140156bc0(2,puVar4[0xd]);
        case 0xb:
          iVar10 = local_d8 / 2;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          iVar14 = (int)(DAT_140e45d30 + (float)puVar4[3]);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          iVar11 = local_d4;
          goto LAB_1400c87c1;
        case 0xd:
          uVar9 = 0xb;
LAB_1400c89de:
          FUN_140156bc0(uVar9,puVar4[0xd]);
switchD_1400c8780_caseD_7:
          iVar10 = local_d8 / 2;
          local_100 = puVar4[0xf];
          local_108 = puVar4[0xe];
          local_110 = CONCAT44(local_110._4_4_,*puVar4);
          iVar14 = (int)(DAT_140e45d30 + (float)puVar4[3]);
          local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                      (double)CONCAT44(uVar34,uVar33);
          iVar11 = local_d4 / 2;
LAB_1400c87c1:
          local_f8 = 0;
          local_128 = *(undefined **)(puVar4 + 6);
          uStack_120 = *(ulonglong *)(puVar4 + 8);
          FUN_1401415a0(iVar14,(int)(float)puVar4[4],iVar10,iVar11);
          break;
        default:
          iVar11 = puVar4[1];
          fVar27 = DAT_140e45d30;
          if (iVar11 < 6) {
            fVar27 = (DAT_14053ae28 -
                     ((DAT_140e445d8 / DAT_14053ab70) / DAT_14053aa20) * (float)iVar11) -
                     (float)(5 - iVar11) * DAT_14053ac34;
          }
          if (uVar1 == 0xe) {
            local_f8 = 0;
            local_100 = puVar4[0xf];
            local_108 = puVar4[0xe];
            local_110 = CONCAT44(local_110._4_4_,*puVar4);
            local_128 = *(undefined **)(puVar4 + 6);
            uStack_120 = *(ulonglong *)(puVar4 + 8);
            local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                        (double)CONCAT44(uVar34,uVar33);
            FUN_1401415a0((int)(fVar27 + (float)puVar4[3]),(int)(float)puVar4[4],local_d8 / 2,
                          local_d4 / 2);
          }
          if (puVar4[2] == 0xf) {
            FUN_140156bc0(2,puVar4[0xd]);
            local_f8 = 0;
            local_100 = puVar4[0xf];
            local_108 = puVar4[0xe];
            local_110 = CONCAT44(local_110._4_4_,*puVar4);
            local_128 = *(undefined **)(puVar4 + 6);
            uStack_120 = *(ulonglong *)(puVar4 + 8);
            local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                        (double)CONCAT44(uVar34,uVar33);
            FUN_1401415a0((int)(fVar27 + (float)puVar4[3]),(int)(float)puVar4[4],local_d8 / 2,
                          local_d4 / 2);
          }
          if (puVar4[2] == 0x10) {
            iVar10 = local_d8 / 2;
            local_100 = puVar4[0xf];
            local_108 = puVar4[0xe];
            local_110 = CONCAT44(local_110._4_4_,*puVar4);
            iVar14 = (int)(fVar27 + (float)puVar4[3]);
            local_118 = (double)*(ushort *)(puVar4 + 5) * (double)CONCAT44(uVar32,uVar30) *
                        (double)CONCAT44(uVar34,uVar33);
            iVar11 = local_d4;
            goto LAB_1400c87c1;
          }
          break;
        case 0x11:
          uVar8 = FUN_14017a940(puVar4[10],puVar4[0xb],puVar4[0xc]);
          local_110 = 0;
          local_118 = (double)CONCAT44(local_118._4_4_,DAT_140539da8);
          uStack_120 = uStack_120 & 0xffffffff00000000;
          local_128 = (undefined *)CONCAT44(local_128._4_4_,uVar8);
          FUN_14013b0f0(DAT_140e45d30 + (float)puVar4[3]);
          break;
        case 0x12:
          uVar8 = FUN_14017a940(puVar4[10],puVar4[0xb],puVar4[0xc]);
          local_110 = 0;
          local_118 = (double)CONCAT44(local_118._4_4_,DAT_140539da8);
          uStack_120 = CONCAT44(uStack_120._4_4_,1);
          local_128 = (undefined *)CONCAT44(local_128._4_4_,uVar8);
          FUN_14013b0f0(DAT_140e45d30 + (float)puVar4[3]);
          break;
        case 0x13:
          FUN_1403307c0();
          FUN_140332d90();
          uVar7 = FUN_14017a940(puVar4[10],puVar4[0xb],puVar4[0xc]);
          uStack_120 = CONCAT44(uStack_120._4_4_,DAT_140539da8);
          local_128 = (undefined *)CONCAT44(local_128._4_4_,uVar7);
          FUN_14013e450(DAT_140e45d30 + (float)puVar4[3]);
          goto LAB_1400c941e;
        case 0x14:
          FUN_14016d2c0((int)*(double *)(puVar4 + 8));
          FUN_14016d440(9);
          dVar18 = *(double *)(puVar4 + 6);
          uVar8 = FUN_14017a940(puVar4[10],puVar4[0xb],puVar4[0xc]);
          uStack_120 = CONCAT44(uStack_120._4_4_,(int)dVar18);
          local_128 = &DAT_140536fb0;
          FUN_14015b020((int)(DAT_140e45d30 + (float)puVar4[3]),(int)(float)puVar4[4],uVar8,
                        DAT_140e46bec);
          break;
        case 0x15:
          fVar27 = (float)puVar4[3];
          goto LAB_1400c8ec7;
        case 0x16:
          fVar27 = DAT_140e45d30 + (float)puVar4[3];
LAB_1400c8ec7:
          local_110 = (ulonglong)local_110._4_4_ << 0x20;
          local_118 = (double)((ulonglong)local_118._4_4_ << 0x20);
          uStack_120 = DAT_140539f40;
          local_128 = (undefined *)0x0;
          FUN_14013b940((int)fVar27,(int)(float)puVar4[4],*(undefined8 *)(puVar4 + 6),*puVar4);
          break;
        case 0x17:
        case 0x18:
          dVar19 = (double)local_d4;
          dVar18 = *(double *)(puVar4 + 8);
          iVar11 = (int)((double)(local_d8 / 2) * *(double *)(puVar4 + 6));
          dVar20 = (double)iVar11 * *(double *)(puVar4 + 6);
          fVar27 = (float)iVar11;
          iVar11 = (int)(dVar20 * DAT_140539ee0);
          if (uVar1 == 0x18) {
            iVar11 = (int)(dVar20 * DAT_140539f28);
            iVar10 = local_d4;
            if (local_d4 < 0) {
              iVar10 = local_d4 + 1;
            }
            local_100 = puVar4[0xe];
            fVar26 = fVar27 + (float)puVar4[3];
            local_108 = *puVar4;
            fVar31 = (float)puVar4[3] - fVar27;
            iVar14 = (int)(float)puVar4[4] + (iVar10 >> 1);
            local_110 = CONCAT44(local_110._4_4_,iVar14);
            iVar10 = (int)((double)((float)(iVar10 >> 1) + (float)puVar4[4]) -
                          (double)(int)(dVar19 * dVar18) * (double)CONCAT44(uVar29,uVar7));
            local_118 = (double)CONCAT44(local_118._4_4_,(int)(fVar31 + DAT_140e45d30));
            uStack_120 = CONCAT44(uStack_120._4_4_,iVar14);
            local_128 = (undefined *)CONCAT44(local_128._4_4_,(int)(fVar26 + DAT_140e45d30));
            FUN_14013f4e0((int)((fVar31 - (float)iVar11) + DAT_140e45d30),iVar10,
                          (int)((fVar26 - (float)iVar11) + DAT_140e45d30),iVar10);
          }
          iVar10 = local_d4;
          if (local_d4 < 0) {
            iVar10 = local_d4 + 1;
          }
          local_100 = puVar4[0xe];
          fVar26 = (float)puVar4[3] - fVar27;
          local_108 = *puVar4;
          fVar27 = fVar27 + (float)puVar4[3];
          iVar14 = (int)(float)puVar4[4] + (iVar10 >> 1);
          local_110 = CONCAT44(local_110._4_4_,iVar14);
          iVar10 = (int)((double)((float)(iVar10 >> 1) + (float)puVar4[4]) -
                        (double)(int)(dVar19 * dVar18) * (double)CONCAT44(uVar29,uVar7));
          local_118 = (double)CONCAT44(local_118._4_4_,(int)(fVar26 + DAT_140e45d30));
          uStack_120 = CONCAT44(uStack_120._4_4_,iVar14);
          local_128 = (undefined *)CONCAT44(local_128._4_4_,(int)(fVar27 + DAT_140e45d30));
          FUN_14013f4e0((int)(fVar26 + (float)iVar11 + DAT_140e45d30),iVar10,
                        (int)(fVar27 + (float)iVar11 + DAT_140e45d30),iVar10);
          break;
        case 0x19:
          fVar27 = (float)puVar4[3];
          dVar18 = (double)FUN_1403300b4(IMAGE_DOS_HEADER_140000000.e_magic +
                                         (&switchD_1400c8780::switchdataD_1400c9510)[(int)uVar1],
                                         DAT_14053b1f0);
          dVar28 = (double)fVar27;
          local_e8 = (double)((int)(dVar18 * DAT_14053aba0) & 0xffff) *
                     (double)CONCAT44(uVar32,uVar30) * (double)CONCAT44(uVar34,uVar33);
          dVar18 = (double)FUN_1403307c0();
          fVar26 = DAT_140e45d30;
          fVar35 = (float)(dVar18 * dVar28) + DAT_140e45d30;
          dVar19 = (double)FUN_140332d90();
          FUN_1403300b4();
          fVar31 = fVar26 + DAT_14053af14;
          dVar20 = (double)FUN_1403307c0();
          dVar21 = (double)FUN_140332d90();
          dVar18 = (double)(fVar27 + _DAT_14053b020);
          dVar22 = (double)FUN_1403307c0();
          dVar23 = (double)FUN_140332d90(local_e8);
          dVar24 = (double)FUN_1403307c0();
          dVar25 = (double)FUN_140332d90();
          local_100 = puVar4[0xe];
          local_108 = *puVar4;
          local_110._0_4_ = (int)((float)(dVar23 * dVar18) + 0.0);
          local_118._0_4_ = (int)((float)(dVar22 * dVar18) + fVar26);
          uStack_120._0_4_ = (int)((float)(dVar25 * dVar18) + 0.0);
          local_128._0_4_ = (int)((float)(dVar24 * dVar18) + fVar31);
          FUN_14013f4e0((int)fVar35,(int)((float)(dVar19 * dVar28) + 0.0),
                        (int)((float)(dVar20 * dVar28) + fVar31),
                        (int)((float)(dVar21 * dVar28) + 0.0));
          fVar27 = (float)puVar4[3];
          dVar28 = (double)(fVar27 - _DAT_14053b020);
          dVar18 = (double)FUN_1403307c0();
          fVar26 = DAT_140e45d30;
          fVar35 = (float)(dVar18 * dVar28) + DAT_140e45d30;
          dVar19 = (double)FUN_140332d90();
          fVar31 = fVar26 + DAT_14053af14;
          dVar20 = (double)FUN_1403307c0();
          dVar21 = (double)FUN_140332d90();
          dVar18 = (double)fVar27;
          dVar22 = (double)FUN_1403307c0();
          dVar23 = (double)FUN_140332d90(local_e8);
          dVar24 = (double)FUN_1403307c0();
          dVar25 = (double)FUN_140332d90();
          local_100 = puVar4[0xe];
          local_108 = *puVar4;
          local_110 = CONCAT44(local_110._4_4_,(int)((float)(dVar23 * dVar18) + 0.0));
          local_118 = (double)CONCAT44(local_118._4_4_,(int)((float)(dVar22 * dVar18) + fVar26));
          uStack_120 = CONCAT44(uStack_120._4_4_,(int)((float)(dVar25 * dVar18) + 0.0));
          local_128 = (undefined *)
                      CONCAT44(local_128._4_4_,(int)((float)(dVar24 * dVar18) + fVar31));
          FUN_14013f4e0((int)fVar35,(int)((float)(dVar19 * dVar28) + 0.0),
                        (int)((float)(dVar20 * dVar28) + fVar31),
                        (int)((float)(dVar21 * dVar28) + 0.0));
          uVar30 = (undefined4)DAT_14053a020;
          uVar32 = (undefined4)((ulonglong)DAT_14053a020 >> 0x20);
          uVar33 = (undefined4)DAT_140539d28;
          uVar34 = (undefined4)((ulonglong)DAT_140539d28 >> 0x20);
LAB_1400c941e:
          uVar7 = (undefined4)DAT_140539f18;
          uVar29 = (undefined4)((ulonglong)DAT_140539f18 >> 0x20);
        }
LAB_1400c9427:
        FUN_140156bc0(1,0xff);
        FUN_140156c60(0xff,0xff,0xff);
LAB_1400c9445:
        puVar16 = *(undefined4 **)(puVar4 + 0x10);
        puVar4 = puVar16;
        puVar6 = local_e0;
      }
    }
    uVar17 = (ulonglong)((int)uVar17 + 1);
    uVar15 = uVar15 + 1;
    if (0x7f < (longlong)uVar15) {
      return;
    }
  } while( true );
}


