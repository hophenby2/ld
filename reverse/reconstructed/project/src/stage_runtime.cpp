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
    return (spawnType >= 0x0e && spawnType <= 0x10) ||
           (spawnType >= 0x1b && spawnType <= 0x20) ||
           spawnType == 0x38 || spawnType == 0x3d || spawnType == 0x3f;
}

bool isStage04FocusedType(int spawnType) {
    return spawnType == 0x35 || spawnType == 0x36 || spawnType == 0x37 ||
           spawnType == 0x38 || spawnType == 0x39 || spawnType == 0x3a ||
           spawnType == 0x3d || spawnType == 0x3f;
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
    bulletFrames_ = resources.loadDivGraph("media\\stage\\Bullet.png", 0x28, 10, 4, 0x3c, 0x3c);
    stageBack1Frames_ = resources.loadDivGraph("media\\stage\\StageBack1.png", 10, 10, 1, 0x2d0, 0xa00);
    stageBack2Frames_ = resources.loadDivGraph("media\\stage\\StageBack2.png", 10, 10, 1, 0x2d0, 0x2d0);

    stageFrameFrames_ = resources.loadDivGraph("media\\system\\StageFrame.png", 2, 2, 1, 600, 720);
    numSmallFrames_ = resources.loadDivGraph("media\\system\\Num_s.png", 0x0e, 0x0e, 1, 0x14, 0x1e);
    numMediumFrames_ = resources.loadDivGraph("media\\system\\Num_m.png", 10, 10, 1, 0x20, 0x30);
    numLargeFrames_ = resources.loadDivGraph("media\\system\\Num_l.png", 0x0e, 0x0e, 1, 0x30, 0x48);
    dataWindowHandle_ = resources.loadGraph("media\\player\\DataWindow.png");
    timeWindowHandle_ = resources.loadGraph("media\\player\\TimeWindow.png");
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
                         config_.loadoutId != next.loadoutId || config_.optionSlots != next.optionSlots;
    config_ = next;
    if (changed) {
        selectedStage_ = normalized;
        reset();
    }
}

void StageRuntime::reset() {
    frame_ = 0;
    player_ = {};
    enemies_.clear();
    enemyProjectiles_.clear();
    playerSideObjects_.clear();
    playerShots_.clear();
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
    enemy.spawnType = event.spawnType;
    enemy.lifetime = event.lifetime;
    enemy.x = static_cast<float>(event.x);
    enemy.y = static_cast<float>(event.y);
    enemy.angle = aimAtPlayer(enemy.x, enemy.y);

    switch (event.spawnType) {
    case 0x06:
    case 0x07:
    case 0x08:
        enemy.hp = 28;
        enemy.radius = 40;
        enemy.visualFrame = 88;
        enemy.vy = 0.25f;
        break;
    case 0x0a:
        enemy.hp = 20;
        enemy.radius = 34;
        enemy.visualFrame = 70;
        enemy.vy = 0.65f;
        break;
    case 0x0b:
        enemy.hp = 8;
        enemy.radius = 24;
        enemy.visualFrame = 16;
        enemy.speed = 1.7f;
        break;
    case 0x0c:
    case 0x0d:
        enemy.hp = 10;
        enemy.radius = 24;
        enemy.visualFrame = 20 + (event.spawnType - 0x0c) * 2;
        enemy.speed = 1.45f;
        break;
    case 0x0e:
    case 0x0f:
    case 0x10:
        enemy.hp = 36;
        enemy.radius = 48;
        enemy.visualFrame = 96;
        enemy.vy = 0.25f;
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
    player_.x = clampFloat(player_.x + dx * speed, kPlayLeft, kPlayRight);
    player_.y = clampFloat(player_.y + dy * speed, kPlayTop, kPlayBottom);

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
        if (isStage04FocusedType(enemy.spawnType)) {
            updateStage04Enemy(enemy, activeAge);
        }
        else {
            updateGenericEnemy(enemy, activeAge);
        }

        enemy.x += enemy.vx;
        enemy.y += enemy.vy;

        if (isStage04FocusedType(enemy.spawnType)) {
            emitStage04Projectiles(enemy, activeAge);
        }
        else {
            emitGenericProjectiles(enemy, activeAge);
        }
    }
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
                if (enemy.hp <= 0) {
                    enemy.active = false;
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
                if (enemy.hp <= 0) {
                    enemy.active = false;
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
        DrawGraph(notes::gameplay_layout::kStageFrameRect.x, notes::gameplay_layout::kStageFrameRect.y, stageFrameFrames_.front(), TRUE);
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
        const auto& frames = stageUsesMediumFrame(enemy.spawnType) ? enemyMediumFrames_ : enemySmallFrames_;
        const int index = frames.empty() ? -1 : std::min(enemy.visualFrame, static_cast<int>(frames.size()) - 1);
        const int handle = index < 0 ? -1 : frames[static_cast<std::size_t>(index)];
        const float x = screenX(enemy.x);
        const float y = screenY(enemy.y);
        if (handle != -1) {
            const double scale = stageUsesMediumFrame(enemy.spawnType) ? 0.42 : 0.55;
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
    }
    drawDebugOverlay();
}

void StageRuntime::drawHudSidebar() const {
    // Layout placeholders: score/reward/gauge/token state is not fully reconstructed yet.
    // Coordinates follow the original HUD draw candidate around FUN_1400c2860.
    constexpr int runScore = 0;
    constexpr int scoreItemBaseValue = 100;
    constexpr int specialGauge = 0;
    constexpr int specialGaugeMax = 50000;
    constexpr int tokenStock = 2;

    if (timeWindowHandle_ != -1) {
        DrawGraph(notes::hud_layout::kTimeWindowRect.x, notes::hud_layout::kTimeWindowRect.y, timeWindowHandle_, TRUE);
    }
    else {
        DrawBox(notes::hud_layout::kTimeWindowRect.x, notes::hud_layout::kTimeWindowRect.y,
                notes::hud_layout::kTimeWindowRect.right(), notes::hud_layout::kTimeWindowRect.bottom(),
                GetColor(18, 20, 36), TRUE);
        DrawBox(notes::hud_layout::kTimeWindowRect.x, notes::hud_layout::kTimeWindowRect.y,
                notes::hud_layout::kTimeWindowRect.right(), notes::hud_layout::kTimeWindowRect.bottom(),
                GetColor(70, 80, 120), FALSE);
    }

    if (dataWindowHandle_ != -1) {
        DrawGraph(notes::hud_layout::kDataWindowRect.x, notes::hud_layout::kDataWindowRect.y, dataWindowHandle_, TRUE);
    }
    else {
        DrawBox(notes::hud_layout::kDataWindowRect.x, notes::hud_layout::kDataWindowRect.y,
                notes::hud_layout::kDataWindowRect.right(), notes::hud_layout::kDataWindowRect.bottom(),
                GetColor(18, 20, 36), TRUE);
        DrawBox(notes::hud_layout::kDataWindowRect.x, notes::hud_layout::kDataWindowRect.y,
                notes::hud_layout::kDataWindowRect.right(), notes::hud_layout::kDataWindowRect.bottom(),
                GetColor(70, 80, 120), FALSE);
    }

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kScoreY - 20, "SCORE", GetColor(180, 210, 255));
    drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kScoreY, runScore, numSmallFrames_, 20, 30, 0.9);

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kBaseValueY - 18, "VALUE", GetColor(180, 210, 255));
    drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kBaseValueY, scoreItemBaseValue, numSmallFrames_, 20, 30, 0.85);

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kGaugeY - 18, "DREAM", GetColor(180, 210, 255));
    drawHudGauge(notes::hud_layout::kLabelX, notes::hud_layout::kGaugeY, specialGauge, specialGaugeMax);

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kTokenY - 18, "TOKEN", GetColor(180, 210, 255));
    drawHudTokenPips(notes::hud_layout::kPipStartX, notes::hud_layout::kTokenY, tokenStock, notes::hud_layout::kMaxTokens);

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kStageY - 18, "STAGE", GetColor(180, 210, 255));
    drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kStageY, selectedStage_, numSmallFrames_, 20, 30, 0.85);

    DrawString(notes::hud_layout::kLabelX, notes::hud_layout::kStockY - 18, "STOCK", GetColor(180, 210, 255));
    DrawString(notes::hud_layout::kNumberRightX - 48, notes::hud_layout::kStockY, "x", GetColor(235, 235, 255));
    drawHudNumber(notes::hud_layout::kNumberRightX, notes::hud_layout::kStockY, std::max(0, player_.lives), numSmallFrames_, 20, 30, 0.85);
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
}

void StageRuntime::drawDebugOverlay() const {
    DrawFormatString(24, notes::kScreenHeight - 48, GetColor(150, 160, 180),
                     "reconstruction probe  stage=%02d frame=%d enemies=%d bullets=%d side=%d shots=%d lives=%d",
                     selectedStage_, frame_, static_cast<int>(enemies_.size()),
                     static_cast<int>(enemyProjectiles_.size()), static_cast<int>(playerSideObjects_.size()),
                     static_cast<int>(playerShots_.size()), player_.lives);
    DrawFormatString(24, notes::kScreenHeight - 26, GetColor(150, 180, 210),
                     "loadout route=%d playerOpt=%d sub=%d loadout=%d shotTimer=%d focus=%d slots=[%d %d %d %d]",
                     config_.routeMode, config_.playerOption, config_.subOption, config_.loadoutId,
                     player_.shotTimer, player_.focused ? 1 : 0,
                     config_.optionSlots[0], config_.optionSlots[1], config_.optionSlots[2], config_.optionSlots[3]);
}

void StageRuntime::drawHudNumber(int rightX, int y, int value, const std::vector<int>& digitFrames, int digitWidth, int digitHeight, double scale) const {
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
    }
}

void StageRuntime::drawHudGauge(int x, int y, int value, int maxValue) const {
    const int width = notes::hud_layout::kGaugeBarWidth;
    const int height = notes::hud_layout::kGaugeBarHeight;
    const float ratio = maxValue <= 0 ? 0.0f : clampFloat(static_cast<float>(value) / static_cast<float>(maxValue), 0.0f, 1.0f);
    if (!dreamGaugeFrames_.empty() && dreamGaugeFrames_.front() != -1) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 95);
        DrawRotaGraphF(static_cast<float>(x + notes::hud_layout::kDreamGaugePreviewCenterOffsetX),
                       static_cast<float>(y + notes::hud_layout::kDreamGaugePreviewCenterOffsetY),
                       notes::hud_layout::kDreamGaugePreviewScale, 0.0, dreamGaugeFrames_.front(), TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    DrawBox(x, y, x + width, y + height, GetColor(32, 36, 64), TRUE);
    DrawBox(x, y, x + width, y + height, GetColor(96, 120, 180), FALSE);
    DrawBox(x + 2, y + 2, x + 2 + static_cast<int>((width - 4) * ratio), y + height - 2, GetColor(100, 220, 255), TRUE);
}

void StageRuntime::drawHudTokenPips(int x, int y, int activeCount, int maxCount) const {
    activeCount = std::max(0, std::min(activeCount, maxCount));
    for (int i = 0; i < maxCount; ++i) {
        const bool active = i < activeCount;
        const int cx = x + i * notes::hud_layout::kPipStep;
        const int color = active ? GetColor(150, 235, 255) : GetColor(60, 68, 88);
        DrawCircle(cx, y + 8, 7, color, TRUE);
        DrawCircle(cx, y + 8, 7, GetColor(150, 170, 210), FALSE);
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
