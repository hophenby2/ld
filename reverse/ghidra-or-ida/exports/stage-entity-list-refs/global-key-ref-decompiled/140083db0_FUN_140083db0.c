// Function: FUN_140083db0 @ 140083db0
// Decompile completed: true

undefined8 * FUN_140083db0(undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  undefined1 auVar3 [16];
  double dVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 local_res8;
  undefined4 uStackX_c;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar13;
  undefined8 local_b8;
  int iStack_9c;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  
  uVar13 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  local_b8 = 0;
  iStack_9c = 0;
  puVar6 = DAT_140e45d80;
  iVar7 = 0;
  local_b8._0_4_ = 0;
  if ((0 < DAT_140e44e6c) && (local_b8._0_4_ = 0, DAT_140e45d80 != (undefined8 *)0x0)) {
    do {
      if (*(int *)((longlong)puVar6 + 4) == param_1[2]) {
        local_b8 = *puVar6;
        iStack_9c = *(int *)((longlong)puVar6 + 0x1c);
        uStack_90 = *(undefined4 *)(puVar6 + 5);
        uStack_8c = *(undefined4 *)((longlong)puVar6 + 0x2c);
      }
      puVar6 = (undefined8 *)puVar6[0xc];
    } while (puVar6 != (undefined8 *)0x0);
    puVar6 = (undefined8 *)0x0;
    iVar7 = iStack_9c;
  }
  if (param_1[3] == 0) {
    uVar9 = (param_1[1] + 0x6f >> 0x1e ^ param_1[1] + 0x6f) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar9 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
    puVar6 = (undefined8 *)((ulonglong)DAT_140e9fd1c * 0xffff0001 & 0xffffffff);
    *(short *)((longlong)param_1 + 0x42) = (short)DAT_140e9fd1c - (short)(DAT_140e9fd1c / 0x10001);
  }
  if (param_1[0x15] == 1) {
    iVar1 = param_1[3];
    dVar2 = (double)FUN_140332d90(SUB84(((double)iVar1 - 0.0) * DAT_14053a900 * DAT_14053a020 *
                                        DAT_140539d28,0));
    dVar4 = dVar2 * DAT_140539e60 + DAT_140539f58;
    uVar12 = SUB84(((double)iVar1 - 0.0) * DAT_14053a628 * DAT_14053a020 * DAT_140539d28,0);
    dVar2 = (double)FUN_140332d90(uVar12);
    fVar11 = (float)(dVar2 * DAT_14053a528) + DAT_140539da8;
    dVar2 = (double)FUN_140332d90(uVar12);
    fVar10 = (float)(dVar2 * DAT_14053a3a0) + DAT_140539da8;
    uVar12 = 0x25;
    if (0x7fff < (ushort)(*(short *)((longlong)param_1 + 0x42) + 0xc000U)) {
      uVar12 = 0x27;
    }
    sVar8 = *(short *)((longlong)param_1 + 0x42) + 0x200;
    *(short *)((longlong)param_1 + 0x42) = sVar8;
    if (0x3c < (int)param_1[3]) {
      fVar10 = DAT_14053accc;
      fVar11 = DAT_14053ad80;
    }
    uVar5 = FUN_140133f30(uStack_90,uStack_8c,*(undefined2 *)(param_1 + 0x10),sVar8,
                          CONCAT44(uVar13,fVar11),fVar10);
    uStackX_c = (undefined4)((ulonglong)uVar5 >> 0x20);
    local_res8 = (undefined4)uVar5;
    auVar3._8_4_ = SUB84(dVar4,0);
    auVar3._0_8_ = dVar4;
    auVar3._12_4_ = (int)((ulonglong)dVar4 >> 0x20);
    param_1[10] = local_res8;
    param_1[0xb] = uStackX_c;
    puVar6 = (undefined8 *)
             FUN_1400c8410(DAT_140e44afc,uVar12,7,local_res8,uStackX_c,(uint)fVar10 & 0xffff0000,
                           auVar3,0xff,0xff,0xff,0xff,1,0);
  }
  if (iVar7 < 1) {
    FUN_140079e20(param_1,0);
    uVar9 = ((uint)param_1[1] >> 0x1e ^ param_1[1]) * 0x6c078965 + 1;
    DAT_140e9fd10 = (uVar9 >> 0x1e ^ uVar9) * 0x6c078965 + 2;
    DAT_140e9fd14 = (DAT_140e9fd10 >> 0x1e ^ DAT_140e9fd10) * 0x6c078965 + 3;
    uVar9 = uVar9 * 0x800 ^ uVar9;
    DAT_140e9fd18 = (DAT_140e9fd14 >> 0x1e ^ DAT_140e9fd14) * 0x6c078965 + 4;
    DAT_140e9fd1c = (DAT_140e9fd18 >> 0xb ^ uVar9) >> 8 ^ DAT_140e9fd18 ^ uVar9;
    puVar6 = (undefined8 *)
             FUN_1400ca6d0(7,param_1[10],param_1[0xb],
                           CONCAT22((short)(DAT_140e9fd1c >> 0x10),
                                    (short)DAT_140e9fd1c + (short)(DAT_140e9fd1c / 0x4001) * -0x4001
                                    + 0x2000),DAT_14053a070,DAT_14053ac80);
  }
  else if ((int)local_b8 != 0) {
    return puVar6;
  }
  *param_1 = 0;
  return puVar6;
}


