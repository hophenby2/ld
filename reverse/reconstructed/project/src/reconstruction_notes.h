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
// Original player-side object bounds point to a 600x720 local gameplay area.
// StageFrame.png is loaded as 2 frames of 600x720 and drawn at screen x=40.
inline constexpr RectI kPlayLocalRect{0, 0, 600, kScreenHeight};
inline constexpr PointI kPlayScreenOrigin{40, 0};
inline constexpr PointI kStageBackOrigin{40, 0};
inline constexpr RectI kStageBackRect{kStageBackOrigin.x, kStageBackOrigin.y, 720, kScreenHeight};
inline constexpr RectI kStageFrameRect{kPlayScreenOrigin.x, kPlayScreenOrigin.y, 600, kScreenHeight};
inline constexpr PointI kPlayerStart{300, 620};
} // namespace gameplay_layout

namespace hud_layout {
// Scaffold anchors only. Exact original HUD coordinates still require deeper
// FUN_1400c2860 xrefs for DataWindow/TimeWindow/DataWindow2/PlayerFrame/State.
inline constexpr RectI kTimeWindowRect{940, 0, 340, 340};
inline constexpr RectI kDataWindowRect{940, 340, 340, 380};

inline constexpr int kLabelX = 1040;
inline constexpr int kNumberRightX = 1230; // Scaffold anchor; refine once numeric draw helper is recovered.
inline constexpr int kScoreY = 450;
inline constexpr int kBaseValueY = 500;
inline constexpr int kGaugeY = 530;
inline constexpr int kTokenY = 580;
inline constexpr int kStageY = 610;
inline constexpr int kStockY = 650;
inline constexpr int kPipStartX = 1037;
inline constexpr int kPipStep = 27;
inline constexpr int kMaxTokens = 9;

inline constexpr int kGaugeBarWidth = 160;
inline constexpr int kGaugeBarHeight = 12;
inline constexpr int kDreamGaugePreviewCenterOffsetX = 80;
inline constexpr int kDreamGaugePreviewCenterOffsetY = 8;
inline constexpr double kDreamGaugePreviewScale = 0.28;
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
inline constexpr int kStageFrame2Frames = 15;
inline constexpr int kStageFrame2FrameWidth = 390;
inline constexpr int kStageFrame2FrameHeight = 300;
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
inline constexpr int kPromptMode = 1;
inline constexpr int kPromptLayer = 0x70;
inline constexpr int kPromptAlpha = 0xff;
// Unresolved: six EquipMenu row coordinates, Stand x/local_1ec,
// status EquipMenu x/local_1f0, Stand shadow x offset DAT_14053ac44,
// and MenuTitle/TextIcon exact frame semantics require DAT_14053 data decoding.
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
// Confirmed resources in 1400d5d50_state_04_gameplay_update_candidate.c;
// exact map layout coordinates are unresolved until fVar38/fVar44/local_290
// and local_218 DAT_14053-derived arrays are decoded.
inline constexpr int kStageFrameLayer = 0x4b;
inline constexpr int kMapMenuLayer = 0x50;
} // namespace stage_select_evidence

namespace hud_evidence {
// Confirmed resource identities; exact HUD coordinates/frame mapping need further
// FUN_1400c2860 xrefs before they can replace scaffold anchors.
inline constexpr bool kHudCoordinatesResolved = false;
} // namespace hud_evidence

// Primary evidence files:
// - reverse/README.md: DxLib + DXArchive, extracted assets, DXA key.
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c
// - reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c
// - reverse/reconstructed/data-structures/resource-handle-map.md
// - reverse/symbols/image-index.csv

} // namespace reconstructed::notes
