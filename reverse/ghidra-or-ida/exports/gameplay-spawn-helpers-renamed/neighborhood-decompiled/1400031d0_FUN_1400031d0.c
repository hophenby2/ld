// Function: FUN_1400031d0 @ 1400031d0
// Decompile completed: true

void FUN_1400031d0(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  bool bVar7;
  double dVar8;
  
  if (DAT_140e4430c == 0) {
    if (DAT_140e419bc == 5) {
      FUN_140109660(0x18,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),0,0,0,0);
      uVar3 = DAT_140e445a8;
      if (DAT_140e4192c == 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x2c);
        uVar2 = *(undefined4 *)(param_1 + 0x28);
        puVar5 = DAT_140e45d28;
        if (DAT_140e45d1c < 0x1000) {
          puVar5 = (undefined8 *)_malloc_base(0x60);
          if (puVar5 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar5 + 0x14) = uVar2;
          *(undefined4 *)(puVar5 + 3) = uVar1;
          *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar2;
          *(undefined4 *)(puVar5 + 4) = uVar1;
          *puVar5 = 1;
          *(undefined4 *)(puVar5 + 1) = 0x26;
          *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
          *(undefined4 *)(puVar5 + 2) = 0x73;
          *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
          puVar5[5] = 0;
          puVar5[6] = 0x3ff0000000000000;
          puVar5[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar5 + 8) = 0x7e;
          *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
          *(undefined4 *)(puVar5 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
          puVar5[10] = 0xff;
          puVar5[0xb] = 0;
          if (bVar7) {
            DAT_140e45d78 = puVar5;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar5;
          }
        }
        DAT_140e45d28 = puVar5;
        if (DAT_140e41b00 == 0) {
          DAT_140e44188 = DAT_140e44188 + 1;
        }
      }
      uVar3 = DAT_140e445ac;
      puVar5 = DAT_140e45d28;
      if (DAT_140e4192c == 1) {
        uVar1 = *(undefined4 *)(param_1 + 0x2c);
        uVar2 = *(undefined4 *)(param_1 + 0x28);
        if (DAT_140e45d1c < 0x1000) {
          puVar5 = (undefined8 *)_malloc_base(0x60);
          if (puVar5 == (undefined8 *)0x0) {
            MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
          }
          DAT_140e45d1c = DAT_140e45d1c + 1;
          bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
          *(undefined4 *)((longlong)puVar5 + 0x14) = uVar2;
          *(undefined4 *)(puVar5 + 3) = uVar1;
          *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar2;
          *(undefined4 *)(puVar5 + 4) = uVar1;
          *puVar5 = 1;
          *(undefined4 *)(puVar5 + 1) = 0x27;
          *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
          *(undefined4 *)(puVar5 + 2) = 0x73;
          *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
          puVar5[5] = 0;
          puVar5[6] = 0x3ff0000000000000;
          puVar5[7] = 0x3ff0000000000000;
          *(undefined4 *)(puVar5 + 8) = 0x7e;
          *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
          *(undefined4 *)(puVar5 + 9) = 0xff;
          *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
          puVar5[10] = 0xff;
          puVar5[0xb] = 0;
          if (bVar7) {
            DAT_140e45d78 = puVar5;
          }
          if (DAT_140e45d28 != (undefined8 *)0x0) {
            DAT_140e45d28[0xb] = puVar5;
          }
        }
      }
    }
    else {
      stage_pending_effect_flush_candidate();
      puVar5 = DAT_140e45d28;
      if (DAT_140e44654 < 100) {
        DAT_140e44654 = 100;
      }
    }
    DAT_140e45d28 = puVar5;
    uVar3 = *(undefined4 *)(&DAT_140e419dc + (longlong)(DAT_140e445c0 * 10) * 4);
    puVar5 = DAT_140e45d28;
    if (0xfff < DAT_140e45d1c) goto LAB_140003a97;
    puVar5 = (undefined8 *)_malloc_base(0x60);
    if (puVar5 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *(undefined4 *)(puVar5 + 1) = 0x16;
    *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
    puVar5[2] = 0x6f;
    puVar5[6] = 0x3ff0000000000000;
  }
  else {
    FUN_140109660(0x18,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),0,0,0,0);
    uVar3 = DAT_140e445a8;
    iVar6 = DAT_140e45d1c;
    if (DAT_140e4192c == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x2c);
      uVar2 = *(undefined4 *)(param_1 + 0x28);
      iVar4 = DAT_140e4430c / 0xf;
      puVar5 = DAT_140e45d28;
      if (DAT_140e45d1c < 0x1000) {
        puVar5 = (undefined8 *)_malloc_base(0x60);
        if (puVar5 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar6 = DAT_140e45d1c + 1;
        *(undefined4 *)((longlong)puVar5 + 0x14) = uVar2;
        bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar5 + 3) = uVar1;
        *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar2;
        *(undefined4 *)(puVar5 + 4) = uVar1;
        *puVar5 = 1;
        *(undefined4 *)(puVar5 + 1) = 0x26;
        *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
        *(undefined4 *)(puVar5 + 2) = 0x73;
        *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x3ff0000000000000;
        puVar5[7] = 0x3ff0000000000000;
        *(int *)(puVar5 + 8) = iVar4 + 0x3c;
        *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
        *(undefined4 *)(puVar5 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
        puVar5[10] = 0xff;
        puVar5[0xb] = 0;
        if (bVar7) {
          DAT_140e45d78 = puVar5;
        }
        DAT_140e45d1c = iVar6;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar5;
        }
      }
      DAT_140e45d28 = puVar5;
      uVar3 = *(undefined4 *)(&DAT_140e419d8 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar5 = DAT_140e45d28;
      if (iVar6 < 0x1000) {
        puVar5 = (undefined8 *)_malloc_base(0x60);
        if (puVar5 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar6 = DAT_140e45d1c + 1;
        *puVar5 = 1;
        bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar5 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
        puVar5[2] = 0x6f;
        puVar5[3] = 0;
        *(undefined4 *)(puVar5 + 4) = 0;
        *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x3ff0000000000000;
        puVar5[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar5 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
        *(undefined4 *)(puVar5 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
        puVar5[10] = 0xff;
        puVar5[0xb] = 0;
        if (bVar7) {
          DAT_140e45d78 = puVar5;
        }
        DAT_140e45d1c = iVar6;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar5;
        }
      }
      DAT_140e45d28 = puVar5;
      if (DAT_140e41b00 == 0) {
        DAT_140e44188 = DAT_140e44188 + 1;
      }
    }
    uVar3 = DAT_140e445ac;
    puVar5 = DAT_140e45d28;
    if (DAT_140e4192c == 1) {
      uVar1 = *(undefined4 *)(param_1 + 0x2c);
      uVar2 = *(undefined4 *)(param_1 + 0x28);
      iVar4 = DAT_140e4430c / 0xf;
      if (iVar6 < 0x1000) {
        puVar5 = (undefined8 *)_malloc_base(0x60);
        if (puVar5 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar6 = DAT_140e45d1c + 1;
        *(undefined4 *)((longlong)puVar5 + 0x14) = uVar2;
        bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar5 + 3) = uVar1;
        *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar2;
        *(undefined4 *)(puVar5 + 4) = uVar1;
        *puVar5 = 1;
        *(undefined4 *)(puVar5 + 1) = 0x27;
        *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
        *(undefined4 *)(puVar5 + 2) = 0x73;
        *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x3ff0000000000000;
        puVar5[7] = 0x3ff0000000000000;
        *(int *)(puVar5 + 8) = iVar4 + 0x3c;
        *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
        *(undefined4 *)(puVar5 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
        puVar5[10] = 0xff;
        puVar5[0xb] = 0;
        if (bVar7) {
          DAT_140e45d78 = puVar5;
        }
        DAT_140e45d1c = iVar6;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar5;
        }
      }
      DAT_140e45d28 = puVar5;
      uVar3 = *(undefined4 *)(&DAT_140e419c8 + (longlong)(DAT_140e445c0 * 10) * 4);
      puVar5 = DAT_140e45d28;
      if (iVar6 < 0x1000) {
        puVar5 = (undefined8 *)_malloc_base(0x60);
        if (puVar5 == (undefined8 *)0x0) {
          MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
        }
        iVar6 = DAT_140e45d1c + 1;
        *puVar5 = 1;
        bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
        *(undefined4 *)(puVar5 + 1) = 0x16;
        *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
        puVar5[2] = 0x6f;
        puVar5[3] = 0;
        *(undefined4 *)(puVar5 + 4) = 0;
        *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
        puVar5[5] = 0;
        puVar5[6] = 0x3ff0000000000000;
        puVar5[7] = 0x3ff0000000000000;
        *(undefined4 *)(puVar5 + 8) = 0x78;
        *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
        *(undefined4 *)(puVar5 + 9) = 0xff;
        *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
        puVar5[10] = 0xff;
        puVar5[0xb] = 0;
        if (bVar7) {
          DAT_140e45d78 = puVar5;
        }
        DAT_140e45d1c = iVar6;
        if (DAT_140e45d28 != (undefined8 *)0x0) {
          DAT_140e45d28[0xb] = puVar5;
        }
      }
    }
    DAT_140e45d28 = puVar5;
    puVar5 = DAT_140e45d28;
    if ((DAT_140e4192c == -1) &&
       (uVar3 = *(undefined4 *)(&DAT_140e419dc + (longlong)(DAT_140e445c0 * 10) * 4), iVar6 < 0x1000
       )) {
      puVar5 = (undefined8 *)_malloc_base(0x60);
      if (puVar5 == (undefined8 *)0x0) {
        MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
      }
      iVar6 = DAT_140e45d1c + 1;
      *puVar5 = 1;
      bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
      *(undefined4 *)(puVar5 + 1) = 0x16;
      *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
      puVar5[2] = 0x6f;
      puVar5[3] = 0;
      *(undefined4 *)(puVar5 + 4) = 0;
      *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
      puVar5[5] = 0;
      puVar5[6] = 0x3ff0000000000000;
      puVar5[7] = 0x3ff0000000000000;
      *(undefined4 *)(puVar5 + 8) = 0x78;
      *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
      *(undefined4 *)(puVar5 + 9) = 0xff;
      *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
      puVar5[10] = 0xff;
      puVar5[0xb] = 0;
      if (bVar7) {
        DAT_140e45d78 = puVar5;
      }
      DAT_140e45d1c = iVar6;
      if (DAT_140e45d28 != (undefined8 *)0x0) {
        DAT_140e45d28[0xb] = puVar5;
      }
    }
    DAT_140e45d28 = puVar5;
    dVar8 = (double)DAT_140e4430c;
    puVar5 = DAT_140e45d28;
    if (0xfff < iVar6) goto LAB_140003a97;
    puVar5 = (undefined8 *)_malloc_base(0x60);
    if (puVar5 == (undefined8 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    puVar5[6] = dVar8;
    puVar5[1] = 0x28;
    puVar5[2] = 0x72;
  }
  DAT_140e45d1c = DAT_140e45d1c + 1;
  bVar7 = DAT_140e45d78 == (undefined8 *)0x0;
  puVar5[0xb] = 0;
  puVar5[10] = 0xff;
  *(undefined4 *)((longlong)puVar5 + 0x4c) = 0xff;
  *(undefined4 *)(puVar5 + 9) = 0xff;
  *(undefined4 *)((longlong)puVar5 + 0x44) = 0xff;
  *(undefined4 *)(puVar5 + 8) = 0x78;
  puVar5[7] = 0x3ff0000000000000;
  puVar5[5] = 0;
  *(undefined2 *)((longlong)puVar5 + 0x24) = 0;
  *(undefined4 *)(puVar5 + 4) = 0;
  puVar5[3] = 0;
  *puVar5 = 1;
  if (bVar7) {
    DAT_140e45d78 = puVar5;
  }
  if (DAT_140e45d28 != (undefined8 *)0x0) {
    DAT_140e45d28[0xb] = puVar5;
  }
LAB_140003a97:
  DAT_140e45d28 = puVar5;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x54) = 1;
  return;
}


