#pragma once

namespace reconstructed::notes {

inline constexpr const char* kDxArchiveKey = "VanillaFever11";
inline constexpr int kScreenWidth = 0x500;   // 1280, from startup decompile SetGraphMode path.
inline constexpr int kScreenHeight = 0x2d0;  // 720.

struct PointI {
    int x = 0;
    int y = 0;
};

struct RectI {
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    constexpr int right() const { return x + width; }
    constexpr int bottom() const { return y + height; }
};

namespace title_layout {
inline constexpr int kLogoWidth = 500;
inline constexpr int kLogoHeight = 320;
inline constexpr int kLogoX = (kScreenWidth - kLogoWidth) / 2;
inline constexpr int kLogoBaseY = 44;

inline constexpr int kMenuCount = 9;
inline constexpr int kMenuFrameWidth = 540;
inline constexpr int kMenuFrameHeight = 60;
inline constexpr int kMenuSelectedX = (kScreenWidth - kMenuFrameWidth) / 2;
inline constexpr int kMenuSelectedY = 420;
inline constexpr int kMenuNeighborStepX = 20;
inline constexpr int kMenuNeighborStepY = 66;

inline constexpr int kMenu2Width = 300;
inline constexpr int kMenu2Height = 30;
inline constexpr int kMenu2X = 490;
inline constexpr int kMenu2YOffset = 68;
} // namespace title_layout

namespace gameplay_layout {
// Original entities use x=60..660 and are translated by +280 for the central
// screen playfield at x=340..940. Stage scripts retain those original values.
inline constexpr RectI kPlayLocalRect{60, 0, 600, kScreenHeight};
inline constexpr PointI kPlayScreenOrigin{280, 0};
inline constexpr PointI kStageBackOrigin{280, 0};
inline constexpr RectI kStageBackRect{kStageBackOrigin.x, kStageBackOrigin.y, 720, kScreenHeight};
inline constexpr RectI kStageFrameRect{340, 0, 600, kScreenHeight};
inline constexpr PointI kPlayerStart{360, 600};
} // namespace gameplay_layout

namespace hud_layout {
// Right-side anchors and frame identities decoded from FUN_1400c2860.
inline constexpr RectI kRightPanelRect{940, 0, 340, 720};
inline constexpr RectI kTimeWindowRect{940, 0, 340, 340};
inline constexpr RectI kDataWindowRect{940, 340, 340, 380};

inline constexpr int kLabelX = 1040;
inline constexpr int kNumberRightX = 1240;
inline constexpr int kBestY = 410;
inline constexpr int kLikeY = 450;
inline constexpr int kFollowerY = 500;
inline constexpr int kBuzzY = 530;
inline constexpr int kLifeY = 580;
inline constexpr int kNextExtendY = 610;
inline constexpr int kMentalY = 650;
inline constexpr int kHeartStartX = 1037;
inline constexpr int kHeartStep = 27;
inline constexpr int kHeartCount = 9;

// Left-side HUD from FUN_1400c4bb0. This panel is conditionally called from
// FUN_1400c2860 and mirrors the right DataWindow-style HUD on x<340.
inline constexpr RectI kLeftDataWindowRect{0, 330, 340, 380};
inline constexpr int kLeftStageLabelX = 30;
inline constexpr int kLeftStageLabelY = 365;
inline constexpr int kLeftFrameLabelX = 280;
inline constexpr int kLeftFrameLabelY = 365;
inline constexpr int kLeftGrazeLabelX = 135;
inline constexpr int kLeftGrazeLabelY = 535;
inline constexpr int kLeftKeyStateIconX = 280;
inline constexpr int kLeftKeyStateIconY = 535;
inline constexpr int kLeftKeyStateValueRightX = 245;
inline constexpr int kLeftPlayerIconX = 55;
inline constexpr int kLeftPlayerIconY = 640;
inline constexpr int kLeftDataWindow2X = 160;
inline constexpr int kLeftDataWindow2Y = 647;
} // namespace hud_layout

namespace ui_resource_evidence {
inline constexpr int kEquipMenuFrames = 30;
inline constexpr int kEquipMenuFrameWidth = 300;
inline constexpr int kEquipMenuFrameHeight = 240;
inline constexpr int kMenuTitleFrames = 13;
inline constexpr int kMenuTitleFrameWidth = 320;
inline constexpr int kMenuTitleFrameHeight = 80;
inline constexpr int kStandFrames = 50;
inline constexpr int kStandFrameWidth = 800;
inline constexpr int kStandFrameHeight = 1000;
inline constexpr int kTextBoxFrames = 2;
inline constexpr int kTextBoxFrameWidth = 600;
inline constexpr int kTextBoxFrameHeight = 100;
inline constexpr int kTextIconFrames = 20;
inline constexpr int kTextIconFrameWidth = 80;
inline constexpr int kTextIconFrameHeight = 80;
inline constexpr int kMapMenuFrames = 14;
inline constexpr int kMapMenuFrameWidth = 400;
inline constexpr int kMapMenuFrameHeight = 60;
inline constexpr int kMapMenu2Frames = 20;
inline constexpr int kMapMenu2FrameWidth = 240;
inline constexpr int kMapMenu2FrameHeight = 80;
inline constexpr int kStageFrameFrames = 2;
inline constexpr int kStageFrameFrameWidth = 600;
inline constexpr int kStageFrameFrameHeight = 720;
inline constexpr int kStageFrame2Frames = 15;
inline constexpr int kStageFrame2FrameWidth = 390;
inline constexpr int kStageFrame2FrameHeight = 300;
inline constexpr int kNumSmallFrames = 14;
inline constexpr int kNumSmallFrameWidth = 20;
inline constexpr int kNumSmallFrameHeight = 30;
inline constexpr int kDataWindow2Frames = 10;
inline constexpr int kDataWindow2FrameWidth = 60;
inline constexpr int kDataWindow2FrameHeight = 60;
inline constexpr int kPlayerFrameFrames = 30;
inline constexpr int kPlayerFrameFrameWidth = 340;
inline constexpr int kPlayerFrameFrameHeight = 720;
inline constexpr int kStateFrames = 32;
inline constexpr int kStateFrameWidth = 200;
inline constexpr int kStateFrameHeight = 40;
inline constexpr int kDreamGaugeFrames = 2;
inline constexpr int kDreamGaugeFrameWidth = 160;
inline constexpr int kDreamGaugeFrameHeight = 160;
} // namespace ui_resource_evidence

namespace stage_setup_evidence {
// Confirmed in 1400d4610_state_03_stage_start_init_candidate.c.
inline constexpr PointI kTitleBackOrigin{0, 0};
inline constexpr PointI kMenuTitleOrigin{0, 0};
inline constexpr int kStandY = 300;
inline constexpr int kStandShadowY = 320;
inline constexpr int kStatusEquipMenuY = 160;
inline constexpr PointI kTextBoxOrigin{640, 650};
inline constexpr PointI kTextIconOrigin{390, 650};
inline constexpr PointI kEquipMenuRow0{660, 170};
inline constexpr PointI kEquipMenuRow1{1000, 170};
inline constexpr PointI kEquipMenuRow2{740, 410};
inline constexpr PointI kEquipMenuRow3{1080, 410};
inline constexpr PointI kEquipMenuRow4{910, 560};
inline constexpr PointI kEquipMenuRow5{1100, 650};
inline constexpr int kStandBaseX = 480;
inline constexpr int kStandShadowOffsetX = 15;
inline constexpr int kStatusEquipMenuX = 600;
inline constexpr int kPromptMode = 1;
inline constexpr int kPromptLayer = 0x70;
inline constexpr int kPromptAlpha = 0xff;
// Resolved from LikeDreamer.exe .rdata constants: _DAT_14053bcd0,
// _DAT_14053bd90, _DAT_14053be70, DAT_14053ae7c,
// DAT_14053ac44, and DAT_14053aec0. Remaining frame semantics still need
// handler-level validation.
// Unresolved: transition/easing offsets and MenuTitle/TextIcon exact frame semantics.
} // namespace stage_setup_evidence

namespace prompt_helper_evidence {
// Confirmed default branch coordinates in 1400d9b60_FUN_1400d9b60.c.
inline constexpr PointI kDefaultIcon0{5, 600};
inline constexpr PointI kDefaultText0{45, 600};
inline constexpr PointI kDefaultIcon1{5, 640};
inline constexpr PointI kDefaultText1{45, 640};
inline constexpr PointI kDefaultIcon2{5, 680};
inline constexpr PointI kDefaultText2{45, 680};
// Mode 1..8 coordinates still depend on DAT_14053 constants and are unresolved.
} // namespace prompt_helper_evidence

namespace stage_select_evidence {
// Confirmed state_04 world-map transform and per-node composition.
inline constexpr int kStageFrameLayer = 0x4b;
inline constexpr int kMapMenuLayer = 0x4b;
inline constexpr PointI kMapFocusOffset{640, 320};
inline constexpr int kVisibleLeft = -640;
inline constexpr int kVisibleRight = 1920;
inline constexpr int kMapMenuYOffset = -240;
inline constexpr int kStageFrame2YOffset = -50;
inline constexpr int kStageTintAlpha = 0xbf; // int(0xff * 0.75).
inline constexpr int kMapMenuEntryFrame = 30;
inline constexpr int kStageFrame2EntryFrame = 35;
inline constexpr PointI kStandCenter{200, 480};
inline constexpr PointI kLeftArrow{400, 320};
inline constexpr PointI kRightArrow{880, 320};
} // namespace stage_select_evidence

namespace stage_setup_provisional_layout {
// Remaining practical anchors only. The major state_03 positions above are now
// decoded from .rdata; prompt text placement is scaffold UI, not original.
inline constexpr PointI kPromptNote{648, 682};
} // namespace stage_setup_provisional_layout


namespace difficulty_overlay_evidence {
// state_04 DAT_140e45274 phases: 0=stage, 1=difficulty/counter, 2=launch, -1=back.
inline constexpr int kInputEnableFrame = 0x3b;
inline constexpr int kDifficultyCount = 5;
inline constexpr int kDefaultDifficulty = 2; // Expert
inline constexpr PointI kBaseMapMenu2{590, 460};      // MapMenu2 frame 4, layer 0x50.
inline constexpr PointI kDifficultyMapMenu2{640, 530}; // MapMenu2 frame 6+difficulty, layer 0x54.
inline constexpr PointI kCounterMapMenu2{640, 580};    // MapMenu2 frame 5, layer 0x55.
inline constexpr PointI kCounterArrow{730, 580};       // Effect_s frame 1, layer 0x52.
inline constexpr PointI kDifficultyTips{850, 450};
inline constexpr PointI kLeftDifficultyArrow{500, 530};
inline constexpr PointI kRightDifficultyArrow{780, 530};
inline constexpr double kDifficultyArrowScale = 0.8;
inline constexpr double kCounterArrowScale = 0.5;
inline constexpr int kLayerSwitchCommitFrames = 10;
inline constexpr int kLaunchCommitFrames = 100;
inline constexpr int kMapMenu2BaseFrame = 4;
inline constexpr int kMapMenu2CounterFrame = 5;
inline constexpr int kMapMenu2DifficultyBaseFrame = 6;
inline constexpr int kMapMenu2LockedFrame = 12;
inline constexpr int kMapMenu2SpecialDifficultyFrame = 11;
inline constexpr int kMapMenu2SpecialLockedFrame = 13;
inline constexpr int kSpecialDifficultyTipsFrame = 5;
inline constexpr int kArrowEffectFrame = 1; // DAT_140e41934 = Effect_s frame 1.
inline constexpr int kLockedFixedAngle = 0xf000;
inline constexpr int kLeftFixedAngle = 0x8000;
inline constexpr int kCounterOffFixedAngle = 0xc000;
inline constexpr int kCounterOnFixedAngle = 0x4000;
} // namespace difficulty_overlay_evidence

namespace hud_evidence {
// Resource identities, anchors, and frame meanings are confirmed from
// FUN_1400c2860, FUN_1400c4bb0, and direct sprite-sheet inspection.
inline constexpr bool kHudPanelAnchorsResolved = true;
inline constexpr bool kHudFrameMeaningsResolved = true;
} // namespace hud_evidence

// Primary evidence files:
// - reverse/README.md: DxLib + DXArchive, extracted assets, DXA key.
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c
// - reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c
// - reverse/reconstructed/data-structures/resource-handle-map.md
// - reverse/symbols/image-index.csv

} // namespace reconstructed::notes
