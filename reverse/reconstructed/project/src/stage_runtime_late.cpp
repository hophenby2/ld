#include "stage_runtime.h"

#include <DxLib.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

constexpr double kPi = 3.14159265358979323846;
constexpr double kTau = kPi * 2.0;
constexpr int kUseScheduledY = 0x7fffffff;
constexpr std::size_t kLateStageEntityCap = 0x200;

struct LateSpawnSpec {
    int spawnType;
    int updateCase;
    int entityKind;
    int radius;
    int forcedY;
};

// updateCase comes from stage-spawn-used-update-map.csv. entityKind/radius and
// the forced-y branches come from stage-spawn-dispatch-used-types.csv plus the
// recovered common tails at 0x14007bf81..0x14007bfc3.
constexpr std::array<LateSpawnSpec, 60> kLateSpawnSpecs{{
    {0x44, 0x32,   5,  30, kUseScheduledY},
    {0x45, 0x33,   7,  40, kUseScheduledY},
    {0x46, 0x34,  12,  70, kUseScheduledY},
    {0x47, 0x35,  20,  80, kUseScheduledY},
    {0x48, 0x35,  20,  80, kUseScheduledY},
    // Internally-created Stage 5 nodes. Their x/y constructor fields are
    // offsets or polar radii interpreted by the owning helper.
    {0x49, 0x36,   5,  35, kUseScheduledY},
    {0x4a, 0x37,  42,  90, -100},
    {0x4b, 0x1c,   1,  20, kUseScheduledY},
    {0x4c, 0x38,   4,  80, kUseScheduledY},
    {0x4d, 0x39,  80,  90, kUseScheduledY},
    {0x4e, 0x3a,   8,  30, kUseScheduledY},
    {0x4f, 0x3b, 120, 160, kUseScheduledY},
    {0x50, 0x3c,   0, 100, kUseScheduledY},
    {0x51, 0x3c,   0, 100, kUseScheduledY},
    {0x52, 0x3c,   0, 100, kUseScheduledY},
    {0x53, 0x3d,   1,  40, kUseScheduledY},
    // FUN_14001c8b0 creates these only while the Stage 5 final boss is
    // active. They use the dispatcher slots at 0x3e..0x40.
    {0x54, 0x3e,   0,  40, kUseScheduledY},
    {0x55, 0x3f,   2,  25, kUseScheduledY},
    {0x56, 0x40,   1,  40, kUseScheduledY},
    {0x57, 0x41,  12,  60, kUseScheduledY},
    {0x58, 0x41,  12,  60, kUseScheduledY},
    {0x59, 0x42,  20,  60, kUseScheduledY},
    {0x5a, 0x43,   6,  40, kUseScheduledY},
    {0x5b, 0x44,   6,  40, kUseScheduledY},
    {0x5c, 0x44,   6,  40, kUseScheduledY},
    {0x5d, 0x45,  20,  60, kUseScheduledY},
    {0x5e, 0x46,  36,  95, kUseScheduledY},
    {0x5f, 0x47,  77, 120, kUseScheduledY},
    {0x60, 0x48,   1,  25, kUseScheduledY},
    {0x70, 0x4f,  10,  40, kUseScheduledY},
    {0x71, 0x50,  24,  80, kUseScheduledY},
    {0x72, 0x50,  24,  80, kUseScheduledY},
    {0x73, 0x51,  36, 100, -100},
    {0x74, 0x52,  10,  40, kUseScheduledY},
    {0x75, 0x53,  15,  50, kUseScheduledY},
    {0x76, 0x54,  64, 110, kUseScheduledY},
    {0x77, 0x55, 100,  60, kUseScheduledY},
    {0x95, 0x62,   5,  45, kUseScheduledY},
    {0x96, 0x63,   5,  40, kUseScheduledY},
    {0x97, 0x64,   7,  50, kUseScheduledY},
    {0x98, 0x64,   7,  50, kUseScheduledY},
    {0x99, 0x64,   7,  50, kUseScheduledY},
    {0x9a, 0x65,  80, 140, kUseScheduledY},
    {0x9b, 0x66,  24,  70, kUseScheduledY},
    {0x9c, 0x66,  24,  70, kUseScheduledY},
    {0x9e, 0x66,  24,  70, kUseScheduledY},
    {0x9f, 0x66,  24,  70, kUseScheduledY},
    {0xa1, 0x66,  24,  70, kUseScheduledY},
    {0xa2, 0x66,  24,  70, kUseScheduledY},
    {0xa4, 0x67, 120,  90, kUseScheduledY},
    // S09 directly calls FUN_140078a00 for 0xad rather than the spawn
    // dispatcher: case 0x6c, kind 5, y=-10, speed 1, radius 40.
    {0xad, 0x6c,   5,  40, -10},
    {0xfa, 0x82,   5,  45, kUseScheduledY},
    {0xfb, 0x83,   5,  45, -20},
    {0xfc, 0x84,  10,  60, -60},
    {0xfd, 0x85,  16,  50, -50},
    {0xfe, 0x86,  24,  70, kUseScheduledY},
    {0x100, 0x87, 24,  70, kUseScheduledY},
    {0x102, 0x88, 36,  90, -100},
    {0x103, 0x89, 48,  90, kUseScheduledY},
    {0x104, 0x89, 48,  90, kUseScheduledY},
}};

struct LateBossSpec {
    int spawnType;
    int updateCase;
    float spawnX;
    float spawnY;
    float targetX;
    float targetY;
    double speed;
    int radius;
    int breaks;
};

struct Stage10FinalBossNodeSpec {
    int spawnType;
    int updateCase;
    float spawnY;
    int radius;
    int parentBreakState;
};

// FUN_140052fb0 creates these six shared-HP apparatus nodes at timer 30 of
// combat states 11, 31, 51, 71, 91, and 111 respectively.
constexpr std::array<Stage10FinalBossNodeSpec, 6> kStage10FinalBossNodeSpecs{{
    {0x111, 0x8d, 250.0f, 150,  20},
    {0x112, 0x8e, 250.0f, 100,  40},
    {0x113, 0x8f, 300.0f,  80,  60},
    {0x115, 0x91, 250.0f, 150,  80},
    {0x11a, 0x93, 250.0f, 170, 100},
    {0x11d, 0x95, 320.0f, 150, 120},
}};

// Direct FUN_140078a00 call arguments recovered from the per-stage handlers.
// 0x142 has no observed direct call; its dispatch slot is retained so an
// internally-created node never falls through to the generic implementation.
constexpr std::array<LateBossSpec, 17> kLateBossSpecs{{
    {0x13c, 0xa3, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 175,  6},
    {0x13d, 0xa4, 480.0f,  150.0f, 480.0f, 150.0f, 0.3, 175,  5},
    {0x13e, 0xa5, 360.0f,  250.0f, 360.0f, 200.0f, 0.2, 210,  5},
    {0x13f, 0xa6, 360.0f,  180.0f, 360.0f, 180.0f, 0.3, 130,  6},
    {0x140, 0xa7, 360.0f,  190.0f, 360.0f, 190.0f, 0.1, 140,  4},
    {0x141, 0xa8, 360.0f,  320.0f, 360.0f, 200.0f, 0.4,  80, 16},
    {0x142, 0xb6, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 100,  0},
    {0x143, 0xa9, 400.0f,  240.0f, 400.0f, 240.0f, 0.3,  80,  1},
    {0x144, 0xaa, 360.0f,  900.0f, 360.0f, 200.0f, 0.3,  50,  1},
    {0x145, 0xab, 360.0f,  900.0f, 360.0f, 200.0f, 0.3,  50,  1},
    {0x146, 0xac, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 160,  1},
    {0x147, 0xad, 360.0f,  270.0f, 360.0f, 200.0f, 0.3, 220,  1},
    {0x148, 0xae, 360.0f,  200.0f, 360.0f, 200.0f, 4.5, 150,  1},
    {0x149, 0xaf, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 200,  1},
    {0x14a, 0xb0, 360.0f,  200.0f, 360.0f, 200.0f, 0.3, 175,  1},
    {0x14b, 0xb1, 360.0f,  240.0f, 360.0f, 200.0f, 1.6, 175,  1},
    {0x14c, 0xb2, 360.0f, -2400.0f, 360.0f, 250.0f, 0.0, 200,  3},
}};

const LateSpawnSpec* lateSpawnSpec(int spawnType) {
    for (const auto& spec : kLateSpawnSpecs) {
        if (spec.spawnType == spawnType) {
            return &spec;
        }
    }
    return nullptr;
}

const LateBossSpec* lateBossSpec(int spawnType) {
    for (const auto& spec : kLateBossSpecs) {
        if (spec.spawnType == spawnType) {
            return &spec;
        }
    }
    return nullptr;
}

const Stage10FinalBossNodeSpec* stage10FinalBossNodeSpec(int spawnType) {
    for (const auto& spec : kStage10FinalBossNodeSpecs) {
        if (spec.spawnType == spawnType) {
            return &spec;
        }
    }
    return nullptr;
}

bool isStage10FinalBossAuxNodeType(int spawnType) {
    return spawnType == 0x114 ||
           (spawnType >= 0x116 && spawnType <= 0x119) ||
           spawnType == 0x11b || spawnType == 0x11c ||
           (spawnType >= 0x11e && spawnType <= 0x122);
}

bool isStage06BossNodeType(int spawnType) {
    return spawnType >= 0x64 && spawnType <= 0x6f;
}

std::uint16_t normalizeAngle16(int angle) {
    return static_cast<std::uint16_t>(angle & 0xffff);
}

double fixedAngleRadians(std::uint16_t angle) {
    return static_cast<double>(angle) * kTau / 65536.0;
}

std::uint16_t radiansToAngle16(double radians) {
    return normalizeAngle16(static_cast<int>(radians * 65536.0 / kTau));
}

std::uint16_t approachAngle16(std::uint16_t current, std::uint16_t target,
                              int step) {
    int delta = static_cast<int>(target) - static_cast<int>(current);
    if (delta > 0x8000) delta -= 0x10000;
    if (delta < -0x8000) delta += 0x10000;
    delta = std::clamp(delta, -step, step);
    return normalizeAngle16(static_cast<int>(current) + delta);
}

double smoothStep(double value) {
    value = std::clamp(value, 0.0, 1.0);
    return value * value * (3.0 - 2.0 * value);
}

int frameHandle(const std::vector<int>& frames, int index) {
    return index >= 0 && index < static_cast<int>(frames.size())
               ? frames[static_cast<std::size_t>(index)]
               : -1;
}

std::uint32_t lateBossFrameRand(int frame) {
    const auto seed = static_cast<std::uint32_t>(frame);
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

template <std::size_t N>
int loopingFrame(int timer, int start, int hold,
                 const std::array<int, N>& frames) {
    const int local = (timer - start) % (hold * static_cast<int>(N));
    return frames[static_cast<std::size_t>(local / hold)];
}

int lateEnemyDeathRewardWindow(int spawnType, int fallbackWeight) {
    switch (spawnType) {
    case 0x44: return 200;
    case 0x45: return 0xf0;
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4d:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x4e: return 500;
    case 0x4c: return 300;
    case 0x70: return 0x168;
    case 0x74:
    case 0x75: return 600;
    case 0x76: return 800;
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e: return 1000;
    case 0x4f:
    case 0x5f:
    case 0x77: return 0x708;
    default: return std::max(200, fallbackWeight * 10);
    }
}

int lateEnemyDeathEffectMode(int spawnType, int radius) {
    switch (spawnType) {
    case 0x44:
    case 0x45:
    case 0x4c:
    case 0x4e:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x70:
    case 0x74: return 0;
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5d:
    case 0x5e:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x75: return 1;
    case 0x4d:
    case 0x4f:
    case 0x5f:
    case 0x76:
    case 0x77: return 2;
    default: return radius >= 100 ? 2 : 1;
    }
}

double lateEnemyProjectileSpeed(int difficulty,
                                const std::array<double, 5>& values) {
    return values[static_cast<std::size_t>(std::clamp(difficulty, 0, 4))];
}

std::uint32_t lateStageScriptRand(int seed) {
    const auto value = static_cast<std::uint32_t>(seed);
    const std::uint32_t u = ((value >> 30) ^ value) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

} // namespace

bool StageRuntime::configureLateStageEnemy(StageEnemy& enemy,
                                           const StageSpawnEvent& event) {
    if (const LateSpawnSpec* spec = lateSpawnSpec(event.spawnType)) {
        enemy.updateCase = spec->updateCase;
        enemy.sourceDispatchKind = spec->entityKind;
        enemy.sourceDispatchField = spec->radius;
        enemy.rewardWeight = spec->entityKind;
        enemy.radius = spec->radius;
        if (spec->forcedY != kUseScheduledY) {
            enemy.y = static_cast<float>(spec->forcedY);
            enemy.originY = enemy.y;
            enemy.sourceY = spec->forcedY;
        }
        enemy.visualFrame = spec->updateCase;
        enemy.sourceAngle16 = 0x4000;
        enemy.secondaryAngle16 = 0x4000;
        enemy.targetAngle16 = 0x4000;
        enemy.angle = static_cast<float>(fixedAngleRadians(enemy.sourceAngle16));
        enemy.sourceSpeed = 1.0;
        enemy.speed = 1.0f;
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.activationDelay = 0;
        enemy.targetable = false;
        return true;
    }

    const LateBossSpec* spec = lateBossSpec(event.spawnType);
    if (spec == nullptr) {
        return false;
    }

    enemy.updateCase = spec->updateCase;
    enemy.sourceDispatchKind = 0;
    enemy.sourceDispatchField = spec->radius;
    enemy.rewardWeight = 0;
    enemy.radius = spec->radius;
    enemy.x = spec->spawnX;
    enemy.y = spec->spawnY;
    enemy.originX = spec->spawnX;
    enemy.originY = spec->spawnY;
    enemy.markerDrawX = spec->targetX;
    enemy.markerDrawY = spec->targetY;
    enemy.sourceX = static_cast<int>(spec->spawnX);
    enemy.sourceY = static_cast<int>(spec->spawnY);
    enemy.sourceAngle16 = 0;
    enemy.secondaryAngle16 = 0;
    enemy.targetAngle16 = 0;
    enemy.angle = 0.0f;
    enemy.sourceSpeed = spec->speed;
    enemy.speed = static_cast<float>(spec->speed);
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.activationDelay = 0;
    enemy.targetable = false;

    if (isLateStageFinalBossType(event.spawnType)) {
        lateStageBossPhaseMode_ = 0;
        lateStageBossPhaseIndex_ = 0;
        lateStageBossBreaksRemaining_ = spec->breaks;
        lateStageBossCountdown_ = 0;
        lateStageBossMaxHp_ = event.hitPoints;
        lateStageBossTargetX_ = spec->targetX;
        lateStageBossTargetY_ = spec->targetY;
        lateStageClearStarted_ = false;
        lateStageClearTimer_ = 0;
        clearLateStageGate(selectedStage_);
        switch (selectedStage_) {
        case 5: stage05GateFlag_ = true; break;
        case 6: stage06GateFlag_ = true; break;
        case 7: stage07GateFlag_ = true; break;
        case 8: stage08GateFlag_ = true; break;
        case 9: stage09GateFlag_ = true; break;
        case 10: stage10GateFlag_ = true; break;
        default: break;
        }
    }
    else if (event.spawnType == 0x14c) {
        // FUN_14012b260 initializes DAT_140e418cc to zero for the scene root.
        stage10GateFlag_ = false;
        lateStageBossBreaksRemaining_ = spec->breaks;
        lateStageBossPhaseIndex_ = 0;
        lateStageBossPhaseMode_ = 0;
        lateStageBossCountdown_ = 0;
        lateStageBossMaxHp_ = event.hitPoints;
    }
    return true;
}

bool StageRuntime::isLateStageEnemyType(int spawnType) const {
    return lateSpawnSpec(spawnType) != nullptr || lateBossSpec(spawnType) != nullptr ||
           isStage06BossNodeType(spawnType) ||
           stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType);
}

bool StageRuntime::isLateStageBossType(int spawnType) const {
    return lateBossSpec(spawnType) != nullptr ||
           isStage06BossNodeType(spawnType) ||
           stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType);
}

bool StageRuntime::isLateStageFinalBossType(int spawnType) const {
    return spawnType >= 0x13c && spawnType <= 0x141;
}

bool StageRuntime::isStage10FinalBossNodeType(int spawnType) const {
    return stage10FinalBossNodeSpec(spawnType) != nullptr ||
           isStage10FinalBossAuxNodeType(spawnType);
}

bool StageRuntime::isLateStageGateOwner(const StageEnemy& enemy) const {
    switch (selectedStage_) {
    case 5: return enemy.spawnType == 0x4f;
    case 6: return enemy.spawnType == 0x143;
    case 7:
        return enemy.spawnType == 0x77 || enemy.spawnType == 0x144 ||
               enemy.spawnType == 0x145;
    case 8: return enemy.spawnType == 0xa4 || enemy.spawnType == 0x2e;
    case 9:
        return enemy.spawnType == 0xa4 ||
               (enemy.spawnType >= 0x146 && enemy.spawnType <= 0x14b);
    default: return false;
    }
}

void StageRuntime::clearLateStageGate(int stage) {
    switch (stage) {
    case 5: stage05GateFlag_ = false; break;
    case 6: stage06GateFlag_ = false; break;
    case 7: stage07GateFlag_ = false; break;
    case 8: stage08GateFlag_ = false; break;
    case 9: stage09GateFlag_ = false; break;
    case 10: stage10GateFlag_ = false; break;
    default: break;
    }
}

bool StageRuntime::spawnStage10FinalBossNode(StageEnemy& parent,
                                             int spawnType) {
    const Stage10FinalBossNodeSpec* spec = stage10FinalBossNodeSpec(spawnType);
    if (spec == nullptr || parent.spawnType != 0x141 ||
        enemies_.size() + pendingEnemies_.size() >= kLateStageEntityCap) {
        return false;
    }
    const auto alreadyPresent = [&parent, spawnType](const StageEnemy& node) {
        return node.active && node.spawnType == spawnType &&
               node.parentEntityId == parent.entityId;
    };
    if (std::any_of(enemies_.begin(), enemies_.end(), alreadyPresent) ||
        std::any_of(pendingEnemies_.begin(), pendingEnemies_.end(), alreadyPresent)) {
        return false;
    }

    const char* note = nullptr;
    switch (spawnType) {
    case 0x111: note = "S10 FUN_140052fb0 state 11 timer 30 node 0x111"; break;
    case 0x112: note = "S10 FUN_140052fb0 state 31 timer 30 node 0x112"; break;
    case 0x113: note = "S10 FUN_140052fb0 state 51 timer 30 node 0x113"; break;
    case 0x115: note = "S10 FUN_140052fb0 state 71 timer 30 node 0x115"; break;
    case 0x11a: note = "S10 FUN_140052fb0 state 91 timer 30 node 0x11a"; break;
    case 0x11d: note = "S10 FUN_140052fb0 state 111 timer 30 node 0x11d"; break;
    default: break;
    }

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = spec->updateCase;
    node.sourceHitPoints = 99999999;
    node.sourceX = 360;
    node.sourceY = static_cast<int>(spec->spawnY);
    node.sourceNote = note;
    node.sourceDispatchKind = 0;
    node.sourceDispatchField = spec->radius;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = 0x141;
    node.x = 360.0f;
    node.y = spec->spawnY;
    node.originX = node.x;
    node.originY = node.y;
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    node.sourceAngle16 = 0x4000;
    node.secondaryAngle16 = 0x4000;
    node.targetAngle16 = 0x4000;
    node.angle = static_cast<float>(fixedAngleRadians(node.sourceAngle16));
    node.sourceSpeed = 1.0;
    node.speed = 1.0f;
    node.hp = config_.difficulty == 0 ? 79999999 : 99999999;
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = spec->radius;
    node.activationDelay = 0;
    node.rewardWeight = 0;
    node.targetable = false;
    pendingEnemies_.push_back(node);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage10FinalBossNode(StageEnemy& enemy) {
    if (isStage10FinalBossAuxNodeType(enemy.spawnType)) {
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        enemy.drawMarkerThisFrame = false;
        enemy.drawBodyThisFrame = true;
        StageEnemy* owner = findEnemyById(enemy.parentEntityId);
        if (owner == nullptr || !owner->active ||
            owner->spawnType != enemy.parentSpawnType) {
            enemy.targetable = false;
            enemy.active = false;
            return;
        }

        const int timer = enemy.helperTimer;
        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const auto aimAtPlayer = [this, &enemy]() {
            return radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - enemy.y),
                static_cast<double>(player_.x - enemy.x)));
        };
        bool fired = false;

        if (enemy.spawnType == 0x114) {
            const float targetX = owner->x + enemy.originX;
            const float targetY = owner->y + enemy.originY;
            enemy.x += (targetX - enemy.x) * 0.2f;
            enemy.y += (targetY - enemy.y) * 0.2f;
            enemy.targetAngle16 = radiansToAngle16(std::atan2(
                static_cast<double>(targetY - enemy.y),
                static_cast<double>(targetX - enemy.x)));
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, enemy.targetAngle16,
                0x80 + std::abs(static_cast<int>(enemy.targetAngle16) -
                                static_cast<int>(enemy.sourceAngle16)) / 10);
            enemy.targetable = false;
            if (owner->helperState == 1 && timer >= 40) {
                const int local = (timer - 40 + enemy.childIndex * 9) % 0x50;
                if (local < 20 && local % 5 == 0) {
                    spawnProjectileNode(10, 1, enemy.x, enemy.y,
                                        aimAtPlayer(), 10.0f,
                                        8.0 + difficulty * 0.4, 6, 0);
                    fired = true;
                }
            }
        }
        else if (enemy.spawnType >= 0x116 && enemy.spawnType <= 0x119) {
            if (owner->helperState == 99 && enemy.helperState < 99) {
                enemy.helperState = 99;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                return;
            }
            if (enemy.hp < 1 && enemy.helperState < 99) {
                spawnEnemyDeathRewardBurst(enemy, 0x960);
                spawnEnemyDeathEffects(enemy, 2);
                enemy.helperState = 99;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                return;
            }
            if (enemy.helperState == 99) {
                enemy.targetable = false;
                if (timer < 90) {
                    enemy.y += static_cast<float>(timer) * 0.02f;
                }
                if (timer >= 140) {
                    enemy.active = false;
                }
            }
            else {
                if (enemy.helperState == 0 && owner->helperState >= 1) {
                    enemy.helperState = 1;
                    enemy.helperTimer = 0;
                    enemy.targetable = false;
                }
                else if (enemy.helperState >= 1) {
                    enemy.targetable = true;
                    const double phase = static_cast<double>(enemy.age) *
                                             kTau / 240.0 +
                                         enemy.childIndex * kPi * 0.5;
                    const float targetX = enemy.originX +
                        static_cast<float>(std::cos(phase) * 70.0);
                    const float targetY = enemy.originY + 120.0f +
                        static_cast<float>(std::sin(phase * 0.7) * 55.0);
                    enemy.x += (targetX - enemy.x) * 0.055f;
                    enemy.y += (targetY - enemy.y) * 0.055f;

                    const int cadence = std::max(12, 27 - difficulty * 3);
                    if (timer >= 30 && timer % cadence == 0) {
                        if ((enemy.spawnType & 1) == 0) {
                            spawnProjectileSpread(0x0b, 1, enemy.x, enemy.y,
                                                  aimAtPlayer(), 0.0f,
                                                  5.0 + difficulty * 0.5,
                                                  6, 5 + difficulty,
                                                  0x2800, 0);
                        }
                        else {
                            spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                                  normalizeAngle16(
                                                      enemy.age * 0x3c),
                                                  0.0f,
                                                  6.0 + difficulty * 0.4,
                                                  6, 12 + difficulty * 2,
                                                  0x10000, 0);
                        }
                        fired = true;
                    }
                    if (timer >= 80) {
                        enemy.helperState = enemy.helperState == 4
                                                ? 1
                                                : enemy.helperState + 1;
                        enemy.helperTimer = 0;
                    }
                }
            }
        }
        else if (enemy.spawnType == 0x11b || enemy.spawnType == 0x11c) {
            if (owner->helperState == 99 && enemy.helperState < 99) {
                enemy.helperState = 99;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                return;
            }
            enemy.targetable = false;
            const float targetX = owner->x + enemy.originX;
            const float targetY = owner->y + enemy.originY;
            if (owner->helperState == 0) {
                enemy.x = targetX;
                enemy.y = targetY;
            }
            else {
                enemy.x += (targetX - enemy.x) * 0.5f;
                enemy.y += (targetY - enemy.y) * 0.5f;
            }
            if (enemy.helperState == 99 && timer >= 100) {
                enemy.active = false;
            }
        }
        else { // FUN_1400630f0: 0x11e..0x122 parent-relative batteries
            if (owner->helperState == 99 && enemy.helperState < 99) {
                enemy.helperState = 99;
                enemy.helperTimer = 0;
                enemy.targetable = false;
                return;
            }
            const float targetX = owner->x + enemy.originX;
            const float targetY = owner->y + enemy.originY;
            enemy.x += (targetX - enemy.x) * 0.2f;
            enemy.y += (targetY - enemy.y) * 0.2f;

            if (enemy.helperState == 99) {
                enemy.targetable = false;
                if (timer >= 100) {
                    enemy.active = false;
                }
            }
            else {
                enemy.targetable = owner->targetable;
                if (enemy.targetable) {
                    if (enemy.hp < owner->hp) {
                        owner->hp = enemy.hp;
                    }
                    else if (owner->hp < enemy.hp) {
                        enemy.hp = owner->hp;
                    }
                    enemy.drawHp = owner->drawHp;

                    const int cadence = std::max(14, 34 - difficulty * 4);
                    if (timer >= 30 &&
                        (timer + enemy.childIndex * 3) % cadence == 0) {
                        const double speed = 4.0 + enemy.childIndex * 0.35;
                        if ((enemy.childIndex & 1) == 0) {
                            spawnProjectileSpread(7, 0, enemy.x, enemy.y,
                                                  aimAtPlayer(), 0.0f,
                                                  speed, 6,
                                                  7 + difficulty,
                                                  0x3000, 0);
                        }
                        else {
                            spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                                  normalizeAngle16(
                                                      enemy.age * 2000 +
                                                      enemy.childIndex * 5000),
                                                  0.0f, speed, 6,
                                                  8 + difficulty * 2,
                                                  0x10000, 0);
                        }
                        fired = true;
                    }
                }
            }
        }

        if (fired) {
            playPlayerSound(bullet2SoundHandle_, 9);
        }
        return;
    }

    const Stage10FinalBossNodeSpec* spec =
        stage10FinalBossNodeSpec(enemy.spawnType);
    if (spec == nullptr) {
        enemy.active = false;
        return;
    }

    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    if (parent == nullptr || parent->spawnType != 0x141 || !parent->active) {
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    const auto spawnAuxNode =
        [this](int spawnType, int parentEntityId, int parentSpawnType,
               int childIndex, float x, float y, float offsetX,
               float offsetY, int hitPoints, int radius) {
            if (enemies_.size() + pendingEnemies_.size() >=
                kLateStageEntityCap) {
                return 0;
            }
            int updateCase = 0;
            if (spawnType == 0x114) updateCase = 0x90;
            else if (spawnType >= 0x116 && spawnType <= 0x119) updateCase = 0x92;
            else if (spawnType == 0x11b || spawnType == 0x11c) updateCase = 0x94;
            else if (spawnType >= 0x11e && spawnType <= 0x122) updateCase = 0x96;
            else return 0;

            StageEnemy node;
            node.entityId = nextEntityId_++;
            node.spawnType = spawnType;
            node.updateCase = updateCase;
            node.sourceHitPoints = hitPoints;
            node.sourceX = static_cast<int>(std::lround(offsetX));
            node.sourceY = static_cast<int>(std::lround(offsetY));
            node.sourceNote = "S10 final-boss recovered auxiliary node";
            node.sourceDispatchKind = spawnType >= 0x116 &&
                                              spawnType <= 0x119
                                          ? 0x50
                                          : 0;
            node.sourceDispatchField = radius;
            node.parentEntityId = parentEntityId;
            node.parentSpawnType = parentSpawnType;
            node.childIndex = childIndex;
            node.x = x;
            node.y = y;
            node.originX = offsetX;
            node.originY = offsetY;
            node.markerDrawX = x;
            node.markerDrawY = y;
            node.sourceAngle16 = 0x4000;
            node.secondaryAngle16 = 0x4000;
            node.targetAngle16 = 0x4000;
            node.angle = static_cast<float>(fixedAngleRadians(0x4000));
            node.sourceSpeed = 1.0;
            node.speed = 1.0f;
            const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
            node.hp = std::max(1, static_cast<int>(hitPoints * hpScale));
            node.maxHp = node.hp;
            node.drawHp = node.hp;
            node.radius = radius;
            node.activationDelay = 0;
            node.rewardWeight = node.sourceDispatchKind;
            node.targetable = false;
            pendingEnemies_.push_back(node);
            return node.entityId;
        };

    if (enemy.helperState == 0 && enemy.helperTimer == 0) {
        if (enemy.spawnType == 0x115) {
            spawnAuxNode(0x116, enemy.entityId, enemy.spawnType, 0,
                         170.0f, 150.0f, 170.0f, 150.0f,
                         7000, 120);
            spawnAuxNode(0x117, enemy.entityId, enemy.spawnType, 1,
                         550.0f, 150.0f, 550.0f, 150.0f,
                         7000, 120);
        }
        else if (enemy.spawnType == 0x11a) {
            const int centerId = spawnAuxNode(
                0x11b, enemy.entityId, enemy.spawnType, 0,
                enemy.x, enemy.y, 0.0f, -80.0f,
                99999999, 100);
            if (centerId != 0) {
                spawnAuxNode(0x11c, centerId, 0x11b, 0,
                             enemy.x, enemy.y - 80.0f,
                             0.0f, 80.0f, 99999999, 100);
            }
        }
        else if (enemy.spawnType == 0x11d) {
            constexpr std::array<int, 9> kTypes{{
                0x11e, 0x11f, 0x11f, 0x120, 0x120,
                0x121, 0x121, 0x122, 0x122,
            }};
            constexpr std::array<float, 9> kOffsetX{{
                0.0f, 70.0f, -70.0f, 160.0f, -160.0f,
                240.0f, -240.0f, 300.0f, -300.0f,
            }};
            constexpr std::array<float, 9> kOffsetY{{
                -300.0f, -180.0f, -180.0f, -260.0f, -260.0f,
                -310.0f, -310.0f, -240.0f, -240.0f,
            }};
            constexpr std::array<double, 9> kSpeed{{
                10.0, 20.0, 20.0, 30.0, 30.0,
                40.0, 40.0, 50.0, 50.0,
            }};
            for (std::size_t i = 0; i < kTypes.size(); ++i) {
                const int entityId = spawnAuxNode(
                    kTypes[i], enemy.entityId, enemy.spawnType,
                    static_cast<int>(i), enemy.x, enemy.y,
                    kOffsetX[i], kOffsetY[i], 99999999, 60);
                if (entityId != 0 && !pendingEnemies_.empty()) {
                    pendingEnemies_.back().sourceSpeed = kSpeed[i];
                    pendingEnemies_.back().speed = static_cast<float>(kSpeed[i]);
                    pendingEnemies_.back().hp = enemy.hp;
                    pendingEnemies_.back().maxHp = enemy.maxHp;
                    pendingEnemies_.back().drawHp = enemy.drawHp;
                }
            }
        }
    }

    if (enemy.helperState < 99 &&
        (parent->helperState == spec->parentBreakState ||
         parent->helperState == 200)) {
        enemy.helperState = 99;
        enemy.helperTimer = 0;
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        spawnStage02DeathExplosionChain(enemy);
    }

    if (enemy.helperState == 99) {
        enemy.targetable = false;
        enemy.drawBodyThisFrame = enemy.helperTimer < 100;
        if (enemy.helperTimer < 90) {
            enemy.y += static_cast<float>(enemy.helperTimer) * 0.02f;
        }
        if (enemy.helperTimer < 90 && enemy.helperTimer % 6 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (enemy.helperTimer == 90) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 1, false);
        }
        if (enemy.helperTimer >= 140) {
            enemy.active = false;
            if (parent->liveChildCount > 0) {
                --parent->liveChildCount;
            }
        }
        return;
    }

    // Each helper owns a 190-tick materialization state. At the transition it
    // copies the root's current and queued HP fields and becomes targetable.
    if (enemy.helperState == 0) {
        enemy.targetable = false;
        if (enemy.helperTimer >= 190) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = std::max(1, parent->hp);
            enemy.maxHp = std::max(1, parent->maxHp);
            enemy.drawHp = parent->drawHp;
            // The state-0 helper leaves +0x54 set for the transition frame;
            // state 1 clears it on the following entity dispatch.
            enemy.targetable = false;
            enemy.targetableTimer = 0;
            switch (enemy.spawnType) {
            case 0x111: enemy.sourceSpeed = 0.3; break;
            case 0x112:
                enemy.sourceSpeed = 30.0;
                enemy.markerDrawX = 540.0f;
                enemy.markerDrawY = 330.0f;
                break;
            case 0x113: enemy.sourceSpeed = 0.5; break;
            case 0x115: enemy.sourceSpeed = 1.0; break;
            case 0x11a:
                enemy.sourceSpeed = 70.0;
                enemy.markerDrawX = 300.0f;
                enemy.markerDrawY = 140.0f;
                break;
            case 0x11d:
                enemy.sourceSpeed = 20.0;
                enemy.markerDrawX = 320.0f;
                enemy.markerDrawY = 220.0f;
                break;
            default: break;
            }
        }
        return;
    }

    // FUN_14005a3f0 and its sibling helpers make the apparatus a second hit
    // surface for the root: damage received by either surface is reflected to
    // the other before this frame's body is queued.
    if (enemy.hp < parent->hp) {
        parent->hp = enemy.hp;
    }
    else if (parent->hp < enemy.hp) {
        enemy.hp = parent->hp;
    }
    if (parent->hp < 1 || enemy.hp < 1) {
        parent->hp = std::min(parent->hp, enemy.hp);
        enemy.hp = parent->hp;
    }
    enemy.drawHp = parent->drawHp;
    enemy.targetable = true;

    const int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimAt = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };
    const auto steerAndMove = [&enemy](float targetX, float targetY,
                                       int turnStep, double speed) {
        const auto target = radiansToAngle16(std::atan2(
            static_cast<double>(targetY - enemy.y),
            static_cast<double>(targetX - enemy.x)));
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target,
                                              turnStep);
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * speed);
        enemy.y += static_cast<float>(std::sin(radians) * speed);
    };
    const auto moveByDivisor = [&enemy](float targetX, float targetY,
                                        double divisor) {
        const float dx = targetX - enemy.x;
        const float dy = targetY - enemy.y;
        enemy.x += dx / static_cast<float>(std::max(1.0, divisor));
        enemy.y += dy / static_cast<float>(std::max(1.0, divisor));
        enemy.sourceAngle16 = radiansToAngle16(std::atan2(
            static_cast<double>(dy), static_cast<double>(dx)));
    };
    bool fired = false;

    switch (enemy.spawnType) {
    case 0x111: { // FUN_14005a3f0
        if (timer % 50 == 0) {
            enemy.markerDrawX = 210.0f + static_cast<float>(
                lateBossFrameRand(frame_ + enemy.entityId) % 301u);
            enemy.markerDrawY = 200.0f + static_cast<float>(
                lateBossFrameRand(frame_ + 0x457 + enemy.entityId) % 101u);
        }
        steerAndMove(enemy.markerDrawX, enemy.markerDrawY, 0x200, 0.3);
        if (timer >= 30) {
            const int local = (timer - 30) % 0x398;
            const bool shortFan =
                ((local >= 0x1e && local < 0x46) ||
                 (local >= 0x1e0 && local < 0x208)) &&
                (local & 3) == 0;
            if (shortFan) {
                const auto aimed = aimAt(enemy.x - 99.0f, enemy.y - 120.0f);
                spawnProjectileSpread(0x0b, 0, enemy.x - 99.0f,
                                      enemy.y - 120.0f, aimed, 0.0f, 11.1,
                                      6, 5, 10000, 0);
                fired = true;
            }
            if (local == 0x50) {
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(aimAt(enemy.x + 108.0f,
                                           enemy.y - 105.0f)) - 0x4000);
            }
            if (local >= 0x50 && local < 0x186 && (local & 1) == 0) {
                const double speed = 5.5 + static_cast<double>(local - 0x50) * 0.025;
                spawnProjectileNode(2, 0x39, enemy.x + 108.0f,
                                    enemy.y - 105.0f, enemy.secondaryAngle16,
                                    0.0f, speed, 6, 0);
                spawnProjectileNode(3, 9, enemy.x + 108.0f,
                                    enemy.y - 105.0f, enemy.secondaryAngle16,
                                    0.0f, speed + 2.0, 6, 0);
                enemy.secondaryAngle16 = normalizeAngle16(
                    static_cast<int>(enemy.secondaryAngle16) - 0x960);
                fired = true;
            }
            if (local >= 0x208 && local < 0x384 &&
                ((local - 0x208) & 7) == 0) {
                const auto aimed = aimAt(enemy.x + 108.0f, enemy.y - 105.0f);
                const int oscillation = static_cast<int>(
                    std::sin(static_cast<double>(timer) * kTau / 150.0) *
                    12000.0);
                const double speed = 5.0 +
                    static_cast<double>(local - 0x208) * 0.016;
                spawnProjectileSpread(2, 0, enemy.x + 108.0f,
                                      enemy.y - 105.0f,
                                      normalizeAngle16(static_cast<int>(aimed) +
                                                       oscillation),
                                      0.0f, speed, 6, 9, 24000, 0);
                fired = true;
            }
        }
        break;
    }
    case 0x112: { // FUN_14005b4a0
        const int local = timer % 0x44c;
        if (local == 1) {
            enemy.markerDrawX = 540.0f;
            enemy.markerDrawY = 330.0f;
            enemy.sourceSpeed = 10.0;
        }
        else if (local == 0x28) {
            enemy.markerDrawX = 120.0f;
            enemy.markerDrawY = 240.0f;
            enemy.sourceSpeed = 20.0;
        }
        else if (local == 0x6e) {
            enemy.markerDrawX = 500.0f;
            enemy.markerDrawY = 190.0f;
        }
        else if (local == 0xb4) {
            enemy.markerDrawX = 150.0f;
            enemy.markerDrawY = 160.0f;
        }
        else if (local == 0xfa) {
            enemy.markerDrawX = 380.0f;
            enemy.markerDrawY = 60.0f;
        }
        else if (local >= 0x168 && local < 0x258 && local % 20 == 0) {
            enemy.markerDrawX = 160.0f + static_cast<float>(
                lateBossFrameRand(frame_ + enemy.entityId) % 361u);
            enemy.markerDrawY = 80.0f + static_cast<float>(
                lateBossFrameRand(frame_ + 0x15b3) % 221u);
            enemy.sourceSpeed = 5.0;
        }
        moveByDivisor(enemy.markerDrawX, enemy.markerDrawY,
                      std::max(5.0, enemy.sourceSpeed));

        if (local >= 0x28 && local < 0x140) {
            const int segment = (local - 0x28) % 0x46;
            if (segment <= 0x23 && (segment & 1) == 0) {
                spawnProjectileSpread(0x0d, 4, enemy.x, enemy.y,
                                      aimAt(enemy.x, enemy.y), 0.0f,
                                      5.0 + segment * 0.3, 7, 5, 0x3000, 0);
                fired = true;
            }
            if (local >= 0x5a && (local - 0x5a) % 0x46 == 0) {
                const auto base = normalizeAngle16(static_cast<int>(
                    lateBossFrameRand(frame_ + timer)));
                spawnProjectileSpread(10, 0, enemy.x, enemy.y, base,
                                      0.0f, 3.0, 6, 25, 0x10000, 0);
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      aimAt(enemy.x, enemy.y), 0.0f,
                                      4.5, 6, 25, 0x10000, 0);
                fired = true;
            }
        }
        if (local >= 0x168 && local < 0x258 && local % 20 == 0) {
            spawnProjectileSpread(0x0d, 1, enemy.x, enemy.y,
                                  aimAt(enemy.x, enemy.y), 0.0f,
                                  5.0 + (local - 0x168) * 0.005,
                                  7, 14, 0x2400, 0);
            fired = true;
        }
        if (local >= 0x280 && local < 0x424 && (local & 1) == 0) {
            spawnProjectileNode(0x0d, 3, enemy.x, enemy.y,
                                normalizeAngle16(timer * 0x960), 0.0f,
                                3.6 + (local - 0x280) * 0.005, 6, 0);
            fired = true;
        }
        break;
    }
    case 0x113: { // FUN_14005cc30
        if (timer == 1) {
            constexpr std::array<float, 4> kOffsetX{{
                100.0f, -100.0f, 210.0f, -210.0f,
            }};
            constexpr std::array<float, 4> kOffsetY{{
                -120.0f, -120.0f, -70.0f, -70.0f,
            }};
            for (std::size_t i = 0; i < kOffsetX.size(); ++i) {
                spawnAuxNode(0x114, enemy.entityId, enemy.spawnType,
                             static_cast<int>(i), enemy.x, enemy.y,
                             kOffsetX[i], kOffsetY[i], 99999999, 40);
            }
        }
        if (timer % 50 == 0) {
            enemy.markerDrawX = 240.0f + static_cast<float>(
                lateBossFrameRand(frame_ + enemy.entityId) % 241u);
            enemy.markerDrawY = 150.0f + static_cast<float>(
                lateBossFrameRand(frame_ + 0xd05) % 101u);
        }
        const double speed = timer < 180
                                 ? 0.5 + 3.5 * std::sin(
                                       static_cast<double>(timer) * kPi / 360.0)
                                 : 4.0;
        steerAndMove(enemy.markerDrawX, enemy.markerDrawY, 0x300, speed);
        if (timer >= 40) {
            const int local = (timer - 40) % 0x4b0;
            const int burst = local % 0x50;
            if (burst < 40 && burst % 5 == 0) {
                const auto aimed = aimAt(enemy.x, enemy.y + 20.0f);
                spawnProjectileNode(7, 1, enemy.x + 20.0f,
                                    enemy.y + 20.0f, aimed, 10.0f,
                                    8.0 + difficulty * 0.35, 6, 0);
                spawnProjectileNode(7, 1, enemy.x - 20.0f,
                                    enemy.y + 20.0f, aimed, 10.0f,
                                    8.0 + difficulty * 0.35, 6, 0);
                fired = true;
            }
        }
        break;
    }
    case 0x115: { // FUN_14005e4e0 plus its 0x116..0x119 launchers
        int scheduledTimer = 20;
        for (int i = 0; i < 30; ++i) {
            if (timer == scheduledTimer) {
                const int selector = i & 3;
                const int type = selector == 0 ? 0x118
                                 : (selector == 1 ? 0x119
                                    : (selector == 2 ? 0x116 : 0x117));
                float spawnX = 170.0f;
                if (i % 3 == 0) {
                    spawnX = 260.0f + static_cast<float>(
                        lateBossFrameRand(timer + i * 0x457) % 201u);
                }
                else if (i % 3 == 2) {
                    spawnX = 550.0f;
                }
                spawnAuxNode(type, enemy.entityId, enemy.spawnType,
                             i + 2, spawnX, -150.0f,
                             spawnX, -150.0f, 10000, 120);
            }
            if (i % 3 != 1) {
                scheduledTimer += 0x104;
            }
        }
        break;
    }
    case 0x11a: { // FUN_14005fc20
        if (enemy.helperState == 1 || enemy.helperState == 3) {
            if (timer % 90 == 0) {
                enemy.markerDrawX = 210.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + enemy.entityId) % 301u);
                enemy.markerDrawY = 200.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + 0x15b3) % 101u);
            }
            moveByDivisor(enemy.markerDrawX, enemy.markerDrawY,
                          std::max(10.0, enemy.sourceSpeed));
            if (timer >= 30 && timer < 360 && (timer - 30) % 30 == 0) {
                spawnProjectileSpread(3, 0, enemy.x, enemy.y - 100.0f,
                                      aimAt(enemy.x, enemy.y - 100.0f),
                                      0.0f, 8.0, 6, 5, 0x2bf0, 0);
                fired = true;
            }
            const int ringCadence = enemy.helperState == 3 ? 13 : 27;
            if (timer >= 30 && timer < 360 &&
                (timer - 30) % ringCadence == 0) {
                spawnProjectileSpread(4, 0, enemy.x, enemy.y - 100.0f,
                                      normalizeAngle16(timer * 0x3c),
                                      0.0f, 6.8, 6, 29, 0x10000, 0);
                fired = true;
            }
            if (timer >= 360) {
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 30.0;
            }
        }
        else if (enemy.helperState == 2) {
            const float phase = static_cast<float>(
                std::sin(timer * kTau / 220.0) * 180.0);
            enemy.markerDrawX = 360.0f + phase;
            enemy.markerDrawY -= 0.1f;
            moveByDivisor(enemy.markerDrawX, enemy.markerDrawY, 30.0);
            if (timer >= 60 && timer < 620 && (timer - 60) % 72 == 0) {
                const auto rotation = normalizeAngle16(static_cast<int>(
                    lateBossFrameRand(frame_ + timer)));
                spawnProjectileSpread(2, 0, enemy.x, enemy.y - 100.0f,
                                      rotation, 0.0f, 11.1, 6, 27,
                                      0x10000, 0);
                for (int layer = 0; layer < 3; ++layer) {
                    spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                          normalizeAngle16(rotation +
                                                           0x7d0 * layer),
                                          0.0f, 5.0 + layer * 2.0,
                                          6, 11, 0x10000, 0);
                }
                fired = true;
            }
            if (timer >= 640) {
                enemy.helperState = 3;
                enemy.helperTimer = 19;
                enemy.sourceSpeed = 70.0;
            }
        }
        break;
    }
    case 0x11d: { // FUN_140062060 plus its 0x11e..0x122 batteries
        if (enemy.helperState == 1) {
            if (timer == 1) {
                enemy.markerDrawX = 320.0f;
                enemy.markerDrawY = 220.0f;
            }
            else if (timer > 210 && timer < 420 && timer % 30 == 0) {
                enemy.markerDrawX = 260.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + enemy.entityId) % 201u);
                enemy.markerDrawY = 180.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + 0xd05) % 141u);
            }
            moveByDivisor(enemy.markerDrawX, enemy.markerDrawY, 20.0);
            if (timer >= 450) {
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 0.7;
            }
        }
        else if (enemy.helperState == 2) {
            if (timer % 50 == 0) {
                enemy.markerDrawX = 210.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + enemy.entityId) % 301u);
                enemy.markerDrawY = 220.0f + static_cast<float>(
                    lateBossFrameRand(frame_ + 0x457) % 101u);
            }
            steerAndMove(enemy.markerDrawX, enemy.markerDrawY, 0x200, 0.7);
            if (timer >= 800) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 20.0;
            }
        }

        break;
    }
    default:
        break;
    }

    if (fired) {
        playPlayerSound((enemy.spawnType == 0x115 ||
                         enemy.spawnType == 0x11d)
                            ? bullet2SoundHandle_
                            : bullet1SoundHandle_,
                        0x13);
    }
}

void StageRuntime::updateLateStageEnemy(StageEnemy& enemy, int activeAge) {
    (void)activeAge;
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = false;
    enemy.drawMarkerThisFrame = false;

    if (enemy.parentSpawnType == 0x13c &&
        enemy.spawnType >= 0x54 && enemy.spawnType <= 0x56) {
        updateStage05BossChild(enemy);
        return;
    }

    const auto aimAtPlayer16 = [this, &enemy]() {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
    };
    const auto setVelocity = [&enemy](double speed) {
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.angle = static_cast<float>(radians);
        enemy.sourceSpeed = speed;
        enemy.speed = static_cast<float>(speed);
        enemy.vx = static_cast<float>(std::cos(radians) * speed);
        enemy.vy = static_cast<float>(std::sin(radians) * speed);
    };
    const auto beginExactDeath = [this, &enemy]() {
        spawnEnemyDeathRewardBurst(
            enemy, lateEnemyDeathRewardWindow(enemy.spawnType, enemy.rewardWeight));
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemy.helperState = 2;
        enemy.helperTimer = 0;
    };
    const auto updateExactDeath = [this, &enemy](float acceleration) {
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        enemy.targetable = false;
        enemy.vy = static_cast<float>(enemy.helperTimer) * acceleration;
        if (enemy.helperTimer < 60 && enemy.helperTimer % 3 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (enemy.helperTimer >= 60) {
            spawnEnemyDeathEffects(
                enemy, lateEnemyDeathEffectMode(enemy.spawnType, enemy.radius));
            if (isLateStageGateOwner(enemy)) {
                clearLateStageGate(selectedStage_);
            }
            enemy.active = false;
        }
    };

    const auto spawnInternalChild = [this](StageEnemy& parent, int spawnType,
                                            int hitPoints, int kind, float x,
                                            float y, std::uint16_t angle16,
                                            double speed, int radius,
                                            bool targetable,
                                            const char* note) {
        const LateSpawnSpec* childSpec = lateSpawnSpec(spawnType);
        if (childSpec == nullptr ||
            enemies_.size() + pendingEnemies_.size() >= kLateStageEntityCap) {
            return false;
        }

        StageEnemy child;
        child.entityId = nextEntityId_++;
        child.spawnType = spawnType;
        child.updateCase = childSpec->updateCase;
        child.sourceHitPoints = hitPoints;
        child.sourceX = static_cast<int>(std::lround(x));
        child.sourceY = static_cast<int>(std::lround(y));
        child.sourceNote = note;
        child.sourceDispatchKind = kind;
        child.sourceDispatchField = radius;
        child.rewardWeight = kind;
        child.parentEntityId = parent.entityId;
        child.parentSpawnType = parent.spawnType;
        child.childIndex = parent.liveChildCount;
        child.x = x;
        child.y = y;
        child.originX = x;
        child.originY = y;
        child.markerDrawX = x;
        child.markerDrawY = y;
        child.sourceAngle16 = angle16;
        child.secondaryAngle16 = angle16;
        child.targetAngle16 = angle16;
        child.angle = static_cast<float>(fixedAngleRadians(angle16));
        child.sourceSpeed = speed;
        child.speed = static_cast<float>(speed);
        const double hpScale = config_.difficulty == 0 ? 0.8 : 1.0;
        child.hp = std::max(1, static_cast<int>(hitPoints * hpScale));
        child.maxHp = child.hp;
        child.drawHp = child.hp;
        child.radius = radius;
        child.activationDelay = 0;
        child.targetable = targetable;
        pendingEnemies_.push_back(child);
        ++parent.liveChildCount;
        return true;
    };
    const auto releaseFromParent = [this](StageEnemy& child) {
        StageEnemy* parent = findEnemyById(child.parentEntityId);
        if (parent != nullptr && parent->liveChildCount > 0) {
            --parent->liveChildCount;
        }
        child.active = false;
    };
    const auto finishImmediateDeath = [this, &releaseFromParent](
                                          StageEnemy& target,
                                          bool releaseParent) {
        spawnEnemyDeathRewardBurst(
            target, lateEnemyDeathRewardWindow(target.spawnType,
                                               target.rewardWeight));
        spawnEnemyDeathEffects(
            target, lateEnemyDeathEffectMode(target.spawnType, target.radius));
        target.targetable = false;
        if (releaseParent) {
            releaseFromParent(target);
        }
        else {
            target.active = false;
        }
    };
    const auto outsideBounds = [](const StageEnemy& target, float left,
                                  float right, float top, float bottom) {
        return target.x < left || target.x > right ||
               target.y < top || target.y > bottom;
    };

    if (enemy.spawnType == 0x44) { // FUN_140096890
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y - 20.0f;
            if (enemy.helperTimer >= 20) {
                const int randomAngle = static_cast<int>(
                    lateStageScriptRand(frame_ + enemy.entityId) % 3001u);
                if (enemy.y <= 0.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(0x3a24 + randomAngle);
                }
                if (enemy.x <= 0.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(-0x5dc + randomAngle);
                }
                if (enemy.x >= 720.0f) {
                    enemy.sourceAngle16 = normalizeAngle16(0x7a24 + randomAngle);
                }
                enemy.y -= 20.0f;
                enemy.sourceSpeed = selectedStage_ >= 9 ? 6.0 : 3.0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }

        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            const float dx = player_.x - enemy.x;
            const float dy = player_.y - enemy.y;
            const bool emitsDeathShot = dx * dx + dy * dy >= 50.0f * 50.0f &&
                                        (config_.difficulty != 0 ||
                                         (enemy.entityId & 1) == 0);
            if (emitsDeathShot) {
                const int difficulty = std::clamp(config_.difficulty, 0, 4);
                const double speed = lateEnemyProjectileSpeed(
                    difficulty,
                    std::array<double, 5>{{5.5, 6.5, 7.0, 6.5, 7.5}});
                const auto fire = [this, &enemy](std::uint16_t angle,
                                                 double shotSpeed) {
                    spawnProjectileNode(9, 2, enemy.x, enemy.y, angle,
                                        0.0f, shotSpeed, 1, 0);
                };
                fire(enemy.sourceAngle16, speed);
                if (difficulty > 2) {
                    fire(enemy.sourceAngle16, speed + 2.0);
                }
                if (difficulty > 3) {
                    for (const int offset : {-0xd05, 0xd05}) {
                        const auto angle = normalizeAngle16(
                            static_cast<int>(enemy.sourceAngle16) + offset);
                        fire(angle, speed);
                        fire(angle, speed + 2.0);
                    }
                }
            }
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -180.0f, 780.0f, -180.0f, 900.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer < 200) {
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimAtPlayer16(), 0xff);
        }
        enemy.sourceSpeed += 0.1;
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x45) { // FUN_140097270
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y - 20.0f;
            if (enemy.helperTimer >= 20) {
                enemy.sourceSpeed = 6.0 + static_cast<double>(
                    lateStageScriptRand(frame_ + enemy.entityId) % 3u);
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
                enemy.y -= 20.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -180.0f, 780.0f, -180.0f, 900.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer < 150) {
            if (enemy.sourceSpeed > 2.0) enemy.sourceSpeed -= 0.1;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimAtPlayer16(), 0x80);
        }
        else {
            enemy.sourceSpeed += 0.1;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, 0xc000, 0x100);
        }
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x46) { // FUN_140097d30
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y - 50.0f;
            if (enemy.helperTimer >= 20) {
                enemy.sourceSpeed = 12.0;
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 2000;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x7830;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (enemy.helperTimer > 120 &&
            outsideBounds(enemy, -128.0f, 848.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer < 100) {
            if (enemy.sourceSpeed > 0.0) enemy.sourceSpeed -= 0.12;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimAtPlayer16(), 0x20);
        }
        else if (enemy.helperTimer < 240) {
            if (enemy.helperTimer < 130) enemy.sourceSpeed += 0.05;
            enemy.sourceAngle16 = approachAngle16(
                enemy.sourceAngle16, aimAtPlayer16(), 0x80);
        }
        else {
            enemy.sourceSpeed -= 0.1;
        }
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x47 || enemy.spawnType == 0x48) {
        // FUN_140098700 materializes the root for 90 ticks, then leaves a
        // rotating 0x49 ring around its live position.
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (enemy.helperTimer == 0) {
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (enemy.helperTimer == 60) {
                const int difficulty = std::clamp(config_.difficulty, 0, 4);
                const int childCount = std::array<int, 5>{{5, 7, 9, 9, 8}}[
                    static_cast<std::size_t>(difficulty)];
                for (int i = 0; i < childCount; ++i) {
                    const auto angle = normalizeAngle16(
                        i * (0x10000 / childCount) - 0x4000);
                    spawnInternalChild(
                        enemy, 0x49, 0x4b0, 5, 180.0f, 0.0f, angle,
                        0.0, 35, false,
                        "S05 FUN_140098700 timer 60 type 0x49 ring node");
                }
            }
            const int timer = std::clamp(enemy.helperTimer, 0, 90);
            const float radius = 90.0f * static_cast<float>(
                1.0 - std::sin(static_cast<double>(timer) * kPi / 180.0));
            const double entranceAngle =
                static_cast<double>(enemy.entityId % 16) * kTau / 16.0;
            enemy.x = enemy.originX +
                      static_cast<float>(std::cos(entranceAngle) * radius);
            enemy.y = enemy.originY +
                      static_cast<float>(std::sin(entranceAngle) * radius);
            if (enemy.helperTimer >= 90) {
                enemy.x = enemy.originX;
                enemy.y = enemy.originY;
                enemy.sourceSpeed = 0.5;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -180.0f, 780.0f, -180.0f, 900.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer <= 120 && enemy.sourceSpeed > 0.2) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimAtPlayer16(), 0x80);
        if (enemy.helperTimer > 299) enemy.sourceSpeed -= 0.1;
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x49) { // FUN_140098f40
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || !parent->active || parent->hp < 1 ||
            (parent->spawnType != 0x47 && parent->spawnType != 0x48)) {
            spawnEnemyDeathEffects(enemy, 0);
            releaseFromParent(enemy);
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, true);
            return;
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        float radius = 180.0f;
        if (enemy.helperState == 0) {
            radius = 180.0f * static_cast<float>(std::sin(
                static_cast<double>(std::clamp(enemy.helperTimer, 0, 30)) *
                kPi / 60.0));
        }
        const float targetX = parent->x +
                              static_cast<float>(std::cos(radians) * radius);
        const float targetY = parent->y +
                              static_cast<float>(std::sin(radians) * radius);
        if (enemy.helperTimer == 0 && enemy.helperState == 0) {
            enemy.x = parent->x;
            enemy.y = parent->y;
        }
        enemy.x += (targetX - enemy.x) / 20.0f;
        enemy.y += (targetY - enemy.y) / 20.0f;
        const int turn = parent->spawnType == 0x47 ? 0x1bc : -0x1bc;
        enemy.sourceAngle16 = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) + turn);
        if (enemy.helperState == 0 && enemy.helperTimer >= 30) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        return;
    }

    if (enemy.spawnType == 0x4a) { // FUN_140099570
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y - 50.0f;
            if (enemy.helperTimer == 0) {
                constexpr std::array<float, 4> kX{{190.0f, -190.0f,
                                                   90.0f, -90.0f}};
                constexpr std::array<float, 4> kY{{-20.0f, -20.0f,
                                                   -80.0f, -80.0f}};
                constexpr std::array<int, 4> kAngle{{-1000, 1000,
                                                     -3000, 3000}};
                for (std::size_t i = 0; i < kX.size(); ++i) {
                    spawnInternalChild(
                        enemy, 0x4b, 99999999, 1, kX[i], kY[i],
                        normalizeAngle16(kAngle[i]), 0.0, 20, false,
                        "S05 FUN_140099570 timer 0 type 0x4b anchor");
                }
            }
            if (enemy.helperTimer >= 20) {
                enemy.sourceSpeed = 7.0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, false);
            return;
        }
        if (outsideBounds(enemy, -128.0f, 848.0f, -128.0f, 848.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer <= 120 && enemy.sourceSpeed > 0.8) {
            enemy.sourceSpeed -= 0.1;
        }
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimAtPlayer16(), 0x80);
        if (enemy.helperTimer > 289) enemy.sourceSpeed -= 0.1;
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x4b) { // FUN_14008bd60 Stage 5 branch
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4a ||
            !parent->active || parent->hp < 1) {
            releaseFromParent(enemy);
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.targetable = false;
        const float targetX = parent->x + enemy.originX;
        const float targetY = parent->y + enemy.originY;
        if (enemy.helperTimer == 0) {
            enemy.x = parent->x;
            enemy.y = parent->y;
        }
        enemy.x += (targetX - enemy.x) * 0.05f;
        enemy.y += (targetY - enemy.y) * 0.05f;

        const int difficulty = std::clamp(config_.difficulty, 0, 4);
        const int interval = std::array<int, 5>{{60, 40, 34, 30, 25}}[
            static_cast<std::size_t>(difficulty)];
        const int start = (enemy.entityId - parent->entityId) * interval + 44;
        if (enemy.helperTimer >= start && parent->helperState == 1 &&
            parent->helperTimer < 290 &&
            (enemy.helperTimer - start) % (interval * 5) == 0 &&
            enemy.x >= 0.0f && enemy.x <= 720.0f &&
            enemy.y >= 0.0f && enemy.y <= 780.0f) {
            const auto angle = radiansToAngle16(std::atan2(
                static_cast<double>(player_.y - (enemy.y + 20.0f)),
                static_cast<double>(player_.x - enemy.x)));
            spawnInternalChild(
                *parent, 0x4c, 400, 4, enemy.x, enemy.y, angle,
                3.6, 80, false,
                "S05 FUN_14008bd60 staggered type 0x4c projectile enemy");
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.spawnType == 0x4c) { // FUN_140099e50
        if (enemy.helperState == 2) {
            enemy.drawBodyThisFrame = false;
            enemy.targetable = false;
            StageEnemy* parent = findEnemyById(enemy.parentEntityId);
            if (parent == nullptr || !parent->active ||
                parent->spawnType != 0x4a) {
                releaseFromParent(enemy);
                return;
            }
            const int chunk = std::max(1, enemy.maxHp / 30);
            const int damage = std::min(enemy.hp, chunk);
            enemy.hp -= damage;
            parent->hp -= damage;
            if (enemy.hp < 1 || enemy.helperTimer >= 29) {
                releaseFromParent(enemy);
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        // FUN_140099e50 advances along the constructor angle before both its
        // 20-tick materialization branch and its lethal branch.
        setVelocity(enemy.sourceSpeed);
        if (enemy.helperState == 0 && enemy.helperTimer >= 20) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.radius = config_.difficulty < 2 ? 80 : 100;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        if (enemy.hp < 1) {
            const float distance = std::sqrt(
                (player_.x - enemy.x) * (player_.x - enemy.x) +
                (player_.y - enemy.y) * (player_.y - enemy.y));
            if (distance >= static_cast<float>(enemy.radius + 30) &&
                enemy.y < 360.0f && enemy.y < player_.y) {
                const int difficulty = std::clamp(config_.difficulty, 0, 4);
                const int count = difficulty < 2 ? 15 : 19;
                const double speed = lateEnemyProjectileSpeed(
                    difficulty,
                    std::array<double, 5>{{4.5, 5.5, 6.5, 5.5, 7.0}});
                const float ringRadius = static_cast<float>(enemy.radius - 15);
                for (int i = 0; i < count; ++i) {
                    const double ringAngle = static_cast<double>(i) * kTau /
                                             static_cast<double>(count);
                    const float sourceX = enemy.x +
                        static_cast<float>(std::cos(ringAngle) * ringRadius);
                    const float sourceY = enemy.y +
                        static_cast<float>(std::sin(ringAngle) * ringRadius);
                    const auto angle = radiansToAngle16(std::atan2(
                        static_cast<double>(player_.y - sourceY),
                        static_cast<double>(player_.x - sourceX)));
                    spawnProjectileNode(13, 2, sourceX, sourceY, angle,
                                        0.0f, speed, 1, 0);
                    if (difficulty > 2) {
                        spawnProjectileNode(13, 2, sourceX, sourceY, angle,
                                            0.0f, speed + 2.0, 1, 0);
                    }
                }
            }
            spawnEnemyDeathRewardBurst(enemy, 300);
            spawnEnemyDeathEffects(enemy, 0);
            enemy.targetable = false;
            enemy.helperState = 2;
            enemy.helperTimer = 0;
            // FUN_140099e50 unlinks 0x4c and creates a type 0x153 node that
            // drains its max HP from the 0x4a owner over 30 updates. Reusing the
            // invisible death state preserves that observable contract locally.
            enemy.hp = enemy.maxHp;
            return;
        }
        if (outsideBounds(enemy, -128.0f, 848.0f, -128.0f, 848.0f)) {
            releaseFromParent(enemy);
            return;
        }
        return;
    }

    if (enemy.spawnType == 0x4d) { // FUN_14009a4a0
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (enemy.helperTimer == 0) {
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            if (enemy.helperTimer >= 20) {
                if (enemy.x <= 0.0f) enemy.sourceAngle16 = 0;
                if (enemy.x >= 720.0f) enemy.sourceAngle16 = 0x8000;
                enemy.y -= 150.0f;
                constexpr std::array<float, 3> kX{{16.0f, 79.0f, -61.0f}};
                constexpr std::array<float, 3> kY{{99.0f, 70.0f, 67.0f}};
                for (std::size_t i = 0; i < kX.size(); ++i) {
                    spawnInternalChild(
                        enemy, 0x4e, 0xa8c, 8, kX[i], kY[i], 0xc000,
                        0.0, 30, false,
                        "S05 FUN_14009a4a0 timer 20 type 0x4e satellite");
                }
                enemy.sourceSpeed = 9.0;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 2) {
            updateExactDeath(0.15f);
            return;
        }
        if (enemy.hp < 1) {
            beginExactDeath();
            return;
        }
        if (outsideBounds(enemy, -240.0f, 960.0f, -240.0f, 960.0f)) {
            enemy.active = false;
            return;
        }
        if (enemy.helperTimer <= 90 && enemy.sourceSpeed > 0.5) {
            enemy.sourceSpeed -= 0.1;
        }
        const int turnStep = enemy.helperTimer < 90
                                 ? std::max(1, enemy.helperTimer * 4)
                                 : 0x40;
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimAtPlayer16(), turnStep);
        if (enemy.helperTimer > 359) enemy.sourceSpeed -= 0.1;
        setVelocity(enemy.sourceSpeed);
        return;
    }

    if (enemy.spawnType == 0x4e) { // FUN_14009b0a0
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4d ||
            !parent->active || parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            releaseFromParent(enemy);
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            finishImmediateDeath(enemy, true);
            return;
        }
        const float mountX = parent->x + enemy.originX;
        const float mountY = parent->y + enemy.originY;
        const auto aimed = radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - mountY),
            static_cast<double>(player_.x - mountX)));
        int delta = static_cast<int>(aimed) -
                    static_cast<int>(enemy.sourceAngle16);
        if (delta > 0x8000) delta -= 0x10000;
        if (delta < -0x8000) delta += 0x10000;
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimed, std::abs(delta) / 10 + 0x30);
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x = mountX + static_cast<float>(std::cos(radians) * 40.0);
        enemy.y = mountY + static_cast<float>(std::sin(radians) * 40.0);
        enemy.targetable = true;
        return;
    }

    if (enemy.spawnType >= 0x50 && enemy.spawnType <= 0x52) {
        // FUN_14009c530: the 0x50 root and its 0x51/0x52 decorations follow
        // their immediate owner through a 100-tick materialization curve.
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        const int expectedParent = enemy.spawnType == 0x50 ? 0x4f : 0x50;
        if (parent == nullptr || parent->spawnType != expectedParent ||
            !parent->active) {
            releaseFromParent(enemy);
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        enemy.targetable = false;
        if (enemy.spawnType == 0x50 && enemy.helperTimer == 0) {
            spawnInternalChild(
                enemy, 0x51, 99999999, 0, 60.0f, 120.0f, 0x4000,
                1.0, 100, false,
                "S05 FUN_14009c530 type 0x50 left 0x51 part");
            spawnInternalChild(
                enemy, 0x51, 99999999, 0, -60.0f, 120.0f, 0x4000,
                1.0, 100, false,
                "S05 FUN_14009c530 type 0x50 right 0x51 part");
            spawnInternalChild(
                enemy, 0x52, 99999999, 0, 70.0f, -50.0f, 0x4000,
                1.0, 100, false,
                "S05 FUN_14009c530 type 0x50 left 0x52 part");
            spawnInternalChild(
                enemy, 0x52, 99999999, 0, -70.0f, -50.0f, 0x4000,
                1.0, 100, false,
                "S05 FUN_14009c530 type 0x50 right 0x52 part");
        }
        const double materialize = enemy.helperState == 0
                                       ? smoothStep(static_cast<double>(
                                             std::clamp(enemy.helperTimer, 0, 100)) /
                                             100.0)
                                       : 1.0;
        const float targetX = parent->x +
                              static_cast<float>(enemy.originX * materialize);
        const float targetY = parent->y +
                              static_cast<float>(enemy.originY * materialize);
        if (enemy.helperTimer == 0 && enemy.helperState == 0) {
            enemy.x = parent->x;
            enemy.y = parent->y;
        }
        enemy.x += (targetX - enemy.x) / 5.0f;
        enemy.y += (targetY - enemy.y) / 5.0f;
        if (enemy.helperState == 0 && enemy.helperTimer >= 100) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.spawnType == 0x50 && parent->helperState == 2 &&
            parent->helperTimer >= 60) {
            releaseFromParent(enemy);
        }
        return;
    }

    if (enemy.spawnType == 0x53) { // FUN_14009cd10
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4f ||
            !parent->active || parent->hp < 1) {
            spawnEnemyDeathEffects(enemy, 1);
            releaseFromParent(enemy);
            return;
        }
        enemy.drawBodyThisFrame = true;
        const float targetX = parent->x + enemy.originX;
        const float targetY = parent->y + enemy.originY;
        if (enemy.helperTimer == 0 && enemy.helperState == 0) {
            enemy.x = targetX;
            enemy.y = targetY;
        }
        enemy.x += (targetX - enemy.x) / 40.0f;
        enemy.y += (targetY - enemy.y) / 40.0f;
        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (enemy.helperTimer >= 30) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.hp = parent->hp;
                enemy.maxHp = parent->maxHp;
                enemy.drawHp = parent->drawHp;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        if (enemy.hp < parent->hp) {
            parent->hp = enemy.hp;
        }
        else if (parent->hp < enemy.hp) {
            enemy.hp = parent->hp;
        }
        enemy.drawHp = parent->drawHp;
        enemy.targetable = true;
        return;
    }

    if (enemy.spawnType == 0x4f) {
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            if (enemy.helperTimer == 0) {
                spawnInternalChild(
                    enemy, 0x50, 99999999, 0, 0.0f, 210.0f,
                    0x4000, 1.0, 100, false,
                    "S05 FUN_14009b5f0 timer 0 type 0x50 structure root");
                playPlayerSound(bullet2SoundHandle_, 0x19);
            }
            const double entrance = std::sin(
                static_cast<double>(std::clamp(enemy.helperTimer, 0, 100)) *
                kPi / 200.0);
            enemy.y = 580.0f + static_cast<float>(
                entrance * static_cast<double>(enemy.originY - 580.0f));
            enemy.targetable = false;
            if (enemy.helperTimer >= 100) {
                enemy.y = enemy.originY;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.sourceSpeed = 0.4;
                enemy.speed = 0.4f;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
                enemy.markerDrawX = 360.0f;
                enemy.markerDrawY = 200.0f;
            }
            return;
        }
        if (enemy.helperState == 1) {
            if (enemy.hp < 1) {
                beginExactDeath();
                return;
            }
            switch (enemy.helperTimer) {
            case 220:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, 220.0f, -40.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 220 type 0x53 battery");
                break;
            case 230:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, -220.0f, -40.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 230 type 0x53 battery");
                break;
            case 240:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, 120.0f, -120.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 240 type 0x53 battery");
                break;
            case 250:
                spawnInternalChild(
                    enemy, 0x53, 99999999, 1, -120.0f, -120.0f,
                    0x4000, 1.0, 40, false,
                    "S05 FUN_14009b5f0 timer 250 type 0x53 battery");
                break;
            default:
                break;
            }
            if (enemy.helperTimer < 1200) {
                if (frame_ % 50 == 0 || enemy.helperTimer == 1) {
                    const auto randomX = lateStageScriptRand(
                        frame_ + enemy.entityId * 0x15b3);
                    const auto randomY = lateStageScriptRand(
                        frame_ + enemy.entityId * 0x15b3 + 1);
                    enemy.markerDrawX = 210.0f + static_cast<float>(randomX % 301u);
                    enemy.markerDrawY = 150.0f + static_cast<float>(randomY % 101u);
                }
                const auto targetAngle = radiansToAngle16(std::atan2(
                    static_cast<double>(enemy.markerDrawY - enemy.y),
                    static_cast<double>(enemy.markerDrawX - enemy.x)));
                enemy.sourceAngle16 = approachAngle16(
                    enemy.sourceAngle16, targetAngle, 0x200);
                setVelocity(0.4);
            }
            else {
                enemy.vy = -static_cast<float>(enemy.helperTimer - 1200) * 0.1f;
            }
            return;
        }
        updateExactDeath(0.15f);
        return;
    }

    if (enemy.spawnType == 0x5f) {
        enemy.y += 1.0f;
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0 && enemy.y >= -100.0f) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        if (enemy.helperState == 1) {
            if (enemy.helperTimer >= 80) {
                enemy.targetable = true;
            }
            if (enemy.hp < 1) {
                beginExactDeath();
            }
            if (enemy.y >= 960.0f) {
                enemy.active = false;
            }
            return;
        }
        if (enemy.helperState == 2) {
            updateExactDeath(0.0f);
        }
        return;
    }

    if (enemy.spawnType == 0x77) {
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y;
            if (enemy.helperTimer >= 20) {
                enemy.y -= 20.0f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        if (enemy.helperState == 1) {
            if (enemy.hp < 1) {
                beginExactDeath();
                return;
            }
            const int timer = enemy.helperTimer;
            enemy.originY += 0.25f;
            if (timer <= 150) {
                enemy.y = enemy.originY - 900.0f * static_cast<float>(
                    std::sin(static_cast<double>(timer) * kPi / 300.0));
            }
            else if (timer < 1020) {
                enemy.y = enemy.originY - 900.0f;
            }
            else if (timer < 1200) {
                enemy.y = enemy.originY - 900.0f * static_cast<float>(
                    std::sin(static_cast<double>(timer - 840) * kPi / 360.0));
            }
            else {
                enemy.y = enemy.originY +
                          static_cast<float>(timer - 1200) * 0.05f;
            }
            enemy.x = enemy.originX;
            return;
        }
        updateExactDeath(0.1f);
        return;
    }

    if (enemy.hp < 1) {
        spawnEnemyDeathRewardBurst(
            enemy, lateEnemyDeathRewardWindow(enemy.spawnType, enemy.rewardWeight));
        spawnEnemyDeathEffects(
            enemy, lateEnemyDeathEffectMode(enemy.spawnType, enemy.radius));
        if (isLateStageGateOwner(enemy)) {
            clearLateStageGate(selectedStage_);
        }
        enemy.targetable = false;
        enemy.active = false;
        return;
    }

    if (enemy.spawnType == 0x5a || enemy.spawnType == 0x5d ||
        enemy.spawnType == 0x5e) {
        enemy.originY += 1.0f;
        const float activationY = enemy.spawnType == 0x5e ? -140.0f : -100.0f;
        if (enemy.helperState == 0 && enemy.originY >= activationY) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
        }
        enemy.drawBodyThisFrame = enemy.helperState == 1;
        enemy.drawHp = enemy.hp;
        if (enemy.helperState == 0) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
            return;
        }
        const double timer = static_cast<double>(enemy.helperTimer);
        if (enemy.spawnType == 0x5a) {
            enemy.x = enemy.originX + static_cast<float>(
                2.0 * std::sin((timer - enemy.entityId * 7.0) * kTau / 53.0));
            enemy.y = enemy.originY + static_cast<float>(
                2.0 * std::sin((timer - enemy.entityId * 11.0) * kTau / 73.0));
            if (enemy.targetable == false && enemy.originY >= 0.0f) {
                enemy.targetable = true;
            }
        }
        else if (enemy.spawnType == 0x5d) {
            enemy.x = enemy.originX;
            enemy.y = enemy.originY;
            if (enemy.helperTimer >= 60) {
                enemy.targetable = true;
            }
        }
        else {
            enemy.x = enemy.originX + static_cast<float>(
                3.0 * std::sin((timer - enemy.entityId * 7.0) * kTau / 83.0));
            enemy.y = enemy.originY + static_cast<float>(
                3.0 * std::sin((timer - enemy.entityId * 11.0) * kTau / 104.0));
            if (enemy.originY >= -40.0f) {
                enemy.targetable = true;
            }
        }
        return;
    }

    if (enemy.spawnType == 0x5b || enemy.spawnType == 0x5c) {
        enemy.y += 1.0f;
        if (enemy.helperState == 0) {
            enemy.drawMarkerThisFrame = true;
            enemy.markerDrawTimer = enemy.helperTimer;
            enemy.markerDrawX = enemy.x;
            enemy.markerDrawY = enemy.y;
            if (enemy.helperTimer >= 20) {
                const bool leftHalf = enemy.originX <= 360.0f;
                if (enemy.spawnType == 0x5b) {
                    enemy.sourceAngle16 = leftHalf ? 0 : 0x8000;
                }
                else {
                    enemy.sourceAngle16 = leftHalf ? 0xe0c0 : 0x9f40;
                }
                enemy.sourceSpeed = 1.5;
                enemy.speed = 1.5f;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
            }
            return;
        }
        enemy.drawBodyThisFrame = true;
        enemy.drawHp = enemy.hp;
        if (enemy.spawnType == 0x5c) {
            const int turn = enemy.originX <= 360.0f ? 0x13 : -0x12;
            enemy.sourceAngle16 = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) + turn);
        }
        setVelocity(1.5);
        if (enemy.x >= -25.0f && enemy.x <= 745.0f &&
            enemy.y >= -50.0f && enemy.y <= 850.0f) {
            enemy.targetable = true;
        }
        if (enemy.x < -180.0f || enemy.x > 900.0f ||
            enemy.y < -100.0f || enemy.y > 820.0f) {
            enemy.active = false;
        }
        return;
    }

    if (enemy.helperState == 0) {
        enemy.drawMarkerThisFrame = true;
        enemy.markerDrawTimer = enemy.helperTimer;
        enemy.markerDrawX = std::clamp(enemy.x, -50.0f, 770.0f);
        enemy.markerDrawY = std::clamp(enemy.y, -50.0f, 770.0f);
        if (enemy.helperTimer >= 20) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            if (enemy.spawnType == 0x45) {
                // FUN_140097270 reselects its active point after the marker.
                enemy.x = 80.0f + static_cast<float>((enemy.entityId * 137) % 560);
                enemy.y = -20.0f;
            }
            if (enemy.x < 0.0f) enemy.sourceAngle16 = 0;
            else if (enemy.x > 720.0f) enemy.sourceAngle16 = 0x8000;
            else if (enemy.y > 720.0f) enemy.sourceAngle16 = 0xc000;
            else if (enemy.y < 0.0f) enemy.sourceAngle16 = 0x4000;
            else enemy.sourceAngle16 = aimAtPlayer16();
            enemy.secondaryAngle16 = enemy.sourceAngle16;
            enemy.originX = enemy.x;
            enemy.originY = enemy.y;
        }
        return;
    }

    const int timer = enemy.helperTimer;
    const int variant = enemy.spawnType & 3;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    switch (enemy.updateCase) {
    case 0x32: { // FUN_140096890: accelerating aimed curve
        if (timer < 200) {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                  aimAtPlayer16(), 0xff);
        }
        const double speed = timer < 120 ? 3.0 + timer * 0.025
                                         : 6.0 + std::max(0, timer - 280) * 0.035;
        setVelocity(speed);
        break;
    }
    case 0x33: { // FUN_140097270: swaying dive, then vertical exit
        const double sway = std::sin(static_cast<double>(timer) * kTau / 150.0);
        enemy.sourceAngle16 = timer < 150
                                  ? approachAngle16(enemy.sourceAngle16,
                                                    aimAtPlayer16(), 0x80)
                                  : approachAngle16(enemy.sourceAngle16, 0x4000, 0x100);
        setVelocity(2.2 + 0.8 * sway + (timer > 300 ? (timer - 300) * 0.02 : 0.0));
        break;
    }
    case 0x34: { // FUN_140097d30: multi-phase tracking lane
        if (timer < 100) {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                  aimAtPlayer16(), 0x20);
            setVelocity(std::max(1.0, 12.0 - timer * 0.08));
        }
        else if (timer < 240) {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                                  aimAtPlayer16(), 0x80);
            setVelocity(4.0 + (timer - 100) * 0.025);
        }
        else {
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0xc000, 0x100);
            setVelocity(std::max(1.0, 7.5 - (timer - 240) * 0.03));
        }
        break;
    }
    case 0x35: { // FUN_140098700: radial entrance family 0x47/0x48
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, aimAtPlayer16(), timer < 150 ? 0x80 : 0x180);
        setVelocity(timer < 120 ? 1.2 : 2.0 + 0.3 * variant);
        enemy.vx += static_cast<float>(std::sin(timer * 0.045 + variant) * 1.4);
        break;
    }
    case 0x37:
    case 0x39:
    case 0x3b: { // Stage 5 anchors and gate controller
        const float targetX = 360.0f + (enemy.spawnType == 0x4d ? -90.0f : 0.0f);
        const float targetY = enemy.spawnType == 0x4f ? 200.0f : 170.0f;
        enemy.vx = (targetX - enemy.x) * 0.025f;
        enemy.vy = (targetY - enemy.y) * 0.025f;
        enemy.angle = static_cast<float>(std::sin(timer * 0.025) * 0.2);
        break;
    }
    case 0x41: // Stage 6 paired diagonal divers
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              aimAtPlayer16(), 0x60);
        setVelocity(2.5 + 0.6 * std::sin(timer * 0.04 + variant));
        enemy.vx += enemy.spawnType == 0x57 ? -0.8f : 0.8f;
        break;
    case 0x42: // Stage 6 oscillating anchor
        enemy.vx = (360.0f - enemy.x) * 0.018f +
                   static_cast<float>(std::sin(timer * 0.035) * 1.8);
        enemy.vy = (210.0f - enemy.y) * 0.018f;
        break;
    case 0x43:
    case 0x44: // Stage 6 light swarm variants
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              aimAtPlayer16(), 0xa0 + variant * 0x20);
        setVelocity(2.4 + variant * 0.35);
        enemy.vx += static_cast<float>(std::sin((timer + variant * 17) * 0.08));
        break;
    case 0x45:
    case 0x46: { // Stage 6 formation nodes
        const float lane = 130.0f + static_cast<float>((enemy.entityId * 97) % 460);
        enemy.vx = (lane - enemy.x) * 0.02f;
        enemy.vy = (190.0f - enemy.y) * 0.02f +
                   static_cast<float>(std::sin(timer * 0.03 + variant) * 0.45);
        break;
    }
    case 0x47: // Stage 6 large formation core
        enemy.vx = (360.0f - enemy.x) * 0.015f;
        enemy.vy = (180.0f - enemy.y) * 0.035f;
        break;
    case 0x4f: { // FUN_1400a2310: dual-anchor/offset mover
        const float phase = static_cast<float>(timer) * 0.025f + variant;
        enemy.vx = (360.0f + std::sin(phase) * 210.0f - enemy.x) * 0.045f;
        enemy.vy = (230.0f + std::cos(phase * 0.7f) * 90.0f - enemy.y) * 0.045f;
        break;
    }
    case 0x50:
        enemy.vx = (360.0f + (enemy.spawnType == 0x71 ? -150.0f : 150.0f) - enemy.x) * 0.03f;
        enemy.vy = (210.0f + std::sin(timer * 0.035) * 80.0f - enemy.y) * 0.03f;
        break;
    case 0x51:
        enemy.vx = static_cast<float>(std::sin(timer * 0.025) * 3.2);
        enemy.vy = (180.0f - enemy.y) * 0.025f;
        break;
    case 0x52:
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              timer < 180 ? aimAtPlayer16() : 0xc000, 0xc0);
        setVelocity(timer < 180 ? 2.6 : 4.0);
        break;
    case 0x53:
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              aimAtPlayer16(), timer < 90 ? 0x40 : 0x180);
        setVelocity(timer < 90 ? 1.6 : 5.5);
        break;
    case 0x54:
        enemy.vx = (360.0f - enemy.x) * 0.02f;
        enemy.vy = (180.0f - enemy.y) * 0.02f;
        break;
    case 0x55: // Stage 7 gate owner
        enemy.vx = (360.0f - enemy.x) * 0.025f;
        enemy.vy = (220.0f - enemy.y) * 0.04f;
        break;
    case 0x62:
    case 0x63:
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              aimAtPlayer16(), 0x100);
        setVelocity(2.8 + 0.4 * std::sin(timer * 0.06));
        break;
    case 0x64: { // 0x97/0x98/0x99 share a helper with distinct lanes
        const int lane = enemy.spawnType - 0x97;
        const float targetX = 180.0f + lane * 180.0f;
        enemy.vx = (targetX - enemy.x) * 0.035f;
        enemy.vy = (180.0f + std::sin((timer + lane * 24) * 0.04) * 70.0f - enemy.y) * 0.035f;
        break;
    }
    case 0x65:
        enemy.vx = (360.0f - enemy.x) * 0.018f;
        enemy.vy = (170.0f - enemy.y) * 0.018f;
        break;
    case 0x66: { // Composite family keeps per-type phase offsets
        const int lane = (enemy.spawnType - 0x9b) & 7;
        const float phase = static_cast<float>(timer + lane * 31) * 0.022f;
        enemy.vx = (360.0f + std::sin(phase) * (90.0f + lane * 12.0f) - enemy.x) * 0.04f;
        enemy.vy = (200.0f + std::cos(phase * 1.3f) * 80.0f - enemy.y) * 0.04f;
        break;
    }
    case 0x67: // 0xa4 gate controller
        enemy.vx = (360.0f - enemy.x) * 0.03f;
        enemy.vy = (180.0f - enemy.y) * 0.03f;
        break;
    case 0x6c: // Direct S09 type 0xad
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16,
                                              aimAtPlayer16(), 0x120);
        setVelocity(3.0 + 0.5 * std::sin(timer * 0.08));
        break;
    case 0x82: { // FUN_1400af090: edge-aware curve
        std::uint16_t exit = enemy.sourceAngle16;
        if (enemy.originX < 0.0f) exit = 0;
        else if (enemy.originX > 720.0f) exit = 0x8000;
        else if (enemy.originY < 0.0f) exit = 0x4000;
        enemy.sourceAngle16 = approachAngle16(
            enemy.sourceAngle16, timer < 150 ? aimAtPlayer16() : exit, 0x100);
        setVelocity(3.0 + (timer > 220 ? (timer - 220) * 0.025 : 0.0));
        break;
    }
    case 0x83:
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, 0x4000, 0x80);
        setVelocity(2.6);
        enemy.vx += static_cast<float>(std::sin((timer + enemy.entityId * 7) * 0.065) * 2.0);
        break;
    case 0x84: // FUN_1400b0120: sway before a downward turn
        enemy.vx = static_cast<float>(std::sin((timer + enemy.entityId * 11) * 0.055) * 3.4);
        enemy.vy = timer < 180 ? 1.8f : 3.2f;
        enemy.sourceAngle16 = radiansToAngle16(std::atan2(enemy.vy, enemy.vx));
        enemy.angle = static_cast<float>(fixedAngleRadians(enemy.sourceAngle16));
        break;
    case 0x85:
        enemy.vx = static_cast<float>(std::sin(timer * 0.035 + variant) * 1.2);
        enemy.vy = timer < 160 ? 2.0f : -2.8f;
        break;
    case 0x86:
        enemy.vx = (360.0f - enemy.x) * 0.025f;
        enemy.vy = (200.0f - enemy.y) * 0.025f;
        break;
    case 0x87:
        enemy.vx = (enemy.originX - enemy.x) * 0.02f;
        enemy.vy = (200.0f - enemy.y) * 0.025f;
        break;
    case 0x88:
        enemy.vx = (enemy.originX - enemy.x) * 0.02f;
        enemy.vy = (170.0f - enemy.y) * 0.03f;
        break;
    case 0x89: {
        const float targetX = enemy.spawnType == 0x103 ? 500.0f : 220.0f;
        enemy.vx = (targetX - enemy.x) * 0.025f;
        enemy.vy = (180.0f - enemy.y) * 0.025f;
        break;
    }
    default:
        // Every configured late type has a recovered family above. Keeping an
        // inert body is safer than silently routing it through generic logic.
        enemy.vx = 0.0f;
        enemy.vy = 0.0f;
        break;
    }

    const bool formationCore = enemy.updateCase == 0x47 ||
                               enemy.updateCase == 0x55 ||
                               enemy.updateCase == 0x65 ||
                               enemy.updateCase == 0x67 ||
                               enemy.updateCase == 0x86 ||
                               enemy.updateCase == 0x87 ||
                               enemy.updateCase == 0x88;
    const int cleanupDelay = formationCore ? 900 : 180;
    if (timer > cleanupDelay &&
        (enemy.x < -420.0f || enemy.x > 1140.0f ||
         enemy.y < -520.0f || enemy.y > 1240.0f)) {
        enemy.active = false;
        if (isLateStageGateOwner(enemy)) {
            clearLateStageGate(selectedStage_);
        }
    }
}

void StageRuntime::emitLateStageProjectiles(StageEnemy& enemy, int activeAge) {
    if (enemy.helperState != 1 || !enemy.targetable || enemy.hp < 1) {
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto interval = [difficulty](int base) {
        return std::max(6, base - difficulty * std::max(2, base / 10));
    };
    const float aimed = aimAtPlayer(enemy.x, enemy.y);
    const float phase = static_cast<float>(activeAge) * 0.045f +
                        static_cast<float>(enemy.entityId & 15);
    bool fired = false;

    const float sourceX = enemy.x - enemy.vx;
    const float sourceY = enemy.y - enemy.vy;
    const auto aimFrom = [this](float x, float y) {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - y),
            static_cast<double>(player_.x - x)));
    };

    if (enemy.spawnType == 0x44) {
        // FUN_140096890 only emits from its lethal branch, which is handled in
        // updateLateStageEnemy before the entity unlinks.
        return;
    }

    if (enemy.spawnType == 0x45) { // FUN_140097270
        constexpr std::array<int, 5> kStart{{20, 14, 10, 5, 5}};
        constexpr std::array<int, 5> kCadence{{55, 30, 24, 21, 16}};
        constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 6.5, 7.5, 9.0}};
        const int start = kStart[static_cast<std::size_t>(difficulty)];
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (activeAge >= start && activeAge < 150 &&
            (activeAge - start) % cadence == 0 && sourceY + 20.0f < 360.0f) {
            const auto aimed16 = aimFrom(sourceX, sourceY + 20.0f);
            const auto snapped = normalizeAngle16(
                (static_cast<int>(aimed16) + 0x400) & ~0x7ff);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(8, 0, sourceX, sourceY + 20.0f,
                                snapped, 10.0f, speed, 1, 0);
            if (difficulty == 2) {
                spawnProjectileNode(8, 0, sourceX, sourceY + 20.0f,
                                    snapped, 10.0f, speed + 0.5, 1, 0);
            }
            if (difficulty > 2) {
                spawnProjectileNode(8, 0, sourceX, sourceY + 20.0f,
                                    normalizeAngle16(snapped - 2000),
                                    10.0f, speed - 1.5, 1, 0);
                spawnProjectileNode(8, 0, sourceX, sourceY + 20.0f,
                                    normalizeAngle16(snapped + 2000),
                                    10.0f, speed - 1.5, 1, 0);
            }
            fired = true;
        }
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x46) { // FUN_140097d30
        constexpr std::array<int, 5> kCadence{{96, 64, 50, 40, 36}};
        constexpr std::array<int, 5> kSpread{{0, 0x8ae, 0xd05,
                                               0xd05, 0xd05}};
        constexpr std::array<double, 5> kBase{{6.0, 7.0, 7.5, 8.0, 9.0}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (activeAge >= 64 && activeAge < 240) {
            const int local = (activeAge - 64) % cadence;
            if (local == 0) {
                enemy.secondaryAngle16 = aimFrom(sourceX, sourceY + 50.0f);
            }
            if (local < 30 && local % 5 == 0) {
                const double speed = kBase[static_cast<std::size_t>(difficulty)] +
                                     local * 0.06;
                spawnProjectileNode(7, 0, sourceX, sourceY + 50.0f,
                                    enemy.secondaryAngle16, 10.0f,
                                    speed, 1, 0);
                if (difficulty > 0) {
                    spawnProjectileSpread(
                        7, 0, sourceX, sourceY + 50.0f,
                        enemy.secondaryAngle16, 10.0f, speed - 1.0,
                        1, 2, kSpread[static_cast<std::size_t>(difficulty)], 0);
                }
                if (difficulty > 2) {
                    spawnProjectileNode(7, 0, sourceX, sourceY + 50.0f,
                                        enemy.secondaryAngle16, 10.0f,
                                        speed + 1.8, 1, 0);
                    spawnProjectileSpread(
                        7, 0, sourceX, sourceY + 50.0f,
                        enemy.secondaryAngle16, 10.0f, speed + 0.8,
                        1, 2, kSpread[static_cast<std::size_t>(difficulty)], 0);
                }
                fired = true;
            }
        }
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x47 || enemy.spawnType == 0x48) {
        constexpr std::array<int, 5> kCadence{{150, 120, 90, 90, 70}};
        constexpr std::array<int, 5> kCount{{3, 5, 7, 7, 9}};
        constexpr std::array<int, 5> kAngleStep{{0x12c0, 0xe10, 0x834,
                                                 0x834, 0x708}};
        constexpr std::array<double, 5> kSpeed{{4.0, 5.0, 5.5, 6.5, 7.5}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (activeAge >= 80 && activeAge < 300 &&
            (activeAge - 80) % cadence == 0) {
            const auto aimed16 = aimFrom(sourceX, sourceY);
            const int count = kCount[static_cast<std::size_t>(difficulty)];
            const int spread = (count - 1) *
                               kAngleStep[static_cast<std::size_t>(difficulty)];
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileSpread(11, 0, sourceX, sourceY, aimed16,
                                  0.0f, speed, 1, count, spread, 0);
            if (difficulty > 2) {
                spawnProjectileSpread(11, 0, sourceX, sourceY, aimed16,
                                      0.0f, speed - 1.5, 1, count,
                                      static_cast<int>(spread * 0.7), 0);
            }
            fired = true;
        }
        if (fired) playPlayerSound(bullet2SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x49) { // FUN_140098f40
        constexpr std::array<int, 5> kCadence{{150, 120, 90, 90, 70}};
        constexpr std::array<int, 5> kBurstStep{{12, 7, 5, 5, 4}};
        constexpr std::array<double, 5> kSpeed{{4.0, 4.5, 5.0, 5.0, 6.0}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        const int local = activeAge % cadence;
        if (activeAge < 300 && local < 30 &&
            local % kBurstStep[static_cast<std::size_t>(difficulty)] == 0) {
            const auto angle = normalizeAngle16(
                static_cast<int>(enemy.sourceAngle16) - 0x8000);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(4, 0, sourceX, sourceY, angle,
                                0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(4, 0, sourceX, sourceY, angle,
                                    0.0f, speed + 1.1, 1, 0);
            }
            fired = true;
        }
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x4a) { // FUN_140099570
        constexpr std::array<int, 5> kCadence{{32, 24, 20, 20, 16}};
        constexpr std::array<int, 5> kCount{{5, 7, 9, 7, 9}};
        constexpr std::array<double, 5> kSpeed{{5.0, 5.5, 6.0, 6.5, 8.0}};
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (activeAge >= 50 && activeAge < 290) {
            const int local = (activeAge - 50) % 120;
            if (local < cadence * 3 && local % cadence == 0) {
                const int count = kCount[static_cast<std::size_t>(difficulty)];
                const auto aimed16 = aimFrom(sourceX, sourceY + 20.0f);
                const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(4, 0, sourceX, sourceY + 20.0f,
                                      aimed16, 0.0f, speed, 1,
                                      count, 17000, 0);
                if (difficulty > 2 && count > 1) {
                    spawnProjectileSpread(
                        4, 0, sourceX, sourceY + 20.0f, aimed16,
                        0.0f, speed + 1.4, 1, count - 1,
                        (17000 / (count - 1)) * (count - 2), 0);
                }
                fired = true;
            }
        }
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x4b || enemy.spawnType == 0x4c) {
        // 0x4b creates 0x4c enemies; 0x4c only emits its recovered death ring.
        return;
    }

    if (enemy.spawnType == 0x4d) { // FUN_14009a4a0
        constexpr std::array<int, 5> kCadence{{101, 72, 65, 60, 60}};
        constexpr std::array<int, 5> kCount{{5, 9, 11, 11, 13}};
        constexpr std::array<int, 5> kBurst{{20, 30, 35, 35, 35}};
        constexpr std::array<int, 5> kTurn{{33, 55, 66, 99, 120}};
        constexpr std::array<double, 5> kSpeed{{6.6, 8.0, 9.0, 10.0, 12.0}};
        if (activeAge >= 90 && activeAge < 360) {
            const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
            const int rootLocal = activeAge - 90;
            if (rootLocal % cadence == 0) {
                enemy.secondaryAngle16 = aimFrom(sourceX, sourceY);
            }
            const int direction = enemy.originX >= 360.0f ? 1 : -1;
            const auto fireSweep = [&](int local, int sign) {
                if (local < 0 || local >= kBurst[static_cast<std::size_t>(difficulty)] ||
                    local % 5 != 0) {
                    return;
                }
                const auto angle = normalizeAngle16(
                    static_cast<int>(enemy.secondaryAngle16) +
                    sign * direction * local *
                        kTurn[static_cast<std::size_t>(difficulty)]);
                spawnProjectileSpread(
                    3, 7, sourceX, sourceY, angle, 10.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)], 1,
                    kCount[static_cast<std::size_t>(difficulty)], 30000, 0);
                fired = true;
            };
            fireSweep(rootLocal % (cadence * 2), 1);
            fireSweep((activeAge - (cadence + 90)) % (cadence * 2), -1);
        }
        if (fired) playPlayerSound(bullet2SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType == 0x4e) { // FUN_14009b0a0
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4d) return;
        constexpr std::array<int, 5> kCadence{{41, 23, 20, 17, 14}};
        constexpr std::array<double, 5> kSpeed{{3.6, 4.5, 5.5, 6.0, 8.0}};
        const int start = (parent->entityId - enemy.entityId) * 7 + 45;
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        if (activeAge >= start && (activeAge - start) % cadence == 0) {
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            const float fireX = sourceX +
                static_cast<float>(std::cos(radians) * 40.0);
            const float fireY = sourceY +
                static_cast<float>(std::sin(radians) * 40.0);
            const auto snapped = normalizeAngle16(
                (static_cast<int>(enemy.sourceAngle16) + 0x400) & ~0x7ff);
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(0, 0, fireX, fireY, snapped,
                                0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(0, 0, fireX, fireY, snapped,
                                    0.0f, speed - 1.8, 1, 0);
            }
            fired = true;
        }
        if (fired) playPlayerSound(bullet1SoundHandle_, 0x10);
        return;
    }

    if (enemy.spawnType >= 0x50 && enemy.spawnType <= 0x52) {
        // FUN_14009c530's 0x50..0x52 parts are visual-only.
        return;
    }

    if (enemy.spawnType == 0x53) { // FUN_14009cd10
        StageEnemy* parent = findEnemyById(enemy.parentEntityId);
        if (parent == nullptr || parent->spawnType != 0x4f ||
            parent->helperTimer >= 1201) {
            return;
        }
        constexpr std::array<int, 5> kCadence{{320, 270, 240, 240, 240}};
        constexpr std::array<double, 5> kSpeed{{5.0, 6.0, 7.0, 8.0, 9.0}};
        const int sequence = std::clamp(enemy.childIndex, 1, 4);
        const int start = sequence * 20;
        const int cadence = kCadence[static_cast<std::size_t>(difficulty)];
        // At `start` the original creates a short-lived type-0x31 muzzle cue.
        // Its projectile event follows exactly 40 ticks later.
        if (activeAge >= start + 40 &&
            (activeAge - (start + 40)) % cadence == 0) {
            const double speed = kSpeed[static_cast<std::size_t>(difficulty)];
            spawnProjectileNode(17, 0x0c, sourceX, sourceY + 10.0f,
                                static_cast<std::uint16_t>(0x4000),
                                0.0f, speed, 1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(17, 0x0c, sourceX, sourceY + 10.0f,
                                    static_cast<std::uint16_t>(0x0b44),
                                    0.0f, speed, 1, 0);
                spawnProjectileNode(17, 0x0c, sourceX, sourceY + 10.0f,
                                    normalizeAngle16(0x0b44 + 27000),
                                    0.0f, speed, 1, 0);
            }
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.spawnType == 0x4f) {
        const int cadence = std::array<int, 5>{{2, 1, 2, 2, 2}}[
            static_cast<std::size_t>(difficulty)];
        const int count = difficulty < 2 ? 1 : 2;
        const int angleStep = std::array<int, 5>{{0x578, 0x9c4, 0x898, 0x898, 0x898}}[
            static_cast<std::size_t>(difficulty)];
        const double speed = lateEnemyProjectileSpeed(
            difficulty, std::array<double, 5>{{4.5, 5.5, 6.0, 6.0, 8.0}});
        if (activeAge >= 20 && activeAge < 120 &&
            (activeAge - 20) % cadence == 0) {
            const int angle = (activeAge - 20) * angleStep - 0x4000;
            spawnProjectileSpread(10, 2, enemy.x, enemy.y,
                                  static_cast<float>(fixedAngleRadians(
                                      normalizeAngle16(angle))),
                                  speed, 10, count,
                                  static_cast<float>(fixedAngleRadians(
                                      count * 7000 - 7000)));
            if (difficulty > 2) {
                spawnProjectileSpread(10, 2, enemy.x, enemy.y,
                                      static_cast<float>(fixedAngleRadians(
                                          normalizeAngle16(angle))),
                                      speed + 1.5, 10, count,
                                      static_cast<float>(fixedAngleRadians(
                                          count * 12000 - 12000)));
            }
            fired = true;
        }
        if (activeAge >= 120 && activeAge < 220 &&
            (activeAge - 120) % cadence == 0) {
            const int angle = (100 - activeAge) * angleStep + 0x4000;
            spawnProjectileSpread(11, 2, enemy.x, enemy.y,
                                  static_cast<float>(fixedAngleRadians(
                                      normalizeAngle16(angle))),
                                  speed, 10, count,
                                  static_cast<float>(fixedAngleRadians(
                                      count * 7000 - 7000)));
            if (difficulty > 2) {
                spawnProjectileSpread(11, 2, enemy.x, enemy.y,
                                      static_cast<float>(fixedAngleRadians(
                                          normalizeAngle16(angle))),
                                      speed + 1.0, 10, count,
                                      static_cast<float>(fixedAngleRadians(
                                          count * 12000 - 12000)));
            }
            fired = true;
        }
        const int lateCadence = std::array<int, 5>{{0x5f, 0x36, 0x2d, 0x2d, 0x23}}[
            static_cast<std::size_t>(difficulty)];
        if (activeAge >= 480 && (activeAge - 480) % lateCadence == 0) {
            spawnProjectileSpread(3, 0x1c, enemy.x + 65.0f,
                                  enemy.y + 40.0f, aimed,
                                  11.5, 6, 1, 0.0f);
            spawnProjectileSpread(3, 0x1c, enemy.x - 65.0f,
                                  enemy.y + 40.0f, aimed + static_cast<float>(kPi),
                                  11.5, 6, 1, 0.0f);
            fired = true;
        }
        if (fired) {
            playPlayerSound(bullet2SoundHandle_, 0x10);
        }
        return;
    }

    if (enemy.spawnType == 0x5f) {
        return;
    }

    if (enemy.spawnType == 0x5a) {
        const int cadence = std::array<int, 5>{{0x4d, 0x30, 0x24, 0x24, 0x20}}[
            static_cast<std::size_t>(difficulty)];
        const double speed = lateEnemyProjectileSpeed(
            difficulty, std::array<double, 5>{{5.0, 6.0, 6.2, 6.2, 6.8}});
        if (activeAge >= 70) {
            const int local = (activeAge - 70) % cadence;
            if (local < 12 && local % 4 == 0) {
                spawnProjectileSpread(4, 0, enemy.x, enemy.y,
                                      aimed, speed, 5, 1, 0.0f);
                fired = true;
            }
        }
        if (difficulty > 2 && activeAge >= 90 &&
            (activeAge - 90) % cadence == 0) {
            spawnProjectileSpread(5, 0, enemy.x, enemy.y,
                                  aimed, speed + 0.5, 5, 2,
                                  static_cast<float>(fixedAngleRadians(0x640)));
            fired = true;
        }
        if (fired) {
            playPlayerSound(bullet1SoundHandle_, 0x10);
        }
        return;
    }

    if (enemy.spawnType == 0x5b || enemy.spawnType == 0x5c) {
        const int cadence = std::array<int, 5>{{0x2c, 0x15, 0x0f, 9, 7}}[
            static_cast<std::size_t>(difficulty)];
        const int local = activeAge % (cadence * 5);
        if (local < cadence * 3 && local % cadence == 0) {
            const double speed = lateEnemyProjectileSpeed(
                difficulty, std::array<double, 5>{{5.0, 5.5, 6.5, 7.0, 8.0}});
            spawnProjectileSpread(1, 0, enemy.x, enemy.y,
                                  aimed, speed, 5, 1, 0.0f);
            if (difficulty > 2) {
                spawnProjectileSpread(1, 0, enemy.x, enemy.y,
                                      aimed, speed + 2.0, 5, 1, 0.0f);
            }
            fired = true;
        }
        if (fired) {
            playPlayerSound(bullet1SoundHandle_, 0x10);
        }
        return;
    }

    if (enemy.spawnType == 0x5d) {
        const int cadence = std::array<int, 5>{{0xb4, 100, 0x50, 0x46, 0x32}}[
            static_cast<std::size_t>(difficulty)];
        if (activeAge >= 110) {
            const int local = (activeAge - 110) % cadence;
            if (local < 20 && local % 10 == 0) {
                const double speed = lateEnemyProjectileSpeed(
                    difficulty, std::array<double, 5>{{5.5, 6.5, 7.5, 6.5, 8.0}});
                spawnProjectileSpread(13, 0, enemy.x + 30.0f, enemy.y,
                                      aimed, speed, 6, difficulty > 2 ? 3 : 1,
                                      difficulty > 2
                                          ? static_cast<float>(fixedAngleRadians(0x3e80))
                                          : 0.0f);
                spawnProjectileSpread(13, 0, enemy.x - 30.0f, enemy.y,
                                      aimed, speed, 6, difficulty > 2 ? 3 : 1,
                                      difficulty > 2
                                          ? static_cast<float>(fixedAngleRadians(0x3e80))
                                          : 0.0f);
                fired = true;
            }
        }
        if (fired) {
            playPlayerSound(bullet2SoundHandle_, 0x10);
        }
        return;
    }

    if (enemy.spawnType == 0x5e) {
        const int cadence = std::array<int, 5>{{0x78, 0x3c, 0x32, 0x2d, 0x2d}}[
            static_cast<std::size_t>(difficulty)];
        const int burstLength = std::array<int, 5>{{0x10, 0x10, 0x14, 0x18, 0x1e}}[
            static_cast<std::size_t>(difficulty)];
        const double speed = lateEnemyProjectileSpeed(
            difficulty, std::array<double, 5>{{6.0, 6.6, 7.5, 8.5, 9.5}});
        if (activeAge >= 120) {
            const int local = (activeAge - 120) % cadence;
            if (local < burstLength && local % 4 == 0) {
                const int count = local / 4 + 1;
                spawnProjectileSpread(9, 0, enemy.x, enemy.y,
                                      aimed, speed, 7, count,
                                      static_cast<float>(fixedAngleRadians(
                                          count * 400 - 400)));
                fired = true;
            }
            const int secondStart = cadence + 0x82 + burstLength;
            if (activeAge >= secondStart &&
                (activeAge - secondStart) % (cadence * 2) == 0) {
                const int count = std::array<int, 5>{{9, 11, 13, 13, 15}}[
                    static_cast<std::size_t>(difficulty)];
                spawnProjectileSpread(14, 0, enemy.x, enemy.y,
                                      aimed, speed - 2.0, 7, count,
                                      static_cast<float>(fixedAngleRadians(27000)));
                fired = true;
            }
        }
        if (fired) {
            playPlayerSound(bullet2SoundHandle_, 0x10);
        }
        return;
    }

    if (enemy.spawnType == 0x77) {
        if (activeAge < 120 || activeAge >= 1200 || enemy.y >= 360.0f) {
            return;
        }
        const int local = (activeAge - 120) % 0x148;
        const int cadence = std::array<int, 5>{{0x13, 0x0d, 0x0b, 10, 8}}[
            static_cast<std::size_t>(difficulty)];
        const int ringCount = std::array<int, 5>{{6, 8, 9, 10, 10}}[
            static_cast<std::size_t>(difficulty)];
        const double ringSpeed = lateEnemyProjectileSpeed(
            difficulty, std::array<double, 5>{{5.4, 6.0, 6.5, 7.0, 8.0}});
        if (local < 120 && local % cadence == 0) {
            spawnProjectileSpread(4, local % 0x15, enemy.x, enemy.y + 10.0f,
                                  phase, ringSpeed, 6, ringCount,
                                  static_cast<float>(kTau));
            spawnProjectileSpread(4, 0, enemy.x, enemy.y + 10.0f,
                                  phase + static_cast<float>(kTau /
                                      static_cast<double>(ringCount * 3)),
                                  ringSpeed - 0.5, 6, ringCount,
                                  static_cast<float>(kTau));
            fired = true;
        }
        if (local >= 160 && local < 300 &&
            (local - 160) % cadence == 0) {
            const int count = std::array<int, 5>{{3, 3, 5, 5, 7}}[
                static_cast<std::size_t>(difficulty)];
            const int source = ((local - 160) / cadence) & 3;
            constexpr std::array<float, 4> kOffsetX{{-125.0f, 125.0f, 125.0f, -125.0f}};
            constexpr std::array<float, 4> kOffsetY{{125.0f, 125.0f, 40.0f, 40.0f}};
            spawnProjectileSpread(12, local % 0x15,
                                  enemy.x + kOffsetX[static_cast<std::size_t>(source)],
                                  enemy.y + kOffsetY[static_cast<std::size_t>(source)],
                                  aimed, 4.4 + difficulty * 0.6, 6, count,
                                  static_cast<float>(fixedAngleRadians(
                                      count * 0x960 - 0x960)));
            fired = true;
        }
        if (fired) {
            playPlayerSound(bullet2SoundHandle_, 0x10);
        }
        return;
    }

    switch (enemy.updateCase) {
    case 0x32:
        if (activeAge >= 40 && activeAge % interval(72) == 0) {
            spawnProjectileSpread(9, 0, enemy.x, enemy.y, aimed,
                                  4.0 + difficulty * 0.7, 5,
                                  1 + difficulty, 0.28f + difficulty * 0.05f);
            fired = true;
        }
        break;
    case 0x33:
        if (activeAge >= 30 && activeAge % interval(60) == 0) {
            spawnProjectileSpread(7, 2, enemy.x, enemy.y,
                                  phase, 3.0 + difficulty * 0.45, 6,
                                  6 + difficulty * 2, static_cast<float>(kTau));
            fired = true;
        }
        break;
    case 0x34:
        if (activeAge >= 64 && activeAge < 240 &&
            activeAge % interval(48) == 0) {
            spawnProjectileSpread(7, 0, enemy.x, enemy.y, aimed,
                                  4.5 + difficulty * 0.65, 5,
                                  3 + difficulty * 2, 0.75f);
            fired = true;
        }
        break;
    case 0x35:
        if (activeAge >= 80 && activeAge % interval(90) == 0) {
            const int count = 8 + difficulty * 2;
            spawnProjectileSpread(enemy.spawnType == 0x47 ? 3 : 5, 8,
                                  enemy.x, enemy.y, phase,
                                  2.8 + difficulty * 0.4, 7, count,
                                  static_cast<float>(kTau));
            fired = true;
        }
        break;
    case 0x37:
    case 0x39:
    case 0x3b:
        if (activeAge >= 60 && activeAge % interval(100) == 0) {
            const int count = 10 + difficulty * 3;
            spawnProjectileSpread(4, 2, enemy.x, enemy.y,
                                  phase, 2.6 + difficulty * 0.5, 8,
                                  count, static_cast<float>(kTau));
            if (enemy.updateCase == 0x3b) {
                spawnProjectileSpread(1, 0, enemy.x, enemy.y, aimed,
                                      5.0 + difficulty * 0.7, 5,
                                      5 + difficulty * 2, 0.9f);
            }
            fired = true;
        }
        break;
    case 0x41:
        if (activeAge % interval(66) == 0) {
            spawnProjectileSpread(2, 0, enemy.x, enemy.y, aimed,
                                  4.0 + difficulty * 0.6, 5,
                                  3 + difficulty, 0.55f);
            fired = true;
        }
        break;
    case 0x42:
    case 0x43:
    case 0x44:
        if (activeAge % interval(enemy.updateCase == 0x42 ? 80 : 54) == 0) {
            const float center = enemy.updateCase == 0x44 ? phase : aimed;
            spawnProjectileSpread(6, enemy.updateCase == 0x44 ? 2 : 0,
                                  enemy.x, enemy.y, center,
                                  3.2 + difficulty * 0.55, 6,
                                  5 + difficulty * 2,
                                  enemy.updateCase == 0x44
                                      ? static_cast<float>(kTau)
                                      : 0.8f);
            fired = true;
        }
        break;
    case 0x45:
    case 0x46:
    case 0x47:
        if (activeAge >= 45 && activeAge % interval(84) == 0) {
            spawnProjectileSpread(8, 8, enemy.x, enemy.y, phase,
                                  2.5 + difficulty * 0.4, 7,
                                  8 + difficulty * 2, static_cast<float>(kTau));
            if (enemy.updateCase == 0x47) {
                spawnProjectileSpread(0, 0, enemy.x, enemy.y, aimed,
                                      5.2 + difficulty * 0.65, 5,
                                      5 + difficulty * 2, 1.0f);
            }
            fired = true;
        }
        break;
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
        if (activeAge >= 50 && activeAge % interval(72) == 0) {
            const bool radial = enemy.updateCase == 0x4f ||
                                enemy.updateCase == 0x51 ||
                                enemy.updateCase == 0x55;
            spawnProjectileSpread(5 + (enemy.updateCase & 3), radial ? 2 : 0,
                                  enemy.x, enemy.y, radial ? phase : aimed,
                                  3.3 + difficulty * 0.55, 6,
                                  radial ? 10 + difficulty * 2 : 4 + difficulty * 2,
                                  radial ? static_cast<float>(kTau) : 0.9f);
            fired = true;
        }
        break;
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x6c:
        if (activeAge >= 30 && activeAge % interval(60) == 0) {
            const bool spiral = enemy.updateCase == 0x65 ||
                                enemy.updateCase == 0x66 ||
                                enemy.updateCase == 0x67;
            spawnProjectileSpread(2 + (enemy.updateCase & 7), spiral ? 2 : 0,
                                  enemy.x, enemy.y, spiral ? phase : aimed,
                                  3.6 + difficulty * 0.6, 6,
                                  spiral ? 12 + difficulty * 2 : 5 + difficulty * 2,
                                  spiral ? static_cast<float>(kTau) : 1.0f);
            fired = true;
        }
        break;
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
        if (activeAge >= 24 && activeAge % interval(50) == 0) {
            const bool ring = enemy.updateCase == 0x84;
            spawnProjectileSpread(7 + (enemy.updateCase & 1), ring ? 2 : 0,
                                  enemy.x, enemy.y, ring ? phase : aimed,
                                  4.0 + difficulty * 0.65, 5,
                                  ring ? 10 + difficulty * 2 : 3 + difficulty * 2,
                                  ring ? static_cast<float>(kTau) : 0.72f);
            fired = true;
        }
        break;
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
        if (activeAge >= 40 && activeAge % interval(78) == 0) {
            spawnProjectileSpread(9, 8, enemy.x, enemy.y, phase,
                                  2.8 + difficulty * 0.5, 8,
                                  12 + difficulty * 3, static_cast<float>(kTau));
            spawnProjectileSpread(1, 0, enemy.x, enemy.y, aimed,
                                  5.0 + difficulty * 0.75, 5,
                                  5 + difficulty * 2, 0.85f);
            fired = true;
        }
        break;
    default:
        break;
    }

    if (fired) {
        playPlayerSound((enemy.updateCase & 1) == 0
                            ? bullet1SoundHandle_
                            : bullet2SoundHandle_,
                        0x10);
    }
}

bool StageRuntime::spawnStage05BossChild(StageEnemy& parent, int spawnType,
                                         float offsetX, float offsetY,
                                         std::uint16_t angle16, double speed,
                                         int radius, int hitPoints, int kind,
                                         const char* note) {
    const LateSpawnSpec* spec = lateSpawnSpec(spawnType);
    if (parent.spawnType != 0x13c || spec == nullptr ||
        spawnType < 0x54 || spawnType > 0x56 ||
        enemies_.size() + pendingEnemies_.size() >= kLateStageEntityCap) {
        return false;
    }

    StageEnemy child;
    child.entityId = nextEntityId_++;
    child.spawnType = spawnType;
    child.updateCase = spec->updateCase;
    child.sourceHitPoints = hitPoints;
    child.sourceX = static_cast<int>(std::lround(offsetX));
    child.sourceY = static_cast<int>(std::lround(offsetY));
    child.sourceNote = note;
    child.sourceDispatchKind = kind;
    child.sourceDispatchField = radius;
    child.rewardWeight = 0;
    child.parentEntityId = parent.entityId;
    child.parentSpawnType = parent.spawnType;
    child.childIndex = parent.liveChildCount;
    child.originX = offsetX;
    child.originY = offsetY;
    child.x = parent.x + offsetX;
    child.y = parent.y + offsetY;
    child.markerDrawX = child.x;
    child.markerDrawY = child.y;
    child.sourceAngle16 = angle16;
    child.secondaryAngle16 = angle16;
    child.targetAngle16 = angle16;
    child.angle = static_cast<float>(fixedAngleRadians(angle16));
    child.sourceSpeed = speed;
    child.speed = static_cast<float>(speed);
    const double easyScale = config_.difficulty == 0 ? 0.8 : 1.0;
    child.hp = std::max(1, static_cast<int>(hitPoints * easyScale));
    child.maxHp = child.hp;
    child.drawHp = child.hp;
    child.radius = radius;
    child.activationDelay = 0;
    child.targetable = false;
    pendingEnemies_.push_back(child);
    ++parent.liveChildCount;
    return true;
}

void StageRuntime::updateStage05BossChild(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    const auto release = [&]() {
        if (parent != nullptr && parent->liveChildCount > 0) {
            --parent->liveChildCount;
        }
        enemy.targetable = false;
        enemy.active = false;
    };
    if (parent == nullptr || !parent->active || parent->spawnType != 0x13c) {
        release();
        return;
    }

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimAtPlayer16 = [this, &enemy]() {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
    };
    const auto syncSharedHp = [&]() {
        if (enemy.hp < parent->hp) {
            parent->hp = enemy.hp;
        }
        else if (parent->hp < enemy.hp) {
            enemy.hp = parent->hp;
        }
        enemy.maxHp = parent->maxHp;
        enemy.drawHp = parent->drawHp;
    };

    if (enemy.spawnType == 0x54) {
        if (parent->helperState != 8 && parent->helperState != 9) {
            release();
            return;
        }

        const int timer = enemy.helperTimer;
        if (timer == 0) {
            enemy.x = parent->x + 5.0f;
            enemy.y = parent->y + 30.0f;
        }
        const float targetX = parent->x + static_cast<float>(
            std::sin(timer * 0.02268) * 200.0);
        const float targetY = parent->y + static_cast<float>(
            std::sin(timer * 0.01522) * -90.0 -
            std::sin(timer * 0.00913) * 60.0);
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (targetY - enemy.y) / 30.0f;

        if (enemy.helperState == 0) {
            enemy.targetable = false;
            if (timer >= 0xac) {
                enemy.helperState = 1;
                enemy.hp = parent->hp;
                enemy.maxHp = parent->maxHp;
                enemy.drawHp = parent->drawHp;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }

        syncSharedHp();
        enemy.targetable = true;
        const int local = (timer - 0xac) % 700;
        static constexpr std::array<int, 5> kAimInterval{{83, 51, 33, 45, 33}};
        static constexpr std::array<int, 5> kFireInterval{{10, 6, 3, 4, 3}};
        static constexpr std::array<double, 5> kSweepSpeed{{3.6, 4.5, 5.0, 4.0, 6.0}};
        const int aimInterval = kAimInterval[static_cast<std::size_t>(difficulty)];
        const int fireInterval = kFireInterval[static_cast<std::size_t>(difficulty)];
        if (local >= 0x78 && local < 0x1e0 &&
            (local - 0x78) % fireInterval == 0) {
            const int phase = (local - 0x78) % (aimInterval * 2);
            const int triangle = phase < aimInterval
                                     ? phase
                                     : aimInterval * 2 - phase;
            const int sweep = triangle * (0x8000 / aimInterval) - 0x4190;
            const auto center = normalizeAngle16(
                static_cast<int>(aimAtPlayer16()) + sweep);
            const double speed =
                kSweepSpeed[static_cast<std::size_t>(difficulty)] +
                static_cast<double>(local - 0x78) * 0.006;
            for (int i = 0; i < 3; ++i) {
                spawnProjectileNode(0x0d, 0, enemy.x, enemy.y + 10.0f,
                                    normalizeAngle16(static_cast<int>(center) +
                                                     i * 400),
                                    10.0f, speed, 1, 0);
            }
            if (difficulty > 2) {
                for (int i = 0; i < 3; ++i) {
                    spawnProjectileNode(0x0d, 0, enemy.x,
                                        enemy.y + 10.0f,
                                        normalizeAngle16(
                                            static_cast<int>(center) +
                                            0x457 + i * 400),
                                        10.0f, speed + 1.0, 1, 0);
                }
            }
            playPlayerSound(bullet1SoundHandle_, 0x13);
        }

        static constexpr std::array<int, 5> kBurstStep{{18, 9, 6, 4, 3}};
        static constexpr std::array<int, 5> kBurstWindow{{40, 50, 55, 60, 66}};
        static constexpr std::array<double, 5> kBurstSpeed{{5.0, 6.0, 7.0, 8.0, 9.0}};
        const int burstStep = kBurstStep[static_cast<std::size_t>(difficulty)];
        const int burstWindow = kBurstWindow[static_cast<std::size_t>(difficulty)];
        const bool firstBurst = local >= 500 && local < 500 + burstWindow &&
                                (local - 500) % burstStep == 0;
        const bool secondBurst = local >= 600 && local < 600 + burstWindow &&
                                 (local - 600) % burstStep == 0;
        if (firstBurst || secondBurst) {
            const std::uint32_t random = lateStageScriptRand(timer);
            const int jitter = static_cast<int>(random % 40001u) - 20000;
            spawnProjectileNode(
                0x11, 0x0c, enemy.x, enemy.y + 10.0f,
                normalizeAngle16(static_cast<int>(aimAtPlayer16()) + jitter),
                0.0f, kBurstSpeed[static_cast<std::size_t>(difficulty)],
                1, 0);
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
        return;
    }

    if (enemy.spawnType == 0x55) {
        if (parent->helperState != 9 || lateStageBossPhaseMode_ != 1) {
            release();
            return;
        }
        const int timer = enemy.helperTimer;
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * enemy.sourceSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * enemy.sourceSpeed) +
                   static_cast<float>(timer) * 0.15f;
        enemy.targetable = timer >= 10;
        enemy.drawHp = enemy.hp;
        if (enemy.hp < 1) {
            spawnEnemyDeathEffects(enemy, 0);
            release();
            return;
        }
        if (timer >= 50) {
            static constexpr std::array<double, 5> kSpeed{{
                3.6, 4.5, 5.0, 5.0, 6.4,
            }};
            const auto snapped = normalizeAngle16(
                (static_cast<int>(aimAtPlayer16()) + 0x400) & ~0x7ff);
            spawnProjectileNode(0, 0, enemy.x, enemy.y, snapped,
                                10.0f,
                                kSpeed[static_cast<std::size_t>(difficulty)],
                                1, 0);
            if (difficulty > 2) {
                spawnProjectileNode(
                    0, 0, enemy.x, enemy.y, snapped, 10.0f,
                    kSpeed[static_cast<std::size_t>(difficulty)] + 1.5,
                    1, 0);
            }
            playPlayerSound(bullet1SoundHandle_, 0x13);
            release();
        }
        return;
    }

    if (parent->helperState < 11 || parent->helperState > 13 ||
        lateStageBossPhaseMode_ != 1) {
        release();
        return;
    }
    if (enemy.helperState == 0) {
        const float targetX = parent->x + enemy.originX;
        const float targetY = parent->y + enemy.originY;
        enemy.x += (targetX - enemy.x) / 30.0f;
        enemy.y += (targetY - enemy.y) / 30.0f;
        enemy.targetable = false;
        if (enemy.helperTimer >= 30) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = parent->hp;
            enemy.maxHp = parent->maxHp;
            enemy.drawHp = parent->drawHp;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        return;
    }

    const float targetX = parent->x + enemy.originX;
    const float targetY = parent->y + enemy.originY;
    enemy.x += (targetX - enemy.x) / 30.0f;
    enemy.y += (targetY - enemy.y) / 30.0f;
    syncSharedHp();
    enemy.targetable = true;

    const int local = enemy.helperTimer % 0x4b0;
    static constexpr std::array<int, 5> kAimInterval{{83, 61, 47, 41, 36}};
    static constexpr std::array<int, 5> kSweepStep{{15, 7, 5, 4, 3}};
    static constexpr std::array<int, 5> kRandomStep{{18, 8, 6, 4, 3}};
    static constexpr std::array<double, 5> kSpeed{{4.0, 4.0, 4.5, 5.0, 6.4}};
    const int aimInterval = kAimInterval[static_cast<std::size_t>(difficulty)];
    const int sweepStep = kSweepStep[static_cast<std::size_t>(difficulty)];
    if (local >= 40 && local < 200 && (local - 40) % sweepStep == 0) {
        const int phase = (local - 40) % (aimInterval * 2);
        const int triangle = phase < aimInterval
                                 ? phase
                                 : aimInterval * 2 - phase;
        int sweep = triangle * (28000 / aimInterval) - 14000;
        if (enemy.originX < 0.0f) sweep = -sweep;
        spawnProjectileNode(
            0x11, 0x0d, enemy.x, enemy.y + 10.0f,
            normalizeAngle16(static_cast<int>(aimAtPlayer16()) + sweep),
            10.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
        playPlayerSound(bossSe7SoundHandle_, 0x10);
    }
    const int randomStep = kRandomStep[static_cast<std::size_t>(difficulty)];
    if (local >= 0xd2 && local < 0x154 &&
        (local - 0xd2) % randomStep == 0) {
        const std::uint32_t random = lateStageScriptRand(
            enemy.helperTimer + enemy.entityId - parent->entityId);
        const int jitter = static_cast<int>(random % 28001u) - 14000;
        spawnProjectileNode(
            0x11, 0x0d, enemy.x, enemy.y + 10.0f,
            normalizeAngle16(static_cast<int>(aimAtPlayer16()) + jitter),
            10.0f, kSpeed[static_cast<std::size_t>(difficulty)], 1, 0);
        playPlayerSound(bossSe7SoundHandle_, 0x10);
    }
    if (local >= 0x1b8 && local < 0x4a6 &&
        (local - 0x1b8) % 3 == 0) {
        const int spread = local < 500 ? (0x221 - local) * 600 : 27000;
        spawnProjectileSpread(
            6, 0, enemy.x, enemy.y + 10.0f, aimAtPlayer16(),
            10.0f, 14.0, 1, 5, std::max(27000, spread), 0);
        playPlayerSound(bullet1SoundHandle_, 0x10);
    }
}

bool StageRuntime::spawnStage06BossNode(StageEnemy& parent, int spawnType,
                                        int childIndex, float offsetX,
                                        float offsetY,
                                        std::uint16_t angle16, int radius) {
    if (!isStage06BossNodeType(spawnType) ||
        enemies_.size() + pendingEnemies_.size() >= kLateStageEntityCap) {
        return false;
    }

    int updateCase = 0;
    if (spawnType <= 0x65) updateCase = 0x4a;
    else if (spawnType <= 0x6a) updateCase = 0x4b;
    else if (spawnType <= 0x6d) updateCase = 0x4c;
    else if (spawnType == 0x6e) updateCase = 0x4d;
    else updateCase = 0x4e;

    StageEnemy node;
    node.entityId = nextEntityId_++;
    node.spawnType = spawnType;
    node.updateCase = updateCase;
    node.sourceHitPoints = 99999999;
    node.sourceX = static_cast<int>(std::lround(offsetX));
    node.sourceY = static_cast<int>(std::lround(offsetY));
    node.sourceNote = "S06 FUN_140023260 recovered boss apparatus";
    node.sourceDispatchKind = 0;
    node.sourceDispatchField = radius;
    node.parentEntityId = parent.entityId;
    node.parentSpawnType = parent.spawnType;
    node.childIndex = childIndex;
    node.originX = offsetX;
    node.originY = offsetY;
    node.sourceAngle16 = angle16;
    node.secondaryAngle16 = angle16;
    node.targetAngle16 = angle16;
    node.angle = static_cast<float>(fixedAngleRadians(angle16));
    node.sourceSpeed = 1.0;
    node.speed = 1.0f;
    node.hp = 99999999;
    node.maxHp = node.hp;
    node.drawHp = node.hp;
    node.radius = radius;
    node.activationDelay = 0;
    node.rewardWeight = 0;
    node.targetable = false;

    if (spawnType == 0x6e) {
        node.x = parent.x + offsetX;
        node.y = parent.y + offsetY;
    }
    else {
        const double radians = fixedAngleRadians(angle16);
        node.x = parent.x + static_cast<float>(std::cos(radians) * offsetX);
        node.y = parent.y + static_cast<float>(std::sin(radians) * offsetX) +
                 offsetY;
    }
    node.markerDrawX = node.x;
    node.markerDrawY = node.y;
    pendingEnemies_.push_back(node);

    // FUN_140023260 writes five after creating 0x66..0x6a. This is the
    // destructible-arm count consumed by FUN_1400270f0, not every apparatus.
    if (spawnType >= 0x66 && spawnType <= 0x6a) {
        ++parent.liveChildCount;
    }
    return true;
}

void StageRuntime::updateStage06BossNode(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawMarkerThisFrame = false;
    enemy.drawBodyThisFrame = true;
    enemy.drawHp = enemy.hp;

    StageEnemy* parent = findEnemyById(enemy.parentEntityId);
    const auto release = [this, &enemy, &parent](bool destroyed) {
        if (destroyed) {
            spawnEnemyDeathRewardBurst(enemy, 3000);
            spawnEnemyDeathEffects(enemy, 1);
        }
        if (parent != nullptr && enemy.spawnType >= 0x66 &&
            enemy.spawnType <= 0x6a && parent->liveChildCount > 0) {
            --parent->liveChildCount;
        }
        enemy.targetable = false;
        enemy.active = false;
    };
    if (parent == nullptr || !parent->active ||
        parent->spawnType != enemy.parentSpawnType) {
        release(false);
        return;
    }

    const int timer = enemy.helperTimer;
    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimAtPlayer = [this, &enemy]() {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
    };
    bool fired = false;

    if (enemy.spawnType == 0x64 || enemy.spawnType == 0x65) {
        if (parent->helperState > 4 ||
            (parent->helperState == 4 && parent->helperTimer >= 130)) {
            release(false);
            return;
        }
        const int side = enemy.spawnType == 0x64 ? -1 : 1;
        const auto mountAngle = normalizeAngle16(
            static_cast<int>(parent->sourceAngle16) + side * 0x4000);
        const double radians = fixedAngleRadians(mountAngle);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * 75.0);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * 75.0);
        enemy.sourceAngle16 = mountAngle;
        if (parent->helperState == 3 && parent->helperTimer == 30 &&
            enemy.liveChildCount == 0) {
            if (spawnStage06BossNode(enemy,
                                     enemy.spawnType == 0x64 ? 0x6c : 0x6d,
                                     0, 0.0f, 0.0f, mountAngle, 50)) {
                enemy.liveChildCount = 1;
            }
        }
        return;
    }

    if (enemy.spawnType >= 0x66 && enemy.spawnType <= 0x6a) {
        if (parent->helperState > 1 || lateStageBossCountdown_ < 1) {
            release(false);
            return;
        }
        if (enemy.helperState == 0 && parent->helperState == 1) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.hp = 33000;
            enemy.maxHp = 33000;
            enemy.drawHp = 33000;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            return;
        }

        const int index = enemy.spawnType - 0x66;
        const auto mountAngle = normalizeAngle16(
            static_cast<int>(parent->sourceAngle16) +
            index * 0x3333 + 0x4000);
        const double radians = fixedAngleRadians(mountAngle);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * 75.0);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * 75.0);
        enemy.sourceAngle16 = mountAngle;
        if (enemy.helperState != 1) {
            return;
        }
        if (enemy.hp < 1) {
            release(true);
            return;
        }

        static constexpr std::array<int, 5> kPhaseStart{{
            120, 240, 360, 480, 0,
        }};
        static constexpr std::array<int, 5> kVisual{{10, 3, 7, 4, 9}};
        const int start = kPhaseStart[static_cast<std::size_t>(index)];
        const int period = std::max(225, (3 + parent->liveChildCount) * 75);
        if (timer >= start) {
            const int local = (timer - start) % period;
            const int cadence = std::max(5, 18 - difficulty * 2);
            if (local < 75 && local % cadence == 0) {
                const int count = 5 + difficulty * 2;
                const auto center = index == 1 || index == 3
                                        ? aimAtPlayer()
                                        : normalizeAngle16(
                                              timer * (0x80 + index * 0x18));
                spawnProjectileSpread(
                    kVisual[static_cast<std::size_t>(index)], 0,
                    enemy.x, enemy.y, center, 10.0f,
                    5.0 + difficulty * 0.7, 1, count,
                    index == 0 || index == 4 ? 0x10000 : 0x7530, 0);
                fired = true;
            }
        }
    }
    else if (enemy.spawnType == 0x6b) {
        if (parent->helperState != 3) {
            release(false);
            return;
        }
        const double radians = fixedAngleRadians(parent->sourceAngle16);
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * 90.0);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * 90.0);
        enemy.sourceAngle16 = parent->sourceAngle16;

        static constexpr std::array<int, 5> kWindow{{40, 55, 65, 75, 65}};
        static constexpr std::array<int, 5> kCount{{5, 7, 7, 7, 9}};
        static constexpr std::array<double, 5> kSpeed{{5.5, 6.4, 7.0, 7.5, 8.0}};
        if (timer < 300) {
            const int local = timer % 100;
            if (local < kWindow[static_cast<std::size_t>(difficulty)] &&
                local % 5 == 0) {
                const auto aimed = aimAtPlayer();
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      normalizeAngle16(static_cast<int>(aimed) + 300),
                                      10.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                                      1, kCount[static_cast<std::size_t>(difficulty)],
                                      30000, 0);
                spawnProjectileSpread(10, 0, enemy.x, enemy.y,
                                      normalizeAngle16(static_cast<int>(aimed) - 300),
                                      10.0f, kSpeed[static_cast<std::size_t>(difficulty)],
                                      1, kCount[static_cast<std::size_t>(difficulty)],
                                      30000, 0);
                fired = true;
            }
        }
        else if (timer >= 600 && (timer - 600) % 5 == 0) {
            spawnProjectileSpread(0x0b, 0, enemy.x, enemy.y,
                                  aimAtPlayer(), 10.0f, 12.0, 1, 4,
                                  18000, 0);
            fired = true;
        }
    }
    else if (enemy.spawnType == 0x6c || enemy.spawnType == 0x6d) {
        if (parent->spawnType != 0x64 && parent->spawnType != 0x65) {
            release(false);
            return;
        }
        enemy.x = parent->x;
        enemy.y = parent->y;
        enemy.sourceAngle16 = parent->sourceAngle16;
        const int cadence = std::max(4, 9 - difficulty);
        if (timer >= 40 && timer < 770 && timer % cadence == 0) {
            const int visual = enemy.spawnType == 0x6c ? 3 : 4;
            const int direction = enemy.spawnType == 0x6c ? -1 : 1;
            const auto center = normalizeAngle16(
                static_cast<int>(aimAtPlayer()) + direction *
                    static_cast<int>(lateStageScriptRand(timer) % 5000u));
            spawnProjectileSpread(visual, 0, enemy.x, enemy.y, center,
                                  10.0f, 4.8 + difficulty * 0.6, 1,
                                  5 + difficulty, 20000, 0);
            fired = true;
        }
    }
    else if (enemy.spawnType == 0x6e) {
        if (parent->helperState != 5) {
            release(false);
            return;
        }
        enemy.x = parent->x + enemy.originX;
        enemy.y = parent->y + enemy.originY;
        enemy.sourceAngle16 = aimAtPlayer();
        if (enemy.helperState == 0 && timer >= 40) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            return;
        }
        if (enemy.helperState == 1) {
            const int local = timer % 1200;
            const int cadence = std::max(8, 24 - difficulty * 3);
            if (local >= 240 && local < 1160 && local % cadence == 0) {
                const bool alternate = ((local / cadence) & 1) != 0;
                spawnProjectileSpread(alternate ? 5 : 6, alternate ? 1 : 0,
                                      enemy.x, enemy.y, aimAtPlayer(), 10.0f,
                                      4.5 + difficulty * 0.65, 1,
                                      5 + difficulty * 2,
                                      alternate ? 4000 : 22000, 0);
                fired = true;
            }
        }
    }
    else { // 0x6f, FUN_14002aac0
        if (parent->helperState != 7) {
            release(false);
            return;
        }
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        const float radial = enemy.helperState == 0
                                 ? static_cast<float>(
                                       std::sin(std::min(timer, 40) * kPi / 80.0) *
                                       160.0)
                                 : 160.0f;
        enemy.x = parent->x + static_cast<float>(std::cos(radians) * radial);
        enemy.y = parent->y + static_cast<float>(std::sin(radians) * radial);
        if (enemy.helperState == 0 && parent->targetableTimer >= 160) {
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            return;
        }
        if (enemy.helperState == 1) {
            const int cadence = difficulty == 0 ? 90 : 60;
            if (timer % cadence == 0) {
                spawnProjectileSpread(5, timer & 1, enemy.x, enemy.y,
                                      aimAtPlayer(), 10.0f,
                                      4.0 + difficulty * 0.65, 1,
                                      5 + difficulty * 2, 4000, 0);
                fired = true;
            }
        }
    }

    if (fired) {
        playPlayerSound(bullet2SoundHandle_, 0x13);
    }
}

void StageRuntime::updateStage06Boss(StageEnemy& enemy) {
    const int difficulty = std::clamp(config_.difficulty, 0, 4);

    if (lateStageBossPhaseMode_ == 1 &&
        (enemy.hp < 1 || lateStageBossCountdown_ < 1)) {
        enemy.targetable = false;
        enemy.targetableTimer = 0;
        enemyProjectiles_.clear();
        spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
        enemy.helperTimer = 0;
        switch (lateStageBossBreaksRemaining_) {
        case 5: enemy.helperState = 2; lateStageBossPhaseMode_ = 2; break;
        case 4: enemy.helperState = 4; lateStageBossPhaseMode_ = 2; break;
        case 3: enemy.helperState = 6; lateStageBossPhaseMode_ = 2; break;
        case 2: enemy.helperState = 8; lateStageBossPhaseMode_ = 2; break;
        case 1:
            enemy.helperState = 10;
            lateStageBossPhaseMode_ = -1;
            lateStageClearStarted_ = true;
            lateStageClearTimer_ = 0;
            player_.invulnerableFrames =
                std::max(player_.invulnerableFrames, 360);
            break;
        default: break;
        }
        lateStageBossBreaksRemaining_ =
            std::max(0, lateStageBossBreaksRemaining_ - 1);
    }

    if (frame_ % 50 == 0) {
        lateStageBossTargetX_ = 210.0f + static_cast<float>(
            lateBossFrameRand(frame_) % 301u);
        lateStageBossTargetY_ = 140.0f + static_cast<float>(
            lateBossFrameRand(selectedStage_ * 0xde + frame_) % 101u);
    }

    const auto steerAndMove = [this, &enemy](double speed) {
        const auto target = radiansToAngle16(std::atan2(
            static_cast<double>(lateStageBossTargetY_ - enemy.y),
            static_cast<double>(lateStageBossTargetX_ - enemy.x)));
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, target, 0x200);
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        enemy.x += static_cast<float>(std::cos(radians) * speed);
        enemy.y += static_cast<float>(std::sin(radians) * speed);
    };
    const auto openPhase = [this, &enemy](int state, int hitPoints,
                                          int countdown, double speed,
                                          int phaseIndex) {
        enemy.helperState = state;
        enemy.helperTimer = 0;
        enemy.hp = hitPoints;
        enemy.maxHp = hitPoints;
        enemy.drawHp = hitPoints;
        enemy.sourceSpeed = speed;
        enemy.speed = static_cast<float>(speed);
        enemy.targetable = true;
        enemy.targetableTimer = 0;
        lateStageBossMaxHp_ = hitPoints;
        lateStageBossCountdown_ = countdown;
        lateStageBossPhaseIndex_ = phaseIndex;
        lateStageBossPhaseMode_ = 1;
    };

    const int timer = enemy.helperTimer;
    switch (enemy.helperState) {
    case 0: {
        if (timer == 0) {
            playPlayerSound(bossSe8SoundHandle_, 0x19);
        }
        if (timer >= 60 && timer < 160) {
            const double t = static_cast<double>(timer - 60) / 100.0;
            const double ease = std::sin(t * kPi * 0.5);
            enemy.x = 480.0f + static_cast<float>((360.0 - 480.0) * ease) +
                      static_cast<float>(std::sin(t * kPi) * 45.0);
            enemy.y = 150.0f + static_cast<float>((240.0 - 150.0) * ease) -
                      static_cast<float>(std::sin(t * kPi) * 30.0);
        }
        else if (timer >= 160) {
            enemy.y += 0.1f;
        }

        static constexpr std::array<int, 5> kTypes{{
            0x6a, 0x69, 0x68, 0x67, 0x66,
        }};
        static constexpr std::array<int, 5> kAngleOrder{{3, 1, 4, 2, 8}};
        for (int i = 0; i < 5; ++i) {
            if (timer == 150 + i * 10) {
                spawnStage06BossNode(
                    enemy, kTypes[static_cast<std::size_t>(i)], i,
                    75.0f, 0.0f,
                    normalizeAngle16(kAngleOrder[static_cast<std::size_t>(i)] *
                                         0x3333 + 0x4000),
                    60);
            }
        }
        if (timer == 220) {
            spawnStage06BossNode(enemy, 0x64, 0, 75.0f, 0.0f,
                                 0x8000, 40);
            spawnStage06BossNode(enemy, 0x65, 1, 75.0f, 0.0f,
                                 0x8000, 40);
        }
        if (timer == 240) {
            openPhase(1, 100000, 3600, 0.3, 0);
        }
        break;
    }
    case 1:
        steerAndMove(0.3);
        break;
    case 2:
        if (timer < 90) {
            enemy.y += static_cast<float>(timer) * 0.01f;
        }
        if (timer == 100) {
            enemy.sourceSpeed = 1.6;
            enemy.speed = 1.6f;
        }
        if (timer >= 100) {
            steerAndMove(1.6);
        }
        if (timer == 180) {
            openPhase(3, 86000, 2100, 1.6, 1);
        }
        break;
    case 3:
        steerAndMove(1.6);
        if (timer == 30) {
            spawnStage06BossNode(enemy, 0x6b, 0, 90.0f, 0.0f,
                                 0x4000, 40);
        }
        break;
    case 4:
        if (timer < 120) {
            enemy.y += static_cast<float>(timer) * 0.02f;
        }
        if (timer == 130) {
            enemy.y -= 75.0f;
            enemy.sourceSpeed = 0.6;
            enemy.speed = 0.6f;
        }
        if (timer >= 130) {
            steerAndMove(0.6);
        }
        if (timer == 380) {
            openPhase(5, 68000, 1800, 0.6, 2);
        }
        break;
    case 5:
        steerAndMove(0.6);
        if (timer == 10) {
            static constexpr std::array<float, 4> kOffsetX{{
                100.0f, -100.0f, 210.0f, -210.0f,
            }};
            static constexpr std::array<float, 4> kOffsetY{{
                -120.0f, -120.0f, -70.0f, -70.0f,
            }};
            for (int i = 0; i < 4; ++i) {
                spawnStage06BossNode(
                    enemy, 0x6e, i,
                    kOffsetX[static_cast<std::size_t>(i)],
                    kOffsetY[static_cast<std::size_t>(i)],
                    0x4000, 40);
            }
            playPlayerSound(bossSe8SoundHandle_, 0x19);
        }
        break;
    case 6:
    case 8:
        enemy.y += 0.1f;
        if (timer == 1) {
            playPlayerSound(enemyDown3SoundHandle_, 0x19);
        }
        if (timer < 90) {
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 180) {
            if (enemy.helperState == 6) {
                openPhase(7, 70000, 2100, 0.6, 3);
            }
            else {
                openPhase(9, 80000, 2100, 0.6, 4);
            }
        }
        break;
    case 7: {
        steerAndMove(0.6);
        static constexpr std::array<int, 5> kCount{{17, 21, 25, 25, 27}};
        const int count = kCount[static_cast<std::size_t>(difficulty)];
        const int step = std::max(1, 100 / count);
        for (int i = 0; i < count; ++i) {
            if (timer == 10 + i * step) {
                spawnStage06BossNode(
                    enemy, 0x6f, i, 0.0f, 0.0f,
                    normalizeAngle16(i * (0x10000 / count) - 0x4000),
                    40);
            }
        }
        break;
    }
    case 9: {
        steerAndMove(0.6);
        const int baseInterval = difficulty == 0 ? 120 : 100;
        const int switchFrame = (baseInterval + 12) * 5;
        const int interval = timer >= switchFrame
                                 ? baseInterval / 2
                                 : baseInterval;
        if (timer > 59 && (timer - 60) % interval == 0) {
            const bool firstFamily = timer < switchFrame
                                         ? (timer - 60) % (interval * 2) == 0
                                         : (lateStageScriptRand(timer) & 1u) == 0u;
            static constexpr std::array<int, 5> kRingCount{{
                15, 19, 21, 12, 9,
            }};
            const int count = kRingCount[static_cast<std::size_t>(difficulty)];
            const std::uint32_t random = lateStageScriptRand(timer);
            const auto baseAngle = normalizeAngle16(static_cast<int>(
                random - random / 0x10001u));
            const int visual = firstFamily ? 2 : 3;
            const int projectileId = firstFamily ? 0x1f : 0x20;
            const int direction = firstFamily ? -1 : 1;
            const int extraLayers = difficulty == 4 ? 4 :
                                    (difficulty == 3 ? 2 : 0);
            for (int layer = 0; layer <= extraLayers; ++layer) {
                const auto angle = normalizeAngle16(
                    static_cast<int>(baseAngle) + direction * layer * 0x4b0);
                for (int i = 0; i < count; ++i) {
                    spawnProjectileNode(
                        visual, projectileId, enemy.x - 33.0f,
                        enemy.y - 83.0f,
                        normalizeAngle16(static_cast<int>(angle) +
                                         i * (0x10000 / count)),
                        0.0f, 0.0, 1, 0);
                }
            }
            playPlayerSound(bullet2SoundHandle_, 0x13);
        }
        break;
    }
    case 10:
        enemy.targetable = false;
        if (timer < 240) {
            enemy.y += 0.2f;
            spawnStage02DeathExplosionChain(enemy);
        }
        if (timer == 240) {
            playPlayerSound(blast2SoundHandle_, 0x19);
            spawnEnemyDeathEffects(enemy, 2);
        }
        if (timer >= 480) {
            clearLateStageGate(6);
            enemy.active = false;
        }
        break;
    default:
        break;
    }

    enemy.drawHp = enemy.hp;
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;
    if (lateStageBossPhaseMode_ == 1) {
        updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
        --lateStageBossCountdown_;
    }
}

void StageRuntime::updateLateStageBoss(StageEnemy& enemy) {
    enemy.vx = 0.0f;
    enemy.vy = 0.0f;
    enemy.drawBodyThisFrame = true;
    enemy.drawMarkerThisFrame = false;
    enemy.drawHp = enemy.hp;

    if (isStage06BossNodeType(enemy.spawnType)) {
        updateStage06BossNode(enemy);
        return;
    }
    if (isStage10FinalBossNodeType(enemy.spawnType)) {
        updateStage10FinalBossNode(enemy);
        return;
    }
    lateStageBossCountdownDraw_ = lateStageBossCountdown_;

    const LateBossSpec* spec = lateBossSpec(enemy.spawnType);
    if (spec == nullptr) {
        enemy.active = false;
        return;
    }
    if (enemy.spawnType == 0x13d) {
        updateStage06Boss(enemy);
        return;
    }
    if (enemy.spawnType == 0x13c) {
        updateStage05Boss(enemy);
        return;
    }

    const auto playBossTrack = [this](int oldIndex, int newIndex) {
        if (oldIndex >= 0 && oldIndex < static_cast<int>(bossBgmHandles_.size())) {
            const int oldHandle = bossBgmHandles_[static_cast<std::size_t>(oldIndex)];
            if (oldHandle != -1) StopSoundMem(oldHandle);
        }
        if (newIndex >= 0 && newIndex < static_cast<int>(bossBgmHandles_.size())) {
            activeBossBgmIndex_ = newIndex;
            const int handle = bossBgmHandles_[static_cast<std::size_t>(newIndex)];
            if (handle != -1) {
                ChangeVolumeSoundMem(static_cast<int>(config_.bgmVolume * 25.5), handle);
                PlaySoundMem(handle, DX_PLAYTYPE_LOOP, TRUE);
            }
        }
    };

    const int difficulty = std::clamp(config_.difficulty, 0, 4);
    const auto aimAtPlayer16 = [this, &enemy]() {
        return radiansToAngle16(std::atan2(
            static_cast<double>(player_.y - enemy.y),
            static_cast<double>(player_.x - enemy.x)));
    };
    const auto emitBossPattern = [this, &enemy, difficulty, &aimAtPlayer16]() {
        const int timer = enemy.helperTimer;
        const int phase = std::max(0, lateStageBossPhaseIndex_);
        const int baseInterval = std::max(12, 58 - difficulty * 6 - (phase % 4) * 3);
        if (timer % baseInterval == 0) {
            const int count = std::min(31, 7 + difficulty * 2 + (phase % 5) * 2);
            const float rotation = static_cast<float>(timer * (0.025 + phase * 0.002));
            spawnProjectileSpread((enemy.spawnType + phase) % 10, 2,
                                  enemy.x, enemy.y, rotation,
                                  2.7 + difficulty * 0.45 + phase * 0.08,
                                  7, count, static_cast<float>(kTau));
            playPlayerSound(bullet2SoundHandle_, 0x10);
        }
        const int aimedInterval = std::max(18, 90 - difficulty * 8 - (phase % 3) * 6);
        if (timer % aimedInterval == aimedInterval / 2) {
            const int count = 3 + difficulty * 2 + (phase & 1) * 2;
            spawnProjectileSpread(1 + ((enemy.spawnType + phase) & 7),
                                  phase % 3 == 2 ? 8 : 0,
                                  enemy.x, enemy.y,
                                  fixedAngleRadians(aimAtPlayer16()),
                                  4.3 + difficulty * 0.65 + phase * 0.06,
                                  5, count, 0.8f + (phase % 4) * 0.12f);
            playPlayerSound(bullet1SoundHandle_, 0x10);
        }
    };

    if (enemy.spawnType == 0x14c) {
        if (enemy.helperState == 0 && config_.rawStartFrame >= 12000) {
            // FUN_1400ef010 forces late practice starts straight to state 7 at
            // timer 0xf0 so the 0x141 handoff happens on this update.
            enemy.helperState = 7;
            enemy.helperTimer = 240;
            enemy.targetable = false;
            lateStageBossBreaksRemaining_ = 0;
            lateStageBossPhaseMode_ = -1;
            stage10GateFlag_ = true;
        }
        const auto beginSceneBossBreak = [this, &enemy]() {
            if (enemy.hp > 0 && lateStageBossCountdown_ > 0) {
                return false;
            }

            enemy.targetable = false;
            enemy.targetableTimer = 0;
            enemyProjectiles_.clear();
            spawnEnemyDeathRewardBurst(enemy, 0x708);
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            if (lateStageBossBreaksRemaining_ == 3) {
                lateStageBossBreaksRemaining_ = 2;
                lateStageBossPhaseIndex_ = 1;
                lateStageBossPhaseMode_ = 2;
                enemy.helperState = 3;
            }
            else if (lateStageBossBreaksRemaining_ == 2) {
                lateStageBossBreaksRemaining_ = 1;
                lateStageBossPhaseIndex_ = 2;
                lateStageBossPhaseMode_ = 2;
                enemy.helperState = 5;
            }
            else {
                lateStageBossBreaksRemaining_ = 0;
                lateStageBossPhaseMode_ = -1;
                enemy.helperState = 7;
                for (const int handle : stageBgmHandles_) {
                    if (handle != -1) StopSoundMem(handle);
                }
                for (const int handle : bossBgmHandles_) {
                    if (handle != -1) StopSoundMem(handle);
                }
                activeBossBgmIndex_ = -1;
            }
            enemy.helperTimer = 0;
            return true;
        };

        if (enemy.helperState == 0 || enemy.helperState == 1) {
            const bool preAttackState = enemy.helperState == 1;
            if (preAttackState) {
                stage10GateFlag_ = true;
                enemy.targetable = true;
                if (beginSceneBossBreak()) {
                    return;
                }
            }

            float targetX = 360.0f;
            float targetY = -2400.0f;
            if (frame_ < 1200) {
                // Keep the constructor anchor until the first recovered window.
            }
            else if (frame_ < 3000) {
                targetY = -2400.0f + static_cast<float>(
                    std::sin((frame_ - 1200) * kTau / 3600.0) * 800.0);
            }
            else if (frame_ < 4700) {
                targetY = -1600.0f + static_cast<float>(
                    std::sin((frame_ - 3000) * kTau / 3400.0) * 850.0);
            }
            else if (frame_ < 6600) {
                const double wave = std::sin((frame_ - 4700) * kTau / 3800.0);
                targetX = 360.0f - static_cast<float>(wave * 560.0);
                targetY = -735.0f + static_cast<float>(wave * 100.0);
            }
            else if (frame_ < 8500) {
                const double wave = std::sin((frame_ - 6600) * kTau / 3800.0);
                targetX = -200.0f + static_cast<float>(wave * 1120.0);
                targetY = -500.0f + static_cast<float>(
                    std::sin((frame_ - 6600) * kTau / 1900.0) * 180.0);
            }
            else if (frame_ < 9100) {
                const double wave = std::sin((frame_ - 8500) * kTau / 1200.0);
                targetX = 920.0f - static_cast<float>(wave * 560.0);
                targetY = -600.0f - static_cast<float>(wave * 100.0);
            }
            else if (frame_ < 11300) {
                targetY = -700.0f + static_cast<float>(
                    std::sin((frame_ - 9100) * kTau / 4400.0) * 450.0);
            }
            else if (frame_ < 12000) {
                targetY = -250.0f + static_cast<float>(
                    std::sin((frame_ - 11300) * kTau / 1400.0) * 400.0);
            }
            else {
                targetY = 150.0f;
            }
            targetX += static_cast<float>(std::sin(frame_ * kTau / 180.0) * 18.0);
            enemy.x += (targetX - enemy.x) * 0.2f;
            enemy.y += (targetY - enemy.y) * 0.2f;
            if (!preAttackState) {
                enemy.targetable = false;
                stage10GateFlag_ = false;
            }

            // FUN_1400ef010 enters the 55k pre-attack state on any update in
            // 11900..11910. This also covers the rawStartFrame+1 practice spawn.
            if (!preAttackState && frame_ >= 11900 && frame_ < 11911) {
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.hp = 55000;
                enemy.maxHp = 55000;
                enemy.drawHp = 55000;
                lateStageBossMaxHp_ = 55000;
                lateStageBossCountdown_ = 1500;
                lateStageBossCountdownDraw_ = lateStageBossCountdown_;
                lateStageBossPhaseMode_ = 0;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
                stage10GateFlag_ = true;
            }
            else if (preAttackState && frame_ == 12000) {
                // The original processes state 1 for frame 12000, then advances;
                // state 2 must not emit until the following entity update.
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                lateStageBossPhaseMode_ = 1;
            }
            if (preAttackState && lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
        }
        else if (enemy.helperState == 2 || enemy.helperState == 4 ||
                 enemy.helperState == 6) {
            stage10GateFlag_ = true;
            enemy.targetable = true;
            if (beginSceneBossBreak()) {
                return;
            }

            const float orbit = static_cast<float>(enemy.helperTimer) * 0.012f +
                                static_cast<float>(enemy.helperState);
            const float targetX = 360.0f + std::sin(orbit) * 115.0f;
            const float targetY = 150.0f + std::cos(orbit * 0.73f) * 55.0f;
            enemy.x += (targetX - enemy.x) * 0.035f;
            enemy.y += (targetY - enemy.y) * 0.035f;
            emitBossPattern();
            if (lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
        }
        else if (enemy.helperState == 3 || enemy.helperState == 5) {
            enemy.targetable = false;
            stage10GateFlag_ = true;
            if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer >= 120) {
                const bool secondTransition = enemy.helperState == 5;
                enemy.helperState = secondTransition ? 6 : 4;
                enemy.helperTimer = 0;
                enemy.hp = secondTransition ? 66000 : 55000;
                enemy.maxHp = enemy.hp;
                enemy.drawHp = enemy.hp;
                lateStageBossMaxHp_ = enemy.hp;
                lateStageBossCountdown_ = secondTransition ? 1800 : 1500;
                lateStageBossCountdownDraw_ = lateStageBossCountdown_;
                lateStageBossPhaseMode_ = 1;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
        }
        else if (enemy.helperState == 7) {
            enemy.targetable = false;
            stage10GateFlag_ = true;
            if (enemy.helperTimer < 150) {
                enemy.y += static_cast<float>(enemy.helperTimer) * 0.01f;
            }
            if (enemy.helperTimer < 150 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer == 150) {
                playPlayerSound(blast2SoundHandle_, 0x19);
                enemyProjectiles_.clear();
                spawnEnemyDeathEffects(enemy, 2);
            }
            if (enemy.helperTimer >= 240 && !stage10FinalBossSpawned_) {
                if (activeBossBgmIndex_ != 4) {
                    const int stageHandle = stageBgmHandles_[9];
                    if (stageHandle != -1) {
                        StopSoundMem(stageHandle);
                    }
                    playBossTrack(-1, 4);
                }
                const std::size_t before = enemies_.size();
                spawnEnemy({frame_, 0x141, 100000, 360, 320,
                            "S10 FUN_1400ef010 state-7 timer 240 final root 0x141"});
                if (enemies_.size() > before) {
                    stage10FinalBossSpawned_ = true;
                    enemy.active = false;
                }
            }
        }
        return;
    }

    if (enemy.spawnType == 0x141) {
        constexpr std::array<int, 16> kPhaseHp{{
            75000, 70000, 65000, 50000, 75000, 50000, 60000, 100000,
            45000, 80000, 65000, 75000, 85000, 128000, 32000, 270000,
        }};
        constexpr std::array<int, 16> kPhaseCountdown{{
            2400, 2400, 2100, 2400, 2400, 2400, 2100, 3300,
            2100, 2400, 2400, 2400, 2400, 3300, 5400, 6000,
        }};
        constexpr std::array<int, 17> kBreakModeByRemaining{{
            -1, -1, 3, 3, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3,
        }};
        constexpr std::array<int, 16> kTransitionCompleteMode{{
            0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1,
        }};
        if (enemy.helperState == 0) {
            const double t = smoothStep(static_cast<double>(enemy.helperTimer) / 260.0);
            enemy.x = spec->spawnX;
            enemy.y = spec->spawnY +
                      static_cast<float>((spec->targetY - spec->spawnY) * t);
            if (enemy.helperTimer >= 260) {
                enemy.x = spec->targetX;
                enemy.y = spec->targetY;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.hp = kPhaseHp[0];
                enemy.maxHp = enemy.hp;
                enemy.drawHp = enemy.hp;
                enemy.targetable = true;
                enemy.targetableTimer = 0;
                lateStageBossBreaksRemaining_ = 16;
                lateStageBossPhaseIndex_ = 0;
                lateStageBossMaxHp_ = enemy.hp;
                lateStageBossCountdown_ = kPhaseCountdown[0];
                lateStageBossCountdownDraw_ = lateStageBossCountdown_;
                lateStageBossPhaseMode_ = 1;
            }
            return;
        }

        const bool combatState = enemy.helperState == 1 ||
            (enemy.helperState >= 11 && enemy.helperState <= 151 &&
             enemy.helperState % 10 == 1);
        if (combatState) {
            if (enemy.hp < 1 || lateStageBossCountdown_ < 1) {
                enemy.targetable = false;
                enemy.targetableTimer = 0;
                enemyProjectiles_.clear();
                spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
                if (lateStageBossBreaksRemaining_ > 1) {
                    const int remaining = std::clamp(lateStageBossBreaksRemaining_, 2, 16);
                    enemy.helperState = (17 - remaining) * 10;
                    lateStageBossPhaseMode_ =
                        kBreakModeByRemaining[static_cast<std::size_t>(remaining)];
                    --lateStageBossBreaksRemaining_;
                    ++lateStageBossPhaseIndex_;
                }
                else {
                    lateStageBossBreaksRemaining_ = 0;
                    enemy.helperState = 200;
                    lateStageBossPhaseMode_ = -1;
                    lateStageClearStarted_ = true;
                    lateStageClearTimer_ = 0;
                    player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
                }
                enemy.helperTimer = 0;
                return;
            }

            if (frame_ % 50 == 0) {
                lateStageBossTargetX_ = 210.0f + static_cast<float>(
                    lateBossFrameRand(frame_) % 301u);
                lateStageBossTargetY_ = 180.0f + static_cast<float>(
                    lateBossFrameRand(selectedStage_ * 0x457 + frame_) % 101u);
            }
            const auto targetAngle = radiansToAngle16(std::atan2(
                static_cast<double>(lateStageBossTargetY_ - enemy.y),
                static_cast<double>(lateStageBossTargetX_ - enemy.x)));
            enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, targetAngle, 0x200);
            const double radians = fixedAngleRadians(enemy.sourceAngle16);
            const double motionSpeed = 0.4 + lateStageBossPhaseIndex_ * 0.025;
            enemy.x += static_cast<float>(std::cos(radians) * motionSpeed);
            enemy.y += static_cast<float>(std::sin(radians) * motionSpeed);
            emitBossPattern();
            if (enemy.helperTimer == 30) {
                int nodeType = 0;
                switch (enemy.helperState) {
                case 11:  nodeType = 0x111; break;
                case 31:  nodeType = 0x112; break;
                case 51:  nodeType = 0x113; break;
                case 71:  nodeType = 0x115; break;
                case 91:  nodeType = 0x11a; break;
                case 111: nodeType = 0x11d; break;
                default: break;
                }
                if (nodeType != 0) {
                    spawnStage10FinalBossNode(enemy, nodeType);
                }
            }
            if (lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
            return;
        }

        if (enemy.helperState >= 10 && enemy.helperState <= 150 &&
            enemy.helperState % 10 == 0) {
            if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            const int transitionIndex = enemy.helperState / 10;
            const int transitionLength = (transitionIndex & 1) != 0 ? 180 : 200;
            if (enemy.helperTimer >= transitionLength) {
                const int phase = std::clamp(lateStageBossPhaseIndex_, 0, 15);
                ++enemy.helperState;
                enemy.helperTimer = 0;
                enemy.hp = kPhaseHp[static_cast<std::size_t>(phase)];
                enemy.maxHp = enemy.hp;
                enemy.drawHp = enemy.hp;
                lateStageBossMaxHp_ = enemy.hp;
                lateStageBossCountdown_ = kPhaseCountdown[static_cast<std::size_t>(phase)];
                lateStageBossCountdownDraw_ = lateStageBossCountdown_;
                lateStageBossPhaseMode_ =
                    kTransitionCompleteMode[static_cast<std::size_t>(transitionIndex)];
                enemy.targetable = true;
                enemy.targetableTimer = 0;
            }
            return;
        }

        if (enemy.helperState == 200) {
            enemy.targetable = false;
            if (enemy.helperTimer < 180 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            if (enemy.helperTimer == 240) {
                playPlayerSound(blast2SoundHandle_, 0x19);
                spawnEnemyDeathEffects(enemy, 2);
            }
            if (enemy.helperTimer >= 480) {
                clearLateStageGate(selectedStage_);
                enemy.active = false;
            }
            return;
        }
    }

    if (!isLateStageFinalBossType(enemy.spawnType)) {
        if (enemy.helperState == 0) {
            const double t = smoothStep(static_cast<double>(enemy.helperTimer) / 120.0);
            enemy.x += (spec->targetX - enemy.x) * static_cast<float>(0.03 + t * 0.05);
            enemy.y += (spec->targetY - enemy.y) * static_cast<float>(0.03 + t * 0.05);
            if (enemy.helperTimer >= 119) {
                enemy.x = spec->targetX;
                enemy.y = spec->targetY;
                enemy.helperState = 1;
                enemy.helperTimer = 0;
                enemy.targetable = true;
                lateStageBossPhaseIndex_ = 0;
                lateStageBossCountdown_ = 1800;
                lateStageBossCountdownDraw_ = lateStageBossCountdown_;
                lateStageBossMaxHp_ = enemy.maxHp;
            }
        }
        else if (enemy.helperState == 1) {
            if (enemy.hp < 1 || lateStageBossCountdown_ < 1) {
                if (enemy.spawnType >= 0x146 && enemy.spawnType <= 0x14b) {
                    const std::size_t index = static_cast<std::size_t>(enemy.spawnType - 0x146);
                    if (stage09BossDefeatFrames_[index] < 0) {
                        stage09BossDefeatFrames_[index] = frame_;
                    }
                }
                enemy.targetable = false;
                enemy.helperState = 2;
                enemy.helperTimer = 0;
                enemyProjectiles_.clear();
                spawnEnemyDeathRewardBurst(enemy, 0x708);
                spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
                return;
            }
            const float orbit = static_cast<float>(enemy.helperTimer) * 0.018f +
                                static_cast<float>(enemy.spawnType & 7);
            enemy.x += (spec->targetX + std::sin(orbit) * 110.0f - enemy.x) * 0.035f;
            enemy.y += (spec->targetY + std::cos(orbit * 0.7f) * 45.0f - enemy.y) * 0.035f;
            emitBossPattern();
            if (lateStageBossCountdown_ > 0) {
                updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
                --lateStageBossCountdown_;
            }
        }
        else {
            if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
                spawnStage02DeathExplosionChain(enemy);
            }
            enemy.y += 0.15f;
            const int deathDuration =
                enemy.spawnType >= 0x146 && enemy.spawnType <= 0x14b ? 150 : 120;
            if (enemy.helperTimer >= deathDuration) {
                spawnEnemyDeathEffects(enemy, 2);
                clearLateStageGate(selectedStage_);
                enemy.active = false;
            }
        }
        return;
    }

    if (enemy.helperState == 0) {
        const double t = smoothStep(static_cast<double>(enemy.helperTimer) / 120.0);
        enemy.x = spec->spawnX;
        enemy.y = spec->spawnY + static_cast<float>((1.0 - t) * 300.0);
        if (enemy.helperTimer >= 119) {
            enemy.x = spec->spawnX;
            enemy.y = spec->spawnY;
            enemy.helperState = 1;
            enemy.helperTimer = 0;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
            enemy.hp = enemy.maxHp;
            enemy.drawHp = enemy.hp;
            lateStageBossMaxHp_ = enemy.hp;
            lateStageBossCountdown_ = 1800;
            lateStageBossCountdownDraw_ = lateStageBossCountdown_;
            lateStageBossPhaseMode_ = 1;
            lateStageBossPhaseIndex_ = 0;
        }
        return;
    }

    if ((enemy.helperState & 1) != 0) {
        if (enemy.hp < 1 || lateStageBossCountdown_ < 1) {
            enemy.targetable = false;
            enemy.targetableTimer = 0;
            enemyProjectiles_.clear();
            spawnPlayerSideObject(0x18, enemy.x, enemy.y, 0.0, 0, 0, 0.0f);
            enemy.helperState += 1; // even-numbered break/death state
            enemy.helperTimer = 0;
            if (lateStageBossBreaksRemaining_ > 1) {
                --lateStageBossBreaksRemaining_;
                ++lateStageBossPhaseIndex_;
                lateStageBossPhaseMode_ = 2;
            }
            else {
                lateStageBossBreaksRemaining_ = 0;
                lateStageBossPhaseMode_ = -1;
                lateStageClearStarted_ = true;
                lateStageClearTimer_ = 0;
                player_.invulnerableFrames = std::max(player_.invulnerableFrames, 360);
            }
            return;
        }
        if (frame_ % 50 == 0) {
            const int seed = frame_ + enemy.entityId * 97 + lateStageBossPhaseIndex_ * 53;
            lateStageBossTargetX_ = 190.0f + static_cast<float>((seed * 73) % 341);
            lateStageBossTargetY_ = 110.0f + static_cast<float>((seed * 37) % 151);
        }
        const auto targetAngle = radiansToAngle16(std::atan2(
            static_cast<double>(lateStageBossTargetY_ - enemy.y),
            static_cast<double>(lateStageBossTargetX_ - enemy.x)));
        enemy.sourceAngle16 = approachAngle16(enemy.sourceAngle16, targetAngle, 0x200);
        const double radians = fixedAngleRadians(enemy.sourceAngle16);
        const double motionSpeed = std::max(0.3, spec->speed) +
                                   static_cast<double>(lateStageBossPhaseIndex_) * 0.025;
        enemy.x += static_cast<float>(std::cos(radians) * motionSpeed);
        enemy.y += static_cast<float>(std::sin(radians) * motionSpeed);
        emitBossPattern();
        if (lateStageBossCountdown_ > 0) {
            updateBossCountdownAudio(enemy.hp, lateStageBossCountdown_);
            --lateStageBossCountdown_;
        }

        return;
    }

    if (lateStageBossBreaksRemaining_ > 0) {
        if (enemy.helperTimer < 90 && enemy.helperTimer % 3 == 0) {
            spawnStage02DeathExplosionChain(enemy);
        }
        enemy.y += 0.08f;
        if (enemy.helperTimer >= 179) {
            // Stage 8's root changes from Boss2 to Boss3 on original state
            // 10 -> 11. Odd combat/even break numbering preserves that point.
            if (enemy.spawnType == 0x13f && enemy.helperState == 10) {
                playBossTrack(1, 2);
            }
            enemy.helperState += 1;
            enemy.helperTimer = 0;
            const int baseHp = std::max(1, enemy.maxHp);
            const double phaseScale = 0.55 +
                                      0.05 * static_cast<double>(lateStageBossPhaseIndex_ % 5);
            enemy.hp = std::max(1, static_cast<int>(baseHp * phaseScale));
            enemy.drawHp = enemy.hp;
            lateStageBossMaxHp_ = enemy.hp;
            lateStageBossCountdown_ = std::max(
                900, 1800 - lateStageBossPhaseIndex_ * 35);
            lateStageBossCountdownDraw_ = lateStageBossCountdown_;
            lateStageBossPhaseMode_ = 1;
            enemy.targetable = true;
            enemy.targetableTimer = 0;
        }
        return;
    }

    if (enemy.helperTimer < 180 && enemy.helperTimer % 3 == 0) {
        spawnStage02DeathExplosionChain(enemy);
    }
    enemy.y += 0.2f;
    if (enemy.spawnType == 0x140 && enemy.helperTimer == 0x140) {
        // The Stage 9 root starts Boss4 at the recovered late-segment timer.
        playBossTrack(2, 3);
    }
    if (enemy.helperTimer == 240) {
        playPlayerSound(blast2SoundHandle_, 0x19);
        spawnEnemyDeathEffects(enemy, 2);
    }
    if (enemy.helperTimer >= 480) {
        clearLateStageGate(selectedStage_);
        enemy.active = false;
    }
}

bool StageRuntime::drawStage10FinalBossNode(const StageEnemy& enemy, float x,
                                            float y) const {
    if (!isStage10FinalBossNodeType(enemy.spawnType)) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    const int timer = enemy.drawHelperTimer;
    int alpha = 255;
    if (enemy.drawHelperState == 0) {
        alpha = std::clamp(timer * 255 / 150, 0, 255);
    }
    else if (enemy.drawHelperState == 99) {
        alpha = std::clamp((100 - timer) * 255 / 100, 0, 255);
    }
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

    bool drew = false;
    const auto drawLarge = [this, &drew](int frame, float drawX, float drawY,
                                         std::uint16_t angle = 0,
                                         bool reverseX = false,
                                         double scale = 1.0) {
        const int graph = frameHandle(enemyLargeFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  scale, scale, reverseX);
            drew = true;
        }
    };
    const auto drawMedium = [this, &drew](int frame, float drawX, float drawY,
                                          std::uint16_t angle = 0,
                                          bool reverseX = false) {
        const int graph = frameHandle(enemyMediumFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  1.0, 1.0, reverseX);
            drew = true;
        }
    };
    const auto drawSmall = [this, &drew](int frame, float drawX, float drawY,
                                         std::uint16_t angle = 0,
                                         bool reverseX = false) {
        const int graph = frameHandle(enemySmallFrames_, frame);
        if (graph != -1) {
            drawOriginalMode7Node(graph, drawX, drawY, angle,
                                  1.0, 1.0, reverseX);
            drew = true;
        }
    };

    switch (enemy.spawnType) {
    case 0x114:
        drawSmall(0xa6 + (timer / 5) % 3, x, y,
                  enemy.sourceAngle16, enemy.originX < 0.0f);
        break;
    case 0x116:
    case 0x117:
    case 0x118:
    case 0x119: {
        const int frame = 0x5a + (enemy.spawnType - 0x116);
        drawLarge(0x59, x, y + 120.0f, 0, false, 0.9);
        drawLarge(frame, x, y + 120.0f, enemy.sourceAngle16,
                  enemy.x < 360.0f);
        break;
    }
    case 0x11b:
        drawLarge(0x5f, x, y);
        break;
    case 0x11c:
        drawLarge(0x60, x - 20.0f, y, 0, true);
        drawLarge(0x60, x + 20.0f, y);
        break;
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122: {
        const int frame = enemy.spawnType == 0x11e ? 0x62 : 0x63;
        const auto angle = normalizeAngle16(static_cast<int>(
            std::atan2(-enemy.originY, -enemy.originX) *
            65536.0 / kTau));
        drawLarge(frame, x, y - 70.0f, angle, enemy.originX < 0.0f);
        break;
    }
    case 0x111:
        // DAT_140e44a48 == Enemy_l[0x4e].
        drawLarge(0x4e, x, y, enemy.sourceAngle16);
        break;
    case 0x112: {
        // FUN_14005b4a0 draws a three-link articulated body. Enemy_l[0x54]
        // is replaced by [0x57] during the shared 99-state dissolve.
        const int mainFrame = enemy.drawHelperState == 99 ? 0x57 : 0x54;
        const double swing = std::sin(timer * kTau / 140.0);
        const auto upperAngle = normalizeAngle16(
            static_cast<int>(enemy.sourceAngle16) +
            static_cast<int>(swing * 0x1000));
        drawLarge(0x56, x, y - 110.0f, upperAngle);
        drawLarge(0x55, x - 82.0f, y - 35.0f,
                  normalizeAngle16(static_cast<int>(upperAngle) - 0x1400));
        drawLarge(0x55, x + 82.0f, y - 35.0f,
                  normalizeAngle16(0x8000 - static_cast<int>(upperAngle) +
                                   0x1400), true);
        drawLarge(mainFrame, x, y, enemy.sourceAngle16);
        if (enemy.drawHelperState == 99) {
            drawLarge(0x58, x, y + static_cast<float>(timer * timer) * 0.02f,
                      normalizeAngle16(timer * 0x115c));
        }
        break;
    }
    case 0x113: {
        // The root is Enemy_m[0..2]; its four 0x114 satellites are separate
        // Enemy_s entities and therefore draw in their own list positions.
        drawMedium((timer / 5) % 3, x, y, enemy.sourceAngle16);
        break;
    }
    case 0x115:
        // FUN_14005e4e0 has no body draw; all visible parts are the real
        // 0x116..0x119 children appended by the helper.
        drew = true;
        break;
    case 0x11a:
        // Enemy_l[0x5e] is the shared-HP root. 0x11b/0x11c own [0x5f]/[0x60].
        drawLarge(0x5e, x, y, enemy.sourceAngle16);
        break;
    case 0x11d:
        // The nine batteries are separate parent-relative entities.
        drawLarge(0x61, x, y - 80.0f, enemy.sourceAngle16);
        break;
    default:
        break;
    }

    if (!drew) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(20, enemy.radius / 3),
                   GetColor(255, 96, 160), TRUE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    return true;
}

bool StageRuntime::drawLateStageBoss(const StageEnemy& enemy, float x,
                                     float y) const {
    if (!isLateStageBossType(enemy.spawnType)) {
        return false;
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }
    if (isStage06BossNodeType(enemy.spawnType)) {
        int graph = -1;
        bool large = false;
        switch (enemy.spawnType) {
        case 0x64:
            graph = frameHandle(enemyLargeFrames_, 40);
            large = true;
            break;
        case 0x65:
            graph = frameHandle(enemyMediumFrames_, 101);
            break;
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6a:
            graph = frameHandle(enemyMediumFrames_,
                                104 + enemy.spawnType - 0x66);
            break;
        case 0x6b:
        case 0x6c:
        case 0x6d:
            graph = frameHandle(enemyMediumFrames_,
                                109 + enemy.spawnType - 0x6b);
            break;
        case 0x6e:
            graph = frameHandle(enemyMediumFrames_, 112);
            break;
        case 0x6f:
            graph = frameHandle(enemySmallFrames_,
                                72 + (enemy.drawHelperTimer / 5) % 6);
            break;
        default:
            break;
        }
        if (graph != -1) {
            drawOriginalMode7Node(graph, x, y, enemy.sourceAngle16,
                                  large ? 1.0 : 1.0,
                                  large ? 1.0 : 1.0, false);
        }
        return true;
    }
    if (isStage10FinalBossNodeType(enemy.spawnType)) {
        return drawStage10FinalBossNode(enemy, x, y);
    }

    const int timer = enemy.drawHelperTimer;
    int handle = -1;
    double scale = 1.0;
    bool drewBody = false;
    bool bodyIntentionallyHidden = false;
    if (enemy.spawnType == 0x13d) {
        const int state = enemy.drawHelperState;
        if (state < 4 || (state == 4 && timer < 130)) {
            const auto drawLarge = [this, &drewBody](int frame, float drawX,
                                                      float drawY,
                                                      std::uint16_t angle,
                                                      bool reverse = false) {
                const int graph = frameHandle(enemyLargeFrames_, frame);
                if (graph != -1) {
                    drawOriginalMode7Node(graph, drawX, drawY, angle,
                                          1.0, 1.0, reverse);
                    drewBody = true;
                }
            };
            const int spin = std::max(0, frame_ - 1) * 0xb6;
            drawLarge(36, x + 75.0f, y,
                      normalizeAngle16(spin));
            drawLarge(36, x - 75.0f, y,
                      normalizeAngle16(-spin), true);
            drawLarge(37, x, y, enemy.secondaryAngle16);
            drawLarge(39, x, y, enemy.targetAngle16);
            drawLarge(38, x, y, enemy.targetAngle16);

            const int mediumFrame = state < 3 ||
                                    (state == 2 && timer < 101)
                                        ? 102
                                        : 103;
            const int medium = frameHandle(enemyMediumFrames_, mediumFrame);
            if (medium != -1) {
                const double radians = fixedAngleRadians(enemy.targetAngle16);
                drawOriginalMode7Node(
                    medium,
                    x + static_cast<float>(std::cos(radians) * 75.0),
                    y + static_cast<float>(std::sin(radians) * 75.0),
                    enemy.targetAngle16, 1.0, 1.0, false);
                drewBody = true;
            }
        }
        else {
            int bossFrame = 70;
            if (state == 10) {
                bossFrame = 78 + (timer / 5) % 2;
            }
            else if ((state & 1) != 0) {
                bossFrame = timer < 10
                                ? 73 + (timer / 5) % 2
                                : 75 + ((timer - 10) / 5) % 3;
            }
            else {
                bossFrame = 70 + (timer / 5) % 3;
            }
            handle = frameHandle(bossFrames_, bossFrame);
        }
    }
    else if (enemy.spawnType == 0x14c) {
        const auto drawLarge = [this, &drewBody](int frame, float drawX,
                                                  float drawY,
                                                  std::uint16_t angle,
                                                  bool reverseX = false) {
            const int graph = frameHandle(enemyLargeFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverseX);
                drewBody = true;
            }
        };

        // FUN_1400ef010 queues these parts with the global stage frame. draw()
        // runs after update() advances frame_, so recover the queued source tick.
        const int sourceFrame = std::max(0, frame_ - 1);
        const int upperSwing = static_cast<int>(
            std::sin((sourceFrame - 16) * kTau / 100.0) * 1600.0);
        const int leftUpperAngle = upperSwing + 0x2000;
        const double leftUpperRadians = fixedAngleRadians(
            normalizeAngle16(leftUpperAngle));
        const float upperX = static_cast<float>(
            std::cos(leftUpperRadians) * 200.0 + 150.0);
        const float upperY = static_cast<float>(
            std::sin(leftUpperRadians) * 200.0 - 120.0);
        drawLarge(70, x + upperX, y + upperY,
                  normalizeAngle16(leftUpperAngle));
        drawLarge(70, x - upperX, y + upperY,
                  normalizeAngle16(-0x2000 - upperSwing), true);

        int bodyFrame = 66;
        if (enemy.drawHelperState <= 2) bodyFrame = 63;
        else if (enemy.drawHelperState == 4) bodyFrame = 64;
        else if (enemy.drawHelperState == 6) bodyFrame = 65;
        drawLarge(bodyFrame, x, y, 0);

        const int lowerSwing = static_cast<int>(
            std::sin(sourceFrame * kTau / 100.0) * 700.0);
        drawLarge(67, x + 148.0f, y - 70.0f,
                  normalizeAngle16(lowerSwing + 0x3da8));
        drawLarge(67, x - 148.0f, y - 70.0f,
                  normalizeAngle16(-0x3da8 - lowerSwing), true);
        drawLarge(68, x,
                  y + static_cast<float>(
                      std::sin(sourceFrame * kTau / 100.0) * 2.0),
                  0);
        drawLarge(69, x,
                  y + static_cast<float>(
                      std::sin((sourceFrame - 8) * kTau / 100.0) * 2.0) -
                      100.0f,
                  0);
    }
    else if (enemy.spawnType == 0x141) {
        constexpr std::array<int, 4> kIdle{{0x91, 0x92, 0x93, 0x92}};
        constexpr std::array<int, 2> kWindup{{0x94, 0x95}};
        constexpr std::array<int, 6> kAttack{{
            0x96, 0x97, 0x98, 0x99, 0x98, 0x97,
        }};
        constexpr std::array<int, 4> kSpecial{{0x9a, 0x9b, 0x9c, 0x9d}};
        constexpr std::array<int, 2> kTransition{{0x9e, 0x9f}};

        const int state = enemy.drawHelperState;
        bodyIntentionallyHidden = (state == 142 && timer <= 40) ||
                                  (state == 200 && timer >= 60);
        int bossFrame = loopingFrame(timer, 0, 5, kIdle);
        if (state == 142) {
            bossFrame = loopingFrame(timer, 0, 5, kSpecial);
        }
        else if (state == 152 || state == 200 ||
                 (state >= 10 && state <= 150 && state % 20 == 10)) {
            bossFrame = loopingFrame(timer, 0, 5, kTransition);
        }
        else {
            // FUN_140052fb0's alternating combat families begin their override
            // at 20/30 or 30/40 ticks respectively.
            const bool delayedFamily = state >= 11 && state <= 151 &&
                                       state % 20 == 11;
            const int windupStart = delayedFamily ? 30 : 20;
            const int attackStart = windupStart + 10;
            if (timer >= attackStart) {
                bossFrame = loopingFrame(timer, attackStart, 5, kAttack);
            }
            else if (timer >= windupStart) {
                bossFrame = loopingFrame(timer, windupStart, 5, kWindup);
            }
        }
        if (!bodyIntentionallyHidden) {
            handle = frameHandle(bossFrames_, bossFrame);
        }
    }
    else if (isLateStageFinalBossType(enemy.spawnType)) {
        const int animation = (timer / 6) % 3;
        const int base = 40 + (enemy.spawnType - 0x13c) * 16;
        handle = frameHandle(bossFrames_, base + animation);
        if (handle == -1) handle = frameHandle(bossFrames_, base);
    }
    else {
        const int animation = (timer / 6) % 3;
        const int base = 16 + (enemy.spawnType - 0x143) * 9;
        handle = frameHandle(bossFrames_, base + animation);
        if (handle == -1) handle = frameHandle(enemyLargeFrames_,
                                               20 + (enemy.spawnType - 0x143) * 3);
        scale = enemy.spawnType >= 0x146 ? 1.0 : 0.85;
    }

    if (handle != -1) {
        drawOriginalMode7Node(handle, x, y, 0, scale, scale, false);
        drewBody = true;
    }
    if (!drewBody && !bodyIntentionallyHidden) {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(24, enemy.radius / 2), GetColor(255, 96, 160), TRUE);
    }

    return true;
}

bool StageRuntime::drawLateStageEnemy(const StageEnemy& enemy, float x,
                                      float y) const {
    const LateSpawnSpec* spec = lateSpawnSpec(enemy.spawnType);
    if (spec == nullptr) {
        return false;
    }

    if (enemy.drawMarkerThisFrame) {
        const int marker = frameHandle(effectMediumFrames_, 4);
        if (marker != -1) {
            const double scale = std::max(0.0, 3.0 - enemy.markerDrawTimer * 0.15);
            const float markerX = x + enemy.markerDrawX - enemy.x;
            const float markerY = y + enemy.markerDrawY - enemy.y;
            DrawRotaGraphF(markerX, markerY, scale, 0.0, marker, TRUE);
        }
    }
    if (!enemy.drawBodyThisFrame) {
        return true;
    }

    int handle = -1;
    bool large = false;
    switch (spec->updateCase) {
    case 0x1c: handle = frameHandle(enemySmallFrames_, 53); break;
    case 0x32: handle = frameHandle(enemySmallFrames_, 46); break;
    case 0x33: handle = frameHandle(enemySmallFrames_, 48); break;
    case 0x34: handle = frameHandle(enemyMediumFrames_, 75); break;
    case 0x35: handle = frameHandle(enemyMediumFrames_, 78); break;
    case 0x36: handle = frameHandle(enemyMediumFrames_, 79); break;
    case 0x37: handle = frameHandle(enemyMediumFrames_, 80); break;
    case 0x38: handle = frameHandle(enemyMediumFrames_, 81); break;
    case 0x39: handle = frameHandle(enemyMediumFrames_, 93); break;
    case 0x3a: handle = frameHandle(enemyMediumFrames_, 83); break;
    case 0x3b: handle = frameHandle(enemyLargeFrames_, 22 + (enemy.drawHelperTimer / 8) % 2); large = true; break;
    case 0x3c:
        if (enemy.spawnType == 0x50) {
            handle = frameHandle(enemyLargeFrames_, 24);
        }
        else if (enemy.spawnType == 0x51) {
            handle = frameHandle(enemyLargeFrames_,
                                 enemy.originX < 0.0f ? 26 : 25);
        }
        else {
            handle = frameHandle(enemyLargeFrames_,
                                 enemy.originX < 0.0f ? 28 : 27);
        }
        large = true;
        break;
    case 0x3d: handle = frameHandle(enemySmallFrames_, 55); break;
    case 0x41: handle = frameHandle(enemyMediumFrames_, 87 + (enemy.spawnType - 0x57)); break;
    case 0x42: handle = frameHandle(enemyMediumFrames_, 90); break;
    case 0x43: handle = frameHandle(enemySmallFrames_, 58); break;
    case 0x44: handle = frameHandle(enemySmallFrames_, 66 + (enemy.spawnType - 0x5b)); break;
    case 0x45: handle = frameHandle(enemyMediumFrames_, 91); break;
    case 0x46: handle = frameHandle(enemyMediumFrames_, 97); break;
    case 0x47: handle = frameHandle(enemyLargeFrames_, 35); large = true; break;
    case 0x4f: handle = frameHandle(enemySmallFrames_, 78 + (enemy.drawHelperTimer / 7) % 4); break;
    case 0x50: handle = frameHandle(enemyMediumFrames_, 113 + (enemy.spawnType - 0x71)); break;
    case 0x51: handle = frameHandle(enemyMediumFrames_, 115 + (enemy.drawHelperTimer / 6) % 3); break;
    case 0x52: handle = frameHandle(enemySmallFrames_, 84); break;
    case 0x53: handle = frameHandle(enemySmallFrames_, 90 + (enemy.drawHelperTimer / 5) % 2); break;
    case 0x54: handle = frameHandle(enemyMediumFrames_, 118 + (enemy.drawHelperTimer / 8) % 3); break;
    case 0x55: handle = frameHandle(enemyLargeFrames_, 41); large = true; break;
    case 0x62: handle = frameHandle(enemySmallFrames_, 119 + (enemy.drawHelperTimer / 5) % 3); break;
    case 0x63: handle = frameHandle(enemySmallFrames_, 122); break;
    case 0x64: handle = frameHandle(enemySmallFrames_, 129 + (enemy.spawnType - 0x97)); break;
    case 0x65: handle = frameHandle(enemyLargeFrames_, 52); large = true; break;
    case 0x66: handle = frameHandle(enemyMediumFrames_, 145 + ((enemy.spawnType - 0x9b) & 3)); break;
    case 0x67: handle = frameHandle(enemyMediumFrames_, 149); break;
    case 0x6c: handle = frameHandle(enemySmallFrames_, 142); break;
    case 0x82: handle = frameHandle(enemySmallFrames_, 152 + (enemy.drawHelperTimer / 5) % 2); break;
    case 0x83: handle = frameHandle(enemySmallFrames_, 154 + (enemy.drawHelperTimer / 5) % 2); break;
    case 0x84: handle = frameHandle(enemySmallFrames_, 156 + (enemy.drawHelperTimer / 6) % 4); break;
    case 0x85: handle = frameHandle(enemyMediumFrames_, 202 + (enemy.drawHelperTimer / 6) % 2); break;
    case 0x86: handle = frameHandle(enemyMediumFrames_, 204 + (enemy.drawHelperTimer / 7) % 2); break;
    case 0x87: handle = frameHandle(enemyMediumFrames_, 206 + (enemy.drawHelperTimer / 7) % 2); break;
    case 0x88: handle = frameHandle(enemyMediumFrames_, 208 + (enemy.drawHelperTimer / 7) % 3); break;
    case 0x89: handle = frameHandle(enemyMediumFrames_, 211 + (enemy.spawnType - 0x103)); break;
    default: break;
    }

    if (handle != -1) {
        const bool exactStage05 = enemy.spawnType >= 0x44 &&
                                  enemy.spawnType <= 0x53;
        const double pulse = exactStage05
                                 ? 1.0
                                 : 1.0 + 0.03 *
                                       std::sin(enemy.drawHelperTimer * 0.08);
        drawOriginalMode7Node(handle, x, y, enemy.sourceAngle16,
                              pulse, pulse, false);

        const auto drawSmallPart = [this](int frame, float drawX, float drawY,
                                           std::uint16_t angle,
                                           bool reverse = false) {
            const int graph = frameHandle(enemySmallFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        };
        const auto drawMediumPart = [this](int frame, float drawX, float drawY,
                                            std::uint16_t angle,
                                            bool reverse = false) {
            const int graph = frameHandle(enemyMediumFrames_, frame);
            if (graph != -1) {
                drawOriginalMode7Node(graph, drawX, drawY, angle,
                                      1.0, 1.0, reverse);
            }
        };
        if (enemy.spawnType == 0x44) {
            const int spin = enemy.drawHelperTimer * 0x29a;
            drawSmallPart(47, x, y, normalizeAngle16(spin));
            drawSmallPart(47, x, y, normalizeAngle16(-spin), true);
        }
        else if (enemy.spawnType == 0x45) {
            const float sway = static_cast<float>(
                std::sin(enemy.drawHelperTimer * kTau / 150.0) * 12.0);
            drawSmallPart(49, x, y + sway, 0);
            drawSmallPart(50, x + 16.0f, y + sway, 0);
            drawSmallPart(50, x - 16.0f, y + sway, 0, true);
            drawSmallPart(51, x + 8.0f, y + sway + 8.0f,
                          enemy.sourceAngle16);
            drawSmallPart(51, x - 8.0f, y + sway + 8.0f,
                          normalizeAngle16(-static_cast<int>(enemy.sourceAngle16)),
                          true);
        }
        else if (enemy.spawnType == 0x46) {
            drawMediumPart(76, x, y, enemy.sourceAngle16);
            drawMediumPart(76, x, y,
                           normalizeAngle16(-static_cast<int>(enemy.sourceAngle16)),
                           true);
            drawMediumPart(77, x, y, 0);
        }
        else if (enemy.spawnType == 0x4a) {
            drawSmallPart(52, x, y + 20.0f, 0);
        }
        else if (enemy.spawnType == 0x4b) {
            const float wave = static_cast<float>(
                std::sin(enemy.drawHelperTimer * kTau / 360.0) * 2.0);
            drawSmallPart(54, x, y + wave, 0);
            drawSmallPart(53, x, y - wave, 0);
        }
        else if (enemy.spawnType == 0x4d) {
            // DAT_140e44c3c..DAT_140e44c50 are Enemy_m[88..93].
            // The exact helpers use these as one body, paired side mounts, and
            // a collision core; retain that ordering with recovered offsets.
            drawMediumPart(88, x, y, 0);
            drawMediumPart(89, x, y - 16.0f, 0);
            drawMediumPart(90, x, y - 32.0f, 0);
            drawMediumPart(91, x + 24.0f, y - 24.0f,
                           enemy.sourceAngle16);
            drawMediumPart(91, x - 24.0f, y - 24.0f,
                           normalizeAngle16(-static_cast<int>(enemy.sourceAngle16)),
                           true);
            drawMediumPart(92, x + 42.0f, y, enemy.sourceAngle16);
            drawMediumPart(92, x - 42.0f, y,
                           normalizeAngle16(-static_cast<int>(enemy.sourceAngle16)),
                           true);
        }
        if (large) {
            const int core = frameHandle(effectMediumFrames_, 3);
            if (core != -1) {
                SetDrawBlendMode(DX_BLENDMODE_ADD, 96);
                DrawRotaGraphF(x, y, 0.7, enemy.drawHelperTimer * 0.02,
                               core, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
        }
    }
    else {
        DrawCircle(static_cast<int>(x), static_cast<int>(y),
                   std::max(8, enemy.radius / 3), GetColor(255, 120, 180), TRUE);
    }

    if (enemy.targetable && enemy.maxHp >= 1000) {
        StageEnemy gauge = enemy;
        gauge.hp = enemy.drawHp;
        int gaugeMode = enemy.radius >= 100 ? 2 : 1;
        switch (enemy.spawnType) {
        case 0x44:
        case 0x45:
        case 0x4e: gaugeMode = 2; break;
        case 0x4d:
        case 0x4f: gaugeMode = 0; break;
        default: break;
        }
        drawEnemyGaugeExact(gauge, gaugeMode, x, y);
    }
    return true;
}

} // namespace reconstructed
