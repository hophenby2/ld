// Function: FUN_140070e40 @ 140070e40
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140070e40(void)

{
  int iVar1;
  int *piVar2;
  double dVar3;
  double dVar4;
  int *piVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  
  dVar4 = DAT_14053a020;
  dVar3 = DAT_140539d28;
  for (piVar2 = DAT_140e45d78; piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x16)) {
    switch(piVar2[2]) {
    case 0:
    case 1:
    case 2:
    case 3:
      FUN_140071570(piVar2);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
      FUN_140071cb0(piVar2);
      break;
    case 0xc:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
      FUN_140072560(piVar2);
      break;
    case 0xd:
      iVar6 = piVar2[9];
      iVar1 = piVar2[1];
      dVar7 = (double)iVar1 * DAT_140539de8;
      dVar8 = (double)FUN_1403307c0();
      fVar10 = (float)(dVar8 * *(double *)(piVar2 + 10)) + (float)piVar2[5];
      piVar2[5] = (int)fVar10;
      dVar8 = (double)FUN_140332d90();
      fVar9 = (float)(dVar8 * *(double *)(piVar2 + 10)) + (float)piVar2[6];
      piVar2[6] = (int)fVar9;
      FUN_1400c8410(piVar2[3],piVar2[4],8,fVar10,fVar9,(short)iVar6,
                    *(double *)(piVar2 + 0xc) + dVar7,*(double *)(piVar2 + 0xe) + dVar7,0xff,0xff,
                    0xff,piVar2[0x14] - (int)((double)piVar2[0x14] * DAT_140539e80 * (double)iVar1),
                    1,0);
      if (piVar2[1] == 8) {
        *piVar2 = 0;
      }
      break;
    case 0xe:
      FUN_1400732a0(piVar2);
      break;
    case 0x10:
    case 0x11:
    case 0x36:
      FUN_140072930(piVar2);
      break;
    case 0x12:
      FUN_140073050(piVar2);
      break;
    case 0x13:
      iVar1 = piVar2[1];
      iVar6 = 0xff;
      if (0x1f < iVar1) {
        iVar6 = iVar1 * -0x10 + 0x2ff;
      }
      dVar7 = *(double *)(piVar2 + 0xc) + DAT_140539e60;
      *(double *)(piVar2 + 0xc) = dVar7;
      if (iVar1 == 0x30) {
        *piVar2 = 0;
      }
      else if (*piVar2 == 1) {
        FUN_1400c8410(piVar2[3],piVar2[4],8,piVar2[5],piVar2[6],0,dVar7,dVar7,iVar6,iVar6,iVar6,0xff
                      ,1,0);
      }
      break;
    case 0x14:
      iVar1 = piVar2[1];
      dVar7 = (double)FUN_140332d90();
      dVar7 = dVar7 * _DAT_14053b0b8 + DAT_14053a0f8;
      dVar8 = (double)FUN_140332d90();
      iVar6 = (int)(dVar8 * DAT_14053a578);
      if (0x3c < iVar1) {
        iVar6 = 0xc0;
        dVar7 = DAT_140539f40;
      }
      FUN_1400c8410(piVar2[3],piVar2[4],8,DAT_140e445d8,DAT_140e445dc,(short)DAT_140e44acc * -0x400,
                    dVar7,dVar7,0xff,0xff,0xff,iVar6,1,0);
      if (DAT_140e45d34 == 0) {
        *piVar2 = 0;
      }
      break;
    case 0x15:
      FUN_140078110(piVar2);
      break;
    case 0x16:
      iVar1 = piVar2[1];
      iVar6 = 0xff;
      if (iVar1 < 8) {
        dVar7 = (double)FUN_140332d90(((double)iVar1 - 0.0) * DAT_14053aa28 * dVar4 * dVar3);
        iVar6 = (int)(dVar7 * DAT_14053a5f8);
      }
      if (piVar2[0x10] + -8 <= iVar1) {
        dVar7 = (double)FUN_140332d90();
        iVar6 = 0xff - (int)(dVar7 * DAT_14053a5f8);
      }
      iVar1 = piVar2[3];
      piVar5 = (int *)_malloc_base(0x48);
      if (piVar5 == (int *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      *piVar5 = iVar1;
      piVar5[1] = 0x6f;
      piVar5[2] = 0;
      piVar5[3] = 0;
      piVar5[4] = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      piVar5[6] = 0;
      piVar5[7] = 0x3ff00000;
      piVar5[8] = 0;
      piVar5[9] = 0x3ff00000;
      piVar5[10] = 0xff;
      piVar5[0xb] = 0xff;
      piVar5[0xc] = 0xff;
      piVar5[0xd] = iVar6;
      piVar5[0xe] = 1;
      piVar5[0xf] = 0;
      piVar5[0x10] = 0;
      piVar5[0x11] = 0;
      _DAT_140e46e4c = _DAT_140e46e4c + 1;
      if (DAT_140e46bf0 == (int *)0x0) {
        DAT_140e46bf0 = piVar5;
      }
      if (DAT_140e46c88 != (int *)0x0) {
        *(int **)(DAT_140e46c88 + 0x10) = piVar5;
      }
      DAT_140e46c88 = piVar5;
      if (piVar2[1] == piVar2[0x10]) {
        *piVar2 = 0;
      }
      break;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
      FUN_140076130(piVar2);
      break;
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
      FUN_140073e60(piVar2);
      break;
    case 0x2a:
    case 0x2b:
      FUN_1400735a0(piVar2);
      break;
    case 0x2c:
      FUN_140073a60(piVar2);
      break;
    case 0x31:
    case 0x32:
      FUN_1400757a0(piVar2);
      break;
    case 0x33:
    case 0x34:
    case 0x35:
      FUN_140075a00(piVar2);
      break;
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
      FUN_140076b00(piVar2);
      break;
    case 0x3b:
    case 0x3d:
    case 0x3e:
    case 0x42:
      FUN_140076ec0(piVar2);
      break;
    case 0x3c:
      FUN_140077830(piVar2);
      break;
    case 0x3f:
    case 0x40:
      FUN_140077a50(piVar2);
      break;
    case 0x41:
      FUN_140077cf0(piVar2);
      break;
    case 0x49:
    case 0x4a:
      FUN_1400785c0(piVar2);
    }
    piVar2[1] = piVar2[1] + 1;
  }
  return;
}


