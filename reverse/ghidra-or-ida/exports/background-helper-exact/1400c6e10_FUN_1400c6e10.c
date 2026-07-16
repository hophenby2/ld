// Function: FUN_1400c6e10 @ 1400c6e10
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400c6e10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  longlong lVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  byte bVar13;
  undefined4 *puVar14;
  bool bVar15;
  bool bVar16;
  undefined1 auStack_58 [32];
  FILE *local_38;
  ulonglong local_30;
  
  local_30 = DAT_1407c6b00 ^ (ulonglong)auStack_58;
  if (((DAT_140e4695c == 1) && (DAT_140e41928 == 1)) && (DAT_140e451a4 == 0)) {
    DAT_140e44e68 = 1;
  }
  bVar13 = false;
  bVar16 = false;
  if (DAT_140e41928 == 0) {
    bVar8 = DAT_1407c7798 - 8U < 2;
    if (DAT_140e467e8 != 0) {
      bVar15 = DAT_1407c7798 == DAT_140e467e8;
LAB_1400c6eca:
      if (bVar15) {
LAB_1400c6ecc:
        bVar8 = true;
      }
    }
  }
  else {
    bVar8 = bVar16;
    if ((DAT_140e41928 == 1) && (-1 < DAT_140e41abc)) {
      if (((DAT_140e44e68 == 0) && (DAT_1407c7798 == 8)) ||
         (bVar8 = (bool)bVar13, DAT_1407c7798 == 9)) {
        bVar8 = true;
      }
      if (DAT_140e467e8 != 0) {
        if (DAT_140e467e8 == DAT_1407c7798) goto LAB_1400c6ecc;
        if (DAT_140e467e8 == DAT_1407c7798 + 1) {
          bVar15 = DAT_140e41abc == 0;
          goto LAB_1400c6eca;
        }
      }
    }
  }
  puVar14 = &DAT_140e45100;
  bVar15 = true;
  if (((DAT_140e41928 == 1) && (DAT_140e41abc == 0)) &&
     ((bVar8 == false && ((DAT_140e41b00 == 0 && (DAT_1407c7798 < 6)))))) {
LAB_1400c73de:
    iVar4 = DAT_140e467e8;
    lVar6 = DAT_140e46ea0;
    if (DAT_1407c7798 == 10) {
      if (DAT_140e41b00 == 0) {
        DAT_140e4680c = 1;
        DAT_140e418c8 = 0;
        DAT_140e46014 = 0;
        DAT_140e46bb4 = 0;
        *(int *)(&DAT_140e4330c + (longlong)DAT_140e445c0 * 200) =
             *(int *)(&DAT_140e4330c + (longlong)DAT_140e445c0 * 200) + 1;
        DAT_140e46bb0 = 0;
        DAT_140e45fac = 0;
        if ((iVar4 == 0) && (DAT_140e43f54 == 0)) {
          DAT_140e43f54 = 1;
          FUN_1400b4350(0,0xe);
          save_init_or_reset_candidate();
        }
        fopen_s(&local_38,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_38);
        FUN_140323e90(local_38);
        goto LAB_1400c7b7e;
      }
LAB_1400c7b91:
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
      FUN_14018a340(DAT_140e4721c,1,1);
      DAT_140e41a38 = 1;
      DAT_140e45270 = 0x27;
      DAT_140e467fc = 1;
      DAT_140e46a20 = 1;
    }
    else {
      while (lVar6 != 0) {
        lVar6 = *(longlong *)(lVar6 + 0x38);
        FUN_140323ce8();
      }
      DAT_140e46ea0 = 0;
      DAT_140e9fd38 = 0;
      DAT_140e4764c = 0;
      lVar6 = DAT_140e46e90;
      while (lVar6 != 0) {
        lVar6 = *(longlong *)(lVar6 + 0x28);
        FUN_140323ce8();
      }
      DAT_140e46e90 = 0;
      DAT_140e46e98 = 0;
      DAT_140e46c5c = 0;
      stage_entity_flush_effects_candidate();
      stage_pending_effect_flush_candidate();
      iVar4 = DAT_1407c7798;
      lVar6 = DAT_140e45d78;
      while (DAT_1407c7798 = iVar4, lVar6 != 0) {
        lVar6 = *(longlong *)(lVar6 + 0x58);
        FUN_140323ce8();
        iVar4 = DAT_1407c7798;
      }
      DAT_140e445f0 = 0;
      DAT_140e445e8 = 0xc000;
      DAT_140e4463c = 0xc000;
      DAT_140e45d78 = 0;
      DAT_140e45d28 = 0;
      DAT_140e45d1c = 0;
      DAT_140e445d4 = 1;
      DAT_140e445d8 = 0x43b40000;
      DAT_140e445dc = 0x44160000;
      DAT_140e445e0 = 0x43b40000;
      DAT_140e445e4 = 0x44160000;
      DAT_140e44640 = 0;
      _DAT_140e44654 = 0x3c;
      _DAT_140e44648 = 0x20;
      DAT_140e44650 = 0;
      DAT_140e41a38 = 1;
      DAT_140e41b08 = 1;
      DAT_140e41a3c = 1;
      DAT_140e44604 = 0x43b40000;
      DAT_140e44608 = 0x44160000;
      _DAT_140e44624 = 0xc000c000;
      _DAT_140e4462c = 0;
      DAT_140e4460c = 0x43b40000;
      DAT_140e44610 = 0x44160000;
      _DAT_140e44614 = 0x43b40000;
      _DAT_140e44618 = 0x44160000;
      _DAT_140e44628 = 0xc000c000;
      _DAT_140e44634 = 0;
      _DAT_140e4461c = 0x43b40000;
      _DAT_140e44620 = 0x44160000;
      DAT_1407c779c = 1;
      if ((DAT_140e41b00 == 0) &&
         (bVar16 = DAT_140e451a4 == 1, (&DAT_140e45c78)[iVar4] = DAT_140e44590, bVar16)) {
        *(longlong *)(&DAT_140e45cc8 + (longlong)iVar4 * 2) = (longlong)DAT_140e451b0;
      }
      if (bVar15 == false) {
        DAT_140e418c8 = DAT_140e46a1c;
        _DAT_140e46a38 = 0;
        _DAT_140e46a28 = 0;
        _DAT_140e46a30 = 0;
        if (DAT_140e41abc == 0) {
          switch(iVar4) {
          case 1:
            DAT_1407c7798 = DAT_140e452c8;
            break;
          case 2:
          case 3:
            DAT_1407c7798 = DAT_140e452cc;
            break;
          case 4:
          case 5:
            DAT_1407c7798 = DAT_140e452d0;
            break;
          case 6:
          case 7:
            DAT_1407c7798 = 8;
            break;
          case 8:
            DAT_1407c7798 = 9;
          }
        }
        else {
          DAT_1407c7798 = iVar4 + 1;
          if (DAT_140e41abc == 1) {
            DAT_140e418c8 = *(int *)(&UNK_140538ad8 + (longlong)DAT_1407c7798 * 4) + -0x14a;
            DAT_140e45d74 = DAT_140e418c8;
          }
        }
        goto switchD_1400c7602_default;
      }
      if (5 < iVar4) goto switchD_1400c7602_default;
      DAT_140e45270 = 0x22;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
    }
    DAT_140e45274 = 0;
    DAT_140e46014 = 0;
    DAT_140e45fac = 0;
  }
  else {
    puVar5 = &DAT_140e45100;
    do {
      FUN_14018f230(*puVar5,0);
      iVar7 = DAT_140e41b00;
      iVar4 = DAT_1407c7798;
      puVar5 = puVar5 + 1;
    } while ((longlong)puVar5 < 0x140e45178);
    _DAT_1407c777c = 0x3f800000;
    if (DAT_140e41928 == 0) {
      DAT_140e418c8 = 0;
      DAT_140e46014 = 0;
      DAT_140e46bb4 = 0;
      DAT_140e46bb0 = 0;
      DAT_140e45fac = 0;
      if (DAT_140e41b00 == 0) {
        lVar12 = (longlong)DAT_140e445c0;
        lVar6 = (longlong)DAT_1407c7798;
        lVar10 = (longlong)(int)DAT_140e419b8;
        iVar1 = FUN_140135290(DAT_1407c7798,DAT_140e445c0);
        lVar6 = (lVar6 * 3 + lVar12) * 0x32 + lVar10;
        if (iVar1 == 0) {
          (&DAT_140e41b94)[lVar6] = (&DAT_140e41b94)[lVar6] + 1;
        }
        else {
          (&DAT_140e41ba8)[lVar6] = (&DAT_140e41ba8)[lVar6] + 1;
        }
        iVar1 = (int)lVar10;
        if (bVar8 == false) {
          if (DAT_140e41b68 == iVar4) {
            DAT_140e41b68 = DAT_140e41b68 + 1;
            DAT_140e46958 = 1;
            if (DAT_140e41b68 == 2) {
              DAT_140e46b04 = 1;
            }
          }
        }
        else {
          if (DAT_140e43ed4 < iVar1) {
            DAT_140e43ed4 = iVar1;
          }
          if (DAT_140e41b1c == 0) {
            DAT_140e46b08 = 1;
            DAT_140e41b1c = 1;
          }
        }
        if (DAT_140e43eac < 3) {
          if (((((0 < DAT_140e41df4) || (0 < DAT_140e41ebc)) || (0 < DAT_140e41f84)) ||
              ((0 < DAT_140e41e08 || (0 < DAT_140e41ed0)))) || (0 < DAT_140e41f98)) {
            bVar13 = true;
          }
          if (((0 < DAT_140e4204c) || (0 < DAT_140e42114)) ||
             ((0 < DAT_140e421dc ||
              (((0 < DAT_140e42060 || (0 < DAT_140e42128)) || (0 < DAT_140e421f0)))))) {
            bVar13 = bVar13 + 1;
          }
          if ((((0 < DAT_140e422a4) || (0 < DAT_140e4236c)) ||
              ((0 < DAT_140e42434 || ((0 < DAT_140e422b8 || (0 < DAT_140e42380)))))) ||
             (0 < DAT_140e42448)) {
            bVar13 = bVar13 + 1;
          }
          if (((((0 < DAT_140e424fc) || (0 < DAT_140e425c4)) || (0 < DAT_140e4268c)) ||
              ((0 < DAT_140e42510 || (0 < DAT_140e425d8)))) || (0 < DAT_140e426a0)) {
            bVar13 = bVar13 + 1;
          }
          if (((0 < DAT_140e42754) || (0 < DAT_140e4281c)) ||
             ((0 < DAT_140e428e4 ||
              (((0 < DAT_140e42768 || (0 < DAT_140e42830)) || (0 < DAT_140e428f8)))))) {
            bVar13 = bVar13 + 1;
          }
          if (((0 < DAT_140e429ac) || (0 < DAT_140e42a74)) ||
             (((0 < DAT_140e42b3c || ((0 < DAT_140e429c0 || (0 < DAT_140e42a88)))) ||
              (0 < DAT_140e42b50)))) {
            bVar13 = bVar13 + 1;
          }
          if (((((0 < DAT_140e42c04) || (0 < DAT_140e42ccc)) || (0 < DAT_140e42d94)) ||
              ((0 < DAT_140e42c18 || (0 < DAT_140e42ce0)))) || (0 < DAT_140e42da8)) {
            bVar13 = bVar13 + 1;
          }
          if (((0 < DAT_140e42e5c) || (0 < DAT_140e42f24)) ||
             ((0 < DAT_140e42fec ||
              (((0 < DAT_140e42e70 || (0 < DAT_140e42f38)) || (0 < DAT_140e43000)))))) {
            bVar13 = bVar13 + 1;
          }
          if (7 < bVar13) {
            DAT_140e43eac = 3;
            _DAT_140e46b0c = 1;
          }
        }
        if (((int)(&DAT_140e43ea8)[iVar4 + 1] < iVar1) && (iVar4 < 9)) {
          (&DAT_140e43ea8)[iVar4 + 1] = iVar1;
        }
        lVar6 = 3;
        switch(iVar4) {
        case 2:
          lVar6 = 4;
          break;
        case 3:
          lVar6 = 5;
          break;
        case 4:
          lVar6 = 6;
          break;
        case 5:
          lVar6 = 7;
          break;
        case 6:
          lVar6 = 9;
          break;
        case 7:
          lVar6 = 10;
          break;
        case 8:
          lVar6 = 0xc;
          break;
        case 9:
          lVar6 = 0xd;
        }
        if ((DAT_140e467e8 == 0) && ((&DAT_140e43f1c)[lVar6] == 0)) {
          (&DAT_140e43f1c)[lVar6] = 1;
          FUN_1400b4350(0);
          save_init_or_reset_candidate();
          iVar7 = DAT_140e41b00;
          iVar4 = DAT_1407c7798;
        }
        if (iVar4 == 6) {
          if (((iVar7 == 0) && (DAT_140e467e8 == 0)) && (DAT_140e43f3c == 0)) {
            DAT_140e43f3c = 1;
            FUN_1400b4350(0,8);
            save_init_or_reset_candidate();
            iVar7 = DAT_140e41b00;
            iVar4 = DAT_1407c7798;
            goto LAB_1400c72e1;
          }
        }
        else {
LAB_1400c72e1:
          if (((iVar4 == 7) && (iVar7 == 0)) && ((DAT_140e467e8 == 0 && (DAT_140e43f48 == 0)))) {
            DAT_140e43f48 = 1;
            FUN_1400b4350(0,0xb);
            save_init_or_reset_candidate();
          }
        }
        fopen_s(&local_38,"save\\save.dat","wb");
        FUN_140327c78(&DAT_140e41b10,0x2730,1,local_38);
        FUN_140323e90(local_38);
        DAT_140e471fc = 0xb4;
        DAT_140e45270 = 0x20;
      }
      else {
        FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
        FUN_14018a340(DAT_140e4721c,1,1);
        DAT_140e45274 = 0;
        DAT_140e46014 = 0;
        DAT_140e45fac = 0;
        DAT_140e467fc = 1;
        DAT_140e45270 = 0x27;
        DAT_140e41a38 = 1;
      }
      DAT_140e46a20 = 1;
    }
    iVar4 = DAT_140e41b00;
    if (DAT_140e41928 != 1) goto switchD_1400c7602_default;
    bVar15 = bVar16;
    if (bVar8 == false) goto LAB_1400c73de;
    if (DAT_140e41b00 != 0) goto LAB_1400c7b91;
    lVar10 = (longlong)DAT_140e445c0;
    uVar11 = (ulonglong)(int)DAT_140e419b8;
    DAT_140e418c8 = 0;
    iVar2 = DAT_140e41abc + 0xb;
    DAT_140e46014 = 0;
    DAT_140e46bb4 = 0;
    DAT_140e46bb0 = 0;
    DAT_140e45fac = 0;
    iVar7 = DAT_140e41abc;
    iVar1 = FUN_140135290(iVar2,DAT_140e445c0);
    lVar6 = (longlong)iVar2 * 3 + lVar10;
    if (iVar1 == 0) {
      (&DAT_140e41b94)[lVar6 * 0x32 + uVar11] = (&DAT_140e41b94)[lVar6 * 0x32 + uVar11] + 1;
    }
    else {
      (&DAT_140e41ba8)[lVar6 * 0x32 + uVar11] = (&DAT_140e41ba8)[lVar6 * 0x32 + uVar11] + 1;
    }
    iVar1 = DAT_1407c7798;
    iVar2 = (int)uVar11;
    if ((iVar7 < 3) && (DAT_1407c7798 != 10)) {
      if (DAT_140e41b6c + -0xb == iVar7) {
        DAT_140e41b6c = DAT_140e41b6c + 1;
        DAT_140e46958 = 1;
      }
      if ((int)(&DAT_140e43ea8)[iVar7 + 0xc] < iVar2) {
        (&DAT_140e43ea8)[iVar7 + 0xc] = iVar2;
      }
    }
    iVar3 = DAT_140e467e8;
    if ((DAT_140e43eac < 3) && (iVar2 == 2)) {
      _DAT_140e46b0c = 1;
      DAT_140e43eac = 3;
    }
    if ((iVar7 == 1) && (DAT_140e41b74 == 0)) {
      DAT_140e41b74 = 1;
      _DAT_140e46b10 = 1;
    }
    if (DAT_140e467e8 == 0) {
      if (DAT_140e43f18 == 0) {
        DAT_140e43f18 = 1;
        _DAT_140e46b20 = 1;
      }
      if ((iVar1 == 9) && (DAT_140e41b68 < 9)) {
        DAT_140e41b68 = iVar1;
        _DAT_140e46b14 = 1;
        if (DAT_140e43ecc < DAT_140e43ec8) {
          DAT_140e43ecc = iVar2;
        }
      }
      if (DAT_140e41b20 == 0) {
        DAT_140e41b20 = 1;
      }
      if ((DAT_140e41b78 == 0) && (DAT_140e41b20 == 1)) {
        _DAT_140e46b18 = 1;
        DAT_140e41b78 = 1;
        _DAT_140e43ed0 = 4;
      }
      if ((iVar2 == 3) && (DAT_140e43eac < 4)) {
        DAT_140e43eac = 4;
        _DAT_140e46b1c = 1;
      }
    }
    if (iVar7 == 3) {
      lVar6 = (longlong)DAT_140e45268;
      if (DAT_140e451b0 < DAT_140e46bb8) {
        *(int *)(&DAT_140e43cf0 + (lVar6 + (lVar10 * 0x19 + uVar11) * 2) * 4) = DAT_140e451b0;
      }
      DAT_140e46bb8 = *(int *)(&DAT_140e43cf0 + (lVar6 + (lVar10 * 0x19 + uVar11) * 2) * 4);
    }
    if (((iVar1 == 9) && (iVar3 == 0)) && (DAT_140e43f50 == 0)) {
      DAT_140e43f50 = 1;
      FUN_1400b4350(0,0xd);
      save_init_or_reset_candidate();
      uVar11 = (ulonglong)DAT_140e419b8;
      iVar4 = DAT_140e41b00;
      iVar3 = DAT_140e467e8;
      iVar7 = DAT_140e41abc;
    }
    uVar9 = (uint)uVar11;
    if (iVar7 == 0) {
      if (((iVar4 == 0) && (iVar3 == 0)) && (DAT_140e43f58 == 0)) {
        DAT_140e43f58 = 1;
        FUN_1400b4350(0,0xf);
        save_init_or_reset_candidate();
        iVar4 = DAT_140e41b00;
        iVar3 = DAT_140e467e8;
        iVar7 = DAT_140e41abc;
        uVar9 = DAT_140e419b8;
        goto LAB_1400c79fb;
      }
    }
    else {
LAB_1400c79fb:
      if (iVar7 == 1) {
        if (((iVar4 != 0) || (iVar3 != 0)) || (DAT_140e43f5c != 0)) goto LAB_1400c7ae2;
        DAT_140e43f5c = 1;
        FUN_1400b4350(0,0x10);
        save_init_or_reset_candidate();
        iVar4 = DAT_140e41b00;
        iVar3 = DAT_140e467e8;
        iVar7 = DAT_140e41abc;
        uVar9 = DAT_140e419b8;
      }
      if (iVar7 == 2) {
        if (((iVar4 != 0) || (iVar3 != 0)) || (DAT_140e43f60 != 0)) goto LAB_1400c7ae2;
        DAT_140e43f60 = 1;
        FUN_1400b4350(0,0x11);
        save_init_or_reset_candidate();
        iVar4 = DAT_140e41b00;
        iVar3 = DAT_140e467e8;
        iVar7 = DAT_140e41abc;
        uVar9 = DAT_140e419b8;
      }
      if (((iVar7 == 3) && (iVar4 == 0)) && ((iVar3 == 0 && (DAT_140e43f64 == 0)))) {
        DAT_140e43f64 = 1;
        FUN_1400b4350(0,0x12);
        save_init_or_reset_candidate();
        iVar4 = DAT_140e41b00;
        iVar3 = DAT_140e467e8;
        uVar9 = DAT_140e419b8;
      }
    }
LAB_1400c7ae2:
    if (((2 < (int)uVar9) && (iVar4 == 0)) && ((iVar3 == 0 && (DAT_140e43f68 == 0)))) {
      DAT_140e43f68 = 1;
      FUN_1400b4350(0,0x13);
      save_init_or_reset_candidate();
    }
    fopen_s(&local_38,"save\\save.dat","wb");
    FUN_140327c78(&DAT_140e41b10,0x2730,1,local_38);
    FUN_140323e90(local_38);
    if ((DAT_140e44e68 == 0) && (DAT_1407c7798 == 8)) {
      DAT_140e4680c = 1;
    }
    else if (DAT_1407c7798 == 9) {
      DAT_140e4680c = 2;
    }
LAB_1400c7b7e:
    DAT_140e471fc = 0xb4;
    DAT_140e46a20 = 1;
    DAT_140e45270 = 0x20;
  }
switchD_1400c7602_default:
  if (DAT_140e41928 == 2) {
    if (DAT_140e41b00 == 0) {
      FUN_1400f6fb0();
      do {
        FUN_14018f230(*puVar14,0);
        puVar14 = puVar14 + 1;
      } while ((longlong)puVar14 < 0x140e45178);
      DAT_140e45270 = 0x23;
      fopen_s(&local_38,"save\\save.dat","wb");
      FUN_140327c78(&DAT_140e41b10,0x2730,1,local_38);
      FUN_140323e90(local_38);
      DAT_140e471fc = 0xb4;
    }
    else {
      FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4721c);
      FUN_14018a340(DAT_140e4721c,1,1);
      DAT_140e45274 = 0;
      DAT_140e46014 = 0;
      DAT_140e45fac = 0;
      DAT_140e46a20 = 1;
      DAT_140e467fc = 1;
      DAT_140e45270 = 0x27;
      DAT_140e41a38 = 1;
    }
  }
  return;
}


