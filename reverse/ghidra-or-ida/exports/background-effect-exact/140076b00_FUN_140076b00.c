// Function: FUN_140076b00 @ 140076b00
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140076b00(undefined4 *param_1)

{
  double dVar1;
  float fVar2;
  float fVar3;
  undefined1 auStack_c8 [32];
  float local_a8;
  undefined2 local_a0;
  undefined8 local_98;
  double dStack_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  int local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 *local_58;
  float *local_50;
  int local_48;
  undefined1 local_44 [4];
  ulonglong local_40;
  
  local_40 = DAT_1407c6b00 ^ (ulonglong)auStack_c8;
  FUN_140142af0(param_1[3],&local_48,local_44);
  local_58 = param_1 + 9;
  local_50 = (float *)(param_1 + 5);
  if (param_1[2] == 0x37) {
    local_70 = param_1[0x14];
    local_98 = *(undefined8 *)(param_1 + 0xc);
    dStack_90 = *(double *)(param_1 + 0xe);
    local_60 = 0;
    local_68 = 1;
    local_78 = param_1[0x13];
    local_80 = param_1[0x12];
    local_88 = param_1[0x11];
    local_a0 = *(undefined2 *)local_58;
    local_a8 = (float)DAT_1407c77a4 + (float)param_1[6];
    param_1[6] = local_a8;
    FUN_1400c8410(param_1[3],param_1[4],7,*local_50);
  }
  if (param_1[2] == 0x38) {
    local_98 = *(undefined8 *)(param_1 + 0xc);
    dStack_90 = *(double *)(param_1 + 0xe);
    local_60 = 0;
    fVar2 = DAT_140e45d24 + (float)param_1[5];
    local_68 = 1;
    local_70 = param_1[0x14];
    local_78 = param_1[0x13];
    local_80 = param_1[0x12];
    local_88 = param_1[0x11];
    local_a0 = *(undefined2 *)(param_1 + 9);
    local_a8 = (float)(DAT_1407c77a4 << 4) + (float)param_1[6];
    param_1[6] = local_a8;
    FUN_1400c8410(param_1[3],param_1[4],7,fVar2);
  }
  if (param_1[2] == 0x39) {
    local_60 = 0;
    local_68 = 1;
    local_98 = *(undefined8 *)(param_1 + 0xc);
    dStack_90 = *(double *)(param_1 + 0xe);
    local_a8 = (float)(DAT_1407c77a4 << 4) + (float)param_1[6];
    local_70 = param_1[0x14] -
               (int)(((double)(int)param_1[0x14] / (double)(int)param_1[0x10]) *
                    (double)(int)param_1[1]);
    fVar2 = DAT_140e45d24 + *local_50;
    local_78 = param_1[0x13];
    local_80 = param_1[0x12];
    local_88 = param_1[0x11];
    param_1[6] = local_a8;
    local_a0 = *(undefined2 *)local_58;
    FUN_1400c8410(param_1[3],param_1[4],8,fVar2);
  }
  if (param_1[2] == 0x3a) {
    fVar3 = (float)DAT_1407c77a4;
    fVar2 = (float)param_1[6];
    dVar1 = ((double)(int)param_1[1] - 0.0) * _DAT_14053abe8 * DAT_14053a020;
    param_1[6] = fVar3 + fVar2;
    dVar1 = (double)FUN_140332d90(dVar1 * DAT_140539d28);
    local_70 = param_1[0x14];
    local_60 = 0;
    local_68 = 1;
    local_78 = param_1[0x13];
    local_80 = param_1[0x12];
    dStack_90 = (dVar1 * DAT_140539e60 + DAT_140539f40) * *(double *)(param_1 + 0xe);
    local_88 = param_1[0x11];
    local_98 = *(undefined8 *)(param_1 + 0xc);
    local_a0 = *(undefined2 *)local_58;
    local_a8 = fVar3 + fVar2;
    FUN_1400c8410(param_1[3],param_1[4],10,*local_50);
  }
  if (((((float)param_1[5] < DAT_140e445d8 / DAT_14053ab70 - (float)local_48) ||
       ((float)(local_48 + 600) + DAT_140e445d8 / DAT_14053ab70 < (float)param_1[5])) ||
      ((float)param_1[6] < (float)-local_48)) || ((float)(local_48 + 0x2d0) < (float)param_1[6])) {
    *param_1 = 0;
  }
  return;
}


