#include "resource_tables.h"

#include <array>

namespace reconstructed {
namespace {

// Evidence: reverse/reconstructed/data-structures/resource-handle-map.md,
// graphics-table.md, and renamed decompiled anchors 1400f4f70/1400ced90/1400d0e50.
constexpr std::array<GraphResourceSpec, 5> kStartupGraphs{{
    {"GFX_system_WhiteBack", "media\\system\\WhiteBack.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Startup},
    {"GFX_system_starting", "media\\system\\starting.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Startup},
    {"GFX_system_NowLoading", "media\\system\\NowLoading.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Startup},
    {"GFX_system_TitleBack", "media\\system\\TitleBack.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_system_TitleLogo", "media\\system\\TitleLogo.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
}};

constexpr std::array<GraphResourceSpec, 23> kFrontendGraphs{{
    {"GFX_system_TitleMenu", "media\\system\\TitleMenu.png", GraphLoadKind::Div, 9, 1, 9, 0x21c, 0x3c, ResourceSource::Primary},
    {"GFX_system_TitleMenu2", "media\\system\\TitleMenu2.png", GraphLoadKind::Div, 9, 1, 9, 300, 30, ResourceSource::Secondary},
    {"GFX_system_TitleMenu2_ch1", "media\\system\\TitleMenu2_ch1.png", GraphLoadKind::Div, 9, 1, 9, 300, 30, ResourceSource::Secondary},
    {"GFX_system_TitleMenu2_ch2", "media\\system\\TitleMenu2_ch2.png", GraphLoadKind::Div, 9, 1, 9, 300, 30, ResourceSource::Secondary},
    {"GFX_system_MenuTitle", "media\\system\\MenuTitle.png", GraphLoadKind::Div, 13, 1, 13, 320, 80, ResourceSource::Secondary},
    {"GFX_system_MenuTitle_ch1", "media\\system\\MenuTitle_ch1.png", GraphLoadKind::Div, 13, 1, 13, 320, 80, ResourceSource::Secondary},
    {"GFX_system_MenuTitle_ch2", "media\\system\\MenuTitle_ch2.png", GraphLoadKind::Div, 13, 1, 13, 320, 80, ResourceSource::Secondary},
    {"GFX_system_ConfigMenu", "media\\system\\ConfigMenu.png", GraphLoadKind::Div, 20, 1, 20, 240, 40, ResourceSource::Primary},
    {"GFX_system_ConfigMenu2", "media\\system\\ConfigMenu2.png", GraphLoadKind::Div, 15, 1, 15, 240, 40, ResourceSource::Primary},
    {"GFX_system_KeyConfigMenu", "media\\system\\KeyConfigMenu.png", GraphLoadKind::Div, 21, 1, 21, 240, 40, ResourceSource::Primary},
    {"GFX_system_Stand", "media\\system\\Stand.png", GraphLoadKind::Div, 50, 10, 5, 800, 1000, ResourceSource::Primary},
    {"GFX_system_TextBox", "media\\system\\TextBox.png", GraphLoadKind::Div, 2, 1, 2, 600, 100, ResourceSource::Primary},
    {"GFX_system_TextIcon", "media\\system\\TextIcon.png", GraphLoadKind::Div, 20, 10, 2, 80, 80, ResourceSource::Primary},
    {"GFX_system_EquipMenu", "media\\system\\EquipMenu.png", GraphLoadKind::Div, 30, 6, 5, 300, 240, ResourceSource::Secondary},
    {"GFX_system_MapMenu", "media\\system\\MapMenu.png", GraphLoadKind::Div, 14, 1, 14, 400, 60, ResourceSource::Secondary},
    {"GFX_system_MapMenu2", "media\\system\\MapMenu2.png", GraphLoadKind::Div, 20, 1, 20, 240, 80, ResourceSource::Secondary},
    {"GFX_system_StageFrame", "media\\system\\StageFrame.png", GraphLoadKind::Div, 2, 2, 1, 600, 720, ResourceSource::Primary},
    {"GFX_system_StageFrame2", "media\\system\\StageFrame2.png", GraphLoadKind::Div, 15, 5, 3, 390, 300, ResourceSource::Primary},
    {"GFX_system_Num_s", "media\\system\\Num_s.png", GraphLoadKind::Div, 14, 14, 1, 20, 30, ResourceSource::Primary},
    {"GFX_system_DifficultyTips", "media\\system\\DifficultyTips.png", GraphLoadKind::Div, 6, 1, 6, 300, 120, ResourceSource::Secondary},
    {"GFX_effect_Effect_s", "media\\effect\\Effect_s.png", GraphLoadKind::Div, 0x14, 10, 2, 100, 100, ResourceSource::Primary},
    {"GFX_player_DataWindow2", "media\\player\\DataWindow2.png", GraphLoadKind::Div, 10, 10, 1, 60, 60, ResourceSource::Primary},
    {"GFX_system_WhiteBack_frontend", "media\\system\\WhiteBack.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Startup},
}};

constexpr std::array<GraphResourceSpec, 59> kExpandedGraphs{{
    {"GFX_system_BetaLogo", "media\\system\\BetaLogo.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_system_DemoEnd", "media\\system\\DemoEnd.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_system_TitleMenu", "media\\system\\TitleMenu.png", GraphLoadKind::Div, 9, 1, 9, 0x21c, 0x3c, ResourceSource::Primary},
    {"GFX_system_Stand", "media\\system\\Stand.png", GraphLoadKind::Div, 0x32, 10, 5, 800, 1000, ResourceSource::Primary},
    {"GFX_system_TextBox", "media\\system\\TextBox.png", GraphLoadKind::Div, 2, 1, 2, 600, 100, ResourceSource::Primary},
    {"GFX_system_TextIcon", "media\\system\\TextIcon.png", GraphLoadKind::Div, 0x14, 10, 2, 0x50, 0x50, ResourceSource::Primary},
    {"GFX_system_ConfigMenu", "media\\system\\ConfigMenu.png", GraphLoadKind::Div, 0x14, 1, 0x14, 0xf0, 0x28, ResourceSource::Primary},
    {"GFX_system_ConfigMenu2", "media\\system\\ConfigMenu2.png", GraphLoadKind::Div, 0xf, 1, 0xf, 0xf0, 0x28, ResourceSource::Primary},
    {"GFX_system_KeyConfigMenu", "media\\system\\KeyConfigMenu.png", GraphLoadKind::Div, 0x15, 1, 0x15, 0xf0, 0x28, ResourceSource::Primary},
    {"GFX_system_Num_s", "media\\system\\Num_s.png", GraphLoadKind::Div, 0xe, 0xe, 1, 0x14, 0x1e, ResourceSource::Primary},
    {"GFX_system_Num_m", "media\\system\\Num_m.png", GraphLoadKind::Div, 10, 10, 1, 0x20, 0x30, ResourceSource::Primary},
    {"GFX_system_Num_l", "media\\system\\Num_l.png", GraphLoadKind::Div, 0xe, 0xe, 1, 0x30, 0x48, ResourceSource::Primary},
    {"GFX_player_DataWindow", "media\\player\\DataWindow.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_player_TimeWindow", "media\\player\\TimeWindow.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_player_DataWindow2", "media\\player\\DataWindow2.png", GraphLoadKind::Div, 10, 10, 1, 0x3c, 0x3c, ResourceSource::Primary},
    {"GFX_player_Player", "media\\player\\Player.png", GraphLoadKind::Div, 0x78, 0xf, 8, 0x50, 0x50, ResourceSource::Primary},
    {"GFX_player_Item", "media\\player\\Item.png", GraphLoadKind::Div, 0xf, 0xf, 1, 100, 100, ResourceSource::Primary},
    {"GFX_player_PlayerFrame", "media\\player\\PlayerFrame.png", GraphLoadKind::Div, 0x1e, 10, 3, 0x154, 0x2d0, ResourceSource::Primary},
    {"GFX_player_State", "media\\player\\State.png", GraphLoadKind::Div, 0x20, 1, 0x20, 200, 0x28, ResourceSource::Primary},
    {"GFX_player_DreamGauge", "media\\player\\DreamGauge.png", GraphLoadKind::Div, 2, 2, 1, 0xa0, 0xa0, ResourceSource::Primary},
    {"GFX_effect_Effect_s", "media\\effect\\Effect_s.png", GraphLoadKind::Div, 0x14, 10, 2, 100, 100, ResourceSource::Primary},
    {"GFX_effect_Effect_m", "media\\effect\\Effect_m.png", GraphLoadKind::Div, 0x1e, 10, 3, 200, 200, ResourceSource::Primary},
    {"GFX_effect_Effect_l", "media\\effect\\Effect_l.png", GraphLoadKind::Div, 0x1e, 10, 3, 600, 600, ResourceSource::Primary},
    {"GFX_stage_StageBack1", "media\\stage\\StageBack1.png", GraphLoadKind::Div, 10, 10, 1, 0x2d0, 0xa00, ResourceSource::Primary},
    {"GFX_stage_StageBack1b", "media\\stage\\StageBack1b.png", GraphLoadKind::Div, 10, 10, 1, 0x2d0, 0xa00, ResourceSource::Primary},
    {"GFX_stage_StageBack1c", "media\\stage\\StageBack1c.png", GraphLoadKind::Div, 0x0c, 0x0c, 1, 0x2d0, 0xa00, ResourceSource::Primary},
    {"GFX_stage_StageBack1d", "media\\stage\\StageBack1d.png", GraphLoadKind::Div, 10, 10, 1, 0x2d0, 0xa00, ResourceSource::Primary},
    {"GFX_stage_StageBack2", "media\\stage\\StageBack2.png", GraphLoadKind::Div, 10, 10, 1, 0x2d0, 0x2d0, ResourceSource::Primary},
    {"GFX_stage_Enemy_s", "media\\stage\\Enemy_s.png", GraphLoadKind::Div, 0xaa, 10, 0x11, 100, 100, ResourceSource::Primary},
    {"GFX_stage_Enemy_m", "media\\stage\\Enemy_m.png", GraphLoadKind::Div, 0xe6, 10, 0x17, 200, 200, ResourceSource::Primary},
    {"GFX_stage_Enemy_l", "media\\stage\\Enemy_l.png", GraphLoadKind::Div, 0x6e, 10, 0xb, 600, 600, ResourceSource::Primary},
    {"GFX_stage_Boss", "media\\stage\\Boss.png", GraphLoadKind::Div, 0xa0, 10, 0x10, 200, 200, ResourceSource::Primary},
    {"GFX_stage_Bullet", "media\\stage\\Bullet.png", GraphLoadKind::Div, 0x28, 10, 4, 0x3c, 0x3c, ResourceSource::Primary},
    {"GFX_gallery_NoticeFrame", "media\\gallery\\NoticeFrame.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_gallery_GalleryFrame", "media\\gallery\\GalleryFrame.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_gallery_EnemyListWindow", "media\\gallery\\EnemyListWindow.png", GraphLoadKind::Single, 1, 1, 1, 0, 0, ResourceSource::Primary},
    {"GFX_system_Manual", "media\\system\\Manual.png", GraphLoadKind::Div, 0xb, 1, 0xb, 0, 0, ResourceSource::Secondary},
    {"GFX_system_ManualMenu", "media\\system\\ManualMenu.png", GraphLoadKind::Div, 0xc, 1, 0xc, 0, 0, ResourceSource::Secondary},
    {"GFX_system_DifficultyTips", "media\\system\\DifficultyTips.png", GraphLoadKind::Div, 6, 1, 6, 0, 0, ResourceSource::Secondary},
    {"GFX_system_KerPromot", "media\\system\\KerPromot.png", GraphLoadKind::Div, 0xe, 1, 0xe, 0, 0, ResourceSource::Secondary},
    {"GFX_player_PauseMenu", "media\\player\\PauseMenu.png", GraphLoadKind::Div, 0x1e, 1, 0x1e, 0, 0, ResourceSource::Secondary},
    {"GFX_stage_TutorialPanel", "media\\stage\\TutorialPanel.png", GraphLoadKind::Div, 3, 3, 1, 0, 0, ResourceSource::Secondary},
    {"GFX_player_Unlock", "media\\player\\Unlock.png", GraphLoadKind::Div, 9, 1, 9, 0, 0, ResourceSource::Secondary},
    {"GFX_gallery_NoticeText2", "media\\gallery\\NoticeText2.png", GraphLoadKind::Div, 0x14, 1, 0x14, 0, 0, ResourceSource::Secondary},
    {"GFX_gallery_NoticeText3", "media\\gallery\\NoticeText3.png", GraphLoadKind::Div, 0x32, 1, 0x32, 0, 0, ResourceSource::Secondary},
    {"GFX_system_Manual_eng", "media\\system\\Manual_eng.png", GraphLoadKind::Div, 0xb, 1, 0xb, 0, 0, ResourceSource::Secondary},
    {"GFX_player_PauseMenu_eng", "media\\player\\PauseMenu_eng.png", GraphLoadKind::Div, 0x1e, 1, 0x1e, 0, 0, ResourceSource::Secondary},
    {"GFX_stage_TutorialPanel_eng", "media\\stage\\TutorialPanel_eng.png", GraphLoadKind::Div, 3, 3, 1, 0, 0, ResourceSource::Secondary},
    {"GFX_player_Unlock_eng", "media\\player\\Unlock_eng.png", GraphLoadKind::Div, 9, 1, 9, 0, 0, ResourceSource::Secondary},
    {"GFX_system_Manual_ch1", "media\\system\\Manual_ch1.png", GraphLoadKind::Div, 0xb, 1, 0xb, 0, 0, ResourceSource::Secondary},
    {"GFX_player_PauseMenu_ch1", "media\\player\\PauseMenu_ch1.png", GraphLoadKind::Div, 0x1e, 1, 0x1e, 0, 0, ResourceSource::Secondary},
    {"GFX_stage_TutorialPanel_ch1", "media\\stage\\TutorialPanel_ch1.png", GraphLoadKind::Div, 3, 3, 1, 0, 0, ResourceSource::Secondary},
    {"GFX_player_Unlock_ch1", "media\\player\\Unlock_ch1.png", GraphLoadKind::Div, 9, 1, 9, 0, 0, ResourceSource::Secondary},
    {"GFX_system_Manual_ch2", "media\\system\\Manual_ch2.png", GraphLoadKind::Div, 0xb, 1, 0xb, 0, 0, ResourceSource::Secondary},
    {"GFX_player_PauseMenu_ch2", "media\\player\\PauseMenu_ch2.png", GraphLoadKind::Div, 0x1e, 1, 0x1e, 0, 0, ResourceSource::Secondary},
    {"GFX_stage_TutorialPanel_ch2", "media\\stage\\TutorialPanel_ch2.png", GraphLoadKind::Div, 3, 3, 1, 0, 0, ResourceSource::Secondary},
    {"GFX_player_Unlock_ch2", "media\\player\\Unlock_ch2.png", GraphLoadKind::Div, 9, 1, 9, 0, 0, ResourceSource::Secondary},
    {"GFX_gallery_GalleryPic_ch1", "media\\gallery\\GalleryPic_ch1.png", GraphLoadKind::Div, 0x14, 5, 4, 0, 0, ResourceSource::Secondary},
    {"GFX_gallery_GalleryPic_ch2", "media\\gallery\\GalleryPic_ch2.png", GraphLoadKind::Div, 0x14, 5, 4, 0, 0, ResourceSource::Secondary},
}};

constexpr std::array<SoundResourceSpec, 48> kSounds{{
    {"BGM_bgm_Opening", "media\\bgm\\Opening.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Title", "media\\bgm\\Title.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Tutorial", "media\\bgm\\Tutorial.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Gameover", "media\\bgm\\Gameover.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage1", "media\\bgm\\Stage1.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage2", "media\\bgm\\Stage2.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage3", "media\\bgm\\Stage3.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage4", "media\\bgm\\Stage4.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage5", "media\\bgm\\Stage5.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage6", "media\\bgm\\Stage6.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage7", "media\\bgm\\Stage7.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage8", "media\\bgm\\Stage8.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage9", "media\\bgm\\Stage9.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Stage10", "media\\bgm\\Stage10.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Boss1", "media\\bgm\\Boss1.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Boss2", "media\\bgm\\Boss2.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Boss3", "media\\bgm\\Boss3.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Boss4", "media\\bgm\\Boss4.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Boss5", "media\\bgm\\Boss5.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_StageClear", "media\\bgm\\StageClear.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Ending", "media\\bgm\\Ending.ogg", SoundKind::Bgm, 3},
    {"BGM_bgm_Unlock", "media\\bgm\\Unlock.ogg", SoundKind::Bgm, 3},
    {"SE_se_Select", "media\\se\\Select.mp3", SoundKind::Se, 3},
    {"SE_se_Enter", "media\\se\\Enter.wav", SoundKind::Se, 3},
    {"SE_se_Cancel", "media\\se\\Cancel.wav", SoundKind::Se, 3},
    {"SE_se_Error", "media\\se\\Error.wav", SoundKind::Se, 3},
    {"SE_se_Switch", "media\\se\\Switch.wav", SoundKind::Se, 3},
    {"SE_se_Text", "media\\se\\Text.wav", SoundKind::Se, 3},
    {"SE_se_Miss", "media\\se\\Miss.wav", SoundKind::Se, 3},
    {"SE_se_Shot1", "media\\se\\Shot1.wav", SoundKind::Se, 3},
    {"SE_se_Shothit", "media\\se\\Shothit.wav", SoundKind::Se, 3},
    {"SE_se_Shothit2", "media\\se\\Shothit2.wav", SoundKind::Se, 3},
    {"SE_se_Item1", "media\\se\\Item1.wav", SoundKind::Se, 3},
    {"SE_se_BossApproach", "media\\se\\BossApproach.wav", SoundKind::Se, 3},
    {"SE_se_BossLife", "media\\se\\BossLife.wav", SoundKind::Se, 3},
    {"SE_se_Notice", "media\\se\\Notice.wav", SoundKind::Se, 3},
    {"SE_se_Bomb1", "media\\se\\Bomb1.wav", SoundKind::Se, 3},
    {"SE_se_Bomb2", "media\\se\\Bomb2.wav", SoundKind::Se, 3},
    {"SE_se_Bomb3", "media\\se\\Bomb3.wav", SoundKind::Se, 3},
    {"SE_se_Bomb4", "media\\se\\Bomb4.wav", SoundKind::Se, 3},
    {"SE_se_Bomb5", "media\\se\\Bomb5.wav", SoundKind::Se, 3},
    {"SE_se_Bomb6", "media\\se\\Bomb6.wav", SoundKind::Se, 3},
    {"SE_se_Bomb7", "media\\se\\Bomb7.wav", SoundKind::Se, 3},
    {"SE_se_Bomb8", "media\\se\\Bomb8.wav", SoundKind::Se, 3},
    {"SE_se_Fever1", "media\\se\\Fever1.wav", SoundKind::Se, 3},
    {"SE_se_Fever2", "media\\se\\Fever2.mp3", SoundKind::Se, 3},
    {"SE_se_Fever3", "media\\se\\Fever3.wav", SoundKind::Se, 3},
    {"SE_se_Fever4", "media\\se\\Fever4.wav", SoundKind::Se, 3},
}};

constexpr std::array<TextResourceSpec, 4> kTexts{{
    {"text01_japanese", "media\\text\\text01.csv", 932, false},
    {"text02_english", "media\\text\\text02.csv", 932, false},
    {"text03_simplified_chinese", "media\\text\\text03.csv", 65001, true},
    {"text04_traditional_chinese", "media\\text\\text04.csv", 65001, true},
}};

} // namespace

std::span<const GraphResourceSpec> startupGraphResources() { return kStartupGraphs; }
std::span<const GraphResourceSpec> frontendGraphResources() { return kFrontendGraphs; }
std::span<const GraphResourceSpec> expandedGraphResources() { return kExpandedGraphs; }
std::span<const SoundResourceSpec> soundResources() { return kSounds; }
std::span<const TextResourceSpec> textResources() { return kTexts; }

const char* toString(ResourceSource source) {
    switch (source) {
    case ResourceSource::Startup: return "startup";
    case ResourceSource::Primary: return "primary";
    case ResourceSource::Secondary: return "secondary";
    }
    return "unknown";
}

const char* toString(GraphLoadKind kind) {
    return kind == GraphLoadKind::Div ? "div" : "single";
}

const char* toString(SoundKind kind) {
    return kind == SoundKind::Bgm ? "bgm" : "se";
}

} // namespace reconstructed
