// Function: load_secondary_localized_resources_candidate @ 1400d0e50
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 load_secondary_localized_resources_candidate(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined1 auStack_68 [32];
  undefined *local_48;
  undefined4 *local_40;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_20;
  int local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_68;
  if (DAT_140e441b4 == 0) {
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e47570;
    local_40._0_4_ = 0x230;
    local_48._0_4_ = 800;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\Manual.png",0xb,1,0xb);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e476a0;
    local_40._0_4_ = 0x1e;
    local_48._0_4_ = 0xb4;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\ManualMenu.png",0xc,1,0xc);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e47460;
    local_40._0_4_ = 0x78;
    local_48._0_4_ = 300;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\DifficultyTips.png",6,1,6);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e47608;
    local_40._0_4_ = 0x28;
    local_48._0_4_ = 0x8c;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\KerPromot.png",0xe,1,0xe);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e47840;
    local_40._0_4_ = 0x50;
    local_48._0_4_ = 0x1e0;
    iVar1 = dxlib_load_div_graph_candidate("media\\player\\PauseMenu.png",0x1e,1,0x1e);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e477d8;
    local_40._0_4_ = 0x2d0;
    local_48._0_4_ = 600;
    iVar1 = dxlib_load_div_graph_candidate("media\\stage\\TutorialPanel.png",3,3,1);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e475e0;
    local_40._0_4_ = 0x10e;
    local_48._0_4_ = 700;
    iVar1 = dxlib_load_div_graph_candidate("media\\player\\Unlock.png",9,1,9);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e45fb0;
    local_40._0_4_ = 0x19;
    local_48._0_4_ = 0x8c;
    iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText2.png",0x14,1,0x14);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e466f0;
    local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0x19);
    local_48 = (undefined *)CONCAT44(local_48._4_4_,0x8c);
    iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText3.png",0x32,1,0x32);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    pcVar4 = "media\\gallery\\GalleryPic.png";
LAB_1400d1cd4:
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e46810;
    local_40._0_4_ = 0x2d0;
    local_48._0_4_ = 0x500;
    iVar1 = dxlib_load_div_graph_candidate(pcVar4,0x14,5,4);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e47438;
    local_40._0_4_ = 0x1e;
    local_48._0_4_ = 300;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\TitleMenu2.png",9,1,9);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e46018;
    local_40._0_4_ = 0x50;
    local_48._0_4_ = 0x140;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\MenuTitle.png",0xd,1,0xd);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e46a40;
    local_40._0_4_ = 0xf0;
    local_48._0_4_ = 300;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\EquipMenu.png",0x1e,6,5);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = (undefined4 *)&DAT_140e46918;
    local_40._0_4_ = 0x3c;
    local_48._0_4_ = 400;
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu.png",0xe,1,0xe);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    local_20 = 0;
    local_28 = 0;
    local_30 = 0;
    local_38 = &DAT_140e47650;
    local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0x50);
    local_48 = (undefined *)CONCAT44(local_48._4_4_,0xf0);
    iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu2.png",0x14,1,0x14);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    pcVar4 = "media\\stage\\BossApproach1.png";
  }
  else {
    if (DAT_140e441b4 == 1) {
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47570;
      local_40._0_4_ = 0x230;
      local_48._0_4_ = 800;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\Manual_eng.png",0xb,1,0xb);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e476a0;
      local_40._0_4_ = 0x1e;
      local_48._0_4_ = 0xb4;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\ManualMenu_eng.png",0xc,1,0xc);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47460;
      local_40._0_4_ = 0x78;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\DifficultyTips_eng.png",6,1,6);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47608;
      local_40._0_4_ = 0x28;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\KerPromot_eng.png",0xe,1,0xe);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47840;
      local_40._0_4_ = 0x50;
      local_48._0_4_ = 0x1e0;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\PauseMenu_eng.png",0x1e,1,0x1e);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e477d8;
      local_40._0_4_ = 0x2d0;
      local_48._0_4_ = 600;
      iVar1 = dxlib_load_div_graph_candidate("media\\stage\\TutorialPanel_eng.png",3,3,1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e475e0;
      local_40._0_4_ = 0x10e;
      local_48._0_4_ = 700;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\Unlock_eng.png",9,1,9);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e45fb0;
      local_40._0_4_ = 0x19;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText2_eng.png",0x14,1,0x14);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e466f0;
      local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0x19);
      local_48 = (undefined *)CONCAT44(local_48._4_4_,0x8c);
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText3_eng.png",0x32,1,0x32);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      pcVar4 = "media\\gallery\\GalleryPic_eng.png";
      goto LAB_1400d1cd4;
    }
    if (DAT_140e441b4 == 2) {
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47570;
      local_40._0_4_ = 0x230;
      local_48._0_4_ = 800;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\Manual_ch1.png",0xb,1,0xb);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e476a0;
      local_40._0_4_ = 0x1e;
      local_48._0_4_ = 0xb4;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\ManualMenu_ch1.png",0xc,1,0xc);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47460;
      local_40._0_4_ = 0x78;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\DifficultyTips_ch1.png",6,1,6);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47608;
      local_40._0_4_ = 0x28;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\KerPromot_ch1.png",0xe,1,0xe);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47840;
      local_40._0_4_ = 0x50;
      local_48._0_4_ = 0x1e0;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\PauseMenu_ch1.png",0x1e,1,0x1e);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e477d8;
      local_40._0_4_ = 0x2d0;
      local_48._0_4_ = 600;
      iVar1 = dxlib_load_div_graph_candidate("media\\stage\\TutorialPanel_ch1.png",3,3,1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e475e0;
      local_40._0_4_ = 0x10e;
      local_48._0_4_ = 700;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\Unlock_ch1.png",9,1,9);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e45fb0;
      local_40._0_4_ = 0x19;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText2_ch1.png",0x14,1,0x14);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e466f0;
      local_40._0_4_ = 0x19;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText3_ch1.png",0x32,1,0x32);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e46810;
      local_40._0_4_ = 0x2d0;
      local_48._0_4_ = 0x500;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\GalleryPic_ch1.png",0x14,5,4);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47438;
      local_40._0_4_ = 0x1e;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\TitleMenu2_ch1.png",9,1,9);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e46018;
      local_40._0_4_ = 0x50;
      local_48._0_4_ = 0x140;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MenuTitle_ch1.png",0xd,1,0xd);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e46a40;
      local_40._0_4_ = 0xf0;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\EquipMenu_ch1.png",0x1e,6,5);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e46918;
      local_40._0_4_ = 0x3c;
      local_48._0_4_ = 400;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu_ch1.png",0xe,1,0xe);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47650;
      local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0x50);
      local_48 = (undefined *)CONCAT44(local_48._4_4_,0xf0);
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu2_ch.png",0x14,1,0x14);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      pcVar4 = "media\\stage\\BossApproach1_ch1.png";
    }
    else {
      if (DAT_140e441b4 != 3) goto LAB_1400d1ee0;
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47570;
      local_40._0_4_ = 0x230;
      local_48._0_4_ = 800;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\Manual_ch2.png",0xb,1,0xb);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e476a0;
      local_40._0_4_ = 0x1e;
      local_48._0_4_ = 0xb4;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\ManualMenu_ch2.png",0xc,1,0xc);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47460;
      local_40._0_4_ = 0x78;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\DifficultyTips_ch2.png",6,1,6);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47608;
      local_40._0_4_ = 0x28;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\KerPromot_ch2.png",0xe,1,0xe);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47840;
      local_40._0_4_ = 0x50;
      local_48._0_4_ = 0x1e0;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\PauseMenu_ch2.png",0x1e,1,0x1e);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e477d8;
      local_40._0_4_ = 0x2d0;
      local_48._0_4_ = 600;
      iVar1 = dxlib_load_div_graph_candidate("media\\stage\\TutorialPanel_ch2.png",3,3,1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e475e0;
      local_40._0_4_ = 0x10e;
      local_48._0_4_ = 700;
      iVar1 = dxlib_load_div_graph_candidate("media\\player\\Unlock_ch2.png",9,1,9);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e45fb0;
      local_40._0_4_ = 0x19;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText2_ch2.png",0x14,1,0x14);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e466f0;
      local_40._0_4_ = 0x19;
      local_48._0_4_ = 0x8c;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\NoticeText3_ch2.png",0x32,1,0x32);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e46810;
      local_40._0_4_ = 0x2d0;
      local_48._0_4_ = 0x500;
      iVar1 = dxlib_load_div_graph_candidate("media\\gallery\\GalleryPic_ch2.png",0x14,5,4);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e47438;
      local_40._0_4_ = 0x1e;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\TitleMenu2_ch2.png",9,1,9);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e46018;
      local_40._0_4_ = 0x50;
      local_48._0_4_ = 0x140;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MenuTitle_ch2.png",0xd,1,0xd);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e46a40;
      local_40._0_4_ = 0xf0;
      local_48._0_4_ = 300;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\EquipMenu_ch2.png",0x1e,6,5);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = (undefined4 *)&DAT_140e46918;
      local_40._0_4_ = 0x3c;
      local_48._0_4_ = 400;
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu_ch2.png",0xe,1,0xe);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      local_20 = 0;
      local_28 = 0;
      local_30 = 0;
      local_38 = &DAT_140e47650;
      local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0x50);
      local_48 = (undefined *)CONCAT44(local_48._4_4_,0xf0);
      iVar1 = dxlib_load_div_graph_candidate("media\\system\\MapMenu2_ch.png",0x14,1,0x14);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      pcVar4 = "media\\stage\\BossApproach1_ch2.png";
    }
  }
  local_20 = 0;
  local_28 = 0;
  local_30 = 0;
  local_38 = &DAT_140e41ac0;
  local_40 = (undefined4 *)CONCAT44(local_40._4_4_,100);
  local_48 = (undefined *)CONCAT44(local_48._4_4_,400);
  iVar1 = dxlib_load_div_graph_candidate(pcVar4,0xe,1,0xe);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
LAB_1400d1ee0:
  if ((DAT_140e441b4 == 0) || (DAT_140e441b4 == 1)) {
    DAT_140e470c0 = "Nyashi.ttf";
    DAT_140e47640 = &DAT_140538128;
  }
  else if ((DAT_140e441b4 == 2) || (DAT_140e441b4 == 3)) {
    DAT_140e470c0 = "ChillRoundM.ttf";
    DAT_140e47640 = &DAT_140538920;
  }
  iVar1 = AddFontResourceExA(DAT_140e470c0,0x10,(PVOID)0x0);
  if (0 < iVar1) {
    local_30 = 0xffffffff;
    local_38 = (undefined4 *)((ulonglong)local_38 & 0xffffffff00000000);
    local_40._0_4_ = 0xffffffff;
    local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
    DAT_140e46c60 = FUN_14015a5f0(DAT_140e47640,0x14,9,0x13);
    local_30 = 0xffffffff;
    local_38 = (undefined4 *)((ulonglong)local_38 & 0xffffffff00000000);
    local_40._0_4_ = 0xffffffff;
    local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
    DAT_140e46c64 = FUN_14015a5f0(DAT_140e47640,0x18,9,0x13);
    local_30 = 0xffffffff;
    local_38 = (undefined4 *)((ulonglong)local_38 & 0xffffffff00000000);
    local_40._0_4_ = 0xffffffff;
    local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
    DAT_140e46c68 = FUN_14015a5f0(DAT_140e47640,0x1b,9,0x13);
    local_30 = 0xffffffff;
    local_38 = (undefined4 *)((ulonglong)local_38 & 0xffffffff00000000);
    local_40._0_4_ = 0xffffffff;
    local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
    DAT_140e46c6c = FUN_14015a5f0(DAT_140e47640,0x20,9,0x13);
    local_30 = 0xffffffff;
    local_38 = (undefined4 *)((ulonglong)local_38 & 0xffffffff00000000);
    local_40 = (undefined4 *)CONCAT44(local_40._4_4_,0xffffffff);
    local_48 = (undefined *)((ulonglong)local_48 & 0xffffffff00000000);
    _DAT_140e46c70 = FUN_14015a5f0(DAT_140e47640,0x12,9,0x12);
    piVar3 = &DAT_140e46c60;
    do {
      if (*piVar3 == -1) {
        return 0xffffffff;
      }
      piVar3 = piVar3 + 1;
    } while ((longlong)piVar3 < 0x140e46c88);
    local_18 = 0;
    local_14 = 0;
    if (DAT_140e441b4 == 0) {
      iVar1 = FUN_140137460("media\\text\\text01.csv",0);
    }
    else {
      iVar1 = 0;
    }
    if (DAT_140e441b4 == 1) {
      iVar1 = FUN_140137460("media\\text\\text02.csv",0);
    }
    if (DAT_140e441b4 == 2) {
      iVar1 = FUN_140137460("media\\text\\text03.csv",0);
    }
    if (DAT_140e441b4 == 3) {
      iVar1 = FUN_140137460("media\\text\\text04.csv",0);
    }
    if (iVar1 != 0) {
      local_48 = &DAT_140e47a10 + (longlong)local_18 * 0x200;
      local_40 = &local_14;
      iVar2 = FUN_140137aa0(iVar1,"%d,%[^,],%[^,],%d",&local_18,
                            &DAT_140e47910 + (longlong)local_18 * 0x200);
      while ((iVar2 != -1 && (local_18 != 0x22b))) {
        local_48 = &DAT_140e47a10 + (longlong)local_18 * 0x200;
        local_40 = &local_14;
        iVar2 = FUN_140137aa0(iVar1,"%d,%[^,],%[^,],%d",&local_18,
                              &DAT_140e47910 + (longlong)local_18 * 0x200);
      }
      FUN_140137440(iVar1);
      return 1;
    }
    FUN_140137440(0);
  }
  return 0xffffffff;
}


