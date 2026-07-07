#include "stage_runtime.h"

#include "reconstruction_notes.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>

namespace reconstructed {
namespace {

constexpr float kPi = 3.14159265358979323846f;
constexpr float kTau = kPi * 2.0f;
constexpr int kFixedAngleFullCircle = 0x10000;
constexpr int kProjectileCap = 0x800;
constexpr int kRewardItemCap = 0x200;
constexpr int kPlayerSideObjectCap = 0x100;
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

// First-pass Stage 02 slice: a deterministic subset of the stage 02 schedule that
// preserves the observed timing/type block (0x19..0x20 plus common 0x0b/0x0d).
// It is intentionally sparse enough to be inspectable in the current runtime.
constexpr std::array<StageRuntime::StageSpawnEvent, 30> kStage02Events{{
    {120, 0x19, 800, -0x398, -20, "S02 row 1: type 0x19 patterned top lane"},
    {150, 0x19, 800, -0x2f8, -20, "S02 row 1 repeat: type 0x19 patterned top lane"},
    {180, 0x19, 800, -0x258, -20, "S02 row 1 repeat: type 0x19 patterned top lane"},
    {260, 0x1a, 300, 0x160, -20, "S02 row 2: type 0x1a randomized top entry"},
    {280, 0x1a, 300, 0x240, -20, "S02 row 2 repeat: type 0x1a randomized top entry"},
    {700, 0x07, 5000, 0x104, 0, "S02 row 3: common marker/emitter"},
    {1020, 0x1d, 0x6a4, 0x120, 0x80, "S02 row 4: type 0x1d fixed path point"},
    {1120, 0x1d, 0x6a4, 0x240, 0x90, "S02 row 4 repeat: type 0x1d fixed path point"},
    {1240, 0x1e, 0x834, 0x180, 0x60, "S02 row 5: type 0x1e path point"},
    {1400, 0x1f, 11000, 0x1e4, -0xdbe, "S02 row 6: type 0x1f long setpiece"},
    {1700, 0x0b, 400, 740, 180, "S02 row 7: reused common side entry"},
    {1760, 0x0b, 400, 740, 260, "S02 row 7 repeat: reused common side entry"},
    {1900, 0x1b, 0x1130, 0x104, 0, "S02 row 8: type 0x1b long anchor"},
    {2000, 0x1b, 0x1130, 0x1cc, 0, "S02 row 9: type 0x1b long anchor"},
    {2250, 0x0d, 400, -20, 0x96, "S02 row 10: reused common left/top entry"},
    {2420, 0x19, 500, 0x1d0, -20, "S02 row 11: type 0x19 top random entry"},
    {2560, 0x1a, 300, 0x220, -20, "S02 row 12: type 0x1a top random entry"},
    {2670, 0x1b, 0x1130, 0xf0, 0, "S02 row 13: type 0x1b anchor"},
    {2820, 0x0b, 400, 740, 180, "S02 row 14: common right entry"},
    {3000, 0x0b, 400, -20, 180, "S02 row 15: common left entry"},
    {3200, 0x1c, 6000, 0x348, 0x32, "S02 row 16: type 0x1c side setpiece"},
    {3500, 0x1a, 300, 0x1a0, -20, "S02 row 17: type 0x1a burst"},
    {3650, 0x1c, 6000, -120, 100, "S02 row 18: type 0x1c side setpiece"},
    {3900, 0x0b, 400, 0x220, -20, "S02 row 19: common top burst"},
    {4200, 0x19, 700, 0x1b0, -20, "S02 row 20: type 0x19 burst"},
    {4500, 0x1b, 4000, 0x168, 0, "S02 row 21: type 0x1b paired anchor"},
    {4580, 0x1b, 4000, 0x1fe, 0, "S02 row 22: type 0x1b paired anchor"},
    {4900, 0x1a, 300, 0x1e0, -20, "S02 row 23: type 0x1a top burst"},
    {5200, 0x1c, 0x1068, 0x348, 0x50, "S02 row 24: type 0x1c right-side setpiece"},
    {5600, 0x20, 0x2b5c, 0x168, -500, "S02 row 25: type 0x20 long stage-end setpiece"},
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

float distanceSquared(float ax, float ay, float bx, float by) {
    const float dx = ax - bx;
    const float dy = ay - by;
    return dx * dx + dy * dy;
}

bool stageUsesMediumFrame(int spawnType) {
    return spawnType == 0x06 || spawnType == 0x08 || spawnType == 0x09 || spawnType == 0x0a ||
           (spawnType >= 0x0e && spawnType <= 0x11) ||
           (spawnType >= 0x1b && spawnType <= 0x20) || spawnType == 0x138 ||
           spawnType == 0x38 || spawnType == 0x3d || spawnType == 0x3f;
}

bool isStage04FocusedType(int spawnType) {
    return spawnType == 0x35 || spawnType == 0x36 || spawnType == 0x37 ||
           spawnType == 0x38 || spawnType == 0x39 || spawnType == 0x3a ||
           spawnType == 0x3d || spawnType == 0x3f;
}

bool isStage01ObservedType(int spawnType) {
    return spawnType == 0x06 || spawnType == 0x08 || spawnType == 0x09 || spawnType == 0x0a ||
           spawnType == 0x0b || spawnType == 0x0c || spawnType == 0x0d ||
           spawnType == 0x0e || spawnType == 0x0f || spawnType == 0x10 ||
           spawnType == 0x11 || spawnType == 0x138;
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

int stageRandCoord(int frame, int modulus, int base) {
    return static_cast<int>(stageScriptRandFromFrame(frame) % static_cast<std::uint32_t>(modulus)) + base;
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

float projectileScaleForVisualSelector(int visualSelector) {
    switch (visualSelector) {
    case 0x0a:
    case 0x0b:
    case 0x10:
        return 0.82f;
    case 0x02:
    case 0x03:
        return 0.86f;
    default:
        return 0.75f;
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

std::uint16_t radiansToFixedAngle(float radians) {
    const int angle = static_cast<int>(std::lround(radians * static_cast<float>(kFixedAngleFullCircle) / kTau));
    return normalizeAngle16(angle);
}

float projectileDrawRotationForVisualSelector(int visualSelector, int age, std::uint16_t angle16) {
    // FUN_140070250 is selector-driven: some visuals preserve projectile angle,
    // while pellets/orbs/beads/diamonds overwrite it with age-based spin.
    const int ageSpinStep = projectileAgeSpinStepForVisualSelector(visualSelector);
    if (ageSpinStep != 0) {
        return fixedAngleToRadians(normalizeAngle16(age * ageSpinStep));
    }
    return fixedAngleToRadians(angle16);
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

} // namespace

const StageRuntime::StageSpawnEvent* StageRuntime::eventsForStage(int stage, std::size_t& count) {
    if (stage == 2) {
        count = kStage02Events.size();
        return kStage02Events.data();
    }
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
    enemySmallFrames_ = resources.loadDivGraph("media\\stage\\Enemy_s.png", 0xaa, 10, 0x11, 100, 100);
    enemyMediumFrames_ = resources.loadDivGraph("media\\stage\\Enemy_m.png", 0xe6, 10, 0x17, 200, 200);
    bossFrames_ = resources.loadDivGraph("media\\stage\\Boss.png", 0xa0, 10, 0x10, 200, 200);
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
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

    config_ = config;
    selectedStage_ = (config.stage == 2 || config.stage == 4) ? config.stage : 1;
    config_.stage = selectedStage_;
    initialized_ = !playerFrames_.empty() && playerFrames_.front() != -1 &&
                   !enemySmallFrames_.empty() && enemySmallFrames_.front() != -1 &&
                   !bulletFrames_.empty() && bulletFrames_.front() != -1;
    reset();
    return initialized_;
}

void StageRuntime::setStage(int stage) {
    auto next = config_;
    next.stage = stage;
    setConfig(next);
}

void StageRuntime::setConfig(const StageRuntimeConfig& config) {
    auto next = config;
    const int normalized = (next.stage == 2 || next.stage == 4) ? next.stage : 1;
    next.stage = normalized;
    const bool changed = selectedStage_ != normalized || config_.routeMode != next.routeMode ||
                         config_.playerOption != next.playerOption || config_.subOption != next.subOption ||
                         config_.loadoutId != next.loadoutId || config_.difficulty != next.difficulty ||
                         config_.counterMode != next.counterMode || config_.optionSlots != next.optionSlots;
    config_ = next;
    if (changed) {
        selectedStage_ = normalized;
        reset();
    }
}

void StageRuntime::reset() {
    frame_ = 0;
    player_ = {};
    nextEntityId_ = 1;
    enemies_.reserve(512);
    rewardItems_.reserve(kRewardItemCap);
    stage01GateFlag_ = false;
    stage01EndVisualQueued_ = false;
    stage01EndFlushed_ = false;
    stage01BossSpawned_ = false;
    enemies_.clear();
    pendingEnemies_.clear();
    enemyProjectiles_.clear();
    playerSideObjects_.clear();
    playerShots_.clear();
    rewardItems_.clear();
}

void StageRuntime::update() {
    if (!initialized_) {
        return;
    }

    updateLayoutGuideToggle();

    if (CheckHitKey(KEY_INPUT_R) != 0) {
        reset();
        return;
    }

    spawnDueEvents();
    updatePlayer();
    updatePlayerSideObjects();
    updatePlayerShots();
    updateEnemies();
    updateProjectiles();
    updateRewardItems();
    handleCollisions();

    enemies_.erase(std::remove_if(enemies_.begin(), enemies_.end(), [](const StageEnemy& enemy) {
                       return !enemy.active || offscreen(enemy.x, enemy.y, 360.0f) || enemy.age > enemy.lifetime;
                   }), enemies_.end());
    enemyProjectiles_.erase(std::remove_if(enemyProjectiles_.begin(), enemyProjectiles_.end(), [](const StageProjectile& projectile) {
                                return !projectile.active || offscreen(projectile.x, projectile.y, 80.0f);
                            }), enemyProjectiles_.end());
    playerSideObjects_.erase(std::remove_if(playerSideObjects_.begin(), playerSideObjects_.end(), [](const PlayerSideObject& object) {
                                 return !object.active || offscreen(object.x, object.y, 80.0f);
                             }), playerSideObjects_.end());
    rewardItems_.erase(std::remove_if(rewardItems_.begin(), rewardItems_.end(), [](const RewardItem& item) {
                           return !item.active || offscreen(item.x, item.y, 120.0f);
                       }), rewardItems_.end());
    playerShots_.erase(std::remove_if(playerShots_.begin(), playerShots_.end(), [](const PlayerShot& shot) {
                           return !shot.active || shot.y < -40.0f;
                       }), playerShots_.end());

    ++frame_;
}

void StageRuntime::draw() const {
    drawBackground();
    drawPlayerSideObjects();
    drawPlayerShots();
    drawEnemies();
    drawProjectiles();
    drawRewardItems();
    drawPlayer();
    drawOverlay();
}

int StageRuntime::enemiesAlive() const {
    return static_cast<int>(enemies_.size());
}

int StageRuntime::enemyProjectilesAlive() const {
    return static_cast<int>(enemyProjectiles_.size());
}

void StageRuntime::spawnDueEvents() {
    if (selectedStage_ == 1) {
        spawnStage01OriginalSchedule();
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
    auto spawn = [this](int type, int lifetime, int x, int y, const char* note) {
        spawnEnemy({frame_, type, lifetime, x, y, note});
    };
    auto spawn0bTop = [&](int lifetime, int modulus, int base, const char* note) {
        spawn(0x0b, lifetime, stageRandCoord(f, modulus, base), -20, note); // original y literal: 0xffffffec
    };
    auto spawn0bLeft = [&](int lifetime, int modulus, int base, const char* note) {
        spawn(0x0b, lifetime, -20, stageRandCoord(f, modulus, base), note); // original x literal: 0xffffffec
    };
    auto spawn0bRight = [&](int lifetime, int modulus, int base, const char* note) {
        spawn(0x0b, lifetime, 0x2e4, stageRandCoord(f, modulus, base), note);
    };
    auto spawn0cTop = [&](const char* note) {
        spawn(0x0c, 400, stageRandCoord(f, 0x191, 0xa0), -20, note); // original y literal: 0xffffffec
    };
    auto spawn0dLeft = [&](int lifetime, int modulus, int base, const char* note) {
        spawn(0x0d, lifetime, -20, stageRandCoord(f, modulus, base), note); // original x literal: 0xffffffec
    };
    auto spawn0dRight = [&](int lifetime, int modulus, int base, const char* note) {
        spawn(0x0d, lifetime, 0x2e4, stageRandCoord(f, modulus, base), note);
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
        spawn(0x138, 100000, 300, 180, "S01 boss handoff: endFrame + 0x3c entity 0x138");
        stage01BossSpawned_ = true;
    }
}

void StageRuntime::spawnStage04OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int lifetime, int x, int y, const char* note) {
        spawnEnemy({frame_, type, lifetime, x, y, note});
    };
    auto spawnEvery = [&](int start, int duration, int step, int type, int lifetime, int x, int y, const char* note) {
        const int local = f - start;
        if (local >= 0 && local < duration && local % step == 0) {
            spawn(type, lifetime, x, y, note);
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
    auto spawn0bTop = [&](int lifetime, int modulus, int base, const char* note) { spawn(0x0b, lifetime, randX(modulus, base, 7), -20, note); };
    auto spawn0bLeft = [&](int lifetime, int modulus, int base, const char* note) { spawn(0x0b, lifetime, -20, randX(modulus, base, 11), note); };
    auto spawn0bRight = [&](int lifetime, int modulus, int base, const char* note) { spawn(0x0b, lifetime, 0x2e4, randX(modulus, base, 13), note); };

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
}

void StageRuntime::spawnEnemy(const StageSpawnEvent& event) {
    StageEnemy enemy;
    enemy.entityId = nextEntityId_++;
    enemy.spawnType = event.spawnType;
    enemy.lifetime = event.lifetime;
    enemy.sourceLifetime = event.lifetime;
    enemy.sourceX = event.x;
    enemy.sourceY = event.y;
    enemy.sourceNote = event.sourceNote;
    if (selectedStage_ == 1 && isStage01ObservedType(event.spawnType)) {
        enemy.updateCase = stage01UpdateCaseForSpawnType(event.spawnType);
        enemy.sourceDispatchKind = stage01DispatchKindForSpawnType(event.spawnType);
        enemy.sourceDispatchField = stage01DispatchFieldForSpawnType(event.spawnType);
        enemy.activationDelay = event.spawnType == 0x138 ? 60 : 0;
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
        break;
    case 0x0a:
        enemy.hp = 20;
        enemy.radius = 34;
        enemy.visualFrame = 15;
        enemy.vy = 0.65f;
        break;
    case 0x0b:
        enemy.hp = 8;
        enemy.radius = 24;
        enemy.visualFrame = 4;
        enemy.speed = 1.7f;
        break;
    case 0x0c:
    case 0x0d:
        enemy.hp = 10;
        enemy.radius = 24;
        enemy.visualFrame = event.spawnType == 0x0c ? 6 : 9;
        enemy.speed = 1.45f;
        break;
    case 0x0e:
        enemy.hp = 36;
        enemy.radius = 48;
        enemy.visualFrame = 16;
        enemy.vy = 0.25f;
        break;
    case 0x0f:
        enemy.hp = 36;
        enemy.radius = 48;
        enemy.visualFrame = 22;
        enemy.vy = 0.25f;
        break;
    case 0x10:
        enemy.hp = 36;
        enemy.radius = 48;
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
        enemy.radius = 72;
        enemy.visualFrame = 0;
        enemy.vy = 0.0f;
        enemy.activationDelay = 60;
        break;
    case 0x19:
    case 0x1a:
        enemy.hp = 12;
        enemy.radius = 26;
        enemy.visualFrame = 34 + (event.spawnType - 0x19) * 4;
        enemy.speed = event.spawnType == 0x19 ? 1.35f : 1.75f;
        break;
    case 0x1b:
    case 0x1c:
        enemy.hp = 32;
        enemy.radius = 44;
        enemy.visualFrame = 108 + (event.spawnType - 0x1b) * 3;
        enemy.vy = 0.18f;
        break;
    case 0x1d:
    case 0x1e:
        enemy.hp = 18;
        enemy.radius = 32;
        enemy.visualFrame = 46 + (event.spawnType - 0x1d) * 6;
        enemy.speed = 1.15f;
        break;
    case 0x1f:
    case 0x20:
        enemy.hp = 48;
        enemy.radius = 58;
        enemy.visualFrame = 132;
        enemy.vy = 0.35f;
        break;
    case 0x35:
        enemy.hp = 18;
        enemy.radius = 28;
        enemy.visualFrame = 34;
        enemy.speed = 5.0f;
        break;
    case 0x36:
    case 0x37:
        enemy.hp = 14;
        enemy.radius = 26;
        enemy.visualFrame = event.spawnType == 0x36 ? 36 : 40;
        enemy.speed = event.spawnType == 0x36 ? 3.2f : 1.7f;
        enemy.activationDelay = event.spawnType == 0x37 ? 96 : 24;
        break;
    case 0x38:
        enemy.hp = 80;
        enemy.radius = 56;
        enemy.visualFrame = 120;
        enemy.vy = 0.2f;
        enemy.activationDelay = 48;
        break;
    case 0x39:
    case 0x3a:
        enemy.hp = 50;
        enemy.radius = 44;
        enemy.visualFrame = event.spawnType == 0x39 ? 124 : 128;
        enemy.speed = 1.1f;
        enemy.activationDelay = 40;
        break;
    case 0x3d:
        enemy.hp = 64;
        enemy.radius = 48;
        enemy.visualFrame = 134;
        enemy.vy = 0.16f;
        enemy.activationDelay = 36;
        break;
    case 0x3f:
        enemy.hp = 240;
        enemy.radius = 70;
        enemy.visualFrame = 138;
        enemy.vy = 0.1f;
        enemy.activationDelay = 60;
        break;
    default:
        enemy.hp = 12;
        enemy.radius = 28;
        enemy.visualFrame = 8;
        enemy.speed = 1.2f;
        break;
    }

    enemies_.push_back(enemy);
}

void StageRuntime::spawnStage01Child(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int lifetime, const char* note) {
    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = 0x11;
    child.lifetime = lifetime;
    child.sourceLifetime = lifetime;
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
    child.hp = 18;
    child.radius = 22;
    child.visualFrame = 32 + (childIndex % 2);
    child.activationDelay = 0;
    child.helperState = 0;
    pendingEnemies_.push_back(child);
}

void StageRuntime::spawnStage01MarkerSatellite(StageEnemy& parent, int childIndex, float offsetX, float offsetY, int lifetime, const char* note) {
    StageEnemy satellite;
    satellite.entityId = nextEntityId_++;
    satellite.spawnType = 0x09;
    satellite.lifetime = lifetime;
    satellite.sourceLifetime = lifetime;
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
    satellite.hp = 10;
    satellite.radius = 18;
    satellite.visualFrame = 11;
    satellite.activationDelay = 0;
    satellite.helperState = 0;
    pendingEnemies_.push_back(satellite);
}

void StageRuntime::updatePlayer() {
    player_.focused = CheckHitKey(KEY_INPUT_LSHIFT) != 0 || CheckHitKey(KEY_INPUT_RSHIFT) != 0;
    const float speed = player_.focused ? 3.0f : 5.5f;
    float dx = 0.0f;
    float dy = 0.0f;
    if (CheckHitKey(KEY_INPUT_LEFT) != 0) dx -= 1.0f;
    if (CheckHitKey(KEY_INPUT_RIGHT) != 0) dx += 1.0f;
    if (CheckHitKey(KEY_INPUT_UP) != 0) dy -= 1.0f;
    if (CheckHitKey(KEY_INPUT_DOWN) != 0) dy += 1.0f;
    if (dx != 0.0f && dy != 0.0f) {
        dx *= 0.70710678f;
        dy *= 0.70710678f;
    }
    constexpr float kPlayerClampInset = 4.0f;
    player_.x = clampFloat(player_.x + dx * speed, kPlayLeft + kPlayerClampInset, kPlayRight - kPlayerClampInset);
    player_.y = clampFloat(player_.y + dy * speed, kPlayTop + kPlayerClampInset, kPlayBottom - kPlayerClampInset);

    if (player_.invulnerableFrames > 0) {
        --player_.invulnerableFrames;
    }
    if (CheckHitKey(KEY_INPUT_Z) != 0) {
        ++player_.shotTimer;
        if (player_.shotTimer % 5 == 1) {
            emitPlayerNormalShot();
        }
    }
    else {
        player_.shotTimer = 0;
    }
}

void StageRuntime::updateEnemies() {
    for (auto& enemy : enemies_) {
        ++enemy.age;
        if (enemy.age <= enemy.activationDelay) {
            enemy.vx *= 0.92f;
            enemy.vy *= 0.92f;
            continue;
        }
        const int activeAge = enemy.age - enemy.activationDelay;
        if (selectedStage_ == 1 && isStage01ObservedType(enemy.spawnType)) {
            updateStage01Enemy(enemy, activeAge);
        }
        else if (isStage04FocusedType(enemy.spawnType)) {
            updateStage04Enemy(enemy, activeAge);
        }
        else {
            updateGenericEnemy(enemy, activeAge);
        }

        enemy.x += enemy.vx;
        enemy.y += enemy.vy;

        if (selectedStage_ == 1 && isStage01ObservedType(enemy.spawnType)) {
            emitStage01Projectiles(enemy, activeAge);
        }
        else if (isStage04FocusedType(enemy.spawnType)) {
            emitStage04Projectiles(enemy, activeAge);
        }
        else {
            emitGenericProjectiles(enemy, activeAge);
        }
    }
    if (!pendingEnemies_.empty()) {
        enemies_.insert(enemies_.end(), pendingEnemies_.begin(), pendingEnemies_.end());
        pendingEnemies_.clear();
    }
}

void StageRuntime::updateStage01Enemy(StageEnemy& enemy, int activeAge) {
    // Stage 01 type routing is evidence-backed by stage-spawn-used-update-map.md:
    // 0x0a->FUN_14007c9c0, 0x0b->FUN_14007d4e0, 0x0c->FUN_14007dfb0,
    // 0x0d->FUN_14007ea30, 0x0e->FUN_14007f2c0, 0x0f->FUN_140080170,
    // 0x10->FUN_140080fb0, 0x11->FUN_140082090, 0x06/0x08->FUN_140082d90,
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
    case 0x0f:
    case 0x10:
        updateStage01Setpiece(enemy, activeAge);
        break;
    case 0x11:
        updateStage01Child(enemy, activeAge);
        break;
    case 0x09:
        updateStage01MarkerSatellite(enemy, activeAge);
        break;
    case 0x06:
    case 0x08:
        updateStage01Marker(enemy, activeAge);
        break;
    case 0x138:
        enemy.vx = std::sin(enemy.age * 0.025f) * 0.25f;
        enemy.vy = std::sin(enemy.age * 0.017f) * 0.08f;
        enemy.angle = aimAtPlayer(enemy.x, enemy.y);
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
    // FUN_14007c9c0: two-state early Stage 1 enemy. State 0 lasts 0x78
    // frames, then state 1 tracks the player for 300 frames before turning
    // toward fixed angle 0xc000 and accelerating away. The exact random entry
    // jitter and draw overlays are still deferred; movement/shot timing below
    // follows the confirmed state/cadence structure.
    if (enemy.helperState == 0) {
        const float t = clampFloat(static_cast<float>(activeAge) / 120.0f, 0.0f, 1.0f);
        const float wobble = std::sin((enemy.age + enemy.sourceX * 3) * 0.08f) * (1.0f - t) * 12.0f;
        enemy.x = enemy.originX + wobble;
        enemy.y = enemy.originY + std::sin((enemy.age + enemy.sourceY * 5) * 0.07f) * (1.0f - t) * 8.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= 0x78) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = 0.8;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            enemy.secondaryAngle16 = enemy.sourceAngle16;
        }
        return;
    }

    const int stateAge = enemy.age;
    if (enemy.sourceSpeed <= 0.0) {
        enemy.sourceSpeed = 0.8;
    }
    if (stateAge < 300) {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)), 0x100);
    }
    else {
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x100);
        enemy.sourceSpeed += 1.0 / 60.0;
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = std::cos(enemy.angle) * enemy.speed;
    enemy.vy = std::sin(enemy.angle) * enemy.speed;
}

void StageRuntime::updateStage01Type0B(StageEnemy& enemy, int activeAge) {
    // Evidence: FUN_14007d4e0 @ 0x14007d4e0. State 0 draws the entry effect
    // for 0x14 frames, then state 1 tracks for 200 frames with 0x80-angle
    // steps, exits toward 0xc000 with 0x200 steps, and accelerates by 1/60.
    updateStage01SmallChaser(enemy, activeAge, 0x14, 200, 0x80, 0x200, 1.0, 1.0);
}

void StageRuntime::updateStage01Type0C(StageEnemy& enemy, int activeAge) {
    // Evidence: FUN_14007dfb0 @ 0x14007dfb0. The structure matches 0x0b,
    // but uses a 0x100 exit turn step and a randomized decoded initial speed
    // range; runtime keeps the lower confirmed bound as the playable baseline.
    updateStage01SmallChaser(enemy, activeAge, 0x14, 200, 0x80, 0x100, stage01SpeedConstantValue(0x0b0), 1.0);
}

void StageRuntime::updateStage01Type0D(StageEnemy& enemy, int activeAge) {
    // Evidence: FUN_14007ea30 @ 0x14007ea30. This helper is not the shared
    // chaser: after the 0x14-frame entry effect it moves with a side-selected
    // fixed angle (0xf2fb from left, 0x8d05 from right) and speed 3.0/4.0.
    if (enemy.helperState == 0) {
        const float t = clampFloat(static_cast<float>(activeAge) / 20.0f, 0.0f, 1.0f);
        enemy.x = enemy.originX;
        enemy.y = enemy.originY - (1.0f - t) * 20.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= 0x14) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = selectedStage_ > 3 ? stage01SpeedConstantValue(0x070) : stage01SpeedConstantValue(0x018);
            enemy.sourceAngle16 = enemy.sourceX <= 0.0f ? 0xf2fb : 0x8d05;
            enemy.secondaryAngle16 = enemy.sourceAngle16;
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
        }
        return;
    }

    const int stateAge = enemy.age;
    if (enemy.sourceSpeed <= 0.0) {
        enemy.sourceSpeed = selectedStage_ > 3 ? stage01SpeedConstantValue(0x070) : stage01SpeedConstantValue(0x018);
    }
    const float bodyWave = std::sin(stateAge * 0.035f) * 5.5f;
    const float verticalWave = std::sin(stateAge * 0.07f) * 1.2f;
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = std::cos(enemy.angle) * enemy.speed;
    enemy.vy = std::sin(enemy.angle) * enemy.speed + verticalWave;
    enemy.x += bodyWave * 0.02f;
}

void StageRuntime::updateStage01SmallChaser(StageEnemy& enemy, int activeAge, int enterFrames, int trackFrames, int turnStep, int exitTurnStep, double initialSpeed, double floorSpeed) {
    // Shared structure for FUN_14007d4e0 (0x0b) and FUN_14007dfb0 (0x0c): a
    // short state-0 entry display, then state-1 motion that turns toward the
    // player for a fixed window and exits toward 0xc000 while accelerating.
    // Exact original effect/list overlay allocation remains deferred.
    if (enemy.helperState == 0) {
        const float t = clampFloat(static_cast<float>(activeAge) / static_cast<float>(std::max(1, enterFrames)), 0.0f, 1.0f);
        enemy.x = enemy.originX;
        enemy.y = enemy.originY - (1.0f - t) * 20.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= enterFrames) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = initialSpeed;
            if (enemy.sourceX <= 0) {
                enemy.sourceAngle16 = 0x0000;
            }
            else if (enemy.sourceX >= 0x2e4) {
                enemy.sourceAngle16 = 0x8000;
            }
            else {
                enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            }
            enemy.secondaryAngle16 = enemy.sourceAngle16;
        }
        return;
    }

    const int stateAge = enemy.age;
    if (enemy.sourceSpeed <= 0.0) {
        enemy.sourceSpeed = initialSpeed;
    }
    const std::uint16_t target = stateAge < trackFrames ? radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)) : 0xc000;
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, stateAge < trackFrames ? turnStep : exitTurnStep);
    if (stateAge < trackFrames) {
        enemy.sourceSpeed = std::max(floorSpeed, enemy.sourceSpeed - 1.0 / 60.0);
    }
    else {
        enemy.sourceSpeed += 1.0 / 60.0;
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    enemy.speed = static_cast<float>(enemy.sourceSpeed);
    enemy.vx = std::cos(enemy.angle) * enemy.speed;
    enemy.vy = std::sin(enemy.angle) * enemy.speed;
}

void StageRuntime::updateStage01Setpiece(StageEnemy& enemy, int activeAge) {
    // FUN_14007f2c0/140080170/140080fb0 are long-lived Stage 1 sources. They
    // enter after 0x14 frames and then run mostly as scripted pattern anchors.
    // This preserves their state timing and broad motion role; exact effect
    // overlays remain deferred.
    if (enemy.helperState == 0) {
        const float t = clampFloat(static_cast<float>(activeAge) / 20.0f, 0.0f, 1.0f);
        enemy.y = enemy.originY - (1.0f - t) * 50.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        if (activeAge >= 0x14) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            if (enemy.spawnType == 0x0e) enemy.sourceSpeed = 7.0;
            else if (enemy.spawnType == 0x0f) enemy.sourceSpeed = 9.0;
            else enemy.sourceSpeed = 0.7;
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

    const int trackFrames = enemy.spawnType == 0x0e ? 300 : 300;
    enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y)), 0x80);
    if (stateAge > trackFrames) {
        enemy.sourceSpeed = std::max(1.2, enemy.sourceSpeed - 1.0 / 60.0);
    }
    enemy.angle = fixedAngleToRadians(enemy.sourceAngle16);
    const float wobble = std::sin((stateAge + enemy.spawnType * 23) * 0.025f) * (enemy.spawnType == 0x0e ? 0.6f : 0.9f);
    enemy.vx = std::cos(enemy.angle) * static_cast<float>(enemy.sourceSpeed) * 0.15f + wobble;
    enemy.vy = std::sin(enemy.angle) * static_cast<float>(enemy.sourceSpeed) * 0.12f;
}

void StageRuntime::updateStage01Marker(StageEnemy& enemy, int activeAge) {
    // FUN_140082d90 is used by common marker/emitter types 0x06/0x08. It
    // spawns child entities based on route/difficulty and then behaves as a
    // low-motion pattern anchor. The child helper is represented by spawnType
    // 0x11; effect-node overlays from the original helper remain deferred.
    if (enemy.helperState == 0) {
        if (activeAge >= 0x14) {
            enemy.helperState = 1;
            enemy.age = 0;
            enemy.sourceSpeed = 1.0;
            enemy.sourceAngle16 = radiansToFixedAngle(aimAtPlayer(enemy.x, enemy.y));
            const float spacing = enemy.spawnType == 0x08 ? 56.0f : 44.0f;
            spawnStage01MarkerSatellite(enemy, 0, -spacing, 24.0f, 3000, "S01 marker satellite 0x09 left from FUN_140082d90");
            spawnStage01MarkerSatellite(enemy, 1, spacing, 24.0f, 3000, "S01 marker satellite 0x09 right from FUN_140082d90");
            spawnStage01Child(enemy, 0, -spacing * 0.7f, 46.0f, 360, "S01 marker child 0x11 left anchor from FUN_140082d90");
            spawnStage01Child(enemy, 1, spacing * 0.7f, 46.0f, 360, "S01 marker child 0x11 right anchor from FUN_140082d90");
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
    // FUN_140083db0: child/satellite type spawned by marker helper 0x06/0x08.
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
        enemy.sourceAngle16 = normalizeAngle16(static_cast<int>(enemy.entityId * 0x1111));
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
    // emits projectile id 7 and id 9. Parent-id lookup is represented by the
    // captured parent entity id; if the parent is gone, the child expires.
    StageEnemy* parent = nullptr;
    for (auto& candidate : enemies_) {
        if (candidate.entityId == enemy.parentEntityId && candidate.active && candidate.spawnType == enemy.parentSpawnType) {
            parent = &candidate;
            break;
        }
    }
    if (parent == nullptr) {
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

void StageRuntime::emitStage01Projectiles(StageEnemy& enemy, int activeAge) {
    if (enemy.spawnType == 0x0a) {
        // FUN_14007c9c0 fires projectile id 4 during state 1, while state age
        // is below 300. Difficulty controls the first volley frame and repeat
        // interval; each volley has a short 20-frame window and fires every 3
        // frames. Original emits left/right/center offsets, plus extra center
        // speed/angle variants on higher difficulties.
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

        const float bulletSpeed = stage01Type0AProjectileSpeed(difficulty, selectedStage_);
        const float centerAngle = fixedAngleToRadians(enemy.secondaryAngle16 != 0 ? enemy.secondaryAngle16 : enemy.sourceAngle16);
        const float aimCenter = aimAtPlayer(enemy.x, enemy.y);
        enemy.secondaryAngle16 = approachAngle16(enemy.secondaryAngle16, radiansToFixedAngle(aimCenter), 0x40);
        const float y = enemy.y - 18.0f;
        spawnProjectileNode(4, 0, enemy.x + 24.0f, y, centerAngle, bulletSpeed, 5);
        spawnProjectileNode(4, 0, enemy.x - 24.0f, y, centerAngle, bulletSpeed, 5);
        spawnProjectileNode(4, 0, enemy.x, enemy.y - 34.0f, centerAngle, bulletSpeed, 5);
        if (difficulty > 2) {
            spawnProjectileNode(4, 0, enemy.x, enemy.y - 34.0f, centerAngle, bulletSpeed + 0.5f, 5);
        }
        if (difficulty > 3) {
            spawnProjectileNode(4, 0, enemy.x, enemy.y - 34.0f, centerAngle - 0.12f, bulletSpeed, 5);
            spawnProjectileNode(4, 0, enemy.x, enemy.y - 34.0f, centerAngle + 0.12f, bulletSpeed, 5);
        }
        return;
    }

    if (enemy.spawnType == 0x0b) {
        // FUN_14007d4e0: projectile id 0, active for state-age < 200, with a
        // repeating burst window of interval*3 frames and shots every interval.
        if (enemy.helperState != 1 || enemy.age >= 200) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int start = stage01Type0BShotStartFrame(difficulty);
        const int interval = stage01Type0BShotInterval(difficulty, selectedStage_);
        if (enemy.age < start || interval <= 0) return;
        const int local = (enemy.age - start) % (interval * 5);
        if (local >= interval * 3 || local % interval != 0) return;
        const float shotX = enemy.x;
        const float shotY = enemy.y + 18.0f;
        const float angle = aimAtPlayer(shotX, shotY);
        const float speed = stage01Type0BProjectileSpeed(difficulty, selectedStage_);
        spawnProjectileNode(0, local / interval, shotX, shotY, angle, speed, 5);
        if (difficulty > 2) {
            spawnProjectileNode(0, 0, shotX, shotY, angle, speed + 0.35f, 5);
        }
        return;
    }

    if (enemy.spawnType == 0x0c) {
        // FUN_14007dfb0: projectile id 7, state-age < 200, burst window of
        // roughly 0x28 frames with shots every 5 frames. It emits symmetric
        // left/right sources and adds extra angled variants on high difficulty.
        if (enemy.helperState != 1 || enemy.age >= 200) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int start = stage01Type0CShotStartFrame(difficulty, selectedStage_);
        const int interval = stage01Type0CShotInterval(difficulty, selectedStage_);
        if (enemy.age < start || interval <= 0) return;
        const int local = (enemy.age - start) % interval;
        if (local > 0x27 || local % 5 != 0) return;
        const float speed = stage01Type0CProjectileSpeed(difficulty, selectedStage_) + static_cast<float>(local / 5) * 0.08f;
        const float leftX = enemy.x - 24.0f;
        const float rightX = enemy.x + 24.0f;
        const float y = enemy.y;
        const float leftAngle = aimAtPlayer(leftX, y);
        const float rightAngle = aimAtPlayer(rightX, y);
        spawnProjectileNode(7, 0, rightX, y, rightAngle, speed, 5);
        spawnProjectileNode(7, 0, leftX, y, leftAngle, speed, 5);
        if (difficulty > 2) {
            spawnProjectileNode(7, 0, rightX, y, rightAngle - 0.11f, speed + 0.25f, 5);
            spawnProjectileNode(7, 0, leftX, y, leftAngle + 0.11f, speed + 0.25f, 5);
        }
        return;
    }

    if (enemy.spawnType == 0x0d) {
        // FUN_14007ea30: side-entry source that fires projectile id 0 from an
        // offset side point whenever the global stage frame hits its difficulty
        // interval. Original also emits a paired accelerated shot.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int interval = stage01Type0DShotInterval(difficulty, selectedStage_);
        if (interval <= 0 || frame_ % interval != 0) return;
        const bool fromLeft = enemy.sourceX < 0x168;
        const float shotX = enemy.x + (fromLeft ? -24.0f : 24.0f);
        const float shotY = enemy.y - 20.0f;
        const float angle = aimAtPlayer(shotX, shotY);
        const float speed = stage01Type0DProjectileSpeed(difficulty, selectedStage_);
        spawnProjectileNode(0, frame_ % interval, shotX, shotY, angle, speed, 5);
        spawnProjectileNode(0, 0, shotX, shotY, angle, speed + 0.3f, 5);
        return;
    }

    if (enemy.spawnType == 0x0e) {
        // FUN_14007f2c0: multipart source. It alternates projectile id 9 from
        // left/right offsets and later emits id 0 spreads. Exact sprite child
        // overlays are deferred.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int cycle = enemy.age % 0x96;
        const int fanCount = difficulty == 0 ? 4 : difficulty == 1 ? 6 : difficulty == 2 ? 10 : difficulty == 3 ? 12 : 13;
        const float speed = stage01DecodedSpeedForOffsets(difficulty, selectedStage_, {0x0f8, 0x158, 0x190, 0x1b8, 0x208}, {0x0f8, 0x158, 0x190, 0x1b8, 0x208});
        if ((cycle < 0x1e && cycle % 5 == 0) || (cycle >= 0x28 && cycle < 0x46 && (cycle - 0x28) % 5 == 0)) {
            const float side = cycle < 0x28 ? 42.0f : -42.0f;
            const float x = enemy.x + side;
            const float y = enemy.y + std::sin(enemy.age * 0.04f) * 18.0f;
            spawnProjectileNode(9, 0, x, y, aimAtPlayer(x, y), speed, 7);
            if (difficulty > 1) {
                spawnProjectileSpread(9, 0, x, y, aimAtPlayer(x, y), speed - 0.35f, 7, 2, 0.22f + difficulty * 0.04f);
            }
            return;
        }
        if (cycle >= 0x50 && cycle < 0x78) {
            const int interval = difficulty < 2 ? 0x28 : 0x1e;
            if ((cycle - 0x50) % interval == 0) {
                spawnProjectileSpread(0, cycle / std::max(1, interval), enemy.x, enemy.y + 24.0f, aimAtPlayer(enemy.x, enemy.y), speed - 0.55f, 5, fanCount, kPi * 0.85f);
            }
        }
        return;
    }

    if (enemy.spawnType == 0x0f) {
        // FUN_140080170: side setpiece with paired id 5/id 1 volleys and later
        // denser spread phases. This keeps the confirmed paired-source shape.
        if (enemy.helperState != 1) return;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int cycle = (enemy.age - 0x28) % (difficulty == 0 ? 200 : difficulty == 1 ? 0x78 : difficulty == 2 ? 100 : 0x5a);
        if (enemy.age < 0x28 || cycle < 0) return;
        const int activeWindow = difficulty == 0 ? 0x1e : difficulty == 1 ? 0x28 : 0x32;
        if (cycle >= activeWindow) return;
        const float speed = stage01DecodedSpeedForOffsets(difficulty, selectedStage_, {0x070, 0x0d0, 0x0f8, 0x138, 0x190}, {0x070, 0x0d0, 0x0f8, 0x138, 0x190}) + cycle * 0.01f;
        const float leftX = enemy.x - 34.0f;
        const float rightX = enemy.x + 34.0f;
        const float y = enemy.y - 28.0f;
        if (cycle % 2 == 0) {
            spawnProjectileNode(5, 0, rightX, y, aimAtPlayer(rightX, y) + std::sin(frame_ * 0.03f) * 0.08f, speed, 6);
            spawnProjectileNode(5, 0, leftX, y, aimAtPlayer(leftX, y) - std::sin(frame_ * 0.03f) * 0.08f, speed, 6);
        }
        if ((cycle & 1) == 1) {
            spawnProjectileNode(1, 0, rightX, y, aimAtPlayer(rightX, y), speed, 5);
            spawnProjectileNode(1, 0, leftX, y, aimAtPlayer(leftX, y), speed, 5);
        }
        if (cycle == 0x41 || (difficulty > 2 && cycle % 0x20 == 0)) {
            spawnProjectileSpread(0, 0, enemy.x, enemy.y + 20.0f, aimAtPlayer(enemy.x, enemy.y), speed - 0.4f, 5, 5 + difficulty * 2, kPi * 0.7f);
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
        // projectile id 7 during the first 300 aimed frames, then id 9 arced
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

    if (enemy.spawnType == 0x09) {
        if (enemy.age % 90 == 0) {
            spawnProjectileNode(0, 0, enemy.x, enemy.y, enemy.sourceAngle16, 0.0f, stage01MarkerProjectileSpeed(std::clamp(config_.difficulty, 0, 4)) * 0.65f, 5, 0);
        }
        return;
    }

    if (enemy.spawnType == 0x06 || enemy.spawnType == 0x08) {
        // FUN_140082d90: common marker/emitter. It spawns child 0x11 anchors;
        // the marker itself also keeps the confirmed id 0 spread cadence.
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

    if (enemy.spawnType == 0x138) {
        if (enemy.age % 90 == 0) {
            const int difficulty = std::clamp(config_.difficulty, 0, 4);
            spawnProjectileSpread(0, 0, enemy.x, enemy.y + 20.0f, aimAtPlayer(enemy.x, enemy.y), stage01SpeedConstantValue(0x0f8), 5, 8 + difficulty * 2, kTau);
        }
        return;
    }

    // Stage 01 projectile emission belongs in the per-type helpers above once
    // their original callsites are ported. Until then, keep the old generic
    // playable fallback separate so it is not mistaken for original behavior.
    emitGenericProjectiles(enemy, activeAge);
}

void StageRuntime::updateStage04Enemy(StageEnemy& enemy, int activeAge) {
    switch (enemy.spawnType) {
    case 0x35: {
        const float desired = aimAtPlayer(enemy.x, enemy.y + 48.0f);
        enemy.angle = approachAngle(enemy.angle, desired, activeAge < 100 ? 0.12f : 0.025f);
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        if (activeAge > 100) {
            enemy.speed = std::max(1.4f, enemy.speed - 0.035f);
        }
        break;
    }
    case 0x36: {
        const float exitAngle = kPi * 0.5f;
        const float desired = activeAge < 200 ? aimAtPlayer(enemy.x, enemy.y) : exitAngle;
        enemy.angle = approachAngle(enemy.angle, desired, activeAge < 200 ? 0.08f : 0.045f);
        if (activeAge > 220) {
            enemy.speed = std::max(1.4f, enemy.speed - 0.018f);
        }
        enemy.vx = std::cos(enemy.angle) * enemy.speed;
        enemy.vy = std::sin(enemy.angle) * enemy.speed;
        break;
    }
    case 0x37: {
        const float wobble = std::sin((enemy.age + enemy.spawnType * 11) * 0.06f);
        enemy.angle = approachAngle(enemy.angle, aimAtPlayer(enemy.x, enemy.y), 0.03f);
        const float speedPulse = 0.75f + std::sin(activeAge * 0.045f) * 0.35f;
        enemy.vx = std::cos(enemy.angle) * enemy.speed * speedPulse + wobble * 0.9f;
        enemy.vy = std::sin(enemy.angle) * enemy.speed * speedPulse;
        break;
    }
    case 0x38:
        enemy.angle = approachAngle(enemy.angle, aimAtPlayer(enemy.x, enemy.y), 0.018f);
        enemy.vx = std::sin((activeAge + enemy.spawnType * 17) * 0.024f) * 1.05f;
        enemy.vy = activeAge < 90 ? 0.18f : std::sin(activeAge * 0.018f) * 0.22f;
        break;
    case 0x39:
    case 0x3a: {
        const float sign = enemy.spawnType == 0x39 ? 1.0f : -1.0f;
        enemy.angle = approachAngle(enemy.angle, aimAtPlayer(enemy.x, enemy.y), 0.035f);
        enemy.vx = sign * std::sin(activeAge * 0.025f) * 1.8f;
        enemy.vy = 0.55f + std::cos(activeAge * 0.03f) * 0.45f;
        break;
    }
    case 0x3d:
        enemy.angle = approachAngle(enemy.angle, aimAtPlayer(enemy.x, enemy.y), 0.02f);
        enemy.vx = std::sin((activeAge + enemy.spawnType * 13) * 0.018f) * 0.75f;
        enemy.vy = 0.10f + std::sin(activeAge * 0.015f) * 0.16f;
        break;
    case 0x3f:
        enemy.angle = approachAngle(enemy.angle, aimAtPlayer(enemy.x, enemy.y), activeAge < 180 ? 0.018f : 0.01f);
        if (activeAge < 180) {
            enemy.vx = std::sin(activeAge * 0.026f) * 1.2f;
            enemy.vy = 0.12f;
        }
        else if (activeAge < 900) {
            enemy.vx = std::sin(activeAge * 0.018f) * 1.45f;
            enemy.vy = std::sin(activeAge * 0.018f) * 0.45f;
        }
        else {
            enemy.vx = std::sin(activeAge * 0.012f) * 0.85f;
            enemy.vy = 0.20f + std::sin(activeAge * 0.02f) * 0.28f;
        }
        break;
    default:
        break;
    }
}

void StageRuntime::emitStage04Projectiles(StageEnemy& enemy, int activeAge) {
    // These patterns are playable approximations of the reviewed Stage04 helpers;
    // true child entities (0x3b/0x3c/0x3e) and effect-node overlays are deferred.
    if (enemy.spawnType == 0x35 && activeAge > 40 && activeAge % 42 == 0) {
        spawnProjectileSpread(6, 0x06, enemy.x, enemy.y + 48.0f, aimAtPlayer(enemy.x, enemy.y), 2.8f, 6, 3, kPi / 7.0f);
    }
    if (enemy.spawnType == 0x36 && activeAge > 50 && activeAge % 72 == 0) {
        spawnProjectileSpread(4, 0x00, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.9f, 6, 3, kPi / 5.0f);
    }
    if (enemy.spawnType == 0x37 && activeAge > 70 && activeAge % 64 == 0) {
        spawnProjectileNode(0, 0x00, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.2f, 5);
        if ((activeAge / 64) % 2 == 1) {
            spawnProjectileNode(0, 0x01, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y) + 0.08f, 3.0f, 5);
        }
    }
    if (enemy.spawnType == 0x38 && activeAge > 100 && activeAge % 96 == 0) {
        spawnProjectileSpread(9, 0x08, enemy.x, enemy.y, enemy.angle, 2.3f, 8, 10, kTau);
    }
    if (enemy.spawnType == 0x38 && activeAge > 140 && (activeAge + 48) % 144 == 0) {
        spawnProjectileSpread(8, 0x09, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.1f, 8, 6, kPi * 0.85f);
    }
    if ((enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) && activeAge > 80 && activeAge % 120 == 0) {
        spawnProjectileSpread(3, 0x03, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.5f, 7, 7, kPi * 0.85f);
    }
    if ((enemy.spawnType == 0x39 || enemy.spawnType == 0x3a) && activeAge > 60 && activeAge % 90 == 0) {
        const int selector = enemy.spawnType == 0x39 ? 0x08 : 0x09;
        spawnProjectileSpread(8, selector, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.0f, 7, 3, kPi / 6.0f);
    }
    if (enemy.spawnType == 0x3d && activeAge > 70 && activeAge % 130 == 0) {
        for (float offset : {-80.0f, 0.0f, 80.0f}) {
            spawnProjectileSpread(5, 0x0b, enemy.x + offset, enemy.y, aimAtPlayer(enemy.x + offset, enemy.y), 2.4f, 8, 5, kPi / 3.0f);
        }
    }
    if (enemy.spawnType == 0x3f && activeAge > 90 && activeAge % 75 == 0) {
        spawnProjectileSpread(7, 0x07, enemy.x, enemy.y, enemy.angle, 2.6f, 7, 14, kTau);
    }
    if (enemy.spawnType == 0x3f && activeAge > 220 && activeAge % 100 == 0) {
        spawnProjectileSpread(4, 0x04, enemy.x, enemy.y + 24.0f, aimAtPlayer(enemy.x, enemy.y), 2.7f, 7, 5, kPi / 2.8f);
    }
    if (enemy.spawnType == 0x3f && activeAge > 520 && activeAge % 150 == 0) {
        spawnProjectileSpread(2, 0x02, enemy.x, enemy.y + 32.0f, aimAtPlayer(enemy.x, enemy.y), 2.0f, 9, 8, kPi);
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
             enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f || enemy.spawnType == 0x20) {
        enemy.vx = std::sin((enemy.age + enemy.spawnType * 17) * 0.025f) * 1.1f;
    }
    else {
        (void)activeAge;
    }
}

void StageRuntime::emitGenericProjectiles(StageEnemy& enemy, int activeAge) {
    if (activeAge > 30 && activeAge % 70 == 0) {
        const int selector = (enemy.spawnType >= 0x19 && enemy.spawnType <= 0x20) ? 1 : 0;
        spawnProjectileNode(0, selector, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 3.0f, 6);
    }
    if ((enemy.spawnType == 0x0c || enemy.spawnType == 0x0d || enemy.spawnType == 0x19 || enemy.spawnType == 0x1a) &&
        activeAge > 80 && activeAge % 120 == 0) {
        const int count = (enemy.spawnType == 0x0c || enemy.spawnType == 0x19) ? 3 : 5;
        spawnProjectileSpread(count, 0, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.6f, 6, count, kPi / 5.0f);
    }
    if ((enemy.spawnType == 0x0e || enemy.spawnType == 0x0f || enemy.spawnType == 0x10 ||
         enemy.spawnType == 0x1b || enemy.spawnType == 0x1c || enemy.spawnType == 0x1f || enemy.spawnType == 0x20) &&
        activeAge > 120 && activeAge % 180 == 0) {
        const int selector = enemy.spawnType >= 0x19 ? 3 : 2;
        spawnProjectileSpread(2, selector, enemy.x, enemy.y, aimAtPlayer(enemy.x, enemy.y), 2.2f, 8, 12, kTau);
    }
}

void StageRuntime::updateProjectiles() {
    const std::size_t initialCount = enemyProjectiles_.size();
    for (std::size_t i = 0; i < initialCount && i < enemyProjectiles_.size(); ++i) {
        auto& projectile = enemyProjectiles_[i];
        if (!projectile.active) {
            continue;
        }
        ++projectile.age;
        switch (projectile.projectileId) {
        case 0x08:
            updateProjectileReflectOnBoundary(projectile);
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
            break;
        case 0x1f:
        case 0x20:
            updateProjectileOrbitArcPair(projectile);
            break;
        case 0x3a:
        case 0x3b:
            updateProjectileExpandingSpiralPair(projectile);
            break;
        default:
            updateProjectileCommonMotion(projectile);
            break;
        }
    }
}

void StageRuntime::updateProjectileCommonMotion(StageProjectile& projectile) {
    switch (projectile.projectileId) {
    case 0x01:
        projectile.speed += 0.010f;
        break;
    case 0x02:
        if (projectile.age > 18) {
            projectile.speed = std::min(projectile.baseSpeed * 1.35f, projectile.speed + projectile.baseSpeed / 90.0f);
        }
        break;
    case 0x03:
        if (projectile.age == 1) projectile.speed = 0.10f;
        if (projectile.age > 30) projectile.speed = std::min(projectile.baseSpeed, projectile.speed + projectile.baseSpeed / 70.0f);
        break;
    case 0x04:
        if (projectile.age == 1) projectile.speed = std::max(0.10f, projectile.baseSpeed * 0.20f);
        if (projectile.age > 12) projectile.speed = std::min(projectile.baseSpeed, projectile.speed + projectile.baseSpeed / 45.0f);
        break;
    case 0x05:
        if (projectile.age < 60) projectile.speed = std::max(projectile.baseSpeed * 0.45f, projectile.speed * 0.985f);
        else projectile.speed = std::min(projectile.baseSpeed * 1.25f, projectile.speed + projectile.baseSpeed / 80.0f);
        break;
    case 0x06:
        if (projectile.age < 30) projectile.speed = std::max(projectile.baseSpeed * 0.45f, projectile.speed - projectile.baseSpeed / 60.0f);
        break;
    case 0x07:
        if (projectile.age < 40) projectile.speed = std::max(projectile.baseSpeed * 0.35f, projectile.speed - projectile.baseSpeed / 75.0f);
        else if (projectile.age < 100) projectile.speed = std::min(projectile.baseSpeed * 1.30f, projectile.speed + projectile.baseSpeed / 80.0f);
        break;
    case 0x09:
        if (projectile.age == 30 || projectile.age == 45) {
            projectile.angle16 = radiansToFixedAngle(aimAtPlayer(projectile.x, projectile.y));
            projectile.prevAngle16 = projectile.angle16;
            projectile.speedOrAccelHint = 0.0f;
            projectile.speed = std::max(projectile.speed, projectile.baseSpeed * 0.8f);
        }
        break;
    case 0x0a:
        if (projectile.age == 40) {
            projectile.angle16 = radiansToFixedAngle(aimAtPlayer(projectile.prevX, projectile.prevY));
            projectile.prevAngle16 = projectile.angle16;
        }
        break;
    case 0x0b:
        if (projectile.age == 50) {
            projectile.angle16 = radiansToFixedAngle(std::atan2(player_.y + 24.0f - projectile.y, player_.x - projectile.x));
            projectile.prevAngle16 = projectile.angle16;
            projectile.speed = std::max(projectile.baseSpeed * 0.85f, projectile.speed);
        }
        break;
    case 0x0d:
        if (projectile.age > 24) {
            projectile.speed = std::min(projectile.baseSpeed * 1.4f, projectile.speed + projectile.baseSpeed / 90.0f);
            if (projectile.age % 10 == 0) {
                spawnProjectileNode(4, 0x0f, projectile.x, projectile.y, projectile.angle16, 0.0f, 0.45f, 3, 0);
            }
        }
        break;
    case 0x0f:
        if (projectile.age > 20) projectile.active = false;
        break;
    case 0x10:
        if (projectile.age > 40) projectile.active = false;
        break;
    case 0x11:
        if (projectile.age > 10) projectile.active = false;
        break;
    case 0x12:
        if (projectile.age > 60) projectile.active = false;
        break;
    default:
        break;
    }
    if (!projectile.active) {
        return;
    }
    updateProjectileVelocity(projectile);
    projectile.prevX = projectile.x;
    projectile.prevY = projectile.y;
    projectile.x += projectile.vx;
    projectile.y += projectile.vy;
}

void StageRuntime::updateProjectileReflectOnBoundary(StageProjectile& projectile) {
    updateProjectileVelocity(projectile);
    projectile.prevX = projectile.x;
    projectile.prevY = projectile.y;
    projectile.x += projectile.vx;
    projectile.y += projectile.vy;

    int reflectedAngle = projectile.angle16;
    bool reflected = false;
    if ((projectile.x < kPlayLeft && projectile.vx < 0.0f) || (projectile.x > kPlayRight && projectile.vx > 0.0f)) {
        reflectedAngle = -0x8000 - static_cast<int>(projectile.angle16);
        projectile.x = clampFloat(projectile.x, kPlayLeft, kPlayRight);
        reflected = true;
    }
    if ((projectile.y < kPlayTop && projectile.vy < 0.0f) || (projectile.y > kPlayBottom && projectile.vy > 0.0f)) {
        reflectedAngle = -static_cast<int>(projectile.angle16);
        projectile.y = clampFloat(projectile.y, kPlayTop, kPlayBottom);
        reflected = true;
    }
    if (reflected) {
        const auto angle = normalizeAngle16(reflectedAngle);
        spawnProjectileNode(projectile.projectileId, projectile.visualSelector, projectile.x, projectile.y, angle,
                            projectile.speedOrAccelHint, projectile.speed, projectile.radius, projectile.arg8OrAux);
        projectile.active = false;
    }
}

void StageRuntime::updateProjectileHomingSteering(StageProjectile& projectile) {
    const std::uint16_t target = radiansToFixedAngle(aimAtPlayer(projectile.x, projectile.y));
    int turnStep = projectile.projectileId == 0x0c ? 0x180 : 0x100;
    if (projectile.projectileId >= 0x23) turnStep = 0xc0;
    projectile.angle16 = approachAngle16(projectile.angle16, target, turnStep);

    if (projectile.projectileId == 0x0c) {
        if (projectile.age < 60) projectile.speed = std::max(projectile.baseSpeed * 0.35f, projectile.speed - 0.035f);
        else projectile.speed = std::min(projectile.baseSpeed * 1.4f, projectile.speed + 0.035f);
        if (projectile.age > 60 && projectile.age % 12 == 0) {
            spawnProjectileNode(4, 0x0f, projectile.x, projectile.y, projectile.angle16, 0.0f, 0.55f, 3, 0);
        }
    }
    else if (projectile.projectileId == 0x0e) {
        projectile.speed = projectile.baseSpeed * (0.85f + std::sin(projectile.age * 0.06f) * 0.25f);
        if (projectile.age % 14 == 0) {
            spawnProjectileNode(5, 0x0f, projectile.x, projectile.y, projectile.angle16, 0.0f, 0.45f, 3, 0);
        }
    }
    else {
        projectile.speed = std::min(projectile.baseSpeed * 1.25f, projectile.speed + 0.006f);
    }

    updateProjectileVelocity(projectile);
    projectile.prevX = projectile.x;
    projectile.prevY = projectile.y;
    projectile.x += projectile.vx;
    projectile.y += projectile.vy;
}

void StageRuntime::updateProjectileScriptedEmitter(StageProjectile& projectile) {
    updateProjectileVelocity(projectile);
    projectile.prevX = projectile.x;
    projectile.prevY = projectile.y;
    projectile.x += projectile.vx;
    projectile.y += projectile.vy;

    switch (projectile.projectileId) {
    case 0x17:
        if (projectile.age == 25) {
            spawnProjectileNode(3, 1, projectile.x, projectile.y, radiansToFixedAngle(aimAtPlayer(projectile.x, projectile.y)), 0.0f, projectile.baseSpeed, 5, 0);
            projectile.active = false;
        }
        break;
    case 0x18:
    case 0x19:
        if (projectile.age % 24 == 0 && projectile.age < 96) {
            const int childId = projectile.projectileId == 0x18 ? 0x0c : 0x0d;
            spawnProjectileSpread(childId, projectile.visualSelector, projectile.x, projectile.y, projectile.angle16, 0.0f, projectile.baseSpeed, 5, 3, 0x3000, 0);
        }
        if (projectile.age > 120) projectile.active = false;
        break;
    case 0x1a:
    case 0x1b:
        if (projectile.age % 36 == 0) {
            const int childId = projectile.projectileId == 0x1a ? 8 : 9;
            spawnProjectileSpread(childId, projectile.visualSelector, projectile.x, projectile.y, projectile.angle16, 0.0f, projectile.baseSpeed, 5, 2, 0x4000, 0);
        }
        break;
    case 0x21:
    case 0x22:
        if (projectile.age == 36) {
            const int offset = projectile.projectileId == 0x21 ? 0x1800 : -0x1800;
            spawnProjectileNode(2, 4, projectile.x, projectile.y, normalizeAngle16(projectile.angle16 + offset), 0.0f, projectile.baseSpeed, 5, 0);
            projectile.active = false;
        }
        break;
    case 0x39:
        if (projectile.age == 30) {
            spawnProjectileSpread(2, 2, projectile.x, projectile.y, projectile.angle16, 0.0f, projectile.baseSpeed, 5, 2, 0x4000, 0);
            projectile.active = false;
        }
        break;
    case 0x3c:
        if (projectile.age % 3 == 0) {
            spawnProjectileNode(4, 0x11, projectile.x + deterministicUnit(projectile.age, projectile.arg8OrAux) * 12.0f - 6.0f,
                                projectile.y + deterministicUnit(projectile.age, projectile.arg8OrAux + 7) * 12.0f - 6.0f,
                                projectile.angle16, 0.0f, 0.35f, 2, 0);
        }
        projectile.speed = std::min(projectile.baseSpeed * 1.2f, projectile.speed + 0.006f);
        break;
    default:
        break;
    }
}

void StageRuntime::updateProjectileOrbitArcPair(StageProjectile& projectile) {
    const float radius = projectile.speedOrAccelHint + std::min(projectile.age, 40) * 2.0f;
    const float angle = fixedAngleToRadians(projectile.angle16);
    projectile.x = projectile.prevX + std::cos(angle) * radius;
    projectile.y = projectile.prevY + std::sin(angle) * radius * 0.6f;
    if (projectile.age == 40) {
        projectile.prevAngle16 = radiansToFixedAngle(aimAtPlayer(projectile.prevX, projectile.prevY));
    }
    if (projectile.age > 40) {
        projectile.prevX += std::cos(fixedAngleToRadians(projectile.prevAngle16)) * (projectile.speed + projectile.age * 0.004f);
        projectile.prevY += std::sin(fixedAngleToRadians(projectile.prevAngle16)) * (projectile.speed + projectile.age * 0.004f);
    }
    const int direction = projectile.projectileId == 0x1f ? 0x70 : -0x70;
    projectile.angle16 = normalizeAngle16(projectile.angle16 + direction);
}

void StageRuntime::updateProjectileExpandingSpiralPair(StageProjectile& projectile) {
    if (projectile.age == 1) {
        projectile.prevX = projectile.speedOrAccelHint;
    }
    const float radius = projectile.prevX * std::min(1.0f, projectile.age / 10.0f);
    const float centerSpeed = projectile.speed + projectile.age * 0.006f - projectile.baseSpeed * 0.25f;
    projectile.x += std::cos(fixedAngleToRadians(projectile.angle16)) * centerSpeed;
    projectile.y += std::sin(fixedAngleToRadians(projectile.angle16)) * centerSpeed;
    const int direction = projectile.projectileId == 0x3a ? 0x1bc : -0x1bc;
    projectile.angle16 = normalizeAngle16(projectile.angle16 + direction);
    projectile.prevY = projectile.y + std::sin(fixedAngleToRadians(projectile.angle16)) * radius;
    projectile.prevX = projectile.x + std::cos(fixedAngleToRadians(projectile.angle16)) * radius;
}

void StageRuntime::updateRewardItems() {
    for (auto& item : rewardItems_) {
        if (!item.active) {
            continue;
        }
        ++item.age;
        if (!item.homing && (item.age > 30 || player_.y < 180.0f)) {
            item.homing = true;
        }
        if (item.homing) {
            item.angle16 = approachAngle16(item.angle16, radiansToFixedAngle(std::atan2(player_.y - item.y, player_.x - item.x)), 0x900);
            item.speed = std::min(9.0f, item.speed + 0.22f);
        }
        else {
            item.speed = std::max(0.6f, item.speed - 0.015f);
        }
        const float angle = fixedAngleToRadians(item.angle16);
        item.x += std::cos(angle) * item.speed;
        item.y += std::sin(angle) * item.speed;
        const int collectRadius = item.radiusOrScale + (player_.focused ? 5 : 8);
        if (distanceSquared(item.x, item.y, player_.x, player_.y) <= static_cast<float>(collectRadius * collectRadius)) {
            item.active = false;
            if (item.itemType == 6) {
                // FUN_1400ca7b0 type 6 adds one stock threshold chunk via
                // DAT_140e45d88 when stock level is below the cap, then leaves
                // the exact effect-node 0x16 visual to the deferred effect list.
                const int threshold = 30000;
                if (player_.lives < 3) {
                    player_.stockProgress = std::min(threshold * 3, player_.stockProgress + threshold);
                    ++player_.lives;
                }
                else {
                    player_.stockProgress = std::min(threshold * 3, player_.stockProgress + threshold / 3);
                }
                player_.specialGauge = std::min(50000, player_.specialGauge + 3000);
                player_.score += player_.scoreItemBaseValue * 10;
            }
            else {
                player_.score += player_.scoreItemBaseValue;
                player_.specialGauge = std::min(50000, player_.specialGauge + 300);
            }
        }
    }
}

void StageRuntime::updatePlayerSideObjects() {
    for (auto& object : playerSideObjects_) {
        if (!object.active) {
            continue;
        }
        ++object.age;
        if (object.type >= 0 && object.type <= 0x0a) {
            const float angle = fixedAngleToRadians(object.angle16);
            object.x += std::cos(angle) * object.speedOrScale;
            object.y += std::sin(angle) * object.speedOrScale;
        }
        if (object.age > object.alphaOrLifetime && object.alphaOrLifetime > 0) {
            object.active = false;
        }
    }
}

void StageRuntime::emitPlayerNormalShot() {
    const std::uint16_t up = radiansToFixedAngle(-kPi * 0.5f);
    const int mainType = player_.shotVariant != 0 || player_.specialGauge >= 50000 ? 1 : 0;
    spawnPlayerSideObject(mainType, player_.x - 10.0f, player_.y - 22.0f, 13.5f, up, 0x82, 8);
    spawnPlayerSideObject(mainType, player_.x + 10.0f, player_.y - 22.0f, 13.5f, up, 0x82, 8);

    constexpr std::array<std::array<float, 2>, 4> kSpreadAnchors{{
        std::array<float, 2>{-44.0f, -12.0f}, std::array<float, 2>{44.0f, -12.0f},
        std::array<float, 2>{-24.0f, -40.0f}, std::array<float, 2>{24.0f, -40.0f},
    }};
    constexpr std::array<std::array<float, 2>, 4> kFocusedAnchors{{
        std::array<float, 2>{-26.0f, -18.0f}, std::array<float, 2>{26.0f, -18.0f},
        std::array<float, 2>{-14.0f, -44.0f}, std::array<float, 2>{14.0f, -44.0f},
    }};
    const auto& anchors = player_.focused ? kFocusedAnchors : kSpreadAnchors;
    for (int i = 0; i < static_cast<int>(anchors.size()); ++i) {
        const int type = optionShotTypeForSlot(i);
        const float angleOffset = (i == 0 ? -0.10f : (i == 1 ? 0.10f : (i == 2 ? -0.04f : 0.04f)));
        const float subOptionSpeed = config_.subOption == 0 ? 0.0f : 0.8f;
        spawnPlayerSideObject(type, player_.x + anchors[static_cast<std::size_t>(i)][0],
                              player_.y + anchors[static_cast<std::size_t>(i)][1],
                              10.5f + subOptionSpeed, radiansToFixedAngle(-kPi * 0.5f + angleOffset), 0x46, 6);
    }
}

void StageRuntime::spawnPlayerSideObject(int type, float x, float y, float speedOrScale, std::uint16_t angle16, int radiusOrLifetime, int auxRadiusOrScale) {
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
    object.speedOrScale = speedOrScale;
    object.alphaOrLifetime = 180;
    object.radiusOrScale = radiusOrLifetime;
    object.auxRadiusOrScale = auxRadiusOrScale;
    playerSideObjects_.push_back(object);
}

int StageRuntime::baseOptionShotTypeForConfig() const {
    const int route = std::max(0, std::min(config_.routeMode, 2));
    const int loadoutBand = std::max(0, std::min(config_.loadoutId / 3, 2));
    return std::min(10, 2 + route * 2 + loadoutBand * 2);
}

int StageRuntime::optionShotTypeForSlot(int slot) const {
    const int base = baseOptionShotTypeForConfig();
    const int optionShift = config_.playerOption != 0 && slot >= 2 ? 1 : 0;
    return std::max(2, std::min(10, base + (slot % 2) + optionShift));
}

bool StageRuntime::enemyUsesMediumFrame(const StageEnemy& enemy) const {
    return stageUsesMediumFrame(enemy.spawnType);
}

int StageRuntime::enemyVisualFrameForSpawnType(const StageEnemy& enemy) const {
    if (selectedStage_ == 1) {
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
    return object.active && object.type >= 0 && object.type <= 0x0a;
}

int StageRuntime::playerSideObjectDamage(const PlayerSideObject& object) const {
    return object.type <= 1 ? 2 : 1;
}
void StageRuntime::updatePlayerShots() {
    for (auto& shot : playerShots_) {
        shot.y += shot.vy;
    }
}

void StageRuntime::handleCollisions() {
    for (auto& object : playerSideObjects_) {
        if (!playerSideObjectCanHitEnemy(object)) {
            continue;
        }
        for (auto& enemy : enemies_) {
            if (!enemy.active) {
                continue;
            }
            const int radius = object.auxRadiusOrScale + enemy.radius;
            if (distanceSquared(object.x, object.y, enemy.x, enemy.y) <= static_cast<float>(radius * radius)) {
                object.active = false;
                enemy.hp -= playerSideObjectDamage(object);
                player_.specialGauge = std::min(50000, player_.specialGauge + 90);
                player_.scoreItemBaseValue = std::min(999999, player_.scoreItemBaseValue + 1);
                ++player_.graze;
                if (enemy.hp <= 0) {
                    enemy.active = false;
                    if (enemy.spawnType == 0x10) {
                        spawnRewardItem(6, enemy.x, enemy.y, radiansToFixedAngle(-kPi * 0.5f), 2.2f, 18);
                    }
                    player_.score += 1000 + enemy.spawnType * 10;
                    player_.tokenStock = std::min(notes::hud_layout::kMaxTokens, player_.tokenStock + 1);
                    ++player_.keyStateCount;
                    player_.specialGauge = std::min(50000, player_.specialGauge + 1200);
                }
                break;
            }
        }
    }

    for (auto& shot : playerShots_) {
        if (!shot.active) {
            continue;
        }
        for (auto& enemy : enemies_) {
            if (!enemy.active) {
                continue;
            }
            const int radius = shot.radius + enemy.radius;
            if (distanceSquared(shot.x, shot.y, enemy.x, enemy.y) <= static_cast<float>(radius * radius)) {
                shot.active = false;
                enemy.hp -= 2;
                player_.specialGauge = std::min(50000, player_.specialGauge + 180);
                player_.scoreItemBaseValue = std::min(999999, player_.scoreItemBaseValue + 1);
                ++player_.graze;
                if (enemy.hp <= 0) {
                    enemy.active = false;
                    if (enemy.spawnType == 0x10) {
                        spawnRewardItem(6, enemy.x, enemy.y, radiansToFixedAngle(-kPi * 0.5f), 2.2f, 18);
                    }
                    player_.score += 1000 + enemy.spawnType * 10;
                    player_.tokenStock = std::min(notes::hud_layout::kMaxTokens, player_.tokenStock + 1);
                    ++player_.keyStateCount;
                    player_.specialGauge = std::min(50000, player_.specialGauge + 1200);
                }
                break;
            }
        }
    }

    if (player_.invulnerableFrames == 0) {
        for (auto& projectile : enemyProjectiles_) {
            const int radius = projectile.radius + (player_.focused ? 3 : 6);
            if (distanceSquared(projectile.x, projectile.y, player_.x, player_.y) <= static_cast<float>(radius * radius)) {
                projectile.active = false;
                --player_.lives;
                player_.invulnerableFrames = 180;
                player_.x = static_cast<float>(notes::gameplay_layout::kPlayerStart.x);
                player_.y = static_cast<float>(notes::gameplay_layout::kPlayerStart.y);
                if (player_.lives < 0) {
                    player_.lives = 3;
                    reset();
                }
                break;
            }
        }
    }
}

void StageRuntime::spawnProjectileNode(int projectileId, int visualSelector, float x, float y, float angle, float speed, int radius) {
    spawnProjectileNode(projectileId, visualSelector, x, y, radiansToFixedAngle(angle), 0.0f, speed, radius, 0);
}

void StageRuntime::spawnProjectileNode(int projectileId, int visualSelector, float x, float y, std::uint16_t angle16, float speedOrAccelHint, float speed, int radius, int arg8OrAux) {
    if (enemyProjectiles_.size() >= kProjectileCap) {
        return;
    }
    StageProjectile projectile;
    projectile.projectileId = projectileId;
    projectile.visualSelector = visualSelector;
    projectile.x = x;
    projectile.y = y;
    projectile.prevX = x;
    projectile.prevY = y;
    projectile.speedOrAccelHint = speedOrAccelHint;
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
    const float movementSpeed = projectile.speed + projectile.speedOrAccelHint;
    projectile.vx = std::cos(projectile.angle) * movementSpeed;
    projectile.vy = std::sin(projectile.angle) * movementSpeed;
}

void StageRuntime::spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, float centerAngle, float speed, int radius, int count, float spreadRadians) {
    const int spreadAngle16 = spreadRadians >= kTau - 0.001f
                                  ? kFixedAngleFullCircle
                                  : static_cast<int>(std::lround(spreadRadians * static_cast<float>(kFixedAngleFullCircle) / kTau));
    spawnProjectileSpread(projectileId, visualSelector, x, y, radiansToFixedAngle(centerAngle), 0.0f, speed, radius, count, spreadAngle16, 0);
}

void StageRuntime::spawnProjectileSpread(int projectileId, int visualSelector, float x, float y, std::uint16_t centerAngle16, float speedOrAccelHint, float speed, int radius, int count, int spreadAngle16, int arg8OrAux) {
    if (count <= 1) {
        spawnProjectileNode(projectileId, visualSelector, x, y, centerAngle16, speedOrAccelHint, speed, radius, arg8OrAux);
        return;
    }
    if (spreadAngle16 == kFixedAngleFullCircle) {
        const int step = kFixedAngleFullCircle / count;
        for (int i = 0; i < count; ++i) {
            spawnProjectileNode(projectileId, visualSelector, x, y, normalizeAngle16(centerAngle16 + i * step), speedOrAccelHint, speed, radius, arg8OrAux);
        }
        return;
    }
    const int start = static_cast<int>(centerAngle16) - spreadAngle16 / 2;
    const int step = spreadAngle16 / (count - 1);
    for (int i = 0; i < count; ++i) {
        spawnProjectileNode(projectileId, visualSelector, x, y, normalizeAngle16(start + i * step), speedOrAccelHint, speed, radius, arg8OrAux);
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
    const int scroll = frame_ % 720;
    if (!stageBack2Frames_.empty() && stageBack2Frames_.front() != -1) {
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, scroll - 720, stageBack2Frames_.front(), TRUE);
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, scroll, stageBack2Frames_.front(), TRUE);
    }
    if (!stageBack1Frames_.empty() && stageBack1Frames_.front() != -1) {
        const int slowScroll = (frame_ / 2) % 720;
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, slowScroll - 720, stageBack1Frames_.front(), TRUE);
        DrawGraph(notes::gameplay_layout::kStageBackOrigin.x, slowScroll, stageBack1Frames_.front(), TRUE);
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
    for (const auto& object : playerSideObjects_) {
        const int frameIndex = playerSideObjectVisualFrame(object);
        const int handle = playerFrames_.empty() || frameIndex >= static_cast<int>(playerFrames_.size()) ? -1 : playerFrames_[static_cast<std::size_t>(frameIndex)];
        const float x = screenX(object.x);
        const float y = screenY(object.y);
        if (handle != -1) {
            DrawRotaGraphF(x, y, 0.55, fixedAngleToRadians(object.angle16) + kPi * 0.5f, handle, TRUE);
        }
        else {
            const int color = object.type <= 1 ? GetColor(120, 220, 255) : GetColor(180, 255, 180);
            DrawCircle(static_cast<int>(x), static_cast<int>(y), std::max(3, object.auxRadiusOrScale), color, TRUE);
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
        const auto& frames = enemy.spawnType == 0x138 ? bossFrames_ : (enemyUsesMediumFrame(enemy) ? enemyMediumFrames_ : enemySmallFrames_);
        const int visualFrame = enemyVisualFrameForSpawnType(enemy);
        const int index = frames.empty() ? -1 : std::min(visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        const float x = screenX(enemy.x);
        const float y = screenY(enemy.y);
        if (handle != -1) {
            const double scale = enemyUsesMediumFrame(enemy) ? 0.42 : 0.55;
            if (selectedStage_ == 1 && enemy.spawnType == 0x0b && !enemyUsesMediumFrame(enemy)) {
                const int overlayIndex = enemySmallFrames_.empty() ? -1 : std::min(5, static_cast<int>(enemySmallFrames_.size()) - 1);
                const int overlayHandle = overlayIndex < 0 ? -1 : enemySmallFrames_[static_cast<std::size_t>(overlayIndex)];
                if (overlayHandle != -1) {
                    for (int i = 0; i < 4; ++i) {
                        const float angle = enemy.age * 0.11f + i * kTau * 0.25f;
                        DrawRotaGraphF(x + std::cos(angle) * 14.0f, y - 12.0f + std::sin(angle) * 8.0f,
                                       scale * 0.36, angle, overlayHandle, TRUE);
                    }
                }
            }
            if (selectedStage_ == 1 && enemy.spawnType == 0x0c && !enemyUsesMediumFrame(enemy)) {
                const int wingIndex = enemySmallFrames_.empty() ? -1 : std::min(8, static_cast<int>(enemySmallFrames_.size()) - 1);
                const int midIndex = enemySmallFrames_.empty() ? -1 : std::min(7, static_cast<int>(enemySmallFrames_.size()) - 1);
                const int wingHandle = wingIndex < 0 ? -1 : enemySmallFrames_[static_cast<std::size_t>(wingIndex)];
                const int midHandle = midIndex < 0 ? -1 : enemySmallFrames_[static_cast<std::size_t>(midIndex)];
                if (wingHandle != -1) {
                    DrawRotaGraphF(x - 18.0f, y - 6.0f, scale * 0.42, enemy.angle - 0.45f, wingHandle, TRUE);
                    DrawRotaGraphF(x + 18.0f, y - 6.0f, scale * 0.42, enemy.angle + 0.45f, wingHandle, TRUE);
                }
                if (midHandle != -1) {
                    DrawRotaGraphF(x, y + 12.0f, scale * 0.45, enemy.angle, midHandle, TRUE);
                }
            }
            if (selectedStage_ == 1 && enemy.spawnType == 0x0d && !enemyUsesMediumFrame(enemy)) {
                const int wingIndex = enemySmallFrames_.empty() ? -1 : std::min(10, static_cast<int>(enemySmallFrames_.size()) - 1);
                const int wingHandle = wingIndex < 0 ? -1 : enemySmallFrames_[static_cast<std::size_t>(wingIndex)];
                if (wingHandle != -1) {
                    const float side = enemy.sourceAngle16 < 0xc000 ? -1.0f : 1.0f;
                    DrawRotaGraphF(x + side * 16.0f, y - 8.0f, scale * 0.42, enemy.angle + side * 0.65f, wingHandle, TRUE);
                    DrawRotaGraphF(x - side * 16.0f, y + 8.0f, scale * 0.42, enemy.angle - side * 0.35f, wingHandle, TRUE);
                }
            }
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
            if (enemy.spawnType == 0x3f) {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
                DrawRotaGraphF(x - 48.0f, y + 18.0f, scale * 0.55, enemy.angle, handle, TRUE);
                DrawRotaGraphF(x + 48.0f, y + 18.0f, scale * 0.55, enemy.angle, handle, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
        else {
            DrawCircle(static_cast<int>(x), static_cast<int>(y), enemy.radius, GetColor(255, 96, 160), TRUE);
        }
    }
}

void StageRuntime::drawProjectiles() const {
    for (const auto& projectile : enemyProjectiles_) {
        const int frameIndex = bulletFrameForVisualSelector(projectile.visualSelector);
        const int handle = bulletFrames_.empty() || frameIndex >= static_cast<int>(bulletFrames_.size()) ? -1 : bulletFrames_[static_cast<std::size_t>(frameIndex)];
        const float angle = projectileDrawRotationForVisualSelector(projectile.visualSelector, projectile.age, projectile.angle16);
        const float x = screenX(projectile.x);
        const float y = screenY(projectile.y);
        if (handle != -1) {
            // Selectors 0x11..0x14 also add overlays/effects in FUN_140070250; this runtime maps them to base bead frames until effect nodes are reconstructed.
            DrawRotaGraphF(x, y, projectileScaleForVisualSelector(projectile.visualSelector), angle, handle, TRUE);
        }
        else {
            DrawCircle(static_cast<int>(x), static_cast<int>(y), projectile.radius, GetColor(255, 80, 180), TRUE);
        }
    }
}

void StageRuntime::drawRewardItems() const {
    for (const auto& item : rewardItems_) {
        const float x = screenX(item.x);
        const float y = screenY(item.y);
        const int radius = item.itemType == 6 ? 9 : 5;
        const int color = item.itemType == 6 ? GetColor(255, 220, 120) : GetColor(160, 220, 255);
        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, color, TRUE);
        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius + 3, GetColor(255, 255, 255), FALSE);
    }
}

void StageRuntime::drawPlayerShots() const {
    for (const auto& shot : playerShots_) {
        const float x = screenX(shot.x);
        const float y = screenY(shot.y);
        DrawBox(static_cast<int>(x - 2), static_cast<int>(y - 12),
                static_cast<int>(x + 2), static_cast<int>(y + 8), GetColor(120, 220, 255), TRUE);
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
    drawLeftHudPanel();
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
        const int frameIndex = std::min(config_.routeMode * 10, static_cast<int>(playerFrameFrames_.size()) - 1);
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
    const float ratio = maxValue <= 0 ? 0.0f : clampFloat(static_cast<float>(value) / static_cast<float>(maxValue), 0.0f, 1.0f);
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
    DrawBox(x + 2, y + 18, x + 2 + static_cast<int>((width - 4) * ratio), y + 16 + height - 2, GetColor(100, 220, 255), TRUE);
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
                     "reconstruction probe  stage=%02d frame=%d enemies=%d bullets=%d side=%d shots=%d lives=%d",
                     selectedStage_, frame_, static_cast<int>(enemies_.size()),
                     static_cast<int>(enemyProjectiles_.size()), static_cast<int>(playerSideObjects_.size()),
                     static_cast<int>(playerShots_.size()), player_.lives);
    DrawFormatString(24, notes::kScreenHeight - 26, GetColor(150, 180, 210),
                     "loadout route=%d playerOpt=%d sub=%d loadout=%d diff=%d counter=%d shotTimer=%d focus=%d slots=[%d %d %d %d]",
                     config_.routeMode, config_.playerOption, config_.subOption, config_.loadoutId, config_.difficulty, config_.counterMode,
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
