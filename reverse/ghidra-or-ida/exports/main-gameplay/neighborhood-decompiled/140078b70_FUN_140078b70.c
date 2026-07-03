// Function: FUN_140078b70 @ 140078b70
// Decompile completed: true

void FUN_140078b70(void)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  undefined8 local_78;
  undefined8 uStack_60;
  undefined8 uStack_50;
  undefined8 local_28;
  
  for (puVar3 = DAT_140e45d80; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0xc]) {
    uVar1 = *(uint *)(puVar3 + 3);
    if (uVar1 < 0x154) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch((&DAT_1400799a8)[(int)uVar1]) {
      case 0:
        FUN_1401327d0(puVar3);
        break;
      case 1:
        FUN_1401331c0(puVar3);
        break;
      case 2:
        FUN_140082d90(puVar3);
        break;
      case 3:
        FUN_140083db0(puVar3);
        break;
      case 4:
        FUN_14007c9c0(puVar3);
        break;
      case 5:
        FUN_14007d4e0(puVar3);
        break;
      case 6:
        FUN_14007dfb0(puVar3);
        break;
      case 7:
        FUN_14007ea30(puVar3);
        break;
      case 8:
        FUN_14007f2c0(puVar3);
        break;
      case 9:
        FUN_140080170(puVar3);
        break;
      case 10:
        FUN_140080fb0(puVar3);
        break;
      case 0xb:
        FUN_140082090(puVar3);
        break;
      case 0xc:
        FUN_140007960(puVar3);
        break;
      case 0xd:
        FUN_140007fc0(puVar3);
        break;
      case 0xe:
        FUN_1400841d0(puVar3);
        break;
      case 0xf:
        FUN_140084be0(puVar3);
        break;
      case 0x10:
        FUN_1400853f0(puVar3);
        break;
      case 0x11:
        FUN_140085f70(puVar3);
        break;
      case 0x12:
        FUN_140086aa0(puVar3);
        break;
      case 0x13:
        FUN_1400870a0(puVar3);
        break;
      case 0x14:
        FUN_140087750(puVar3);
        break;
      case 0x15:
        FUN_140088110(puVar3);
        break;
      case 0x16:
        FUN_140088c20(puVar3);
        break;
      case 0x17:
        FUN_14000d480(puVar3);
        break;
      case 0x18:
        FUN_14000e3b0(puVar3);
        break;
      case 0x19:
        FUN_1400894a0(puVar3);
        break;
      case 0x1a:
        FUN_140089e00(puVar3);
        break;
      case 0x1b:
        FUN_14008a970(puVar3);
        break;
      case 0x1c:
        FUN_14008bd60(puVar3);
        break;
      case 0x1d:
        FUN_14008b480(puVar3);
        break;
      case 0x1e:
        FUN_14008d230(puVar3);
        break;
      case 0x1f:
        FUN_14008dfb0(puVar3);
        break;
      case 0x20:
        FUN_14008e710(puVar3);
        break;
      case 0x21:
        FUN_14008efc0(puVar3);
        break;
      case 0x22:
        FUN_14008ffe0(puVar3);
        break;
      case 0x23:
        FUN_140011a80(puVar3);
        break;
      case 0x24:
        FUN_1400120b0(puVar3);
        break;
      case 0x25:
        FUN_140012dc0(puVar3);
        break;
      case 0x26:
        FUN_140013c00(puVar3);
        break;
      case 0x27:
        FUN_140090c30(puVar3);
        break;
      case 0x28:
        FUN_140091540(puVar3);
        break;
      case 0x29:
        FUN_140092230(puVar3);
        break;
      case 0x2a:
        FUN_140092b20(puVar3);
        break;
      case 0x2b:
        FUN_140093540(puVar3);
        break;
      case 0x2c:
        FUN_1400941d0(puVar3);
        break;
      case 0x2d:
        FUN_140094bc0(puVar3);
        break;
      case 0x2e:
        FUN_140095130(puVar3);
        break;
      case 0x2f:
        FUN_140018480(puVar3);
        break;
      case 0x30:
        FUN_14001ac40(puVar3);
        break;
      case 0x31:
        FUN_14001b540(puVar3);
        break;
      case 0x32:
        FUN_140096890(puVar3);
        break;
      case 0x33:
        FUN_140097270(puVar3);
        break;
      case 0x34:
        FUN_140097d30(puVar3);
        break;
      case 0x35:
        FUN_140098700(puVar3);
        break;
      case 0x36:
        FUN_140098f40(puVar3);
        break;
      case 0x37:
        FUN_140099570(puVar3);
        break;
      case 0x38:
        FUN_140099e50(puVar3);
        break;
      case 0x39:
        FUN_14009a4a0(puVar3);
        break;
      case 0x3a:
        FUN_14009b0a0(puVar3);
        break;
      case 0x3b:
        FUN_14009b5f0(puVar3);
        break;
      case 0x3c:
        FUN_14009c530(puVar3);
        break;
      case 0x3d:
        FUN_14009cd10(puVar3);
        break;
      case 0x3e:
        FUN_1400210c0(puVar3);
        break;
      case 0x3f:
        FUN_140021c80(puVar3);
        break;
      case 0x40:
        FUN_140022120(puVar3);
        break;
      case 0x41:
        FUN_14009d610(puVar3);
        break;
      case 0x42:
        FUN_14009e3d0(puVar3);
        break;
      case 0x43:
        FUN_14009eca0(puVar3);
        break;
      case 0x44:
        FUN_14009f5d0(puVar3);
        break;
      case 0x45:
        FUN_1400a0220(puVar3);
        break;
      case 0x46:
        FUN_1400a0e90(puVar3);
        break;
      case 0x47:
        FUN_1400a1730(puVar3);
        break;
      case 0x48:
        FUN_1400a1df0(puVar3);
        break;
      case 0x49:
        FUN_1400dc1c0(puVar3);
        break;
      case 0x4a:
        FUN_140026b80(puVar3);
        break;
      case 0x4b:
        FUN_1400270f0(puVar3);
        break;
      case 0x4c:
        FUN_1400289b0(puVar3);
        break;
      case 0x4d:
        FUN_140029880(puVar3);
        break;
      case 0x4e:
        FUN_14002aac0(puVar3);
        break;
      case 0x4f:
        FUN_1400a2310(puVar3);
        break;
      case 0x50:
        FUN_1400a2ca0(puVar3);
        break;
      case 0x51:
        FUN_1400a3990(puVar3);
        break;
      case 0x52:
        FUN_1400a4440(puVar3);
        break;
      case 0x53:
        FUN_1400a4fe0(puVar3);
        break;
      case 0x54:
        FUN_1400a5dd0(puVar3);
        break;
      case 0x55:
        FUN_1400a7760(puVar3);
        break;
      case 0x56:
        FUN_1400a8a80(puVar3);
        break;
      case 0x57:
        FUN_1400e0680(puVar3);
        break;
      case 0x58:
        FUN_1400e20e0(puVar3);
        break;
      case 0x59:
        FUN_140032040(puVar3);
        break;
      case 0x5a:
        FUN_140036410(puVar3);
        break;
      case 0x5b:
        FUN_14002d2f0(puVar3);
        break;
      case 0x5c:
        FUN_140032740(puVar3);
        break;
      case 0x5d:
        FUN_140033070(puVar3);
        break;
      case 0x5e:
        FUN_140034670(puVar3);
        break;
      case 0x5f:
        FUN_140034e90(puVar3);
        break;
      case 0x60:
        FUN_140036b60(puVar3);
        break;
      case 0x61:
        FUN_140037b30(puVar3);
        break;
      case 0x62:
        FUN_1400a9080(puVar3);
        break;
      case 99:
        FUN_1400a9af0(puVar3);
        break;
      case 100:
        FUN_1400aa590(puVar3);
        break;
      case 0x65:
        FUN_1400ab110(puVar3);
        break;
      case 0x66:
        FUN_1400abc50(puVar3);
        break;
      case 0x67:
        FUN_1400acd20(puVar3);
        break;
      case 0x68:
        FUN_1400ad970(puVar3);
        break;
      case 0x69:
        FUN_140040750(puVar3);
        break;
      case 0x6a:
        FUN_140041710(puVar3);
        break;
      case 0x6b:
        FUN_140041e90(puVar3);
        break;
      case 0x6c:
        FUN_140042b10(puVar3);
        break;
      case 0x6d:
        FUN_140043710(puVar3);
        break;
      case 0x6e:
        FUN_140043fa0(puVar3);
        break;
      case 0x6f:
        FUN_140044910(puVar3);
        break;
      case 0x70:
        FUN_140045080(puVar3);
        break;
      case 0x71:
        FUN_140045aa0(puVar3);
        break;
      case 0x72:
        FUN_1400465d0(puVar3);
        break;
      case 0x73:
        FUN_1400483e0(puVar3);
        break;
      case 0x74:
        FUN_1400488b0(puVar3);
        break;
      case 0x75:
        FUN_14004a4a0(puVar3);
        break;
      case 0x76:
        FUN_1400e47c0(puVar3);
        break;
      case 0x77:
        FUN_1400e6340(puVar3);
        break;
      case 0x78:
        FUN_1400e8570(puVar3);
        break;
      case 0x79:
        FUN_1400e9e20(puVar3);
        break;
      case 0x7a:
        FUN_1400ee200(puVar3);
        break;
      case 0x7b:
        FUN_1400ee710(puVar3);
        break;
      case 0x7c:
        FUN_140051030(puVar3);
        break;
      case 0x7d:
        FUN_1400512b0(puVar3);
        break;
      case 0x7e:
        FUN_1400526c0(puVar3);
        break;
      case 0x7f:
        FUN_1400f1250(puVar3);
        break;
      case 0x80:
        FUN_1400f3060(puVar3);
        break;
      case 0x81:
        FUN_1400f4430(puVar3);
        break;
      case 0x82:
        FUN_1400af090(puVar3);
        break;
      case 0x83:
        FUN_1400af900(puVar3);
        break;
      case 0x84:
        FUN_1400b0120(puVar3);
        break;
      case 0x85:
        FUN_1400b0b70(puVar3);
        break;
      case 0x86:
        FUN_1400b14d0(puVar3);
        break;
      case 0x87:
        FUN_1400b1db0(puVar3);
        break;
      case 0x88:
        FUN_1400b2760(puVar3);
        break;
      case 0x89:
        FUN_1400b3540(puVar3);
        break;
      case 0x8a:
        FUN_140057f90(puVar3);
        break;
      case 0x8b:
        FUN_140058ad0(puVar3);
        break;
      case 0x8c:
        FUN_140059000(puVar3);
        break;
      case 0x8d:
        FUN_14005a3f0(puVar3);
        break;
      case 0x8e:
        FUN_14005b4a0(puVar3);
        break;
      case 0x8f:
        FUN_14005cc30(puVar3);
        break;
      case 0x90:
        FUN_14005dd50(puVar3);
        break;
      case 0x91:
        FUN_14005e4e0(puVar3);
        break;
      case 0x92:
        FUN_14005e890(puVar3);
        break;
      case 0x93:
        FUN_14005fc20(puVar3);
        break;
      case 0x94:
        FUN_140061a00(puVar3);
        break;
      case 0x95:
        FUN_140062060(puVar3);
        break;
      case 0x96:
        FUN_1400630f0(puVar3);
        break;
      case 0x97:
        FUN_140063ec0(puVar3);
        break;
      case 0x98:
        FUN_140064630(puVar3);
        break;
      case 0x99:
        FUN_140066370(puVar3);
        break;
      case 0x9a:
        FUN_14006a2e0(puVar3);
        break;
      case 0x9b:
        FUN_14006a8b0(puVar3);
        break;
      case 0x9c:
        FUN_14006ad60(puVar3);
        break;
      case 0x9d:
        FUN_140059760(puVar3);
        break;
      case 0x9e:
        FUN_14007c1a0(puVar3);
        break;
      case 0x9f:
        FUN_140004660(puVar3);
        break;
      case 0xa0:
        FUN_140009480(puVar3);
        break;
      case 0xa1:
        FUN_14000ed10(puVar3);
        break;
      case 0xa2:
        FUN_140014bf0(puVar3);
        break;
      case 0xa3:
        FUN_14001c8b0(puVar3);
        break;
      case 0xa4:
        FUN_140023260(puVar3);
        break;
      case 0xa5:
        FUN_14002b680(puVar3);
        break;
      case 0xa6:
        FUN_140038190(puVar3);
        break;
      case 0xa7:
        FUN_14004a970(puVar3);
        break;
      case 0xa8:
        FUN_140052fb0(puVar3);
        break;
      case 0xa9:
        FUN_1400db1f0(puVar3);
        break;
      case 0xaa:
        FUN_1400dcd10(puVar3);
        break;
      case 0xab:
        FUN_1400de960(puVar3);
        break;
      case 0xac:
        FUN_1400e3070(puVar3);
        break;
      case 0xad:
        FUN_1400e5260(puVar3);
        break;
      case 0xae:
        FUN_1400e6f70(puVar3);
        break;
      case 0xaf:
        FUN_1400e8d20(puVar3);
        break;
      case 0xb0:
        FUN_1400eb780(puVar3);
        break;
      case 0xb1:
        FUN_1400ed2a0(puVar3);
        break;
      case 0xb2:
        FUN_1400ef010(puVar3);
        break;
      case 0xb3:
        if (uVar1 - 0x14d < 2) {
          *(undefined4 *)(puVar3 + 0xb) = 0;
        }
        if (*(int *)((longlong)puVar3 + 0xc) == 1) {
          *(undefined4 *)puVar3 = 0;
        }
        break;
      case 0xb4:
        iVar6 = *(int *)(puVar3 + 1);
        uStack_60 = 0;
        uStack_60._4_4_ = 0;
        local_78 = 0;
        local_78._0_4_ = 0;
        if ((0 < DAT_140e44e6c) &&
           (puVar4 = DAT_140e45d80, local_78._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
          do {
            if (*(int *)((longlong)puVar4 + 4) == iVar6) {
              local_78 = *puVar4;
              uStack_60 = puVar4[3];
              uStack_50 = puVar4[5];
              local_28 = puVar4[10];
            }
            puVar4 = (undefined8 *)puVar4[0xc];
          } while (puVar4 != (undefined8 *)0x0);
        }
        *(undefined4 *)((longlong)puVar3 + 0x54) = local_28._4_4_;
        iVar2 = *(int *)((longlong)puVar3 + 0x1c);
        *(float *)(puVar3 + 5) = (float)uStack_50 + *(float *)(puVar3 + 6);
        *(float *)((longlong)puVar3 + 0x2c) = uStack_50._4_4_ + *(float *)((longlong)puVar3 + 0x34);
        if ((iVar2 < uStack_60._4_4_) && (puVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)) {
          for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
            if (*(int *)((longlong)puVar4 + 4) == iVar6) {
              *(int *)((longlong)puVar4 + 0x1c) =
                   *(int *)((longlong)puVar4 + 0x1c) - (uStack_60._4_4_ - iVar2);
            }
          }
        }
        iVar6 = *(int *)((longlong)puVar3 + 0x1c);
        if (uStack_60._4_4_ < *(int *)((longlong)puVar3 + 0x1c)) {
          *(int *)((longlong)puVar3 + 0x1c) = uStack_60._4_4_;
          iVar6 = uStack_60._4_4_;
        }
        if ((iVar6 < 1) && (iVar6 = *(int *)(puVar3 + 1), puVar4 = DAT_140e45d80, 0 < DAT_140e44e6c)
           ) {
          for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
            if (*(int *)((longlong)puVar4 + 4) == iVar6) {
              *(int *)((longlong)puVar4 + 0x1c) =
                   *(int *)((longlong)puVar4 + 0x1c) - uStack_60._4_4_;
            }
          }
        }
        if ((int)local_78 == 0) {
          *(undefined4 *)puVar3 = 0;
        }
        break;
      case 0xb5:
        iVar6 = *(int *)((longlong)puVar3 + 0x1c);
        iVar2 = *(int *)(puVar3 + 1);
        iVar5 = (int)((ulonglong)((longlong)*(int *)(puVar3 + 4) * -0x77777777) >> 0x20) +
                *(int *)(puVar3 + 4);
        iVar5 = (iVar5 >> 4) - (iVar5 >> 0x1f);
        if (iVar5 < iVar6) {
          puVar4 = DAT_140e45d80;
          if (0 < DAT_140e44e6c) {
            for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
              if (*(int *)((longlong)puVar4 + 4) == iVar2) {
                *(int *)((longlong)puVar4 + 0x1c) = *(int *)((longlong)puVar4 + 0x1c) - iVar5;
              }
            }
          }
          iVar6 = (int)((ulonglong)((longlong)*(int *)(puVar3 + 4) * 0x77777777) >> 0x20) -
                  *(int *)(puVar3 + 4);
          *(int *)((longlong)puVar3 + 0x1c) =
               *(int *)((longlong)puVar3 + 0x1c) + ((iVar6 >> 4) - (iVar6 >> 0x1f));
        }
        else {
          puVar4 = DAT_140e45d80;
          if (0 < DAT_140e44e6c) {
            for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[0xc]) {
              if (*(int *)((longlong)puVar4 + 4) == iVar2) {
                *(int *)((longlong)puVar4 + 0x1c) = *(int *)((longlong)puVar4 + 0x1c) - iVar6;
              }
            }
          }
          *(undefined4 *)puVar3 = 0;
        }
      }
    }
    if (*(int *)((longlong)puVar3 + 0x54) == 0) {
      FUN_1400cc2f0(puVar3);
    }
    *(int *)((longlong)puVar3 + 0xc) = *(int *)((longlong)puVar3 + 0xc) + 1;
    if (*(int *)((longlong)puVar3 + 0x54) == 0) {
      *(int *)(puVar3 + 2) = *(int *)(puVar3 + 2) + 1;
    }
  }
  return;
}


