// Function: FUN_14024b170 @ 14024b170
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14024b170(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  float fVar6;
  undefined1 auStack_298 [32];
  undefined8 local_278;
  undefined4 local_270;
  undefined4 local_268;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined1 local_240 [32];
  undefined4 local_220;
  float local_218;
  float local_214;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  float local_1c8;
  float local_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  float local_1b8;
  float local_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  float local_1a8;
  float local_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  float local_198;
  float local_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  float local_188;
  float local_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  float local_178;
  float local_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  float local_168;
  float local_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  float local_158;
  float local_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  float local_148;
  float local_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  float local_138;
  float local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  float local_128;
  float local_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  float local_118;
  float local_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  float local_108;
  float local_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  float local_f8;
  float local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float local_e8;
  float local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  float local_d8;
  float local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_298;
  lVar5 = 0;
  iVar3 = FUN_1401eed30();
  if (iVar3 == 0) {
LAB_14024b1b2:
    uVar4 = 0xffffffff;
  }
  else {
    if (((((DAT_140987e88 == 0) || (uVar1 = *(uint *)(param_1 + 0x10), (int)uVar1 < 0)) ||
         ((uVar1 & 0x7c000000) != DAT_140987ed8)) ||
        ((DAT_140987ee0 <= (int)(uVar1 & 0x3ffff) ||
         (piVar2 = *(int **)(DAT_140987e90 + (ulonglong)(uVar1 & 0x3ffff) * 8), piVar2 == (int *)0x0
         )))) || (*piVar2 << 0x12 != (uVar1 & 0x3fc0000))) {
LAB_14024b25d:
      if (((DAT_14098ba90 == 0) ||
          (((uVar1 = *(uint *)(param_1 + 0x10), (int)uVar1 < 0 ||
            ((uVar1 & 0x7c000000) != DAT_14098bae0)) || (DAT_14098bae8 <= (int)(uVar1 & 0x3ffff)))))
         || ((piVar2 = *(int **)(DAT_14098ba98 + (ulonglong)(uVar1 & 0x3ffff) * 8),
             piVar2 == (int *)0x0 || (*piVar2 << 0x12 != (uVar1 & 0x3fc0000))))) goto LAB_14024b1b2;
      if (piVar2[6] != 0) {
        if ((piVar2[6] < 2) && (-1 < piVar2[8])) {
          iVar3 = FUN_1401afbe0();
        }
        else {
          iVar3 = FUN_1401b82b0(uVar1);
        }
        if ((iVar3 < 0) ||
           (*(longlong *)(DAT_14098ba98 + (ulonglong)(*(uint *)(param_1 + 0x10) & 0x3ffff) * 8) == 0
           )) goto LAB_14024b1b2;
      }
    }
    else if (piVar2[6] != 0) {
      if ((piVar2[6] < 2) && (-1 < piVar2[8])) {
        iVar3 = FUN_1401afbe0();
      }
      else {
        iVar3 = FUN_1401b82b0(uVar1);
      }
      if ((iVar3 < 0) ||
         (*(longlong *)(DAT_140987e90 + (ulonglong)(*(uint *)(param_1 + 0x10) & 0x3ffff) * 8) == 0))
      goto LAB_14024b25d;
    }
    if (param_2 != 8) {
      if (param_2 == 0x10) {
        lVar5 = 1;
      }
      else if (param_2 == 0x20) {
        lVar5 = 2;
      }
    }
    piVar2 = &DAT_140b189f0 + lVar5;
    if ((int)(&DAT_140b189f0)[lVar5] < 0) {
      iVar3 = FUN_140248fc0((&PTR_s_Gauss_08Pixel_PS_pso_14066f4e8)[lVar5],1);
      *piVar2 = iVar3;
      if (iVar3 < 0) {
        local_270 = 0x4b0;
        local_278 = (float *)0x80;
        FUN_1401c0470((&PTR_s_Gauss_08Pixel_PS_pso_14066f4e8)[lVar5],0xffffffff,0x7ffd,&local_c8);
        FUN_140159b70(&DAT_1404e8628,&local_c8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar3,piVar2);
    }
    FUN_140142ce0(*(undefined4 *)(param_1 + 0x10),&local_258,&local_254);
    local_248 = DAT_1407cea38;
    local_244 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_240,&DAT_1407ce9e8,4);
    local_208 = *param_4;
    uStack_200 = param_4[1];
    local_220 = 1;
    local_1f8 = param_4[2];
    uStack_1f0 = param_4[3];
    local_218 = (float)local_258;
    local_1e8 = param_4[4];
    uStack_1e0 = param_4[5];
    local_214 = (float)local_254;
    local_1d8 = param_4[6];
    uStack_1d0 = param_4[7];
    if (*(int *)(param_1 + 0x24) == 0) {
      local_1c8 = 0.0 / local_218;
      local_1c4 = 0.0;
      uStack_1c0 = 0;
      uStack_1bc = 0;
      local_1b4 = 0.0;
      uStack_1b0 = 0;
      uStack_1ac = 0;
      local_1a4 = 0.0;
      uStack_1a0 = 0;
      uStack_19c = 0;
      local_194 = 0.0;
      uStack_190 = 0;
      uStack_18c = 0;
      local_184 = 0.0;
      uStack_180 = 0;
      uStack_17c = 0;
      local_174 = 0.0;
      uStack_170 = 0;
      uStack_16c = 0;
      local_164 = 0.0;
      uStack_160 = 0;
      uStack_15c = 0;
      local_154 = 0.0;
      uStack_150 = 0;
      uStack_14c = 0;
      local_144 = 0.0;
      uStack_140 = 0;
      uStack_13c = 0;
      local_134 = 0.0;
      uStack_130 = 0;
      uStack_12c = 0;
      local_124 = 0.0;
      uStack_120 = 0;
      uStack_11c = 0;
      local_114 = 0.0;
      uStack_110 = 0;
      uStack_10c = 0;
      local_104 = 0.0;
      uStack_100 = 0;
      uStack_fc = 0;
      local_f4 = 0.0;
      uStack_f0 = 0;
      uStack_ec = 0;
      local_e4 = 0.0;
      uStack_e0 = 0;
      uStack_dc = 0;
      local_d4 = 0.0;
      uStack_d0 = 0;
      uStack_cc = 0;
      local_1b8 = DAT_140539e78 / local_218;
      local_1a8 = DAT_1404a7e6c / local_218;
      local_198 = DAT_1404e8e40 / local_218;
      local_188 = DAT_1404e8e44 / local_218;
      local_178 = DAT_1404e8e48 / local_218;
      local_168 = DAT_1404e8e4c / local_218;
      local_158 = DAT_1404e8e50 / local_218;
      local_148 = DAT_1404e8e54 / local_218;
      local_138 = DAT_1404e8e58 / local_218;
      local_128 = DAT_1404e8e5c / local_218;
      local_118 = DAT_1404e8e60 / local_218;
      local_108 = DAT_1404e8e64 / local_218;
      local_f8 = DAT_14053ac64 / local_218;
      local_e8 = DAT_1404e8e68 / local_218;
      local_d8 = DAT_1404e8e6c / local_218;
    }
    else if (*(int *)(param_1 + 0x24) == 1) {
      local_1c4 = 0.0 / local_214;
      local_1c8 = 0.0;
      uStack_1c0 = 0;
      uStack_1bc = 0;
      local_1b8 = 0.0;
      uStack_1b0 = 0;
      uStack_1ac = 0;
      local_1a8 = 0.0;
      uStack_1a0 = 0;
      uStack_19c = 0;
      local_198 = 0.0;
      uStack_190 = 0;
      uStack_18c = 0;
      local_188 = 0.0;
      uStack_180 = 0;
      uStack_17c = 0;
      local_178 = 0.0;
      uStack_170 = 0;
      uStack_16c = 0;
      local_168 = 0.0;
      uStack_160 = 0;
      uStack_15c = 0;
      local_158 = 0.0;
      uStack_150 = 0;
      uStack_14c = 0;
      local_148 = 0.0;
      uStack_140 = 0;
      uStack_13c = 0;
      local_138 = 0.0;
      uStack_130 = 0;
      uStack_12c = 0;
      local_128 = 0.0;
      uStack_120 = 0;
      uStack_11c = 0;
      local_118 = 0.0;
      uStack_110 = 0;
      uStack_10c = 0;
      local_108 = 0.0;
      uStack_100 = 0;
      uStack_fc = 0;
      local_f8 = 0.0;
      uStack_f0 = 0;
      uStack_ec = 0;
      local_e8 = 0.0;
      uStack_e0 = 0;
      uStack_dc = 0;
      local_d8 = 0.0;
      uStack_d0 = 0;
      uStack_cc = 0;
      local_1b4 = DAT_140539e78 / local_214;
      local_1a4 = DAT_1404a7e6c / local_214;
      local_194 = DAT_1404e8e40 / local_214;
      local_184 = DAT_1404e8e44 / local_214;
      local_174 = DAT_1404e8e48 / local_214;
      local_164 = DAT_1404e8e4c / local_214;
      local_154 = DAT_1404e8e50 / local_214;
      local_144 = DAT_1404e8e54 / local_214;
      local_134 = DAT_1404e8e58 / local_214;
      local_124 = DAT_1404e8e5c / local_214;
      local_114 = DAT_1404e8e60 / local_214;
      local_104 = DAT_1404e8e64 / local_214;
      local_f4 = DAT_14053ac64 / local_214;
      local_e4 = DAT_1404e8e68 / local_214;
      local_d4 = DAT_1404e8e6c / local_214;
    }
    local_268 = 0;
    local_278 = &local_218;
    local_270 = 0x15;
    FUN_14023dd40(&DAT_140ca5d24,3,1);
    FUN_1401584b0(*piVar2);
    FUN_1402482c0(param_1,1);
    FUN_140248df0(&local_248);
    local_278._0_4_ = 0x15;
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    if (*(int *)(param_1 + 0x24) == 0) {
      FUN_140142ce0(*(undefined4 *)(param_1 + 0x18),&local_24c,&local_250);
      local_c0 = 0;
      local_bc = 0x3f800000;
      local_a4 = 0;
      local_a0 = 0x3f800000;
      local_88 = 0;
      local_84 = 0x3f800000;
      local_6c = 0;
      local_68 = 0x3f800000;
      local_b4 = (float)*(int *)(param_1 + 0x54);
      fVar6 = (float)*(int *)(param_1 + 0x58) +
              (float)(*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c));
      local_98 = local_b4 + (float)(*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28));
      local_c8 = local_b4 - DAT_140539d20;
      local_c4 = fVar6 - DAT_140539d20;
      local_ac = local_98 - DAT_140539d20;
      local_b0 = (fVar6 - DAT_140539da8) / (float)local_250;
      local_8c = (float)local_250 - DAT_140539d20;
      local_b4 = local_b4 / (float)local_24c;
      local_98 = local_98 / (float)local_24c;
      local_a8 = local_c4;
      local_94 = local_b0;
      local_90 = local_c8;
      local_7c = local_b4;
      local_78 = local_b0;
      local_74 = local_ac;
      local_70 = local_8c;
      local_60 = local_98;
      local_5c = local_b0;
      local_b8 = FUN_14017aa20(0xff,0xff,0xff,0xff);
      local_278 = (float *)((ulonglong)local_278._4_4_ << 0x20);
      local_9c = local_b8;
      local_80 = local_b8;
      local_64 = local_b8;
      FUN_140140480(&local_c8,4,5,*(undefined4 *)(param_1 + 0x18));
    }
    uVar4 = 0;
  }
  return uVar4;
}


