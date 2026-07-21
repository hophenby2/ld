#include "stage_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <initializer_list>
#include <limits>
#include <string>
#include <string_view>

namespace reconstructed {
namespace {

constexpr float kPi = 3.14159265358979323846f;
constexpr float kTau = kPi * 2.0f;
constexpr int kFixedAngleFullCircle = 0x10000;
constexpr int kStageEntityCap = 0x200;
constexpr int kProjectileCap = 0x800;
constexpr int kRewardItemCap = 0x200;
constexpr int kPlayerSideObjectCap = 0x100;
constexpr int kStageEffectCap = 0x1000;
constexpr std::size_t kReplayStageSnapshotOffset = 0x0098;
constexpr std::size_t kReplayStageSnapshotStride = 0x00f0;
constexpr int kSpecialGaugeReady = 50000;
constexpr int kSpecialGaugeForcedFull = 9999999;
constexpr int kFeverActiveFrames = 600;
constexpr int kLifeStockCap = 9;
constexpr std::array<int, 11> kStageEndFrames{{
    0, 5700, 9700, 9500, 11700, 11800, 12500, 12500, 21420, 17900, 12000,
}};
constexpr std::array<int, 5> kOriginalStockThresholds{{56000, 70000, 70000, 70000, 70000}};
constexpr std::array<std::array<std::int64_t, 5>, 5> kExtendThresholds{{
    {{4000000LL, 16000000LL, 80000000LL, 400000000LL, 2000000000LL}},
    {{6000000LL, 24000000LL, 120000000LL, 600000000LL, 3000000000LL}},
    {{8000000LL, 32000000LL, 160000000LL, 800000000LL, 4000000000LL}},
    {{10000000LL, 40000000LL, 200000000LL, 1000000000LL, 5000000000LL}},
    {{10000000LL, 40000000LL, 200000000LL, 1000000000LL, 5000000000LL}},
}};
constexpr int kGrazeMargin = 48;

void normalizeSystemConfig(std::array<int, 7>& values) {
    values[0] = values[0] != 0 ? 1 : 0;
    values[1] = std::clamp(values[1], 0, 2);
    values[2] = values[2] != 0 ? 1 : 0;
    values[3] = values[3] != 0 ? 1 : 0;
    values[4] = values[4] != 0 ? 1 : 0;
    values[5] = values[5] != 0 ? 1 : 0;
    values[6] = std::clamp(values[6], 0, 3);
}
constexpr std::array<double, 5> kProjectileId1Acceleration{{0.06, 0.07, 0.08, 0.10, 0.10}};
constexpr std::array<double, 5> kProjectileRetargetAcceleration{{0.13, 0.15, 0.175, 0.20, 0.20}};
constexpr std::array<double, 5> kProjectileId13Acceleration{{0.15, 0.17, 0.18, 0.20, 0.20}};
constexpr std::array<int, 5> kScript18Window{{12, 16, 20, 20, 20}};
constexpr std::array<int, 5> kScript1AInterval{{10, 8, 6, 5, 5}};
constexpr std::array<double, 5> kScript1ASpeed{{5.0, 6.0, 6.5, 6.0, 7.0}};
constexpr std::array<int, 5> kScript1CPeriod{{18, 18, 15, 16, 14}};
constexpr std::array<int, 5> kScript1CWindow{{6, 7, 8, 10, 10}};
constexpr std::array<double, 5> kScript1CSpeed{{3.2, 4.0, 4.5, 4.5, 5.5}};
constexpr std::array<int, 5> kScript1DInterval{{4, 3, 3, 3, 2}};
constexpr std::array<double, 5> kScript1DSpeed{{2.5, 3.2, 3.6, 4.0, 5.0}};
constexpr std::array<int, 5> kScript29Interval{{8, 6, 5, 5, 5}};
constexpr std::array<double, 5> kScript29Speed{{3.0, 3.5, 3.5, 4.0, 5.0}};
constexpr std::array<int, 5> kScript2BCount{{1, 3, 5, 7, 7}};
constexpr std::array<double, 5> kScript2BSpeed{{8.0, 10.0, 11.0, 12.0, 12.0}};
constexpr std::array<int, 5> kScript2ECount{{3, 5, 6, 7, 7}};
constexpr std::array<double, 5> kScript2ESpeed{{4.5, 5.0, 5.0, 5.5, 5.5}};
constexpr std::array<int, 5> kHoming12Turn{{120, 160, 200, 250, 300}};
constexpr std::array<int, 5> kHoming14BaseTurn{{200, 240, 270, 300, 300}};
constexpr std::array<int, 5> kEmitter23Interval{{15, 11, 9, 9, 8}};
constexpr std::array<double, 5> kEmitter23Speed{{3.5, 4.5, 5.5, 5.0, 6.0}};
constexpr std::array<int, 5> kCurve26Turn{{150, 170, 180, 195, 211}};
constexpr std::array<int, 5> kCurve2CTurn{{150, 170, 180, 195, 180}};
constexpr std::array<int, 5> kOrbitTurn{{0x46, 0x78, 0x8c, 0xb4, 0xdc}};
constexpr std::array<int, 5> kStage02Type1DInterval{{90, 50, 40, 30, 20}};
constexpr std::array<double, 5> kStage02Type1DSpeed{{4.5, 5.5, 6.5, 7.0, 8.0}};
constexpr std::array<int, 5> kStage02Type1EInterval{{140, 100, 80, 80, 50}};
constexpr std::array<double, 5> kStage02Type1ESpeed{{5.0, 6.0, 7.0, 8.5, 9.5}};
constexpr std::array<int, 5> kStage03Type25Start{{24, 18, 15, 15, 15}};
constexpr std::array<int, 5> kStage03Type25Cycle{{120, 80, 70, 60, 50}};
constexpr std::array<double, 5> kStage03Type25Speed{{6.0, 7.0, 8.0, 8.8, 10.8}};
constexpr std::array<int, 5> kStage03Type26Cycle{{110, 70, 60, 60, 60}};
constexpr std::array<double, 5> kStage03Type26ShotSpeed{{6.0, 7.0, 8.0, 8.0, 9.5}};
constexpr std::array<double, 5> kStage03Type26FanSpeed{{4.0, 5.0, 6.0, 6.5, 8.0}};
constexpr std::array<int, 5> kStage03Type26FanCount{{5, 7, 9, 7, 11}};
constexpr std::array<int, 5> kStage03Type27Cycle{{160, 120, 90, 90, 90}};
constexpr std::array<int, 5> kStage03Type27FanCount{{3, 5, 7, 7, 9}};
constexpr std::array<double, 5> kStage03Type27FanSpeed{{4.5, 6.5, 7.5, 8.0, 9.5}};
constexpr std::array<double, 5> kStage03Type28Speed{{5.0, 6.0, 6.5, 6.5, 8.0}};
constexpr std::array<int, 5> kStage03Type2ACycle{{90, 60, 50, 50, 40}};
constexpr std::array<double, 5> kStage03Type2ASpeed{{5.6, 6.5, 7.0, 6.5, 8.0}};
constexpr std::array<int, 5> kStage03Type2BInterval{{18, 14, 12, 12, 10}};
constexpr std::array<int, 5> kStage03Type2BCountA{{2, 3, 5, 5, 7}};
constexpr std::array<double, 5> kStage03Type2BSpeedA{{4.5, 5.8, 6.5, 6.5, 8.0}};
constexpr std::array<int, 5> kStage03Type2BHalfPeriod{{55, 40, 32, 26, 20}};
constexpr std::array<int, 5> kStage03Type2BCountB{{7, 13, 15, 15, 17}};
constexpr std::array<double, 5> kStage03Type2BSpeedB{{4.0, 4.5, 5.0, 5.5, 7.0}};
constexpr std::array<int, 5> kStage03Type2CInterval{{60, 36, 28, 24, 18}};
constexpr std::array<double, 5> kStage03Type2CSpeed{{4.5, 5.5, 6.0, 6.5, 8.5}};
constexpr std::array<int, 5> kStage03Type2DInterval{{120, 80, 70, 60, 45}};
constexpr std::array<int, 5> kStage03Type2DBurst{{16, 20, 24, 24, 24}};
constexpr std::array<int, 5> kStage03Type2DFanCount{{1, 1, 2, 2, 2}};
constexpr std::array<double, 5> kStage03Type2DSpeed{{5.5, 6.5, 7.5, 8.0, 10.0}};
constexpr std::array<int, 5> kStage03Type2EIntervalA{{24, 20, 18, 18, 16}};
constexpr std::array<int, 5> kStage03Type2ERepeatA{{3, 3, 4, 6, 6}};
constexpr std::array<int, 5> kStage03Type2ECountA{{1, 3, 4, 4, 5}};
constexpr std::array<double, 5> kStage03Type2ESpeedA{{3.5, 4.5, 5.0, 5.0, 6.0}};
constexpr std::array<int, 5> kStage03Type2EIntervalB{{70, 48, 38, 32, 28}};
constexpr std::array<int, 5> kStage03Type2ESpreadStepB{{6000, 4000, 3200, 2800, 2600}};
constexpr std::array<double, 5> kStage03Type2ESpeedB{{3.5, 4.5, 5.0, 5.0, 6.5}};
constexpr std::array<int, 5> kStage03Type2FCount{{1, 3, 5, 5, 5}};
constexpr std::array<double, 5> kStage03Type2FSpeed{{3.5, 4.5, 5.0, 5.0, 6.5}};
constexpr std::array<int, 5> kStage04Type35Interval{{42, 16, 10, 10, 8}};
constexpr std::array<double, 5> kStage04Type35Speed{{5.0, 6.0, 7.0, 7.0, 9.0}};
constexpr std::array<int, 5> kStage04Type36Interval{{60, 40, 30, 24, 16}};
constexpr std::array<double, 5> kStage04Type36Speed{{4.0, 5.2, 6.5, 7.5, 9.0}};
constexpr std::array<int, 5> kStage04Type37Interval{{100, 60, 50, 40, 32}};
constexpr std::array<int, 5> kStage04Type37Substep{{10, 7, 5, 4, 4}};
constexpr std::array<int, 5> kStage04Type37Jitter{{600, 800, 1000, 1200, 1400}};
constexpr std::array<double, 5> kStage04Type37Speed{{4.2, 5.2, 6.0, 6.0, 7.5}};
constexpr std::array<int, 5> kStage04Type38FirstWindow{{16, 24, 28, 32, 36}};
constexpr std::array<int, 5> kStage04Type38WideCount{{3, 5, 7, 7, 9}};
constexpr std::array<int, 5> kStage04Type38SpreadUnit{{320, 320, 350, 450, 600}};
constexpr std::array<double, 5> kStage04Type38Speed{{6.0, 7.0, 7.5, 10.0, 11.0}};
constexpr std::array<int, 5> kStage04CarrierInterval{{100, 70, 60, 60, 40}};
constexpr std::array<int, 5> kStage04CarrierCount{{5, 7, 9, 7, 9}};
constexpr std::array<int, 5> kStage04CarrierChildInterval{{88, 55, 47, 41, 31}};
constexpr std::array<double, 5> kStage04CarrierChildSpeed{{4.5, 5.0, 5.5, 6.0, 7.7}};
constexpr std::array<int, 5> kStage04Type3DHalfCycle{{100, 80, 50, 60, 50}};
constexpr std::array<double, 5> kStage04Type3DSpeed{{3.2, 3.6, 4.0, 5.0, 6.5}};
constexpr std::array<int, 5> kStage04Type3DCount{{5, 7, 9, 9, 9}};
constexpr std::array<int, 5> kStage04Type3EInterval{{95, 60, 45, 38, 27}};
constexpr std::array<double, 5> kStage04Type3ESpeed{{4.6, 5.5, 6.0, 5.5, 7.0}};
constexpr std::array<int, 5> kStage04Type3FAlternatingHalfCycle{{70, 55, 45, 40, 40}};
constexpr std::array<int, 5> kStage04Type3FAlternatingWindow{{12, 16, 20, 20, 20}};
constexpr std::array<double, 5> kStage04Type3FAlternatingSpeed{{4.5, 5.5, 6.0, 7.5, 9.5}};
constexpr std::array<int, 5> kStage04Type3FJitterInterval{{16, 10, 8, 7, 5}};
constexpr std::array<double, 5> kStage04Type3FJitterSpeed{{3.0, 4.0, 4.5, 4.5, 6.0}};
constexpr std::array<int, 5> kStage04Type3FFanInterval{{100, 70, 60, 50, 25}};
constexpr std::array<int, 5> kStage04Type3FFanCount{{7, 9, 11, 13, 15}};
constexpr std::array<double, 5> kStage04Type3FFanSpeed{{3.5, 4.5, 5.0, 5.0, 6.0}};
struct StageBannerSpec {
    int stage;
    int textIdBase;
    int iconIndex;
    int startFrame;
    int endFrame;
    int mode;
    bool addSetupGroupToTextId;
};

// iconIndex -1 selects the current setup group. Stages 1-9 call
// FUN_14012e8e0 for their opening and FUN_140001060 for the final approach;
// Stage 10 uses the latter at frame 50. Stage 9 owns the 0xb7/0xb8 special
// branch, while Stage 7 owns the additional mode-2 speaker at y=160.
constexpr std::array<StageBannerSpec, 30> kStageBanners{{
    {1, 100, -1, 50, 230, 0, true},
    {2, 110, -1, 50, 230, 0, true},
    {3, 120, -1, 50, 230, 0, true},
    {4, 130, -1, 50, 230, 0, true},
    {5, 140, -1, 50, 230, 0, true},
    {6, 150, -1, 50, 230, 0, true},
    {7, 160, -1, 50, 230, 0, true},
    {8, 170, -1, 50, 230, 0, true},
    {9, 180, -1, 50, 230, 0, true},

    {1, 103, 4, 5400, 5560, 1, true},
    {1, 106, -1, 5540, 5700, 0, true},
    {2, 113, 5, 9400, 9560, 1, true},
    {2, 116, -1, 9540, 9700, 0, true},
    {3, 123, 6, 9200, 9360, 1, true},
    {3, 126, -1, 9340, 9500, 0, true},
    {4, 133, 7, 11400, 11560, 1, true},
    {4, 136, -1, 11540, 11700, 0, true},
    {5, 143, 8, 11500, 11660, 1, true},
    {5, 146, -1, 11640, 11800, 0, true},
    {6, 153, 9, 12200, 12360, 1, true},
    {6, 156, -1, 12340, 12500, 0, true},
    {7, 163, 10, 12200, 12360, 1, true},
    {7, 200, 15, 12200, 12360, 2, true},
    {7, 166, -1, 12340, 12500, 0, true},
    {8, 173, 11, 21120, 21280, 1, true},
    {8, 176, -1, 21260, 21420, 0, true},
    {9, 0xb7, 0x0c, 17600, 17760, 1, false},
    {9, 0xb8, 0x0c, 17740, 17900, 1, false},
    {10, 193, 13, 50, 210, 1, true},
    {10, 196, -1, 190, 350, 0, true},
}};

int stageBannerTextId(const StageBannerSpec& banner, int setupGroup,
                      bool specialStage) {
    int base = banner.textIdBase;
    if (banner.stage == 1 && banner.startFrame == 50 && specialStage) {
        base = 0x127;
    }
    return base + (banner.addSetupGroupToTextId ? setupGroup : 0);
}
constexpr double kStageTextBobStep = 0.08849556770675474;
constexpr float kPlayLeft = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.x);
constexpr float kPlayRight = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.right());
constexpr float kPlayTop = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.y);
constexpr float kPlayBottom = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.bottom());

float screenY(float localY) {
    return localY + static_cast<float>(notes::gameplay_layout::kPlayScreenOrigin.y);
}

float projectileHorizontalOrigin(float playerX) {
    // The original projectile helpers derive their horizontal bounds from
    // DAT_140e445d8 / 6 rather than from the fixed player movement rectangle.
    return playerX / 6.0f;
}

std::size_t utf8CodePointLength(std::string_view text, std::size_t offset) {
    const auto lead = static_cast<unsigned char>(text[offset]);
    std::size_t length = 1;
    if ((lead & 0xe0u) == 0xc0u) {
        length = 2;
    }
    else if ((lead & 0xf0u) == 0xe0u) {
        length = 3;
    }
    else if ((lead & 0xf8u) == 0xf0u) {
        length = 4;
    }
    if (offset + length > text.size()) {
        return 1;
    }
    for (std::size_t i = 1; i < length; ++i) {
        if ((static_cast<unsigned char>(text[offset + i]) & 0xc0u) != 0x80u) {
            return 1;
        }
    }
    return length;
}

int utf8CodePointCount(std::string_view text) {
    int count = 0;
    for (std::size_t offset = 0; offset < text.size(); ++count) {
        offset += utf8CodePointLength(text, offset);
    }
    return count;
}

// Hand-transcribed Stage 01 slice from stage-spawn-schedule.csv. Rows that used
// DAT_140e9fd1c modulo expressions in the decompile are represented by stable
// deterministic coordinates here; this is a runnable reconstruction probe, not
// an exact recovered script interpreter.
constexpr std::array<StageRuntime::StageSpawnEvent, 25> kStage01Events{{
    {200, 0x0a, 0x960, 0x1e0, 0x96, "S01 row 1: type 0x0a fixed early entry"},
    {260, 0x0a, 2000, 0x0f0, 200, "S01 row 2: type 0x0a fixed follow-up"},
    {350, 0x0a, 2000, 0x208, 100, "S01 row 3: type 0x0a fixed lane"},
    {365, 0x0a, 2000, 0x168, 100, "S01 row 4: type 0x0a fixed lane"},
    {380, 0x0a, 2000, 200, 100, "S01 row 5: type 0x0a fixed lane"},
    {400, 0x0b, 400, 0x140, -20, "S01 row 6: type 0x0b top random entry"},
    {420, 0x0b, 400, 0x240, -20, "S01 row 6 repeat: type 0x0b top random entry"},
    {700, 0x06, 5000, 0x1cc, 0, "S01 row 7: common marker/emitter"},
    {900, 0x0e, 10000, 0x118, 0, "S01 row 8: long-lived common setpiece"},
    {1100, 0x0e, 10000, 0x1cc, 0, "S01 row 9: long-lived common setpiece"},
    {1180, 0x0c, 400, 0x1a0, -20, "S01 row 10: type 0x0c top entry"},
    {1270, 0x0d, 700, 740, 290, "S01 row 11: type 0x0d right edge entry"},
    {1380, 0x0b, 500, -20, 180, "S01 row 12: type 0x0b left edge entry"},
    {1460, 0x0b, 500, 740, 220, "S01 row 13: type 0x0b right edge entry"},
    {2200, 0x0f, 8000, 0x348, 0x96, "S01 row 14: type 0x0f side setpiece"},
    {2500, 0x0d, 700, -20, 290, "S01 row 15: type 0x0d left entry burst"},
    {2650, 0x0b, 400, 0x260, -20, "S01 row 16: type 0x0b top burst"},
    {2780, 0x10, 40000, 0x168, 0x50, "S01 row 17: type 0x10 long setpiece"},
    {3600, 0x0c, 400, 0x180, -20, "S01 row 18: later type 0x0c top entry"},
    {3600, 0x0e, 7000, 0x1cc, 0, "S01 row 19: later type 0x0e setpiece"},
    {3820, 0x0b, 500, 740, 240, "S01 row 20: later type 0x0b side entry"},
    {4200, 0x0d, 500, -20, 300, "S01 row 21: later type 0x0d left/top entry"},
    {4200, 0x0e, 7000, 0x1cc, 0, "S01 row 22: later type 0x0e setpiece"},
    {4360, 0x0f, 8000, -120, 100, "S01 row 23: later type 0x0f side setpiece"},
    {5100, 0x08, 5000, 0x104, 0, "S01 row 27: common marker/emitter"},
}};

// Literal Stage 02 route points copied by stage_02_gameplay_update_candidate
// from .rdata. Each pair is converted from float to int immediately before the
// original spawn dispatcher call, and every recovered value is integral.
constexpr std::array<std::array<int, 2>, 19> kStage02EarlyType1DPath{{
    {{510, -135}}, {{605, -212}}, {{385, -220}}, {{265, -445}},
    {{130, -475}}, {{220, -545}}, {{530, -580}}, {{610, -685}},
    {{465, -695}}, {{260, -2805}}, {{100, -2840}}, {{365, -2880}},
    {{220, -2930}}, {{345, -3000}}, {{140, -3040}}, {{350, -3390}},
    {{590, -3390}}, {{350, -3660}}, {{615, -3660}},
}};

constexpr std::array<std::array<int, 2>, 6> kStage02EarlyType1EPath{{
    {{485, -305}}, {{175, -310}}, {{345, -410}},
    {{165, -630}}, {{444, -795}}, {{620, -795}},
}};

constexpr std::array<std::array<int, 2>, 17> kStage02LateType1DPath{{
    {{95, -210}}, {{230, -185}}, {{390, -195}}, {{535, -240}},
    {{650, -330}}, {{222, -595}}, {{477, -660}}, {{80, -760}},
    {{420, -790}}, {{430, -1245}}, {{320, -1655}}, {{565, -1245}},
    {{356, -1320}}, {{630, -1320}}, {{200, -1625}}, {{100, -1685}},
    {{380, -1740}},
}};

constexpr std::array<std::array<int, 2>, 5> kStage02LateType1EPath{{
    {{360, -590}}, {{110, -620}}, {{540, -760}},
    {{110, -895}}, {{420, -895}},
}};

// Literal Stage 03 route points copied from the local stack arrays assembled by
// stage_03_gameplay_update_candidate @ 0x14011b3d0. The source converts each
// float pair to int immediately before dispatching spawn type 0x2c.
constexpr std::array<std::array<int, 2>, 7> kStage03EarlyType2CPath{{
    {{385, -190}}, {{600, -190}}, {{490, -280}}, {{350, -390}},
    {{630, -390}}, {{350, -630}}, {{630, -630}},
}};

constexpr std::array<std::array<int, 2>, 6> kStage03MiddleType2CPath{{
    {{70, -155}}, {{350, -155}}, {{95, -345}},
    {{330, -345}}, {{95, -495}}, {{145, -660}},
}};

constexpr std::array<std::array<int, 2>, 11> kStage03LateType2CPath{{
    {{100, -155}}, {{235, -155}}, {{490, -155}}, {{635, -155}},
    {{550, -280}}, {{620, -400}}, {{485, -440}}, {{65, -470}},
    {{190, -530}}, {{130, -635}}, {{240, -635}},
}};

// First-pass Stage 04 slice: sparse anchors from the Stage 04 schedule and
// reviewed helper notes. This gives the runtime a body-after-marker type (0x35),
// drifting emitter (0x37), heavy multipart source (0x38), child-carrier pair
// (0x39/0x3a), anchor spread emitter (0x3d), and boss-like controller (0x3f).
constexpr std::array<StageRuntime::StageSpawnEvent, 24> kStage04Events{{
    {0, 0x37, 500, 0x1c0, 420, "S04 row 1: type 0x37 random drifting emitter"},
    {80, 0x35, 0xfa, 0x2e4, 0x96, "S04 row 2: type 0x35 right-entry tri-afterimage"},
    {180, 0x38, 5000, 0x1e0, 0, "S04 row 3: type 0x38 long multipart source"},
    {260, 0x35, 0xfa, -20, 0x96, "S04 row 4: type 0x35 left-entry tri-afterimage"},
    {400, 0x38, 5000, 0xf0, 0, "S04 row 5: type 0x38 long multipart source"},
    {700, 0x07, 5000, 0x1cc, 0, "S04 row 9: common marker/emitter"},
    {820, 0x3d, 9000, -200, 0x96, "S04 row 10: type 0x3d three-anchor spread emitter"},
    {980, 0x36, 400, -20, 300, "S04 row 11: type 0x36 side curving spread emitter"},
    {1100, 0x36, 400, 740, 300, "S04 row 12: type 0x36 mirrored side curving spread emitter"},
    {1280, 0x38, 4000, 500, 0, "S04 row 13: type 0x38 fixed heavy source"},
    {1380, 0x38, 4000, 0xdc, 0, "S04 row 14: type 0x38 fixed heavy source"},
    {1540, 0x3d, 7000, 0x398, 0x96, "S04 row 15: type 0x3d right anchor emitter"},
    {1780, 0x39, 8000, 0x262, -80, "S04 row 20: type 0x39 directional child carrier"},
    {1900, 0x39, 8000, 0x6e, -80, "S04 row 21: type 0x39 directional child carrier"},
    {2050, 0x3a, 8000, 800, 200, "S04 row 22: type 0x3a mirrored child carrier"},
    {2300, 0x0b, 400, 0x210, -20, "S04 row 23: reused common top burst"},
    {2500, 0x36, 400, -20, 360, "S04 row 25: type 0x36 late left burst"},
    {2600, 0x36, 400, 740, 360, "S04 row 26: type 0x36 late right burst"},
    {3600, 0x3f, 48000, 0x167, 0, "S04 row 27: boss-like multipart pattern controller"},
    {4500, 0x35, 200, 0x2e4, 0x8c, "S04 row 28: fast right tri-afterimage pair"},
    {4500, 0x35, 200, -20, 0x8c, "S04 row 29: fast left tri-afterimage pair"},
    {4700, 0x3d, 9000, -200, 0x96, "S04 row 30: type 0x3d anchor refresh"},
    {5480, 0x37, 500, 0x220, 430, "S04 row 32: late type 0x37 drifting wave"},
    {5600, 0x38, 6000, 0x1cc, 0, "S04 row 33: late heavy source"},
}};

float clampFloat(float value, float low, float high) {
    return std::max(low, std::min(value, high));
}

float sineEaseIn(int frame, int duration, float maximum) {
    if (duration <= 0) {
        return maximum;
    }
    const float t = clampFloat(static_cast<float>(frame) / static_cast<float>(duration), 0.0f, 1.0f);
    return std::sin(t * kPi * 0.5f) * maximum;
}

float sineEaseOut(int frame, int duration, float maximum) {
    if (duration <= 0) {
        return 0.0f;
    }
    const float t = clampFloat(static_cast<float>(frame) / static_cast<float>(duration), 0.0f, 1.0f);
    return std::cos(t * kPi * 0.5f) * maximum;
}

int rootFlashAlpha(int age, int lifetime, int maximum = 192) {
    if (age < 0 || age >= lifetime) {
        return 0;
    }
    if (age < 32) {
        return static_cast<int>(sineEaseIn(age, 32, static_cast<float>(maximum)));
    }
    if (age >= lifetime - 16) {
        return static_cast<int>(sineEaseOut(age - (lifetime - 16), 16, static_cast<float>(maximum)));
    }
    return maximum;
}

float distanceSquared(float ax, float ay, float bx, float by) {
    const float dx = ax - bx;
    const float dy = ay - by;
    return dx * dx + dy * dy;
}

bool stageUsesMediumFrame(int spawnType) {
    return (spawnType >= 0x06 && spawnType <= 0x0a) ||
           (spawnType >= 0x0e && spawnType <= 0x11) ||
           (spawnType >= 0x1b && spawnType <= 0x20) ||
           spawnType == 0x26 || spawnType == 0x27 || spawnType == 0x28 ||
           spawnType == 0x29 || spawnType == 0x2a || spawnType == 0x2d || spawnType == 0x2f ||
           (spawnType >= 0x138 && spawnType <= 0x13b) ||
           (spawnType >= 0x38 && spawnType <= 0x3f);
}

bool isStage03FocusedType(int spawnType) {
    return spawnType >= 0x25 && spawnType <= 0x2f;
}

bool isStage03BossChildType(int spawnType) {
    return spawnType >= 0x30 && spawnType <= 0x34;
}

bool isStage03BossNodeType(int spawnType) {
    return spawnType == 0x13a || isStage03BossChildType(spawnType);
}

bool isStage04FocusedType(int spawnType) {
    return spawnType == 0x35 || spawnType == 0x36 || spawnType == 0x37 ||
           spawnType == 0x38 || (spawnType >= 0x39 && spawnType <= 0x3c) ||
           spawnType == 0x3d || spawnType == 0x3e || spawnType == 0x3f;
}

bool isStage04CarrierFamily(int spawnType) {
    return spawnType >= 0x39 && spawnType <= 0x3c;
}

bool isStage01ObservedType(int spawnType) {
    return (spawnType >= 0x06 && spawnType <= 0x0a) ||
           spawnType == 0x0b || spawnType == 0x0c || spawnType == 0x0d ||
           spawnType == 0x0e || spawnType == 0x0f || spawnType == 0x10 ||
           spawnType == 0x11 || (spawnType >= 0x15 && spawnType <= 0x17) ||
           spawnType == 0x138;
}

bool isStage01BossChildType(int spawnType) {
    return spawnType >= 0x15 && spawnType <= 0x17;
}

bool isStage01BossDecorationType(int spawnType) {
    return spawnType >= 0x12 && spawnType <= 0x14;
}

int stage01UpdateCaseForSpawnType(int spawnType) {
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        return 0x2;
    case 0x09:
        return 0x3;
    case 0x0a:
        return 0x4;
    case 0x0b:
        return 0x5;
    case 0x0c:
        return 0x6;
    case 0x0d:
        return 0x7;
    case 0x0e:
        return 0x8;
    case 0x0f:
        return 0x9;
    case 0x10:
        return 0x0a;
    case 0x11:
        return 0x0b;
    case 0x138:
        return 0x9f;
    default:
        return -1;
    }
}

int stage01DispatchKindForSpawnType(int spawnType) {
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x0f:
        return 30;
    case 0x09:
        return 0;
    case 0x0a:
        return 10;
    case 0x0b:
    case 0x0d:
        return 5;
    case 0x0c:
        return 7;
    case 0x0e:
        return 24;
    case 0x10:
        return 120;
    case 0x11:
        return 1;
    case 0x138:
        return 120;
    default:
        return -1;
    }
}

int stage01DispatchFieldForSpawnType(int spawnType) {
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        return 90;
    case 0x09:
        return 0x28;
    case 0x0a:
        return 50;
    case 0x0b:
    case 0x0c:
    case 0x0d:
        return 30;
    case 0x0e:
        return 80;
    case 0x10:
        return 150;
    case 0x11:
        return 0;
    case 0x138:
        return 0xa0;
    default:
        return 0;
    }
}

int stage01DeathRewardWindow(int spawnType) {
    // Second argument passed to FUN_14007b010 by each Stage 1 helper. The
    // helper reads entity_kind (+0x24) from the node for the actual payout
    // weight; stage01DispatchKindForSpawnType() reconstructs that field.
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08: return 500;
    case 0x0a: return 400;
    case 0x0b: return 300;
    case 0x0c: return 0x168;
    case 0x0d: return 0x1e0;
    case 0x0e:
    case 0x0f: return 500;
    case 0x10: return 0x708;
    case 0x11: return 0x4b0;
    default: return 0;
    }
}

std::uint32_t stageScriptRandFromFrame(int frame) {
    // Matches the repeated DAT_140e9fd1c computation in
    // stage_01_gameplay_update_candidate @ 0x140118420. This is not the
    // generic runtime RNG; it is the frame-seeded expression embedded in the
    // stage schedule blocks.
    const auto seed = static_cast<std::uint32_t>(frame);
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return ((c >> 11) ^ mixed) >> 8 ^ c ^ mixed;
}

double scriptRandomHundredth(std::uint32_t seed, double minimum, double maximum) {
    const int minimum100 = static_cast<int>(minimum * 100.0);
    const int maximum100 = static_cast<int>(maximum * 100.0);
    if (minimum100 == maximum100) {
        return minimum;
    }
    const auto random = stageScriptRandFromFrame(static_cast<int>(seed));
    return static_cast<double>(minimum100 +
                               random % static_cast<std::uint32_t>(maximum100 - minimum100 + 1)) /
           100.0;
}

int stageRandCoord(int frame, int modulus, int base) {
    return static_cast<int>(stageScriptRandFromFrame(frame) % static_cast<std::uint32_t>(modulus)) + base;
}

int stageRandomIntInclusive(std::uint32_t seed, int minimum, int maximum) {
    if (minimum == maximum) {
        return minimum;
    }
    return minimum + static_cast<int>(
                         stageScriptRandFromFrame(static_cast<int>(seed)) %
                         static_cast<std::uint32_t>(maximum - minimum + 1));
}

std::uint16_t scriptRandomAngle(std::uint32_t seed) {
    const std::uint32_t random = stageScriptRandFromFrame(static_cast<int>(seed));
    return static_cast<std::uint16_t>(random - random / 0x10001u);
}

std::uint16_t scriptRandomUpperHalfAngle(std::uint32_t seed) {
    const std::uint32_t random = stageScriptRandFromFrame(static_cast<int>(seed));
    return static_cast<std::uint16_t>(
        random + random / 0x8001u * 0x7fffu - 0x8000u);
}

std::uint16_t cancelRewardAngle(int frame, std::size_t projectileIndex) {
    const std::uint32_t seed = static_cast<std::uint32_t>(frame) +
                               static_cast<std::uint32_t>(projectileIndex) + 1u;
    return scriptRandomAngle(seed);
}

int bulletFrameForVisualSelector(int visualSelector) {
    switch (visualSelector) {
    case 0x00: return 0;
    case 0x01: return 1;
    case 0x02: return 2;
    case 0x03: return 3;
    case 0x04: return 4;
    case 0x05: return 5;
    case 0x06: return 6;
    case 0x07: return 7;
    case 0x08: return 8;
    case 0x09: return 9;
    case 0x0a: return 20;
    case 0x0b: return 21;
    case 0x0c: return 22;
    case 0x0d: return 23;
    case 0x0e: return 24;
    case 0x0f: return 25;
    case 0x10: return 26;
    case 0x11: return 4;
    case 0x12: return 5;
    case 0x13: return 5;
    case 0x14: return 4;
    default: return 0;
    }
}

double projectileScaleA(int age) {
    constexpr double kOriginalPi = 3.14159265358979;
    return 1.1 + std::sin(static_cast<double>(age) * 2.0 * kOriginalPi / 11.0) * 0.1;
}

double projectileScaleB(int age) {
    constexpr double kOriginalPi = 3.14159265358979;
    return 1.1 + std::sin(static_cast<double>(age - 6) * 2.0 * kOriginalPi / 11.0) * 0.2;
}

std::array<double, 2> projectileScaleForVisualSelector(int visualSelector, int age) {
    const double scaleA = projectileScaleA(age);
    const double scaleB = projectileScaleB(age);
    switch (visualSelector) {
    case 0x00:
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x0e:
    case 0x0f:
        return {scaleA, scaleA};
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x10:
        return {1.0f, scaleB};
    case 0x0a:
    case 0x0b:
    case 0x0c:
    case 0x0d:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
        return {scaleA, scaleB};
    default:
        // FUN_140070250 initializes the default frame to Bullet[0] and keeps
        // both age pulses when the selector is outside its explicit table.
        return {scaleA, scaleB};
    }
}

int projectileAgeSpinStepForVisualSelector(int visualSelector) {
    switch (visualSelector) {
    case 0x00:
    case 0x01:
        return 2000;
    case 0x02:
    case 0x03:
    case 0x0e:
    case 0x0f:
        return 999;
    case 0x04:
    case 0x05:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
        return 0x682;
    default:
        return 0;
    }
}

std::uint16_t normalizeAngle16(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

float fixedAngleToRadians(std::uint16_t angle) {
    return static_cast<float>(angle) * kTau / static_cast<float>(kFixedAngleFullCircle);
}

double fixedAngleToRadiansDouble(std::uint16_t angle) {
    constexpr double kPiDouble = 3.14159265358979;
    return static_cast<double>(angle) * kPiDouble / 32768.0;
}

std::uint16_t radiansToFixedAngle(float radians) {
    const int angle = static_cast<int>(std::lround(radians * static_cast<float>(kFixedAngleFullCircle) / kTau));
    return normalizeAngle16(angle);
}

std::uint16_t radiansToFixedAngleTrunc(double radians) {
    constexpr double kFixedAnglePerRadian = 10430.378350470464;
    return normalizeAngle16(static_cast<int>(radians * kFixedAnglePerRadian));
}

std::uint16_t projectileDrawAngleForVisualSelector(int visualSelector, int age,
                                                   std::uint16_t angle16) {
    // FUN_140070250 is selector-driven: some visuals preserve projectile angle,
    // while pellets/orbs/beads/diamonds overwrite it with age-based spin.
    const int ageSpinStep = projectileAgeSpinStepForVisualSelector(visualSelector);
    if (ageSpinStep != 0) {
        return normalizeAngle16(age * ageSpinStep);
    }
    return angle16;
}

std::uint16_t approachAngle16(std::uint16_t current, std::uint16_t target, int maxStep) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    delta = std::max(-maxStep, std::min(maxStep, delta));
    return normalizeAngle16(static_cast<int>(current) + delta);
}

int stage01Type0AShotStartFrame(int difficulty) {
    switch (difficulty) {
    case 0: return 0x14;
    case 1: return 10;
    default: return 0;
    }
}

int stage01Type0AShotInterval(int difficulty, int stage) {
    if (stage > 7) {
        switch (difficulty) {
        case 0: return 0x78;
        case 1: return 0x5a;
        case 2: return 0x32;
        case 3: return 0x28;
        case 4: return 0x20;
        default: return 1;
        }
    }
    switch (difficulty) {
    case 0: return 0x96;
    case 1: return 0x78;
    case 2: return 0x3c;
    case 3: return 0x28;
    case 4: return 0x20;
    default: return 1;
    }
}

float stage01SpeedConstantValue(int globalOffset) {
    switch (globalOffset) {
    case 0x018: return 3.0f;
    case 0x040: return 3.5f;
    case 0x070: return 4.0f;
    case 0x088: return 4.5f;
    case 0x0a0: return 4.8f;
    case 0x0b0: return 5.0f;
    case 0x0d0: return 5.5f;
    case 0x0f8: return 6.0f;
    case 0x118: return 6.5f;
    case 0x138: return 7.0f;
    case 0x158: return 7.5f;
    case 0x178: return 8.0f;
    case 0x190: return 8.5f;
    case 0x1b8: return 9.0f;
    case 0x1c8: return 9.5f;
    case 0x208: return 11.0f;
    default: return 4.0f;
    }
}

float stage01Type0AProjectileSpeed(int difficulty, int stage) {
    // FUN_14007c9c0 selects decoded DAT_14053a* constants by difficulty.
    if (stage > 7) {
        switch (difficulty) {
        case 0: return stage01SpeedConstantValue(0x0b0);
        case 1: return stage01SpeedConstantValue(0x0f8);
        case 2: return stage01SpeedConstantValue(0x118);
        case 3: return stage01SpeedConstantValue(0x138);
        case 4: return stage01SpeedConstantValue(0x178);
        default: return stage01SpeedConstantValue(0x0f8);
        }
    }
    switch (difficulty) {
    case 0: return stage01SpeedConstantValue(0x070);
    case 1: return stage01SpeedConstantValue(0x0b0);
    case 2: return stage01SpeedConstantValue(0x118);
    case 3: return stage01SpeedConstantValue(0x138);
    case 4: return stage01SpeedConstantValue(0x178);
    default: return stage01SpeedConstantValue(0x0b0);
    }
}

int stage01Type0BShotStartFrame(int difficulty) {
    switch (difficulty) {
    case 0: return 0x1e;
    case 1: return 0x10;
    case 2: return 0x0c;
    case 3: return 8;
    case 4: return 6;
    default: return 1;
    }
}

int stage01Type0BShotInterval(int difficulty, int stage) {
    if (stage > 3) {
        switch (difficulty) {
        case 0: return 0x18;
        case 1: return 0x14;
        case 2: return 0x10;
        case 3: return 0x0c;
        case 4: return 6;
        default: return 1;
        }
    }
    switch (difficulty) {
    case 0: return 0x20;
    case 1: return 0x1b;
    case 2: return 0x14;
    case 3: return 0x0f;
    case 4: return 6;
    default: return 1;
    }
}

int stage01Type0CShotStartFrame(int difficulty, int stage) {
    if (stage > 3) {
        switch (difficulty) {
        case 0: return 0x14;
        case 1: return 0x0c;
        default: return 10;
        }
    }
    switch (difficulty) {
    case 0: return 0x1e;
    case 1: return 0x14;
    case 2: return 0x0c;
    default: return 10;
    }
}

int stage01Type0CShotInterval(int difficulty, int stage) {
    if (stage > 3) {
        switch (difficulty) {
        case 0: return 0x78;
        case 1: return 0x50;
        case 2:
        case 3: return 0x3c;
        case 4: return 0x32;
        default: return 1;
        }
    }
    switch (difficulty) {
    case 0: return 0x8c;
    case 1: return 100;
    case 2:
    case 3: return 0x50;
    case 4: return 0x3c;
    default: return 1;
    }
}

int stage01Type0DShotInterval(int difficulty, int stage) {
    if (stage > 3) {
        switch (difficulty) {
        case 0: return 0x2c;
        case 1: return 0x1f;
        case 2: return 0x11;
        case 3: return 0x0c;
        case 4: return 7;
        default: return 1;
        }
    }
    switch (difficulty) {
    case 0: return 0x3c;
    case 1: return 0x2c;
    case 2: return 0x18;
    case 3: return 0x0f;
    case 4: return 7;
    default: return 1;
    }
}

float stage01DecodedSpeedForOffsets(int difficulty, int stage, const std::array<int, 5>& normal, const std::array<int, 5>& later) {
    const auto& table = stage > 3 ? later : normal;
    return stage01SpeedConstantValue(table[static_cast<std::size_t>(std::clamp(difficulty, 0, 4))]);
}

float stage01Type0BProjectileSpeed(int difficulty, int stage) {
    return stage01DecodedSpeedForOffsets(difficulty, stage, {0x088, 0x0d0, 0x118, 0x118, 0x190}, {0x088, 0x0d0, 0x118, 0x118, 0x190});
}

float stage01Type0CProjectileSpeed(int difficulty, int stage) {
    return stage01DecodedSpeedForOffsets(difficulty, stage, {0x0a0, 0x118, 0x178, 0x178, 0x1c8}, {0x0f8, 0x138, 0x178, 0x178, 0x1c8});
}

float stage01Type0DProjectileSpeed(int difficulty, int stage) {
    return stage01DecodedSpeedForOffsets(difficulty, stage, {0x018, 0x070, 0x088, 0x0d0, 0x158}, {0x070, 0x088, 0x0b0, 0x0f8, 0x158});
}

float stage01MarkerProjectileSpeed(int difficulty) {
    switch (difficulty) {
    case 0: return stage01SpeedConstantValue(0x070);
    case 1: return stage01SpeedConstantValue(0x0f8);
    case 2: return stage01SpeedConstantValue(0x178);
    case 3: return stage01SpeedConstantValue(0x1c8);
    case 4: return stage01SpeedConstantValue(0x208);
    default: return stage01SpeedConstantValue(0x0f8);
    }
}

int controlDeviceForPadType(int padType) {
    // main dispatcher 0x1400f5ef0 maps DxLib pad types to prompt families.
    if (padType == 1 || padType == 2) {
        return 2;
    }
    if (padType == 4 || padType == 5) {
        return 4;
    }
    if (padType == 8) {
        return 3;
    }
    return 0;
}

bool defersEnemyDeathEffects(int spawnType) {
    return spawnType == 0x10 || spawnType == 0x1f || spawnType == 0x20 || spawnType == 0x2b ||
           spawnType == 0x2e || spawnType == 0x30 || spawnType == 0x3f || spawnType == 0x40 ||
           (spawnType >= 0x116 && spawnType <= 0x119);
}

int immediateEnemyDeathEffectMode(int spawnType) {
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x0e:
    case 0x0f:
    case 0x11:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1b:
    case 0x1c:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x26:
    case 0x27:
    case 0x29:
    case 0x2d:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3d:
        return 1;
    default:
        return 0;
    }
}

int enemyDeathFeedbackStrength(int spawnType, int radius) {
    switch (spawnType) {
    case 0x06:
    case 0x07:
    case 0x08: return 12;
    case 0x0a: return 5;
    case 0x0b:
    case 0x0c:
    case 0x0d: return 3;
    case 0x0e:
    case 0x0f: return 8;
    case 0x10: return 30;
    case 0x11: return 10;
    case 0x15:
    case 0x16:
    case 0x17: return 8;
    case 0x19:
    case 0x1a: return 3;
    case 0x1b:
    case 0x1c: return 8;
    case 0x1d:
    case 0x1e: return 5;
    case 0x1f: return 12;
    case 0x20: return 30;
    case 0x21: return 9;
    case 0x25: return 4;
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29: return 8;
    case 0x2b: return 16;
    case 0x2c: return 5;
    case 0x2d: return 10;
    case 0x2e: return 30;
    case 0x30: return 8;
    case 0x32:
    case 0x33: return 1;
    case 0x34: return 5;
    case 0x35: return 2;
    case 0x36:
    case 0x37: return 3;
    case 0x38: return 8;
    case 0x39:
    case 0x3a: return 10;
    case 0x3b:
    case 0x3c: return 1;
    case 0x3d: return 8;
    case 0x3f: return 30;
    case 0x40: return 8;
    default: return std::max(1, radius / 10);
    }
}

} // namespace

const StageRuntime::StageSpawnEvent* StageRuntime::eventsForStage(int stage, std::size_t& count) {
    if (stage == 4) {
        count = kStage04Events.size();
        return kStage04Events.data();
    }
    if (stage == 1) {
        count = kStage01Events.size();
        return kStage01Events.data();
    }
    count = 0;
    return nullptr;
}

float StageRuntime::screenX(float localX) const {
    // FUN_1400bca30 updates DAT_140e45d30 every gameplay frame. Mode-7/8/10
    // nodes use this camera offset, keeping the dynamic world rectangle fixed
    // at screen x=340..940 as the player moves through its logical bounds.
    const float cameraX = 340.0f - player_.x / 6.0f;
    return cameraX + localX;
}

bool StageRuntime::initialize(ResourceManager& resources, int stage) {
    StageRuntimeConfig config;
    config.stage = stage;
    return initialize(resources, config);
}

bool StageRuntime::initialize(ResourceManager& resources, const StageRuntimeConfig& config) {
    playerFrames_ = resources.loadDivGraph("media\\player\\Player.png", 0x78, 0xf, 8, 0x50, 0x50);
    itemFrames_ = resources.loadDivGraph("media\\player\\Item.png", 0x0f, 0x0f, 1, 100, 100);
    enemySmallFrames_ = resources.loadDivGraph("media\\stage\\Enemy_s.png", 0xaa, 10, 0x11, 100, 100);
    enemyMediumFrames_ = resources.loadDivGraph("media\\stage\\Enemy_m.png", 0xe6, 10, 0x17, 200, 200);
    enemyLargeFrames_ = resources.loadDivGraph("media\\stage\\Enemy_l.png", 0x6e, 10, 0x0b, 600, 600);
    enemyExtraLargeFrames_ = resources.loadDivGraph("media\\stage\\Enemy_xl.png", 8, 4, 2, 800, 800);
    effectSmallFrames_ = resources.loadDivGraph("media\\effect\\Effect_s.png", 0x14, 10, 2, 100, 100);
    effectMediumFrames_ = resources.loadDivGraph("media\\effect\\Effect_m.png", 0x1e, 10, 3, 200, 200);
    effectLargeFrames_ = resources.loadDivGraph("media\\effect\\Effect_l.png", 0x1e, 10, 3, 600, 600);
    enemyGaugeFrames_ = resources.loadDivGraph("media\\stage\\EnemyGauge1.png", 3, 1, 3, 0xf6, 0x10);
    enemyGaugeFillHandle_ = resources.loadGraph("media\\stage\\EnemyGauge2.png");
    bossFrames_ = resources.loadDivGraph("media\\stage\\Boss.png", 0xa0, 10, 0x10, 200, 200);
    bossApproach1Frames_ = resources.loadDivGraph(
        "media\\stage\\BossApproach1.png", 0x0e, 1, 0x0e, 400, 100);
    bossApproach1Ch1Frames_ = resources.loadDivGraph(
        "media\\stage\\BossApproach1_ch1.png", 0x0e, 1, 0x0e, 400, 100);
    bossApproach1Ch2Frames_ = resources.loadDivGraph(
        "media\\stage\\BossApproach1_ch2.png", 0x0e, 1, 0x0e, 400, 100);
    bossApproach2Handle_ = resources.loadGraph("media\\stage\\BossApproach2.png");
    stage04PhaseTitleStandHandle_ = resources.graphFrame(
        "media\\system\\Stand.png", 33);
    bossGaugeFrames_ = resources.loadDivGraph("media\\stage\\BossGauge.png", 10, 1, 10, 500, 30);
    bossNameFrames_ = resources.loadDivGraph("media\\stage\\BossName.png", 0x16, 1, 0x16, 400, 30);
    textBoxFrames_ = resources.loadDivGraph("media\\system\\TextBox.png", 2, 1, 2, 600, 100);
    textIconFrames_ = resources.loadDivGraph("media\\system\\TextIcon.png", 0x14, 10, 2, 80, 80);
    if (bannerFontHandles_[0] == -1) {
        constexpr char kNyashiFace[] =
            "\xe3\x81\xab\xe3\x82\x83\xe3\x81\x97\xe3\x81\x83"
            "\xe3\x83\x95\xe3\x82\xa9\xe3\x83\xb3\xe3\x83\x88"
            "\xe6\x94\xb9\xe4\xba\x8c";
        bannerFontHandles_[0] = CreateFontToHandle(
            kNyashiFace, 0x12, 9, DX_FONTTYPE_ANTIALIASING_4X4);
    }
    if (bannerFontHandles_[1] == -1) {
        constexpr char kChillRoundFace[] =
            "\xe5\xaf\x92\xe8\x9d\x89\xe5\x8d\x8a"
            "\xe5\x9c\x86\xe4\xbd\x93";
        bannerFontHandles_[1] = CreateFontToHandle(
            kChillRoundFace, 0x12, 9, DX_FONTTYPE_ANTIALIASING_4X4);
    }
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack1bFrames_ = resources.loadDivGraph("media\\stage\\StageBack1b.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack1cFrames_ = resources.loadDivGraph("media\\stage\\StageBack1c.png", 0x0c, 0x0c, 1, 0x2d0, 0xa00);
    stageBack1dFrames_ = resources.loadDivGraph("media\\stage\\StageBack1d.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack2Frames_ = resources.loadDivGraph("media\\stage\\StageBack2.png", 10, 10, 1, 0x2d0, 0x2d0);
    const auto graphOrLoad = [&resources](const char* id, const char* path) {
        const int loaded = resources.graphHandleById(id);
        return loaded != -1 ? loaded : resources.loadGraph(path);
    };
    stage2BackHandle_ = graphOrLoad("GFX_stage_Stage2Back", "media\\stage\\Stage2Back.png");
    stage3BackHandle_ = graphOrLoad("GFX_stage_Stage3Back", "media\\stage\\Stage3Back.png");
    stage6BackHandle_ = graphOrLoad("GFX_stage_Stage6Back", "media\\stage\\Stage6Back.png");
    stage8Back1Handle_ = graphOrLoad("GFX_stage_Stage8Back1", "media\\stage\\Stage8Back1.png");
    stage8Back2Handle_ = graphOrLoad("GFX_stage_Stage8Back2", "media\\stage\\Stage8Back2.png");

    numSmallFrames_ = resources.loadDivGraph("media\\system\\Num_s.png", 0x0e, 0x0e, 1, 0x14, 0x1e);
    numMediumFrames_ = resources.loadDivGraph("media\\system\\Num_m.png", 10, 10, 1, 0x20, 0x30);
    numLargeFrames_ = resources.loadDivGraph("media\\system\\Num_l.png", 0x0e, 0x0e, 1, 0x30, 0x48);
    dataWindowHandle_ = resources.loadGraph("media\\player\\DataWindow.png");
    timeWindowHandle_ = resources.loadGraph("media\\player\\TimeWindow.png");
    dataWindow2Frames_ = resources.loadDivGraph("media\\player\\DataWindow2.png", 10, 10, 1, 60, 60);
    playerFrameFrames_ = resources.loadDivGraph("media\\player\\PlayerFrame.png", 0x1e, 10, 3, 0x154, 0x2d0);
    stateFrames_ = resources.loadDivGraph("media\\player\\State.png", 0x20, 1, 0x20, 200, 0x28);
    resultFrames_ = resources.loadDivGraph("media\\player\\Result.png", 0x14, 1, 0x14, 0xf0, 0x3c);
    configNumberFrames_ = resources.loadDivGraph("media\\system\\ConfigNumber.png", 0x0b, 1, 0x0b, 0x1e, 0x28);
    dreamGaugeFrames_ = resources.loadDivGraph("media\\player\\DreamGauge.png", 2, 2, 1, 0xa0, 0xa0);
    whiteBackHandle_ = resources.graphHandleById("GFX_system_WhiteBack");
    constexpr std::array<const char*, 8> kBombSoundIds{{
        "SE_se_Bomb1", "SE_se_Bomb2", "SE_se_Bomb3", "SE_se_Bomb4",
        "SE_se_Bomb5", "SE_se_Bomb6", "SE_se_Bomb7", "SE_se_Bomb8",
    }};
    constexpr std::array<const char*, 4> kFeverSoundIds{{
        "SE_se_Fever1", "SE_se_Fever2", "SE_se_Fever3", "SE_se_Fever4",
    }};
    for (std::size_t i = 0; i < bombSoundHandles_.size(); ++i) {
        bombSoundHandles_[i] = resources.soundHandleById(kBombSoundIds[i]);
    }
    for (std::size_t i = 0; i < feverSoundHandles_.size(); ++i) {
        feverSoundHandles_[i] = resources.soundHandleById(kFeverSoundIds[i]);
    }
    normalShotSoundHandle_ = resources.soundHandleById("SE_se_Shot1");
    optionLockSoundHandle_ = resources.soundHandleById("SE_se_BossSE4");
    missSoundHandle_ = resources.soundHandleById("SE_se_Miss");
    miss2SoundHandle_ = resources.soundHandleById("SE_se_Miss2");
    grazeSoundHandle_ = resources.soundHandleById("SE_se_Graze");
    guardSoundHandle_ = resources.soundHandleById("SE_se_Guard");
    shotHitSoundHandle_ = resources.soundHandleById("SE_se_Shothit");
    shotHit2SoundHandle_ = resources.soundHandleById("SE_se_Shothit2");
    item1SoundHandle_ = resources.soundHandleById("SE_se_Item1");
    item2SoundHandle_ = resources.soundHandleById("SE_se_Item2");
    item3SoundHandle_ = resources.soundHandleById("SE_se_Item3");
    extendSoundHandle_ = resources.soundHandleById("SE_se_Extend");
    blast1SoundHandle_ = resources.soundHandleById("SE_se_Blast1");
    enemyDown1SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown1");
    enemyDown2SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown2");
    enemyDown3SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown3");
    alertSoundHandle_ = resources.soundHandleById("SE_se_Alert");
    blast2SoundHandle_ = resources.soundHandleById("SE_se_Blast2");
    bullet1SoundHandle_ = resources.soundHandleById("SE_se_Bullet1");
    bullet2SoundHandle_ = resources.soundHandleById("SE_se_Bullet2");
    bossLifeSoundHandle_ = resources.soundHandleById("SE_se_BossLife");
    bonusSoundHandle_ = resources.soundHandleById("SE_se_Bonus");
    bossApproachSoundHandle_ = resources.soundHandleById("SE_se_BossApproach");
    bossWeakenSoundHandle_ = resources.soundHandleById("SE_se_BossWeaken");
    timerSoundHandle_ = resources.soundHandleById("SE_se_Timer");
    bossSe1SoundHandle_ = resources.soundHandleById("SE_se_BossSE1");
    bossSe2SecondSoundHandle_ = resources.soundHandleById("SE_se_BossSE2_2");
    bossSe3SoundHandle_ = resources.soundHandleById("SE_se_BossSE3");
    bossSe4SecondSoundHandle_ = resources.soundHandleById("SE_se_BossSE4_2");
    bossSe5SoundHandle_ = resources.soundHandleById("SE_se_BossSE5");
    bossSe6SoundHandle_ = resources.soundHandleById("SE_se_BossSE6");
    bossSe7SoundHandle_ = resources.soundHandleById("SE_se_BossSE7");
    bossSe8SoundHandle_ = resources.soundHandleById("SE_se_BossSE8");
    bossSe9SoundHandle_ = resources.soundHandleById("SE_se_BossSE9");
    bossSe14SoundHandle_ = resources.soundHandleById("SE_se_BossSE14");
    bossSe15SoundHandle_ = resources.soundHandleById("SE_se_BossSE15");
    constexpr std::array<const char*, 10> kStageBgmIds{{
        "BGM_bgm_Stage1", "BGM_bgm_Stage2", "BGM_bgm_Stage3", "BGM_bgm_Stage4",
        "BGM_bgm_Stage5", "BGM_bgm_Stage6", "BGM_bgm_Stage7", "BGM_bgm_Stage8",
        "BGM_bgm_Stage9", "BGM_bgm_Stage10",
    }};
    constexpr std::array<const char*, 5> kBossBgmIds{{
        "BGM_bgm_Boss1", "BGM_bgm_Boss2", "BGM_bgm_Boss3",
        "BGM_bgm_Boss4", "BGM_bgm_Boss5",
    }};
    for (std::size_t i = 0; i < stageBgmHandles_.size(); ++i) {
        stageBgmHandles_[i] = resources.soundHandleById(kStageBgmIds[i]);
    }
    for (std::size_t i = 0; i < bossBgmHandles_.size(); ++i) {
        bossBgmHandles_[i] = resources.soundHandleById(kBossBgmIds[i]);
    }
    stage04BgmHandle_ = stageBgmHandles_[3];
    // Stage 4-8 hand off to DAT_140e45140, the second loaded boss track.
    stage04BossBgmHandle_ = bossBgmHandles_[1];
    textSoundHandle_ = resources.soundHandleById("SE_se_Text");
    text2SoundHandle_ = resources.soundHandleById("SE_se_Text2");

    config_ = config;
    selectedStage_ = (config.stage >= 1 && config.stage <= 10) ? config.stage : 1;
    config_.stage = selectedStage_;
    config_.routeSubmode = std::clamp(config_.routeSubmode, 0, 3);
    config_.controlDevice = std::clamp(config_.controlDevice, 0, 5);
    config_.controlModeEnabled = config_.controlModeEnabled != 0 ? 1 : 0;
    config_.helpMode = std::clamp(config_.helpMode, 0, 6);
    config_.helpAutoProgress = std::max(config_.helpAutoProgress, 0);
    config_.specialMode = config_.specialMode != 0 ? 1 : 0;
    config_.specialStageFlag = config_.specialStageFlag != 0 ? 1 : 0;
    config_.dataWindowEnabled = config_.dataWindowEnabled != 0 ? 1 : 0;
    config_.language = std::clamp(config_.language, 0, 3);
    config_.bgmVolume = std::clamp(config_.bgmVolume, 0, 10);
    config_.soundEffectVolume = std::clamp(config_.soundEffectVolume, 0, 10);
    normalizeSystemConfig(config_.systemConfig);
    config_.itemVisibility = config_.systemConfig[3];
    config_.likeStyle = config_.systemConfig[5];
    initializePauseResources(resources);
    config_.rawStartFrame = std::max(config_.rawStartFrame, 0);
    config_.firstDispatchFrame = std::max(config_.firstDispatchFrame, -1);
    config_.initialStock = config_.initialStock < 0
                               ? -1
                               : std::clamp(config_.initialStock, 0, 3);
    config_.initialStockProgressSteps = config_.initialStockProgressSteps < 0
                                            ? -1
                                            : std::clamp(config_.initialStockProgressSteps, 0, 20);
    config_.initialSpecialGauge = config_.initialSpecialGauge < 0
                                      ? -1
                                      : std::clamp(config_.initialSpecialGauge, 0,
                                                   kSpecialGaugeReady);
    config_.initialBestScore = std::max<std::int64_t>(0, config_.initialBestScore);
    config_.initialBestTimeFrames = std::max(0, config_.initialBestTimeFrames);
    config_.continueRun = false;
    initialized_ = !playerFrames_.empty() && playerFrames_.front() != -1 &&
                   !itemFrames_.empty() && itemFrames_.front() != -1 &&
                   !enemySmallFrames_.empty() && enemySmallFrames_.front() != -1 &&
                   !bulletFrames_.empty() && bulletFrames_.front() != -1;
    reset();
    return initialized_;
}

void StageRuntime::setStage(int stage) {
    auto next = config_;
    next.stage = stage;
    (void)setConfig(next);
}

bool StageRuntime::setConfig(const StageRuntimeConfig& config) {
    auto next = config;
    const int normalized = (next.stage >= 1 && next.stage <= 10) ? next.stage : 1;
    next.stage = normalized;
    next.controlDevice = std::clamp(next.controlDevice, 0, 5);
    next.routeSubmode = std::clamp(next.routeSubmode, 0, 3);
    next.controlModeEnabled = next.controlModeEnabled != 0 ? 1 : 0;
    next.helpMode = std::clamp(next.helpMode, 0, 6);
    next.helpAutoProgress = std::max(next.helpAutoProgress, 0);
    next.specialMode = next.specialMode != 0 ? 1 : 0;
    next.specialStageFlag = next.specialStageFlag != 0 ? 1 : 0;
    next.dataWindowEnabled = next.dataWindowEnabled != 0 ? 1 : 0;
    next.language = std::clamp(next.language, 0, 3);
    next.bgmVolume = std::clamp(next.bgmVolume, 0, 10);
    next.soundEffectVolume = std::clamp(next.soundEffectVolume, 0, 10);
    normalizeSystemConfig(next.systemConfig);
    next.itemVisibility = next.systemConfig[3];
    next.likeStyle = next.systemConfig[5];
    next.rawStartFrame = std::max(next.rawStartFrame, 0);
    next.firstDispatchFrame = std::max(next.firstDispatchFrame, -1);
    next.initialStock = next.initialStock < 0 ? -1 : std::clamp(next.initialStock, 0, 3);
    next.initialStockProgressSteps = next.initialStockProgressSteps < 0
                                         ? -1
                                         : std::clamp(next.initialStockProgressSteps, 0, 20);
    next.initialSpecialGauge = next.initialSpecialGauge < 0
                                   ? -1
                                   : std::clamp(next.initialSpecialGauge, 0,
                                                kSpecialGaugeReady);
    next.initialBestScore = std::max<std::int64_t>(0, next.initialBestScore);
    next.initialBestTimeFrames = std::max(0, next.initialBestTimeFrames);
    const bool changed = selectedStage_ != normalized || config_.routeMode != next.routeMode ||
                         config_.routeSubmode != next.routeSubmode ||
                         config_.setupGroup != next.setupGroup ||
                         config_.playerOption != next.playerOption || config_.subOption != next.subOption ||
                         config_.loadoutId != next.loadoutId || config_.difficulty != next.difficulty ||
                         config_.counterMode != next.counterMode || config_.optionSlots != next.optionSlots ||
                         config_.specialMode != next.specialMode ||
                         config_.specialStageFlag != next.specialStageFlag ||
                         config_.dataWindowEnabled != next.dataWindowEnabled ||
                         config_.language != next.language ||
                         config_.bgmVolume != next.bgmVolume ||
                         config_.soundEffectVolume != next.soundEffectVolume ||
                         config_.dataWindowUnlocked != next.dataWindowUnlocked ||
                         config_.systemConfig != next.systemConfig ||
                         config_.itemVisibility != next.itemVisibility ||
                         config_.likeStyle != next.likeStyle ||
                         config_.keyboardBindings != next.keyboardBindings ||
                         config_.controllerBindings != next.controllerBindings ||
                         config_.controlDevice != next.controlDevice ||
                         config_.controlModeEnabled != next.controlModeEnabled || config_.helpMode != next.helpMode ||
                         config_.helpAutoProgress != next.helpAutoProgress ||
                         config_.rawStartFrame != next.rawStartFrame ||
                         config_.firstDispatchFrame != next.firstDispatchFrame ||
                         config_.initialStock != next.initialStock ||
                         config_.initialStockProgressSteps != next.initialStockProgressSteps ||
                         config_.initialSpecialGauge != next.initialSpecialGauge ||
                         config_.initialBestScore != next.initialBestScore ||
                         config_.initialBestTimeFrames != next.initialBestTimeFrames ||
                         config_.replayPlayback != next.replayPlayback ||
                         next.continueRun;
    config_ = next;
    selectedStage_ = normalized;
    if (changed) {
        reset();
    }
    return changed;
}

StageRuntime::GameplayExitRequest StageRuntime::consumeExitRequest() {
    const GameplayExitRequest request = pendingExitRequest_;
    pendingExitRequest_ = GameplayExitRequest::None;
    return request;
}

void StageRuntime::reset() {
    const PlayerState previousPlayer = player_;
    const bool continueRun = config_.continueRun;
    const int previousTimeWindowStage = timeWindowStage_;
    const int previousTimeWindowElapsedFrames = timeWindowElapsedFrames_;
    const auto previousTimeWindowStageBoundaries = timeWindowStageBoundaries_;
    config_.continueRun = false;
    pendingExitRequest_ = GameplayExitRequest::None;
    frame_ = config_.firstDispatchFrame;
    player_ = {};
    hudSpecialGaugeFlashTimer_ = 0;
    const bool timeWindowEnabled = config_.specialStageFlag == 1 &&
                                   (config_.routeMode == 1 || config_.routeMode == 2);
    timeWindowDispatchCount_ = 1;
    timeWindowStage_ = selectedStage_;
    if (continueRun && timeWindowEnabled) {
        timeWindowElapsedFrames_ = previousTimeWindowElapsedFrames;
        timeWindowStageBoundaries_ = previousTimeWindowStageBoundaries;
        if (previousTimeWindowStage >= 1 && previousTimeWindowStage <= 8 &&
            selectedStage_ > previousTimeWindowStage) {
            timeWindowStageBoundaries_[static_cast<std::size_t>(previousTimeWindowStage)] =
                previousTimeWindowElapsedFrames;
        }
    }
    else {
        timeWindowElapsedFrames_ = 0;
        timeWindowStageBoundaries_.fill(0);
    }
    timeWindowBestFrames_ = std::max(0, config_.initialBestTimeFrames);
    player_.bestScore = std::max<std::int64_t>(0, config_.initialBestScore);
    if (continueRun) {
        player_.score = previousPlayer.score;
        player_.bestScore = std::max(player_.bestScore, previousPlayer.bestScore);
        player_.scoreItemBaseValue = previousPlayer.scoreItemBaseValue;
        player_.specialGauge = previousPlayer.specialGauge;
        player_.tokenStock = previousPlayer.tokenStock;
        player_.graze = previousPlayer.graze;
        player_.beingShotCount = previousPlayer.beingShotCount;
        player_.extendIndex = previousPlayer.extendIndex;
        player_.stockProgress = previousPlayer.stockProgress;
        player_.lives = previousPlayer.lives;
        player_.animationClock = previousPlayer.animationClock;
        player_.drawAnimationClock = previousPlayer.drawAnimationClock;
    }
    else {
        if (config_.initialStock >= 0) {
            player_.tokenStock = config_.initialStock;
        }
        if (config_.routeMode == 2) {
            // FUN_1401105c0 applies the selected Mental level separately and
            // always starts Practice with the full nine-heart Life stock.
            player_.lives = kLifeStockCap;
        }
        const int threshold = stockThresholdForCurrentConfig();
        player_.stockProgress = threshold * player_.tokenStock;
        if (config_.initialStockProgressSteps >= 0) {
            player_.stockProgress +=
                (threshold / 20) * config_.initialStockProgressSteps;
            if (config_.initialStockProgressSteps == 20) {
                --player_.stockProgress;
            }
        }
        if (config_.initialSpecialGauge >= 0) {
            player_.specialGauge = config_.initialSpecialGauge;
            if (config_.initialSpecialGauge > 0) {
                hudSpecialGaugeFlashTimer_ = 60;
            }
        }
    }
    player_.optionX.fill(player_.x);
    player_.optionY.fill(player_.y);
    if (!continueRun) {
        replayRecording_.clear();
        replayCheckpointPending_ = false;
        if (!config_.replayPlayback) {
            initializeReplayRecording();
        }
    }
    else if (replayRecording_.recordable && config_.routeMode == 1 &&
             selectedStage_ != 10) {
        // The original stores this checkpoint after appending the first input
        // node and dispatching the new stage's first frame.
        replayCheckpointPending_ = true;
    }
    hudFrameRateSampleStart_ = std::chrono::steady_clock::now();
    hudFrameRateSampleTicks_ = 0;
    hudMeasuredFrameRate_ = 60;
    enemyProjectileSpawnsThisSecond_ = 0;
    enemyProjectileSpawnsLastSecond_ = 0;
    nextEntityId_ = 1;
    enemies_.reserve(kStageEntityCap);
    enemyProjectiles_.reserve(kProjectileCap);
    playerSideObjects_.reserve(kPlayerSideObjectCap);
    rewardItems_.reserve(kRewardItemCap);
    stageEffects_.reserve(kStageEffectCap);
    stage01GateFlag_ = false;
    stage02GateFlag_ = false;
    stage03GateFlag_ = false;
    stage04GateFlag_ = false;
    stage05GateFlag_ = false;
    stage06GateFlag_ = false;
    stage07GateFlag_ = false;
    stage08GateFlag_ = false;
    stage09GateFlag_ = false;
    stage10GateFlag_ = false;
    stage01EndVisualQueued_ = false;
    stage01EndFlushed_ = false;
    stage01BossSpawned_ = false;
    stage01BossPhaseMode_ = 0;
    stage01BossMaxHp_ = 100000;
    stage01BossCountdown_ = 0;
    stage01BossCountdownDraw_ = 0;
    stage01BossBreaksRemaining_ = 3;
    stage01BossPhaseIndex_ = 0;
    stage01BossTargetX_ = 360.0f;
    stage01BossTargetY_ = 200.0f;
    stage01ClearStarted_ = false;
    stage01ClearTransition_ = false;
    stage01ClearComplete_ = false;
    stage02BossPhaseMode_ = 0;
    stage02BossMaxHp_ = 100000;
    stage02BossCountdown_ = 0;
    stage02BossCountdownDraw_ = 0;
    stage02BossBreaksRemaining_ = 4;
    stage02BossPhaseIndex_ = 0;
    stage02BossTargetX_ = 360.0f;
    stage02BossTargetY_ = 180.0f;
    stage02ClearStarted_ = false;
    stage02ClearTransition_ = false;
    stage02ClearComplete_ = false;
    stage03BossPhaseMode_ = 0;
    stage03BossMaxHp_ = 100000;
    stage03BossCountdown_ = 0;
    stage03BossCountdownDraw_ = 0;
    stage03BossBreaksRemaining_ = 4;
    stage03BossPhaseIndex_ = 0;
    stage03BossTargetX_ = 360.0f;
    stage03BossTargetY_ = 200.0f;
    stage03ClearStarted_ = false;
    stage03ClearTransition_ = false;
    stage03ClearComplete_ = false;
    stage04BossPhaseMode_ = 0;
    stage04BossMaxHp_ = 100000;
    stage04BossCountdown_ = 0;
    stage04BossCountdownDraw_ = 0;
    stage04BossBreaksRemaining_ = 4;
    stage04BossPhaseIndex_ = 0;
    stage04BossTargetX_ = 360.0f;
    stage04BossTargetY_ = 200.0f;
    stage04ClearStarted_ = false;
    stage04ClearTransition_ = false;
    stage04ClearComplete_ = false;
    earlyStageApproachAgeDraw_ = -1;
    lateStageClearComplete_.fill(false);
    lateStageApproachAgeDraw_ = -1;
    lateStageClearTimer_ = 0;
    lateStageBossPhaseMode_ = 0;
    lateStageBossPhaseIndex_ = 0;
    lateStageBossBreaksRemaining_ = 0;
    lateStageBossCountdown_ = 0;
    lateStageBossCountdownDraw_ = 0;
    lateStageBossMaxHp_ = 100000;
    lateStageBossTargetX_ = 360.0f;
    lateStageBossTargetY_ = 200.0f;
    bossPhaseRewardIndex_ = 0;
    observedBossPhaseMode_ = 0;
    lateStageBossSpawned_ = false;
    lateStageClearStarted_ = false;
    activeBossBgmIndex_ = -1;
    stage10TransitionStarted_ = false;
    stage10FinalBossSpawned_ = false;
    inputActions_.fill(false);
    pauseFlowState_ = PauseFlowState::Gameplay;
    pauseCursor_ = 0;
    pauseTransitionTimer_ = 0;
    pauseStateTimer_ = 0;
    pauseSelectionPulse_ = 0;
    pauseUpHeldFrames_ = 0;
    pauseDownHeldFrames_ = 0;
    pauseLeftHeldFrames_ = 0;
    pauseRightHeldFrames_ = 0;
    pauseInputConsumed_ = false;
    pauseSettingsDirty_ = false;
    pauseSaveDataRequested_ = false;
    pauseSaveSystemConfigRequested_ = false;
    pauseInputHeld_ = false;
    gameOverDelayComplete_ = false;
    pauseKeyCaptureActive_ = false;
    pauseKeyCaptureDelay_ = 0;
    pauseLastControlDevice_ = config_.controlDevice;
    pausedBgmHandles_.clear();
    enemies_.clear();
    pendingEnemies_.clear();
    enemyProjectiles_.clear();
    playerSideObjects_.clear();
    rewardItems_.clear();
    stageEffects_.clear();
    lateBackgroundScroll_.fill(0.0);
    lateBackgroundScrollFrame_ = -0x3fffffff;
    backgroundDrawFrame_ = frame_;
    backgroundStage08BossState_ = -1;
    backgroundStage08BossTimer_ = 0;
    backgroundStage09BossState_ = -1;
    backgroundStage09BossTimer_ = 0;
    backgroundStageGateOpen_ = false;
    stage09BossDefeatFrames_.fill(-1);
    backgroundStage09BossDefeatFrames_.fill(-1);

    for (const int handle : stageBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle);
        }
    }
    for (const int handle : bossBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle);
        }
    }
    if (gameOverBgmHandle_ != -1) {
        StopSoundMem(gameOverBgmHandle_);
    }
    const int stageBgm = stageBgmHandles_[static_cast<std::size_t>(selectedStage_ - 1)];
    // Fresh Stage 10 runs start this at frame 320. Practice/Trial entries beyond
    // that boundary arrive with the track already selected by the context init.
    if ((selectedStage_ != 10 || config_.rawStartFrame >= 320) && stageBgm != -1) {
        ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5), stageBgm);
        PlaySoundMem(stageBgm, DX_PLAYTYPE_LOOP, TRUE);
    }
}

void StageRuntime::update() {
    if (!initialized_) {
        return;
    }

    const auto frameRateNow = std::chrono::steady_clock::now();
    ++hudFrameRateSampleTicks_;
    if (frameRateNow - hudFrameRateSampleStart_ > std::chrono::seconds(1)) {
        hudMeasuredFrameRate_ = hudFrameRateSampleTicks_;
        hudFrameRateSampleTicks_ = 0;
        hudFrameRateSampleStart_ = frameRateNow;
    }

    const bool replayRecordsThisTick =
        pauseFlowState_ == PauseFlowState::Gameplay && !stageComplete();
    pollInput();
    if (replayRecordsThisTick) {
        recordReplayInputFrame();
    }
    if (updatePauseFlow()) {
        return;
    }

    updateLayoutGuideToggle();
    if (stageComplete()) {
        return;
    }

    // Entity/projectile helpers enqueue their terminal-frame draw before the
    // original linked-list unlink pass. Keep inactive nodes through this frame's
    // draw and unlink them only at the beginning of the next update.
    enemyProjectiles_.erase(
        std::remove_if(enemyProjectiles_.begin(), enemyProjectiles_.end(),
                       [](const StageProjectile& projectile) { return !projectile.active; }),
        enemyProjectiles_.end());
    enemies_.erase(std::remove_if(enemies_.begin(), enemies_.end(), [this](const StageEnemy& enemy) {
                       // FUN_14002d2f0 parks the non-participating Stage 7 head
                       // at y=30000 and brings it back for the final joint phase.
                       // Its original linked-list lifetime is controlled by the
                       // helper's active flag, not by its temporary position.
                       const bool persistentStage07Head =
                           enemy.parentSpawnType == 0x13e &&
                           (enemy.spawnType == 0x83 || enemy.spawnType == 0x84);
                       // The original Stage 6/8 schedules also enqueue later
                       // formation rows several screens above the playfield.
                       // Keep only those proven deep-entry rows until their
                       // exact helpers have advanced them into the normal range.
                       const bool stage06DeepEntry = selectedStage_ == 6 &&
                           (enemy.spawnType == 0x5a || enemy.spawnType == 0x5d ||
                            enemy.spawnType == 0x5e || enemy.spawnType == 0x5f);
                       const bool stage08DeepEntry = selectedStage_ == 8 &&
                           (enemy.spawnType == 0x1d || enemy.spawnType == 0x1f ||
                            enemy.spawnType == 0x5a || enemy.spawnType == 0x5d ||
                            enemy.spawnType == 0x5f || enemy.spawnType == 0x97 ||
                            enemy.spawnType == 0x9a);
                       const bool deferredDeepEntry =
                           enemy.sourceY < -4096 && enemy.y < -4096.0f &&
                           (stage06DeepEntry || stage08DeepEntry);
                       return !enemy.active ||
                              (!persistentStage07Head && !deferredDeepEntry &&
                               offscreen(enemy.x, enemy.y, 4096.0f));
                   }), enemies_.end());
    playerSideObjects_.erase(
        std::remove_if(playerSideObjects_.begin(), playerSideObjects_.end(),
                       [](const PlayerSideObject& object) { return !object.active; }),
        playerSideObjects_.end());
    rewardItems_.erase(
        std::remove_if(rewardItems_.begin(), rewardItems_.end(),
                       [](const RewardItem& item) { return !item.active; }),
        rewardItems_.end());
    stageEffects_.erase(
        std::remove_if(stageEffects_.begin(), stageEffects_.end(),
                       [](const StageEffect& effect) { return !effect.active; }),
        stageEffects_.end());

    int stageDispatchCount = 1;
    const bool stageGateOpen = [this]() {
        switch (selectedStage_) {
        case 1: return stage01GateFlag_;
        case 2: return stage02GateFlag_;
        case 3: return stage03GateFlag_;
        case 4: return stage04GateFlag_;
        case 5: return stage05GateFlag_;
        case 6: return stage06GateFlag_;
        case 7: return stage07GateFlag_;
        case 8: return stage08GateFlag_;
        case 9: return stage09GateFlag_;
        case 10: return stage10GateFlag_;
        default: return false;
        }
    }();
    const int stageEnd = kStageEndFrames[static_cast<std::size_t>(selectedStage_)];
    if (config_.specialStageFlag == 1 && frame_ > 230 &&
        frame_ >= config_.rawStartFrame + 10 && frame_ < stageEnd - 360 &&
        !stageGateOpen) {
        int activeRadius = 0;
        for (const StageEnemy& enemy : enemies_) {
            if (enemy.active && enemy.targetable) {
                activeRadius += enemy.radius;
            }
        }
        if (activeRadius == 0) {
            stageDispatchCount = 4;
        }
        else if (activeRadius < 70) {
            stageDispatchCount = 3;
        }
        else if (activeRadius < 140) {
            stageDispatchCount = 2;
        }
    }
    if (config_.specialStageFlag == 1 &&
        (config_.routeMode == 1 || config_.routeMode == 2)) {
        ++timeWindowElapsedFrames_;
    }
    timeWindowDispatchCount_ = stageDispatchCount;

    // FUN_1400be7a0 queues the complete background before the stage-specific
    // entity dispatcher mutates the frame counter or boss helper state.
    backgroundDrawFrame_ = frame_;
    backgroundStage08BossState_ = -1;
    backgroundStage08BossTimer_ = 0;
    backgroundStage09BossState_ = -1;
    backgroundStage09BossTimer_ = 0;
    backgroundStageGateOpen_ = stageGateOpen;
    for (const StageEnemy& enemy : enemies_) {
        if (!enemy.active) {
            continue;
        }
        if (enemy.spawnType == 0x13f && backgroundStage08BossState_ < 0) {
            backgroundStage08BossState_ = enemy.helperState;
            backgroundStage08BossTimer_ = enemy.helperTimer;
        }
        else if (enemy.spawnType == 0x140 && backgroundStage09BossState_ < 0) {
            backgroundStage09BossState_ = enemy.helperState;
            backgroundStage09BossTimer_ = enemy.helperTimer;
        }
    }
    backgroundStage09BossDefeatFrames_ = stage09BossDefeatFrames_;
    spawnBackgroundEffects();

    for (int dispatch = 0; dispatch < stageDispatchCount; ++dispatch) {
        spawnDueEvents();
        if (dispatch + 1 < stageDispatchCount) {
            ++frame_;
        }
    }
    if (replayCheckpointPending_) {
        // State 0x14 appends this tick's input first, runs the stage dispatcher,
        // then snapshots the new stage before FUN_140106be0 updates the player.
        captureReplayStageCheckpoint();
    }
    updatePlayer();
    const bool hasGaugeFlashClockSource =
        std::any_of(enemies_.begin(), enemies_.end(),
                    [](const StageEnemy& enemy) {
                        return enemy.active && enemy.targetable;
                    }) ||
        std::any_of(rewardItems_.begin(), rewardItems_.end(),
                    [](const RewardItem& item) { return item.active; });
    if (hudSpecialGaugeFlashTimer_ > 0 && hasGaugeFlashClockSource) {
        --hudSpecialGaugeFlashTimer_;
    }
    updatePlayerSideObjects();
    updateEnemies();
    // FUN_140078b70 performs the player-object collision pass from each enemy
    // update, before reward items and FUN_140070e40 advance the effect list.
    // This lets hit sparks and shot afterimages update and queue in the frame
    // in which they were created.
    handlePlayerSideObjectEnemyCollisions();
    const int currentBossPhaseMode = [this]() {
        switch (selectedStage_) {
        case 1: return stage01BossPhaseMode_;
        case 2: return stage02BossPhaseMode_;
        case 3: return stage03BossPhaseMode_;
        case 4: return stage04BossPhaseMode_;
        default: return lateStageBossPhaseMode_;
        }
    }();
    if (currentBossPhaseMode == 1 && observedBossPhaseMode_ != 1) {
        // Every original live attack resets DAT_140e4192c before the player
        // can invalidate its no-miss bonus.
        bossPhaseRewardIndex_ = 0;
    }
    observedBossPhaseMode_ = currentBossPhaseMode;
    updateRewardItems();
    updateStageEffects();
    updateProjectiles();
    handlePlayerSideObjectProjectileCancels();
    handleEnemyProjectilePlayerHitAndGraze();

    const auto& extendThresholds =
        kExtendThresholds[static_cast<std::size_t>(std::clamp(config_.difficulty, 0, 4))];
    if (player_.extendIndex >= 0 && player_.extendIndex < 5 &&
        player_.score >= extendThresholds[static_cast<std::size_t>(player_.extendIndex)]) {
        playPlayerSound(extendSoundHandle_);
        if (player_.lives < kLifeStockCap) {
            ++player_.lives;
        }
        ++player_.extendIndex;
    }

    if (frame_ > 59 && frame_ % 60 == 0) {
        enemyProjectileSpawnsLastSecond_ = enemyProjectileSpawnsThisSecond_;
        enemyProjectileSpawnsThisSecond_ = 0;
    }

    // FUN_1400bca30 increments DAT_140e44acc at the dispatcher tail even when
    // the player update returned early for a miss or the game-over delay.
    ++player_.animationClock;
    ++frame_;
    completeGameOverDelayFrame();
}

void StageRuntime::draw() const {
    if (pauseFlowState_ == PauseFlowState::GameOverPresentation) {
        drawRightHudPanel(0x6e);
        drawHudSidebar(0x6e);
        drawHudSidebar(0x6f);
        drawHudSidebar(0x70);
        drawHudSidebar(0x73);
        drawHudSidebar(0x78);
        drawHudSidebar(0x7c);
        drawOverlay();
        drawPauseFlow();
        return;
    }

    const auto drawEnemyEffectRange = [this](int firstLayer, int lastLayer) {
        for (int layer = firstLayer; layer <= lastLayer; ++layer) {
            if (layer <= 0x18) {
                drawBackgroundLayer(layer);
            }
            drawEnemies(layer);
            drawStageEffects(true, layer);
        }
    };

    drawEnemyEffectRange(0x00, 0x15);
    drawBackgroundLayer(0x16);
    if (config_.itemVisibility == 1 && whiteBackHandle_ != -1) {
        // FUN_1400be7a0 queues this at layer 0x16, after the lower
        // background/effect nodes and before the normal entity layers.
        SetDrawBright(0, 0, 0);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
        DrawGraph(0, 0, whiteBackHandle_, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        SetDrawBright(255, 255, 255);
    }
    // The background mask is queued first at 0x16; persistent effects on the
    // same layer are appended later in the frame and therefore draw over it.
    drawEnemies(0x16);
    drawStageEffects(true, 0x16);

    for (int layer = 0x17; layer <= 0x26; ++layer) {
        if (layer <= 0x18) {
            drawBackgroundLayer(layer);
        }
        if (layer == 0x17) {
            drawPlayerSideObjects(PlayerSideDrawPass::Flash);
        }
        drawEnemies(layer);
        drawStageEffects(true, layer);
        if (layer == 0x23) {
            // Selectors 0x13/0x14 queue their immediate overlay here even
            // though their base projectile remains on 0x50 or 0x51.
            drawProjectiles(layer);
        }
    }
    drawEnemies(0x27);
    drawStageEffects(true, 0x27);
    drawPlayerBody();
    drawEnemies(0x28);
    drawStageEffects(true, 0x28);
    drawEnemyEffectRange(0x29, 0x2b);
    drawPlayerSideObjects(PlayerSideDrawPass::Normal);
    drawEnemies(0x2c);
    drawStageEffects(true, 0x2c);
    drawEnemyEffectRange(0x2d, 0x3b);
    drawPlayerSideObjects(PlayerSideDrawPass::Core);
    drawEnemies(0x3c);
    drawStageEffects(true, 0x3c);
    drawEnemyEffectRange(0x3d, 0x3f);
    drawEnemies(0x40);
    drawStageEffects(true, 0x40);
    drawEnemies(0x41);
    drawRewardItems(false);
    drawStageEffects(true, 0x41);
    drawEnemyEffectRange(0x42, 0x45);
    drawPlayer(PlayerOverlayDrawPass::MarkerRing);
    drawEnemies(0x46);
    drawStageEffects(true, 0x46);
    drawEnemyEffectRange(0x47, 0x4b);
    drawPlayer(PlayerOverlayDrawPass::GaugeFill);
    drawEnemies(0x4c);
    drawRewardItems(true);
    drawStageEffects(true, 0x4c);
    drawPlayer(PlayerOverlayDrawPass::GaugeFrame);
    drawEnemies(0x4d);
    drawStageEffects(true, 0x4d);
    drawEnemies(0x4e);
    drawStageEffects(true, 0x4e);
    drawProjectiles(0x4e);
    drawEnemies(0x4f);
    drawStageEffects(true, 0x4f);
    drawProjectiles(0x4f);
    drawPlayer(PlayerOverlayDrawPass::Aura);
    drawEnemies(0x50);
    drawStageEffects(true, 0x50);
    drawProjectiles(0x50);
    drawEnemies(0x51);
    drawStageEffects(true, 0x51);
    drawProjectiles(0x51);
    drawEnemyEffectRange(0x52, 0x59);
    drawPlayer(PlayerOverlayDrawPass::Hitbox);
    drawEnemies(0x5a);
    drawStageEffects(true, 0x5a);
    drawEnemyEffectRange(0x5b, 0x6d);
    drawRightHudPanel(0x6e);
    drawHudSidebar(0x6e);
    drawEnemies(0x6e);
    drawStageEffects(true, 0x6e);
    drawHudSidebar(0x6f);
    drawStageApproach();
    drawStage01BossHud();
    drawStage02BossHud();
    drawStage03BossHud();
    drawStage04BossHud();
    drawLateStageBossHud();
    drawEnemies(0x6f);
    drawStageEffects(true, 0x6f);
    drawHudSidebar(0x70);
    drawStageBannerPanels();
    drawStageEffects(true, 0x70);
    drawStageEffects(true, 0x71);
    drawStageEffects(true, 0x72);
    drawHudSidebar(0x73);
    drawStageEffects(true, 0x73);
    drawHudSidebar(0x78);
    drawHudSidebar(0x7c);
    drawOverlay();
    drawStageBannerText();
    drawPauseFlow();
}

int StageRuntime::enemiesAlive() const {
    return static_cast<int>(std::count_if(enemies_.begin(), enemies_.end(),
                                         [](const StageEnemy& enemy) {
                                             return enemy.active && enemy.spawnType != 0x137 &&
                                                    enemy.spawnType != 0x153;
                                         }));
}

int StageRuntime::enemyProjectilesAlive() const {
    return static_cast<int>(enemyProjectiles_.size());
}

void StageRuntime::pollInput() {
    const int padState = GetJoypadInputState(DX_INPUT_PAD1);
    bool keyboardUsed = false;
    bool controllerUsed = false;
    for (std::size_t action = 0; action < inputActions_.size(); ++action) {
        const int key = config_.keyboardBindings[action];
        const bool keyboardDown = key > 0 && key < 0x100 && CheckHitKey(key) != 0;
        const int binding = config_.controllerBindings[action];
        const bool controllerDown = padState != -1 && binding != 0 && (padState & binding) != 0;
        inputActions_[action] = keyboardDown || controllerDown;
        keyboardUsed = keyboardUsed || keyboardDown;
        controllerUsed = controllerUsed || controllerDown;
    }
    if (keyboardUsed) {
        config_.controlDevice = 5;
    }
    if (controllerUsed) {
        config_.controlDevice = controlDeviceForPadType(GetJoypadType(DX_INPUT_PAD1));
    }
}

bool StageRuntime::actionDown(InputAction action) const {
    const auto index = static_cast<std::size_t>(action);
    return index < inputActions_.size() && inputActions_[index];
}

void StageRuntime::initializeReplayStageDefaults() {
    auto& header = replayRecording_.header;
    for (int stage = 1; stage <= 10; ++stage) {
        const std::size_t base = kReplayStageSnapshotOffset +
                                 static_cast<std::size_t>(stage - 1) *
                                     kReplayStageSnapshotStride;

        // FUN_1401121f0 initializes ten 0xf0-byte checkpoint records with the
        // same neutral player state. Fields not represented by StageRuntime
        // remain zero, as they do in the original initializer.
        writeReplayI32(header, base + 0x1c, 1);
        writeReplayF32(header, base + 0x20, 360.0f);
        writeReplayF32(header, base + 0x24, 600.0f);
        writeReplayF32(header, base + 0x28, 360.0f);
        writeReplayF32(header, base + 0x2c, 600.0f);
        writeReplayU16(header, base + 0x30, 0xc000);
        writeReplayI32(header, base + 0x40, 2);
        writeReplayF32(header, base + 0x4c, 360.0f);
        writeReplayF32(header, base + 0x50, 600.0f);
        writeReplayF32(header, base + 0x54, 360.0f);
        writeReplayF32(header, base + 0x58, 600.0f);
        writeReplayF32(header, base + 0x5c, 360.0f);
        writeReplayF32(header, base + 0x60, 600.0f);
        writeReplayF32(header, base + 0x64, 360.0f);
        writeReplayF32(header, base + 0x68, 600.0f);
        writeReplayU16(header, base + 0x6c, 0xc000);
        writeReplayU16(header, base + 0x6e, 0xc000);
        writeReplayU16(header, base + 0x70, 0xc000);
        writeReplayU16(header, base + 0x72, 0xc000);
        writeReplayU16(header, base + 0x84, 0xc000);
        writeReplayI64(header, base + 0x90, 0x20);
        writeReplayI32(header, base + 0x9c, 0x3c);
    }
}

void StageRuntime::initializeReplayRecording() {
    replayRecording_.clear();
    replayRecording_.recordable = true;
    replayRecording_.inputRecords.reserve(40000);

    auto& header = replayRecording_.header;
    writeReplayI32(header, 0x0000, kReplayFormatVersion);
    header[0x0008] = ' ';
    header[0x0009] = ' ';
    header[0x000a] = ' ';

    const std::time_t now = std::time(nullptr);
    const auto timestamp = std::max<std::int64_t>(0, static_cast<std::int64_t>(now));
    writeReplayI64(header, 0x0010, timestamp);
    writeReplayI32(header, 0x0018, config_.routeMode);
    writeReplayI32(header, 0x001c, config_.routeSubmode);
    writeReplayI32(header, 0x0020, config_.difficulty);
    writeReplayI32(header, 0x0024, config_.counterMode);
    writeReplayI32(header, 0x0028, config_.specialStageFlag);
    writeReplayI32(header, 0x002c, config_.setupGroup);
    for (std::size_t index = 0; index < config_.optionSlots.size(); ++index) {
        writeReplayI32(header, 0x0030 + index * sizeof(std::int32_t),
                       config_.optionSlots[index]);
    }
    writeReplayI32(header, 0x0040, selectedStage_);
    writeReplayI32(header, 0x0044, 1);
    writeReplayI32(header, 0x0048, 2);
    writeReplayI32(header, 0x004c, 4);
    writeReplayI32(header, 0x0050, 6);
    writeReplayI32(header, 0x0068, config_.controlModeEnabled);
    writeReplayI32(header, 0x006c, config_.specialMode);
    // FUN_1401121f0 resolves Auto (0) at recording start, while explicit
    // levels 1..5 and the Off sentinel (6) are stored unchanged.
    writeReplayI32(header, 0x0070,
                   config_.helpMode == 0 ? effectiveHelpLevel() : config_.helpMode);
    writeReplayI64(header, 0x0074, 1);
    initializeReplayStageDefaults();
    replayCheckpointPending_ = config_.routeMode == 1 && selectedStage_ != 10;
}

void StageRuntime::captureReplayStageCheckpoint() {
    if (!replayRecording_.recordable || selectedStage_ < 1 || selectedStage_ > 10) {
        replayCheckpointPending_ = false;
        return;
    }

    auto& header = replayRecording_.header;
    const std::size_t base = kReplayStageSnapshotOffset +
                             static_cast<std::size_t>(selectedStage_ - 1) *
                                 kReplayStageSnapshotStride;
    writeReplayI32(header, base + 0x00,
                   static_cast<std::int32_t>(replayRecording_.inputRecords.size()));
    writeReplayI32(header, base + 0x08, config_.setupGroup);
    for (std::size_t index = 0; index < config_.optionSlots.size(); ++index) {
        writeReplayI32(header, base + 0x0c + index * sizeof(std::int32_t),
                       config_.optionSlots[index]);
    }
    writeReplayI32(header, base + 0x1c, 1);
    writeReplayF32(header, base + 0x20, player_.x);
    writeReplayF32(header, base + 0x24, player_.y);
    writeReplayF32(header, base + 0x28, player_.sharedOptionTargetX);
    writeReplayF32(header, base + 0x2c, player_.sharedOptionTargetY);
    writeReplayU16(header, base + 0x30, player_.movementAngle16);
    writeReplayI32(header, base + 0x40, player_.lives);
    writeReplayI32(header, base + 0x44, player_.playerStateTimer);
    writeReplayI32(header, base + 0x48, player_.bombLock);
    for (std::size_t index = 0; index < player_.optionX.size(); ++index) {
        writeReplayF32(header, base + 0x4c + index * 8, player_.optionX[index]);
        writeReplayF32(header, base + 0x50 + index * 8, player_.optionY[index]);
        writeReplayU16(header, base + 0x6c + index * sizeof(std::uint16_t),
                       player_.optionAngle16[index]);
        writeReplayI32(header, base + 0x74 + index * sizeof(std::int32_t),
                       player_.optionTargetEntityIds[index]);
    }
    writeReplayU16(header, base + 0x84, player_.optionFormationAngle16);
    writeReplayI32(header, base + 0x88, player_.shotTimer);
    writeReplayI32(header, base + 0x8c, player_.focused ? 1 : 0);
    writeReplayI32(header, base + 0x90, player_.focusTransition);
    writeReplayI32(header, base + 0x94, player_.lateralAnimation);
    writeReplayI32(header, base + 0x98, player_.focusHoldTimer);
    writeReplayI32(header, base + 0x9c, player_.invulnerableFrames);
    writeReplayI32(header, base + 0xa0, player_.shotVariant);
    writeReplayI32(header, base + 0xa8, player_.extendIndex);
    writeReplayI32(header, base + 0xac, player_.tokenStock);
    writeReplayI32(header, base + 0xb0, player_.stockProgress);
    writeReplayI32(header, base + 0xb4, player_.specialGauge);
    writeReplayI32(header, base + 0xb8, hudSpecialGaugeFlashTimer_);
    writeReplayI64(header, base + 0xc0, player_.score);
    writeReplayI64(header, base + 0xc8, player_.scoreItemBaseValue);
    writeReplayI32(header, base + 0xd0, timeWindowElapsedFrames_);
    writeReplayI32(header, base + 0xdc, player_.beingShotCount);
    writeReplayI32(header, base + 0xe0, player_.graze);
    writeReplayI32(header, base + 0xe8, config_.counterMode);
    replayCheckpointPending_ = false;
}

void StageRuntime::recordReplayInputFrame() {
    if (!replayRecording_.recordable || config_.replayPlayback ||
        replayRecording_.inputRecords.size() >=
            static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max())) {
        return;
    }

    std::uint16_t inputMask = 0;
    // The on-disk mask contains the first ten original actions. Pause is the
    // eleventh runtime action and was never serialized by FUN_1400bca30.
    for (std::size_t action = 0; action < 10; ++action) {
        if (inputActions_[action]) {
            inputMask = static_cast<std::uint16_t>(inputMask | (1U << action));
        }
    }
    replayRecording_.inputRecords.push_back({
        static_cast<std::uint32_t>(replayRecording_.inputRecords.size()), inputMask,
    });
    writeReplayI32(replayRecording_.header, 0x0004,
                   static_cast<std::int32_t>(replayRecording_.inputRecords.size()));
}

ReplayData StageRuntime::finalizedReplayData() {
    if (replayRecording_.recordable && !config_.replayPlayback && stageComplete() &&
        selectedStage_ >= 1 && selectedStage_ <= 9) {
        // FUN_1400c6e10 stores cumulative boundaries at the current stage
        // index; element zero remains the run's zero baseline.
        writeReplayI64(replayRecording_.header,
                       0x09f8 + static_cast<std::size_t>(selectedStage_) * 8,
                       player_.score);
        if (config_.specialStageFlag == 1) {
            writeReplayI64(replayRecording_.header,
                           0x0a48 + static_cast<std::size_t>(selectedStage_) * 8,
                           timeWindowElapsedFrames_);
        }
    }
    ReplayData replay = replayRecording_;
    if (!replay.recordable || config_.replayPlayback) {
        replay.clear();
        return replay;
    }
    writeReplayI32(replay.header, 0x0004,
                   static_cast<std::int32_t>(std::min<std::size_t>(
                       replay.inputRecords.size(),
                       static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()))));
    writeReplayI32(replay.header, 0x0044, selectedStage_);
    writeReplayI64(replay.header, 0x0058, player_.score);
    writeReplayI64(replay.header, 0x0060,
                   config_.specialStageFlag == 1 ? timeWindowElapsedFrames_ : 0);
    int routeCompletion = 0;
    if (stageComplete() && config_.routeMode == 1) {
        if (selectedStage_ == 8 || selectedStage_ == 10) {
            routeCompletion = 1;
        }
        else if (selectedStage_ == 9) {
            routeCompletion = 2;
        }
    }
    writeReplayI32(replay.header, 0x0064, routeCompletion);
    return replay;
}

void StageRuntime::spawnDueEvents() {
    updateStageBannerTextSound();
    if (selectedStage_ >= 1 && selectedStage_ <= 3) {
        updateEarlyStageApproachTimeline();
    }

    if (selectedStage_ == 1) {
        spawnStage01OriginalSchedule();
        return;
    }
    if (selectedStage_ == 2) {
        spawnStage02OriginalSchedule();
        return;
    }
    if (selectedStage_ == 3) {
        spawnStage03OriginalSchedule();
        return;
    }
    if (selectedStage_ == 4) {
        spawnStage04OriginalSchedule();
        return;
    }
    if (selectedStage_ == 5) {
        spawnStage05OriginalSchedule();
        updateLateStageTimeline();
        return;
    }
    if (selectedStage_ == 6) {
        spawnStage06OriginalSchedule();
        updateLateStageTimeline();
        return;
    }
    if (selectedStage_ == 7) {
        spawnStage07OriginalSchedule();
        updateLateStageTimeline();
        return;
    }
    if (selectedStage_ == 8) {
        spawnStage08OriginalSchedule();
        updateLateStageTimeline();
        return;
    }
    if (selectedStage_ == 9) {
        spawnStage09OriginalSchedule();
        updateLateStageTimeline();
        return;
    }
    if (selectedStage_ == 10) {
        spawnStage10OriginalSchedule();
        updateLateStageTimeline();
        return;
    }

    std::size_t eventCount = 0;
    const StageSpawnEvent* events = eventsForStage(selectedStage_, eventCount);
    for (std::size_t i = 0; i < eventCount; ++i) {
        const auto& event = events[i];
        if (event.frame == frame_) {
            spawnEnemy(event);
        }
    }
}

void StageRuntime::spawnStage01OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto spawn0bTop = [&](int hitPoints, int modulus, int base, const char* note) {
        spawn(0x0b, hitPoints, stageRandCoord(f, modulus, base), -20, note); // original y literal: 0xffffffec
    };
    auto spawn0bLeft = [&](int hitPoints, int modulus, int base, const char* note) {
        spawn(0x0b, hitPoints, -20, stageRandCoord(f, modulus, base), note); // original x literal: 0xffffffec
    };
    auto spawn0bRight = [&](int hitPoints, int modulus, int base, const char* note) {
        spawn(0x0b, hitPoints, 0x2e4, stageRandCoord(f, modulus, base), note);
    };
    auto spawn0cTop = [&](const char* note) {
        spawn(0x0c, 400, stageRandCoord(f, 0x191, 0xa0), -20, note); // original y literal: 0xffffffec
    };
    auto spawn0dLeft = [&](int hitPoints, int modulus, int base, const char* note) {
        spawn(0x0d, hitPoints, -20, stageRandCoord(f, modulus, base), note); // original x literal: 0xffffffec
    };
    auto spawn0dRight = [&](int hitPoints, int modulus, int base, const char* note) {
        spawn(0x0d, hitPoints, 0x2e4, stageRandCoord(f, modulus, base), note);
    };

    // Direct transcription of stage_01_gameplay_update_candidate @ 0x140118420.
    // All scheduled Stage 1 types below now route to their recovered helpers.
    if (f == 200) spawn(0x0a, 0x960, 0x1e0, 0x96, "S01 original line 27: 0x0a fixed early entry");
    if (f == 0x104) spawn(0x0a, 0x960, 0x0f0, 200, "S01 original line 30: 0x0a fixed follow-up");
    if (f == 0x15e) spawn(0x0a, 2000, 0x208, 100, "S01 original line 33: 0x0a fixed lane");
    if (f == 0x16d) spawn(0x0a, 2000, 0x168, 100, "S01 original line 36: 0x0a fixed lane");
    if (f == 0x17c) spawn(0x0a, 2000, 200, 100, "S01 original line 39: 0x0a fixed lane");

    if (f >= 600 && f < 600 + 0x50 && (f - 600) % 0x14 == 0) {
        spawn0bTop(400, 0x12d, 0x3c, "S01 original line 50: 0x0b top random entry");
    }
    if (f == 700) spawn(0x06, 5000, 0x1cc, 0, "S01 original line 54: common marker/emitter");
    if (f == 900) spawn(0x0e, 10000, 0x118, 0, "S01 original line 58: 0x0e long setpiece");
    if (f == 0x44c) spawn(0x0e, 10000, 0x1cc, 0, "S01 original line 62: 0x0e long setpiece");

    if (f >= 0x514 && f < 0x514 + 0x96 && (f - 0x514) % 0x14 == 0) {
        spawn0cTop("S01 original line 73: 0x0c top random entry");
    }
    if (f >= 0x60e && f < 0x60e + 300 && (f - 0x60e) % 0x1e == 0) {
        spawn0dRight(700, 0x65, 0xfa, "S01 original line 84: 0x0d right random entry");
    }
    if (f >= 0x78a && f < 0x78a + 0x78 && (f - 0x78a) % 0x14 == 0) {
        spawn0bLeft(500, 0xc9, 100, "S01 original line 95: 0x0b left random entry");
    }
    if (f >= 0x834 && f < 0x834 + 0x50 && (f - 0x834) % 0x14 == 0) {
        spawn0bRight(500, 0xc9, 100, "S01 original line 106: 0x0b right random entry");
    }
    if (f == 0x898) spawn(0x0f, 8000, 0x348, 0x96, "S01 original line 110: 0x0f side setpiece");
    if (f >= 0x8ca && f < 0x8ca + 200 && (f - 0x8ca) % 0x1e == 0) {
        spawn0dLeft(700, 0x65, 0xfa, "S01 original line 121: 0x0d left random entry");
    }
    if (f >= 0x9f6 && f < 0x9f6 + 100 && (f - 0x9f6) % 10 == 0) {
        spawn0bTop(400, 0x191, 0xa0, "S01 original line 132: 0x0b top burst");
    }
    if (f == 0xabe) {
        spawn(0x10, 40000, 0x168, 0x50, "S01 original line 137: 0x10 long setpiece; sets DAT_140e418cc");
        stage01GateFlag_ = true;
    }

    if (!stage01GateFlag_ && f >= 0xaf0 && f < 0xdde) {
        const int local = (f - 0xaf0) % 0x96;
        if (local < 100 && local % 0x0c == 0) {
            spawn0cTop("S01 original line 155: gated 0x0c top burst");
        }
    }
    // In FUN_140118420 this call remains inside the gate-open branch; when
    // 0x10 is still alive, control jumps past it to LAB_140118eb4.
    if (!stage01GateFlag_ && f == 0xe10) {
        spawn(0x0e, 7000, 0x168, 0, "S01 original line 159: gate-open 0x0e setpiece");
    }
    if (f >= 0xed8 && f < 0xf78 && (f - 0xed8) % 0x14 == 0) {
        spawn0bRight(500, 0xc9, 100, "S01 original line 173: later 0x0b right random entry");
    }
    if (f >= 0xf3c && f < 0xf3c + 200 && (f - 0xf3c) % 0x1e == 0) {
        spawn0dLeft(500, 0x65, 300, "S01 original line 185: later 0x0d left low entry");
    }
    if (f == 0x1068) spawn(0x0e, 7000, 0x1cc, 0, "S01 original line 189: later 0x0e setpiece");
    if (f == 0x1108) spawn(0x0f, 8000, -120, 100, "S01 original line 193: later 0x0f side setpiece; original x 0xffffff88");
    if (f >= 0x1194 && f < 0x1194 + 200) {
        const int local = (f - 0x1194) % 0x96;
        if (local < 100 && local % 0x10 == 0) {
            spawn0cTop("S01 original line 209: later gated 0x0c top burst");
        }
    }
    if (f >= 0x122a && f < 0x122a + 200 && (f - 0x122a) % 0x1e == 0) {
        spawn0dLeft(500, 0x65, 0xfa, "S01 original line 221: later 0x0d left random entry");
    }
    if (f >= 0x1324 && f < 0x1324 + 0x96 && (f - 0x1324) % 0x14 == 0) {
        spawn0bTop(400, 0xc9, 0x168, "S01 original line 233: final 0x0b top random entry");
    }
    if (f == 0x13ec) spawn(0x08, 5000, 0x104, 0, "S01 original line 237: ending marker/emitter");

    if (!stage01EndVisualQueued_ && f == stage01EndFrame_ - 300) {
        stage01EndVisualQueued_ = true;
    }
    if (f >= stage01EndFrame_ - 0x168 && f < stage01EndFrame_ - 0xf0) {
        stage01EndFlushed_ = true;
    }
    if (f == stage01EndFrame_) {
        flushStageForBossHandoff(0);
    }
    if (!stage01BossSpawned_ && f == stage01EndFrame_ + 0x3c) {
        spawn(0x138, 100000, 360, 200, "S01 boss handoff: endFrame + 0x3c entity 0x138");
        stage01BossSpawned_ = true;
        stage01GateFlag_ = true;
    }
}

void StageRuntime::spawnStage02OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto inWindow = [f](int start, int duration, int step) {
        const int local = f - start;
        return local >= 0 && local < duration && local % step == 0;
    };

    // Direct transcription of all 56 spawn-dispatch call sites in
    // stage_02_gameplay_update_candidate @ 0x140119640. Repeated call sites and
    // same-frame path arrays remain repeated here instead of being flattened.
    if (inWindow(0x10e, 0x78, 0x1e)) {
        spawn(0x19, 800, f * 4 - 0x398, -20, "S02 original line 53: 0x19 linear top wave");
    }
    if (inWindow(0x1cc, 0xbe, 0x0e)) {
        spawn(0x1a, 300, stageRandCoord(f, 0xfb, 0x104), -20,
              "S02 original line 64: 0x1a random top wave");
    }
    if (f == 700) {
        spawn(0x07, 5000, 0x104, 0, "S02 original line 68: common marker");
    }
    if (f == 800) {
        for (const auto& point : kStage02EarlyType1DPath) {
            spawn(0x1d, 0x6a4, point[0], point[1], "S02 original line 99: early 0x1d path point");
        }
        for (const auto& point : kStage02EarlyType1EPath) {
            spawn(0x1e, 0x834, point[0], point[1], "S02 original line 105: early 0x1e path point");
        }
        spawn(0x1f, 11000, 0x1e4, -0xdbe, "S02 original line 109: early 0x1f controller");
    }
    if (inWindow(0x546, 100, 0x12)) {
        spawn(0x0b, 400, 0x2e4, stageRandCoord(f, 0xc9, 100),
              "S02 original line 120: common right wave");
    }
    if (f == 0x6a4) {
        spawn(0x1b, 0x1130, 0x104, 0, "S02 original line 124: 0x1b anchor");
    }
    if (f == 0x708) {
        spawn(0x1b, 0x1130, 0x1cc, 0, "S02 original line 128: 0x1b anchor");
    }
    if (inWindow(0x708, 200, 0x19)) {
        spawn(0x0d, 400, -20, stageRandCoord(f, 0x65, 0x96),
              "S02 original line 139: common left wave");
    }
    if (inWindow(0x7ee, 100, 0x14)) {
        spawn(0x19, 500, stageRandCoord(f, 0xc9, 0x168), -20,
              "S02 original line 150: 0x19 random top wave");
    }
    if (inWindow(0x898, 0x32, 10)) {
        spawn(0x1a, 300, stageRandCoord(f, 0x12d, 0xa0), -20,
              "S02 original line 161: 0x1a random top wave");
    }
    if (f == 0x8ca) {
        spawn(0x1b, 0x1130, 0xf0, 0, "S02 original line 165: 0x1b anchor");
    }
    if (inWindow(0x92e, 100, 0x12)) {
        spawn(0x0b, 400, 0x2e4, stageRandCoord(f, 0x97, 100),
              "S02 original line 176: common right wave");
    }
    if (inWindow(0x992, 100, 0x12)) {
        spawn(0x0b, 400, -20, stageRandCoord(f, 0x97, 100),
              "S02 original line 187: common left wave");
    }
    if (f == 0xa28) {
        spawn(0x1c, 6000, 0x348, 0x32, "S02 original line 191: right 0x1c setpiece");
    }
    if (inWindow(0xaa0, 0xa0, 0x0f)) {
        spawn(0x1a, 300, stageRandCoord(f, 0x12d, 0xd2), -20,
              "S02 original line 202: 0x1a random top wave");
    }
    if (f == 0xb54) {
        spawn(0x1c, 6000, -120, 100, "S02 original line 206: left 0x1c setpiece");
    }
    if (inWindow(3000, 100, 0x0f)) {
        spawn(0x0b, 400, stageRandCoord(f, 0x191, 0xa0), -20,
              "S02 original line 217: common top wave");
    }
    if (inWindow(0xc4e, 100, 0x14)) {
        spawn(0x19, 700, stageRandCoord(f, 0x191, 0xa0), -20,
              "S02 original line 228: 0x19 random top wave");
    }
    if (f == 0xce4) {
        spawn(0x1b, 4000, 0x168, 0, "S02 original line 232: 0x1b anchor");
    }
    if (f == 0xd34) {
        spawn(0x1b, 4000, 0x1fe, 0, "S02 original line 236: 0x1b anchor");
    }
    if (inWindow(0xd7a, 100, 0x0f)) {
        spawn(0x1a, 300, stageRandCoord(f, 0x12d, 0xd2), -20,
              "S02 original line 247: 0x1a random top wave");
    }
    if (f == 0xe74) {
        spawn(0x1c, 5000, 0x348, 0x50, "S02 original line 251: right 0x1c setpiece");
    }
    if (inWindow(0xf64, 0x8c, 0x14)) {
        spawn(0x19, 700, stageRandCoord(f, 0x191, 0xa0), -20,
              "S02 original line 262: 0x19 random top wave");
    }
    if (inWindow(0x11bc, 0x6e, 0x0f)) {
        spawn(0x0b, 400, -20, stageRandCoord(f, 0x97, 100),
              "S02 original line 273: common left wave");
    }
    if (f == 0x1248) {
        spawn(0x1b, 0xe10, 0x1e0, 0, "S02 original line 277: 0x1b anchor");
    }
    if (f == 0x1298) {
        spawn(0x1b, 0xe10, 0xf0, 0, "S02 original line 281: 0x1b anchor");
    }
    if (inWindow(0x12d4, 0x28, 10)) {
        spawn(0x1a, 300, stageRandCoord(f, 0x12d, 0xd2), -20,
              "S02 original line 292: 0x1a random top wave");
    }
    if (f == 0x1306) {
        spawn(0x1c, 0x1068, 0x348, 0x50, "S02 original line 296: right 0x1c setpiece");
    }
    if (f == 0x136a) {
        spawn(0x1c, 0x1068, -120, 0x50, "S02 original line 300: left 0x1c setpiece");
    }
    if (f == 0x13ce) {
        spawn(0x1c, 0x1068, 0x348, 0x50, "S02 original line 304: right 0x1c setpiece");
    }
    if (inWindow(0x1482, 0x96, 8)) {
        spawn(0x1a, 300, stageRandCoord(f, 0x259, 0x3c), 0,
              "S02 original line 320: 0x1a wide random wave");
    }
    if (f == 0x14b4) {
        spawn(0x20, 0x2b5c, 0x168, -500, "S02 original line 326: 0x20 gated controller");
        stage02GateFlag_ = true;
    }

    if (!stage02GateFlag_ && f >= 0x157c && f < 0x157c + 900) {
        if (inWindow(0x1748, 0x154, 0x50)) {
            spawn(0x0a, 1000, stageRandCoord(f, 0x1f5, 0x6e), 0x32,
                  "S02 original line 339: gate-open common wave");
        }
        if ((f - 0x157c) % 0x10 == 0) {
            spawn(0x1a, 300, stageRandCoord(f, 0x259, 0x3c), 0,
                  "S02 original line 355: gate-open 0x1a wave");
        }
    }

    if (f == 0x1978 || f == 0x19dc || f == 0x1a40 || f == 0x1a68 || f == 0x1a90) {
        spawn(0x19, 500, 0x6e, -20, "S02 original line 362: six-lane 0x19 wall");
        spawn(0x19, 500, 0xd2, -20, "S02 original line 363: six-lane 0x19 wall");
        spawn(0x19, 500, 0x136, -20, "S02 original line 364: six-lane 0x19 wall");
        spawn(0x19, 500, 0x19a, -20, "S02 original line 365: six-lane 0x19 wall");
        spawn(0x19, 500, 0x1fe, -20, "S02 original line 366: six-lane 0x19 wall");
        spawn(0x19, 500, 0x262, -20, "S02 original line 367: six-lane 0x19 wall");
    }
    if (inWindow(0x1b1c, 0x3c, 0x0c)) {
        spawn(0x0b, 400, stageRandCoord(f, 0xfb, 0x6e), -20,
              "S02 original line 378: common top wave");
    }
    if (inWindow(7000, 0x3c, 0x0c)) {
        spawn(0x0b, 400, 0x2e4, stageRandCoord(f, 0x97, 100),
              "S02 original line 389: common right wave");
    }
    if (f == 0x1bbc) {
        spawn(0x1b, 0xc80, 0x230, 0, "S02 original line 393: 0x1b anchor");
    }
    if (f == 0x1bee) {
        spawn(0x1b, 0xc80, 0x168, 0, "S02 original line 397: 0x1b anchor");
    }
    if (f == 0x1c20) {
        spawn(0x1b, 0xc80, 0xa0, 0, "S02 original line 401: 0x1b anchor");
        for (const auto& point : kStage02LateType1DPath) {
            spawn(0x1d, 0x5dc, point[0], point[1], "S02 original line 427: late 0x1d path point");
        }
        for (const auto& point : kStage02LateType1EPath) {
            spawn(0x1e, 2000, point[0], point[1], "S02 original line 432: late 0x1e path point");
        }
        spawn(0x1f, 8000, 0x104, -810, "S02 original line 436: late 0x1f controller");
        spawn(0x1f, 8000, 0x1f9, -1425, "S02 original line 437: late 0x1f controller");
        spawn(0x1f, 8000, 0xe6, -1820, "S02 original line 438: late 0x1f controller");
    }
    if (inWindow(0x1d88, 0x8c, 0x10)) {
        spawn(0x19, 500, stageRandCoord(f, 0x15f, 0xa0), -20,
              "S02 original line 455: 0x19 random top wave");
    }
    if (f == 0x2080) {
        spawn(0x1c, 6000, -120, 100, "S02 original line 460: left 0x1c setpiece");
    }
    if (inWindow(0x21de, 0x82, 0x0c)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x12d, 0x6e), -20,
              "S02 original line 472: common top wave");
    }
    if (f == 0x238c) {
        spawn(0x08, 5000, 0x1cc, 0, "S02 original line 476: ending marker");
    }

    // UNK_140538ad8[2] is 9700. The original creates the Stage 2 root boss
    // exactly 60 frames after the stage-length handoff.
    if (f == 9700) {
        flushStageForBossHandoff(0);
    }
    if (f == 9700 + 0x3c) {
        spawn(0x139, 100000, 360, 180,
              "S02 boss handoff: endFrame + 0x3c entity 0x139");
    }
}

void StageRuntime::spawnStage03OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto inWindow = [f](int start, int duration, int step) {
        const int local = f - start;
        return local >= 0 && local < duration && local % step == 0;
    };

    // Direct transcription of all 50 FUN_14007b710 call sites in
    // stage_03_gameplay_update_candidate @ 0x14011b3d0. The three 0x2c
    // dispatcher sites intentionally remain path loops, matching the source.
    if (inWindow(0x10e, 200, 0x23)) {
        spawn(0x25, 700, stageRandCoord(f, 0x1e1, 0x78), -20,
              "S03 original line 43: 0x25 early random top wave");
    }
    if (f == 500) {
        spawn(0x26, 5000, 0x208, -20, "S03 original line 47: 0x26 fixed top anchor");
    }
    if (f == 600) {
        spawn(0x26, 5000, 200, -20, "S03 original line 51: 0x26 fixed top anchor");
    }
    if (inWindow(700, 0x96, 0x18)) {
        spawn(0x25, 600, stageRandCoord(f, 0x1a5, 0xb4), -20,
              "S03 original line 62: 0x25 random top wave");
    }
    if (f == 0x3ac) {
        spawn(0x27, 7000, 0x21c, 300, "S03 original line 66: 0x27 right setpiece");
    }
    if (f == 0x47e) {
        spawn(0x29, 7000, 0xb4, 0xfa, "S03 original line 70: 0x29 left setpiece");
    }
    if (f == 0x546) {
        spawn(0x07, 5000, 0x1cc, 0, "S03 original line 74: common marker");
    }
    if (f == 0x5dc) {
        for (const auto& point : kStage03EarlyType2CPath) {
            spawn(0x2c, 0x640, point[0], point[1],
                  "S03 original line 86: early 0x2c path point");
        }
        spawn(0x2d, 6000, 0x1ea, -600, "S03 original line 90: early 0x2d controller");
    }
    if (inWindow(0x5dc, 500, 0x30)) {
        spawn(0x25, 500, stageRandCoord(f, 0xc9, 0xa0), -20,
              "S03 original line 101: 0x25 path-overlap top wave");
    }
    if (inWindow(0x8fc, 0x96, 0x10)) {
        spawn(0x0b, 300, -20, stageRandCoord(f, 0x97, 0x96),
              "S03 original line 117: common left wave");
    }
    if (f == 0x992) {
        spawn(0x29, 6000, 0x1e0, 300, "S03 original line 122: 0x29 center setpiece");
    }
    if (inWindow(0xa8c, 0x96, 10)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 133: common top wave");
    }
    if (f == 0xb40) {
        spawn(0x2e, 65000, 0x168, -120, "S03 original line 138: gated 0x2e controller");
        stage03GateFlag_ = true;
    }

    // DAT_140e418cc is released by the original controller/helper chain. That
    // behavior is intentionally outside this schedule-only port.
    if (!stage03GateFlag_ && inWindow(3000, 0x514, 0x2d)) {
        spawn(0x25, 500, stageRandCoord(f, 0x141, 200), -20,
              "S03 original line 150: gate-open 0x25 top wave");
    }
    if (!stage03GateFlag_ && inWindow(3000, 0x514, 0x15)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 161: gate-open common top wave");
    }

    if (f == 0x1130) {
        for (const auto& point : kStage03MiddleType2CPath) {
            spawn(0x2c, 0x5dc, point[0], point[1],
                  "S03 original line 173: middle 0x2c path point");
        }
        spawn(0x2d, 0x1518, 0xd2, -225, "S03 original line 177: middle 0x2d controller");
        spawn(0x2d, 0x1518, 0x113, -580, "S03 original line 178: middle 0x2d controller");
        spawn(0x26, 5000, 0x21c, -20, "S03 original line 181: middle 0x26 anchor");
    }
    if (inWindow(0x12c0, 0x78, 0x0c)) {
        spawn(0x0b, 300, 0x2e4, stageRandCoord(f, 0x97, 0x96),
              "S03 original line 193: common right wave");
    }
    if (inWindow(0x141e, 200, 0x1e)) {
        spawn(0x25, 500, stageRandCoord(f, 0x12d, 0x104), -20,
              "S03 original line 204: 0x25 random top wave");
    }
    if (f == 0x14a0) {
        spawn(0x26, 4000, 0xd2, -20, "S03 original line 208: 0x26 fixed top anchor");
    }
    if (f == 0x1518) {
        spawn(0x27, 7000, 0x21c, 300, "S03 original line 212: 0x27 right setpiece");
    }
    if (f == 0x15e0) {
        spawn(0x2b, 12000, 0x1b8, 0, "S03 original line 216: 0x2b center setpiece");
    }
    if (inWindow(0x1676, 100, 0x0c)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x15f, 0x6e), -20,
              "S03 original line 227: common top wave");
    }
    if (f == 0x170c) {
        spawn(0x26, 5000, 0x168, -20, "S03 original line 231: 0x26 center anchor");
    }
    if (inWindow(0x173e, 0x82, 0x19)) {
        spawn(0x25, 500, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 242: 0x25 random top wave");
    }
    if (f == 0x17d4) {
        spawn(0x26, 5000, 200, -20, "S03 original line 246: 0x26 fixed top anchor");
    }
    if (inWindow(0x1806, 0x82, 0x14)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x12d, 0x104), -20,
              "S03 original line 257: common top wave");
    }
    if (f == 0x189c) {
        spawn(0x26, 5000, 0x208, -20, "S03 original line 261: 0x26 fixed top anchor");
    }
    if (inWindow(0x18ce, 0x82, 0x14)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x12d, 0xa0), -20,
              "S03 original line 272: common top wave");
    }
    if (f == 0x1946) {
        spawn(0x26, 4000, 0xf0, -20, "S03 original line 276: 0x26 left anchor");
    }
    if (f == 0x1964) {
        spawn(0x26, 4000, 0x1e0, -20, "S03 original line 280: 0x26 right anchor");
    }
    if (f == 0x19f0) {
        spawn(0x29, 4000, 0xf0, 300, "S03 original line 284: 0x29 left setpiece");
    }
    if (f == 0x1a2c) {
        spawn(0x29, 4000, 0x1e0, 0xfa, "S03 original line 288: 0x29 right setpiece");
    }
    if (inWindow(0x1acc, 0x5a, 0x0f)) {
        spawn(0x25, 400, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 299: 0x25 random top wave");
    }
    if (f == 7000) {
        spawn(0x2b, 12000, 0x118, 0, "S03 original line 303: 0x2b left setpiece");
    }
    if (inWindow(0x1bf8, 0xf0, 0x1e)) {
        spawn(0x25, 500, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 314: 0x25 random top wave");
    }
    if (f == 0x1c84) {
        for (const auto& point : kStage03LateType2CPath) {
            spawn(0x2c, 0x578, point[0], point[1],
                  "S03 original line 330: late 0x2c path point");
        }
        spawn(0x2d, 0x1068, 0xa5, -350, "S03 original line 334: late 0x2d controller");
        spawn(0x2d, 0x1068, 0x235, -605, "S03 original line 335: late 0x2d controller");
    }
    if (inWindow(0x1dec, 0x186, 0x32)) {
        spawn(0x25, 500, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 346: 0x25 random top wave");
    }
    if (inWindow(0x1fa4, 100, 0x14)) {
        spawn(0x25, 400, stageRandCoord(f, 0xc9, 0x104), -20,
              "S03 original line 357: 0x25 narrow top wave");
    }
    if (f == 0x2008) {
        spawn(0x26, 6000, 0x168, -20, "S03 original line 361: 0x26 center anchor");
    }
    if (f == 0x209e) {
        spawn(0x27, 6000, 0x1e0, 300, "S03 original line 365: 0x27 center setpiece");
    }
    if (f == 0x20d0) {
        spawn(0x29, 5000, 0xf0, 0xfa, "S03 original line 369: 0x29 left setpiece");
    }
    if (inWindow(0x2198, 100, 0x10)) {
        spawn(0x0b, 300, stageRandCoord(f, 0x191, 0xa0), -20,
              "S03 original line 385: common top wave");
    }
    if (f == 0x21fc) {
        spawn(0x2b, 12000, 0x1b8, 0, "S03 original line 390: 0x2b center setpiece");
    }
    if (f == 0x22f6) {
        spawn(0x08, 5000, 0x104, 0, "S03 original line 394: ending marker");
    }

    // The stage length table entry for Stage 3 is 9500. The original direct
    // stage-entity call follows 60 frames later at local position (360, 200).
    if (f == 9500) {
        flushStageForBossHandoff(0);
    }
    if (f == 9500 + 0x3c) {
        spawn(0x13a, 100000, 360, 200, "S03 boss handoff: endFrame + 0x3c entity 0x13a");
    }
}

void StageRuntime::updateStageBannerTextSound() const {
    if (config_.textDatabase == nullptr) {
        return;
    }

    const int language = std::clamp(config_.language, 0, 3);
    const int revealRate = language == 1 ? 1 : 2;
    const int group = std::clamp(config_.setupGroup, 0, 2);
    for (const auto& banner : kStageBanners) {
        if (banner.stage != selectedStage_) {
            continue;
        }
        const int textStart = banner.startFrame + 16;
        const int textEnd = banner.endFrame - 16;
        if (frame_ < textStart || frame_ >= textEnd) {
            continue;
        }

        const TextRecord* record = config_.textDatabase->find(
            language, stageBannerTextId(banner, group,
                                        config_.specialStageFlag != 0));
        if (record == nullptr) {
            continue;
        }
        const int line2Count = record->line2 == "NULL"
                                   ? 0
                                   : utf8CodePointCount(record->line2);
        const int totalCount = utf8CodePointCount(record->line1) + line2Count;
        const int textAge = frame_ - textStart;
        if ((textAge & 1) == 0 && textAge <= totalCount * revealRate) {
            playPlayerSound(banner.mode == 0 ? textSoundHandle_
                                             : text2SoundHandle_,
                            9);
        }
    }
}

void StageRuntime::updateEarlyStageApproachTimeline() {
    int endFrame = 0;
    switch (selectedStage_) {
    case 1: endFrame = 5700; break;
    case 2: endFrame = 9700; break;
    case 3: endFrame = 9500; break;
    default:
        earlyStageApproachAgeDraw_ = -1;
        return;
    }

    const int approachStart = endFrame - 300;
    earlyStageApproachAgeDraw_ = frame_ >= approachStart && frame_ <= endFrame
                                     ? frame_ - approachStart
                                     : -1;

    const int stageBgm = stageBgmHandles_[static_cast<std::size_t>(selectedStage_ - 1)];
    if (frame_ >= endFrame - 360 && frame_ < endFrame - 240 && stageBgm != -1) {
        const double fade = 1.0 - std::sin(
            static_cast<double>(frame_ - (endFrame - 360)) * kPi / 240.0);
        ChangeVolumeSoundMem(static_cast<int>(
                                 static_cast<double>(config_.bgmVolume) * 25.5 * fade),
                             stageBgm);
    }
    if (frame_ == approachStart) {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int frameIndex = 5 + group * 10;
        const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                       ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                       : -1;
        spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                         0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 300,
                         0xff, 0xff, 0xff, 0xff);
    }
    if (frame_ >= approachStart && frame_ < endFrame - 30 &&
        (frame_ - approachStart) % 20 == 0) {
        playPlayerSound(alertSoundHandle_, 0x14);
    }
}

void StageRuntime::spawnStage04OriginalSchedule() {
    const int f = frame_;
    earlyStageApproachAgeDraw_ = f >= 11400 && f <= 11700
                                    ? f - 11400
                                    : -1;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto spawnEvery = [&](int start, int duration, int step, int type, int hitPoints, int x, int y, const char* note) {
        const int local = f - start;
        if (local >= 0 && local < duration && local % step == 0) {
            spawn(type, hitPoints, x, y, note);
        }
    };
    const std::uint32_t scheduleRandom = stageScriptRandFromFrame(f);
    auto randCoord = [&](int modulus, int base) {
        return static_cast<int>(scheduleRandom % static_cast<std::uint32_t>(modulus)) + base;
    };
    auto spawn37 = [&](int modulusX, int baseX, const char* note) {
        // Both coordinates use DAT_140e9fd1c from the same frame-seeded
        // expression in FUN_14011cdd0.
        spawn(0x37, 500, randCoord(modulusX, baseX), randCoord(0x97, 400), note);
    };
    auto spawn36Left = [&](const char* note) { spawn(0x36, 400, -20, randCoord(0xc9, 300), note); };
    auto spawn36Right = [&](const char* note) { spawn(0x36, 400, 0x2e4, randCoord(0xc9, 300), note); };
    auto spawn0bTop = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, randCoord(modulus, base), -20, note); };
    auto spawn0bLeft = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, -20, randCoord(modulus, base), note); };
    auto spawn0bRight = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, 0x2e4, randCoord(modulus, base), note); };

    // Stage 04 schedule transcribed from stage_04_gameplay_update_candidate.
    // Its inline random-coordinate blocks are the frame-seeded expression in
    // stageScriptRandFromFrame, not the generic runtime RNG.
    if (f >= 0x96 && f < 0x96 + 0x15e && (f - 0x96) % 0x14 == 0) spawn37(0x191, 0xa0, "S04 original row 33: 0x37 random drifter");
    spawnEvery(700, 100, 8, 0x35, 0xfa, 0x2e4, 0x96, "S04 original row 45: 0x35 right wave");
    if (f == 800) spawn(0x38, 5000, 0x1e0, 0, "S04 original row 50: 0x38 center heavy");
    spawnEvery(900, 100, 8, 0x35, 0xfa, -20, 0x96, "S04 original row 60: 0x35 left wave");
    if (f == 1000) spawn(0x38, 5000, 0xf0, 0, "S04 original row 65: 0x38 left heavy");
    spawnEvery(0x44c, 100, 8, 0x35, 0xfa, 0x2e4, 400, "S04 original row 75: 0x35 right lower wave");
    spawnEvery(0x4d8, 100, 8, 0x35, 0xfa, -20, 400, "S04 original row 86: 0x35 left lower wave");
    if (f >= 0x4d8 && f < 0x4d8 + 0x50 && (f - 0x4d8) % 0x10 == 0) spawn37(0x191, 0xa0, "S04 original row 104: 0x37 drifter refresh");
    if (f == 0x578) spawn(7, 5000, 0x1cc, 0, "S04 original row 111: common marker");
    if (f == 0x60e) spawn(0x3d, 9000, -200, 0x96, "S04 original row 115: 0x3d left anchor");
    if (f >= 0x6d6 && f < 0x6d6 + 0x226 && (f - 0x6d6) % 0x78 == 0) spawn36Left("S04 original row 126: 0x36 left timed");
    if (f >= 0x712 && f < 0x712 + 0x1ea && (f - 0x712) % 0x78 == 0) spawn36Right("S04 original row 137: 0x36 right timed");
    if (f == 0x708) spawn(0x38, 4000, 500, 0, "S04 original row 141: 0x38 heavy slot");
    if (f == 0x76c) spawn(0x38, 4000, 0xdc, 0, "S04 original row 145: 0x38 heavy slot");
    if (f == 0x834) spawn(0x3d, 7000, 0x398, 0x96, "S04 original row 149: 0x3d right anchor");
    if (f == 0x8fc) spawn(0x38, 0x1194, 0xf0, 0, "S04 original row 153: 0x38 long left");
    if (f == 0x960) spawn(0x38, 0x1194, 0x1e0, 0, "S04 original row 157: 0x38 long center");
    spawnEvery(0x99c, 0x50, 8, 0x35, 0xfa, -20, 0x78, "S04 original row 167: 0x35 left high wave");
    if (f == 0xa5a) spawn(0x3a, 10000, -80, 200, "S04 original row 172: 0x3a carrier");
    if (f == 0xb22) spawn(0x39, 8000, 0x262, -80, "S04 original row 176: 0x39 carrier");
    if (f == 0xbea) spawn(0x39, 8000, 0x6e, -80, "S04 original row 180: 0x39 carrier");
    if (f == 0xcb2) spawn(0x3a, 8000, 800, 200, "S04 original row 184: 0x3a carrier");
    for (int base = 0xaf0; base < 0xaf0 + 600; base += 200) if (f >= base && f < base + 0x3c && (f - base) % 0x1e == 0) spawn0bTop(400, 0xf1, 0x168, "S04 original row 196: common top burst A");
    for (int base = 0xb54; base < 0xb54 + 500; base += 200) if (f >= base && f < base + 0x3c && (f - base) % 0x1e == 0) spawn0bTop(400, 0xf1, 0x78, "S04 original row 208: common top burst B");
    if (f >= 0xd34 && f < 0xd34 + 0x46 && (f - 0xd34) % 0x14 == 0) spawn36Left("S04 original row 219: 0x36 late left");
    if (f >= 0xd3e && f < 0xd3e + 0x3c && (f - 0xd3e) % 0x14 == 0) spawn36Right("S04 original row 230: 0x36 late right");
    if (f == 0xe10) {
        spawn(0x3f, 48000, 0x167, 0, "S04 original row 235: 0x3f controller");
        stage04GateFlag_ = true;
    }
    if (!stage04GateFlag_ &&
        ((f >= 0xe74 && f < 0x1158 && (f - 0xe74) % 8 == 0) ||
         (f >= 0x1194 && f < 0x1194 + 0x96 && (f - 0x1194) % 8 == 0))) {
        spawn(0x35, 200, 0x2e4, 0x8c, "S04 original row 256: gated boss-side right");
        spawn(0x35, 200, -20, 0x8c, "S04 original row 257: gated boss-side left");
    }
    if (f == 0x125c) spawn(0x3d, 9000, -200, 0x96, "S04 original row 262: 0x3d refresh");
    if (f >= 0x12f2 && f < 0x12f2 + 100 && (f - 0x12f2) % 0x0c == 0) spawn0bTop(0xfa, 0xf1, 0x168, "S04 original row 273: 0x0b short top");
    if (f >= 5000 && f < 5300 && (f - 5000) % 0x12 == 0) spawn37(0x1e1, 0x78, "S04 original row 285: 0x37 late drifter");
    if (f == 0x157c) spawn(0x38, 6000, 0x1cc, 0, "S04 original row 291: 0x38 late");
    if (f == 0x15ae) spawn(0x38, 6000, 0x104, 0, "S04 original row 295: 0x38 late");
    spawnEvery(0x1644, 100, 8, 0x35, 0xfa, 0x2e4, 400, "S04 original row 305: 0x35 right lower");
    if (f == 0x16a8) spawn(0x38, 5000, 0x1fe, 0, "S04 original row 310: 0x38 late heavy");
    spawnEvery(0x16f8, 100, 8, 0x35, 0xfa, -20, 400, "S04 original row 320: 0x35 left lower");
    if (f == 0x175c) spawn(0x38, 5000, 0xd2, 0, "S04 original row 325: 0x38 late heavy");
    spawnEvery(0x17ac, 0x6e, 8, 0x35, 0xfa, 0x2e4, 0x96, "S04 original row 335: 0x35 right mid");
    spawnEvery(0x1824, 0x6e, 8, 0x35, 0xfa, -20, 0x96, "S04 original row 346: 0x35 left mid");
    spawnEvery(0x189c, 100, 8, 0x35, 0xfa, 0x2e4, 0x15e, "S04 original row 357: 0x35 right low");
    if (f == 0x1900) { spawn(0x38, 4000, 0x1e0, 0, "S04 original row 362: 0x38 pair center"); spawn(0x38, 4000, 0xf0, 0, "S04 original row 363: 0x38 pair left"); }
    if (f == 0x1964 || f == 0x1bbc) spawn(0x39, 6000, 0x6e, -80, "S04 original row 367: 0x39 repeated carrier");
    if (f == 0x19fa || f == 0x1c52) spawn(0x39, 6000, 0x262, -80, "S04 original row 371: 0x39 repeated carrier");
    if (f == 0x1a90 || f == 0x1ce8) spawn(0x3a, 6000, -80, 200, "S04 original row 375: 0x3a repeated carrier");
    if (f == 0x1b26 || f == 0x1d7e) spawn(0x3a, 6000, 800, 200, "S04 original row 379: 0x3a repeated carrier");
    if (f >= 0x1996 && f < 0x1996 + 0x47e && (f - 0x1996) % 0x4b == 0) spawn37(0x1e1, 0x78, "S04 original row 391: 0x37 long wave");
    if (f >= 0x1e78 && f < 0x1e78 + 0x3c && (f - 0x1e78) % 0x10 == 0) spawn36Left("S04 original row 409: 0x36 left burst");
    if (f >= 0x1eb4 && f < 0x1eb4 + 0x3c && (f - 0x1eb4) % 10 == 0) spawn0bLeft(0xfa, 0x97, 0x96, "S04 original row 421: 0x0b left burst");
    if (f >= 0x1f18 && f < 0x1f18 + 0x3c && (f - 0x1f18) % 0x10 == 0) spawn36Right("S04 original row 437: 0x36 right burst");
    if (f >= 0x1f54 && f < 0x1f54 + 0x3c && (f - 0x1f54) % 10 == 0) spawn0bRight(0xfa, 0x97, 0x96, "S04 original row 449: 0x0b right burst");
    if (f == 0x2008) spawn(0x38, 5000, 0xdc, 0, "S04 original row 453: 0x38 final block");
    if (f == 0x203a) spawn(0x38, 5000, 500, 0, "S04 original row 457: 0x38 final block");
    spawnEvery(0x20d0, 0x96, 8, 0x35, 200, 0x2e4, 0x96, "S04 original row 467: 0x35 paired right");
    spawnEvery(0x20d0, 0x96, 8, 0x35, 200, -20, 0x96, "S04 original row 468: 0x35 paired left");
    if (f == 0x2198) spawn(0x3d, 7000, 0x398, 0x78, "S04 original row 473: 0x3d right high");
    if (f >= 0x21e8 && f < 0x21e8 + 0x50 && (f - 0x21e8) % 10 == 0) spawn0bLeft(0xfa, 0x97, 100, "S04 original row 484: 0x0b left top");
    if (f == 0x2260) spawn(0x3d, 7000, -200, 0x96, "S04 original row 488: 0x3d left");
    if (f >= 0x22b0 && f < 0x22b0 + 0x50 && (f - 0x22b0) % 10 == 0) spawn0bRight(0xfa, 0x97, 100, "S04 original row 499: 0x0b right top");
    if (f == 9000) spawn(0x3d, 7000, 0x398, 0xb4, "S04 original row 503: 0x3d right low");
    if (f == 0x238c) spawn(0x38, 5000, 200, 0, "S04 original row 507: 0x38 final source");
    spawnEvery(0x23dc, 100, 8, 0x35, 0xfa, 0x2e4, 0xb4, "S04 original row 517: 0x35 right final");
    if (f == 0x2454) spawn(0x3d, 7000, 0x398, 0x96, "S04 original row 522: 0x3d right final");
    spawnEvery(0x24a4, 100, 8, 0x35, 0xfa, -20, 0x15e, "S04 original row 532: 0x35 left final");
    if (f == 0x251c) spawn(0x3d, 7000, -200, 0x78, "S04 original row 537: 0x3d left high");
    if (f == 0x2580) spawn(0x39, 6000, 0x262, -80, "S04 original row 541: 0x39 final carrier");
    if (f >= 0x25d0 && f < 0x25d0 + 0x50 && (f - 0x25d0) % 10 == 0) spawn0bTop(0xfa, 0x259, 0x3c, "S04 original row 552: 0x0b wide top");
    if (f == 0x2648) {
        spawn(0x3f, 44000, 0x169, 0, "S04 original row 556: 0x3f second controller");
        stage04GateFlag_ = true;
    }
    if (f >= 0x28a0 && f < 0x28a0 + 300 && (f - 0x28a0) % 0x28 == 0) spawn0bTop(300, 0x1e1, 0x78, "S04 original row 568: 0x0b late wide");
    if (!stage04GateFlag_ && f >= 0x2648 && f - 0x2648 < 0x385 &&
        (f - 0x2648) % 100 == 0) {
        spawn(0x38, 5000, randCoord(0x169, 0xb4), 0,
              "S04 original row 580: gated random late");
    }
    if (f == 0x2a30) { spawn(0x38, 4000, 0x1e0, 0, "S04 original row 584: 0x38 end pair"); spawn(0x38, 4000, 0xf0, 0, "S04 original row 585: 0x38 end pair"); }
    spawnEvery(0x2a94, 0x5a, 8, 0x35, 200, 0x2e4, 0x78, "S04 original row 594: 0x35 ending right");
    spawnEvery(0x2aee, 0x5a, 8, 0x35, 200, -20, 0x96, "S04 original row 604: 0x35 ending left");
    if (f == 0x2b5c) spawn(8, 5000, 0x104, 0, "S04 original row 609: ending marker");

    // FUN_14011cdd0 fades the Stage 4 track across the 120-frame lead-in,
    // while FUN_140001060 owns the 300-frame approach presentation.
    if (f >= 11340 && f < 11460 && stage04BgmHandle_ != -1) {
        const double fade = 1.0 - std::sin(
            static_cast<double>(f - 11340) * kPi / 240.0);
        ChangeVolumeSoundMem(static_cast<int>(
                                 static_cast<double>(config_.bgmVolume) *
                                 25.5 * fade),
                             stage04BgmHandle_);
    }
    if (f >= 11400 && f < 11670 && (f - 11400) % 20 == 0) {
        playPlayerSound(alertSoundHandle_, 0x14);
    }
    if (f == 11400) {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int frameIndex = 5 + group * 10;
        const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                       ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                       : -1;
        spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                         0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 300,
                         0xff, 0xff, 0xff, 0xff);
    }

    // UNK_140538ad8[4] is 11700. At the endpoint the original calls the same
    // entity/projectile flush pair as Stages 1-3, then selects Boss2.
    if (f == 11700) {
        flushStageForBossHandoff(1);
    }
    if (f == 11700 + 0x3c) {
        spawn(0x13b, 100000, 360, 120,
              "S04 boss handoff: endFrame + 0x3c entity 0x13b");
    }
}

void StageRuntime::flushStageForBossHandoff(int bossBgmIndex) {
    const int flushHandle = effectMediumFrames_.size() > 4
                                ? effectMediumFrames_[4]
                                : -1;
    for (const auto& enemy : enemies_) {
        const double scale = static_cast<double>(enemy.radius) / 16.0;
        spawnStageEffect(0x0c, flushHandle, 200, 0x3d,
                         enemy.x, enemy.y, 0, 0.0, scale, scale, 16,
                         0xff, 0xff, 0xff, 0xff);
    }
    for (const auto& enemy : pendingEnemies_) {
        const double scale = static_cast<double>(enemy.radius) / 16.0;
        spawnStageEffect(0x0c, flushHandle, 200, 0x3d,
                         enemy.x, enemy.y, 0, 0.0, scale, scale, 16,
                         0xff, 0xff, 0xff, 0xff);
    }
    flushEnemyProjectilesToEffects();
    enemies_.clear();
    pendingEnemies_.clear();

    for (const int handle : stageBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle);
        }
    }
    for (const int handle : bossBgmHandles_) {
        if (handle != -1) {
            StopSoundMem(handle);
        }
    }
    if (bossBgmIndex >= 0 && bossBgmIndex < static_cast<int>(bossBgmHandles_.size())) {
        activeBossBgmIndex_ = bossBgmIndex;
        const int handle = bossBgmHandles_[static_cast<std::size_t>(bossBgmIndex)];
        if (handle != -1) {
            ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5), handle);
            PlaySoundMem(handle, DX_PLAYTYPE_LOOP, TRUE);
        }
    }
}

void StageRuntime::flushEnemyProjectilesToEffects() {
    for (const auto& projectile : enemyProjectiles_) {
        // FUN_14006c420 always reads raw +0x10/+0x14 and reconstructs the
        // radial point with +0x20 and +0x24. Integrated steering stores its raw
        // position in x/y; the radial helpers retain anchorX/anchorY instead.
        const bool integratedPosition =
            projectile.projectileId == 0x0c || projectile.projectileId == 0x0e ||
            (projectile.projectileId >= 0x23 && projectile.projectileId <= 0x27) ||
            projectile.projectileId == 0x2c || projectile.projectileId == 0x2d ||
            projectile.projectileId == 0x35 || projectile.projectileId == 0x36;
        const float rawX = integratedPosition ? projectile.x : projectile.anchorX;
        const float rawY = integratedPosition ? projectile.y : projectile.anchorY;
        const double radians = fixedAngleToRadiansDouble(projectile.angle16);
        const float effectX = rawX + static_cast<float>(
            std::cos(radians) * static_cast<double>(projectile.speedOrAccelHint));
        const float effectY = rawY + static_cast<float>(
            std::sin(radians) * static_cast<double>(projectile.speedOrAccelHint));
        spawnProjectileTerminalEffect(effectX, effectY);
    }
    enemyProjectiles_.clear();
}

void StageRuntime::spawnBossPhaseBreakFeedback(const StageEnemy& enemy,
                                               int countdown) {
    const int group = std::clamp(config_.setupGroup, 0, 2);
    const auto playerFrameHandle = [this, group](int offset) {
        const int index = offset + group * 10;
        return index >= 0 && index < static_cast<int>(playerFrameFrames_.size())
                   ? playerFrameFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };

    int portraitOffset = 7;
    if (countdown > 0) {
        if (bossPhaseRewardIndex_ == 0 || bossPhaseRewardIndex_ == 1) {
            const int effectType = bossPhaseRewardIndex_ == 0 ? 0x26 : 0x27;
            const int gaugeIndex = bossPhaseRewardIndex_ == 0 ? 4 : 5;
            const int gaugeHandle = gaugeIndex < static_cast<int>(bossGaugeFrames_.size())
                                        ? bossGaugeFrames_[static_cast<std::size_t>(gaugeIndex)]
                                        : -1;
            spawnStageEffect(effectType, gaugeHandle, 0, 0x73,
                             enemy.x, enemy.y, 0,
                             0.0, 1.0, 1.0, countdown / 15 + 60,
                             0xff, 0xff, 0xff, 0xff);
            portraitOffset = bossPhaseRewardIndex_ == 0 ? 6 : 2;
        }

        // FUN_140073e60 type 0x28 snapshots the remaining frame countdown and
        // renders it for 120 updates through the four small-number handles.
        spawnStageEffect(0x28, -1, 0, 0x72,
                         0.0f, 0.0f, 0,
                         static_cast<double>(countdown), 1.0, 1.0, 120,
                         0xff, 0xff, 0xff, 0xff);
    }

    spawnStageEffect(0x16, playerFrameHandle(portraitOffset), 0, 0x6f,
                     0.0f, 0.0f, 0,
                     0.0, 1.0, 1.0, 120,
                     0xff, 0xff, 0xff, 0xff);
}

void StageRuntime::spawnProjectileTerminalEffect(float x, float y) {
    const int handle = effectMediumFrames_.size() > 4
                           ? effectMediumFrames_[4]
                           : -1;
    spawnStageEffect(0x0c, handle, 200, 0x3d,
                     x, y, 0, 0.0, 0.6, 0.6, 0x10,
                     0xff, 0xff, 0xff, 0xff);
}

void StageRuntime::updateLateStageTimeline() {
    struct EndSpec {
        int endFrame;
        int bossType;
        int bossX;
        int bossY;
        int breaks;
        int bossBgmIndex;
    };
    EndSpec spec{};
    switch (selectedStage_) {
    case 5: spec = {11800, 0x13c, 360, 200, 6, 1}; break;
    case 6: spec = {12500, 0x13d, 480, 150, 5, 1}; break;
    case 7: spec = {12500, 0x13e, 360, 250, 5, 1}; break;
    case 8: spec = {21420, 0x13f, 360, 180, 6, 1}; break;
    case 9: spec = {17900, 0x140, 360, 190, 4, 2}; break;
    case 10: spec = {12000, 0x141, 360, 320, 16, 4}; break;
    default: return;
    }

    if (lateStageClearStarted_) {
        ++lateStageClearTimer_;
        if (lateStageClearTimer_ >= 360 && lateStageClearTimer_ <= 480) {
            const int fadeIndex = activeBossBgmIndex_ >= 0
                                      ? activeBossBgmIndex_
                                      : spec.bossBgmIndex;
            const int handle = bossBgmHandles_[static_cast<std::size_t>(fadeIndex)];
            if (handle != -1) {
                const double fade = 1.0 - std::sin(
                    static_cast<double>(lateStageClearTimer_ - 360) * kPi / 240.0);
                ChangeVolumeSoundMem(static_cast<int>(
                                         static_cast<double>(config_.bgmVolume) * 25.5 * fade),
                                     handle);
            }
        }
        if (lateStageClearTimer_ >= 480) {
            lateStageClearComplete_[static_cast<std::size_t>(selectedStage_)] = true;
        }
    }

    if (selectedStage_ == 10) {
        lateStageApproachAgeDraw_ = frame_ >= 50 && frame_ <= 350
                                        ? frame_ - 50
                                        : -1;
        if (frame_ == 1) {
            stage10GateFlag_ = true;
        }
        if (frame_ == 50) {
            const int group = std::clamp(config_.setupGroup, 0, 2);
            const int frameIndex = 5 + group * 10;
            const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                           ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                           : -1;
            spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                             0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 300,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (frame_ >= 50 && frame_ < 320 && (frame_ - 50) % 20 == 0) {
            playPlayerSound(alertSoundHandle_, 0x14);
        }
        if (frame_ == 320) {
            const int handle = stageBgmHandles_[9];
            if (handle != -1) {
                ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5), handle);
                PlaySoundMem(handle, DX_PLAYTYPE_LOOP, TRUE);
            }
        }
        if (frame_ == 350) {
            stage10GateFlag_ = false;
        }
        if (frame_ == spec.endFrame && !stage10TransitionStarted_) {
            stage10TransitionStarted_ = true;
        }
        return;
    }

    lateStageApproachAgeDraw_ = frame_ >= spec.endFrame - 300 && frame_ <= spec.endFrame
                                    ? frame_ - (spec.endFrame - 300)
                                    : -1;
    const int stageBgm = stageBgmHandles_[static_cast<std::size_t>(selectedStage_ - 1)];
    if (frame_ >= spec.endFrame - 360 && frame_ < spec.endFrame - 240 && stageBgm != -1) {
        const double fade = 1.0 - std::sin(
            static_cast<double>(frame_ - (spec.endFrame - 360)) * kPi / 240.0);
        ChangeVolumeSoundMem(static_cast<int>(
                                 static_cast<double>(config_.bgmVolume) * 25.5 * fade),
                             stageBgm);
    }
    if (frame_ == spec.endFrame - 300) {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int frameIndex = 5 + group * 10;
        const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                       ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                       : -1;
        spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                         0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 300,
                         0xff, 0xff, 0xff, 0xff);
    }
    if (frame_ >= spec.endFrame - 300 && frame_ < spec.endFrame - 30 &&
        (frame_ - (spec.endFrame - 300)) % 20 == 0) {
        playPlayerSound(alertSoundHandle_, 0x14);
    }
    if (frame_ == spec.endFrame) {
        flushStageForBossHandoff(spec.bossBgmIndex);
        lateStageBossBreaksRemaining_ = spec.breaks;
        lateStageBossPhaseIndex_ = 0;
        lateStageBossPhaseMode_ = 0;
        lateStageBossSpawned_ = false;
    }
    if (frame_ == spec.endFrame + 0x3c && !lateStageBossSpawned_) {
        spawnEnemy({frame_, spec.bossType, 100000, spec.bossX, spec.bossY,
                    "late-stage original boss handoff: endFrame + 0x3c"});
        lateStageBossSpawned_ = true;
    }
}

void StageRuntime::spawnEnemy(const StageSpawnEvent& event) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }
    StageEnemy enemy;
    enemy.entityId = nextEntityId_++;
    enemy.spawnType = event.spawnType;
    enemy.sourceHitPoints = event.hitPoints;
    enemy.sourceX = event.x;
    enemy.sourceY = event.y;
    enemy.sourceNote = event.sourceNote;
    const bool commonMarkerFamily = event.spawnType >= 0x06 && event.spawnType <= 0x09;
    const bool sharedEarlyEnemy = event.spawnType >= 0x0a && event.spawnType <= 0x0d;
    if (commonMarkerFamily || sharedEarlyEnemy || isStage01ObservedType(event.spawnType)) {
        enemy.updateCase = stage01UpdateCaseForSpawnType(event.spawnType);
        enemy.sourceDispatchKind = stage01DispatchKindForSpawnType(event.spawnType);
        enemy.sourceDispatchField = stage01DispatchFieldForSpawnType(event.spawnType);
        enemy.rewardWeight = std::max(1, enemy.sourceDispatchKind);
        enemy.activationDelay = 0;
    }
    enemy.x = static_cast<float>(event.x);
    enemy.y = static_cast<float>(event.y);
    enemy.originX = enemy.x;
    enemy.originY = enemy.y;
    enemy.angle = aimAtPlayer(enemy.x, enemy.y);
    const bool lateStageConfigured = configureLateStageEnemy(enemy, event);

    switch (event.spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        // stage_spawn_dispatch_candidate case 3 ignores the scheduled y and
        // constructs this family at y=-100 with kind 30/radius 90.
        enemy.y = -100.0f;
        enemy.originY = enemy.y;
        enemy.radius = 90;
        enemy.visualFrame = 8;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0;
        enemy.targetAngle16 = 0;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.targetable = false;
        break;
    case 0x09:
        enemy.radius = 0x28;
        enemy.visualFrame = 11;
        enemy.sourceDispatchKind = 0;
        enemy.rewardWeight = 0;
        enemy.sourceSpeed = 0.0;
        enemy.speed = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0a:
        // stage_spawn_dispatch_candidate case 4: the common constructor keeps
        // the scheduled position/HP, but uses kind 10, radius 50, angle
        // 0x4000, speed 1.0, and targetability flag 1 (invulnerable).
        enemy.updateCase = 0x04;
        enemy.sourceDispatchKind = 10;
        enemy.sourceDispatchField = 50;
        enemy.rewardWeight = 10;
        enemy.radius = 50;
        enemy.visualFrame = 12;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0b:
        // stage_spawn_dispatch_candidate case 5 preserves the scheduled
        // position/HP and constructs the shared FUN_14007d4e0 enemy.
        enemy.updateCase = 0x05;
        enemy.sourceDispatchKind = 5;
        enemy.sourceDispatchField = 30;
        enemy.rewardWeight = 5;
        enemy.radius = 30;
        enemy.visualFrame = 4;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0c:
        // stage_spawn_dispatch_candidate case 6 ignores the scheduled y and
        // constructs the shared FUN_14007dfb0 enemy at y=-20.
        enemy.updateCase = 0x06;
        enemy.sourceDispatchKind = 7;
        enemy.sourceDispatchField = 30;
        enemy.rewardWeight = 7;
        enemy.y = -20.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -20;
        enemy.radius = 30;
        enemy.visualFrame = 6;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0d:
        // stage_spawn_dispatch_candidate case 5 also constructs the shared
        // FUN_14007ea30 enemy; only its update case/body frame differ from 0x0b.
        enemy.updateCase = 0x07;
        enemy.sourceDispatchKind = 5;
        enemy.sourceDispatchField = 30;
        enemy.rewardWeight = 5;
        enemy.radius = 30;
        enemy.visualFrame = 9;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0e:
        // stage_spawn_dispatch_candidate case 7 ignores the schedule y and
        // constructs FUN_14007f2c0 at y=-100 with kind 24 and radius 80.
        enemy.updateCase = 0x08;
        enemy.sourceDispatchKind = 24;
        enemy.sourceDispatchField = 80;
        enemy.rewardWeight = 24;
        enemy.y = -100.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -100;
        enemy.radius = 80;
        enemy.visualFrame = 16;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x0f:
        // stage_spawn_dispatch_candidate case 8 keeps scheduled x/y/HP and
        // constructs FUN_140080170 with kind 30 and radius 90.
        enemy.updateCase = 0x09;
        enemy.sourceDispatchKind = 30;
        enemy.sourceDispatchField = 90;
        enemy.rewardWeight = 30;
        enemy.radius = 90;
        enemy.visualFrame = 22;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x10:
        enemy.hp = 36;
        enemy.radius = 150;
        enemy.visualFrame = 26;
        enemy.vy = 0.25f;
        // FUN_140080fb0 clears +0x54 only when the 120-frame entry ends.
        enemy.targetable = false;
        break;
    case 0x11:
        enemy.hp = 18;
        enemy.radius = 22;
        enemy.visualFrame = 32;
        enemy.activationDelay = 0;
        break;
    case 0x138:
        enemy.hp = 100000;
        enemy.radius = 160;
        enemy.visualFrame = 0;
        enemy.sourceDispatchKind = 0;
        enemy.sourceDispatchField = 160;
        enemy.angle = 0.0f;
        enemy.speed = 0.3f;
        enemy.sourceSpeed = 0.3;
        enemy.sourceAngle16 = 0;
        enemy.targetAngle16 = 0;
        enemy.rewardWeight = 0;
        enemy.targetable = false;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        stage01BossPhaseMode_ = 0;
        stage01BossMaxHp_ = 100000;
        stage01BossCountdown_ = 0;
        stage01BossBreaksRemaining_ = 3;
        stage01BossPhaseIndex_ = 0;
        stage01GateFlag_ = true;
        stage01ClearStarted_ = false;
        stage01ClearTransition_ = false;
        stage01ClearComplete_ = false;
        break;
    case 0x139:
        // FUN_140119640 -> FUN_140078a00: kind 0, position (360,180),
        // angle 0, speed 0.3, radius 180, initially untargetable.
        enemy.hp = config_.difficulty == 0 ? 80000 : 100000;
        enemy.maxHp = enemy.hp;
        enemy.drawHp = enemy.hp;
        enemy.updateCase = 0xa0;
        enemy.sourceDispatchKind = 0;
        enemy.sourceDispatchField = 180;
        enemy.radius = 180;
        enemy.visualFrame = 0;
        enemy.sourceAngle16 = 0;
        enemy.secondaryAngle16 = 0;
        enemy.targetAngle16 = 0;
        enemy.angle = 0.0f;
        enemy.sourceSpeed = 0.3;
        enemy.speed = 0.3f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 0;
        enemy.targetable = false;
        stage02BossPhaseMode_ = 0;
        stage02BossMaxHp_ = enemy.hp;
        stage02BossCountdown_ = 0;
        stage02BossCountdownDraw_ = 0;
        stage02BossBreaksRemaining_ = 4;
        stage02BossPhaseIndex_ = 0;
        stage02BossTargetX_ = 360.0f;
        stage02BossTargetY_ = 180.0f;
        stage02GateFlag_ = true;
        stage02ClearStarted_ = false;
        stage02ClearTransition_ = false;
        stage02ClearComplete_ = false;
        break;
    case 0x19:
    case 0x1a:
        // stage_spawn_dispatch_candidate @ 0x14007bc4f/0x14007b869.
        enemy.updateCase = event.spawnType == 0x19 ? 0x0e : 0x0f;
        enemy.sourceDispatchKind = event.spawnType == 0x19 ? 6 : 5;
        enemy.sourceDispatchField = event.spawnType == 0x19 ? 40 : 30;
        enemy.rewardWeight = enemy.sourceDispatchKind;
        enemy.radius = enemy.sourceDispatchField;
        enemy.visualFrame = event.spawnType == 0x19 ? 15 : 18;
        if (event.spawnType == 0x1a) {
            // This dispatch branch ignores the schedule y argument.
            enemy.y = -20.0f;
            enemy.originY = enemy.y;
            enemy.sourceY = -20;
        }
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x1b:
        // stage_spawn_dispatch_candidate @ 0x14007b899.
        enemy.updateCase = 0x10;
        enemy.sourceDispatchKind = 20;
        enemy.sourceDispatchField = 80;
        enemy.rewardWeight = 20;
        enemy.y = -100.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -100;
        enemy.radius = 80;
        enemy.visualFrame = 34;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x1c:
        // stage_spawn_dispatch_candidate @ 0x14007ba77.
        enemy.updateCase = 0x11;
        enemy.sourceDispatchKind = 30;
        enemy.sourceDispatchField = 60;
        enemy.rewardWeight = 30;
        enemy.radius = 60;
        enemy.visualFrame = 36;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x1d:
    case 0x1e:
        // stage_spawn_dispatch_candidate @ 0x14007bde7/0x14007bb47.
        enemy.updateCase = event.spawnType == 0x1d ? 0x12 : 0x13;
        enemy.sourceDispatchKind = event.spawnType == 0x1d ? 5 : 7;
        enemy.sourceDispatchField = 40;
        enemy.rewardWeight = enemy.sourceDispatchKind;
        enemy.radius = 40;
        enemy.visualFrame = event.spawnType == 0x1d ? 19 : 39;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x1f:
        // stage_spawn_dispatch_candidate @ 0x14007b927.
        enemy.updateCase = 0x14;
        enemy.sourceDispatchKind = 50;
        enemy.sourceDispatchField = 100;
        enemy.rewardWeight = 50;
        enemy.radius = 100;
        enemy.visualFrame = 43;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        break;
    case 0x20:
        // stage_spawn_dispatch_candidate case 9 constructs this controller
        // with entity kind 120 and collision radius 150.
        enemy.updateCase = 0x15;
        enemy.sourceDispatchKind = 120;
        enemy.sourceDispatchField = 150;
        enemy.radius = 150;
        enemy.visualFrame = 45;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 120;
        enemy.targetable = false;
        break;
    case 0x25:
        enemy.updateCase = 0x19;
        enemy.sourceDispatchKind = 8;
        enemy.sourceDispatchField = 40;
        enemy.y = -20.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -20;
        enemy.radius = 40;
        enemy.visualFrame = 24;
        enemy.sourceAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 8;
        enemy.targetable = false;
        break;
    case 0x26:
        enemy.updateCase = 0x1a;
        enemy.sourceDispatchKind = 20;
        enemy.sourceDispatchField = 90;
        enemy.y = -100.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -100;
        enemy.radius = 90;
        enemy.visualFrame = 49;
        enemy.sourceAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 20;
        enemy.targetable = false;
        break;
    case 0x27:
    case 0x29:
        enemy.updateCase = event.spawnType == 0x27 ? 0x1b : 0x1d;
        enemy.sourceDispatchKind = 24;
        enemy.sourceDispatchField = 70;
        enemy.radius = 70;
        enemy.visualFrame = event.spawnType == 0x27 ? 51 : 53;
        enemy.sourceAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 24;
        enemy.targetable = false;
        break;
    case 0x2b:
        enemy.updateCase = 0x1e;
        enemy.sourceDispatchKind = 64;
        enemy.sourceDispatchField = 100;
        enemy.y = -150.0f;
        enemy.originY = enemy.y;
        enemy.sourceY = -150;
        enemy.radius = 100;
        enemy.visualFrame = 10;
        enemy.sourceAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 64;
        enemy.targetable = false;
        break;
    case 0x2c:
        enemy.updateCase = 0x1f;
        enemy.sourceDispatchKind = 7;
        enemy.sourceDispatchField = 40;
        enemy.radius = 40;
        enemy.visualFrame = 25;
        enemy.sourceAngle16 = 0xc000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 7;
        enemy.targetable = false;
        break;
    case 0x2d:
        enemy.updateCase = 0x20;
        enemy.sourceDispatchKind = 30;
        enemy.sourceDispatchField = 80;
        enemy.radius = 80;
        enemy.visualFrame = 58;
        enemy.sourceAngle16 = 0xc000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 30;
        enemy.targetable = false;
        break;
    case 0x2e:
        enemy.updateCase = 0x21;
        enemy.sourceDispatchKind = 120;
        enemy.sourceDispatchField = 240;
        enemy.radius = 240;
        enemy.visualFrame = 11;
        enemy.sourceAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 120;
        enemy.targetable = false;
        break;
    case 0x35:
        enemy.hp = 18;
        enemy.radius = 30;
        enemy.visualFrame = 32;
        enemy.speed = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 5;
        enemy.targetable = false;
        break;
    case 0x36:
    case 0x37:
        enemy.hp = 14;
        enemy.radius = 40;
        enemy.visualFrame = event.spawnType == 0x36 ? 34 : 40;
        enemy.speed = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 5;
        enemy.targetable = false;
        break;
    case 0x38:
        enemy.hp = 80;
        enemy.y = -100.0f;
        enemy.originY = -100.0f;
        enemy.sourceY = -100;
        enemy.radius = 90;
        enemy.visualFrame = 63;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 24;
        enemy.targetable = false;
        break;
    case 0x39:
    case 0x3a:
        enemy.hp = 50;
        enemy.radius = 60;
        enemy.visualFrame = 68;
        enemy.speed = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 50;
        enemy.targetable = false;
        break;
    case 0x3b:
    case 0x3c:
        enemy.hp = 50;
        enemy.radius = 40;
        enemy.visualFrame = event.spawnType == 0x3b ? 70 : 71;
        enemy.speed = 2.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = event.spawnType == 0x3b ? 5 : 10;
        enemy.targetable = true;
        break;
    case 0x3d:
        enemy.radius = 160;
        enemy.visualFrame = 73;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 48;
        enemy.targetable = false;
        break;
    case 0x3f:
        enemy.radius = 240;
        enemy.visualFrame = 74;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 120;
        enemy.targetable = false;
        break;
    case 0x13a:
        // FUN_14011b3d0 -> FUN_140078a00: kind 0, position (360,200),
        // angle 0, speed 0.5, radius 150, initially untargetable.
        enemy.updateCase = 0xa1;
        enemy.sourceDispatchKind = 0;
        enemy.sourceDispatchField = 150;
        enemy.radius = 150;
        enemy.visualFrame = 0;
        enemy.sourceAngle16 = 0;
        enemy.secondaryAngle16 = 0;
        enemy.targetAngle16 = 0;
        enemy.angle = 0.0f;
        enemy.sourceSpeed = 0.5;
        enemy.speed = 0.5f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 0;
        enemy.targetable = false;
        stage03BossPhaseMode_ = 0;
        stage03BossMaxHp_ = 100000;
        stage03BossCountdown_ = 0;
        stage03BossCountdownDraw_ = 0;
        stage03BossBreaksRemaining_ = 4;
        stage03BossPhaseIndex_ = 0;
        stage03BossTargetX_ = 360.0f;
        stage03BossTargetY_ = 200.0f;
        stage03GateFlag_ = true;
        stage03ClearStarted_ = false;
        stage03ClearTransition_ = false;
        stage03ClearComplete_ = false;
        break;
    case 0x13b:
        // FUN_14011cdd0 -> FUN_140078a00: kind 0, position (360,120),
        // angle 0, speed 0.3, radius 200, initially untargetable.
        enemy.updateCase = 0xa2;
        enemy.sourceDispatchKind = 0;
        enemy.sourceDispatchField = 200;
        enemy.radius = 200;
        enemy.visualFrame = 0;
        enemy.sourceAngle16 = 0;
        enemy.secondaryAngle16 = 0;
        enemy.targetAngle16 = 0;
        enemy.angle = 0.0f;
        enemy.sourceSpeed = 0.3;
        enemy.speed = 0.3f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.rewardWeight = 0;
        enemy.targetable = false;
        stage04BossPhaseMode_ = 0;
        stage04BossMaxHp_ = 100000;
        stage04BossCountdown_ = 0;
        stage04BossCountdownDraw_ = 0;
        stage04BossBreaksRemaining_ = 4;
        stage04BossPhaseIndex_ = 0;
        stage04BossTargetX_ = 360.0f;
        stage04BossTargetY_ = 200.0f;
        stage04GateFlag_ = true;
        stage04ClearStarted_ = false;
        stage04ClearTransition_ = false;
        stage04ClearComplete_ = false;
        break;
    default:
        if (!lateStageConfigured) {
            enemy.hp = 12;
            enemy.radius = 28;
            enemy.visualFrame = 8;
            enemy.speed = 1.2f;
        }
        break;
    }

    // stage_entity_spawn_candidate copies param2 into +0x1c/+0x20. Only
    // difficulty 0 scales it by DAT_140539f28 (0.8), except spawn type 0x153.
    const double hpScale = config_.difficulty == 0 && event.spawnType != 0x153 ? 0.8 : 1.0;
    enemy.hp = std::max(1, static_cast<int>(static_cast<double>(event.hitPoints) * hpScale));
    enemy.maxHp = enemy.hp;
    enemy.drawHp = enemy.hp;

    enemies_.push_back(enemy);
}

void StageRuntime::spawnStage01Child(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }
    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x11;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceNote = note;
    child.updateCase = stage01UpdateCaseForSpawnType(0x11);
    // FUN_140080fb0 bypasses the schedule dispatcher and calls
    // FUN_140078a00 directly with kind 0x28 and radius 0x3c.
    child.sourceDispatchKind = 0x28;
    child.sourceDispatchField = 0x3c;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.x = parent.x;
    child.y = parent.y;
    child.originX = offsetX;
    child.originY = offsetY;
    child.angle = parent.angle;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.hp = std::max(1, static_cast<int>(hitPoints * (config_.difficulty == 0 ? 0.8 : 1.0)));
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = 0x3c;
    child.rewardWeight = 0x28;
    child.visualFrame = 32 + (childIndex % 2);
    child.activationDelay = 0;
    child.helperState = 0;
    child.targetable = false;
    pendingEnemies_.push_back(child);
}

bool StageRuntime::spawnStage01BossChild(StageEnemy& parent, int spawnType, int childIndex,
                                         float offsetX, float offsetY, int hitPoints, const char* note) {
    if (!isStage01BossChildType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceNote = note;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x138;
    child.childIndex = childIndex;
    child.sourceDispatchKind = 10;
    child.sourceDispatchField = 50;
    child.rewardWeight = 10;
    child.x = offsetX;
    child.y = offsetY;
    child.originX = offsetX;
    child.originY = offsetY;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.targetAngle16 = 0;
    child.angle = fixedAngleToRadians(child.sourceAngle16);
    child.speed = 1.0f;
    child.sourceSpeed = 1.0;
    child.radius = 50;
    child.visualFrame = 11;
    child.activationDelay = 0;
    child.targetable = false;
    child.helperState = 0;
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = std::max(1, static_cast<int>(static_cast<double>(hitPoints) * hpScale));
    child.maxHp = child.hp;
    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

bool StageRuntime::spawnStage01BossDecoration(StageEnemy& parent, int spawnType,
                                              float offsetX, float offsetY,
                                              const char* note) {
    if (!isStage01BossDecorationType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.updateCase = 0x0c;
    child.sourceHitPoints = 99999999;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceNote = note;
    child.sourceDispatchKind = 0;
    child.sourceDispatchField = 100;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.x = offsetX;
    child.y = offsetY;
    child.originX = offsetX;
    child.originY = offsetY;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.targetAngle16 = 0x4000;
    child.angle = fixedAngleToRadians(child.sourceAngle16);
    child.sourceSpeed = 1.0;
    child.speed = 1.0f;
    child.hp = config_.difficulty == 0 ? 79999999 : 99999999;
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = 100;
    child.rewardWeight = 0;
    child.activationDelay = 0;
    child.targetable = false;
    child.helperState = 0;
    child.helperTimer = 0;
    pendingEnemies_.push_back(child);
    return true;
}

void StageRuntime::spawnStage02Type21Child(const StageEnemy& parent, int childIndex, float x, float yOffset) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    // FUN_140088110 creates these through stage_entity_spawn_candidate.
    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x21;
    child.sourceHitPoints = 0x0c80;
    child.sourceX = static_cast<int>(std::lround(x));
    child.sourceY = static_cast<int>(std::lround(parent.y + yOffset));
    child.sourceNote = "S02 FUN_140088110 type 0x21 child";
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x20;
    child.childIndex = childIndex;
    child.updateCase = 0x16;
    child.sourceDispatchKind = 0x20;
    child.sourceDispatchField = 0x32;
    child.x = x;
    child.y = parent.y + yOffset;
    child.originX = child.x;
    child.originY = child.y;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.targetAngle16 = 0x4000;
    child.angle = fixedAngleToRadians(child.sourceAngle16);
    child.sourceSpeed = 0.0;
    child.speed = 0.0f;
    child.hp = std::max(1, static_cast<int>(0x0c80 * (config_.difficulty == 0 ? 0.8 : 1.0)));
    child.maxHp = child.hp;
    child.radius = 0x32;
    child.visualFrame = 44;
    child.activationDelay = 0;
    child.rewardWeight = 0x20;
    child.targetable = false;
    pendingEnemies_.push_back(child);
}

bool StageRuntime::spawnStage02BossChild(StageEnemy& parent, int spawnType, int childIndex,
                                         float offsetOrRadiusX, float offsetY,
                                         std::uint16_t orbitAngle, const char* note) {
    if ((spawnType < 0x22 || spawnType > 0x24) ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.updateCase = spawnType == 0x22 ? 0x17 : 0x18;
    child.sourceHitPoints = 99999999;
    child.sourceDispatchKind = 10;
    child.sourceDispatchField = 50;
    child.sourceNote = note;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x139;
    child.childIndex = childIndex;
    child.sourceAngle16 = orbitAngle;
    child.secondaryAngle16 = orbitAngle;
    child.targetAngle16 = orbitAngle;
    child.angle = fixedAngleToRadians(orbitAngle);
    child.speed = spawnType == 0x22 ? 1.0f : 0.0f;
    child.sourceSpeed = child.speed;
    child.hp = 99999999;
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = 50;
    child.activationDelay = 0;
    child.rewardWeight = 0;
    child.targetable = false;

    if (spawnType == 0x22) {
        child.originX = offsetOrRadiusX;
        child.originY = offsetY;
        child.x = parent.x + offsetOrRadiusX;
        child.y = parent.y + offsetY;
        child.visualFrame = 39 + childIndex % 4;
    }
    else {
        child.originX = offsetOrRadiusX;
        child.originY = 0.0f;
        const double orbitRadians = fixedAngleToRadiansDouble(orbitAngle);
        child.x = parent.x + static_cast<float>(std::cos(orbitRadians) * offsetOrRadiusX);
        child.y = parent.y + static_cast<float>(std::sin(orbitRadians) * offsetOrRadiusX);
        child.visualFrame = 23;
    }

    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::spawnStage01MarkerSatellite(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int hitPoints, const char* note) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }
    (void)offsetX;
    (void)offsetY;

    StageEnemy satellite;
    satellite.entityId = nextEntityId_++;
    satellite.spawnType = 0x09;
    satellite.sourceHitPoints = hitPoints;
    satellite.sourceX = 0;
    satellite.sourceY = 0;
    satellite.sourceNote = note;
    satellite.updateCase = stage01UpdateCaseForSpawnType(0x09);
    satellite.sourceDispatchKind = 0;
    satellite.sourceDispatchField = 0x28;
    satellite.rewardWeight = 0;
    satellite.parentEntityId = parent.entityId;
    satellite.parentSpawnType = parent.spawnType;
    satellite.childIndex = childIndex;
    satellite.x = 0.0f;
    satellite.y = 0.0f;
    satellite.originX = 0.0f;
    satellite.originY = 0.0f;
    satellite.angle = 0.0f;
    satellite.sourceAngle16 = scriptRandomAngle(
        static_cast<std::uint32_t>(frame_ + childIndex));
    satellite.secondaryAngle16 = 0;
    satellite.targetAngle16 = 0;
    satellite.sourceSpeed = 0.0;
    satellite.speed = 0.0f;
    satellite.hp = std::max(1, static_cast<int>(hitPoints * (config_.difficulty == 0 ? 0.8 : 1.0)));
    satellite.maxHp = satellite.hp;
    satellite.drawHp = satellite.hp;
    satellite.radius = 0x28;
    satellite.visualFrame = 11;
    satellite.activationDelay = 0;
    satellite.helperState = 0;
    satellite.targetable = false;
    pendingEnemies_.push_back(satellite);
}

void StageRuntime::spawnStage03Satellite(const StageEnemy& parent, int spawnType, int childIndex,
                                         float offsetX, float offsetY, int angle16) {
    if ((spawnType != 0x28 && spawnType != 0x2a) ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.sourceHitPoints = 99999999;
    child.sourceX = static_cast<int>(offsetX);
    child.sourceY = static_cast<int>(offsetY);
    child.sourceNote = spawnType == 0x28
                           ? "S03 FUN_14008a970 type 0x28 satellite"
                           : "S03 FUN_14008b480 type 0x2a satellite";
    child.updateCase = 0x1c;
    child.sourceDispatchKind = 1;
    child.sourceDispatchField = 20;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.x = parent.x;
    child.y = parent.y;
    child.originX = offsetX;
    child.originY = offsetY;
    child.sourceAngle16 = normalizeAngle16(angle16);
    child.secondaryAngle16 = child.sourceAngle16;
    child.sourceSpeed = 0.0;
    child.hp = 99999999;
    child.maxHp = 99999999;
    child.radius = 20;
    child.visualFrame = spawnType == 0x28 ? 27 : 28;
    child.activationDelay = 0;
    child.rewardWeight = 1;
    child.targetable = false;
    pendingEnemies_.push_back(child);
}

void StageRuntime::spawnStage03Type2FChild(const StageEnemy& parent) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x2f;
    child.sourceHitPoints = parent.maxHp;
    child.sourceX = 0;
    child.sourceY = 240;
    child.sourceNote = "S03 FUN_14008efc0 shared-HP type 0x2f child";
    child.updateCase = 0x22;
    child.sourceDispatchKind = 1;
    child.sourceDispatchField = 70;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x2e;
    child.x = parent.x;
    child.y = parent.y;
    child.originX = 0.0f;
    child.originY = 240.0f;
    child.sourceAngle16 = 0x4000;
    child.secondaryAngle16 = 0x4000;
    child.sourceSpeed = 0.0;
    child.hp = parent.maxHp;
    child.maxHp = parent.maxHp;
    child.radius = 70;
    child.visualFrame = 60;
    child.activationDelay = 0;
    child.rewardWeight = 1;
    child.targetable = false;
    pendingEnemies_.push_back(child);
}

bool StageRuntime::spawnStage03BossChild(StageEnemy& parent, int spawnType,
                                         int childIndex, float offsetOrTargetX,
                                         float offsetOrTargetY, int hitPoints,
                                         int kind, double speed, int radius,
                                         std::uint16_t angle16, const char* note) {
    if (!isStage03BossChildType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(offsetOrTargetX));
    child.sourceY = static_cast<int>(std::lround(offsetOrTargetY));
    child.sourceNote = note;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x13a;
    child.childIndex = childIndex;
    child.x = parent.x;
    child.y = parent.y;
    child.originX = offsetOrTargetX;
    child.originY = offsetOrTargetY;
    child.markerDrawX = offsetOrTargetX;
    child.markerDrawY = offsetOrTargetY;
    child.sourceAngle16 = angle16;
    child.secondaryAngle16 = angle16;
    child.targetAngle16 = angle16;
    child.angle = fixedAngleToRadians(angle16);
    child.sourceSpeed = speed;
    child.speed = static_cast<float>(speed);
    child.sourceDispatchKind = kind;
    child.sourceDispatchField = radius;
    child.rewardWeight = kind;
    child.radius = radius;
    child.activationDelay = 0;
    child.targetable = false;
    child.updateCase = spawnType == 0x30 ? 0x23
                         : (spawnType == 0x31 ? 0x24
                            : (spawnType <= 0x33 ? 0x25 : 0x26));
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = std::max(1, static_cast<int>(static_cast<double>(hitPoints) * hpScale));
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    pendingEnemies_.push_back(child);
    return true;
}

void StageRuntime::spawnDelayedOwnerDamageNode(int hitPoints,
                                               int ownerEntityId,
                                               int ownerSpawnType,
                                               const char* note) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = 0x153;
    node.sourceHitPoints = hitPoints;
    node.sourceX = -100;
    node.sourceY = -100;
    node.sourceNote = note;
    node.updateCase = 0xb5;
    node.sourceDispatchKind = 1;
    node.sourceDispatchField = 10;
    node.parentEntityId = ownerEntityId;
    node.parentSpawnType = ownerSpawnType;
    node.x = -100.0f;
    node.y = -100.0f;
    node.originX = -100.0f;
    node.originY = -100.0f;
    node.sourceAngle16 = 0x4000;
    node.sourceSpeed = 1.0;
    node.speed = 1.0f;
    node.hp = std::max(1, hitPoints);
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = 10;
    node.activationDelay = 0;
    node.rewardWeight = 1;
    node.targetable = false;
    pendingEnemies_.push_back(node);
}

void StageRuntime::spawnStage03DeathNode(const StageEnemy& enemy, int hitPoints,
                                         int ownerEntityId) {
    (void)enemy;
    spawnDelayedOwnerDamageNode(
        hitPoints, ownerEntityId, 0x13a,
        "S03 child death delayed-damage node 0x153");
}

bool StageRuntime::spawnStage04BossChild(StageEnemy& parent, int spawnType,
                                         int childIndex, float offsetX,
                                         float offsetY, int hitPoints, int kind,
                                         double speed, int radius,
                                         std::uint16_t angle16,
                                         const char* note) {
    if (spawnType < 0x40 || spawnType > 0x43 ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceNote = note;
    child.updateCase = spawnType == 0x40 ? 0x2f
                         : (spawnType == 0x41 ? 0x30 : 0x31);
    child.sourceDispatchKind = kind;
    child.sourceDispatchField = radius;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = 0x13b;
    child.childIndex = childIndex;
    child.x = parent.x + offsetX;
    child.y = parent.y + offsetY;
    child.originX = offsetX;
    child.originY = offsetY;
    child.markerDrawX = offsetX;
    child.markerDrawY = offsetY;
    child.sourceAngle16 = angle16;
    child.secondaryAngle16 = angle16;
    child.targetAngle16 = angle16;
    child.angle = fixedAngleToRadians(angle16);
    child.sourceSpeed = speed;
    child.speed = static_cast<float>(speed);
    child.radius = radius;
    child.activationDelay = 0;
    child.rewardWeight = kind;
    child.targetable = false;
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = std::max(1, static_cast<int>(static_cast<double>(hitPoints) * hpScale));
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    pendingEnemies_.push_back(child);
    return true;
}

void StageRuntime::spawnStage04DeathNode(const StageEnemy& enemy, int hitPoints,
                                         int ownerEntityId) {
    (void)enemy;
    spawnDelayedOwnerDamageNode(
        hitPoints, ownerEntityId, 0x13b,
        "S04 boss child delayed-damage node 0x153");
}

void StageRuntime::spawnStage04CarrierChild(const StageEnemy& parent, int spawnType) {
    if (!isStage04CarrierFamily(spawnType) || spawnType < 0x3b ||
        enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.sourceHitPoints = parent.maxHp;
    child.sourceX = static_cast<int>(std::lround(parent.originX));
    child.sourceY = static_cast<int>(std::lround(parent.originY));
    child.sourceNote = spawnType == 0x3b
                           ? "S04 FUN_140093540 carrier satellite"
                           : "S04 FUN_140093540 carrier terminal satellite";
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = parent.helperTimer / 40;
    child.x = parent.originX;
    child.y = parent.originY;
    child.originX = parent.originX;
    child.originY = parent.originY;
    child.sourceAngle16 = parent.secondaryAngle16;
    child.secondaryAngle16 = parent.secondaryAngle16;
    child.angle = fixedAngleToRadians(child.sourceAngle16);
    child.sourceSpeed = 2.0;
    child.speed = 2.0f;
    child.hp = parent.hp;
    child.maxHp = parent.maxHp;
    child.radius = 40;
    child.visualFrame = spawnType == 0x3b ? 70 : 71;
    child.activationDelay = 0;
    child.helperState = 0;
    child.rewardWeight = spawnType == 0x3b ? 5 : 10;
    child.targetable = true;
    pendingEnemies_.push_back(child);
}

void StageRuntime::spawnStage04Type3DChild(const StageEnemy& parent, int childIndex,
                                           float offsetX, float offsetY) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    constexpr int kChildHitPoints = 99999999;
    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x3e;
    child.sourceHitPoints = kChildHitPoints;
    child.sourceX = static_cast<int>(offsetX);
    child.sourceY = static_cast<int>(offsetY);
    child.sourceNote = "S04 FUN_1400941d0 local anchor child";
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.x = offsetX;
    child.y = offsetY;
    child.originX = offsetX;
    child.originY = offsetY;
    child.sourceAngle16 = 0xc000;
    child.secondaryAngle16 = 0xc000;
    child.angle = fixedAngleToRadians(child.sourceAngle16);
    child.sourceSpeed = 0.0;
    child.speed = 0.0f;
    const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = static_cast<int>(static_cast<double>(kChildHitPoints) * hpScale);
    child.maxHp = child.hp;
    child.radius = 40;
    child.visualFrame = 72;
    child.activationDelay = 0;
    child.helperState = 0;
    child.helperTimer = 0;
    child.rewardWeight = 1;
    child.targetable = false;
    pendingEnemies_.push_back(child);
}

StageRuntime::StageEnemy* StageRuntime::findEnemyById(int entityId) {
    for (auto& candidate : enemies_) {
        if (candidate.entityId == entityId) {
            return &candidate;
        }
    }
    return nullptr;
}

void StageRuntime::updatePlayer() {
    // DAT_140e44acc belongs to the gameplay dispatcher, not to the live-player
    // branch. Keep the value used by this frame even when a miss returns early.
    player_.drawAnimationClock = player_.animationClock;
    const int shotTimerBeforeInput = player_.shotTimer;

    // The terminal miss clears the original player-active flag before state
    // 0x1e continues dispatching the rest of the stage simulation.
    if (pauseFlowState_ == PauseFlowState::GameOverDelay) {
        return;
    }
    player_.shotVariantAuraScale = 0.0f;

    const bool shootDown = actionDown(InputAction::Shoot);
    const bool rapidFireDown = actionDown(InputAction::RapidFire);
    const bool slowDown = actionDown(InputAction::Slow);

    // FUN_140106be0 uses the signed transition counter while changing between
    // high- and low-speed formations. Arcade mode derives focus from Shoot;
    // holding Rapid-Fire alongside its first Shoot frame seeds the timer at 8.
    if (config_.controlModeEnabled == 1) {
        if (slowDown) {
            player_.focused = true;
            if (player_.focusTransition > 0) {
                player_.focusTransition = -1;
            }
        }
        else {
            player_.focused = false;
            if (player_.focusTransition < 0) {
                player_.focusTransition = 1;
            }
        }
    }
    else {
        if (player_.focusHoldTimer != 0) {
            ++player_.focusHoldTimer;
        }
        if (shootDown) {
            if (player_.focusHoldTimer == 0) {
                player_.focusHoldTimer = 1;
            }
            else if (player_.focusHoldTimer != 1 && player_.focusHoldTimer > 11) {
                player_.focused = true;
                if (player_.focusTransition > 0) {
                    player_.focusTransition = -1;
                }
            }
            if (player_.focusHoldTimer == 1 && rapidFireDown) {
                player_.focusHoldTimer = 8;
            }
        }
        else {
            player_.focused = false;
            if (player_.focusTransition < 0 && !slowDown) {
                player_.focusTransition = 1;
            }
            player_.focusHoldTimer = 0;
        }
        if (slowDown) {
            player_.focused = true;
            if (player_.focusTransition > 0) {
                player_.focusTransition = -1;
            }
        }
    }
    if (player_.focusTransition < 0) {
        --player_.focusTransition;
    }
    else if (player_.focusTransition > 0) {
        ++player_.focusTransition;
    }

    const bool upDown = actionDown(InputAction::Up);
    const bool downDown = actionDown(InputAction::Down);
    const bool rightDown = actionDown(InputAction::Right);
    const bool leftDown = actionDown(InputAction::Left);
    if (upDown) player_.movementAngle16 = 0xc000;
    if (downDown) player_.movementAngle16 = 0x4000;
    if (rightDown) player_.movementAngle16 = 0x0000;
    if (leftDown) player_.movementAngle16 = 0x8000;
    if (rightDown && downDown) player_.movementAngle16 = 0x2000;
    if (leftDown && downDown) player_.movementAngle16 = 0x6000;
    if (leftDown && upDown) player_.movementAngle16 = 0xa000;
    if (rightDown && upDown) player_.movementAngle16 = 0xe000;

    const bool directionalInput = upDown || downDown || rightDown || leftDown;
    const bool verticalOnly = player_.movementAngle16 == 0x4000 ||
                              player_.movementAngle16 == 0xc000;
    const bool movingLeft = player_.movementAngle16 == 0x6000 ||
                            player_.movementAngle16 == 0x8000 ||
                            player_.movementAngle16 == 0xa000;
    if (!directionalInput || verticalOnly) {
        if (player_.lateralAnimation < 0) {
            ++player_.lateralAnimation;
        }
        else if (player_.lateralAnimation > 0) {
            --player_.lateralAnimation;
        }
    }
    else if (movingLeft) {
        if (player_.lateralAnimation > 0) {
            player_.lateralAnimation = 0;
        }
        player_.lateralAnimation = std::max(player_.lateralAnimation - 1, -12);
    }
    else {
        if (player_.lateralAnimation < 0) {
            player_.lateralAnimation = 0;
        }
        player_.lateralAnimation = std::min(player_.lateralAnimation + 1, 12);
    }

    constexpr std::array<std::array<double, 2>, 3> kMovementSpeeds{{
        {{7.5, 4.0}}, {{7.9, 4.1}}, {{8.3, 4.2}},
    }};
    float nextX = player_.x;
    float nextY = player_.y;
    const bool playerMovedThisFrame =
        player_.playerStateTimer <= 180 && directionalInput;
    if (playerMovedThisFrame) {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const double speed = kMovementSpeeds[static_cast<std::size_t>(group)][player_.focused ? 1U : 0U];
        const double angle = fixedAngleToRadiansDouble(player_.movementAngle16);
        nextX += static_cast<float>(std::cos(angle) * speed * 1.2);
        nextY += static_cast<float>(std::sin(angle) * speed);
    }
    // FUN_1401346a0 reads the already-updated global x while deriving mode-4
    // bounds, so this self-dependent origin is intentional.
    const float horizontalOrigin = nextX / 6.0f;
    player_.x = clampFloat(nextX, horizontalOrigin + 4.0f, horizontalOrigin + 596.0f);
    player_.y = clampFloat(nextY, 4.0f, 716.0f);
    if (player_.playerStateTimer >= 181 && player_.playerStateTimer <= 220) {
        constexpr float kRespawnX = 360.0f;
        constexpr float kRespawnY = 600.0f;
        const float deltaX = kRespawnX - player_.x;
        const float deltaY = kRespawnY - player_.y;
        const float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
        if (distance > 0.0f) {
            const double angle = std::atan2(static_cast<double>(deltaY),
                                            static_cast<double>(deltaX));
            const double step = static_cast<double>(distance) / 10.0 + 1.0;
            player_.x += static_cast<float>(std::cos(angle) * step);
            player_.y += static_cast<float>(std::sin(angle) * step);
        }
    }
    if (player_.y <= 300.0f && player_.playerStateTimer < 180) {
        for (auto& item : rewardItems_) {
            const bool autoCollectType =
                (item.itemType >= 0 && item.itemType <= 5) || item.itemType == 8;
            if (item.active && item.age > 0x1f && autoCollectType) {
                item.homing = true;
            }
        }
    }
    updatePlayerOptions();

    const bool firing = player_.playerStateTimer < 180 && (shootDown || rapidFireDown);
    const bool stageClearShotLock = [this]() {
        switch (selectedStage_) {
        case 1: return stage01ClearTransition_;
        case 2: return stage02ClearTransition_;
        case 3: return stage03ClearTransition_;
        case 4: return stage04ClearTransition_;
        // Stages 5-7 and 10 use FUN_140003ad0, which raises the original
        // DAT_140e41b08 lock on clear age 420. Stages 8 and 9 use
        // FUN_140003e60 and raise it on the first clear frame instead.
        case 5:
        case 6:
        case 7:
        case 10:
            return lateStageClearStarted_ && lateStageClearTimer_ >= 420;
        case 8:
        case 9:
            return lateStageClearStarted_;
        default:
            return false;
        }
    }();
    if (player_.playerStateTimer >= 180 || player_.bombLock > 0 ||
        stageClearShotLock) {
        player_.shotTimer = 0;
    }
    else if (config_.controlModeEnabled == 1) {
        if (firing) {
            ++player_.shotTimer;
        }
        else if (player_.shotTimer != 0) {
            if (player_.shotTimer % 5 == 4) {
                player_.shotTimer = 0;
            }
            else {
                ++player_.shotTimer;
            }
        }
    }
    else {
        if (player_.shotTimer != 0) {
            ++player_.shotTimer;
        }
        if (firing && player_.shotTimer == 0) {
            player_.shotTimer = 1;
        }
        if (!firing && player_.shotTimer > 0x10) {
            player_.shotTimer = 0;
        }
    }
    if (player_.shotTimer % 5 == 1) {
        emitPlayerNormalShot();
    }
    if (config_.setupGroup == 0 && config_.optionSlots[1] == 0 &&
        player_.focusTransition < 0 && player_.shotTimer == 1) {
        // FUN_140106be0 restarts this formation transition on the opening
        // volley so the four lock-on options acquire in their original order.
        player_.focusTransition = -1;
    }
    updateSpecialGaugeAction();
    if (config_.setupGroup == 1 && config_.optionSlots[2] == 1) {
        if (player_.shotVariant > 0) {
            player_.shotVariantAuraScale =
                static_cast<float>(player_.shotVariant) / 600.0f;
            --player_.shotVariant;
        }
        else if (player_.shotVariant < 0) {
            player_.shotVariant = 0;
        }
    }
    if (settlePendingPlayerHit()) {
        return;
    }

    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int baseFrame = group * 30;
    const auto animationFrame = [](int tick, int offset, int duration,
                                   std::initializer_list<int> frames) {
        const int count = static_cast<int>(frames.size());
        const int period = duration * count;
        int phase = period > 0 ? (tick - offset) % period : 0;
        if (phase < 0) {
            phase += period;
        }
        return *(frames.begin() + std::min(phase / duration, count - 1));
    };
    if (player_.lateralAnimation == 0) {
        player_.visualFrame = baseFrame + animationFrame(
            player_.animationClock, 0, 7, {0, 1, 2, 1});
    }
    else if (player_.lateralAnimation > 0 && player_.lateralAnimation < 12) {
        player_.visualFrame = baseFrame + animationFrame(
            player_.lateralAnimation, 0, 6, {3, 4, 5});
    }
    else if (player_.lateralAnimation >= 12) {
        player_.visualFrame = baseFrame + animationFrame(
            player_.animationClock, 12, 7, {5, 6, 7});
    }
    else if (player_.lateralAnimation > -12) {
        player_.visualFrame = baseFrame + animationFrame(
            -player_.lateralAnimation, 0, 6, {8, 9, 10});
    }
    else {
        player_.visualFrame = baseFrame + animationFrame(
            player_.animationClock, 12, 7, {10, 11, 12});
    }

    if (frame_ < 60) {
        player_.hitboxScale = 0.0f;
    }
    else if (frame_ < 90) {
        constexpr double kHitboxEaseStep = 3.14159265358979 / 60.0;
        player_.hitboxScale = static_cast<float>(
            std::sin(static_cast<double>(frame_ - 60) * kHitboxEaseStep));
    }
    else {
        player_.hitboxScale = 1.0f;
    }
    player_.hitboxAngle16 = normalizeAngle16(player_.animationClock * 0x3c0);
    player_.drawInvulnerabilityOverlay =
        player_.invulnerableFrames != 0 && (player_.animationClock & 1) == 0;

    if (player_.playerStateTimer > 0) {
        --player_.playerStateTimer;
    }
    processStockProgressAfterGain(0);
    updateSpecialGaugeState(shotTimerBeforeInput);
    if (playerMovedThisFrame && !player_.focused &&
        (player_.drawAnimationClock & 1) == 0) {
        const int afterimageHandle =
            player_.visualFrame >= 0 &&
                    player_.visualFrame < static_cast<int>(playerFrames_.size())
                ? playerFrames_[static_cast<std::size_t>(player_.visualFrame)]
                : -1;
        spawnStageEffect(0x05, afterimageHandle, 0x50, 0x27,
                         player_.x, player_.y, 0,
                         0.0, 1.0, 1.0, 0x18,
                         0xff, 0xff, 0xff, 0x60);
    }
    if (player_.invulnerableFrames > 0) {
        --player_.invulnerableFrames;
    }
}

void StageRuntime::updatePlayerOptions() {
    // FUN_14010cc90 keeps four persistent option nodes. Positions close 25% of
    // the remaining distance and angles turn by abs(delta) / 10 + 0x80.
    constexpr std::array<std::array<float, 8>, 6> kUnfocusedOffsets{{
        {{50.0f, 60.0f, -50.0f, 60.0f, 80.0f, 10.0f, -80.0f, 10.0f}},
        {{50.0f, -30.0f, -50.0f, -30.0f, 80.0f, 30.0f, -80.0f, 30.0f}},
        {{50.0f, -50.0f, -50.0f, -50.0f, 90.0f, 30.0f, -90.0f, 30.0f}},
        {{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}},
        {{70.0f, 60.0f, -70.0f, 60.0f, 150.0f, 0.0f, -150.0f, 0.0f}},
        {{60.0f, -60.0f, -60.0f, -60.0f, 110.0f, -20.0f, -110.0f, -20.0f}},
    }};
    constexpr std::array<std::array<std::uint16_t, 4>, 6> kUnfocusedAngles{{
        {{0xc5dc, 0xba24, 0xcfa0, 0xb060}},
        {{0xcbb8, 0xb448, 0xd770, 0xa890}},
        {{0xc0c8, 0xbf38, 0xc2bc, 0xbd44}},
        {{0x01f4, 0xfe0c, 0x05dc, 0xfa24}},
        {{0xc000, 0xc000, 0xc000, 0xc000}},
        {{0xc000, 0xc000, 0xc3e8, 0xbc18}},
    }};
    constexpr std::array<float, 8> kFocusedGroup0Option0Offsets{{
        -160.0f, 0.0f, 160.0f, 0.0f, -80.0f, 40.0f, 80.0f, 40.0f,
    }};
    constexpr std::array<float, 8> kFocusedNarrowOffsets{{
        -70.0f, -20.0f, 70.0f, -20.0f, -30.0f, -70.0f, 30.0f, -70.0f,
    }};
    constexpr std::array<float, 8> kFocusedGroup2Option0Offsets{{
        30.0f, 50.0f, -30.0f, 50.0f, 70.0f, 0.0f, -70.0f, 0.0f,
    }};
    constexpr std::array<float, 8> kFocusedGroup2Option1Offsets{{
        25.0f, -60.0f, -25.0f, -60.0f, 60.0f, -20.0f, -60.0f, -20.0f,
    }};
    constexpr std::array<std::uint16_t, 4> kUpAngles{{0xc000, 0xc000, 0xc000, 0xc000}};
    constexpr std::array<std::uint16_t, 4> kFocusedGroup0Option1Angles{{
        0xc1f4, 0xbe0c, 0xc000, 0xc000,
    }};
    constexpr std::array<std::uint16_t, 4> kFocusedGroup1Option0Angles{{
        0xc3e8, 0xbc18, 0xc1f4, 0xbe0c,
    }};
    constexpr std::array<std::uint16_t, 4> kFocusedGroup2Option1Angles{{
        0xc000, 0xc000, 0xc1f4, 0xbe0c,
    }};
    constexpr std::array<int, 4> kRadialAngleOffsets{{0x01f4, -0x01f4, 0x05dc, -0x05dc}};

    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int option0 = std::clamp(config_.optionSlots[0], 0, 1);
    const int option1 = std::clamp(config_.optionSlots[1], 0, 1);
    player_.optionDrawScale = 1.0f;
    if (player_.playerStateTimer >= 180 && player_.playerStateTimer < 260) {
        if (player_.playerStateTimer < 190) {
            player_.optionDrawScale = static_cast<float>(
                1.0 - std::sin(static_cast<double>(player_.playerStateTimer - 180) *
                               static_cast<double>(kPi) / 20.0));
        }
        else if (player_.playerStateTimer < 250) {
            player_.optionDrawScale = 0.0f;
        }
        else {
            player_.optionDrawScale = static_cast<float>(
                1.0 - std::sin(static_cast<double>(player_.playerStateTimer - 240) *
                               static_cast<double>(kPi) / 20.0));
        }
    }
    const auto isCommonTarget = [this](const StageEnemy& enemy) {
        if (!enemy.active || !enemy.targetable) {
            return false;
        }
        const float radius = static_cast<float>(std::max(0, enemy.radius));
        const float horizontalOrigin = player_.x / 6.0f;
        return enemy.x >= horizontalOrigin - (radius + 100.0f) &&
               enemy.x <= horizontalOrigin + radius + 700.0f &&
               enemy.y >= -(radius + 100.0f) &&
               enemy.y <= radius + 820.0f;
    };
    const auto findTargetById = [this](int entityId) -> const StageEnemy* {
        if (entityId == 0) {
            return nullptr;
        }
        for (const auto& enemy : enemies_) {
            if (enemy.entityId == entityId) {
                return &enemy;
            }
        }
        return nullptr;
    };
    const auto acquireOptionTarget = [&](float optionX, float optionY) {
        const StageEnemy* nearest = nullptr;
        float nearestSurfaceDistance = 2000.0f;
        for (const auto& enemy : enemies_) {
            if (!isCommonTarget(enemy)) {
                continue;
            }
            const float radius = static_cast<float>(std::max(0, enemy.radius));
            if (enemy.y >= optionY ||
                std::abs(enemy.x - optionX) >= radius + 180.0f) {
                continue;
            }
            const float dx = enemy.x - optionX;
            const float dy = enemy.y - optionY;
            const float surfaceDistance = std::sqrt(dx * dx + dy * dy) - radius;
            if (surfaceDistance < nearestSurfaceDistance) {
                nearestSurfaceDistance = surfaceDistance;
                nearest = &enemy;
            }
        }
        return nearest != nullptr ? nearest->entityId : 0;
    };
    const auto advanceSharedTarget = [&]() {
        double heading = std::atan2(
            static_cast<double>(player_.y - player_.sharedOptionTargetY),
            static_cast<double>(player_.x - player_.sharedOptionTargetX));
        if (player_.focusTransition == -2) {
            const float dx = player_.x - player_.sharedOptionTargetX;
            const float dy = player_.y - player_.sharedOptionTargetY;
            if (std::sqrt(dx * dx + dy * dy) <= 30.0f) {
                player_.sharedOptionTargetX = player_.x;
                player_.sharedOptionTargetY = player_.y;
            }
        }

        float nearestSurfaceDistance = 2000.0f;
        float targetX = player_.x;
        float targetY = -65536.0f;
        bool hasCommonTarget = false;
        for (const auto& enemy : enemies_) {
            if (!isCommonTarget(enemy)) {
                continue;
            }
            hasCommonTarget = true;
            const float radius = static_cast<float>(std::max(0, enemy.radius));
            const float dx = enemy.x - player_.sharedOptionTargetX;
            const float dy = enemy.y - player_.sharedOptionTargetY;
            const float surfaceDistance = std::sqrt(dx * dx + dy * dy) - radius;
            if (surfaceDistance < nearestSurfaceDistance) {
                nearestSurfaceDistance = surfaceDistance;
                targetX = enemy.x;
                targetY = enemy.y;
            }
        }
        if (hasCommonTarget) {
            heading = std::atan2(
                static_cast<double>(targetY + 200.0f - player_.sharedOptionTargetY),
                static_cast<double>(targetX - player_.sharedOptionTargetX));
        }
        player_.sharedOptionTargetX += static_cast<float>(std::cos(heading) * 0.1);
        player_.sharedOptionTargetY += static_cast<float>(std::sin(heading) * 0.1);
    };

    const bool rotatingUnfocusedFormation =
        !player_.focused &&
        ((group == 1 && option0 == 1) || (group == 2 && option0 == 0));
    if (rotatingUnfocusedFormation) {
        std::uint16_t target = 0xc000;
        if (actionDown(InputAction::Left)) {
            target = 0xae6c;
        }
        else if (actionDown(InputAction::Right)) {
            target = 0xd194;
        }
        player_.optionFormationAngle16 = approachAngle16(player_.optionFormationAngle16, target, 0x5a);
    }
    if (player_.focused && group == 1 && option0 == 1) {
        player_.optionFormationAngle16 = 0xc000;
    }

    for (int slot = 0; slot < 4; ++slot) {
        float offsetX = 0.0f;
        float offsetY = 0.0f;
        float anchorX = player_.x;
        float anchorY = player_.y;
        std::uint16_t targetAngle = 0xc000;
        const std::size_t offsetIndex = static_cast<std::size_t>(slot * 2);

        if (!player_.focused) {
            const bool useSharedTransition =
                group == 2 && option1 == 1 && player_.focusTransition < 0x11;
            if (useSharedTransition) {
                const std::size_t row = static_cast<std::size_t>(group * 2 + option0);
                anchorX = player_.sharedOptionTargetX;
                anchorY = player_.sharedOptionTargetY;
                offsetX = kUnfocusedOffsets[row][offsetIndex];
                offsetY = kUnfocusedOffsets[row][offsetIndex + 1];
                targetAngle = kUnfocusedAngles[row][static_cast<std::size_t>(slot)];
            }
            else if (group == 1 && option0 == 1) {
                const float angle = fixedAngleToRadians(player_.optionFormationAngle16);
                offsetX = std::cos(angle) * 100.0f;
                offsetY = std::sin(angle) * 100.0f + 20.0f;
                targetAngle = normalizeAngle16(
                    static_cast<int>(player_.optionFormationAngle16) +
                    kRadialAngleOffsets[static_cast<std::size_t>(slot)]);
            }
            else if (group == 2 && option0 == 0) {
                constexpr std::array<float, 8> kOffsets{{
                    70.0f, 60.0f, -70.0f, 60.0f, 150.0f, 0.0f, -150.0f, 0.0f,
                }};
                offsetX = kOffsets[offsetIndex];
                offsetY = kOffsets[offsetIndex + 1];
                targetAngle = player_.optionFormationAngle16;
            }
            else {
                const std::size_t row = static_cast<std::size_t>(group * 2 + option0);
                offsetX = kUnfocusedOffsets[row][offsetIndex];
                offsetY = kUnfocusedOffsets[row][offsetIndex + 1];
                targetAngle = kUnfocusedAngles[row][static_cast<std::size_t>(slot)];
            }
            if (group == 2 && option1 == 1 && !useSharedTransition) {
                player_.sharedOptionTargetX = player_.x;
                player_.sharedOptionTargetY = player_.y;
            }
            player_.optionTargetEntityIds[static_cast<std::size_t>(slot)] = 0;
        }
        else if (group == 0 && option1 == 0) {
            offsetX = kFocusedGroup0Option0Offsets[offsetIndex];
            offsetY = kFocusedGroup0Option0Offsets[offsetIndex + 1];
            targetAngle = kUpAngles[static_cast<std::size_t>(slot)];

            const std::size_t index = static_cast<std::size_t>(slot);
            const bool canAcquire = player_.focusTransition <= -(slot + 1) * 5 &&
                                    player_.shotTimer >= 1;
            if (!canAcquire) {
                player_.optionTargetEntityIds[index] = 0;
            }
            else if (player_.optionTargetEntityIds[index] == 0) {
                player_.optionTargetEntityIds[index] =
                    acquireOptionTarget(player_.optionX[index], player_.optionY[index]);
                if (player_.optionTargetEntityIds[index] != 0) {
                    targetAngle = 0;
                    playPlayerSound(optionLockSoundHandle_, 0x13);
                }
            }
            else {
                const StageEnemy* target =
                    findTargetById(player_.optionTargetEntityIds[index]);
                if (target == nullptr || !target->active || !target->targetable) {
                    player_.optionTargetEntityIds[index] = 0;
                    targetAngle = 0;
                }
                else {
                    targetAngle = radiansToFixedAngleTrunc(std::atan2(
                        static_cast<double>(target->y - player_.optionY[index]),
                        static_cast<double>(target->x - player_.optionX[index])));
                }
            }
        }
        else if (group == 0) {
            offsetX = kFocusedNarrowOffsets[offsetIndex];
            offsetY = kFocusedNarrowOffsets[offsetIndex + 1];
            targetAngle = kFocusedGroup0Option1Angles[static_cast<std::size_t>(slot)];
            player_.optionTargetEntityIds[static_cast<std::size_t>(slot)] = 0;
        }
        else if (group == 1) {
            offsetX = kFocusedNarrowOffsets[offsetIndex];
            offsetY = kFocusedNarrowOffsets[offsetIndex + 1];
            targetAngle = option1 == 0
                ? kFocusedGroup1Option0Angles[static_cast<std::size_t>(slot)]
                : kUpAngles[static_cast<std::size_t>(slot)];
            player_.optionTargetEntityIds[static_cast<std::size_t>(slot)] = 0;
        }
        else if (option1 == 0) {
            offsetX = kFocusedGroup2Option0Offsets[offsetIndex];
            offsetY = kFocusedGroup2Option0Offsets[offsetIndex + 1];
            targetAngle = player_.optionFormationAngle16;
            player_.optionTargetEntityIds[static_cast<std::size_t>(slot)] = 0;
        }
        else {
            advanceSharedTarget();
            anchorX = player_.sharedOptionTargetX;
            anchorY = player_.sharedOptionTargetY;
            offsetX = kFocusedGroup2Option1Offsets[offsetIndex];
            offsetY = kFocusedGroup2Option1Offsets[offsetIndex + 1];
            targetAngle = kFocusedGroup2Option1Angles[static_cast<std::size_t>(slot)];
            player_.optionTargetEntityIds[static_cast<std::size_t>(slot)] = 0;
        }

        const float targetX = anchorX + offsetX;
        const float targetY = anchorY + offsetY;
        const std::size_t index = static_cast<std::size_t>(slot);
        const double deltaX = static_cast<double>(targetX - player_.optionX[index]);
        const double deltaY = static_cast<double>(targetY - player_.optionY[index]);
        const double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
        const double heading = std::atan2(deltaY, deltaX);
        player_.optionX[index] += static_cast<float>(std::cos(heading) * distance * 0.25);
        player_.optionY[index] += static_cast<float>(std::sin(heading) * distance * 0.25);

        const std::uint16_t currentAngle = player_.optionAngle16[index];
        int delta = static_cast<int>(targetAngle) - static_cast<int>(currentAngle);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        const int turnStep = std::abs(delta) / 10 + 0x80;
        player_.optionAngle16[index] =
            approachAngle16(currentAngle, targetAngle, turnStep);
    }
}

void StageRuntime::updateEnemies() {
    const auto appendPending = [this]() {
        if (pendingEnemies_.empty()) {
            return;
        }
        const std::size_t remaining = kStageEntityCap - std::min<std::size_t>(enemies_.size(), kStageEntityCap);
        const std::size_t count = std::min(remaining, pendingEnemies_.size());
        enemies_.insert(enemies_.end(), pendingEnemies_.begin(), pendingEnemies_.begin() + count);
        pendingEnemies_.clear();
    };

    // The original walks a growable linked list. Index iteration plus the fixed
    // 0x200 reserve lets children appended by a helper run later in this frame.
    for (std::size_t enemyIndex = 0; enemyIndex < enemies_.size(); ++enemyIndex) {
        auto& enemy = enemies_[enemyIndex];
        const bool commonMarkerRoot = enemy.spawnType >= 0x06 && enemy.spawnType <= 0x08;
        const bool commonMarkerSatellite = enemy.spawnType == 0x09;
        const bool sharedType0A = enemy.spawnType == 0x0a;
        const bool sharedType0B = enemy.spawnType == 0x0b;
        const bool sharedType0C = enemy.spawnType == 0x0c;
        const bool sharedType0D = enemy.spawnType == 0x0d;
        const bool sharedType0E = enemy.spawnType == 0x0e;
        const bool sharedType0F = enemy.spawnType == 0x0f;
        const bool stage01Type10 = enemy.spawnType == 0x10;
        const bool stage01Type11 = enemy.spawnType == 0x11;
        const bool stage03Exact = isStage03FocusedType(enemy.spawnType);
        const bool stage03BossRoot = enemy.spawnType == 0x13a;
        const bool stage03BossChild = isStage03BossChildType(enemy.spawnType) &&
                                      enemy.parentSpawnType == 0x13a;
        const bool stage03BossNode = stage03BossRoot || stage03BossChild;
        const bool stage03DeathNode = enemy.spawnType == 0x153 &&
                                      enemy.parentSpawnType == 0x13a;
        const bool stage04BossRoot = enemy.spawnType == 0x13b;
        const bool stage04BossChild = enemy.spawnType >= 0x40 && enemy.spawnType <= 0x43 &&
                                      enemy.parentSpawnType == 0x13b;
        const bool stage04BossNode = stage04BossRoot || stage04BossChild;
        const bool stage04DeathNode = enemy.spawnType == 0x153 &&
                                      enemy.parentSpawnType == 0x13b;
        const bool delayedOwnerDamageNode = enemy.spawnType == 0x153;
        const bool lateStageBoss = isLateStageBossType(enemy.spawnType) ||
                                   (enemy.parentSpawnType == 0x13f &&
                                    isStage08BossNodeType(enemy.spawnType)) ||
                                   (enemy.parentSpawnType == 0x140 &&
                                    isStage09BossNodeType(enemy.spawnType));
        const bool lateStageEnemy = isLateStageEnemyType(enemy.spawnType) && !lateStageBoss;
        const bool stage06MidbossQueueSnapshotOwned =
            enemy.spawnType == 0x143 ||
            (enemy.parentSpawnType == 0x143 &&
             enemy.spawnType >= 0x61 && enemy.spawnType <= 0x63);
        const bool carrierFamily = isStage04CarrierFamily(enemy.spawnType);
        const bool stage04SimpleExact = enemy.spawnType == 0x35 || enemy.spawnType == 0x36 || enemy.spawnType == 0x37;
        const bool stage04Type38 = enemy.spawnType == 0x38;
        const bool stage04Type3DFamily = enemy.spawnType == 0x3d || enemy.spawnType == 0x3e;
        const bool stage04Type3F = enemy.spawnType == 0x3f;
        const bool stage02Type19 = enemy.spawnType == 0x19;
        const bool stage02Type1A = enemy.spawnType == 0x1a;
        const bool stage02Type1B = enemy.spawnType == 0x1b;
        const bool stage02Type1C = enemy.spawnType == 0x1c;
        const bool stage02Type1DOr1E = enemy.spawnType == 0x1d || enemy.spawnType == 0x1e;
        const bool stage02Type1F = enemy.spawnType == 0x1f;
        const bool stage02Type20 = enemy.spawnType == 0x20;
        const bool stage02Type21 = enemy.spawnType == 0x21 &&
                                   enemy.parentSpawnType == 0x20;
        const bool stage02Exact = stage02Type19 || stage02Type1A || stage02Type1B ||
                                  stage02Type1C || stage02Type1DOr1E || stage02Type1F ||
                                  stage02Type20 || stage02Type21;
        const bool stage01BossRoot = enemy.spawnType == 0x138;
        const bool stage01BossDecoration =
            isStage01BossDecorationType(enemy.spawnType) &&
            ((enemy.spawnType == 0x12 && enemy.parentSpawnType == 0x138) ||
             (enemy.spawnType != 0x12 && enemy.parentSpawnType == 0x12));
        const bool stage01BossChild = isStage01BossChildType(enemy.spawnType);
        const bool stage01BossNode = stage01BossRoot ||
                                     stage01BossDecoration ||
                                     stage01BossChild;
        const bool stage02BossRoot = enemy.spawnType == 0x139;
        const bool stage02BossChild = enemy.spawnType >= 0x22 && enemy.spawnType <= 0x24 &&
                                      enemy.parentSpawnType == 0x139;
        const bool stage02BossNode = stage02BossRoot || stage02BossChild;
        const bool postDeathCounter = enemy.spawnType == 0x137;
        if (selectedStage_ >= 5 && enemy.hp < 1 &&
            isLateStageGateOwner(enemy) && enemy.spawnType != 0xa4 &&
            enemy.spawnType != 0x143 &&
            !isStage09MidbossType(enemy.spawnType)) {
            clearLateStageGate(selectedStage_);
        }
        // Entity helpers own the +0x1c < 1 death branch. Collision only writes
        // HP; cleanup/rewards happen when the helper runs on the next frame.
        if (enemy.hp < 1 && !commonMarkerRoot && !commonMarkerSatellite &&
            !sharedType0A && !sharedType0B && !sharedType0C &&
            !sharedType0D && !sharedType0E && !sharedType0F &&
            !stage01Type10 && !stage01Type11 && !stage01BossNode &&
            !stage02BossNode && !postDeathCounter &&
            !delayedOwnerDamageNode &&
            !stage03Exact && !stage03BossNode && !stage03DeathNode &&
            !stage04BossNode && !stage04DeathNode &&
            !lateStageEnemy && !lateStageBoss &&
            !stage02Exact &&
            !carrierFamily && !stage04SimpleExact && !stage04Type38 &&
            !stage04Type3DFamily && !stage04Type3F) {
            const int stage01Window = stage01DeathRewardWindow(enemy.spawnType);
            if (stage01Window > 0) {
                spawnEnemyDeathRewardBurst(enemy, stage01Window);
            }
            else if (enemy.spawnType != 0x09) {
                spawnEnemyDeathRewardBurst(enemy);
            }
            if (enemy.spawnType == 0x11) {
                const StageEnemy* parent = findEnemyById(enemy.parentEntityId);
                if (parent == nullptr || parent->spawnType != enemy.parentSpawnType ||
                    parent->hp < 1) {
                    // FUN_140082090 evaluates its independent owner-HP tail even
                    // after the child's own death branch has already fired.
                    spawnEnemyDeathEffects(enemy, 1);
                }
            }
            enemy.active = false;
            appendPending();
            continue;
        }
        ++enemy.age;
        if (enemy.age <= enemy.activationDelay) {
            enemy.vx *= 0.92f;
            enemy.vy *= 0.92f;
            continue;
        }
        const int activeAge = enemy.age - enemy.activationDelay;
        if (commonMarkerRoot) {
            updateStage01Marker(enemy, activeAge);
        }
        else if (commonMarkerSatellite) {
            updateStage01MarkerSatellite(enemy, activeAge);
        }
        else if (sharedType0A) {
            updateStage01Type0A(enemy, activeAge);
        }
        else if (sharedType0B) {
            updateStage01Type0B(enemy, activeAge);
        }
        else if (sharedType0C) {
            updateStage01Type0C(enemy, activeAge);
        }
        else if (sharedType0D) {
            updateStage01Type0D(enemy, activeAge);
        }
        else if (sharedType0E) {
            updateStage01Type0E(enemy);
        }
        else if (sharedType0F) {
            updateStage01Type0F(enemy);
        }
        else if (stage01BossRoot) {
            updateStage01Boss(enemy);
        }
        else if (stage01BossDecoration) {
            updateStage01BossDecoration(enemy);
        }
        else if (stage01BossChild) {
            updateStage01BossChild(enemy);
        }
        else if (stage02Type19) {
            updateStage02Type19(enemy);
        }
        else if (stage02Type1A) {
            updateStage02Type1A(enemy);
        }
        else if (stage02Type1B) {
            updateStage02Type1B(enemy);
        }
        else if (stage02Type1C) {
            updateStage02Type1C(enemy);
        }
        else if (stage02Type1DOr1E) {
            updateStage02Type1DOr1E(enemy);
        }
        else if (stage02Type1F) {
            updateStage02Type1F(enemy);
        }
        else if (stage02Type20) {
            updateStage02Type20(enemy);
        }
        else if (stage02Type21) {
            updateStage02Type21(enemy);
        }
        else if (stage02BossRoot) {
            updateStage02Boss(enemy);
        }
        else if (stage02BossChild) {
            updateStage02BossChild(enemy);
        }
        else if (postDeathCounter) {
            updatePostDeathCounterEntity(enemy);
        }
        else if (delayedOwnerDamageNode) {
            updateStage03DeathNode(enemy);
        }
        else if (stage03Exact) {
            updateStage03Enemy(enemy);
        }
        else if (stage03BossRoot) {
            updateStage03Boss(enemy);
        }
        else if (stage03BossChild) {
            updateStage03BossChild(enemy);
        }
        else if (stage03DeathNode) {
            updateStage03DeathNode(enemy);
        }
        else if (stage04BossRoot) {
            updateStage04Boss(enemy);
        }
        else if (stage04BossChild) {
            updateStage04BossChild(enemy);
        }
        else if (stage04DeathNode) {
            updateStage03DeathNode(enemy);
        }
        else if (lateStageBoss) {
            updateLateStageBoss(enemy);
        }
        else if (lateStageEnemy) {
            updateLateStageEnemy(enemy, activeAge);
        }
        else if (isStage01ObservedType(enemy.spawnType)) {
            updateStage01Enemy(enemy, activeAge);
        }
        else if (isStage04FocusedType(enemy.spawnType)) {
            updateStage04Enemy(enemy, activeAge);
        }
        else {
            // No Stage 1-10 schedule or recovered child constructor reaches
            // this path. Keep reserved dispatcher slots inert rather than
            // assigning them invented movement.
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            enemy.targetable = false;
            enemy.drawBodyThisFrame = false;
        }

        // FUN_140090c30 fires type 0x35 from its saved pre-movement point.
        // FUN_140091540/FUN_140092230 advance 0x36/0x37 before their volleys.
        const bool stage04PreMovementFire = enemy.spawnType == 0x35;
        const bool stage04OwnsHelperTimer = stage04SimpleExact || stage04Type38 || carrierFamily ||
                                            stage04Type3DFamily || stage04Type3F;
        const bool ownsHelperTimer = commonMarkerRoot || commonMarkerSatellite ||
                                     sharedType0B || sharedType0C || sharedType0D ||
                                     sharedType0E || sharedType0F ||
                                     stage01Type10 || stage01BossNode || stage02BossNode ||
                                     postDeathCounter || stage02Exact ||
                                     delayedOwnerDamageNode ||
                                     stage03Exact || stage03BossNode || stage03DeathNode ||
                                     stage04BossNode || stage04DeathNode ||
                                     lateStageEnemy || lateStageBoss ||
                                     stage04OwnsHelperTimer;
        if (stage04PreMovementFire) {
            // These helpers emit from the pre-movement point.
            emitStage04Projectiles(enemy, enemy.helperTimer);
        }

        if (!stage01BossNode && !stage02BossNode && !stage03BossNode &&
            !stage03DeathNode && !stage04BossNode && !stage04DeathNode &&
            !delayedOwnerDamageNode &&
            !lateStageBoss &&
            !postDeathCounter && !stage02Exact) {
            enemy.x += enemy.vx;
            enemy.y += enemy.vy;
        }

        if (postDeathCounter) {
            // FUN_14007c1a0 owns this invisible helper's lifetime and emissions.
        }
        else if (stage02Exact) {
            // Stage 2 exact helpers emit before the central dispatcher advances
            // their helper timers; no generic fallback belongs to these nodes.
        }
        else if (stage03Exact || stage03BossNode || stage03DeathNode ||
                 stage04BossNode || stage04DeathNode ||
                 delayedOwnerDamageNode || lateStageBoss) {
            // Stage 3 exact helpers emit internally from the original
            // pre/post-movement source coordinates. Stage 4 boss helpers follow
            // the same queue-owned update contract.
        }
        else if (stage01BossNode) {
            // FUN_140004660 and FUN_140007fc0 emit internally and own their
            // direct position updates.
        }
        else if (stage02BossNode) {
            // FUN_140009480/FUN_14000d480/FUN_14000e3b0 own movement and
            // projectile emission inside their helper calls.
        }
        else if (commonMarkerRoot) {
            emitStage01Projectiles(enemy, enemy.helperTimer);
        }
        else if (commonMarkerSatellite) {
            // FUN_140083db0 only queues its orbiting body while its parent is
            // alive; it does not emit an enemy projectile.
        }
        else if (sharedType0A) {
            emitStage01Projectiles(enemy, activeAge);
        }
        else if (sharedType0B || sharedType0C || sharedType0D || sharedType0F) {
            emitStage01Projectiles(enemy, enemy.helperTimer);
        }
        else if (isStage01ObservedType(enemy.spawnType)) {
            emitStage01Projectiles(enemy, activeAge);
        }
        else if (isStage04FocusedType(enemy.spawnType) && !stage04PreMovementFire) {
            emitStage04Projectiles(enemy, stage04OwnsHelperTimer ? enemy.helperTimer : activeAge);
        }
        else if (lateStageEnemy) {
            emitLateStageProjectiles(enemy, enemy.helperTimer);
        }
        else {
            // Reserved/unconstructed dispatcher slots have no projectile
            // helper and must remain silent.
        }
        if (stage01Type10 && enemy.helperState == 1 && enemy.hp < 1) {
            // FUN_140080fb0 performs its lethal transition after movement and
            // firing, so the final combat tick remains visible and can shoot.
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            const int group = std::clamp(config_.setupGroup, 0, 2);
            const int frameIndex = 1 + group * 10;
            const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                           ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                           : -1;
            spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                             0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 0x78,
                             0xff, 0xff, 0xff, 0xff);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
            spawnStage02DeathExplosionChain(enemy); // state-2 timer 0
        }
        if (stage01Type10 && enemy.helperState == 1 && enemy.targetable) {
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            if (enemy.x < horizontalOrigin - 300.0f ||
                enemy.x > horizontalOrigin + 900.0f ||
                enemy.y < -300.0f || enemy.y > 1020.0f) {
                enemy.active = false;
                stage01GateFlag_ = false;
            }
        }
        if (stage04Type3F && enemy.helperState == 1 && enemy.hp < 1) {
            // FUN_140095130 performs this after the active movement/projectile
            // families, so the lethal frame still fires before entering state 2.
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            const int group = std::clamp(config_.setupGroup, 0, 2);
            const int frameIndex = 1 + group * 10;
            const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                           ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                           : -1;
            spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                             0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 0x78,
                             0xff, 0xff, 0xff, 0xff);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
            spawnStage02DeathExplosionChain(enemy); // state-2 timer 0
        }
        if (commonMarkerRoot) {
            // FUN_140082d90 queues movement, shots, its multipart body and the
            // gauge before evaluating the lethal and lifetime tails.
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 500);
                const auto rewardAngle = normalizeAngle16(
                    static_cast<int>(stageScriptRandFromFrame(frame_) % 0x4001u) +
                    0x2000);
                spawnRewardItem(6, enemy.x, enemy.y, rewardAngle,
                                stage01SpeedConstantValue(0x070), 30);
                enemy.active = false;
            }
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            if (enemy.x < horizontalOrigin - 128.0f ||
                enemy.x > horizontalOrigin + 728.0f ||
                enemy.y < -128.0f || enemy.y > 848.0f) {
                enemy.active = false;
            }
        }
        if (sharedType0A) {
            // FUN_14007c9c0 queues movement, shots, body, and gauge before its
            // death/bounds tail. Inactive nodes remain drawable until the next
            // update's unlink pass.
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 400);
                enemy.active = false;
            }
            const float horizontalOrigin = player_.x / 6.0f;
            if (enemy.x < horizontalOrigin - 64.0f ||
                enemy.x > horizontalOrigin + 664.0f ||
                enemy.y < -64.0f || enemy.y > 784.0f) {
                enemy.active = false;
            }
        }
        if (sharedType0B || sharedType0C || sharedType0D) {
            // FUN_14007d4e0/FUN_14007dfb0/FUN_14007ea30 queue their movement,
            // shots, body, and gauge before the shared death/bounds tail.
            if (enemy.hp < 1) {
                const int rewardWindow = sharedType0B ? 300 : (sharedType0C ? 0x168 : 0x1e0);
                spawnEnemyDeathRewardBurst(enemy, rewardWindow);
                enemy.active = false;
            }
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            if (enemy.x < horizontalOrigin - 180.0f ||
                enemy.x > horizontalOrigin + 780.0f ||
                enemy.y < -180.0f || enemy.y > 900.0f) {
                enemy.active = false;
            }
        }
        if (sharedType0E) {
            // FUN_14007f2c0 queues movement, bullets, multipart body, and gauge
            // before its death/bounds tail.
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 500);
                enemy.active = false;
            }
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            if (enemy.x < horizontalOrigin - 128.0f ||
                enemy.x > horizontalOrigin + 728.0f ||
                enemy.y < -128.0f || enemy.y > 848.0f) {
                enemy.active = false;
            }
        }
        if (sharedType0F) {
            // FUN_140080170 has the same queue-before-terminal-tail ordering,
            // but uses the larger kind-30 lifetime rectangle.
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 500);
                enemy.active = false;
            }
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            if (enemy.x < horizontalOrigin - 360.0f ||
                enemy.x > horizontalOrigin + 960.0f ||
                enemy.y < -360.0f || enemy.y > 1080.0f) {
                enemy.active = false;
            }
        }
        if (stage04SimpleExact && enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, enemy.spawnType == 0x35 ? 200 : 300);
            enemy.active = false;
        }
        if (stage04Type38) {
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 500);
                enemy.active = false;
            }
            const float horizontalOrigin = player_.x / 6.0f;
            if (enemy.x < horizontalOrigin - 128.0f || enemy.x > horizontalOrigin + 728.0f ||
                enemy.y < -128.0f || enemy.y > 848.0f) {
                enemy.active = false;
            }
        }
        if (enemy.spawnType == 0x3d) {
            if (enemy.hp < 1) {
                spawnEnemyDeathRewardBurst(enemy, 500);
                enemy.active = false;
            }
            const float horizontalOrigin = player_.x / 6.0f;
            if (enemy.x < horizontalOrigin - 360.0f || enemy.x > horizontalOrigin + 960.0f ||
                enemy.y < -360.0f || enemy.y > 1080.0f) {
                enemy.active = false;
            }
        }
        else if (enemy.spawnType == 0x3e) {
            const StageEnemy* owner = findEnemyById(enemy.parentEntityId);
            if (owner == nullptr || owner->hp < 1 || !owner->active) {
                enemy.active = false;
            }
        }
        else if (stage04Type3F && enemy.targetable) {
            const float horizontalOrigin = player_.x / 6.0f;
            if (enemy.x < horizontalOrigin - 400.0f ||
                enemy.x > horizontalOrigin + 1000.0f ||
                enemy.y < -400.0f || enemy.y > 1120.0f) {
                enemy.active = false;
                stage04GateFlag_ = false;
            }
        }
        if (!enemy.active && selectedStage_ >= 5 && isLateStageGateOwner(enemy)) {
            clearLateStageGate(selectedStage_);
        }
        if (ownsHelperTimer) {
            const bool stage03QueueSnapshotOwned = stage03BossRoot ||
                (stage03BossChild && enemy.spawnType >= 0x32);
            const bool stage04QueueSnapshotOwned = stage04BossNode;
            if (!stage01BossNode && !stage02BossNode && !stage03QueueSnapshotOwned &&
                !stage04QueueSnapshotOwned && !stage06MidbossQueueSnapshotOwned) {
                enemy.drawHelperState = enemy.helperState;
                enemy.drawHelperTimer = enemy.helperTimer;
            }
            ++enemy.helperTimer;
            if (enemy.targetable) {
                ++enemy.targetableTimer;
            }
        }
        else if ((sharedType0A || stage01Type11) && enemy.targetable) {
            // The generic dispatcher increments +0x10 after the helper call.
            ++enemy.targetableTimer;
        }
        appendPending();
    }
    appendPending();
}

void StageRuntime::updateStage02Type1B(StageEnemy& enemy) {
    constexpr std::array<int, 5> kCycleLength{{120, 80, 70, 70, 60}};
    constexpr std::array<int, 5> kFrontCount{{3, 5, 7, 7, 9}};
    constexpr std::array<int, 5> kRearSpread{{0, 0x708, 0x12c0, 0x12c0, 0x1130}};
    constexpr std::array<double, 5> kFrontSpeed{{4.0, 5.0, 5.5, 6.0, 7.2}};
    constexpr std::array<double, 5> kRearSpeed{{5.5, 6.5, 7.0, 7.5, 9.5}};
    constexpr double kPiDouble = 3.14159265358979;

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);

        if (enemy.helperTimer == 20) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 7.0;
            enemy.speed = 7.0f;
            enemy.targetable = true;
        }
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        const auto aimFrom = [this](float x, float y) {
            return radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - y),
                static_cast<double>(player_.x - x)));
        };

        if (timer <= 120 && enemy.sourceSpeed > 1.5) {
            enemy.sourceSpeed -= 0.1;
        }
        const std::uint16_t steeringTarget = aimFrom(enemy.x, enemy.y);
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, steeringTarget, 0x80);
        if (timer >= 240) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        const double motionRadians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(motionRadians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(motionRadians) * enemy.sourceSpeed);
        enemy.drawBodyThisFrame = true;

        if (timer >= 24 && timer <= 239) {
            const int difficulty = std::clamp(config_.difficulty, 0, 4);
            const int phase = (timer - 24) % kCycleLength[static_cast<std::size_t>(difficulty)];
            const double bodyScaleY =
                1.0 + 0.05 * std::sin(static_cast<double>(timer) * 2.0 * kPiDouble / 72.0);
            const float frontY = enemy.y + static_cast<float>(bodyScaleY * 65.0);
            const float rearY = enemy.y - static_cast<float>(bodyScaleY * 50.0);
            const std::uint16_t frontAim = aimFrom(enemy.x, frontY);
            const std::uint16_t rearAim = aimFrom(enemy.x, rearY);

            if (phase == 0) {
                const int count = kFrontCount[static_cast<std::size_t>(difficulty)];
                const double speed = kFrontSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(5, 0, enemy.x, frontY, frontAim, 0.0f, speed, 1,
                                      count, (count - 1) * 300, 0);
                if (difficulty >= 3) {
                    spawnProjectileSpread(5, 0, enemy.x, frontY, frontAim, 0.0f,
                                          speed - 0.5, 1, count, (count - 1) * 450, 0);
                }
            }
            else if (phase == 30 || (phase > 30 && phase < 60 && (phase - 30) % 4 == 0)) {
                if (phase == 30) {
                    enemy.secondaryAngle16 = rearAim;
                }

                const double speed = kRearSpeed[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>(phase - 30) * 0.05;
                const int spread = kRearSpread[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(0, 0, enemy.x, rearY, enemy.secondaryAngle16,
                                    10.0f, speed, 1, 0);
                if (difficulty >= 1) {
                    spawnProjectileSpread(0, 0, enemy.x, rearY, enemy.secondaryAngle16,
                                          10.0f, speed - 0.5, 1, 2, spread, 0);
                }
                if (difficulty >= 3) {
                    spawnProjectileNode(0, 0, enemy.x, rearY, enemy.secondaryAngle16,
                                        10.0f, speed + 2.5, 1, 0);
                    spawnProjectileSpread(0, 0, enemy.x, rearY, enemy.secondaryAngle16,
                                          10.0f, speed + 2.0, 1, 2, spread, 0);
                }
                if (difficulty >= 4) {
                    spawnProjectileSpread(0, 0, enemy.x, rearY, enemy.secondaryAngle16,
                                          10.0f, speed + 1.5, 1, 2, spread * 3, 0);
                }
                enemy.secondaryAngle16 =
                    approachAngle16(enemy.secondaryAngle16, rearAim, 0x40);
            }
        }
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 500);
        enemy.active = false;
    }
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    if (enemy.x < horizontalOrigin - 128.0f ||
        enemy.x > horizontalOrigin + 728.0f ||
        enemy.y < -128.0f || enemy.y > 848.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type1C(StageEnemy& enemy) {
    constexpr std::array<int, 5> kCycle{{100, 80, 60, 60, 54}};
    constexpr std::array<int, 5> kBurstWindow{{21, 30, 36, 36, 36}};
    constexpr std::array<int, 5> kFanCount{{4, 8, 10, 10, 12}};
    constexpr std::array<double, 5> kBurstSpeed{{5.5, 6.5, 8.0, 9.0, 10.5}};
    constexpr std::array<double, 5> kFanSpeed{{3.5, 4.5, 5.0, 5.0, 6.5}};

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);

    if (enemy.helperState == 0) {
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);

        if (enemy.helperTimer == 20) {
            enemy.sourceSpeed = 2.5;
            enemy.speed = 2.5f;
            enemy.sourceAngle16 = enemy.x <= 360.0f
                                      ? normalizeAngle16(6000)
                                      : static_cast<std::uint16_t>(0x6890);
            enemy.x = clampFloat(enemy.x, horizontalOrigin - 100.0f,
                                 horizontalOrigin + 700.0f);
            enemy.y = clampFloat(enemy.y, -100.0f, 820.0f);
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }
    }

    if (enemy.helperState == 1) {
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const std::size_t tableIndex = static_cast<std::size_t>(difficulty);
        const int timer = enemy.helperTimer;
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x14);
        const double movementAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(movementAngle) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(movementAngle) * enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.drawBodyThisFrame = true;

        const bool inside = enemy.x >= horizontalOrigin &&
                            enemy.x <= horizontalOrigin + 600.0f &&
                            enemy.y >= 0.0f && enemy.y <= 720.0f;
        const float fireY = enemy.y + 30.0f;
        const std::uint16_t liveAim = radiansToFixedAngleTrunc(
            std::atan2(static_cast<double>(player_.y - fireY),
                       static_cast<double>(player_.x - enemy.x)));
        const int cycle = kCycle[tableIndex];
        if (timer >= 45 && timer < 300 && (timer - 45) % cycle == 0) {
            enemy.secondaryAngle16 = liveAim;
        }

        if (inside) {
            if (timer >= 45 && timer < 300) {
                const int phase = (timer - 45) % cycle;
                if (phase < kBurstWindow[tableIndex] && phase % 3 == 0) {
                    const double speed = kBurstSpeed[tableIndex];
                    spawnProjectileNode(9, 0, enemy.x, fireY, enemy.secondaryAngle16,
                                        10.0f, speed, 1, 0);
                    if (difficulty >= 3) {
                        spawnProjectileNode(
                            9, 0, enemy.x, fireY,
                            normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 3500),
                            10.0f, speed, 1, 0);
                        spawnProjectileNode(
                            9, 0, enemy.x, fireY,
                            normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 3500),
                            10.0f, speed, 1, 0);
                    }
                }
            }

            if (timer >= 85 && timer < 300 && (timer - 85) % cycle == 0) {
                const double speed = kFanSpeed[tableIndex];
                const int count = kFanCount[tableIndex];
                spawnProjectileSpread(4, 0, enemy.x, fireY, liveAim, 0.0f,
                                      speed, 1, count, 27000, 0);
                if (difficulty >= 3) {
                    spawnProjectileSpread(4, 0, enemy.x, fireY, liveAim, 0.0f,
                                          speed + 1.2, 1, count, 27000, 0);
                }
            }
        }
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 500);
        enemy.active = false;
    }
    if (enemy.x < horizontalOrigin - 360.0f ||
        enemy.x > horizontalOrigin + 960.0f ||
        enemy.y < -360.0f || enemy.y > 1080.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type1DOr1E(StageEnemy& enemy) {
    // FUN_140086aa0/FUN_1400870a0 add the integer scroll scalar directly to y.
    enemy.y += 1.0f;
    enemy.drawBodyThisFrame = true;
    if (enemy.y >= 0.0f) {
        enemy.targetable = true;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimFrom = [this](float x, float y) {
        const float deltaY = player_.y - y;
        const float deltaX = player_.x - x;
        return radiansToFixedAngleTrunc(std::atan2(static_cast<double>(deltaY),
                                                   static_cast<double>(deltaX)));
    };

    if (enemy.targetable && enemy.y < 400.0f) {
        if (enemy.spawnType == 0x1d) {
            const int interval = kStage02Type1DInterval[static_cast<std::size_t>(difficulty)];
            const int phase = frame_ % interval;
            const float fireY = enemy.y + 30.0f;
            if (frame_ >= 0 && phase == 0) {
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(aimFrom(enemy.x, fireY)) + 0x400);
            }
            if (frame_ >= 0 && phase < 9 && phase % 3 == 0) {
                const std::uint16_t shotAngle =
                    static_cast<std::uint16_t>(enemy.secondaryAngle16 & 0xf800u);
                const double speed = kStage02Type1DSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(1, 0, enemy.x, fireY, shotAngle,
                                    0.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(1, 0, enemy.x, fireY, shotAngle,
                                        0.0f, speed + 1.8, 1, 0);
                }
            }
        }
        else {
            const int timer = enemy.helperTimer;
            const int interval = kStage02Type1EInterval[static_cast<std::size_t>(difficulty)];
            const double speed = kStage02Type1ESpeed[static_cast<std::size_t>(difficulty)];
            const float fireY = enemy.y - 60.0f;
            if (timer >= 80) {
                const int phase = (timer - 80) % interval;
                if (phase == 0) {
                    enemy.secondaryAngle16 = aimFrom(enemy.x, fireY);
                }
                if (phase < 48 && phase % 12 == 0) {
                    spawnProjectileNode(0x0c, 0, enemy.x, fireY,
                                        enemy.secondaryAngle16, 0.0f, speed, 1, 0);
                }
            }
            if (difficulty > 2 && timer >= 86) {
                const int phase = (timer - 86) % interval;
                if (phase < 36 && phase % 12 == 0) {
                    spawnProjectileNode(0x0c, 0, enemy.x, fireY,
                                        normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 600),
                                        0.0f, speed, 1, 0);
                    spawnProjectileNode(0x0c, 0, enemy.x, fireY,
                                        normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 600),
                                        0.0f, speed, 1, 0);
                }
            }
        }
    }

    if (enemy.hp < 1) {
        const int handle = effectSmallFrames_.size() > 6 ? effectSmallFrames_[6] : -1;
        const auto seed = static_cast<std::uint32_t>(enemy.entityId) +
                          static_cast<std::uint32_t>(frame_);
        const double minimumScale = enemy.spawnType == 0x1d ? 1.0 : 0.8;
        const double maximumScale = enemy.spawnType == 0x1d ? 1.2 : 1.0;
        const double scale = scriptRandomHundredth(seed, minimumScale, maximumScale);
        const float yOffset = enemy.spawnType == 0x1d ? 10.0f : 5.0f;
        spawnStageEffect(0x37, handle, 100, 0x15, enemy.x, enemy.y + yOffset,
                         scriptRandomAngle(seed), 1.0, scale, scale,
                         0x78, 0xff, 0xff, 0xff, 0x80);
        spawnEnemyDeathRewardBurst(enemy, 1000);
        enemy.active = false;
    }
    if (enemy.y >= 760.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type19(StageEnemy& enemy) {
    // FUN_1400841d0 owns movement, firing, drawing state, death, and bounds.
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(
            std::atan2(static_cast<double>(player_.y - y),
                       static_cast<double>(player_.x - x)));
    };
    const std::uint16_t entryAim = aimFrom(enemy.x, enemy.y);

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = timer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (timer < 20) {
            goto finish;
        }

        enemy.sourceSpeed = 1.4;
        if (enemy.x <= 0.0f) {
            enemy.sourceAngle16 = 0;
        }
        if (enemy.x >= 720.0f) {
            enemy.sourceAngle16 = 0x8000;
        }
        enemy.x = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                             horizontalOrigin + 620.0f);
        enemy.y = clampFloat(enemy.y, -20.0f, 740.0f);
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        const float oldX = enemy.x;
        const float oldY = enemy.y;
        const float fireY = oldY + 10.0f;

        if (timer < 150) {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, entryAim, 0x80);
            enemy.sourceSpeed += 0.02;
        }
        else {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x100);
            enemy.sourceSpeed += 0.1;
        }
        const double movementAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x = oldX + static_cast<float>(std::cos(movementAngle) * enemy.sourceSpeed);
        enemy.y = oldY + static_cast<float>(std::sin(movementAngle) * enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.drawBodyThisFrame = true;

        const bool inside = oldX >= horizontalOrigin && oldX <= horizontalOrigin + 600.0f &&
                            fireY >= 0.0f && fireY <= 720.0f;
        if (inside && timer < 150) {
            constexpr std::array<int, 5> kBaseStart{{36, 30, 24, 20, 16}};
            constexpr std::array<int, 5> kBaseInterval{{150, 48, 32, 32, 20}};
            constexpr std::array<int, 5> kLateStart{{32, 24, 20, 20, 16}};
            constexpr std::array<int, 5> kLateInterval{{80, 40, 32, 32, 20}};
            constexpr std::array<int, 5> kSpread{{900, 2800, 4000, 2500, 2500}};
            constexpr std::array<double, 5> kBaseSpeed{{4.0, 5.0, 6.0, 7.0, 8.5}};
            constexpr std::array<double, 5> kLateSpeed{{5.0, 6.0, 6.5, 7.0, 8.5}};
            const bool lateStageVariant = selectedStage_ > 7;
            const int start = (lateStageVariant ? kLateStart : kBaseStart)
                                  [static_cast<std::size_t>(difficulty)];
            const int interval = (lateStageVariant ? kLateInterval : kBaseInterval)
                                     [static_cast<std::size_t>(difficulty)];
            if (timer >= start && (timer - start) % interval == 0) {
                const auto aimed = aimFrom(oldX, fireY);
                const std::uint16_t snapped = normalizeAngle16(
                    ((static_cast<int>(aimed) + 0x400) >> 11) * 0x800);
                const int spread = kSpread[static_cast<std::size_t>(difficulty)];
                const double speed = (lateStageVariant ? kLateSpeed : kBaseSpeed)
                                         [static_cast<std::size_t>(difficulty)];
                if (difficulty >= 3) {
                    spawnProjectileSpread(5, 0, oldX, fireY, snapped, 0.0f,
                                          speed * 0.9, 1, 2, spread * 2, 0);
                }
                spawnProjectileSpread(5, 0, oldX, fireY, snapped, 0.0f,
                                      speed, 1, 2, spread, 0);
                spawnProjectileNode(5, 0, oldX, fireY, snapped, 0.0f,
                                    speed * 1.1, 1, 0);
            }
        }
    }

finish:
    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 300);
        enemy.active = false;
    }
    if (enemy.x < horizontalOrigin - 180.0f ||
        enemy.x > horizontalOrigin + 780.0f ||
        enemy.y < -180.0f || enemy.y > 900.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type1A(StageEnemy& enemy) {
    // FUN_140084be0 computes its aimed angle before state transition/movement.
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const std::uint16_t entryAim = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(player_.y - enemy.y),
                   static_cast<double>(player_.x - enemy.x)));

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = timer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (timer < 20) {
            goto finish;
        }

        const std::uint32_t random = stageScriptRandFromFrame(frame_);
        enemy.sourceSpeed = 8.6;
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(random % 0x961u) + 0x3b50);
        enemy.secondaryAngle16 = static_cast<std::uint16_t>(
            random - random / 0x10001u);
        enemy.x = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                             horizontalOrigin + 620.0f);
        enemy.y = clampFloat(enemy.y, -20.0f, 740.0f);
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        if (timer < 40) {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, entryAim, 0x80);
            if (enemy.sourceSpeed > 0.6) {
                enemy.sourceSpeed -= 0.2;
            }
        }
        else {
            enemy.sourceSpeed += 0.16;
        }

        const double movementAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(movementAngle) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(movementAngle) * enemy.sourceSpeed);
        enemy.secondaryAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + 0x378);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.drawBodyThisFrame = true;

        const bool inside = enemy.x >= horizontalOrigin &&
                            enemy.x <= horizontalOrigin + 600.0f &&
                            enemy.y >= 0.0f && enemy.y <= 720.0f;
        const float dx = enemy.x - player_.x;
        const float dy = enemy.y - player_.y;
        if (inside && dx * dx + dy * dy > 10000.0f) {
            constexpr std::array<int, 5> kBaseStart{{18, 14, 12, 12, 8}};
            constexpr std::array<int, 5> kBaseInterval{{32, 24, 16, 16, 8}};
            constexpr std::array<int, 5> kLateStart{{16, 12, 8, 8, 8}};
            constexpr std::array<int, 5> kLateInterval{{27, 20, 13, 13, 8}};
            constexpr std::array<double, 5> kShotSpeed{{5.5, 6.5, 7.5, 8.0, 9.6}};
            const bool lateStageVariant = selectedStage_ > 3;
            const int start = (lateStageVariant ? kLateStart : kBaseStart)
                                  [static_cast<std::size_t>(difficulty)];
            const int interval = (lateStageVariant ? kLateInterval : kBaseInterval)
                                     [static_cast<std::size_t>(difficulty)];
            if (timer >= start && timer < 90 && (timer - start) % interval == 0) {
                const double speed = kShotSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(0x0e, 0, enemy.x, enemy.y, entryAim,
                                    0.0f, speed, 1, 0);
                if (difficulty >= 3) {
                    spawnProjectileNode(0x0e, 0, enemy.x, enemy.y, entryAim,
                                        0.0f, speed - 2.0, 1, 0);
                }
            }
        }
    }

finish:
    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 300);
        enemy.active = false;
    }
    if (enemy.x < horizontalOrigin - 180.0f ||
        enemy.x > horizontalOrigin + 780.0f ||
        enemy.y < -180.0f || enemy.y > 900.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type1F(StageEnemy& enemy) {
    constexpr std::array<int, 5> kAimInterval{{50, 30, 30, 30, 20}};
    constexpr std::array<int, 5> kAimCount{{1, 3, 5, 5, 5}};
    constexpr std::array<double, 5> kAimSpeed{{3.0, 3.0, 4.0, 4.0, 5.0}};
    constexpr std::array<int, 5> kRingInterval{{90, 72, 60, 50, 50}};
    constexpr std::array<int, 5> kRingCount{{6, 12, 14, 16, 16}};
    constexpr std::array<double, 5> kRingSpeed{{4.0, 4.0, 4.5, 5.0, 7.0}};
    constexpr std::array<int, 5> kRingAngleStep{{18, 25, 25, 36, 42}};

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.y += 1.0f;

    if (enemy.helperState == 0 && enemy.y >= -100.0f) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
    }

    if (enemy.helperState == 1) {
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const std::size_t tableIndex = static_cast<std::size_t>(difficulty);
        const int timer = enemy.helperTimer;
        if (timer == 50) {
            enemy.targetable = true;
        }

        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        const bool inside = enemy.x >= horizontalOrigin - 50.0f &&
                            enemy.x <= horizontalOrigin + 650.0f &&
                            enemy.y >= -50.0f && enemy.y <= 770.0f;
        if (inside && enemy.y < 350.0f) {
            const int aimInterval = kAimInterval[tableIndex];
            if (timer >= 50 && (timer - 50) % aimInterval == 0) {
                const float fireY = enemy.y + 70.0f;
                const std::uint16_t aim = radiansToFixedAngleTrunc(
                    std::atan2(static_cast<double>(player_.y - fireY),
                               static_cast<double>(player_.x - enemy.x)));
                const int count = kAimCount[tableIndex];
                const double speed = kAimSpeed[tableIndex];
                spawnProjectileSpread(3, 1, enemy.x, fireY, aim, 10.0f,
                                      speed, 1, count, 18000, 0);
                if (difficulty >= 3) {
                    spawnProjectileSpread(3, 1, enemy.x, fireY,
                                          normalizeAngle16(static_cast<int>(aim) + 800),
                                          10.0f, speed, 1, count, 18000, 0);
                    spawnProjectileSpread(3, 1, enemy.x, fireY,
                                          normalizeAngle16(static_cast<int>(aim) - 800),
                                          10.0f, speed, 1, count, 18000, 0);
                }
            }

            const int ringInterval = kRingInterval[tableIndex];
            if (timer >= 60) {
                const int phase = (timer - 60) % ringInterval;
                if (phase < 32 && phase % 8 == 0) {
                    const int direction = enemy.x < 360.0f ? -1 : 1;
                    const std::uint16_t angle = normalizeAngle16(
                        direction * kRingAngleStep[tableIndex] * timer);
                    const float fireY = enemy.y - 55.0f;
                    const int count = kRingCount[tableIndex];
                    const double speed = kRingSpeed[tableIndex];
                    spawnProjectileSpread(4, 0, enemy.x, fireY, angle, 0.0f,
                                          speed, 1, count, kFixedAngleFullCircle, 0);
                    spawnProjectileSpread(
                        4, 0, enemy.x, fireY,
                        normalizeAngle16(static_cast<int>(angle) + 800), 0.0f,
                        speed, 1, count, kFixedAngleFullCircle, 0);
                }
            }
        }

        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }

    if (enemy.helperState == 2 && enemy.helperTimer <= 60) {
        spawnStage02DeathExplosionChain(enemy);
        if (enemy.helperTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            const int handle = effectMediumFrames_.size() > 18 ? effectMediumFrames_[18] : -1;
            const auto seed = static_cast<std::uint32_t>(enemy.entityId) +
                              static_cast<std::uint32_t>(frame_);
            const double scale = scriptRandomHundredth(seed, 1.0, 1.1);
            spawnStageEffect(0x37, handle, 200, 0x15, enemy.x, enemy.y + 30.0f,
                             scriptRandomAngle(seed), 1.0, scale, scale,
                             0x78, 0xff, 0xff, 0xff, 0x80);
            enemy.active = false;
        }
    }
    if (enemy.helperState != 2 && enemy.y >= 820.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type20(StageEnemy& enemy) {
    // FUN_140088110 advances vertically inside the helper rather than through
    // the common velocity path.
    enemy.y += 1.0f;

    if (enemy.helperState == 0) {
        if (enemy.helperTimer == 0) {
            constexpr std::array<float, 5> kChildX{{420.0f, 235.0f, 570.0f, 125.0f, 620.0f}};
            constexpr std::array<float, 5> kChildYOffset{{320.0f, 260.0f, 210.0f, 120.0f, 60.0f}};
            for (std::size_t i = 0; i < kChildX.size(); ++i) {
                spawnStage02Type21Child(enemy, static_cast<int>(i), kChildX[i], kChildYOffset[i]);
            }
            enemy.liveChildCount = 5;
        }

        if (enemy.y >= -150.0f) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }
    }

    if (enemy.helperState == 1) {
        constexpr std::array<int, 5> kShotInterval{{45, 30, 20, 15, 15}};
        constexpr std::array<int, 5> kShotCount{{7, 11, 15, 19, 21}};
        constexpr std::array<double, 5> kShotSpeed{{5.0, 6.0, 7.0, 7.5, 9.5}};
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int timer = enemy.helperTimer;
        const float bob = 2.0f * std::sin(static_cast<float>(timer) * kTau / 72.0f);
        const float fireY = enemy.y + 85.0f + bob;

        if (enemy.y < 350.0f && timer >= 50) {
            const int interval = kShotInterval[static_cast<std::size_t>(difficulty)];
            const int localTimer = timer - 50;
            const int cycle = localTimer % 120;
            if (cycle < 60 && cycle % interval == 0) {
                enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                    std::atan2(static_cast<double>(player_.y - fireY),
                               static_cast<double>(player_.x - enemy.x)));
                const int randomOffset = static_cast<int>(stageScriptRandFromFrame(timer) % 3001u) - 1500;
                const std::uint16_t centerAngle =
                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + randomOffset);
                spawnProjectileSpread(3, 7, enemy.x, fireY, centerAngle, 10.0f,
                                      kShotSpeed[static_cast<std::size_t>(difficulty)], 1,
                                      kShotCount[static_cast<std::size_t>(difficulty)], 0x8000, 0);
            }
        }

        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x0708);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }

    if (enemy.helperState == 2 && enemy.helperTimer <= 0x3c) {
        spawnStage02DeathExplosionChain(enemy);
        if (enemy.helperTimer == 0x3c) {
            spawnEnemyDeathEffects(enemy, 2);
            const int handle = effectLargeFrames_.size() > 12 ? effectLargeFrames_[12] : -1;
            const auto seed = static_cast<std::uint32_t>(enemy.entityId) +
                              static_cast<std::uint32_t>(frame_);
            const double scale = scriptRandomHundredth(seed, 0.9, 1.0);
            spawnStageEffect(0x37, handle, 600, 0x15, enemy.x, enemy.y + 60.0f,
                             scriptRandomAngle(seed), 1.0, scale, scale,
                             0x78, 0xff, 0xff, 0xff, 0x80);
            enemy.active = false;
            stage02GateFlag_ = false;
        }
    }
    if (enemy.helperState != 2 && enemy.y >= 1080.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage02Type21(StageEnemy& enemy) {
    // FUN_140088c20 resolves the parent before advancing this child. A missing,
    // inactive, or defeated parent clears the child without a reward payout.
    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    const bool parentActive = parent != nullptr && parent->active;
    const int parentHp = parent != nullptr ? parent->hp : 0;
    enemy.drawBodyThisFrame = false;
    enemy.y += 1.0f;

    if (enemy.helperState == 0 && enemy.y >= -55.0f) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
    }

    if (enemy.helperState == 1) {
        constexpr std::array<int, 5> kCycleLength{{180, 150, 120, 120, 100}};
        constexpr std::array<int, 5> kFanStep{{20, 14, 10, 10, 8}};
        constexpr std::array<int, 5> kSpreadStep{{6000, 4400, 3200, 3200, 2800}};
        constexpr std::array<double, 5> kShotSpeed{{4.0, 5.0, 5.5, 6.0, 7.5}};
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int timer = enemy.helperTimer;

        if (timer == 0x1e) {
            enemy.targetable = true;
        }

        const float horizontalOrigin = player_.x / 6.0f;
        const bool insideFiringArea = enemy.x >= horizontalOrigin &&
                                      enemy.x <= horizontalOrigin + 600.0f &&
                                      enemy.y >= 0.0f && enemy.y <= 720.0f;
        if (insideFiringArea && enemy.y < 350.0f && timer >= 0x3c) {
            const int cycleLength = kCycleLength[static_cast<std::size_t>(difficulty)];
            const int phase = (timer - 0x3c) % cycleLength;
            const int fanStep = kFanStep[static_cast<std::size_t>(difficulty)];
            const float fireY = enemy.y - 20.0f;

            if (phase == 0) {
                enemy.secondaryAngle16 =
                    radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, fireY)));
            }
            if (phase < 0x30 && phase % fanStep == 0) {
                const int fanIndex = phase / fanStep;
                spawnProjectileSpread(0x0c, 0, enemy.x, fireY, enemy.secondaryAngle16,
                                      10.0f, kShotSpeed[static_cast<std::size_t>(difficulty)], 1,
                                      fanIndex + 1,
                                      kSpreadStep[static_cast<std::size_t>(difficulty)] * fanIndex, 0);
            }

            if (difficulty >= 3 && phase < 0x19 && phase % 5 == 0) {
                const int count = phase / 5 + 1;
                spawnProjectileSpread(0x0d, 0, enemy.x, fireY, enemy.secondaryAngle16,
                                      10.0f, kShotSpeed[static_cast<std::size_t>(difficulty)] + 3.0,
                                      1, count, (count - 1) * 250, 0);
            }
        }
        enemy.drawBodyThisFrame = true;
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 1000);
        if (parent != nullptr) {
            --parent->liveChildCount;
        }
        enemy.active = false;
    }
    if (parentHp < 1) {
        spawnEnemyDeathEffects(enemy, 1);
    }
    if (parentHp < 1 || !parentActive) {
        enemy.active = false;
    }
}

void StageRuntime::spawnStage02DeathExplosionChain(const StageEnemy& enemy) {
    const int timer = enemy.helperTimer;
    if (timer % 3 == 0) {
        const std::uint32_t random = stageScriptRandFromFrame(timer);
        const std::uint16_t burstAngle = scriptRandomAngle(static_cast<std::uint32_t>(timer));
        const int distance = static_cast<int>(
            random % static_cast<std::uint32_t>(enemy.radius + 51));
        const double burstRadians = fixedAngleToRadiansDouble(burstAngle);
        const float x = enemy.x + static_cast<float>(std::cos(burstRadians) * distance);
        const float y = enemy.y + static_cast<float>(std::sin(burstRadians) * distance);

        const double scaleBase = static_cast<double>(enemy.radius) / 200.0 + 0.1;
        const double burstScale = scriptRandomHundredth(
            static_cast<std::uint32_t>(frame_), scaleBase, scaleBase + 0.3);
        const int burstHandle = effectMediumFrames_.size() > 5
                                    ? effectMediumFrames_[5]
                                    : -1;
        const bool deathChainGate = selectedStage_ == 1
                                        ? stage01GateFlag_
                                        : (selectedStage_ == 2
                                               ? stage02GateFlag_
                                               : (selectedStage_ == 3
                                                      ? stage03GateFlag_
                                                      : (selectedStage_ == 4 &&
                                                         stage04GateFlag_)));
        spawnStageEffect(deathChainGate ? 0x2b : 0x2a,
                         burstHandle, 200, 0x3e, x, y, burstAngle,
                         1.0, burstScale, burstScale, 0x18,
                         0xff, 0xff, 0xff, 0xff);

        const std::uint32_t angleSeed = static_cast<std::uint32_t>(timer) * 0x37u;
        const std::uint32_t scaleSeed = static_cast<std::uint32_t>(timer) * 0x15b3u;
        const std::uint32_t speedSeed = static_cast<std::uint32_t>(frame_) * 0x22bu;
        const std::uint16_t sparkAngle = scriptRandomAngle(angleSeed);
        const double sparkScale = scriptRandomHundredth(scaleSeed, 0.8, 1.6);
        const double sparkSpeed = scriptRandomHundredth(speedSeed, 14.0, 22.0);
        const int sparkHandle = playerFrames_.size() > 14 ? playerFrames_[14] : -1;
        spawnStageEffect(0x2c, sparkHandle, 80, 0x48, x, y, sparkAngle,
                         sparkSpeed, sparkScale, sparkScale, 0,
                         0xff, 0xff, 0xff, 0xc0);
    }

    if (timer % 6 == 0) {
        playPlayerSound(blast1SoundHandle_, 0x14);
    }
}

void StageRuntime::spawnBackgroundEffects() {
    if (selectedStage_ == 3) {
        const int graph = effectLargeFrames_.size() > 13
                              ? effectLargeFrames_[13]
                              : -1;
        const auto spawnTower = [this, graph](float x) {
            spawnStageEffect(0x3a, graph, 600, 0x13,
                             x, -200.0f, 0, 0.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xff);
        };
        if (frame_ == 0x578) {
            spawnTower(492.0f);
        }
        else if (frame_ == 0x10b8) {
            spawnTower(213.0f);
        }
        else if (frame_ == 0x1c0c) {
            spawnTower(105.0f);
            spawnTower(622.0f);
        }
    }

    if (selectedStage_ == 4) {
        const int stageEnd = kStageEndFrames[4];
        int brightness = 0xc0;
        if (stageEnd > 0 && frame_ >= 0 && frame_ < stageEnd) {
            const double phase = static_cast<double>(frame_ + stageEnd) * kPi /
                                 (2.0 * static_cast<double>(stageEnd));
            brightness = 0x80 + static_cast<int>(std::sin(phase) * 64.0);
        }
        else if (frame_ >= stageEnd) {
            brightness = 0x80;
        }

        if (frame_ % 0x28 == 5) {
            const int graph = effectLargeFrames_.size() > 14
                                  ? effectLargeFrames_[14]
                                  : -1;
            spawnStageEffect(0x3b, graph, 600, 5,
                             360.0f, 750.0f, 0xc000, 1.0, 0.0, 0.0, 0x5a,
                             brightness, brightness, brightness, 0x60);
        }
        if (frame_ % 0x3f == 5) {
            const std::uint32_t random = stageScriptRandFromFrame(frame_);
            const auto angle = normalizeAngle16(
                static_cast<int>(random % 0x5dc1u) - 0x6ee0);
            const double speed = scriptRandomHundredth(
                static_cast<std::uint32_t>(frame_), 1.5, 3.0);
            const int graph = effectMediumFrames_.size() > 19
                                  ? effectMediumFrames_[19]
                                  : -1;
            spawnStageEffect(0x3c, graph, 200, 6,
                             360.0f, 750.0f, angle, speed, 0.0, 0.0, 0x96,
                             brightness, brightness, brightness, 0x60);
        }
    }

    if (selectedStage_ == 5 && frame_ <= 11800 - 600) {
        if (player_.animationClock % 0x18 == 0) {
            const int graph = stageBack2Frames_.size() > 1
                                  ? stageBack2Frames_[1]
                                  : -1;
            spawnStageEffect(0x3d, graph, 720, 5,
                             360.0f, 640.0f, 0xc000, 0.5, 0.0, 0.0, 0x78,
                             0xff, 0xff, 0xff, 0xff);
        }
        if (player_.animationClock % 0x13 == 0) {
            const int graph = stageBack2Frames_.size() > 2
                                  ? stageBack2Frames_[2]
                                  : -1;
            spawnStageEffect(0x3e, graph, 720, 10,
                             360.0f, 640.0f, 0xc000, 0.5, 0.0, 0.0, 0x78,
                             0xff, 0xff, 0xff, 0x80);
        }
    }

    if (selectedStage_ == 8 && frame_ >= 0x1a90 && frame_ < 0x2968 &&
        (player_.animationClock & 0x1f) == 0) {
        const int graph = stageBack2Frames_.size() > 5
                              ? stageBack2Frames_[5]
                              : -1;
        spawnStageEffect(0x42, graph, 720, 5,
                         360.0f, 640.0f, 0xc000, 2.0, 0.0, 0.0, 100,
                         0xff, 0xff, 0xff, 0xff);
    }
}

void StageRuntime::spawnStageEffect(int type, int graphHandle, int graphExtent, int drawLayer,
                                    float x, float y, std::uint16_t angle16,
                                    double scale0, double scaleX, double scaleY,
                                    int lifetime, int colorR, int colorG, int colorB, int alpha,
                                    int ownerEntityId) {
    const bool graphlessFamily = type == 0x10 || type == 0x11 ||
                                 type == 0x19 ||
                                 type == 0x1a ||
                                 type == 0x1d || type == 0x1e ||
                                 type == 0x1f || type == 0x28 ||
                                 type == 0x2d ||
                                 type == 0x36;
    if ((!graphlessFamily && graphHandle == -1) || stageEffects_.size() >= kStageEffectCap) {
        return;
    }

    StageEffect effect;
    effect.type = type;
    effect.graphHandle = graphHandle;
    effect.graphExtent = graphExtent;
    effect.drawLayer = drawLayer;
    effect.x = x;
    effect.y = y;
    effect.angle16 = angle16;
    effect.scale0 = scale0;
    effect.scaleX = scaleX;
    effect.scaleY = scaleY;
    effect.lifetime = lifetime;
    effect.colorR = colorR;
    effect.colorG = colorG;
    effect.colorB = colorB;
    effect.alpha = alpha;
    effect.ownerEntityId = ownerEntityId;
    if (type == 0x2c) {
        effect.randomSeed = static_cast<std::uint32_t>(angle16) +
                            static_cast<std::uint32_t>(frame_);
    }
    else if (type == 0x3b || type == 0x3d || type == 0x3e) {
        // FUN_140076ec0 derives the fixed rotation from
        // DAT_140e44acc - age, i.e. the animation clock at creation.
        effect.randomSeed = static_cast<std::uint32_t>(player_.animationClock);
    }
    else if (type == 0x33 || type == 0x3a) {
        effect.randomSeed = static_cast<std::uint32_t>(frame_);
    }
    stageEffects_.push_back(effect);
}

void StageRuntime::updateStageEffects() {
    // The original list walk observes nodes appended to its tail by an effect
    // helper. The vector is reserved to the hard cap, so index iteration keeps
    // references stable while preserving that same-frame behavior.
    for (std::size_t effectIndex = 0; effectIndex < stageEffects_.size(); ++effectIndex) {
        auto& effect = stageEffects_[effectIndex];
        effect.drawQueuedThisFrame = false;
        if (!effect.active) {
            continue;
        }

        const int age = effect.age;
        switch (effect.type) {
        case 0x08: {
            // FUN_140071cb0 type 8 keeps alpha constant while both axes shrink
            // linearly to zero. Motion is applied before the mode-7 draw.
            const int lifetime = std::max(1, effect.lifetime);
            const double remaining =
                1.0 - static_cast<double>(age) / static_cast<double>(lifetime);
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX * remaining;
            effect.drawScaleY = effect.scaleY * remaining;
            effect.drawAlpha = effect.alpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x0d: {
            // FUN_140070e40 handles type 0x0d inline: the impact afterimage
            // keeps travelling along the shot heading, expands by 0.02 per
            // frame on both axes, and fades linearly over exactly eight frames.
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            const double growth = static_cast<double>(age) * 0.02;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX + growth;
            effect.drawScaleY = effect.scaleY + growth;
            effect.drawAlpha = effect.alpha - static_cast<int>(
                static_cast<double>(effect.alpha) * 0.125 *
                static_cast<double>(age));
            effect.drawQueuedThisFrame = true;
            if (age == 8) {
                effect.active = false;
            }
            break;
        }
        case 0x0e: {
            // FUN_1400732a0 keeps (global gameplay tick - age) stable, so this
            // random choice is fixed for the particle's whole life. It selects
            // both the 10..20 frame lifetime and the per-frame spin step.
            if (age == 0) {
                effect.randomSeed = static_cast<std::uint32_t>(effect.angle16) +
                                    static_cast<std::uint32_t>(frame_);
            }
            const std::uint32_t random = stageScriptRandFromFrame(
                static_cast<int>(effect.randomSeed));
            const int randomPhase = static_cast<int>(random % 11u);
            const int lifetime = randomPhase + 10;

            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.scaleX += 0.01;

            int drawAlpha = effect.alpha;
            const int fadeStart = randomPhase + 2;
            if (age >= lifetime) {
                drawAlpha = 0;
            }
            else if (age >= fadeStart) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(age - (randomPhase - 6)) *
                             kPi / 16.0) *
                    static_cast<double>(effect.alpha));
            }

            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) +
                (static_cast<int>(random % 571u) + 30) * age);
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x10:
        case 0x11:
        case 0x36: {
            // FUN_140072930 expands these graphless terminal-burst drivers once
            // and then unlinks the driver. Types 0x10/0x11 own the full burst;
            // type 0x10 additionally plays Miss2, while 0x36 is the small burst.
            const bool fullBurst = effect.type != 0x36;
            const int radialCount = fullBurst ? 0x30 : 0x0c;
            const double radialSpeedStep = fullBurst ? 0.4 : 1.6;
            const double radialScaleStep = fullBurst ? 0.02 : 0.06;
            const int radialHandle = effectMediumFrames_.size() > 3
                                         ? effectMediumFrames_[3]
                                         : -1;
            for (int i = 0; i < radialCount; ++i) {
                const double speed = 3.0 + static_cast<double>(i) * radialSpeedStep;
                const double scale = 0.1 + static_cast<double>(i) * radialScaleStep;
                spawnStageEffect(
                    0x12, radialHandle, 0x4f, 0x4f, effect.x, effect.y,
                    scriptRandomAngle(static_cast<std::uint32_t>(frame_ + i)),
                    speed, scale, scale, 0,
                    0xff, 0xff, 0xff, 0xff);
            }

            const int sparkCount = fullBurst ? 0x20 : 8;
            const int sparkHandle = playerFrames_.size() > 14
                                        ? playerFrames_[14]
                                        : -1;
            for (int i = 0; i < sparkCount; ++i) {
                const std::uint32_t angleSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x37);
                const std::uint32_t scaleSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x15b3);
                const std::uint32_t speedSeed =
                    static_cast<std::uint32_t>(frame_ + i * 0x22b);
                const double scale = scriptRandomHundredth(scaleSeed, 1.1, 2.2);
                spawnStageEffect(
                    0x2c, sparkHandle, 80, 0x48, effect.x, effect.y,
                    scriptRandomAngle(angleSeed),
                    scriptRandomHundredth(speedSeed, 16.0, 26.0),
                    scale, scale, 0,
                    0xff, 0xff, 0xff, 0xc0);
            }

            if (fullBurst) {
                const int centerHandle = effectLargeFrames_.empty()
                                             ? -1
                                             : effectLargeFrames_[0];
                spawnStageEffect(0x13, centerHandle, 200, 0x5b,
                                 effect.x, effect.y, 0,
                                 0.0, 0.0, 0.0, 0,
                                 0xff, 0xff, 0xff, 0xff);
            }
            if (effect.type == 0x10) {
                playPlayerSound(miss2SoundHandle_, 0x19);
            }
            effect.active = false;
            break;
        }
        case 0x12: {
            // FUN_140073050 grows and spins the medium particle while applying
            // its age-dependent downward acceleration. Even frames use one of
            // the original seven palette colors; odd frames are white.
            static constexpr std::array<std::array<int, 3>, 7> kColors{{
                {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
                {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
                {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
                {{0xdc, 0x78, 0xff}},
            }};
            const std::uint32_t random = stageScriptRandFromFrame(
                static_cast<int>(effect.angle16) + age);
            if ((age & 1) == 0) {
                const auto& color = kColors[static_cast<std::size_t>(random % 7u)];
                effect.colorR = color[0];
                effect.colorG = color[1];
                effect.colorB = color[2];
            }
            else {
                effect.colorR = 0xff;
                effect.colorG = 0xff;
                effect.colorB = 0xff;
            }

            effect.scaleX += 0.02;
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0 +
                                           static_cast<double>(age) * 0.4);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) + age * 0x400);
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = age > 0x30 ? 0x3ff - age * 0x10 : 0xff;
            effect.drawQueuedThisFrame = true;
            if (age == 0x40) {
                effect.active = false;
            }
            break;
        }
        case 0x13: {
            // The center flash starts at zero scale, grows by 0.1 per update,
            // and fades over the final sixteen visible frames.
            if (age == 0x30) {
                effect.active = false;
                break;
            }
            effect.scaleX += 0.1;
            effect.scaleY = effect.scaleX;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = 0;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = age > 0x1f ? 0x2ff - age * 0x10 : 0xff;
            effect.drawQueuedThisFrame = true;
            break;
        }
        case 0x15: {
            // FUN_140078110 is the persistent Fever-ready orbit. It follows
            // one third of the player delta, draws three palette-cycling
            // nodes, and switches to a sixty-frame negative-age fade as soon
            // as the gauge leaves the ready range.
            constexpr std::array<std::array<int, 3>, 7> kFeverColors{{
                {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
                {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
                {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
                {{0xdc, 0x78, 0xff}},
            }};

            double baseScale = 1.0;
            int orbitRadius = 90;
            int spinStep = 600;
            if (age >= 0 && age < 30) {
                const double entrance = std::sin(
                    static_cast<double>(age) * kPi / 60.0);
                baseScale = entrance;
                orbitRadius = static_cast<int>(entrance * 90.0);
                spinStep = 2000 - static_cast<int>(entrance * 1400.0);
            }
            else if (age >= -60 && age < 0) {
                const double fade = 1.0 - std::sin(
                    static_cast<double>(age + 60) * kPi / 120.0);
                baseScale = fade;
                orbitRadius = 90 - static_cast<int>((1.0 - fade) * 90.0);
                spinStep = 2000;
            }
            if (player_.specialGauge < 0) {
                spinStep = 1200;
            }

            effect.angle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) + spinStep);
            effect.x += (player_.x - effect.x) / 3.0f;
            effect.y += (player_.y - effect.y) / 3.0f;

            const int colorClock = std::max(player_.drawAnimationClock, 0);
            const int colorIndex =
                (colorClock / 20) % static_cast<int>(kFeverColors.size());
            const int nextColorIndex =
                (colorIndex + 1) % static_cast<int>(kFeverColors.size());
            const int colorStep = colorClock % 20;
            const auto channel = [&](std::size_t index) {
                const int current =
                    kFeverColors[static_cast<std::size_t>(colorIndex)][index];
                const int next =
                    kFeverColors[static_cast<std::size_t>(nextColorIndex)][index];
                return static_cast<int>(
                    static_cast<double>(current) -
                    (static_cast<double>(current - next) / 20.0) *
                        static_cast<double>(colorStep));
            };
            effect.colorR = channel(0);
            effect.colorG = channel(1);
            effect.colorB = channel(2);
            effect.scale0 = static_cast<double>(orbitRadius);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = normalizeAngle16(static_cast<int>(
                std::sin(static_cast<double>(colorClock) * kPi / 45.0) *
                2000.0));
            const double pulse =
                1.0 + std::sin(static_cast<double>(colorClock) * kPi / 45.0) * 0.1;
            effect.drawScaleX = baseScale * pulse;
            effect.drawScaleY = baseScale * pulse;
            effect.drawAlpha = effect.alpha;
            effect.drawQueuedThisFrame = true;

            if (age == -1) {
                effect.active = false;
            }
            else if (age >= 0 && player_.specialGauge < 50000) {
                // The dispatcher increments age after the helper, so the next
                // observed age is -59 exactly as in the original list walk.
                effect.age = -60;
            }
            break;
        }
        case 0x16: {
            // FUN_140070e40 queues this full-screen portrait through age 300.
            // Its renderer mode is top-left DrawGraph rather than the centered
            // stage-coordinate mode used by the ordinary effect families.
            constexpr double kPiDouble = 3.14159265358979;
            int drawAlpha = effect.alpha;
            if (age < 8) {
                drawAlpha = static_cast<int>(
                    static_cast<double>(effect.alpha) *
                    std::sin(static_cast<double>(age) * kPiDouble / 16.0));
            }
            else if (age >= effect.lifetime - 8) {
                drawAlpha = effect.alpha - static_cast<int>(
                    static_cast<double>(effect.alpha) *
                    std::sin(static_cast<double>(age - (effect.lifetime - 8)) *
                             kPiDouble / 16.0));
            }
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleY;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x17:
        case 0x18: {
            // FUN_140076130: type 0x17 is a vertically opening dual
            // alpha/additive node; type 0x18 is the ordinary Fever trail.
            const int lifetime = std::max(1, effect.lifetime);
            const double entrance = age < 0
                                        ? 0.0
                                        : (age < 5
                                               ? std::sin(static_cast<double>(age) *
                                                          kPi / 10.0)
                                               : 1.0);
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = 0;
            effect.drawScaleX = effect.type == 0x17
                                    ? 1.0
                                    : entrance * effect.scaleX;
            effect.drawScaleY = entrance * effect.scaleY;
            effect.drawAlpha = age >= lifetime - 8
                                   ? static_cast<int>(sineEaseOut(
                                         age - (lifetime - 8), 8,
                                         static_cast<float>(effect.alpha)))
                                   : effect.alpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x26:
        case 0x27: {
            // FUN_140073e60 keeps the bonus banner at a fixed screen point,
            // blinks it in three-frame half-alpha bands, and emits one score
            // item per update (two for the no-miss type 0x26) until the final
            // sixty frames of the node lifetime.
            effect.drawX = 640.0f;
            effect.drawY = 190.0f;
            effect.drawAngle16 = 0;
            effect.drawScaleX = 1.0;
            effect.drawScaleY = 1.0;
            effect.drawAlpha = age % 6 <= 2 ? 0x80 : 0xff;
            effect.drawQueuedThisFrame = true;

            if (age < effect.lifetime - 60) {
                const int itemType = age % 10 == 0 ? 4 : 3;
                const int itemCount = effect.type == 0x26 ? 2 : 1;
                const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
                for (int itemIndex = 0; itemIndex < itemCount; ++itemIndex) {
                    const std::uint32_t pointSeed =
                        static_cast<std::uint32_t>(frame_ + itemIndex * 111);
                    const int distance = stageRandomIntInclusive(pointSeed, 150, 200);
                    const std::uint16_t pointAngle = scriptRandomAngle(pointSeed);
                    const double radians = fixedAngleToRadiansDouble(pointAngle);
                    const float pointX = std::clamp(
                        effect.x + static_cast<float>(std::cos(radians) * distance),
                        horizontalOrigin, horizontalOrigin + 600.0f);
                    const float pointY = std::clamp(
                        effect.y + static_cast<float>(std::sin(radians) * distance),
                        0.0f, 720.0f);
                    const std::uint32_t itemSeed =
                        static_cast<std::uint32_t>(frame_ + itemIndex * 0x22b8);
                    spawnRewardItem(itemType, pointX, pointY,
                                    scriptRandomAngle(itemSeed), 2.0f,
                                    itemType == 4 ? 45 : 30);
                }
            }
            if (age == 0) {
                playPlayerSound(bonusSoundHandle_, 0x19);
            }
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x28: {
            // The four digit calls use the original raw screen coordinates;
            // drawStageEffects expands this graphless snapshot.
            const int countdown = std::clamp(static_cast<int>(effect.scale0), 0, 5999);
            effect.colorR = 0xff;
            effect.colorG = std::min(countdown, 0xff);
            effect.colorB = std::min(countdown, 0xff);
            effect.drawAlpha = age % 5 == 0 ? 0x80 : 0xff;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x38: {
            const int lifetime = std::max(1, effect.lifetime);
            const double fade = std::clamp(
                1.0 - static_cast<double>(age) / static_cast<double>(lifetime),
                0.0, 1.0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleY;
            effect.drawAlpha = static_cast<int>(static_cast<double>(effect.alpha) * fade);
            effect.drawQueuedThisFrame = true;
            if (age >= lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x04:
        case 0x05:
        case 0x07: {
            // FUN_140071cb0 keeps the original scale for types 4..7 and
            // linearly fades alpha after applying the per-frame velocity.
            const int lifetime = std::max(1, effect.lifetime);
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleY;
            effect.drawAlpha = effect.alpha - static_cast<int>(
                (static_cast<double>(effect.alpha) /
                 static_cast<double>(lifetime)) * static_cast<double>(age));
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x22: {
            // FUN_140072560 uses a linear scale ramp for effect types 0x22..0x25.
            // This dash-exit node is stationary and fades only in its last eight frames.
            const int lifetime = std::max(1, effect.lifetime);
            const double drawScale = effect.scaleX *
                                     static_cast<double>(age) /
                                     static_cast<double>(lifetime);
            int drawAlpha = effect.alpha;
            if (age >= lifetime - 8) {
                drawAlpha -= static_cast<int>(
                    static_cast<double>((age - lifetime) + 8) *
                    static_cast<double>(effect.alpha) * 0.125);
            }
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = drawScale;
            effect.drawScaleY = drawScale;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x20: {
            // FUN_140072560 duplicates the first constructor scale into both
            // renderer axes for type 0x20; the second stored scale is unused.
            const int lifetime = std::max(1, effect.lifetime);
            const double drawScale =
                std::sin(static_cast<double>(age) * kPi /
                         (2.0 * static_cast<double>(lifetime))) *
                effect.scaleX;
            int drawAlpha = effect.alpha;
            if (age >= lifetime - 8) {
                drawAlpha -= static_cast<int>(
                    static_cast<double>((age - lifetime) + 8) *
                    static_cast<double>(effect.alpha) * 0.125);
            }
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = drawScale;
            effect.drawScaleY = drawScale;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x41: {
            // FUN_140077cf0 resolves +0x54 as a stage-entity id on every update.
            // drawStageEffects expands this snapshot into the eleven trail nodes.
            const StageEnemy* owner = findEnemyById(effect.ownerEntityId);
            if (owner == nullptr) {
                effect.active = false;
                break;
            }
            effect.x = owner->x;
            effect.y = owner->y;
            effect.angle16 = owner->sourceAngle16;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleY;
            effect.drawAlpha = effect.alpha;
            effect.drawQueuedThisFrame = true;
            if (age % 10 == 0) {
                playPlayerSound(bossSe4SecondSoundHandle_, 0x10);
            }
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x0c: {
            const int lifetime = std::max(1, effect.lifetime);
            const double drawScale =
                std::sin(static_cast<double>(age) * kPi /
                         (2.0 * static_cast<double>(lifetime))) *
                effect.scaleX;
            int drawAlpha = effect.alpha;
            if (effect.lifetime - 8 <= age) {
                drawAlpha -= static_cast<int>(
                    static_cast<double>((age - effect.lifetime) + 8) *
                    static_cast<double>(effect.alpha) * 0.125);
            }
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = drawScale;
            effect.drawScaleY = drawScale;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x19:
        case 0x1a: {
            const int multiplier = std::max(0, static_cast<int>(effect.scaleX));
            if (age == 0) {
                player_.scoreItemBaseValue += multiplier;
                if (player_.specialGauge >= 0) {
                    const double difficultyScale = std::max(
                        0.6, 1.0 - static_cast<double>(config_.difficulty / 2) * 0.1);
                    const int amount = static_cast<int>(
                        difficultyScale * static_cast<double>(multiplier) *
                        static_cast<double>(effect.type == 0x19 ? 30 : 10));
                    player_.specialGauge += amount;
                    if (player_.specialGauge < 0) {
                        player_.specialGauge = 0;
                    }
                }
                hudSpecialGaugeFlashTimer_ = 60;
            }

            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);

            double entranceScale = 1.0;
            if (age < 0) {
                entranceScale = 0.0;
            }
            else if (age < 5) {
                entranceScale = std::sin(static_cast<double>(age) * kPi / 10.0);
            }
            int drawAlpha = effect.alpha;
            if (age >= effect.lifetime) {
                drawAlpha = 0;
            }
            else if (age >= effect.lifetime - 8) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(
                                 age - (effect.lifetime - 16)) *
                             kPi / 16.0) *
                    static_cast<double>(effect.alpha));
            }

            const int frameIndex = age < multiplier * 2
                                       ? age / 2 + 1
                                       : multiplier;
            effect.graphHandle = frameIndex >= 0 &&
                                         frameIndex < static_cast<int>(itemFrames_.size())
                                     ? itemFrames_[static_cast<std::size_t>(frameIndex)]
                                     : -1;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = 0;
            effect.drawScaleX = entranceScale * effect.scaleY;
            effect.drawScaleY = entranceScale * effect.scaleY;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x1d: {
            if (age % 3 == 1) {
                const std::uint32_t pointSeed =
                    static_cast<std::uint32_t>(age) * 0x378u +
                    static_cast<std::uint32_t>(frame_);
                const std::uint32_t distanceSeed =
                    static_cast<std::uint32_t>(age) * 0x22b8u +
                    static_cast<std::uint32_t>(frame_);
                const std::uint16_t sampleAngle = normalizeAngle16(
                    static_cast<int>(scriptRandomAngle(pointSeed)) - 0x4000);
                const int distance = stageRandomIntInclusive(
                    distanceSeed, 0,
                    std::max(0, static_cast<int>(effect.scaleY)));
                const double sampleRadians =
                    fixedAngleToRadiansDouble(sampleAngle);
                const float pointX = effect.x + static_cast<float>(
                    std::cos(sampleRadians) * static_cast<double>(distance));
                const float pointY = effect.y + static_cast<float>(
                    std::sin(sampleRadians) * static_cast<double>(distance));
                const std::uint32_t random = stageScriptRandFromFrame(
                    static_cast<int>(distanceSeed));
                const std::uint16_t childAngle = normalizeAngle16(
                    static_cast<int>(random % 12001u) - 22384);
                spawnStageEffect(
                    0x19, -1, 0, 0x42, pointX, pointY, childAngle,
                    1.0, effect.scaleX, effect.scaleX * 0.1 + 0.5, 50,
                    0xff, 0xff, 0xff, 0xc0);
                playPlayerSound(item2SoundHandle_, 0x0c);
            }
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x1e:
        case 0x1f: {
            // FUN_140073e60 uses these graphless post-hit drivers to discharge
            // Dream Gauge. Type 0x1f is the faster terminal-death variant.
            if (player_.specialGauge >= kSpecialGaugeReady) {
                player_.specialGauge = 48000;
            }
            if (player_.specialGauge > 0) {
                const double stageScale = std::max(
                    0.6,
                    1.0 - static_cast<double>(selectedStage_ / 2) * 0.1);
                const double baseDrain = effect.type == 0x1e ? -100.0 : -200.0;
                player_.specialGauge += static_cast<int>(stageScale * baseDrain);
                if (player_.specialGauge < 0) {
                    player_.specialGauge = 0;
                }
            }
            else if (player_.specialGauge < 0) {
                playPlayerSound(feverSoundHandles_[2], 0x19);
                player_.specialGauge = 0;
            }
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x2d: {
            // State 9 creates this graphless owner driver for 60 frames.
            // FUN_140073e60 emits a large owner-linked pulse every 20 frames
            // and one spiralling owner-linked particle on every update.
            if (age == 1) {
                playPlayerSound(bossSe3SoundHandle_, 0x19);
            }
            if (age % 20 == 0) {
                const int handle = effectMediumFrames_.size() > 4
                                       ? effectMediumFrames_[4]
                                       : -1;
                spawnStageEffect(0x31, handle, 200, 0x23,
                                 0.0f, 0.0f, 0, 0.0, 5.0, 5.0, 40,
                                 0xff, 0xff, 0xff, 0xff,
                                 effect.ownerEntityId);
            }
            const std::uint32_t random = stageScriptRandFromFrame(frame_);
            const float radius = static_cast<float>(random % 301u + 400u);
            const double scale = scriptRandomHundredth(frame_, 0.4, 0.7);
            const int particleHandle = effectMediumFrames_.size() > 3
                                           ? effectMediumFrames_[3]
                                           : -1;
            spawnStageEffect(0x33, particleHandle, 0x48, 0x48,
                             radius, 0.0f,
                             static_cast<std::uint16_t>(random % 0x10001u),
                             0.0, scale, scale, 60,
                             0xff, 0xff, 0xff, 0x80,
                             effect.ownerEntityId);
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x2a:
        case 0x2b: {
            if (effect.type == 0x2b && age == 0 && player_.score != 0) {
                const std::uint32_t frameSeed =
                    static_cast<std::uint32_t>(frame_);
                spawnRewardItem(
                    3, effect.x, effect.y, scriptRandomAngle(frameSeed),
                    static_cast<float>(scriptRandomHundredth(
                        frameSeed + 0x22bu, 0.0, 8.0)),
                    30);
                const std::uint32_t random = stageScriptRandFromFrame(frame_);
                const std::uint16_t feedbackAngle = normalizeAngle16(
                    static_cast<int>(random % 0x8001u) + 0x8000);
                spawnStageEffect(0x19, -1, 0, 0x42,
                                 effect.x, effect.y, feedbackAngle,
                                 1.0, 3.0, 0.8, 50,
                                 0xff, 0xff, 0xff, 0xc0);
            }
            double drawScaleX = effect.scaleX;
            double drawScaleY = effect.scaleY;
            if (age < 0) {
                drawScaleX = 0.0;
                drawScaleY = 0.0;
            }
            else if (age < 8) {
                const double entrance = std::sin(static_cast<double>(age) * kPi / 16.0);
                drawScaleX *= entrance;
                drawScaleY *= entrance;
            }

            int drawAlpha = effect.alpha;
            if (effect.lifetime - 8 <= age) {
                drawAlpha -= static_cast<int>(
                    static_cast<double>((age - effect.lifetime) + 8) *
                    static_cast<double>(effect.alpha) * 0.125);
            }

            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) + age * 0x640);
            effect.drawScaleX = drawScaleX;
            effect.drawScaleY = drawScaleY;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x2c: {
            const std::uint32_t random = stageScriptRandFromFrame(
                static_cast<int>(effect.randomSeed));
            const int lifetime = static_cast<int>(random % 21u) + 30;
            const int pulseStart = static_cast<int>(random % 26u) + 5;
            const double speedFalloff = std::sin(
                static_cast<double>(age) * kPi / (2.0 * static_cast<double>(lifetime)));
            const double speed = effect.scale0 * (1.0 - speedFalloff);
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * speed);
            effect.y += static_cast<float>(std::sin(radians) * speed);

            const double pulse = std::sin(
                static_cast<double>(age - pulseStart) * kPi /
                (2.0 * static_cast<double>(pulseStart)));
            const double drawScaleX = pulse * effect.scaleX;
            effect.scaleX += 0.005;

            int drawAlpha = effect.alpha;
            const int fadeStart = lifetime - 12;
            if (age >= fadeStart && age < lifetime) {
                const double fade = std::sin(
                    static_cast<double>(age - (lifetime - 24)) * kPi / 24.0);
                drawAlpha = static_cast<int>(fade * static_cast<double>(effect.alpha));
            }
            else if (age >= lifetime) {
                drawAlpha = 0;
            }

            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) +
                (static_cast<int>(random % 571u) + 30) * age);
            effect.drawScaleX = drawScaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x31: {
            // FUN_1400757a0 resolves the owner, fades in for eight frames, and
            // shrinks the five-times Effect_m[4] pulse to zero over 40 frames.
            const StageEnemy* owner = findEnemyById(effect.ownerEntityId);
            if (owner == nullptr) {
                effect.active = false;
                break;
            }
            const int lifetime = std::max(1, effect.lifetime);
            double drawScale = 0.0;
            if (age < lifetime) {
                drawScale = effect.scaleX * std::sin(
                    static_cast<double>(age + lifetime) * kPi /
                    static_cast<double>(lifetime * 2));
            }
            int drawAlpha = effect.alpha;
            if (age < 8) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(age) * kPi / 16.0) *
                    static_cast<double>(effect.alpha));
            }
            effect.drawX = owner->x + effect.x;
            effect.drawY = owner->y + effect.y;
            effect.drawAngle16 = 0;
            effect.drawScaleX = drawScale;
            effect.drawScaleY = drawScale;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x33: {
            // FUN_140075a00 keeps the node on a deterministic spiral whose
            // 400..700 radius contracts to its owner over the full 60 frames.
            const StageEnemy* owner = findEnemyById(effect.ownerEntityId);
            if (owner == nullptr) {
                effect.active = false;
                break;
            }
            const int lifetime = std::max(1, effect.lifetime);
            const double envelope = std::sin(
                static_cast<double>(age) * kPi /
                static_cast<double>(lifetime * 2));
            const double radius = static_cast<double>(effect.x) *
                                  (1.0 - envelope);
            const double positionAngle = fixedAngleToRadiansDouble(effect.angle16);
            effect.drawX = owner->x + static_cast<float>(
                std::cos(positionAngle) * radius);
            effect.drawY = owner->y + static_cast<float>(
                std::sin(positionAngle) * radius);
            effect.drawAngle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) - age * 999);
            effect.drawScaleX = effect.scaleX + 1.0 - envelope;
            effect.drawScaleY = effect.drawScaleX;

            int drawAlpha = effect.alpha;
            if (age < 16) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(age) * kPi / 32.0) *
                    static_cast<double>(effect.alpha));
            }
            else if (age >= lifetime - 4) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(lifetime - age) * kPi / 8.0) *
                    static_cast<double>(effect.alpha));
            }
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;

            const int spin = 600 + static_cast<int>(
                stageScriptRandFromFrame(
                    static_cast<int>(effect.randomSeed + 111u)) % 301u);
            effect.angle16 = normalizeAngle16(
                static_cast<int>(effect.angle16) - spin);
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x3b: {
            // Stage 4 FUN_140076ec0: the large sheet rises from y=750 while
            // cumulatively growing, with fixed creation-frame rotation and
            // 32-frame entrance / 16-frame exit alpha envelopes.
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.scaleX +=
                (static_cast<double>(age) * 0.00002 + 0.0005) *
                static_cast<double>(age);
            effect.scaleY = effect.scaleX;

            int drawAlpha = effect.alpha;
            if (age < 0) {
                drawAlpha = 0;
            }
            else if (age < 0x20) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(age) * kPi / 64.0) *
                    static_cast<double>(effect.alpha));
            }
            else if (age >= effect.lifetime - 0x10) {
                if (age < effect.lifetime) {
                    drawAlpha = static_cast<int>(
                        std::sin(static_cast<double>(
                                     age - ((effect.lifetime - 0x10) * 2 -
                                            effect.lifetime)) *
                                 kPi / 32.0) *
                        static_cast<double>(effect.alpha));
                }
                else {
                    drawAlpha = 0;
                }
            }

            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = scriptRandomAngle(effect.randomSeed);
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime || frame_ == kStageEndFrames[4] + 1) {
                effect.active = false;
            }
            break;
        }
        case 0x3c: {
            // Stage 4 FUN_140077830: an accelerating center trajectory carries
            // a growing particle whose draw point orbits that trajectory.
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);
            effect.scale0 += 0.04;
            effect.scaleX +=
                (static_cast<double>(age) * 0.000001 + 0.00012) *
                static_cast<double>(age);
            effect.scaleY = effect.scaleX;

            const auto orbitAngle = normalizeAngle16(
                static_cast<int>((static_cast<std::uint32_t>(
                                      (player_.animationClock + age) / 2) &
                                  0xffffu) *
                                 0x22bu));
            const double orbitRadians = fixedAngleToRadiansDouble(orbitAngle);
            const double orbitRadius = effect.scaleX * 60.0;

            int drawAlpha = effect.alpha;
            if (age < 0) {
                drawAlpha = 0;
            }
            else if (age < 0x20) {
                drawAlpha = static_cast<int>(
                    std::sin(static_cast<double>(age) * kPi / 64.0) *
                    static_cast<double>(effect.alpha));
            }
            else if (age >= effect.lifetime - 0x10) {
                if (age < effect.lifetime) {
                    drawAlpha = static_cast<int>(
                        std::sin(static_cast<double>(
                                     age - ((effect.lifetime - 0x10) * 2 -
                                            effect.lifetime)) *
                                 kPi / 32.0) *
                        static_cast<double>(effect.alpha));
                }
                else {
                    drawAlpha = 0;
                }
            }

            effect.drawX = effect.x + static_cast<float>(
                std::cos(orbitRadians) * orbitRadius);
            effect.drawY = effect.y + static_cast<float>(
                std::sin(orbitRadians) * orbitRadius);
            effect.drawAngle16 = 0;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = drawAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == effect.lifetime || frame_ == kStageEndFrames[4] + 1) {
                effect.active = false;
            }
            break;
        }
        case 0x3d:
        case 0x3e: {
            // FUN_140076ec0: the two Stage 5 background sheets share their
            // acceleration, cubic scale growth, deterministic rotation, and
            // the stage-opening alpha envelope. Type 0x3d advances through
            // five normal-blend layers; 0x3e remains additive on layer 10.
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);

            const int lifetime = std::max(1, effect.lifetime);
            const int riseStart = 0x18;
            const int riseEnd = lifetime - 0x10;
            int brightness = 0;
            if (age >= riseStart && age < riseEnd) {
                brightness = static_cast<int>(
                    std::sin(static_cast<double>(age - riseStart) * kPi /
                             (2.0 * static_cast<double>(riseEnd - riseStart))) *
                    255.0);
            }
            else if (age >= riseEnd && age < lifetime) {
                brightness = static_cast<int>(
                    std::sin(static_cast<double>(age - (riseEnd * 2 - lifetime)) *
                             kPi /
                             (2.0 * static_cast<double>(lifetime - riseEnd))) *
                    255.0);
            }
            else if (age >= lifetime) {
                brightness = 0;
            }

            int stageAlpha = 0;
            if (frame_ > 180 && frame_ < 600) {
                stageAlpha = static_cast<int>(
                    std::sin(static_cast<double>(frame_ - 180) * kPi / 840.0) *
                    static_cast<double>(effect.alpha));
            }
            else if (frame_ >= 600) {
                stageAlpha = effect.alpha;
            }

            effect.scale0 += 0.08;
            effect.scaleX +=
                (static_cast<double>(age) * 0.00002 + 0.0005) *
                static_cast<double>(age);
            effect.colorR = brightness;
            effect.colorG = brightness;
            effect.colorB = brightness;
            effect.drawLayer = effect.type == 0x3d ? 5 + age / 0x18 : 10;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = scriptRandomAngle(effect.randomSeed);
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = stageAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x42: {
            // FUN_140076ec0: Stage 8's late-background motes move upward,
            // expand quadratically, step through five layers, and share the
            // stage-wide 6900..7400 alpha entrance.
            const double radians = fixedAngleToRadiansDouble(effect.angle16);
            effect.x += static_cast<float>(std::cos(radians) * effect.scale0);
            effect.y += static_cast<float>(std::sin(radians) * effect.scale0);

            const int lifetime = std::max(1, effect.lifetime);
            const int fadeStart = 0x10;
            const int fadeEnd = lifetime - 0x10;
            int brightness = 0;
            if (age >= fadeStart && age < fadeEnd) {
                brightness = static_cast<int>(
                    std::sin(static_cast<double>(age - fadeStart) * kPi /
                             (2.0 * static_cast<double>(fadeEnd - fadeStart))) *
                    255.0);
            }
            else if (age >= fadeEnd && age < lifetime) {
                brightness = static_cast<int>(
                    std::sin(static_cast<double>(age - (fadeEnd * 2 - lifetime)) *
                             kPi /
                             (2.0 * static_cast<double>(lifetime - fadeEnd))) *
                    255.0);
            }
            else if (age >= lifetime) {
                brightness = 0;
            }

            int stageAlpha = 0;
            if (frame_ >= 0x1af4 && frame_ < 0x1ce8) {
                stageAlpha = static_cast<int>(
                    std::sin(static_cast<double>(frame_ - 0x1af4) * kPi / 1000.0) *
                    static_cast<double>(effect.alpha));
            }
            else if (frame_ >= 0x1ce8) {
                stageAlpha = effect.alpha;
            }

            effect.scaleX +=
                (static_cast<double>(age) * 0.00003 + 0.0001) *
                static_cast<double>(age);
            effect.colorR = brightness;
            effect.colorG = brightness;
            effect.colorB = brightness;
            effect.drawLayer = 5 + age / 0x18;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = 0;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleX;
            effect.drawAlpha = stageAlpha;
            effect.drawQueuedThisFrame = true;
            if (age == lifetime) {
                effect.active = false;
            }
            break;
        }
        case 0x37:
        case 0x3a:
            // FUN_140076b00 advances these vertical nodes by DAT_1407c77a4.
            effect.y += static_cast<float>(
                std::clamp(timeWindowDispatchCount_, 1, 4));
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.type == 0x3a
                                    ? (std::sin(static_cast<double>(age) *
                                                2.0 * kPi / 3.0) *
                                           0.1 +
                                       1.0) *
                                          effect.scaleY
                                    : effect.scaleY;
            effect.drawAlpha = effect.alpha;
            effect.drawQueuedThisFrame = true;
            if (effect.x < projectileHorizontalOrigin(player_.x) -
                               static_cast<float>(effect.graphExtent) ||
                effect.x > projectileHorizontalOrigin(player_.x) + 600.0f +
                               static_cast<float>(effect.graphExtent) ||
                effect.y < kPlayTop - static_cast<float>(effect.graphExtent) ||
                effect.y > kPlayBottom + static_cast<float>(effect.graphExtent)) {
                effect.active = false;
            }
            break;
        default:
            effect.active = false;
            break;
        }
        ++effect.age;
    }
}

void StageRuntime::updateStage03Enemy(StageEnemy& enemy) {
    // Every exact helper queues its gauge before the dispatcher performs the
    // collision pass. Preserve that pre-hit HP for the deferred draw pass.
    enemy.drawHp = enemy.hp;
    switch (enemy.spawnType) {
    case 0x25:
        updateStage03Type25(enemy);
        break;
    case 0x26:
        updateStage03Type26(enemy);
        break;
    case 0x27:
    case 0x29:
        updateStage03Type27Or29(enemy);
        break;
    case 0x28:
    case 0x2a:
        updateStage03Satellite(enemy);
        break;
    case 0x2b:
        updateStage03Type2B(enemy);
        break;
    case 0x2c:
        updateStage03Type2C(enemy);
        break;
    case 0x2d:
        updateStage03Type2D(enemy);
        break;
    case 0x2e:
        updateStage03Type2E(enemy);
        break;
    case 0x2f:
        updateStage03Type2F(enemy);
        break;
    default:
        break;
    }
}

void StageRuntime::updateStage03Type25(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        const float wobble = 100.0f * std::sin((static_cast<float>(frame_) - enemy.entityId * 55.0f) *
                                              kTau / 320.0f);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = timer;
        // FUN_1400894a0 clamps the marker's y through FUN_1401346a0, but its
        // x draw coordinate comes directly from the hidden trajectory plus the
        // global-frame wobble.
        enemy.markerDrawX = enemy.originX + wobble;
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (timer < 20) {
            return;
        }

        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 2.0;
        enemy.sourceAngle16 = 0x4000;
        enemy.x = clampFloat(enemy.x, horizontalOrigin - 20.0f, horizontalOrigin + 620.0f);
        enemy.y = clampFloat(enemy.y, -20.0f, 740.0f);
        enemy.originX = enemy.x;
        enemy.originY = enemy.y;
        enemy.targetable = true;
    }

    const int timer = enemy.helperTimer;
    if (timer < 180) {
        const auto target = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - enemy.originY),
            static_cast<double>(player_.x - enemy.originX)));
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x40);
        const double angle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.originX += static_cast<float>(std::cos(angle) * enemy.sourceSpeed);
        enemy.originY += static_cast<float>(std::sin(angle) * enemy.sourceSpeed);
        enemy.x = enemy.originX +
                  100.0f * std::sin((static_cast<float>(frame_) - enemy.entityId * 55.0f) *
                                    kTau / 320.0f);
        enemy.y = enemy.originY;
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0xa0);
        enemy.sourceSpeed += 0.1;
        const double angle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(angle) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(angle) * enemy.sourceSpeed);
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.drawBodyThisFrame = true;

    const bool inside = enemy.x >= horizontalOrigin && enemy.x <= horizontalOrigin + 600.0f &&
                        enemy.y >= 0.0f && enemy.y <= 720.0f;
    const int start = kStage03Type25Start[static_cast<std::size_t>(difficulty)];
    const int cycle = kStage03Type25Cycle[static_cast<std::size_t>(difficulty)];
    if (inside && timer >= start && timer < 180) {
        const int phase = (timer - start) % cycle;
        if (phase == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - enemy.y),
                static_cast<double>(player_.x - enemy.x)));
        }
        if (phase < 30 && phase % 5 == 0) {
            const double speed = kStage03Type25Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(7, 0, enemy.x + 16.0f, enemy.y + 40.0f,
                                enemy.secondaryAngle16, 10.0f, speed, 1, 0);
            spawnProjectileNode(7, 0, enemy.x - 16.0f, enemy.y + 40.0f,
                                enemy.secondaryAngle16, 10.0f, speed, 1, 0);
            if (difficulty >= 3) {
                spawnProjectileNode(7, 0, enemy.x + 16.0f, enemy.y + 40.0f,
                                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 400),
                                    10.0f, speed - 0.2, 1, 0);
                spawnProjectileNode(7, 0, enemy.x - 16.0f, enemy.y + 40.0f,
                                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 400),
                                    10.0f, speed - 0.2, 1, 0);
            }
        }
    }

    if (timer % 4 == 0) {
        const int trail = enemySmallFrames_.size() > 24 ? enemySmallFrames_[24] : -1;
        spawnStageEffect(0x05, trail, 100, 0x22, enemy.x, enemy.y, 0,
                         0.0, 1.0, 1.0, 0x18,
                         0xff, 0xff, 0xff, 0x40);
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 300);
        enemy.active = false;
        return;
    }
    if (enemy.x < horizontalOrigin - 180.0f || enemy.x > horizontalOrigin + 780.0f ||
        enemy.y < -180.0f || enemy.y > 900.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type26(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = timer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (timer < 20) {
            return;
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 6.0;
        enemy.targetable = true;
    }

    const int timer = enemy.helperTimer;
    if (timer < 210) {
        if (timer < 121 && enemy.sourceSpeed > 1.5) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16,
            radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y))), 0x40);
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0xa0);
        enemy.sourceSpeed += 0.1;
    }
    const double angle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.x += static_cast<float>(std::cos(angle) * enemy.sourceSpeed);
    enemy.y += static_cast<float>(std::sin(angle) * enemy.sourceSpeed);
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.drawBodyThisFrame = true;

    if (timer >= 24 && timer < 210) {
        const int cycle = kStage03Type26Cycle[static_cast<std::size_t>(difficulty)];
        const int phase = (timer - 24) % cycle;
        const float rightX = enemy.x + 50.0f;
        const float leftX = enemy.x - 50.0f;
        const float fireY = enemy.y + 80.0f;
        if (phase == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(rightX, fireY)));
            enemy.targetAngle16 = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(leftX, fireY)));
        }
        if (phase < 24 && phase % 4 == 0) {
            const double speed = kStage03Type26ShotSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(7, 0, rightX, fireY, enemy.secondaryAngle16, 10.0f, speed, 1, 0);
            spawnProjectileNode(7, 0, leftX, fireY, enemy.targetAngle16, 10.0f, speed, 1, 0);
            if (difficulty >= 3) {
                for (int offset : {-1000, 1000}) {
                    spawnProjectileNode(7, 0, rightX, fireY,
                                        normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + offset),
                                        10.0f, speed, 1, 0);
                    spawnProjectileNode(7, 0, leftX, fireY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) + offset),
                                        10.0f, speed, 1, 0);
                }
            }
        }

        const int doubled = (timer - 24) % (cycle * 2);
        const int fanCount = kStage03Type26FanCount[static_cast<std::size_t>(difficulty)];
        const double fanSpeed = kStage03Type26FanSpeed[static_cast<std::size_t>(difficulty)];
        auto fan = [&](float x, std::uint16_t center) {
            spawnProjectileSpread(4, 0, x, fireY, center, 0.0f, fanSpeed, 1,
                                  fanCount, 20000, 0);
            if (difficulty >= 3 && fanCount > 1) {
                spawnProjectileSpread(4, 0, x, fireY, center, 0.0f, fanSpeed - 1.5, 1,
                                      fanCount - 1,
                                      (20000 / (fanCount - 1)) * (fanCount - 2), 0);
            }
        };
        if (doubled == 32) {
            fan(rightX, enemy.secondaryAngle16);
        }
        if (doubled == cycle + 32) {
            fan(leftX, enemy.targetAngle16);
        }
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 500);
        enemy.active = false;
        return;
    }
    if (enemy.x < horizontalOrigin - 128.0f || enemy.x > horizontalOrigin + 728.0f ||
        enemy.y < -128.0f || enemy.y > 848.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type27Or29(StageEnemy& enemy) {
    const bool type27 = enemy.spawnType == 0x27;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        if (timer == 0) {
            enemy.x = enemy.originX < 360.0f ? -100.0f : 820.0f;
            enemy.y = -100.0f;
        }
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = timer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (timer < 20) {
            return;
        }

        if (type27) {
            spawnStage03Satellite(enemy, 0x28, 0, 50.0f, -90.0f, -1000);
            spawnStage03Satellite(enemy, 0x28, 1, -50.0f, -90.0f, 1000);
            if (difficulty > 0) {
                spawnStage03Satellite(enemy, 0x28, 2, 100.0f, -50.0f, -3000);
                spawnStage03Satellite(enemy, 0x28, 3, -100.0f, -50.0f, 3000);
            }
        }
        else {
            spawnStage03Satellite(enemy, 0x2a, 0, 30.0f, 80.0f, 200);
            spawnStage03Satellite(enemy, 0x2a, 1, -30.0f, 80.0f, -200);
            if (difficulty > 0) {
                spawnStage03Satellite(enemy, 0x2a, 2, 70.0f, 40.0f, 0);
                spawnStage03Satellite(enemy, 0x2a, 3, -70.0f, 40.0f, 0);
            }
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = type27 ? 11.5 : 12.0;
        enemy.sourceAngle16 = radiansToFixedAngleTrunc(
            std::atan2(static_cast<double>(enemy.originY - enemy.y),
                       static_cast<double>(enemy.originX - enemy.x)));
        enemy.targetable = true;
    }

    const int timer = enemy.helperTimer;
    if (timer >= 60 && timer < 240 && (timer - 60) % 50 == 0) {
        const auto xRand = stageScriptRandFromFrame(timer * enemy.entityId * 0x14d);
        const auto yRand = stageScriptRandFromFrame(timer * enemy.entityId * 0xd05);
        enemy.originX = static_cast<float>(xRand % 481u + 120u);
        enemy.originY = static_cast<float>(timer + static_cast<int>(yRand % 101u));
    }
    if (timer < 61) {
        const double floor = type27 ? 2.5 : 3.0;
        if (enemy.sourceSpeed > floor) {
            enemy.sourceSpeed -= 0.15;
        }
    }
    if (timer >= 240) {
        enemy.originY = -500.0f;
        enemy.sourceSpeed += 0.1;
    }
    const auto target = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(enemy.originY - enemy.y),
                   static_cast<double>(enemy.originX - enemy.x)));
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x200);
    const double angle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.x += static_cast<float>(std::cos(angle) * enemy.sourceSpeed);
    enemy.y += static_cast<float>(std::sin(angle) * enemy.sourceSpeed);
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.drawBodyThisFrame = true;

    if (type27 && timer >= 60 && timer < 240) {
        const int cycle = kStage03Type27Cycle[static_cast<std::size_t>(difficulty)];
        const int phase = timer - 60;
        if (phase % cycle == 0 ||
            (difficulty >= 3 && timer >= 84 && (timer - 84) % cycle == 0)) {
            const int count = kStage03Type27FanCount[static_cast<std::size_t>(difficulty)];
            const double speed = kStage03Type27FanSpeed[static_cast<std::size_t>(difficulty)];
            const auto aim = radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y)));
            if (count > 1) {
                spawnProjectileSpread(2, 9, enemy.x, enemy.y, aim, 10.0f, speed + 3.0, 1,
                                      count - 1,
                                      (20000 / (count - 1)) * (count - 2), 0);
            }
            spawnProjectileSpread(3, 0, enemy.x, enemy.y, aim, 10.0f, speed, 1,
                                  count, 20000, 0);
        }
    }

    if (timer % 4 == 0) {
        const int frame = type27 ? 51 : 53;
        const int trail = frame < static_cast<int>(enemyMediumFrames_.size())
                              ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                              : -1;
        spawnStageEffect(0x05, trail, 200, 0x21, enemy.x, enemy.y, 0,
                         0.0, 1.0, 1.0, 0x18,
                         0xff, 0xff, 0xff, 0x40);
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 500);
        enemy.active = false;
        return;
    }
    if (timer >= 240 &&
        (enemy.x < horizontalOrigin - 128.0f || enemy.x > horizontalOrigin + 728.0f ||
         enemy.y < -128.0f || enemy.y > 848.0f)) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Satellite(StageEnemy& enemy) {
    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr) {
        enemy.active = false;
        return;
    }
    const bool parentActive = parent->active;

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    if (enemy.helperTimer == 0) {
        enemy.x = parent->x;
        enemy.y = parent->y;
    }
    else {
        enemy.x += (targetX - enemy.x) * 0.125f;
        enemy.y += (targetY - enemy.y) * 0.125f;
    }
    enemy.drawBodyThisFrame = true;
    if (parent->hp < 1) {
        spawnEnemyDeathEffects(enemy, 0);
        enemy.active = false;
        return;
    }
    if (!parentActive) {
        enemy.active = false;
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    if (parent->helperTimer >= 240) {
        return;
    }
    const bool type28 = enemy.spawnType == 0x28;
    const int start = type28 ? 100 : 75;
    if (enemy.helperTimer < start) {
        return;
    }
    const int cycle = type28
                          ? kStage03Type27Cycle[static_cast<std::size_t>(difficulty)]
                          : kStage03Type2ACycle[static_cast<std::size_t>(difficulty)];
    const int phase = (enemy.helperTimer - start) % cycle;
    // FUN_14008bd60 accepts phases through 0x27/0x1d, respectively. Using
    // <= 40/30 adds one projectile at the next five-frame boundary.
    const int window = type28 ? 40 : 30;
    if (phase == 0) {
        enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
            static_cast<double>(aimAtPlayer(parent->x, parent->y)));
    }
    if (phase < window && phase % 5 == 0) {
        const double base = type28
                                ? kStage03Type28Speed[static_cast<std::size_t>(difficulty)]
                                : kStage03Type2ASpeed[static_cast<std::size_t>(difficulty)];
        const double speed = base + static_cast<double>(phase) * 0.08;
        const auto angle = normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) +
                                            static_cast<int>(static_cast<std::int16_t>(enemy.sourceAngle16)));
        spawnProjectileNode(type28 ? 9 : 7, 0, enemy.x, enemy.y, angle,
                            10.0f, speed, 1, 0);
        if (difficulty >= 3) {
            spawnProjectileNode(type28 ? 9 : 7, 0, enemy.x, enemy.y, angle,
                                10.0f, speed + (type28 ? 2.0 : 2.5), 1, 0);
        }
    }
}

void StageRuntime::updateStage03Type2B(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;

    if (enemy.helperState == 0) {
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (enemy.helperTimer < 20) {
            return;
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 7.0;
        enemy.targetable = true;
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        if (timer < 300) {
            if (timer < 121 && enemy.sourceSpeed > 0.8) {
                enemy.sourceSpeed -= 0.1;
            }
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16,
                radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y))), 0x40);
        }
        else {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0xa0);
            enemy.sourceSpeed += 0.1;
        }
        const double angle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(angle) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(angle) * enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);

        if (timer >= 40 && timer < 300) {
            const float waveA = 2.0f * std::sin(static_cast<float>(timer) * kTau / 38.0f);
            const float waveC = 2.0f * std::sin(static_cast<float>(timer - 18) * kTau / 38.0f);
            const int interval = kStage03Type2BInterval[static_cast<std::size_t>(difficulty)];
            if ((timer - 40) % interval == 0) {
                const int phase = (timer - 40) % 244;
                const int sweep = phase < 122 ? phase * 196 + 0x1120
                                              : phase * -196 - 0x3410;
                const int count = kStage03Type2BCountA[static_cast<std::size_t>(difficulty)];
                const double speed = kStage03Type2BSpeedA[static_cast<std::size_t>(difficulty)];
                const float sourceY = enemy.y + 140.0f + waveC;
                spawnProjectileSpread(9, 0, enemy.x, sourceY, normalizeAngle16(sweep),
                                      10.0f, speed, 1, count, (count - 1) * 0xc80, 0);
                if (difficulty >= 3) {
                    spawnProjectileSpread(9, 0, enemy.x, sourceY, normalizeAngle16(sweep),
                                          10.0f, speed + 1.0, 1, count,
                                          (count - 1) * 0xc80, 0);
                }
            }

            const int halfPeriod = kStage03Type2BHalfPeriod[static_cast<std::size_t>(difficulty)];
            const int count = kStage03Type2BCountB[static_cast<std::size_t>(difficulty)];
            const double speed = kStage03Type2BSpeedB[static_cast<std::size_t>(difficulty)] +
                                 static_cast<double>(timer - 40) * 0.006;
            const float sourceY = enemy.y - 35.0f + waveA;
            const auto aim = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(enemy.x, sourceY)));
            if (timer >= 50 && (timer - 50) % (halfPeriod * 2) == 0) {
                spawnProjectileSpread(4, 0, enemy.x, sourceY, aim, 0.0f, speed, 1,
                                      count, 0x8000, 0);
            }
            if (timer >= halfPeriod + 50 &&
                (timer - (halfPeriod + 50)) % (halfPeriod * 2) == 0 && count > 1) {
                spawnProjectileSpread(4, 0, enemy.x, sourceY, aim, 0.0f, speed, 1,
                                      count - 1,
                                      (0x8000 / (count - 1)) * (count - 2), 0);
            }
        }

        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 1000);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            const int group = std::clamp(config_.setupGroup, 0, 2);
            const int frameIndex = 1 + group * 10;
            const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                           ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                           : -1;
            spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                             0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 0x78,
                             0xff, 0xff, 0xff, 0xff);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }

    if (enemy.helperState == 2 && enemy.helperTimer <= 60) {
        spawnStage02DeathExplosionChain(enemy);
        enemy.y += static_cast<float>(enemy.helperTimer) * 0.1f;
        if (enemy.helperTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            enemy.active = false;
        }
    }

    if (enemy.x < horizontalOrigin - 200.0f || enemy.x > horizontalOrigin + 800.0f ||
        enemy.y < -200.0f || enemy.y > 920.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type2C(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.y += 1.0f;
    if (enemy.helperState == 0 && enemy.y >= -40.0f) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
    }
    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer == 40) {
        enemy.targetable = true;
    }
    const auto target = radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y)));
    const int delta = std::abs(static_cast<int>(static_cast<std::int16_t>(target - enemy.sourceAngle16)));
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, delta / 10 + 0x30);
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.drawBodyThisFrame = true;

    if (timer >= 40 && enemy.y < 350.0f) {
        const int interval = kStage03Type2CInterval[static_cast<std::size_t>(difficulty)];
        if ((timer - 40) % interval == 0) {
            const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
            const float sourceX = enemy.x + static_cast<float>(std::cos(radians) * 77.0);
            const float sourceY = enemy.y + static_cast<float>(std::sin(radians) * 77.0);
            const double speed = kStage03Type2CSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(6, 0, sourceX, sourceY, enemy.sourceAngle16, 10.0f, speed, 1, 0);
            spawnProjectileNode(6, 0, sourceX, sourceY, enemy.sourceAngle16, 10.0f, speed + 0.3, 1, 0);
            if (difficulty >= 3) {
                for (double extra : {0.6, 0.9, 1.2}) {
                    spawnProjectileNode(6, 0, sourceX, sourceY, enemy.sourceAngle16,
                                        10.0f, speed + extra, 1, 0);
                }
            }
        }
    }
    if (enemy.hp < 1) {
        const int handle = effectSmallFrames_.size() > 6 ? effectSmallFrames_[6] : -1;
        const auto seed = static_cast<std::uint32_t>(enemy.entityId) +
                          static_cast<std::uint32_t>(frame_);
        const double scale = scriptRandomHundredth(seed, 1.0, 1.2);
        spawnStageEffect(0x37, handle, 100, 0x15, enemy.x, enemy.y,
                         scriptRandomAngle(seed), 1.0, scale, scale,
                         0x78, 0xff, 0xff, 0xff, 0xc0);
        spawnEnemyDeathRewardBurst(enemy, 1000);
        enemy.active = false;
    }
    if (enemy.y >= 800.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type2D(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.y += 1.0f;
    if (enemy.helperState == 0 && enemy.y >= -100.0f) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
    }
    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer == 60) {
        enemy.targetable = true;
    }
    const int interval = kStage03Type2DInterval[static_cast<std::size_t>(difficulty)];
    const int burst = kStage03Type2DBurst[static_cast<std::size_t>(difficulty)];
    const int phase = timer >= 60 ? (timer - 60) % interval : interval;
    const auto target = radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y)));
    if (phase > burst) {
        const int delta = std::abs(static_cast<int>(static_cast<std::int16_t>(target - enemy.sourceAngle16)));
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, delta / 10 + 0x30);
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.drawBodyThisFrame = true;

    if (timer >= 60 && enemy.y < 350.0f && phase < burst && phase % 4 == 0) {
        const int count = kStage03Type2DFanCount[static_cast<std::size_t>(difficulty)];
        const double speed = kStage03Type2DSpeed[static_cast<std::size_t>(difficulty)];
        for (int sign : {-1, 1}) {
            const auto mountAngle = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + sign * 0xce4);
            const double radians = fixedAngleToRadiansDouble(mountAngle);
            const float sourceX = enemy.x + static_cast<float>(std::cos(radians) * 150.0);
            const float sourceY = enemy.y + static_cast<float>(std::sin(radians) * 150.0);
            spawnProjectileSpread(7, 0, sourceX, sourceY, enemy.sourceAngle16, 10.0f,
                                  speed, 1, count, 0x578, 0);
            if (difficulty >= 3) {
                spawnProjectileNode(7, 0, sourceX, sourceY, enemy.sourceAngle16,
                                    10.0f, speed + 2.0, 1, 0);
            }
        }
    }
    if (enemy.hp < 1) {
        const int handle = effectMediumFrames_.size() > 18 ? effectMediumFrames_[18] : -1;
        const auto seed = static_cast<std::uint32_t>(enemy.entityId) +
                          static_cast<std::uint32_t>(frame_);
        const double scale = scriptRandomHundredth(seed, 1.0, 1.1);
        spawnStageEffect(0x37, handle, 200, 0x15, enemy.x, enemy.y,
                         scriptRandomAngle(seed), 1.0, scale, scale,
                         0x78, 0xff, 0xff, 0xff, 0xc0);
        spawnEnemyDeathRewardBurst(enemy, 1000);
        enemy.active = false;
    }
    if (enemy.y >= 900.0f) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type2E(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        if (timer == 0) {
            spawnStage03Type2FChild(enemy);
        }
        const double phase = static_cast<double>(timer) * kPi / 180.0;
        if (timer < 90) {
            enemy.x = enemy.originX -
                      static_cast<float>(700 - static_cast<int>(std::sin(phase) * 700.0));
            enemy.y = enemy.originY +
                      static_cast<float>(1000 - static_cast<int>(std::sin(phase) * 1000.0));
        }
        else {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
        }
        enemy.originY += 1.0f;
        if (timer < 120) {
            return;
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 0.7;
        enemy.targetable = true;
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        if (timer < 1300) {
            if (timer % 20 == 0) {
                enemy.originX = static_cast<float>(stageScriptRandFromFrame(frame_) % 241u + 240u);
                enemy.originY = static_cast<float>(stageScriptRandFromFrame(frame_ + 0xd05) % 61u + 20u);
            }
            const auto target = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(enemy.originY - enemy.y),
                           static_cast<double>(enemy.originX - enemy.x)));
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x200);
            if (timer >= 520 && timer < 620) {
                enemy.sourceSpeed += 0.01;
            }
        }
        else {
            enemy.sourceAngle16 = 0xc000;
            enemy.sourceSpeed = static_cast<double>(timer - 1300) * 0.1;
        }
        const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);

        const float wave = 3.0f * std::sin(static_cast<float>(frame_) * kTau / 68.0f) - 24.0f;
        const float fireY = enemy.y + 222.0f + wave;
        const float leftX = enemy.x - 180.0f;
        const float rightX = enemy.x + 180.0f;
        const int intervalA = kStage03Type2EIntervalA[static_cast<std::size_t>(difficulty)];
        const int countA = kStage03Type2ECountA[static_cast<std::size_t>(difficulty)];
        const int repeatsA = kStage03Type2ERepeatA[static_cast<std::size_t>(difficulty)];
        const double speedA = kStage03Type2ESpeedA[static_cast<std::size_t>(difficulty)];

        if (timer == 90) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(leftX, fireY)));
        }
        if (timer >= 90 && timer < 250 && (timer - 90) % intervalA == 0) {
            const int local = timer - 90;
            const int sweep = 13000 - local * 162;
            for (int i = 0; i < repeatsA; ++i) {
                spawnProjectileSpread(4, 0, leftX, fireY,
                                      normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + sweep + i * 400),
                                      0.0f, speedA, 1, countA, (countA - 1) * 0x125c, 0);
            }
        }
        if (timer == 320) {
            enemy.targetAngle16 = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(rightX, fireY)));
        }
        if (timer >= 320 && timer < 480 && (timer - 320) % intervalA == 0) {
            const int local = timer - 320;
            const int sweep = -13000 + local * 162;
            for (int i = 0; i < repeatsA; ++i) {
                spawnProjectileSpread(4, 0, rightX, fireY,
                                      normalizeAngle16(static_cast<int>(enemy.targetAngle16) + sweep - i * 400),
                                      0.0f, speedA, 1, countA, (countA - 1) * 0x125c, 0);
            }
        }

        if (timer >= 550 && timer < 1300) {
            const int intervalB = kStage03Type2EIntervalB[static_cast<std::size_t>(difficulty)];
            const int local = timer - 550;
            const int phaseB = local % intervalB;
            const int volley = local / intervalB;
            if (phaseB == 0) {
                enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                    static_cast<double>(aimAtPlayer(rightX, fireY)));
                enemy.targetAngle16 = radiansToFixedAngleTrunc(
                    static_cast<double>(aimAtPlayer(leftX, fireY)));
            }
            if (phaseB < 20 && phaseB % 4 == 0) {
                const int count = volley + 1;
                const int spread = volley * kStage03Type2ESpreadStepB[static_cast<std::size_t>(difficulty)];
                const double speed = kStage03Type2ESpeedB[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>(phaseB) * 0.1;
                spawnProjectileSpread(9, 0, rightX, fireY, enemy.secondaryAngle16,
                                      10.0f, speed, 1, count, spread, 0);
                spawnProjectileSpread(9, 0, leftX, fireY, enemy.targetAngle16,
                                      10.0f, speed, 1, count, spread, 0);
            }
        }

        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            const int group = std::clamp(config_.setupGroup, 0, 2);
            const int frameIndex = 1 + group * 10;
            const int portraitHandle = frameIndex < static_cast<int>(playerFrameFrames_.size())
                                           ? playerFrameFrames_[static_cast<std::size_t>(frameIndex)]
                                           : -1;
            spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                             0.0f, 0.0f, 0, 0.0, 1.0, 1.0, 0x78,
                             0xff, 0xff, 0xff, 0xff);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }

    if (enemy.helperState == 2 && enemy.helperTimer <= 60) {
        spawnStage02DeathExplosionChain(enemy);
        enemy.y += static_cast<float>(enemy.helperTimer) * 0.1f;
        if (enemy.helperTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            enemy.active = false;
            stage03GateFlag_ = false;
        }
    }

    if (enemy.targetable &&
        (enemy.x < horizontalOrigin - 400.0f || enemy.x > horizontalOrigin + 1000.0f ||
         enemy.y < -400.0f || enemy.y > 1120.0f)) {
        enemy.active = false;
        stage03GateFlag_ = false;
    }
}

void StageRuntime::updateStage03Type2F(StageEnemy& enemy) {
    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr) {
        enemy.active = false;
        return;
    }
    const bool parentActive = parent->active;

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    if (enemy.helperTimer == 0) {
        enemy.x = targetX;
        enemy.y = targetY;
    }
    else {
        enemy.x += (targetX - enemy.x) / 7.0f;
        enemy.y += (targetY - enemy.y) / 7.0f;
    }
    enemy.drawBodyThisFrame = true;
    if (!parentActive) {
        enemy.active = false;
        return;
    }

    if (enemy.helperState == 0 && enemy.helperTimer == 120) {
        enemy.hp = parent->hp;
        enemy.maxHp = parent->maxHp;
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }
    if (enemy.helperState != 1) {
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    constexpr std::array<int, 8> kWindowStart{{10, 58, 114, 178, 250, 330, 418, 514}};
    constexpr std::array<int, 8> kWindowLength{{20, 32, 44, 56, 68, 80, 92, 104}};
    for (std::size_t i = 0; i < kWindowStart.size(); ++i) {
        const int local = timer - kWindowStart[i];
        if (local < 0 || local >= kWindowLength[i] || timer >= 500 || local % 4 != 0) {
            continue;
        }
        const float fireY = enemy.y + 90.0f;
        const auto aim = radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, fireY)));
        if (local == 0) {
            enemy.secondaryAngle16 = aim;
        }
        else {
            enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, aim, 400);
        }
        const int count = kStage03Type2FCount[static_cast<std::size_t>(difficulty)];
        const double speed = kStage03Type2FSpeed[static_cast<std::size_t>(difficulty)] +
                             static_cast<double>(local) * 0.12;
        spawnProjectileSpread(0x0d, 0, enemy.x, fireY, enemy.secondaryAngle16,
                              0.0f, speed, 1, count, 27000, 0);
        if (difficulty >= 3) {
            spawnProjectileNode(0x0d, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 800),
                                0.0f, speed + 1.0, 1, 0);
            spawnProjectileNode(0x0d, 0, enemy.x, fireY,
                                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 800),
                                0.0f, speed + 1.0, 1, 0);
        }
        break;
    }

    const int parentHpAtEntry = parent->hp;
    if (enemy.hp < parentHpAtEntry) {
        parent->hp -= parentHpAtEntry - enemy.hp;
    }
    if (parentHpAtEntry < enemy.hp) {
        enemy.hp = parentHpAtEntry;
    }
    if (enemy.hp < 1) {
        parent->hp = 0;
    }
    if (parent->hp < 1) {
        enemy.targetable = false;
        enemy.helperState = 2;
    }
}

void StageRuntime::updateStage03Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;

    // FUN_14000ed10 computes steering before replacing the shared random
    // destination.
    const auto steeringTarget = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(stage03BossTargetY_ - enemy.y),
        static_cast<double>(stage03BossTargetX_ - enemy.x)));

    // The live-bar break runs before the switch. Its new transition state is
    // consequently executed in this same helper call at timer zero.
    if (stage03BossPhaseMode_ == 1 &&
        (enemy.hp < 1 || stage03BossCountdown_ < 1)) {
        const bool countdownExpired = stage03BossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, stage03BossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        switch (stage03BossBreaksRemaining_) {
        case 4:
            enemy.helperState = 2;
            enemy.radius = 200;
            stage03BossPhaseMode_ = 2;
            break;
        case 3:
            enemy.helperState = 4;
            enemy.radius = 200;
            stage03BossPhaseMode_ = 2;
            break;
        case 2:
            enemy.helperState = 6;
            stage03BossPhaseMode_ = 2;
            break;
        case 1:
            enemy.helperState = 8;
            stage03BossPhaseMode_ = -1;
            break;
        default:
            break;
        }
        stage03BossBreaksRemaining_ = std::max(0, stage03BossBreaksRemaining_ - 1);
    }

    // The common 50-frame refresh follows the phase-break preamble. State 3
    // then performs a second 25-frame refresh with y=120..220. On a state-3
    // break frame the second refresh must not run for the old state.
    if (frame_ % 50 == 0) {
        stage03BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
        stage03BossTargetY_ = static_cast<float>(
            stageRandCoord(frame_ + (selectedStage_ - 1) * 0x14d, 101, 150));
    }
    if (enemy.helperState == 3 && frame_ % 25 == 0) {
        stage03BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
        stage03BossTargetY_ = static_cast<float>(
            stageRandCoord(frame_ + (selectedStage_ - 1) * 0x14d, 101, 120));
    }

    // FUN_14000ed10 queues the body from the state selected after the
    // phase-break preamble, but before any transition performed by that
    // state's own tail. Preserve that queue-time state for draw().
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    const auto steerTowardStageTarget = [&enemy, steeringTarget](int turnStep) {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              steeringTarget, turnStep);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.x += std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        enemy.y += std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
    };
    const auto openPhase = [this, &enemy](int state, int hitPoints,
                                          int radius, int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.radius = radius;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        stage03BossMaxHp_ = hitPoints;
        stage03BossCountdown_ = 1800;
        stage03BossPhaseIndex_ = phaseIndex;
        stage03BossPhaseMode_ = 1;
    };

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0:
        if (timer == 0) {
            spawnStage03BossChild(enemy, 0x30, 0, 150.0f, 120.0f,
                                  10000, 48, 1.0, 50, 0x4000,
                                  "S03 FUN_14000ed10 lower arm right");
            spawnStage03BossChild(enemy, 0x30, 1, -150.0f, 120.0f,
                                  10000, 48, 1.0, 50, 0x4000,
                                  "S03 FUN_14000ed10 lower arm left");
            spawnStage03BossChild(enemy, 0x31, 0, 100.0f, -100.0f,
                                  99999999, 0, 1.0, 50, 0x4000,
                                  "S03 FUN_14000ed10 upper satellite right");
            spawnStage03BossChild(enemy, 0x31, 1, -100.0f, -100.0f,
                                  99999999, 0, 1.0, 50, 0x4000,
                                  "S03 FUN_14000ed10 upper satellite left");
            enemy.liveChildCount = 4;
        }
        enemy.x = 360.0f;
        if (timer < 60) {
            enemy.y = -200.0f + static_cast<float>(static_cast<int>(
                std::sin(static_cast<double>(timer) * kPi / 120.0) * 600.0));
        }
        else if (timer == 60) {
            enemy.y = 400.0f;
        }
        else if (timer < 180) {
            enemy.y = 200.0f + static_cast<float>(static_cast<int>(
                std::sin(static_cast<double>(timer + 60) * kPi / 240.0) * 200.0));
        }
        else if (timer == 180) {
            enemy.y = 200.0f;
            openPhase(1, 70000, 150, 0);
        }
        break;
    case 1:
        steerTowardStageTarget(0x200);
        emitStage03BossProjectiles(enemy);
        break;
    case 2:
        if (timer < 90) {
            enemy.y += static_cast<float>(timer) * 0.04f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 90) {
            enemy.sourceSpeed = 3.0;
            enemy.speed = 3.0f;
        }
        if (timer >= 90) {
            steerTowardStageTarget(0x309);
        }
        if (timer == 200) {
            openPhase(3, 66000, 150, 1);
        }
        break;
    case 3:
        steerTowardStageTarget(0x309);
        emitStage03BossProjectiles(enemy);
        break;
    case 4:
        if (timer < 120) {
            enemy.y += static_cast<float>(timer) * 0.02f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 120) {
            enemy.sourceSpeed = 0.5;
            enemy.speed = 0.5f;
        }
        if (timer >= 130) {
            steerTowardStageTarget(0x200);
        }
        if (timer == 380) {
            openPhase(5, 40000, 80, 2);
        }
        break;
    case 5:
        steerTowardStageTarget(0x200);
        emitStage03BossProjectiles(enemy);
        break;
    case 6:
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += 0.1f;
        if (timer == 180) {
            openPhase(7, 50000, 80, 3);
        }
        break;
    case 7:
        steerTowardStageTarget(0x200);
        if (timer == 10) {
            static constexpr std::array<float, 4> kOffsetX{{250.0f, -250.0f,
                                                            120.0f, -120.0f}};
            static constexpr std::array<float, 4> kOffsetY{{-20.0f, -20.0f,
                                                            -70.0f, -70.0f}};
            for (int i = 0; i < 4; ++i) {
                spawnStage03BossChild(
                    enemy, 0x34, i, kOffsetX[static_cast<std::size_t>(i)],
                    kOffsetY[static_cast<std::size_t>(i)], 9000, 24, 1.0, 50,
                    0x4000, "S03 FUN_14000ed10 final satellite 0x34");
            }
            enemy.liveChildCount = 4;
        }
        if (timer > 99 && enemy.liveChildCount == 0) {
            enemy.helperTimer = 0;
        }
        break;
    case 8:
        if (timer < 240) {
            spawnStage02DeathExplosionChain(enemy);
            enemy.y += 0.2f;
        }
        if (timer == 1) {
            stage03ClearStarted_ = true;
            player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
        }
        if (timer == 240) {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        }
        if (timer == 420) {
            stage03ClearTransition_ = true;
        }
        if (timer == 480) {
            stage03GateFlag_ = false;
            stage03ClearComplete_ = true;
            enemy.active = false;
        }
        break;
    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    stage03BossCountdownDraw_ = stage03BossCountdown_;
    if (stage03BossPhaseMode_ == 1) {
        updateBossCountdownAudio(enemy.hp, stage03BossCountdown_);
        --stage03BossCountdown_;
    }
}

void StageRuntime::emitStage03BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };

    if (enemy.helperState == 1) {
        static constexpr std::array<int, 5> kBurstLength{{20, 36, 50, 60, 60}};
        static constexpr std::array<int, 5> kAngleStep{{300, 400, 500, 500, 600}};
        static constexpr std::array<double, 5> kBaseSpeed{{4.0, 6.0, 7.5, 8.0, 9.0}};
        const int p = timer % 1000;
        if (p < 80 || p > 399) {
            return;
        }
        const int local = p - 80;
        const int block = local / 80;
        const int q = local % 80;
        const float sourceY = enemy.y + 140.0f;
        if (q == 0) {
            enemy.secondaryAngle16 = aimFrom(enemy.x, sourceY);
        }
        if (q < kBurstLength[static_cast<std::size_t>(difficulty)] && q % 4 == 0) {
            const int count = q / 4 + 1;
            const int spread = (count - 1) *
                               kAngleStep[static_cast<std::size_t>(difficulty)];
            const double speed = kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                                 static_cast<double>(block) * 0.5;
            spawnProjectileSpread(12, 0, enemy.x, sourceY,
                                  enemy.secondaryAngle16, 10.0f, speed, 1,
                                  count, spread, 0);
        }
        return;
    }

    if (enemy.helperState == 3) {
        static constexpr std::array<int, 5> kCadence{{40, 36, 30, 20, 16}};
        static constexpr std::array<int, 5> kFanCount{{5, 7, 9, 9, 9}};
        static constexpr std::array<double, 5> kFanSpeed{{4.0, 5.5, 6.5, 6.0, 7.0}};
        const int p = timer % 1200;
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        const float sourceY = enemy.y + 140.0f;
        if (p >= 30 && p <= 279) {
            const int local = p - 30;
            if (local % (cadence * 3) == 0) {
                enemy.secondaryAngle16 = aimFrom(enemy.x, sourceY);
            }
            if (local % cadence == 0) {
                const int count = kFanCount[static_cast<std::size_t>(difficulty)];
                const double speed = kFanSpeed[static_cast<std::size_t>(difficulty)];
                if (difficulty > 0) {
                    spawnProjectileSpread(1, 0, enemy.x, sourceY,
                                          enemy.secondaryAngle16, 0.0f,
                                          speed - 1.2, 1, count - 1, 24000, 0);
                }
                spawnProjectileSpread(5, 0, enemy.x, sourceY,
                                      enemy.secondaryAngle16, 0.0f, speed, 1,
                                      count, 24000, 0);
            }
        }

        static constexpr std::array<int, 5> kWindowGap{{70, 50, 40, 40, 40}};
        static constexpr std::array<int, 5> kWindowCount{{3, 5, 7, 7, 9}};
        static constexpr std::array<double, 5> kWindowSlope{{0.10, 0.18, 0.20, 0.20, 0.24}};
        int start = 320;
        for (int window = 0; window < 8; ++window) {
            const int length = 30 + window * 15;
            if (p >= start && p < start + length) {
                const int local = p - start;
                if (local == 0) {
                    enemy.targetAngle16 = aimFrom(enemy.x, sourceY);
                }
                if (local % 5 == 0) {
                    const int count = kWindowCount[static_cast<std::size_t>(difficulty)];
                    const double speed = 3.5 +
                        static_cast<double>(local) *
                            kWindowSlope[static_cast<std::size_t>(difficulty)];
                    spawnProjectileSpread(3, 0, enemy.x, sourceY,
                                          enemy.targetAngle16, 0.0f, speed, 1,
                                          count, 27000, 0);
                    if (difficulty >= 3) {
                        spawnProjectileSpread(3, 0, enemy.x, sourceY,
                                              enemy.targetAngle16, 0.0f,
                                              speed + 1.5, 1, count, 27000, 0);
                    }
                    enemy.targetAngle16 = approachAngle16(
                        enemy.targetAngle16, aimFrom(enemy.x, sourceY), 0x78);
                }
                break;
            }
            start += kWindowGap[static_cast<std::size_t>(difficulty)] +
                     window * 15;
        }
        return;
    }

    if (enemy.helperState == 5 && timer >= 10) {
        static constexpr std::array<int, 5> kPeriod{{150, 120, 100, 100, 100}};
        static constexpr std::array<int, 5> kCadence{{10, 9, 8, 8, 8}};
        const int period = kPeriod[static_cast<std::size_t>(difficulty)];
        const int phase = (timer - 10) % (period * 2);
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        const auto cachedAim = aimFrom(enemy.x, -3200.0f);
        if (phase >= 0 && phase < 60 && phase % cadence == 0) {
            spawnStage03BossChild(enemy, 0x32, timer, static_cast<float>(phase * 12),
                                  0.0f, 500, 4, 1.0, 30, cachedAim,
                                  "S03 FUN_14000ed10 left-to-right sweep node");
        }
        if (phase >= period && phase < period + 60) {
            const int local = phase - period;
            if (local % cadence == 0) {
                spawnStage03BossChild(enemy, 0x33, timer,
                                      static_cast<float>(720 - local * 12), 0.0f,
                                      500, 4, 1.5, 30, cachedAim,
                                      "S03 FUN_14000ed10 right-to-left sweep node");
            }
        }
    }
}

void StageRuntime::updateStage03BossChild(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != 0x13a || !parent->active) {
        enemy.active = false;
        return;
    }

    switch (enemy.spawnType) {
    case 0x30:
        updateStage03Type30(enemy, *parent);
        break;
    case 0x31:
        updateStage03Type31(enemy, *parent);
        break;
    case 0x32:
    case 0x33:
        updateStage03Type32Or33(enemy, *parent);
        break;
    case 0x34:
        updateStage03Type34(enemy, *parent);
        break;
    default:
        enemy.active = false;
        break;
    }
}

void StageRuntime::updateStage03Type30(StageEnemy& enemy, StageEnemy& parent) {
    const float targetX = parent.x + enemy.originX;
    const float targetY = parent.y + enemy.originY;
    if (enemy.helperTimer == 0) {
        enemy.x = targetX;
        enemy.y = targetY;
    }
    else {
        enemy.x += (targetX - enemy.x) / 5.0f;
        enemy.y += (targetY - enemy.y) / 5.0f;
    }
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    if (enemy.helperState == 0 && parent.helperState == 1) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
    }

    if (enemy.helperState == 1) {
        static constexpr std::array<int, 5> kCycle{{100, 60, 40, 36, 30}};
        static constexpr std::array<int, 5> kCount{{1, 1, 1, 2, 2}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 7.0, 8.0, 9.0}};
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int timer = enemy.helperTimer;
        if (timer > 9) {
            const int phase = (timer - 10) % kCycle[static_cast<std::size_t>(difficulty)];
            if (phase < 20 && phase % 4 == 0) {
                spawnProjectileSpread(
                    3, 0, enemy.x, enemy.y + 65.0f, 0x4000, 0.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)], 1,
                    kCount[static_cast<std::size_t>(difficulty)], 3000, 0);
            }
        }

        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 1800, false);
            spawnEnemyDeathEffects(enemy, 2);
            spawnStage03DeathNode(enemy, enemy.maxHp, parent.entityId);
            parent.liveChildCount = std::max(0, parent.liveChildCount - 1);
            ++enemy.helperState;
            enemy.targetable = false;
        }
        if (parent.helperState == 2) {
            spawnEnemyDeathEffects(enemy, 2);
            ++enemy.helperState;
            enemy.targetable = false;
        }
    }

    if (parent.helperState > 2 ||
        (parent.helperState == 2 && parent.helperTimer == 130)) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type31(StageEnemy& enemy, StageEnemy& parent) {
    const double oldHeading = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    const float projectileSourceX =
        enemy.x + static_cast<float>(std::cos(oldHeading) * 70.0);
    const float projectileSourceY =
        enemy.y + static_cast<float>(std::sin(oldHeading) * 70.0);
    const auto aimed = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - enemy.y),
        static_cast<double>(player_.x - enemy.x)));
    enemy.x = parent.x + enemy.originX;
    enemy.y = parent.y + enemy.originY;
    enemy.drawBodyThisFrame = true;
    enemy.targetable = false;

    const auto turnStepFor = [](std::uint16_t current, std::uint16_t target) {
        const int raw = (static_cast<int>(target) - static_cast<int>(current)) & 0xffff;
        const int distance = std::min(raw, 0x10000 - raw);
        return distance / 10 + 0x30;
    };

    if (enemy.helperState == 0 && parent.helperState == 1) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
    }
    else if (enemy.helperState == 0 && parent.helperState == 2) {
        enemy.helperState = 2;
        enemy.helperTimer = 0;
    }

    if (enemy.helperState == 1) {
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int local = enemy.helperTimer % 1000;

        if (local < 400) {
            static constexpr std::array<int, 5> kCadence{{100, 50, 40, 40, 30}};
            static constexpr std::array<int, 5> kCount{{1, 1, 1, 3, 3}};
            static constexpr std::array<double, 5> kSpeed{{4.5, 5.5, 6.0, 6.5, 7.5}};
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed,
                turnStepFor(enemy.sourceAngle16, aimed));
            const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
            if (local >= 30 && (local - 30) % cadence == 0) {
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(7, 0, projectileSourceX, projectileSourceY,
                                      enemy.sourceAngle16, 10.0f, speed, 1,
                                      count, 2400, 0);
                spawnProjectileSpread(7, 0, projectileSourceX, projectileSourceY,
                                      enemy.sourceAngle16, 10.0f, speed + 0.3, 1,
                                      count, 2400, 0);
            }
        }
        else if (local < 700) {
            static constexpr std::array<int, 5> kDivisor{{4, 3, 2, 2, 2}};
            static constexpr std::array<int, 5> kCount{{1, 2, 3, 3, 4}};
            static constexpr std::array<int, 5> kRotation{{700, 750, 800, 800, 800}};
            static constexpr std::array<double, 5> kSpeed{{2.0, 3.0, 4.0, 3.0, 3.5}};
            if (local <= 430) {
                const auto sideTarget = static_cast<std::uint16_t>(
                    enemy.originX <= 0.0f ? 0x6000 : 0xe000);
                enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                      sideTarget, 0x44c);
            }
            else if (local < 570) {
                enemy.sourceAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.sourceAngle16) +
                    kRotation[static_cast<std::size_t>(difficulty)]);
            }
            else {
                enemy.sourceAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.sourceAngle16) -
                    kRotation[static_cast<std::size_t>(difficulty)]);
            }
            if (local >= 430 &&
                (local - 430) % kDivisor[static_cast<std::size_t>(difficulty)] == 0) {
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                const int spread = (count - 1) * 8888;
                spawnProjectileSpread(13, 1, projectileSourceX, projectileSourceY,
                                      enemy.sourceAngle16, 10.0f, speed, 1,
                                      count, spread, 0);
                if (difficulty >= 3) {
                    spawnProjectileSpread(13, 1, projectileSourceX, projectileSourceY,
                                          enemy.sourceAngle16, 10.0f,
                                          speed + 1.5, 1, count, spread, 0);
                }
            }
        }
        else {
            static constexpr std::array<int, 5> kCadence{{80, 45, 40, 40, 40}};
            static constexpr std::array<int, 5> kCount{{3, 5, 7, 7, 9}};
            static constexpr std::array<int, 5> kGrowth{{4, 6, 8, 8, 1}};
            static constexpr std::array<double, 5> kSpeed{{4.0, 6.0, 7.0, 7.0, 8.0}};
            if (local <= 730) {
                enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                      aimed, 0x44c);
            }
            const int sequence = local - 730;
            if (sequence >= 0) {
                const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
                const int block = sequence / cadence;
                const int phase = sequence % cadence;
                int delta = 30 + block * kGrowth[static_cast<std::size_t>(difficulty)];
                if (sequence < 270 && phase == 0) {
                    enemy.targetAngle16 = aimed;
                }
                if (sequence < 270 && phase < 40 && phase % 4 == 0) {
                    const int count = kCount[static_cast<std::size_t>(difficulty)];
                    const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                         static_cast<double>(block) * 0.5 +
                                         static_cast<double>(phase) * 0.1;
                    spawnProjectileSpread(6, 0, projectileSourceX, projectileSourceY,
                                          enemy.targetAngle16, 10.0f, speed, 1,
                                          count, 22000, 0);
                    if (difficulty >= 3) {
                        spawnProjectileSpread(6, 0, projectileSourceX, projectileSourceY,
                                              enemy.targetAngle16, 10.0f,
                                              speed + 1.6, 1, count, 22000, 0);
                    }
                }
                if (sequence % (cadence * 2) >= cadence) {
                    delta = -delta;
                }
                enemy.targetAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.targetAngle16) + delta);
            }
        }

        if (parent.helperState == 2) {
            enemy.helperState = 2;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == 2 && parent.helperState == 3) {
        enemy.helperState = 3;
        enemy.helperTimer = 0;
    }

    if (enemy.helperState == 3) {
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        static constexpr std::array<int, 5> kInterval{{140, 100, 90, 90, 70}};
        static constexpr std::array<int, 5> kCount{{3, 5, 7, 7, 7}};
        static constexpr std::array<double, 5> kSpeed{{7.7, 8.5, 9.0, 9.0, 9.0}};
        const int p = enemy.helperTimer % 1200;
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        const int start = enemy.originX >= 0.0f ? 690 : 690 + interval;
        if (p >= start && p < 1120 && (p - start) % (interval * 2) == 0) {
            const int visual = enemy.originX >= 0.0f ? 3 : 2;
            const int behavior = enemy.originX >= 0.0f ? 26 : 27;
            spawnProjectileSpread(visual, behavior,
                                  projectileSourceX, projectileSourceY,
                                  aimed, 10.0f,
                                  kSpeed[static_cast<std::size_t>(difficulty)], 1,
                                  kCount[static_cast<std::size_t>(difficulty)],
                                  20000, 0);
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimed,
            turnStepFor(enemy.sourceAngle16, aimed));
        if (parent.hp < 1 || stage03BossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.active = false;
        }
    }
    if (parent.helperState > 4) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type32Or33(StageEnemy& enemy,
                                           StageEnemy& parent) {
    const int timer = enemy.helperTimer;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = timer;
    enemy.drawBodyThisFrame = true;
    if (enemy.helperState == 0) {
        if (timer == 0) {
            enemy.markerDrawX = parent.x;
            enemy.markerDrawY = parent.y;
        }
        const double entry = std::sin(static_cast<double>(timer) * kPi / 80.0);
        enemy.x = enemy.markerDrawX +
                  static_cast<float>(entry *
                      static_cast<double>(enemy.originX - enemy.markerDrawX));
        enemy.y = enemy.markerDrawY +
                  static_cast<float>(entry *
                      static_cast<double>(enemy.originY - enemy.markerDrawY));
        if ((timer & 1) == 0) {
            const int trail = enemySmallFrames_.size() > 29 ? enemySmallFrames_[29] : -1;
            const double scale = std::max(0.0, entry);
            spawnStageEffect(0x38, trail, 100, 0x22, enemy.x, enemy.y, 0,
                             0.0, scale, scale, 24,
                             0xff, 0xff, 0xff, 0x60);
        }
        if (timer == 40) {
            enemy.markerDrawX = enemy.originX;
            enemy.markerDrawY = enemy.originY;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
    }

    if (enemy.helperState == 1) {
        const float projectileSourceX = enemy.x;
        const float projectileSourceY = enemy.y;
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.markerDrawX += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.markerDrawY += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        enemy.sourceSpeed += 0.04;
        const float wobble = static_cast<float>(
            std::sin(static_cast<double>(enemy.helperTimer) * kPi / 75.0) * 30.0);
        enemy.x = enemy.markerDrawX + (enemy.spawnType == 0x32 ? wobble : -wobble);
        enemy.y = enemy.markerDrawY;

        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        static constexpr std::array<int, 5> kCycle{{80, 60, 50, 50, 50}};
        static constexpr std::array<int, 5> kBurst{{24, 32, 36, 36, 40}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.5, 7.0, 6.0, 7.5}};
        if (parent.helperTimer >= 60) {
            const int phase = (parent.helperTimer - 60) %
                              kCycle[static_cast<std::size_t>(difficulty)];
            if (phase == 0) {
                enemy.targetAngle16 = radiansToFixedAngleTrunc(std::atan2(
                    static_cast<double>(player_.y - (-200.0f)),
                    static_cast<double>(player_.x - parent.x)));
            }
            if (phase < kBurst[static_cast<std::size_t>(difficulty)] && phase % 4 == 0 &&
                enemy.y < 700.0f &&
                distanceSquared(enemy.x, enemy.y, player_.x, player_.y) > 30.0f * 30.0f) {
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(7, 0, projectileSourceX, projectileSourceY,
                                    enemy.targetAngle16, 10.0f, speed, 1, 0);
                spawnProjectileNode(7, 0, projectileSourceX, projectileSourceY,
                                    normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 0x8000),
                                    10.0f, speed, 1, 0);
                if (difficulty >= 3) {
                    spawnProjectileNode(7, 0, projectileSourceX, projectileSourceY,
                                        enemy.targetAngle16, 10.0f, speed + 2.0, 1, 0);
                    spawnProjectileNode(7, 0, projectileSourceX, projectileSourceY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 0x8000),
                                        10.0f, speed + 2.0, 1, 0);
                }
            }
        }
    }

    enemy.secondaryAngle16 = normalizeAngle16(
        static_cast<int>(enemy.secondaryAngle16) + 2000);
    enemy.drawHp = enemy.hp;

    if (enemy.hp < 1) {
        static constexpr std::array<double, 5> kDeathSpeed{{5.0, 6.0, 6.5, 6.5, 7.5}};
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        if (enemy.y < 520.0f &&
            distanceSquared(enemy.x, enemy.y, player_.x, player_.y) > 80.0f * 80.0f) {
            const auto aimed = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - enemy.y),
                static_cast<double>(player_.x - enemy.x)));
            spawnProjectileNode(2, 3, enemy.x, enemy.y, aimed, 0.0f,
                                kDeathSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
            if (difficulty >= 3) {
                spawnProjectileNode(2, 3, enemy.x, enemy.y, aimed, 0.0f,
                                    difficulty == 3 ? 8.0 : 9.0, 1, 0);
            }
        }
        spawnEnemyDeathRewardBurst(enemy, 500);
        // DAT_140e44654 is the live screen-clear/invulnerability countdown.
        // PlayerState's invulnerability timer is the closest represented gate.
        if (player_.invulnerableFrames == 0) {
            spawnStage03DeathNode(enemy, enemy.maxHp, parent.entityId);
        }
        enemy.active = false;
    }
    if (parent.hp < 1 || stage03BossCountdown_ < 1) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
    }
}

void StageRuntime::updateStage03Type34(StageEnemy& enemy, StageEnemy& parent) {
    const int timer = enemy.helperTimer;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = timer;
    enemy.drawBodyThisFrame = true;
    const float goalX = parent.x + enemy.markerDrawX;
    const float goalY = parent.y + enemy.markerDrawY;
    enemy.x += (goalX - enemy.x) / 10.0f;
    enemy.y += (goalY - enemy.y) / 10.0f;
    if (enemy.helperState == 0) {
        if (timer == 0) {
            enemy.x = parent.x;
            enemy.y = parent.y;
        }
        const double entry = std::sin(static_cast<double>(timer) * kPi / 80.0);
        enemy.markerDrawX = static_cast<float>(entry * enemy.originX);
        enemy.markerDrawY = static_cast<float>(entry * enemy.originY);
        if ((timer & 1) == 0) {
            const int trail = enemySmallFrames_.size() > 29 ? enemySmallFrames_[29] : -1;
            const double scale = std::max(0.0, entry);
            spawnStageEffect(0x38, trail, 100, 0x22, enemy.x, enemy.y, 0,
                             0.0, scale, scale, 24,
                             0xff, 0xff, 0xff, 0x60);
        }
        if (timer == 40) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
    }

    if (enemy.helperState == 1) {
        if (parent.helperTimer >= 80) {
            const int difficulty = std::clamp(config_.difficulty, 0, 4);
            const int p = (parent.helperTimer - 80) % 380;
            const int index = enemy.childIndex & 3;
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            const bool insideFiringArea = enemy.x >= horizontalOrigin &&
                                          enemy.x <= horizontalOrigin + 600.0f &&
                                          enemy.y >= 0.0f && enemy.y <= 720.0f;
            if (p <= 200) {
                static constexpr std::array<int, 5> kBurstLength{{6, 9, 12, 12, 12}};
                static constexpr std::array<int, 5> kRingCount{{15, 23, 27, 27, 25}};
                static constexpr std::array<int, 5> kAngleStep{{50, 70, 80, 80, 120}};
                static constexpr std::array<double, 5> kSpeed{{4.5, 6.4, 7.5, 8.0, 9.0}};
                const int start = index * 50;
                const int end = kBurstLength[static_cast<std::size_t>(difficulty)] +
                                index * 56;
                if (p == start) {
                    enemy.targetAngle16 = radiansToFixedAngleTrunc(std::atan2(
                        static_cast<double>(player_.y - enemy.y),
                        static_cast<double>(player_.x - enemy.x)));
                }
                if (insideFiringArea && p < 200 && p >= start && p < end &&
                    (p - start) % 3 == 0) {
                    const int count = kRingCount[static_cast<std::size_t>(difficulty)];
                    const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                         static_cast<double>(index) * 0.6;
                    spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                          enemy.targetAngle16, 0.0f, speed, 1,
                                          count, kFixedAngleFullCircle, 0);
                    if (difficulty >= 3) {
                        spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                              enemy.targetAngle16, 0.0f,
                                              speed + 1.2, 1, count,
                                              kFixedAngleFullCircle, 0);
                    }
                }
                const int direction = (index & 1) == 0 ? 1 : -1;
                enemy.targetAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.targetAngle16) + direction *
                        (kAngleStep[static_cast<std::size_t>(difficulty)] + index * 10));
            }
            if (p >= 200) {
                static constexpr std::array<int, 5> kSpacing{{32, 18, 16, 16, 10}};
                static constexpr std::array<int, 5> kCount{{23, 31, 35, 35, 35}};
                static constexpr std::array<double, 5> kSpeed{{3.6, 5.0, 5.5, 5.5, 6.5}};
                const int spacing = kSpacing[static_cast<std::size_t>(difficulty)];
                const int start = 200 + index * spacing;
                if (insideFiringArea && p >= start && p < 330 &&
                    (p - start) % (spacing * 5) == 0) {
                    const int count = kCount[static_cast<std::size_t>(difficulty)] + index * 2;
                    const double speed = kSpeed[static_cast<std::size_t>(difficulty)] +
                                         static_cast<double>(index) * 0.3;
                    const auto randomAngle = scriptRandomAngle(static_cast<std::uint32_t>(p));
                    spawnProjectileSpread(3, 0, enemy.x, enemy.y,
                                          randomAngle, 0.0f, speed, 1,
                                          count, kFixedAngleFullCircle, 0);
                    if (difficulty >= 3) {
                        std::uint32_t u = (((static_cast<std::uint32_t>(p) >> 30) ^
                                            static_cast<std::uint32_t>(p)) *
                                           0x6c078965u) + 1u;
                        const std::uint32_t a = (((u >> 30) ^ u) * 0x6c078965u) + 2u;
                        const std::uint32_t b = (((a >> 30) ^ a) * 0x6c078965u) + 3u;
                        const std::uint32_t c = (((b >> 30) ^ b) * 0x6c078965u) + 4u;
                        const std::uint32_t mixed1 = (u << 11) ^ u;
                        const std::uint32_t mixed2 = (mixed1 << 11) ^ mixed1;
                        const std::uint32_t result =
                            (((c >> 11) ^ mixed2) >> 8) ^ mixed2 ^ c;
                        const auto secondAngle = static_cast<std::uint16_t>(
                            result - result / 0x10001u);
                        spawnProjectileSpread(3, 0, enemy.x, enemy.y,
                                              secondAngle, 0.0f, speed + 1.0, 1,
                                              count, kFixedAngleFullCircle, 0);
                    }
                }
            }
        }
    }

    enemy.secondaryAngle16 = normalizeAngle16(
        static_cast<int>(enemy.secondaryAngle16) + 2000);
    enemy.drawHp = enemy.hp;
    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(enemy, 1800);
        spawnStage03DeathNode(enemy, std::max(1, enemy.maxHp / 2), parent.entityId);
        parent.liveChildCount = std::max(0, parent.liveChildCount - 1);
        enemy.active = false;
    }
    if (parent.hp < 1 || stage03BossCountdown_ < 1) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
    }
}

void StageRuntime::updateStage03DeathNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    StageEnemy* owner = findEnemyById(enemy.parentEntityId);
    if (owner == nullptr || owner->spawnType != enemy.parentSpawnType || !owner->active) {
        enemy.active = false;
        return;
    }
    const int chunk = std::max(1, enemy.maxHp / 30);
    const int damage = std::min(enemy.hp, chunk);
    enemy.hp -= damage;
    owner->hp -= damage;
    enemy.drawHp = enemy.hp;
    if (enemy.hp < 1) {
        enemy.active = false;
    }
}

void StageRuntime::updateStage01Enemy(StageEnemy& enemy, int activeAge) {
    // Stage 01 type routing is evidence-backed by stage-spawn-used-update-map.md:
    // 0x0a->FUN_14007c9c0, 0x0b->FUN_14007d4e0, 0x0c->FUN_14007dfb0,
    // 0x0d->FUN_14007ea30, 0x0e->FUN_14007f2c0, 0x0f->FUN_140080170,
    // 0x10->FUN_140080fb0, 0x11->FUN_140082090, 0x06..0x08->FUN_140082d90,
    // marker satellite 0x09->FUN_140083db0, boss handoff 0x138->FUN_140004660.
    switch (enemy.spawnType) {
    case 0x0a:
        updateStage01Type0A(enemy, activeAge);
        break;
    case 0x0b:
        updateStage01Type0B(enemy, activeAge);
        break;
    case 0x0c:
        updateStage01Type0C(enemy, activeAge);
        break;
    case 0x0d:
        updateStage01Type0D(enemy, activeAge);
        break;
    case 0x0e:
        updateStage01Type0E(enemy);
        break;
    case 0x0f:
    case 0x10:
        updateStage01Setpiece(enemy, activeAge);
        break;
    case 0x11:
        updateStage01Child(enemy, activeAge);
        break;
    case 0x15:
    case 0x16:
    case 0x17:
        updateStage01BossChild(enemy);
        break;
    case 0x09:
        updateStage01MarkerSatellite(enemy, activeAge);
        break;
    case 0x06:
    case 0x07:
    case 0x08:
        updateStage01Marker(enemy, activeAge);
        break;
    case 0x138:
        updateStage01Boss(enemy);
        break;
    default:
        // Every Stage 1 entity observed in the script or created by its boss
        // helpers has a dedicated route above.
        break;
    }
}

void StageRuntime::updateStage01Type0A(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    constexpr double kOriginalPi = 3.14159265358979;

    // FUN_14007c9c0 evaluates its animation from the global gameplay frame
    // before the dispatcher advances any timers. Cache those draw values here
    // because StageRuntime renders after update().
    const int animationTick = frame_ + enemy.entityId * 5;
    enemy.visualFrame = 12 + (animationTick % 18) / 6;
    enemy.targetAngle16 = normalizeAngle16(static_cast<int>(
        std::sin(static_cast<double>(animationTick) * kOriginalPi / 4.0) * 3000.0));
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    // The runtime increments age before dispatch. During state 0, age-1 is the
    // original +0x0c helper timer; after the transition reset, age itself is
    // the original active-state timer.
    int stateAge = enemy.age;
    if (enemy.helperState == 0) {
        stateAge = std::max(0, enemy.age - 1);
    }
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = stateAge;

    // The helper computes this aim before changing the state-0 position. On
    // timer 120 that pre-interpolation angle becomes the initial travel angle.
    const std::uint16_t preMoveAim = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(player_.y - enemy.y),
                   static_cast<double>(player_.x - enemy.x)));

    if (enemy.helperState == 0) {
        const std::uint32_t random = stageScriptRandFromFrame(enemy.entityId);
        const std::uint16_t entryAngle16 = static_cast<std::uint16_t>(
            random % 4001u + 0x3830u);
        const double entryAngle = fixedAngleToRadiansDouble(entryAngle16);
        const float entryX = enemy.originX +
                             static_cast<float>(std::cos(entryAngle) * 300.0);
        const float entryY = enemy.originY +
                             static_cast<float>(std::sin(entryAngle) * 300.0);
        const double interpolation = std::sin(
            static_cast<double>(stateAge) * kOriginalPi / 240.0);
        enemy.x = entryX + static_cast<float>(
                              interpolation * static_cast<double>(enemy.originX - entryX));
        enemy.y = entryY + static_cast<float>(
                              interpolation * static_cast<double>(enemy.originY - entryY));
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (stateAge != 0x78) {
            return;
        }

        enemy.helperState = 1;
        enemy.age = 0;
        stateAge = 0;
        enemy.sourceSpeed = 0.8;
        enemy.sourceAngle16 = preMoveAim;
        enemy.targetable = true;
    }

    if (enemy.sourceSpeed <= 0.0) {
        enemy.sourceSpeed = 0.8;
    }
    if (stateAge < 300) {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, preMoveAim, 0x100);
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x100);
        enemy.sourceSpeed += 0.1;
    }
    const double travelAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(travelAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(travelAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(travelAngle) * enemy.sourceSpeed);
}

void StageRuntime::updateStage01Type0B(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    // FUN_14007d4e0 computes this aim before its state-0 clamp and reuses it
    // for steering on the transition frame.
    const auto preMoveAim = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - enemy.y),
        static_cast<double>(player_.x - enemy.x)));

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (enemy.helperTimer != 20) {
            return;
        }

        enemy.sourceSpeed = scriptRandomHundredth(
            static_cast<std::uint32_t>(frame_), 7.0, 9.0);
        if (enemy.x <= 0.0f) {
            enemy.sourceAngle16 = 0;
        }
        if (enemy.x >= 720.0f) {
            enemy.sourceAngle16 = 0x8000;
        }
        enemy.x = enemy.markerDrawX;
        enemy.y = enemy.markerDrawY;
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer < 200) {
        if (timer >= 0 && enemy.sourceSpeed > 1.0) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, preMoveAim, 0x80);
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x200);
        enemy.sourceSpeed += 0.1;
    }

    // The helper retains these pre-movement values for its projectile source.
    enemy.originX = enemy.x;
    enemy.originY = enemy.y;
    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Type0C(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    const auto preMoveAim = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - enemy.y),
        static_cast<double>(player_.x - enemy.x)));

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (enemy.helperTimer != 20) {
            return;
        }

        enemy.sourceSpeed = scriptRandomHundredth(
            static_cast<std::uint32_t>(frame_), 5.0, 7.0);
        if (enemy.x <= 0.0f) {
            enemy.sourceAngle16 = 0;
        }
        if (enemy.x >= 720.0f) {
            enemy.sourceAngle16 = 0x8000;
        }
        enemy.x = enemy.markerDrawX;
        enemy.y = enemy.markerDrawY;
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer < 200) {
        if (timer >= 0 && enemy.sourceSpeed > 1.0) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, preMoveAim, 0x80);
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x100);
        enemy.sourceSpeed += 0.1;
    }

    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Type0D(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    constexpr double kOriginalPi = 3.14159265358979;

    // FUN_14007ea30 caches +0x40 on entry. The transition frame therefore
    // moves with the newly selected angle but still chooses its muzzle/body
    // side from the old 0x4000 constructor angle.
    enemy.secondaryAngle16 = enemy.sourceAngle16;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -20.0f, 740.0f);
        if (enemy.helperTimer != 0x14) {
            return;
        }

        enemy.sourceSpeed = selectedStage_ >= 4 ? 4.0 : 3.0;
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        if (enemy.x <= 360.0f) {
            enemy.sourceAngle16 = 0xf2fb;
        }
        if (enemy.x >= 720.0f) {
            enemy.sourceAngle16 = 0x8d05;
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    const int phase = timer % 33;
    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.originX += static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.originY += static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.x = enemy.originX;
    enemy.y = enemy.originY - static_cast<float>(
                                  std::sin(static_cast<double>(phase) *
                                           kOriginalPi / 33.0) *
                                  10.0);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Type0E(StageEnemy& enemy) {
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    const auto entryAim = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - enemy.y),
        static_cast<double>(player_.x - enemy.x)));

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (enemy.helperTimer != 0x14) {
            return;
        }

        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 7.0;
        enemy.speed = 7.0f;
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer <= 0x78 && enemy.sourceSpeed > 1.2) {
        enemy.sourceSpeed -= 0.1;
    }
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, entryAim, 0x80);
    if (timer >= 300) {
        enemy.sourceSpeed -= 0.1;
    }

    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Type0F(StageEnemy& enemy) {
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    // FUN_140080170 captures this aim before its entry transition and before
    // active movement, then uses the same value for the capped turn.
    const auto entryAim = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - enemy.y),
        static_cast<double>(player_.x - enemy.x)));

    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (enemy.helperTimer != 0x14) {
            return;
        }

        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.sourceSpeed = 9.0;
        enemy.speed = 9.0f;
        if (enemy.x <= 360.0f) {
            enemy.sourceAngle16 = 0;
        }
        if (enemy.x >= 720.0f) {
            enemy.sourceAngle16 = 0x8000;
        }
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer <= 0x78 && enemy.sourceSpeed > 1.0) {
        enemy.sourceSpeed -= 0.1;
    }
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, entryAim, 0x80);
    if (timer >= 300) {
        enemy.sourceSpeed -= 0.1;
    }

    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Setpiece(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    // FUN_140080fb0 owns Stage 1's 0x10 gate controller. Its entry lasts 120
    // ticks; the combat state persists until death or the original bounds tail.
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    if (enemy.helperState == 2) {
        const int timer = enemy.helperTimer;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.speed = 0.0f;
        if (timer <= 60) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += static_cast<float>(timer) * 0.1f;
        if (timer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            enemy.active = false;
            stage01GateFlag_ = false;
        }
        return;
    }

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        if (timer == 0) {
            spawnStage01Child(enemy, 0, 160.0f, 40.0f, 7000,
                              "S01 0x10 child 0x11 offset (+160,+40) from FUN_140080fb0");
            spawnStage01Child(enemy, 1, -160.0f, 40.0f, 7000,
                              "S01 0x10 child 0x11 offset (-160,+40) from FUN_140080fb0");
            enemy.liveChildCount = 2;
            if (selectedStage_ == 1) {
                spawnStage01Child(enemy, 2, 270.0f, -20.0f, 7000,
                                  "S01 0x10 child 0x11 offset (+270,-20) from FUN_140080fb0");
                spawnStage01Child(enemy, 3, -270.0f, -20.0f, 7000,
                                  "S01 0x10 child 0x11 offset (-270,-20) from FUN_140080fb0");
                enemy.liveChildCount = 4;
            }
        }

        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (timer < 90) {
            constexpr double kOriginalPi = 3.14159265358979323846;
            const int entryOffset = 1000 - static_cast<int>(
                std::sin(static_cast<double>(timer) * kOriginalPi / 180.0) * 1000.0);
            enemy.y = enemy.originY + static_cast<float>(entryOffset);
        }
        else {
            enemy.y = enemy.originY;
        }
        enemy.originY += 1.0f;

        if (timer == 120) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 0.7;
            enemy.speed = 0.7f;
            enemy.targetable = true;
        }
        else {
            return;
        }
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        if (timer < 900) {
            if (timer % 20 == 0) {
                enemy.originX = static_cast<float>(stageRandCoord(frame_, 0x141, 200));
                enemy.originY = static_cast<float>(stageRandCoord(frame_ + 0x457, 0x29, 0xb4));
            }
            const auto target = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(enemy.originY - enemy.y),
                static_cast<double>(enemy.originX - enemy.x)));
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x200);
        }
        else {
            enemy.sourceSpeed = static_cast<double>(timer - 900) * 0.1;
            enemy.sourceAngle16 = 0xc000;
        }
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        enemy.angle = static_cast<float>(radians);
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.vx = static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.vy = static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        return;
    }
}

void StageRuntime::updateStage01Marker(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    // FUN_140082d90 handles the common 0x06..0x08 marker family. Its state-0
    // marker and the newly active body are both queued on transition timer 20.
    if (enemy.helperState == 0) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                      horizontalOrigin + 650.0f);
        enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);
        if (enemy.helperTimer != 0x14) {
            return;
        }

        enemy.sourceSpeed = 6.0;
        enemy.speed = 6.0f;
        const bool createsHelpSatellites =
            (enemy.spawnType == 0x06 &&
             (config_.routeMode == 0 || config_.routeMode == 1)) ||
            (enemy.spawnType == 0x07 && config_.routeMode == 0);
        const int satelliteCount = createsHelpSatellites ? effectiveHelpLevel() : 0;
        for (int childIndex = 0; childIndex < satelliteCount; ++childIndex) {
            spawnStage01MarkerSatellite(
                enemy, childIndex, 0.0f, 0.0f, 3000,
                "FUN_140082d90 Help satellite type 0x09");
        }
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }

    if (enemy.helperState != 1) {
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    constexpr std::array<int, 5> kStart{{40, 30, 30, 30, 30}};
    constexpr std::array<int, 5> kCycle{{100, 80, 60, 60, 50}};
    const int timer = enemy.helperTimer;
    const int start = kStart[static_cast<std::size_t>(difficulty)];
    const int cycle = kCycle[static_cast<std::size_t>(difficulty)];
    const auto aimed = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(player_.y - (enemy.y + 75.0f)),
        static_cast<double>(player_.x - enemy.x)));
    if ((timer - start) % cycle == 0) {
        enemy.secondaryAngle16 = aimed;
    }
    enemy.secondaryAngle16 = approachAngle16(
        enemy.secondaryAngle16, aimed, 0x14);

    if (timer <= 120 && enemy.sourceSpeed > 1.0) {
        enemy.sourceSpeed -= 0.1;
    }
    const double motionAngle = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    enemy.angle = static_cast<float>(motionAngle);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = static_cast<float>(std::cos(motionAngle) * enemy.sourceSpeed);
    enemy.vy = static_cast<float>(std::sin(motionAngle) * enemy.sourceSpeed);
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01MarkerSatellite(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr) {
        enemy.active = false;
        return;
    }
    if (parent->hp < 1) {
        spawnEnemyDeathEffects(enemy, 0);
        const auto rewardAngle = normalizeAngle16(
            static_cast<int>(stageScriptRandFromFrame(enemy.entityId) % 0x4001u) +
            0x2000);
        spawnRewardItem(7, enemy.x, enemy.y, rewardAngle,
                        stage01SpeedConstantValue(0x070), 30);
        enemy.active = false;
        return;
    }
    if (!parent->active) {
        enemy.active = false;
        return;
    }

    const int timer = enemy.helperTimer;
    if (timer == 0) {
        enemy.secondaryAngle16 = scriptRandomAngle(
            static_cast<std::uint32_t>(enemy.entityId + 0x6f));
    }
    enemy.secondaryAngle16 = normalizeAngle16(
        static_cast<int>(enemy.secondaryAngle16) + 0x200);

    double radiusA = 160.0;
    double radiusB = 60.0;
    if (timer <= 60) {
        const double entrance = std::sin(
            static_cast<double>(timer) * static_cast<double>(kPi) / 120.0);
        radiusA = entrance * 160.0 + 1.0;
        radiusB = entrance * 60.0 + 1.0;
    }
    const double source = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    const double inner = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
    const double sourceCos = std::cos(source);
    const double sourceSin = std::sin(source);
    const double innerCos = std::cos(inner);
    const double innerSin = std::sin(inner);
    enemy.x = parent->x + static_cast<float>(
        sourceCos * innerCos * radiusB - sourceSin * innerSin * radiusA);
    enemy.y = parent->y + static_cast<float>(
        sourceCos * innerSin * radiusA + sourceSin * innerCos * radiusB);
    enemy.angle = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;
}

void StageRuntime::updateStage01Child(StageEnemy& enemy, int activeAge) {
    // FUN_140082090: child type 0x11 resolves a parent entity by id, starts by
    // following parent-relative offsets, then switches to an aimed state that
    // emits visual selectors 7 and 9 with their original movement IDs. Parent-id lookup is represented by the
    // captured parent entity id; if the parent is gone, the child expires.
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != enemy.parentSpawnType) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
        return;
    }

    const auto finishTerminalState = [this, &enemy, parent]() {
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x4b0, false);
            spawnEnemyDeathEffects(enemy, 1);
            spawnDelayedOwnerDamageNode(
                std::max(1, enemy.maxHp / 2), parent->entityId,
                parent->spawnType,
                "S01 type 0x11 delayed-damage node 0x153");
            parent->liveChildCount = std::max(0, parent->liveChildCount - 1);
            enemy.active = false;
        }
        // FUN_140082090 evaluates these owner tails independently after the
        // child's own lethal branch.
        if (parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.active = false;
        }
        if (!parent->active) {
            enemy.active = false;
        }
    };

    if (enemy.helperState == 0) {
        // The dispatcher increments age before this reconstruction runs, so
        // age 1 corresponds to the original helper's attach timer 0.
        const int attachTimer = std::max(0, activeAge - 1);
        constexpr double kOriginalPi = 3.14159265358979323846;
        if (attachTimer == 0) {
            enemy.x = parent->x;
            enemy.y = parent->y;
        }
        else {
            // FUN_140082090 moves 1/20 of the remaining distance toward the
            // parent plus the offset calculated on the previous tick.
            const double previousScale = std::sin(
                static_cast<double>(attachTimer - 1) * kOriginalPi / 240.0);
            const float targetX = parent->x + static_cast<float>(
                static_cast<int>(previousScale * static_cast<double>(enemy.originX)));
            const float targetY = parent->y + static_cast<float>(
                static_cast<int>(previousScale * static_cast<double>(enemy.originY)));
            enemy.x += (targetX - enemy.x) / 20.0f;
            enemy.y += (targetY - enemy.y) / 20.0f;
        }
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (attachTimer == 0x78) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = 1.0;
            enemy.secondaryAngle16 = enemy.sourceAngle16;
            enemy.targetable = true;
        }
        finishTerminalState();
        return;
    }

    const int stateAge = enemy.age;
    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    enemy.vx = (targetX - enemy.x) / 20.0f;
    enemy.vy = (targetY - enemy.y) / 20.0f;
    if (stateAge < 300) {
        // FUN_140082090 deliberately aims from the parent anchor during the
        // first window, even though the projectile source is the child.
        const auto targetAngle = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - parent->y),
            static_cast<double>(player_.x - parent->x)));
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, targetAngle, 0x20);
    }
    else if (stateAge < 900) {
        const auto targetAngle = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
        int delta = static_cast<int>(targetAngle) -
                    static_cast<int>(enemy.sourceAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, targetAngle, std::abs(delta) / 20 + 1);
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    finishTerminalState();
}

void StageRuntime::updateStage01Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawHp = enemy.hp;
    const auto steeringTarget = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(stage01BossTargetY_ - enemy.y),
                   static_cast<double>(stage01BossTargetX_ - enemy.x)));
    if (frame_ % 50 == 0) {
        stage01BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
        stage01BossTargetY_ = static_cast<float>(
            stageRandCoord(frame_ + selectedStage_ * 111, 101, 150));
    }

    if (stage01BossPhaseMode_ == 1 &&
        (enemy.hp < 1 || stage01BossCountdown_ < 1)) {
        const bool countdownExpired = stage01BossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, stage01BossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.helperTimer = 0;
        if (stage01BossBreaksRemaining_ == 3) {
            enemy.helperState = 2;
            enemy.radius = 240;
            stage01BossPhaseMode_ = 2;
        }
        else if (stage01BossBreaksRemaining_ == 2) {
            enemy.helperState = 4;
            stage01BossPhaseMode_ = 2;
        }
        else if (stage01BossBreaksRemaining_ == 1) {
            enemy.helperState = 6;
            stage01BossPhaseMode_ = -1;
        }
        stage01BossBreaksRemaining_ = std::max(0, stage01BossBreaksRemaining_ - 1);
        enemy.liveChildCount = 0;
    }

    // The original queues rendering inside the helper before the dispatcher
    // increments or a state tail resets +0x0c.
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawBodyThisFrame = true;
    const int timer = enemy.helperTimer;

    const auto steerTowardStageTarget = [&enemy, steeringTarget]() {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, steeringTarget, 0x200);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.x += std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        enemy.y += std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
    };

    switch (enemy.helperState) {
    case 0:
        if (timer == 0) {
            spawnStage01BossDecoration(
                enemy, 0x12, 0.0f, 210.0f,
                "S01 FUN_140004660 state 0 type 0x12 decoration");
        }
        if (timer < 180) {
            const double pathAngle = static_cast<double>(timer + 60) * static_cast<double>(kPi) / 120.0;
            const int amplitude = -600 - static_cast<int>(-600.0 *
                                                           std::sin(static_cast<double>(timer) *
                                                                    static_cast<double>(kPi) / 360.0));
            enemy.x = enemy.originX + static_cast<float>(std::sin(pathAngle) * amplitude);
            enemy.y = 600.0f + static_cast<float>(static_cast<int>(std::sin(pathAngle) *
                                                                   static_cast<double>(enemy.originY - 600.0f)));
        }
        else if (timer < 191) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
        }
        else {
            enemy.y += 0.1f;
        }
        if (timer == 240) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = 60000;
            enemy.maxHp = 60000;
            enemy.targetable = true;
            stage01BossMaxHp_ = 60000;
            stage01BossCountdown_ = 1800;
            stage01BossPhaseIndex_ = 0;
            stage01BossPhaseMode_ = 1;
        }
        break;
    case 1:
        steerTowardStageTarget();
        emitStage01BossProjectiles(enemy);
        break;
    case 2:
        if (timer < 120) {
            enemy.y += static_cast<float>(timer) * 0.02f;
        }
        else if (timer >= 130) {
            steerTowardStageTarget();
        }
        if (timer == 380) {
            enemy.radius = 80;
            enemy.targetable = true;
            enemy.helperState = 3;
            enemy.helperTimer = 0;
            enemy.hp = 55000;
            enemy.maxHp = 55000;
            stage01BossMaxHp_ = 55000;
            stage01BossCountdown_ = 1800;
            stage01BossPhaseIndex_ = 0;
            stage01BossPhaseMode_ = 1;
        }
        break;
    case 3:
        steerTowardStageTarget();
        if (timer == 1) {
            spawnStage01BossChild(enemy, 0x15, 0, -30.0f, 200.0f, 6000,
                                  "S01 FUN_140004660 state 3 type 0x15 child 0");
        }
        else if (timer == 11) {
            spawnStage01BossChild(enemy, 0x15, 1, -30.0f, -200.0f, 6000,
                                  "S01 FUN_140004660 state 3 type 0x15 child 1");
        }
        else if (timer == 21) {
            spawnStage01BossChild(enemy, 0x15, 2, -140.0f, 110.0f, 6000,
                                  "S01 FUN_140004660 state 3 type 0x15 child 2");
        }
        else if (timer == 31) {
            spawnStage01BossChild(enemy, 0x15, 3, -140.0f, -110.0f, 6000,
                                  "S01 FUN_140004660 state 3 type 0x15 child 3");
        }
        emitStage01BossProjectiles(enemy);
        break;
    case 4:
        enemy.y += 0.1f;
        if (timer == 180) {
            enemy.targetable = true;
            enemy.helperState = 5;
            enemy.helperTimer = 0;
            enemy.hp = 60000;
            enemy.maxHp = 60000;
            stage01BossMaxHp_ = 60000;
            stage01BossCountdown_ = 1800;
            stage01BossPhaseIndex_ = 0;
            stage01BossPhaseMode_ = 1;
        }
        break;
    case 5:
        steerTowardStageTarget();
        if (timer == 1) {
            spawnStage01BossChild(enemy, 0x16, 0, 200.0f, -30.0f, 12000,
                                  "S01 FUN_140004660 state 5 type 0x16 child 0");
        }
        else if (timer == 11) {
            spawnStage01BossChild(enemy, 0x16, 1, -200.0f, -30.0f, 12000,
                                  "S01 FUN_140004660 state 5 type 0x16 child 1");
        }
        else if (timer == 21) {
            spawnStage01BossChild(enemy, 0x17, 0, 100.0f, -160.0f, 7000,
                                  "S01 FUN_140004660 state 5 type 0x17 child 0");
        }
        else if (timer == 31) {
            spawnStage01BossChild(enemy, 0x17, 1, -100.0f, -160.0f, 7000,
                                  "S01 FUN_140004660 state 5 type 0x17 child 1");
        }
        emitStage01BossProjectiles(enemy);
        break;
    case 6:
        if (timer == 1) {
            stage01ClearStarted_ = true;
            player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
        }
        if (timer == 420) {
            stage01ClearTransition_ = true;
        }
        if (timer == 480) {
            stage01GateFlag_ = false;
            stage01ClearComplete_ = true;
            enemy.active = false;
        }
        if (timer < 240) {
            enemy.y += 0.2f;
        }
        break;
    default:
        break;
    }

    // FUN_140002260 runs at the tail of the boss helper. A newly opened
    // 1800-frame bar therefore leaves its transition frame at 1799.
    stage01BossCountdownDraw_ = stage01BossCountdown_;
    if (stage01BossPhaseMode_ == 1) {
        updateBossCountdownAudio(enemy.hp, stage01BossCountdown_);
        --stage01BossCountdown_;
    }
}

void StageRuntime::updateStage01BossDecoration(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr) {
        enemy.drawBodyThisFrame = false;
        enemy.active = false;
        return;
    }

    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    if (enemy.helperTimer == 0) {
        enemy.x = parent->x;
        enemy.y = parent->y;
    }
    else {
        // FUN_140007960 closes one fifth of the remaining owner-relative
        // displacement on every helper call.
        enemy.x += (targetX - enemy.x) / 5.0f;
        enemy.y += (targetY - enemy.y) / 5.0f;
    }

    if (enemy.spawnType == 0x12 && enemy.helperTimer == 0) {
        spawnStage01BossDecoration(
            enemy, 0x13, 60.0f, 120.0f,
            "S01 FUN_140007960 type 0x13 right decoration");
        spawnStage01BossDecoration(
            enemy, 0x13, -60.0f, 120.0f,
            "S01 FUN_140007960 type 0x13 left decoration");
        spawnStage01BossDecoration(
            enemy, 0x14, 80.0f, -80.0f,
            "S01 FUN_140007960 type 0x14 right decoration");
        spawnStage01BossDecoration(
            enemy, 0x14, -80.0f, -80.0f,
            "S01 FUN_140007960 type 0x14 left decoration");
    }

    StageEnemy* root = parent;
    if (root->spawnType != 0x138) {
        root = findEnemyById(root->parentEntityId);
    }
    if (root == nullptr || root->spawnType != 0x138) {
        enemy.active = false;
        return;
    }

    // Tail-appended nodes run after the owner. Its queue snapshot retains the
    // state/timer values FUN_140007960 tests before unlinking this apparatus.
    if (root->drawHelperState == 2 && root->drawHelperTimer == 130) {
        enemy.active = false;
    }
}

void StageRuntime::emitStage01BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;

    if (enemy.helperState == 1 && timer >= 40) {
        static constexpr std::array<double, 5> kPrimarySpeed{{4.0, 5.0, 6.5, 7.5, 9.0}};
        static constexpr std::array<int, 5> kVisual1Cadence{{7, 7, 5, 5, 4}};
        static constexpr std::array<int, 5> kSideCadence{{20, 14, 10, 10, 10}};
        static constexpr std::array<int, 5> kSideCount{{3, 5, 7, 7, 8}};
        static constexpr std::array<double, 5> kSideSpeed{{3.5, 4.5, 6.5, 7.0, 9.0}};
        static constexpr std::array<int, 5> kRotateCadence{{6, 4, 3, 3, 2}};
        static constexpr std::array<int, 5> kRotateCount{{3, 5, 7, 9, 11}};
        static constexpr std::array<int, 5> kRotateStep{{1000, 1400, 2060, 2060, 2900}};
        static constexpr std::array<double, 5> kRotateSpeed{{3.5, 5.5, 6.0, 6.0, 7.5}};
        const int local = (timer - 40) % 720;
        const double primarySpeed = kPrimarySpeed[static_cast<std::size_t>(difficulty)];
        const float centerY = enemy.y + 70.0f;

        if (local % 60 == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - centerY),
                           static_cast<double>(player_.x - enemy.x)));
        }
        const bool primaryWindow = local < 30 ||
                                   (local >= 240 && local < 270) ||
                                   (local >= 300 && local < 330) ||
                                   (local >= 600 && local < 630) ||
                                   (local >= 660 && local < 690);
        if (primaryWindow && local % 4 == 0) {
            spawnProjectileNode(0x0b, 0, enemy.x, centerY, enemy.secondaryAngle16,
                                10.0f, primarySpeed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0x0b, 0, enemy.x, centerY,
                                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 1500),
                                    10.0f, primarySpeed - 1.0, 1, 0);
                spawnProjectileNode(0x0b, 0, enemy.x, centerY,
                                    normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 1500),
                                    10.0f, primarySpeed - 1.0, 1, 0);
            }
        }

        const bool visual1Window = (local >= 10 && local < 40) ||
                                   (local >= 250 && local < 280) ||
                                   (local >= 310 && local < 340) ||
                                   (local >= 610 && local < 640) ||
                                   (local >= 670 && local < 700);
        if (difficulty > 0 && visual1Window) {
            const int phase = (local - 10) % 60;
            if (phase % kVisual1Cadence[static_cast<std::size_t>(difficulty)] == 0) {
                spawnProjectileSpread(1, 0, enemy.x, centerY, enemy.secondaryAngle16,
                                      0.0f, primarySpeed - 0.4, 1, 2,
                                      phase * 800 + 1200, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(1, 0, enemy.x, centerY, enemy.secondaryAngle16,
                                          0.0f, primarySpeed - 1.6, 1, 2,
                                          phase * 800 + 2000, 0);
                }
            }
        }

        const int sideCadence = kSideCadence[static_cast<std::size_t>(difficulty)];
        const int sideCount = kSideCount[static_cast<std::size_t>(difficulty)];
        const double sideSpeed = kSideSpeed[static_cast<std::size_t>(difficulty)];
        const bool rightSide = local >= 60 && local < 100;
        const bool leftSide = local >= 125 && local < 165;
        if (local == 60 || local == 125) {
            const float sourceX = enemy.x + (local == 60 ? 95.0f : -95.0f);
            const float sourceY = enemy.y - 5.0f;
            enemy.targetAngle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - sourceY),
                           static_cast<double>(player_.x - sourceX)));
        }
        if ((rightSide && (local - 60) % sideCadence == 0) ||
            (leftSide && (local - 125) % sideCadence == 0)) {
            const float sourceX = enemy.x + (rightSide ? 95.0f : -95.0f);
            const float sourceY = enemy.y - 5.0f;
            const int jitter = static_cast<int>(stageScriptRandFromFrame(timer) % 6001u) - 3000;
            const auto angle = normalizeAngle16(static_cast<int>(enemy.targetAngle16) + jitter);
            spawnProjectileSpread(4, 0, sourceX, sourceY, angle, 0.0f, sideSpeed,
                                  1, sideCount, 12000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(0, 0, sourceX, sourceY, angle, 0.0f, sideSpeed - 2.0,
                                      1, sideCount, 12000, 0);
            }
        }

        const int rotateCadence = kRotateCadence[static_cast<std::size_t>(difficulty)];
        const int rotateCount = kRotateCount[static_cast<std::size_t>(difficulty)];
        const int rotateSpread = rotateCount * 400 - 400;
        const int rotateStep = kRotateStep[static_cast<std::size_t>(difficulty)];
        const double rotateBaseSpeed = kRotateSpeed[static_cast<std::size_t>(difficulty)];
        const bool rightRotate = local >= 360 && local < 440;
        const bool leftRotate = local >= 470 && local < 560;
        if ((rightRotate && (local - 360) % rotateCadence == 0) ||
            (leftRotate && (local - 470) % rotateCadence == 0)) {
            const float sourceX = enemy.x + (rightRotate ? 95.0f : -95.0f);
            const float sourceY = enemy.y - 5.0f;
            const int rawAngle = rightRotate ? local * rotateStep + 0x6000
                                             : -0x6000 - local * rotateStep;
            const auto angle = normalizeAngle16(rawAngle);
            const double speed = rotateBaseSpeed +
                                 static_cast<double>(local - (rightRotate ? 360 : 470)) * 0.01;
            spawnProjectileSpread(4, 0, sourceX, sourceY, angle, 0.0f, speed,
                                  1, rotateCount, rotateSpread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(4, 0, sourceX, sourceY, angle, 0.0f, speed + 1.2,
                                      1, rotateCount, rotateSpread, 0);
            }
        }
        return;
    }

    if (enemy.helperState == 3 && timer >= 180) {
        static constexpr std::array<int, 5> kCadence{{16, 12, 8, 7, 6}};
        static constexpr std::array<int, 5> kCount{{1, 3, 4, 5, 7}};
        static constexpr std::array<int, 5> kSpread{{0, 7000, 10000, 12000, 16000}};
        static constexpr std::array<int, 5> kStep{{180, 240, 300, 300, 350}};
        static constexpr std::array<double, 5> kSpeed{{3.5, 4.0, 4.5, 5.0, 7.2}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        const int count = kCount[static_cast<std::size_t>(difficulty)];
        const int spread = kSpread[static_cast<std::size_t>(difficulty)];
        const int step = kStep[static_cast<std::size_t>(difficulty)];
        double speed = kSpeed[static_cast<std::size_t>(difficulty)];
        const bool noChildren = enemy.liveChildCount < 1;
        if (noChildren) {
            speed *= 1.5;
        }
        if ((timer - 180) % cadence == 0) {
            spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                  normalizeAngle16((timer - 180) * step - 0x2000),
                                  0.0f, speed, 1, count, spread, 0);
            if (noChildren) {
                spawnProjectileSpread(5, 0, enemy.x, enemy.y,
                                      normalizeAngle16((timer - 180) * step + 0x2000),
                                      0.0f, speed + 1.0, 1, count, spread, 0);
            }
        }
        if (timer >= 280 && (timer - 280) % cadence == 0) {
            spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                  normalizeAngle16((280 - timer) * step - 0x6000),
                                  0.0f, speed, 1, count, spread, 0);
            if (noChildren) {
                spawnProjectileSpread(5, 0, enemy.x, enemy.y,
                                      normalizeAngle16((280 - timer) * step + 0x6000),
                                      0.0f, speed + 1.0, 1, count, spread, 0);
            }
        }
        return;
    }

    if (enemy.helperState == 5 && timer >= 160) {
        static constexpr std::array<int, 5> kCount{{7, 9, 11, 11, 13}};
        static constexpr std::array<double, 5> kSpeed{{4.5, 5.5, 6.5, 6.5, 7.5}};
        const int destroyed = std::clamp(4 - enemy.liveChildCount, 0, 4);
        const int count = kCount[static_cast<std::size_t>(difficulty)];
        const int period = (5 - destroyed) * 20;
        const double speed = kSpeed[static_cast<std::size_t>(difficulty)] + destroyed * 0.5;
        const auto aim = radiansToFixedAngleTrunc(
            std::atan2(static_cast<double>(player_.y - (enemy.y - 25.0f)),
                       static_cast<double>(player_.x - enemy.x)));
        const int jitter = enemy.liveChildCount == 0
                               ? static_cast<int>(stageScriptRandFromFrame(timer) % 6001u) - 3000
                               : 0;
        const auto shotAngle = normalizeAngle16(static_cast<int>(aim) + jitter);
        if ((timer - 160) % period == 0) {
            spawnProjectileSpread(2, 0, enemy.x, enemy.y, shotAngle, 0.0f, speed,
                                  1, count, 0x8000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(2, 0, enemy.x, enemy.y, shotAngle, 0.0f, speed + 1.8,
                                      1, count, 0x8000, 0);
            }
        }
        if (enemy.liveChildCount == 0 && timer >= 170 && (timer - 170) % 20 == 0) {
            spawnProjectileSpread(3, 0, enemy.x, enemy.y, shotAngle,
                                  0.0f, speed, 1, count, 0x8000, 0);
        }
    }
}

void StageRuntime::updateStage01BossChild(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawBodyThisFrame = true;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent != nullptr) {
        const float targetX = parent->x + enemy.originX;
        const float targetY = parent->y + enemy.originY;
        if (enemy.helperTimer == 0) {
            enemy.x = parent->x + enemy.originX * 3.0f;
            enemy.y = parent->y + enemy.originY * 3.0f;
            if (enemy.spawnType == 0x16) {
                enemy.secondaryAngle16 = enemy.originX > 0.0f ? 0xe000 : 0xa000;
            }
        }
        else {
            enemy.x += (targetX - enemy.x) / 30.0f;
            enemy.y += (targetY - enemy.y) / 30.0f;
        }
    }

    if (enemy.helperState == 0 && enemy.helperTimer == 60) {
        enemy.helperState = 1;
        enemy.helperTimer = 0;
        enemy.targetable = true;
    }
    if (parent != nullptr && enemy.helperState == 1) {
        emitStage01BossChildProjectiles(enemy, *parent);
    }

    const bool ownDeath = enemy.hp < 1;
    if (ownDeath) {
        spawnEnemyDeathRewardBurst(enemy, 1000);
        if (parent != nullptr) {
            spawnDelayedOwnerDamageNode(
                enemy.maxHp, parent->entityId, parent->spawnType,
                "S01 boss child delayed-damage node 0x153");
            parent->liveChildCount = std::max(0, parent->liveChildCount - 1);
        }
        enemy.active = false;
    }
    const bool ownerDeathVisual = parent == nullptr || parent->hp < 1 ||
                                  stage01BossCountdown_ < 1;
    if (ownerDeathVisual) {
        spawnEnemyDeathEffects(enemy, 1);
    }
    if (ownDeath || parent == nullptr || !parent->active || parent->hp < 1 ||
        stage01BossCountdown_ < 1 || stage01BossPhaseMode_ != 1 ||
        (parent->helperState != 3 && parent->helperState != 5)) {
        enemy.active = false;
    }
}

void StageRuntime::emitStage01BossChildProjectiles(StageEnemy& enemy, const StageEnemy& parent) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int parentTimer = parent.helperTimer;
    const float sourceY = enemy.y - 20.0f;

    if (enemy.spawnType == 0x15) {
        static constexpr std::array<int, 5> kPeriod{{150, 100, 80, 80, 60}};
        static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 7.0, 9.0, 11.0}};
        const int start = (enemy.childIndex + 9) * 10;
        const int period = kPeriod[static_cast<std::size_t>(difficulty)];
        if (parentTimer >= start) {
            const int local = (parentTimer - start) % period;
            if (local == 0) {
                enemy.targetAngle16 = radiansToFixedAngleTrunc(
                    std::atan2(static_cast<double>(player_.y - sourceY),
                               static_cast<double>(player_.x - enemy.x)));
            }
            if (local < 12 && local % 4 == 0) {
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(7, 0, enemy.x, sourceY, enemy.targetAngle16,
                                    10.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(7, 0, enemy.x, sourceY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 700),
                                        10.0f, speed - 1.4, 1, 0);
                    spawnProjectileNode(7, 0, enemy.x, sourceY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 700),
                                        10.0f, speed - 1.4, 1, 0);
                }
            }
        }
        return;
    }

    if (enemy.spawnType == 0x16) {
        static constexpr std::array<int, 5> kSpreadCount{{1, 1, 2, 2, 2}};
        static constexpr std::array<int, 5> kSpreadAngle{{0, 0, 1500, 2400, 3000}};
        static constexpr std::array<int, 5> kTripleCadence{{24, 11, 9, 9, 5}};
        static constexpr std::array<int, 5> kTripleStep{{100, 190, 160, 160, 370}};
        static constexpr std::array<double, 5> kTripleSpeed{{3.0, 4.0, 5.0, 5.0, 6.0}};
        if (parentTimer > 89 && parentTimer < 210) {
            const int turn = enemy.originX > 0.0f ? 200 : -200;
            enemy.secondaryAngle16 = normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + turn);
        }
        else if (parentTimer >= 210) {
            const auto aim = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - parent.y),
                           static_cast<double>(player_.x - parent.x)));
            enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, aim, 0x20);
            enemy.secondaryAngle16 = static_cast<std::uint16_t>(
                std::clamp(static_cast<int>(enemy.secondaryAngle16), 0x3060, 0x4fa0));
        }
        if (parentTimer > 89 && (parentTimer - 90) % 4 == 0) {
            spawnProjectileSpread(7, 0, enemy.x, sourceY, enemy.secondaryAngle16,
                                  10.0f, 10.0, 1,
                                  kSpreadCount[static_cast<std::size_t>(difficulty)],
                                  kSpreadAngle[static_cast<std::size_t>(difficulty)], 0);
        }
        const int cadence = kTripleCadence[static_cast<std::size_t>(difficulty)];
        if (parentTimer >= 380 && (parentTimer - 380) % cadence == 0) {
            const int sideStep = (enemy.originX > 0.0f ? -1 : 1) *
                                 kTripleStep[static_cast<std::size_t>(difficulty)];
            const double speed = kTripleSpeed[static_cast<std::size_t>(difficulty)];
            for (int i = 0; i < 3; ++i) {
                const auto angle = normalizeAngle16(i * 0x5555 + enemy.helperTimer * sideStep);
                spawnProjectileNode(8, 0, enemy.x, sourceY, angle, 10.0f, speed, 1, 0);
                if (difficulty > 2) {
                    spawnProjectileNode(8, 0, enemy.x, sourceY, angle, 10.0f, speed + 1.0, 1, 0);
                }
            }
        }
        return;
    }

    static constexpr std::array<int, 5> kPeriod{{200, 120, 100, 90, 80}};
    static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 7.0, 9.0, 11.0}};
    const int period = kPeriod[static_cast<std::size_t>(difficulty)];
    const int start = 210 + (enemy.childIndex - 1) * (period / 2);
    if (parentTimer >= start) {
        const int local = (parentTimer - start) % period;
        if (local == 0) {
            enemy.targetAngle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - sourceY),
                           static_cast<double>(player_.x - enemy.x)));
        }
        if (local < 24 && local % 4 == 0) {
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(0x0b, 0, enemy.x, sourceY, enemy.targetAngle16,
                                10.0f, speed, 1, 0);
            if (difficulty > 1) {
                spawnProjectileNode(0x0b, 0, enemy.x, sourceY,
                                    normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 3000),
                                    10.0f, speed - 0.2, 1, 0);
                spawnProjectileNode(0x0b, 0, enemy.x, sourceY,
                                    normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 3000),
                                    10.0f, speed - 0.2, 1, 0);
            }
        }
    }
}

void StageRuntime::updateStage02Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawHp = enemy.hp;

    // FUN_140009480 computes the steering angle before refreshing the global
    // target, so every 50-frame refresh intentionally has a one-frame delay.
    const auto steeringTarget = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(stage02BossTargetY_ - enemy.y),
        static_cast<double>(stage02BossTargetX_ - enemy.x)));
    if (frame_ % 50 == 0) {
        stage02BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
        const int targetBaseY = enemy.helperState == 3 ? 220 : 150;
        stage02BossTargetY_ = static_cast<float>(
            stageRandCoord(frame_ + (selectedStage_ - 1) * 0xde,
                           101, targetBaseY));
    }

    if (stage02BossPhaseMode_ == 1 &&
        (enemy.hp < 1 || stage02BossCountdown_ < 1)) {
        const bool countdownExpired = stage02BossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, stage02BossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        switch (stage02BossBreaksRemaining_) {
        case 4:
            enemy.helperState = 2;
            enemy.radius = 240;
            stage02BossPhaseMode_ = 2;
            break;
        case 3:
            enemy.helperState = 4;
            enemy.radius = 300;
            stage02BossPhaseMode_ = 2;
            break;
        case 2:
            enemy.helperState = 6;
            stage02BossPhaseMode_ = 2;
            break;
        case 1:
            enemy.helperState = 8;
            stage02BossPhaseMode_ = -1;
            break;
        default:
            break;
        }
        stage02BossBreaksRemaining_ = std::max(0, stage02BossBreaksRemaining_ - 1);
    }

    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawBodyThisFrame = true;
    const int timer = enemy.helperTimer;

    const auto steerTowardStageTarget = [&enemy, steeringTarget]() {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, steeringTarget, 0x200);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.x += std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        enemy.y += std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
    };
    const auto openPhase = [this, &enemy](int state, int hitPoints, int radius, int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.radius = radius;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        stage02BossMaxHp_ = hitPoints;
        stage02BossCountdown_ = 1800;
        stage02BossPhaseIndex_ = phaseIndex;
        stage02BossPhaseMode_ = 1;
    };

    switch (enemy.helperState) {
    case 0:
        if (timer < 180) {
            enemy.y = 900.0f + static_cast<float>(static_cast<int>(
                std::sin(static_cast<double>(timer) * kTau / 720.0) *
                static_cast<double>(enemy.originY - 900.0f)));
        }
        else if (timer < 191) {
            enemy.y = enemy.originY;
        }
        else {
            enemy.y += 0.1f;
        }
        if (timer == 210) {
            openPhase(1, 60000, 180, 0);
        }
        break;
    case 1:
        steerTowardStageTarget();
        emitStage02BossProjectiles(enemy);
        break;
    case 2:
        if (timer < 90) {
            enemy.y += static_cast<float>(timer) * 0.01f;
            spawnStage02DeathExplosionChain(enemy);
        }
        else if (timer >= 100) {
            if (timer == 100) {
                enemy.y += 160.0f;
            }
            steerTowardStageTarget();
            if (timer < 240) {
                enemy.y -= static_cast<float>(
                    1.0 - std::sin(static_cast<double>(timer - 100) * kTau / 560.0));
            }
        }
        if (timer == 180) {
            spawnStage02BossChild(enemy, 0x22, 0, 70.0f, -50.0f, 0x4000,
                                  "S02 FUN_140009480 state 2 type 0x22 child 0");
            spawnStage02BossChild(enemy, 0x22, 1, -70.0f, -50.0f, 0x4000,
                                  "S02 FUN_140009480 state 2 type 0x22 child 1");
            spawnStage02BossChild(enemy, 0x22, 2, 140.0f, -110.0f, 0x4000,
                                  "S02 FUN_140009480 state 2 type 0x22 child 2");
            spawnStage02BossChild(enemy, 0x22, 3, -140.0f, -110.0f, 0x4000,
                                  "S02 FUN_140009480 state 2 type 0x22 child 3");
        }
        if (timer == 240) {
            openPhase(3, 75000, 220, 1);
        }
        break;
    case 3:
        steerTowardStageTarget();
        break;
    case 4:
        if (timer < 120) {
            spawnStage02DeathExplosionChain(enemy);
            enemy.y += static_cast<float>(timer) * 0.02f;
        }
        else if (timer >= 130) {
            if (timer == 130) {
                enemy.y -= 160.0f;
            }
            steerTowardStageTarget();
        }
        if (timer == 380) {
            openPhase(5, 40000, 80, 2);
        }
        break;
    case 5:
        steerTowardStageTarget();
        if (timer == 10) {
            static constexpr std::array<int, 5> kChildCount{{3, 5, 7, 7, 9}};
            const int count = kChildCount[static_cast<std::size_t>(std::clamp(config_.difficulty, 0, 4))];
            for (int i = 0; i < count; ++i) {
                const auto orbitAngle = normalizeAngle16(
                    (kFixedAngleFullCircle / count) * i - 0x4000);
                spawnStage02BossChild(enemy, 0x23, i, 140.0f, 0.0f, orbitAngle,
                                      "S02 FUN_140009480 state 5 type 0x23 orbit child");
            }
        }
        emitStage02BossProjectiles(enemy);
        break;
    case 6:
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += 0.1f;
        if (timer == 180) {
            openPhase(7, 50000, 80, 3);
        }
        break;
    case 7:
        steerTowardStageTarget();
        emitStage02BossProjectiles(enemy);
        if (timer == 210) {
            for (int i = 0; i < 9; ++i) {
                const auto orbitAngle = normalizeAngle16(i * 0x1c71 - 0x4000);
                spawnStage02BossChild(enemy, 0x24, i, 120.0f, 0.0f, orbitAngle,
                                      "S02 FUN_140009480 state 7 type 0x24 orbit child");
            }
        }
        break;
    case 8:
        if (timer < 240) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 1) {
            stage02ClearStarted_ = true;
            player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
        }
        if (timer == 240) {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        }
        if (timer == 420) {
            stage02ClearTransition_ = true;
        }
        if (timer == 480) {
            stage02GateFlag_ = false;
            stage02ClearComplete_ = true;
            enemy.active = false;
        }
        if (timer < 240) {
            enemy.y += 0.2f;
        }
        break;
    default:
        break;
    }

    // FUN_140002260 submits the four countdown digits before decrementing the
    // shared counter. Preserve that visible value across the later draw pass.
    stage02BossCountdownDraw_ = stage02BossCountdown_;
    if (stage02BossPhaseMode_ == 1) {
        updateBossCountdownAudio(enemy.hp, stage02BossCountdown_);
        --stage02BossCountdown_;
    }
}

void StageRuntime::emitStage02BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - y), static_cast<double>(player_.x - x)));
    };

    if (enemy.helperState == 1 && timer >= 30) {
        const int q = (timer - 30) % 960;
        static constexpr std::array<float, 4> kSourceX{{70.0f, -70.0f, 140.0f, -140.0f}};
        static constexpr std::array<float, 4> kSourceY{{0.0f, 0.0f, -80.0f, -80.0f}};

        if (q < 300) {
            static constexpr std::array<int, 5> kPrimaryPeriod{{120, 90, 80, 70, 60}};
            static constexpr std::array<int, 5> kPrimaryBurst{{15, 24, 30, 30, 30}};
            static constexpr std::array<double, 5> kPrimarySpeed{{5.5, 7.0, 8.0, 9.0, 11.0}};
            static constexpr std::array<int, 5> kSideInterval{{18, 11, 9, 10, 9}};
            static constexpr std::array<double, 5> kSideSpeed{{4.0, 4.5, 5.5, 6.0, 7.5}};
            static constexpr std::array<int, 5> kSideCount{{3, 4, 5, 5, 6}};

            for (int source = 0; source < 4; ++source) {
                const float sourceX = enemy.x + kSourceX[static_cast<std::size_t>(source)];
                const float sourceY = enemy.y + kSourceY[static_cast<std::size_t>(source)];
                if (source < 2) {
                    const int period = kPrimaryPeriod[static_cast<std::size_t>(difficulty)];
                    const int start = period + 20;
                    if (q < start) {
                        continue;
                    }
                    const int phase = (q - start) % period;
                    std::uint16_t& cachedAim = source == 0 ? enemy.secondaryAngle16
                                                          : enemy.targetAngle16;
                    if (phase == 0) {
                        cachedAim = aimFrom(sourceX, sourceY);
                    }
                    if (phase < kPrimaryBurst[static_cast<std::size_t>(difficulty)] &&
                        phase % 3 == 0) {
                        const double speed = kPrimarySpeed[static_cast<std::size_t>(difficulty)];
                        spawnProjectileNode(3, 7, sourceX, sourceY, cachedAim,
                                            10.0f, speed, 1, 0);
                        if (difficulty >= 3) {
                            spawnProjectileNode(3, 7, sourceX, sourceY,
                                                normalizeAngle16(static_cast<int>(cachedAim) - 1400),
                                                10.0f, speed - 1.5, 1, 0);
                            spawnProjectileNode(3, 7, sourceX, sourceY,
                                                normalizeAngle16(static_cast<int>(cachedAim) + 1400),
                                                10.0f, speed - 1.5, 1, 0);
                        }
                    }
                    cachedAim = approachAngle16(cachedAim,
                                                aimFrom(sourceX, sourceY), 0x20);
                    continue;
                }

                const int interval = kSideInterval[static_cast<std::size_t>(difficulty)];
                const int stagger = source == 2 ? 0 : interval;
                if (q < stagger || (q - stagger) % (interval * 2) != 0) {
                    continue;
                }
                const int count = kSideCount[static_cast<std::size_t>(difficulty)];
                const int randomOffset =
                    static_cast<int>(stageScriptRandFromFrame(timer) % 14001u) - 7000;
                const auto aimed = aimFrom(sourceX, sourceY);
                const double speed = kSideSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(4, 0, sourceX, sourceY,
                                      normalizeAngle16(static_cast<int>(aimed) + randomOffset),
                                      0.0f, speed, 1, count, (count - 1) * 440, 0);
                if (difficulty >= 3) {
                    const int highCount = count - 2;
                    const int highSpread = (highCount - 1) * 440;
                    spawnProjectileSpread(4, 0, sourceX, sourceY,
                                          normalizeAngle16(static_cast<int>(aimed) + randomOffset - 2000),
                                          0.0f, speed, 1, highCount, highSpread, 0);
                    spawnProjectileSpread(4, 0, sourceX, sourceY,
                                          normalizeAngle16(static_cast<int>(aimed) + randomOffset - 12000),
                                          0.0f, speed, 1, highCount, highSpread, 0);
                }
            }
            return;
        }

        if (q >= 330 && q < 660) {
            static constexpr std::array<int, 5> kPeriod{{18, 9, 6, 5, 4}};
            static constexpr std::array<double, 5> kBaseSpeed{{2.5, 3.5, 4.0, 4.0, 5.5}};
            static constexpr std::array<int, 5> kAngleStep{{160, 250, 300, 300, 440}};
            static constexpr std::array<int, 4> kSourceOffset{{-3000, 3000, -9000, 9000}};
            const int local = q - 330;
            if (local % kPeriod[static_cast<std::size_t>(difficulty)] == 0) {
                const double speed = kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>(local) * 0.01;
                for (int source = 0; source < 4; ++source) {
                    const float sourceX = enemy.x + kSourceX[static_cast<std::size_t>(source)];
                    const float sourceY = enemy.y + kSourceY[static_cast<std::size_t>(source)];
                    const int rawAngle = local * kAngleStep[static_cast<std::size_t>(difficulty)] +
                                         kSourceOffset[static_cast<std::size_t>(source)];
                    spawnProjectileNode(9, 0, sourceX, sourceY, normalizeAngle16(rawAngle),
                                        10.0f, speed, 1, 0);
                    spawnProjectileNode(8, 0, sourceX, sourceY, normalizeAngle16(-rawAngle),
                                        10.0f, speed, 1, 0);
                    if (difficulty >= 3) {
                        spawnProjectileNode(9, 0, sourceX, sourceY, normalizeAngle16(rawAngle),
                                            10.0f, speed + 1.2, 1, 0);
                        spawnProjectileNode(8, 0, sourceX, sourceY, normalizeAngle16(-rawAngle),
                                            10.0f, speed + 1.2, 1, 0);
                    }
                }
            }
            return;
        }

        if (q >= 690 && q < 930) {
            static constexpr std::array<int, 5> kPeriod{{90, 60, 50, 40, 40}};
            static constexpr std::array<int, 5> kBurst{{20, 20, 30, 20, 30}};
            static constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.5, 7.0, 8.0}};
            static constexpr std::array<int, 4> kSourceOffset{{-1000, 1000, -2000, 2000}};
            const int local = q - 690;
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int phase = local % period;
            if (phase == 0) {
                enemy.secondaryAngle16 = aimFrom(enemy.x, 0.0f);
            }
            if (phase < kBurst[static_cast<std::size_t>(difficulty)] && phase % 4 == 0) {
                for (int source = difficulty == 0 ? 2 : 0; source < 4; ++source) {
                    const float sourceX = enemy.x + kSourceX[static_cast<std::size_t>(source)];
                    const float sourceY = enemy.y + kSourceY[static_cast<std::size_t>(source)];
                    const int center = static_cast<int>(enemy.secondaryAngle16) +
                                       kSourceOffset[static_cast<std::size_t>(source)];
                    const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                    for (int opposite = 0; opposite < 2; ++opposite) {
                        const int angle = center - opposite * 0x8000;
                        spawnProjectileNode(2, 0x17, sourceX, sourceY, normalizeAngle16(angle),
                                            10.0f, speed, 1, 0);
                        if (difficulty >= 3) {
                            spawnProjectileNode(2, 0x17, sourceX, sourceY,
                                                normalizeAngle16(angle + 2000),
                                                10.0f, speed, 1, 0);
                            spawnProjectileNode(2, 0x17, sourceX, sourceY,
                                                normalizeAngle16(angle - 2000),
                                                10.0f, speed, 1, 0);
                        }
                    }
                }
            }
        }
        return;
    }

    if (enemy.helperState == 5 && timer > 59) {
        static constexpr std::array<int, 5> kPeriod{{120, 80, 70, 60, 60}};
        static constexpr std::array<int, 5> kCount{{5, 7, 9, 7, 9}};
        static constexpr std::array<double, 5> kBaseSpeed{{4.5, 5.5, 7.0, 8.0, 9.0}};
        const int q = (timer - 60) % 480;
        if (q > 89 && q < 450) {
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int phase = (q - 90) % period;
            if (phase == 0) {
                enemy.secondaryAngle16 = aimFrom(enemy.x - 25.0f, enemy.y - 85.0f);
            }
            if (phase < 24 && phase % 3 == 0) {
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const double speed = kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>((q - 60) % period) * 0.07;
                spawnProjectileSpread(16, 0, enemy.x - 25.0f, enemy.y - 85.0f,
                                      enemy.secondaryAngle16, 10.0f, speed, 1,
                                      count, 0x8000, 0);
                if (difficulty >= 3) {
                    const int highCount = count - 1;
                    spawnProjectileSpread(16, 0, enemy.x - 25.0f, enemy.y - 85.0f,
                                          enemy.secondaryAngle16, 10.0f, speed - 1.4, 1,
                                          highCount, (0x8000 / highCount) * (highCount - 1), 0);
                }
            }
            enemy.secondaryAngle16 = approachAngle16(
                enemy.secondaryAngle16,
                aimFrom(enemy.x - 25.0f, enemy.y - 85.0f), 0x30);
        }
        return;
    }

    if (enemy.helperState == 7 && timer > 59) {
        static constexpr std::array<int, 5> kPeriod{{12, 9, 9, 10, 10}};
        static constexpr std::array<int, 5> kWidth{{4, 5, 5, 5, 6}};
        static constexpr std::array<int, 5> kCount{{1, 1, 2, 3, 3}};
        static constexpr std::array<double, 5> kSpeed{{3.0, 3.6, 4.0, 4.0, 5.0}};
        const int local = timer - 60;
        if (local % kPeriod[static_cast<std::size_t>(difficulty)] <
            kWidth[static_cast<std::size_t>(difficulty)]) {
            int angle = timer * 300 - 18000;
            if (local % 600 > 299) {
                angle = -0x4000 - angle;
            }
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(16, 8, enemy.x - 25.0f, enemy.y - 85.0f,
                                  normalizeAngle16(angle), 10.0f,
                                  kSpeed[static_cast<std::size_t>(difficulty)], 1,
                                  count, count * 9000, 0);
        }
    }
}

void StageRuntime::updateStage02BossChild(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.targetable = false;
    enemy.drawBodyThisFrame = true;
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != 0x139) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
        return;
    }
    if (!parent->active) {
        enemy.active = false;
        return;
    }

    const int timer = enemy.helperTimer;
    if (enemy.spawnType == 0x22) {
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY;
        if (enemy.helperState == 0 && timer == 50) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperState == 1) {
            emitStage02BossChildProjectiles(enemy, *parent);
        }
        const bool livePhaseEnded = parent->helperState == 3 &&
                                    (parent->hp < 1 || stage02BossCountdown_ < 1 ||
                                     stage02BossPhaseMode_ != 1);
        if (livePhaseEnded) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.active = false;
        }
        return;
    }

    const float orbitRadius = enemy.originX;
    if (enemy.helperState == 0) {
        const double entry = std::sin(static_cast<double>(timer) * kPi / 100.0);
        const int entryTurn = static_cast<int>(entry * 3000.0) - 3000;
        enemy.secondaryAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + entryTurn);
        const double radians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * orbitRadius * entry);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * orbitRadius * entry);
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + parent->helperTimer * 333);
        const int trailHandle = enemySmallFrames_.size() > 23 ? enemySmallFrames_[23] : -1;
        const double trailScale = 1.0 + 0.1 * std::sin(
            static_cast<double>(parent->helperTimer) * kTau / 44.0);
        spawnStageEffect(0x38, trailHandle, 100, 0x1c, enemy.x, enemy.y,
                         enemy.sourceAngle16, 0.0, trailScale, trailScale,
                         16, 0xff, 0xff, 0xff, 0x60);
        if (timer == 50) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
    }
    if (enemy.helperState == 1) {
        const int orbitDelta = enemy.spawnType == 0x23
                                   ? static_cast<int>(std::sin(static_cast<double>(enemy.helperTimer) *
                                                               kTau / 480.0) * 777.0)
                                   : static_cast<int>(std::sin(static_cast<double>(enemy.helperTimer) *
                                                               kTau / 240.0) * 400.0);
        enemy.secondaryAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + orbitDelta);
        const double radians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * orbitRadius);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * orbitRadius);
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + parent->helperTimer * 333);
        emitStage02BossChildProjectiles(enemy, *parent);
    }

    const int expectedParentState = enemy.spawnType == 0x23 ? 5 : 7;
    if (parent->helperState != expectedParentState || parent->hp < 1 ||
        stage02BossCountdown_ < 1 || stage02BossPhaseMode_ != 1) {
        if (parent->hp < 1 || stage02BossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 1);
        }
        enemy.active = false;
    }
}

void StageRuntime::emitStage02BossChildProjectiles(StageEnemy& enemy,
                                                    const StageEnemy& parent) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - y), static_cast<double>(player_.x - x)));
    };

    if (enemy.spawnType == 0x22) {
        if (timer < 20) {
            return;
        }
        static constexpr std::array<int, 5> kSpinPeriod{{24, 20, 18, 20, 20}};
        static constexpr std::array<int, 5> kSpinWidth{{6, 8, 10, 12, 12}};
        static constexpr std::array<int, 5> kCount{{2, 4, 5, 6, 7}};
        static constexpr std::array<double, 5> kSpinSpeed{{3.5, 4.5, 5.5, 6.0, 7.5}};
        static constexpr std::array<int, 5> kAimCadence{{120, 80, 60, 48, 48}};
        static constexpr std::array<double, 5> kAimSpeed{{5.0, 6.6, 8.0, 9.0, 11.0}};
        static constexpr std::array<int, 5> kRingPeriod{{90, 60, 40, 40, 36}};
        static constexpr std::array<int, 5> kRingCount{{15, 23, 27, 25, 27}};
        static constexpr std::array<int, 5> kAngleStep{{150, 180, 200, 200, 200}};
        const int q = (timer - 20) % 1200;
        const int index = enemy.childIndex & 3;
        if (q == 0) {
            enemy.secondaryAngle16 = normalizeAngle16(
                (kFixedAngleFullCircle /
                 (kCount[static_cast<std::size_t>(difficulty)] * 4)) * index);
        }
        const int direction = (index == 0 || index == 3) ? 1 : -1;
        enemy.secondaryAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) +
            direction * kAngleStep[static_cast<std::size_t>(difficulty)]);
        const float sourceY = enemy.y - 60.0f;

        const auto emitAimedBurst = [&](int start) {
            if (q < start || q >= start + 240) {
                return;
            }
            const int phase = (q - start) % kAimCadence[static_cast<std::size_t>(difficulty)];
            if (phase == 0) {
                enemy.targetAngle16 = aimFrom(enemy.x, sourceY);
            }
            if (phase < 24 && phase % 3 == 0) {
                const int visual = index < 2 ? 12 : 13;
                const double speed = kAimSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(visual, 0, enemy.x, sourceY, enemy.targetAngle16,
                                    10.0f, speed, 1, 0);
                if (difficulty >= 3) {
                    spawnProjectileNode(visual, 0, enemy.x, sourceY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 800),
                                        10.0f, speed, 1, 0);
                    spawnProjectileNode(visual, 0, enemy.x, sourceY,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 800),
                                        10.0f, speed, 1, 0);
                }
            }
        };
        const auto emitSpin = [&](int visual, int phase, int period, int width) {
            if (period <= 0 || width <= 0 || phase % period >= width ||
                (phase % period) % 2 != 0) {
                return;
            }
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const double speed = kSpinSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(visual, 0, enemy.x, sourceY, enemy.secondaryAngle16,
                                  0.0f, speed, 1, count, kFixedAngleFullCircle, 0);
            if (difficulty == 4) {
                spawnProjectileSpread(visual, 0, enemy.x, sourceY, enemy.secondaryAngle16,
                                      0.0f, speed + 0.8, 1, count,
                                      kFixedAngleFullCircle, 0);
            }
        };

        if (index < 2) {
            emitAimedBurst(60);
            if (q >= 330 && q < 630) {
                emitSpin(12, q - 330,
                         kSpinPeriod[static_cast<std::size_t>(difficulty)] - 2,
                         kSpinWidth[static_cast<std::size_t>(difficulty)] - 2);
            }
        }
        else {
            if (q < 300) {
                emitSpin(13, q,
                         kSpinPeriod[static_cast<std::size_t>(difficulty)],
                         kSpinWidth[static_cast<std::size_t>(difficulty)]);
            }
            emitAimedBurst(390);
        }

        const int ringPeriod = kRingPeriod[static_cast<std::size_t>(difficulty)];
        const int ringStart = 650 + ringPeriod * index;
        if (q >= ringStart && q <= 1149 &&
            (q - ringStart) % (ringPeriod * 4) == 0) {
            const int count = kRingCount[static_cast<std::size_t>(difficulty)];
            const auto aim = aimFrom(enemy.x, sourceY);
            const int movement = (index & 1) == 0 ? 0x18 : 0x19;
            spawnProjectileSpread(3, movement, enemy.x, sourceY, aim,
                                  10.0f, 7.0, 1, count, kFixedAngleFullCircle, 0);
            if (difficulty >= 3) {
                spawnProjectileSpread(3, movement, enemy.x, sourceY, aim,
                                      10.0f, 8.2, 1, count,
                                      kFixedAngleFullCircle, 0);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x23) {
        static constexpr std::array<int, 5> kPeriod{{9, 5, 5, 5, 4}};
        static constexpr std::array<double, 5> kSpeed{{4.0, 5.0, 6.0, 6.5, 7.5}};
        const int period = kPeriod[static_cast<std::size_t>(difficulty)];
        if (timer % 480 < 420 && timer % period == 0 &&
            distanceSquared(enemy.x, enemy.y, player_.x, player_.y) >= 80.0f * 80.0f) {
            const auto angle = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) - parent.helperTimer * 180);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(1, 0, enemy.x, enemy.y, angle, 10.0f, speed, 1, 0);
            if (difficulty >= 3) {
                spawnProjectileNode(1, 0, enemy.x, enemy.y, angle,
                                    10.0f, speed + 0.6, 1, 0);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x24 && timer >= 30) {
        static constexpr std::array<int, 5> kPeriod{{240, 210, 180, 180, 160}};
        static constexpr std::array<int, 5> kWidth{{16, 25, 32, 32, 32}};
        static constexpr std::array<double, 5> kBaseSpeed{{4.0, 5.0, 6.0, 6.0, 7.7}};
        const int local = (timer - 30) % kPeriod[static_cast<std::size_t>(difficulty)];
        const auto liveAim = aimFrom(enemy.x, enemy.y);
        if (local == 0) {
            enemy.targetAngle16 = liveAim;
        }
        if (local < kWidth[static_cast<std::size_t>(difficulty)] && local % 3 == 0) {
            spawnProjectileNode(11, 0, enemy.x, enemy.y, enemy.targetAngle16,
                                10.0f,
                                kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                                    static_cast<double>(local) * 0.2,
                                1, 0);
        }
        enemy.targetAngle16 = approachAngle16(enemy.targetAngle16, liveAim, 0x30);
    }
}

void StageRuntime::emitStage01Projectiles(StageEnemy& enemy, int activeAge) {
    if (enemy.spawnType == 0x0a) {
        // FUN_14007c9c0 fires visual selector 4 / movement id 0 from two side
        // mounts and one center mount. The center aim is captured at the start
        // of each interval, used for this volley, then approached by 0x40 only
        // on firing frames.
        if (enemy.helperState != 1 || enemy.age >= 300) {
            return;
        }
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int start = stage01Type0AShotStartFrame(difficulty);
        const int interval = stage01Type0AShotInterval(difficulty, selectedStage_);
        if (enemy.age < start || interval <= 0) {
            return;
        }
        const int local = (enemy.age - start) % interval;
        if (local > 0x13 || local % 3 != 0) {
            return;
        }

        const float sideY = enemy.y - 20.0f; // DAT_14053ac58
        const float centerY = enemy.y - 15.0f; // DAT_14053ac44
        const std::uint16_t currentAim = radiansToFixedAngleTrunc(
            std::atan2(static_cast<double>(player_.y - centerY),
                       static_cast<double>(player_.x - enemy.x)));
        if (local == 0) {
            enemy.secondaryAngle16 = currentAim;
        }
        const std::uint16_t centerAngle = enemy.secondaryAngle16;
        const float bulletSpeed = stage01Type0AProjectileSpeed(difficulty, selectedStage_);
        spawnProjectileNode(4, 0, enemy.x + 5.0f, sideY, centerAngle, 0.0f, bulletSpeed, 1, 0);
        spawnProjectileNode(4, 0, enemy.x - 5.0f, sideY, centerAngle, 0.0f, bulletSpeed, 1, 0);
        spawnProjectileNode(4, 0, enemy.x, centerY, centerAngle, 0.0f, bulletSpeed, 1, 0);
        if (difficulty > 2) {
            spawnProjectileNode(4, 0, enemy.x, centerY, centerAngle, 0.0f, bulletSpeed + 2.0, 1, 0);
        }
        if (difficulty > 3) {
            spawnProjectileNode(4, 0, enemy.x, centerY, normalizeAngle16(static_cast<int>(centerAngle) - 0x457), 0.0f, bulletSpeed, 1, 0);
            spawnProjectileNode(4, 0, enemy.x, centerY, normalizeAngle16(static_cast<int>(centerAngle) + 0x457), 0.0f, bulletSpeed, 1, 0);
        }
        enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, currentAim, 0x40);
        return;
    }

    if (enemy.spawnType == 0x0b) {
        // FUN_14007d4e0 emits from the pre-movement point after movement has
        // been committed to the entity. Five intervals form a cycle and only
        // the first three interval starts fire.
        const int timer = enemy.helperTimer;
        if (enemy.helperState != 1 || timer >= 200) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int start = stage01Type0BShotStartFrame(difficulty);
        const int interval = stage01Type0BShotInterval(difficulty, selectedStage_);
        if (timer < start || interval <= 0) return;
        const int local = (timer - start) % (interval * 5);
        if (local >= interval * 3 || local % interval != 0) return;

        const float shotX = enemy.originX;
        const float shotY = enemy.originY + 25.0f;
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        if (shotX < horizontalOrigin + 40.0f ||
            shotX > horizontalOrigin + 560.0f ||
            shotY < 40.0f || shotY > 680.0f) {
            return;
        }

        const auto rawAim = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - shotY),
            static_cast<double>(player_.x - shotX)));
        const std::uint16_t angle = normalizeAngle16(((static_cast<int>(rawAim) + 0x400) >> 11) * 0x800);
        const float speed = stage01Type0BProjectileSpeed(difficulty, selectedStage_);
        spawnProjectileNode(0, 0, shotX, shotY, angle, 0.0f, speed, 1, 0);
        if (difficulty > 2) {
            spawnProjectileNode(0, 0, shotX, shotY, angle, 0.0f, speed + 1.6, 1, 0);
        }
        return;
    }

    if (enemy.spawnType == 0x0c) {
        // FUN_14007dfb0 captures a separate post-movement aim for each mount
        // at the interval boundary, then emits every five frames for 40 frames.
        const int timer = enemy.helperTimer;
        if (enemy.helperState != 1 || timer >= 200) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        constexpr std::array<int, 5> kNormalStart{{30, 20, 12, 10, 10}};
        constexpr std::array<int, 5> kNormalInterval{{140, 100, 80, 80, 60}};
        const int normalStart = kNormalStart[static_cast<std::size_t>(difficulty)];
        const int normalInterval = kNormalInterval[static_cast<std::size_t>(difficulty)];
        const int speedPhase = (timer - normalStart) % normalInterval;
        const int start = stage01Type0CShotStartFrame(difficulty, selectedStage_);
        const int interval = stage01Type0CShotInterval(difficulty, selectedStage_);
        if (timer < start || interval <= 0) return;
        const int local = (timer - start) % interval;
        const float leftX = enemy.x - 25.0f;
        const float rightX = enemy.x + 25.0f;
        const float y = enemy.y;
        if (local == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - y),
                static_cast<double>(player_.x - rightX)));
            enemy.targetAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - y),
                static_cast<double>(player_.x - leftX)));
        }
        if (local >= 40 || local % 5 != 0) return;

        const double speed = stage01Type0CProjectileSpeed(difficulty, selectedStage_) +
                             static_cast<double>(speedPhase) * 0.02;
        spawnProjectileNode(7, 0, rightX, y, enemy.secondaryAngle16, 10.0f, speed, 1, 0);
        spawnProjectileNode(7, 0, leftX, y, enemy.targetAngle16, 10.0f, speed, 1, 0);
        if (difficulty > 2) {
            spawnProjectileNode(7, 0, rightX, y,
                                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 700),
                                10.0f, speed - 0.8, 1, 0);
            spawnProjectileNode(7, 0, leftX, y,
                                normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 700),
                                10.0f, speed - 0.8, 1, 0);
        }
        return;
    }

    if (enemy.spawnType == 0x0d) {
        // FUN_14007ea30 fires after its anchor movement. The side decision uses
        // the angle cached at helper entry, which differs from sourceAngle16 on
        // the state-0 -> state-1 transition call.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int interval = stage01Type0DShotInterval(difficulty, selectedStage_);
        if (frame_ < 0 || interval <= 0 || frame_ % interval != 0) return;

        const bool cachedAngleBelowC000 = enemy.secondaryAngle16 < 0xc000;
        const float shotX = enemy.x + (cachedAngleBelowC000 ? -40.0f : 40.0f);
        const float shotY = enemy.y - 12.0f;
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        if (shotX < horizontalOrigin + 40.0f ||
            shotX > horizontalOrigin + 560.0f ||
            shotY < 40.0f || shotY > 680.0f ||
            distanceSquared(shotX, shotY, player_.x, player_.y) < 2500.0f) {
            return;
        }

        const auto rawAim = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - (enemy.y + 25.0f)),
            static_cast<double>(player_.x - enemy.x)));
        const auto angle16 = normalizeAngle16(
            ((static_cast<int>(rawAim) + 0x400) >> 11) * 0x800);
        const float speed = stage01Type0DProjectileSpeed(difficulty, selectedStage_);
        spawnProjectileNode(0, 0, shotX, shotY, angle16, 0.0f, speed, 1, 0);
        spawnProjectileNode(0, 0, shotX, shotY, angle16, 10.0f, speed, 1, 0);
        return;
    }

    if (enemy.spawnType == 0x0e) {
        // FUN_14007f2c0 fires after movement from two side mounts, then from
        // the center. The side aim is cached only at each window boundary.
        if (enemy.helperState != 1) {
            return;
        }
        const int timer = enemy.helperTimer;
        if (timer < 0x18 || timer >= 0x12c) {
            return;
        }

        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        constexpr std::array<double, 5> kSpeed{{6.0, 7.5, 8.5, 9.0, 11.0}};
        constexpr std::array<int, 5> kSideSpread{{0, 0, 0x708, 0xce4, 0x9c4}};
        constexpr std::array<int, 5> kCenterInterval{{0x28, 0x1e, 0x1e, 0x0f, 0x0f}};
        constexpr std::array<int, 5> kCenterCount{{4, 6, 10, 12, 13}};
        constexpr double kOriginalPi = 3.14159265358979;
        constexpr double kBodyWave = 2.0 * kOriginalPi / 63.0;

        const int cycle = (timer - 0x18) % 0x96;
        const float middleYOffset = static_cast<float>(
            2.0 * std::sin(static_cast<double>(timer - 23) * kBodyWave));
        const float sideY = enemy.y + 15.0f + middleYOffset;
        const double speed = kSpeed[static_cast<std::size_t>(difficulty)];

        auto emitSideWindow = [&](float sourceX, std::uint16_t cachedAim) {
            spawnProjectileNode(9, 0, sourceX, sideY, cachedAim,
                                10.0f, speed, 1, 0);
            if (difficulty > 1) {
                spawnProjectileSpread(9, 0, sourceX, sideY, cachedAim,
                                      10.0f, speed - 1.0, 1, 2,
                                      kSideSpread[static_cast<std::size_t>(difficulty)], 0);
            }
            if (difficulty > 3) {
                spawnProjectileSpread(9, 0, sourceX, sideY, cachedAim,
                                      10.0f, speed - 2.0, 1, 2,
                                      kSideSpread[static_cast<std::size_t>(difficulty)] * 2, 0);
            }
        };

        if (cycle == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - sideY),
                           static_cast<double>(player_.x - (enemy.x + 55.0f))));
        }
        if (cycle < 0x1e && cycle % 5 == 0) {
            emitSideWindow(enemy.x + 55.0f, enemy.secondaryAngle16);
            return;
        }
        if (cycle == 0x28) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - sideY),
                           static_cast<double>(player_.x - (enemy.x - 55.0f))));
        }
        if (cycle >= 0x28 && cycle < 0x46 && (cycle - 0x28) % 5 == 0) {
            emitSideWindow(enemy.x - 55.0f, enemy.secondaryAngle16);
            return;
        }
        if (cycle >= 0x50 && cycle < 0x78 &&
            (cycle - 0x50) % kCenterInterval[static_cast<std::size_t>(difficulty)] == 0) {
            const float centerY = enemy.y + static_cast<float>(
                2.0 * std::sin(static_cast<double>(timer) * kBodyWave) - 24.0);
            const auto aim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - centerY),
                static_cast<double>(player_.x - enemy.x)));
            const int count = kCenterCount[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(0, 0, enemy.x, centerY,
                                  normalizeAngle16(static_cast<int>(aim) + 200),
                                  0.0f, speed - 2.5, 1, count, 28000, 0);
            spawnProjectileSpread(0, 0, enemy.x, centerY,
                                  normalizeAngle16(static_cast<int>(aim) - 200),
                                  0.0f, speed - 2.5, 1, count, 28000, 0);
        }
        return;
    }

    if (enemy.spawnType == 0x0f) {
        // FUN_140080170 alternates visual selectors 5 and 1 from its two
        // moving mounts, then emits a six-layer difficulty-scaled center fan.
        if (enemy.helperState != 1) {
            return;
        }
        const int timer = enemy.helperTimer;
        if (timer < 0x28 || timer >= 300) {
            return;
        }

        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        constexpr std::array<int, 5> kPeriod{{200, 120, 100, 90, 90}};
        constexpr std::array<int, 5> kActiveWindow{{30, 40, 50, 50, 50}};
        constexpr std::array<int, 5> kJitter{{800, 1200, 1800, 2400, 3000}};
        constexpr std::array<double, 5> kEarlyStageSpeed{{4.0, 5.5, 6.0, 7.0, 8.5}};
        constexpr std::array<double, 5> kLateStageSpeed{{5.5, 6.5, 7.0, 7.0, 8.5}};
        constexpr std::array<double, 5> kEarlyStageFanSpeed{{3.5, 4.5, 5.5, 6.0, 7.5}};
        constexpr std::array<double, 5> kLateStageFanSpeed{{4.5, 5.5, 6.0, 6.0, 7.5}};
        constexpr std::array<int, 5> kFanCount{{5, 11, 15, 17, 19}};
        constexpr double kOriginalPi = 3.14159265358979;

        const auto tableIndex = static_cast<std::size_t>(difficulty);
        const int cycle = (timer - 0x28) % kPeriod[tableIndex];
        const double bodyWave = std::sin(static_cast<double>(timer) * kOriginalPi / 36.0);
        const double mountWave = std::sin(static_cast<double>(timer) * kOriginalPi / 50.0);
        const auto mountAngle = normalizeAngle16(static_cast<int>(mountWave * 2000.0));
        const double mountRadians = fixedAngleToRadiansDouble(mountAngle);
        const float mountX = static_cast<float>(std::cos(mountRadians) * 95.0);
        const float mountY = static_cast<float>(std::sin(mountRadians) * 95.0);
        const float shiftedBodyWave = static_cast<float>(
            std::sin(static_cast<double>(timer - 17) * kOriginalPi / 36.0));
        const float rightX = enemy.x + mountX + 10.0f;
        const float leftX = enemy.x - mountX - 10.0f;
        const float sideY = enemy.y + shiftedBodyWave + mountY - 15.0f;

        if (cycle == 0) {
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - sideY),
                static_cast<double>(player_.x - rightX)));
            enemy.targetAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - sideY),
                static_cast<double>(player_.x - leftX)));
        }

        if (cycle < kActiveWindow[tableIndex]) {
            const std::uint32_t jitterSeed =
                static_cast<std::uint32_t>(frame_) * 0x6fu +
                static_cast<std::uint32_t>(timer);
            const int jitter = stageRandomIntInclusive(
                jitterSeed, -kJitter[tableIndex], kJitter[tableIndex]);
            const int visualSelector = (cycle & 1) == 0 ? 5 : 1;
            const double baseSpeed = selectedStage_ > 4
                                         ? kLateStageSpeed[tableIndex]
                                         : kEarlyStageSpeed[tableIndex];
            const double speed = baseSpeed + static_cast<double>(cycle) * 0.1;
            spawnProjectileNode(visualSelector, 0, rightX, sideY,
                                normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + jitter),
                                0.0f, speed, 1, 0);
            spawnProjectileNode(visualSelector, 0, leftX, sideY,
                                normalizeAngle16(static_cast<int>(enemy.targetAngle16) + jitter),
                                0.0f, speed, 1, 0);
        }

        if (cycle == 0x41) {
            const float centerY = enemy.y + static_cast<float>(bodyWave) - 30.0f;
            const auto centerAim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - centerY),
                static_cast<double>(player_.x - enemy.x)));
            const int count = kFanCount[tableIndex];
            const int spread = (count - 1) * 0xf0;
            const double speed = selectedStage_ > 4
                                     ? kLateStageFanSpeed[tableIndex]
                                     : kEarlyStageFanSpeed[tableIndex];
            const auto emitFanLayer = [&](double layerSpeed) {
                spawnProjectileSpread(4, 0, enemy.x, centerY, centerAim,
                                      0.0f, layerSpeed, 1, count, spread, 0);
                if (difficulty > 0) {
                    spawnProjectileSpread(4, 0, enemy.x, centerY,
                                          normalizeAngle16(static_cast<int>(centerAim) + 10000),
                                          0.0f, layerSpeed, 1, count, spread, 0);
                    spawnProjectileSpread(4, 0, enemy.x, centerY,
                                          normalizeAngle16(static_cast<int>(centerAim) - 10000),
                                          0.0f, layerSpeed, 1, count, spread, 0);
                }
            };
            emitFanLayer(speed);
            if (difficulty > 2) {
                emitFanLayer(speed + 1.2);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x10) {
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int timer = enemy.helperTimer;

        constexpr std::array<int, 5> kFirstInterval{{120, 60, 60, 60, 60}};
        constexpr std::array<int, 5> kFirstCount{{1, 3, 5, 5, 7}};
        constexpr std::array<int, 5> kLateStageFirstCount{{3, 5, 7, 5, 7}};
        constexpr std::array<double, 5> kFirstSpeed{{3.0, 4.0, 5.0, 6.0, 7.0}};
        constexpr std::array<double, 5> kLateStageFirstSpeed{{4.5, 5.5, 6.0, 7.0, 7.0}};
        constexpr std::array<int, 5> kSecondInterval{{100, 80, 70, 60, 50}};
        constexpr std::array<int, 5> kSecondCount{{5, 7, 9, 9, 11}};
        constexpr std::array<double, 5> kSecondSpeed{{3.0, 4.0, 5.0, 5.0, 6.5}};

        const std::size_t table = static_cast<std::size_t>(difficulty);
        const float fireX = enemy.x;
        // FUN_140080fb0 uses the global-frame 68-tick body wave for the
        // projectile mount: y + 3*sin(frame*pi/34) - 24 - 35.
        const float fireY = enemy.y + static_cast<float>(
            std::sin(static_cast<double>(frame_) *
                     3.14159265358979323846 / 34.0) * 3.0) - 59.0f;
        const auto aimed = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));

        if (timer >= 0x1e && timer - 0x1e < 0x10e) {
            const int phase = timer - 0x1e;
            const int interval = kFirstInterval[table];
            const int local = phase % interval;
            if (local == 0) enemy.secondaryAngle16 = aimed;
            if (local < 20 && local % 3 == 0) {
                const bool lateStageVariant = selectedStage_ > 7;
                int count = (lateStageVariant ? kLateStageFirstCount : kFirstCount)[table];
                if (timer > 0xef) count += 2;
                const double speed =
                    (lateStageVariant ? kLateStageFirstSpeed : kFirstSpeed)[table] +
                    timer * 0.01;
                spawnProjectileSpread(0, 0, fireX, fireY,
                                      enemy.secondaryAngle16, 0.0f, speed,
                                      1, count, 18000, 0);
                if (difficulty > 2 && count > 1) {
                    spawnProjectileSpread(
                        0, 0, fireX, fireY, enemy.secondaryAngle16,
                        0.0f, speed - 2.4, 1, count - 1,
                        (18000 / (count - 1)) * (count - 2), 0);
                }
                enemy.secondaryAngle16 = approachAngle16(
                    enemy.secondaryAngle16, aimed, 0x40);
            }
        }

        if (timer >= 0x1a4 && timer - 0x1a4 < 0x1e0 &&
            (timer - 0x1a4) % kSecondInterval[table] == 0) {
            const int volley =
                (timer - 0x1a4) / kSecondInterval[table];
            const int count = kSecondCount[table] + volley * 2;
            const double speed =
                kSecondSpeed[table] + (timer - 0x1a4) * 0.007;
            spawnProjectileSpread(2, 0, fireX, fireY, aimed,
                                  0.0f, speed, 1, count, 0x8000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(2, 0, fireX, fireY, aimed,
                                      0.0f, speed + 2.0, 1,
                                      count, 0x8000, 0);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x11) {
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int stateAge = enemy.age;
        constexpr std::array<int, 5> kEarlyInterval{{60, 32, 24, 20, 16}};
        constexpr std::array<double, 5> kEarlySpeed{{3.5, 4.5, 5.0, 5.0, 6.5}};
        constexpr std::array<int, 5> kLateInterval{{100, 80, 70, 60, 50}};
        constexpr std::array<int, 5> kLateLayers{{1, 1, 2, 3, 3}};
        constexpr std::array<double, 5> kLateSpeed{{3.0, 5.0, 6.0, 7.0, 8.5}};
        const std::size_t table = static_cast<std::size_t>(difficulty);
        const double sourceRadians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        const float fireX = enemy.x +
            static_cast<float>(std::cos(sourceRadians) * 70.0);
        const float fireY = enemy.y +
            static_cast<float>(std::sin(sourceRadians) * 70.0);

        if (stateAge < 300 && stateAge % kEarlyInterval[table] == 0) {
            const int extent = stateAge * 0x10;
            const int jitter = stageRandomIntInclusive(
                static_cast<std::uint32_t>(stateAge), -extent, extent);
            const auto angle = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) + jitter);
            const double baseSpeed = kEarlySpeed[table];
            spawnProjectileNode(7, 0, fireX, fireY, angle,
                                10.0f, baseSpeed, 1, 0);
            spawnProjectileNode(7, 0, fireX, fireY, angle,
                                10.0f, baseSpeed + 0.3, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(7, 0, fireX, fireY, angle,
                                    10.0f, baseSpeed + 2.0, 1, 0);
                spawnProjectileNode(7, 0, fireX, fireY, angle,
                                    10.0f, baseSpeed + 2.3, 1, 0);
            }
        }

        const int lateAge = stateAge - 0x186;
        if (lateAge >= 0 && lateAge < 0x1fe) {
            const int local = lateAge % kLateInterval[table];
            if (local < 0x19 && local % 3 == 0) {
                for (int layer = 0; layer < kLateLayers[table]; ++layer) {
                    spawnProjectileSpread(
                        9, 0, fireX, fireY, enemy.sourceAngle16,
                        10.0f,
                        kLateSpeed[table] + local * 0.2 - layer * 0.4,
                        1, 2, layer * 1000, 0);
                }
            }
        }
        return;
    }

    if (enemy.spawnType >= 0x06 && enemy.spawnType <= 0x08) {
        // FUN_140082d90 emits after movement from the y+75 mount, using the
        // pre-movement aim cached and turned by updateStage01Marker().
        if (enemy.helperState != 1) {
            return;
        }
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        constexpr std::array<int, 5> kStart{{40, 30, 30, 30, 30}};
        constexpr std::array<int, 5> kCycle{{100, 80, 60, 60, 50}};
        constexpr std::array<int, 5> kCount{{1, 3, 5, 5, 7}};
        const std::size_t table = static_cast<std::size_t>(difficulty);
        const int timer = enemy.helperTimer;
        if (timer < kStart[table] || timer >= 0xf0) {
            return;
        }
        const int local = (timer - kStart[table]) % kCycle[table];
        if (local >= 0x1e || local % 5 != 0) {
            return;
        }
        const double speed = stage01MarkerProjectileSpeed(difficulty) +
                             static_cast<double>(local) * 0.05;
        spawnProjectileSpread(0, 0, enemy.x, enemy.y + 75.0f,
                              enemy.secondaryAngle16, 0.0f, speed, 1,
                              kCount[table], 20000, 0);
        if (difficulty > 2) {
            spawnProjectileSpread(0, 0, enemy.x, enemy.y + 75.0f,
                                  enemy.secondaryAngle16, 0.0f,
                                  speed - 2.0, 1, kCount[table], 20000, 0);
        }
        return;
    }

    // Every observed Stage 1 firing helper returns through a dedicated branch.
    (void)activeAge;
}

void StageRuntime::updateStage04Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;

    // FUN_140014bf0 caches the steering heading before refreshing its shared
    // 50-frame destination.
    const auto steeringTarget = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(stage04BossTargetY_ - enemy.y),
        static_cast<double>(stage04BossTargetX_ - enemy.x)));

    if (stage04BossPhaseMode_ == 1 &&
        (enemy.hp < 1 || stage04BossCountdown_ < 1)) {
        const bool countdownExpired = stage04BossCountdown_ < 1;
        if (countdownExpired) {
            flushEnemyProjectilesToEffects();
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 100);
        }
        else {
            spawnPlayerSideObject(0x18, enemy.x, enemy.y,
                                  0.0, 0, 0, 0.0f);
        }
        spawnBossPhaseBreakFeedback(enemy, stage04BossCountdown_);
        spawnPostDeathCounterEntity(enemy, 140.0);
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperTimer = 0;
        enemy.liveChildCount = 0;
        switch (stage04BossBreaksRemaining_) {
        case 4:
            enemy.helperState = 2;
            enemy.radius = 240;
            stage04BossPhaseMode_ = 2;
            break;
        case 3:
            enemy.helperState = 6;
            stage04BossPhaseMode_ = 2;
            break;
        case 2:
            enemy.helperState = 8;
            stage04BossPhaseMode_ = 2;
            break;
        case 1:
            enemy.helperState = 11;
            stage04BossPhaseMode_ = -1;
            break;
        default:
            break;
        }
        stage04BossBreaksRemaining_ = std::max(0, stage04BossBreaksRemaining_ - 1);
    }

    if (frame_ % 50 == 0) {
        if (enemy.helperState == 1) {
            stage04BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 201, 260));
            stage04BossTargetY_ = static_cast<float>(
                stageRandCoord((selectedStage_ - 1) * 444 + frame_, 121, 60));
        }
        else {
            stage04BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
            stage04BossTargetY_ = static_cast<float>(
                stageRandCoord((selectedStage_ - 1) * 444 + frame_, 101, 150));
        }
    }

    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;

    const auto steerTowardSharedTarget = [&enemy, steeringTarget]() {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              steeringTarget, 0x200);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.x += std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        enemy.y += std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
    };
    const auto openPhase = [this, &enemy](int state, int hitPoints,
                                          int countdown, int radius,
                                          int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.radius = radius;
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        stage04BossMaxHp_ = hitPoints;
        stage04BossCountdown_ = countdown;
        stage04BossPhaseIndex_ = phaseIndex;
        stage04BossPhaseMode_ = 1;
    };

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0:
        if (timer == 0) {
            playPlayerSound(bossSe8SoundHandle_, 0x19);
        }
        if (timer == 20 || timer == 26 || timer == 32 || timer == 38) {
            playPlayerSound(bossLifeSoundHandle_, 0x14);
        }
        enemy.x = 360.0f;
        if (timer <= 240) {
            enemy.y = 120.0f + 500.0f - static_cast<float>(static_cast<int>(
                std::sin(static_cast<double>(timer) * kPi / 480.0) * 500.0));
        }
        if (timer == 180) {
            static constexpr std::array<float, 6> kOffsetX{{
                60.0f, -60.0f, 150.0f, -150.0f, 230.0f, -230.0f,
            }};
            static constexpr std::array<float, 6> kOffsetY{{
                260.0f, 260.0f, 230.0f, 230.0f, 170.0f, 170.0f,
            }};
            for (int i = 0; i < 6; ++i) {
                spawnStage04BossChild(
                    enemy, 0x40, i, kOffsetX[static_cast<std::size_t>(i)],
                    kOffsetY[static_cast<std::size_t>(i)], 12000, 15, 1.0, 30,
                    0x4000, "S04 FUN_140014bf0 initial appendage 0x40");
            }
        }
        if (timer == 240) {
            openPhase(1, 195000, 4500, 200, 0);
        }
        break;
    case 1:
        steerTowardSharedTarget();
        emitStage04BossProjectiles(enemy);
        if (timer == 3420) {
            enemy.helperTimer = 0;
        }
        break;
    case 2:
        if (timer < 120) {
            enemy.y += static_cast<float>(timer) * 0.02f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer >= 130) {
            steerTowardSharedTarget();
        }
        if (timer == 120) {
            playPlayerSound(blast2SoundHandle_, 0x19);
        }
        if (timer == 260 || timer == 284) {
            playPlayerSound(bossApproachSoundHandle_, 0x19);
        }
        if (timer == 380) {
            openPhase(3, 45000, 1800, 80, 1);
        }
        break;
    case 3:
        steerTowardSharedTarget();
        if (timer == 10) {
            playPlayerSound(bossSe1SoundHandle_, 0x19);
            const int difficulty = std::clamp(config_.difficulty, 0, 4);
            static constexpr std::array<int, 5> kCount{{7, 9, 11, 11, 13}};
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            for (int i = 0; i < count; ++i) {
                const auto angle = normalizeAngle16(
                    i * (kFixedAngleFullCircle / count) - 0x4000);
                spawnStage04BossChild(
                    enemy, 0x41, i, 100.0f, 200.0f, 99999999, 10, 0.0,
                    30, angle, "S04 FUN_140014bf0 orbit satellite 0x41");
            }
        }
        if (timer == 150) {
            enemy.helperState = 4;
            enemy.helperTimer = 0;
        }
        break;
    case 4:
    case 9: {
        const int duration = enemy.helperState == 4 ? 60 : 40;
        if (timer == 1) {
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
            if (enemy.helperState == 4) {
                const std::uint32_t random = stageScriptRandFromFrame(frame_);
                const float distance = static_cast<float>(random % 41u + 80u);
                float targetX = (random & 1u) == 0u
                                    ? enemy.x + distance
                                    : enemy.x - distance;
                if (targetX > 520.0f) targetX = enemy.x - distance;
                if (targetX < 200.0f) targetX = enemy.x + distance;
                enemy.markerDrawX = targetX;
                enemy.markerDrawY = static_cast<float>(
                    stageRandCoord(frame_ + 444, 101, 150));
            }
            else {
                enemy.markerDrawX = 440.0f;
                enemy.markerDrawY = 150.0f;
                spawnStageEffect(0x2d, -1, 0, 0x28,
                                 0.0f, 0.0f, 0, 1.0, 1.0, 1.0, 60,
                                 0xff, 0xff, 0xff, 0xff, enemy.entityId);
            }
        }
        const double ease = std::sin(static_cast<double>(timer) * kPi /
                                     static_cast<double>(duration * 2));
        enemy.x = enemy.originX +
                  static_cast<float>(ease * (enemy.markerDrawX - enemy.originX));
        enemy.y = enemy.originY +
                  static_cast<float>(ease * (enemy.markerDrawY - enemy.originY));
        if (timer == duration) {
            enemy.x = enemy.markerDrawX;
            enemy.y = enemy.markerDrawY;
            enemy.helperState = enemy.helperState + 1;
            enemy.helperTimer = 0;
        }
        break;
    }
    case 5:
        steerTowardSharedTarget();
        if (timer == 90) {
            enemy.helperState = 4;
            enemy.helperTimer = 0;
        }
        break;
    case 6:
    case 8:
        if (timer == 1) {
            playPlayerSound(enemyDown3SoundHandle_, 0x19);
        }
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += 0.1f;
        if (timer == 180) {
            if (enemy.helperState == 6) {
                openPhase(7, 58000, 1800, enemy.radius, 2);
            }
            else {
                openPhase(9, 70000, 2100, enemy.radius, 3);
            }
        }
        break;
    case 7:
        steerTowardSharedTarget();
        if (timer == 10) {
            playPlayerSound(bossSe1SoundHandle_, 0x19);
            for (int i = 0; i < 3; ++i) {
                spawnStage04BossChild(
                    enemy, 0x42, i, 180.0f, 0.0f, enemy.maxHp, 10, 0.0, 50,
                    normalizeAngle16(i * 0x5555 - 0x4000),
                    "S04 FUN_140014bf0 shared-HP satellite 0x42");
            }
        }
        emitStage04BossProjectiles(enemy);
        break;
    case 10: {
        const double amplitude = timer < 777
                                     ? 80.0 + 120.0 * std::sin(
                                           static_cast<double>(timer) * kPi / 1554.0)
                                     : 200.0;
        enemy.x = 360.0f + static_cast<float>(
            amplitude * std::sin(static_cast<double>(timer + 91) * kPi / 182.0));
        enemy.y = 200.0f - static_cast<float>(
            50.0 * std::sin(static_cast<double>(timer + 120) * kPi / 240.0));
        if (timer == 300) {
            playPlayerSound(bossSe1SoundHandle_, 0x19);
            for (int i = 0; i < 3; ++i) {
                spawnStage04BossChild(
                    enemy, 0x43, i, 130.0f, 0.0f, enemy.maxHp, 10, 0.0, 50,
                    normalizeAngle16(i * 0x5555 - 0x4000),
                    "S04 FUN_140014bf0 shared-HP satellite 0x43");
            }
        }
        emitStage04BossProjectiles(enemy);
        break;
    }
    case 11:
        if (timer < 240) {
            enemy.y += 0.2f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 1) {
            stage04ClearStarted_ = true;
            player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
        }
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        }
        if (timer == 420) {
            stage04ClearTransition_ = true;
        }
        if (timer >= 360 && timer <= 480 &&
            (config_.routeMode == 0 || config_.routeMode == 2) &&
            stage04BossBgmHandle_ != -1) {
            const double fade = 1.0 - std::sin(
                static_cast<double>(timer - 360) * kPi / 240.0);
            ChangeVolumeSoundMem(static_cast<int>(
                                     static_cast<double>(config_.bgmVolume) *
                                     25.5 * fade),
                                 stage04BossBgmHandle_);
        }
        if (timer == 480) {
            stage04GateFlag_ = false;
            stage04ClearComplete_ = true;
            enemy.active = false;
        }
        break;
    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    stage04BossCountdownDraw_ = stage04BossCountdown_;
    if (stage04BossPhaseMode_ == 1) {
        updateBossCountdownAudio(enemy.hp, stage04BossCountdown_);
        --stage04BossCountdown_;
    }
}

void StageRuntime::emitStage04BossProjectiles(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int timer = enemy.helperTimer;
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };

    if (enemy.helperState == 1 && timer >= 64) {
        static constexpr std::array<int, 5> kInterval{{200, 160, 160, 160, 120}};
        static constexpr std::array<int, 5> kMaximum{{11, 17, 20, 20, 20}};
        static constexpr std::array<double, 5> kBaseSpeed{{4.0, 5.0, 5.5, 6.0, 7.2}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        if ((timer - 64) % interval == 0) {
            playPlayerSound(bullet2SoundHandle_, 0x13);
            const int maximum = kMaximum[static_cast<std::size_t>(difficulty)];
            const double baseSpeed = kBaseSpeed[static_cast<std::size_t>(difficulty)];
            const auto aimed = aimFrom(enemy.x, enemy.y);
            for (int i = 0; i <= maximum; ++i) {
                const int spread = i * (kFixedAngleFullCircle / maximum);
                const double speed = baseSpeed -
                    static_cast<double>(i) * (baseSpeed - 1.0) /
                        static_cast<double>(maximum);
                spawnProjectileSpread(10, 0, enemy.x, enemy.y, aimed, 10.0f,
                                      speed, 1, 2, spread, 0);
                if (difficulty >= 3 && i < maximum) {
                    const double secondSpeed = baseSpeed - 1.0 -
                        static_cast<double>(i) * (baseSpeed - 2.4) /
                            static_cast<double>(maximum);
                    spawnProjectileSpread(10, 0, enemy.x, enemy.y, aimed, 10.0f,
                                          secondSpeed, 1, 2, spread + 1500, 0);
                }
            }
        }
        return;
    }

    const float sourceX = enemy.x;
    const float sourceY = enemy.y - 60.0f;
    if (enemy.helperState == 7) {
        static constexpr std::array<int, 5> kInterval{{28, 24, 20, 20, 16}};
        static constexpr std::array<int, 5> kCount{{4, 7, 7, 7, 7}};
        static constexpr std::array<int, 5> kExtraPairs{{2, 2, 3, 4, 4}};
        static constexpr std::array<double, 5> kSpeed{{4.5, 6.0, 6.5, 7.0, 8.5}};
        const int p = (timer - 60) % 1200;
        if (timer >= 60) {
            for (const int start : {300, 460, 620}) {
                if (p < start || p >= start + 80) {
                    continue;
                }
                const int interval = kInterval[static_cast<std::size_t>(difficulty)];
                const int local = p - start;
                int count = kCount[static_cast<std::size_t>(difficulty)];
                int spread = 0x8000;
                if (local % (interval * 2) == interval) {
                    --count;
                    spread = (0x8000 / count) * (count - 1);
                }
                else if (local % (interval * 2) != 0) {
                    continue;
                }
                playPlayerSound(bullet2SoundHandle_, 0x0c);
                const auto aimed = aimFrom(sourceX, sourceY);
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(4, 0, sourceX, sourceY, aimed, 0.0f,
                                      speed, 1, count, spread, 0);
                for (int j = 1;
                     j <= kExtraPairs[static_cast<std::size_t>(difficulty)]; ++j) {
                    spawnProjectileSpread(4, 0, sourceX, sourceY,
                                          normalizeAngle16(static_cast<int>(aimed) - j * 400),
                                          0.0f, speed, 1, count, spread, 0);
                    spawnProjectileSpread(4, 0, sourceX, sourceY,
                                          normalizeAngle16(static_cast<int>(aimed) + j * 400),
                                          0.0f, speed, 1, count, spread, 0);
                }
            }
        }
        return;
    }

    if (enemy.helperState != 10) {
        return;
    }

    const auto aimed = aimFrom(sourceX, sourceY);
    if (timer < 180 || (timer >= 360 && timer < 660)) {
        static constexpr std::array<int, 5> kInterval{{44, 27, 23, 18, 16}};
        static constexpr std::array<int, 5> kFanCount{{4, 7, 7, 7, 9}};
        static constexpr std::array<int, 5> kAngleLayers{{2, 2, 3, 3, 3}};
        static constexpr std::array<int, 5> kSecondCount{{9, 15, 19, 21, 23}};
        static constexpr std::array<double, 5> kSpeed{{4.5, 6.0, 5.5, 6.0, 7.2}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
        if (timer % (interval * 3) == 0) {
            playPlayerSound(bullet1SoundHandle_, 0x0c);
            const int count = kFanCount[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(4, 0, sourceX, sourceY, aimed, 0.0f,
                                  speed, 1, count, 0x8000, 0);
            for (int j = 1;
                 j <= kAngleLayers[static_cast<std::size_t>(difficulty)]; ++j) {
                spawnProjectileSpread(4, 0, sourceX, sourceY,
                                      normalizeAngle16(static_cast<int>(aimed) - j * 400),
                                      0.0f, speed, 1, count, 0x8000, 0);
                spawnProjectileSpread(4, 0, sourceX, sourceY,
                                      normalizeAngle16(static_cast<int>(aimed) + j * 400),
                                      0.0f, speed, 1, count, 0x8000, 0);
            }
        }
        if (timer >= interval && (timer - interval) % (interval * 3) == 0) {
            playPlayerSound(bullet1SoundHandle_, 0x0c);
            const int count = kSecondCount[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(0, 0, sourceX, sourceY, aimed, 0.0f,
                                  speed, 1, count, 0x8000, 0);
        }
        if (timer >= interval * 2 &&
            (timer - interval * 2) % (interval * 3) == 0) {
            playPlayerSound(bullet1SoundHandle_, 0x0c);
            const int count = kSecondCount[static_cast<std::size_t>(difficulty)] - 1;
            const int spread = (0x8000 / count) * (count - 1);
            spawnProjectileSpread(0, 0, sourceX, sourceY, aimed, 0.0f,
                                  speed, 1, count, spread, 0);
        }
    }

    if (timer >= 200 && timer < 350) {
        static constexpr std::array<int, 5> kCycle{{50, 40, 30, 30, 38}};
        static constexpr std::array<int, 5> kBurst{{20, 28, 27, 30, 36}};
        static constexpr std::array<double, 5> kSlope{{0.08, 0.12, 0.14, 0.14, 0.16}};
        static constexpr std::array<double, 5> kBase{{4.0, 5.5, 6.0, 6.0, 7.5}};
        const int cycle = kCycle[static_cast<std::size_t>(difficulty)];
        const int local = (timer - 200) % cycle;
        if (local == 0) {
            enemy.secondaryAngle16 = aimed;
        }
        if (local < kBurst[static_cast<std::size_t>(difficulty)] && local % 3 == 0) {
            playPlayerSound(bullet1SoundHandle_, 0x0c);
            const int count = local / 3 + 1;
            const double speed = kBase[static_cast<std::size_t>(difficulty)] +
                                 local * kSlope[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(12, 0, sourceX, sourceY,
                                  enemy.secondaryAngle16, 0.0f, speed, 1,
                                  count, count * 600 - 600, 0);
            if (difficulty >= 3) {
                spawnProjectileSpread(12, 0, sourceX, sourceY,
                                      normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) - 9000),
                                      0.0f, speed, 1, count, count * 600 - 600, 0);
                spawnProjectileSpread(12, 0, sourceX, sourceY,
                                      normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + 9000),
                                      0.0f, speed, 1, count, count * 600 - 600, 0);
            }
        }
    }

    if (timer >= 670 && (timer - 670) % 3 == 0) {
        static constexpr std::array<int, 5> kSpread{{10000, 8000, 7500, 7500, 7000}};
        for (int i = 0; i < 3; ++i) {
            playPlayerSound(bullet1SoundHandle_, 0x0c);
            const int baseSpread = kSpread[static_cast<std::size_t>(difficulty)] + i * 5000;
            int spread = baseSpread;
            auto center = aimed;
            if (timer < 800) {
                spread = baseSpread * 5 - static_cast<int>(
                    std::sin(static_cast<double>(timer - 670) * kPi / 260.0) *
                    static_cast<double>(baseSpread * 4));
            }
            else {
                center = normalizeAngle16(static_cast<int>(aimed) + static_cast<int>(
                    std::sin(static_cast<double>(timer - 800) * kPi / 64.0) * 1200.0));
            }
            spawnProjectileSpread(8, 0, sourceX, sourceY, center, 10.0f,
                                  12.0, 1, 2, spread, 0);
        }
    }
}

void StageRuntime::updateStage04BossChild(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != 0x13b || !parent->active) {
        enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x40) {
        updateStage04Type40(enemy, *parent);
    }
    else if (enemy.spawnType == 0x41) {
        updateStage04Type41(enemy, *parent);
    }
    else {
        updateStage04Type42Or43(enemy, *parent);
    }
}

void StageRuntime::updateStage04Type40(StageEnemy& enemy, StageEnemy& parent) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int index = std::clamp(enemy.childIndex, 0, 5);
    const int parentTimer = parent.helperTimer;
    const auto sourceOnScreen = [this](float x, float y) {
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        return x >= horizontalOrigin && x <= horizontalOrigin + 600.0f &&
               y >= 0.0f && y <= 720.0f;
    };
    const auto aimFrom = [this](float x, float y) {
        return radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto turnStepFor = [](std::uint16_t current, std::uint16_t target,
                                int base) {
        int delta = static_cast<int>(target) - static_cast<int>(current);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        return std::abs(delta) / 10 + base;
    };
    const auto mountX = [&]() { return parent.x + enemy.originX; };
    const auto mountY = [&]() { return parent.y + enemy.originY; };
    const auto mountAngleAtEntry = radiansToFixedAngleTrunc(std::atan2(
        static_cast<double>(mountY() - enemy.y),
        static_cast<double>(mountX() - enemy.x)));
    const auto followMount = [&]() {
        enemy.secondaryAngle16 = approachAngle16(
            enemy.secondaryAngle16, mountAngleAtEntry, 0x457);
        const double radians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
    };
    const auto easeToMount = [&]() {
        enemy.x += (mountX() - enemy.x) / 20.0f;
        enemy.y += (mountY() - enemy.y) / 20.0f;
    };

    if (enemy.helperState == 0) {
        const int timer = enemy.helperTimer;
        if (timer == 0) {
            enemy.x = mountX();
            enemy.y = mountY();
        }
        if (timer == 60) {
            enemy.secondaryAngle16 =
                (index == 0 || index == 3 || index == 4) ? 1000 : 0x7c18;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 1.0;
            enemy.speed = 1.0f;
            enemy.targetable = true;
            ++parent.liveChildCount;
        }
        if (timer == 40) {
            playPlayerSound(bossSe1SoundHandle_, 0x13);
        }
    }

    if (enemy.helperState == 1) {
        followMount();
        if (enemy.helperTimer > 29) {
            if (parentTimer < 600) {
                enemy.helperState = 2;
                enemy.helperTimer = 0;
            }
            else if (parentTimer < 940) {
                enemy.helperState = 3;
                enemy.helperTimer = 0;
            }
            else if (parentTimer >= 1950 && parentTimer < 2550) {
                enemy.helperState = 6;
                enemy.helperTimer = 0;
            }
        }
        if (parentTimer == 960 + index * 150) {
            enemy.helperState = 4;
            enemy.helperTimer = 0;
        }
        if (parentTimer == 2600 || parentTimer == 2870 || parentTimer == 3140) {
            enemy.helperState = 7;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == 2) {
        followMount();
        if (parentTimer < 580) {
            static constexpr std::array<int, 5> kPeriod{{79, 79, 61, 48, 39}};
            static constexpr std::array<int, 5> kPairStep{{12, 12, 10, 8, 7}};
            static constexpr std::array<double, 5> kSpeed{{2.5, 3.5, 3.8, 4.5, 5.5}};
            static constexpr std::array<int, 6> kWaveSign{{
                2222, -2222, -2222, 2222, 2222, -2222,
            }};
            const auto baseAim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - enemy.y),
                static_cast<double>(player_.x - parent.x)));
            const auto shotAngle = normalizeAngle16(
                static_cast<int>(baseAim) + static_cast<int>(
                    std::sin(static_cast<double>(parentTimer - 32) * kPi / 72.0) *
                    kWaveSign[static_cast<std::size_t>(index)]));
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, shotAngle,
                turnStepFor(enemy.sourceAngle16, shotAngle, 0x30));
            const int start = 32 + (index / 2) *
                                      kPairStep[static_cast<std::size_t>(difficulty)];
            if (parentTimer >= start &&
                (parentTimer - start) % kPeriod[static_cast<std::size_t>(difficulty)] == 0) {
                if (sourceOnScreen(enemy.x, enemy.y)) {
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(13, 0, enemy.x, enemy.y, shotAngle, 0.0f,
                                    speed, 1, 0);
                if (difficulty > 0) {
                    spawnProjectileNode(13, 0, enemy.x, enemy.y,
                                        normalizeAngle16(static_cast<int>(shotAngle) - 4444),
                                        0.0f, speed - 0.3, 1, 0);
                    spawnProjectileNode(13, 0, enemy.x, enemy.y,
                                        normalizeAngle16(static_cast<int>(shotAngle) + 4444),
                                        0.0f, speed - 0.3, 1, 0);
                }
            }
        }
        if (parentTimer == 600) {
            enemy.helperState = 3;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == 3) {
        easeToMount();
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, 0x4000,
            turnStepFor(enemy.sourceAngle16, 0x4000, 0x30));
        if (parentTimer >= 660 && parentTimer < 920) {
            static constexpr std::array<int, 5> kPeriod{{65, 44, 38, 44, 38}};
            static constexpr std::array<double, 5> kBaseSpeed{{4.2, 5.5, 6.0, 6.0, 8.0}};
            static constexpr std::array<int, 6> kIndexOffset{{
                0, 0, -1000, 1000, -2000, 2000,
            }};
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int local = (parentTimer - 660) % period;
            if (local == 0) {
                enemy.targetAngle16 = normalizeAngle16(
                    static_cast<int>(aimFrom(enemy.x, enemy.y)) +
                    kIndexOffset[static_cast<std::size_t>(index)] +
                    static_cast<int>(
                        std::sin(static_cast<double>(parentTimer -
                                                     (660 - period / 2)) *
                                 kPi / static_cast<double>(period)) *
                        static_cast<double>((parentTimer - 660) * 16)));
            }
            if (local <= 20 && local % 4 == 0) {
                if (sourceOnScreen(enemy.x, enemy.y)) {
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                }
                const double speed = kBaseSpeed[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>(local) * 0.1;
                spawnProjectileNode(9, 0, enemy.x, enemy.y,
                                    enemy.targetAngle16, 0.0f, speed, 1, 0);
                if (difficulty >= 3) {
                    spawnProjectileNode(9, 0, enemy.x, enemy.y,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 3888),
                                        0.0f, speed - 0.6, 1, 0);
                    spawnProjectileNode(9, 0, enemy.x, enemy.y,
                                        normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 3889),
                                        0.0f, speed - 0.6, 1, 0);
                }
            }
        }
        if (parentTimer == 940) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == 4 || enemy.helperState == 7) {
        const int dashState = enemy.helperState;
        const int timer = enemy.helperTimer;
        if (timer < 50) {
            const auto aimed = aimFrom(enemy.x, enemy.y);
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed,
                turnStepFor(enemy.sourceAngle16, aimed, 0x30));
        }
        if (timer == 1) {
            playPlayerSound(bossSe2SecondSoundHandle_, 0x19);
            const int handle = effectMediumFrames_.size() > 20
                                   ? effectMediumFrames_[20]
                                   : -1;
            spawnStageEffect(0x41, handle, 80, 0x4e, enemy.x, enemy.y,
                             enemy.sourceAngle16, 0.0, 0.7, 0.7, 90,
                             0xff, 0xff, 0xff, 0x80, enemy.entityId);
        }
        if (timer == 90) {
            playPlayerSound(bossSe5SoundHandle_, 0x19);
            enemy.sourceSpeed = 10.0;
            enemy.speed = 10.0f;
        }
        if (timer >= 90) {
            const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
            enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
            enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
            enemy.sourceSpeed += 0.2;
            enemy.speed = static_cast<float>(enemy.sourceSpeed);

            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            const bool inside = enemy.x >= horizontalOrigin &&
                                enemy.x <= horizontalOrigin + 600.0f &&
                                enemy.y >= 0.0f && enemy.y <= 720.0f;
            if (inside) {
                playPlayerSound(bullet1SoundHandle_, 0x0c);
                const float muzzleX = enemy.x + static_cast<float>(std::cos(radians) * 60.0);
                const float muzzleY = enemy.y + static_cast<float>(std::sin(radians) * 60.0);
                const auto reverse = normalizeAngle16(
                    static_cast<int>(enemy.sourceAngle16) + 0x8000);
                spawnProjectileNode(
                    3, 1, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(reverse) +
                                     stageRandomIntInclusive(
                                         static_cast<std::uint32_t>(frame_ + 444),
                                         -1200, 1200)),
                    0.0f, 10.0, 1, 0);
                spawnProjectileNode(
                    5, 1, muzzleX, muzzleY,
                    normalizeAngle16(static_cast<int>(reverse) +
                                     stageRandomIntInclusive(
                                         static_cast<std::uint32_t>(frame_),
                                         -1500, 1500)),
                    0.0f, 9.0, 1, 0);

                if (dashState == 4) {
                    static constexpr std::array<int, 5> kPeriod{{4, 1, 1, 1, 1}};
                    static constexpr std::array<int, 5> kCount{{1, 1, 2, 2, 3}};
                    static constexpr std::array<double, 5> kSpeed{{2.0, 2.8, 3.2, 3.6, 5.0}};
                    static constexpr std::array<int, 5> kSpin{{2000, 3800, 3600, 3600, 3200}};
                    const int period = kPeriod[static_cast<std::size_t>(difficulty)];
                    if ((timer - 90) % period == 0) {
                        const int direction = (index & 1) == 0 ? -1 : 1;
                        const auto ringAngle = normalizeAngle16(
                            static_cast<int>(enemy.sourceAngle16) +
                            direction * kSpin[static_cast<std::size_t>(difficulty)] * timer);
                        const int count = kCount[static_cast<std::size_t>(difficulty)];
                        const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                        spawnProjectileSpread(12, 3, muzzleX, muzzleY,
                                              ringAngle, 0.0f, speed, 1,
                                              count, kFixedAngleFullCircle, 0);
                        if (difficulty >= 3) {
                            spawnProjectileSpread(12, 3, muzzleX, muzzleY,
                                                  ringAngle, 0.0f, speed - 0.6, 1,
                                                  count, kFixedAngleFullCircle, 0);
                        }
                    }
                }
            }
        }
        if (timer >= 100 &&
            (enemy.x < 40.0f || enemy.x > 680.0f ||
             enemy.y < 40.0f || enemy.y > 680.0f)) {
            playPlayerSound(bossSe6SoundHandle_, 0x14);
            const int body = enemyMediumFrames_.size() > 75
                                 ? enemyMediumFrames_[75]
                                 : -1;
            spawnStageEffect(0x22, body, 80, 0x24, enemy.x, enemy.y,
                             enemy.sourceAngle16, 0.0, 3.0, 3.0, 24,
                             0xff, 0xff, 0xff, 0x80);
            enemy.helperState = dashState + 1;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == 5 || enemy.helperState == 8) {
        const int returnState = enemy.helperState;
        const int timer = enemy.helperTimer;
        if (timer >= 90) {
            easeToMount();
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, 0x4000,
                turnStepFor(enemy.sourceAngle16, 0x4000, 0x30));
        }
        if (returnState == 8) {
            static constexpr std::array<int, 5> kDivisor{{7, 4, 3, 2, 2}};
            static constexpr std::array<int, 5> kWindow{{14, 18, 20, 20, 23}};
            static constexpr std::array<double, 5> kSpeed{{3.5, 4.5, 5.0, 5.5, 7.5}};
            static constexpr std::array<float, 6> kChainX{{
                50.0f, -50.0f, 100.0f, -100.0f, 140.0f, -140.0f,
            }};
            static constexpr std::array<float, 6> kChainY{{
                150.0f, 150.0f, 140.0f, 140.0f, 120.0f, 120.0f,
            }};
            const int start = index * 12 + 8;
            if (timer >= start &&
                timer < start + kWindow[static_cast<std::size_t>(difficulty)] &&
                (timer - start) % 3 == 0) {
                const float anchorX = parent.x + kChainX[static_cast<std::size_t>(index)];
                const float anchorY = parent.y + kChainY[static_cast<std::size_t>(index)];
                const auto chainAngle = radiansToFixedAngleTrunc(std::atan2(
                    static_cast<double>(enemy.y - anchorY),
                    static_cast<double>(enemy.x - anchorX)));
                for (int segment = 0; segment < 20; ++segment) {
                    if (segment % kDivisor[static_cast<std::size_t>(difficulty)] != 0) {
                        continue;
                    }
                    const float fraction = static_cast<float>(segment) / 20.0f;
                    const float wave = 4.0f * std::sin(
                        static_cast<double>(frame_ - segment * 7) * kTau / 80.0);
                    const float sourceX = anchorX + (enemy.x - anchorX) * fraction + wave;
                    const float sourceY = anchorY + (enemy.y - anchorY) * fraction;
                    if (sourceOnScreen(sourceX, sourceY)) {
                        playPlayerSound(bullet1SoundHandle_, 9);
                    }
                    spawnProjectileSpread(
                        4, 0, sourceX, sourceY,
                        normalizeAngle16(static_cast<int>(chainAngle) + 0x8000),
                        0.0f,
                        kSpeed[static_cast<std::size_t>(difficulty)] +
                            static_cast<double>(timer - start) * 0.1,
                        1, 2, 0x4000 + segment * 0x666, 0);
                }
            }
        }
        if (timer == 120 || parentTimer == 2868 || parentTimer == 3138) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.sourceSpeed = 1.0;
            enemy.speed = 1.0f;
        }
    }

    if (enemy.helperState == 6) {
        easeToMount();
        static constexpr std::array<int, 6> kPhaseStart{{14, 21, 7, 27, 0, 35}};
        static constexpr std::array<int, 6> kPhaseOffset{{
            0, 0, -2000, 2000, -4000, 4000,
        }};
        const int wave = kPhaseOffset[static_cast<std::size_t>(index)] +
                         static_cast<int>(std::sin(
                             static_cast<double>(parentTimer -
                                                  kPhaseStart[static_cast<std::size_t>(index)]) *
                             kTau / 155.0) * 2400.0);
        auto heading = normalizeAngle16(wave + 0x4000);
        if (enemy.y >= player_.y) {
            heading = normalizeAngle16(static_cast<int>(heading) + 0x8000);
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, heading,
            turnStepFor(enemy.sourceAngle16, 0x4000, 0x30));

        static constexpr std::array<int, 5> kPeriod{{72, 44, 32, 32, 28}};
        static constexpr std::array<int, 5> kWindow{{12, 16, 16, 16, 20}};
        static constexpr std::array<int, 5> kCount{{1, 1, 1, 2, 2}};
        static constexpr std::array<double, 5> kBase{{3.0, 3.8, 4.5, 4.5, 5.5}};
        const int start = 2000 + (index / 2) * 8;
        if (parentTimer >= start) {
            const int remainder = parentTimer - start;
            const int phase = remainder % kPeriod[static_cast<std::size_t>(difficulty)];
            if (phase < kWindow[static_cast<std::size_t>(difficulty)] &&
                remainder % 4 == 0) {
                if (sourceOnScreen(enemy.x, enemy.y)) {
                    playPlayerSound(bullet1SoundHandle_, 9);
                }
                const double speed = kBase[static_cast<std::size_t>(difficulty)] +
                                     static_cast<double>(parentTimer - 2000) * 0.005;
                spawnProjectileSpread(13, 0, enemy.x, enemy.y, heading, 0.0f,
                                      speed, 1,
                                      kCount[static_cast<std::size_t>(difficulty)],
                                      0x0d05, 0);
                const auto opposite = normalizeAngle16(static_cast<int>(heading) + 0x8000);
                spawnProjectileNode(13, 0, enemy.x, enemy.y,
                                    normalizeAngle16(static_cast<int>(opposite) - 0x2aaa),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(13, 0, enemy.x, enemy.y,
                                    normalizeAngle16(static_cast<int>(opposite) + 0x2aab),
                                    0.0f, speed, 1, 0);
            }
        }
        if (parentTimer == 2550) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
    }

    if (enemy.helperState == -1) {
        const int timer = enemy.helperTimer;
        static constexpr std::array<float, 6> kChainX{{
            50.0f, -50.0f, 100.0f, -100.0f, 140.0f, -140.0f,
        }};
        static constexpr std::array<float, 6> kChainY{{
            150.0f, 150.0f, 140.0f, 140.0f, 120.0f, 120.0f,
        }};
        const float anchorX = parent.x + kChainX[static_cast<std::size_t>(index)];
        const float anchorY = parent.y + kChainY[static_cast<std::size_t>(index)];
        for (int segment = 0; segment < 20; ++segment) {
            if (timer != 60 - segment * 3) {
                continue;
            }
            const float fraction = static_cast<float>(segment) / 20.0f;
            const float pointX = anchorX + (enemy.x - anchorX) * fraction +
                4.0f * std::sin(static_cast<double>(frame_ - segment * 7) *
                                kTau / 80.0);
            const float pointY = anchorY + (enemy.y - anchorY) * fraction;
            const int burst = effectMediumFrames_.size() > 5
                                  ? effectMediumFrames_[5]
                                  : -1;
            const int spark = playerFrames_.size() > 14
                                  ? playerFrames_[14]
                                  : -1;
            spawnStageEffect(0x2a, burst, 200, 0x1d, pointX, pointY,
                             scriptRandomAngle(static_cast<std::uint32_t>(timer + segment)),
                             0.0, 1.0, 1.0, 24,
                             0xff, 0xff, 0xff, 0xc0);
            spawnStageEffect(0x2c, spark, 80, 0x3e, pointX, pointY,
                             scriptRandomAngle(static_cast<std::uint32_t>(frame_ + segment)),
                             8.0, 1.0, 1.0, 0,
                             0xff, 0xff, 0xff, 0xc0);
            playPlayerSound(enemyDown1SoundHandle_, 0x13);
        }
        if (parent.helperState != 1 && timer >= 80) {
            enemy.active = false;
        }
        if (timer == 200) {
            enemy.hp = enemy.maxHp;
            enemy.drawHp = enemy.hp;
            enemy.x = mountX();
            enemy.y = mountY();
            enemy.helperState = 0;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }

    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawHp = enemy.hp;

    if (enemy.hp < 1 && enemy.helperState >= 1) {
        spawnEnemyDeathRewardBurst(enemy, 2000, false);
        spawnEnemyDeathEffects(enemy, 1);
        spawnStage04DeathNode(enemy, enemy.maxHp, parent.entityId);
        parent.liveChildCount = std::max(0, parent.liveChildCount - 1);
        enemy.targetable = false;
        enemy.helperState = -1;
        enemy.helperTimer = 0;
    }
    else if (enemy.helperState >= 1 &&
             !(parent.hp > 0 && stage04BossCountdown_ > 0 &&
               parent.helperState < 2)) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.targetable = false;
        enemy.helperState = -1;
        enemy.helperTimer = 0;
    }
}

void StageRuntime::updateStage04Type41(StageEnemy& enemy, StageEnemy& parent) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int stateAtEntry = enemy.helperState;
    const int timer = enemy.helperTimer;
    double entryScale = 1.0;
    if (enemy.helperState == 0) {
        entryScale = std::sin(static_cast<double>(timer) * kPi / 100.0);
        if (timer == 50) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            entryScale = 1.0;
        }
    }

    if (enemy.helperState == 1) {
        const int liveTimer = enemy.helperTimer;
        const int maximumStep = difficulty == 0 ? 333 : 555;
        int step = 0;
        if (liveTimer < 600) {
            step = static_cast<int>(std::sin(
                static_cast<double>(liveTimer) * kPi / 1200.0) * maximumStep);
        }
        else if (liveTimer < 1200) {
            step = maximumStep;
        }
        else if (liveTimer < 1800) {
            step = maximumStep - static_cast<int>(std::sin(
                static_cast<double>(liveTimer - 1200) * kPi / 1200.0) * maximumStep);
        }
        enemy.secondaryAngle16 = normalizeAngle16(
            static_cast<int>(enemy.secondaryAngle16) + step);

        static constexpr std::array<int, 5> kInterval{{8, 5, 3, 4, 3}};
        static constexpr std::array<double, 5> kSpeed{{4.8, 6.0, 7.0, 7.0, 9.0}};
        const int interval = kInterval[static_cast<std::size_t>(difficulty)];
        for (int wave = 0; wave < 25; ++wave) {
            const int start = 10 + 24 * wave +
                              interval * wave * (wave - 1) / 2;
            if (liveTimer >= start && liveTimer <= start + wave * interval &&
                (liveTimer - start) % interval == 0) {
                playPlayerSound(bullet1SoundHandle_, 0x0c);
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(3, 0, enemy.x, enemy.y + 15.0f,
                                    enemy.secondaryAngle16, 0.0f, speed, 1, 0);
                if (difficulty >= 3) {
                    spawnProjectileNode(9, 0, enemy.x, enemy.y + 15.0f,
                                        enemy.secondaryAngle16, 0.0f,
                                        speed - 2.4, 1, 0);
                }
            }
        }
    }

    const double radians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
    enemy.x = parent.x + static_cast<float>(
        std::cos(radians) * static_cast<double>(enemy.originX) * entryScale);
    enemy.y = parent.y + static_cast<float>(
        std::sin(radians) * static_cast<double>(enemy.originY) * entryScale);
    if (stateAtEntry == 0 && timer < 50 && (timer & 1) == 0) {
        const double base = entryScale *
            (0.9 + 0.1 * std::sin(fixedAngleToRadiansDouble(
                                enemy.secondaryAngle16)));
        const double pulse0 = base * (1.0 + 0.1 * std::sin(
            static_cast<double>(parent.helperTimer) * kPi / 22.0));
        const double pulse10 = base * (1.0 + 0.1 * std::sin(
            static_cast<double>(parent.helperTimer - 10) * kPi / 22.0));
        const int layer = enemy.secondaryAngle16 <= 0x8000 ? 0x1f : 0x1c;
        spawnStageEffect(0x05,
                         enemySmallFrames_.size() > 44 ? enemySmallFrames_[44] : -1,
                         16, layer + 1, enemy.x, enemy.y, 0,
                         0.0, pulse10, base, 16,
                         0xff, 0xff, 0xff, 0x60);
        spawnStageEffect(0x05,
                         enemySmallFrames_.size() > 45 ? enemySmallFrames_[45] : -1,
                         16, layer + 1, enemy.x, enemy.y, 0,
                         0.0, pulse0, base, 16,
                         0xff, 0xff, 0xff, 0x60);
    }
    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawHp = enemy.hp;

    if (parent.hp < 1 || stage04BossCountdown_ < 1) {
        spawnEnemyDeathEffects(enemy, 0);
        enemy.active = false;
    }
}

void StageRuntime::updateStage04Type42Or43(StageEnemy& enemy,
                                           StageEnemy& parent) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int stateAtEntry = enemy.helperState;
    const int timerAtEntry = enemy.helperTimer;
    const float centerX = parent.x;
    const float centerY = parent.y - 60.0f;
    double entryScale = 1.0;

    if (enemy.helperState == 0) {
        if (timerAtEntry == 0) {
            enemy.sourceAngle16 = 0x4000;
        }
        entryScale = std::sin(static_cast<double>(timerAtEntry) * kPi / 100.0);
        const double radians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
        enemy.x = centerX + static_cast<float>(
            std::cos(radians) * static_cast<double>(enemy.originX) * entryScale);
        enemy.y = centerY + static_cast<float>(
            std::sin(radians) * static_cast<double>(enemy.originX) * entryScale);
        if (timerAtEntry == 50) {
            enemy.maxHp = parent.maxHp;
            enemy.hp = parent.hp;
            enemy.drawHp = enemy.hp;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            entryScale = 1.0;
        }
    }

    if (enemy.helperState == 1) {
        const int timer = enemy.helperTimer;
        const float oldX = enemy.x;
        const float oldY = enemy.y;
        const auto oldHeading = enemy.sourceAngle16;
        const double oldHeadingRadians = fixedAngleToRadiansDouble(oldHeading);
        const float muzzleX = oldX + static_cast<float>(std::cos(oldHeadingRadians) * 50.0);
        const float muzzleY = oldY + static_cast<float>(std::sin(oldHeadingRadians) * 50.0);

        if (enemy.spawnType == 0x42) {
            const int cycle = timer % 1200;
            const int rotationStep = static_cast<int>(
                std::sin(static_cast<double>(timer) * kPi / 1200.0) * 550.0);
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + rotationStep);
            static constexpr std::array<int, 5> kRadiusAmplitude{{
                -120, -80, -60, -60, -40,
            }};
            const double radius = 180.0 +
                std::sin(static_cast<double>(cycle) * kPi / 1200.0) *
                    kRadiusAmplitude[static_cast<std::size_t>(difficulty)];
            const double orbitRadians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
            enemy.x = centerX + static_cast<float>(std::cos(orbitRadians) * radius);
            enemy.y = centerY + static_cast<float>(std::sin(orbitRadians) * radius);

            const auto aimed = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - centerY),
                static_cast<double>(player_.x - centerX)));
            int delta = static_cast<int>(aimed) - static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed, std::abs(delta) / 10 + 0x30);

            static constexpr std::array<int, 5> kPeriodA{{90, 44, 33, 50, 44}};
            static constexpr std::array<int, 5> kBurstA{{18, 21, 24, 24, 24}};
            static constexpr std::array<double, 5> kBaseA{{4.0, 5.0, 6.0, 6.5, 7.5}};
            if (cycle < 280) {
                const int phase = cycle % kPeriodA[static_cast<std::size_t>(difficulty)];
                if (phase == 0) {
                    enemy.targetAngle16 = enemy.sourceAngle16;
                }
                if (phase < kBurstA[static_cast<std::size_t>(difficulty)] &&
                    phase % 3 == 0) {
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                    const double speed = kBaseA[static_cast<std::size_t>(difficulty)] +
                                         static_cast<double>(phase) * 0.1;
                    spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                        enemy.targetAngle16, 10.0f, speed, 1, 0);
                    if (difficulty >= 3) {
                        spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 0x0d05),
                                            10.0f, speed - 0.8, 1, 0);
                        spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 0x0d05),
                                            10.0f, speed - 0.8, 1, 0);
                    }
                }
            }

            static constexpr std::array<int, 4> kAnchors{{410, 570, 730, 800}};
            static constexpr std::array<double, 5> kBaseB{{3.5, 4.5, 5.0, 5.0, 6.0}};
            static constexpr std::array<double, 5> kSlopeB{{0.10, 0.15, 0.20, 0.20, 0.24}};
            for (const int anchor : kAnchors) {
                if (cycle == anchor) {
                    enemy.targetAngle16 = enemy.sourceAngle16;
                }
                if (cycle >= anchor && cycle < anchor + 60 &&
                    (cycle - anchor) % 4 == 0) {
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                    const double speed = kBaseB[static_cast<std::size_t>(difficulty)] +
                        static_cast<double>(cycle - anchor) *
                            kSlopeB[static_cast<std::size_t>(difficulty)];
                    spawnProjectileNode(2, 0, muzzleX, muzzleY,
                                        enemy.targetAngle16, 10.0f, speed, 1, 0);
                    if (difficulty >= 3) {
                        spawnProjectileNode(2, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 0x34bc),
                                            10.0f, speed, 1, 0);
                        spawnProjectileNode(2, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 0x34bc),
                                            10.0f, speed, 1, 0);
                    }
                }
            }

            static constexpr std::array<int, 5> kIntervalC{{48, 30, 18, 14, 12}};
            static constexpr std::array<double, 5> kSpeedC{{4.0, 5.0, 5.5, 6.5, 7.7}};
            if (cycle >= 880 && cycle < 1150 &&
                (cycle - 880) % kIntervalC[static_cast<std::size_t>(difficulty)] == 0) {
                playPlayerSound(bullet1SoundHandle_, 0x0c);
                const double speed = kSpeedC[static_cast<std::size_t>(difficulty)];
                spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                    enemy.sourceAngle16, 10.0f, speed, 1, 0);
                if (difficulty > 0) {
                    spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                        normalizeAngle16(static_cast<int>(enemy.sourceAngle16) - 0x0f30),
                                        10.0f, speed, 1, 0);
                    spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                        normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + 0x0f31),
                                        10.0f, speed, 1, 0);
                }
            }
        }
        else {
            int rotationStep = 0;
            if (timer < 600) {
                rotationStep = static_cast<int>(
                    std::sin(static_cast<double>(timer) * kPi / 1200.0) * 240.0);
            }
            else if (timer < 1200) {
                rotationStep = 240;
            }
            else if (timer < 1800) {
                rotationStep = 240 - static_cast<int>(
                    std::sin(static_cast<double>(timer - 1200) * kPi / 1200.0) * 240.0);
            }
            enemy.secondaryAngle16 = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) + rotationStep);
            const double orbitRadians = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
            enemy.x = centerX + static_cast<float>(std::cos(orbitRadians) * 130.0);
            enemy.y = centerY + static_cast<float>(std::sin(orbitRadians) * 130.0);

            const auto aimed = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - oldY),
                static_cast<double>(player_.x - oldX)));
            int delta = static_cast<int>(aimed) - static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimed, std::abs(delta) / 10 + 0x30);

            static constexpr std::array<int, 5> kPeriod{{75, 40, 36, 32, 26}};
            static constexpr std::array<double, 5> kBase{{5.5, 6.5, 7.0, 7.5, 9.5}};
            const int period = kPeriod[static_cast<std::size_t>(difficulty)];
            const int start = 20 + enemy.childIndex * period;
            if (timer >= start) {
                const int cycle = (timer - start) % (period * 3);
                if (cycle == 0) {
                    enemy.targetAngle16 = enemy.sourceAngle16;
                }
                if (cycle < 24 && cycle % 3 == 0) {
                    playPlayerSound(bullet1SoundHandle_, 0x0c);
                    const double speed = kBase[static_cast<std::size_t>(difficulty)] +
                        static_cast<double>((timer - start) % period) * 0.07;
                    spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                        enemy.targetAngle16, 10.0f, speed, 1, 0);
                    if (difficulty >= 3) {
                        spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) - 750),
                                            10.0f, speed - 0.5, 1, 0);
                        spawnProjectileNode(13, 0, muzzleX, muzzleY,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) + 750),
                                            10.0f, speed - 0.5, 1, 0);
                    }
                }
            }
            enemy.targetAngle16 = approachAngle16(enemy.targetAngle16, aimed, 0x30);
        }
    }

    if (stateAtEntry == 0 && timerAtEntry < 50 && (timerAtEntry & 1) == 0) {
        const double pulse0 = entryScale * (1.0 + 0.1 * std::sin(
            static_cast<double>(parent.helperTimer) * kPi / 33.0));
        const double pulse12 = entryScale * (1.0 + 0.1 * std::sin(
            static_cast<double>(parent.helperTimer - 12) * kPi / 33.0));
        const double headingRadians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        spawnStageEffect(0x05,
                         enemyMediumFrames_.size() > 77 ? enemyMediumFrames_[77] : -1,
                         20, 0x24,
                         enemy.x + static_cast<float>(
                             std::cos(headingRadians) * 30.0 * entryScale),
                         enemy.y + static_cast<float>(
                             std::sin(headingRadians) * 30.0 * entryScale),
                         enemy.sourceAngle16, 0.0, entryScale, pulse12, 20,
                         0xff, 0xff, 0xff, 0x60);
        spawnStageEffect(0x05,
                         enemyMediumFrames_.size() > 76 ? enemyMediumFrames_[76] : -1,
                         20, 0x24, enemy.x, enemy.y, 0,
                         0.0, entryScale, pulse0, 20,
                         0xff, 0xff, 0xff, 0x60);
    }

    enemy.drawHelperState = enemy.helperState;
    enemy.drawHelperTimer = enemy.helperTimer;
    enemy.drawHp = enemy.hp;

    if (enemy.helperState == 1) {
        if (enemy.hp < parent.hp) {
            parent.hp = enemy.hp;
        }
        if (parent.hp < enemy.hp) {
            enemy.hp = parent.hp;
        }
        if (enemy.hp < 1) {
            parent.hp = 0;
        }
        if (parent.hp < 1 || stage04BossCountdown_ < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            enemy.active = false;
        }
    }
}

void StageRuntime::updateStage04Enemy(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    // FUN_140078b70 performs collision after the helper has queued its gauge.
    enemy.drawHp = enemy.hp;
    switch (enemy.spawnType) {
    case 0x35: {
        if (enemy.helperState == 0) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            if (enemy.helperTimer < 20) {
                break;
            }
            enemy.speed = 12.0f;
            if (enemy.originX <= 0.0f) {
                enemy.sourceAngle16 = 0x0000;
            }
            else if (enemy.originX >= 720.0f) {
                enemy.sourceAngle16 = 0x8000;
            }
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }
        int turn = enemy.helperTimer >= 45 && enemy.helperTimer <= 64 ? 1300 : 60;
        if ((enemy.originX <= 0.0f && enemy.originY >= 300.0f) ||
            (enemy.originX >= 720.0f && enemy.originY < 300.0f)) {
            turn = -turn;
        }
        enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + turn);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.vx = std::cos(enemy.angle) * 12.0f;
        enemy.vy = std::sin(enemy.angle) * 12.0f;
        const float nextX = enemy.x + enemy.vx;
        const float nextY = enemy.y + enemy.vy;
        const float horizontalOrigin = player_.x / 6.0f;
        if (nextX < horizontalOrigin - 180.0f || nextX > horizontalOrigin + 780.0f ||
            nextY < -180.0f || nextY > 900.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0x36: {
        if (enemy.helperState == 0) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            if (enemy.helperTimer < 20) {
                break;
            }
            const std::uint32_t random = stageScriptRandFromFrame(frame_);
            const int randomPart = static_cast<int>(random % 5001u);
            if (enemy.originX <= 0.0f) {
                enemy.sourceAngle16 = normalizeAngle16(-randomPart - 9000);
            }
            else if (enemy.originX >= 720.0f) {
                enemy.sourceAngle16 = normalizeAngle16(randomPart - 23768);
            }
            const float horizontalOrigin = player_.x / 6.0f;
            enemy.x = clampFloat(enemy.x, horizontalOrigin - 20.0f, horizontalOrigin + 620.0f);
            enemy.y = clampFloat(enemy.y, -20.0f, 740.0f);
            enemy.speed = 15.0f;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        const std::uint16_t target = enemy.helperTimer >= 201
                                         ? static_cast<std::uint16_t>(0xc000)
                                         : radiansToFixedAngleTrunc(std::atan2(
                                               static_cast<double>(player_.y - enemy.y),
                                               static_cast<double>(player_.x - enemy.x)));
        if (enemy.helperTimer < 80) {
            const int turnStep = std::max(0, static_cast<int>(
                std::sin(enemy.helperTimer * kPi / 160.0f) * 700.0f));
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, turnStep);
            if (enemy.speed > 1.0) {
                enemy.speed -= 0.18;
            }
        }
        else if (enemy.helperTimer <= 200) {
            if (enemy.helperTimer == 80) {
                enemy.targetable = true;
            }
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x80);
        }
        else {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 200);
            enemy.speed += 0.1;
        }
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        const float nextX = enemy.x + enemy.vx;
        const float nextY = enemy.y + enemy.vy;
        const float horizontalOrigin = player_.x / 6.0f;
        if (nextX < horizontalOrigin - 180.0f || nextX > horizontalOrigin + 780.0f ||
            nextY < -180.0f || nextY > 900.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0x37: {
        if (enemy.helperState == 0 && enemy.helperTimer == 0) {
            const std::uint32_t random = stageScriptRandFromFrame(frame_);
            const int low = static_cast<std::int16_t>(random & 0xffffu);
            const int quotient = static_cast<std::int16_t>((random / 4001u) & 0xffffu);
            enemy.sourceAngle16 = normalizeAngle16(low - quotient * 4001 - 0x47d0);
            enemy.secondaryAngle16 = enemy.sourceAngle16;
        }
        const float phaseScale = enemy.helperState == 0
                                     ? clampFloat(enemy.helperTimer / 120.0f, 0.0f, 1.0f)
                                     : 1.0f;
        const float baseSpeed = 8.0f * phaseScale;
        enemy.speed = baseSpeed - std::sin((enemy.helperTimer % 30) * kPi / 60.0f) * baseSpeed;
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        const int visualOffset = ((enemy.helperTimer / 30) & 1) == 0 ? 0x0d05 : -0x0d05;
        enemy.secondaryAngle16 = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + visualOffset);
        if (enemy.helperState == 0 && enemy.helperTimer >= 120) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }
        const float nextX = enemy.x + enemy.vx;
        const float nextY = enemy.y + enemy.vy;
        const float horizontalOrigin = player_.x / 6.0f;
        if (nextX < horizontalOrigin - 64.0f || nextX > horizontalOrigin + 664.0f ||
            nextY < -64.0f || nextY > 784.0f) {
            enemy.active = false;
        }
        break;
    }
    case 0x38: {
        const std::uint16_t motionTarget = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (enemy.helperState == 0) {
            if (enemy.helperTimer < 20) {
                break;
            }
            enemy.helperState = 1;
            enemy.sourceSpeed = 7.0;
            enemy.speed = 7.0f;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }

        if (enemy.helperTimer <= 120 && enemy.sourceSpeed > 1.2) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, motionTarget, 0x80);
        if (enemy.helperTimer >= 290) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.speed = static_cast<float>(enemy.sourceSpeed);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        break;
    }
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c: {
        enemy.drawBodyThisFrame = false;
        StageEnemy* owner = nullptr;
        const bool child = enemy.spawnType >= 0x3b;
        if (child) {
            owner = findEnemyById(enemy.parentEntityId);
        }

        if (enemy.helperState == 0) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            if (child) {
                if (owner == nullptr) {
                    break;
                }
                enemy.parentSpawnType = owner->spawnType;
                enemy.maxHp = owner->maxHp;
                enemy.hp = owner->hp;
                enemy.helperState = 1;
            }
            else {
                if (enemy.helperTimer < 20) {
                    break;
                }
                enemy.sourceAngle16 = enemy.spawnType == 0x39
                                          ? static_cast<std::uint16_t>(0x4000)
                                          : static_cast<std::uint16_t>(enemy.originX <= 360.0f ? 0xe4a8 : 0x9b58);
                enemy.secondaryAngle16 = enemy.sourceAngle16;
                enemy.sourceSpeed = 2.0;
                enemy.speed = 2.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
            }
        }

        if (enemy.helperState != 1) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            break;
        }

        enemy.drawBodyThisFrame = true;
        const int ownerType = child && owner != nullptr ? owner->spawnType : enemy.spawnType;
        int turn = 0;
        if (ownerType == 0x39) {
            turn = enemy.helperTimer < 120 ? 20 : (enemy.helperTimer < 180 ? 100 : 40);
        }
        else if (ownerType == 0x3a) {
            turn = enemy.helperTimer < 210 ? -80 : 60;
        }
        const int signedTurn = enemy.originX > 360.0f ? turn : -turn;
        enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + signedTurn);
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.speed = static_cast<float>(enemy.sourceSpeed == 0.0 ? 2.0 : enemy.sourceSpeed);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        break;
    }
    case 0x3d: {
        enemy.drawMarkerThisFrame = false;
        enemy.drawBodyThisFrame = false;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;

        if (enemy.helperState == 0) {
            const float horizontalOrigin = player_.x / 6.0f;
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                           horizontalOrigin + 650.0f);
            enemy.markerDrawY = clampFloat(enemy.y, -50.0f, 770.0f);

            if (enemy.helperTimer == 0) {
                spawnStage04Type3DChild(enemy, 0, -148.0f, -80.0f);
                spawnStage04Type3DChild(enemy, 1, -95.0f, -105.0f);
                spawnStage04Type3DChild(enemy, 2, 113.0f, -110.0f);
            }
            if (enemy.helperTimer != 20) {
                break;
            }

            enemy.sourceSpeed = 2.5;
            enemy.speed = 2.5f;
            enemy.sourceAngle16 = enemy.x <= 360.0f ? static_cast<std::uint16_t>(2000)
                                                    : static_cast<std::uint16_t>(0x7830);
            enemy.x = clampFloat(enemy.x, horizontalOrigin - 200.0f,
                                 horizontalOrigin + 800.0f);
            enemy.y = clampFloat(enemy.y, -200.0f, 920.0f);
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }

        if (enemy.helperState == 1) {
            enemy.drawBodyThisFrame = true;
            const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
            enemy.angle = static_cast<float>(radians);
            enemy.vx = static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
            enemy.vy = static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        }
        break;
    }
    case 0x3e: {
        enemy.drawMarkerThisFrame = false;
        enemy.drawBodyThisFrame = true;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;

        // FUN_140094bc0 aims from the previous child position before refreshing
        // the current position from the owner's current position plus local offset.
        const auto desiredAngle = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y) - static_cast<double>(enemy.y),
            static_cast<double>(player_.x) - static_cast<double>(enemy.x)));
        const StageEnemy* owner = findEnemyById(enemy.parentEntityId);
        const float ownerX = owner != nullptr ? owner->x : 0.0f;
        const float ownerY = owner != nullptr ? owner->y : 0.0f;
        const float ownerOriginX = owner != nullptr ? owner->originX : 0.0f;
        enemy.x = ownerX + enemy.originX;
        enemy.y = ownerY + enemy.originY;

        if (enemy.helperState == 0) {
            if (enemy.helperTimer == 0 && ownerOriginX < 360.0f) {
                // The position above intentionally retains the unmirrored x for
                // this first draw; the mirrored offset applies on the next call.
                enemy.originX = -enemy.originX;
            }
            if (enemy.helperTimer != 20) {
                break;
            }
            enemy.helperTimer = 0;
            enemy.helperState = 1;
        }

        if (enemy.helperState == 1) {
            int delta = static_cast<int>(desiredAngle) - static_cast<int>(enemy.sourceAngle16);
            if (delta > 0x8000) delta -= 0x10000;
            if (delta < -0x8000) delta += 0x10000;
            const int turnStep = std::abs(delta) / 10 + 0x30;
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, desiredAngle, turnStep);
            enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        }
        break;
    }
    case 0x3f: {
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;

        if (enemy.helperState == 0) {
            const int timer = enemy.helperTimer;
            const bool enterFromLeft = enemy.originX < 360.0f;
            if (timer < 90) {
                constexpr double kPiDouble = 3.14159265358979323846;
                const double wave = std::sin(static_cast<double>(timer) * kPiDouble / 180.0);
                const int horizontalTravel = 700 - static_cast<int>(wave * 700.0);
                const int verticalTravel = 400 - static_cast<int>(wave * 400.0);
                enemy.x = enemy.originX + static_cast<float>(
                    enterFromLeft ? horizontalTravel : -horizontalTravel);
                enemy.y = enemy.originY + static_cast<float>(verticalTravel);
            }
            else {
                enemy.x = enemy.originX;
                enemy.y = enemy.originY;
            }
            enemy.originY += 1.0f;

            if (timer != 120) {
                break;
            }
            enemy.sourceSpeed = 0.3;
            enemy.speed = 0.3f;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
        }

        if (enemy.helperState == 1) {
            const int timer = enemy.helperTimer;
            if (timer < 900) {
                if (timer % 20 == 0) {
                    enemy.originX = static_cast<float>(
                        stageScriptRandFromFrame(frame_) % 241u + 240u);
                    enemy.originY = static_cast<float>(
                        stageScriptRandFromFrame(frame_ + 0x115c) % 61u + 40u);
                }
                const auto target = radiansToFixedAngleTrunc(std::atan2(
                    static_cast<double>(enemy.originY) - static_cast<double>(enemy.y),
                    static_cast<double>(enemy.originX) - static_cast<double>(enemy.x)));
                enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x200);
            }
            else {
                enemy.sourceSpeed = static_cast<double>(timer - 900) * 0.1;
                enemy.speed = static_cast<float>(enemy.sourceSpeed);
                enemy.sourceAngle16 = 0x4000;
            }
            const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
            enemy.angle = static_cast<float>(radians);
            enemy.vx = static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
            enemy.vy = static_cast<float>(std::sin(radians) * enemy.sourceSpeed);
        }
        else if (enemy.helperState == 2) {
            if (enemy.helperTimer < 0x3d) {
                spawnStage02DeathExplosionChain(enemy);
            }
            enemy.y += static_cast<float>(enemy.helperTimer) * 0.06f;
            if (enemy.helperTimer == 60) {
                spawnEnemyDeathEffects(enemy, 2);
                enemy.active = false;
                stage04GateFlag_ = false;
            }
        }
        break;
    }
    default:
        break;
    }
}

void StageRuntime::emitStage04Projectiles(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    if (enemy.spawnType == 0x35) {
        const float horizontalOrigin = player_.x / 6.0f;
        const float fireY = enemy.y + 20.0f;
        const float nextX = enemy.x + enemy.vx;
        const float nextY = enemy.y + enemy.vy;
        if (enemy.helperState != 1 || enemy.helperTimer >= 200 ||
            enemy.x < horizontalOrigin + 40.0f || enemy.x > horizontalOrigin + 560.0f ||
            fireY < 40.0f || fireY > 680.0f ||
            nextX < horizontalOrigin + 20.0f || nextX > horizontalOrigin + 580.0f ||
            nextY < 20.0f || nextY > 700.0f) {
            return;
        }
        const int interval = kStage04Type35Interval[static_cast<std::size_t>(difficulty)];
        if (frame_ % interval == 0) {
            const auto aim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - fireY),
                static_cast<double>(player_.x - enemy.x)));
            const double speed = kStage04Type35Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(6, 0, enemy.x, fireY, aim, 0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(6, 0, enemy.x, fireY, aim, 0.0f, speed + 2.2, 1, 0);
            }
        }
        return;
    }
    if (enemy.spawnType == 0x36) {
        const int timer = enemy.helperTimer;
        const float horizontalOrigin = player_.x / 6.0f;
        const double heading = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        const float fireX = enemy.x + static_cast<float>(std::cos(heading) * 20.0);
        const float fireY = enemy.y + static_cast<float>(std::sin(heading) * 20.0);
        if (enemy.helperState != 1 || timer < 80 || timer >= 200 ||
            fireX < horizontalOrigin || fireX > horizontalOrigin + 600.0f ||
            fireY < 0.0f || fireY > 720.0f) {
            return;
        }
        const int interval = kStage04Type36Interval[static_cast<std::size_t>(difficulty)];
        if ((timer - 80) % interval == 0) {
            const auto rawAim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - fireY),
                static_cast<double>(player_.x - fireX)));
            const auto aim = normalizeAngle16(((static_cast<int>(rawAim) + 0x400) >> 11) * 0x800);
            const double speed = kStage04Type36Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(4, 0, fireX, fireY, normalizeAngle16(static_cast<int>(aim) - 200), 0.0f, speed, 1, 0);
            spawnProjectileNode(4, 0, fireX, fireY, normalizeAngle16(static_cast<int>(aim) + 200), 0.0f, speed, 1, 0);
            spawnProjectileNode(4, 0, fireX, fireY, aim, 0.0f, speed + 0.3, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(4, 0, fireX, fireY, normalizeAngle16(static_cast<int>(aim) - 750), 0.0f, speed - 0.5, 1, 0);
                spawnProjectileNode(4, 0, fireX, fireY, normalizeAngle16(static_cast<int>(aim) + 750), 0.0f, speed - 0.5, 1, 0);
            }
        }
        return;
    }
    if (enemy.spawnType == 0x37) {
        if (enemy.helperState != 1 || distanceSquared(enemy.x, enemy.y, player_.x, player_.y) <= 2500.0f) {
            return;
        }
        const int interval = kStage04Type37Interval[static_cast<std::size_t>(difficulty)];
        const int timer = enemy.helperTimer;
        if (timer < 10) {
            return;
        }
        const int phase = (timer - 10) % interval;
        if (phase == 0) {
            enemy.targetAngle16 = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - enemy.y),
                static_cast<double>(player_.x - enemy.x)));
        }
        const int substep = kStage04Type37Substep[static_cast<std::size_t>(difficulty)];
        if (phase < 24 && phase % substep == 0) {
            const int jitterRange = kStage04Type37Jitter[static_cast<std::size_t>(difficulty)];
            const int jitter = stageRandomIntInclusive(
                static_cast<std::uint32_t>(timer) * 0xad9cu +
                static_cast<std::uint32_t>(frame_),
                -jitterRange, jitterRange);
            const auto angle = normalizeAngle16(static_cast<int>(enemy.targetAngle16) + jitter);
            const double speed = kStage04Type37Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(0, 0, enemy.x, enemy.y, angle, 0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0, 0, enemy.x, enemy.y, angle, 0.0f, speed + 1.2, 1, 0);
            }
            enemy.targetAngle16 = approachAngle16(
                enemy.targetAngle16,
                radiansToFixedAngleTrunc(std::atan2(
                    static_cast<double>(player_.y - enemy.y),
                    static_cast<double>(player_.x - enemy.x))), 0x80);
        }
        return;
    }
    if (enemy.spawnType == 0x38) {
        const int timer = enemy.helperTimer;
        if (enemy.helperState != 1 || timer < 24 || timer > 289) {
            return;
        }

        const float rearWave = static_cast<float>(2.0 * std::sin(timer * kTau / 63.0f)) - 8.0f;
        const float fireY = enemy.y + rearWave - 5.0f;
        const std::uint16_t fireAim = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - fireY),
            static_cast<double>(player_.x - enemy.x)));
        const int local = (timer - 24) % 120;
        if (local == 0 || local == 40) {
            enemy.secondaryAngle16 = fireAim;
        }

        const int firstWindow = kStage04Type38FirstWindow[static_cast<std::size_t>(difficulty)];
        if (local < firstWindow && local % 4 == 0) {
            const int step = local / 4;
            spawnProjectileSpread(9, 0, enemy.x, fireY, enemy.secondaryAngle16, 10.0f,
                                  kStage04Type38Speed[static_cast<std::size_t>(difficulty)], 1,
                                  step + 1,
                                  step * kStage04Type38SpreadUnit[static_cast<std::size_t>(difficulty)], 0);
        }

        if (local >= 40 && local <= 69 && (local - 40) % 4 == 0) {
            const double ramp = static_cast<double>(local - 40) * 0.1;
            const double baseSpeed = kStage04Type38Speed[static_cast<std::size_t>(difficulty)];
            const int count = kStage04Type38WideCount[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(8, 0, enemy.x, fireY, enemy.secondaryAngle16, 0.0f,
                                  baseSpeed + ramp + 1.0, 1, count, 20000, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(8, 0, enemy.x, fireY, enemy.secondaryAngle16, 0.0f,
                                      baseSpeed + ramp - 2.0, 1, count, 20000, 0);
            }
        }
        enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, fireAim, 0x20);
        return;
    }
    if (enemy.spawnType == 0x3d) {
        if (enemy.helperState != 1) {
            return;
        }

        const bool entryFromLeft = enemy.originX < 360.0f;
        const float fireX = enemy.x + (entryFromLeft ? 180.0f : -180.0f);
        const float fireY = enemy.y + 33.0f;
        const float horizontalOrigin = player_.x / 6.0f;
        if (fireX < horizontalOrigin || fireX > horizontalOrigin + 600.0f ||
            fireY < 0.0f || fireY > 720.0f) {
            return;
        }

        const auto aim = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y) - static_cast<double>(fireY),
            static_cast<double>(player_.x) - static_cast<double>(fireX)));
        const int halfCycle = kStage04Type3DHalfCycle[static_cast<std::size_t>(difficulty)];
        const double baseSpeed = kStage04Type3DSpeed[static_cast<std::size_t>(difficulty)];
        const int count = kStage04Type3DCount[static_cast<std::size_t>(difficulty)];
        const int spread = (count - 1) * 360;
        const int timer = enemy.helperTimer;
        const auto fan = [&](int angleOffset, double speed) {
            spawnProjectileSpread(5, 0, fireX, fireY,
                                  normalizeAngle16(static_cast<int>(aim) + angleOffset),
                                  0.0f, speed, 1, count, spread, 0);
        };

        if (timer >= 32 && (timer - 32) % (halfCycle * 2) == 0) {
            fan(0, baseSpeed);
            fan(7000, baseSpeed);
            fan(-7000, baseSpeed);
            if (difficulty > 2) {
                fan(3500, baseSpeed - 1.2);
                fan(-3500, baseSpeed - 1.2);
            }
        }
        if (timer >= halfCycle + 32 &&
            (timer - (halfCycle + 32)) % (halfCycle * 2) == 0) {
            fan(3500, baseSpeed);
            fan(-3500, baseSpeed);
            if (difficulty > 2) {
                fan(0, baseSpeed - 1.2);
                fan(7000, baseSpeed - 1.2);
                fan(-7000, baseSpeed - 1.2);
            }
        }
        return;
    }
    if (enemy.spawnType == 0x3e) {
        if (enemy.helperState != 1) {
            return;
        }
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.x < horizontalOrigin - 30.0f || enemy.x > horizontalOrigin + 630.0f ||
            enemy.y < -30.0f || enemy.y > 750.0f) {
            return;
        }

        const StageEnemy* owner = findEnemyById(enemy.parentEntityId);
        const int ownerId = owner != nullptr ? owner->entityId : 0;
        const int phase = 30 + (ownerId - enemy.entityId) * 12;
        const int timer = enemy.helperTimer;
        const int interval = kStage04Type3EInterval[static_cast<std::size_t>(difficulty)];
        if (timer < phase || (timer - phase) % interval != 0) {
            return;
        }

        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        const float emitX = enemy.x + static_cast<float>(std::cos(radians) * 55.0);
        const float emitY = enemy.y + static_cast<float>(std::sin(radians) * 55.0);
        const double baseSpeed = kStage04Type3ESpeed[static_cast<std::size_t>(difficulty)];
        const auto shot = [&](double speed) {
            spawnProjectileNode(6, 0, emitX, emitY, enemy.sourceAngle16,
                                10.0f, speed, 1, 0);
        };
        shot(baseSpeed);
        shot(baseSpeed + 0.4);
        if (difficulty > 2) {
            shot(baseSpeed + 2.0);
            shot(baseSpeed + 2.4);
        }
        return;
    }
    if (enemy.spawnType == 0x3f) {
        if (enemy.helperState != 1) {
            return;
        }

        const int timer = enemy.helperTimer;
        if (timer < 900) {
            const auto centerAim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y) - static_cast<double>(enemy.y + 150.0f),
                static_cast<double>(player_.x) - static_cast<double>(enemy.x)));
            const int halfCycle = kStage04Type3FAlternatingHalfCycle[static_cast<std::size_t>(difficulty)];
            const int window = kStage04Type3FAlternatingWindow[static_cast<std::size_t>(difficulty)];
            const double alternatingSpeed =
                kStage04Type3FAlternatingSpeed[static_cast<std::size_t>(difficulty)];
            constexpr std::array<float, 4> kEmitterOffsetX{{90.0f, -90.0f, 160.0f, -160.0f}};
            constexpr std::array<float, 4> kEmitterOffsetY{{170.0f, 170.0f, 117.0f, 117.0f}};

            for (std::size_t emitter = 0; emitter < kEmitterOffsetX.size(); ++emitter) {
                int phase = -1;
                if (emitter < 2) {
                    phase = timer % (halfCycle * 2);
                }
                else if (timer >= halfCycle) {
                    phase = (timer - halfCycle) % (halfCycle * 2);
                }
                if (phase < 0 || phase >= window || phase % 3 != 0) {
                    continue;
                }

                const float emitX = enemy.x + kEmitterOffsetX[emitter];
                const float emitY = enemy.y + kEmitterOffsetY[emitter];
                int baseAngle = static_cast<int>(enemy.secondaryAngle16);
                if (player_.y < emitY) {
                    baseAngle -= 0x8000;
                }
                const auto shot = [&](int offset, double speed) {
                    spawnProjectileNode(7, 0, emitX, emitY,
                                        normalizeAngle16(baseAngle + offset),
                                        10.0f, speed, 1, 0);
                };
                for (int i = 0; i < 3; ++i) {
                    shot(i * 9000 - 9000, alternatingSpeed);
                }
                if (difficulty > 2) {
                    for (int i = 0; i < 3; ++i) {
                        shot(i * 9000 - 0x2134, alternatingSpeed - 0.5);
                    }
                    for (int i = 0; i < 3; ++i) {
                        shot(i * 9000 - 0x251c, alternatingSpeed - 0.5);
                    }
                }
            }
            enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, centerAim, 0x10);

            const auto lowerAim = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y) - static_cast<double>(enemy.y + 220.0f),
                static_cast<double>(player_.x) - static_cast<double>(enemy.x)));
            const int jitterOffset = timer - 60;
            if (jitterOffset >= 0 && jitterOffset < 360) {
                const int windowPhase = jitterOffset % 90;
                if (windowPhase == 0) {
                    enemy.targetAngle16 = lowerAim;
                }
                const int interval = kStage04Type3FJitterInterval[static_cast<std::size_t>(difficulty)];
                if (windowPhase <= 49 && windowPhase % interval == 0) {
                    const int jitter = static_cast<int>(stageScriptRandFromFrame(frame_) % 6001u) - 3000;
                    const double speed = static_cast<double>(timer) * 0.005 +
                                         kStage04Type3FJitterSpeed[static_cast<std::size_t>(difficulty)];
                    const auto jitterShot = [&](int offset, double shotSpeed) {
                        spawnProjectileNode(4, 0, enemy.x, enemy.y,
                                            normalizeAngle16(static_cast<int>(enemy.targetAngle16) +
                                                             jitter + offset),
                                            10.0f, shotSpeed, 1, 0);
                    };
                    jitterShot(0, speed);
                    if (difficulty == 3) {
                        jitterShot(0, speed + 1.2);
                    }
                    else if (difficulty == 4) {
                        // The original adds raw (rng % 6001) to -5777/+(-222).
                        // Relative to `jitter == raw - 3000`, these are -2777/+2778.
                        jitterShot(-0x0ad9, speed);
                        jitterShot(0x0ada, speed);
                    }
                }
            }

            const int fanOffset = timer - 450;
            const int fanInterval = kStage04Type3FFanInterval[static_cast<std::size_t>(difficulty)];
            if (fanOffset >= 0 && fanOffset < 450 && fanOffset % fanInterval == 0) {
                const double speed = static_cast<double>(fanOffset) * 0.01 +
                                     kStage04Type3FFanSpeed[static_cast<std::size_t>(difficulty)];
                const int count = kStage04Type3FFanCount[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(2, 0, enemy.x, enemy.y, lowerAim,
                                      10.0f, speed, 1, count, 0x8000, 0);
                if (difficulty > 2) {
                    spawnProjectileSpread(2, 0, enemy.x, enemy.y, lowerAim,
                                          10.0f, speed + 1.2, 1, count, 0x8000, 0);
                }
            }
        }

        return;
    }
    if (isStage04CarrierFamily(enemy.spawnType)) {
        StageEnemy* owner = enemy.spawnType >= 0x3b ? findEnemyById(enemy.parentEntityId) : nullptr;
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperState == 1 &&
            enemy.x >= horizontalOrigin - 10.0f && enemy.x <= horizontalOrigin + 610.0f &&
            enemy.y >= -10.0f && enemy.y <= 730.0f) {
            const std::uint16_t aim = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            if (enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) {
                const int interval = kStage04CarrierInterval[static_cast<std::size_t>(difficulty)];
                const int count = kStage04CarrierCount[static_cast<std::size_t>(difficulty)];
                if (enemy.helperTimer >= 0 && enemy.helperTimer % interval == 0) {
                    spawnProjectileSpread(3, 1, enemy.x, enemy.y, aim, 10.0f, 1.2, 1, count, 22000, 0);
                    if (difficulty > 2) {
                        const int secondaryCount = count - 1;
                        const int secondarySpread = (22000 / secondaryCount) * (secondaryCount - 1);
                        spawnProjectileSpread(3, 1, enemy.x, enemy.y, aim, 10.0f, 0.2, 1,
                                              secondaryCount, secondarySpread, 0);
                    }
                }
            }
            else if (enemy.spawnType == 0x3b && owner != nullptr) {
                const int ownerTimer = owner->helperTimer;
                const int interval = kStage04CarrierChildInterval[static_cast<std::size_t>(difficulty)];
                if (ownerTimer >= 0 && ownerTimer % interval == 0) {
                    const double speed = kStage04CarrierChildSpeed[static_cast<std::size_t>(difficulty)];
                    spawnProjectileNode(8, 0, enemy.x, enemy.y, aim, 10.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(8, 0, enemy.x, enemy.y, aim, 10.0f, speed + 1.8, 1, 0);
                    }
                }
            }
        }

        if (enemy.helperState == 1 && (enemy.spawnType == 0x39 || enemy.spawnType == 0x3a)) {
            const int timerFromFirstChild = enemy.helperTimer - 40;
            if (timerFromFirstChild >= 0 && timerFromFirstChild < 320 && timerFromFirstChild % 40 == 0) {
                spawnStage04CarrierChild(enemy, 0x3b);
            }
            if (enemy.helperTimer == 360) {
                spawnStage04CarrierChild(enemy, 0x3c);
            }
        }

        finishStage04CarrierSharedHp(enemy);
        return;
    }
}

void StageRuntime::finishStage04CarrierSharedHp(StageEnemy& enemy) {
    const bool child = enemy.spawnType == 0x3b || enemy.spawnType == 0x3c;
    StageEnemy* owner = child ? findEnemyById(enemy.parentEntityId) : nullptr;

    if (child && enemy.helperState == 1 && owner != nullptr) {
        const int ownerHpAtEntry = owner->hp;
        if (enemy.hp < ownerHpAtEntry) {
            owner->hp -= ownerHpAtEntry - enemy.hp;
        }
        if (ownerHpAtEntry < enemy.hp) {
            enemy.hp = ownerHpAtEntry;
        }
        if (enemy.hp < 1) {
            owner->hp -= ownerHpAtEntry;
        }
        if (ownerHpAtEntry < 1) {
            enemy.targetable = false;
            const int ownerTimer = owner->helperTimer;
            enemy.helperTimer = 100 - (ownerTimer - enemy.helperTimer) / 8;
            ++enemy.helperState;
        }
    }
    else if (!child && enemy.helperState == 1 && enemy.hp < 1) {
        enemy.targetable = false;
        spawnEnemyDeathRewardBurst(enemy, 1000);
        ++enemy.helperState;
    }

    if (child && enemy.helperState == 2 && enemy.helperTimer == 100) {
        spawnEnemyDeathRewardBurst(enemy, 1000);
        enemy.active = false;
    }
    if (enemy.helperTimer == 1000 || (child && (owner == nullptr || !owner->active))) {
        enemy.active = false;
    }
}

void StageRuntime::updateProjectiles() {
    // The original walks a linked list whose tail can grow during the walk, so
    // children appended by a helper are eligible for update later in this same
    // frame. Reserving the hard 0x800-node cap keeps references stable here.
    for (std::size_t i = 0; i < enemyProjectiles_.size(); ++i) {
        auto& projectile = enemyProjectiles_[i];
        projectile.drawQueuedThisFrame = false;
        if (!projectile.active) {
            continue;
        }
        projectile.drawAge = projectile.age;
        // FUN_14006c620 uses 0x4f for the three entrance-speed families.
        // FUN_14006ce40 promotes its emitter families to 0x51; all remaining
        // enemy projectile helpers queue the base sprite at 0x50.
        switch (projectile.projectileId) {
        case 0x03:
        case 0x04:
        case 0x05:
            projectile.drawLayer = 0x4f;
            break;
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x2f:
        case 0x30:
        case 0x32:
        case 0x3c:
            projectile.drawLayer = 0x51;
            break;
        default:
            projectile.drawLayer = 0x50;
            break;
        }
        bool helperQueuedDraw = false;
        switch (projectile.projectileId) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        case 0x05:
        case 0x06:
        case 0x07:
        case 0x09:
        case 0x0a:
        case 0x0b:
        case 0x0d:
        case 0x0f:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x16:
            updateProjectileCommonMotion(projectile);
            helperQueuedDraw = true;
            break;
        case 0x08:
            updateProjectileReflectOnBoundary(projectile);
            helperQueuedDraw = true;
            break;
        case 0x0c:
        case 0x0e:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x2c:
        case 0x2d:
        case 0x35:
        case 0x36:
            updateProjectileHomingSteering(projectile);
            helperQueuedDraw = true;
            break;
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x21:
        case 0x22:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3c:
            updateProjectileScriptedEmitter(projectile);
            helperQueuedDraw = true;
            break;
        case 0x1f:
        case 0x20:
            updateProjectileOrbitArcPair(projectile);
            helperQueuedDraw = true;
            break;
        case 0x3a:
        case 0x3b:
            updateProjectileExpandingSpiralPair(projectile);
            helperQueuedDraw = true;
            break;
        case 0x13:
        case 0x15:
            if (projectile.age == 0) {
                projectile.grazeOrHitProcessed = true;
                projectile.collisionEnabled = false;
            }
            else if (projectile.age == 1) {
                projectile.active = false;
            }
            break;
        case 0x14:
            if (projectile.age == 0) {
                projectile.grazeOrHitProcessed = true;
                projectile.collisionEnabled = false;
            }
            else if (projectile.age == 3) {
                projectile.active = false;
            }
            break;
        default:
            projectile.active = false;
            break;
        }
        projectile.drawQueuedThisFrame = helperQueuedDraw;
        if (helperQueuedDraw) {
            // FUN_140070250 appends these selector-owned afterimages before its
            // base projectile draw. They enter the effect list after that
            // list's update pass, so their first visible update is next frame.
            if (projectile.visualSelector == 0x13 ||
                projectile.visualSelector == 0x14) {
                const bool clockwise = projectile.visualSelector == 0x14;
                const int overlayIndex = clockwise ? 118 : 117;
                const int handle = overlayIndex < static_cast<int>(enemySmallFrames_.size())
                                       ? enemySmallFrames_[static_cast<std::size_t>(overlayIndex)]
                                       : -1;
                const int direction = clockwise ? 1 : -1;
                spawnStageEffect(clockwise ? 0x07 : 0x05,
                                 handle, 100, 0x22, projectile.x, projectile.y,
                                 normalizeAngle16(direction * projectile.drawAge * 0x457),
                                 0.0, 1.0, 1.0, 0x10,
                                 0xff, 0xff, 0xff, 0x60);
            }

            int trailLayer = -1;
            switch (projectile.projectileId) {
            case 0x1a:
            case 0x1b:
            case 0x1c:
            case 0x1d:
            case 0x1e:
            case 0x32:
            case 0x3c:
                trailLayer = 0x4f;
                break;
            case 0x29:
            case 0x2a:
            case 0x2b:
            case 0x2e:
                trailLayer = 0x4e;
                break;
            default:
                break;
            }
            if (trailLayer >= 0) {
                const int frameIndex = bulletFrameForVisualSelector(projectile.visualSelector);
                const int handle = frameIndex < static_cast<int>(bulletFrames_.size())
                                       ? bulletFrames_[static_cast<std::size_t>(frameIndex)]
                                       : -1;
                const auto scale = projectileScaleForVisualSelector(
                    projectile.visualSelector, projectile.drawAge);
                const std::uint16_t drawAngle = projectileDrawAngleForVisualSelector(
                    projectile.visualSelector, projectile.drawAge, projectile.angle16);
                spawnStageEffect(0x05, handle, 60, trailLayer,
                                 projectile.x, projectile.y, drawAngle,
                                 0.0, scale[0], scale[1], 0x0c,
                                 0xff, 0xff, 0xff, 0x40);
            }
        }
        // The state-0x14 dispatcher calls the selected helper with the current
        // age and increments +0x04 afterwards (1400bca30 lines 758-853).
        ++projectile.age;
    }
}

void StageRuntime::updateProjectileCommonMotion(StageProjectile& projectile) {
    // FUN_14006c620 keeps x/y as a segment anchor and +0x20 as accumulated
    // travel. Each frame first adds the current double speed at +0x28, computes
    // the visible/collision point, then updates speed for the following frame.
    projectile.speedOrAccelHint += static_cast<float>(projectile.speed);
    const double motionAngle = fixedAngleToRadiansDouble(projectile.angle16);
    const float nextX = projectile.anchorX + static_cast<float>(
        std::cos(motionAngle) * static_cast<double>(projectile.speedOrAccelHint));
    const float nextY = projectile.anchorY + static_cast<float>(
        std::sin(motionAngle) * static_cast<double>(projectile.speedOrAccelHint));
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    switch (projectile.projectileId) {
    case 0x01:
        projectile.speed += kProjectileId1Acceleration[static_cast<std::size_t>(difficulty)];
        break;
    case 0x02:
        if (projectile.age == 0) {
            projectile.speed = 0.1 + projectile.baseSpeed / 30.0;
        }
        else if (projectile.age <= 0x1e) {
            projectile.speed += projectile.baseSpeed / 30.0;
        }
        break;
    case 0x03:
        if (projectile.age == 0) {
            projectile.speed = 0.1;
        }
        else if (projectile.age >= 0x1e && projectile.age <= 0x5a) {
            projectile.speed += projectile.baseSpeed / 60.0;
        }
        break;
    case 0x04:
        if (projectile.age == 0) {
            projectile.speed = 0.1;
        }
        else if (projectile.age >= 0x0c && projectile.age <= 0x48) {
            projectile.speed += projectile.baseSpeed / 60.0;
        }
        break;
    case 0x05:
        if (projectile.age == 0) {
            projectile.speed = projectile.baseSpeed * 0.5;
        }
        else if (projectile.age >= 0x3c && projectile.age <= 0x78) {
            projectile.speed += projectile.baseSpeed / 120.0;
        }
        break;
    case 0x06:
        if (projectile.age == 0) {
            projectile.baseSpeed = projectile.speed / 5.0;
        }
        if (projectile.age <= 0x1e && projectile.baseSpeed < projectile.speed) {
            projectile.speed -= projectile.baseSpeed / 6.0;
        }
        break;
    case 0x07:
        if (projectile.age < 0x28) {
            projectile.speed -= projectile.baseSpeed / 40.0;
        }
        else if (projectile.age <= 99) {
            projectile.speed += projectile.baseSpeed / 60.0;
        }
        break;
    case 0x09:
        if (projectile.age < 0x1e) {
            projectile.speed -= projectile.baseSpeed / 30.0;
        }
        else {
            if (projectile.age == 0x1e) {
                projectile.anchorX = nextX;
                projectile.anchorY = nextY;
                projectile.angle16 = radiansToFixedAngleTrunc(
                    std::atan2(static_cast<double>(player_.y - nextY),
                               static_cast<double>(player_.x - nextX)));
                projectile.speedOrAccelHint = 0.0f;
            }
            projectile.prevAngle16 = projectile.angle16;
            projectile.speed += kProjectileRetargetAcceleration[static_cast<std::size_t>(difficulty)];
        }
        break;
    case 0x0a:
        if (projectile.age < 0x28) {
            const double startSpeed = projectile.baseSpeed * 1.8;
            projectile.speed = startSpeed - (startSpeed / 40.0) * projectile.age;
        }
        else if (projectile.age == 0x28) {
            projectile.anchorX = nextX;
            projectile.anchorY = nextY;
            projectile.angle16 = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(player_.y - projectile.prevY),
                           static_cast<double>(player_.x - projectile.prevX)));
            projectile.prevAngle16 = projectile.angle16;
            projectile.speedOrAccelHint = 0.0f;
            projectile.speed = projectile.baseSpeed / 60.0;
        }
        else if (projectile.age <= 99) {
            projectile.speed += projectile.baseSpeed / 60.0;
        }
        break;
    case 0x0b:
        if (projectile.age < 0x32) {
            projectile.speed -= projectile.baseSpeed / 50.0;
        }
        else {
            if (projectile.age == 0x32) {
                projectile.anchorX = nextX;
                projectile.anchorY = nextY;
                projectile.angle16 = radiansToFixedAngleTrunc(
                    std::atan2(static_cast<double>(player_.y - (projectile.prevY - 200.0f)),
                               static_cast<double>(player_.x - projectile.prevX)));
                projectile.prevAngle16 = projectile.angle16;
                projectile.speedOrAccelHint = 0.0f;
                projectile.speed = 0.0;
            }
            projectile.speed += 0.07;
        }
        break;
    case 0x0d:
        if (projectile.age > 0x17) {
            projectile.speed += kProjectileId13Acceleration[static_cast<std::size_t>(difficulty)];
        }
        if (nextX >= horizontalOrigin - 30.0f && nextX <= horizontalOrigin + 630.0f &&
            nextY >= -30.0f && nextY <= 750.0f) {
            // Original call order is (visual selector 4, movement id 0x0f).
            spawnProjectileNode(4, 0x0f, nextX, nextY, projectile.angle16,
                                0.0f, 0.0, projectile.radius, 0);
        }
        break;
    case 0x0f:
        if (projectile.age == 0x14) projectile.active = false;
        break;
    case 0x10:
        if (projectile.age == 0x28) projectile.active = false;
        break;
    case 0x11:
        if (projectile.age == 10) projectile.active = false;
        break;
    case 0x12:
        if (projectile.age == 0x3c) {
            spawnProjectileTerminalEffect(nextX, nextY);
            projectile.active = false;
        }
        break;
    default:
        break;
    }

    // fVar20/fVar17 are the point drawn and boundary-tested this frame even
    // when a retarget case has just committed a new anchor for the next frame.
    projectile.x = nextX;
    projectile.y = nextY;
    projectile.angle = fixedAngleToRadians(projectile.angle16);
    projectile.vx = std::cos(motionAngle) * static_cast<float>(projectile.speed);
    projectile.vy = std::sin(motionAngle) * static_cast<float>(projectile.speed);
    if (nextX < horizontalOrigin - 30.0f || nextX > horizontalOrigin + 630.0f ||
        nextY < -30.0f || nextY > 750.0f) {
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileReflectOnBoundary(StageProjectile& projectile) {
    // FUN_14006faa0 uses the same anchor + accumulated-travel representation
    // as the common helper. Crossing left/right or the top creates a behavior-0
    // replacement; the bottom is an exit, not a reflecting wall.
    projectile.speedOrAccelHint += static_cast<float>(projectile.speed);
    const double angleRadians = fixedAngleToRadiansDouble(projectile.angle16);
    const float nextX = projectile.anchorX + static_cast<float>(
        std::cos(angleRadians) * static_cast<double>(projectile.speedOrAccelHint));
    const float nextY = projectile.anchorY + static_cast<float>(
        std::sin(angleRadians) * static_cast<double>(projectile.speedOrAccelHint));
    projectile.x = nextX;
    projectile.y = nextY;

    const float radius = static_cast<float>(projectile.radius);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const bool outsideTrigger = nextX < horizontalOrigin - radius ||
                                nextX > horizontalOrigin + 600.0f + radius ||
                                nextY < -radius || nextY > 720.0f + radius;
    if (outsideTrigger) {
        int reflectedAngle = projectile.angle16;
        if (nextX < horizontalOrigin || nextX > horizontalOrigin + 600.0f) {
            reflectedAngle = -0x8000 - static_cast<int>(projectile.angle16);
        }
        if (nextY < 0.0f) {
            reflectedAngle = -static_cast<int>(projectile.angle16);
        }
        projectile.angle16 = normalizeAngle16(reflectedAngle);
        projectile.angle = fixedAngleToRadians(projectile.angle16);
        spawnProjectileNode(projectile.visualSelector, 0, nextX, nextY,
                            projectile.angle16, 0.0f,
                            projectile.speed, projectile.radius, 0);
        projectile.active = false;
    }
    if (nextX < horizontalOrigin - 30.0f || nextX > horizontalOrigin + 630.0f ||
        nextY < -30.0f || nextY > 750.0f) {
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileHomingSteering(StageProjectile& projectile) {
    // FUN_14006ecf0 aims from the pre-move point, integrates with the old
    // heading/speed, and only then mutates state for the following frame.
    const std::uint16_t target = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(player_.y - projectile.y),
                   static_cast<double>(player_.x - projectile.x)));
    const double oldAngle = fixedAngleToRadiansDouble(projectile.angle16);
    projectile.prevX = projectile.x;
    projectile.prevY = projectile.y;
    projectile.x += static_cast<float>(std::cos(oldAngle) * projectile.speed);
    projectile.y += static_cast<float>(std::sin(oldAngle) * projectile.speed);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const bool inCommonRect = projectile.x >= horizontalOrigin - 30.0f &&
                              projectile.x <= horizontalOrigin + 630.0f &&
                              projectile.y >= -30.0f && projectile.y <= 750.0f;

    switch (projectile.projectileId) {
    case 0x0c: {
        if (projectile.age < 60) {
            if (projectile.age == 0) {
                projectile.speed = 8.0;
            }
            if (projectile.speed > 1.4) {
                projectile.speed -= 0.11;
            }
            projectile.angle16 = approachAngle16(projectile.angle16, target, 0x29a);
        }
        else {
            if (projectile.age == 60) {
                projectile.speed = projectile.baseSpeed + 0.1;
            }
            else {
                projectile.speed += 0.1;
            }
            projectile.angle16 = approachAngle16(
                projectile.angle16, target,
                kHoming12Turn[static_cast<std::size_t>(difficulty)]);
        }
        if (inCommonRect) {
            spawnProjectileNode(4, 0x0f, projectile.x, projectile.y,
                                projectile.angle16, 0.0f, 0.0,
                                projectile.radius, 0);
        }
        break;
    }
    case 0x0e: {
        const double phase = (projectile.age + 30) * static_cast<double>(kTau) / 120.0;
        int turnStep = 200;
        if (projectile.age < 240) {
            projectile.speed = (projectile.baseSpeed + 3.0) * 0.5 +
                               std::sin(phase) * (projectile.baseSpeed - 3.0) * 0.5;
            const int baseTurn = kHoming14BaseTurn[static_cast<std::size_t>(difficulty)];
            turnStep = projectile.age < 30
                           ? baseTurn + 500
                           : baseTurn + 300 - static_cast<int>(std::sin(phase) * 300.0);
        }
        else {
            projectile.speed += 0.1;
        }
        projectile.angle16 = approachAngle16(projectile.angle16, target, turnStep);
        if (inCommonRect) {
            spawnProjectileNode(5, 0x0f, projectile.x, projectile.y,
                                projectile.angle16, 0.0f, 0.0,
                                projectile.radius, 0);
        }
        break;
    }
    case 0x23:
    case 0x24: {
        if (projectile.projectileId == 0x24 && projectile.age == 0) {
            projectile.x = clampFloat(projectile.x, horizontalOrigin - 30.0f,
                                      horizontalOrigin + 630.0f);
            projectile.y = clampFloat(projectile.y, -30.0f, 750.0f);
        }
        const int interval = kEmitter23Interval[static_cast<std::size_t>(difficulty)];
        if (projectile.age % interval == 0 && projectile.x >= horizontalOrigin &&
            projectile.x <= horizontalOrigin + 600.0f &&
            projectile.y >= 0.0f && projectile.y <= 720.0f) {
            const int spread = projectile.projectileId == 0x23 ? 0x7448 : 0x85dc;
            const double speed = kEmitter23Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(8, 3, projectile.x, projectile.y,
                                  projectile.angle16, 0.0f, speed,
                                  projectile.radius, 2, spread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(8, 3, projectile.x, projectile.y,
                                      projectile.angle16, 0.0f, speed + 1.5,
                                      projectile.radius, 2, spread, 0);
            }
        }
        if (inCommonRect) {
            spawnProjectileNode(5, 0x0f, projectile.x, projectile.y,
                                projectile.angle16, 0.0f, 0.0, 1, 0);
        }
        projectile.speed += 0.1;
        break;
    }
    case 0x25:
        if (inCommonRect) {
            spawnProjectileNode(4, 0x0f, projectile.x, projectile.y,
                                projectile.angle16, 0.0f, 0.0,
                                projectile.radius, 0);
        }
        if (difficulty > 2) {
            projectile.angle16 = approachAngle16(projectile.angle16, target, 0xa0);
        }
        projectile.speed += 0.1;
        break;
    case 0x26:
    case 0x27: {
        const int direction = projectile.projectileId == 0x26 ? -1 : 1;
        if (inCommonRect) {
            spawnProjectileNode(projectile.projectileId == 0x26 ? 5 : 4, 0x0f,
                                projectile.x, projectile.y, projectile.angle16,
                                0.0f, 0.0, projectile.radius, 0);
        }
        projectile.angle16 = normalizeAngle16(
            static_cast<int>(projectile.angle16) +
            direction * kCurve26Turn[static_cast<std::size_t>(difficulty)]);
        projectile.speed += 0.05;
        break;
    }
    case 0x2c:
    case 0x2d: {
        const int direction = projectile.projectileId == 0x2c ? -1 : 1;
        projectile.angle16 = normalizeAngle16(
            static_cast<int>(projectile.angle16) +
            direction * kCurve2CTurn[static_cast<std::size_t>(difficulty)]);
        projectile.speed += 0.05;
        break;
    }
    case 0x35:
    case 0x36:
        if (projectile.age < 90) {
            const int direction = projectile.projectileId == 0x35 ? 1 : -1;
            projectile.angle16 = normalizeAngle16(static_cast<int>(projectile.angle16) + direction * 0x5a);
            projectile.speed += 0.05;
        }
        break;
    default:
        break;
    }

    projectile.angle = fixedAngleToRadians(projectile.angle16);
    projectile.vx = std::cos(projectile.angle) * static_cast<float>(projectile.speed);
    projectile.vy = std::sin(projectile.angle) * static_cast<float>(projectile.speed);
    if (projectile.x < horizontalOrigin - 250.0f ||
        projectile.x > horizontalOrigin + 850.0f ||
        projectile.y < -250.0f || projectile.y > 970.0f) {
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileScriptedEmitter(StageProjectile& projectile) {
    // FUN_14006ce40 shares the common helper's anchor + radial travel pre-step.
    projectile.speedOrAccelHint += static_cast<float>(projectile.speed);
    const double angleRadians = fixedAngleToRadiansDouble(projectile.angle16);
    float drawX = projectile.anchorX + static_cast<float>(
        std::cos(angleRadians) * static_cast<double>(projectile.speedOrAccelHint));
    float drawY = projectile.anchorY + static_cast<float>(
        std::sin(angleRadians) * static_cast<double>(projectile.speedOrAccelHint));
    projectile.x = drawX;
    projectile.y = drawY;
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto angleToPoint = [](float fromX, float fromY, float targetX, float targetY) {
        const float deltaY = targetY - fromY;
        const float deltaX = targetX - fromX;
        return radiansToFixedAngleTrunc(std::atan2(static_cast<double>(deltaY),
                                                   static_cast<double>(deltaX)));
    };

    switch (projectile.projectileId) {
    case 0x17:
        if (projectile.age == 25) {
            spawnProjectileNode(3, 1, drawX, drawY,
                                angleToPoint(drawX, drawY, player_.x, player_.y),
                                0.0f, 2.0, projectile.radius, 0);
        }
        break;
    case 0x18:
    case 0x19: {
        const int endAge = 16 + kScript18Window[static_cast<std::size_t>(difficulty)];
        if (projectile.age >= 16 && projectile.age < endAge && (projectile.age & 1) == 0) {
            const bool clockwise = projectile.projectileId == 0x19;
            const int childVisual = clockwise ? 0x0d : 0x0c;
            const int offset = clockwise
                                   ? projectile.age * 200 + 0x36a0
                                   : -projectile.age * 200 - 0x36a0;
            spawnProjectileNode(childVisual, 1, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + offset),
                                0.0f, 1.5, projectile.radius, 0);
        }
        if (projectile.age == endAge) {
            spawnProjectileTerminalEffect(drawX, drawY);
            projectile.active = false;
        }
        break;
    }
    case 0x1a:
    case 0x1b: {
        const int interval = kScript1AInterval[static_cast<std::size_t>(difficulty)];
        if (projectile.age % interval == 0 && drawX >= horizontalOrigin &&
            drawX <= horizontalOrigin + 600.0f && drawY >= 0.0f && drawY <= 720.0f) {
            const bool mirrored = projectile.projectileId == 0x1b;
            const int childVisual = mirrored ? 9 : 8;
            const int childAngle = mirrored
                                       ? static_cast<int>(projectile.angle16) + projectile.age * 250 - 30000
                                       : static_cast<int>(projectile.angle16) + (120 - projectile.age) * 250;
            const double speed = kScript1ASpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(childVisual, 2, drawX, drawY, normalizeAngle16(childAngle),
                                0.0f, speed, projectile.radius, 0);
            if (difficulty > 2) {
                spawnProjectileNode(childVisual, 2, drawX, drawY, normalizeAngle16(childAngle),
                                    0.0f, speed + 1.5, projectile.radius, 0);
            }
        }
        break;
    }
    case 0x1c: {
        const int period = kScript1CPeriod[static_cast<std::size_t>(difficulty)];
        const int window = kScript1CWindow[static_cast<std::size_t>(difficulty)];
        const int halfPhase = (projectile.age + frame_) / 2;
        const int phase = halfPhase % period;
        if (halfPhase >= 0 && phase < window && drawX >= horizontalOrigin &&
            drawX <= horizontalOrigin + 600.0f && drawY >= 0.0f && drawY <= 720.0f) {
            const double speed = kScript1CSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(9, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) - 0x4000),
                                0.0f, speed, projectile.radius, 0);
            spawnProjectileNode(9, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + 0x4000),
                                0.0f, speed, projectile.radius, 0);
        }
        break;
    }
    case 0x1d:
    case 0x1e: {
        constexpr double kWaveAngleScale = 992.969696969697;
        constexpr double kFixedAngleToRadiansScale = 3.0517578125e-05;
        constexpr double kPiDouble = 3.14159265358979;
        const double waveAngle = static_cast<double>(frame_ * 2) *
                                 kWaveAngleScale * kPiDouble * kFixedAngleToRadiansScale;
        const float lateralTravel = static_cast<float>(
            std::sin(waveAngle) * static_cast<double>(static_cast<float>(projectile.age)));
        const int lateralOffset = projectile.projectileId == 0x1d ? -0x4000 : 0x4000;
        const std::uint16_t lateralAngle16 = normalizeAngle16(
            static_cast<int>(projectile.angle16) + lateralOffset);
        const double lateralAngle = static_cast<double>(lateralAngle16) *
                                    kPiDouble * kFixedAngleToRadiansScale;
        drawX += static_cast<float>(std::cos(lateralAngle) * static_cast<double>(lateralTravel));
        drawY += static_cast<float>(std::sin(lateralAngle) * static_cast<double>(lateralTravel));
        projectile.x = drawX;
        projectile.y = drawY;

        const int interval = kScript1DInterval[static_cast<std::size_t>(difficulty)];
        const int halfPhase = (projectile.age + frame_) / 2;
        const int cycle = interval * 2;
        const bool inPlayfield = drawX >= horizontalOrigin &&
                                 drawX <= horizontalOrigin + 600.0f &&
                                 drawY >= 0.0f && drawY <= 720.0f;
        const double childSpeed = kScript1DSpeed[static_cast<std::size_t>(difficulty)];
        if (halfPhase >= 0 && halfPhase % cycle == 0 && inPlayfield) {
            spawnProjectileNode(0x0d, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + 0x4000),
                                0.0f, childSpeed, projectile.radius, 0);
        }
        if (halfPhase >= interval && (halfPhase - interval) % cycle == 0 && inPlayfield) {
            spawnProjectileNode(0x0d, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) - 0x4000),
                                0.0f, childSpeed, projectile.radius, 0);
        }
        break;
    }
    case 0x21:
    case 0x22:
        if (projectile.age == 36) {
            const int offset = projectile.projectileId == 0x21 ? 12000 : -12000;
            spawnProjectileNode(2, 4, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + offset),
                                0.0f, projectile.baseSpeed + 1.2, projectile.radius, 0);
        }
        break;
    case 0x28: {
        const StageEnemy* parent = findEnemyById(projectile.arg8OrAux);
        if (parent != nullptr) {
            const int phase = (parent->helperTimer - 60) % 1400;
            if (phase == 870 || phase == 1020) {
                const double childSpeed = projectile.baseSpeed - 1.0;
                spawnProjectileNode(8, 4, drawX, drawY,
                                    normalizeAngle16(static_cast<int>(projectile.angle16) - 9000),
                                    0.0f, childSpeed, projectile.radius, 0);
                spawnProjectileNode(8, 4, drawX, drawY,
                                    normalizeAngle16(static_cast<int>(projectile.angle16) + 9000),
                                    0.0f, childSpeed, projectile.radius, 0);
            }
        }
        break;
    }
    case 0x29:
    case 0x2a: {
        const int interval = kScript29Interval[static_cast<std::size_t>(difficulty)];
        if (projectile.age >= 0 && projectile.age % interval == 0 &&
            drawX >= horizontalOrigin &&
            drawX <= horizontalOrigin + 600.0f && drawY >= 0.0f && drawY <= 720.0f) {
            const bool reverse = projectile.projectileId == 0x2a;
            const int angleOffset = reverse
                                        ? -projectile.age * 200 + 24000
                                        : projectile.age * 200 - 24000;
            spawnProjectileNode(reverse ? 9 : 8, 4, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + angleOffset),
                                0.0f, kScript29Speed[static_cast<std::size_t>(difficulty)],
                                projectile.radius, 0);
        }
        break;
    }
    case 0x2b:
        if (projectile.age == 0) {
            projectile.prevX = player_.x;
            projectile.prevY = player_.y;
        }
        if (projectile.age >= 0 && projectile.age <= 35 && projectile.age % 3 == 0 &&
            drawX >= horizontalOrigin && drawX <= horizontalOrigin + 600.0f &&
            drawY >= 0.0f && drawY <= 720.0f) {
            const std::uint16_t targetAngle = angleToPoint(
                drawX, drawY, projectile.prevX, projectile.prevY);
            spawnProjectileSpread(0x0c, 4, drawX, drawY, targetAngle, 0.0f,
                                  kScript2BSpeed[static_cast<std::size_t>(difficulty)],
                                  projectile.radius,
                                  kScript2BCount[static_cast<std::size_t>(difficulty)],
                                  20000, 0);
        }
        break;
    case 0x2e:
        if (drawX < horizontalOrigin || drawX > horizontalOrigin + 600.0f ||
            drawY < 0.0f || drawY > 720.0f) {
            int reflectedAngle = projectile.angle16;
            if (drawX < horizontalOrigin || drawX > horizontalOrigin + 600.0f) {
                reflectedAngle = 0x8000 - static_cast<int>(projectile.angle16);
            }
            if (drawY < 0.0f || drawY > 720.0f) {
                reflectedAngle = -static_cast<int>(projectile.angle16);
            }
            projectile.angle16 = normalizeAngle16(reflectedAngle);
            projectile.anchorX = clampFloat(drawX, horizontalOrigin, horizontalOrigin + 600.0f);
            projectile.anchorY = clampFloat(drawY, 0.0f, 720.0f);
            spawnProjectileSpread(0x0d, 5, drawX, drawY, projectile.angle16, 0.0f,
                                  kScript2ESpeed[static_cast<std::size_t>(difficulty)],
                                  projectile.radius,
                                  kScript2ECount[static_cast<std::size_t>(difficulty)],
                                  32000, 0);
            projectile.active = false;
        }
        break;
    case 0x2f:
    case 0x30:
        if (projectile.age >= 4 && projectile.age < 36 && (projectile.age & 1) == 0) {
            const bool reverse = projectile.projectileId == 0x30;
            const int angleOffset = reverse
                                        ? -projectile.age * 0x309 - 12000
                                        : projectile.age * 0x309 + 12000;
            spawnProjectileNode(reverse ? 0x0d : 0x0c, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + angleOffset),
                                0.0f, 8.5, projectile.radius, 0);
        }
        if (projectile.age == 36) {
            spawnProjectileTerminalEffect(drawX, drawY);
            projectile.active = false;
        }
        break;
    case 0x31: {
        const float radius = static_cast<float>(projectile.radius);
        if (drawX < horizontalOrigin - radius ||
            drawX > horizontalOrigin + 600.0f + radius ||
            drawY < -radius || drawY > 720.0f + radius) {
            int reflectedAngle = projectile.angle16;
            if (drawX < horizontalOrigin || drawX > horizontalOrigin + 600.0f) {
                reflectedAngle = 0x8000 - static_cast<int>(projectile.angle16);
            }
            if (drawY < 0.0f || drawY > 720.0f) {
                reflectedAngle = -static_cast<int>(projectile.angle16);
            }
            projectile.angle16 = normalizeAngle16(reflectedAngle);
            projectile.anchorX = clampFloat(projectile.anchorX, horizontalOrigin,
                                            horizontalOrigin + 600.0f);
            projectile.anchorY = clampFloat(projectile.anchorY, 0.0f, 720.0f);
            spawnProjectileNode(10, 0, drawX, drawY, projectile.angle16,
                                0.0f, projectile.speed, projectile.radius, 0);
            projectile.active = false;
        }
        break;
    }
    case 0x32:
        if (projectile.age >= 0 && projectile.age % 9 == 0 &&
            (projectile.visualSelector == 2 || projectile.visualSelector == 3)) {
            const int childVisual = projectile.visualSelector == 2 ? 8 : 9;
            spawnProjectileNode(childVisual, 4, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) - 0x115c),
                                0.0f, 6.4, projectile.radius, 0);
            spawnProjectileNode(childVisual, 4, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + 0x115c),
                                0.0f, 6.4, projectile.radius, 0);
        }
        break;
    case 0x33: {
        const float radius = static_cast<float>(projectile.radius);
        if (drawX < horizontalOrigin - radius ||
            drawX > horizontalOrigin + 600.0f + radius ||
            drawY < -radius || drawY > 720.0f + radius) {
            spawnProjectileNode(projectile.visualSelector, 1, drawX, drawY,
                                angleToPoint(drawX, drawY, player_.x, player_.y),
                                0.0f, 4.0, projectile.radius, 0);
            projectile.active = false;
        }
        break;
    }
    case 0x34:
        if (projectile.age == 20) {
            spawnProjectileNode(5, 1, drawX, drawY,
                                angleToPoint(drawX, drawY, player_.x, player_.y),
                                0.0f, 3.0, projectile.radius, 0);
        }
        break;
    case 0x37:
    case 0x38:
        if (projectile.age < 51) {
            if (projectile.speed > 0.0) {
                projectile.speed -= projectile.baseSpeed / 50.0;
            }
            if (projectile.age == 50) {
                const StageEnemy* parent = findEnemyById(projectile.arg8OrAux);
                if (parent != nullptr) {
                    const int parentTimer16 = static_cast<std::uint16_t>(parent->helperTimer);
                    const int parentTurn = parentTimer16 * 0x14d;
                    const int direction = projectile.projectileId == 0x37 ? 1 : -1;
                    const int baseAngle = static_cast<int>(projectile.angle16) +
                                          direction * parentTurn;
                    for (int i = 0; i < 3; ++i) {
                        spawnProjectileNode(8, 2, drawX, drawY,
                                            normalizeAngle16(baseAngle + i * 0x5555),
                                            0.0f, 4.8, projectile.radius, 0);
                    }
                }
                spawnProjectileTerminalEffect(drawX, drawY);
                projectile.active = false;
            }
        }
        break;
    case 0x39:
        if (projectile.age < 30) {
            projectile.speed -= projectile.baseSpeed / 30.0;
        }
        if (projectile.age == 30) {
            spawnProjectileNode(2, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) - 15000),
                                0.0f, 5.2, projectile.radius, 0);
            spawnProjectileNode(2, 2, drawX, drawY,
                                normalizeAngle16(static_cast<int>(projectile.angle16) + 15000),
                                0.0f, 5.2, projectile.radius, 0);
            projectile.active = false;
        }
        break;
    case 0x3c: {
        projectile.speed += 0.15;
        const std::uint32_t age = static_cast<std::uint32_t>(projectile.age);
        const std::uint32_t globalFrame = static_cast<std::uint32_t>(frame_);
        const std::uint16_t offsetAngle16 =
            scriptRandomAngle(age * 0x5c49u + globalFrame);
        const float offsetAngle = fixedAngleToRadians(offsetAngle16);
        const float offsetRadius = static_cast<float>(
            stageScriptRandFromFrame(static_cast<int>(age * 0xeacu + globalFrame)) % 0x0bu);
        spawnProjectileNode(4, 0x11,
                            drawX + std::cos(offsetAngle) * offsetRadius,
                            drawY + std::sin(offsetAngle) * offsetRadius,
                            projectile.angle16, 0.0f, 0.0, 1, 0);

        const float effectRadius = static_cast<float>(
            stageScriptRandFromFrame(
                static_cast<int>(age * 0x22b8u + globalFrame)) % 0x11u);
        const std::uint16_t effectOffsetAngle16 =
            scriptRandomAngle(age * 0x378u + globalFrame);
        const double effectOffsetAngle = fixedAngleToRadiansDouble(
            effectOffsetAngle16);
        const double effectScale = scriptRandomHundredth(
            age * 0x15b38u + globalFrame, 0.5, 1.0);
        static constexpr std::array<std::array<int, 3>, 7> kPalette{{
            {{0xff, 0x78, 0x78}}, {{0xff, 0xc8, 0x6e}},
            {{0xff, 0xff, 0x78}}, {{0x78, 0xff, 0x78}},
            {{0x78, 0xff, 0xff}}, {{0x78, 0x78, 0xff}},
            {{0xdc, 0x78, 0xff}},
        }};
        const auto& color = kPalette[static_cast<std::size_t>((age / 3u) % 7u)];
        const int effectHandle = effectSmallFrames_.size() > 17
                                     ? effectSmallFrames_[17]
                                     : -1;
        spawnStageEffect(
            0x04, effectHandle, 100, 0x22,
            drawX + static_cast<float>(std::cos(effectOffsetAngle) * effectRadius),
            drawY + static_cast<float>(std::sin(effectOffsetAngle) * effectRadius),
            scriptRandomAngle(age * 0x58u + globalFrame),
            0.0, effectScale, effectScale, 0x10,
            color[0], color[1], color[2], 0xc0);
        break;
    }
    default:
        break;
    }

    if (drawX < horizontalOrigin - 30.0f || drawX > horizontalOrigin + 630.0f ||
        drawY < -30.0f || drawY > 750.0f) {
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileOrbitArcPair(StageProjectile& projectile) {
    constexpr double kOriginalPi = 3.14159265358979;
    constexpr double kFixedAngleToRadiansScale = 3.0517578125e-05;
    constexpr double kRadiansToFixedAngleScale = 10430.378350470464;

    float verticalRadius = 0.0f;
    float horizontalRadius = 0.0f;
    if (projectile.age >= 0 && projectile.age < 40) {
        const double rampAngle = static_cast<double>(projectile.age) * 409.6 *
                                 kOriginalPi * kFixedAngleToRadiansScale;
        const double ramp = std::sin(rampAngle);
        verticalRadius = static_cast<float>(static_cast<int>(ramp * 150.0));
        horizontalRadius = static_cast<float>(static_cast<int>(ramp * 320.0));
    }
    else if (projectile.age >= 40) {
        verticalRadius = 150.0f;
        horizontalRadius = 320.0f;
    }
    if (projectile.age == 40) {
        const float deltaY = player_.y - projectile.prevY;
        const float deltaX = player_.x - projectile.prevX;
        const double targetAngle = std::atan2(static_cast<double>(deltaY),
                                              static_cast<double>(deltaX));
        projectile.prevAngle16 = normalizeAngle16(
            static_cast<int>(targetAngle * kRadiansToFixedAngleScale));
    }
    if (projectile.age > 40) {
        if (projectile.speed < 4.0) {
            projectile.speed += 0.05;
        }
        const double anchorAngle = static_cast<double>(projectile.prevAngle16) *
                                   kOriginalPi * kFixedAngleToRadiansScale;
        projectile.prevX += static_cast<float>(std::cos(anchorAngle) * projectile.speed);
        projectile.prevY += static_cast<float>(std::sin(anchorAngle) * projectile.speed);
    }

    int turn = 1;
    if (config_.difficulty >= 0 && config_.difficulty < static_cast<int>(kOrbitTurn.size())) {
        turn = kOrbitTurn[static_cast<std::size_t>(config_.difficulty)];
    }
    if (projectile.projectileId == 0x1f) {
        projectile.angle16 = normalizeAngle16(static_cast<int>(projectile.angle16) + turn);
    }
    else if (projectile.projectileId == 0x20) {
        projectile.angle16 = normalizeAngle16(static_cast<int>(projectile.angle16) - turn);
    }

    const double drawAngle = static_cast<double>(projectile.angle16) *
                             kOriginalPi * kFixedAngleToRadiansScale;
    const float drawX = projectile.prevX + static_cast<float>(
        std::cos(drawAngle) * static_cast<double>(horizontalRadius));
    const float drawY = projectile.prevY + static_cast<float>(
        std::sin(drawAngle) * static_cast<double>(verticalRadius));
    // FUN_140133f30 commits its derived point to raw node +0x10/+0x14.
    projectile.anchorX = drawX;
    projectile.anchorY = drawY;
    projectile.x = drawX;
    projectile.y = drawY;

    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    if (drawX < horizontalOrigin - 256.0f ||
        drawX > horizontalOrigin + 856.0f ||
        drawY < -256.0f || drawY > 976.0f) {
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileExpandingSpiralPair(StageProjectile& projectile) {
    constexpr double kOriginalPi = 3.14159265358979;
    constexpr double kFixedAngleToRadiansScale = 3.0517578125e-05;

    if (projectile.age == 0) {
        // Raw +0x18 becomes the permanent base radius; +0x20 remains current radius.
        projectile.prevX = projectile.speedOrAccelHint;
        projectile.prevAngle16 = projectile.anchorY > player_.y ? 0xc000 : 0x4000;
    }
    const float baseRadius = projectile.prevX;
    float radius = baseRadius;
    if (projectile.age < 0) {
        radius = 0.0f;
    }
    else if (projectile.age < 10) {
        const double rampAngle = static_cast<double>(projectile.age) * 1638.4 *
                                 kOriginalPi * kFixedAngleToRadiansScale;
        radius = static_cast<float>(std::sin(rampAngle) * static_cast<double>(baseRadius));
    }
    projectile.speedOrAccelHint = radius;
    projectile.speed = static_cast<double>(projectile.age) * 0.35 - 2.0;

    const double oldAngle = static_cast<double>(projectile.angle16) *
                            kOriginalPi * kFixedAngleToRadiansScale;
    projectile.anchorX += static_cast<float>(std::cos(oldAngle) * projectile.speed);
    projectile.anchorY += static_cast<float>(std::sin(oldAngle) * projectile.speed);
    if (projectile.projectileId == 0x3a) {
        projectile.angle16 = normalizeAngle16(static_cast<int>(projectile.angle16) + 0x1bc);
    }
    else if (projectile.projectileId == 0x3b) {
        projectile.angle16 = normalizeAngle16(static_cast<int>(projectile.angle16) - 0x1bc);
    }

    const double drawAngle = static_cast<double>(projectile.angle16) *
                             kOriginalPi * kFixedAngleToRadiansScale;
    projectile.x = projectile.anchorX + static_cast<float>(
        std::cos(drawAngle) * static_cast<double>(radius));
    projectile.y = projectile.anchorY + static_cast<float>(
        std::sin(drawAngle) * static_cast<double>(radius));

    const int boundaryRadius = static_cast<int>(baseRadius);
    const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
    if (projectile.anchorX < horizontalOrigin - static_cast<float>(boundaryRadius + 50) ||
        projectile.anchorX > horizontalOrigin + static_cast<float>(boundaryRadius + 650) ||
        projectile.anchorY < static_cast<float>(-(boundaryRadius + 50)) ||
        projectile.anchorY > static_cast<float>(boundaryRadius + 770)) {
        projectile.active = false;
    }
}

void StageRuntime::updateRewardItems() {
    for (auto& item : rewardItems_) {
        if (!item.active) {
            continue;
        }
        item.drawAge = item.age;
        const bool ordinaryScoreItem = item.itemType >= 0 && item.itemType <= 5;
        const bool specialRewardItem = item.itemType >= 6 && item.itemType <= 8;
        const float preMoveX = item.x;
        const float preMoveY = item.y;
        float movementSpeed = item.speed;
        if (ordinaryScoreItem) {
            if (!item.homing) {
                if (item.age < 0x21) {
                    movementSpeed = item.speed * static_cast<float>(
                        1.0 - std::sin(static_cast<double>(item.age) * kPi / 33.0));
                }
                if (item.age == 0x20) {
                    item.speed = 0.0f;
                    const std::uint32_t random = stageScriptRandFromFrame(
                        frame_ + static_cast<int>(preMoveX + preMoveY));
                    item.angle16 = normalizeAngle16(
                        static_cast<int>(random % 0x801u) + 0x3c00);
                    if (player_.playerStateTimer < 0xb5) {
                        if (item.itemType >= 3) {
                            item.homing = true;
                        }
                        else {
                            // The original writes 0x21 here before the common
                            // tail increment, so ordinary tiers skip age 0x21.
                            item.age = 0x21;
                        }
                    }
                }
                if (item.age > 0x20 && item.speed < 5.0f) {
                    item.speed = std::min(5.0f, item.speed + 0.05f);
                }
                if (item.age > 0x1f && player_.playerStateTimer < 0xb5 &&
                    distanceSquared(preMoveX, preMoveY, player_.x, player_.y) <
                        static_cast<float>((item.radiusOrScale + 160) *
                                           (item.radiusOrScale + 160))) {
                    item.homing = true;
                }
            }
            else {
                item.angle16 = approachAngle16(
                    item.angle16,
                    radiansToFixedAngleTrunc(std::atan2(
                        static_cast<double>(player_.y - preMoveY),
                        static_cast<double>(player_.x - preMoveX))),
                    0x1000);
                item.speed = 12.0f;
                if (player_.playerStateTimer == 0x103) {
                    item.age = 0x28;
                    item.speed = 0.0f;
                    item.homing = false;
                    const std::uint32_t random = stageScriptRandFromFrame(
                        frame_ + static_cast<int>(preMoveX + preMoveY));
                    item.angle16 = normalizeAngle16(
                        static_cast<int>(random % 0x801u) + 0x3c00);
                }
            }
        }
        else if (specialRewardItem) {
            if (!item.homing) {
                if (player_.playerStateTimer < 0xb5 &&
                    distanceSquared(preMoveX, preMoveY, player_.x, player_.y) <
                        static_cast<float>((item.radiusOrScale + 80) *
                                           (item.radiusOrScale + 80)) &&
                    (player_.tokenStock != 3 || item.itemType != 6)) {
                    item.homing = true;
                    item.angle16 = radiansToFixedAngleTrunc(std::atan2(
                        static_cast<double>(player_.y - preMoveY),
                        static_cast<double>(player_.x - preMoveX)));
                }
            }
            else {
                item.angle16 = approachAngle16(
                    item.angle16,
                    radiansToFixedAngleTrunc(std::atan2(
                        static_cast<double>(player_.y - preMoveY),
                        static_cast<double>(player_.x - preMoveX))),
                    0x1000);
                item.speed = 12.0f;
                if (player_.playerStateTimer > 0xb4) {
                    item.homing = false;
                    item.speed = 4.0f;
                }
            }
            movementSpeed = item.speed;
        }
        else {
            item.active = false;
            ++item.age;
            continue;
        }
        const float angle = fixedAngleToRadians(item.angle16);
        item.x = preMoveX + std::cos(angle) * movementSpeed;
        item.y = preMoveY + std::sin(angle) * movementSpeed;
        if (specialRewardItem && item.age < 0x4b0) {
            const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
            const std::uint16_t originalAngle = item.angle16;
            int reflectedAngle = -0x8000 - static_cast<int>(originalAngle);
            if (item.x >= horizontalOrigin + 30.0f) {
                reflectedAngle = originalAngle;
            }
            if (item.x > horizontalOrigin + 570.0f) {
                reflectedAngle = -0x8000 - static_cast<int>(originalAngle);
            }
            if (item.y < 30.0f || item.y > 690.0f) {
                reflectedAngle = -static_cast<int>(originalAngle);
            }
            item.angle16 = normalizeAngle16(reflectedAngle);
            item.x = clampFloat(item.x, horizontalOrigin + 30.0f,
                                horizontalOrigin + 570.0f);
            item.y = clampFloat(item.y, 30.0f, 690.0f);
        }
        const int collectRadius = item.radiusOrScale + 36;
        const bool collectionAgeReady = specialRewardItem || item.age > 0x20;
        if (collectionAgeReady && player_.playerStateTimer < 0xb5 &&
            distanceSquared(preMoveX, preMoveY, player_.x, player_.y) <
                static_cast<float>(collectRadius * collectRadius)) {
            item.active = false;
            collectRewardItem(item);
        }
        const float horizontalOrigin = projectileHorizontalOrigin(player_.x);
        if (item.x < horizontalOrigin - 128.0f ||
            item.x > horizontalOrigin + 728.0f ||
            item.y < -128.0f || item.y > 848.0f) {
            item.active = false;
        }
        ++item.age;
    }
}

int StageRuntime::effectiveHelpLevel() const {
    // FUN_140135290 returns explicit levels 1..5 unchanged and folds Off (6)
    // to zero. Auto (0) derives a level from the current stage/setup/difficulty
    // attempt record captured by the frontend from save.dat.
    if (config_.helpMode >= 1 && config_.helpMode <= 5) {
        return config_.helpMode;
    }
    if (config_.helpMode != 0) {
        return 0;
    }
    if (config_.helpAutoProgress < 3) {
        return 0;
    }
    if (config_.helpAutoProgress < 6) {
        return 1;
    }
    if (config_.helpAutoProgress < 8) {
        return 2;
    }
    if (config_.helpAutoProgress < 10) {
        return 3;
    }
    if (config_.helpAutoProgress < 12) {
        return 4;
    }
    return 5;
}

int StageRuntime::stockThresholdForCurrentConfig() const {
    // DAT_140538bd8 is a five-entry difficulty/route table in .rdata:
    // {56000, 70000, 70000, 70000, 70000}. FUN_1400f6c40 initializes
    // DAT_140e45d88 as table[DAT_140e419b8] * DAT_140e474ec, and
    // FUN_14010e250 uses the same chunk for the 0..3 Mental-level bands.
    const int index = std::max(0, std::min(config_.difficulty, static_cast<int>(kOriginalStockThresholds.size()) - 1));
    return kOriginalStockThresholds[static_cast<std::size_t>(index)];
}

void StageRuntime::addRunScore(std::int64_t amount) {
    player_.score = std::max<std::int64_t>(0, player_.score + amount);
    if (!config_.replayPlayback &&
        (config_.routeMode == 0 || config_.routeMode == 1) &&
        effectiveHelpLevel() == 0) {
        player_.bestScore = std::max(player_.bestScore, player_.score);
    }
}

void StageRuntime::addSpecialGauge(int amount) {
    if (player_.specialGauge < 0 || amount <= 0) {
        return;
    }
    player_.specialGauge += amount;
    if (player_.specialGauge < 0) {
        player_.specialGauge = 0;
    }
}

void StageRuntime::processStockProgressAfterGain(int progressGain) {
    const int threshold = stockThresholdForCurrentConfig();
    const int cap = threshold * 3;
    player_.stockProgress = std::min(cap, player_.stockProgress + std::max(0, progressGain));
    if (player_.tokenStock < 3 &&
        player_.stockProgress >= (player_.tokenStock + 1) * threshold) {
        ++player_.tokenStock;
    }
}

void StageRuntime::collectRewardItem(const RewardItem& item) {
    // FUN_1400ca7b0 reward collection table: 0/3 = 1x base, 1/4 = 5x,
    // 2/5 = 10x; 6 feeds Mental progress, 7 adds a life, and 8 grants both.
    const double gaugeScale = std::max(
        0.6, 1.0 - static_cast<double>(selectedStage_ / 2) * 0.1);
    switch (item.itemType) {
    case 0:
    case 3:
        addRunScore(player_.scoreItemBaseValue);
        addSpecialGauge(static_cast<int>(gaugeScale * 10.0));
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 1:
    case 4:
        addRunScore(player_.scoreItemBaseValue * 5);
        addSpecialGauge(static_cast<int>(gaugeScale * 50.0));
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 2:
    case 5:
        addRunScore(player_.scoreItemBaseValue * 10);
        addSpecialGauge(static_cast<int>(gaugeScale * 100.0));
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 6:
        if (player_.tokenStock < 3) {
            player_.stockProgress += stockThresholdForCurrentConfig();
        }
        playPlayerSound(item3SoundHandle_);
        break;
    case 7:
        if (player_.lives < kLifeStockCap) {
            ++player_.lives;
            playPlayerSound(extendSoundHandle_);
        }
        break;
    case 8:
        player_.stockProgress += 99999;
        player_.lives = kLifeStockCap;
        break;
    default:
        break;
    }
    hudSpecialGaugeFlashTimer_ = 60;
}

void StageRuntime::spawnEnemyDeathRewardBurst(const StageEnemy& enemy, int payoutWindow,
                                              bool spawnImmediateEffect) {
    int payout = 1;
    if (payoutWindow - enemy.targetableTimer > 0) {
        payout = static_cast<int>(
            (static_cast<double>(payoutWindow - enemy.targetableTimer) /
             static_cast<double>(payoutWindow)) *
            static_cast<double>(enemy.rewardWeight));
    }
    const bool feverActive = player_.specialGauge < 0;
    if (feverActive) {
        payout *= 2;
    }

    int highCount = 0;
    if (payout > 49) {
        highCount = payout / 20;
        payout -= highCount * 10;
    }
    int mediumCount = 0;
    if (payout > 9) {
        mediumCount = payout / 10;
        payout -= mediumCount * 5;
    }
    const int lowCount = payout;
    const std::uint32_t globalFrame = static_cast<std::uint32_t>(frame_);
    const auto emitTier = [this, &enemy, globalFrame](int itemType, int count,
                                                      std::uint32_t angleOffset,
                                                      std::uint32_t speedOffset,
                                                      int radiusOrScale) {
        for (int i = 0; i < count; ++i) {
            const auto ordinal = static_cast<std::uint32_t>(i);
            spawnRewardItem(
                itemType, enemy.x, enemy.y,
                scriptRandomAngle(globalFrame + angleOffset + ordinal),
                static_cast<float>(scriptRandomHundredth(
                    globalFrame + speedOffset + ordinal, 0.0, 16.0)),
                radiusOrScale);
        }
    };
    emitTier(2, highCount, 666u, 555u, 60);
    emitTier(1, mediumCount, 444u, 333u, 45);
    emitTier(0, lowCount, 222u, 111u, 30);

    const double deltaX = static_cast<double>(player_.x) - static_cast<double>(enemy.x);
    const double deltaY = static_cast<double>(player_.y) - static_cast<double>(enemy.y);
    const int proximity = static_cast<int>(std::sqrt(deltaX * deltaX + deltaY * deltaY)) -
                          enemy.radius;
    int feedbackMultiplier = 1;
    if (proximity <= 150) {
        feedbackMultiplier = 10;
    }
    else if (proximity < 450) {
        feedbackMultiplier = std::max(1, (450 - proximity) / 30);
    }
    if (feverActive) {
        feedbackMultiplier = 10;
    }
    spawnStageEffect(0x1d, -1, 0, 0, enemy.x, enemy.y, 0,
                     0.0, static_cast<double>(feedbackMultiplier),
                     static_cast<double>(enemy.radius + 60),
                     enemyDeathFeedbackStrength(enemy.spawnType, enemy.radius) * 3,
                     0xff, 0xff, 0xff, 0xc0);

    const double progressScale = proximity <= 500
                                     ? 1.0 + static_cast<double>(500 - proximity) / 200.0
                                     : 1.0;
    player_.stockProgress += static_cast<int>(
        static_cast<double>(enemy.radius + 100) * progressScale);
    if (feverActive) {
        spawnPlayerSideObject(0x1a, enemy.x, enemy.y, 0.0, 0, 0,
                              static_cast<float>(enemy.radius) * 1.5f + 60.0f);
    }

    spawnPostDeathCounterEntity(enemy, static_cast<double>(enemy.radius) * 0.6);
    if (spawnImmediateEffect && !defersEnemyDeathEffects(enemy.spawnType)) {
        spawnEnemyDeathEffects(enemy, immediateEnemyDeathEffectMode(enemy.spawnType));
    }
}

void StageRuntime::spawnEnemyDeathEffects(const StageEnemy& enemy, int mode,
                                          bool playSound) {
    if (mode < 0 || mode > 2) {
        return;
    }

    if (playSound) {
        switch (mode) {
        case 0:
            playPlayerSound(enemyDown1SoundHandle_, 19);
            break;
        case 1:
            playPlayerSound(enemyDown2SoundHandle_, 22);
            break;
        case 2:
            playPlayerSound(enemyDown3SoundHandle_, 25);
            break;
        default:
            break;
        }
    }

    const int count = stageRandomIntInclusive(
        static_cast<std::uint32_t>(enemy.entityId) * 111u +
            static_cast<std::uint32_t>(frame_),
        enemy.radius / 4, enemy.radius / 3);
    const int burstHandle = effectMediumFrames_.size() > 5 ? effectMediumFrames_[5] : -1;
    const int sparkHandle = playerFrames_.size() > 14 ? playerFrames_[14] : -1;
    const std::uint32_t baseSeed =
        static_cast<std::uint32_t>(enemy.entityId) * 666u +
        static_cast<std::uint32_t>(frame_);
    for (int i = 0; i < count; ++i) {
        const auto ordinal = static_cast<std::uint32_t>(i);
        const std::uint32_t burstSeed = baseSeed + ordinal;
        const int distance = stageRandomIntInclusive(burstSeed, 0, enemy.radius + 60);
        const std::uint16_t burstAngle = scriptRandomAngle(burstSeed);
        const double burstRadians = fixedAngleToRadiansDouble(burstAngle);
        const float burstX = enemy.x +
                             static_cast<float>(std::cos(burstRadians) * distance);
        const float burstY = enemy.y +
                             static_cast<float>(std::sin(burstRadians) * distance);
        const double burstScale = scriptRandomHundredth(
            burstSeed, static_cast<double>(enemy.radius) / 200.0 + 0.4,
            static_cast<double>(enemy.radius) / 200.0 + 0.7);
        spawnStageEffect(0x2a, burstHandle, 200, 0x3e, burstX, burstY,
                         burstAngle, 1.0, burstScale, burstScale, 24,
                         0xff, 0xff, 0xff, 0xff);

        std::uint32_t angleSeed = static_cast<std::uint32_t>(frame_);
        std::uint32_t scaleSeed = baseSeed;
        std::uint32_t speedSeed = static_cast<std::uint32_t>(frame_);
        double scaleMinimum = 0.7;
        double scaleMaximum = 1.0;
        double speedMinimum = 6.0;
        double speedMaximum = 9.0;
        if (mode == 0) {
            angleSeed += ordinal * 11u;
            scaleSeed += ordinal * 1111u;
            speedSeed += ordinal * 555u;
        }
        else if (mode == 1) {
            angleSeed += ordinal * 22u;
            scaleSeed += ordinal * 2222u;
            speedSeed += ordinal * 222u;
            scaleMinimum = 0.9;
            scaleMaximum = 1.5;
            speedMinimum = 10.0;
            speedMaximum = 15.0;
        }
        else {
            angleSeed += ordinal * 33u;
            scaleSeed += ordinal * 3333u;
            speedSeed = baseSeed + ordinal * 333u;
            scaleMinimum = 1.0;
            scaleMaximum = 2.2;
            speedMinimum = 16.0;
            speedMaximum = 26.0;
        }
        const double sparkScale = scriptRandomHundredth(
            scaleSeed, scaleMinimum, scaleMaximum);
        spawnStageEffect(0x2c, sparkHandle, 80, 0x3e, enemy.x, enemy.y,
                         scriptRandomAngle(angleSeed),
                         scriptRandomHundredth(speedSeed, speedMinimum, speedMaximum),
                         sparkScale, sparkScale, 0,
                         0xff, 0xff, 0xff, 0xc0);
    }

    if (mode == 2) {
        const int centerHandle = effectLargeFrames_.empty()
                                     ? -1
                                     : effectLargeFrames_[0];
        spawnStageEffect(0x13, centerHandle, 600, 0x5b,
                         enemy.x, enemy.y, 0, 0.0, 0.0, 0.0, 0,
                         0xff, 0xff, 0xff, 0xff);
    }
    else if (player_.specialGauge >= 0) {
        const int ringHandle = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        const double ringScale = static_cast<double>(enemy.radius) / 16.0;
        spawnStageEffect(0x0c, ringHandle, 200, 0x3d, enemy.x, enemy.y, 0,
                         0.0, ringScale, ringScale, 24,
                         0xff, 0xff, 0xff, 0x60);
    }
}

void StageRuntime::spawnPostDeathCounterEntity(const StageEnemy& enemy, double lifetime) {
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy counter;
    counter.entityId = nextEntityId_++;
    counter.spawnType = 0x137;
    counter.sourceHitPoints = 99999999;
    counter.sourceX = static_cast<int>(enemy.x);
    counter.sourceY = static_cast<int>(enemy.y);
    counter.sourceNote = "post-death counter entity 0x137";
    counter.updateCase = 0x9e;
    counter.sourceDispatchKind = 0;
    counter.sourceDispatchField = enemy.radius;
    counter.x = enemy.x;
    counter.y = enemy.y;
    counter.originX = enemy.x;
    counter.originY = enemy.y;
    counter.sourceSpeed = lifetime;
    counter.speed = static_cast<float>(lifetime);
    counter.hp = 99999999;
    counter.maxHp = 99999999;
    counter.drawHp = 99999999;
    counter.radius = enemy.radius;
    counter.activationDelay = 0;
    counter.rewardWeight = 0;
    counter.targetable = false;
    pendingEnemies_.push_back(counter);
}

void StageRuntime::updatePostDeathCounterEntity(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;
    if (config_.counterMode != 1) {
        enemy.active = false;
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const int interval = std::array<int, 5>{{5, 4, 3, 2, 2}}[
        static_cast<std::size_t>(difficulty)];
    const int timer = enemy.helperTimer;
    if (player_.score != 0 && timer >= 0 && timer % interval == 0 && enemy.y < 600.0f) {
        const std::uint32_t entityId = static_cast<std::uint32_t>(enemy.entityId);
        const std::uint16_t radialAngle = scriptRandomAngle(
            static_cast<std::uint32_t>(timer) * 666u + entityId);
        const int radialLength = stageRandomIntInclusive(
            static_cast<std::uint32_t>(timer) * 6666u + entityId,
            0, enemy.radius);
        const double radialRadians = fixedAngleToRadiansDouble(radialAngle);
        const float pointX = enemy.x +
                             static_cast<float>(std::cos(radialRadians) * radialLength);
        const float pointY = enemy.y +
                             static_cast<float>(std::sin(radialRadians) * radialLength);
        const std::uint16_t aimedAngle = radiansToFixedAngleTrunc(std::atan2(
            static_cast<double>(player_.y - pointY),
            static_cast<double>(player_.x - pointX)));
        const int jitter = stageRandomIntInclusive(
            static_cast<std::uint32_t>(timer) * 3333u + entityId,
            -1000, 1000);
        const std::uint16_t heading = normalizeAngle16(
            static_cast<int>(aimedAngle) + jitter);
        const int threshold = stageRandomIntInclusive(
            static_cast<std::uint32_t>(timer) * 777u + entityId,
            180, 480);
        const double playerDistance = std::sqrt(
            static_cast<double>(distanceSquared(pointX, pointY, player_.x, player_.y)));
        const std::uint32_t itemSeed =
            static_cast<std::uint32_t>(timer) * 7777u + entityId;
        if (playerDistance <= 480.0 && playerDistance < static_cast<double>(threshold)) {
            spawnRewardItem(0, pointX, pointY, scriptRandomAngle(itemSeed),
                            static_cast<float>(scriptRandomHundredth(itemSeed, 0.0, 16.0)),
                            30);
            const std::uint16_t feedbackAngle = normalizeAngle16(
                static_cast<int>(scriptRandomAngle(
                    static_cast<std::uint32_t>(timer) * 77777u + entityId)) +
                static_cast<int>(heading) + 0x4000);
            spawnStageEffect(0x1a, -1, 0, 0x49, pointX, pointY, feedbackAngle,
                             1.0, 1.0, 0.5, 50,
                             0xff, 0xff, 0xff, 0xc0);
            const int ringHandle = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            spawnStageEffect(0x0c, ringHandle, 200, 0x3d, pointX, pointY, 0,
                             0.0, 0.6, 0.6, 16,
                             0xff, 0xff, 0xff, 0xff);
        }
        else {
            constexpr std::array<double, 5> kMinimumSpeed{{3.5, 4.0, 4.5, 5.5, 6.5}};
            const double minimum = kMinimumSpeed[static_cast<std::size_t>(difficulty)] +
                                   static_cast<double>(selectedStage_) * 0.1;
            spawnProjectileNode(0x0f, 0x16, pointX, pointY, heading, 0.0f,
                                scriptRandomHundredth(itemSeed, minimum, minimum + 2.0),
                                1, 0);
        }
    }

    int lifetime = static_cast<int>(enemy.sourceSpeed);
    if (difficulty == 0) {
        lifetime /= 2;
    }
    if (timer == lifetime) {
        enemy.active = false;
    }
}

void StageRuntime::updateSpecialGaugeAction() {
    const bool bombDown = actionDown(InputAction::Bomb);
    const bool manualFever = config_.specialMode == 1;
    const bool stageClearBombLock = [this]() {
        switch (selectedStage_) {
        case 1: return stage01ClearTransition_;
        case 2: return stage02ClearTransition_;
        case 3: return stage03ClearTransition_;
        case 4: return stage04ClearTransition_;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            return lateStageClearStarted_;
        default:
            return false;
        }
    }();
    const bool triggerAllowed =
        player_.bombLock == 0 &&
        (player_.tokenStock != 0 ||
         (manualFever && player_.specialGauge >= kSpecialGaugeReady)) &&
        !stageClearBombLock &&
        static_cast<std::uint32_t>(player_.playerStateTimer - 120) > 139U &&
        (player_.specialGauge >= 0 ||
         static_cast<std::uint32_t>(player_.invulnerableFrames - 1) > 278U);

    if (bombDown && triggerAllowed) {
        if (!manualFever || player_.specialGauge < kSpecialGaugeReady) {
            startEquippedBomb();
        }
        else {
            startFever(true);
        }
    }

    if (player_.bombLock != 0) {
        ++player_.bombLock;
    }
    if (player_.bombLock >= 180) {
        player_.bombLock = -30;
    }
}

void StageRuntime::updateSpecialGaugeState(int shotTimerBeforeInput) {
    const bool manualFever = config_.specialMode == 1;
    if (player_.specialGauge < kSpecialGaugeReady) {
        if (player_.specialGauge < 0) {
            // DAT_140e46b2c pauses Fever at empty stage boundaries and on
            // alternating idle frames. Special/Time-window play uses its own
            // elapsed counter for the parity test.
            const bool hasLiveEnemy = std::any_of(
                enemies_.begin(), enemies_.end(),
                [](const StageEnemy& enemy) {
                    return enemy.active && enemy.targetable;
                });
            const bool hasLiveProjectile = std::any_of(
                enemyProjectiles_.begin(), enemyProjectiles_.end(),
                [](const StageProjectile& projectile) {
                    return projectile.active;
                });
            const int stageEnd = kStageEndFrames[
                static_cast<std::size_t>(std::clamp(selectedStage_, 0, 10))];
            bool timerPaused =
                (frame_ < 0xf0 || frame_ >= stageEnd - 0x14a) &&
                !hasLiveEnemy && !hasLiveProjectile;
            const int idleParityClock = config_.specialStageFlag == 0
                                            ? frame_
                                            : timeWindowElapsedFrames_;
            if (shotTimerBeforeInput == 0 && (idleParityClock & 1) != 0) {
                timerPaused = true;
            }
            if (!timerPaused) {
                ++player_.specialGauge;
            }
            if ((player_.drawAnimationClock & 0x0f) == 0 &&
                player_.specialGauge < -60) {
                spawnFeverTrailEffect();
            }
            if (player_.specialGauge == 0) {
                playPlayerSound(feverSoundHandles_[2], 0x13);
                spawnPlayerSideObject(0x18, player_.x, player_.y, 0.0, 0, 0, 0.0f);
            }
        }
        else if (player_.specialGauge > 0 && hudSpecialGaugeFlashTimer_ == 0) {
            const double stageScale = std::max(
                0.6, 1.0 - static_cast<double>(selectedStage_ / 2) * 0.1);
            player_.specialGauge += static_cast<int>(stageScale * -50.0);
            if (player_.specialGauge < 0) {
                player_.specialGauge = 0;
            }
        }
    }
    else if (!manualFever) {
        startFever(false);
    }
    else if (player_.specialGauge <= kSpecialGaugeForcedFull - 1) {
        armManualFever();
    }
}

bool StageRuntime::settlePendingPlayerHit() {
    if (player_.playerStateTimer != 260) {
        return false;
    }
    if (pauseFlowState_ == PauseFlowState::GameOverDelay ||
        pauseFlowState_ == PauseFlowState::GameOverPresentation) {
        return false;
    }
    const int phaseMode = selectedStage_ == 1 ? stage01BossPhaseMode_
                          : selectedStage_ == 2 ? stage02BossPhaseMode_
                          : selectedStage_ == 3 ? stage03BossPhaseMode_
                          : selectedStage_ == 4 ? stage04BossPhaseMode_
                                                : lateStageBossPhaseMode_;
    const int style = std::clamp(config_.optionSlots[3], 0, 3);
    const bool autoGuard = player_.tokenStock > 0 && style != 3;
    if (autoGuard) {
        if (phaseMode == 1 && bossPhaseRewardIndex_ == 0) {
            bossPhaseRewardIndex_ = 1;
        }
        playPlayerSound(guardSoundHandle_, 0x19);
        const int centerHandle = effectLargeFrames_.empty()
                                     ? -1
                                     : effectLargeFrames_[0];
        spawnStageEffect(0x13, centerHandle, 600, 0x5b,
                         player_.x, player_.y, 0,
                         0.0, 0.0, 0.0, 0,
                         0xff, 0xff, 0xff, 0xff);

        constexpr std::array<float, 4> kGuardRadii{{0.0f, 240.0f, 320.0f, 480.0f}};
        const float guardRadius = style == 0
                                      ? 240.0f
                                      : kGuardRadii[static_cast<std::size_t>(
                                            std::clamp(player_.tokenStock, 0, 3))];
        spawnPlayerSideObject(0x16, player_.x, player_.y,
                              0.0, 0, 0, guardRadius);
        if (style == 0) {
            --player_.tokenStock;
            player_.stockProgress -= stockThresholdForCurrentConfig();
        }
        else {
            player_.tokenStock = 0;
            player_.stockProgress = 0;
        }

        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int portraitIndex = 4 + group * 10;
        const int portraitHandle = portraitIndex < static_cast<int>(playerFrameFrames_.size())
                                       ? playerFrameFrames_[static_cast<std::size_t>(portraitIndex)]
                                       : -1;
        spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                         0.0f, 0.0f, 0,
                         0.0, 1.0, 1.0, 0x78,
                         0xff, 0xff, 0xff, 0xff);
        spawnStageEffect(0x1e, -1, 0, 1,
                         0.0f, 0.0f, 0,
                         0.0, 1.0, 1.0, 0x60,
                         0xff, 0xff, 0xff, 0xff);
        player_.playerStateTimer = 0;
        player_.bombLock = -120;
        player_.invulnerableFrames = std::max(player_.invulnerableFrames, 150);
        return false;
    }

    player_.shotVariant = 0;
    if (phaseMode == 1) {
        bossPhaseRewardIndex_ = -1;
    }
    spawnStageEffect(0x10, -1, 0, 0x28,
                     player_.x, player_.y, 0,
                     0.0, 1.0, 1.0, 0,
                     0xff, 0xff, 0xff, 0xff);
    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int portraitIndex = (player_.lives == 0 ? 9 : 8) + group * 10;
    const int portraitHandle = portraitIndex < static_cast<int>(playerFrameFrames_.size())
                                   ? playerFrameFrames_[static_cast<std::size_t>(portraitIndex)]
                                   : -1;
    spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                     0.0f, 0.0f, 0,
                     0.0, 1.0, 1.0, player_.lives == 0 ? 1000 : 0x78,
                     0xff, 0xff, 0xff, 0xff);
    spawnStageEffect(0x1f, -1, 0, 1,
                     0.0f, 0.0f, 0,
                     0.0, 1.0, 1.0, 0x50,
                     0xff, 0xff, 0xff, 0xff);

    // FUN_140106be0 emits one Mental/Bomb item on the first two misses and
    // two on later non-terminal misses.  State 0x15 (the route -1 shortcut)
    // and the terminal Game Over branch skip these drops.  DAT_140e477e4 is
    // incremented only after the old count has selected the drop quantity.
    const int completedMisses = player_.beingShotCount;
    if (player_.lives != 0 && config_.routeMode != -1) {
        const int dropCount = completedMisses > 1 ? 2 : 1;
        for (int i = 0; i < dropCount; ++i) {
            const std::uint32_t random = stageScriptRandFromFrame(frame_ + i * 10);
            const std::uint16_t angle = normalizeAngle16(
                static_cast<int>(random % 0x4001u) - 0x6000);
            spawnRewardItem(6, player_.x, player_.y, angle, 3.5f, 30);
        }
    }
    ++player_.beingShotCount;

    if (player_.lives == 0) {
        beginGameOver();
        return true;
    }
    flushEnemyProjectilesToEffects();
    --player_.lives;
    return false;
}

void StageRuntime::startEquippedBomb() {
    constexpr std::array<std::array<int, 2>, 3> kRootTypes{{
        {{0x0b, 0x0e}}, {{0x0f, 0x11}}, {{0x12, 0x15}},
    }};
    constexpr std::array<std::array<double, 2>, 3> kRootSpeeds{{
        {{0.0, 18.0}}, {{0.0, 0.0}}, {{0.0, 0.0}},
    }};
    constexpr std::array<std::array<int, 2>, 3> kRootValues{{
        {{0, 0}}, {{0, 0}}, {{0, 15}},
    }};
    constexpr std::array<std::array<float, 2>, 3> kRootRadii{{
        {{0.0f, 45.0f}}, {{0.0f, 0.0f}}, {{0.0f, 0.0f}},
    }};
    constexpr std::array<std::array<int, 2>, 3> kBombLocks{{
        {{-210, -210}}, {{1, -180}}, {{-210, -270}},
    }};
    constexpr std::array<std::array<int, 2>, 3> kBombInvulnerability{{
        {{300, 300}}, {{300, 150}}, {{300, 360}},
    }};

    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int slot = std::clamp(config_.optionSlots[2], 0, 1);
    const int stateTimerBeforeBomb = player_.playerStateTimer;
    const int phaseMode = selectedStage_ == 1 ? stage01BossPhaseMode_
                          : selectedStage_ == 2 ? stage02BossPhaseMode_
                          : selectedStage_ == 3 ? stage03BossPhaseMode_
                          : selectedStage_ == 4 ? stage04BossPhaseMode_
                                                : lateStageBossPhaseMode_;
    if (phaseMode == 1 && bossPhaseRewardIndex_ == 0) {
        bossPhaseRewardIndex_ = 1;
    }
    spawnPlayerSideObject(kRootTypes[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          player_.x, player_.y,
                          kRootSpeeds[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          0xc000,
                          kRootValues[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          kRootRadii[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)]);
    player_.bombLock = kBombLocks[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)];
    player_.invulnerableFrames =
        kBombInvulnerability[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)];
    --player_.tokenStock;
    player_.stockProgress -= stockThresholdForCurrentConfig();

    // FUN_140106be0 checks the pre-Bomb state timer. A normal activation uses
    // PlayerFrame[3], while a deathbomb first emits the small terminal burst
    // and uses PlayerFrame[7]. Both portraits remain for 180 frames.
    const bool deathbombPresentation = stateTimerBeforeBomb >= 0x104;
    if (deathbombPresentation) {
        spawnStageEffect(0x36, -1, 0, 0x28,
                         player_.x, player_.y, 0,
                         0.0, 1.0, 1.0, 0,
                         0xff, 0xff, 0xff, 0xff);
    }
    const int portraitIndex = (deathbombPresentation ? 7 : 3) + group * 10;
    const int portraitHandle =
        portraitIndex < static_cast<int>(playerFrameFrames_.size())
            ? playerFrameFrames_[static_cast<std::size_t>(portraitIndex)]
            : -1;
    spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                     0.0f, 0.0f, 0,
                     0.0, 1.0, 1.0, 0xb4,
                     0xff, 0xff, 0xff, 0xff);

    player_.playerStateTimer = 0;
    if (group == 0 && slot == 1) {
        // Vivid Grenade's dedicated Bomb4 sound is queued before Bomb1 in the
        // original input branch.
        playPlayerSound(bombSoundHandles_[3]);
    }
    playPlayerSound(bombSoundHandles_[0]);
}

void StageRuntime::startFever(bool manualActivation) {
    if (manualActivation) {
        player_.playerStateTimer = 0;
        if (player_.invulnerableFrames > 279) {
            player_.invulnerableFrames = 280;
        }
    }
    player_.specialGauge = -kFeverActiveFrames;
    player_.bombLock = -120;
    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 150);
    spawnPlayerSideObject(0x18, player_.x, player_.y, 0.0, 0, 0, 0.0f);
    if (!manualActivation) {
        // Manual Fever created these nodes when it entered the armed sentinel;
        // the auto path creates them at activation instead.
        spawnFeverReadyEffects();
    }
    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int portraitIndex = 6 + group * 10;
    const int portraitHandle =
        portraitIndex < static_cast<int>(playerFrameFrames_.size())
            ? playerFrameFrames_[static_cast<std::size_t>(portraitIndex)]
            : -1;
    spawnStageEffect(0x16, portraitHandle, 0, 0x6f,
                     0.0f, 0.0f, 0,
                     0.0, 1.0, 1.0, 0x78,
                     0xff, 0xff, 0xff, 0xff);
    playPlayerSound(feverSoundHandles_[0]);
    playPlayerSound(feverSoundHandles_[1]);
}

void StageRuntime::armManualFever() {
    spawnFeverReadyEffects();
    playPlayerSound(feverSoundHandles_[3]);
    player_.specialGauge = kSpecialGaugeForcedFull;
}

void StageRuntime::spawnFeverReadyEffects() {
    const int orbitHandle = effectSmallFrames_.size() > 8
                                ? effectSmallFrames_[8]
                                : -1;
    spawnStageEffect(0x15, orbitHandle, 100, 0x4a,
                     player_.x, player_.y, 0,
                     0.0, 1.0, 1.0, 0,
                     0xff, 0xff, 0xff, 0xc0);

    const int bannerHandle = stateFrames_.size() > 21
                                 ? stateFrames_[21]
                                 : -1;
    const std::uint32_t random = stageScriptRandFromFrame(frame_);
    const std::uint16_t angle = normalizeAngle16(
        static_cast<int>(random % 0x2ee1u) - 0x5770);
    spawnStageEffect(0x17, bannerHandle, 200, 0x4b,
                     player_.x, player_.y - 120.0f, angle,
                     1.0, 1.0, 1.0, 0x78,
                     0xff, 0xff, 0xff, 0x80);
}

void StageRuntime::spawnFeverTrailEffect() {
    const int handle = effectMediumFrames_.empty()
                           ? -1
                           : effectMediumFrames_[0];
    const std::uint32_t random = stageScriptRandFromFrame(frame_);
    const float x = static_cast<float>(random % 0x2d1u);
    const std::uint16_t angle = normalizeAngle16(
        static_cast<int>(random % 0x7d1u) - 0x43e8);
    const double scale = scriptRandomHundredth(
        static_cast<std::uint32_t>(frame_), 1.5, 3.0);
    spawnStageEffect(0x18, handle, 200, 0x16,
                     x, 1120.0f, angle,
                     12.0, scale, scale, 0x168,
                     0xff, 0xff, 0xff, 0x60);
}

void StageRuntime::playPlayerSound(int handle, int volumeMultiplier) const {
    if (handle == -1) {
        return;
    }
    ChangeVolumeSoundMem(config_.soundEffectVolume * volumeMultiplier, handle);
    PlaySoundMem(handle, DX_PLAYTYPE_BACK, TRUE);
}

void StageRuntime::updateBossCountdownAudio(int hitPoints, int countdown) const {
    if (hitPoints < 8001 && frame_ % 16 == 0) {
        playPlayerSound(bossWeakenSoundHandle_, 0x10);
    }
    if (countdown >= 360 && countdown <= 600 && countdown % 60 == 0) {
        playPlayerSound(timerSoundHandle_, 0x10);
    }
    else if (countdown >= 1 && countdown <= 300 && countdown % 60 == 0) {
        playPlayerSound(timerSoundHandle_, 0x19);
    }
}

void StageRuntime::updatePlayerSideObjects() {
    for (std::size_t objectIndex = 0; objectIndex < playerSideObjects_.size(); ++objectIndex) {
        auto& object = playerSideObjects_[objectIndex];
        if (!object.active) {
            continue;
        }
        const int updateAge = object.age;
        const auto moveAlongAngle = [&object]() {
            const double angle = fixedAngleToRadiansDouble(object.angle16);
            object.x += static_cast<float>(std::cos(angle) * object.speedOrScale);
            object.y += static_cast<float>(std::sin(angle) * object.speedOrScale);
        };
        const auto reflectAndClamp = [this, &object]() {
            const float horizontalOrigin = player_.x / 6.0f;
            const float radius = std::max(0.0f, object.collisionRadiusOrScale);
            const int originalAngle = object.angle16;
            int reflectedAngle = originalAngle;
            if (object.x < horizontalOrigin + radius || object.x > horizontalOrigin + 600.0f - radius) {
                reflectedAngle = 0x8000 - originalAngle;
            }
            if (object.y < radius || object.y > 720.0f - radius) {
                reflectedAngle = -originalAngle;
            }
            object.angle16 = normalizeAngle16(reflectedAngle);
            object.x = clampFloat(object.x, horizontalOrigin + radius, horizontalOrigin + 600.0f - radius);
            object.y = clampFloat(object.y, radius, 720.0f - radius);
        };
        const auto spawnOrangeBombTrail = [this, &object, updateAge]() {
            const int handle = effectSmallFrames_.empty()
                                   ? -1
                                   : effectSmallFrames_[0];
            const std::uint32_t radiusRandom = stageScriptRandFromFrame(
                frame_ + updateAge * 0x457);
            const int offsetRadius = static_cast<int>(radiusRandom % 0x33u);
            const std::uint16_t offsetAngle = scriptRandomAngle(
                static_cast<std::uint32_t>(frame_ + updateAge * 0x6f));
            const double radians = fixedAngleToRadiansDouble(offsetAngle);
            spawnStageEffect(
                0x08, handle, 100, 0x3b,
                object.x + static_cast<float>(std::cos(radians) * offsetRadius),
                object.y + static_cast<float>(std::sin(radians) * offsetRadius),
                0, 0.0, 0.8, 0.8, 0x14,
                0xff, 0xc0, 0x40, 0x80);
        };

        if (object.type >= 0 && object.type <= 0x0a) {
            moveAlongAngle();
            if (object.type == 0) {
                object.damageOrLifetime = updateAge < 0x11
                                              ? 0x82 - updateAge * 5
                                              : 0x32;
            }
            else if (object.type == 1) {
                object.damageOrLifetime = updateAge < 0x11
                                              ? 0xa0 - updateAge * 5
                                              : 0x50;
            }
            if (object.type >= 8 && object.type <= 10 && updateAge < 60) {
                const int group = std::clamp(config_.setupGroup, 0, 2);
                if (group < 2) {
                    const std::uint16_t target = nearestTargetAngleForPlayerShot(object);
                    const int turnStep = group == 0 ? (updateAge + 16) * 0x20 : 0x200;
                    object.angle16 = approachAngle16(object.angle16, target, turnStep);
                }
            }
            object.drawAngle16 = object.angle16;
            if (object.type >= 8 && object.type <= 10 && config_.setupGroup == 0) {
                object.drawAngle16 = normalizeAngle16(
                    static_cast<int>(object.angle16) + updateAge * 0x400);
            }
            const float radius = std::max(0.0f, object.collisionRadiusOrScale);
            const float horizontalOrigin = player_.x / 6.0f;
            if (object.x < horizontalOrigin - radius - 160.0f ||
                object.x > horizontalOrigin + radius + 760.0f ||
                object.y < -radius - 160.0f || object.y > radius + 880.0f) {
                object.active = false;
            }
        }
        else {
            switch (object.type) {
            case 0x0b:
                if (updateAge == 0) {
                    spawnPlayerSideObject(0x1a, player_.x, player_.y, 0.0, 0, 0, 300.0f);
                }
                if (updateAge == 0 || updateAge == 8 || updateAge == 16 || updateAge == 24) {
                    const std::size_t slot = static_cast<std::size_t>(updateAge / 8);
                    const auto angle16 = player_.optionAngle16[slot];
                    const float angle = fixedAngleToRadians(angle16);
                    spawnPlayerSideObject(0x0c,
                                          player_.optionX[slot] + std::cos(angle) * 40.0f,
                                          player_.optionY[slot] + std::sin(angle) * 40.0f,
                                          20.0, angle16, 0, 45.0f);
                    playPlayerSound(bombSoundHandles_[1], 0x13);
                }
                if (updateAge == 180) {
                    object.active = false;
                }
                break;
            case 0x0c: {
                moveAlongAngle();
                if (updateAge < 20) {
                    reflectAndClamp();
                }
                const float radius = std::max(0.0f, object.collisionRadiusOrScale);
                const float horizontalOrigin = player_.x / 6.0f;
                bool terminate = object.y < 50.0f || updateAge == 148;
                if (updateAge >= 20) {
                    terminate = terminate || object.x < horizontalOrigin - radius ||
                                object.x > horizontalOrigin + 600.0f + radius ||
                                object.y < -radius || object.y > 720.0f + radius;
                }
                if (terminate) {
                    spawnPlayerSideObject(0x0d, object.x, object.y, 0.0, 0, 16, 0.0f);
                    playPlayerSound(bombSoundHandles_[2]);
                    object.active = false;
                }
                // The original still appends this terminal-frame trail after
                // it clears the projectile's active flag.
                spawnOrangeBombTrail();
                break;
            }
            case 0x0d:
                if (updateAge < 10) {
                    object.collisionRadiusOrScale = sineEaseIn(updateAge, 10, 160.0f);
                }
                else if (updateAge >= 120 && updateAge < 130) {
                    object.collisionRadiusOrScale = sineEaseOut(updateAge - 120, 10, 160.0f);
                }
                else {
                    object.collisionRadiusOrScale = updateAge < 130 ? 160.0f : 0.0f;
                }
                if (updateAge == 130) {
                    object.active = false;
                }
                break;
            case 0x0e:
                if (updateAge == 0) {
                    spawnPlayerSideObject(0x19, player_.x, player_.y, 0.0, 0, 0, 0.0f);
                }
                if (updateAge < 30) {
                    object.speedOrScale = std::max(0.0, object.speedOrScale - 0.6);
                    moveAlongAngle();
                    reflectAndClamp();
                    spawnOrangeBombTrail();
                }
                else {
                    if (updateAge == 30) {
                        playPlayerSound(bombSoundHandles_[4]);
                        object.speedOrScale = 1.0;
                        object.damageOrLifetime = 32;
                    }
                    moveAlongAngle();
                    object.collisionRadiusOrScale = updateAge < 40
                                                        ? sineEaseIn(updateAge - 30, 10, 250.0f)
                                                        : 250.0f;
                    if (updateAge % 8 == 0) {
                        const int frameIndex = 2 + ((updateAge & 0x0f) >> 3);
                        const int handle =
                            frameIndex < static_cast<int>(effectLargeFrames_.size())
                                ? effectLargeFrames_[static_cast<std::size_t>(frameIndex)]
                                : -1;
                        spawnStageEffect(
                            0x20, handle, 600, 0x3c,
                            object.x, object.y, 0,
                            0.0,
                            static_cast<double>(object.collisionRadiusOrScale) / 150.0,
                            static_cast<double>(object.collisionRadiusOrScale) / 120.0,
                            0x28, 0xff, 0xff, 0xff, 0xff);
                    }
                }
                if (updateAge == 180) {
                    object.active = false;
                }
                break;
            case 0x0f:
                object.x = player_.x;
                object.y = player_.y;
                if (updateAge % 3 == 0) {
                    for (std::size_t slot = 0; slot < player_.optionX.size(); ++slot) {
                        spawnPlayerSideObject(0x10, player_.optionX[slot], player_.optionY[slot],
                                              50.0, player_.optionAngle16[slot], 90, 60.0f);
                    }
                    playPlayerSound(bombSoundHandles_[5], 0x10);
                }
                if (updateAge % 30 == 0) {
                    const int handle = effectLargeFrames_.empty()
                                           ? -1
                                           : effectLargeFrames_[0];
                    spawnStageEffect(0x13, handle, 600, 0x5b,
                                     object.x, object.y, 0,
                                     0.0, 0.0, 0.0, 0,
                                     0xff, 0xff, 0xff, 0xff);
                }
                if (updateAge == 180) {
                    object.active = false;
                }
                break;
            case 0x10:
                moveAlongAngle();
                object.drawAngle16 = object.angle16;
                spawnStageEffect(
                    0x05,
                    effectMediumFrames_.size() > 7 ? effectMediumFrames_[7] : -1,
                    200, 0x3b, object.x, object.y, object.angle16,
                    0.0, 1.0, 1.0, 0x0c,
                    0xff, 0xff, 0xff, 0x80);
                if (object.y < -500.0f) {
                    object.active = false;
                }
                break;
            case 0x11:
                if (updateAge == 0) {
                    spawnPlayerSideObject(0x18, player_.x, player_.y, 0.0, 0, 0, 0.0f);
                    player_.shotVariant = 600;
                }
                if (updateAge == 600 || (updateAge > 59 && player_.bombLock == -179)) {
                    object.active = false;
                }
                break;
            case 0x12:
                if (updateAge % 40 == 0 && updateAge < 151) {
                    const int handle = effectLargeFrames_.empty()
                                           ? -1
                                           : effectLargeFrames_[0];
                    spawnStageEffect(0x13, handle, 600, 0x5b,
                                     player_.x, player_.y, 0,
                                     0.0, 0.0, 0.0, 0,
                                     0xff, 0xff, 0xff, 0xff);
                    const auto randomAngle = normalizeAngle16(static_cast<int>(
                        deterministicUnit(frame_, static_cast<int>(objectIndex) * 0x457 + updateAge) *
                        static_cast<float>(kFixedAngleFullCircle)));
                    spawnPlayerSideObject(0x13, player_.x, player_.y, 0.0, randomAngle, 0, 0.0f);
                }
                if (updateAge == 180) {
                    object.active = false;
                }
                break;
            case 0x13:
                if (updateAge % 5 == 0) {
                    const float distance = 80.0f + static_cast<float>(updateAge) * 8.0f;
                    for (int i = 0; i < 3; ++i) {
                        const auto radialAngle = normalizeAngle16(
                            static_cast<int>(object.angle16) + updateAge * 999 + i * 0x5555);
                        const float radians = fixedAngleToRadians(radialAngle);
                        const auto drawAngle = normalizeAngle16(static_cast<int>(
                            deterministicUnit(frame_ + i, static_cast<int>(objectIndex) * 0xd05 + updateAge) *
                            static_cast<float>(kFixedAngleFullCircle)));
                        spawnPlayerSideObject(0x14,
                                              object.x + std::cos(radians) * distance,
                                              object.y + std::sin(radians) * distance,
                                              0.0, drawAngle, 5, 120.0f);
                    }
                    playPlayerSound(bombSoundHandles_[6], 0x13);
                }
                if (updateAge == 90) {
                    object.active = false;
                }
                break;
            case 0x14:
                object.collisionRadiusOrScale =
                    sineEaseIn(updateAge, 30, object.auxRadiusOrScale);
                if (updateAge == 30) {
                    object.active = false;
                }
                break;
            case 0x15:
                object.x = player_.x;
                object.y = player_.y;
                if (updateAge < 32) {
                    object.collisionRadiusOrScale = sineEaseIn(updateAge, 32, 200.0f);
                }
                else if (updateAge >= 230 && updateAge < 240) {
                    object.collisionRadiusOrScale = sineEaseOut(updateAge - 230, 10, 200.0f);
                }
                else {
                    object.collisionRadiusOrScale = updateAge < 240 ? 200.0f : 0.0f;
                }
                if (updateAge % 20 == 0) {
                    playPlayerSound(bombSoundHandles_[7], 0x13);
                }
                if (updateAge == 240) {
                    object.active = false;
                }
                break;
            case 0x16:
                if (updateAge == 0) {
                    const int particleHandle = playerFrames_.size() > 14
                                                   ? playerFrames_[14]
                                                   : -1;
                    // FUN_140109780 emits 32 independent guard sparks here.
                    for (int i = 0; i < 32; ++i) {
                        const std::uint32_t angleSeed =
                            static_cast<std::uint32_t>(frame_ + i * 0x21);
                        const std::uint32_t scaleSeed =
                            static_cast<std::uint32_t>(frame_ + i * 0xd05);
                        const std::uint32_t speedSeed =
                            static_cast<std::uint32_t>(frame_ + i * 0x14d);
                        const double scale = scriptRandomHundredth(
                            scaleSeed, 1.1, 2.2);
                        spawnStageEffect(
                            0x2c, particleHandle, 80, 0x48,
                            object.x, object.y, scriptRandomAngle(angleSeed),
                            scriptRandomHundredth(speedSeed, 16.0, 26.0),
                            scale, scale, 0,
                            0xff, 0xff, 0xff, 0xc0);
                    }
                }
                object.collisionRadiusOrScale = updateAge < 32
                                                    ? 20.0f + sineEaseIn(
                                                          updateAge, 32,
                                                          std::max(0.0f, object.auxRadiusOrScale - 20.0f))
                                                    : object.auxRadiusOrScale;
                if (updateAge == 96) {
                    object.active = false;
                }
                break;
            case 0x17:
            case 0x18:
                if (updateAge == 0) {
                    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 100);
                }
                object.collisionRadiusOrScale += 25.0f;
                if (updateAge == 48) {
                    object.active = false;
                }
                break;
            case 0x19:
                if (updateAge == 0) {
                    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 100);
                }
                object.collisionRadiusOrScale += 50.0f;
                if (updateAge == 24) {
                    object.active = false;
                }
                break;
            case 0x1a:
                object.collisionRadiusOrScale = sineEaseIn(updateAge, 24, object.auxRadiusOrScale);
                if (updateAge == 24) {
                    object.active = false;
                }
                break;
            default:
                if (object.damageOrLifetime > 0 && updateAge == object.damageOrLifetime) {
                    object.active = false;
                }
                break;
            }
        }
        ++object.age;
    }
}

std::uint16_t StageRuntime::nearestTargetAngleForPlayerShot(const PlayerSideObject& object) const {
    const StageEnemy* nearest = nullptr;
    float nearestSurfaceDistance = 2000.0f;
    const float horizontalOrigin = player_.x / 6.0f;
    bool hasCommonTarget = false;
    for (const auto& enemy : enemies_) {
        if (!enemy.active || !enemy.targetable) {
            continue;
        }
        const float radius = static_cast<float>(std::max(0, enemy.radius));
        if (enemy.x < horizontalOrigin - (radius + 100.0f) ||
            enemy.x > horizontalOrigin + radius + 700.0f ||
            enemy.y < -(radius + 100.0f) || enemy.y > radius + 820.0f) {
            continue;
        }
        hasCommonTarget = true;
        const float dx = enemy.x - object.x;
        const float dy = enemy.y - object.y;
        const float surfaceDistance = std::sqrt(dx * dx + dy * dy) - radius;
        if (surfaceDistance < nearestSurfaceDistance) {
            nearestSurfaceDistance = surfaceDistance;
            nearest = &enemy;
        }
    }
    if (!hasCommonTarget) {
        return object.angle16;
    }
    const float targetX = nearest != nullptr ? nearest->x : player_.x;
    const float targetY = nearest != nullptr ? nearest->y : -65536.0f;
    return radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(targetY - object.y),
                   static_cast<double>(targetX - object.x)));
}

void StageRuntime::emitPlayerNormalShot() {
    constexpr std::uint16_t up = 0xc000;
    // FUN_14010db70 selects the enhanced family while DAT_140e44658 is active
    // or DAT_140e45d18 is negative. A full, ready positive gauge remains type 0.
    const bool enhanced = player_.shotVariant != 0 || player_.specialGauge < 0;
    const int mainType = enhanced ? 1 : 0;
    const double mainSpeed = mainType == 0 ? 25.0 : 40.0;
    const int mainDamage = mainType == 0 ? 0x82 : 0x96;
    const int mainRadius = mainType == 0 ? 30 : 60;
    spawnPlayerSideObject(mainType, player_.x + 20.0f, player_.y - 30.0f,
                          mainSpeed, up, mainDamage, mainRadius);
    spawnPlayerSideObject(mainType, player_.x - 20.0f, player_.y - 30.0f,
                          mainSpeed, up, mainDamage, mainRadius);

    const int group = std::clamp(config_.setupGroup, 0, 2);
    const int option0 = std::clamp(config_.optionSlots[0], 0, 1);
    const int option1 = std::clamp(config_.optionSlots[1], 0, 1);
    const int style = std::clamp(config_.optionSlots[3], 0, 3);
    const bool poweredForStance = player_.focused ? style >= 2 : (style & 1) != 0;

    int optionType = 0;
    int optionDamage = 0x32;
    double optionSpeed = enhanced ? 40.0 : 25.0;
    float muzzleOffset = enhanced ? 60.0f : 40.0f;
    int optionRadius = enhanced ? 60 : 30;

    if (!player_.focused) {
        const bool alternateFamily = group == 0 && option0 == 1;
        if (enhanced) {
            optionType = alternateFamily ? 10 : 4;
            optionDamage = alternateFamily ? 0x23 : 0x46;
        }
        else if (alternateFamily) {
            optionType = poweredForStance ? 9 : 8;
            optionDamage = poweredForStance ? 0x1e : 0x19;
        }
        else {
            optionType = poweredForStance ? 3 : 2;
            optionDamage = poweredForStance ? 0x3c : 0x32;
        }
    }
    else {
        const bool alternateFamily = group == 1 && option1 == 1;
        if (enhanced) {
            optionType = alternateFamily ? 10 : 7;
            optionDamage = alternateFamily ? 0x3f : 0x46;
        }
        else if (alternateFamily) {
            optionType = poweredForStance ? 9 : 8;
            optionDamage = poweredForStance ? 0x36 : 0x2d;
        }
        else {
            optionType = poweredForStance ? 6 : 5;
            optionDamage = poweredForStance ? 0x3c : 0x32;
        }

        // The focused group-0/option-1==0 branch keeps types 5/6/7 but uses
        // the lower 45/54/63 damage family.
        if (group == 0 && option1 == 0) {
            optionDamage = enhanced ? 0x3f : (poweredForStance ? 0x36 : 0x2d);
        }
    }

    if (!enhanced && poweredForStance) {
        optionSpeed = 30.0;
        muzzleOffset = 50.0f;
        optionRadius = 45;
    }

    for (int slot = 0; slot < 4; ++slot) {
        const std::size_t index = static_cast<std::size_t>(slot);
        const std::uint16_t angle16 = player_.optionAngle16[index];
        const double angle = fixedAngleToRadiansDouble(angle16);
        const float x = player_.optionX[index] + static_cast<float>(
            std::cos(angle) * static_cast<double>(muzzleOffset));
        const float y = player_.optionY[index] + static_cast<float>(
            std::sin(angle) * static_cast<double>(muzzleOffset));
        spawnPlayerSideObject(optionType, x, y, optionSpeed, angle16,
                              optionDamage, optionRadius);
    }
    playPlayerSound(enhanced ? bombSoundHandles_[5] : normalShotSoundHandle_,
                    enhanced ? 0x10 : 0x0c);
}

void StageRuntime::spawnPlayerSideObject(int type, float x, float y, double speedOrScale, std::uint16_t angle16, int damageOrLifetime, float collisionRadiusOrScale) {
    if (playerSideObjects_.size() >= kPlayerSideObjectCap) {
        return;
    }
    PlayerSideObject object;
    object.type = type;
    object.x = x;
    object.y = y;
    object.originX = x;
    object.originY = y;
    object.angle16 = angle16;
    object.drawAngle16 = angle16;
    object.speedOrScale = speedOrScale;
    object.damageOrLifetime = damageOrLifetime;
    object.collisionRadiusOrScale = collisionRadiusOrScale;
    object.auxRadiusOrScale = collisionRadiusOrScale;
    playerSideObjects_.push_back(object);
}

bool StageRuntime::enemyUsesMediumFrame(const StageEnemy& enemy) const {
    return stageUsesMediumFrame(enemy.spawnType);
}

int StageRuntime::enemyVisualFrameForSpawnType(const StageEnemy& enemy) const {
    switch (enemy.spawnType) {
    case 0x06:
    case 0x08: return 8 + (enemy.entityId % 3);
    case 0x09: return 11;
    case 0x0a: return 15;
    case 0x0b: return 4;
    case 0x0c: return 6;
    case 0x0d: return 9;
    case 0x0e: return 16 + (enemy.entityId % 6);
    case 0x0f: return 22 + (enemy.entityId % 4);
    case 0x10: return 26 + (enemy.entityId % 6);
    case 0x11: return 32 + (enemy.childIndex % 2);
    default: break;
    }
    return enemy.visualFrame;
}

int StageRuntime::playerSideObjectVisualFrame(const PlayerSideObject& object) const {
    const int group = std::clamp(config_.setupGroup, 0, 2);
    constexpr std::array<int, 3> kMainFrames{{0x1c, 0x2c, 0x49}};
    constexpr std::array<int, 3> kUnfocusedFrames{{0x1d, 0x3a, 0x4a}};
    constexpr std::array<int, 3> kFocusedFrames{{0x2b, 0x3b, 0x58}};
    constexpr std::array<int, 3> kTrackingFrames{{0x59, 0x67, 0x59}};
    switch (object.type) {
    case 0:
    case 1: return kMainFrames[static_cast<std::size_t>(group)];
    case 2:
    case 3:
    case 4: return kUnfocusedFrames[static_cast<std::size_t>(group)];
    case 5:
    case 6:
    case 7: return kFocusedFrames[static_cast<std::size_t>(group)];
    case 8:
    case 9:
    case 10: return kTrackingFrames[static_cast<std::size_t>(group)];
    default: return kMainFrames[static_cast<std::size_t>(group)];
    }
}

bool StageRuntime::playerSideObjectCanHitEnemy(const PlayerSideObject& object) const {
    (void)object;
    return true;
}

bool StageRuntime::playerSideObjectCanCancelProjectile(const PlayerSideObject& object) const {
    const unsigned type = static_cast<unsigned>(object.type);
    return ((type < 0x1fU) && (((0x63737000U >> (type & 0x1fU)) & 1U) != 0U)) || object.type == 0x1a;
}

int StageRuntime::playerSideObjectDamage(const PlayerSideObject& object) const {
    return object.damageOrLifetime;
}

void StageRuntime::handleCollisions() {
    handlePlayerSideObjectEnemyCollisions();
    handlePlayerSideObjectProjectileCancels();
    handleEnemyProjectilePlayerHitAndGraze();
}

void StageRuntime::handlePlayerSideObjectEnemyCollisions() {
    // FUN_1400cc2f0 is called once per targetable enemy and then walks the
    // complete player-object list. It deliberately does not test object.active:
    // terminal-frame objects and shots consumed by an earlier enemy still run.
    for (auto& enemy : enemies_) {
        // The entity dispatcher tests targetability after calling the helper;
        // it does not re-test the entity's active link flag. Preserve that
        // terminal collision call for exact helpers that queued a body before
        // setting their link flag inactive in the death/bounds tail.
        const bool terminalExactEnemy =
            (((enemy.spawnType >= 0x0a && enemy.spawnType <= 0x0f) ||
              (enemy.spawnType >= 0x32 && enemy.spawnType <= 0x34) ||
              enemy.spawnType == 0x42 || enemy.spawnType == 0x43) &&
             enemy.drawBodyThisFrame);
        if ((!enemy.active && !terminalExactEnemy) || !enemy.targetable) {
            continue;
        }
        std::uint32_t collisionOrdinal = 0;
        for (std::size_t objectIndex = 0; objectIndex < playerSideObjects_.size(); ++objectIndex) {
            if (!playerSideObjectCanHitEnemy(playerSideObjects_[objectIndex])) {
                continue;
            }
            auto& object = playerSideObjects_[objectIndex];
            const float radius = object.collisionRadiusOrScale + static_cast<float>(enemy.radius);
            if (distanceSquared(object.x, object.y, enemy.x, enemy.y) >= radius * radius ||
                enemy.radius == 0) {
                continue;
            }

            const int objectType = object.type;
            const std::uint32_t collisionSeed =
                static_cast<std::uint32_t>(frame_) + ++collisionOrdinal;
            const float dx = enemy.x - object.x;
            const float dy = enemy.y - object.y;
            const double contactAngle = std::atan2(
                static_cast<double>(dy), static_cast<double>(dx));
            const float unitX = static_cast<float>(std::cos(contactAngle));
            const float unitY = static_cast<float>(std::sin(contactAngle));
            const float objectContactX =
                object.x + unitX * object.collisionRadiusOrScale;
            const float objectContactY =
                object.y + unitY * object.collisionRadiusOrScale;
            const float enemyContactX = enemy.x - unitX * static_cast<float>(enemy.radius);
            const float enemyContactY = enemy.y - unitY * static_cast<float>(enemy.radius);
            const auto spawnHitSpark = [this, collisionSeed](float x, float y) {
                const int sparkHandle = playerFrames_.size() > 14
                                            ? playerFrames_[14]
                                            : -1;
                spawnStageEffect(
                    0x0e, sparkHandle, 80, 0x48, x, y,
                    scriptRandomAngle(collisionSeed * 0x42u),
                    scriptRandomHundredth(collisionSeed * 0x2cu, 5.0, 8.0),
                    0.3, 0.3, 0x0c,
                    0xff, 0xff, 0xff, 0xff);
            };
            if ((objectType >= 0 && objectType <= 0x0a) || objectType == 0x10) {
                addRunScore(0x10);
                player_.stockProgress += object.age < 0x11
                                             ? (0x15 - object.age) * 2
                                             : 10;

                if (player_.specialGauge < 0) {
                    const float dxToPlayer = player_.x - enemy.x;
                    const float dyToPlayer = player_.y - enemy.y;
                    const float playerDistance =
                        std::sqrt(dxToPlayer * dxToPlayer + dyToPlayer * dyToPlayer);
                    const int chanceMaximum = std::max(
                        2, static_cast<int>(playerDistance -
                                            static_cast<float>(enemy.radius)) /
                                   60 +
                               2);
                    if (stageRandomIntInclusive(
                            static_cast<std::uint32_t>(frame_) + collisionSeed,
                            0, chanceMaximum) == 0) {
                        spawnRewardItem(
                            0, objectContactX, objectContactY,
                            scriptRandomAngle(collisionSeed), 2.0f, 30);
                    }
                }

                spawnHitSpark(objectContactX, objectContactY);
                if (objectType <= 0x0a) {
                    int frameIndex = playerSideObjectVisualFrame(object);
                    if (config_.setupGroup == 2 && objectType < 2) {
                        frameIndex = 0x3f;
                    }
                    else if (config_.setupGroup == 2 &&
                             objectType >= 2 && objectType <= 4) {
                        frameIndex = 0x40;
                    }
                    const int trailHandle =
                        frameIndex >= 0 && frameIndex < static_cast<int>(playerFrames_.size())
                            ? playerFrames_[static_cast<std::size_t>(frameIndex)]
                            : -1;
                    const double baseScale =
                        objectType >= 2 && objectType <= 4 ? 1.5 : 1.0;
                    double scaleX = baseScale;
                    double scaleY = 1.0;
                    if ((0x248u >> static_cast<unsigned>(objectType)) & 1u) {
                        scaleX *= 1.5;
                        scaleY = 1.5;
                    }
                    else if ((0x492u >> static_cast<unsigned>(objectType)) & 1u) {
                        scaleX *= 2.0;
                        scaleY = 2.0;
                    }
                    spawnStageEffect(
                        0x0d, trailHandle, 80, 0x2d,
                        object.x, object.y, object.angle16,
                        object.speedOrScale / 5.0, scaleX, scaleY, 8,
                        0xff, 0xff, 0xff, 0x60);
                }
                else {
                    const std::uint32_t chanceRandom =
                        stageScriptRandFromFrame(static_cast<int>(collisionSeed * 0x16u));
                    if (chanceRandom % 6u == 0u) {
                        const std::uint32_t graphRandom = stageScriptRandFromFrame(
                            static_cast<int>(collisionSeed * 0xdeu));
                        const int graphIndex = 8 + static_cast<int>(graphRandom & 3u);
                        const int graphHandle =
                            graphIndex < static_cast<int>(effectMediumFrames_.size())
                                ? effectMediumFrames_[static_cast<std::size_t>(graphIndex)]
                                : -1;
                        spawnStageEffect(
                            0x17, graphHandle, 200, 0x4b,
                            objectContactX, objectContactY,
                            scriptRandomAngle(collisionSeed * 0x8aeu),
                            2.0, 1.0, 1.0, 0x18,
                            0xff, 0xff, 0xff, 0x80);
                    }
                    const int trailHandle = effectMediumFrames_.size() > 7
                                                ? effectMediumFrames_[7]
                                                : -1;
                    spawnStageEffect(
                        0x0d, trailHandle, 200, 0x2d,
                        object.x, object.y, object.angle16,
                        object.speedOrScale / 5.0, 3.0, 2.0, 8,
                        0xff, 0xff, 0xff, 0x60);
                }
                object.active = false;
            }
            else if (objectType == 0x0c) {
                const float impactX = object.x;
                const float impactY = object.y;
                object.active = false;
                spawnPlayerSideObject(0x0d, impactX, impactY, 0.0, 0, 10, 0.0f);
                playPlayerSound(bombSoundHandles_[2]);
            }
            else if (objectType == 0x0d || objectType == 0x0e || objectType == 0x15) {
                player_.stockProgress += 5;
            }
            else if (objectType == 0x14) {
                player_.stockProgress += 3;
            }

            if ((objectType == 0x0d || objectType == 0x0e ||
                 objectType == 0x14 || objectType == 0x15) &&
                enemy.age % 3 == 0) {
                spawnHitSpark(enemyContactX, enemyContactY);
            }

            const int damage = playerSideObjectDamage(playerSideObjects_[objectIndex]);
            if (damage > 0) {
                enemy.hp -= damage;
                const float deltaX = player_.x - enemy.x;
                const float deltaY = player_.y - enemy.y;
                const float playerDistance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
                const int attenuation = std::max(
                    0, static_cast<int>(playerDistance) - enemy.radius - 60);
                playPlayerSound(shotHitSoundHandle_, (140 - attenuation / 10) / 10);
                if (enemy.spawnType == 0x3d && enemy.hp < 1) {
                    // The original parent is followed by its children in the
                    // live entity list. They see the post-collision owner HP in
                    // this same traversal and clear themselves before unlink.
                    for (auto& child : enemies_) {
                        if (child.spawnType == 0x3e && child.parentEntityId == enemy.entityId) {
                            child.active = false;
                        }
                    }
                }
            }
            const auto typeBit = [](int type, int base, int count,
                                    std::uint64_t mask) {
                const int offset = type - base;
                return offset >= 0 && offset < count &&
                       ((mask >> static_cast<unsigned>(offset)) & 1ULL) != 0ULL;
            };
            const int enemyType = enemy.spawnType;
            const bool usesHitFeedback =
                (enemyType >= 0x138 && enemyType < 0x140) ||
                typeBit(enemyType, 0x000, 0x2f, 0x400100010000ULL) ||
                typeBit(enemyType, 0x02f, 0x28, 0xb1001b0003ULL) ||
                (enemyType >= 0x143 && enemyType < 0x146) ||
                typeBit(enemyType, 0x066, 0x1e, 0x2008001fULL) ||
                typeBit(enemyType, 0x084, 0x29, 0x1670000000fULL) ||
                (enemyType >= 0x0b8 && enemyType < 0x0bc) ||
                (enemyType >= 0x146 && enemyType < 0x14b) ||
                enemyType == 0x0c8 ||
                typeBit(enemyType, 0x111, 0x3c, 0xc01800000000003ULL) ||
                typeBit(enemyType, 0x0c3, 0x2f, 0x4c0000000001ULL) ||
                typeBit(enemyType, 0x113, 0x0e, 0x3cf9ULL) ||
                typeBit(enemyType, 0x121, 0x32, 0x2000000001073ULL);
            if (usesHitFeedback && damage > 0) {
                int feedbackPeriod = 12;
                switch (objectType) {
                case 0x0d: feedbackPeriod = 0xf0; break;
                case 0x0e:
                case 0x11: feedbackPeriod = 0x3c; break;
                case 0x10: feedbackPeriod = 9; break;
                case 0x14: feedbackPeriod = 0x168; break;
                case 0x15: feedbackPeriod = 0x5a; break;
                case 0x1b: feedbackPeriod = 0x78; break;
                default: break;
                }
                if (stageRandomIntInclusive(
                        static_cast<std::uint32_t>(frame_) + collisionSeed,
                        0, feedbackPeriod) == 0) {
                    const std::uint16_t pointAngle =
                        scriptRandomUpperHalfAngle(collisionSeed);
                    const int pointRadius = stageRandomIntInclusive(
                        collisionSeed, 0, std::max(0, enemy.radius));
                    const double pointRadians = fixedAngleToRadiansDouble(pointAngle);
                    const float pointX = enemy.x + static_cast<float>(
                        std::cos(pointRadians) * static_cast<double>(pointRadius));
                    const float pointY = enemy.y - 100.0f + static_cast<float>(
                        std::sin(pointRadians) * static_cast<double>(pointRadius));

                    const float feedbackDeltaX = player_.x - enemy.x;
                    const float feedbackDeltaY = player_.y - enemy.y;
                    const float feedbackPlayerDistance = std::sqrt(
                        feedbackDeltaX * feedbackDeltaX +
                        feedbackDeltaY * feedbackDeltaY);
                    const int surfaceDistance =
                        static_cast<int>(feedbackPlayerDistance) - enemy.radius;
                    int multiplier = 1;
                    if (surfaceDistance < 0x97) {
                        multiplier = 10;
                    }
                    else if (surfaceDistance < 0x1c2) {
                        multiplier = (0x1c2 - surfaceDistance) / 0x1e;
                    }
                    if (player_.specialGauge < 0) {
                        multiplier = 10;
                    }
                    else {
                        multiplier = std::max(multiplier, 1);
                    }

                    const std::uint32_t feedbackAngleSeed =
                        collisionSeed * 0x1bcu + static_cast<std::uint32_t>(frame_);
                    spawnStageEffect(
                        0x19, -1, 0, 0x42, pointX, pointY,
                        scriptRandomUpperHalfAngle(feedbackAngleSeed),
                        1.0, static_cast<double>(multiplier),
                        static_cast<double>(multiplier) * 0.1 + 0.5,
                        0x32, 0xff, 0xff, 0xff, 0xc0);
                }
            }
            const bool usesHeavyHitSound =
                enemyType == 0x0c3 ||
                typeBit(enemyType, 0x127, 0x2a, 0x28000008001ULL);
            if (usesHeavyHitSound && objectType != 0x1e) {
                playPlayerSound(shotHit2SoundHandle_, 9);
            }
        }
    }
}

void StageRuntime::handlePlayerSideObjectProjectileCancels() {
    // FUN_1400cd750 filters the mixed player-side list with the original
    // 0x63737000 type bitmask (plus a separate 0x1a path) before testing enemy
    // projectiles. Keep this separate from enemy-hit logic: many visible player
    // objects are not bullet-cancel fields.
    for (auto& object : playerSideObjects_) {
        if (!playerSideObjectCanCancelProjectile(object)) {
            continue;
        }
        const float objectRadius = std::max(0.0f, object.collisionRadiusOrScale);
        const bool noReward = object.type == 0x16 || object.type == 0x1e;
        const bool ignoresProjectileFlags =
            object.type == 0x18 || object.type == 0x19 || object.type == 0x1a;
        for (std::size_t projectileIndex = 0; projectileIndex < enemyProjectiles_.size();
             ++projectileIndex) {
            auto& projectile = enemyProjectiles_[projectileIndex];
            if (!ignoresProjectileFlags &&
                (!projectile.active || !projectile.collisionEnabled || projectile.radius == 0)) {
                continue;
            }
            const float radius = objectRadius + static_cast<float>(projectile.radius);
            if (distanceSquared(object.x, object.y, projectile.x, projectile.y) >= radius * radius) {
                continue;
            }
            projectile.active = false;
            projectile.grazeOrHitProcessed = true;
            if (!noReward) {
                const int rewardType = projectile.radius < 2 ? 3 : 4;
                spawnRewardItem(rewardType, projectile.x, projectile.y,
                                cancelRewardAngle(frame_, projectileIndex), 2.0f,
                                rewardType == 4 ? 45 : 30);
            }
        }
    }
}

void StageRuntime::handleEnemyProjectilePlayerHitAndGraze() {
    // FUN_1400cbd30 reconstructs the effective point from the raw node position
    // and accumulated radial travel. Integrated steering stores its raw point
    // directly in x/y; the other helpers retain it in anchorX/anchorY.
    const int playerHitRadius =
        static_cast<std::uint32_t>(player_.focusTransition + 2) > 4U ? 3 : 4;
    bool playerHit = false;
    std::uint32_t projectileOrdinal = 0;
    for (auto& projectile : enemyProjectiles_) {
        if (!projectile.active) {
            continue;
        }
        const std::uint32_t ordinal = projectileOrdinal++;
        if (projectile.radius <= 0) {
            continue;
        }
        const bool integratedPosition =
            projectile.projectileId == 0x0c || projectile.projectileId == 0x0e ||
            (projectile.projectileId >= 0x23 && projectile.projectileId <= 0x27) ||
            projectile.projectileId == 0x2c || projectile.projectileId == 0x2d ||
            projectile.projectileId == 0x35 || projectile.projectileId == 0x36;
        const float rawX = integratedPosition ? projectile.x : projectile.anchorX;
        const float rawY = integratedPosition ? projectile.y : projectile.anchorY;
        const double angle = fixedAngleToRadiansDouble(projectile.angle16);
        const float testX = rawX + static_cast<float>(
            std::cos(angle) * static_cast<double>(projectile.speedOrAccelHint));
        const float testY = rawY + static_cast<float>(
            std::sin(angle) * static_cast<double>(projectile.speedOrAccelHint));
        const float distSq = distanceSquared(testX, testY, player_.x, player_.y);
        const int hitRadius = projectile.radius + playerHitRadius;
        if (distSq <= static_cast<float>(hitRadius * hitRadius)) {
            projectile.active = false;
            playerHit = true;
            continue;
        }
        const int grazeRadius = projectile.radius + kGrazeMargin;
        if (config_.routeMode >= 0 &&
            pauseFlowState_ != PauseFlowState::GameOverDelay &&
            projectile.collisionEnabled && !projectile.grazeOrHitProcessed &&
            distSq <= static_cast<float>(grazeRadius * grazeRadius)) {
            projectile.grazeOrHitProcessed = true;
            const std::uint16_t aimAngle = radiansToFixedAngleTrunc(std::atan2(
                static_cast<double>(player_.y - testY),
                static_cast<double>(player_.x - testX)));
            const std::uint16_t feedbackAngle = normalizeAngle16(
                static_cast<int>(scriptRandomAngle(
                    static_cast<std::uint32_t>(frame_) + 112u + ordinal)) +
                static_cast<int>(aimAngle) + 0x4000);
            spawnStageEffect(0x19, -1, 0, 0x42, testX, testY, feedbackAngle,
                             1.0, 1.0, 0.5, 50,
                             0xff, 0xff, 0xff, 0xc0);
            const int grazeParticleHandle = playerFrames_.size() > 14
                                                ? playerFrames_[14]
                                                : -1;
            const std::uint32_t particleSpeedSeed =
                static_cast<std::uint32_t>(frame_) + 0x2710u + ordinal;
            const std::uint32_t particleAngleSeed =
                static_cast<std::uint32_t>(frame_) + 1u + ordinal;
            spawnStageEffect(
                0x0e, grazeParticleHandle, 80, 0x44,
                (testX + player_.x) * 0.5f, (testY + player_.y) * 0.5f,
                scriptRandomAngle(particleAngleSeed),
                scriptRandomHundredth(particleSpeedSeed, 5.0, 8.0),
                0.3, 0.3, 0x0c,
                0xff, 0xff, 0xff, 0xff);
            playPlayerSound(grazeSoundHandle_, 0x10);
            ++player_.graze;
            hudSpecialGaugeFlashTimer_ = 60;
        }
    }
    if (playerHit && player_.invulnerableFrames == 0) {
        player_.playerStateTimer = 280;
        player_.invulnerableFrames = 300;
        playPlayerSound(missSoundHandle_, 0x19);
    }
}

void StageRuntime::spawnProjectileNode(int visualSelector, int projectileId, float x, float y, float angle, double speed, int radius) {
    spawnProjectileNode(visualSelector, projectileId, x, y, radiansToFixedAngle(angle), 0.0f, speed, radius, 0);
}

void StageRuntime::spawnProjectileNode(int visualSelector, int projectileId, float x, float y, std::uint16_t angle16, float initialTravel, double speed, int radius, int arg8OrAux) {
    if (enemyProjectiles_.size() >= kProjectileCap) {
        return;
    }
    StageProjectile projectile;
    projectile.visualSelector = visualSelector;
    projectile.projectileId = projectileId;
    projectile.x = x;
    projectile.y = y;
    projectile.anchorX = x;
    projectile.anchorY = y;
    projectile.prevX = x;
    projectile.prevY = y;
    projectile.speedOrAccelHint = initialTravel;
    projectile.angle16 = angle16;
    projectile.prevAngle16 = angle16;
    projectile.angle = fixedAngleToRadians(angle16);
    projectile.speed = speed;
    projectile.baseSpeed = speed;
    projectile.radius = radius;
    projectile.arg8OrAux = arg8OrAux;
    projectile.collisionEnabled = true;
    updateProjectileVelocity(projectile);
    enemyProjectiles_.push_back(projectile);
    ++enemyProjectileSpawnsThisSecond_;
}

void StageRuntime::updateProjectileVelocity(StageProjectile& projectile) {
    projectile.angle = fixedAngleToRadians(projectile.angle16);
    const float movementSpeed = static_cast<float>(projectile.speed) + projectile.speedOrAccelHint;
    projectile.vx = std::cos(projectile.angle) * movementSpeed;
    projectile.vy = std::sin(projectile.angle) * movementSpeed;
}

void StageRuntime::spawnProjectileSpread(int visualSelector, int projectileId, float x, float y, float centerAngle, double speed, int radius, int count, float spreadRadians) {
    const int spreadAngle16 = spreadRadians >= kTau - 0.001f
                                  ? kFixedAngleFullCircle
                                  : static_cast<int>(std::lround(spreadRadians * static_cast<float>(kFixedAngleFullCircle) / kTau));
    spawnProjectileSpread(visualSelector, projectileId, x, y, radiansToFixedAngle(centerAngle), 0.0f, speed, radius, count, spreadAngle16, 0);
}

void StageRuntime::spawnProjectileSpread(int visualSelector, int projectileId, float x, float y, std::uint16_t centerAngle16, float initialTravel, double speed, int radius, int count, int spreadAngle16, int arg8OrAux) {
    if (count <= 0) {
        return;
    }
    if (count == 1) {
        spawnProjectileNode(visualSelector, projectileId, x, y, centerAngle16, initialTravel, speed, radius, arg8OrAux);
        return;
    }
    if (spreadAngle16 == kFixedAngleFullCircle) {
        const int step = kFixedAngleFullCircle / count;
        for (int i = 0; i < count; ++i) {
            spawnProjectileNode(visualSelector, projectileId, x, y, normalizeAngle16(centerAngle16 + i * step), initialTravel, speed, radius, arg8OrAux);
        }
        return;
    }
    const int start = static_cast<int>(centerAngle16) - spreadAngle16 / 2;
    const int step = spreadAngle16 > 0 ? spreadAngle16 / (count - 1) : 0;
    for (int i = 0; i < count; ++i) {
        spawnProjectileNode(visualSelector, projectileId, x, y, normalizeAngle16(start + i * step), initialTravel, speed, radius, arg8OrAux);
    }
}

void StageRuntime::spawnRewardItem(int itemType, float x, float y, std::uint16_t angle16, float speed, int radiusOrScale) {
    if (rewardItems_.size() >= kRewardItemCap) {
        return;
    }
    RewardItem item;
    item.itemType = itemType;
    item.x = x;
    item.y = y;
    item.angle16 = angle16;
    item.speed = speed;
    item.radiusOrScale = radiusOrScale;
    rewardItems_.push_back(item);
}

void StageRuntime::drawBackgroundLayer(int exactLayer) const {
    // Keep the recovered formulas readable while evaluating them at the frame
    // on which the original queued the nodes, before gameplay dispatch.
    const int frame_ = this->backgroundDrawFrame_;
    constexpr double kOriginalPi = 3.14159265358979;
    const auto sineEnvelope = [](int frame, int enterStart, int enterEnd,
                                 int leaveStart, int leaveEnd,
                                 float outsideValue, float insideValue) {
        constexpr double kPiExact = 3.14159265358979;
        float value = insideValue;
        if (enterStart != enterEnd) {
            if (frame < enterStart) {
                value = outsideValue;
            }
            else if (frame < enterEnd) {
                const double phase = static_cast<double>(frame - enterStart) *
                                     kPiExact /
                                     static_cast<double>((enterEnd - enterStart) * 2);
                value = outsideValue + static_cast<float>(
                    std::sin(phase) * static_cast<double>(insideValue - outsideValue));
            }
        }
        if (leaveStart != leaveEnd) {
            if (frame >= leaveStart && frame < leaveEnd) {
                const double phase = static_cast<double>(
                                         frame - (leaveStart * 2 - leaveEnd)) *
                                     kPiExact /
                                     static_cast<double>((leaveEnd - leaveStart) * 2);
                value = outsideValue + static_cast<float>(
                    std::sin(phase) * static_cast<double>(insideValue - outsideValue));
            }
            else if (frame >= leaveEnd) {
                value = outsideValue;
            }
        }
        return value;
    };
    const auto frameHandle = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawDedicatedTall = [this, exactLayer](int drawLayer, int handle,
                                      float logicalX, float y, bool bottomAnchor,
                                      int red = 0xff, int green = 0xff,
                                      int blue = 0xff, int alpha = 0xff,
                                      bool additive = false) {
        if (drawLayer != exactLayer || handle == -1) {
            return;
        }
        int width = 0;
        int height = 0;
        if (GetGraphSize(handle, &width, &height) != 0 || width <= 0 || height <= 0 ||
            alpha <= 0) {
            return;
        }
        SetDrawBright(std::clamp(red, 0, 255), std::clamp(green, 0, 255),
                      std::clamp(blue, 0, 255));
        SetDrawBlendMode(additive ? DX_BLENDMODE_ADD : DX_BLENDMODE_ALPHA,
                         std::clamp(alpha, 0, 255));
        DrawRotaGraph3F(
            static_cast<float>(static_cast<int>(screenX(logicalX))),
            static_cast<float>(static_cast<int>(y)),
            static_cast<float>(width) * 0.5f,
            bottomAnchor ? static_cast<float>(height)
                         : static_cast<float>(height) * 0.5f,
            1.0, 1.0, 0.0, handle, TRUE);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    };
    const bool advanceLateScroll = lateBackgroundScrollFrame_ != frame_;
    const auto drawScrolledTall = [this, advanceLateScroll, exactLayer](
                                      int drawLayer, int slot, int handle, float x,
                                      int red, int green, int blue, int alpha,
                                      float speed, bool additive = false) {
        if (drawLayer != exactLayer || slot < 0 ||
            slot >= static_cast<int>(lateBackgroundScroll_.size())) {
            return;
        }
        if (advanceLateScroll) {
            // FUN_1400c2670 advances each scroll accumulator by
            // DAT_1407c77a4 * speed before wrapping it at 0xa00.
            lateBackgroundScroll_[static_cast<std::size_t>(slot)] +=
                speed * static_cast<float>(std::clamp(timeWindowDispatchCount_, 1, 4));
        }
        if (handle == -1 || alpha <= 0) {
            return;
        }
        int width = 0;
        int height = 0;
        if (GetGraphSize(handle, &width, &height) != 0 || width <= 0 || height <= 0) {
            return;
        }
        constexpr int kOriginalTallHeight = 0xa00;
        const int scroll = static_cast<int>(
                               lateBackgroundScroll_[static_cast<std::size_t>(slot)]) %
                           kOriginalTallHeight;
        SetDrawBright(std::clamp(red, 0, 255), std::clamp(green, 0, 255),
                      std::clamp(blue, 0, 255));
        SetDrawBlendMode(additive ? DX_BLENDMODE_ADD : DX_BLENDMODE_ALPHA,
                         std::clamp(alpha, 0, 255));
        float cameraOffset = 340.0f - player_.x / 6.0f;
        if (drawLayer < 6) {
            // FUN_1400c8530 applies layer-dependent horizontal parallax to
            // modes 14..16. At layer 0 this is 280; layer 5 reaches cameraX.
            cameraOffset = 340.0f - player_.x / 30.0f * drawLayer -
                           static_cast<float>(5 - drawLayer) * 12.0f;
        }
        const float drawX = static_cast<float>(
            static_cast<int>(cameraOffset + x));
        for (const int offset : {0, kOriginalTallHeight, -kOriginalTallHeight}) {
            DrawRotaGraph3F(drawX, static_cast<float>(scroll + offset),
                            static_cast<float>(width) * 0.5f,
                            static_cast<float>(height) * 0.5f,
                            1.005, 1.0, 0.0, handle, TRUE);
        }
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    };

    if (selectedStage_ == 1) {
        const float speed = sineEnvelope(frame_, 600, 0x348, 5400, 5700,
                                         10.0f, 2.5f);
        drawScrolledTall(1, 1, frameHandle(stageBack1Frames_, 4), 360.0f,
                         255, 255, 255, 255, speed * 0.5f);
        drawScrolledTall(3, 2, frameHandle(stageBack1Frames_, 5), 360.0f,
                         255, 255, 255, 255, speed);
        if (frame_ <= 600) {
            int alpha = 0;
            if (frame_ < 300) {
                alpha = 255;
            }
            else if (frame_ < 600) {
                alpha = static_cast<int>(
                    std::sin(static_cast<double>(frame_) * kOriginalPi / 600.0) *
                    255.0);
            }
            drawScrolledTall(4, 0, frameHandle(stageBack1Frames_, 2), 360.0f,
                             255, 255, 255, alpha, speed * 2.0f);
        }
        drawScrolledTall(5, 3, frameHandle(stageBack1Frames_, 3), 360.0f,
                         255, 255, 255, 128, speed * 3.0f);
    }
    else if (selectedStage_ == 2) {
        const float speed = sineEnvelope(frame_, 0, 300, 9700, 10300,
                                         20.0f, 1.0f);
        drawScrolledTall(2, 0, frameHandle(stageBack1Frames_, 6), 360.0f,
                         255, 255, 255, 255, speed * 0.5f);
        drawScrolledTall(4, 1, frameHandle(stageBack1Frames_, 7), 360.0f,
                         255, 255, 255, 255, speed * 0.75f);
        if (frame_ >= 750 && frame_ <= 10000) {
            drawDedicatedTall(0x14, stage2BackHandle_, 360.0f,
                              static_cast<float>(frame_) - 4970.0f,
                              false, 0, 0, 0, 0x30);
            drawDedicatedTall(0x14, stage2BackHandle_, 360.0f,
                              static_cast<float>(frame_) - 5000.0f,
                              false);
        }
    }
    else if (selectedStage_ == 3) {
        drawScrolledTall(2, 0, frameHandle(stageBack1Frames_, 8), 360.0f,
                         255, 255, 255, 255, 6.0f);

        // FUN_1400be7a0 case 3 appends these 21 mode-8 nodes every frame.
        // Effect_l[5] is mirrored along both playfield axes with the original
        // 150/200 pixel spacing and fixed 2x1 scale.
        const int particle = frameHandle(effectLargeFrames_, 5);
        if (exactLayer == 3 && particle != -1) {
            const int animationFrame = std::max(player_.drawAnimationClock, 0);
            const float originX = static_cast<float>(
                static_cast<int>(screenX(0.0f)));
            SetDrawBright(0, 0xff, 0xc0);
            SetDrawBlendMode(DX_BLENDMODE_ADD, 0x30);
            for (int i = 0; i < 7; ++i) {
                const float edge = static_cast<float>(
                    (animationFrame * 2) % 0x96 + i * 0x96);
                const float top = static_cast<float>(
                    (animationFrame * 0x0f) % 200 + i * 200);
                DrawRotaGraph3F(originX + edge, 360.0f, 300.0f, 300.0f,
                                2.0, 1.0, kPi * 0.5, particle, TRUE);
                DrawRotaGraph3F(originX + 720.0f - edge, 360.0f,
                                300.0f, 300.0f, 2.0, 1.0,
                                kPi * 0.5, particle, TRUE);
                DrawRotaGraph3F(originX + 360.0f, top, 300.0f, 300.0f,
                                2.0, 1.0, 0.0, particle, TRUE);
            }
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        drawScrolledTall(4, 1, frameHandle(stageBack1Frames_, 9), 360.0f,
                         255, 255, 255, 255, 12.0f, true);
        if (frame_ >= 0x5dc && frame_ <= 9500) {
            drawDedicatedTall(0x14, stage3BackHandle_, 360.0f,
                              static_cast<float>(frame_ - 0x5dc), true);
        }
    }
    else if (selectedStage_ == 4) {
        const double fade = frame_ >= 0 && frame_ < 11700
                                ? std::cos(static_cast<double>(frame_) *
                                           kOriginalPi / (11700.0 * 2.0))
                                : (frame_ < 0 ? 1.0 : 0.0);
        const int redGreen = 32 + static_cast<int>(fade * 223.0);
        const int blue = 96 + static_cast<int>(fade * 159.0);
        drawScrolledTall(1, 0, frameHandle(stageBack1bFrames_, 0), 360.0f,
                         redGreen, redGreen, blue, 255, -0.7f);
        drawScrolledTall(3, 1, frameHandle(stageBack1bFrames_, 1), 360.0f,
                         redGreen, redGreen, blue, 0x48, -1.5f, true);
    }
    else if (selectedStage_ == 5) {
        constexpr int kEndFrame = 11800;
        if (frame_ > kEndFrame - 600) {
            int alpha = 0;
            if (frame_ >= kEndFrame) {
                alpha = 255;
            }
            else if (frame_ >= kEndFrame - 450) {
                alpha = static_cast<int>(std::sin(
                            static_cast<double>(frame_ - (kEndFrame - 450)) *
                            kOriginalPi / 900.0) *
                        255.0);
            }
            float speed = 0.2f;
            if (frame_ >= kEndFrame + 600) {
                speed = 3.0f;
            }
            else if (frame_ >= kEndFrame) {
                speed = 0.2f + static_cast<float>(
                                   std::sin(static_cast<double>(frame_ - kEndFrame) *
                                            kOriginalPi / 1200.0) *
                                   2.8);
            }
            drawScrolledTall(1, 0, frameHandle(stageBack1bFrames_, 2), 360.0f,
                             alpha, alpha, alpha, 255, speed);
            drawScrolledTall(2, 1, frameHandle(stageBack1bFrames_, 3), 360.0f,
                             alpha, alpha, alpha, 255, speed * 2.2f);
            drawScrolledTall(3, 2, frameHandle(stageBack1bFrames_, 4), 360.0f,
                             alpha, alpha, alpha, 255, speed * 3.4f);
            drawScrolledTall(4, 3, frameHandle(stageBack1bFrames_, 5), 360.0f,
                             alpha, alpha, alpha, 255, speed * 4.6f);
        }
    }
    else if (selectedStage_ == 6) {
        constexpr int kEndFrame = 12500;
        float speed = frame_ < 0 ? 20.0f : 1.0f;
        if (frame_ >= 0 && frame_ < 300) {
            speed = 20.0f - static_cast<float>(
                                std::sin(static_cast<double>(frame_) *
                                         kOriginalPi / 600.0) *
                                19.0);
        }
        else if (frame_ >= kEndFrame + 300 && frame_ < kEndFrame + 900) {
            speed = 10.0f - static_cast<float>(
                                std::sin(static_cast<double>(
                                             frame_ - (kEndFrame - 300)) *
                                         kOriginalPi / 1200.0) *
                                9.0);
        }
        else if (frame_ >= kEndFrame + 900) {
            speed = 10.0f;
        }
        drawScrolledTall(1, 0, frameHandle(stageBack1bFrames_, 6), 360.0f,
                         255, 255, 255, 255, speed * 0.5f);
        drawScrolledTall(2, 1, frameHandle(stageBack1bFrames_, 7), 360.0f,
                         128, 128, 255, 0x32, speed * 0.7f, true);
        drawScrolledTall(3, 2, frameHandle(stageBack1bFrames_, 8), 360.0f,
                         192, 192, 255, 0x4b, speed, true);
        drawScrolledTall(4, 3, frameHandle(stageBack1bFrames_, 9), 360.0f,
                         255, 255, 255, 100, speed * 1.4f, true);
        if (exactLayer == 10 && frame_ >= 6500 && frame_ <= kEndFrame + 120) {
            float y = 150.0f;
            const int riseEnd = kEndFrame + 60;
            if (frame_ < riseEnd) {
                y = -120.0f + static_cast<float>(
                    std::sin(static_cast<double>(frame_ - 6500) *
                             kOriginalPi /
                             (2.0 * static_cast<double>(riseEnd - 6500))) *
                    270.0);
            }
            const int handle = frameHandle(enemyMediumFrames_, 109);
            if (handle != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xc0);
                drawOriginalMode7Node(
                    handle,
                    static_cast<float>(static_cast<int>(screenX(480.0f))),
                    static_cast<float>(static_cast<int>(y)),
                    0, 1.0, 1.0, false);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        if (frame_ > 0x419 && frame_ <= kEndFrame + 300) {
            drawDedicatedTall(0x14, stage6BackHandle_, 360.0f,
                              static_cast<float>(frame_ - 0x44c), true);
        }
    }
    else if (selectedStage_ == 7) {
        constexpr std::array<std::array<int, 3>, 7> kPalette{{
            {{255, 120, 120}}, {{255, 200, 110}}, {{255, 255, 120}},
            {{120, 255, 120}}, {{120, 255, 255}}, {{120, 120, 255}},
            {{220, 120, 255}},
        }};
        const int animationFrame = std::max(player_.drawAnimationClock, 0);
        const int paletteIndex = (animationFrame / 300) % static_cast<int>(kPalette.size());
        const int paletteNext = (paletteIndex + 1) % static_cast<int>(kPalette.size());
        const int paletteLocal = animationFrame % 300;
        std::array<int, 3> color{};
        for (std::size_t channel = 0; channel < color.size(); ++channel) {
            const int current = kPalette[static_cast<std::size_t>(paletteIndex)][channel];
            const int next = kPalette[static_cast<std::size_t>(paletteNext)][channel];
            color[channel] = static_cast<int>(
                static_cast<double>(current) -
                (static_cast<double>(current - next) / 300.0) * paletteLocal);
        }
        drawScrolledTall(1, 0, frameHandle(stageBack1cFrames_, 0), 360.0f,
                         color[0], color[1], color[2], 255, 8.0f);
        drawScrolledTall(2, 1, frameHandle(stageBack1cFrames_, 1), 360.0f,
                         color[0] / 3, color[1] / 3, color[2] / 3, 255, 4.8f);
        drawScrolledTall(4, 2, frameHandle(stageBack1Frames_, 3), 360.0f,
                         128, 128, 128, 192, 12.8f, true);
        if (frame_ < 12500 - 480) {
            const int fade = frame_ < 0
                                 ? 0
                                 : (frame_ < 300
                                        ? static_cast<int>(255.0 * std::sin(
                                              static_cast<double>(frame_) * kPi / 600.0))
                                        : 255);
            const float x = 360.0f + 80.0f * static_cast<float>(
                std::sin(static_cast<double>(frame_) * kTau / 3300.0));
            drawScrolledTall(0x14, 2, frameHandle(stageBack1cFrames_, 2), x,
                             fade, fade, fade, 255, 16.0f);
        }
        if (frame_ >= 12500 - 600 && frame_ < 12500 - 300) {
            const int local = frame_ - (12500 - 600);
            const double envelope = local < 120
                                        ? std::sin(static_cast<double>(local) * kPi / 240.0)
                                        : std::sin(static_cast<double>(300 - local) * kPi / 360.0);
            drawScrolledTall(0x18, 3, frameHandle(stageBack1Frames_, 2), 360.0f,
                             128, 128, 128,
                             static_cast<int>(255.0 * std::max(0.0, envelope)), 32.0f);
        }
    }
    else if (selectedStage_ == 8) {
        constexpr int kEndFrame = 21420;
        if (frame_ < 0x1af4) {
            int layerAlpha = 255;
            if (frame_ >= 240 && frame_ < 360) {
                layerAlpha = static_cast<int>(
                    std::sin(static_cast<double>(frame_ - 120) *
                             kOriginalPi / 240.0) *
                    255.0);
            }
            if (frame_ >= 360) {
                layerAlpha = 0;
            }
            float speed = 10.0f;
            if (frame_ >= 240 && frame_ < 360) {
                speed = 10.0f - static_cast<float>(
                                    std::sin(static_cast<double>(frame_ - 240) *
                                             kOriginalPi / 240.0) *
                                    9.0);
            }
            else if (frame_ >= 360) {
                speed = 1.0f;
            }
            if (frame_ < 6001) {
                drawScrolledTall(1, 1, frameHandle(stageBack1Frames_, 4), 360.0f,
                                 255, 255, 255, 255, speed * 0.5f);
                drawScrolledTall(3, 2, frameHandle(stageBack1Frames_, 3), 360.0f,
                                 255, 255, 128, 128, speed * 7.0f);
            }
            if (frame_ < 401) {
                drawScrolledTall(4, 0, frameHandle(stageBack1Frames_, 2), 360.0f,
                                 128, 128, 128, layerAlpha, 32.0f);
            }
            if (frame_ >= 400) {
                drawDedicatedTall(0x14, stage8Back1Handle_, 360.0f,
                                  static_cast<float>(frame_ - 400), true);
            }

            // case 8 queues StageBack2[4] as an additive, centered layer from
            // frame 6000 through its 150-frame exit ending at frame 6900.
            if (frame_ >= 6000) {
                const int transition = frameHandle(stageBack2Frames_, 4);
                int alpha = 0xff;
                if (frame_ >= 0x1a5e) {
                    alpha = static_cast<int>(
                        std::sin(static_cast<double>(frame_ - 6600) *
                                 kOriginalPi / 300.0) *
                        255.0);
                }
                if (exactLayer == 1 && transition != -1 && alpha > 0) {
                    int width = 0;
                    int height = 0;
                    if (GetGraphSize(transition, &width, &height) == 0 &&
                        width > 0 && height > 0) {
                        SetDrawBlendMode(DX_BLENDMODE_ADD,
                                         std::clamp(alpha, 0, 255));
                        DrawRotaGraph3F(
                            static_cast<float>(
                                static_cast<int>(screenX(360.0f))),
                            360.0f,
                            static_cast<float>(width) * 0.5f,
                            static_cast<float>(height) * 0.5f,
                            1.005, 1.005, 0.0, transition, TRUE);
                        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                    }
                }
            }
        }
        if (frame_ >= 0x29cc) {
            if (exactLayer == 0 && frame_ == 0x29cc && advanceLateScroll) {
                lateBackgroundScroll_.fill(0.0f);
            }
            int alpha = 0;
            if (frame_ > 0x29cc && frame_ < 0x2c24) {
                alpha = static_cast<int>(
                    std::sin(static_cast<double>(frame_ - 0x29cc) *
                             kOriginalPi / 1200.0) *
                    255.0);
            }
            else if (frame_ >= 0x2c24) {
                alpha = 255;
            }
            if (frame_ >= kEndFrame - 600) {
                alpha = frame_ < kEndFrame - 480
                            ? static_cast<int>(
                                  std::sin(static_cast<double>(
                                               frame_ - (kEndFrame - 720)) *
                                           kOriginalPi / 240.0) *
                                           255.0)
                            : 0;
            }
            if (frame_ >= kEndFrame - 300) {
                alpha = frame_ < kEndFrame
                            ? static_cast<int>(
                                  std::sin(static_cast<double>(
                                               frame_ - (kEndFrame - 300)) *
                                           kOriginalPi / 600.0) *
                                  255.0)
                            : 255;
            }
            float speed = 0.0f;
            if (frame_ > 0x29cc && frame_ < 0x300c) {
                speed = static_cast<float>(
                    std::sin(static_cast<double>(frame_ - 0x29cc) *
                             kOriginalPi / 3200.0));
            }
            else if (frame_ >= 0x300c) {
                speed = 1.0f;
            }
            if (frame_ >= 0x4394) {
                speed = sineEnvelope(frame_, 0x4394, 0x45ec,
                                     kEndFrame - 480, kEndFrame - 300,
                                     1.0f, 12.0f);
            }
            if (frame_ >= kEndFrame) {
                if (backgroundStageGateOpen_ &&
                    backgroundStage08BossState_ > 10) {
                    speed = 10.0f;
                    if (backgroundStage08BossState_ == 11 &&
                        backgroundStage08BossTimer_ >= 0 &&
                        backgroundStage08BossTimer_ < 300) {
                        speed = 1.0f + static_cast<float>(
                                           std::sin(static_cast<double>(
                                                        backgroundStage08BossTimer_) *
                                                    kOriginalPi / 600.0) *
                                           9.0);
                    }
                }
            }
            drawScrolledTall(1, 0, frameHandle(stageBack1cFrames_, 3), 360.0f,
                             255, 255, 255, alpha, speed * 0.3f);
            if (frame_ < kEndFrame - 480) {
                drawScrolledTall(2, 1, frameHandle(stageBack1cFrames_, 4), 360.0f,
                                 255, 255, 255,
                                 static_cast<int>(alpha * 0.6), speed * 0.5f);
                constexpr std::array<int, 4> kVariantFrames{{5, 6, 10, 11}};
                const int variant = kVariantFrames[static_cast<std::size_t>(
                    std::clamp(config_.language, 0, 3))];
                drawScrolledTall(3, 2, frameHandle(stageBack1cFrames_, variant), 360.0f,
                                 255, 255, 255,
                                 static_cast<int>(alpha * 0.8), speed * 0.7f);
                drawScrolledTall(4, 3, frameHandle(stageBack1Frames_, 1), 360.0f,
                                 64, 255, 192,
                                 static_cast<int>(alpha * 0.3), speed * 1.5f);
            }
            if (frame_ >= kEndFrame - 300) {
                const double amount = frame_ < kEndFrame
                                          ? std::sin(static_cast<double>(
                                                         frame_ - (kEndFrame - 300)) *
                                                     kOriginalPi / 600.0)
                                          : 1.0;
                drawScrolledTall(2, 3, frameHandle(stageBack1cFrames_, 7), 360.0f,
                                 0, static_cast<int>(amount * 255.0 * 0.3),
                                 static_cast<int>(amount * 192.0 * 0.3), 255,
                                 speed * 0.5f);
                drawScrolledTall(3, 2, frameHandle(stageBack1cFrames_, 8), 360.0f,
                                 0, static_cast<int>(amount * 255.0 * 0.55),
                                 static_cast<int>(amount * 192.0 * 0.55), 255,
                                 speed * 0.8f);
                drawScrolledTall(4, 1, frameHandle(stageBack1cFrames_, 9), 360.0f,
                                 0, static_cast<int>(amount * 255.0 * 0.8),
                                 static_cast<int>(amount * 192.0 * 0.8), 255,
                                 speed * 1.2f);
            }
            if (frame_ >= 0x2a30 && frame_ <= kEndFrame) {
                drawDedicatedTall(0x14, stage8Back2Handle_, 360.0f,
                                  static_cast<float>(frame_ - 0x2a30), true);
            }

            // The original appends four mode-7 Effect_l[5] nodes for each of
            // seven offsets. Unlike the Stage 3/9 family these are normal
            // alpha-blended and include both top and bottom mirrors.
            const int particle = frameHandle(effectLargeFrames_, 5);
            const int particleAlpha = alpha / 10;
            if (exactLayer == 6 && particle != -1 && particleAlpha > 0) {
                const int animationFrame =
                    std::max(player_.drawAnimationClock, 0);
                const float originX = static_cast<float>(
                    static_cast<int>(screenX(0.0f)));
                SetDrawBright(0x40, 0xff, 0xff);
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, particleAlpha);
                for (int i = 0; i < 7; ++i) {
                    const float edge = static_cast<float>(
                        animationFrame % 0x78 + i * 0x78);
                    const float vertical = static_cast<float>(
                        animationFrame % 0xa0 + i * 0xa0);
                    DrawRotaGraph3F(originX + edge, 360.0f,
                                    300.0f, 300.0f, 2.0, 1.0,
                                    kPi * 0.5, particle, TRUE);
                    DrawRotaGraph3F(originX + 720.0f - edge, 360.0f,
                                    300.0f, 300.0f, 2.0, 1.0,
                                    kPi * 0.5, particle, TRUE);
                    DrawRotaGraph3F(originX + 360.0f, vertical,
                                    300.0f, 300.0f, 2.0, 1.0,
                                    0.0, particle, TRUE);
                    DrawRotaGraph3F(originX + 360.0f, 720.0f - vertical,
                                    300.0f, 300.0f, 2.0, 1.0,
                                    0.0, particle, TRUE);
                }
                SetDrawBright(255, 255, 255);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
    }
    else if (selectedStage_ == 9) {
        constexpr int kEndFrame = 17900;
        constexpr std::array<int, 3> kBase{{192, 64, 64}};
        constexpr std::array<int, 6> kColorStart{{1350, 4100, 6200, 9000, 11860, 13900}};
        constexpr std::array<std::array<int, 3>, 6> kTargets{{
            {{64, 192, 192}}, {{192, 128, 64}}, {{64, 192, 64}},
            {{64, 64, 192}}, {{64, 64, 64}}, {{128, 64, 192}},
        }};
        std::array<int, 3> color = kBase;
        int colorIndex = -1;
        for (std::size_t i = 0; i < kColorStart.size(); ++i) {
            if (frame_ >= kColorStart[i]) colorIndex = static_cast<int>(i);
        }
        if (colorIndex >= 0 && frame_ < 16099) {
            const auto& target = kTargets[static_cast<std::size_t>(colorIndex)];
            const int defeatFrame =
                backgroundStage09BossDefeatFrames_[static_cast<std::size_t>(colorIndex)];
            const bool returning = defeatFrame >= 0 && frame_ >= defeatFrame;
            const int local = returning ? frame_ - defeatFrame
                                        : frame_ - kColorStart[static_cast<std::size_t>(colorIndex)];
            const int amount = std::clamp(local, 0, 180);
            for (std::size_t channel = 0; channel < color.size(); ++channel) {
                const int from = returning ? target[channel] : kBase[channel];
                const int to = returning ? kBase[channel] : target[channel];
                color[channel] = (from * (180 - amount) + to * amount) / 180;
            }
        }

        if (frame_ < kEndFrame - 480) {
            int alpha = 0;
            if (frame_ >= 300 && frame_ < 1500) {
                alpha = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(frame_ - 300) * kPi / 2400.0));
            }
            else if (frame_ >= 1500 && frame_ < kEndFrame - 600) {
                alpha = 255;
            }
            else if (frame_ >= kEndFrame - 600) {
                alpha = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(frame_ - (kEndFrame - 720)) * kPi / 240.0));
            }
            drawScrolledTall(1, 0, frameHandle(stageBack1dFrames_, 0), 360.0f,
                             color[0], color[1], color[2], alpha, 3.0);
            drawScrolledTall(2, 1, frameHandle(stageBack1dFrames_, 1), 360.0f,
                             color[0], color[1], color[2], alpha, 7.0);
            drawScrolledTall(4, 2, frameHandle(stageBack1dFrames_, 2), 360.0f,
                             color[0], color[1], color[2], alpha, 10.0);
        }
        else {
            double amount = 0.0;
            if (frame_ >= kEndFrame) {
                amount = 1.0;
            }
            else if (frame_ >= kEndFrame - 300) {
                amount = std::sin(
                    static_cast<double>(frame_ - (kEndFrame - 300)) *
                    kOriginalPi / 600.0);
            }

            double speed = 10.0 - 10.0 * std::sin(
                static_cast<double>(frame_ - (kEndFrame - 480)) *
                kOriginalPi / 960.0);
            if (frame_ >= kEndFrame) {
                speed = 0.0;
            }
            if (frame_ >= kEndFrame && backgroundStageGateOpen_ &&
                backgroundStage09BossState_ >= 11) {
                speed = 16.0;
                if ((backgroundStage09BossState_ == 11 ||
                     backgroundStage09BossState_ == 111) &&
                    backgroundStage09BossTimer_ < 300) {
                    speed = 16.0 * std::sin(
                                       static_cast<double>(std::max(
                                           0, backgroundStage09BossTimer_)) *
                                       kOriginalPi / 600.0);
                }
            }

            drawScrolledTall(1, 0, frameHandle(stageBack1dFrames_, 0), 360.0f,
                             kBase[0], kBase[1], kBase[2],
                             static_cast<int>(amount * 255.0),
                             static_cast<float>(0.3 * speed));
            drawScrolledTall(2, 1, frameHandle(stageBack1cFrames_, 7), 360.0f,
                             static_cast<int>(kBase[0] * amount * 0.3),
                             static_cast<int>(kBase[1] * amount * 0.3),
                             static_cast<int>(kBase[2] * amount * 0.3), 255,
                             static_cast<float>(0.5 * speed));
            drawScrolledTall(3, 2, frameHandle(stageBack1cFrames_, 8), 360.0f,
                             static_cast<int>(kBase[0] * amount * 0.55),
                             static_cast<int>(kBase[1] * amount * 0.55),
                             static_cast<int>(kBase[2] * amount * 0.55), 255,
                             static_cast<float>(0.8 * speed));
            drawScrolledTall(4, 3, frameHandle(stageBack1cFrames_, 9), 360.0f,
                             static_cast<int>(kBase[0] * amount * 0.8),
                             static_cast<int>(kBase[1] * amount * 0.8),
                             static_cast<int>(kBase[2] * amount * 0.8), 255,
                             static_cast<float>(1.2 * speed));
        }

        const int particle = frameHandle(effectLargeFrames_, 5);
        if (exactLayer == 5 && particle != -1) {
            SetDrawBright(color[0], color[1], color[2]);
            SetDrawBlendMode(DX_BLENDMODE_ADD, 48);
            const int animationFrame =
                std::max(player_.drawAnimationClock, 0);
            for (int i = 0; i < 7; ++i) {
                const float edge = static_cast<float>(
                    (animationFrame * 2) % 150 + i * 150);
                const float top = static_cast<float>(
                    (animationFrame * 15) % 200 + i * 200);
                const float originX = static_cast<float>(
                    static_cast<int>(screenX(0.0f)));
                DrawRotaGraph3F(originX + edge, 360.0f, 300.0f, 300.0f,
                                2.0, 1.0, kPi * 0.5, particle, TRUE);
                DrawRotaGraph3F(originX + 720.0f - edge, 360.0f, 300.0f, 300.0f,
                                2.0, 1.0, kPi * 0.5, particle, TRUE);
                DrawRotaGraph3F(originX + 360.0f, top, 300.0f, 300.0f,
                                2.0, 1.0, 0.0, particle, TRUE);
            }
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
    else if (selectedStage_ == 10) {
        const double speed = frame_ < 0
                                 ? 10.0
                                 : (frame_ < 480
                                        ? 10.0 - 8.0 * std::sin(
                                              static_cast<double>(frame_) * kPi / 960.0)
                                        : 2.0);
        drawScrolledTall(1, 0, frameHandle(stageBack1dFrames_, 3), 360.0f,
                         255, 255, 255, 255, static_cast<float>(speed * 0.4));
        drawScrolledTall(1, 1, frameHandle(stageBack1dFrames_, 4), 360.0f,
                         255, 255, 255, 255, static_cast<float>(speed));
        drawScrolledTall(3, 2, frameHandle(stageBack1dFrames_, 5), 360.0f,
                         255, 255, 255, 255, 16.0f);
    }

    if (exactLayer == 0x18) {
        lateBackgroundScrollFrame_ = frame_;
    }

}

void StageRuntime::drawPlayerSideObjects(PlayerSideDrawPass pass) const {
    const auto frameHandle = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawEffect = [&](const std::vector<int>& frames, int index, float x, float y,
                                double scale, std::uint16_t angle16, int alpha,
                                bool additive = false) {
        const int handle = frameHandle(frames, index);
        if (handle == -1 || alpha <= 0 || scale <= 0.0) {
            return;
        }
        SetDrawBlendMode(additive ? DX_BLENDMODE_ADD : DX_BLENDMODE_ALPHA,
                         std::clamp(alpha, 0, 255));
        DrawRotaGraphF(static_cast<float>(static_cast<int>(x)),
                       static_cast<float>(static_cast<int>(y)),
                       scale, fixedAngleToRadians(angle16), handle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    };
    const auto drawWhiteFlash = [this](int alpha) {
        if (whiteBackHandle_ == -1 || alpha <= 0) {
            return;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
        DrawGraph(0, 0, whiteBackHandle_, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    };
    const auto drawPlayerSprite = [](int handle, float x, float y,
                                     double scaleX, double scaleY,
                                     std::uint16_t angle16,
                                     int red, int green, int blue, int alpha) {
        if (handle == -1 || scaleX <= 0.0 || scaleY <= 0.0 || alpha <= 0) {
            return;
        }
        int width = 0;
        int height = 0;
        if (GetGraphSize(handle, &width, &height) != 0 || width <= 0 || height <= 0) {
            return;
        }
        SetDrawBright(std::clamp(red, 0, 255), std::clamp(green, 0, 255),
                      std::clamp(blue, 0, 255));
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
        DrawRotaGraph3F(static_cast<float>(static_cast<int>(x)),
                        static_cast<float>(static_cast<int>(y)),
                        static_cast<float>(width) * 0.5f,
                        static_cast<float>(height) * 0.5f,
                        scaleX, scaleY, fixedAngleToRadians(angle16), handle, TRUE);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    };

    if (pass == PlayerSideDrawPass::Normal &&
        pauseFlowState_ != PauseFlowState::GameOverDelay &&
        pauseFlowState_ != PauseFlowState::GameOverPresentation) {
        constexpr std::array<int, 4> kGroup1OptionFrames{{0x5f, 0x60, 0x61, 0x60}};
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int phase = (std::max(0, player_.drawAnimationClock) / 6) %
                          (group == 1 ? 4 : 5);
        const int frameIndex = group == 0
                                   ? 0x5a + phase
                                   : (group == 1
                                          ? kGroup1OptionFrames[static_cast<std::size_t>(phase)]
                                          : 0x62 + phase);
        const int handle = frameHandle(playerFrames_, frameIndex);
        for (std::size_t slot = 0; slot < player_.optionX.size(); ++slot) {
            drawPlayerSprite(handle, screenX(player_.optionX[slot]),
                             screenY(player_.optionY[slot]),
                             player_.optionDrawScale, player_.optionDrawScale,
                             player_.optionAngle16[slot],
                             255, 255, 255, 255);
        }
    }

    for (const auto& object : playerSideObjects_) {
        const bool normalType = object.type >= 0 && object.type <= 0x0a;
        const bool flashType = object.type == 0x0b || object.type == 0x0e ||
                               object.type == 0x0f || object.type == 0x11 ||
                               object.type == 0x12 || object.type == 0x15;
        const bool coreType = object.type == 0x0c || object.type == 0x0d ||
                              object.type == 0x0e || object.type == 0x10 ||
                              object.type == 0x14 || object.type == 0x15 ||
                              object.type == 0x16;
        const bool ringType = object.type >= 0x17 && object.type <= 0x1a;
        const bool selected =
            (pass == PlayerSideDrawPass::Normal && normalType) ||
            (pass == PlayerSideDrawPass::Flash && flashType) ||
            (pass == PlayerSideDrawPass::Core && coreType) ||
            (pass == PlayerSideDrawPass::Ring && ringType);
        if (!selected) {
            continue;
        }
        const float x = screenX(object.x);
        const float y = screenY(object.y);
        const int drawAge = std::max(0, object.age - 1);
        if (object.type >= 0 && object.type <= 0x0a) {
            const int frameIndex = playerSideObjectVisualFrame(object);
            const int handle = frameHandle(playerFrames_, frameIndex);
            if (handle != -1) {
                int red = 255;
                int green = 255;
                int blue = 255;
                int alpha = 0x80;
                double scale = 1.0;
                if (object.type == 0) {
                    green = drawAge < 0x11 ? 0x80 + drawAge * 8 : 0xff;
                    blue = green;
                }
                else if (object.type == 1) {
                    green = drawAge < 0x11 ? 0x80 + drawAge * 8 : 0xff;
                    blue = 0x80;
                    alpha = 0xc0;
                    scale = 2.0;
                }
                else if (object.type == 3 || object.type == 6 || object.type == 9) {
                    green = 0x80;
                    blue = 0x80;
                    scale = 1.5;
                }
                else if (object.type == 4 || object.type == 7 || object.type == 10) {
                    alpha = 0xc0;
                    scale = 2.0;
                    if (player_.specialGauge < 0) {
                        green = 0xff;
                        blue = 0x80;
                    }
                    else {
                        red = 0xc0;
                        green = 0x40;
                        blue = 0x40;
                    }
                }
                const bool stretched = object.type >= 2 && object.type <= 4;
                drawPlayerSprite(handle, x, y,
                                 stretched ? scale * 1.5 : scale, scale,
                                 object.drawAngle16,
                                 red, green, blue, alpha);
            }
            continue;
        }
        if (pass == PlayerSideDrawPass::Flash) {
            const int lifetime = object.type == 0x11
                                     ? 600
                                     : (object.type == 0x15 ? 240 : 180);
            drawWhiteFlash(rootFlashAlpha(drawAge, lifetime));
            continue;
        }

        switch (object.type) {
        case 0x0b:
            drawWhiteFlash(rootFlashAlpha(drawAge, 180));
            break;
        case 0x0c: {
            const double scale = drawAge < 8 ? sineEaseIn(drawAge, 8, 1.0f) : 1.0;
            drawEffect(effectMediumFrames_, 6, x, y, scale,
                       normalizeAngle16(player_.drawAnimationClock * 999), 255);
            break;
        }
        case 0x0d:
            drawEffect(effectLargeFrames_, 1, x, y,
                       object.collisionRadiusOrScale / 180.0,
                       normalizeAngle16(player_.drawAnimationClock * 2000), 192);
            break;
        case 0x0e:
            if (drawAge < 30) {
                const double scale = drawAge < 20
                                         ? sineEaseIn(drawAge, 20, 1.0f)
                                         : sineEaseOut(drawAge - 20, 10, 1.0f);
                drawEffect(effectMediumFrames_, 6, x, y, scale,
                           normalizeAngle16(player_.drawAnimationClock * 999), 255);
            }
            break;
        case 0x0f:
            drawWhiteFlash(rootFlashAlpha(drawAge, 180));
            break;
        case 0x10:
            drawEffect(effectMediumFrames_, 7, x, y, 1.0, object.drawAngle16, 255);
            break;
        case 0x11:
            drawWhiteFlash(rootFlashAlpha(drawAge, 600));
            break;
        case 0x12:
            drawWhiteFlash(rootFlashAlpha(drawAge, 180));
            break;
        case 0x13:
            break;
        case 0x14: {
            const int alpha = drawAge < 24
                                  ? 192
                                  : static_cast<int>(sineEaseOut(drawAge - 24, 6, 192.0f));
            drawEffect(effectMediumFrames_, 12, x, y,
                       object.collisionRadiusOrScale / 75.0,
                       object.angle16, alpha, true);
            break;
        }
        case 0x15: {
            const int fieldAlpha = drawAge < 32
                                       ? static_cast<int>(sineEaseIn(drawAge, 32, 48.0f))
                                       : (drawAge >= 224
                                              ? static_cast<int>(sineEaseOut(drawAge - 224, 16, 48.0f))
                                              : 48);
            SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(fieldAlpha, 0, 255));
            const int edgeHandle = frameHandle(effectLargeFrames_, 5);
            if (edgeHandle != -1) {
                for (int i = 0; i < 7; ++i) {
                    const float horizontal = static_cast<float>((drawAge * 3) % 120 + i * 120);
                    const float vertical = static_cast<float>((drawAge * 3) % 160 + i * 160);
                    DrawRotaGraph3F(
                                    static_cast<float>(static_cast<int>(screenX(horizontal))),
                                    static_cast<float>(static_cast<int>(screenY(360.0f))),
                                    300.0f, 300.0f, 2.0, 1.0,
                                    kPi * 0.5f, edgeHandle, TRUE);
                    DrawRotaGraph3F(
                                    static_cast<float>(static_cast<int>(screenX(720.0f - horizontal))),
                                    static_cast<float>(static_cast<int>(screenY(360.0f))),
                                    300.0f, 300.0f, 2.0, 1.0,
                                    kPi * 0.5f, edgeHandle, TRUE);
                    DrawRotaGraph3F(
                                    static_cast<float>(static_cast<int>(screenX(360.0f))),
                                    static_cast<float>(static_cast<int>(screenY(vertical))),
                                    300.0f, 300.0f, 2.0, 1.0,
                                    0.0, edgeHandle, TRUE);
                    DrawRotaGraph3F(
                                    static_cast<float>(static_cast<int>(screenX(360.0f))),
                                    static_cast<float>(static_cast<int>(screenY(720.0f - vertical))),
                                    300.0f, 300.0f, 2.0, 1.0,
                                    0.0, edgeHandle, TRUE);
                }
            }
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            drawEffect(effectLargeFrames_, 4, x, y,
                       object.collisionRadiusOrScale / 250.0,
                       normalizeAngle16(drawAge * 0x29a), 160);
            drawEffect(effectLargeFrames_, 4, x, y,
                       object.collisionRadiusOrScale / 250.0,
                       normalizeAngle16(-drawAge * 0x29a), 160);
            for (int i = 0; i < 6; ++i) {
                const float angle = deterministicUnit(drawAge * 0x6f + i, frame_) * kTau;
                const float radius = deterministicUnit(drawAge * 0x457 + i, frame_ + i) *
                                     object.collisionRadiusOrScale;
                drawEffect(effectSmallFrames_, 2,
                           x + std::cos(angle) * radius,
                           y + std::sin(angle) * radius,
                           object.collisionRadiusOrScale / 250.0,
                           normalizeAngle16(drawAge * 0x29a), 255, true);
            }
            break;
        }
        case 0x16: {
            const int alpha = drawAge < 80
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 80, 16, 255.0f));
            drawEffect(effectLargeFrames_, 6, x, y,
                       object.collisionRadiusOrScale / 200.0,
                       normalizeAngle16(drawAge * 0x400), alpha, true);
            drawEffect(effectLargeFrames_, 6, x, y,
                       object.collisionRadiusOrScale / 200.0,
                       normalizeAngle16(-drawAge * 0x400), alpha, true);
            break;
        }
        case 0x17:
        case 0x18: {
            const int alpha = drawAge < 32
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 32, 16, 255.0f));
            drawEffect(effectLargeFrames_, 0, x, y,
                       object.collisionRadiusOrScale / 250.0, 0, alpha, true);
            break;
        }
        case 0x19: {
            const int alpha = drawAge < 16
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 16, 8, 255.0f));
            drawEffect(effectLargeFrames_, 0, x, y,
                       object.collisionRadiusOrScale / 250.0, 0, alpha, true);
            break;
        }
        case 0x1a: {
            const int alpha = drawAge < 16
                                  ? 96
                                  : static_cast<int>(sineEaseOut(drawAge - 16, 8, 96.0f));
            drawEffect(effectMediumFrames_, 5, x, y,
                       object.collisionRadiusOrScale / 75.0, 0, alpha, true);
            break;
        }
        default:
            break;
        }
    }
}

void StageRuntime::drawPlayerBody() const {
    if (pauseFlowState_ == PauseFlowState::GameOverDelay ||
        pauseFlowState_ == PauseFlowState::GameOverPresentation ||
        (player_.playerStateTimer >= 180 && player_.playerStateTimer < 260)) {
        return;
    }
    const int frameIndex = player_.visualFrame;
    if (frameIndex < 0 || frameIndex >= static_cast<int>(playerFrames_.size())) {
        return;
    }
    const int frame = playerFrames_[static_cast<std::size_t>(frameIndex)];
    if (frame == -1) {
        return;
    }
    // FUN_1400c8530 truncates mode-7/8 coordinates after applying the stage
    // camera translation. Keep that final integer point for every player node.
    const float x = static_cast<float>(static_cast<int>(screenX(player_.x)));
    const float y = static_cast<float>(static_cast<int>(screenY(player_.y)));
    DrawRotaGraphF(x, y, 1.0, 0.0, frame, TRUE);

    if (player_.specialGauge < 0 || player_.specialGauge >= 50000) {
        constexpr std::array<std::array<int, 3>, 7> kFeverColors{{
            {{255, 120, 120}}, {{255, 200, 110}}, {{255, 255, 120}},
            {{120, 255, 120}}, {{120, 255, 255}}, {{120, 120, 255}},
            {{220, 120, 255}},
        }};
        const int colorClock = std::max(player_.drawAnimationClock, 0);
        const int colorIndex =
            (colorClock / 20) % static_cast<int>(kFeverColors.size());
        const int nextColorIndex =
            (colorIndex + 1) % static_cast<int>(kFeverColors.size());
        const int colorStep = colorClock % 20;
        const auto channel = [&](std::size_t index) {
            const int current =
                kFeverColors[static_cast<std::size_t>(colorIndex)][index];
            const int next =
                kFeverColors[static_cast<std::size_t>(nextColorIndex)][index];
            return static_cast<int>(
                static_cast<double>(current) -
                (static_cast<double>(current - next) / 20.0) *
                    static_cast<double>(colorStep));
        };
        const int alpha = 0x60 - static_cast<int>(
            std::sin(static_cast<double>(colorClock) *
                     static_cast<double>(kPi) / 15.0) * -96.0);
        SetDrawBright(channel(0), channel(1), channel(2));
        SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(alpha, 0, 255));
        DrawRotaGraphF(x, y, 1.0, 0.0, frame, TRUE);
        SetDrawBright(0xff, 0xff, 0xff);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (player_.drawInvulnerabilityOverlay) {
        const int overlayIndex = frameIndex + 15;
        if (overlayIndex >= 0 &&
            overlayIndex < static_cast<int>(playerFrames_.size())) {
            const int overlay =
                playerFrames_[static_cast<std::size_t>(overlayIndex)];
            if (overlay != -1) {
                DrawRotaGraphF(x, y, 1.0, 0.0, overlay, TRUE);
            }
        }
    }

    if (player_.playerStateTimer > 259 && effectMediumFrames_.size() > 4) {
        const int hitEntryOverlay = effectMediumFrames_[4];
        if (hitEntryOverlay != -1) {
            const double scale =
                static_cast<double>(player_.playerStateTimer - 260) * 0.05;
            SetDrawBright(0xff, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xff);
            DrawRotaGraphF(x, y, scale, 0.0, hitEntryOverlay, TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            SetDrawBright(0xff, 0xff, 0xff);
        }
    }
}

void StageRuntime::drawPlayer(PlayerOverlayDrawPass pass) const {
    if (pauseFlowState_ == PauseFlowState::GameOverPresentation) {
        return;
    }
    if (pauseFlowState_ == PauseFlowState::GameOverDelay ||
        (player_.playerStateTimer >= 180 && player_.playerStateTimer < 260)) {
        if (pass == PlayerOverlayDrawPass::MarkerRing) {
            drawPlayerSideObjects(PlayerSideDrawPass::Ring);
        }
        return;
    }
    const float x = static_cast<float>(static_cast<int>(screenX(player_.x)));
    const float y = static_cast<float>(static_cast<int>(screenY(player_.y)));
    const auto frameHandle = [this](int index) {
        return index >= 0 && index < static_cast<int>(playerFrames_.size())
                   ? playerFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    constexpr std::array<std::array<int, 3>, 7> kFeverColors{{
        {{255, 120, 120}}, {{255, 200, 110}}, {{255, 255, 120}},
        {{120, 255, 120}}, {{120, 255, 255}}, {{120, 120, 255}},
        {{220, 120, 255}},
    }};
    const int colorClock = std::max(player_.drawAnimationClock, 0);
    const int colorIndex = (colorClock / 20) % static_cast<int>(kFeverColors.size());
    const int nextColorIndex = (colorIndex + 1) % static_cast<int>(kFeverColors.size());
    const int colorStep = colorClock % 20;
    const auto feverChannel = [&](std::size_t channel) {
        const int current = kFeverColors[static_cast<std::size_t>(colorIndex)][channel];
        const int next = kFeverColors[static_cast<std::size_t>(nextColorIndex)][channel];
        return static_cast<int>(
            static_cast<double>(current) -
            (static_cast<double>(current - next) / 20.0) *
                static_cast<double>(colorStep));
    };
    const std::array<int, 3> feverColor{{
        feverChannel(0), feverChannel(1), feverChannel(2),
    }};
    int stageShade = 0xff;
    double bandPercent = 100.0;
    std::array<int, 3> gaugeFillColor{{stageShade, stageShade, stageShade}};
    if (!dreamGaugeFrames_.empty()) {
        if (selectedStage_ == 2 || selectedStage_ == 6 || selectedStage_ == 10) {
            stageShade = 0x60;
        }
        else if (selectedStage_ == 1) {
            stageShade = 0x80;
        }

        const int mentalLevel = std::clamp(player_.tokenStock, 0, 3);
        const int threshold = stockThresholdForCurrentConfig();
        const int bandFloor = mentalLevel * threshold;
        if (mentalLevel < 3 && threshold > 0) {
            bandPercent = std::clamp(
                static_cast<double>(player_.stockProgress - bandFloor) /
                    static_cast<double>(threshold) * 100.0,
                0.0, 100.0);
        }

        gaugeFillColor = {{stageShade, stageShade, stageShade}};
        if (mentalLevel == 1) {
            gaugeFillColor = {{0x80, 0xff, 0x80}};
        }
        else if (mentalLevel == 2) {
            gaugeFillColor = {{0x80, 0xff, 0xff}};
        }
        else if (mentalLevel == 3) {
            gaugeFillColor = {{
                (player_.drawAnimationClock & 1) == 0 ? 0x80 : 0xff,
                0xff,
                0xff,
            }};
        }
    }

    if (pass == PlayerOverlayDrawPass::MarkerRing) {
        if (std::clamp(config_.setupGroup, 0, 2) == 0 &&
            config_.optionSlots[1] == 0 && player_.focused &&
            effectMediumFrames_.size() > 16 && effectMediumFrames_[16] != -1) {
            SetDrawBright(0xff, 0x40, 0x40);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x40);
            for (int targetId : player_.optionTargetEntityIds) {
                if (targetId == 0) {
                    continue;
                }
                const auto target = std::find_if(
                    enemies_.begin(), enemies_.end(),
                    [targetId](const StageEnemy& enemy) {
                        return enemy.entityId == targetId;
                    });
                if (target == enemies_.end() || !target->active ||
                    !target->targetable) {
                    continue;
                }
                const double scale =
                    static_cast<double>(std::max(0, target->radius)) / 100.0 *
                    (1.0 + 0.1 * std::sin(
                        static_cast<double>(player_.drawAnimationClock) *
                        static_cast<double>(kPi) / 5.0));
                if (scale > 0.0) {
                    DrawRotaGraphF(
                        static_cast<float>(static_cast<int>(screenX(target->x))),
                        static_cast<float>(static_cast<int>(screenY(target->y))), scale,
                        fixedAngleToRadians(normalizeAngle16(
                            player_.drawAnimationClock * 0x29a)),
                        effectMediumFrames_[16], TRUE);
                }
            }
            SetDrawBright(0xff, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }

        drawPlayerSideObjects(PlayerSideDrawPass::Ring);
        return;
    }

    if (pass == PlayerOverlayDrawPass::GaugeFill) {
        if (dreamGaugeFrames_.size() > 1 && dreamGaugeFrames_[1] != -1) {
            SetDrawBright(gaugeFillColor[0], gaugeFillColor[1], gaugeFillColor[2]);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
            DrawCircleGauge(static_cast<int>(x), static_cast<int>(y), bandPercent,
                            dreamGaugeFrames_[1]);
            SetDrawBright(0xff, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return;
    }

    if (pass == PlayerOverlayDrawPass::GaugeFrame) {
        if (!dreamGaugeFrames_.empty() && dreamGaugeFrames_[0] != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
            SetDrawBright(stageShade, stageShade, stageShade);
            DrawRotaGraphF(
                x, y, 1.0,
                fixedAngleToRadians(normalizeAngle16(
                    -player_.drawAnimationClock * 0x100)),
                dreamGaugeFrames_[0], TRUE);
            SetDrawBright(0xff, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return;
    }

    if (pass == PlayerOverlayDrawPass::Aura) {
        if (enemyGaugeFillHandle_ != -1) {
            int gaugeWidth = 0;
            int gaugeHeight = 0;
            if (GetGraphSize(enemyGaugeFillHandle_, &gaugeWidth, &gaugeHeight) == 0 &&
                gaugeWidth > 0 && gaugeHeight > 0) {
                const auto drawAura = [&](double scaleX, float yOffset,
                                          int red, int green, int blue) {
                    if (scaleX <= 0.0) {
                        return;
                    }
                    SetDrawBright(red, green, blue);
                    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
                    DrawRotaGraph3F(
                        x,
                        static_cast<float>(static_cast<int>(
                            screenY(player_.y + yOffset))),
                        static_cast<float>(gaugeWidth) * 0.5f,
                        static_cast<float>(gaugeHeight) * 0.5f,
                        scaleX, 1.0, 0.0, enemyGaugeFillHandle_, TRUE);
                    SetDrawBright(255, 255, 255);
                    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                };
                drawAura(player_.shotVariantAuraScale, 80.0f, 255, 64, 64);
                if (player_.specialGauge < 0) {
                    drawAura(-static_cast<double>(player_.specialGauge) / 600.0,
                             80.0f,
                             feverColor[0], feverColor[1], feverColor[2]);
                }
            }
        }
        return;
    }

    if (pass == PlayerOverlayDrawPass::Hitbox) {
        const int hitbox = frameHandle(13);
        if (hitbox != -1 && player_.hitboxScale > 0.0f) {
            DrawRotaGraphF(x, y, player_.hitboxScale,
                           fixedAngleToRadians(player_.hitboxAngle16), hitbox, TRUE);
        }
    }
}

void StageRuntime::drawEnemies(int exactLayer) const {
    for (const auto& enemy : enemies_) {
        if (enemy.spawnType == 0x137 || enemy.spawnType == 0x153) {
            continue;
        }
        const float x = screenX(enemy.x);
        const float y = screenY(enemy.y);
        if (drawStage01BossExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage02BossExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage02Type19Exact(enemy, x, y, exactLayer) ||
            drawStage02Type1AExact(enemy, x, y, exactLayer) ||
            drawStage02Type1BExact(enemy, x, y, exactLayer) ||
            drawStage02Type1CExact(enemy, x, y, exactLayer) ||
            drawStage02Type1DOr1EExact(enemy, x, y, exactLayer) ||
            drawStage02Type1FExact(enemy, x, y, exactLayer) ||
            drawStage02Type20Exact(enemy, x, y, exactLayer) ||
            drawStage02Type21Exact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage03EnemyExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage04BossExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage04EnemyExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawLateStageBoss(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage01MarkerExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawType0AExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage01Type0EExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage01Type0FExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage01Type10Or11Exact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawStage01SmallEnemyExact(enemy, x, y, exactLayer)) {
            continue;
        }
        if (drawLateStageEnemy(enemy, x, y, exactLayer)) {
            continue;
        }
        if (exactLayer != 0x23) {
            continue;
        }
        const auto& frames = (enemy.spawnType >= 0x138 && enemy.spawnType <= 0x13b)
                                 ? bossFrames_
                                 : (enemyUsesMediumFrame(enemy) ? enemyMediumFrames_ : enemySmallFrames_);
        const int visualFrame = enemyVisualFrameForSpawnType(enemy);
        const int index = frames.empty() ? -1 : std::min(visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        if (handle != -1) {
            const double scale = enemyUsesMediumFrame(enemy) ? 0.42 : 0.55;
            if (enemy.spawnType == 0x35) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 110);
                DrawRotaGraphF(x, y, scale * 0.92, enemy.angle + kPi * 0.5f + kTau / 3.0f, handle, TRUE);
                DrawRotaGraphF(x, y, scale * 0.92, enemy.angle + kPi * 0.5f - kTau / 3.0f, handle, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            DrawRotaGraphF(x, y, scale, enemy.angle + kPi * 0.5f, handle, TRUE);
            if (enemy.spawnType == 0x3d) {
                for (float offset : {-80.0f, 0.0f, 80.0f}) {
                    DrawCircle(static_cast<int>(x + offset), static_cast<int>(y), 8, GetColor(120, 190, 255), FALSE);
                }
            }
        }
        else {
            DrawCircle(static_cast<int>(x), static_cast<int>(y), enemy.radius, GetColor(255, 96, 160), TRUE);
        }
    }
}

bool StageRuntime::drawStage01BossExact(const StageEnemy& enemy, float x, float y,
                                        int exactLayer) const {
    if (enemy.spawnType == 0x138) {
        if (exactLayer != 0x1e) {
            return true;
        }
        const int state = enemy.drawHelperState;
        const int timer = enemy.drawHelperTimer;
        int frame = -1;
        bool useLargeFrame = false;
        double scale = 1.0;

        switch (state) {
        case 0:
        case 1:
            frame = 0;
            useLargeFrame = true;
            break;
        case 2:
            if (timer < 130) {
                frame = 0;
                useLargeFrame = true;
            }
            else {
                frame = (timer / 7) % 3;
            }
            break;
        case 3:
            if (timer < 10) {
                frame = 3 + (timer / 5) % 2;
            }
            else if (timer < 60) {
                frame = 5 + ((timer - 10) / 5) % 3;
            }
            else if (timer < 70) {
                frame = 4 - (timer - 60) / 5;
            }
            else {
                frame = ((timer - 70) / 7) % 3;
            }
            break;
        case 4:
            frame = 8 + (timer / 5) % 2;
            scale = 1.0 - 0.3 * std::sin(static_cast<double>(timer) *
                                         static_cast<double>(kPi) / 180.0);
            break;
        case 5:
            if (timer < 80) {
                frame = (timer / 7) % 3;
            }
            else if (timer < 90) {
                frame = 3 + (timer - 80) / 5;
            }
            else {
                frame = 5 + ((timer - 90) / 5) % 3;
            }
            break;
        case 6:
            if (timer < 240) {
                frame = 8 + (timer / 5) % 2;
            }
            break;
        default:
            break;
        }

        const auto& frames = useLargeFrame ? enemyLargeFrames_ : bossFrames_;
        if (frame >= 0 && frame < static_cast<int>(frames.size())) {
            const int handle = frames[static_cast<std::size_t>(frame)];
            if (handle != -1) {
                drawOriginalMode7Node(handle, x, y, 0, scale, scale, false);
            }
        }
        return true;
    }

    if (isStage01BossDecorationType(enemy.spawnType)) {
        const int drawLayer = enemy.spawnType == 0x12 ? 0x1d : 0x1c;
        if (exactLayer != drawLayer) {
            return true;
        }
        if (!enemy.drawBodyThisFrame) {
            return true;
        }
        const auto largeHandle = [this](int frame) {
            return frame >= 0 && frame < static_cast<int>(enemyLargeFrames_.size())
                       ? enemyLargeFrames_[static_cast<std::size_t>(frame)]
                       : -1;
        };
        const auto drawLarge = [this, &largeHandle](
                                   int frame, float drawX, float drawY,
                                   std::uint16_t angle16,
                                   bool reverseX = false) {
            const int handle = largeHandle(frame);
            if (handle != -1) {
                drawOriginalMode7Node(handle, drawX, drawY, angle16,
                                      1.0, 1.0, reverseX);
            }
        };

        const int timer = enemy.drawHelperTimer;
        constexpr double kDecorationPeriod = 99.0;
        if (enemy.spawnType == 0x12) {
            const float wave = static_cast<float>(
                std::sin(static_cast<double>(timer) * kTau /
                         kDecorationPeriod));
            drawLarge(2, x, y, 0);
            drawLarge(1, x, y + wave * 2.0f - 50.0f, 0);
        }
        else if (enemy.spawnType == 0x13) {
            const bool mirrored = enemy.originX < 0.0f;
            const int amplitude = mirrored ? -700 : 700;
            const auto angle = normalizeAngle16(static_cast<int>(
                std::sin(static_cast<double>(timer - 66) * kTau /
                         kDecorationPeriod) * amplitude));
            drawLarge(3, x, y, angle, mirrored);
        }
        else {
            const bool mirrored = enemy.originX < 0.0f;
            const int amplitude = mirrored ? -900 : 900;
            const int bias = mirrored ? -8000 : 8000;
            const auto angle = normalizeAngle16(
                static_cast<int>(std::sin(
                    static_cast<double>(timer - 33) * kTau /
                    kDecorationPeriod) * amplitude) + bias);
            drawLarge(4, x, y, angle, mirrored);
        }
        return true;
    }

    if (!isStage01BossChildType(enemy.spawnType)) {
        return false;
    }
    if (exactLayer != 0x23) {
        return true;
    }
    if (!enemy.drawBodyThisFrame || enemySmallFrames_.empty()) {
        return true;
    }

    const auto smallHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto drawSmall = [&](int frame, float drawX, float drawY,
                               std::uint16_t angle16, bool reverseX) {
        const int handle = smallHandle(frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle16, 1.0, 1.0, reverseX);
        }
    };

    const double timer = static_cast<double>(enemy.drawHelperTimer);
    const double bodyWave = kTau / 50.0;
    const double wingWave = kTau / 39.0;
    const float rearWave = static_cast<float>(std::sin(timer * bodyWave));
    const float middleWave = static_cast<float>(std::sin((timer - 18.0) * bodyWave));
    const float frontWave = static_cast<float>(std::sin((timer - 36.0) * bodyWave));
    const auto flap = static_cast<std::int16_t>(
        static_cast<int>(std::sin(timer * wingWave) * 2400.0));
    const float flapRadians = fixedAngleToRadians(static_cast<std::uint16_t>(flap));
    const float wingX = std::cos(flapRadians) * 40.0f;
    const float wingY = std::sin(flapRadians) * 40.0f;

    drawSmall(14, x + wingX, y + middleWave + wingY,
              static_cast<std::uint16_t>(flap), false);
    drawSmall(14, x - wingX, y + middleWave + wingY,
              static_cast<std::uint16_t>(-flap), true);
    drawSmall(13, x, y + frontWave + 16.0f, 0, false);
    drawSmall(12, x, y + middleWave, 0, false);
    drawSmall(11, x, y + rearWave - 32.0f, 0, false);
    return true;
}

bool StageRuntime::drawStage02BossExact(const StageEnemy& enemy, float x, float y,
                                        int exactLayer) const {
    const bool root = enemy.spawnType == 0x139;
    const bool child = enemy.spawnType >= 0x22 && enemy.spawnType <= 0x24 &&
                       enemy.parentSpawnType == 0x139;
    if (!root && !child) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const auto handleAt = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawNode = [this](int handle, float drawX, float drawY,
                                 std::uint16_t angle, double scaleX,
                                 double scaleY, bool reverseX = false) {
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scaleX, scaleY, reverseX);
        }
    };

    if (child) {
        const int timer = enemy.drawHelperTimer;
        if (enemy.spawnType == 0x22) {
            const int medium = handleAt(enemyMediumFrames_, 39 + (enemy.childIndex & 3));
            const int core = handleAt(enemySmallFrames_, 20 + (timer / 3) % 3);
            const double bodyScaleX = 1.0 - 0.05 * std::sin(
                static_cast<double>(timer) * kTau / 25.0);
            double bodyScaleY = 1.0;
            double coreScale = 1.0;
            if (enemy.drawHelperState == 0 && timer < 30) {
                bodyScaleY = std::sin(static_cast<double>(timer) * kPi / 60.0);
                coreScale = 0.0;
            }
            else if (enemy.drawHelperState == 0 && timer < 50) {
                coreScale = std::sin(static_cast<double>(timer - 30) * kPi / 40.0);
            }
            if (medium != -1 && exactLayer == 0x1e) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
                SetDrawBright(0, 0, 0);
                drawNode(medium, x, y - 50.0f, 0, bodyScaleX, bodyScaleY);
                SetDrawBright(255, 255, 255);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            if (medium != -1 && exactLayer == 0x23) {
                drawNode(medium, x, y + 50.0f, 0, bodyScaleX, bodyScaleY);
            }
            if (exactLayer == 0x23) {
                drawNode(core, x, y - 60.0f, 0, coreScale, coreScale);
            }
            return true;
        }

        if (exactLayer != 0x1d) {
            return true;
        }

        const int body = handleAt(enemySmallFrames_, 23);
        int parentTimer = 0;
        for (const auto& candidate : enemies_) {
            if (candidate.entityId == enemy.parentEntityId &&
                candidate.spawnType == 0x139) {
                parentTimer = candidate.drawHelperTimer;
                break;
            }
        }
        const double orbitScale = 1.0 + 0.1 * std::sin(
            static_cast<double>(parentTimer) * kTau / 44.0);
        if (body != -1) {
            drawNode(body, x, y, enemy.sourceAngle16, orbitScale, orbitScale);
        }
        return true;
    }

    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    if (state <= 3 || (state == 4 && timer < 130)) {
        const int baseLayer = state == 0 ? 0x0f : 0x1e;
        const float yShift = state > 2 || (state == 2 && timer > 100)
                                 ? -160.0f
                                 : 0.0f;
        const double pulse = 1.0 + 0.1 * std::sin(static_cast<double>(timer) *
                                                  kTau / 60.0);
        const int largeRotor = handleAt(enemyLargeFrames_, 8);
        const int largeMiddle = handleAt(enemyLargeFrames_, 7);
        const int largeBody = handleAt(enemyLargeFrames_, 6);
        const int mediumDecoration = handleAt(enemyMediumFrames_, 46);
        const int mediumMount = handleAt(enemyMediumFrames_, 47);
        const int mediumOrbit = handleAt(enemyMediumFrames_, 48);
        const auto drawOrbitHalf = [&](bool backHalf) {
            if (mediumOrbit == -1) {
                return;
            }
            for (int i = 0; i < 13; ++i) {
                const auto orbitAngle = normalizeAngle16(frame_ * 0xde + i * 0x13b1);
                const bool isBackHalf = orbitAngle > 0x8000;
                if (isBackHalf != backHalf) {
                    continue;
                }
                const double radians = fixedAngleToRadiansDouble(orbitAngle);
                drawNode(mediumOrbit,
                         x - static_cast<float>(std::cos(radians) * 120.0),
                         y + yShift + 80.0f +
                             static_cast<float>(std::sin(radians) * 215.0),
                         0, 1.0, 1.0);
            }
        };
        static constexpr std::array<int, 6> kDecorationAngles{{
            0, 0x2aaa, 0x5554, 0x7ffe, 0xaaa8, 0xd552,
        }};
        const auto drawDecorations = [&](int begin, int end) {
            for (int i = begin; i < end; ++i) {
                const double radians = fixedAngleToRadiansDouble(
                    normalizeAngle16(kDecorationAngles[static_cast<std::size_t>(i)]));
                drawNode(mediumDecoration,
                         x - static_cast<float>(std::cos(radians) * 90.0),
                         y - 80.0f + static_cast<float>(std::sin(radians) * 140.0),
                         0, pulse, 1.0);
            }
        };

        if (exactLayer == baseLayer) {
            for (int i = 0; i < 4; ++i) {
                drawNode(largeRotor, x, y + yShift + 250.0f,
                         normalizeAngle16(frame_ * 600 + i * 0x4000),
                         1.0, 1.0);
            }
            drawNode(largeMiddle, x, y + yShift + 160.0f, 0, 1.0, 1.0);
        }

        if (state < 2 || (state == 2 && timer <= 100)) {
            if (exactLayer == baseLayer + 1) {
                drawOrbitHalf(true);
            }
            if (exactLayer == baseLayer + 2) {
                drawNode(largeBody, x, y, 0, 1.0, 1.0);
                drawDecorations(4, 6);
                drawOrbitHalf(false);
            }
            if (exactLayer == baseLayer + 3) {
                drawNode(mediumMount, x, y - 90.0f, 0, 1.0, 1.0);
                drawDecorations(0, 4);
            }
        }
        else {
            const int upper = handleAt(bossFrames_, 10 + (timer / 5) % 3);
            if (upper != -1 && exactLayer == baseLayer + 1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
                SetDrawBright(0, 0, 0);
                drawNode(upper, x, y + yShift, 0, 1.0, 1.0);
                SetDrawBright(255, 255, 255);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            if (exactLayer == baseLayer + 1) {
                drawOrbitHalf(true);
            }
            if (upper != -1 && exactLayer == baseLayer + 2) {
                drawNode(upper, x, y + yShift, 0, 1.0, 1.0);
            }
            if (exactLayer == baseLayer + 2) {
                drawOrbitHalf(false);
            }
        }
        return true;
    }

    if (exactLayer != 0x1e) {
        return true;
    }

    int bossFrame = -1;
    double scale = 1.0;
    switch (state) {
    case 4:
        bossFrame = 10 + (timer / 5) % 3;
        break;
    case 5:
    case 7:
        bossFrame = timer < 10 ? 13 + (timer / 5) % 2
                               : 15 + ((timer - 10) / 5) % 3;
        break;
    case 6:
        bossFrame = 18 + (timer / 5) % 2;
        scale = 1.0 - 0.3 * std::sin(static_cast<double>(timer) * kTau / 360.0);
        break;
    case 8:
        if (timer < 240) {
            bossFrame = 18 + (timer / 5) % 2;
        }
        break;
    default:
        break;
    }
    drawNode(handleAt(bossFrames_, bossFrame), x, y, 0, scale, scale);
    return true;
}

void StageRuntime::drawSharedBossHud(const StageEnemy& boss, int phaseMode,
                                     int maxHp, int countdown,
                                     int breaksRemaining,
                                     int bossNameIndex) const {
    if (bossGaugeFrames_.empty()) {
        return;
    }

    const int timer = boss.drawHelperTimer;
    int playerAlpha = 255;
    if (player_.y < 150.0f) {
        playerAlpha = 55;
    }
    else if (player_.y < 200.0f) {
        playerAlpha = static_cast<int>(player_.y - 150.0f) * 4 + 55;
    }

    int baseAlpha = playerAlpha;
    int overlayAlpha = 0;
    int fillRed = 64;
    int fillGreen = 64;
    int fillBlue = 64;
    double fill = 0.0;
    switch (phaseMode) {
    case 0:
    case 6:
        baseAlpha = timer < 0
                        ? 0
                        : (timer < 8
                               ? static_cast<int>(std::sin(
                                     static_cast<double>(timer) * kPi / 16.0) *
                                                   255.0)
                               : 255);
        fill = timer >= 50 ? 1.0 : std::max(0, timer) * 0.02;
        if (phaseMode == 0) {
            fillRed = 0;
            fillGreen = 255;
            fillBlue = 255;
        }
        break;
    case 1:
        fill = maxHp > 0
                   ? std::clamp(static_cast<double>(boss.drawHp) /
                                    static_cast<double>(maxHp),
                                0.0, 1.0)
                   : 0.0;
        if (fill <= 0.5) {
            fillRed = static_cast<int>(255.0 - fill * 511.0);
            fillGreen = static_cast<int>(fill * 511.0);
            fillBlue = 0;
        }
        else {
            fillRed = 0;
            fillGreen = 255;
            fillBlue = static_cast<int>((fill - 0.5) * 511.0);
        }
        break;
    case 2:
        fill = timer < 40 ? 0.0 : (timer < 70 ? (timer - 40) / 30.0 : 1.0);
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case 3:
        fill = 0.0;
        break;
    case 4:
        fill = timer < 40 ? 0.0 : (timer < 70 ? (timer - 40) / 30.0 : 1.0);
        break;
    case 5:
        fill = maxHp > 0
                   ? std::clamp(static_cast<double>(countdown) /
                                    static_cast<double>(maxHp),
                                0.0, 1.0)
                   : 0.0;
        break;
    case -1:
        overlayAlpha = timer >= 0 && timer < 64
                           ? static_cast<int>(std::sin(
                                 static_cast<double>(timer) * kPi / 64.0) *
                                               255.0)
                           : 0;
        if (timer >= 32) {
            baseAlpha = 0;
        }
        break;
    default:
        break;
    }

    const auto frameHandle = [this](int index) {
        return index >= 0 && index < static_cast<int>(bossGaugeFrames_.size())
                   ? bossGaugeFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawTopLeft = [](int handle, float x, float y,
                                double scaleX = 1.0, double scaleY = 1.0) {
        if (handle != -1) {
            DrawRotaGraph3F(x, y, 0.0f, 0.0f, scaleX, scaleY,
                            0.0, handle, TRUE);
        }
    };

    const int gauge0 = frameHandle(0);
    const int gauge1 = frameHandle(1);
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(overlayAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(2), 390.0f, 30.0f, fill, 1.0);
    SetDrawBright(std::clamp(fillRed, 0, 255),
                  std::clamp(fillGreen, 0, 255),
                  std::clamp(fillBlue, 0, 255));
    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(3), 390.0f, 30.0f, fill, 1.0);

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    if (bossNameIndex >= 0 &&
        bossNameIndex < static_cast<int>(bossNameFrames_.size()) &&
        bossNameFrames_[static_cast<std::size_t>(bossNameIndex)] != -1) {
        drawTopLeft(bossNameFrames_[static_cast<std::size_t>(bossNameIndex)],
                    372.0f, 0.0f);
    }

    const int breakHandle = frameHandle(7);
    if (breakHandle != -1) {
        for (int i = 0; i < std::max(0, breaksRemaining); ++i) {
            int breakAlpha = baseAlpha;
            double breakScale = 1.0;
            if (phaseMode == 0) {
                const int start = i * 6;
                if (timer < start) {
                    breakAlpha = 0;
                }
                else if (timer < start + 20) {
                    const double entrance = std::sin(
                        static_cast<double>(timer - start) * kPi / 40.0);
                    breakAlpha = static_cast<int>(entrance * 255.0);
                    breakScale = 3.0 - entrance * 2.0;
                }
            }
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(breakAlpha, 0, 255));
            DrawRotaGraphF(400.0f + static_cast<float>(i * 20), 74.0f,
                           breakScale, 0.0, breakHandle, TRUE);
        }
    }

    if (phaseMode == 1 || phaseMode == 5) {
        const int clampedCountdown = std::max(0, countdown);
        const int display = std::min(clampedCountdown, 5999);
        const int frames = display % 60;
        const int seconds = display / 60;
        const int tint = std::min(clampedCountdown, 255);
        SetDrawBright(255, tint, tint);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
        const auto drawDigit = [this](int digit, float x, float y,
                                      double scale) {
            if (digit >= 0 && digit < static_cast<int>(numSmallFrames_.size())) {
                const int handle = numSmallFrames_[static_cast<std::size_t>(digit)];
                if (handle != -1) {
                    DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
                }
            }
        };
        drawDigit(seconds / 10, 854.0f, 16.0f, 1.0);
        drawDigit(seconds % 10, 870.0f, 16.0f, 1.0);
        drawDigit(frames / 10, 885.0f, 20.0f, 0.6);
        drawDigit(frames % 10, 895.0f, 20.0f, 0.6);
    }

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawStage01BossHud() const {
    const auto boss = std::find_if(enemies_.begin(), enemies_.end(),
                                   [](const StageEnemy& enemy) {
                                       return enemy.spawnType == 0x138 &&
                                              (enemy.active ||
                                               enemy.drawBodyThisFrame);
                                   });
    if (boss == enemies_.end()) {
        return;
    }
    drawSharedBossHud(*boss, stage01BossPhaseMode_, stage01BossMaxHp_,
                      stage01BossCountdownDraw_, stage01BossBreaksRemaining_, 0);
}

void StageRuntime::drawLateStageBossHud() const {
    if (selectedStage_ < 5 || selectedStage_ > 10) {
        return;
    }

    const StageEnemy* boss = nullptr;
    for (const StageEnemy& enemy : enemies_) {
        // Internal apparatus nodes share the late-boss update route, but the
        // original HUD always reads the root 0x13c..0x14c entity.
        if (enemy.spawnType >= 0x13c && enemy.spawnType <= 0x14c &&
            (enemy.active || enemy.drawBodyThisFrame)) {
            boss = &enemy;
        }
    }
    if (boss == nullptr ||
        (boss->spawnType == 0x14c && boss->drawHelperState == 0)) {
        return;
    }

    const bool sharedPhaseState = isLateStageFinalBossType(boss->spawnType) ||
                                  boss->spawnType == 0x14c;
    const int phaseMode = sharedPhaseState
                              ? lateStageBossPhaseMode_
                              : (boss->drawHelperState == 0
                                     ? 0
                                     : (boss->targetable ? 1 : -1));
    const int maxHp = sharedPhaseState ? lateStageBossMaxHp_
                                       : std::max(1, boss->maxHp);
    const int breaks = sharedPhaseState ? lateStageBossBreaksRemaining_ : 1;
    int bossNameIndex = 5;
    switch (boss->spawnType) {
    case 0x13c:
        bossNameIndex = 4;
        break;
    case 0x13d:
        bossNameIndex = 6;
        break;
    case 0x13e: {
        const int state = boss->drawHelperState;
        bossNameIndex = 9;
        if ((state >= 0x15 && state <= 0x27) || state == 0x3b) {
            bossNameIndex = 7;
        }
        if ((state >= 0x29 && state <= 0x3a) || state == 0x3c) {
            bossNameIndex = 8;
        }
        break;
    }
    case 0x13f:
        bossNameIndex = 10;
        break;
    case 0x140:
        bossNameIndex = boss->drawHelperState > 10
                            ? (config_.difficulty > 3 ? 18 : 17)
                            : 10;
        break;
    case 0x141:
    case 0x14c:
        bossNameIndex = 19;
        break;
    case 0x143:
        bossNameIndex = 5;
        break;
    case 0x144:
        bossNameIndex = 7;
        break;
    case 0x145:
        bossNameIndex = 8;
        break;
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14a:
    case 0x14b:
        bossNameIndex = 11 + boss->spawnType - 0x146;
        break;
    default:
        break;
    }
    drawSharedBossHud(*boss, phaseMode, maxHp, lateStageBossCountdownDraw_,
                      breaks, bossNameIndex);
}

void StageRuntime::drawStage02BossHud() const {
    const StageEnemy* boss = nullptr;
    for (const auto& enemy : enemies_) {
        if (enemy.spawnType == 0x139 && (enemy.active || enemy.drawBodyThisFrame)) {
            boss = &enemy;
            break;
        }
    }
    if (boss == nullptr) {
        return;
    }

    const int timer = boss->drawHelperTimer;
    if (boss->drawHelperState == 8 && timer >= 60 && timer < 240) {
        const double presentationScale = timer < 76
                                             ? static_cast<double>(sineEaseIn(timer - 60, 16, 1.0f))
                                             : (timer >= 224
                                                    ? static_cast<double>(sineEaseOut(timer - 224, 16, 1.0f))
                                                    : 1.0);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        if (textBoxFrames_.size() > 1 && textBoxFrames_[1] != -1) {
            DrawRotaGraph3F(640.0f, 60.0f, 300.0f, 50.0f,
                            1.0, presentationScale, 0.0,
                            textBoxFrames_[1], TRUE);
        }
        const int iconIndex = selectedStage_ + 2;
        if (iconIndex >= 0 && iconIndex < static_cast<int>(textIconFrames_.size()) &&
            textIconFrames_[static_cast<std::size_t>(iconIndex)] != -1) {
            DrawRotaGraphF(390.0f, 60.0f, presentationScale, 0.0,
                           textIconFrames_[static_cast<std::size_t>(iconIndex)], TRUE);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (bossGaugeFrames_.empty()) {
        return;
    }

    int playerAlpha = 255;
    if (player_.y < 150.0f) {
        playerAlpha = 55;
    }
    else if (player_.y < 200.0f) {
        playerAlpha = static_cast<int>(player_.y - 150.0f) * 4 + 55;
    }
    int baseAlpha = playerAlpha;
    int overlayAlpha = 0;
    int fillRed = 64;
    int fillGreen = 64;
    int fillBlue = 64;
    double fill = 0.0;
    switch (stage02BossPhaseMode_) {
    case 0:
        baseAlpha = timer < 0
                        ? 0
                        : (timer < 8
                               ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                           kPi / 16.0) * 255.0)
                               : 255);
        fill = timer >= 50 ? 1.0 : std::max(0, timer) * 0.02;
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case 1:
        fill = stage02BossMaxHp_ > 0
                   ? std::clamp(static_cast<double>(boss->drawHp) /
                                    static_cast<double>(stage02BossMaxHp_),
                                0.0, 1.0)
                   : 0.0;
        if (fill <= 0.5) {
            fillRed = static_cast<int>(255.0 - fill * 511.0);
            fillGreen = static_cast<int>(fill * 511.0);
            fillBlue = 0;
        }
        else {
            fillRed = 0;
            fillGreen = 255;
            fillBlue = static_cast<int>((fill - 0.5) * 511.0);
        }
        break;
    case 2:
        fill = timer < 40 ? 0.0 : (timer < 70 ? (timer - 40) / 30.0 : 1.0);
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case -1:
        overlayAlpha = timer >= 0 && timer < 64
                           ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                       kPi / 64.0) * 255.0)
                           : 0;
        if (timer >= 32) {
            baseAlpha = 0;
        }
        break;
    default:
        break;
    }

    const auto frameHandle = [this](int index) {
        return index >= 0 && index < static_cast<int>(bossGaugeFrames_.size())
                   ? bossGaugeFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawTopLeft = [](int handle, float x, float y,
                                double scaleX = 1.0, double scaleY = 1.0) {
        if (handle != -1) {
            DrawRotaGraph3F(x, y, 0.0f, 0.0f, scaleX, scaleY,
                            0.0, handle, TRUE);
        }
    };

    const int gauge0 = frameHandle(0);
    const int gauge1 = frameHandle(1);
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(overlayAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(2), 390.0f, 30.0f, fill, 1.0);
    SetDrawBright(std::clamp(fillRed, 0, 255),
                  std::clamp(fillGreen, 0, 255),
                  std::clamp(fillBlue, 0, 255));
    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(3), 390.0f, 30.0f, fill, 1.0);

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    if (bossNameFrames_.size() > 1 && bossNameFrames_[1] != -1) {
        drawTopLeft(bossNameFrames_[1], 372.0f, 0.0f);
    }
    const int breakHandle = frameHandle(7);
    if (breakHandle != -1) {
        for (int i = 0; i < stage02BossBreaksRemaining_; ++i) {
            int breakAlpha = baseAlpha;
            double breakScale = 1.0;
            if (stage02BossPhaseMode_ == 0) {
                const int start = i * 6;
                if (timer < start) {
                    breakAlpha = 0;
                }
                else if (timer < start + 20) {
                    const double entrance = std::sin(
                        static_cast<double>(timer - start) * kPi / 40.0);
                    breakAlpha = static_cast<int>(entrance * 255.0);
                    breakScale = 3.0 - entrance * 2.0;
                }
            }
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(breakAlpha, 0, 255));
            DrawRotaGraphF(400.0f + static_cast<float>(i * 20),
                           74.0f, breakScale, 0.0, breakHandle, TRUE);
        }
    }
    if (stage02BossPhaseMode_ == 1) {
        const int countdown = std::max(0, stage02BossCountdownDraw_);
        const int display = std::min(countdown, 5999);
        const int frames = display % 60;
        const int seconds = display / 60;
        const int tint = std::min(countdown, 255);
        SetDrawBright(255, tint, tint);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
        const auto drawDigit = [this](int digit, float x, float y, double scale) {
            if (digit >= 0 && digit < static_cast<int>(numSmallFrames_.size())) {
                const int handle = numSmallFrames_[static_cast<std::size_t>(digit)];
                if (handle != -1) {
                    DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
                }
            }
        };
        drawDigit(seconds / 10, 854.0f, 16.0f, 1.0);
        drawDigit(seconds % 10, 870.0f, 16.0f, 1.0);
        drawDigit(frames / 10, 885.0f, 20.0f, 0.6);
        drawDigit(frames % 10, 895.0f, 20.0f, 0.6);
    }
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawStage03BossHud() const {
    const StageEnemy* boss = nullptr;
    for (const auto& enemy : enemies_) {
        if (enemy.spawnType == 0x13a && (enemy.active || enemy.drawBodyThisFrame)) {
            boss = &enemy;
            break;
        }
    }
    if (boss == nullptr) {
        return;
    }

    const int timer = boss->drawHelperTimer;
    if (boss->drawHelperState == 8 && timer >= 60 && timer < 240) {
        const double presentationScale = timer < 76
                                             ? static_cast<double>(sineEaseIn(timer - 60, 16, 1.0f))
                                             : (timer >= 224
                                                    ? static_cast<double>(sineEaseOut(timer - 224, 16, 1.0f))
                                                    : 1.0);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        if (textBoxFrames_.size() > 1 && textBoxFrames_[1] != -1) {
            DrawRotaGraph3F(640.0f, 60.0f, 300.0f, 50.0f,
                            1.0, presentationScale, 0.0,
                            textBoxFrames_[1], TRUE);
        }
        constexpr int kStage03TextIcon = 5;
        if (textIconFrames_.size() > kStage03TextIcon &&
            textIconFrames_[kStage03TextIcon] != -1) {
            DrawRotaGraphF(390.0f, 60.0f, presentationScale, 0.0,
                           textIconFrames_[kStage03TextIcon], TRUE);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (bossGaugeFrames_.empty()) {
        return;
    }

    int playerAlpha = 255;
    if (player_.y < 150.0f) {
        playerAlpha = 55;
    }
    else if (player_.y < 200.0f) {
        playerAlpha = static_cast<int>(player_.y - 150.0f) * 4 + 55;
    }
    int baseAlpha = playerAlpha;
    int overlayAlpha = 0;
    int fillRed = 64;
    int fillGreen = 64;
    int fillBlue = 64;
    double fill = 0.0;
    switch (stage03BossPhaseMode_) {
    case 0:
        baseAlpha = timer < 0
                        ? 0
                        : (timer < 8
                               ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                           kPi / 16.0) * 255.0)
                               : 255);
        fill = timer >= 50 ? 1.0 : std::max(0, timer) * 0.02;
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case 1:
        fill = stage03BossMaxHp_ > 0
                   ? std::clamp(static_cast<double>(boss->drawHp) /
                                    static_cast<double>(stage03BossMaxHp_),
                                0.0, 1.0)
                   : 0.0;
        if (fill <= 0.5) {
            fillRed = static_cast<int>(255.0 - fill * 511.0);
            fillGreen = static_cast<int>(fill * 511.0);
            fillBlue = 0;
        }
        else {
            fillRed = 0;
            fillGreen = 255;
            fillBlue = static_cast<int>((fill - 0.5) * 511.0);
        }
        break;
    case 2:
        fill = timer < 40 ? 0.0 : (timer < 70 ? (timer - 40) / 30.0 : 1.0);
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case -1:
        overlayAlpha = timer >= 0 && timer < 64
                           ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                       kPi / 64.0) * 255.0)
                           : 0;
        if (timer >= 32) {
            baseAlpha = 0;
        }
        break;
    default:
        break;
    }

    const auto frameHandle = [this](int index) {
        return index >= 0 && index < static_cast<int>(bossGaugeFrames_.size())
                   ? bossGaugeFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawTopLeft = [](int handle, float x, float y,
                                double scaleX = 1.0, double scaleY = 1.0) {
        if (handle != -1) {
            DrawRotaGraph3F(x, y, 0.0f, 0.0f, scaleX, scaleY,
                            0.0, handle, TRUE);
        }
    };

    const int gauge0 = frameHandle(0);
    const int gauge1 = frameHandle(1);
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(overlayAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(2), 390.0f, 30.0f, fill, 1.0);
    SetDrawBright(std::clamp(fillRed, 0, 255),
                  std::clamp(fillGreen, 0, 255),
                  std::clamp(fillBlue, 0, 255));
    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(3), 390.0f, 30.0f, fill, 1.0);

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    if (bossNameFrames_.size() > 2 && bossNameFrames_[2] != -1) {
        drawTopLeft(bossNameFrames_[2], 372.0f, 0.0f);
    }
    const int breakHandle = frameHandle(7);
    if (breakHandle != -1) {
        for (int i = 0; i < stage03BossBreaksRemaining_; ++i) {
            int breakAlpha = baseAlpha;
            double breakScale = 1.0;
            if (stage03BossPhaseMode_ == 0) {
                const int start = i * 6;
                if (timer < start) {
                    breakAlpha = 0;
                }
                else if (timer < start + 20) {
                    const double entrance = std::sin(
                        static_cast<double>(timer - start) * kPi / 40.0);
                    breakAlpha = static_cast<int>(entrance * 255.0);
                    breakScale = 3.0 - entrance * 2.0;
                }
            }
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(breakAlpha, 0, 255));
            DrawRotaGraphF(400.0f + static_cast<float>(i * 20),
                           74.0f, breakScale, 0.0, breakHandle, TRUE);
        }
    }
    if (stage03BossPhaseMode_ == 1) {
        const int countdown = std::max(0, stage03BossCountdownDraw_);
        const int display = std::min(countdown, 5999);
        const int frames = display % 60;
        const int seconds = display / 60;
        const int tint = std::min(countdown, 255);
        SetDrawBright(255, tint, tint);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
        const auto drawDigit = [this](int digit, float x, float y, double scale) {
            if (digit >= 0 && digit < static_cast<int>(numSmallFrames_.size())) {
                const int handle = numSmallFrames_[static_cast<std::size_t>(digit)];
                if (handle != -1) {
                    DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
                }
            }
        };
        drawDigit(seconds / 10, 854.0f, 16.0f, 1.0);
        drawDigit(seconds % 10, 870.0f, 16.0f, 1.0);
        drawDigit(frames / 10, 885.0f, 20.0f, 0.6);
        drawDigit(frames % 10, 895.0f, 20.0f, 0.6);
    }
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

const std::vector<int>& StageRuntime::localizedBossApproach1Frames() const {
    if (config_.language == 2) {
        return bossApproach1Ch1Frames_;
    }
    if (config_.language == 3) {
        return bossApproach1Ch2Frames_;
    }
    return bossApproach1Frames_;
}

void StageRuntime::drawStage04BossHud() const {
    const StageEnemy* boss = nullptr;
    for (const auto& enemy : enemies_) {
        if (enemy.spawnType == 0x13b && (enemy.active || enemy.drawBodyThisFrame)) {
            boss = &enemy;
            break;
        }
    }
    if (boss == nullptr) {
        return;
    }

    const int timer = boss->drawHelperTimer;
    const auto& approachFrames = localizedBossApproach1Frames();
    if (boss->drawHelperState == 2 && timer >= 220 && timer < 380 &&
        approachFrames.size() > 5) {
        const int age = timer - 220;
        const auto envelopeAlpha = [age](int start) {
            if (age < start) {
                return 0;
            }
            if (age < start + 20) {
                return static_cast<int>(
                    std::sin(static_cast<double>(age - start) * kPi / 40.0) *
                    255.0);
            }
            if (age < 120) {
                return 255;
            }
            return static_cast<int>(
                std::sin(static_cast<double>(age - 80) * kPi / 80.0) *
                255.0);
        };
        const auto envelopeScale = [age](int start) {
            if (age < start) {
                return 3.0;
            }
            if (age < start + 20) {
                return 3.0 - 2.0 * std::sin(
                    static_cast<double>(age - start) * kPi / 40.0);
            }
            return 1.0;
        };
        const auto backgroundAlpha = [age](int maximum) {
            if (age < 20) {
                return static_cast<int>(
                    std::sin(static_cast<double>(age) * kPi / 40.0) *
                    static_cast<double>(maximum));
            }
            if (age < 120) {
                return maximum;
            }
            return static_cast<int>(
                std::sin(static_cast<double>(age - 80) * kPi / 80.0) *
                static_cast<double>(maximum));
        };
        const int backdropAlpha = backgroundAlpha(128);
        if (whiteBackHandle_ != -1 && backdropAlpha > 0) {
            SetDrawBright(0, 0, 0);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(backdropAlpha, 0, 0xff));
            DrawExtendGraph(0, 0, 1280, 720, whiteBackHandle_, TRUE);
        }

        const int gridAlpha = backgroundAlpha(40);
        if (!approachFrames.empty() && approachFrames[0] != -1 && gridAlpha > 0) {
            constexpr double kGridAngleA = 5.862874571298915;
            constexpr double kGridAngleB = 4.904136578870390;
            const int phase = (frame_ % 210) * 2;
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(gridAlpha, 0, 0xff));
            for (int row = 0; row < 7; ++row) {
                const int rowOffset = phase + row * 420;
                for (int column = 0; column < 32; ++column) {
                    const int columnOffset = column * 60;
                    const float x = static_cast<float>(
                        columnOffset * std::cos(kGridAngleB) +
                        rowOffset * std::cos(kGridAngleA) - 1000.0);
                    const float y = static_cast<float>(
                        columnOffset * std::sin(kGridAngleB) +
                        rowOffset * std::sin(kGridAngleA) + 1440.0);
                    DrawRotaGraph3F(x, y, 200.0f, 50.0f,
                                    1.0, 1.0,
                                    fixedAngleToRadiansDouble(0xeee0),
                                    approachFrames[0], TRUE);
                }
            }
        }

        const int standAlpha = envelopeAlpha(20);
        if (stage04PhaseTitleStandHandle_ != -1 && standAlpha > 0) {
            const double standScale = envelopeScale(20);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(standAlpha, 0, 0xff));
            DrawRotaGraph3F(660.0f, 360.0f, 400.0f, 500.0f,
                            standScale, standScale, 0.0,
                            stage04PhaseTitleStandHandle_, TRUE);
        }

        const int titleAlpha = envelopeAlpha(44);
        if (titleAlpha > 0) {
            const double titleScale = envelopeScale(44);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(titleAlpha, 0, 0xff));
            const double angle = fixedAngleToRadiansDouble(0xf830);
            if (approachFrames[1] != -1) {
                DrawRotaGraph3F(650.0f, 450.0f, 200.0f, 50.0f,
                                titleScale, titleScale, angle,
                                approachFrames[1], TRUE);
            }
            if (approachFrames[5] != -1) {
                DrawRotaGraph3F(720.0f, 500.0f, 200.0f, 50.0f,
                                titleScale, titleScale, angle,
                                approachFrames[5], TRUE);
            }
        }
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (boss->drawHelperState == 11 && timer >= 60 && timer < 240) {
        const double presentationScale = timer < 76
                                             ? static_cast<double>(sineEaseIn(timer - 60, 16, 1.0f))
                                             : (timer >= 224
                                                    ? static_cast<double>(sineEaseOut(timer - 224, 16, 1.0f))
                                                    : 1.0);
        SetDrawBright(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        if (textBoxFrames_.size() > 1 && textBoxFrames_[1] != -1) {
            DrawRotaGraph3F(640.0f, 60.0f, 300.0f, 50.0f,
                            1.0, presentationScale, 0.0,
                            textBoxFrames_[1], TRUE);
        }
        constexpr int kStage04TextIcon = 6;
        if (textIconFrames_.size() > kStage04TextIcon &&
            textIconFrames_[kStage04TextIcon] != -1) {
            DrawRotaGraphF(390.0f, 60.0f, presentationScale, 0.0,
                           textIconFrames_[kStage04TextIcon], TRUE);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (bossGaugeFrames_.empty()) {
        return;
    }

    int playerAlpha = 255;
    if (player_.y < 150.0f) {
        playerAlpha = 55;
    }
    else if (player_.y < 200.0f) {
        playerAlpha = static_cast<int>(player_.y - 150.0f) * 4 + 55;
    }
    int baseAlpha = playerAlpha;
    int overlayAlpha = 0;
    int fillRed = 64;
    int fillGreen = 64;
    int fillBlue = 64;
    double fill = 0.0;
    switch (stage04BossPhaseMode_) {
    case 0:
        baseAlpha = timer < 0
                        ? 0
                        : (timer < 8
                               ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                           kPi / 16.0) * 255.0)
                               : 255);
        fill = timer >= 50 ? 1.0 : std::max(0, timer) * 0.02;
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case 1:
        fill = stage04BossMaxHp_ > 0
                   ? std::clamp(static_cast<double>(boss->drawHp) /
                                    static_cast<double>(stage04BossMaxHp_),
                                0.0, 1.0)
                   : 0.0;
        if (fill <= 0.5) {
            fillRed = static_cast<int>(255.0 - fill * 511.0);
            fillGreen = static_cast<int>(fill * 511.0);
            fillBlue = 0;
        }
        else {
            fillRed = 0;
            fillGreen = 255;
            fillBlue = static_cast<int>((fill - 0.5) * 511.0);
        }
        break;
    case 2:
        fill = timer < 40 ? 0.0 : (timer < 70 ? (timer - 40) / 30.0 : 1.0);
        fillRed = 0;
        fillGreen = 255;
        fillBlue = 255;
        break;
    case -1:
        overlayAlpha = timer >= 0 && timer < 64
                           ? static_cast<int>(std::sin(static_cast<double>(timer) *
                                                       kPi / 64.0) * 255.0)
                           : 0;
        if (timer >= 32) {
            baseAlpha = 0;
        }
        break;
    default:
        break;
    }

    const auto frameHandle = [this](int index) {
        return index >= 0 && index < static_cast<int>(bossGaugeFrames_.size())
                   ? bossGaugeFrames_[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawTopLeft = [](int handle, float x, float y,
                                double scaleX = 1.0, double scaleY = 1.0) {
        if (handle != -1) {
            DrawRotaGraph3F(x, y, 0.0f, 0.0f, scaleX, scaleY,
                            0.0, handle, TRUE);
        }
    };

    const int gauge0 = frameHandle(0);
    const int gauge1 = frameHandle(1);
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(overlayAlpha, 0, 255));
    drawTopLeft(gauge0, 378.0f, 30.0f);
    drawTopLeft(gauge1, 402.0f, 30.0f);

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(2), 390.0f, 30.0f, fill, 1.0);
    SetDrawBright(std::clamp(fillRed, 0, 255),
                  std::clamp(fillGreen, 0, 255),
                  std::clamp(fillBlue, 0, 255));
    SetDrawBlendMode(DX_BLENDMODE_ADD, std::clamp(baseAlpha, 0, 255));
    drawTopLeft(frameHandle(3), 390.0f, 30.0f, fill, 1.0);

    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
    if (bossNameFrames_.size() > 3 && bossNameFrames_[3] != -1) {
        drawTopLeft(bossNameFrames_[3], 372.0f, 0.0f);
    }
    const int breakHandle = frameHandle(7);
    if (breakHandle != -1) {
        for (int i = 0; i < stage04BossBreaksRemaining_; ++i) {
            int breakAlpha = baseAlpha;
            double breakScale = 1.0;
            if (stage04BossPhaseMode_ == 0) {
                const int start = i * 6;
                if (timer < start) {
                    breakAlpha = 0;
                }
                else if (timer < start + 20) {
                    const double entrance = std::sin(
                        static_cast<double>(timer - start) * kPi / 40.0);
                    breakAlpha = static_cast<int>(entrance * 255.0);
                    breakScale = 3.0 - entrance * 2.0;
                }
            }
            SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                             std::clamp(breakAlpha, 0, 255));
            DrawRotaGraphF(400.0f + static_cast<float>(i * 20),
                           74.0f, breakScale, 0.0, breakHandle, TRUE);
        }
    }
    if (stage04BossPhaseMode_ == 1) {
        const int countdown = std::max(0, stage04BossCountdownDraw_);
        const int display = std::min(countdown, 5999);
        const int frames = display % 60;
        const int seconds = display / 60;
        const int tint = std::min(countdown, 255);
        SetDrawBright(255, tint, tint);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(baseAlpha, 0, 255));
        const auto drawDigit = [this](int digit, float x, float y, double scale) {
            if (digit >= 0 && digit < static_cast<int>(numSmallFrames_.size())) {
                const int handle = numSmallFrames_[static_cast<std::size_t>(digit)];
                if (handle != -1) {
                    DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
                }
            }
        };
        drawDigit(seconds / 10, 854.0f, 16.0f, 1.0);
        drawDigit(seconds % 10, 870.0f, 16.0f, 1.0);
        drawDigit(frames / 10, 885.0f, 20.0f, 0.6);
        drawDigit(frames % 10, 895.0f, 20.0f, 0.6);
    }
    SetDrawBright(255, 255, 255);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawStageApproach() const {
    const bool earlyStageApproach = selectedStage_ >= 1 && selectedStage_ <= 4;
    const bool lateStageApproach = selectedStage_ >= 5 && selectedStage_ <= 10;
    const int age = earlyStageApproach ? earlyStageApproachAgeDraw_
                                       : lateStageApproachAgeDraw_;
    const auto& approachFrames = localizedBossApproach1Frames();
    if ((!earlyStageApproach && !lateStageApproach) || age < 0 || age > 300 ||
        bossApproach2Handle_ == -1 || approachFrames.empty() ||
        approachFrames.front() == -1) {
        return;
    }

    double scale = 1.0;
    int alpha = 0xff;
    int flashAlpha = 0x80;
    if (age < 60) {
        const double entrance = std::sin(static_cast<double>(age) * kPi / 120.0);
        scale = 5.0 - entrance * 4.0;
        alpha = static_cast<int>(entrance * 255.0);
        flashAlpha = static_cast<int>(entrance * 128.0);
    }
    else if (age >= 270) {
        const double exit = std::sin(static_cast<double>(300 - age) * kPi / 60.0);
        scale = 5.0 - exit * 4.0;
        alpha = static_cast<int>(exit * 255.0);
    }
    alpha += static_cast<int>(48.0 * std::sin(
                 static_cast<double>(age) * kPi / 10.0)) - 48;
    if (age >= 240) {
        flashAlpha = static_cast<int>(
            std::sin(static_cast<double>(300 - age) * kPi / 120.0) * 128.0);
    }

    if (whiteBackHandle_ != -1 && flashAlpha > 0) {
        SetDrawBright(0, 0, 0);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                         std::clamp(flashAlpha, 0, 0xff));
        DrawExtendGraph(0, 0, 1280, 720, whiteBackHandle_, TRUE);
    }
    SetDrawBright(255, 255, 255);

    // FUN_140001060 fills the approach backdrop with 7x32 faint diagonal
    // copies of BossApproach1[0]. Preserve its two fixed angles and spacing.
    const int stripHandle = approachFrames.front();
    const double gridAngleA = 5.862874571298915;
    const double gridAngleB = 4.904136578870390;
    const int sourceFrame = frame_ > 0 ? frame_ - 1 : frame_;
    const int gridPhase = (sourceFrame % 210) * 2;
    const int gridAlpha = std::clamp(
        20 + static_cast<int>(20.0 * std::sin(
                 static_cast<double>(sourceFrame % 210) * kPi / 210.0)),
        0, 0xff);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, gridAlpha);
    for (int row = 0; row < 7; ++row) {
        const int rowOffset = gridPhase + row * 420;
        for (int column = 0; column < 32; ++column) {
            const int columnOffset = column * 60;
            const float x = static_cast<float>(
                columnOffset * std::cos(gridAngleB) +
                rowOffset * std::cos(gridAngleA) - 1000.0);
            const float y = static_cast<float>(
                columnOffset * std::sin(gridAngleB) +
                rowOffset * std::sin(gridAngleA) + 1440.0);
            DrawRotaGraph3F(x, y, 200.0f, 50.0f, 1.0, 1.0,
                            fixedAngleToRadiansDouble(0xeee0),
                            stripHandle, TRUE);
        }
    }

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 0xff));
    DrawRotaGraph3F(640.0f, 300.0f, 300.0f, 75.0f,
                    1.0, scale, 0.0, bossApproach2Handle_, TRUE);

    const float travel = static_cast<float>((age % 105) * 4);
    for (int strip = 0; strip < 4; ++strip) {
        const float x = static_cast<float>(strip * 420) + travel;
        DrawRotaGraph3F(x, 300.0f - static_cast<float>(scale * 90.0),
                        200.0f, 50.0f, scale, scale, 0.0,
                        stripHandle, TRUE);
        DrawRotaGraph3F(1280.0f - x,
                        300.0f + static_cast<float>(scale * 90.0),
                        200.0f, 50.0f, scale, scale, 0.0,
                        stripHandle, TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawStageBannerPanels() const {
    if (selectedStage_ < 1 || selectedStage_ > 10) {
        return;
    }

    const int sourceFrame = frame_ > 0 ? frame_ - 1 : -1;
    const int group = std::clamp(config_.setupGroup, 0, 2);
    SetDrawBright(0xff, 0xff, 0xff);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xff);
    for (const auto& banner : kStageBanners) {
        if (banner.stage != selectedStage_) {
            continue;
        }
        if (sourceFrame < banner.startFrame || sourceFrame >= banner.endFrame) {
            continue;
        }

        const int localFrame = sourceFrame - banner.startFrame;
        const int duration = banner.endFrame - banner.startFrame;
        double envelope = 1.0;
        if (localFrame < 16) {
            envelope = static_cast<double>(sineEaseIn(localFrame, 16, 1.0f));
        }
        else if (localFrame >= duration - 16) {
            envelope = static_cast<double>(
                sineEaseOut(localFrame - (duration - 16), 16, 1.0f));
        }

        const int panelIndex = banner.mode == 0 ? 0 : 1;
        const float centerY = banner.mode == 0
                                  ? 660.0f
                                  : (banner.mode == 2 ? 160.0f : 60.0f);
        if (panelIndex < static_cast<int>(textBoxFrames_.size())) {
            const int handle = textBoxFrames_[static_cast<std::size_t>(panelIndex)];
            if (handle != -1) {
                DrawRotaGraph3F(640.0f, centerY, 300.0f, 50.0f,
                                1.0, envelope, 0.0, handle, TRUE);
            }
        }

        const int iconIndex = banner.iconIndex < 0 ? group : banner.iconIndex;
        if (iconIndex >= 0 && iconIndex < static_cast<int>(textIconFrames_.size())) {
            const int handle = textIconFrames_[static_cast<std::size_t>(iconIndex)];
            if (handle != -1) {
                DrawRotaGraphF(390.0f, centerY, envelope, 0.0, handle, TRUE);
            }
        }
    }
    SetDrawBright(0xff, 0xff, 0xff);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawStageBannerText() const {
    if (config_.textDatabase == nullptr) {
        return;
    }

    const int sourceFrame = frame_ > 0 ? frame_ - 1 : -1;
    const int language = std::clamp(config_.language, 0, 3);
    const int revealRate = language == 1 ? 1 : 2;
    const int characterStep = language == 1 ? 9 : 18;
    const int fontHandle = bannerFontHandles_[language < 2 ? 0 : 1];
    if (fontHandle == -1) {
        return;
    }

    const int group = std::clamp(config_.setupGroup, 0, 2);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xff);
    for (const auto& banner : kStageBanners) {
        if (banner.stage != selectedStage_) {
            continue;
        }
        const int textStart = banner.startFrame + 16;
        const int textEnd = banner.endFrame - 16;
        if (sourceFrame < textStart || sourceFrame >= textEnd) {
            continue;
        }

        const TextRecord* record = config_.textDatabase->find(
            language, stageBannerTextId(banner, group,
                                        config_.specialStageFlag != 0));
        if (record == nullptr) {
            continue;
        }
        const bool hasLine2 = record->line2 != "NULL";
        const int line1Count = utf8CodePointCount(record->line1);
        const int line2Count = hasLine2 ? utf8CodePointCount(record->line2) : 0;
        const int textAge = sourceFrame - textStart;
        int remaining = std::min(line1Count + line2Count,
                                 textAge / revealRate + 1);
        int characterOrdinal = 0;
        const int baseY = banner.mode == 0
                              ? 635
                              : (banner.mode == 2 ? 135 : 35);
        const unsigned int color = banner.mode == 0
                                       ? GetColor(0x40, 0x40, 0x80)
                                       : GetColor(0xff, 0xff, 0xff);

        const auto drawLine = [&](std::string_view line, int lineIndex) {
            int column = 0;
            for (std::size_t offset = 0;
                 offset < line.size() && remaining > 0;
                 ++column, ++characterOrdinal, --remaining) {
                const std::size_t length = utf8CodePointLength(line, offset);
                const std::string glyph(line.substr(offset, length));
                const int waveY = static_cast<int>(std::sin(
                    static_cast<double>(textAge - characterOrdinal * 3) *
                    kStageTextBobStep) * 2.0);
                DrawStringToHandle(435 + column * characterStep,
                                   baseY + lineIndex * 30 + waveY,
                                   glyph.c_str(), color, fontHandle);
                offset += length;
            }
        };
        drawLine(record->line1, 0);
        if (hasLine2 && remaining > 0) {
            drawLine(record->line2, 1);
        }
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawEnemyGaugeExact(const StageEnemy& enemy, int mode, float x,
                                       float y, int exactLayer) const {
    if (exactLayer != 0x32 ||
        mode < 0 || mode >= static_cast<int>(enemyGaugeFrames_.size()) ||
        enemy.hp < 0 || enemy.maxHp <= 0) {
        return;
    }

    const double ratio = static_cast<double>(enemy.hp) / static_cast<double>(enemy.maxHp);
    int red = 0;
    int green = 255;
    int blue = static_cast<int>((ratio - 0.5) * 511.0);
    if (ratio <= 0.5) {
        red = static_cast<int>(255.0 - ratio * 511.0);
        green = static_cast<int>(ratio * 511.0);
        blue = 0;
    }
    red = std::clamp(red, 0, 255);
    green = std::clamp(green, 0, 255);
    blue = std::clamp(blue, 0, 255);

    double fillScale = ratio;
    float fillOffsetX = -120.0f;
    if (mode == 1) {
        fillScale *= 0.5;
        fillOffsetX = -60.0f;
    }
    else if (mode == 2) {
        fillScale /= 3.0;
        fillOffsetX = -40.0f;
    }

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
    const int background = enemyGaugeFrames_[static_cast<std::size_t>(mode)];
    if (background != -1) {
        DrawRotaGraphF(x, y, 1.0, 0.0, background, TRUE);
    }
    if (enemyGaugeFillHandle_ != -1) {
        SetDrawBright(red, green, blue);
        DrawRotaGraph3F(x + fillOffsetX, y - 5.0f, 0.0f, 0.0f,
                        fillScale, 1.0, 0.0, enemyGaugeFillHandle_, TRUE);
        SetDrawBright(255, 255, 255);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

bool StageRuntime::drawStage02Type1BExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x1b) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX), screenY(enemy.markerDrawY),
                                  0, scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
        return true;
    }
    if (exactLayer != 0x20) {
        return true;
    }

    constexpr double kPiDouble = 3.14159265358979;
    const int timer = enemy.drawHelperTimer;
    const int flap = static_cast<int>(
        std::sin(static_cast<double>(timer) * 2.0 * kPiDouble / 27.0) * 3300.0);
    const std::uint16_t flapAngle = normalizeAngle16(flap);
    const double flapRadians = fixedAngleToRadiansDouble(flapAngle);
    const float flapX = static_cast<float>(std::cos(flapRadians) * 20.0);
    const float flapY = static_cast<float>(std::sin(flapRadians) * 20.0);
    const int wing = enemyMediumFrames_.size() > 35 ? enemyMediumFrames_[35] : -1;
    const int center = enemyMediumFrames_.size() > 34 ? enemyMediumFrames_[34] : -1;

    if (wing != -1) {
        drawOriginalMode7Node(wing, x + 30.0f + flapX, y + 10.0f + flapY,
                              flapAngle, 1.0, 1.0, false);
        drawOriginalMode7Node(wing, x - 30.0f - flapX, y + 10.0f + flapY,
                              normalizeAngle16(-flap), 1.0, 1.0, true);
    }
    if (center != -1) {
        const double scaleY =
            1.0 + 0.05 * std::sin(static_cast<double>(timer) * 2.0 * kPiDouble / 72.0);
        drawOriginalMode7Node(center, x, y, 0, 1.0, scaleY, false);
    }
    return true;
}

bool StageRuntime::drawStage02Type1CExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x1c) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX), screenY(enemy.markerDrawY),
                                  0, scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
        return true;
    }
    if (exactLayer != 0x20) {
        return true;
    }

    const auto medium = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const int timer = enemy.drawHelperTimer;
    const int lower = medium(37);
    const int center = medium(36);
    const int rotor = medium(38);
    if (lower != -1) {
        drawOriginalMode7Node(lower, x, y + 35.0f, 0, 1.0, 1.0, false);
    }
    if (center != -1) {
        const double scaleX =
            1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 61.0);
        drawOriginalMode7Node(center, x, y, 0, scaleX, 1.0, false);
    }
    if (rotor != -1) {
        const int angle = timer * 0x708;
        drawOriginalMode7Node(rotor, x, y - 50.0f, normalizeAngle16(angle),
                              1.0, 1.0, false);
        drawOriginalMode7Node(rotor, x, y - 50.0f, normalizeAngle16(angle + 0x5555),
                              1.0, 1.0, false);
        drawOriginalMode7Node(rotor, x, y - 50.0f, normalizeAngle16(angle - 0x5556),
                              1.0, 1.0, false);
    }
    return true;
}

bool StageRuntime::drawStage02Type1DOr1EExact(const StageEnemy& enemy, float x,
                                              float y, int exactLayer) const {
    if (enemy.spawnType != 0x1d && enemy.spawnType != 0x1e) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        return true;
    }
    if (exactLayer != 0x18 && exactLayer != 0x19) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0x1d) {
        double scaleX = 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 60.0);
        if (timer % 120 < 11) {
            scaleX = 1.0 + 0.05 * std::sin(static_cast<double>(timer) * kTau / 10.0);
        }
        const int body = enemySmallFrames_.size() > 19 ? enemySmallFrames_[19] : -1;
        if (body != -1 && exactLayer == 0x18) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            drawOriginalMode7Node(body, x, y, 0, scaleX, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (body != -1 && exactLayer == 0x19) {
            drawOriginalMode7Node(body, x, y, 0, scaleX, 1.0, false);
        }
    }
    else {
        const double scaleX = 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 25.0);
        const int mediumIndex = 39 + (enemy.entityId % 4);
        const int mediumBody = mediumIndex >= 0 && mediumIndex < static_cast<int>(enemyMediumFrames_.size())
                                   ? enemyMediumFrames_[static_cast<std::size_t>(mediumIndex)]
                                   : -1;
        if (mediumBody != -1 && exactLayer == 0x18) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            drawOriginalMode7Node(mediumBody, x, y - 50.0f, 0, scaleX, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (mediumBody != -1 && exactLayer == 0x19) {
            drawOriginalMode7Node(mediumBody, x, y - 50.0f, 0, scaleX, 1.0, false);
        }
        const int smallIndex = 20 + (timer / 3) % 3;
        const int smallBody = smallIndex >= 0 && smallIndex < static_cast<int>(enemySmallFrames_.size())
                                  ? enemySmallFrames_[static_cast<std::size_t>(smallIndex)]
                                  : -1;
        if (smallBody != -1 && exactLayer == 0x19) {
            drawOriginalMode7Node(smallBody, x, y - 60.0f, 0, 1.0, 1.0, false);
        }
    }
    return true;
}

bool StageRuntime::drawStage02Type1FExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x1f) {
        return false;
    }

    const int body = enemyMediumFrames_.size() > 43 ? enemyMediumFrames_[43] : -1;
    int timer = enemy.drawHelperTimer;
    if (enemy.drawHelperState == 1 && timer == 0 && !enemy.targetable && enemy.age > 1) {
        // FUN_140087750 computes this frame's body scale before resetting the
        // state timer on entry.
        timer = enemy.age - 1;
    }
    const double scale = enemy.drawHelperState == 2
                             ? 1.0 + 0.15 * std::sin(static_cast<double>(timer) * kTau / 9.0)
                             : 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 50.0);
    if (body != -1 && exactLayer == 0x18) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(body, x, y, 0, scale, 1.0, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (body != -1 && exactLayer == 0x1a) {
        drawOriginalMode7Node(body, x, y, 0, scale, 1.0, false);
    }
    if (enemy.targetable) {
        drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
    }
    return true;
}

bool StageRuntime::drawStage02Type19Exact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x19) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 2.0 - static_cast<double>(enemy.markerDrawTimer) * 0.1);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                  screenY(enemy.markerDrawY), 0, scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        return true;
    }
    if (exactLayer != 0x23) {
        return true;
    }

    const int center = enemySmallFrames_.size() > 15 ? enemySmallFrames_[15] : -1;
    const int side = enemySmallFrames_.size() > 16 ? enemySmallFrames_[16] : -1;
    const int timer = enemy.drawHelperTimer;
    const auto sideAngle = normalizeAngle16(
        static_cast<int>(std::sin(static_cast<double>(timer) * kTau / 11.0) * 6500.0) -
        8000);
    const double sideRadians = fixedAngleToRadiansDouble(sideAngle);
    const float sideX = static_cast<float>(std::cos(sideRadians) * 40.0);
    const float sideY = static_cast<float>(std::sin(sideRadians) * 40.0);

    if (side != -1) {
        drawOriginalMode7Node(side, x + sideX + 15.0f, y + sideY - 5.0f,
                              sideAngle, 1.0, 1.0, false);
        drawOriginalMode7Node(side, x - sideX - 15.0f, y + sideY - 5.0f,
                              normalizeAngle16(-static_cast<int>(sideAngle)),
                              1.0, 1.0, true);
    }
    if (center != -1) {
        const double scale = 1.0 +
                             0.1 * std::sin(static_cast<double>(timer) * kTau / 51.0);
        drawOriginalMode7Node(center, x, y, 0, scale, scale, false);
    }
    return true;
}

bool StageRuntime::drawStage02Type1AExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x1a) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 2.0 - static_cast<double>(enemy.markerDrawTimer) * 0.1);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                  screenY(enemy.markerDrawY), 0, scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        drawEnemyGaugeExact(enemy, 2, x, y, exactLayer);
        return true;
    }
    if (exactLayer != 0x23) {
        return true;
    }

    const int rotating = enemySmallFrames_.size() > 17 ? enemySmallFrames_[17] : -1;
    const int center = enemySmallFrames_.size() > 18 ? enemySmallFrames_[18] : -1;
    const int timer = enemy.drawHelperTimer;
    if (rotating != -1) {
        const double scale = 1.0 +
                             0.1 * std::sin(static_cast<double>(timer) * kTau / 23.0);
        drawOriginalMode7Node(rotating, x, y, enemy.secondaryAngle16,
                              scale, scale, false);
    }
    if (center != -1) {
        drawOriginalMode7Node(center, x, y, 0, 1.0, 1.0, false);
    }
    return true;
}

bool StageRuntime::drawStage02Type20Exact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x20) {
        return false;
    }

    const int largeBody = enemyLargeFrames_.size() > 5 ? enemyLargeFrames_[5] : -1;
    const int mediumBody = enemyMediumFrames_.size() > 45 ? enemyMediumFrames_[45] : -1;
    int timer = enemy.drawHelperTimer;
    if (enemy.drawHelperState == 1 && timer == 0 && enemy.age > 1) {
        // FUN_140088110 computes scale and bob before its state-0 timer reset.
        timer = enemy.age - 1;
    }
    const double scale = enemy.drawHelperState == 2
                             ? 1.0 + 0.1 * std::sin(static_cast<double>(timer) * kTau / 19.0)
                             : 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 101.0);
    const float bob = 2.0f * std::sin(static_cast<float>(timer) * kTau / 72.0f);

    if (largeBody != -1 && exactLayer == 0x18) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(largeBody, x, y - 125.0f, 0, scale, 0.6, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (largeBody != -1 && exactLayer == 0x1a) {
        drawOriginalMode7Node(largeBody, x, y - 120.0f, 0, scale, 1.0, false);
    }
    if (mediumBody != -1 && exactLayer == 0x1a) {
        drawOriginalMode7Node(mediumBody, x, y + 50.0f + bob, 0, 1.0, 1.0, false);
    }
    if (enemy.targetable) {
        drawEnemyGaugeExact(enemy, 0, x, y, exactLayer);
    }
    return true;
}

bool StageRuntime::drawStage02Type21Exact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x21 || enemy.parentSpawnType != 0x20) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const int body = enemyMediumFrames_.size() > 44 ? enemyMediumFrames_[44] : -1;
    const int timer = enemy.drawHelperTimer;
    const double scale = 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 72.0);
    const float bodyY = y - 60.0f;
    if (body != -1 && exactLayer == 0x18) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(body, x, bodyY, 0, scale, 1.0, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (body != -1 && exactLayer == 0x19) {
        drawOriginalMode7Node(body, x, bodyY, 0, scale, 1.0, false);
    }

    drawEnemyGaugeExact(enemy, 1, x, y, exactLayer);
    return true;
}

bool StageRuntime::drawStage03EnemyExact(const StageEnemy& enemy, float x, float y,
                                         int exactLayer) const {
    if (!isStage03FocusedType(enemy.spawnType) &&
        !isStage03BossNodeType(enemy.spawnType)) {
        return false;
    }

    const auto small = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto medium = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto large = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyLargeFrames_.size())
                   ? enemyLargeFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto draw = [this](int handle, float drawX, float drawY, std::uint16_t angle,
                             double scaleX = 1.0, double scaleY = 1.0, bool reverse = false) {
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle, scaleX, scaleY, reverse);
        }
    };
    const auto drawGauge = [this, &enemy, x, y, exactLayer](int mode) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, mode, x, y, exactLayer);
    };

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        double scale = 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15;
        if (enemy.spawnType == 0x25) {
            scale = 2.0 - static_cast<double>(enemy.markerDrawTimer) * 0.1;
        }
        else if (enemy.spawnType == 0x2b) {
            scale = 4.0 - static_cast<double>(enemy.markerDrawTimer) * 0.2;
        }
        draw(marker, screenX(enemy.markerDrawX), screenY(enemy.markerDrawY), 0,
             std::max(0.0, scale), std::max(0.0, scale));
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    switch (enemy.spawnType) {
    case 0x13a: {
        const int state = enemy.drawHelperState;
        if (state <= 3 || (state == 4 && timer < 130)) {
            if (exactLayer == 0x20) {
                draw(large(13), x, y, 0);
            }
            if (exactLayer == 0x22) {
                for (int i = 0; i < 4; ++i) {
                    draw(large(15), x, y - 255.0f,
                         normalizeAngle16(frame_ * 0x500 + i * 0x4000));
                }
            }
            break;
        }

        int bossFrame = -1;
        if ((state == 4 && timer >= 130) || state == 5 || state == 7) {
            bossFrame = 20 + (timer / 7) % 3;
        }
        else if (state == 6 || (state == 8 && timer < 240)) {
            bossFrame = 23 + (timer / 5) % 2;
        }
        if (exactLayer == 0x1e && bossFrame >= 0 &&
            bossFrame < static_cast<int>(bossFrames_.size())) {
            draw(bossFrames_[static_cast<std::size_t>(bossFrame)], x, y, 0);
        }
        break;
    }
    case 0x30: {
        if (exactLayer == 0x1f && enemy.drawHelperState <= 2) {
            const int bodyFrame = enemy.drawHelperState == 2 ? 16 : 14;
            draw(large(bodyFrame), x, y, 0, 1.0, 1.0,
                 enemy.originX < 0.0f);
        }
        if (exactLayer == 0x1e && !effectSmallFrames_.empty() &&
            effectSmallFrames_[0] != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (timer % 4 >= 2) {
                SetDrawBright(255, 128, 0);
            }
            const float accentX = x + (enemy.originX < 0.0f ? 85.0f : -85.0f);
            draw(effectSmallFrames_[0], accentX, y - 255.0f, 0);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (enemy.targetable) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 1, x, y, exactLayer);
        }
        break;
    }
    case 0x31:
        if (exactLayer == 0x21) {
            draw(medium(62), x, y, enemy.sourceAngle16);
        }
        break;
    case 0x32:
    case 0x33:
    case 0x34: {
        double outerScale = 1.0;
        double innerScale = 1.0;
        if (enemy.drawHelperState == 0) {
            if (timer < 10) {
                outerScale = sineEaseIn(timer, 10, 1.0f);
                innerScale = 0.0;
            }
            else if (timer < 40) {
                innerScale = sineEaseIn(timer - 10, 30, 1.0f);
            }
        }
        if (exactLayer == 0x23) {
            draw(small(30), x, y, 0, outerScale, outerScale);
            draw(small(29), x, y, 0, innerScale, innerScale);
            static constexpr std::array<int, 5> kLeafOffset{{
                0, 0x3333, 0x6666, -0x6667, -0x3334,
            }};
            const auto queuedLeafAngle = normalizeAngle16(
                static_cast<int>(enemy.secondaryAngle16) - 2000);
            for (const int offset : kLeafOffset) {
                draw(small(31), x, y - 30.0f,
                     normalizeAngle16(static_cast<int>(queuedLeafAngle) + offset),
                     innerScale, innerScale);
            }
        }
        if (enemy.targetable) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 2, x, y, exactLayer);
        }
        break;
    }
    case 0x25: {
        if (exactLayer == 0x23 && !effectSmallFrames_.empty()) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (timer % 4 >= 2) {
                SetDrawBright(255, 128, 0);
            }
            draw(effectSmallFrames_[0], x + 12.0f, y - 32.0f, 0, 0.4, 0.4);
            draw(effectSmallFrames_[0], x - 12.0f, y - 32.0f, 0, 0.4, 0.4);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (exactLayer == 0x23) {
            draw(small(24), x, y, 0);
        }
        drawGauge(2);
        break;
    }
    case 0x26: {
        if (exactLayer == 0x20 && !effectSmallFrames_.empty()) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (timer % 4 >= 2) SetDrawBright(255, 128, 0);
            draw(effectSmallFrames_[0], x + 50.0f, y - 55.0f, 0, 0.8, 0.8);
            draw(effectSmallFrames_[0], x - 50.0f, y - 55.0f, 0, 0.8, 0.8);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (exactLayer == 0x20) {
            draw(medium(50), x + 50.0f, y + 10.0f, 0);
            draw(medium(50), x - 50.0f, y + 10.0f, 0, 1.0, 1.0, true);
            draw(medium(49), x, y, 0);
        }
        drawGauge(1);
        break;
    }
    case 0x27:
    case 0x29: {
        const bool type27 = enemy.spawnType == 0x27;
        const float bob = 5.0f * std::sin(static_cast<float>(timer) * kTau / 48.0f);
        if (exactLayer == 0x22) {
            if ((timer & 1) == 0) {
                draw(medium(type27 ? 52 : 54), x + 70.0f,
                     y + bob - (type27 ? 10.0f : 0.0f), 0);
                draw(medium(type27 ? 52 : 54), x - 70.0f,
                     y + bob - (type27 ? 10.0f : 0.0f), 0, 1.0, 1.0, true);
            }
            draw(medium(type27 ? 51 : 53), x, y, 0);
        }
        drawGauge(1);
        break;
    }
    case 0x28:
        if (exactLayer == 0x22) {
            draw(small(27), x, y, 0, 1.0,
                 1.0 + std::sin(static_cast<double>(timer) * kPi / 16.0) * 0.1);
        }
        break;
    case 0x2a:
        if (exactLayer == 0x22) {
            draw(small(28), x, y, normalizeAngle16(timer * 0x14d));
        }
        break;
    case 0x2b: {
        const float wave0 = 2.0f * std::sin(static_cast<float>(timer) * kTau / 38.0f);
        const float wave9 = 2.0f * std::sin(static_cast<float>(timer - 9) * kTau / 38.0f);
        const float wave18 = 2.0f * std::sin(static_cast<float>(timer - 18) * kTau / 38.0f);
        const int rotA = static_cast<int>(std::sin(static_cast<double>(timer) * kTau / 9.0) * 3800.0);
        const int rotB = static_cast<int>(std::sin(static_cast<double>(timer - 4) * kTau / 9.0) * 3800.0);
        if (exactLayer == 0x1e) {
            draw(large(10), x + 10.0f, y - 40.0f + wave9, normalizeAngle16(rotB));
            draw(large(10), x - 10.0f, y - 40.0f + wave9, normalizeAngle16(-rotB), 1.0, 1.0, true);
            draw(large(9), x + 10.0f, y - 45.0f + wave9, normalizeAngle16(rotA));
            draw(large(9), x - 10.0f, y - 45.0f + wave9, normalizeAngle16(-rotA), 1.0, 1.0, true);
            draw(medium(57), x, y + 50.0f + wave18, 0);
            draw(medium(56), x, y + wave9, 0, 1.0, 1.0, true);
            draw(medium(55), x, y - 70.0f + wave0, 0);
        }
        drawGauge(1);
        if (enemy.targetable) {
            // FUN_14008d230 deliberately calls the shared gauge helper twice
            // while +0x54 is clear.
            drawGauge(1);
        }
        break;
    }
    case 0x2c: {
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        if (exactLayer == 0x18) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            draw(small(25), x + 8.0f, y + 5.0f, enemy.sourceAngle16);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (exactLayer == 0x19) {
            draw(small(25), x, y, enemy.sourceAngle16);
            draw(small(26), x + static_cast<float>(std::cos(radians) * 35.0),
                 y + static_cast<float>(std::sin(radians) * 35.0), enemy.sourceAngle16);
        }
        drawGauge(2);
        break;
    }
    case 0x2d: {
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        if (exactLayer == 0x18) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            draw(medium(58), x + 16.0f, y + 10.0f, enemy.sourceAngle16);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if (exactLayer == 0x1a) {
            draw(medium(58), x, y, enemy.sourceAngle16);
            draw(medium(59), x + static_cast<float>(std::cos(radians) * 100.0),
                 y + static_cast<float>(std::sin(radians) * 100.0), enemy.sourceAngle16);
        }
        drawGauge(1);
        break;
    }
    case 0x2e: {
        const float wave = 3.0f * std::sin(static_cast<float>(frame_) * kTau / 68.0f) - 24.0f;
        if (exactLayer == 0x20) {
            draw(large(12), x + 180.0f, y + 80.0f + wave, 0);
            draw(large(12), x - 180.0f, y + 80.0f + wave, 0, 1.0, 1.0, true);
            draw(large(11), x, y + 80.0f, 0);
        }
        break;
    }
    case 0x2f: {
        const StageEnemy* parent = nullptr;
        for (const auto& candidate : enemies_) {
            if (candidate.entityId == enemy.parentEntityId) {
                parent = &candidate;
                break;
            }
        }
        if (parent != nullptr && exactLayer == 0x21) {
            const float anchorX = screenX(parent->x + enemy.originX);
            const float anchorY = screenY(parent->y + enemy.originY);
            const auto angle = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(y - anchorY), static_cast<double>(x - anchorX)));
            draw(medium(61), anchorX, anchorY, normalizeAngle16(static_cast<int>(angle) - 0x4000));
            draw(medium(61), (anchorX + x) * 0.5f, (anchorY + y) * 0.5f,
                 normalizeAngle16(static_cast<int>(angle) - 0x4000));
        }
        if (exactLayer == 0x22) {
            draw(medium(60), x, y, 0);
        }
        if (enemy.targetable) {
            drawGauge(0);
        }
        break;
    }
    default:
        break;
    }
    return true;
}

bool StageRuntime::drawStage04BossExact(const StageEnemy& enemy, float x,
                                        float y, int exactLayer) const {
    const bool root = enemy.spawnType == 0x13b;
    const bool child = enemy.spawnType >= 0x40 && enemy.spawnType <= 0x43 &&
                       enemy.parentSpawnType == 0x13b;
    if (!root && !child) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const auto small = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto medium = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto large = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyLargeFrames_.size())
                   ? enemyLargeFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto boss = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(bossFrames_.size())
                   ? bossFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto draw = [this](int handle, float drawX, float drawY,
                             std::uint16_t angle = 0, double scaleX = 1.0,
                             double scaleY = 1.0) {
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle,
                                  scaleX, scaleY, false);
        }
    };

    const int state = enemy.drawHelperState;
    const int timer = enemy.drawHelperTimer;
    if (root) {
        const auto drawLargePair = [&](double scale0, double scale1,
                                       int brightness, int alpha) {
            SetDrawBright(brightness, brightness, brightness);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
            if (exactLayer == 0x1e) {
                draw(large(19), x, y, 0, scale0, scale0);
            }
            if (exactLayer == 0x1b) {
                draw(large(20), x, y, 0, scale1, scale1);
            }
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        };
        const auto secondLayerPulse = [](double scale, int frame) {
            const int phase = frame % 40;
            return phase < 11
                       ? scale - scale * 0.1 *
                             std::sin(static_cast<double>(phase) * kPi / 10.0)
                       : scale;
        };

        if (state == 0) {
            const double scale = timer < 180
                                     ? 0.3 + 0.7 * std::sin(
                                           static_cast<double>(timer) * kPi / 360.0)
                                     : 0.3;
            int brightness = 0;
            int alpha = 255;
            if (timer < 60) {
                alpha = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(timer) * kPi / 120.0));
            }
            else if (timer < 180) {
                brightness = static_cast<int>(255.0 * std::sin(
                    static_cast<double>(timer - 60) * kPi / 240.0));
            }
            drawLargePair(scale, secondLayerPulse(scale, frame_), brightness, alpha);
            return true;
        }
        if (state == 1) {
            drawLargePair(1.0, secondLayerPulse(1.0, frame_), 255, 255);
            return true;
        }
        if (state == 2 && timer < 130) {
            const double scale0 = 1.0 + 0.1 * std::sin(
                static_cast<double>(frame_) * kTau / 21.0);
            const double scale1 = 1.0 - 0.2 * std::sin(
                static_cast<double>(frame_ % 5) * kPi / 5.0);
            drawLargePair(scale0, scale1, 255, 255);
            return true;
        }

        int bossFrame = -1;
        double scale = 1.0;
        if ((state == 2 && timer >= 130) || state == 3 ||
            state == 5 || state == 7) {
            bossFrame = 25 + (timer / 7) % 3;
        }
        else if (state == 4 || state == 9) {
            const int duration = state == 4 ? 60 : 40;
            if (timer >= duration) {
                bossFrame = 25;
            }
            else {
                const bool moveRight = enemy.markerDrawX > enemy.originX;
                if (timer < 10) {
                    bossFrame = (moveRight ? 28 : 33) + (timer / 5) % 2;
                }
                else if (timer < duration - 10) {
                    bossFrame = (moveRight ? 30 : 35) +
                                ((timer - 10) / 5) % 3;
                }
                else {
                    bossFrame = (moveRight ? 29 : 34) -
                                (timer - (duration - 10)) / 5;
                }
            }
        }
        else if (state == 6 || state == 8) {
            bossFrame = 38 + (timer / 5) % 2;
            scale = 1.0 - 0.3 * std::sin(
                static_cast<double>(timer) * kPi / 180.0);
        }
        else if (state == 10) {
            const int phase = timer % 364;
            if (phase < 15) {
                static constexpr std::array<int, 3> kFrames{{26, 33, 34}};
                bossFrame = kFrames[static_cast<std::size_t>(phase / 5)];
            }
            else if (phase < 167) {
                bossFrame = 35 + ((phase - 15) / 5) % 3;
            }
            else if (phase < 197) {
                static constexpr std::array<int, 6> kFrames{{
                    34, 33, 25, 26, 28, 29,
                }};
                bossFrame = kFrames[static_cast<std::size_t>((phase - 167) / 5)];
            }
            else if (phase < 349) {
                bossFrame = 30 + ((phase - 197) / 5) % 3;
            }
            else {
                static constexpr std::array<int, 3> kFrames{{29, 28, 25}};
                bossFrame = kFrames[static_cast<std::size_t>((phase - 349) / 5)];
            }
        }
        else if (state == 11 && timer < 240) {
            bossFrame = 38 + (timer / 5) % 2;
        }
        if (exactLayer == 0x1e) {
            draw(boss(bossFrame), x, y, 0, scale, scale);
        }
        return true;
    }

    if (enemy.spawnType == 0x40) {
        const StageEnemy* parent = nullptr;
        for (const auto& candidate : enemies_) {
            if (candidate.entityId == enemy.parentEntityId) {
                parent = &candidate;
                break;
            }
        }
        static constexpr std::array<float, 6> kChainX{{
            50.0f, -50.0f, 100.0f, -100.0f, 140.0f, -140.0f,
        }};
        static constexpr std::array<float, 6> kChainY{{
            150.0f, 150.0f, 140.0f, 140.0f, 120.0f, 120.0f,
        }};
        if (parent != nullptr && exactLayer == 0x1c) {
            const int index = std::clamp(enemy.childIndex, 0, 5);
            const float anchorX = parent->x + kChainX[static_cast<std::size_t>(index)];
            const float anchorY = parent->y + kChainY[static_cast<std::size_t>(index)];
            for (int segment = 0; segment < 20; ++segment) {
                if (state == -1 && timer > 60 - segment * 3) {
                    continue;
                }
                double segmentScale = 1.0;
                if (state == 0) {
                    const int start = segment * 2;
                    if (timer < start) {
                        segmentScale = 0.0;
                    }
                    else if (timer < start + 8) {
                        segmentScale = std::sin(
                            static_cast<double>(timer - start) * kPi / 16.0);
                    }
                }
                const float fraction = static_cast<float>(segment) / 20.0f;
                const float localX = anchorX + (enemy.x - anchorX) * fraction +
                    4.0f * std::sin(static_cast<double>(frame_ - segment * 7) *
                                    kTau / 80.0);
                const float localY = anchorY + (enemy.y - anchorY) * fraction;
                draw(small(43), screenX(localX), screenY(localY),
                     enemy.sourceAngle16, segmentScale, segmentScale);
            }
        }

        if (state != -1 && exactLayer == 0x23) {
            double bodyScale = 1.0;
            if (state == 0) {
                if (timer < 40) {
                    bodyScale = 0.0;
                }
                else if (timer < 48) {
                    bodyScale = std::sin(
                        static_cast<double>(timer - 40) * kPi / 16.0);
                }
            }
            else if ((state == 5 || state == 8) && timer < 9) {
                bodyScale = 1.0 + 0.4 * std::sin(
                    static_cast<double>(timer) * kPi / 8.0);
            }
            draw(medium(75), x, y, enemy.sourceAngle16,
                 bodyScale, bodyScale);
            if ((state == 4 || state == 7) && timer % 4 < 2) {
                draw(medium(75), x, y, enemy.sourceAngle16,
                     bodyScale, bodyScale);
            }
        }
        if (enemy.targetable) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 80.0f,
                                exactLayer);
        }
        return true;
    }

    const StageEnemy* parent = nullptr;
    for (const auto& candidate : enemies_) {
        if (candidate.entityId == enemy.parentEntityId) {
            parent = &candidate;
            break;
        }
    }
    const int parentTimer = parent == nullptr ? 0 : parent->helperTimer;
    double entryScale = 1.0;
    if (state == 0) {
        entryScale = std::sin(static_cast<double>(timer) * kPi / 100.0);
    }
    if (enemy.spawnType == 0x41) {
        const int bodyLayer = enemy.secondaryAngle16 > 0x8000 ? 0x1c : 0x1f;
        if (exactLayer != bodyLayer) {
            return true;
        }
        const double base = entryScale *
            (0.9 + 0.1 * std::sin(fixedAngleToRadiansDouble(
                                enemy.secondaryAngle16)));
        const double pulse0 = base * (1.0 + 0.1 * std::sin(
            static_cast<double>(parentTimer) * kPi / 22.0));
        const double pulse10 = base * (1.0 + 0.1 * std::sin(
            static_cast<double>(parentTimer - 10) * kPi / 22.0));
        draw(small(44), x, y, 0, pulse10, base);
        draw(small(45), x, y, 0, pulse0, base);
        return true;
    }

    const double pulse0 = entryScale * (1.0 + 0.1 * std::sin(
        static_cast<double>(parentTimer) * kPi / 33.0));
    const double pulse12 = entryScale * (1.0 + 0.1 * std::sin(
        static_cast<double>(parentTimer - 12) * kPi / 33.0));
    const double headingRadians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
    if (exactLayer == 0x23) {
        draw(medium(77),
             x + static_cast<float>(std::cos(headingRadians) * 30.0 * entryScale),
             y + static_cast<float>(std::sin(headingRadians) * 30.0 * entryScale),
             enemy.sourceAngle16, entryScale, pulse12);
        draw(medium(76), x, y, 0, entryScale, pulse0);
    }
    return true;
}

bool StageRuntime::drawStage04EnemyExact(const StageEnemy& enemy, float x, float y,
                                         int exactLayer) const {
    const auto drawGauge = [this, &enemy, exactLayer](int mode, float drawX,
                                                       float drawY) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, mode, drawX, drawY, exactLayer);
    };
    if (enemy.spawnType == 0x3f) {
        const int smallBody = enemySmallFrames_.size() > 42 ? enemySmallFrames_[42] : -1;
        const int sideBody = enemyMediumFrames_.size() > 74 ? enemyMediumFrames_[74] : -1;
        const int centerBody = enemyLargeFrames_.size() > 18 ? enemyLargeFrames_[18] : -1;

        constexpr double kTauDouble = 6.28318530717958647692;
        const double chainPhase = static_cast<double>(frame_) * kTauDouble / 136.0;
        const double chainSin = std::sin(chainPhase);
        const double chainCos = std::cos(chainPhase);
        if (smallBody != -1 && exactLayer == 0x20) {
            const int spinUnit = static_cast<int>(chainSin * 444.0);
            for (int i = 0; i < 11; ++i) {
                const double distance = static_cast<double>(i) * 25.0;
                drawOriginalMode7Node(
                    smallBody,
                    x + static_cast<float>(chainCos * distance),
                    y - 100.0f + static_cast<float>(chainSin * distance),
                    normalizeAngle16(spinUnit * (i + 1) - 0x4000),
                    1.0 - static_cast<double>(i) * 0.05,
                    1.0 - static_cast<double>(i) * 0.05,
                    false);
            }
        }

        const double pulse = std::sin(static_cast<double>(frame_) * kTauDouble / 120.0) * 0.05 + 1.0;
        const int sideAngle = static_cast<int>(
            std::sin(static_cast<double>(frame_) * kTauDouble / 66.0) * 777.0);
        if (sideBody != -1 && exactLayer == 0x20) {
            drawOriginalMode7Node(sideBody, x + static_cast<float>(pulse * 60.0), y + 230.0f,
                                  normalizeAngle16(sideAngle), 1.0, 1.0, false);
            drawOriginalMode7Node(sideBody, x - static_cast<float>(pulse * 60.0), y + 230.0f,
                                  normalizeAngle16(-sideAngle), 1.0, 1.0, true);
        }
        if (centerBody != -1 && exactLayer == 0x20) {
            drawOriginalMode7Node(centerBody, x, y + 70.0f, 0, pulse, pulse, false);
        }

        if (exactLayer == 0x32 && enemy.drawHp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.drawHp) / static_cast<double>(enemy.maxHp);
            const int gauge = enemyGaugeFrames_.empty() ? -1 : enemyGaugeFrames_[0];
            int red = 0;
            int green = 255;
            int blue = static_cast<int>((ratio - 0.5) * 511.0);
            if (ratio <= 0.5) {
                red = static_cast<int>(255.0 - ratio * 511.0);
                green = static_cast<int>(ratio * 511.0);
                blue = 0;
            }
            red = std::clamp(red, 0, 255);
            green = std::clamp(green, 0, 255);
            blue = std::clamp(blue, 0, 255);

            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (gauge != -1) {
                DrawRotaGraphF(x, y - 40.0f, 1.0, 0.0, gauge, TRUE);
            }
            if (enemyGaugeFillHandle_ != -1) {
                SetDrawBright(red, green, blue);
                DrawRotaGraph3F(x - 120.0f, y - 45.0f, 0.0f, 0.0f,
                                ratio, 1.0, 0.0, enemyGaugeFillHandle_, TRUE);
                SetDrawBright(255, 255, 255);
            }
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return true;
    }

    if (enemy.spawnType == 0x3d || enemy.spawnType == 0x3e) {
        const auto mediumHandle = [this](int frame) {
            return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                       ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                       : -1;
        };

        if (enemy.spawnType == 0x3e) {
            const int childBody = mediumHandle(72);
            if (exactLayer == 0x1e && enemy.drawBodyThisFrame &&
                childBody != -1) {
                drawOriginalMode7Node(childBody, x, y, enemy.sourceAngle16,
                                      1.0, 1.0, false);
            }
            return true;
        }

        if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            if (marker != -1) {
                const double markerScale = 4.0 - static_cast<double>(enemy.markerDrawTimer) * 0.2;
                DrawRotaGraphF(screenX(enemy.markerDrawX), screenY(enemy.markerDrawY),
                               markerScale, 0.0, marker, TRUE);
            }
        }

        if (!enemy.drawBodyThisFrame) {
            return true;
        }

        const bool entryFromLeft = enemy.originX < 360.0f;
        const float sideX = x + (entryFromLeft ? -205.0f : 205.0f);
        const float sideY = y + 12.0f;
        constexpr double kPiDouble = 3.14159265358979323846;
        const double sideScale = std::sin(static_cast<double>(enemy.drawHelperTimer) *
                                          (2.0 * kPiDouble / 19.0));
        const int sideBody = mediumHandle(73);
        if (sideBody != -1 && exactLayer == 0x1e) {
            drawOriginalMode7Node(sideBody, sideX, sideY, 0xc000,
                                  sideScale, 1.0, true);
            drawOriginalMode7Node(sideBody, sideX, sideY, 0xc000,
                                  -sideScale, 1.0, true);
        }

        const int centerBody = enemyLargeFrames_.size() > 17 ? enemyLargeFrames_[17] : -1;
        if (centerBody != -1 && exactLayer == 0x1e) {
            drawOriginalMode7Node(centerBody, x, y, 0, 1.0, 1.0, entryFromLeft);
        }

        if (exactLayer == 0x32 && enemy.drawHp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.drawHp) / static_cast<double>(enemy.maxHp);
            const int gauge = enemyGaugeFrames_.empty() ? -1 : enemyGaugeFrames_[0];
            int red = 0;
            int green = 255;
            int blue = static_cast<int>((ratio - 0.5) * 511.0);
            if (ratio <= 0.5) {
                red = static_cast<int>(255.0 - ratio * 511.0);
                green = static_cast<int>(ratio * 511.0);
                blue = 0;
            }
            red = std::clamp(red, 0, 255);
            green = std::clamp(green, 0, 255);
            blue = std::clamp(blue, 0, 255);

            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (gauge != -1) {
                DrawRotaGraphF(x, y - 150.0f, 1.0, 0.0, gauge, TRUE);
            }
            if (enemyGaugeFillHandle_ != -1) {
                SetDrawBright(red, green, blue);
                DrawRotaGraph3F(x - 120.0f, y - 155.0f, 0.0f, 0.0f,
                                ratio, 1.0, 0.0, enemyGaugeFillHandle_, TRUE);
                SetDrawBright(255, 255, 255);
            }
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return true;
    }

    if (enemy.spawnType == 0x38) {
        if (enemy.helperState == 0) {
            const float horizontalOrigin = player_.x / 6.0f;
            const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                                     horizontalOrigin + 650.0f));
            const float markerY = screenY(clampFloat(enemy.y, -50.0f, 770.0f));
            const double markerScale = std::max(0.0, 3.0 - enemy.drawHelperTimer * 0.15);
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            if (marker != -1 && exactLayer == 0x32) {
                drawOriginalMode7Node(marker, markerX, markerY, 0, markerScale, markerScale, false);
            }
            return true;
        }

        const auto drawMedium = [&](int frame, float drawX, float drawY,
                                    std::uint16_t angle, bool reverseX) {
            if (frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())) {
                const int graph = enemyMediumFrames_[static_cast<std::size_t>(frame)];
                if (graph != -1) {
                    drawOriginalMode7Node(graph, drawX, drawY, angle, 1.0, 1.0, reverseX);
                }
            }
        };
        const int timer = enemy.drawHelperTimer;
        const float rearWave = static_cast<float>(2.0 * std::sin(timer * kTau / 63.0f)) - 8.0f;
        const float bodyWave = static_cast<float>(2.0 * std::sin((timer - 23) * kTau / 63.0f));
        const int rot65 = static_cast<int>(std::sin(timer * kTau / 50.0f) * 1500.0f);
        const int rot66 = static_cast<int>(std::sin((timer - 25) * kTau / 50.0f) * 1500.0f);
        if (exactLayer == 0x20) {
            drawMedium(66, x + 30.0f, y + bodyWave, normalizeAngle16(rot66), false);
            drawMedium(66, x - 30.0f, y + bodyWave, normalizeAngle16(-rot66), true);
            drawMedium(65, x + 25.0f, y + bodyWave + 80.0f, normalizeAngle16(rot65), false);
            drawMedium(65, x - 25.0f, y + bodyWave + 80.0f, normalizeAngle16(-rot65), true);
            drawMedium(64, x, y + bodyWave, 0, false);
            drawMedium(63, x, y + rearWave, 0, false);
        }

        if (exactLayer == 0x32 && enemy.drawHp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.drawHp) / static_cast<double>(enemy.maxHp);
            const int gauge = enemyGaugeFrames_.size() > 1 ? enemyGaugeFrames_[1] : -1;
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (gauge != -1) {
                DrawRotaGraphF(x, y - 120.0f, 1.0, 0.0, gauge, TRUE);
            }
            int red = 0;
            int green = 255;
            int blue = static_cast<int>((ratio - 0.5) * 511.0);
            if (ratio <= 0.5) {
                red = static_cast<int>(255.0 - ratio * 511.0);
                green = static_cast<int>(ratio * 511.0);
                blue = 0;
            }
            red = std::clamp(red, 0, 255);
            green = std::clamp(green, 0, 255);
            blue = std::clamp(blue, 0, 255);
            const int fillWidth = std::max(0, static_cast<int>(ratio * 120.0));
            if (fillWidth > 0) {
                DrawBox(static_cast<int>(x - 60.0f), static_cast<int>(y - 125.0f),
                        static_cast<int>(x - 60.0f) + fillWidth, static_cast<int>(y - 115.0f),
                        GetColor(red, green, blue), TRUE);
            }
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        return true;
    }

    if (isStage04CarrierFamily(enemy.spawnType)) {
        const auto mediumHandle = [this](int frame) {
            return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                       ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                       : -1;
        };
        const auto drawMedium = [&](int frame, float drawX, float drawY, std::uint16_t angle,
                                    double scaleX, double scaleY, bool reverseX) {
            const int graph = mediumHandle(frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle, scaleX, scaleY, reverseX);
            }
        };

        const int drawTimer = enemy.drawHelperTimer;
        const double pulse = std::sin(static_cast<double>(drawTimer) * 474.8985507246377 *
                                      static_cast<double>(kPi) / 32768.0) * 0.1 + 1.0;
        if (enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) {
            if (enemy.helperState == 0) {
                const double markerScale = std::max(0.0, 3.0 - drawTimer * 0.15);
                const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
                const float horizontalOrigin = player_.x / 6.0f;
                const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                                         horizontalOrigin + 650.0f));
                const float markerY = screenY(clampFloat(enemy.y, -50.0f, 770.0f));
                if (marker != -1 && exactLayer == 0x32) {
                    drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                          markerScale, markerScale, false);
                }
                else if (exactLayer == 0x32) {
                    drawMedium(68, markerX, markerY, enemy.sourceAngle16, markerScale, markerScale, false);
                }
                return true;
            }
            if (!enemy.drawBodyThisFrame) {
                return true;
            }

            if (exactLayer != 0x1d) {
                return true;
            }
            const int spin = static_cast<int>(std::sin(static_cast<double>(drawTimer) *
                                                       590.4144144144144 * static_cast<double>(kPi) /
                                                       32768.0) * 2400.0);
            const std::uint16_t positive = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + spin);
            const std::uint16_t negative = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) - spin);
            const float positiveRadians = fixedAngleToRadians(positive);
            const float negativeRadians = fixedAngleToRadians(negative);
            drawMedium(69, x + std::cos(positiveRadians) * 40.0f,
                       y + std::sin(positiveRadians) * 40.0f,
                       normalizeAngle16(static_cast<int>(positive) + 0x4000), 1.0, pulse, false);
            drawMedium(69, x + std::cos(negativeRadians) * 40.0f,
                       y + std::sin(negativeRadians) * 40.0f,
                       normalizeAngle16(static_cast<int>(negative) + 0x4000), 1.0, pulse, true);
            drawMedium(68, x, y, enemy.sourceAngle16, 1.0, pulse, false);
            return true;
        }
        if (enemy.spawnType == 0x3b) {
            if (exactLayer == 0x1c) {
                drawMedium(70, x, y, enemy.sourceAngle16, 1.0, pulse, false);
            }
            return true;
        }

        const float angle = fixedAngleToRadians(enemy.sourceAngle16);
        if (exactLayer == 0x1c) {
            drawMedium(71, x + std::cos(angle) * 45.0f, y + std::sin(angle) * 45.0f,
                       enemy.sourceAngle16, 1.0, pulse, false);
        }
        return true;
    }

    if (enemySmallFrames_.empty() ||
        (enemy.spawnType != 0x35 && enemy.spawnType != 0x36 && enemy.spawnType != 0x37)) {
        return false;
    }
    const auto handleFor = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemySmallFrames_.size())
                   ? enemySmallFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto draw = [&](int frame, float drawX, float drawY, double scale, std::uint16_t angle) {
        const int graph = handleFor(frame);
        if (graph != -1) {
            DrawRotaGraphF(drawX, drawY, scale, fixedAngleToRadians(angle), graph, TRUE);
        }
    };
    const auto drawScaled = [&](int frame, float drawX, float drawY,
                                double scaleX, double scaleY,
                                std::uint16_t angle, bool reverseX = false) {
        const int graph = handleFor(frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scaleX, scaleY, reverseX);
        }
    };

    if (enemy.spawnType == 0x35) {
        if (enemy.helperState == 0) {
            const double markerScale = std::max(0.0, 2.0 - enemy.drawHelperTimer * 0.1);
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            const float horizontalOrigin = player_.x / 6.0f;
            const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                                     horizontalOrigin + 620.0f));
            const float markerY = screenY(clampFloat(enemy.y, -20.0f, 740.0f));
            if (marker != -1 && exactLayer == 0x32) {
                drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                      markerScale, markerScale, false);
            }
            else if (exactLayer == 0x32) {
                draw(32, markerX, markerY, markerScale, enemy.sourceAngle16);
            }
            return true;
        }
        if (exactLayer == 0x23) {
            draw(32, x, y, 1.0, 0);
            const std::uint16_t base = normalizeAngle16(enemy.drawHelperTimer * 2000);
            draw(33, x, y - 35.0f, 1.0, base);
            draw(33, x, y - 35.0f, 1.0, normalizeAngle16(static_cast<int>(base) + 0x5555));
            draw(33, x, y - 35.0f, 1.0, normalizeAngle16(static_cast<int>(base) - 0x5556));
        }
        drawGauge(2, x, y);
        return true;
    }

    if (enemy.spawnType == 0x36) {
        if (enemy.helperState == 0) {
            const double markerScale = std::max(0.0, 2.0 - enemy.drawHelperTimer * 0.1);
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            const float horizontalOrigin = player_.x / 6.0f;
            const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 20.0f,
                                                     horizontalOrigin + 620.0f));
            const float markerY = screenY(clampFloat(enemy.y, -20.0f, 740.0f));
            if (marker != -1 && exactLayer == 0x32) {
                drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                      markerScale, markerScale, false);
            }
            else if (exactLayer == 0x32) {
                draw(34, markerX, markerY, markerScale, enemy.sourceAngle16);
            }
            return true;
        }
        const int timer = enemy.drawHelperTimer;
        int bodyFrame = 34;
        if (enemy.drawHelperState == 1 && timer > 79) {
            bodyFrame = 37;
        }
        else if (enemy.drawHelperState == 1 && timer > 69) {
            bodyFrame = 35 + ((timer - 70) / 5);
        }
        const double heading = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        const double bodyPulse = 1.0 + 0.1 * std::sin(
            static_cast<double>(timer) * kTau / 47.0);
        const int sideSpin = static_cast<int>(6000.0 * std::sin(
            static_cast<double>(timer) * kTau / 72.0));
        const auto positiveSide = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) + 0x4000);
        const auto negativeSide = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) - 0x4000);
        if (exactLayer == 0x23) {
        drawScaled(39,
                   x + static_cast<float>(std::cos(fixedAngleToRadiansDouble(positiveSide)) * 10.0),
                   y + static_cast<float>(std::sin(fixedAngleToRadiansDouble(positiveSide)) * 10.0),
                   1.0, 1.0,
                   normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + sideSpin + 0x4000));
        drawScaled(39,
                   x + static_cast<float>(std::cos(fixedAngleToRadiansDouble(negativeSide)) * 10.0),
                   y + static_cast<float>(std::sin(fixedAngleToRadiansDouble(negativeSide)) * 10.0),
                   1.0, 1.0,
                   normalizeAngle16(static_cast<int>(enemy.sourceAngle16) - sideSpin + 0x4000), true);
        drawScaled(38,
                   x - static_cast<float>(std::cos(heading) * 15.0),
                   y - static_cast<float>(std::sin(heading) * 15.0),
                   1.0, bodyPulse, enemy.sourceAngle16);
        drawScaled(bodyFrame,
                   x + static_cast<float>(std::cos(heading) * 20.0),
                   y + static_cast<float>(std::sin(heading) * 20.0),
                   1.0, bodyPulse, enemy.sourceAngle16);
        }
        if (enemy.targetable) {
            drawGauge(2, x, y);
        }
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    const double scale = enemy.drawHelperState == 0
                             ? std::max(0.0, std::min(1.0, enemy.drawHelperTimer / 120.0))
                             : 1.0;
    const double pulsePhase = std::sin(
        static_cast<double>(timer % 30) * kPi / 60.0);
    const double scaleX = scale * (0.9 + pulsePhase * 0.3);
    const double scaleY = scale * (1.2 - pulsePhase * 0.3);
    const double visualHeading = fixedAngleToRadiansDouble(enemy.secondaryAngle16);
    const int bodyLayer = enemy.drawHelperState == 0 ? 0x0c : 0x23;
    if (exactLayer == bodyLayer && enemy.drawHelperState == 0) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,
                         std::clamp(static_cast<int>(timer * 2.125), 0, 255));
    }
    if (exactLayer == bodyLayer) {
    drawScaled(41,
               x - static_cast<float>(std::cos(visualHeading) * 40.0 * scale),
               y - static_cast<float>(std::sin(visualHeading) * 40.0 * scale),
               scaleX, scaleY, enemy.secondaryAngle16);
    drawScaled(40, x, y, scale, scaleY, enemy.secondaryAngle16);
    }
    if (exactLayer == bodyLayer && enemy.drawHelperState == 0) {
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (enemy.targetable) {
        drawGauge(2, x, y);
    }
    return true;
}

bool StageRuntime::drawStage01Type0EExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x0e) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                  screenY(enemy.markerDrawY), 0,
                                  scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 120.0f, exactLayer);
        return true;
    }
    if (exactLayer != 0x20) {
        return true;
    }

    const auto mediumHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto drawMedium = [&](int frame, float drawX, float drawY,
                                std::uint16_t angle16, bool reverseX) {
        const int handle = mediumHandle(frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle16,
                                  1.0, 1.0, reverseX);
        }
    };

    constexpr double kOriginalPi = 3.14159265358979;
    constexpr double kBodyWave = 2.0 * kOriginalPi / 63.0;
    constexpr double kMountWave = 2.0 * kOriginalPi / 36.0;
    const int timer = enemy.drawHelperTimer;
    const float frontY = static_cast<float>(
        2.0 * std::sin(static_cast<double>(timer) * kBodyWave) - 24.0);
    const float middleY = static_cast<float>(
        2.0 * std::sin(static_cast<double>(timer - 23) * kBodyWave));
    const float rearY = static_cast<float>(
        2.0 * std::sin(static_cast<double>(timer - 46) * kBodyWave));
    const int bodyAngle = static_cast<int>(
        std::sin(static_cast<double>(timer) * kBodyWave) * 2400.0);
    const int innerAngle = static_cast<int>(
        std::sin(static_cast<double>(timer) * kMountWave) * 2000.0);
    const int outerAngle = static_cast<int>(
        std::sin(static_cast<double>(timer - 3) * kMountWave) * 2000.0) + 10000;

    const double innerRadians = fixedAngleToRadiansDouble(normalizeAngle16(innerAngle));
    const float innerX = static_cast<float>(std::cos(innerRadians) * 85.0);
    const float innerY = static_cast<float>(std::sin(innerRadians) * 85.0);
    const double outerRadians = fixedAngleToRadiansDouble(normalizeAngle16(outerAngle));
    const float outerX = static_cast<float>(std::cos(outerRadians) * 70.0);
    const float outerY = static_cast<float>(std::sin(outerRadians) * 70.0);

    drawMedium(21, x + outerX, y + middleY + outerY,
               normalizeAngle16(outerAngle), false);
    drawMedium(21, x - outerX, y + middleY + outerY,
               normalizeAngle16(-outerAngle), true);
    drawMedium(20, x + innerX, y + middleY + innerY,
               normalizeAngle16(innerAngle), false);
    drawMedium(20, x - innerX, y + middleY + innerY,
               normalizeAngle16(-innerAngle), true);
    drawMedium(19, x, y + rearY, 0, false);
    drawMedium(18, x, y + middleY, 0, false);
    drawMedium(17, x + 45.0f, y + frontY - 60.0f,
               normalizeAngle16(bodyAngle - 1000), false);
    drawMedium(17, x - 45.0f, y + frontY - 60.0f,
               normalizeAngle16(1000 - bodyAngle), true);
    drawMedium(16, x, y + frontY, 0, false);

    return true;
}

bool StageRuntime::drawStage01Type0FExact(const StageEnemy& enemy, float x, float y,
                                          int exactLayer) const {
    if (enemy.spawnType != 0x0f) {
        return false;
    }

    if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                  screenY(enemy.markerDrawY), 0,
                                  scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (exactLayer == 0x32) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 120.0f, exactLayer);
        return true;
    }
    if (exactLayer != 0x20) {
        return true;
    }

    const auto mediumHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto drawMedium = [&](int frame, float drawX, float drawY,
                                std::uint16_t angle16, bool reverseX) {
        const int handle = mediumHandle(frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle16,
                                  1.0, 1.0, reverseX);
        }
    };

    constexpr double kOriginalPi = 3.14159265358979;
    const int timer = enemy.drawHelperTimer;
    const float frontWave = static_cast<float>(
        std::sin(static_cast<double>(timer) * kOriginalPi / 36.0));
    const float middleWave = static_cast<float>(
        std::sin(static_cast<double>(timer - 17) * kOriginalPi / 36.0));
    const float rearWave = static_cast<float>(
        std::sin(static_cast<double>(timer - 34) * kOriginalPi / 36.0));
    const auto mountAngle = normalizeAngle16(static_cast<int>(
        std::sin(static_cast<double>(timer) * kOriginalPi / 50.0) * 2000.0));
    const double mountRadians = fixedAngleToRadiansDouble(mountAngle);
    const float mountX = static_cast<float>(std::cos(mountRadians) * 95.0);
    const float mountY = static_cast<float>(std::sin(mountRadians) * 95.0);

    drawMedium(25, x + mountX + 10.0f, y + middleWave + mountY - 15.0f,
               mountAngle, false);
    drawMedium(25, x - mountX - 10.0f, y + middleWave + mountY - 15.0f,
               normalizeAngle16(-static_cast<int>(mountAngle)), true);
    drawMedium(24, x, y + rearWave, 0, false);
    drawMedium(23, x, y + middleWave, 0, false);
    drawMedium(22, x, y + frontWave, 0, false);

    return true;
}

bool StageRuntime::drawStage01Type10Or11Exact(const StageEnemy& enemy, float x,
                                              float y, int exactLayer) const {
    if (enemy.spawnType != 0x10 && enemy.spawnType != 0x11) {
        return false;
    }

    const auto mediumHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto drawMedium = [&](int frame, float drawX, float drawY,
                                std::uint16_t angle16, bool reverseX = false) {
        const int handle = mediumHandle(frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle16,
                                  1.0, 1.0, reverseX);
        }
    };

    constexpr double kOriginalPi = 3.14159265358979323846;
    if (enemy.spawnType == 0x10) {
        if (!enemy.drawBodyThisFrame) {
            return true;
        }
        if (exactLayer == 0x32) {
            if (enemy.targetable) {
                StageEnemy gaugeSnapshot = enemy;
                gaugeSnapshot.hp = enemy.drawHp;
                drawEnemyGaugeExact(gaugeSnapshot, 0, x, y - 160.0f,
                                    exactLayer);
            }
            return true;
        }
        if (exactLayer != 0x20) {
            return true;
        }

        // FUN_140080fb0 @ 0x140081cb3..0x140081fcf queues Enemy_m
        // frames 29, 28, 27x2, 26, 30 and 31 in this order. All four waves
        // use DAT_14053a8d8 (65536/68) against the global stage frame.
        const double phase = kOriginalPi / 34.0;
        const float wave0 = static_cast<float>(
            std::sin(static_cast<double>(frame_) * phase));
        const float wave21 = static_cast<float>(
            std::sin(static_cast<double>(frame_ - 21) * phase));
        const float wave42 = static_cast<float>(
            std::sin(static_cast<double>(frame_ - 42) * phase));
        const float wave30 = static_cast<float>(
            std::sin(static_cast<double>(frame_ - 30) * phase));
        const int armWobble = static_cast<int>(wave30 * 2400.0f);

        drawMedium(29, x, y + wave42 * 3.0f + 100.0f, 0);
        drawMedium(28, x, y + wave21 * 3.0f + 50.0f, 0);
        drawMedium(27, x + 40.0f, y + wave0 * 3.0f - 124.0f,
                   normalizeAngle16(armWobble + 10000));
        drawMedium(27, x - 40.0f, y + wave0 * 3.0f - 124.0f,
                   normalizeAngle16(-10000 - armWobble), true);
        drawMedium(26, x, y + wave0 * 3.0f - 94.0f, 0);
        drawMedium(30, x - 105.0f, y + wave30 * 4.0f - 40.0f, 4000);
        drawMedium(31, x + 90.0f, y + wave30 * 4.0f + 40.0f, 0);

        return true;
    }

    // FUN_140082090 rotates both assemblies around the opposite of the
    // current firing angle. Frame 32 is layer 0x20; the three frame-33
    // rotors are layer 0x23 and therefore render in front of it.
    const int timer = enemy.helperState == 0
                          ? std::max(0, enemy.age - 1)
                          : enemy.age;
    const auto oppositeAngle = normalizeAngle16(
        static_cast<int>(enemy.sourceAngle16) + 0x8000);
    const double oppositeRadians = fixedAngleToRadiansDouble(oppositeAngle);
    const float directionX = static_cast<float>(std::cos(oppositeRadians));
    const float directionY = static_cast<float>(std::sin(oppositeRadians));
    const int rotorAngle = timer * 2000;

    if (exactLayer == 0x20) {
        drawMedium(32, x + directionX * 30.0f, y + directionY * 30.0f,
                   enemy.sourceAngle16);
    }
    if (exactLayer == 0x23) {
        drawMedium(33, x + directionX * 125.0f, y + directionY * 125.0f,
                   normalizeAngle16(rotorAngle));
        drawMedium(33, x + directionX * 125.0f, y + directionY * 125.0f,
                   normalizeAngle16(rotorAngle + 0x5555));
        drawMedium(33, x + directionX * 125.0f, y + directionY * 125.0f,
                   normalizeAngle16(rotorAngle - 0x5556));
    }

    if (enemy.targetable) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 110.0f, exactLayer);
    }
    return true;
}

bool StageRuntime::drawStage01MarkerExact(const StageEnemy& enemy, float x,
                                          float y, int exactLayer) const {
    const bool root = enemy.spawnType >= 0x06 && enemy.spawnType <= 0x08;
    const bool satellite = enemy.spawnType == 0x09;
    if (!root && !satellite) {
        return false;
    }

    if (root && enemy.drawMarkerThisFrame && exactLayer == 0x32) {
        const int marker = effectMediumFrames_.size() > 4
                               ? effectMediumFrames_[4]
                               : -1;
        if (marker != -1) {
            const double scale = std::max(
                0.0, 3.0 - static_cast<double>(enemy.markerDrawTimer) * 0.15);
            drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                  screenY(enemy.markerDrawY), 0,
                                  scale, scale, false);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const auto mediumHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    if (satellite) {
        const int bodyLayer =
            static_cast<std::uint16_t>(
                static_cast<int>(enemy.secondaryAngle16) + 0xc000) <= 0x7fff
                ? 0x25
                : 0x27;
        if (exactLayer != bodyLayer) {
            return true;
        }
        const int handle = mediumHandle(11);
        if (handle != -1) {
            const double scale = 1.1 + 0.1 * std::sin(
                static_cast<double>(enemy.drawHelperTimer) *
                static_cast<double>(kPi) / 32.0);
            drawOriginalMode7Node(handle, x, y, 0, scale, scale, false);
        }
        return true;
    }

    if (exactLayer == 0x32) {
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 80.0f, exactLayer);
        return true;
    }
    if (exactLayer != 0x26) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    const double bodyScale = 1.0 + 0.1 * std::sin(
        static_cast<double>(timer) * static_cast<double>(kTau) / 90.0);
    const int outerHandle = mediumHandle(10);
    if (outerHandle != -1) {
        const int baseAngle = timer * 0x6f1;
        drawOriginalMode7Node(outerHandle, x, y + 80.0f,
                              normalizeAngle16(baseAngle), 1.0, 1.0, false);
        drawOriginalMode7Node(outerHandle, x, y + 80.0f,
                              normalizeAngle16(baseAngle + 0x5555),
                              1.0, 1.0, false);
        drawOriginalMode7Node(outerHandle, x, y + 80.0f,
                              normalizeAngle16(baseAngle - 0x5556),
                              1.0, 1.0, false);
    }

    const int middleHandle = mediumHandle(9);
    if (middleHandle != -1) {
        drawOriginalMode7Node(middleHandle, x, y, 0,
                              bodyScale, 1.0, false);
    }

    const int itemHandle = itemFrames_.size() > 11 ? itemFrames_[11] : -1;
    if (itemHandle != -1) {
        double itemScale = 1.0;
        if (timer % 60 < 11) {
            itemScale += 0.1 * std::sin(
                static_cast<double>(timer) * static_cast<double>(kPi) / 10.0);
        }
        for (int index = 0; index < 16; ++index) {
            const auto radialAngle = scriptRandomAngle(
                static_cast<std::uint32_t>(enemy.entityId + 0x4d + index));
            const double radius = scriptRandomHundredth(
                static_cast<std::uint32_t>(enemy.entityId + 0x309 + index),
                15.0, 32.0) * bodyScale;
            const double radians = fixedAngleToRadiansDouble(radialAngle);
            const float itemX = x + static_cast<float>(std::cos(radians) * radius);
            const float itemY = y - 25.0f +
                                static_cast<float>(std::sin(radians) * radius);
            const auto drawAngle = scriptRandomAngle(
                static_cast<std::uint32_t>(enemy.entityId + 0x1e61 + index));
            drawOriginalMode7Node(itemHandle, itemX, itemY, drawAngle,
                                  itemScale, itemScale, false);
        }
    }

    const int coreHandle = mediumHandle(8);
    if (coreHandle != -1) {
        drawOriginalMode7Node(coreHandle, x, y, 0,
                              bodyScale, 1.0, false);
    }
    return true;
}

bool StageRuntime::drawType0AExact(const StageEnemy& enemy, float x, float y,
                                   int exactLayer) const {
    if (enemy.spawnType != 0x0a || enemyMediumFrames_.empty()) {
        return false;
    }

    if (exactLayer == 0x32) {
        if (enemy.targetable) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 80.0f, exactLayer);
        }
        return true;
    }
    const int bodyLayer = enemy.drawHelperState == 0 ? 0x07 : 0x23;
    if (exactLayer != bodyLayer) {
        return true;
    }

    const auto mediumHandle = [this](int frame) {
        return frame >= 0 && frame < static_cast<int>(enemyMediumFrames_.size())
                   ? enemyMediumFrames_[static_cast<std::size_t>(frame)]
                   : -1;
    };
    const auto drawMedium = [&](int frame, float drawX, float drawY,
                                std::uint16_t angle16, double scale,
                                bool reverseX) {
        const int handle = mediumHandle(frame);
        if (handle != -1) {
            drawOriginalMode7Node(handle, drawX, drawY, angle16,
                                  scale, scale, reverseX);
        }
    };

    constexpr double kOriginalPi = 3.14159265358979;
    double scale = 1.0;
    if (enemy.drawHelperState == 0) {
        const int timer = std::clamp(enemy.drawHelperTimer, 0, 0x78);
        scale = std::sin(static_cast<double>(timer) * kOriginalPi / 240.0);
    }

    const std::uint16_t wingAngle = enemy.targetAngle16;
    drawMedium(15, x, y - 15.0f, wingAngle, scale, false);
    drawMedium(15, x, y - 15.0f,
               normalizeAngle16(-static_cast<int>(wingAngle)), scale, true);
    drawMedium(enemy.visualFrame, x, y, 0, scale, false);

    return true;
}

bool StageRuntime::drawStage01SmallEnemyExact(const StageEnemy& enemy, float x,
                                              float y, int exactLayer) const {
    const bool sharedType0BTo0D = enemy.spawnType >= 0x0b && enemy.spawnType <= 0x0d;
    if (enemyUsesMediumFrame(enemy) || enemySmallFrames_.empty()) {
        return false;
    }

    const auto smallHandle = [this](int frame) {
        if (frame < 0 || frame >= static_cast<int>(enemySmallFrames_.size())) {
            return -1;
        }
        return enemySmallFrames_[static_cast<std::size_t>(frame)];
    };
    const auto drawSmall = [&](int frame, float drawX, float drawY, std::uint16_t angle16,
                               double scaleX, double scaleY, bool reverseX) {
        const int smallHandleValue = smallHandle(frame);
        if (smallHandleValue != -1) {
            drawOriginalMode7Node(smallHandleValue, drawX, drawY, angle16, scaleX, scaleY, reverseX);
        }
    };

    if (sharedType0BTo0D) {
        if (enemy.drawMarkerThisFrame && exactLayer == 0x32) {
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            if (marker != -1) {
                const double scale = std::max(
                    0.0, 2.0 - static_cast<double>(enemy.markerDrawTimer) * 0.1);
                drawOriginalMode7Node(marker, screenX(enemy.markerDrawX),
                                      screenY(enemy.markerDrawY), 0,
                                      scale, scale, false);
            }
        }
        if (!enemy.drawBodyThisFrame) {
            return true;
        }
    }
    else if (enemy.helperState != 1) {
        return false;
    }

    switch (enemy.spawnType) {
    case 0x0b: {
        if (exactLayer == 0x32) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f, exactLayer);
            return true;
        }
        if (exactLayer != 0x23) {
            return true;
        }
        // FUN_14007d4e0: DAT_140e44670 body, then four DAT_140e44674 wing/orbit nodes.
        // The manual nodes are literal 0x48 render queue nodes at decompile lines 244-350.
        constexpr double kBodyWaveStep = 0.12319971190548208;
        const int timer = enemy.drawHelperTimer;
        const std::uint16_t bodyAngle = 0;
        const double bodyScaleX =
            1.0 + std::sin(static_cast<double>(timer) * kBodyWaveStep) * 0.1;
        const double bodyScaleY = 1.0;
        drawSmall(4, x, y, bodyAngle, bodyScaleX, bodyScaleY, false);

        constexpr float kWingOffsetY = 45.0f; // DAT_14053acb0 as float, evidence: .rdata @ 14053acb0.
        const std::uint16_t wingBase = normalizeAngle16(timer * 2000);
        drawSmall(5, x, y - kWingOffsetY, wingBase, 1.0, 1.0, false);
        drawSmall(5, x, y - kWingOffsetY, normalizeAngle16(static_cast<int>(wingBase) + 0x4000), 1.0, 1.0, false);
        drawSmall(5, x, y - kWingOffsetY, normalizeAngle16(static_cast<int>(wingBase) - 0x8000), 1.0, 1.0, false);
        drawSmall(5, x, y - kWingOffsetY, normalizeAngle16(static_cast<int>(wingBase) - 0x4000), 1.0, 1.0, false);
        return true;
    }
    case 0x0c: {
        if (exactLayer == 0x32) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f, exactLayer);
            return true;
        }
        if (exactLayer != 0x26) {
            return true;
        }
        // FUN_14007dfb0 lines 309-321: frame 8, mirrored frame 8, frame 7, frame 6.
        constexpr double kYOffsetStep = 0.1698158191129618;  // _DAT_14053aa00 * pi * (1/32768).
        constexpr double kAngleStep = 1.2566370614359172;    // DAT_14053abc0 * pi * (1/32768).
        constexpr double kAngleScale = 2400.0;               // _DAT_14053aa40 as double.
        constexpr float kFrontBodyYOffset = 7.0f;            // DAT_14053abf8 as float.
        constexpr float kBackBodyYOffset = 14.0f;            // _DAT_14053ac40 as float.
        const double timer = static_cast<double>(enemy.drawHelperTimer);
        const float wingY =
            y + static_cast<float>(std::sin((timer - 17.0) * kYOffsetStep));
        const float backBodyWaveY =
            y + static_cast<float>(std::sin(timer * kYOffsetStep));
        const auto wingAngle = static_cast<std::int16_t>(
            static_cast<int>(std::sin(timer * kAngleStep) * kAngleScale));
        const std::uint16_t wingAngle16 = static_cast<std::uint16_t>(wingAngle);
        const std::uint16_t bodyAngle16 = 0;
        drawSmall(8, x, wingY, wingAngle16, 1.0, 1.0, false);
        drawSmall(8, x, wingY, static_cast<std::uint16_t>(-wingAngle), 1.0, 1.0, true);
        drawSmall(7, x, wingY - kFrontBodyYOffset, bodyAngle16, 1.0, 1.0, false);
        drawSmall(6, x, backBodyWaveY - kBackBodyYOffset, bodyAngle16, 1.0, 1.0, false);
        return true;
    }
    case 0x0d: {
        if (exactLayer == 0x32) {
            StageEnemy gaugeSnapshot = enemy;
            gaugeSnapshot.hp = enemy.drawHp;
            drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f, exactLayer);
            return true;
        }
        if (exactLayer != 0x23) {
            return true;
        }
        // FUN_14007ea30 lines 233-257: two frame 10 side nodes, then frame 9 body.
        constexpr double kScaleWaveStep = 0.19039955476301776; // _DAT_14053aa10 * pi * (1/32768).
        constexpr double kAngleStep = 0.09519977738150888;     // _DAT_14053a8e8 * pi * (1/32768), applied to age % 33.
        constexpr double kAngleScale = 6666.0;                 // _DAT_14053ab40 as double.
        constexpr float kSideOffset = 6.0f;                    // DAT_14053ab70 as float.
        constexpr float kSecondWingYOffset = 12.0f;            // DAT_14053ac34 as float.
        const int timer = enemy.drawHelperTimer;
        const double scale =
            1.0 + std::sin(static_cast<double>(timer) * kScaleWaveStep) * 0.1;
        const int localAngleAge = timer % 33;
        const auto flap = static_cast<std::int16_t>(static_cast<int>(std::sin(localAngleAge * kAngleStep) * kAngleScale));
        const bool sourceBelowC000 = enemy.secondaryAngle16 < 0xc000;
        std::uint16_t secondAngle = 0;
        if (sourceBelowC000) {
            const std::uint16_t firstAngle = normalizeAngle16(0x4000 - flap);
            secondAngle = normalizeAngle16(static_cast<int>(flap) + 0x4bb8);
            drawSmall(10, x + kSideOffset, y - kSideOffset, firstAngle, scale, scale, false);
            drawSmall(10, x - kSideOffset, y - kSecondWingYOffset, secondAngle, scale, scale, false);
        }
        else {
            const std::uint16_t firstAngle = normalizeAngle16(static_cast<int>(flap) + 0x4000);
            secondAngle = normalizeAngle16(0x3448 - flap);
            drawSmall(10, x - kSideOffset, y - kSideOffset, firstAngle, scale, scale, false);
            drawSmall(10, x + kSideOffset, y - kSecondWingYOffset, secondAngle, scale, scale, false);
        }
        drawSmall(9, x, y, 0, scale, scale, sourceBelowC000);
        return true;
    }
    default:
        return false;
    }
}

void StageRuntime::drawOriginalMode7Node(int handle, float x, float y, std::uint16_t angle16, double scaleX, double scaleY, bool reverseX) const {
    // FUN_1400c8530 mode 7 passes queued x/y, angle16 * pi * (1/32768),
    // scaleX/scaleY, TransFlag=1, and ReverseX from node +0x3c to the rotated
    // graph wrapper at 0x1401415a0. That wrapper supplies the image center.
    int width = 0;
    int height = 0;
    GetGraphSize(handle, &width, &height);
    DrawRotaGraph3F(static_cast<float>(static_cast<int>(x)),
                    static_cast<float>(static_cast<int>(y)),
                    static_cast<float>(width) * 0.5f,
                    static_cast<float>(height) * 0.5f, scaleX, scaleY,
                    fixedAngleToRadiansDouble(angle16), handle, TRUE,
                    reverseX ? TRUE : FALSE);
}

void StageRuntime::drawStageEffects(bool foreground, int exactLayer) const {
    for (const auto& effect : stageEffects_) {
        if (!effect.drawQueuedThisFrame ||
            (effect.graphHandle == -1 && effect.type != 0x28)) {
            continue;
        }
        if (exactLayer >= 0) {
            if (effect.drawLayer != exactLayer) {
                continue;
            }
        }
        else if ((effect.drawLayer >= 0x18) != foreground ||
                 effect.drawLayer == 0x27 ||
                 effect.drawLayer == 0x1d || effect.drawLayer == 0x20 ||
                 effect.drawLayer == 0x6f || effect.drawLayer == 0x72 ||
                 effect.drawLayer == 0x73) {
            continue;
        }

        const int alpha = std::clamp(effect.drawAlpha, 0, 0xff);
        if (alpha == 0 && effect.type != 0x16) {
            continue;
        }
        SetDrawBright(std::clamp(effect.colorR, 0, 0xff),
                      std::clamp(effect.colorG, 0, 0xff),
                      std::clamp(effect.colorB, 0, 0xff));
        if (effect.type == 0x16) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            DrawGraph(static_cast<int>(effect.drawX),
                      static_cast<int>(effect.drawY), effect.graphHandle, TRUE);
            continue;
        }
        if (effect.type == 0x26 || effect.type == 0x27) {
            // FUN_140073e60 queues this mode-1 banner in absolute screen
            // coordinates rather than in translated stage coordinates.
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawOriginalMode7Node(effect.graphHandle,
                                  effect.drawX, effect.drawY,
                                  effect.drawAngle16,
                                  effect.drawScaleX, effect.drawScaleY,
                                  false);
            continue;
        }
        if (effect.type == 0x28) {
            const int countdown = std::clamp(static_cast<int>(effect.scale0), 0, 5999);
            const int subsecondFrames = countdown % 60;
            const int wholeSeconds = countdown / 60;
            const auto drawDigit = [this](int digit, float x, float y, double scale) {
                if (digit < 0 || digit > 9 ||
                    digit >= static_cast<int>(numSmallFrames_.size())) {
                    return;
                }
                const int handle = numSmallFrames_[static_cast<std::size_t>(digit)];
                if (handle != -1) {
                    drawOriginalMode7Node(handle, x, y, 0,
                                          scale, scale, false);
                }
            };
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawDigit(subsecondFrames / 10, 885.0f, 20.0f, 0.6);
            drawDigit(subsecondFrames % 10, 895.0f, 20.0f, 0.6);
            drawDigit(wholeSeconds / 10, 854.0f, 16.0f, 1.0);
            drawDigit(wholeSeconds % 10, 870.0f, 16.0f, 1.0);
            continue;
        }
        if (effect.type == 0x3a) {
            // FUN_140076b00 uses renderer mode 10: additive, horizontally
            // centered, and top-anchored instead of centered on both axes.
            int width = 0;
            int height = 0;
            GetGraphSize(effect.graphHandle, &width, &height);
            SetDrawBlendMode(DX_BLENDMODE_ADD, alpha);
            DrawRotaGraph3F(
                static_cast<float>(static_cast<int>(screenX(effect.drawX))),
                static_cast<float>(static_cast<int>(screenY(effect.drawY))),
                static_cast<float>(width) * 0.5f, 0.0f,
                effect.drawScaleX, effect.drawScaleY,
                fixedAngleToRadiansDouble(effect.drawAngle16),
                effect.graphHandle, TRUE);
            continue;
        }
        if (effect.type == 0x41) {
            const int age = std::max(0, effect.age - 1);
            for (int segment = 0; segment <= 10; ++segment) {
                const int start = segment * 5;
                if (age < start) {
                    continue;
                }

                double scale = effect.scaleX;
                std::uint16_t angle = 0;
                int nodeAlpha = effect.alpha;
                if (age < start + 32) {
                    if (age < start + 30) {
                        const double entrance = std::sin(
                            static_cast<double>(age - start) * kPi / 60.0);
                        nodeAlpha = static_cast<int>(entrance * effect.alpha);
                        scale = entrance * (effect.scaleX - effect.scaleX * 6.0) +
                                effect.scaleX * 6.0;
                        angle = normalizeAngle16(
                            static_cast<int>(entrance * kFixedAngleFullCircle));
                    }
                }
                else if ((age - start - 30) % 5 == 4) {
                    nodeAlpha = 0;
                }
                if (nodeAlpha <= 0) {
                    continue;
                }

                const double distance = effect.scaleX *
                                        static_cast<double>(200 + segment * 170);
                const float nodeX = effect.drawX +
                    static_cast<float>(std::cos(distance) * distance);
                const float nodeY = effect.drawY +
                    static_cast<float>(std::sin(distance) * distance);
                SetDrawBlendMode(DX_BLENDMODE_ADD,
                                 std::clamp(nodeAlpha, 0, 0xff));
                drawOriginalMode7Node(effect.graphHandle,
                                      screenX(nodeX), screenY(nodeY), angle,
                                      scale, scale, false);
            }
            continue;
        }
        if (effect.type == 0x15) {
            // FUN_140078110 queues three mode-7 nodes around the stored orbit
            // angle. Mode 7 truncates the final translated coordinates.
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            for (int node = 0; node < 3; ++node) {
                const std::uint16_t orbitAngle = normalizeAngle16(
                    static_cast<int>(effect.angle16) + node * 0x5555);
                const double radians = fixedAngleToRadiansDouble(orbitAngle);
                const float nodeX = effect.drawX + static_cast<float>(
                    std::cos(radians) * effect.scale0);
                const float nodeY = effect.drawY + static_cast<float>(
                    std::sin(radians) * effect.scale0);
                drawOriginalMode7Node(
                    effect.graphHandle, screenX(nodeX), screenY(nodeY),
                    effect.drawAngle16, effect.drawScaleX,
                    effect.drawScaleY, false);
            }
            continue;
        }
        if (effect.type == 0x17) {
            // FUN_140076130 draws the base mode-7 node every frame and appends
            // an otherwise identical mode-8 node every third update.
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawOriginalMode7Node(
                effect.graphHandle, screenX(effect.drawX), screenY(effect.drawY),
                effect.drawAngle16, effect.drawScaleX,
                effect.drawScaleY, false);
            const int drawAge = effect.age - 1;
            if (drawAge % 3 == 0) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, alpha);
                drawOriginalMode7Node(
                    effect.graphHandle, screenX(effect.drawX), screenY(effect.drawY),
                    effect.drawAngle16, effect.drawScaleX,
                    effect.drawScaleY, false);
            }
            continue;
        }
        const bool additive = effect.type == 0x05 || effect.type == 0x07 ||
                              effect.type == 0x0d ||
                              effect.type == 0x13 ||
                              effect.type == 0x22 ||
                              effect.type == 0x31 || effect.type == 0x33 ||
                              effect.type == 0x3b || effect.type == 0x3c ||
                              effect.type == 0x3e;
        SetDrawBlendMode(additive ? DX_BLENDMODE_ADD : DX_BLENDMODE_ALPHA,
                         alpha);
        drawOriginalMode7Node(effect.graphHandle,
                              screenX(effect.drawX), screenY(effect.drawY),
                              effect.drawAngle16, effect.drawScaleX,
                              effect.drawScaleY, false);
    }
    SetDrawBright(0xff, 0xff, 0xff);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawProjectiles(int exactLayer) const {
    for (const auto& projectile : enemyProjectiles_) {
        if (!projectile.drawQueuedThisFrame) {
            continue;
        }
        const float x = screenX(projectile.x);
        const float y = screenY(projectile.y);
        if ((projectile.visualSelector == 0x11 || projectile.visualSelector == 0x12) &&
            exactLayer == projectile.drawLayer - 1 &&
            effectSmallFrames_.size() > 7 && effectSmallFrames_[7] != -1) {
            constexpr double kOriginalPi = 3.14159265358979;
            const double pulseY = 0.6 +
                                  std::sin(static_cast<double>(projectile.drawAge) *
                                           2.0 * kOriginalPi / 17.0) *
                                      0.4;
            SetDrawBright(0xff, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xc0);
            drawOriginalMode7Node(effectSmallFrames_[7], x, y, projectile.angle16,
                                  1.0, pulseY, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        if ((projectile.visualSelector == 0x13 || projectile.visualSelector == 0x14) &&
            exactLayer == 0x23) {
            const int overlayIndex = projectile.visualSelector == 0x13 ? 117 : 118;
            if (overlayIndex < static_cast<int>(enemySmallFrames_.size()) &&
                enemySmallFrames_[static_cast<std::size_t>(overlayIndex)] != -1) {
                const int direction = projectile.visualSelector == 0x13 ? -1 : 1;
                SetDrawBright(0xff, 0xff, 0xff);
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xff);
                drawOriginalMode7Node(
                    enemySmallFrames_[static_cast<std::size_t>(overlayIndex)], x, y,
                    normalizeAngle16(direction * projectile.drawAge * 0x457),
                    1.0, 1.0, projectile.visualSelector == 0x14);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        if (exactLayer != projectile.drawLayer) {
            continue;
        }

        const int frameIndex = bulletFrameForVisualSelector(projectile.visualSelector);
        const int handle = bulletFrames_.empty() ||
                                   frameIndex >= static_cast<int>(bulletFrames_.size())
                               ? -1
                               : bulletFrames_[static_cast<std::size_t>(frameIndex)];
        const std::uint16_t drawAngle = projectileDrawAngleForVisualSelector(
            projectile.visualSelector, projectile.drawAge, projectile.angle16);
        const auto scale = projectileScaleForVisualSelector(
            projectile.visualSelector, projectile.drawAge);
        if (handle != -1) {
            // FUN_140070250 queues mode 7: the renderer applies the dynamic
            // camera offset, truncates both screen coordinates, and draws in
            // white with alpha blending even when alpha is fully opaque.
            SetDrawBright(0xff, 0xff, 0xff);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xff);
            drawOriginalMode7Node(handle, x, y, drawAngle,
                                  scale[0], scale[1], false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
}

void StageRuntime::drawRewardItems(bool specialLayer) const {
    for (const auto& item : rewardItems_) {
        const bool specialItem = item.itemType >= 6 && item.itemType <= 8;
        if (specialItem != specialLayer) {
            continue;
        }
        int handle = -1;
        int alpha = 0xff;
        double scale = 1.0;
        bool magentaTint = false;

        const bool ordinaryScoreItem = item.itemType >= 0 && item.itemType <= 5;
        if (ordinaryScoreItem) {
            // FUN_1400ca7b0 has no type-5 draw branch even though type 5 shares
            // type 2's collection payout.
            double baseScale = 0.0;
            if (item.itemType == 0 || item.itemType == 3) {
                baseScale = 0.75;
            }
            else if (item.itemType == 1 || item.itemType == 4) {
                baseScale = 1.0;
            }
            else if (item.itemType == 2) {
                baseScale = 1.5;
            }
            else {
                continue;
            }

            const int frameIndex = config_.likeStyle == 1 ? 13 : 0;
            if (frameIndex >= static_cast<int>(itemFrames_.size())) {
                continue;
            }
            handle = itemFrames_[static_cast<std::size_t>(frameIndex)];
            const double pulse =
                1.0 + 0.2 * std::sin(static_cast<double>(item.drawAge) *
                                     static_cast<double>(kPi) / 33.0);
            scale = baseScale * pulse;
            alpha = config_.likeStyle == 1 ? 200 : (config_.itemVisibility == 1 ? 128 : 160);
        }
        else if (item.itemType >= 6 && item.itemType <= 8) {
            scale = 1.0 + 0.1 * std::sin(static_cast<double>(item.drawAge) *
                                         static_cast<double>(kPi) / 32.0);
            if (item.itemType == 6 && itemFrames_.size() > 11) {
                handle = itemFrames_[11];
            }
            else if (item.itemType == 7 && itemFrames_.size() > 12) {
                handle = itemFrames_[12];
            }
            else if (item.itemType == 8 && enemySmallFrames_.size() > 11) {
                handle = enemySmallFrames_[11];
                magentaTint = true;
            }
        }

        if (handle == -1) {
            continue;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        if (magentaTint) {
            SetDrawBright(0xff, 0x20, 0xff);
        }
        DrawRotaGraphF(screenX(item.x), screenY(item.y), scale, 0.0, handle, TRUE);
        if (magentaTint) {
            SetDrawBright(0xff, 0xff, 0xff);
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

void StageRuntime::drawOverlay() const {
    if (showLayoutGuides_) {
        drawLayoutGuides();
        drawDebugOverlay();
    }
}

void StageRuntime::drawHudSidebar(int exactLayer) const {
    drawStateRows(exactLayer);
    drawTimeWindowHud(exactLayer);
    if (config_.dataWindowEnabled == 1 && config_.routeMode != -1) {
        drawLeftHudPanel(exactLayer);
    }
}


void StageRuntime::drawLeftHudPanel(int exactLayer) const {
    if (exactLayer == 0x7c) {
        if (selectedStage_ == 10 && resultFrames_.size() > 9 &&
            resultFrames_[9] != -1) {
            DrawRotaGraph3F(30.0f, 365.0f, 0.0f, 30.0f,
                            0.9, 0.9, 0.0, resultFrames_[9], TRUE);
        }
        return;
    }
    if (exactLayer != 0x73) {
        return;
    }

    if (dataWindowHandle_ != -1) {
        DrawGraph(0, 330, dataWindowHandle_, TRUE);
    }

    if (selectedStage_ != 10 && resultFrames_.size() > 1) {
        const int handle = resultFrames_[1];
        if (handle != -1) {
            DrawRotaGraph3F(30.0f, 365.0f, 0.0f, 30.0f,
                            0.9, 0.9, 0.0, handle, TRUE);
        }
    }
    if (selectedStage_ != 10) {
        drawHudNumber(120.0f, 365.0f, selectedStage_, numSmallFrames_,
                      16.0f, 0.9, 1, false);
    }
    if (pauseFlowState_ != PauseFlowState::GameOverPresentation) {
        drawHudNumber(280.0f, 365.0f, frame_, numSmallFrames_,
                      16.0f, 1.0, 5, false);
    }

    float nearestSurfaceDistance = std::numeric_limits<float>::max();
    bool hasDistanceTarget = false;
    const float horizontalOrigin = player_.x / 6.0f;
    for (const StageEnemy& enemy : enemies_) {
        if (!enemy.active || !enemy.targetable) {
            continue;
        }
        const float radius = static_cast<float>(std::max(0, enemy.radius));
        if (enemy.x < horizontalOrigin - (radius + 100.0f) ||
            enemy.x > horizontalOrigin + radius + 700.0f ||
            enemy.y < -(radius + 100.0f) || enemy.y > radius + 820.0f) {
            continue;
        }
        hasDistanceTarget = true;
        const float dx = enemy.x - player_.x;
        const float dy = enemy.y - player_.y;
        const float surfaceDistance =
            std::sqrt(dx * dx + dy * dy) - static_cast<float>(enemy.radius);
        nearestSurfaceDistance = std::min(nearestSurfaceDistance, surfaceDistance);
    }
    int distanceValue = 0;
    int distanceTier = 10;
    if (nearestSurfaceDistance >= 0.0f && nearestSurfaceDistance < 2000.0f) {
        distanceValue = static_cast<int>(nearestSurfaceDistance);
        if (distanceValue > 150) {
            distanceTier = 1;
            if (distanceValue < 450) {
                distanceTier = std::max(1, (450 - distanceValue) / 30);
            }
        }
    }
    if (hasDistanceTarget) {
        drawHudNumber(54.0f, 447.0f, distanceValue, numSmallFrames_,
                      16.0f, 1.0, 4, true);
    }
    if (hasDistanceTarget && distanceTier >= 0 &&
        distanceTier < static_cast<int>(itemFrames_.size())) {
        const int handle = itemFrames_[static_cast<std::size_t>(distanceTier)];
        if (handle != -1) {
            const double scale = static_cast<double>(distanceTier) * 0.035 + 0.35;
            DrawRotaGraphF(120.0f, 450.0f, scale, 0.0, handle, TRUE);
        }
    }

    const int bulletCount = static_cast<int>(std::count_if(
        enemyProjectiles_.begin(), enemyProjectiles_.end(),
        [](const StageProjectile& projectile) { return projectile.active; }));
    drawHudNumber(280.0f, 435.0f, bulletCount, numSmallFrames_,
                  16.0f, 1.0, 4, false);
    drawHudNumber(265.0f, 465.0f, enemyProjectileSpawnsLastSecond_, numSmallFrames_,
                  16.0f, 0.7, 4, false);
    drawHudNumber(135.0f, 535.0f, player_.graze, numSmallFrames_,
                  16.0f, 1.0, 6, false);

    const bool hiddenStage = config_.routeMode == 1 &&
                             config_.specialStageFlag == 0 && selectedStage_ != 10;
    if (hiddenStage && dataWindow2Frames_.size() > 9 && dataWindow2Frames_[9] != -1) {
        constexpr std::array<std::array<int, 4>, 5> kHiddenShotLimits{{
            {{6, 5, 5, 3}}, {{6, 5, 5, 3}}, {{6, 5, 5, 3}},
            {{8, 7, 7, 4}}, {{10, 8, 8, 5}},
        }};
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int style = std::clamp(config_.optionSlots[3], 0, 3);
        const bool hiddenStateUnlocked =
            player_.beingShotCount <=
            kHiddenShotLimits[static_cast<std::size_t>(difficulty)]
                             [static_cast<std::size_t>(style)];
        int brightness = 64;
        if (selectedStage_ == 9) {
            brightness = 255;
        }
        else if (hiddenStateUnlocked) {
            brightness = 224 + static_cast<int>(
                32.0 * std::sin(static_cast<double>(player_.drawAnimationClock) *
                                static_cast<double>(kPi) / 60.0));
        }
        SetDrawBright(brightness, brightness, brightness);
        DrawRotaGraphF(280.0f, 535.0f, 1.0, 0.0, dataWindow2Frames_[9], TRUE);
        SetDrawBright(255, 255, 255);
    }
    drawHudNumber(hiddenStage ? 215.0f : 245.0f, 540.0f,
                  player_.beingShotCount, configNumberFrames_,
                  25.0f, 1.0, 2, true);

    const int group = std::clamp(config_.setupGroup, 0, 2);
    constexpr std::array<int, 4> kNeutralSequence{{0, 1, 2, 1}};
    const int neutralFrame = group * 30 +
        kNeutralSequence[static_cast<std::size_t>(
            (std::max(player_.drawAnimationClock, 0) / 7) % 4)];
    if (neutralFrame >= 0 && neutralFrame < static_cast<int>(playerFrames_.size()) &&
        playerFrames_[static_cast<std::size_t>(neutralFrame)] != -1) {
        DrawRotaGraphF(55.0f, 640.0f, 1.0, 0.0,
                       playerFrames_[static_cast<std::size_t>(neutralFrame)], TRUE);
    }
    if (player_.invulnerableFrames > 0 &&
        (player_.drawAnimationClock & 1) == 0) {
        const int overlayFrame = neutralFrame + 15;
        if (overlayFrame < static_cast<int>(playerFrames_.size()) &&
            playerFrames_[static_cast<std::size_t>(overlayFrame)] != -1) {
            DrawRotaGraphF(55.0f, 640.0f, 1.0, 0.0,
                           playerFrames_[static_cast<std::size_t>(overlayFrame)], TRUE);
        }
    }
    if (player_.invulnerableFrames > 0) {
        drawHudNumber(55.0f, 640.0f, player_.invulnerableFrames,
                      numSmallFrames_, 16.0f, 1.0, 4, true);
    }

    if (dataWindow2Frames_.size() >= 9) {
        const auto drawDataWindowFrame = [&](int frameIndex, float x, float y,
                                             std::uint16_t angle16 = 0) {
            const int handle = dataWindow2Frames_[static_cast<std::size_t>(frameIndex)];
            if (handle == -1) {
                return;
            }
            const double angle = static_cast<double>(angle16) *
                                 static_cast<double>(kPi) / 32768.0;
            DrawRotaGraphF(x, y, 1.0, angle, handle, TRUE);
        };
        drawDataWindowFrame(0, 160.0f, 647.0f);
        constexpr std::array<InputAction, 4> kDirections{{
            InputAction::Up, InputAction::Down,
            InputAction::Right, InputAction::Left,
        }};
        constexpr std::array<float, 4> kDirectionX{{160.0f, 160.0f, 190.0f, 130.0f}};
        constexpr std::array<float, 4> kDirectionY{{610.0f, 670.0f, 640.0f, 640.0f}};
        constexpr std::array<std::uint16_t, 4> kDirectionAngles{{
            0xc000, 0x4000, 0x0000, 0x8000,
        }};
        for (std::size_t i = 0; i < kDirections.size(); ++i) {
            drawDataWindowFrame(actionDown(kDirections[i]) ? 2 : 1,
                                kDirectionX[i], kDirectionY[i], kDirectionAngles[i]);
        }

        constexpr std::array<InputAction, 4> kButtons{{
            InputAction::Shoot, InputAction::Bomb,
            InputAction::RapidFire, InputAction::Slow,
        }};
        constexpr std::array<float, 4> kButtonX{{220.0f, 270.0f, 290.0f, 240.0f}};
        constexpr std::array<float, 4> kButtonY{{615.0f, 615.0f, 665.0f, 665.0f}};
        for (std::size_t i = 0; i < kButtons.size(); ++i) {
            drawDataWindowFrame(5 + static_cast<int>(i),
                                kButtonX[i], kButtonY[i] - 20.0f);
            drawDataWindowFrame(actionDown(kButtons[i]) ? 4 : 3,
                                kButtonX[i], kButtonY[i]);
        }
    }
}

void StageRuntime::drawRightHudPanel(int exactLayer) const {
    if (exactLayer != 0x6e) {
        return;
    }
    if (!playerFrameFrames_.empty() && playerFrameFrames_.front() != -1) {
        // FUN_1400c2860 draws the fixed right-side frame first, then the
        // selected setup's left-side PlayerFrame overlay. routeMode does not
        // select this family.
        DrawGraph(940, 0, playerFrameFrames_.front(), TRUE);
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const int overlayIndex =
            (pauseFlowState_ == PauseFlowState::GameOverPresentation ? 9 : 1) +
            group * 10;
        if (overlayIndex < static_cast<int>(playerFrameFrames_.size()) &&
            playerFrameFrames_[static_cast<std::size_t>(overlayIndex)] != -1) {
            DrawGraph(0, 0,
                      playerFrameFrames_[static_cast<std::size_t>(overlayIndex)], TRUE);
        }
    }
}

void StageRuntime::drawTimeWindowHud(int exactLayer) const {
    if (exactLayer != 0x70 || config_.specialStageFlag != 1 ||
        timeWindowHandle_ == -1) {
        return;
    }

    // FUN_1400c5930 replaces PlayerFrame[0]'s upper panel at layer 0x70.
    DrawGraph(940, 0, timeWindowHandle_, TRUE);

    if (effectSmallFrames_.size() > 1 && effectSmallFrames_[1] != -1) {
        const int dispatchCount = std::clamp(timeWindowDispatchCount_, 0, 4);
        for (int i = 0; i < dispatchCount; ++i) {
            DrawRotaGraphF(965.0f + static_cast<float>(i * 24), 15.0f,
                           0.4, 0.0, effectSmallFrames_[1], TRUE);
        }
    }

    if (numSmallFrames_.size() < 14) {
        return;
    }
    const auto drawFrame = [this](int frameIndex, float x, float y, double scale) {
        const int handle = numSmallFrames_[static_cast<std::size_t>(frameIndex)];
        if (handle != -1) {
            DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
        }
    };
    const auto drawTime = [&](int sourceFrames, float x, float y, double scale) {
        int remaining = std::max(0, sourceFrames);
        const bool displaySeconds = remaining >= 60;
        const float step = 16.0f * static_cast<float>(scale);
        const auto drawRightAligned = [&](int value, float rightX) {
            value = std::max(0, value);
            do {
                drawFrame(value % 10, rightX, y, scale);
                rightX -= step;
                value /= 10;
            } while (value > 0);
        };

        if (remaining >= 3600) {
            const int minutes = std::min(remaining / 3600, 99);
            drawRightAligned(minutes, x + step * 2.0f);
            drawFrame(13, x + step * 3.0f, y, scale);
            remaining %= 3600;
        }
        if (displaySeconds) {
            const int seconds = remaining / 60;
            drawRightAligned(seconds, x + step * 5.0f);
            if (seconds < 10) {
                drawFrame(0, x + step * 4.0f, y, scale);
            }
            drawFrame(10, x + step * 6.0f + 5.0f, y, scale);
            remaining %= 60;
        }

        const int hundredths = std::min(
            static_cast<int>(static_cast<double>(remaining) * (5.0 / 3.0)), 99);
        if (hundredths < 10) {
            drawFrame(0, x + step * 7.0f, y, scale);
        }
        drawRightAligned(hundredths, x + step * 8.0f);
    };

    if (config_.routeMode == 1) {
        for (int row = 0; row < 8; ++row) {
            const int stage = row + 1;
            const float y = 50.0f + static_cast<float>(row * 26);
            if (stage < timeWindowStage_) {
                const int start = timeWindowStageBoundaries_[static_cast<std::size_t>(stage - 1)];
                const int end = timeWindowStageBoundaries_[static_cast<std::size_t>(stage)];
                drawTime(end, 1030.0f, y, 0.7);
                drawTime(std::max(0, end - start), 1150.0f, y, 0.7);
            }
            else if (stage == timeWindowStage_) {
                const int start = timeWindowStageBoundaries_[static_cast<std::size_t>(stage - 1)];
                drawTime(timeWindowElapsedFrames_, 1030.0f, y, 0.7);
                drawTime(std::max(0, timeWindowElapsedFrames_ - start),
                         1150.0f, y, 0.7);
            }
        }
        drawTime(timeWindowElapsedFrames_, 1070.0f, 262.0f, 1.0);
        drawTime(timeWindowBestFrames_, 1070.0f, 295.0f, 1.0);
    }
    else if (config_.routeMode == 2) {
        drawTime(timeWindowElapsedFrames_, 1070.0f, 262.0f, 1.0);
    }
}

void StageRuntime::drawStateRows(int exactLayer) const {
    const auto drawState = [&](int frameIndex, float x, float y,
                               int red = 255, int green = 255, int blue = 255,
                               int alpha = 255, double scale = 1.0) {
        if (frameIndex < 0 || frameIndex >= static_cast<int>(stateFrames_.size())) {
            return;
        }
        const int handle = stateFrames_[static_cast<std::size_t>(frameIndex)];
        if (handle == -1) {
            return;
        }
        SetDrawBright(red, green, blue);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        DrawRotaGraphF(x, y, scale, 0.0, handle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        SetDrawBright(255, 255, 255);
    };

    constexpr std::array<int, 3> kFrameRates{{60, 30, 20}};
    const int frameRateMode = std::clamp(config_.systemConfig[1], 0, 2);
    const int targetFrameRate = kFrameRates[static_cast<std::size_t>(frameRateMode)];
    const int measuredFrameRate = frameRateMode == 0
                                      ? hudMeasuredFrameRate_
                                      : hudMeasuredFrameRate_ / (frameRateMode + 1);
    if (exactLayer == 0x6e) {
        drawHudNumber(1270.0f, 12.0f, targetFrameRate, numSmallFrames_,
                      16.0f, 0.8, 3, false);
        if (numSmallFrames_.size() > 12 && numSmallFrames_[12] != -1) {
            DrawRotaGraph3F(1235.0f, 0.0f, 0.0f, 0.0f,
                            0.8, 0.8, 0.0, numSmallFrames_[12], TRUE);
        }
        return;
    }
    if (exactLayer == 0x78) {
        drawHudNumber(1230.0f, 12.0f, measuredFrameRate, numSmallFrames_,
                      16.0f, 0.8, 3, false);
        return;
    }
    if (exactLayer != 0x6f) {
        return;
    }

    if (config_.routeMode == -1) {
        drawState(15, 1115.0f, 340.0f);
    }
    else if (selectedStage_ == 10) {
        drawState(16, 1115.0f, 340.0f);
    }
    else {
        drawState(10 + std::clamp(config_.difficulty, 0, 4),
                  1115.0f, 340.0f);
    }
    if (config_.routeMode == 1 && selectedStage_ != 10) {
        drawState(17, 1115.0f, 370.0f);
    }
    else if (config_.routeMode == 2) {
        drawState(28, 1115.0f, 370.0f);
    }

    const int bestFrame = config_.likeStyle == 0 ? 0 : 29;
    const int likeFrame = config_.likeStyle == 0 ? 1 : 30;
    drawState(bestFrame, 1040.0f, 410.0f);
    drawState(likeFrame, 1040.0f, 450.0f);
    drawHudNumber(1240.0f, 410.0f, player_.bestScore, numSmallFrames_,
                  16.0f, 1.0, 12, false, true);
    drawHudNumber(1240.0f, 450.0f, player_.score, numSmallFrames_,
                  16.0f, 1.0, 12, false, true);

    drawState(2, 1040.0f, 500.0f);
    drawHudNumber(1240.0f, 500.0f, player_.scoreItemBaseValue,
                  numSmallFrames_, 16.0f, 1.0, 9, false, true);

    drawState(3, 1040.0f, 530.0f);
    if (!enemyGaugeFrames_.empty() && enemyGaugeFrames_[0] != -1) {
        SetDrawBright(64, 64, 128);
        DrawRotaGraphF(1135.0f, 534.0f, 1.0, 0.0, enemyGaugeFrames_[0], TRUE);
        SetDrawBright(255, 255, 255);
    }
    if (enemyGaugeFillHandle_ != -1) {
        double gaugeScale = static_cast<double>(player_.specialGauge) / 50000.0;
        int gaugeRed = 255;
        int gaugeGreen = 64;
        int gaugeBlue = 64;
        // The original first comparison is unsigned: negative cooldown values
        // enter the same rainbow branch as the full/ready sentinel.
        if (player_.specialGauge < 0 || player_.specialGauge > 49999) {
            gaugeScale = player_.specialGauge < 0
                             ? -static_cast<double>(player_.specialGauge) / 600.0
                             : 1.0;
            constexpr std::array<std::array<int, 3>, 7> kReadyColors{{
                {{255, 120, 120}}, {{255, 200, 110}}, {{255, 255, 120}},
                {{120, 255, 120}}, {{120, 255, 255}}, {{120, 120, 255}},
                {{220, 120, 255}},
            }};
            const int colorTick = std::max(player_.drawAnimationClock, 0);
            const int colorIndex = (colorTick / 20) % 7;
            const int nextColorIndex = (colorIndex + 1) % 7;
            const double mix = static_cast<double>(colorTick % 20) / 20.0;
            const auto interpolate = [&](int channel) {
                const int current = kReadyColors[static_cast<std::size_t>(colorIndex)]
                                                [static_cast<std::size_t>(channel)];
                const int next = kReadyColors[static_cast<std::size_t>(nextColorIndex)]
                                             [static_cast<std::size_t>(channel)];
                return static_cast<int>(static_cast<double>(current) +
                                        static_cast<double>(next - current) * mix);
            };
            gaugeRed = interpolate(0);
            gaugeGreen = interpolate(1);
            gaugeBlue = interpolate(2);
        }
        SetDrawBright(gaugeRed, gaugeGreen, gaugeBlue);
        DrawRotaGraph3F(1015.0f, 529.0f, 0.0f, 0.0f,
                        gaugeScale, 1.0, 0.0, enemyGaugeFillHandle_, TRUE);
        SetDrawBright(255, 255, 255);
        if (hudSpecialGaugeFlashTimer_ > 0) {
            SetDrawBright(255, 128, 64);
            DrawRotaGraph3F(1015.0f, 543.0f, 0.0f, 0.0f,
                            static_cast<double>(hudSpecialGaugeFlashTimer_) / 60.0,
                            0.5, 0.0, enemyGaugeFillHandle_, TRUE);
            SetDrawBright(255, 255, 255);
        }
    }

    drawState(4, 1040.0f, 580.0f);
    // DAT_140e445f8: nine-heart Life stock, represented by player_.lives.
    for (int i = 0; i < 9; ++i) {
        const float x = static_cast<float>(1037 + i * 27);
        drawState(8, x, 580.0f, 0, 0, 0, 64);
        if (i < player_.lives) {
            drawState(8, x, 580.0f);
        }
    }

    drawState(5, 1050.0f, 610.0f);
    const auto& thresholds =
        kExtendThresholds[static_cast<std::size_t>(std::clamp(config_.difficulty, 0, 4))];
    if (player_.extendIndex >= 0 && player_.extendIndex < 5) {
        drawHudNumber(1240.0f, 611.0f,
                      thresholds[static_cast<std::size_t>(player_.extendIndex)], numSmallFrames_,
                      16.0f, 0.7, 12, false, true);
    }

    drawState(6, 1040.0f, 650.0f);
    // DAT_140e45d34: three-step Mental level, represented by tokenStock.
    constexpr std::array<float, 3> kMentalX{{1100.0f, 1135.0f, 1170.0f}};
    for (std::size_t i = 0; i < kMentalX.size(); ++i) {
        drawState(9, kMentalX[i], 650.0f, 0, 0, 0, 64);
        if (static_cast<int>(i) < player_.tokenStock) {
            drawState(9, kMentalX[i], 650.0f);
        }
    }

    drawState(7, 1030.0f, 695.0f);
    for (std::size_t i = 0; i < config_.optionSlots.size(); ++i) {
        drawState(22 + std::clamp(config_.optionSlots[i], 0, 3),
                  1130.0f + static_cast<float>(i) * 20.0f, 695.0f);
    }
    drawState(config_.specialMode == 0 ? 26 : 27, 1300.0f, 695.0f);
}

void StageRuntime::drawLayoutGuides() const {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
    DrawBox(notes::gameplay_layout::kStageBackRect.x, notes::gameplay_layout::kStageBackRect.y,
            notes::gameplay_layout::kStageBackRect.right(), notes::gameplay_layout::kStageBackRect.bottom(),
            GetColor(80, 120, 255), FALSE);
    DrawBox(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y,
            notes::gameplay_layout::kStageFrameRect.right(), notes::gameplay_layout::kStageFrameRect.bottom(),
            GetColor(80, 255, 160), FALSE);
    DrawBox(static_cast<int>(screenX(kPlayLeft)), static_cast<int>(screenY(kPlayTop)),
            static_cast<int>(screenX(kPlayRight)), static_cast<int>(screenY(kPlayBottom)),
            GetColor(255, 220, 80), FALSE);
    DrawBox(notes::hud_layout::kTimeWindowRect.x, notes::hud_layout::kTimeWindowRect.y,
            notes::hud_layout::kTimeWindowRect.right(), notes::hud_layout::kTimeWindowRect.bottom(),
            GetColor(255, 120, 80), FALSE);
    DrawBox(notes::hud_layout::kDataWindowRect.x, notes::hud_layout::kDataWindowRect.y,
            notes::hud_layout::kDataWindowRect.right(), notes::hud_layout::kDataWindowRect.bottom(),
            GetColor(255, 120, 200), FALSE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    const int lineColor = GetColor(180, 220, 255);
    for (int y : {notes::hud_layout::kBestY, notes::hud_layout::kLikeY,
                  notes::hud_layout::kFollowerY, notes::hud_layout::kBuzzY,
                  notes::hud_layout::kLifeY, notes::hud_layout::kNextExtendY,
                  notes::hud_layout::kMentalY}) {
        DrawLine(notes::hud_layout::kDataWindowRect.x, y, notes::hud_layout::kDataWindowRect.right(), y, lineColor);
    }
    for (int i = 0; i < notes::hud_layout::kHeartCount; ++i) {
        const int x = notes::hud_layout::kHeartStartX + i * notes::hud_layout::kHeartStep;
        DrawLine(x, notes::hud_layout::kLifeY - 10, x,
                 notes::hud_layout::kLifeY + 26, GetColor(180, 255, 220));
    }
    DrawFormatString(56, 20, GetColor(255, 245, 160),
                     "F7 layout guides  player local=(%.1f, %.1f) screen=(%.1f, %.1f)",
                     player_.x, player_.y, screenX(player_.x), screenY(player_.y));
    DrawString(56, 42, "blue=StageBack  green=StageFrame  yellow=600x720 playfield  red/pink=HUD windows", GetColor(210, 220, 240));
    DrawString(56, 64, "HUD anchors and frame identities follow FUN_1400c2860/FUN_1400c4bb0.", GetColor(255, 220, 170));
}

void StageRuntime::drawDebugOverlay() const {
    DrawFormatString(24, notes::kScreenHeight - 70, GetColor(170, 170, 190),
                     "F7 guide: decoded HUD anchors from FUN_1400c2860/FUN_1400c4bb0.");
    DrawFormatString(24, notes::kScreenHeight - 48, GetColor(150, 160, 180),
                     "reconstruction probe  stage=%02d frame=%d enemies=%d bullets=%d side=%d lives=%d",
                     selectedStage_, frame_, static_cast<int>(enemies_.size()),
                     static_cast<int>(enemyProjectiles_.size()), static_cast<int>(playerSideObjects_.size()),
                     player_.lives);
    DrawFormatString(24, notes::kScreenHeight - 26, GetColor(150, 180, 210),
                     "loadout route=%d group=%d playerOpt=%d sub=%d loadout=%d diff=%d counter=%d shotTimer=%d focus=%d slots=[%d %d %d %d]",
                     config_.routeMode, config_.setupGroup, config_.playerOption, config_.subOption, config_.loadoutId, config_.difficulty, config_.counterMode,
                     player_.shotTimer, player_.focused ? 1 : 0,
                     config_.optionSlots[0], config_.optionSlots[1], config_.optionSlots[2], config_.optionSlots[3]);
}

void StageRuntime::drawHudNumber(float anchorX, float centerY, std::int64_t value,
                                 const std::vector<int>& digitFrames,
                                 float unscaledStep, double scale,
                                 int maxDigits, bool centered,
                                 bool separators) const {
    value = std::max<std::int64_t>(0, value);
    maxDigits = std::clamp(maxDigits, 1, 12);

    std::int64_t maximum = 1;
    for (int i = 0; i < maxDigits; ++i) {
        maximum *= 10;
    }
    --maximum;
    const bool overflow = value > maximum;
    std::int64_t remaining = std::min(value, maximum);

    std::array<int, 12> digits{};
    int digitCount = 0;
    do {
        digits[static_cast<std::size_t>(digitCount++)] =
            static_cast<int>(remaining % 10);
        remaining /= 10;
    } while (remaining > 0 && digitCount < maxDigits);

    const float step = unscaledStep * static_cast<float>(scale);
    float digitX = anchorX;
    if (centered) {
        digitX += static_cast<float>(digitCount - 1) * step * 0.5f;
    }

    if (digitFrames.size() < 10 || digitFrames.front() == -1) {
        DrawFormatString(static_cast<int>(anchorX), static_cast<int>(centerY),
                         GetColor(245, 245, 255), "%lld",
                         static_cast<long long>(std::min(value, maximum)));
        return;
    }

    const float leastSignificantX = digitX;
    // The manually composed right-side rows prepend '+'. FUN_1400c95e0's
    // ungrouped left-side numbers clamp without an overflow marker.
    if (overflow && separators && numSmallFrames_.size() > 11 &&
        numSmallFrames_[11] != -1) {
        DrawRotaGraphF(leastSignificantX + step, centerY, scale, 0.0,
                       numSmallFrames_[11], TRUE);
    }
    for (int i = 0; i < digitCount; ++i) {
        const int digit = digits[static_cast<std::size_t>(i)];
        const int handle = digitFrames[static_cast<std::size_t>(digit)];
        if (handle != -1) {
            DrawRotaGraphF(digitX, centerY, scale, 0.0, handle, TRUE);
        }
        digitX -= step;
        if (separators && (i + 1) % 3 == 0 && i + 1 < digitCount &&
            numSmallFrames_.size() > 10 && numSmallFrames_[10] != -1) {
            digitX -= 5.0f * static_cast<float>(scale);
            DrawRotaGraphF(digitX + step, centerY, scale, 0.0,
                           numSmallFrames_[10], TRUE);
        }
    }
}


void StageRuntime::updateLayoutGuideToggle() {
    const bool down = CheckHitKey(KEY_INPUT_F7) != 0;
    if (down && !prevLayoutGuideToggle_) {
        showLayoutGuides_ = !showLayoutGuides_;
    }
    prevLayoutGuideToggle_ = down;
}

float StageRuntime::aimAtPlayer(float x, float y) const {
    return std::atan2(player_.y - y, player_.x - x);
}

float StageRuntime::deterministicUnit(int frame, int salt) {
    std::uint32_t value = static_cast<std::uint32_t>(frame * 1103515245u + salt * 12345u + 0x314159u);
    value ^= value >> 16;
    return static_cast<float>(value & 0xffffu) / 65535.0f;
}

bool StageRuntime::offscreen(float x, float y, float margin) {
    return x < kPlayLeft - margin || x > kPlayRight + margin || y < kPlayTop - margin || y > kPlayBottom + margin;
}

} // namespace reconstructed
