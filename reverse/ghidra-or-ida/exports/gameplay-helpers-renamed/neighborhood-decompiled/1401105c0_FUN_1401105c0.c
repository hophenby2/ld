// Function: FUN_1401105c0 @ 1401105c0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1401105c0(int *param_1)

{
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined4 local_1a8;
  undefined8 local_1a4;
  undefined4 local_19c;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_198 = _DAT_14053b510;
  uStack_190 = _UNK_14053b518;
  DAT_140e419b8 = param_1[1];
  local_178 = _DAT_14053b4b0;
  uStack_170 = _UNK_14053b4b8;
  local_188 = _DAT_14053b9d0;
  uStack_180 = _UNK_14053b9d8;
  local_158 = _DAT_14053b440;
  uStack_150 = _UNK_14053b448;
  local_168 = _DAT_14053b9b0;
  uStack_160 = _UNK_14053b9b8;
  local_138 = _DAT_14053b450;
  uStack_130 = _UNK_14053b458;
  local_148 = _DAT_14053b9f0;
  uStack_140 = _UNK_14053b9f8;
  local_118 = _DAT_14053b950;
  uStack_110 = _UNK_14053b958;
  local_128 = _DAT_14053ba30;
  uStack_120 = _UNK_14053ba38;
  local_f8 = _DAT_14053b9e0;
  uStack_f0 = _UNK_14053b9e8;
  local_108 = _DAT_14053b520;
  uStack_100 = _UNK_14053b528;
  local_d8 = _DAT_14053ba20;
  uStack_d0 = _UNK_14053ba28;
  local_e8 = _DAT_14053b4c0;
  uStack_e0 = _UNK_14053b4c8;
  local_b8 = _DAT_14053ba40;
  uStack_b0 = _UNK_14053ba48;
  local_c8 = _DAT_14053b4d0;
  uStack_c0 = _UNK_14053b4d8;
  local_1a8 = 0;
  local_19c = 0;
  local_18 = 0;
  DAT_1407c7798 = *param_1;
  local_98 = _DAT_14053b530;
  uStack_90 = _UNK_14053b538;
  local_a8 = _DAT_14053b9c0;
  uStack_a0 = _UNK_14053b9c8;
  local_88 = 0;
  uStack_80 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_1a4 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (DAT_1407c7798 == 10) {
    DAT_140e419b8 = 2;
  }
  DAT_140e45268 = param_1[2];
  DAT_140e45d34 = param_1[5];
  DAT_140e45d74 =
       *(undefined4 *)
        ((longlong)&local_1b8 + ((longlong)DAT_1407c7798 * 7 + (longlong)param_1[4]) * 4);
  DAT_140e418c8 = DAT_140e45d74;
  DAT_140e45d88 =
       (*(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4) / 0x14) * param_1[6] +
       *(int *)(&DAT_140538bd8 + (longlong)DAT_140e419b8 * 4) * param_1[5];
  if (param_1[6] == 0x14) {
    DAT_140e45d88 = DAT_140e45d88 + -1;
  }
  DAT_140e445f8 = 9;
  DAT_140e45d18 = param_1[7] * 0x9c4;
  if (param_1[7] != 0) {
    DAT_140e45d20 = 0x3c;
  }
  return;
}


