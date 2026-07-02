// Function: FUN_14023e7a0 @ 14023e7a0
// Decompile completed: true

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14023e7a0(void)

{
  int iVar1;
  undefined *puVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar7;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined1 auStack_10b8 [32];
  undefined1 *local_1098;
  int local_1088;
  undefined1 local_1084 [12];
  undefined4 local_1078;
  undefined4 uStack_1074;
  undefined4 uStack_1070;
  undefined4 uStack_106c;
  undefined1 local_78 [8];
  char local_70;
  char local_6a;
  char local_69;
  char local_64;
  char local_61;
  char local_57;
  char local_52;
  ulonglong local_38;
  undefined4 *puVar6;
  undefined4 *puVar8;
  
  local_38 = DAT_1407c6b00 ^ (ulonglong)auStack_10b8;
  FUN_14023fc10();
  puVar11 = (undefined4 *)0x0;
  DAT_1407cd8d4 = 0;
  if (((DAT_140ca5d1c != 0) && (DAT_140ca5d20 != 0)) ||
     ((DAT_140ca5d14 != 0 && (DAT_140ca5d18 != 0)))) {
    DAT_1407cd8d4 = 1;
    iVar1 = FUN_14023d4c0();
    if (iVar1 == 0) {
      puVar2 = &DAT_1404b02b8;
LAB_14023eba5:
      FUN_140159b70(puVar2);
    }
    else {
      lVar3 = FUN_1401b2e50(&DAT_140d8cd58);
      local_1098 = local_1084;
      iVar1 = FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,"Base2DVertexShader.vso",&local_1088);
      if ((iVar1 == 0) && (iVar1 = FUN_140221330(local_1088 + lVar3,&DAT_140ccd4a0), iVar1 != 0)) {
        puVar2 = &DAT_1404e6330;
        goto LAB_14023eba5;
      }
      FUN_1401ae7d0(local_78,0x40,"ps_nonetex_type0_ach0.pso");
      puVar8 = puVar11;
      do {
        local_69 = (char)puVar8 + '0';
        puVar6 = puVar11;
        do {
          local_64 = (char)puVar6 + '0';
          local_1098 = local_1084;
          iVar1 = FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,local_78,&local_1088);
          if ((iVar1 == 0) &&
             (iVar1 = FUN_140220d70(local_1088 + lVar3,
                                    &DAT_140ccd4a8 +
                                    (longlong)(int)puVar6 + (longlong)(int)puVar8 * 2), iVar1 != 0))
          {
            puVar2 = &DAT_1404e6390;
            goto LAB_14023eba5;
          }
          uVar4 = (int)puVar6 + 1;
          puVar6 = (undefined4 *)(ulonglong)uVar4;
        } while ((int)uVar4 < 2);
        uVar4 = (int)puVar8 + 1;
        puVar8 = (undefined4 *)(ulonglong)uVar4;
      } while ((int)uVar4 < 7);
      FUN_1401ae7d0(local_78,0x40,"ps_blend0_type0_igcolor0_igtalpha0_ach0.pso");
      puVar8 = puVar11;
      do {
        local_70 = (char)puVar8 + '0';
        puVar6 = puVar11;
        do {
          local_6a = (char)puVar6 + '0';
          puVar9 = puVar11;
          do {
            local_61 = (char)puVar9 + '0';
            puVar10 = puVar11;
            do {
              local_57 = (char)puVar10 + '0';
              puVar7 = puVar11;
              do {
                local_52 = (char)puVar7 + '0';
                local_1098 = local_1084;
                iVar1 = FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,local_78,&local_1088);
                if ((iVar1 == 0) &&
                   (iVar1 = FUN_140220d70(local_1088 + lVar3,
                                          &DAT_140ccd518 +
                                          (longlong)(int)puVar7 +
                                          ((longlong)(int)puVar10 +
                                          ((longlong)(int)puVar9 +
                                          ((longlong)(int)puVar8 * 7 + (longlong)(int)puVar6) * 2) *
                                          2) * 2), iVar1 != 0)) {
                  FUN_140159b70(&DAT_1404e6390);
                  goto LAB_14023ebaa;
                }
                uVar4 = (int)puVar7 + 1;
                puVar7 = (undefined4 *)(ulonglong)uVar4;
              } while ((int)uVar4 < 2);
              uVar4 = (int)puVar10 + 1;
              puVar10 = (undefined4 *)(ulonglong)uVar4;
            } while ((int)uVar4 < 2);
            uVar4 = (int)puVar9 + 1;
            puVar9 = (undefined4 *)(ulonglong)uVar4;
          } while ((int)uVar4 < 2);
          uVar4 = (int)puVar6 + 1;
          puVar6 = (undefined4 *)(ulonglong)uVar4;
        } while ((int)uVar4 < 7);
        uVar4 = (int)puVar8 + 1;
        puVar8 = (undefined4 *)(ulonglong)uVar4;
      } while ((int)uVar4 < 4);
      local_1098 = local_1084;
      FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,"ps_mask_blend.pso",&local_1088);
      iVar1 = FUN_140220d70(local_1088 + lVar3,&DAT_140ccdc18);
      puVar8 = puVar11;
      if (iVar1 == 0) {
        do {
          iVar5 = (int)puVar8;
          local_1098 = local_1084;
          FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,
                        (&PTR_s_ps_mask_blend_use_grhandle_cha_p_140574610)[iVar5],&local_1088);
          iVar1 = FUN_140220d70(local_1088 + lVar3,&DAT_140ccdc20 + iVar5);
          if (iVar1 != 0) {
LAB_14023eb9e:
            puVar2 = &DAT_1404e6410;
            goto LAB_14023eba5;
          }
          local_1098 = local_1084;
          FUN_1401b2f00(&DAT_140d8cd58,0x7ffd,
                        (&PTR_s_ps_mask_blend_use_grhandle_cha_r_140574630)[iVar5],&local_1088);
          iVar1 = FUN_140220d70(local_1088 + lVar3,&DAT_140ccdc40 + iVar5);
          if (iVar1 != 0) goto LAB_14023eb9e;
          puVar8 = (undefined4 *)(ulonglong)(iVar5 + 1U);
        } while ((int)(iVar5 + 1U) < 4);
        if (DAT_1407cd8d4 != 0) {
          puVar2 = &DAT_1404e6480;
          goto LAB_14023ebb8;
        }
        goto LAB_14023ebb1;
      }
      FUN_140159b70(&DAT_1404e6410);
    }
LAB_14023ebaa:
    DAT_1407cd8d4 = 0;
  }
LAB_14023ebb1:
  puVar2 = &DAT_1404e6450;
LAB_14023ebb8:
  FUN_140159b70(puVar2);
  FUN_14023e510(&DAT_140ca5d38,1,0);
  FUN_1401ae2f0(0x140ca6144,&DAT_140574650,(longlong)(int)DAT_140ca6140);
  DAT_140cc3e58 = 1;
  if (DAT_140ca5d24 != 0) {
    puVar8 = puVar11;
    if (0xfd < (byte)(DAT_140cccea0 - 1)) {
      DAT_140cccea0 = 0;
      puVar8 = (undefined4 *)&DAT_140574650;
    }
    if (DAT_140ca5960 != 0) {
      if (puVar8 == (undefined4 *)0x0) {
        FUN_1401ae370(&local_1078,0,0x1000);
        if (DAT_140cccea0 != 0xff) {
          lVar3 = (ulonglong)DAT_140cccea0 * 0x140c;
          local_1078 = *(undefined4 *)((longlong)&DAT_140ca6140 + lVar3 + 4);
          uStack_1074 = *(undefined4 *)(lVar3 + 0x140ca6148);
          uStack_1070 = *(undefined4 *)(lVar3 + 0x140ca614c);
          uStack_106c = *(undefined4 *)(lVar3 + 0x140ca6150);
        }
        puVar8 = &local_1078;
      }
      if (DAT_1407cd8d4 == 1) {
        FUN_140222aa0(0,puVar8,1);
      }
      FUN_1401ae2f0(&DAT_140cc5a64,puVar8,0x10);
    }
  }
  FUN_14023e510(&DAT_140cb4dc8,1,0);
  FUN_1401ae2f0(0x140cb51d4,&DAT_140574660,(longlong)(int)DAT_140cb51d0);
  DAT_140cc4a58 = 1;
  if (DAT_140ca5d24 != 0) {
    if (0xfd < (byte)(DAT_140ccd1a0 - 1)) {
      DAT_140ccd1a0 = 0;
      puVar11 = (undefined4 *)&DAT_140574660;
    }
    if (DAT_140ca5960 != 0) {
      if (puVar11 == (undefined4 *)0x0) {
        FUN_1401ae370(&local_1078,0,0x1000);
        if (DAT_140ccd1a0 != 0xff) {
          lVar3 = (ulonglong)DAT_140ccd1a0 * 0x140c;
          local_1078 = *(undefined4 *)((longlong)&DAT_140cb51d0 + lVar3 + 4);
          uStack_1074 = *(undefined4 *)(lVar3 + 0x140cb51d8);
          uStack_1070 = *(undefined4 *)(lVar3 + 0x140cb51dc);
          uStack_106c = *(undefined4 *)(lVar3 + 0x140cb51e0);
        }
        puVar11 = &local_1078;
      }
      if (DAT_1407cd8d4 == 1) {
        FUN_1402228f0(0,puVar11,1);
      }
      FUN_1401ae2f0(&DAT_140cc9688,puVar11,0x10);
    }
  }
  return 1;
}


