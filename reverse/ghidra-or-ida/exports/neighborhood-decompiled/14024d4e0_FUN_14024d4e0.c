// Function: FUN_14024d4e0 @ 14024d4e0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14024d4e0(longlong param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  undefined1 auStack_188 [32];
  undefined8 *local_168;
  undefined4 local_160;
  undefined4 local_158;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120 [8];
  int local_100;
  undefined8 local_f8;
  float local_f0;
  float local_ec;
  undefined1 local_e8 [128];
  ulonglong local_68;
  
  local_68 = DAT_1407c6b00 ^ (ulonglong)auStack_188;
  iVar4 = 0;
  bVar1 = *(int *)(param_1 + 0xc) - 0xfU < 2;
  iVar2 = FUN_1401eed30();
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_140156d20(0);
    lVar6 = (longlong)(int)((uint)bVar1 * 2 - ((int)~param_2 >> 0x1f));
    piVar5 = (int *)(&DAT_140b18a8c + lVar6 * 4);
    if (*(int *)(&DAT_140b18a8c + lVar6 * 4) < 0) {
      iVar2 = FUN_140248fc0((&PTR_s_Y2uv2ToRgb_pso_14066f610)[lVar6],1);
      *piVar5 = iVar2;
      if (iVar2 < 0) {
        local_160 = 0x4b0;
        local_168 = (undefined8 *)0x80;
        FUN_1401c0470((&PTR_s_Y2uv2ToRgb_pso_14066f610)[lVar6],0xffffffff,0x7ffd,local_e8);
        FUN_140159b70(&DAT_1404e8628,local_e8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar2,piVar5);
    }
    local_128 = DAT_1407cea38;
    local_124 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_120,&DAT_1407ce9e8,8);
    local_100 = 2;
    if ((-1 < (int)param_2) || (bVar1)) {
      FUN_140142af0(*(undefined4 *)(param_1 + 0x10),&local_148,&local_140);
      FUN_140142ce0(*(undefined4 *)(param_1 + 0x10),&local_144,&local_13c);
      if ((int)param_2 < 0) {
        local_f8 = 0;
        local_ec = 0.0;
      }
      else {
        FUN_140142af0(param_2,&local_138,&local_130);
        FUN_140142ce0(param_2,&local_134,&local_12c);
        local_ec = ((float)local_138 / (float)local_134) * DAT_140539d20;
        local_f8 = CONCAT44(((float)local_130 / (float)local_12c) /
                            ((float)local_140 / (float)local_13c),
                            ((float)local_138 / (float)local_134) /
                            ((float)local_148 / (float)local_144));
      }
      local_f0 = ((float)local_148 / (float)local_144) * DAT_140539d20;
      local_168 = &local_f8;
      local_158 = 0;
      local_160 = 1;
      FUN_14023dd40(&DAT_140ca5d24,3,1);
    }
    FUN_1401584b0(*piVar5);
    FUN_140158590(1,param_2);
    FUN_1402482c0(param_1,1);
    if (0 < local_100) {
      piVar5 = local_120;
      do {
        iVar2 = *piVar5;
        if (*piVar5 == 0) {
          iVar2 = -1;
        }
        FUN_140158590(iVar4,iVar2);
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < local_100);
    }
    FUN_140158760(local_128);
    FUN_1401584b0(local_124);
    if (-1 < (int)param_2) {
      local_168 = (undefined8 *)CONCAT44(local_168._4_4_,1);
      FUN_14023dc20(&DAT_140ca5d24,3,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


