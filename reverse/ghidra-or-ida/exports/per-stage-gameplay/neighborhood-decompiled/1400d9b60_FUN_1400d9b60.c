// Function: FUN_1400d9b60 @ 1400d9b60
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400d9b60(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  
  uVar8 = FUN_1400dacb0(4);
  uVar9 = FUN_1400dacb0(5);
  uVar10 = FUN_1400dacb0(6);
  uVar11 = FUN_1400dacb0(7);
  uVar12 = FUN_1400dacb0(8);
  uVar13 = FUN_1400dacb0(9);
  uVar14 = FUN_1400dacb0(10);
  uVar15 = FUN_1400dacb0(0xffffffff);
  uVar7 = _UNK_14053bb2c;
  uVar6 = _UNK_14053bb28;
  uVar5 = _UNK_14053bb24;
  uVar4 = _DAT_14053bb20;
  uVar3 = DAT_14053aef4;
  uVar17 = DAT_14053aef0;
  uVar19 = DAT_14053ae48;
  uVar20 = DAT_14053aa20;
  switch(param_1) {
  default:
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar16 = uVar15;
    puVar16[1] = param_2;
    puVar16[2] = 0;
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar16[3] = 0x40a00000;
    puVar16[4] = 0x44160000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    uVar20 = DAT_140e47608;
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    *puVar16 = uVar20;
    puVar16[1] = param_2;
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    puVar16[2] = 0;
    puVar16[3] = 0x42340000;
    puVar16[4] = 0x44160000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar8;
    puVar16[1] = param_2;
    puVar16[2] = 0;
    puVar16[3] = 0x40a00000;
    puVar16[4] = 0x44200000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    uVar20 = DAT_140e47610;
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar20;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[1] = param_2;
    puVar16[2] = 0;
    puVar16[3] = 0x42340000;
    puVar16[4] = 0x44200000;
    *(undefined2 *)(puVar16 + 5) = 0;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar9;
    puVar16[1] = param_2;
    puVar16[2] = 0;
    puVar16[3] = 0x40a00000;
    puVar16[4] = 0x442a0000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    uVar20 = DAT_140e47618;
    DAT_140e46c88 = puVar16;
    puVar16 = (undefined4 *)_malloc_base(0x48);
    if (puVar16 == (undefined4 *)0x0) {
      MessageBoxA((HWND)0x0,"Insufficient memory capacity.","error",0);
    }
    (&DAT_140e46c90)[param_2] = (&DAT_140e46c90)[param_2] + 1;
    bVar18 = DAT_140e46bf0 == (undefined4 *)0x0;
    *puVar16 = uVar20;
    puVar16[1] = param_2;
    puVar16[2] = 0;
    puVar16[3] = 0x42340000;
    puVar16[4] = 0x442a0000;
    *(undefined2 *)(puVar16 + 5) = 0;
    *(undefined8 *)(puVar16 + 6) = 0x3ff0000000000000;
    *(undefined8 *)(puVar16 + 8) = 0x3ff0000000000000;
    puVar16[10] = 0xff;
    puVar16[0xb] = 0xff;
    puVar16[0xc] = 0xff;
    puVar16[0xd] = param_3;
    *(undefined8 *)(puVar16 + 0xe) = 1;
    *(undefined8 *)(puVar16 + 0x10) = 0;
    if (bVar18) {
      DAT_140e46bf0 = puVar16;
    }
    if (DAT_140e46c88 != (undefined4 *)0x0) {
      *(undefined4 **)(DAT_140e46c88 + 0x10) = puVar16;
    }
    break;
  case 1:
    FUN_1400c8410(uVar15,param_2,0,DAT_14053af70,DAT_14053aa20,0,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47608,param_2,0,DAT_14053af84,uVar20,0,CONCAT44(uVar5,uVar4),
                  CONCAT44(uVar7,uVar6),0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(uVar8,param_2,0,DAT_14053afb4,uVar20,0,CONCAT44(uVar5,uVar4),CONCAT44(uVar7,uVar6)
                  ,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47610,param_2,0,DAT_14053afc4,uVar20,0,CONCAT44(uVar5,uVar4),
                  CONCAT44(uVar7,uVar6),0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(uVar9,param_2,0,DAT_14053afd8,uVar20,0,CONCAT44(uVar5,uVar4),CONCAT44(uVar7,uVar6)
                  ,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053afe0;
    uVar17 = DAT_140e47618;
    goto LAB_1400d9dc0;
  case 2:
    uVar1 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
    uVar2 = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
    FUN_1400c8410(DAT_140e470f0,param_2,0,DAT_14053aa20,DAT_14053aef4,0,uVar1,uVar2,0xff,0xff,0xff,
                  param_3,1,0);
    FUN_1400c8410(DAT_140e4762c,param_2,0,DAT_14053acb0,uVar3,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1
                  ,0);
    puVar16 = DAT_140e46c88;
    break;
  case 3:
    uVar1 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
    uVar2 = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
    FUN_1400c8410(uVar8,param_2,0,DAT_14053aa20,DAT_14053ae48,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1
                  ,0);
    uVar17 = DAT_14053acb0;
    FUN_1400c8410(DAT_140e47630,param_2,0,DAT_14053acb0,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,
                  1,0);
    uVar19 = DAT_14053ae7c;
    FUN_1400c8410(uVar15,param_2,0,uVar20,DAT_14053ae7c,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e4760c,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053ae90;
    FUN_1400c8410(uVar10,param_2,0,uVar20,DAT_14053ae90,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47614,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053aea8;
    FUN_1400c8410(uVar11,param_2,0,uVar20,DAT_14053aea8,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e4761c,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053aec0;
    FUN_1400c8410(uVar12,param_2,0,uVar20,DAT_14053aec0,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47620,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053aedc;
    FUN_1400c8410(uVar13,param_2,0,uVar20,DAT_14053aedc,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47624,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053aef4;
    FUN_1400c8410(uVar14,param_2,0,uVar20,DAT_14053aef4,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47628,param_2,0,uVar17,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    puVar16 = DAT_140e46c88;
    break;
  case 4:
    uVar1 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
    uVar2 = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
    FUN_1400c8410(uVar8,param_2,0,DAT_14053aa20,DAT_14053aa20,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1
                  ,0);
    uVar19 = DAT_14053acb0;
    FUN_1400c8410(DAT_140e47634,param_2,0,DAT_14053acb0,uVar20,0,uVar1,uVar2,0xff,0xff,0xff,param_3,
                  1,0);
    FUN_1400c8410(uVar14,param_2,0,uVar20,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47628,param_2,0,uVar19,uVar19,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1,0);
    puVar16 = DAT_140e46c88;
    break;
  case 5:
    uVar1 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
    uVar2 = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
    FUN_1400c8410(uVar9,param_2,0,DAT_14053aa20,DAT_14053aef0,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1
                  ,0);
    FUN_1400c8410(DAT_140e47634,param_2,0,DAT_14053acb0,uVar17,0,uVar1,uVar2,0xff,0xff,0xff,param_3,
                  1,0);
    puVar16 = DAT_140e46c88;
    break;
  case 6:
    uVar1 = CONCAT44(_UNK_14053bb24,_DAT_14053bb20);
    uVar2 = CONCAT44(_UNK_14053bb2c,_UNK_14053bb28);
    FUN_1400c8410(uVar8,param_2,0,DAT_14053afdc,DAT_14053aef0,0,uVar1,uVar2,0xff,0xff,0xff,param_3,1
                  ,0);
    FUN_1400c8410(DAT_140e47630,param_2,0,DAT_14053afe8,uVar17,0,uVar1,uVar2,0xff,0xff,0xff,param_3,
                  1,0);
    puVar16 = DAT_140e46c88;
    break;
  case 7:
    FUN_1400c8410(uVar15,param_2,0,DAT_14053aa20,DAT_14053aef4,0,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47608,param_2,0,DAT_14053acb0,uVar3,0,CONCAT44(uVar5,uVar4),
                  CONCAT44(uVar7,uVar6),0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(uVar8,param_2,0,DAT_14053ad48,uVar3,0,CONCAT44(uVar5,uVar4),CONCAT44(uVar7,uVar6),
                  0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(DAT_140e47638,param_2,0,DAT_14053ad88,uVar3,0,CONCAT44(uVar5,uVar4),
                  CONCAT44(uVar7,uVar6),0xff,0xff,0xff,param_3,1,0);
    FUN_1400c8410(uVar9,param_2,0,DAT_14053ae08,uVar3,0,CONCAT44(uVar5,uVar4),CONCAT44(uVar7,uVar6),
                  0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053ae20;
    uVar20 = uVar3;
    uVar17 = DAT_140e47618;
    goto LAB_1400d9dc0;
  case 8:
    FUN_1400c8410(uVar8,param_2,0,DAT_14053aa20,DAT_14053aa20,0,
                  CONCAT44(_UNK_14053bb24,_DAT_14053bb20),CONCAT44(_UNK_14053bb2c,_UNK_14053bb28),
                  0xff,0xff,0xff,param_3,1,0);
    uVar19 = DAT_14053acb0;
    uVar17 = DAT_140e47630;
LAB_1400d9dc0:
    FUN_1400c8410(uVar17,param_2,0,uVar19,uVar20,0,CONCAT44(uVar5,uVar4),CONCAT44(uVar7,uVar6),0xff,
                  0xff,0xff,param_3,1,0);
    puVar16 = DAT_140e46c88;
  }
  DAT_140e46c88 = puVar16;
  return;
}


