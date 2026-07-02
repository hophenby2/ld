// Function: FUN_14024aad0 @ 14024aad0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14024aad0(longlong param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  int iVar11;
  int iVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  float *pfVar16;
  longlong lVar17;
  uint uVar18;
  undefined8 *puVar19;
  longlong lVar20;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar25 [16];
  undefined1 auVar27 [16];
  undefined1 auVar29 [16];
  float fVar30;
  float fVar31;
  undefined1 auStack_258 [32];
  undefined8 *local_238;
  uint local_230;
  undefined4 local_228;
  undefined4 local_218;
  undefined4 local_214;
  undefined1 local_210 [32];
  undefined4 local_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
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
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined1 local_e8 [128];
  ulonglong local_68;
  undefined1 auVar21 [16];
  undefined1 auVar24 [16];
  undefined1 auVar26 [16];
  undefined1 auVar28 [16];
  
  local_68 = DAT_1407c6b00 ^ (ulonglong)auStack_258;
  lVar20 = 0;
  lVar17 = 0;
  iVar11 = FUN_1401eed30();
  if (iVar11 == 0) {
    return 0xffffffff;
  }
  if (((((DAT_140987e88 == 0) || (uVar18 = *(uint *)(param_1 + 0x10), (int)uVar18 < 0)) ||
       ((uVar18 & 0x7c000000) != DAT_140987ed8)) ||
      ((DAT_140987ee0 <= (int)(uVar18 & 0x3ffff) ||
       (piVar7 = *(int **)(DAT_140987e90 + (ulonglong)(uVar18 & 0x3ffff) * 8), piVar7 == (int *)0x0)
       ))) || (*piVar7 << 0x12 != (uVar18 & 0x3fc0000))) {
LAB_14024b163:
    uVar15 = 0xffffffff;
  }
  else {
    if (piVar7[6] != 0) {
      if ((piVar7[6] < 2) && (-1 < piVar7[8])) {
        iVar11 = FUN_1401afbe0();
      }
      else {
        iVar11 = FUN_1401b82b0(uVar18);
      }
      if ((iVar11 < 0) ||
         (*(longlong *)(DAT_140987e90 + (ulonglong)(*(uint *)(param_1 + 0x10) & 0x3ffff) * 8) == 0))
      goto LAB_14024b163;
    }
    iVar11 = 2;
    if ((0 < param_2) && (2 < param_2)) {
      if (param_2 == 4) {
        lVar20 = 1;
      }
      else if (param_2 == 8) {
        lVar20 = 2;
      }
    }
    piVar1 = &DAT_140b18a24 + lVar20;
    if ((int)(&DAT_140b18a24)[lVar20] < 0) {
      iVar12 = FUN_140248fc0((&PTR_s_DownScaleX2_pso_14066f500)[lVar20],1);
      *piVar1 = iVar12;
      if (iVar12 < 0) {
        local_230 = 0x4b0;
        local_238 = (undefined8 *)0x80;
        FUN_1401c0470((&PTR_s_DownScaleX2_pso_14066f500)[lVar20],0xffffffff,0x7ffd,local_e8);
        FUN_140159b70(&DAT_1404e8628,local_e8);
        return 0xffffffff;
      }
      FUN_1401b7da0(iVar12,piVar1);
    }
    local_218 = DAT_1407cea38;
    local_214 = DAT_1407cea40;
    FUN_14023de90(&DAT_140ca5d24,3);
    FUN_1401ae2f0(local_210,&DAT_1407ce9e8,4);
    local_1f0 = 1;
    if (0 < param_2) {
      if (param_2 < 3) {
        lVar17 = 1;
        local_1e8 = 0;
        uStack_1e0 = 0;
      }
      else if (param_2 == 4) {
        lVar17 = 4;
        local_1e8 = _DAT_1404e8f10;
        uStack_1e0 = _UNK_1404e8f18;
        local_1d8 = _DAT_1404e8ef0;
        uStack_1d0 = _UNK_1404e8ef8;
        local_1c8 = CONCAT44(_UNK_1404e8e94,_DAT_1404e8e90);
        uStack_1c0 = CONCAT44(_UNK_1404e8e9c,_UNK_1404e8e98);
        local_1b8 = _DAT_1404e8e70;
        uStack_1b0 = _UNK_1404e8e78;
      }
      else if (param_2 == 8) {
        lVar17 = 0x10;
        local_1e8 = _DAT_1404e8f60;
        uStack_1e0 = _UNK_1404e8f68;
        local_1d8 = _DAT_1404e8f50;
        uStack_1d0 = _UNK_1404e8f58;
        local_1c8 = _DAT_1404e8f30;
        uStack_1c0 = _UNK_1404e8f38;
        local_1b8 = _DAT_1404e8f40;
        uStack_1b0 = _UNK_1404e8f48;
        local_1a8 = _DAT_1404e8f20;
        uStack_1a0 = _UNK_1404e8f28;
        local_198 = _DAT_1404e8f10;
        uStack_190 = _UNK_1404e8f18;
        local_188 = _DAT_1404e8ef0;
        uStack_180 = _UNK_1404e8ef8;
        local_178 = _DAT_1404e8f00;
        uStack_170 = _UNK_1404e8f08;
        local_168 = _DAT_1404e8ea0;
        uStack_160 = _UNK_1404e8ea8;
        local_158 = CONCAT44(_UNK_1404e8e94,_DAT_1404e8e90);
        uStack_150 = CONCAT44(_UNK_1404e8e9c,_UNK_1404e8e98);
        local_148 = _DAT_1404e8e70;
        uStack_140 = _UNK_1404e8e78;
        local_138 = _DAT_1404e8e80;
        uStack_130 = _UNK_1404e8e88;
        local_128 = _DAT_1404e8ee0;
        uStack_120 = _UNK_1404e8ee8;
        local_118 = _DAT_1404e8ed0;
        uStack_110 = _UNK_1404e8ed8;
        local_108 = _DAT_1404e8eb0;
        uStack_104 = _UNK_1404e8eb4;
        uStack_100 = _UNK_1404e8eb8;
        uStack_fc = _UNK_1404e8ebc;
        local_f8 = _DAT_1404e8ec0;
        uStack_f0 = _UNK_1404e8ec8;
      }
    }
    iVar12 = 0;
    fVar30 = (float)*(int *)(*(longlong *)(piVar7 + 0x28) + 0x68);
    fVar31 = (float)*(int *)(*(longlong *)(piVar7 + 0x28) + 0x6c);
    uVar18 = (uint)lVar17;
    if (7 < uVar18) {
      puVar19 = &local_1c8;
      do {
        auVar22._4_4_ = *(undefined4 *)puVar19;
        auVar22._0_4_ = *(undefined4 *)(puVar19 + -4);
        uVar2 = *(undefined4 *)((longlong)puVar19 + 4);
        uVar3 = *(undefined4 *)((longlong)puVar19 + 0x14);
        auVar22._8_4_ = *(undefined4 *)puVar19;
        auVar22._12_4_ = *(undefined4 *)(puVar19 + 2);
        auVar21._8_8_ = auVar22._8_8_;
        auVar21._4_4_ = *(undefined4 *)(puVar19 + -2);
        auVar21._0_4_ = *(undefined4 *)(puVar19 + -4);
        uVar4 = *(undefined4 *)((longlong)puVar19 + -0xc);
        auVar23._4_4_ = fVar30;
        auVar23._0_4_ = fVar30;
        auVar23._8_4_ = fVar30;
        auVar23._12_4_ = fVar30;
        auVar23 = divps(auVar21,auVar23);
        *(int *)(&local_1e8 + (longlong)iVar12 * 2) = auVar23._0_4_;
        *(int *)(&local_1e8 + (longlong)(iVar11 + -1) * 2) = auVar23._4_4_;
        *(int *)(&local_1e8 + (longlong)iVar11 * 2) = auVar23._8_4_;
        *(int *)(&local_1e8 + (longlong)(iVar11 + 1) * 2) = auVar23._12_4_;
        uVar5 = *(undefined4 *)(puVar19 + 10);
        auVar25._4_4_ = uVar2;
        auVar25._0_4_ = *(undefined4 *)((longlong)puVar19 + -0x1c);
        uVar6 = *(undefined4 *)(puVar19 + 8);
        auVar25._8_4_ = uVar2;
        auVar25._12_4_ = uVar3;
        auVar24._8_8_ = auVar25._8_8_;
        auVar24._4_4_ = uVar4;
        auVar24._0_4_ = *(undefined4 *)((longlong)puVar19 + -0x1c);
        uVar2 = *(undefined4 *)(puVar19 + 6);
        auVar9._4_4_ = fVar31;
        auVar9._0_4_ = fVar31;
        auVar9._8_4_ = fVar31;
        auVar9._12_4_ = fVar31;
        auVar23 = divps(auVar24,auVar9);
        *(int *)((longlong)&local_1e8 + (longlong)iVar12 * 0x10 + 4) = auVar23._0_4_;
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + -1) * 0x10 + 4) = auVar23._4_4_;
        *(int *)((longlong)&local_1e8 + (longlong)iVar11 * 0x10 + 4) = auVar23._8_4_;
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + 1) * 0x10 + 4) = auVar23._12_4_;
        uVar3 = *(undefined4 *)((longlong)puVar19 + 0x54);
        auVar27._4_4_ = uVar6;
        auVar27._0_4_ = *(undefined4 *)(puVar19 + 4);
        uVar4 = *(undefined4 *)((longlong)puVar19 + 0x44);
        auVar27._8_4_ = uVar6;
        auVar27._12_4_ = uVar5;
        auVar26._8_8_ = auVar27._8_8_;
        auVar26._4_4_ = uVar2;
        auVar26._0_4_ = *(undefined4 *)(puVar19 + 4);
        uVar2 = *(undefined4 *)((longlong)puVar19 + 0x34);
        auVar8._4_4_ = fVar30;
        auVar8._0_4_ = fVar30;
        auVar8._8_4_ = fVar30;
        auVar8._12_4_ = fVar30;
        auVar23 = divps(auVar26,auVar8);
        *(int *)(&local_1e8 + (longlong)(iVar11 + 2) * 2) = auVar23._0_4_;
        *(int *)(&local_1e8 + (longlong)(iVar11 + 3) * 2) = auVar23._4_4_;
        *(int *)(&local_1e8 + (longlong)(iVar11 + 4) * 2) = auVar23._8_4_;
        *(int *)(&local_1e8 + (longlong)(iVar11 + 5) * 2) = auVar23._12_4_;
        auVar29._4_4_ = uVar4;
        auVar29._0_4_ = *(undefined4 *)((longlong)puVar19 + 0x24);
        auVar29._8_4_ = uVar4;
        auVar29._12_4_ = uVar3;
        auVar28._8_8_ = auVar29._8_8_;
        auVar28._4_4_ = uVar2;
        auVar28._0_4_ = *(undefined4 *)((longlong)puVar19 + 0x24);
        auVar10._4_4_ = fVar31;
        auVar10._0_4_ = fVar31;
        auVar10._8_4_ = fVar31;
        auVar10._12_4_ = fVar31;
        auVar23 = divps(auVar28,auVar10);
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + 2) * 0x10 + 4) = auVar23._0_4_;
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + 3) * 0x10 + 4) = auVar23._4_4_;
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + 4) * 0x10 + 4) = auVar23._8_4_;
        iVar12 = iVar12 + 8;
        *(int *)((longlong)&local_1e8 + (longlong)(iVar11 + 5) * 0x10 + 4) = auVar23._12_4_;
        iVar11 = iVar11 + 8;
        puVar19 = puVar19 + 0x10;
      } while (iVar12 < (int)(uVar18 & 0xfffffff8));
    }
    lVar20 = (longlong)iVar12;
    if (lVar20 < lVar17) {
      if (3 < lVar17 - lVar20) {
        lVar13 = lVar20 * 0x10;
        lVar14 = ((lVar17 - lVar20) - 4U >> 2) + 1;
        lVar20 = lVar20 + lVar14 * 4;
        pfVar16 = (float *)((longlong)&local_1e8 + lVar13 + 4);
        do {
          pfVar16[-1] = pfVar16[-1] / fVar30;
          *pfVar16 = *pfVar16 / fVar31;
          pfVar16[3] = pfVar16[3] / fVar30;
          pfVar16[4] = pfVar16[4] / fVar31;
          pfVar16[7] = pfVar16[7] / fVar30;
          pfVar16[8] = pfVar16[8] / fVar31;
          pfVar16[0xb] = pfVar16[0xb] / fVar30;
          pfVar16[0xc] = pfVar16[0xc] / fVar31;
          lVar14 = lVar14 + -1;
          pfVar16 = pfVar16 + 0x10;
        } while (lVar14 != 0);
      }
      if (lVar20 < lVar17) {
        lVar17 = lVar17 - lVar20;
        pfVar16 = (float *)((longlong)&local_1e8 + lVar20 * 0x10 + 4);
        do {
          pfVar16[-1] = pfVar16[-1] / fVar30;
          *pfVar16 = *pfVar16 / fVar31;
          lVar17 = lVar17 + -1;
          pfVar16 = pfVar16 + 4;
        } while (lVar17 != 0);
      }
    }
    local_228 = 0;
    local_238 = &local_1e8;
    local_230 = uVar18;
    FUN_14023dd40(&DAT_140ca5d24,3,1);
    FUN_1401584b0(*piVar1);
    FUN_1402482c0(param_1,param_2,0);
    FUN_140248df0(&local_218);
    local_238 = (undefined8 *)CONCAT44(local_238._4_4_,uVar18);
    FUN_14023dc20(&DAT_140ca5d24,3,1);
    uVar15 = 0;
  }
  return uVar15;
}


