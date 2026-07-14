// Function: FUN_140116940 @ 140116940
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140116940(int param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,
                  undefined8 param_6,undefined8 param_7,int param_8,int param_9,int param_10,
                  int param_11,int param_12,int param_13,int param_14,int param_15,int param_16,
                  undefined8 param_17,int param_18,int param_19)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined1 auStack_2d8 [32];
  char *local_2b8;
  undefined4 local_2b0;
  int local_2a8;
  int local_2a0;
  undefined8 local_280;
  longlong local_278;
  char *local_270;
  int local_268;
  int local_260;
  int local_258;
  int local_250;
  char *local_248;
  undefined8 *local_240;
  longlong local_238;
  char local_228 [8];
  undefined8 local_220;
  undefined1 local_218;
  undefined4 local_210;
  undefined4 local_20c;
  undefined2 local_208;
  int local_200;
  int local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  undefined8 local_1f0;
  undefined1 local_1e8 [16];
  int local_1d8;
  int local_1d4;
  undefined4 local_1c0;
  undefined1 local_1bc;
  undefined4 local_1bb;
  undefined1 local_1b7;
  undefined4 local_1b6;
  undefined1 local_1b2;
  undefined4 local_1b1;
  undefined1 local_1ad;
  undefined4 local_1ac;
  undefined1 local_1a8;
  undefined4 local_1a7;
  undefined1 local_1a3;
  undefined4 local_1a2;
  undefined1 local_19e;
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_193;
  undefined1 local_18f;
  undefined4 local_18e;
  undefined1 local_18a;
  undefined4 local_189;
  undefined1 local_185;
  undefined4 local_184;
  undefined1 local_180;
  undefined4 local_17f;
  undefined1 local_17b;
  undefined4 local_17a;
  undefined1 local_176;
  undefined4 local_175;
  undefined1 local_171;
  undefined4 local_170;
  undefined1 local_16c;
  undefined4 local_16b;
  undefined1 local_167;
  undefined4 local_166;
  undefined1 local_162;
  undefined4 local_161;
  undefined1 local_15d;
  char local_158 [4];
  char local_154 [2];
  undefined8 local_152;
  undefined1 local_14a;
  undefined4 local_149;
  undefined2 local_145;
  undefined8 local_143;
  undefined1 local_13b;
  undefined4 local_13a;
  undefined2 local_136;
  undefined8 local_134;
  undefined1 local_12c;
  char local_128 [8];
  char local_120 [2];
  char local_11e;
  undefined4 local_11d;
  char local_119 [8];
  char local_111 [2];
  char local_10f;
  undefined4 local_10e;
  char local_10a [8];
  char local_102 [2];
  char local_100;
  undefined4 local_ff;
  char local_fb [8];
  char local_f3 [2];
  char local_f1;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined2 local_e4;
  undefined1 local_e2;
  undefined4 local_e1;
  char local_dd [8];
  char local_d5 [2];
  char local_d3;
  undefined4 local_d2;
  undefined8 local_ce;
  undefined2 local_c6;
  undefined1 local_c4;
  undefined4 local_c3;
  undefined8 local_bf;
  undefined2 local_b7;
  undefined1 local_b5;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined2 local_a8;
  undefined1 local_a6;
  undefined4 local_a5;
  char local_a1 [8];
  char local_99 [2];
  char local_97;
  undefined4 local_96;
  undefined8 local_92;
  undefined2 local_8a;
  undefined1 local_88;
  undefined4 local_87;
  undefined8 local_83;
  undefined2 local_7b;
  undefined1 local_79;
  undefined4 local_78;
  ulonglong local_68;
  
  local_68 = DAT_1407c6b00 ^ (ulonglong)auStack_2d8;
  lVar10 = (longlong)param_10;
  lVar12 = (longlong)param_14;
  lVar13 = (longlong)param_18;
  local_1f0 = param_7;
  local_1f8 = param_11;
  local_1fc = param_12;
  local_200 = param_13;
  local_1c0 = DAT_140539584;
  local_1bc = DAT_140539588;
  local_1bb = DAT_14053958c;
  local_1b7 = DAT_140539590;
  local_1b6 = DAT_140539594;
  local_1b2 = DAT_140539598;
  local_1b1 = DAT_14053959c;
  local_1ad = DAT_1405395a0;
  local_1ac = DAT_1405395a4;
  local_1a8 = DAT_1405395a8;
  local_1a7 = DAT_1405395ac;
  local_1a3 = DAT_1405395b0;
  local_1a2 = DAT_1405395b4;
  local_19e = DAT_1405395b8;
  local_158 = (char  [4])s_Alice_140539468._0_4_;
  local_154 = (char  [2])s_Alice_140539468._4_2_;
  local_152 = 0;
  local_14a = 0;
  local_149 = DAT_140539470;
  local_145 = DAT_140539474;
  local_143 = 0;
  local_13b = 0;
  local_13a = DAT_140539478;
  local_136 = DAT_14053947c;
  local_134 = 0;
  local_12c = 0;
  local_194 = 0;
  local_18f = 0;
  local_18a = 0;
  local_185 = 0;
  local_180 = 0;
  local_17b = 0;
  local_176 = 0;
  local_171 = 0;
  builtin_strncpy(local_228,"ABCD",4);
  local_198 = 0x317453;
  local_193 = 0x327453;
  local_18e = 0x337453;
  local_189 = 0x347453;
  local_184 = 0x357453;
  local_17f = 0x367453;
  local_17a = 0x377453;
  local_175 = 0x387453;
  local_16c = 0;
  local_167 = 0;
  local_166 = DAT_140539488;
  local_162 = DAT_14053948c;
  local_15d = 0;
  local_120 = (char  [2])s_Casual_1405395c0._8_2_;
  local_11e = s_Casual_1405395c0[10];
  local_11d = 0;
  local_111 = (char  [2])s_Maniac_1405395d0._8_2_;
  local_10f = s_Maniac_1405395d0[10];
  local_10e = 0;
  local_102 = (char  [2])s_Expert_1405395e0._8_2_;
  local_100 = s_Expert_1405395e0[10];
  local_ff = 0;
  local_f3 = (char  [2])s_Nightmare_1405395f0._8_2_;
  local_f1 = s_Nightmare_1405395f0[10];
  local_f0 = 0;
  local_e4 = DAT_140539608;
  local_e2 = DAT_14053960a;
  local_e1 = 0;
  local_d5 = (char  [2])s_Extra_140539610._8_2_;
  local_d3 = s_Extra_140539610[10];
  local_d2 = 0;
  local_c6 = DAT_140539628;
  local_128 = (char  [8])s_Casual_1405395c0._0_8_;
  local_c4 = DAT_14053962a;
  local_119 = (char  [8])s_Maniac_1405395d0._0_8_;
  local_10a = (char  [8])s_Expert_1405395e0._0_8_;
  local_c3 = 0;
  local_b7 = DAT_140539638;
  local_fb = (char  [8])s_Nightmare_1405395f0._0_8_;
  local_b5 = DAT_14053963a;
  local_ec = DAT_140539600;
  local_dd = (char  [8])s_Extra_140539610._0_8_;
  local_b4 = 0;
  local_a8 = DAT_140539648;
  local_ce = DAT_140539620;
  local_a6 = DAT_14053964a;
  local_bf = DAT_140539630;
  local_170 = 0x397453;
  local_16b = 0x4c4c41;
  local_161 = 0x202020;
  local_b0 = DAT_140539640;
  local_a5 = 0;
  local_99 = (char  [2])s_Nightmare__140539650._8_2_;
  local_97 = s_Nightmare__140539650[10];
  local_96 = 0;
  local_8a = DAT_140539668;
  local_88 = DAT_14053966a;
  local_87 = 0;
  local_7b = DAT_140539678;
  local_79 = DAT_14053967a;
  local_a1 = (char  [8])s_Nightmare__140539650._0_8_;
  local_92 = DAT_140539660;
  local_78 = 0;
  local_83 = DAT_140539670;
  local_1f4 = FUN_14017a940(param_5,param_5,param_5);
  iVar9 = param_8;
  iVar8 = param_15;
  if (param_8 == 1) {
    if (param_9 < 1) {
      if (param_9 == -1) {
        iVar9 = 6;
        iVar8 = 5;
      }
    }
    else {
      iVar9 = param_9 + 2;
    }
  }
  iVar5 = iVar8 + 6;
  if (param_16 != 1) {
    iVar5 = iVar8;
  }
  DAT_140e46bec = DAT_140e46c74;
  local_2b0 = param_2;
  if (param_1 != 1) {
    local_2b8 = "%02d.----------------------------------------------------------------";
    FUN_14015b020((int)param_3,(int)param_4,local_1f4);
    return;
  }
  thunk_FUN_14032f930(local_1e8,&param_6);
  if (param_19 == 0) {
    cVar1 = local_228[lVar12];
    local_238 = (longlong)&local_198 + lVar13 * 5;
    local_248 = local_128 + (longlong)iVar5 * 0xf;
    cVar2 = local_228[local_200];
    local_270 = local_158 + lVar10 * 0xf;
    cVar3 = local_228[local_1fc];
    cVar4 = local_228[local_1f8];
    local_278 = (longlong)&local_1c0 + (longlong)iVar9 * 5;
    local_240 = (undefined8 *)CONCAT44(param_17._4_4_,(int)param_17);
    local_2b8 = "%02d.%04d/%02d/%02d %02d:%02d %s %s %s %c%c%c%c %s %12lld %s";
    goto LAB_140117135;
  }
  local_220 = DAT_140539cb0;
  local_218 = DAT_140539cb8;
  local_210 = 0x33323130;
  local_20c = 0x37363534;
  local_208 = 0x3938;
  if ((int)param_17 < 0xe10) {
    local_220._3_5_ = (undefined5)((ulonglong)DAT_140539cb0 >> 0x18);
    local_220 = CONCAT53(local_220._3_5_,0x3a3030);
    iVar8 = (int)param_17;
    if (0x3b < (int)param_17) goto LAB_140116f98;
    local_220._5_3_ = (undefined3)((ulonglong)DAT_140539cb0 >> 0x28);
    local_220 = CONCAT35(local_220._5_3_,0x30303a3030);
  }
  else {
    uVar11 = (int)param_17 / 0xe10;
    local_220._1_7_ = (undefined7)((ulonglong)DAT_140539cb0 >> 8);
    if ((int)uVar11 < 100) {
      if (9 < (int)uVar11) goto LAB_140116f44;
      local_220 = CONCAT71(local_220._1_7_,0x30);
    }
    else {
      uVar11 = 99;
LAB_140116f44:
      local_220 = CONCAT71(local_220._1_7_,
                           *(undefined1 *)((longlong)&local_210 + (ulonglong)uVar11 / 10));
    }
    uVar7 = local_220;
    local_220._0_3_ = CONCAT12(0x3a,(undefined2)local_220);
    local_220._0_2_ =
         CONCAT11(*(undefined1 *)((longlong)&local_210 + (longlong)((int)uVar11 % 10)),(char)uVar7);
    iVar8 = (int)param_17 % 0xe10;
LAB_140116f98:
    uVar7 = local_220;
    iVar6 = iVar8 / 0x3c;
    if (iVar6 < 10) {
      local_220._0_4_ = CONCAT13(0x30,(undefined3)local_220);
    }
    else {
      local_220._0_4_ =
           CONCAT13(*(undefined1 *)((longlong)&local_210 + (longlong)(iVar6 / 10)),
                    (undefined3)local_220);
    }
    local_220._5_3_ = SUB83(uVar7,5);
    local_220._0_5_ =
         CONCAT14(*(undefined1 *)((longlong)&local_210 + (longlong)(iVar6 % 10)),
                  (undefined4)local_220);
    iVar8 = iVar8 % 0x3c;
  }
  local_220._0_6_ = CONCAT15(0x2e,(undefined5)local_220);
  uVar11 = (uint)((double)iVar8 * DAT_140539fb0);
  if ((int)uVar11 < 100) {
    if (9 < (int)uVar11) goto LAB_14011703b;
    local_220._0_7_ = CONCAT16(0x30,(undefined6)local_220);
  }
  else {
    uVar11 = 99;
LAB_14011703b:
    local_220._0_7_ =
         CONCAT16(*(undefined1 *)((longlong)&local_210 + (ulonglong)uVar11 / 10),
                  (undefined6)local_220);
  }
  cVar1 = local_228[lVar12];
  local_238 = (longlong)&local_198 + lVar13 * 5;
  local_220 = CONCAT17(*(undefined1 *)((longlong)&local_210 + (longlong)((int)uVar11 % 10)),
                       (undefined7)local_220);
  local_248 = local_128 + (longlong)iVar5 * 0xf;
  cVar2 = local_228[local_200];
  local_270 = local_158 + lVar10 * 0xf;
  cVar3 = local_228[local_1fc];
  cVar4 = local_228[local_1f8];
  local_278 = (longlong)&local_1c0 + (longlong)iVar9 * 5;
  local_240 = &local_220;
  local_2b8 = "%02d.%04d/%02d/%02d %02d:%02d %s %s %s %c%c%c%c %s     %s %s";
LAB_140117135:
  local_250 = (int)cVar1;
  local_258 = (int)cVar2;
  local_260 = (int)cVar3;
  local_268 = (int)cVar4;
  local_280 = local_1f0;
  local_2a0 = local_1d8 + 1;
  local_2a8 = local_1d4 + 0x76c;
  FUN_14015b020((int)param_3,(int)param_4,local_1f4,DAT_140e46bec);
  return;
}


