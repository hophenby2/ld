// Function: FUN_14020c8c0 @ 14020c8c0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_14020c8c0(longlong *param_1,undefined8 param_2,int *param_3,longlong *param_4,undefined8 param_5
             ,int *param_6,int param_7,int param_8,longlong param_9,longlong param_10,
             longlong *param_11,longlong param_12,int *param_13,longlong param_14,longlong param_15,
             longlong param_16,char param_17)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  undefined8 uVar4;
  uint *puVar5;
  float *pfVar6;
  ulonglong uVar7;
  longlong lVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined1 auStack_3a8 [32];
  undefined8 *local_388;
  undefined4 local_380;
  int local_378;
  int local_374;
  undefined8 local_370;
  undefined8 uStack_368;
  longlong local_360;
  longlong local_358;
  longlong local_350;
  undefined8 local_348;
  undefined8 local_340;
  undefined8 local_338 [2];
  undefined4 local_328 [2];
  int local_320 [3];
  uint local_314;
  undefined4 local_310 [2];
  int local_308 [3];
  uint local_2fc;
  undefined8 local_2f8;
  float local_2f0;
  float local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined8 local_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined4 local_2b8;
  uint local_2b0;
  uint local_2ac;
  uint local_280;
  uint local_27c;
  float local_248;
  uint local_244;
  float local_240;
  float local_23c;
  undefined8 local_238;
  float local_230;
  uint local_22c;
  float local_228;
  float local_224;
  undefined8 local_220;
  float local_218;
  uint local_214;
  float local_210;
  float local_20c;
  undefined8 local_208;
  float local_200;
  uint local_1fc;
  float local_1f8;
  float local_1f4;
  undefined8 local_1f0;
  float local_1e8;
  uint local_1e4 [71];
  ulonglong local_c8;
  
  local_c8 = DAT_1407c6b00 ^ (ulonglong)auStack_3a8;
  local_348 = param_5;
  local_374 = param_7;
  local_378 = param_8;
  local_360 = param_10;
  local_350 = param_12;
  local_358 = param_16;
  local_2e0 = 0;
  local_2d8 = 0;
  local_2d0 = 0;
  local_2c8 = 0;
  local_2c0 = 0;
  local_2b8 = 0;
  local_370 = 0;
  uStack_368 = 0;
  local_328[0] = 0;
  local_340 = param_2;
  FUN_1401ef160(0);
  if (DAT_140b27168 != 0) {
    FUN_1401df4f0();
  }
  (**(code **)(*param_1 + 0x50))(param_1,&local_280);
  (**(code **)(*param_4 + 0x50))(param_4,&local_2b0);
  if (param_11 != (longlong *)0x0) {
    (**(code **)(*param_11 + 0x50))(param_11,&local_2e0);
  }
  if (param_3 == (int *)0x0) {
    local_308[0] = 0;
    local_308[1] = 0;
    param_3 = local_308;
    local_308[2] = local_280;
    local_2fc = local_27c;
  }
  if (param_6 == (int *)0x0) {
    local_320[0] = 0;
    local_320[1] = 0;
    param_6 = local_320;
    local_320[2] = local_2b0;
    local_314 = local_2ac;
  }
  fVar10 = (float)local_2b0;
  if (param_14 == 0) {
    fVar13 = (float)param_6[3] / (float)local_2ac;
    fVar12 = (float)param_6[1] / (float)local_2ac;
    local_214 = (uint)((fVar13 + fVar13) - DAT_140539da8) ^ DAT_14053bf00;
    local_244 = (uint)((fVar12 + fVar12) - DAT_140539da8) ^ DAT_14053bf00;
    local_248 = ((float)*param_6 / fVar10 + (float)*param_6 / fVar10) - DAT_140539da8;
    local_230 = ((float)param_6[2] / fVar10 + (float)param_6[2] / fVar10) - DAT_140539da8;
    local_240 = (float)*param_3 / (float)local_280;
    local_23c = (float)param_3[1] / (float)local_27c;
    local_228 = (float)param_3[2] / (float)local_280;
    local_20c = (float)param_3[3] / (float)local_27c;
    if (param_11 == (longlong *)0x0) {
      fVar10 = (float)local_370;
      fVar12 = local_370._4_4_;
      fVar13 = (float)uStack_368;
      fVar11 = uStack_368._4_4_;
    }
    else {
      if (param_13 == (int *)0x0) {
        local_320[0] = 0;
        local_320[1] = 0;
        param_13 = local_320;
        local_320[2] = (uint)local_2e0;
        local_314 = local_2e0._4_4_;
      }
      fVar10 = (float)*param_13 / (float)(local_2e0 & 0xffffffff);
      fVar12 = (float)param_13[1] / (float)local_2e0._4_4_;
      fVar13 = (float)param_13[2] / (float)(local_2e0 & 0xffffffff);
      fVar11 = (float)param_13[3] / (float)local_2e0._4_4_;
    }
    local_22c = local_244;
    local_224 = local_23c;
    local_218 = local_248;
    local_210 = local_240;
    local_200 = local_230;
    local_1fc = local_214;
    local_1f8 = local_228;
    local_1f4 = local_20c;
    if (param_11 == (longlong *)0x0) {
      local_238 = 0;
      local_220 = 0;
      local_208 = 0;
      local_1f0 = 0;
    }
    else {
      local_238 = CONCAT44(fVar12,fVar10);
      local_220 = CONCAT44(fVar12,fVar13);
      local_208 = CONCAT44(fVar11,fVar10);
      local_1f0 = CONCAT44(fVar11,fVar13);
    }
  }
  else {
    puVar3 = local_1e4;
    lVar8 = 4;
    puVar5 = (uint *)(param_14 + 0x14);
    do {
      fVar12 = (float)puVar5[-4];
      fVar13 = (float)puVar5[-5];
      puVar3[1] = *puVar5;
      puVar3[2] = puVar5[1];
      puVar3[3] = puVar5[2];
      puVar3[4] = puVar5[3];
      puVar3[5] = puVar5[4];
      puVar3[6] = puVar5[5];
      puVar3[7] = puVar5[6];
      puVar3[8] = puVar5[7];
      puVar3[9] = puVar5[8];
      puVar3[10] = puVar5[9];
      puVar3[0xb] = puVar5[10];
      puVar3[0xc] = puVar5[0xb];
      puVar3[0xd] = puVar5[0xc];
      puVar3[0xe] = puVar5[0xd];
      puVar3[0xf] = puVar5[0xe];
      puVar1 = puVar5 + 0xf;
      puVar5 = puVar5 + 0x15;
      puVar3[0x10] = *puVar1;
      *puVar3 = (uint)((fVar12 / (float)local_2ac + fVar12 / (float)local_2ac) - DAT_140539da8) ^
                DAT_14053bf00;
      puVar3[-1] = (uint)((fVar13 / fVar10 + fVar13 / fVar10) - DAT_140539da8);
      puVar3 = puVar3 + 0x12;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
  }
  uVar4 = 0x60;
  if (param_14 != 0) {
    uVar4 = 0x120;
  }
  FUN_1401f4a80(uVar4);
  local_388 = local_338;
  local_380 = 0;
  FUN_14021d030(DAT_140c592a8,0,4);
  if (param_14 == 0) {
    uVar4 = 0x60;
    pfVar6 = &local_248;
  }
  else {
    uVar4 = 0x120;
    pfVar6 = &local_1e8;
  }
  FUN_1401ae2f0(local_338[0],pfVar6,uVar4);
  FUN_14021d280(DAT_140c592a8,0,0);
  FUN_14021d160(1,&local_348);
  FUN_14021d1e0(0,1,&local_340);
  if (local_350 != 0) {
    FUN_14021d1e0(1,1,&local_350);
  }
  if (local_358 != 0) {
    FUN_14021d1e0(2,1,&local_358);
  }
  local_2f8 = 0;
  local_2e8 = 0;
  local_2e4 = 0x3f800000;
  local_2f0 = (float)local_2b0;
  local_2ec = (float)local_2ac;
  FUN_14021d220(1,&local_2f8);
  iVar2 = local_374;
  uVar7 = (ulonglong)(-(uint)(local_374 != 0) & 8);
  FUN_14021d1a0(0,1,(longlong)&DAT_140c3eb70 + uVar7);
  if (param_11 != (longlong *)0x0) {
    FUN_14021d1a0(1,1,(longlong)&DAT_140c3eb70 + uVar7);
  }
  if (param_15 != 0) {
    if (param_17 == '\0') {
      uVar7 = (ulonglong)(iVar2 != 0);
    }
    else {
      uVar7 = 2;
    }
    FUN_14021d1a0(2,1,&DAT_140c3eb70 + uVar7);
  }
  FUN_14021d200(DAT_140c3eb88);
  FUN_14021d140(DAT_140c3eb90,0);
  bVar9 = local_378 != 0;
  local_378 = -local_378;
  FUN_14021d120(*(undefined8 *)((longlong)&DAT_140c3eb98 + (ulonglong)(-(uint)bVar9 & 8)),
                &DAT_140c9d8c8,0xffffffff);
  FUN_14021cf90(5);
  uVar4 = DAT_140c49190;
  if (param_14 != 0) {
    uVar4 = DAT_140c49198;
  }
  FUN_14021cf70(uVar4);
  lVar8 = DAT_140c3ebb8;
  if (local_360 != 0) {
    lVar8 = local_360;
  }
  FUN_14021d1c0(lVar8,0,0);
  if (param_9 == 0) {
    param_9 = DAT_140c3eba8;
    if (param_14 != 0) {
      param_9 = DAT_140c3ebb0;
    }
  }
  FUN_14021d4b0(param_9,0,0);
  if (DAT_140c713b8 != 0) {
    FUN_14021cef0(0,0,0);
  }
  local_310[0] = 0x18;
  if (param_14 != 0) {
    local_310[0] = 0x48;
  }
  local_388 = (undefined8 *)local_328;
  FUN_14021cfb0(0,1,&DAT_140c592a8,local_310);
  FUN_14021ceb0(4);
  DAT_1407cd8f4 = DAT_1407cd8f4 + 1;
  local_388 = (undefined8 *)local_328;
  FUN_14021cfb0(0,1,&DAT_140c713e8,&DAT_140c713f0);
  FUN_14021d4b0(DAT_140c713b0,0,0);
  FUN_14021d1c0(DAT_140c713c8,0,0);
  if (DAT_140c713b8 != 0) {
    FUN_14021cef0(DAT_140c713b8,0,0);
  }
  FUN_14021cf70(DAT_140c713e0);
  FUN_14021cf90(DAT_140c71250);
  FUN_14021d120(DAT_140c70bc0,&DAT_140c9d8c8,0xffffffff);
  FUN_14021d140(DAT_140c70960,0);
  FUN_14021d200(DAT_140c70718);
  FUN_14021d1a0(0,1,&DAT_140c59990);
  if (param_11 != (longlong *)0x0) {
    FUN_14021d1a0(1,1,&DAT_140c59998);
  }
  if (local_358 != 0) {
    FUN_14021d1a0(2,1,&DAT_140c599a0);
  }
  FUN_1401f8140();
  FUN_14021d220(1,&DAT_140c706d0);
  FUN_14021d1e0(0,1,&DAT_140c70e30);
  if (local_350 != 0) {
    FUN_14021d1e0(1,1,&DAT_140c70e38);
  }
  if (local_358 != 0) {
    FUN_14021d1e0(2,1,&DAT_140c70e40);
  }
  return 0;
}


