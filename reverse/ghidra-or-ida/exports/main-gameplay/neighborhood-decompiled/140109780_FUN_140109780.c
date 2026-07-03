// Function: FUN_140109780 @ 140109780
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140109780(void)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  ushort uVar28;
  uint uVar29;
  ulonglong uVar30;
  undefined8 *puVar31;
  undefined4 *puVar32;
  short sVar33;
  short sVar34;
  int iVar35;
  uint uVar36;
  ushort uVar37;
  int iVar38;
  undefined4 uVar39;
  uint uVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  undefined2 *puVar44;
  ulonglong uVar45;
  longlong lVar46;
  int *piVar47;
  ulonglong uVar48;
  bool bVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  double dVar57;
  undefined4 uVar58;
  float fVar59;
  undefined4 uVar60;
  float fVar61;
  float fVar62;
  undefined4 uVar63;
  undefined4 uVar64;
  undefined4 uVar65;
  undefined4 uVar66;
  undefined4 uVar67;
  float local_res18;
  float fStackX_1c;
  float in_stack_fffffffffffffe08;
  undefined2 uVar68;
  uint in_stack_fffffffffffffe10;
  undefined2 uVar69;
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  double in_stack_fffffffffffffe28;
  
  fVar27 = DAT_14053af14;
  fVar26 = DAT_14053aec0;
  fVar25 = DAT_14053acbc;
  fVar24 = DAT_14053ab70;
  dVar23 = DAT_14053aa28;
  dVar22 = DAT_14053a9d8;
  dVar21 = DAT_14053a900;
  dVar20 = DAT_14053a890;
  dVar19 = DAT_14053a778;
  dVar18 = DAT_14053a578;
  dVar17 = DAT_14053a548;
  dVar16 = DAT_14053a528;
  dVar15 = DAT_14053a500;
  dVar14 = DAT_14053a480;
  dVar13 = DAT_14053a1e8;
  dVar12 = DAT_14053a020;
  uVar11 = DAT_140539fc8;
  dVar10 = DAT_140539f90;
  dVar9 = DAT_140539f40;
  dVar8 = DAT_140539d28;
  if (DAT_140e46ea0 != (int *)0x0) {
    uVar63 = SUB84(DAT_140539f40,0);
    uVar64 = (undefined4)((ulonglong)DAT_140539f40 >> 0x20);
    uVar65 = (undefined4)DAT_140539fc8;
    uVar66 = (undefined4)((ulonglong)DAT_140539fc8 >> 0x20);
    piVar47 = DAT_140e46ea0;
    fStackX_1c = in_stack_fffffffffffffe08;
    do {
      uVar58 = DAT_14053ae30;
      fVar62 = DAT_14053ad40;
      fVar61 = DAT_14053ac18;
      uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
      uVar60 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
      uVar30 = 0;
      dVar57 = 0.0;
      uVar40 = piVar47[2];
      iVar35 = 0;
      switch(uVar40) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
        iVar38 = piVar47[7];
        iVar35 = 0xff;
        uVar67 = 0x80;
        iVar43 = 0xff;
        local_res18 = 1.79366e-43;
        dVar57 = (double)FUN_1403307c0();
        fVar62 = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[3];
        piVar47[3] = (int)fVar62;
        dVar57 = (double)FUN_140332d90();
        fVar61 = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[4];
        piVar47[4] = (int)fVar61;
        uVar58 = uVar63;
        uVar60 = uVar64;
        if (uVar40 < 2) {
          if (DAT_140e445c0 == 0) {
            uVar45 = 0x1c;
          }
          else if (DAT_140e445c0 == 1) {
            uVar45 = 0x2c;
          }
          else if (DAT_140e445c0 == 2) {
            uVar45 = 0x49;
          }
          else {
            uVar45 = 1;
            if (DAT_140e445c0 == 3) {
              uVar45 = uVar30;
            }
          }
          iVar42 = piVar47[1];
          if (iVar42 < 0x11) {
            iVar35 = iVar42 * -5 + 0x82;
            iVar43 = iVar42 * 8 + 0x80;
          }
          else {
            iVar35 = 0x32;
            iVar43 = 0xff;
          }
          piVar47[10] = iVar35;
          iVar35 = iVar43;
          if (uVar40 == 1) {
            iVar43 = 0x80;
            if (iVar42 < 0x11) {
              iVar35 = iVar42 * 8 + 0x80;
              iVar42 = iVar42 * -5 + 0xa0;
            }
            else {
              iVar35 = 0xff;
              iVar42 = 0x50;
            }
            uVar67 = 0xc0;
            piVar47[10] = iVar42;
            local_res18 = 2.69049e-43;
            uVar58 = uVar65;
            uVar60 = uVar66;
          }
          in_stack_fffffffffffffe28 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),0xff);
          auVar70._4_4_ = uVar60;
          auVar70._0_4_ = uVar58;
          auVar70._8_4_ = uVar58;
          auVar70._12_4_ = uVar60;
          in_stack_fffffffffffffe10 =
               CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),(short)iVar38);
          FUN_1400c8410((&DAT_140e44e70)[uVar45],0x2c,7,fVar62,fVar61,in_stack_fffffffffffffe10,
                        auVar70,in_stack_fffffffffffffe28,iVar35,iVar43,uVar67,1,0);
          fStackX_1c = fVar61;
        }
        uVar40 = piVar47[2];
        if ((uVar40 < 10) && ((0x248U >> (uVar40 & 0x1f) & 1) != 0)) {
          iVar35 = 0x80;
          uVar58 = SUB84(dVar10,0);
          uVar60 = (undefined4)((ulonglong)dVar10 >> 0x20);
          iVar43 = 0x80;
        }
        if (((uVar40 == 4) || (uVar40 == 7)) || (uVar39 = 0xff, uVar40 == 10)) {
          if (DAT_140e45d18 < 0) {
            iVar35 = 0xff;
            iVar43 = 0x80;
            uVar39 = 0xff;
          }
          else {
            iVar35 = 0x40;
            uVar39 = 0xc0;
            iVar43 = 0x40;
          }
          uVar67 = 0xc0;
          local_res18 = 2.69049e-43;
          uVar58 = uVar65;
          uVar60 = uVar66;
        }
        if ((uVar40 == 2) || (uVar40 - 3 < 2)) {
          lVar46 = 1;
          if (DAT_140e445c0 == 0) {
            lVar46 = 0x1d;
          }
          else if (DAT_140e445c0 == 1) {
            lVar46 = 0x3a;
          }
          else if (DAT_140e445c0 == 2) {
            lVar46 = 0x4a;
          }
          else if (DAT_140e445c0 == 3) {
            lVar46 = 0;
          }
          in_stack_fffffffffffffe28 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),uVar39);
          fStackX_1c = (float)piVar47[4];
          in_stack_fffffffffffffe10 =
               CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),(short)piVar47[7]);
          FUN_1400c8410((&DAT_140e44e70)[lVar46],0x2c,7,piVar47[3],fStackX_1c,
                        in_stack_fffffffffffffe10,(double)CONCAT44(uVar60,uVar58) * dVar10,
                        CONCAT44(uVar60,uVar58),in_stack_fffffffffffffe28,iVar35,iVar43,uVar67,1,0);
        }
        if (piVar47[2] - 5U < 3) {
          lVar46 = 1;
          if (DAT_140e445c0 == 0) {
            lVar46 = 0x2b;
          }
          else if (DAT_140e445c0 == 1) {
            lVar46 = 0x3b;
          }
          else if (DAT_140e445c0 == 2) {
            lVar46 = 0x58;
          }
          else if (DAT_140e445c0 == 3) {
            lVar46 = 0;
          }
          fStackX_1c = (float)piVar47[4];
          in_stack_fffffffffffffe28 =
               (double)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),uVar39);
          auVar71._4_4_ = uVar60;
          auVar71._0_4_ = uVar58;
          auVar71._8_4_ = uVar58;
          auVar71._12_4_ = uVar60;
          in_stack_fffffffffffffe10 =
               CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),(short)piVar47[7]);
          FUN_1400c8410((&DAT_140e44e70)[lVar46],0x2c,7,piVar47[3],fStackX_1c,
                        in_stack_fffffffffffffe10,auVar71,in_stack_fffffffffffffe28,iVar35,iVar43,
                        uVar67,1,0);
        }
        uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
        uVar67 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
        if (piVar47[2] - 8U < 3) {
          lVar46 = 1;
          if (DAT_140e445c0 == 0) {
LAB_140109dcf:
            lVar46 = 0x59;
          }
          else if (DAT_140e445c0 == 1) {
            lVar46 = 0x67;
          }
          else {
            if (DAT_140e445c0 == 2) goto LAB_140109dcf;
            if (DAT_140e445c0 == 3) {
              lVar46 = 0;
            }
          }
          uVar40 = piVar47[1];
          if ((int)uVar40 < 0x3c) {
            if (DAT_140e445c0 == 0) {
              uVar1 = *(ushort *)(piVar47 + 7);
              iVar41 = (uVar40 + 0x10) * 0x20;
              uVar28 = FUN_140134420(uVar40 & 0xffff,0,uVar1);
              iVar42 = (uint)uVar28 - (uint)uVar1;
              iVar38 = iVar42 + 0x10000;
              if (-0x8001 < iVar42) {
                iVar38 = iVar42;
              }
              iVar42 = iVar38 + -0x10000;
              if (iVar38 < 0x8001) {
                iVar42 = iVar38;
              }
              sVar34 = (short)iVar41;
              if (iVar42 < 1) {
                uVar37 = uVar1;
                if ((iVar42 < 0) &&
                   (uVar37 = uVar1 - sVar34, (int)((uVar40 + 0x10) * -0x20) < iVar42)) {
                  uVar37 = uVar28;
                }
              }
              else {
                uVar37 = uVar28;
                if (iVar41 <= iVar42) {
                  uVar37 = uVar1 + sVar34;
                }
              }
              *(ushort *)(piVar47 + 7) = uVar37;
            }
            if (DAT_140e445c0 == 1) {
              uVar1 = *(ushort *)(piVar47 + 7);
              uVar28 = FUN_140134420(uVar40 & 0xffff,1,uVar1);
              iVar42 = (uint)uVar28 - (uint)uVar1;
              iVar38 = iVar42 + 0x10000;
              if (-0x8001 < iVar42) {
                iVar38 = iVar42;
              }
              iVar42 = iVar38 + -0x10000;
              if (iVar38 < 0x8001) {
                iVar42 = iVar38;
              }
              if (iVar42 < 1) {
                uVar37 = uVar1;
                if ((iVar42 < 0) && (uVar37 = uVar1 - 0x200, -0x200 < iVar42)) {
                  uVar37 = uVar28;
                }
              }
              else {
                uVar37 = uVar28;
                if (0x1ff < iVar42) {
                  uVar37 = uVar1 + 0x200;
                }
              }
              *(ushort *)(piVar47 + 7) = uVar37;
            }
          }
          sVar34 = (short)piVar47[7];
          fStackX_1c = (float)piVar47[4];
          if (DAT_140e445c0 == 0) {
            sVar34 = (short)uVar40 * 0x400 + sVar34;
          }
          auVar72._4_4_ = uVar60;
          auVar72._0_4_ = uVar58;
          auVar72._8_4_ = uVar58;
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar67,uVar39);
          auVar72._12_4_ = uVar60;
          in_stack_fffffffffffffe10 = CONCAT22(uVar69,sVar34);
          FUN_1400c8410((&DAT_140e44e70)[lVar46],0x2c,7,piVar47[3],fStackX_1c,
                        in_stack_fffffffffffffe10,auVar72,in_stack_fffffffffffffe28,iVar35,iVar43,
                        local_res18,1,0);
        }
        iVar35 = (int)(float)piVar47[0xb];
        if (((((float)piVar47[3] < DAT_140e445d8 / fVar24 - (float)(iVar35 + 0xa0)) ||
             ((float)(iVar35 + 0x2f8) + DAT_140e445d8 / fVar24 < (float)piVar47[3])) ||
            ((float)piVar47[4] < (float)-(iVar35 + 0xa0))) ||
           ((float)(iVar35 + 0x370) < (float)piVar47[4])) {
          *piVar47 = 0;
        }
        break;
      case 0xb:
        iVar38 = piVar47[1];
        iVar43 = (iVar38 >> 0x1f & 0xffffff40U) + 0xc0;
        if ((-1 < iVar38) && (iVar38 < 0x20)) {
          dVar57 = (double)FUN_140332d90(((double)iVar38 - 0.0) * dVar19 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          iVar43 = (int)(dVar57 * dVar18);
        }
        if (iVar38 - 0xa4U < 0x10) {
          dVar57 = (double)FUN_140332d90(((double)iVar38 - dVar15) * dVar21 * dVar12 * dVar8);
          iVar43 = (int)(dVar57 * dVar18);
        }
        if (iVar38 < 0xb4) {
          iVar35 = iVar43;
        }
        if (iVar38 == 0) {
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)((uint)fStackX_1c & 0xffff0000);
          FUN_140109660(0x1a);
        }
        uVar69 = DAT_140e44624;
        uVar68 = (undefined2)((uint)fStackX_1c >> 0x10);
        if (piVar47[1] == 0) {
          FUN_1403307c0();
          FUN_140332d90();
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)CONCAT22(uVar68,uVar69);
          FUN_140109660(0xc);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47250);
          FUN_14018a340(DAT_140e47250,1,1);
        }
        uVar69 = DAT_140e44626;
        uVar68 = (undefined2)((uint)fStackX_1c >> 0x10);
        if (piVar47[1] == 8) {
          FUN_1403307c0();
          FUN_140332d90();
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)CONCAT22(uVar68,uVar69);
          FUN_140109660(0xc);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47250);
          FUN_14018a340(DAT_140e47250,1,1);
        }
        uVar69 = DAT_140e44628;
        uVar68 = (undefined2)((uint)fStackX_1c >> 0x10);
        if (piVar47[1] == 0x10) {
          FUN_1403307c0();
          FUN_140332d90();
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)CONCAT22(uVar68,uVar69);
          FUN_140109660(0xc);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47250);
          FUN_14018a340(DAT_140e47250,1,1);
        }
        uVar69 = DAT_140e4462a;
        uVar68 = (undefined2)((uint)fStackX_1c >> 0x10);
        if (piVar47[1] == 0x18) {
          FUN_1403307c0();
          FUN_140332d90();
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)CONCAT22(uVar68,uVar69);
          FUN_140109660(0xc);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47250);
          FUN_14018a340(DAT_140e47250,1,1);
        }
        uVar58 = DAT_140e41ab8;
        puVar32 = (undefined4 *)_malloc_base(0x48);
        if (puVar32 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar32 = uVar58;
        puVar32[0xd] = iVar35;
        goto LAB_14010a3e8;
      case 0xc:
        iVar35 = piVar47[1];
        if ((-1 < iVar35) && (dVar57 = dVar9, iVar35 < 8)) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - 0.0) * dVar23 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          dVar57 = dVar57 + 0.0;
        }
        sVar34 = (short)piVar47[7];
        dVar50 = (double)FUN_1403307c0();
        local_res18 = (float)(dVar50 * *(double *)(piVar47 + 8)) + (float)piVar47[3];
        piVar47[3] = (int)local_res18;
        dVar50 = (double)FUN_140332d90();
        fVar61 = (float)(dVar50 * *(double *)(piVar47 + 8)) + (float)piVar47[4];
        piVar47[4] = (int)fVar61;
        if (iVar35 < 0x14) {
          fVar62 = (float)(int)(float)piVar47[0xb];
          sVar33 = -0x8000 - sVar34;
          if (DAT_140e445d8 / fVar24 + fVar62 <= local_res18) {
            sVar33 = sVar34;
          }
          if ((fVar26 - fVar62) + DAT_140e445d8 / fVar24 < local_res18) {
            sVar33 = -0x8000 - sVar34;
          }
          if (fVar61 < fVar62) {
            sVar33 = -sVar34;
          }
          if (fVar27 - fVar62 < fVar61) {
            sVar33 = -sVar34;
          }
          *(short *)(piVar47 + 7) = sVar33;
          uVar55 = FUN_1401346a0(*(undefined8 *)(piVar47 + 3),(int)(float)piVar47[0xb]);
          local_res18 = (float)uVar55;
          fStackX_1c = (float)((ulonglong)uVar55 >> 0x20);
          piVar47[3] = (int)local_res18;
          piVar47[4] = (int)fStackX_1c;
        }
        fVar61 = (float)piVar47[4];
        if (fVar61 < fVar25) {
LAB_14010a652:
          uVar69 = 0;
          FUN_140109660(0xd);
          FUN_140184700(DAT_140e44190 * 0x19,DAT_140e47254);
          FUN_14018a340(DAT_140e47254,1,1);
          *piVar47 = 0;
        }
        else if (0x13 < piVar47[1]) {
          iVar35 = (int)(float)piVar47[0xb];
          if ((((local_res18 < DAT_140e445d8 / fVar24 - (float)iVar35) ||
               ((float)(iVar35 + 600) + DAT_140e445d8 / fVar24 < local_res18)) ||
              (fVar61 < (float)-iVar35)) || ((float)(iVar35 + 0x2d0) < fVar61)) goto LAB_14010a652;
        }
        fStackX_1c = (float)piVar47[4];
        in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
        auVar3._8_4_ = SUB84(dVar57,0);
        auVar3._0_8_ = dVar57;
        auVar3._12_4_ = (int)((ulonglong)dVar57 >> 0x20);
        in_stack_fffffffffffffe10 = CONCAT22(uVar69,(short)DAT_140e44acc * 999);
        FUN_1400c8410(DAT_140e41a58,0x3c,7,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,auVar3,
                      in_stack_fffffffffffffe28,0xff,0xff,0xff,1,0);
        uVar40 = piVar47[1] * 0x457 + DAT_140e418c8;
        uVar40 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 1;
        uVar29 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 2;
        uVar29 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 3;
        uVar40 = uVar40 * 0x800 ^ uVar40;
        uVar29 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 4;
        uVar36 = piVar47[1] * 0x6f + DAT_140e418c8;
        uVar36 = (uVar36 >> 0x1e ^ uVar36) * 0x6c078965 + 1;
        DAT_140e9fd10 = (uVar36 >> 0x1e ^ uVar36) * 0x6c078965 + 2;
        DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
        DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
        uVar36 = uVar36 * 0x800 ^ uVar36;
        DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar36) >> 8 ^ DAT_140e9fd18 ^ uVar36;
        dVar50 = (double)(((uVar29 >> 0xb ^ uVar40) >> 8 ^ uVar40 ^ uVar29) % 0x33);
        dVar57 = (double)FUN_1403307c0();
        fVar62 = (float)(dVar57 * dVar50) + (float)piVar47[3];
        dVar57 = (double)FUN_140332d90();
        uVar58 = DAT_140e41930;
        fVar61 = (float)(dVar57 * dVar50) + (float)piVar47[4];
        puVar31 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar31 = (undefined8 *)_malloc_base(0x60);
          if (puVar31 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar49 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)((longlong)puVar31 + 0x14) = fVar62;
          *(float *)(puVar31 + 3) = fVar61;
          *(float *)((longlong)puVar31 + 0x1c) = fVar62;
          *(float *)(puVar31 + 4) = fVar61;
          *puVar31 = 1;
          *(undefined4 *)(puVar31 + 1) = 8;
          *(undefined4 *)((longlong)puVar31 + 0xc) = uVar58;
          *(undefined4 *)(puVar31 + 2) = 0x3b;
          *(undefined2 *)((longlong)puVar31 + 0x24) = 0;
          puVar31[5] = 0;
          puVar31[6] = 0x3fe999999999999a;
          puVar31[7] = 0x3fe999999999999a;
          *(undefined4 *)(puVar31 + 8) = 0x14;
          *(undefined4 *)((longlong)puVar31 + 0x44) = 0xff;
          *(undefined4 *)(puVar31 + 9) = 0xc0;
          *(undefined4 *)((longlong)puVar31 + 0x4c) = 0x40;
          puVar31[10] = 0x80;
          puVar31[0xb] = 0;
          if (bVar49) {
            DAT_140e45d78 = puVar31;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar31;
          }
        }
        DAT_140e45d28 = puVar31;
        if (piVar47[1] == 0x94) {
          *piVar47 = 0;
        }
        break;
      case 0xd:
        iVar35 = piVar47[1];
        if (iVar35 < 0) {
LAB_14010aa05:
          dVar57 = 0.0;
        }
        else if (iVar35 < 10) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - 0.0) * dVar22 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          dVar57 = dVar57 * dVar16 + 0.0;
        }
        else {
          dVar57 = dVar16;
          if (0x77 < iVar35) {
            if (0x81 < iVar35) goto LAB_14010aa05;
            dVar57 = (double)FUN_140332d90(((double)iVar35 - dVar14) * dVar22 * dVar12 * dVar8,
                                           DAT_14053a248,999);
            dVar57 = dVar57 * dVar16 + 0.0;
          }
        }
        in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
        sVar34 = (short)DAT_140e44acc * 2000;
        piVar47[0xb] = (int)(float)dVar57;
        dVar57 = (double)(float)dVar57 / dVar17;
        fStackX_1c = (float)piVar47[4];
        in_stack_fffffffffffffe10 = CONCAT22(uVar69,sVar34);
        FUN_1400c8410(DAT_140e45064,0x3c,7,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,dVar57,
                      dVar57,in_stack_fffffffffffffe28,0xff,0xff,0xc0,1,0);
        if (piVar47[1] == 0x82) {
          *piVar47 = 0;
        }
        break;
      case 0xe:
        iVar35 = piVar47[1];
        uVar40 = (iVar35 >> 0x1f & 0xffffff40U) + 0xc0;
        if ((-1 < iVar35) && (iVar35 < 0x20)) {
          dVar50 = (double)FUN_140332d90(((double)iVar35 - 0.0) * dVar19 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          uVar40 = (uint)(dVar50 * dVar18);
        }
        if (iVar35 - 0xa4U < 0x10) {
          dVar50 = (double)FUN_140332d90(((double)iVar35 - dVar15) * dVar21 * dVar12 * dVar8);
          uVar40 = (uint)(dVar50 * dVar18);
        }
        if (iVar35 < 0xb4) {
          uVar30 = (ulonglong)uVar40;
        }
        uVar60 = (undefined4)uVar30;
        if (iVar35 == 0) {
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)((uint)fStackX_1c & 0xffff0000);
          FUN_140109660(0x19);
        }
        uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
        uVar58 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
        iVar35 = piVar47[1];
        puVar31 = DAT_140e45d28;
        if (iVar35 < 0x1e) {
          if (-1 < iVar35) {
            if (iVar35 < 0x14) {
              dVar57 = ((double)iVar35 - 0.0) * dVar20;
            }
            else {
              dVar57 = ((double)iVar35 - dVar13) * dVar22;
            }
            dVar57 = (double)FUN_140332d90(dVar57 * dVar12 * dVar8);
            dVar57 = dVar57 + 0.0;
          }
          dVar50 = *(double *)(piVar47 + 8);
          if (0.0 < dVar50) {
            dVar50 = dVar50 - DAT_140539f10;
            *(double *)(piVar47 + 8) = dVar50;
          }
          sVar34 = (short)piVar47[7];
          dVar51 = (double)FUN_1403307c0();
          fVar59 = (float)(dVar51 * dVar50) + (float)piVar47[3];
          piVar47[3] = (int)fVar59;
          dVar51 = (double)FUN_140332d90();
          fVar62 = (float)(int)(float)piVar47[0xb];
          fVar61 = (float)(dVar51 * dVar50) + (float)piVar47[4];
          piVar47[4] = (int)fVar61;
          sVar33 = -0x8000 - sVar34;
          if (DAT_140e445d8 / fVar24 + fVar62 <= fVar59) {
            sVar33 = sVar34;
          }
          if ((fVar26 - fVar62) + DAT_140e445d8 / fVar24 < fVar59) {
            sVar33 = -0x8000 - sVar34;
          }
          if (fVar61 < fVar62) {
            sVar33 = -sVar34;
          }
          if (fVar27 - fVar62 < fVar61) {
            sVar33 = -sVar34;
          }
          *(short *)(piVar47 + 7) = sVar33;
          uVar30 = FUN_1401346a0(*(undefined8 *)(piVar47 + 3),(int)(float)piVar47[0xb]);
          fStackX_1c = (float)(uVar30 >> 0x20);
          local_res18 = (float)uVar30;
          sVar34 = (short)DAT_140e44acc * 999;
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar58,0xff);
          auVar2._8_4_ = SUB84(dVar57,0);
          auVar2._0_8_ = dVar57;
          auVar2._12_4_ = (int)((ulonglong)dVar57 >> 0x20);
          piVar47[3] = (int)local_res18;
          in_stack_fffffffffffffe10 = CONCAT22(uVar69,sVar34);
          piVar47[4] = (int)fStackX_1c;
          FUN_1400c8410(DAT_140e41a58,0x3c,7,uVar30 & 0xffffffff,fStackX_1c,
                        in_stack_fffffffffffffe10,auVar2,in_stack_fffffffffffffe28,0xff,0xff,0xff,1,
                        0);
          uVar40 = piVar47[1] * 0x457 + DAT_140e418c8;
          uVar40 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 1;
          uVar29 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 2;
          uVar29 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 3;
          uVar40 = uVar40 * 0x800 ^ uVar40;
          uVar36 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 4;
          uVar29 = piVar47[1] * 0x6f + DAT_140e418c8;
          uVar29 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar29 = uVar29 * 0x800 ^ uVar29;
          dVar50 = (double)(((uVar36 >> 0xb ^ uVar40) >> 8 ^ uVar40 ^ uVar36) % 0x33);
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar29) >> 8 ^ uVar29 ^ DAT_140e9fd18;
          dVar57 = (double)FUN_1403307c0();
          fVar62 = (float)(dVar57 * dVar50) + (float)piVar47[3];
          dVar57 = (double)FUN_140332d90();
          uVar58 = DAT_140e41930;
          fVar61 = (float)(dVar57 * dVar50) + (float)piVar47[4];
          puVar31 = DAT_140e45d28;
          if (DAT_140e45d1c < 0x1000) {
            puVar31 = (undefined8 *)_malloc_base(0x60);
            if (puVar31 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar49 = DAT_140e45d78 == (undefined8 *)0x0;
            *(float *)((longlong)puVar31 + 0x14) = fVar62;
            *(float *)(puVar31 + 3) = fVar61;
            *(float *)((longlong)puVar31 + 0x1c) = fVar62;
            *(float *)(puVar31 + 4) = fVar61;
            *puVar31 = 1;
            *(undefined4 *)(puVar31 + 1) = 8;
            *(undefined4 *)((longlong)puVar31 + 0xc) = uVar58;
            *(undefined4 *)(puVar31 + 2) = 0x3b;
            *(undefined2 *)((longlong)puVar31 + 0x24) = 0;
            puVar31[5] = 0;
            puVar31[6] = 0x3fe999999999999a;
            puVar31[7] = 0x3fe999999999999a;
            *(undefined4 *)(puVar31 + 8) = 0x14;
            *(undefined4 *)((longlong)puVar31 + 0x44) = 0xff;
            *(undefined4 *)(puVar31 + 9) = 0xc0;
            *(undefined4 *)((longlong)puVar31 + 0x4c) = 0x40;
            puVar31[10] = 0x80;
            puVar31[0xb] = 0;
            if (bVar49) {
              DAT_140e45d78 = puVar31;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar31;
            }
          }
        }
        DAT_140e45d28 = puVar31;
        dVar57 = DAT_14053a5f0;
        iVar35 = piVar47[1];
        puVar31 = DAT_140e45d28;
        if (0x1d < iVar35) {
          if (iVar35 < 0x28) {
            dVar50 = (double)FUN_140332d90(((double)iVar35 - DAT_14053a2d8) * dVar22 * dVar12 *
                                           dVar8);
            dVar57 = dVar50 * dVar57 + 0.0;
          }
          piVar47[0xb] = (int)(float)dVar57;
          if (iVar35 == 0x1e) {
            FUN_140184700(DAT_140e44190 * 0x19,DAT_140e4725c);
            FUN_14018a340(DAT_140e4725c,1,1);
            piVar47[10] = 0x20;
            piVar47[8] = 0;
            piVar47[9] = 0x3ff00000;
          }
          dVar57 = (double)FUN_1403307c0();
          fVar62 = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[3];
          piVar47[3] = (int)fVar62;
          dVar57 = (double)FUN_140332d90();
          fVar61 = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[4];
          piVar47[4] = (int)fVar61;
          uVar40 = piVar47[1] & 0x80000007;
          if ((int)uVar40 < 0) {
            uVar40 = (uVar40 - 1 | 0xfffffff8) + 1;
          }
          puVar31 = DAT_140e45d28;
          if (uVar40 == 0) {
            in_stack_fffffffffffffe28 = (double)(float)piVar47[0xb] / DAT_14053a4a0;
            uVar40 = piVar47[1] & 0x8000000f;
            if ((int)uVar40 < 0) {
              uVar40 = (uVar40 - 1 | 0xfffffff0) + 1;
            }
            if ((int)uVar40 < 0) {
              uVar40 = uVar40 + 7;
            }
            in_stack_fffffffffffffe10 = in_stack_fffffffffffffe10 & 0xffff0000;
            FUN_140070d00(0x20,*(undefined4 *)(&DAT_140e45068 + (longlong)((int)uVar40 >> 3) * 4),
                          0x3c,fVar62,fVar61,in_stack_fffffffffffffe10,0,
                          (double)(float)piVar47[0xb] / DAT_14053a510,in_stack_fffffffffffffe28,0x28
                          ,0xff,0xff,0xff,0xff,0);
            puVar31 = DAT_140e45d28;
            fStackX_1c = fVar61;
          }
        }
        goto LAB_14010b156;
      case 0xf:
        iVar35 = piVar47[1];
        piVar47[3] = (int)DAT_140e445d8;
        uVar40 = (iVar35 >> 0x1f & 0xffffff40U) + 0xc0;
        piVar47[4] = DAT_140e445dc;
        if ((-1 < iVar35) && (iVar35 < 0x20)) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - 0.0) * dVar19 * dVar12 * dVar8);
          uVar40 = (uint)(dVar57 * dVar18);
        }
        if (iVar35 - 0xa4U < 0x10) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - dVar15) * dVar21 * dVar12 * dVar8);
          uVar40 = (uint)(dVar57 * dVar18);
        }
        if (iVar35 < 0xb4) {
          uVar30 = (ulonglong)uVar40;
        }
        uVar60 = (undefined4)uVar30;
        if (iVar35 == (iVar35 / 3 + (iVar35 >> 0x1f) +
                      (int)(((longlong)iVar35 / 3 + ((longlong)iVar35 >> 0x3f) & 0xffffffffU) >>
                           0x1f)) * 3) {
          puVar44 = &DAT_140e44624;
          do {
            in_stack_fffffffffffffe10 = 0;
            fStackX_1c = (float)((uint)fStackX_1c & 0xffff0000);
            FUN_140109660(0x10);
            puVar44 = puVar44 + 1;
          } while ((longlong)puVar44 < 0x140e4462c);
          FUN_140184700(DAT_140e44190 << 4,DAT_140e47260);
          FUN_14018a340(DAT_140e47260,1,1);
        }
        uVar58 = DAT_140e45060;
        iVar35 = DAT_140e445dc;
        fVar61 = DAT_140e445d8;
        puVar31 = DAT_140e45d28;
        if ((piVar47[1] == (piVar47[1] / 0x1e) * 0x1e) && (DAT_140e45d1c < 0x1000)) {
          puVar31 = (undefined8 *)_malloc_base(0x60);
          if (puVar31 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar49 = DAT_140e45d78 == (undefined8 *)0x0;
          *(float *)((longlong)puVar31 + 0x14) = fVar61;
          *(int *)(puVar31 + 3) = iVar35;
          *(float *)((longlong)puVar31 + 0x1c) = fVar61;
          *(int *)(puVar31 + 4) = iVar35;
          *puVar31 = 1;
          *(undefined4 *)(puVar31 + 1) = 0x13;
          *(undefined4 *)((longlong)puVar31 + 0xc) = uVar58;
          *(undefined4 *)(puVar31 + 2) = 0x5b;
          *(undefined2 *)((longlong)puVar31 + 0x24) = 0;
          puVar31[5] = 0;
          puVar31[6] = 0;
          puVar31[7] = 0;
          *(undefined4 *)(puVar31 + 8) = 0;
          *(undefined4 *)((longlong)puVar31 + 0x44) = 0xff;
          *(undefined4 *)(puVar31 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar31 + 0x4c) = 0xff;
          puVar31[10] = 0xff;
          puVar31[0xb] = 0;
          if (bVar49) {
            DAT_140e45d78 = puVar31;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar31;
          }
        }
        goto LAB_14010b156;
      case 0x10:
        iVar35 = piVar47[7];
        dVar57 = (double)FUN_1403307c0();
        fVar61 = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[3];
        piVar47[3] = (int)fVar61;
        dVar57 = (double)FUN_140332d90();
        in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
        auVar73._8_4_ = uVar63;
        auVar73._0_8_ = dVar9;
        auVar73._12_4_ = uVar64;
        in_stack_fffffffffffffe10 = CONCAT22(uVar69,(short)iVar35);
        fStackX_1c = (float)(dVar57 * *(double *)(piVar47 + 8)) + (float)piVar47[4];
        piVar47[4] = (int)fStackX_1c;
        FUN_1400c8410(DAT_140e41a5c,0x3c,7,fVar61,fStackX_1c,in_stack_fffffffffffffe10,auVar73,
                      in_stack_fffffffffffffe28,0xff,0xff,0xff,1,0);
        uVar58 = DAT_140e41a5c;
        iVar43 = piVar47[7];
        iVar35 = piVar47[4];
        iVar38 = piVar47[3];
        puVar31 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar31 = (undefined8 *)_malloc_base(0x60);
          if (puVar31 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar49 = DAT_140e45d78 == (undefined8 *)0x0;
          *(int *)((longlong)puVar31 + 0x14) = iVar38;
          *(int *)(puVar31 + 3) = iVar35;
          *(int *)((longlong)puVar31 + 0x1c) = iVar38;
          *(int *)(puVar31 + 4) = iVar35;
          *puVar31 = 1;
          *(undefined4 *)(puVar31 + 1) = 5;
          *(undefined4 *)((longlong)puVar31 + 0xc) = uVar58;
          *(undefined4 *)(puVar31 + 2) = 0x3b;
          *(short *)((longlong)puVar31 + 0x24) = (short)iVar43;
          puVar31[5] = 0;
          puVar31[6] = 0x3ff0000000000000;
          puVar31[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar31 + 8) = 0xc;
          *(undefined4 *)((longlong)puVar31 + 0x44) = 0xff;
          *(undefined4 *)(puVar31 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar31 + 0x4c) = 0xff;
          puVar31[10] = 0x80;
          puVar31[0xb] = 0;
          if (bVar49) {
            DAT_140e45d78 = puVar31;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar31;
          }
        }
        DAT_140e45d28 = puVar31;
        if ((float)piVar47[4] <= DAT_14053b408 && DAT_14053b408 != (float)piVar47[4]) {
          *piVar47 = 0;
        }
        break;
      case 0x11:
        iVar38 = piVar47[1];
        iVar43 = (iVar38 >> 0x1f & 0xffffff40U) + 0xc0;
        if ((-1 < iVar38) && (iVar38 < 0x20)) {
          dVar57 = (double)FUN_140332d90(((double)iVar38 - 0.0) * dVar19 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          iVar43 = (int)(dVar57 * dVar18);
        }
        if (iVar38 - 0x248U < 0x10) {
          dVar57 = (double)FUN_140332d90(((double)iVar38 - _DAT_14053a7b8) * dVar21 * dVar12 * dVar8
                                        );
          iVar43 = (int)(dVar57 * dVar18);
        }
        if (iVar38 < 600) {
          iVar35 = iVar43;
        }
        if (iVar38 == 0) {
          in_stack_fffffffffffffe10 = 0;
          fStackX_1c = (float)((uint)fStackX_1c & 0xffff0000);
          FUN_140109660(0x18);
          DAT_140e44658 = 600;
        }
        uVar58 = DAT_140e41ab8;
        puVar32 = (undefined4 *)_malloc_base(0x48);
        if (puVar32 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar32 = uVar58;
        *(undefined8 *)(puVar32 + 1) = 0x17;
        *(undefined8 *)(puVar32 + 3) = 0;
        *(undefined2 *)(puVar32 + 5) = 0;
        *(undefined8 *)(puVar32 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 10) = 0;
        puVar32[0xc] = 0;
        puVar32[0xd] = iVar35;
        *(undefined8 *)(puVar32 + 0xe) = 1;
        *(undefined8 *)(puVar32 + 0x10) = 0;
        _DAT_140e46cec = _DAT_140e46cec + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar32;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar32;
        }
        DAT_140e46c88 = puVar32;
        if (piVar47[1] == 600) goto LAB_14010b74f;
        if (0x3b < piVar47[1]) {
          bVar49 = DAT_140e44600 == -0xb3;
          goto LAB_14010b74d;
        }
        break;
      case 0x12:
        iVar35 = piVar47[1];
        uVar40 = (iVar35 >> 0x1f & 0xffffff40U) + 0xc0;
        if ((-1 < iVar35) && (iVar35 < 0x20)) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - 0.0) * dVar19 * dVar12 * dVar8,
                                         DAT_14053a248,999);
          uVar40 = (uint)(dVar57 * dVar18);
        }
        if (iVar35 - 0xa4U < 0x10) {
          dVar57 = (double)FUN_140332d90(((double)iVar35 - dVar15) * dVar21 * dVar12 * dVar8);
          uVar40 = (uint)(dVar57 * dVar18);
        }
        uVar58 = DAT_140e45060;
        iVar38 = DAT_140e445dc;
        fVar61 = DAT_140e445d8;
        uVar69 = (undefined2)((uint)fStackX_1c >> 0x10);
        if (iVar35 < 0xb4) {
          uVar30 = (ulonglong)uVar40;
        }
        uVar60 = (undefined4)uVar30;
        puVar31 = DAT_140e45d28;
        if ((iVar35 == (iVar35 / 0x28) * 0x28) && (iVar35 < 0x97)) {
          if (DAT_140e45d1c < 0x1000) {
            puVar31 = (undefined8 *)_malloc_base(0x60);
            if (puVar31 == (undefined8 *)0x0) {
              MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
            }
            DAT_140e45d1c = DAT_140e45d1c + 1;
            bVar49 = DAT_140e45d78 == (undefined8 *)0x0;
            *(float *)((longlong)puVar31 + 0x14) = fVar61;
            *(int *)(puVar31 + 3) = iVar38;
            *(float *)((longlong)puVar31 + 0x1c) = fVar61;
            *(int *)(puVar31 + 4) = iVar38;
            *puVar31 = 1;
            *(undefined4 *)(puVar31 + 1) = 0x13;
            *(undefined4 *)((longlong)puVar31 + 0xc) = uVar58;
            *(undefined4 *)(puVar31 + 2) = 0x5b;
            *(undefined2 *)((longlong)puVar31 + 0x24) = 0;
            puVar31[5] = 0;
            puVar31[6] = 0;
            puVar31[7] = 0;
            *(undefined4 *)(puVar31 + 8) = 0;
            *(undefined4 *)((longlong)puVar31 + 0x44) = 0xff;
            *(undefined4 *)(puVar31 + 9) = 0xff;
            *(undefined4 *)((longlong)puVar31 + 0x4c) = 0xff;
            puVar31[10] = 0xff;
            puVar31[0xb] = 0;
            if (bVar49) {
              DAT_140e45d78 = puVar31;
            }
            if (DAT_140e45d28 != (undefined8 *)0x0) {
              DAT_140e45d28[0xb] = puVar31;
            }
          }
          DAT_140e45d28 = puVar31;
          in_stack_fffffffffffffe10 = 0;
          uVar40 = (DAT_140e418c8 >> 0x1e ^ DAT_140e418c8) * 0x6c078965 + 1;
          DAT_140e9fd10 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 2;
          DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
          uVar40 = uVar40 * 0x800 ^ uVar40;
          DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
          DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar40) >> 8 ^ uVar40 ^ DAT_140e9fd18;
          fStackX_1c = (float)CONCAT22(uVar69,(short)DAT_140e9fd1c -
                                              (short)(DAT_140e9fd1c / 0x10001));
          FUN_140109660(0x13,(ulonglong)DAT_140e9fd1c / 0x10001,DAT_140e9fd10,0,fStackX_1c,0);
          puVar31 = DAT_140e45d28;
        }
LAB_14010b156:
        DAT_140e45d28 = puVar31;
        uVar58 = DAT_140e41ab8;
        puVar32 = (undefined4 *)_malloc_base(0x48);
        if (puVar32 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar32 = uVar58;
        puVar32[0xd] = uVar60;
LAB_14010a3e8:
        *(undefined8 *)(puVar32 + 1) = 0x17;
        *(undefined8 *)(puVar32 + 3) = 0;
        *(undefined2 *)(puVar32 + 5) = 0;
        *(undefined8 *)(puVar32 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 10) = 0;
        puVar32[0xc] = 0;
        *(undefined8 *)(puVar32 + 0xe) = 1;
        *(undefined8 *)(puVar32 + 0x10) = 0;
        _DAT_140e46cec = _DAT_140e46cec + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar32;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar32;
        }
        bVar49 = piVar47[1] == 0xb4;
        DAT_140e46c88 = puVar32;
        goto LAB_14010a45a;
      case 0x13:
        if (piVar47[1] == (piVar47[1] / 5) * 5) {
          do {
            uVar69 = (undefined2)((uint)fStackX_1c >> 0x10);
            fVar62 = (float)piVar47[1] * fVar61 + DAT_14053acfc;
            FUN_1403307c0();
            dVar57 = (double)FUN_140332d90();
            uVar40 = DAT_140e418c8 + (int)uVar30;
            in_stack_fffffffffffffe10 = 0;
            uVar40 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar40 >> 0x1e ^ uVar40) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar40 = uVar40 * 0x800 ^ uVar40;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar40) >> 8 ^ DAT_140e9fd18 ^ uVar40;
            fStackX_1c = (float)CONCAT22(uVar69,(short)DAT_140e9fd1c -
                                                (short)(DAT_140e9fd1c / 0x10001));
            FUN_140109660(0x14,(ulonglong)DAT_140e9fd1c / 0x10001,
                          (float)(dVar57 * (double)fVar62) + (float)piVar47[4],0,fStackX_1c,5);
            uVar40 = (int)uVar30 + 0xd05;
            uVar30 = (ulonglong)uVar40;
          } while ((int)uVar40 < 9999);
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47264,999);
          FUN_14018a340(DAT_140e47264,1,1);
        }
        bVar49 = piVar47[1] == 0x5a;
        goto LAB_14010a45a;
      case 0x14:
        if (*piVar47 == 1) {
          iVar38 = piVar47[1];
          iVar43 = 0xc0;
          if (iVar38 - 0x18U < 6) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - DAT_14053a268) * _DAT_14053aa68 *
                                           dVar12 * dVar8);
            iVar43 = (int)(dVar57 * dVar18);
          }
          dVar57 = (double)FUN_140332d90();
          if (iVar38 < 0x1e) {
            iVar35 = iVar43;
          }
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
          fVar61 = (float)(dVar57 * (double)(float)piVar47[0xc]) + 0.0;
          piVar47[0xb] = (int)fVar61;
          dVar57 = (double)fVar61 / _DAT_14053a3e8;
          in_stack_fffffffffffffe10 = CONCAT22(uVar69,(short)piVar47[7]);
          fStackX_1c = (float)piVar47[4];
          FUN_1400c8410(DAT_140e41a70,0x3c,8,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,dVar57,
                        dVar57,in_stack_fffffffffffffe28,0xff,0xff,iVar35,1,0);
          bVar49 = piVar47[1] == 0x1e;
          goto LAB_14010a45a;
        }
        break;
      case 0x15:
        uVar40 = piVar47[1];
        iVar38 = ((int)uVar40 >> 0x1f & 0xffffffd0U) + 0x30;
        dVar57 = (double)(float)piVar47[0xb] / DAT_14053a5f0;
        uVar60 = SUB84(dVar57,0);
        uVar67 = (undefined4)((ulonglong)dVar57 >> 0x20);
        if (uVar40 < 0x20) {
          dVar50 = (double)FUN_140332d90(((double)(int)uVar40 - 0.0) * dVar19 * dVar12 * dVar8);
          iVar38 = (int)(dVar50 * DAT_14053a368);
LAB_14010be4e:
          if (0xef < (int)uVar40) {
LAB_14010be56:
            iVar38 = iVar35;
          }
          iVar43 = ((int)uVar40 >> 0x1f & 0xffffff40U) + 0xc0;
          if (uVar40 < 0x20) {
            dVar50 = (double)FUN_140332d90(((double)(int)uVar40 - 0.0) * dVar19 * dVar12 * dVar8);
            iVar43 = (int)(dVar50 * dVar18);
LAB_14010beb5:
            if ((int)uVar40 < 0xf0) goto LAB_14010bec5;
          }
          else {
            if ((int)uVar40 < 0xe0) goto LAB_14010beb5;
            if ((int)uVar40 < 0xf0) goto LAB_14010bf79;
          }
          iVar43 = 0;
        }
        else {
          if ((int)uVar40 < 0xe0) goto LAB_14010be4e;
          if (0xef < (int)uVar40) goto LAB_14010be56;
          dVar50 = (double)FUN_140332d90(((double)(int)uVar40 - _DAT_14053a5a8) * dVar21 * dVar12 *
                                         dVar8);
          iVar38 = (int)(dVar50 * DAT_14053a368);
LAB_14010bf79:
          dVar50 = (double)FUN_140332d90(((double)(int)uVar40 - _DAT_14053a5a8) * dVar21 * dVar12 *
                                         dVar8);
          iVar43 = (int)(dVar50 * dVar18);
        }
LAB_14010bec5:
        uVar40 = piVar47[1];
        piVar47[3] = (int)DAT_140e445d8;
        piVar47[4] = DAT_140e445dc;
        if (uVar40 < 0x20) {
          dVar50 = ((double)(int)uVar40 - 0.0) * dVar19;
LAB_14010bfe5:
          dVar50 = (double)FUN_140332d90(dVar50 * dVar12 * dVar8);
          iVar42 = (int)(dVar50 * DAT_14053a598);
        }
        else {
          iVar42 = ((int)uVar40 >> 0x1f & 0xffffff38U) + 200;
          if ((0xe5 < (int)uVar40) && (iVar42 = iVar35, (int)uVar40 < 0xf0)) {
            dVar50 = ((double)(int)uVar40 - DAT_14053a5c0) * dVar22;
            goto LAB_14010bfe5;
          }
        }
        fVar61 = DAT_14053ad80;
        piVar47[0xb] = (int)(float)iVar42;
        uVar45 = uVar30;
        do {
          uVar55 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),0xff);
          fVar59 = (float)(int)uVar45;
          uVar39 = CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),0x4000);
          fVar62 = (float)((piVar47[1] * 3) % 0x78) + fVar59 * fVar62;
          fVar59 = (float)((piVar47[1] * 3) % 0xa0) + fVar59 * fVar61;
          FUN_1400c8410(DAT_140e45074,0x3c,8,fVar62,uVar58,uVar39,uVar11,dVar9,uVar55,0xff,0xff,
                        iVar38,1,0);
          uVar55 = CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
          uVar40 = CONCAT22((short)((uint)uVar39 >> 0x10),0x4000);
          FUN_1400c8410(DAT_140e45074,0x3c,8,fVar27 - fVar62,uVar58,uVar40,uVar11,dVar9,uVar55,0xff,
                        0xff,iVar38,1,0);
          uVar55 = CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
          uVar40 = uVar40 & 0xffff0000;
          FUN_1400c8410(DAT_140e45074,0x3c,8,uVar58,fVar59,uVar40,uVar11,dVar9,uVar55,0xff,0xff,
                        iVar38,1,0);
          in_stack_fffffffffffffe28 = (double)CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
          in_stack_fffffffffffffe10 = uVar40 & 0xffff0000;
          FUN_1400c8410(DAT_140e45074,0x3c,8,uVar58,fVar27 - fVar59,in_stack_fffffffffffffe10,uVar11
                        ,dVar9,in_stack_fffffffffffffe28,0xff,0xff,iVar38,1,0);
          uVar40 = (int)uVar45 + 1;
          uVar45 = (ulonglong)uVar40;
          fVar62 = DAT_14053ad40;
        } while ((int)uVar40 < 7);
        uVar55 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),0xff);
        auVar4._8_4_ = uVar60;
        auVar4._0_8_ = dVar57;
        auVar4._12_4_ = uVar67;
        uVar58 = CONCAT22((short)(in_stack_fffffffffffffe10 >> 0x10),(short)piVar47[1] * 0x29a);
        FUN_1400c8410(DAT_140e45070,0x3c,7,piVar47[3],piVar47[4],uVar58,auVar4,uVar55,0xff,0xff,0xa0
                      ,1,0);
        in_stack_fffffffffffffe28 = (double)CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
        auVar5._8_4_ = uVar60;
        auVar5._0_8_ = dVar57;
        auVar5._12_4_ = uVar67;
        in_stack_fffffffffffffe10 =
             CONCAT22((short)((uint)uVar58 >> 0x10),(short)piVar47[1] * -0x29a);
        FUN_1400c8410(DAT_140e45070,0x3c,7,piVar47[3],piVar47[4],in_stack_fffffffffffffe10,auVar5,
                      in_stack_fffffffffffffe28,0xff,0xff,0xa0,1,0);
        do {
          uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
          uVar58 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
          iVar35 = piVar47[1];
          dVar50 = (double)(float)piVar47[0xb];
          dVar51 = (double)FUN_1403307c0();
          fVar61 = (float)piVar47[3];
          dVar52 = (double)FUN_140332d90();
          fVar62 = (float)piVar47[4];
          dVar53 = (double)FUN_1403307c0();
          fVar59 = (float)piVar47[3];
          dVar54 = (double)FUN_140332d90();
          uVar55 = CONCAT44(uVar58,0xff);
          auVar6._8_4_ = uVar60;
          auVar6._0_8_ = dVar57;
          auVar6._12_4_ = uVar67;
          uVar58 = CONCAT22(uVar69,(short)iVar35 * 0x29a);
          fStackX_1c = (float)(dVar54 * dVar50) + (float)piVar47[4];
          FUN_1400c8410(DAT_140e41938,0x3c,8,(float)(dVar51 * dVar50) + fVar61,
                        (float)(dVar52 * dVar50) + fVar62,uVar58,auVar6,uVar55,0xff,0xff,0xff,1,0);
          in_stack_fffffffffffffe28 = (double)CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
          auVar7._8_4_ = uVar60;
          auVar7._0_8_ = dVar57;
          auVar7._12_4_ = uVar67;
          in_stack_fffffffffffffe10 =
               CONCAT22((short)((uint)uVar58 >> 0x10),(short)piVar47[1] * 0x29a);
          FUN_1400c8410(DAT_140e41938,0x3c,8,(float)(dVar53 * dVar50) + fVar59,fStackX_1c,
                        in_stack_fffffffffffffe10,auVar7,in_stack_fffffffffffffe28,0xff,0xff,0xff,1,
                        0);
          uVar40 = (int)uVar30 + 1;
          uVar30 = (ulonglong)uVar40;
        } while ((int)uVar40 < 3);
        if (piVar47[1] == (piVar47[1] / 0x14) * 0x14) {
          FUN_140184700(DAT_140e44190 * 0x13,DAT_140e47268);
          FUN_14018a340(DAT_140e47268,1,1);
        }
        uVar58 = DAT_140e41ab8;
        puVar32 = (undefined4 *)_malloc_base(0x48);
        if (puVar32 == (undefined4 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        *puVar32 = uVar58;
        *(undefined8 *)(puVar32 + 6) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 8) = 0x3ff0000000000000;
        *(undefined8 *)(puVar32 + 1) = 0x17;
        *(undefined8 *)(puVar32 + 3) = 0;
        *(undefined2 *)(puVar32 + 5) = 0;
        *(undefined8 *)(puVar32 + 10) = 0;
        puVar32[0xc] = 0;
        puVar32[0xd] = iVar43;
        *(undefined8 *)(puVar32 + 0xe) = 1;
        *(undefined8 *)(puVar32 + 0x10) = 0;
        _DAT_140e46cec = _DAT_140e46cec + 1;
        if (DAT_140e46bf0 == (undefined4 *)0x0) {
          DAT_140e46bf0 = puVar32;
        }
        if (DAT_140e46c88 != (undefined4 *)0x0) {
          *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar32;
        }
        bVar49 = piVar47[1] == 0xf0;
        DAT_140e46c88 = puVar32;
        goto LAB_14010a45a;
      case 0x16:
        uVar45 = uVar30;
        uVar48 = uVar30;
        if (piVar47[1] == 0) {
          do {
            uVar40 = DAT_140e418c8;
            uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
            uVar29 = (int)uVar30 + DAT_140e418c8;
            iVar38 = (int)uVar45 + DAT_140e418c8;
            uVar29 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 1;
            DAT_140e9fd10 = (uVar29 >> 0x1e ^ uVar29) * 0x6c078965 + 2;
            DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
            uVar29 = uVar29 * 0x800 ^ uVar29;
            DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
            uVar29 = (DAT_140e9fd18 >> 0xb ^ uVar29) >> 8 ^ DAT_140e9fd18 ^ uVar29;
            DAT_140e9fd1c = uVar29;
            in_stack_fffffffffffffe28 = (double)FUN_140134db0(iVar38);
            uVar55 = FUN_140134db0(iVar38);
            uVar56 = FUN_140134db0((int)uVar48 + uVar40);
            fStackX_1c = (float)piVar47[4];
            in_stack_fffffffffffffe10 = CONCAT22(uVar69,(short)uVar29 - (short)(uVar29 / 0x10001));
            FUN_140070d00(0x2c,DAT_140e44ea8,0x48,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,
                          uVar56,uVar55,in_stack_fffffffffffffe28,0,0xff,0xff,0xff,0xc0,0);
            uVar40 = (int)uVar30 + 0x21;
            uVar30 = (ulonglong)uVar40;
            uVar45 = (ulonglong)((int)uVar45 + 0xd05);
            uVar48 = (ulonglong)((int)uVar48 + 0x14d);
          } while ((int)uVar40 < 0x420);
        }
        uVar69 = (undefined2)(in_stack_fffffffffffffe10 >> 0x10);
        uVar58 = (undefined4)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
        iVar38 = piVar47[1];
        if (iVar38 < 0x61) {
          iVar43 = 0xff;
          if (iVar38 - 0x50U < 0x10) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - DAT_14053a3b0) * dVar21 * dVar12 *
                                           dVar8);
            iVar43 = (int)(dVar57 * DAT_14053a5f8);
          }
          iVar42 = (int)(float)piVar47[0xc];
          if (iVar38 < 0x60) {
            iVar35 = iVar43;
          }
          if (iVar38 < 0) {
            iVar42 = 0x14;
          }
          else if (iVar38 < 0x20) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - 0.0) * dVar19 * dVar12 * dVar8);
            iVar42 = (int)(dVar57 * (double)(iVar42 + -0x14)) + 0x14;
          }
          uVar55 = CONCAT44(uVar58,0xff);
          piVar47[0xb] = (int)(float)iVar42;
          uVar58 = CONCAT22(uVar69,(short)iVar38 * 0x400);
          FUN_1400c8410(DAT_140e45078,0x3c,8,piVar47[3],piVar47[4],uVar58,
                        (double)iVar42 / DAT_14053a598,(double)iVar42 / DAT_14053a598,uVar55,0xff,
                        0xff,iVar35,1,0);
          in_stack_fffffffffffffe28 = (double)CONCAT44((int)((ulonglong)uVar55 >> 0x20),0xff);
          in_stack_fffffffffffffe10 =
               CONCAT22((short)((uint)uVar58 >> 0x10),(short)piVar47[1] * -0x400);
          fStackX_1c = (float)piVar47[4];
          FUN_1400c8410(DAT_140e45078,0x3c,8,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,
                        (double)(float)piVar47[0xb] / DAT_14053a598,
                        (double)(float)piVar47[0xb] / DAT_14053a598,in_stack_fffffffffffffe28,0xff,
                        0xff,iVar35,1,0);
        }
        bVar49 = piVar47[1] == 0x60;
LAB_14010b74d:
        if (bVar49) {
LAB_14010b74f:
          *piVar47 = 0;
        }
        break;
      case 0x17:
      case 0x18:
        if (*piVar47 == 1) {
          iVar38 = piVar47[1];
          iVar43 = 0xff;
          if (iVar38 - 0x20U < 0x10) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - DAT_14053a248) * dVar21 * dVar12 *
                                           dVar8);
            iVar43 = (int)(dVar57 * DAT_14053a5f8);
          }
          dVar57 = DAT_14053a5f0;
          if (iVar38 < 0x30) {
            iVar35 = iVar43;
          }
          if ((iVar38 == 0) && (DAT_140e44654 < 100)) {
            DAT_140e44654 = 100;
          }
          fVar61 = (float)piVar47[0xb] + DAT_14053ac60;
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
          piVar47[0xb] = (int)fVar61;
          fStackX_1c = (float)piVar47[4];
          dVar57 = (double)fVar61 / dVar57;
          in_stack_fffffffffffffe10 = in_stack_fffffffffffffe10 & 0xffff0000;
          FUN_1400c8410(DAT_140e45060,0x46,8,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,dVar57,
                        dVar57,in_stack_fffffffffffffe28,0xff,0xff,iVar35,1,0);
          bVar49 = piVar47[1] == 0x30;
          goto LAB_14010a45a;
        }
        break;
      case 0x19:
        if (*piVar47 == 1) {
          iVar38 = piVar47[1];
          iVar43 = 0xff;
          if (iVar38 - 0x10U < 8) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - DAT_14053a178) * dVar23 * dVar12 *
                                           dVar8);
            iVar43 = (int)(dVar57 * DAT_14053a5f8);
          }
          dVar57 = DAT_14053a5f0;
          if (iVar38 < 0x18) {
            iVar35 = iVar43;
          }
          if ((iVar38 == 0) && (DAT_140e44654 < 100)) {
            DAT_140e44654 = 100;
          }
          fVar61 = (float)piVar47[0xb] + fVar25;
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
          piVar47[0xb] = (int)fVar61;
          fStackX_1c = (float)piVar47[4];
          dVar57 = (double)fVar61 / dVar57;
          in_stack_fffffffffffffe10 = in_stack_fffffffffffffe10 & 0xffff0000;
          FUN_1400c8410(DAT_140e45060,0x46,8,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,dVar57,
                        dVar57,in_stack_fffffffffffffe28,0xff,0xff,iVar35,1,0);
          bVar49 = piVar47[1] == 0x18;
          goto LAB_14010a45a;
        }
        break;
      case 0x1a:
        if (*piVar47 == 1) {
          iVar38 = piVar47[1];
          iVar43 = 0x60;
          if (iVar38 - 0x10U < 8) {
            dVar57 = (double)FUN_140332d90(((double)iVar38 - DAT_14053a178) * dVar23 * dVar12 *
                                           dVar8);
            iVar43 = (int)(dVar57 * DAT_14053a450);
          }
          dVar57 = (double)FUN_140332d90();
          if (iVar38 < 0x18) {
            iVar35 = iVar43;
          }
          in_stack_fffffffffffffe28 = (double)CONCAT44(uVar60,0xff);
          fVar61 = (float)(dVar57 * (double)(float)piVar47[0xc]) + 0.0;
          piVar47[0xb] = (int)fVar61;
          dVar57 = (double)fVar61 / _DAT_14053a3e8;
          in_stack_fffffffffffffe10 = in_stack_fffffffffffffe10 & 0xffff0000;
          fStackX_1c = (float)piVar47[4];
          FUN_1400c8410(DAT_140e41a54,0x46,8,piVar47[3],fStackX_1c,in_stack_fffffffffffffe10,dVar57,
                        dVar57,in_stack_fffffffffffffe28,0xff,0xff,iVar35,1,0);
          bVar49 = piVar47[1] == 0x18;
          goto LAB_14010a45a;
        }
        break;
      default:
        bVar49 = piVar47[1] == 1;
LAB_14010a45a:
        if (bVar49) {
          *piVar47 = 0;
        }
      }
      piVar47[1] = piVar47[1] + 1;
      piVar47 = *(int **)(piVar47 + 0xe);
    } while (piVar47 != (int *)0x0);
  }
  return;
}


