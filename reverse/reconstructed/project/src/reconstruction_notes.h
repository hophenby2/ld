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
// Coordinates follow the original HUD draw candidate around FUN_1400c2860.
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

// Primary evidence files:
// - reverse/README.md: DxLib + DXArchive, extracted assets, DXA key.
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c
// - reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c
// - reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400c2860_FUN_1400c2860.c
// - reverse/reconstructed/data-structures/resource-handle-map.md
// - reverse/symbols/image-index.csv

} // namespace reconstructed::notes
