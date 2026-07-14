#include "stage_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>

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
constexpr int kSpecialGaugeReady = 50000;
constexpr int kSpecialGaugeForcedFull = 9999999;
constexpr int kFeverActiveFrames = 600;
constexpr int kSpecialTokenCap = 9;
constexpr std::array<int, 5> kOriginalStockThresholds{{56000, 70000, 70000, 70000, 70000}};
constexpr int kGrazeMargin = 24;
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
constexpr float kPlayLeft = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.x);
constexpr float kPlayRight = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.right());
constexpr float kPlayTop = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.y);
constexpr float kPlayBottom = static_cast<float>(notes::gameplay_layout::kPlayLocalRect.bottom());

float screenX(float localX) {
    return localX + static_cast<float>(notes::gameplay_layout::kPlayScreenOrigin.x);
}

float screenY(float localY) {
    return localY + static_cast<float>(notes::gameplay_layout::kPlayScreenOrigin.y);
}

float projectileHorizontalOrigin(float playerX) {
    // The original projectile helpers derive their horizontal bounds from
    // DAT_140e445d8 / 6 rather than from the fixed player movement rectangle.
    return playerX / 6.0f;
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
        return 1;
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

float normalizeAngle(float angle) {
    while (angle > kPi) angle -= kTau;
    while (angle < -kPi) angle += kTau;
    return angle;
}

float approachAngle(float current, float target, float amount) {
    return current + normalizeAngle(target - current) * amount;
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
        return {1.0f, 1.0f};
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

double projectileDrawRotationForVisualSelector(int visualSelector, int age, std::uint16_t angle16) {
    // FUN_140070250 is selector-driven: some visuals preserve projectile angle,
    // while pellets/orbs/beads/diamonds overwrite it with age-based spin.
    const int ageSpinStep = projectileAgeSpinStepForVisualSelector(visualSelector);
    if (ageSpinStep != 0) {
        return fixedAngleToRadiansDouble(normalizeAngle16(age * ageSpinStep));
    }
    return fixedAngleToRadiansDouble(angle16);
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

float stage01SmallProjectileSpeed(int difficulty, int stage, float base = 2.0f) {
    const float stageBoost = stage > 3 ? 0.35f : 0.0f;
    switch (difficulty) {
    case 0: return base + stageBoost;
    case 1: return base + 0.35f + stageBoost;
    case 2: return base + 0.75f + stageBoost;
    case 3: return base + 1.05f + stageBoost;
    case 4: return base + 1.45f + stageBoost;
    default: return base + stageBoost;
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
           spawnType == 0x2e || spawnType == 0x30 || spawnType == 0x3f;
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
    default: return std::max(1, radius / 10);
    }
}

} // namespace

const StageRuntime::StageSpawnEvent* StageRuntime::eventsForStage(int stage, std::size_t& count) {
    if (stage == 4) {
        count = kStage04Events.size();
        return kStage04Events.data();
    }
    count = kStage01Events.size();
    return kStage01Events.data();
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
    effectSmallFrames_ = resources.loadDivGraph("media\\effect\\Effect_s.png", 0x14, 10, 2, 100, 100);
    effectMediumFrames_ = resources.loadDivGraph("media\\effect\\Effect_m.png", 0x1e, 10, 3, 200, 200);
    effectLargeFrames_ = resources.loadDivGraph("media\\effect\\Effect_l.png", 0x1e, 10, 3, 600, 600);
    enemyGaugeFrames_ = resources.loadDivGraph("media\\stage\\EnemyGauge1.png", 3, 1, 3, 0xf6, 0x10);
    enemyGaugeFillHandle_ = resources.loadGraph("media\\stage\\EnemyGauge2.png");
    bossFrames_ = resources.loadDivGraph("media\\stage\\Boss.png", 0xa0, 10, 0x10, 200, 200);
    bossGaugeFrames_ = resources.loadDivGraph("media\\stage\\BossGauge.png", 10, 1, 10, 500, 30);
    bossNameFrames_ = resources.loadDivGraph("media\\stage\\BossName.png", 0x16, 1, 0x16, 400, 30);
    textBoxFrames_ = resources.loadDivGraph("media\\system\\TextBox.png", 2, 1, 2, 600, 100);
    textIconFrames_ = resources.loadDivGraph("media\\system\\TextIcon.png", 0x14, 10, 2, 80, 80);
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack1bFrames_ = resources.loadDivGraph("media\\stage\\StageBack1b.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack1cFrames_ = resources.loadDivGraph("media\\stage\\StageBack1c.png", 0x0c, 0x0c, 1, 0x2d0, 0xa00);
    stageBack1dFrames_ = resources.loadDivGraph("media\\stage\\StageBack1d.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack2Frames_ = resources.loadDivGraph("media\\stage\\StageBack2.png", 10, 10, 1, 0x2d0, 0x2d0);

    stageFrameFrames_ = resources.loadDivGraph("media\\system\\StageFrame.png", 2, 2, 1, 600, 720);
    numSmallFrames_ = resources.loadDivGraph("media\\system\\Num_s.png", 0x0e, 0x0e, 1, 0x14, 0x1e);
    numMediumFrames_ = resources.loadDivGraph("media\\system\\Num_m.png", 10, 10, 1, 0x20, 0x30);
    numLargeFrames_ = resources.loadDivGraph("media\\system\\Num_l.png", 0x0e, 0x0e, 1, 0x30, 0x48);
    dataWindowHandle_ = resources.loadGraph("media\\player\\DataWindow.png");
    timeWindowHandle_ = resources.loadGraph("media\\player\\TimeWindow.png");
    dataWindow2Frames_ = resources.loadDivGraph("media\\player\\DataWindow2.png", 10, 10, 1, 60, 60);
    playerFrameFrames_ = resources.loadDivGraph("media\\player\\PlayerFrame.png", 0x1e, 10, 3, 0x154, 0x2d0);
    stateFrames_ = resources.loadDivGraph("media\\player\\State.png", 0x20, 1, 0x20, 200, 0x28);
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
    shotHitSoundHandle_ = resources.soundHandleById("SE_se_Shothit");
    shotHit2SoundHandle_ = resources.soundHandleById("SE_se_Shothit2");
    item1SoundHandle_ = resources.soundHandleById("SE_se_Item1");
    item3SoundHandle_ = resources.loadSound("media\\se\\Item3.wav", 3);
    extendSoundHandle_ = resources.loadSound("media\\se\\Extend.wav", 3);
    blast1SoundHandle_ = resources.loadSound("media\\se\\Blast1.wav", 3);
    enemyDown1SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown1");
    enemyDown2SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown2");
    enemyDown3SoundHandle_ = resources.soundHandleById("SE_se_EnemyDown3");

    config_ = config;
    selectedStage_ = (config.stage >= 1 && config.stage <= 4) ? config.stage : 1;
    config_.stage = selectedStage_;
    config_.controlDevice = std::clamp(config_.controlDevice, 0, 5);
    config_.controlModeEnabled = config_.controlModeEnabled != 0 ? 1 : 0;
    config_.helpMode = std::clamp(config_.helpMode, 0, 6);
    config_.helpAutoProgress = std::max(config_.helpAutoProgress, 0);
    config_.specialMode = config_.specialMode != 0 ? 1 : 0;
    config_.dataWindowEnabled = config_.dataWindowEnabled != 0 ? 1 : 0;
    config_.soundEffectVolume = std::clamp(config_.soundEffectVolume, 0, 10);
    config_.itemVisibility = config_.itemVisibility != 0 ? 1 : 0;
    config_.likeStyle = config_.likeStyle != 0 ? 1 : 0;
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
    const int normalized = (next.stage >= 1 && next.stage <= 4) ? next.stage : 1;
    next.stage = normalized;
    next.controlDevice = std::clamp(next.controlDevice, 0, 5);
    next.controlModeEnabled = next.controlModeEnabled != 0 ? 1 : 0;
    next.helpMode = std::clamp(next.helpMode, 0, 6);
    next.helpAutoProgress = std::max(next.helpAutoProgress, 0);
    next.specialMode = next.specialMode != 0 ? 1 : 0;
    next.dataWindowEnabled = next.dataWindowEnabled != 0 ? 1 : 0;
    next.soundEffectVolume = std::clamp(next.soundEffectVolume, 0, 10);
    next.itemVisibility = next.itemVisibility != 0 ? 1 : 0;
    next.likeStyle = next.likeStyle != 0 ? 1 : 0;
    const bool changed = selectedStage_ != normalized || config_.routeMode != next.routeMode ||
                         config_.setupGroup != next.setupGroup ||
                         config_.playerOption != next.playerOption || config_.subOption != next.subOption ||
                         config_.loadoutId != next.loadoutId || config_.difficulty != next.difficulty ||
                         config_.counterMode != next.counterMode || config_.optionSlots != next.optionSlots ||
                         config_.specialMode != next.specialMode ||
                         config_.dataWindowEnabled != next.dataWindowEnabled ||
                         config_.soundEffectVolume != next.soundEffectVolume ||
                         config_.itemVisibility != next.itemVisibility ||
                         config_.likeStyle != next.likeStyle ||
                         config_.controlModeEnabled != next.controlModeEnabled || config_.helpMode != next.helpMode ||
                         config_.helpAutoProgress != next.helpAutoProgress;
    config_ = next;
    selectedStage_ = normalized;
    if (changed) {
        reset();
    }
    return changed;
}

void StageRuntime::reset() {
    frame_ = 0;
    player_ = {};
    player_.stockProgress = stockThresholdForCurrentConfig() * player_.lives;
    player_.optionX.fill(player_.x);
    player_.optionY.fill(player_.y);
    nextEntityId_ = 1;
    enemies_.reserve(kStageEntityCap);
    enemyProjectiles_.reserve(kProjectileCap);
    playerSideObjects_.reserve(kPlayerSideObjectCap);
    rewardItems_.reserve(kRewardItemCap);
    stageEffects_.reserve(kStageEffectCap);
    stage01GateFlag_ = false;
    stage02GateFlag_ = false;
    stage03GateFlag_ = false;
    stage01EndVisualQueued_ = false;
    stage01EndFlushed_ = false;
    stage01BossSpawned_ = false;
    stage01BossPhaseMode_ = 0;
    stage01BossMaxHp_ = 100000;
    stage01BossCountdown_ = 0;
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
    inputActions_.fill(false);
    paused_ = false;
    pauseInputHeld_ = false;
    enemies_.clear();
    pendingEnemies_.clear();
    enemyProjectiles_.clear();
    playerSideObjects_.clear();
    rewardItems_.clear();
    stageEffects_.clear();
}

void StageRuntime::update() {
    if (!initialized_) {
        return;
    }

    pollInput();
    const bool pauseDown = actionDown(InputAction::Pause);
    if (pauseDown && !pauseInputHeld_) {
        paused_ = !paused_;
    }
    pauseInputHeld_ = pauseDown;
    if (paused_) {
        return;
    }

    updateLayoutGuideToggle();

    if (CheckHitKey(KEY_INPUT_R) != 0) {
        reset();
        return;
    }
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
    enemies_.erase(std::remove_if(enemies_.begin(), enemies_.end(), [](const StageEnemy& enemy) {
                       return !enemy.active || offscreen(enemy.x, enemy.y, 4096.0f);
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

    spawnDueEvents();
    updatePlayer();
    updatePlayerSideObjects();
    updateEnemies();
    updateStageEffects();
    updateProjectiles();
    updateRewardItems();
    handleCollisions();

    ++frame_;
}

void StageRuntime::draw() const {
    drawBackground();
    drawPlayerSideObjects();
    drawStageEffects(false);
    drawEnemies();
    drawProjectiles();
    drawStageEffects(true);
    drawRewardItems();
    drawPlayer();
    drawStage02BossHud();
    drawStage03BossHud();
    drawOverlay();
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

void StageRuntime::spawnDueEvents() {
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
    // This replaces the older 25-row approximation for Stage 1; enemy behavior
    // still falls back to the current generic/update-helper paths until the
    // individual original helpers are ported.
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
    if (f == 0xe10) spawn(0x0e, 7000, 0x168, 0, "S01 original line 159: later 0x0e setpiece");
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
    if (f >= stage01EndFrame_ - 300 && f <= stage01EndFrame_) {
        enemyProjectiles_.clear();
    }
    if (f == stage01EndFrame_) {
        enemyProjectiles_.clear();
        playerSideObjects_.clear();
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
    if (f == 9500 + 0x3c) {
        spawn(0x13a, 100000, 360, 200, "S03 boss handoff: endFrame + 0x3c entity 0x13a");
    }
}

void StageRuntime::spawnStage04OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto spawnEvery = [&](int start, int duration, int step, int type, int hitPoints, int x, int y, const char* note) {
        const int local = f - start;
        if (local >= 0 && local < duration && local % step == 0) {
            spawn(type, hitPoints, x, y, note);
        }
    };
    auto stageRand = [](int seed, int salt) -> std::uint32_t {
        std::uint32_t u = (static_cast<std::uint32_t>(seed) >> 30 ^ static_cast<std::uint32_t>(seed)) * 0x6c078965u + 1u + static_cast<std::uint32_t>(salt);
        std::uint32_t a = (u >> 30 ^ u) * 0x6c078965u + 2u;
        std::uint32_t b = (a >> 30 ^ a) * 0x6c078965u + 3u;
        std::uint32_t c = (b >> 30 ^ b) * 0x6c078965u + 4u;
        std::uint32_t mixed = u * 0x800u ^ u;
        return (mixed ^ (c >> 11)) >> 8 ^ mixed ^ c;
    };
    auto randX = [&](int modulus, int base, int salt = 0) { return static_cast<int>(stageRand(f, salt) % static_cast<std::uint32_t>(modulus)) + base; };
    auto randY = [&](int modulus, int base, int salt = 9) { return static_cast<int>(stageRand(f, salt) % static_cast<std::uint32_t>(modulus)) + base; };
    auto spawn37 = [&](int modulusX, int baseX, const char* note) {
        spawn(0x37, 500, randX(modulusX, baseX), randY(0x97, 400), note);
    };
    auto spawn36Left = [&](const char* note) { spawn(0x36, 400, -20, randX(0xc9, 300, 3), note); };
    auto spawn36Right = [&](const char* note) { spawn(0x36, 400, 0x2e4, randX(0xc9, 300, 5), note); };
    auto spawn0bTop = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, randX(modulus, base, 7), -20, note); };
    auto spawn0bLeft = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, -20, randX(modulus, base, 11), note); };
    auto spawn0bRight = [&](int hitPoints, int modulus, int base, const char* note) { spawn(0x0b, hitPoints, 0x2e4, randX(modulus, base, 13), note); };

    // Stage 04 schedule transcribed from stage_04_gameplay_update_candidate. Random expressions use a deterministic stand-in for DAT_140e9fd1c/DAT_140e9fd18 until the RNG update globals are fully ported.
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
    if (f == 0xe10) spawn(0x3f, 48000, 0x167, 0, "S04 original row 235: 0x3f controller");
    spawnEvery(0xe74, 999, 8, 0x35, 200, 0x2e4, 0x8c, "S04 original row 256: 0x35 boss-side right");
    spawnEvery(0xe74, 999, 8, 0x35, 200, -20, 0x8c, "S04 original row 257: 0x35 boss-side left");
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
    if (f == 0x2648) spawn(0x3f, 44000, 0x169, 0, "S04 original row 556: 0x3f second controller");
    if (f >= 0x28a0 && f < 0x28a0 + 300 && (f - 0x28a0) % 0x28 == 0) spawn0bTop(300, 0x1e1, 0x78, "S04 original row 568: 0x0b late wide");
    if (f >= 0x2648 && f - 0x2648 < 0x385 && (f - 0x2648) % 100 == 0) spawn(0x38, 5000, randX(0x169, 0xb4, 19), 0, "S04 original row 580: 0x38 random late");
    if (f == 0x2a30) { spawn(0x38, 4000, 0x1e0, 0, "S04 original row 584: 0x38 end pair"); spawn(0x38, 4000, 0xf0, 0, "S04 original row 585: 0x38 end pair"); }
    spawnEvery(0x2a94, 0x5a, 8, 0x35, 200, 0x2e4, 0x78, "S04 original row 594: 0x35 ending right");
    spawnEvery(0x2aee, 0x5a, 8, 0x35, 200, -20, 0x96, "S04 original row 604: 0x35 ending left");
    if (f == 0x2b5c) spawn(8, 5000, 0x104, 0, "S04 original row 609: ending marker");

    // UNK_140538ad8[4] is 11700. FUN_14011cdd0 hands the cleared stage to
    // root boss 0x13b at endFrame + 0x3c.
    if (f == 11700 + 0x3c) {
        spawn(0x13b, 100000, 360, 120,
              "S04 boss handoff: endFrame + 0x3c entity 0x13b");
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

    switch (event.spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        enemy.hp = 28;
        enemy.radius = 40;
        enemy.visualFrame = 8;
        enemy.vy = 0.25f;
        break;
    case 0x09:
        enemy.hp = 10;
        enemy.radius = 18;
        enemy.visualFrame = 11;
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
        stage01BossPhaseMode_ = 0;
        stage01BossMaxHp_ = 100000;
        stage01BossCountdown_ = 0;
        stage01BossBreaksRemaining_ = 4;
        stage01BossPhaseIndex_ = 0;
        stage01ClearStarted_ = false;
        stage01ClearTransition_ = false;
        stage01ClearComplete_ = false;
        break;
    default:
        enemy.hp = 12;
        enemy.radius = 28;
        enemy.visualFrame = 8;
        enemy.speed = 1.2f;
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
    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x11;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(parent.x + offsetX));
    child.sourceY = static_cast<int>(std::lround(parent.y + offsetY));
    child.sourceNote = note;
    child.updateCase = stage01UpdateCaseForSpawnType(0x11);
    child.sourceDispatchKind = stage01DispatchKindForSpawnType(0x11);
    child.sourceDispatchField = stage01DispatchFieldForSpawnType(0x11);
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = childIndex;
    child.x = parent.x + offsetX;
    child.y = parent.y + offsetY;
    child.originX = offsetX;
    child.originY = offsetY;
    child.angle = parent.angle;
    child.sourceAngle16 = parent.sourceAngle16;
    child.secondaryAngle16 = parent.sourceAngle16;
    child.hp = std::max(1, static_cast<int>(hitPoints * (config_.difficulty == 0 ? 0.8 : 1.0)));
    child.maxHp = child.hp;
    child.radius = 22;
    child.visualFrame = 32 + (childIndex % 2);
    child.activationDelay = 0;
    child.helperState = 0;
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
    child.updateCase = spawnType;
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
    StageEnemy satellite;
    satellite.entityId = nextEntityId_++;
    satellite.spawnType = 0x09;
    satellite.sourceHitPoints = hitPoints;
    satellite.sourceX = static_cast<int>(std::lround(parent.x + offsetX));
    satellite.sourceY = static_cast<int>(std::lround(parent.y + offsetY));
    satellite.sourceNote = note;
    satellite.updateCase = stage01UpdateCaseForSpawnType(0x09);
    satellite.sourceDispatchKind = stage01DispatchKindForSpawnType(0x09);
    satellite.sourceDispatchField = stage01DispatchFieldForSpawnType(0x09);
    satellite.parentEntityId = parent.entityId;
    satellite.parentSpawnType = parent.spawnType;
    satellite.childIndex = childIndex;
    satellite.x = parent.x + offsetX;
    satellite.y = parent.y + offsetY;
    satellite.originX = offsetX;
    satellite.originY = offsetY;
    satellite.angle = parent.angle;
    satellite.sourceAngle16 = normalizeAngle16(childIndex * 0x5555);
    satellite.secondaryAngle16 = satellite.sourceAngle16;
    satellite.hp = std::max(1, static_cast<int>(hitPoints * (config_.difficulty == 0 ? 0.8 : 1.0)));
    satellite.maxHp = satellite.hp;
    satellite.radius = 18;
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

void StageRuntime::spawnStage03DeathNode(const StageEnemy& enemy, int hitPoints,
                                         int ownerEntityId) {
    (void)enemy;
    if (enemies_.size() + pendingEnemies_.size() >= kStageEntityCap) {
        return;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = 0x153;
    node.sourceHitPoints = hitPoints;
    node.sourceX = -100;
    node.sourceY = -100;
    node.sourceNote = "S03 child death delayed-damage node 0x153";
    node.updateCase = 0xb5;
    node.sourceDispatchKind = 1;
    node.sourceDispatchField = 10;
    node.parentEntityId = ownerEntityId;
    node.parentSpawnType = 0x13a;
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

    constexpr std::array<std::array<double, 2>, 3> kMovementSpeeds{{
        {{7.5, 4.0}}, {{7.9, 4.1}}, {{8.3, 4.2}},
    }};
    float nextX = player_.x;
    float nextY = player_.y;
    if (player_.playerStateTimer < 180 && (upDown || downDown || rightDown || leftDown)) {
        const int group = std::clamp(config_.setupGroup, 0, 2);
        const double speed = kMovementSpeeds[static_cast<std::size_t>(group)][player_.focused ? 1U : 0U];
        const double angle = fixedAngleToRadiansDouble(player_.movementAngle16);
        nextX += static_cast<float>(std::cos(angle) * speed * 1.2);
        nextY += static_cast<float>(std::sin(angle) * speed);
    }
    const float horizontalOrigin = nextX / 6.0f;
    player_.x = clampFloat(nextX, horizontalOrigin + 4.0f, horizontalOrigin + 596.0f);
    player_.y = clampFloat(nextY, 4.0f, 716.0f);
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
    if (player_.playerStateTimer >= 180 || player_.bombLock > 0) {
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
    updateSpecialGaugeAction();
    if (settlePendingPlayerHit()) {
        return;
    }
    if (player_.playerStateTimer > 0) {
        --player_.playerStateTimer;
    }
    processStockProgressAfterGain(0);
    updateSpecialGaugeState();
    if (player_.shotVariant > 0) {
        --player_.shotVariant;
    }
    if (player_.invulnerableFrames > 0) {
        --player_.invulnerableFrames;
    }
}

void StageRuntime::updatePlayerOptions() {
    // FUN_14010cc90 keeps four persistent option nodes. Most configurations
    // select a fixed offset/angle row; node positions close 25% of the remaining
    // distance each frame and angles use the original delta/10 + 0x80 turn step.
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
    const bool rotatingUnfocusedFormation = !player_.focused &&
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

    for (int slot = 0; slot < 4; ++slot) {
        float offsetX = 0.0f;
        float offsetY = 0.0f;
        std::uint16_t targetAngle = 0xc000;
        const std::size_t offsetIndex = static_cast<std::size_t>(slot * 2);

        if (!player_.focused) {
            if (group == 1 && option0 == 1) {
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
        }
        else if (group == 0 && option1 == 0) {
            // The original may assign an enemy ID to each node here. Until that
            // ID list is represented, retain its exact no-target formation.
            offsetX = kFocusedGroup0Option0Offsets[offsetIndex];
            offsetY = kFocusedGroup0Option0Offsets[offsetIndex + 1];
            targetAngle = kUpAngles[static_cast<std::size_t>(slot)];
        }
        else if (group == 0) {
            offsetX = kFocusedNarrowOffsets[offsetIndex];
            offsetY = kFocusedNarrowOffsets[offsetIndex + 1];
            targetAngle = kFocusedGroup0Option1Angles[static_cast<std::size_t>(slot)];
        }
        else if (group == 1) {
            offsetX = kFocusedNarrowOffsets[offsetIndex];
            offsetY = kFocusedNarrowOffsets[offsetIndex + 1];
            targetAngle = option1 == 0
                ? kFocusedGroup1Option0Angles[static_cast<std::size_t>(slot)]
                : kUpAngles[static_cast<std::size_t>(slot)];
        }
        else if (option1 == 0) {
            offsetX = kFocusedGroup2Option0Offsets[offsetIndex];
            offsetY = kFocusedGroup2Option0Offsets[offsetIndex + 1];
            targetAngle = player_.optionFormationAngle16;
        }
        else {
            // FUN_14010cc90 can move the shared anchor toward the nearest enemy;
            // these are the exact per-node offsets/angles for its no-target path.
            offsetX = kFocusedGroup2Option1Offsets[offsetIndex];
            offsetY = kFocusedGroup2Option1Offsets[offsetIndex + 1];
            targetAngle = kFocusedGroup2Option1Angles[static_cast<std::size_t>(slot)];
        }

        const float targetX = player_.x + offsetX;
        const float targetY = player_.y + offsetY;
        player_.optionX[static_cast<std::size_t>(slot)] +=
            (targetX - player_.optionX[static_cast<std::size_t>(slot)]) * 0.25f;
        player_.optionY[static_cast<std::size_t>(slot)] +=
            (targetY - player_.optionY[static_cast<std::size_t>(slot)]) * 0.25f;

        const std::uint16_t currentAngle = player_.optionAngle16[static_cast<std::size_t>(slot)];
        int delta = static_cast<int>(targetAngle) - static_cast<int>(currentAngle);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        const int turnStep = std::abs(delta) / 10 + 0x80;
        player_.optionAngle16[static_cast<std::size_t>(slot)] =
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
        const bool stage03Exact = isStage03FocusedType(enemy.spawnType);
        const bool stage03BossRoot = enemy.spawnType == 0x13a;
        const bool stage03BossChild = isStage03BossChildType(enemy.spawnType) &&
                                      enemy.parentSpawnType == 0x13a;
        const bool stage03BossNode = stage03BossRoot || stage03BossChild;
        const bool stage03DeathNode = enemy.spawnType == 0x153 &&
                                      enemy.parentSpawnType == 0x13a;
        const bool unportedBossScaffold = enemy.spawnType == 0x13b;
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
        const bool stage01BossChild = isStage01BossChildType(enemy.spawnType);
        const bool stage01BossNode = stage01BossRoot || stage01BossChild;
        const bool stage02BossRoot = enemy.spawnType == 0x139;
        const bool stage02BossChild = enemy.spawnType >= 0x22 && enemy.spawnType <= 0x24 &&
                                      enemy.parentSpawnType == 0x139;
        const bool stage02BossNode = stage02BossRoot || stage02BossChild;
        const bool postDeathCounter = enemy.spawnType == 0x137;
        // Entity helpers own the +0x1c < 1 death branch. Collision only writes
        // HP; cleanup/rewards happen when the helper runs on the next frame.
        if (enemy.hp < 1 && !sharedType0A && !sharedType0B && !sharedType0C &&
            !sharedType0D && !sharedType0E && !sharedType0F &&
            !stage01Type10 && !stage01BossNode && !stage02BossNode && !postDeathCounter &&
            !stage03Exact && !stage03BossNode && !stage03DeathNode && !unportedBossScaffold &&
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
        else if (unportedBossScaffold) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
        }
        else if (isStage01ObservedType(enemy.spawnType)) {
            updateStage01Enemy(enemy, activeAge);
        }
        else if (isStage04FocusedType(enemy.spawnType)) {
            updateStage04Enemy(enemy, activeAge);
        }
        else {
            updateGenericEnemy(enemy, activeAge);
        }

        const bool stage04PreMovementFire = stage04SimpleExact;
        const bool stage04OwnsHelperTimer = stage04PreMovementFire || stage04Type38 || carrierFamily ||
                                            stage04Type3DFamily || stage04Type3F;
        const bool ownsHelperTimer = sharedType0B || sharedType0C || sharedType0D ||
                                     sharedType0E || sharedType0F ||
                                     stage01Type10 || stage01BossNode || stage02BossNode ||
                                     postDeathCounter || stage02Exact ||
                                     stage03Exact || stage03BossNode || stage03DeathNode ||
                                     unportedBossScaffold ||
                                     stage04OwnsHelperTimer;
        if (stage04PreMovementFire) {
            // These helpers emit from the pre-movement point.
            emitStage04Projectiles(enemy, enemy.helperTimer);
        }

        if (!stage01BossNode && !stage02BossNode && !stage03BossNode &&
            !stage03DeathNode && !postDeathCounter && !stage02Exact) {
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
                 unportedBossScaffold) {
            // Stage 3 exact helpers emit internally from the original
            // pre/post-movement source coordinates. The boss scaffold is kept
            // out of the generic emitter until FUN_14000ed10 is represented.
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
            emitStage01Projectiles(enemy, activeAge);
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
        else {
            emitGenericProjectiles(enemy, activeAge);
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
            }
        }
        if (ownsHelperTimer) {
            if (!stage01BossNode && !stage02BossNode) {
                enemy.drawHelperState = enemy.helperState;
                enemy.drawHelperTimer = enemy.helperTimer;
            }
            ++enemy.helperTimer;
            if (enemy.targetable) {
                ++enemy.targetableTimer;
            }
        }
        else if (sharedType0A && enemy.targetable) {
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
                                               : (selectedStage_ == 3 && stage03GateFlag_));
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

void StageRuntime::spawnStageEffect(int type, int graphHandle, int graphExtent, int drawLayer,
                                    float x, float y, std::uint16_t angle16,
                                    double scale0, double scaleX, double scaleY,
                                    int lifetime, int colorR, int colorG, int colorB, int alpha) {
    const bool graphlessFamily = type == 0x1a || type == 0x1d;
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
    if (type == 0x2c) {
        effect.randomSeed = static_cast<std::uint32_t>(angle16) +
                            static_cast<std::uint32_t>(frame_);
    }
    stageEffects_.push_back(effect);
}

void StageRuntime::updateStageEffects() {
    for (auto& effect : stageEffects_) {
        effect.drawQueuedThisFrame = false;
        if (!effect.active) {
            continue;
        }

        const int age = effect.age;
        switch (effect.type) {
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
        case 0x1a:
        case 0x1d:
            // These nodes drive graph families that are not represented by the
            // compact renderer. Preserve their exact allocation and lifetime.
            if (age == effect.lifetime) {
                effect.active = false;
            }
            break;
        case 0x2a:
        case 0x2b: {
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
        case 0x37:
            effect.y += 1.0f;
            effect.drawX = effect.x;
            effect.drawY = effect.y;
            effect.drawAngle16 = effect.angle16;
            effect.drawScaleX = effect.scaleX;
            effect.drawScaleY = effect.scaleY;
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
        default:
            effect.active = false;
            break;
        }
        ++effect.age;
    }
}

void StageRuntime::updateStage03Enemy(StageEnemy& enemy) {
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
        enemy.markerDrawX = clampFloat(enemy.x + wobble, horizontalOrigin - 20.0f,
                                      horizontalOrigin + 620.0f);
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
        const auto target = radiansToFixedAngleTrunc(static_cast<double>(aimAtPlayer(enemy.x, enemy.y)));
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
            enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
                static_cast<double>(aimAtPlayer(enemy.x, enemy.y + 40.0f)));
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
    const int window = type28 ? 40 : 30;
    if (phase == 0) {
        enemy.secondaryAngle16 = radiansToFixedAngleTrunc(
            static_cast<double>(aimAtPlayer(parent->x, parent->y)));
    }
    if (phase <= window && phase % 5 == 0) {
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
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }
    else if (enemy.helperState == 2) {
        enemy.y += static_cast<float>(enemy.helperTimer) * 0.1f;
        if (enemy.helperTimer == 60) {
            spawnEnemyDeathEffects(enemy, 2);
            enemy.active = false;
        }
    }

    if (enemy.helperState != 2 &&
        (enemy.x < horizontalOrigin - 200.0f || enemy.x > horizontalOrigin + 800.0f ||
         enemy.y < -200.0f || enemy.y > 920.0f)) {
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
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
        }
    }
    else if (enemy.helperState == 2) {
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
        spawnPostDeathCounterEntity(enemy, 140.0);
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
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
        enemy.maxHp = hitPoints;
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
            spawnEnemyDeathRewardBurst(enemy, 1800);
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
    if (owner == nullptr || owner->spawnType != 0x13a || !owner->active) {
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
        // Other Stage 1 helper bodies are not fully ported yet, so retain the
        // previous playable movement as an explicit fallback behind the Stage
        // 1-specific dispatch point.
        updateGenericEnemy(enemy, activeAge);
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
    // Remaining broad FUN_140080fb0 controller path. Types 0x0e and 0x0f use
    // their dedicated exact helpers before this dispatcher is reached.
    if (enemy.spawnType == 0x10 && enemy.hp < 1 && enemy.helperState < 2) {
        spawnEnemyDeathRewardBurst(enemy, 0x708);
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        enemy.helperState = 2;
        enemy.helperTimer = 0;
        enemy.targetable = false;
    }
    if (enemy.spawnType == 0x10 && enemy.helperState == 2) {
        const int timer = enemy.helperTimer;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.speed = 0.0f;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
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
        const float t = clampFloat(static_cast<float>(activeAge) / 20.0f, 0.0f, 1.0f);
        enemy.y = enemy.originY - (1.0f - t) * 50.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= 0x14) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.helperTimer = 0;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            enemy.sourceSpeed = 0.7;
        }
        return;
    }

    const int stateAge = enemy.age;
    if (enemy.spawnType == 0x10) {
        if (enemy.helperState == 1 && stateAge == 1) {
            spawnStage01Child(enemy, 0, -42.0f, 16.0f, 920, "S01 0x10 child 0x11 left anchor from FUN_140080fb0");
            spawnStage01Child(enemy, 1, 42.0f, 16.0f, 920, "S01 0x10 child 0x11 right anchor from FUN_140080fb0");
        }
        if (enemy.helperState == 1 && stateAge < 900) {
            if (stateAge % 0x14 == 0) {
                enemy.originX = static_cast<float>(stageRandCoord(frame_, 0x141, 200));
                enemy.originY = static_cast<float>(stageRandCoord(frame_ + 0x457, 0x29, 0xb4));
            }
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, radiansToFixedAngle(std::atan2(enemy.originY - enemy.y, enemy.originX - enemy.x)), 0x200);
        }
        else {
            enemy.sourceAngle16 = 0xc000;
            enemy.sourceSpeed = std::max(enemy.sourceSpeed, (stateAge - 900) / 60.0);
        }
        if (enemy.helperState == 1 && stateAge == 900) {
            spawnRewardItem(6, enemy.x, enemy.y, radiansToFixedAngle(-kPi * 0.5f), 2.0f, 18);
        }
        enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
        enemy.vx = std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        enemy.vy = std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed);
        return;
    }

    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)), 0x80);
    if (stateAge > 300) {
        enemy.sourceSpeed = std::max(1.2, enemy.sourceSpeed - 1.0 / 60.0);
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    const float wobble = std::sin((stateAge + enemy.spawnType * 23) * 0.025f) * 0.9f;
    enemy.vx = std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed) * 0.15f + wobble;
    enemy.vy = std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed) * 0.12f;
}

void StageRuntime::updateStage01Marker(StageEnemy& enemy, int activeAge) {
    // FUN_140082d90 handles the common 0x06..0x08 marker family. On frame 0x14,
    // type 0x06 creates Help-level type-0x09 satellites in routes 0 and 1;
    // type 0x07 does so only in route 0, while type 0x08 never creates them.
    if (enemy.helperState == 0) {
        if (activeAge >= 0x14) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = 1.0;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            const bool createsHelpSatellites =
                (enemy.spawnType == 0x06 && (config_.routeMode == 0 || config_.routeMode == 1)) ||
                (enemy.spawnType == 0x07 && config_.routeMode == 0);
            const int satelliteCount = createsHelpSatellites ? effectiveHelpLevel() : 0;
            for (int childIndex = 0; childIndex < satelliteCount; ++childIndex) {
                spawnStage01MarkerSatellite(enemy, childIndex, 0.0f, 0.0f, 3000,
                                            "FUN_140082d90 Help satellite type 0x09");
            }
        }
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        return;
    }
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)), 0x14);
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.vx = std::sin(enemy.age * 0.018f) * 0.35f;
    enemy.vy = 0.05f;
}

void StageRuntime::updateStage01MarkerSatellite(StageEnemy& enemy, int activeAge) {
    // FUN_140083db0: child/satellite type spawned by marker helper 0x06/0x07.
    // It resolves its marker parent, spins around parent-derived coordinates,
    // drops reward type 7 when the parent is gone, and otherwise mostly exists
    // as a visual/effect satellite.
    StageEnemy* parent = nullptr;
    for (auto& candidate : enemies_) {
        if (candidate.entityId == enemy.parentEntityId && candidate.active) {
            parent = &candidate;
            break;
        }
    }
    if (parent == nullptr) {
        spawnRewardItem(7, enemy.x, enemy.y, radiansToFixedAngle(-kPi * 0.5f), stage01SpeedConstantValue(0x070), 18);
        enemy.active = false;
        return;
    }
    if (enemy.helperState == 0) {
        enemy.helperState = 1;
        enemy.sourceAngle16 = scriptRandomAngle(static_cast<std::uint32_t>(enemy.entityId + 0x6f));
    }
    const float orbit = activeAge > 60 ? 60.0f : 38.0f + activeAge * 0.35f;
    enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + 0x200);
    const float targetX = parent->x + std::cos(fixedAngleToRadians(enemy.sourceAngle16)) * orbit;
    const float targetY = parent->y + std::sin(fixedAngleToRadians(enemy.sourceAngle16)) * orbit * 0.65f;
    enemy.vx = (targetX - enemy.x) * 0.12f;
    enemy.vy = (targetY - enemy.y) * 0.12f;
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
}

void StageRuntime::updateStage01Child(StageEnemy& enemy, int activeAge) {
    // FUN_140082090: child type 0x11 resolves a parent entity by id, starts by
    // following parent-relative offsets, then switches to an aimed state that
    // emits visual selectors 7 and 9 with their original movement IDs. Parent-id lookup is represented by the
    // captured parent entity id; if the parent is gone, the child expires.
    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != enemy.parentSpawnType) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
        return;
    }
    if (parent->hp < 1) {
        spawnEnemyDeathEffects(enemy, 1);
        enemy.active = false;
        return;
    }
    if (!parent->active) {
        enemy.active = false;
        return;
    }

    if (enemy.helperState == 0) {
        const float t = clampFloat(static_cast<float>(activeAge) / 120.0f, 0.0f, 1.0f);
        const float wobble = std::sin((activeAge + enemy.childIndex * 37) * 0.09f) * 10.0f * (1.0f - t);
        enemy.x = parent->x + enemy.originX * t + wobble;
        enemy.y = parent->y + enemy.originY * t;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= 0x78) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = 1.0;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            enemy.secondaryAngle16 = enemy.sourceAngle16;
        }
        return;
    }

    const int stateAge = enemy.age;
    const float parentPull = enemy.parentSpawnType == 0x10 ? 0.018f : 0.035f;
    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    enemy.vx = (targetX - enemy.x) * parentPull;
    enemy.vy = (targetY - enemy.y) * parentPull;
    const std::uint16_t targetAngle = stateAge < 300
                                          ? radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y))
                                          : parent->sourceAngle16;
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, targetAngle, stateAge < 300 ? 0x20 : 0x60);
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
}

void StageRuntime::updateStage01Boss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    const auto steeringTarget = radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(stage01BossTargetY_ - enemy.y),
                   static_cast<double>(stage01BossTargetX_ - enemy.x)));
    if (frame_ % 50 == 0) {
        stage01BossTargetX_ = static_cast<float>(stageRandCoord(frame_, 301, 210));
        stage01BossTargetY_ = static_cast<float>(
            stageRandCoord(frame_ + selectedStage_ * 111, 101, 150));
    }

    if (stage01BossPhaseMode_ == 1 && (enemy.hp < 1 || stage01BossCountdown_ < 1)) {
        spawnPostDeathCounterEntity(enemy, 140.0);
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
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
    if (stage01BossPhaseMode_ == 1) {
        --stage01BossCountdown_;
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
        spawnPostDeathCounterEntity(enemy, 140.0);
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
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
        // FUN_140080fb0: Stage 1 long controller. Original spawns child type
        // 0x11 anchors; this runtime now creates those anchors and leaves most
        // controller volleys to the children, while keeping a light parent phase
        // so the controller remains a visible pattern source.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        if (enemy.age < 0x1e || enemy.age >= 900) return;
        const int local = (enemy.age - 0x1e) % (difficulty == 0 ? 100 : difficulty == 1 ? 0x50 : difficulty == 2 ? 0x46 : difficulty == 3 ? 0x3c : 0x32);
        if (local > 0x13 || local % 3 != 0) return;
        int count = difficulty == 0 ? 5 : difficulty == 1 ? 7 : difficulty < 4 ? 9 : 0xb;
        if (enemy.age > 0xf0) count += 2;
        const float speed = stage01DecodedSpeedForOffsets(difficulty, selectedStage_, {0x018, 0x070, 0x0b0, 0x0f8, 0x138}, {0x088, 0x0d0, 0x0f8, 0x138, 0x138}) + enemy.age * 0.0006f;
        spawnProjectileSpread(0, 0, enemy.x, enemy.y + 20.0f, aimAtPlayer(enemy.x, enemy.y), speed, 5, count, kPi * 0.75f);
        if (difficulty > 2) {
            spawnProjectileSpread(0, 0, enemy.x, enemy.y + 20.0f, aimAtPlayer(enemy.x, enemy.y), speed - 0.35f, 5, std::max(2, count - 1), kPi * 0.55f);
        }
        return;
    }

    if (enemy.spawnType == 0x11) {
        // FUN_140082090 child helper: after the 0x78-frame attach state it emits
        // visual selector 7 during the first 300 aimed frames, then selector 9 arced
        // volleys from the later state. Difficulty tables/constants are still
        // approximated, but ids/cadence/state split match the decompile.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int stateAge = enemy.age;
        const int earlyInterval = difficulty == 0 ? 0x3c : difficulty == 1 ? 0x20 : difficulty == 2 ? 0x18 : difficulty == 3 ? 0x14 : 0x10;
        const float baseSpeed = stage01DecodedSpeedForOffsets(difficulty, selectedStage_, {0x040, 0x088, 0x0b0, 0x118, 0x118}, {0x040, 0x088, 0x0b0, 0x118, 0x118});
        if (stateAge < 300 && earlyInterval > 0 && stateAge % earlyInterval == 0) {
            const std::uint16_t wave = normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + static_cast<int>(std::sin(stateAge * 0.11f) * 0x500));
            spawnProjectileNode(7, 0, enemy.x, enemy.y, wave, 0.0f, baseSpeed, 5, 1);
            spawnProjectileNode(7, 0, enemy.x, enemy.y, wave, 0.0f, baseSpeed + 0.35f, 5, 1);
            if (difficulty > 2) {
                spawnProjectileNode(7, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(wave) - 0x400), 0.0f, baseSpeed + 0.15f, 5, 1);
                spawnProjectileNode(7, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(wave) + 0x400), 0.0f, baseSpeed + 0.15f, 5, 1);
            }
        }
        const int lateAge = stateAge - 0x186;
        const int lateInterval = difficulty == 0 ? 100 : difficulty == 1 ? 0x50 : difficulty == 2 ? 0x46 : difficulty == 3 ? 0x3c : 0x32;
        if (lateAge >= 0 && lateAge < 0x1fe && lateInterval > 0) {
            const int local = lateAge % lateInterval;
            if (local < 0x19 && local % 3 == 0) {
                const int count = difficulty < 2 ? 1 : difficulty < 4 ? 2 : 3;
                const float speed = stage01DecodedSpeedForOffsets(difficulty, selectedStage_, {0x018, 0x0f8, 0x138, 0x190, 0x190}, {0x018, 0x0f8, 0x138, 0x190, 0x190}) + local * 0.015f;
                spawnProjectileSpread(9, 0, enemy.x, enemy.y, enemy.sourceAngle16, 0.0f, speed, 7, count, 0x1800 + difficulty * 0x300, 2);
            }
        }
        return;
    }

    if (enemy.spawnType >= 0x06 && enemy.spawnType <= 0x08) {
        // FUN_140082d90 common marker/emitter selector-0 spread cadence.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int start = difficulty == 0 ? 0x28 : 0x1e;
        const int interval = difficulty == 0 ? 100 : difficulty == 1 ? 0x50 : difficulty < 4 ? 0x3c : 0x32;
        if (enemy.age < start || enemy.age >= 0xf0 || interval <= 0) return;
        const int local = (enemy.age - start) % interval;
        if (local >= 0x1e || local % 5 != 0) return;
        const int count = difficulty == 0 ? 1 : difficulty == 1 ? 3 : difficulty < 4 ? 5 : 7;
        const float speed = stage01MarkerProjectileSpeed(difficulty) + local * 0.01f;
        spawnProjectileSpread(0, 0, enemy.x, enemy.y + 26.0f, fixedAngleToRadians(enemy.secondaryAngle16 ? enemy.secondaryAngle16 : enemy.sourceAngle16), speed, 5, count, kPi * 0.6f);
        if (difficulty > 2) {
            spawnProjectileSpread(0, 0, enemy.x, enemy.y + 26.0f, fixedAngleToRadians(enemy.sourceAngle16), speed - 0.45f, 5, count, kPi * 0.5f);
        }
        return;
    }

    // Stage 01 projectile emission belongs in the per-type helpers above once
    // their original callsites are ported. Until then, keep the old generic
    // playable fallback separate so it is not mistaken for original behavior.
    emitGenericProjectiles(enemy, activeAge);
}

void StageRuntime::updateStage04Enemy(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    switch (enemy.spawnType) {
    case 0x35: {
        if (enemy.helperState == 0) {
            enemy.vx = 0.0f;
            enemy.vy = 0.0f;
            if (enemy.helperTimer < 20) {
                break;
            }
            enemy.speed = 12.0f;
            enemy.sourceAngle16 = enemy.originX <= 0.0f ? 0x0000 : 0x8000;
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
            const std::uint32_t random = stageScriptRandFromFrame(frame_ + enemy.entityId * 17);
            const int randomPart = static_cast<int>(random % 5001u);
            enemy.sourceAngle16 = normalizeAngle16(enemy.originX <= 0.0f
                                                       ? -randomPart - 9000
                                                       : randomPart - 23768);
            const float horizontalOrigin = player_.x / 6.0f;
            enemy.x = clampFloat(enemy.x, horizontalOrigin - 20.0f, horizontalOrigin + 620.0f);
            enemy.y = clampFloat(enemy.y, -20.0f, 740.0f);
            enemy.speed = 15.0f;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        const std::uint16_t target = enemy.helperTimer >= 201
                                         ? static_cast<std::uint16_t>(0xc000)
                                         : radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
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
            const std::uint32_t random = stageScriptRandFromFrame(frame_ + enemy.entityId * 31);
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
        const std::uint16_t motionTarget = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
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
            enemy.vy = static_cast<float>(enemy.helperTimer) * 0.06f;
            if (enemy.helperTimer == 60) {
                spawnEnemyDeathEffects(enemy, 2);
                enemy.active = false;
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
        if (enemy.helperState != 1 || enemy.helperTimer >= 200 ||
            enemy.x < horizontalOrigin - 30.0f || enemy.x > horizontalOrigin + 630.0f ||
            enemy.y < -30.0f || enemy.y > 750.0f) {
            return;
        }
        const int interval = kStage04Type35Interval[static_cast<std::size_t>(difficulty)];
        if (frame_ % interval == 0) {
            const auto aim = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y + 20.0f));
            const double speed = kStage04Type35Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(6, 0, enemy.x, enemy.y + 20.0f, aim, 0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(6, 0, enemy.x, enemy.y + 20.0f, aim, 0.0f, speed + 2.2, 1, 0);
            }
        }
        return;
    }
    if (enemy.spawnType == 0x36) {
        const int timer = enemy.helperTimer;
        const float horizontalOrigin = player_.x / 6.0f;
        if (enemy.helperState != 1 || timer < 80 || timer >= 200 ||
            enemy.x < horizontalOrigin || enemy.x > horizontalOrigin + 600.0f ||
            enemy.y < 0.0f || enemy.y > 720.0f) {
            return;
        }
        const int interval = kStage04Type36Interval[static_cast<std::size_t>(difficulty)];
        if (timer % interval == 0) {
            const auto rawAim = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            const auto aim = normalizeAngle16(((static_cast<int>(rawAim) + 0x400) >> 11) * 0x800);
            const double speed = kStage04Type36Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(4, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(aim) - 200), 0.0f, speed, 1, 0);
            spawnProjectileNode(4, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(aim) + 200), 0.0f, speed, 1, 0);
            spawnProjectileNode(4, 0, enemy.x, enemy.y, aim, 0.0f, speed + 0.3, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(4, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(aim) - 750), 0.0f, speed - 0.5, 1, 0);
                spawnProjectileNode(4, 0, enemy.x, enemy.y, normalizeAngle16(static_cast<int>(aim) + 750), 0.0f, speed - 0.5, 1, 0);
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
            enemy.secondaryAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
        }
        const int substep = kStage04Type37Substep[static_cast<std::size_t>(difficulty)];
        if (phase < 24 && phase % substep == 0) {
            const int jitterRange = kStage04Type37Jitter[static_cast<std::size_t>(difficulty)];
            const std::uint32_t random = stageScriptRandFromFrame(frame_ + enemy.entityId * 43 + timer);
            const int jitter = static_cast<int>(random % static_cast<std::uint32_t>(jitterRange * 2 + 1)) - jitterRange;
            const auto angle = normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + jitter);
            const double speed = kStage04Type37Speed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(0, 0, enemy.x, enemy.y, angle, 0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0, 0, enemy.x, enemy.y, angle, 0.0f, speed + 1.2, 1, 0);
            }
            enemy.secondaryAngle16 = approachAngle16(
                enemy.secondaryAngle16,
                radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)), 0x80);
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
        const std::uint16_t fireAim = radiansToFixedAngle(aimAtPlayer(enemy.x, fireY));
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

        // FUN_140095130 performs its active-state volley before entering the
        // dedicated 60-frame death state on the first non-positive HP frame.
        if (enemy.hp < 1) {
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            enemy.targetable = false;
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

void StageRuntime::updateGenericEnemy(StageEnemy& enemy, int activeAge) {
    if ((enemy.spawnType == 0x0b || enemy.spawnType == 0x0c || enemy.spawnType == 0x0d ||
         enemy.spawnType == 0x19 || enemy.spawnType == 0x1a || enemy.spawnType == 0x1d || enemy.spawnType == 0x1e) && enemy.age < 220) {
        const float desired = aimAtPlayer(enemy.x, enemy.y);
        enemy.angle = approachAngle(enemy.angle, desired, 0.06f);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
    }
    else if (enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10 ||
             enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f) {
        enemy.vx = std::sin((enemy.age + enemy.spawnType * 17) * 0.025f) * 1.1f;
    }
    else {
        (void)activeAge;
    }
}

void StageRuntime::emitGenericProjectiles(StageEnemy& enemy, int activeAge) {
    if (enemy.spawnType == 0x20 || enemy.spawnType == 0x21) {
        return;
    }
    if (activeAge > 30 && activeAge % 70 == 0) {
        const int selector = (enemy.spawnType >= 0x19 && enemy.spawnType <= 0x1f) ? 1 : 0;
        spawnProjectileNode(selector, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.0, 6);
    }
    if ((enemy.spawnType == 0x0c || enemy.spawnType == 0x0d || enemy.spawnType == 0x19 || enemy.spawnType == 0x1a) &&
        activeAge > 80 && activeAge % 120 == 0) {
        const int count = (enemy.spawnType == 0x0c || enemy.spawnType == 0x19) ? 3 : 5;
        spawnProjectileSpread(0, count, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.6, 6, count, kPi / 5.0f);
    }
    if ((enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10 ||
         enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f) &&
        activeAge > 120 && activeAge % 180 == 0) {
        const int selector = enemy.spawnType >= 0x19 ? 3 : 2;
        spawnProjectileSpread(selector, 2, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.2, 8, 12, kTau);
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
        if (projectile.age == 0x3c) projectile.active = false;
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
        if (ordinaryScoreItem) {
            // FUN_1400ca7b0 keeps score/cancel drops in their initial drift until
            // the age gate around 0x20/0x21, then the node can snap into the
            // homing path. Homing turns by at most 0x1000 fixed-angle units and
            // uses a hard speed of 12.0 rather than the old runtime ramp.
            if (!item.homing) {
                if (item.age == 0x20) {
                    item.speed = 0.0f;
                }
                if (item.age > 0x20 && item.speed < 5.0f) {
                    item.speed += 0.125f;
                }
                if (item.age > 0x1f && player_.playerStateTimer < 0xb5 &&
                    distanceSquared(item.x, item.y, player_.x, player_.y) <=
                        static_cast<float>((item.radiusOrScale + 0x40) *
                                           (item.radiusOrScale + 0x40))) {
                    item.homing = true;
                }
            }
            else {
                item.angle16 = approachAngle16(item.angle16, radiansToFixedAngle(std::atan2(player_.y - item.y, player_.x - item.x)), 0x1000);
                item.speed = 12.0f;
            }
        }
        else if (specialRewardItem) {
            // Types 6..8 use the separate FUN_1400ca7b0 path. They reflect inside
            // the playfield through age 0x4af; homing still snaps to speed 12.0
            // and uses the same 0x1000 fixed-angle turn cap.
            if (!item.homing) {
                if (player_.playerStateTimer < 0xb5 &&
                    distanceSquared(item.x, item.y, player_.x, player_.y) <=
                        static_cast<float>((item.radiusOrScale + 0x48) *
                                           (item.radiusOrScale + 0x48)) &&
                    (player_.lives != 3 || item.itemType != 6)) {
                    item.homing = true;
                    item.angle16 = radiansToFixedAngle(std::atan2(player_.y - item.y, player_.x - item.x));
                }
            }
            else {
                item.angle16 = approachAngle16(item.angle16, radiansToFixedAngle(std::atan2(player_.y - item.y, player_.x - item.x)), 0x1000);
                item.speed = 12.0f;
                if (player_.playerStateTimer > 0xb4) {
                    item.homing = false;
                    item.speed = 4.0f;
                }
            }
        }
        else {
            item.active = false;
            ++item.age;
            continue;
        }
        const float angle = fixedAngleToRadians(item.angle16);
        item.x += std::cos(angle) * item.speed;
        item.y += std::sin(angle) * item.speed;
        if (specialRewardItem && item.age < 0x4b0) {
            if (item.x < kPlayLeft + static_cast<float>(item.radiusOrScale) || item.x > kPlayRight - static_cast<float>(item.radiusOrScale)) {
                item.angle16 = normalizeAngle16(-0x8000 - static_cast<int>(item.angle16));
                item.x = clampFloat(item.x, kPlayLeft + static_cast<float>(item.radiusOrScale), kPlayRight - static_cast<float>(item.radiusOrScale));
            }
            if (item.y < kPlayTop + static_cast<float>(item.radiusOrScale) || item.y > kPlayBottom - static_cast<float>(item.radiusOrScale)) {
                item.angle16 = normalizeAngle16(-static_cast<int>(item.angle16));
                item.y = clampFloat(item.y, kPlayTop + static_cast<float>(item.radiusOrScale), kPlayBottom - static_cast<float>(item.radiusOrScale));
            }
        }
        const int collectRadius = item.radiusOrScale + (player_.focused ? 5 : 8);
        if (player_.playerStateTimer < 0xb5 &&
            distanceSquared(item.x, item.y, player_.x, player_.y) <=
                static_cast<float>(collectRadius * collectRadius)) {
            item.active = false;
            collectRewardItem(item);
        }
        if (item.x < kPlayLeft - 160.0f || item.x > kPlayRight + 760.0f || item.y < kPlayTop - 160.0f || item.y > kPlayBottom + 880.0f) {
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
    // FUN_14010e250 uses the same chunk for the 0..3 stock bands.
    const int index = std::max(0, std::min(config_.difficulty, static_cast<int>(kOriginalStockThresholds.size()) - 1));
    return kOriginalStockThresholds[static_cast<std::size_t>(index)];
}

void StageRuntime::addRunScore(int amount) {
    player_.score = std::max(0, player_.score + amount);
}

void StageRuntime::addSpecialGauge(int amount) {
    // DAT_140e45d18 can be negative during cooldown and can also hold the forced
    // full sentinel 9999999. Reward collection does not refill either state.
    if (player_.specialGauge < 0 || player_.specialGauge == kSpecialGaugeForcedFull || amount <= 0) {
        return;
    }
    player_.specialGauge = std::min(kSpecialGaugeReady, player_.specialGauge + amount);
}

void StageRuntime::processStockProgressAfterGain(int progressGain) {
    const int threshold = stockThresholdForCurrentConfig();
    const int cap = threshold * 3;
    player_.stockProgress = std::min(cap, player_.stockProgress + std::max(0, progressGain));
    if (player_.lives < 3 &&
        player_.stockProgress >= (player_.lives + 1) * threshold) {
        ++player_.lives;
    }
}

void StageRuntime::collectRewardItem(const RewardItem& item) {
    // FUN_1400ca7b0 reward collection table: 0/3 = 1x base, 1/4 = 5x,
    // 2/5 = 10x; 6 feeds stock progress, 7 token stock, 8 large stock/token.
    switch (item.itemType) {
    case 0:
    case 3:
        addRunScore(player_.scoreItemBaseValue);
        addSpecialGauge(300);
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 1:
    case 4:
        addRunScore(player_.scoreItemBaseValue * 5);
        addSpecialGauge(900);
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 2:
    case 5:
        addRunScore(player_.scoreItemBaseValue * 10);
        addSpecialGauge(1800);
        playPlayerSound(item1SoundHandle_, 0x0c);
        break;
    case 6:
        if (player_.lives < 3) {
            player_.stockProgress += stockThresholdForCurrentConfig();
        }
        addSpecialGauge(3000);
        addRunScore(player_.scoreItemBaseValue * 10);
        playPlayerSound(item3SoundHandle_);
        break;
    case 7:
        if (player_.tokenStock < kSpecialTokenCap) {
            ++player_.tokenStock;
            playPlayerSound(extendSoundHandle_);
        }
        break;
    case 8:
        player_.stockProgress += 99999;
        player_.tokenStock = kSpecialTokenCap;
        break;
    default:
        addRunScore(player_.scoreItemBaseValue);
        addSpecialGauge(300);
        break;
    }
}

void StageRuntime::spawnEnemyDeathRewardBurst(const StageEnemy& enemy, int payoutWindow) {
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
    if (!defersEnemyDeathEffects(enemy.spawnType)) {
        spawnEnemyDeathEffects(enemy, immediateEnemyDeathEffectMode(enemy.spawnType));
    }
    ++player_.keyStateCount;
}

void StageRuntime::spawnEnemyDeathEffects(const StageEnemy& enemy, int mode) {
    if (mode < 0 || mode > 2) {
        return;
    }

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

    if (mode != 2 && player_.specialGauge >= 0) {
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
    counter.updateCase = 0x137;
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
    const bool triggerAllowed =
        player_.bombLock == 0 &&
        (player_.lives != 0 || (manualFever && player_.specialGauge >= kSpecialGaugeReady)) &&
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

void StageRuntime::updateSpecialGaugeState() {
    const bool manualFever = config_.specialMode == 1;
    if (player_.specialGauge < kSpecialGaugeReady) {
        if (player_.specialGauge < 0) {
            ++player_.specialGauge;
            if (player_.specialGauge == 0) {
                playPlayerSound(feverSoundHandles_[2], 0x13);
                spawnPlayerSideObject(0x18, player_.x, player_.y, 0.0, 0, 0, 0.0f);
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
    --player_.lives;
    player_.stockProgress -= stockThresholdForCurrentConfig();
    player_.x = static_cast<float>(notes::gameplay_layout::kPlayerStart.x);
    player_.y = static_cast<float>(notes::gameplay_layout::kPlayerStart.y);
    if (player_.lives < 0) {
        reset();
        return true;
    }
    player_.playerStateTimer = 0;
    player_.bombLock = -120;
    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 150);
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
    spawnPlayerSideObject(kRootTypes[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          player_.x, player_.y,
                          kRootSpeeds[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          0xc000,
                          kRootValues[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)],
                          kRootRadii[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)]);
    player_.bombLock = kBombLocks[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)];
    player_.invulnerableFrames =
        kBombInvulnerability[static_cast<std::size_t>(group)][static_cast<std::size_t>(slot)];
    --player_.lives;
    player_.stockProgress -= stockThresholdForCurrentConfig();
    player_.playerStateTimer = 0;
    playPlayerSound(bombSoundHandles_[0]);
    if (group == 0 && slot == 1) {
        playPlayerSound(bombSoundHandles_[3]);
    }
}

void StageRuntime::startFever(bool manualActivation) {
    if (manualActivation) {
        player_.playerStateTimer = 0;
        if (player_.invulnerableFrames > 279) {
            player_.invulnerableFrames = 280;
        }
    }
    player_.specialGauge = -kFeverActiveFrames;
    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 150);
    spawnPlayerSideObject(0x18, player_.x, player_.y, 0.0, 0, 0, 0.0f);
    playPlayerSound(feverSoundHandles_[0]);
    playPlayerSound(feverSoundHandles_[1]);
}

void StageRuntime::armManualFever() {
    player_.specialGauge = kSpecialGaugeForcedFull;
    playPlayerSound(feverSoundHandles_[3]);
}

void StageRuntime::playPlayerSound(int handle, int volumeMultiplier) const {
    if (handle == -1) {
        return;
    }
    ChangeVolumeSoundMem(config_.soundEffectVolume * volumeMultiplier, handle);
    PlaySoundMem(handle, DX_PLAYTYPE_BACK, TRUE);
}

void StageRuntime::updatePlayerSideObjects() {
    for (std::size_t objectIndex = 0; objectIndex < playerSideObjects_.size(); ++objectIndex) {
        auto& object = playerSideObjects_[objectIndex];
        if (!object.active) {
            continue;
        }
        const int updateAge = object.age;
        const auto moveAlongAngle = [&object]() {
            const float angle = fixedAngleToRadians(object.angle16);
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

        if (object.type >= 0 && object.type <= 0x0a) {
            moveAlongAngle();
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
                if (updateAge == 180) {
                    object.active = false;
                }
                break;
            case 0x10:
                moveAlongAngle();
                object.drawAngle16 = object.angle16;
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
    float nearestSurfaceDistance = std::numeric_limits<float>::max();
    const float horizontalOrigin = player_.x / 6.0f;
    for (const auto& enemy : enemies_) {
        if (!enemy.active || !enemy.targetable || enemy.hp <= 0 || enemy.age <= enemy.activationDelay) {
            continue;
        }
        const float radius = static_cast<float>(std::max(0, enemy.radius));
        if (enemy.x < horizontalOrigin - (radius + 100.0f) ||
            enemy.x > horizontalOrigin + radius + 700.0f ||
            enemy.y < -(radius + 100.0f) || enemy.y > radius + 820.0f) {
            continue;
        }
        const float dx = enemy.x - object.x;
        const float dy = enemy.y - object.y;
        const float surfaceDistance = std::sqrt(dx * dx + dy * dy) - radius;
        if (surfaceDistance < nearestSurfaceDistance) {
            nearestSurfaceDistance = surfaceDistance;
            nearest = &enemy;
        }
    }
    if (nearest == nullptr) {
        return object.angle16;
    }
    return radiansToFixedAngleTrunc(
        std::atan2(static_cast<double>(nearest->y - object.y),
                   static_cast<double>(nearest->x - object.x)));
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
    switch (object.type) {
    case 0: return 0x19;
    case 1: return 0x1e;
    case 2:
    case 3: return 0x23;
    case 4:
    case 5: return 0x2d;
    case 6: return 0x36;
    case 7: return 0x3c;
    case 8: return 0x3f;
    case 9:
    case 10: return 0x46;
    default: return 0x19;
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
              (enemy.spawnType >= 0x32 && enemy.spawnType <= 0x34)) &&
             enemy.drawBodyThisFrame);
        if ((!enemy.active && !terminalExactEnemy) || !enemy.targetable) {
            continue;
        }
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
            if ((objectType >= 0 && objectType <= 0x0a) || objectType == 0x10) {
                addRunScore(0x10);
                player_.stockProgress += object.age < 0x11
                                             ? (0x15 - object.age) * 2
                                             : 10;
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
            const bool usesHeavyHitSound = enemy.spawnType == 0xc3 ||
                                           enemy.spawnType == 0x127 ||
                                           enemy.spawnType == 0x136 ||
                                           enemy.spawnType == 0x14e ||
                                           enemy.spawnType == 0x150;
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
    // FUN_1400cbd30 handles enemy projectile collision and graze/near-miss. This
    // keeps `graze` tied to bullet proximity rather than offensive hits.
    for (auto& projectile : enemyProjectiles_) {
        if (!projectile.active || !projectile.collisionEnabled) {
            continue;
        }
        const int hitRadius = projectile.radius + (player_.focused ? 3 : 6);
        const float distSq = distanceSquared(projectile.x, projectile.y, player_.x, player_.y);
        if (player_.invulnerableFrames == 0 && distSq <= static_cast<float>(hitRadius * hitRadius)) {
            projectile.active = false;
            projectile.grazeOrHitProcessed = true;
            player_.playerStateTimer = 280;
            player_.invulnerableFrames = 300;
            break;
        }
        const int grazeRadius = hitRadius + kGrazeMargin;
        if (!projectile.grazeOrHitProcessed && distSq <= static_cast<float>(grazeRadius * grazeRadius)) {
            projectile.grazeOrHitProcessed = true;
            ++player_.graze;
            addRunScore(10);
        }
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

void StageRuntime::drawBackground() const {
    DrawBox(0, 0, notes::kScreenWidth, notes::kScreenHeight, GetColor(10, 14, 28), TRUE);
    auto drawTiled = [](const std::vector<int>& frames, int frameIndex, int y) {
        if (frames.empty()) {
            return;
        }
        const int index = std::max(0, std::min(frameIndex, static_cast<int>(frames.size()) - 1));
        const int handle = frames[static_cast<std::size_t>(index)];
        if (handle == -1) {
            return;
        }
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, y - 720, handle, TRUE);
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, y, handle, TRUE);
    };

    // Original primary resources load four 720x2560 StageBack1 variants plus
    // StageBack2. FUN_1400be7a0 layers them by stage segment: StageBack1 is the
    // base, 1b/1d fade in near section transitions, and 1c uses its 12-frame
    // strip for the later dynamic background. The reconstruction keeps the
    // recovered composition order and scrolls the tall layers through the play
    // window instead of flattening everything to StageBack1.front().
    const int fastScroll = frame_ % 720;
    const int slowScroll = (frame_ / 2) % 720;
    drawTiled(stageBack2Frames_, 0, fastScroll);
    drawTiled(stageBack1Frames_, 0, slowScroll);

    if (!stageBack1bFrames_.empty() && frame_ >= 300) {
        const int alpha = std::min(255, (frame_ - 300) * 3);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        drawTiled(stageBack1bFrames_, 0, (slowScroll + 120) % 720);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (!stageBack1cFrames_.empty() && frame_ >= 840) {
        const int frameIndex = (frame_ / 6) % static_cast<int>(stageBack1cFrames_.size());
        const int alpha = std::min(220, 80 + std::max(0, frame_ - 840) / 3);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        drawTiled(stageBack1cFrames_, frameIndex, (slowScroll + 240) % 720);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (!stageBack1dFrames_.empty() && frame_ >= 1560) {
        const int alpha = std::min(210, (frame_ - 1560) * 2);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        drawTiled(stageBack1dFrames_, 0, (slowScroll + 360) % 720);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    if (!stageFrameFrames_.empty() && stageFrameFrames_.front() != -1) {
        const int frameIndex = (config_.routeMode == 2 && stageFrameFrames_.size() > 1) ? 1 : 0;
        DrawGraph(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y, stageFrameFrames_[static_cast<std::size_t>(frameIndex)], TRUE);
    }
    else {
        DrawBox(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y,
                notes::gameplay_layout::kStageFrameRect.right(), notes::gameplay_layout::kStageFrameRect.bottom(),
                GetColor(12, 12, 28), FALSE);
    }
}

void StageRuntime::drawPlayerSideObjects() const {
    const auto frameHandle = [](const std::vector<int>& frames, int index) {
        return index >= 0 && index < static_cast<int>(frames.size())
                   ? frames[static_cast<std::size_t>(index)]
                   : -1;
    };
    const auto drawEffect = [&](const std::vector<int>& frames, int index, float x, float y,
                                double scale, std::uint16_t angle16, int alpha) {
        const int handle = frameHandle(frames, index);
        if (handle == -1 || alpha <= 0 || scale <= 0.0) {
            return;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(alpha, 0, 255));
        DrawRotaGraphF(x, y, scale, fixedAngleToRadians(angle16), handle, TRUE);
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

    for (const auto& object : playerSideObjects_) {
        const float x = screenX(object.x);
        const float y = screenY(object.y);
        const int drawAge = std::max(0, object.age - 1);
        if (object.type >= 0 && object.type <= 0x0a) {
            const int frameIndex = playerSideObjectVisualFrame(object);
            const int handle = frameHandle(playerFrames_, frameIndex);
            if (handle != -1) {
                DrawRotaGraphF(x, y, 0.55, fixedAngleToRadians(object.drawAngle16) + kPi * 0.5f,
                               handle, TRUE);
            }
            else {
                const int color = object.type <= 1 ? GetColor(120, 220, 255) : GetColor(180, 255, 180);
                DrawCircle(static_cast<int>(x), static_cast<int>(y),
                           std::max(3, static_cast<int>(object.auxRadiusOrScale)), color, TRUE);
            }
            continue;
        }

        switch (object.type) {
        case 0x0b:
            drawWhiteFlash(rootFlashAlpha(drawAge, 180));
            break;
        case 0x0c: {
            const double scale = drawAge < 8 ? sineEaseIn(drawAge, 8, 1.0f) : 1.0;
            drawEffect(effectMediumFrames_, 6, x, y, scale,
                       normalizeAngle16(frame_ * 999), 255);
            break;
        }
        case 0x0d:
            drawEffect(effectLargeFrames_, 1, x, y,
                       object.collisionRadiusOrScale / 180.0,
                       normalizeAngle16(frame_ * 2000), 192);
            break;
        case 0x0e:
            drawWhiteFlash(rootFlashAlpha(drawAge, 180));
            if (drawAge < 30) {
                const double scale = drawAge < 20
                                         ? sineEaseIn(drawAge, 20, 1.0f)
                                         : sineEaseOut(drawAge - 20, 10, 1.0f);
                drawEffect(effectMediumFrames_, 6, x, y, scale,
                           normalizeAngle16(frame_ * 999), 255);
            }
            else {
                drawEffect(effectLargeFrames_, 2 + ((drawAge / 8) & 1), x, y,
                           object.collisionRadiusOrScale / 250.0,
                           normalizeAngle16(drawAge * 0x400), 255);
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
                       object.angle16, alpha);
            break;
        }
        case 0x15: {
            const int ambientAlpha = rootFlashAlpha(drawAge, 240);
            const int fieldAlpha = drawAge < 32
                                       ? static_cast<int>(sineEaseIn(drawAge, 32, 48.0f))
                                       : (drawAge >= 224
                                              ? static_cast<int>(sineEaseOut(drawAge - 224, 16, 48.0f))
                                              : 48);
            drawWhiteFlash(ambientAlpha);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::clamp(fieldAlpha, 0, 255));
            const int edgeHandle = frameHandle(effectLargeFrames_, 5);
            if (edgeHandle != -1) {
                for (int i = 0; i < 7; ++i) {
                    const float horizontal = static_cast<float>((drawAge * 3) % 120 + i * 120);
                    const float vertical = static_cast<float>((drawAge * 3) % 160 + i * 160);
                    DrawRotaGraphF(screenX(horizontal), screenY(360.0f), 1.0, kPi * 0.5f, edgeHandle, TRUE);
                    DrawRotaGraphF(screenX(720.0f - horizontal), screenY(360.0f), 1.0, kPi * 0.5f, edgeHandle, TRUE);
                    DrawRotaGraphF(screenX(360.0f), screenY(vertical), 1.0, 0.0, edgeHandle, TRUE);
                    DrawRotaGraphF(screenX(360.0f), screenY(720.0f - vertical), 1.0, 0.0, edgeHandle, TRUE);
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
                           normalizeAngle16(drawAge * 0x29a), 255);
            }
            break;
        }
        case 0x16: {
            const int alpha = drawAge < 80
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 80, 16, 255.0f));
            drawEffect(effectLargeFrames_, 6, x, y,
                       object.collisionRadiusOrScale / 200.0,
                       normalizeAngle16(drawAge * 0x400), alpha);
            drawEffect(effectLargeFrames_, 6, x, y,
                       object.collisionRadiusOrScale / 200.0,
                       normalizeAngle16(-drawAge * 0x400), alpha);
            break;
        }
        case 0x17:
        case 0x18: {
            const int alpha = drawAge < 32
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 32, 16, 255.0f));
            drawEffect(effectLargeFrames_, 0, x, y,
                       object.collisionRadiusOrScale / 250.0, 0, alpha);
            break;
        }
        case 0x19: {
            const int alpha = drawAge < 16
                                  ? 255
                                  : static_cast<int>(sineEaseOut(drawAge - 16, 8, 255.0f));
            drawEffect(effectLargeFrames_, 0, x, y,
                       object.collisionRadiusOrScale / 250.0, 0, alpha);
            break;
        }
        case 0x1a: {
            const int alpha = drawAge < 16
                                  ? 96
                                  : static_cast<int>(sineEaseOut(drawAge - 16, 8, 96.0f));
            drawEffect(effectMediumFrames_, 5, x, y,
                       object.collisionRadiusOrScale / 75.0, 0, alpha);
            break;
        }
        default:
            DrawCircle(static_cast<int>(x), static_cast<int>(y),
                       std::max(1, static_cast<int>(object.collisionRadiusOrScale)),
                       GetColor(180, 255, 180), FALSE);
            break;
        }
    }
}

void StageRuntime::drawPlayer() const {
    const float x = screenX(player_.x);
    const float y = screenY(player_.y);
    const int frame = playerFrames_.empty() ? -1 : playerFrames_[0];
    if (frame != -1 && (player_.invulnerableFrames / 6) % 2 == 0) {
        DrawRotaGraphF(x, y, 0.7, 0.0, frame, TRUE);
    }
    const int color = player_.focused ? GetColor(128, 220, 255) : GetColor(255, 255, 255);
    DrawCircle(static_cast<int>(x), static_cast<int>(y), player_.focused ? 3 : 5, color, FALSE);
}

void StageRuntime::drawEnemies() const {
    for (const auto& enemy : enemies_) {
        if (enemy.spawnType == 0x137 || enemy.spawnType == 0x153) {
            continue;
        }
        const float x = screenX(enemy.x);
        const float y = screenY(enemy.y);
        if (drawStage01BossExact(enemy, x, y)) {
            continue;
        }
        if (drawStage02BossExact(enemy, x, y)) {
            continue;
        }
        if (drawStage02Type19Exact(enemy, x, y) ||
             drawStage02Type1AExact(enemy, x, y) ||
             drawStage02Type1BExact(enemy, x, y) ||
             drawStage02Type1CExact(enemy, x, y) ||
             drawStage02Type1DOr1EExact(enemy, x, y) ||
             drawStage02Type1FExact(enemy, x, y) ||
             drawStage02Type20Exact(enemy, x, y) || drawStage02Type21Exact(enemy, x, y)) {
            continue;
        }
        if (drawStage03EnemyExact(enemy, x, y)) {
            continue;
        }
        if (drawType0AExact(enemy, x, y)) {
            continue;
        }
        if (drawStage01Type0EExact(enemy, x, y)) {
            continue;
        }
        if (drawStage01Type0FExact(enemy, x, y)) {
            continue;
        }
        if (drawStage01SmallEnemyExact(enemy, x, y)) {
            continue;
        }
        const auto& frames = (enemy.spawnType >= 0x138 && enemy.spawnType <= 0x13b)
                                 ? bossFrames_
                                 : (enemyUsesMediumFrame(enemy) ? enemyMediumFrames_ : enemySmallFrames_);
        const int visualFrame = enemyVisualFrameForSpawnType(enemy);
        const int index = frames.empty() ? -1 : std::min(visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        if (handle != -1) {
            if (drawStage04EnemyExact(enemy, x, y)) {
                continue;
            }
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

bool StageRuntime::drawStage01BossExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType == 0x138) {
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

    if (!isStage01BossChildType(enemy.spawnType)) {
        return false;
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

bool StageRuntime::drawStage02BossExact(const StageEnemy& enemy, float x, float y) const {
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
            if (medium != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
                SetDrawBright(0, 0, 0);
                drawNode(medium, x, y - 50.0f, 0, bodyScaleX, bodyScaleY);
                SetDrawBright(255, 255, 255);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
                drawNode(medium, x, y + 50.0f, 0, bodyScaleX, bodyScaleY);
            }
            drawNode(core, x, y - 60.0f, 0, coreScale, coreScale);
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

        for (int i = 0; i < 4; ++i) {
            drawNode(largeRotor, x, y + yShift + 250.0f,
                     normalizeAngle16(frame_ * 600 + i * 0x4000),
                     1.0, 1.0);
        }
        drawNode(largeMiddle, x, y + yShift + 160.0f, 0, 1.0, 1.0);

        if (state < 2 || (state == 2 && timer <= 100)) {
            drawOrbitHalf(true);
            drawNode(largeBody, x, y, 0, 1.0, 1.0);
            // The two upper ellipse nodes share the body layer. The lower four
            // and the mount are one layer forward in the original queue.
            drawDecorations(4, 6);
            drawOrbitHalf(false);
            drawNode(mediumMount, x, y - 90.0f, 0, 1.0, 1.0);
            drawDecorations(0, 4);
        }
        else {
            const int upper = handleAt(bossFrames_, 10 + (timer / 5) % 3);
            if (upper != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
                SetDrawBright(0, 0, 0);
                drawNode(upper, x, y + yShift, 0, 1.0, 1.0);
                SetDrawBright(255, 255, 255);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            drawOrbitHalf(true);
            if (upper != -1) {
                drawNode(upper, x, y + yShift, 0, 1.0, 1.0);
            }
            drawOrbitHalf(false);
        }
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

void StageRuntime::drawEnemyGaugeExact(const StageEnemy& enemy, int mode, float x, float y) const {
    if (mode < 0 || mode >= static_cast<int>(enemyGaugeFrames_.size()) ||
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

bool StageRuntime::drawStage02Type1BExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x1b) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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
    drawEnemyGaugeExact(enemy, 1, x, y);
    return true;
}

bool StageRuntime::drawStage02Type1CExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x1c) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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
    drawEnemyGaugeExact(enemy, 1, x, y);
    return true;
}

bool StageRuntime::drawStage02Type1DOr1EExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x1d && enemy.spawnType != 0x1e) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    if (enemy.spawnType == 0x1d) {
        double scaleX = 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 60.0);
        if (timer % 120 < 11) {
            scaleX = 1.0 + 0.05 * std::sin(static_cast<double>(timer) * kTau / 10.0);
        }
        const int body = enemySmallFrames_.size() > 19 ? enemySmallFrames_[19] : -1;
        if (body != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            drawOriginalMode7Node(body, x, y, 0, scaleX, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            drawOriginalMode7Node(body, x, y, 0, scaleX, 1.0, false);
        }
    }
    else {
        const double scaleX = 1.0 - 0.05 * std::sin(static_cast<double>(timer) * kTau / 25.0);
        const int mediumIndex = 39 + (enemy.entityId % 4);
        const int mediumBody = mediumIndex >= 0 && mediumIndex < static_cast<int>(enemyMediumFrames_.size())
                                   ? enemyMediumFrames_[static_cast<std::size_t>(mediumIndex)]
                                   : -1;
        if (mediumBody != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
            drawOriginalMode7Node(mediumBody, x, y - 50.0f, 0, scaleX, 1.0, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            drawOriginalMode7Node(mediumBody, x, y - 50.0f, 0, scaleX, 1.0, false);
        }
        const int smallIndex = 20 + (timer / 3) % 3;
        const int smallBody = smallIndex >= 0 && smallIndex < static_cast<int>(enemySmallFrames_.size())
                                  ? enemySmallFrames_[static_cast<std::size_t>(smallIndex)]
                                  : -1;
        if (smallBody != -1) {
            drawOriginalMode7Node(smallBody, x, y - 60.0f, 0, 1.0, 1.0, false);
        }
    }
    drawEnemyGaugeExact(enemy, 2, x, y);
    return true;
}

bool StageRuntime::drawStage02Type1FExact(const StageEnemy& enemy, float x, float y) const {
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
    if (body != -1) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(body, x, y, 0, scale, 1.0, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        drawOriginalMode7Node(body, x, y, 0, scale, 1.0, false);
    }
    if (enemy.targetable) {
        drawEnemyGaugeExact(enemy, 1, x, y);
    }
    return true;
}

bool StageRuntime::drawStage02Type19Exact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x19) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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
    drawEnemyGaugeExact(enemy, 2, x, y);
    return true;
}

bool StageRuntime::drawStage02Type1AExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x1a) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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
    drawEnemyGaugeExact(enemy, 2, x, y);
    return true;
}

bool StageRuntime::drawStage02Type20Exact(const StageEnemy& enemy, float x, float y) const {
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

    if (largeBody != -1) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(largeBody, x, y - 125.0f, 0, scale, 0.6, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        drawOriginalMode7Node(largeBody, x, y - 120.0f, 0, scale, 1.0, false);
    }
    if (mediumBody != -1) {
        drawOriginalMode7Node(mediumBody, x, y + 50.0f + bob, 0, 1.0, 1.0, false);
    }
    if (enemy.targetable) {
        drawEnemyGaugeExact(enemy, 0, x, y);
    }
    return true;
}

bool StageRuntime::drawStage02Type21Exact(const StageEnemy& enemy, float x, float y) const {
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
    if (body != -1) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        drawOriginalMode7Node(body, x, bodyY, 0, scale, 1.0, false);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        drawOriginalMode7Node(body, x, bodyY, 0, scale, 1.0, false);
    }

    drawEnemyGaugeExact(enemy, 1, x, y);
    return true;
}

bool StageRuntime::drawStage03EnemyExact(const StageEnemy& enemy, float x, float y) const {
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

    if (enemy.drawMarkerThisFrame) {
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
            draw(large(13), x, y, 0);
            for (int i = 0; i < 4; ++i) {
                draw(large(15), x, y - 255.0f,
                     normalizeAngle16(frame_ * 0x500 + i * 0x4000));
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
        if (bossFrame >= 0 && bossFrame < static_cast<int>(bossFrames_.size())) {
            draw(bossFrames_[static_cast<std::size_t>(bossFrame)], x, y, 0);
        }
        break;
    }
    case 0x30: {
        if (enemy.drawHelperState <= 2) {
            const int bodyFrame = enemy.drawHelperState == 2 ? 16 : 14;
            draw(large(bodyFrame), x, y, 0);
        }
        if (!effectSmallFrames_.empty() && effectSmallFrames_[0] != -1) {
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
            drawEnemyGaugeExact(enemy, 1, x, y);
        }
        break;
    }
    case 0x31:
        draw(medium(62), x, y, enemy.sourceAngle16);
        break;
    case 0x32:
    case 0x33:
    case 0x34: {
        draw(small(30), x, y, 0);
        draw(small(29), x, y, 0);
        static constexpr std::array<int, 5> kLeafOffset{{
            0, 0x3333, 0x6666, -0x6667, -0x3334,
        }};
        for (const int offset : kLeafOffset) {
            draw(small(31), x, y - 30.0f,
                 normalizeAngle16(static_cast<int>(enemy.secondaryAngle16) + offset));
        }
        if (enemy.targetable) {
            drawEnemyGaugeExact(enemy, 2, x, y);
        }
        break;
    }
    case 0x25: {
        if (!effectSmallFrames_.empty()) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (timer % 4 >= 2) {
                SetDrawBright(255, 128, 0);
            }
            draw(effectSmallFrames_[0], x + 12.0f, y - 32.0f, 0, 0.4, 0.4);
            draw(effectSmallFrames_[0], x - 12.0f, y - 32.0f, 0, 0.4, 0.4);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        draw(small(24), x, y, 0);
        break;
    }
    case 0x26: {
        if (!effectSmallFrames_.empty()) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
            if (timer % 4 >= 2) SetDrawBright(255, 128, 0);
            draw(effectSmallFrames_[0], x + 50.0f, y - 55.0f, 0, 0.8, 0.8);
            draw(effectSmallFrames_[0], x - 50.0f, y - 55.0f, 0, 0.8, 0.8);
            SetDrawBright(255, 255, 255);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        draw(medium(50), x + 50.0f, y + 10.0f, 0);
        draw(medium(50), x - 50.0f, y + 10.0f, 0, 1.0, 1.0, true);
        draw(medium(49), x, y, 0);
        break;
    }
    case 0x27:
    case 0x29: {
        const bool type27 = enemy.spawnType == 0x27;
        const float bob = 5.0f * std::sin(static_cast<float>(timer) * kTau / 48.0f);
        if ((timer & 1) == 0) {
            draw(medium(type27 ? 52 : 54), x + 70.0f,
                 y + bob - (type27 ? 10.0f : 0.0f), 0);
            draw(medium(type27 ? 52 : 54), x - 70.0f,
                 y + bob - (type27 ? 10.0f : 0.0f), 0, 1.0, 1.0, true);
        }
        draw(medium(type27 ? 51 : 53), x, y, 0);
        break;
    }
    case 0x28:
        draw(small(27), x, y, 0, 1.0,
             1.0 + std::sin(static_cast<double>(timer) * kPi / 16.0) * 0.1);
        break;
    case 0x2a:
        draw(small(28), x, y, normalizeAngle16(timer * 0x14d));
        break;
    case 0x2b: {
        const float wave0 = 2.0f * std::sin(static_cast<float>(timer) * kTau / 38.0f);
        const float wave9 = 2.0f * std::sin(static_cast<float>(timer - 9) * kTau / 38.0f);
        const float wave18 = 2.0f * std::sin(static_cast<float>(timer - 18) * kTau / 38.0f);
        const int rotA = static_cast<int>(std::sin(static_cast<double>(timer) * kTau / 9.0) * 3800.0);
        const int rotB = static_cast<int>(std::sin(static_cast<double>(timer - 4) * kTau / 9.0) * 3800.0);
        draw(large(10), x + 10.0f, y - 40.0f + wave9, normalizeAngle16(rotB));
        draw(large(10), x - 10.0f, y - 40.0f + wave9, normalizeAngle16(-rotB), 1.0, 1.0, true);
        draw(large(9), x + 10.0f, y - 45.0f + wave9, normalizeAngle16(rotA));
        draw(large(9), x - 10.0f, y - 45.0f + wave9, normalizeAngle16(-rotA), 1.0, 1.0, true);
        draw(medium(57), x, y + 50.0f + wave18, 0);
        draw(medium(56), x, y + wave9, 0, 1.0, 1.0, true);
        draw(medium(55), x, y - 70.0f + wave0, 0);
        break;
    }
    case 0x2c: {
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        draw(small(25), x + 8.0f, y + 5.0f, enemy.sourceAngle16);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        draw(small(25), x, y, enemy.sourceAngle16);
        draw(small(26), x + static_cast<float>(std::cos(radians) * 35.0),
             y + static_cast<float>(std::sin(radians) * 35.0), enemy.sourceAngle16);
        break;
    }
    case 0x2d: {
        const double radians = fixedAngleToRadiansDouble(enemy.sourceAngle16);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
        draw(medium(58), x + 16.0f, y + 10.0f, enemy.sourceAngle16);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        draw(medium(58), x, y, enemy.sourceAngle16);
        draw(medium(59), x + static_cast<float>(std::cos(radians) * 100.0),
             y + static_cast<float>(std::sin(radians) * 100.0), enemy.sourceAngle16);
        break;
    }
    case 0x2e: {
        const float wave = 3.0f * std::sin(static_cast<float>(frame_) * kTau / 68.0f) - 24.0f;
        draw(large(12), x + 180.0f, y + 80.0f + wave, 0);
        draw(large(12), x - 180.0f, y + 80.0f + wave, 0, 1.0, 1.0, true);
        draw(large(11), x, y + 80.0f, 0);
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
        if (parent != nullptr) {
            const float anchorX = screenX(parent->x + enemy.originX);
            const float anchorY = screenY(parent->y + enemy.originY);
            const auto angle = radiansToFixedAngleTrunc(
                std::atan2(static_cast<double>(y - anchorY), static_cast<double>(x - anchorX)));
            draw(medium(61), anchorX, anchorY, normalizeAngle16(static_cast<int>(angle) - 0x4000));
            draw(medium(61), (anchorX + x) * 0.5f, (anchorY + y) * 0.5f,
                 normalizeAngle16(static_cast<int>(angle) - 0x4000));
        }
        draw(medium(60), x, y, 0);
        break;
    }
    default:
        break;
    }
    return true;
}

bool StageRuntime::drawStage04EnemyExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType == 0x3f) {
        const int smallBody = enemySmallFrames_.size() > 42 ? enemySmallFrames_[42] : -1;
        const int sideBody = enemyMediumFrames_.size() > 74 ? enemyMediumFrames_[74] : -1;
        const int centerBody = enemyLargeFrames_.size() > 18 ? enemyLargeFrames_[18] : -1;

        constexpr double kTauDouble = 6.28318530717958647692;
        const double chainPhase = static_cast<double>(frame_) * kTauDouble / 136.0;
        const double chainSin = std::sin(chainPhase);
        const double chainCos = std::cos(chainPhase);
        if (smallBody != -1) {
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
        if (sideBody != -1) {
            drawOriginalMode7Node(sideBody, x + static_cast<float>(pulse * 60.0), y + 230.0f,
                                  normalizeAngle16(sideAngle), 1.0, 1.0, false);
            drawOriginalMode7Node(sideBody, x - static_cast<float>(pulse * 60.0), y + 230.0f,
                                  normalizeAngle16(-sideAngle), 1.0, 1.0, true);
        }
        if (centerBody != -1) {
            drawOriginalMode7Node(centerBody, x, y + 70.0f, 0, pulse, pulse, false);
        }

        if (enemy.hp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.hp) / static_cast<double>(enemy.maxHp);
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
            if (enemy.drawBodyThisFrame && childBody != -1) {
                drawOriginalMode7Node(childBody, x, y, enemy.sourceAngle16,
                                      1.0, 1.0, false);
            }
            return true;
        }

        if (enemy.drawMarkerThisFrame) {
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
        if (sideBody != -1) {
            drawOriginalMode7Node(sideBody, sideX, sideY, 0xc000,
                                  sideScale, 1.0, true);
            drawOriginalMode7Node(sideBody, sideX, sideY, 0xc000,
                                  -sideScale, 1.0, true);
        }

        const int centerBody = enemyLargeFrames_.size() > 17 ? enemyLargeFrames_[17] : -1;
        if (centerBody != -1) {
            drawOriginalMode7Node(centerBody, x, y, 0, 1.0, 1.0, entryFromLeft);
        }

        if (enemy.hp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.hp) / static_cast<double>(enemy.maxHp);
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
            if (marker != -1) {
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
        drawMedium(66, x + 30.0f, y + bodyWave, normalizeAngle16(rot66), false);
        drawMedium(66, x - 30.0f, y + bodyWave, normalizeAngle16(-rot66), true);
        drawMedium(65, x + 25.0f, y + bodyWave + 80.0f, normalizeAngle16(rot65), false);
        drawMedium(65, x - 25.0f, y + bodyWave + 80.0f, normalizeAngle16(-rot65), true);
        drawMedium(64, x, y + bodyWave, 0, false);
        drawMedium(63, x, y + rearWave, 0, false);

        if (enemy.hp >= 0 && enemy.maxHp > 0) {
            const double ratio = static_cast<double>(enemy.hp) / static_cast<double>(enemy.maxHp);
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
                if (marker != -1) {
                    drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                          markerScale, markerScale, false);
                }
                else {
                    drawMedium(68, markerX, markerY, enemy.sourceAngle16, markerScale, markerScale, false);
                }
                return true;
            }
            if (!enemy.drawBodyThisFrame) {
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
            drawMedium(70, x, y, enemy.sourceAngle16, 1.0, pulse, false);
            return true;
        }

        const float angle = fixedAngleToRadians(enemy.sourceAngle16);
        drawMedium(71, x + std::cos(angle) * 45.0f, y + std::sin(angle) * 45.0f,
                   enemy.sourceAngle16, 1.0, pulse, false);
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

    if (enemy.spawnType == 0x35) {
        if (enemy.helperState == 0) {
            const double markerScale = std::max(0.0, 2.0 - enemy.drawHelperTimer * 0.1);
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            const float horizontalOrigin = player_.x / 6.0f;
            const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                                     horizontalOrigin + 650.0f));
            const float markerY = screenY(clampFloat(enemy.y, -50.0f, 770.0f));
            if (marker != -1) {
                drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                      markerScale, markerScale, false);
            }
            else {
                draw(32, markerX, markerY, markerScale, enemy.sourceAngle16);
            }
            return true;
        }
        draw(32, x, y, 1.0, enemy.sourceAngle16);
        const std::uint16_t base = normalizeAngle16(enemy.drawHelperTimer * 2000);
        draw(33, x, y - 35.0f, 1.0, base);
        draw(33, x, y - 35.0f, 1.0, normalizeAngle16(static_cast<int>(base) + 0x5555));
        draw(33, x, y - 35.0f, 1.0, normalizeAngle16(static_cast<int>(base) - 0x5556));
        return true;
    }

    if (enemy.spawnType == 0x36) {
        if (enemy.helperState == 0) {
            const double markerScale = std::max(0.0, 2.0 - enemy.drawHelperTimer * 0.1);
            const int marker = effectMediumFrames_.size() > 4 ? effectMediumFrames_[4] : -1;
            const float horizontalOrigin = player_.x / 6.0f;
            const float markerX = screenX(clampFloat(enemy.x, horizontalOrigin - 50.0f,
                                                     horizontalOrigin + 650.0f));
            const float markerY = screenY(clampFloat(enemy.y, -50.0f, 770.0f));
            if (marker != -1) {
                drawOriginalMode7Node(marker, markerX, markerY, enemy.sourceAngle16,
                                      markerScale, markerScale, false);
            }
            else {
                draw(34, markerX, markerY, markerScale, enemy.sourceAngle16);
            }
            return true;
        }
        int bodyFrame = 34;
        if (enemy.helperState == 1 && enemy.drawHelperTimer > 79) {
            bodyFrame = 37;
        }
        else if (enemy.helperState == 1 && enemy.drawHelperTimer > 69) {
            bodyFrame = 35 + ((enemy.drawHelperTimer - 70) / 5);
        }
        draw(bodyFrame, x, y, 1.0, enemy.sourceAngle16);
        if (enemy.helperState == 1) {
            draw(38, x, y, 1.0, enemy.sourceAngle16);
            draw(39, x - 16.0f, y, 1.0, normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + 0x4000));
            draw(39, x + 16.0f, y, 1.0, normalizeAngle16(static_cast<int>(enemy.sourceAngle16) + 0x4000));
        }
        return true;
    }

    const double scale = enemy.helperState == 0
                             ? std::max(0.0, std::min(1.0, enemy.drawHelperTimer / 120.0))
                             : 1.0;
    draw(41, x, y, scale, enemy.secondaryAngle16);
    draw(40, x, y, scale, enemy.secondaryAngle16);
    return true;
}

bool StageRuntime::drawStage01Type0EExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x0e) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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

    StageEnemy gaugeSnapshot = enemy;
    gaugeSnapshot.hp = enemy.drawHp;
    // FUN_140079c10(entity, 1, ..., xOffset=0, yOffset=-120).
    drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 120.0f);
    return true;
}

bool StageRuntime::drawStage01Type0FExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x0f) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
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

    StageEnemy gaugeSnapshot = enemy;
    gaugeSnapshot.hp = enemy.drawHp;
    drawEnemyGaugeExact(gaugeSnapshot, 1, x, y - 120.0f);
    return true;
}

bool StageRuntime::drawType0AExact(const StageEnemy& enemy, float x, float y) const {
    if (enemy.spawnType != 0x0a || enemyMediumFrames_.empty()) {
        return false;
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

    if (enemy.targetable) {
        // FUN_140079c10(entity, 2, ..., xOffset=0, yOffset=-80).
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 80.0f);
    }
    return true;
}

bool StageRuntime::drawStage01SmallEnemyExact(const StageEnemy& enemy, float x, float y) const {
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
        if (enemy.drawMarkerThisFrame) {
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
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f);
        return true;
    }
    case 0x0c: {
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
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f);
        return true;
    }
    case 0x0d: {
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
        StageEnemy gaugeSnapshot = enemy;
        gaugeSnapshot.hp = enemy.drawHp;
        drawEnemyGaugeExact(gaugeSnapshot, 2, x, y - 50.0f);
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
    DrawRotaGraph3F(x, y, static_cast<float>(width) * 0.5f,
                    static_cast<float>(height) * 0.5f, scaleX, scaleY,
                    fixedAngleToRadiansDouble(angle16), handle, TRUE,
                    reverseX ? TRUE : FALSE);
}

void StageRuntime::drawStageEffects(bool foreground) const {
    for (const auto& effect : stageEffects_) {
        if (!effect.drawQueuedThisFrame || effect.graphHandle == -1 ||
            (effect.drawLayer >= 0x18) != foreground) {
            continue;
        }

        const int alpha = std::clamp(effect.drawAlpha, 0, 0xff);
        if (alpha == 0) {
            continue;
        }
        SetDrawBright(std::clamp(effect.colorR, 0, 0xff),
                      std::clamp(effect.colorG, 0, 0xff),
                      std::clamp(effect.colorB, 0, 0xff));
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        drawOriginalMode7Node(effect.graphHandle,
                              screenX(effect.drawX), screenY(effect.drawY),
                              effect.drawAngle16, effect.drawScaleX, effect.drawScaleY, false);
    }
    SetDrawBright(0xff, 0xff, 0xff);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void StageRuntime::drawProjectiles() const {
    for (const auto& projectile : enemyProjectiles_) {
        if (!projectile.drawQueuedThisFrame) {
            continue;
        }
        const int frameIndex = bulletFrameForVisualSelector(projectile.visualSelector);
        const int handle = bulletFrames_.empty() || frameIndex >= static_cast<int>(bulletFrames_.size()) ? -1 : bulletFrames_[static_cast<std::size_t>(frameIndex)];
        const double angle = projectileDrawRotationForVisualSelector(projectile.visualSelector, projectile.drawAge, projectile.angle16);
        const auto scale = projectileScaleForVisualSelector(projectile.visualSelector, projectile.drawAge);
        const float x = screenX(projectile.x);
        const float y = screenY(projectile.y);
        if ((projectile.visualSelector == 0x11 || projectile.visualSelector == 0x12) &&
            effectSmallFrames_.size() > 7 && effectSmallFrames_[7] != -1) {
            constexpr double kOriginalPi = 3.14159265358979;
            const double pulseY = 0.6 +
                                  std::sin(static_cast<double>(projectile.drawAge) *
                                           2.0 * kOriginalPi / 17.0) *
                                      0.4;
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xc0);
            drawOriginalMode7Node(effectSmallFrames_[7], x, y, projectile.angle16,
                                  1.0, pulseY, false);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        else if ((projectile.visualSelector == 0x13 || projectile.visualSelector == 0x14)) {
            const int overlayIndex = projectile.visualSelector == 0x13 ? 117 : 118;
            if (overlayIndex < static_cast<int>(enemySmallFrames_.size()) &&
                enemySmallFrames_[static_cast<std::size_t>(overlayIndex)] != -1) {
                const int direction = projectile.visualSelector == 0x13 ? -1 : 1;
                drawOriginalMode7Node(
                    enemySmallFrames_[static_cast<std::size_t>(overlayIndex)], x, y,
                    normalizeAngle16(direction * projectile.drawAge * 0x457),
                    1.0, 1.0, projectile.visualSelector == 0x14);
            }
        }
        if (handle != -1) {
            // Selectors 0x13/0x14 also append persistent generic effect nodes;
            // their immediate overlays and base beads are rendered here.
            DrawRotaGraph3F(x, y, 30.0f, 30.0f, scale[0], scale[1], angle, handle, TRUE);
        }
        else {
            DrawCircle(static_cast<int>(x), static_cast<int>(y), projectile.radius, GetColor(255, 80, 180), TRUE);
        }
    }
}

void StageRuntime::drawRewardItems() const {
    for (const auto& item : rewardItems_) {
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
                                     static_cast<double>(kTau) / 33.0);
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
    drawHudSidebar();
    if (showLayoutGuides_) {
        drawLayoutGuides();
        drawDebugOverlay();
    }
}

void StageRuntime::drawHudSidebar() const {
    if (config_.dataWindowEnabled == 1 && config_.routeMode != -1) {
        drawLeftHudPanel();
    }
    drawRightHudPanel();
    drawStateRows();
    drawNumberWithSeparators(notes::hud_layout::kNumberRightX, notes::hud_layout::kScoreY, player_.score, numSmallFrames_, 20, 30, 0.9);
    drawNumberWithSeparators(notes::hud_layout::kNumberRightX, notes::hud_layout::kBaseValueY, player_.scoreItemBaseValue, numSmallFrames_, 20, 30, 0.85);
    drawDreamGauge(notes::hud_layout::kLabelX, notes::hud_layout::kDreamGaugeY, player_.specialGauge, 50000);
    drawDataWindow2Tokens(notes::hud_layout::kPipStartX, notes::hud_layout::kTokenY, player_.tokenStock, notes::hud_layout::kMaxTokens);
    drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kStageY, selectedStage_, numSmallFrames_, 20, 30, 0.85);
    drawHudStatusIconGroup();
}


void StageRuntime::drawLeftHudPanel() const {
    if (dataWindowHandle_ != -1) {
        DrawGraph(notes::hud_layout::kLeftDataWindowRect.x, notes::hud_layout::kLeftDataWindowRect.y, dataWindowHandle_, TRUE);
    }
    else {
        DrawBox(notes::hud_layout::kLeftDataWindowRect.x, notes::hud_layout::kLeftDataWindowRect.y,
                notes::hud_layout::kLeftDataWindowRect.right(), notes::hud_layout::kLeftDataWindowRect.bottom(),
                GetColor(18, 20, 36), TRUE);
    }

    if (!stateFrames_.empty() && stateFrames_.front() != -1) {
        const auto drawState = [&](int frame, int x, int y, int alpha = 255) {
            if (frame >= 0 && frame < static_cast<int>(stateFrames_.size()) && stateFrames_[static_cast<std::size_t>(frame)] != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
                DrawGraph(x, y, stateFrames_[static_cast<std::size_t>(frame)], TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        };
        drawState(0, notes::hud_layout::kLeftStageLabelX, notes::hud_layout::kLeftStageLabelY);
        drawState(1, notes::hud_layout::kLeftFrameLabelX, notes::hud_layout::kLeftFrameLabelY);
        drawState(3, notes::hud_layout::kLeftGrazeLabelX, notes::hud_layout::kLeftGrazeLabelY);
        drawState(27, notes::hud_layout::kLeftKeyStateIconX - 80, notes::hud_layout::kLeftKeyStateIconY - 20, 220);
    }

    drawHudNumber(notes::hud_layout::kLeftStageLabelX + 190, notes::hud_layout::kLeftStageLabelY + 6,
                  selectedStage_, numSmallFrames_, 20, 30, 0.72);
    drawHudNumber(notes::hud_layout::kLeftFrameLabelX + 235, notes::hud_layout::kLeftFrameLabelY + 6,
                  frame_, numSmallFrames_, 20, 30, 0.62);
    drawNumberWithSeparators(notes::hud_layout::kLeftGrazeLabelX + 235, notes::hud_layout::kLeftGrazeLabelY + 6,
                             player_.graze, numSmallFrames_, 20, 30, 0.62);
    drawHudNumber(notes::hud_layout::kLeftKeyStateValueRightX, notes::hud_layout::kLeftKeyStateIconY + 8,
                  player_.keyStateCount, numSmallFrames_, 20, 30, 0.72);

    if (!playerFrames_.empty() && playerFrames_.front() != -1) {
        const int base = std::min(config_.routeMode * 0x1e, static_cast<int>(playerFrames_.size()) - 1);
        DrawRotaGraphF(static_cast<float>(notes::hud_layout::kLeftPlayerIconX),
                       static_cast<float>(notes::hud_layout::kLeftPlayerIconY),
                       0.62, 0.0, playerFrames_[static_cast<std::size_t>(base)], TRUE);
    }
    if (!dataWindow2Frames_.empty() && dataWindow2Frames_.front() != -1) {
        for (int i = 0; i < std::min(player_.tokenStock, 5); ++i) {
            const int frame = std::min(i, static_cast<int>(dataWindow2Frames_.size()) - 1);
            DrawRotaGraphF(static_cast<float>(notes::hud_layout::kLeftDataWindow2X + i * 24),
                           static_cast<float>(notes::hud_layout::kLeftDataWindow2Y),
                           0.38, 0.0, dataWindow2Frames_[static_cast<std::size_t>(frame)], TRUE);
        }
    }
}

void StageRuntime::drawRightHudPanel() const {
    if (!playerFrameFrames_.empty() && playerFrameFrames_.front() != -1) {
        const int frameIndex = std::clamp(config_.routeMode * 10, 0,
                                          static_cast<int>(playerFrameFrames_.size()) - 1);
        DrawGraph(notes::hud_layout::kRightPanelRect.x, notes::hud_layout::kRightPanelRect.y, playerFrameFrames_[static_cast<std::size_t>(frameIndex)], TRUE);
        return;
    }
    if (timeWindowHandle_ != -1) {
        DrawGraph(notes::hud_layout::kTimeWindowRect.x, notes::hud_layout::kTimeWindowRect.y, timeWindowHandle_, TRUE);
    }
    if (dataWindowHandle_ != -1) {
        DrawGraph(notes::hud_layout::kDataWindowRect.x, notes::hud_layout::kDataWindowRect.y, dataWindowHandle_, TRUE);
    }
}

void StageRuntime::drawStateRows() const {
    if (stateFrames_.empty() || stateFrames_.front() == -1) {
        return;
    }
    constexpr std::array<int, 6> frames{{0, 1, 2, 3, 4, 5}};
    constexpr std::array<int, 6> ys{{notes::hud_layout::kScoreY - 32, notes::hud_layout::kBaseValueY - 32, notes::hud_layout::kGaugeY - 32,
                                     notes::hud_layout::kTokenY - 32, notes::hud_layout::kStageY - 32, notes::hud_layout::kStockY - 32}};
    for (std::size_t i = 0; i < frames.size(); ++i) {
        const int frame = frames[i] < static_cast<int>(stateFrames_.size()) ? stateFrames_[static_cast<std::size_t>(frames[i])] : -1;
        if (frame != -1) {
            DrawGraph(notes::hud_layout::kLabelX, ys[i], frame, TRUE);
        }
    }
}

void StageRuntime::drawDreamGauge(int x, int y, int value, int maxValue) const {
    const bool feverActive = value < 0;
    const float ratio = maxValue <= 0 || feverActive ? 0.0f : clampFloat(static_cast<float>(value) / static_cast<float>(maxValue), 0.0f, 1.0f);
    if (!dreamGaugeFrames_.empty() && dreamGaugeFrames_.front() != -1) {
        DrawRotaGraphF(static_cast<float>(x + notes::hud_layout::kDreamGaugePreviewCenterOffsetX),
                       static_cast<float>(y + notes::hud_layout::kDreamGaugePreviewCenterOffsetY),
                       notes::hud_layout::kDreamGaugePreviewScale, 0.0, dreamGaugeFrames_.front(), TRUE);
        if (dreamGaugeFrames_.size() > 1 && dreamGaugeFrames_[1] != -1) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(80 + ratio * 175));
            DrawRotaGraphF(static_cast<float>(x + notes::hud_layout::kDreamGaugePreviewCenterOffsetX),
                           static_cast<float>(y + notes::hud_layout::kDreamGaugePreviewCenterOffsetY),
                           notes::hud_layout::kDreamGaugePreviewScale, 0.0, dreamGaugeFrames_[1], TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
    const int width = notes::hud_layout::kGaugeBarWidth;
    const int height = notes::hud_layout::kGaugeBarHeight;
    DrawBox(x, y + 16, x + width, y + 16 + height, GetColor(32, 36, 64), TRUE);
    const int gaugeColor = feverActive ? GetColor(255, 110, 140) : GetColor(100, 220, 255);
    const int fillWidth = feverActive
                              ? static_cast<int>((width - 4) * clampFloat(static_cast<float>(-value) / static_cast<float>(kFeverActiveFrames), 0.0f, 1.0f))
                              : static_cast<int>((width - 4) * ratio);
    DrawBox(x + 2, y + 18, x + 2 + fillWidth, y + 16 + height - 2, gaugeColor, TRUE);
}

void StageRuntime::drawDataWindow2Tokens(int x, int y, int activeCount, int maxCount) const {
    activeCount = std::max(0, std::min(activeCount, maxCount));
    for (int i = 0; i < maxCount; ++i) {
        const bool active = i < activeCount;
        const int handle = dataWindow2Frames_.empty() ? -1 : dataWindow2Frames_[static_cast<std::size_t>(std::min(i, static_cast<int>(dataWindow2Frames_.size()) - 1))];
        if (handle == -1) {
            continue;
        }
        const int cx = x + i * notes::hud_layout::kPipStep;
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, active ? 255 : 90);
        DrawRotaGraphF(static_cast<float>(cx), static_cast<float>(y), 0.42, 0.0, handle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

void StageRuntime::drawHudStatusIconGroup() const {
    if (dataWindow2Frames_.empty() || dataWindow2Frames_.front() == -1) {
        drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kStockY, std::max(0, player_.lives), numSmallFrames_, 20, 30, 0.85);
        return;
    }
    const std::array<int, 3> xs{{notes::hud_layout::kStockIcon0X, notes::hud_layout::kStockIcon1X, notes::hud_layout::kStockIcon2X}};
    for (std::size_t i = 0; i < xs.size(); ++i) {
        const int handle = dataWindow2Frames_[static_cast<std::size_t>(std::min(6 + static_cast<int>(i), static_cast<int>(dataWindow2Frames_.size()) - 1))];
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(i) < player_.lives ? 255 : 90);
        DrawRotaGraphF(static_cast<float>(xs[i]), static_cast<float>(notes::hud_layout::kStockY), 0.48, 0.0, handle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
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
    for (int y : {notes::hud_layout::kScoreY, notes::hud_layout::kBaseValueY, notes::hud_layout::kGaugeY,
                  notes::hud_layout::kTokenY, notes::hud_layout::kStageY, notes::hud_layout::kStockY}) {
        DrawLine(notes::hud_layout::kDataWindowRect.x, y, notes::hud_layout::kDataWindowRect.right(), y, lineColor);
    }
    for (int i = 0; i < notes::hud_layout::kMaxTokens; ++i) {
        const int x = notes::hud_layout::kPipStartX + i * notes::hud_layout::kPipStep;
        DrawLine(x, notes::hud_layout::kTokenY - 10, x, notes::hud_layout::kTokenY + 26, GetColor(180, 255, 220));
    }
    DrawFormatString(56, 20, GetColor(255, 245, 160),
                     "F7 layout guides  player local=(%.1f, %.1f) screen=(%.1f, %.1f)",
                     player_.x, player_.y, screenX(player_.x), screenY(player_.y));
    DrawString(56, 42, "blue=StageBack  green=StageFrame  yellow=600x720 playfield  red/pink=HUD windows", GetColor(210, 220, 240));
    DrawString(56, 64, "HUD panel anchors follow FUN_1400c2860; State/DataWindow2 frame meanings remain provisional.", GetColor(255, 220, 170));
}

void StageRuntime::drawDebugOverlay() const {
    DrawFormatString(24, notes::kScreenHeight - 70, GetColor(170, 170, 190),
                     "F7 guide: HUD anchors from FUN_1400c2860; frame meanings provisional.");
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

void StageRuntime::drawHudNumber(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale) const {
    drawNumberWithSeparators(rightX, y, value, digitFrames, digitWidth, digitHeight, scale);
}

void StageRuntime::drawNumberWithSeparators(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale) const {
    const int originalValue = std::max(0, value);
    value = originalValue;
    std::array<int, 12> digits{};
    int count = 0;
    do {
        digits[static_cast<std::size_t>(count++)] = value % 10;
        value /= 10;
    } while (value > 0 && count < static_cast<int>(digits.size()));

    if (digitFrames.empty() || digitFrames.front() == -1) {
        DrawFormatString(rightX - count * digitWidth, y, GetColor(245, 245, 255), "%d", originalValue);
        return;
    }

    const int step = static_cast<int>(static_cast<double>(digitWidth) * scale);
    int x = rightX - step;
    for (int i = 0; i < count; ++i) {
        const int digit = digits[static_cast<std::size_t>(i)];
        const int handle = digit < static_cast<int>(digitFrames.size()) ? digitFrames[static_cast<std::size_t>(digit)] : -1;
        if (handle != -1) {
            DrawRotaGraphF(static_cast<float>(x + step / 2), static_cast<float>(y + static_cast<int>(digitHeight * scale) / 2), scale, 0.0, handle, TRUE);
        }
        else {
            DrawFormatString(x, y, GetColor(245, 245, 255), "%d", digit);
        }
        x -= step;
        if ((i + 1) % 3 == 0 && i + 1 < count) {
            const int commaFrame = digitFrames.size() > 10 ? digitFrames[10] : -1;
            if (commaFrame != -1) {
                DrawRotaGraphF(static_cast<float>(x + step / 2), static_cast<float>(y + static_cast<int>(digitHeight * scale) / 2), scale, 0.0, commaFrame, TRUE);
            }
            x -= step / 2;
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
